# r22: weak-name fixes (GLDriver)

Plain renames: ilTypeToLaneKindTable (+ptrTo_), Program__laneKindOfIlType,
psnDefaultOperandWord2_001dbf94, opcodeTemplateTablePtrsToken14/15/16,
declContextTable->stateBlock, isIndexedLoadVariant->isRegisterType20,
extensionWordPtr->regWordBasePtr (translateILInstruction only).
Neutral names for hybrid webs: readerStateOrScratch->scratchRegister,
instOrSourceCount->nodeOrCount, scratchInstOrOperandIndex->scratchPtrOrConst.
No further splits possible (each hybrid sits on one def-use web).
Pool rows: 69 reworded to "referenced only through the pool".
Gates: apply_names --check 0 pending/0 errors (105714 applied);
compile gate vs 35a8b28b SPLIT-EQUIVALENT (parts 017/024/026, 0 problems);
datacheck diffs are rename-only text.
