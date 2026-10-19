# Full evaluation of a rebuilt-driver build (stock vs rebuilt)

Written Oct 18 for tip `0c80ead` (kext built `-Os`, staged by `sh Tools/stage_for_test.sh`). Every phase compares the rebuilt kext with the stock 4.1.9 kext on the same G5. First full run: Oct 18-19 on tip `06f8492` (status table at the end).
Paths: `S=~/rung3/src_<sha>` (sources + built tests) and `K=kext_build_<sha>` on the G5; `swap.sh` loads `~/rung3/$K`. Evidence goes in `~/g5logs/final_eval/` (dev) and `~/rung3/final_eval/` (G5), never /tmp.

## Rules that apply to every phase
- Hot-swap only (`sh ~/rung3/swap.sh $K`, then `cd $S && sh Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh`). **No boot-time install until every other phase passes** (Phase 9 needs an explicit go-ahead).
- **Never hot-swap back to stock after client activity** (#179 panics): each "side" of a consumer test starts from a fresh boot. Plan the order so that stock work happens first on a boot, then swap to rebuilt, then reboot.
- Precheck before each phase: `ssh G5 'ps auxww | egrep -i "godot|soak|crashdump"'` (a `Z` crashdump zombie is normal) and `kextstat | grep ATIRadeon`.
- Watchdog on the dev machine for every long phase: `Tools/stability_watch.sh -l ~/g5logs/final_eval/watch_<phase>.tsv G5 &`. After a hang/panic: power-cycle, pull `/Library/Logs/panic.log` (diff the body, not the mtime), `diskutil verifyVolume` on every volume, then continue.
- Every divergence from stock is a NEW issue (label `rebuilt-kext-defect`), never a reopened one. A stock-only misbehaviour is `stock-driver-bug`.
- **Export the environment in the same Bash call as the script:** `REBUILT_DIR=kext_build_<sha> STOCK_DIR=stockkext SRC=src_<sha> KEXT=kext_build_<sha>`. The scripts default to `kext_build_fix`, which is the wrong tip (a sweep once started that way).
- **The watchdog dies when the G5 reboots.** For reboot-heavy phases run it in a restart loop (`while :; do sh Tools/stability_watch.sh -i 20 -d 3000 -l ...watch_<phase>_$n.tsv G5; sleep 15; done`), started with `setsid nohup ... </dev/null &`.
- **A reboot can take up to ~10 min** (SonnetSATA card initialisation); "No route to host" for several minutes is not by itself a hang. Ping first; power-cycle only after ~15 min of silence. After every reboot check Test HD is mounted, `grep -c "Failed OOB" /var/log/system.log` and `panic.log` size. A stall can also recover on its own (#190).
- Start long jobs detached (`setsid nohup ... </dev/null >log 2>&1 &`); a foreground ssh/pipe keeps the tool call open.
- The shared 4K monitor can re-handshake (display flips 1920x1080@60 -> 3840x2160@30; the `hwup_sampler` log shows the flap). It stops a soak (parity diff on display info). It is environmental, not a driver defect: restore with the unstick script, move the log aside, restart. Above 1080p the DVI-to-HDMI link needs more than 165 MHz (single-link limit); the monitor EDID itself advertises 1440p60 and 4K30.
- Not safe, never run: broad-fuzz IOConnectMethod calls, kernel memory scans, `glstress`/window fastclear modes, system sleep (#180), the `*_inject` T3 tests.

## Phase 0 - Gates (dev machine; run for the tip before staging)
`python3 Tools/apply_renames.py --check` = 0 errors; `sh Tests/difftest/run_all.sh` = all PASS (553); `sh Tools/verify_identical_build.sh G5` = IDENTICAL; `sh Tools/stage_for_test.sh G5` = STAGED.

## Phase 1 - Stock reference on this boot (stock loaded, nothing swapped)
All on the G5 from `$S/Tests`; results into `~/rung3/final_eval/stock_*`.
1. Interface parity baseline: `sh compare_to_baseline.sh` and `DEEP=1 sh compare_to_baseline.sh` (must be IDENTICAL to the recorded stock baselines; this proves the machine is in the known state).
2. GL feature suite: `sh run_gl_feature_suite.sh ~/rung3/final_eval/stock_gl 120` (about 90 self-checking programs checked against the GL spec formulas plus `cgl_probe`). Stock is known to fail some (#129-#139, userspace GLDriver bugs): the stock result is the reference, not "all pass".
3. Performance: `sh perf_collect.sh ~/rung3/final_eval/stock_perf 5 50000 100` (per-method call cost + GL create/draw/readback cycles, 5 repetitions).
4. Opcode battery (GL): `cd Tools/userspace && sh run_all_opcode_workloads.sh ~/rung3/final_eval/stock_opcodes` (needs `opcode_recorder.dylib`, `glcov`, `glwin`; Godot game and editor 40 s each; the Godot paths are hard-coded on Test HD). Compare against `Tests/baseline/opcode/`.

## Phase 2 - Rebuilt, same boot (hot-swap)
1. `sh ~/rung3/swap.sh $K` then the unstick script; confirm `kextstat` shows the rebuilt bundle and a new load address.
2. Repeat Phase 1 steps 1-4 into `rebuilt_*` directories. Verdicts:
   - harness: `compare_to_baseline.sh` IDENTICAL for the normal suite; the deep suite may differ only in the known hot-swap artifacts (leak-check instance counts `{0,0,0,0,0,2}` vs `{1,2,1,0,1,2}` and the flaky `GL wait_for_stamp(5)`), which must also reproduce on hot-swapped stock to count as artifacts.
   - GL features: `sh compare_gl_feature_runs.sh ~/rung3/final_eval/stock_gl ~/rung3/final_eval/rebuilt_gl` = IDENTICAL.
   - perf: `python3 Tools/perf_compare.py` on the two `perf_collect` directories: no regression beyond noise.
   - opcodes: every opcode seen on stock is seen on rebuilt (`Tools/opcode_usage.py`), 0 anomalies.
3. Reboot to stock.

## Phase 3 - Interleaved performance (the scripts swap by themselves; dev machine)
- 2D compositing + WindowServer gestures: `sh Tools/perf_2d_compare.sh ~/g5logs/final_eval/perf2d 3 4 200` (A B A B, 12 runs a side; read with `Tools/perf_2d_report2.py`). Needs `~/rung3/gest2d.sh` (`Tests/perf_2d_gestures.sh`) on the G5; both hard-code `~/rung3/srchead`, which still exists.
- Godot frame rate: `sh Tools/godot_fps_compare.sh ~/g5logs/final_eval/godotfps 3 90` then `Tools/frame_rate_from_log.py` on each `game.tsv`.
- GL userspace perf: `SRC=src_<sha> REBUILT_DIR=... STOCK_DIR=stockkext sh Tools/perf_gl_userspace_compare.sh ~/g5logs/final_eval/glperf 3` (interleaved A B A B of the five `perf_gl_*` programs), then `python3 Tools/perf_compare.py OUT/stock OUT/rebuilt`.

## Phase 4 - Consumers, each side from a FRESH BOOT (dev machine)
- Installed-application sweep: `sh Tools/sweep_fresh_boots.sh ~/g5logs/final_eval/sweep` (ends with a reboot to stock).
- Video: `sh Tools/video_fresh_boots.sh ~/g5logs/final_eval/video` (QuickTime and VLC under the passive recorder; `SIDES`/`JOBS` env override the order). **A boot-time stock driver and a hot-swapped rebuilt one behave differently for QuickTime (type-2 accelerator calls); that is a hot-swap artifact, not a defect. Always add a control with hot-swapped stock (`video_control_stockswap`) before filing.**
- DVD Player on the generated disc: **one side per boot** (#190: unloading hot-swapped stock after DVD Player use stalled the G5). `SEQ=stock sh Tools/dvd_disc_compare.sh OUT 60`, reboot, then `SEQ=rebuilt ...` (the default `stock rebuilt` sequence in one boot is unsafe). Compare the `.watch` counts (dvd=1 gl=1 2d=1 surface=1) and the screenshots. Run alone with the watchdog, never during a soak. Oct 14: launching DVD Player once hung the hot-swapped rebuilt kext; that did not recur on `06f8492`.
- Display sleep/wake (not system sleep, #180): `sh Tools/display_sleep_test.sh ~/g5logs/final_eval/dsleep boot 3` and `... rebuilt 3`.

## Phase 5 - Soak (4 h, rebuilt hot-swapped + unstick, nothing else running)
`cd $S/Tests && LOG=$HOME/rung3/final_eval/soak.log MASK_INSTANCE_COUNTS=1 nohup sh soak.sh 14400 &`, watchdog on the dev machine, and optionally `Tools/soak_consumers.sh` alongside (QuickTime, DVD Player, 2D compositing). Start it with `</dev/null` on the ssh. Pass = log ends `SOAK DONE`, 0 unrecovered failures, watchdog `OK`. If it stops with `STEP-DIFF ... differs` showing display info `0x7800438 -> 0xf000870`, that is the monitor re-handshake (see Rules): restore 1080p, move the log aside, restart.

## Phase 6 - T3 destructive checklist (27 tests, one per boot, rebuilt)
`sh Tools/t3_phaseR_all.sh` (or one at a time: `sh Tools/t3_phaseR_one.sh NAME reboot`). Each test hot-swaps the rebuilt kext, runs the #87 protocol (preflight, test, postflight) and compares its RESULT lines with the recorded Phase S log in `$S/Tests/destructive/phaseS`; the machine reboots between tests. Summary: `~/g5logs/t3_phaseR/summary.tsv` (0 = same as stock, 1 = DIVERGENCE -> new issue, 3 = HANG). Known open: #116/#158 history; #90 untouched. Run with `SRC=src_<sha> KEXT=kext_build_<sha>` exported, detached (`setsid nohup sh Tools/t3_phaseR_all.sh > ~/g5logs/final_eval/t3_all.out 2>&1 </dev/null &`), from a fresh stock boot (the script refuses to start if stock is not loaded). Verified end to end on the G5 Oct 19 (`2d_declare_image`: SAME AS STOCK). The runner's 300 s hang check applies only while a test runs; the wait after each reboot is unbounded. Expect 27 x (6-8 min + a reboot that can take ~10 min).

## Phase 7 - Repeat Phase 1 harness check after the T3 reboots
`sh compare_to_baseline.sh` and the deep variant on a fresh stock boot: the machine must be back in the known state (no volume damage: `diskutil verifyVolume /` and Test HD).

## Phase 8 - Consumers that need a person (mostly automatable; human look only before a closure)
GUI apps launch from SSH inside the console session with `open -a Terminal x.command` (real pixels; the old `bootstrap_register` failure only affects direct SSH launch). Synthetic mouse/keyboard (`CGPostMouseEvent`) and WindowServer performance data work over SSH, so Godot, WindowServer gestures, Expose and Dashboard can be driven by script with screenshots (Phase 3 already does Godot and gestures this way); Expose/Dashboard automation is untried. A person is needed only to look at the screenshots before closing a hardware bug, because automated evidence alone does not close one.

## Phase 9 - DVD IDCT performance (boot-time install; ONLY with the user's explicit go-ahead)
Back up the stock binary + mkext (`~/rung3/bootinstall_backup`), install the rebuilt binary into `/System/Library/Extensions`, rebuild the mkext, run `Tests/perf_dvd_idct` against a fresh stock baseline, then RESTORE stock and reboot. Recovery if boot hangs: Option-key boot to Sorbet HD, restore from the Tiger HD mount (Sorbet itself stays untouched).

## Report
One table per phase: pass / divergence (issue #) / not run, with the evidence directory. Update `project_kext_naming_cleanup` memory and comment on #122 and #45.

## Status of the Oct 18-19 run on `06f8492`
| Phase | Result | Evidence (`~/g5logs/final_eval/`) |
|---|---|---|
| 3 2D compositing, Godot fps, GL userspace perf | pass, no divergence | perf2d, godotfps, glperf |
| 4 sweep (9/9 apps), VLC | pass | sweep, video, video_repeat |
| 4 QuickTime | not a defect (hot-swap artifact, control identical) | video_control_stockswap |
| 4 DVD | pass (dvd=1 gl=1 2d=1 surface=1 both sides, screenshots identical); the same-boot stock-then-rebuilt sequence stalled the G5: #190 | dvd, dvd_hang |
| 4 display sleep | pass, 3/3 both sides | dsleep |
| 5 soak 4 h | pass (751 rounds, 14416 s, 0 transients); attempt 1 stopped at 17 min on a monitor re-handshake | soak |
| 6 T3 27 tests | in progress | `~/g5logs/t3_phaseR/summary.tsv` |
| 7, 8, 9 | not run yet (9 needs the user's go-ahead) | |
