# Trace differential (unicorn) - stock vs rebuilt GLEngine, Nov 15 2026

Tool and tiers: see `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`, `census_summary.py`). Gate rules (user, Nov 15): strict for hardware registers
(command ring contents, ordered calls with arguments, return values, final stored values); relaxed for order/width of ordinary memory loads/stores and dead loads; unchecked out-of-range table-index
reads are out of contract.

Inputs: stock `GLEngine_stock` (md5 02f4a2854a95be1f2853baeb99ae22b3), rebuilt image built from commit 10aa00e5 (with #288 fix; md5 6fd17c4f05a80b103c01d213a99002b8, G5 `~/rung3/gleng_i288`),
plain ledger (2673 rows), 150 coverage-guided inputs per row (400,950 trials). Census f (`~/g5logs/fnf_237/v5/census_gleng_fuzz150f.tsv`), reproduce:

    python3 Tools/userspace/emu/trace_diff.py STOCK REBUILT LEDGER --all 16 --fuzz 150 --procs 30 --out OUT.tsv --symmap GLEngine_stock.syms --nm REBUILT.nm \
        --funcs Userspace/GLEngine/ppc/ledger.tsv --nargs gleng_nargs.tsv
    python3 Tools/userspace/emu/census_summary.py OUT.tsv [VERDICT]

## Result (census f)
Gate: PASS 2669 (of which 8 resolved by hand below), OUT-OF-CONTRACT 4, FAIL 0, REVIEW 0, NO-INFO 0.
Trials: IDENTICAL 210,621; REORDERED 125,202; READ_SET 2,402; FAULT_SITE/FAULT_PARTIAL 57,949; FAULT_MISMATCH 486 (the 8 rows below); PTR_VALUE_DEP 186; LAYOUT_DEP 2,476 (excluded);
TIMEOUT 1,552 (not informative); EFFECTS 0; UNINIT_REBUILT 0; EMUERR 0.

## Defect found by the census
`_gleSetAttrib` (GL_PIXEL_MODE_BIT restore): ten pixel-map counts passed as doubles (K&R call, `float *` read) -> issue #288, checked patch `PATCHES['_gleSetAttrib']`, fixed in the image above;
`_gleSetAttrib` no longer appears in the review list. (Class: int word read through a `float *` and passed to an unprototyped callee; a source scan of all 3150 GLEngine functions found no other site.)

## The 8 one-sided FAULT_MISMATCH rows (stock faults on a load, rebuilt returns)
`_glActiveStencilFace_ListExec`, `_glSamplePass_ListExec`, `_glGetPixelMapuiv_Exec`, `_glGetPixelMapusv_Exec`, `_gleLookUpTexture1D/3D`, `_gleLookUpNonProxyTexture1D/3D`.
In each, the stock performs a load early / unconditionally whose value the rebuilt reads later or not at all (confirmed from the disassembly of both images, session Nov 15 ~17:00; the
`_glSamplePass_ListExec` load feeds a `blr` function). Stores and calls out before the fault are identical. Classified STOCK_HOISTED_LOAD (dead-load, relaxed by the user's rule), gate PASS
(`EXPLAINED` in `census_summary.py`). Not "verified identical": the rebuilt does not perform that load, so a read that is implicit hardware behaviour would differ; userspace maps RAM only, so the
difference is fault timing on an invalid address.

## OUT-OF-CONTRACT (4 rows) and the emulator rules added for this census
| row | verdict | proof |
|---|---|---|
| `_glePreInitTOC` | PTR_VALUE_DEP (r3 0 vs 0x80000000) | the stock never writes r3 (returns the incoming r3); the corpus declares `int` and returns an uninitialised `in_r3`; its only caller ignores the result. Not an observable return. (A `void` signature would match the stock; not changed because the result is unused.) |
| `_glEvalCoord2fv_CompExec` | both fault, different places | an image pointer is stored and part of it is read back; the accessed address is built from those address bits, which depend on image layout |
| `_glVertex2iv_Comp`, `_glVertex2s_Comp` | stock write fault, rebuilt returns | same mechanism; verified arithmetically: stock fault address = loaded base + 4 x (merged pointer word) for both images (2020626488 = 1342250204 + 4 x 169594071; rebuilt 2131091512 = 1342250204 + 4 x 197210327) |
Also PTR_VALUE_DEP in earlier censuses (now REORDERED or PASS): `_glColor4iv_Comp`, `_glBindVertexArrayEXT_Comp` (wild write address inside the larger rebuilt image only), `_gliExecDispatchTable` (stock one-instruction wrapper entries mapped to rebuilt names).

Emulator rules (all in `trace_diff.py`): wrapper-alias mapping (stock `b target` entries and fall-in aliases); partial stored-pointer reads also explain a fault-vs-return difference; both fault after
identical ordered stores and no call -> FAULT_SITE; a fetch outside the image text (wild branch into arena/stack data) ends the run as `('F','wild',addr)` in both images; `__TEXT` is mapped read-only
(a wild store into it faults like a real process; before this it persisted across runs in a worker and made 3 rows EMUERR_ALL - not a defect of either image, reproduced standalone as clean).

## Not covered / not established
Rows whose every trial faults in both images (907 rows) only prove the crash behaviour equal; hardware-channel coverage for GLEngine (it emits no ring packets itself) and the import-reaching functions
beyond the call-out arguments are not exercised by this census. glprog, GA, VA, libGL: not yet run through the trace differential.

## Update Nov 16: extended coverage (683 previously uncovered rows)
683 further GLEngine functions (all sizes; `fnfuzz_gen.py` with `FNFUZZ_EMU=1`, `-` signature = 8 random words), 150 inputs each (102,450 trials). Images as above: stock md5 02f4a2854a95be1f2853baeb99ae22b3, rebuilt `GLEngine_rebuilt_i288` md5 6fd17c4f05a80b103c01d213a99002b8. Table: `trace_diff_census_emu_fuzz150.tsv`.
Gate: PASS 683, FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0. Tiers: IDENTICAL 399, REORDERED 138, FAULT_SITE 136, READ_SET 10 (rows by worst verdict). 428 of 102,450 trials excluded as layout-dependent.
389 rows returned normally in at least one run in both images; **294 rows fault in every run in both images** and are only proven equal up to the common fault (not verified deeper; typed inputs are the next step of the agreed plan).
Rule changes used: `own_frame` covers the whole stack below sp0 (alloca), misaligned `lwarx` = fault (both rules only relax comparisons; the 683 rows were run before the second rule and contained no EMUERR).

## Update Nov 16 (afternoon): pointer-repair census, #295, #296
Pointer repair (`TD_REPAIR=12`: a both-image fault on a null-page / near-null address makes the emulator build the missing object by patching the pointer cell that produced the address) and the allocator mock (`TD_HEAP=1`) were run on the 294 rows whose trials all faulted (table `trace_diff_census_emu_repair.tsv`; stock md5 02f4a2854a95be1f2853baeb99ae22b3, rebuilt `GLEngine_rebuilt_i288` md5 6fd17c4f05a80b103c01d213a99002b8, 150 inputs/row, 142,902 trials).
Gate: PASS 292, OUT-OF-CONTRACT 2, FAIL 0. 191 of the 294 rows now return normally in both images in at least one run; 103 still fault in every run.
The two OUT-OF-CONTRACT rows, with data:
| row | verdict | proof |
|---|---|---|
| `_gleOptimizeDisplayListCreateHashTable` | PTR_VALUE_DEP (150/150, RET/RET) | the bucket is `(address of the _gle*_ListExec function) & 0x7c` (`uVar1 = uVar6 & 0x7c`): stock 0x10044004 -> bucket 4, rebuilt 0x1004a500 -> bucket 0, so the table entries land in different slots by construction; calloc(1,0x80) and every malloc(16) call are identical in both, and the entries' contents are the same record words. Same as the fnfuzz `FNFUZZ_ADDRDEP` classification. |
| `_gleVtxLightRGBABackPtr` (first run, before #295) | IMAGE_ADDR_DEP, 8 of 150 inputs stock RET / rebuilt FAULT | NOT address dependence: defect #295 (below). The classification came from different image constants being read by the two layouts; the fault is in the call. |

### Defect #295 (found by this census, fixed)
`FUN_000d45ec`, `FUN_000d4a8c`, `_gleVtxLightRGBAFrontPtr`, `_gleVtxLightRGBABackPtr`: the first indirect call of `PTR__gleVectorNormalize_00112064` was `(fparam_1,param_1,&local_d0,&local_d0)`; the stock passes `(ctx, vec, vec)` (r3 = ctx, r4 = r5 = &local_d0; stock 0xd47e0.., 0xd4c84.., 0xd60e4.., 0xd6590..0xd65c0). The stale double in f1 shifted every argument two registers; `_gleVectorNormalize` read its input through r4 = low word of the double and faulted at 0x80000004. Checked patches in `Tools/userspace/patches.py` (4 entries), `part_044.c` edited, commit 19d5da51, image `GLEngine_rebuilt_i295` (md5 d81a61c540fb956779383c7b4a669e80, G5 `~/rung3/gleng_19d5da51`).
Re-run on the four functions (`trace_diff_census_295_light4.tsv`, 150 inputs/row): no stock RET / rebuilt FAULT row remains. Scan of all six corpora for an indirect call with a float argument: only these 4 lines.

### Open defect class #296 (not fixed): never-assigned `extraout_f*` / `extraout_r*`
The same four functions still differ (FUN_000d45ec EFFECTS: stock calls `_pow`, rebuilt not; `_gleVtxLightRGBABackPtr` PTR_VALUE_DEP: stored 0x7fc00000 vs 0x7f800000; `_gleVtxLightRGBAFrontPtr` FAULT_PARTIAL). Cause shown by the fcmpu operand sequences of the two runs (FUN_000d45ec trial, repro pickle in `~/g5logs/fnf_237/v17/repro4`): after the `_gleVectorNormalize` call the stock compares its returned length (f1 = NaN vs 4.99e-06 at stock 0xd4828), the rebuilt compares an unrelated register (4.99e-06 vs 1.0000000000000069 at rebuilt 0xfb25c), because the corpus reads `extraout_f1_00`, a declared variable that is never assigned.
Scan (`Tools/userspace/extraout_scan.py`, list `audit_extraout_f_unassigned.tsv`): 272 unassigned `extraout_f*` reads in 148 functions (360 / 170 with `extraout_r*`); GLDriver, glprog, GA, VA, libGL: 0. Precise live-read count (host gcc 14 `-O2 -Wmaybe-uninitialized` over every part, `~/g5logs/fnf_237/v17/host_uninit.log`): `extraout_f` 117 reads in 111 functions, `extraout_r` 62 in 17, `in_f` 1025 in 155, `in_r` 262 in 90, `in_stack_*` ~200; 347 functions with at least one. Which of these change behaviour is not established; the census finds only those reachable with the emulator's inputs. Fix design (per callee: the stock callee writes f1/r3 and returns it -> typed return + assigned; or leaves it unchanged -> keep the caller's live variable) is awaiting the user's decision (Ghidra re-decompile of the callees vs C-level rewrite).

## Update Nov 16 (evening): #295 closed, #296 status
Census 296b (`trace_diff_census_296b_light8.tsv`, 123 of the 126 rows at the time of writing; rebuilt image built from ff129261): GATE PASS 122, OUT-OF-CONTRACT 1 (`_glBitmap_NoopExec`, PTR_VALUE_DEP). The eight light-vertex routines (FUN_000d45ec, FUN_000d4a8c, `_gleVtxLightRGBA{Front,Back}Ptr`, `_gleVtxLightSpecRGBA{Front,Back}{,Ptr}`): IDENTICAL / REORDERED / FAULT_SITE only; no EFFECTS, PTR_VALUE_DEP or FAULT_PARTIAL (FUN_000d45ec no longer differs in the `_pow` call). Caveat: 423-1626 of each row's 430-1628 runs fault in both images with random inputs, so equality holds for the runs that reach the code. #295 closed on this evidence.
#296 (never-assigned extraout_*): per-site table `audit_extraout_live_classified.tsv` (179 live reads: 12 FIXED, 155 BENIGN with the stock callee's register use, 12 DOCUMENTED with the dead use NOT proven). Open criterion: those 12 sites.
