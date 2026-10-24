#!/usr/bin/env python3
"""chainsplit.py DIR FN VAR ROLES [SPECOUT]

Split a variable that is redefined from itself (`x = A; ... x = f(x);`) into per-role names inside straight-line webs.
ROLES lines: NAME<TAB>DEFREGEX<TAB>EVIDENCE (DEFREGEX searched in the right-hand side of each `VAR = ...` definition; first match = the role the definition CREATES;
a definition that matches no role is reported and aborts).  Within a web, a use line takes the role of the latest definition above it; on a definition line whose
right-hand side also reads VAR (a chain), the left side takes the new role and the right side the previous one (L/R rows).
Output: rng.py SPEC lines (file-line ranges) appended to SPECOUT (run `rng.py DIR FN SPECOUT` for the rows)."""
import sys, os, re, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn, var, rolesf = sys.argv[1:5]
out = sys.argv[5] if len(sys.argv) > 5 else None
roles = []
for l in open(rolesf):
    if l.strip() and not l.startswith('#'):
        c = l.rstrip('\n').split('\t'); roles.append((c[0], re.compile(c[1]), c[2] if len(c) > 2 else ''))
body, brace = F.load(d, fn)
first = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    for i, l in enumerate(open(pf).read().split('\n')):
        m = re.match(r'^/\* (\S+) @ 0x', l)
        if m and m.group(1) == fn: first = i + 1
    if first: break
nodes, entry = F.build_cfg(body, brace)
ws, er = F.webs(nodes, entry, var)
DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
V = re.compile(r'\b%s\b' % re.escape(var))
res = {}   # role -> list of (file line, side)
ok = True
for k, ls in enumerate(ws):
    ls = sorted(ls)
    cur = None
    for x in ls:
        if x <= brace: continue
        m = DEF.search(body[x])
        if m:
            rhs = m.group(1)
            hit = [n for n, rx, ev in roles if rx.search(rhs)]
            if not hit:
                print('web %d line %d: definition matches no role: %s' % (k, first + x, body[x].strip()[:90])); ok = False; continue
            new = hit[0]
            if V.search(rhs) and cur is not None and cur != new:
                res.setdefault(cur, []).append((first + x, 'R')); res.setdefault(new, []).append((first + x, 'L'))
            elif V.search(rhs) and cur is None:
                res.setdefault(new, []).append((first + x, 'A'))
            else:
                res.setdefault(new, []).append((first + x, 'A'))
            cur = new
        else:
            if cur is None: print('web %d line %d: use before definition' % (k, first + x)); ok = False; continue
            res.setdefault(cur, []).append((first + x, 'A'))
ev = {n: e for n, _, e in roles}
lines = []
for n, items in res.items():
    allv = sorted(l for l, s in items if s == 'A')
    rng = []
    for l in allv:
        if rng and l == rng[-1][1] + 1: rng[-1][1] = l
        else: rng.append([l, l])
    rs = ['%d-%d' % (a, b) if a != b else str(a) for a, b in rng]
    if rs: lines.append('%s\t%s\t%s\tINFERRED\t%s' % (var, ','.join(rs), n, ev[n]))
    for l, s in items:
        if s in 'LR': lines.append('%s\t%d%s\t%s\tINFERRED\t%s' % (var, l, s, n, ev[n]))
print('\n'.join(lines))
if out and ok:
    with open(out, 'a') as f: f.write('\n'.join(lines) + '\n')
elif out: print('NOT written (errors above)')
