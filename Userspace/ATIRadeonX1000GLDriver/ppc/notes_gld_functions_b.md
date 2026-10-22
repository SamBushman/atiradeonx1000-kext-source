# GLDriver: non-compiler large functions identified in round 3 (fork D5)

Scope: the even-numbered lines of `gld_top_round3.txt` (the 75 largest placeholder holders at the start of round 3) that are not
compiler IR/backend (forks C1-C3), the state layer (X) or the shader dumps (Sd). Evidence is quoted per item; tiers follow the tables
(`CONFIRMED` = the binary shows it, `INFERRED` = role clear from use). Everything named is in `names_D5_*.tsv`.

## 1. GL_EXT_vertex_shader implementation (CONFIRMED by the enums in the code)

The EXT_vertex_shader enums (0x8780-0x87e0) appear as literals: opcodes 0x8782 OP_INDEX .. 0x8799 OP_MOV, 0x8786 OP_MUL, 0x8787 OP_ADD,
0x8788 OP_MADD, 0x8798 OP_MULTIPLY_MATRIX; 0x87be/0x87bf/0x87c0 GL_SCALAR/VECTOR/MATRIX_EXT; 0x87c1..0x87c4 GL_VARIANT/INVARIANT/
LOCAL_CONSTANT/LOCAL_EXT storage; swizzle selectors 0x87d5-0x87d8 GL_X..W_EXT, 0x87d9-0x87dc GL_NEGATIVE_X..W_EXT; state matrices
0xba6 / 0xba7 = GL_MODELVIEW_MATRIX / GL_PROJECTION_MATRIX.

Shader object (`shader`, the function parameter): `+0x14` instruction count, `+0x18` instruction array, `+0x1c` symbol table
`{count, records, ...}` (so `+0x20` = records), `+0x2c` cached synthesized MVP symbol index.

Instruction record (0x74 bytes): `+0` opcode, `+4` destination type (1 = output, 2 = temp/local), `+8` destination index,
`+0xc..+0x1b` four write-enable words (the low byte at `+0xf/+0x13/+0x17/+0x1b` is tested), then three source slots at `+0x20`, `+0x3c`,
`+0x58`, each 0x1c bytes: type, index, four swizzle selector words (0x87d5-0x87dc, or 0x87dd-0x87df zero/one/negative one), one more word.

Symbol record (0x54 bytes): `+0x24` data type (scalar/vector/matrix), `+0x28` storage (0x87c1-0x87c4 or -1), `+0x3c` flag, `+0x44` bound-to-state
flag, `+0x48` state enum when bound (0xba6 modelview, 0xba7 projection; 0xf for a full-mask scalar).

| function | name | role | tier |
|---|---|---|---|
| FUN_000b9f10 | extvsOptimizeProgram | pass 1 backward dead-write removal; pass 2 MUL+ADD fused into MADD; pass 3 modelview*projection multiplies fused into one multiply by a synthesized MVP symbol | CONFIRMED |
| FUN_000b72d0 | extvsInstReadsTempComponents | per opcode, which components X/Y/Z/W of a temp an instruction reads | CONFIRMED |
| FUN_000550e0 | extvsOperandDataType | operand -> GL_SCALAR/VECTOR/MATRIX_EXT | CONFIRMED |
| FUN_00054dd0 | extvsAppendSymbol | append a symbol record to the growable array | CONFIRMED |
| FUN_000538e0 / FUN_00053990 | extvsBeginShader / extvsEndShader | per-ctx "shader open" flag (ctx+0x1170); End runs the optimizer then three ctx hooks | INFERRED |

Related, identified but not renamed (not in this fork's list or evidence short): FUN_00071bc0 (7188 bytes) walks the 0x74-byte instruction
array and assigns hardware resources to symbols (ctx+0x118c/0x1398 tables, 0x16-entry tables initialised to -1); FUN_000b3630 and FUN_000b6580
(ctx+0x1134/0x1144/0x1154 shader-object selection, then FUN_000b4400 -> FUN_000cae90 compile); FUN_0007dde0 / FUN_0003c400 (X) use 1426 / 95 of
these enums.

## 2. ARB_vertex_program / ARB_fragment_program text parser (CONFIRMED by the error strings)

Functions FUN_000885b0 .. FUN_0008c590 are the program-text parser; every name below is fixed by its own error strings (the table
`names_D5_arbparser_func.tsv`). Parser state `parser`: `[0]` -> ctx (its first word receives GL error 0x502 on any error), `[3]/[4]` token
cursors, `[5]` current token type, `[6]` token value, `[0xb]/[0xc]` first error position/message, `[0x11]/[0x12]` variable list head/tail,
constant pool at word `0x9016` (four floats each, count at `[0x9116]`).

FUN_00088920 `arbNextToken`, FUN_00088e70 `arbSetError`, FUN_00089160 `arbExpectToken`, FUN_00089740 `arbParseOptionalSign` (tokens 0x19/0x1a),
FUN_00089190 `arbComponentLetterToIndex`, FUN_00089320 `arbInternConstant`, FUN_00089280 `arbAllocBindingEntry`,
FUN_0008aa40 `arbParseParamBinding` (program.env/local, state.fog/depth/light/lightmodel/lightprod/material/matrix...; state kinds
0x16/0x17 fog, 0x18 depth, 0x32 program.env, 0x33 program.local), FUN_0008b9f0 `arbParseProgramText` (header, OPTION, declarations,
statements), FUN_0008c590 `arbValidateProgram` (ALU/indirection limits, "line %d: %s" error formatting).

Not renamed: FUN_000885b0's callers' glue (FUN_00088190, FUN_00088480: no strings), FUN_00093000/FUN_00093a40/FUN_00096600/FUN_00097440:
these are the ARB *assembler* side (X's `ARB_` scope): per-temp component busy flags at ctx+0x6c4 (4 bytes per temp),
FUN_00090ca0 allocates a temp (constant tables at DAT_001dbd74..90), FUN_000911a0 frees a component; the emit callbacks hang off the allocator
object at ctx+0x3d4 (slots 0x12e8/0x12ec). Not named for lack of per-case evidence.

## 3. Texture (FUN_00032100, INFERRED)

`gldTextureMakeResident(ctx, texture, ...)`: calls FUN_00030b50 first, derives the non-power-of-two flag from the base-level dimensions minus twice
the border (level record = 0x18 bytes at texImages+0x90, width/height/depth shorts at +0xa4/+0xa6/+0xa8, border byte +0xaa) and the wrap modes
(0x2901 REPEAT, 0x8370 MIRRORED_REPEAT, 0x8742-0x8744 MIRROR_CLAMP family), then picks an upload path from the flags word (0x400 / 0x800 / 0x2000),
copies the level data (`_memcpy`, `_glgProcessPixels`, `_glgConvertType`, `_valloc`) and builds a 0x348-word hardware state packet using the
0x24-byte format table at DAT_001d9f34 (hardware format fields from +0x18/+0x1c/+0x20 of the entry, R500 registers 0x575 and 0x1393 appear as packet ids).
Callers name its result `textureComplete`.

## 4. In the list but belonging to other forks' domains (not touched)

Compiler IR passes (IRInst/Arena/Vector users): FUN_001102e0, FUN_0013da3c, FUN_0016ff54, pass_post_pack_insts, pass_ssa_build, FUN_00141930,
FUN_000f6d14, HwLimits slots 81/82, FUN_0012f0f8, FUN_00156d48, FUN_0015ceb0, FUN_0011ff7c, FUN_000f07a8, FUN_001670fc and the other
`IRInst__`-calling functions (C1/C2/C3). SC compile and psn helpers: FUN_000cae90, FUN_000c8e50 (compiler core), FUN_000bfed0
(resource-limit check + packing of a pixel program: errors 0x80000012/13/14/18 for >0x7f / >0xff / >0x10 / >0x200 totals; not named).
State layer: FUN_000369f0, FUN_0001ecd0 (X).

## 5. Unidentified (no strings, no recognisable enums)

FUN_0007c760 (initialises a large tables block, 0x2ff-entry loops), FUN_000ac720 (25 parameters, switch on param_4 with 20 memcpy), FUN_0009f0b0,
FUN_00071bc0 (see 1), FUN_000a4980 (sqrtf, memcmp), FUN_0001c380, FUN_0009d410, FUN_000a9ac0 (floats), FUN_000d8450 / FUN_000d6340
(ctx tables at +0x13b2/+0x13f8, memcpy-heavy), FUN_000c0fd0, FUN_000c42f0, FUN_0002ddf0, FUN_000c6470, FUN_00040ac4/374/370 (grow-by-realloc
vectors, X's token buffers).
