#!/usr/bin/env python3
"""webview.py DIR FN VAR [web,web...] : PLAIN webs of Ghidra variable VAR with their def lines, a few use lines and the enclosing `case N:` label (file line numbers as fshow.py prints them)"""
import sys, os, re, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn, v = sys.argv[1:4]
only = set(int(x) for x in sys.argv[4].split(',')) if len(sys.argv) > 4 else None
body, brace = F.load(d, fn); cur = F.CURRENT
first = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    for i, l in enumerate(open(pf).read().split('\n')):
        m = re.match(r'^/\* (\S+) @ 0x', l)
        if m and m.group(1) == fn: first = i + 1
    if first: break
off = first - 0  # body line k -> file line k+first? verify with fshow numbering below
CASE = re.compile(r'^\s*case (0x[0-9a-f]+|\d+):')
cases = [(i, m.group(1)) for i, l in enumerate(body) for m in [CASE.match(l)] if m]
def case_of(i):
    c = None
    for j, n in cases:
        if j <= i: c = n
        else: break
    return c
nodes, entry = F.build_cfg(body, brace)
ws = F.webs(nodes, entry, v)[0]
W = r'\b%s\b' % re.escape(v)
for k, w in enumerate(ws):
    if only is not None and k not in only: continue
    ls = sorted(w)
    pl = [l for l in ls if re.search(W, body[l])]
    if not any(re.search(W, cur[l]) for l in pl): continue
    defs = [l for l in pl if re.search(W + r'\s*(=|\+=|-=|\|=|&=)[^=]', body[l])]
    uses = [l for l in pl if l not in defs]
    shown = defs[:3] + uses[:4]
    print('w%d n=%d [case %s .. %s] lines %d-%d' % (k, len(pl), case_of(ls[0]), case_of(ls[-1]), ls[0] + first, ls[-1] + first))
    for l in sorted(set(shown)):
        print('    %d%s %s' % (l + first, '=' if l in defs else ' ', cur[l].strip()[:150]))
