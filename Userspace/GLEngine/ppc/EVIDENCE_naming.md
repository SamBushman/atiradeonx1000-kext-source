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
