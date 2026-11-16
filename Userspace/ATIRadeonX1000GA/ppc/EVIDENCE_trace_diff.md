# Trace differential (unicorn) - stock vs rebuilt GA, Nov 15 2026

Tool, tiers, gate rules: `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md`, `Userspace/libGLProgrammability/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`). Stock = the stock binary
(`~/g5logs/fnf_237/stockbins` / `/Library/ATIRadeonX1000-Rebuilt/stock`), rebuilt = `us_3c4e11b1` image, ledger ledger_1ec1_ga_rz.tsv (retargeted to the 3c4e11b1 image), 150 coverage-guided inputs per row, import arities from `Tools/userspace/import_arity.py`.
Census: `trace_diff_census_fuzz150.tsv` (this directory).

Result: 11 rows, gate PASS 11 (FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0): 1,307 IDENTICAL, 314 REORDERED, 29 LAYOUT_DEP of 1,650 trials. EFFECTS 0, FAULT_MISMATCH 0, UNINIT_REBUILT 0.

Not covered: the ledger holds 11 of 80 corpus functions (the fnfuzz-eligible ones); the others have no argument model in this census yet.

## Update Nov 16: extended coverage (35 rows, was 11)
`FNFUZZ_EMU=1 fnfuzz_gen.py` (ledger `ledger_emu_ga.tsv`, 35 candidates of the 80 corpus functions; the rest are not functions the generator can place) run through the same comparator, 150 inputs per row (5,250 trials), stock `ga_stock` against the
`us_3c4e11b1` image (corpus unchanged since): gate PASS 35 (IDENTICAL 16, REORDERED 15, FAULT_SITE 4), FAIL 0, REVIEW 0, NO-INFO 0; 26 rows have runs where both images return normally, 9 rows fault in every run. Census: `trace_diff_census_emu_fuzz150.tsv`.
Tool changes this needed (`trace_diff.py`): `io_connect_method_scalarI_structureO` was missing from the call-out arity table (default 8 made dead r9/r10 look like arguments; 4 false EFFECTS); IOKit method call-outs now compare the CONTENT of their input
buffers (scalar words / structure bytes) instead of the caller's address of them: the stock spills an argument into its caller's parameter area and passes that address, the rebuilt corpus passes a local (`__WaitComplete`: same word, different address).
