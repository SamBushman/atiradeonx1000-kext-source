#!/usr/bin/env python3
"""perf_compare.py - issue #44 criteria 3 and 5: decide whether a candidate's performance is "no worse than" the stock driver's, separating noise from regression.

Inputs: two directories written by Tests/perf_collect.sh (STOCK and CAND), each with run<k>_methods.txt (Tests/perf_methods.c) and run<k>_gl.txt (Tests/perf_baseline.c), >= 3 repetitions
each for a conclusive verdict (fewer is accepted but the report says INDICATIVE).

Rule (per metric, in microseconds; each run contributes its p10 (perf_methods: the fast-mode floor of a long sample, see the note in Tests/perf_methods.c) or, for perf_baseline lines, its median):
  S = median over stock runs of the run median;  noise = (max - min) of the stock run medians / S        (run-to-run spread on the same machine)
  C = median over candidate runs of the run median
  margin = max(5 %, 3 x noise);  a metric is NOISY (no conclusion possible) if margin > 25 %
  REGRESSION  C > S x (1 + margin)  AND  C - S > floor            (floor = 0.15 us for perf_methods metrics, 50 us for the glcycle.* metrics from perf_baseline: ms-scale timer resolution)
  IMPROVED    C < S x (1 - margin)  AND  S - C > floor
  OK          otherwise
Exit status: 0 when no REGRESSION, 1 when at least one, 2 on usage/parse errors.  `--self-test STOCKDIR` splits the stock runs into two groups and must report no regression, then scales one
metric by +20 % (must be REGRESSION) and by +4 % (must be OK).

Usage: perf_compare.py STOCKDIR CANDDIR [-o report.md]      |      perf_compare.py --self-test STOCKDIR
"""
import argparse, glob, os, re, statistics, sys

M_RE = re.compile(r"^METRIC (?P<n>\S+) n=(?P<cnt>\d+) min_us=(?P<min>[\d.]+)(?: p10_us=(?P<p10>[\d.]+))? median_us=(?P<med>[\d.]+) p90_us=(?P<p90>[\d.]+) max_us=(?P<max>[\d.]+)")
G_RE = re.compile(r"^(?P<n>\S+)\s+min=(?P<min>[\d.]+)ms median=(?P<med>[\d.]+)ms max=(?P<max>[\d.]+)ms mean=(?P<mean>[\d.]+)ms \(n=(?P<cnt>\d+)\)")
FLOOR_METHODS, FLOOR_GL = 0.15, 50.0


def load_dir(d):
    """-> {metric: [run medians in us]}"""
    out = {}
    files = sorted(glob.glob(os.path.join(d, "run*_methods.txt")) + glob.glob(os.path.join(d, "run*_gl.txt")))
    if not files:
        raise SystemExit("no run*_methods.txt / run*_gl.txt in %s" % d)
    for f in files:
        for ln in open(f, errors="replace"):
            m = M_RE.match(ln)
            if m:
                out.setdefault(m.group("n"), []).append(float(m.group("p10") or m.group("med")))   # p10 = fast-mode floor when present
                continue
            g = G_RE.match(ln)
            if g:
                out.setdefault("glcycle." + g.group("n"), []).append(float(g.group("med")) * 1000.0)
    return out


def judge(stock, cand):
    rows = []
    for name in sorted(stock):
        s_runs = stock[name]
        c_runs = cand.get(name)
        floor = FLOOR_GL if name.startswith("glcycle.") else FLOOR_METHODS
        S = statistics.median(s_runs)
        noise = (max(s_runs) - min(s_runs)) / S if S else 0.0
        margin = max(0.05, 3 * noise)
        if not c_runs:
            rows.append((name, S, None, noise, margin, "MISSING", len(s_runs), 0)); continue
        C = statistics.median(c_runs)
        if margin > 0.25:
            v = "NOISY"
        elif C > S * (1 + margin) and C - S > floor:
            v = "REGRESSION"
        elif C < S * (1 - margin) and S - C > floor:
            v = "IMPROVED"
        else:
            v = "OK"
        rows.append((name, S, C, noise, margin, v, len(s_runs), len(c_runs)))
    return rows


def render(rows, title):
    out = ["# %s" % title, "", "| metric | stock median (us) | cand median (us) | ratio | stock noise | margin | runs s/c | verdict |", "|---|---:|---:|---:|---:|---:|---|---|"]
    for name, S, C, noise, margin, v, ns, nc in rows:
        out.append("| %s | %.2f | %s | %s | %.1f %% | %.1f %% | %d/%d | %s |" % (name, S, "%.2f" % C if C is not None else "-", "%.3f" % (C / S) if C else "-", noise * 100, margin * 100, ns, nc, v))
    cnt = {}
    for r in rows:
        cnt[r[5]] = cnt.get(r[5], 0) + 1
    out += ["", "Totals: " + ", ".join("%s %d" % kv for kv in sorted(cnt.items()))]
    if rows and min(min(r[6], r[7]) for r in rows) < 3:
        out.append("INDICATIVE only: fewer than 3 runs on at least one side.")
    return "\n".join(out) + "\n", cnt.get("REGRESSION", 0)


def self_test(d):
    st = load_dir(d)
    if min(len(v) for v in st.values()) < 4:
        print("self-test needs >= 4 runs in %s" % d); return 2
    k = len(next(iter(st.values()))) // 2
    A = {n: v[:k + 1] for n, v in st.items()}
    B = {n: v[k:] for n, v in st.items()}     # overlapping split: both sides see the machine's real run-to-run variation
    _, reg0 = render(judge(A, B), "x")
    print("self-test 1 (stock runs vs other stock runs): %d regression(s) (want 0)" % reg0)
    name = "gl.get_config.sel3" if "gl.get_config.sel3" in B else sorted(B)[0]
    B20 = {n: ([x * 1.20 for x in v] if n == name else v) for n, v in B.items()}
    B04 = {n: ([x * 1.04 for x in v] if n == name else v) for n, v in B.items()}
    r20 = [r for r in judge(A, B20) if r[0] == name][0][5]
    r04 = [r for r in judge(A, B04) if r[0] == name][0][5]
    print("self-test 2 (%s +20%%): %s (want REGRESSION, or NOISY if its stock noise is high)" % (name, r20))
    print("self-test 3 (%s +4%%): %s (want OK)" % (name, r04))
    return 0 if (reg0 == 0 and r20 in ("REGRESSION", "NOISY") and r04 in ("OK", "NOISY")) else 1


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("stock", nargs="?"); ap.add_argument("cand", nargs="?"); ap.add_argument("-o"); ap.add_argument("--self-test", metavar="STOCKDIR")
    a = ap.parse_args()
    if a.self_test:
        sys.exit(self_test(a.self_test))
    if not (a.stock and a.cand):
        ap.error("STOCKDIR and CANDDIR are required")
    txt, nreg = render(judge(load_dir(a.stock), load_dir(a.cand)), "Performance: stock vs candidate")
    if a.o:
        open(a.o, "w").write(txt)
    else:
        sys.stdout.write(txt)
    sys.exit(1 if nreg else 0)
