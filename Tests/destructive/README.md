# Destructive / interruptible external-method tests - the protocol (issue #87)

Ten external methods (#88-#97) and the T3 rows of #100 can hang or panic the machine, write GPU registers, change global accelerator or display
state, or corrupt a display. Each is ONE binary built from `<name>.c` + `dtest.c`, run **one per boot session**, never linked into the parity
suite (`../Makefile` does not know this directory), and always through `dtest_main()` (`dtest.h`), which enforces the gates below.

## Running a test (on the G5, Tiger, from this directory)

1. `make destructive-<name>`
2. On the **dev machine** (a second machine): `sh peer_ack.sh G5 <dir-on-G5>` - checks the dev git tree is clean and pushed, touches
   `results/peer_ack` over ssh (proof that a second ssh session answers) and tells you to run `nc -ul 9999` in a second terminal.
3. On the G5: `sh preflight.sh <name>` - captures kextstat, `ioreg -l -w0`, displays, vm_stat, the system.log tail, (register snapshot if
   `./regsnap` exists), a screenshot, and `diskutil verifyVolume` of `/` and `/Volumes/Test HD`; checks the ATI kext is loaded, no GL or DVD
   client exists, and the peer acknowledged. Any failure aborts. On success it writes `results/preflight.ok`.
4. `./<name> --phase <A|B|..> [--kext stock|rebuilt] [--mirror DEVHOST:9999] --i-understand-this-may-hang-the-machine`
5. `sh postflight.sh <name>` - repeats the capture into `post.*`, diffs it (kextstat must be identical, volumes clean), prints the other diffs.
6. Put the outcome class, the log and the diffs into the issue.

`dtest_main()` refuses (exit 2-7) without `--phase` and `--i-understand-this-may-hang-the-machine`, while `results/<name>.state` says
`IN PROGRESS` (an interrupted run), without a preflight and a peer acknowledgement newer than 15 minutes, while a GL or DVD context exists
(unless the test declares it needs one), or when the accelerator service is missing.

## Write-ahead log
`dtest_about()` appends `ABOUT TO CALL <selector> args=...` to `results/<name>_<kext>_<UTC>.log` and `fsync()`s **before** the call;
`dtest_result()` appends the outcome after. The same line goes to stdout (`ssh G5 ./x | tee` on a second terminal) and, with `--mirror`, to a UDP
listener on the second machine. A hang or panic therefore always leaves the exact last call on disk and on the other machine's screen.

## Outcome classes (recorded in `results/<name>.state` and the issue)
`PASS` (return code and every measurement in the issue matched), `EXPECTED-REJECT` (rejected with the code the body predicts), `DIVERGENCE`
(rebuilt differs from stock), `HANG` (needs reset), `PANIC`, `CORRUPTION` (verifyVolume or display damage). A HANG/PANIC on STOCK is a finding
about the stock driver and becomes its own issue (see #98, #99); on the rebuilt kext it is a defect. `HANG`/`PANIC`/`CORRUPTION` cannot be
written by the dying process - the state file is simply left `IN PROGRESS`; whoever resets the machine records the class.

## Reset procedure (referenced by every per-method issue)
1. soft: `ssh G5 'sudo shutdown -r now'`;
2. if ssh is dead but the display responds: hold the power button 5 s, then power on;
3. if the machine is unresponsive: physical power-off.
After ANY reset: `diskutil verifyVolume` on every mounted volume (`capture.sh` does it), `kextstat | grep -i ati` shows the stock kext (or the
rebuilt one for Phase R), `sh ../compare_to_baseline.sh` of the normal suite matches the baseline (the machine is back to the known state), then
run the test with `--acknowledge-interrupted` once (it renames the state file), and note the interruption in the issue. A hard power-off once
corrupted files on the Tiger working volume (godot-ports #9): never skip the volume check.

## Order and isolation
One test per boot session. Reboot between tests whose issue says "reboot after" (all that change global or hardware state). Never two destructive
tests in one session. Never while a GL / 2D / DVD client other than WindowServer is running unless the issue says the test needs one.
Never broad-scan kernel memory and never broad-fuzz call shapes (each crashed the G5 before; `feedback` in the issues #43/#87): the setup of every
test is built from calls already proven live on the stock kext, and every parameter that is not proven (a register offset, an IDCT stream, a
mode-bit combination) must be derived from evidence first (Step 0 of the issue), never chosen.

## Two phases
**Phase S**: the STOCK kext (what is installed) - the reference behaviour and measurements; may be run today. **Phase R**: the rebuilt kext - only
inside Stage 3 of `../first_load_plan.md` with the user's per-stage authorisation, and only after #85 and #86 (both resolved 2026-10-01). A test is
"exercised" when Phase S has a recorded PASS/EXPECTED-REJECT and Phase R matches it (or its divergence is a tracked defect).

## Measurement toolkit
`ioreg -l -w0` diff; `kextstat`; `vm_stat`; `/var/log/system.log`; `screencapture`; DVD/2D `read_regs` (sel 13/16) for register snapshots; DVD
`check_stamps` (sel 20) / `wait_for_stamps` (19) and GL `wait_for_stamp` for GPU timestamp progress; Surface `get_state` (2), `surface_query_lock`
(11), `surface_read_lock_options` (0) for surface state; and, only where an issue explicitly names one fixed address, a **single**
`../../Tools/read_mem.py` read (never a scan).

## Files
`dtest.h/.c` (the protocol library) - `capture.sh` (shared capture) - `preflight.sh` / `postflight.sh` - `peer_ack.sh` (second machine) -
`selftest_get_state.c` (validates the framework itself with the one call already proven safe; not a destructive test) - `Makefile`.
