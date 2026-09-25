#!/usr/bin/env python3
"""ret_used.py DIS CANDIDATES.json KEY - for each candidate function, look at every stock `bl` to it: is r3 (or f1) read after the call before being
written, on the straight-line code that follows? gcc never reads r3/f1 after calling a void function, so a read means the callee returns a value."""
import sys, re, json
dis, cj, key = sys.argv[1:4]
ins, lab = [], {}
for l in open(dis, errors='replace'):
    l = l.rstrip('\n')
    m = re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)', l)
    if m: ins.append((int(m.group(1), 16), m.group(2), m.group(3)))
    else:
        m = re.match(r'^([^\s:][^:]*):$', l)
        if m and ins is not None: lab[m.group(1)] = None; pending = m.group(1)
# label -> address: the next instruction after a label line
lab = {}
cur = None
for l in open(dis, errors='replace'):
    l = l.rstrip('\n')
    m = re.match(r'([0-9a-f]{8})\t', l)
    if m:
        if cur: lab[cur] = int(m.group(1), 16); cur = None
    elif l.endswith(':') and '\t' not in l: cur = l[:-1]
by_target = {}
for i, (a, op, arg) in enumerate(ins):
    if op in ('bl', 'bl+', 'bl-'):
        t = arg.split()[0]
        ms = re.search(r'symbol stub for: (\S+)', arg)
        ta = lab.get(ms.group(1)) if ms else (int(t, 16) if t.startswith('0x') else lab.get(t))
        if ta is not None: by_target.setdefault(ta, []).append(i)
def reads(arg, r):
    ops = [o.strip() for o in arg.split(';')[0].split(',')]
    return any(re.search(r'\b%s\b' % r, o) for o in ops[1:]) or (len(ops) == 1 and re.search(r'\b%s\b' % r, ops[0]) is not None)
def writes(op, arg, r):
    ops = [o.strip() for o in arg.split(';')[0].split(',')]
    return ops and ops[0] == r and not op.startswith(('st', 'cmp', 'fcmp', 'b', 'mt'))
out = []
for a, n, *_ in json.load(open(cj))[key]:
    a = int(a, 16); res = {'r3': 0, 'f1': 0}; sites = by_target.get(a, [])
    for i in sites:
        for r in ('r3', 'f1'):
            for j in range(i + 1, min(i + 40, len(ins))):
                _, op, arg = ins[j]
                if reads(arg, r) and not (op.startswith('st') and arg.split(',')[0].strip() != r and False):
                    if op.startswith(('st',)) and arg.split(',')[0].strip() == r: res[r] += 1; break
                    if not writes(op, arg, r) or re.search(r'\b%s\b' % r, ','.join(arg.split(',')[1:])): res[r] += 1; break
                if writes(op, arg, r): break
                if op.startswith(('b', 'bl')) or op in ('blr', 'bctr'): break
    out.append((hex(a), n, len(sites), res['r3'], res['f1']))
for o in out: print('%s\t%s\tcallsites=%d\tr3-read-after=%d\tf1-read-after=%d' % o)
