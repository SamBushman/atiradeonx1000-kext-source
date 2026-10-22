# Shader text formats in ATIRadeonX1000GLDriver

What the three shader-printing functions of the GLDriver decode, recovered from the code and the data sections (`data/DATA___data.c`,
`data/cstrings.c`) and not from any documentation. Every statement names its evidence. "CONFIRMED" = read straight from the code or the printed
strings; "INFERRED" = the role is clear from use but nothing names it.

Functions covered (addresses are the corpus names; renamed variables are in `names_R3_*.tsv`):

| function | role |
|---|---|
| `FUN_0000f620` | prints a *program object* (ARB vertex/fragment program or GLSL shader object) as ARB-assembly-like text; returns a malloc'ed string |
| `FUN_0000bfa0` | double -> shortest decimal text (Steele-White style), used for float constants |
| `FUN_0000c8a0` | output buffer guard: grows the buffer by 0x800 when fewer than 0x100 bytes remain |
| `FUN_0000c930` `FUN_0000ca50` `FUN_0000df50` `FUN_0000ce90` `FUN_0000d240` | instruction / declaration suffix printers |
| `FUN_0000cdf0` `FUN_0000cb90` | decimal integer printer (recursive digit writer) |
| `FUN_0000d380` `FUN_0000e1f0` `FUN_0000f250` | destination operand, source operand and texture operand printers |
| `FUN_000ddbcc` | disassembler of an IL-style *token stream* (printf-based) |
| `FUN_000d183c` | dump of an R300-family "pixel shader" object (three formats) |

## 1. The program object read by FUN_0000f620 (CONFIRMED)

All table offsets below are in units of 8 bytes: a table is `program + program[k] * 8` (the code writes `program + program[k] * 2` on a `uint *`).
Entries are 8 bytes (two words); the halfword at entry+6 is the register id.

| `program[i]` | meaning | evidence |
|---|---|---|
| `[0]` | target: 0x8620 ARBvp1.0, 0x8804 ARBfp1.0, 0x8b30 fragment shader object, 0x8b31 vertex shader object | header strings `!!ARBvp1.0`, `!!ARBfp1.0`, `!!ARBfragmentshader`, `!!ARBvertexshader`; anything else prints `Unkown Target (error)` (sic) |
| `[4]`,`[5]` | TEMP count, table offset | loop printing `TEMP` / `LONG TEMP` / `SHORT TEMP` |
| `[6]` | ADDRESS register count | prints `ADDRESS adr0, adr1 ...;` |
| `[8]`,`[9]` | ATTRIB count, table offset | `ATTRIB att<id> = fragment.|vertex.<binding>` |
| `[10]`,`[0xb]` | PARAM count, table offset | `PARAM prm<n>[...] = ...` |
| `[0xc]`,`[0xd]` | OUTPUT count, table offset | `OUTPUT res<id> = result.<binding>` |
| `[0xe]`,`[0xf]` | PARAM array count, descriptor table | `PARAM prm<n>[<len>] = { ... }` groups |
| `[0x10]`,`[0x11]` | TEMP array count, descriptor table | `tmp<n>[<i>]` groups |
| `[0x12]`,`[0x13]` | OPTION count, table offset (first byte of an entry = option id) | `OPTION ARB_position_invariant;` ... |
| `[0x14]`,`[0x15]` | instruction count, table offset | instruction loop |
| `[0x1b]` | offset of the constant pool: 4 floats (16 bytes) per constant | `{a, b, c, d}` printed with FUN_0000bfa0 |

Shader objects (`0x8b30`/`0x8b31`) get blank lines between sections; plain assembly programs (`isAssemblyProgram`) do not.

OPTION ids: 0 ARB_position_invariant, 1 ARB_fog_exp, 2 ARB_fog_exp2, 3 ARB_fog_linear, 4 ARB_precision_hint_fastest, 5 ARB_precision_hint_nicest,
6 APPLE_no_runtime_compile, ... 0xa NV_vertex_program2, 0xb NV_vertex_program3, 0xc ARB_draw_buffers, 0xd ARB_fragment_program_shadow.

### TEMP / OUTPUT entry word 0
Bits 29..31 = precision: 0 plain, 1 `LONG`, 2 `SHORT` (OUTPUT: `LONG OUTPUT` / `SHORT OUTPUT`). Bits 24..28 feed the type suffix `:<n><F|X|I|B><32|16|12>`
(FUN_0000ce90, see section 4). TEMP entries carry the id at entry+6. TEMPs and PARAMs that belong to an array are printed `tmp<n>[<i>]` /
`prm<n>[<i>]`: a pre-pass builds two tables indexed by register id (printed number and group state 0 = starts an array, 1 = member, -1 = plain).

### ATTRIB entry
Low 4 bits of the first halfword select the binding: 1 `position`, 2 `color.primary`, 3 `color.secondary`, 4 `normal`, 5 `fogcoord`,
6 `weight[n]`, 7 `texcoord[n]`, 8 `matrixindex[n]`, 9 `attrib[n]`, 0xa `material.<front|back>.<ambient|diffuse|specular|emission|shininess>`
(bit 0 = face, bits 12..15 = property), 0xb `frontfacing`; `n` = word & 0x1f. Prefix `fragment.` for 0x8804/0x8b30, `vertex.` for 0x8620/0x8b31.

### PARAM entry (low 5 bits = kind)
1 `program.local[n]` (n = low halfword), 2 `program.env[n]`, 3 `state.light[n].<ambient|diffuse|specular|position|spot.direction|attenuation|half|spotcutoff>`
(bits 8..11), 4 `state.lightprod[n].<front|back>.<ambient|diffuse|specular>` (bit 8, bits 9..10), 5 `state.material.<...>` or `state.lightmodel.scenecolor`,
6 `state.lightmodel.ambient`, 7 `state.texgen[n].eye.<s|t|r|q>` (bits 5..7), 8 `state.texgen[n].object.<s|t|r|q>`, 9 `state.texenv[n].color`, 0xa `state.clip[n].plane`,
0xb `state.fog.color`, 0xc `state.fog.params`, 0xd `state.point.size`, 0xe `state.point.attenuation`, 0xf `state.depth.range`, 0x10 `state.matrix.<mvp|projection|color[n]|modelview[n]|texture[n]|program[n]>`
with optional `inverse.`, `transpose.`, `invtrans.` (bits 14..15) and `.row[m]` (bits 12..13), 0x12 `state.normalscale`, 0x11 constant vector: bits 26..28 of the
word: 0/1 four floats `{a, b, c, d}`, 2 fixed data (`{-- Fixed constant data not currently supported --}`), 3/4 four integers.

### OUTPUT entry
Bits 16..19 = binding: 1 `result.position`, 2 `result.fogcoord`, 3 `result.pointsize`, 4 `result.color` (+ `.front.primary`/`.back.primary` for vertex targets by bit 0,
or `[n]` = bits 1..3 for fragment targets with n >= 2), 5 `result.color` secondary, 6 `result.texcoord[n]`, 7 `result.depth`, 8 `result.eyePosition`, 9 `result.clipVertex`,
0xa `result.attrib[n]`.

## 2. Instruction record (CONFIRMED)
Records follow each other in the instruction table. A record is `nSrc + 2` entries of 8 bytes, where `nSrc = word0 >> 29`
(loop: `entry += (word0 >> 29) + 2`).

| entry | word 0 | word 1 |
|---|---|---|
| 0 header | bits 0..17 instruction index (0 for `main:`), bits 18..25 opcode, bits 29..31 source count | bit 20 saturate, bit 21 CC register 1, bit 22 CC update, bits 18..19 precision R/H/X, bits 23..25 element type, bits 26..27 vector size - 1, bit 28 second size |
| 1 destination | register file (bits 17..19: 1 tmp, 3 res, 4 adr), write mask bits 13..16 (x y z w; 0x1e000 = all), condition (bits 28..30) | relative addressing: bit 31, adr register bit 30, adr component bits 28..29, signed offset, low halfword = register index |
| 2.. sources | bit 27 negate (`-`), bit 26 absolute (`|x|`), bits 23..25 register file (0 att, 1 tmp, 2 prm, 3 res, 4 adr), swizzle: four 2-bit selectors at bits 21, 19, 17, 15 (x y z w), size bits 12..14 | register index / relative addressing as the destination |

BRA (0x4b) and CAL (0x4c) read the target instruction index from header word 1 & 0x3ffff; the printer collects the distinct targets, sorts them and prints
`label_<n>` and, in shader objects, a trailing `# Target: <index>` comment. The condition is printed ` (TR|EQ|GE|GT|LE|LT|NE|FL)` followed by a four-component
swizzle, and for the SWZ instruction (0x41) the per-component selectors (`x y z w -x -y -z -w 1 0 -1`, 4 bits each) come from the following entry
(FUN_0000e1f0 with its last argument 1). Texture instructions print `texture[<unit>], <CUBE|3D|RECT|2D|1D|SHADOWRECT|SHADOW2D|SHADOW1D>` (FUN_0000f250: unit = word & 0x1f,
target = bits 5..7).

## 3. Opcodes of the program IR (mnemonic table at 0x1d9004, CONFIRMED)

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

Operand shapes (which `case` group of FUN_0000f620 prints the opcode): a destination then 1, 2, 3 or 4 sources; `0x41` SWZ, `0x42`/`0x43`/`0x44.. TEX family` use the texture operand
printer; BRA/CAL print a label; RET and the structured-flow ops print only the mnemonic. The group membership is in the `switch(opcode)` of `FUN_0000f620`.

## 4. Suffix and number printers (CONFIRMED)

| function | prints | arguments |
|---|---|---|
| `FUN_0000ca50(cursor, p)` | precision letter after the mnemonic: 1 `R`, 2 `H`, 3 `X` | word 1 bits 18..19 |
| `FUN_0000c930(cursor, cc, cc1, sat)` | `C` (condition-code update), `1` (second CC register), `_SAT` | word 1 bits 22, 21, 20 |
| `FUN_0000df50(cursor, n-1, second, type)` | `:<n>[:<n>]<F|X|I|B>` | word 1 bits 26..27, 28, 23..25 |
| `FUN_0000ce90(cursor, n-1, second, type, bits)` | same plus `32`, `16` or `12` | declaration words: bits 24..25, -, 26..28, 29..31 |
| `FUN_0000d240(cursor, n-1, second)` | `:<n>[:<n>]` size suffix of a source (nothing when n-1 = 3 and the flag is clear) | source word 0 bits 12..13, 14 |
| `FUN_0000cdf0(cursor, int)` | signed decimal; returns the length | |
| `FUN_0000bfa0(.., out, size, value, tolerance)` | shortest decimal text of a double within `tolerance`; exponent form `e-N` outside about 1e-4..1e15; returns the pointer to the NUL (NULL if the text does not fit) | |

## 5. Token stream disassembled by FUN_000ddbcc (CONFIRMED mnemonics, INFERRED operand grouping)

`disassembler[2]` is the stream pointer, `disassembler[0x87]` the indentation depth; the opcode is the low 16 bits of the token (`< 0xbf`). Each case prints the
mnemonic through `FUN_000da9fc`, then operands through one of the helpers: `FUN_000ddb7c` (dst + 1 src), `FUN_000ddb14` (dst + 2 src), `FUN_000dda98` (dst + 3 src),
`FUN_000dccd4` (comparison suffix), `FUN_000dd1f8` / `FUN_000dd6bc` (single operands), `FUN_000db2f4` (function label), and ends with `FUN_000da984` (end of instruction).
The mnemonic set is that of AMD's IL (ATI Intermediate Language: `dcl_*`, `sample_*`, `texld`, `memexport`, `resinfo`, `imul_high`, ...). Cases with a formatted suffix:
`dclpp`/`dclv` `_param(n)` (bits 16..23), `dcl_resource` `_id(n)` (bits 16..23), `load` `_id(n)` (bits 16..28), `resinfo` `_id(n)` (bits 16..27, bit 28 `_uint`),
`memimport` `_elem(n)` (bits 16..21), `memexport` `_exportStream(n)_stateStride(b)_elemOffset(m)` (bits 16..21, 22, 23..28),
`dcl_max_output_vertex_count` `(n)` (bits 16..29), `dcl_input` interpolation (bits 19..21: constant, linear, linear_centroid, linear_noperspective, linear_noperspective_centroid),
`def` four floats or four integers, `dcl_immed_cb` a count then `0x%x` literals, and opcode 0xf, a pseudo-op that prints an inline text comment (length in the low 16 bits of the next word, in 4-byte units).

| opcode | mnemonic | operands |
|---|---|---|
| 0x01 | abs | dst, src |
| 0x02 | acos | dst, src |
| 0x03 | add | dst, src, src |
| 0x04 | asin | dst, src |
| 0x05 | atan | dst, src |
| 0x06 | break | (no operands) |
| 0x07 | breakc | (no operands) |
| 0x08 | call | (no operands) |
| 0x09 | callnz | (no operands) |
| 0x0a | clamp | dst, src, src, src |
| 0x0b | clg | dst, src |
| 0x0c | cmov | dst, src, src |
| 0x0d | cmp | dst, src, src, src |
| 0x0e | colorclamp | dst, src |
| 0x0f |  );  |  |
| 0x10 | continue | (no operands) |
| 0x11 | continuec | (no operands) |
| 0x12 | cos | dst, src |
| 0x13 | crs | dst, src, src |
| 0x14 | dclarray | (no operands) |
| 0x15 | dcldef | (no operands) |
| 0x16 | dclpi | (no operands) |
| 0x17 | dclpin | (no operands) |
| 0x18 | dclpp | (no operands) |
| 0x19 | dclpt | (no operands) |
| 0x1a | dclv | (no operands) |
| 0x1b | dclvout | (no operands) |
| 0x1c | def | FUN_000dd6bc |
| 0x1d | defb | (no operands) |
| 0x1e | det | dst, src |
| 0x1f | dist | dst, src, src |
| 0x20 | div | dst, src, src |
| 0x21 | dp2add | dst, src, src, src |
| 0x22 | dp3 | dst, src, src |
| 0x23 | dp4 | dst, src, src |
| 0x24 | dst | dst, src, src |
| 0x25 | dsx | dst, src |
| 0x26 | dsy | dst, src |
| 0x27 | else | (no operands) |
| 0x28 | end | (no operands) |
| 0x29 | endif | (no operands) |
| 0x2a | endloop | (no operands) |
| 0x2b | endmain | (no operands) |
| 0x2c | exn | dst, src |
| 0x2d | exp | dst, src |
| 0x2e | expp | dst, src |
| 0x2f | faceforward | dst, src, src, src |
| 0x30 | flr | dst, src |
| 0x31 | frc | dst, src |
| 0x32 | func | (no operands) |
| 0x33 | fwidth | dst, src |
| 0x34 | ifc | (no operands) |
| 0x35 | ifnz  | (no operands) |
| 0x36 | (formatted, see source) |  |
| 0x37 | kill | (no operands) |
| 0x38 | len | dst, src |
| 0x39 | lit | dst, src |
| 0x3a | ln | dst, src |
| 0x3b | lod | dst, src |
| 0x3c | log | dst, src |
| 0x3d | logp | dst, src |
| 0x3e | loop | (no operands) |
| 0x3f | lrp | dst, src, src, src |
| 0x40 | mad | dst, src, src, src |
| 0x41 | max | dst, src, src |
| 0x42 | memexport | dst, src |
| 0x43 | memimport | dst, src |
| 0x44 | min | dst, src, src |
| 0x45 | mmul | dst, src, src |
| 0x46 | mod | dst, src, src |
| 0x47 | mov | dst, src |
| 0x48 | mova | dst, src |
| 0x49 | mul | dst, src, src |
| 0x4a | noise | dst, src |
| 0x4b | nop | (no operands) |
| 0x4c | nrm | dst, src |
| 0x4d | pireduce | dst, src |
| 0x4e | pow | dst, src, src |
| 0x50 | project | dst, src |
| 0x51 | rcp | dst, src |
| 0x52 | reflect | dst, src, src |
| 0x53 | ret | (no operands) |
| 0x54 | rnd | dst, src |
| 0x55 | rsq | dst, src |
| 0x56 | set | dst, src, src |
| 0x57 | sgn | dst, src |
| 0x58 | sin | dst, src |
| 0x59 | sincos | dst, src |
| 0x5a | sqrt | dst, src |
| 0x5b | sub | dst, src, src |
| 0x5c | tan | dst, src |
| 0x5d | texld | dst, src |
| 0x5e | texldb | dst, src, src |
| 0x5f | texldd | dst, src, src, src |
| 0x60 | texldms | dst, src |
| 0x61 | texweight | dst, src |
| 0x62 | transpose | dst, src |
| 0x63 | trc | dst, src |
| 0x64 | dxsincos | dst, src, src, src |
| 0x65 | break_logicalz | (no operands) |
| 0x66 | break_logicalnz | (no operands) |
| 0x67 | call_logicalz | (no operands) |
| 0x68 | call_logicalnz | (no operands) |
| 0x69 | case  | (no operands) |
| 0x6a | continue_logicalz | (no operands) |
| 0x6b | continue_logicalnz | (no operands) |
| 0x6c | default | (no operands) |
| 0x6d | endswitch | (no operands) |
| 0x6e | endfunc | (no operands) |
| 0x6f | if_logicalz  | (no operands) |
| 0x70 | if_logicalnz  | (no operands) |
| 0x71 | whileloop | (no operands) |
| 0x72 | switch | (no operands) |
| 0x73 | ret_dyn | (no operands) |
| 0x74 | ret_logicalz  | (no operands) |
| 0x75 | ret_logicalnz  | (no operands) |
| 0x76 | dcl_immed_cb | (no operands) |
| 0x77 | dcl_indexed_temp_array | (no operands) |
| 0x78 | dcl_input_primitive | (no operands) |
| 0x79 | dcl_literal | FUN_000da904, FUN_000dd1f8, FUN_000da904 |
| 0x7a | dcl_max_output_vertex_count | (no operands) |
| 0x7b | dcl_odepth | (no operands) |
| 0x7c | dcl_output_topology | (no operands) |
| 0x7d | dcl_output | (no operands) |
| 0x7e | dcl_input | FUN_000da904 |
| 0x7f | dcl_vprim | (no operands) |
| 0x80 | dcl_resource | (no operands) |
| 0x81 | cut | (no operands) |
| 0x82 | discard_logicalz | (no operands) |
| 0x83 | discard_logicalnz | (no operands) |
| 0x84 | emit | (no operands) |
| 0x85 | emitcut | (no operands) |
| 0x86 | load | dst, src |
| 0x87 | resinfo | dst, src |
| 0x88 | sample | dst, src |
| 0x89 | sample_b | dst, src, src |
| 0x8a | sample_g | dst, src, src, src |
| 0x8b | sample_l | dst, src |
| 0x8c | sample_c | dst, src, src |
| 0x8d | sample_c_lz | dst, src, src |
| 0x8e | inot | dst, src |
| 0x8f | ior | dst, src, src |
| 0x90 | ixor | dst, src, src |
| 0x91 | iadd | dst, src, src |
| 0x92 | imad | dst, src, src, src |
| 0x93 | imax | dst, src, src |
| 0x94 | imin | dst, src, src |
| 0x95 | imul | dst, src, src |
| 0x96 | imul_high | dst, src, src |
| 0x97 | ieq | dst, src, src |
| 0x98 | ige | dst, src, src |
| 0x99 | ilt | dst, src, src |
| 0x9a | inegate | dst, src |
| 0x9b | ine | dst, src, src |
| 0x9c | ishl | dst, src, src |
| 0x9d | ishr | dst, src, src |
| 0x9e | ushr | dst, src, src |
| 0x9f | udiv | dst, src, src |
| 0xa0 | umod | dst, src, src |
| 0xa1 | umad | dst, src, src, src |
| 0xa2 | umax | dst, src, src |
| 0xa3 | umin | dst, src, src |
| 0xa4 | ult | dst, src, src |
| 0xa5 | uge | dst, src, src |
| 0xa6 | umul | dst, src, src |
| 0xa7 | umul_high | dst, src, src |
| 0xa8 | ftoi | dst, src |
| 0xa9 | ftou | dst, src |
| 0xaa | itof | dst, src |
| 0xab | utof | dst, src |
| 0xac | and | dst, src, src |
| 0xad | cmov_logical | dst, src, src, src |
| 0xae | eq | dst, src, src |
| 0xaf | exp_vec | dst, src |
| 0xb0 | ge | dst, src, src |
| 0xb1 | log_vec | dst, src |
| 0xb2 | lt | dst, src, src |
| 0xb3 | ne | dst, src, src |
| 0xb4 | round_nearest | dst, src |
| 0xb5 | round_neginf | dst, src |
| 0xb6 | round_plusinf | dst, src |
| 0xb7 | round_zero | dst, src |
| 0xb8 | rsq_vec | dst, src |
| 0xb9 | sin_vec | dst, src |
| 0xba | cos_vec | dst, src |
| 0xbb | sqrt_vec | dst, src |
| 0xbc | dp2 | dst, src, src |
| 0xbe | scatter | (no operands) |


## 6. The pixel shader object dumped by FUN_000d183c (CONFIRMED prints, INFERRED field names)

`FUN_000d183c(shader, label, id)` first calls `FUN_000d0b68(shader, 1, id)` and then prints one of three formats, chosen by bit 4 of byte 0xf of the shader:
bit clear = "Loki NSF pixel shader dump" (with the raw `BEGIN_PSN` listing after it), bit set = "r520 neutral format pixel shader".
The object is an array of 0x48-byte records. Record 0 is the header; the following records are RS (kind 1), TEX (kind 2), ALU (kind 3) and predicate-setting ALU (kind 4) instructions.

Header record (0x48 bytes; offsets in bytes): `+0x08` record count, `+0x0e` UMRT_EN, `+0x10` start address, `+0x12` end address, `+0x14` stats-valid flag, `+0x16` levels,
`+0x18` RS instruction count, `+0x1a` TEX count, `+0x1c` ALU count, `+0x1e` ALU slots, `+0x20` CF instruction count, `+0x22` pixel size, `+0x24` highest constant,
`+0x26` nominal cycle count, `+0x2a..+0x39` sixteen texture-lookup counters. The raw listing labels the groups `R300PSN_INST_HEADER`, `R300PSN_INST_RS`, `R300PSN_INST_TEX`,
`R300PSN_INST_ALU`, `RGB_ADDR`, `ALPHA_ADDR`, `RGB_INST`, `ALPHA_INST` ("PSN" = the pixel-shader native format of the R300 family; the R5xx dump reuses it).

RS record (kind 1): `+0x04` halfword dest register for the texture coordinate, `+0x08` texture coordinate index (`txc%02ld`), `+0x09` texture-coordinate-present flag, `+0x0c` adjusted flag,
`+0x0e` write mask nibble (inverted, indexes the 5-character strings at 0x1dc279); `+0x06` halfword dest register for the colour, `+0x0a` colour index (`col%02ld`),
`+0x0b` colour source (0 none, 1 colour interpolator, 2 `fbuf`, 3 `back`), `+0x0d` biased flag, `+0x0f` write mask nibble.

TEX record (kind 2): `+0x04` semaphore wait (` sem_wait`), `+0x0b` ALU wait (` alu_wait`), `+0x1c` ignore-uncovered (` ign_unc`), `+0x1b` semaphore grab (` sem_grab`),
`+0x0c` dest register, `+0x0e` source register (bit 14 set = `r[AL+nn]` relative), `+0x10` and `+0x12` dx / dy registers, `+0x14` write mask bits, `+0x15` source swizzle,
`+0x16` dx swizzle, `+0x19` texture unit (`tex%02d`), `+0x1a` opcode (0 NOP, 1 lookup, 2 kill, 3 lookup_proj, 4 lookup_lodbias, 5 lookup_lod, 6 lookup_dxdy, 7 lookup_uncached),
`+0x1d..+0x1f` per-component write enables and swizzle flags, `+0x05`..`+0x09` predicate controls (` p.rgb`, ` !p.rrr` ... and `write_inactive`).

ALU record (kinds 3 and 4): RGB part `+0x0c` dest temp register, `+0x0e`/`+0x10`/`+0x12` source addresses 0..2, `+0x14` temp write mask, `+0x15` output write mask, `+0x16` output index
(kind 4 prints `pred.<mask> = (<|==|>=|!=)` instead of `out%d.`), `+0x2a..+0x2c` source selects 0..2, `+0x2d..+0x2f` source modifiers, `+0x30` pre-subtract/add op
(0 `1.0-2.0*x`, 1 `a-b`, 2 `a+b`, 3 `1.0-x`), `+0x31` RGB opcode (0 mad, 1 dp3, 2 dp4, 3 d2a, 4 min, 5 max, 7 cnd, 8 cmp, 9 frc, 10 sop, 0xb mdh, 0xc mdv),
`+0x32` output scale (0 none, 1 `*2`, 2 `*4`, 3 `*8`, 4 `/2`, 5 `/4`, 6 `/8`), `+0x33` clamp. Alpha part `+0x18` dest temp register, `+0x1a`/`+0x1c`/`+0x1e` source addresses,
`+0x20` temp write enable, `+0x21` output enable (`out%d.a`), `+0x22` output index, `+0x23` depth write, `+0x39..+0x3b` source selects, `+0x3c..+0x3e` source modifiers,
`+0x3f` pre-op, `+0x40` alpha opcode (0 mad, 1 dp, 2 min, 3 max, 5 cnd, 6 cmp, 7 frc, 8 ex2, 9 ln2, 10 rcp, 11 rsq), `+0x41` output scale, `+0x42` clamp; `+0x34` post-NOP flag.

Open points: the meaning of the bits inside the source-select / modifier bytes (`+0x2a..+0x2f`, `+0x39..+0x3e`), the `+0x24/+0x26/+0x28` halfwords and `+0x36/+0x37` bytes, and FUN_000d0b68 (the pre-dump
normalisation) were not decoded.
