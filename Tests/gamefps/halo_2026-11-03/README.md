# Halo timedemo, installed final GLDriver (fe83266b, md5 dff47f98…) vs stock — 2026-11-03

Interleaved (binary swap per pass, per-process load), 3 rounds, order alternated, warm-up pass first; harness `Tools/gamefps/halo_run_side.sh`
(800x600 high / 640x480 low — Halo ignores the profile resolution, see G5_game_benchmark_renamed_2026-11-02.md).

| preset | stock fps (3) | rebuilt fps (3) | delta | tol |
|---|---|---|---|---|
| 800x600 high | 92.35 92.49 91.88 | 92.49 91.98 92.14 | -0.0 % | 5 % |
| 640x480 low | 122.29 123.02 122.07 | 121.99 121.43 121.91 | -0.6 % | 5 % |

0 regressions. Stock restored afterwards (md5 5d63b5e3…). Raw per-run lines: driver.log.
