#!/usr/bin/env python3
"""fshow.py DIR FN [FN...] : print the CURRENT text of the functions (declarations dropped when they carry no placeholder is NOT done: full text)"""
import sys, re, glob, os
d = sys.argv[1]; want = set(sys.argv[2:])
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    on = False
    for n, l in enumerate(open(pf, errors='replace'), 1):
        m = H.match(l)
        if m: on = m.group(1) in want
        if on: print('%d:%s' % (n, l.rstrip()[:240]))
