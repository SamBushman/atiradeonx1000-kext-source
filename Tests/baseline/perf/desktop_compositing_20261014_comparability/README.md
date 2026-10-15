# 2D / gesture comparability, stock vs rebuilt (#45), 2026-10-14

Protocol: `Tests/perf_2d_comparability_plan.md`; driver `Tools/perf_2d_compare.sh`; analysis `Tools/perf_2d_report2.py` (visit-level hierarchical bootstrap, 90 % CI, margin +-10 %). Hot-swap only; boot-time driver untouched.

| dir | content |
|---|---|
| `aa_pilot` | stock vs stock, 2+2 visits x 3 runs (protocol check) |
| `main` | S R x4 visits, 3 runs (`rebuilt_v4_r3` is empty: my cleanup `killall` hit it mid-run) |
| `main2` | same again, 4+4 visits |
| `main3_reversed` | order R S, 6+6 visits x 2 runs (removes the "rebuilt always follows stock" confound) |
| `pooled` | all of the above, visits renumbered (main2 = v5-8, main3 = v9-14): **14 visits / 36 runs per side** |

## Result (pooled_report.md): 165 EQUIVALENT, 26 INCONCLUSIVE, 0 DIFFERENT, 9 ZERO (counter is 0 on both)

No metric differs between stock and the rebuilt kext. 165 are shown equal within +-10 %; 26 are still not resolved either way, so "NOT MEASURABLE" is NOT yet established for them (the A/B/A/B plan's Phase 2 was cut short, see below).

## Noise sources identified from the data
1. **`idle.*` is a decaying transient, not a steady state.** idle.d rises to ~115 and decays to a ~62-66 floor in each run (carry-over from the previous scenario), so its whole-run median is bimodal (~62 vs 72-76) on BOTH kexts. The new `.tail` readout (median of the second half) fixes it: idle.c.tail and idle.d.tail are EQUIVALENT with CI [0.994, 1.000]. `.active` thresholds built on the idle median were polluted by the same effect (now based on the tail).
2. **Run-level latent in dashboard.a / expose.a** (corr 0.86 between the two within a run; a run is either ~4.2-4.6 or ~5.5-6.8): first run after a swap is often high (A/A pilot stock v1r1 = 6.26). Rebuilt r1 was high in 6/8 vs stock 2/8 in the first two batches, but with the order reversed (batch 3) it is 3/6 on both sides, so it is a first-run-after-swap effect on both kexts, not a rebuilt-kext difference. Cause of the latent itself not yet identified (power-stepping is not observable: `hw.cpufrequency` fixed 2.5 GHz).
3. The two DIFFERENT rows in batch 3 alone (`idle.a.active`, `idle.b.active`) are a degenerate readout (counters are 0 at idle, threshold 0) and disappear when pooled.

## Not done (session ended on request)
Planted-difference control (hook `BURN_TAGS`/`BURN_N` is in the driver, never run), re-running the 26 INCONCLUSIVE metrics with a longer/repeated-animation readout, GL perf re-run on HEAD, DVD IDCT comparison (needs boot-time install, not authorized). #45 stays open.

## Update 2026-10-15: planted-difference control, margin analysis, end states

* **Planted-difference control (`planted_burner`, report `planted_report.md`):** stock vs the same stock kext with 2 CPU burners (`yes`) running, 3+3 visits x 3 runs. **61 metrics DIFFERENT, 90 EQUIVALENT, 21 INCONCLUSIVE.** The test is therefore not blind: e.g. dashboard.c x1.89, dock_hover.c x2.5, expose_all_windows.c.active 44 -> 200, and also the a/b counters (+30 %), so a/b respond to system load. (Pre-run load average does not explain the run-level latent: corr dashboard.a vs 1-min load = 0.06 over 71 runs.)
* **Margins (pooled 14+14 visits, 36 runs/side), stock-only A/A (7 vs 7 visits) run with the same margin:**

| margin | stock vs rebuilt: EQUIVALENT / INCONCLUSIVE / DIFFERENT | stock vs stock (A/A): EQUIVALENT / INCONCLUSIVE / DIFFERENT |
|---|---|---|
| +-10 % | 165 / 26 / 0 | (A/A, 7v7) see aa_stockonly_m0.15 for +-15 % |
| +-15 % | 171 / 20 / 0 | 152 / 19 / 0 |
| +-25 % | **182 / 9 / 0** | 165 / 6 / 0 |

  Rebuilt behaves like stock to within the stock-vs-stock noise at every margin; nothing is DIFFERENT at any margin.
* **End states of the 9 metrics not EQUIVALENT at +-25 %** (`pooled_m0.25.md`):
  * `idle.a.active`, `idle.b.active`, `idle.c.active`, `idle.d.active`: **NOT MEASURABLE as `.active`** - idle.a/b are 0 everywhere (the threshold is 0), idle.c/d.active count ticks above 1.5x a decaying counter's floor, so a few ticks decide it; A/A gives the same INCONCLUSIVE. Replacement readouts `idle.c.tail`, `idle.d.tail` are EQUIVALENT (CI [0.994, 1.000]); idle.a/b read 0 on both kexts (ZERO).
  * `dashboard.d.active`, `expose_all_windows.d.active`: **NOT MEASURABLE as `.active`** (A/A INCONCLUSIVE too; animation duration in ticks varies +-40 % run to run); replacement: the `.sum`/`.peak` readouts of the same counter (EQUIVALENT within +-25 %).
  * `dashboard.a`, `expose_all_windows.a.tail`, `expose_all_windows.b.tail`: still a run-level latent (stock A/A shows the same: dashboard.a A/A CI [0.894, 1.257]); not resolvable at +-25 % with 36 runs; their `.peak`/`.sum` readouts are EQUIVALENT (within +-25 %; some only at that margin). Latent not root-caused (not pre-run load; not visible in `hw.cpufrequency`).
