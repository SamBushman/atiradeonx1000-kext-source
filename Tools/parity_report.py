#!/usr/bin/env python3
"""parity_report.py - issue #42 criterion 4: a pass/fail/parity report between a recorded STOCK run and a candidate (rebuilt-kext) run.

Inputs (all are the files the existing harnesses already write; nothing new is required of a run):
  * destructive-test logs: <dir>/<test>_<kext>_<UTC timestamp>.log   (Tests/destructive/dtest.c write-ahead logs; kext = stock | rebuilt)
  * harness text outputs: Tests/baseline/*.txt vs a candidate output file of the same harness (--text STOCK CAND, repeatable)

Usage:
  parity_report.py --stock-dir Tests/destructive/phaseS --cand-dir <dir with *_rebuilt_*.log> [--cand-kext rebuilt] [--text A B]... [-o report.md]
  parity_report.py --self-test            (compares the stock logs with themselves, then with one deliberately altered call: must say IDENTICAL, then DIVERGENT)

Per test the stock log (newest) and the candidate log (newest) are reduced to the sequence of (call description, return code) plus NOTE lines (observed values),
with timestamps, kext name and phase tags removed. Verdicts:
  PARITY      identical call/return sequence and notes
  VALUE-DIFF  same calls and return codes, different NOTE values (printed)
  DIVERGENT   a return code differs, a call is missing/extra, or the candidate run did not finish (no `finish:` note)
  KNOWN       divergent/differing, but the test is on the deviation list (Tests/known_vendor_deviations.md) -> shown with its V-id, not counted as a failure
  NO-CAND     no candidate log for a test that has a stock log
Exit status: 0 when no DIVERGENT / NO-CAND (VALUE-DIFF and KNOWN are reported but do not fail), 1 otherwise, 2 on usage errors.
"""
import argparse, difflib, glob, os, re, sys

# test -> deviation id(s) in Tests/known_vendor_deviations.md (a divergence in these tests is expected to be explained by the entry)
KNOWN = {
    "t3_surface_locks": "V4 (#123: lockOptions 0 panics stock; the stock run dropped those calls)",
    "t3_dvd_idct_lock_leak": "V3 (#98: lock-leak claim unreconciled)",
    "t3_gl_set_stereo_enable": "V8 (#88: NoMemory on this machine)",
    "t3_dvd_write_buffer": "V5 (unbound call never made; bound call is a no-op)",
    "t3_dvd_macrovision": "V5 (unbound call never made)",
    "t3_gl_reclaim": "V6 (data-buffer pool offsets are machine-state dependent)",
}

LOG_RE = re.compile(r"^(?P<test>.+)_(?P<kext>stock|rebuilt|[a-z0-9]+)_(?P<ts>\d{8}T\d{6}Z)\.log$")
LINE_RE = re.compile(r"^\S+Z \[[^\]]*\] (?P<body>.*)$")


def reduce_log(path):
    """-> (calls [(desc, rc)], notes [str], finished bool)"""
    calls, notes, fin, pending = [], [], False, None
    for raw in open(path, errors="replace"):
        m = LINE_RE.match(raw.rstrip("\n"))
        if not m:
            continue
        b = m.group("body")
        if b.startswith("ABOUT TO CALL "):
            pending = b[len("ABOUT TO CALL "):]
        elif b.startswith("RESULT -> "):
            rc = b[len("RESULT -> "):].split(" ", 1)[0]
            desc = b.split(") ", 1)[1] if ") " in b else b
            calls.append((desc, rc))
            pending = None
        elif b.startswith("NOTE "):
            n = b[5:]
            if n.startswith("start:") or n.startswith("finish:"):
                if n.startswith("finish:"):
                    fin = True
                continue          # mirror address / outcome word differ between runs by design
            notes.append(n)
    if pending is not None:
        calls.append((pending, "NO-RESULT"))   # the call in flight when the log ended (hang / panic)
    return calls, notes, fin


def newest(dirs, kext):
    best = {}
    for d in dirs:
        for p in glob.glob(os.path.join(d, "*.log")):
            m = LOG_RE.match(os.path.basename(p))
            if m and m.group("kext") == kext:
                t = m.group("test")
                if t not in best or m.group("ts") > best[t][0]:
                    best[t] = (m.group("ts"), p)
    return {t: p for t, (ts, p) in best.items()}


def compare(stock_path, cand_path):
    sc, sn, sf = reduce_log(stock_path)
    cc, cn, cf = reduce_log(cand_path)
    detail = []
    if not cf:
        detail.append("candidate run did not finish (last call: %s)" % (cc[-1][0] if cc else "none"))
    if sc != cc:
        for l in difflib.unified_diff(["%s -> %s" % c for c in sc], ["%s -> %s" % c for c in cc], "stock", "cand", lineterm="", n=0):
            if not l.startswith(("---", "+++", "@@")):
                detail.append(l)
        return "DIVERGENT", detail
    if not cf:
        return "DIVERGENT", detail
    if sn != cn:
        for l in difflib.unified_diff(sn, cn, "stock", "cand", lineterm="", n=0):
            if not l.startswith(("---", "+++", "@@")):
                detail.append(l)
        return "VALUE-DIFF", detail
    return "PARITY", detail


def text_compare(a, b):
    d = [l for l in difflib.unified_diff(open(a, errors="replace").read().splitlines(), open(b, errors="replace").read().splitlines(), a, b, lineterm="", n=0)
         if not l.startswith(("---", "+++", "@@"))]
    return ("PARITY" if not d else "DIVERGENT"), d


def report(args):
    stock = newest(args.stock_dir, "stock")
    cand = newest(args.cand_dir, args.cand_kext)
    rows, bad = [], 0
    for t in sorted(stock):
        if t not in cand:
            rows.append((t, "NO-CAND", ["no %s log" % args.cand_kext])); bad += 1; continue
        v, d = compare(stock[t], cand[t])
        if v in ("DIVERGENT", "VALUE-DIFF") and t in KNOWN:
            rows.append((t, "KNOWN", ["%s: %s" % (KNOWN[t], v)] + d))
        else:
            rows.append((t, v, d))
            if v == "DIVERGENT":
                bad += 1
    for a, b in (args.text or []):
        v, d = text_compare(a, b)
        rows.append((os.path.basename(a), v, d))
        if v == "DIVERGENT":
            bad += 1
    out = ["# Parity report: stock vs %s" % args.cand_kext, "", "| test | verdict |", "|---|---|"]
    out += ["| %s | %s |" % (t, v) for t, v, _ in rows]
    cnt = {}
    for _, v, _ in rows:
        cnt[v] = cnt.get(v, 0) + 1
    out += ["", "Totals: " + ", ".join("%s %d" % kv for kv in sorted(cnt.items())), ""]
    for t, v, d in rows:
        if d and v != "PARITY":
            out += ["## %s - %s" % (t, v), "```"] + d[:60] + ["```", ""]
    txt = "\n".join(out) + "\n"
    if args.o:
        open(args.o, "w").write(txt)
    else:
        sys.stdout.write(txt)
    return 1 if bad else 0


def self_test(stock_dir):
    import tempfile, shutil
    tmp = tempfile.mkdtemp()
    try:
        n = 0
        for p in glob.glob(os.path.join(stock_dir, "*_stock_*.log")):
            shutil.copy(p, os.path.join(tmp, os.path.basename(p).replace("_stock_", "_rebuilt_"))); n += 1
        a = argparse.Namespace(stock_dir=[stock_dir], cand_dir=[tmp], cand_kext="rebuilt", text=None, o=None)
        sys.stdout = open(os.devnull, "w"); r1 = report(a); sys.stdout = sys.__stdout__
        print("self-test 1 (stock vs byte-copy of stock, %d logs): exit %d (want 0)" % (n, r1))
        victim = sorted(glob.glob(os.path.join(tmp, "t3_scaling_rebuilt_*.log")))[0]
        s = open(victim).read()
        s2 = re.sub(r"(RESULT -> )0x00000000 \(kIOReturnSuccess\)", r"\g<1>0xe00002bc (kIOReturnError)", s, count=1)
        assert s != s2, "mutation did not apply"
        open(victim, "w").write(s2)
        sys.stdout = open(os.devnull, "w"); r2 = report(a); sys.stdout = sys.__stdout__
        print("self-test 2 (one return code altered in t3_scaling): exit %d (want 1)" % r2)
        return 0 if (r1 == 0 and r2 == 1) else 1
    finally:
        sys.stdout = sys.__stdout__
        shutil.rmtree(tmp)


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--stock-dir", action="append", default=[])
    ap.add_argument("--cand-dir", action="append", default=[])
    ap.add_argument("--cand-kext", default="rebuilt")
    ap.add_argument("--text", nargs=2, action="append", metavar=("STOCK", "CAND"))
    ap.add_argument("-o")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        sys.exit(self_test((a.stock_dir or ["Tests/destructive/phaseS"])[0]))
    if not a.stock_dir or not a.cand_dir:
        ap.error("--stock-dir and --cand-dir are required")
    sys.exit(report(a))
