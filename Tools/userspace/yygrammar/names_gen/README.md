# names_gen - how names_R1b.tsv (yyparse) was generated

`python3 emit.py /names_R1b.tsv` (run in this directory, against the Ghidra-text `part_006.c` BEFORE names_R1b.tsv is applied) rewrites
`Userspace/libGLProgrammability/ppc/names_R1b.tsv`; then `python3 Tools/userspace/apply_names.py Userspace/libGLProgrammability/ppc`.
The scripts hard-code the author's worktree paths (`/home/sam/wt/R1b`, the Tiger libGLProgrammability.dylib under ~/Documents/ATI-X1900-Decomp):
change `ROOT` in yyinfo.py, `PART`, `D` in emit.py and the dylib path in vt.py to reproduce.

* `yyinfo.py` - loads yyparse, builds its webs (Tools/userspace/webs.py), the bison rule table with mid-rule actions numbered as bison numbers them
  (rule(177) = @new_scope ...), `case` regions and "case-pure" lines (no label between the `case N:` line and the line, no stacked case labels).
* `vt.py` - the dylib symbol table: vtable symbols (`__ZTV...`), exact method names per vtable slot (slot k at vptr + 4k), `nl_symbol_ptr`
  imports (`PTR_vtable_a7b7c0f4` = `__ZTV9TFunction` ...).
* `rules1.py`, `pass2.py` - the rules: std::string refcount-release idiom, `$k` value-stack loads named by the rule's right-hand-side symbol,
  virtual-call results named by the receiver's vtable slot (receiver class propagated from getAsX results, allocations, typed `$k` nodes), pool
  allocations named by the vtable class stored into them, bison skeleton variables, PIC base / vtable addresses (0xa7b8374c - 0x610c = TType vtable),
  TParseContext+4 = symbolTable, c_str() data pointers, loop counters, TType bit-field parts.
* A web is named only when EVERY definition agrees with the rule (a web with defs of different roles is left alone).
* `emit.py` - one `use` row per (web, line): anchors are the exact Ghidra text of the line (renames taken back), `@N` = Nth identical line.
