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

<!-- RUN17/18 RESULTS: filled in when the runs finish -->
<!-- RUN16 RESULTS (superseded by the run17/run18 lines above) -->

