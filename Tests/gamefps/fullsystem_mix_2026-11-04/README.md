# Full system with the default GLDriver image ("mix") - 2026-11-04

Config: renamed kext `43d82745` (installed per `Tests/boot_time_install_procedure.md`; after the 2nd reboot it loads from the regenerated prelinked cache @0x541000, cache md5 507b5402…) + userspace GLDriver `d988e2c5…` = the default `build_gld_image.sh` image (shader-compiler parts `-Os`, rest `-O2 -mtune=970`; commit 2915f27a; see `../gldriver_212_2026-11-04/`). "Stock" side of every interleaved comparison = stock GLDriver `5d63b5e3…` swapped onto the SAME renamed kext. Tolerance max(5 %, 3x stock noise).

| test | result |
|---|---|
| install state | kext md5 43d82745…, GLDriver d988e2c5…, panic.log 227356 B unchanged |
| `compare_to_baseline.sh` normal | IDENTICAL (`perf/parity_full.txt`) |
| `compare_to_baseline.sh --deep` | one-line diff, **not a driver difference** - see "check_stamps" below |
| installed GL feature suite | 83 outputs, 0 DIFF / 0 EMPTY vs stock outputs; the same 3 non-zero exits as stock (accum, runtime_quirks, tex3d_cubemap) - `gls_fullmix.cmp` |
| fresh-boot `perf_collect` vs 3 stock fresh boots (`../gldriver_212_2026-11-04/pc3,pc4`) | 0 regressions of 24; Clear+Flush 197 us vs stock 189/195/192 (+1.0..+4.2 %), Draw100Tri 117 vs 118-120 us (-1..-2.5 %) - `perf/` |
| `perf_dvd_idct 2000 12` x3 | 4.26-4.41 / 5.01-5.04 / 12.03 us (stock 4.33 / 5.05 / 12.03) |
| `pcd` (draw paths) x3 interleaved | arrays/elements/immediate within +-1.3 % of stock; state-change paths slower, see #213 and `pcd/`, `pcd_var/` |
| `pcd4` 1024 textures (#211 crash repro) x6 | rc=0 all runs; texSub RGBA 1024 5.37 ms vs stock 6.53 ms |
| UT2004, 4 interleaved visits x 4 map/presets | 0 regressions; avg -0.8..-0.9 % (`ut/report.txt`) |
| Doom 3 timedemo, 3 rounds | 0 regressions; -1.1 %..+0.9 % (`d3/report.txt`) |
| Halo, 3 rounds | 800x600 high -0.8 %, 640x480 low -0.8 % (`halo.log`) |
| 4 h soak (`Tests/soak.sh 14400`, MASK_INSTANCE_COUNTS=1) | SOAK DONE rounds=1049 elapsed=14411 s transients_recovered=0; watchdog (`soak/watch.tsv`, 239 samples) all ok, kext stayed @0x541000, no crashdump, panic.log unchanged - `soak/` |
| restore to stock | 5 discrete restores from `Test HD/rung3_backup_nov2` (md5 verified), touch, 2 reboots: prelinked stock @0x541000, kext 9c7a9fff…, GLDriver 5d63b5e3…, kernelcache 664968f6…, normal + DEEP IDENTICAL on an idle boot, panic.log 227356 B |

## check_stamps(5,5) in `--deep`
On the full system `--deep` differed from the recorded baseline in one line: `DVD check_stamps(5,5) ... both=1` vs recorded `both=0` (the test accepts 0 or 1). Cause confirmed on STOCK (`stock_check/`): idle stock boot -> IDENTICAL; after a `perf_baseline` GL run -> IDENTICAL; after `perf_dvd_idct 2000 12` -> the same one-line diff (`both=1`). It depends on the GPU stamp counter after DVD work, so it is boot/workload state, not the rebuilt kext or GLDriver. (Nov 3: DEEP right after install, before any DVD work, was IDENTICAL.)

## Open finding
State-change draw paths cost more CPU per call than stock (arb env +7.4 %, matrix change +5.6 %, lighting +5.5 %, tex rebind +1.2 %; absolute 0.03-0.28 us): issue #213. No game metric is affected.

## Notes
- Long `pcd` runs (`PCD_MUL=400`, one stock/rebuilt pair) are in `pcd_n400/`; the interleaved 3-round set used `PCD_REPS=7 PCD_MUL=100`.
- Chain log: `chain_driver.log`.
