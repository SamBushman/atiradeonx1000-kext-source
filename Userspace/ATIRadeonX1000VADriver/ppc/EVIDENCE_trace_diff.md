# Trace differential (unicorn) - stock vs rebuilt VA, Nov 15 2026

Tool, tiers, gate rules: `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md`, `Userspace/libGLProgrammability/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`). Stock = the stock binary
(`~/g5logs/fnf_237/stockbins` / `/Library/ATIRadeonX1000-Rebuilt/stock`), rebuilt = `us_3c4e11b1` image, ledger ledger11_va_rz.tsv (retargeted), 150 coverage-guided inputs per row, import arities from `Tools/userspace/import_arity.py`.
Census: `trace_diff_census_fuzz150.tsv` (this directory).

Result: 35 rows, gate PASS 35 (FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0): 4,200 IDENTICAL, 428 REORDERED, 401 FAULT_SITE/PARTIAL, 113 TIMEOUT, 108 LAYOUT_DEP of 5,250 trials. EFFECTS 0, FAULT_MISMATCH 0, UNINIT_REBUILT 0.

Not covered: the ledger holds 35 of 120 corpus functions (the fnfuzz-eligible ones); the others have no argument model in this census yet.

## Update Nov 16: extended coverage (76 rows, was about a third of that)
`FNFUZZ_EMU=1 fnfuzz_gen.py` ledger `ledger_emu_va.tsv` (76 candidates), 150 inputs per row (11,400 trials), `va_stock` against the `us_3c4e11b1` image (corpus unchanged since), comparator as in the GA update (IOKit input buffers by content, arity table):
gate PASS 76 (IDENTICAL 34, REORDERED 29, FAULT_SITE 13), FAIL 0, REVIEW 0, NO-INFO 0; 58 rows have runs where both images return normally, 18 fault in every run; 114 of 11,400 trials excluded as layout-dependent. Census: `trace_diff_census_emu_fuzz150.tsv`.

## Update Nov 17: ENTRYARGS + heap/repair census (76 rows)
Mode: `TD_ENTRYARGS=1 TD_HEAP=1 TD_REPAIR=12 TD_ARITY_FILE=arity_va.tsv` (`controls/arity_gen.py` on this corpus), ledger `ledger_emu_va.tsv`, 150 coverage-guided inputs per row, `va_stock` against `va_rebuilt` (the `us_3c4e11b1` image; VA corpus unchanged since). Mode meaning as in the GA update of this date:
`TD_ENTRYARGS` compares the callee argument records, `TD_HEAP` makes malloc/calloc/realloc return zeroed blocks of a bump heap (same sequence in both images), `TD_REPAIR` re-runs a trial (up to 12 times) after both images fault on a null/unmapped pointer, patching the pointer source to a sub-object so the run proceeds.
Script: `run_ea_small.sh` (scratch `~/g5logs/fnf_237/v24`), census `trace_diff_census_ea_heap_fuzz150.tsv` (this directory).

Result: 76 rows, 27,604 trials (110 excluded as layout-dependent: the stock itself differs at a second slide): gate PASS 76, FAIL 0, REVIEW 0, NO-INFO 0, UNINIT_REBUILT 0. IDENTICAL 31, REORDERED 31, FAULT_SITE 14 rows. 74 rows have runs where both images returned normally; 2 rows fault in every run
(no typed input for them yet). Rows whose rebuilt image covered fewer instructions of the function than the stock: 11; stock fewer: 20 (coverage is reported, not a verdict).
Not covered: 44 of the 120 corpus functions have no argument model in the ledger (`ledger_emu_va.tsv` holds 76).

## Update Nov 17 (late afternoon): pointer-rich census of the fault-only rows (`ptrgraph_diff.py`)
The VA rows of `trace_diff_census_emu_fuzz150.tsv` whose every run ended FAULT/FAULT were rerun with `Tools/userspace/emu/ptrgraph_diff.py` (pointer-rich arenas, see the GLDriver evidence of this date), `TD_ENTRYARGS=1 TD_HEAP=1 TD_REPAIR=12`, 8 seed trials + coverage-guided mutation to 60 inputs per row. Table: `trace_diff_census_ptrgraph_fuzz60.tsv`. Gate PASS for every row (no EFFECTS, no UNINIT_REBUILT). 18 rows: REORDERED 15, IDENTICAL 2, FAULT_SITE 1; 17 of 18 now return normally in both images (before: none). The first run flagged `ava_destroy_context` (EFFECTS: `_IOServiceClose` call #216, r9/r10 differ): `IOServiceClose(connect)` takes ONE argument and the call-out arity table had no entry for it (default 8), so dead r9/r10 residue was compared; `trace_diff.py` now knows the arity of the IOKit/mach entries (`IOServiceClose` 1, `IOObjectRelease` 1, `IOServiceOpen` 4, `IOServiceGetMatchingService` 2, `IOServiceMatching` 1, `IOConnectMapMemory` 6, `IOConnectUnmapMemory` 4, `IOConnectSetCFProperties` 2, `mach_task_self` 0) and the row is PASS (r3..r8 were already equal).
