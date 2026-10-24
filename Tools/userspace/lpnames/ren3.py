#!/usr/bin/env python3
"""ren3.py DIR FN OLDAPPLIED NEW [EVIDENCE] : rename the APPLIED name of a variable of FN (table rows of FN, keyed by its Ghidra or renamed name; the current function body).
FN may be either name of the function (ren2.py needs both)."""
import sys, re, glob, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import apply_names as A
d, fn, old, new = sys.argv[1:5]; ev = sys.argv[5] if len(sys.argv) > 5 else None
roots = A.func_roots(A.load_funcs(d)); root = roots.get(fn, fn)
rows = 0
for t in sorted(glob.glob(os.path.join(d, 'names*.tsv'))):
    L = open(t, errors='surrogateescape').read().split('\n'); ch = False
    for i, l in enumerate(L):
        c = l.split('\t')
        if len(c) > 5 and c[0] in ('local', 'use') and roots.get(c[1], c[1]) == root:
            c2 = list(c)
            if c[3] == old:
                c2[3] = new
                if ev: c2[5] = ev
            if len(c) > 6 and c[0] == 'use': c2[6:] = [re.sub(r'(?<![\w])%s(?![\w])' % re.escape(old), new, x) if k == 0 else x for k, x in enumerate(c[6:])] if False else c2[6:]
            if c2 != c: L[i] = '\t'.join(c2); rows += 1; ch = True
    if ch: open(t, 'w', errors='surrogateescape').write('\n'.join(L))
H = re.compile(r'^/\* (\S+) @ 0x'); lines = 0; rx = re.compile(r'(?<![\w])%s(?![\w])' % re.escape(old))
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(pf, errors='surrogateescape').read().split('\n'); cur = None; ch = False
    for i, l in enumerate(L):
        m = H.match(l)
        if m: cur = m.group(1); continue
        if cur and roots.get(cur, cur) == root and rx.search(l): L[i] = rx.sub(new, l); lines += 1; ch = True
    if ch: open(pf, 'w', errors='surrogateescape').write('\n'.join(L))
print(fn, old, '->', new, 'rows', rows, 'lines', lines)
