# G5 game benchmarks: stock vs RENAMED kext + RENAMED userspace GLDriver (Nov 2 2026)

Machine: Power Mac G5 quad, Tiger 10.4.11, X1900 (GL 1.5 ATI-1.4.19), 16 GB. Stock = Apple ATIRadeonX1000 4.1.9 (md5 9c7a9fff…) + Apple ATIRadeonX1000GLDriver (md5 5d63b5e3…). Renamed kext = `kext_build_575ad528` (md5 43d82745…, kext sources unchanged since; difftest 907/907, compare_to_baseline normal+DEEP IDENTICAL on the installed build). Renamed GLDriver = repo HEAD 88ce65c9 (md5 a0c7d7e9…, `-O0`; GL feature suite byte-identical to stock, 81/82 installed + 80/82 via redirect, only printed pointers differ; same 3 stock failures). Both installed in `/System/Library/Extensions` (binary only, stock Info.plist), kextd-loaded (0x7582f000), one configuration per boot, no hot-swap. Stock reference data: Oct 21-22 runs (`~/g5logs/gamefps/ut2004_run3`, `doom3_run3`); Halo stock re-measured on a fresh boot after the restore.

## Result in one table (avg FPS, higher is better)
| Test | Stock | Renamed kext + stock GLDriver | Renamed kext + renamed GLDriver (-O0) |
|---|---|---|---|
| UT2004 DM-Antalus_high (3 visits) | 73.54 | 72.96 (1 pass, -0.8 %) | 56.09 (-23.7 %) |
| UT2004 DM-Antalus_low | 87.30 | – | 68.93 (-21.0 %) |
| UT2004 ONS-Torlan_high | 65.72 | – | 50.39 (-23.3 %) |
| UT2004 ONS-Torlan_low | 68.64 | – | 54.96 (-19.9 %) |
| Doom 3 1024x768 high | 33.70 | 33.77 (+0.2 %) | 20.80 (-38.3 %) |
| Doom 3 1024x768 low | 34.20 | 34.00 (-0.6 %) | 21.00 (-38.6 %) |
| Doom 3 1920x1080 high | 31.03 | 31.30 (+0.9 %) | 20.50 (-33.9 %) |
| Doom 3 1920x1080 low | 31.77 | 31.53 (-0.7 %) | 20.63 (-35.0 %) |
| Halo timedemo "high" (800x600) | 93.69 (median of 3; 84.9/93.7/93.8) | 92.91 (-0.8 %) | 65.07 / 69.23 (n=2, -26..-31 %) |
| Halo timedemo "low" (640x480) | 124.36 | 123.36 (-0.8 %) | 98.58 (-20.7 %) |

**Conclusions.** (1) The renamed KERNEL driver is at parity with stock in every game (all within 1 %, Doom 3 report: 0 regressions). (2) The renamed USERSPACE GLDriver is functionally identical to stock on the GL feature suite but 20-39 % slower in all three games; this is a CPU-bound speed gap of the `-O0` machine-transcribed build, tracked in #209 (`-O1`: 63.3 fps in DM-Antalus_high, +13 %, still -14 % vs stock; `-O1`/`-O2` break parity on 7 tests, i.e. latent transcription bugs).

## Method notes and deviations from the plan
- UT2004: `Tools/gamefps/ut2004_run_side.sh` (seed 453418555, 60 s, 3 visits), report `Tools/game_fps_report.py` (14 REGRESSION verdicts for the both-renamed side). Doom 3: `Tools/gamefps/doom3_run_side.sh`, `r_useVertexBuffers 0`, 3 rounds, frame counts identical, `Tools/game_fps_report_d3.py`.
- **Halo could not be run at 1920x1080.** Halo (Mac 1.0.9) ignores the resolution patched into the profile/plist: requests for 1920x1080, 1600x1200, 1280x1024 and 1024x768 all ran at 800x600 (high preset) and 640x480 (low preset). The two presets are as defined in `Tools/gamefps/halo_run_side.sh` (high = shaders + max quality bytes, low = fixed function, everything off). Halo's FPS is the built-in 4700-frame timedemo average and includes the level-load stall in its first 4-11 frames.
- **First Halo stock baseline discarded:** taken at 2 days of uptime it averaged 68.1/83.2 fps with a 22 s load stall; on a fresh boot the same stock driver gives 93.7/124.4 with a ~4 s stall (cold first run 84.9). All Halo numbers above are fresh-boot, kextd-loaded on both sides. `renamed_high` run 2 did not produce a result file (n=2).
- Raw Halo timedemo outputs: `Tests/gamefps/halo_2026-11-02/` (`stock_high*`/`stock_low*` = the discarded 2-day-uptime baseline; `stockfresh_*` = the valid stock reference; `kext_*` = renamed kext + stock GLDriver; `renamed_*` = both renamed).
- NOT run: the T3 destructive checklist (27 reboots, hot-swap), non-hot-swap Phase R and the 4 h soak. The kext's behaviour was validated by difftest 907/907, baseline harness (normal+DEEP) IDENTICAL, the GL suite, and three games at parity.

## Final G5 state
Stock kext binary (md5 9c7a9fff…) and stock GLDriver (md5 5d63b5e3…) restored, `touch /System/Library/Extensions`, rebooted; stock loaded via kextd (0x72a37000, size 0x4f000); `compare_to_baseline.sh` IDENTICAL; `/Library/Logs/panic.log` unchanged (227356 B, Oct 21 23:22) through the whole session. Backups: `/Volumes/Test HD/rung3_backup_nov2` and `~/g5logs/final_eval/nov2_backup`.
