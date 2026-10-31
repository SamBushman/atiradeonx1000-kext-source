# r11 (GLDriver): the 14 blocked labels, DAT_ naming, what is left

Rows: `names_r11_labels.tsv` (14), `names_r11_data.tsv` (59 `DAT_`), `names_r11_ptr.tsv` (2 slots).

## The 14 "blocked" labels were NOT a transcription gap
r09 suspected `gld_initContextDispatch` had no stores for the emit slots at `0x12e4..0x131c`. It does: the disassembly addresses them off `r30 = ctx + 0x240` (`addi r30,r3,0x240` at 0xa7058, `stw r30,0x1c(r30)` stores the sub-struct pointer into itself), so the slot at `0x12e4(r30)` is `ctx + 0x1524` in the C. The ffvp emitters (`programBuilder + 0x3d4`) hold that `ctx + 0x240` sub-struct as `glCtx`, hence `glCtx + 0x12e4`. Mapping, from the `ctxByte1aa8 != 0` (IL) arm of part_015.c:
| glCtx offset | C offset (ctx+) | callback |
|---|---|---|
| 0x12e4 | 0x1524 | arbEmitIlDp4 |
| 0x12e8 | 0x1528 | arbEmitIlMov |
| 0x12ec | 0x152c | arbEmitIlMul |
| 0x12f0 | 0x1530 | arbEmitIlAdd |
| 0x12f4 | 0x1534 | arbEmitIlMad |
| 0x1314 | 0x1554 | arbEmitIlRcp |
| 0x1318 | 0x1558 | arbEmitIlRsq |
(the other arm installs the arbEmitRecord*Src_op* variants in the same slots). Labels named from the callback each one reaches; all INFERRED. Two of the 14 (`LAB_000d64e8`, `LAB_000d6534`) are in `ffpsEmitTexEnvCombine`, not an ffvp function. Two more (`LAB_000972c8`, `LAB_00097360`) are in `ffvpEmitSceneColor`.

## DAT_: 59 named
- bss zero blocks `0x1fa5e8` (369 uses, the modifier pointer after each swizzle pointer in emit-callback calls) and `0x1fa5f8..0x1fa614` (two 4-word operand templates copied into `resultOperand`): `zeroWords4_*`. Two nl_symbol_ptr slots to them / to `laneWordSplatTable_001aa818` renamed too.
- Vertex-array type tables `0x1d92a8/9358/9408/94b8`: `vertexTypeSwizzleField{W,Z,Y,X}Table_*`. Evidence: 44-word tables indexed `(type*4 + components-1)*4`, `& 7`, packed into bits 9-11/6-8/3-5/0-2 of `vertexArray[attr+0x6a]`; the float rows read X=0 Y=1 Z=2 W=3, 4 = zero, 5 = one. Also `0x1d9644` (`vertexTypeDwordCountTable`).
- KhanPs seed tables `0x1aff08..0x1affb8`, `0x1dba44`, `0x1dbab8`, `0x1dbed4` (`colorMaterialLookupTable`), `0x1b004c`, `0x1aa761`, and 25 select/write-mask words (`laneWord<value>_<addr>`, auto-named only when the 4 bytes are all 0..4 with a non-zero top byte and the use is scalar).

## Left unnamed on purpose
- PIC anchors, not data: `DAT_001ab134`, `001acec0`, `001ad5d8`, `001b2eb8`, `001b40f0`, `001b81b8`, `001b9d04`, `001ea500`, `001f3a54`, `001e3a54`, `001e3520`, `001db440`, `001f8514`, `001f65e7` (Ghidra's `constBase`/`picBase` pointers used with a large constant offset; a data name would be wrong).
- int/enum tables whose role is not stated: `001e61*`, `001e6134..6188`, `001e6668/66cc`, `001d9b70/9b9c/9c4c/9cfc/9dac` (parallel to the named vertex-type tables, role of each field unproven), `001da500/50c`, `001da630`, `001db998/2f4/344`, `001dbcd0`, `001dbf90/94`, `001dba98`, `001e1c1c/1c2c/1c30/25f4/2604/2608` (FudoVs/KhanVs install records), `001b0170`-`001b01f4` zero/float constants, `001b2994`, `001b0228`, `001b0244`, `001b02ec`, `001b19e0`.
- `DAT_001fc1f0..1fc` (`__common` bucket table in part_032, written through computed offsets).
- eh_frame / `__const_coal` symbols that appear only in `link/symbol_map.tsv`.
- Vtable slots `001e9108` (base of KhanPs/KhanVs/FudoPs, stored `+8` in all their dtors), `001e9144`, `001e9100`, `001e9148`: the base class has no name in the corpus (the three derived classes are the only users), so a slot name would not be derivable. Not changed.

## Gates
apply_names --check 0 errors (105,146 applied). datacheck.sh (base 380a4b9f): symbol_map/data.s/etc identical; only part_014.c/part_019.c differ, by the 14 label names (checked line by line). Compile gate (G5, Tiger) vs 380a4b9f: SPLIT-EQUIVALENT, 29 differing objects, 29 parts compared, 0 problems; no quota/No space/compared 0 in the log.
