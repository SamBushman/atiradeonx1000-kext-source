# names_gen_D6 - how the names_D6_*.tsv tables of libGLProgrammability were produced

Scratch generators of fork D6 (round 3), kept for reproducibility; they hard-code the author's worktree (`~/wt/D6`) and scratch dir (`~/g5logs/D6`), and read the Ghidra-text
corpus that existed BEFORE the D6 tables (`/tmp/d6pristine/ppc` = a copy of `Userspace/libGLProgrammability/ppc` at main 3d61e2e). Change the paths to reproduce.
The tables themselves (`Userspace/libGLProgrammability/ppc/names_D6_*.tsv`) are the record.

| generator | table | what it names |
|---|---|---|
| `gen_pat.py` (+ spec rows) | `names_D6_refcount.tsv`, `names_D6_ib.tsv`, `names_D6_cls.tsv`, `names_D6_std.tsv` | webs whose every definition matches a regex; a spec row is `FUNCTION VAR NEW TIER EVIDENCE DEFREGEX[&&USE:regex]` (`*` = every function / every variable) |
| `spec/*.tsv` + `emit.sh` (find_webs.py --emit) | `names_D6_execinit.tsv`, `names_D6_arrayerr.tsv` | hand-written per-web names of `TParseContext::executeInitializer` and `arrayErrorCheck`; web numbers are of the pristine text (`wd.py FUNCTION` lists them) |
| `gen_stacktype.py` | `names_D6_stacktype.tsv` | the ten words of a stack-allocated TType (vtable store at the first word); overlapping objects get `...Or...` names |
| `gen_oprec.py` | `names_D6_oprec.tsv` | the 14 words of a `_PPStreamOperation` record passed to `_PPStreamAddOperation` / `TPPStreamCompiler::AddOperation` |
| `gen_pair.py` | `names_D6_pair.tsv` | two-word operand descriptors returned through a hidden pointer |
| `gen_symblock.py` | `names_D6_symblock.tsv` | the stack frame of the inlined `symbolTable.insert(TVariable)` block relative to its stack TType |
| `gen_art.py` | `names_D6_art.tsv` | Ghidra register-model artifacts: `in_RESERVE`, `in_cr0`, the CR0 byte |
| `vtmap.py`, `gen_cls.py` | `names_D6_cls.tsv` | `this` field loads named by accessors, `this` virtual calls named by the `__ZTV` slot method names |
| `gen_std.py`, `gen_strparams.py` | `names_D6_std.tsv`, `names_D6_strparams.tsv` | libstdc++ 4.0 `std::vector` / COW `std::string` members |
| `mk_unwind.py`, `mk_unwind2.py` | `names_D6_unwind.tsv` | the statically linked libgcc DWARF2 unwinder, named from the GCC 4.0 sources |
| `gen_roles.py`, `typeprop.py` | (not merged) | callee-named webs with `new`/`create`/`find` rules; class typing of parameters by call arguments (14 candidates, all already named) |
