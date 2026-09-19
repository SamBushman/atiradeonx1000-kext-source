#!/usr/bin/env python3
"""callee_compare.py STOCK_DIS OURS_DIS [MIN_DIFF]  - fidelity check: for every ledger method, compare the multiset of
callees (jbsr/bl targets, virtual `bctrl` count, kernel-stub names) in the shipped kext against the rebuild.
STOCK_DIS/OURS_DIS: `otool -arch ppc -tV` output. A faithful transcription calls the same things the same number of times
(modulo inlining by the compiler); big deltas mark bodies to re-read against the decompile."""
import sys, re, collections
sdis, odis = sys.argv[1], sys.argv[2]
mind = int(sys.argv[3]) if len(sys.argv) > 3 else 1
led = {}
addr2name = {}
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 5:
        addr2name[int(f[0], 16)] = f[4]
    if len(f) >= 6 and f[2] == 'method' and f[3] == 'DONE':
        led[f[5]] = (int(f[0], 16), int(f[1]), f[4])
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
def callees(lines):
    c = collections.Counter()
    for a, op, rest in lines:
        if op == 'jbsr':
            c[rest.split(',')[0].lstrip('_')] += 1
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            c['bl:' + t.lstrip('_')] += 1
        elif op == 'bctrl':
            c['<indirect>'] += 1
    return c
# stock
srows = []
for l in open(sdis):
    m = ins.match(l)
    if m: srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
import bisect
saddr = [r[0] for r in srows]
def stock_range(a, n):
    i = bisect.bisect_left(saddr, a); j = bisect.bisect_left(saddr, a + n)
    return srows[i:j]
# ours: labels
ofun = {}; cur = None
for l in open(odis):
    if re.match(r'^\S+:$', l.strip()) and not l.startswith('\t') and not l.startswith('0'):
        cur = l.strip()[:-1]; ofun[cur] = []
        continue
    m = ins.match(l)
    if m and cur: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
def norm(c, ours):
    out = collections.Counter()
    for k, v in c.items():
        if k.startswith('bl:'):
            t = k[3:]
            # stock local direct calls are addresses: name them via the ledger
            if t.startswith('0x'):
                try: t = addr2name.get(int(t, 16), t)
                except ValueError: pass
            k = 'bl:' + t
        out[k] += v
    return out
# ours: fold in helper functions that the shipped kext has no separate function for (anonymous-namespace / static helpers the
# compiler inlined there): their callees count towards the caller
ocall = {s.lstrip('_'): callees(r) for s, r in ofun.items()}
ledn = {k.lstrip('_') for k in led}
def expand(sym, seen=()):
    out = collections.Counter()
    for k, v in ocall[sym.lstrip('_')].items():
        kk = k[3:] if k.startswith('bl:') else k
        if kk in ocall and kk not in ledn and kk not in seen:
            for k2, v2 in expand(kk, seen + (sym,)).items(): out[k2] += v * v2
        else:
            out[k] += v
    return out
res = []
for sym, (a, n, name) in led.items():
    if sym not in ofun: continue
    cs = norm(callees(stock_range(a, n)), False)
    co = norm(expand(sym), True)
    # bl to a defined local function shows as a name in ours and an address in stock: fold both to bare names
    ALIAS = {'memmove': 'memcpy', 'bzero': 'memset'}
    def fold(c):
        r = collections.Counter()
        for k, v in c.items():
            k = k[3:] if k.startswith('bl:') else k
            if k.startswith('FormatTableLookup_'): continue   # the shipped code reads the table inline
            if re.match(r'^(Z1M|Z25enforceInOrder|Z22instructionSynch|Z2\dppc|Z\d+dataCacheBlock|Z\d+(sync|eieio)|ZL|Z\d+(BF|FBITS|CONCAT|SUB41))', k): continue   # -O0 helper wrappers (M<T>, intrinsics)
            r[ALIAS.get(k, k)] += v
        return r
    cs, co = fold(cs), fold(co)
    d = sum(((cs - co) + (co - cs)).values())
    if d >= mind: res.append((d, name, dict(cs - co), dict(co - cs)))
res.sort(reverse=True)
print(len(res), 'methods differ (of', len(led), ')')
for d, name, miss, extra in res[:int(sys.argv[4]) if len(sys.argv) > 4 else 80]:
    print(d, name, 'STOCK-ONLY', miss, 'OURS-ONLY', extra)
