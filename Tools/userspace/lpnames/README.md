# lpnames: helpers used for the libGLProgrammability naming round (lpE)

Run from the repo root. All of them work on `Userspace/<Bin>/ppc` and need the compile gate (`Tools/userspace/verify_names.sh`, G5).

* `orig.py DIR FN [from to]` - print FN with every table rename taken back (Ghidra text), with current-file line numbers.
* `lw2.py DIR FN` - placeholder variables of FN with their def-use webs (`Tools/userspace/find_webs.py`); each web is PLAIN (Ghidra name still there) or ALIAS (a previous row already named it).
* `wf2.py DIR SPEC OUT` - workflow 2: `ren FN old new ev` renames the new-name of an existing row (table + part file; safe for the gate), `web VAR WEBS new tier ev` goes through `emit_webs.py` (only for PLAIN webs). `fn FN` sets the function.
* `rn.py DIR ren|revert|revert-use ...` - change/undo rows together with the part-file text. NOTE revert-use must not touch `return NAME;` lines (fixed).
* `prep.py`, `reset_fn.py` - undo all rows of some variables / reset a function to HEAD (text + rows).
* `chk.py DIR PART` - compare each function's Ghidra-normalised statements with HEAD (catches lost lines such as `return x;` or `goto`).
* `dupdecl.py FILE... [--fix]` - duplicate declarations in a function's declaration block.
* `fixspec.py`, `mk2.py` - spec helpers (HEAD-group aware web names; local rows that turn into `ren` when a row already exists).
* `mkrows.py DIR SPEC` - `FN|old|new|evidence[|TIER]` lines (FN may be a glob) -> whole-function `local` rows; use it only for variables that really have one role.
* `ph.py DIR [FN-glob]` - placeholders left per function (incl. the `pXVar` / `p_VarN` type-derived names); `fshow.py DIR FN...` - current text of functions with the part-file line numbers `rng.py` wants.
* `anchorfix.py DIR FN...` - turns the machine-written `#L` line anchors of FN's `use` rows into regex anchors; run it BEFORE adding rows that declare new names in FN (see pitfalls).
* `gate.sh TAG [BASE]` - full gate with the UNTRUNCATED problem list (verify_names.sh prints only the last 8 lines of split_equiv, which hid MERGE problems).

Pitfalls found (all gate-visible): a new name spanning webs that a HEAD alias keeps apart (x = f(x) lines are lhs/rhs-split in HEAD rows) is a MERGE; `#N` anchors count from the end of the DECL-matching declaration prefix, so a `T * x;` declaration inserted at the top (apply_names.py now writes `T *x;`) shifts them.

Pitfalls found in the lpK round (all gate- or check-visible):
* `#L` anchors count from the end of the declaration block, so every new `T x;` a split adds shifts them: the first apply passes, the NEXT `apply_names.py --check` fails. Run `anchorfix.py` on the function first.
* Never rename a name an earlier row produced with a new `local` row (chain): use `rn.py ren FN OLD NEW` (edits the row and the text). `rn.py ren` on a Ghidra-original name (e.g. `p0`, `this_00`) changes the text without any row - revert it and add a normal row.
* `rng.py` line numbers are part-file lines of the tree it runs in: generate the rows in the tree the rows will be applied to (a merge that adds declarations above shifts every line).
* A split that leaves one use on the old name shows as DATAFLOW / UNINIT: list every line of the variable (`grep -n`) before writing ranges (multi-line `for (...)` headers, `x = f(x)` lines, the malloc after a length computation).
* Fake-struct locals (`local_50[2]`, `local_48`, `local_40[2]` in `TGenericLinker__BuildSymbolTableList`) are addressed relative to each other (`(int)local_40 + i*4 - 8`): the number of 4-byte declarations a split adds changes their relative distance (MERGE of A-slots). Keep the added declaration count even, or leave the function's split count where the gate passes.
* `find_webs` refuses functions with `do ... while( true )` / goto spaghetti ("do without while"); use `rng.py` ranges there.

Pitfalls found in the lpL round:
* `ph.py` now also counts `fparam_N` (FPR parameters), `in_stack_*` (stack argument slots) and `FUN_xxxx` calls/definitions: the older counters (`[a-z]{0,3}Var..|local_..|param_..|in_[a-z0-9]+`) missed all of them because `\b` does not match inside `fparam_1` / `in_stack_ffffff48`, and ignored the capitalised `pTVar` prefix.
* A split that adds or removes declarations shifts the `#N` line anchors of OTHER tables' rows for the same function (names_L2_roles.tsv `OutputBinary`); the first apply passes and the next `--check` errors with "neither X nor Y in the segment". Convert the row's anchor to a regex over the Ghidra line (`orig.py` prints it).
* An FPR scratch (`fparam_N` assigned in several `switch` cases of `_InterpreterEmulateOp` and also forwarded as a stale argument to the texture sampler) is ONE web: it cannot be split; name it after the register (`scratchF2`) and list the roles in the evidence.
* Gate base must be the last GATED commit; a gate of a committed tree against HEAD compares the tree with itself and reports IDENTICAL.
