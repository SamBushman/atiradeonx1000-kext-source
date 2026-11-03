# Full system (renamed kext 43d82745 kextd-loaded @0x714b4000 + userspace GLDriver fe83266b dff47f98…) — 2026-11-03

Installed per Tests/boot_time_install_procedure.md (binary swap in the stock bundles, `touch /System/Library/Extensions`, reboot). Comparison side = stock GLDriver
(5d63b5e3…) swapped onto the SAME renamed kext, interleaved per pass; UT numbers are also checked against the earlier stock-kext + stock-GLDriver run
(final_fe83266b). Tolerance max(5 %, 3× stock noise).

- compare_to_baseline.sh normal + DEEP: IDENTICAL; panic.log unchanged (227356 B).
- GL feature suite (installed): 83 outputs, 0 DIFF / 0 EMPTY vs stock outputs (gls_full.cmp empty after the count line).
- UT2004, 4 interleaved visits x 4 map/presets: 0 / 16 beyond tolerance (avg -0.6…-1.2 %, min -1.3…+7.1 %) vs stock GLDriver on the same kext; 0 / 16 vs the stock system.
- Doom 3 timedemo, 3 rounds: 1024x768 high -1.0 %, low -0.8 %; 1920x1080 high +0.6 %, low -0.8 %; 0 regressions (d3.driver.log).
- Halo, 3 rounds: 800x600 high -0.7 %, 640x480 low -0.7 % (halo.log).
- Fresh-boot (renamed kext in the regenerated prelinked cache @0x541000): perf_collect vs the Oct stock baseline 0 regressions (5 improved, 19 OK); perf_dvd_idct 4.26-4.35 / 5.01-5.07 / 12.03-12.06 us (stock 4.33 / 5.05 / 12.03). Note: glcycle microbenchmarks drift up to ±40 % with uptime/boot state (Draw100Tri 127 us on a fresh boot, 234 us after an hour of games with the same code) - compare fresh-boot to fresh-boot or interleave.
- 4 h soak (Tests/soak.sh 14400, MASK_INSTANCE_COUNTS=1) on the full system: SOAK DONE rounds=1052 elapsed=14406s transients_recovered=0, no STEP-DIFF; watchdog (soak/watch.tsv) OK throughout, panic.log unchanged (227356 B).
