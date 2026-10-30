# Merging fork branches (GLDriver naming)

Text-level `git merge` fails when forks edit the same functions through rows. Scripts here (originals ran from ~/g5logs; copy them back there or fix the paths):
- `mergeall.sh TAG` - works in the integration worktree ~/wt/int (branch `integ`; forks must never see an unverified main): merges every wt-q0N branch that is ahead (env EXCL="wt-q03" skips one), `fnmerge.py` (function-level 3-way over part files, union func-rename normalisation, conflicting functions keep the side with fewer placeholders), `rowfix.py` (TSV local/use rows of conflicting functions follow the chosen side), apply_names.py, gate vs the pre-merge HEAD, pushes `integ:main` only if the gate verdict is (SPLIT-)EQUIVALENT/IDENTICAL.
- `restorefn.py REV PART ADDR FUN_NAME` - put one function's text and rows back to REV (use when the gate flags a function a fork broke).
- After a merge: grep for conflict markers in non-part files (names_*.tsv, Tools/*.py): the scripts only print them, they do not abort.
- Gate lines other than `, 0 problems` and the VERDICT line must be inspected; a transient empty namemap.tsv gives a false NOT-EQUIVALENT (rerun).
