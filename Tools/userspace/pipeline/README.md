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

## Stage B2 - call-accurate dumps (issue #61, second pass)
The archived dumps are made from a COPY of the project with these steps (scripts: `regen_glprog.sh`, `regen_glprog_companions.sh`, `regen_gld.sh`,
`regen_gld_companions.sh`, `regen_32bit_signatures.sh`; `filter_dump.py` restricts a fresh dump to the archived function set; `repo_regen.sh` rebuilds a
repo corpus + verification + archive). They fix defects that made the decompile print calls wrongly (see `Userspace/README.md`, "Call-argument accuracy"):
1. `gs/NopMillicode.java LO HI` - `bl` into the register-save millicode (stfd f14..f31 chain) becomes a `nop` in the analysed copy (the decompiler models it as a
   call that clobbers r3..r10).
2. `gs/CommitLiveSigs.java [OLD_DUMP] ` then `gs/CommitLiveSigs.java EXTEND` - machine-code liveness (registers read before written, closed over calls and
   tail jumps) gives each function's argument registers and return register; EXTEND keeps Ghidra's typed signature and only appends what it lacks.
3. `gs/RemoveExtras.java DUMP_DIR...` - back to the function set of the archived dump (the project also holds the landing-pad/orphan functions and their
   disassembly, which change how main functions print).
4. `gs/UniqueNames.java` (C++: colliding demangled names -> mangled symbol), `gs/ThisToStdcall.java` (`this` explicit), `gs/CopySigToStubs.java` (PIC stubs of
   in-image functions get the real function's signature; matched by mangled name).
5. `DecompAll.java` (retries a function that exceeds the default limits with 256 MB payload / 1800 s: GLDriver `FUN_00115fa0`), `DumpRanges.java`; refresh the
   thunk names of `RANGES.tsv` from the new dump.
Checks: `Tools/userspace/detect_dropped_args.py`, `detect_short_calls.py`, `check_import_binding.py`, callee compare **without** `LOOSE_NAMES` for C++ (the
variable is tested for presence: `LOOSE_NAMES=0` still means loose).

## Stage B3 - targeted re-decompiles (issues #67-#72, 2026-09-25)
`regen_b3.sh OUT` (address lists in `b3/`) works on copies of the B2 projects and re-decompiles only the functions it changes; their files replace
the ones in the archived `n_<x>` dumps. Each step fixes a defect class the GLSL differential test or a link check exposed:
1. `gs/PatchConstSwitch.java` on the seven constant-index switches of the glprog parse helpers (`TParseContext::error`, `ParseBinary` x2,
   `ParseUnary`, `ParseSelection`, `ParseLoop`, `ParseBranch`: an inlined `TInfoSink::prefix(EPrefixError)` compiled to `lwz r0,K(table); add; mtctr; bctr`).
   Ghidra had printed a call through the stock table address (the live case body was never transcribed); the listed `bctr`s become `b target`, the seven
   RANGES rows are widened to the flow-reachable code (`Tools/userspace/flow_ranges.py`, `b3/ranges_widened_glprog.tsv`).
2. `gs/SetValueReturn.java`: functions whose own decompile printed `void` although the stock leaves the result in r3 and callers read it
   (`std::string::_Rep::_S_create` returned the new rep; the C returned whatever r3 held). Candidates = void-printed functions whose callers use the
   value in the C, kept when a stock call site reads r3 after the `bl` (`Tools/userspace/ret_used.py`; gcc never reads r3 after a void call) or the
   function's epilogue sets r3: 13 glprog, 25 GLDriver, 1 GA.
3. `gs/OverrideVariadicCalls.java`: printf-family calls with a literal format get a call-site signature override with exactly the arguments the
   format consumes (46 glprog `sprintf(buf, "%d:%d", line)` calls had lost the column register).
4. `gs/FlattenStructParams.java`: by-value iterator/tag parameters (`__normal_iterator`, the 1-byte `forward_iterator_tag` whose storage was
   UNASSIGNED) become `undefined4` in their argument slot, for all 148 glprog functions that have them (`gs/ListStructParams.java`). Those types made the
   decompiler misattribute call arguments ("WARNING: Heritage AFTER dead removal", 42 glprog functions; `std::string(const char*)` passed
   `strlen(s)` as the string). After it, no dump file carries that warning, and six hand patches of `patches.py` were retired as superseded.

## Reproducibility check (GA, from scratch)
A fresh import + FindMoreFuncs + DecompAll + DumpRanges reproduces the archived function set and RANGES exactly; 9 of 82 dump files differ only in
stack-variable naming (`local_28` vs `uStack_28`) - Ghidra's stack analysis is not fully deterministic between sessions. The archived dump is the
authority.
