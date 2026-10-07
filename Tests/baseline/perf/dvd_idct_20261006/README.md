# DVD intra/residual IDCT throughput - stock 4.1.9 baseline (2026-10-06)

First real baseline for issue #44 criterion 1's DVD/video decode domain, via `Tests/perf_dvd_idct.c`. Covers only the
intra/residual reconstruction path (stream 0, `planeSelector=0`) - the forward-predicted (P/B) macroblock composite
is permanently excluded (see the test's own header comment and #142: it never posts a completion stamp on stock
hardware, by design, not a gap).

## Result (`run1.txt`, `env.txt` for the machine state)

| metric | n | min_us | p10_us | median_us | p90_us | max_us |
|---|---:|---:|---:|---:|---:|---:|
| `dvd.doIDCT.intra.1mb` (1 macroblock) | 2000 | 4.23 | 4.35 | 4.38 | 4.41 | 9.03 |
| `dvd.doIDCT.intra.4mb` (4 macroblocks) | 2000 | 4.20 | 4.35 | 5.04 | 5.13 | 6.90 |
| `dvd.doIDCT.intra.12mb` (12 macroblocks, full 64x48 picture) | 2000 | 4.23 | 11.94 | 12.03 | 12.12 | 13.92 |

Per-call cost scales roughly linearly with macroblock count once past the fixed per-call floor (~4.2us): the
12-macroblock submission costs about 2.7x the 1-macroblock one for 12x the data, i.e. most of the fixed cost is
per-call overhead (IOKit round trip + the kernel's own ring-submission bookkeeping in `submit_idct_buffer_consumed`),
not per-macroblock work - consistent with the actual hardware-visible cost being dominated by fixed submission
overhead at this picture size, not by the engine's own per-macroblock decode time.

## Methodology notes (read before comparing against a future run)

- **The readiness-wait time (`readiness probe attempt N`, "doIDCT ready after N attempt(s)") is NOT part of the
  measured metric and must not be confused with it.** This run needed 49 one-second-spaced attempts (~49s) before
  the very first real `doIDCT` call succeeded, despite every documented precondition (`Sources/
  ATIR500DVDContext_doIDCT_Port.cpp`'s own gate: bound surface, hardware-up, ring-ready) already being satisfied -
  confirmed directly via a live `Tools/vram_peek/VRAMPeek.cpp` read during an earlier diagnostic run, and no
  `DumpASICHangState` ever logged (ruling out the ring-full-timeout path in `submit_idct_buffer_consumed`). This
  matches issue #127/V15's own prior finding that `start_xdct_engine`'s "ring ready" flag is set unconditionally
  regardless of real readiness, and that the real settling time is genuinely probabilistic hardware timing (their
  own trials showed the identical uptime giving different outcomes across separate attempts) - not a fixed delay,
  and not something this test's own code can shorten or predict. A future run may need anywhere from under a second
  to (so far, observed) tens of seconds before the first real call succeeds; only the `METRIC` lines after that
  point are the actual throughput measurement.
- Fresh boot, 15 min uptime, fingerprint `2221852201` matches the existing baseline-of-record fingerprint in
  `Tests/baseline/perf/stock_4.1.9_g5_tiger_20261002_freshboot/env.txt` - same display/environment state.
- Single run, not yet repeated 3-5x the way the GL-side baselines were (`Tests/performance_plan.md` sections 1-7) -
  this establishes the metric and the methodology works end to end; repeating it to apply the project's own noise/
  regression rule (`Tools/perf_compare.py`) is the natural next step before this counts as a enforceable gate.
