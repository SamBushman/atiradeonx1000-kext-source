#!/usr/bin/env python3
"""unname.py DIR FN VAR... : take every `local` and `use` row of the Ghidra variables VAR of function FN out of the tables AND put VAR back in the part file text.

FN may be the function's current name or its old Ghidra name (rows are matched through the corpus' `func OLD NEW` rows, so rows written under FUN_xxxx still match
after the function was renamed). Use it before writing web rows (specs.py / emit_webs.py) for a variable that earlier rounds named as a whole, e.g. a hybrid
name; it replaces `prep.py` + `rn.py revert`, which need the table's function name to equal the part file's.
Prints, per variable, the new names that were rolled back and the number of text lines touched. Then run apply_names.py --check."""
import sys, re, glob, os
d, fn = sys.argv[1], sys.argv[2]; vars_ = sys.argv[3:]
names = {fn}
for t in sorted(glob.glob(os.path.join(d, 'names*.tsv'))):
    for l in open(t, errors='surrogateescape'):
        c = l.rstrip('\n').split('\t')
        if len(c) >= 4 and c[0] == 'func' and (c[1] == fn or c[2] == fn): names |= {c[1], c[2]}
back = {v: set() for v in vars_}
for t in sorted(glob.glob(os.path.join(d, 'names*.tsv'))):
    rows = open(t, errors='surrogateescape').read().split('\n'); keep = []; ch = False
    for l in rows:
        c = l.split('\t')
        if len(c) >= 6 and c[0] in ('local', 'use') and c[1] in names and c[2] in back:
            back[c[2]].add(c[3]); ch = True; continue
        keep.append(l)
    if ch: open(t, 'w', errors='surrogateescape').write('\n'.join(keep))
HDR = re.compile(r'^/\* (\S+) @ 0x')
for f in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(f, errors='surrogateescape').read().split('\n')
    s = next((i for i, l in enumerate(L) if HDR.match(l) and HDR.match(l).group(1) in names), None)
    if s is None: continue
    e = next((i for i in range(s + 1, len(L)) if HDR.match(L[i])), len(L))
    for v, news in back.items():
        n = 0
        for new in sorted(news, key=len, reverse=True):
            rx = re.compile(r'\b%s\b' % re.escape(new))
            for i in range(s, e):
                if rx.search(L[i]): L[i] = rx.sub(v, L[i]); n += 1
        print(v, sorted(news), 'lines', n)
    open(f, 'w', errors='surrogateescape').write('\n'.join(L))
    break
