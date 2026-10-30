# q04 (parts 015-018) names that stay multi-role or inferred-by-offset

Written during the Oct 29-30 q04 round. Every entry says why the name could not be split further (gate evidence in the commit message).

* `gld_validateDirtyState` (FUN_000a9ac0): `puVar16` is named `staleR4Chain` - it only carries the r4 value left over after each helper call (Ghidra `extraout_r4` chain), there is no source variable. `puVar21` (`dirtyHighMask`) is reused as an argument-register image after its last real use. `stackWord64..stackFloat40` are the stack slots compared with the identity matrix (values come from the caller frame; Ghidra shows them as locals, they are not initialised in this function).
* `psnDecReplaceSourceAddress`: `param_4` (`halfSelect`), `param_6` (`sourceReg`) and `param_8` (`freeSlotIndex`) are incoming parameters that the function overwrites with loop scratch values; apply_names cannot split parameters, and the later values are forwarded as stale arguments of psnDecCanonicalizeEntry.
* `psnDecTryMergeAddressSlots`: `uVar9` (`slotFound`) first holds `destSelect & 0x100` (dead) and then the found flag; `puVar14` (`usageSlotPtr`) points into the usage words in two loops and is then forwarded as a stale argument; `param_4` (`staleArgR6`) is only written (0xffff) and forwarded.
* `psnDecodedToProgram`, `psnProgramToDecoded`: the `uVar12`/`uVar13` webs that share a register across the rgb and alpha halves are named per web; the one-hot -> code switch (`outputScaleCode`) reuses `uStack_31` as a byte slot.
* `FUN_000a4770`: `quantizedSize` (fVar3) is one name for two webs: the split made the quantized value possibly-uninitialised (gate UNINIT 0->1). `FUN_000b6f20`: `field15Bits` is one name for a saturated/unsaturated pair for the same reason. `FUN_000a7a60`: `packedFormatBits` merges the format word read and the repacked value (statement `x = f(x)` with a read on the rhs). `FUN_000a6500`: `fillPattern` merges three webs (gate UNINIT 4->5 when split).
* `FUN_000b4cd0`: `resultByte0..4` / `rangeStart..rangeReserved1` / `decodeInfo` / `decodeBuffer` are Ghidra overlays on one stack frame (fake struct); they are named whole-variable only.
* Tool fix (Tools/userspace/find_webs.py): `a && var` was read as `& var` (address-of) and made every variable on the rhs of a `&&` unsplittable; fixed, so earlier "address taken" skips in other functions can now be revisited.
* `FUN_000a3be0` (`gld_setPrimitiveInputRegisters`): the incoming parameters `param_3` (`unitCounter`) and `param_5` (`tableCursor`) are overwritten with loop scratch values in the different branches (parameters cannot be split); `uVar10`/`uVar5` webs are named per web.
* `FUN_000abd10` (`gld_scanProgramTokens`): `operandScratch0..3` are the 4-float vector passed by address plus plain temporaries in opcodes 0x5d/0x5e; they are adjacent stack slots addressed relative to each other (whole-variable names only).
* find_webs pitfall (psnDecEncodeHwWords): a definition inside a condition expression (`(x = 5, ...)`) is not seen as a definition, so such a variable's webs are split wrongly (DATAFLOW). Merge the affected webs under one name (rgbSourceSelect).
* FUN_000bef40 (psnRemapTempRegisters): scalar webs of bools and ints next to the address-taken remap table failed ADDRESS-TAKEN splits; merged (bankFlag, remapIndex, countdownIndex). gld_compileILProgram (FUN_000b4400): local renames only (iVar8 loopCounter, iVar10 regLoopValue, ... multi-role); splitting gave ADDRESS-TAKEN/CODE failures even with USE_DECL=beside.
* ilRewriteForTextureState and ilAssembleProgram: not named (about 1900 uses): ~100 stack locals of an IL token interpreter whose roles overlap across two passes.

## Late additions (ilAssembleProgram / extvsInstReadsTempComponents)

- ilAssembleProgram `uVar33`: its size-accumulation webs are defined inside conditions
  (`if (cond && (x = y + 0xc, flag))`), so web splitting yields DATAFLOW garbage, and the older gT_B4/B5
  anchored rows depend on the raw `uVar33` text. It is named as ONE variable (`scratchWord`) by a trailing
  `use ... *` row (`names_q04_ac.tsv`); the already-split `sizeBytes*` webs keep their names.
- ilAssembleProgram `pppppppuVar20`/`pppppppuVar25` carry a stale call argument across unrelated code and are
  named `scratchCursorA/B` (neutral).
- extvsInstReadsTempComponents `bVar1..bVar16`: each holds a different operand/component test in different opcode
  cases and every definition sits inside a comma expression, so no semantic split is possible; they get the neutral
  `componentReadFlag<N>` (N = original decompiler index).
- Remaining placeholders in parts 015-018 (24) are call-site references to callees whose bodies live in
  other forks' parts (FUN_0004b190, FUN_00064720, FUN_0004e990, FUN_0004ce30, FUN_0004ab60, FUN_0004b710,
  FUN_0003b160, FUN_00050ef0, FUN_0004d620, FUN_0004ac90, FUN_000d8450/55c0/5390, FUN_000da0c0/420/78c,
  FUN_000e0ca8/0cd0/0e28/161c, FUN_00193b3c/be8); they resolve when the owning fork names the callee.
