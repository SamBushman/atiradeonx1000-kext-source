# GLDriver: identified non-compiler functions (round 3, fork D4)

Each section: address range, what the code is, the evidence, and confidence. Names are in `names_D4_*.tsv` (`func` rows in `names_D4_*_func.tsv`).
Tiers follow the project convention (CONFIRMED / INFERRED / UNKNOWN) and are repeated per row in the tables.

## 1. ARB_fragment_program (ARBfp1.0) parser and compiler front end, 0x88480-0x8c590 (arbfp*)

**Identification: CONFIRMED.** The error strings are the ARB_fragment_program grammar errors verbatim ("invalid texture target", "too many ALU
instructions", "multiple targets on texture context", "more than one fog option", "redeclared variable name", "invalid writemask order",
"invalid swizzle suffix", ...), the header test in `arbfpParseProgram` (0x8b9f0) spells `!!ARBfp1.0` character by character, and
`arbfpLoadDefaultProgram` (0x8f760) compiles the literal `!!ARBfp1.0\nEND\n`.

Parser state (`parser`, the first parameter of every `arbfp*` function; `workArea` of `arbfpCompileProgram`, 0x24a30 bytes):

| offset | meaning |
|---|---|
| +0 | callbacks / limits table (`+0xc` allocator, `+0x18` free; limit bytes/words at `+0x11d4..+0x13b6`) which also receives the GL error word |
| +8 / +0xc / +0x10 | token start / cursor / source end |
| +0x14 / +0x18 / +0x1c | token kind / token value (int, or keyword value) / double value |
| +0x24 | token counter |
| +0x28 / +0x2c / +0x30 | error position / error line / error message (first error only) |
| +0x34..+0x3a | option flags (one byte per OPTION keyword: fog exp / exp2 / linear, precision hint fastest / nicest, shadow, ATI_draw_buffers) |
| +0x3c / +0x40 | declared-variable list head / tail; +0x44 / +0x48 anonymous list; +0x4c / +0x50 alias list |
| +0x50 | instruction array, 0x60-byte records: opcode, destination (variable, write mask), three 7-word source operands |
| +0x9014 / +0x9015 | ALU / texture instruction counts (ALU first, texture after) |
| +0x9016.. | literal vec4 constants (0x10 bytes each), count at +0x9116 |
| +0x9117.. | parameter table A (0x14-byte entries), count at +0x9149; +0x914a.. table B, count at +0x928a |
| +0x928b | temporaries used |

Token vocabulary (decoded from the keyword table at `__DATA,__const+8`, 130 `{name, kind, value}` entries, found by binary search in `arbfpLookupKeyword`):
kind 0 plain word (ambient .. transpose: values 1..0x2b), 1 OPTION name, 2 ALIAS, 3 vector binary op (ADD DP3 DP4 DPH DST MAX MIN MUL SGE SLT SUB XPD),
4 POW, 5 declaration (TEMP 0, ATTRIB 1, PARAM 2, OUTPUT 3), 6 END, 7 KIL, 8 OPTION, 9 scalar op (COS EX2 LG2 RCP RSQ SCS SIN), 0xa SWZ,
0xb texture op (TEX 0x1d, TXB 0x1e, TXP 0x1f), 0xc ternary (CMP 2, LRP 0xe, MAD 0xf), 0xd unary vector (ABS FLR FRC LIT MOV), 0xe texture target
(1D 2D 3D CUBE RECT SHADOW1D SHADOW2D SHADOWRECT = 1..8). `_SAT` forms have value = base + 0x21. Punctuation kinds from `arbfpNextToken`: 0x11 '.', 0x12 '..',
0x13 ',', 0x14 ';', 0x15 '[', 0x16 ']', 0x17 '{', 0x19 '+', 0x1a '-', 0x1b '=', 0xf integer literal, 0x10 float literal.

Parameter element kinds (written by `arbfpParseParameterBinding`, read by `arbfpFetchParameterValue` 0x8ebb0, which resolves them against the GL state block at
`(glContext+4)->+0x10`): 5..9 material front (ambient diffuse specular emission shininess; back = +0x2b00), 0xa..0x10 light i (ambient diffuse specular position
attenuation spot.direction half; lights at +0x24c0 stride 0x80), 0x11 lightmodel.ambient, 0x12 lightmodel.scenecolor (computed), 0x13..0x15 lightprod, 0x16 fog.color,
0x17 fog.params, 0x18 depth.range, 0x19 texenv.color, 0x1a..0x1d modelview[n] rows (matrices 0x40 bytes apart at +0x1960), 0x1e..0x21 projection, 0x22..0x25 mvp,
0x26..0x29 texture[n], 0x2a.. palette, 0x2e..0x31 program matrix[n]; element+0x10 modifier: 0 none, 1 inverse, 2 transpose, 3 invtrans (a Gauss-Jordan
inversion is inlined); 0x32 program.env[n] (state +0x1010), 0x33 program.local[n]; 0x34 inline constant; 0x35 result binding record.

Program objects: `arbfpProgramObjectInit/Free` (0x8dc50 / 0x8dda0) manage the 0x78-byte program object (instance table at +0x70, compiled record at +0x74, 0x98 bytes);
`arbfpProgramString` (0x8df50) is the `glProgramStringARB` body for target 0x8804 (GL_FRAGMENT_PROGRAM_ARB), format 0x8875: text starting `!!ILfs1.0` is stored as IL,
everything else goes through `arbfpCompileProgram`; GL_INVALID_OPERATION (0x502) on a parse error, 0x505 (GL_OUT_OF_MEMORY) on allocation failure.
`arbfpCompileProgram` (0x8c590) validates hardware limits (temporaries, ALU instructions, texture instructions, texture indirections - counted by tracking which temps
were written since the last texture fetch, one "indirection" per dependent fetch) and builds the output program.

Confidence: names of the parser functions CONFIRMED (strings). `arbfpUpdateStateForProgram` (0x8d470), `arbfpBindProgram`, `arbfpInitProgramState`,
`arbfpGrowInstanceTable` INFERRED from their data flow only.

## 2. EXT_vertex_shader translation, 0x738c0-0x76600 (evs*)

**Identification: CONFIRMED for the family, INFERRED per emitter.** `evsEncodeSource` (0x738c0) switches on 0x87d5..0x87de, the EXT_vertex_shader swizzle enumerants
(GL_X_EXT .. GL_W_EXT, GL_NEGATIVE_X_EXT .. GL_NEGATIVE_W_EXT, GL_ZERO_EXT 0x87dd, GL_ONE_EXT 0x87de); symbol classes 0x87c1..0x87c4 are GL_VARIANT / INVARIANT /
LOCAL_CONSTANT / LOCAL_EXT and data types 0x87be..0x87c0 GL_SCALAR / VECTOR / MATRIX_EXT; `evsEncodeDestination` (0x744d0) tests 0x879a/0x879b (OUTPUT_VERTEX /
OUTPUT_COLOR0), 0x879d.. (OUTPUT_TEXTURE_COORDn) and 0x87bd (OUTPUT_FOG). `evsFoldConstantMoves` (0x7dde0) pattern-matches GL_OP_MOV_EXT (0x8799).

The 33 per-op emitters are the entries of a function-pointer table at `__DATA,__data+0x2b0c` (descending addresses 0x76560 .. 0x74b30), each calling
`evsAppendInstruction` (0x74a70) with an IL vertex opcode and then the destination / source encoders. The opcode-to-mnemonic mapping is the IL table of
`notes_shader_formats.md` (0x47 mov, 0x22 dp3, 0x23 dp4, 0x49 mul, 3 add, 0x40 mad, ...). Several emitters (the mov variants at 0x752c0, 0x75360, 0x75400, 0x74ed0,
0x75060, and 0x76560) emit the same opcode with different operand shapes and are left unnamed; the order of the table does not follow the GL enumerant order, so the
mapping from GL op to emitter is by opcode only. Confidence: INFERRED.

## 3. GL state validation, 0x4d000-0x52300 and 0x90470 (gldValidate*)

**Identification: INFERRED from GL enumerants.** `gldValidateState` (0x90470) tests two dirty words (`glContext+0x38`, `+0x3c`) and calls one translator per set bit; the
translators read the GL state block (`(glContext+4)->+0x10`) and write register shadows in the context (`+0x1930` is the register-dirty word they all OR a bit into):

- `gldValidateBlend` (0x51420, dirty2 bit 0x8): equation 0x8006/0x8007/0x8008/0x800a/0x800b, factors ZERO/ONE/0x300-0x308/0x8001-0x8004 -> blend-control shadows +0x1a80/+0x1a84.
- `gldValidateStencil` (0x51010): GL_KEEP 0x1e00 .. INCR 0x1e02/DECR 0x1e03, INVERT 0x150a, INCR_WRAP 0x8507, DECR_WRAP 0x8508.
- `gldValidateAlphaTest` (0x4ff70): function 0x201..0x207, reference scaled by 255.0 (+0x1a4f byte, +0x1bde 16-bit).
- `gldValidateScissor` (0x4f550), `gldValidateCullFace` (0x4f080: GL_CW 0x900, cull 0x404/0x405/0x408), `gldValidateDepthTest` (0x4dac0),
  `gldValidateTexEnvColor` (0x4dc30: per-unit 4-float colour copy, state stride 0xcc -> shadow stride 0x10).
- Not identified (left unnamed): 0x4ea70 (polygon mode 0x1b00..0x1b02), 0x4eba0, 0x4ed90, 0x520c0, 0x4f2e0, 0x4def0 (2.4 KB), 0x4d100, 0x52280, 0x50300, 0x50140 (0x1d01 GL_SMOOTH,
  probably shade model), 0x4d620, 0x900a0.

The `glContext` of these functions is a different object from X's GLDContext (`ctx`, `notes_gl_context.md`): +0x38 is a dirty word here, a render-buffer mask there.

## 4. Looked at, not identified

0x46e90 / 0x48da0 (program linking? `0x8b30` GL_FRAGMENT_SHADER appears twice), 0xc8e50 and 0xd7520 (compiler core / IL), 0x98500 and 0x94840 (called from 0x9d410, constants 0x12ec/0x20d4/0x2d48),
0x78f80 / 0x7b0d0 / 0x7c760 (fixed-function vertex program generator over a per-unit table at +0x450/+0x2a87c/+0x3348c), 0xaec40, 0x62af0, 0x353a0 / 0x18120 / 0x21c70 / 0x24970
(pixel-transfer family next to X's functions, register 0x1095 = GA_US_VECTOR_DATA is written), 0x50300 / 0x52280.
