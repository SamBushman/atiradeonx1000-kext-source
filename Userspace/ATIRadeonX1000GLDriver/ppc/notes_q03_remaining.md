# q03 (parts 010-014): what is left and why (Oct 30-31)

Range count with the wide regex: 419 = 359 Ghidra artifacts (`extraout_*`, `in_*`, `fparam_*`, `forwarded_*`: not variables, never named) + 53 references to unnamed `FUN_` functions
defined in other forks' ranges (FUN_0004fc80, FUN_000b51a0/b5320/b50a0, FUN_0004eba0, ...) + 7 placeholders that were named in the last commit. No real variable of the range is left.

Gate-rejected splits (evidence in ~/g5logs/<tag>.log; all kept as one name):
* `recordProgramBuildDependencies` `dVar29` (two webs, a source-word pointer copy and `((lc_str*)srcWordPtrTable.compat)->offset`): two names => `DATAFLOW _FUN_0007c760 6 loads reached by different stores; first at 1624 lwz r2,192(r30) | lwz r2,196(r30)` (q03_n3, q03_i3..i5). One name `srcWordPtrScratch` => IDENTICAL (q03_n3b).
* `arbValidateProgram` `iVar2` in `iVar2 = alloc(iVar2*0x70+..., iVar2)`: tool puts the stale right-hand uses in the left-hand web => `UNINIT FUN_0008c590 2 -> 3` / DATAFLOW (q03_f3, q03_f4). Fixed by a lhs-only segment (`codeBuffer`, seg.py `1979-1984:first=lhs`) and a `use` row naming the right-hand uses `totalInsts`.
* Whole-variable names only (no split) for fake-struct / address-taken frames: `ffvpBuildProgram` matrixElem0..12, `evsEmitOp879c/d` and `evsEmitMova` destination/source word frames, `FUN_000934f0` (sphere-map duplicate), `arbfpCompileFragmentProgram` keyBlock0..6 (macro aliases onto `local_48_arr`, named through `local` rows, gate IDENTICAL q03_n9).
* Joined misnomers kept honest: staging temporaries are named for the argument register they stage (`scratchArg2/3/5/6/8`, `stageR4`, `stageR9`, `stageR10`, `callResultPair`) because Ghidra reuses them for unrelated call arguments.

Tooling pitfalls found: `rn.py revert-use` leaves duplicate placeholder declarations (compile error `redeclaration`, gate `FAIL cand`): run `dupdecl.py --fix` and `unuseddecl.py --fix` afterwards. A new name that equals a libc symbol or an existing identifier (`index`, `elem`, `component`, `usage`) is refused by apply_names.py with `collides` and leaves earlier rows half-applied: `git checkout` the part and re-apply.
