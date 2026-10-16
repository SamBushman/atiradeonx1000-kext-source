#!/usr/bin/env python3
"""perf_2d_report.py DIR [-o REPORT] - compare the interleaved stock/rebuilt runs written by Tools/perf_2d_compare.sh (files stock_v*_r*.txt / rebuilt_v*_r*.txt of
Tests/perf_2d_compositing.c METRIC lines). Same decision rule as Tools/perf_compare.py: per metric S = median over stock runs of the run median, noise = (max-min of those)/S,
margin = max(5 %, 3 x noise), NOISY if margin > 25 %; REGRESSION / IMPROVED when the candidate median is outside S*(1+-margin). Raw CGSGetPerformanceData values: HIGHER = more
flush activity per tick, so a LOWER candidate on a drag/resize/scroll metric means the rebuilt desktop redrew less (reported as LOWER, not as an improvement). Exit 1 on any REGRESSION/LOWER."""
import re, glob, os, sys, statistics
d = sys.argv[1]; out = sys.argv[sys.argv.index('-o') + 1] if '-o' in sys.argv else None
R = re.compile(r'^METRIC (\S+) n=(\d+) min=([\d.]+) p10=([\d.]+) median=([\d.]+) p90=([\d.]+) max=([\d.]+)')
def load(tag):
    runs = []
    for f in sorted(glob.glob(os.path.join(d, tag + '_v*_r*.txt'))):
        m = {}
        for l in open(f):
            r = R.match(l)
            if r: m[r.group(1)] = float(r.group(5))
        runs.append(m)
    return runs
S, C = load('stock'), load('rebuilt')
names = sorted(set(k for r in S for k in r) & set(k for r in C for k in r))
rows = []; bad = 0
for n in names:
    s = [r[n] for r in S if n in r]; c = [r[n] for r in C if n in r]
    sm, cm = statistics.median(s), statistics.median(c)
    noise = (max(s) - min(s)) / sm if sm else 0
    margin = max(0.05, 3 * noise)
    if margin > 0.25: v = 'NOISY'
    elif cm > sm * (1 + margin): v = 'HIGHER'
    elif cm < sm * (1 - margin): v = 'LOWER'
    else: v = 'OK'
    if v == 'LOWER': bad += 1
    rows.append((n, sm, cm, (cm / sm - 1) * 100 if sm else 0, noise * 100, margin * 100, v))
lines = ['| metric | stock median | rebuilt median | delta | stock noise | margin | verdict |', '|---|---:|---:|---:|---:|---:|---|']
for n, sm, cm, dl, nz, mg, v in rows: lines.append('| %s | %.3f | %.3f | %+.1f %% | %.1f %% | %.1f %% | %s |' % (n, sm, cm, dl, nz, mg, v))
cnt = {v: sum(1 for r in rows if r[6] == v) for v in ('OK', 'NOISY', 'HIGHER', 'LOWER')}
lines.append('\n%d metrics, %d stock runs, %d rebuilt runs: %s' % (len(rows), len(S), len(C), cnt))
t = '\n'.join(lines); print(t)
if out: open(out, 'w').write(t + '\n')
sys.exit(1 if bad else 0)
