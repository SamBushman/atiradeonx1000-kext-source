# Round 6, agent T: refused / unproven renames

## Gate-refused (register allocation changed; rows not kept)
- `_gleUpdateViewScissorData` (gate T6_2: only this function differs, r20/r21 and r30/r31 swapped; the data/nm comparison also reported a difference in that gate, gone once the function was reset). Whole-variable joined names refused together: `uVar16`=clipMaxY, `uVar17`=clipWidth, `uVar15`=scissorMinXThenClipMinY, `uVar18`=scissorMinYThenClipMaxX, `uVar14`=scissorMaxXThenWindowOffsetXThenWindowMaxX, `uVar8`=scissorRightThenScissorMaxYThenClipHeight, `fVar6`=halfScaleThenHalfClipWidth, `fVar7`=halfClipHeight. Roles are as described by those names (verified in the code); they could be retried one or two at a time.

## Not attempted / not established
- `_gleInterpolClipNO0000`: the five floats are permuted by clip plane (see notes E, L); no single name is true.

## Round 6 gate T6_6 refusals (allocator-sensitive whole-variable names)

Gate T6_6 was DIFFERENT in three functions; their rows were reset with reset_fn.py and T6_7 (all other rows) was IDENTICAL.
The refused rows are whole-variable renames; the compiler's register allocation reacted to them (same effect as `_gleUpdateViewScissorData`).

- `_glTexImage3D_Comp`: unpackBuffer, imageEndOffset, bufferSize, bytesPerElementResult, staleReturnThenBytesPerElement, alignedRowBytes/alignedDataBytes, fillResult/callResult, formatMatchesType.
- `_glTexSubImage1D_Comp`: same family of names as above.
- `_glCombinerParameterfvNV_Exec`: combinerCountThenRawRThenClampedG, rawAlpha, rawGreenThenClampedBlue, rawBlueThenClampedAlpha, clampedRed, constantColorSlot.

They can be retried a name or two at a time if someone needs them.

## Proposed source fixes

None evidenced. Observations: the old `_gleCopy` param name `lists` was false for most callers (renamed `source`); round 6 brief says `incomingStackWord_<hex>` while the P_01 example uses `stackArgSlot_` (followed the brief text).
