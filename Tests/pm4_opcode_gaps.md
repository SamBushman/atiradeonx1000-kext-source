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
