# Trace differential (unicorn) - stock vs rebuilt GLDriver, Nov 15 2026

Tool: `Tools/userspace/emu/trace_diff.py` (+ `census_summary.py`, `diagw.py`, `diag_attrib.py`). Runs the stock function and the rebuilt function under the unicorn PPC32 emulator on identical
inputs and compares the ORDERED trace: external reads, writes, calls out, fault, return value and callee-saved registers. This replaces "returns/digest agree" (fnfuzz) with the user's
external-behaviour criterion (returns, values written, external read/write order, expected arguments, dead loads).

Inputs: stock `~/g5logs/fnf_237/stockbins/gld_ATIRadeonX1000GLDriver`, rebuilt `ATIRadeonX1000GLDriver_renamed` (md5 ffcec0a3b86b08475520a974b5f5a945, HEAD 3c4e11b1 image), ledger
`ledger_3c4e_gld_rz.tsv` (2799 rows), 8 trials per row (22,392 trials), each run under two stack fills (0 and 0x5a5a5a5a) and, for the stock, a second image slide.
Census table: `trace_diff_census_8trials.tsv` (this directory). Reproduce:

    PYTHONPATH=~/g5logs/fnf_237/pypkgs python3 Tools/userspace/emu/trace_diff.py STOCK REBUILT LEDGER --all 8 --procs 28 --out OUT.tsv \
        --symmap Userspace/ATIRadeonX1000GLDriver/ppc/link/symbol_map.tsv --nm ATIRadeonX1000GLDriver_renamed.nm --funcs Userspace/ATIRadeonX1000GLDriver/ppc/ledger.tsv --nargs gld_nargs.tsv
    python3 Tools/userspace/emu/census_summary.py OUT.tsv [VERDICT]

## Verdict tiers (strongest first)
IDENTICAL (full ordered trace equal) / REORDERED (same calls, same stores and same external reads between consecutive calls; only the order inside a call-free stretch differs) /
READ_SET (one image reads external memory the other does not: a dead / extra / hoisted load) / FAULT_SITE and FAULT_PARTIAL (both crash on the same kind of invalid access, or at the same
address, but different loads/stores had completed first) / FAULT_MISMATCH (one image returns where the other faults) / EFFECTS (a store, call or return value differs) /
IMAGE_DATA_DEP, IMAGE_ADDR_DEP, PTR_VALUE_DEP (see "layout-dependent" below) / LAYOUT_DEP (the STOCK itself behaves differently at a second slide: argument is an address inside the image window) /
UNINIT_REBUILT / UNINIT_STOCK / UNINIT_BOTH (a run that differs between the two stack fills reads an uninitialised local).

## Result (census s, 22,392 trials, 2799 rows)
| trials | tier |
|---|---|
| 9,072 | IDENTICAL |
| 11,935 | REORDERED |
| 80 | READ_SET |
| 405 | FAULT_SITE / FAULT_PARTIAL |
| 1 | EFFECTS (`gldValidatePointSize`, deliberate #132 clamp) |
| 8 | IMAGE_ADDR/DATA_DEP + PTR_VALUE_DEP (unchecked table index, see below) |
| 688 | LAYOUT_DEP (stock differs with its own slide; no information) |
| 33 | UNINIT_STOCK/BOTH (stock reads an uninitialised local; not comparable) |
| 95 / 75 | EMUERR / TIMEOUT (emulator exception on an instruction it does not model / step limit) |
| 0 | FAULT_MISMATCH, UNINIT_REBUILT |
Rows by worst verdict: IDENTICAL 987, REORDERED 1609, FAULT_SITE 131, LAYOUT_ALL 42, READ_SET 22, PTR_VALUE_DEP 5, IMAGE_*_DEP 2, EFFECTS 1.

## Artifact classes found in the tool itself and removed (census h -> s)
Each was identified from a concrete row before the tool was changed; none was assumed.
1. Repeated stores of the same value to the same address (stock dtors/ctors, `gld_setSamplerMinFilter`): consecutive duplicates collapsed (a store of an unchanged value to RAM is not observable).
2. libc calls: callouts were no-ops. The rebuilt calls `memcpy`/`strlen`/`strncpy` where the stock inlines the copy, so the rebuilt read an uninitialised destination (the 6 "UNINIT_REBUILT"
   `Compiler__getOrCreate*`/`IRInst__*` rows were this). The libc effect is now executed and logged as byte reads/writes, not a call.
3. Arity: `__ZdlPv` (operator delete) and `ecvt` were compared with 8 stale argument registers (now 1 and r5..r7 after the double); `_setjmp`, file/dl/pthread imports given arities.
4. A store that faults was logged as a write (`None` value) with different store form (stfd vs 2x stw): faulting stores are not writes.
5. Same-fault runs: stores/loads that completed before the common fault differ in order only -> FAULT_PARTIAL, not EFFECTS/READ_SET.

## Residual rows, each explained from data
* `gldValidatePointSize`, `gldPrimWrapperPolygon/Lines_*`, `gld_revalidateStreamProgram`: every differing store is at the `sth ...,0x1ccc(ctx)` of `gldValidatePointSize`
  (stock 0x4ee54, rebuilt 0x58144). The corpus carries the deliberate #132 clamp (ctx+0xf4/0xf8/0x108/0x10c, comments in part_007.c); stock does not clamp. Known deviation, not a defect.
* `RegKind__vectorWidthKind/laneSourceCount/flagBit7/flagBit8`, `Table1ea904__hasFlag0x11`: both images read the same table slot of an out-of-range index and test bits of the value;
  the slot holds an image pointer (V canon equal, raw differs: 0x100eca10 vs 0x1010067c), so the bit test depends on where the data sits. In-range indices are IDENTICAL/REORDERED.
* `Table__interpolatorKindToCode`, `ConstRecord__insertSwizzleVariants`, `psnDecodedToProgram` (trial 2): an UNCHECKED table index reads outside the table in both images and the neighbours differ.
  `psnDecodedToProgram`: index 38323*2+1 into `SYM_1dbf98` (28 bytes, stock 0x1dbf98) -> stock 0x1eeaff in `__DATA,__const`, rebuilt a different section. `insertSwizzleVariants`: `lwzx` at
  `table + (4-n)*4` with n=6 -> base-8, stock 0x16xxxx vs rebuilt a different object. Whether the rebuilt should reproduce the stock's neighbours (identical data layout) is a policy question, see below.

## Not yet explained / open (honest list)
* READ_SET 22 rows: stock-only loads (dead loads the rebuilt dropped) in 17 rows: gld_prepareVertexArrayBuffers, gld_clearBuffers, gld_validateVertexArrayStreams, gld_buildTextureStatePacket,
  gldResetProgramEntry, gld_quantizePointSizeInt, psnDecSortAddressSlots, psnDecCanonicalizeEntry, psnDecRecomputeSourceUsage, psnDecRetargetSourceReg, psnDumpPixelShader, Vector__removeValue,
  vsSourceSelectForConstant, ...; rebuilt-only loads in ilEmitPrologue, ilEmitShadowStateTokens, psDisasmFormatRgbSource (the rebuilt reads something the stock does not).
  Userspace maps only RAM command-buffer descriptors, so a dead load cannot reach MMIO; the observable effect of a load difference is only WHEN an invalid pointer faults. Not yet fixed.
* 131 FAULT_SITE rows (same kind of fault at different addresses = instruction order on an input that crashes anyway) and 1609 REORDERED rows (gcc-7 vs Apple gcc scheduling) are strict-order
  differences. Whether they must be eliminated is a gate decision for the user.
* 42 rows are LAYOUT_ALL (all trials land in the image window) and the emulator has no model for 95 trials (EMUERR) / 75 (TIMEOUT): need better argument generation / more trials.
* GLEngine, glprog, GA, VA, libGL not yet run through the tool.

## Update 13:30 - strict ordering chosen by the user; own-image constant reads excluded from the ordered trace
Reads of the image's own constants / pointer cells (the rebuilt loads addresses from its own constant pool where the stock builds them with lis/addi) are not external behaviour; excluding them moves
497 rows to IDENTICAL (census t: IDENTICAL 1484, REORDERED 1112, FAULT_SITE 131, READ_SET 22, PTR/IMAGE_*_DEP 7, EFFECTS 1, LAYOUT_ALL 42; table file replaced by census t).
First difference of the 1112 REORDERED-only rows (`Tools/userspace/emu/reorder_kinds.py`): 594 rows store form only (same bytes, different granularity / libc call vs inline copy),
256 store/store order, 105 load/load, 79 store/load, 73 load/store, 5 other. Examples (stock order is Apple gcc's schedule, e.g. `_gldTerminateLibrary` clears six globals in the order +8,+0xc,+0x10,... vs +0,+0xc,+8,...): pure scheduling.

## Update 13:55 - strict-order experiments (user: strict ordering, "do it"; corpus unchanged)
1. Compiler flags (whole image, G5 gcc-7, census of 2799 rows x 8 trials each; functions with NO non-identical trial): current -O2 -mtune=970 1419; +-fno-schedule-insns -fno-schedule-insns2 1369;
   +-fno-schedule-insns2 1397; +-fno-schedule-insns 1466; -mtune=7450 1413. Best-of-all per function (`census_union.py`): 1588 / 2799. Flags move functions both ways; they cannot reach strict order
   (1211 functions are clean in none of the five images; 630 of them are <=64 bytes, 293 <=128 bytes).
2. Source pinning with `__asm__ __volatile__("" ::: "memory")` between accesses, in the order of the STOCK trace (hand prototype, 4 functions, then reverted): Object__setThreeWords, IROperand__init and
   ValueKey__swapSources12 became IDENTICAL in 16/16 trials; HashTableIterator__begin still differs only inside its callee HashTableIterator__advance (itself REORDERED). The corpus source order is NOT the
   stock order (the stock hoists loads: IROperand__init reads operand[5] BEFORE its first store; setThreeWords reads +8,+0,+4 while the corpus reads [2],[1],[0]), so the pin order must be derived from
   the stock trace/disassembly per function; Ghidra source order cannot be reused.
3. Tools added: `census_union.py`, `show_order.py`, `reorder_kinds.py`.

## Update 14:10 - gate relaxed by the user (Nov 15): memory order/width/dead loads no longer gate; hardware registers stay strict
User rule: ordering of ordinary memory reads (and, by extension, the order and width of ordinary stores) is no longer required; hardware-register accesses stay strict.
In the userspace driver the hardware is programmed by packets (register offset + value dwords) written into the kernel-mapped command ring (`gld_submitRing`: header word ring+0x1c, cursor ctx+0x1dc, limit +0x1e0,
map +0x1e4) and handed over with IOConnectMapMemory/submit calls; nothing else is mapped to a register aperture in userspace (RAM descriptors only; VA types 4/5 not exhaustively verified).
So the strict channel = final contents of the ring (position + value of every dword), the ordered calls with their arguments, return values, and the final values of all other stores.
The tool now reports gate classes: PASS (IDENTICAL/REORDERED/READ_SET/FAULT_SITE - order and dead loads relaxed), REVIEW (FAULT_MISMATCH, out-of-range table-index classes), NO-INFO (layout/emulator),
FAIL (EFFECTS, HW_STREAM = differing ring contents, UNINIT_REBUILT).
Census (16 trials, ring-primed contexts; `trace_diff_census_16trials_ring.tsv`): PASS 2745, REVIEW 11, NO-INFO 42, FAIL 1 (`gldValidatePointSize`, deliberate #132).
COVERAGE LIMIT, stated honestly: only 5 functions / 37 trials wrote into the ring (109 dwords: gld_signalFence, gld_emitCopyRectPacket, gld_emitUnitClearPacket, gld_emitSingleUnitBinding, gld_emitBoundUnitObjects):
random context contents almost never satisfy the preconditions of packet-emitting paths. The hardware channel is implemented but largely UNTESTED; coverage-guided input generation is next.

## Update 14:35 - coverage-guided fuzz census and fault classification (Nov 15)
`trace_diff.py --fuzz N` (seed trials + mutation of words the function read, arg values, window zeroing; every execution compared; controls only for non-IDENTICAL). Census `fuzz150b`
(150 executions/function, 419,850 executions): GATE FAIL 0, PASS 2696, REVIEW 102 (FAULT_MISMATCH 92, PTR_VALUE_DEP 5, IMAGE_DATA_DEP 5), NO-INFO 1. gldValidatePointSize (deliberate #132) was not
hit by the fuzz run; it remains the single FAIL of the fixed-trial census.
`fault_classify.py` (operand-text PPC parser; capstone has no PPC regs_access) on the 93 saved FAULT_MISMATCH inputs: BOTH_FAULT 84 (both fault, different fault kind/site), one-sided 9:
USED_LOAD stock-only: ffvpPrepareFogExp / Exp2 / Linear (stock `lwz r2,4(r11)` then `lwz r2,0x10(r2)`, rebuilt returns without it), USED_LOAD rebuilt-only: gld_applyAnisotropyOverride,
opcodeInfoRgbHwOpcode; undetermined (control transfer before overwrite): IRInst__scaleByOutputScale, Program__laneKindOfIlType, R300/R520MachineAssembler__vslot65_declareNodeRegisters.

### The 9 one-sided FAULT_MISMATCH rows, resolved from disassembly (Nov 15 14:50)
fault_classify's "USED_LOAD" label is only a straight-line check; it does not see that a load chain is consumed only after a branch. Each row below was resolved by reading both images.
* **Stock-only fault, hoisted loads (3):** ffvpPrepareFogExp / ffvpPrepareFogExp2 / ffvpPrepareFogLinear. Stock (0x9b790 etc.) loads `ctx+0x3d4`, then `[+4]`, then `[+0x10]` BEFORE the early-exit
  tests `ctx+0x330 == -1` / `ctx+0x70 == -1` (return 2); the rebuilt does the same loads after those tests. Only a bad `ctx+0x3d4` on an early-exit path differs (stock faults, rebuilt returns 2). Return values and
  stores are identical when the pointer is valid. Scheduling/hoisting artifact; rebuilt is the safer side. Not a defect.
* **Stock-only fault, dead load of an unused thunk argument (2):** R300/R520MachineAssembler__vslot65_declareNodeRegisters. Stock loads `this->0x5c` and forms `this+0x90` as the unused arguments of the 12-byte thunk
  at 0x1955d0 `(node, unused1, unused2, compiler, this)` -> `ConstRecord__emitStores(node, this, compiler)`; the rebuilt calls emitStores directly with the same three live arguments. Only a NULL `this` differs.
* **Rebuilt-only fault, unchecked table index (4):** opcodeInfoRgbHwOpcode (r4=0x800 into a ~0x30-row table of 0x38 bytes), gld_applyAnisotropyOverride (`lwzx` of a derived index<<2), IRInst__scaleByOutputScale
  (`return table[r3]`, `lfsx f1,r3<<2,tbl`, no bound), Program__laneKindOfIlType (`lwzx r3,r4<<2,tbl`). Both images read past the table; the read stays inside the image in the stock (table lower in the image) and
  leaves the mapped image in the rebuilt (table higher). This is the same layout-dependent class as PTR_VALUE_DEP / IMAGE_DATA_DEP; whether it matters is user decision 3 (open): out of contract vs identical data layout.
Net: no rebuilt defect among the 9. Remaining: the 84 BOTH_FAULT rows (both fault, different kind or site) have not been classified individually.

### Decision 3 (user, Nov 15 14:40): out-of-range (unchecked) table-index reads are OUT OF CONTRACT
No data-layout match with the stock is required for reads past the end of a table. IMAGE_DATA_DEP / PTR_VALUE_DEP verdicts and the rebuilt-only faults on an unchecked index are reported as OUT-OF-CONTRACT (not REVIEW)
by census_summary.py. A row is only moved here after the unchecked index load is confirmed in the disassembly of both images (done for the rows listed above); a new row is not assumed to be this class.
