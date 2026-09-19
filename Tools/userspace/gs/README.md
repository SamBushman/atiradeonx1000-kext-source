Ghidra 12.1.3 headless scripts behind the userspace corpora (run with `analyzeHeadless <proj dir> <proj> -process -noanalysis -scriptPath Tools/userspace/gs -postScript X.java args`):

* `FindMoreFuncs.java` - create functions for code a `bl` reaches that auto-analysis missed (the full-discovery pass)
* `DecompAll.java OUT [lo hi]` - decompile every function to `OUT/0x<entry>.txt` + `INDEX.tsv` (the corpus input); `DumpRanges.java` writes `RANGES.tsv`
* `FixSwitches.java <bctr addrs>` - JumpTable overrides for Darwin embedded switch tables Ghidra could not recover; `RedumpContaining.java OUT addrs`
  re-decompiles the functions containing them
* `PatchConstSwitch.java` / `PatchTest.java` / `RestoreBctr.java` - experiment for `_ShCompile` (rewriting the constant-selector `bctr` as `b`
  crashes Ghidra's decompiler on that function; the project was restored - do not apply)
