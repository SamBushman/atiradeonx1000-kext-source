# libGLProgrammability: shader ISA, interpreter, constant folder and PowerPC/AltiVec runtime compiler

Reverse-engineered from the transcribed corpus (`part_013..019.c`) of the Tiger PPC `libGLProgrammability`. Everything here is read off the
code; the evidence column says where. Names in `names_R5_*.tsv` follow this document.

## 1. The instruction stream ("pp stream")

One shader instruction is a 0x11c-byte record (`inst`, stride `0x47` words: `_InterpreterEmulateOp` returns `inst + 0x47`, or NULL after the
program's last instruction, `*(*(emulator+0xd80)+4)`).

| offset | field | evidence |
|---|---|---|
| +0x00 | opcode (index into the table below) | `iVar21 = *inst`; `_glpDisassemble1Op` prints `_ppstreamOpString[word0 >> 18 & 0xff]` |
| +0x04 | byte0 = saturate flag; byte1 = ?; byte2 = update-condition-code flag (+6); byte `+5` = vector dimension 1..4 | CompileAV appends `_glpOpSaturateAVRTC` when byte0 set; dot/length/normalize loops run `inst[+5]` components; `_InterpreterWriteDestination` last argument is `*(byte*)(inst+6)` |
| +0x0c..+0x2f | destination operand (9 words, section 2) | `_InterpreterWriteDestination(machine, inst[3..0xb], ...)` |
| +0x30 | source operand count | `iVar14 = inst[0xc]` |
| +0x34 + 0x24*k | source operand k (9 words) | `_InterpreterLoadSource(machine, inst[0xd + 9k .. 0x15 + 9k], ...)` |
| +0x118 (word 0x46) | offset of this instruction's generated code inside the code buffer | `instruction[0x46] = codeCursor - codeBuffer` in CompileAV |
| (array) | the instructions are a contiguous array with stride 0x11c, starting at program info +0x120; `inst + 0x47` words is the next one | `instructionCursor = inst + 0x47` at the end of the CompileAV loop; branch targets are `index * 0x11c` |

### Opcode table (`_ppstreamOpString`, 0x71 entries, `__DATA,__data +0xda8`)

| opcode | mnemonic |
|---|---|
| 0x00 | MOV |
| 0x01 | LIT |
| 0x02 | ABS |
| 0x03 | CEI |
| 0x04 | FRC |
| 0x05 | FLR |
| 0x06 | FWD |
| 0x07 | SSG |
| 0x08 | ANY |
| 0x09 | ALL |
| 0x0a | NOT |
| 0x0b | NSE |
| 0x0c | SQT |
| 0x0d | RSQ |
| 0x0e | RCP |
| 0x0f | RCC |
| 0x10 | EX2 |
| 0x11 | EXP |
| 0x12 | LEN |
| 0x13 | LG2 |
| 0x14 | LOG |
| 0x15 | NRM |
| 0x16 | RAD |
| 0x17 | DEG |
| 0x18 | SCS |
| 0x19 | SIN |
| 0x1a | COS |
| 0x1b | TAN |
| 0x1c | ASN |
| 0x1d | ACS |
| 0x1e | ATN |
| 0x1f | ADD |
| 0x20 | SUB |
| 0x21 | MOD |
| 0x22 | MUL |
| 0x23 | MLC |
| 0x24 | ANL |
| 0x25 | ORL |
| 0x26 | XRL |
| 0x27 | DOT |
| 0x28 | DP3 |
| 0x29 | DP4 |
| 0x2a | DPH |
| 0x2b | DST |
| 0x2c | MIN |
| 0x2d | MAX |
| 0x2e | XPD |
| 0x2f | RFL |
| 0x30 | STR |
| 0x31 | SEQ |
| 0x32 | SGE |
| 0x33 | SGT |
| 0x34 | SLE |
| 0x35 | SLT |
| 0x36 | SNE |
| 0x37 | SFL |
| 0x38 | POW |
| 0x39 | SEL |
| 0x3a | DIV |
| 0x3b | FFW |
| 0x3c | LRP |
| 0x3d | CLM |
| 0x3e | CMP |
| 0x3f | MAD |
| 0x40 | SMS |
| 0x41 | SWZ |
| 0x42 | TEX |
| 0x43 | TXP |
| 0x44 | TXB |
| 0x45 | TXPB |
| 0x46 | TXL |
| 0x47 | TXPL |
| 0x48 | ARL |
| 0x49 | ARR |
| 0x4a | ARA |
| 0x4b | BRA |
| 0x4c | CAL |
| 0x4d | RET |
| 0x4e | FTR |
| 0x4f | KIL |
| 0x50 | DDX |
| 0x51 | DDY |
| 0x52 | DP2 |
| 0x53 | DP2A |
| 0x54 | BRK |
| 0x55 | IF |
| 0x56 | LOOP |
| 0x57 | REP |
| 0x58 | ELSE |
| 0x59 | ENDIF |
| 0x5a | ENDLOOP |
| 0x5b | ENDREP |
| 0x5c | PK2H |
| 0x5d | PK2US |
| 0x5e | PK4B |
| 0x5f | PK4UB |
| 0x60 | POPA |
| 0x61 | PUSHA |
| 0x62 | TXD |
| 0x63 | UP2H |
| 0x64 | UP2US |
| 0x65 | UP4B |
| 0x66 | UP4UB |
| 0x67 | X2D |
| 0x68 | RFR |
| 0x69 | CONT |
| 0x6a | WHILE |
| 0x6b | ENDWHILE |
| 0x6c | MTC |
| 0x6d | DSL |
| 0x6e | NOOP |
| 0x6f | EXPE |
| 0x70 | LOGE |

The names are the ARB/NV fragment-program mnemonics extended with GLSL-compiler operations (`DIV`, `LRP`, `CLM`, `SWZ`, `MTC` (matrix transform),
`ANL/ORL/XRL`, `NSE` (noise), `SMS`, `RFR`, `WHILE/ENDWHILE`, ...). The interpreter switch (`_InterpreterEmulateOp`) and the constant folder
(`_EmulateOp`) are indexed directly by this opcode; e.g. case 0x22 (`MUL`) generalises to scalar*vector, vector*matrix, matrix*vector and
matrix*matrix products depending on the operands' dimension bytes.

### The packed program ("pp" program / shader) used by the printers

`_glpPPDisassemble(program)` and `_glpPPShaderToProgramString(shader, ...)` print the compact form: header words (index in 32-bit words), each
table entry is 8 bytes (two words; the register id is the ushort at byte +6 of the second word):

| header word | meaning | evidence |
|---|---|---|
| 0 | target: 0x8804 ARB fragment program, 0x8620 ARB vertex program, 0x8b30 fragment shader, 0x8b31 vertex shader | the `!!ARBfp1.0` / `!!ARBvp1.0` / `!!ARBfragmentshader` / `!!ARBvertexshader` header strings |
| 4 | temporary count (`TEMP tmpN`) | printed with the TEMP strings |
| 6 | address register count (`ADDRESS adr0, adr1`) | |
| 8 / 9 | attribute count / offset (`ATTRIB attN = fragment.* / vertex.*`) | |
| 10 / 0xb | parameter count / offset (`PARAM prmN`, `prmN[size]` for arrays) | |
| 0xc / 0xd | output count / offset (`OUTPUT resN = result.*`) | |
| 0xe | number of parameter arrays (array-size table) | `piVar14 = malloc(shader[0xe] << 2)` |
| 0x12 / 0x13 | option count / offset (`OPTION ARB_position_invariant`, `ARB_fog_exp`, `ARB_fog_exp2`, `ARB_fog_linear`, `ARB_precision_hint_fastest/nicest`, `APPLE_no_runtime_compile`, `APPLE_no_altivec`, `NV_fragment_program/2`, `NV_vertex_program2/3`, `ARB_draw_buffers`) | switch on the option byte |
| 0x14 / 0x15 | instruction count / offset (compact instructions of 2..10 words printed by `_glpDisassemble1Op` / `_glpDisassemble2Op`) | |
| 0x18 / 0x19 | raster-state record count / offset (`STATE ALPHA_TEST PP_LESS ...`, blend factors `PP_BLEND_*`, stencil ops `PP_STENCIL_*`, `PP_FUNC_*`) | the state records fixed-function raster state folded into the program |

The compact instruction: word 0 bits 31..29 source count, bits 25..18 opcode; word 1 bits 23..20 saturate/clamp flags, 19..18 precision,
28..23 size/type; word 2 bits 11..10 vector size - 1, bits 16..13 write mask; words 3.. destination and sources (2 words each, high bit =
invalid operand). `_glpPPShaderToProgramString` first builds two tables (`paramNumbers`, `paramArrayPos`) that renumber constant registers into
`prmN` names and mark parameter-array heads, then prints each instruction through `_glpDisassemble2Op`.

## 2. The 9-word operand descriptor (36 bytes)

Used for the destination and for each source; passed as nine integer arguments to `_InterpreterLoadSource` /
`_InterpreterWriteDestination` / `_PPCRuntimeCompilerLoadSourceNO|AV` / `_PPCRuntimeCompilerLoadRegister` / `_PPCRuntimeCompilerSetRegister`.

| word | name used in the tables | meaning (evidence) |
|---|---|---|
| 0 | opOffsets / componentOffsets | pointer to a table of 4 ints per vec4 slot: byte offsets of the x,y,z,w components inside the storage class (`param_2[element*4 + swizzle]` in `_InterpreterLoadSource`) |
| 1 | opBank / bankIndex | index of the 0xc-byte bank record at `program+0x80+0xc*bank`: `+0x80` base, `+0x84` count, `+0x88` index mask (relative addressing) |
| 2 | opSwizzle | four component selects: x = bits 31..24, y = 23..16, z = 15..8, w = 7..0 |
| 3 | opIndexInfo | high 16 bits: signed relative-address offset added to the address register (`machine+0xa40`) |
| 4 | opStorage | high 16 bits: storage class (index into the base-pointer table at `emulator+0xd84`; class 1 = fragment output slots, 2 = interpolated attributes, 9 = machine scalars), byte 2: negate, byte 3: relative-addressing flag |
| 5 | opFlags5 | byte 0: vector flag (operand has an explicit width), byte 1: component count; only counted for widest-operand search (`elementCount`) |
| 6 | opType | value type: 0/1 float, 3/4 signed int (converted with the 2^52 bias trick) |
| 7 | (destination) write mask | bits 0x1000000/0x2000000/0x4000000/0x8000000 = write-enable x/y/z/w; byte 2 = condition compare code |
| 8 | (destination) condition swizzle | bytes for components z,w of the condition-register swizzle (x,y live in word 7) |

Condition codes: `machine+0xa44..0xa47` hold the four condition-register components: 3 = NaN, 2 = negative, 1 = positive, 0 = zero
(`_InterpreterWriteDestination`). `_InterpreterTestCR` compares them with code 0 TR, 1 EQ, 2 GE, 3 GT, 4 LE, 5 LT, 6 NE, 7 FL.

## 3. Emulator / interpreter

* `machine` (`int*`): `*machine` = emulator context. Emulator context: `+0xd80` program info (+0x38 target: 0x8804 ARB fragment program / 0x8b30 GLSL fragment shader, otherwise vertex; +0x3c raster-op stage flags: bit0 alpha test, bits1-2 depth/stencil, bit3 blend, bit5 logic op, bit6 buffer mask; +0x34 state bits; +0x120 instruction list; +0xb8/+0xbc/+0xd8/+0xdc strides), `+0xd84` base-pointer table by storage class, `+0xd88` current output vertex/fragment, `+0xd9c` GL state (viewport scale/bias at +0x1b70.. +0x1b88), `+0xda0/+0xda4` fragment attribute slope/base pointers, `+0xdf0` interpreter machine.
* Machine words: `[0x28c]` fragment x offset, `[0x28f]` 1/w factor, `[0x290]` address register, `0xa44..0xa47` condition register bytes, `0xa48..` final fragment colour (words `[0x292..0x295]`), `0xa58` kill/discard flag, raster-op machine at `0xa24`.
* `_InterpreterRun(emulator, count)`: runs `count` vertices/fragments; fragments go through `_InterpreterWriteFinalFragmentToBuffer` (alpha test, depth/stencil, unpack framebuffer pixel, blend, logic op, buffer mask, pack); vertices compute the clip code (x<-w 0x10, x>=w 0x20, y<-w 4, y>=w 8, z<-w 1, z>w 2), the perspective divide and the viewport transform with scale/bias from the GL state.
* `_InterpreterPackPixel/UnpackPixel`: framebuffer format bits 0x8000000 = 4 x float, 0x8000 = RGBA8, 0x400 = RGB5A1.
* `_EmulateOp(context, inst, hashSet)`: constant folder: looks the operands up in a hash set of 0x28-byte register-type-info records (`+0x14` = value known, `+0x18..0x27` = constant vec4) and, when every source is a known constant, evaluates the opcode at compile time (`destInfo+0x18`), else marks the destination unknown.

## 4. The runtime compiler (shader to PowerPC / AltiVec)

`_PPCRuntimeCompilerCreate` callocs 0xe54 bytes. Fields (word offsets in parentheses are `compiler[N]`):

| offset | field |
|---|---|
| +0x000.. | 0x20 scalar register records (FPRs), stride 0x38 |
| +0x700.. | 0x20 vector register records (VRs), stride 0x38 (`+0x708` is the record's descriptor copy) |
| +0xe00/+0xe04 | variable-info array and count (`_PPCRuntimeCompilerInitialiseVariableInfo`) |
| +0xe08/+0xe0c | = -1 (cleared by Initialise) |
| +0xe14 | embedded raster-op machine (`_PPCRasterOpMachineInitialise`) |
| +0xe1c | texture sampler (`_PPCTextureSamplerCreate`) |
| +0xe20 | emulator context |
| +0xe24 | program info (`AttachEmulatorProgram`) |
| +0xe28 | current instruction |
| +0xe2c | code buffer base |
| +0xe30 | code write cursor |
| +0xe34 | start of the instruction code after the prolog |
| +0xe40 | branch target (epilog / loop) used by the emitted `b` |
| +0xe44 | register-use counter (LRU stamp) |
| +0xe48 | compile pass counter |
| +0xe4c | vector mode (1 = AltiVec: registers are indexed +0x20) |
| +0xe50 | option flags (`SetOptionFlags`; bit 0/1 pre-mark registers busy, bit 2 enable data caching) |

Register record (0x38 bytes) written by `_PPCRuntimeCompilerSetRegister`:

| +0 | dirty flag (0 = holds data, DirtyRegister sets it) |
| +4 | element (vec4 slot of the operand) |
| +8..+0x2b | copy of the operand descriptor (9 words) |
| +0x2c | in-use flag |
| +0x30 | last-use stamp (`compiler+0xe44`, incremented) |
| +0x34 | record flag |

`_PPCRuntimeCompilerRegisterContainsData` returns 0 (no), 1 (identical), 2 (all four components present), 3 (partial). `BackupRegister` finds the
least recently used clean register and `SwizzleRegisterAV` permutes components with `vperm`.

Code generation: most operations are *chunks*: `_glpRTCAddAChunk(chunk, cursor)` copies a zero-terminated array of precompiled PowerPC/AltiVec
words (`_glpOpMulAVRTC`, `_glpOpDp4AVRTC`, `_glpOpSaturateAVRTC`, `_glpNegateSourceARTC` ...) into the buffer and returns the word count; the
rest is emitted word by word by OR-ing register fields into templates (`rt << 21 | ra << 16 | rb << 11 | opcode`), e.g.
`_PPCRuntimeCompilerCalculateIndirectAddress` emits `addi r15,r16,imm; andi. r15,r15,mask; mulli r15,r15,16; lis r23,hi; ori r23,r23,lo; add r15,r15,r23`
(the indirect register-file address). Scalar (NO) code uses FPR opcodes (`lfs` 0xc0.., `stfs` 0xd0.., `fmr` 0xfc..), AltiVec (AV) code uses
primary-opcode-4 words and `lvx/stvx` (0x7c..). The buffer starts as 0x2000 bytes and `_glpDCBRealloc` grows it when fewer than 3000 bytes remain.

## 5. Tables

`names_R5_interp.tsv`, `names_R5_emu.tsv`, `names_R5_jit.tsv` hold the renames; tiers: CONFIRMED (the code shows it), INFERRED, UNKNOWN.
