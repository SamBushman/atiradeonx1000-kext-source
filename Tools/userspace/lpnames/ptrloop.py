#!/usr/bin/env python3
"""ptrloop.py DIR PARTLO PARTHI [--dry] : variables named loopIndex[N] that are declared as pointers (`T *loopIndex3;`) walk an array: rename them loopPtr[N]
(table rows of the function, keyed by its Ghidra or its renamed name, and the function body)."""
import sys, re, glob, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import apply_names as A
d = sys.argv[1]; lo, hi = int(sys.argv[2]), int(sys.argv[3]); dry = '--dry' in sys.argv
roots = A.func_roots(A.load_funcs(d))
H = re.compile(r'^/\* (\S+) @ 0x')
DECL = re.compile(r'^  [\w ]+ \*+(loopIndex\d*);')
todo = {}                                   # function -> {old: new}
for pn in range(lo, hi + 1):
    pf = os.path.join(d, 'part_%03d.c' % pn)
    if not os.path.exists(pf): continue
    cur = None
    for l in open(pf, errors='surrogateescape'):
        m = H.match(l)
        if m: cur = m.group(1); continue
        m = DECL.match(l)
        if m and cur: todo.setdefault(cur, {})[m.group(1)] = m.group(1).replace('loopIndex', 'loopPtr')
print(len(todo), 'functions,', sum(len(v) for v in todo.values()), 'variables')
if dry: sys.exit()
nrows = 0; nlines = 0
for t in sorted(glob.glob(os.path.join(d, 'names*.tsv'))):
    L = open(t, errors='surrogateescape').read().split('\n'); ch = False
    for i, l in enumerate(L):
        c = l.split('\t')
        if len(c) > 5 and c[0] in ('local', 'use'):
            for fn, mp in todo.items():
                if c[1] in (fn, roots.get(fn, fn)) and c[3] in mp:
                    c[3] = mp[c[3]]; L[i] = '\t'.join(c); nrows += 1; ch = True; break
    if ch: open(t, 'w', errors='surrogateescape').write('\n'.join(L))
for pn in range(lo, hi + 1):
    pf = os.path.join(d, 'part_%03d.c' % pn)
    if not os.path.exists(pf): continue
    L = open(pf, errors='surrogateescape').read().split('\n'); cur = None; ch = False
    for i, l in enumerate(L):
        m = H.match(l)
        if m: cur = m.group(1); continue
        if cur in todo:
            for old, new in todo[cur].items():
                if re.search(r'\b%s\b' % old, l): L[i] = re.sub(r'\b%s\b' % old, new, L[i]); nlines += 1; ch = True; l = L[i]
    if ch: open(pf, 'w', errors='surrogateescape').write('\n'.join(L))
print('rows', nrows, 'lines', nlines)
