#!/usr/bin/env python3
"""game_fps_report.py OUTDIR - stock-vs-rebuilt report for Tools/gamefps/ut2004_compare.sh results.

OUTDIR/<side>_v<visit>/<map>_<preset>/{avgfps.log,stats.csv}. Per map x preset and side it computes, over visits:
avg FPS (game's own "min / avg / max fps" line, cross-checked against frames/time from stats.csv), min FPS, p10/p90 frame time and max stall (from the
per-frame stats.csv, first column = frame ms). Verdict per metric, perf_compare.py style: REGRESSION when the rebuilt side is worse than stock by more
than max(5 %, 3x stock run-to-run noise) (noise = stdev/mean over the stock visits); NOISY when the stock noise itself exceeds 5 %; else OK.
"""
import sys, os, re, csv, glob, statistics as st

def load(d):
    r = {}
    try:
        t = open(os.path.join(d, 'avgfps.log')).read()
        m = re.search(r'([\d.]+) / ([\d.]+) / ([\d.]+) fps', t)
        r['min'], r['avg'], r['max'] = map(float, m.groups())
        r['score'] = float(re.search(r'Score = ([\d.]+)', t).group(1))
    except Exception:
        return None
    try:
        rows = list(csv.reader(open(os.path.join(d, 'stats.csv'))))
        h = [i for i, x in enumerate(rows) if x and x[0].startswith('Frame Frame')][0]
        ms = sorted(float(x[0]) for x in rows[h + 1:] if x)
        n = len(ms); tot = sum(ms)
        r['csv_avg'] = 1000.0 * n / tot; r['frames'] = n
        r['p10'] = ms[int(n * .10)]; r['p90'] = ms[int(n * .90)]; r['stall'] = ms[-1]
    except Exception:
        pass
    return r

def main(o):
    res = {}
    for d in sorted(glob.glob(os.path.join(o, '*_v*', '*'))):
        side, v = os.path.basename(os.path.dirname(d)).rsplit('_v', 1)
        r = load(d)
        if r: res.setdefault(os.path.basename(d), {}).setdefault(side, []).append(r)
    # metric: (key, higher_is_better)
    M = [('avg', True), ('min', True), ('p90', False), ('stall', False)]
    bad = 0
    for k in sorted(res):
        s, b = res[k].get('stock', []), res[k].get('rebuilt', [])
        print('== %s  (stock n=%d, rebuilt n=%d)' % (k, len(s), len(b)))
        if not s or not b: print('   incomplete'); continue
        for key, hib in M:
            sv = [x[key] for x in s if key in x]; bv = [x[key] for x in b if key in x]
            if not sv or not bv: continue
            sm, bm = st.mean(sv), st.mean(bv)
            noise = (st.stdev(sv) / sm) if len(sv) > 1 else 0.0
            tol = max(0.05, 3 * noise)
            delta = (bm - sm) / sm if hib else (sm - bm) / sm   # >0 means rebuilt better
            if delta < -tol: v = 'REGRESSION'; bad += 1
            elif noise > 0.05: v = 'NOISY'
            else: v = 'OK'
            print('   %-6s stock %9.2f  rebuilt %9.2f  delta %+6.1f%%  tol %4.1f%%  noise %4.1f%%  %s' % (key, sm, bm, delta * 100, tol * 100, noise * 100, v))
        ck = [abs(x['csv_avg'] - x['avg']) / x['avg'] for x in s + b if 'csv_avg' in x]
        if ck: print('   avg-fps cross-check (csv vs game line): worst %.1f%%' % (max(ck) * 100))
    print('REGRESSIONS: %d' % bad)
    return 1 if bad else 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1]))
