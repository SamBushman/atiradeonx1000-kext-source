# GLDriver part_006..009 naming round (fork lp18, tag gR): findings

* **glContext is GLDContext+0x240.** `gldValidate*`, `FUN_0004a860..FUN_00053000` (state block) and `gldEmitHardwareState` (was FUN_00050300) take the GL context state
  object that is embedded at `GLDContext+0x240` (fields_gld.tsv calls that offset `commandStream`: it carries the stream callbacks `streamAllocate` (+0x2998 =
  glContext+0x2758) and `streamSetCurrent` (+0x299c = glContext+0x275c)). Shadow registers read as `glContext + (field offset - 0x240)`. `FUN_0002c6c0` calls
  `gldEmitHardwareState(ctx + 0x240)`; `glContext+4` points to the GL state object (`glState`), whose +0x10 is the GL state block.
* **Register map from the AMD PDFs.** `Tools/userspace/lpnames/regmap_r3xx_r5xx.json` maps register byte addresses to names (R3xx_3D_Registers.pdf + R5xx_Acceleration_v1.5.pdf, 235
  registers). The state packets are {id, value} pairs with id = byte address / 4 (bits 16+ = count-1); `fieldwebs.py` pairs each shadow load with the id written next to it.
  Audit against fields_gld.tsv: 14 of 16 checked fields agree; the 2 disagreements are `ga_color_control` (0x1df8, table says id 0x109e = GA_COLOR_CONTROL 0x4278, but in
  `gldEmitHardwareState` the word is paired with id 0x1096 = GA_COLOR_CONTROL_PS3 0x4258, and ctx+0x1d6c pairs with 0x4278) and `gb_ps3_enable` (alias of PS3_ENABLE).
  OPEN: fields_gld.tsv row 0x1df8 is probably `ga_color_control_ps3` and 0x1d6c `ga_color_control`; GLD_ga_color_control is used in part_004/005 (other forks' ranges), so it was
  not renamed here.
* **Positional names.** `glContextWord<hex>` (offset relative to glContext) names a shadow/state word that has no fields_gld.tsv row and no register pairing; they still need roles.
  Known roles are in `fieldwebs.py` EXTRA (`registerDirty` +0x1930, `glState` +4, `dirtyWord0/1` +0x38/+0x3c).
* **extvsEmit*** emitters share one inlined block: `hwProgram` (**(int**)(*(ctx+0x118c)*4 + *shader): +0x18 `instCount`, +0x1c instruction array, +0x20 capacity bytes), a 16-byte
  `instSlot`, operands of the IL record (`instRecord`: destination at +4, `src0Operand` +0x20, `src1Operand` +0x3c, `src2Operand` +0x58, 0x1c bytes each: kind, index, 4 component words,
  flag byte). `extvsEncodeSourceOperand/Swizzle` use the EXT_vertex_shader enumerants (0x87d5..0x87df swizzle selectors, 0x87be..0x87c0 SCALAR/VECTOR/MATRIX_EXT, 0x87c1..0x87c4 storage).
* **arbEmitIl*** build `token = (file & 0x3f) << 16 | index & 0xffff` per operand plus a packed select/negate word. `arbEmitIlMad` is fully named; the packed-word-after-token
  heuristic of `arbop_family.py` is only valid there (the 2Src/AddMad3Src/Rnd emitters interleave opcode tokens), so those keep only the token/component names.
* Tools added: fieldwebs.py, family.py, chainsplit.py, extvs_family.py, tmpoperands.py, arbop_family.py (Tools/userspace/lpnames).
