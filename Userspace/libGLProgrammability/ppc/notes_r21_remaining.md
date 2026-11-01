# r21: class A (lwarx/stwcx. pseudo-call) in VA, libGLProgrammability, GLDriver leftovers

Continues r17 (`Userspace/ATIRadeonX1000GLDriver/ppc/notes_r17_remaining.md`, flaw class A). Same defect, same fix: Ghidra shows
`lwarx rD,0,rP; add/addi rT,rD,K; stwcx. rT,0,rP; bne- retry` as `do { [old = *P;] if (reservation != 0) { x = storeWordConditionalIndexed(old + K,0,P); *P = x; cr = 2; } } while (!(cr >> 1 & 1));`
-- a call to a symbol that exists nowhere (the object calls an undefined `_storeWordConditionalIndexed` stub) and an uninitialised `reservation` flag.
Each loop is now `[old = ]atomicAddWord(P,K);` (macro in `ghidra_c.h`: inline lwarx/add/stwcx./bne-, yields the old word = the lwarx result).

## What changed
- `Tools/userspace/atomic_add_fix.py` (new): parses every loop shape (pointer form, `*P + K` form, separate `NEW = OLD + K` form, absolute-address global form, the loop-less `if (res) { G = store(G + K,0,ADDR); }` form), converts it, drops the declarations that only the removed construct used (reservation, cr bits, atomicStore/newRefCount results). 294 sites converted, 0 unparsed: VA 2 (`ava_acquire_image`), libGLProgrammability 292 (137 functions incl. 22 `unowned_code` fragments).
- `ghidra_c.h` (Tools/userspace master + VA + libGLProgrammability + its `unowned_code/` and `landing_pads/` copies): `atomicAddWord` macro added. `extern int storeWordConditionalIndexed();` removed from the four `decls.h` (GLDriver too: nothing references it any more).
- `Tools/userspace/retire_stale_rows.py` (new): retires the `names_*.tsv` rows that `apply_names --check` flags as stale, ONLY for the rewritten functions (aborts on any other function). Retired: libGLProgrammability 951, VA 2, GLDriver 2. Every removed row is in `notes_r21_removed_rows_{lgp,va,gld}.txt` (file name starts with `notes` because apply_names scans other .txt/.tsv files for old names).
- GLDriver leftovers r17 flagged: `loopExitFlagWord` (`gld_readPixelsViaBlit`) and `scratchFlag35` (`gld_drawPixelsFromClientSurface`) were only the Ghidra rendering of cr0 (`(unitIndex == 0) << 1`) feeding the outer `bne` of the unit loop (the loop condition `unitIndex != 0` already carries the test); after r17 nothing read them, stock keeps the result in CR only. Dead stores and declarations removed, their two rows retired. Observable behaviour is unchanged (no store, call, argument or return is touched).

## Evidence against STOCK
Stock `__text` and all other code sections scanned for `lwarx` (raw words, big-endian, then Capstone for the context): GLDriver 47 (r17), VA 2, libGLProgrammability 253 (232 in `__text`, 21 in `__textcoal_nt`).
- Shape: each is `lwarx / addi|add / stwcx. / bne <back to lwarx>`.
- Delta: for every corpus function the multiset of `K` in `atomicAddWord(..,K)` equals the multiset of stock `addi rT,rD,K` immediates of the stock function with the same start address (VA 1/1, libGLProgrammability 121/135 exactly). The 14 that do not compare by function start are duplicated decompilations of code the stock has once, all with matching K: the 6 `*__errorReportTail`/`error__tail` stubs (12-byte entries whose body repeats the shared tail, K=-1, same as the `prefix*Entry` fragments that DO match by range), `TFunction C1/C2`, `TGenericLinker C1/C2`, `TPPStreamCompiler C1/C2` and `__ZNSsC1ERKSs` (4-byte alias entries repeating the C4/real body: same K list as the matching C4/real function), and `TPPStreamCompiler C4` whose stock delta is register `r27` (`li r27,1` at 0x97bc970c; corpus K=[1,1]).
- Corpus sites 292 vs stock 253 in libGLProgrammability: the 39 extra are these duplicate decompilations (they were already present as duplicate `storeWordConditionalIndexed` calls before).
- Compiled on the G5 (Tiger): candidate `lwarx` count = `stwcx.` count = 292 (libGLProgrammability) / 2 (VA); the base had 0 `lwarx` and 292 / 2 `bl L_storeWordConditionalIndexed$stub` calls; the candidate has none. `-Wuninitialized` warnings (compiled -O1): libGLProgrammability 1111 -> 899, VA 17 -> 15, GLDriver 48 -> 48.

## Gate
Tier 1 (`gate.sh`, base aaec42e4) prints NOT-EQUIVALENT for all three binaries as expected: the old code called a stub, the new code is inline, label numbers shift after a changed function. Full per-function check instead (all `base.*.dis` / `cand.*.dis` of the parts whose object differs, local labels normalised, stub/non-lazy tail compared separately): 
- VA: 88 functions compared, 1 differs (`ava_acquire_image`, the rewritten one).
- GLDriver: 82 compared, 2 differ (`gld_readPixelsViaBlit`, `gld_drawPixelsFromClientSurface`, the two dead-flag removals).
- libGLProgrammability: 1,894 compared (incl. `unowned_code`), 135 differ, **0** outside the rewritten set (a `.non_lazy_symbol_pointer` directive moves in `part_024` because the removed stub changes the stub grouping; no new symbol, no content difference). The tails of the 19 changed parts differ only by the removed `_storeWordConditionalIndexed` stub block.
Objects of every other part are byte-identical.
`apply_names --check` (each touched binary): 0 errors (libGLProgrammability 31,246 applied, VA 1,290, GLDriver 106,142 at the time).
`datacheck.sh` (base aaec42e4): DATA-DIFFERENT only in `decls.h`, `ghidra_c.h`, `part_*.c` (edited sources) and, for libGLProgrammability, `data.s`: the two alias labels `SYM_a7b7bf8c` / `SYM_a7b7c00c` disappear. They were generated for the absolute address literals inside the old pseudo-calls (`..., 0xa7b7bf8c)`, `..., 0xa7b7c00c)`); the same addresses carry the named labels `emptyStringRepRefcount_a7b7bf8c` and `__default_alloc_template_true_0____S_force_new` (referenced by the new `&name` operand), and `symbol_map.tsv`/the exports are identical.

## Still open
- The Ghidra `cr0` pseudo-assignments (`cr0Reg = (x == 0) << 1;` etc.) are still in many functions as dead stores (e.g. `TIntermediate__growAggregate`, `__addConversion`); they are not part of class A and were not touched except for the two r17 flagged.
- `Tools/userspace/lpnames/tmp0nwoprsz/` is a stray tracked temp directory from an old gate run that still contains the old `storeWordConditionalIndexed` text; not touched.
