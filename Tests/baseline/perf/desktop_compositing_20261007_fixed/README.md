# 2D/desktop-compositing baseline, fixed and fully stable (2026-10-07)

Supersedes `../desktop_compositing_20261006/` after investigating why #44's own repeat-pass (2026-10-07) found 13 of
24 metrics exceeding a 25% run-to-run spread. Both real root causes were found and fixed, not just documented -
this baseline is the result: **0 of 24 metrics exceed 25% spread across 5 runs.**

## What was actually wrong (two distinct, now-fixed issues)

1. **`window_resize` never restored the window's size, unlike `window_drag` which already did.** Confirmed via a
   raw `CGSGetPerformanceData` probe (pinned at exactly `0.000` for `a`/`b` at true rest, ruling out instrument
   noise) and a direct A/B test, then by reading `Tests/perf_2d_compositing.c` itself: `window_resize`'s gesture drags
   the window's bottom-right corner outward by `(150,100)` with no step afterward to put it back, so every repeated
   invocation permanently grew the test window by that amount. A 10-run pool (kept in `../desktop_compositing_20261006/`
   for the record) showed this as a clean, monotonic drift once the runs were reordered correctly (the raw file
   listing sorts lexicographically, scrambling `run10` next to `run1` - reorder by actual sequence before eyeballing
   any trend). After 10 uncorrected runs the test window had grown to 1459x803px. **Fixed**: `perf_2d_compositing.c`
   now restores the original bounds after `window_resize`, the exact same way `window_drag` already did.
2. **The test's precondition (Finder's "remembered" window size) is itself unpredictable and can be dangerously
   large.** Even with the restore fix, a 5-run pool using a fresh Finder window each time still drifted
   (`window_resize.a` 60->41, `window_drag.b` 24M->75M) - the fresh windows were defaulting to Finder's own
   remembered size, `1600x1007`, inherited from whatever a window was last left at. On this G5's `1920x1080` display,
   that size's resize-drag target (`+150,+100` from the corner) lands at `(1750, 1107)` - **27px past the bottom of
   the actual screen.** Partially-off-screen synthetic mouse events behave inconsistently depending on exact timing/
   clipping, which is what produced the apparent "noise." **Fixed (process, not code)**: explicitly set the test
   window to a known-safe, fully-on-screen size (`{100,100,700,500}`) before every run, rather than trusting
   whatever size Finder happens to remember.

`idle`'s own apparent noise in the original 13-metric finding turned out to be a *third*, separate, already-
understood effect (not a bug): `idle.a`/`idle.b` genuinely read `0.000` at true rest and a real nonzero value right
after a fresh window is created - confirmed directly via `cgs_probe.c` (a standalone diagnostic that samples the raw
call in a tight loop with zero real activity: `a`/`b` pinned at `0.000` for 20/20 samples) and a clean A/B test (same
process, immediately consecutive runs, window-just-opened vs not). This isn't noise, it's the metric correctly
reporting two different real system states - a consistent precondition (always a fresh window immediately before
measuring, which this baseline now does) makes it a non-issue.

## Method

Same as `../desktop_compositing_20261006/README.md` describes (six scenarios, `CGPostMouseEvent`/
`CGPostScrollWheelEvent`, `CGSGetPerformanceData` sampled every tick) - only the fix and the controlled precondition
are new. See that file for the full mechanism note (how the private call was found, what the four raw values are).

## Result (5 runs, `run1.txt`-`run5.txt`)

**0 of 24 metrics exceed a 25% run-to-run spread.** Representative medians:

| scenario | a (median) | b (median) | c (median) | d (median) |
|---|---:|---:|---:|---:|
| idle | 0.000 | 0.000 | 80.2 | 61.9 |
| window_open | 9.5 | 2,101,583 | 265.6 | 333.0 |
| window_drag | 55.0 | 15,954,381 | 253.6 | 344.7 |
| window_resize | 59.6 | 20,679,640 | 512.4 | 1,391.1 |
| scroll | 0.000 | 0.000 | 129.3 | 369.1 |
| dock_hover | 59.4 | 6,061,256 | 257.8 | 1,025.0 |

`idle` and `scroll` both genuinely read `0`/near-`0` for `a`/`b` now (consistent with the true-rest probe) - this is
correct, not a measurement failure; `c`/`d` stay small and nonzero for both, consistent with `cgs_probe.c`'s finding
that those two have their own small inherent baseline even at absolute rest.

## Standing enforceable gate

This baseline is now safe to use as the regression gate #44 asks for. **Any future run against this baseline must
use the same controlled precondition** (a fresh Finder window explicitly set to `{100,100,700,500}` immediately
before invoking the test) - comparing against a run that used a different window size/position would reintroduce
exactly the noise this investigation eliminated.
