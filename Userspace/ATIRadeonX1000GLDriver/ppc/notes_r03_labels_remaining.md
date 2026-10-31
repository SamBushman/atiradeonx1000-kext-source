# GLDriver labels left as LAB_/switchD_ placeholders (r03)

Not named because the statement the label resumes at gives no variable/callee to name it by (`}`, `;`, `do {`, indirect call, `goto`/`break`, or only placeholders). 114 labels.

| function | label | why |
|---|---|---|
| _gldGetInteger | switchD_00005c44_caseD_5 | no switch found |
| _gldChoosePixelFormat | LAB_000089f0 | stmt 'return 10000;' |
| gld_textureVariantClass | switchD_0000a324_caseD_400 | no switch found |
| arbIrPrintDestinationOperand | switchD_0000dc3c_default | no switch found |
| arbIrPrintSourceOperand | switchD_0000e310_default | no switch found |
| arbIrPrintSourceOperand | switchD_0000ebf8_default | no switch found |
| arbIrPrintTextureOperand | switchD_0000f394_default | no switch found |
| arbProgramIrToText | switchD_0000f958_default | no switch found |
| arbProgramIrToText | switchD_000109e4_caseD_0 | no switch found |
| arbProgramIrToText | switchD_000118c8_caseD_11 | no switch found |
| arbProgramIrToText | switchD_000118c8_caseD_0 | no switch found |
| arbProgramIrToText | switchD_00013960_caseD_0 | no switch found |
| gld_postDisplayNotification | LAB_00017cfc | stmt 'if (scratchStack3c != 0) {' |
| _gldAllocVertexBuffer | LAB_0001b494 | stmt 'return 0;' |
| gld_validateVertexArrayStreams | LAB_0001dae4 | stmt 'do {' |
| gld_buildVertexStreamLayout | switchD_0001ffbc_default | no switch found |
| gld_gatherProgramConstants | switchD_00025774_caseD_1 | no switch found |
| gld_buildVertexStreamCache | switchD_00027e30_default | no switch found |
| gld_buildVertexStreamCache | switchD_00027c3c_default | no switch found |
| gldTextureMakeResident | LAB_00032e78 | stmt 'scratchStack64 = &scratchStack158;' |
| gld_uploadProgramStateConstants | switchD_0003bf70_caseD_1 | no switch found |
| extvsTranslateShaderObject | switchD_0003cbec_caseD_3 | no switch found |
| gld_emitProgramConstantUpdates | LAB_0003d820 | stmt 'while( true ) {' |
| gld_emitProgramConstantUpdates | switchD_0003de14_caseD_1 | no switch found |
| fragmentProgramToIL | switchD_00049180_caseD_0 | no switch found |
| fragmentProgramToIL | switchD_00049180_caseD_1 | no switch found |
| gldReleaseProgramEntry | LAB_0004b6a8 | stmt '(**(code **)(glContext + 0x18))(*(undefined4 *)(((' |
| extvsEncodeSourceSwizzle | LAB_00057ae0 | stmt 'return 0;' |
| extvsEmitSwizzle | LAB_0005d2d0 | stmt 'return 0;' |
| vpUploadConstantsWithFog | LAB_000620ec | stmt '(*commitCallback)(glContext,constantCount);' |
| extvsUploadProgramConstants | LAB_00064af0 | stmt 'while( true ) {' |
| ffvpSelectLitProgramVariant | LAB_00065500 | stmt '(**(code **)(((unsigned char *)0x000012dc) + glCon' |
| vpStateSelectForDraw | LAB_00076dc0 | stmt '(**(code **)(((unsigned char *)0x000012b4) + ctx))' |
| recordIsSchedulable | switchD_000778cc_caseD_1 | no switch found |
| recordOpcodeSourceMask | switchD_000785b4_caseD_46 | no switch found |
| recordProgramBuildDependencies | switchD_0007d27c_caseD_0 | no switch found |
| evsFoldConstantMoves | LAB_0007e760 | stmt ';' |
| gldAllocAndUploadConstants | LAB_000829e0 | stmt 'while( true ) {' |
| ffvpEmitTexCoordGen | switchD_0009696c_default | no switch found |
| ffvpEmitSceneColor | LAB_00097360 | stmt '(**(code **)(((unsigned char *)0x000012f4) + glCtx' |
| ffvpEmitSceneColor | LAB_000972c8 | stmt '(**(code **)(((unsigned char *)0x000012f0) + glCtx' |
| ffvpEmitDirectionalLight | LAB_000980d0 | stmt 'if (iStack0000002c == 0) {' |
| ffvpEmitDirectionalLight | LAB_00097d70 | stmt '(**(code **)(((unsigned char *)0x000012f4) + glCtx' |
| ffvpEmitDirectionalLight | LAB_00097d1c | stmt '(**(code **)(((unsigned char *)0x000012ec) + glCtx' |
| ffvpEmitDirectionalLight | LAB_00098038 | stmt '(**(code **)(((unsigned char *)0x000012f4) + glCtx' |
| ffvpEmitDirectionalLight | LAB_00097fd4 | stmt '(**(code **)(((unsigned char *)0x000012ec) + glCtx' |
| ffvpEmitLight | LAB_00099084 | stmt '(**(code **)(((unsigned char *)0x000012f4) + light' |
| ffvpEmitLight | LAB_000996c0 | stmt '(**(code **)(((unsigned char *)0x000012f4) + light' |
| ffvpEmitLight | LAB_0009991c | stmt '(**(code **)(((unsigned char *)0x000012ec) + light' |
| ffvpEmitLight | LAB_00099980 | stmt '(**(code **)(((unsigned char *)0x000012f4) + light' |
| ffvpEmitLight | LAB_0009966c | stmt '(**(code **)(((unsigned char *)0x000012ec) + light' |
| ffvpEmitPointSizeAttenuation | switchD_00099ea8_default | no switch found |
| gld_scanProgramTokens | switchD_000ac280_caseD_4 | no switch found |
| gld_scanProgramTokens | switchD_000abe1c_caseD_0 | no switch found |
| gld_compileFragmentProgram | LAB_000b1448 | stmt '(**(code **)(((unsigned char *)0x00001224) + glCon' |
| atifsCompileCurrentShader | switchD_000b3adc_caseD_8962 | no switch found |
| atifsCompileCurrentShader | switchD_000b3e78_caseD_8962 | no switch found |
| atifsCompileCurrentShader | LAB_000b4370 | stmt '(*setConstantFn)(ctx,compiledProgram,constantIndex' |
| gld_compileILProgram | switchD_000b4be8_caseD_80000007 | no switch found |
| ilAssembleProgram | switchD_000c90cc_caseD_15 | no switch found |
| ilAssembleProgram | switchD_000c90cc_caseD_18 | no switch found |
| ilAssembleProgram | switchD_000c9ab8_caseD_18 | no switch found |
| ilAssembleProgram | switchD_000c90cc_caseD_0 | no switch found |
| ilRewriteForTextureState | switchD_000cb23c_caseD_15 | no switch found |
| ilRewriteForTextureState | switchD_000cb23c_caseD_18 | no switch found |
| ilRewriteForTextureState | switchD_000cbc48_caseD_18 | no switch found |
| ilRewriteForTextureState | switchD_000cb23c_caseD_0 | no switch found |
| psnDumpPixelShader | switchD_000d4578_caseD_6 | no switch found |
| psnDumpPixelShader | switchD_000d489c_caseD_4 | no switch found |
| psnDumpPixelShader | switchD_000d2d30_caseD_6 | no switch found |
| psnDumpPixelShader | switchD_000d324c_caseD_4 | no switch found |
| ffpsEmitTexEnvCombine | LAB_000d64e8 | stmt 'iVar9 = combineRgbMode - 0x10000;' |
| ffpsEmitTexEnvCombine | LAB_000d6534 | stmt 'iVar9 = combineRgbMode - 0x10000;' |
| ildisPrintResultModifiers | switchD_000daebc_caseD_0 | no switch found |
| ildisPrintRegisterType | switchD_000dcf24_caseD_7 | no switch found |
| ildisPrintInstruction | switchD_000ddc1c_caseD_0 | no switch found |
| ILReader__nextInstruction | LAB_000e5e9c | stmt 'while( true ) {' |
| ILReader__nextInstruction | switchD_000e61ac_caseD_a | no switch found |
| Program__foldKind6IntoKind7Inst | LAB_000f1940 | stmt '(*UNRECOVERED_JUMPTABLE)(inst,placementInst,compil' |
| Program__propagateMovThroughUses | LAB_000f26b0 | stmt 'do {' |
| SelectWord__canonicalize | LAB_000f35b4 | stmt '(*(unsigned char *)((unsigned char *)ghidra_home +' |
| IRInst__setConstantOperand | LAB_000f6f18 | stmt 'do {' |
| Program__translateILInstruction | LAB_000fb800 | stmt 'pdVar25 = (dword *)(*(int *)(*(int *)(program + 8)' |
| Program__translateILStream | switchD_000fdaf0_caseD_2 | no switch found |
| Program__translateILStream | switchD_0010061c_caseD_0 | no switch found |
| Program__packInterpolatorEntries | LAB_001116f4 | stmt ';' |
| Program__sequentializeParallelCopies | LAB_00120cb8 | stmt '(**(code **)(*block + 0x38))(block);' |
| KhanVs__vslot71_canCombineSources | switchD_00129ce4_caseD_0 | no switch found |
| RegAlloc__insertSpillCode | LAB_00133348 | stmt ';' |
| RegAlloc__insertSpillCode | LAB_00133bd0 | stmt '(**(code **)(*deferredInst + 0xc))(deferredInst,0,' |
| IRInst__findLaneDefinition | LAB_001382d4 | stmt 'do {' |
| HwLimits__computeBlockLiveness | LAB_00138d24 | stmt ';' |
| Program__computeLaneInsertWords_0013a8a4 | LAB_0013ae10 | stmt ';' |
| Program__scanUsevectorChains | LAB_0013c9e0 | stmt 'do {' |
| pass_post_pack_insts | LAB_00146530 | stmt 'do {' |
| IRInst__isOpcodeInSet147398 | LAB_001474b4 | stmt 'return 1;' |
| Inst__replaceDuplicateInst | LAB_0014e690 | stmt '(**(code **)(*inst2 + 0xc))(inst2,1,*(undefined4 *' |
| Inst__canShiftTargetField | LAB_0015802c | stmt 'do {' |
| Inst__shiftTargetField | LAB_001589b0 | stmt 'do {' |
| Inst__foldCompareChain_00159b58 | switchD_0015a394_default | no switch found |
| Inst__takeOutCommonFactor | LAB_0015b134 | stmt '(**(code **)(*newSource3 + 0xc))(newSource3,1,*(un' |
| Inst__hoistScalarMulOutOfDot | LAB_00163950 | stmt ';' |
| Scheduler__computeBlockRegisterSets | LAB_001655a8 | stmt ';' |
| Scheduler__splitAddressRegisterUses | LAB_0016e800 | stmt ';' |
| Scheduler__selectNextNode | LAB_0016fcc0 | stmt 'do {' |
| ValueKey__eliminateTrivialInst | LAB_00173718 | stmt '(*removeFn)(producerInst,0,compilerRef);' |
| ValueKey__simplifyModifiersAndAddressing | LAB_00180a14 | stmt ';' |
| R300SchedModel__vslot16 | LAB_0018b190 | stmt '(**(code **)(newInstVtable + 4))(newInst);' |
| PackState__buildSlotTable | LAB_0018c498 | stmt 'do {' |
| PackState__tryPlaceInstructionSources | LAB_0018da08 | stmt ';' |
| R300MachineAssembler__placeInstructionConstants | LAB_001971a8 | stmt ';' |
| R300MachineAssembler__assembleAluInstruction | LAB_001999e8 | stmt '(**(code **)(*this + 0xf4))(this,srcIdx,rgbSelect,' |
| R520VMachineAssembler__vslot27_assembleLoopHeader | LAB_0019dc0c | stmt '(**(code **)(*this + 0x34))(this,block,*(undefined' |
| R520VMachineAssembler__vslot25_assembleConditionalBlock | LAB_0019e5d0 | stmt '(**(code **)(*this + 0x34))(this,block,*(undefined' |
