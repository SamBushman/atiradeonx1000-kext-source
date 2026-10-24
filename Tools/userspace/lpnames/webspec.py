#!/usr/bin/env python3
"""webspec.py DIR FN VAR RULES [SPECOUT]

Like classwebs.py (RULES: `NAME<TAB>REGEX<TAB>EVIDENCE`, REGEX searched in the right-hand side of every `VAR = ...` definition of a web; the first rule that
matches names the definition), but the output is a spec for seg.py (`FN VAR NAME RANGES TIER EVIDENCE`, FILE-line ranges of the current tree), and a web whose
definitions get DIFFERENT names is split when it is a chain:  `VAR = f(VAR)` (the second definition reads the first one's value on its own line L): the lines up
to L (with L only on its right-hand side) get the first name, L's left-hand side and the lines after it get the second name.  Webs with 3+ definitions or a
non-chain mix are listed as unhandled. Several webs with the same name are written as one spec line (comma separated ranges).
Prints one line per web; with SPECOUT the specs are appended to that file."""
import sys, os, re
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
import glob

d, fn, var, rules = sys.argv[1:5]
out = sys.argv[5] if len(sys.argv) > 5 else None
body, brace = F.load(d, fn)
first = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    for i, l in enumerate(open(pf).read().split('\n')):
        m = re.match(r'^/\* (\S+) @ 0x', l)
        if m and m.group(1) == fn: first = i + 1
    if first: break
nodes, entry = F.build_cfg(body, brace)
ws, er = F.webs(nodes, entry, var)
R = []
for l in open(rules):
    if not l.strip() or l.startswith('#'): continue
    c = l.rstrip('\n').split('\t')
    R.append((c[0], re.compile(c[1]), c[2] if len(c) > 2 else ''))
DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
OPEN = re.compile(r'\b%s\b' % re.escape(var))
EV = {n.lstrip('~'): e for n, _, e in R}


def rule_for(t):
    for n, rx, ev in R:
        if rx.search(t): return n
    return None


def fmt(lines, tail=None, head=None):
    """ranges as seg.py wants them (file lines); tail = last line index taken only on its rhs, head = first line index taken only on its lhs"""
    out = []
    for (a, b) in F.runs(lines):
        s = '%d' % (first + a) if a == b else '%d-%d' % (first + a, first + b)
        if head is not None and a == head: s = (s.split('-')[0] if True else s)
        out.append((a, b))
    res = []
    for (a, b) in out:
        r = '%d-%d' % (first + a, first + b) if a != b else '%d' % (first + a)
        if head is not None and a == head: r += ':first=lhs'
        if tail is not None and b == tail: r += ':last=rhs'
        res.append(r)
    return res


by = {}; bad = []
for k, ls in enumerate(ws):
    if not any(OPEN.search(F.CURRENT[x]) for x in ls): continue
    ls = sorted(ls)
    defs = []
    for x in ls:
        m = DEF.search(body[x])
        if m: defs.append((x, m.group(1)))
    desc = ','.join('%d-%d' % r if r[0] != r[1] else str(r[0]) for r in F.runs(ls))
    if not defs:
        print('web %2d %-26s lines %s' % (k, 'ENTRY', desc)); bad.append(k); continue
    names = [rule_for(t) for _, t in defs]
    strong = {n for n in names if n is not None and not n.startswith('~')}
    if None not in names and len(strong) == 1 and len(set(names)) > 1 and not (len(defs) == 2 and OPEN.search(defs[1][1])):
        names = [next(iter(strong))] * len(names)       # weak defs (rule names starting with ~: a default 0 ...) join the web's one strong role
    names = [n.lstrip('~') if n else n for n in names]
    if len(set(names)) == 1 and names[0] is not None:
        print('web %2d %-26s lines %s' % (k, names[0], desc))
        by.setdefault(names[0], []).extend(fmt(ls)); continue
    if len(defs) == 2 and None not in names and OPEN.search(defs[1][1]):
        L = defs[1][0]
        A = [x for x in ls if x <= L]; B = [x for x in ls if x >= L]
        print('web %2d %-26s lines %s  [chain at %d]' % (k, names[0] + '>' + names[1], desc, first + L))
        by.setdefault(names[0], []).extend(fmt(A, tail=L))
        by.setdefault(names[1], []).extend(fmt(B, head=L)); continue
    print('web %2d %-26s lines %s | %s' % (k, 'UNHANDLED:' + ','.join(str(n) for n in names), desc, ' || '.join(t[:50] for _, t in defs[:3])))
    bad.append(k)
if out:
    with open(out, 'a') as f:
        for n, rg in by.items():
            f.write('%s\t%s\t%s\t%s\tINFERRED\t%s\n' % (fn, var, n, ','.join(rg), EV[n]))
print('unhandled webs:', bad)
