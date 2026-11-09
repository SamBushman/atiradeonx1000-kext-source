#!/usr/bin/env python3
"""link_corpus.py - turn a userspace corpus (Userspace/<Bin>/ppc) into a linkable build directory (issue #61).

    link_corpus.py CORPUS_DIR STOCK_BINARY GHIDRA_DATA.tsv OUT_DIR [--exclude NAME[,NAME...]] [--config link_config.json]

The corpus compiles part by part but refers to data by Ghidra's names (`DAT_`/`PTR_`/`s_`/`FLOAT_`, `_gll_cc`, ...) declared `extern`, so it cannot
be linked as it stands. This tool

  1. builds the DATA SYMBOL MAP (`symbol_map.tsv`): every data label the corpus refers to -> address, section, size, Ghidra data type, C type used,
     what the word(s) contain (pointer target / constant), where it is defined in the link;
  2. writes `link_decls.h` as `decls.h`: every extern gets an assembler label equal to its Ghidra/Mach-O name (the C name `_glClear` would otherwise
     be the symbol `__glClear`), data externs get the width/signedness of the Ghidra data type instead of `unsigned char`;
  3. writes `data.s`: every non-code section of the stock binary as assembler data, one label per referenced address, with pointer words expressed
     as `.long symbol+offset` (using the binary's own relocation entries, the indirect symbol table for symbol-pointer slots, and the function ledger),
     so the linker lays the data out anywhere and every reference still resolves to the right object;
  4. copies the `part_*.c` (minus functions the toolchain supplies), and writes `exports.txt` (the stock's exported symbols) and `build.sh`.

`build.sh` (run on the Tiger G5 with Apple gcc 4.0.1) compiles and links the dylib/bundle with the stock's install name and versions.
"""
import sys, os, re, json, struct, collections, glob
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import machoutil as mo
import rewrites
import apply_names

args = sys.argv[1:]
opts = {'exclude': set(), 'config': None}
pos = []
i = 0
while i < len(args):
    if args[i] == '--exclude':
        opts['exclude'] |= set(args[i + 1].split(','))
        i += 2
    elif args[i] == '--config':
        opts['config'] = json.load(open(args[i + 1]))
        i += 2
    else:
        pos.append(args[i])
        i += 1
corpus, stock, gdata, out = pos
cfg = opts['config'] or {}
for _k in ('gl_headers',):
    if _k in cfg:
        cfg[_k] = [os.path.expandvars(x) for x in cfg[_k]]
os.makedirs(out, exist_ok=True)
m = mo.load(stock)

# ---------------------------------------------------------------------------------------------- function ledger
ledger = []   # (addr, size, name, part)
failed_fns = []   # (addr, size, name) of ledger rows the decompiler failed on (GLEngine _gleInvertMatrix_AltiVec: AltiVec): linked from the stock's own words until transcribed
EXTRA_DIRS = [d for d in cfg.get('extra_corpora', []) if os.path.isdir(os.path.join(corpus, d))]
for l in open(os.path.join(corpus, 'ledger.tsv')):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 4:
        ledger.append((int(f[0], 16), int(f[1]), f[2], f[3]))
        if len(f) >= 5 and f[4].startswith('DECOMPILE-FAILED'):
            failed_fns.append((int(f[0], 16), int(f[1]), f[2]))
for d_ in EXTRA_DIRS:      # companion corpora (unowned_code/: code only reached through data or exported entry points no analysis found)
    for l in open(os.path.join(corpus, d_, 'ledger.tsv')):
        f = l.rstrip('\n').split('\t')
        if len(f) >= 4:
            ledger.append((int(f[0], 16), int(f[1]), f[2], d_ + '/' + f[3]))
fn_by_addr = {a: n for a, s, n, p in ledger}
# declared parameter counts (K&R / ANSI definitions of the corpus), for rewrites.bind_calls
for _pf in sorted(glob.glob(os.path.join(corpus, 'part_*.c'))):
    for _m in re.finditer(r'(?m)^/\* (\S+) @ \S+ \(\d+ bytes\) \*/\n[^\n(]*?\b\w+\(([^)]*)\)', open(_pf).read()):
        _ps = [x for x in _m.group(2).split(',') if x.strip() and x.strip() != 'void']
        rewrites.ARITY[_m.group(1)] = len(_ps)
fn_addrs = sorted(fn_by_addr)

# ---------------------------------------------------------------------------------------------- ghidra data
gd = {}     # addr -> dict(block, name, dtype, len, target, tname)
for l in open(gdata):
    f = l.rstrip('\n').split('\t')
    if len(f) < 7:
        continue
    gd[int(f[0], 16)] = dict(block=f[1], name=f[2], dtype=f[3], len=int(f[4]), target=int(f[5], 16) if f[5] != '-' else None, tname=f[6])

# ---------------------------------------------------------------------------------------------- mach-o facts
code_secs = [s for s in m.secs if mo.is_code(s)]
def in_code(a):
    return any(s['addr'] <= a < s['addr'] + s['size'] for s in code_secs)
SKIP_SECS = {('__DATA', '__dyld'), ('__TEXT', '__eh_frame'), ('__TEXT', '__gcc_except_tab'), ('__DATA', '__eh_frame')}
sym_ptr_secs = [s for s in m.secs if (s['flags'] & 0xff) in (6, 7)]   # non-lazy / lazy symbol pointers
data_secs = [s for s in m.secs if not mo.is_code(s) and (s['seg'], s['name']) not in SKIP_SECS and s not in sym_ptr_secs and s['seg'] not in ('__LINKEDIT',)
             and not (s['seg'] == '__TEXT' and s['name'] in ('__mach_header',))]

def indirect_name(sec, idx):
    """symbol name (or None for local/abs) of entry `idx` of a symbol-pointer section"""
    k = m.indirect[sec['r1'] + idx]
    if k in (0x80000000, 0x40000000, 0xc0000000):
        return None
    return m.syms[k]['name']

nlist_by_addr = collections.defaultdict(list)
for s in m.syms:
    if (s['type'] & 0x0e) == 0x0e and s['name']:
        nlist_by_addr[s['value']].append(s)

# ---------------------------------------------------------------------------------------------- what the toolchain supplies
TOOLCHAIN_FN = set(cfg.get('toolchain_functions', [])) | {'dyld_stub_binding_helper', 'cfm_stub_binding_helper', '__dyld_func_lookup', '___initialize_Cplusplus'} | opts['exclude']
TOOLCHAIN_RE = re.compile(r'^(save|rest)(FP|GP|GPR|VR|F|G)\w*$|^(saveFP|restFP)$|^_*dyld_func_lookup_(call|island)\w*$')   # the last: crt long-branch thunks `b __dyld_func_lookup` (issue #227)
TOOLCHAIN_RANGES = [(int(a, 16), int(b, 16)) for a, b in cfg.get('toolchain_addr_ranges', [])]
def toolchain_fn(name, addr=None):
    return name in TOOLCHAIN_FN or bool(TOOLCHAIN_RE.match(name)) or (addr is not None and any(lo <= addr < hi for lo, hi in TOOLCHAIN_RANGES))
TOOLCHAIN_DATA = set(cfg.get('toolchain_data', [])) | {'dyld__mh_dylib_header', 'dyld_lazy_symbol_binding_entry_point', 'dyld_func_lookup_pointer', 'dyld__mh_bundle_header', '__mh_bundle_header', '__mh_dylib_header', '__mh_execute_header'}

# ---------------------------------------------------------------------------------------------- decls.h
def read_decl_lines(path):
    """decls.h lines, with a prototype that wraps over several lines joined into one"""
    out_, cur_ = [], ''
    for l_ in open(path).read().split('\n'):
        if cur_:
            cur_ += ' ' + l_.strip()
            if cur_.rstrip().endswith(';'):
                out_.append(cur_)
                cur_ = ''
        elif l_.startswith('extern') and not l_.rstrip().endswith(';'):
            cur_ = l_
        else:
            out_.append(l_)
    if cur_:
        out_.append(cur_)
    return out_
decls = read_decl_lines(os.path.join(corpus, 'decls.h'))
for d_ in EXTRA_DIRS:
    have_ = set(decls)
    def _fn(l):
        mm_ = re.match(r'^extern (?:const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)\((.*)\);\s*$', l)
        return mm_.group(2) if mm_ and '(*' not in l else None
    have_fns = {_fn(l) for l in decls} - {None}      # a companion corpus only sees a callee as `extern int f();`: the main corpus's (typed) declaration wins
    decls += [l for l in read_decl_lines(os.path.join(corpus, d_, 'decls.h')) if l.startswith('extern') and l not in have_ and _fn(l) not in have_fns]
func_names, data_decls = [], {}
for ln in decls:
    mm = re.match(r'^extern (?:const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)\((.*)\);\s*$', ln)
    if mm and '(*' not in ln:
        func_names.append(mm.group(2))
        continue
    mm = re.match(r'^extern (?:const )?(.*?)\(\*([A-Za-z_][A-Za-z_0-9]*)\)\(\);\s*$', ln)
    if mm:
        data_decls[mm.group(2)] = ('fnptr', ln)
        continue
    mm = re.match(r'^extern (?:const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)(\[\])?;\s*$', ln)
    if mm:
        data_decls[mm.group(2)] = ('array' if mm.group(3) else 'scalar', ln)

# `data` rows of the corpus's names*.tsv rename a Ghidra data label (DAT_001aa838) to a real name that no longer carries the stock address: DATA_ROOT maps the
# new name to the Ghidra name it came from, whose suffix still is the address
DATA_ROOT = apply_names.func_roots(apply_names.load_datas(corpus))

# `target` rows (`target<TAB>LD_<hex address><TAB>NEWNAME<TAB>tier<TAB>evidence`) name an object the link layer would label LD_<address>: an anonymous data object that only
# pointer words reach (a vtable, a template). The new name replaces LD_<address> everywhere in data.s/code.s; ld(addr) gives the label for an address.
TARGET_NAME = {}
for _r in apply_names.load_targets(corpus):
    _a = int(_r[2][3:], 16)
    assert _a not in TARGET_NAME, 'two target rows for 0x%x' % _a
    TARGET_NAME[_a] = _r[3]
def ld(a):
    return TARGET_NAME.get(a, 'LD_%x' % a)

# LOCAL / PARAMETER RENAMES vs the link-time rewrites. rewrites.mirror_frame / fix_byte_buffers / fix_struct_blocks / fix_pointer_records recognise a stack variable by its
# Ghidra name (`local_48`, `acStack_210`: the number is the variable's distance below the caller's sp), and rewrite_float_stores / rewrite_pair_results / bind_calls /
# rewrite_float_args key on `fVarN` / `uVarN` / `param_N` shapes. A `local` / `use` row that gave a variable a real name silently switched those rewrites off for the
# function (GLDriver: 561 mirrored frames before the naming work, 542 after; first bad commit 30b76756, cgl_probe read 170,170,170,170 instead of the triangle).
# So, per function: take every renamed variable back to its Ghidra name, run the whole rewrite chain, then give the survivors their real names again (the
# linked source keeps the corpus's names). A mirrored frame turns its variables into `ghidra_frame` accesses (the names vanish), so the function gets a comment
# listing real name = Ghidra name. A Ghidra name that was split into several real names (`use` rows) cannot be given back unambiguously: it keeps the Ghidra name.
# LOCAL_RENAMES[function] = {new: old}.
LOCAL_RENAMES = collections.defaultdict(dict)
_func_old = apply_names.func_roots(apply_names.load_funcs(corpus))
for _r in apply_names.load_rows(corpus):
    LOCAL_RENAMES[_r[2]][_r[4]] = _r[3]
for _new_fn, _old_fn in _func_old.items():                  # rows keep the OLD function name; the header comment carries the new one
    if _old_fn in LOCAL_RENAMES:
        LOCAL_RENAMES[_new_fn].update(LOCAL_RENAMES[_old_fn])
# frame_blocks (gld.json): {function: {block: ghidra name}} - a block the corpus merged from several adjacent stock locals by hand (b5e19899: `uint requestWords [2]`
# for `local_b8`/`local_b4`) is declared under a real name no row records. Naming the stock slot it starts at lets mirror_frame put it into the frame at its stock
# offset; as a separate -O0 local it was only 8 bytes, and gldTextureFormatLookup (handed it as a 0x28-byte descriptor) wrote over the saved r29..r31.
for _fn, _blocks in cfg.get('frame_blocks', {}).items():
    LOCAL_RENAMES[_fn].update(_blocks)
STACK_RE = re.compile(r'^(?:local|\w*Stack)_[0-9a-f]+(?:_buf)?$')
VAR_DECL = re.compile(r'^\s+[A-Za-z_][\w *]*?\b[A-Za-z_]\w*(?:\s*\[[^\]]*\])?;\s*$')

def unrename_locals(txt, fn):
    """-> (txt with every renamed variable back at its Ghidra name, {ghidra name: real name} for the names that can be given back, count)"""
    m_all = LOCAL_RENAMES.get(fn)
    if not m_all:
        return txt, {}, 0
    cnt_ = collections.Counter(m_all.values())
    # a non-stack variable that was split into several real names stays split (their declarations may differ in type); stack variables must all go back
    m_ = {new_: old_ for new_, old_ in m_all.items() if cnt_[old_] == 1 or STACK_RE.match(old_)}
    n_ = [0]
    def sub_(t):
        o_ = m_.get(t.group(0))
        if o_ is None:
            return t.group(0)
        n_[0] += 1
        return o_
    txt = re.sub(r'[A-Za-z_][A-Za-z0-9_]*', sub_, txt)
    # a variable split into several roles had one declaration per role: they all carry the Ghidra name again, keep the first of identical lines (only inside the
    # declaration block right after the `{`: it ends at the first line that is not a declaration)
    k_ = txt.find('\n{')
    if k_ >= 0:
        lines_ = txt[k_ + 1:].split('\n')
        seen_, out_, i_ = set(), [lines_[0]], 1
        while i_ < len(lines_) and (VAR_DECL.match(lines_[i_]) or not lines_[i_].strip()) and not re.match(r'^\s+(?:return|break|continue|goto|else|case|default)\b', lines_[i_]):
            if lines_[i_] in seen_ and lines_[i_].strip():
                i_ += 1
                continue
            seen_.add(lines_[i_])
            out_.append(lines_[i_])
            i_ += 1
        txt = txt[:k_ + 1] + '\n'.join(out_ + lines_[i_:])
    by_old = collections.defaultdict(set)
    for new_, old_ in m_.items():
        by_old[old_].add(new_)
    fwd_ = {old_: next(iter(news_)) for old_, news_ in by_old.items() if len(news_) == 1}
    return txt, fwd_, n_[0]

def rename_back(txt, fwd, fn):
    """give the variables that survived the rewrites their real names again; list the stack variables a mirrored frame swallowed"""
    if not fwd:
        return txt
    frame_ = []
    if 'ghidra_frame[' in txt:
        m_ = LOCAL_RENAMES.get(fn, {})
        frame_ = sorted(((old_, new_) for new_, old_ in m_.items() if STACK_RE.match(old_)), key=lambda x: x[0])
    txt = re.sub(r'[A-Za-z_][A-Za-z0-9_]*', lambda t: fwd.get(t.group(0), t.group(0)), txt)
    if frame_:
        txt = re.sub(r'(?m)^(\s*unsigned long long ghidra_frame\[\d+\](?: = \{ 0 \})?;.*)$', lambda x: x.group(1) + '\n' + x.group(0)[:len(x.group(0)) - len(x.group(0).lstrip())] + '/* frame slots (real name = Ghidra name): ' + ', '.join('%s = %s' % (new_, old_) for old_, new_ in frame_) + ' */', txt, count=1)
    return txt

def addr_of_name(n):
    mm = re.search(r'_([0-9a-f]{8})$', DATA_ROOT.get(n, n))
    return int(mm.group(1), 16) if mm else None

# ghidra names by address (for names without an address suffix, e.g. _gll_cc); C++ names also under the identifier the corpus gives them (`TType::vtable` -> TType__vtable)
def csan(n):
    n = re.sub(r'\([^()]*\)(?=::)', '', n)      # `func(args)::var` (a function-local static) is `func::var` in the corpus
    return re.sub(r'[^A-Za-z0-9_]', '_', n)
def scope_split(n):
    """split a C++ qualified name at top-level `::`"""
    parts, depth, cur = [], 0, ''
    i = 0
    while i < len(n):
        c = n[i]
        if c in '<(':
            depth += 1
        elif c in '>)':
            depth -= 1
        if depth == 0 and n.startswith('::', i):
            parts.append(cur)
            cur = ''
            i += 2
            continue
        cur += c
        i += 1
    parts.append(cur)
    return parts
ghidra_name_addr = {}
suffix_addrs = collections.defaultdict(set)
for a, e in gd.items():
    if e['name'] != '-':
        ghidra_name_addr[e['name']] = a
        ghidra_name_addr.setdefault(csan(e['name']), a)
        if '::' in e['name']:
            ps = scope_split(e['name'])
            for k in range(1, len(ps)):
                suffix_addrs[csan('::'.join(ps[k:]))].add(a)
                suffix_addrs[csan('::'.join(ps[k:]).replace('::', '__'))].add(a)
for a, ss in nlist_by_addr.items():
    for s in ss:
        ghidra_name_addr.setdefault(s['name'], a)
        ghidra_name_addr.setdefault(csan(s['name']), a)
# plain labels (no data type at the address) from DumpData's .syms file; a name on several addresses (Ghidra calls every class's vtable `TType::vtable`) resolves to
# the one a pointer slot targets, else the lowest
ptr_targets = {g['target'] for g in gd.values() if g['target'] is not None}
if os.path.exists(gdata + '.syms'):
    by_name = collections.defaultdict(set)
    for l in open(gdata + '.syms'):
        f = l.rstrip('\n').split('\t')
        if len(f) == 3:
            by_name[f[2]].add(int(f[0], 16))
    for n_, addrs in by_name.items():
        cands = sorted(addrs)
        pt = [x for x in cands if x in ptr_targets]
        pick = (pt or cands)[0]
        ghidra_name_addr.setdefault(n_, pick)
        ghidra_name_addr.setdefault(csan(n_), pick)
for k_, v_ in cfg.get('manual_names', {}).items():
    ghidra_name_addr[k_] = int(v_, 16)
# the real (mangled) Mach-O symbol at an address, preferring an external one: this is the assembler label every definition/reference must use
def macho_label(addr):
    ss = nlist_by_addr.get(addr, [])
    ss = sorted(ss, key=lambda s: (0 if s['type'] & 1 else 1, s['name']))
    return ss[0]['name'] if ss else None

def data_addr(name):
    a = addr_of_name(name)
    if a is not None and m.sec_at(a):
        return a
    if name in ghidra_name_addr:
        return ghidra_name_addr[name]
    cands = suffix_addrs.get(name, ())
    if len(cands) > 1:      # a static data member and its weak (coalesced) copy: the code uses the plain one
        plain = [x for x in cands if (m.sec_at(x) or {}).get('flags', 0) & 0xff != 0xb]
        cands = plain or cands
    if len(cands) >= 1:      # the corpus drops leading scopes (`std::`) of C++ names
        return sorted(cands)[0]
    return a

CT = {1: 'unsigned char', 2: 'unsigned short', 4: 'unsigned int', 8: 'unsigned long long'}
def c_type_for(name, kind):
    """C declaration for a data label from Ghidra's data type at its address"""
    a = data_addr(name)
    g = gd.get(a) if a is not None else None
    sec = m.sec_at(a) if a is not None else None
    if kind == 'fnptr':
        return 'int (*%s)()'
    if g is None:
        return None
    dt, ln = g['dtype'], g['len']
    if dt in ('TerminatedCString', 'string', 'unicode', 'TerminatedUnicode'):
        return 'char %s[]'
    if (dt == 'pointer' or re.match(r'^[\w ]+ \*$', dt)) and ln == 4:      # `undefined *` etc.: a 4-byte pointer (GLEngine _tex1_func_array: a table of function pointers)
        return 'unsigned char *%s' if kind != 'array' else 'unsigned char *%s[]'
    if dt == 'float':
        return 'float %s' if kind != 'array' else 'float %s[]'
    if dt == 'double':
        return 'double %s' if kind != 'array' else 'double %s[]'
    mm = re.match(r'^(?:undefined|u?int|dword|word|byte|char|short|ushort|uint|long|ulong)(\d*)(?:\[(\d+)\])?$', dt)
    if mm:
        w = {'dword': 4, 'word': 2, 'byte': 1, 'char': 1, 'short': 2, 'ushort': 2, 'uint': 4, 'int': 4, 'long': 4, 'ulong': 4}.get(re.match(r'[a-z]+', dt).group(0), None)
        n = mm.group(1)
        if w is None or re.match(r'^undefined', dt):
            w = int(n) if n else 1
        cnt = int(mm.group(2)) if mm.group(2) else 1
        if dt.startswith('undefined') and not mm.group(2) and ln > w:
            cnt = ln // w
        t = CT.get(w, 'unsigned char')
        return t + ' %s' + ('[]' if (cnt > 1 or kind == 'array') else '')
    return 'unsigned char %s[]'   # structures etc.: raw bytes

# ---------------------------------------------------------------------------------------------- link_decls.h (decls.h with asm labels + real widths)
# `(&DAT_001e6158)[iVar2]` is Ghidra's index into an array of ITS data type (undefined4: the stock does `rlwinm r0,r3,2,0,29; lwzx`); the corpus declares such a table
# `unsigned char X[]` (it is also used for byte arithmetic), so the rebuilt index scaled by 1 and read one byte (GLDriver FUN_001771b0 / FUN_0017729c filled the texture-unit
# state from the wrong table entries; found by the pure-function fuzz `graph` profile). Index through a pointer of the Ghidra type's width.
sized_index_tables = {}
_decl_text = ''.join(open(os.path.join(corpus, _h)).read() for _h in ('decls.h', 'extra_decls.h') if os.path.exists(os.path.join(corpus, _h)))   # a table the corpus declares in extra_decls.h too (GLEngine _tex1_func_array)
for _nm, _v in data_decls.items():
    _t = c_type_for(_nm, _v[0])
    _mw = re.match(r'^(unsigned (?:short|int|long long))\b', _t or '')
    _elem = _mw.group(1) if _mw else ('unsigned int' if (_t or '').startswith('unsigned char *%s') and _v[0] != 'array' else None)   # a 4-byte pointer-typed table is indexed by words
    if _elem and re.search(r'extern (?:const )?unsigned char %s\[\];' % re.escape(_nm), _decl_text):
        sized_index_tables[_nm] = _elem
label_of = {}        # C identifier -> assembler symbol
signed_kept = []     # data names whose signed corpus type was kept over Ghidra's unsigned-by-default one
typed = 0
def transform(lines):
    global typed
    res = []
    for ln in lines:
        mm = re.match(r'^extern (const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)\((.*)\);\s*$', ln)
        if mm and '(*' not in ln:
            nm = mm.group(3)
            if nm in void_valued and re.match(r'^extern void\b', ln): ln = ln.replace('extern void', 'extern ' + void_valued[nm], 1)
            res.append('%s asm("%s");' % (ln.rstrip()[:-1], cfg.get('label_overrides', {}).get(nm, fn_label.get(nm, nm))))
            label_of[nm] = nm
            continue
        mm = re.match(r'^extern (?:const )?(.*?)\(\*([A-Za-z_][A-Za-z_0-9]*)\)\(\);\s*$', ln)
        if mm:
            nm = mm.group(2)
            res.append('extern int (*%s)() asm("%s");' % (nm, nm))
            label_of[nm] = nm
            continue
        mm = re.match(r'^extern (const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)(\[\])?;\s*$', ln)
        if mm and mm.group(3) in data_decls:
            nm = mm.group(3)
            kind = data_decls[nm][0]
            t_ = c_type_for(nm, kind)
            orig_ptr = ('*' in mm.group(2)) or kind == 'array' or nm in byte_arith   # the corpus uses it as a pointer / array, or does byte arithmetic on its address (`&X + n*8`): keep its form, just label it
            _lab = cfg.get('data_label_overrides', {}).get(nm, nm)
            if nm in cfg.get('data_label_overrides', {}):
                res.append('%s asm("%s");' % (ln.rstrip()[:-1], _lab))
            elif t_ == 'char %s[]' and 'MACH_HEADER' not in ln:
                # a string label IS the string, not a variable holding a pointer to it: the corpus declares `unsigned char *s_X` and reads `s_X[0]`, which on a
                # pointer variable loads the string's first four bytes as an address (the rebuilt InitAtomTable read "~!%^" = 0x7e21255e and crashed)
                res.append('extern %s asm("%s");' % (t_ % nm, nm))
                typed += 1
            elif t_ and 'MACH_HEADER' not in ln and 'Ghidra' not in ln and not orig_ptr:
                # Ghidra's data type gives the width; a corpus declaration that is already a SIGNED integer of that width keeps its signedness (the
                # decompiler typed it from signed uses): glprog `_S_force_new` became `unsigned int`, the allocator's `_S_force_new < 1` test (stock
                # `cmpwi; ble`) failed for its -1, and std::allocator freed pool blocks with operator delete ("pointer not malloced", issue #68)
                _ct = mm.group(2).strip()
                _signed = {'int': ('unsigned int', 'int'), 'long': ('unsigned int', 'int'), 'short': ('unsigned short', 'short'),
                           'char': ('unsigned char', 'signed char'), 'longlong': ('unsigned long long', 'long long'), 'long long': ('unsigned long long', 'long long')}.get(_ct)
                if _signed and t_.startswith(_signed[0] + ' '):
                    t_ = _signed[1] + t_[len(_signed[0]):]
                    signed_kept.append(nm)
                res.append('extern %s asm("%s");' % (t_ % nm, nm))
                typed += 1
            elif nm in byte_arith and kind == 'scalar' and '*' not in mm.group(2):
                res.append('extern unsigned char %s asm("%s");' % (nm, nm))      # `&X + n*8` is byte arithmetic on X's address
            else:
                res.append('%s asm("%s");' % (ln.rstrip()[:-1], nm))
            label_of[nm] = nm
            continue
        res.append(ln)
    return res
extra_lines = []
_p = os.path.join(corpus, 'extra_decls.h')
if os.path.exists(_p):
    extra_lines = read_decl_lines(_p)
    for ln in extra_lines:
        mm = re.match(r'^extern (?:const )?(.*?)\(\*([A-Za-z_][A-Za-z_0-9]*)\)\(\);\s*$', ln)
        if mm:
            data_decls[mm.group(2)] = ('fnptr', ln)
            continue
        mm = re.match(r'^extern (?:const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)(\[\])?;\s*$', ln)
        if mm and '(' not in ln:
            data_decls[mm.group(2)] = ('array' if mm.group(3) else 'scalar', ln)
fn_label = {}
nlist_alias = {}
for a_, ss_ in nlist_by_addr.items():
    for s_ in ss_:
        nlist_alias.setdefault(s_['name'], a_)
_lab_count = collections.Counter()
for a_, s_, n_, p_ in ledger:
    lab = macho_label(a_) if in_code(a_) else None
    if lab:
        _lab_count[lab] += 1
for a_, s_, n_, p_ in ledger:
    lab = macho_label(a_) if in_code(a_) else None
    # two different local functions can carry the same Mach-O name (static functions of different source files): the corpus already made the C names unique
    ext_ = any(s2['type'] & 1 for s2 in nlist_by_addr.get(a_, []))
    fn_label[n_] = lab if lab and lab != n_ and (ext_ or _lab_count[lab] == 1) else n_
_all_body = ''
for _d in [''] + EXTRA_DIRS:
    for _f in sorted(os.listdir(os.path.join(corpus, _d))):
        if re.match(r'part_\d+\.c$', _f):
            _all_body += open(os.path.join(corpus, _d, _f)).read()
byte_arith = set(re.findall(r'&\s*(\w+)\s*[+-]\s', _all_body)) | set(re.findall(r'\(\s*&\s*(\w+)\s*\)\s*\[', _all_body))   # address arithmetic assumes a byte-sized object
# ... but only for an object Ghidra has no type for (`DAT_` with no data type, printed as a byte). An object with a real 2/4-byte type (`undefined4`,
# `undefined2`, `pointer`) keeps its type: `X == 0` and `(&X)[i]` are element accesses (a 1-byte declaration read a byte / indexed by bytes: the rebuilt
# GetSymbolTable tested one byte and `_shaderString[i]` indexed bytes, DAT_001b004c = 0x00010203 read as 0), and the explicit byte-offset forms
# `&X + n*k` are rewritten to arithmetic on `(unsigned char *)&X` instead.
def _sized_type(nm_):
    a_ = data_addr(nm_)
    g_ = gd.get(a_) if a_ is not None else None
    return bool(g_) and re.match(r'^(undefined[248]|dword|word|short|ushort|int|uint|long|ulong|float|double|pointer|undefined \*)', g_['dtype']) is not None and g_['len'] in (2, 4, 8)
byte_arith_sized = {n_ for n_ in byte_arith if _sized_type(n_)}
byte_arith -= byte_arith_sized
# A function whose own decompile returns nothing (`void`) but that a caller uses the result of (`x = (double)((void (*)())f)(...)`): Ghidra models the callee as
# leaving a value in f1/r3 that it never wrote (a passed-through argument). C cannot use a void result, so give such a function the type the callers read it as.
void_valued = {}
for m_ in re.finditer(r'[=(,]\s*(?:\(([\w ]+)\))?\s*\(\(void \(\*\)\(\)\)(\w+)\)\(', _all_body):
    ty_ = (m_.group(1) or 'int').strip()
    void_valued[m_.group(2)] = 'double' if ty_ in ('double', 'float') else void_valued.get(m_.group(2), 'int')
DROP_DECLS = set(cfg.get('drop_decls', []))
# a dropped toolchain function that is only `import(args); return;` is a PIC stub of that import: callers reach the import itself
stub_alias = {}
for _d in [''] + EXTRA_DIRS:
    for _f in sorted(os.listdir(os.path.join(corpus, _d))):
        if not re.match(r'part_\d+\.c$', _f):
            continue
        for _m in re.finditer(r'(?m)^/\* (\S+) @ 0x([0-9a-f]+) \(\d+ bytes\) \*/\n[^\n]*\n(?:[^\n{]*\n)*?\{\n\s+(_?[A-Za-z]\w*)\([^;]*\);\n\s+return;\n\}', open(os.path.join(corpus, _d, _f)).read()):
            _n, _a, _callee = _m.group(1), int(_m.group(2), 16), _m.group(3)
            if any(lo <= _a < hi for lo, hi in [(int(x, 16), int(y, 16)) for x, y in cfg.get('toolchain_addr_ranges', [])]) and not _callee.startswith(('FUN_', 'DAT_')):
                stub_alias[_n] = _callee
cfg.setdefault('label_overrides', {}).update({k: v for k, v in stub_alias.items() if k not in cfg.get('label_overrides', {})})
decls = [l for l in decls if not any(re.search(r'\b%s\b' % re.escape(d), l) for d in DROP_DECLS)]
for nm_, a_ in nlist_alias.items():       # another name (in the symbol table) of a function that has a ledger entry under a different one
    ln_ = fn_by_addr.get(a_)
    if ln_ and nm_ not in fn_label and nm_ != ln_:
        fn_label[nm_] = fn_label.get(ln_, ln_)
new_decls = transform(decls)
float_protos_ = rewrites.float_protos(new_decls)
floatargs_total = [0]
fstores_total = [0]
if cfg.get('prelude'):
    new_decls = list(cfg['prelude']) + new_decls
if cfg.get('postlude'):
    new_decls = new_decls + list(cfg['postlude'])
open(os.path.join(out, 'decls.h'), 'w').write('\n'.join(new_decls) + '\n')
extra_lines = [l for l in extra_lines if not any(re.search(r'\b%s\b' % re.escape(d), l) for d in DROP_DECLS)]
open(os.path.join(out, 'extra_decls.h'), 'w').write('\n'.join(transform(extra_lines)) + '\n' if extra_lines else '')
if os.path.exists(os.path.join(corpus, 'ghidra_c.h')):
    open(os.path.join(out, 'ghidra_c.h'), 'w').write(open(os.path.join(corpus, 'ghidra_c.h')).read())
for _fh in glob.glob(os.path.join(corpus, '*_fields.h')):   # decls.h #includes the per-context field headers (gld_/arb_/prog_/comp_ctx_fields.h)
    open(os.path.join(out, os.path.basename(_fh)), 'w').write(open(_fh).read())

# ---------------------------------------------------------------------------------------------- which data symbols need a definition
needed = {}      # name -> address
DROPPED = set(cfg.get('drop_decls', []))
body = ''
for d_ in [''] + EXTRA_DIRS:
    for f in sorted(os.listdir(os.path.join(corpus, d_))):
        if re.match(r'part_\d+\.c$', f):
            body += open(os.path.join(corpus, d_, f)).read()
used = set(re.findall(r'[A-Za-z_][A-Za-z_0-9]*', body))
for nm in data_decls:
    if nm in DROPPED:
        continue
    if nm in used or True:
        a = data_addr(nm)
        needed[nm] = a

# image-address literals in code (`0xa7b7bf8c` passed as a pointer): only for images with a high preferred address, where such a value cannot be a plain number
# string literals that are really numbers or table addresses: Ghidra types bytes as a string (code bytes at 0x2d48 in GLDriver, part of the parser's yyr1
# table in glprog) and then prints a constant that points there as that string. Used with arithmetic (`*(short *)("}J3x..." + off)`, a struct field
# at 0x2d48; `*(short *)(" !\"#$..." + yyn*2 + 0x40)`, yyr1[yyn]) the C would index a copy of the literal. Match the literal's bytes to Ghidra's string
# items and put the address back as a number (an image address is then symbolised like any other literal).
def _c_unescape(lit):
    out, i = bytearray(), 0
    while i < len(lit):
        c = lit[i]
        if c == '\\' and i + 1 < len(lit):
            n = lit[i + 1]
            if n in 'x':
                j = i + 2
                while j < len(lit) and lit[j] in '0123456789abcdefABCDEF': j += 1
                out.append(int(lit[i + 2:j], 16) & 0xff); i = j; continue
            if n in '01234567':
                j = i + 1
                while j < len(lit) and j < i + 4 and lit[j] in '01234567': j += 1
                out.append(int(lit[i + 1:j], 8) & 0xff); i = j; continue
            out.append(ord({'n': '\n', 't': '\t', 'r': '\r', 'a': '\a', 'b': '\b', 'f': '\f', 'v': '\v'}.get(n, n)) & 0xff); i += 2; continue
        out.append(ord(c) & 0xff); i += 1
    return bytes(out)
_str_items = collections.defaultdict(list)
for _a, _g in gd.items():
    if _g['dtype'] in ('string', 'TerminatedCString') and _g['len'] > 1:
        _str_items[m.read(_a, _g['len']).split(b'\0')[0]].append(_a)
STRLIT_ARITH = re.compile(r'\(\s*"((?:[^"\\]|\\.)*)"\s*\+')
def fix_string_arith(txt):
    def r(mm):
        cands = _str_items.get(_c_unescape(mm.group(1)))
        if not cands or len(cands) != 1:
            return mm.group(0)
        strlit_fixed.append(cands[0])
        return '((char *)0x%x +' % cands[0]
    return STRLIT_ARITH.sub(r, txt)
strlit_fixed = []
body = fix_string_arith(body)
del strlit_fixed[:]
lit_syms = {}
biased_bases = []   # literals below a data section used as indexed table bases
zf_lits = []    # (literal, zerofill object start it is expressed from)
img_lo = min(s['addr'] for s in m.secs if s['size'])
img_hi = max(s['addr'] + s['size'] for s in m.secs if s['size'])
if cfg.get('symbolize_literals') and img_lo >= 0x10000000:
    # two adjacent address words folded into ONE 64-bit constant (Binding::GetString: the stock copies the two-entry table {"..%s..", "..%s.."} with an
    # `lfd`/`stfd` pair; Ghidra prints `0x97c2b3bc97c2b3dc`): split it so that each half is symbolised like any other image-address literal
    def _split64(mm):
        hi, lo = int(mm.group(1), 16), int(mm.group(2), 16)
        if img_lo <= hi < img_hi and img_lo <= lo < img_hi:
            return '(((unsigned long long)0x%08x << 32) | (unsigned long long)0x%08x)' % (hi, lo)
        return mm.group(0)
    body = re.sub(r'\b0x([0-9a-f]{8})([0-9a-f]{8})\b', _split64, body)
    _lit = set(int(x, 16) for x in re.findall(r'\b0x([0-9a-f]{8})\b', body))
    # Ghidra prints an address above 0x80000000 as a NEGATIVE constant (`(int)p < -0x584817f7` is `p < 0xa7b7e809`, a loop bound / end pointer)
    _lit |= set((1 << 32) - int(x, 16) for x in re.findall(r'(?<![\w)\]])-0x([0-9a-f]{1,8})\b', body))
    for v in sorted(_lit):
        sec_v = m.sec_at(v) if img_lo <= v < img_hi else None
        if sec_v is None or in_code(v):
            continue
        if (sec_v['flags'] & 0xff) in (1, 0xc):
            # zerofill: every named object there is emitted as its own .zerofill (no label can sit inside one), so the literal is expressed from the
            # object that contains it - the nearest named address at or below (glprog `(int)p < -0x584817f7` = GetSymbolTable()::SymbolTables + 0xd,
            # the end bound of its 3-pointer array; the literal had stayed the stock address and the initialisation loop ran once)
            _cands = [a_ for a_ in set(a2 for a2 in needed.values() if a2 is not None) | set(nlist_by_addr) if sec_v['addr'] <= a_ <= v]
            if not _cands:
                continue
            _b = max(_cands)
            zf_lits.append((v, _b))
        else:
            _b = v & ~3      # an unaligned value (`p <= 0xa7b7bb3c` normalised to `p < 0xa7b7bb3d`) is the aligned label plus a byte offset
        lit_syms[v] = ('SYM_%x' % _b, v - _b)
        needed['SYM_%x' % _b] = _b
    # biased table bases: `*(undefined4 *)(i * 4 + -0x584a7114)` - Ghidra folded `table - k*4` into a constant that lies BELOW the image's data (the
    # index is never small: GetGLStringForType's GL type enums 0x8b50..0x8b64). Such a literal (just below a section, used as `* N + LIT`) is expressed
    # from that section's start, so the displacement to the real table survives the rebuilt layout.
    _secs_sorted = sorted((s_['addr'], s_) for s_ in data_secs if s_['size'] and (s_['flags'] & 0xff) not in (1, 0xc))   # sections data.s emits whole
    for _mm in re.finditer(r'\*\s*\d+\s*\+\s*(-?)0x([0-9a-f]{1,8})\b', body):
        _v = int(_mm.group(2), 16)
        _v = (1 << 32) - _v if _mm.group(1) else _v
        if _v in lit_syms or m.sec_at(_v) is not None:
            continue
        _sec = next((s_ for sa_, s_ in _secs_sorted if sa_ > _v), None)
        # anchor = the first named object of that section (its first words can be toolchain data the link does not emit: glprog __data starts with
        # dyld's own pointers)
        _nxt = min((a_ for a_ in needed.values() if a_ is not None and _sec is not None and _sec['addr'] <= a_ < _sec['addr'] + _sec['size']), default=None)
        if _nxt is not None and _nxt - _v < 0x40000:
            lit_syms[_v] = ('SYM_%x' % _nxt, _v - _nxt)
            needed['SYM_%x' % _nxt] = _nxt
            biased_bases.append(_v)
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for nm in sorted(set(nm_ for nm_, _ in lit_syms.values())):
            f_.write('extern unsigned char %s asm("%s");\n' % (nm, nm))

# An image whose addresses are small (GLDriver: 0x1dc198) cannot symbolise every literal - masks and offsets look the same - but Ghidra folds a PIC
# `addis r2,r31,0x12; lwz r0,disp(r2)` into the ABSOLUTE stock address, printed `(x & 0x7c) + 0x1dc198` / `*(uint *)(i * 4 + 0x1dc0d8)`: an ADDRESS added to an
# index. Such a literal - inside a writable/const DATA section (not eh_frame, exception tables, zerofill), used as an operand of a binary `+` and not of a
# bitwise / comparison operator - is expressed from a label, so it survives the rebuilt layout (GLDriver FUN_000c1780 read 1.0f from a wrong address).
_CTX_LIT = re.compile(r'(?<![\w.])0x0*([0-9a-f]{5,8})\b')
ctx_lit_syms = {}
def _ctx_lit_ok(txt, mt):
    v = int(mt.group(1), 16)
    left = txt[max(0, mt.start() - 24):mt.start()].rstrip(); right = txt[mt.end():mt.end() + 6].lstrip()
    if not left or left[-1] in '"\'': return False
    lplus = left.endswith('+') and not left.endswith('++') and len(left) > 1 and re.search(r'[\w)\]]\s*\+$', left) is not None
    rplus = right.startswith('+') and not right.startswith('++')
    if not (lplus or rplus): return False
    if re.search(r'(&|\||\^|<|>|=|!|~|-|\*)\s*$', left) and not lplus: return False
    if re.match(r'(&|\||\^|<|>|=|!|\*)', right): return False
    return True
if cfg.get('symbolize_literals_ctx'):
    for mt in _CTX_LIT.finditer(body):
        v = int(mt.group(1), 16)
        if v in ctx_lit_syms or not (img_lo <= v < img_hi): continue
        sec_v = m.sec_at(v)
        if sec_v is None or in_code(v) or (sec_v['flags'] & 0xff) in (1, 0xc): continue
        if sec_v['name'] in ('__eh_frame', '__gcc_except_tab', '__dyld', '__la_symbol_ptr', '__nl_symbol_ptr') or not _ctx_lit_ok(body, mt): continue
        _b = v & ~3
        ctx_lit_syms[v] = ('SYM_%x' % _b, v - _b)
        needed['SYM_%x' % _b] = _b
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for nm in sorted(set(nm_ for nm_, _ in ctx_lit_syms.values())):
            f_.write('extern unsigned char %s asm("%s");\n' % (nm, nm))
    print('%d context-symbolised data address literals' % len(ctx_lit_syms))

# PIC anchors folded into numbers: the stock builds a data pointer as `anchor + offset` (`addis/addi` off the PIC base; Ghidra prints `local_58 = 0x1d6d90;` or
# `local_60 = FUN_001d8514;` and later `((unsigned char *)0x4ff4) + iVar7` = DAT_001dbd84). The anchor itself is not an address of anything (it lies in code or
# between objects), so no literal pass touches it and the rebuilt image, whose sections sit elsewhere, hands the callee a stock address. An assignment
# `v = L;` of such a value whose uses add ONE constant K (or several that land in one section) is rewritten to `v = (int)&SYM_T - K`, T = L + K the address the
# stock reaches, so the target follows the rebuilt layout (FUN_00096d80: the descriptor table pointer of every 0x12f4/0x12ec dispatch was a stock address).
anchor_edits = {}     # function name -> [(variable, literal text, replacement)]
anchor_skipped = []
anchor_code_syms = set()      # function names an anchor was re-expressed from
if cfg.get('symbolize_anchors'):
    _hdr = re.compile(r'(?m)^/\* (\S+) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n')
    _hs = list(_hdr.finditer(body))
    for _i, _h in enumerate(_hs):
        _chunk = body[_h.end():_hs[_i + 1].start() if _i + 1 < len(_hs) else len(body)]
        _addr_by_fn = {v_: k_ for k_, v_ in fn_by_addr.items()}
        for _a in re.finditer(r'(?m)^\s*([A-Za-z_]\w*) = (0x[0-9a-f]{5,6}|FUN_00[0-9a-f]{6}|[A-Za-z_]\w*);', _chunk):
            _lv, _lt = _a.group(1), _a.group(2)
            # a renamed function (`KhanVs__deleting_dtor_1d8514`) used as a folded PIC anchor is the same thing as its FUN_ text
            if _lt[:2] != '0x' and not _lt.startswith('FUN_'):
                if _lt not in _addr_by_fn: continue
                _L = _addr_by_fn[_lt]
            else:
                _L = int(_lt[4:], 16) if _lt.startswith('FUN_') else int(_lt, 16)
            if not (0x1000 <= _L < img_hi) or _L & 0xffff == 0 or _lv in [e_[0] for e_ in anchor_edits.get(_h.group(1), [])]: continue
            _al = {_lv}      # the variable and the variables it is copied into (`iVar7 = local_58;`)
            for _r in range(2):
                _al |= set(re.findall(r'(?m)^\s*([A-Za-z_]\w*) = (?:\([\w ]+\*?\))?(?:%s);' % '|'.join(re.escape(x_) for x_ in _al), _chunk))
            _ks = set()
            for _v in _al:
                _ks |= set(int(x, 16) for x in re.findall(r'\(\(unsigned char \*\)0x0*([0-9a-f]+)\)\s*\+\s*(?:\(int\))?%s\b' % _v, _chunk))
                _ks |= set(int(x, 16) for x in re.findall(r'\b%s\s*\+\s*0x0*([0-9a-f]+)\b' % _v, _chunk))
                _ks |= set(int(x) for x in re.findall(r'\b%s\s*\+\s*(\d{3,})\b' % _v, _chunk))
                _ks |= set(int(x, 16) for x in re.findall(r'\b0x0*([0-9a-f]+)\s*\+\s*(?:\(int\))?%s\b' % _v, _chunk))
                # a NEGATIVE offset (`v + -0x770`, `(int)v - 0x770`): the anchor lies above its target - R300SchedModel__vslot28's hash / equality callbacks,
                # the select-word constants of part_026 and the lane-kind tables of part_032 were all left at the STOCK address by the positive-only patterns
                _ks |= set(-int(x, 16) for x in re.findall(r'\b%s\s*\+\s*-0x0*([0-9a-f]+)\b' % _v, _chunk))
                _ks |= set(-int(x, 16) for x in re.findall(r'\(int\)%s\s*-\s*0x0*([0-9a-f]+)\b' % _v, _chunk))
            _ks = sorted(k_ for k_ in _ks if abs(k_) >= 0x100)
            if not _ks: continue
            _ts = [_L + k_ for k_ in _ks]
            _secs = [m.sec_at(t_) if img_lo <= t_ < img_hi else None for t_ in _ts]
            # ONE code target: the anchor was folded from `pic_base + (function - pic_base)`, i.e. a FUNCTION POINTER (a callback stored into a table); express it
            # from the function's own symbol so it follows the rebuilt layout (the stock address of the callback crashed combine / shadow in HashTable__find)
            if len(_ks) == 1 and img_lo <= _ts[0] < img_hi and in_code(_ts[0]) and _ts[0] in fn_by_addr:
                anchor_edits.setdefault(_h.group(1), []).append((_lv, _lt, '((int)%s - (%d))' % (fn_by_addr[_ts[0]], _ks[0])))
                anchor_code_syms.add(fn_by_addr[_ts[0]])
                continue
            if any(s_ is None or in_code(t_) or s_['name'] in ('__eh_frame', '__gcc_except_tab', '__dyld', '__la_symbol_ptr', '__nl_symbol_ptr') for s_, t_ in zip(_secs, _ts)) or len(set(s_['name'] for s_ in _secs)) != 1:
                anchor_skipped.append((_h.group(1), _lv, hex(_L), [hex(k_) for k_ in _ks])); continue
            _T, _K, _sec = _ts[0], _ks[0], _secs[0]
            if (_sec['flags'] & 0xff) in (1, 0xc):
                _cands = [a_ for a_ in set(a2 for a2 in needed.values() if a2 is not None) | set(nlist_by_addr) if _sec['addr'] <= a_ <= _T]
                if not _cands or any(max(a_ for a_ in _cands if a_ <= t_) != max(_cands) for t_ in _ts): anchor_skipped.append((_h.group(1), _lv, hex(_L), 'zerofill')); continue
                _b = max(_cands)
            else:
                _b = _T & ~3
            needed['SYM_%x' % _b] = _b
            anchor_edits.setdefault(_h.group(1), []).append((_lv, _lt, '((int)&SYM_%x + %d - (%d))' % (_b, _T - _b, _K)))
        # `v = &PTR_DAT_001f4850;` used as `v + 0x1766` (pointer arithmetic by the element size of v's type): Ghidra folded `&other_object` into `&this + k*elem`; the
        # sum leaves this object (and may leave its section), so it is expressed from the object the stock reaches
        _ESZ = {'undefined': 1, 'char': 1, 'byte': 1, 'uchar': 1, 'undefined1': 1, 'undefined2': 2, 'short': 2, 'ushort': 2}
        for _a in re.finditer(r'(?m)^\s*([A-Za-z_]\w*) = &(\w+);', _chunk):
            _lv, _nm0 = _a.group(1), _a.group(2)
            _A0 = addr_of_name(_nm0)
            if _A0 is None or not (img_lo <= _A0 < img_hi) or _lv in [e_[0] for e_ in anchor_edits.get(_h.group(1), [])]: continue
            _dm = re.search(r'(?m)^  ([A-Za-z_][\w ]*?)\s*(\**)\s*%s;' % _lv, _chunk)
            if not _dm: continue
            _nst = len(_dm.group(2)) + _dm.group(1).count('*')
            _esz = 4 if _nst >= 2 else _ESZ.get(_dm.group(1).split()[-1], 4) if _nst == 1 else None
            if _esz is None: continue
            _al = {_lv}
            _ksb = set(int(x, 16) for x in re.findall(r'(?<!\(int\))\b%s\s*\+\s*0x0*([0-9a-f]+)\b' % _lv, _chunk))
            _ksb = set(k_ * _esz for k_ in _ksb)                         # `v + k` is scaled by the element size, `(int)v + k` is bytes
            _ksb |= set(int(x, 16) for x in re.findall(r'\(int\)%s\s*\+\s*0x0*([0-9a-f]+)\b' % _lv, _chunk))
            _ksb |= set(int(x) for x in re.findall(r'\(int\)%s\s*\+\s*(\d{3,})\b' % _lv, _chunk))
            _ks = sorted(k_ for k_ in _ksb if k_ >= 0x400)
            if not _ks: continue
            _ts = [_A0 + k_ for k_ in _ks]
            _secs = [m.sec_at(t_) if img_lo <= t_ < img_hi else None for t_ in _ts]
            if any(s_ is None or in_code(t_) or s_['name'] in ('__eh_frame', '__gcc_except_tab', '__dyld', '__la_symbol_ptr', '__nl_symbol_ptr') for s_, t_ in zip(_secs, _ts)) or len(set(s_['name'] for s_ in _secs)) != 1:
                anchor_skipped.append((_h.group(1), _lv, _nm0, [hex(k_) for k_ in _ks])); continue
            _T, _K, _sec = _ts[0], _ks[0], _secs[0]
            if (_sec['flags'] & 0xff) in (1, 0xc):
                _cands = [a_ for a_ in set(a2 for a2 in needed.values() if a2 is not None) | set(nlist_by_addr) if _sec['addr'] <= a_ <= _T]
                if not _cands or any(max(a_ for a_ in _cands if a_ <= t_) != max(_cands) for t_ in _ts): anchor_skipped.append((_h.group(1), _lv, _nm0, 'zerofill')); continue
                _b = max(_cands)
            else:
                _b = _T & ~3
            needed['SYM_%x' % _b] = _b
            anchor_edits.setdefault(_h.group(1), []).append((_lv, '&' + _nm0, '((%s)((int)&SYM_%x + %d - %d))' % ((_dm.group(1) + ' ' + _dm.group(2)).strip() + (' *' if False else '') if False else 'void *', _b, _T - _b, _K)))
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for _nm in sorted(set(re.search(r'SYM_[0-9a-f]+', r_[2]).group(0) for v_ in anchor_edits.values() for r_ in v_ if re.search(r'SYM_[0-9a-f]+', r_[2]))):
            f_.write('extern unsigned char %s asm("%s");\n' % (_nm, _nm))
    print('%d anchor assignments symbolised in %d functions (%d skipped, %d re-expressed from a function symbol)' % (sum(len(v_) for v_ in anchor_edits.values()), len(anchor_edits), len(anchor_skipped), len(anchor_code_syms)))
    for _s in anchor_skipped: print('  anchor skipped:', _s)

# Folded PIC bases (images at their stock addresses: glprog, libGL; issue #227). The stock reaches a data object / vtable as `lis/addi` (or `addis rX,r31,hi`) off a
# PIC register; Ghidra, which knows r31, prints the SUM as one constant - `picBase = 0xa7b81734;` ... `(picBase - 0x473c)` (a vtable stored into a new object),
# `**(undefined1 **)(picBaseConst + -0x7cc4)` (a std::string terminator slot), `terminatorGlobalBase = -0x58488c94;` - or a bare leftover of such a register passed on as an
# argument nobody reads (`fwdR9 = 0xa7b79cdc;`, `..., scratchR8, 0xa7b7faf0)`). The constant lies in no section (a base is the target minus a 16-bit displacement),
# so symbolize_literals leaves it, and the rebuilt image, whose sections sit elsewhere, reads and stores STOCK addresses: it works only while the stock image is mapped
# at the same place (every side-by-side test) and crashes in a process where it is not (Godot's yyparse). A variable assigned such a constant whose uses all add ONE
# displacement (or several landing in one section) is re-expressed from a label, `v = (int)&SYM_T + (T - T&~3) - K`, so the target follows the rebuilt layout; one whose only
# uses are bare call arguments / copies is a dead leftover and becomes 0 (no callee can interpret a PIC temporary of the stock layout). Anything else is left alone and
# caught by the stale-literal gate below.
pic_base_edits = {}      # function name -> [(variable, rhs text, replacement)]
pic_base_log = []
pic_base_skipped = []
STOCK_SEGS = [(s_['vmaddr'], s_['vmaddr'] + s_['vmsize']) for s_ in m.segs if s_['vmsize'] and s_['name'] != '__PAGEZERO']
def near_image(v, margin=0x10000):
    return img_lo >= 0x10000000 and any(a_ - margin <= v < b_ + margin for a_, b_ in STOCK_SEGS)
def _lit_val(txt):
    mt = re.fullmatch(r'(?:\(([\w ]+?\s*\**)\))?\s*(-?)0x([0-9a-f]{5,8})', txt.strip())
    if not mt: return None
    v = int(mt.group(3), 16)
    return ((-v) & 0xffffffff if mt.group(2) else v), (mt.group(1) or '')
if cfg.get('symbolize_pic_bases') and img_lo >= 0x10000000:
    _hdr = re.compile(r'(?m)^/\* (\S+) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n')
    _hs = list(_hdr.finditer(body))
    _ASG = re.compile(r'(?m)^(\s*)([A-Za-z_]\w*) = ((?:\([\w ]+?\s*\**\))?\s*-?0x[0-9a-f]{5,8});')
    for _i, _h in enumerate(_hs):
        _chunk = body[_h.end():_hs[_i + 1].start() if _i + 1 < len(_hs) else len(body)]
        _fn = _h.group(1)
        _groups = collections.OrderedDict()      # variable -> {rhs text: value}
        for _a in _ASG.finditer(_chunk):
            _lv = _lit_val(_a.group(3))
            if _lv is None: continue
            _L = _lv[0]
            if not near_image(_L) or (img_lo <= _L < img_hi and m.sec_at(_L) is not None and not in_code(_L)): continue     # symbolize_literals' (a label address)
            _groups.setdefault(_a.group(2), {})[_a.group(3)] = _L
        _sib = {}      # constant -> the anchor expression of a variable that holds it and is offset (a dead leftover of the SAME PIC register gets the same value)
        for _pass in (0, 1):
            for _v, _rhs in _groups.items():
                if len(set(_rhs.values())) != 1:
                    pic_base_skipped.append((_fn, _v, 'assigned different constants')); continue
                _L = next(iter(_rhs.values()))
                _dm = re.search(r'(?m)^  ([A-Za-z_][\w ]*?)\s*(\**)\s*%s;' % re.escape(_v), _chunk)
                _ty = (_dm.group(1) if _dm else '').split()[-1:] or ['']
                if _dm and (len(_dm.group(2)) + _dm.group(1).count('*')) and _ty[0] not in ('char', 'uchar', 'byte', 'undefined', 'undefined1', 'void'):
                    pic_base_skipped.append((_fn, _v, 'pointer to a non-byte type: displacements are scaled')); continue
                _al = {_v}      # the variable and the variables it is copied into (`staleR8Value = picBase;`)
                for _r in range(3):
                    _al |= set(re.findall(r'(?m)^\s*([A-Za-z_]\w*) = (?:\([\w ]+?\s*\**\))?(?:%s);' % '|'.join(re.escape(x_) for x_ in _al), _chunk))
                _ks = collections.Counter(); _other = 0; _nullcmp = 0
                _forced_dead = any(d_['func'] == _fn and d_['var'] == _v for d_ in cfg.get('pic_base_dead', []))
                for _x in ([] if _forced_dead else _al):
                    for _um in re.finditer(r'\b%s\b' % re.escape(_x), _chunk):
                        _ls = _chunk.rfind('\n', 0, _um.start()) + 1; _le = _chunk.find('\n', _um.end()); _le = len(_chunk) if _le < 0 else _le
                        _line = _chunk[_ls:_le]; _after = _chunk[_um.end():_um.end() + 40]; _before = _chunk[max(0, _um.start() - 60):_um.start()]
                        if re.fullmatch(r'\s*[A-Za-z_][\w ]*?\s*\**\s*%s;\s*' % re.escape(_x), _line):
                            continue                                      # a declaration
                        if re.match(r'\s*=(?!=)', _after):
                            continue                                      # `x = ...` the assignment's left-hand side (any statement or comma expression)
                        _km = re.match(r'\s*([+-])\s*(-?)(0x[0-9a-f]+|\d+)\b', _after)
                        if _km and not re.match(r'\s*[*/%.\[]', _after[_km.end():]):
                            _k = int(_km.group(3), 0)
                            _k = -_k if _km.group(2) else _k
                            _ks[_k if _km.group(1) == '+' else -_k] += 1
                            continue
                        if re.match(r'\s*[,)]', _after) and re.search(r'[(,]\s*(\([\w ]+?\s*\**\))?\s*$', _before):
                            continue                                      # a bare call argument (the list may continue on the next line)
                        if re.match(r'\s*;', _after) and re.fullmatch(r'(?s).*\n\s*[A-Za-z_]\w*\s*=\s*(\([\w ]+?\s*\**\))?\s*', '\n' + _before.split('\n')[-1]):
                            continue                                      # `y = x;` (y is in the alias set)
                        if re.match(r'\s*[!=]=\s*(\([\w ]+?\s*\**\))?\s*(0x0|0)\b', _after):
                            _nullcmp += 1; continue                       # a NULL test: true only if the value is 0
                        _other += 1
                        pic_base_log.append((_fn, _x, 'unrecognised use', _line.strip()[:120]))
                if _other:
                    pic_base_skipped.append((_fn, _v, '%d use(s) of an unrecognised shape' % _other)); continue
                _rhs_txt = next(iter(_rhs))
                _cast = re.match(r'(\([\w ]+?\s*\**\))?', _rhs_txt).group(1) or ''
                if not _ks:
                    if _pass == 0: continue
                    if _L in _sib:
                        pic_base_edits.setdefault(_fn, []).append((_v, _rhs_txt, '%s%s' % (_cast, _sib[_L])))
                        pic_base_log.append((_fn, _v, hex(_L), 'dead leftover of the PIC register an anchor of this function is built from -> same anchor'))
                    elif _nullcmp:
                        pic_base_skipped.append((_fn, _v, 'a NULL test of a value that would become 0')); continue
                    else:
                        pic_base_edits.setdefault(_fn, []).append((_v, _rhs_txt, '%s0' % _cast))
                        pic_base_log.append((_fn, _v, hex(_L), 'dead leftover -> 0'))
                    continue
                if _pass == 1: continue
                _kl = sorted(_ks)
                _ts = [(_L + k_) & 0xffffffff for k_ in _kl]
                _secs = [m.sec_at(t_) if img_lo <= t_ < img_hi else None for t_ in _ts]
                if any(s_ is None or in_code(t_) or s_['name'] in ('__eh_frame', '__gcc_except_tab', '__dyld', '__la_symbol_ptr', '__nl_symbol_ptr') for s_, t_ in zip(_secs, _ts)) or len(set(s_['name'] for s_ in _secs)) != 1:
                    pic_base_skipped.append((_fn, _v, 'targets %s not all in one data section (%s)' % ([hex(t_) for t_ in _ts], [s_['name'] if s_ else None for s_ in _secs]))); continue
                _T, _K, _sec = _ts[0], _kl[0], _secs[0]
                if (_sec['flags'] & 0xff) in (1, 0xc):
                    _cands = [a_ for a_ in set(a2 for a2 in needed.values() if a2 is not None) | set(nlist_by_addr) if _sec['addr'] <= a_ <= _T]
                    if not _cands or any(max(a_ for a_ in _cands if a_ <= t_) != max(_cands) for t_ in _ts):
                        pic_base_skipped.append((_fn, _v, 'zerofill targets span several objects')); continue
                    _b = max(_cands)
                else:
                    _b = _T & ~3
                needed['SYM_%x' % _b] = _b
                _sib.setdefault(_L, '((int)&SYM_%x + %d - (%d))' % (_b, _T - _b, _K))
                pic_base_edits.setdefault(_fn, []).append((_v, _rhs_txt, '%s((int)&SYM_%x + %d - (%d))' % (_cast, _b, _T - _b, _K)))
                pic_base_log.append((_fn, _v, hex(_L), 'anchor of %s -> &SYM_%x%+d' % ([hex(t_) for t_ in _ts], _b, _T - _b)))
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for _nm in sorted(set(re.search(r'SYM_[0-9a-f]+', r_[2]).group(0) for v_ in pic_base_edits.values() for r_ in v_ if re.search(r'SYM_[0-9a-f]+', r_[2]))):
            f_.write('extern unsigned char %s asm("%s");\n' % (_nm, _nm))
    print('%d folded PIC-base assignments re-expressed in %d functions (%d skipped)' % (sum(len(v_) for v_ in pic_base_edits.values()), len(pic_base_edits), len(pic_base_skipped)))
    for _s in dict.fromkeys(pic_base_skipped): print('  PIC base skipped:', _s)
    for _s in pic_base_log:
        if _s[2] == 'unrecognised use': print('  PIC base unrecognised use:', _s)

# names that are really numeric constants Ghidra labelled as data (`&DAT_00010001` = 0x10001, an address in no section of the image, or `UINT_00002ee0` in code)
const_names = []
for nm, a in sorted(needed.items()):
    if a is None:
        continue
    sec_ = m.sec_at(a)
    zf = any(s2['addr'] <= a < s2['addr'] + s2['size'] for s2 in m.secs if (s2['flags'] & 0xff) in (1, 0xc))
    if nm not in cfg.get('data_label_overrides', {}) and (sec_ is None and not zf and nm not in TOOLCHAIN_DATA and a not in nlist_by_addr) or (re.match(r'^(UINT|INT|SHORT|BYTE|LAB)_', nm) and in_code(a)):
        const_names.append(nm)
for nm in const_names:
    needed.pop(nm, None)

# names the decompile gives to code addresses (`&_radeonCopyRegion`): alias to the function's own label, or - when the name marks a clipped function
# entry (a few instructions that fall through into the next function; raw/code_extents.tsv) - a tiny asm entry that branches on to it
extents = []
_p = os.path.join(corpus, 'raw', 'code_extents.tsv')
if os.path.exists(_p):
    for l in open(_p):
        f = l.split()
        if len(f) >= 2:
            extents.append((int(f[0], 16), int(f[1], 16)))
clipped_entries = []
clipped_blocks = []      # (entry names, machine words, ledger name of the function they fall into, stock start address) - emitted into that function's translation unit
code_alias, code_s = ['#define %s (*(unsigned char *)0x%x)   /* a numeric constant, not an object */' % (nm, data_addr(nm) or 0) for nm in const_names], ['.text', '.align 2']
for nm, a in sorted(needed.items()):
    if a is not None and in_code(a) and nm not in fn_by_addr.values():
        e = fn_by_addr.get(a)
        ext = next(((lo, hi) for lo, hi in extents if lo == a), None)
        if e and '+' not in e:
            code_alias.append('#define %s %s' % (nm, e))
        elif ext and ext[1] in fn_by_addr:
            clipped_blocks.append(([nm], [struct.unpack('>I', m.read(w, 4))[0] for w in range(ext[0], ext[1], 4)], fn_by_addr[ext[1]], ext[0]))
            clipped_entries.append(nm)
        else:
            code_alias.append('/* %s at 0x%x: no function starts there */' % (nm, a))
for a_, ss_ in sorted(nlist_by_addr.items()):
    if not in_code(a_) or a_ in fn_by_addr:
        continue
    ext_ = next(((lo, hi) for lo, hi in extents if lo == a_), None)
    if ext_ and ext_[1] in fn_by_addr:
        # register save/restore millicode (saveFP/restFP chains) is toolchain code: the compiled functions use gcc's own, and a chain continued into
        # the C transcription of the next chain segment would be meaningless
        nms_ = [s_['name'] for s_ in ss_ if s_['name'] not in clipped_entries and not toolchain_fn(s_['name'], a_)]
        clipped_entries.extend(nms_)
        if nms_:
            clipped_blocks.append((nms_, [struct.unpack('>I', m.read(w, 4))[0] for w in range(ext_[0], ext_[1], 4)], fn_by_addr[ext_[1]], ext_[0]))
open(os.path.join(out, 'code.s'), 'w').write('\n'.join(code_s) + '\n')
stub_secs = [s_ for s_ in m.secs if (s_['flags'] & 0xff) == 8 and s_['r2']]   # S_SYMBOL_STUBS: one indirect-table entry per r2-byte stub
def code_target_name(t):
    """the symbol the rebuilt image knows the stock code address `t` by: a ledger function, a symbol-table name, or the import a dyld stub stands for"""
    if t in fn_by_addr:
        return fn_label.get(fn_by_addr[t], fn_by_addr[t])
    for s_ in nlist_by_addr.get(t, []):
        return s_['name']
    for s_ in stub_secs:
        if s_['addr'] <= t < s_['addr'] + s_['size'] and (t - s_['addr']) % s_['r2'] == 0:
            n_ = indirect_name(s_, (t - s_['addr']) // s_['r2'])
            if n_:
                return n_
    ext_ = next(((lo, hi) for lo, hi in extents if lo == t), None) if 'raw_entries' in globals() else None
    if ext_ is not None:
        # a raw code extent starts there (code no function owns and nothing names, reached only by a branch from another raw block: GLEngine
        # 0x22590 `b 0x262cc`, the target of `beq` in the _gleSetEnable_* extent at 0x22574): it is emitted as its own _raw_entry_<addr>
        raw_entries[t] = ext_
        return '_raw_entry_%x' % t
    return None
clip_stubs = []   # (label, symbol) of the stubs the clipped entries being emitted need
def clip_stub(addr, n_):
    """a PIC symbol stub + lazy pointer for a branch from a clipped entry, as gcc emits for a call: dyld 10.4 cannot apply an external BR24/BR14
    relocation (a direct `b _free`, or `b` to an exported function of the image itself: "unknown external relocation type" at dlopen)"""
    lab = 'Lclip_%x_%d' % (addr, len(clip_stubs))
    clip_stubs.append((lab, n_))
    return lab + '_stub'
def clip_stub_asm():
    t = ''.join('.section __TEXT,__picsymbolstub1,symbol_stubs,pure_instructions,32\\n.align 2\\n%s_stub:\\n.indirect_symbol %s\\nmflr r0\\nbcl 20,31,%s_pb\\n'
                '%s_pb:\\nmflr r11\\naddis r11,r11,ha16(%s_lp-%s_pb)\\nmtlr r0\\nlwzu r12,lo16(%s_lp-%s_pb)(r11)\\nmtctr r12\\nbctr\\n'
                '.lazy_symbol_pointer\\n%s_lp:\\n.indirect_symbol %s\\n.long dyld_stub_binding_helper\\n' % (l_, n_, l_, l_, l_, l_, l_, l_, l_, n_)
                for l_, n_ in clip_stubs)
    del clip_stubs[:]
    return t
def clipped_word(addr, w, loc=None):
    """one machine word of a clipped entry as assembler: position-dependent instructions (relative branches) are rewritten symbolically, a PIC-base
    sequence (`bcl 20,31`) is refused - its addis/lwz offsets are relative to the stock layout"""
    op = w >> 26
    if w == 0x429f0005:
        raise SystemExit('clipped entry at 0x%x computes a PIC base (bcl 20,31): its data offsets would be wrong in the rebuilt layout' % addr)
    if op == 18 and not w & 2:
        d = w & 0x03fffffc
        t = (addr + (d - 0x04000000 if d & 0x02000000 else d)) & 0xffffffff
        if loc and loc[0] <= t < loc[1]:
            return '%s Lre_%x_%x' % ('bl' if w & 1 else 'b', loc[0], t)     # a branch inside the same raw extent stays a plain relative branch to a local label
        n_ = code_target_name(t)
        if n_ is None:
            raise SystemExit('clipped entry at 0x%x branches to 0x%x, which has no symbol' % (addr, t))
        return '%s %s' % ('bl' if w & 1 else 'b', clip_stub(addr, n_))
    if op == 16 and not w & 2:
        d = w & 0xfffc
        t = (addr + (d - 0x10000 if d & 0x8000 else d)) & 0xffffffff
        if loc and loc[0] <= t < loc[1]:
            return 'bc%s %d,%d,Lre_%x_%x' % ('l' if w & 1 else '', (w >> 21) & 31, (w >> 16) & 31, loc[0], t)
        n_ = code_target_name(t)
        if n_ is None:
            raise SystemExit('clipped entry at 0x%x branches to 0x%x, which has no symbol' % (addr, t))
        return 'bc%s %d,%d,%s' % ('l' if w & 1 else '', (w >> 21) & 31, (w >> 16) & 31, clip_stub(addr, n_))
    return '.long 0x%08x' % w
PIC_DFORM = {14: 'addi', 32: 'lwz', 33: 'lwzu', 34: 'lbz', 35: 'lbzu', 36: 'stw', 37: 'stwu', 38: 'stb', 39: 'stbu', 40: 'lhz', 41: 'lhzu', 42: 'lha', 43: 'lhau',
             44: 'sth', 45: 'sthu', 48: 'lfs', 49: 'lfsu', 50: 'lfd', 51: 'lfdu', 52: 'stfs', 53: 'stfsu', 54: 'stfd', 55: 'stfdu'}
def pic_fixups(lo_, ws_):
    """a raw extent's PIC-base data accesses (`bcl 20,31,+4; mflr rX; ... addis rD,rX,H; lfd f,d(rD)`: the stock reaches a constant by its offset from the
    sequence's own address, which the rebuilt layout changes). Returns {word index: ('hi'|'lo', target address)}: straight-line register tracking from the
    bcl; the rebuilt code addresses the object absolutely (lis/ha16 + lo16(label)(reg)), like the rest of the image (-mdynamic-no-pic)"""
    fx_, regs_, lr_ = {}, {}, None
    for i_, w_ in enumerate(ws_):
        a_ = lo_ + 4 * i_; op_ = w_ >> 26
        if w_ == 0x429f0005:
            lr_ = a_ + 4
        elif (w_ & 0xfc1fffff) == 0x7c0802a6 and lr_ is not None:                # mflr rX
            regs_[(w_ >> 21) & 31] = (lr_, None)
        elif op_ == 15 and ((w_ >> 16) & 31) in regs_:                           # addis rD,rX,H
            rd_, ra_ = (w_ >> 21) & 31, (w_ >> 16) & 31
            base_ = (regs_[ra_][0] + ((w_ & 0xffff) << 16)) & 0xffffffff
            regs_[rd_] = (base_, i_)
            fx_[i_] = ('hi', None, rd_)
        elif op_ in PIC_DFORM and ((w_ >> 16) & 31) in regs_:
            ra_ = (w_ >> 16) & 31; base_, hi_i_ = regs_[ra_]
            if hi_i_ is None:
                raise SystemExit('raw code at 0x%x uses the PIC base register directly (word 0x%08x)' % (a_, w_))
            d_ = w_ & 0xffff
            t_ = (base_ + (d_ - 0x10000 if d_ & 0x8000 else d_)) & 0xffffffff
            if fx_[hi_i_][1] not in (None, t_):
                raise SystemExit('raw code at 0x%x: one PIC addis reaches two objects (0x%x, 0x%x); ha16/lo16 would need distinct pairs' % (a_, fx_[hi_i_][1], t_))
            fx_[i_] = ('lo', t_, ra_)
            fx_[hi_i_] = ('hi', t_, fx_[hi_i_][2])
            if (op_ not in (36, 37, 38, 39, 44, 45, 52, 53, 54, 55)) and ((w_ >> 21) & 31) == ra_ and op_ < 48:
                regs_.pop(ra_, None)                                            # the load overwrote the base register
    return {i_: v_ for i_, v_ in fx_.items() if v_[1] is not None}
def pic_word(addr, w, kind, t):
    op_ = w >> 26
    if kind == 'hi':
        return 'lis r%d,ha16(%s)' % ((w >> 21) & 31, first_name_of(t))
    rt_ = (w >> 21) & 31; ra_ = (w >> 16) & 31
    rt_s = ('f%d' if 48 <= op_ <= 55 else 'r%d') % rt_
    if op_ == 14:
        return 'addi %s,r%d,lo16(%s)' % (rt_s, ra_, first_name_of(t))
    return '%s %s,lo16(%s)(r%d)' % (PIC_DFORM[op_], rt_s, first_name_of(t), ra_)
def clipped_lines(lo_, ws_):
    """the words of a raw code extent starting at stock address lo_ as assembler lines: relative branches are symbolic (clipped_word), and a branch to
    another word of the SAME extent stays a relative branch to a local label (GLEngine: the extent 0x1ed50 has `bne 0x1ed80` / `b 0x1ed84` inside itself)"""
    hi_ = lo_ + 4 * len(ws_)
    tg_ = set()
    for i_, w_ in enumerate(ws_):
        a_ = lo_ + 4 * i_
        if (w_ >> 26) == 18 and not w_ & 2:
            d_ = w_ & 0x03fffffc; t2_ = (a_ + (d_ - 0x04000000 if d_ & 0x02000000 else d_)) & 0xffffffff
        elif (w_ >> 26) == 16 and not w_ & 2:
            d_ = w_ & 0xfffc; t2_ = (a_ + (d_ - 0x10000 if d_ & 0x8000 else d_)) & 0xffffffff
        else:
            continue
        if lo_ <= t2_ < hi_:
            tg_.add(t2_)
    out_ = []
    fx_ = pic_fixups(lo_, ws_)
    for i_, w_ in enumerate(ws_):
        a_ = lo_ + 4 * i_
        if a_ in tg_:
            out_.append('Lre_%x_%x:' % (lo_, a_))
        if i_ in fx_:
            out_.append(pic_word(a_, w_, fx_[i_][0], fx_[i_][1]))
        elif w_ == 0x429f0005 and fx_:
            out_ += ['bcl 20,31,Lpic_%x' % a_, 'Lpic_%x:' % a_]               # the PIC sequence stays (its base register is dead once the data accesses are absolute)
        else:
            out_.append(clipped_word(a_, w_, (lo_, hi_)))
    return out_
for _n in sorted({n_ for n_ in re.findall(r'\bthunk_(FUN_[0-9a-f]+)\b', _all_body)}):
    # the thunk targets the function at the address in its name; once that function has been renamed (FUN_00134de8 -> RegAlloc__registerOfInst) `FUN_<addr>` no longer exists
    code_alias.append('#define thunk_%s %s' % (_n, fn_by_addr.get(int(_n[4:], 16), _n)))
if code_alias:
    with open(os.path.join(out, 'decls.h'), 'a') as f:
        f.write('\n'.join(code_alias) + '\n')

# ---------------------------------------------------------------------------------------------- pointer words
reloc_at = {r['addr']: r for r in m.relocs}
for lst in m.sec_relocs.values():
    for r in lst:
        reloc_at.setdefault(r['addr'], r)

ret64_names = set(re.findall(r'(?m)^(?:extern\s+)?(?:ulonglong|longlong|undefined8|unsigned long long|long long)\s+\**\s*(\w+)\s*\(', _all_body + '\n'.join(decls)))

def fn_symbol_for(addr):
    """asm symbol expression for a code address"""
    if addr in fn_by_addr:
        return fn_label.get(fn_by_addr[addr], fn_by_addr[addr])
    k = None
    lo, hi = 0, len(fn_addrs)
    while lo < hi:
        mid = (lo + hi) // 2
        if fn_addrs[mid] <= addr:
            lo = mid + 1
        else:
            hi = mid
    if lo:
        base = fn_addrs[lo - 1]
        # only inside the function's own extent
        for a, s, n, p in ledger:
            if a == base and addr < a + max(s, 4):
                # a function whose chunk starts with alignment `nop`s (the ledger's extent runs from the previous function's end to the next entry): the
                # pointer is to the REAL entry, which is where the compiled C function begins - `label+12` would land in the middle of the compiled body
                # (orph_4c544+12: the ctx+0x1338 callback; called, it ran into the rebuilt prologue's middle and the state packet FUN_00086710 was never emitted)
                if all(struct.unpack('>I', m.read(x_, 4))[0] == 0x60000000 for x_ in range(a, addr, 4)):
                    return fn_label.get(n, n)
                return '%s+%d' % (fn_label.get(n, n), addr - a)
    return None

targets = set()        # data addresses that need a label
for _nm, _sp in cfg.get('data_anchors', {}).items():
    targets.add(int(_sp['base'], 16))      # the object a PIC anchor is measured from needs a label
# data objects no pointer word and no anchor reaches (a token stream nothing in the stock references) get their LD_<address> label from the config, so a `target` row can name them
for _a in cfg.get('extra_data_labels', []):
    targets.add(int(_a, 16))
ghidra_ptr_words = []
prebound_import_words, ext_addend_fixed = [], []   # external-reloc words: prebound import values dropped / addends corrected
unresolved_ptr_words = []   # (address, value) of relocated data words whose target has no symbol in the link
raw_entries = {}            # stock address -> (lo, hi) raw code extent that data points at and no function owns
raw_extra_labels = collections.defaultdict(list)   # raw entry address -> further assembler labels (a failed function's own name)
def register_raw(t, ext):
    raw_entries[t] = ext
    for _i, (_k, _t, _r) in pic_fixups(ext[0], [struct.unpack('>I', m.read(_a, 4))[0] for _a in range(ext[0], ext[1], 4)]).items():
        if m.sec_at(_t) is not None:
            targets.add(_t)           # the constant a PIC-base access of the entry reaches needs its label
for _a in cfg.get('extra_raw_entries', []):      # code a name used by the decompile (`label_overrides`) stands for, with no function and no data word reaching it (a Ghidra thunk, `b <fn>`)
    _a = int(_a, 16)
    register_raw(_a, next((e_ for e_ in extents if e_[0] == _a), None) or (_a, _a + 4))
for _a, _sz, _nm in failed_fns:
    register_raw(_a, (_a, _a + _sz))
    raw_extra_labels[_a].append(fn_label.get(_nm, _nm))
def raw_entry_asm():
    """the raw entries as assembler: the stock words, relative branches symbolic (via stubs), and a branch to whatever follows the block when its
    last instruction is not an unconditional transfer (b / blr / bctr), since the next stock block is not laid out after it here"""
    out_ = []
    done_ = set()
    while True:             # emitting a block can add entries (a branch to another raw extent, code_target_name): work until none is new
        todo_ = sorted(t_ for t_ in raw_entries if t_ not in done_)
        if not todo_:
            break
        t_ = todo_[0]; done_.add(t_); lo_, hi_ = raw_entries[t_]
        ws_ = [struct.unpack('>I', m.read(a_, 4))[0] for a_ in range(lo_, hi_, 4)]
        out_ += ['.globl _raw_entry_%x' % t_, '_raw_entry_%x:' % t_]
        for _l in raw_extra_labels.get(t_, []):
            out_ += ['.globl %s' % _l, '%s:' % _l]
        out_ += clipped_lines(lo_, ws_)
        last_ = ws_[-1]
        if not ((last_ >> 26) == 18 and not last_ & 3) and last_ not in (0x4e800020, 0x4e800420):
            n_ = code_target_name(hi_)
            if n_ is None:
                raise SystemExit('raw entry 0x%x falls through to 0x%x, which has no symbol' % (t_, hi_))
            out_.append('b %s' % clip_stub(hi_, n_))
        out_.append(clip_stub_asm().replace('\\n', '\n') + '.text')
    return out_
word_expr = {}         # addr -> asm expression for that word (pointer words), decided in pass 1
clipped_at = {start_: names_[0] for names_, words_, target_, start_ in clipped_blocks}
HEADER_SYM = {6: '__mh_dylib_header', 8: '__mh_bundle_header', 2: '__mh_execute_header'}.get(m.filetype)
text_seg_addr = next((sg['vmaddr'] for sg in m.segs if sg['name'] == '__TEXT'), None)
def classify_target(t):
    if t == text_seg_addr and HEADER_SYM:
        return HEADER_SYM              # the image's own Mach header (a word the stock's crt/atexit code passes as the image handle)
    if in_code(t):
        e = fn_symbol_for(t)
        if e is None and t in clipped_at:
            e = clipped_at[t]          # a clipped entry (emitted as asm next to the function it falls into): `_noop` in a glprog InputSrc record
        if e is None and any(lo == t for lo, hi in extents):
            pass                       # a raw extent starts here (code no ledger function owns): it is emitted as _raw_entry_<addr> below, whatever name the stock's nlist gives it (GLEngine: the _gle*Filter{1,2,3} pixel-conversion routines, reached only through data pointers and not defined by any corpus function)
        elif e is None and not any(sc_['name'] == '__text' and sc_['addr'] <= t < sc_['addr'] + sc_['size'] for sc_ in code_secs):
            e = next((ss['name'] for ss in nlist_by_addr.get(t, [])), None)   # (stub sections etc.: the symbol the stock's table gives it)
        if e is None:
            # the stock names t, but no corpus function starts there (code Ghidra folded into the function that follows it: GLEngine `_glNormal3d_Exec`
            # 0x78060, 7 instructions inside _glNormal3d_CompExec's ranges): a raw entry with the stock's words, the data pointer reaches it by label
            ext_ = next(((lo, hi) for lo, hi in extents if lo == t), None)
            if ext_ is None:
                # no raw extent starts there: code Ghidra filed as a detached range of some other function (GLDriver 0x19a468, a 7-instruction
                # virtual method listed under FUN_0019d480). The entry runs to its first unconditional transfer.
                for k_ in range(64):
                    w_ = struct.unpack('>I', m.read(t + 4 * k_, 4))[0]
                    if ((w_ >> 26) == 18 and not w_ & 3) or w_ in (0x4e800020, 0x4e800420):
                        ext_ = (t, t + 4 * k_ + 4)
                        break
                if ext_:
                    # the block may branch on to more of the same unowned code: a stock-named routine Ghidra filed as a detached range of the NEXT function
                    # (GLEngine _glPNTrianglesfATIX_Exec 0x7e354, 144 bytes below _glPNTrianglesfATIX_CompExec: `blt 0x7e374` leaves its first block).
                    # Then the entry is the whole gap, up to the next function's entry.
                    gend_ = min((a_ for a_ in fn_by_addr if a_ > t), default=None)
                    if gend_ is not None and gend_ > ext_[1]:
                        for a_ in range(ext_[0], ext_[1], 4):
                            w_ = struct.unpack('>I', m.read(a_, 4))[0]
                            d_ = None
                            if (w_ >> 26) == 18 and not w_ & 2:
                                d_ = w_ & 0x03fffffc; d_ = d_ - 0x04000000 if d_ & 0x02000000 else d_
                            elif (w_ >> 26) == 16 and not w_ & 2:
                                d_ = w_ & 0xfffc; d_ = d_ - 0x10000 if d_ & 0x8000 else d_
                            if d_ is not None and ext_[1] <= a_ + d_ < gend_:
                                ext_ = (t, gend_)
                                break
            if ext_:
                # code only a data word reaches (a vtable slot pointing at an empty `blr` method, an entry thunk `b FUN_..`): a raw block no ledger
                # function owns; emitted into code.s as its own entry (see raw_entry_asm)
                register_raw(t, ext_)
                e = '_raw_entry_%x' % t
        return e
    s = m.sec_at(t)
    if s is not None:
        targets.add(t)
        return ld(t)
    for ss in nlist_by_addr.get(t, []):
        return ss['name']
    return None

for s in data_secs:
    if (s['flags'] & 0xff) in (1, 0xc):
        continue
    a = s['addr']
    end = a + s['size']
    while a + 4 <= end:
        r = reloc_at.get(a)
        v = struct.unpack('>I', m.read(a, 4))[0]
        if r is not None and r['length'] == 2:
            if r['ext']:
                sn = m.syms[r['symnum']]['name']
                # a prebound image (glprog, libGL) stores the symbol's RESOLVED address in the word, not an addend: `sym + v` put
                # `compileNode + 0x97bbe7f0` into TIntermBinary's vtable (issue #72). The addend is v minus the symbol's own address when the image
                # defines it, and 0 for an import whose prebound address lies in another image.
                # only a PREBOUND image (MH_PREBOUND) stores resolved addresses; elsewhere the word IS the addend (GLDriver's typeinfo pointers:
                # __si_class_type_info's vtable + 8)
                sd = m.syms[r['symnum']]
                own = sd['value'] if (sd['type'] & 0x0e) == 0x0e else None
                if not (m.flags & 0x10):
                    add = v
                elif own is not None and v:
                    add = (v - own) & 0xffffffff
                    add = add - (1 << 32) if add & 0x80000000 else add
                elif v and m.sec_at(v) is None:
                    add = 0; prebound_import_words.append(a)
                else:
                    add = v
                if add != v:
                    ext_addend_fixed.append(a)
                word_expr[a] = '%s%+d' % (sn, add) if add else sn
            else:
                e = classify_target(v)
                if e:
                    word_expr[a] = e
                else:
                    unresolved_ptr_words.append((a, v))   # a relocated word would stay the stock address: it must not pass silently
        elif r is None and s['seg'] == '__TEXT' and a in gd and gd[a]['target'] is not None and gd[a]['dtype'] == 'pointer' and gd[a]['len'] == 4 and gd[a]['target'] == v:
            # read-only text cannot carry relocations, but the image is prebound: Ghidra's pointer type at the word is the only record that it is an address
            e = classify_target(v)
            if e:
                word_expr[a] = e
                ghidra_ptr_words.append(a)
        a += 4

# symbol-pointer slots (nl/la): name -> asm expression of the slot's value
slot_expr = {}
for s in sym_ptr_secs:
    for k in range(s['size'] // 4):
        a = s['addr'] + k * 4
        nm = indirect_name(s, k)
        v = struct.unpack('>I', m.read(a, 4))[0]
        if nm is not None:
            slot_expr[a] = nm
        else:
            e = classify_target(v) if v else None
            slot_expr[a] = e if e else '0x%x' % v

# ---------------------------------------------------------------------------------------------- names per address
names_at = collections.defaultdict(list)
for nm, a in needed.items():
    if a is not None:
        names_at[a].append(nm)
for a, ss in nlist_by_addr.items():
    sec = m.sec_at(a)
    if sec is not None and not mo.is_code(sec) and sec not in sym_ptr_secs:
        for s in ss:
            if s['name'] not in names_at[a] and s['name'] not in TOOLCHAIN_DATA:
                names_at[a].append(s['name'])
for a, g in gd.items():
    if g['name'] != '-' and not re.match(r'^(DAT|PTR|LAB|UNK|s|u|FLOAT|DOUBLE|switchdataD)_', g['name']):
        sec = m.sec_at(a)
        if sec is not None and not mo.is_code(sec) and sec not in sym_ptr_secs and g['name'] in needed and g['name'] not in names_at[a]:
            names_at[a].append(g['name'])

for v_, b_ in zf_lits:
    # no other zerofill object may start between the base and the literal, or the offset would reach into a separately placed object
    assert not any(b_ < a_ <= v_ for a_ in names_at if names_at[a_] and a_ != b_), 'zerofill literal 0x%x crosses an object boundary above 0x%x' % (v_, b_)

# ---------------------------------------------------------------------------------------------- data.s
S = []
S.append('# data.s - generated by Tools/userspace/link_corpus.py from %s' % os.path.basename(stock))
defined = set()
emitted_reloc = set(); reloc_lost_all = []
def emit_label(a):
    for nm in names_at.get(a, []):
        if nm in defined or nm in TOOLCHAIN_DATA:
            continue
        defined.add(nm)
        S.append('.globl %s' % nm)
        S.append('%s:' % nm)
    if a in targets and ld(a) not in defined:   # a `target` row naming the object a `data` row already labelled (r35) must not label it twice
        defined.add(ld(a))
        S.append('%s:' % ld(a))

label_positions = sorted(set(a2 for a2 in names_at if names_at[a2]) | set(targets))
skip_words = set()
for a, ss in nlist_by_addr.items():
    if any(s['name'] in TOOLCHAIN_DATA for s in ss):
        skip_words.add(a)
for a, g in gd.items():
    if g['name'] in TOOLCHAIN_DATA:
        skip_words.add(a)
zerofill_grown = []   # (address, name, Ghidra length, emitted size) of zerofill objects larger than their Ghidra type
def first_name_of(a_):
    return (names_at.get(a_) or [ld(a_)])[0]
for s in data_secs:
    ty = s['flags'] & 0xff
    a, end = s['addr'], s['addr'] + s['size']
    if ty == 1 or ty == 0xc:     # zerofill: one .zerofill per named object (a label at an address inside a .zerofill area cannot be expressed)
        objs = sorted({a2 for a2 in names_at if a > 0 and a <= a2 < end and names_at[a2]} | {a2 for a2 in targets if a <= a2 < end})
        if not objs:
            continue
        for k, a2 in enumerate(objs):
            nxt = objs[k + 1] if k + 1 < len(objs) else end
            g = gd.get(a2)
            # the whole gap to the next label: zerofill objects are emitted one by one (the stock layout is not kept), so bytes an object's Ghidra type
            # does not cover would be lost - an array typed by its first element (glprog GetSymbolTable()::SymbolTables, 3 pointers typed as one
            # undefined4) got 4 bytes and its other entries overlapped the next object. Padding at worst.
            size = nxt - a2
            if g and g['len'] and g['len'] < size:
                zerofill_grown.append((a2, first_name_of(a2), g['len'], size))
            names = [n for n in names_at.get(a2, []) if n not in defined and n not in TOOLCHAIN_DATA]
            first = names[0] if names else ld(a2)
            for n in names:
                defined.add(n)
                S.append('.globl %s' % n)
            if a2 in targets and not names:
                S.append('.globl %s' % ld(a2))
            # Alignment 0 for every object but the first: each object's size is the whole gap to the next label, so objects laid out in address order without padding keep the
            # stock's exact offsets - and with them the stock's alignment, from the section's start. Aligning a later object (7981-byte DAT_001f65e7, 8-aligned) moved it one
            # byte away from DAT_001f65e4..e6, which the pixel-conversion code (FUN_0001c380) indexes as ONE buffer (`DAT_001f65e4[i]`, `DAT_001f65e5[i]`, `&DAT_001f65e7 + i*4`).
            S.append('.zerofill %s,%s,%s,%d,%d' % (s['seg'], s['name'], first, size, min(4, (a2 & -a2).bit_length() - 1) if k == 0 and a2 == a else 0))   # the first object: the stock address's own alignment (up to 16), the rest follow it at the stock offsets
            for n in names[1:]:
                S.append('.set %s, %s' % (n, first))
            if a2 in targets and names:
                S.append('.set %s, %s' % (ld(a2), first))
        continue
    DIRECTIVE = {('__TEXT', '__cstring'): '.cstring', ('__TEXT', '__literal4'): '.literal4', ('__TEXT', '__literal8'): '.literal8', ('__TEXT', '__const'): '.const',
                 ('__DATA', '__const'): '.const_data', ('__DATA', '__data'): '.data'}
    if ty == 2 or ty == 3 or ty == 4 or ty == 0xe:
        S.append({2: '.cstring', 3: '.literal4', 4: '.literal8', 0xe: '.literal16'}[ty])
    elif s['seg'] == '__TEXT' and s['name'] in ('__const', '__const_coal') and any(a <= w_ < end for w_ in word_expr):
        # dyld 10.4 cannot apply relocations (least of all against external symbols) inside __TEXT: a table of pointers moves to the writable __DATA,__const
        S.append('.const_data')
    elif ty == 0xb and s['name'] in ('__const_coal', '__datacoal_nt'):
        # weak/coalesced data of the stock: one plain section here (a coalesced section needs a symbol at every atom start)
        S.append('.const_data' if s['name'] == '__const_coal' else '.data')
    elif (s['seg'], s['name']) in DIRECTIVE:
        S.append(DIRECTIVE[(s['seg'], s['name'])])
    else:
        S.append('.section %s,%s' % (s['seg'], s['name']) + (',coalesced' if ty == 0xb else ''))
    S.append('.align %d' % s['align'])
    if ty == 2:      # cstring: emit byte runs split at labels
        cur = a
        raw = m.read(a, s['size'])
        while cur < end:
            nxt = cur
            while nxt < end and raw[nxt - a] != 0:
                nxt += 1
            labs = [x for x in range(cur, nxt + 1) if x in targets or names_at.get(x)]
            if labs:
                esc = lambda bs: ''.join(chr(c) if 32 <= c < 127 and c not in (34, 92) else '\\%03o' % c for c in bs)
                pos = cur
                for x in labs + [nxt + 1]:
                    if x > pos:
                        seg_end = min(x, nxt)
                        if seg_end > pos:
                            S.append('.ascii "%s"' % esc(raw[pos - a:seg_end - a]))
                        pos = seg_end
                    if x <= nxt:
                        emit_label(x)
                S.append('.byte 0')
            cur = nxt + 1
        continue
    cur = a
    import bisect
    while cur < end:
        if cur in skip_words:
            cur += 4
            continue
        emit_label(cur)
        i_ = bisect.bisect_right(label_positions, cur)
        nextlab = label_positions[i_] if i_ < len(label_positions) else end
        nextlab = min(nextlab, end)
        if cur in word_expr and cur + 4 <= end:
            S.append('.long %s' % word_expr[cur])
            emitted_reloc.add(cur)
            cur += 4
        elif cur + 4 <= nextlab and cur + 4 <= end and not any((cur + k_) in word_expr for k_ in (1, 2, 3)):
            # (a raw word must not run over the first byte of a relocated word that starts 1-3 bytes further on: a label at an odd address inside the data - e.g. libGLProgrammability's
            # `tokensTableLastEntryPlus1` loop limit, one byte into the last record - used to shift the chunking by one, and the pointer after it stayed the stock's absolute address: Godot
            # crashed in HashString reading 0x97c23e08, which only the side-by-side tests, with the stock image mapped at that address, could survive)
            S.append('.long 0x%08x' % struct.unpack('>I', m.read(cur, 4))[0])
            cur += 4
        else:
            S.append('.byte 0x%02x' % m.read(cur, 1)[0])
            cur += 1
    # every relocated word inside this section must have been emitted as one (a relocation lost = a raw absolute address of the stock image in the rebuilt one)
    _lost_reloc = sorted(w_ for w_ in word_expr if a <= w_ < end and w_ + 4 <= end and w_ not in emitted_reloc and w_ not in skip_words)
    if _lost_reloc:
        reloc_lost_all.extend(_lost_reloc)

if reloc_lost_all:
    sys.exit('link_corpus: %d relocated data words were not emitted as relocations (stale absolute addresses of the stock image would remain), first: %s' % (len(reloc_lost_all), ', '.join('0x%x' % w_ for w_ in reloc_lost_all[:8])))
# symbol-pointer slots the corpus refers to: ordinary initialised words
S.append('.data')
S.append('.align 2')
for a in sorted(slot_expr):
    for nm in names_at.get(a, []):
        if nm in defined:
            continue
        defined.add(nm)
        S.append('.globl %s' % nm)
        S.append('%s:' % nm)
        S.append('.long %s' % slot_expr[a])
# PIC anchors: Ghidra folds `pic_base + offset` (the compiler's `L_object - L_pic` split into addis/addi) into an address that is no object of the image (`&DAT_001b81b8`),
# and the code then reads the real object at a displacement from it (`*(anchor - 0x56f8)`, `anchor + 4 * opcode`). The anchor is the real object's label plus the same
# constant, so it moves with the object in the rebuilt image: `.set NAME, LD_<base> + (anchor - base)`.
for nm_, sp_ in sorted(cfg.get('data_anchors', {}).items()):
    # the config names the anchor by its Ghidra label; a `data` row may have renamed it (the code then refers to the new name): define whichever name the corpus uses
    nm_ = next((k_ for k_, v_ in sorted(DATA_ROOT.items()) if v_ == nm_ and k_ in needed), nm_)
    base_ = int(sp_['base'], 16)
    anchor_ = addr_of_name(nm_)
    delta_ = anchor_ - base_
    S.append('.globl %s' % nm_)
    S.append('.set %s, %s%s' % (nm_, ld(base_), ('%+d' % delta_) if delta_ else ''))
    defined.add(nm_)
open(os.path.join(out, 'data.s'), 'w').write('\n'.join(S) + '\n')

# ---------------------------------------------------------------------------------------------- symbol map
with open(os.path.join(out, 'symbol_map.tsv'), 'w') as w:
    w.write('name\taddress\tsection\tghidra_type\tlen\tc_declaration\tvalue\tdefined_in\n')
    for nm in sorted(needed, key=lambda n: (needed[n] or 0, n)):
        a = needed[nm]
        sec = m.sec_at(a) if a is not None else None
        g = gd.get(a) if a is not None else None
        val = ''
        if a is not None:
            if a in slot_expr:
                val = 'pointer -> %s' % slot_expr[a]
            elif a in word_expr:
                val = 'pointer -> %s' % word_expr[a]
            elif sec is not None and sec['size'] and (sec['flags'] & 0xff) not in (1, 0xc):
                val = '0x%08x' % struct.unpack('>I', m.read(a, 4))[0]
        decl = [l for l in new_decls if re.search(r'\b%s\b' % re.escape(nm), l) and l.startswith('extern')]
        w.write('%s\t0x%x\t%s\t%s\t%s\t%s\t%s\t%s\n' % (nm, a or 0, ('%s,%s' % (sec['seg'], sec['name'])) if sec else '?', g['dtype'] if g else '-', g['len'] if g else '-', decl[0] if decl else '', val, 'data.s' if nm in defined else 'NOT DEFINED'))
undefined = [nm for nm in needed if nm not in defined and nm not in fn_by_addr.values() and nm not in TOOLCHAIN_DATA and nm not in clipped_entries and nm not in cfg.get('data_label_overrides', {}) and not (needed[nm] is not None and in_code(needed[nm]) and ('#define %s ' % nm) in ''.join(code_alias))]
with open(os.path.join(out, 'unresolved_data.txt'), 'w') as w:
    for nm in undefined:
        w.write('%s\t%s\n' % (nm, hex(needed[nm]) if needed[nm] is not None else '?'))

# ---------------------------------------------------------------------------------------------- parts
dropped = []
patched, unpatched = [], []
hdr = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')
atomics_total = [0]
bufs_total = [0]
patches_applied = []
stale_lits = []; dead_arg_lits = []
di3_total = [0]
cmp_total = [0]
dbl_total = [0]
floatlit_total = [0]
blocks_total = [0]
concat_inreg_total = [0]
pair_total = [0]
mirrored_total = [0]
unrenamed_total = [0]
ptr_blocks_total = [0]
placed_clipped = []
unresolved_calls = []
bind_info = cfg.get('bind_calls')
ledger_by_addr = {a: n for a, s, n, p in ledger}
fn_addr_by_name = {n: a for a, n in ledger_by_addr.items()}
short_to_c, siblings, callees = {}, {}, {}
if bind_info:
    orig = {}
    for l in open(os.path.expandvars(bind_info['orig_index'])):
        f = l.rstrip('\n').split('\t')
        if len(f) >= 3:
            orig[int(f[0], 16)] = f[2]
    def short_of(n):
        n = re.sub(r'\([^()]*\)', '', n)
        ps = scope_split(n)
        s_ = ps[-1] if ps else n
        return re.sub(r'<.*', '', s_) if not s_.startswith('operator') else s_
    for a_, n_ in ledger_by_addr.items():
        if a_ in orig:
            short_to_c.setdefault(short_of(orig[a_]), []).append(n_)
            ps_ = scope_split(re.sub(r'\([^()]*\)(?=::)', '', orig[a_]))
            for k_ in range(1, len(ps_)):           # `_Rep::_M_grab`, `string::string` ... the corpus drops leading scopes of some C++ names
                short_to_c.setdefault(csan('::'.join(ps_[k_:])), []).append(n_)
    groups = collections.defaultdict(list)
    for a_, n_ in sorted(ledger_by_addr.items()):
        groups[re.sub(r'_[0-9a-f]{8}$', '', n_)].append(n_)
    for base, ns in groups.items():
        if len(ns) > 1:
            for n_ in ns:
                siblings[n_] = ns
            siblings[base] = ns
    sym_addr_ = {s_['name']: a_ for a_, ss_ in nlist_by_addr.items() for s_ in ss_}
    callees = rewrites.parse_callees(os.path.expandvars(bind_info['stock_dis']), [(a, s, n) for a, s, n, p in ledger], sym_addr_)
gl_protos = None
if cfg.get('gl_headers'):
    import fix_gl_stubs
    gl_protos = fix_gl_stubs.parse_prototypes(cfg['gl_headers'])
dropped_addr = {n_: a_ for a_, s_, n_, p_ in ledger if toolchain_fn(n_, a_) or toolchain_fn(fn_label.get(n_, ''))}
_part_files = [('', f) for f in sorted(os.listdir(corpus)) if re.match(r'part_\d+\.c$', f)]
for d_ in EXTRA_DIRS:
    _part_files += [(d_, f) for f in sorted(os.listdir(os.path.join(corpus, d_))) if re.match(r'part_\d+\.c$', f)]
for pdir_, f in _part_files:
    text = open(os.path.join(corpus, pdir_, f)).read().split('\n')
    outname = f if not pdir_ else 'x_%s_%s' % (pdir_, f)
    chunks, cur = [], []
    for ln in text:
        if hdr.match(ln) and cur:
            chunks.append(cur)
            cur = []
        cur.append(ln)
    chunks.append(cur)
    o = []
    uses_gl = False
    uses_link = False
    for ch in chunks:
        mm = hdr.match(ch[0])
        if mm and (toolchain_fn(mm.group(1), int(mm.group(2), 16)) or toolchain_fn(fn_label.get(mm.group(1), ''))):
            dropped.append(mm.group(1))
            continue
        if mm:
            txt = '\n'.join(ch)
            txt, _fwd, _nun = unrename_locals(txt, mm.group(1))
            unrenamed_total[0] += _nun
            for vn_, vt_ in void_valued.items():
                if vn_ in txt:
                    txt = txt.replace('((void (*)())%s)' % vn_, '((%s (*)())%s)' % (vt_, vn_))
                    txt = re.sub(r'(?m)^void(\s+)%s\b' % re.escape(vn_), r'%s\1%s' % (vt_, vn_), txt)
            txt, natom = rewrites.rewrite_atomics(txt)
            atomics_total[0] += natom
            if re.search(r'\b(vectorPermute|vectorConditionalSelect|dataCacheBlockClearToZero|dataCacheBlockAllocate)\(', txt):
                uses_link = True
            txt, nfa = rewrites.rewrite_float_args(txt, float_protos_)
            if nfa:
                uses_link = True
                floatargs_total[0] += nfa
            if os.environ.get('FLOAT_LITERALS', '1') != '0':
                txt, nfl_ = rewrites.rewrite_float_literals(txt)
                floatlit_total[0] += nfl_
            txt, ndbl = rewrites.rewrite_double_bits(txt)
            dbl_total[0] += ndbl
            if ndbl:
                uses_link = True
            for pt_ in cfg.get('text_patches', []):
                if pt_['func'] == mm.group(1) and pt_['old'] in txt:
                    txt = txt.replace(pt_['old'], pt_['new'])
                    patches_applied.append(pt_['func'])
            txt, ndi = rewrites.rewrite_di3_calls(txt)
            di3_total[0] += ndi
            txt, ncmp = rewrites.rewrite_narrow_compares(txt)
            cmp_total[0] += ncmp
            txt, npair = rewrites.rewrite_pair_results(txt, ret64_names)
            pair_total[0] += npair
            if npair:
                uses_link = True
            for _lv, _lt, _rp in anchor_edits.get(mm.group(1), []):
                # the edit was found on the corpus text (real names); txt is at its Ghidra names here (unrename_locals), so look for the variable under both
                _lg = LOCAL_RENAMES.get(mm.group(1), {}).get(_lv, _lv)
                for _lvn in dict.fromkeys((_lg, _lv)):
                    txt = re.sub(r'(?m)^(\s*)%s = %s;' % (re.escape(_lvn), re.escape(_lt)), lambda x_, _lvn=_lvn: '%s%s = %s;' % (x_.group(1), _lvn, _rp), txt)
            for _lv, _lt, _rp in pic_base_edits.get(mm.group(1), []):
                _lg = LOCAL_RENAMES.get(mm.group(1), {}).get(_lv, _lv)
                for _lvn in dict.fromkeys((_lg, _lv)):
                    txt = re.sub(r'(?<![\w.])%s = %s(?=\s*[;,)])' % (re.escape(_lvn), re.escape(_lt)), lambda x_, _lvn=_lvn: '%s = %s' % (_lvn, _rp), txt)
            if cfg.get('mirror_frames') and mm.group(1) not in cfg.get('mirror_skip', []):
                txt, nmir = rewrites.mirror_frame(txt, cfg.get('mirror_stackaddr', True))
                mirrored_total[0] += nmir
            txt, nbuf = rewrites.fix_byte_buffers(txt)
            bufs_total[0] += nbuf
            txt, nblk = rewrites.fix_struct_blocks(txt)
            blocks_total[0] += nblk
            txt, npblk = rewrites.fix_pointer_records(txt)
            blocks_total[0] += npblk
            ptr_blocks_total[0] += npblk
            if natom:
                uses_link = True
            for cn_, ca_ in dropped_addr.items():
                if cn_ in txt and cn_ not in cfg.get('label_overrides', {}):
                    # a toolchain function that is not linked in can only be a number here (a field offset that equals its address): non-call uses become literals
                    txt = re.sub(r'(?<![\w])%s\b(?!\s*\()' % re.escape(cn_), '0x%x' % ca_, txt)
            for cn_ in cfg.get('const_function_names', []):
                if cn_ in fn_addr_by_name:
                    # a register offset / constant that equals a function's address: Ghidra printed the function name (value use only, not a call)
                    txt = re.sub(r'(?<![\w])%s\b(?!\s*\()' % re.escape(cn_), '0x%x' % fn_addr_by_name[cn_], txt)
            for bn_ in byte_arith_sized:
                txt = re.sub(r'&\s*%s\b(?=\s*[+-]\s)' % re.escape(bn_), '((unsigned char *)&%s)' % bn_, txt)
            txt = fix_string_arith(txt)
            # `CONCAT22(in_register_00000010, param_2)`: Ghidra typed a parameter as a halfword and shows the rest of its register as an uninitialised
            # `in_register_...`; the register as a whole IS the parameter the C already receives (TemporaryAllocator::getTemporary(ushort) indexed a
            # table with garbage in the upper half)
            txt, _nci = re.subn(r'CONCAT\d\d\(in_register_[0-9a-f]+,\s*(\w+)\)', r'(\1)', txt)
            concat_inreg_total[0] += _nci
            if lit_syms:
                txt = re.sub(r'\b0x([0-9a-f]{8})([0-9a-f]{8})\b', _split64, txt)
                txt = re.sub(r'\b0x([0-9a-f]{8})\b', lambda x: ('((unsigned int)&%s + %d)' % lit_syms[int(x.group(1), 16)]) if int(x.group(1), 16) in lit_syms else x.group(0), txt)
                txt = re.sub(r'(?<![\w)\]])-0x([0-9a-f]{1,8})\b', lambda x: ('((int)&%s + %d)' % lit_syms[(1 << 32) - int(x.group(1), 16)]) if (1 << 32) - int(x.group(1), 16) in lit_syms else x.group(0), txt)
            # `((unsigned char *)0x000c6e40)` where 0xc6e40 is the entry of a function of the link (ghidra2c prints `&DAT_...` of a code address that way): its label
            # ...but NOT when it is then indexed (`((unsigned char *)0x00030c50)[param_3 + param_1]`): that is a struct-field OFFSET that coincides with a function's entry
            # (stock `addis r2,r2,3; lbz r0,0xc50(r2)` = param_1 + param_3 + 0x30c50), the same coincidence ghidra2c.fix_code_offsets handles for `+` / `-`. The label's
            # address is the REBUILT function's, so the access went through a wild pointer (GLDriver FUN_00079b00, FUN_0001ecd0, FUN_00024970; found by fnfuzz, #44)
            txt = re.sub(r'\(\(unsigned char \*\)0x([0-9a-f]{8})\)(?!\s*\[)', lambda x: ('((unsigned char *)%s)' % fn_by_addr[int(x.group(1), 16)]) if int(x.group(1), 16) in fn_by_addr and '+' not in fn_by_addr[int(x.group(1), 16)] else x.group(0), txt)
            if sized_index_tables:
                txt = re.sub(r'\((%s)\)\[' % '|'.join(re.escape(n_) for n_ in sized_index_tables), lambda x: '((%s *)%s)[' % (sized_index_tables[x.group(1)], x.group(1)), txt)
                txt = re.sub(r'(?<![\w)>.&])(%s)\[' % '|'.join(re.escape(n_) for n_ in sized_index_tables), lambda x: '((%s *)%s)[' % (sized_index_tables[x.group(1)], x.group(1)), txt)
            if ctx_lit_syms:
                txt = _CTX_LIT.sub(lambda x: ('((unsigned int)&%s + %d)' % ctx_lit_syms[int(x.group(1), 16)]) if int(x.group(1), 16) in ctx_lit_syms and _ctx_lit_ok(txt, x) else x.group(0), txt)
            if bind_info:
                txt = rewrites.bind_calls(txt, int(mm.group(2), 16), ledger_by_addr, short_to_c, siblings, callees, unresolved_calls)
            # last: the other rewrites match plain `x = call(...)` statements (rewrite_pair_results, bind_calls); GH_STF hides that shape
            txt, _nus = rewrites.fix_unsigned_small_compare(txt)
            txt, _nhs = rewrites.fix_home_subword_store(txt)
            txt, nlow = rewrites._magic_low_words(txt)      # again: after mirror_frame the operands carry their types (`*(float *)(frame + N)`)
            txt, nfst = rewrites.rewrite_float_stores(txt)
            nfst += nlow
            if nfst:
                uses_link = True
                fstores_total[0] += nfst
            txt = rename_back(txt, _fwd, mm.group(1))
            if img_lo >= 0x10000000:
                # stale-literal gate (issue #227): a number inside / right next to one of the STOCK image's segments that survived every pass above is an absolute address of the
                # stock layout. As a bare call argument (`f(a, b, 0xa7b7faf0)`: the PIC temporary the stock left in a register, which the callee does not take) it is a dead
                # leftover and becomes 0; anywhere else it stops the link - the rebuilt image would read/store the stock layout's address.
                _nc = re.sub(r'/\*.*?\*/', lambda x_: ' ' * len(x_.group(0)), txt, flags=re.S)
                _out = []; _last = 0
                for _lm in re.finditer(r'(?<![\w.])(?:(?<![\w)\]])(-)|)0x([0-9a-f]{8})\b', _nc):
                    _lvv = int(_lm.group(2), 16)
                    _lvv = (-_lvv) & 0xffffffff if _lm.group(1) else _lvv
                    if not near_image(_lvv) or _lvv in fn_by_addr: continue
                    _bef = _nc[max(0, _lm.start() - 3):_lm.start()]; _aft = _nc[_lm.end():_lm.end() + 3]
                    if re.search(r'[(,]\s*$', _bef) and re.match(r'\s*[,)]', _aft) and not re.search(r'\b(if|while|switch|return)\s*\(\s*$', _nc[max(0, _lm.start() - 12):_lm.start()]):
                        _out.append((_lm.start(), _lm.end())); dead_arg_lits.append((mm.group(1), _lm.group(0), hex(_lvv)))
                    else:
                        stale_lits.append((mm.group(1), _lm.group(0), _nc[max(0, _lm.start() - 50):_lm.end() + 20].replace('\n', ' ').strip()))
                for _a_, _b_ in reversed(_out):
                    txt = txt[:_a_] + '0' + txt[_b_:]
            ch = txt.split('\n')
        if mm and gl_protos is not None and mm.group(1).startswith('_gl') and not mm.group(1).startswith('_gll'):
            new_ch, status = fix_gl_stubs.patch_function('\n'.join(ch), mm.group(1), gl_protos)
            if status == 'ok':
                patched.append(mm.group(1))
                uses_gl = True
                o.append(new_ch)
                continue
            unpatched.append((mm.group(1), status))
        o.append('\n'.join(ch))
    if stale_lits:
        for _x in stale_lits: print('  stale literal: %s: %s [%s]' % _x)
        sys.exit('link_corpus: %d stale absolute address(es) of the STOCK image survive in the link C (the rebuilt image would read/store the stock layout; issue #227), first: %s' %
                 (len(stale_lits), '; '.join('%s: %s [%s]' % x_ for x_ in stale_lits[:6])))
    src = '\n'.join(o)
    # the corpus carries `asm(".globl FUN_x"); asm(".set FUN_x, _FUN_x")` / `_thunk_FUN_x` alias pairs for the raw-declaration builds; here every function already has its own
    # asm label (link_decls.h), so the aliases would reference the undefined `_FUN_x`
    src = re.sub(r'(?m)^asm\("\.(?:globl|set) [^"]*"\);\n', '', src)
    _defined_here = set()
    for ch_ in chunks:
        mm_ = hdr.match(ch_[0])
        if mm_:
            _defined_here.add(mm_.group(1))
    for names_, words_, target_, start_ in clipped_blocks:
        if target_ in _defined_here:
            # a few instructions that fall through into the next function (a clipped entry): emitted next to that function so the branch stays inside one object.
            # The words are the stock machine code, so a PC-relative branch among them is re-emitted against its target's symbol (copied verbatim it would jump
            # to wherever the same displacement lands in the rebuilt image: `_AddAtom` = `b _LookUpAddString` went into the middle of a float routine)
            src += '\n__asm__(".text\\n' + ''.join('.globl %s\\n%s:\\n' % (n_, n_) for n_ in names_) + ''.join(l_ + '\\n' for l_ in clipped_lines(start_, words_)) + 'b %s\\n' % fn_label.get(target_, target_) + clip_stub_asm() + '.text\\n");\n'
            placed_clipped.append(names_[0])
    if uses_link:
        src = src.replace('#include "decls.h"', '#include "decls.h"\n#include "ghidra_link.h"', 1)
    if uses_gl:
        src = src.replace('#include "decls.h"', '#define GL_GLEXT_PROTOTYPES 1\n#include <OpenGL/gl.h>\n#include <OpenGL/glext.h>\n#include "decls.h"', 1)
    open(os.path.join(out, outname), 'w').write(src)
_declared = set(re.findall(r'\b(FUN_[0-9a-f]+|thunk_FUN_[0-9a-f]+)\b', open(os.path.join(out, 'decls.h')).read())) | set(re.findall(r'\b(FUN_[0-9a-f]+|thunk_FUN_[0-9a-f]+)\b', open(os.path.join(out, 'extra_decls.h')).read() if os.path.exists(os.path.join(out, 'extra_decls.h')) else ''))
_used_fun = set()
for f_ in os.listdir(out):
    if re.match(r'(x_\w+_)?part_\d+\.c$', f_):
        _used_fun |= set(re.findall(r'\b(FUN_[0-9a-f]{6,8})\b', open(os.path.join(out, f_)).read()))
_undecl = sorted(n for n in _used_fun if n not in _declared and n not in {'FUN_' + ('%08x' % a) for a in ()})
if _undecl:
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for n in _undecl:
            f_.write('extern int %s() asm("%s");\n' % (n, n))
if cfg.get('extra_c'):      # C the image needs that no stock function provides (a faithful stand-in for dropped toolchain code)
    with open(os.path.join(out, 'x_extra_part_000.c'), 'w') as f_:
        f_.write('#include "decls.h"\n' + '\n'.join(cfg['extra_c']) + '\n')
for dn_ in cfg.get('dummy_functions', []):
    with open(os.path.join(out, 'x_dummy_part_000.c'), 'a') as f_:
        f_.write('/* %s: not reproduced (millicode entry Ghidra printed as a call, or a function whose decompile failed); returns 0 */\nunsigned long long %s_dummy() asm("%s");\nunsigned long long %s_dummy() { return 0; }\n' % (dn_, dn_, dn_, dn_))
# say why a mapped name has no definition in data.s
_out_ids = set()
for f_ in os.listdir(out):
    if re.match(r'(x_\w+_)?part_\d+\.c$', f_):
        _out_ids |= set(re.findall(r'[A-Za-z_][A-Za-z_0-9]*', open(os.path.join(out, f_)).read()))
_rows = [l.rstrip('\n').split('\t') for l in open(os.path.join(out, 'symbol_map.tsv'))]
with open(os.path.join(out, 'symbol_map.tsv'), 'w') as w_:
    w_.write('\t'.join(_rows[0]) + '\n')
    for r_ in _rows[1:]:
        if r_[7] == 'NOT DEFINED':
            if r_[0] in cfg.get('data_label_overrides', {}) or r_[0] in ('__mh_bundle_header', '__mh_dylib_header', '__mh_execute_header'):
                r_[7] = 'linker symbol %s' % cfg.get('data_label_overrides', {}).get(r_[0], r_[0])
            elif r_[0] in clipped_entries:
                r_[7] = 'code entry (asm next to its function)'
            elif r_[0] in TOOLCHAIN_DATA:
                r_[7] = 'toolchain (crt/dyld data)'
            elif r_[0] not in _out_ids:
                r_[7] = 'unused (referenced only by dropped toolchain code)'
        w_.write('\t'.join(r_) + '\n')
with open(os.path.join(out, 'rewrites.txt'), 'w') as w:
    w.write('atomic read-modify-write idioms rewritten as compare-and-swap loops: %d\n' % atomics_total[0])
    w.write('byte buffers Ghidra declared as scalars, turned into arrays: %d\n' % bufs_total[0])
    w.write('(double)CONCAT44 bit-pattern constructions: %d\n' % dbl_total[0])
    w.write('float literals suffixed f: %d\n' % floatlit_total[0])
    w.write('hand text patches applied (config text_patches): %s\n' % ', '.join(patches_applied))
    w.write('stale stock-address literals passed as dead call arguments (-> 0): %d; PIC-base assignments re-expressed: %d\n' % (len(dead_arg_lits), sum(len(v_) for v_ in pic_base_edits.values())))
    for _x in pic_base_log: w.write('  pic base: %s\n' % (_x,))
    for _x in dead_arg_lits: w.write('  dead arg: %s\n' % (_x,))
    w.write('64-bit shift helper calls fixed: %d\n' % di3_total[0])
    w.write('narrow-type subtract-and-compare idioms: %d\n' % cmp_total[0])
    w.write('float/double call arguments given their true type (integer bit patterns reinterpreted): %d\n' % floatargs_total[0])
    w.write('float / double values stored into integer-typed words, stored as bits (rewrites.rewrite_float_stores, GH_STF): %d\n' % fstores_total[0])
    w.write('stack records Ghidra declared as separate scalars, merged into one block: %d\n' % blocks_total[0])
    w.write('  of which records with pointer members (rewrites.fix_pointer_records): %d\n' % ptr_blocks_total[0])
    w.write('functions whose stack frame is mirrored at the stock offsets (rewrites.mirror_frame): %d\n' % mirrored_total[0])
    w.write('renamed variables taken back to their Ghidra names for the rewrite chain and renamed again afterwards (LOCAL_RENAMES): %d\n' % unrenamed_total[0])
    w.write('external-relocation data words whose stored (prebound) value was not an addend, corrected: %d (%d of them prebound imports)\n' % (len(ext_addend_fixed), len(prebound_import_words)))
    w.write('CONCATnn(in_register_x, param) replaced by the parameter: %d; biased table-base literals anchored to the next section: %d\n' % (concat_inreg_total[0], len(biased_bases)))
    w.write('string literals used with arithmetic, put back as the number / address they stand for: %d sites\n' % len(strlit_fixed))
    w.write('32-bit call results assigned to an r3:r4 pair variable, moved to its high word (rewrites.rewrite_pair_results): %d\n' % pair_total[0])
    w.write('short C++ call names left unresolved (%d):\n' % len(unresolved_calls))
    for f_, tok, n_ in unresolved_calls:
        w.write('  in %s: %s (%d candidates)\n' % (f_, tok, n_))
open(os.path.join(out, 'ghidra_link.h'), 'w').write('''/* ghidra_link.h - helpers the link-time rewrites (Tools/userspace/rewrites.py) call */
static inline double GH_BITS_D(unsigned int hi, unsigned int lo) {
    union { unsigned long long u; double d; } x;
    x.u = ((unsigned long long)hi << 32) | lo;
    return x.d;
}
static inline float GH_BITS_F(unsigned int u) { union { unsigned int u; float f; } x; x.u = u; return x.f; }
#define GH_PAIR_HI(hi, old) ((((unsigned long long)(unsigned int)(hi)) << 32) | (unsigned int)(old))   /* r3:r4 pair: a 32-bit result in r3 = the high word */
static inline double GH_BITS_DD(unsigned long long u) { union { unsigned long long u; double d; } x; x.u = u; return x.d; }
#define GH_IS_FP(x) (__builtin_types_compatible_p(__typeof__(x), float) || __builtin_types_compatible_p(__typeof__(x), double))
/* the branch __builtin_choose_expr does not take must still type-check: a pointer argument (a stack slot Ghidra typed `int *` holding float bits,
   GLDriver FUN_0010b118's third argument) cannot be cast to double, so the FP branch casts a value that is 0.0 unless x is floating */
#define GH_FPV(x) ((double)__builtin_choose_expr(GH_IS_FP(x), (x), 0.0))
#define GH_ISF(x) __builtin_types_compatible_p(__typeof__(x), float)
#define GH_ISD(x) __builtin_types_compatible_p(__typeof__(x), double)
static inline unsigned long long GH_D2ULL(double d) { union { double d; unsigned long long u; } x; x.d = d; return x.u; }
/* GH_STF(lv, rhs): `lv = rhs` where rhs is float / double typed and lv an integer word (Ghidra's typing of an stfs / stfd destination): the BITS are stored (rewrites.rewrite_float_stores).
   Every unchosen branch still type-checks, so the float / double operands go through choose_expr with a 0.0 fallback */
#define GH_STF(lv, rhs) ((lv) = __builtin_choose_expr(GH_IS_FP(lv), (rhs), \\
    __builtin_choose_expr(sizeof(lv) == 4 && GH_ISF(rhs), (__typeof__(lv))GH_F2U(__builtin_choose_expr(GH_ISF(rhs), (rhs), 0.0f)), \\
    __builtin_choose_expr(sizeof(lv) == 4 && GH_ISD(rhs), (__typeof__(lv))GH_F2U((float)__builtin_choose_expr(GH_ISD(rhs), (rhs), 0.0)), \\
    __builtin_choose_expr(sizeof(lv) == 8 && GH_ISD(rhs), (__typeof__(lv))GH_D2ULL(__builtin_choose_expr(GH_ISD(rhs), (rhs), 0.0)), (rhs))))))
/* the low word of the int -> double magic-number sequence (rewrites._magic_low_words): a float-typed operand is a WORD Ghidra typed float - its bits (`-x` on it is the sign-flip
   xoris that makes a signed word's magic-double form); an integer operand converts / negates as before */
#define GH_LOWW(x) __builtin_choose_expr(GH_ISF(x), GH_F2U(__builtin_choose_expr(GH_ISF(x), (x), 0.0f)), (unsigned int)(x))
#define GH_LOWNEG(x) __builtin_choose_expr(GH_ISF(x), GH_F2U(__builtin_choose_expr(GH_ISF(x), (x), 0.0f)) ^ 0x80000000u, (unsigned int)(-(long)(x)))
#define GH_ARGF(x) __builtin_choose_expr(GH_IS_FP(x), GH_FPV(x), (double)GH_BITS_F((unsigned int)(x)))
#define GH_ARGD(x) __builtin_choose_expr(GH_IS_FP(x), GH_FPV(x), __builtin_choose_expr(sizeof(x) == 8, GH_BITS_DD((unsigned long long)(x)), (double)(long)(x)))
static inline void GH_DCBZ(unsigned int p) { __asm__ __volatile__("dcbz 0,%0" : : "r"(p) : "memory"); }
/* v0-v2 are live only between the lvx and the stvx, but Darwin saves a thread's vector registers across a context switch only for the bits set in VRSAVE (SPR 256):
   without them an interrupt inside the window loses the operands (GLDriver FUN_0001eaf0: 1 in ~15 test runs returned a different checksum). Set v0-v2's bits around the asm, restore after */
#ifdef __VEC__   /* compiled with -maltivec (build.sh does that for the one file that uses vec16): real vector registers, the compiler handles VRSAVE */
static inline vec16 GH_VPERM(vec16 a, vec16 b, vec16 c) { return vec_perm(a, b, c); }
static inline vec16 GH_VSEL(vec16 a, vec16 b, vec16 c) { return vec_sel(a, b, c); }
#else
static inline vec16 GH_VPERM(vec16 a, vec16 b, vec16 c) {
    unsigned int vs0, vs1; vec16 ra __attribute__((aligned(16))) = a, rb __attribute__((aligned(16))) = b, rc __attribute__((aligned(16))) = c, r __attribute__((aligned(16)));
    __asm__ __volatile__("mfspr %0,256\\n\\toris %1,%0,0xe000\\n\\tmtspr 256,%1\\n\\tlvx v0,0,%3\\n\\tlvx v1,0,%4\\n\\tlvx v2,0,%5\\n\\tvperm v0,v0,v1,v2\\n\\tstvx v0,0,%2\\n\\tmtspr 256,%0" : "=&r"(vs0), "=&r"(vs1) : "r"(&r), "r"(&ra), "r"(&rb), "r"(&rc) : "memory");
    return r;
}
static inline vec16 GH_VSEL(vec16 a, vec16 b, vec16 c) {
    unsigned int vs0, vs1; vec16 ra __attribute__((aligned(16))) = a, rb __attribute__((aligned(16))) = b, rc __attribute__((aligned(16))) = c, r __attribute__((aligned(16)));
    __asm__ __volatile__("mfspr %0,256\\n\\toris %1,%0,0xe000\\n\\tmtspr 256,%1\\n\\tlvx v0,0,%3\\n\\tlvx v1,0,%4\\n\\tlvx v2,0,%5\\n\\tvsel v0,v0,v1,v2\\n\\tstvx v0,0,%2\\n\\tmtspr 256,%0" : "=&r"(vs0), "=&r"(vs1) : "r"(&r), "r"(&ra), "r"(&rb), "r"(&rc) : "memory");
    return r;
}
#endif
#define vectorPermute GH_VPERM
#define vectorConditionalSelect GH_VSEL
#define dataCacheBlockClearToZero(p) GH_DCBZ((unsigned int)(p))
#define dataCacheBlockClearToZeroLine(p) __asm__ __volatile__("dcbzl 0,%0" : : "r"((unsigned int)(p)) : "memory")
#define dataCacheBlockAllocate(p) ((void)0)
static inline int ghidra_cas32(void *p, int oldv, int newv) {
    int cur;
    __asm__ __volatile__("1: lwarx %0,0,%2\\n\\tcmpw %0,%3\\n\\tbne- 2f\\n\\tstwcx. %4,0,%2\\n\\tbne- 1b\\n2:"
                         : "=&r"(cur), "+m"(*(int *)p) : "r"(p), "r"(oldv), "r"(newv) : "cr0", "memory");
    return cur == oldv;
}
''')
print('rewrites: %d atomic idioms, %d unresolved short call names' % (atomics_total[0], len(unresolved_calls)))
if gl_protos is not None:
    with open(os.path.join(out, 'gl_stub_patch.txt'), 'w') as w:
        w.write('patched %d stubs with their gl.h/glext.h prototypes\n' % len(patched))
        for n, s in unpatched:
            w.write('NOT PATCHED %s: %s\n' % (n, s))
    print('gl stubs: %d patched, %d not patched (gl_stub_patch.txt)' % (len(patched), len(unpatched)))
    # a stub whose dispatch call the patcher cannot find keeps the decompile's argument order and forwards float arguments as doubles (rebuilt libGL crashed in glClearColor when the
    # real-name rewrite made the matcher miss all 888): that must never be silent
    _lost = [n for n, st in unpatched if st in ('no dispatch call', 'unrecognised layout')]
    if _lost:
        sys.exit('link_corpus: %d GL dispatch stubs could not be patched (%s ...): see gl_stub_patch.txt' % (len(_lost), ', '.join(_lost[:5])))

# a data name only the dropped (toolchain) functions used is not needed
_out_ids = set()
for f_ in os.listdir(out):
    if re.match(r'(x_\w+_)?part_\d+\.c$', f_):
        _out_ids |= set(re.findall(r'[A-Za-z_][A-Za-z_0-9]*', open(os.path.join(out, f_)).read()))
undefined = [n for n in undefined if n in _out_ids]
with open(os.path.join(out, 'unresolved_data.txt'), 'w') as w:
    for nm in undefined:
        w.write('%s\t%s\n' % (nm, hex(needed[nm]) if needed[nm] is not None else '?'))

# ---------------------------------------------------------------------------------------------- exports + build script
ex = sorted({n for n, a, s in mo.exports(m)} - set(TOOLCHAIN_FN))
open(os.path.join(out, 'exports.txt'), 'w').write('\n'.join(ex) + '\n')
idl = m.id_dylib
def ver(v):
    return '%d.%d.%d' % (v >> 16, (v >> 8) & 0xff, v & 0xff)
def lib_flag(path):
    mm = re.match(r'^/System/Library/Frameworks/([^/]+)\.framework/Versions/[^/]+/\1$', path)
    if mm:
        return '-framework %s' % mm.group(1)
    return path
auto_flags = []
for c_, nm_, cur_, comp_ in m.dylibs:
    f_ = lib_flag(nm_)
    if f_ not in auto_flags:
        auto_flags.append(f_)
if os.environ.get('COVERAGE'):      # function coverage of the rebuilt image (issue #65): every C function appends its image offset to $COV_FILE the first time a process enters it.
    # KNOWN ISSUE (2026-09-26): linking this hook object into glprog - even compiled plain, with every part_*.c's -finstrument-functions calls
    # left off, so nothing in the image ever calls it - makes 3 of 141 glsl_test shaders (e.g. v_ctor.vert) crash in TParseContext::executeInitializer
    # on a garbage pointer read off TParseContext's own stack frame, reached through generateBuiltInSymbolTable/initializeSymbolTable/ShInitialize.
    # Shrinking cov_seen to 16 bytes does not stop it; removing this file entirely does. So it is not this array's size, and (given the crash is
    # unchanged whether the calls fire or not) not the __cyg_profile_* calls clobbering a register either - something about the mere presence of an
    # extra linked object shifts a layout-sensitive address this function's stack computation depends on. Not root-caused; do not trust glprog's
    # function-coverage numbers for the functions on that path until it is.
    with open(os.path.join(out, 'x_cov_part_000.c'), 'w') as f_:
        f_.write(r'''#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
extern char cov_hdr asm("%s");
static unsigned char cov_seen[0x180000 / 8]; static int cov_fd; static char cov_opened;   /* zero-init only: an initialised static would land in __DATA,__data and shift the stock section layout that data.s reproduces */
void __cyg_profile_func_enter(void *fn, void *site) __attribute__((no_instrument_function));
void __cyg_profile_func_exit(void *fn, void *site) __attribute__((no_instrument_function));
void __cyg_profile_func_enter(void *fn, void *site) {
    unsigned off = (unsigned)fn - (unsigned)&cov_hdr, i = off >> 2;
    if (i >= 8u * sizeof cov_seen || (cov_seen[i >> 3] & (1 << (i & 7)))) return;
    cov_seen[i >> 3] |= 1 << (i & 7);
    if (!cov_opened) { const char *p = getenv("COV_FILE"); cov_opened = 1; cov_fd = open(p ? p : "/tmp/cov_default.bin", O_WRONLY | O_APPEND | O_CREAT, 0666); }
    if (cov_fd >= 0) write(cov_fd, &off, 4);
}
void __cyg_profile_func_exit(void *fn, void *site) {}
''' % HEADER_SYM)
# issue #229: the stock images were built by an optimising gcc that contracts a*b+c into one fused multiply-add; the -O0 rebuilt image does not, and rounds twice.
# cfg "fuse_madd": every part is compiled to assembly, Tools/userspace/fuse_madd.py fuses the mul+add/sub pairs, and that assembly is assembled (the -O0 code is otherwise unchanged).
if cfg.get('fuse_madd') and os.environ.get('LINK_OPT', cfg.get('link_opt', '-O0')).split()[0] == '-O0':   # the fuse pass is for the -O0 code; optimised code is already fused by gcc
    import shutil
    shutil.copy(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'fuse_madd.py'), os.path.join(out, 'fuse_madd.py'))
    COMPILE_CMD = ('{ gcc $CF $XF -S $f -o obj/${f%.c}.s && ${FUSE_PY:-/usr/local/bin/python3} fuse_madd.py obj/${f%.c}.s 2>>obj/fuse_madd.log && gcc $CF $XF -c obj/${f%.c}.s -o obj/${f%.c}.o; }')
else:
    COMPILE_CMD = 'gcc $CF $XF -c $f -o obj/${f%.c}.o'
kind = '-dynamiclib' if m.filetype == 6 else '-bundle'
ln = ['#!/bin/sh', '# build.sh - compile + link on the Tiger G5 (gcc 4.0.1). Usage: sh build.sh [OUT_NAME]',
      'set -e', 'cd "$(dirname "$0")"', 'OUT=${1:-linked.out}', 'CFLAGS="-arch ppc %s -w %s -fno-common -force_cpusubtype_ALL%s"' % (os.environ.get('LINK_OPT', cfg.get('link_opt', '-O0')), os.environ.get('LINK_PIC', '-fPIC'), ' -finstrument-functions' if os.environ.get('COVERAGE') else ''),
      'rm -rf obj; mkdir obj',
      # LINK_OPT_ALT_FILES (space-separated part basenames) are compiled with LINK_OPT_ALT instead of LINK_OPT (issue #212: the shader-compiler parts are faster at -Os, the draw/state parts at -O2)
      'ALTFILES=" %s "; CFLAGS_ALT="-arch ppc %s -w %s -fno-common -force_cpusubtype_ALL"' % (os.environ.get('LINK_OPT_ALT_FILES', ''), os.environ.get('LINK_OPT_ALT', '-Os -mtune=970'), os.environ.get('LINK_PIC', '-fPIC')),
      'for f in part_*.c x_*part_*.c; do [ -f $f ] || continue; XF=; grep -qw vec16 $f && XF=-maltivec; CF="$CFLAGS"; case "$ALTFILES" in *" ${f%.c} "*) CF="$CFLAGS_ALT";; esac; ' + COMPILE_CMD + ' || echo "COMPILE FAIL $f"; done',
      'as -arch ppc -o obj/data.o data.s',
      'as -arch ppc -o obj/code.o code.s',
      '# INSTALL overrides the install name (a dlopen() of a copy that keeps the stock name returns the already-loaded system image)',
      'gcc -arch ppc %s -o $OUT obj/*.o -exported_symbols_list exports.txt -read_only_relocs suppress %s %s' % (
          kind,
          ('-install_name "${INSTALL:-%s}" -compatibility_version %s -current_version %s' % (idl[1], ver(idl[3]), ver(idl[2]))) if idl and kind == '-dynamiclib' else '',
          ' '.join(cfg.get('link_flags', auto_flags) + cfg.get('extra_link_flags', [])))]
open(os.path.join(out, 'build.sh'), 'w').write('\n'.join(ln) + '\n')
print('%s: %d typed data decls, %d data labels emitted, %d unresolved data symbols, %d toolchain functions dropped, %d exports' % (os.path.basename(stock), typed, len(defined), len(undefined), len(dropped), len(ex)))
if undefined:
    print('UNRESOLVED:', ', '.join(undefined[:20]))
if raw_entries:
    with open(os.path.join(out, 'code.s'), 'a') as f:
        f.write('\n'.join(raw_entry_asm()) + '\n')
    print('%d raw code entries reached only from data emitted into code.s' % len(raw_entries))
with open(os.path.join(out, 'signed_kept.txt'), 'w') as f:
    f.write('\n'.join(signed_kept) + ('\n' if signed_kept else ''))
with open(os.path.join(out, 'zerofill_grown.txt'), 'w') as f:
    for a_, n_, gl_, sz_ in zerofill_grown:
        f.write('0x%x\t%s\tghidra %d\temitted %d\n' % (a_, n_, gl_, sz_))
with open(os.path.join(out, 'unresolved_pointer_words.txt'), 'w') as f:
    for a_, v_ in unresolved_ptr_words:
        f.write('0x%x\t0x%x\n' % (a_, v_))
if unresolved_ptr_words:
    print('WARNING: %d relocated data word(s) keep their stock value (no symbol for the target), see unresolved_pointer_words.txt' % len(unresolved_ptr_words))
