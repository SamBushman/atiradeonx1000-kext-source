# DVD IDCT benchmark after hot-swap: never ready, on stock AND rebuilt (2026-10-13)

`Tests/perf_dvd_idct.c` (2000 calls, up to 12 MB): after kextunload/kextload + `unstick_hotswap_vram.sh`, `doIDCT` returned 0xe00002d8
for all 180 one-second readiness attempts on **stock** (3 runs) and on **rebuilt issue172c** (1 run) -> `RESULT: FAIL`, no METRIC lines.
The 2026-10-06 baseline (`../dvd_idct_20261006/`) was a FRESH BOOT of the stock kext (ready after 49 attempts). So the DVD engine
readiness is a boot-time property that a hot-swap does not reproduce; the benchmark cannot compare stock vs rebuilt in the hot-swap
state, and no discrepancy is attributable to the rebuilt driver (it behaves identically to stock here).
To get a real comparison the rebuilt kext must be the boot-time driver (install to /System/Library/Extensions + reboot = a boot-volume
install, which needs explicit user confirmation) and be measured against a fresh-boot stock run in the same boot state.
