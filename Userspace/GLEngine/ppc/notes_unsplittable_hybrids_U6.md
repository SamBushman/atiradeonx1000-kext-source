# GLEngine round 6, agent U: unsplittable hybrids, refusals and proposed source fixes

Row files: `names_loc6_U_01.tsv` .. `names_loc6_U_06.tsv` (and any later numbers). Every row file is committed after a gate with VERDICT IDENTICAL.

## Rows refused by the gate (register allocation changes)

A pure rename must leave the image byte-identical. These names changed gcc's register allocation or operand order, so they were dropped (nothing is left half-applied):

| Gate | Function | Variable | Name tried | Observed difference |
|---|---|---|---|---|
| U6_2 | `_gleSelectQuadsFunc_body` | iVar9 | previousFacing | register allocation |
| U6_2 | `_gleSelectTriangleFanFunc_body` | iVar9 | previousFacing | register allocation |
| U6_2 | `_gleFeedbackTriangleStripFunc_body` | uVar21 | carriedParity | register allocation |
| U6_2 | `_gleRenderFlatQuadStripFunc_body` | bVar2 | orientationChanged | register allocation |
| U6_5 | `_glGetPixelMapuiv_Exec` | iVar3 | mapSizeThenByteOffset | `stwx r2,r9,r28` became `stwx r2,r28,r9` (operand order) |
| U6_6 | `_glGetPixelMapuiv_Exec` | iVar6 | pixelPackBuffer | `li r9`/`li r11` allocation swap |
| U6_8 | `_gleSwitchToRenderer` | param_2, uVar1, uVar5, uVar6, puVar4 | rendererIndex, rendererHandle, newDirtyFlags31c, dispatchSlot, finishFunc | store order and register allocation (0x318/0x31c stores swapped, bctrl moved) |

Rows withheld to protect earlier anchored rows (not a gate failure): `_glGetVertexAttribfvARB_Exec` iVar5 (indexedRecord) and remaining3 (elementCount). Earlier rows in `names_loc_B_07.tsv` anchor on lines that contain `iVar5`, so renaming it made `apply_names.py --check` report 4 new anchor-not-found errors (96 instead of 94 plus 2 chain errors in `_glArrayElement_Comp`). The names are TRUE and can be applied once B_07 is rebased onto final names.

Rows are preserved under `~/g5logs/fnf_237/vn/agent_U6/dropped_g*.tsv`.

## Placeholders left on purpose

Each of these is a variable that holds several unrelated values over its lifetime. A single name would be false, and a joined name would claim roles that were not all verified.

* `_gleVPGetParameterPtr`, `_glePPUpdateProgram`: operand-descriptor decoder. uVar1/uVar3/uVar6/uVar10 are reused for the raw descriptor word, the register file selector, the relative-addressing flag and the index in different branches.
* `_glePPPruneParams` iVar1/iVar8: loop cursor and item pointers reused across two passes.
* `_glePPParse`: uVar23 (84 uses) and the iVar/sVar family are scratch parse state; earlier rounds refused the same names.
* `_glTexImage1D_Exec`, `_glTexImage2D_Exec`, `_glTexSubImage2D_Exec`: iVar results hold a callee return value, then a pointer, then an error code.
* `_gleOptimizeDisplayList`: fVar6 to fVar10, iVar11, iVar14 are plain webs that alias different fields of the opcode records across the peephole cases.
* `_glCopyTexImage1D_Exec`: copies uVar4/uVar9/uVar10 of the pack-state words.
* `_glUseProgramObjectARB_Exec`: uVar20/uVar21.
* `_gleFlushPrimitiveTCLRDirtyFunc`, `_gleFlushPrimitiveTCLFunc`: iVar1/iVar2/iVar4 are reused per `case` of the primitive-type switch for different buffer cursors.
* `_LFSParserParseRegisterInit`: iVar2/iVar3 are reused for token compare results, error codes and list nodes.
* `_gleGetState` iVar13: offset, pointer and value in different pname branches; param_5 is an out flag set to 1 together with valueType 0x140a but no caller reads it, so its role is not established.
* `_glGetProgramivARB_Exec` uVar4, `_gleCheckTexImageArgs` bVar1: compare temporaries.
* `_gleDrawArraysOrElementsOutOfLine_ListExec`, `_glDrawArraysOrElements_ListExec`: the display-list argument record offsets (puVar13/iVar14/piVar12/uVar11) were not traced to GL arguments.

## Convention note

Round-6 renames `incomingStack_<hex>` to `incomingStackWord_<hex>`. Chained rows (in_stack_X to incomingStack_X to incomingStackWord_X) make `apply_names.py --check` print 94 "neither in_stack nor incomingStack present" errors; the apply still applies the new rows and link_corpus resolves the chain.

## Proposed source fixes

None established. No suspected corpus defects were found with evidence.
