#!/usr/bin/env python3
"""float_params.py STOCK_DIS RANGES_TSV CORPUS_DIR  - which `double fparam_k` parameters of the decompiled GLEngine are really `float` parameters.

Ghidra types every floating-point argument register `double` (the custom storage is 8 bytes wide). Source compiled with a `float` parameter reads it with
single-precision instructions (fmuls, fadds, fmadds, stfs ...) and never rounds it first; a `double` parameter used as a float is rounded (`frsp`) first. A rebuilt
function declared `double fparam_k` therefore gets an extra frsp in front of every use (74 per function in the lighting code: instruction count and, for a value
that is not a float, the rounding). A parameter is classified `float` when, in the stock code, EVERY read of its argument register before the function writes it
again (address order inside the function's ranges) is a single-precision arithmetic/store instruction or format-neutral (fabs fneg fcmpu fctiwz), and at least one
read is single precision. The whole function is scanned (a later write of the register does not end the scan: a double-precision read of a reused register
makes the parameter `double`, which can only cost speed, never precision). Any double-precision read (fmul fadd stfd frsp ...), pass-through to a call and `fmr` copies leave it `double` (conservative).
Prints `ENTRY NAME k[,k...]` for each function that has at least one float parameter (k = the number in `fparam_k`, f_k)."""
import sys, re
dis, rng_f, cdir = sys.argv[1:4]
ins = {}
for l in open(dis, errors='replace'):
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l.rstrip())
    if m: ins[int(m.group(1), 16)] = (m.group(2), m.group(3).split(';')[0].strip())
rows = {}
for l in open(rng_f):
    p = l.rstrip('\n').split('\t')
    if len(p) > 3 and p[0].startswith('0x') and p[2] == 'fn':
        rows[int(p[0], 16)] = [tuple(int(x, 16) for x in r.split('-')) for r in p[3].strip(';').split(';') if r]
SP = {'fadds', 'fsubs', 'fmuls', 'fdivs', 'fmadds', 'fmsubs', 'fnmadds', 'fnmsubs', 'fres', 'frsqrtes', 'fsqrts', 'fsels_'}
SPD = {'stfs', 'stfsx', 'stfsu'}              # single-precision store of the register
NEUTRAL = {'fabs', 'fneg', 'fnabs', 'fcmpu', 'fcmpo', 'fctiwz', 'fctiw', 'fsel'}
FR = re.compile(r'\bf(\d{1,2})\b')
def fdefs_uses(op, arg):
    """(defined fpr set, used fpr set) of one instruction"""
    regs = [int(x) for x in FR.findall(arg)]
    if op in ('bl', 'bctrl', 'blrl'): return set(range(0, 14)), set(range(1, 14))
    if op in ('blr', 'bctr', 'b'): return set(), set()
    if op.startswith(('stf',)): return set(), set(regs[:1])
    if op.startswith(('lf',)): return set(regs[:1]), set()
    if op.startswith('fc') or op.startswith('fcmp'): return set(), set(regs[-2:])
    if regs: return {regs[0]}, set(regs[1:])
    return set(), set()
# the corpus functions with double params: name -> [k]
sig = {}
import glob
for f in sorted(glob.glob(cdir + '/part_*.c')):
    for m in re.finditer(r'(?m)^/\* (\S+) @ 0x([0-9a-f]+) \(\d+ bytes\) \*/\n[^\n(]*?\b(\S+)\(([^)]*)\)', open(f, errors='replace').read()):
        ks = [int(x) for x in re.findall(r'double fparam_(\d+)', m.group(4))]
        if ks: sig[int(m.group(2), 16)] = (m.group(1), ks)
out = 0
for ent, (name, ks) in sorted(sig.items()):
    if ent not in rows: continue
    addrs = sorted(a for lo, hi in rows[ent] for a in range(lo, hi, 4) if a in ins)
    res = []
    for k in ks:
        sp = bad = 0; first = None
        alias = set()         # registers that hold a plain copy of the parameter (`fmr f4,f1`), from the fmr until something else writes them or a call: their reads are reads of the parameter
        for a in addrs:
            op, arg = ins[a]; d, u = fdefs_uses(op, arg)
            if first is None and (k in u or k in d): first = 'u' if (k in u and op not in ('bl', 'bctrl', 'blrl')) else 'd'   # a call first: unknown, left double   # the entry value must be read before anything writes the register (address order)
            holds = {k} | alias
            if op == 'fmr' and len(u) == 1 and next(iter(u)) in holds and first == 'u' and (k not in d):
                alias.add(next(iter(d)))             # a copy: its reads count (the copy itself is not a read of the format)
                continue
            if holds & u:
                if op in ('bl', 'bctrl', 'blrl'): pass      # argument passing: consistent with either type
                elif op in SP or op in SPD: sp += 1
                elif op in NEUTRAL: pass
                else: bad += 1
            alias -= (d - ({k} if False else set()))       # any other write ends an alias
            if op in ('bl', 'bctrl', 'blrl'): alias = set()
        if sp and not bad and first == 'u': res.append(k)
    if res: print('%x\t%s\t%s' % (ent, name, ','.join(map(str, res)))); out += 1
sys.stderr.write('float_params: %d functions with float parameters (of %d with double parameters)\n' % (out, len(sig)))
