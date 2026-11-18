# Unsplittable hybrids / splits refused by the image gate (round 3, agent I)

- `_gleGetAttrib`: `puVar10` web 2 (srcCursor over ctx+0x2d0) and web 25 (srcCursor over ctx+0x3534) under ONE new name changed register allocation (gate I3_3); with distinct names each is IDENTICAL.
- `_gleSetAttrib`: splitting `fVar9` (webs 0..5: copied float / countdown / bit mask) swaps r6/r7 around the two stores to ctx+0x74d8/0x74dc (gate I3_9, I3_10); `fVar9` and `fVar10` keep their placeholders (the bit-mask words saved from attribBuffer[3]/[0xd] and [0]/[4], stored to ctx+0x74d8/0x74dc and tested with `1 << loopIndex`).
- `_glTexImage1D_ListExec` (`iVar7`) and `_glTexImage2D_ListExec` (`iVar9`): `width = listRecord[3]` (maybe reduced by pixel-store offsets) and the later `x = _gleCreateTextureLevel(.., x, ..)` result are separate webs, but splitting them changed the saved-register count (gate I3_19: stmw r18 -> r19); both keep one joined name `widthThenCreateResult`.
- `_glTexParameterF_Exec`: splitting `fVar3`/`fVar7` (clamp bounds loaded from FLOAT_00108e50/54, later reused for *params and the substituted bound) changed the fcmpu/cror sequence (gate I3_12); both keep their placeholders.
- `_glCompressedTexSubImage2D_Exec` `iVar9` web 0 / `iVar5` and `_glTexSubImage3D_Exec` `iVar5` web 0: one register carries the pixel-unpack buffer (ctx+0x4a6c) and later the result of the plugin callback / faceIndex*2: multi-role, left as placeholders.

## _glGetTexImage_Exec
- uVar16: faceIndex (target - 0x8515) and the reloaded level height share one register; splitting into two names changed register allocation (I3_21 DIFFERENT, r19/r20 swap). Joined as faceIndexThenHeight.

## _glCopyTexImage2D_Exec
- uVar15 (webs: forwardedArg3 copy of level, renderer dispatch flags from ctx+0x4788, faceIndex) left unnamed: naming any of its webs separately changed register allocation (I3_23/I3_25 DIFFERENT, r26/r28 swap on faceIndex). Only the changeWord3/texUnit webs, already named in earlier rounds, remain.
- iVar11 width web 2 and level cursor web 3 are one joined name (copyWidthThenLevelCursor); splitting them swapped r19/r20 (I3_23).

## _glVertexAttribPointerARB_Exec
- iVar9 web 1 (component size 1/2/4/8 set in the type switch) left unnamed: renaming it separately from the clientState web changed the switch code layout (I3_27 DIFFERENT, li r9,4/1/2 reordering).

## _glCompressedTexImage3D_Exec / _glFinishObjectAPPLE_Exec / _glCreateProgramObjectARB_Exec / _glDrawPixels_ListExec / _glFramebufferTexture
- Joined names (…Then…) are used where a single register holds two roles (glContext copy then texture object; scratch end then fast-path result; attachment base then temp). Splitting was not attempted for these because the original register is shared.

## _gleGetState iVar13
- iVar13 has 33 webs. All renamed at once (minus w22) gave DIFFERENT (I3_30: lwzx r4,r2,r4 -> r4,r4,r2, operand order of an indexed load). Webs <=16 (I3_33A) and webs {<=10, 18, 19, 28, 30} (I3_33B) are each IDENTICAL alone; only the union changes the indexed load. Committed: webs <=16. Left unnamed: w18 (ctx+0x5004 matrix pointer), w19 (activeTexUnit), w22 (renderer index * 4), w28 (raster tex coord pointer), w30 (current tex coord pointer) and the aliases. Unions beyond that were not bisected further.
- iVar11 (attachmentIndexThenBody), iVar3, dVar14, fVar1, uVar4/7/8/9/10 and lVar15 are named (I3_29..I3_34).

## I3_37 refusals (gate DIFFERENT when the webs were named apart; joined in I3_38)
- _gleResetLevels: uVar14, uVar10, uVar9, uVar20, uVar17, bVar3, bVar4 (register allocation of the r14..r21 block shifts when the webs get separate declarations).
- _gleSetFunctionIDFromArray: uVar2, uVar3 (split changes which of r5/r11 holds the stream slot); iVar7 left as is.
- _gleVPSetFuncOutputDesc: uVar1, uVar5, iVar6 (split swaps r7/r8).
