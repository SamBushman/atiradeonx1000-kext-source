# GLDriver functions, round 5, fork I3 (unclassified functions below 0xc0000)

Scope: the `unclassified` rows of `subsystem_map.tsv` whose address is below 0xc0000 and that no `names*.tsv` / `class_methods.tsv` row names
(420 at the start). Names are in `names_I3_func.tsv` (every row carries tier and evidence); this file records the method, the findings that
span several functions, and what is left. Tiers: CONFIRMED = the code or a table shows it, INFERRED = role clear from use.

## Findings that cross function boundaries

### 1. The ARB program IR opcode table drives the fragment translators (CONFIRMED)

`__DATA,__data+0x1c30` is an array of 16-byte entries, one per ARB program IR opcode (entry k at +0x10*k, word 1 = `k << 24 | flags`, word 3 at
+0xc = translator pointer or 0). Opcode numbers are the mnemonic table of `notes_shader_formats.md` section 3. The non-null handlers:

| handler | opcodes |
|---|---|
| FUN_0003fd80 `fragmentTranslateSimpleOp` | FWD, DDX, BRK, ELSE, ENDIF, ENDREP, CONT, ENDWHILE |
| FUN_00040370/40374 `fragmentTranslateScalarMath` | EX2, EXP, LG2, LOG, ASN, ACS, EXPE, LOGE |
| FUN_00041310 / 41510 | SIN COS TAN / RAD DEG |
| 41750, 41c00, 42e00, 43df0, 43f60, 44360, 44500, 44ac0, 3ff40, 401b0 | MOD, ATN, RFR, FFW, DST, IF, RFL, WHILE, REP, DDY |

`fragmentInstructionToIL` (0x46e90) handles the remaining opcodes itself and calls five more translators (ADD/SUB/MUL/MLC/DIV -> 46a30, ANY -> 467a0,
ALL -> 46180, SEL -> 457f0, DSL -> 44c90). The shared helpers are `fpilReserveTokens` (0x3ef50), `fpilEmitInstruction` (0x3fbf0),
`fpilTranslateDestination` / `fpilTranslateSource` (0x3f750 / 0x3f1c0). The translator object is 0x38 bytes: [0] program IR, [5] flags,
[9] error word (1 = out of memory, 3 = bad register file), [10..12] the IL token vector {data, count, capacity}.

### 2. GL_ATI_fragment_shader API and its replay path (CONFIRMED)

Entry points in 0xa12b0-0xa3490, all on the shader table at ctx+0x1154 (0x78-byte shader objects at table+0x88, current shader ptr ctx+0x1144,
Begin flag ctx+0x1134, pass counter ctx+0x1138): glGen/Bind/Delete/Begin/End FragmentShader, glPassTexCoordATI, glSampleMapATI,
glColorFragmentOp1/2/3ATI, glAlphaFragmentOp1/2/3ATI, glSetFragmentShaderConstantATI. PassTexCoord vs SampleMap are told apart by the record
kind nibble: the `atifsEmitTextureOps` compiler emits `mov` (0x47) for kind 0 and `texld` (0x5d) otherwise, and the replay function
`atifsReplayTextureOps` (0x3e4d0) calls glPassTexCoordATI_impl for `(record & 0xf0) == 0`, glSampleMapATI_impl otherwise.
`atifsReplayProgram` (0x3eb70) rebuilds a stored shader image through these entry points.

### 3. ARB_vertex/fragment_program object API (CONFIRMED enumerants)

0xa0290-0xa0d70: the program table at ctx+0x112c (0x18-byte entries {id, target, length, ..., object}, refcounted): glGenPrograms (0xa0570),
glBindProgram (0xa0380, targets 0x8620 / 0x8804), glDeleteProgramsARB (0xa0d70), glGetProgramivARB (0xa05f0), glProgramStringARB (0xa0300).

### 4. EXT_vertex_shader emitter table 1 (CONFIRMED indices)

`extvsPrepareHardwareProgram` dispatches `PTR_FUN_001db9b8[op - 0x8782]`: 33 entries at `__DATA,__data+0x29b8`, same order as the evs table at
+0x2b0c (INDEX .. MOV 0x8799, then SWIZZLE 0x879a, WRITEMASK 0x879b, 0x879c, 0x879d, LIT, DST, EXPP, LOGP, MOVA). Names `extvsEmit<Op>`; the
hardware op argument of `extvsEncodeSourceOperand` matches the op (1 dot, 2 mul, 3 add, 4 mad, 6 frc, 7 max, 8 min, 9 sge, 10 slt, 5 dst-vector,
0xd mova conversion; math-engine ops flagged with the extra argument 1: 1 expp, 2 logp, 6 rcp, 0xb exp, 0xc log).

**Possible swap in earlier names.** `glExtractComponentEXT_impl` (0x54270) passes opcode 0x879c and zeroes the destination write enables except the
chosen component itself; `glInsertComponentEXT_impl` (0x543b0) passes 0x879d and stores the component number at instruction+0x40. The evs emitter
for 0x879d (FUN_00074ed0) uses +0x40 to replicate one SOURCE component (what an extract does) and the one for 0x879c (FUN_00075060) rebuilds the
DESTINATION write enables (what an insert does). By GL semantics the two impl names look swapped; I named the emitters by opcode
(`evsEmitOp879c/879d`, `extvsEmitOp879c/879d`) and left the impl names alone.

### 5. Program-record emitters and accessors (CONFIRMED layout)

`arbEmitRecord{1,2,3}Src_op<NN>` (0x83e10-0x864e0) claim the next 0x10-byte record of ctx+0x3c8 and bit-pack: word 0 = dst file (<<8), index
(7 bits <<13), write enable bits 20..23, opcode byte at +3; source word = file (4 bits), index (<<5), four 3-bit selects at 13/16/19/22,
negate bits 25..28. `recordGet/Set*` (0x77850, 0x78f10, 0x798f0, 0x79a20, 0x79a90) read/write exactly those fields. The IL-token twins
`arbEmitIl<Op>` (0x65ea0-0x6ec10) write the IL opcode (dp4 0x23, mov 0x47, mul 0x49, add 3, mad 0x40, min 0x44, max 0x41, set 0x56 with
compare 2 / 5, rnd 0x54, rcp 0x51, rsq 0x55, exp 0x2d, exn 0x2c, pow 0x4e) as the first token; `arbEmitIlEnd` (0x28) and the header emitter
bracket a program. They are installed into the engine state (ctx+0x14fc..0x156c) by FUN_000a7050 per hardware generation and called through it
by the fixed-function vertex program generator.

### 6. Misc identifications

* S3TC: `dxt1DecodeColorIndex` (0x1c1c0), `dxtDecompressImage` (0x1d1e0, formats 0xc/0xd/0xe), `dxt5EncodeAlphaBlock` (0x1be50),
  `gldCompressedImageBytes` (0x303d0).
* ring helpers: `copyIndices16Swapped_{prefetch,dcbz}` copy 16-bit index arrays with swapped halfwords (the call sites in gld_drawVertexArray).
* ARB program text printer `arbProgramIrToText` (0xf620, 27 KB) and its helpers (notes_shader_formats.md).
* 24-bit float helpers `floatToFp24` / `fp24ToFloat` (0x4a7d0 / 0x4a830), half-float `floatToHalfBits` (0x1d7c0).
* `gldValidatePolygonMode` (0x4ea70) was listed as unidentified in notes_gld_functions.md section 3.

## Method

1. List unclassified functions (`subsystem_map.tsv` unclassified, name still FUN_, not in a `func` row, not in `class_methods.tsv`, address < 0xc0000).
2. Rank by size and by number of callers; resolve indirect callers by looking for the function's address in `data/*.c` tables (the opcode table above,
   the emitter tables at +0x29b8/+0x2b0c, the nl_symbol_ptr table).
3. Classify with callers/callees, enumerants, strings and table position, name families by their table index or opcode constant, and write
   `func` rows with the evidence.

## Left

Of the 420 original targets, 276 are named (290 `func` rows: some rows name neighbours outside the 420) and 144 (about 70 KB) are not. What is
left, by area (all have a subsystem label in `subsystem_map.tsv` unless listed under "no label"):

* record-program optimizer / register allocator, 0x77500-0x7b0d0 (`vertex-program-regalloc`): FUN_0007b0d0 (5.6 KB, the optimizer driver:
  rewrites record opcodes 4 -> 0x80 and 0xb -> 0x81, walks the dependency lists), FUN_00078f80, FUN_0007a4a0, FUN_0007aae0, FUN_0007a1a0,
  FUN_00077860, FUN_00078b80; the helpers it uses are named (`recordGet*`, `depList*`, `regBinding*`, `record*Register*`).
* fragment program assembler, 0xa6500-0xaec40 (`fragment-program-assembler`): FUN_000ac720 (7.9 KB) and FUN_000aec40 (3.9 KB) pack IL
  instructions into hardware words (called by FUN_000afe40 per IL opcode group), FUN_000abd10, FUN_000a9070, FUN_000a8340, FUN_000a8a00.
* state upload family (`command-ring` / `gl-state-and-hooks`): FUN_0009be00 / FUN_0009cc30 (dirty bit 0x20 of gldValidateState, through
  FUN_000bd9a0), FUN_00027990, FUN_0002d2b0 (float clamp + half-float state words), FUN_00022eb0, FUN_00023700 and the per-unit texture state
  helpers 0x4b520-0x4c720.
* compiler support 0xbde70-0xbfcc0 (`compiler`): checks a magic word (0xABADF00D complement) in its argument, i.e. compiler IR objects.
* no label: FUN_00007810, FUN_00018090, FUN_0001a010, FUN_0004b520, FUN_0004c720, FUN_0004fd80, FUN_000a64d0.

Local variables: most large functions reuse scratch variables for several roles (evsAssignVertexInputs alone has 1100 placeholders in about
25 variables with 5 to 60 distinct definitions each), so naming them needs `use` rows per segment; only single-role variables and parameters
were named (names_I3_locals.tsv).
