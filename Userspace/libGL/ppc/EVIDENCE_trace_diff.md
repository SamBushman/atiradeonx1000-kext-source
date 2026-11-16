# Trace differential (unicorn) - stock vs rebuilt libGL, Nov 15 2026

Tool, tiers, gate rules: `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md`, `Userspace/libGLProgrammability/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`). Stock = the stock binary
(`~/g5logs/fnf_237/stockbins` / `/Library/ATIRadeonX1000-Rebuilt/stock`), rebuilt = `us_3c4e11b1` image, ledger ledger_1ec1_libgl_rz.tsv (retargeted; sbs/libGL.dylib), 150 coverage-guided inputs per row, import arities from `Tools/userspace/import_arity.py`.
Census: `trace_diff_census_fuzz150.tsv` (this directory).

Result: 1 rows, gate PASS 1 (FAIL 0, REVIEW 0, OUT-OF-CONTRACT 0): 150 IDENTICAL of 150 trials. EFFECTS 0, FAULT_MISMATCH 0, UNINIT_REBUILT 0.

Not covered: the ledger holds 1 of 897 corpus functions (the fnfuzz-eligible ones); the others have no argument model in this census yet.

## Update Nov 16: extended coverage (892 stubs) and the stub check
`FNFUZZ_EMU=1 fnfuzz_gen.py` ledger `ledger_emu_libgl.tsv` (892 candidates), generic census as for the other binaries (150 inputs per row, 133,800 trials, `trace_diff_census_emu_fuzz150.tsv`): gate PASS 892, all trials IDENTICAL, BUT 890 rows never return normally in
either image (the stub loads the current-context cell, which is NULL in the emulator, and faults at `ctx+0xab0` in both), so that census proves equal crash behaviour only. Only `_CGLGetCurrentContext` and `_CGLSetCurrentContext` run through.

`Tools/userspace/emu/libgl_stub_check.py` (result: `libgl_stub_check_result.txt`) makes the stubs informative. A stub is `ctx = *cell; if ((ctx->+0xab0 ^ sp) & ~0xfff) refetch the context; r3 = ctx[0] (args shifted); tail-jump through ctx[slot]`. Per image the
tool finds the cell (the last 4-byte zero read before the fault), points it at a context in the arena whose thread marker matches the stack and whose slots are 1,024 distinct call-out stubs, runs the stub with distinct integer (r3..r10) and double (f1..f13) arguments and compares
the tail-call record (which slot, the argument registers the stock passes on, f1, status, sp). Result: 888 of the 890 stubs tail-call the same slot with the same forwarded argument registers, 682 distinct slots reached; the two others are the CGL functions covered by the generic census.
Rule: a register the stock itself clobbers (e.g. r9 = the result of its `rlwinm.` marker test in `_glAccum`) is not an argument and is ignored; every register the stock forwards must arrive identically. Mismatch control (each stock stub against the NEXT rebuilt stub): 0 of 890 identical, so the check does see slot and argument differences.
NOT covered: the marker-mismatch path (thread context refetch through the in-image function and `pthread_getspecific`), the slots' targets (they are the dispatch table filled at run time), stubs with more than 8 integer arguments (stack-passed arguments are not compared).
