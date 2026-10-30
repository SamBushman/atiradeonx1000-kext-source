#!/usr/bin/env python3
"""namecheck.py DIR FN ROWS... : find new names in the ROWS files (tsv use/local rows of FN) that are used for two Ghidra variables, or collide with a name already in the function text or in the applied rows -- these make apply_names fail after a 100 s run"""
import sys, re, glob, collections, os
d, fn = sys.argv[1:3]
new = collections.defaultdict(set)
for f in sys.argv[3:]:
    for l in open(f):
        c = l.rstrip('\n').split('\t')
        if len(c) > 3 and c[1] == fn and c[0] in ('use', 'local'): new[c[3]].add(c[2])
old = collections.defaultdict(set)
for t in glob.glob(os.path.join(d, 'names*.tsv')):
    for l in open(t):
        c = l.rstrip('\n').split('\t')
        if len(c) > 3 and c[1] == fn and c[0] in ('use', 'local'): old[c[3]].add(c[2])
txt = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(pf, errors='replace').read().split('\n')
    for i, l in enumerate(L):
        if l.startswith('/* %s @ ' % fn):
            j = i + 1
            while j < len(L) and not L[j].startswith('/* ') : j += 1
            txt = '\n'.join(L[i:j]); break
    if txt: break
ids = set(re.findall(r'\b[A-Za-z_]\w*\b', txt or ''))
bad = 0
for n, v in new.items():
    if len(v) > 1: print('DUP', n, v); bad += 1
    if n in old and old[n] - v: print('OLDCOL', n, old[n], v); bad += 1
    if n in ids and n not in old: print('IDCOL', n); bad += 1
print('namecheck:', bad, 'problems')
