# GL / IOKit method perf, rebuilt `95edbd2` vs stock, 2026-10-15 (#45, #44 method)
`Tests/perf_collect.sh` (5 reps) + `Tools/perf_compare.py`, hot-swap only, same swap+unstick state per set, 60 s settle. Order: stockA, stockB (drift control), rebuilt, stockC (after).
Result: **24 metrics, 0 REGRESSION, 0 IMPROVED, 0 NOISY, 24 OK** for stockA/stockB/stockC vs rebuilt, and stockA vs stockB (A/A) is also 24 OK. Kext source is unchanged since 95edbd2 (git diff outside Tests/Tools/docs empty).
