# First load of the rebuilt kext - test plan (NOT EXECUTED)

Status: written 2026-09-19 for issues #59 (last open criterion: "the rebuilt kext matches the stock baseline") and #41-#45. **Nothing in this file has been run.**
Every live step needs the user's explicit go-ahead, one step at a time; a step is only proposed once the previous step's output has been reported.

Standing constraints (from the project's own history): no `/dev/kmem` scans, no fuzzing of `IOConnect*`, no install into a boot volume as a side effect of building,
check which OS the G5 is booted into first (Tiger = `/Volumes/Test HD` is the workspace; Sorbet HD is Leopard's own disk), `ld64` on PATH for big builds.

## What is being tested, and the one thing that makes this risky

`ATIRadeonX1000.kext` is the *accelerator* (`IOATIR500Accelerator` and friends); the framebuffer is a separate driver. The stock accelerator is loaded and in use while the
machine is up. Two kexts that both match the X1900 cannot drive it at once, so a meaningful run needs the stock accelerator unloaded (Quartz falls back to unaccelerated
drawing; this has not been observed on this machine, treat a blank screen as possible). Everything before Stage 3 avoids that.

## Stage 0 - offline checks (no kext is loaded; safe to run without asking twice)

1. `sh Tools/remote_build.sh` builds with a distinct identifier (`com.example.ATIRadeonX1000.linktest`, see `Tools/build_kext.sh`); output stays in `/tmp` on the G5 or under Test HD.
2. `sh Tools/link_check.sh` (done for the current tree: only the five KPI symbols listed in `build_kext.sh` are undefined).
3. `kextutil -t -n` (test, no load) on a copy in `/Volumes/Test HD/...`: prints undefined symbols, missing dependencies, and Info.plist problems without touching the kernel.
   Record the output in the issue. Expected: dependency resolution against `IOPCIFamily`, `IOGraphicsFamily`, `IONDRVSupport`, `IOAGPFamily` as the stock kext's `OSBundleLibraries` lists.
4. Verify the stock backup is intact before anything else: `cd /Volumes/Test\ HD/atiradeonx1000-kext-source/backups/stock-driver-2026-09-19 && md5 -r ... | diff - CHECKSUMS.md5.txt`.

## Stage 1 - rehearse the rollback on a harmless kext (needs authorization)

Per #41's own open item: exercise `kextunload` -> `kextload` -> `kextcache` rebuild on a kext whose absence cannot affect graphics (for example a scratch copy of a
small, unused Apple kext under a different identifier), and write down the exact commands and timings. Goal: the rollback commands have been typed once before they matter.

## Stage 2 - load the rebuilt kext without letting it match hardware (needs authorization)

1. Build a variant whose Info.plist personality cannot match the X1900 (wrong `IOPCIMatch`, or `IOProviderClass` of a class that never exists). The bundle id stays distinct.
2. `kextload` it from a non-boot location with root:wheel ownership and 0755/0644 modes. Expected: the module loads, static constructors run (metaclass registration for the 12
   classes), nothing starts (no `start()` because nothing matches).
3. Check `kextstat`, `ioclasscount` (the new classes appear with 0 instances), and `dmesg`/`system.log`. Then `kextunload` and confirm the classes disappear.
   This exercises: the rebuilt object/vtable layouts loading at all, `kmod_info`, the constructor/destructor lists, the KPI imports (`IOLockLock/IOLockUnlock`, `IOUserClient::init`,
   `IONDRVFramebuffer::metaClass`). It exercises none of the GPU code.
4. Report the outputs. Stop here unless told to continue.

## Stage 3 - replace the stock accelerator (needs explicit, separate authorization; physical access to the G5 required)

1. Have the recovery ladder from #41 ready before starting: `kextunload` -> remove the bundle + `kextcache -k` -> physical power-off (hold the power button; not a soft restart) ->
   Option-key boot picker -> Sorbet HD (Leopard has its own separate copy of the driver). Target Disk Mode remains the last fallback.
2. Take a fresh screenshot and `ioreg -l -w0` snapshot; note the stock accelerator's `kextstat` line.
3. `kextunload` the stock accelerator by its bundle id (fails harmlessly if something holds it). Confirm the desktop is still drawn.
4. `kextload` the rebuilt bundle with a personality that matches the X1900 (the stock Info.plist's, under the distinct id). Watch `system.log`.
5. Run the baseline harness against it: `Tests/compare_to_baseline.sh` (the stock's recorded call results are in `Tests/`); GL context creation, surface create/lock/swap, 2D and DVD
   contexts are the interesting external methods. Abort on the first panic-log entry, kernel `IOLog` warning that names our classes, or a frozen display.
6. Unload ours, reload the stock (`kextload` of the backup copy), and confirm `kextstat` and the display are back to the step-2 snapshot.

## Abort criteria and what each failure means

| observation | meaning | action |
|---|---|---|
| Stage 2 `kextload` refuses (undefined symbol, dependency) | link/KPI problem, no hardware involved | fix in `Sources/`, rebuild; nothing to roll back |
| Stage 2 loads but constructors panic | a static-initialiser or vtable problem | power-cycle, recovery ladder step 3 onward; keep `panic.log` |
| Stage 3 desktop blanks after unloading the stock kext | Quartz cannot run without the accelerator on this OS | physical restart; do not repeat without a different approach |
| Stage 3 panic or hang on `kextload` of ours | real driver defect in a mechanically re-ported method | power-off, Sorbet HD, `panic.log`; compare against the method's stock decompile |

## Not part of this plan

Installing into `/System/Library/Extensions` of Tiger HD or Sorbet HD; kernel-memory reads or scans; broad call fuzzing; running anything on the Leopard boot before Tiger's stages pass.
