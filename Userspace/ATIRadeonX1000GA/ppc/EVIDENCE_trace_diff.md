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

## Update Nov 17: ENTRYARGS + heap/repair census, defect #302, image ga_i302
Mode: `TD_ENTRYARGS=1 TD_HEAP=1 TD_REPAIR=12 TD_ARITY_FILE=arity_ga.tsv` (`controls/arity_gen.py` on this corpus), the same 35-row ledger, 150 coverage-guided inputs per row. `TD_HEAP=1 TD_REPAIR=12` lets the inputs reach deeper paths (each pointer argument gets a repaired, valid object; 12 retries after a fault in the stock):
`_radeonCopyRegionBody` goes from 17 to 138 RET/RET trials, which is how the defect below was reached. The first run on the image of 17d835a2^ (`ga_rebuilt`, corpus unchanged since Nov 12) gave gate FAIL 1, PASS 34.

### Defect found: #302 (fixed)
`_radeonCopyRegionBody` region quad: the four texture-coordinate words are read back through `scratchWord0Ptr..scratchWord3Ptr` before the stores that fill the slots (Ghidra sank the stores below the reads; stock spills at 0x6e5c..0x6e68 before the quad words). Row verdict UNINIT_REBUILT (23 trials): the rebuilt differs between the two stack fills at the first read, stock stores 0, rebuilt the fill word (`0x5a5a5a5a`); the words are command-stream data. Fix: the four assignments moved before the reads (`part_001.c`, commit 17d835a2). Image `ga_i302` (G5 `~/rung3/ga_i302`): same row, same inputs: UNINIT_REBUILT 0, REORDERED. Issue #302.
(Tried and dropped: a textual order scan for `*P` before the first `V =` for address-taken locals; it cannot see per-block order, the earlier quad blocks of the function assign the same locals first, so it did not flag the original defect. The dynamic UNINIT detector under heap/repair inputs is the detector; it is being run over the other corpora.)

### Result on the fixed image (`trace_diff_census_ea_heap_fuzz150.tsv`)
35 rows, 10,068 trials (47 excluded as layout-dependent): gate PASS 35, FAIL 0, REVIEW 0, NO-INFO 0, UNINIT 0. REORDERED 19, IDENTICAL 12, FAULT_SITE 4. 33 rows have runs where both images returned normally; 2 rows fault in every run. Not covered: the 45 corpus functions outside the ledger (unchanged).
