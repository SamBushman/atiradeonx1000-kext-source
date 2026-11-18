# Round 6, agent T: refused / unproven renames

## Gate-refused (register allocation changed; rows not kept)
- `_gleUpdateViewScissorData` (gate T6_2: only this function differs, r20/r21 and r30/r31 swapped; the data/nm comparison also reported a difference in that gate, gone once the function was reset). Whole-variable joined names refused together: `uVar16`=clipMaxY, `uVar17`=clipWidth, `uVar15`=scissorMinXThenClipMinY, `uVar18`=scissorMinYThenClipMaxX, `uVar14`=scissorMaxXThenWindowOffsetXThenWindowMaxX, `uVar8`=scissorRightThenScissorMaxYThenClipHeight, `fVar6`=halfScaleThenHalfClipWidth, `fVar7`=halfClipHeight. Roles are as described by those names (verified in the code); they could be retried one or two at a time.

## Not attempted / not established
- `_gleInterpolClipNO0000`: the five floats are permuted by clip plane (see notes E, L); no single name is true.
