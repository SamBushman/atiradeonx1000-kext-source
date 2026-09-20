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
import sys, os, re, json, struct, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import machoutil as mo

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
EXTRA_DIRS = [d for d in cfg.get('extra_corpora', []) if os.path.isdir(os.path.join(corpus, d))]
for l in open(os.path.join(corpus, 'ledger.tsv')):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 4:
        ledger.append((int(f[0], 16), int(f[1]), f[2], f[3]))
for d_ in EXTRA_DIRS:      # companion corpora (unowned_code/: code only reached through data or exported entry points no analysis found)
    for l in open(os.path.join(corpus, d_, 'ledger.tsv')):
        f = l.rstrip('\n').split('\t')
        if len(f) >= 4:
            ledger.append((int(f[0], 16), int(f[1]), f[2], d_ + '/' + f[3]))
fn_by_addr = {a: n for a, s, n, p in ledger}
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
TOOLCHAIN_RE = re.compile(r'^(save|rest)(FP|GP|GPR|VR|F|G)\w*$|^(saveFP|restFP)$')
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
    decls += [l for l in read_decl_lines(os.path.join(corpus, d_, 'decls.h')) if l.startswith('extern') and l not in have_]
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

def addr_of_name(n):
    mm = re.search(r'_([0-9a-f]{8})$', n)
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
    if dt == 'pointer' and ln == 4:
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
label_of = {}        # C identifier -> assembler symbol
typed = 0
def transform(lines):
    global typed
    res = []
    for ln in lines:
        mm = re.match(r'^extern (const )?(.*?)\b([A-Za-z_][A-Za-z_0-9]*)\((.*)\);\s*$', ln)
        if mm and '(*' not in ln:
            nm = mm.group(3)
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
            orig_ptr = ('*' in mm.group(2)) or kind == 'array'   # the corpus uses it as a pointer / array: keep its form, just label it
            if t_ and 'MACH_HEADER' not in ln and 'Ghidra' not in ln and not orig_ptr:
                res.append('extern %s asm("%s");' % (t_ % nm, nm))
                typed += 1
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
DROP_DECLS = set(cfg.get('drop_decls', []))
decls = [l for l in decls if not any(re.search(r'\b%s\b' % re.escape(d), l) for d in DROP_DECLS)]
for nm_, a_ in nlist_alias.items():       # another name (in the symbol table) of a function that has a ledger entry under a different one
    ln_ = fn_by_addr.get(a_)
    if ln_ and nm_ not in fn_label and nm_ != ln_:
        fn_label[nm_] = fn_label.get(ln_, ln_)
new_decls = transform(decls)
if cfg.get('prelude'):
    new_decls = list(cfg['prelude']) + new_decls
if cfg.get('postlude'):
    new_decls = new_decls + list(cfg['postlude'])
open(os.path.join(out, 'decls.h'), 'w').write('\n'.join(new_decls) + '\n')
extra_lines = [l for l in extra_lines if not any(re.search(r'\b%s\b' % re.escape(d), l) for d in DROP_DECLS)]
open(os.path.join(out, 'extra_decls.h'), 'w').write('\n'.join(transform(extra_lines)) + '\n' if extra_lines else '')
if os.path.exists(os.path.join(corpus, 'ghidra_c.h')):
    open(os.path.join(out, 'ghidra_c.h'), 'w').write(open(os.path.join(corpus, 'ghidra_c.h')).read())

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
lit_syms = {}
img_lo = min(s['addr'] for s in m.secs if s['size'])
img_hi = max(s['addr'] + s['size'] for s in m.secs if s['size'])
if cfg.get('symbolize_literals') and img_lo >= 0x10000000:
    _lit = set(int(x, 16) for x in re.findall(r'\b0x([0-9a-f]{8})\b', body))
    for v in sorted(_lit):
        if img_lo <= v < img_hi and m.sec_at(v) is not None and not in_code(v) and (m.sec_at(v)['flags'] & 0xff) != 1:
            lit_syms[v] = 'SYM_%x' % v
            needed['SYM_%x' % v] = v
    with open(os.path.join(out, 'decls.h'), 'a') as f_:
        for v, nm in lit_syms.items():
            f_.write('extern unsigned char %s asm("%s");\n' % (nm, nm))

# names that are really numeric constants Ghidra labelled as data (`&DAT_00010001` = 0x10001, an address in no section of the image, or `UINT_00002ee0` in code)
const_names = []
for nm, a in sorted(needed.items()):
    if a is None:
        continue
    sec_ = m.sec_at(a)
    zf = any(s2['addr'] <= a < s2['addr'] + s2['size'] for s2 in m.secs if (s2['flags'] & 0xff) in (1, 0xc))
    if (sec_ is None and not zf and nm not in TOOLCHAIN_DATA and a not in nlist_by_addr) or (re.match(r'^(UINT|INT|SHORT|BYTE|LAB)_', nm) and in_code(a)):
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
clipped_blocks = []      # (entry names, machine words, ledger name of the function they fall into) - emitted into that function's translation unit
code_alias, code_s = ['#define %s (*(unsigned char *)0x%x)   /* a numeric constant, not an object */' % (nm, data_addr(nm) or 0) for nm in const_names], ['.text', '.align 2']
for nm, a in sorted(needed.items()):
    if a is not None and in_code(a) and nm not in fn_by_addr.values():
        e = fn_by_addr.get(a)
        ext = next(((lo, hi) for lo, hi in extents if lo == a), None)
        if e and '+' not in e:
            code_alias.append('#define %s %s' % (nm, e))
        elif ext and ext[1] in fn_by_addr:
            clipped_blocks.append(([nm], [struct.unpack('>I', m.read(w, 4))[0] for w in range(ext[0], ext[1], 4)], fn_by_addr[ext[1]]))
            clipped_entries.append(nm)
        else:
            code_alias.append('/* %s at 0x%x: no function starts there */' % (nm, a))
for a_, ss_ in sorted(nlist_by_addr.items()):
    if not in_code(a_) or a_ in fn_by_addr:
        continue
    ext_ = next(((lo, hi) for lo, hi in extents if lo == a_), None)
    if ext_ and ext_[1] in fn_by_addr:
        nms_ = [s_['name'] for s_ in ss_ if s_['name'] not in clipped_entries and s_['name'] not in TOOLCHAIN_FN]
        clipped_entries.extend(nms_)
        if nms_:
            clipped_blocks.append((nms_, [struct.unpack('>I', m.read(w, 4))[0] for w in range(ext_[0], ext_[1], 4)], fn_by_addr[ext_[1]]))
open(os.path.join(out, 'code.s'), 'w').write('\n'.join(code_s) + '\n')
if code_alias:
    with open(os.path.join(out, 'decls.h'), 'a') as f:
        f.write('\n'.join(code_alias) + '\n')

# ---------------------------------------------------------------------------------------------- pointer words
reloc_at = {r['addr']: r for r in m.relocs}
for lst in m.sec_relocs.values():
    for r in lst:
        reloc_at.setdefault(r['addr'], r)

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
                return '%s+%d' % (fn_label.get(n, n), addr - a)
    return None

targets = set()        # data addresses that need a label
ghidra_ptr_words = []
word_expr = {}         # addr -> asm expression for that word (pointer words), decided in pass 1
def classify_target(t):
    if in_code(t):
        e = fn_symbol_for(t)
        return e
    s = m.sec_at(t)
    if s is not None:
        targets.add(t)
        return 'LD_%x' % t
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
                word_expr[a] = '%s+%d' % (sn, v) if v else sn
            else:
                e = classify_target(v)
                if e:
                    word_expr[a] = e
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

# ---------------------------------------------------------------------------------------------- data.s
S = []
S.append('# data.s - generated by Tools/userspace/link_corpus.py from %s' % os.path.basename(stock))
defined = set()
def emit_label(a):
    for nm in names_at.get(a, []):
        if nm in defined or nm in TOOLCHAIN_DATA:
            continue
        defined.add(nm)
        S.append('.globl %s' % nm)
        S.append('%s:' % nm)
    if a in targets:
        S.append('LD_%x:' % a)

label_positions = sorted(set(a2 for a2 in names_at if names_at[a2]) | set(targets))
skip_words = set()
for a, ss in nlist_by_addr.items():
    if any(s['name'] in TOOLCHAIN_DATA for s in ss):
        skip_words.add(a)
for a, g in gd.items():
    if g['name'] in TOOLCHAIN_DATA:
        skip_words.add(a)
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
            size = min(nxt - a2, g['len']) if g and g['len'] and g['len'] <= nxt - a2 else nxt - a2
            names = [n for n in names_at.get(a2, []) if n not in defined and n not in TOOLCHAIN_DATA]
            first = names[0] if names else 'LD_%x' % a2
            for n in names:
                defined.add(n)
                S.append('.globl %s' % n)
            if a2 in targets and not names:
                S.append('.globl LD_%x' % a2)
            S.append('.zerofill %s,%s,%s,%d,%d' % (s['seg'], s['name'], first, size, min(s['align'], 4) if size >= (1 << min(s['align'], 4)) else 0))
            for n in names[1:]:
                S.append('.set %s, %s' % (n, first))
            if a2 in targets and names:
                S.append('.set LD_%x, %s' % (a2, first))
        continue
    DIRECTIVE = {('__TEXT', '__cstring'): '.cstring', ('__TEXT', '__literal4'): '.literal4', ('__TEXT', '__literal8'): '.literal8', ('__TEXT', '__const'): '.const',
                 ('__DATA', '__const'): '.const_data', ('__DATA', '__data'): '.data'}
    if ty == 2 or ty == 3 or ty == 4 or ty == 0xe:
        S.append({2: '.cstring', 3: '.literal4', 4: '.literal8', 0xe: '.literal16'}[ty])
    elif s['seg'] == '__TEXT' and s['name'] in ('__const', '__const_coal') and any(a <= w_ < end for w_ in word_expr):
        # dyld 10.4 cannot apply relocations (least of all against external symbols) inside __TEXT: a table of pointers moves to the writable __DATA,__const
        S.append('.const_data')
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
            cur += 4
        elif cur + 4 <= nextlab and cur + 4 <= end:
            S.append('.long 0x%08x' % struct.unpack('>I', m.read(cur, 4))[0])
            cur += 4
        else:
            S.append('.byte 0x%02x' % m.read(cur, 1)[0])
            cur += 1

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
undefined = [nm for nm in needed if nm not in defined and nm not in fn_by_addr.values() and nm not in TOOLCHAIN_DATA and nm not in clipped_entries and not (needed[nm] is not None and in_code(needed[nm]) and ('#define %s ' % nm) in ''.join(code_alias))]
with open(os.path.join(out, 'unresolved_data.txt'), 'w') as w:
    for nm in undefined:
        w.write('%s\t%s\n' % (nm, hex(needed[nm]) if needed[nm] is not None else '?'))

# ---------------------------------------------------------------------------------------------- parts
dropped = []
patched, unpatched = [], []
hdr = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')
import rewrites
atomics_total = [0]
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
            txt, natom = rewrites.rewrite_atomics(txt)
            atomics_total[0] += natom
            if natom:
                uses_link = True
            for cn_ in cfg.get('const_function_names', []):
                if cn_ in fn_addr_by_name:
                    # a register offset / constant that equals a function's address: Ghidra printed the function name (value use only, not a call)
                    txt = re.sub(r'(?<![\w])%s\b(?!\s*\()' % re.escape(cn_), '0x%x' % fn_addr_by_name[cn_], txt)
            if lit_syms:
                txt = re.sub(r'\b0x([0-9a-f]{8})\b', lambda x: '((unsigned int)&%s)' % lit_syms[int(x.group(1), 16)] if int(x.group(1), 16) in lit_syms else x.group(0), txt)
            if bind_info:
                txt = rewrites.bind_calls(txt, int(mm.group(2), 16), ledger_by_addr, short_to_c, siblings, callees, unresolved_calls)
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
    src = '\n'.join(o)
    _defined_here = set()
    for ch_ in chunks:
        mm_ = hdr.match(ch_[0])
        if mm_:
            _defined_here.add(mm_.group(1))
    for names_, words_, target_ in clipped_blocks:
        if target_ in _defined_here:
            # a few instructions that fall through into the next function (a clipped entry): emitted next to that function so the branch stays inside one object
            src += '\n__asm__(".text\\n' + ''.join('.globl %s\\n%s:\\n' % (n_, n_) for n_ in names_) + ''.join('.long 0x%08x\\n' % w_ for w_ in words_) + 'b %s\\n");\n' % fn_label.get(target_, target_)
            placed_clipped.append(names_[0])
    if uses_link:
        src = src.replace('#include "decls.h"', '#include "decls.h"\n#include "ghidra_link.h"', 1)
    if uses_gl:
        src = src.replace('#include "decls.h"', '#define GL_GLEXT_PROTOTYPES 1\n#include <OpenGL/gl.h>\n#include <OpenGL/glext.h>\n#include "decls.h"', 1)
    open(os.path.join(out, outname), 'w').write(src)
with open(os.path.join(out, 'rewrites.txt'), 'w') as w:
    w.write('atomic read-modify-write idioms rewritten as compare-and-swap loops: %d\n' % atomics_total[0])
    w.write('short C++ call names left unresolved (%d):\n' % len(unresolved_calls))
    for f_, tok, n_ in unresolved_calls:
        w.write('  in %s: %s (%d candidates)\n' % (f_, tok, n_))
open(os.path.join(out, 'ghidra_link.h'), 'w').write('''/* ghidra_link.h - helpers the link-time rewrites (Tools/userspace/rewrites.py) call */
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
    mm = re.match(r'^/System/Library/Frameworks/([^/]+)\.framework/', path)
    if mm:
        return '-framework %s' % mm.group(1)
    return path
auto_flags = []
for c_, nm_, cur_, comp_ in m.dylibs:
    f_ = lib_flag(nm_)
    if f_ not in auto_flags:
        auto_flags.append(f_)
kind = '-dynamiclib' if m.filetype == 6 else '-bundle'
ln = ['#!/bin/sh', '# build.sh - compile + link on the Tiger G5 (gcc 4.0.1). Usage: sh build.sh [OUT_NAME]',
      'set -e', 'cd "$(dirname "$0")"', 'OUT=${1:-linked.out}', 'CFLAGS="-arch ppc -O0 -w -fPIC -fno-common"',
      'rm -rf obj; mkdir obj',
      'for f in part_*.c x_*part_*.c; do [ -f $f ] || continue; gcc $CFLAGS -c $f -o obj/${f%.c}.o || echo "COMPILE FAIL $f"; done',
      'as -arch ppc -o obj/data.o data.s',
      'as -arch ppc -o obj/code.o code.s',
      '# INSTALL overrides the install name (a dlopen() of a copy that keeps the stock name returns the already-loaded system image)',
      'gcc -arch ppc %s -o $OUT obj/*.o -exported_symbols_list exports.txt -read_only_relocs suppress %s %s' % (
          kind,
          ('-install_name ${INSTALL:-%s} -compatibility_version %s -current_version %s' % (idl[1], ver(idl[3]), ver(idl[2]))) if idl and kind == '-dynamiclib' else '',
          ' '.join(cfg.get('link_flags', auto_flags) + cfg.get('extra_link_flags', [])))]
open(os.path.join(out, 'build.sh'), 'w').write('\n'.join(ln) + '\n')
print('%s: %d typed data decls, %d data labels emitted, %d unresolved data symbols, %d toolchain functions dropped, %d exports' % (os.path.basename(stock), typed, len(defined), len(undefined), len(dropped), len(ex)))
if undefined:
    print('UNRESOLVED:', ', '.join(undefined[:20]))
