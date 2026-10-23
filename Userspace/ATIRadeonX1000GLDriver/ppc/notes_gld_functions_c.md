# GLDriver functions, round 4 (fork E4): the IL translation front ends

Evidence: opcodes and register-type bits come from the IL token table decoded in `notes_shader_formats.md` (section 5, FUN_000ddbcc),
GL enumerants appear as literals in the code, and callers are traced through the corpus. Tier per name is in the `names_E4_*.tsv` rows.

## 1. The pipeline these functions belong to

Every GL state or program that becomes a hardware fragment program is first expressed as an **IL token stream** (AMD IL: opcode in the low
16 bits, `mov` 0x47, `add` 3, `mul` 0x49, `mad` 0x40, `lrp` 0x3f, `sub` 0x5b, `dp3` 0x22, `dp4` 0x23, `texld` 0x5d, `colorclamp` 0xe, `dclpi` 0x16,
`dclpt` 0x19, `def` 0x1c, `end` 0x28), then rewritten for the bound texture state (`ilRewriteForTextureState`), then assembled into the hardware program
record (`ilAssembleProgram`). Producers of IL token streams found so far:

| producer | functions |
|---|---|
| GL_ATI_fragment_shader | `atifsCompileCurrentShader` (FUN_000b3630) with `atifsEmit*` helpers |
| fixed-function texture environment | `ffpsEmitDeclarations` (FUN_000d5900), `ffpsEmitTexEnvCombine` (FUN_000d6340), `ffpsEmitTexEnvLegacy` (FUN_000d7520), `ffpsBuild*SourceOperand` (FUN_000d4ef0 / FUN_000d51a0) |
| ARB_fragment_program / GLSL fragment shader | `fragmentProgramToIL` (FUN_00048da0), `fragmentInstructionToIL` (FUN_00046e90) |
| (by D4/D5) | ARB program text parser `arb*`, EXT_vertex_shader `evs*` |

IL operand encoding (as used by the emitters, INFERRED from the pushed constants):
* source token: bits 16..21 register type (1 constant, 4 temp, 0x11 texcoord input, 0x12 colour0, 0x13 colour1, 0x17 output colour), bits 0..15
  register index, bit 22 (0x400000) = a second word (swizzle / modifiers) follows.
* swizzle word: 4-bit component selects (0..3 = x,y,z,w, 4 = constant 0, 5 = constant 1), e.g. 0x3210 identity, 0x4444 all zero, 0x5555 all one, 0x0000 xxxx;
  modifier bits above (0x8888 negate, 0x10000 / 0x20000 / 0x40000 complement / bias / x2 as produced by `atifsEmitSourceOperand`).
* destination token: temp index | 0x40000, 0x400000 = write-mask word follows (2 bits per component: 1 = write; 0x15 = xyz); output modifier bits 0x100 saturate,
  0x200..0xc00 scale x2, x4, x8, /2, /4, /8.

## 2. GL_ATI_fragment_shader (CONFIRMED: ATI enumerants 0x8921.. 0x8961.. 0x8976..)

| function | name | what it does |
|---|---|---|
| FUN_000b15d0 | ilTokenBufPush | append a word to a growable {count,capacity,data} buffer (grows by 0x80 words through ctx+0xc alloc / ctx+0x18 free) |
| FUN_000b30e0 | atifsEmitInputDeclarations | `dclpi` colour0 / colour1 / used texcoords, `dclpt` per sampled unit |
| FUN_000b2e60 | atifsEmitClearTemp0 | `mov r0, 0` |
| FUN_000b25a0 | atifsEmitTextureOps | per pass: SampleMap / PassTexCoord records (12 bytes) -> `mov` / `texld` with the four swizzles GL_SWIZZLE_STR/STQ/STR_DR/STQ_DQ_ATI |
| FUN_000b2260 | atifsEmitDestinationOperand | destination {reg, mask, mod} -> IL dst + write mask + saturate / scale |
| FUN_000b1e80 | atifsEmitSourceOperand | argument {reg, ?, argMod, argRep} -> IL source + swizzle (rep -> GL_RED..GL_ALPHA replicate; 2X/COMP/NEGATE/BIAS) |
| FUN_000b1b90 | atifsEmitMoveWithWriteMask | `mov dstReg.mask, temp` (used to move a result redirected to scratch temp 6) |
| FUN_000b1870 | atifsEmitAddSecondaryColor | `add r0, r0, colour1.rgb0` for separate specular |
| FUN_000b1690 | atifsEmitFinalColorClamp | `colorclamp o0, r0` |
| FUN_000b3630 | atifsCompileCurrentShader | the driver: per pass texture ops then paired colour/alpha ALU ops (records of 0x4c bytes; ops GL_MOV 0x8961, ADD 0x8963, MUL 0x8964, SUB 0x8965, DOT3 0x8966, DOT4 0x8967, MAD 0x8968, LERP 0x8969, CND 0x896a, CND0 0x896b, DOT2_ADD 0x896c) |

Colour and alpha instructions of one ATI pass are issued together; when the colour result would be read by the paired alpha op the colour destination is
redirected to scratch temp 6 and moved afterwards (`redirectedToScratch`). The result is cached in the per-variant compiled program (`+0x118` secondary-add flag,
`+0x119` dirty).

## 3. Fixed-function texture environment (CONFIRMED enumerants; per-unit state at ctx + unit*0xcc)

`ffpsEmitTexEnvCombine` maps GL_COMBINE_RGB/ALPHA functions to IL opcodes (REPLACE -> mov, MODULATE -> mul, ADD -> add, ADD_SIGNED 0x8574 -> add with bias,
INTERPOLATE 0x8575 -> lrp, SUBTRACT 0x84e7 -> sub, DOT3_RGB/RGBA (ARB 0x86ae/0x86af, EXT 0x8740/0x8741) -> dp3, ATI_texture_env_combine3 0x8744..0x8746 -> mad).
Sources come from `ffpsBuild*SourceOperand` (GL_TEXTUREn, GL_CONSTANT 0x8576, GL_PRIMARY_COLOR 0x8577, GL_PREVIOUS 0x8578 and the operands 0x300..0x303).
The RGB scale (unit state +0x474) selects the destination scale bits (0x115 / 0x315 / 0x515 / 0x715). FUN_000d8450 (5.8 KB) belongs to the same family
(it emits mul / mad / sub on texcoord inputs with temps 0x20..0x22); its role is not identified.

## 4. IL consumers

* `ilRewriteForTextureState` (FUN_000cae90, INFERRED): textures whose base format is GL_DEPTH_COMPONENT (0x1902) get GL_DEPTH_TEXTURE_MODE handling
  (texture object +0x58: 0x1906 / 0x1909 / 0x8049) and, with compare on (+0x5a), the shadow compare sequence (0x1b extra output words per sample).
* `ilAssembleProgram` (FUN_000c8e50, INFERRED): fills the 0x569c-byte program record that FUN_000b57a0 allocates.
* `fragmentProgramToIL` / `fragmentInstructionToIL` (INFERRED): ARB_fragment_program and GLSL fragment programs; header words `1, 0x10200` as the other producers.

## 5. Not identified (candidates left for later rounds)
FUN_000d8450; the 0xd5390 / 0xd55c0 emitters (one-instruction emitters: 0xe colorclamp, add secondary colour); FUN_00007b0d0 (fixed-function vertex program?);
FUN_000353a0 (ring writer with GH_F2U conversions; locking via pthread); FUN_00097440 / FUN_00093a40 (0x81fa GL state).

## 6. glCopyPixels (FUN_00018120, INFERRED)
`glCopyPixels_impl(ctx, rasterPos[2], x, y, width, height, type)`: type 0x1801 is GL_DEPTH, `param_7 - 0x1801 < 2` covers depth and stencil. It recomputes the fast-path
eligibility bits at ctx+0x26b0 from the engine state (colour mask, blend, depth, stencil, alpha test enables and their functions), clips against the drawable,
tests overlap of the source and destination rectangles and chooses one of four modes (0 slow path, 1 hardware blit through FUN_00020b30, 2 / 3 textured-quad
variants). It is the third member of the pixel-transfer family with `glDrawPixels_impl` (FUN_00018a40) and `glReadPixels_impl` (FUN_00029294).
