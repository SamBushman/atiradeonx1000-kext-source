# libGLProgrammability: PP stream, packed program printers, copy propagation (part_016 / part_017)

Read off `_PPStream*`, `_glpPPDisassemble`, `_glpPPShaderToProgramString`, `_glpDisassemble1Op/2Op`, `_InlineFunctionsBranch`,
`_*AvailableCopy*`, `_BitSet*`. Names are in `names_lpF_1.tsv` / `names_lpF_2.tsv` (plus fixes to `names_W3.tsv`, `names_R5_dis.tsv`).

## Chunk and chunk list

A chunk is `calloc`ed: byte +0 type, +1 "renumbered" mark (used by `_renumberLabels` / `_renumberTargets` with markRenumbered), +4 previous,
+8 next, payload from +0xc. A chunk list header is 3 words: head +0, tail +4, count +8. `_PPStreamChunkCompare` compares the payload:
0x10 bytes for types 0, 3, 10; 4 for type 1; 8 for types 2, 4, 5, 6, 7, 9; 0x38 for type 8 (operations).

## Stream (`_PPStreamCreate` / `_PPStreamAttachStream`)

`stream[0]` is the target word; the other words are chunk list pointers. Chunk type to list (confirmed by `_PPStreamFindDuplicateChunk`):

| type | meaning | list | packed header words (count / offset) |
|---|---|---|---|
| 0 | temp register declaration | stream[1] (+4) | [4] / [5] |
| 1 | address register | stream[3] (+0xc) | [6] (count only) |
| 2 | attribute | stream[6] (+0x18) | [8] / [9] |
| 3 | parameter | stream[4] (+0x10) | [10] / [11] |
| 4 | output | stream[7] (+0x1c) | [12] / [13] |
| 5 | parameter array | stream[5] (+0x14) | [14] / [15] |
| 6 | temp array | stream[2] (+8) | [16] / [17] |
| 7 | option | stream[0xc] (+0x30) | [18] / [19] |
| 8 | operation | stream[8] (+0x20) | [20] / [21] |
| 9 | raster state | stream[10] (+0x28) | [24] / [25] |
| 10 | (16-byte entries, not named) | stream[0xb] (+0x2c) | [26] / [27] |
| 0xb | label | stream[9] (+0x24) | none (built by `_PPStreamAddLabel`) |

Operation chunk payload (from +0xc): the 14-word operation record (word0 opcode in bits 18..25, source count in bits 29..31, operation index in
the low 18 bits; word1 flags; words 2/3 destination; words 4..9 up to three sources of two words each; words 10..13 aux/line/text length). When
word 13 (chunk +0x40) is non-zero, that many text bytes follow at chunk +0x44 (a function name). Label chunk: +0xc operation index, +0x10 name
length, +0x14 name text.

## Packed program ("pp" program) tables

The header words are count/offset pairs as above; offsets are in 8-byte units. Each table entry is 8 bytes: word 0 holds kind/type/size
bits, the register number is the ushort at byte +6 (low 16 bits of word 1). Array tables (temp arrays, parameter arrays) have the first register
in the low 16 bits of word 0 and the length in the ushort at +6. Register file in operands (word0 >> 0x17 & 7): 0 attribute, 1 temp, 2 parameter,
3 output; in the compact 2-op destination (word2 >> 0x11 & 7): 1 tmp, 3 res, 4 adr.

## Printer conventions

`_ncpy` writes a decimal number and returns its length; the string literals are copied by inlined loops. `tempNumbers` / `tempArrayPos` /
`paramNumbers` / `paramArrayPos` are per-register tables built by `_glpPPDisassemble` / `_glpPPShaderToProgramString`: the printed number of the
register, and its position in an array (-1 not in an array, 0 first element, k later elements); `arraySizes` receives the array lengths.

## Parser limits block

`_glpPPShaderToProgram` fills a 0x3c-byte block (15 words) and copies it to `parser + 0x450`; the words are bounds checked by `_PPParser*`
(error codes 0x2e, 0x2f, 0x30, 0x32, 0x34, 0x38, 0x39, 0x3b, 0x3c, 0x3d at parser offsets 0x450, 0x454, 0x458, 0x45c, 0x464, 0x470, 0x478, 0x480,
0x484, 0x488). Values: 0x80 fragment / 0x100 vertex for the first two.

## Optimisation passes (`_glpPPShaderLinearizeStreamMgr`)

Flag bits: 1 inline functions (`_InlineFunctionsBranch`), 0x102 detect and unroll constant loops, 4 pack indices then flatten ifs, 8 local copy
propagation (`_LocalCopyPropagator`), 0x10 embed sampler parameter indices, 0x20 interference sets and register merge, 0x40 dead-code
elimination, 0x80 constant propagate and fold; any non-zero flag builds a program (`_ProgramNew`, registerify, blockify) and `_RegistersCleanup`.

## Available-copy table (`_AddToAvailableCopyTable`, ...)

Header `{count, entries}`; entries are 0x48 bytes and the table grows by 8 entries: +0 in use, +4 destination file, +8 destination register,
+0xc source file, +0x10 source register, +0x14 component count - 1, +0x18 swizzle select[4], +0x28 component valid[4], +0x38 negate,
+0x3c relative-addressing flag, +0x40 destination array index, +0x44 source array index.

## Function table (`_RecordFunctionCall`, ...)

0x20-byte records, grown in steps of 0x80: +0 key (operation index of the function entry), +4 end/edge value, +8 operation counter, +0xc branch count,
+0x10 branch source index array, +0x14 branch target index array (the jump table of that function).

## Bit set

`{bitCount, byteSize, words}` (12 bytes); `words` is a `malloc`ed array of 32-bit words, grown by `_BitSetSetSizeEquals` / `_BitSetExpandEquals`.
