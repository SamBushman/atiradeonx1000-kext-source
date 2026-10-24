#!/usr/bin/env python3
"""ph.py DIR [FN-glob ...] : per function, the placeholder variables still present in the CURRENT text with counts"""
import sys, re, glob, os, fnmatch, collections
d = sys.argv[1]; pats = sys.argv[2:] or ['*']
R = re.compile(r'\b(?:extraout_\w+|\w*Stack_[0-9a-f]+)\b|\b(?:[a-z]{0,3}Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z0-9]+|[a-z]?Stack_[0-9a-f]+|p+_?[A-Za-z]*Var\d+|fparam_\d+|in_stack_\w+|FUN_[0-9a-f]+)\b')
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    cur = None; c = collections.Counter()
    def flush():
        if cur and c and any(fnmatch.fnmatchcase(cur, p) for p in pats):
            print('%s: %s' % (cur, ' '.join('%s*%d' % kv for kv in c.items())))
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m: flush(); cur = m.group(1); c = collections.Counter(); continue
        for x in R.findall(l): c[x] += 1
    flush()
