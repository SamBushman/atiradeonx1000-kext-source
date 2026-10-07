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
