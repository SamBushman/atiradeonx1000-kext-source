# Round 5 naming, agent O: placeholders left in place and why

Function list: `r5_O.txt` (5609 placeholders at the start of round 5). Every name that is
in the part files came from a `names_loc5_O_<NN>.tsv` row and passed the gate
(`gate_agent.sh`, tags O5_1 .. O5_36) with `VERDICT: IDENTICAL`. The entries below are the
placeholders that stay, with the evidence.

## Ghidra `incomingStack_<hex>` pseudo-variables (about 207 placeholders, 26 functions)

These must not be renamed. The corpus build derives the stack-argument offset from the
name (`incomingStack_ffffff88` means frame offset -0x78), so a renamed variable changes
the emitted code. Tried twice:

- O5_20: eleven functions differed after the rename.
- O5_32: renaming `incomingStack_*` to `incomingStackWordN` in 15 functions changed the
  code (and data/nm) of all 15 functions; the attempt was reverted (nothing committed).

Affected functions include `_glMapVertexAttrib2dARB_Exec`, `_gleVtxLightFastRGBABack`,
`_gleVtxLightRGBABackPtr`, `_gleVtxLightFastRGBABackPtr`, `_gleFeedbackQuadsFunc_body`,
`_gleFeedbackPolygonFunc_body`, `_gleRenderSmoothTrianglesFunc_body`, `_gleVPRenderQuads_body`,
`_gleSelectQuadStripFunc_body`, `_gleEvalDomain1Coord`, `_gleEvalDomain2Color`,
`_gleEvalDomainDeriv2Coord`, `_glFlush_RevertExec`, `_glFrustum_CompExec`,
`_glLightiv_Exec`, `_glLightiv_ListExec`, `_glMap2d_CompExec`,
`_glMapVertexAttrib2dARB_CompExec`, `_glMapGrid2_ListExec`, `_glNormal3i_CompExec`,
`_glRenderMode_Exec`, `_glRotateZ_ListExec`, `_glEvalPoint2_ListExec`,
`_glCombinerParameterivNV_ListExec`, `_gliUpdatePluginConfig`, `_gleSwitchToNonRevertRenderer`.

## Local variables whose rename changes the generated code (gate DIFFERENT)

Same function, same single-role variable, but the gate shows a register-allocation change
after the rename; they stay at the placeholder name (no false name):

- `_glDetachObjectARB_Exec` `iVar10` (O5_26): `li r10,1` became `li r25`.
- O5_35: `_gleVPRenderQuads_body` `iVar11` and `_gleSelectQuadStripFunc_body` `iVar9`
  (the run's back-facing flag, -1 until the first quad), and `_gleFeedbackQuadsFunc_body`
  `iVar20` (polygon vertex count) and `puVar14` (swap-partner polygon list): each rename
  moved registers in its function. These four roles are known; only the gate refuses them.
- `_glTexParameterF_Exec` `fVar3`/`fVar7` (O5_22): splitting them changed the fcmpu/cror
  code; the joined whole-variable names `clampUpperOrClampedShadowAmbient` and
  `clampLowerOrParamValue` are used instead.

## Variables whose role could not be proven (left unnamed on purpose)

- `_gleInitializeGLTexture` `uVar2`, `uVar6`: several consecutive roles, not all provable.
- `_gleTexLevelStorage` `uVar1`: same.
- `_gleDeletePluginTextureLevel` `bVar3`, `uVar8`: same.
- `_gleSetFunctionIDFromArray` `iVar7`: a per-slot field at +4 that is clamped to 0x3ff and
  packed into the low 10 bits of the output word; probably a slot stride, not proven.
- `_gleSetFunctionIDFromList` `local_14`: really `slotOffsets[31]` (adjacent-locals split of a
  frame array, see the suspected defects below).
- `_glPNTrianglesfATIX_CompExec` `iVar1`: holds `(int)` of a float argument that is compared
  against pname constants; the role depends on a probable signature defect.
- `_gleFinishFence` `param_2`, `_gleFeedbackBitmap` `param_2`: callers always pass 0 or the
  argument is unused; no role is evidenced.
- `_glEvalCoord2d_CompExec` `fparam_9`: part of `CONCAT44(in_LR, ...)`, a decompiler artifact.
- `_glTexParameterI_Comp` `puVar1`: renamed with the joined name `pnameCheckValue` (O5_33);
  its roles cannot be split.
- `FUN_000087b0`, `FUN_000087c4`, `FUN_000087d0`: function names (stubs), not variables.

## Suspected corpus defects (reported, not changed)

- `_glGetProgramStringARB_Exec`, `_glGetProgramEnvParameterfvARB_Exec`, `_glBindProgramARB_Exec`:
  the second-target compare constant shows as 0x8200 for target < 0x8621 (0x8804 otherwise);
  likely a decompile artifact of a select, but it would accept target 0x8200 if real.
- `_glPNTrianglesfATIX_CompExec`: tests `(int)param` (the float argument f1) against the pname
  constants 0x6093/0x6094 and ignores pname; the signature or register assignment is wrong.
- `_gleSetFunctionIDFromList`: `local_14` is read as `slotOffsets[31]` (the array is declared
  with 31 elements): adjacent-locals frame split, defect class #282.
- `_glEvalCoord2d_CompExec`: `CONCAT44(in_LR, fparam_9 ...)` builds a double from the link
  register.
- `_glTexParameteri_Comp`, `_glTexParameterI_Comp`: `ghidra_home` spill-slot hack and odd
  `((unsigned char *)0x00001004)` casts.
- `_glBitmap_NoopExec`, `_gleInitDrawPixelsShareObject`: the leftover temporary (r9/r10) is
  passed as an argument of unrelated meaning.
