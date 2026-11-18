# Round 6 naming, agent S: placeholders left in place, refused splits, proposed source fixes

Function list: `r6_S.txt` (111 functions, 5605 placeholder occurrences at the start of round 6).
Every name in the part files came from a `names_loc6_S_<NN>.tsv` row (or a `rn.py` rename of such
a row) and the tree was gated with `gate_agent.sh` (tags S6_1 .. S6_12) with `VERDICT: IDENTICAL`
before each commit.

## The merge rule (why most "refused splits" are refused)

The image build (`link_corpus.py` LOCAL_RENAMES + `fix_link_tree.py`) reverts every renamed
variable to its Ghidra name, runs the rewrites, then re-applies ONE real name per Ghidra variable.
All webs (def-use chains) of one Ghidra variable therefore merge into ONE variable of the
image under the single alias name, including the "plain" webs that carry no row. Giving a second,
different name to one web of such a variable splits the stock image's variable in two, and gcc 4.0.1
(-O2 -mtune=970) then allocates registers or orders instructions differently: gate DIFFERENT.
Some splits pass by chance (`_gleRenderSmoothQuadStripFunc_body` iVar17 web 2, `_gleFreeOrphans`
iVar7 web 0); do not rely on that.

Consequences used in this round:

- A whole-variable `local` row never changes the bytes.
- Where a Ghidra variable has several roles in different webs, ONE joined name for ALL webs
  (`rn.py ren` of the existing alias to the joined name plus `use` rows for the plain webs, then
  `dupdecl.py --fix`) is neutral. Each role in a joined name was verified in the code.
- Gate failures that showed the rule: S6_2/S6_3 (`_gleRenderFlatTriangleFanFunc_body`), S6_5 (4
  functions), S6_9 (7 functions: `_gleFeedbackQuadsFunc_body`, `_glSeparableFilter2D_Exec`,
  `_glDetachObjectARB_Exec`, `_gleUpdateDispatchCodeChange`, `_gleFeedbackTrianglesFunc_body`,
  `_gleSelectTrianglesFunc_body`, `_gleVPRenderQuads_body`), all fixed by joined names and
  re-gated IDENTICAL (S6_7, S6_10).
- A faster pre-gate check (compile only the changed parts on the G5 and compare function
  instruction sequences, ~3 min) was used before every formal gate.

## Refused splits (separate names per role)

- `_gleRenderFlatTriangleFanFunc_body` iVar8: a separate name for the run count / cull result web
  (gate S6_2) changed the code. One joined name
  `texEnableBitsThenLightCursorThenRunCountThenCullResultThenLightOffset` is used for all webs.
- `_gleRenderFlatTriangleFanFunc_body` iVar10 web 0 as `runBackFacing` (gate S6_3) changed the
  code: the same Ghidra variable also holds the light loop count (web 0) and the polygon vertex
  count (webs 1, 2). One joined name for all webs
  (`runBackFacingThenLightLoopCountThenPolygonVertexCount`).
- The same register-reuse pattern (texture enable bits / run vertex count / cull result /
  back-facing in one variable, run back-facing / polygon vertex count in another) exists in the
  whole `*_body` render family: `_gleVPRenderTriangles_body`, `_gleVPRenderQuadStrip_body`,
  `_gleRenderSmoothTriangleFanFunc_body`, `_gleRenderSmoothQuadsFunc_body`,
  `_gleRenderSmoothQuadStripFunc_body`, `_gleRenderFlatTrianglesFunc_body`. Joined names are used
  in each, with the roles listed in the rows' evidence column.

## Joined names in use (every role verified in the code)

- `_glTexImage2D_Comp` uVar2 `glErrorCodeThenExecResultThenFillImageResult`, uVar3
  `expectedFormatThenAlignedImageSize`, iVar5 `glContextThenBytesPerElementThenImageSize`;
  `_glTexSubImage2D_Comp` uVar3 `glErrorCodeThenFillImageResult`, iVar5 as above.
- `_glCombinerParameterivNV_Exec` / `_glCombinerStageParameterfvNV_Exec`: the colour floats hold
  the raw component first and the clamped next component afterwards
  (`redFloatThenClampedGreen`, `greenFloatThenClampedBlue`, `blueFloatThenClampedAlpha`;
  `redThenClampedGreen` ... in the stage variant); `clampedRed` is its own variable.
- `_gleDrawArraysOrElements_IMM_Exec` uVar10, `_gleDrawArraysOrElements_CVA_Exec` uVar11.
- `_glProgramStringARB_Exec` iVar6, iVar7, iVar8, uVar3, uVar4, puVar1 (loop counters, offsets
  and cursors share registers across the 0x8620 and 0x8804 paths).
- `_gleClipPoly` iVar1, uVar2, iVar5; `_gleVAClipPoly` bVar3, puVar7, puVar9.
- `_gliAttachDrawableWithOptions` iVar2; `_gleDrawPixelsSaveState` uVar1.

## Roles not established (placeholder or low-confidence name left)

- `_gleTestFence` param_2: every caller passes 0; no read inside the function fixes a role.
- `_gleSetAttrib` fVar9: a float-typed variable that holds an integer register value (decompiler
  type artefact), role not named.
- `DeletePluginTextureLevel` levelRangeShift is INFERRED.
- `_gliAttachDrawableWithOptions` param_2 / param_3 (`drawableWord484c` / `drawableWord4848`):
  only their destination (ctx+0x484c / 0x4848) and their pass-through to the renderer's attach
  callback are established, not what the two drawable words mean.
- `_gleDrawArraysOrElements_VBO_Exec` piVar7 / piVar8 / iVar9 (copies of the incoming arguments
  that are re-used as shifted outgoing arguments of `_gleUpdateFramebufferCompleteness`, plus
  loop counters): not named, the joined name would list five roles and has no value.
- `_gleVtxLight*` bodies: the first floating register parameter `fparam_1` is both an incoming
  argument and a scratch value; not named.
- Large JIT builders and the 28 KB `_gleTextureImagePut_Slow`, `_gleDrawPixelsFast`: not
  attempted beyond what is committed; the per-web role maps of their 40..80-web variables need
  hours of tracing each.

## Proposed source fixes (not applied; the lead gates them separately)

1. `_glUniformMatrix4fvARB_Comp` (observed earlier in this round, not re-verified for this
   write-up): the stock code allocates `count * 0x30 + 8` bytes for the display-list item and
   advances 0xc words per matrix, but 16 floats are written per matrix and the matching ListExec
   returns `count * 0x40 + 8` (stock `mulli r5,r5,0x30` at 0x8db84). That is a heap overflow in
   the stock code which the corpus reproduces byte for byte; it is a stock defect, not a corpus
   defect. Changing the factor to 0x40 would change the bytes, so it cannot be done as a naming
   row.
2. `_glMap2d_CompExec`: a stale stack word is forwarded as an extra call argument
   (`incomingStackWord_*`); it is noise for the callee.
3. The corpus declares `double` variables for registers that carry integers or pointers
   (`_gleSetAttrib` fVar9); a type fix in the part file would let the variable be named by its
   real role.

## Conventions

- `incomingStack_<hex>` -> `incomingStackWord_<hex>` (round 6).
- Floating register left by the previous call and passed on unchanged: `forwardedFpr1`
  (INFERRED), as in `_gleDrawPixelsFast`.
- `glContextByte<hex>` / `drawableWord<hex>` name a value by the context offset it is stored to.
