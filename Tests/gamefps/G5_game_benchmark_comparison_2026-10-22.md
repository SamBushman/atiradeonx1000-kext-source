# G5 game benchmarks: stock vs rebuilt ATIRadeonX1000

Generated 2026-10-22 00:21 on the dev machine from the G5 results.

## Summary
- **Regressions of the rebuilt driver against stock: 0** (criterion: a metric worse than stock by more than max(5 %, 3x stock run-to-run noise)).
- No metric regressed: UT2004 and Doom 3 results are within tolerance of stock everywhere (see the tables and the NOISY rows).
- Doom 3 frame counts are identical on every pass (2148 for demo1), and UT2004 uses a fixed RNG seed, so both drivers rendered the same workload.
- Driver restore and G5 shutdown status is recorded in the 'Final G5 state' section at the end of this file.

## Setup
- Mac Power Mac G5 (quad PPC970), Mac OS X 10.4.11 (Tiger), ATI Radeon X1900 (`GL_VERSION 1.5 ATI-1.4.19`), 16 GB.
- **Stock driver:** Apple `ATIRadeonX1000` 4.1.9, loaded from the prelinked kernelcache (0x541000), binary md5 `9c7a9fff5ee767ed5280e58d55df92cd`.
- **Rebuilt driver:** source tip `6842a99`, binary md5 `3c187f4d15785192ec050579c6e6d1be`, installed over the stock binary in `/System/Library/Extensions` and booted (prelinked after kextd regenerated the kernelcache, same load path as stock).
- Method: **one driver per boot, no hot-swapping.** Stock measured, rebuilt installed and the G5 rebooted, then the identical passes repeated.
- Settings are fixed in scripts (`Tools/gamefps/` in atiradeonx1000-kext-source) and identical for both sides: vsync off, sound off, fixed resolution, fixed RNG seed (UT2004).

## UT2004 (build 3369.2, built-in benchmark, DM-Antalus and ONS-Torlan, 60 s, seed 453418555, 8 bots, attract camera)
Presets: `high` = 1920x1080 with the existing ultra textures; `low` = 1024x768, lowest texture detail, no decals/coronas/projectors.

### Average FPS
| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |
|---|---|---|---|---|---|
| DM-Antalus_high | 73.54 (3) | 73.53 (3) | -0.0% | 5.0% | OK |
| DM-Antalus_low | 87.30 (3) | 87.12 (3) | -0.2% | 5.0% | OK |
| ONS-Torlan_high | 65.72 (3) | 65.54 (2) | -0.3% | 5.0% | OK |
| ONS-Torlan_low | 68.64 (3) | 68.56 (2) | -0.1% | 5.0% | OK |

### Minimum FPS
| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |
|---|---|---|---|---|---|
| DM-Antalus_high | 20.02 (3) | 19.48 (3) | -2.7% | 6.9% | OK |
| DM-Antalus_low | 24.90 (3) | 25.85 (3) | +3.8% | 7.7% | OK |
| ONS-Torlan_high | 7.61 (3) | 7.15 (2) | -6.0% | 67.2% | NOISY |
| ONS-Torlan_low | 9.44 (3) | 9.33 (2) | -1.1% | 5.0% | OK |

### 90th-percentile frame time (ms, lower is better)
| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |
|---|---|---|---|---|---|
| DM-Antalus_high | 15.17 (3) | 15.17 (3) | +0.0% | 5.0% | OK |
| DM-Antalus_low | 12.94 (3) | 12.98 (3) | -0.3% | 5.0% | OK |
| ONS-Torlan_high | 17.01 (3) | 17.08 (2) | -0.4% | 5.0% | OK |
| ONS-Torlan_low | 15.93 (3) | 15.96 (2) | -0.2% | 5.0% | OK |

### Maximum stall (ms, lower is better)
| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |
|---|---|---|---|---|---|
| DM-Antalus_high | 73.56 (3) | 71.46 (3) | +2.9% | 14.4% | OK |
| DM-Antalus_low | 65.95 (3) | 68.40 (3) | -3.7% | 5.0% | OK |
| ONS-Torlan_high | 136.59 (3) | 144.48 (2) | -5.8% | 77.2% | NOISY |
| ONS-Torlan_low | 105.99 (3) | 107.21 (2) | -1.1% | 5.0% | OK |

Notes: per-frame data come from the game's own `stats.csv`; the game's reported average and the CSV-derived average agree within 0.3 %. ONS-Torlan has 2 rebuilt rounds (the round-1 passes were killed by an unexplained SIGTERM); stock has 3.

## Doom 3 (dhewm3 built for PPC Tiger, retail data + 1.3.1 patch, `timeDemoQuit demo1`, fullscreen, 3 rounds)
Presets are explicit cvars: `high` = anisotropy 8, no downsizing/compression; `low` = anisotropy 1, textures downsized, compression on. `r_useVertexBuffers 0` for both sides (see notes).

### Average FPS (higher is better)
| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |
|---|---|---|---|---|---|
| 1024x768_high_demo1 | 33.70 (3) | 33.43 (3) | -0.8% | 5.0% | OK |
| 1024x768_low_demo1 | 34.20 (3) | 34.10 (3) | -0.3% | 5.0% | OK |
| 1920x1080_high_demo1 | 31.03 (3) | 31.00 (3) | -0.1% | 5.0% | OK |
| 1920x1080_low_demo1 | 31.77 (3) | 31.70 (3) | -0.2% | 5.0% | OK |

Notes:
- The run is largely CPU-bound on this machine: going from 1920x1080 to 1024x768, or high to low quality, changes FPS by only about 10 %, so the benchmark is a weak probe of GPU-side differences.
- The Doom 3 data and results were on Tiger HD (onboard disk) for these numbers. An earlier set of rebuilt/stock passes read the data from Test HD (the SonnetSATA disk); those are kept separately (`testhd_rebuilt_r*`, `stock_r*` in `doom3_run2`) and show the same parity.

### Raw per-pass results

| Run | FPS | frames |
|---|---|---|
| Doom 3 1024x768_high_demo1 stock #1 | 33.8 | 2148 |
| Doom 3 1024x768_high_demo1 stock #2 | 33.6 | 2148 |
| Doom 3 1024x768_high_demo1 stock #3 | 33.7 | 2148 |
| Doom 3 1024x768_high_demo1 rebuilt #1 | 33.6 | 2148 |
| Doom 3 1024x768_high_demo1 rebuilt #2 | 33.4 | 2148 |
| Doom 3 1024x768_high_demo1 rebuilt #3 | 33.3 | 2148 |
| Doom 3 1024x768_low_demo1 stock #1 | 34.3 | 2148 |
| Doom 3 1024x768_low_demo1 stock #2 | 34.2 | 2148 |
| Doom 3 1024x768_low_demo1 stock #3 | 34.1 | 2148 |
| Doom 3 1024x768_low_demo1 rebuilt #1 | 34.2 | 2148 |
| Doom 3 1024x768_low_demo1 rebuilt #2 | 34.1 | 2148 |
| Doom 3 1024x768_low_demo1 rebuilt #3 | 34.0 | 2148 |
| Doom 3 1920x1080_high_demo1 stock #1 | 30.8 | 2148 |
| Doom 3 1920x1080_high_demo1 stock #2 | 31.2 | 2148 |
| Doom 3 1920x1080_high_demo1 stock #3 | 31.1 | 2148 |
| Doom 3 1920x1080_high_demo1 rebuilt #1 | 31.1 | 2148 |
| Doom 3 1920x1080_high_demo1 rebuilt #2 | 31.0 | 2148 |
| Doom 3 1920x1080_high_demo1 rebuilt #3 | 30.9 | 2148 |
| Doom 3 1920x1080_low_demo1 stock #1 | 32.0 | 2148 |
| Doom 3 1920x1080_low_demo1 stock #2 | 31.6 | 2148 |
| Doom 3 1920x1080_low_demo1 stock #3 | 31.7 | 2148 |
| Doom 3 1920x1080_low_demo1 rebuilt #1 | 31.8 | 2148 |
| Doom 3 1920x1080_low_demo1 rebuilt #2 | 31.6 | 2148 |
| Doom 3 1920x1080_low_demo1 rebuilt #3 | 31.7 | 2148 |
| UT2004 DM-Antalus_high stock #1 | 73.88 (min 20.5, max 98.9) | 1801 |
| UT2004 DM-Antalus_high stock #2 | 73.31 (min 19.7, max 98.1) | 1801 |
| UT2004 DM-Antalus_high stock #3 | 73.42 (min 19.9, max 97.9) | 1801 |
| UT2004 DM-Antalus_high rebuilt #1 | 73.72 (min 20.3, max 98.8) | 1801 |
| UT2004 DM-Antalus_high rebuilt #2 | 73.53 (min 18.9, max 98.7) | 1801 |
| UT2004 DM-Antalus_high rebuilt #3 | 73.35 (min 19.3, max 98.4) | 1801 |
| UT2004 DM-Antalus_low stock #1 | 87.55 (min 24.9, max 116.4) | 1801 |
| UT2004 DM-Antalus_low stock #2 | 87.28 (min 25.5, max 116.8) | 1801 |
| UT2004 DM-Antalus_low stock #3 | 87.07 (min 24.3, max 116.3) | 1801 |
| UT2004 DM-Antalus_low rebuilt #1 | 87.39 (min 25.7, max 116.4) | 1801 |
| UT2004 DM-Antalus_low rebuilt #2 | 87.09 (min 26.4, max 116.0) | 1801 |
| UT2004 DM-Antalus_low rebuilt #3 | 86.88 (min 25.5, max 115.9) | 1801 |
| UT2004 ONS-Torlan_high stock #1 | 65.56 (min 5.6, max 79.5) | 1801 |
| UT2004 ONS-Torlan_high stock #2 | 65.76 (min 8.6, max 79.2) | 1801 |
| UT2004 ONS-Torlan_high stock #3 | 65.84 (min 8.6, max 79.2) | 1801 |
| UT2004 ONS-Torlan_high rebuilt #1 | 65.52 (min 5.9, max 79.4) | 1801 |
| UT2004 ONS-Torlan_high rebuilt #2 | 65.56 (min 8.4, max 78.9) | 1801 |
| UT2004 ONS-Torlan_low stock #1 | 68.74 (min 9.6, max 82.0) | 1801 |
| UT2004 ONS-Torlan_low stock #2 | 68.66 (min 9.4, max 81.9) | 1801 |
| UT2004 ONS-Torlan_low stock #3 | 68.52 (min 9.3, max 81.8) | 1801 |
| UT2004 ONS-Torlan_low rebuilt #1 | 68.66 (min 9.3, max 81.9) | 1801 |
| UT2004 ONS-Torlan_low rebuilt #2 | 68.45 (min 9.3, max 81.7) | 1801 |

## Things you should know
1. **Doom 3 hangs the stock driver with vertex buffer objects on.** With `r_useVertexBuffers 1` the first GUI `glBufferSubData` blocks forever in the ATI kernel call (`gldFinishObject`), WindowServer then blocks too, and only a reboot recovers it. This is on the **stock** driver, not a rebuilt-driver bug. All results use `r_useVertexBuffers 0`. Evidence: `~/g5logs/gamefps/doom3_hang1/`. Whether the rebuilt driver behaves the same with VBOs on was **not tested**.
2. **Two G5 crashes during the rebuilt runs were SonnetSATA kernel panics, not the ATI driver.** Both are a NULL dereference at the same place in SonnetSATA 2.2.4 (offset 0x15394, DAR 0), with identical kernel backtraces and no ATIRadeonX1000 frame. The SATA card holds Test HD (Marvell 88SX7042, WDC 750 GB); Tiger HD is on the onboard bay. The rebuilt kext has no dependency on SonnetSATA. 2.2.4 (2010) is the newest Power Mac Sonnet driver; 2.2.9b is Intel-only. Evidence: `~/g5logs/gamefps/crash1/`, `crash2/`.
3. The passive opcode recorder cannot be used as a frame counter for UT2004 (about 8 flushes per frame, and it halves FPS), so the game's own timing was used.
4. A like-for-like caveat from earlier work: boot-time stock is loaded from the prelinked kernelcache, and so is the rebuilt driver here (kernelcache md5 `36443c16...` contains the rebuilt binary).

## Driver state on each side
Stock boot:
```
(not recorded)
```
Rebuilt boot:
```
21:13  up 5 mins, 1 user, load averages: 0.49 0.38 0.18
   76    0 0x541000   0x4f000    0x4e000    com.apple.ATIRadeonX1000 (4.1.9) <75 74 16 11>
3c187f4d15785192ec050579c6e6d1be /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000
-rw-r--r--   1 root  admin  225354 Oct 21 21:08 /Library/Logs/panic.log
-rw-r--r--   1 root  admin  225354 Oct 21 21:08 /Library/Logs/panic.log
   76    0 0x541000   0x4f000    0x4e000    com.apple.ATIRadeonX1000 (4.1.9) <75 74 16 11>
```

## Final G5 state
```
done rebuilt: /home/sam/g5logs/gamefps/doom3_run3
   76    0 0x541000   0x4f000    0x4e000    com.apple.ATIRadeonX1000 (4.1.9) <75 74 16 11>
-rw-r--r--   1 root  admin  227356 Oct 21 23:22 /Library/Logs/panic.log
9c7a9fff5ee767ed5280e58d55df92cd /tmp/ATIRadeonX1000.stock
9c7a9fff5ee767ed5280e58d55df92cd /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000
23:47:42 restore files done; reboot 1
   73    0 0x71e1a000 0x4f000    0x4e000    com.apple.ATIRadeonX1000 (4.1.9) <72 71 16 11>
23:55:02 reboot 2
   77    0 0x541000   0x4f000    0x4e000    com.apple.ATIRadeonX1000 (4.1.9) <76 75 16 11>
9c7a9fff5ee767ed5280e58d55df92cd /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000
-rw-r--r--   1 root  admin  227356 Oct 21 23:22 /Library/Logs/panic.log
IDENTICAL to baseline (baseline/stock_4.1.9_g5_tiger.txt)
IDENTICAL to baseline (baseline/stock_4.1.9_g5_tiger_deep.txt)
done stock: /home/sam/g5logs/gamefps/doom3_run3
shutdown: [pid 2985]
Stopping Network Information Service
Stopping Apache web server
Stopping network time synchronization
00:21:22 shutdown issued
00:23:25 G5 no longer answers ping (shut down)
```
