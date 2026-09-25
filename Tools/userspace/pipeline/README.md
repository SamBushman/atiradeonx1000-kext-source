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
5. `gs/OverrideIndirectCalls.java`: every indirect call (`bctrl`: virtual calls, function pointers; 1288 in glprog) gets a call-site signature: an 8-argument
   override, then the arguments up to the last one that carries a value the caller defines (data flow; the caller's own untouched input registers
   are dropped), bounded by the registers actually set up between the previous call and the `bctrl` (a tail `bctr` keeps the data-flow count), never
   fewer than Ghidra printed. Ghidra had printed virtual calls without their object (`(**(code **)(*p + 8))()`) or with 2 of 5 arguments
   (`TType::setType`).
6. `gs/ExtendParams.java`: functions whose own decompile reads an argument register it does not declare (`in_r4`: TIntermAggregate::setName is
   `addi r3,r3,0x54; b assign`, passing the caller's r4 on) get the parameter, when stock callers set that register before the call
   (`Tools/userspace/param_used.py`) or, for functions reached only indirectly (virtual methods), for every register the body reads; PIC stubs
   of the same name are extended too (callers through a stub print with the stub's signature). b3/extend_*.txt: 59 glprog, 31 GLDriver, 1 GA, 1 VA.
7. `gs/WidenParams.java`: parameters typed narrower than their register although the function rebuilds the whole register
   (`CONCAT31(in_register_0000000c, param_1)`): ParseOperand::GetAsSourceVar(bool) had the demangled `bool` on r3, which carries the hidden
   struct-return pointer, and callers passed that stack address cast to bool (44 glprog functions, b3/widen_glprog.txt).
8. Stack parameters (`gs/ExtendParams.java` again, lists b3/stackparams_*.txt): Ghidra's PowerPC cspec is SysV and never gives a function more
   than the eight register arguments by itself; a 9th+ argument word (stored by the caller at 0x38(r1)) was read by the callee as an uninitialised
   local `in_stack_00000038`, and callers dropped the argument. `_glpDisassemble2Op` takes the address of its caller's flag word as argument 9;
   with the argument gone the word looked unaliased, its tests folded to constants ("Removing unreachable block") and the rebuilt
   `_glpPPShaderToProgramString` never printed "TEMP scratch;". The functions come from `Tools/userspace/instack_table.py` (positive offsets),
   the counts and call sites from `Tools/userspace/stack_params.py`; parameters 9+ get explicit Darwin storage (0x38 + 4k - dynamic storage would
   put them at SysV's Stack[0x8]), `nofp` drops invented float parameters first (`_InterpreterLoadSource`: eleven, the body only writes FPRs).
   Iterated to closure (functions that forward their own stack arguments appear once their callee takes them): 14 glprog, 70 GLDriver
   (FUN_00029290 by hand: its committed signature was `(void)`; its callers are orphan code). After it no dump file reads a positive
   `in_stack_` offset except six glprog and two GLDriver clipped fragments that nothing calls. Not changed: negative `in_stack_` reads are
   over-arity arguments (SysV-stacked fparam_9..13 of 57 signatures, `gs/ListStackParams.java`); 56 are never read, FUN_0002bbc4's goes on to
   FUN_00090470, which uses no FPR.
9. GLDriver's two embedded jump tables that Ghidra never resolved ("Jumptable with 0 entries", the C jumped into the stock table as a call):
   `FUN_000d0488` (0xd072c, 32 entries / 9 targets, `param_8 < 0x20`) and `FUN_000d0888` (0xd0aa0, 4 targets) - `gs/FixSwitches.java`, owners
   re-decompiled; their RANGES rows are widened to the case code by step 10. Every other "indirect jump treated as call" in the five dumps is an epilogue tail call through a
   function pointer (`lmw ...; mtctr; bctr`) or an import stub's jump, which the C prints as call + return - equivalent (`Tools/userspace/jumptable_triage.py`).
   The same step fixes FUN_00002ae0, entry 0 of the dispatch table `_gldInitDispatch` hands out - the driver's glAccum(ctx, op, value): the stock reads
   r3, r4 (the op, `switch` 0x100..0x104 = GL_ACCUM..GL_ADD) and f1; Ghidra had `(param_1, double)` and the C switched on an uninitialised `in_r4`.
   ExtendParams now inserts GPR parameters in front of float ones (Darwin gives an int after a double the GPR the double shadows).
10. Switch owners' RANGES: when Ghidra's decompiler recovers a jump table it transcribes the cases, but the listing's function body - what RANGES
   records - stops at the `bctr`, so the case code counted as unowned ("switch-code", raw asm): FUN_00002ae0's five cases were an 11 KB "orphan"
   region (0x2b38-0x5610). `Tools/userspace/switch_ranges.py` follows every embedded table of each owner (the size from the `cmplwi` guard, words read
   from the binary - otool shows a negative offset as an FP instruction and 0x200 as `attn`; a constant-index table `lwz r0,K(base)` reaches only
   entry K/4) and widens 22 GLDriver and 31 glprog rows (b3/ranges_switch_*.tsv). What stays unowned: in glprog 76 blocks behind unused entries of
   constant-index tables (dead in the stock code, emitted as byte-identical asm), elsewhere only alignment `nop`s; unowned_blocks.py now calls a
   table whose words decode as instructions a table. __text accounting: GLDriver function bodies 1626832 -> 1647352 bytes, glprog 629768 -> 639588,
   0 bytes unaccounted. Side finding for #72: 20 orphan extents of unowned_code (14 GLDriver in 0x1efd0.., 0xc5538.., 0x10b3b4..; glprog one in each of the six
   constant-switch owners of step 3) now duplicate case code their owner transcribes, and 11 glprog landing-pad extents run into the next
   function's entry.
11. `TPPStreamCompiler::error` / `::warning` (glprog): r3 is `this`, Ghidra put the demangled `bool` there; the body read `this` as `in_r3` and
   callers passed `SUB41(this,0)`. WidenParams (now matched by namespace-qualified name, so `TParseContext::error` is not touched; PIC stubs by
   their `<EXTERNAL>::` name) on the two functions and the stub, callers re-decompiled (b3/widen2_redump_glprog.txt). Found by
   `Tools/userspace/inreg_liveness.py` (Userspace/README.md, "Undeclared argument registers").
12. Floating-point arguments and results. Darwin's PPC ABI gives every float argument a slot in the GPR sequence too (a double shadows two GPRs)
   and passes f1..f13 in registers; Ghidra's cspec is SysV. `gs/DarwinStorage.java` lists every signature whose storage differs: only GLDriver's
   `_ecvt(double, int, int*, int*)` had an integer in the wrong register (r3/r4/r5 instead of r5/r6/r7), so its caller FUN_000cdc3c (the driver's
   float formatter) passed `param_2` as the decpt/sign pointers and its minus-sign / negative-exponent code was pruned as unreachable; the others
   only move the unread fparam_9..13. FUN_000cdc3c's own value is an undeclared f1 (`in_f1`) that all 17 stock callers load - `gs/AddDoubleParams.java`
   (found by `inreg_liveness.py ... fpr`, which classifies the 19 functions with `in_fN`: that one real, the rest forwarded garbage). The libm
   imports had no signature, so results were read from r3 / an unassigned `extraout_f1`: `gs/SetLibmSignatures.java` gives them their prototypes
   (GLDriver 11, glprog 17, VA 2 functions + stubs) and their callers are re-decompiled; ghidra2c also declares them with their real return type.
   `Tests/userspace/ftoa_test.c` compares FUN_000cdc3c stock vs rebuilt on 20 values: identical (the build before step 12 died with SIGBUS; with only
   the ecvt/f1 fixes every exponent printed as `e00`).
13. Misplaced function entries. gcc sometimes scheduled the first instructions before `mflr r0` - the entry compare (`cmpwi cr7,r4,0`), the CR
   save and a `cmplwi` (`mfcr r2; cmplwi cr7,r3,5`), or `stmw; or. r29,r4,r4` - and auto-analysis started those functions at the `mflr`. The run
   before it became an orphan and the decompile tested an uninitialised `in_cr7` / `in_cr0` or read `unaff_r29`: GLDriver FUN_0010b334 had five of
   its six switch cases pruned, and glprog's `___gxx_personality_v0` and `_glpDCBRealloc` branched on garbage. `Tools/userspace/fallin_entries.py`
   lists entries that the preceding code falls into; the 19 whose decompile reads a register that run sets (17 GLDriver, 2 glprog - the other two
   glprog hits are FUN_97b88a90/97b89f04, patched in patches.py, and a saveFP piece) are re-created at the true entry by `gs/MoveEntries.java`
   (b3/move_entries_*.txt); `Tools/userspace/apply_moves.py` moves their INDEX/RANGES rows and dump files. Afterwards no GLDriver function reads an
   entry-set register, and `Tools/userspace/prune_orphans.py` drops every orphan whose code a function now owns: glprog 8 (the two moved entries
   and the six constant-switch owners' duplicates), GLDriver 31 (the 17 moved entries, FUN_0010b32c's switch cases, and the FUN_0001ecd0 /
   FUN_000c5460 case-code duplicates) - the #72 duplicate list.
14. Call arguments the decompile dropped. `Tools/userspace/callarg_check.py` compares, for every direct call, the constants the stock caller loads
   into r3..r10 with the literal arguments of the decompile's calls to that callee (10112 GLDriver constants). Two classes:
   * imports without a signature print only the arguments the decompiler happens to see: GLDriver called
     `io_connect_method_scalarI_structureI(connect, 0)` where the stock passes six (the scalar array, its count, the struct and its size reached the
     kernel as whatever r5..r8 held). `gs/SetImportSignatures.java` gives ~100 IOKit / libSystem / CoreFoundation / dyld / C++-runtime imports
     their argument counts (GLDriver 132, glprog 80, VA 40, GA 66 functions incl. stubs); libGL's pthread calls were already right.
   * arguments forwarded, untouched, to a call through a pointer: FUN_000e1564(ctx, size) calls ctx->alloc(ctx->allocctx, size) with the caller's
     r4 - all 20 stock callers load the size - but had one parameter, and the call's override (OverrideIndirectCalls: a caller's untouched input
     register is "not set") one argument. `Tools/userspace/hidden_params.py` lists argument registers live at entry beyond the declared parameters
     that stock callers set (57 in GLDriver: 20 are return pass-throughs, 12 reach no reader, 1 is the patched calloc wrapper); the 19 functions
     whose value reaches an indirect call get the parameters and at least that many arguments on their indirect calls (`gs/ForwardArgs.java`,
     b3/forward_args_gld.txt). Extending their direct callees as well (FUN_001054ec's chain into the same allocator callback) was tried and
     dropped: those callees are called from hundreds of sites that never set the registers, and Ghidra printed junk constants for them.
   glprog (hidden_params.py now resolves the unstripped image's `bl _name` calls): `std::string::_Rep::_M_destroy(const allocator&)` had only the
   demangled allocator in r3 - which is `this` - so its real argument r4, loaded by all 4 stock callers and read further down, was dropped; and
   `_M_replace<const char*>` forwards r8 (4/4 callers). Both extended (function and PIC stub; b3/forward_args_glprog.txt). VA's and GLDriver's
   other hits are dyld helpers inside the toolchain ranges, not linked.
   After both: 29 of 10112 GLDriver constants unmatched (was 154) plus 9 printed as the text address they equal (harmless: ghidra2c turns
   `&UNK_00003754` back into 0x3754), glprog 20 of 777 (no call there lost an argument; string literals with commas had been miscounted). The parameters ForwardArgs adds are `uint`:
   as `undefined4` Ghidra printed FUN_000e1564's allocation size 0x1740 as `FUN_00001740` - the rebuilt function's address - at four call sites
   (callarg_check.py reports such SYMBOLIZED-FUNCTION arguments; the dumps were produced with undefined4 and then `gs/RetypeParams.java`
   b3/retype_forwarded_gld.txt). The redumps also inline values Ghidra now reads from `__const` / `__literal` data (glprog 308, GLDriver 5
   declarations fewer): read-only, so equivalent.
   RedumpContaining now raises the decompiler's payload limit (FUN_00115fa0, 3500 lines, failed with "Response buffer size exceeded").
15. Integers and pointers in float-typed variables. Ghidra types a value by its uses, and a storage it shares with floats (a union array, a
   reused stack slot) makes it `float`; the C then converts the VALUE where the stock moves bits:
   * glprog `TIntermConstantUnion::fold` keeps int, float and bool constants in one `float *` array. The rebuilt front end folded
     `ivec4(7,5,17,6) - ivec4(3,1,4,2)` to 0, negation and division to garbage, and reported a divide by zero (the denormal bits of a small
     integer converted to 0) - `Tests/userspace/glsl_intfold2.vert`; the function has no fctiw at all.
   * GLDriver FUN_00180830 kept the object pointers FUN_001043f0 returns in float locals (`fVar7 = (float)FUN_001043f0(..)`, `*(T *)((int)fVar7 +
     0x98)`: 24 bits of mantissa); GA `_radeonSolidScanlines` & co. kept IOConnectMapMemory's address/size out-parameters and command counters in
     float stack locals (`local_1a0 = 2.8026e-45` is the integer 2; `puVar40[(int)local_1a0]` indexed 0).
   Fixes: `gs/SetPointerReturn.java` (FUN_001043f0 returns `void *`), `gs/RetypeLocals.java` on the stack locals `Tools/userspace/float_ints.py`
   finds (denormal literal assigned or `(int)local` used as an address: GA 16, GLDriver 12, glprog 1), and in ghidra2c `fix_float_int`: 32-bit
   PowerPC has no int->float instruction (a real conversion is the 0x43300000 magic sequence, printed as CONCAT44), so `(float)<int expression>`
   is always a bit reinterpretation (GH_U2F), and in a function whose stock code has no fctiw/fctiwz `(int)fVarN` is one too (GH_F2U) -
   `Tools/userspace/cvt_scan.py` counts the functions (GLDriver 175, glprog 50, GA 4, VA 1 without fctiw). 263 casts rewritten. GLDriver
   FUN_0009d410 remains: it compares an address with the bits of 1.0f (the stock does that too); same outcome.
Step 2 was repeated with an exhaustive candidate set - every function whose C returns nothing, checked against every stock call site
(`Tools/userspace/ret_used.py`): `AllocateAtom`, `NewSymbol`, `lNewBlock`, `glpWriteSourceOperand` (214 callers)... (b3/setret_*.txt: 25 glprog, 42
GLDriver, 3 GA, 3 VA; two GLDriver/GA hits are register-save millicode, r3 merely passes through).

## Reproducibility check (GA, from scratch)
A fresh import + FindMoreFuncs + DecompAll + DumpRanges reproduces the archived function set and RANGES exactly; 9 of 82 dump files differ only in
stack-variable naming (`local_28` vs `uStack_28`) - Ghidra's stack analysis is not fully deterministic between sessions. The archived dump is the
authority.
