# Performance measurement plan and stock baseline (issue #44)

Scope (per the 2026-10-02 scope decision on #41-#45): this file **defines** the benchmarks, the "no worse than" rule, the profiling method and the noise handling, and records the **stock** driver's baseline.
Running the same tooling against the rebuilt kext and iterating on regressions is #45. Nothing here loads the rebuilt kext.

## 1. What is measured (criterion 1)

| domain | metric family | tool | covers |
|---|---|---|---|
| kext external methods, all four contexts | `gl.*`, `2d.*`, `dvd.*`, `surface.*`: latency of one proven-safe call (user -> IOConnectMethod* -> method body -> back), p10 of 50 000 calls | `Tests/perf_methods.c` | per-selector cost, so a regression localises to a context and selector; includes two real MMIO register reads (`read_regs`, ~+0.7 us over a pure query) |
| connection lifecycle | `open_close.surface/gl/2d/dvd`: open + close one user client | `Tests/perf_methods.c` | allocation/teardown of each context object and its state |
| GL rendering path | `glcycle.*`: one create-context / pbuffer / clear / 100-triangle draw / readback / destroy cycle, per-phase median over 100 cycles | `Tests/perf_baseline.c` | the userspace GL driver + the kext's GL/Surface contexts together |
| 2D / compositing responsiveness (real desktop) | window move/resize/scroll frame times | **manual, not automated**: needs a person at the console (SSH-launched GUI apps deadlock); the 2D *context* is covered by `2d.*` above | see `Tests/consumer_scenarios.md` |
| DVD / video decode (IDCT throughput, dropped frames) | **not measurable on stock today**: QuickTime and DVD Player both decode in software on this machine (no DVD context is ever opened, `Tools/userspace/va_capture/`), and `doIDCT` has no safe valid call (#93). The DVD context is covered by `dvd.*` latency only | - | revisit when a client really uses the hardware IDCT path |

All calls are the ones `Tests/test_deep_t1.c` already asserts on stock: no surface binding, locking, flipping, submission or register writes.

## 2. Baseline numbers (criterion 2)

Stock `com.apple.ATIRadeonX1000` 4.1.9, G5 2.5 GHz x4, Mac OS X 10.4.11, ATI X1900 (R580), one 1920x1080 display, 5 fresh-process repetitions 5 s apart.
Raw files and the environment record: `Tests/baseline/perf/stock_4.1.9_g5_tiger_20261002/` (`env.txt`, `run<k>_methods.txt`, `run<k>_gl.txt`). Collected with `sh Tests/perf_collect.sh OUTDIR` on the G5.
Each number is the median over the 5 runs of the run's p10 (`perf_methods`) or median (`perf_baseline`); "noise" is (max - min) of the 5 run values / the median; "margin" is the regression threshold of section 3.

| metric | stock | noise | margin |
|---|---|---:|---:|
| `2d.get_config.sel1` | 3.54 us | 4.2 % | 13 % |
| `2d.get_surface_info.sel2` | 3.69 us | 2.4 % | 7 % |
| `2d.read_regs_1.sel16` | 4.32 us | 2.8 % | 8 % |
| `2d.read_regs_2.sel16` | 4.77 us | 1.3 % | 5 % |
| `dvd.check_stamps.sel20` | 3.54 us | 2.5 % | 8 % |
| `dvd.get_config.sel1` | 3.51 us | 2.6 % | 8 % |
| `dvd.get_status.sel2` | 3.54 us | 3.4 % | 10 % |
| `dvd.read_regs.sel13` | 4.32 us | 2.8 % | 8 % |
| `gl.get_config.sel3` | 3.69 us | 1.6 % | 5 % |
| `gl.get_hw_info.sel20` | 3.63 us | 1.7 % | 5 % |
| `gl.get_status.sel4` | 3.63 us | 1.7 % | 5 % |
| `glcycle.ChoosePixelFormat` | 33.00 us (0% of a 7.2 ms cycle) | 0.0 % | 5 % |
| `glcycle.Clear+Flush` | 195.00 us (3% of a 7.2 ms cycle) | 0.5 % | 5 % |
| `glcycle.CreateContext` | 1.99 ms (27% of a 7.2 ms cycle) | 1.3 % | 5 % |
| `glcycle.Draw100Tri+Flush` | 230.00 us (3% of a 7.2 ms cycle) | 0.9 % | 5 % |
| `glcycle.ReadPixels` | 1.78 ms (25% of a 7.2 ms cycle) | 5.8 % | 18 % |
| `glcycle.SetPBuffer` | 1.93 ms (27% of a 7.2 ms cycle) | 1.3 % | 5 % |
| `glcycle.Teardown` | 1.08 ms (15% of a 7.2 ms cycle) | 0.6 % | 5 % |
| `open_close.2d` | 89.50 us | 0.7 % | 5 % |
| `open_close.dvd` | 157.78 us | 1.5 % | 5 % |
| `open_close.gl` | 303.71 us | 0.5 % | 5 % |
| `open_close.surface` | 62.97 us | 0.6 % | 5 % |
| `surface.get_state.sel2` | 3.57 us | 3.4 % | 10 % |
| `surface.query_lock.sel11` | 3.60 us | 1.7 % | 5 % |

GL cycle phases (where the time goes, criterion 4): CreateContext 27 %, SetPBuffer 27 %, ReadPixels 25 %, Teardown 15 %, Clear 3 %, Draw 3 %, ChoosePixelFormat < 1 % of a 7.2 ms cycle: context and pbuffer set-up/readback/teardown
(the kext's context, surface and memory management and the DMA readback) dominate; actual drawing is a few percent.

## 3. "No worse than" (criterion 3) and noise (criterion 5)

`python3 Tools/perf_compare.py STOCKDIR CANDDIR` (>= 3 repetitions each; fewer is marked INDICATIVE). Per metric, with S = median over the stock runs and C = median over the candidate runs of the per-run value:

* noise = (max - min) of the stock run values / S, margin = **max(5 %, 3 x noise)**
* **REGRESSION** if C > S x (1 + margin) **and** C - S > floor (0.15 us for `perf_methods` metrics, 50 us for `glcycle.*`: the timer/IOKit resolution); **IMPROVED** if the mirror holds; otherwise **OK**
* a metric with margin > 25 % is **NOISY**: no conclusion, rerun on a quiet machine
* exit status 1 if any REGRESSION. `--self-test STOCKDIR` checks the rule on real data: stock vs other stock runs gives 0 regressions, a synthetic +20 % is REGRESSION, +4 % is OK.

Why 5 % at minimum: the stock metrics repeat within 1-6 %, so a 5 % floor with 3x the measured noise keeps false alarms rare while still catching the 10-20 % slowdowns a missing fast path or an extra lock would cause.
Comparisons are only valid like-with-like: same machine, same boot (a fresh boot is cleanest), same display state, nothing else running (`env.txt` records load and busy processes).

### The G5 dynamic-power-step trap (found while building this)

The first stock baseline (kept as `stock_4.1.9_g5_tiger_20261002_unwarmed_first_attempt/`) used 2000-call samples and showed an apparent **2x bimodality**: the same call measured 3.5 us in one run and 7.3 us in the next
(52-100 % "spread", which made the self-test report a false regression). A 50 000-call sample was uniformly fast, so it is a start-up transient: an idle G5 starts a process at roughly half speed for its first tens of ms
(dynamic power stepping) and ramps up under load. Fix, now built in: `perf_methods` burns ~0.7 s of CPU before each group, takes 50 000 calls per metric and reports p10 as the headline (the fast-mode floor). After this every
metric's run-to-run spread is <= 6 %. Any new benchmark on this machine needs a warm-up and a long sample, or it measures the power governor.

## 4. Localising a regression (criterion 4)

1. Run `perf_compare.py`; the REGRESSION rows name the context and selector (`2d.read_regs_1.sel16`) or GL phase (`glcycle.SetPBuffer`).
2. A selector row -> the method body is the suspect: compare it with the stock body (`Tools/callee_compare.py`, `size_compare.py`, `imm_compare.py`, `Tests/body_triage.tsv`) - a missing fast path or an extra call/lock shows there. The per-call IOKit overhead
   (~3.5 us) is identical for stock and rebuilt, so differences are method time; `read_regs` vs `get_config` shows how an MMIO access scales.
3. A `glcycle.*` phase row -> phase share first (the table above; apply the `component-cost-profiling` method: optimise/inspect the largest share), then `open_close.gl` / `2d.*` / `surface.*` to see whether the kext side moved or the userspace GL driver did.
4. Function-level timing inside the rebuilt kext needs kernel instrumentation (timestamps around suspect calls via `mach_absolute_time` in a debug build) and is part of #45's iterate loop, not set up here.

## 5. Not covered yet (and why)

* Heavier method bodies (surface bind, lock, swap, scaling, texture allocation) are not timed: they are the destructive/T3 calls, one per boot by protocol #87, and cannot be looped safely. A timing for those would be a single-shot number per boot, too noisy to gate on.
* Real GL application frame times and desktop compositing: manual runs at the console (section 1).
* 2D and DVD hardware throughput: no safe workload exists (section 1).
