# Gate-rejected splits in parts 006-009 (q02)

Whole-variable joined names (`AOrB`) stand for these registers; the finer per-web names below were tried and rejected by the compile gate
(SPLITS=1 verify_names.sh, USE_DECL=beside placement), gate logs in ~/g5logs.

* `extvsPrepareHardwareProgram` (`FUN_0005f810`): the pointer-plus-offset hybrids `iVar18 = iVar11 + iVar18` / `iVar19 = iVar16 + iVar19`.
  Naming the webs `symbolRecord`, `symbolRecord2`, `symbolRecords`, `symbolRecords2` separately gave
  `MERGE _FUN_0005f810 candidate slot 264 stands for 260 and 116` and `slot 288 stands for 284 and 112` (gate q02_s10, also q02_44 earlier). The joined names
  `recordOffsetOrCount` (iVar11), `recordOrOffsetScratch` (iVar16), `symbolRecordOrCallResult` (iVar18), `symbolRecordsBase` (iVar19) are accepted
  (gate q02_66 IDENTICAL).  `src2Operand` (iVar16 web 25, the `x = f(x)` handler call) gave UNINIT 4 -> 5 and stays inside the joined iVar16 name.
* `extvsAssignVertexInputs` (`FUN_0005e7f0`): splitting iVar17 into `instrRecords` / `rowsLeft` gave
  `DATAFLOW ... 6 loads reached by different stores` and `ADDRESS-TAKEN split _FUN_0005e7f0 56` (gates q02_s4, q02_s5, q02_s8 "rowsLeft" probe). The hybrids
  iVar4 / iVar7 / iVar16 (bound count, data type, symbol record copies in the three unrolled operand copies) were not split; joined names
  `instrRecordsOrRowsLeft`, `symbolRecordOrBoundCount`, `boundCountOrDataType`, `boundCountCopyOrRecord` (gate q02_67 IDENTICAL).
* `fragmentInstructionToIL`: iVar23 / iVar24 at the `fpilTranslateDestination` / `fpilTranslateSource` result group (`iVar23 = f(iVar23 + 0x10)` on one line) cannot
  be split by the line-range tool (lhs and rhs of one statement with a later use of the result on the same line).
* Declaration placement: new declarations must follow the first declaration and precede the fake-struct arrays (notes_q06_split_placement.md). `USE_DECL=beside` used.
* Registers `in_r7` / `in_r8` of `extvsPrepareHardwareProgram` (stale call arguments) and `extraout_*` / `in_f*` residuals are decompiler artifacts and are not renamed.
