#!/usr/bin/env python3
"""census_union.py BASE.tsv VARIANT.tsv [...]: per function, is the ordered trace IDENTICAL in ALL trials (no non-identical tier)?  Reports how many functions are strict-identical in BASE, in each variant, and in the union
(a function picks the build flags of any variant in which it is clean)."""
import sys
def load(f):
    d = {}
    for l in open(f):
        if l.startswith('#'): continue
        p = l.rstrip('\n').split('\t')
        if len(p) < 21: continue
        runs = int(p[7] or 0); lay = int(p[20] or 0); ident = int(p[8] or 0)
        bad = sum(int(p[i] or 0) for i in (9, 10, 11, 12, 13, 14, 15, 16)) + int(p[21] or 0 if len(p) > 21 else 0) + int(p[22] if len(p) > 22 else 0)
        d[p[1]] = (bad == 0 and ident > 0)
    return d
ds = [load(f) for f in sys.argv[1:]]
names = set(ds[0])
for f, d in zip(sys.argv[1:], ds): print('%-45s clean %d / %d' % (f.split('/')[-1], sum(1 for n in names if d.get(n)), len(names)))
print('union clean: %d' % sum(1 for n in names if any(d.get(n) for d in ds)))
