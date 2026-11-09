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
# FNFUZZ_CTX=1: the ledger for tests/userspace/ctxfuzz.c (hand-built context) instead of the pure-function one. It keeps exactly the functions the plain ledger leaves out
# because they call through a pointer (`bctrl`) or import something outside the whitelist, minus those that can reach an import that is not safe to run on garbage arguments (UNSAFE),
# and adds a column per function: the indirect-call slots `param:off[:off...]` (each a code pointer the stock loads from `*(param+off)` or deeper and jumps to) that the harness
# fills with recording stubs.
CTX = bool(os.environ.get('FNFUZZ_CTX'))
# FNFUZZ_RZ_STORED=1: a load from the red zone (`lwz r9,0xfff4(r1)`) is the function's own when an earlier instruction of the SAME function stored to that slot (`stfd f0,0xfff0(r1)`: the
# float->int move of a leaf function; GLEngine has 715 of them), and only a load of a slot nothing stored is a fragment of a caller's frame
RZ_STORED = bool(os.environ.get('FNFUZZ_RZ_STORED'))
UNSAFE = re.compile(r'^_?(NS[A-Z]|IO[A-Z]|exit$|scandir$|mach_|host_info$|sysctl$|PP[A-Z]|Sh[A-Z]|glp|pthread_(?!mutex)|fork|exec|kill|abort$|system$|open$|write$|read$|unlink$)')
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
# the function names of the CORPUS, by stock address: the dump (and the Sept ledgers) name functions FUN_<addr>, the renamed corpus has real names, and CTYPES / IMPLICIT / the asm labels
# are all keyed by the corpus name (without this, a renamed corpus left GA 29 and VA 3 candidates of 33 and 11)
BYADDR = {}
for _pf in sorted(glob.glob(os.path.join(link, 'part_*.c'))) + sorted(glob.glob(os.path.join(link, 'x_*_part_*.c'))):
    for _m in re.finditer(r'(?m)^/\* (\S+) @ 0x([0-9a-f]+) \(\d+ bytes\) \*/', open(_pf).read()):
        BYADDR.setdefault(int(_m.group(2), 16), _m.group(1))
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
        # scan on until r3 is read (the result is used), redefined, or the straight-line code ends in a call / return / jump. The cap used to be 10 instructions: the caller
        # of VA's ava_reserve_list_words (stock 0x83e0) reads the returned write pointer 34 instructions after the call, so the function was classed `v`, its r3 was never
        # compared, and the rebuilt body that returned nothing passed fnfuzz (#233).
        for j in range(i + 1, min(i + 400, len(seq))):
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
# FNFUZZ_ALLOW=dcbz,lwarx,... lets functions containing those (otherwise excluded) instructions in; FNFUZZ_ONLY_ALLOWED=1 then keeps ONLY the functions that do contain one:
# the ledger of the hardware-flavoured functions (cache ops, atomics, barriers) for a single-threaded differential (issue #69)
ALLOW = set(x for x in os.environ.get('FNFUZZ_ALLOW', '').split(',') if x); ONLY_ALLOWED = bool(os.environ.get('FNFUZZ_ONLY_ALLOWED'))
FN_INFO = {}
WHY = []
def scan(ent, rs):
    bad = None; badc = None; size = 0; used_allowed = False; imps = set(); callees = set(); ctxops = []; rzs = set()
    for lo, hi in rs:
        size += hi - lo
        for a in range(lo, hi, 4):
            if a not in idx: continue
            op, arg = seq[idx[a]][1:]
            if CTX: ctxops.append((op, arg))
            if RZ_STORED and op.startswith('st'):
                mz = re.search(r'\b(0x[0-9a-f]+)\(r1\)', arg)
                if mz:
                    o_ = int(mz.group(1), 16); n_ = 1
                    if op.startswith('stfd'): n_ = 2
                    elif op == 'stmw': n_ = 32 - int(re.match(r'r(\d+)', arg).group(1))
                    for k_ in range(n_): rzs.add(o_ + 4 * k_)
            if op in ('bctrl', 'blrl', 'sc'):
                if not bad: bad = op
                if op != 'bctrl' and not badc: badc = op
            elif op == 'mtspr' and 'lr' not in arg and 'ctr' not in arg: bad = bad or 'spr'; badc = badc or 'spr'
            elif op == 'mfspr' and not re.search(r'\b(lr|ctr|xer)\b', arg): bad = bad or 'spr'; badc = badc or 'spr'
            elif re.search(r'\b0xff[0-9a-f]{2}\(r1\)', arg) and op in ('lwz', 'lhz', 'lbz', 'lfs', 'lfd', 'lha') and not (RZ_STORED and int(re.search(r'(0x[0-9a-f]+)\(r1\)', arg).group(1), 16) & ~3 in rzs): bad = bad or 'redzone'; badc = badc or 'redzone'   # a load below the stack pointer: a fragment of a caller's frame (prologue saves are stores)
            elif op in ('sync', 'eieio', 'isync', 'lwarx', 'stwcx.', 'dcbz', 'dcbf', 'icbi', 'dcbst'):
                if op in ALLOW: used_allowed = True
                else: bad = bad or op; badc = badc or op
            elif op in ('bl', 'bl+', 'bl-', 'b'):
                mm = re.search(r'symbol stub for: (\S+)', arg)
                if mm:
                    imps.add(mm.group(1))
                    if op != 'b' and mm.group(1).lstrip('_') not in WL: bad = bad or 'import'     # (a tail `b` to a stub only counts for the hand-built-context ledger)
                    if UNSAFE.match(mm.group(1)): badc = badc or 'unsafe:' + mm.group(1)
                else:
                    t_ = arg.split()[0] if arg.split() else ''
                    if t_.startswith('0x') and int(t_, 16) in fns and not any(l_ <= int(t_, 16) < h_ for l_, h_ in rs): callees.add(int(t_, 16))
        if bad and not CTX: break
    return bad, badc, callees, size, ctxops, used_allowed
UNS = set()
if CTX:
    for _e, (_nm, _rs) in fns.items():
        _b, _bc, _cal, _sz, _ops, _ua = scan(_e, _rs); FN_INFO[_e] = (_b, _bc, _cal)
    UNS = {e for e, v in FN_INFO.items() if v[1] and v[1].startswith('unsafe:')}
    ch = True
    while ch:                      # an unsafe import reached through direct calls makes the caller unsafe too
        ch = False
        for e, v in FN_INFO.items():
            if e not in UNS and any(c in UNS for c in v[2]): UNS.add(e); ch = True
def ind_chains(ops):
    """the code pointers a function jumps through (`lwz rX,OFF(rB); ...; mtctr rX`) as chains from an incoming parameter: (param index, (off1, off2, ...)): rB is a parameter
    (r3..r10, or a register copied from one) for off1, and the result of the previous load for the deeper ones. Straight-line over the address order, all paths merged."""
    st = {'r%d' % r: (r - 3, ()) for r in range(3, 11)}; out = []; recent = []     # recent: (instruction index, destination register, chain) of every load from a tracked pointer
    VOL = ['r0'] + ['r%d' % i for i in range(3, 13)]
    for ix, (op, arg) in enumerate(ops):
        o = [x.strip() for x in arg.split(';')[0].split(',')]
        if op in ('lwz', 'lwzu') and len(o) == 2:
            mm = re.match(r'(0x[0-9a-f]+|\d+)\((r\d+)\)$', o[1])
            if mm:
                off, rb = int(mm.group(1), 0), mm.group(2)
                src = st.get(rb)
                if op == 'lwzu': st.pop(rb, None)
                if src and off < 0x8000 and len(src[1]) < 3: st[o[0]] = (src[0], src[1] + (off,)); recent.append((ix, o[0], st[o[0]]))
                else: st.pop(o[0], None)
                continue
        if op == 'or' and len(o) == 3 and o[1] == o[2]:
            if o[1] in st: st[o[0]] = st[o[1]]
            else: st.pop(o[0], None)
            continue
        if op == 'mtspr' and o[0] == 'ctr' and len(o) == 2:
            for c in [st.get(o[1])] + [ch for k, r, ch in recent if r == o[1] and ix - k <= 16]:      # a conditional load picks one of several slots: all loads of that register just before
                if c and c[1] and c not in out: out.append(c)
            continue
        if op in ('bl', 'bl+', 'bl-', 'bctrl', 'blrl'):
            for r in VOL: st.pop(r, None)
            continue
        if re.match(r'^(st|cmp|b|mt|tw|dcb|sync|isync|eieio|nop|icbi|cr)', op) and not op.startswith('stwu') and not op.startswith('stbu'): continue
        if o and re.match(r'^r\d+$', o[0]): st.pop(o[0], None)
        if op in ('stwu', 'stbu', 'sthu', 'lbzu', 'lhzu') and len(o) == 2:
            mm = re.search(r'\((r\d+)\)', o[1])
            if mm: st.pop(mm.group(1), None)
    return out
rows = []
for ent, (nm, rs) in sorted(fns.items()):
    nm = BYADDR.get(ent, nm)
    if nm in IMPLICIT:
        WHY.append((ent, nm, 'implicit-register-input')); continue
    bad, badc, callees, size, ctxops, used_allowed = scan(ent, rs)
    if CTX:
        if not ((bad or ind_chains(ctxops)) and not badc and ent not in UNS):
            WHY.append((ent, nm, 'unsafe-import-reachable' if (badc or ent in UNS) else 'plain-candidate')); continue         # what the plain ledger cannot run (indirect calls, imports): unless it can reach an unsafe import, that is left for the live test
        bad = None
    first = seq[idx[ent]][1:] if ent in idx else ('', '')
    if first[0] in ('stfd', 'lfd') and re.match(r'f(1[4-9]|2\d|3[01])\b', first[1]): continue      # saveFP / restFP millicode entry points (a register-save chain, not a function)
    if re.search(r'_frag_[0-9a-f]+$', nm): continue                                              # `_frag_` = a clipped piece of a function (a switch case body that reads the parent's registers), not a function
    if key == 'glprog' and ent in (0x97b89f04, 0x97b88a90): continue                                # clipped fragments patched in patches.py (they read the parent's registers)
    if bad or size < 16 or re.match(r'^(eh_|__Unwind|orph_|save_world|rest_world|dyld_stub|_glp?Unwind|_*(lshr|ashl|ashr|mul|div|mod|udiv|umod|cmp|ucmp|fix|float|neg|ffs|clz|ctz|popcount|parity)[a-z]*[ds]i[0-9]?$)', nm): continue
    if ONLY_ALLOWED and not used_allowed: continue
    sg = sig_of(ent)
    if sg is None:
        WHY.append((ent, nm, 'no-signature (variadic / >8 arg slots / none)')); continue
    ct = CTYPES.get(nm)
    if ct and len(ct) == len(sg[0]):     # the decompile's own types refine the header's class letters
        sg = (''.join(('p' if '*' in t else 'n' if re.match(r'^(u?int|u?short|u?char|byte|bool|u?long)$', t) and c == 'i' else c) for t, c in zip(ct, sg[0])), sg[1])
    sym = asm.get(nm) or ('_' + nm if not nm.startswith('FUN_') and not nm.startswith('_') else nm)
    roff = R.get(sym) if sym in R else (R.get('_' + nm) if ('_' + nm) in R else R.get(nm))
    if roff is None:
        WHY.append((ent, nm, 'no-rebuilt-symbol')); continue
    rc = sg[1]
    if rc == 'v' and ent in RETUSED: rc = 'i'
    rows.append((ent, nm, size, roff, sg[0], rc, ind_chains(ctxops) if CTX else None))
with open(out, 'w') as f:
    f.write('#anchor\t%s\t%x\t%x\n' % (anchor, S[anchor], R[anchor]))
    for i, (ent, nm, size, roff, pc, rc, ind) in enumerate(rows):
        f.write('%d\t%s\t%x\t%x\t%d\t%s\t%s' % (i, nm, ent, roff, size, pc or '-', rc))
        if CTX: f.write('\t' + (','.join('%d:' % p_ + ':'.join('%x' % o_ for o_ in offs_) for p_, offs_ in ind[:24]) or '-'))
        f.write('\n')
print('%s: %d candidates, anchor %s' % (key, len(rows), anchor))
if CTX:
    with open(out + '.why', 'w') as f:
        for e_, n_, w_ in WHY: f.write('%x\t%s\t%s\n' % (e_, n_, w_))
