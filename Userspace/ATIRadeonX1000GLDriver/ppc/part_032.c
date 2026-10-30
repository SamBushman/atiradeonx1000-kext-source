#include "decls.h"

/* Program__countUsedInterpolatorSlots @ 0x10f704 (376 bytes) */
int Program__countUsedInterpolatorSlots(scopeId, vector, compiler)
  int scopeId;
  uint *vector;
  int compiler;
{
  uint vectorCount;
  uint loopIndex2;
  int bitCountdown;
  undefined4 *bitsetClearCursor;
  undefined4 *allocation;
  int *vectorElementRef;
  int usedSlotCount;
  uint recordSlot;
  uint slotWordOffset;
  undefined4 *usedSlotBitset;
  undefined4 arena;
  uint loopIndex;
  
  arena = *(undefined4 *)(compiler + COMP_arenaB);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  usedSlotBitset = allocation + 1;
  allocation[1] = 2;
  *allocation = arena;
  allocation[2] = 0x30;
  loopIndex2 = 0;
  bitsetClearCursor = usedSlotBitset;
  do {
    loopIndex2 = loopIndex2 + 1;
    bitsetClearCursor[2] = 0;
    bitsetClearCursor = bitsetClearCursor + 1;
  } while (loopIndex2 < 2);
  vectorCount = vector[1];
  loopIndex = 0;
  if (vectorCount != 0) {
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (int *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (int *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      if (*(int *)(*vectorElementRef + 0x1c) == scopeId) {
        recordSlot = *(uint *)(*vectorElementRef + 0x14);
        slotWordOffset = recordSlot >> 3 & 0x1ffffffc;
        *(uint *)((int)usedSlotBitset + slotWordOffset + 8) =
             1 << (recordSlot & 0x1f) | *(uint *)((int)usedSlotBitset + slotWordOffset + 8);
      }
      vectorCount = vector[1];
    } while (loopIndex < vectorCount);
  }
  bitCountdown = allocation[2];
  usedSlotCount = 0;
  if (bitCountdown != 0) {
    loopIndex2 = 0;
    do {
      if ((*(uint *)((int)usedSlotBitset + (loopIndex2 >> 3 & 0x1ffffffc) + 8) >> (loopIndex2 & 0x1f) & 1) != 0) {
        usedSlotCount = usedSlotCount + 1;
      }
      loopIndex2 = loopIndex2 + 1;
      bitCountdown = bitCountdown + -1;
    } while (bitCountdown != 0);
  }
  return usedSlotCount;
}

/* Program__renumberExportInsts @ 0x10f87c (424 bytes) */
int Program__renumberExportInsts(program, unusedArg2, vector)
  int program;
  undefined4 unusedArg2;
  uint *vector;
{
  uint vectorCount;
  int operandRecord;
  bool moreLanes;
  uint laneRecordCount;
  undefined4 *vectorElementRef;
  int laneKind;
  int *laneRecordRef;
  uint nextExportIndex;
  uint exportIndex;
  int laneNumber;
  int exportInst;
  uint loopIndex;
  uint *laneRecordVector;
  int recordKindOrIndex;
  int laneRecord;
  
  vectorCount = vector[1];
  if (vectorCount != 0) {
    exportIndex = 0;
    do {
      if (exportIndex < *vector) {
        if (vectorCount <= exportIndex) {
          _memset(vectorCount * 4 + vector[2],0,(exportIndex - vectorCount) * 4 + 4);
          vector[1] = exportIndex + 1;
        }
        vectorElementRef = (undefined4 *)(exportIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,exportIndex);
      }
      nextExportIndex = exportIndex + 1;
      exportInst = *(int *)*vectorElementRef;
      if (*(uint *)(exportInst + 0x94) != exportIndex) {
        operandRecord = IRInst__getOperandRecord(exportInst,0);
        laneNumber = 0;
        *(uint *)(operandRecord + 8) = exportIndex;
        do {
          laneRecordVector = *(uint **)(program + 0x418);
          laneRecordCount = laneRecordVector[1];
          if (laneRecordCount != 0) {
            loopIndex = 0;
            do {
              if (loopIndex < *laneRecordVector) {
                if (laneRecordCount <= loopIndex) {
                  _memset(laneRecordCount * 4 + laneRecordVector[2],0,(loopIndex - laneRecordCount) * 4 + 4);
                  laneRecordVector[1] = loopIndex + 1;
                }
                laneRecordRef = (int *)(loopIndex * 4 + laneRecordVector[2]);
              }
              else {
                laneRecordRef = (int *)Vector__elementRefGrow(laneRecordVector,loopIndex);
              }
              laneRecord = *laneRecordRef;
              recordKindOrIndex = *(int *)(laneRecord + 4);
              laneKind = IRLoadInterp__laneKind_104ee4(exportInst,laneNumber);
              if (((recordKindOrIndex == laneKind) &&
                  (recordKindOrIndex = *(int *)(laneRecord + 8), laneKind = IRLoadInterp__laneIndex_104180(exportInst,laneNumber), recordKindOrIndex == laneKind
                  )) && (*(int *)(laneRecord + 0x18) == laneNumber)) {
                *(uint *)(laneRecord + 0xc) = exportIndex;
                *(uint *)(laneRecord + 0x14) = exportIndex;
                break;
              }
              laneRecordVector = *(uint **)(program + 0x418);
              loopIndex = loopIndex + 1;
              laneRecordCount = laneRecordVector[1];
            } while (loopIndex < laneRecordCount);
          }
          moreLanes = laneNumber != 3;
          laneNumber = laneNumber + 1;
        } while (moreLanes);
      }
      vectorCount = vector[1];
      exportIndex = nextExportIndex;
    } while (nextExportIndex < vectorCount);
  }
  return;
}

/* Program__bindLinkRecordsToSlots @ 0x10fa24 (304 bytes) */
int Program__bindLinkRecordsToSlots(scopeId, slotOwnerRegister, firstSlot, slotEnd, vector)
  int scopeId;
  int slotOwnerRegister;
  int firstSlot;
  int slotEnd;
  uint *vector;
{
  int *vectorElementRef;
  int slotsLeft;
  uint vectorCount;
  int foundSlot;
  int *slotScanCursor;
  int vectorElement;
  uint loopIndex;
  
  vectorCount = vector[1];
  if (vectorCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (int *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (int *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = *vectorElementRef;
      if ((*(int *)(vectorElement + 0x1c) == scopeId) && (firstSlot < slotEnd)) {
        foundSlot = firstSlot;
        if (*(int *)(vectorElement + 0x14) != *(int *)(slotOwnerRegister + firstSlot * 4)) {
          slotsLeft = slotEnd - firstSlot;
          slotScanCursor = (int *)(slotOwnerRegister + firstSlot * 4);
          do {
            foundSlot = foundSlot + 1;
            slotsLeft = slotsLeft + -1;
            if (slotsLeft == 0) goto LAB_0010fb28;
            slotScanCursor = slotScanCursor + 1;
          } while (*slotScanCursor != *(int *)(vectorElement + 0x14));
        }
        *(int *)(vectorElement + 0x14) = foundSlot;
      }
LAB_0010fb28:
      vectorCount = vector[1];
    } while (loopIndex < vectorCount);
  }
  return;
}

/* Program__assignExportSlotsByKind @ 0x10fb54 (308 bytes) */
int Program__assignExportSlotsByKind(vector, nextSlotRef, program)
  uint *vector;
  int *nextSlotRef;
  int program;
{
  int exportRecordInst;
  uint vectorCount;
  undefined4 *vectorElementRef;
  int bindingKind;
  int slotEnd;
  int assignedSlot;
  int firstSlot;
  uint loopIndex;
  int *vectorElement;
  int exportInst;
  undefined4 slotOwnerRegister [51];
  
  slotEnd = 1;
  firstSlot = *nextSlotRef;
  *nextSlotRef = firstSlot + 4;
  vectorCount = vector[1];
  if (0 < (int)vectorCount) {
    loopIndex = 0;
    slotEnd = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = (int *)*vectorElementRef;
      exportInst = *vectorElement;
      bindingKind = Lane__remapValue(*(undefined4 *)(exportInst + 0x13c),*(undefined4 *)(exportInst + 0x140));
      assignedSlot = firstSlot + bindingKind;
      if (3 < bindingKind) {
        assignedSlot = *nextSlotRef;
        *nextSlotRef = assignedSlot + 1;
        exportInst = *vectorElement;
      }
      slotOwnerRegister[assignedSlot] = *(undefined4 *)(exportInst + 0x94);
      exportRecordInst = *vectorElement;
      *(undefined4 *)(exportRecordInst + 0x98) = 5;
      *(int *)(exportRecordInst + 0x94) = assignedSlot;
      if (slotEnd < assignedSlot) {
        slotEnd = assignedSlot;
      }
      vectorCount = vector[1];
    } while ((int)loopIndex < (int)vectorCount);
    slotEnd = slotEnd + 1;
  }
  return ((int (*)())Program__bindLinkRecordsToSlots)(2,slotOwnerRegister,firstSlot,slotEnd,*(undefined4 *)(program + 0x418));
}

/* Program__assignOutputExportSlots @ 0x10fc88 (272 bytes) */
int Program__assignOutputExportSlots(bindContext, vector, unusedArg3, program)
  undefined4 bindContext;
  uint *vector;
  undefined4 unusedArg3;
  int program;
{
  int exportInstB;
  int assignedSlot;
  uint vectorCount;
  int exportInstA;
  undefined4 *vectorElementRef;
  int slotEnd;
  int *vectorElement;
  int outputBase;
  uint loopIndex;
  undefined4 slotOwnerRegister [53];
  
  vectorCount = vector[1];
  outputBase = *(int *)(program + 0x3f0);
  slotEnd = 1;
  if (0 < (int)vectorCount) {
    loopIndex = 0;
    slotEnd = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = (int *)*vectorElementRef;
      exportInstA = *vectorElement;
      assignedSlot = outputBase + *(int *)(exportInstA + 0x140);
      slotOwnerRegister[assignedSlot] = *(undefined4 *)(exportInstA + 0x94);
      exportInstB = *vectorElement;
      *(undefined4 *)(exportInstB + 0x98) = 5;
      *(int *)(exportInstB + 0x94) = assignedSlot;
      if (slotEnd < assignedSlot) {
        slotEnd = assignedSlot;
      }
      vectorCount = vector[1];
    } while ((int)loopIndex < (int)vectorCount);
    slotEnd = slotEnd + 1;
  }
  return ((int (*)())Program__bindLinkRecordsToSlots)(bindContext,slotOwnerRegister,outputBase,slotEnd,*(undefined4 *)(program + 0x418));
}

/* Program__assignSharedExportSlots @ 0x10fd98 (396 bytes) */
int Program__assignSharedExportSlots(scopeId, vector, nextSlotRef, program)
  undefined4 scopeId;
  uint *vector;
  int *nextSlotRef;
  int program;
{
  bool foundExisting;
  int scanRemaining;
  int tableByteOffset;
  int elementRecord;
  int registerKey;
  int endSlot;
  int registerRecord;
  uint vectorCount;
  undefined4 *vectorElementRef;
  int *vectorElement;
  int slotNumber;
  int *slotCursor;
  uint loopIndex;
  int firstSlot;
  int slotTable [52];
  
  firstSlot = 0x30;
  tableByteOffset = 0;
  do {
    *(undefined4 *)((int)slotTable + tableByteOffset) = 0xffffffff;
    tableByteOffset = tableByteOffset + 4;
    firstSlot = firstSlot + -1;
  } while (firstSlot != 0);
  vectorCount = vector[1];
  firstSlot = *nextSlotRef;
  endSlot = firstSlot;
  if (0 < (int)vectorCount) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorElementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      vectorElement = (int *)*vectorElementRef;
      registerKey = *(int *)(*vectorElement + 0x94);
      if (firstSlot < 0x30) {
        scanRemaining = 0x30 - firstSlot;
        slotCursor = slotTable + firstSlot;
        foundExisting = false;
        slotNumber = firstSlot;
        do {
          if (registerKey == *slotCursor) {
            registerRecord = *vectorElement;
            foundExisting = true;
            *(undefined4 *)(registerRecord + 0x98) = 5;
            *(int *)(registerRecord + 0x94) = slotNumber;
          }
          slotNumber = slotNumber + 1;
          slotCursor = slotCursor + 1;
          scanRemaining = scanRemaining + -1;
        } while (scanRemaining != 0);
        if (!foundExisting) goto LAB_0010febc;
      }
      else {
LAB_0010febc:
        slotNumber = *nextSlotRef;
        slotTable[slotNumber] = registerKey;
        elementRecord = *vectorElement;
        *(int *)(elementRecord + 0x94) = slotNumber;
        *(undefined4 *)(elementRecord + 0x98) = 5;
        *nextSlotRef = *nextSlotRef + 1;
      }
      vectorCount = vector[1];
    } while ((int)loopIndex < (int)vectorCount);
    endSlot = *nextSlotRef;
  }
  return ((int (*)())Program__bindLinkRecordsToSlots)(scopeId,slotTable,firstSlot,endSlot,*(undefined4 *)(program + 0x418));
}

/* PackEntry__bindToVectorRegister @ 0x10ff24 (252 bytes) */
int PackEntry__bindToVectorRegister(packEntry, vector)
  int *packEntry;
  uint *vector;
{
  int entryDestRegister;
  uint vectorCount;
  int *record;
  int *laneSourceCursor;
  int laneNumber;
  uint loopIndex;
  int laneCountdown;
  
  vectorCount = vector[1];
  if (vectorCount != 0) {
    loopIndex = 0;
    do {
      if (loopIndex < *vector) {
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        record = (int *)(loopIndex * 4 + vector[2]);
      }
      else {
        record = (int *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      record = (int *)*record;
      if (record[7] == packEntry[6]) {
        laneCountdown = 4;
        laneNumber = 0;
        laneSourceCursor = packEntry;
        do {
          if (*record == laneSourceCursor[1]) {
            entryDestRegister = *(int *)(*packEntry + 0x94);
            record[6] = laneNumber;
            record[5] = entryDestRegister;
          }
          laneNumber = laneNumber + 1;
          laneSourceCursor = laneSourceCursor + 1;
          laneCountdown = laneCountdown + -1;
        } while (laneCountdown != 0);
      }
      vectorCount = vector[1];
    } while (loopIndex < vectorCount);
  }
  return;
}

/* Program__collectExportEntry @ 0x110020 (204 bytes) */
int Program__collectExportEntry(program, valueKey)
  int program;
  int valueKey;
{
  int laneNumber;
  int kindQuery690;
  int kindQuery6e8;
  int kindQuery744;
  uint vectorAt418Count;
  uint *vectorAt418;
  undefined4 *allocation;
  undefined4 arena;
  int valueNumberEnabled;
  int operandRecord2;
  bool moreLanes;
  int isOutputInst;
  undefined4 *exportListSlotRef;
  int operandRecord;
  undefined4 laneIndexValue;
  undefined4 semanticCode;
  undefined4 *laneRecordSlotRef;
  int *exportRecord;
  undefined4 laneValue;
  uint exportListCount;
  undefined4 destRegister;
  undefined4 laneKind;
  undefined4 arenaAt374;
  int *outputInst;
  uint *exportListVector;
  
  outputInst = *(int **)(valueKey + 0xb0);
  isOutputInst = IRInst__query68AndWord4fNotIn6_7(outputInst);
  if (isOutputInst == 0) {
    return;
  }
  operandRecord2 = IRInst__getOperandRecord(outputInst,0);
  if (*(int *)(operandRecord2 + 0x10) == DAT_001afa14) {
    Program__removeInst(program,outputInst);
                    
                    
    (**(code **)(*outputInst + 0xc))(outputInst,0,*(undefined4 *)(program + 8));
    return;
  }
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x30);
  exportRecord = allocation + 1;
  *allocation = arena;
  LaneInfo__ctor_10e814(exportRecord,outputInst);
  kindQuery744 = IRInst__query68AndWord4fNotMasked(outputInst);
  if (kindQuery744 == 0) {
    kindQuery6e8 = IRInst__query68AndWord4fIn16_17(outputInst);
    if (kindQuery6e8 == 0) {
      kindQuery690 = IRInst__query68AndWord4fIs18(outputInst);
      if (kindQuery690 == 0) goto LAB_001101ac;
      exportListVector = *(uint **)(program + 0x424);
      exportListCount = exportListVector[1];
      if (exportListCount < *exportListVector) goto LAB_00110170;
    }
    else {
      exportListVector = *(uint **)(program + 0x420);
      exportListCount = exportListVector[1];
      if (exportListCount < *exportListVector) goto LAB_00110170;
    }
LAB_0011019c:
    exportListSlotRef = (undefined4 *)Vector__elementRefGrow(exportListVector,exportListCount);
  }
  else {
    exportListVector = *(uint **)(program + 0x41c);
    exportListCount = exportListVector[1];
    if (*exportListVector <= exportListCount) goto LAB_0011019c;
LAB_00110170:
    _memset((void *)(exportListCount * 4 + exportListVector[2]),0,4);
    exportListSlotRef = (undefined4 *)(exportListCount * 4 + exportListVector[2]);
    exportListVector[1] = exportListCount + 1;
  }
  *exportListSlotRef = exportRecord;
LAB_001101ac:
  valueNumberEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),7);
  if (valueNumberEnabled != 0) {
    ValueKey__initResultLaneValues(valueKey);
    PackEntry__assignLaneSources(exportRecord,valueKey + 0x20);
  }
  laneNumber = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*exportRecord,0);
    if (*(char *)(laneNumber + operandRecord + 0x10) != '\x01') {
      laneValue = *(undefined4 *)(valueKey + 0x20);
      laneKind = IRLoadInterp__laneKind_104ee4(*exportRecord,laneNumber);
      laneIndexValue = IRLoadInterp__laneIndex_104180(*exportRecord,laneNumber);
      destRegister = *(undefined4 *)(*exportRecord + 0x94);
      semanticCode = RegKind__laneSourceCount(*(undefined4 *)(*exportRecord + 0x13c));
      arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaAt374,0x24);
      *allocation = arenaAt374;
      allocation[1] = laneValue;
      allocation[2] = laneKind;
      allocation[3] = laneIndexValue;
      allocation[6] = destRegister;
      allocation[8] = semanticCode;
      allocation[4] = destRegister;
      allocation[5] = laneNumber;
      allocation[7] = laneNumber;
      vectorAt418 = *(uint **)(program + 0x418);
      vectorAt418Count = vectorAt418[1];
      if (vectorAt418Count < *vectorAt418) {
        _memset((void *)(vectorAt418Count * 4 + vectorAt418[2]),0,4);
        laneRecordSlotRef = (undefined4 *)(vectorAt418Count * 4 + vectorAt418[2]);
        vectorAt418[1] = vectorAt418Count + 1;
      }
      else {
        laneRecordSlotRef = (undefined4 *)Vector__elementRefGrow(vectorAt418,vectorAt418Count);
      }
      *laneRecordSlotRef = allocation + 1;
    }
    moreLanes = laneNumber != 3;
    valueKey = valueKey + 4;
    laneNumber = laneNumber + 1;
  } while (moreLanes);
  return;
}

/* Program__packInterpolatorEntries @ 0x1102e0 (124 bytes) */
int Program__packInterpolatorEntries(program, scopeId, vector)
  int program;
  int scopeId;
  uint *vector;
{
  uint *entryMembersVector;
  uint *entryLaneVector;
  uint *candLaneVector;
  uint *bucketMembers;
  int laneSource;
  int destOperandRec;
  int laneNumber;
  undefined4 *newEntryAlloc;
  int cloneSrcOperand;
  int headSrcOperand;
  int cloneDestOperand;
  int savedLaneWord;
  int laneInstValue;
  int entryLaneBudget;
  int candSrcOperand;
  int laneSourceInst;
  int laneStepsLeft;
  int savedSwizzle;
  int laneStep;
  undefined4 *laneKindTable;
  undefined4 *vectorSlotRef;
  undefined4 *laneListRef;
  undefined4 *groupEntryRef;
  undefined4 *bucketSlotRef;
  undefined4 *laneFlagBytePtr;
  undefined4 *recordRef;
  undefined4 *bucketVectorAlloc;
  undefined4 *groupElemRef;
  undefined4 *outVectorAlloc;
  undefined4 *allocElemRef;
  undefined4 *groupVectorAlloc;
  int laneCountTarget;
  int lanePriority;
  int groupInst;
  int headInst;
  int bucketInst;
  int defaultLaneKind;
  int candidateDestRegister;
  int matchResult;
  int laneCountdown;
  int entryDestOperand;
  int groupCursor;
  int entryInst;
  int requiredLanes;
  int bucketRegister;
  int groupSizeRemaining;
  int needsLaneFixup;
  int packingSupported;
  int laneCounter;
  int groupLimit;
  undefined1 srcSwizzleByte;
  bool isLastLane;
  bool notLastBucket;
  undefined4 entryBlock;
  undefined4 cloneDestRegister;
  undefined4 swizzleCode;
  undefined4 laneKindValue;
  uint copyCount;
  uint allocIndex;
  uint groupIndex;
  uint bucketCopyIndex;
  uint laneListIndex;
  uint otherIndex;
  uint copyIndex;
  uint groupVectorCount;
  uint bucketVectorCount;
  uint recordCount;
  uint packEntryCount;
  int *candidateWordCursor;
  int *laneRecord;
  int *newEntrySlotRef;
  int *newLaneSlotRef;
  int *entryLaneFlagCursor;
  int *candidateGroup;
  int *otherEntry;
  int *candidateEntry;
  int *laneInstRef;
  int *packEntryRef;
  int *packEntry;
  int *bucketCursor;
  int *laneSourceCursor;
  int *newSlotRef;
  int *searchRef;
  int clonedInst;
  int headLanesLeft;
  int headDestOperand;
  int candidateLaneCount;
  int laneFlagCursor;
  int candidateInst;
  int laneIndex;
  int srcOperand;
  int swappedLaneSource;
  int scanOperand;
  int vectorAt418BElement;
  int vectorAt418Element;
  int *vectorElement2;
  int *vectorElement;
  int *vectorAt418ElementRef;
  int *vectorAt418BElementRef2;
  int *vectorAt418BElementRef;
  uint vectorAt418Count;
  uint vectorCount2;
  uint vectorAt418BCount;
  uint vectorAt418BIndex3;
  uint vectorAt418Index;
  uint vectorAt418BIndex2;
  uint vectorCount;
  uint vectorIndex;
  uint vectorAt418BIndex;
  undefined4 *vectorElementRef;
  uint *vectorAt418B;
  uint *vectorAt418;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  bool notLastLane;
  undefined1 swizzleByteA;
  undefined1 swizzleByteB;
  int *savedSwizzlePtr;
  int entryLanesLeft;
  undefined4 *outRef;
  uint allocationCount;
  int recordInst;
  int operandOrSlot;
  int *laneSourceWalk;
  undefined4 *packEntryElemRef;
  undefined4 *allocRef;
  int *laneInstCursor;
  int swapEntryInst;
  int laneInst;
  int candDestOperand;
  undefined4 *copyRef;
  int *groupWordCursor;
  int headDestRegister;
  undefined1 *laneFlagPtr;
  int wordCountdown;
  int *linkRecord;
  uint *allocationVector;
  int *linkRecordRef;
  undefined4 destRegister;
  uint bucketScanIndex;
  undefined4 candDestRegister;
  undefined4 *newEntry;
  uint *groupVector;
  uint *outVector;
  uint searchRemaining;
  uint searchIndex;
  uint *bucketVector;
  int iStack0000001c;
  undefined4 savedLaneKind;
  int savedSwizzleWords [4];
  undefined1 savedLaneSources [28];
  int vec4GroupCount;
  undefined *laneKindTableBase;
  uint nextLaneListIndex;
  int *savedSwizzleWordsAlias;
  undefined *swizzleTableBase;
  undefined1 *savedLaneSourcesAlias;
  
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  iStack0000001c = scopeId;
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  vectorAt418BIndex = 0;
  vectorAt418B = *(uint **)(program + 0x418);
  vectorAt418BCount = vectorAt418B[1];
  if (vectorAt418BCount != 0) {
    do {
      if (vectorAt418BIndex < *vectorAt418B) {
        if (vectorAt418BCount <= vectorAt418BIndex) {
          _memset((void *)(vectorAt418BCount * 4 + vectorAt418B[2]),0,(vectorAt418BIndex - vectorAt418BCount) * 4 + 4);
          vectorAt418B[1] = vectorAt418BIndex + 1;
        }
        linkRecordRef = (int *)(vectorAt418BIndex * 4 + vectorAt418B[2]);
      }
      else {
        linkRecordRef = (int *)Vector__elementRefGrow(vectorAt418B,vectorAt418BIndex);
      }
      vectorAt418BIndex = vectorAt418BIndex + 1;
      linkRecordRef = (int *)*linkRecordRef;
      if (iStack0000001c == linkRecordRef[7]) {
        allocationCount = allocation[2];
        if ((int)allocationCount < 1) {
          recordInst = *linkRecordRef;
        }
        else {
          recordInst = *linkRecordRef;
          searchIndex = 0;
          searchRemaining = allocationCount;
          do {
            searchRef = (int *)0x0;
            if (searchIndex < allocationCount) {
              searchRef = (int *)(searchIndex * 4 + allocation[3]);
            }
            if (*searchRef == recordInst) goto LAB_0011047c;
            searchIndex = searchIndex + 1;
            searchRemaining = searchRemaining - 1;
          } while (searchRemaining != 0);
        }
        if (allocationCount < (uint)allocation[1]) {
          _memset((void *)(allocationCount * 4 + allocation[3]),0,4);
          newSlotRef = (int *)(allocationCount * 4 + allocation[3]);
          allocation[2] = allocationCount + 1;
        }
        else {
          newSlotRef = (int *)Vector__elementRefGrow(allocation + 1,allocationCount);
        }
        *newSlotRef = recordInst;
      }
LAB_0011047c:
      vectorAt418B = *(uint **)(program + 0x418);
      vectorAt418BCount = vectorAt418B[1];
    } while (vectorAt418BIndex < vectorAt418BCount);
  }
  allocationCount = allocation[2];
  vec4GroupCount = ((int)allocationCount >> 2) + (uint)((int)allocationCount < 0 && (allocationCount & 3) != 0);
  *(uint *)(program + 0x428) = allocationCount;
  if ((allocationCount & 3) != 0) {
    vec4GroupCount = vec4GroupCount + 1;
  }
  groupLimit = ((int (*)())Program__countUsedInterpolatorSlots)(iStack0000001c,vectorAt418B,*(undefined4 *)(program + 8));
  if (vec4GroupCount < groupLimit) {
    packEntryCount = vector[1];
    vectorIndex = 0;
    if (packEntryCount == 0) {
      packEntryCount = 0;
    }
    else {
      do {
        if (vectorIndex < *vector) {
          if (packEntryCount <= vectorIndex) {
            _memset((void *)(packEntryCount * 4 + vector[2]),0,(vectorIndex - packEntryCount) * 4 + 4);
            vector[1] = vectorIndex + 1;
          }
          vectorElementRef = (undefined4 *)(vectorIndex * 4 + vector[2]);
        }
        else {
          vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorIndex);
        }
        vectorIndex = vectorIndex + 1;
        DList__unlink(*(undefined4 *)*vectorElementRef);
        packEntryCount = vector[1];
      } while (vectorIndex < packEntryCount);
    }
    if (packEntryCount != 0) {
      vectorIndex = 0;
      do {
        if (vectorIndex < *vector) {
          if (packEntryCount <= vectorIndex) {
            _memset((void *)(packEntryCount * 4 + vector[2]),0,(vectorIndex - packEntryCount) * 4 + 4);
            vector[1] = vectorIndex + 1;
          }
          vectorElementRef = (undefined4 *)(vectorIndex * 4 + vector[2]);
        }
        else {
          vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorIndex);
        }
        vectorIndex = vectorIndex + 1;
        vectorElement = (int *)*vectorElementRef;
        laneCounter = 0;
        laneSourceCursor = vectorElement;
        do {
          operandOrSlot = IRInst__getOperandRecord(*vectorElement,0);
          if ((*(char *)(laneCounter + operandOrSlot + 0x10) != '\x01') &&
             (operandOrSlot = Array__firstIndexOfEntry(vectorElement,laneCounter), -1 < operandOrSlot)) {
            entryLanesLeft = vectorElement[5];
            laneSourceCursor[1] = 0;
            vectorElement[5] = entryLanesLeft + -1;
            vectorAt418B = *(uint **)(program + 0x418);
            vectorAt418BCount = vectorAt418B[1];
            if (vectorAt418BCount != 0) {
              vectorAt418BIndex2 = 0;
              do {
                if (vectorAt418BIndex2 < *vectorAt418B) {
                  if (vectorAt418BCount <= vectorAt418BIndex2) {
                    _memset((void *)(vectorAt418BCount * 4 + vectorAt418B[2]),0,(vectorAt418BIndex2 - vectorAt418BCount) * 4 + 4);
                    vectorAt418B[1] = vectorAt418BIndex2 + 1;
                  }
                  vectorAt418BElementRef = (int *)(vectorAt418BIndex2 * 4 + vectorAt418B[2]);
                }
                else {
                  vectorAt418BElementRef = (int *)Vector__elementRefGrow(vectorAt418B,vectorAt418BIndex2);
                }
                vectorAt418BElement = *vectorAt418BElementRef;
                if (((iStack0000001c == *(int *)(vectorAt418BElement + 0x1c)) && (*(int *)(vectorAt418BElement + 0x10) == laneCounter)
                    ) && (*(int *)(vectorAt418BElement + 0xc) == *(int *)(*vectorElement + 0x94))) {
                  *(int *)(vectorAt418BElement + 0x18) = operandOrSlot;
                  break;
                }
                vectorAt418B = *(uint **)(program + 0x418);
                vectorAt418BIndex2 = vectorAt418BIndex2 + 1;
                vectorAt418BCount = vectorAt418B[1];
              } while (vectorAt418BIndex2 < vectorAt418BCount);
            }
            *(undefined1 *)(laneCounter + *vectorElement + 0x9c) = 1;
          }
          notLastLane = laneCounter != 3;
          laneSourceCursor = laneSourceCursor + 1;
          laneCounter = laneCounter + 1;
        } while (notLastLane);
        packEntryCount = vector[1];
      } while (vectorIndex < packEntryCount);
    }
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported == 0) {
      packEntryCount = vector[1];
      vectorIndex = 0;
      if (packEntryCount == 0) {
        packEntryCount = 0;
      }
      else {
        do {
          if (vectorIndex < *vector) {
            if (packEntryCount <= vectorIndex) {
              _memset((void *)(packEntryCount * 4 + vector[2]),0,(vectorIndex - packEntryCount) * 4 + 4);
              vector[1] = vectorIndex + 1;
            }
            vectorElementRef = (undefined4 *)(vectorIndex * 4 + vector[2]);
          }
          else {
            vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorIndex);
          }
          vectorIndex = vectorIndex + 1;
          vectorElement2 = (int *)*vectorElementRef;
          needsLaneFixup = IRInst__destMaskHasGap(*vectorElement2);
          if (needsLaneFixup != 0) {
            laneCounter = 0;
            do {
              entryDestOperand = IRInst__getOperandRecord(*vectorElement2,0);
              if ((*(char *)(laneCounter + entryDestOperand + 0x10) == '\x01') && (entryDestOperand = laneCounter + 1, entryDestOperand < 4)) {
                do {
                  scanOperand = IRInst__getOperandRecord(*vectorElement2,0);
                  if (*(char *)(entryDestOperand + scanOperand + 0x10) == '\0') {
                    swapEntryInst = *vectorElement2;
                    swappedLaneSource = vectorElement2[laneCounter + 1];
                    vectorElement2[laneCounter + 1] = vectorElement2[entryDestOperand + 1];
                    vectorElement2[entryDestOperand + 1] = swappedLaneSource;
                    *(undefined1 *)(laneCounter + swapEntryInst + 0x9c) = 0;
                    *(undefined1 *)(entryDestOperand + *vectorElement2 + 0x9c) = 1;
                    srcOperand = IRInst__getOperandRecord(*vectorElement2,1);
                    swizzleByteB = *(undefined1 *)(entryDestOperand + srcOperand + 0x10);
                    srcOperand = IRInst__getOperandRecord(*vectorElement2,1);
                    swizzleByteA = *(undefined1 *)(laneCounter + srcOperand + 0x10);
                    (**(code **)(*(int *)*vectorElement2 + 0x88))((int *)*vectorElement2,1,laneCounter,swizzleByteB);
                    (**(code **)(*(int *)*vectorElement2 + 0x88))((int *)*vectorElement2,1,entryDestOperand,swizzleByteA);
                    break;
                  }
                  notLastLane = entryDestOperand != 3;
                  entryDestOperand = entryDestOperand + 1;
                } while (notLastLane);
              }
              laneCounter = laneCounter + 1;
            } while (laneCounter < 4);
            vectorAt418B = *(uint **)(program + 0x418);
            vectorAt418BIndex2 = 0;
            vectorAt418BCount = vectorAt418B[1];
            if (vectorAt418BCount != 0) {
              do {
                if (vectorAt418BIndex2 < *vectorAt418B) {
                  if (vectorAt418BCount <= vectorAt418BIndex2) {
                    _memset((void *)(vectorAt418BCount * 4 + vectorAt418B[2]),0,(vectorAt418BIndex2 - vectorAt418BCount) * 4 + 4);
                    vectorAt418B[1] = vectorAt418BIndex2 + 1;
                  }
                  linkRecord = (int *)(vectorAt418BIndex2 * 4 + vectorAt418B[2]);
                }
                else {
                  linkRecord = (int *)Vector__elementRefGrow(vectorAt418B,vectorAt418BIndex2);
                }
                vectorAt418BIndex2 = vectorAt418BIndex2 + 1;
                linkRecord = (int *)*linkRecord;
                if ((iStack0000001c == linkRecord[7]) && (linkRecord[3] == *(int *)(*vectorElement2 + 0x94))) {
                  laneCountdown = 4;
                  laneCounter = 0;
                  laneSourceWalk = vectorElement2;
                  do {
                    if (*linkRecord == laneSourceWalk[1]) {
                      linkRecord[6] = laneCounter;
                      break;
                    }
                    laneCounter = laneCounter + 1;
                    laneSourceWalk = laneSourceWalk + 1;
                    laneCountdown = laneCountdown + -1;
                  } while (laneCountdown != 0);
                }
                vectorAt418B = *(uint **)(program + 0x418);
                vectorAt418BCount = vectorAt418B[1];
              } while (vectorAt418BIndex2 < vectorAt418BCount);
            }
          }
          packEntryCount = vector[1];
        } while (vectorIndex < packEntryCount);
      }
      groupSizeRemaining = 4;
      do {
        if (0 < (int)packEntryCount) {
          vectorIndex = 0;
          do {
            if (vectorIndex < *vector) {
              if (packEntryCount <= vectorIndex) {
                _memset((void *)(packEntryCount * 4 + vector[2]),0,(vectorIndex - packEntryCount) * 4 + 4);
                vector[1] = vectorIndex + 1;
                packEntryCount = vectorIndex + 1;
              }
              vectorElementRef = (undefined4 *)(vectorIndex * 4 + vector[2]);
            }
            else {
              vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorIndex);
              packEntryCount = vector[1];
            }
            vectorIndex = vectorIndex + 1;
            vectorElement2 = (int *)*vectorElementRef;
            if ((groupSizeRemaining == vectorElement2[5]) && (otherIndex = 0, 0 < (int)packEntryCount)) {
              do {
                if (otherIndex < *vector) {
                  if (packEntryCount <= otherIndex) {
                    _memset((void *)(packEntryCount * 4 + vector[2]),0,(otherIndex - packEntryCount) * 4 + 4);
                    vector[1] = otherIndex + 1;
                  }
                  vectorElementRef = (undefined4 *)(otherIndex * 4 + vector[2]);
                }
                else {
                  vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,otherIndex);
                }
                vectorElement = (int *)*vectorElementRef;
                matchResult = PackEntry__computeLaneMap(vectorElement,vectorElement2,savedSwizzleWords);
                if (matchResult != 0) {
                  vectorAt418B = *(uint **)(program + 0x418);
                  vectorAt418BCount = vectorAt418B[1];
                  candidateDestRegister = *(int *)(*vectorElement + 0x94);
                  destRegister = *(undefined4 *)(*vectorElement2 + 0x94);
                  if (0 < (int)vectorAt418BCount) {
                    vectorAt418BIndex3 = 0;
                    do {
                      if (vectorAt418BIndex3 < *vectorAt418B) {
                        if (vectorAt418BCount <= vectorAt418BIndex3) {
                          _memset((void *)(vectorAt418BCount * 4 + vectorAt418B[2]),0,(vectorAt418BIndex3 - vectorAt418BCount) * 4 + 4);
                          vectorAt418B[1] = vectorAt418BIndex3 + 1;
                        }
                        vectorAt418BElementRef = (int *)(vectorAt418BIndex3 * 4 + vectorAt418B[2]);
                      }
                      else {
                        vectorAt418BElementRef = (int *)Vector__elementRefGrow(vectorAt418B,vectorAt418BIndex3);
                      }
                      vectorAt418BIndex3 = vectorAt418BIndex3 + 1;
                      vectorAt418BElement = *vectorAt418BElementRef;
                      if (((iStack0000001c == *(int *)(vectorAt418BElement + 0x1c)) &&
                          (candidateDestRegister == *(int *)(vectorAt418BElement + 0x14))) &&
                         (savedSwizzleWords[*(int *)(vectorAt418BElement + 0x18)] != -1)) {
                        *(int *)(vectorAt418BElement + 0x18) = savedSwizzleWords[*(int *)(vectorAt418BElement + 0x18)];
                        *(undefined4 *)(vectorAt418BElement + 0x14) = destRegister;
                      }
                      vectorAt418B = *(uint **)(program + 0x418);
                      vectorAt418BCount = vectorAt418B[1];
                    } while ((int)vectorAt418BIndex3 < (int)vectorAt418BCount);
                  }
                  Vector__removeValue(vector,vectorElement);
                  otherIndex = otherIndex - 1;
                  Program__removeInst(program,*vectorElement);
                  *(int *)(program + 0x230) = *(int *)(program + 0x230) + 1;
                }
                packEntryCount = vector[1];
                otherIndex = otherIndex + 1;
              } while ((int)otherIndex < (int)packEntryCount);
            }
          } while ((int)vectorIndex < (int)packEntryCount);
        }
        groupSizeRemaining = groupSizeRemaining + -1;
      } while (groupSizeRemaining != 0);
    }
    outVector = (uint *)0x0;
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported != 0) {
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      outVector = allocation + 1;
      allocation[1] = 2;
      *allocation = arena;
      allocation[2] = 0;
      allocation[4] = arena;
      vectorData = Arena__alloc(arena,8);
      vectorCount2 = vector[1];
      groupSizeRemaining = 4;
      allocation[3] = vectorData;
      do {
        if (vectorCount2 == 0) break;
        if (0 < (int)vectorCount2) {
          vectorIndex = 0;
          do {
            if (vectorIndex < *vector) {
              if (vectorCount2 <= vectorIndex) {
                _memset((void *)(vectorCount2 * 4 + vector[2]),0,(vectorIndex - vectorCount2) * 4 + 4);
                vector[1] = vectorIndex + 1;
              }
              packEntryElemRef = (undefined4 *)(vectorIndex * 4 + vector[2]);
            }
            else {
              packEntryElemRef = (undefined4 *)Vector__elementRefGrow(vector,vectorIndex);
            }
            packEntryElemRef = (undefined4 *)*packEntryElemRef;
            if (packEntryElemRef[5] == 0) {
              Vector__removeValue(vector,packEntryElemRef);
              vectorIndex = vectorIndex - 1;
              Program__removeInst(program,*packEntryElemRef);
              *(int *)(program + 0x230) = *(int *)(program + 0x230) + 1;
              IRInst__getOperandRecord(*packEntryElemRef,0);
            }
            else if (packEntryElemRef[5] == groupSizeRemaining) {
              Vector__removeValue(vector,packEntryElemRef);
              PackEntry__lanesFitVector(packEntryElemRef,vector);
              ((int (*)())PackEntry__bindToVectorRegister)(packEntryElemRef,*(undefined4 *)(program + 0x418));
              allocationCount = allocation[2];
              if (allocationCount < *outVector) {
                _memset((void *)(allocationCount * 4 + allocation[3]),0,4);
                allocRef = (undefined4 *)(allocationCount * 4 + allocation[3]);
                allocation[2] = allocationCount + 1;
              }
              else {
                allocRef = (undefined4 *)Vector__elementRefGrow(outVector,allocationCount);
              }
              *allocRef = packEntryElemRef;
              vectorIndex = vectorIndex - 1;
            }
            vectorCount2 = vector[1];
            vectorIndex = vectorIndex + 1;
          } while ((int)vectorIndex < (int)vectorCount2);
        }
        groupSizeRemaining = groupSizeRemaining + -1;
      } while (groupSizeRemaining != 0);
    }
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported == 0) {
      outVector = vector;
    }
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    allocationVector = allocation + 1;
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    groupVectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
    groupVector = groupVectorAlloc + 1;
    *groupVectorAlloc = arena;
    groupVectorAlloc[1] = 2;
    groupVectorAlloc[2] = 0;
    groupVectorAlloc[4] = arena;
    vectorData = Arena__alloc(arena,8);
    groupVectorAlloc[3] = vectorData;
    laneCounter = 0;
    bucketCursor = &DAT_001fc1f0;
    laneKindTableBase = &DAT_001b02ec;
    do {
      bucketCursor[2] = 4;
      defaultLaneKind = *(int *)(laneKindTableBase + -0x8d8);
      *bucketCursor = laneCounter;
      bucketCursor[1] = defaultLaneKind;
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      bucketVectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
      bucketVectorAlloc[1] = 2;
      *bucketVectorAlloc = arena;
      bucketVectorAlloc[2] = 0;
      bucketVectorAlloc[4] = arena;
      vectorData = Arena__alloc(arena,8);
      notLastBucket = laneCounter != 0xb;
      bucketVectorAlloc[3] = vectorData;
      laneCounter = laneCounter + 1;
      bucketCursor[3] = (int)(bucketVectorAlloc + 1);
      bucketCursor = bucketCursor + 4;
    } while (notLastBucket);
    recordCount = outVector[1];
    if (0 < (int)recordCount) {
      bucketScanIndex = 0;
      do {
        if (bucketScanIndex < *outVector) {
          if (recordCount <= bucketScanIndex) {
            _memset((void *)(recordCount * 4 + outVector[2]),0,(bucketScanIndex - recordCount) * 4 + 4);
            outVector[1] = bucketScanIndex + 1;
          }
          recordRef = (undefined4 *)(bucketScanIndex * 4 + outVector[2]);
        }
        else {
          recordRef = (undefined4 *)Vector__elementRefGrow(outVector,bucketScanIndex);
        }
        bucketScanIndex = bucketScanIndex + 1;
        packEntry = (int *)*recordRef;
        laneIndex = 0;
        bucketInst = *packEntry;
        bucketRegister = *(int *)(bucketInst + 0x94);
        laneFlagBytePtr = &DAT_001fc1f4 + bucketRegister * 4;
        while( true ) {
          bucketInst = IRInst__getOperandRecord(bucketInst,0);
          if (*(char *)(laneIndex + bucketInst + 0x10) != '\x01') {
            *(undefined1 *)laneFlagBytePtr = 0;
            (DAT_001fc1f8)[bucketRegister * 4] = (DAT_001fc1f8)[bucketRegister * 4] + -1;
          }
          isLastLane = laneIndex == 3;
          laneFlagBytePtr = (undefined4 *)((int)laneFlagBytePtr + 1);
          laneIndex = laneIndex + 1;
          if (isLastLane) break;
          bucketInst = *packEntry;
        }
        bucketVector = (uint *)(DAT_001fc1fc)[bucketRegister * 4];
        bucketVectorCount = bucketVector[1];
        if (bucketVectorCount < *bucketVector) {
          _memset((void *)(bucketVectorCount * 4 + bucketVector[2]),0,4);
          bucketSlotRef = (undefined4 *)(bucketVectorCount * 4 + bucketVector[2]);
          bucketVector[1] = bucketVectorCount + 1;
        }
        else {
          bucketSlotRef = (undefined4 *)Vector__elementRefGrow(bucketVector,bucketVectorCount);
        }
        *bucketSlotRef = packEntry;
        recordCount = outVector[1];
      } while ((int)bucketScanIndex < (int)recordCount);
    }
    laneCounter = 0;
    bucketCursor = DAT_001fc1f8;
    do {
      if (*bucketCursor == 0) {
        bucketMembers = (uint *)bucketCursor[1];
        recordCount = bucketMembers[1];
        if (0 < (int)recordCount) {
          bucketCopyIndex = 0;
          do {
            if (bucketCopyIndex < *bucketMembers) {
              if (recordCount <= bucketCopyIndex) {
                _memset((void *)(recordCount * 4 + bucketMembers[2]),0,(bucketCopyIndex - recordCount) * 4 + 4);
                bucketMembers[1] = bucketCopyIndex + 1;
              }
              recordRef = (undefined4 *)(bucketCopyIndex * 4 + bucketMembers[2]);
            }
            else {
              recordRef = (undefined4 *)Vector__elementRefGrow(bucketMembers,bucketCopyIndex);
            }
            bucketCopyIndex = bucketCopyIndex + 1;
            allocationCount = allocation[2];
            if (allocationCount < *allocationVector) {
              _memset((void *)(allocationCount * 4 + allocation[3]),0,4);
              copyRef = (undefined4 *)(allocationCount * 4 + allocation[3]);
              allocation[2] = allocationCount + 1;
            }
            else {
              copyRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocationCount);
            }
            *copyRef = *recordRef;
            bucketMembers = (uint *)bucketCursor[1];
            recordCount = bucketMembers[1];
          } while ((int)bucketCopyIndex < (int)recordCount);
        }
      }
      else if (*bucketCursor < 4) {
        groupVectorCount = groupVectorAlloc[2];
        if (groupVectorCount < *groupVector) {
          _memset((void *)(groupVectorCount * 4 + groupVectorAlloc[3]),0,4);
          bucketSlotRef = (undefined4 *)(groupVectorCount * 4 + groupVectorAlloc[3]);
          groupVectorAlloc[2] = groupVectorCount + 1;
        }
        else {
          bucketSlotRef = (undefined4 *)Vector__elementRefGrow(groupVector,groupVectorCount);
        }
        *bucketSlotRef = &DAT_001fc1f0 + laneCounter * 4;
      }
      notLastBucket = laneCounter != 0xb;
      bucketCursor = bucketCursor + 4;
      laneCounter = laneCounter + 1;
    } while (notLastBucket);
    savedLaneSourcesAlias = savedLaneSources;
    groupVectorCount = groupVectorAlloc[2];
    requiredLanes = 1;
    swizzleTableBase = &DAT_001b02ec;
    do {
      if (0 < (int)groupVectorCount) {
        savedSwizzleWordsAlias = savedSwizzleWords;
        groupIndex = 0;
        do {
          if (groupIndex < *groupVector) {
            if (groupVectorCount <= groupIndex) {
              _memset((void *)(groupVectorCount * 4 + groupVectorAlloc[3]),0,(groupIndex - groupVectorCount) * 4 + 4);
              groupVectorCount = groupIndex + 1;
              groupVectorAlloc[2] = groupVectorCount;
            }
            groupEntryRef = (undefined4 *)(groupIndex * 4 + groupVectorAlloc[3]);
          }
          else {
            groupEntryRef = (undefined4 *)Vector__elementRefGrow(groupVector,groupIndex);
            groupVectorCount = groupVectorAlloc[2];
          }
          packEntry = (int *)*groupEntryRef;
          headInst = *packEntry;
          if ((requiredLanes == packEntry[2]) && (otherIndex = 0, 0 < (int)groupVectorCount)) {
LAB_00111270:
            if (otherIndex < *groupVector) {
              if (groupVectorCount <= otherIndex) {
                _memset((void *)(groupVectorCount * 4 + groupVectorAlloc[3]),0,(otherIndex - groupVectorCount) * 4 + 4);
                groupVectorAlloc[2] = otherIndex + 1;
              }
              groupEntryRef = (undefined4 *)(otherIndex * 4 + groupVectorAlloc[3]);
            }
            else {
              groupEntryRef = (undefined4 *)Vector__elementRefGrow(groupVector,otherIndex);
            }
            otherEntry = (int *)*groupEntryRef;
            candidateInst = *otherEntry;
            if ((candidateInst == headInst) || (requiredLanes < 4 - otherEntry[2])) goto LAB_001116e0;
            Vector__removeValue(groupVector,otherEntry);
            candLaneVector = (uint *)otherEntry[3];
            recordCount = candLaneVector[1];
            if (0 < (int)recordCount) {
              laneListIndex = 0;
              do {
                if (laneListIndex < *candLaneVector) {
                  nextLaneListIndex = laneListIndex + 1;
                  if (recordCount <= laneListIndex) {
                    _memset((void *)(recordCount * 4 + candLaneVector[2]),0,(laneListIndex - recordCount) * 4 + 4);
                    candLaneVector[1] = nextLaneListIndex;
                  }
                  laneRecord = (int *)(laneListIndex * 4 + candLaneVector[2]);
                }
                else {
                  laneRecord = (int *)Vector__elementRefGrow(candLaneVector,laneListIndex);
                  nextLaneListIndex = laneListIndex + 1;
                }
                wordCountdown = 4;
                laneRecord = (int *)*laneRecord;
                savedLaneKind = *(undefined4 *)(laneKindTableBase + -0x8d8);
                savedSwizzleWords[0] = *(int *)(swizzleTableBase + -0x8dc);
                laneStep = 0;
                laneInst = *laneRecord;
                groupWordCursor = laneRecord;
                do {
                  *(undefined4 *)(savedLaneSourcesAlias + laneStep) = 0;
                  laneStep = laneStep + 4;
                  groupWordCursor[7] = 0;
                  groupWordCursor = groupWordCursor + 1;
                  wordCountdown = wordCountdown + -1;
                } while (wordCountdown != 0);
                laneStep = 0;
                entryLaneFlagCursor = packEntry + 1;
                do {
                  if (*(char *)entryLaneFlagCursor == '\x01') {
                    laneNumber = 0;
                    laneFlagPtr = (undefined1 *)(laneInst + 0x9c);
                    laneInstCursor = laneRecord;
LAB_001113e0:
                    laneInstCursor = laneInstCursor + 1;
                    candDestOperand = IRInst__getOperandRecord(laneInst,0);
                    if (*(char *)(laneNumber + candDestOperand + 0x10) == '\x01') goto LAB_00111508;
                    candSrcOperand = IRInst__getOperandRecord(laneInst,1);
                    savedSwizzlePtr = savedSwizzleWordsAlias;
                    srcSwizzleByte = *(undefined1 *)(laneNumber + candSrcOperand + 0x10);
                    *(undefined1 *)((int)savedSwizzleWords + laneStep + -4) = 0;
                    *(undefined1 *)(laneStep + (int)savedSwizzlePtr) = srcSwizzleByte;
                    entryLaneBudget = packEntry[2];
                    *(char *)entryLaneFlagCursor = '\0';
                    packEntry[2] = entryLaneBudget + -1;
                    vectorAt418B = *(uint **)(program + 0x418);
                    *(int *)(savedLaneSourcesAlias + laneStep * 4) = *laneInstCursor;
                    vectorAt418BCount = vectorAt418B[1];
                    if (0 < (int)vectorAt418BCount) {
                      vectorAt418BIndex2 = 0;
                      do {
                        if (vectorAt418BIndex2 < *vectorAt418B) {
                          if (vectorAt418BCount <= vectorAt418BIndex2) {
                            _memset((void *)(vectorAt418BCount * 4 + vectorAt418B[2]),0,(vectorAt418BIndex2 - vectorAt418BCount) * 4 + 4);
                            vectorAt418B[1] = vectorAt418BIndex2 + 1;
                          }
                          vectorAt418BElementRef2 = (int *)(vectorAt418BIndex2 * 4 + vectorAt418B[2]);
                        }
                        else {
                          vectorAt418BElementRef2 = (int *)Vector__elementRefGrow(vectorAt418B,vectorAt418BIndex2);
                        }
                        vectorAt418BIndex2 = vectorAt418BIndex2 + 1;
                        laneInstValue = *vectorAt418BElementRef2;
                        if (((iStack0000001c == *(int *)(laneInstValue + 0x1c)) &&
                            (candidateInst == *(int *)(laneInstValue + 0x14))) &&
                           (laneNumber == *(int *)(laneInstValue + 0x18))) {
                          *(int *)(laneInstValue + 0x18) = laneStep;
                          *(int *)(laneInstValue + 0x14) = headInst;
                        }
                        vectorAt418B = *(uint **)(program + 0x418);
                        vectorAt418BCount = vectorAt418B[1];
                      } while ((int)vectorAt418BIndex2 < (int)vectorAt418BCount);
                    }
                    *laneFlagPtr = 1;
                  }
LAB_0011151c:
                  notLastLane = laneStep != 3;
                  entryLaneFlagCursor = (int *)((int)entryLaneFlagCursor + 1);
                  laneStep = laneStep + 1;
                } while (notLastLane);
                wordCountdown = 4;
                laneStep = 0;
                groupWordCursor = laneRecord;
                do {
                  savedLaneWord = *(int *)(savedLaneSourcesAlias + laneStep);
                  laneStep = laneStep + 4;
                  groupWordCursor[7] = 1;
                  groupWordCursor[1] = savedLaneWord;
                  groupWordCursor = groupWordCursor + 1;
                  wordCountdown = wordCountdown + -1;
                } while (wordCountdown != 0);
                destOperandRec = IRInst__getOperandRecord(laneInst,0);
                savedSwizzle = savedSwizzleWords[0];
                *(int *)(destOperandRec + 8) = headInst;
                *(undefined4 *)(laneInst + 0x9c) = savedLaneKind;
                laneInst = IRInst__getOperandRecord(laneInst,1);
                *(int *)(laneInst + 0x10) = savedSwizzle;
                entryLaneVector = (uint *)packEntry[3];
                recordCount = entryLaneVector[1];
                if (recordCount < *entryLaneVector) {
                  _memset((void *)(recordCount * 4 + entryLaneVector[2]),0,4);
                  newLaneSlotRef = (int *)(recordCount * 4 + entryLaneVector[2]);
                  entryLaneVector[1] = recordCount + 1;
                }
                else {
                  newLaneSlotRef = (int *)Vector__elementRefGrow(entryLaneVector,recordCount);
                }
                *newLaneSlotRef = (int)laneRecord;
                candLaneVector = (uint *)otherEntry[3];
                recordCount = candLaneVector[1];
                laneListIndex = nextLaneListIndex;
              } while ((int)nextLaneListIndex < (int)recordCount);
            }
            if (packEntry[2] < 1) {
              entryLaneVector = (uint *)packEntry[3];
              laneListIndex = 0;
              recordCount = entryLaneVector[1];
              if (0 < (int)recordCount) {
                do {
                  if (laneListIndex < *entryLaneVector) {
                    if (recordCount <= laneListIndex) {
                      _memset((void *)(recordCount * 4 + entryLaneVector[2]),0,(laneListIndex - recordCount) * 4 + 4);
                      entryLaneVector[1] = laneListIndex + 1;
                    }
                    laneListRef = (undefined4 *)(laneListIndex * 4 + entryLaneVector[2]);
                  }
                  else {
                    laneListRef = (undefined4 *)Vector__elementRefGrow(entryLaneVector,laneListIndex);
                  }
                  laneListIndex = laneListIndex + 1;
                  allocationCount = allocation[2];
                  if (allocationCount < *allocationVector) {
                    _memset((void *)(allocationCount * 4 + allocation[3]),0,4);
                    copyRef = (undefined4 *)(allocationCount * 4 + allocation[3]);
                    allocation[2] = allocationCount + 1;
                  }
                  else {
                    copyRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocationCount);
                  }
                  *copyRef = *laneListRef;
                  entryLaneVector = (uint *)packEntry[3];
                  recordCount = entryLaneVector[1];
                } while ((int)laneListIndex < (int)recordCount);
              }
              Vector__removeValue(groupVector,packEntry);
              groupVectorCount = groupVectorAlloc[2];
            }
            else {
              groupVectorCount = groupVectorAlloc[2];
              requiredLanes = packEntry[2] + -1;
              groupIndex = 1;
            }
            goto LAB_001116f4;
          }
LAB_001116f0:
          groupIndex = groupIndex + 1;
LAB_001116f4: ;
        } while ((int)groupIndex < (int)groupVectorCount);
      }
      requiredLanes = requiredLanes + 1;
    } while (requiredLanes < 4);
    groupIndex = 0;
    if (0 < (int)groupVectorCount) {
      do {
        if (groupIndex < *groupVector) {
          if (groupVectorCount <= groupIndex) {
            _memset((void *)(groupVectorCount * 4 + groupVectorAlloc[3]),0,(groupIndex - groupVectorCount) * 4 + 4);
            groupVectorAlloc[2] = groupIndex + 1;
          }
          packEntryRef = (int *)(groupIndex * 4 + groupVectorAlloc[3]);
        }
        else {
          packEntryRef = (int *)Vector__elementRefGrow(groupVector,groupIndex);
        }
        groupIndex = groupIndex + 1;
        entryInst = *packEntryRef;
        entryMembersVector = *(uint **)(entryInst + 0xc);
        recordCount = entryMembersVector[1];
        if (0 < (int)recordCount) {
          laneListIndex = 0;
          do {
            if (laneListIndex < *entryMembersVector) {
              if (recordCount <= laneListIndex) {
                _memset((void *)(recordCount * 4 + entryMembersVector[2]),0,(laneListIndex - recordCount) * 4 + 4);
                entryMembersVector[1] = laneListIndex + 1;
              }
              laneInstRef = (int *)(laneListIndex * 4 + entryMembersVector[2]);
            }
            else {
              laneInstRef = (int *)Vector__elementRefGrow(entryMembersVector,laneListIndex);
            }
            laneListIndex = laneListIndex + 1;
            allocationCount = allocation[2];
            groupInst = *laneInstRef;
            if (allocationCount < *allocationVector) {
              _memset((void *)(allocationCount * 4 + allocation[3]),0,4);
              newSlotRef = (int *)(allocationCount * 4 + allocation[3]);
              allocation[2] = allocationCount + 1;
            }
            else {
              newSlotRef = (int *)Vector__elementRefGrow(allocationVector,allocationCount);
            }
            *newSlotRef = groupInst;
            laneStepsLeft = 4;
            laneFlagCursor = entryInst;
            do {
              if (*(char *)(laneFlagCursor + 4) == '\0') {
                *(undefined4 *)(groupInst + 0x1c) = 1;
              }
              laneFlagCursor = laneFlagCursor + 1;
              groupInst = groupInst + 4;
              laneStepsLeft = laneStepsLeft + -1;
            } while (laneStepsLeft != 0);
            entryMembersVector = *(uint **)(entryInst + 0xc);
            recordCount = entryMembersVector[1];
          } while ((int)laneListIndex < (int)recordCount);
        }
        groupVectorCount = groupVectorAlloc[2];
      } while ((int)groupIndex < (int)groupVectorCount);
    }
    allocationCount = allocation[2];
    if (0 < (int)allocationCount) {
      groupIndex = 0;
      do {
        if (groupIndex < *allocationVector) {
          if (allocationCount <= groupIndex) {
            _memset((void *)(allocationCount * 4 + allocation[3]),0,(groupIndex - allocationCount) * 4 + 4);
            allocation[2] = groupIndex + 1;
          }
          allocElemRef = (undefined4 *)(groupIndex * 4 + allocation[3]);
        }
        else {
          allocElemRef = (undefined4 *)Vector__elementRefGrow(allocationVector,groupIndex);
        }
        groupIndex = groupIndex + 1;
        allocElemRef = (undefined4 *)*allocElemRef;
        laneCounter = 0;
        do {
          IRLoadInterp__setLaneKindAndIndex(*allocElemRef,laneCounter,0,0);
          notLastLane = laneCounter != 3;
          laneCounter = laneCounter + 1;
        } while (notLastLane);
        allocationCount = allocation[2];
      } while ((int)groupIndex < (int)allocationCount);
    }
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported == 0) {
      allocationCount = allocation[2];
      outVector = (uint *)0x0;
    }
    else {
      arena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      outVectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
      outVector = outVectorAlloc + 1;
      *outVectorAlloc = arena;
      outVectorAlloc[1] = 2;
      outVectorAlloc[2] = 0;
      outVectorAlloc[4] = arena;
      vectorData = Arena__alloc(arena,8);
      outVectorAlloc[3] = vectorData;
      groupCursor = ((int (*)())Program__countUsedInterpolatorSlots)(iStack0000001c,*(undefined4 *)(program + 0x418),
                           *(undefined4 *)(program + 8));
      if (vec4GroupCount < groupCursor) {
        allocationCount = allocation[2];
        do {
          lanePriority = 1;
          candidateEntry = (int *)0x0;
          do {
            allocIndex = 0;
            if (0 < (int)allocationCount) {
              do {
                if (allocIndex < *allocationVector) {
                  if (allocationCount <= allocIndex) {
                    _memset((void *)(allocationCount * 4 + allocation[3]),0,(allocIndex - allocationCount) * 4 + 4);
                    allocation[2] = allocIndex + 1;
                  }
                  allocRef = (undefined4 *)(allocIndex * 4 + allocation[3]);
                }
                else {
                  allocRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocIndex);
                }
                candidateEntry = (int *)*allocRef;
                if (candidateEntry[5] == lanePriority) {
                  Vector__removeValue(allocationVector,candidateEntry);
                  Program__removeInst(program,*candidateEntry);
                  *(int *)(program + 0x230) = *(int *)(program + 0x230) + 1;
                  allocationCount = allocation[2];
                  goto code_r0x00111aa4;
                }
                allocationCount = allocation[2];
                allocIndex = allocIndex + 1;
              } while ((int)allocIndex < (int)allocationCount);
            }
            lanePriority = lanePriority + 1;
          } while (lanePriority < 5);
code_r0x00111aa4:
          laneCountTarget = 3;
          do {
            if (0 < (int)allocationCount) {
              allocIndex = 0;
              do {
                if (allocIndex < *allocationVector) {
                  if (allocationCount <= allocIndex) {
                    _memset((void *)(allocationCount * 4 + allocation[3]),0,(allocIndex - allocationCount) * 4 + 4);
                    allocation[2] = allocIndex + 1;
                  }
                  allocRef = (undefined4 *)(allocIndex * 4 + allocation[3]);
                }
                else {
                  allocRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocIndex);
                }
                candidateGroup = (int *)*allocRef;
                candidateLaneCount = PackEntry__activeLaneCount(candidateGroup);
                if (laneCountTarget == candidateLaneCount) {
                  laneIndex = 0;
                  laneKindTable = (undefined4 *)PTR_DAT_001e8b64;
                  candidateWordCursor = candidateGroup;
                  do {
                    laneSourceInst = PackEntry__laneNeedsZero(candidateGroup,laneIndex);
                    if (laneSourceInst != 0) {
                      laneStep = 0;
                      do {
                        headDestOperand = IRInst__getOperandRecord(*candidateEntry,0);
                        if (*(char *)(laneStep + headDestOperand + 0x10) != '\x01') {
                          laneSource = candidateEntry[laneStep + 1];
                          *(undefined1 *)(laneStep + *candidateEntry + 0x9c) = 1;
                          headLanesLeft = candidateEntry[5];
                          candidateEntry[laneStep + 1] = 0;
                          candidateEntry[5] = headLanesLeft + -1;
                          goto code_r0x00111b80;
                        }
                        notLastLane = laneStep != 3;
                        laneStep = laneStep + 1;
                      } while (notLastLane);
                      laneStep = -1;
                      laneSource = 0;
code_r0x00111b80:
                      headDestRegister = *(int *)(*candidateEntry + 0x94);
                      clonedInst = IRInst__clone(*candidateEntry,*(undefined4 *)(program + 8),0);
                      candDestRegister = *(undefined4 *)(*candidateGroup + 0x94);
                      cloneDestOperand = IRInst__getOperandRecord(clonedInst,0);
                      laneKindValue = *laneKindTable;
                      *(undefined4 *)(cloneDestOperand + 8) = candDestRegister;
                      *(undefined4 *)(clonedInst + 0x9c) = laneKindValue;
                      headSrcOperand = IRInst__getOperandRecord(*candidateEntry,1);
                      swizzleCode = *(undefined4 *)
                                (PTR_DAT_001e8b8c + (uint)*(byte *)(laneStep + headSrcOperand + 0x10) * 4);
                      cloneSrcOperand = IRInst__getOperandRecord(clonedInst,1);
                      *(undefined4 *)(cloneSrcOperand + 0x10) = swizzleCode;
                      Program__addInst(program,clonedInst);
                      *(int *)(program + 0x230) = *(int *)(program + 0x230) + -1;
                      arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
                      newEntryAlloc = (undefined4 *)Arena__alloc(arena,0x30);
                      newEntry = newEntryAlloc + 1;
                      *newEntryAlloc = arena;
                      LaneInfo__ctor_10e814(newEntry,clonedInst);
                      newEntryAlloc[6] = 1;
                      newEntry[laneIndex + 1] = laneSource;
                      groupVectorCount = outVectorAlloc[2];
                      if (groupVectorCount < *outVector) {
                        _memset((void *)(groupVectorCount * 4 + outVectorAlloc[3]),0,4);
                        newEntrySlotRef = (int *)(groupVectorCount * 4 + outVectorAlloc[3]);
                        outVectorAlloc[2] = groupVectorCount + 1;
                      }
                      else {
                        newEntrySlotRef = (int *)Vector__elementRefGrow(outVector,groupVectorCount);
                      }
                      *newEntrySlotRef = (int)newEntry;
                      cloneDestRegister = *(undefined4 *)(clonedInst + 0x94);
                      candidateWordCursor[7] = 1;
                      vectorAt418 = *(uint **)(program + 0x418);
                      vectorAt418Count = vectorAt418[1];
                      if (vectorAt418Count != 0) {
                        vectorAt418Index = 0;
                        do {
                          if (vectorAt418Index < *vectorAt418) {
                            if (vectorAt418Count <= vectorAt418Index) {
                              _memset((void *)(vectorAt418Count * 4 + vectorAt418[2]),0,(vectorAt418Index - vectorAt418Count) * 4 + 4);
                              vectorAt418[1] = vectorAt418Index + 1;
                            }
                            vectorAt418ElementRef = (int *)(vectorAt418Index * 4 + vectorAt418[2]);
                          }
                          else {
                            vectorAt418ElementRef = (int *)Vector__elementRefGrow(vectorAt418,vectorAt418Index);
                          }
                          vectorAt418Index = vectorAt418Index + 1;
                          vectorAt418Element = *vectorAt418ElementRef;
                          if (((iStack0000001c == *(int *)(vectorAt418Element + 0x1c)) &&
                              (headDestRegister == *(int *)(vectorAt418Element + 0x14))) &&
                             (laneStep == *(int *)(vectorAt418Element + 0x18))) {
                            *(int *)(vectorAt418Element + 0x18) = laneIndex;
                            *(undefined4 *)(vectorAt418Element + 0x14) = cloneDestRegister;
                          }
                          vectorAt418 = *(uint **)(program + 0x418);
                          vectorAt418Count = vectorAt418[1];
                        } while (vectorAt418Index < vectorAt418Count);
                      }
                      if (candidateEntry[5] == 0) {
                        laneCountTarget = 0;
                        break;
                      }
                    }
                    notLastLane = laneIndex != 3;
                    candidateWordCursor = candidateWordCursor + 1;
                    laneKindTable = laneKindTable + 1;
                    laneIndex = laneIndex + 1;
                  } while (notLastLane);
                }
                allocationCount = allocation[2];
                allocIndex = allocIndex + 1;
              } while ((int)allocIndex < (int)allocationCount);
            }
            laneCountTarget = laneCountTarget + -1;
          } while (0 < laneCountTarget);
          groupCursor = groupCursor + -1;
        } while (vec4GroupCount < groupCursor);
      }
      else {
        allocationCount = allocation[2];
      }
    }
    entryBlock = *(undefined4 *)(program + 0x3a8);
    if (allocationCount != 0) {
      allocIndex = 0;
      do {
        if (allocIndex < *allocationVector) {
          if (allocationCount <= allocIndex) {
            _memset((void *)(allocationCount * 4 + allocation[3]),0,(allocIndex - allocationCount) * 4 + 4);
            allocation[2] = allocIndex + 1;
          }
          allocElemRef = (undefined4 *)(allocIndex * 4 + allocation[3]);
        }
        else {
          allocElemRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocIndex);
        }
        allocIndex = allocIndex + 1;
        Block__appendInst(entryBlock,*(undefined4 *)*allocElemRef);
        allocationCount = allocation[2];
      } while (allocIndex < allocationCount);
    }
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported != 0) {
      copyCount = outVector[1];
      copyIndex = 0;
      if (copyCount != 0) {
        do {
          if (copyIndex < *outVector) {
            if (copyCount <= copyIndex) {
              _memset((void *)(copyCount * 4 + outVector[2]),0,(copyIndex - copyCount) * 4 + 4);
              outVector[1] = copyIndex + 1;
            }
            groupElemRef = (undefined4 *)(copyIndex * 4 + outVector[2]);
          }
          else {
            groupElemRef = (undefined4 *)Vector__elementRefGrow(outVector,copyIndex);
          }
          copyIndex = copyIndex + 1;
          Block__appendInst(entryBlock,*(undefined4 *)*groupElemRef);
          copyCount = outVector[1];
        } while (copyIndex < copyCount);
      }
    }
    vectorCount2 = vector[1];
    while (vectorCount2 != 0) {
      Vector__removeAt(vector,0);
      vectorCount2 = vector[1];
    }
    allocationCount = allocation[2];
    if (allocationCount != 0) {
      allocIndex = 0;
      do {
        if (allocIndex < *allocationVector) {
          if (allocationCount <= allocIndex) {
            _memset((void *)(allocationCount * 4 + allocation[3]),0,(allocIndex - allocationCount) * 4 + 4);
            allocation[2] = allocIndex + 1;
          }
          allocElemRef = (undefined4 *)(allocIndex * 4 + allocation[3]);
        }
        else {
          allocElemRef = (undefined4 *)Vector__elementRefGrow(allocationVector,allocIndex);
        }
        allocIndex = allocIndex + 1;
        vectorCount2 = vector[1];
        if (vectorCount2 < *vector) {
          _memset((void *)(vectorCount2 * 4 + vector[2]),0,4);
          vectorSlotRef = (undefined4 *)(vectorCount2 * 4 + vector[2]);
          vector[1] = vectorCount2 + 1;
        }
        else {
          vectorSlotRef = (undefined4 *)Vector__elementRefGrow(vector,vectorCount2);
        }
        *vectorSlotRef = *allocElemRef;
        allocationCount = allocation[2];
      } while (allocIndex < allocationCount);
    }
    packingSupported = (**(code **)(**(int **)(*(int *)(program + 8) + 0x30c) + 0xc4))();
    if (packingSupported != 0) {
      copyCount = outVector[1];
      copyIndex = 0;
      if (copyCount != 0) {
        do {
          if (copyIndex < *outVector) {
            if (copyCount <= copyIndex) {
              _memset((void *)(copyCount * 4 + outVector[2]),0,(copyIndex - copyCount) * 4 + 4);
              outVector[1] = copyIndex + 1;
            }
            outRef = (undefined4 *)(copyIndex * 4 + outVector[2]);
          }
          else {
            outRef = (undefined4 *)Vector__elementRefGrow(outVector,copyIndex);
          }
          copyIndex = copyIndex + 1;
          vectorCount = vector[1];
          if (vectorCount < *vector) {
            _memset((void *)(vectorCount * 4 + vector[2]),0,4);
            packEntryElemRef = (undefined4 *)(vectorCount * 4 + vector[2]);
            vector[1] = vectorCount + 1;
          }
          else {
            packEntryElemRef = (undefined4 *)Vector__elementRefGrow(vector,vectorCount);
          }
          *packEntryElemRef = *outRef;
          copyCount = outVector[1];
        } while (copyIndex < copyCount);
      }
    }
  }
  return;
LAB_001116e0:
  groupVectorCount = groupVectorAlloc[2];
  otherIndex = otherIndex + 1;
  if ((int)groupVectorCount <= (int)otherIndex) goto LAB_001116f0;
  goto LAB_00111270;
LAB_00111508:
  isLastLane = laneNumber == 3;
  laneFlagPtr = laneFlagPtr + 1;
  laneNumber = laneNumber + 1;
  if (isLastLane) goto LAB_0011151c;
  goto LAB_001113e0;
}

/* Program__packPsInputs @ 0x1121b4 (156 bytes) */
int Program__packPsInputs(program)
  int program;
{
  bool moreLanes;
  undefined4 *laneKindSlot;
  undefined4 *laneIndexSlot;
  int *allocation;
  uint vectorCount;
  uint nextIndex;
  int *cursorInst;
  int *interpInst;
  int *otherCandidateRef;
  int *candidateRef;
  int destOperandRecord;
  int outLane;
  int nextLane;
  int interpWord13c;
  undefined4 firstLaneKind;
  undefined4 interpWord148;
  undefined4 firstLaneIndex;
  uint innerElementCount;
  int otherWrittenCount;
  int mergedByteOffset;
  int mergedLane;
  int operandRecord;
  undefined4 mergedLaneKind;
  undefined4 instArena;
  undefined4 mergedLaneIndex;
  undefined4 *candidateSlotRef;
  undefined4 *interpAlloc;
  uint candidateCount;
  undefined1 *laneSlotCursor;
  int mergeCount;
  int *targetBlock;
  uint *candidateVector;
  int laneCount;
  int sourceLoad;
  int moveIndex;
  int interpWord144;
  int newElementCount;
  int laneIndex;
  int sourceLane;
  int instBaseOffset;
  int destRecord;
  int laneByteOffset;
  int interpWord140;
  uint outerIndex;
  uint appendIndex;
  uint innerIndex;
  int *nextInst;
  int *mergedLoad;
  int *laneFlagCursor;
  int *appendRef;
  int otherLoad;
  int vectorArena;
  int writtenCount;
  int interpKind;
  int query4c;
  int arenaRef;
  int nextOutputLane;
  int laneNo;
  int slotByteOffset;
  int candidateLoad;
  int vectorData;
  undefined1 gatherLaneSource [4];
  int savedDestSwizzle;
  undefined4 gatherLaneKind [4];
  undefined4 gatherLaneIndex [4];
  int gatherLoads [6];
  undefined1 *gatherBase;
  
  targetBlock = *(int **)(program + 0x3a4);
  if (targetBlock == (int *)0x0) {
    targetBlock = *(int **)(program + 0x3a0);
  }
  vectorArena = *(int *)(*(int *)(program + 8) + 0x378);
  allocation = (int *)Arena__alloc(vectorArena,0x14);
  candidateVector = (uint *)(allocation + 1);
  allocation[1] = 2;
  *allocation = vectorArena;
  allocation[2] = 0;
  allocation[4] = vectorArena;
  vectorData = Arena__alloc(vectorArena,8);
  allocation[3] = vectorData;
  candidateCount = 0;
  cursorInst = (int *)targetBlock[0x26];
  nextInst = (int *)((int *)targetBlock[0x26])[2];
  do {
    if (nextInst == (int *)0x0) {
      Vector__shellSort(candidateVector,Compare__ascendingByWrittenComponents);
      if (0 < (int)candidateCount) {
        outerIndex = 0;
        do {
          if (outerIndex < *candidateVector) {
            vectorCount = allocation[2];
            if (vectorCount <= outerIndex) {
              _memset((void *)(vectorCount * 4 + allocation[3]),0,(outerIndex - vectorCount) * 4 + 4);
              allocation[2] = outerIndex + 1;
            }
            candidateRef = (int *)(outerIndex * 4 + allocation[3]);
          }
          else {
            candidateRef = (int *)Vector__elementRefGrow(candidateVector,outerIndex);
          }
          nextIndex = outerIndex + 1;
          candidateLoad = *candidateRef;
          if (candidateLoad != 0) {
            laneCount = 0;
            laneIndex = 0;
            do {
              destOperandRecord = IRInst__getOperandRecord(candidateLoad,0);
              if (*(char *)(laneIndex + destOperandRecord + 0x10) != '\x01') {
                firstLaneKind = IRLoadInterp__laneKind(candidateLoad,laneIndex);
                gatherLaneKind[laneCount] = firstLaneKind;
                firstLaneIndex = IRLoadInterp__laneIndex(candidateLoad,laneIndex);
                gatherLaneSource[laneCount] = (char)laneIndex;
                gatherLaneIndex[laneCount] = firstLaneIndex;
                laneCount = laneCount + 1;
              }
              moreLanes = laneIndex != 3;
              laneIndex = laneIndex + 1;
            } while (moreLanes);
            interpWord140 = *(int *)(candidateLoad + 0x140);
            interpWord144 = *(int *)(candidateLoad + 0x144);
            interpWord148 = *(undefined4 *)(candidateLoad + 0x148);
            interpWord13c = *(int *)(candidateLoad + 0x13c);
            gatherLoads[0] = candidateLoad;
            if ((int)nextIndex < (int)candidateCount) {
              gatherBase = gatherLaneSource;
              newElementCount = outerIndex + 2;
              slotByteOffset = nextIndex * 4;
              mergeCount = 1;
              innerIndex = nextIndex;
              do {
                if (innerIndex < *candidateVector) {
                  innerElementCount = allocation[2];
                  if (innerElementCount <= innerIndex) {
                    _memset((void *)(innerElementCount * 4 + allocation[3]),0,(innerIndex - innerElementCount) * 4 + 4);
                    allocation[2] = newElementCount;
                  }
                  otherCandidateRef = (int *)(slotByteOffset + allocation[3]);
                }
                else {
                  otherCandidateRef = (int *)Vector__elementRefGrow(candidateVector,innerIndex);
                }
                otherLoad = *otherCandidateRef;
                if (((otherLoad != 0) && (otherWrittenCount = IRInst__countWrittenComponents(otherLoad), laneCount + otherWrittenCount < 5)) &&
                   ((*(int *)(otherLoad + 0x144) == interpWord144 &&
                    ((interpWord13c == *(int *)(otherLoad + 0x13c) && (interpWord140 == *(int *)(otherLoad + 0x140)))))))
                {
                  mergedLane = 0;
                  laneSlotCursor = gatherBase + laneCount * 4;
                  do {
                    operandRecord = IRInst__getOperandRecord(otherLoad,0);
                    if (*(char *)(mergedLane + operandRecord + 0x10) != '\x01') {
                      mergedLaneKind = IRLoadInterp__laneKind(otherLoad,mergedLane);
                      *(undefined4 *)(laneSlotCursor + 8) = mergedLaneKind;
                      mergedLaneIndex = IRLoadInterp__laneIndex(otherLoad,mergedLane);
                      *(undefined4 *)(laneSlotCursor + 0x18) = mergedLaneIndex;
                      laneSlotCursor = laneSlotCursor + 4;
                      gatherBase[laneCount] = (char)mergedLane;
                      laneCount = laneCount + 1;
                    }
                    moreLanes = mergedLane != 3;
                    mergedLane = mergedLane + 1;
                  } while (moreLanes);
                  mergedByteOffset = mergeCount * 4;
                  mergeCount = mergeCount + 1;
                  *(int *)(gatherBase + mergedByteOffset + 0x28) = otherLoad;
                  if (innerIndex < *candidateVector) {
                    innerElementCount = allocation[2];
                    if (innerElementCount <= innerIndex) {
                      _memset((void *)(innerElementCount * 4 + allocation[3]),0,(innerIndex - innerElementCount) * 4 + 4);
                      allocation[2] = newElementCount;
                    }
                    candidateSlotRef = (undefined4 *)(slotByteOffset + allocation[3]);
                  }
                  else {
                    candidateSlotRef = (undefined4 *)Vector__elementRefGrow(candidateVector,innerIndex);
                  }
                  *candidateSlotRef = 0;
                  if (laneCount == 4) break;
                }
                innerIndex = innerIndex + 1;
                newElementCount = newElementCount + 1;
                slotByteOffset = slotByteOffset + 4;
              } while (candidateCount != innerIndex);
              if (1 < mergeCount) {
                instArena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
                interpAlloc = (undefined4 *)Arena__alloc(instArena,0x168);
                *interpAlloc = instArena;
                interpInst = interpAlloc + 1;
                IRLoadInterp__ctor_109198(interpInst,*(undefined4 *)(program + 8));
                interpAlloc[0x51] = interpWord140;
                interpAlloc[0x50] = interpWord13c;
                interpAlloc[0x26] = interpWord148;
                interpAlloc[0x27] = interpWord144;
                interpAlloc[0x52] = interpWord144;
                interpAlloc[0x53] = interpWord148;
                if (0 < laneCount) {
                  laneByteOffset = 0;
                  laneFlagCursor = interpInst;
                  laneNo = 0;
                  do {
                    *(undefined1 *)(laneFlagCursor + 0x27) = 0;
                    laneFlagCursor = (int *)((int)laneFlagCursor + 1);
                    (**(code **)(*interpInst + 0x88))(interpInst,1,laneNo,gatherLaneSource[laneNo]);
                    laneKindSlot = (undefined4 *)((int)gatherLaneKind + laneByteOffset);
                    laneIndexSlot = (undefined4 *)((int)gatherLaneIndex + laneByteOffset);
                    nextLane = laneNo + 1;
                    laneByteOffset = laneByteOffset + 4;
                    IRLoadInterp__setLane(interpInst,laneNo,3,*laneKindSlot,*laneIndexSlot);
                    laneNo = nextLane;
                  } while (laneCount != nextLane);
                }
                nextOutputLane = 0;
                moveIndex = 0;
                interpAlloc[0x59] = mergeCount + *(int *)(program + 0x478);
                (**(code **)(*targetBlock + 0xc))(targetBlock,interpInst);
                do {
                  mergedLoad = (int *)gatherLoads[moveIndex];
                  destRecord = IRInst__getOperandRecord(mergedLoad,0);
                  savedDestSwizzle = *(int *)(destRecord + 0x10);
                  instBaseOffset = mergedLoad[0x58] - *(int *)(program + 0x478);
                  if (instBaseOffset < 0) {
                    instBaseOffset = 0;
                  }
                  DList__unlink(mergedLoad);
                  IRInst__reinitAsMov(mergedLoad,0x31,*(undefined4 *)(program + 8));
                  mergedLoad[0x26] = 0;
                  outLane = 0;
                  mergedLoad[0x25] = mergedLoad[0x53];
                  mergedLoad[0x27] = savedDestSwizzle;
                  mergedLoad[0x58] = instBaseOffset + *(int *)(program + 0x478);
                  sourceLane = nextOutputLane;
                  do {
                    if (*(char *)((int)gatherLaneKind + outLane + -4) == '\x01') {
                      (**(code **)(*mergedLoad + 0x88))(mergedLoad,1,outLane,4);
                      nextOutputLane = sourceLane;
                    }
                    else {
                      nextOutputLane = sourceLane + 1;
                      (**(code **)(*mergedLoad + 0x88))(mergedLoad,1,outLane,sourceLane);
                    }
                    moreLanes = outLane != 3;
                    outLane = outLane + 1;
                    sourceLane = nextOutputLane;
                  } while (moreLanes);
                  moveIndex = moveIndex + 1;
                  IRInst__setOperandSource(mergedLoad,1,interpInst,0,*(undefined4 *)(program + 8));
                  Block__appendInst(targetBlock,mergedLoad);
                } while (mergeCount != moveIndex);
              }
            }
          }
          outerIndex = nextIndex;
        } while ((int)nextIndex < (int)candidateCount);
      }
      if (candidateVector != (uint *)0x0) {
        Arena__free(allocation[4],allocation[3]);
        arenaRef = *allocation;
        if ((*(int *)(arenaRef + 0x28) != 0) &&
           (targetBlock = *(int **)(arenaRef + 0x14), targetBlock == allocation)) {
          _memset(targetBlock,0,*(int *)(arenaRef + 8) - (int)targetBlock);
          *(undefined4 *)(arenaRef + 8) = *(undefined4 *)(arenaRef + 0x14);
        }
        return;
      }
      return;
    }
    if ((cursorInst[5] & 1U) != 0) {
      query4c = (**(code **)(*cursorInst + 0x4c))(cursorInst);
      if (query4c != 0) {
        sourceLoad = (**(code **)(*cursorInst + 0x80))(cursorInst);
        interpKind = *(int *)(sourceLoad + 0x144);
        if (((((*(int *)(program + 0x3e4) == 0) || (interpKind != *(int *)(program + 0x3f4))) ||
             (*(int *)(sourceLoad + 0x148) < *(int *)(program + 1000))) ||
            (*(int *)(program + 0x3ec) <= *(int *)(sourceLoad + 0x148))) &&
           (((interpKind == 0x24 || (interpKind == 0x15)) &&
            ((writtenCount = IRInst__countWrittenComponents(sourceLoad), writtenCount != 4 &&
             (writtenCount = IRInst__countWrittenComponents(sourceLoad), writtenCount != 0)))))) {
          appendIndex = allocation[2];
          candidateCount = candidateCount + 1;
          if (appendIndex < *candidateVector) {
            _memset((void *)(appendIndex * 4 + allocation[3]),0,4);
            appendRef = (int *)(appendIndex * 4 + allocation[3]);
            allocation[2] = appendIndex + 1;
          }
          else {
            appendRef = (int *)Vector__elementRefGrow(candidateVector,appendIndex);
          }
          *appendRef = sourceLoad;
          nextInst = (int *)cursorInst[2];
          goto LAB_00112378;
        }
      }
      nextInst = (int *)cursorInst[2];
    }
LAB_00112378:
    cursorInst = nextInst;
    nextInst = (int *)nextInst[2];
  } while( true );
}

/* KhanVs__vslot88_assignOutputBindings @ 0x1128a0 (1640 bytes) */
int KhanVs__vslot88_assignOutputBindings(this, program)
  int *this;
  int program;
{
  uint *exportVector;
  code *bindGroupFn;
  uint slotMask;
  uint exportIndex;
  uint scanIndex;
  undefined4 interpolatorCode;
  uint nextExportIndex;
  int *exportRecordRef;
  undefined4 semanticCode;
  undefined4 semanticWord;
  undefined4 kind7LaneIndex;
  int outputRecord;
  int slotBase;
  int byteOffset;
  int fixedLayout;
  uint recordCountB;
  uint outputSlot;
  int interpolatorKind;
  int bindingKindB;
  int exportPackingEnabled;
  uint loopIndex;
  int instQuery68;
  undefined4 kind6LaneIndex;
  undefined4 *outputRecordRef;
  undefined4 defaultLaneMask;
  uint recordCountA;
  int bindingKind;
  int *nextInstInList;
  int *nextInst;
  uint recordCapacity;
  undefined4 compiler;
  int *outputKind7Inst;
  uint nextIndex;
  uint recordCount;
  code *bindOutputFn;
  int *inst;
  uint *kind2Vector;
  int *outputKind6Inst;
  int recordInst;
  int nextSlot;
  undefined1 slotFlagBytes [4];
  undefined4 slotValueWords [10];
  
  inst = *(int **)(*(int *)(program + 0x3a8) + 0x98);
  nextInstInList = (int *)inst[2];
  if (nextInstInList == (int *)0x0) {
    outputKind6Inst = (int *)0x0;
    outputKind7Inst = (int *)0x0;
  }
  else {
    outputKind6Inst = (int *)0x0;
    outputKind7Inst = (int *)0x0;
    do {
      nextInst = nextInstInList;
      if ((inst[5] & 1U) != 0) {
        instQuery68 = (**(code **)(*inst + 0x68))(inst);
        if (instQuery68 == 0) {
LAB_0011293c:
          nextInst = (int *)inst[2];
        }
        else if (inst[0x4f] == 6) {
          nextInst = (int *)inst[2];
          outputKind6Inst = inst;
        }
        else {
          if (inst[0x4f] != 7) goto LAB_0011293c;
          nextInst = (int *)inst[2];
          outputKind7Inst = inst;
        }
      }
      nextInstInList = (int *)nextInst[2];
      inst = nextInst;
    } while ((int *)nextInst[2] != (int *)0x0);
  }
  nextSlot = 0;
  compiler = *(undefined4 *)(program + 8);
  if (outputKind6Inst != (int *)0x0) {
    outputKind6Inst[0x25] = 0;
    outputKind6Inst[0x26] = 5;
    nextSlot = 1;
    bindOutputFn = *(code **)(*this + 0x54);
    kind6LaneIndex = IRLoadInterp__laneIndex_104180(outputKind6Inst,0);
    defaultLaneMask = DAT_001afa0c;
    IRLoadInterp__laneIndex_104180(outputKind6Inst,0);
    (*bindOutputFn)(this,0,0,kind6LaneIndex,defaultLaneMask,0,0,0);
  }
  if (outputKind7Inst != (int *)0x0) {
    outputKind7Inst[0x25] = 1;
    outputKind7Inst[0x26] = 5;
    nextSlot = nextSlot + 1;
    bindOutputFn = *(code **)(*this + 0x54);
    kind7LaneIndex = IRLoadInterp__laneIndex_104180(outputKind7Inst,0);
    defaultLaneMask = DAT_001afa0c;
    IRLoadInterp__laneIndex_104180(outputKind7Inst,0);
    (*bindOutputFn)(this,1,1,kind7LaneIndex,defaultLaneMask,0,0,0);
  }
  fixedLayout = Program__classifyExportInsts(program);
  *(int *)(program + 0x3e4) = fixedLayout;
  if (fixedLayout == 0) {
    Vector__shellSort(*(undefined4 *)(program + 0x420),Compare__descendingByRemappedKey);
    kind2Vector = *(uint **)(program + 0x420);
    recordCount = kind2Vector[1];
    if (recordCount != 0) {
      loopIndex = 0;
      nextIndex = 1;
      byteOffset = 0;
      do {
        recordCapacity = *kind2Vector;
        if (loopIndex < recordCapacity) {
          if (recordCount <= loopIndex) {
            _memset(recordCount * 4 + kind2Vector[2],0,(loopIndex - recordCount) * 4 + 4);
            recordCapacity = *kind2Vector;
            kind2Vector[1] = nextIndex;
          }
          outputRecordRef = (undefined4 *)(byteOffset + kind2Vector[2]);
        }
        else {
          outputRecordRef = (undefined4 *)Vector__elementRefGrow(kind2Vector,loopIndex);
          recordCapacity = *kind2Vector;
        }
        semanticWord = *(undefined4 *)(*(int *)*outputRecordRef + 0x13c);
        if (loopIndex < recordCapacity) {
          recordCount = kind2Vector[1];
          if (recordCount <= loopIndex) {
            _memset(recordCount * 4 + kind2Vector[2],0,(loopIndex - recordCount) * 4 + 4);
            kind2Vector[1] = nextIndex;
          }
          outputRecordRef = (undefined4 *)(byteOffset + kind2Vector[2]);
        }
        else {
          outputRecordRef = (undefined4 *)Vector__elementRefGrow(kind2Vector,loopIndex);
        }
        bindingKind = Lane__remapValue(semanticWord,*(undefined4 *)(*(int *)*outputRecordRef + 0x140));
        if (bindingKind - 2U < 2) {
          exportPackingEnabled = Compiler__isOptionEnabled(compiler,0x3f);
          slotBase = nextSlot;
          if (exportPackingEnabled == 0) {
            kind2Vector = *(uint **)(program + 0x420);
            nextSlot = nextSlot + 4;
            recordCount = kind2Vector[1];
            if (recordCount != 0) {
              scanIndex = 0;
              do {
                if (scanIndex < *kind2Vector) {
                  if (recordCount <= scanIndex) {
                    _memset(recordCount * 4 + kind2Vector[2],0,(scanIndex - recordCount) * 4 + 4);
                    kind2Vector[1] = scanIndex + 1;
                  }
                  outputRecordRef = (undefined4 *)(scanIndex * 4 + kind2Vector[2]);
                }
                else {
                  outputRecordRef = (undefined4 *)Vector__elementRefGrow(kind2Vector,scanIndex);
                }
                scanIndex = scanIndex + 1;
                recordInst = *(int *)*outputRecordRef;
                bindingKindB = Lane__remapValue(*(undefined4 *)(recordInst + 0x13c),*(undefined4 *)(recordInst + 0x140)
                                    );
                if (bindingKindB < 4) {
                  *(undefined4 *)(recordInst + 0x98) = 5;
                  *(int *)(recordInst + 0x94) = slotBase + bindingKindB;
                }
                else {
                  *(int *)(recordInst + 0x94) = nextSlot;
                  *(undefined4 *)(recordInst + 0x98) = 5;
                  nextSlot = nextSlot + 1;
                }
                kind2Vector = *(uint **)(program + 0x420);
                recordCount = kind2Vector[1];
              } while (scanIndex < recordCount);
            }
          }
          else {
            ((int (*)())Program__assignExportSlotsByKind)(*(undefined4 *)(program + 0x420),&nextSlot,program);
          }
          goto LAB_00112c28;
        }
        recordCount = kind2Vector[1];
        loopIndex = loopIndex + 1;
        nextIndex = nextIndex + 1;
        byteOffset = byteOffset + 4;
      } while (loopIndex < recordCount);
      kind2Vector = *(uint **)(program + 0x420);
    }
    ((int (*)())Program__assignSharedExportSlots)(2,kind2Vector,&nextSlot,program);
LAB_00112c28:
    ((int (*)())Program__assignSharedExportSlots)(3,*(undefined4 *)(program + 0x424),&nextSlot,program);
    Vector__shellSort(*(undefined4 *)(program + 0x41c),Compare__descendingByField140);
    ((int (*)())Program__assignSharedExportSlots)(1,*(undefined4 *)(program + 0x41c),&nextSlot,program);
  }
  else {
    *(int *)(program + 0x3f0) = nextSlot - *(int *)(program + 1000);
    ((int (*)())Program__assignOutputExportSlots)(2,*(undefined4 *)(program + 0x420),&nextSlot,program);
    ((int (*)())Program__assignOutputExportSlots)(3,*(undefined4 *)(program + 0x424),&nextSlot,program);
    ((int (*)())Program__assignOutputExportSlots)(1,*(undefined4 *)(program + 0x41c),&nextSlot,program);
  }
  *(int *)(program + 0x234) = nextSlot + 1;
  slotMask = 0;
  exportIndex = 0;
LAB_00112ec4:
  exportVector = *(uint **)(program + 0x418);
  recordCountA = exportVector[1];
  if (recordCountA <= exportIndex) {
    return;
  }
  if (exportIndex < *exportVector) {
    if (recordCountA <= exportIndex) {
      _memset(recordCountA * 4 + exportVector[2],0,(exportIndex - recordCountA) * 4 + 4);
      exportVector[1] = exportIndex + 1;
    }
    exportRecordRef = (int *)(exportIndex * 4 + exportVector[2]);
  }
  else {
    exportRecordRef = (int *)Vector__elementRefGrow(exportVector,exportIndex);
  }
  nextExportIndex = exportIndex + 1;
  outputRecord = *exportRecordRef;
  outputSlot = *(uint *)(outputRecord + 0x10);
  slotValueWords[outputSlot] = *(undefined4 *)(outputRecord + 0x14);
  slotFlagBytes[*(int *)(outputRecord + 0x10)] = (char)*(undefined4 *)(outputRecord + 0x18);
  exportVector = *(uint **)(program + 0x418);
  slotMask = slotMask | 1 << (outputSlot & 0x3f);
  recordCountB = exportVector[1];
  if (recordCountB != nextExportIndex) goto code_r0x00112df4;
  interpolatorKind = *(int *)(outputRecord + 4);
  goto LAB_00112e78;
code_r0x00112df4:
  if (nextExportIndex < *exportVector) {
    if (recordCountB <= nextExportIndex) {
      _memset(recordCountB * 4 + exportVector[2],0,(nextExportIndex - recordCountB) * 4 + 4);
      exportVector[1] = exportIndex + 2;
    }
    exportRecordRef = (int *)(nextExportIndex * 4 + exportVector[2]);
  }
  else {
    exportRecordRef = (int *)Vector__elementRefGrow(exportVector,nextExportIndex);
  }
  interpolatorKind = *(int *)(outputRecord + 4);
  if ((interpolatorKind != *(int *)(*exportRecordRef + 4)) ||
     (exportIndex = nextExportIndex, *(int *)(outputRecord + 8) != *(int *)(*exportRecordRef + 8))) {
LAB_00112e78:
    bindGroupFn = *(code **)(*this + 0x58);
    interpolatorCode = Table__interpolatorKindToCode(program,interpolatorKind);
    semanticCode = Index__scaleForMode(*(undefined4 *)(outputRecord + 4),*(undefined4 *)(outputRecord + 8));
    (*bindGroupFn)(this,slotValueWords,slotFlagBytes,interpolatorCode,semanticCode,slotMask);
    slotMask = 0;
    exportIndex = nextExportIndex;
  }
  goto LAB_00112ec4;
}

/* OpcodeTraits__getRecordTail @ 0x112f08 (76 bytes) */
int OpcodeTraits__getRecordTail(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + 0x30c) + 0x16c))(*(int **)(compiler + 0x30c),compiler);
  return opcodeFlagTable + opcode * 0x38 + 0x10;
}

/* Opcode__getInfo @ 0x112f54 (36 bytes) */
int Opcode__getInfo(opcode)
  int opcode;
{
  return *(undefined4 *)(&DAT_001fc2b0 + opcode * 4);
}

/* OpcodeTraits__flagBit0 @ 0x112f78 (76 bytes) */
int OpcodeTraits__flagBit0(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) & 1;
}

/* Value__isBelow8 @ 0x112fc4 (16 bytes) */
int Value__isBelow8(value)
  uint value;
{
  return value < 8;
}

/* Value__isBelow7 @ 0x112fd4 (16 bytes) */
int Value__isBelow7(value)
  uint value;
{
  return value < 7;
}

/* Backend__bindingSlotsSequential @ 0x112fe4 (172 bytes) */
int Backend__bindingSlotsSequential(compiler)
  int compiler;
{
  int entrySlotNumber;
  int nextExpectedSlot;
  int limitsTable;
  int bindingCount;
  undefined4 slotsAreSequential;
  int *entryCursor;
  
  limitsTable = (**(code **)(**(int **)(compiler + 0x30c) + 0x16c))(*(int **)(compiler + 0x30c));
  bindingCount = (**(code **)(**(int **)(compiler + 0x30c) + 0x40))(*(int **)(compiler + 0x30c));
  if (bindingCount < 1) {
LAB_00113034:
    slotsAreSequential = 1;
  }
  else {
    if (*(int *)(limitsTable + 8) == 0) {
      entryCursor = (int *)(limitsTable + 0x40);
      entrySlotNumber = 0;
      do {
        nextExpectedSlot = entrySlotNumber + 1;
        if (bindingCount == nextExpectedSlot) goto LAB_00113034;
        entrySlotNumber = *entryCursor;
        entryCursor = entryCursor + 0xe;
      } while (entrySlotNumber == nextExpectedSlot);
    }
    slotsAreSequential = 0;
  }
  return slotsAreSequential;
}

/* OpcodeTraits__flagBit2 @ 0x113090 (76 bytes) */
int OpcodeTraits__flagBit2(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 2 & 1;
}

/* OpcodeTraits__flagBit3 @ 0x1130dc (76 bytes) */
int OpcodeTraits__flagBit3(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 3 & 1;
}

/* OpcodeTraits__flagBit6 @ 0x113128 (76 bytes) */
int OpcodeTraits__flagBit6(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 6 & 1;
}

/* OpcodeTraits__flagBit7 @ 0x113174 (76 bytes) */
int OpcodeTraits__flagBit7(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 7 & 1;
}

/* OpcodeTraits__flagBit8 @ 0x1131c0 (76 bytes) */
int OpcodeTraits__flagBit8(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 8 & 1;
}

/* OpcodeTraits__flagBit9 @ 0x11320c (76 bytes) */
int OpcodeTraits__flagBit9(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 9 & 1;
}

/* OpcodeTraits__flagBit10 @ 0x113258 (76 bytes) */
int OpcodeTraits__flagBit10(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 10 & 1;
}

/* OpcodeTraits__flagBit12 @ 0x1132a4 (76 bytes) */
int OpcodeTraits__flagBit12(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 0xc & 1;
}

/* OpcodeTraits__flagBit13 @ 0x1132f0 (76 bytes) */
int OpcodeTraits__flagBit13(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(uint *)(opcode * 0x38 + opcodeFlagTable) >> 0xd & 1;
}

/* OpcodeTraits__getField4 @ 0x11333c (76 bytes) */
int OpcodeTraits__getField4(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(undefined4 *)(opcode * 0x38 + opcodeFlagTable + 4);
}

/* OpcodeTraits__getInstClass @ 0x113388 (76 bytes) */
int OpcodeTraits__getInstClass(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(undefined4 *)(opcode * 0x38 + opcodeFlagTable + 0x30);
}

/* OpcodeTraits__getFieldC @ 0x1133d4 (76 bytes) */
int OpcodeTraits__getFieldC(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(undefined4 *)(opcode * 0x38 + opcodeFlagTable + 0xc);
}

/* OpcodeTraits__getField34 @ 0x113420 (76 bytes) */
int OpcodeTraits__getField34(opcode, compiler)
  int opcode;
  int compiler;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + COMP_target) + 0x16c))(*(int **)(compiler + COMP_target),compiler);
  return *(undefined4 *)(opcode * 0x38 + opcodeFlagTable + 0x34);
}

/* OpcodeTraits__instFlagBit2 @ 0x11346c (80 bytes) */
int OpcodeTraits__instFlagBit2(compiler, inst)
  int compiler;
  int inst;
{
  int opcodeFlagTable;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + 0x30c) + 0x16c))(*(int **)(compiler + 0x30c),inst);
  return *(uint *)(opcodeFlagTable + *(int *)(*(int *)(inst + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* OpcodeInfo__getResultMode @ 0x1134bc (152 bytes) */
int OpcodeInfo__getResultMode(opcodeInfo, inst, program)
  int opcodeInfo;
  int *inst;
  int program;
{
  int vtableQueryResult;
  int instFlagBit2Result;
  int resultMode;
  
  resultMode = *(int *)(opcodeInfo + 0xc);
  if (resultMode == 0) {
    instFlagBit2Result = ((int (*)())OpcodeTraits__instFlagBit2)(*(undefined4 *)(program + 8),inst);
    if (instFlagBit2Result != 0) {
      return 1;
    }
    resultMode = *(int *)(opcodeInfo + 0xc);
  }
  if (resultMode != 0x10) {
    return resultMode;
  }
  vtableQueryResult = (**(code **)(*inst + 0x30))(inst);
  if (vtableQueryResult != 0) {
    return 9;
  }
  instFlagBit2Result = ((int (*)())OpcodeTraits__instFlagBit2)(*(undefined4 *)(program + 8),inst);
  if (instFlagBit2Result != 0) {
    return 1;
  }
  return 0;
}

/* mulFloatZeroAnnihilates @ 0x113554 (56 bytes) */
double mulFloatZeroAnnihilates(double fparam_1,double fparam_2)
{
  double dVar1;
  
  dVar1 = (double)FLOAT_001aa0d4;
  if (fparam_1 == dVar1) {
    return dVar1;
  }
  if (fparam_2 == dVar1) {
    return dVar1;
  }
  return (double)(float)(fparam_1 * fparam_2);
}

/* OpcodeSetup__mode9 @ 0x11358c (28 bytes) */
int OpcodeSetup__mode9(setup, inst)
  int setup;
  int inst;
{
  *(undefined4 *)(inst + 0x84) = 3;
  *(undefined4 *)(inst + 0x80) = 1;
  *(undefined4 *)(setup + 4) = 9;
  return;
}

/* OpcodeSetup__mode6 @ 0x1135a8 (24 bytes) */
int OpcodeSetup__mode6(setup, inst)
  int setup;
  int inst;
{
  *(undefined4 *)(inst + 0x84) = 1;
  *(undefined4 *)(inst + 0x80) = 1;
  *(undefined4 *)(setup + 4) = 6;
  return;
}

/* OpcodeSetup__mode1 @ 0x1135c0 (44 bytes) */
int OpcodeSetup__mode1(setup, inst)
  int setup;
  int inst;
{
  *(undefined4 *)(inst + 0x84) = 0;
  *(undefined4 *)(inst + 300) = 0;
  *(undefined4 *)(inst + 0x80) = 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18000;
  *(undefined4 *)(setup + 4) = 1;
  return;
}

/* OpcodeSetup__mode7 @ 0x1135ec (80 bytes) */
int OpcodeSetup__mode7(setup, inst, compiler)
  int setup;
  int inst;
  int compiler;
{
  *(undefined4 *)(inst + 0x84) = 1;
  *(undefined4 *)(inst + 0x80) = 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18;
  Program__addInst(*(undefined4 *)(compiler + 0x6c4),inst);
  *(undefined4 *)(setup + 4) = 7;
  return;
}

/* OpcodeSetup__mode8 @ 0x11363c (84 bytes) */
int OpcodeSetup__mode8(setup, inst, compiler)
  int setup;
  int inst;
  int compiler;
{
  *(undefined4 *)(inst + 0x80) = 0;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18;
  *(undefined4 *)(inst + 0x84) = 1;
  Program__addInst(*(undefined4 *)(compiler + 0x6c4),inst);
  *(undefined4 *)(setup + 4) = 8;
  return;
}

/* OpcodeSetup__mode5 @ 0x113690 (84 bytes) */
int OpcodeSetup__mode5(setup, inst, compiler)
  int setup;
  int inst;
  int compiler;
{
  *(undefined4 *)(inst + 0x84) = 1;
  *(undefined4 *)(inst + 0x80) = 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18018;
  Program__addInst(*(undefined4 *)(compiler + 0x6c4),inst);
  *(undefined4 *)(setup + 4) = 5;
  return;
}

/* OpcodeSetup__mode3 @ 0x1136e4 (40 bytes) */
int OpcodeSetup__mode3(setup, inst)
  int setup;
  int inst;
{
  *(undefined4 *)(inst + 0x84) = 1;
  *(undefined4 *)(inst + 0x80) = 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18000;
  *(undefined4 *)(setup + 4) = 3;
  return;
}

/* OpcodeSetup__mode2 @ 0x11370c (40 bytes) */
int OpcodeSetup__mode2(setup, inst)
  int setup;
  int inst;
{
  *(undefined4 *)(inst + 0x84) = 0;
  *(undefined4 *)(inst + 0x80) = 0;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x18000;
  *(undefined4 *)(setup + 4) = 2;
  return;
}

/* OpcodeTraits__instFlagBit2_113734 @ 0x113734 (104 bytes) */
int OpcodeTraits__instFlagBit2_113734(compiler, inst, unusedArg3, destDescriptor, unusedArg5, foldedResult, unusedArg7)
  int compiler;
  int inst;
  undefined4 unusedArg3;
  undefined4 destDescriptor;
  undefined4 unusedArg5;
  undefined4 foldedResult;
  undefined4 unusedArg7;
{
  uint flagBit2;
  int *targetObject;
  int opcodeFlagTable;
  
  flagBit2 = 0;
  targetObject = *(int **)(compiler + 0x30c);
  if ((targetObject[2] & 0x10U) != 0) {
    opcodeFlagTable = (**(code **)(*targetObject + 0x16c))(targetObject);
    flagBit2 = *(uint *)(opcodeFlagTable + *(int *)(*(int *)(inst + 0x88) + 8) * 0x38) >> 2 & 1;
  }
  return flagBit2;
}

/* OpcodeTraits__flag1WithoutFlag7 @ 0x11379c (124 bytes) */
int OpcodeTraits__flag1WithoutFlag7(compiler, inst)
  int compiler;
  int inst;
{
  int opcodeFlagTable;
  int flagBit7Result;
  undefined4 result;
  int opcode;
  
  opcodeFlagTable = (**(code **)(**(int **)(compiler + 0x30c) + 0x16c))(*(int **)(compiler + 0x30c),inst);
  opcode = *(int *)(*(int *)(inst + 0x88) + 8);
  flagBit7Result = ((int (*)())OpcodeTraits__flagBit7)(opcode,compiler);
  if ((flagBit7Result != 0) || (result = 1, (*(uint *)(opcodeFlagTable + opcode * 0x38) & 2) == 0)) {
    result = 0;
  }
  return result;
}

/* IrRecipSqrtClamp__opcodeInfo_atexit_dtor_op65 @ 0x113818 (40 bytes) */
int IrRecipSqrtClamp__opcodeInfo_atexit_dtor_op65()
{
  DAT_001fb93c = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrRecipSqrtFF__opcodeInfo_atexit_dtor_op66 @ 0x113840 (40 bytes) */
int IrRecipSqrtFF__opcodeInfo_atexit_dtor_op66()
{
  DAT_001fb928 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrRecipSqrtIEEE__opcodeInfo_atexit_dtor_op67 @ 0x113868 (40 bytes) */
int IrRecipSqrtIEEE__opcodeInfo_atexit_dtor_op67()
{
  DAT_001fb914 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrRecipClamp__opcodeInfo_atexit_dtor_op62 @ 0x113890 (40 bytes) */
int IrRecipClamp__opcodeInfo_atexit_dtor_op62()
{
  DAT_001fbf90 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrRecipFF__opcodeInfo_atexit_dtor_op63 @ 0x1138b8 (40 bytes) */
int IrRecipFF__opcodeInfo_atexit_dtor_op63()
{
  DAT_001fbf7c = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrRecipIEEE__opcodeInfo_atexit_dtor_op64 @ 0x1138e0 (40 bytes) */
int IrRecipIEEE__opcodeInfo_atexit_dtor_op64()
{
  DAT_001fbf68 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrMulFloat__opcodeInfo_atexit_dtor_op19 @ 0x113908 (40 bytes) */
int IrMulFloat__opcodeInfo_atexit_dtor_op19()
{
  DAT_001fc134 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrMul__opcodeInfo_atexit_dtor_op54 @ 0x113930 (40 bytes) */
int IrMul__opcodeInfo_atexit_dtor_op54()
{
  DAT_001fc120 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrLogClamp__opcodeInfo_atexit_dtor_op58 @ 0x113958 (40 bytes) */
int IrLogClamp__opcodeInfo_atexit_dtor_op58()
{
  DAT_001fb964 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrLogIEEE__opcodeInfo_atexit_dtor_op59 @ 0x113980 (40 bytes) */
int IrLogIEEE__opcodeInfo_atexit_dtor_op59()
{
  DAT_001fb950 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrLoopStart__opcodeInfo_atexit_dtor_001fb478 @ 0x1139a8 (40 bytes) */
int IrLoopStart__opcodeInfo_atexit_dtor_001fb478()
{
  DAT_001fb464 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrLoopStart__opcodeInfo_atexit_dtor_op129 @ 0x1139d0 (40 bytes) */
int IrLoopStart__opcodeInfo_atexit_dtor_op129()
{
  DAT_001fb478 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrDot2Add__opcodeInfo_atexit_dtor_op30 @ 0x1139f8 (40 bytes) */
int IrDot2Add__opcodeInfo_atexit_dtor_op30()
{
  DAT_001fbdc4 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrAdd__opcodeInfo_atexit_dtor_op52 @ 0x113a20 (40 bytes) */
int IrAdd__opcodeInfo_atexit_dtor_op52()
{
  DAT_001fc170 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrOpDp__opcodeInfo_atexit_dtor_op151 @ 0x113a48 (40 bytes) */
int IrOpDp__opcodeInfo_atexit_dtor_op151()
{
  DAT_001fb2c0 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrAllocInterp__opcodeInfo_atexit_dtor_op150 @ 0x113a70 (40 bytes) */
int IrAllocInterp__opcodeInfo_atexit_dtor_op150()
{
  DAT_001fb2d4 = PTR_DAT_001e8f28 + 8;
  return;
}

/* IrAllocColor__opcodeInfo_atexit_dtor_op149 @ 0x113a98 (40 bytes) */
int IrAllocColor__opcodeInfo_atexit_dtor_op149()
{
  DAT_001fb2e8 = PTR_DAT_001e8f28 + 8;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001128a0");
asm(".set FUN_001128a0, _KhanVs__vslot88_assignOutputBindings");
