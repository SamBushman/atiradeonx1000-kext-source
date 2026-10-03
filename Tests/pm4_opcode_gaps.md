# GL opcodes never observed on the stock kext (issue #42 criterion 2) - what is known about each

Context: `Tests/pm4_opcode_usage.md` (generated) lists what 30+ real/synthetic workloads made the stock GL driver emit: **51 of the 66 inventory opcodes (77 %)**, 0 anomalies. This file explains the 15 that were
never seen. "Emitter" = a function of the stock `ATIRadeonX1000GLDriver` that stores the opcode's header constant `0xNN000000` (found in the Ghidra C reconstruction `Userspace/ATIRadeonX1000GLDriver/ppc/`; a
literal-store search cannot find headers built at run time, so "no emitter found" is **not** proof the driver never emits it). "Kernel meaning" is from `GAPS.md`, the headers and `Sources/ATIR500GLContext_process_command_buffer_Port.cpp`.

| opcode | kernel meaning (source) | userspace emitter | status |
|---|---|---|---|
| 0x02 | sets the dispatcher's return value to 1 (GAPS.md section 3: DVD sets 3) | none found (only flag constants `0x2000000` in other structures) | no known trigger |
| 0x03 | not characterised | none found (only flag constants) | no known trigger |
| 0x27 | handler at dispatcher line 1015, not characterised | none found | no known trigger |
| 0x2a | maps a mode value (1->0, 2->4, 3->5, 4->6, 7->2, default 1) to a hardware value | `FUN_00020b30` (part_003.c:4831; PM4 `0xc0089b00` + rectangle parameters) | emitter exists; trigger not found (draw/read buffer selection, copy and resolve operations tried) |
| 0x2b | explicit mid-stream flush: calls `submit_buffer` | none found | no known trigger (glFlush, glFinish, front-buffer draws, fences tried) |
| 0x2c | clip/bounds pairwise MAX that depends on whether an FBO render target (`this+0x3bc`) is active | none found | no known trigger (FBO + viewport/scissor changes tried) |
| 0x2d | FSAA resolve blit (GAPS.md) | `FUN_00021c70` (part_003.c:4891; 1028-word record) | emitter exists; not triggered by multisample window reads/copies/swaps (which did give 0x30) |
| 0x31 | depth buffer resolve (GAPS.md) | `FUN_00018120` (part_002.c:9620; 1000-word record) - a large fixed-function state validator that also calls the 0x2a and 0x2d emitters | emitter exists; trigger not found |
| 0x35 | render-target generation stamp (GAPS.md) | `FUN_000369f0` (part_005.c:6141) | emitter exists; trigger not found (FBO switches, render-to-texture then sample tried) |
| 0x36 | not characterised; its emitter stores a primitive type and a count (array draw?) | `FUN_00027150` (part_004.c:1773) | emitter exists; not triggered by large client arrays, VBOs, vertex array range, display lists |
| 0x38 | not characterised; emitter stores an index-size * count (indexed draw?) | `FUN_00026bf0` (part_004.c:1584) | same as 0x36 |
| 0x3d | not characterised; emitter writes a type-keyed record (`0x132`, `300`, ...) | `FUN_00017310` (part_002.c:8742) | emitter exists; trigger not found |
| 0x43 | not characterised | none found | no known trigger |
| 0x45 | kernel offset 0x28200 (Headers/ATIR500GLContext.h:359) | `FUN_0002ce40` (part_004.c:6100), `FUN_00031340` (part_005.c:2305) | emitter exists; trigger not found |
| 0x46 | "fast clear", kernel offset 0x292a0 (Headers/ATIR500GLContext.h:349) | none found | no known trigger (exact 0/1 clears tried; that window mode stalled the driver, see below) |

What was run to look for them (all logs in `Tests/baseline/opcode/`): per-feature pbuffer programs (multiple texture units, texture formats/targets, FBO, queries/fences, clears, fixed-function state, draw methods, shaders and ARB
programs, pixel operations, VBOs, big draws), the windowed program with 0/2/4/6-sample multisample, depth/stencil variants and clear/hz/resolve modes, and two real applications (the Godot game and editor).
The 12 opcodes found by these were mostly the texture-bind family (units 2-14 need 16-unit multitexturing, 0x08-0x14), 0x05 (per frame in windows and with 16-unit fragment programs), 0x04 and 0x30 (multisample windows), 0x32 (window
copy/readback), 0x26 (big draws), 0x09/0x0d and others.

## Hazards found while doing this (stock driver, G5, 2026-10-03)

* A seeded random fixed-function state stress (`Tests/userspace/glstress.h`) made the GL stack call `exit(0)` from inside `glClear` (seed 1, ARB vertex programs enabled with other random state, and a second combination at 200
  iterations), produced multi-minute runs, and left killed processes in the exiting state for 40 s to 3 min.
* After that and a window "fastclear" mode that never finished its frames, **new GL clients hung at start-up** (even the safe `cgl_probe`) until the G5 was rebooted. Those modes are marked as hazards in the sources and are not part of any default run.

## What 100 % would need

For the 8 opcodes that have an emitter, the missing piece is the GL operation that reaches it; the efficient way is to trace which GLDriver functions run for a given GL call (function-entry tracing under gdb, as in
`Tools/userspace/emu/hwseq.py`) and match it against the emitter addresses above. For the 7 with no emitter found, the first step is to prove whether the driver can build those headers at all (dynamic header construction),
and if it cannot they are unreachable from the stock userspace driver and cannot be part of a real-workload coverage figure. Neither is a blind-workload problem any more.
