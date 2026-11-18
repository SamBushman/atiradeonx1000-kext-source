# Round 4 naming, agent J: hybrids and refused splits

Placeholders in this list were left on purpose. Each entry says why. The rule is
that a name must be true for every use of the variable; where a role was not
established, or where renaming changed the compiled image, the placeholder stays.

## Reused-temporary hybrids (one variable, several unrelated roles)

- `_gleUpdateViewScissorData`: uVar/fVar temporaries are reused for unrelated
  float/int values across the function.
- `_glRotateXYZ_Exec`: fVar11, fVar15, fVar16 carry different values in
  different phases (angle, sin/cos products, axis components).
- `_gleVtxLight*` (SpecRGBAFront, RGBABack_body, FastRGBAFrontPtr, FastRGBAFront):
  float temporaries are recycled for diffuse/specular/attenuation intermediates;
  no single role holds across a variable's whole life.
- Quad-strip loops (`_gleRenderFlatQuadStripFunc_body`, `_gleVPRenderQuadStrip_body`):
  uVar7 / uVar17 are rotating vertex cursors that change meaning each iteration.
- Polygon and fan bodies: iVar7 / iVar8 webs whose lw2 web includes the
  cull-result definition (`iVar = _gleCull...()`), so one web mixes the cull
  result with an unrelated pointer.
- Polygon `uVar9`: flag forwarded to `_gleClipPoly`; its meaning is not
  established.

## Splits refused because renaming changed the compiled image

Each of these was verified on the G5 with a variant build: the rename made the
register allocation differ from a null variant of the same tree, so it was
dropped. These are image-affecting declaration merges (all webs of a variable
must be renamed together, and reusing an existing alias name merges the
declarations).

- `runBackFacing` variables in the render/select functions.
- `_gleRenderFlatTriangleFanFunc_body` iVar8 / iVar10.
- `_gleRenderFlatTriangleStripFunc_body` iVar14.
- `_gleRenderFlatQuadStripFunc_body` bVar2 / iVar7 / iVar10.
- `_gleFeedbackTrianglesFunc_body` iVar20.
- `_gleOptimizeDisplayList`: the S2/S4 web-split groups conflict with the T3
  set (each group alone is safe, the combination differs); iVar11
  (`attribAddr`) and iVar14 (`attribOffsetValue`) groups are among the
  conflicting ones.

## Not attempted (role not established from evidence)

- JIT emitters: `_gleBuildVertexFuncNO`, `_gleBuildModelviewTransformFuncNO`,
  `_gleBuildNormalTransformFuncNO_body`, `_gleBuildNormalTransformFuncAV_body`,
  `_gleBuildCompileFuncAV`, `_gleBuildCompileFuncTCLNO`, `_gleBuildInterpFunc`.
  The variables hold fragments of PPC instruction encodings assembled by
  shifts and masks; naming them needs per-opcode decoding, which was not done.
- Not reached for lack of budget (no hybrid reason): `_gleCompileTCLVertexArray`,
  `_gleFlushPrimitiveTCLRDirtyFunc`, `_LFSParser*`, `_CopySourceSubImageToTexture`,
  `_setImageUnit`, `_gleDrawPixelsFast`, `_gleImagingScaleAndBias`,
  `_gleDrawArraysOrElementsOutOfLine_ListExec`, `_gleDrawArraysOrElements_Comp`.
