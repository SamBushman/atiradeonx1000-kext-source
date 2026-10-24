#!/usr/bin/env python3
"""ren2.py DIR FNNEW FNOLD OLDAPPLIED NEW [EVIDENCE] : like rn.py ren, for a function that has a `func` row (table rows key the Ghidra/old function name, the part file carries the new one).
Edits the applied new name in every table row of FNOLD and in the body of FNNEW."""
import sys, re, glob, os
d, fnnew, fnold, old, new = sys.argv[1:6]; ev = sys.argv[6] if len(sys.argv) > 6 else None
rows = 0
for t in sorted(glob.glob(os.path.join(d, 'names*.tsv'))):
    L = open(t, errors='surrogateescape').read().split('\n'); ch = False
    for i, l in enumerate(L):
        c = l.split('\t')
        if len(c) > 5 and c[0] in ('local', 'use') and c[1] == fnold and c[3] == old:
            c[3] = new
            if ev: c[5] = ev
            L[i] = '\t'.join(c); rows += 1; ch = True
    if ch: open(t, 'w', errors='surrogateescape').write('\n'.join(L))
H = re.compile(r'^/\* (\S+) @ 0x')
lines = 0
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(pf, errors='surrogateescape').read().split('\n'); cur = None; ch = False
    rx = re.compile(r'\b%s\b' % re.escape(old))
    for i, l in enumerate(L):
        m = H.match(l)
        if m: cur = m.group(1); continue
        if cur == fnnew and rx.search(l): L[i] = rx.sub(new, l); lines += 1; ch = True
    if ch: open(pf, 'w', errors='surrogateescape').write('\n'.join(L))
print('rows', rows, 'lines', lines)
