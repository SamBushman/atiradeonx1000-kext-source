#!/usr/bin/env python3
"""ghidra2c.py DECOMP_DIR OUT_DIR [PART_SIZE] - turn a DecompAll.java dump (one .txt per function + INDEX.tsv) into a compilable C
corpus: OUT_DIR/decls.h (prototypes + data/import declarations), OUT_DIR/part_NNN.c (PART_SIZE functions each, default 60),
OUT_DIR/ledger.tsv (address, size, name, part, status). The function text is unchanged apart from: (1) class/struct-typed
pointer types Ghidra invented become `unsigned char *` (byte arithmetic, as Ghidra models them); (2) comment header removed."""
import sys, os, re, collections, struct
src, out = sys.argv[1], sys.argv[2]
part = int(sys.argv[3]) if len(sys.argv) > 3 else 60
text_ranges = []   # (lo, hi) of code sections: DAT_/LAB_/UNK_ addresses inside them are numeric constants Ghidra mislabels
for arg in sys.argv[4:]:
    lo, hi = arg.split('-'); text_ranges.append((int(lo, 16), int(hi, 16)))
def in_text(hexaddr): return any(lo <= int(hexaddr, 16) < hi for lo, hi in text_ranges)
os.makedirs(out, exist_ok=True)
for _f in os.listdir(out):   # stale output of an earlier (different) function set must not survive
    if re.match(r"part_\d+\.c$|extra_decls\.h$|externals\.tsv$", _f): os.remove(os.path.join(out, _f))
def sanitize_scoped(t):
    """C++ names (A::b, A<int,B<C> >::d, ~E, operator...) -> C identifiers; angle brackets are matched, so templates nest."""
    t = re.sub(r'::[ \t]*\n[ \t]*', '::', t)
    t = re.sub(r'\n[ \t]*::', '::', t)
    # a function-local static prints as `func(argtypes)::var`: treat as the scoped name `func::var`
    t = re.sub(r'((?:(?<![\w:])|::)~?[A-Za-z_]\w*(?:::~?[A-Za-z_]\w*)*)\([^()]*\)::(?=[A-Za-z_])', r'\1::', t)
    t = re.sub(r'(?<![\w>])::(?=[~A-Za-z_])', '', t)
    out = []; i = 0; n = len(t)
    idr = re.compile(r'~?[A-Za-z_]\w*')
    while i < n:
        m = idr.match(t, i)
        if not m or (i > 0 and (t[i - 1].isalnum() or t[i - 1] == '_')):
            out.append(t[i]); i += 1; continue
        j = m.end(); k = j; scoped = False
        while True:
            if k < n and t[k] == '<':
                d = 0; q = k
                while q < n:
                    if t[q] == '<': d += 1
                    elif t[q] == '>':
                        d -= 1
                        if d == 0: break
                    elif t[q] in ';{}': q = n; break
                    q += 1
                if q >= n: break
                k = q + 1; continue
            if t.startswith('::', k):
                m2 = idr.match(t, k + 2)
                if not m2: break
                k = m2.end(); scoped = True; continue
            break
        seg = t[i:k]
        # a bare `x < y` comparison is not a template: only treat `<` chains that were followed by `::` or that contain no spaces
        if scoped or ('<' in seg and re.fullmatch(r'[\w:<>,*~ &]+', seg) and '::' in seg or ('<' in seg and ' ' not in seg)):
            out.append(re.sub(r'[^A-Za-z0-9_]', '_', seg)); i = k
        else:
            out.append(m.group(0)); i = j
    return ''.join(out)

idx = []
externals = []
name_map = {}   # original (C++ demangled) Ghidra name -> C identifier (first function of that name)
short_map = collections.defaultdict(set)
first_san = {}
used = set(); orig_of = {}
for l in open(os.path.join(src, 'INDEX.tsv')):
    a, sz, name = l.rstrip('\n').split('\t')
    if text_ranges and not in_text(a):   # Ghidra's EXTERNAL-block placeholders for dyld imports (1 byte, no code): recorded, not transcribed
        externals.append((a, name)); continue
    san = re.sub(r'[^A-Za-z0-9_]', '_', name)
    if san in used: san = san + '_' + a[2:]
    used.add(san); orig_of[a] = name
    if name not in first_san: first_san[name] = san
    if '::' in name:
        short_map[name.split('::')[-1]].add(san)
    idx.append((a, int(sz), san))
name_map = {k: v for k, v in first_san.items() if k != v}
plain_names = {n for n in first_san if '::' not in n}   # a real free function of that name exists: the short name must not be redirected
short_unique = {k: list(v)[0] for k, v in short_map.items() if len(v) == 1 and re.match(r'^~?[A-Za-z_]\w*$', k) and k not in plain_names}
idx.sort(key=lambda r: int(r[0], 16))
kw = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'do', 'else', 'case', 'goto', 'const', 'struct', 'union', 'enum', 'typedef', 'extern', 'static'}
PRIM = set('dylib lc_str _Unwind_Exception dwarf_eh_bases vec16 FILE sbyte word va_list section GhidraMachOSection segment_command load_command GhidraMachOCommand pthread_mutex_t pthread_cond_t pthread_t pthread_key_t pthread_once_t pid_t dword time_t off_t mode_t uid_t gid_t int3 uint3 MACH_HEADER_t undefined undefined1 undefined2 undefined3 undefined4 undefined8 uint ulong ushort uchar byte bool longlong ulonglong char short int long unsigned signed void float double code size_t'.split())
# `this` of a __thiscall method call: Ghidra prints `Class::method(args)` and omits the object when it is the caller's own `this`. In C the callee's first parameter
# is that object, so the omitted argument must be added back (the stock passes r3 through). thiscall_n: Ghidra name -> parameter counts of its definitions.
STRING_LIT = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])+\'')
def sub_outside_strings(rx, repl, text):
    """re.sub that leaves string/char literals alone (an error message that names a function - "bad buffer in yy_scan_bytes()" - is not a call)"""
    out, pos = [], 0
    for m in STRING_LIT.finditer(text):
        out.append(re.sub(rx, repl, text[pos:m.start()])); out.append(m.group(0)); pos = m.end()
    out.append(re.sub(rx, repl, text[pos:]))
    return ''.join(out)
def split_params_raw(sp):
    out, d, cur, q = [], 0, '', False
    for ch in sp:
        if ch == '"': q = not q
        if not q:
            if ch in '([<': d += 1
            if ch in ')]>': d -= 1
            if ch == ',' and d == 0: out.append(cur); cur = ''; continue
        cur += ch
    if cur.strip(): out.append(cur)
    return out
thiscall_n = collections.defaultdict(set)
_raw = {}
for a, sz, name in idx:
    _t = open(os.path.join(src, a + '.txt')).read()
    _raw[a] = _t
    _b = '\n'.join(l for l in _t.split('\n') if not l.startswith('//'))
    _i = _b.find('{')
    if _i > 0 and '__thiscall' in _b[:_i]:
        _hd = re.sub(r'\s+', ' ', _b[:_i])
        _m = re.search(r'__thiscall\s+(.+?)\((.*)\)\s*$', _hd.strip())
        if _m: thiscall_n[orig_of.get(a, name)].add(len(split_params_raw(_m.group(2))) if _m.group(2).strip() not in ('', 'void') else 0)
def add_this(body, self_is_thiscall):
    self_this = None
    _ib0 = body.find('{')
    if self_is_thiscall and _ib0 > 0:
        _hm = re.search(r'__thiscall\s+.+?\((.*)\)\s*$', re.sub(r'\s+', ' ', body[:_ib0]).strip())
        if _hm:
            _pp = split_params_raw(_hm.group(1))
            if _pp:
                _nm = re.search(r'(\w+)\s*$', _pp[0].strip())
                self_this = _nm.group(1) if _nm else None
    self_is_thiscall = bool(self_this)
    """insert the omitted object argument into calls of thiscall methods: the caller's own `this` (a method calling a method), else the object the previous
    call to a method of the same class in this function was given (`error(obj, ...); recover();`)"""
    if not thiscall_n: return body, 0
    n_added = 0
    names = sorted(set(thiscall_n) | {n_ for n_ in orig_of.values() if '::' in n_ and not n_.endswith('::~' + n_.split('::')[-1].lstrip('~'))}, key=len, reverse=True)
    rx = re.compile(r'(?<![\w:>~])(' + '|'.join(re.escape(x) for x in names) + r')(\s*)\(')
    out, pos = [], 0
    hdr_end = body.find('{')
    last_obj = {}
    for m in rx.finditer(body):
        if m.start() < hdr_end: continue
        i, d, q = m.end(), 1, False
        while i < len(body) and d:
            ch = body[i]
            if ch == '"' and body[i - 1] != '\\': q = not q
            elif not q:
                if ch == '(': d += 1
                elif ch == ')': d -= 1
            i += 1
        args = body[m.end():i - 1]
        parts = split_params_raw(args) if args.strip() else []
        nargs = len(parts)
        cls = m.group(1).rsplit('::', 1)[0] if '::' in m.group(1) else m.group(1)
        if m.group(1) not in thiscall_n or nargs in thiscall_n[m.group(1)]:
            if parts: last_obj[cls] = parts[0].strip()
        elif (nargs + 1) in thiscall_n[m.group(1)]:
            obj = self_this if self_is_thiscall else last_obj.get(cls)
            if obj:
                out.append(body[pos:m.end()]); out.append(obj + (', ' if args.strip() else '')); pos = m.end(); n_added += 1
                last_obj[cls] = obj
            else:
                unresolved_this.append((m.group(1)))
                if os.environ.get('SHOW_UNRESOLVED'): print('UNRESOLVED', m.group(1), nargs, '|', re.sub(r'\s+', ' ', body[max(0, m.start()-70):m.end()+60]))
    out.append(body[pos:])
    return ''.join(out), n_added
unresolved_this = []
this_added = 0
bodies = {}; defined = {}
for a, sz, name in idx:
    t = _raw[a]
    lines = t.split('\n')
    body = '\n'.join(l for l in lines if not l.startswith('//'))
    _ib = body.find('{')
    body, _n = add_this(body, _ib > 0 and '__thiscall' in body[:_ib])
    this_added += _n
    _lits = []
    body = STRING_LIT.sub(lambda m: (_lits.append(m.group(0)), '__STRLIT_%d__' % (len(_lits) - 1))[1], body)   # names are rewritten below; a message that names a function is data, not a call
    if name_map:
        _names = sorted(name_map, key=len, reverse=True)
        if '_name_rx' not in globals(): _name_rx = re.compile(r'(?<![\w])(?:' + '|'.join(re.escape(n) for n in _names) + r')(?![\w])')
        oname = orig_of.get(a)
        body = re.sub(r'\b(?:__thiscall|__stdcall|__cdecl|__fastcall)\b', '', body)
        # definition header: the function's own (address-unique) name
        san_self = [n for a2, sz2, n in idx if a2 == a][0]
        if oname:
            i0 = body.find('{'); hd = body[:i0]
            hd = re.sub(r'::[ \t]*\n[ \t]*', '::', hd); hd = re.sub(r'\n[ \t]*::', '::', hd)   # a scoped name Ghidra wrapped across lines
            k = hd.rfind(oname)
            if k >= 0: hd = hd[:k] + san_self + hd[k + len(oname):]
            body = hd + body[i0:]
        body = _name_rx.sub(lambda m: name_map[m.group(0)], body)
        for sh, sn in short_unique.items():
            body = re.sub(r'(?<![\w:.>])%s\s*\(' % re.escape(sh), sn + '(', body)
    # the address the switch jumps to (`(int)&table + table[i]`, the operand of the `bctr`): the C `switch` replaces the jump, so nothing reads it
    body = re.sub(r'\(int\)&switchD_\w+::switchdataD_\w+\s*\+\s*\(&switchD_\w+::switchdataD_\w+\)\[[^\]]+\]', '0', body)
    body = re.sub(r'\b(?:switchD_[0-9a-f]+)::(switchdataD_[0-9a-f]+)', r'\1', body)
    body = sanitize_scoped(body)
    body = re.sub(r'__STRLIT_(\d+)__', lambda m: _lits[int(m.group(1))], body)
    body = re.sub(r'/\*.*?\*/', lambda m: '', body, flags=re.S)
    body = re.sub(r'\b(?:switchD_[0-9a-f]+)::(switchdataD_[0-9a-f]+)', r'\1', body)
    if '!! decompile failed' in body: bodies[a] = None; continue
    bodies[a] = body.strip('\n') + '\n'
# collect referenced tokens
defined_names = {name for a, sz, name in idx}
allbody = '\n'.join(b for b in bodies.values() if b)
data_syms = sorted(set(re.findall(r'\bswitchdataD_[0-9a-f]{8}\b|(?<![A-Za-z0-9])_?(?:DAT|UNK|PTR|EXT)_[0-9a-f]{8}\b|\b(?:PTR_)?(?:s|u|PTR)_[A-Za-z_0-9]*_[0-9a-f]{8}\b|\bPTR_[A-Za-z_0-9]+_[0-9a-f]{8}\b', allbody)))
data_syms = [d for d in data_syms if not (re.search(r'_([0-9a-f]{8})$', d) and in_text(re.search(r'_([0-9a-f]{8})$', d).group(1)) and not d.startswith(('PTR_', 'switchdataD_')))]
calls = set(re.findall(r'\b([A-Za-z_][A-Za-z_0-9]*)\s*\(', allbody))
imports = sorted(c for c in calls if c not in kw and c not in defined_names and c not in PRIM and not re.match(r'^(CONCAT|SUB|ZEXT|SEXT|sync|instructionSynchronize|dataCache|enforce|trap|halt|CARRY|SCARRY|SBORROW|LOCK|UNLOCK|NAN|ROUND|ABS|INT2FLOAT|FLOAT2FLOAT|TRUNC|POPCOUNT|BREAK|GBITS)', c) and c not in data_syms)
# return types of defined functions: text before the name on its definition line(s)
def ret_type(body, name):
    m = re.search(r'^(.*?)\b' + re.escape(name) + r'\s*\(', body, flags=re.M | re.S)
    return (m.group(1).strip() if m else 'int') or 'int'
TYPE = r'[A-Za-z_][\w]*(?:::[~A-Za-z_]\w*)*(?:<[^;(){}]*?>)?(?:::[~A-Za-z_]\w*)*'
def fix_types(s):
    """class/struct-typed types Ghidra invented -> unsigned char (pointers stay pointers; only in type positions)"""
    # AltiVec 128-bit registers: Ghidra's `undefined1 auVarN [16]` locals are assigned from vector loads and passed to
    # vectorPermute(); model them as a 16-byte struct (assignable) instead of an array
    s = re.sub(r'undefined1 (auVar\d+) \[16\];', r'vec16 \1;', s)
    s = s.replace('(undefined1 (*) [16])', '(vec16 *)')
    def base(t): return re.split(r'[<:]', t)[0]
    def isty(t): return base(t) not in PRIM and base(t) not in kw and t not in PRIM
    ib = s.find('{')
    head, rest = (s[:ib], s[ib:]) if ib >= 0 else ('', s)
    # K&R parameter declarations / plain declarations (`TYPE *name;`, `TYPE name;`, `TYPE name [N];`)
    decl = re.compile(r'(?m)^(\s+)(?:const\s+)?(' + TYPE + r')(\s*\*+\s*|\s+)([A-Za-z_]\w*)(\s*(?:\[[^\]]*\])?\s*;)')
    def dfix(m):
        if not isty(m.group(2)) or m.group(2) in ('return', 'goto', 'else', 'case'): return m.group(0)
        stars = m.group(3).strip()
        return '%sunsigned char %s%s%s' % (m.group(1), (stars + ' ') if stars else '', m.group(4), m.group(5))
    head = decl.sub(dfix, head)
    _m = re.search(r'\n[ \t]*\n', rest)
    ie = _m.start() if _m else -1
    if ie > 0:
        blk = decl.sub(dfix, rest[:ie]); rest = blk + rest[ie:]
    # casts to class types: `(T *)`, `(T **)` and `(T)literal`
    rest = re.sub(r'\(\s*(?:const\s+)?(' + TYPE + r')(\s*\*+)\s*\)', lambda m: '(unsigned char' + m.group(2) + ')' if isty(m.group(1)) else m.group(0), rest)
    rest = re.sub(r'\(\s*(' + TYPE + r')\s*\)(?=\s*(?:0x|\d|\())', lambda m: '' if isty(m.group(1)) else m.group(0), rest)
    # parameters of call-through function types etc: `(T *param` in headers
    head = re.sub(r'(?<=[(,])\s*(?:const\s+)?(' + TYPE + r')(\s*\*+\s*)([A-Za-z_]\w*)(?=\s*[,)])', lambda m: ' unsigned char' + m.group(2) + m.group(3) if isty(m.group(1)) else m.group(0), head)
    return head + rest
SMALL = re.compile(r'\b(byte|uchar|char|short|ushort|bool|undefined1|undefined2|undefined)\b(?!\s*\*)')
def split_header(body, name):
    i = body.index('{')
    head = body[:i]
    m = re.search(r'^(.*?)\b' + re.escape(name) + r'\s*\((.*)\)\s*$', head.strip(), flags=re.S)
    if not m: return None
    return m.group(1).strip(), m.group(2).strip()
def split_params(sp):
    out, d, cur = [], 0, ''
    for ch in sp:
        if ch in '([': d += 1
        if ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
def fix_proto_type(t):
    """a prototype's type (one line, not a K&R declaration): a class/struct type Ghidra invented becomes unsigned char, keeping pointer stars
    (`TIntermConstantUnion *` in fold's exact prototype broke every part: fix_types only rewrites declarations at line starts)"""
    t = ' '.join(t.split())
    m = re.match(r'^(const\s+)?([A-Za-z_][\w:<>, ]*?)\s*(\**)$', t)
    if not m:
        return t
    b = re.split(r'[<:]', m.group(2))[0]
    if b in PRIM or b in kw or m.group(2) in PRIM:
        return t
    return ('unsigned char ' + m.group(3)).strip()
def fix_proto_param(q):
    m = re.match(r'^(.*?)([A-Za-z_]\w*)$', q.strip())
    if not m:
        return q
    ty = m.group(1).strip()
    return '%s%s%s' % (fix_proto_type(ty), '' if fix_proto_type(ty).endswith('*') else ' ', m.group(2))
proto = {}
for a, sz, name in idx:
    b = bodies.get(a)
    if not b: continue
    h = split_header(b, name)
    if not h: continue
    rt, params = h
    exact = bool(re.search(r'\b(float|double)\b(?!\s*\*)', rt + ' ' + params)) and not os.environ.get('LOOSE')   # LOOSE: verification build, callee sets only (float ABI irrelevant)
    if exact:
        proto[a] = (fix_proto_type(rt), ','.join(fix_proto_param(q) for q in split_params(' '.join(params.split()))), True)
        # the definition keeps an ANSI header (float/double arguments), written from the sanitised prototype: Ghidra's own header text can carry an
        # invented class type on a line of its own (`TIntermConstantUnion *` before fold's name), which fix_types does not see
        i = b.index('{')
        bodies[a] = '%s %s(%s)\n' % (proto[a][0], name, proto[a][1]) + b[i:]
    else:
        nrt = 'int' if not re.search(r'\b(longlong|ulonglong|undefined8)\b(?!\s*\*)', rt) else fix_types(rt + ' ').strip()
        nparams = SMALL.sub('int', params)
        proto[a] = (nrt, fix_types(nparams + ' ').strip(), False)
        # rewrite the definition header
        i = b.index('{')
        pl = [] if nparams in ('void', '') else split_params(fix_types(nparams + ' ').strip())
        names = []; decl = []
        pl = [q_ for q_ in pl if q_.strip() != '...']   # variadic: a K&R definition accepts the extra arguments anyway
        for p_ in pl:
            mm = re.match(r'^(.*?)(\w+)((?:\s*\[[^\]]*\])*)$', p_.strip())
            if not mm: names = None; break
            names.append(mm.group(2)); decl.append('  %s%s%s;' % (mm.group(1), mm.group(2), mm.group(3)) if not mm.group(1).strip().endswith('*') else '  %s%s%s;' % (mm.group(1), mm.group(2), mm.group(3)))
        if names is None: bodies[a] = nrt + ' ' + name + '(' + fix_types(nparams + ' ').strip() + ')\n\n' + b[i:]
        else: bodies[a] = nrt + ' ' + name + '(' + ', '.join(names) + ')\n' + '\n'.join(decl) + ('\n' if decl else '') + b[i:]
# A function whose own decompile returns nothing (`void`) but that a caller uses the result of (`f1 = (double)f(...)`, `if (f(...) == 0)`): Ghidra models the callee as
# leaving a value in f1/r3 it never wrote (a passed-through argument). C cannot use a void result, so such a function is given the type its callers read it as.
_void_names = {name for a_, (rt_, pr_, ex_) in proto.items() for a2_, sz2_, name in idx if a2_ == a_ and ex_ and rt_ == 'void'}
if _void_names:
    _allb = '\n'.join(b_ for b_ in bodies.values() if b_)
    for _vn in _void_names:
        _m = re.search(r'(?:[=(,!]|==|!=|&&|\|\|)\s*(?:\(([\w ]+)\))?\s*%s\s*\(' % re.escape(_vn), _allb)
        if not _m: continue
        _nt = 'double' if (_m.group(1) or '').strip() in ('double', 'float') else 'int'
        for a_, sz_, name_ in idx:
            if name_ == _vn and bodies.get(a_):
                bodies[a_] = re.sub(r'(?m)^void(\s+)%s\b' % re.escape(_vn), r'%s\1%s' % (_nt, _vn), bodies[a_], count=1)
                rt_, pr_, ex_ = proto[a_]; proto[a_] = (_nt, pr_, ex_)
decls = ['#include "ghidra_c.h"', '']
exact_fns = {name: a for a, (rt, params, exact) in [(a, proto[a]) for a in proto] for a2, sz2, name in idx if a2 == a and exact}
for a, sz, name in idx:
    if a in proto:
        rt, params, exact = proto[a]
        decls.append('extern %s %s(%s);' % (rt, name, params) if exact else 'extern %s %s();' % (rt, name))
# libm imports return their value in f1: declared `int` the C read r3 (GLDriver's float formatter printed every exponent as `e00`: `_log(x) /
# _log(10)` was garbage; glprog's constant folding of sin/cos/pow...). K&R declarations with the real return type (arguments keep the default
# promotions, as Ghidra printed them).
_LIBM_D = {'log', 'log10', 'log2', 'pow', 'sqrt', 'sin', 'cos', 'tan', 'exp', 'exp2', 'floor', 'ceil', 'fabs', 'atof', 'strtod', 'ldexp', 'fmod',
           'modf', 'frexp', 'atan', 'atan2', 'asin', 'acos', 'round', 'trunc', 'rint', 'hypot', 'cbrt', 'sinh', 'cosh', 'tanh', 'nearbyint'}
_LIBM_F = {x + 'f' for x in _LIBM_D}
for n in imports:
    if n in ('vectorPermute', 'vectorConditionalSelect'): continue   # vectorPermute is declared (returning vec16) in ghidra_c.h
    bn = n.lstrip('_')
    decls.append('extern %s %s();' % ('double' if bn in _LIBM_D else 'float' if bn in _LIBM_F else 'int', n))
called_data = set(re.findall(r'\(\s*\*\s*\(?\s*(?:\(code \*\))?\s*([A-Za-z_]\w*)\s*\)\s*\)?\s*\(', allbody))
deref = set(re.findall(r'(?<![\w)\]])\*\s*\(?\s*([A-Za-z_]\w*)\b', allbody)) | set(re.findall(r'\b([A-Za-z_]\w*)\s*\[', allbody)) | set(re.findall(r'\(\s*[\w ]+\*+\s*\)\s*\*\s*([A-Za-z_]\w*)', allbody))
tables = {t for t in re.findall(r'\(&\s*([A-Za-z_]\w*)\s*\)\s*\[', allbody) if re.match(r'^(?:_?(?:DAT|UNK|PTR|EXT)_|PTR_|FLOAT_|DOUBLE_|switchdataD_|s_|u_)', t)}
for d in data_syms:
    if d.startswith('switchdataD_'): decls.append('extern int %s[];' % d)
    elif d in tables: decls.append('extern unsigned char *%s[];' % d if d.startswith('PTR_') else 'extern unsigned char %s[];' % d)
    elif d in called_data: decls.append('extern int (*%s)();' % d)
    elif d in deref: decls.append('extern unsigned char *%s;' % d)
    else: decls.append('extern unsigned char %s;' % d)
if re.search(r'\bMACH_HEADER\b', allbody): decls.append('extern MACH_HEADER_t MACH_HEADER;')
for mh in sorted(set(re.findall(r'\b(__mh_\w+_header)\b', allbody))): decls.append('extern MACH_HEADER_t %s;' % mh)
ftab = set(re.findall(r'\(\s*((?:FLOAT|DOUBLE)_[0-9a-f]{8})\s*\)\s*\[', allbody)) | set(re.findall(r'\b((?:FLOAT|DOUBLE)_[0-9a-f]{8})\s*\[', allbody)) | tables
for f in sorted(set(re.findall(r'\bFLOAT_[0-9a-f]{8}\b', allbody))): decls.append('extern float %s%s;' % (f, '[]' if f in ftab else ''))
for f in sorted(set(re.findall(r'\bDOUBLE_[0-9a-f]{8}\b', allbody))): decls.append('extern double %s%s;' % (f, '[]' if f in ftab else ''))
open(os.path.join(out, 'decls.h'), 'w').write('\n'.join(decls) + '\n')
print('thiscall arguments restored: %d (%d still without an object)' % (this_added, len(unresolved_this)))
def fix_arrays(b):
    """Ghidra declares stack pieces as arrays but the code treats them as scalars, indexes past the declared bound (the array runs
    over the following stack variables), or stores 4-byte pieces into byte arrays."""
    # (0) arrays indexed past their declared bound: absorb the contiguous run of stack variables that follows them
    decl_rx = r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+(\w*(?:local|Stack)_([0-9a-f]+))\s*(?:\[\s*(\d+)\s*\])?;'
    for m in list(re.finditer(decl_rx, b)):
        if m.group(4) is None: continue
        nm, off, cnt = m.group(2), int(m.group(3), 16), int(m.group(4))
        ty = m.group(1).strip()
        if ty not in ('undefined4', 'uint', 'int', 'ulong', 'long', 'undefined *', 'undefined **', 'code *', 'float', 'unsigned int'): continue
        rest = b[:m.start()] + b[m.end():]
        ix = re.findall(r'(?<![&\w.])(?:\(\s*%s\s*\)|%s)\s*\[\s*([^\]]+)\]' % (re.escape(nm), re.escape(nm)), rest)
        lit_over = any(re.fullmatch(r'\d+|0x[0-9a-f]+', i.strip()) and int(i.strip(), 0) >= cnt for i in ix)
        var_idx = any(not re.fullmatch(r'\d+|0x[0-9a-f]+', i.strip()) for i in ix)
        if not ix or not (lit_over or (var_idx and cnt == 1)): continue
        total = cnt
        while True:
            cand = off - 4 * total
            m2 = None
            for mm in re.finditer(decl_rx, b):
                if int(mm.group(3), 16) == cand and mm.group(2) != nm: m2 = mm; break
            if not m2: break
            n2 = m2.group(2); c2 = int(m2.group(4)) if m2.group(4) else None
            if m2.group(1).strip() not in ('undefined4', 'uint', 'int', 'ulong', 'long', 'float', 'undefined *', 'unsigned int', 'code *'): break
            span = c2 if c2 else 1
            # drop the absorbed declaration first, then rename its uses
            b = b.replace(m2.group(0), '', 1)
            if c2:
                b = re.sub(r'(?<![\w.])%s\s*\[\s*(\d+)\s*\]' % re.escape(n2), lambda z: '%s[%d]' % (nm, total + int(z.group(1))), b)
                b = re.sub(r'(?<![\w.])%s\s*\[' % re.escape(n2), '(%s + %d)[' % (nm, total), b)
                b = re.sub(r'(?<![\w.&])%s\b(?!\s*\[)' % re.escape(n2), '(%s + %d)' % (nm, total), b)
            else:
                b = re.sub(r'(?<![\w.])%s\b(?!\s*\[)' % re.escape(n2), '%s[%d]' % (nm, total), b)
            total += span
        if total != cnt:
            b = re.sub(r'(?m)^(\s*)([A-Za-z_][\w ]*?)([\s*]+)%s\s*\[\s*%d\s*\];' % (re.escape(nm), cnt), lambda z: '%s%s%s%s[%d];' % (z.group(1), z.group(2), z.group(3), nm, total), b, count=1)
        # scalar uses of the array name -> element 0
        b = re.sub(r'&\s*\(\s*%s\s*\)' % re.escape(nm), '&(%s[0])' % nm, b)
        b = re.sub(r'(?<![&\w.])%s\b(?!\s*\[)(?!\s*\)\s*\[)' % re.escape(nm), '%s[0]' % nm, b)
    # (1) one-element arrays used as scalars
    for um in list(re.finditer(r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+(\w+)\s*\[\s*1\s*\];', b)):
        nm = um.group(2)
        if re.search(r'(?<![&\w.])%s\s*\)?\s*\[\s*[^0\]]' % re.escape(nm), b[:um.start()] + b[um.end():]): continue   # genuinely indexed beyond element 0
        m2 = re.search(r'(?m)^\s*([A-Za-z_][\w ]*?)[\s*]+%s\s*\[\s*1\s*\];' % re.escape(nm), b)
        if not m2: continue
        ty = m2.group(1).strip()
        b = b.replace(m2.group(0), '  %s %s;' % (ty, nm), 1)
        b = re.sub(r'(?<![\w.])%s\s*\[\s*0\s*\]' % re.escape(nm), nm, b)
        b = re.sub(r'\(%s\)\s*\[\s*0\s*\]' % re.escape(nm), nm, b)
    # (2) byte-array locals that are stored to as 4-byte pieces: `NAME = (unsigned int)(...)` -> `*(unsigned int *)NAME = ...`
    for am in list(re.finditer(r'(?m)^\s*(?:char|byte|undefined1?|uchar)\s+([A-Za-z_]\w*)\s*\[\s*\d+\s*\];', b)):
        nm = am.group(1)
        b = re.sub(r'(?m)^(\s*)%s\s*=\s*\((unsigned int|unsigned short)\)' % re.escape(nm), lambda m: '%s*(%s *)%s = (%s)' % (m.group(1), m.group(2), nm, m.group(2)), b)
        b = re.sub(r'(?m)^(\s*)%s\s*=\s*(\(\*\((?:unsigned int|unsigned short) \*\))' % re.escape(nm), lambda m: '%s*(unsigned int *)%s = %s' % (m.group(1), nm, m.group(2)), b)
    b = re.sub(r'(?m)^(\s*p\w+ = (?:\(\w+ \*\))?)((?:local|\w*Stack)_[0-9a-f]+)\[0\];', r'\1\2;', b)   # array decay (pointer to the buffer), not element 0
    return b

led = []
import importlib.util
_pp = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'patches.py')
PATCHES = {}
NOTES = {}
if os.path.exists(_pp):
    _spec = importlib.util.spec_from_file_location('patches', _pp); _m = importlib.util.module_from_spec(_spec); _spec.loader.exec_module(_m); PATCHES = _m.PATCHES; NOTES = getattr(_m, 'NOTES', {})
_PatchError = getattr(_m, 'PatchError', Exception) if os.path.exists(_pp) else Exception
CORPUS_SCOPE = os.environ.get('CORPUS_SCOPE', '')
# int <-> float casts that are only Ghidra's typing: a union word (GLSL TIntermConstantUnion::fold keeps int, float and bool constants in one
# `float *` array), an object pointer in a float-typed local. 32-bit PowerPC has no int->float instruction (a real conversion is the 0x43300000
# magic-double sequence, printed as CONCAT44), and a real float->int conversion needs fctiw/fctiwz - so `(float)<int expression>` is always a bit
# reinterpretation, and `(int)fVarN` is one in every function whose stock code has no fctiw*. The rebuilt fold had folded ivec4(7,5,17,6) -
# ivec4(3,1,4,2) to 0 and reported a divide by zero for the division (the denormal bits of a small integer converted to 0).
_FCTIW = None
if os.environ.get('CORPUS_SLICE') and os.path.exists(os.path.join(src, 'RANGES.tsv')):
    import struct as _st
    _d = open(os.environ['CORPUS_SLICE'], 'rb').read(); _secs = []
    _nc = _st.unpack('>I', _d[16:20])[0]; _p = 28
    for _ in range(_nc):
        _c, _cs = _st.unpack('>II', _d[_p:_p + 8])
        if _c == 1:
            _ns = _st.unpack('>I', _d[_p + 48:_p + 52])[0]; _q = _p + 56
            for _ in range(_ns):
                _a, _sz, _off = _st.unpack('>3I', _d[_q + 32:_q + 44]); _secs.append((_a, _sz, _off)); _q += 68
        _p += _cs
    def _word(x):
        for sa, sz_, off in _secs:
            if sa <= x < sa + sz_ and off: return _st.unpack('>I', _d[off + x - sa:off + x - sa + 4])[0]
        return 0
    _FCTIW = set()
    for _l in open(os.path.join(src, 'RANGES.tsv')):
        _f = _l.rstrip('\n').split('\t')
        if len(_f) > 3 and _f[0].startswith('0x') and _f[2] == 'fn':
            for _r in _f[3].split(';'):
                if not _r: continue
                _lo, _hi = (int(x, 16) for x in _r.split('-'))
                if any((_word(x) >> 26) == 63 and ((_word(x) >> 1) & 0x3ff) in (14, 15) for x in range(_lo, _hi, 4)):
                    _FCTIW.add(int(_f[0], 16)); break
    # NaN-pattern constants each function builds (`lis rD,hi` + `ori rD,rD,lo` / `addi rD,rD,lo` / nothing): Ghidra prints a float variable holding ANY NaN
    # pattern as the bare token NAN (payload lost) although the stock's is 0x7fffffff (INT_MAX assigned to a union word Ghidra typed float). GH_NAN() in the
    # recompile is math.h's 0x7fc00000. fix_nan() below substitutes the real bits.
    _NANC = {}
    for _l in open(os.path.join(src, 'RANGES.tsv')):
        _f = _l.rstrip('\n').split('\t')
        if len(_f) > 3 and _f[0].startswith('0x') and _f[2] == 'fn':
            _cs = set()
            for _r in _f[3].split(';'):
                if not _r: continue
                _lo, _hi = (int(x, 16) for x in _r.split('-'))
                for x in range(_lo, _hi, 4):
                    w = _word(x)
                    if (w >> 26) != 15 or ((w >> 16) & 31) != 0: continue      # addis rD,0,imm = lis
                    rd = (w >> 21) & 31; v = (w & 0xffff) << 16; w2 = _word(x + 4)
                    if (w2 >> 26) == 24 and ((w2 >> 21) & 31) == rd: v |= w2 & 0xffff       # ori rA,rS,imm (rS = rD)
                    elif (w2 >> 26) == 14 and ((w2 >> 16) & 31) == rd:                     # addi rD,rD,simm
                        v = (v + ((w2 & 0xffff) - (0x10000 if w2 & 0x8000 else 0))) & 0xffffffff
                    if (v >> 23) & 0xff == 0xff and v & 0x7fffff: _cs.add(v)
            _NANC[int(_f[0], 16)] = _cs
def _operand(t, i):
    """end index of the primary expression starting at t[i] (after optional unary - * & and casts): an identifier with subscripts / member
    access, a parenthesised expression, a literal"""
    n = len(t)
    while i < n and t[i] == ' ': i += 1
    while i < n and t[i] in '-*&!~': i += 1
    while i < n and t[i] == '(':   # a cast or a parenthesised expression
        d = 0; j = i
        while j < n:
            if t[j] == '(': d += 1
            elif t[j] == ')':
                d -= 1
                if d == 0: break
            j += 1
        inner = t[i + 1:j]
        if re.match(r'^\s*(?:unsigned |signed )?[A-Za-z_]\w*(?:\s*\*)*\s*$', inner) and not re.match(r'^\s*[a-z]\w*Var\d+\s*$', inner):
            i = j + 1   # a cast: the operand follows
            while i < n and t[i] in ' -*&!~': i += 1
            continue
        i = j + 1; break
    else:
        m = re.match(r'[A-Za-z_]\w*|0x[0-9a-fA-F]+|\d+', t[i:])
        if not m: return None
        i += m.end()
    while i < n and t[i] in '[.-(':   # subscripts / member access / a call's argument list
        if t[i] == '(':
            d = 0; j = i
            while j < n:
                if t[j] == '(': d += 1
                elif t[j] == ')':
                    d -= 1
                    if d == 0: break
                j += 1
            i = j + 1
        elif t[i] == '[':
            d = 0; j = i
            while j < n:
                if t[j] == '[': d += 1
                elif t[j] == ']':
                    d -= 1
                    if d == 0: break
                j += 1
            i = j + 1
        elif t.startswith('->', i) or t[i] == '.':
            k = i + (2 if t[i] == '-' else 1); m = re.match(r'[A-Za-z_]\w*', t[k:])
            if not m: break
            i = k + m.end()
        else: break
    return i
_FLOATY = re.compile(r'\b(?:[fd]Var\d+|pfVar\d+|pdVar\d+|FLOAT_\w+|DOUBLE_\w+|fparam_\w+|in_f\d+|extraout_f\d+|float|double)\b|\d\.\d|\d+e[-+]?\d')
def fix_float_int(b, entry):
    floc = set(re.findall(r'(?m)^\s+float\s+(\w+)(?:\s*\[\d+\])?;', b))
    out = []; i = 0; n = 0
    while True:
        m = re.search(r'\((float|int|uint|u?short|u?char|byte|undefined4)\)', b[i:])
        if not m: out.append(b[i:]); break
        st = i + m.start(); en = i + m.end(); ty = m.group(1)
        e = _operand(b, en)
        if e is None: out.append(b[i:en]); i = en; continue
        opd = b[en:e].strip()
        # a comparison / logical expression is an int (0 or 1) whatever the variables inside it are: `(uint)(fVar5 == fVar6)` is the bool word, not a float
        _cmp = re.search(r'==|!=|<=|>=|&&|\|\||(?<![<-])<(?![<=])|(?<![>-])>(?![>=])', re.sub(r'"[^"]*"', '', opd))
        if _cmp and ty != 'float':
            out.append(b[i:en]); i = en; continue
        if _cmp and re.match(r'^\(\s*(?:u?int|byte|u?short|u?char|undefined\d?|bool)\s*\)', opd):   # the outer `(float)(uint)(a == b)`: an int stored into a float-typed word
            out.append(b[i:st]); out.append('GH_U2F((unsigned int)(%s))' % opd); i = e; n += 1; continue
        if ty == 'float':
            # an integer expression made float without the conversion sequence
            if opd and not _FLOATY.search(opd) and not opd.startswith('('+'double'):
                out.append(b[i:st]); out.append('GH_U2F((unsigned int)(%s))' % opd); i = e; n += 1; continue
        elif _FCTIW is not None and entry not in _FCTIW:
            base = re.match(r'^\*?\(?\s*([A-Za-z_]\w*)', opd)
            if base and (re.match(r'^(?:f)Var\d+$', base.group(1)) or base.group(1) in floc or re.match(r'^pfVar\d+$', base.group(1)) and ('[' in opd or opd.startswith('*'))) \
               and not re.search(r'[+\-*/]\s', opd):
                out.append(b[i:st]); out.append('(%s)GH_F2U(%s)' % (ty, opd)); i = e; n += 1; continue
        out.append(b[i:en]); i = en
    return ''.join(out), n
# Callee parameter types by name, for fix_float_args
_PTYPES = {}
for _a, _sz, _nm in idx:
    if _a in proto and bodies.get(_a):
        _rt, _pr, _ex = proto[_a]
        _pl = [] if _pr.strip() in ('void', '') else split_params(_pr)
        _PTYPES[_nm] = [re.sub(r'\b\w+$', '', q.strip()).strip() or 'int' for q in _pl]
def _split_call_args(t):
    out = []; d = 0; cur = ''; q = None
    for ch in t:
        if q:
            cur += ch
            if ch == q: q = None
            continue
        if ch in '"\'': q = ch; cur += ch; continue
        if ch in '([': d += 1
        if ch in ')]': d -= 1
        if ch == ',' and d == 0: out.append(cur.strip()); cur = ''
        else: cur += ch
    if cur.strip(): out.append(cur.strip())
    return out
_FLT_ARG = re.compile(r'^(\*)(p?fVar\d+)$|^(pfVar\d+)\[([^\[\]]+)\]$|^(fVar\d+)$|^\*\(float \*\)(.+)$')
def fix_float_args(b):
    """A float-typed lvalue (`*pfVar24`, `pfVar24[1]`, `fVar10`, `*(float *)p`) passed where the callee's parameter is an integer / pointer: Ghidra typed the
    pointer float because another path of the function reads floats through it, but this call passes the WORD (the stock loads it with `lwz` into an
    argument register). Left as is, gcc converts the float to an int (or, through an unprototyped `(int (*)())` cast, passes a double: r4 = its high word) -
    the rebuilt `PARAM prm0 = {916455424, 0, 0, 0}` for `float(bool)`. -> the word."""
    out = []; i = 0; n = 0
    for m in re.finditer(r'(?<![\w.>])([A-Za-z_]\w*)\)?\(', b):
        name = m.group(1)
        if name not in _PTYPES or m.start() < i: continue
        j = m.end(); d = 1
        while d and j < len(b):
            if b[j] == '(': d += 1
            elif b[j] == ')': d -= 1
            j += 1
        args = _split_call_args(b[m.end():j - 1]); changed = False
        for k, a in enumerate(args):
            if k >= len(_PTYPES[name]) or re.search(r'\b(float|double)\b(?!\s*\*)', _PTYPES[name][k]): continue
            fm = _FLT_ARG.match(a)
            if not fm: continue
            if fm.group(2): args[k] = '*(unsigned int *)%s' % fm.group(2)
            elif fm.group(3): args[k] = '((unsigned int *)%s)[%s]' % (fm.group(3), fm.group(4))
            elif fm.group(5): args[k] = 'GH_F2U(%s)' % fm.group(5)
            else: args[k] = '*(unsigned int *)%s' % fm.group(6)
            changed = True; n += 1
        if changed:
            out.append(b[i:m.end()]); out.append(', '.join(args) + ')'); i = j
    out.append(b[i:])
    return ''.join(out), n
def fix_home_slots(b, name):
    """`STACKARG(0x18..0x34)` is the caller-allocated home word of one of the register arguments r3..r10 (entry-sp + 0x18 + 4k): a function that takes the address
    of a by-value struct / char array / va_list argument spills the register there in its prologue (TIntermediate::makeAggregate's TSourceLoc,
    TPPStreamCompiler::error's `...` handed to vsprintf, PPCRuntimeCompiler*'s 4-byte swizzle masks). The recompiled function does not spill: the C read the
    caller's parameter area, i.e. whatever the caller left there. Give the function its own home words, filled with the incoming register parameters."""
    _fa = r'\(\*\(([^()]*?) \*\)\(\*\(unsigned int \*\)__builtin_frame_address\(0\) \+ 0x([0-9a-f]+)\)\)'   # `bStack00000021` / `puStack00000020` / `in_stack_00000024`
    slots = [m for m in re.findall(r'STACKARG\((0x[0-9a-f]+)\)', b) if 0x18 <= int(m, 16) < 0x38] + [m[1] for m in re.findall(_fa, b) if 0x18 <= int(m[1], 16) < 0x38]
    if not slots: return b, 0
    k = b.index('{'); head, rest = b[:k], b[k:]
    hm = re.search(r'\(([^()]*)\)', head)
    if not hm: return b, 0
    if re.search(r'\b(float|double|longlong|ulonglong|undefined8)\b(?!\s*\*)', head):
        sys.stderr.write('HOME-SLOTS: %s has float / 64-bit parameters - STACKARG home words left as is\n' % name); return b, 0
    names = [q.strip().split()[-1].lstrip('*') for q in hm.group(1).split(',') if q.strip() and q.strip() != 'void']
    words = (names + ['0'] * 8)[:8]
    rest = rest.replace('{\n', '{\n  unsigned int ghidra_home[8] = { %s };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */\n' % ', '.join(words), 1)
    rest = re.sub(r'STACKARG\((0x[0-9a-f]+)\)', lambda m: '(*(unsigned int *)((unsigned char *)ghidra_home + %d))' % (int(m.group(1), 16) - 0x18) if 0x18 <= int(m.group(1), 16) < 0x38 else m.group(0), rest)
    rest = re.sub(_fa, lambda m: '(*(%s *)((unsigned char *)ghidra_home + %d))' % (m.group(1), int(m.group(2), 16) - 0x18) if 0x18 <= int(m.group(2), 16) < 0x38 else m.group(0), rest)
    return head + rest, len(slots)
def fix_nan(b, entry):
    """a bare `NAN` token (a float-typed variable holding a NaN-pattern word) -> the one NaN-pattern constant the stock function builds"""
    if not re.search(r'(?<![\w"])NAN\b(?!\s*\()', b): return b, 0
    cs = sorted(_NANC.get(entry, ())) if _FCTIW is not None else []
    if len(cs) != 1:
        sys.stderr.write('NAN-CONST: %x has %d candidate NaN constants %s - not substituted\n' % (entry, len(cs), [hex(c) for c in cs]))
        return b, 0
    # (in)equality with the constant: the stock compares the WORDS (a NaN never compares equal as a float), so compare bits
    _opd = r'(\*?[A-Za-z_]\w*(?:\[[^\]\n]*\])?)'
    b = re.sub(_opd + r'\s*(==|!=)\s*NAN\b(?!\s*\()', lambda m: '(GH_F2U(%s) %s 0x%08xU)' % (m.group(1), m.group(2), cs[0]), b)
    b = re.sub(r'(?<![\w"])NAN\b(?!\s*\()\s*(==|!=)\s*' + _opd, lambda m: '(GH_F2U(%s) %s 0x%08xU)' % (m.group(2), m.group(1), cs[0]), b)
    return re.sub(r'(?<![\w"])NAN\b(?!\s*\()', 'GH_U2F(0x%08xU)' % cs[0], b), 1
_applied = set()
funcs = [(a, sz, name) for a, sz, name in idx]
for pi in range(0, len(funcs), part):
    chunk = funcs[pi:pi + part]; pn = 'part_%03d' % (pi // part)
    samepart = [n for a_, sz_, n in chunk if bodies.get(a_)]
    with open(os.path.join(out, pn + '.c'), 'w') as f:
        f.write('#include "decls.h"\n\n')
        for a, sz, name in chunk:
            b = bodies.get(a)
            if b is None: led.append((a, sz, name, pn, 'DECOMPILE-FAILED')); continue
            f.write('/* %s @ %s (%d bytes) */\n' % (name, a, sz))
            labels = set(re.findall(r'^\s*(LAB_[0-9a-f]+):', b, flags=re.M)) | set(re.findall(r'^(switchD_\w+):', b, flags=re.M))
            def fixgoto(m):
                return m.group(0) if m.group(1) in labels else 'return ((int (*)())0x%s)();   /* Ghidra: jump to a label inside another function */' % m.group(1)[4:].lstrip('0').rjust(1, '0') if m.group(1).startswith('LAB_') else m.group(0)
            b = re.sub(r'\bgoto (LAB_[0-9a-f]+|switchD_\w+);', fixgoto, b)
            b = re.sub(r'(?m)^(\s*(?:LAB_[0-9a-f]+|switchD_\w+):)(\s*\n\s*\})', r'\1 ;\2', b)
            b = re.sub(r'(?m)^(\s*(?:case [^:\n]+|default):)(\s*\n\s*\})', r'\1 ;\2', b)
            b = re.sub(r'\(code\)', '(code *)', b)
            b = re.sub(r'\((\w+(?: \*)+)\)((?:FLOAT|DOUBLE)_[0-9a-f]{8})\b', r'(\1)&\2', b)
            b = re.sub(r'(?m)^(\s*)(auVar\d+) = ZEXT816\(0\) << 0x20;', r'\1_memset(\2, 0, 16);', b)
            for tn in ftab: b = re.sub(r'(?<![\w&])%s\b(?!\s*\[)(?!\s*\)\s*\[)' % tn, '%s[0]' % tn, b)
            b = re.sub(r'(?m)^(\s*)char (ac\w+)\s*\[\s*\d+\s*\];(?=(?:.|\n)*^\s*\2 = (?:ac|&)\w+;)', r'\1char *\2;', b)
            b = re.sub(r'\b_(local_[0-9a-f]+)\b', r'\1', b)
            # array-declared locals that Ghidra assigns as scalars/pointers
            for am in re.finditer(r'(?m)^\s*(?:char|byte|undefined1?|uchar|short|ushort)\s+([A-Za-z_]\w*)\s*\[\s*\d+\s*\];', b):
                nm = am.group(1)
                if re.search(r'(?m)^\s*%s\s*=\s*(?:&?[A-Za-z_(]|\()' % re.escape(nm), b) and not re.search(r'\b%s\s*\[' % re.escape(nm), b):
                    b = re.sub(r'(?m)^(\s*)(?:char|byte|undefined1?|uchar|short|ushort)\s+%s\s*\[\s*\d+\s*\];' % re.escape(nm), r'\1unsigned char *%s;' % nm, b)
            # scalar-declared locals used as arrays -> arrays sized to the gap to the next stack variable
            offs = {}
            for om in re.finditer(r'\b(\w*?(?:local|Stack)_?)([0-9a-f]{1,8})\b', b):
                pass
            for sm in re.finditer(r'(?m)^\s*(unsigned char|char|byte|undefined1|undefined2|undefined4|undefined8|uint|int|ushort|short|ulong|long|float|double|longlong|ulonglong|undefined)\s+(\w*(?:local|Stack)_([0-9a-f]+))\s*;', b):
                nm = sm.group(2)
                if re.search(r'(?<![\w.])(?:\(\s*%s\s*\)|%s)\s*\[' % (re.escape(nm), re.escape(nm)), b):
                    o = int(sm.group(3), 16)
                    others = [int(x, 16) for x in re.findall(r'\b\w*(?:local|Stack)_([0-9a-f]+)\b', b) if int(x, 16) < o]
                    gap = (o - max(others)) if others else 64
                    esz = {'char': 1, 'byte': 1, 'undefined1': 1, 'unsigned char': 1, 'undefined': 1, 'short': 2, 'ushort': 2, 'undefined2': 2, 'double': 8, 'longlong': 8, 'ulonglong': 8, 'undefined8': 8}.get(sm.group(1), 4)
                    cnt = max(1, gap // esz)
                    b = re.sub(r'(?m)^(\s*)%s\s+%s\s*;' % (re.escape(sm.group(1)), re.escape(nm)), r'\1%s %s[%d];' % (sm.group(1), nm, cnt), b, count=1)
            b = re.sub(r'\(\s*(?:undefined1|char|byte|undefined|uchar)\s+\[(\d)\]\s*\)', lambda m: '(%s)' % {'1': 'unsigned char', '2': 'unsigned short', '4': 'unsigned int', '8': 'unsigned long long'}.get(m.group(1), 'unsigned int'), b)
            b = re.sub(r'\(&\s*([A-Za-z_]\w*)\s*\)\s*\[', lambda m: '(%s)[' % m.group(1) if (m.group(1) in tables or m.group(1).startswith('switchdataD_')) else m.group(0), b)
            b = re.sub(r'&\s*([A-Za-z_]\w*)\b(?!\s*\))', lambda m: m.group(1) if (m.group(1) in tables and not m.group(1).startswith(('FLOAT_','DOUBLE_'))) else m.group(0), b)
            b = re.sub(r'\b([a-z]{1,2})Ram([0-9a-f]{8})\b', lambda m: '(*(%s *)0x%s)' % ({'u': 'unsigned int', 'i': 'int', 'b': 'unsigned char', 'c': 'char', 's': 'short', 'us': 'unsigned short', 'p': 'unsigned char *', 'd': 'double', 'f': 'float', 'l': 'long long', 'ul': 'unsigned long long'}.get(m.group(1), 'unsigned int'), m.group(2)), b)
            b = re.sub(r'\bregister0x[0-9a-f]{8}\b', '((unsigned int)__builtin_frame_address(0))', b)
            b = re.sub(r'&\s*(?:LAB|DAT|UNK)_([0-9a-f]{8})\b', lambda m: '((unsigned char *)0x%s)' % m.group(1) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\(\s*(?:DAT|UNK)_([0-9a-f]{8})\s*\)\s*\[', lambda m: ('((unsigned char *)0x%s)[' % m.group(1)) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\b\w+_command_([0-9a-f]{8})\b', lambda m: '(*(GhidraMachOCommand *)0x%s)' % m.group(1), b)   # a constant that lands in the Mach-O header area (e.g. 0x1c = first load command), not an object
            b = re.sub(r'\bsection_([0-9a-f]{8})\b', lambda m: '(*(GhidraMachOSection *)0x%s)' % m.group(1), b)
            b = re.sub(r'\(float\)\(\(unsigned char \*\)(0x[0-9a-f]+)\)', r'(float)\1', b)
            b = re.sub(r'\b(?:DAT|UNK)_([0-9a-f]{8})\s*\[', lambda m: ('((unsigned char *)0x%s)[' % m.group(1)) if in_text(m.group(1)) else m.group(0), b)
            b = re.sub(r'\b(?:LAB|DAT|UNK)_([0-9a-f]{8})\b', lambda m: '(*(unsigned char *)0x%s)' % m.group(1) if in_text(m.group(1)) and m.group(0).startswith(('DAT', 'UNK')) else m.group(0), b)
            b = re.sub(r'(?<![\w.>])(%s)\s*\[' % '|'.join(re.escape(n) for n in defined_names) if defined_names else 'x^', lambda m: '((code **)%s)[' % m.group(1), b)
            b, _nfi = fix_float_int(b, int(a, 16))
            b, _nnan = fix_nan(b, int(a, 16))
            b, _nfa = fix_float_args(b)
            # an integer / pointer cast of a float LITERAL is its bit pattern: Ghidra inlines a read-only float constant it read with an integer load
            # (GLDriver FUN_000a9ac0: `local_54 ^ (uint)1.0`, `param_4 == (undefined *)1.0` - the stock compares words with 0x3f800000 loaded by
            # lwz from FLOAT_001aa0e8); PowerPC 32 has no float->int conversion without fctiw, and a real one of a constant would be folded
            b = re.sub(r'\(((?:uint|int|undefined4|ulong|long|[A-Za-z_]\w*(?: \w+)*\s*\*+))\)\s*(-?\d+\.\d+(?:e[-+]?\d+)?)\b(?!\s*[fF])',
                       lambda m: '(%s)0x%08xU' % (m.group(1), struct.unpack('>I', struct.pack('>f', float(m.group(2))))[0]), b)
            # a pointer cast of an element of a float/double cursor (`(undefined4 *)pfVar3[3]`: GLDriver FUN_000ddbcc reads three floats and then a
            # pointer word from one stream) converts the float VALUE; the stock loads the word - reinterpret it
            b = re.sub(r'\(([A-Za-z_]\w*(?:\s*\*)+)\)\s*(p[fd]Var\d+)\[([^\[\]]+)\]', r'(*(\1 *)(\2 + (\3)))', b)
            # Ghidra fits the Mach-O header struct onto a record whose first word it reads (`((mach_header *)(local_a8 + -1))->magic`, GLDriver
            # FUN_000fd5c8; the struct is normalised to a byte type): `magic` is the first 4-byte field - the word at that address
            b = re.sub(r'\(\((?:mach_header|unsigned char)\s*\*\)\s*\(([^()]*(?:\([^()]*\)[^()]*)*)\)\)->magic\b', r'(*(unsigned int *)(\1))', b)
            # ...and the same word used as a float later (`(float)puVar14`, the fourth component of that stream): its bits are the float
            b = re.sub(r'\(float\)\s*(p\w*Var\d+)\b(?!\s*[\[(])', r'(*(float *)&\1)', b)
            # `in_stack_000000XX` (XX >= 0) is the word at entry-sp + XX: the caller's frame (0 = back chain, 0x38+ = argument words 9+ that the
            # signature does not declare - ExtendParams.java covers the called ones). Ghidra declares it as a local, so the C read garbage; read the
            # entry stack pointer's memory instead, as for the `uStack` names below (the unwinder walks frames through in_stack_00000000).
            for ist_ in list(re.finditer(r'(?m)^[ \t]*([A-Za-z_][\w ]*?[\s*]+)(in_stack_([0-7][0-9a-f]{7}))\s*;\n', b)):
                b = b.replace(ist_.group(0), '', 1)
                b = re.sub(r'\b%s\b' % ist_.group(2), '(*(%s *)(*(unsigned int *)__builtin_frame_address(0) + 0x%s))' % (ist_.group(1).strip(), ist_.group(3).lstrip('0') or '0'), b)
            declared_ = set(re.findall(r'(?m)^\s*[A-Za-z_][\w ]*?[\s*]+(\w+)\s*(?:\[[^\]]*\])?\s*;', b))
            b = re.sub(r'\b_?([a-z]{1,2})Stack([0-9a-f]{8})\b', lambda m: m.group(0) if m.group(0) in declared_ else '(*(%s *)(*(unsigned int *)__builtin_frame_address(0) + 0x%s))' % ({'b': 'unsigned char', 'c': 'char', 'u': 'unsigned int', 'i': 'int', 's': 'short', 'us': 'unsigned short', 'p': 'unsigned char *', 'd': 'double', 'f': 'float', 'l': 'long long'}.get(m.group(1), 'unsigned int'), m.group(2).lstrip('0') or '0'), b)
            b = re.sub(r'\bstack0x([0-9a-f]{8})\b', lambda m: m.group(0) if m.group(0) in declared_ else 'STACKARG(0x%s)' % m.group(1).lstrip('0').rjust(1, '0'), b)
            b = re.sub(r'\((STACKARG\(0x[0-9a-f]+\))\)\s*\[', r'((unsigned int *)\1)[', b)
            b, _nhs = fix_home_slots(b, name)
            b = re.sub(r'\b([A-Za-z_]\w*(?:\[[^\]]*\])?(?:\.[A-Za-z_]\w*)*)\._(\d+)_(\d+)_', lambda m: '(*(%s *)((unsigned char *)&(%s) + %s))' % ({'1': 'unsigned char', '2': 'unsigned short', '4': 'unsigned int', '8': 'unsigned long long'}.get(m.group(3), 'unsigned int'), m.group(1), m.group(2)), b)
            k_ = b.index('{'); head_, rest_ = b[:k_], b[k_:]
            for nm in ([] if (os.environ.get('NOCAST') and not os.environ.get('CASTEXACT')) else exact_fns):
                if nm in rest_: rest_ = sub_outside_strings(r'(?<![\w.>])%s\s*\(' % re.escape(nm), '((%s (*)())%s)(' % (proto[exact_fns[nm]][0], nm), rest_)
            for nm in ([] if os.environ.get('NOCAST') else samepart):
                if nm in rest_: rest_ = sub_outside_strings(r'(?<![\w.>])%s\s*\(' % re.escape(nm), '((int (*)())%s)(' % nm, rest_)
            b = head_ + rest_
            conv = fix_arrays(fix_types(b))
            for cn_ in set(re.findall(r'(?m)^\s*code (\w+);', conv)):           # a scalar `code` local (a byte Ghidra typed as code) that is never called
                if not re.search(r'\b%s\(|\(\*%s\)' % (cn_, cn_), conv):
                    conv = re.sub(r'(?m)^(\s*)code %s;' % cn_, r'\1unsigned char %s;' % cn_, conv)
            for cn_ in set(re.findall(r'(?m)^\s*code \*(\w+);', conv)):        # a `code *` local that is indexed and never called is a byte pointer
                if re.search(r'\b%s\[' % cn_, conv) and not re.search(r'\(\*?%s\)\(|\b%s\(' % (cn_, cn_), conv):
                    conv = re.sub(r'(?m)^(\s*)code \*%s;' % cn_, r'\1unsigned char *%s;' % cn_, conv)
            conv = re.sub(r'\bcase \(\s*[\w ]+\*+\s*\)\s*(0x[0-9a-fA-F]+|\d+)\s*:', r'case \1:', conv)   # a pointer-typed switch: its case values are plain integers
            conv = re.sub(r'switch\((\w+)\)', lambda m: 'switch((int)%s)' % m.group(1) if re.search(r'(?m)^\s*[\w ]+\*+\s*%s\s*;' % m.group(1), conv) else m.group(0), conv)   # a pointer-typed switch variable
            conv = re.sub(r'(?m)^(\s*[A-Za-z_]\w*:)(\s*\n\s*\})', r'\1 ;\2', conv)   # a label needs a statement: `code_r0x...:` directly before `}` when the target is the function's end
            if name in PATCHES:
                _sc = getattr(PATCHES[name], 'scope', None)
                if _sc is None or _sc == CORPUS_SCOPE:
                    try: conv = PATCHES[name](b, conv); _applied.add(name)
                    except _PatchError as _e:
                        if os.environ.get('PATCH_DIAG'): print('PATCH-FAIL', name, _e)   # diagnostic: list every patch that no longer applies, keep going
                        else: sys.exit('patches.py: %s: %s' % (name, _e))
                elif not CORPUS_SCOPE: sys.exit('patches.py: %s has a scoped patch (%s) but CORPUS_SCOPE is not set (build_corpus.py / verify_corpus.sh set it)' % (name, _sc))
            f.write(conv + '\n')
            if os.environ.get('SINGLE'):
                os.makedirs(os.path.join(out, 'single'), exist_ok=True)
                open(os.path.join(out, 'single', (name if len(name) < 100 else name[:80] + '_' + a[2:]) + '.c'), 'w').write('#include "../decls.h"\n\n' + conv + '\n')
            led.append((a, sz, name, pn, NOTES.get(name, 'converted')))
with open(os.path.join(out, 'ledger.tsv'), 'w') as f:
    for r in led: f.write('\t'.join(map(str, r)) + '\n')
if externals:
    with open(os.path.join(out, 'externals.tsv'), 'w') as f:
        for a_, n_ in externals: f.write('%s\t%s\texternal (dyld import placeholder, no code in this binary)\n' % (a_, n_))
_unused = sorted(k for k, v in PATCHES.items() if getattr(v, 'scope', None) == CORPUS_SCOPE and k not in _applied)
if _unused and not os.environ.get('SINGLE'): print('patches.py: %d patch(es) of scope %s not applied (function absent from this dump or renamed): %s' % (len(_unused), CORPUS_SCOPE, ', '.join(_unused)))
print(len(funcs), 'functions,', len(imports), 'imports,', len(data_syms), 'data symbols,', (len(funcs) + part - 1) // part, 'parts')
