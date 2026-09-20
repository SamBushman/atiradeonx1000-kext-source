# Reproducing the userspace corpora

Inputs (not in this repo - vendor binaries): `ATI-X1900-Decomp/tiger-hd-pull/*` (GA.plugin, VADriver.bundle, GLDriver.bundle, libGL.dylib,
libGLProgrammability.dylib, ATIRadeonX1000.kext). Ghidra 12.1.3, Apple gcc 4.0.1 on the Tiger G5 (`ssh G5`).

Archived so the corpora can be rebuilt without redoing the decompiles: `Userspace/<bin>/ppc/ghidra/decompile_dump.tar.xz` (main dump `n_*` with
`INDEX.tsv`/`RANGES.tsv`, landing-pad dump `p_*`, orphan dump `o_*`) and `Ledger/ghidra/kext_ppc_decompile_dump.tar.xz` (kext).

## Stage A - corpora from the archived dump (no Ghidra needed)
    tar -xJf Userspace/<bin>/ppc/ghidra/decompile_dump.tar.xz -C $SCRATCH         # -> $SCRATCH/n_<x>, p_<x>, o_<x>
    python3 Tools/userspace/pipeline/extract_slices.py <vendor binary> /tmp/spec/slices
    python3 Tools/userspace/build_corpus.py <slice> ppc $SCRATCH/n_<x> Userspace/<bin>/ppc     # C corpus + compile check on the G5
    LOOSE_NAMES=1(C++ only) EXTRA=Userspace/<bin>/ppc/extra_decls.h sh Tools/userspace/verify_corpus.sh <name> <slice> $SCRATCH/n_<x>
`run_corpora_and_verify.sh`, `run_landing_pads.sh`, `run_unowned_code.sh` are the exact drivers used (paths are the author's; edit SCR/TG).
Then `raw_blocks.py` -> `raw_emit.py` (data/asm blocks, byte-verified) -> `text_complete.py` (accounting) -> `unowned_blocks.py`.

## Stage B - the Ghidra dumps (what was archived)
1. import the ppc slice into a project and analyse (`analyzeHeadless <proj> <name> -import <slice>`), then `-postScript FindMoreFuncs.java`
   (functions for code a `bl` reaches that auto-analysis missed). `import_rest.sh`/`decomp_rest.sh`/`redump.sh` are the original drivers.
2. `DecompAll.java <out>` and `DumpRanges.java <out>/RANGES.tsv` (`-process -noanalysis -readOnly`).
3. libGLProgrammability and GLDriver only: `FixSwitches.java <addresses>` writes JumpTable overrides for Darwin embedded switch tables Ghidra could
   not recover (`failed_switches.json` = the site lists: dump warning sites that coincide with a `bctr` followed by table words), then
   `RedumpContaining.java <out> <addresses>` re-decompiles the affected functions, then `DumpRanges.java` again. `_ShCompile` additionally needs
   `PatchConstSwitch.java 0x97ba14bc 0x97ba15e0 0x97ba17ac 0x97ba1854` (it removes the function's overrides first - an override under a patched
   instruction kills the decompiler) and a re-dump; its RANGES row was widened by hand to include the four blocks.
4. landing pads / orphan code: `CreatePads.java pads_<x>.tsv <out>` and `CreateOrphans.java orph_<x>.tsv <out>` (the tsv files are here). CreatePads
   marks `_Unwind_Resume` noreturn, which shrinks owner function bodies in the project: keep the pre-pad RANGES for comparisons and
   `RemovePads.java` afterwards.

## Reproducibility check (GA, from scratch)
A fresh import + FindMoreFuncs + DecompAll + DumpRanges reproduces the archived function set and RANGES exactly; 9 of 82 dump files differ only in
stack-variable naming (`local_28` vs `uStack_28`) - Ghidra's stack analysis is not fully deterministic between sessions. The archived dump is the
authority.
