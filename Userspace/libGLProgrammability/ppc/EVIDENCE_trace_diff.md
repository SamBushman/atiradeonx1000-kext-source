# Trace differential (unicorn) - stock vs rebuilt libGLProgrammability, Nov 15 2026

Tool, tiers, gate rules: see `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md` and `Userspace/GLEngine/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`, `census_summary.py`).

Inputs: stock `libGLProgrammability.dylib` from `/Library/ATIRadeonX1000-Rebuilt/stock/` (md5 7f9f4e4e29e7ec66dac4748872863b4b; NOT the file under /System, which is the rebuilt copy installed Nov 8),
rebuilt `us_3c4e11b1/sbs/libGLProgrammability.dylib` (md5 40e96ec0c1b00f0cfeea5693d13b63ff), ledger `ledger_3c4e_glprog_rz.tsv` (508 rows), 150 coverage-guided inputs per row (76,200 trials).
Census: `trace_diff_census_fuzz150.tsv` (this directory). Reproduce: `trace_diff.py STOCK REBUILT LEDGER --all 16 --fuzz 150 --procs 30 --out OUT --symmap link/symbol_map.tsv --nm REBUILT.nm --funcs ledger.tsv --nargs NARGS`
(NARGS = the ledger-function table plus the import arities from `Tools/userspace/import_arity.py` run over Tiger libSystem/libmathCommon/libgcc/libstdc++).

## Result
Gate: PASS 507, OUT-OF-CONTRACT 1, FAIL 0, REVIEW 0, NO-INFO 0. Trials: IDENTICAL 58,831; REORDERED 12,587; READ_SET 749; FAULT_SITE/PARTIAL 1,919; FAULT_MISMATCH 0; EFFECTS 0; PTR_VALUE_DEP 0; IMAGE_DATA_DEP 0;
LAYOUT_DEP 1,087 (excluded: input is an address inside the image window); end state UCERR/UCERR 655 (both images raise the same unemulated exception: no comparison); TIMEOUT 309; UNINIT_REBUILT 3 trials (one row, below).
Outcome pairs over all trials: FAULT/FAULT 43,904, RET/RET 31,234, UCERR/UCERR 655, TIMEOUT/TIMEOUT 289, RET/FAULT 98 (all in LAYOUT_DEP trials, i.e. image-window inputs), TIMEOUT/FAULT 12, TIMEOUT/RET 8.

## The one OUT-OF-CONTRACT row
`_PPCRuntimeCompilerGetOffsetInRegister` (UNINIT_REBUILT, 3 trials): both images copy 0x24 bytes of a record to a local and then do `lbz 8(buf + *(record+4))` (stock `lbz r0,8(r28)`, r28 = buf + `lwz r2,4(r29)`; rebuilt 0x6e7bc/0x6e7d0): the
record field is an unchecked index into the local copy. With field > 0x1c the byte read lies beyond the copy; the two images have different frame sizes (stock 0x80, rebuilt 0xc0), so what lies there differs
(rebuilt: uninitialised stack, differs between the two fills; what the stock reads there is not established). Unchecked out-of-range index confirmed in both disassemblies -> out of contract (user decision 3, Nov 15).

## Tool changes needed for this binary (all in `trace_diff.py`, none changes a GLEngine/GLDriver verdict)
The stock is a prebound, split-segment dylib linked at 0x97b7b000: addresses are rebased so the image starts at the common slide; relocation addresses are relative to the first writable segment (MH_SPLIT_SEGS);
undefined symbols of type N_PBUD are imports; ledger, symbol-map and `_name_97c1c44c`-style names carry absolute stock addresses and are rebased; `abort`, `exit` and `__cxa_rethrow` end the run (noreturn: the
rebuilt/stock code after the call is not behaviour); libm callees (exp2, log2, acos, asin, atan, tan, trunc, atan2f, isnanf) take their arguments in FPRs. The first runs had 179 REVIEW and 13 FAIL rows; every one was
traced to one of these loader/arity gaps (stock fetch faults at 0x9000xxxx = prebound libSystem addresses; `_exp2`/`_memchr` call arguments compared in unused registers; vtable pointers canonicalised in the wrong
address space; code after `abort` executed), none to a rebuilt-code difference.

## Not covered
The ledger holds 508 of 1,799 corpus functions (the fnfuzz-eligible ones); the other ~1,290 (C++ methods with `this`/object graphs, varargs, callback-only, tiny) have no argument model in this census.
