#!/usr/bin/env python3
"""return_code_audit.py  (issue #100 criterion 2; run from the repo root)
For every external-method section of Tests/deep_paths.md, lists the IOReturn constants the SHIPPED body can produce and which of them were observed live on
STOCK in the two recorded baselines (Tests/baseline/stock_4.1.9_g5_tiger.txt, ..._deep.txt). A baseline line is attributed to a method when it names the context
and the method (`GL set_surface`, `DVD dvd_enable_deint`, `Surface set_id_mode`) or its `(sel N)`; codes are read from `r=0x........` / `-> 0x........`.
Heuristic attribution: every row printed as UNOBSERVED must be justified by hand in Tests/deep_paths_notes.tsv (`<row> codes ...`)."""
import re, sys
doc = open('Tests/deep_paths.md').read()
lines = []
for f in ('Tests/baseline/stock_4.1.9_g5_tiger.txt', 'Tests/baseline/stock_4.1.9_g5_tiger_deep.txt'):
    lines += [l.rstrip('\n') for l in open(f)]
notes = {}
for l in open('Tests/deep_paths_notes.tsv'):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 3 and p[1] == 'codes': notes[p[0]] = p[2]
ctxname = {'GL': 'GL', '2D': '2D', 'DVD': 'DVD', 'Surface': 'Surface'}
sec = re.split(r'\n## ', doc)[1:]
tot = unobs = 0
for s in sec:
    m = re.match(r'(GL|2D|DVD|Surface) sel (\d+) - `[^:]*::(\w+)`', s)
    if not m: continue
    ctx, sel, name = m.group(1), m.group(2), m.group(3)
    if 'IOReturn constants in the shipped body: (none' in s: consts = set()
    else:
        c = re.search(r'IOReturn constants in the shipped body: ([^\n]*)', s)
        consts = set(re.findall(r'0x[0-9a-f]{8}', c.group(1))) if c else set()
    seen = set()
    for l in lines:
        if ctx in l and (name in l or ('(sel %s)' % sel) in l or ('sel %s,' % sel) in l or ('sel %s ' % sel) in l):
            seen |= set(re.findall(r'(?:r=|-> )(0x[0-9a-f]{8})', l))
    row = '%s %s' % (ctx, sel)
    tot += 1
    miss = sorted(consts - seen)
    if miss and row not in notes:
        unobs += 1
        print('UNOBSERVED %-12s %-34s shipped %s observed %s' % (row, name, sorted(consts), sorted(seen)))
print('return_code_audit: %d methods, %d with shipped codes not observed live and not justified in the notes' % (tot, unobs))
