# Round 4 agent K: joined hybrid names, refused splits and skipped functions

Rule applied: a joined name (`...Then...`) is used only when every role of the variable is verified;
address-taken stack locals (#282 class) keep a whole-variable name. Where a rename or a web split changed
the compiled image (gate DIFFERENT), the offending rename was dropped and the placeholder kept.

## Web splits refused by the image gate (register allocation changes)

| Function | Variable | Reason |
| --- | --- | --- |
| `_glePPParse` | iVar5, sVar12, iVar14, uVar15, iVar16, iVar21, uVar23, uVar24 | `use` (web split) rows changed gcc register allocation (gate K4_3: `or r13,r3,r3` vs `stw r3,0x174(r1)`); only whole-variable names kept, the multi-role ones stay placeholders |
| `_glDetachObjectARB_Exec` | iVar10 | web split changed allocation (gate K4_5: `li r10` vs `li r25`) |
| `_gleSelectQuadsFunc_body`, `_gleSelectQuadStripFunc_body`, `_gleVPRenderQuads_body` | iVar9 / iVar9 / iVar11 (the variable that is assigned the constant 4) | even the whole-variable rename moves the dead `li rN,4` store and changes allocation (gate K4_8) |
| `_gleSetAttrib` | fVar9, fVar10, iVar23 | several unrelated roles per variable, left as placeholders |
| `_gleInitGLDState` | iVar9 (several webs) | one variable reused for many unrelated roles; no safe whole name |

## Joined names kept (all roles verified)

Many `...Then...` names in the Feedback/Select/Render/VPRender `*Func_body` families, for example
`cullResultThenBackFacing`, `texEnableBitsThenCullResultThenBackFacing`,
`firstVertexThenCursorThenCullResultThenPolygonMode`: the Ghidra decompile merges several lifetimes of one
register into a single variable and the web split is refused (see above). Also
`_gleTransformNormalBlend.vertexArrayThenCursor`, `_gleCullPolygonPtrStack.polygonListThenCursor`,
`_gleInvertMatrix_601_body.pivotThenReciprocal`, `_gleTextureImagePut_Fast.srcStartThenPointer`.

## Functions attempted only partly or skipped (reason)

* `_gleQuickOptimizeDisplayList`: iVar5, iVar6, iVar10-12, piVar3, puVar1, uVar14 each take 3-6 unrelated roles
  (hash node, var item offset, shared state, removed object...); no whole-variable name is true.
* `_gleExecuteClippedVertexArray`, `_gleEmitTransformInstructions`, `_gleBuildCompileFuncNO`,
  `_gleBuildCompileFuncTCLAV`, `_gleBuildProjectionTransformFuncNO/AV`, `_glePPUpdateProgram`,
  `_gleSetupAndDrawArraysOrElementsOutOfLine_ListExec`, `_gleDrawArraysOrElements_Exec`,
  `_gleDrawArraysOrElements_VAR_Exec`: bit-packed or runtime-code-emitting bodies whose variables are
  reused across unrelated roles (uVar12 flag then mask bits, etc.) or whose parameters have no evidence
  beyond forwarding (`param_5`, `param_6` of the DrawArraysOrElements family). Left as placeholders rather
  than invent names.
