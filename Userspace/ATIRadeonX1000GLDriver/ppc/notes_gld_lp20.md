# GLDriver parts 015-018 (lp20 round): structures read off the GL engine / shader code

Scope: `part_015.c` .. `part_018.c`. `ctx` below is the **GL engine context** (the object whose `+0x10` is the calloc callback, `+0xc` malloc,
`+0x18` free, `+0x1344` memcpy); it is NOT the GLDContext of `gld_scope.txt` (see notes_gl_context.md §1). Offsets are plain numbers because
`gld_ctx_fields.h` covers GLDContext only.

## GL_ATI_fragment_shader (glGen/Bind/Delete/Begin/End FragmentShaderATI_impl, atifs*)

Enums seen as literals: 0x8921..0x8926 GL_REG_0..5_ATI; 0x8941..0x8948 GL_CON_0..7_ATI; 0x8961..0x896c the ops (MOV, ADD, MUL, SUB, DOT3, DOT4, MAD,
LERP, CND, CND0, DOT2_ADD, ...; the mask 0xffd excludes op 0x8962 index 1); 0x896d GL_SECONDARY_INTERPOLATOR_ATI; 0x8577 GL_PRIMARY_COLOR; 0x8976..0x8979
GL_SWIZZLE_STR/STQ/STR_DR/STQ_DQ_ATI; 0x84c0.. GL_TEXTURE0; modifier bits 1 = 2X, 2 = COMP, 4 = NEGATE, 8 = BIAS; 0x1903..0x1906 GL_RED..GL_ALPHA (argument
replicate).

ctx fields: +0x1134 `inShaderDefinition` (byte, set by Begin, cleared by End), +0x1135 `usedTextureUnitMask` (byte, `FUN_000a11f0`), +0x1136 `programDirty`,
+0x1137 `passBoundaryPending`, +0x1138 `currentPass`, +0x113c `contextSlot` (index into every shader's program table), +0x1140 `boundShaderIndex`,
+0x1144 `boundShader` (pointer into the shader array), +0x1148 ushort `regsPerPass` (6), +0x114a ushort `constantCount` (8), +0x114c ushort `maxColorOps`,
+0x114e ushort `maxAlphaOps`, +0x1150 byte `maxPasses` (2), +0x1154 `shaderTable`, +0x1158/+0x115c/+0x1160/+0x1164 hooks (program invalidate / reset /
release / validate).

Shader table (`ctx+0x1154`): +0 next shader name (glGenFragmentShadersATI), +4 shader count, +8 refcount (shared between contexts), +0xc default constants
(`constantCount` x 0x14 bytes), +0x10 the default (name 0) shader record, +0x88 shader array (0x78-byte records), +0x8c number of context slots.

Shader record (0x78 bytes): +0 name, +4 pass count, +8 next op ordinal, +0xc texture ops (12-byte entries, `regsPerPass x maxPasses`: byte0 used, byte1 is
SampleMap, +4 swizzle, +8 coordinate source), +0x10 colour ops (0x4c stride) / +0x14 colour ops per pass / +0x18 colour op count, +0x1c alpha ops /
+0x20 per pass / +0x24 count, +0x28 constants (0x14 stride: set flag, 4 floats), +0x6c `usesColorInterpolator`, +0x70 per-context program table
(`contextSlot`-indexed), +0x74 valid flag (`atifsSetShaderValid`).

Op record (0x4c bytes, built on the stack by `atifsAddColorOp` / `atifsAddAlphaOp`): +0 op, +4 dst register, +8 dst mask (colour only), +0xc dst
modifier, +0x10 reserved, +0x14/+0x24/+0x34 the three packed arguments (16 bytes: register, 0, modifier bits, replicate), +0x44 ordinal, +0x48 pass.

## Joined names left in parts 015-018 (with evidence)

* `FUN_000cdc3c` (float formatter): `decimalPointOrRemainder` (`local_98`) is the int whose address is passed to `_ecvt` (decimal point exponent); the scientific
  branch reuses it as the running remainder of the exponent digit loop. It is an address-taken frame slot, so `apply_names.py` cannot split it.
* `vsDisassembleLine`: `iVar1` is split into `disasmState` / `labelEntry` / `length` (gate gT9 SPLIT-EQUIVALENT; the `x = f(x)` line takes an rhs row for the state and an lhs row for
  the entry). `labelTableOrLine` (`piVar5`) stays joined: it holds the label table pointer until the loop and the entry's instruction number inside it, and the printf after the loop
  reads it as a dead argument whichever value it holds; splitting it into two names made that read uninitialised on one path (gate gT5: UNINIT 0 -> 3).
