# GLDriver functions, round 5, fork I4: the unclassified functions of the upper half (address >= 0xc0000)

Scope: the `FUN_` definitions of `Userspace/ATIRadeonX1000GLDriver/ppc/part_*.c` at 0xc0000 and above that no `names*.tsv` row, `class_methods.tsv` row or
`subsystem_map.tsv` subsystem covered (355 functions, 76 KB; the table at the end lists every one with its present name; 248 are named now, 107 are left, see section 8).
Method: callers/callees from the corpus text (a regex over every `FUN_` token, because most calls are written `((int (*)())FUN_x)(...)`), strings, GL / IL
constants, the R3xx register manual (`~/Documents/AMD Docs/R3xx_3D_Registers.pdf`), the RTTI class tree (`notes_compiler_ir.md` 1.1) and the nl_symbol_ptr cells
of `link/symbol_map.tsv`. Names: `names_I4_func.tsv` (func rows), `names_I4_ildis.tsv`, `names_I4_il.tsv`, `names_I4_hash.tsv`, `names_I4_pdec.tsv`,
`names_I4_pdec2.tsv`, `names_I4_loops2.tsv` (variable rows). Tier per row in the tables.

## 1. The R3xx pixel-shader ("PSN") decoded-instruction optimiser, 0xc0880 - 0xc6470 (CONFIRMED structure, INFERRED function roles)

This is the code behind the `R300PSN_*` dumps of `notes_shader_formats.md`: the PSN program (0x48-byte records: header, then RS = kind 1, TEX = kind 2,
ALU = kind 3/4) is converted into an array of **decoded entries**, optimised there, and written back.

`psnProgramToDecoded` (FUN_000c42f0) builds `decodedProgram` = `{[0] entry count, [1] temp count, [2] -> entries of 0xa0 bytes}`; `psnDecodedToProgram`
(FUN_000c4ce0) is the inverse; `psnDecDecodeHwInstruction` (FUN_000c1780) decodes one *hardware* instruction (register images) into an entry and
`psnDecEncodeHwWords` (FUN_000c1f80) encodes all entries back. The entry mode word (+0x8c) is 0 = RS, 1 = TEX, 2 = ALU, matching the three hardware tables.

Entry layout (the ALU case; offsets from the decode/encode pair checked against R3xx `US_ALU_RGB_ADDR` 0x46c0, `US_ALU_ALPHA_ADDR` 0x47c0,
`US_ALU_RGB_INST` 0x48c0, `US_ALU_ALPHA_INST` 0x49c0 - the four register images sit 0x100 apart at +0x98 / +0x198 / +0x298 / +0x398 of the program image):

| offset | field | evidence |
|---|---|---|
| +0x00 / +0x40 | half 0 (RGB) / half 1 (alpha) | `entry + h*0x40` in every loop over `0..1` |
| half +0x00 | render target (`TARGET`, 2 bits) | decode: `RGB_ADDR >> 29 & 3`; alpha `ALPHA_ADDR >> 25 & 3` |
| half +0x02 | output mask (`OMASK`: RGB 3 bits, alpha 8, depth `OMASK_W` 0x10) | decode `>> 26 & 7`; alpha bit 24 / bit 27 |
| half +0x04 | destination register (`ADDRD`) | `>> 18 & 0x1f` |
| half +0x06 | write mask (`WMASK`: RGB 3 bits, alpha 8) | `>> 23 & 7` / bit 23 |
| half +0x08 + 4*i | source slot i: ushort select (bits 0-1 address slot, 0x100 RGB-address group, 0x200 alpha-address group; slot 3 = result of another half), ushort swizzle word (low bits = component read mask built by `psnAccumulate*SelectRead` from six `{address, readMask}` records, 0x300 replicate mode, 0x1000 / 0x2000 = `MOD` negate / abs) | `psnDecRecomputeSourceUsage`, `SEL_A/B/C` + `MOD_A/B/C` fields at bits 4:0/6:5, 11:7/13:12, 18:14/20:19 of `US_ALU_*_INST` |
| half +0x14, +0x1a | per-address-slot read masks (3 ushorts each, RGB group / alpha group) | `psnDecRecomputeSourceUsage` |
| half +0x28 | opcode (internal code; table at 0x1dbf98 / 0x1dc158 maps to the 4-bit `OP`) | `psnDecEncodeHwWords` |
| half +0x2a | pre-subtract op (`SRCP_OP`, bits 22:21 of `RGB_INST`) | decode `word298 >> 0x15 & 3` |
| half +0x2c | output scale as float (1, 2, 4, 8, 0.5 ... from the 3-bit `OMOD`) | table 0x1dc198, encode converts back with the 2^k switch |
| half +0x30 | flags (bit 3 = clamp from `RGB_INST` bit 30; recomputed bits 1, 2, 4-6, 8-12) | |
| half +0x34/+0x36/+0x38 | per-source flags (0x20 negate, 0x40 abs, 8 / 0x10 / 1 / 2 / 4 kinds) | `psnDecRecomputeSourceUsage` |
| entry +0x80 .. +0x8a | six address slots: RGB `ADDR0..2` (+0x80/82/84), alpha `ADDR0..2` (+0x86/88/8a); 0xffff = unused, bit 15 = constant (`ADDR >= 32`, minus 0x20) | decode `word98 & 0x3f, >>6, >>12` and the `0x20` fix-up loop |
| entry +0x8c / +0x90 | mode (0 RS, 1 TEX, 2 ALU) / instruction index | decode / encode |

Functions: `psnDecRecomputeSourceUsage` (0xc0880), `psnDecCanonicalizeEntry` (0xc0fd0; the compiler inlined both into `psnDecDecodeHwInstruction` and the
usage pass into the canonicaliser), `psnDecAllocateTempsAndCompact` (0xc2834: linear-scan temp allocation + dead entry removal + encode),
`psnDecTryRebindAddressWithRollback` (0xc38a0, saves the 0xa0-byte entry and restores it on failure), `psnDecTryMergeAddressSlots`,
`psnDecReplaceSourceAddress`, `psnDecRetargetSourceReg`, the swap / sort helpers, the read-mask predicates `psnDecReadsRegMask` ..., and the register
allocator `psnReallocateTemps` (0xc6470) with `psnRaReleaseUse` / `psnRaAssignDefinition` (interval table + sorted free list).

## 2. The SC (shader compiler) public API and its dump helpers, 0xcd154 - 0xd4e8c

`FUN_000c6ff0` fills a callback block (alloc `FUN_000c6e40`, free, fopen / fclose / fwrite / fread, printf-append: `scCallback*`) and hands it, with the chip id
test over the X1000 / X1xxx PCI ids, to the creator `FUN_000cd05c`. Entry points are variadic wrappers (`scDumpSrcShader`, `scDumpShader`,
`scDumpShaderToString`, `scDisassembleIL`) around `*Impl` functions that print the `SC_SRCSHADER Dump` / `SC_SHADERSTATE: ...` text through the sink
record (`scLogToSink`), the VS dumpers (`vsdis*`, `vsDisassemble*` were named earlier) and the PSN dumper `FUN_000d183c`.

## 3. The AMD-IL token disassembler `ildis*`, 0xda904 - 0xe0740

`ildisPrintInstruction` (FUN_000ddbcc, documented in `notes_shader_formats.md` 5) is driven by `ildisRun`; its operand printers decode the token layout:
destination / source token = register index (bits 0-15), register type (16-21), +1 modifier dword when bit 22, relative address by bits 23-24
(0x800000 address register + offset, 0x1000000 nested operand), bit 25 extra operand, bit 26 literal-index dword; source modifier dword = swizzle
(4 x 3 bits), negate bits 3/7/11/15, `_invert` 0x10000, `_bias` 0x20000, `_x2` 0x40000, `_sign` 0x80000, `_abs` 0x100000, `_divcomp` bits 21-23.
The ctx is `{+0 error count, +4 first token, +8 cursor, +0xc count, +0x10 line buffer (0x200), +0x210 sink record, +0x214 sink arg, +0x218 is-pixel, +0x21c indent}`.
Every printer's tail parameters `param_3..param_8` are Ghidra register pass-throughs (r5..r10) forwarded to `ildisAppendf`.

## 4. IL program assembly helpers, 0xc71e0 - 0xc8e30

Helpers of `ilAssembleProgram` / `ilRewriteForTextureState` (records at the 0x2xxx offsets of the program record): free-constant bitmaps (+0xc, +0x2c),
`ilEmitProjectiveDivide` (rcp + mul on the texcoord q), `ilEmitShadowCompare` (the compare function is the GL enum 0x200-0x207 at record+0x138+unit*4),
`ilEmitPrologue`, `ilCopyInstructionRemapped` (copies one instruction rewriting the output register through the tables at +0x21e0/+0x2200/+0x2208/+0x232c),
`ilMarkInstructionRegistersUsed`.

## 5. Compiler: constants, value numbering, hash tables, small leaves

* ConstKey (`Compiler__getOrCreateLoadConstN` + wrappers, `ConstKey__compare1..4`, `ConstKey__lanes1..4`, `ConstKey__compareOrdered`): hash-consed constant
  operand records; the scratch key is `compiler[10]` (presence bits at +0x15c, operands 0x18 bytes at +0x10).
* ValueKey per-opcode simplifiers called from `FUN_0017f7ec` (mul by 0 / +-1, dot with a unit vector, power-of-two sources folded into the output scale
  (`outputScaleFromExponent` table 0x1af9e0 = 0.125 .. 8), x op x, max(x,-x), compare of equal sources). The dispatcher is a decision tree on the opcode,
  so which simplifier belongs to which `Ir*` opcode was NOT assigned (only by content).
* Constructors recovered through `PTR_DAT_<cell> + 8` -> vtable -> RTTI class: `IRVertexFetch`, `IRTextureFetchGradients`, `IRMemLoad`, `IRMemStore`,
  `IRZeroary`, `IRNop`, `IRMov`, `IRExportColorAndFog`, `IRUndefined`, `IRLoadTemp`, `AddrIndexedSet`, `LoopRegister`, `BreakOrContinueBlock`, `DListNode`
  (`<Class>__ctor_<addr>`, complete / base object pairs).
* HashTable family (`HashTable__grow`, pair table `HashTable__insert_1950e0`, destroy, findEntry), `Vector__shellSort`, `Arena__bytesInUse`,
  interference-matrix pair index (`pairIndex`, `InterferenceMatrix__setPair/testPair`), RegKind table accessors (`RegKind__flagBit1/9`, `RegKind__laneCount`).

## 5b. Variable names: web-based splits (new tools)

Most variables of the PSN functions are reused registers (`uVar16` is the source swizzle word, then a write mask, then a read mask ...). They were named with the
def-use webs of `Tools/userspace/find_webs.py` (webs are closed under def-use, so the generated `use` rows pass the split gate):
`find_webs.py DIR FUNC --all` lists the webs, `Tools/userspace/emit_webs.py DIR FUNC SPEC.tsv` turns `VAR  webs  name  tier  evidence` lines into rows
(with a line filter `1<200` for a web that find_webs joins through an assignment inside a condition), and `Tools/userspace/map_webs.py DIR FUNC_A FUNC_B SPEC_A.tsv`
carries the names of a named function to a near-duplicate by aligning the statements: `psnDecRecomputeSourceUsage` -> the copy inlined into
`psnDecCanonicalizeEntry` -> the copies inlined into `psnDecDecodeHwInstruction` (rows are only taken when the B web is wholly inside the aligned code).
`names_G2.tsv` had named seven variables of `psnDecDecodeHwInstruction` for the whole function (`word98`, `modeOrEntry` ...); they held several roles, so
the rows were removed and the variables renamed per web (`rgbAddrWord`, `alphaAddrWord`, `rgbInstWord` = the R3xx `US_ALU_*` images).

## 6. What the gate and the tables taught (for the next round)

* A variable that another table already renamed through `use` rows (anchors are written against Ghidra's text) must not be touched by a new row in the same
  function: `HashTable__grow` / `HashTable__grow_194e44` (E1/W6 rows) made `apply_names.py --check` fail for every anchor of the function when any
  local row was added; the rows were dropped.
* Names produced by other tables (`allocation`, `loopIndex*`) are not placeholders: renaming them breaks those tables' `use` anchors.
* Anchors of `use` rows must use the *Ghidra* name of a renamed function (`FUN_000da8fc`, not `returnZero_da8fc`).

## 7. libGLProgrammability yyparse stack-overlay temporaries (target B): measured, not renamed

`Tools/userspace/yygrammar/names_gen` (fork R1b) already names the deterministic idioms per web (std::string refcount release, `$k` value-stack loads named from
the rule, virtual-call results from the vtable slot, pool allocations by class). What is left in `yyparse` (3.7k occurrences, 206 variables) is:

* `local_850 .. local_7cc` and `local_83c`-style words: the words of **address-taken** stack objects (`&local_850`, `&local_840`, `&local_820`, `&local_7f0`,
  `&local_800`: a `std::string` of 2 words, a `TPublicType` of 7 or a `TType` of 10 words, depending on the case). `find_webs.py` refuses these (address taken),
  and splitting them per case with `use` rows would put the words of one object into different stack variables and break the adjacency the code relies on
  (the corpus rule is to fix layouts, never to split them). Whole-variable names would be false in all but one case.
* the register copies `pTVar3/31/32/33/34`, `iVar55`, `uVar57` ...: 30 / 4 / 4 / 6 / 3 unnamed webs for the pTVar group (304 lines, mostly `pTVar33`'s
  193-line web that joins the yyval carry across the whole function), 70 webs (259 lines) for `iVar55` (virtual calls whose receiver class the R1b rules could not
  resolve, `*(yyvsp + off)` loads in regions that are not case-pure), 30 for `uVar57`, 27 for `piVar61`. Control flow jumps between case bodies (`goto LAB_...`,
  `switchD_97ba39c8_caseD_*`), so a per-case segment is not closed under def-use and the webs are the only safe unit; each of the ~200 remaining webs is a 2-5 line
  fragment whose role needs the receiver class or the rule, which the existing generator already tried.
* 89 single-use arrays `local_XXX[4]` (`local_5e0[0] = local_840;`): the allocator copy passed to `_Rep::_M_destroy`; whole-variable names would be possible
  but carry only "allocator copy of string N of rule R".

Nothing was changed in libGLProgrammability by this fork.

## 8. Left (74 of the 355 functions still carry a FUN_ name)

Unnamed because the evidence does not name them: the IL -> IR translator leaves (0xf8588 - 0xf8d50; `FUN_000f8d50` converts a relative-address IL operand), the
Block / instruction navigation helpers around 0x130728 - 0x130e68 (register allocator front end), the liveness scan `FUN_00137f14`, the pair-packer helpers
0x140e5c - 0x143664, the opcode-class initialisers 0x11358c - 0x11370c, and a group of 4-byte stubs at 0x1a3254 - 0x1a3264.

## Appendix. All 355 candidate functions (address >= 0x0c0000) with their current names

| address | bytes | name |
|---|---|---|
| 0x0c0880 | 1832 | `psnDecRecomputeSourceUsage` |
| 0x0c0fd0 | 1936 | `psnDecCanonicalizeEntry` |
| 0x0c1780 | 1416 | `psnDecDecodeHwInstruction` |
| 0x0c1d60 | 276 | `psnDecTrySwapAddressSlots` |
| 0x0c1e90 | 232 | `psnDecSortAddressSlots` |
| 0x0c1f80 | 1824 | `psnDecEncodeHwWords` |
| 0x0c2834 | 1536 | `psnDecAllocateTempsAndCompact` |
| 0x0c2e40 | 48 | `psnMaskIsSingleComponent` |
| 0x0c2e70 | 36 | `psnDecAlphaDestIs` |
| 0x0c2ea0 | 120 | `psnDecAlphaComponentReadsReg` |
| 0x0c2f20 | 140 | `psnDecAnySourceIsReg` |
| 0x0c2fb0 | 148 | `psnDecAnyPartialSourceIsReg` |
| 0x0c3050 | 64 | `psnDecMaskCoveredByDests` |
| 0x0c3090 | 52 | `psnDecFirstFreeAddressSlot` |
| 0x0c30d0 | 40 | `psnDecHasFreeAddressSlot` |
| 0x0c3100 | 312 | `psnDecRetargetSourceReg` |
| 0x0c3240 | 916 | `psnDecReplaceSourceAddress` |
| 0x0c3600 | 120 | `psnDecReadsRegMask` |
| 0x0c3680 | 100 | `psnDecSourceHasPartialMask` |
| 0x0c36f0 | 60 | `psnDecDestMatchesRegMask` |
| 0x0c3740 | 120 | `psnDecCanFoldIntoSlot` |
| 0x0c37c0 | 216 | `psnDecSwapAddressSlotsInSources` |
| 0x0c38a0 | 1208 | `psnDecTryRebindAddressWithRollback` |
| 0x0c3d60 | 232 | `psnConstantComponentsAreOne` |
| 0x0c3e50 | 376 | `psnDecRangeHasConflict` |
| 0x0c3fd0 | 784 | `psnDecTryMergeAddressSlots` |
| 0x0c42f0 | 2444 | `psnProgramToDecoded` |
| 0x0c4ce0 | 1484 | `psnDecodedToProgram` |
| 0x0c5460 | 72 | `psnAccumulateRgbSelectRead` |
| 0x0c57b0 | 104 | `psnAccumulateAlphaSelectRead` |
| 0x0c59c0 | 580 | `psnRaReleaseUse` |
| 0x0c5c50 | 476 | `psnRaAssignDefinition` |
| 0x0c6470 | 1284 | `psnReallocateTemps` |
| 0x0c6e50 | 40 | `scCallbackFree` |
| 0x0c6e80 | 16 | `scCallbackGetFlagZero` |
| 0x0c6ef0 | 88 | `scCallbackFopen` |
| 0x0c6f60 | 44 | `scCallbackFclose` |
| 0x0c6f90 | 40 | `scCallbackFwrite` |
| 0x0c6fc0 | 40 | `scCallbackFread` |
| 0x0c71e0 | 76 | `ilFreeRecordList` |
| 0x0c7350 | 72 | `ilAllocLowestFreeBit8` |
| 0x0c73a0 | 20 | `ilNextCounterValue` |
| 0x0c73c0 | 144 | `ilPopFreeRegister` |
| 0x0c7460 | 468 | `ilEmitProjectiveDivide` |
| 0x0c7650 | 680 | `ilEmitShadowCompare` |
| 0x0c8110 | 1252 | `ilEmitPrologue` |
| 0x0c8760 | 104 | `ilRemapSourceOperandRegister` |
| 0x0c87d0 | 296 | `ilMarkOperandRegisterUsed` |
| 0x0c8910 | 400 | `ilMarkInstructionRegistersUsed` |
| 0x0c8aa0 | 780 | `ilCopyInstructionRemapped` |
| 0x0c8de0 | 76 | `ilPushDclRecord` |
| 0x0c8e30 | 28 | `ilStoreFloat4Constant` |
| 0x0cd154 | 92 | `scDestroy` |
| 0x0cd1d8 | 20 | `scCheckHandle` |
| 0x0cd1ec | 40 | `scDisassembleIL` |
| 0x0cd214 | 40 | `scDumpSrcShader` |
| 0x0cd23c | 40 | `scDumpShader` |
| 0x0cd264 | 40 | `scDumpShaderToString` |
| 0x0cd388 | 28 | `scDisassembleILImpl` |
| 0x0cd3a4 | 96 | `scLogToSink` |
| 0x0cd404 | 1952 | `scDumpSrcShaderImpl` |
| 0x0cdba4 | 64 | `scDumpShaderImpl` |
| 0x0cdbe4 | 60 | `scDumpShaderToStringImpl` |
| 0x0cdc24 | 24 | `scShaderStateFlag` |
| 0x0ce020 | 24 | `vsdisClearSinkRecord` |
| 0x0ce038 | 24 | `vsdisClearSinkRecord2` |
| 0x0ce4e4 | 48 | `vsdisPrintInputDx` |
| 0x0ce514 | 864 | `vsdisPrintOutputMapping` |
| 0x0ce88c | 480 | `vsdisPrintShaderData` |
| 0x0cfc94 | 144 | `vsdisFlowOpcodeName` |
| 0x0cfd24 | 524 | `vsdisPrintFlowInstruction` |
| 0x0d10a8 | 52 | `psnSwizzleIsAlphaSourceForm` |
| 0x0d4de8 | 16 | `psnClearSinkRecord` |
| 0x0d4df8 | 16 | `psnClearSinkRecord2` |
| 0x0d4e08 | 92 | `scDumpPixelProgramPsn` |
| 0x0d4e64 | 40 | `scDumpPixelProgramToStringStub` |
| 0x0d4e8c | 60 | `scDumpPixelProgram` |
| 0x0d9bac | 228 | `scStoreConstantComponent` |
| 0x0da394 | 68 | `scSetCallbackTables` |
| 0x0da438 | 32 | `FUN_000da438` |
| 0x0da458 | 96 | `scDestroyCompilerObject` |
| 0x0da8a8 | 40 | `ildisInitContext` |
| 0x0da8d0 | 16 | `ildisSkipToken` |
| 0x0da8e0 | 20 | `ildisSetIndent` |
| 0x0da984 | 120 | `ildisFlushLine` |
| 0x0daab0 | 412 | `ildisPrintNegateComponents` |
| 0x0dac4c | 204 | `ildisComponentSelectChar` |
| 0x0dae5c | 260 | `ildisPrintResultModifiers` |
| 0x0daf7c | 172 | `ildisPrintElementFormat` |
| 0x0db048 | 224 | `ildisPrintFormatXyzw` |
| 0x0db128 | 156 | `ildisModComponentChar` |
| 0x0db1c4 | 304 | `ildisPrintDestinationWriteMask` |
| 0x0db2f4 | 92 | `ildisPrintUnsigned` |
| 0x0db350 | 244 | `ildisPrintCmpVal` |
| 0x0db458 | 260 | `ildisPrintUsage` |
| 0x0db574 | 352 | `ildisPrintFixedPoint` |
| 0x0db6d4 | 196 | `ildisPrintTexelOffsets` |
| 0x0db798 | 132 | `ildisPrintSignedField` |
| 0x0db81c | 196 | `ildisPrintAddressOffsetImmediate` |
| 0x0db8e0 | 88 | `ildisPrintResourceSampler` |
| 0x0db938 | 280 | `ildisPrintAnisoMode` |
| 0x0dba6c | 216 | `ildisPrintMipFilter` |
| 0x0dbb44 | 124 | `ildisPrintFilterName` |
| 0x0dbbc0 | 284 | `ildisPrintFilterModes` |
| 0x0dbcdc | 192 | `ildisPrintShadowMode` |
| 0x0dbd9c | 124 | `ildisPrintBoundComponent` |
| 0x0dbe18 | 284 | `ildisPrintDclvoutOperands` |
| 0x0dbf34 | 356 | `ildisPrintDclpinOperands` |
| 0x0dc098 | 276 | `ildisPrintDclvOperands` |
| 0x0dc1ac | 280 | `ildisPrintDclpiOperands` |
| 0x0dc2c4 | 196 | `ildisPrintResourceType` |
| 0x0dc3b0 | 164 | `ildisPrintDclptCoordMode` |
| 0x0dc454 | 104 | `ildisPrintDcldefComponent` |
| 0x0dc4bc | 192 | `ildisPrintDcldefComponents` |
| 0x0dc57c | 220 | `ildisPrintZeroOp` |
| 0x0dc658 | 196 | `ildisPrintOutputTopology` |
| 0x0dc71c | 268 | `ildisPrintInputPrimitive` |
| 0x0dc83c | 80 | `ildisPrintStage` |
| 0x0dc88c | 324 | `ildisPrintTexldmsModifiers` |
| 0x0dc9d0 | 36 | `ildisPrintNormalizeFlag` |
| 0x0dc9f4 | 36 | `ildisPrintRoundFlag` |
| 0x0dca18 | 36 | `ildisPrintSampleFlag` |
| 0x0dca3c | 36 | `ildisPrintCentroidFlag` |
| 0x0dca60 | 212 | `ildisPrintSampleModifiers` |
| 0x0dcb34 | 152 | `ildisPrintLoadModifiers` |
| 0x0dcbcc | 244 | `ildisPrintMatrixMode` |
| 0x0dccd4 | 264 | `ildisPrintRelop` |
| 0x0dcdf4 | 256 | `ildisPrintHeader` |
| 0x0dcef4 | 640 | `ildisPrintRegisterType` |
| 0x0dd1f8 | 1220 | `ildisPrintSourceOperand` |
| 0x0dd6bc | 988 | `ildisPrintDestinationOperand` |
| 0x0dda98 | 124 | `ildisPrintDestAnd3Sources` |
| 0x0ddb14 | 104 | `ildisPrintDestAnd2Sources` |
| 0x0ddb7c | 80 | `ildisPrintDestAnd1Source` |
| 0x0ddbcc | 10080 | `ildisPrintInstruction` |
| 0x0e0640 | 84 | `ildisRun` |
| 0x0e0694 | 68 | `ildisPrintProgram` |
| 0x0e06d8 | 104 | `ildisDisassembleTokens` |
| 0x0e0740 | 80 | `ildisDisassembleBody` |
| 0x0e0794 | 36 | `Compiler__setOptionBit` |
| 0x0e07b8 | 36 | `Compiler__clearOptionBit` |
| 0x0e0cc8 | 8 | `testBit24` |
| 0x0e0ea0 | 28 | `noop_e0ea0` |
| 0x0e0ebc | 44 | `isWhitespaceChar` |
| 0x0e138c | 28 | `noop_e138c` |
| 0x0e13a8 | 12 | `FUN_000e13a8` |
| 0x0e144c | 24 | `FUN_000e144c` |
| 0x0e1464 | 28 | `Compiler__timerOutputFileName` |
| 0x0e1484 | 80 | `Compiler__releaseOutputBuffer` |
| 0x0e14d4 | 16 | `Compiler__setTableEntry534` |
| 0x0e15b8 | 36 | `Compiler__propagateFlag5a1Bit1` |
| 0x0e15dc | 64 | `Compiler__selectEntry534ByProgramFlags` |
| 0x0e16b8 | 76 | `Compiler__selectBlockByProgramFlags` |
| 0x0e1704 | 88 | `Compiler__setBitInSelectedBlockB8` |
| 0x0e175c | 88 | `Compiler__setBitInSelectedBlockD8` |
| 0x0e17b4 | 88 | `Compiler__setBitInSelectedBlock98` |
| 0x0e2780 | 140 | `FUN_000e2780` |
| 0x0e280c | 44 | `FUN_000e280c` |
| 0x0e2838 | 20 | `FUN_000e2838` |
| 0x0e284c | 20 | `FUN_000e284c` |
| 0x0e2a44 | 16 | `moduloDifference` |
| 0x0e2ee4 | 32 | `FUN_000e2ee4` |
| 0x0e4400 | 8 | `setWord30` |
| 0x0e468c | 132 | `FUN_000e468c` |
| 0x0e7924 | 104 | `Block__nearestCommonAncestor` |
| 0x0e798c | 20 | `Block__vectorF8NonEmpty` |
| 0x0e79fc | 20 | `Block__vectorD4NonEmpty` |
| 0x0e7c98 | 88 | `Block__resolveRedirect` |
| 0x0e7de4 | 172 | `Block__isInVectorD4Of` |
| 0x0eac08 | 88 | `BreakOrContinueBlock__ctor_eac08` |
| 0x0eac60 | 88 | `BreakOrContinueBlock__ctor_eac60` |
| 0x0ec1ec | 28 | `callTargetSlot25` |
| 0x0f2d08 | 16 | `FUN_000f2d08` |
| 0x0f2e50 | 72 | `laneBytes__mapTwoThreeToOne` |
| 0x0f2e98 | 144 | `laneBytes__mergeOneAndTwo` |
| 0x0f308c | 72 | `laneBytes__commonSelect` |
| 0x0f3764 | 84 | `laneBytes__clearSetLanes` |
| 0x0f388c | 124 | `laneMask__fromSelectBytes` |
| 0x0f4a70 | 20 | `isRegKindBelow21` |
| 0x0f4bc8 | 32 | `floatLess` |
| 0x0f4be8 | 92 | `BitSet__findFirstSet` |
| 0x0f4c48 | 268 | `ConstKey__compareOrdered` |
| 0x0f4d54 | 44 | `ConstKey__countPresentOperands` |
| 0x0f53c0 | 396 | `Compiler__getOrCreateLoadConst3` |
| 0x0f554c | 352 | `Compiler__getOrCreateLoadConst2` |
| 0x0f56ac | 324 | `Compiler__getOrCreateLoadConst1` |
| 0x0f645c | 376 | `Compiler__getOrCreateConstVector4` |
| 0x0f65d4 | 396 | `Compiler__getOrCreateConstVector3` |
| 0x0f6760 | 352 | `Compiler__getOrCreateConstVector2` |
| 0x0f68c0 | 324 | `Compiler__getOrCreateConstVector1` |
| 0x0f771c | 340 | `IRInst__makeLiteralVec4Int` |
| 0x0f79c4 | 332 | `IRInst__makeLiteralVec4Float` |
| 0x0f8588 | 72 | `lazyEntryGet` |
| 0x0f8980 | 20 | `FUN_000f8980` |
| 0x0f89b4 | 52 | `tableWordOrEight` |
| 0x0f89e8 | 36 | `remapSelect1To0` |
| 0x0f8a0c | 36 | `remapSelectSmall` |
| 0x0f8a30 | 112 | `FUN_000f8a30` |
| 0x0f8c88 | 64 | `FUN_000f8c88` |
| 0x0f8ccc | 132 | `FUN_000f8ccc` |
| 0x0f8d50 | 568 | `FUN_000f8d50` |
| 0x103e54 | 28 | `constantZeroFloat` |
| 0x103e70 | 16 | `isLessThan2` |
| 0x103fe8 | 52 | `operandsHaveSameConstant` |
| 0x1040b0 | 84 | `RegKind__laneCount` |
| 0x104330 | 52 | `IRVertexFetch__initSemantics` |
| 0x1043a0 | 80 | `FUN_001043a0` |
| 0x10485c | 120 | `Inst__nearestCommonAncestorBlock` |
| 0x1048d4 | 56 | `FUN_001048d4` |
| 0x10490c | 56 | `FUN_0010490c` |
| 0x104944 | 56 | `FUN_00104944` |
| 0x104d68 | 184 | `FUN_00104d68` |
| 0x105d04 | 184 | `IRInst__firstLiteralSourceValue` |
| 0x1061b0 | 128 | `FUN_001061b0` |
| 0x107250 | 128 | `IRVertexFetch__ctor_107250` |
| 0x1072d0 | 128 | `IRVertexFetch__ctor_1072d0` |
| 0x107600 | 76 | `IRTextureFetchGradients__ctor_107600` |
| 0x107864 | 76 | `IRTextureFetchGradients__ctor_107864` |
| 0x10792c | 84 | `IRMemLoad__ctor_10792c` |
| 0x1079d4 | 84 | `IRMemStore__ctor_1079d4` |
| 0x107a28 | 76 | `IRZeroary__ctor_107a28` |
| 0x107a74 | 92 | `IRNop__ctor_107a74` |
| 0x107b4c | 92 | `IRNop__ctor_107b4c` |
| 0x107ba8 | 76 | `IRZeroary__ctor_107ba8` |
| 0x107d38 | 112 | `IRMov__ctor_107d38` |
| 0x108870 | 84 | `IRExportColorAndFog__ctor_108870` |
| 0x1088c4 | 84 | `IRExportColorAndFog__ctor_1088c4` |
| 0x108e8c | 84 | `IRUndefined__ctor_108e8c` |
| 0x108f5c | 84 | `IRUndefined__ctor_108f5c` |
| 0x10900c | 92 | `IRUndefined__ctor_10900c` |
| 0x1093b8 | 112 | `IRLoadTemp__ctor_1093b8` |
| 0x1094fc | 88 | `IRLoadTemp__ctor_1094fc` |
| 0x1095b4 | 96 | `IRLoadTemp__ctor_1095b4` |
| 0x10aad4 | 40 | `outputScaleFromExponent` |
| 0x10aafc | 68 | `isOutputScaleValue` |
| 0x10ab40 | 76 | `outputScaleExponent` |
| 0x10ab8c | 172 | `tryOutputScaleExponent` |
| 0x10b820 | 220 | `evaluateCompareFloats` |
| 0x10dbfc | 36 | `FUN_0010dbfc` |
| 0x10dde4 | 8 | `FUN_0010dde4` |
| 0x10e55c | 16 | `FUN_0010e55c` |
| 0x10e7b8 | 92 | `FUN_0010e7b8` |
| 0x10e870 | 84 | `FUN_0010e870` |
| 0x10e8c4 | 32 | `FUN_0010e8c4` |
| 0x112fc4 | 16 | `FUN_00112fc4` |
| 0x112fd4 | 16 | `FUN_00112fd4` |
| 0x112fe4 | 172 | `FUN_00112fe4` |
| 0x113554 | 56 | `mulFloatZeroAnnihilates` |
| 0x11358c | 28 | `FUN_0011358c` |
| 0x1135a8 | 24 | `FUN_001135a8` |
| 0x1135c0 | 44 | `FUN_001135c0` |
| 0x1136e4 | 40 | `FUN_001136e4` |
| 0x11370c | 40 | `FUN_0011370c` |
| 0x122f28 | 124 | `FUN_00122f28` |
| 0x125f40 | 84 | `AddrIndexedSet__ctor_125f40` |
| 0x125fe8 | 76 | `LoopRegister__ctor_125fe8` |
| 0x126878 | 44 | `RegKind__flagBit1` |
| 0x1268a4 | 44 | `RegKind__flagBit9` |
| 0x1268d0 | 40 | `RegKind__byte4` |
| 0x127264 | 8 | `ConstKey__lanes1` |
| 0x12726c | 16 | `ConstKey__lanes2` |
| 0x12727c | 24 | `ConstKey__lanes3` |
| 0x127294 | 32 | `ConstKey__lanes4` |
| 0x1272b4 | 16 | `FUN_001272b4` |
| 0x1272d4 | 80 | `FUN_001272d4` |
| 0x12766c | 52 | `ConstKey__compare1` |
| 0x1276a0 | 92 | `ConstKey__compare2` |
| 0x1276fc | 124 | `ConstKey__compare3` |
| 0x127778 | 156 | `ConstKey__compare4` |
| 0x127814 | 60 | `keyEqualsThreeWords` |
| 0x127fd8 | 32 | `FUN_00127fd8` |
| 0x12c0e4 | 80 | `Program__hasKillTexture` |
| 0x1304a4 | 200 | `FUN_001304a4` |
| 0x13056c | 40 | `BitSet__setBit42c` |
| 0x130594 | 136 | `FUN_00130594` |
| 0x130728 | 164 | `FUN_00130728` |
| 0x1307cc | 44 | `FUN_001307cc` |
| 0x1307f8 | 228 | `FUN_001307f8` |
| 0x130944 | 20 | `FUN_00130944` |
| 0x130a78 | 68 | `FUN_00130a78` |
| 0x130e68 | 88 | `FUN_00130e68` |
| 0x134aa8 | 8 | `FUN_00134aa8` |
| 0x134ab0 | 8 | `FUN_00134ab0` |
| 0x134ab8 | 100 | `FUN_00134ab8` |
| 0x134b1c | 60 | `pairIndex` |
| 0x134b58 | 76 | `InterferenceMatrix__setPair` |
| 0x134ba4 | 76 | `InterferenceMatrix__testPair` |
| 0x134c18 | 188 | `FUN_00134c18` |
| 0x134db0 | 56 | `FUN_00134db0` |
| 0x134fc0 | 80 | `storeAfterLocate` |
| 0x137e74 | 36 | `BitSet__testRegisterLane` |
| 0x137f14 | 364 | `FUN_00137f14` |
| 0x13922c | 104 | `FUN_0013922c` |
| 0x139344 | 80 | `IRInst__isOpcodeInSet139344` |
| 0x1396a0 | 48 | `IRInst__markOpcode13After12` |
| 0x140e5c | 20 | `FUN_00140e5c` |
| 0x140e70 | 12 | `FUN_00140e70` |
| 0x141090 | 112 | `FUN_00141090` |
| 0x1418b0 | 128 | `PostPack__canPairInEitherOrder` |
| 0x143664 | 80 | `FUN_00143664` |
| 0x1436b4 | 168 | `PostPack__buildCandidate` |
| 0x14675c | 44 | `FUN_0014675c` |
| 0x147044 | 152 | `FUN_00147044` |
| 0x147398 | 120 | `IRInst__isOpcodeInSet147398` |
| 0x1729bc | 108 | `FUN_001729bc` |
| 0x176350 | 148 | `classifyConstantRange` |
| 0x1763e4 | 144 | `ValueKey__rowLanesAllEqual` |
| 0x176474 | 104 | `ValueKey__findOrInsertLiteral` |
| 0x1764fc | 28 | `ValueKey__sourceKindIs1` |
| 0x176518 | 28 | `ValueKey__sourceKindIs4` |
| 0x176854 | 128 | `ValueKey__lanesAreUnset` |
| 0x177ad0 | 124 | `ValueKey__cancelNegatedSourcePair` |
| 0x1789d4 | 28 | `IRInst__isOpcode8bOr8c` |
| 0x1789f0 | 168 | `FUN_001789f0` |
| 0x179894 | 184 | `ValueKey__foldCompareSameSourcesValueNumber` |
| 0x17ab4c | 472 | `ValueKey__foldDotPowerOfTwoIntoOutputScale` |
| 0x17bf70 | 392 | `ValueKey__foldDot3SingleLaneSource` |
| 0x17c0f8 | 332 | `ValueKey__foldDot4UnitVectorSource` |
| 0x17c41c | 136 | `ValueKey__replaceWithSource2IfSourcesEqual23` |
| 0x17c4a4 | 316 | `FUN_0017c4a4` |
| 0x17c774 | 276 | `ValueKey__foldMulByPlusMinusOne` |
| 0x17c888 | 136 | `ValueKey__replaceWithSource1IfSourcesEqual` |
| 0x17d3f8 | 232 | `ValueKey__foldCompareSameSourcesToConstant` |
| 0x17d4e0 | 156 | `ValueKey__replaceWithZeroIfSourcesEqual` |
| 0x17d57c | 148 | `ValueKey__foldMulByZero` |
| 0x17e1f4 | 324 | `ValueKey__foldMulPowerOfTwoIntoOutputScale` |
| 0x17e658 | 112 | `ValueKey__foldMadZeroAddend` |
| 0x17e6c8 | 280 | `ValueKey__foldMadByPlusMinusOne` |
| 0x17f594 | 8 | `ValueKey__foldMaxOfNegatedPair` |
| 0x17f59c | 8 | `ValueKey__foldMinOfNegatedPair` |
| 0x184bcc | 36 | `compareIntsAscending` |
| 0x18f850 | 200 | `FUN_0018f850` |
| 0x193a8c | 88 | `FUN_00193a8c` |
| 0x193ae4 | 88 | `FUN_00193ae4` |
| 0x193eb8 | 76 | `Arena__bytesInUse` |
| 0x194060 | 72 | `DListNode__ctor_194060` |
| 0x1940f0 | 280 | `Vector__shellSort` |
| 0x1943f0 | 276 | `HashTable__destroy_1943f0` |
| 0x194504 | 276 | `HashTable__destroy_194504` |
| 0x194618 | 264 | `HashTable__findEntry` |
| 0x194aa8 | 260 | `HashTable__grow` |
| 0x194e44 | 260 | `HashTable__grow_194e44` |
| 0x1950e0 | 208 | `HashTable__insert_1950e0` |
| 0x19ebdc | 172 | `FUN_0019ebdc` |
| 0x19ec88 | 108 | `ilSkipRelativeAddressWords` |
| 0x19ecf4 | 192 | `ilSourceOperandWordCount` |
| 0x19edb4 | 84 | `ilInstructionHeaderWordCount` |
| 0x19ee08 | 108 | `ilDestinationOperandWordCount` |
| 0x1a322c | 32 | `FUN_001a322c` |
| 0x1a324c | 8 | `FUN_001a324c` |
| 0x1a3254 | 4 | `FUN_001a3254` |
| 0x1a3258 | 4 | `FUN_001a3258` |
| 0x1a325c | 4 | `FUN_001a325c` |
| 0x1a3260 | 4 | `FUN_001a3260` |
| 0x1a3264 | 24 | `FUN_001a3264` |
