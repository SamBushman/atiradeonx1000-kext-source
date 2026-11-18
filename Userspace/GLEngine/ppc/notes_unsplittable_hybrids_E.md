# Unsplittable hybrid variables (round 2, agent E, parts 019-041)

A hybrid is one Ghidra variable whose register carries two roles that share a statement (`x = f(x)`) or a def-use web, so the row tooling cannot give the roles separate names. The name is a joined name that lists both roles. Every entry was checked against the whole life of the variable.

- `_gleInterpolClip*` / `_gleInterpolEye*`: `clipXThenNdcX`, `clipYThenNdcY`, `clipZThenNdcZ`, `clipWThenInvW`: the clip-space coordinate of the produced vertex (start vertex word, replaced by the interpolated value, stored to outVertex[4..7]) is multiplied in place by 1/w (`clipW` is replaced by 1/w, stored to outVertex[3]) for the window transform. Where the web has no window-divide the plain `clipX/Y/Z/W` is used.
- `_gleInterpolClip*`: `endToOutTexCoordT/Q` (and R/S in the other variants): per-unit texture coordinate loaded from the end vertex, then overwritten by the lerp result in the same statement `v = edgeT * (v - start) + start`, then scaled by 1/w and stored.
- `_gleInterpolClipNO0000`: not named: the same registers carry end-clip w, the interpolated clip w, the edge parameter and start/end clip coordinates in different branches (`fVar4`, `fVar7`, `fVar10`, `fVar11`, `fVar9` are permuted by plane); no single name is true for all uses.
- `_gleBuild*` (RTC builders): `chunkWordCountThenCodeCursor`: the word count returned by `_gleRTCAddAChunk_*` is overwritten by the advanced code cursor (`iVar7 = iVar5 + 0x20 + iVar7 * 4`).
- `_glUniform*ARB_Exec` / `_glUniformMatrix*`: `registerIndexThenOffset`: the constant-register index looked up in the stage record is multiplied by 16 in place to a byte offset.

## State-validation idiom (RasterPos*, CopyTex*, Draw*Noop*, DrawArraysOrElements*, BeginQuery/EndQuery ...)
- `dirtyWord3ThenMasked`: one register first holds the dirty flag word at context offset 0x31c (`uVar = *(uint *)(ctx + 0x31c)`, tested against 0x15555), then is overwritten in place by `uVar & 0x17000000` / `uVar & 0x17ffffff` for the all-clean test. Joined name for both stages.

## glGetTexGen{i,f,d}v_Exec
- `texUnitThenMode`: one register first holds the active texture unit (context +0x53d4), then is overwritten in place by the 16-bit texgen mode word of that unit (unit * 0x94 + ctx + 0x3ce8..) that is returned for GL_TEXTURE_GEN_MODE. Joined name for both roles.
