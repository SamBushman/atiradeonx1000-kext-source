#!/usr/bin/env python3
"""fctiw_oracle.py STOCK_DIS RANGES.tsv REBUILT_OTOOL.txt [N] - per-function count of float -> integer conversion instructions (fctiw / fctiwz), stock vs rebuilt (issue #68).

A real float -> integer conversion needs one fctiw* instruction in the stock; a float stored as a word (`stfs` into a location Ghidra typed unsigned) needs none. Ghidra prints both as
`(uint)fVar`, and C converts the value in both cases - so a rebuilt function with MORE fctiw* than the stock has bit stores that became conversions (GLDriver FUN_000353a0's packet writer,
GA radeonFill: 0 in the stock, 36 rebuilt). Fewer is normal where Ghidra merged duplicate conversions; a small surplus is normal where it printed one conversion several times.
  STOCK_DIS       `otool -tV` (+ `-s __TEXT __textcoal_nt -v`) of the stock image, as in link/*.dis
  RANGES.tsv      the dump's RANGES.tsv (entry, name, kind, lo-hi;...)
  REBUILT_OTOOL   `otool -tV rebuilt.out | grep -E 'fctiw|^[_A-Za-z]'` (run on the G5)
Prints the functions whose counts differ (MORE = rebuilt has more)."""
import sys, re, bisect
dis, ranges, reb_f = sys.argv[1:4]; lim = int(sys.argv[4]) if len(sys.argv) > 4 else 60
stock = sorted(int(m.group(1), 16) for m in (re.match(r'([0-9a-f]{8})\tfctiw', l) for l in open(dis, errors='replace')) if m)
reb = {}; cur = None
for l in open(reb_f, errors='replace'):
    l = l.rstrip('\n')
    if re.match(r'[0-9a-f]{8}\t', l) or l.startswith('\t'):
        if 'fctiw' in l and cur: reb[cur] = reb.get(cur, 0) + 1
    else:
        m = re.match(r'^(\S+):$', l)
        if m: cur = m.group(1); reb.setdefault(cur, 0)
rows = []
for l in open(ranges):
    p = l.rstrip('\n').split('\t')
    if len(p) < 4 or p[2] != 'fn': continue
    s = 0
    for r in p[3].split(';'):
        if r:
            a, b = (int(x, 16) for x in r.split('-')); s += bisect.bisect_left(stock, b) - bisect.bisect_left(stock, a)
    rn = next((c for c in (p[1], '_' + p[1], p[1].lstrip('_')) if c in reb), None)
    rows.append((p[1], p[0], s, reb.get(rn) if rn else None))
more = [r for r in rows if r[3] is not None and r[3] > r[2]]; less = [r for r in rows if r[3] is not None and r[3] < r[2]]
print('functions %d, with a rebuilt symbol %d: rebuilt MORE %d, LESS %d' % (len(rows), sum(1 for r in rows if r[3] is not None), len(more), len(less)))
for r in sorted(more, key=lambda r: r[3] - r[2], reverse=True)[:lim]: print('  MORE', r)
for r in less[:lim]: print('  LESS', r)
