# GLDriver functions, round 4, fork E5 (even lines of gld_top_round4.txt)

Scope: the even-numbered entries of the round-4 top-300 placeholder list that are not compiler IR/backend. The largest cluster turned out to
be one subsystem: the **GL_EXT_vertex_shader implementation**, addresses 0x538e0-0x61ee0 (fork D5 had named the ends: extvsBeginShader,
extvsEndShader, extvsAppendSymbol, extvsOperandDataType, extvsOptimizeProgram).

## EXT_vertex_shader module map (evidence = each function body; tiers in names_E5_func.tsv)

Per-context state: pointer at ctx+0x116c = the shader table {+0 refcount, +4 shader count, +0xc array of 0x7c-byte shader objects,
+0x10 next namespace id, +0x14 symbol list, +0x24 first (MVP) symbol index, +0x28 state-symbol hash buckets}. ctx+0x1168 = the current shader object,
ctx+0x1170 = "a shader is open" byte, ctx+0x118c = index of the current table, ctx+0x112c = the program-object table (entries of type 0x8620).
ctx+0xc/+0x10/+0x18 = malloc/calloc/free hooks, ctx+0x1344 = memcpy hook, ctx+0x11a4/+0x11a8/+0x11ac = shader-object lifecycle hooks.

* lifecycle: extvsInitState (0x54b20), extvsReleaseState (0x54a90), extvsFreeAllShaders (0x54980), extvsFreeShaderObject (0x55300),
  extvsAttachSharedState (0x54c10), extvsInitShaderObject (0x55b50), extvsInitSymbolListWithMVP (0x55a60: the list starts with the MVP_MATRIX_EXT state symbol, enum 0x87e3).
* object table: extvsFindShaderIndex (0x53a90), extvsGetShaderById (0x53b00), extvsBindShader (0x53b60: glBindVertexShaderEXT, grows the array by 16),
  extvsDeleteShaderObject (0x53de0) behind glDeleteVertexShaderEXT_impl (0x53ef0).
* GL entry points (all test the open byte ctx+0x1170 first): glShaderOp1/2/3EXT_impl (0x53f00/0x53f80/0x54000, all through extvsAppendInstruction 0x553c0),
  glWriteMaskEXT_impl (0x541a0, four enables each < 2), glExtractComponentEXT_impl (0x54270) / glInsertComponentEXT_impl (0x543b0) (component < 4;
  which of the two is which rests on what each writes into the instruction, tier INFERRED), glSetLocalConstantEXT_impl (0x547f0, storage 0x87c3),
  glGenSymbolsEXT_impl (0x53340, arguments validated against datatype 0x87be-0x87c0, storage 0x87c1-0x87c4, range 0x87e0/0x87e1).
* symbols: 0x54-byte records in a list {+4 records, +8 index array, +0xc count}; extvsCreateSymbol (0x55610), extvsSymbolListGetIndex (0x54da0),
  extvsSymbolListGetSymbol (0x55a30), extvsFreeSymbolData (0x551f0), extvsGetOrCreateStateSymbol (0x53220).
* back end (shader -> hardware program), driven by extvsPrepareHardwareProgram (0x5f810, 9.6 KB):
  - extvsAssignVertexInputs (0x5e7f0): marks the fixed-function vertex attributes read by unbound VARIANT symbols (switch on the state kind 0..0x10 sets
    the attribute-used bytes programState+0x2c..+0x41) and hands out input registers (scalars, vectors, 4 per matrix) into programState+0x24 (0x28-byte slots).
  - extvsAllocConstantRegisters (0x55da0, INVARIANT symbols), extvsAllocTempRegisters (0x564c0, LOCAL symbols), extvsFreeDeadTempSlots (0x56be0),
    extvsOperandUsesTempSlot (0x56b80): 0x28-byte register slots with a used byte at +0x10 and up to four symbol indices at +0x18..+0x24; pools grow by 16 slots.
  - extvsEncodeSourceOperand (0x56f20) and extvsEncodeSourceSwizzle (0x57340): the hardware source word (register select, flags, per-component swizzle/negate).
  - extvsEmitSingleSourceInstruction (0x58300) and the unnamed emitters 0x57cf0 / 0x58450 / 0x59190 ... which write the 0x10-byte output instructions
    (limit 0x100 instructions per program).
  - extvsPrepareHardwareProgram itself: records which outputs are written (0x879a vertex position, colours, texture coordinates 0x879d-..), snapshots each
    instruction's four write-enable words, assigns output registers programState+0x1e8..0x200 and allocates constants.

Not named (identified only): FUN_00071bc0 (7.2 KB, resource assignment across the instruction array, tables at ctx+0x118c/0x1398), FUN_00057cf0 /
FUN_00058450 / FUN_00059190 (per-opcode code generators, 1.5 KB / 0.9 KB / 2.5 KB), FUN_00057b80, FUN_00054470, FUN_00054590, FUN_000546d0.

## Fixed-function vertex program generator

FUN_00098500 (6.4 KB, ffvpEmitLight, INFERRED): per-light emission with the temp allocator of FUN_00090ca0 / FUN_000911a0 (D5 notes). Evidence: 0x3c-byte
per-light parameter records at builder+0xf8 (indices that must not be -1), 0x80-byte light state at +0x251c indexed by light (a float tested against 0.0
looks like the spot exponent), flags at +0x150c with stride 0x6c. Its neighbours FUN_00094840 / FUN_0007c760 / FUN_00078f80 belong to the same generator
(D4 notes) and are left unnamed.

## Left unidentified, with what the evidence says

* FUN_000a4980 (4.8 KB): int->double conversions (0x43300000), sqrtf, one string tail "ram[" (a mid-string pointer into a state-name literal such as
  "program.env["), memcmp: derived-state computation for ARB program state bindings, not decoded.
* FUN_000a9ac0 (7.7 KB): calls arbfpUpdateStateForProgram x6, string "ir_undefined"; ctx offsets 0x1874/0x18a4/0x1928; fragment-program state upload.
* FUN_000ac720 (7.9 KB): 20 memcpy calls with 0x200/0x800/0x8000 masks: texture/sampler state packing, not decoded.
* FUN_0009f0b0 (4.4 KB), FUN_0001c380 (3.7 KB; GL enums 0x80e0/0x80e1 BGR/BGRA and 0x1907 RGB: pixel format conversion), FUN_0007c760 (4.9 KB; 0x8a1b,
  0x1fe0 ...), FUN_000fb3d4 / FUN_001102e0 / FUN_0014f420 (compiler IR passes, other forks' scope).
