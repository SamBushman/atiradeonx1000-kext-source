#!/usr/bin/env python3
"""gatediag.py TAG PART FUNCLABEL : explain a gate DATAFLOW/UNINIT problem: new uninit warning names, and for every load whose reaching stores differ the base/candidate stores (frame slots) -- map the slots to variables by looking at the cand source around the stores"""
import sys, re, subprocess, collections
tag, part, fn = sys.argv[1:4]
T = '/tmp/vn_Userspace_ATIRadeonX1000GLDriver_ppc_%s' % tag
def uninit(p):
    c = collections.Counter()
    for l in open(p, errors='replace'):
        if 'uninit' in l: c[re.sub(r'^[^:]*:\d+: ', '', l.strip())] += 1
    return c
b = uninit('%s/base.%s.warn' % (T, part)); c = uninit('%s/cand.%s.warn' % (T, part))
for k, v in c.items():
    if v > b.get(k, 0): print('NEW UNINIT:', k, [l.split(':')[1] for l in open('%s/cand.%s.warn' % (T, part), errors='replace') if k.split("'")[1] in l and 'uninit' in l][:3])
src = open('/home/sam/wt/q05/Tools/userspace/split_equiv.py').read()
src = src[:src.rindex('main()')]
ns = {'__name__': 'se'}; exec(compile(src, 'se', 'exec'), ns)
B = ns['funcs']('%s/base.%s.dis' % (T, part)); MB = dict(ns['META']); C = ns['funcs']('%s/cand.%s.dis' % (T, part)); MC = dict(ns['META'])
k = [n for n in B if fn in n][0]
bb, cc = B[k], C[k]
rb, tb = ns['reaching'](bb, MB[k]); rc, tc = ns['reaching'](cc, MC[k])
diffs = [x for x in rb if rb[x] != rc.get(x)]
print(len(diffs), 'diff loads')
for d in diffs[:4]:
    print('load', d, bb[d], '|', cc[d])
    print('  base stores', sorted(rb[d]), 'cand stores', sorted(rc.get(d, [])))
    for s in sorted(set(rb[d]) | set(rc.get(d, []))): print('     store', s, bb[s], '|', cc[s], '   prev:', bb[s-1] if s else '', '|', cc[s-1] if s else '')
