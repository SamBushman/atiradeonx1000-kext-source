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
