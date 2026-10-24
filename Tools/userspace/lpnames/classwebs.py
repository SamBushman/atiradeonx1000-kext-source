#!/usr/bin/env python3
"""classwebs.py DIR FN VAR RULES [SPECOUT]

Classify the def-use webs of VAR (Ghidra's original name; renames of FN are taken back) by what their DEFINITIONS assign, so one reused
variable can be split into per-role names without listing webs by hand.

RULES: file with lines  NAME<TAB>REGEX<TAB>EVIDENCE  (REGEX is searched in the text of every `VAR = ...` definition line of a web; first rule
that matches ALL definition texts of the web wins; a web whose definitions match different rules is MIXED; a web with no definition is ENTRY).
Webs whose lines no longer mention VAR in the current text (an earlier `use` row renamed them) are skipped.
Prints the classification (web, lines, def texts). With SPECOUT, writes `VAR<TAB>webs<TAB>NAME<TAB>INFERRED<TAB>EVIDENCE` lines for emit_webs.py
(rows only for fully classified webs; MIXED / unmatched webs are listed and must be handled by the caller).
"""
import sys, os, re
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F

d, fn, var, rules = sys.argv[1:5]
out = sys.argv[5] if len(sys.argv) > 5 else None
body, brace = F.load(d, fn)
nodes, entry = F.build_cfg(body, brace)
ws, er = F.webs(nodes, entry, var)
R = []
for l in open(rules):
    if not l.strip() or l.startswith('#'): continue
    c = l.rstrip('\n').split('\t')
    R.append((c[0], re.compile(c[1]), c[2] if len(c) > 2 else ''))
DEF = re.compile(r'(?<![\w.>])%s\s*=(?!=)\s*(.*)' % re.escape(var))
by = {}; bad = []
OPEN = re.compile(r'\b%s\b' % re.escape(var))
for k, ls in enumerate(ws):
    if not any(OPEN.search(F.CURRENT[x]) for x in ls): continue   # already named in the current text (earlier use rows)
    defs = []
    for x in ls:
        for m in DEF.finditer(body[x]): defs.append(m.group(1))
    names = set()
    for t in defs:
        hit = [n for n, rx, ev in R if rx.search(t)]
        names.add(hit[0] if hit else None)
    if not defs: tag = 'ENTRY'
    elif len(names) == 1 and None not in names: tag = names.pop()
    elif None in names and len(names) == 1: tag = '?'
    else: tag = 'MIXED:' + ','.join(sorted(str(n) for n in names))
    print('web %2d %-26s lines %s  | %s' % (k, tag, ','.join('%d-%d' % r if r[0] != r[1] else str(r[0]) for r in F.runs(ls)), ' || '.join(t[:50] for t in defs[:3])))
    if tag in {n for n, _, _ in R}: by.setdefault(tag, []).append(k)
    else: bad.append(k)
if out:
    ev = {n: e for n, _, e in R}
    with open(out, 'a') as f:
        for n, l in by.items(): f.write('%s\t%s\t%s\tINFERRED\t%s\n' % (var, ','.join(map(str, l)), n, ev[n]))
print('unhandled webs:', bad)
