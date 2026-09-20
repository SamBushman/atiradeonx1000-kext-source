# Ledger

The completeness ledger for the shipped `ATIRadeonX1000.kext` (PPC slice). Every function in the binary is a row.

- `kext_ppc_ledger.tsv` - address, size, category (`method` / `stub` / `external` / `generated` / `toolchain`), status (`DONE` / `n/a`), name, mangled symbol.
  Regenerate with `sh Tools/check_ledger.sh G5`; expect 0 MISSING (506 methods DONE, 249104 bytes; 404 externals, 1083 stubs, 122 generated).
  `stub` rows are the lazy-binding stubs kxld patches; they resolve to imports and need no body.
- `kext_ppc_vtables.txt` - the vtable layout of every class, compared with the rebuild's by `check_ledger.sh` (0 differing lines; the only differences by
  construction are stock's `___cxa_pure_virtual` slots and the two `system_will_sleep/did_wake` imports stock leaves undefined).
- `kext_ppc_functions.tsv`, `kext_ppc_worklist.tsv` - the raw function list and the historical work list the ledger grew from.
- `data/` - the kext's non-code sections (see its README) and `ghidra/` - the archived Ghidra decompile dump the mechanical ports are generated from
  (`tar -xJf Ledger/ghidra/kext_ppc_decompile_dump.tar.xz` then point `$SCRATCH` at it; `Tools/replace_fn.py` reads `$SCRATCH/work/0xADDR.txt`).
