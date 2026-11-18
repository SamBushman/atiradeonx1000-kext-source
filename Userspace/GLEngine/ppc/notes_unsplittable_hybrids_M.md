# Round 5, agent M: variables left as placeholders and why

Every name in `names_loc5_M_01..13.tsv` was applied with `apply_names.py` (`USE_DECL=beside`) and the
committed state passed the image gate (`VERDICT: IDENTICAL`, 3557 functions, 0 differ). The groups
below were written and checked but either failed the gate or could not be proven, so the variable
keeps its placeholder. The part files are authoritative.

## Renames refused by the image gate (names were correct, the build changed)

Each set applied cleanly and compiled, but the image differed in one function (register
allocation or operand order). Dropped, not forced.

- `_gleFeedbackQuadStripFunc_body`: `iVar17` (13 uses): any rename changes register allocation.
- `_gleFeedbackTrianglesFunc_body`: `iVar20` -> `runVertexCount` (whole variable, 11 uses) changes
  allocation (gate M5_16: `li r25,3` hoisting and r28/r24 swap). The later `iVar20 = 3` is a dead
  assignment, which is what the allocator reacts to.
- `_gleSelectTrianglesFunc_body`: `iVar9` (6 uses) and `extraout_f1_00` (declared, never used).
  `dVar18` -> `f1AfterHookCall` passed in the last gate and is committed; `iVar9` failed three
  gates (M5_9..M5_11), also as a whole-variable joined name.
- `_glGetPixelMapuiv_Exec`: `iVar3` (18 uses) and `iVar6` (7 uses, `bufferObject`): gates M5_7..M5_9
  swapped `stwx` operand order / r9-r11 (agent L saw the same for `iVar6`).
- `_gleUpdateDispatchCodeChange`: `uVar3` (15 uses): four distinct roles in four webs; splitting
  or joining changes allocation (gate M5_7, M5_8).
- `_glGetError_Exec`: `iVar1`: split webs and the joined whole-variable name
  `errorCodeThenRendererRecordThenRendererError` (M5_9, M5_17 experiment: the joined name passed
  and is committed; the split rows failed).
- `_glVertexAttribPointerARB_Exec`: `iVar9` (8 uses) -> `typeBytes` changes the `li r9,4/1/2`
  constants (gate M5_15): the byte-size constant is shared with a flag by the allocator.

## Roles not provable (left as placeholders on purpose)

- `_gleUpdatePolyMode`: `uVar2`, `bVar3` multi-role byte flags; semantics of each bit not proven.
- `_gleCheckCopyTexImageArgs`: `param_5`, `param_6` are flags derived from the caller's target
  kind; the callers pass computed values, no role provable from this function.
- `_gleVtxLightSpecRGBABack`: `extraout_r3`, `extraout_r3_00`, `extraout_f1` are declared but never
  used.
- `_glTexParameterF_Comp`, `_glMaterialiv_Comp`: `puVar1` is reused for several records.
- `_glGetDoublev_Exec` `auStack_b0`, `_glepLoadRenderers` `auStack_147`,
  `_PPEmulatorProgramSetupHandlesFromPPStream` `auStack_30`, `_glGetCompressedTexImage_Exec`
  `local_98`: stack buffers with sizes/roles not provable (stack-layout artifacts of Ghidra).
- `_LFSParserAttachString`: `iVar1` has three roles (strlen, preprocess result, newline result)
  and is not a verified join.
- `_glGetProgramivARB_Exec`: `uVar4` candidate compare constants, no single role.
- `_gleFeedbackDrawPixels`: `param_2` is forwarded to a callee whose parameter is unnamed.
- `FUN_000087ac`, `FUN_000087c0`, `FUN_000087cc`, `FUN_00008b68`: function names (not variables).
- Weight*_Comp functions: the `glContext` parameter cannot be renamed because earlier row files
  expect the name `glContext` (it is reassigned to the list record, see defects below).

## Joined names (every role verified)

strideDwordsThenRemaining, bufferStartThenCopyDestination, vertexEndThenRemaining,
resultThenRangeStart, oneThenPointValue, invUDeltaThenPointValue, stackCursorThenAttribElement,
bankStateThenSlotPriorityAddress, combinerIndexThenConstantRecord, variableIndexThenQueryValue,
outputLengthThenNewlineResult, strideLog2ThenInstructionWord, contextThenByteOffsetThenDrawResult,
copyResultThenContext, execResultThenMemcpyResult, textureObjectThenMipmapResult,
registryEntryThenBundleNameString, scaledDsThenClampResult, oneMinusCosThenZxOneMinusCos,
radiansPerDegreeThenCosValue, axisLengthThenInverseLength, removeNameResultThenObject,
f1ThenHookF1Result, yorigShadowThenFormatArg, xmoveShadowThenBitmapArg,
errorCodeThenRendererRecordThenRendererError, sharedStateThenXObject variants.

## Suspected corpus defects (decompiler artifacts, not fixed here)

- `_glAreTexturesResident_Exec`: an earlier-round row named `iVar3` only at the assignment; a later
  use at `+0x10` reads the hash object.
- `_glWeightivARB_Comp`, `_glWeightbvARB_Comp`, `_glWeightusvARB_Comp` and similar: the `glContext`
  parameter is reassigned to the list record (typed as uint), so the name is misleading.
- `((unsigned char *)0x00001004) + iVar` constant artifacts in `_glGenRenderbuffersEXT_Exec`,
  `_glIsRenderbufferEXT_Exec`, `_gleBindRenderbuffer`.
- `_gleSelectTrianglesFunc_body`, `_gleVtxLightSpecRGBABack`: unused `extraout_*` declarations.
- `_gleFeedbackTrianglesFunc_body`: `iVar20 = 3` is a dead assignment.
