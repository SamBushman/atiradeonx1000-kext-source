# DVD IDCT throughput, rebuilt vs stock, both as the BOOT-TIME driver (2026-10-15, #45)

`Tests/perf_dvd_idct.c` (2000 calls/metric, up to 12 MB), 3 runs each, fresh boot each side, `Tools/perf_compare.py`.
* stock: fresh boot 09:11, shipped binary md5 `9c7a9fff5ee767ed5280e58d55df92cd` (also verified against `backups/stock-driver-2026-10-06`).
* rebuilt: the `kext_build_fix` binary (commit `95edbd2`, md5 `2de86c496d062dd618e715e34c29bb74`, the same binary used for every hot-swap run since 2026-10-14 11:09; file mtime 2026-10-14 12:05) copied over `/System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000` (stock Info.plist kept), reboot 09:21. `Extensions.mkext` was rebuilt with `kextcache -a ppc -l -m`; the result is byte-identical to the original (md5 492e7401...), i.e. the accelerator is not in the boot mkext and kextd loads it from the Extensions folder. Boot-time load address 0x588000, no panic (`panic.log` unchanged, 218602 bytes).
* stock restored afterwards (md5 9c7a9fff verified, rebooted 09:28; `kextstat` 0x588000, panic.log unchanged).

| metric | stock p10-based median (us) | rebuilt | ratio | verdict |
|---|---:|---:|---:|---|
| dvd.doIDCT.intra.1mb | 4.23 | 4.29 | 1.014 | OK |
| dvd.doIDCT.intra.4mb | 4.29 | 4.38 | 1.021 | OK |
| dvd.doIDCT.intra.12mb | 11.94 | 11.94 | 1.000 | OK |

Raw medians: 12mb 12.03 us (stock) vs 12.06 us (rebuilt). Readiness waits (not part of the metric): stock 40/49/48 attempts, rebuilt 28/48/48. Both match the 2026-10-06 stock baseline (12.03 us).
Caveat: that the kernel actually loaded the rebuilt binary is supported by the on-disk md5 and the accelerator's absence from the mkext; I did not read the loaded image back (kextstat shows the same size and 0x588000 for both).
Only intra/residual stream-0 reconstruction is measured (the P/B composite is excluded by #44's scope decision).
