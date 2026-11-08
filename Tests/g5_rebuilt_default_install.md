# The G5 runs the rebuilt X1900 stack by default (installed 2026-11-08)

From 2026-11-08 the G5's Tiger HD boots and runs OUR rebuilt kext and userspace images; nothing is injected and nothing depends on Test HD. This replaces the earlier arrangement
(stock installed, rebuilt loaded for a test by `gld_redirect.dylib` / hot-swap / the boot-time install of `Tests/boot_time_install_procedure.md`).

## What is installed (all on Tiger HD)
| system path | image | md5 |
|---|---|---|
| `/System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000` (stock `Info.plist` kept) | rebuilt kext, `kext_build_9904dde8` | `378d12e3617b9a9a2dcf0ad869eeff0a` |
| `.../ATIRadeonX1000GLDriver.bundle/Contents/MacOS/ATIRadeonX1000GLDriver` | rebuilt GLDriver, set `fad22b1d` | `5197c9cdcc904415b1d234f5a9d8bc36` |
| `.../ATIRadeonX1000GA.plugin/Contents/MacOS/ATIRadeonX1000GA` | rebuilt GA | `650f91d348127ae83e32b4a51b75f7a6` |
| `.../ATIRadeonX1000VADriver.bundle/Contents/MacOS/ATIRadeonX1000VADriver` | rebuilt VADriver | `87355720b2f7858aaca9fb70272c569c` |
| `/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib` | rebuilt libGL | `ed6ab34e417b0dfec756dd320e3bcb21` |
| `.../libGLProgrammability.dylib` | rebuilt libGLProgrammability | `c67e4d462c6a8e42943e6d5292a7e1aa` |

The kernelcache / mkext / kextcache were not replaced: the install touched `/System/Library/Extensions`, so the prelinked cache is out of date and kextd loads the installed kext (first boot: load address `0x71f36000`, size `0x4f000`).
Stock for comparison: kext `9c7a9fff5ee767ed5280e58d55df92cd`, GLDriver `5d63b5e3d86e770daa6aee657bc784c2`, GA `85ade3fd0bfa09e24e26bb12482dcf25`, VADriver `26e2e0281b7b9f77bf9d52911ec335b9`, libGL `ac62ab01d8fe244b25d3e35e9908f3c9`, libGLProgrammability `7f9f4e4e29e7ec66dac4748872863b4b`.
(The libraries' file dates of 2023 are what the stock install already had.)

## Files kept on Tiger HD: `/Library/ATIRadeonX1000-Rebuilt/`
- `rebuilt/` the six images above + `md5.txt`; `stock/` the six stock originals + stock `Extensions.mkext`, `Extensions.kextcache`, `kernelcache.86C01707` (as found 2026-11-08) + `md5.txt`.
- `swap.sh` (source: `Tools/g5_swap_stack.sh`): `sudo sh /Library/ATIRadeonX1000-Rebuilt/swap.sh stock|rebuilt`, then `sudo reboot`. Copies each file to a temp name, sets root:wheel and the mode, checks md5 against the directory's `md5.txt`, moves it over the target, touches `/System/Library/Extensions`. `sudo env DRY=1 sh swap.sh MODE` checks everything and replaces nothing (both modes were dry-run before the install).
- Copies of the same sources also live in `~/rung3` (Test HD) for the build/test work; the boot does not use them.

## How the install was done (discrete commands, one purpose each)
Staging dirs; stock backup + md5; rebuilt copy + md5; `swap.sh` written and dry-run in both modes; then per file `cp` to `NAME.new` in the target directory, `chown root:wheel`, `chmod`, md5, `mv`; `touch /System/Library/Extensions`; `reboot`.
The user asked for it ("Set up the G5 to boot and run with the rebuilt kext and userspace binaries ... by default from now on").

## Revert to stock (needed for any stock baseline or arm S/U measurement)
`sudo sh /Library/ATIRadeonX1000-Rebuilt/swap.sh stock`, `sudo reboot` (reboot twice if you want the stock kext loaded from the prelinked cache at `0x541000` again). Check: kext md5 `9c7a9fff...`, GLDriver md5 `5d63b5e3...`, `compare_to_baseline.sh` identical.
Arms U / K / KU of the runbook now need to start from the stock set (revert first) and then use `gld_redirect` / a kext swap as before; "rebuilt" is the default state.
If the GUI does not come up: ssh in (sshd does not depend on GL) and run the revert above. If ssh is gone: the Phase 9 recovery in `Tests/boot_time_install_procedure.md` (Option-key boot into Sorbet HD, mount Tiger HD, copy the files from `/Library/ATIRadeonX1000-Rebuilt/stock/` back) applies.

## Verification after the first reboot (10:03)
- `kextstat`: `com.apple.ATIRadeonX1000 (4.1.9)` `0x71f36000` size `0x4f000`; installed kext md5 `378d12e3...`; `panic.log` unchanged (229725 bytes); WindowServer, Dock and Finder running; no `DYLD_*` / `GLD_*` environment in launchd.
- `lsof` on WindowServer shows the rebuilt images mapped by size: GLDriver 2716736 bytes (stock 4361232), GA 127768 (stock 138776), libGLProgrammability 1074188 (stock 979416).
- Desktop screenshot normal (Quartz Extreme compositing running on the rebuilt GLDriver).
- `gld_ctxlist_test` PASS 20/20, `perf_dvd_idct 2000 12` PASS (medians 4.44 / 5.07 / 12.06 us, stock 4.33 / 5.05 / 12.03).
