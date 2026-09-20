# Tools

Kext build and verification (run from the repo root; the G5 is `ssh G5`):

| tool | purpose |
|---|---|
| `remote_build.sh` | copy the tree to the G5, build with Apple gcc 4.0.1, print only failures + the link summary (`OPT=-O0` for the callee comparison) |
| `build_kext.sh`, `link_check.sh`, `kmod_info.c` | the on-G5 build (kext bundle, `kmod_info`) and the link-state check |
| `check_ledger.sh`, `build_ledger.py`, `vtable_map.py` | regenerate `Ledger/` and diff the vtables against the shipped kext |
| `callee_compare.py`, `imm_compare.py`, `size_compare.py`, `arch_compare.py` | fidelity comparisons against the shipped kext (callee multisets, immediates/displacements, size at -O1, PPC vs i386) |
| `replace_fn.py`, `port_fn.py`, `ghidra2cpp.py`, `replace_fn_overrides.tsv` | mechanical port of a method from the archived Ghidra decompile; `restore_old.py` undoes one |
| `audit_cast_types.py`, `autofix_ptrcast.py`, `showerrs.py` | port hygiene: scalar-pointer params aliased as bytes (must print 0 flagged), pointer-store casts, compile errors with source lines |
| `audit_kext_data.py`, `emit_data.py`, `dump_method_tables.py`, `read_mem.py` | data tables: comparison with the shipped kext, extraction, dispatch tables, live single-address kernel reads (safe, targeted only) |
| `const_ptr.py`, `func_relocs.py`, `stub_target.py`, `function_coverage.py`, `decomp_arch_diff.py` | relocation-table helpers (the kext is an MH_OBJECT, so stubs and base-class calls resolve statically) and the method-coverage report |

`userspace/` is the userspace pipeline (Ghidra dump -> C corpus -> verification -> raw blocks -> byte-level accounting); `userspace/pipeline/README.md` is the
ordered recipe and `Userspace/README.md` describes the results.
