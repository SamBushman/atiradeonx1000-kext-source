# VA capture kit (issue #93, DVD `doIDCT`)

Purpose: learn, from a **real player**, how the VA driver (`ATIRadeonX1000VADriver.bundle`) uses the kext's DVD context - the `set_surface` / `setup_buffers` / `write_buffer` arguments and the `doIDCT` parameter blocks and
buffers - so #93's valid-path phases can be derived from evidence instead of guessed. Everything here is a **passive observer**: the recorder forwards every call unchanged and never makes a call of its own;
`watch_hw_path.sh` only reads `ioreg`/`kextstat`. The stock kext stays loaded; nothing is written to hardware by this kit.

## Files
| file | role |
|---|---|
| `iokit_record_va.c` | `DYLD_INSERT_LIBRARIES` shim (superset of `Tools/userspace/iokit_record.c`): logs `IOServiceOpen/Close`, `IOConnectMapMemory`, all four `io_connect_method_*` MIG routines the VA bundle imports, and dumps the first `VA_DUMP_BYTES` (4096) of every mapped buffer before each doIDCT-shaped call (`structureI_structureO`, selector 18, struct >= 0x34 bytes), at most `VA_DUMP_MAX` (64) calls |
| `record_selftest.c` | proves the recorder on the G5 with the already-proven-safe Surface `get_state` (done: log `get_state -> 0x0 out=0x1`, recorded) |
| `make_streams.sh`, `streams/*.mpg|vob` | three 4-second synthetic MPEG-2 streams (720x480 NTSC with B frames, the same as a DVD VOB, and a 352x240 control), generated with ffmpeg (6 MB) |
| `author_video_ts.sh`, `dvd/disc/VIDEO_TS/` | DVD Player only opens a disc folder, not a bare .mpg (confirmed: it refuses the .mpg). The script authors a one-title NTSC disc (30 s, 720x480, AC-3 stereo) from `streams/test_ntsc_dvd.vob` with dvdauthor 0.7.2+ (build recipe in the script); the result `dvd/disc/` has `VIDEO_TS.IFO/BUP`, `VTS_01_0.IFO/BUP`, `VTS_01_1.VOB` |
| `install_on_g5.sh` | copies this folder to `/tmp/va_cap` on the G5, builds the dylib there (`gcc -dynamiclib ... -framework IOKit -framework CoreFoundation`) and runs the self-test (**already run: INSTALL_OK**) |
| `watch_hw_path.sh` | ON THE G5, read-only: once per second counts DVD/GL/2D/Surface user clients; "max DVD contexts seen: 0" means the player decoded in software (the hardware IDCT path was not used) |
| `play_with_recorder_quicktime.command`, `..._dvdplayer.command`, `..._vlc.command` | double-click launchers: start the player binary directly with the recorder inserted and the watcher running; logs go to `/tmp/va_cap/rec_<time>.tsv` (+ `.mem`) and `hw_watch_<time>.log` |
| `analyze_capture.py` | dev-machine summary of a capture: connections, selector sequence per context, set-up call arguments, mapped regions, every doIDCT-shaped call decoded as `sATIDVDIDCTParams`, `.mem` heads |
| `va_callsites.txt` | static scan of the VA bundle: only three constant-selector call sites (1, 16, 0) are found; the doIDCT site (`FUN_00005fd0`) was later found by reading the decompile (issue #140) - a live capture is no longer needed to learn the stream format |

## Procedure (needs a person at the G5 console: a GUI app started from ssh deadlocks Cocoa on this machine)
1. Dev machine: `sh Tools/userspace/va_capture/install_on_g5.sh` (already done once; repeat after editing the recorder).
2. At the G5: double-click `/tmp/va_cap/play_with_recorder_quicktime.command` (QuickTime Player has `QuickTimeMPEG2.component`), play the stream to the end, quit the player. Repeat with the `dvdplayer` and `vlc`
   launchers if the first shows no DVD context (the stream can also be passed as an argument: `sh /tmp/va_cap/play_with_recorder_vlc.command /tmp/va_cap/streams/test_ntsc_dvd.vob`).
3. Look at `/tmp/va_cap/hw_watch_*.log`: `max DVD contexts seen: 0` -> this player is not using the driver's hardware path (try another player / stream); >= 1 -> go on.
4. Copy `/tmp/va_cap/rec_*.tsv`, `rec_*.tsv.mem` and `hw_watch_*.log` back to the dev machine and run `python3 Tools/userspace/va_capture/analyze_capture.py rec_<time>.tsv`.
5. Record the findings in #93 (what the VA driver passes to `set_surface` / `setup_buffers`, the `sATIDVDIDCTParams` words, the mapped buffer layout). Only after that can anyone decide whether a valid-path run of `doIDCT` is
   justifiable; the hang/lock recovery protocol of #87 applies to any such run.

## DVD Player
Use `play_with_recorder_dvdplayer.command` (default argument `/tmp/va_cap/dvd/disc`); if DVD Player does not open the folder from the command line, use its File > Open VIDEO_TS Folder... on `/tmp/va_cap/dvd/disc` (the player is already running with the recorder loaded).

## Results so far
* QuickTime Player + `test_ntsc_720x480.mpg`: **software path** - `hw_watch` saw DVD contexts = 0 for the whole run (only GL 1-6, 2D, Surface); 109 recorded calls, none on a DVD connection; no doIDCT-shaped call (`captures/rec_000950.tsv`). DVD Player refuses the bare .mpg.
* DVD Player + the authored disc (`dvd/disc`, 30 s): **also software path**. `captures/hw_watch_001822.log`: DVD contexts = 0 throughout (GL 1-2, 2D 2-3, Surface 1-2). `captures/rec_001822.tsv` (504 lines): client types opened = Surface x11, GL x33, 2D x1 and **no type 3 (DVD)**; no doIDCT-shaped call, no .mem file. It did call 2D `set_macrovision` (selector 15) five times, all with scalar 0 and rc 0 - the same call/value #89 ran, so a real client sends exactly that. Conclusion: on this Tiger/X1900 setup neither player uses the kext's DVD context, so the hardware IDCT path cannot be captured this way.

## Known unknowns
* Whether Apple's players use this driver's hardware IDCT path on the X1900 at all (step 3 answers it).
* Which player/stream triggers it (DVD Player normally wants a VIDEO_TS folder; dvdauthor was built locally to author the disc folder).
