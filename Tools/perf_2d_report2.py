#!/usr/bin/env python3
"""perf_2d_report2.py DIR [--aa] [--margin 0.10] [-o report.md] - three-way verdicts for the stock-vs-rebuilt desktop-compositing data of Tools/perf_2d_compare.sh
(Tests/perf_2d_comparability_plan.md). Per metric the unit of replication is the VISIT (hot-swap + unstick state) with its runs nested inside, never the tick (ticks are autocorrelated).
Metrics: the per-run medians of every `scenario.{a,b,c,d}` METRIC line, plus, when the per-run .raw dumps exist, whole-animation readouts derived from the per-tick samples:
`.sum` (sum over the scenario's ticks), `.peak` (max), `.active` (ticks above an idle threshold = the idle median x 1.5 of the same run, a duration-like readout).
Ratio = median(candidate)/median(reference) with a 90 % hierarchical-bootstrap CI (resample visits, then runs within a visit, 4000 draws).
  EQUIVALENT    CI inside [1-margin, 1+margin]            DIFFERENT     CI excludes 1.0 and is not inside the margin band (or lies wholly outside it)
  INCONCLUSIVE  anything else (more/better data needed)   ZERO          both sides all-zero (nothing flushed)
--aa : stock vs stock (odd visits vs even visits). The test is only trustworthy for a metric if A/A says EQUIVALENT for it.
Exit status 0 always (it is a report); the table is the artifact."""
import re, glob, os, sys, random, statistics as st
args = sys.argv[1:]; AA = '--aa' in args
margin = float(args[args.index('--margin') + 1]) if '--margin' in args else 0.10
out = args[args.index('-o') + 1] if '-o' in args else None
d = [a for a in args if not a.startswith('-')][0]
M = re.compile(r'^METRIC (\S+) n=\d+ min=[\d.]+ p10=[\d.]+ median=([\d.]+)')
def runs_of(tag):
    """-> {visit: [ {metric: value} per run ]}"""
    res = {}
    for f in sorted(glob.glob(os.path.join(d, tag + '_v*_r*.txt'))):
        v = int(re.search(r'_v(\d+)_r', f).group(1)); m = {}
        for l in open(f):
            r = M.match(l)
            if r: m[r.group(1)] = float(r.group(2))
        raw = f[:-4] + '.raw'
        if os.path.exists(raw):
            ser = {}
            for l in open(raw):
                p = l.split()
                if len(p) == 6: ser.setdefault(p[0], []).append([float(x) for x in p[2:]])
            idle = ser.get('idle')
            for sc, rows in ser.items():
                for k, name in enumerate('abcd'):
                    col = [r[k] for r in rows]
                    m['%s.%s.sum' % (sc, name)] = sum(col); m['%s.%s.peak' % (sc, name)] = max(col)
                    if idle:
                        thr = st.median([r[k] for r in idle]) * 1.5
                        if thr > 0: m['%s.%s.active' % (sc, name)] = float(sum(1 for x in col if x > thr))
        if m: res.setdefault(v, []).append(m)
    return res
if AA:
    s = runs_of('stock'); A = {v: r for v, r in s.items() if v % 2 == 1}; B = {v: r for v, r in s.items() if v % 2 == 0}
else:
    A, B = runs_of('stock'), runs_of('rebuilt')
names = sorted(set(k for v in A.values() for r in v for k in r) & set(k for v in B.values() for r in v for k in r))
rng = random.Random(1234)
def stat(side, name):
    vals = [r[name] for v in side.values() for r in v if name in r]
    return st.median(vals) if vals else None
def boot(side, name):
    vs = [v for v in side if any(name in r for r in side[v])]
    draw = []
    for v in (rng.choice(vs) for _ in vs):
        rs = [r[name] for r in side[v] if name in r]
        draw += [rng.choice(rs) for _ in rs]
    return st.median(draw)
rows = []
for n in names:
    a, b = stat(A, n), stat(B, n)
    if not a and not b and a is not None and b is not None and a == 0 and b == 0:
        rows.append((n, 0, 0, None, None, None, 'ZERO')); continue
    if not a:
        rows.append((n, a, b, None, None, None, 'INCONCLUSIVE')); continue
    rat = []
    for _ in range(4000):
        x, y = boot(A, n), boot(B, n)
        if x: rat.append(y / x)
    rat.sort(); lo, hi = rat[int(len(rat) * 0.05)], rat[int(len(rat) * 0.95)]
    if lo >= 1 - margin and hi <= 1 + margin: v = 'EQUIVALENT'
    elif lo > 1 or hi < 1:
        v = 'DIFFERENT' if (hi < 1 - margin or lo > 1 + margin or b / a > 1 + margin or b / a < 1 - margin) else 'INCONCLUSIVE'
    else: v = 'INCONCLUSIVE'
    rows.append((n, a, b, b / a, lo, hi, v))
nv = lambda s: len(s); nr = lambda s: sum(len(x) for x in s.values())
lines = ['Mode: %s; margin +-%.0f %%; reference side: %d visits / %d runs, candidate side: %d visits / %d runs\n' % ('A/A (stock odd vs even visits)' if AA else 'stock vs rebuilt', margin * 100, nv(A), nr(A), nv(B), nr(B)),
         '| metric | reference | candidate | ratio | 90 % CI | verdict |', '|---|---:|---:|---:|---|---|']
for n, a, b, r, lo, hi, v in rows:
    lines.append('| %s | %s | %s | %s | %s | %s |' % (n, '%.4g' % a if a is not None else '-', '%.4g' % b if b is not None else '-', '%.3f' % r if r else '-', '[%.3f, %.3f]' % (lo, hi) if lo is not None else '-', v))
cnt = {}
for r in rows: cnt[r[6]] = cnt.get(r[6], 0) + 1
lines.append('\n%d metrics: %s' % (len(rows), cnt))
t = '\n'.join(lines); print(t)
if out: open(out, 'w').write(t + '\n')
