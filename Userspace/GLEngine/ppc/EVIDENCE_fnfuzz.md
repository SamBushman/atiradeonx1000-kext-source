# GLEngine corpus - fnfuzz / ctxfuzz differential: evidence for the cleared DIFFs

Image under test: `gleng_link/GLEngine_rebuilt` built from commit a3a6228a (`sh Tools/userspace/build_gleng_image.sh`), against Apple's Tiger 10.4.11 GLEngine
(md5 02f4a2854a95be1f2853baeb99ae22b3), both loaded in the same process on the G5. Harnesses: `Tests/userspace/fnfuzz.c` (pure functions, 2673 candidates, 12 trials each),
`Tests/userspace/ctxfuzz.c` (hand-built context with recording stubs for indirect calls, 595 candidates, 24 trials each), mock tests (`gleng_mock_*.c`, valid contexts).
Ledgers are regenerated per image (`fnfuzz_gen.py`, `FNFUZZ_RZ_STORED=1`, ctx ledger with `FNFUZZ_CTX=1`). Logs: `~/g5logs/gleng-fnfuzz/run16_*.log` on the G5.
A DIFF line prints the first differing trial: status (st: 0 returned, 10/11 SIGBUS/SIGSEGV, 14 watchdog hang), r3, f1, the digest of the 128 KB argument arena (`dg`; image
addresses normalised) and the arguments. Each section below states what was measured; where a reason is not established it says so.

Harness options added while classifying these (all default off):
- `FNFUZZ_STACKFILL=<hex word>`: fill 32 KB of stack below the call, so a stack slot a function never writes holds a known value in both images.
- `FNFUZZ_FLOATARGS=1`: doubles passed to float-typed parameters are float-valued (what an ABI-valid caller passes).
- `FNFUZZ_LISTCTX=1` (fnfuzz only): parameter 0 is a valid display-list context (list block, item table, capacity) so the `_Comp` list compilers run on a context they can use.

## 1. Return register only: the stock function is void (memory digest equal)

| function | stock r3 / f1 | rebuilt | digest |
|---|---|---|---|
| `_glepPluginConnectAll` | r3 0x360 | 0 | equal |
| `_glePreInitTOC` | r3 0 | 0x80000000 | equal |
| `_glepUnloadRenderers` | r3 0x1700 | 0 | equal |
| `_gleFreeBufferObject` | r3 0x13 | 0x32a0 | equal |
| `_gleFreeEnableHashObject` | r3 0x14 | 0x40000 | equal |
| `_gleDrawArraysOrElements_Exec` | r3 only | | equal |
| `_glMapVertexAttrib1dARB_Comp` (f1) | f1 = +1.28125 | f1 = -1.28125 | equal |

The stock functions end in `blr` (or a tail call) with no value computed for the caller: `_gleFreeBufferObject` ends `b _gleVecFree` (0xc7204), so its r3/f1 is whatever the callee
or the last instruction left; the corpus declares them `int`/`double` because Ghidra's signature comes from register liveness. Writes to the arena, the recorded indirect calls and
every other compared word are identical (equal `dg`, `calls stock N rebuilt N`). For `_glepPluginConnectAll` and `_glePreInitTOC` the sole caller ignores r3 (checked earlier); for the others
that a caller never uses the value is not established statically - they are tail-call/leftover values of a void stock function, so there is no meaningful value to use.
Not changed: giving them `void` return would also remove the DIFF line; 19 functions return `extraout_r3` for that reason (see the report: recommended to leave).

## 2. A load the rebuilt code does not perform (invalid context only)

- `_gleUpdateMatrixFunc` (1 of 24 ctx trials: stock r3 = 7, rebuilt r3 = 0x1a6e0002, equal digest, no recorded calls in either): a hoisted load (judged earlier); it occurs only for an
  input the harness did not make a valid ctx (argument 0 is the plain integer 0x50001000, args `50001000 0 785 d38bb67e 0`). The exact load was not re-derived for this file: not re-established here.
- `_gleLookUpTexture3D` (8 of 48 plain trials, with stack fill 0 and 01010101 alike): the stock's first instruction is `lwz r2,0x53d4(r3)` (0x273fc); that value is used only
  for target 0x806f. For every other target the stock still reads ctx+0x53d4 and takes SIGBUS/SIGSEGV when `ctx` is not an address (the ledger types it `n`), the rebuilt code
  returns 0 without reading it (st 0, equal digest). A load from valid ctx memory has no effect, so on every context a caller can pass the two are identical.

## 3. Non-float-valued double passed to a float parameter (store rounding)

`_glColor3f_CompExec`, `_glColor4f_Comp`, `_glColor4f_ColorMat_Exec`, `_glTexCoord2f_Exec` and `_glSecondaryColor3f_Comp` (DIFF observed) store their argument with `stfs`.
Stock stores the incoming FPR directly (a float parameter arrives as a float-valued double); the corpus declares some of these parameters `double` and rounds with `frsp` first.
On the PPC970, `stfs` of a non-float-representable double truncates (0.1 -> 0x3dcccccc) and leaves a signalling NaN unquieted; `frsp`+`stfs` rounds to nearest and quiets. The two
differ only for a double that is not exactly a float, i.e. an argument an ABI-valid caller never passes.
Measured: `gleng_mock_color4f_comp` (valid ctx, 16x6 argument sets): 0 differences among sets whose arguments are all exactly floats. With `FNFUZZ_FLOATARGS=1`
(run16_floatargs_check.log): `_glColor3f_CompExec` (ctxfuzz, 96 trials) 0 differ, `_glColor4f_ColorMat_Exec` (96) 0 differ, `_glTexCoord2f_Exec` (96) 0 differ.
`float_params.tsv` types 98 functions' parameters `float` (the rebuilt code then has no extra `frsp`); the passthrough parameters of `_glColor3f_CompExec` remain `double`.

## 4. Imaging pixel-path functions (descriptor words left to the stack)

`_gleImagingUnpackData` / `_gleImagingPackData` hand `glgProcessPixels` a 0x34+ byte descriptor of which the stock and the rebuilt code initialise the same 13 words
and leave the rest to stack residue. Without a stack fill the rebuilt image differed in 29 of 48 Unpack trials (hang) and 1 of 48 Pack trials (SIGSEGV); with
`FNFUZZ_STACKFILL` = 0, 01010101, a5a5a5a5, ffffffff, 00000001 both pass 48 of 48.
Real defect found on the way (fixed in a3a6228a): `_gleImagingUnpackData` reads a 9th stack argument (`lwz r2,0x148(r1)` in a 0x110 frame) that Ghidra had folded into a
local array, so the corpus had 8 parameters, the descriptor word was stack residue and `_gleConvolutionFilter1D` dropped the argument it passes (`stw r0,0x38(r1)`).
`gleng_mock_conv1d` (valid ctx, 9 cases of component/width/format/type): the pre-fix image (049b1eba) SIGSEGVs, a3a6228a matches stock in all 9 (buffer + context words).
`_gleConvolutionFilter1D` in the fuzzers (random ctx: `free(garbage)`, `malloc(random size)`): differs with some fills and not others, because the outcome depends on heap state;
instruction-by-instruction it matches stock (checked against 0xd3be8: same arguments to `_gleImagingUnpackData` incl. the stack word, same tail call to `_gleImagingScaleAndBias`).

## 5. The `_Comp` display-list compilers on a garbage context

`_glRotatef_Comp`, `_glVertexArrayParameteriEXT_Comp`, `_glBlendFunc_Comp`, `_glBlendEquationSeparateEXT_CompExec`, `_glIndexs_Comp`, `_glIndexubv_Comp`, `_glSecondaryColor3f_Comp`
(plain ledger, 1 of 12 trials each, garbage ctx, digest differs): each begins with `_gleAddListItem`, which `realloc`s the list buffer when the random capacity word is exceeded.
`_gleAddListItem` itself is proven identical on a valid context (`gleng_mock_listitem`). With a valid list context (`FNFUZZ_LISTCTX=1`) `_glRotatef_Comp` passes 48 of 48.
The run16_compfamily.log run applies `FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 FNFUZZ_STACKFILL=0` to every `_Comp` function: results below.

## 6. `_glResetHistogram_*` (hoisted load; invalid ctx only)

`_glResetHistogram_ListExec`, `_glResetHistogram_Exec`, `_glResetHistogram_CompExec` (run17_targeted.log, 24 trials each): with a random context stock takes SIGBUS/SIGSEGV (st 10/11) and the rebuilt
code returns (st 0) with an equal digest, under no fill, fill 0 and fill 01010101 alike. Stock `_glResetHistogram_Exec` (0x6ae9c) loads `lfs f0,0x20(r3)` (ctx+0x20) unconditionally on entry; the rebuilt code
loads that float only on the branch that uses it. With `FNFUZZ_LISTCTX=1` (a context that is a real address) all three pass 24 of 24 under all three fills (RESULT: PASS x3 each). Same class as
`_gleLookUpTexture3D` in section 2: the stock fault is a load from a bad context pointer, which no caller can pass.

## 7. `_glGetHistogramParameterfv_Exec` / `_glGetMinmaxParameterfv_Exec`: stack residue on the error path

Fuzz result (run17_targeted.log): both differ in 19/24 and 17/24 trials without `LISTCTX`, 24/24 with it, with every fill (digest and r3 differ; stock r3 = ctx, rebuilt r3 = ctx+0x7574).
The functions are `fv(ctx, target, pname, float *out)`: call `iv(ctx, target, pname, &local)`, then store `(float)local` to `*out`. The stock iv function (0x6aa3c, 0x6ac28) returns without writing
`local` whenever it sets a GL error (ctx+0x4a10 >= 0, bad target, bad pname), so `local` is whatever the stack held: the stock slot is `0x48(r1)` of a 0x60 frame, the rebuilt slot `0x40(r1)` of its frame.
In the failing fuzz trials the stock stored float is 0x4ea00020 = (float)0x50001000, i.e. a word equal to the ctx argument (how it got into the slot is not established; neither function writes the slot), and the rebuilt one stores (float)0 from its own slot;
the arena difference is those words (`FNFUZZ_VERBOSE=1 FNFUZZ_CONTEXT=1`: `arena+02220: stock 4ea00020 rebuilt 00000000`, every other word listed equal). The return register differs for the same reason:
the stock iv function is a leaf that returns with r3 untouched (`bnelr`), the rebuilt returns `&ctx->error` (`addi r3,r3,0x7574`) in r3; both functions are void.
Valid-context test `gleng_mock_getparam` (`mock_getparam_a3a6228a.txt`): ctx+0x4a10 = -1 (the non-error state), 7 targets x 19 pnames x error word {0, 0x502} x 2 context fills, for the four functions
Histogram iv/fv and Minmax iv/fv. Cases where the stock iv function writes the output word: Histogram 64 (targets 0x8024/0x8025 x pnames 0x8026..0x802d), Minmax 8 (target 0x802e x pnames 0x802f/0x8030) each:
**0 differences** in the output word and in the whole 32 KB context. The 1984 error-path cases (output word is residue in both images, not compared) also leave the whole context identical.
Conclusion: the DIFF is an uninitialised stack word read in both images; every defined input behaves identically.

## 8. `_gleGenerateMipmapData` (ctx fuzz)

Earlier run16 ctxfuzz DIFF (stock st 14 hang, rebuilt returned) does not reproduce: with `CTXFUZZ_ARGINFO=1` 48 trials PASS under no fill, fill 0 and fill 01010101 (run17_targeted.log).
The earlier divergence therefore depended on stack residue / heap state of that run, not on the code.

## 9. `_glWeight{bv,sv,iv,dv,ubv,usv,uiv}ARB_Comp[Exec]`: a real defect (fixed in 05a0a503)

Found by the `_Comp` family run (run19: `FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 FNFUZZ_STACKFILL=0`, 966 functions, 11796 trials): 14 functions, digest differs (the list item the function writes), r3 differs.
Cause: Ghidra's decompiler prototype typed the count (`param_2`) `float` and the context/list pointer (`param_1`, reused for the list slot) `float *`, because the count is stored through a `float *` slot.
A `float` parameter arrives in f1; the stock code (and the K&R `_CompExec` callers) pass the count in r4, so the rebuilt function (a3a6228a: `fctiwz f0,f1`) read it from f1, and the list item's count word was the f1 bit pattern.
The old C also compared and stored the context's error word as a float (`param_1[0x1d5d] == 0.0`, store of `1.79506e-42` = 0x501).
Fix at the source, not in the C: `RetypeParams.java 0x<entry>:0` (all three parameters -> `uint`) on the Ghidra project copy, full re-dump, corpus rebuilt; the stored count is `*(uint *)p = n` (integer store, `stw`), the entries `*(float *)p`.
Audit: over the whole dump (3385 functions) and the corpus, no other function has a `float`/`double` parameter named `param_N` (a general-purpose-register parameter).
Verification (image 05a0a503): `image_function_diff.py` a3a6228a vs 05a0a503: 17 functions differ: the 14 Weight functions (`stmw r30` prologue -> `cmpwi cr7,r4,0x4`; `or r29,r4,r4` -> `or r29,r3,r3` in the wrappers) and `_gleVPGetResultOffset`,
`_gleVPGetParameterPtr`, `_glGetPixelMapuiv_Exec`, whose only change is a displacement that moves with the code layout (`lis r2,0x2 -> 0x3`, `addi r2,r2,0x88 -> 0x428`). All 26 `_glWeight*` functions
(run20_weight.log): `FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1` with stack fill 0, 01010101 and none, 48 trials each: 1248 trials, 0 differ, three times.

## 10. Void signatures (classes #15b / #15c, images 5054b4a5 and 955406de)

Section 1 left 30 stock-void functions declared `int`/`double` because Ghidra's signature comes from register liveness; the corpus then returned an unassigned `extraout_r3` / `extraout_f1` local (uninitialised in the
rebuilt image, a leftover register in the stock). Decision (user, Nov 9): match the stock's signatures. 78 functions are now `void` in the analysed Ghidra copy (`SetReturnType.java void:<entry>`), 2139 void definitions
in the corpus, no `return extraout_*` left. Not reproducing the leftover register value does not change external behaviour for any direct caller (no caller reads it); an indirect dispatch-table caller that read r3/f1
after a stock-void function would be untraceable statically, so that part is "no reader found", not proven.
Defect #15c found by the first void build: a void definition plus an `int`-typed same-part call cast (`((int (*)())callee)(...)`) made gcc emit `trap` (419 instructions, SIGTRAP st=5 in 285 DIFF lines of run22).
`ghidra2c.py` now casts to the callee's defined return type (`_rt_by_name`, 955406de); `grep -c "	trap"` of the image disassembly is 0 and must stay 0 after every build.

## 11. Class #16: a function name printed for a number (image 866643c7)

Ghidra prints a numeric constant that equals the address of a function as that function's name (non-call use); the link tree resolves the name to the REBUILT function's address. 36 corpus sites:
`_glePreInitVertexSubmitFunc` = 0x2100 (GL_MODULATE) in 12 compares (`_glTexEnv{f,fv,i,iv}_Exec`), `restFP` = 0x8b30 (GL_FRAGMENT_SHADER) in 3 compares (`_glCreateShaderObjectARB_Exec`, `_glLinkProgramARB_Exec`),
`_gleUpdatePolyMode` = 0x9404 in 3 assignments, and the byte tables `_gleSelectVertexAddMaterialFunc` = 0x9da8 (15 sites: the MapData per-attribute flag bytes, `stb r0,-0x6258(r9)` after `addis r9,r9,1`),
`_gleNullMemoryPointers` = 0x3e94 and `_gleAllocFunctions` = 0x42c0 (1 each). The compares could never match the enum values; the byte tables were indexed as `code **` (index scaled by 4, word store).
This is the cause of the stock-returns / rebuilt-SIGBUS DIFFs of `_glMap1VertexAttrib{1,2,3,4}ARB_ListExec` that run16, run22 and run23 reported and that had not been root-caused.
Fix (`ghidra2c.py` `fix_literal_syms`): a NAMED function that is not called and whose address is a 16-bit D-form immediate/displacement (or a lis/ori constant) of the same function is that number; a
`((code **)NAME)[i]` table with such a base becomes `((unsigned char *)0xADDR)[i]`. Exactly those 36 lines change (git diff of 866643c7). Clearing Ghidra's scalar-operand references was tried and rejected:
3085 of the 3141 non-flow references to function entries are real lis/addi pair references.
Verification: `gleng_mock_listexec` (valid ctx, MapData block, idx 0..15 x count 0..6 x 2 fills x 4 functions): 896 of 896 cases give identical return value, MapData block and context on 866643c7 (G5 `~/g5logs/gleng-fnfuzz/mock_listexec_866643c7.txt`);
the previous image 955406de dies with SIGBUS (exit 138). The `0x2100` / `0x8b30` / `0x9da8` immediates of `_glTexEnvfv_Exec`, `_glCreateShaderObjectARB_Exec`, `_glMapVertexAttrib1fARB_Exec` are present in both images
(`_glTexEnvi_Exec` / `_glTexEnviv_Exec`: stock 3 `cmpwi 0x2100`, rebuilt 2 `cmpwi` + 1 `xori r0,r6,0x2100` - gcc's equality form).
Fuzz run24 on 866643c7 (plain 2673 + ctx 595): all DIFF names are in the set classified in sections 1-9; the four ListExec DIFFs are gone.

## 12. Totals (image 866643c7, runs 24 and 25; earlier images a3a6228a, 05a0a503 for run16-run20)

- Plain ledger (2673 candidates), run24: 43 DIFF lines in 2 ranges (36 + 7); ctx ledger (595 candidates): 7 DIFF lines. Every DIFF name is in the set already classified in sections 1-9 (same-name comparison against
  the 81 names of run16-run23: 0 new names). Gone compared with run23: the four `_glMap1VertexAttrib*ARB_ListExec` (class #16, section 11), the 12 f1-only `_glRasterPos*_Comp` / `_glMapVertexAttrib1dARB_Comp`
  (void signatures, section 10) and the `_glWeight*` functions (class #15, section 9).
- `_Comp` family (966 functions) on a valid list context (run25): **0 DIFFs** (11616 trials, 72 uninformative); `_glWeight*` targeted with 3 stack fills: 0 differ.
- Not covered by a differential: functions the harnesses cannot run (system calls, atomics, unsafe imports: 3385 - 2673 - 595 = 117 functions). Those need the mock harnesses (phase 3, import-reachable functions) and are open.
- The sites that need a valid context rather than a random one (TexEnv compares, shader-type compares, MapVertexAttrib readers) are covered by the immediate comparison of section 11 and `gleng_mock_listexec`, not by the fuzzers.

## 13. Single-precision arithmetic as float arithmetic (pipeline step 15; images 9b93bd2c, cd1bf96f, 9749f935)

Ghidra models the stock's `fsubs` / `fmadds` / `fmuls` as double arithmetic rounded to float, so gcc emitted the double operation plus `frsp` where the stock has one single-precision instruction.
Total `frsp` in the image disassembly: stock 2134, image 866643c7 3024, 9b93bd2c 3024 -> 2898 (cd1bf96f) -> 2605 (9749f935); instruction count 316989 -> 316565 (stock 268909).
Per-function extra `frsp` (width_audit helpers, only functions with more than the stock): 1885 in 228 functions -> 905 / 187 -> 779 / 144 for the second image. The remainder is mostly real int-to-float conversions (the CONCAT44 magic-double form) and expressions over values that are still double.
Value-preserving rewrites only (`Tools/userspace/narrow_float_ops.py`, `float_params.py`, run from `build_corpus.py` for GLEngine):
- `(float)(X op Y)` with op in + - * / and both operands float-valued is the float operation (a double carries more than 2p+2 bits, so double rounding is innocuous); `(float)((X*Y)+-Z)` becomes a float expression that gcc contracts to the stock's `fmadds`.
- A `double` local whose every assignment is float-valued is retyped `float` (uses become `(double)local`).
- A `double fparam_k` is retyped `float` when every stock read of the argument FPR is single-precision or neutral and at least one is single-precision. `fmr` copies into f14-f31 survive calls, calls clobber f0-f13, millicode calls are skipped, and a parameter passed through to a callee's float parameter is float (least fixed point over the call graph): 1284 parameters in 286 functions.
Float-valued = type float, `(double)<float>`, or a double literal exactly representable as float. This is a change of expression form, not of values; there is no guard and no stock behaviour is added.
Verification on 9749f935 (`trap` count 0): plain ledger 2673 + ctx ledger 595 (run27): 36 + 6 plain and 6 ctx DIFF lines, 48 distinct names, 0 outside the classified set of sections 1-9; the same plain ledger with `FNFUZZ_FLOATARGS=1` (run29): 36 + 6, 42 names, 0 new;
`_Comp` family (966 functions, valid list ctx, float-valued args, run28): 0 DIFFs, 11616 trials; `_glWeight*` with 3 stack fills: 0 differ. Run26 (9b93bd2c): 50 names, 0 new. Compared with run26 the two names `_glMultiTexCoord3d_CompExec` and `_glMultiTexCoord4f_Comp` no longer differ.

## 14. Pipeline tail (images 762930a4 and fada32cb)

**Call-argument follow-ups.** `callarg_check.py` / `callarg_triage.py` on GLEngine: 29 residual rows, all benign (16 by the triage, 13 read by hand: shared-tail joins with a variable, stack addresses via locals, a `param_2 == 0x8d41` guard). `DarwinStorage.java` (list mode): 247 signatures; the 65 with "int moved" are the ExtendParams stack words (flat int parameters beyond r10); no change needed.

**Defect class: an embedded jump table that Ghidra did not recover.** `_glePPLogParam` (0x25020) has a `bctr` table inside the code ("Too many branches"): the decompile called through the stock table address with a byte-indexed load, and the case bodies existed only as raw asm. `FixSwitches.java 0x25020` on the GLEngine project, `RedumpContaining.java`, then the `switch_ranges.py` ranges widened; the `_glePPLogParam` C now has its `switch` cases. Found by the raw-block audit (the cases were unowned code), not by a differential (the function is only reachable through the shader-log path).

**Raw blocks regenerated.** `raw/` predated the 89 moved entries (class #6): 296 stale blocks. Regenerated with `unowned_blocks.py`, `coverage.py`, `raw_blocks.py`, `raw_emit.py`, `text_complete.py`: 165 raw blocks (code_extents 165, data_extents 131), 0 bytes accounted for by no function or block (`raw/verify.txt`, `text_accounting.txt`).

**Millicode no-ops dropped.** The save side was already patched; the restore tail left 46 `FUN_00008b68()` and 2 `restFP()` calls (empty calls before `return;`). `ghidra2c.py drop_millicode_calls` drops standalone calls to the PPC save/restore millicode (`FUN_000087a8` ... `FUN_000087d4`, `FUN_00008b68`, `saveFP` / `restFP`) when they are not the body of an `if`/`else`. Image 762930a4 (switch recovery + millicode drop + raw regeneration): run30 plain + ctx: 42 plain / 6 ctx DIFF names, 0 new compared with run27; run31 `_Comp` family on a valid list ctx: 0 differ; `_glWeight*` with 3 stack fills: 0 differ.

**`_gleInvertMatrix_AltiVec` transcribed by hand** (0x335c0, 624 bytes; the only function whose decompile fails: AltiVec). `Userspace/GLEngine/ppc/hand/part_000.c` (extra corpus `hand`, built with `-maltivec`): one intrinsic per stock instruction, in the stock's order. Pointer-argument pair `(ctx, idx)`, 4x4 float Gauss-Jordan inverse of the matrix at ctx + idx*64 + 0x1bc0 into ctx + idx*64 + 0x21c0 (unaligned load via lvsl/vperm, unaligned 64-byte store via lvsr/vperm + stvebx/stvehx/stvewx/stvx), pivot by vcmpgefp/vsel, vrefp + two Newton steps, returns nothing. Link fix: the C name assembles to `__gleInvertMatrix_AltiVec` but `data.s` refers to `_gleInvertMatrix_AltiVec`: the hand definition carries `__asm__("_gleInvertMatrix_AltiVec")` (commit fada32cb).
Phase 3 mock `Tests/userspace/gleng_mock_invmat.c` (stock `0x335c0` vs rebuilt, same process, 16 start alignments x idx 0..4 x identity / diagonal / singular rows / +-0 / Inf / NaN / denormals / 1e-30..1e30 / random bit patterns, the WHOLE 0x2400-byte block compared): 179360 tests, **0 differ**; liveness: 179360 of 179360 wrote their 64 output bytes, identity -> identity in 80 of 80 cases. (The fuzzers cannot cover it: it never returns a value and needs a valid matrix block.)

**Run32 (image fada32cb), plain 2673 + ctx 595:** 36 + 7 plain and 6 ctx DIFF lines. Compared with run30: the same 42 plain names, the same 6 ctx names, plus **one new plain name, `_glFinalCombinerInputNV_Comp`** (1 of 12 trials, trial 2 mode 0: stock SIGSEGV, rebuilt returns). Classified environmental:
- Reproducible (3 runs: DIFF on fada32cb; 3 runs: no DIFF on 762930a4). The function is `_gleAddListItem(ctx, ...)` on the harness's random context: `*(ctx + 0x53e8)` is NULL, so `_gleAddListItem` does `realloc(NULL, 200)` and then READS `*(block + 0x10)` of the uninitialised block as the item count. Stock (gdb): that word is stale heap contents (0x3c003b68), the index store `stwx r28,r2,r11` faults at 0xf030fb10. The rebuilt run did not fault (exit normally, r3 = the new block); the word's value in that run was not captured, so 'different stale contents' is inferred from the stock-vs-copy result below, not measured.
- Stock against a byte-identical COPY of itself (`GLEngine_stockcopy`, different load address, so different heap history): `_glFinalCombinerInputNV_Comp` DIFFs (25 of 48 trials differ, stock st=0 / copy st=4) and `_glFinalCombinerInputNV_CompExec` DIFFs (35 of 48). So the plain-ledger result of this function depends on what the dynamic loader left in the heap, not on the code.
- The code is identical to the one that passed in 762930a4 (no source change besides the image layout). Covered properly by the valid-list-ctx `_Comp` run below, where the list header is initialised.
Run32b (fada32cb): `_Comp` family (966 functions, valid list ctx, float-valued args, fill 0): **0 DIFFs** (11616 trials, 72 uninformative), `_glFinalCombinerInputNV_Comp` included; `_glWeight*` with 3 stack fills: 0 differ. Net result for fada32cb: no behavioural difference against stock introduced by sections 14's changes; the one plain-ledger name that moved is the load-layout dependence shown above.
