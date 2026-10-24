#!/usr/bin/env python3
"""casename.py DIR FN SPEC [SPECOUT]

Names the def-use webs of placeholder variables that lie INSIDE a line range of FN (typically one `case` of a big switch), for variables whose role differs
from case to case. SPEC lines (tab separated, '#' comment):
    START-END<TAB>VAR<TAB>NAME<TAB>EVIDENCE[<TAB>DEFREGEX]
START/END are FILE lines of the current tree; VAR is Ghidra's name of the variable. Every web of VAR whose lines ALL lie in START..END (and, when DEFREGEX is
given, whose definition right-hand sides all match it) gets NAME; webs that straddle the range are listed and skipped (they need their own handling). Output
is a seg.py spec (`FN VAR NAME RANGES TIER EVIDENCE`), appended to SPECOUT or printed. Run uniq_names.py on the result before seg.py."""
import sys, os, re, glob
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F

d, fn, spec = sys.argv[1:4]
out = sys.argv[4] if len(sys.argv) > 4 else None
body, brace = F.load(d, fn)
first = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    for i, l in enumerate(open(pf).read().split('\n')):
        m = re.match(r'^/\* (\S+) @ 0x', l)
        if m and m.group(1) == fn: first = i + 1
    if first: break
nodes, entry = F.build_cfg(body, brace)
cache = {}
res = []
for l in open(spec):
    if not l.strip() or l.startswith('#'): continue
    c = l.rstrip('\n').split('\t')
    rg, var, name, ev = c[:4]
    rx = re.compile(c[4]) if len(c) > 4 else None
    a, _, b = rg.partition('-'); a = int(a) - first; b = int(b) - first
    if var not in cache:
        try: cache[var] = F.webs(nodes, entry, var)[0]
        except (Exception, SystemExit) as e: print('# %s: %s' % (var, str(e)[:70])); cache[var] = []
    DEF = re.compile(r'(?<![\w.>*])%s\s*=(?!=)\s*(.*)' % re.escape(var))
    ranges = []
    for k, ls in enumerate(cache[var]):
        ls = sorted(ls)
        if not any(re.search(r'\b%s\b' % re.escape(var), F.CURRENT[x]) for x in ls): continue      # already renamed
        if ls[0] < a or ls[-1] > b:
            if any(a <= x <= b for x in ls): print('# %s web %d straddles %s (lines %d-%d)' % (var, k, rg, first + ls[0], first + ls[-1]))
            continue
        if rx:
            defs = [DEF.search(body[x]).group(1) for x in ls if DEF.search(body[x])]
            if not defs or not all(rx.search(t) for t in defs): continue
        for (x, y) in F.runs(ls):
            ranges.append('%d-%d' % (first + x, first + y) if x != y else '%d' % (first + x))
    if ranges:
        res.append('%s\t%s\t%s\t%s\tINFERRED\t%s' % (fn, var, name, ','.join(ranges), ev))
        print('%s %s -> %s (%d runs)' % (rg, var, name, len(ranges)))
    else:
        print('# nothing for %s %s' % (rg, var))
if out:
    with open(out, 'a') as f: f.write('\n'.join(res) + ('\n' if res else ''))
