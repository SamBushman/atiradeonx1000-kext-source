#!/usr/bin/env python3
"""fixalias2.py DIR PARTLO PARTHI OUTSPEC [--apply] : like fixalias.py but undoes the whole-function `arena` / `allocation` rows of mixed variables with
prep.py (it reverts text and every dependent row, so later rows anchored on the variable keep working), and writes the per-web rows for the webs that really
are the arena / an allocation as a gspec file (W lines). The remaining webs return to Ghidra's placeholder name. Run gspec + apply_names afterwards."""
import sys, os, re, glob, collections, subprocess
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, lo, hi, out = sys.argv[1], int(sys.argv[2]), int(sys.argv[3]), sys.argv[4]
apply = '--apply' in sys.argv
H = re.compile(r'^/\* (\S+) @ 0x')
mine = set()
for p in range(lo, hi + 1):
    for l in open('%s/part_%03d.c' % (d, p), errors='replace'):
        m = H.match(l)
        if m: mine.add(m.group(1))
GOOD = {'arena': re.compile(r'COMP_arena[AB]|\+ 0x37[48]\)'), 'allocation': re.compile(r'FUN_00193e18\(|Arena__alloc\(')}
S = os.path.dirname(os.path.abspath(__file__))
by = collections.defaultdict(list)
for f in sorted(glob.glob(d + '/names*.tsv')):
    for l in open(f):
        c = l.rstrip('\n').split('\t')
        if c[0] == 'local' and c[1] in mine and c[3] in GOOD and len(c) >= 6: by[c[1]].append(c)
plan = []
for fn, rs in by.items():
    try: body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException: continue
    for c in rs:
        old, new = c[2], c[3]
        try: ws, er = F.webs(nodes, entry, old)
        except BaseException: continue
        good = []; other = 0
        for k, w in enumerate(ws):
            ls = sorted(w)
            df = [l for l in ls if re.search(r'(?<![\w.>*\]])%s\s*=(?!=)' % re.escape(old), body[l])]
            if df and all(GOOD[new].search(body[l].split('=', 1)[1]) for l in df if '=' in body[l]): good.append(k)
            else: other += 1
        if other: plan.append((fn, old, new, good, c[5]))
print(len(plan), 'mixed variables')
lines = []
for fn, old, new, good, ev in plan:
    print(fn, old, new, good)
    if not apply: continue
    r = subprocess.run([sys.executable, '-I', os.path.join(S, 'prep.py'), d, fn, old], capture_output=True, text=True)
    if 'function not found' in r.stdout + r.stderr: print('  PREP FAILED', (r.stdout + r.stderr).strip()[:80]); continue
    if good: lines.append('W|%s|%s|%s|%s|%s' % (fn, old, ','.join(map(str, good)), new, ev.replace('|', '/')))
if apply: open(out, 'w').write('\n'.join(lines) + '\n')
