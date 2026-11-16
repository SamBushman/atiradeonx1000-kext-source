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
