# The R500 backend of the GLDriver shader compiler (R300/R520 assemblers)

What was recovered about the machine-code back end of ATI's shader compiler inside `ATIRadeonX1000GLDriver` (the classes `R300MachineAssembler`,
`R520MachineAssembler`, `R300VMachineAssembler`, `R520VMachineAssembler`, address range `0x195000`-`0x1a3000`), from the code, the data sections and the
AMD documentation in `~/Documents/AMD Docs` (`R5xx_Acceleration_v1.5.pdf`, `R3xx_3D_Registers.pdf`). Renamed functions and variables are in
`names_C3_func.tsv` / `names_C3_locals.tsv`. CONFIRMED = read straight from code/data/documentation; INFERRED = role clear from use.

## 1. IR opcode numbers (CONFIRMED) - the table `notes_compiler_ir.md` listed as open

`FUN_00115fa0` (34636 bytes, part_036) is the static initialiser that constructs one global `Ir<Name>` object per IR opcode. For each it stores the class vtable
(a non-lazy pointer, e.g. `PTR_DAT_001e8f08 + 8`), the opcode number into the object (`DAT_001fc1a0 = 0x11`) and then the object's address into the table
`DAT_001fc2b0 + 4 * opcode` (`DAT_001fc2f4 = &DAT_001fc198`). The vtable's typeinfo (`[offset-to-top][typeinfo*]` before slot 0) points at the class name string.
Joining the three gives the opcode -> class map below (253 of 255; opcodes `0xb6`, `0xef` have no object in the static init; opcodes below `0x0f` are not in the table).
The map was validated against code: the RGB/alpha opcode setters of the pixel-shader assemblers (`R300MachineAssembler__setRgbOpcode` / `setAlphaOpcode`) treat
`0x31`/`0x66` (`IrMovFloat`/`IrMov`) as `mad(a, ONE, ZERO)`, `0x12`/`0x34` (`IrAddFloat`/`IrAdd`) as `mad(a, ONE, b)`, `0x13`/`0x36` (`IrMulFloat`/`IrMul`) as
`mad(a, b, ZERO)`, `0x9d` (`IrCnd05`) as the R300 `cnd` opcode - exactly what the names say.

| hex | dec | class |
|---|---|---|
| 0x0f | 15 | `IrRet` |
| 0x10 | 16 | `IrCondJmp` |
| 0x11 | 17 | `IrAlloc` |
| 0x12 | 18 | `IrAddFloat` |
| 0x13 | 19 | `IrMulFloat` |
| 0x14 | 20 | `IrMulAddFloat` |
| 0x15 | 21 | `IrFloorFloat` |
| 0x16 | 22 | `IrFractFloat` |
| 0x17 | 23 | `IrMaxFloat` |
| 0x18 | 24 | `IrMax4` |
| 0x19 | 25 | `IrMinFloat` |
| 0x1a | 26 | `IrTruncFloat` |
| 0x1b | 27 | `IrCube` |
| 0x1c | 28 | `IrDot3` |
| 0x1d | 29 | `IrDot4` |
| 0x1e | 30 | `IrDot2Add` |
| 0x1f | 31 | `IrDst` |
| 0x20 | 32 | `IrKillEFloat` |
| 0x21 | 33 | `IrKillGTFloat` |
| 0x22 | 34 | `IrKillGEFloat` |
| 0x23 | 35 | `IrKillNEFloat` |
| 0x24 | 36 | `IrCndEFloat` |
| 0x25 | 37 | `IrCndGEFloat` |
| 0x26 | 38 | `IrCndGTFloat` |
| 0x27 | 39 | `IrSetEFloat` |
| 0x28 | 40 | `IrSetGTFloat` |
| 0x29 | 41 | `IrSetGEFloat` |
| 0x2a | 42 | `IrSetNEFloat` |
| 0x2b | 43 | `IrMovaRoundFloat` |
| 0x2c | 44 | `IrPredSetEPush` |
| 0x2d | 45 | `IrPredSetNEPush` |
| 0x2e | 46 | `IrPredSetGTPush` |
| 0x2f | 47 | `IrPredSetGEPush` |
| 0x30 | 48 | `IrExportFloat` |
| 0x31 | 49 | `IrMovFloat` |
| 0x32 | 50 | `IrLit` |
| 0x33 | 51 | `IrNop` |
| 0x34 | 52 | `IrAdd` |
| 0x35 | 53 | `IrSub` |
| 0x36 | 54 | `IrMul` |
| 0x37 | 55 | `IrExp` |
| 0x38 | 56 | `IrFloor` |
| 0x39 | 57 | `IrFract` |
| 0x3a | 58 | `IrLogClamp` |
| 0x3b | 59 | `IrLogIEEE` |
| 0x3c | 60 | `IrMax` |
| 0x3d | 61 | `IrMin` |
| 0x3e | 62 | `IrRecipClamp` |
| 0x3f | 63 | `IrRecipFF` |
| 0x40 | 64 | `IrRecipIEEE` |
| 0x41 | 65 | `IrRecipSqrtClamp` |
| 0x42 | 66 | `IrRecipSqrtFF` |
| 0x43 | 67 | `IrRecipSqrtIEEE` |
| 0x44 | 68 | `IrSqrt` |
| 0x45 | 69 | `IrTrunc` |
| 0x46 | 70 | `IrAddConst0` |
| 0x47 | 71 | `IrMulConst0` |
| 0x48 | 72 | `IrSubConst0` |
| 0x49 | 73 | `IrAddConst1` |
| 0x4a | 74 | `IrMulConst1` |
| 0x4b | 75 | `IrSubConst1` |
| 0x4c | 76 | `IrSin` |
| 0x4d | 77 | `IrCos` |
| 0x4e | 78 | `IrKillE` |
| 0x4f | 79 | `IrKillGT` |
| 0x50 | 80 | `IrKillGE` |
| 0x51 | 81 | `IrKillNE` |
| 0x52 | 82 | `IrKillOne` |
| 0x53 | 83 | `IrPredSetE` |
| 0x54 | 84 | `IrPredSetNE` |
| 0x55 | 85 | `IrPredSetGT` |
| 0x56 | 86 | `IrPredSetGE` |
| 0x57 | 87 | `IrPredSetInv` |
| 0x58 | 88 | `IrPredSetPop` |
| 0x59 | 89 | `IrPredSetClr` |
| 0x5a | 90 | `IrPredSetRst` |
| 0x5b | 91 | `IrSetE` |
| 0x5c | 92 | `IrSetGT` |
| 0x5d | 93 | `IrSetGE` |
| 0x5e | 94 | `IrSetNE` |
| 0x5f | 95 | `IrAddPrev` |
| 0x60 | 96 | `IrMulPrev` |
| 0x61 | 97 | `IrMulPrev2` |
| 0x62 | 98 | `IrSubPrev` |
| 0x63 | 99 | `IrMovaRound` |
| 0x64 | 100 | `IrMovaFloor` |
| 0x65 | 101 | `IrExport` |
| 0x66 | 102 | `IrMov` |
| 0x67 | 103 | `IrNop1` |
| 0x68 | 104 | `IrFetchVertex` |
| 0x69 | 105 | `IrFetchTextureMap` |
| 0x6a | 106 | `IrFetch3DNoiseMap` |
| 0x6b | 107 | `IrFetchShadowMap` |
| 0x6c | 108 | `IrFetchMultiSample` |
| 0x6d | 109 | `IrGetBorderColorFraction` |
| 0x6e | 110 | `IrGetCompTexLod` |
| 0x6f | 111 | `IrGetGradients` |
| 0x70 | 112 | `IrGetWeights` |
| 0x71 | 113 | `IrSetTexLod` |
| 0x72 | 114 | `IrSetGradientsH` |
| 0x73 | 115 | `IrSetGradientsV` |
| 0x74 | 116 | `IrSetFilter4Weights` |
| 0x75 | 117 | `IrFetchTextureMapProj` |
| 0x76 | 118 | `IrFetchTextureMapBias` |
| 0x77 | 119 | `IrFetchTextureMapKill` |
| 0x78 | 120 | `IrFetchTextureMapGradients` |
| 0x79 | 121 | `IrLoadConst` |
| 0x7a | 122 | `IrLoadTemp` |
| 0x7b | 123 | `IrLoadPhysical` |
| 0x7c | 124 | `IrLoadAbstractState` |
| 0x7d | 125 | `IrLoadTempDefault` |
| 0x7e | 126 | `IrLoadInterp` |
| 0x7f | 127 | `IrVertexLoopFetch` |
| 0x80 | 128 | `IrPixelLoopFetch` |
| 0x81 | 129 | `IrLoopStart` |
| 0x82 | 130 | `IrLoopIndex` |
| 0x83 | 131 | `IrMerge` |
| 0x84 | 132 | `IrProjection` |
| 0x85 | 133 | `IrUndefined` |
| 0x86 | 134 | `IrHeader` |
| 0x87 | 135 | `IrEntry` |
| 0x88 | 136 | `IrExit` |
| 0x89 | 137 | `IrProlog` |
| 0x8a | 138 | `IrEpilog` |
| 0x8b | 139 | `IrCmp2` |
| 0x8c | 140 | `IrCmp1D` |
| 0x8d | 141 | `IrCmp1S` |
| 0x8e | 142 | `IrPhi` |
| 0x8f | 143 | `IrStartCallRoutine` |
| 0x90 | 144 | `IrStartMakeCall` |
| 0x91 | 145 | `IrEndCall` |
| 0x92 | 146 | `IrEndMakeCall` |
| 0x93 | 147 | `IrAllocPos` |
| 0x94 | 148 | `IrAllocMem` |
| 0x95 | 149 | `IrAllocColor` |
| 0x96 | 150 | `IrAllocInterp` |
| 0x97 | 151 | `IrOpDp` |
| 0x98 | 152 | `IrOpSop` |
| 0x99 | 153 | `IrPresubBX2Neg` |
| 0x9a | 154 | `IrPresubSub` |
| 0x9b | 155 | `IrPresubAdd` |
| 0x9c | 156 | `IrPresubInvert` |
| 0x9d | 157 | `IrCnd05` |
| 0x9e | 158 | `IrDsx` |
| 0x9f | 159 | `IrDsx1` |
| 0xa0 | 160 | `IrDsy` |
| 0xa1 | 161 | `IrDsy1` |
| 0xa2 | 162 | `IrMix` |
| 0xa3 | 163 | `IrDp3Add` |
| 0xa4 | 164 | `IrLoad` |
| 0xa5 | 165 | `IrPow` |
| 0xa6 | 166 | `IrMovaFlr` |
| 0xa7 | 167 | `IrR300Expp` |
| 0xa8 | 168 | `IrDxLogp` |
| 0xa9 | 169 | `IrR300ExpBaseE` |
| 0xaa | 170 | `IrMad` |
| 0xab | 171 | `IrCndE1` |
| 0xac | 172 | `IrCndGE1` |
| 0xad | 173 | `IrCndGT1` |
| 0xae | 174 | `IrFetchTextureLOD` |
| 0xaf | 175 | `IrFetchTextureUncached` |
| 0xb0 | 176 | `IrCmovEQ` |
| 0xb1 | 177 | `IrCmovGE` |
| 0xb2 | 178 | `IrCmovGT` |
| 0xb3 | 179 | `IrCmovNE` |
| 0xb4 | 180 | `IrScatter` |
| 0xb5 | 181 | `IrFetchShaderCall` |
| 0xb6 | 182 | `(not found)` |
| 0xb7 | 183 | `IrMaxDx10` |
| 0xb8 | 184 | `IrMinDx10` |
| 0xb9 | 185 | `IrSetE_Dx10` |
| 0xba | 186 | `IrSetGTDx10` |
| 0xbb | 187 | `IrSetGE_Dx10` |
| 0xbc | 188 | `IrSetNE_Dx10` |
| 0xbd | 189 | `IrCeil` |
| 0xbe | 190 | `IrRoundNearestEven` |
| 0xbf | 191 | `IrMovaFloorFloat` |
| 0xc0 | 192 | `IrMovaFloorGprInt` |
| 0xc1 | 193 | `IrMovaFloorInt` |
| 0xc2 | 194 | `IrAndInt` |
| 0xc3 | 195 | `IrOrInt` |
| 0xc4 | 196 | `IrXorInt` |
| 0xc5 | 197 | `IrNotInt` |
| 0xc6 | 198 | `IrAddInt` |
| 0xc7 | 199 | `IrMaxInt` |
| 0xc8 | 200 | `IrMinInt` |
| 0xc9 | 201 | `IrMaxUInt` |
| 0xca | 202 | `IrMinUInt` |
| 0xcb | 203 | `IrSubInt` |
| 0xcc | 204 | `IrSetEInt` |
| 0xcd | 205 | `IrSetGTInt` |
| 0xce | 206 | `IrSetGEInt` |
| 0xcf | 207 | `IrSetGTUint` |
| 0xd0 | 208 | `IrSetGE_uint` |
| 0xd1 | 209 | `IrSetNEInt` |
| 0xd2 | 210 | `IrPredSetEInt` |
| 0xd3 | 211 | `IrPredSetGTInt` |
| 0xd4 | 212 | `IrPredSetGEInt` |
| 0xd5 | 213 | `IrPredSetNEInt` |
| 0xd6 | 214 | `IrPredSetLTInt` |
| 0xd7 | 215 | `IrPredSetLEInt` |
| 0xd8 | 216 | `IrPredSetEPushInt` |
| 0xd9 | 217 | `IrPredSetNEPushInt` |
| 0xda | 218 | `IrPredSetGTPushInt` |
| 0xdb | 219 | `IrPredSetGEPushInt` |
| 0xdc | 220 | `IrPredSetLTPushInt` |
| 0xdd | 221 | `IrPredSetLEPushInt` |
| 0xde | 222 | `IrDot4IEEE` |
| 0xdf | 223 | `IrDot3IEEE` |
| 0xe0 | 224 | `IrF2Int` |
| 0xe1 | 225 | `IrInt2F` |
| 0xe2 | 226 | `IrUInt2F` |
| 0xe3 | 227 | `IrAshrInt` |
| 0xe4 | 228 | `IrLshrInt` |
| 0xe5 | 229 | `IrLshlInt` |
| 0xe6 | 230 | `IrMulLowInt` |
| 0xe7 | 231 | `IrMulHiInt` |
| 0xe8 | 232 | `IrMulLowUInt` |
| 0xe9 | 233 | `IrMulHiUInt` |
| 0xea | 234 | `IrRecipInt` |
| 0xeb | 235 | `IrRecipUInt` |
| 0xec | 236 | `IrCndEInt` |
| 0xed | 237 | `IrCndGTInt` |
| 0xee | 238 | `IrCndGEInt` |
| 0xef | 239 | `(not found)` |
| 0xf0 | 240 | `IrMulAddIEEE` |
| 0xf1 | 241 | `IrMulAdd` |
| 0xf2 | 242 | `IrCndE` |
| 0xf3 | 243 | `IrCndGT` |
| 0xf4 | 244 | `IrCndGE` |
| 0xf5 | 245 | `IrMulLit` |
| 0xf6 | 246 | `IrPsColorFog` |
| 0xf7 | 247 | `IrEmit` |
| 0xf8 | 248 | `IrDyamicReturn` |
| 0xf9 | 249 | `IrExportRing` |
| 0xfa | 250 | `IrMemInit` |
| 0xfb | 251 | `IrScratchLoad` |
| 0xfc | 252 | `IrScratchStore` |
| 0xfd | 253 | `IrWhileStart` |
| 0xfe | 254 | `IrCbLoad` |
| 0xff | 255 | `IrFetchLoad` |
| 0x100 | 256 | `IrSampleC` |
| 0x101 | 257 | `IrSampleL` |
| 0x102 | 258 | `IrSampleCLZ` |
| 0x103 | 259 | `IrSampleG` |
| 0x104 | 260 | `IrLdBuffer` |
| 0x105 | 261 | `IrCut` |
| 0x106 | 262 | `IrDyamicReturnSwitch` |
| 0x107 | 263 | `IrEmitThenCut` |
| 0x108 | 264 | `IrF2UInt` |
| 0x109 | 265 | `IrGetResource` |
| 0x10a | 266 | `IrImmedConstBuffer` |
| 0x10b | 267 | `IrImmedConstLoad` |

## 2. The pixel-shader native (PSN) record (CONFIRMED against the writer code)

The assembler objects hold an array of 0x48-byte records (`R300MachineAssembler`: base at +0x58 with the allocation (0x963c bytes) at +0x5c, current index at +0x60,
index 1 is the first instruction; `R520MachineAssembler`: base +0xa8, allocation +0xac). Record 0 is the header. This is the layout `FUN_000d183c` prints
(`notes_shader_formats.md` sec. 6); the writers that fill it are now named:

| record | kind word | writers |
|---|---|---|
| header (0) | - | `*__writeHeaderRecord` (vslot 81): +0x24 highest constant, +8 record count, +0x16 levels, +0x18 RS count, +0x1a TEX count, +0x1c ALU count, +0x1e ALU slots, +0x22 pixel size |
| RS | 1 | `*__setRsColorFields` (vslot 49: +0xa colour index, +0xb colour source, +6 destination register, +0xd biased), `*__setRsTexCoordFields` (vslot 50: +8 texcoord index, +9 present, +4 destination register, +0xc adjusted) |
| TEX | 2 | `*__emitTexRecord` (vslot 23): +0xe source register, +0xc destination register, +0x19 texture unit, +0x1a TEX opcode, +0x1f flags |
| ALU | 3 | `*__initNopAluRecord` (vslot 48), `*__setAluSourceAddresses` (vslot 70: +0xe/+0x10/+0x12 RGB, +0x1a/+0x1c/+0x1e alpha source addresses), `*__setAluSourceSelectsAndModifiers` (vslot 71: selects +0x2a..+0x2c / +0x39..+0x3b, modifiers +0x2d..+0x2f / +0x3c..+0x3e), `*__setRgbOpcode` (vslot 75: +0x31 opcode, +0x32 scale, +0x33 clamp), `*__setAlphaOpcode` (vslot 76: +0x40 opcode, +0x41 scale, +0x42 clamp), `*__setTempDestination` (vslot 72: +0xc/+0x14 and +0x18/+0x20), `*__setOutputDestination` (vslot 73: +0x15/+0x16 and +0x21/+0x22/+0x23) |
| predicate-set ALU | 4 | `R520MachineAssembler__vslot74_setPredicateSetDestination` |
| control flow | 5 (R520 only) | `R520MachineAssembler__vslot38_appendBranchRecord`, `...vslot39_appendLoopStartRecord`, `...appendBranchEndRecord`, `...appendLoopRecord`, `...vslot37_closeBranch` ... (+0xe CF opcode, +0x12 mask, +0x13/+0x15 counts, +0xc patched branch target) |

Source select codes (R300 assembler, CONFIRMED): the bytes written at ALU record +0x2a..+0x2c (RGB) and +0x39..+0x3b (alpha) follow the R300 ALU argument tables
of `R3xx_3D_Registers.pdf` (`US_ALU_RGB_INST` / `US_ALU_ALPHA_INST`, argument select fields):

* RGB (ARGC): `0 SRC0C_XYZ, 1 SRC0C_XXX, 2 SRC0C_YYY, 3 SRC0C_ZZZ, 4..7 the same for SRC1, 8..11 SRC2, 12/13/14 SRC0A/SRC1A/SRC2A, 15 SRCP_XYZ, 16..19 SRCP_XXX/YYY/ZZZ/WWW,
  20 ZERO, 21 ONE, 22 HALF, 23..25 SRCnC_YZX, 26..28 SRCnC_ZXY, 29..31 SRCnCA_WZY`.
  Evidence: `rgbSelectForSrcpSwizzle` stores 0xf..0x13 for the swizzle patterns 0x00010203/0/0x01010101/0x02020202/0x03030303 (identity, xxxx, yyyy, zzzz, wwww);
  `rgbSelectForSourceSwizzle` stores `4*src + {0,1,2,3}` and `src + 0x17/0x1a/0x1d`; `rgbSelectForLiteralFloat` stores 0x14/0x15/0x16 for the literals 0.0/1.0/0.5.
* alpha (ARGA): `0..8 SRCnC_X/Y/Z, 9/10/11 SRC0A/SRC1A/SRC2A, 12..15 SRCP_X/Y/Z/W, 16 ZERO, 17 ONE, 18 HALF`
  (`alphaSelectForColorComponent` = `3*src + comp`, `alphaSelectForAlphaSource` = `src + 9`, `alphaSelectForSrcpComponent` = `0xc + comp`, `alphaSelectForLiteralFloat` = 0x10/0x11/0x12).
* The R520 twins store `3` (SRCP) or the source number in the select byte and put the swizzle/literal choice in the packed words at +0x24 / +0x28
  (3 bits per lane; literal 0.0 / 0.5 / 1.0 = 4 / 5 / 6) - layout INFERRED from the shift/mask constants.

## 3. Assembler objects

`R300MachineAssembler` (allocated by `__create`, 0xac bytes; `R520MachineAssembler` 0x10c4 bytes). Fields used by the named functions (CONFIRMED unless marked):

| offset | meaning |
|---|---|
| +0x0 | vtable (below) |
| +0xc | compiler object (`compiler + 0x6c4` register allocation table, `+0x30c` target description, `+0x374`/`+0x378` arenas) |
| +0x10 | program being assembled (control-flow stacks: vectors at program +0x24 / +0x28, count at +4, storage at +8) |
| +0x58 / +0x5c / +0x60 | R300: record array / allocation / current record index (R520: +0xa8 / +0xac / +0x60) |
| +0x64 | ALU record count; +0x68 TEX count; +0x74 RS count; +0x7c extra ALU slots; +0x88 texture indirection levels (INFERRED from `writeHeaderRecord`) |
| +0xa0..+0xa3 | the four swizzle lanes of source 0 of the instruction being classified |
| allocation +0x936c / +0x9370 / +0x9374 / +0x9378 | used-texture-unit mask / flag / highest colour output / per-unit flags (INFERRED) |

`R300VMachineAssembler` (vertex shader, allocated by `__create`, 0x90 bytes; `R520VMachineAssembler` 0xa0 bytes): +0x44 array of 0x10-byte PVS instructions (4 words,
`__vslot14_assembleInstruction` encodes into it), +0x40 array of 0x1c-byte control-flow entries, +0x50 0x28-byte header block, +0x54 control-flow output block,
+0x58 instruction count, +0x5c control-flow count, +0x60 loop stack (0xc bytes per level), +0x70 current loop id.

## 4. Vertex instruction format (PVS) - CONFIRMED against the documentation

`R300VMachineAssembler__encodeDestinationWord` / `encodeSourceOperand` / `encodeDualMathOperands` build the 4-word PVS instruction exactly as the
`R5xx_Acceleration_v1.5.pdf` section 'PVS Opcode & Destination Operand Description' / 'PVS Source Operand Description' / 'Dual Math Instruction' define it:

* word 0: bits 5:0 opcode, bit 6 `PVS_DST_MATH_INST` (the code ORs 0x40 for math-engine operations), bit 7 `PVS_DST_MACRO_INST`, bits 11:8 destination register type (table `DAT_001b2ad0`), bit 12 `ADDR_MODE_1`, bits 19:13 destination offset, bits 23:20 write enables (the code sets them from lane bytes that are 0), bit 24 `VE_SAT`, bit 25 `ME_SAT`, bit 26 `PRED_ENABLE`, bit 27 `PRED_SENSE`, bit 28 `DUAL_MATH_OP`;
* words 1..3: source operands: bits 1:0 register type, bit 3 `ABS`, bit 4 `ADDR_MODE_0`, bits 12:5 offset, swizzles 3 bits per lane at bits 13/16/19/22, negate X..W bits 25..28, bits 30:29 `ADDR_SEL`, bit 31 `ADDR_MODE_1`;
* the final step of `vslot14_assembleInstruction` sets bit 26 (predicate enable) and bit 27 (sense) from the instruction's predicate kind (`inst + 0x11c` 2 / 3).

## 5. Vtables (slot k is at `*object + 4*k`)

Slot semantics recovered by the callers/callees (names carry the slot number where the role is only partly known). Entries shown as 'inline empty method' are
4-byte `blr` functions in `__textcoal_nt` that the ledger does not list.

#### R300MachineAssembler (R3xx pixel shader) (vtable `0x1eb698`)

| slot | offset | target |
|---|---|---|
| 0 | 0x0 | `R300MachineAssembler__dtor` |
| 1 | 0x4 | `MachineAssembler__dtor_196e3c` |
| 2 | 0x8 | `R300MachineAssembler__vslot2_exceedsInstructionLimit` |
| 3 | 0xc | `R300MachineAssembler__vslot3_noOp` |
| 4 | 0x10 | `R300MachineAssembler__vslot4_finishProgram` |
| 5 | 0x14 | `R300MachineAssembler__vslot5_beginProgram` |
| 6 | 0x18 | `R300MachineAssembler__vslot6_noOp` |
| 7 | 0x1c | `0x195470` (4-byte inline empty method) |
| 8 | 0x20 | `R300MachineAssembler__vslot8_returnsTrue` |
| 9 | 0x24 | `R300MachineAssembler__vslot9_getRecordBufferWords` |
| 10 | 0x28 | `0x1cd69c` (4-byte inline empty method) |
| 11 | 0x2c | `0x1cd6a0` (4-byte inline empty method) |
| 12 | 0x30 | `R300MachineAssembler__vslot12_assembleNodeAndMarkChildren` |
| 13 | 0x34 | `R300MachineAssembler__assembleBlock` |
| 14 | 0x38 | `R300MachineAssembler__assembleAluInstruction` |
| 15 | 0x3c | `R300MachineAssembler__assembleAsOpcodeInfo31` |
| 16 | 0x40 | `R300MachineAssembler__vslot16_noOp` |
| 17 | 0x44 | `0x1cd6a4` (4-byte inline empty method) |
| 18 | 0x48 | `R300MachineAssembler__callSlot14` |
| 19 | 0x4c | `R300MachineAssembler__vslot19_noOp` |
| 20 | 0x50 | `R300MachineAssembler__vslot20_noOp` |
| 21 | 0x54 | `R300MachineAssembler__vslot21_noOp` |
| 22 | 0x58 | `R300MachineAssembler__vslot22_noOp` |
| 23 | 0x5c | `R300MachineAssembler__emitTexRecord` |
| 24 | 0x60 | `0x1d8cb4` (4-byte inline empty method) |
| 25 | 0x64 | `0x1961b0` (4-byte inline empty method) |
| 26 | 0x68 | `FUN_000e3140` |
| 27 | 0x6c | `0x1d8cb8` (4-byte inline empty method) |
| 28 | 0x70 | `0x1d8cbc` (4-byte inline empty method) |
| 29 | 0x74 | `R300MachineAssembler__vslot29_noOp` |
| 30 | 0x78 | `0x1d8cc0` (4-byte inline empty method) |
| 31 | 0x7c | `0x1d8cc4` (4-byte inline empty method) |
| 32 | 0x80 | `0x1d8cc8` (4-byte inline empty method) |
| 33 | 0x84 | `0x1d8ccc` (4-byte inline empty method) |
| 34 | 0x88 | `FUN_000e2fd8` |
| 35 | 0x8c | `psnLiteralAddressFromRegisterWord` |
| 36 | 0x90 | `R300MachineAssembler__vslot36_noOp` |
| 37 | 0x94 | `0x1d8cd0` (4-byte inline empty method) |
| 38 | 0x98 | `R300MachineAssembler__vslot38_returnsFalse` |
| 39 | 0x9c | `R300MachineAssembler__vslot39_noOp` |
| 40 | 0xa0 | `R300MachineAssembler__vslot40_noOp` |
| 41 | 0xa4 | `R300MachineAssembler__vslot41_noOp` |
| 42 | 0xa8 | `R300MachineAssembler__vslot42_noOp` |
| 43 | 0xac | `R300MachineAssembler__vslot43_noOp` |
| 44 | 0xb0 | `R300MachineAssembler__vslot44_noOp` |
| 45 | 0xb4 | `0x195644` (4-byte inline empty method) |
| 46 | 0xb8 | `0x195648` (4-byte inline empty method) |
| 47 | 0xbc | `0x1d8cd4` (4-byte inline empty method) |
| 48 | 0xc0 | `R300MachineAssembler__initNopAluRecord` |
| 49 | 0xc4 | `R300MachineAssembler__setRsColorFields` |
| 50 | 0xc8 | `R300MachineAssembler__setRsTexCoordFields` |
| 51 | 0xcc | `0x1d8cd8` (4-byte inline empty method) |
| 52 | 0xd0 | `0x1d8cec` (4-byte inline empty method) |
| 53 | 0xd4 | `R300MachineAssembler__rgbSelectForLiteralFloat` |
| 54 | 0xd8 | `R300MachineAssembler__alphaSelectForLiteralFloat` |
| 55 | 0xdc | `0x1d8d00` (4-byte inline empty method) |
| 56 | 0xe0 | `0x1d8d08` (4-byte inline empty method) |
| 57 | 0xe4 | `0x1d8d14` (4-byte inline empty method) |
| 58 | 0xe8 | `0x1d8d2c` (4-byte inline empty method) |
| 59 | 0xec | `R300MachineAssembler__rgbSelectForSrcpSwizzle` |
| 60 | 0xf0 | `R300MachineAssembler__alphaSelectForSrcpComponent` |
| 61 | 0xf4 | `R300MachineAssembler__rgbSelectForAlphaSource` |
| 62 | 0xf8 | `R300MachineAssembler__rgbSelectForSourceSwizzle` |
| 63 | 0xfc | `R300MachineAssembler__alphaSelectForAlphaSource` |
| 64 | 0x100 | `R300MachineAssembler__alphaSelectForColorComponent` |
| 65 | 0x104 | `R300MachineAssembler__vslot65_declareNodeRegisters` |
| 66 | 0x108 | `0x1d8d44` (4-byte inline empty method) |
| 67 | 0x10c | `0x1d8d48` (4-byte inline empty method) |
| 68 | 0x110 | `0x1d8d4c` (4-byte inline empty method) |
| 69 | 0x114 | `0x1d8d88` (4-byte inline empty method) |
| 70 | 0x118 | `R300MachineAssembler__setAluSourceAddresses` |
| 71 | 0x11c | `R300MachineAssembler__setAluSourceSelectsAndModifiers` |
| 72 | 0x120 | `R300MachineAssembler__setTempDestination` |
| 73 | 0x124 | `R300MachineAssembler__setOutputDestination` |
| 74 | 0x128 | `0x1d8dc0` (4-byte inline empty method) |
| 75 | 0x12c | `R300MachineAssembler__setRgbOpcode` |
| 76 | 0x130 | `R300MachineAssembler__setAlphaOpcode` |
| 77 | 0x134 | `R300MachineAssembler__setAlphaTempWriteEnable` |
| 78 | 0x138 | `R300MachineAssembler__closeTextureIndirectionLevel` |
| 79 | 0x13c | `0x1d8dc4` (4-byte inline empty method) |
| 80 | 0x140 | `0x1d8dc8` (4-byte inline empty method) |
| 81 | 0x144 | `R300MachineAssembler__writeHeaderRecord` |
| 82 | 0x148 | `0x1d8dcc` (4-byte inline empty method) |
| 83 | 0x14c | `0x1d8dd0` (4-byte inline empty method) |
| 84 | 0x150 | `0x1d8dd4` (4-byte inline empty method) |
| 85 | 0x154 | `R300MachineAssembler__noteFetchTextureUnit` |
| 86 | 0x158 | `R300MachineAssembler__resolveSourceRegister` |
| 87 | 0x15c | `R300MachineAssembler__beginNextRecord` |

#### R520MachineAssembler (R5xx pixel shader) (vtable `0x1eb9a0`)

| slot | offset | target |
|---|---|---|
| 0 | 0x0 | `R520MachineAssembler__dtor` |
| 1 | 0x4 | `R520MachineAssembler__deleting_dtor` |
| 2 | 0x8 | `R300MachineAssembler__vslot2_exceedsInstructionLimit` |
| 3 | 0xc | `R300MachineAssembler__vslot3_noOp` |
| 4 | 0x10 | `R520MachineAssembler__vslot4_finishProgram` |
| 5 | 0x14 | `R520MachineAssembler__vslot5_beginProgram` |
| 6 | 0x18 | `R300MachineAssembler__vslot6_noOp` |
| 7 | 0x1c | `0x195470` (4-byte inline empty method) |
| 8 | 0x20 | `R300MachineAssembler__vslot8_returnsTrue` |
| 9 | 0x24 | `R520MachineAssembler__vslot9_getRecordWordsUsed` |
| 10 | 0x28 | `0x1cd69c` (4-byte inline empty method) |
| 11 | 0x2c | `0x1cd6a0` (4-byte inline empty method) |
| 12 | 0x30 | `R300MachineAssembler__vslot12_assembleNodeAndMarkChildren` |
| 13 | 0x34 | `R300MachineAssembler__assembleBlock` |
| 14 | 0x38 | `R300MachineAssembler__assembleAluInstruction` |
| 15 | 0x3c | `R300MachineAssembler__assembleAsOpcodeInfo31` |
| 16 | 0x40 | `R300MachineAssembler__vslot16_noOp` |
| 17 | 0x44 | `0x1cd6a4` (4-byte inline empty method) |
| 18 | 0x48 | `R300MachineAssembler__callSlot14` |
| 19 | 0x4c | `R300MachineAssembler__vslot19_noOp` |
| 20 | 0x50 | `R300MachineAssembler__vslot20_noOp` |
| 21 | 0x54 | `R300MachineAssembler__vslot21_noOp` |
| 22 | 0x58 | `R300MachineAssembler__vslot22_noOp` |
| 23 | 0x5c | `R520MachineAssembler__vslot23_emitTexRecord` |
| 24 | 0x60 | `R520MachineAssembler__vslot24_assembleWithTarget` |
| 25 | 0x64 | `R520MachineAssembler__vslot25_assembleLoop` |
| 26 | 0x68 | `R520MachineAssembler__vslot26_assembleThenAppendRecord` |
| 27 | 0x6c | `R520MachineAssembler__vslot27_assembleIf` |
| 28 | 0x70 | `R520MachineAssembler__vslot28_endLoop` |
| 29 | 0x74 | `R520MachineAssembler__vslot29_patchBranchTarget` |
| 30 | 0x78 | `R520MachineAssembler__vslot30_assembleThenTerminate` |
| 31 | 0x7c | `R520MachineAssembler__vslot31_assembleChildrenAndMark` |
| 32 | 0x80 | `R520MachineAssembler__vslot32_assembleBranchEnd` |
| 33 | 0x84 | `0x1d8f54` (4-byte inline empty method) |
| 34 | 0x88 | `FUN_000e2fd8` |
| 35 | 0x8c | `0x19fcc4` (4-byte inline empty method) |
| 36 | 0x90 | `R300MachineAssembler__vslot36_noOp` |
| 37 | 0x94 | `R520MachineAssembler__vslot37_closeBranch` |
| 38 | 0x98 | `R520MachineAssembler__vslot38_appendBranchRecord` |
| 39 | 0x9c | `R520MachineAssembler__vslot39_appendLoopStartRecord` |
| 40 | 0xa0 | `R300MachineAssembler__vslot40_noOp` |
| 41 | 0xa4 | `R300MachineAssembler__vslot41_noOp` |
| 42 | 0xa8 | `R300MachineAssembler__vslot42_noOp` |
| 43 | 0xac | `R300MachineAssembler__vslot43_noOp` |
| 44 | 0xb0 | `R300MachineAssembler__vslot44_noOp` |
| 45 | 0xb4 | `0x195644` (4-byte inline empty method) |
| 46 | 0xb8 | `0x195648` (4-byte inline empty method) |
| 47 | 0xbc | `R520MachineAssembler__clearCurrentRecord` |
| 48 | 0xc0 | `R520MachineAssembler__initNopAluRecord` |
| 49 | 0xc4 | `R520MachineAssembler__setRsColorFields` |
| 50 | 0xc8 | `R520MachineAssembler__setRsTexCoordFields` |
| 51 | 0xcc | `0x1d8e10` (4-byte inline empty method) |
| 52 | 0xd0 | `0x1d8e24` (4-byte inline empty method) |
| 53 | 0xd4 | `R520MachineAssembler__vslot53_selectBitsForLiteralFloat` |
| 54 | 0xd8 | `R520MachineAssembler__vslot54_selectBitsForAlphaLiteral` |
| 55 | 0xdc | `R520MachineAssembler__vslot55_tryEncodeImmediateLiteral` |
| 56 | 0xe0 | `0x1d8e38` (4-byte inline empty method) |
| 57 | 0xe4 | `0x1d8e5c` (4-byte inline empty method) |
| 58 | 0xe8 | `0x1d8e74` (4-byte inline empty method) |
| 59 | 0xec | `R520MachineAssembler__vslot59_selectForSrcpSwizzle` |
| 60 | 0xf0 | `R520MachineAssembler__vslot60_selectForSrcpComponent` |
| 61 | 0xf4 | `R520MachineAssembler__vslot61_selectForAlphaSource` |
| 62 | 0xf8 | `R520MachineAssembler__vslot62_selectForSourceSwizzle` |
| 63 | 0xfc | `R520MachineAssembler__vslot63_selectForAlphaComponent` |
| 64 | 0x100 | `R520MachineAssembler__vslot64_selectForColorComponent` |
| 65 | 0x104 | `R520MachineAssembler__vslot65_declareNodeRegisters` |
| 66 | 0x108 | `R520MachineAssembler__vslot66_selectBitsForLiteralLanes` |
| 67 | 0x10c | `R520MachineAssembler__vslot67_selectForConstantLanes` |
| 68 | 0x110 | `0x1d8e90` (4-byte inline empty method) |
| 69 | 0x114 | `0x1d8ecc` (4-byte inline empty method) |
| 70 | 0x118 | `R520MachineAssembler__setAluSourceAddresses` |
| 71 | 0x11c | `R520MachineAssembler__vslot71_setAluSourceSelectsAndModifiers` |
| 72 | 0x120 | `R520MachineAssembler__vslot72_setTempDestination` |
| 73 | 0x124 | `R520MachineAssembler__vslot73_setOutputDestination` |
| 74 | 0x128 | `R520MachineAssembler__vslot74_setPredicateSetDestination` |
| 75 | 0x12c | `R520MachineAssembler__setRgbOpcode` |
| 76 | 0x130 | `R520MachineAssembler__setAlphaOpcode` |
| 77 | 0x134 | `R520MachineAssembler__vslot77_setRecordByteB` |
| 78 | 0x138 | `0x1d8e8c` (4-byte inline empty method) |
| 79 | 0x13c | `R520MachineAssembler__vslot79_setTexCompareFlags` |
| 80 | 0x140 | `R520MachineAssembler__vslot80_setRecordByte9` |
| 81 | 0x144 | `R520MachineAssembler__writeHeaderRecord` |
| 82 | 0x148 | `0x1d8f04` (4-byte inline empty method) |
| 83 | 0x14c | `0x1d8f34` (4-byte inline empty method) |
| 84 | 0x150 | `0x1d8e44` (4-byte inline empty method) |
| 85 | 0x154 | `0x1d8f50` (4-byte inline empty method) |
| 86 | 0x158 | `R520MachineAssembler__vslot86_resolveSourceRegister` |
| 87 | 0x15c | `R520MachineAssembler__beginNextRecord` |

#### R300VMachineAssembler (R3xx vertex shader) (vtable `0x1eb800`)

| slot | offset | target |
|---|---|---|
| 0 | 0x0 | `MachineAssembler__dtor_19b9ac` |
| 1 | 0x4 | `R300VMachineAssembler__deleting_dtor` |
| 2 | 0x8 | `R300VMachineAssembler__vslot2_exceedsLimits` |
| 3 | 0xc | `0x1d8df8` (4-byte inline empty method) |
| 4 | 0x10 | `R300VMachineAssembler__finishProgram` |
| 5 | 0x14 | `R300VMachineAssembler__init` |
| 6 | 0x18 | `R300VMachineAssembler__vslot6_setLoopStack` |
| 7 | 0x1c | `R300VMachineAssembler__logStatistics` |
| 8 | 0x20 | `0x1d8dec` (4-byte inline empty method) |
| 9 | 0x24 | `R300VMachineAssembler__copyControlFlowToOutput` |
| 10 | 0x28 | `0x1cd69c` (4-byte inline empty method) |
| 11 | 0x2c | `0x1cd6a0` (4-byte inline empty method) |
| 12 | 0x30 | `0x19a468` (4-byte inline empty method) |
| 13 | 0x34 | `R300VMachineAssembler__assembleBlock` |
| 14 | 0x38 | `R300VMachineAssembler__vslot14_assembleInstruction` |
| 15 | 0x3c | `R300VMachineAssembler__vslot15_assembleUnlessConstantMove` |
| 16 | 0x40 | `R300VMachineAssembler__vslot16_noOp` |
| 17 | 0x44 | `0x1cd6a4` (4-byte inline empty method) |
| 18 | 0x48 | `R300VMachineAssembler__vslot18_callSlot14` |
| 19 | 0x4c | `R300VMachineAssembler__vslot19_callSlot14` |
| 20 | 0x50 | `0x19a8cc` (4-byte inline empty method) |
| 21 | 0x54 | `0x19a8d0` (4-byte inline empty method) |
| 22 | 0x58 | `0x19aca8` (4-byte inline empty method) |
| 23 | 0x5c | `0x19acac` (4-byte inline empty method) |
| 24 | 0x60 | `R300VMachineAssembler__vslot24_assembleWithTarget` |
| 25 | 0x64 | `R300VMachineAssembler__vslot25_assembleOrFail` |
| 26 | 0x68 | `FUN_000e3140` |
| 27 | 0x6c | `R300VMachineAssembler__vslot27_assembleOrFail` |
| 28 | 0x70 | `R300VMachineAssembler__vslot28_assembleChildOrFail` |
| 29 | 0x74 | `R300VMachineAssembler__vslot29_endIfBlock` |
| 30 | 0x78 | `R300VMachineAssembler__vslot30_assembleBlockThenSlot40` |
| 31 | 0x7c | `0x19aad8` (4-byte inline empty method) |
| 32 | 0x80 | `0x19ab58` (4-byte inline empty method) |
| 33 | 0x84 | `0x19ab5c` (4-byte inline empty method) |
| 34 | 0x88 | `FUN_000e2fd8` |
| 35 | 0x8c | `0xe2ac4` (4-byte inline empty method) |
| 36 | 0x90 | `0x19ac28` (4-byte inline empty method) |
| 37 | 0x94 | `R300VMachineAssembler__vslot37_patchControlFlowTarget` |
| 38 | 0x98 | `R300VMachineAssembler__vslot38_appendCallEntry` |
| 39 | 0x9c | `R300VMachineAssembler__vslot39_appendBranchEntry` |
| 40 | 0xa0 | `R300VMachineAssembler__vslot40_endControlFlowBlock` |
| 41 | 0xa4 | `0x1d8e0c` (4-byte inline empty method) |
| 42 | 0xa8 | `R300VMachineAssembler__vslot42_noOp` |
| 43 | 0xac | `R300VMachineAssembler__vslot43_beginLoop` |
| 44 | 0xb0 | `R300VMachineAssembler__vslot44_endLoopBody` |
| 45 | 0xb4 | `R300VMachineAssembler__vslot45_endLoop` |
| 46 | 0xb8 | `R300VMachineAssembler__vslot46_leaveLoop` |
| 47 | 0xbc | `R300VMachineAssembler__clearCurrentInstruction` |
| 48 | 0xc0 | `R300VMachineAssembler__vslot48_declareAndAssemble` |
| 49 | 0xc4 | `R300VMachineAssembler__vslot49_advanceInstruction` |

#### R520VMachineAssembler (R5xx vertex shader, flow control) (vtable `0x1eb8d0`)

| slot | offset | target |
|---|---|---|
| 0 | 0x0 | `MachineAssembler__dtor_19df54` |
| 1 | 0x4 | `R520VMachineAssembler__deleting_dtor` |
| 2 | 0x8 | `R300VMachineAssembler__vslot2_exceedsLimits` |
| 3 | 0xc | `0x1d8df8` (4-byte inline empty method) |
| 4 | 0x10 | `R300VMachineAssembler__finishProgram` |
| 5 | 0x14 | `R520VMachineAssembler__init` |
| 6 | 0x18 | `R520VMachineAssembler__vslot6_setLoopStack` |
| 7 | 0x1c | `R300VMachineAssembler__logStatistics` |
| 8 | 0x20 | `0x1d8dec` (4-byte inline empty method) |
| 9 | 0x24 | `R300VMachineAssembler__copyControlFlowToOutput` |
| 10 | 0x28 | `0x1cd69c` (4-byte inline empty method) |
| 11 | 0x2c | `0x1cd6a0` (4-byte inline empty method) |
| 12 | 0x30 | `R520VMachineAssembler__vslot12_visitNode` |
| 13 | 0x34 | `R300VMachineAssembler__assembleBlock` |
| 14 | 0x38 | `R300VMachineAssembler__vslot14_assembleInstruction` |
| 15 | 0x3c | `R300VMachineAssembler__vslot15_assembleUnlessConstantMove` |
| 16 | 0x40 | `R300VMachineAssembler__vslot16_noOp` |
| 17 | 0x44 | `0x1cd6a4` (4-byte inline empty method) |
| 18 | 0x48 | `R300VMachineAssembler__vslot18_callSlot14` |
| 19 | 0x4c | `R300VMachineAssembler__vslot19_callSlot14` |
| 20 | 0x50 | `0x19a8cc` (4-byte inline empty method) |
| 21 | 0x54 | `0x19a8d0` (4-byte inline empty method) |
| 22 | 0x58 | `0x19aca8` (4-byte inline empty method) |
| 23 | 0x5c | `0x19acac` (4-byte inline empty method) |
| 24 | 0x60 | `R520VMachineAssembler__vslot24_assembleWithPredicateSet` |
| 25 | 0x64 | `R520VMachineAssembler__vslot25_assembleConditionalBlock` |
| 26 | 0x68 | `FUN_000e3140` |
| 27 | 0x6c | `R520VMachineAssembler__vslot27_assembleLoopHeader` |
| 28 | 0x70 | `R520VMachineAssembler__vslot28_assembleIfEnd` |
| 29 | 0x74 | `R300VMachineAssembler__vslot29_endIfBlock` |
| 30 | 0x78 | `R520VMachineAssembler__vslot30_assembleBlockThenSlot40` |
| 31 | 0x7c | `R520VMachineAssembler__vslot31_assembleWithPredicateRestore` |
| 32 | 0x80 | `R520VMachineAssembler__vslot32_assembleWithPredicateClear` |
| 33 | 0x84 | `R520VMachineAssembler__vslot33_noOp` |
| 34 | 0x88 | `FUN_000e2fd8` |
| 35 | 0x8c | `0xe2ac4` (4-byte inline empty method) |
| 36 | 0x90 | `0x19ac28` (4-byte inline empty method) |
| 37 | 0x94 | `R520VMachineAssembler__vslot37_closeConditional` |
| 38 | 0x98 | `R300VMachineAssembler__vslot38_appendCallEntry` |
| 39 | 0x9c | `R300VMachineAssembler__vslot39_appendBranchEntry` |
| 40 | 0xa0 | `R300VMachineAssembler__vslot40_endControlFlowBlock` |
| 41 | 0xa4 | `0x1d8e0c` (4-byte inline empty method) |
| 42 | 0xa8 | `R300VMachineAssembler__vslot42_noOp` |
| 43 | 0xac | `R300VMachineAssembler__vslot43_beginLoop` |
| 44 | 0xb0 | `R300VMachineAssembler__vslot44_endLoopBody` |
| 45 | 0xb4 | `R300VMachineAssembler__vslot45_endLoop` |
| 46 | 0xb8 | `R300VMachineAssembler__vslot46_leaveLoop` |
| 47 | 0xbc | `R300VMachineAssembler__clearCurrentInstruction` |
| 48 | 0xc0 | `R300VMachineAssembler__vslot48_declareAndAssemble` |
| 49 | 0xc4 | `R300VMachineAssembler__vslot49_advanceInstruction` |

## 6. Not established

* The meaning of most bits of the R520 packed select words (+0x24 / +0x28) and of the record fields `+0x34..+0x38`, the CF record fields beyond those named, and
  the R520 'neutral format' mapping to the hardware register words (the R5xx fragment ISA is not among the documents available here).
* The 'opcode info' table `PTR_DAT_001e913c` (0x38-byte entries: +0xc hardware opcode, +0x34 instruction class) was only read through the assemblers that index it; its
  per-opcode contents were not extracted.
* Opcodes `0xb6` and `0xef` have no object in the static initialiser.

## Round 3: D1 (register-allocator liveness/interference, PVS encoders, visitAlu, peephole driver)

Names are in `names_D1_*.tsv` (regenerate with the specs; every `use` row is a def-use web checked by the dataflow gate). Tiers: CONFIRMED = read from code / documented
format; INFERRED = role clear from use.

**Block liveness (`HwLimits__computeBlockLiveness`, was `HwLimits__vslot81`, 0x138694).** Bitsets hold 4 bits per register (`reg * 4 + component`), allocated in the
compiler arena as `{arena, wordCount, bitCount, words...}` (words start at +0xc from the allocation, i.e. at `allocation + 1` is the word-count field). Per block
(`program + 0x37c` DList; `FUN_000ec4f0(program)` returns the 1-based array of blocks): `+0x100` live-in (starts as the upward-exposed uses), `+0x104` live-out, `+0x108`
defs. A first pass over each block's instruction groups (instruction `+8` = next, flag `0x4` of `+0x14` = the group continues) sets use bits for every source component
(component set = `FUN_000f3398`: swizzle -> byte per component) that has not already been written in the block, and def bits for the destination components; a second pass
iterates to a fixpoint: `liveIn |= (OR of successors' liveIn) & ~defs`. Program flag `+0x30 |= 0x1000` marks liveness as computed.

**Interference graph (`HwLimits__buildInterferenceGraph`, was `HwLimits__vslot82`, 0x1322a8).** Walks each block backwards from its live-out set. Parameters: the
`ColorGraph` (`FUN_00135334` adds a symmetric edge, `FUN_00134bf0` maps a register through the disjoint-set representative when `useCoalesced`), `fixedRegCount` (the first
nodes are made pairwise interfering up front), `regCount`, `useCoalesced`. For each definition the destination components get edges to everything live (with exceptions for
copies and for the registers listed in `excludedRegs0..3`); a worklist (`{arena, vector header, membership bitset}`) of registers is drained at group boundaries.

**PVS encoders (R300VMachineAssembler).** `encodeSourceOperand`, `encodeDestinationWord`, `encodeDualMathOperands` build the 4-word PVS instruction exactly as
section 4 describes; the new names label the fields: `swizzleXField..swizzleWField` (bits 13/16/19/22), `negXField..` (bits 25..28), `addrMode0Bit`/`addrMode1Bit`
(bits 4/31), `addrSelBits` (30:29), `offsetBits` (12:5), `srcTypeBits` (1:0). `encodeDualMathOperands` writes word 3: bits 1:0 source register type, 12:5 offset, 15:13 and
18:16 the two select fields, 25/26 the negates, 24:21 the math opcode (+ bit 2 for opcodes >= 16), 28:27 the destination component select derived from the write mask
(`0x10101`, `0x1000101`, `0x1010001`, `0x1010100`), 20:19 the destination offset relative to the target bias. `findFoldableMovePair` finds, inside one instruction
group, the vector-engine instruction and the math-engine instruction and, when the math source is the vector result, inserts a `IrMovFloat` (0x31) to a fresh temporary and
rebinds the math source to it.

**`R300MachineAssembler__assembleAluInstruction` (visitor slot 14, 0x1981ac).** `classifyAluOperation` returns bit 0 (has an rgb part), bit 1 (alpha part), bit 2 and
bit 4 plus two pairs of output words; the per-source loop (`srcIdx` = 1..numSources) resolves each source: a source defined by a mix/mad is looked through (`defSrc1Inst`,
`defSrc2Inst`), other sources are matched against the three source-address slots held in the assembler (`this[7..9]` rgb slot instructions, `this[10..12]` alpha slot
instructions, `this[14..16]` / `this[18..20]` their register ids, `this[0x20]` / `this[0x21]` used-slot masks, searched with `slotNo` 1..3) and the visitor methods
`0xec..0x100` (`rgbSelectFor...` / `alphaSelectFor...`) fill `rgbSelect` / `rgbMod` / `alphaSelect` / `alphaMod` per source; constant sources use slot 55 (`tryEncodeImmediateLiteral`).

**Peephole combine (`FudoPs/KhanPs/KhanVs__peepholeCombine`, HwLimits vtable slot 28, was `vslotXX`).** Arguments `(this, inst, consumerSrcIndex, inst2, program, ...)`: `inst2` is the
producer, `inst` its consumer through source `consumerSrcIndex`. The body tries a fixed sequence of pattern helpers (`FUN_0014abdc`, `FUN_00155a60`, ... each takes the producer and
the program and returns non-zero when it rewrote it) gated by `Compiler__isOptionEnabled(program[2], id)` (ids 0x1b, 0x1c, 0x1d, 0x38, 0x39, 0x3c, 0x3d seen), commits each rewrite
through `FUN_00146610`, bumps the use-count epoch `program[0x11e]` and returns whether anything changed. One explicit pattern is spelled out in FudoPs: an `IrFetchTextureMapKill` (0x77)
whose source 1 is a single-use `IrAddFloat` of two identical-register terms is rewritten into a form with `IrMulFloat`-style operands (option 0x3d).

**Gate finds worth remembering.** The dataflow gate rejected webs that cross loop-carried flag words (`uVar22 = piVar13[5]` flags re-read at the loop test), a split of
`local_88` in `encodeSourceOperand` (changes the instruction count) and `uVar19` there (new -Wuninitialized warning): those variables keep their Ghidra names.
