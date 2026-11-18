# Unsplittable hybrid names (agent H, round 3)

Joined names that list both roles of one register web (the def-use web is a single web, so it cannot be split by name).

- `_gleGenerateEmptyMipmaps`: `baseOffsetThenPreviousLevel` (iVar6: base level record minus 0xc4, then += 0xc4 = previous level record), `faceBaseThenNextLevel` (iVar9: face block start, then next level record).
- `_gliSetInteger`: `targetThenFace` (uVar14: texture target, then target - 0x8515 = cube face index).
- `_gleForceToSoftwareTCL`: `vertexCountThenRemaining` (iVar11: vertex count, then counted down per vertex), `dirtyWord3ThenMasked` (uVar9: dirty word at ctx+0x31c, then the masked copy used for the all-clean test).
- `_gleUpdateViewScissorData`: `windowOffsetXThenMaxX`, `windowOffsetYThenMaxY` (uVar11 / uVar12: window offset, then the maximum edge computed in the same register).
- `_glTexEnviv_Exec`: `activeTextureUnitThenEnableMask` (uVar12: active texture unit, overwritten with the new enable mask in the 0x8861 / 0x8862 path).
- `_gleCompileClippedVertexArray`: `formatFlagsThenCompileKey` (uVar17: format flags from ctx+0x4980, rebuilt in place into the compile-cache key).
- `_gleFillImage` / `_gleEmptyImage`: `skipBitsThenBitShift` (uVar8), `rowLengthThenRowStride` (iVar6, FillImage), `skipRowsThenRowStart` (iVar14, FillImage).
- `_gleBindFramebuffer`: `attachmentLevelThenMip` (uVar14: attached mip level, then incremented to walk the remaining levels).
- `_gleCheckFramebufferStatus`: `dirtyWord3ThenMasked` (uVar6, as in `_gleForceToSoftwareTCL`).
- `_gle_strtod`: `exponentThenScale` (dVar10, third web: the exponent integer, then replaced by `_pow_10(exponent)`).
- `_gleUpdateViewScissorData`, `_gliSetInteger`, `_gleQuickOptimizeDisplayList`, `_glTexSubImage2D_Exec`, `_gleEmptyImage`: variables whose webs carry different true names (for example `iVar13` in `_gliSetInteger`, `uVar8` / `uVar14` / `uVar15` in `_gleUpdateViewScissorData`, `iVar10` / `piVar3` / `puVar1` / `uVar14` in `_gleQuickOptimizeDisplayList`, `iVar3` / `uVar5` in `_glTexSubImage2D_Exec`) were left as placeholders: splitting their webs by name changed the instruction sequence at gates H3_2 .. H3_8, and no joined name is true for every use.
