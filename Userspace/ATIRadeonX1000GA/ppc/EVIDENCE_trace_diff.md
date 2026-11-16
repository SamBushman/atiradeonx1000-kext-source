# Trace differential (unicorn) - stock vs rebuilt GA, Nov 15 2026

Tool, tiers, gate rules: `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md`, `Userspace/libGLProgrammability/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`). Stock = the stock binary
(`~/g5logs/fnf_237/stockbins` / `/Library/ATIRadeonX1000-Rebuilt/stock`), rebuilt = `us_3c4e11b1` image, ledger ledger_1ec1_ga_rz.tsv (retargeted to the 3c4e11b1 image), 150 coverage-guided inputs per row, import arities from `Tools/userspace/import_arity.py`.
Census: `trace_diff_census_fuzz150.tsv` (this directory).

Result: 11 rows, gate PASS 11 (FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0): 1,307 IDENTICAL, 314 REORDERED, 29 LAYOUT_DEP of 1,650 trials. EFFECTS 0, FAULT_MISMATCH 0, UNINIT_REBUILT 0.

Not covered: the ledger holds 11 of 80 corpus functions (the fnfuzz-eligible ones); the others have no argument model in this census yet.
