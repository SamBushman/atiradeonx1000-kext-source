# Desktop compositing, rebuilt (issue172c, -Os) vs stock, same hot-swap method (2026-10-13)

Fully remote (no one at the console): `Tests/perf_2d_compositing.c`, 200 ticks @16 ms, fresh Finder window set to
{100,100,700,500} before every run (precondition from `../desktop_compositing_20261007_fixed/`), 5 runs per set.
Must be run in the **foreground** over ssh: a `nohup`/`disown`ed launch loses the Mach bootstrap and `osascript`
fails with `CFMessagePortCreateLocal ... Processes-0.1048577`.

Order: `p2d_reb` (rebuilt, state left by the earlier perf session) -> swap to stock + unstick -> `p2d_stock`, `p2d_stock2`
-> swap to rebuilt + unstick -> `p2d_reb2`.

| metric (median of 5 runs) | stock A | stock B | rebuilt (1st swap) | rebuilt (fresh swap) |
|---|--:|--:|--:|--:|
| window_drag.a | 37.8 | 35.3 | 55.7 | 35.5 |
| window_resize.a | 34.2 | 34.3 | 59.2 | 34.1 |
| window_resize.d | 812 | 816 | 1382 | 819 |
| window_open.a | 9.3 | 9.1 | 10.2 | 8.9 |
| scroll.d / dock_hover.a | 368 / 59.3 | 368 / 59.5 | 370 / 59.8 | same |

Stock A vs B reproduce each other (<=5% on the continuous gestures). The first rebuilt set read ~1.5-1.7x higher on
drag/resize than same-state stock, but a fresh swap of the same binary reads identical to stock, so that set was a
hot-swap-state effect (it matches the boot-time stock baseline, `../desktop_compositing_20261007_fixed/`: resize.a ~60),
not a driver difference. Rebuilt is at parity with stock; no regression. Lesson: compare only within one swap-state,
and a single swap's result for the 2D metrics is not reproducible across swaps - interleave if a gate is needed.
