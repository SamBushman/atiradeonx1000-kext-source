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

| `userspace/link_corpus.py`, `userspace/rewrites.py`, `userspace/machoutil.py`, `userspace/fix_gl_stubs.py`, `userspace/check_gl_stub_indices.py`, `userspace/link_config/*.json`, `userspace/gs/DumpData.java`, `userspace/pipeline/regen_32bit.sh` | userspace linking (issue #61): see `Userspace/README.md`, "Linking" |
| `userspace/check_symbol_map.py` | checks a link build's data symbol map against the assembled data object |

### Userspace call-accuracy tools (issue #61, second pass)
`userspace/detect_dropped_args.py` (calls printed without arguments), `userspace/detect_short_calls.py` (fewer arguments than parameters), `userspace/check_import_binding.py`
(per-function import calls by mangled name, stock vs rebuilt image), `userspace/gs/{NopMillicode,CommitLiveSigs,RemoveExtras,UniqueNames,ThisToStdcall,CopySigToStubs}.java`
and the drivers in `userspace/pipeline/` (Stage B2 of its README).

### Static fidelity checks added 2026-10-01 (#85/#86, run against `otool -arch ppc -tV` of the shipped and rebuilt kext)
| tool | finds |
|---|---|
| `this_register_check.py` (+ `this_register_allow.txt`) | an argument register dereferenced as another (first real argument used as `this`) - run by `check_ledger.sh` |
| `alloc_size_compare.py`, `gen_layout_checks.py` -> `Sources/LayoutChecks.cpp` | wrong object sizes / member offsets (compile-time checks) |
| `uninit_local_scan.py` | split stack objects: locals read but never assigned (gcc deletes the branches) |
| `arg_setup_compare.py` | small methods: which r3..r10 are written before the first call (finds implicit-r4 forwarding / dropped-result defects; 19 residual hits as of 0ccb392 are codegen noise, e.g. `lwbrx` vs byte loads) |
| `return_code_audit.py` | #100 criterion 2: shipped IOReturn codes per external method vs codes observed live on stock in the baselines; unjustified gaps listed |
| `callee_compare.py`, `size_compare.py`, `imm_compare.py` (use the RAW `otool -tv` dump for real displacements) | missing calls / code / field accesses; classified in `Tests/body_triage.tsv` by `body_triage.py` |
| `decomp_vs_source.py` | hex constants of a fresh Ghidra decompile absent from the C++ body (omitted statements) |
| `call_arg_origin_compare.py` | shifted / swapped call arguments (found the `alloc_surfaces_retry` bug: `this` passed as the mask). NOISY - register reuse makes many hits benign; read each against the disassembly |
| `call_args_compare.py`, `result_use_compare.py` | literal-argument tuples and dropped call results (both noisy; low yield) |
| `DecompList.java` | headless-Ghidra batch decompile of a list of addresses into `$SCRATCH/work/0xADDR.txt` (for `replace_fn.py`) |

### Opcode usage recorder (#42, 2026-10-02)
| tool | purpose |
|---|---|
| `opcode_inventory.py` -> `Tests/pm4_opcode_inventory.md` | opcodes the stock `process_command_buffer` of each context compares against (Capstone over the stock kext; GL 66, DVD 62, 2D 17) |
| `userspace/opcode_recorder.c` (+ `userspace/run_opcode_workloads.sh`) | `DYLD_INSERT_LIBRARIES` interposer: tallies the opcodes in the command buffers a process submits (flush-map = submit); passive, fault-safe, periodic TOTAL snapshots |
| `opcode_usage.py` -> `Tests/pm4_opcode_usage.md` | merges recorder logs per workload and compares with the inventory (coverage, observed-not-in-inventory, never-observed, anomalies); raw logs in `Tests/baseline/opcode/` |
