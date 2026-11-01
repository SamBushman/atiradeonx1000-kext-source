# r29: part_012/014/025/040/054 placeholder sweep

Scope: name the remaining Ghidra placeholder variables/parameters in `part_012.c`, `part_054.c`, `part_014.c`, `part_040.c`, `part_025.c`. All five are now fully clean (`apply_names.py --check`: 0 errors, 0 pending; manual sweep for `[a-z]{0,3}Var[0-9]+`, `local_*`, `unaff_*`, `extraout_*`, `in_rN`/`in_stack_*`, `fparam_N`/`param_N`, `*Stack_*`, `iVarS<N>`, bare `FUN_` definitions, `DAT_`/`PTR_`/`LAB_`/`switchD_`: 0 hits outside comments).

## Commits
- `22f8539d` - 69 placeholders, mostly stale-register/forwarded-argument patterns (`in_rN` -> `staleArgN`, `extraout_r4` -> `retR4`), plus 2 float LOD-bias params, a zero-literal broadcast constant, a spill-load base param, and 2 swizzle-byte-overlay locals.
- `70261092` - 6 more (`unaff_r17-22`, a dead `fparam_9`) that `ph.py`'s regex does not catch (comment-text false positive led to a missed first pass).
- `6c492409` - 57 `iVarS<N>` placeholders in `part_014.c`. **`ph.py`'s regex does not recognize the `iVarS<N>` prefix at all** (not in its counter list; distinct from the already-documented `unaff_*`/`in_stack_*` gaps) - these were found only by a manual wide regex sweep after the ph.py-driven pass looked complete. Recommend adding `iVarS[0-9a-fA-F]+` to `ph.py`'s counter regex for future rounds.

## Important false-positive lesson
`ph.py` counts tokens inside **comments**, not just code. Three functions it flagged had zero real placeholders - `ffvpEmitClipPosition`, `ffvpEmitPointSizeAttenuation` (the `local_90`/`uVar5`/`uVar6` ph.py listed), and `ConstRecord__findInTable` - all of whose matches were historical prose inside `/* issue #64 ... */`-style investigation comments describing a *already-fixed* past state, not live identifiers. `ffvpValidateProgram`'s `fparam_9` was also comment-only on the first check but turned out to have a second, real, code-level `fparam_9` the naive per-function body-extraction regex I used missed (fixed in `70261092`). **Lesson for future rounds**: strip `/* ... */` before deciding a hit is real, and don't trust a single regex extraction of "the function body" without double-checking against `grep -n` of the raw file.

## Naming conventions used (for consistency with later rounds)
- `staleArgN` - a stale `in_rN` register forwarded unread/unmodified to a callee (matches the existing `scratchR5..R8` style from r27 and the q07-round README guidance).
- `retR4` / `retR4b` - the `extraout_r4` side-register from a preceding call, forwarded into a later call.
- `passThroughFloatArgN` - an `fparam_N` double forwarded unread through a wrapper (float counterpart of the already-applied `passThroughArg2-7` ints).
- `deadStagedSlot<origNum>` - an `iVarS<N>` declared but never assigned or read anywhere in the function; the `<origNum>` suffix keeps the original Ghidra slot number traceable.
- `deadEmitFn<hexoffset>` / `deadSrc1File` / `deadSrc1Index` / `deadSrc1Select` / `deadSwizzleSelect0Ptr` / `deadTempBRegBase` - an `iVarS<N>` or `unaff_rN` that IS assigned but the value is a dead duplicate of a value already read (and named) a few lines later for the real call; this matches an existing in-file convention (`deadEmitFn12f4`, `deadSrcTempFile`, etc.) from earlier rounds.
- `vtableDispatchFn` (`pass_remove_empty_graphs`'s `in_r9`) - a single Ghidra web that is read once as stale garbage *before* its own real assignment, then used as the actual vtable-dispatched callee; `find_webs`/`lw2.py` report this as one web (not two), so it got one joined name per the project's "registers reused for unrelated roles get one joined name" rule, same class as the ILReader__nextInstruction/FUN_000fb3d4 hybrids from earlier rounds.
- `matrixElem13/14/15` (`ffvpBuildProgram`'s `unaff_r17/18/19`) - row-4 elements of a 4x4 identity-matrix check, extending the function's own existing `matrixElem0/5/6/7/8/9/10/11/12` series.

No accepted-hybrid/unsplittable cases in this round - every placeholder resolved to a clean single-web rename (whole-variable `local` rows only; no splits were needed).

## Gate evidence
All three gated batches: `VERDICT: IDENTICAL` (pure whole-variable renames, byte-identical as expected). The `part_*: Traceback ... FileNotFoundError` line gate.sh prints after `IDENTICAL` is benign - it is only the per-part split-equivalence loop finding no `.dis` files to iterate when there is nothing to split-compare.
