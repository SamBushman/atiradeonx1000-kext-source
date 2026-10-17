#!/usr/bin/env python3
"""parity_check.py - the gate for a rename / variable-split batch: the functions must keep the stock driver's behaviour, but their compiled bytes may change.

Usage (from the root of the tree under test; the baseline is a git revision, normally HEAD, and the working tree is the candidate):
    parity_check.py [--base REV] [--tag TAG] [--max-slowdown 0.03] FILTER [FILTER ...]
Each FILTER is a substring of a difftest case name (e.g. 'ATIR500Surface::build_swap'); give every function whose source the batch touches.
Env as for Tools/difftest/build_rebuilt.sh (STOCK_KEXT, PYTHONPATH for unicorn); the G5 builds both images (WORK/REBUILT paths are made from TAG).

Checks, per function:
  1. difftest against stock PASSES for the candidate image: same calls (callee, arguments, order), same non-local writes, same return value, same
     hardware register reads/writes (offset, width, bytes, order) - the cases in Tests/difftest, which must cover the changed code (coverage may not drop);
  2. execution speed: the estimated cycles of the candidate, on the same inputs, may not exceed the baseline's by more than --max-slowdown (default 3 %);
  3. no value flows across a split: the candidate is compiled with -Wuninitialized and may not produce a "may be used uninitialized" warning that the
     baseline does not produce (the byte-identical build used to prove this implicitly; with bytes allowed to change, gcc's dataflow check replaces it).
Exit 0 = all pass; 1 = some check failed (printed); 2 = a build failed.
"""
import argparse, json, os, re, subprocess, sys, tempfile, shutil


def sh(cmd, **kw):
    return subprocess.run(cmd, shell=True, capture_output=True, text=True, **kw)


def build(tree, out, work, env_extra):
    env = dict(os.environ, WORK=work, REBUILT_KEXT=out, WARN='-Wuninitialized', **env_extra)
    r = subprocess.run(['sh', 'Tools/difftest/build_rebuilt.sh'], cwd=tree, env=env, capture_output=True, text=True)
    if r.returncode != 0:
        print(r.stdout[-1500:], r.stderr[-800:]); sys.exit(2)


def warnings(logpath):
    out = {}
    for ln in open(logpath, errors='replace'):
        m = re.match(r'^(.*?):(\d+): warning: (.*)$', ln)
        if m and 'uninitialized' in m.group(3): out.setdefault((os.path.basename(m.group(1)), m.group(3)), 0)
        if m and 'uninitialized' in m.group(3): out[(os.path.basename(m.group(1)), m.group(3))] += 1
    return out


def run_cases(image, filters, tag, which):
    res = {}
    cases = sh('sed -n "s/.*difftest.py[^\\n]*\\(Tests\\/difftest.*\\)$/\\1/p" Tests/difftest/run_all.sh').stdout.split()
    cases = [c for c in cases if c.endswith('.py')]
    for f in filters:
        js = tempfile.NamedTemporaryFile(suffix='.json', delete=False).name
        sh('python3 Tools/difftest/difftest.py -j 8 --rebuilt %s -f %s --json %s %s' % (image, "'%s'" % f, js, ' '.join(cases)))
        try: data = json.load(open(js))
        except Exception: data = []
        os.unlink(js)
        for d in data: res[d['case']] = d
    return res


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--base', default='HEAD'); ap.add_argument('--tag', default='parity'); ap.add_argument('--max-slowdown', type=float, default=0.03)
    ap.add_argument('filters', nargs='+')
    a = ap.parse_args()
    ev = os.path.expanduser('~/g5logs/parity_%s' % a.tag); os.makedirs(ev, exist_ok=True)
    sha = sh('git rev-parse %s' % a.base).stdout.strip()
    base_img = os.path.join(ev, 'base_%s.bin' % sha[:10])
    if not os.path.exists(base_img):
        t = tempfile.mkdtemp()
        sh('git archive %s | tar -x -C %s' % (a.base, t))
        os.makedirs(os.path.join(t, 'build/difftest'), exist_ok=True)
        build(t, base_img, 'rung3/parity_%s_base' % a.tag, {}); shutil.rmtree(t)
    cand_img = os.path.join(ev, 'cand.bin')
    build('.', cand_img, 'rung3/parity_%s_cand' % a.tag, {})
    bad = []
    wb, wc = warnings(base_img[:-4] + '.err'), warnings(cand_img[:-4] + '.err')
    for k, n in wc.items():
        if n > wb.get(k, 0): bad.append('NEW uninitialized warning (%d vs %d): %s: %s' % (n, wb.get(k, 0), k[0], k[1]))
    rb, rc = run_cases(base_img, a.filters, a.tag, 'base'), run_cases(cand_img, a.filters, a.tag, 'cand')
    if not rc: bad.append('no difftest case matched %s' % a.filters)
    for name, c in rc.items():
        b = rb.get(name)
        if c['verdict'] != 'PASS': bad.append('%s: difftest %s %s' % (name, c['verdict'], c.get('problems') or c.get('failures'))); continue
        if b and b['verdict'] == 'PASS':
            if b['cycles_rebuilt'] and c['cycles_rebuilt'] > b['cycles_rebuilt'] * (1 + a.max_slowdown):
                bad.append('%s: estimated cycles %d -> %d (+%.1f%%)' % (name, b['cycles_rebuilt'], c['cycles_rebuilt'], 100.0 * (c['cycles_rebuilt'] / b['cycles_rebuilt'] - 1)))
            cb, cc = b.get('coverage_rebuilt'), c.get('coverage_rebuilt')
            if cb is not None and cc is not None and cc + 1e-9 < cb - 0.01:
                bad.append('%s: coverage %.0f%% -> %.0f%%' % (name, 100 * cb, 100 * cc))
        print('%-4s %s  cycles %s -> %s' % ('ok', name, b and b['cycles_rebuilt'], c['cycles_rebuilt']))
    for m in bad: print('FAIL', m)
    print('PARITY OK' if not bad else 'PARITY FAILED')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
