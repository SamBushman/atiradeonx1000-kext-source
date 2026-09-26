#!/usr/bin/env python3
"""fnfuzz_gen.py KEY STOCK_DIS DUMP_DIR LINK_TREE STOCK_NM REBUILT_NM OUT.tsv  - candidate ledger for the pure-function differential (issue #68, criterion 1).

A function is a candidate when its stock code has no indirect call, no system call, no special-register or atomic / cache instruction and calls no import
outside a small whitelist (memcpy/memset/str*/libm): it can then be called with arbitrary arguments in a scratch process, stock and rebuilt, and the results
compared. One row per candidate: id, C name, stock address, rebuilt file offset (from nm, via the C name's asm label in decls.h), size, parameter classes
(p pointer, i integer or unknown word, n definite integer, f float, d double, L 64-bit integer; from the dump's signature) and the return class (i, d, v).

STOCK_DIS must cover EVERY code section: `otool -tv` (__text) plus `otool -s __TEXT __textcoal_nt -v`. GLDriver keeps 764 functions (42 KB, the vertex-program emulator's
built-ins among them) in __textcoal_nt; a __text-only disassembly made them look like candidates with no forbidden instruction, and left the same functions out of
every other stock-code audit (indirect_args, inreg_liveness, ...)."""
import sys, re, os
key, dis, dump, link, snm, rnm, out = sys.argv[1:8]
WL = set('memcpy memset bcopy memmove memcmp strlen strcmp strncmp strcpy strncpy strcat strchr strrchr bzero sqrt sqrtf pow powf exp exp2 log log2 log10 sin cos tan atan atan2 asin acos floor ceil fabs fmod modf frexp ldexp abs labs'.split())
seq = []; lab = {}; cur = None
for l in open(dis, errors='replace'):
    l = l.rstrip('\n'); m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l)
    if m: seq.append((int(m.group(1), 16), m.group(2), m.group(3)))
idx = {a: i for i, (a, _, _) in enumerate(seq)}
fns = {}
for l in open(os.path.join(dump, 'RANGES.tsv')):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3 and f[0].startswith('0x') and f[2] == 'fn': fns[int(f[0], 16)] = (f[1], [tuple(int(x, 16) for x in r.split('-')) for r in f[3].split(';') if r])
asm = {}
for l in open(os.path.join(link, 'decls.h')):
    m = re.match(r'extern (?:[\w \*]+?) (\w+)\(.*?\)(?: asm\("([^"]+)"\))?;', l)
    if m and m.group(2): asm[m.group(1)] = m.group(2)
def nm_table(path):
    t = {}
    for l in open(path):
        p = l.split()
        if len(p) == 3 and p[1] in 'TtSsDdbB': t.setdefault(p[2], int(p[0], 16))
        elif len(p) == 3 and p[1] in 'Ttx': pass
    return t
S = {}
for l in open(snm):
    p = l.split()
    if len(p) == 3 and p[1] == 'T': S[p[2]] = int(p[0], 16)
R = nm_table(rnm)
anchor = next((n for n in S if n in R and n.lstrip('_') and not n.startswith('__Z') and n not in ('__mh_execute_header', '_main')), None)
if anchor is None: anchor = next((n for n in S if n in R), None)
# parameter types as the decompile typed them (the K&R declarations of the linked corpus): `int param_1` = Ghidra saw arithmetic on it, `int *param_1` = a pointer,
# `undefined4 param_1` = a word of unknown use
CTYPES = {}
import glob
for _pf in sorted(glob.glob(os.path.join(link, 'part_*.c'))):
    _t = open(_pf).read()
    for _m in re.finditer(r'(?m)^/\* (\S+) @ \S+ \(\d+ bytes\) \*/\n[^\n(]*?\b\w+\(([^)]*)\)((?:\n  [^\n]*;)*)', _t):
        _names = [x.strip() for x in _m.group(2).split(',') if x.strip() and x.strip() != 'void']
        _decl = {}
        for _d in _m.group(3).split('\n'):
            _d = _d.strip().rstrip(';')
            _mm = re.match(r'(.*?[\s*])(\w+)$', _d)
            if _mm: _decl[_mm.group(2)] = _mm.group(1).strip()
        if _names and all(n in _decl for n in _names): CTYPES[_m.group(1)] = [_decl[n] for n in _names]
def sig_of(entry):
    p = os.path.join(dump, '0x%x.txt' % entry)
    if not os.path.exists(p): return None
    with open(p, errors='replace') as fh: fh.readline(); s = fh.readline()
    m = re.match(r'// Signature: (.*?)\s*__(?:stdcall|cdecl|thiscall)\s*(\S+)\((.*)\)\s*$', s) or re.match(r'// Signature: (.*?)\s+(\S+)\((.*)\)\s*$', s)
    if not m: return None
    ret, params = m.group(1), m.group(3)
    ps = [x.strip() for x in params.split(',') if x.strip() and x.strip() != 'void']
    if any('...' in x for x in ps): return None
    def cls(x):
        if '*' in x: return 'p'
        if re.match(r'^(double)\b', x): return 'd'
        if re.match(r'^float\b', x): return 'f'
        if re.match(r'^(longlong|ulonglong|undefined8)\b', x): return 'L'
        if re.match(r'^(u?int|u?short|u?char|byte|bool|u?long|ushort|size_t)\b', x): return 'n'    # a definite integer (Ghidra saw arithmetic on it): never handed a pointer
        return 'i'
    rc = 'd' if re.match(r'^(double|float)', ret.strip()) else ('v' if ret.strip() in ('void', 'undefined') else 'i')   # `undefined`: Ghidra saw no use of a result (r3 is whatever the function leaves there)
    pc = ''.join(cls(x) for x in ps)
    slots = sum(2 if c in 'dL' else 1 for c in pc)
    if slots > 8: return None     # parameters beyond r10 travel on the caller's stack; the harness only sets registers
    return pc, rc
# functions whose result some stock caller reads (r3 read right after the `bl`, before being overwritten): their return value is real
def _reads(arg, r):
    ops = [x.strip() for x in arg.split(';')[0].split(',')]
    return any(re.search(r'(^|[(\s])%s($|[),])' % r, o) for o in ops[1:])
RETUSED = set()
labs = {}
for a_, l in [(a, None) for a in idx]: pass
for i, (a, op, arg) in enumerate(seq):
    if op in ('bl', 'bl+', 'bl-'):
        t = arg.split()[0]
        if not t.startswith('0x'): continue
        ta = int(t, 16)
        for j in range(i + 1, min(i + 10, len(seq))):
            a2, op2, arg2 = seq[j]
            ops2 = [x.strip() for x in arg2.split(';')[0].split(',')]
            if _reads(arg2, 'r3') or (op2.startswith(('st', 'cmp')) and ops2 and ops2[0] == 'r3'):
                RETUSED.add(ta); break
            if op2 in ('bl', 'bctrl', 'blr', 'b') or (ops2 and ops2[0] == 'r3' and not op2.startswith(('st', 'cmp', 'b'))): break
# functions the decompile reads implicit inputs in (`in_r11`/`in_r12`: registers the caller sets outside the ABI's argument registers): not callable in isolation
IMPLICIT = set()
for _pf in sorted(glob.glob(os.path.join(link, 'part_*.c'))):
    for _f in re.split(r'(?m)^(?=/\* \S+ @ \S+ \(\d+ bytes\) \*/)', open(_pf).read()):
        _m = re.match(r'/\* (\S+) @', _f)
        if _m and re.search(r'\bin_r(0|2|11|12)\b', _f): IMPLICIT.add(_m.group(1))
rows = []
for ent, (nm, rs) in sorted(fns.items()):
    if nm in IMPLICIT: continue
    bad = None; size = 0
    for lo, hi in rs:
        size += hi - lo
        for a in range(lo, hi, 4):
            if a not in idx: continue
            op, arg = seq[idx[a]][1:]
            if op in ('bctrl', 'blrl', 'sc'): bad = op
            elif op == 'mtspr' and 'lr' not in arg and 'ctr' not in arg: bad = 'spr'
            elif op == 'mfspr' and not re.search(r'\b(lr|ctr|xer)\b', arg): bad = 'spr'
            elif re.search(r'\b0xff[0-9a-f]{2}\(r1\)', arg) and op in ('lwz', 'lhz', 'lbz', 'lfs', 'lfd', 'lha'): bad = 'redzone'   # a load below the stack pointer: a fragment of a caller's frame (prologue saves are stores)
            elif op in ('sync', 'eieio', 'isync', 'lwarx', 'stwcx.', 'dcbz', 'dcbf', 'icbi', 'dcbst'): bad = op
            elif op in ('bl', 'bl+', 'bl-'):
                mm = re.search(r'symbol stub for: (\S+)', arg)
                if mm and mm.group(1).lstrip('_') not in WL: bad = 'import'
        if bad: break
    first = seq[idx[ent]][1:] if ent in idx else ('', '')
    if first[0] in ('stfd', 'lfd') and re.match(r'f(1[4-9]|2\d|3[01])\b', first[1]): continue      # saveFP / restFP millicode entry points (a register-save chain, not a function)
    if key == 'glprog' and ent in (0x97b89f04, 0x97b88a90): continue                                # clipped fragments patched in patches.py (they read the parent's registers)
    if bad or size < 16 or re.match(r'^(eh_|__Unwind|orph_|save_world|rest_world|dyld_stub|_glp?Unwind|_*(lshr|ashl|ashr|mul|div|mod|udiv|umod|cmp|ucmp|fix|float|neg|ffs|clz|ctz|popcount|parity)[a-z]*[ds]i[0-9]?$)', nm): continue
    sg = sig_of(ent)
    if sg is None: continue
    ct = CTYPES.get(nm)
    if ct and len(ct) == len(sg[0]):     # the decompile's own types refine the header's class letters
        sg = (''.join(('p' if '*' in t else 'n' if re.match(r'^(u?int|u?short|u?char|byte|bool|u?long)$', t) and c == 'i' else c) for t, c in zip(ct, sg[0])), sg[1])
    sym = asm.get(nm) or ('_' + nm if not nm.startswith('FUN_') and not nm.startswith('_') else nm)
    roff = R.get(sym) if sym in R else (R.get('_' + nm) if ('_' + nm) in R else R.get(nm))
    if roff is None: continue
    rc = sg[1]
    if rc == 'v' and ent in RETUSED: rc = 'i'
    rows.append((ent, nm, size, roff, sg[0], rc))
with open(out, 'w') as f:
    f.write('#anchor\t%s\t%x\t%x\n' % (anchor, S[anchor], R[anchor]))
    for i, (ent, nm, size, roff, pc, rc) in enumerate(rows):
        f.write('%d\t%s\t%x\t%x\t%d\t%s\t%s\n' % (i, nm, ent, roff, size, pc or '-', rc))
print('%s: %d candidates, anchor %s' % (key, len(rows), anchor))
