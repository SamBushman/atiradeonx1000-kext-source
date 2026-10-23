#!/usr/bin/env python3
"""rng.py DIR FN SPEC : like emit_webs.py but the WEBS column is explicit file-line ranges (as printed by orig.py), e.g. `2862-2870,2900`; `*` = whole function (local row).
SPEC line: VAR<TAB>RANGES<TAB>new<TAB>tier<TAB>evidence. Only lines of the ranges that mention VAR (Ghidra text) are renamed, grouped in runs of consecutive such lines.
Prints `use`/`local` rows for apply_names.py."""
import sys, os, re
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, fn, spec = sys.argv[1:4]
body, brace = F.load(d, fn)
# file line of body[0]
import glob
first = None
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    L = open(pf).read().split('\n')
    for i, l in enumerate(L):
        if l.startswith('/* ') and re.match(r'^/\* (\S+) @ 0x', l) and re.match(r'^/\* (\S+) @ 0x', l).group(1) == fn:
            first = i + 1; break   # 1-based file line of body[0] (the "/* name @" comment line itself)
    if first: break
rows = []
for l in open(spec):
    if not l.strip() or l.startswith('#'): continue
    var, rg, new, tier, ev = l.rstrip('\n').split('\t')[:5]
    if rg == '*':
        rows.append('local\t%s\t%s\t%s\t%s\t%s' % (fn, var, new, tier, ev)); continue
    idx = []; side = 'all'
    if rg and rg[-1] in 'LR' and ',' not in rg and '-' not in rg: side = {'L': 'lhs', 'R': 'rhs'}[rg[-1]]; rg = rg[:-1]
    for part in rg.split(','):
        a, _, b = part.partition('-'); a = int(a); b = int(b) if b else a
        for ln in range(a, b + 1):
            i = ln - first
            if 0 <= i < len(body) and re.search(r'\b%s\b' % re.escape(var), body[i]) and i > brace: idx.append(i)
    if not idx: print('# no lines for', var, rg, file=sys.stderr); continue
    for (x, y) in F.runs(sorted(set(idx))):
        txt = body[x].strip()
        eq = [i for i in range(brace + 1, len(body)) if body[i].strip() == txt]
        nth = eq.index(x) + 1
        frm = '^\\s*' + re.escape(txt) + '$' + ('@%d' % nth if nth > 1 else '')
        rows.append('use\t%s\t%s\t%s\t%s\t%s\t%s\t+%d%s' % (fn, var, new, tier, ev, frm, y - x + 1, '' if side == 'all' else '\t%s\tnone' % side))
print('\n'.join(rows))
