# Full system (renamed kext 43d82745 kextd-loaded @0x714b4000 + userspace GLDriver fe83266b dff47f98…) — 2026-11-03

Installed per Tests/boot_time_install_procedure.md (binary swap in the stock bundles, `touch /System/Library/Extensions`, reboot). Comparison side = stock GLDriver
(5d63b5e3…) swapped onto the SAME renamed kext, interleaved per pass; UT numbers are also checked against the earlier stock-kext + stock-GLDriver run
(final_fe83266b). Tolerance max(5 %, 3× stock noise).

- compare_to_baseline.sh normal + DEEP: IDENTICAL; panic.log unchanged (227356 B).
- GL feature suite (installed): 83 outputs, 0 DIFF / 0 EMPTY vs stock outputs (gls_full.cmp empty after the count line).
- UT2004, 4 interleaved visits x 4 map/presets: 0 / 16 beyond tolerance (avg -0.6…-1.2 %, min -1.3…+7.1 %) vs stock GLDriver on the same kext; 0 / 16 vs the stock system.
- Doom 3 timedemo, 3 rounds: 1024x768 high -1.0 %, low -0.8 %; 1920x1080 high +0.6 %, low -0.8 %; 0 regressions (d3.driver.log).
- Halo, 3 rounds: 800x600 high -0.7 %, 640x480 low -0.7 % (halo.log).
