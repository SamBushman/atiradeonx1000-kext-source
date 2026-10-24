# GLDriver parts 010-014: layout findings from the lp19 naming round (tag gS)

Evidence behind `names_gS_*.tsv` (all INFERRED unless noted). Offsets are bytes.

## Fixed-function vertex program builder (ffvp*), part_014 / part_013

* `ffvpBuildProgram` (FUN_0009d410) creates the program record (FUN_00092bf0) and walks the GL state to decide which state parameters the program needs.
  Each needed parameter is appended to `paramList` = `{+0 kinds*, +4 element indices*, +8 count}` as one (kind, element) pair, and its constant register is
  recorded in the program record parameter map (`programRecord+0xa4`, 0x324 bytes initialised to -1, 0xf words per light; fixed registers at
  `programRecord+0x2d8..0x344`).
* `programFillStateConstants` (FUN_0009f0b0) is the consumer: it walks `paramList` (program+0x50), looks up the register in the parameter map (program+0x54)
  and writes the value into the constant buffer (program+0x4c, 0x10 bytes per register). The kinds are the switch cases 0..0x1d:
  0 = mvp x slot matrix product, 1 = slot matrix copy, 2 = slot matrix inverse (cofactor expansion, `determinant` / `invDeterminant`), 3 = mvp copy,
  4 = alternate slot matrix copy (slot+0x400), 5..7/10/0xd = light fields, 8/9 = point-size/fog related scalars, 0xb/0xc = per-unit scalars (ctx+0x1500 + 0x6c per unit),
  0xe..0x11 = material front/back (front 0x28c0.., back = +0x240), 0x12 = light model color product, 0x13 = shininess, 0x14.. = fog/ctx vectors, 0x1a = texgen planes
  (ctx + 0xcc*unit + 0x4b0), 0x1b = vec at ctx+0x398, 0x1c/0x1d = light x material diffuse/specular products.
* State block (`*(ctx+4)+0x10`): mvp matrix +0x1920 (16 floats), tracked matrices `+0x1860 + n*0x40` (elements from +0x100), light i at `+0x24c0 + i*0x80`
  (fields every 0x10: ambient, diffuse, specular, position, ...; spot direction +0x50.., attenuation +0x5c), material block `+0x28c0`
  (ambient, diffuse +0x10, specular +0x20, emission +0x30, shininess +0x40; back-face block +0x240), fog mode word +0x2e04 (GL_EXP 0x800, GL_EXP2 0x801, GL_LINEAR 0x2601).
* `ffvpAllocTempRegister` (FUN_00090ca0) is the temp register allocator of the generator: per-register 4-byte component flags at `alloc+0x6c4`, register count `alloc+1000`,
  high-water mark `alloc+0x3d0`; fills `resultOperand` (word 0 component count, word 1 register index, words 2..9 selector constants).

## EXT_vertex_shader (evs*), part_010 / part_011

* `evsAssignVertexInputs` (7 KB): phase 1 assigns hardware input registers to variant symbols used as instruction sources (kinds of bound state select the input table slots
  in the program state: +0x60/+0xb8 0x16-entry tables, +0x1388..+0x13a0 registers), phase 2 output registers (`evsFindFreeOutputRegister`),
  phase 3 constants (`evsAllocConstantsForOperand`), then the token buffer at programState+0x140 (`evsTokenBufPush`), temp release scan, fog output.
  Record layouts: instruction 0x74 bytes, symbol 0x54 bytes (see notes_gld_functions_b.md).
* `evsFoldConstantMoves`: source selectors of the 0x74-byte instruction are four words at slot+8 (slot bases +0x20, +0x3c, +0x58).

## ARB program record emitters (arbEmitRecord{1,2,3}Src_op*), part_012

Instruction record = 4 words (0x10 bytes) in `ctx+ARB_instrArray`:
word 0: dst file (bits 8..11), dst index (13..19), write mask (20..23); word 1 / 2 / 3: source 0 / 1 / 2: file (0..3), index (5..12), swizzle selects X/Y/Z/W
(bits 13, 16, 19, 22; 3 bits each), negates X/Y/Z/W (bits 25..28). The temporaries of these emitters are the packed fields (`dstFileBits`, `src0SelectXBits`, ...) and,
in the 1-/2-source emitters, the completed last source word (`srcWord` / `src1Word`).

## Tooling pitfalls found here

* A statement `x = f(..., x, ...)` spread over several Ghidra lines (the final `src1Word = ... | src1SelectXBits | ...;` of the 2-source emitters) is one web in find_webs:
  `emit_webs.py` gives the whole `+N` segment to the defining name, which renames the right-hand-side use too. The gate shows it as DATAFLOW + UNINIT (gS3/gS4).
  Fix: split the segment into the definition line (`+1`), the continuation line (old name) and the following uses.
* `rn.py revert` / `prep.py` look the function up by its name in the part file: for a renamed function use the rows' Ghidra name only in the tables and the new name for the text.
* `autoweb.py` (new): rule-driven per-web naming; the rule module sees the web's definitions and lines (examples in the lp19 scratch rules). Names are made unique across variables.
