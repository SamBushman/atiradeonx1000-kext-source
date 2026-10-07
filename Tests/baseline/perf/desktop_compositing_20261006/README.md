# 2D/desktop-compositing baseline, automated (2026-10-06)

First automated baseline for issue #44's last open item, replacing the single-session, human-at-the-console
methodology in `Tests/performance_plan.md` section 8. Produced by `Tests/perf_2d_compositing.c`.

## Method

Six scenarios (idle, window open/close, window drag, window resize, scroll, Dock hover), each driven by real
synthetic input (`CGPostMouseEvent`/`CGPostScrollWheelEvent` - Tiger-native Quartz Event Services, posts at the HID
level against the already-running login session) for 200 ticks at a 16ms pace (~3.2s/scenario). Every tick samples
the private `CGSGetPerformanceData()` call directly - found by disassembling Quartz Debug's own binary (`otool -tV`,
not guessed), the same call its own Frame Meter gauge is fed from. This replaced an earlier screenshot + needle-
angle-reading draft of this same file: that approach worked (a real, cross-validated pixel calibration was derived)
but cost ~1.1s per sample (full-screen `screencapture` - there is no faster non-invasive capture path on this SDK),
capping it at a handful of samples per gesture. Calling the data source directly costs nothing per sample, so this
baseline has n=200 per scenario instead of a handful.

## Result (`run1.txt`, `env.txt` for machine state)

Four raw values (`a`,`b`,`c`,`d`) are reported per scenario - which one (or what derived combination) matches the
Frame Meter's own displayed 0-90 number is **not established**: Quartz Debug's binary runs a block of dense
floating-point math on values derived from this call before displaying anything, and that block was not fully
traced. All four move together and increase monotonically with real redraw load on this machine:

| scenario | a (median) | b (median) | c (median) | d (median) |
|---|---:|---:|---:|---:|
| idle | 25.1 | 12,869 | 188.8 | 139.0 |
| window_open | 31.1 | 1,616,482 | 374.1 | 426.6 |
| window_drag | 56.9 | 9,325,360 | 327.9 | 418.9 |
| window_resize | 60.3 | 12,427,906 | 537.7 | 1,389.9 |
| scroll | 25.5 (p90 47.9) | 411,901 (p90 7,989,713) | 241.6 (p90 426.7) | 444.8 (p90 1,013.3) |
| dock_hover | 61.3 | 6,570,616 | 316.9 | 1,117.4 |

`scroll`'s median sits near idle with a much higher p90/max - consistent with the scenario alternating scroll
direction every 30 ticks (`Tests/perf_2d_compositing.c`'s `step_scroll`), so roughly half the window is a brief lull
between direction reversals, not a sign the gesture is weak.

## Deliberate tradeoffs and caveats

- **Not claimed to match the original manual session's reported "~5-35 fps" numbers.** Synthetic input may drive a
  genuinely different (plausibly lower, or just differently-shaped) redraw cadence than a real hand on a real mouse -
  this is an accepted tradeoff (the user's own call, 2026-10-06): full byte-for-byte repeatability matters more for
  an actual regression gate than matching an old human-eyeballed number.
- **Not a fresh boot** (4h17m uptime at capture time - see `env.txt`). Per this project's own established finding
  (`Tests/performance_plan.md` section 2), uptime can move numbers by up to 2x. Treated the same as the original
  manual session, which was also not fresh-boot.
- **Single run, not yet repeated.** The GL-side baselines were run 3-5x to apply the project's noise/regression rule
  (`Tools/perf_compare.py`); this is a first data point establishing the method works end to end, not yet a hardened
  gate.
- **An unrelated, pre-existing visual artifact was noticed during this session**: a Firefox window showing a
  "Restore Previous Session" prompt was visible on screen with no live Firefox process behind it (confirmed via
  `ps` - nothing running). This predates this automation (nothing in `perf_2d_compositing.c` targets or clicks
  Firefox or any Dock icon - `step_dock` only moves the cursor, button state always up) and is almost certainly a
  stale WindowServer-cached window image from an earlier, unrelated session - noted here for the record, not
  something this work caused or needed to clean up.

## Mechanism note (for anyone extending this)

`CGSGetPerformanceData(cid, &out1, &out2, &out3, &out4)` - `cid` from `_CGSDefaultConnection()`. All five are
private/undocumented (no header anywhere on this system declares them; found and the argument order confirmed via
PPC disassembly of `/Developer/Applications/Performance Tools/Quartz Debug.app`'s own binary, cross-referenced
against `/usr/sbin/screencapture`'s use of the related `_CGContextCopyDisplayCaptureContentsToRect` during this same
investigation). Pinning down which output corresponds to the Frame Meter's exact displayed value would need tracing
the dense FP block at `Quartz Debug` binary offset ~0x6a48-0x6c00 (computes something from `host_processor_info`
CPU-tick deltas combined with these four values) - not attempted here, since all four already serve this baseline's
actual purpose (a real, reproducible load signal) without it.

## Repeat pass (2026-10-07): real noise found, not just "more data"

Ran twice more (`run2.txt`, `run3.txt`) to apply this project's noise/regression rule (same spirit as `Tools/perf_compare.py`'s own `S`/`noise`/`margin` computation, computed directly here since that tool is wired specifically to `perf_methods.c`/`perf_baseline.c`'s file-naming convention, not this baseline's). Result: **13 of 24 metrics exceed a 25% run-to-run spread** across the 3 runs - this baseline is substantially noisier than the GL or DVD/IDCT baselines, and that noise is not evenly spread:

- **Steady-state continuous gestures' primary value is tight**: `window_drag.a` spread 0.2%, `window_resize.a` 5.5%, `dock_hover.a` 3.4% - these are trustworthy as-is.
- **Transient/history-dependent scenarios are not**: `idle.c`/`idle.d` (159%/125%) - `idle.a`/`idle.b` even read exactly `0.000` in two of three runs but a real nonzero value in the first, i.e. "idle" isn't a stable "nothing happening" reading, it's sensitive to how recently a window changed (the first run followed right after opening the test's own Finder window; runs 2-3 followed immediately after run 1, with no intervening state change, and caught a more truly-settled idle). `window_open.*` (32-220%) and most of `scroll.*` (except `.d`) are similarly noisy - both are inherently bursty/transient events, not steady continuous ones.
- **The `b` metric specifically is noisy almost everywhere it's large** (`window_drag.b` 100%, `window_resize.b` 89%, `window_open.b` 95%) - whatever this raw value tracks (undetermined, see the mechanism note above), it does not average out the way `a`/`c`/`d` mostly do.

**Practical implication**: this baseline is not yet a reliable regression gate across all its metrics as currently measured. The continuous-gesture `a` values are solid; the transient-scenario and `b`-metric values need either more repeats, a different sampling window, or acceptance that they're inherently high-variance signals not suited to a tight numeric gate. Recorded here plainly rather than treated as settled by simply having more runs - a future regression check using this baseline should weight metrics accordingly (or restrict itself to the metrics shown stable here) rather than trust all 24 equally.

## SUPERSEDED (2026-10-07): root cause found and fixed - see `../desktop_compositing_20261007_fixed/`

The "noise" above was investigated further rather than accepted as inherent. Two real, distinct causes were found
and fixed (not just documented): `window_resize` was missing a restore-to-original-size step that `window_drag`
already had (so repeated runs permanently grew the test window), and separately, Finder's own "remembered" window
size can be large enough on this G5's `1920x1080` display that the resize/drag gestures' target coordinates land
off-screen, producing inconsistent synthetic-input behavior. `idle`'s own apparent noise was a third, different
thing - not a bug at all, a real and correct state-dependent reading (confirmed via a standalone `CGSGetPerformanceData`
probe at true rest) that just needs a consistent precondition to be comparable run-to-run.

`run4.txt` through `run10.txt` were added here during that investigation (7 more runs, same unfixed binary/
precondition as `run1`-`run3`) specifically to get a large enough pool to see the drift as a real trend rather than
apparent randomness - **note the file listing sorts lexicographically (`run1, run10, run2, run3, ...`), which
scrambles the actual time order; reorder by run number before reading any trend out of them.** Once correctly
ordered, `window_resize.a` shows a clean monotonic decay (~60 -> ~2) and `window_drag.b` a clean rise-then-plateau
(~9M -> ~65M) across the 10 sequential runs - this is what led to finding the missing-restore bug, not further
evidence of inherent randomness.

The fixed `Tests/perf_2d_compositing.c` plus a controlled precondition (explicit window size, not Finder's
remembered default) produces **0 of 24 metrics exceeding 25% spread** - see `../desktop_compositing_20261007_fixed/README.md`
for the full writeup. Use that baseline going forward; this directory is kept for the historical investigation trail.
