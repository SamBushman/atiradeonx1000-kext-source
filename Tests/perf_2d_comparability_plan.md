# Plan: make the desktop-compositing / gesture data comparable between stock and rebuilt (#45)

Status: planned 2026-10-14, to start after the quiet rebuilt soak (ends ~20:45). Owner: the #45 Phase R run.

## Goal and stop condition

For every reported metric in `Tests/perf_2d_compositing.c` output (11 scenarios x raw values a/b/c/d = 44; 40 reported by `Tools/perf_2d_report.py`), reach one of exactly three **evidence-backed** verdicts, and keep iterating until no metric is left in a fourth state:

| verdict | meaning | evidence required |
|---|---|---|
| EQUIVALENT | stock and rebuilt are the same within +-10 % | 90 % bootstrap CI of the rebuilt/stock ratio lies entirely inside [0.90, 1.10] |
| DIFFERENT | the rebuilt kext differs | the CI excludes 1.0 and the difference reproduces in a second independent visit set; then it becomes a `rebuilt-kext-defect` issue |
| NOT MEASURABLE | the readout cannot compare anything on this machine | the noise source is identified (not guessed), the A/A control (stock vs stock) fails the same test, and an alternative readout is defined and itself reaches EQUIVALENT or DIFFERENT |

"Inconclusive" is not an end state. The work is done when every metric has a verdict and the report says which of the three it is. Margins: +-10 % first; if a metric is EQUIVALENT at +-10 % with room to spare, also report the tighter margin it supports.

## What the first two passes showed (8 runs per pass, order S R S R)

* 24 of 40 metrics OK, 16 NOISY (margin >25 % because stock's own four runs spread). Per-run medians (`~/g5logs/oct14-phaseR/perf2d_scrollfix`, README in the baseline dir) point at **four noise sources**, none yet proven:
  1. **First run after a hot-swap + unstick is often low** (dashboard.a / expose_all_windows.a: one run of 3.6-3.9 against 5.6-6.1 on both kexts; it was stock's v2_r1 and rebuilt's v1_r1). Cold WindowServer / Dock / Finder state after the forced mode-set.
  2. **Background activity** during `idle` (idle.d 79 on one rebuilt run against 62 on the other seven; idle.c 76 vs 66-71).
  3. **Short animations** (Expose, Dashboard, show desktop, minimise, window open): 80-200 ticks cover only a few animation cycles, so a handful of ticks decide the median. Ticks are autocorrelated, so per-tick pooling would fake precision.
  4. Possible **G5 processor power-stepping** (the 2026-10-06 GL baselines saw a 2x bimodality from it) and accumulating stale Dock processes after repeated WindowServer kills.

## Phase 0 - tooling (dev machine, while the quiet soak runs; nothing deployed)

* `Tests/perf_2d_compositing.c`: `RAW=<file>` dumps every tick's four values per scenario (so distributions, not only summaries, are kept); `WARMUP=1` runs the whole scenario list once and discards it.
* `Tools/perf_2d_compare.sh`: per visit = hot-swap + unstick + `killall Dock` (stale Dock cleanup) + 60 s settle + one discarded warm-up run + N measured runs; order A B A B A B A B (4 visits per side, 3 measured runs per visit = 12 per side); a quiesce check (`ps`/load average below a threshold, no `mdworker`/`mds` busy) before each run, with the check output saved.
* `Tools/perf_2d_report2.py`: per metric, per-visit medians; stock-vs-rebuilt ratio with a bootstrap CI that resamples **visits and runs** (not ticks); the three-way verdict above; an A/A mode (stock visits 1,3 vs 2,4) that must report EQUIVALENT for every metric the test claims it can judge.
* Sensitivity control: a planted known difference (the same stock kext measured with a CPU-burner process running, or at a different resolution) must be reported DIFFERENT, so EQUIVALENT is not simply "the test is blind".

## Phase 1 - collect (after ~20:45, G5 rebooted to a fresh stock boot first)

1. Pilot A/A: stock S1 S2 S3 S4 (no rebuilt). Learns the noise floor per metric and validates the protocol. Fix the protocol (settle time, warm-up, quiesce, power-stepping) until A/A is EQUIVALENT for the metrics that are physically stable (idle.*, dock_hover.*, scroll.*, window_resize.*).
2. Main: S R S R S R S R x 3 measured runs.
3. Planted-difference control (see above).

## Phase 2 - analyse and iterate

For every metric not yet EQUIVALENT/DIFFERENT after Phase 1:
* Identify the noise source with data (per-tick traces, `ps`/`top` snapshots taken inside the run, `pmset -g`/`hostinfo` for stepping, run-order effects), not by assumption.
* Remove it (quiesce a daemon, longer settle, more animation cycles per run: 400+ ticks or repeated toggles, finer ticks) or change the readout: for animation scenarios use quantities with far less variance than a per-tick CGS rate, e.g. **sum of a/b/c/d over the whole animation window**, the **tick count until the counters return to idle**, and **peak over a fixed window**, all taken from the raw dump.
* Re-run only the affected scenarios, still interleaved, and re-test. Repeat until every metric has a verdict. If an A/A comparison of a metric cannot reach EQUIVALENT after its noise source is removed or the readout changed, mark it NOT MEASURABLE with the evidence and keep the alternative readout.

## Phase 3 - write-up

`Tests/baseline/perf/desktop_compositing_<date>_comparability/` with raw dumps, the report (one row per metric: verdict, ratio, CI, runs, margin), the A/A and planted-difference controls, and the documented noise sources; a #45 comment; `performance_plan.md` section 8c updated. Anything DIFFERENT gets its own `rebuilt-kext-defect` issue and is root-caused against stock before it is called a defect.

## Out of scope / not touched

Hot-swap only; the boot-time driver is not modified. The DVD IDCT rebuilt comparison needs a boot-time install and stays last, after everything else passes.
