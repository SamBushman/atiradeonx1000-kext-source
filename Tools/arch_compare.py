#!/usr/bin/env python3
"""arch_compare.py PPC_DIS I386_DIS [N]  - the kext's PPC and i386 slices are two compilations of one source. Compare, per shared
function symbol, the multiset of named callees (jbsr/bl vs calll) and the count of indirect calls (bctrl vs call *): a
difference marks code that exists in one slice only (an #ifdef'd path or a different inlining decision)."""
import sys, re, bisect, collections
pdis, idis = sys.argv[1], sys.argv[2]
top = int(sys.argv[3]) if len(sys.argv) > 3 else 60
ins = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
led = {}
for l in open('Ledger/kext_ppc_ledger.tsv'):
    f = l.rstrip('\n').split('\t')
    if len(f) >= 6 and f[2] in ('method', 'generated') and f[3] == 'DONE': led[f[5]] = (int(f[0], 16), int(f[1]), f[4])
prow = []
for l in open(pdis):
    m = ins.match(l)
    if m: prow.append((int(m.group(1), 16), m.group(2), m.group(3)))
paddr = [r[0] for r in prow]
def pcallees(rows):
    c = collections.Counter()
    for a, op, rest in rows:
        if op == 'jbsr': c[rest.split(',')[0].lstrip('_')] += 1
        elif op == 'bctrl': c['<indirect>'] += 1
    return c
ifun = {}; cur = None
for l in open(idis):
    if re.match(r'^_\S+:$', l.strip()) and not l.startswith('\t') and not l[0].isdigit():
        cur = l.strip()[:-1]; ifun[cur] = collections.Counter(); continue
    m = ins.match(l)
    if m and cur:
        op, rest = m.group(2), m.group(3)
        if op in ('calll', 'call'):
            t = rest.strip()
            ifun[cur]['<indirect>' if t.startswith('*') else t.lstrip('_')] += 1
res = []
for sym, (a, n, name) in led.items():
    if sym not in ifun: continue
    i = bisect.bisect_left(paddr, a); j = bisect.bisect_left(paddr, a + n)
    cp = pcallees(prow[i:j]); ci = ifun[sym]
    d = sum(((cp - ci) + (ci - cp)).values())
    if d: res.append((d, name, dict(cp - ci), dict(ci - cp)))
res.sort(reverse=True)
print(len(res), 'functions with differing callees, of', sum(1 for s in led if s in ifun))
for d, name, a, b in res[:top]: print(d, name, 'PPC-ONLY', a, 'I386-ONLY', b)
