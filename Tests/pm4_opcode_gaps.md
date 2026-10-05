# GL opcodes never observed on the stock kext (issue #42 criterion 2) - what is known about each

Context: `Tests/pm4_opcode_usage.md` (generated) lists what 40+ workload runs made the stock GL driver emit: **57 of the 66 inventory opcodes (86 %)**, 0 anomalies. This file explains the 9 never seen, and records
how the earlier undercount was found. "Emitter" = a function of the stock `ATIRadeonX1000GLDriver` that stores the opcode's header constant `0xNN000000` (found in the Ghidra C reconstruction `Userspace/ATIRadeonX1000GLDriver/ppc/`).

## Recorder correction (2026-10-03)

The driver back-patches each record's length when the NEXT record is appended (`*prev |= (new - prev) >> 2`), so **the last record of every buffer keeps a length field of 0**. The first recorder treated length 0 as the terminator and never
counted that final record, so every flush lost one record. Counting it adds 0x01 (plain end of buffer, not in the disassembly inventory), **0x02** (once per frame in windows: the end-of-frame/present record) and **0x03** (end of an offscreen
flush) to the observed set. All earlier numbers (27 -> 51 of 66) were undercounts; the figures here are from the corrected recorder.

## Opcodes found since the first gap analysis, and what triggers them

| opcode | trigger found (from the stock driver's code and gdb backtraces of the driver functions) |
|---|---|
| 0x2d | `glCopyPixels(GL_COLOR)` with **non-overlapping** source and destination rectangles and default pixel-transfer state (`FUN_00018120` mode 2) |
| 0x31 | `glCopyPixels(GL_DEPTH)` with a suitable depth/colour/stencil state mix (found by trying all 256 combinations of depth test, depth func ALWAYS/LESS, depth mask, colour mask, stencil, blend, scissor, texture: 16 of 256 qualified; `FUN_00018120` mode 3) |
| 0x35 | consistent-size framebuffer-object rendering with depth textures / float colour targets (feature `fbo2`; the earlier `fbo` feature's float and depth-texture framebuffers were INCOMPLETE_DIMENSIONS and rendered nothing) |
| 0x45 | a depth **texture** (`GL_DEPTH_COMPONENT`, format 0x1902 in the driver) used as an FBO attachment / uploaded: `FUN_0002ce40` and `FUN_00031340` test exactly that |
| 0x02, 0x03 | final records (see the correction above) |

## The 9 never observed

Four have an emitter whose branch is **statically unreachable** (each proven by reading the whole driver, and consistent with the runtime traces):

| opcode | emitter | why it cannot run |
|---|---|---|
| 0x2a | `FUN_00020b30`, only called from `FUN_00018120` when its mode is 1 | the mode is only ever assigned 0, 2 or 3 (every assignment listed in the function), so the mode-1 branch is dead |
| 0x36 | `FUN_00027150`, installed in dispatch slot 0x15 only when the context byte at offset `0x2b82` is non-zero | the only store to that byte writes 0 (`FUN_0002c790`); the function never ran in any trace |
| 0x38 | the `0x38` branch of `FUN_00026bf0` (ran > 1000 times), taken only when `ctx+0x27d8 & 6` is non-zero | the only store to that word is `(1 or 2) \| (old & 0x18)`, and bits 0x8/0x10 are never set anywhere, so the value is always 1 |
| 0x3d | `FUN_00017310` writes `0x3d000000` only for selector `0x132` | its only caller is `_gldSetInteger`, which handles selector 0x132 itself (it issues an external method call) and never forwards it; `CGLSetParameter(306)` was exercised and traced to confirm |

Five have **no code that stores their header** (no literal store, no `lis/oris/addis` of the high half, and the only run-time-computed headers in the whole driver are the texture-slot families `0x06+n` and `0x16+n`):

| opcode | kernel meaning |
|---|---|
| 0x27 | handler at dispatcher line 1015, not characterised |
| 0x2b | explicit mid-stream flush: calls `submit_buffer` |
| 0x2c | clip/bounds pairwise MAX that depends on whether an FBO render target is active |
| 0x43 | not characterised |
| 0x46 | "fast clear" (Headers/ATIR500GLContext.h:349) |

Caveat for these five: the driver's `__data` holds an opcode-indexed table (0x24-byte entries, headers `0x00000000`..`0x2f000000`, base `0x1d9f34`) that contains their header words; I could not find the code that reads it, so
emission from that table cannot be excluded. They were not produced by any of the ~40 workload runs, including exact 0/1 clears on windows (which stalled the driver, see hazards).

## What was run (all logs in `Tests/baseline/opcode/`)

Per-feature pbuffer programs (multiple texture units, texture formats/targets, FBO, consistent-size FBO with depth textures and float targets, queries/fences, clears, fixed-function state, draw methods, shaders and ARB programs, pixel
operations, copy-pixels, CGL context parameters, VBOs, big draws), the windowed program with 0/2/4/6-sample multisample, depth/stencil variants and clear/hz/resolve modes, five small probes, and the Godot game and editor.

## Hazards found while doing this (stock driver, G5, 2026-10-03)

* A seeded random fixed-function state stress (`Tests/userspace/glstress.h`) made the GL stack call `exit(0)` from inside `glClear` (seed 1, ARB vertex programs enabled with other random state, and a second combination at 200
  iterations), produced multi-minute runs, and left killed processes in the exiting state for 40 s to 3 min.
* After that and a window "fastclear" mode that never finished its frames, **new GL clients hung at start-up** (even the safe `cgl_probe`) until the G5 was rebooted. Those modes are marked as hazards in the sources and are not part of any default run.
* A Godot process killed by SIGTERM during GL activity was once held by a stuck `crashdump` (100 % CPU, minutes); `sudo killall crashdump` released it.

## Method (for repeating or extending this)

`Tools/userspace/gdb_emitter_trace.py` builds a gdb-696 script that sets raw-address breakpoints on stock GLDriver functions (runtime address = 0x1008000 + the function's address) and prints a backtrace on each hit, so the GL call behind a driver
function can be read off the stack (`glClear_Exec`, `glBegin_Exec`, `glDrawPixels_Exec`, ...); `Tools/userspace/gdb_trace_runner.sh` runs the generated scripts on the G5.

## Injection results (2026-10-03): 8 of the 9 unseen opcodes now exercised on the stock kernel

No real workload emits these, so `Tools/userspace/opcode_recorder.c` gained an injection mode (`OPCODE_INJECT_WORDS`, `OPCODE_INJECT_FLUSH`; runner `Tools/userspace/run_inject.sh`): hand-built, well-formed records are spliced
at the start of the stream of one flush of a stock `glcov clear` client, the real stream shifted up behind them, so context/surface/register state is the real one. `INJECT-POST` logs the injected words after the kernel processed
the buffer. Records whose output would be a PM4 packet (0x2c, 0x2a, 0x46, 0x38, 0x3d) are followed by a **discard guard**: a 0x43 record with an out-of-range texture id, whose handler zeroes the pending word count and ends the loop,
so the kernel runs the handler (rewriting the record in place) but submits 0 words to the GPU. Logs: `Tests/baseline/opcode/inject/`. Every run: flush returned 0, process exit 0, no crashdump, panic.log unchanged.

| opcode | injected | kernel's rewrite (observed) | matches handler |
|---|---|---|---|
| 0x2b | `2b000001` | `80000000` (nothing pending, so no submit) | yes |
| 0x27 | `27000001` | `80000000` (context+0x328 is zero, so no-op) | yes |
| 0x43 | `43000004 0 ffff 0` (invalid texture id) | `c0021000` (PM4 NOP), loop ends with 0 words | yes |
| 0x3d | `3d000002 1` (selector != 0x132) | `80000000 80000000` | yes |
| 0x38 | `38000004 0 0 0` (count 0) | `80000000` x4 | yes |
| 0x2c | `2c000003 00010001 00ff00ff` | word 0 -> `c8002020`, bounds words unchanged | yes (a type-3 packet header: this is why it is discard-guarded) |
| 0x46 | `46000010 8 ...` | `000013c8` (register write), `00888000`, `00d00200`, `001fe1ff`, ... | yes |
| 0x2a | `2a000020 1 ...` | `c8002020 c8002020 02000200 ...` | yes |
| 0x36 | tried live, CRASHED (issue #125 / V13) | | word 1 IS a value the kernel issued (`get_data_buffer`, selector 18) rather than something the client forges - but kernel-issued does not mean validated: the handler writes through word[1] unconditionally with no null/type check, and the value is likely a bus/physical address (vtable+0xd0 on the descriptor `get_data_buffer` allocates), not a dereferencable virtual pointer. Injecting a real-looking handle caused a DEFERRED panic one flush later (`remove_texture_from_stream`), not an immediate one. Earlier framing here ("not a unique risk, safe like 0x44") was wrong or at least unproven - see issue #125. NOT exercised; do not retry without resolving #125 first. |

Still unexercised after this: 0x36 (above), the valid-texture branch of 0x43 (needs a real kernel texture id), the 0x132 selector of 0x3d (`set_volatile_state`), and every 2D / DVD dispatcher opcode.

## 2D injection attempt (2026-10-03): HUNG the G5 - lesson

`Tests/destructive/t3_2d_inject.c` opened a 2D client, wrote one record + a discard guard into the buffer from `IOConnectMapMemory(2D, memType 1)` and flushed with memType 0. The first record (0x05) read back **unchanged**
(`05000000 07000002 0000dead`): the kernel had not rewritten it, so that buffer is not the one the dispatcher processed and the guard never ran. The second injection (0x06000008 + zeros) therefore reached the GPU raw and the
G5 stopped answering ssh and ping (last mirrored line: `ABOUT TO CALL inject 0x06 (8 nops) then flush`). The GL injection above is not affected: there the spliced words are inside the stream of a flush the driver itself is submitting,
and `INJECT-POST` proves the kernel rewrote them. For 2D/DVD the same method needs a real 2D/DVD client to splice into (console-launched QuickTime/DVD Player under the recorder) - not a hand-made client.


## Static resolution of 0x36 (2026-10-03)

Earlier framing ("client-controlled kernel pointer, not exercised") was too strong. Static trace: the stock GLDriver's only emitter of 0x36, `FUN_00027150` (@0x27150), writes `puVar6[1] = *(ctx+0x200)` as the record's word 1. The only writer of `ctx+0x200` is `IOATIR500GLContext::get_data_buffer` (`Sources/IOATIR500GLContext_get_data_buffer_Port.cpp`, external method selector 18 - `0 in / 2 out`, `IOATIR500GLContext::start`'s `methodDescs[18]`): a real kernel-dispatched call that allocates a `VendorTransferBuffer`, pins it, and returns the kernel's own handle for it (`VCALL(*piVar4, 0xd0)(piVar4)`, a vtable call on the just-created `IOMemoryDescriptor`-derived object). The client cannot forge this value; it can only replay what the kernel handed it. This is the same trust pattern 0x44 already uses and that 0x44 has already been proven safe for live (0x44 is among the 57/66 observed opcodes).

## Emulator: `Tools/userspace/emu/kemu.py` (2026-10-03)

Runs the STOCK KEXT's real PPC machine code (not the ported C++) of a `process_command_buffer` dispatcher in Unicorn, against a hand-built "self" context and command buffer, with zero risk to real hardware. Works because the kext's raw `.bin` (an unlinked MH_OBJECT) has its single TEXT+DATA segment at `vmaddr 0`, matching the Ghidra decompile's own "real addr" values exactly (confirmed: `ATIR5002DContext::process_command_buffer` symbol value `0x326d0`) - loading the image at address 0 with no slide makes every PC-relative branch AND every already-baked long-branch trampoline for an INTRA-kext call resolve correctly with no Mach-O relocation pass needed. A genuinely external call's trampoline (checked: `_IOGetTime`, confirmed undefined/external in the symbol table) is left unrelocated (`lis 0; ori 0`) by the static linker, landing at address 0 - which the harness treats as "stub: return 0 to LR" (same convention `emu.py` already uses for dyld stubs). Needs `MSR_FP` set (several dispatchers save/restore FPRs in their prologue; Unicorn traps on the first `stfd` otherwise).

**Caveat found the hard way:** Unicorn's `UC_HOOK_MEM_UNMAPPED` silently auto-maps a zero page for any unmapped read (including near address 0), so a null-pointer dereference that would **panic real hardware** instead reads 0 and continues. The emulator is trustworthy for safe, bounded control-flow/record-rewrite questions (confirmed matching live INJECT-POST behaviour and the ported C source throughout this session) but is NOT a substitute for checking real crash/panic conditions - see V12 in `Tests/known_vendor_deviations.md`, found live, that the emulator would have masked.

**Results:** every 2D opcode the live `t3_2d_inject` test queued (0x02,0x03,0x04,0x05,0x06,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x10,0x11,0x12,0x13), run individually with a correctly-padded record (matching its own declared length), rewrote its words exactly as `Sources/ATIR5002DContext_process_command_buffer_Port.cpp` predicts, with no wild pointer excursion and no emulator error - safe, bounded, and consistent with the static source. Chaining several in one buffer confirmed the loop-termination rule from the source directly: any image opcode (0x03/0x04/0x08/0x13/0x10) with an invalid id returns FROM THE WHOLE CALL immediately (word count forced to 0), so no record after it in the same buffer is ever reached - each needs its own flush, matching the live test's original per-record-flush design (that part was never the bug).


## 0x36: two live attempts, both crashed the G5 (2026-10-03)

The static trust argument above ("0x36's word 1 comes from a kernel-dispatched external method, not client-forged") is true but was not sufficient: it does not mean the KERNEL validates that value when it is replayed back through the command stream, and it does not mean an isolated two-call sequence (bind -> get_data_buffer -> inject) reproduces whatever state the real driver's own call sequence maintains around it. Two live attempts:

1. Emulator (`kemu.py`) with a fake pointer: reached the real handler, then spun forever in `IOATIR500Surface::freeToAllocGART` / `IOATIR500Accelerator::freeTransferToAllocGART` - a real GART-pool-management call the fake all-zero accelerator state can never satisfy. Correctly flagged as "emulator cannot give a trustworthy answer here" rather than treated as a clean pass.
2. Live, with a REAL handle from `get_data_buffer` (`0xa000`): the flush that processed the 0x36 record returned successfully, but the **next** flush on the same connection panicked inside `remove_texture_from_stream`, a function unrelated to 0x36 on its face - a deferred-corruption signature, not an immediate fault. Full analysis: issue #125, `Tests/known_vendor_deviations.md` V13.

0x36 is the one GL opcode of the original 9 that remains genuinely unexercised and unresolved. Final GL tally stands at **57/66 observed**, 8 of the remaining 9 safely exercised by injection, 0x36 explicitly NOT safe to retry without further static work (issue #125).


## 0x36: RESOLVED - confirmed dead code, no further live attempt needed or warranted

Re-verifying the original static-unreachability finding (the "4 statically unreachable" emitters found before any injection work): the gating byte at context offset `0x2b82` has exactly two references in the whole GLDriver image - one read (installs `FUN_00027150`, 0x36's only emitter, into dispatch slot 0x15 only when the byte is non-zero) and one write (unconditionally sets it to 0). **0x36 never runs in the real driver.** Its kernel-side handler is the one member of the unreachable group whose code unconditionally dereferences and writes through word[1] as a real pointer with no validation (unlike 0x2a/0x38/0x3d, which only touch PM4-local header words and were proven safe to inject with dummy data). The earlier comparison to 0x44 (same dereference pattern, proven safe via real usage) does not transfer: 0x44 is exercised by real apps under a real precondition (a bound texture); 0x36 is exercised by nothing, ever.

This settles 0x36's status without a third live attempt: it is **confirmed dead code with an unvalidated handler** - a real, if currently unreachable, defect in the stock driver (documented as V13/#125), not a gap in this project's testing. Final tally stands: **57/66 GL opcodes observed**, 8 of the remaining 9 safely exercised by injection, 0x36 statically explained and deliberately left untried a third time.


## DVD #126 follow-up (2026-10-03, later): the 53-opcode list genuinely works - reproduction depends on system freshness, not the opcode sequence

Per the user's standing instruction (crashes are an acceptable, expected cost of understanding the driver, not something to avoid - see project memory), ran a bisection series of live probes rather than stopping at "unresolved":

1. `t3_dvd_probe_1d.c`, PROBE_N=0/1/2/3/4: declare_image then 0 to 4 of {0x19,0x1a,0x1b,0x1c} then 0x1d - ALL PASSED CLEANLY, including the exact 5-opcode sequence that crashed originally.
2. Same probe extended to the FULL real 18-opcode prefix (0x02,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0c,0x13,0x15,0x16,0x17,0x19,0x1a,0x1b,0x1c,0x1d) - an exact byte-for-byte reproduction of the original crashing sequence - ALSO PASSED CLEANLY.
3. Re-ran the original (fixed) `t3_dvd_inject.c` unmodified on the same now-settled G5 (uptime 1h+, many intervening test runs): ALL 53 opcodes completed, `outcome=PASS calls=61`, `TEST_EXIT=0`. No crash, no panic.log growth.

**Conclusion: the declare_image fix is correct and the 53-opcode list is genuinely safe** - the sequence itself is not the cause of the two live crashes. Both crashes happened on a G5 that had *just* rebooted (seconds to low-single-digit minutes of uptime). The most likely remaining explanation is some kernel subsystem (the accelerator, the shared-allocator pool, or GART state) not being fully settled immediately after boot - not a bug reachable by any sequence of command-stream opcodes once the system is up for a while. Not yet proven by a direct reboot-then-immediately-retry test (see below); recorded as the leading hypothesis pending that.

## Freshness experiment confirmed, but not opcode-specific: a post-boot race, not a bug in any one opcode

Direct test: rebooted the G5, ran the unmodified `t3_dvd_inject.c` (53-opcode list, declare_image fix) immediately (34 s uptime). It crashed again - but this time at a DIFFERENT point (dying on 0x07, right after 0x02/0x04/0x05/0x06 succeeded), not at 0x1d as before, and with no panic.log entry at all this time (the ssh session was abruptly reset - "Connection reset by peer" - consistent with a harder/different failure mode than the earlier kernel traps, and no auto-restart-via-panic this time; needed a hard power-cycle).

**Revised understanding:** the crash is not localized to the texture-bind family (0x19-0x2a) or any single opcode - it is a genuine race condition between this test's DVD flush activity and something in the accelerator/GPU's own post-boot settling (mode-setting, memory training, or similar), that manifests at different points run to run depending on timing. The SAME test, same fix, same opcode list: passes completely clean after the system has been up for a while (confirmed: 1h+ uptime run, PASS, 61 calls), and crashes somewhere in the first ~20 flushes when run within the first minute of boot, with the exact failure point varying.

**Not yet established:** how much settling time is actually needed (next experiment: reboot, wait a measured interval e.g. 60-90s, then run - bisect from there).

## Ring warm-up experiment: NEGATIVE result - not a call-count race, likely a real elapsed-time hardware condition

Tested whether 3 throwaway DVD-connection open/close cycles (each re-running `start_xdct_engine`, issue #127) before the real connection would let the IDCT ring genuinely settle even though its own readiness poll can't be trusted. Run on a freshly-rebooted G5 (3 min uptime): **crashed again, at the exact same opcode (0x1d) as the very first crash**, despite the warm-up. This argues against "needs more attempts" and toward a race bounded by real elapsed time (PLL lock, memory training, or similar), not by how many times software pokes at the hardware.

Cross-referencing all data points so far:
- 34 s uptime: crashed (at 0x1d, run 1; at 0x07, run 2).
- 3 min uptime, with warm-up: crashed (at 0x1d).
- 11 min uptime: crashed (at 0x1d) - same full 53-opcode test.
- 11 min uptime, isolated bisection probe (exact same 18-opcode prefix, no warm-up): passed clean.
- 1 h+ uptime: passed clean (all 53 opcodes).

The 11-minute split result (probe passed, full inject crashed, same opcode sequence) is the strongest evidence yet that this is **probabilistic hardware timing, not a deterministic settling threshold** - two runs at the same uptime with ostensibly the same sequence gave different outcomes. The bug in #127 (unconditional ready-report) means the driver itself has no reliable way to know when it's actually safe, so from a client's perspective this hazard cannot be fully eliminated by waiting a fixed amount of time, warming up the connection, or any other software-side workaround available to this project - it is an inherent property of the real hardware/vendor driver combination under investigation.

## `0x14`/`0x3d`/`0x3e`/`0x46` resolved by static trace (2026-10-05) - all four are the same broken composite family as `0x12` (#142), none should be live-tested

Full trace in `Tests/idct_engine_findings.md` section 9x. Each one's real kernel handler in `ATIR500DVDContext::process_command_buffer` writes the identical register signature `0x12`'s composite does (`0x1150`-range offset/pitch, `RB3D_DSTCACHE_CTLSTAT`=10, `0x138a`-range) - they are syntactic variants (single-forward, single-backward, two-source-average, two structurally distinct forward encodings) of the exact mechanism #142 root-caused as never posting its completion stamp. This supersedes the "wrong guessed record shape" note from the 2026-10-03 emulator sweep below: the shapes weren't wrong, the opcodes were never going to be injectable with any record shape, because they all hit the same stuck-firmware fence as `0x12`.

`0x3e` specifically: no userspace emitter exists for it in the VA driver (confirmed, both architectures) - its *kernel* handler is real and part of this family, but nothing in real software ever reaches it. Functionally the same "unreachable" conclusion as `0x36` (#125), for a different reason (no caller at all, vs. `0x36`'s caller existing but permanently gated off) - kept as a distinct note rather than merged with `0x36`'s entry.

**Do not add `0x14`/`0x3d`/`0x3e`/`0x46` to the live-safe opcode list.** They belong in `t3_dvd_inject.c`'s exclusion comment alongside `0x12` itself - live-testing any of them would only reproduce #142's known hang. DVD opcode coverage for this composite family is complete by static analysis; the only remaining DVD coverage gap is the 5 bound-texture-array opcodes (`0xb`, `0xd`, `0x18`, `0x43`, `0x44`), which need a real `declare_image` + slot-binding precondition before a live test is buildable.

## `0xb`/`0xd` live-verified safe; the real texture-bind mechanism itself (not `0x18`) hard-hung the G5 (2026-10-05, `t3_dvd_bind_and_use`)

Built a new live test (`Tests/destructive/t3_dvd_bind_and_use.c`) to close the last gap above. First finding, before the crash: **`0xb` and `0xd` both completed cleanly** with the real-usage argument pattern (word[2]=1, the branch that never touches the texture array) - register writes matched the statically-derived formulas exactly (see the test's own header comment). These are now live-verified, not just statically argued.

**The crash was not in `0x18`.** It happened one step earlier, in the texture-*bind* opcode itself (`0x1c`, slot 3), the first time any live test in this project's history passed it a real, registered image id. `t3_dvd_inject.c` and `t3_dvd_probe_1d.c` had both "exercised" the 0x19-0x24 bind family before, but always with a generic zero-filled record - the image id being bound was always `0`, which is never a registered id, so the kernel's own `pVVar42 != NULL` guard (`LAB_00037620`) made every prior test of this family a silent no-op. This was the first time it did real work, and it hard-hung the machine: `0x0b` and `0x0d` completed (logged `RESULT -> 0x0`), then the mirror log shows `ABOUT TO CALL inject 0x1c (w1=0xc000 ...)` with no result line after it, and the G5 went fully unreachable (`ping`: Destination Host Unreachable) seconds later. Required a manual power cycle - no panic.log, no new crash dump, no new `DiagnosticReports`/`CrashReporter` entry, and `system.log` jumps straight from the last pre-crash line to the next boot's own startup with nothing in between. This is a **silent hang**, not a catchable kernel panic - the same failure class as #141/#142's GPU wedge, not the same class as the kext's null-pointer panics (#123 et al.). Volume integrity confirmed clean after the power cycle (`diskutil verifyVolume`, no repairs needed).

**This happened at 1h3m G5 uptime** - past the only previously-"clean" data point for the unrelated post-boot timing race (#127, see above), so it's not that race recurring; it's a distinct, newly-triggered defect in the bind mechanism itself. No GAProbe or other live register capture was attached for this run, so (unlike #142) the actual stuck sub-unit isn't identified - only the trigger (a real bind via `0x1c`/`LAB_00037620`) and the failure class (silent hang, no panic) are known.

**Revises the "needs real binding" framing from the note above**: the precondition wasn't just *unexercised*, the bind mechanism itself is now a confirmed hazard - independent of and in addition to whatever `0x18`/`0x44` would have done with a bound texture, which remains completely untested. Filed as **#144**. `0x19`-`0x24` (the whole bind-family opcode range, not just `0x1c`) should be treated as hazardous with a real image id until this is root-caused - update `t3_dvd_inject.c`'s own framing of this family (it currently reads as "proven safe," which was only ever true for the id-0 no-op case).

## CORRECTION: `0x18`, not `0x1c`, is the real reproducible trigger - and it's a total kernel lockup, not a partial GPU wedge (2026-10-05, same day, follow-up session)

Two further live attempts (same test, same args, `w1=0xc000`/`0xc040`) both got **past** `0x1c`/`0x1d` cleanly and hung on **`0x18` instead**, 2-for-2. The note above's framing ("the bind mechanism itself is a confirmed hazard") is superseded - `0x1c`'s attempt-1 hang did not reproduce and is now the unexplained outlier, not the headline finding. `0x18` is the real, repeatable trigger.

A GAProbe capture (timed correctly this time - see `Tests/idct_engine_findings.md` section 9z for the two mistimed attempts first) caught attempt 3 live: this is **not** the same failure class as #141/#142's partial GPU wedge. In #142, GAProbe's own independent timer kept ticking for the full 150s, showing the rest of the GPU/kernel healthy while only one completion fence stayed stuck. For `0x18`: GAProbe logged its baseline, then **the entire `system.log` went silent** - every subsystem, not just GAProbe - from the hang until the next boot 41 minutes later. This is a total kernel lockup (consistent with an interrupt-disabled spin or a true bus-level wedge), not a localized stuck fence. No further register-level diagnosis is possible via this method; full detail and the one remaining escalation path (physical NMI break-in) in section 9z.
