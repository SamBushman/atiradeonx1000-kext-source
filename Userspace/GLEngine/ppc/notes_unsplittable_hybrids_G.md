# Unsplittable hybrids (agent G, round 3)

Variables where splitting the Ghidra variable into per-web names changed the
image (gcc register allocation / scheduling), so a single joined name that is
true for every use was kept instead.

## _gleGenerateMipmapData
- Rolling pointer registers (src/dst cursors of the unrolled filter loops):
  joined whole-variable names. Per-web splits failed gates G3_3..G3_7
  (swaps of `or r4,r29,r29` / `or r3,r28,r28`, `li r11,0x1` / `li r16`).
- uVar28 -> typeBorderDepthOrRowCount (joined; split rows failed G3_7).
- uVar6: the w4 split was dropped (same gate failure); the remaining webs of
  uVar6 are named, w4 keeps the joined name of the variable.

## _gleTransformProjectionBlend
- fVar1..fVar21 each hold two or three unrelated values in turn (blend-matrix element
  / projection-matrix element / clip scale or bias / vertex position / weight).
  Per-web names (blendM0.., projM0.., ...) changed the image: gate G3_11 differed
  (spill slots of the matrix floats shifted), and the same rows without the fVarN
  splits passed (G3_12). Each fVarN therefore has one joined name listing its roles,
  e.g. blendM12OrProjM0.
- fVar27 (eyeXThenClipY), fVar31 (fogValueThenClipX), fVar32 (fogFactorThenClipZ):
  joined for the same reason. The single-role floats fVar22..26, 28..30, 33, 34 and
  all pointer/integer variables are named per role.

## _gleVtxLightSpecRGBABack
- fparam_1 (floatArg1) is one Ghidra variable that carries 8 unrelated temporaries
  (vector lengths from _gleVectorNormalize, 1/distance, spot cosine/factor, specular
  green, normal.direction, specular base and its power). It is also a parameter, so a
  per-web split cannot be declared; joined as floatArg1.
- fparam_2..8 (floatArg2..8): incoming FP argument registers that the body reuses as
  temporaries and that are forwarded to the _gleLightExponentPow/_gleMaterialShinePow
  calls; one web each, joined.
- extraout_r3, extraout_r3_00, extraout_f1 are declared but never referenced (no web),
  and incomingStack_* are the existing stack-argument convention; left as they are.

## _gleUpdatePrimitiveData
- puVar1/puVar2/puVar3 are software-pipelined staging pointers that hold, in turn,
  ~70 different PTR_ import slots before each is stored to the glBegin dispatch table;
  joined as stagedFuncPtr1..3 (a per-web split would be ~70 new variables in a pure
  shuffling sequence, not attempted).

## _gleFeedbackTriangleStripFunc_body (not named)
Every naming variant tried (per-web splits, partially joined, fully joined in-place `*` rows)
changes the image (r25/r29 allocation: `li r25,0x3` becomes `b`, `or r25,r0,r0` becomes `or r29,r30,r30`).
Its sibling _gleFeedbackTriangleFanFunc_body gates identical with names. The Strip function is left with
its Ghidra placeholders; no names were committed for it.
