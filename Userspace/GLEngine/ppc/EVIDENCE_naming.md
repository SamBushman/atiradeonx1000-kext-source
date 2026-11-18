# GLEngine naming phase: evidence (Nov 17 2026)

Scope agreed with the user (Nov 15): GLEngine only; data/global names, then the FUN_ functions, then params/locals. Gate per batch: image build (`build_gleng_image.sh`) of HEAD vs the renamed tree, function-level instruction diff (`image_function_diff.py`), data section compare, nm diff.

## Batch 1: data labels (commit 17c4116f)
8 DAT_ names, `names_data_1.tsv`.

## Batch 2: FUN_ functions with a Mach-O symbol (names_funcs_G{A,B,C}.tsv, 72 rows)
Each of these 72 FUN_ functions has a real Mach-O symbol 4 bytes (12 for one) before Ghidra's function start. The image defines that symbol as a raw entry thunk (e.g. `_gleSelectLineLoopFunc: mfcr r2; b FUN_000d9dfc`), so the compiled body cannot take the symbol name (first attempt: `Symbol _glDeleteTextures_Exec already defined`). The body is named `<symbol>_body`. 71 rows CONFIRMED by the symbol, 1 (`_gleFeedbackLines_body`) INFERRED.

Gate result (images `~/rung3/gleng_nmb_f3` = HEAD, `gleng_nmc_f3` = renamed; scripts `~/g5logs/fnf_237/vn/gate3.sh`, `cmp3.sh`):
- functions: old 3557, new 3557; only in old 72 (the FUN_ names), only in new 72 (the _body names); instruction sequence differs in 0 functions.
- every one of the 72 renamed symbols is at the same address as its FUN_ predecessor (checked from `nm -n` of both images: 72 rows, 0 mismatches).
- `otool -dV` data section identical (DATA-IDENTICAL); __TEXT/__DATA sizes identical.

## Not applied: 11 saveFP/restFP millicode entries (`millicode_names_deferred.txt`)
First gate (f2) with these 11 renamed to `saveFP_from_fNN` / `restFP_from_f28`: the new names match the toolchain-code pattern, the link drops them (3546 functions, data pointers shifted by 0xb0). Not a corpus defect, a naming that changes the image; the rows are parked, to be named only together with a toolchain-pattern exception.

## Batch 3: param_1 -> glContext (names_params_ctx_1.tsv, 1093 functions, INFERRED)
Rule: `param_1` is dereferenced at >=2 offsets from the set of 86 context-state offsets that >=30 GLEngine functions access through param_1 (e.g. +0x7574 in 656 functions, +0x4a10 in 459); first argument = GL context. Whole-variable renames only.
Gate p1 (images `~/rung3/gleng_nmb_p1` HEAD ab57b1e7 vs `gleng_nmc_p1`): 3557/3557 functions, 0 instruction-sequence differences, data section identical, same size. (An earlier gate run was invalid because I killed it mid-run and the base tree dir was left half-built; base rebuilt from a clean dir.)

## Batch 4: parts 041-056 (agent C, names_loc_C_01..10.tsv, 4627 renames applied on main; 1836 CONFIRMED, 2791 INFERRED)
Families: _gleExtractPixel*/_gleInsertPixel*, _gleSetEnable_*, TextureImagePut_Fast, mipmap filters, _gleCheck*Args, _gleMap1/2*Load, _gleModifyPixel*, evaluators, matrix Get/Load/Mult, framebuffer/renderbuffer, client attribs, imaging; unusedArgN / unusedFloatArgN / incoming* pseudo-register names (audited: every unused* variable has no use outside its declaration, every incoming* is never assigned; 69 false rows from an earlier batch reverted). Placeholders in parts 041-056: 60,438 -> 38,470.
Gate M1 (HEAD image vs main tree): 3557/3557 functions, 0 instruction diffs, data and nm identical.
Not named (role not established): multi-role registers in _gle{Render,Select,Feedback}*Func_body, _gleVP*, _gleVtxLight*, _gleExecuteClippedVertexArray, _gleDrawPixelsFast, _gleGenerateMipmapData; compiler-optimised Map2*Load variants; PackData/UnpackData frames.
Suspected corpus issues reported by the agent (evidence only, not fixed): _gleInvertMatrix_601_body 16-float matrix split into adjacent stack objects (#282 class); _gleGenerateMipmapData stack pseudo-objects / stale register args to _glgConvertType and _glgProcessPixels; _gleEvalDomain{1,2}{Coord,Color} call _glePreEvaluate with 17 fabricated args; float-typed dVar6/dVar10 assigned doubles in _glePreEvaluate / _gleEvalDomain2Coord; `((unsigned char *)0x00001004) + iVar2` pointer base in _gleBindRenderbuffer/_gleBindFramebuffer (a field offset printed as an absolute address; byte-identical to the stock in the fnfuzz sweeps, cosmetic).
