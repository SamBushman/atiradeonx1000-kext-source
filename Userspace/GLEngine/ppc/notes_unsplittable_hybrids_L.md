# Round 4, agent L: variables left as placeholders and why

Every name in `names_loc4_L_*.tsv` was applied with `apply_names.py` and the committed state
passed the image gate (`VERDICT: IDENTICAL`). The groups below were written, checked and gated,
but could not be committed, or were never written because the variable is a hybrid.

## Role splits refused by the image gate (names were correct, the build changed)

Each row set below applied cleanly (0 errors) and compiled, but the compiled image differed
(register allocation swapped). They were dropped, not forced. The variable keeps its placeholder.

- `_gliSetInteger`: `iVar7`, `iVar16`, `iVar13` web splits (gate L4_9); `iVar9` split into
  `border` / `cubeTarget` (gate L4_12). The `iVar12` splits (`depth`, `textureLevel`) passed and are committed.
- `_glGetPixelMapuiv_Exec`: even the whole-variable renames `iVar6` (`bufferObject`), `uVar5`
  (`uintValue`) and `dVar7` (`scaledValue`) change allocation (gates L4_9, L4_10). Left untouched.
- `_gleEmptyImage`: the `iVar6` splits (`rowLength`, `alignRemainder`, `skipBytes`, `rowStride`) change
  allocation (gates L4_10, L4_11). The `iVar16`, `iVar17`, `iVar19`, `iVar21` splits passed.
- `_glLinkProgramARB_Exec`: `iVar14` splits and the first half of the `iVar18` splits passed.
  The second half (`fragmentLocalParamCount`, `ppStreamManager`, `shaderIndex`, `uniformIndex`,
  `attribIndex`, `shaderStringLength`, `unitRecord`) fails as a whole, in both halves
  of a bisect, and with `shaderIndex` alone (gates L4_17 to L4_20).
- `_gleFeedbackTriangleStripFunc_body`: the eight whole-variable names passed. All role splits fail,
  in each of three groups: {`uVar12`, `uVar20`, `uVar11`, `uVar21`}, {`uVar8`, `uVar22`, `uVar25`, `uVar10`},
  {`iVar13`, `iVar23`, `iVar17`, `iVar14`, `puVar15`} (gates L4_16, L4_18, L4_19, L4_20).
- The integer webs of the strip/fan render bodies (`_gleVPRenderTriangleStrip_body`,
  `_gleVPRenderTriangleFan_body`, `_gleRenderFlatTrianglesFunc_body`, `_gleSelectTriangleStripFunc_body`,
  `_gleSelectTriangleFanFunc_body`) and the dirty-word address webs of `_gleUpdateLightRGBASums`
  and `_gleLightMaterialRGBAChange_B_AD` follow the same pattern (gate L4_5, L4_7).
  Whole-variable names and the splits that passed are committed; the rest keep placeholders.

## Hybrids: one variable, several unrelated roles in one web (not split, no honest single name)

- `_gleInterpolClipNO0000`: every float (`fVar4`, `fVar7`, `fVar9`, `fVar10`, `fVar11`) is reused for
  start/end/clip/NDC values on different paths.
- `_gleVPGetParameterPtr`: `uVar1`, `uVar3`, `uVar4` are descriptor bit fields whose width and meaning change
  per `case`; `uVar1` is even reassigned to a derived index in case 0x10.
- `_gleTextureImagePut_Slow`: remaining placeholders are argument aliases and spill copies
  (`iVar17`, `uVar22`, `uVar23`, `iVar24`, `piVar25`), plus four unrelated `puVar30` byte cursors that
  would need four distinct names for the same role.
- `_gleVtxLightRGBAFront_body`: what is left is call artifacts (`extraout_*`, `incomingStack_*`,
  `incomingFpr*`), `dVar14` (holds the result of `_gleLightExponentPow` and later `_pow`), `iVar4`
  (context pointer then forwarded argument).
- `_glTexImage3D_Exec` `iVar6` and `_glTexSubImage1D_ListExec` `iVar3`: one web covers the texture object
  and the later `_gleGenMipmapsToLevel` result.
- `_gliGetInteger` `iVar2`: one web covers the shared-state pointer and the object returned by
  `_gleLookupHashObject`.
- `_glUseProgramObjectARB_Exec` `iVar6`, `iVar7`, `uVar10`: stage record / unit state cursor,
  program object / reference count, unit index / target bits.
- `_gleVectorNormalizeNO`: `dVar2`..`dVar5`, `fVar1` hold a component and then its normalized value
  (and `dVar2` the squared length and then the inverse length).
- `_gleDrawArraysOrElements_VBO_Exec` `uVar11` (second web): unused-array size flags; role not established.
- `_gleRenderFlatTrianglesFunc_body`: `iVar17`, `iVar7`, `iVar10`, `dVar20`, `puVar12`, `puVar6` (counts, facing,
  call results and swapped list pointers share registers).
