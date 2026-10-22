#!/usr/bin/env python3
"""game_fps_report_d3.py OUTDIR - stock-vs-rebuilt report for Tools/gamefps/doom3_run_side.sh results.

OUTDIR/<side>_r<round>/<res>_<preset>_<demo>/out.txt contains dhewm3's "N frames rendered in X seconds = Y fps" line (timedemo). Per resolution x preset x demo
and side, mean FPS over rounds; REGRESSION when rebuilt is slower than stock by more than max(5 %, 3x stock run-to-run noise) (noise = stdev/mean over the
stock rounds), NOISY when the stock noise itself exceeds 5 %, else OK. Frame count must be identical on both sides (a demo that renders a different number of
frames is not the same workload).
"""
import sys, os, re, glob, statistics as st

def load(d):
    try:
        t = open(os.path.join(d, 'out.txt'), errors='replace').read()
    except OSError:
        return None
    m = re.findall(r'(\d+) frames rendered in ([\d.]+) seconds = ([\d.]+) fps', t)
    if not m:
        return None
    n, sec, fps = m[-1]
    return {'frames': int(n), 'sec': float(sec), 'fps': float(fps)}

def main(o):
    res = {}
    for d in sorted(glob.glob(os.path.join(o, '*_r*', '*'))):
        side = os.path.basename(os.path.dirname(d)).rsplit('_r', 1)[0]
        r = load(d)
        if r: res.setdefault(os.path.basename(d), {}).setdefault(side, []).append(r)
    bad = 0
    for k in sorted(res):
        s, b = res[k].get('stock', []), res[k].get('rebuilt', [])
        print('== %s  (stock n=%d, rebuilt n=%d)' % (k, len(s), len(b)))
        if not s or not b: print('   incomplete'); continue
        fs = {x['frames'] for x in s + b}
        if len(fs) != 1: print('   FRAME COUNT DIFFERS %s' % sorted(fs)); bad += 1
        sv = [x['fps'] for x in s]; bv = [x['fps'] for x in b]
        sm, bm = st.mean(sv), st.mean(bv)
        noise = (st.stdev(sv) / sm) if len(sv) > 1 else 0.0
        tol = max(0.05, 3 * noise); delta = (bm - sm) / sm
        if delta < -tol: v = 'REGRESSION'; bad += 1
        elif noise > 0.05: v = 'NOISY'
        else: v = 'OK'
        print('   fps  stock %7.2f  rebuilt %7.2f  delta %+6.1f%%  tol %4.1f%%  noise %4.1f%%  %s' % (sm, bm, delta * 100, tol * 100, noise * 100, v))
    print('REGRESSIONS: %d' % bad)
    return 1 if bad else 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1]))
