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
* `gate.sh TAG` - full gate with the UNTRUNCATED problem list (verify_names.sh prints only the last 8 lines of split_equiv, which hid MERGE problems).

Pitfalls found (all gate-visible): a new name spanning webs that a HEAD alias keeps apart (x = f(x) lines are lhs/rhs-split in HEAD rows) is a MERGE; `#N` anchors count from the end of the DECL-matching declaration prefix, so a `T * x;` declaration inserted at the top (apply_names.py now writes `T *x;`) shifts them.
