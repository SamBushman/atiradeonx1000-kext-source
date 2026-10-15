# Consumer-application runs, stock vs rebuilt (2026-10-15, #45 gap closing)

All automated (no person at the console): the G5's own Aqua session is driven with `open -a Terminal x.command`, `open -a`, synthetic mouse (`Tools/gui_input.c`) and screenshots. Hot-swap unless stated. Rebuilt = `95edbd2` binary md5 `2de86c49...` throughout.

## Godot game, real GL application frame rate (`../perf/godot_fps_20261015/`)
`Tools/godot_fps_compare.sh`: stock/rebuilt interleaved x3, 90 s each, Godot game under `Tools/userspace/opcode_recorder.c` (rebuilt on the G5: the 2026-10-03 copy lacked the FLUSH `t_us` field), `Tools/frame_rate_from_log.py`. GL flushes in 90 s: stock 10802 / 10798 / 10858, rebuilt 10815 / 10813 / 10825 (about 120 per second on both, spread 0.5 %; no crash, no panic). Per-run median derived fps 101-112 stock, 112-150 rebuilt (one 149.5 outlier), p10 frame time 1.51-1.52 ms and p90 15.2 ms on every run of both: the frame-time distribution is the same.
(The 2026-10-04 baseline of 60.6 fps / 59 flushes per second was a different run condition; compare only within this table.)

## Generated DVD disc (`dvd_disc*`)
A 30 s NTSC DVD-Video disc was authored (`Tools/userspace/va_capture/author_video_ts.sh` with dvdauthor built from source, test pattern with a burned-in timecode and frame counter), wrapped as a UDF/ISO image (`hdiutil makehybrid`) and mounted on the G5; DVD Player plays it (a mouse click answers its "previously viewed disc" dialog).
* **Boot-time stock driver:** plays in real time (frame 519 at 17.317 s = 29.97 fps), finishes and returns to black. DVD contexts opened: 0 (the software decode path, as established in `Tools/userspace/va_capture/README.md`).
* **Hot-swapped, stock AND rebuilt:** DVD Player shows the first frame and never advances (timecode 0, frame 0, at +30 s and +65 s). The four screenshots (stock hot-swap 30 s / 65 s, rebuilt hot-swap 30 s / 65 s) are **byte-identical** (md5 5c96c258...). This matches the earlier finding that DVD readiness is a boot-time property that a hot-swap does not reproduce, so disc playback can only be compared with the rebuilt kext as the BOOT-TIME driver (not done; that is the boot-time test, deliberately last).
* No panic or hang with rebuilt disc playback from a fresh boot. Hot-swapped stock then unloaded after DVD Player use panicked in `stop()` (#179, `stock-driver-bug`; `Tests/baseline/panics/`): never swap after DVD Player use, reboot between sides.
