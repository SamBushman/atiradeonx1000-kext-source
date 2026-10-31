# r05 leftover sweep (step 4)

Wide regex of the Oct 24 handoff over the C parts (`part_*.c`, ghidra/ excluded), then the address-keyed labels.

## (a) kext Sources/ comments
68 distinct `FUN_/DAT_` addresses (90 uses) are cited in `Sources/*.cpp` comments. All 60 `FUN_` ones are still `FUN_` in `Ledger/kext_ppc_functions.tsv`, i.e. the functions have no name yet, so no comment is stale. The 8 `DAT_` citations are raw stock data addresses on purpose. Nothing changed in Sources/ (no difftest needed).

## (b) Userspace variable placeholders (wide regex, named functions)
libGL 0, GA 0, VA 0, libGLProgrammability 0 (`ph.py`). The only placeholders left are in libGLProgrammability `unowned_code/part_000.c` (30 orphan code fragments, 579 uses: `piVar3`, `iVar4`, `in_RESERVE`... overlapping tails of real functions, no owning function) and `landing_pads/part_000.c` (38 EH pads, 132 uses: `param_1` is the `_Unwind_Exception *`, `param_2` the selector compared with -1). Neither is a function the decompile names; left.

## (c) Address-keyed labels (named this round)
| binary | LAB_/switchD_ before -> after | DAT_/PTR_<addr> before -> after |
|---|---|---|
| GA | 27 -> 0 | 15 -> 0 |
| VA | 32 -> 0 | 56 -> 2 (DAT_0000f1a4/f1a8: copies of ctx+0x57c/0x578, role unclear) |
| libGLProgrammability | 1,147 -> 21 labels (50 uses) | 328 -> 316 DAT_ |
| libGL | 0 | 0 |
Label names come from `Tools/userspace/lpnames/gen_label_rows.py` (same scheme as GLDriver names_r03_labels.tsv; r03's own generator was never saved). The 21 libGLProgrammability labels left sit before `}`/`do {`/`goto`.

## Still address-keyed, on purpose
* `PTR_<symbol>_<addr>` (libGL 3 names / 2,665 uses, libGLProgrammability 94 / 706, VA 35, GA 7): non-lazy pointer slots whose name already is the imported symbol (`PTR__gll_cc_a2f27020`); the address only keeps slots apart. Not placeholders.
* libGLProgrammability 316 `DAT_`: mostly C++ library/yacc data (std::string rep pointers, vtable and typeinfo pointers, parser tables) and bss counters; roles need each table's record layout (see GLDriver notes_r04_data_remaining.md).
