#!/usr/bin/env python3
"""param_used.py DIS INREG.json KEY - for functions whose C reads in_rN beyond its parameters: do stock callers set rN before calling it?
A caller that writes rN between its previous call and the `bl` passes a real argument; if no caller ever does, the read is of garbage (forwarded)."""
import sys, re, json
dis, cj, key = sys.argv[1:4]
ins = []; lab = {}; cur = None
for l in open(dis, errors='replace'):
    l = l.rstrip('\n')
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l)
    if m:
        ins.append((int(m.group(1), 16), m.group(2), m.group(3)))
        if cur: lab[cur] = ins[-1][0]; cur = None
    elif l.endswith(':') and '\t' not in l: cur = l[:-1]
by_target = {}
for i, (a, op, arg) in enumerate(ins):
    if op in ('bl', 'b'):
        ms = re.search(r'symbol stub for: (\S+)', arg); t = arg.split()[0] if arg else ''
        ta = lab.get(ms.group(1)) if ms else (int(t, 16) if t.startswith('0x') else lab.get(t))
        if ta is not None: by_target.setdefault(ta, []).append(i)
def written(i):
    regs = set()
    for j in range(i - 1, max(i - 40, -1), -1):
        a, op, arg = ins[j]
        if op.startswith('bl') or op in ('bctrl',) or op.startswith('b') and op not in ('bcl',) and j != i: 
            if op.startswith('bl') or op == 'bctrl': break
        d = arg.split(',')[0].strip()
        if re.fullmatch(r'r([3-9]|10)', d) and not op.startswith(('st', 'cmp', 'b', 'mt')): regs.add(int(d[1:]))
    return regs
for a, n, npar, need in json.load(open(cj))[key]:
    a = int(a, 16); sites = by_target.get(a, [])
    real = sorted({r for i in sites for r in written(i) if r in need})
    print('%s\t%s\tparams=%d\tneed=%s\tsites=%d\treal=%s' % (hex(a), n, npar, need, len(sites), real))
