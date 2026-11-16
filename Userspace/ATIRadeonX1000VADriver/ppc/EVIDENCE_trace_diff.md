# Trace differential (unicorn) - stock vs rebuilt VA, Nov 15 2026

Tool, tiers, gate rules: `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md`, `Userspace/libGLProgrammability/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`). Stock = the stock binary
(`~/g5logs/fnf_237/stockbins` / `/Library/ATIRadeonX1000-Rebuilt/stock`), rebuilt = `us_3c4e11b1` image, ledger ledger11_va_rz.tsv (retargeted), 150 coverage-guided inputs per row, import arities from `Tools/userspace/import_arity.py`.
Census: `trace_diff_census_fuzz150.tsv` (this directory).

Result: 35 rows, gate PASS 35 (FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0): 4,200 IDENTICAL, 428 REORDERED, 401 FAULT_SITE/PARTIAL, 113 TIMEOUT, 108 LAYOUT_DEP of 5,250 trials. EFFECTS 0, FAULT_MISMATCH 0, UNINIT_REBUILT 0.

Not covered: the ledger holds 35 of 120 corpus functions (the fnfuzz-eligible ones); the others have no argument model in this census yet.
