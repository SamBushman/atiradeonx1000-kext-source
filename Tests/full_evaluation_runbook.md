# Full evaluation of a rebuilt-driver build (stock vs rebuilt)

Written Oct 18 for tip `3c31d03` (kext built `-Os`, staged by `sh Tools/stage_for_test.sh`). Every phase compares the rebuilt kext with the stock 4.1.9 kext on the same G5.
Paths: `S=~/rung3/src_<sha>` (sources + built tests) and `K=kext_build_<sha>` on the G5; `swap.sh` loads `~/rung3/$K`. Evidence goes in `~/g5logs/final_eval/` (dev) and `~/rung3/final_eval/` (G5), never /tmp.

## Rules that apply to every phase
- Hot-swap only (`sh ~/rung3/swap.sh $K`, then `cd $S && sh Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh`). **No boot-time install until every other phase passes** (Phase 9 needs an explicit go-ahead).
- **Never hot-swap back to stock after client activity** (#179 panics): each "side" of a consumer test starts from a fresh boot. Plan the order so that stock work happens first on a boot, then swap to rebuilt, then reboot.
- Precheck before each phase: `ssh G5 'ps auxww | egrep -i "godot|soak|crashdump"'` (a `Z` crashdump zombie is normal) and `kextstat | grep ATIRadeon`.
- Watchdog on the dev machine for every long phase: `Tools/stability_watch.sh -l ~/g5logs/final_eval/watch_<phase>.tsv G5 &`. After a hang/panic: power-cycle, pull `/Library/Logs/panic.log` (diff the body, not the mtime), `diskutil verifyVolume` on every volume, then continue.
- Every divergence from stock is a NEW issue (label `rebuilt-kext-defect`), never a reopened one. A stock-only misbehaviour is `stock-driver-bug`.
- Not safe, never run: broad-fuzz IOConnectMethod calls, kernel memory scans, `glstress`/window fastclear modes, system sleep (#180), the `*_inject` T3 tests.

## Phase 0 - Gates (dev machine, done for 3c31d03)
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
- GL userspace perf (`Tests/userspace/perf_gl_*`): run `perf_gl_features`, `perf_gl_pipeline`, `perf_gl_scale`, `perf_gl_statechange`, `perf_gl_upload` on stock, rebuilt, stock again (A B A) and compare.

## Phase 4 - Consumers, each side from a FRESH BOOT (dev machine)
- Installed-application sweep: `sh Tools/sweep_fresh_boots.sh ~/g5logs/final_eval/sweep` (ends with a reboot to stock).
- Video: `sh Tools/video_fresh_boots.sh ~/g5logs/final_eval/video` (QuickTime and VLC under the passive recorder).
- DVD Player on the generated disc: `sh Tools/dvd_disc_compare.sh ~/g5logs/final_eval/dvd 60`. **Known hazard:** on Oct 14 launching DVD Player hung the hot-swapped rebuilt kext (twice); run it alone, with the watchdog, never during a soak; a hang here is expected-to-investigate, not a surprise.
- Display sleep/wake (not system sleep, #180): `sh Tools/display_sleep_test.sh ~/g5logs/final_eval/dsleep boot 3` and `... rebuilt 3`.

## Phase 5 - Soak (4 h, rebuilt hot-swapped + unstick, nothing else running)
`cd $S/Tests && LOG=$HOME/rung3/final_eval/soak.log MASK_INSTANCE_COUNTS=1 nohup sh soak.sh 14400 &`, watchdog on the dev machine, and optionally `Tools/soak_consumers.sh` alongside (QuickTime, DVD Player, 2D compositing). Pass = log ends `SOAK DONE`, 0 unrecovered failures, watchdog `OK`.

## Phase 6 - T3 destructive checklist (27 tests, one per boot, rebuilt)
`sh Tools/t3_phaseR_all.sh` (or one at a time: `sh Tools/t3_phaseR_one.sh NAME reboot`). Each test hot-swaps the rebuilt kext, runs the #87 protocol (preflight, test, postflight) and compares its RESULT lines with the recorded Phase S log in `$S/Tests/destructive/phaseS`; the machine reboots between tests. Summary: `~/g5logs/t3_phaseR/summary.tsv` (0 = same as stock, 1 = DIVERGENCE -> new issue, 3 = HANG). Known open: #116/#158 history; #90 untouched. **The two scripts were written Oct 18 and have not run on the G5 yet: watch the first test by hand.** Expect about 27 x 6-8 min.

## Phase 7 - Repeat Phase 1 harness check after the T3 reboots
`sh compare_to_baseline.sh` and the deep variant on a fresh stock boot: the machine must be back in the known state (no volume damage: `diskutil verifyVolume /` and Test HD).

## Phase 8 - Consumers that need a person
Godot at the console (SSH launch fails with `bootstrap_register`), WindowServer gestures by hand, Expose/Dashboard; a human check is required before closing any hardware bug on automated evidence alone.

## Phase 9 - DVD IDCT performance (boot-time install; ONLY with the user's explicit go-ahead)
Back up the stock binary + mkext (`~/rung3/bootinstall_backup`), install the rebuilt binary into `/System/Library/Extensions`, rebuild the mkext, run `Tests/perf_dvd_idct` against a fresh stock baseline, then RESTORE stock and reboot. Recovery if boot hangs: Option-key boot to Sorbet HD, restore from the Tiger HD mount (Sorbet itself stays untouched).

## Report
One table per phase: pass / divergence (issue #) / not run, with the evidence directory. Update `project_kext_naming_cleanup` memory and comment on #122 and #45.
