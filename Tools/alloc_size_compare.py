#!/usr/bin/env python3
"""alloc_size_compare.py STOCK_DIS OURS_DIS  (#85) - compare the size passed to OSObject::operator new (`li r3,N` shortly before the call)
at every allocation site of the shipped kext and the rebuild. A different size means a class whose layout is wrong (too small = heap
overrun, too large = unfaithful). Sites are keyed by the enclosing method; MetaClass::alloc entries identify each class's own size.
Exit 1 on any difference."""
import sys, re, bisect
led = [l.rstrip('\n').split('\t') for l in open('Ledger/kext_ppc_ledger.tsv')]
rng = sorted((int(f[0], 16), f[4]) for f in led if len(f) >= 5 and re.match(r'^[0-9]+$', f[1]))
starts = [r[0] for r in rng]
def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return rng[i][1] if i >= 0 else '?'
def scan(path, labelled, sym2name):
    rows = []; cur = None; res = []
    for l in open(path):
        l = l.rstrip('\n')
        if labelled and re.match(r'^\S+:$', l) and not l.startswith('0'): cur = l[:-1]; continue
        m = re.match(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$', l)
        if m: rows.append((int(m.group(1), 16), m.group(2), m.group(3), cur))
    for i, (a, op, rest, cur) in enumerate(rows):
        if op in ('jbsr', 'bl', 'b') and 'OSObjectnwEm' in rest:
            sz = None
            for j in range(i - 1, max(i - 10, 0), -1):
                if rows[j][1] == 'li' and rows[j][2].startswith('r3,'): sz = rows[j][2][3:]; break
            res.append(((sym2name.get(cur, cur) if labelled else owner(a)), sz))
    return res
sym2name = {f[5]: f[4] for f in led if len(f) >= 6}
st = scan(sys.argv[1], False, sym2name); ou = scan(sys.argv[2], True, sym2name)
from collections import Counter
cs, co = Counter(st), Counter(ou)
bad = 0
for k in sorted(set(cs) | set(co), key=str):
    if cs[k] != co[k]:
        bad += 1
        print('DIFF  %-50s size %s  stock x%d  rebuilt x%d' % (k[0], k[1], cs[k], co[k]))
print('alloc_size_compare: %d allocation sites in the shipped kext, %d in the rebuild, %d differences' % (len(st), len(ou), bad))
sys.exit(1 if bad else 0)
