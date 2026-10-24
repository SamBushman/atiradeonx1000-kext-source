#!/usr/bin/env python3
"""audit_set.py DIR TABLE [--dry] : rows of TABLE whose new name is `set`/`setN` (an autoweb_callee.py name taken from IROperand__setModifierBits' parameter `set`) become
negateFlag / absFlag (+ suffix) when every use of the variable in the function is the value argument of IROperand__setModifierBits(.., 1, V) (modifier bit 1 = operand negate)
or (.., 2, V) (bit 2 = abs), the bit being the literal in the call."""
import sys, re, glob, os, collections
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import apply_names as A
d, table = sys.argv[1:3]; dry = '--dry' in sys.argv
roots = A.func_roots(A.load_funcs(d))
cur2 = {}
H = re.compile(r'^/\* (\S+) @ 0x')
body = {}
files = {}
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(pf, errors='surrogateescape').read().split('\n'); c = None
    for i, l in enumerate(L):
        m = H.match(l)
        if m: c = m.group(1); body[c] = (pf, i, i); continue
    # function ranges
    starts = [(i, H.match(l).group(1)) for i, l in enumerate(L) if H.match(l)]
    for k, (i, n) in enumerate(starts): body[n] = (pf, i, starts[k + 1][0] if k + 1 < len(starts) else len(L))
rows = [l.split('\t') for l in open(table, errors='surrogateescape').read().split('\n')]
groups = collections.defaultdict(list)
for i, c in enumerate(rows):
    if len(c) > 5 and c[0] in ('use', 'local') and re.match(r'set\d*$', c[3]): groups[(c[1], c[3])].append(i)
plan = {}
for (fn, name), idx in groups.items():
    cur = [n for n in body if roots.get(n, n) == roots.get(fn, fn)]
    if not cur: continue
    pf, a, b = body[cur[0]]
    txt = open(pf, errors='surrogateescape').read().split('\n')[a:b]
    occ = [l for l in txt if re.search(r'(?<![\w])%s(?![\w])' % re.escape(name), l)]
    bits = set(); ok = True; ncalls = 0
    for l in occ:
        for m in re.finditer(r'IROperand__setModifierBits\(.*?,\s*(\d+),\s*%s\)' % re.escape(name), l):
            bits.add(m.group(1)); ncalls += 1
        rest = re.sub(r'IROperand__setModifierBits\(.*?,\s*\d+,\s*%s\)' % re.escape(name), '', l)
        if re.search(r'(?<![\w])%s(?![\w])' % re.escape(name), rest) and not re.match(r'\s*%s = ' % re.escape(name), rest.strip() and rest) and not re.match(r'^\s*(uint|int|undefined4) %s;' % re.escape(name), l):
            ok = False
    if ok and len(bits) == 1 and ncalls >= 1: plan[(fn, name)] = ('negateFlag' if bits == {'1'} else 'absFlag' if bits == {'2'} else None)
plan = {k: v for k, v in plan.items() if v}
print(len(groups), 'set groups,', len(plan), 'upgradable')
if dry: sys.exit()
used = collections.defaultdict(collections.Counter)
newname = {}
for (fn, name), base in sorted(plan.items()):
    used[fn][base] += 1; n = used[fn][base]
    newname[(fn, name)] = base if n == 1 else base + str(n)
for (fn, name), idx in groups.items():
    if (fn, name) in newname:
        for i in idx: rows[i][3] = newname[(fn, name)]; rows[i][5] = 'bit %s of the operand flags (set by IROperand__setModifierBits with modifier bit %s)' % ('0 (negate)' if newname[(fn, name)].startswith('negate') else '1 (abs)', '1' if newname[(fn, name)].startswith('negate') else '2')
open(table, 'w', errors='surrogateescape').write('\n'.join('\t'.join(c) for c in rows))
for (fn, name), new in newname.items():
    cur = [n for n in body if roots.get(n, n) == roots.get(fn, fn)][0]
    pf, a, b = body[cur]
    L = open(pf, errors='surrogateescape').read().split('\n')
    rx = re.compile(r'(?<![\w])%s(?![\w])' % re.escape(name))
    for i in range(a, b):
        if rx.search(L[i]): L[i] = rx.sub(new, L[i])
    open(pf, 'w', errors='surrogateescape').write('\n'.join(L))
print('renamed', len(newname))
