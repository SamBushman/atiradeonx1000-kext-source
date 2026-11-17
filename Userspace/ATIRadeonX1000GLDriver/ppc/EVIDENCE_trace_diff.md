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

### The 84 both-image-fault rows (Nov 15 15:20)
Classified by their normalised traces (offsets relative to the first argument; `both_fault_sig` grouping) and by reading the disassembly of one representative per group.
* **80 rows - invalid first argument, no effect completed:** AddrIndexedSet/Block/DListNode/ExportAddress/ExportSlot/ExportValue/FixedValue/IRInst/IRPseudo/ImmedConstBuffer/Interpolator/MachineAssembler/R300*/R520*/Physical/
  ResourceModel/Resource/SchedNode/TempValue/ThreadModel/VRegInfo/VertexRegister dtors and `OpcodeSetup__mode5/7/8`, `VRegInfo__new_127994`, plus `gldEmitInternalDrawSetupPackets` (ctx = 6) and
  `recordClearBindingTables` (this = 0x7fffffff). In both images the first access is a load/store through the invalid pointer and no store or call completes before the fault. They differ only in which access comes first:
  the stock reads a field of `this` (`lwz r30,0xd4(this)`) BEFORE it stores the vtable pointer, the rebuilt stores the vtable pointer first (or reads `this[-1]` first). With a valid object both do the same thing
  (these rows are IDENTICAL/REORDERED in the other trials). `trace_diff.py` now reports this as FAULT_SITE ("different access kind; no store or call completed in either image"); 81 of the 93 saved inputs move.
* **2 rows - stock bug:** `Program__assignOutputExportSlots` / `assignSharedExportSlots`: the unchecked export-slot index of #283/#284 (stock-driver-bug, preserved).
* **1 row - hoisting:** `gld_emitProgramStateAndConstants`: same three reads, then one extra halfword read in the rebuilt before the same invalid-pointer fault.
* **1 row - REAL DEFECT, #287:** `psnFormatRgbSource` (and the same construct in `psnFormatAlphaSource`). The corpus kept the dead jump-target computation of the recovered embedded switch as
  `*(int *)((unsigned char *)0x000d0730 + selectCode * 4)`: a load from a hard-coded STOCK text address with no relocation (`addis r10,r11,0xd; lwz r2,0x730(r10)`, no local-reloc entry), i.e. an unmapped read in any
  process on every call with `selectCode < 0x20` (`< 0x10` for the alpha variant, table 0xd0aa4). Found because the emulator image has no scattered relocations and the pair lacked a plain one. Fixed in `part_018.c`
  (the dead value is now the function's own address); scan of the corpus for stock-range literals used as dereference bases found no other text-address site (data-section literals are rewritten to relocated symbols
  by `link_corpus.py`, verified on psnDecDecodeHwInstruction). Verification on the rebuilt image: see the update below once the image is built.
`census_summary.py` now carries an EXPLAINED table (row name -> class, gate) for the rows resolved by hand, so each REVIEW row that remains has no recorded explanation yet.

### Update 15:25 - census on the #287-fixed image (HEAD 653b1f3d, md5 of image in ~/rung3/gld_653b1f3d), coverage-guided, 150 executions/function, 419,850 executions
`trace_diff_census_fuzz150_ring.tsv` (this directory). Gate: **FAIL 0, REVIEW 0**, PASS 2785, OUT-OF-CONTRACT 13, NO-INFO 1 (LAYOUT_ALL). Tiers: IDENTICAL 1391, REORDERED 928, FAULT_SITE 434, READ_SET 26,
PTR_VALUE_DEP 5 + IMAGE_DATA_DEP 5 + OOB_TABLE_INDEX 3 (out of contract, user decision 3), STOCK_HOISTED_LOAD 3, STOCK_DEAD_ARG_LOAD 2, STOCK_BUG_284 1. psnFormatRgbSource: REORDERED on the formerly faulting input;
neither psnFormatRgbSource nor psnFormatAlphaSource contains a `lis`/`addis` without a local relocation. Caveats stated honestly: gldValidatePointSize (deliberate #132, the only FAIL of the fixed-trial census) is not
reached by the fuzz run; command-ring coverage is still tiny (5 functions); 640 rows never return normally in both images (fault-only comparison); the hand-resolved rows are in `census_summary.py` EXPLAINED.

## Regression rerun with the final tool (Nov 15 19:41, census f, 8 trials/row, image ffcec0a3)
`__TEXT` read-only in the emulator, wild-fetch stop, partial-pointer and both-fault rules (see `Userspace/GLEngine/ppc/EVIDENCE_trace_diff.md`) applied to the GLDriver: gate FAIL 1 (`gldValidatePointSize`, deliberate #132), NO-INFO 42 (LAYOUT_ALL: functions returning image
addresses/strings), OUT-OF-CONTRACT 7 (5 PTR_VALUE_DEP `RegKind__*`/`Table1ea904__hasFlag0x11`, 2 IMAGE_ADDR_DEP), PASS 2749. Worst verdicts: REORDERED 1368, IDENTICAL 1232, FAULT_SITE 128, LAYOUT_ALL 42, READ_SET 21, PTR_VALUE_DEP 5,
IMAGE_DATA_DEP 2, EFFECTS 1. No new row, no FAULT_MISMATCH, no UNINIT_REBUILT, no EMUERR. Table: `~/g5logs/fnf_237/v5/census_gld_f.tsv`.

## Update Nov 16: extended coverage (1115 previously uncovered rows)
The earlier census covered 2799 rows (those with an argument model). 1115 further functions (C++ methods with `this`, destructors, ctx-taking helpers; extended ledger `fnfuzz_gen.py` with `FNFUZZ_EMU=1`, `-` signature = 8 random words) were run with the same tool, 150 inputs each (167,250 trials).
Images: stock `gld_ATIRadeonX1000GLDriver` (md5 5d63b5e3d86e770daa6aee657bc784c2), rebuilt `ATIRadeonX1000GLDriver_renamed` (md5 bc3fdb49c112bffb3b426d374354738d, the #287-fixed corpus). Table: `trace_diff_census_emu_fuzz150.tsv`.
Gate: PASS 1114, OUT-OF-CONTRACT 1, FAIL 0, REVIEW 0, NO-INFO 0. Tiers: IDENTICAL 772, REORDERED 162, FAULT_SITE 161, READ_SET 17 rows plus the hand-resolved rows below. 1296 of 167,250 trials excluded as layout-dependent.
**541 rows had at least one run in which both images returned normally; 574 rows fault in every run in both images** (random words are not valid objects), so for those the comparison only proves equal behaviour up to the common fault. They are NOT verified deeper; the typed-object-graph step (next phase of the agreed plan) addresses them.

Rows resolved by hand (all recorded in `census_summary.py`):
| row | verdict | class | proof |
|---|---|---|---|
| `gld_uploadParamConstants` | false UNINIT_REBUILT | emulator window | the alloca area lies below the 0x40000-byte frame window; `own_frame` now spans the whole stack below the entry sp. Re-run: clean. |
| `R300MachineAssembler__classifyAluOperation` | FAULT_MISMATCH | STOCK_DEAD_ARG_LOAD | the stock loads `this+0xa4` and never uses it; the rebuilt inlined callees do not read it (trials with arg0 0x7fffffff / 0x7f). |
| `ILReader__currentOpcode` | EFFECTS | DELIBERATE_64_CLAMP | the documented #64 clamp of the opcode index (rebuilt clamps, stock reads out of range). |
| `Compiler__initStaticLocals` | not comparable | emulator | the stock calls its own statically linked `atexit` (stock 0x2748); mapped by `TD_STOCK_HOOKS=2748:___cxa_atexit` to the rebuilt's `___cxa_atexit(f, 0, image-base)` call-out. Re-run: REORDERED 20/20. |
| `gld_initContextDispatch` | PTR_VALUE_DEP, every trial faults | OUT-OF-CONTRACT, **not established** | builds its dispatch table from image addresses; nothing past the first fault is compared. |
| 13 rows (`gld_setBufferAgpRefBacking`, `gld_setTexture*Backing`, `gld_setQuery*Backing`, `_gldModifyVertexArray`, `gld_submitRing`, ...) | EMUERR (UC_ERR_EXCEPTION) | emulator | an unaligned `lwarx` (the instruction before the reported pc; unicorn reports the pc after it). A real PPC970 raises an alignment exception on it, so both images fault identically; `trace_diff.py` now records it as a fault. After the change all 13 are IDENTICAL/FAULT_SITE. |
Emulator rules added: `own_frame` covers the whole stack below sp0 (alloca); `TD_STOCK_HOOKS` (statically linked stock library functions mapped to call-outs); misaligned atomic = fault; `v*printf` consumed-word comparison; `io_connect_method_*` input buffers compared by content.
Not covered / not established: the 574 fault-only rows; command-ring contents of these functions (they emit none with random inputs); instruction coverage is lower than stock in 328 rows and lower in the stock in 480 (different inlining, not a defect by itself).

## Update Nov 16 (afternoon): pointer-repair census, #293, #294, uncovered L-prefixed functions
Pointer repair + allocator mock (`TD_REPAIR=12 TD_HEAP=1`) on the 574 fault-only rows (table `trace_diff_census_emu_repair.tsv`; stock md5 of `gld_ATIRadeonX1000GLDriver` as in the earlier sections; rebuilt image built from commit 486a7ae7 (`v4`, before #293/#294), 150 inputs/row, 248,936 trials, 1053 excluded as layout dependent).
Gate: PASS 572, OUT-OF-CONTRACT 1, FAIL 1. 127 of 574 rows now return normally in both images in at least one run; 447 still fault in every run. Tiers: IDENTICAL 310, REORDERED 155, FAULT_SITE 92, READ_SET 13, STOCK_HOISTED_LOAD 1, OOB_LOCAL_INDEX 1, STOCK_BUG_284 1, EFFECTS 1.
Row classification: `R300MachineAssembler__classifyAluOperation` STOCK_HOISTED_LOAD (stock loads the table entry earlier; PASS), `ffvpEmitColorOutputs` STOCK_HOISTED_LOAD (PASS), `KhanVs__vslot88_assignOutputBindings` STOCK_BUG_284 (the #284 guard; PASS), `ILReader__currentOpcode` EFFECTS (deliberate 64 clamp; PASS), `Compiler__getOrCreateLoadConstN` UNINIT_REBUILT (unchecked out-of-range local index, out of contract), `gld_initContextDispatch` EFFECTS = **real defect**: #293 (the rebuilt allocated the three stream-state blocks twice) fixed by deleting the duplicate block (486a7ae7); that exposed #294 (below).

### Defect #294 (pair-result class, fixed)
Ghidra `undefined8` pair variables hold the callee's r3 in the HIGH word; `rewrites.rewrite_pair_results` now also handles a call nested in a comma expression and `(*codeVar)(...)` calls (509195f6, `Tools/userspace/test_rewrites.py`). Affected: `LoopHeader__verify` (the three vtable queries), `gld_initContextDispatch` (ctx+0x1394 was stored NULL), `R520MachineAssembler__vslot37_closeBranch`. Verified on image 509195f6 (md5 6f134a1897a1339994f5381e6026f4a3): no `srawi`-after-call sites remain; `gld_initContextDispatch` RET/RET; plain census as before (PASS 2785, OOC 13, NO-INFO 1, FAIL 0).

### Coverage gap found: 98 functions had no rebuilt symbol, so no emulator ledger row
ld64 drops the `lbl_<name>` symbols (the assembler labels of `L`-prefixed functions such as `LoopHeader__verify`) from the final image's symbol table; the ledger generator (`fnfuzz_gen.py`) found no rebuilt address and listed them as `no-rebuilt-symbol`. Recovered 59 of the 98 addresses from the per-object symbol tables (`nm` of `obj/*.o`, shifted by the offset of other symbols present in both; no conflicts or missing anchors reported; `~/g5logs/fnf_237/v16/aug.py`, `mkledger.py`) and made `ledger_missing.tsv` (generic 8-word signature). The other 39 are C-runtime / dyld glue of the stock (`cxa_atexit`, `atexit_common`, `*_stub_*`, `__keymgr_*` stubs); the rebuilt uses the system's, so they have no counterpart (not compared).
First row run, `LoopHeader__verify` (937 runs): IDENTICAL 352, REORDERED 186, EFFECTS 341, LAYOUT_DEP 11, TIMEOUT 47; the EFFECTS rows compare the argument registers of the vtable call-out `vcb`: r3..r8 equal, r9 differs (stock 1, rebuilt 7). r9 is not an argument of that call (the decompile calls `(**(code **)(*currentInst + 0x34))(currentInst)` with one argument); it is the register that holds `hasFlagBit` in the stock and is reused in the rebuilt: residue in an unused argument register. Not established for the other 58 rows; the full 59-row census is the next step.

## Update Nov 16 (evening): defects #297, #298, #299; rerun of the 18 flagged rows on the fixed image
Tools: `trace_diff.py` (TD_FLOATEXACT, TD_FLOATEDGE, wrapper unwrap, vcb rule) and `census_summary.py` as committed. Images: stock `gld_ATIRadeonX1000GLDriver` (as above); rebuilt built from cef0e8dd (`~/rung3/gld_cef0e8dd`) and 280e1f36 (`~/rung3/gld_280e1f36`, the image of the table `trace_diff_census_v20_rerun18.tsv`).

| issue | function(s) | cause (stock vs rebuilt) | verification |
|---|---|---|---|
| #297 | `gld_quantizePointSizeInt` (stock 0xa3560), seen through `gldValidatePolygonOffset` | stock `fadds` before `fctiwz`, rebuilt double `fadd` (f1 = -33554432.0: stock -33554432, rebuilt -33554431; also 8388609.0: 8388610 vs 8388609) | directed control `v19/ctl_quant.py`: differs on the old image, identical on cef0e8dd; trace differential quantize 479 runs IDENTICAL 395/READ_SET 84, PolygonOffset 453 runs no EFFECTS |
| #298 | `RewriteStack__pushOperandKeys` | stock `lbz;extsb` (returns -1), rebuilt zero-extended (255) | 315 runs, no return difference |
| #299 | `KhanVs/KhanPs/FudoPs__vslot85_findOrEncodeConstantVector` | stock `lfs`/`fcmpu` on the constant words, rebuilt VALUE-converted the uint to float: the vector passed to `Program__findOrCreateConstInst` is 3f800000 x4 in the stock, 4e7e0000 x4 in the rebuilt | directed control `v19/ctl_v85.py` (hook at the callee): differs on v15, identical on 280e1f36 for all three. The census did not see it (every run faults before the compare; the callee never reads the vector) |

Correction recorded in #297: `gldValidatePointSize` does not call `gld_quantizePointSizeInt`; its 61 EFFECTS rows (stock 0 vs rebuilt 63944 at the `sth` to ctx+0x1ccc) are the deliberate #132 clamp and are unchanged (re-run: EFFECTS 61 of 377, same value pair). Gate entry `DELIBERATE_132_CLAMP`.

Harness findings (not defects of the images): (1) the float arguments of the fuzz never reach |x| >= 2^23, so single-vs-double add differences before an integer conversion are invisible to random inputs (the old image's quantize shows no EFFECTS under 755 float-edge runs); `TD_FLOATEDGE=1` adds 2^23..2^26 values, and directed controls (known stock/rebuilt split on the old image) are what shows the harness can see these defects. (2) The trace differential does not compare the CONTENTS of a stack buffer passed by pointer to an in-image callee that is not reached or does not read it; rows that fault in every run therefore hide such defects (#299 was found through the flop-count audit, not the census). A source scan of all six corpora for a `float` local assigned or compared from an integer-pointer dereference finds no site other than the three #299 functions. (3) The flop-count detectors (`fpprec.py`, `magprec.py`, v18) need capstone `skipdata` (embedded jump tables stop the disassembler) and over-report (data words decode as fmsub); only "stock has 0, rebuilt has some" is a reliable signal; the 15 remaining flagged functions were reviewed: `FudoPs__ctor_191efc/_1920e0` inline the stock tail-callee 0x19175c (same FP sequence: xoris int-to-float, frsp, fsub without frsp), `gldValidatePointSize` (#132 adds two `fadds`), the rest are census-clean with count differences from inlining/rsize bounds - NOT individually proven by float-edge inputs (not established).

### Rerun of the 18 flagged rows (image 280e1f36, TD_FLOATEXACT=1, 150 inputs/row): gate PASS 15, OUT-OF-CONTRACT 2, REVIEW 1
| row | verdict | class / proof |
|---|---|---|
| `gldValidatePolygonOffset`, `gld_quantizePointSizeInt`, `RewriteStack__pushOperandKeys`, `KhanVs/KhanPs/FudoPs__vslot85_*` | clean | defects #297-#299 fixed |
| `gldValidatePointSize` | EFFECTS | deliberate #132 clamp |
| `ILReader__decodeInstruction`, `ILReader__nextInstruction` | FAULT_MISMATCH | stock indexes its opcode table with the unchecked 16-bit opcode (first trial: fault address 1344066140 = table 1342201180 + 51804*36 + 16, opcode word 51804 read just before); the rebuilt has the deliberate #64 clamp. Only the first mismatching trial was checked arithmetically |
| `Program__assignExportSlotsByKind` (and `Program__assignSharedExportSlots`) | FAULT_MISMATCH | stock unchecked slot-index store into the frame table (#283 / #284); rebuilt bounded |
| `R300VMachineAssembler__findFoldableMovePair` | FAULT_MISMATCH | stock `lwz r3,0x88(this)` is the first argument of the helper 0x19a538 which reads only r4 (`lwz r2,0x88(r4)` at 0x19a540): dead argument load |
| `Compiler__getOrCreateConstVectorN`, `extvsCreateVectorSymbolChain` | UNINIT_REBUILT (+EFFECTS, FAULT_MISMATCH of the same trials) | unchecked out-of-range index of a local table (constCount 29 into the 5-word lookupKeyWords; kind byte 32/15 into the 8-word storageClassTable): decision 3, out of contract |
| `psnDecodedToProgram` | FAULT_MISMATCH 1 of 787 runs | **established Nov 16 night (see the ENTRYARGS update below): decision 3, same unchecked index 0xfc1d in both images**. Earlier text: the stock faults in a `memset(r30, 0, 0x48)` at the end of the arena, the rebuilt earlier in a `lbzx` through the unchecked image-table index `lhz 0x28(r9)*2` (0xfc1d). Two unchecked accesses reached in a different order; not proven from both disassemblies |

## Update Nov 16 (night): ENTRYARGS census (`TD_ENTRYARGS=1`), defect #300
Tools: `trace_diff.py` / `census_summary.py` as committed (49a26bc2 and later), controls in `Tools/userspace/emu/controls/`. Stock `gld_ATIRadeonX1000GLDriver`; rebuilt images: v20 (`~/rung3/gld_280e1f36`, the census image) and v22 (`~/rung3/gld_49a26bc2`, #300 fixed).

**The mode.** The ordinary event stream never shows the CONTENT of a stack record a caller hands to an in-image callee when the callee faults or returns before reading it (the blind spot that hid #299). With `TD_ENTRYARGS=1`, at every call into a ledger function (library stubs excluded) the words the caller itself wrote into its own frame at each pointer argument r3..r(3+ngpr) are recorded (up to 16 contiguous written words; `stwu` prunes stale bytes of a new frame). Per argument the words compared are limited by the callee's read extent, by the distance to the next pointer argument of the same call, and by the shorter recorded record (at least the first word); only records inside the immediate caller's frame are kept; frame addresses are one class (OWNFRAME); NaN payloads normalised; printf-family and stub callees skipped; a callee in one image only, or called a different number of times, is skipped. A difference gives EFFECTS "callee argument record differs" when the core verdict is IDENTICAL/REORDERED/READ_SET/FAULT_SITE/FAULT_PARTIAL.

**Control (the mode can see a known defect).** `controls/ctl_entryargs.py`, the #299 rows (`vslot85_findOrEncodeConstantVector`, four equal float words): old image v15 EFFECTS "callee argument record differs" (stock 0x3f800000 words, rebuilt the int-to-float 4e7e0000), v20 IDENTICAL.

**Census.** v20 image, 3,914 rows, 150 executions/function, pointer repair (`TD_REPAIR=12`), `TD_HEAP=1`, 12 workers, about 4.3 h (the last row, `R300VMachineAssembler__copyControlFlowToOutput`, runs ~180k instructions per execution at ~2.5 s, with up to 12 repair retries per execution: slow, not hung). This census ran with the harness as of 14:10; its gate: FAIL 14, NO-INFO 2, OUT-OF-CONTRACT 34, PASS 3859, REVIEW 4 (3,913 rows at that time). All 20 non-PASS rows were re-run with the final harness (`~/g5logs/fnf_237/v21/gld_rr.tsv`, then v22 `v22/rr.tsv`):

| row(s) | first verdict | resolution |
|---|---|---|
| `psnReallocateTemps`, `scDumpShader`, `scDumpShaderToString`, `Inst__swapSharedTermBetweenUses`, `KhanPs__vslot59_tryEncodeSourceConstant`, `R300MachineAssembler__assembleAluInstruction` | EFFECTS "callee argument record differs" | harness artifacts of the first ENTRYARGS versions, removed one by one (raw frame addresses >= sp0 and block order -> OWNFRAME class + read extent + next-argument cap; pointer into a frame above the immediate caller -> bound to the caller's frame; stale GPR for a float / fewer-integer-argument callee -> limited to the ledger's integer parameters). All PASS in the re-run |
| `Compiler__getOrCreateLoadConst1/2/3`, `Compiler__getOrCreateConstVector2/3`, `IRInst__setIntConstantOperand4`, `IRInst__makeLiteralVec4Int`, `VRegPool__create` | EFFECTS "calls differ ... vcb" / FAULT_MISMATCH | harness: the call-out (`vcb`) stand-in return was a hash keyed by the TOTAL call-out count, so an inlined `memcpy` in one image shifted every later return value. Now keyed by call-out name + per-name call number. All PASS in the re-run |
| `Program__applySourceTokenToOperand` | UNINIT_REBUILT | harness: `same_run` (stack-fill comparison) compared the leftover registers r4.. of a `vcb` call-out although `compare` ignores them (rule `TD_VCB_ARGS`, default 1): r6 of the fourth vcb call differed between the two stack fills (0 vs 90) while every compared field was equal. `same_run` now applies the same rule. v22 re-run: REORDERED only. (A real dependence on uninitialised stack hidden in an ignored vcb argument would not be seen; the arity of those slots is unknown, same limitation as the vcb rule itself.) |
| `ValueKey__setOperandFromValueKey` | EXC IndexError | harness: a wild branch into the call-out window past the last registered stub raised in the hook; now a wild-branch fault like any non-code address. Re-run 666 runs: IDENTICAL 353, REORDERED 304, TIMEOUT 9 |
| `vsdisFlowOpcodeName` | NO-INFO (returns a string address) | content comparison `controls/strret_gld.py`: the C strings returned for flowOpcode -2..299 (including 8, 9, 0x35, 0x3e, 0x53) are equal in both images, 302 inputs, 0 differ. Gate entry `RETURNS_IMAGE_CONTENT_VERIFIED` |
| `gld_reserveVertexBufferSpace` | FAULT_MISMATCH stock fetch 125625768 / rebuilt read 270608716 | the callee chain reaches `gld_setPrimitiveInputRegisters` with primitiveMode 0xffff (the stored vertex limit) and reads `primitiveInputRegisterTable_001aa7a8[mode*4]` unchecked. Stock event `('R', IMG 2008996)` = table 0x1aa7a8 + 0x3fffc (inside the stock image), the rebuilt reads 0x101d2950 + 0x3fffc = 0x1021294c, past its image: decision 3, out of contract |
| `psnDecodedToProgram` | FAULT_MISMATCH 1 of 787 runs (earlier written "not established") | now established from the traces of the failing trial: both images read the same 16-bit word 0xfc1d (64541) at arena 1342335372 (stock event 7328, rebuilt 7260) immediately before the `lbzx` that indexes a byte table with it unchecked; the stock's read lands in its own image data (offset 2078674, value 0) and it continues to a later `memset` fault, the rebuilt's lands past the end of its image (fault 270590002): decision 3, out of contract |
| `Scheduler__scheduleBlock` (via `Scheduler__buildDependencyGraph`) | FAULT_MISMATCH stock fetch 4 / rebuilt read 2506665532 | **real defect #300** (below) |

**Defect #300** (found by this census, fixed in 49a26bc2): `Scheduler__buildDependencyGraph` (stock 0x16a568, rebuilt 0x185a44). In the instruction loop the stock does `bctrl` vslot 0x34 -> `bne 0x16b038` and `bctrl` vslot 0x38 -> `bne 0x16b038`, `0x16b038` being the loop advance `lwz r2,8(r28)`. The corpus sent those two cases (and the "tests failed" exits of the needsNoSchedulerNode path) to a label `checkInst` that re-evaluated the new-virtual-register tests and allocated (`compiler+0x3c4` + 1, `inst[0x25]`), a second allocation site the stock does not have (stock: one store to `0x94(r28)` at 0x16a6d0 and one `0x3c4` increment, 0x16a6c0/0x16a6c8, in the whole function). Trial 4: both images call vslot 0x34 on the first node (the stand-in returns 0xad10); stock `bne` skips, rebuilt `bne 0x186570` runs the flag test (`RegKind__flagBit0(inst[0x26])`, table read with a garbage kind). Fix: the label block only advances. Directed control `controls/ctl_bdg.py` on the saved trial: v20 FAULT_MISMATCH, v22 REORDERED (same faults); census re-run on v22 (`v22/rr.tsv`): Scheduler__scheduleBlock 904 runs, FAULT_SITE only; Scheduler__buildDependencyGraph, Scheduler__run/scheduleCycle/commitBundle no mismatch.

**Earlier-classified rows that ENTRYARGS also flagged (unchanged):** the sixteen-bit `sth` rows `gldPrimWrapperTriangles/QuadStrip/LineLoop_23a24`, `gld_reserveDrawSpace`, `gld_emitStampFencePacket`, `gldPrimInlineQuadStrip`, `ffvpValidateProgram`, `gldValidatePointSize`: stock 0 vs rebuilt 63944 at the `sth` to ctx+0x1ccc, store sites found with `controls/wr_pc.py` (stock 0x4ee50/0x4ee54, rebuilt 0x581f4/0x581f8): the deliberate #132 clamp. `gld_uploadParamConstants`: with a program record whose constant count is 0 the stock's `alloca(0)` buffer sits at the top of its frame and the callee writes 8 words there, over the saved r25-r27 slots (stock returns with r25-r27 clobbered; the rebuilt's frame layout keeps them): out of contract; whether a real program can reach an inconsistent record is **not established**. `Program__buildBlockArrayByKey`: the bucket loop count is a random 0x7ffffff.. in the trial, the stock stores one pointer per bucket into a 69-word local and walks past it, so the same stack address holds element 0 (stock) vs element 24 (rebuilt): out-of-bounds local index, out of contract; that a real bucket count is bounded by the key kinds is **not established statically**.

**Still open:** 674 rows have no run in which both images return (faults only); #300 was found only because one such row had a callee-level mismatch, so typed inputs for those rows remain the next coverage item.
