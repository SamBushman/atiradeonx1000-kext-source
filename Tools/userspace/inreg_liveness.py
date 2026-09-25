#!/usr/bin/env python3
"""inreg_liveness.py STOCK_DIS RANGES_TSV DUMP_DIR  - for every function whose decompile reads an argument register it does not declare
(`in_r3`..`in_r10`), decide from the stock machine code whether the register really carries a value into the function (backward liveness over
the function's RANGES, jump tables followed):
  USED  the body itself reads the entry value (compare, arithmetic, address, store, return value): a missing parameter - the C reads garbage
  RET   the entry value is only read by the return (`blr` with r3/r4 untouched on some path): a return-value question (ret_used.py), not a parameter
  PASS  the entry value only reaches a call / tail call as an argument register: whether it matters depends on the callee
  DEAD  the entry value is never read: Ghidra's `in_rN` stands for something else (a clobbered register after a call it modelled differently)
For PASS the callees the value reaches are checked the same way (3 levels): PASS-yes = some callee reads it (the stock passes the caller's value on,
the C passes an uninitialised local), PASS-no = none does (harmless), PASS-vararg = it only reaches a variadic callee's `...` slots,
PASS-indirect / PASS-import = it reaches a call through a pointer / an import of unknown arity, PASS-deep = more than 3 levels.
Prints one row per (function, register): entry, name, register, class, first reading instruction."""
import sys, re, glob, bisect
dis, rng_f, dump = sys.argv[1:4]
ins = {}; label = {}; _pl = None
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m:
        ins[int(m.group(1), 16)] = (m.group(2), m.group(3))
        if _pl: label.setdefault(_pl, int(m.group(1), 16)); _pl = None
    elif l.rstrip().endswith(':') and not l.startswith(('\t', '(')): _pl = l.rstrip()[:-1]
rows = {}
for l in open(rng_f):
    p = l.rstrip('\n').split('\t')
    if len(p) > 3 and p[0].startswith('0x') and p[2] == 'fn':
        rows[int(p[0], 16)] = [tuple(int(x, 16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r]
ENTRIES = set(rows)
GPR = re.compile(r'\br(\d{1,2})\b')
ARGS = set(range(3, 11))
STORE = re.compile(r'^(st[bhw]|stmw|stfd|stfs|stfiwx|stvx|stwcx|sthbrx|stwbrx|dcb|icbi)')
NODEF = ('cmpw', 'cmpwi', 'cmplw', 'cmplwi', 'mtspr', 'mtctr', 'mtlr', 'mtcrf', 'mtocrf', 'tw', 'twi', 'sync', 'isync', 'eieio', 'mtxer')
CALL_CLOBBER = {0} | set(range(3, 13))
def regs(s): return [int(x) for x in GPR.findall(s.split(';')[0])]
def du(a):
    """(defs, real uses, call uses, successors-kind) of the instruction at a"""
    op, arg = ins[a]; r = regs(arg)
    if op in ('bl', 'bl+', 'bl-', 'bctrl', 'blrl'):
        return CALL_CLOBBER, set(), set(ARGS), 'call'
    if op in ('blr',) or op.startswith('blr'):
        return set(), set(), {3, 4} | {'ret'}, 'ret' if op == 'blr' else 'cond'   # 'ret' marks the uses as the return's
    if op == 'b':
        return set(), set(), set(), 'jump'
    if op == 'bctr':
        return set(), set(), set(), 'bctr'
    if op.startswith('b'):
        return set(), set(), set(), 'cond'
    if op == 'lmw': return set(range(r[0], 32)), {r[1]} if len(r) > 1 else set(), set(), 'seq'
    if op == 'stmw': return set(), set(range(r[0], 32)) | ({r[1]} if len(r) > 1 else set()), set(), 'seq'
    if STORE.match(op) or op in NODEF:
        d = {r[-1]} if op.endswith('u') or op.endswith('ux') else set()   # stwu r1,-x(r1): the base is updated
        if op in ('stwcx.',): d = set()
        return d, set(r), set(), 'seq'
    if not r: return set(), set(), set(), 'seq'
    d = {r[0]}; u = set(r[1:])
    if op.startswith('rlwimi') or op.startswith('rldimi'): u.add(r[0])          # insert: the old value is read
    if op in ('addi', 'addis', 'li', 'lis') and len(r) > 1 and r[1] == 0: u.discard(0)   # (rA|0)
    if (op.startswith('l') and '(' in arg) and op.endswith(('u', 'ux')): d.add(r[-1])
    if op.startswith(('lf', 'stf', 'fm', 'fa', 'fs', 'fd', 'fn', 'fc', 'fr', 'fabs', 'fneg', 'fsel', 'mffs', 'mtfs')):   # FPR destinations: only GPR bases matter
        d = set(); u = set(regs(arg.split('(')[1])) if '(' in arg else set()
        if op.startswith('lf') and op.endswith(('u', 'ux')): d = u.copy()
    if op in ('or', 'or.') and len(r) == 3 and r[1] == r[2]: u = {r[1]}
    if op in ('xor', 'subf', 'subf.') and len(r) == 3 and r[1] == r[2]: u = set()   # xor rX,rY,rY / subf rX,rY,rY = 0
    return d, u, set(), 'seq'
def table_targets(a):
    """the targets of the embedded table after the bctr at a (words read from the disassembly's .long lines), [] if none"""
    base = a + 4; out = []; k = 0
    while ins.get(base + 4 * k, ('',))[0] == '.long':
        out.append((base + int(ins[base + 4 * k][1], 16)) & 0xffffffff); k += 1
    return out
def classify(ent):
    iv = rows.get(ent) or []
    owned = lambda a: any(lo <= a < hi for lo, hi in iv)
    addrs = sorted(a for lo, hi in iv for a in range(lo, hi, 4) if a in ins and ins[a][0] != '.long')
    info = {a: du(a) for a in addrs}
    succ = {}
    for a in addrs:
        d, u, cu, k = info[a]; op, arg = ins[a]; s = []
        tgt = re.search(r'0x([0-9a-f]+)\s*(?:;|$)', arg); t = int(tgt.group(1), 16) if tgt else None
        if k in ('seq', 'call'): s = [a + 4]
        elif k == 'cond': s = [a + 4] + ([t] if t is not None else [])
        elif k == 'jump':
            if t is not None and owned(t) and t not in ENTRIES - {ent}: s = [t]
            else: info[a] = (d, u, set(ARGS), k)   # a tail call: argument registers go to the callee
        elif k == 'bctr':
            tt = [x for x in table_targets(a) if owned(x)]
            if tt: s = tt
            else: info[a] = (d, u, set(ARGS), k)   # a tail call through ctr
        succ[a] = [x for x in s if x in info]
    live = {k_: {a: set() for a in addrs} for k_ in ('real', 'ret', 'all')}
    changed = True
    while changed:
        changed = False
        for a in reversed(addrs):
            d, u, cu, k = info[a]
            isret = 'ret' in cu; cu_ = cu - {'ret'}
            for k_, use in (('real', u), ('ret', u | (cu_ if isret else set())), ('all', u | cu_)):
                out = set().union(*(live[k_][x] for x in succ[a])) if succ[a] else set()
                n = use | (out - d)
                if n != live[k_][a]: live[k_][a] = n; changed = True
    return live['real'].get(ent, set()), live['ret'].get(ent, set()), live['all'].get(ent, set()), info, succ
def first_reader(ent, reg, info, succ, real):
    seen = set(); todo = [ent]
    while todo:
        a = todo.pop(0)
        if a in seen or a not in info: continue
        seen.add(a); d, u, cu, k = info[a]
        if reg in u or (not real and reg in cu): return a
        if reg in d: continue
        todo.extend(succ[a])
    return None
_cache = {}
IMPORTS = {}
# argument words of the imports the forwarded registers reach (the C prototypes; `operator new(unsigned long)` = __Znwm)
ARITY = {'_memset': 3, '_memcpy': 3, '_memmove': 3, '_memcmp': 3, '_malloc': 1, '_calloc': 2, '_realloc': 2, '_free': 1, '_strlen': 1,
         '_strcat': 2, '_strcpy': 2, '_strncpy': 3, '_strcmp': 2, '_strncmp': 3, '_getpid': 0, '_pthread_mutex_lock': 1, '_pthread_mutex_unlock': 1,
         '__Znwm': 1, '__Znam': 1, '__ZdlPv': 1, '__ZdaPv': 1, '_abort': 0, '_bzero': 2}
def cls(ent):
    if ent not in _cache: _cache[ent] = classify(ent) if ent in rows else None
    return _cache[ent]
def sites(ent, reg, info, succ):
    """the call / tail-call instructions the entry value of reg reaches (reg not redefined on the way)"""
    seen = set(); todo = [ent]; out = []
    while todo:
        a = todo.pop()
        if a in seen or a not in info: continue
        seen.add(a); d, u, cu, k = info[a]
        if reg in cu and 'ret' not in cu: out.append(a)
        if reg in d: continue
        todo.extend(succ[a])
    return out
VARIADIC = None
def callee_reads(t, reg, depth):
    """does the function at t read reg's entry value: 'yes' (itself), 'no', 'vararg' (a variadic function: va_start spills every argument
    register, a format decides what is read - the stock caller forwarded the same kind of unset register), or why it is unknown"""
    global VARIADIC
    if VARIADIC is None: VARIADIC = {a for n, a in label.items() if re.match(r'^__Z.*z$', n)}   # mangled `...`
    if t in VARIADIC: return 'vararg'
    c = cls(t)
    if c is None: return 'unknown'
    lr, lt, la, info, succ = c
    if reg in lr or reg in lt: return 'yes'
    if reg not in la: return 'no'
    if depth == 0: return 'deep'
    return impact(t, reg, info, succ, depth - 1)
def impact(ent, reg, info, succ, depth=3):
    res = set()
    for a in sites(ent, reg, info, succ):
        op, arg = ins[a]
        if op in ('bctrl', 'bctr'): res.add('indirect'); continue
        if 'symbol stub for:' in arg:
            sym = arg.split('symbol stub for:')[1].strip()
            if sym in label: res.add(callee_reads(label[sym], reg, depth)); continue   # this image's own export, called through its PIC stub
            n = ARITY.get(sym)
            if n is not None: res.add('no' if reg >= 3 + n else 'yes'); continue      # a libSystem / libstdc++ import of known arity
            res.add('import'); IMPORTS.setdefault((ent, reg), set()).add(sym); continue
        m = re.match(r'0x([0-9a-f]+)', arg)
        t = int(m.group(1), 16) if m else label.get(arg.split()[0]) if arg else None   # an unstripped image prints `bl _name`
        if t is None: res.add('unknown'); continue
        res.add(callee_reads(t, reg, depth))
    for k in ('yes', 'indirect', 'import', 'vararg', 'unknown', 'deep'):
        if k in res: return k
    return 'no'
for f in sorted(glob.glob(dump + '/*.txt')):
    t = open(f).read()
    regs_ = sorted(set(int(x) for x in re.findall(r'(?m)^\s+\w[\w *]*\bin_r([3-9]|10);', t)))
    if not regs_: continue
    name, addr = re.search(r'// Function: (.*) @ (\S+)', t).groups(); ent = int(addr, 16)
    if ent not in rows: continue
    lr, lt, la, info, succ = classify(ent)
    for r in regs_:
        c = 'USED' if r in lr else 'RET' if r in lt else 'PASS' if r in la else 'DEAD'
        fr = first_reader(ent, r, info, succ, c == 'USED') if c != 'DEAD' else None
        if c == 'PASS':
            IMPORTS.pop((ent, r), None); c = 'PASS-' + impact(ent, r, info, succ)
            if c == 'PASS-import': fr = None; c += '\t' + ','.join(sorted(IMPORTS.get((ent, r), ())))   # -yes: some callee reads it; -no: none does; -indirect/-import: a call through a pointer / to an import
        print('%x\t%s\tr%d\t%s\t%s' % (ent, name, r, c, ('%x %s %s' % (fr, ins[fr][0], ins[fr][1][:40])) if fr else ''))
