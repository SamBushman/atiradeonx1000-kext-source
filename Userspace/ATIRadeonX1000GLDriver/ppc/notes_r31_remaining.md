# r31: final GLDriver placeholder tail + project-closing sweep

Scope: part_019.c, part_022.c, part_023.c, part_024.c, part_037.c — 5 files r30's final sweep found were never assigned to any prior round (r27-r30 covered 26 other files).

## Renames
- `scDumpPixelProgram` (part_019.c): param_7 -> `unusedArg7` (CONFIRMED: forwarded unchanged into `scDumpPixelProgramPsn`'s own `unusedArg7` slot, which is never read there either).
- `Compiler__createFromRequest_da0c0` (part_019.c): param_1 -> `outState`, param_2 -> `request` (CONFIRMED: both are copied once into the already-named locals `stateOutHome`/`requestHome` and never used again under the old name; pure parameter rename, no structural change).
- `LoopHeader__verify` (part_022.c): param_2 -> `verifyResultCode` (INFERRED: holds the low word of a paired 64-bit vtable-query result, reassigned per loop iteration, forwarded to `Block__verify`'s own ignored slot — same vtable `verify()` signature as the base, which names these `unusedArg2..unusedArg7`); param_3/4/5/6 -> `unusedArg3..unusedArg6` (CONFIRMED: never read in this override either, pure forward, matching `Block__verify`'s established naming for the same vtable slots); param_7 -> `hasFlagBit` (CONFIRMED: `uint`, read directly as `currentInst[5] & 1`, drives real control flow in this function before being forwarded).
- `Block__splitEdgeAndConnect` (part_023.c): param_3 -> `newBlock` (CONFIRMED: forwarded as the 3rd positional arg to `Block__splitOutgoingEdge(block, successor, newBlock)`, whose own parameter at that position is named `newBlock`).
- `IfHeaderStatic__ctor_eb9e0` / `IfHeaderStatic__ctor_ebac8` (part_023.c, two near-identical ctors for different IfHeader vtable identities): param_3 -> `ifFooterBlock` (CONFIRMED: stored to `this[0x50]`, and `part_040.c:2393` reads that exact same field as `ifFooterBlock = ifHeaderAlloc[0x50]`).
- `Program__beginPass` (part_024.c): param_2 -> `passArg` (INFERRED: forwarded per-block to each block's vtable slot 0x48 — a per-block "begin pass" virtual call — and reassigned from the stale-register artifact `r4AfterCall` each iteration, matching the "forwarded/leftover register" pattern already named `staleArgN`/`passArg`-style elsewhere).
- `Program__assignHwRegistersForProjections`-family function in part_024.c (around 0xed... the one building IRProjection records): `iVar6` -> `subRegVReg` (CONFIRMED: the sub-vreg object returned by `createSubReg(...)`, used immediately as a VReg via `VReg__appendUser`/`VReg__addUse`/`IRInst__appendSource`; one web, one role, no split needed).
- `ValueKey__createConstantMov` (part_037.c): param_3 -> `unusedArg3` (CONFIRMED: `uint`, declared, never read in the 984-byte body; both call sites in part_048.c pass literal `0`).

## Dead code removed (not renamed)
- part_037.c: a leftover `int iVar13;` declaration in the function documented by the adjacent comment (the issue-#64 `iteratorState`/`iteratorCurrent` fake-struct fix) — the variable is referenced only in that historical comment's prose, never in live code after the fix merged `iteratorCurrent` into the `iteratorState` buffer. Removed the dead declaration. Gate came back SPLIT-EQUIVALENT (not IDENTICAL) for this one file — removing an unused local shifted the frame layout by 4 bytes; `split_equiv.py` confirmed 0 semantic problems across all 148 functions in the part.

## Gate
One commit (`19bd0c7e`), gated vs main `90e3cf7a`: `BIN=ATIRadeonX1000GLDriver sh Tools/userspace/lpnames/gate.sh r31_1 90e3cf7a` -> `VERDICT: SPLIT-EQUIVALENT`, `part_037: 148 functions compared, 0 problems`. No quota/disk issues (TMPDIR was `~/g5logs/tmp_r31`).

## Project-closing sweep (per directive)
Ran a comment/string-stripped Python regex sweep (not `ph.py`, which both under- and over-counts — see r29/r30's notes) covering every placeholder class across **every** `part_*.c` in `Userspace/ATIRadeonX1000GLDriver/ppc/`, plus every `.c` in `Userspace/libGL/ppc`, `Userspace/libGLProgrammability/ppc`, `Userspace/ATIRadeonX1000GA/ppc`, `Userspace/ATIRadeonX1000VADriver/ppc`.

**Result: 0 genuine placeholders anywhere in any of the four userspace binaries.** Every remaining raw regex hit in GLDriver's own files (part_003/004/014/016/017/018/025/041/042/044/049, ~54 raw matches) is inside a `/* ... */` historical investigation comment (mostly "issue #64 live-repro" fake-struct writeups from earlier rounds) or a printf format string, not live code — confirmed by hand for every file before concluding this.

This closes the GLDriver (and whole userspace) variable/parameter-placeholder naming effort started back in the q01-q08 rounds. Remaining known-separate work (not placeholders, out of this project's scope per [[project_userspace_naming_handoff_nov1]]): the ~1,043-variable "big web" hybrids already accepted as unsplittable in earlier rounds carry descriptive names already (not placeholders); DAT_/PTR_/LAB_ anonymous-object naming and the GLDriver token-stream language are already done (r04-r26); address-keyed data-layer naming for libGL/libGLProgrammability (PTR_<symbol> import slots) was deliberately left unnamed by design.
