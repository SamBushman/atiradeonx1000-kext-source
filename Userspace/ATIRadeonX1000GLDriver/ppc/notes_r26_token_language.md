# r26: the ilOpcodeTemplateStream token language (ATIRadeonX1000GLDriver, Tiger PPC)

Tier key: CONFIRMED = decoded from code/data in the stock binary; INFERRED = best reading, evidence stated.
Numbers are addresses in the stock binary ATIRadeonX1000GLDriver (tiger-hd-pull). Supersedes the r25 recon where they differ (see "Corrections to r25").

## 1. Consumer
Program__translateILStream @ 0xfd5c8 (Ghidra sizes it at 408 bytes; the real body runs to ~0x103c00; part_026.c).
- Per IL instruction: translation kind from the hardware opcode record; kind 5 = template-driven. Kinds 2 (unsupported IL >= 0x88), 3, 4, 6 do nothing in this path (IL mmul 0x45 is kind 6 with a NOP stream).
- templateBase = record[+0x18]. Loop head 0x1005f4: tok = base[cursor]; cmplwi tok,0x71; bgt -> 0x103b2c (default); else jump table at 0x100620 (114 entries, 32-bit offsets from 0xfd5d8+0x3048). CONFIRMED.
- Loop tail 0x103b34: if a work instruction exists and vtable[5](workInst)+1 == operand index, Program__appendInst; cursor++. CONFIRMED.
- Streams are big-endian 32-bit words. Every stream starts with 0x13 (BEGIN) and ends with 0x2a (RET). No length field. The region 0x1ab1e8..0x1af974 tiles exactly into 195 streams; the 16-word operand-slot-info table follows at 0x1af974.

## 2. Hardware opcode records
Three tables of 228 records, stride 0x24, indexed by ilOpcode: vsHardwareTable_001e1994 (shared by KhanVs/FudoVs), KhanPsHardwareTable_001e39a4, FudoPsHardwareTable_001e6730.
Fields: [0] IR opcode id, [1] #sources, [2] has dest, [4] translation kind (5 = template), [5] instruction factory, [6] (+0x18) template stream pointer, [7] out-components-1 << 8 (matrix ops), [8] (+0x20) record id (= ilOpcode, self-check). CONFIRMED.
ilOpcodes 0xbf..0xe3 are "ext" ids: ildisPrintInstruction stops at 0xbe, so they have no IL mnemonic. Ids 0xcf..0xd3 = ildisPrintMatrixMode code + 0xcf (0 4x4, 1 4x3, 2 3x4, 3 3x3, 4 3x2). Their meaning in the stream names is INFERRED from the stream content and [7].
Stream names `ilTemplateOp<IlName><Qual>_<addr>` come from an extractor over the 183-site mnemonic switch in ildisPrintInstruction (part_020.c); Qual: Vs = vertex table only, KhanPs / FudoPs = that pixel table only, Ps = both pixel tables, VsKhanPs etc. combined; no suffix = all three tables.
Hardware template slots (not IL records): vs field 0x2a0 = rec 18 cos, 0xc78 = rec 88 sin, 0xc9c = rec 89 sincos, 0xd08 = rec 92 tan, 0xe28 = rec 100 dxsincos.

## 3. Token table (0x00..0x71)
Payload words after the token: 0x1f:1, 0x20:1, 0x30:4, 0x31:1, 0x32:1, 0x37:1, 0x42:1, 0x4f:1, 0x50:1, 0x6e:1, 0x71:1 (0x1f 0x20 0x30 0x38 0x71 verified in disassembly, the rest from the C); all others 0.
Tokens with no handler (0x00, 0x18-0x1e, 0x25, 0x2b, 0x3f, 0x41, 0x5f, 0x61-0x69, 0x6f, > 0x71) set the fall-through flag (end of template); they occur in the data only as payload words.
NOP tokens (jump target 0x103b20): 0x01 0x13 0x33 0x39 0x3b 0x3c 0x3e 0x40 0x4c 0x5e (the roles of 0x01 0x33 0x39 0x3b 0x3c 0x3e 0x40 0x4c are not further decodable: INFERRED placeholders; 0x5e appears in one unreferenced stream).

| tok | name | payload | semantics | tier |
|---|---|---|---|---|
| 02-05 | BIND0-3 | - | bind next operand: destination register + n | CONFIRMED |
| 06 | BIND4 | - | destination, unsplit | CONFIRMED |
| 07 | BIND5 | - | src0 register +0 (slot-info bit27 set) | CONFIRMED |
| 08 | BIND6 | - | src0 (bit27 clear) | CONFIRMED |
| 09-0b | BIND7-9 | - | src0 register +1..+3 | CONFIRMED |
| 0c-0f | BIND10-13 | - | src1 register +0..+3 | CONFIRMED |
| 10 | BIND14 | - | src2 | CONFIRMED |
| 11 | BIND15 | - | src0 (bit27 set) | CONFIRMED |
| 12 | ABS | - | IROperand__setModifierBits(next operand, mask 2, 1); applies to the NEXT operand bound | CONFIRMED |
| 14/15/16 | CALL tables | - | callee = table[(ILword>>16)&0x3fff]; tables 0x1dc78c / 0x1dc77c / 0x1dc76c (4 entries: CLAMP, FF, IEEE, IEEE) | CONFIRMED |
| 17 | BREAK | - | only when the top scope opcode is loop 0x3e / whileloop 0x71, else ilTemplateCase17Scope72 | CONFIRMED |
| 1f | SWZ | 1 | staged source swizzle = byte-swapped word (stwbrx); lane k = (word>>(8k))&0xff of the file word | CONFIRMED |
| 20 | WMASK | 1 | destination write mask = byte-swapped word; 0 written, 1 masked | CONFIRMED |
| 21 / 23 | CALL Case21 / Case23 | - | ilTemplateCase21Kind0-5 / Case23Kind0-5 by relop (ILword>>16)&7 | CONFIRMED |
| 22 | BIAS | - | source bias: (word>>22)&7 mode, ADD src0 +/- 0.5 or 1.0 through a temp | CONFIRMED (name chosen from effect) |
| 24 | CONTINUE | - | loop continue (ilTemplateCase24 on re-entry) | CONFIRMED |
| 26 / 27 / 28 / 29 | ELSE-scan / ELSE / POP / ENDIF | - | structured control flow; 0x60 and 0x26 skip forward looking for 0x26 / 0x28 | CONFIRMED |
| 2a | RET | - | pop call frame; empty frame ends the template | CONFIRMED |
| 2c | FETCH | - | generic sampler fetch macro using ilSampleOpcodeRecords at 0x1dc660 | CONFIRMED |
| 2d / 2e | FETCHTEX | - | IR 0x76 FETCHTEXTUREMAPBIAS if bit25 clear else 0xae FETCHTEXTURELOD; 0x2d fails if bit25 set | CONFIRMED |
| 2f | FETCHGRAD | - | gradient fetch, IR 0x78, setgradients 0x72/0x73 | CONFIRMED |
| 30 | LIT4 | 4 | vec4 float literal operand | CONFIRMED |
| 31 | PUSH | 1 | push condition: payload 0x3f -> IL word bit18, 0x5f -> bit24, 0x67 -> 1, others -> 0 | CONFIRMED |
| 32 | IF | 1 | payload 0x62 unconditional (IR_CMP2 const), 0x63 ifnz (IR_CMP1S), 0x64 ifc (hw callback vslot 0x24 with relop), 0x65/0x66 IR 0x8c with comparison kind 6/7, 0x6f hw callback vslot 0x28, 0x72 hw callback | CONFIRMED |
| 34 | ZEROCONST | - | operand = register file 0x21 index 0 | CONFIRMED |
| 35 / 36 | ENDLOOP / LOOP | - | LOOP constructs the PostLoopFooter and pushes the loop stack | CONFIRMED |
| 37 | EMIT | 1 | payload = IR opcode id (replaced by 0x75 when program[0x47c] != 0); creates the work IRInst (IRInst__create @ 0x1043f0) | CONFIRMED |
| 38 | (flag) | - | sets a field on the work instruction (verified handler) | CONFIRMED handler / INFERRED role |
| 3a | SAT | - | sets inst+0x120 = 1, tested by IRInst__clampOutputValue | CONFIRMED |
| 3d | NEG | - | toggle modifier mask 1 on the NEXT operand bound | CONFIRMED |
| 42 | FLT | 1 | replicated float literal | CONFIRMED |
| 43-48 | CALL recip table | - | lane-wise in-place reciprocal X/Y/Z/W (43-46), RECIP of src0.w to dst (47), RECIPSQRT w to dst (48); callee = pointer at 0x1dc2cc + (tok*4+idx)*4 (28 pointers 0x1dc6fc..0x1dc76b); idx 0 CLAMP, 1 FF, 2 IEEE, 3 IEEE | CONFIRMED |
| 49 / 4a | CALL rsqrt broadcast | - | both read the same 4-entry table at 0x1dc75c (4a: base + ((word>>14)&0xc)): rsq(T0.x) broadcast | CONFIRMED |
| 4b / 6b | CALL conditional | - | ilTemplateCase4b{Default,HwFlag40Clear} / ilTemplateCase6b{Default,OptionEnabled} | CONFIRMED |
| 4d | (fetch state) | - | sets byte at fetch-state+0x12 from IL word bit24 | CONFIRMED |
| 4e / 53 | LOOKUP | - | OpcodeTemplate__lookup(sub=(word>>16)&7, variant 0 / 1); table 0x1e9f78 = 6 records x {VariantN, NoHw, Variant0}; record index = relop code (ildisPrintRelop: 0 ne, 1 eq, 2 ge, 3 gt, 4 le, 5 lt); null result = NOP | CONFIRMED |
| 4f / 50 | (fixed-point fields) | 1 | IRInst extra fields | INFERRED |
| 51 / 52 | TEXSTAGE / TEXSTAGE2 | - | logs "TextureStage %d misses DCLPT" on failure | CONFIRMED |
| 54 | MARKVREG | - | marks a virtual register | INFERRED |
| 55-5d | T0..T8 | - | cached negative-index temp register #(tok-0x55), allocated on first use | CONFIRMED |
| 60 | IFSKIP | - | skip to ELSE / POP when the pushed condition is false | CONFIRMED |
| 6a | FAIL | - | Compiler__fail 0xf | CONFIRMED |
| 6c | (vslot9 + flag) | - | vslot 9 call, sets inst+0x12c = 1, finalizes | INFERRED |
| 6d | FIXSEL | - | normalize operand-1 swizzle through a MOV into a temp | CONFIRMED |
| 6e | INT | 1 | replicated int literal | CONFIRMED |
| 70 | CALL conditional | - | fixed callee (see r25) | INFERRED |
| 71 | (payload token) | 1 | consumes one payload word | CONFIRMED handler / INFERRED role |

## 4. Recursion tables
- 0x1dc78c / 0x1dc77c / 0x1dc76c: tokens 0x14/0x15/0x16 (log/logp/ln style), index (word>>16)&0x3fff. Entries 1-3 are identical in the r25 scan; index 3 duplicates index 2 (IEEE).
- 0x1dc6fc..0x1dc76b: 28 pointers for tokens 0x43-0x48 (4 each); 0x49 and 0x4a share the 4 entries at 0x1dc75c.
- 0x1e9f78: OpcodeTemplate__lookup records (see 0x4e).
- Stream names carry `Case<tok>Idx<n>` for the recursion tables and `StreamOp<k>` for lookup records.

## 5. IR opcode names
Table at 0x1dca6c, stride 0x38 (id at +0, name at +8): ids 0..180 (SCATTER = 180) are named. A second unrelated table at 0x1df204 follows. IR ids >= 181 used by streams (0xba 0xc2 0xe3 0xe4 0xe5) have no name source (Opcode__getInfo table at 0x1fb2b0 is filled at run time) and are referred to by id only: INFERRED.

## 6. Layout facts the data layer needed
- 12 arrays held two or more streams: 1ab4fc 1ac0bc 1ac37c 1ad158 1ad224 1aec14 1aec3c 1aec94 1aecd0 1aedb4 1af718 1af7b4. 5 arrays were cut short by interior labels: 1abf90 1ac500 1acde8 1ad5a0 1ad7e8. The old r24 sizes were wrong; the new names state the true extent.
- 29 streams are not reached by any pointer word and therefore had no LD_ label: they are listed in `extra_data_labels` in Tools/userspace/link_config/gld.json (consumed by link_corpus.py) so a `target` row can name them (names_r26_templates.tsv). Base and candidate links use the same config, so the data stays identical.
- Interior labels that stay (they sit inside streams): constPoolAnchor_001abfb4 (inside 1abf90), constPoolAnchor_001ac5a4 (inside 1ac500), constPoolAnchor_001acec0 (inside 1acde8), constPoolAnchor_001ad5d8 (inside 1ad5a0), constPoolAnchor_001ada48 (inside 1ad7e8). 1abfb4 and 1ac5a4 were previously called textPrintDoubleShortest_pow10Table and arbTypeTagTable_001ac5a4; both are gcc PIC bases (r31 + addis), not tables, so they were renamed as anchors (the real power-of-ten table is powerOfTenDoubleTable at 0x1aa3a8).
- 13 byte-identical duplicate pairs (the names carry the same core and differ by address): (1ab1e8,1ab238) (1ae1b8,1ae2a0) (1ae1d4,1ae2bc) (1ae1f0,1ae2d8) (1ae20c,1ae2f4) (1ae814,1ae834) (1ae894,1ae8b4) (1ae914,1ae934) (1ae994,1ae9bc) (1aea34,1aea5c) (1aead4,1aeafc) (1aeb74,1aeb9c) (1aec94,1aed6c).
- ilOpcodeTemplateOffsetTable_001aa9e4 is not about streams (small enum map); left alone.

## 7. Corrections to r25
Hardware tables hold 228 records (not 191) and ext ids 0xbf..0xe3 attach there. ABS and NEG modify the NEXT operand, not the last. 0x22 is a source bias, not a saturating move. 0x49 and 0x4a share one table. The r25 "Case4a pointer" overlaps the 0x49 slots.

## 8. What stays INFERRED
Semantics of the ext ops (Op0x...), the roles of the 29 unreferenced streams (named by content), the NOP-class placeholder tokens, token 0x6c / 0x4f / 0x50 / 0x54 / 0x70, IR ids >= 181.

## 9. Stream index (195 streams: address, words, name, tier, row file)
| address | words | name | tier | row file |
|---|---|---|---|---|
| 0x1ab1e8 | 6 | ilTemplateOp0xDEMov_001ab1e8 | INFERRED | names_r24_targets.tsv |
| 0x1ab200 | 7 | ilTemplateOp0xD8Mul_001ab200 | INFERRED | names_r24_targets.tsv |
| 0x1ab21c | 7 | ilTemplateOp0xD5MovNeg_001ab21c | INFERRED | names_r24_targets.tsv |
| 0x1ab238 | 6 | ilTemplateOp0xD4Mov_001ab238 | INFERRED | names_r24_targets.tsv |
| 0x1ab250 | 8 | ilTemplateOp0xCBAddNeg_001ab250 | INFERRED | names_r24_targets.tsv |
| 0x1ab270 | 7 | ilTemplateOp0xBFAdd_001ab270 | INFERRED | names_r24_targets.tsv |
| 0x1ab28c | 22 | ilTemplateOp0xD3Mmul3x2_001ab28c | INFERRED | names_r24_targets.tsv |
| 0x1ab2e4 | 29 | ilTemplateOp0xD2Mmul3x3_001ab2e4 | INFERRED | names_r24_targets.tsv |
| 0x1ab358 | 34 | ilTemplateOp0xD1Mmul3x4_001ab358 | INFERRED | names_r24_targets.tsv |
| 0x1ab3e0 | 29 | ilTemplateOp0xD0Mmul4x3_001ab3e0 | INFERRED | names_r24_targets.tsv |
| 0x1ab454 | 34 | ilTemplateOp0xCFMmul4x4_001ab454 | INFERRED | names_r24_targets.tsv |
| 0x1ab4dc | 8 | ilTemplateOp0xC7CndgeNegSrc0_001ab4dc | INFERRED | names_r24_targets.tsv |
| 0x1ab4fc | 20 | ilTemplateOp0xDDSgn_001ab4fc | INFERRED | names_r24_targets.tsv |
| 0x1ab54c | 52 | ilTemplateIrc2Ire5PerLane_001ab54c | INFERRED | names_r26_templates.tsv |
| 0x1ab61c | 52 | ilTemplateIrc2Ire4PerLane_001ab61c | INFERRED | names_r26_templates.tsv |
| 0x1ab6ec | 52 | ilTemplateIrc2Ire3PerLane_001ab6ec | INFERRED | names_r26_templates.tsv |
| 0x1ab7bc | 31 | ilTemplateOpTanFudoPs_001ab7bc | CONFIRMED | names_r24_targets.tsv |
| 0x1ab838 | 29 | hwLimitsDefaultDataA_001ab838 | CONFIRMED | names_r13_targets.tsv |
| 0x1ab8ac | 174 | vsHardwareTableField0D08Init_001ab8ac | CONFIRMED | names_r13_targets.tsv |
| 0x1abb64 | 18 | ilTemplateOpRnd_001abb64 | CONFIRMED | names_r24_targets.tsv |
| 0x1abbac | 31 | ilTemplateOpReflect_001abbac | CONFIRMED | names_r24_targets.tsv |
| 0x1abc28 | 31 | ilTemplateCase4bDefault_001abc28 | CONFIRMED | names_r13_targets.tsv |
| 0x1abca4 | 37 | ilTemplateCase4bHwFlag40Clear_001abca4 | CONFIRMED | names_r13_targets.tsv |
| 0x1abd38 | 3 | ilTemplateStubCall4b_001abd38 | INFERRED | names_r26_templates.tsv |
| 0x1abd44 | 46 | ilTemplateOpTrcVs_001abd44 | CONFIRMED | names_r24_targets.tsv |
| 0x1abdfc | 28 | ilTemplateOpTrcPs_001abdfc | CONFIRMED | names_r24_targets.tsv |
| 0x1abe6c | 16 | ilTemplateOpFlr_001abe6c | CONFIRMED | names_r24_targets.tsv |
| 0x1abeac | 43 | ilTemplateOpPireduce_001abeac | CONFIRMED | names_r24_targets.tsv |
| 0x1abf58 | 14 | ilTemplateOpLitVs_001abf58 | CONFIRMED | names_r24_targets.tsv |
| 0x1abf90 | 17 | ilTemplateOpLen_001abf90 | CONFIRMED | names_r24_targets.tsv |
| 0x1abfd4 | 13 | ilTemplateLenDot4Sqrt_001abfd4 | INFERRED | names_r26_templates.tsv |
| 0x1ac008 | 45 | ilTemplateOpFwidthVs_001ac008 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac0bc | 29 | ilTemplateOpFwidthFudoPs_001ac0bc | CONFIRMED | names_r24_targets.tsv |
| 0x1ac130 | 24 | ilTemplateGetGradientsHalvesF50x03010301_001ac130 | INFERRED | names_r26_templates.tsv |
| 0x1ac190 | 24 | ilTemplateGetGradientsHalvesF50x02000200_001ac190 | INFERRED | names_r26_templates.tsv |
| 0x1ac1f0 | 3 | ilTemplateOpDp3Ps_001ac1f0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac1fc | 64 | ilTemplateCase6bOptionEnabled_001ac1fc | CONFIRMED | names_r13_targets.tsv |
| 0x1ac2fc | 7 | ilTemplateCase6bDefault_001ac2fc | CONFIRMED | names_r13_targets.tsv |
| 0x1ac318 | 10 | ilTemplateOpDp2add_001ac318 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac340 | 15 | ilTemplateOpDiv_001ac340 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac37c | 23 | ilTemplateOpDist_001ac37c | CONFIRMED | names_r24_targets.tsv |
| 0x1ac3d8 | 19 | ilTemplateDistDot4Sqrt_001ac3d8 | INFERRED | names_r26_templates.tsv |
| 0x1ac424 | 39 | ilTemplateMovSaturateClampSelect_001ac424 | INFERRED | names_r26_templates.tsv |
| 0x1ac4c0 | 16 | ilTemplateOpClg_001ac4c0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac500 | 83 | ilTemplateOpAtan_001ac500 | CONFIRMED | names_r24_targets.tsv |
| 0x1ac64c | 100 | ilTemplateAtanReciprocalReduction_001ac64c | INFERRED | names_r26_templates.tsv |
| 0x1ac7dc | 129 | ilTemplateOpAsin_001ac7dc | CONFIRMED | names_r24_targets.tsv |
| 0x1ac9e0 | 130 | ilTemplateOpAcos_001ac9e0 | CONFIRMED | names_r24_targets.tsv |
| 0x1acbe8 | 35 | ilTemplateOpNrm_001acbe8 | CONFIRMED | names_r24_targets.tsv |
| 0x1acc74 | 7 | ilTemplateOpMovaVs_001acc74 | CONFIRMED | names_r24_targets.tsv |
| 0x1acc90 | 86 | ilTemplateOpModPs_001acc90 | CONFIRMED | names_r24_targets.tsv |
| 0x1acde8 | 64 | ilTemplateOpModVs_001acde8 | CONFIRMED | names_r24_targets.tsv |
| 0x1acee8 | 78 | ilTemplateCase15Idx1To3LogpIeee_001acee8 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad020 | 78 | ilTemplateCase15Idx0LogpClamp_001ad020 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad158 | 3 | ilTemplateOpLogpPs_001ad158 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad164 | 7 | ilTemplateIrBaDstSrc1Src0_001ad164 | INFERRED | names_r26_templates.tsv |
| 0x1ad180 | 8 | ilTemplateCase14Idx1To3LogIeee_001ad180 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad1a0 | 8 | ilTemplateCase14Idx0LogClamp_001ad1a0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad1c0 | 3 | ilTemplateOpLog_001ad1c0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad1cc | 22 | ilTemplateOpExppVs_001ad1cc | CONFIRMED | names_r24_targets.tsv |
| 0x1ad224 | 49 | ilTemplateOpExppPs_001ad224 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad2e8 | 49 | ilTemplateExppScalarFractVariant_001ad2e8 | INFERRED | names_r26_templates.tsv |
| 0x1ad3ac | 49 | ilTemplateCase16Idx1To3LnIeee_001ad3ac | CONFIRMED | names_r24_targets.tsv |
| 0x1ad470 | 49 | ilTemplateCase16Idx0LnClamp_001ad470 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad534 | 3 | ilTemplateOpLn_001ad534 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad540 | 3 | ilTemplateOpLoop_001ad540 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad54c | 2 | ilTemplateOpNop_001ad54c | CONFIRMED | names_r24_targets.tsv |
| 0x1ad554 | 3 | ilTemplateOpMmul_001ad554 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad560 | 16 | ilTemplateOpClamp_001ad560 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad5a0 | 146 | ilTemplateOpTranspose_001ad5a0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ad7e8 | 158 | ilTemplateOpDet_001ad7e8 | CONFIRMED | names_r24_targets.tsv |
| 0x1ada60 | 8 | ilTemplateOpSub_001ada60 | CONFIRMED | names_r24_targets.tsv |
| 0x1ada80 | 19 | ilTemplateOpPow_001ada80 | CONFIRMED | names_r24_targets.tsv |
| 0x1adacc | 14 | ilTemplateOpExnPs_001adacc | CONFIRMED | names_r24_targets.tsv |
| 0x1adb04 | 14 | ilTemplateOpLrp_001adb04 | CONFIRMED | names_r24_targets.tsv |
| 0x1adb3c | 13 | ilTemplateOpDsyFudoPs_001adb3c | CONFIRMED | names_r24_targets.tsv |
| 0x1adb70 | 13 | ilTemplateOpDsxFudoPs_001adb70 | CONFIRMED | names_r24_targets.tsv |
| 0x1adba4 | 40 | ilTemplateOpDstPs_001adba4 | CONFIRMED | names_r24_targets.tsv |
| 0x1adc44 | 116 | vsHardwareTableField02A0Init_001adc44 | CONFIRMED | names_r13_targets.tsv |
| 0x1ade14 | 20 | ilTemplateOpSgnVs_001ade14 | CONFIRMED | names_r24_targets.tsv |
| 0x1ade64 | 25 | ilTemplateOpSgnPs_001ade64 | CONFIRMED | names_r24_targets.tsv |
| 0x1adec8 | 8 | ilTemplateOpAbs_001adec8 | CONFIRMED | names_r24_targets.tsv |
| 0x1adee8 | 12 | ilTemplateOpCosFudoPs_001adee8 | CONFIRMED | names_r24_targets.tsv |
| 0x1adf18 | 12 | ilTemplateOpSinFudoPs_001adf18 | CONFIRMED | names_r24_targets.tsv |
| 0x1adf48 | 100 | vsHardwareTableField0C78Init_001adf48 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae0d8 | 9 | ilTemplateCase23Kind5_001ae0d8 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae0fc | 9 | ilTemplateCase23Kind4_001ae0fc | CONFIRMED | names_r13_targets.tsv |
| 0x1ae120 | 9 | ilTemplateCase23Kind3_001ae120 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae144 | 9 | ilTemplateCase23Kind2_001ae144 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae168 | 10 | ilTemplateCase23Kind1_001ae168 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae190 | 10 | ilTemplateCase23Kind0_001ae190 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae1b8 | 7 | ilTemplateStreamOp4VariantN_001ae1b8 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae1d4 | 7 | ilTemplateStreamOp5VariantN_001ae1d4 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae1f0 | 7 | ilTemplateStreamOp3VariantN_001ae1f0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae20c | 7 | ilTemplateStreamOp2VariantN_001ae20c | CONFIRMED | names_r24_targets.tsv |
| 0x1ae228 | 15 | ilTemplateStreamOp0VariantN_001ae228 | INFERRED | names_r13_targets.tsv |
| 0x1ae264 | 15 | ilTemplateStreamOp1VariantN_001ae264 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae2a0 | 7 | ilTemplateStreamOp4Variant0SameAsVariantN_001ae2a0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae2bc | 7 | ilTemplateStreamOp5Variant0SameAsVariantN_001ae2bc | CONFIRMED | names_r24_targets.tsv |
| 0x1ae2d8 | 7 | ilTemplateStreamOp3Variant0SameAsVariantN_001ae2d8 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae2f4 | 7 | ilTemplateStreamOp2Variant0SameAsVariantN_001ae2f4 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae310 | 7 | ilTemplateStreamOp0Variant0_001ae310 | INFERRED | names_r13_targets.tsv |
| 0x1ae32c | 7 | ilTemplateStreamOp1Variant0_001ae32c | CONFIRMED | names_r24_targets.tsv |
| 0x1ae348 | 22 | ilTemplateStreamOp4NoHw_001ae348 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae3a0 | 22 | ilTemplateStreamOp5NoHw_001ae3a0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae3f8 | 22 | ilTemplateStreamOp3NoHw_001ae3f8 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae450 | 22 | ilTemplateStreamOp2NoHw_001ae450 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae4a8 | 22 | ilTemplateStreamOp0NoHw_001ae4a8 | INFERRED | names_r13_targets.tsv |
| 0x1ae500 | 22 | ilTemplateStreamOp1NoHw_001ae500 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae558 | 73 | ilTemplateOpLitPs_001ae558 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae67c | 3 | ilTemplateOpSetVs_001ae67c | CONFIRMED | names_r24_targets.tsv |
| 0x1ae688 | 3 | ilTemplateOpSetPs_001ae688 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae694 | 9 | ilTemplateCase21Kind5_001ae694 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae6b8 | 9 | ilTemplateCase21Kind4_001ae6b8 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae6dc | 9 | ilTemplateCase21Kind3_001ae6dc | CONFIRMED | names_r13_targets.tsv |
| 0x1ae700 | 9 | ilTemplateCase21Kind2_001ae700 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae724 | 9 | ilTemplateCase21Kind1_001ae724 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae748 | 9 | ilTemplateCase21Kind0_001ae748 | CONFIRMED | names_r13_targets.tsv |
| 0x1ae76c | 21 | ilTemplateOpCmpVs_001ae76c | CONFIRMED | names_r24_targets.tsv |
| 0x1ae7c0 | 3 | ilTemplateOpCmpPs_001ae7c0 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae7cc | 12 | ilTemplateOpSqrt_001ae7cc | CONFIRMED | names_r24_targets.tsv |
| 0x1ae7fc | 3 | ilTemplateOpRsq_001ae7fc | CONFIRMED | names_r24_targets.tsv |
| 0x1ae808 | 3 | ilTemplateOpRcp_001ae808 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae814 | 8 | ilTemplateCase49And4aIdx3SameAsIdx2RecipSqrtIeeeBroadcastX_001ae814 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae834 | 8 | ilTemplateCase49And4aIdx2RecipSqrtIeeeBroadcastX_001ae834 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae854 | 8 | ilTemplateCase49And4aIdx1RecipSqrtFfBroadcastX_001ae854 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae874 | 8 | ilTemplateCase49And4aIdx0RecipSqrtClampBroadcastX_001ae874 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae894 | 8 | ilTemplateCase48Idx3SameAsIdx2RecipSqrtIeeeW_001ae894 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae8b4 | 8 | ilTemplateCase48Idx2RecipSqrtIeeeW_001ae8b4 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae8d4 | 8 | ilTemplateCase48Idx1RecipSqrtFfW_001ae8d4 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae8f4 | 8 | ilTemplateCase48Idx0RecipSqrtClampW_001ae8f4 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae914 | 8 | ilTemplateCase47Idx3SameAsIdx2RecipIeeeW_001ae914 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae934 | 8 | ilTemplateCase47Idx2RecipIeeeW_001ae934 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae954 | 8 | ilTemplateCase47Idx1RecipFfW_001ae954 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae974 | 8 | ilTemplateCase47Idx0RecipClampW_001ae974 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae994 | 10 | ilTemplateCase46Idx3SameAsIdx2RecipIeeeLaneW_001ae994 | CONFIRMED | names_r24_targets.tsv |
| 0x1ae9bc | 10 | ilTemplateCase46Idx2RecipIeeeLaneW_001ae9bc | CONFIRMED | names_r24_targets.tsv |
| 0x1ae9e4 | 10 | ilTemplateCase46Idx1RecipFfLaneW_001ae9e4 | CONFIRMED | names_r24_targets.tsv |
| 0x1aea0c | 10 | ilTemplateCase46Idx0RecipClampLaneW_001aea0c | CONFIRMED | names_r24_targets.tsv |
| 0x1aea34 | 10 | ilTemplateCase45Idx3SameAsIdx2RecipIeeeLaneZ_001aea34 | CONFIRMED | names_r24_targets.tsv |
| 0x1aea5c | 10 | ilTemplateCase45Idx2RecipIeeeLaneZ_001aea5c | CONFIRMED | names_r24_targets.tsv |
| 0x1aea84 | 10 | ilTemplateCase45Idx1RecipFfLaneZ_001aea84 | CONFIRMED | names_r24_targets.tsv |
| 0x1aeaac | 10 | ilTemplateCase45Idx0RecipClampLaneZ_001aeaac | CONFIRMED | names_r24_targets.tsv |
| 0x1aead4 | 10 | ilTemplateCase44Idx3SameAsIdx2RecipIeeeLaneY_001aead4 | CONFIRMED | names_r24_targets.tsv |
| 0x1aeafc | 10 | ilTemplateCase44Idx2RecipIeeeLaneY_001aeafc | CONFIRMED | names_r24_targets.tsv |
| 0x1aeb24 | 10 | ilTemplateCase44Idx1RecipFfLaneY_001aeb24 | CONFIRMED | names_r24_targets.tsv |
| 0x1aeb4c | 10 | ilTemplateCase44Idx0RecipClampLaneY_001aeb4c | CONFIRMED | names_r24_targets.tsv |
| 0x1aeb74 | 10 | ilTemplateCase43Idx3SameAsIdx2RecipIeeeLaneX_001aeb74 | CONFIRMED | names_r24_targets.tsv |
| 0x1aeb9c | 10 | ilTemplateCase43Idx2RecipIeeeLaneX_001aeb9c | CONFIRMED | names_r24_targets.tsv |
| 0x1aebc4 | 10 | ilTemplateCase43Idx1RecipFfLaneX_001aebc4 | CONFIRMED | names_r24_targets.tsv |
| 0x1aebec | 10 | ilTemplateCase43Idx0RecipClampLaneX_001aebec | CONFIRMED | names_r24_targets.tsv |
| 0x1aec14 | 7 | ilTemplateOpProject_001aec14 | CONFIRMED | names_r24_targets.tsv |
| 0x1aec30 | 3 | ilTemplateNopToken5e_001aec30 | INFERRED | names_r26_templates.tsv |
| 0x1aec3c | 3 | ilTemplateOpEndloop_001aec3c | CONFIRMED | names_r24_targets.tsv |
| 0x1aec48 | 4 | ilTemplateIf66_001aec48 | INFERRED | names_r26_templates.tsv |
| 0x1aec58 | 4 | ilTemplateIf65_001aec58 | INFERRED | names_r26_templates.tsv |
| 0x1aec68 | 4 | ilTemplateOpIfnz_001aec68 | CONFIRMED | names_r24_targets.tsv |
| 0x1aec78 | 4 | ilTemplateOpIfc_001aec78 | CONFIRMED | names_r24_targets.tsv |
| 0x1aec88 | 3 | ilDefaultTemplateTable_001aec88 | CONFIRMED | names_r13_targets.tsv |
| 0x1aec94 | 3 | ilTemplateOpElse_001aec94 | CONFIRMED | names_r24_targets.tsv |
| 0x1aeca0 | 6 | ilTemplateIf65ContinueEndif_001aeca0 | INFERRED | names_r26_templates.tsv |
| 0x1aecb8 | 6 | ilTemplateIf66ContinueEndif_001aecb8 | INFERRED | names_r26_templates.tsv |
| 0x1aecd0 | 6 | ilTemplateOpContinuec_001aecd0 | CONFIRMED | names_r24_targets.tsv |
| 0x1aece8 | 6 | ilTemplateIf66BreakEndif_001aece8 | INFERRED | names_r26_templates.tsv |
| 0x1aed00 | 6 | ilTemplateIf65BreakEndif_001aed00 | INFERRED | names_r26_templates.tsv |
| 0x1aed18 | 6 | ilTemplateOpBreakc_001aed18 | CONFIRMED | names_r24_targets.tsv |
| 0x1aed30 | 6 | ilTemplateCase24_001aed30 | CONFIRMED | names_r13_targets.tsv |
| 0x1aed48 | 6 | ilTemplateCase17_001aed48 | CONFIRMED | names_r13_targets.tsv |
| 0x1aed60 | 3 | ilTemplateContinue_001aed60 | INFERRED | names_r26_templates.tsv |
| 0x1aed6c | 3 | ilTemplateCase17Scope72_001aed6c | CONFIRMED | names_r13_targets.tsv |
| 0x1aed78 | 4 | ilTemplateIf6f_001aed78 | INFERRED | names_r26_templates.tsv |
| 0x1aed88 | 3 | ilTemplateOpBreak_001aed88 | CONFIRMED | names_r24_targets.tsv |
| 0x1aed94 | 8 | ilTemplateOpCmov_001aed94 | CONFIRMED | names_r24_targets.tsv |
| 0x1aedb4 | 20 | ilTemplateOpSincosAndDxsincosFudoPs_001aedb4 | CONFIRMED | names_r24_targets.tsv |
| 0x1aee04 | 47 | ilTemplateCosFractReduced_001aee04 | INFERRED | names_r26_templates.tsv |
| 0x1aeec0 | 47 | ilTemplateSinFractReduced_001aeec0 | INFERRED | names_r26_templates.tsv |
| 0x1aef7c | 55 | ilTemplateSincosFractReduced_001aef7c | INFERRED | names_r26_templates.tsv |
| 0x1af058 | 103 | ilTemplateCosFractReducedPerLane_001af058 | INFERRED | names_r26_templates.tsv |
| 0x1af1f4 | 103 | ilTemplateSinFractReducedPerLane_001af1f4 | INFERRED | names_r26_templates.tsv |
| 0x1af390 | 14 | hwLimitsDefaultDataB_001af390 | CONFIRMED | names_r13_targets.tsv |
| 0x1af3c8 | 96 | vsHardwareTableField0E28Init_001af3c8 | CONFIRMED | names_r13_targets.tsv |
| 0x1af548 | 116 | vsHardwareTableField0C9CInit_001af548 | CONFIRMED | names_r13_targets.tsv |
| 0x1af718 | 7 | ilTemplateOpKillPs_001af718 | CONFIRMED | names_r24_targets.tsv |
| 0x1af734 | 26 | ilTemplateKillFetchThenKillGt_001af734 | INFERRED | names_r26_templates.tsv |
| 0x1af79c | 3 | ilTemplateOpTexlddFudoPs_001af79c | CONFIRMED | names_r24_targets.tsv |
| 0x1af7a8 | 3 | ilTemplateOpTexldbFudoPs_001af7a8 | CONFIRMED | names_r24_targets.tsv |
| 0x1af7b4 | 3 | ilTemplateOpTexldbVsKhanPs_001af7b4 | CONFIRMED | names_r24_targets.tsv |
| 0x1af7c0 | 7 | ilTemplateFetch3dNoiseMapTexStage_001af7c0 | INFERRED | names_r26_templates.tsv |
| 0x1af7dc | 7 | ilTemplateGetCompTexLodTexStage_001af7dc | INFERRED | names_r26_templates.tsv |
| 0x1af7f8 | 7 | ilTemplateOpTexldAnyAndTexlddVs_001af7f8 | CONFIRMED | names_r24_targets.tsv |
| 0x1af814 | 3 | ilTemplateOpSampleFudoPs_001af814 | CONFIRMED | names_r24_targets.tsv |
| 0x1af820 | 32 | ilTemplateOpCrs_001af820 | CONFIRMED | names_r24_targets.tsv |
| 0x1af8a0 | 36 | ilTemplateOpFaceforwardVs_001af8a0 | CONFIRMED | names_r24_targets.tsv |
| 0x1af930 | 14 | ilTemplateOpFaceforwardPs_001af930 | CONFIRMED | names_r24_targets.tsv |
| 0x1af968 | 3 | ilTemplateFailUnsupported_001af968 | CONFIRMED | names_r24_targets.tsv |
