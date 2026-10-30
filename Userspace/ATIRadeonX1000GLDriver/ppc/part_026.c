#include "decls.h"

/* ConstRecord__insertSwizzleVariants @ 0xf4ddc (512 bytes) */
int ConstRecord__insertSwizzleVariants(constTables, variantStart, constRecord)
  int constTables;
  int variantStart;
  int constRecord;
{
  uint savedUsedFlag;
  int tableIndex;
  char usedMask;
  uint laneBit;
  int sourceLane;
  uint loopCounterB;
  uint *savedFlagWrite;
  int *variantLane;
  undefined4 laneWord;
  undefined4 *savedLaneWrite;
  undefined4 *savedLaneRead;
  int laneRecord;
  uint *savedFlagRead;
  int *variantEntry;
  int loopCounter;
  uint savedUsedFlags [4];
  undefined4 hashTables [4];
  undefined4 savedLanes [24];
  int variantTable [75];
  int variantTableEnd [3];
  
  _memcpy(variantTable,&DAT_001aa87c,300);
  usedMask = *(char *)(constRecord + 0x15c);
  savedLaneRead = savedLanes;
  savedFlagRead = savedUsedFlags;
  loopCounterB = 0;
  loopCounter = 4;
  savedFlagWrite = savedFlagRead;
  savedLaneWrite = savedLaneRead;
  laneRecord = constRecord;
  do {
    laneBit = loopCounterB & 0x3f;
    laneWord = *(undefined4 *)(laneRecord + 0x20);
    *savedLaneWrite = *(undefined4 *)(laneRecord + 0x1c);
    loopCounterB = loopCounterB + 1;
    savedLaneWrite[1] = laneWord;
    laneRecord = laneRecord + 0x18;
    *savedFlagWrite = (int)usedMask >> laneBit & 1;
    savedLaneWrite = savedLaneWrite + 6;
    savedFlagWrite = savedFlagWrite + 1;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  hashTables[0] = *(undefined4 *)(constTables + 8);
  hashTables[1] = *(undefined4 *)(constTables + 0xc);
  hashTables[2] = *(undefined4 *)(constTables + 0x10);
  hashTables[3] = *(undefined4 *)(constTables + 0x14);
  if (*(int *)(&DAT_001aa86c + (4 - variantStart) * 4) < 0xf) {
    variantEntry = variantTable + *(int *)(&DAT_001aa86c + (4 - variantStart) * 4) * 5;
    do {
      loopCounter = 4;
      loopCounterB = 0;
      variantLane = variantEntry;
      laneRecord = constRecord;
      do {
        sourceLane = variantLane[1];
        if (sourceLane < 0) {
          *(undefined4 *)(laneRecord + 0x1c) = 0;
          *(undefined4 *)(laneRecord + 0x20) = 0;
          *(byte *)(constRecord + 0x15c) = *(byte *)(constRecord + 0x15c) & ~(byte)(1 << (loopCounterB & 0x3f));
        }
        else {
          laneWord = savedLanes[sourceLane * 6];
          *(undefined4 *)(laneRecord + 0x20) = savedLanes[sourceLane * 6 + 1];
          *(undefined4 *)(laneRecord + 0x1c) = laneWord;
          *(byte *)(constRecord + 0x15c) = (byte)(1 << (loopCounterB & 0x3f)) | *(byte *)(constRecord + 0x15c);
        }
        loopCounterB = loopCounterB + 1;
        variantLane = variantLane + 1;
        laneRecord = laneRecord + 0x18;
        loopCounter = loopCounter + -1;
      } while (loopCounter != 0);
      tableIndex = *variantEntry;
      variantEntry = variantEntry + 5;
      HashTable__insert(hashTables[tableIndex],constRecord);
    } while (variantEntry != variantTableEnd);
  }
  loopCounter = 4;
  loopCounterB = 0;
  laneRecord = constRecord;
  do {
    laneWord = savedLaneRead[1];
    *(undefined4 *)(laneRecord + 0x1c) = *savedLaneRead;
    *(undefined4 *)(laneRecord + 0x20) = laneWord;
    savedUsedFlag = *savedFlagRead;
    savedFlagRead = savedFlagRead + 1;
    if (savedUsedFlag == 0) {
      *(byte *)(constRecord + 0x15c) = *(byte *)(constRecord + 0x15c) & ~(byte)(1 << (loopCounterB & 0x3f));
    }
    else {
      *(byte *)(constRecord + 0x15c) = (byte)(1 << (loopCounterB & 0x3f)) | *(byte *)(constRecord + 0x15c);
    }
    loopCounterB = loopCounterB + 1;
    savedLaneRead = savedLaneRead + 6;
    laneRecord = laneRecord + 0x18;
    loopCounter = loopCounter + -1;
  } while (loopCounter != 0);
  return;
}

/* Compiler__getOrCreateLoadConstN @ 0xf4fdc (352 bytes) */
int Compiler__getOrCreateLoadConstN(compiler, constCount, firstConstKind, firstConstValue, firstConstWord2, firstConstWord3, firstConstWord4, firstConstWord5)
  int *compiler;
  int constCount;
  undefined4 firstConstKind;
  undefined4 firstConstValue;
  undefined4 firstConstWord2;
  undefined4 firstConstWord3;
  undefined4 firstConstWord4;
  undefined4 firstConstWord5;
{
  undefined4 *instRecordCursor;
  undefined4 recordWord;
  undefined4 constantSlot;
  undefined4 newInstId;
  undefined4 arena;
  undefined4 recordWord0;
  int recordDest;
  undefined4 *cachedInst;
  undefined4 *allocation;
  int *blockList;
  undefined4 *keyRecordCursor;
  int loopCounter;
  uint loopIndex;
  int loopCounterB;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  /* issue #64 live-repro: same defect as Compiler__getOrCreateConstVectorN in this file (fixed earlier this session) -
   * called below as aiStack_9c[constCount] with constCount observed as 4, one past this array's declared
   * 4 elements; local_8c (assigned right after, from compiler[5]) sits exactly at the missing 5th
   * index by its own hex offset (0x9c-0x8c=0x10). Extended to 5 elements; local_8c aliased to
   * index 4. */
  int aiStack_9c [5];
#define local_8c aiStack_9c[4]
  undefined4 constRecords [29];
  
  aiStack_9c[1] = compiler[2];
  aiStack_9c[2] = compiler[3];
  loopCounterB = 4;
  loopCounter = 0;
  loopIndex = 0;
  constRecords[0] = firstConstKind;
  constRecords[1] = firstConstValue;
  aiStack_9c[3] = compiler[4];
  local_8c = compiler[5];
  keyRecordCursor = constRecords;
  do {
    if ((int)loopIndex < constCount) {
      *(byte *)(compiler[10] + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(compiler[10] + 0x15c);
      recordWord0 = *(undefined4 *)((int)keyRecordCursor + loopCounter);
      recordDest = loopCounter + 0x10 + compiler[10];
      *(undefined4 *)(recordDest + 0x10) = *(undefined4 *)((int)constRecords + loopCounter + 4);
      *(undefined4 *)(recordDest + 0xc) = recordWord0;
    }
    else {
      *(byte *)(compiler[10] + 0x15c) = *(byte *)(compiler[10] + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f))
      ;
    }
    loopIndex = loopIndex + 1;
    loopCounter = loopCounter + 0x18;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  uStack00000020 = firstConstKind;
  uStack00000024 = firstConstValue;
  uStack00000028 = firstConstWord2;
  uStack0000002c = firstConstWord3;
  uStack00000030 = firstConstWord4;
  uStack00000034 = firstConstWord5;
  cachedInst = (undefined4 *)HashTable__find(aiStack_9c[constCount],compiler[10]);
  if (cachedInst == (undefined4 *)0x0) {
    arena = *(undefined4 *)(*compiler + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    cachedInst = allocation + 1;
    IRLoadConst__ctor_109938(cachedInst,*compiler);
    if ((*(uint *)(*(int *)(*compiler + 0x6c4) + 0x30) & 0x10000) == 0) {
      newInstId = RegisterMap__nextTempIndex(compiler);
      allocation[0x26] = newInstId;
      allocation[0x27] = 0xc;
    }
    else {
      constantSlot = Emitter__allocateConstantSlot(compiler,constRecords[0],0,keyRecordCursor,loopCounter,loopIndex,*compiler);
      allocation[0x26] = constantSlot;
      allocation[0x27] = 0xc;
    }
    loopIndex = 0;
    loopCounterB = 4;
    instRecordCursor = allocation + 5;
    loopCounter = 0;
    do {
      if ((int)loopIndex < constCount) {
        *(byte *)(allocation + 0x58) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(allocation + 0x58);
        recordWord = *(undefined4 *)((int)constRecords + loopCounter);
        instRecordCursor[4] = *(undefined4 *)((int)constRecords + loopCounter + 4);
        instRecordCursor[3] = recordWord;
      }
      else {
        *(byte *)(allocation + 0x58) = *(byte *)(allocation + 0x58) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x18;
      instRecordCursor = instRecordCursor + 6;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
    blockList = *(int **)(*(int *)(*compiler + 0x6c4) + 0x3a0);
    (**(code **)(*blockList + 0xc))(blockList,cachedInst);
    ((int (*)())ConstRecord__insertSwizzleVariants)(compiler,constCount,cachedInst);
  }
  return cachedInst;
}
#undef local_8c

/* Compiler__getOrCreateLoadConst4 @ 0xf5248 (376 bytes) */
int Compiler__getOrCreateLoadConst4(compiler, constVec0, constVec1, constVec2, constVec3, constVec4, constVec5, constVec6)
  undefined4 compiler;
  undefined4 constVec0;
  undefined4 constVec1;
  undefined4 constVec2;
  undefined4 constVec3;
  undefined4 constVec4;
  undefined4 constVec5;
  undefined4 constVec6;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = constVec0;
  uStack00000020 = constVec1;
  uStack00000024 = constVec2;
  uStack00000028 = constVec3;
  uStack0000002c = constVec4;
  uStack00000030 = constVec5;
  uStack00000034 = constVec6;
  uVar1 = ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,4,constVec0,constVec1,constVec2,constVec3,constVec4,constVec5);
  return uVar1;
}

/* Compiler__getOrCreateLoadConst3 @ 0xf53c0 (396 bytes) */
int Compiler__getOrCreateLoadConst3(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,3,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateLoadConst2 @ 0xf554c (352 bytes) */
int Compiler__getOrCreateLoadConst2(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,2,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateLoadConst1 @ 0xf56ac (324 bytes) */
int Compiler__getOrCreateLoadConst1(compiler, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  undefined4 compiler;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  return ((int (*)())Compiler__getOrCreateLoadConstN)(compiler,1,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* RegisterMap__findConstVector @ 0xf57f0 (540 bytes) */
int RegisterMap__findConstVector(registerMap, values, selectBytes, unusedArg)
  int *registerMap;
  int values;
  char *selectBytes;
  undefined4 unusedArg;
{
  bool notLastLane;
  uint selectedComponent;
  uint loopCounterC;
  int loopCounter;
  bool notLastWord;
  float wantedValue;
  int recordCursor;
  uint vectorSize;
  int *vectorSlot;
  int canEncode;
  char *selectByteCursor;
  uint loopIndex;
  uint *instVector;
  int candidateInst;
  int loopCounterB;
  undefined4 selectBytesCopy [8];
  
  if (registerMap[7] != 0) {
    loopIndex = 0;
    do {
      instVector = (uint *)registerMap[8];
      if (loopIndex < *instVector) {
        vectorSize = instVector[1];
        if (vectorSize <= loopIndex) {
          _memset(vectorSize * 4 + instVector[2],0,(loopIndex - vectorSize) * 4 + 4);
          instVector[1] = loopIndex + 1;
        }
        vectorSlot = (int *)(loopIndex * 4 + instVector[2]);
      }
      else {
        vectorSlot = (int *)Vector__elementRefGrow(instVector,loopIndex);
      }
      candidateInst = *vectorSlot;
      loopCounter = 0;
      selectByteCursor = selectBytes;
      do {
        if (*selectByteCursor != '\x04') {
          loopCounterC = 0;
          loopCounterB = 4;
          recordCursor = candidateInst;
          while (((((int)*(char *)(candidateInst + 0x15c) >> (loopCounterC & 0x3f) & 1U) == 0 ||
                  (*(int *)(recordCursor + 0x1c) != 2)) ||
                 (*(float *)(recordCursor + 0x20) != *(float *)(values + loopCounter)))) {
            loopCounterC = loopCounterC + 1;
            recordCursor = recordCursor + 0x18;
            loopCounterB = loopCounterB + -1;
            if (loopCounterB == 0) goto LAB_000f59bc;
          }
        }
        notLastWord = loopCounter != 0xc;
        selectByteCursor = selectByteCursor + 1;
        loopCounter = loopCounter + 4;
      } while (notLastWord);
      loopCounter = 0;
      selectBytesCopy[0] = *(undefined4 *)selectBytes;
      selectByteCursor = selectBytes;
      do {
        selectedComponent = (uint)*(byte *)((int)selectBytesCopy + loopCounter);
        if (((selectedComponent != 4) && (((int)*(char *)(candidateInst + 0x15c) >> (selectedComponent & 0x3f) & 1U) != 0)) &&
           (wantedValue = *(float *)(values + loopCounter * 4),
           *(float *)(selectedComponent * 0x18 + candidateInst + 0x20) != wantedValue)) {
          loopCounterB = 4;
          loopCounterC = 0;
          recordCursor = candidateInst;
          do {
            if (((((int)*(char *)(candidateInst + 0x15c) >> (loopCounterC & 0x3f) & 1U) != 0) &&
                (*(int *)(recordCursor + 0x1c) == 2)) && (*(float *)(recordCursor + 0x20) == wantedValue)) {
              *selectByteCursor = (char)loopCounterC;
              break;
            }
            loopCounterC = loopCounterC + 1;
            recordCursor = recordCursor + 0x18;
            loopCounterB = loopCounterB + -1;
          } while (loopCounterB != 0);
        }
        notLastLane = loopCounter != 3;
        selectByteCursor = selectByteCursor + 1;
        loopCounter = loopCounter + 1;
      } while (notLastLane);
      canEncode = (**(code **)(**(int **)(*registerMap + 0x30c) + 0x100))
                        (*(int **)(*registerMap + 0x30c),selectBytes);
      if (canEncode != 0) {
        *(undefined4 *)(candidateInst + 0x9c) = DAT_001aa860;
        return candidateInst;
      }
LAB_000f59bc:
      loopIndex = loopIndex + 1;
    } while (loopIndex < (uint)registerMap[7]);
  }
  return 0;
}

/* IRInst__canFoldConstantSource @ 0xf5a0c (512 bytes) */
int IRInst__canFoldConstantSource(inst, operandIndex, inst2, program)
  int inst;
  int operandIndex;
  undefined4 inst2;
  int program;
{
  uint selectedComponent;
  int inst2Foldable;
  int operandRecordB;
  int operandRecord;
  int sourceDef;
  bool notLastLane;
  uint negateFlag;
  int iVar3;
  undefined4 foldable;
  int constEncodable;
  uint selectedComponentB;
  int *hardwareInfo;
  int loopCounter;
  double constValue;
  
  inst2Foldable = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),inst2);
  if (inst2Foldable == 0) goto LAB_000f5a8c;
  negateFlag = *(uint *)(operandIndex * 0x18 + inst + 0xa0) & 1;
  IRInst__getOperandRecord(inst2,0);
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  iVar3 = *(int *)(sourceDef + 0x98);
  if (iVar3 == 0xc) {
LAB_000f5b30:
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    hardwareInfo = *(int **)(*(int *)(program + 8) + 0x30c);
    loopCounter = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst2,0);
      if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        selectedComponentB = (uint)*(byte *)(loopCounter + operandRecord + 0x10);
        if (selectedComponentB != 4) {
          if (((int)*(char *)(sourceDef + 0x15c) >> (selectedComponentB & 0x3f) & 1U) == 0) goto LAB_000f5a8c;
          if (negateFlag == 0) {
            constValue = (double)*(float *)(selectedComponentB * 0x18 + sourceDef + 0x20);
          }
          else {
            constValue = -(double)*(float *)(selectedComponentB * 0x18 + sourceDef + 0x20);
          }
          constEncodable = (**(code **)(*hardwareInfo + 0xf0))(constValue,hardwareInfo);
          if (constEncodable == 0) goto LAB_000f5a8c;
        }
      }
      notLastLane = loopCounter != 3;
      loopCounter = loopCounter + 1;
    } while (notLastLane);
LAB_000f5b28:
    foldable = 1;
  }
  else {
    if (iVar3 == 0x33) {
      if (negateFlag == 0) {
        sourceDef = IRInst__getOperandSource(inst,operandIndex);
        loopCounter = 0;
        hardwareInfo = *(int **)(*(int *)(program + 8) + 0x30c);
        do {
          operandRecord = IRInst__getOperandRecord(inst2,0);
          if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
            operandRecordB = IRInst__getOperandRecord(inst,operandIndex);
            selectedComponent = (uint)*(byte *)(loopCounter + operandRecordB + 0x10);
            if ((selectedComponent != 4) &&
               (operandRecordB = (**(code **)(*hardwareInfo + 0xf0))
                                  ((double)*(float *)(selectedComponent * 0x18 + sourceDef + 0x20),hardwareInfo),
               operandRecordB == 0)) goto LAB_000f5a8c;
          }
          notLastLane = loopCounter != 3;
          loopCounter = loopCounter + 1;
        } while (notLastLane);
        goto LAB_000f5b28;
      }
    }
    else if (iVar3 == 2) goto LAB_000f5b30;
LAB_000f5a8c:
    foldable = 0;
  }
  return foldable;
}

/* IRInst__sourceMatchesConstant @ 0xf5c0c (228 bytes) */
int IRInst__sourceMatchesConstant(inst, operandIndex, skipLaneMask, wantedValues)
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 skipLaneMask;
  int *wantedValues;
{
  int loopCounter;
  int operandRecord;
  unsigned int ghidra_home[8] = { inst, operandIndex, skipLaneMask, wantedValues, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint laneComponent;
  int *sourceVReg;
  int isConstantSource;
  undefined4 result;
  int loopCounterB;
  char *skipMaskCursor;
  undefined4 operandSelectBytes [9];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = skipLaneMask;
  sourceVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
  isConstantSource = (**(code **)(*sourceVReg + 0x48))(sourceVReg);
  if (isConstantSource == 0) {
LAB_000f5cd8:
    result = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    skipMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    operandSelectBytes[0] = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    do {
      if (((*skipMaskCursor == '\0') && (laneComponent = (uint)*(byte *)((int)operandSelectBytes + loopCounterB), laneComponent < 4)) &&
         ((((int)*(char *)(sourceVReg + 0x57) >> (laneComponent & 0x3f) & 1U) == 0 ||
          (sourceVReg[laneComponent * 6 + 8] != *wantedValues)))) goto LAB_000f5cd8;
      loopCounterB = loopCounterB + 1;
      skipMaskCursor = skipMaskCursor + 1;
      wantedValues = wantedValues + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    result = 1;
  }
  return result;
}

/* IRInst__getUniformSourceConstant @ 0xf5cf0 (412 bytes) */
int IRInst__getUniformSourceConstant(inst, srcIndex, laneMask, outConst)
  int inst;
  int srcIndex;
  undefined4 laneMask;
  int *outConst;
{
  int lanesLeft;
  int srcRecord;
  unsigned int ghidra_home[8] = { inst, srcIndex, laneMask, outConst, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool foundLane;
  int *a0;
  int isConstant;
  int lane;
  char *laneMaskCursor;
  uint readComponent;
  undefined4 srcSelectWord;
  int constKind;
  int laneValueBits;
  int laneWord9;
  int laneWord10;
  int laneWord11;
  int laneWord12;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = laneMask;
  a0 = (int *)IRInst__getOperandSource(inst,srcIndex);
  isConstant = (**(code **)(*a0 + 0x48))(a0);
  if (isConstant != 0) {
    srcRecord = IRInst__getOperandRecord(inst,srcIndex);
    foundLane = false;
    lane = 0;
    laneMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    srcSelectWord = *(undefined4 *)(srcRecord + 0x10);
    lanesLeft = 4;
    do {
      if ((*laneMaskCursor == '\0') && (readComponent = (uint)*(byte *)((int)&srcSelectWord + lane), readComponent < 4)) {
        laneValueBits = a0[readComponent * 6 + 8];
        laneWord9 = a0[readComponent * 6 + 9];
        laneWord10 = a0[readComponent * 6 + 10];
        constKind = a0[readComponent * 6 + 7];
        laneWord12 = a0[readComponent * 6 + 0xc];
        laneWord11 = a0[readComponent * 6 + 0xb];
        if (a0[readComponent * 6 + 7] != 2) {
          return 0;
        }
        if (((int)*(char *)(a0 + 0x57) >> (readComponent & 0x3f) & 1U) == 0) {
          return 0;
        }
        if (foundLane) {
          if (*outConst != 2) {
            return 0;
          }
          if (laneValueBits != outConst[1]) {
            return 0;
          }
          foundLane = true;
        }
        else {
          foundLane = true;
          *outConst = 2;
          outConst[1] = laneValueBits;
        }
      }
      lane = lane + 1;
      laneMaskCursor = laneMaskCursor + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    if (foundLane) {
      if (((*(uint *)(srcIndex * 0x18 + inst + 0xa0) & 2) != 0) && (GH_U2F((unsigned int)(outConst[1])) < 0.0)) {
        outConst[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(outConst[1]))));
      }
      if ((*(uint *)(srcIndex * 0x18 + inst + 0xa0) & 1) != 0) {
        outConst[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(outConst[1]))));
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* IRInst__operandIsNonNegativeFloatConst @ 0xf5e8c (264 bytes) */
int IRInst__operandIsNonNegativeFloatConst(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int loopCounter;
  int operandRecord;
  int *sourceVReg;
  int isConstantSource;
  undefined4 result;
  int loopCounterB;
  uint laneComponent;
  undefined4 operandSelectBytes;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  sourceVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
  isConstantSource = (**(code **)(*sourceVReg + 0x48))(sourceVReg);
  if (isConstantSource == 0) {
LAB_000f5f7c:
    result = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    operandSelectBytes = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    do {
      laneComponent = (uint)*(byte *)((int)&operandSelectBytes + loopCounterB);
      if (laneComponent < 4) {
        local_30 = GH_U2F((unsigned int)(sourceVReg[laneComponent * 6 + 8]));
        local_2c = sourceVReg[laneComponent * 6 + 9];
        local_28 = sourceVReg[laneComponent * 6 + 10];
        local_34 = sourceVReg[laneComponent * 6 + 7];
        local_20 = sourceVReg[laneComponent * 6 + 0xc];
        local_24 = sourceVReg[laneComponent * 6 + 0xb];
        if (((sourceVReg[laneComponent * 6 + 7] != 2) || (((int)*(char *)(sourceVReg + 0x57) >> (laneComponent & 0x3f) & 1U) == 0))
           || (GH_U2F((unsigned int)(sourceVReg[laneComponent * 6 + 8])) < 0.0)) goto LAB_000f5f7c;
      }
      loopCounterB = loopCounterB + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    result = 1;
  }
  return result;
}

/* RegisterMap__findConstVectorExact @ 0xf5f94 (304 bytes) */
int RegisterMap__findConstVectorExact(registerMap, values, selectBytes, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int registerMap;
  int values;
  byte *selectBytes;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  uint selectedComponent;
  uint vectorSize;
  int *vectorSlot;
  int candidateInst;
  int recordAddr;
  int loopCounter;
  byte *selectByteCursor;
  uint loopIndex;
  uint *instVector;
  int loopCounterB;
  
  if (*(int *)(registerMap + 0x1c) != 0) {
    loopIndex = 0;
    do {
      instVector = *(uint **)(registerMap + 0x20);
      if (loopIndex < *instVector) {
        vectorSize = instVector[1];
        if (vectorSize <= loopIndex) {
          _memset(vectorSize * 4 + instVector[2],0,(loopIndex - vectorSize) * 4 + 4);
          instVector[1] = loopIndex + 1;
        }
        vectorSlot = (int *)(loopIndex * 4 + instVector[2]);
      }
      else {
        vectorSlot = (int *)Vector__elementRefGrow(instVector,loopIndex);
      }
      candidateInst = *vectorSlot;
      loopCounterB = 4;
      loopCounter = 0;
      selectByteCursor = selectBytes;
      while ((selectedComponent = (uint)*selectByteCursor, selectedComponent == 4 ||
             (((((int)*(char *)(candidateInst + 0x15c) >> (selectedComponent & 0x3f) & 1U) != 0 &&
               (recordAddr = selectedComponent * 0x18 + candidateInst, *(int *)(recordAddr + 0x1c) == 2)) &&
              (*(float *)(recordAddr + 0x20) == *(float *)(loopCounter + values)))))) {
        selectByteCursor = selectByteCursor + 1;
        loopCounter = loopCounter + 4;
        loopCounterB = loopCounterB + -1;
        if (loopCounterB == 0) {
          *(undefined4 *)(candidateInst + 0x9c) = DAT_001aa860;
          return candidateInst;
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *(uint *)(registerMap + 0x1c));
  }
  return 0;
}

/* Program__dumpConstantRegisters @ 0xf60c4 (388 bytes) */
int Program__dumpConstantRegisters(program, compiler)
  int program;
  int compiler;
{
  undefined4 destRegisterId;
  uint loopCounter;
  bool notLastLane;
  uint recordCount;
  int *recordSlot;
  undefined4 hwRegisterNumber;
  int operandRecord;
  undefined1 *logArg;
  uint recordIndex;
  char *registerFileName;
  undefined4 staleArgR9;
  undefined4 staleArgR10;
  uint nextRecordIndex;
  uint *constRecords;
  int constRecord;
  undefined1 auStack_b8 [148];
  
  constRecords = *(uint **)(program + 0x3c8);
  recordCount = constRecords[1];
  recordIndex = 0;
  if (recordCount != 0) {
    do {
      if (recordIndex < *constRecords) {
        if (recordCount <= recordIndex) {
          _memset(recordCount * 4 + constRecords[2],0,(recordIndex - recordCount) * 4 + 4);
          constRecords[1] = recordIndex + 1;
        }
        recordSlot = (int *)(recordIndex * 4 + constRecords[2]);
      }
      else {
        recordSlot = (int *)Vector__elementRefGrow(constRecords,recordIndex);
      }
      nextRecordIndex = recordIndex + 1;
      constRecord = *recordSlot;
      if ((((*(uint *)(constRecord + 0x14) & 1) != 0) && ((*(byte *)(constRecord + 0x15c) & 1) != 0)) &&
         (*(int *)(constRecord + 0x98) == 0xc)) {
        loopCounter = 0;
        hwRegisterNumber = (**(code **)(**(int **)(compiler + 0x30c) + 0x158))
                          (*(int **)(compiler + 0x30c),*(undefined4 *)(constRecord + 0x94),
                           *(undefined4 *)(constRecord + 0x1c),0,compiler);
        operandRecord = IRInst__getOperandRecord(constRecord,0);
        *(undefined4 *)(operandRecord + 8) = hwRegisterNumber;
        logArg = *(undefined1 **)(constRecord + 0x14c);
        destRegisterId = *(undefined4 *)(constRecord + 0x94);
        registerFileName = "k";
        Compiler__logf(compiler,"(%d)  %d, regnum = %s[%d]: ",logArg,recordIndex,"k",destRegisterId,staleArgR9,staleArgR10);
        do {
          if (((int)*(char *)(constRecord + 0x15c) >> (loopCounter & 0x3f) & 1U) == 0) break;
          logArg = auStack_b8;
          Compiler__logf(compiler,"  %s ",logArg,recordIndex,registerFileName,destRegisterId,staleArgR9,staleArgR10);
          notLastLane = loopCounter != 3;
          loopCounter = loopCounter + 1;
        } while (notLastLane);
        Compiler__logf(compiler,"\n",logArg,recordIndex,registerFileName,destRegisterId,staleArgR9,staleArgR10);
      }
      recordCount = constRecords[1];
      recordIndex = nextRecordIndex;
    } while (nextRecordIndex < recordCount);
  }
  return;
}

/* Compiler__getOrCreateConstVectorN @ 0xf6248 (532 bytes) */
int Compiler__getOrCreateConstVectorN(owner, constCount, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  int owner;
  int constCount;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  undefined4 recordWord0B;
  undefined4 newInstId;
  int loopCounterC;
  int loopCounterB;
  int loopCounter;
  int foundEntry;
  undefined4 recordWord0;
  int recordDest;
  int *vectorSlot;
  int iVar4;
  uint loopIndex;
  int recordCursor;
  int constInst;
  int loopCounterD;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  /* issue #64 live-repro: called below as auStack_8c[constCount] with constCount observed as 4 - one
   * past this array's declared 4 elements (indices 0-3). Confirmed in stock's own disassembly: the
   * word this 5th index reads (entry-sp-0x8c+0x10, by this array's own hex name) is the exact same
   * stack slot as local_7c (entry-sp-0x7c), which the very next line fills with a real value
   * (*(owner+0x14)) - stock never writes a separate word for index 0 either (genuinely padding/
   * unused there), so this is the same locals-that-must-be-contiguous defect as elsewhere this
   * session, just one array cell short instead of a raw address. Left separate, auStack_8c[4] read
   * whatever unrelated word happened to follow it on this build's stack instead of local_7c's real
   * value, corrupting a callback-table lookup several frames down (HashTable__find called through a
   * garbage function pointer, jumping into stack memory as code). Extended to 5 elements; local_7c
   * aliased to index 4 so both names reach the same word. */
  undefined4 auStack_8c [5];
#define local_7c auStack_8c[4]
  undefined4 constRecords [26];
  
  auStack_8c[1] = *(undefined4 *)(owner + 8);
  auStack_8c[2] = *(undefined4 *)(owner + 0xc);
  loopCounterC = 4;
  loopCounterB = 0;
  loopIndex = 0;
  constRecords[0] = operandWord0;
  constRecords[1] = operandWord1;
  auStack_8c[3] = *(undefined4 *)(owner + 0x10);
  local_7c = *(undefined4 *)(owner + 0x14);
  do {
    if ((int)loopIndex < constCount) {
      *(byte *)(*(int *)(owner + 0x28) + 0x15c) =
           (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(*(int *)(owner + 0x28) + 0x15c);
      recordWord0 = *(undefined4 *)((int)constRecords + loopCounterB);
      recordDest = loopCounterB + 0x10 + *(int *)(owner + 0x28);
      *(undefined4 *)(recordDest + 0x10) = *(undefined4 *)((int)constRecords + loopCounterB + 4);
      *(undefined4 *)(recordDest + 0xc) = recordWord0;
    }
    else {
      *(byte *)(*(int *)(owner + 0x28) + 0x15c) =
           *(byte *)(*(int *)(owner + 0x28) + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f));
    }
    loopIndex = loopIndex + 1;
    loopCounterB = loopCounterB + 0x18;
    loopCounterC = loopCounterC + -1;
  } while (loopCounterC != 0);
  uStack00000020 = operandWord0;
  uStack00000024 = operandWord1;
  uStack00000028 = operandWord2;
  uStack0000002c = operandWord3;
  uStack00000030 = operandWord4;
  uStack00000034 = operandWord5;
  foundEntry = HashTable__find(auStack_8c[constCount],*(undefined4 *)(owner + 0x28));
  if (foundEntry == 0) {
    newInstId = RegisterMap__nextTempIndex(owner);
    iVar4 = VRegPool__create(owner,0xc,newInstId,0);
    vectorSlot = *(int **)(iVar4 + 0x18);
    if (*vectorSlot == 0) {
      vectorSlot = (int *)Vector__elementRefGrow(vectorSlot,0);
    }
    else {
      if (vectorSlot[1] == 0) {
        *(undefined4 *)vectorSlot[2] = 0;
        vectorSlot[1] = 1;
      }
      vectorSlot = (int *)vectorSlot[2];
    }
    constInst = *vectorSlot;
    loopCounterD = 4;
    loopIndex = 0;
    recordCursor = constInst + 0x10;
    loopCounter = 0;
    do {
      if ((int)loopIndex < constCount) {
        *(byte *)(constInst + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(constInst + 0x15c);
        recordWord0B = *(undefined4 *)((int)constRecords + loopCounter);
        *(undefined4 *)(recordCursor + 0x10) = *(undefined4 *)((int)constRecords + loopCounter + 4);
        *(undefined4 *)(recordCursor + 0xc) = recordWord0B;
      }
      else {
        *(byte *)(constInst + 0x15c) = *(byte *)(constInst + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x18;
      recordCursor = recordCursor + 0x18;
      loopCounterD = loopCounterD + -1;
    } while (loopCounterD != 0);
    ((int (*)())ConstRecord__insertSwizzleVariants)(owner,constCount,constInst);
  }
  else {
    iVar4 = *(int *)(foundEntry + 0x8c);
  }
  return iVar4;
}
#undef local_7c

/* Compiler__getOrCreateConstVector4 @ 0xf645c (376 bytes) */
int Compiler__getOrCreateConstVector4(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 uVar1;
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  uVar1 = ((int (*)())Compiler__getOrCreateConstVectorN)(owner,4,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
  return uVar1;
}

/* Compiler__getOrCreateConstVector3 @ 0xf65d4 (396 bytes) */
int Compiler__getOrCreateConstVector3(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,3,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateConstVector2 @ 0xf6760 (352 bytes) */
int Compiler__getOrCreateConstVector2(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  undefined4 operandWord6Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  operandWord6Home = operandWord6;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,2,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Compiler__getOrCreateConstVector1 @ 0xf68c0 (324 bytes) */
int Compiler__getOrCreateConstVector1(owner, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  undefined4 owner;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  undefined4 operandWord0Home;
  undefined4 operandWord1Home;
  undefined4 operandWord2Home;
  undefined4 operandWord3Home;
  undefined4 operandWord4Home;
  undefined4 operandWord5Home;
  
  operandWord0Home = operandWord0;
  operandWord1Home = operandWord1;
  operandWord2Home = operandWord2;
  operandWord3Home = operandWord3;
  operandWord4Home = operandWord4;
  operandWord5Home = operandWord5;
  return ((int (*)())Compiler__getOrCreateConstVectorN)(owner,1,operandWord0,operandWord1,operandWord2,operandWord3,operandWord4,operandWord5);
}

/* Program__findOrCreateConstInst @ 0xf6a04 (588 bytes) */
int Program__findOrCreateConstInst(program, constWords, selectWord)
  int program;
  undefined4 constWords;
  undefined4 selectWord;
{
  undefined4 *candidateInst;
  int *newEntryVectorOrSlot;
  undefined4 recordWord1;
  int newEntry;
  int registerMap;
  uint vectorSize;
  uint loopCounterE;
  uint loopCounterD;
  int loopCounterC;
  int loopCounter;
  undefined4 *allocation;
  undefined4 arena;
  unsigned int ghidra_home[8] = { program, constWords, selectWord, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *recordSource;
  int encodable;
  uint vectorCapacityCursor;
  undefined4 newInstId;
  int *vectorSlot;
  undefined4 *recordCursor;
  char *selectByteCursor;
  int loopCounterB;
  int compiler;
  undefined4 *resultInst;
  uint cachedInstCount;
  undefined4 registerMapForNew;
  uint laneBit;
  uint *instVector;
  int constKey;
  int localConstRecords [30];
  
  resultInst = (undefined4 *)0x0;
  compiler = *(int *)(program + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWord;
  encodable = (**(code **)(**(int **)(compiler + 0x30c) + 0xe8))
                    (*(int **)(compiler + 0x30c),constWords,&constKey,selectWord,compiler);
  if (encodable != 0) {
    ConstRecords__fillFloat4(constWords,localConstRecords);
    registerMap = *(int *)(program + 0x3ac);
    loopCounterE = 0;
    cachedInstCount = *(uint *)(*(int *)(registerMap + 0x18) + 4);
    if (0 < (int)cachedInstCount) {
      while( true ) {
        instVector = *(uint **)(registerMap + 0x18);
        if (loopCounterE < *instVector) {
          vectorCapacityCursor = instVector[1];
          if (vectorCapacityCursor <= loopCounterE) {
            _memset(vectorCapacityCursor * 4 + instVector[2],0,(loopCounterE - vectorCapacityCursor) * 4 + 4);
            instVector[1] = loopCounterE + 1;
          }
          vectorSlot = (int *)(loopCounterE * 4 + instVector[2]);
        }
        else {
          vectorSlot = (int *)Vector__elementRefGrow(instVector,loopCounterE);
        }
        candidateInst = (undefined4 *)*vectorSlot;
        if (candidateInst[0x4b] == constKey) {
          selectByteCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
          recordCursor = candidateInst + 4;
          loopCounterB = 0;
          loopCounter = 4;
          while ((*selectByteCursor == '\x04' ||
                 ((recordCursor[3] == *(int *)((int)localConstRecords + loopCounterB) &&
                  (recordCursor[4] == *(int *)((int)localConstRecords + loopCounterB + 4)))))) {
            loopCounter = loopCounter + -1;
            loopCounterB = loopCounterB + 0x18;
            recordCursor = recordCursor + 6;
            selectByteCursor = selectByteCursor + 1;
            if (loopCounter == 0) {
              if (candidateInst != (undefined4 *)0x0) {
                return candidateInst;
              }
              goto LAB_000f6b68;
            }
          }
        }
        loopCounterE = loopCounterE + 1;
        if (cachedInstCount == loopCounterE) break;
        registerMap = *(int *)(program + 0x3ac);
      }
    }
LAB_000f6b68:
    if ((*(uint *)(program + 0x30) & 8) == 0) {
      registerMapForNew = *(undefined4 *)(program + 0x3ac);
      newInstId = RegisterMap__nextTempIndex(registerMapForNew);
      newEntry = VRegPool__create(registerMapForNew,0x33,newInstId,0);
      newEntryVectorOrSlot = *(int **)(newEntry + 0x18);
      if (*newEntryVectorOrSlot == 0) {
        newEntryVectorOrSlot = (int *)Vector__elementRefGrow(newEntryVectorOrSlot,0);
      }
      else {
        if (newEntryVectorOrSlot[1] == 0) {
          *(undefined4 *)newEntryVectorOrSlot[2] = 0;
          newEntryVectorOrSlot[1] = 1;
        }
        newEntryVectorOrSlot = (int *)newEntryVectorOrSlot[2];
      }
      resultInst = (undefined4 *)*newEntryVectorOrSlot;
    }
    else {
      arena = *(undefined4 *)(compiler + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      resultInst = allocation + 1;
      IRLoadConst__ctor_109938(resultInst,*(undefined4 *)(program + 8));
      newInstId = RegisterMap__nextTempIndex(*(undefined4 *)(program + 0x3ac));
      allocation[0x26] = newInstId;
      allocation[0x27] = 0x33;
      (**(code **)(**(int **)(program + 0x3a0) + 0xc))(*(int **)(program + 0x3a0),resultInst);
    }
    resultInst[0x4b] = constKey;
    instVector = *(uint **)(*(int *)(program + 0x3ac) + 0x18);
    vectorSize = instVector[1];
    if (vectorSize < *instVector) {
      _memset(vectorSize * 4 + instVector[2],0,4);
      vectorSlot = (int *)(vectorSize * 4 + instVector[2]);
      instVector[1] = vectorSize + 1;
    }
    else {
      vectorSlot = (int *)Vector__elementRefGrow(instVector,vectorSize);
    }
    *vectorSlot = (int)resultInst;
    loopCounterC = 4;
    loopCounterD = 0;
    recordCursor = resultInst + 4;
    loopCounter = 0;
    do {
      recordSource = (undefined4 *)((int)localConstRecords + loopCounter);
      recordWord1 = *(undefined4 *)((int)localConstRecords + loopCounter + 4);
      loopCounter = loopCounter + 0x18;
      recordCursor[3] = *recordSource;
      recordCursor[4] = recordWord1;
      laneBit = loopCounterD & 0x3f;
      loopCounterD = loopCounterD + 1;
      recordCursor = recordCursor + 6;
      *(byte *)(resultInst + 0x57) = (byte)(1 << laneBit) | *(byte *)(resultInst + 0x57);
      loopCounterC = loopCounterC + -1;
    } while (loopCounterC != 0);
  }
  return resultInst;
}

/* IRInst__setConstantOperand @ 0xf6d14 (2568 bytes) */
int IRInst__setConstantOperand(inst, program, operandIndex, constOperand0Kind, constOperand0Value, constOperand0Word2, constOperand0Word3, constOperand0Word4, constOperand0Word5, constOperand1Kind, constOperand1Value, constOperand1Word2, constOperand1Word3, constOperand1Word4, constOperand1Word5, constOperand2Kind, constOperand2Value, constOperand2Word2, constOperand2Word3, constOperand2Word4, constOperand2Word5, constOperand3Kind, constOperand3Value)
  undefined4 inst;
  int program;
  undefined4 operandIndex;
  int constOperand0Kind;
  undefined4 constOperand0Value;
  undefined4 constOperand0Word2;
  undefined4 constOperand0Word3;
  undefined4 constOperand0Word4;
  undefined4 constOperand0Word5;
  int constOperand1Kind;
  undefined4 constOperand1Value;
  undefined4 constOperand1Word2;
  undefined4 constOperand1Word3;
  undefined4 constOperand1Word4;
  undefined4 constOperand1Word5;
  int constOperand2Kind;
  undefined4 constOperand2Value;
  undefined4 constOperand2Word2;
  undefined4 constOperand2Word3;
  undefined4 constOperand2Word4;
  undefined4 constOperand2Word5;
  int constOperand3Kind;
  undefined4 constOperand3Value;
{
  int compareCount;
  int **sortCursor;
  int **operandCursor;
  int rankFillCount;
  int operandRecordB;
  int loopCounterD;
  int loopCounterC;
  int operandRecord;
  int loopCounter;
  uint programFlags;
  uint operandKindA;
  int existingConstInst;
  int uniqueCount;
  int existingInstRecord;
  bool moreToSort;
  bool operandLess;
  undefined4 constantHandle;
  unsigned int ghidra_home[8] = { inst, program, operandIndex, constOperand0Kind, constOperand0Value, constOperand0Word2, constOperand0Word3, constOperand0Word4 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined1 swapByteNext;
  undefined1 swapByteCurrent;
  uint laneByte;
  int lanesLeft;
  int **fillCursor;
  int loopCounterB;
  int sortPassIndex;
  undefined4 loadConstSource;
  int *candidateOperand;
  uint *operandB;
  int previousLane;
  uint *operandA;
  undefined4 compiler;
  bool notLastWord;
  int laneIndex;
  int existingSelect;
  undefined1 uniqueRank [4];
  undefined4 finalSelect;
  undefined4 laneUniqueIndex;
  undefined4 sortOrder;
  int *local_274;
  int *operandPtrTable [11];
  undefined4 constVec2Op0Kind;
  undefined4 constVec2Op0Value;
  undefined4 constVec2Op0Word2;
  undefined4 constVec2Op0Word3;
  undefined4 constVec2Op0Word4;
  undefined4 constVec2Op0Word5;
  undefined4 constVec1Op0Kind;
  undefined4 constVec1Op0Value;
  undefined4 constVec1Op0Word2;
  undefined4 constVec1Op0Word3;
  undefined4 constVec1Op0Word4;
  undefined4 constVec1Op0Word5;
  undefined4 loadConst4Op3Kind;
  undefined4 loadConst4Op3Value;
  undefined4 loadConst4Op3Word2;
  undefined4 loadConst4Op3Word3;
  undefined4 loadConst4Op3Word4;
  undefined4 loadConst4Op3Word5;
  undefined4 loadConst4Op2Kind;
  undefined4 loadConst4Op2Value;
  undefined4 loadConst4Op2Word2;
  undefined4 loadConst4Op2Word3;
  undefined4 loadConst4Op2Word4;
  undefined4 loadConst4Op2Word5;
  undefined4 loadConst4Op1Kind;
  undefined4 loadConst4Op1Value;
  undefined4 loadConst4Op1Word2;
  undefined4 loadConst4Op1Word3;
  undefined4 loadConst4Op1Word4;
  undefined4 loadConst4Op1Word5;
  undefined4 loadConst4Op0Kind;
  undefined4 loadConst4Op0Value;
  undefined4 loadConst4Op0Word2;
  undefined4 loadConst4Op0Word3;
  undefined4 loadConst4Op0Word4;
  undefined4 loadConst4Op0Word5;
  undefined4 constVec4Op3Kind;
  undefined4 constVec4Op3Value;
  undefined4 constVec4Op3Word2;
  undefined4 constVec4Op3Word3;
  undefined4 constVec4Op3Word4;
  undefined4 constVec4Op3Word5;
  undefined4 loadConst3Op1Kind;
  undefined4 loadConst3Op1Value;
  undefined4 loadConst3Op1Word2;
  undefined4 loadConst3Op1Word3;
  undefined4 loadConst3Op1Word4;
  undefined4 loadConst3Op1Word5;
  undefined4 loadConst3Op0Kind;
  undefined4 loadConst3Op0Value;
  undefined4 loadConst3Op0Word2;
  undefined4 loadConst3Op0Word3;
  undefined4 loadConst3Op0Word4;
  undefined4 loadConst3Op0Word5;
  undefined4 loadConst2Op1Kind;
  undefined4 loadConst2Op1Value;
  undefined4 loadConst2Op1Word2;
  undefined4 loadConst2Op1Word3;
  undefined4 loadConst2Op1Word4;
  undefined4 loadConst2Op1Word5;
  undefined4 loadConst2Op0Kind;
  undefined4 loadConst2Op0Value;
  undefined4 loadConst2Op0Word2;
  undefined4 loadConst2Op0Word3;
  undefined4 loadConst2Op0Word4;
  undefined4 loadConst2Op0Word5;
  undefined4 loadConst1Op0Kind;
  undefined4 loadConst1Op0Value;
  undefined4 loadConst1Op0Word2;
  undefined4 loadConst1Op0Word3;
  undefined4 loadConst1Op0Word4;
  undefined4 loadConst1Op0Word5;
  undefined4 loadConst3Op2Kind;
  undefined4 loadConst3Op2Value;
  undefined4 loadConst3Op2Word2;
  undefined4 loadConst3Op2Word3;
  undefined4 loadConst3Op2Word4;
  undefined4 loadConst3Op2Word5;
  undefined4 constVec4Op2Kind;
  undefined4 constVec4Op2Value;
  undefined4 constVec4Op2Word2;
  undefined4 constVec4Op2Word3;
  undefined4 constVec4Op2Word4;
  undefined4 constVec4Op2Word5;
  undefined4 constVec4Op1Kind;
  undefined4 constVec4Op1Value;
  undefined4 constVec4Op1Word2;
  undefined4 constVec4Op1Word3;
  undefined4 constVec4Op1Word4;
  undefined4 constVec4Op1Word5;
  undefined4 constVec4Op0Kind;
  undefined4 constVec4Op0Value;
  undefined4 constVec4Op0Word2;
  undefined4 constVec4Op0Word3;
  undefined4 constVec4Op0Word4;
  undefined4 constVec4Op0Word5;
  undefined4 constVec3Op2Kind;
  undefined4 constVec3Op2Value;
  undefined4 constVec3Op2Word2;
  undefined4 constVec3Op2Word3;
  undefined4 constVec3Op2Word4;
  undefined4 constVec3Op2Word5;
  undefined4 constVec3Op1Kind;
  undefined4 constVec3Op1Value;
  undefined4 constVec3Op1Word2;
  undefined4 constVec3Op1Word3;
  undefined4 constVec3Op1Word4;
  undefined4 constVec3Op1Word5;
  undefined4 constVec3Op0Kind;
  undefined4 constVec3Op0Value;
  undefined4 constVec3Op0Word2;
  undefined4 constVec3Op0Word3;
  undefined4 constVec3Op0Word4;
  undefined4 constVec3Op0Word5;
  undefined4 constVec2Op1Kind;
  undefined4 constVec2Op1Value;
  undefined4 constVec2Op1Word2;
  undefined4 constVec2Op1Word3;
  undefined4 constVec2Op1Word4;
  undefined4 constVec2Op1Word5;
  
  compiler = *(undefined4 *)(program + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = operandIndex;
  (*(int *)((unsigned char *)ghidra_home + 12)) = constOperand0Kind;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = constOperand0Value;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = constOperand0Word2;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = constOperand0Word3;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = constOperand0Word4;
  if ((((constOperand0Kind == 2) && (constOperand1Kind == 2)) && (constOperand2Kind == 2)) && (constOperand3Kind == 2)) {
    loopCounterD = 4;
    fillCursor = operandPtrTable + 7;
    do {
      *fillCursor = (int *)0x7ffffffe;
      fillCursor = fillCursor + 1;
      loopCounterD = loopCounterD + -1;
    } while (loopCounterD != 0);
    operandPtrTable[8] = (int *)constOperand1Value;
    operandPtrTable[9] = (int *)constOperand2Value;
    operandPtrTable[10] = (int *)constOperand3Value;
    operandPtrTable[7] = (int *)constOperand0Value;
    existingConstInst = ((int (*)())Program__findOrCreateConstInst)(program,operandPtrTable + 7,DAT_001aa868);
    if (existingConstInst != 0) {
      if ((*(uint *)(program + 0x30) & 8) == 0) {
        IRInst__setOperandRef(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),*(undefined4 *)(existingConstInst + 0x8c));
      }
      else {
        IRInst__setOperandSource(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),existingConstInst,*(uint *)(program + 0x30) >> 7 & 1,compiler);
      }
      existingInstRecord = IRInst__getOperandRecord(existingConstInst,0);
      existingSelect = *(int *)(existingInstRecord + 0x10);
      if (existingSelect != DAT_001aa860) {
        loopCounterB = 0;
        do {
          operandRecord = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
          if (*(byte *)(loopCounterB + operandRecord + 0x10) < 4) {
            operandRecord = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
            laneByte = (uint)*(byte *)(loopCounterB + operandRecord + 0x10);
            uniqueRank[laneByte - 4] = 0;
            *(byte *)(existingConstInst + laneByte + 0xc) =
                 (byte)(1 << (laneByte & 0x3f)) | *(byte *)(existingConstInst + laneByte + 0xc);
          }
          notLastWord = loopCounterB != 3;
          loopCounterB = loopCounterB + 1;
        } while (notLastWord);
        *(int *)(existingConstInst + 0x9c) = existingSelect;
      }
      return;
    }
  }
  candidateOperand = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  laneUniqueIndex = DAT_001aa868;
  operandPtrTable[0] = &constOperand1Kind;
  operandCursor = &local_274;
  laneIndex = 0;
  operandPtrTable[1] = &constOperand2Kind;
  operandPtrTable[2] = &constOperand3Kind;
  operandPtrTable[6] = (int *)PTR_DAT_001e8b70;
  local_274 = candidateOperand;
  operandPtrTable[3] = (int *)PTR_DAT_001e8b70;
  operandPtrTable[4] = (int *)PTR_DAT_001e8b70;
  operandPtrTable[5] = (int *)PTR_DAT_001e8b70;
  uniqueCount = 0;
LAB_000f6f18:
  do {
    sortPassIndex = uniqueCount;
    *(char *)((int)&laneUniqueIndex + laneIndex) = (char)sortPassIndex;
    uniqueCount = sortPassIndex + 1;
    operandPtrTable[sortPassIndex + 3] = candidateOperand;
LAB_000f6f58:
    lanesLeft = 4 - laneIndex;
    do {
      previousLane = laneIndex;
      laneIndex = previousLane + 1;
      operandCursor = operandCursor + 1;
      lanesLeft = lanesLeft + -1;
      if (lanesLeft == 0) {
        sortOrder = DAT_001aa868;
        if (0 < uniqueCount) {
          do {
            compareCount = sortPassIndex + 1;
            loopCounter = 0;
            loopCounterD = 0;
            sortCursor = operandPtrTable + 4;
            if (sortPassIndex < 0) {
              compareCount = 1;
            }
            while (compareCount = compareCount + -1, compareCount != 0) {
              operandA = (uint *)sortCursor[-1];
              operandB = (uint *)*sortCursor;
              operandKindA = *operandA;
              if (operandKindA == *operandB) {
                if (operandKindA == 2) {
                  operandLess = GH_U2F((unsigned int)(operandA[1])) < GH_U2F((unsigned int)(operandB[1]));
                }
                else {
                  operandLess = operandA[1] < operandB[1];
                }
              }
              else {
                operandLess = operandKindA < *operandB;
              }
              if (operandLess) {
                swapByteCurrent = *(undefined1 *)((int)&sortOrder + loopCounter);
                swapByteNext = *(undefined1 *)((int)&sortOrder + loopCounterD + 1);
                *sortCursor = (int *)operandA;
                *(undefined1 *)((int)&sortOrder + loopCounterD + 1) = swapByteCurrent;
                sortCursor[-1] = (int *)operandB;
                *(undefined1 *)((int)&sortOrder + loopCounter) = swapByteNext;
              }
              loopCounter = loopCounter + 1;
              sortCursor = sortCursor + 1;
              loopCounterD = loopCounterD + 1;
            }
            moreToSort = 0 < sortPassIndex;
            sortPassIndex = sortPassIndex + -1;
          } while (moreToSort);
          loopCounterC = 0;
          rankFillCount = uniqueCount;
          do {
            uniqueRank[*(byte *)((int)&sortOrder + loopCounterC)] = (char)loopCounterC;
            loopCounterC = loopCounterC + 1;
            rankFillCount = rankFillCount + -1;
          } while (rankFillCount != 0);
        }
        loopCounterD = 0;
        loopCounterC = 4;
        do {
          *(undefined1 *)((int)&finalSelect + loopCounterD) =
               uniqueRank[*(byte *)((int)&laneUniqueIndex + loopCounterD)];
          loopCounterD = loopCounterD + 1;
          loopCounterC = loopCounterC + -1;
        } while (loopCounterC != 0);
        programFlags = *(uint *)(program + 0x30);
        if ((programFlags & 8) == 0) {
          if (uniqueCount == 2) {
            constVec2Op0Kind = *operandPtrTable[3];
            constVec2Op0Value = operandPtrTable[3][1];
            constVec2Op0Word2 = operandPtrTable[3][2];
            constVec2Op0Word3 = operandPtrTable[3][3];
            constVec2Op0Word5 = operandPtrTable[3][5];
            constVec2Op0Word4 = operandPtrTable[3][4];
            constVec2Op1Kind = *operandPtrTable[4];
            constVec2Op1Value = operandPtrTable[4][1];
            constVec2Op1Word2 = operandPtrTable[4][2];
            constVec2Op1Word3 = operandPtrTable[4][3];
            constVec2Op1Word5 = operandPtrTable[4][5];
            constVec2Op1Word4 = operandPtrTable[4][4];
            constantHandle = ((int (*)())Compiler__getOrCreateConstVector2)(*(undefined4 *)(program + 0x3ac),constVec2Op0Kind,constVec2Op0Value,constVec2Op0Word2,
                                  constVec2Op0Word3,constVec2Op0Word4,constVec2Op0Word5,constVec2Op1Kind);
          }
          else if (uniqueCount < 3) {
            if (uniqueCount == 1) {
              constVec1Op0Kind = *operandPtrTable[3];
              constVec1Op0Value = operandPtrTable[3][1];
              constVec1Op0Word2 = operandPtrTable[3][2];
              constVec1Op0Word3 = operandPtrTable[3][3];
              constVec1Op0Word5 = operandPtrTable[3][5];
              constVec1Op0Word4 = operandPtrTable[3][4];
              constantHandle = ((int (*)())Compiler__getOrCreateConstVector1)(*(undefined4 *)(program + 0x3ac),constVec1Op0Kind,constVec1Op0Value,constVec1Op0Word2,
                                    constVec1Op0Word3,constVec1Op0Word4,constVec1Op0Word5);
            }
            else {
LAB_000f73f0:
              constantHandle = 0;
            }
          }
          else if (uniqueCount == 3) {
            constVec3Op0Kind = *operandPtrTable[3];
            constVec3Op0Value = operandPtrTable[3][1];
            constVec3Op0Word2 = operandPtrTable[3][2];
            constVec3Op0Word3 = operandPtrTable[3][3];
            constVec3Op0Word5 = operandPtrTable[3][5];
            constVec3Op0Word4 = operandPtrTable[3][4];
            constVec3Op1Value = operandPtrTable[4][1];
            constVec3Op1Word2 = operandPtrTable[4][2];
            constVec3Op1Word3 = operandPtrTable[4][3];
            constVec3Op1Kind = *operandPtrTable[4];
            constVec3Op1Word5 = operandPtrTable[4][5];
            constVec3Op1Word4 = operandPtrTable[4][4];
            constVec3Op2Word2 = operandPtrTable[5][2];
            constVec3Op2Word3 = operandPtrTable[5][3];
            constVec3Op2Kind = *operandPtrTable[5];
            constVec3Op2Value = operandPtrTable[5][1];
            constVec3Op2Word5 = operandPtrTable[5][5];
            constVec3Op2Word4 = operandPtrTable[5][4];
            constantHandle = ((int (*)())Compiler__getOrCreateConstVector3)(*(undefined4 *)(program + 0x3ac),constVec3Op0Kind,constVec3Op0Value,constVec3Op0Word2,
                                  constVec3Op0Word3,constVec3Op0Word4,constVec3Op0Word5,constVec3Op1Kind);
          }
          else {
            if (uniqueCount != 4) goto LAB_000f73f0;
            constVec4Op0Kind = *operandPtrTable[3];
            constVec4Op0Value = operandPtrTable[3][1];
            constVec4Op0Word2 = operandPtrTable[3][2];
            constVec4Op0Word3 = operandPtrTable[3][3];
            constVec4Op0Word5 = operandPtrTable[3][5];
            constVec4Op0Word4 = operandPtrTable[3][4];
            constVec4Op1Value = operandPtrTable[4][1];
            constVec4Op1Word2 = operandPtrTable[4][2];
            constVec4Op1Word3 = operandPtrTable[4][3];
            constVec4Op1Kind = *operandPtrTable[4];
            constVec4Op1Word5 = operandPtrTable[4][5];
            constVec4Op1Word4 = operandPtrTable[4][4];
            constVec4Op2Word2 = operandPtrTable[5][2];
            constVec4Op2Word3 = operandPtrTable[5][3];
            constVec4Op2Kind = *operandPtrTable[5];
            constVec4Op2Value = operandPtrTable[5][1];
            constVec4Op2Word5 = operandPtrTable[5][5];
            constVec4Op2Word4 = operandPtrTable[5][4];
            constVec4Op3Kind = *operandPtrTable[6];
            constVec4Op3Value = operandPtrTable[6][1];
            constVec4Op3Word2 = operandPtrTable[6][2];
            constVec4Op3Word3 = operandPtrTable[6][3];
            constVec4Op3Word5 = operandPtrTable[6][5];
            constVec4Op3Word4 = operandPtrTable[6][4];
            constantHandle = ((int (*)())Compiler__getOrCreateConstVector4)(*(undefined4 *)(program + 0x3ac),constVec4Op0Kind,constVec4Op0Value,constVec4Op0Word2,
                                  constVec4Op0Word3,constVec4Op0Word4,constVec4Op0Word5,constVec4Op1Kind);
          }
          IRInst__setOperandRef(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),constantHandle);
          goto LAB_000f76c8;
        }
        if (uniqueCount == 2) {
          loadConst2Op0Word2 = operandPtrTable[3][2];
          loadConst2Op0Kind = *operandPtrTable[3];
          loadConst2Op0Value = operandPtrTable[3][1];
          loadConst2Op0Word3 = operandPtrTable[3][3];
          loadConst2Op0Word5 = operandPtrTable[3][5];
          loadConst2Op0Word4 = operandPtrTable[3][4];
          loadConst2Op1Kind = *operandPtrTable[4];
          loadConst2Op1Value = operandPtrTable[4][1];
          loadConst2Op1Word2 = operandPtrTable[4][2];
          loadConst2Op1Word3 = operandPtrTable[4][3];
          loadConst2Op1Word5 = operandPtrTable[4][5];
          loadConst2Op1Word4 = operandPtrTable[4][4];
          loadConstSource = ((int (*)())Compiler__getOrCreateLoadConst2)(*(undefined4 *)(program + 0x3ac),loadConst2Op0Kind,loadConst2Op0Value,loadConst2Op0Word2,
                               loadConst2Op0Word3,loadConst2Op0Word4,loadConst2Op0Word5,loadConst2Op1Kind);
          programFlags = *(uint *)(program + 0x30);
        }
        else if (uniqueCount < 3) {
          if (uniqueCount == 1) {
            loadConst1Op0Word2 = operandPtrTable[3][2];
            loadConst1Op0Kind = *operandPtrTable[3];
            loadConst1Op0Value = operandPtrTable[3][1];
            loadConst1Op0Word3 = operandPtrTable[3][3];
            loadConst1Op0Word5 = operandPtrTable[3][5];
            loadConst1Op0Word4 = operandPtrTable[3][4];
            loadConstSource = ((int (*)())Compiler__getOrCreateLoadConst1)(*(undefined4 *)(program + 0x3ac),loadConst1Op0Kind,loadConst1Op0Value,loadConst1Op0Word2,
                                 loadConst1Op0Word3,loadConst1Op0Word4,loadConst1Op0Word5);
            programFlags = *(uint *)(program + 0x30);
          }
          else {
LAB_000f70d4:
            loadConstSource = 0;
          }
        }
        else if (uniqueCount == 3) {
          loadConst3Op0Word2 = operandPtrTable[3][2];
          loadConst3Op0Kind = *operandPtrTable[3];
          loadConst3Op0Value = operandPtrTable[3][1];
          loadConst3Op0Word3 = operandPtrTable[3][3];
          loadConst3Op0Word5 = operandPtrTable[3][5];
          loadConst3Op0Word4 = operandPtrTable[3][4];
          loadConst3Op1Value = operandPtrTable[4][1];
          loadConst3Op1Kind = *operandPtrTable[4];
          loadConst3Op1Word2 = operandPtrTable[4][2];
          loadConst3Op1Word3 = operandPtrTable[4][3];
          loadConst3Op1Word5 = operandPtrTable[4][5];
          loadConst3Op1Word4 = operandPtrTable[4][4];
          loadConst3Op2Kind = *operandPtrTable[5];
          loadConst3Op2Word2 = operandPtrTable[5][2];
          loadConst3Op2Word3 = operandPtrTable[5][3];
          loadConst3Op2Value = operandPtrTable[5][1];
          loadConst3Op2Word5 = operandPtrTable[5][5];
          loadConst3Op2Word4 = operandPtrTable[5][4];
          loadConstSource = ((int (*)())Compiler__getOrCreateLoadConst3)(*(undefined4 *)(program + 0x3ac),loadConst3Op0Kind,loadConst3Op0Value,loadConst3Op0Word2,
                               loadConst3Op0Word3,loadConst3Op0Word4,loadConst3Op0Word5,loadConst3Op1Kind);
          programFlags = *(uint *)(program + 0x30);
        }
        else {
          if (uniqueCount != 4) goto LAB_000f70d4;
          loadConst4Op0Word2 = operandPtrTable[3][2];
          loadConst4Op0Kind = *operandPtrTable[3];
          loadConst4Op0Value = operandPtrTable[3][1];
          loadConst4Op0Word3 = operandPtrTable[3][3];
          loadConst4Op0Word5 = operandPtrTable[3][5];
          loadConst4Op0Word4 = operandPtrTable[3][4];
          loadConst4Op1Value = operandPtrTable[4][1];
          loadConst4Op1Kind = *operandPtrTable[4];
          loadConst4Op1Word2 = operandPtrTable[4][2];
          loadConst4Op1Word3 = operandPtrTable[4][3];
          loadConst4Op1Word5 = operandPtrTable[4][5];
          loadConst4Op1Word4 = operandPtrTable[4][4];
          loadConst4Op2Kind = *operandPtrTable[5];
          loadConst4Op2Word2 = operandPtrTable[5][2];
          loadConst4Op2Word3 = operandPtrTable[5][3];
          loadConst4Op2Value = operandPtrTable[5][1];
          loadConst4Op2Word5 = operandPtrTable[5][5];
          loadConst4Op2Word4 = operandPtrTable[5][4];
          loadConst4Op3Kind = *operandPtrTable[6];
          loadConst4Op3Value = operandPtrTable[6][1];
          loadConst4Op3Word2 = operandPtrTable[6][2];
          loadConst4Op3Word3 = operandPtrTable[6][3];
          loadConst4Op3Word5 = operandPtrTable[6][5];
          loadConst4Op3Word4 = operandPtrTable[6][4];
          loadConstSource = ((int (*)())Compiler__getOrCreateLoadConst4)(*(undefined4 *)(program + 0x3ac),loadConst4Op0Kind,loadConst4Op0Value,loadConst4Op0Word2,
                               loadConst4Op0Word3,loadConst4Op0Word4,loadConst4Op0Word5,loadConst4Op1Kind);
          programFlags = *(uint *)(program + 0x30);
        }
        IRInst__setOperandSource(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),loadConstSource,programFlags >> 7 & 1,compiler);
LAB_000f76c8:
        operandRecordB = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
        *(undefined4 *)(operandRecordB + 0x10) = finalSelect;
        return;
      }
    } while (uniqueCount < 0);
    if (uniqueCount != 0) {
      candidateOperand = *operandCursor;
      loopCounter = 0;
      while ((*operandPtrTable[loopCounter + 3] != *candidateOperand || (operandPtrTable[loopCounter + 3][1] != candidateOperand[1]))) {
        loopCounter = loopCounter + 1;
        if (uniqueCount < loopCounter) goto LAB_000f6f58;
        if (loopCounter == uniqueCount) goto LAB_000f6f18;
      }
      *(char *)((int)&laneUniqueIndex + previousLane + 1) = (char)loopCounter;
      goto LAB_000f6f58;
    }
    candidateOperand = *operandCursor;
  } while( true );
}

/* IRInst__makeLiteralVec4Int @ 0xf771c (340 bytes) */
int IRInst__makeLiteralVec4Int(inst, program, operandIndex, value0, value1, value2, value3)
  undefined4 inst;
  undefined4 program;
  undefined4 operandIndex;
  undefined4 value0;
  undefined4 value1;
  undefined4 value2;
  undefined4 value3;
{
  undefined4 operand0Word2;
  undefined4 operand0Word3;
  undefined4 operand0Word4;
  undefined4 operand0Word5;
  undefined4 operand1Word2;
  undefined4 operand1Word3;
  undefined4 operand1Word4;
  undefined4 operand1Word5;
  undefined4 operand2Word2;
  undefined4 operand2Word3;
  undefined4 operand2Word4;
  undefined4 operand2Word5;
  
  return ((int (*)())IRInst__setConstantOperand)(inst,program,operandIndex,1,value0,operand0Word2,operand0Word3,operand0Word4,operand0Word5,1,value1,
               operand1Word2,operand1Word3,operand1Word4,operand1Word5,1,value2,operand2Word2,operand2Word3,operand2Word4,operand2Word5,1,value3);
}

/* IRInst__setIntConstantOperand4 @ 0xf7870 (340 bytes) */
int IRInst__setIntConstantOperand4(inst, program, operandIndex, value0, value1, value2, value3)
  undefined4 inst;
  undefined4 program;
  undefined4 operandIndex;
  undefined4 value0;
  undefined4 value1;
  undefined4 value2;
  undefined4 value3;
{
  undefined4 operand0Word2;
  undefined4 operand0Word3;
  undefined4 operand0Word4;
  undefined4 operand0Word5;
  undefined4 operand1Word2;
  undefined4 operand1Word3;
  undefined4 operand1Word4;
  undefined4 operand1Word5;
  undefined4 operand2Word2;
  undefined4 operand2Word3;
  undefined4 operand2Word4;
  undefined4 operand2Word5;
  
  return ((int (*)())IRInst__setConstantOperand)(inst,program,operandIndex,3,value0,operand0Word2,operand0Word3,operand0Word4,operand0Word5,3,value1,
               operand1Word2,operand1Word3,operand1Word4,operand1Word5,3,value2,operand2Word2,operand2Word3,operand2Word4,operand2Word5,3,value3);
}

/* the raw 32-bit pattern of a float, as the stock passes it in a general register / stack word (`stfs f1,0xec(r1); lwz r7,0xec(r1)`) */
#ifndef FBITS
#define FBITS(x) ({ float fbits_ = (float)(x); *(unsigned int *)&fbits_; })
#endif
/* IRInst__makeLiteralVec4Float @ 0xf79c4 (332 bytes) */
void IRInst__makeLiteralVec4Float(undefined4 inst,undefined4 program,undefined4 operandIndex,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4)
{
  undefined4 operand0Word2;
  undefined4 operand0Word3;
  undefined4 operand0Word4;
  undefined4 operand0Word5;
  undefined4 operand1Word2;
  undefined4 operand1Word3;
  undefined4 operand1Word4;
  undefined4 operand1Word5;
  undefined4 operand2Word2;
  undefined4 operand2Word3;
  undefined4 operand2Word4;
  undefined4 operand2Word5;
  
  ((int (*)())IRInst__setConstantOperand)(inst,program,operandIndex,2,FBITS(staleFprArg1),operand0Word2,operand0Word3,operand0Word4,operand0Word5,2,
               FBITS(staleFprArg2),operand1Word2,operand1Word3,operand1Word4,operand1Word5,2,FBITS(staleFprArg3),operand2Word2,
               operand2Word3,operand2Word4,operand2Word5,2,FBITS(staleFprArg4));
  return;
}

/* Vector__findIndexOfKeyPair @ 0xf7b10 (228 bytes) */
int Vector__findIndexOfKeyPair(vector, key0, key1, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  uint *vector;
  int key0;
  int key1;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  undefined4 *vectorSlot;
  uint vectorSize;
  uint loopIndex;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  vectorSize = 0;
  if (vector[1] != 0) {
    loopIndex = 0;
    vectorSize = vector[1];
    iStack0000001c = key0;
    iStack00000020 = key1;
    uStack00000024 = unusedArg4;
    uStack00000028 = unusedArg5;
    uStack0000002c = unusedArg6;
    uStack00000030 = unusedArg7;
    do {
      if (loopIndex < *vector) {
        if (vectorSize <= loopIndex) {
          _memset(vectorSize * 4 + vector[2],0,(loopIndex - vectorSize) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        vectorSlot = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        vectorSlot = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      if ((*(int *)*vectorSlot == key0) && (((int *)*vectorSlot)[1] == key1)) {
        return loopIndex;
      }
      vectorSize = vector[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < vectorSize);
  }
  return vectorSize;
}

/* DominatorTree__ctor_f7bf4 @ 0xf7bf4 (228 bytes) */
int DominatorTree__ctor_f7bf4(domInfo, program)
  undefined4 *domInfo;
  int program;
{
  int listCount;
  int arrayBytes;
  undefined4 allocation;
  int compiler;
  
  domInfo[8] = program;
  listCount = DList__count(program + 0x37c);
  domInfo[7] = listCount;
  compiler = *(int *)(domInfo[8] + 8);
  arrayBytes = listCount * 4 + 4;
  domInfo[9] = compiler;
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x378),arrayBytes);
  domInfo[2] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[1] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[4] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[3] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  *domInfo = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),domInfo[7] * 4 + 4);
  domInfo[6] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),domInfo[7] * 4 + 4);
  domInfo[5] = allocation;
  return;
}

/* DominatorTree__ctor_f7cd8 @ 0xf7cd8 (228 bytes) */
int DominatorTree__ctor_f7cd8(domInfo, program)
  undefined4 *domInfo;
  int program;
{
  int listCount;
  int arrayBytes;
  undefined4 allocation;
  int compiler;
  
  domInfo[8] = program;
  listCount = DList__count(program + 0x37c);
  domInfo[7] = listCount;
  compiler = *(int *)(domInfo[8] + 8);
  arrayBytes = listCount * 4 + 4;
  domInfo[9] = compiler;
  allocation = Arena__alloc(*(undefined4 *)(compiler + 0x378),arrayBytes);
  domInfo[2] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[1] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[4] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  domInfo[3] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),arrayBytes);
  *domInfo = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),domInfo[7] * 4 + 4);
  domInfo[6] = allocation;
  allocation = Arena__alloc(*(undefined4 *)(domInfo[9] + 0x378),domInfo[7] * 4 + 4);
  domInfo[5] = allocation;
  return;
}

/* DominatorTree__computeDominanceFrontiers @ 0xf7dbc (352 bytes) */
int DominatorTree__computeDominanceFrontiers(domInfo)
  int domInfo;
{
  int domChild;
  int childFrontierBlock;
  int *blockCursor;
  int successor;
  uint loopIndex;
  int blockDfsNumber;
  int block;
  int loopCounter;
  int loopCounterB;
  uint loopIndex2;
  uint childFrontierIndex;
  
  blockCursor = (int *)Program__getBlocksArray(*(undefined4 *)(domInfo + 0x20));
  if (*(int *)(domInfo + 0x1c) != 0) {
    loopIndex = 1;
    do {
      blockCursor = blockCursor + 1;
      block = *blockCursor;
      blockDfsNumber = *(int *)(block + 0xe4);
      loopCounter = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(block + 0xd0) + 4); loopIndex2 = loopIndex2 + 1) {
        successor = *(int *)(loopCounter + *(int *)(*(int *)(block + 0xd0) + 8));
        if ((successor != 0) && (blockDfsNumber != *(int *)(*(int *)(successor + 0xe4) * 4 + *(int *)(domInfo + 8))))
        {
          Block__addDominanceFrontier(block,successor);
        }
        loopCounter = loopCounter + 4;
      }
      loopCounter = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(block + 0xf4) + 4); loopIndex2 = loopIndex2 + 1) {
        loopCounterB = 0;
        domChild = *(int *)(loopCounter + *(int *)(*(int *)(block + 0xf4) + 8));
        for (childFrontierIndex = 1; childFrontierBlock = *(int *)(domChild + 0xf8), childFrontierIndex <= *(uint *)(childFrontierBlock + 4);
            childFrontierIndex = childFrontierIndex + 1) {
          childFrontierBlock = *(int *)(loopCounterB + *(int *)(childFrontierBlock + 8));
          if (blockDfsNumber != *(int *)(*(int *)(childFrontierBlock + 0xe4) * 4 + *(int *)(domInfo + 8))) {
            Block__addDominanceFrontier(block,childFrontierBlock);
          }
          loopCounterB = loopCounterB + 4;
        }
        loopCounter = loopCounter + 4;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(uint *)(domInfo + 0x1c));
  }
  return;
}

/* DominatorTree__free_f7f1c @ 0xf7f1c (296 bytes) */
int DominatorTree__free_f7f1c(domInfo)
  undefined4 *domInfo;
{
  int iVar1;
  int bucketNode;
  int bucketArray;
  uint loopIndex;
  int nextBucketNode;
  
  loopIndex = 0;
  bucketArray = domInfo[5];
  do {
    iVar1 = loopIndex * 4;
    bucketNode = *(int *)(iVar1 + bucketArray);
    while ((bucketNode != 0 && (nextBucketNode = *(int *)(bucketNode + 4), nextBucketNode != 0))) {
      Arena__free(*(undefined4 *)(bucketNode + -4),bucketNode + -4);
      *(int *)(iVar1 + domInfo[5]) = nextBucketNode;
      bucketArray = domInfo[5];
      bucketNode = *(int *)(iVar1 + bucketArray);
    }
    iVar1 = *(int *)(iVar1 + bucketArray);
    if (iVar1 != 0) {
      Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      bucketArray = domInfo[5];
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex <= (uint)domInfo[7]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),bucketArray);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[6]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),*domInfo);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[3]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[4]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[1]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[2]);
  domInfo[6] = 0;
  return;
}

/* DominatorTree__free @ 0xf8044 (296 bytes) */
int DominatorTree__free(domInfo)
  undefined4 *domInfo;
{
  int iVar1;
  int bucketNode;
  int bucketArray;
  uint loopIndex;
  int nextBucketNode;
  
  loopIndex = 0;
  bucketArray = domInfo[5];
  do {
    iVar1 = loopIndex * 4;
    bucketNode = *(int *)(iVar1 + bucketArray);
    while ((bucketNode != 0 && (nextBucketNode = *(int *)(bucketNode + 4), nextBucketNode != 0))) {
      Arena__free(*(undefined4 *)(bucketNode + -4),bucketNode + -4);
      *(int *)(iVar1 + domInfo[5]) = nextBucketNode;
      bucketArray = domInfo[5];
      bucketNode = *(int *)(iVar1 + bucketArray);
    }
    iVar1 = *(int *)(iVar1 + bucketArray);
    if (iVar1 != 0) {
      Arena__free(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      bucketArray = domInfo[5];
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex <= (uint)domInfo[7]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),bucketArray);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[6]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),*domInfo);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[3]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[4]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[1]);
  Arena__free(*(undefined4 *)(domInfo[9] + 0x378),domInfo[2]);
  domInfo[6] = 0;
  return;
}

/* DominatorTree__dfsNumber @ 0xf816c (236 bytes) */
int DominatorTree__dfsNumber(domInfo, rootBlock)
  int *domInfo;
  int rootBlock;
{
  int loopCounter;
  int vectorData;
  int arena;
  int slotOffset;
  int *allocation;
  int *stackSlot;
  int nextChild;
  uint *stackVector;
  int arenaObj;
  uint stackSize;
  
  *(int *)(domInfo[8] + 0x474) = *(int *)(domInfo[8] + 0x474) + 1;
  arena = *(int *)(domInfo[9] + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  stackVector = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 *)(rootBlock + 0xe4) = 1;
  *(undefined4 *)(*domInfo + 4) = 0;
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[6]) = rootBlock;
  stackSize = allocation[2];
  if (stackSize < (uint)allocation[1]) {
    _memset((void *)(stackSize * 4 + allocation[3]),0,4);
    allocation[2] = stackSize + 1;
    stackSlot = (int *)(stackSize * 4 + allocation[3]);
  }
  else {
    stackSlot = (int *)Vector__elementRefGrow(stackVector,stackSize);
  }
  *stackSlot = rootBlock;
  loopCounter = 2;
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[1]) = *(int *)(rootBlock + 0xe4);
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[4]) = *(int *)(rootBlock + 0xe4);
  while( true ) {
    while( true ) {
      nextChild = Block__nextUnvisitedSuccessor(rootBlock,*(undefined4 *)(domInfo[8] + 0x474));
      if (nextChild == 0) break;
      stackSize = allocation[2];
      if (stackSize < *stackVector) {
        _memset((void *)(stackSize * 4 + allocation[3]),0,4);
        allocation[2] = stackSize + 1;
        stackSlot = (int *)(stackSize * 4 + allocation[3]);
      }
      else {
        stackSlot = (int *)Vector__elementRefGrow(stackVector,stackSize);
      }
      *stackSlot = nextChild;
      slotOffset = loopCounter * 4;
      *(int *)(nextChild + 0xe4) = loopCounter;
      loopCounter = loopCounter + 1;
      *(undefined4 *)(slotOffset + *domInfo) = *(undefined4 *)(rootBlock + 0xe4);
      *(int *)(*(int *)(nextChild + 0xe4) * 4 + domInfo[6]) = nextChild;
      *(undefined4 *)(nextChild + 0x118) = *(undefined4 *)(domInfo[8] + 0x474);
      *(int *)(*(int *)(nextChild + 0xe4) * 4 + domInfo[1]) = *(int *)(nextChild + 0xe4);
      *(int *)(*(int *)(nextChild + 0xe4) * 4 + domInfo[4]) = *(int *)(nextChild + 0xe4);
      rootBlock = nextChild;
    }
    stackSize = allocation[2];
    if (stackSize == 0) break;
    stackSlot = (int *)0x0;
    if (stackSize - 1 < stackSize) {
      stackSlot = (int *)((stackSize - 1) * 4 + allocation[3]);
    }
    rootBlock = *stackSlot;
    Vector__removeAt(stackVector,stackSize - 1);
  }
  if (stackVector != (uint *)0x0) {
    Arena__free(allocation[4],allocation[3]);
    arenaObj = *allocation;
    if ((*(int *)(arenaObj + 0x28) != 0) && (stackSlot = *(int **)(arenaObj + 0x14), stackSlot == allocation)) {
      _memset(stackSlot,0,*(int *)(arenaObj + 8) - (int)stackSlot);
      *(undefined4 *)(arenaObj + 8) = *(undefined4 *)(arenaObj + 0x14);
    }
    return;
  }
  return;
}

/* DominatorTree__compress @ 0xf83cc (100 bytes) */
int DominatorTree__compress(domInfo, vertex)
  int domInfo;
  int vertex;
{
  uint stackTopIndex;
  int arenaObj;
  int vertexOffset;
  int vectorData;
  int arena;
  int ancestorOffset;
  uint stackSize;
  int *allocation;
  int *stackSlot;
  int ancestorLabel;
  int ancestorArrayB;
  int labelArray;
  uint *stackVector;
  int ancestorArray;
  
  arena = *(int *)(*(int *)(domInfo + 0x24) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  stackVector = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  ancestorArray = *(int *)(domInfo + 0xc);
  while (*(int *)(*(int *)(vertex * 4 + ancestorArray) * 4 + ancestorArray) != 0) {
    stackSize = allocation[2];
    if (stackSize < *stackVector) {
      _memset((void *)(stackSize * 4 + allocation[3]),0,4);
      stackSlot = (int *)(stackSize * 4 + allocation[3]);
      allocation[2] = stackSize + 1;
    }
    else {
      stackSlot = (int *)Vector__elementRefGrow(stackVector,stackSize);
    }
    *stackSlot = vertex;
    ancestorArray = *(int *)(domInfo + 0xc);
    vertex = *(int *)(vertex * 4 + ancestorArray);
  }
  while (allocation[2] != 0) {
    stackTopIndex = allocation[2] - 1;
    stackSlot = (int *)0x0;
    if (stackTopIndex < (uint)allocation[2]) {
      stackSlot = (int *)(stackTopIndex * 4 + allocation[3]);
    }
    vertexOffset = *stackSlot;
    Vector__removeAt(stackVector,allocation[2] - 1);
    ancestorArrayB = *(int *)(domInfo + 0xc);
    vertexOffset = vertexOffset * 4;
    labelArray = *(int *)(domInfo + 0x10);
    ancestorOffset = *(int *)(ancestorArrayB + vertexOffset) * 4;
    ancestorLabel = *(int *)(labelArray + ancestorOffset);
    if (*(uint *)(ancestorLabel * 4 + *(int *)(domInfo + 4)) <
        *(uint *)(*(int *)(vertexOffset + labelArray) * 4 + *(int *)(domInfo + 4))) {
      *(int *)(vertexOffset + labelArray) = ancestorLabel;
      ancestorArrayB = *(int *)(domInfo + 0xc);
    }
    *(undefined4 *)(vertexOffset + ancestorArrayB) = *(undefined4 *)(ancestorOffset + ancestorArrayB);
  }
  if (stackVector == (uint *)0x0) {
    return;
  }
  Arena__free(allocation[4],allocation[3]);
  arenaObj = *allocation;
  if ((*(int *)(arenaObj + 0x28) != 0) && (stackSlot = *(int **)(arenaObj + 0x14), stackSlot == allocation)) {
    _memset(stackSlot,0,*(int *)(arenaObj + 8) - (int)stackSlot);
    *(undefined4 *)(arenaObj + 8) = *(undefined4 *)(arenaObj + 0x14);
  }
  return;
}

/* DominatorTree__eval @ 0xf8588 (72 bytes) */
int DominatorTree__eval(domInfo, vertex)
  int domInfo;
  int vertex;
{
  if (*(int *)(*(int *)(domInfo + 0xc) + vertex * 4) != 0) {
    ((int (*)())DominatorTree__compress)(domInfo,vertex);
  }
  return *(undefined4 *)(vertex * 4 + *(int *)(domInfo + 0x10));
}

/* DominatorTree__compute @ 0xf85d0 (740 bytes) */
int DominatorTree__compute(domInfo)
  int *domInfo;
{
  uint vertexCount;
  int vertexArray;
  int idomBlock;
  int idomArray;
  int bucketByteOffset;
  int vertexBlock2;
  int blockCursor3;
  int blockCursor2;
  int vertexBlock;
  int vertexByteOffset2;
  int vertexByteOffset;
  uint loopCounterB;
  int loopCounter;
  uint loopIndex;
  uint predSemi;
  int predecessorBlock;
  undefined4 *allocation;
  int blockCursor;
  int entryBlock;
  uint vertexNumber;
  int nextBlock;
  int evalResult;
  int semiArray;
  undefined4 arenaB;
  uint predIndex;
  int *bucketNode;
  
  entryBlock = *(int *)(domInfo[8] + 0x3a0);
  if (*(int *)(entryBlock + 0xe4) == 0) {
    blockCursor = *(int *)(domInfo[8] + 900);
    for (nextBlock = *(int *)(blockCursor + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
      *(undefined4 *)(blockCursor + 0xe8) = *(undefined4 *)(blockCursor + 0xe4);
      blockCursor = nextBlock;
    }
  }
  ((int (*)())DominatorTree__dfsNumber)(domInfo,entryBlock);
  Program__storeDominatorOrder(domInfo[8],domInfo[6],domInfo[7]);
  vertexNumber = domInfo[7];
  if (1 < vertexNumber) {
    vertexByteOffset = vertexNumber << 2;
    do {
      loopCounter = 0;
      vertexBlock2 = *(int *)(domInfo[6] + vertexByteOffset);
      for (predIndex = 1; predecessorBlock = *(int *)(vertexBlock2 + 0xd4), predIndex <= *(uint *)(predecessorBlock + 4);
          predIndex = predIndex + 1) {
        predecessorBlock = *(int *)(loopCounter + *(int *)(predecessorBlock + 8));
        if (predecessorBlock != 0) {
          semiArray = domInfo[1];
          predecessorBlock = ((int (*)())DominatorTree__eval)(domInfo,*(undefined4 *)(predecessorBlock + 0xe4));
          predSemi = *(uint *)(predecessorBlock * 4 + semiArray);
          if (predSemi < *(uint *)(vertexByteOffset + domInfo[1])) {
            *(uint *)(vertexByteOffset + domInfo[1]) = predSemi;
          }
        }
        loopCounter = loopCounter + 4;
      }
      arenaB = *(undefined4 *)(domInfo[9] + 0x378);
      allocation = (undefined4 *)Arena__alloc(arenaB,0xc);
      *allocation = arenaB;
      allocation[1] = vertexNumber;
      allocation[2] = 0;
      allocation[2] = *(undefined4 *)(*(int *)(vertexByteOffset + domInfo[1]) * 4 + domInfo[5]);
      *(undefined4 **)(*(int *)(vertexByteOffset + domInfo[1]) * 4 + domInfo[5]) = allocation + 1;
      *(undefined4 *)(vertexByteOffset + domInfo[3]) = *(undefined4 *)(vertexByteOffset + *domInfo);
      for (bucketNode = *(int **)(*(int *)(vertexByteOffset + *domInfo) * 4 + domInfo[5]); bucketNode != (int *)0x0;
          bucketNode = (int *)bucketNode[1]) {
        bucketByteOffset = *bucketNode * 4;
        evalResult = ((int (*)())DominatorTree__eval)(domInfo,*bucketNode);
        predecessorBlock = *(int *)(domInfo[1] + bucketByteOffset);
        if (predecessorBlock == *(int *)(evalResult * 4 + domInfo[1])) {
          *(int *)(bucketByteOffset + domInfo[2]) = predecessorBlock;
        }
        else {
          *(int *)(bucketByteOffset + domInfo[2]) = evalResult;
        }
      }
      vertexNumber = vertexNumber - 1;
      vertexByteOffset = vertexByteOffset + -4;
    } while (1 < vertexNumber);
  }
  *(undefined4 *)(domInfo[2] + 4) = 0;
  vertexCount = domInfo[7];
  if (1 < vertexCount) {
    loopCounterB = 2;
    do {
      vertexByteOffset2 = loopCounterB * 4;
      idomArray = domInfo[2];
      if (*(int *)(vertexByteOffset2 + idomArray) != *(int *)(vertexByteOffset2 + domInfo[1])) {
        *(undefined4 *)(vertexByteOffset2 + idomArray) = *(undefined4 *)(*(int *)(vertexByteOffset2 + idomArray) * 4 + idomArray);
        vertexCount = domInfo[7];
      }
      loopCounterB = loopCounterB + 1;
    } while (loopCounterB <= vertexCount);
  }
  if (vertexCount != 0) {
    vertexArray = domInfo[6];
    idomBlock = 0;
    loopIndex = 1;
    vertexBlock = 4;
    while( true ) {
      vertexBlock = *(int *)(vertexBlock + vertexArray);
      *(int *)(vertexBlock + 0xf0) = idomBlock;
      if (idomBlock != 0) {
        Block__addDominatedChild(idomBlock,vertexBlock);
      }
      loopIndex = loopIndex + 1;
      if ((uint)domInfo[7] < loopIndex) break;
      if (loopIndex == 1) {
        vertexArray = domInfo[6];
        idomBlock = 0;
        vertexBlock = 4;
      }
      else {
        vertexBlock = loopIndex * 4;
        vertexArray = domInfo[6];
        idomBlock = *(int *)(*(int *)(vertexBlock + domInfo[2]) * 4 + vertexArray);
      }
    }
  }
  ((int (*)())DominatorTree__computeDominanceFrontiers)(domInfo);
  if (*(int *)(entryBlock + 0xe8) == 0) {
    blockCursor3 = *(int *)(domInfo[8] + 900);
    for (blockCursor2 = *(int *)(*(int *)(domInfo[8] + 900) + 8); blockCursor2 != 0; blockCursor2 = *(int *)(blockCursor2 + 8))
    {
      *(undefined4 *)(blockCursor3 + 0xe4) = *(undefined4 *)(blockCursor3 + 0xe8);
      blockCursor3 = blockCursor2;
    }
  }
  return;
}

/* Program__computeDominators @ 0xf88b4 (104 bytes) */
int Program__computeDominators(program)
  int program;
{
  int arena;
  int *allocation;
  int *domTree;
  int arenaObj;
  
  arena = *(int *)(*(int *)(program + 8) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x2c);
  *allocation = arena;
  domTree = allocation + 1;
  ((int (*)())DominatorTree__ctor_f7cd8)(domTree,program);
  ((int (*)())DominatorTree__compute)(domTree);
  if (domTree == (int *)0x0) {
    return;
  }
  ((int (*)())DominatorTree__free)(domTree);
  arenaObj = *allocation;
  if ((*(int *)(arenaObj + 0x28) != 0) && (domTree = *(int **)(arenaObj + 0x14), domTree == allocation)) {
    _memset(domTree,0,*(int *)(arenaObj + 8) - (int)domTree);
    *(undefined4 *)(arenaObj + 8) = *(undefined4 *)(arenaObj + 0x14);
  }
  return;
}

/* OpcodeRecord__getField8 @ 0xf8960 (16 bytes) */
int OpcodeRecord__getField8(opcodeIndex, recordTable)
  int opcodeIndex;
  int recordTable;
{
  return *(undefined4 *)(opcodeIndex * 0x24 + recordTable + 8);
}

/* OpcodeRecord__getOperandCount @ 0xf8970 (16 bytes) */
int OpcodeRecord__getOperandCount(opcodeIndex, recordTable)
  int opcodeIndex;
  int recordTable;
{
  return *(undefined4 *)(opcodeIndex * 0x24 + recordTable + 4);
}

/* OpcodeRecord__getOperandByte @ 0xf8980 (20 bytes) */
int OpcodeRecord__getOperandByte(ilOpcode, operandIndex, recordTable)
  int ilOpcode;
  int operandIndex;
  int recordTable;
{
  return *(undefined1 *)(operandIndex + ilOpcode * 0x24 + recordTable + 0x1c);
}

/* OpcodeRecord__getFieldC @ 0xf8994 (16 bytes) */
int OpcodeRecord__getFieldC(opcodeIndex, recordTable)
  int opcodeIndex;
  int recordTable;
{
  return *(undefined4 *)(opcodeIndex * 0x24 + recordTable + 0xc);
}

/* OpcodeRecord__getTranslationKind @ 0xf89a4 (16 bytes) */
int OpcodeRecord__getTranslationKind(opcodeIndex, recordTable)
  int opcodeIndex;
  int recordTable;
{
  return *(undefined4 *)(opcodeIndex * 0x24 + recordTable + 0x10);
}

/* tableWordOrEight @ 0xf89b4 (52 bytes) */
int tableWordOrEight(param_1)
  uint param_1;
{
  if (5 < param_1) {
    return 8;
  }
  return *(undefined4 *)(PTR_DAT_001e8b84 + param_1 * 4);
}

/* remapSelect1To0 @ 0xf89e8 (36 bytes) */
int remapSelect1To0(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  return 2 - (uint)(param_1 == 2);
}

/* remapSelectSmall @ 0xf8a0c (36 bytes) */
int remapSelectSmall(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  if (param_1 == 2) {
    return 1;
  }
  return 3;
}

/* IRInst__literalForLane @ 0xf8a30 (112 bytes) */
double IRInst__literalForLane(int sourceSelect,int lane,int literalMask,int selectBytes)
{
  undefined *puVar1;
  double dVar2;
  
  puVar1 = PTR_DAT_001e8bb8;
  if (sourceSelect == 4) {
    dVar2 = (double)FLOAT_001aa0d4;
    *(undefined1 *)(literalMask + lane) = 0;
    return dVar2;
  }
  if (sourceSelect == 5) {
    dVar2 = (double)FLOAT_001aa0e8;
    *(undefined1 *)(literalMask + lane) = 0;
    return dVar2;
  }
  *(undefined1 *)(literalMask + lane) = 1;
  dVar2 = (double)FLOAT_001aa0d4;
  *(char *)(selectBytes + lane) = (char)*(undefined4 *)(puVar1 + sourceSelect * 4);
  return dVar2;
}

/* Program__applySourceTokenToOperand @ 0xf8aa0 (488 bytes) */
int Program__applySourceTokenToOperand(program, selectWordPtr, descriptor, operandIndex, inst)
  undefined4 program;
  uint *selectWordPtr;
  uint *descriptor;
  int operandIndex;
  int *inst;
{
  uint extensionWord;
  int *instRef;
  undefined4 staleArgR8;
  uint firstTokenWord;
  uint selectWord;
  char laneSources [32];
  
  laneSources[0] = '\0';
  laneSources[1] = 1;
  laneSources[2] = 2;
  laneSources[3] = 3;
  selectWord = *selectWordPtr;
  instRef = inst;
  if (descriptor != (uint *)0x0) {
    firstTokenWord = *descriptor;
    if ((firstTokenWord & 0x400000) != 0) {
      extensionWord = descriptor[1];
      if ((extensionWord >> 3 & 1 & extensionWord >> 7 & 1 & extensionWord >> 0xb & 1 & extensionWord >> 0xf & 1) != 0) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
        firstTokenWord = *descriptor;
      }
    }
    if (((firstTokenWord & 0x400000) != 0) && ((descriptor[1] & 0x100000) != 0)) {
      IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,2,1);
    }
    laneSources[0] = psnPackedLaneSource(descriptor,0);
    laneSources[1] = psnPackedLaneSource(descriptor,1);
    laneSources[2] = psnPackedLaneSource(descriptor,2);
    laneSources[3] = psnPackedLaneSource(descriptor,3);
  }
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,0,(int)laneSources[selectWord >> 0x18],instRef,staleArgR8,*(code **)(*inst + 0x88));
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,1,(int)laneSources[selectWord >> 0x10 & 0xff],instRef,staleArgR8,
             *(code **)(*inst + 0x88));
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,2,(int)laneSources[selectWord >> 8 & 0xff],instRef,staleArgR8,*(code **)(*inst + 0x88)
            );
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,3,(int)laneSources[selectWord & 0xff],instRef,staleArgR8,*(code **)(*inst + 0x88));
  *selectWordPtr = 0x10203;
  return;
}

/* FUN_000f8c88 @ 0xf8c88 (64 bytes) */
int FUN_000f8c88(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + -0x30;
  if ((1 < iVar1) && (iVar1 = 2, param_1 != 0x5f)) {
    iVar1 = param_1 + -0x74;
  }
  return *(undefined4 *)(&DAT_001aa9e4 + iVar1 * 4);
}

/* OpcodeTemplate__lookup @ 0xf8ccc (132 bytes) */
int OpcodeTemplate__lookup(ilOpcode, compiler, variant)
  int ilOpcode;
  int compiler;
  int variant;
{
  int hwTemplateQuery;
  undefined *templateTable;
  
  hwTemplateQuery = (**(code **)(**(int **)(compiler + 0x30c) + 0xdc))
                    (*(int **)(compiler + 0x30c),compiler,variant);
  if (hwTemplateQuery == 0) {
    templateTable = (PTR_DAT_001e9f7c)[ilOpcode * 3];
  }
  else if (variant == 0) {
    templateTable = (PTR_DAT_001e9f80)[ilOpcode * 3];
  }
  else {
    templateTable = (PTR_DAT_001e9f78)[ilOpcode * 3];
  }
  return templateTable;
}

/* IRInst__applyDescriptorSelects @ 0xf8d50 (568 bytes) */
int IRInst__applyDescriptorSelects(program, unusedArg2, overrideSelects, descriptor, unusedArg5, inst, forceOnes)
  int program;
  undefined4 unusedArg2;
  undefined4 overrideSelects;
  uint *descriptor;
  undefined4 unusedArg5;
  int inst;
  int forceOnes;
{
  int laneComponent;
  int hwHasFeature;
  undefined4 registerFileB;
  int loopCounter;
  int registerFile;
  unsigned int ghidra_home[8] = { program, unusedArg2, overrideSelects, descriptor, unusedArg5, inst, forceOnes, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined *laneSelectTable;
  undefined1 laneSelectB;
  char laneSelect;
  int tempId;
  undefined4 registerMap;
  uint descriptorWord;
  undefined1 *overrideCursor2;
  char *overrideCursor;
  code *hwVirtualSlot78;
  undefined4 destRegisterId;
  int *hwDescription;
  int loopCounterB;
  char descriptorSelects [28];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = overrideSelects;
  descriptorSelects[0] = '\0';
  descriptorSelects[1] = '\0';
  descriptorSelects[2] = '\0';
  descriptorSelects[3] = '\0';
  if (descriptor != (uint *)0x0) {
    descriptorWord = *descriptor;
    if ((descriptorWord & 0x1800000) == 0x800000) {
      if (*(int *)(program + 0x3e4) == 0) {
        *(undefined4 *)(program + 0x3f4) = *(undefined4 *)(inst + 0x98);
        *(undefined4 *)(program + 0x3e4) = 1;
      }
      registerMap = *(undefined4 *)(program + 0x3ac);
      destRegisterId = *(undefined4 *)(inst + 0x94);
      tempId = *(int *)(*(int *)(program + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(program + 8) + 0x3c0) = tempId;
      tempId = VRegPool__findOrCreate(registerMap,0x2a,tempId,0);
      *(undefined4 *)(tempId + 0x30) = destRegisterId;
      IRInst__setOperandRef(inst,0,tempId);
      descriptorWord = *descriptor;
    }
    if (((descriptorWord & 0x400000) != 0) && ((descriptor[1] & 0x100) != 0)) {
      hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
      hwVirtualSlot78 = *(code **)(*hwDescription + 0x78);
      registerFileB = Program__registerFileOfIlType(program,descriptorWord >> 0x10 & 0x3f);
      hwHasFeature = (*hwVirtualSlot78)(hwDescription,registerFileB);
      if (hwHasFeature == 0) {
        registerFile = Program__registerFileOfIlType(program,*descriptor >> 0x10 & 0x3f);
        if (registerFile != 9) {
          Program__registerFileOfIlType(program,*descriptor >> 0x10 & 0x3f);
        }
      }
      else {
        *(undefined4 *)(inst + 0x120) = 1;
      }
    }
    laneComponent = psnPackedLaneComponent(descriptor,0);
    laneSelectTable = PTR_DAT_001e8bc8;
    descriptorSelects[0] = (char)*(undefined4 *)(PTR_DAT_001e8bc8 + laneComponent * 4);
    laneComponent = psnPackedLaneComponent(descriptor,1);
    descriptorSelects[1] = (char)*(undefined4 *)(laneSelectTable + laneComponent * 4);
    laneComponent = psnPackedLaneComponent(descriptor,2);
    descriptorSelects[2] = (char)*(undefined4 *)(laneSelectTable + laneComponent * 4);
    laneComponent = psnPackedLaneComponent(descriptor,3);
    descriptorSelects[3] = (char)*(undefined4 *)(laneSelectTable + laneComponent * 4);
  }
  if (forceOnes == 0) {
    loopCounterB = 4;
    loopCounter = 0;
    overrideCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      laneSelect = descriptorSelects[loopCounter];
      if (*overrideCursor != '\0') {
        laneSelect = *overrideCursor;
      }
      *(char *)(inst + 0x9c) = laneSelect;
      loopCounter = loopCounter + 1;
      overrideCursor = overrideCursor + 1;
      inst = inst + 1;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
  }
  else {
    loopCounterB = 4;
    loopCounter = 0;
    overrideCursor2 = (undefined1 *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      laneSelectB = 1;
      if (descriptorSelects[loopCounter] != '\x01') {
        laneSelectB = *overrideCursor2;
      }
      *(undefined1 *)(inst + 0x9c) = laneSelectB;
      loopCounter = loopCounter + 1;
      overrideCursor2 = overrideCursor2 + 1;
      inst = inst + 1;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
  }
  return;
}

/* IRInst__applyDescriptorSwizzle @ 0xf8f88 (176 bytes) */
int IRInst__applyDescriptorSwizzle(descriptor, inst)
  uint *descriptor;
  int *inst;
{
  bool bVar1;
  undefined *puVar2;
  int psnPackedLaneSourceResult;
  int loopCounter;
  
  puVar2 = PTR_DAT_001e8bb8;
  loopCounter = 0;
  do {
    psnPackedLaneSourceResult = psnPackedLaneSource(descriptor,loopCounter);
    (**(code **)(*inst + 0x88))(inst,1,loopCounter,*(undefined4 *)(puVar2 + psnPackedLaneSourceResult * 4));
    bVar1 = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (bVar1);
  if ((*descriptor & 0x400000) != 0) {
    descriptor[1] = descriptor[1] & 0xffff8888 | 0x3210;
  }
  return;
}

/* Program__emitClampPair @ 0xf9038 (264 bytes) */
int Program__emitClampPair(program, tempIndex, list)
  int program;
  undefined4 tempIndex;
  undefined4 list;
{
  undefined4 inst;
  int operandRecord;
  double literalValue;
  
  inst = IRInst__create(0x17,*(undefined4 *)(program + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = tempIndex;
  operandRecord = IRInst__getOperandRecord(inst,1);
  literalValue = (double)FLOAT_001aa0d4;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = tempIndex;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,literalValue,literalValue,literalValue,literalValue);
  DList__pushBack(list,inst);
  inst = IRInst__create(0x19,*(undefined4 *)(program + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = tempIndex;
  operandRecord = IRInst__getOperandRecord(inst,1);
  literalValue = (double)FLOAT_001aa0e8;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = tempIndex;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,literalValue,literalValue,literalValue,literalValue);
  DList__pushBack(list,inst);
  return inst;
}

/* Program__createInstForIlOpcode @ 0xf9140 (284 bytes) */
int Program__createInstForIlOpcode(program, ilOpcode, remapFlag)
  int program;
  int ilOpcode;
  int remapFlag;
{
  int *hardwareInfo;
  int hwQueryResult;
  undefined4 opcodeInfo;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int createdInst;
  
  createdInst = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0xc);
  createdInst = (**(code **)(ilOpcode * 0x24 + createdInst + 0x14))
                    (*(undefined4 *)(ilOpcode * 0x24 + createdInst),*(int *)(program + 8),remapFlag,staleArgR6,
                     staleArgR7,staleArgR8,createdInst);
  if ((remapFlag != 0) &&
     (hardwareInfo = *(int **)(*(int *)(program + 8) + 0x30c), hwQueryResult = (**(code **)(*hardwareInfo + 0xb0))(hardwareInfo),
     hwQueryResult != 0)) {
    switch(ilOpcode) {
    case 0x22:
      opcodeInfo = Opcode__getInfo(0xdf);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
      break;
    case 0x23:
      opcodeInfo = Opcode__getInfo(0xde);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
      break;
    case 0x40:
      opcodeInfo = Opcode__getInfo(0xf0);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
      break;
    case 0x41:
      opcodeInfo = Opcode__getInfo(0xb7);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
      break;
    case 0x44:
      opcodeInfo = Opcode__getInfo(0xb8);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
      break;
    case 0x49:
      opcodeInfo = Opcode__getInfo(0xb6);
      *(undefined4 *)(createdInst + 0x88) = opcodeInfo;
    }
  }
  return createdInst;
}

/* Program__appendInst @ 0xf92fc (480 bytes) */
int Program__appendInst(program, inst, block)
  int program;
  int *inst;
  undefined4 block;
{
  int sourceRegFile;
  int sourceRegNumberB;
  int operandRecord;
  uint instField0x134;
  int splitQuery;
  int *hardwareInfo;
  void *inst2;
  int newTempIndex;
  int sourceRegNumber;
  int iVar7;
  
  splitQuery = (**(code **)(*inst + 0x30))(inst,inst,block);
  if ((splitQuery != 0) &&
     (hardwareInfo = *(int **)(*(int *)(program + 8) + 0x30c),
     splitQuery = (**(code **)(*hardwareInfo + 0x168))(hardwareInfo,program,inst), splitQuery != 0)) {
    inst2 = IRInst__create(0x13,*(undefined4 *)(program + 8));
    newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex;
    instField0x134 = inst[0x4d];
    ((int (*)())IRInst__makeLiteralVec4Int)(inst2,program,1,instField0x134 & 0xffff | 0x60000,instField0x134 & 0xffff | 0x70000,
                 instField0x134 & 0xffff | 0x70000,instField0x134 & 0xffff | 0x70000);
    sourceRegNumber = inst[0x2b];
    sourceRegFile = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,2);
    *(int *)(operandRecord + 0xc) = sourceRegFile;
    *(int *)(operandRecord + 8) = sourceRegNumber;
    ((int (*)())Program__appendInst)(program,inst2,block);
    inst2 = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex;
    *(undefined4 *)((int)inst2 + 0x9c) = 0x1010000;
    sourceRegNumberB = inst[0x2b];
    iVar7 = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,1);
    *(int *)(operandRecord + 8) = sourceRegNumberB;
    *(int *)(operandRecord + 0xc) = iVar7;
    ((int (*)())Program__appendInst)(program,inst2,block);
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex;
  }
  Block__appendInst(block,inst);
  IRInst__bindOperandRegisters(program,inst);
                    
                    
  (**(code **)(*inst + 8))(inst,*(undefined4 *)(program + 8));
  return;
}

/* FUN_000f94dc @ 0xf94dc (968 bytes) */
int FUN_000f94dc(program, list, descriptor, unusedArg4, projectionDestRegister, param_6, param_7)
  int program;
  undefined4 list;
  uint *descriptor;
  undefined4 unusedArg4;
  undefined4 projectionDestRegister;
  undefined4 param_6;
  undefined4 param_7;
{
  int inputTempId;
  undefined4 *projectionInst;
  uint descriptorWord;
  undefined4 mergeOperandIndex;
  undefined4 mergeOperandCount;
  undefined4 inputSelectWord;
  undefined4 hwInputRegister;
  undefined4 successor;
  int operandRecord2;
  undefined4 arenaAt374;
  undefined4 *instAlloc;
  uint loopIndex;
  int loopIndex2;
  uint mergeSlotCount;
  undefined4 registerFile;
  undefined4 *allocation;
  int inputVReg;
  void *inst;
  int operandRecord;
  int *hwDescription;
  undefined4 *puVar8;
  uint inputRegisterCount;
  undefined4 *secondMerge;
  int secondMergeIndex;
  undefined4 *mergeInst;
  int hwRegister;
  undefined4 arenaA;
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  
  if (*(int *)(program + 0x374) == 0) {
    inputRegisterCount = 0;
    switch(param_7) {
    case 0:
      inputRegisterCount = 1;
      break;
    case 1:
      inputRegisterCount = 2;
      break;
    case 2:
      inputRegisterCount = 3;
      break;
    case 3:
      inputRegisterCount = 4;
      break;
    case 4:
      inputRegisterCount = 6;
    }
    Block__successorCount(*(undefined4 *)(program + PROG_entryBlock));
    successor = Block__getSuccessor(*(undefined4 *)(program + PROG_entryBlock),0);
    arenaA = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
    allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
    *allocation = arenaA;
    mergeInst = allocation + 1;
    IRMerge__ctor_109cfc(mergeInst,0x83,*(undefined4 *)(program + PROG_compiler));
    operandRecord2 = IRInst__getOperandRecord(mergeInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0x39;
    *(undefined4 *)(operandRecord2 + 8) = 0;
    mergeSlotCount = inputRegisterCount;
    if (3 < inputRegisterCount) {
      mergeSlotCount = 3;
    }
    allocation[0x22] = mergeSlotCount;
    secondMerge = (undefined4 *)0x0;
    if (inputRegisterCount != 0) {
      loopIndex = 0;
      loopIndex2 = 1;
      secondMergeIndex = -2;
      do {
        hwRegister = loopIndex + 2;
        inst = IRInst__create(0x31,*(undefined4 *)(program + PROG_compiler));
        RegAlloc__testBit42c(program,hwRegister);
        operandRecord = IRInst__getOperandRecord(inst,0);
        *(int *)(operandRecord + 8) = hwRegister;
        *(undefined4 *)(operandRecord + 0xc) = 0x10;
        *(undefined4 *)((int)inst + 0x9c) = 0x10101;
        Program__markHwRegUsed(program,hwRegister);
        RegAlloc__clearBit430(program,hwRegister);
        hwDescription = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
        hwInputRegister = (**(code **)(*hwDescription + 0x9c))(hwDescription,loopIndex,*(int *)(program + PROG_compiler));
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 8) = hwInputRegister;
        *(undefined4 *)(operandRecord + 0xc) = 0x1f;
        hwDescription = *(int **)(*(int *)(program + PROG_compiler) + COMP_target);
        (**(code **)(*hwDescription + 0xa0))(local_58,hwDescription,loopIndex,*(int *)(program + PROG_compiler));
        inputSelectWord = local_58[0];
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 0x10) = inputSelectWord;
        ((int (*)())Program__appendInst)(program,inst,successor);
        if ((int)loopIndex < 3) {
          IRInst__setOperandRef(mergeInst,loopIndex2,*(undefined4 *)((int)inst + 0x8c));
          if (loopIndex2 == 0) {
            allocation[0x28] = 0;
          }
          else {
            operandRecord = IRInst__getOperandRecord(mergeInst,loopIndex2);
            *(undefined4 *)(operandRecord + 0x10) = 0;
          }
        }
        else {
          if (secondMerge == (undefined4 *)0x0) {
            arenaA = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
            instAlloc = (undefined4 *)Arena__alloc(arenaA,0x168);
            *instAlloc = arenaA;
            secondMerge = instAlloc + 1;
            IRMerge__ctor_109cfc(secondMerge,0x83,*(undefined4 *)(program + PROG_compiler));
            operandRecord = IRInst__getOperandRecord(secondMerge,0);
            *(undefined4 *)(operandRecord + 0xc) = 0x39;
            mergeOperandCount = 4;
            *(undefined4 *)(operandRecord + 8) = 1;
            if (inputRegisterCount == 4) {
              mergeOperandCount = 2;
            }
            instAlloc[0x22] = mergeOperandCount;
          }
          IRInst__setOperandRef(secondMerge,secondMergeIndex,*(undefined4 *)((int)inst + 0x8c));
          if (secondMergeIndex == 0) {
            secondMerge[0x27] = 0;
          }
          else {
            operandRecord = IRInst__getOperandRecord(secondMerge,secondMergeIndex);
            *(undefined4 *)(operandRecord + 0x10) = 0;
          }
        }
        arenaA = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
        instAlloc = (undefined4 *)Arena__alloc(arenaA,0x168);
        *instAlloc = arenaA;
        puVar8 = instAlloc + 1;
        IRLoadTemp__ctor_109428(puVar8,0x7a,*(undefined4 *)(program + PROG_compiler));
        operandRecord = IRInst__getOperandRecord(puVar8,0);
        *(undefined4 *)(operandRecord + 0xc) = 0x10;
        loopIndex = loopIndex + 1;
        *(int *)(operandRecord + 8) = hwRegister;
        loopIndex2 = loopIndex2 + 1;
        secondMergeIndex = secondMergeIndex + 1;
        ((int (*)())Program__appendInst)(program,puVar8,*(undefined4 *)(program + PROG_entryBlock));
      } while (inputRegisterCount != loopIndex);
    }
    ((int (*)())Program__appendInst)(program,mergeInst,successor);
    if (secondMerge == (undefined4 *)0x0) {
      *(undefined4 **)(program + 0x374) = mergeInst;
    }
    else {
      mergeOperandIndex = 2;
      if (inputRegisterCount != 4) {
        mergeOperandIndex = 4;
      }
      IRInst__setOperandRef(secondMerge,mergeOperandIndex,allocation[0x24]);
      ((int (*)())Program__appendInst)(program,secondMerge,successor);
      *(undefined4 **)(program + 0x374) = secondMerge;
    }
  }
  arenaAt374 = *(undefined4 *)(*(int *)(program + PROG_compiler) + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
  *allocation = arenaAt374;
  projectionInst = allocation + 1;
  IRProjection__ctor_109e28(projectionInst,0x84,*(undefined4 *)(program + PROG_compiler));
  inputTempId = *(int *)(*(int *)(program + PROG_compiler) + 0x3b4) + 1;
  *(int *)(*(int *)(program + PROG_compiler) + 0x3b4) = inputTempId;
  inputVReg = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x3a,inputTempId,0);
  *(undefined4 *)(inputVReg + 0x30) = 2;
  IRInst__setOperandRef(projectionInst,0,inputVReg);
  descriptorWord = *descriptor;
  registerFile = Program__registerFileOfIlType(program,*descriptor >> 0x10 & 0x3f);
  operandRecord2 = IRInst__getOperandRecord(projectionInst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
  *(uint *)(operandRecord2 + 8) = (uint)(ushort)descriptorWord;
  local_68[0] = 0x10203;
  ((int (*)())Program__applySourceTokenToOperand)(program,local_68,descriptor,1,projectionInst);
  allocation[0x4d] = 1;
  DList__pushBack(list,projectionInst);
  inst = IRInst__create(0x31,*(undefined4 *)(program + PROG_compiler));
  registerFile = Program__registerFileOfIlType(program,param_6);
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
  *(undefined4 *)(operandRecord2 + 8) = projectionDestRegister;
  *(undefined4 *)((int)inst + 0x9c) = 0x10101;
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = 0x3a;
  *(int *)(operandRecord2 + 8) = inputTempId;
  IRInst__appendSource(inst,*(undefined4 *)(*(int *)(program + 0x374) + 0x8c));
  DList__pushBack(list,inst);
  return;
}

/* FUN_000f9a58 @ 0xf9a58 (2736 bytes) */
int FUN_000f9a58(pass, list, descriptor, unusedArg4, modeSelector)
  int pass;
  undefined4 list;
  uint *descriptor;
  undefined4 unusedArg4;
  int modeSelector;
{
  uint sourceTokenWord;
  uint laneMaskWord;
  uint oneLaneMask;
  uint zeroLaneMask;
  int hardwareCheckResult;
  int registerFileSupported;
  bool forceExportPath;
  bool hasSetupInstFlag;
  uint relativeOffset;
  uint loopCounter;
  int sourceNumber;
  int tempId;
  int destRegisterFile;
  int laneIndex;
  int newTempIndex;
  int laneCount;
  undefined4 instWord0xac;
  undefined4 operandSelectWord;
  undefined4 instWord0xc4;
  undefined4 virtualRegister;
  undefined4 arenaA;
  undefined4 registerMap;
  int psnPackedLaneComponentResult;
  void *newInst;
  int operandRecord2;
  int operandRecord;
  int operandRecord3;
  bool notLastLane;
  bool useExportInst;
  void *writeMaskCursor;
  void *setupInst;
  int descriptorTestResult;
  undefined4 registerFile;
  undefined4 *allocation;
  int destRegisterIndex;
  uint *sourceDescriptor;
  uint destRegisterType;
  uint sourceRegisterType;
  uint sourceRegisterIndex;
  int newTempIndex2;
  uint setupLiteralIndex;
  code *registerFileQuery;
  uint sourceOffsetConstant;
  uint destTokenWord;
  int *hardwareInfo;
  undefined4 operandRegisterFile;
  int operandEncodable;
  undefined4 *rewriteInst;
  double staleFprArg1;
  undefined4 operandSelectWordTemp;
  undefined4 identitySwizzleTokens [7];
  
  destRegisterIndex = (int)(short)*descriptor;
  destRegisterType = *descriptor >> 0x10 & 0x3f;
  if (((*descriptor & 0x400000) == 0) || (setupLiteralIndex = descriptor[1] >> 9 & 0xf, setupLiteralIndex == 0)) {
    setupInst = (void *)0x0;
    laneIndex = 0;
  }
  else {
    laneIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = laneIndex;
    *(short *)((int)descriptor + 2) = (short)laneIndex;
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    setupInst = IRInst__create(0x13,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(setupInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    operandRecord2 = IRInst__getOperandRecord(setupInst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    staleFprArg1 = (double)*(float *)(&DAT_001aa9fc + setupLiteralIndex * 4);
    *(int *)(operandRecord2 + 8) = laneIndex;
    ((void (*)())IRInst__makeLiteralVec4Float)(setupInst,pass,2,staleFprArg1,staleFprArg1,staleFprArg1,staleFprArg1);
    DList__pushBack(list,setupInst);
  }
  zeroLaneMask = 0;
  loopCounter = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,loopCounter);
    notLastLane = loopCounter != 3;
    zeroLaneMask = zeroLaneMask | (uint)(psnPackedLaneComponentResult == 2) << (loopCounter & 0x3f);
    loopCounter = loopCounter + 1;
  } while (notLastLane);
  if (zeroLaneMask != 0) {
    if (setupInst == (void *)0x0) {
      laneIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = laneIndex;
      *(short *)((int)descriptor + 2) = (short)laneIndex;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    }
    setupInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(setupInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    ((void (*)())IRInst__makeLiteralVec4Float)(setupInst,pass,1,0.0,0.0,0.0,0.0);
    laneCount = 4;
    loopCounter = 0;
    writeMaskCursor = setupInst;
    do {
      if (((int)zeroLaneMask >> (loopCounter & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)writeMaskCursor + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)writeMaskCursor + 0x9c) = 0;
      }
      loopCounter = loopCounter + 1;
      writeMaskCursor = (void *)((int)writeMaskCursor + 1);
      laneCount = laneCount + -1;
    } while (laneCount != 0);
    DList__pushBack(list,setupInst);
  }
  oneLaneMask = 0;
  loopCounter = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,loopCounter);
    notLastLane = loopCounter != 3;
    oneLaneMask = oneLaneMask | (uint)(psnPackedLaneComponentResult == 3) << (loopCounter & 0x3f);
    loopCounter = loopCounter + 1;
  } while (notLastLane);
  if (oneLaneMask != 0) {
    if (setupInst == (void *)0x0) {
      laneIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = laneIndex;
      *(short *)((int)descriptor + 2) = (short)laneIndex;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    }
    setupInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(setupInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    ((void (*)())IRInst__makeLiteralVec4Float)(setupInst,pass,1,1.0,1.0,1.0,1.0);
    laneCount = 4;
    loopCounter = 0;
    writeMaskCursor = setupInst;
    do {
      if (((int)oneLaneMask >> (loopCounter & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)writeMaskCursor + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)writeMaskCursor + 0x9c) = 0;
      }
      loopCounter = loopCounter + 1;
      writeMaskCursor = (void *)((int)writeMaskCursor + 1);
      laneCount = laneCount + -1;
    } while (laneCount != 0);
    DList__pushBack(list,setupInst);
  }
  laneMaskWord = 0;
  if ((*descriptor & 0x400000) != 0) {
    laneMaskWord = descriptor[1];
    laneMaskWord = (uint)((laneMaskWord & 0xc0) == 0) |
             (uint)((laneMaskWord & 0x30) == 0) << 8 |
             (uint)((laneMaskWord & 0xc) == 0) << 0x10 | (uint)((laneMaskWord & 3) == 0) << 0x18;
  }
  descriptorTestResult = FUN_0019eb30(descriptor);
  if (descriptorTestResult != 0) {
    setupInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(setupInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    operandRecord2 = IRInst__getOperandRecord(setupInst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    DList__pushBack(list,setupInst);
  }
  destTokenWord = *descriptor;
  if (((destTokenWord & 0x400000) == 0) || ((descriptor[1] & 0x100) == 0)) {
LAB_000f9f08:
    hasSetupInstFlag = false;
  }
  else {
    hardwareInfo = *(int **)(*(int *)(pass + 8) + 0x30c);
    registerFileQuery = *(code **)(*hardwareInfo + 0x78);
    registerFile = Program__registerFileOfIlType(pass,destRegisterType);
    registerFileSupported = (*registerFileQuery)(hardwareInfo,registerFile);
    if (registerFileSupported == 0) {
      destRegisterFile = Program__registerFileOfIlType(pass,*descriptor >> 0x10 & 0x3f);
      if (destRegisterFile == 9) {
        destTokenWord = *descriptor;
        goto LAB_000f9f08;
      }
      Program__registerFileOfIlType(pass,*descriptor >> 0x10 & 0x3f);
      destTokenWord = *descriptor;
      hasSetupInstFlag = false;
    }
    else {
      hardwareInfo = *(int **)(*(int *)(pass + 8) + 0x30c);
      hardwareCheckResult = (**(code **)(*hardwareInfo + 0x80))(hardwareInfo);
      if (hardwareCheckResult == 0) {
        if (setupInst == (void *)0x0) {
          laneIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(pass + 8) + 0x3ac) = laneIndex;
          *(short *)((int)descriptor + 2) = (short)laneIndex;
          *descriptor = *descriptor & 0xffc0ffff | 0x40000;
        }
        setupInst = (void *)((int (*)())Program__emitClampPair)(pass,laneIndex,list);
        destTokenWord = *descriptor;
        if ((destTokenWord & 0x400000) == 0) goto LAB_000f9f08;
        hasSetupInstFlag = false;
        descriptor[1] = descriptor[1] & 0xfffffeff;
      }
      else {
        destTokenWord = *descriptor;
        hasSetupInstFlag = true;
      }
    }
  }
  if (setupInst != (void *)0x0) {
    if ((destTokenWord & 0x1800000) == 0x800000) {
      if (*(int *)(pass + 0x3e4) == 0) {
        *(undefined4 *)(pass + 0x3e4) = 1;
        registerFile = Program__registerFileOfIlType(pass,destRegisterType);
        *(undefined4 *)(pass + 0x3f4) = registerFile;
      }
      else {
        Program__registerFileOfIlType(pass,destRegisterType);
      }
      registerMap = *(undefined4 *)(pass + 0x3ac);
      tempId = *(int *)(*(int *)(pass + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(pass + 8) + 0x3c0) = tempId;
      tempId = VRegPool__findOrCreate(registerMap,0x2a,tempId,0);
      *(int *)(tempId + 0x30) = destRegisterIndex;
      IRInst__setOperandRef(setupInst,0,tempId);
      *descriptor = *descriptor & 0xfe7fffff;
    }
    else {
      registerFile = Program__registerFileOfIlType(pass,destRegisterType);
      operandRecord = IRInst__getOperandRecord(setupInst,0);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = destRegisterIndex;
    }
    if (hasSetupInstFlag) {
      *(undefined4 *)((int)setupInst + 0x120) = 1;
    }
    if ((*descriptor & 0x400000) != 0) {
      descriptor[1] = descriptor[1] & 0xfffffeff;
    }
    laneIndex = 0;
    do {
      psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,laneIndex);
      if (psnPackedLaneComponentResult == 0) {
        *(undefined1 *)((int)setupInst + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)setupInst + 0x9c) = 0;
      }
      notLastLane = laneIndex != 3;
      setupInst = (void *)((int)setupInst + 1);
      laneIndex = laneIndex + 1;
    } while (notLastLane);
    destTokenWord = *descriptor;
    if ((destTokenWord & 0x400000) != 0) {
      descriptor[1] = descriptor[1] & 0xffffff00 | 0x55;
    }
  }
  if ((destRegisterType != 0x1f) || ((*(uint *)(pass + 0x30) & 0x4000) == 0)) {
    forceExportPath = false;
    useExportInst = false;
  }
  else {
    forceExportPath = true;
    useExportInst = true;
  }
  if (((undefined4 *)(destTokenWord & 0x3f0000) != 0x001b0000) && (!forceExportPath)) goto LAB_000fa744;
  sourceNumber = 1;
  newTempIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex;
  destTokenWord = *descriptor;
  sourceRegisterIndex = (uint)(ushort)*descriptor;
  sourceRegisterType = destTokenWord >> 0x10 & 0x3f;
  if ((int)destTokenWord < 0) {
    sourceNumber = 2;
    sourceRegisterIndex = sourceRegisterIndex | descriptor[1] << 0x10;
  }
  if ((destTokenWord & 0x400000) != 0) {
    sourceNumber = sourceNumber + 1;
  }
  if ((destTokenWord & 0x1800000) == 0x1000000) {
    sourceDescriptor = descriptor + sourceNumber;
    if (!useExportInst) {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      rewriteInst = allocation + 1;
      IRMemStore__ctor_1071fc(rewriteInst,0xfc,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,sourceRegisterType);
      operandRecord3 = IRInst__getOperandRecord(rewriteInst,0);
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(uint *)(operandRecord3 + 8) = sourceRegisterIndex;
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord3 = IRInst__getOperandRecord(rewriteInst,1);
      allocation[0x28] = laneMaskWord;
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(int *)(operandRecord3 + 8) = newTempIndex;
      if ((*descriptor & 0x4000000) == 0) goto LAB_000fa1bc;
      newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
      relativeOffset = descriptor[sourceNumber + 2];
      newInst = IRInst__create(0xc6,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(newInst,0);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex2;
      sourceTokenWord = *sourceDescriptor;
      registerFile = Program__registerFileOfIlType(pass,*sourceDescriptor >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(newInst,1);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = (uint)(ushort)sourceTokenWord;
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,relativeOffset,relativeOffset,relativeOffset,relativeOffset);
      DList__pushBack(list,newInst);
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(rewriteInst,2);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex2;
    }
    else {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      rewriteInst = allocation + 1;
      IRGeomExport__ctor_108a50(rewriteInst,0xf9,*(undefined4 *)(pass + 8));
      allocation[0x28] = laneMaskWord;
      allocation[0x22] = 2;
      if ((*descriptor & 0x4000000) != 0) {
        sourceRegisterIndex = sourceRegisterIndex + descriptor[sourceNumber + 2];
      }
      allocation[0x51] = sourceRegisterIndex;
      allocation[0x50] = 0x24;
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(rewriteInst,0,virtualRegister);
      operandRecord = IRInst__getOperandRecord(rewriteInst,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex;
LAB_000fa1bc:
      sourceTokenWord = *sourceDescriptor;
      registerFile = Program__registerFileOfIlType(pass,*sourceDescriptor >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(rewriteInst,2);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = (uint)(ushort)sourceTokenWord;
      if (useExportInst) goto LAB_000fa4f8;
    }
    registerFile = Program__registerFileOfIlType(pass,sourceRegisterType);
    operandRecord = IRInst__getOperandRecord(rewriteInst,3);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(uint *)(operandRecord + 8) = sourceRegisterIndex;
    identitySwizzleTokens[0] = 0x10203;
    ((int (*)())Program__applySourceTokenToOperand)(pass,identitySwizzleTokens,sourceDescriptor,2,rewriteInst);
  }
  else if ((destTokenWord & 0x1800000) == 0) {
    sourceOffsetConstant = 0;
    if ((destTokenWord & 0x4000000) != 0) {
      sourceOffsetConstant = descriptor[sourceNumber];
    }
    if (useExportInst) {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      rewriteInst = allocation + 1;
      IRGeomExport__ctor_108770(rewriteInst,*(undefined4 *)(pass + 8));
      allocation[0x28] = laneMaskWord;
      allocation[0x50] = 0x24;
      allocation[0x51] = sourceRegisterIndex;
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(rewriteInst,0,virtualRegister);
      operandRecord = IRInst__getOperandRecord(rewriteInst,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex;
    }
    else {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      rewriteInst = allocation + 1;
      IRMemStore__ctor_1071fc(rewriteInst,0xfc,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,sourceRegisterType);
      operandRecord = IRInst__getOperandRecord(rewriteInst,0);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = sourceRegisterIndex;
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(rewriteInst,1);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex;
      ((int (*)())IRInst__setIntConstantOperand4)(rewriteInst,pass,2,sourceOffsetConstant,sourceOffsetConstant,sourceOffsetConstant,sourceOffsetConstant);
      allocation[0x28] = laneMaskWord;
    }
  }
  else {
    rewriteInst = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  operandRecord = IRInst__getOperandRecord(rewriteInst,2);
  operandSelectWordTemp = *(undefined4 *)(operandRecord + 0x10);
  hardwareInfo = *(int **)(*(int *)(pass + 8) + 0x30c);
  operandEncodable = (**(code **)(*hardwareInfo + 0x104))(hardwareInfo,rewriteInst,2,&operandSelectWordTemp,0);
  if (operandEncodable == 0) {
    newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRegisterFile = rewriteInst[0x32];
    instWord0xc4 = rewriteInst[0x31];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = operandRegisterFile;
    *(undefined4 *)(operandRecord + 8) = instWord0xc4;
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(rewriteInst,2);
    operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
    DList__pushBack(list,newInst);
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(rewriteInst,2);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandEncodable = IRInst__getOperandRecord(rewriteInst,2);
    *(undefined4 *)(operandEncodable + 0x10) = 0;
  }
  if ((!useExportInst) &&
     (hardwareInfo = *(int **)(*(int *)(pass + 8) + 0x30c),
     operandEncodable = (**(code **)(*hardwareInfo + 0x104))(hardwareInfo,rewriteInst,1,&operandSelectWordTemp,0), operandEncodable == 0)) {
    newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRegisterFile = rewriteInst[0x2c];
    instWord0xac = rewriteInst[0x2b];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = operandRegisterFile;
    *(undefined4 *)(operandRecord + 8) = instWord0xac;
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(rewriteInst,1);
    operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
    DList__pushBack(list,newInst);
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(rewriteInst,1);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(rewriteInst,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x10203;
  }
  DList__pushBack(list,rewriteInst);
  *descriptor = *descriptor & 0xffc0ffff | 0x40000;
  *(short *)((int)descriptor + 2) = (short)newTempIndex;
LAB_000fa744:
  if ((destRegisterType == 0x1f) && ((*(uint *)(pass + 0x30) & 0x200000) != 0)) {
    newTempIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex;
    newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
    newInst = IRInst__create(0xcc,*(undefined4 *)(pass + 8));
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 8) = 0;
    *(undefined4 *)(operandRecord + 0xc) = 0x1f;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x1010101;
    if (modeSelector == 1) {
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,1,1,1,1);
    }
    else if (modeSelector < 2) {
      if (modeSelector == 0) {
        ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,0,0,0,0);
      }
    }
    else if (modeSelector == 2) {
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,2,2,2,2);
    }
    else if (modeSelector == 3) {
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,3,3,3,3);
    }
    DList__pushBack(list,newInst);
    newInst = IRInst__create(0x24,*(undefined4 *)(pass + 8));
    registerFile = Program__registerFileOfIlType(pass,0x1f);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = destRegisterIndex;
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex2;
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,2);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex;
    registerFile = Program__registerFileOfIlType(pass,0x1f);
    operandRecord = IRInst__getOperandRecord(newInst,3);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = destRegisterIndex;
    DList__pushBack(list,newInst);
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    *(short *)((int)descriptor + 2) = (short)newTempIndex;
  }
  return;
}

/* Template__bindOperand @ 0xfa958 (1132 bytes) */
int Template__bindOperand(program, opcodeIndex, operandIndex, translateState, inst, flagA, modeWord, stagedSelectPtr, loopStackData, flagB, block)
  int program;
  int opcodeIndex;
  int operandIndex;
  int translateState;
  int inst;
  undefined4 flagA;
  undefined4 modeWord;
  undefined4 stagedSelectPtr;
  undefined4 loopStackData;
  undefined4 flagB;
  undefined4 block;
{
  uint registerType2;
  uint registerType;
  uint *destDescriptor;
  int registerIndex2;
  int splitMov;
  int resultInst;
  int foldedResult;
  int fullSelectWord;
  undefined4 registerFileB;
  undefined4 registerFile;
  int loopCounter;
  undefined4 newInst2;
  int operandRecord2;
  int operandRecord4;
  int newInst;
  int operandRecord;
  int operandRecord3;
  int loopIndex;
  int splitTempIndex;
  undefined4 zeroArg;
  int compiler;
  int loopCounterB;
  uint *sourceDescriptorPtr;
  int newTempIndex;
  int registerIndex;
  uint useDestTable;
  undefined4 laneSelectEntry;
  uint *descriptor;
  uint operandSlotInfo;
  undefined4 destSelectWord;
  undefined4 descriptorCopy;
  
  operandSlotInfo = *(uint *)(PTR_DAT_001e8b88 + opcodeIndex * 4);
  if (operandIndex != 0) {
    useDestTable = operandSlotInfo >> 0x1c & 1;
LAB_000fabd8:
    if (useDestTable == 0) {
      sourceDescriptorPtr = *(uint **)(((operandSlotInfo >> 0x17 & 7) * 5 + (operandSlotInfo >> 0x1d)) * 4 +
                         *(int *)(translateState + 0x6c));
      descriptor = sourceDescriptorPtr;
    }
    else {
      sourceDescriptorPtr = (uint *)0x0;
      descriptor = *(uint **)(((operandSlotInfo >> 0x17 & 7) * 5 + (operandSlotInfo >> 0x1d)) * 4 +
                          *(int *)(translateState + 100));
      descriptorCopy = CONCAT22((*(unsigned short *)((unsigned char *)&(descriptorCopy) + 0)),(short)*descriptor);
      descriptorCopy = *descriptor & 0x1800000 | *descriptor & 0x3f0000 | descriptorCopy & 0xfe40ffff;
      descriptor = &descriptorCopy;
    }
    registerType = *descriptor >> 0x10 & 0x3f;
    compiler = *(int *)(program + 8);
    if ((((*descriptor & 0x3f0000) == 0x100000) && (compiler != 0)) &&
       ((*(uint *)(*(int *)(compiler + 0x30c) + 8) & 0x80) != 0)) {
      registerIndex = 0xf;
    }
    else {
      registerIndex = (int)(short)*descriptor;
    }
    if ((registerType == 0x12) && ((operandSlotInfo & 0x3800000) != 0)) {
      registerIndex = 0;
      registerType = 0x13;
    }
    if (((operandSlotInfo >> 0x1b & 1) == 0) && ((registerType == 1 || (registerType == 0x22)))) {
      splitTempIndex = *(int *)(compiler + 0x3ac) + -1;
      *(int *)(compiler + 0x3ac) = splitTempIndex;
      newInst2 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      operandRecord = IRInst__getOperandRecord(newInst2,0);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = splitTempIndex;
      registerFileB = Program__registerFileOfIlType(program,registerType);
      operandRecord = IRInst__getOperandRecord(newInst2,1);
      *(undefined4 *)(operandRecord + 0xc) = registerFileB;
      *(int *)(operandRecord + 8) = registerIndex;
      ((int (*)())Program__applySourceTokenToOperand)(program,stagedSelectPtr,descriptor,operandIndex,newInst2);
      ((int (*)())Program__appendInst)(program,newInst2,block);
      registerType = 4;
      *descriptor = *descriptor & 0xfe3fffff;
      *(short *)((int)descriptor + 2) = (short)splitTempIndex;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
      registerIndex = splitTempIndex;
    }
    else {
      ((int (*)())Program__applySourceTokenToOperand)(program,stagedSelectPtr,sourceDescriptorPtr,operandIndex,inst);
    }
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = registerIndex;
    return 0;
  }
  useDestTable = 0;
  if ((operandSlotInfo >> 0x1c & 1) == 0) goto LAB_000fabd8;
  destDescriptor = *(uint **)(((operandSlotInfo >> 0x17 & 7) * 5 + (operandSlotInfo >> 0x1d)) * 4 + *(int *)(translateState + 100));
  registerIndex2 = (int)(short)*destDescriptor;
  registerType2 = *destDescriptor >> 0x10 & 0x3f;
  registerFile = Program__registerFileOfIlType(program,registerType2);
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = registerFile;
  zeroArg = 0;
  *(int *)(operandRecord + 8) = registerIndex2;
  foldedResult = inst;
  ((int (*)())IRInst__applyDescriptorSelects)(program,loopStackData,modeWord,destDescriptor,0,inst,flagB);
  foldedResult = OpcodeTraits__instFlagBit2_113734(*(undefined4 *)(program + 8),inst,modeWord,destDescriptor,zeroArg,foldedResult,flagB);
  if (foldedResult != 0) {
    operandRecord4 = IRInst__getOperandRecord(inst,0);
    loopIndex = 0;
    resultInst = 0;
    loopCounter = 0;
    destSelectWord = *(undefined4 *)(operandRecord4 + 0x10);
    loopCounterB = 4;
    do {
      if (*(char *)((int)&destSelectWord + loopCounter) == '\0') {
        loopIndex = loopIndex + 1;
        resultInst = loopCounter;
      }
      loopCounter = loopCounter + 1;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
    if (1 < loopIndex) {
      descriptorCopy = DAT_001aa9e0;
      *(undefined1 *)((int)&descriptorCopy + resultInst) = 0;
      laneSelectEntry = *(undefined4 *)(resultInst * 4 + 0x1dc7bc);
      splitMov = IRInst__create(0x31,*(undefined4 *)(program + 8));
      registerFile = Program__registerFileOfIlType(program,registerType2);
      operandRecord3 = IRInst__getOperandRecord(splitMov,0);
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(int *)(operandRecord3 + 8) = registerIndex2;
      *(undefined4 *)(splitMov + 0x9c) = destSelectWord;
      registerFile = Program__registerFileOfIlType(program,registerType2);
      operandRecord3 = IRInst__getOperandRecord(splitMov,1);
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(int *)(operandRecord3 + 8) = registerIndex2;
      operandRecord3 = IRInst__getOperandRecord(splitMov,1);
      *(undefined4 *)(operandRecord3 + 0x10) = laneSelectEntry;
      *(uint *)(inst + 0x9c) = descriptorCopy;
      goto LAB_000fab1c;
    }
  }
  splitMov = 0;
LAB_000fab1c:
  if ((operandSlotInfo >> 0x1a & 1) != 0) {
    return splitMov;
  }
  operandRecord4 = IRInst__getOperandRecord(inst,0);
  fullSelectWord = DAT_001aa9dc;
  if (*(int *)(operandRecord4 + 0x10) == DAT_001aa9dc) {
    return splitMov;
  }
  newInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
  newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
  registerFile = Program__registerFileOfIlType(program,registerType2);
  operandRecord4 = IRInst__getOperandRecord(newInst,0);
  *(undefined4 *)(operandRecord4 + 0xc) = registerFile;
  *(int *)(operandRecord4 + 8) = registerIndex2;
  operandRecord2 = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = 0;
  *(int *)(operandRecord2 + 8) = newTempIndex;
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord2 + 0xc) = 0;
  *(int *)(operandRecord2 + 8) = newTempIndex;
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(newInst + 0x9c) = *(undefined4 *)(operandRecord2 + 0x10);
  *(int *)(inst + 0x9c) = fullSelectWord;
  return newInst;
}

/* Program__createIfBlock @ 0xfadc4 (240 bytes) */
int Program__createIfBlock(program, inst, blockKey, elseTarget, vector, scopeStack, sourceArg)
  int program;
  undefined4 inst;
  undefined4 blockKey;
  undefined4 elseTarget;
  uint *vector;
  int scopeStack;
  undefined4 sourceArg;
{
  uint scopeCount;
  int *scopeTop;
  undefined4 arena;
  int operandRecord2;
  undefined1 broadcastByte;
  int loopCounter;
  undefined4 *allocation;
  int operandRecord;
  int *vectorSlot;
  undefined4 *ifHeader;
  undefined4 broadcastSelect;
  uint vectorCount;
  int loopCounterB;
  undefined4 local_48 [8];
  
  arena = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  allocation = (undefined4 *)Arena__alloc(arena,0x15c);
  *allocation = arena;
  ifHeader = allocation + 1;
  IfHeader__ctor_ea6d0(ifHeader,inst,elseTarget,0,*(undefined4 *)(program + 8));
  Block__setField0xb8AndChildren(ifHeader,blockKey);
  local_48[0] = DAT_001aa9a8;
  ((int (*)())Template__bindOperand)(program,5,1,sourceArg,inst,1,DAT_001aa9dc,local_48,scopeStack,1,ifHeader);
  operandRecord = IRInst__getOperandRecord(inst,1);
  loopCounter = 0;
  loopCounterB = 4;
  (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0)) = (undefined1)((uint)*(undefined4 *)(operandRecord + 0x10) >> 0x18);
  broadcastByte = (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0));
  local_48[0] = *(undefined4 *)(operandRecord + 0x10);
  do {
    *(undefined1 *)((int)local_48 + loopCounter) = broadcastByte;
    broadcastSelect = local_48[0];
    loopCounter = loopCounter + 1;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0x10) = broadcastSelect;
  IRInst__bindOperandRegisters(program,inst);
  vectorCount = 0;
  if (vector[1] != 0) {
    allocation[0x53] = 0;
    vectorCount = vector[1];
  }
  if (vectorCount < *vector) {
    _memset((void *)(vectorCount * 4 + vector[2]),0,4);
    vectorSlot = (int *)(vectorCount * 4 + vector[2]);
    vector[1] = vectorCount + 1;
  }
  else {
    vectorSlot = (int *)Vector__elementRefGrow(vector,vectorCount);
  }
  *vectorSlot = (int)ifHeader;
  scopeCount = *(uint *)(scopeStack + 4);
  if (scopeCount != 0) {
    scopeTop = (int *)0x0;
    if (scopeCount - 1 < scopeCount) {
      scopeTop = (int *)((scopeCount - 1) * 4 + *(int *)(scopeStack + 8));
    }
    *(int *)(*scopeTop + 300) = *(int *)(*scopeTop + 300) + 1;
  }
  return ifHeader;
}

/* Program__createConstantVReg @ 0xfafa4 (652 bytes) */
int Program__createConstantVReg(program, ilRegisterType, registerIndex, valueCount, values)
  int program;
  int ilRegisterType;
  undefined4 registerIndex;
  int valueCount;
  undefined4 *values;
{
  undefined4 replicatedValue;
  undefined4 laneValue0;
  int *registerListSlot;
  int laneRecord;
  uint loopCounter;
  undefined4 registerFile;
  int virtualRegister;
  uint laneBit;
  byte usedLaneMask;
  undefined4 laneValue;
  int registerMap;
  int *firstRecordSlot;
  int constRecord;
  uint *registerList;
  undefined4 registerMapArg;
  uint registerListCount;
  
  registerMapArg = *(undefined4 *)(program + 0x3ac);
  registerFile = Program__registerFileOfIlType(program,ilRegisterType);
  virtualRegister = VRegPool__findOrCreate(registerMapArg,registerFile,registerIndex,0);
  firstRecordSlot = *(int **)(virtualRegister + 0x18);
  if (*firstRecordSlot == 0) {
    firstRecordSlot = (int *)Vector__elementRefGrow(firstRecordSlot,0);
  }
  else {
    if (firstRecordSlot[1] == 0) {
      *(undefined4 *)firstRecordSlot[2] = 0;
      firstRecordSlot[1] = 1;
    }
    firstRecordSlot = (int *)firstRecordSlot[2];
  }
  registerMap = *(int *)(program + 0x3ac);
  constRecord = *firstRecordSlot;
  registerList = *(uint **)(registerMap + 0x20);
  registerListCount = registerList[1];
  if (registerListCount < *registerList) {
    _memset(registerListCount * 4 + registerList[2],0,4);
    registerListSlot = (int *)(registerListCount * 4 + registerList[2]);
    registerList[1] = registerListCount + 1;
  }
  else {
    registerListSlot = (int *)Vector__elementRefGrow(registerList,registerListCount);
  }
  *registerListSlot = constRecord;
  *(int *)(registerMap + 0x1c) = *(int *)(registerMap + 0x1c) + 1;
  if (ilRegisterType == 1) {
    if (0 < valueCount) {
      loopCounter = 0;
      laneRecord = constRecord;
      do {
        laneValue = values[loopCounter];
        *(undefined4 *)(laneRecord + 0x1c) = 2;
        *(undefined4 *)(laneRecord + 0x20) = laneValue;
        laneBit = loopCounter & 0x3f;
        loopCounter = loopCounter + 1;
        laneRecord = laneRecord + 0x18;
        *(byte *)(constRecord + 0x15c) = (byte)(1 << laneBit) | *(byte *)(constRecord + 0x15c);
        valueCount = valueCount + -1;
      } while (valueCount != 0);
    }
  }
  else if (ilRegisterType < 2) {
    if (ilRegisterType == 0) {
      if (valueCount < 1) {
        usedLaneMask = *(byte *)(constRecord + 0x15c);
      }
      else {
        loopCounter = 0;
        laneRecord = constRecord;
        do {
          laneValue0 = *values;
          *(undefined4 *)(laneRecord + 0x1c) = 4;
          *(undefined4 *)(laneRecord + 0x20) = laneValue0;
          laneBit = loopCounter & 0x3f;
          loopCounter = loopCounter + 1;
          laneRecord = laneRecord + 0x18;
          usedLaneMask = (byte)(1 << laneBit) | *(byte *)(constRecord + 0x15c);
          *(byte *)(constRecord + 0x15c) = usedLaneMask;
          valueCount = valueCount + -1;
        } while (valueCount != 0);
      }
      replicatedValue = *(undefined4 *)(constRecord + 0x20);
      *(undefined4 *)(constRecord + 100) = 4;
      *(byte *)(constRecord + 0x15c) = usedLaneMask | 0xe;
      *(undefined4 *)(constRecord + 0x68) = replicatedValue;
      *(undefined4 *)(constRecord + 0x38) = replicatedValue;
      *(undefined4 *)(constRecord + 0x50) = replicatedValue;
      *(undefined4 *)(constRecord + 0x34) = 4;
      *(undefined4 *)(constRecord + 0x4c) = 4;
    }
  }
  else if (ilRegisterType == 2) {
    if (0 < valueCount) {
      loopCounter = 0;
      laneRecord = constRecord;
      do {
        laneValue = values[loopCounter];
        *(undefined4 *)(laneRecord + 0x1c) = 3;
        *(undefined4 *)(laneRecord + 0x20) = laneValue;
        laneBit = loopCounter & 0x3f;
        loopCounter = loopCounter + 1;
        laneRecord = laneRecord + 0x18;
        *(byte *)(constRecord + 0x15c) = (byte)(1 << laneBit) | *(byte *)(constRecord + 0x15c);
        valueCount = valueCount + -1;
      } while (valueCount != 0);
    }
  }
  else if ((ilRegisterType == 0x1d) && (0 < valueCount)) {
    loopCounter = 0;
    laneRecord = constRecord;
    do {
      laneValue = values[loopCounter];
      *(undefined4 *)(laneRecord + 0x1c) = 3;
      *(undefined4 *)(laneRecord + 0x20) = laneValue;
      laneBit = loopCounter & 0x3f;
      loopCounter = loopCounter + 1;
      laneRecord = laneRecord + 0x18;
      *(byte *)(constRecord + 0x15c) = (byte)(1 << laneBit) | *(byte *)(constRecord + 0x15c);
      valueCount = valueCount + -1;
    } while (valueCount != 0);
  }
  return;
}

/* Program__loadDefaultConstants @ 0xfb230 (420 bytes) */
int Program__loadDefaultConstants(program, ilReader)
  int program;
  undefined4 ilReader;
{
  int floatConstCount;
  int intConstCount;
  int boolConstCount;
  uint programKindSet;
  int nextConstIndex;
  int constIndex;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float defaultFloatX;
  float defaultFloatY;
  float defaultFloatZ;
  float defaultFloatW;
  
  programKindSet = *(uint *)(program + 0x30) & 1 | *(uint *)(program + 0x30) >> 0xe & 1;
  boolConstCount = CompileInput__getBoolConstCount(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < boolConstCount) {
    constIndex = 0;
    do {
      CompileInput__readBoolConst(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,1,&local_48);
      ILReader__appendBoolConst(ilReader,constIndex,(uint)(local_48 != 0));
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,0,constIndex,1,&local_48);
      constIndex = nextConstIndex;
    } while (boolConstCount != nextConstIndex);
  }
  intConstCount = CompileInput__getIntConstCount(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < intConstCount) {
    constIndex = 0;
    do {
      CompileInput__readIntConst(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,4,&local_48);
      ILReader__appendIntConst(ilReader,constIndex,local_48,local_44,local_40,local_3c);
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,2,constIndex,4,&local_48);
      constIndex = nextConstIndex;
    } while (intConstCount != nextConstIndex);
  }
  floatConstCount = CompileInput__getFloatConstCount(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < floatConstCount) {
    constIndex = 0;
    do {
      CompileInput__readFloatConst(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,4,&defaultFloatX);
      ((void (*)())ILReader__appendFloatConst)(ilReader,constIndex,(double)defaultFloatX,(double)defaultFloatY,(double)defaultFloatZ,(double)defaultFloatW
                  );
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,1,constIndex,4,&defaultFloatX);
      constIndex = nextConstIndex;
    } while (floatConstCount != nextConstIndex);
  }
  return;
}

/* FUN_000fb3d4 @ 0xfb3d4 (2560 bytes) */
int FUN_000fb3d4(program, list, tokenWords, descriptor, param_5, argR8, movByRegisterPtr)
  int program;
  undefined4 list;
  dword *tokenWords;
  dword *descriptor;
  dword *param_5;
  dword *argR8;
  int movByRegisterPtr;
{
  int loopCounter;
  undefined4 operandSelectWord2;
  undefined4 constantSelectWord2;
  undefined4 instWord0xc8;
  undefined4 registerFile2;
  uint newTempIndex2;
  uint movTableCount;
  uint swizzleWord;
  uint stackTopIndex;
  undefined4 operandSelectWord3;
  undefined4 registerFile3;
  undefined4 registerMap;
  int *hwDescription;
  dword tokenWord;
  int virtualRegisterB;
  int newTempIndex;
  int createdVReg;
  undefined4 constantSelectWord;
  undefined4 packedLaneSource0;
  undefined4 vectorData;
  undefined4 arenaB;
  undefined4 literalSelectWord;
  undefined4 hwInputRegister;
  undefined4 operandSelectWord;
  undefined4 instWord0xc4;
  undefined4 registerFile;
  undefined4 opcodeNumber;
  undefined4 virtualRegister;
  undefined4 modifierSelectWord;
  undefined4 arenaA;
  undefined4 psnPackedLaneSourceResult;
  undefined4 psnPackedLaneSourceResult2;
  void *newInst;
  int *newInst3;
  dword *newInst2;
  dword *newInst4;
  int operandRecord3;
  int operandRecord2;
  undefined4 arenaAt374;
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  dword dVar4;
  undefined *puVar5;
  int iVar6;
  int *stackTopEntry;
  undefined4 r4Sink;
  undefined4 *allocation;
  void *inst;
  int operandRecord;
  undefined4 uVar12;
  undefined4 psnPackedLaneSourceResult3;
  undefined4 registerFile4;
  void *pvVar15;
  void *inst2;
  undefined4 callResidualR4_0;
  undefined4 callResidualR4_0B;
  undefined4 callResidualR4_1;
  undefined4 callResidualR4_2;
  undefined4 callResidualR4_3;
  undefined4 callResidualR4_4;
  undefined4 callResidualR4_5;
  undefined4 callResidualR4_6;
  undefined4 callResidualR4_7;
  undefined4 callResidualR4_8;
  undefined4 callResidualR4_9;
  undefined4 callResidualR4_10;
  undefined4 callResidualR4_11;
  undefined4 callResidualR4_12;
  undefined4 callResidualR4_13;
  undefined4 callResidualR4_14;
  undefined4 callResidualR4_15;
  undefined4 callResidualR4_16;
  undefined4 callResidualR4_17;
  dword *pdVar17;
  dword *pdVar18;
  uint uVar19;
  int iVar20;
  undefined1 *puVar21;
  uint descriptorWord;
  uint hasExtensionWord;
  uint registerType;
  dword *pdVar25;
  dword *pdVar26;
  dword *pdVar27;
  dword *pdVar28;
  dword *pdVar29;
  dword *pdVar30;
  dword *pdVar31;
  dword *pdVar32;
  undefined4 *newInstObj;
  uint registerType2;
  undefined4 uVar35;
  code *hwVirtualSlot88;
  uint *movTableVector;
  int newTempIndexB;
  double staleFprArg1;
  double staleFprArg2;
  double staleFprArg3;
  double staleFprArg4;
  undefined8 uVar39;
  undefined4 local_98;
  dword local_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  
  descriptorWord = *descriptor;
  hasExtensionWord = descriptorWord >> 0x16 & 1;
  iVar20 = *(int *)(program + 8);
  if ((((descriptorWord & 0x3f0000) == 0x100000) && (iVar20 != 0)) &&
     ((*(uint *)(*(int *)(iVar20 + 0x30c) + 8) & 0x80) != 0)) {
    pdVar25 = (dword *)((int)((unsigned char *)0xc) + 3);
  }
  else {
    pdVar25 = (dword *)(int)(short)*descriptor;
  }
  registerType = descriptorWord >> 0x10 & 0x3f;
  r4Sink = list;
  pdVar17 = tokenWords;
  pdVar18 = descriptor;
  pdVar32 = argR8;
  pdVar31 = pdVar25;
  if ((descriptorWord & 0x1800000) == 0x800000) {
    iVar6 = 8;
    if (hasExtensionWord == 0) {
      iVar6 = 4;
    }
    descriptorWord = *(uint *)(iVar6 + (int)descriptor);
    uVar1 = *(ushort *)((int)descriptor + iVar6 + 2);
    if ((descriptorWord & 0x10000) == 0) {
      pdVar31 = (dword *)(*(int *)(iVar20 + 0x3b4) + 1);
      *(dword **)(iVar20 + 0x3b4) = pdVar31;
      virtualRegisterB = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x26,pdVar31,0);
      *(dword **)(virtualRegisterB + 0x30) = pdVar25;
      arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      newInstObj = allocation + 1;
      IRProjection__ctor_109e28(newInstObj,0x84,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(newInstObj,0,virtualRegisterB);
      pdVar18 = (dword *)0x0;
      registerType = 0x22;
      pdVar25 = (dword *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x25,(uint)uVar1,0);
      pdVar17 = pdVar25;
      IRInst__setOperandRef(newInstObj,1,pdVar25);
      modifierSelectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (descriptorWord >> 0x11 & 7) * 4);
      operandRecord2 = IRInst__getOperandRecord(newInstObj,1);
      *(undefined4 *)(operandRecord2 + 0x10) = modifierSelectWord;
      allocation[0x4c] = pdVar25[0xc];
      DList__pushBack(list,newInstObj);
      r4Sink = callResidualR4_1;
    }
    else {
      stackTopEntry = (int *)0x0;
      stackTopIndex = param_5[1] - 1;
      if (stackTopIndex < param_5[1]) {
        stackTopEntry = (int *)(stackTopIndex * 4 + param_5[2]);
      }
      iVar20 = *stackTopEntry;
      *(undefined4 *)(iVar20 + 0x140) = 1;
      virtualRegister = Block__getLoopFooterRegister(iVar20);
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x27,virtualRegister,0);
      if (registerType == 1) {
        pdVar18 = (dword *)0x0;
        pdVar31 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3b8) + 1);
        *(dword **)(*(int *)(program + 8) + 0x3b8) = pdVar31;
        createdVReg = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x28,pdVar31,0);
        *(dword **)(createdVReg + 0x30) = pdVar25;
        arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        pdVar17 = allocation + 1;
        IRInst__ctor_10502c(pdVar17,0x82,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pdVar17,0,createdVReg);
        IRInst__setOperandRef(pdVar17,1,virtualRegister);
        registerType = 0x23;
        Block__appendInst(iVar20,pdVar17);
        VReg__appendUser(createdVReg,pdVar17);
        VReg__addUse(virtualRegister,1,pdVar17);
        r4Sink = callResidualR4_0;
      }
      else {
        if ((*(uint *)(program + 0x30) & 1) == 0) {
          if ((*(uint *)(program + 0x30) & 0x2000) != 0) {
            if (*(int *)(program + 0x3e4) == 0) {
              *(undefined4 *)(program + 0x3e4) = 1;
              registerFile2 = Program__registerFileOfIlType(program,registerType);
              *(undefined4 *)(program + 0x3f4) = registerFile2;
            }
            else {
              Program__registerFileOfIlType(program,registerType);
            }
          }
        }
        else {
          *(undefined4 *)(program + 0x3d4) = 1;
        }
        pdVar31 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3bc) + 1);
        *(dword **)(*(int *)(program + 8) + 0x3bc) = pdVar31;
        registerMap = *(undefined4 *)(program + 0x3ac);
        registerFile2 = Program__registerFileOfIlType(program,0x24);
        pdVar18 = (dword *)0x0;
        createdVReg = VRegPool__findOrCreate(registerMap,registerFile2,pdVar31,0);
        *(dword **)(createdVReg + 0x30) = pdVar25;
        arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        pdVar17 = allocation + 1;
        IRInst__ctor_10502c(pdVar17,0x82,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(pdVar17,0,createdVReg);
        IRInst__setOperandRef(pdVar17,1,virtualRegister);
        registerType = 0x24;
        Block__appendInst(iVar20,pdVar17);
        VReg__appendUser(createdVReg,pdVar17);
        VReg__addUse(virtualRegister,1,pdVar17);
        r4Sink = callResidualR4_0B;
      }
    }
    descriptorWord = *descriptor & 0xfe7fffff;
    *descriptor = descriptorWord;
  }
  if (((descriptorWord & 0x3f0000) == 0x1c0000) &&
     ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 8) == 0)) {
    *descriptor = descriptorWord & 0xffc0ffff | 0x10000;
    pdVar25 = descriptor;
    if ((descriptorWord & 0x400000) != 0) {
      pdVar25 = descriptor + 1;
    }
    bVar3 = false;
    *(short *)((int)descriptor + 2) = (short)pdVar25[1];
    descriptorWord = *descriptor & 0xfbffffff;
    *descriptor = descriptorWord;
  }
  else {
    bVar3 = true;
  }
  if ((registerType == 0x20) && (bVar2 = true, (descriptorWord & 0x1800000) == 0x1000000)) {
LAB_000fb800:
    pdVar25 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(program + 8) + 0x3ac) = pdVar25;
    descriptorWord = *descriptor;
    registerType2 = descriptorWord >> 0x10 & 0x3f;
    if (!bVar2) {
      opcodeNumber = 0xfe;
      if (registerType2 != 0x1c) {
        opcodeNumber = 0xfb;
      }
    }
    else {
      opcodeNumber = 0x10b;
    }
    loopCounter = 1;
    pdVar18 = pdVar31;
    if ((int)descriptorWord < 0) {
      loopCounter = 2;
      pdVar18 = (dword *)((uint)pdVar31 | descriptor[1] << 0x10);
    }
    if ((descriptorWord & 0x400000) != 0) {
      loopCounter = loopCounter + 1;
    }
    if ((descriptorWord & 0x1800000) == 0x1000000) {
      pdVar29 = descriptor + loopCounter;
      if (!bVar2) {
        arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
        *allocation = arenaAt374;
        allocation = allocation + 1;
        IRMemLoad__ctor_107980(allocation,opcodeNumber,*(undefined4 *)(program + 8));
        registerFile = Program__registerFileOfIlType(program,registerType2);
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
        operandRecord3 = IRInst__getOperandRecord(allocation,1);
        *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
        *(dword **)(operandRecord3 + 8) = pdVar18;
      }
      else {
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        allocation = IRInst__create(opcodeNumber,*(undefined4 *)(program + 8));
        allocation[0x27] = 0;
        allocation[0x50] = 0x10203;
        allocation[0x21] = 2;
        registerFile = Program__registerFileOfIlType(program,registerType2);
        operandRecord3 = IRInst__getOperandRecord(allocation,2);
        *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
        *(undefined4 *)(operandRecord3 + 8) = 0xffffffff;
      }
      registerFile = Program__registerFileOfIlType(program,4);
      operandRecord3 = IRInst__getOperandRecord(allocation,0);
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(dword **)(operandRecord3 + 8) = pdVar25;
      if ((*descriptor & 0x4000000) == 0) {
        tokenWord = *pdVar29;
        registerFile = Program__registerFileOfIlType(program,*pdVar29 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)tokenWord));
      }
      else {
        pdVar32 = (dword *)descriptor[loopCounter + 2];
        inst = IRInst__create(0xc6,*(undefined4 *)(program + 8));
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        tokenWord = *pdVar29;
        registerFile = Program__registerFileOfIlType(program,*pdVar29 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)tokenWord));
        ((int (*)())IRInst__setIntConstantOperand4)(inst,program,2,pdVar32,pdVar32,pdVar32,pdVar32);
        DList__pushBack(list,inst);
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
      }
      local_98 = 0x10203;
      ((int (*)())Program__applySourceTokenToOperand)(program,&local_98,pdVar29,pdVar17,allocation);
    }
    else if ((descriptorWord & 0x1800000) == 0) {
      pdVar32 = (dword *)descriptor[loopCounter];
      arenaAt374 = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaAt374,0x168);
      *allocation = arenaAt374;
      allocation = allocation + 1;
      IRMemLoad__ctor_107980(allocation,opcodeNumber,*(undefined4 *)(program + 8));
      registerFile = Program__registerFileOfIlType(program,4);
      operandRecord2 = IRInst__getOperandRecord(allocation,0);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      registerFile = Program__registerFileOfIlType(program,registerType2);
      operandRecord2 = IRInst__getOperandRecord(allocation,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(dword **)(operandRecord2 + 8) = pdVar18;
      ((int (*)())IRInst__setIntConstantOperand4)(allocation,program,2,pdVar32,pdVar32,pdVar32,pdVar32);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    else {
      allocation = (undefined4 *)0x0;
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    operandRecord2 = IRInst__getOperandRecord(allocation,pdVar17);
    local_94[0] = *(dword *)(operandRecord2 + 0x10);
    pdVar18 = local_94;
    param_5 = (dword *)0x0;
    hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
    iVar20 = (**(code **)(*hwDescription + 0x104))(hwDescription,allocation,pdVar17,pdVar18,0);
    if (iVar20 == 0) {
      newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
      inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      instWord0xc8 = allocation[0x32];
      instWord0xc4 = allocation[0x31];
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = instWord0xc8;
      *(undefined4 *)(operandRecord2 + 8) = instWord0xc4;
      registerFile = Program__registerFileOfIlType(program,4);
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = newTempIndex;
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      operandSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = operandSelectWord;
      DList__pushBack(list,inst);
      registerFile = Program__registerFileOfIlType(program,4);
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = newTempIndex;
      operandRecord2 = IRInst__getOperandRecord(allocation,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0;
    }
    DList__pushBack(list,allocation);
    bVar3 = false;
    *descriptor = *descriptor & 0xffc0ffff | 0x40000;
    *(short *)((int)descriptor + 2) = (short)pdVar25;
    r4Sink = callResidualR4_2;
  }
  else {
    if (((undefined4 *)(descriptorWord & 0x3f0000) == (undefined4 *)0x1c0000) ||
       ((undefined4 *)(descriptorWord & 0x3f0000) == 0x001b0000)) {
      bVar2 = false;
      goto LAB_000fb800;
    }
    pdVar25 = (dword *)0x0;
    if ((descriptorWord & 0x2000000) != 0) {
      pdVar25 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(program + 8) + 0x3ac) = pdVar25;
      descriptorWord = *descriptor;
      if ((descriptorWord & 0x400000) == 0) {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 1);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 1);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 2);
      }
      else {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 2);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 2);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 3);
      }
      if ((descriptorWord & 0x1800000) == 0x1000000) {
        pdVar17 = descriptor + (int)pdVar29;
        pdVar18 = descriptor + (int)param_5;
        pdVar29 = (dword *)((int)pdVar32 + 2);
        if ((descriptorWord & 0x4000000) == 0) {
          param_5 = (dword *)((int)pdVar32 + 3);
          pdVar26 = pdVar29;
        }
        else {
          pdVar29 = (dword *)((int)pdVar32 + 3);
          param_5 = pdVar32 + 1;
          pdVar26 = pdVar29;
        }
      }
      else {
        pdVar17 = (dword *)0x0;
        pdVar18 = (dword *)0x0;
        pdVar26 = pdVar32;
      }
      if ((descriptor[(int)pdVar29] & 0x1800000) == 0x1000000) {
        pdVar30 = descriptor + (int)param_5;
        pdVar28 = (dword *)0x0;
        pdVar27 = descriptor + (int)((int)pdVar26 + 2);
        if ((descriptor[(int)pdVar29] & 0x4000000) != 0) {
          pdVar28 = descriptor + (int)((int)pdVar26 + 3);
        }
      }
      else {
        pdVar30 = (dword *)0x0;
        pdVar27 = (dword *)0x0;
        pdVar28 = (dword *)0x0;
      }
      if (pdVar17 == (dword *)0x0) {
        if (pdVar30 != (dword *)0x0) {
          if ((pdVar18 != (dword *)0x0) || (pdVar27 == (dword *)0x0)) goto LAB_000fc43c;
          newInst4 = IRInst__create(0xe6,*(undefined4 *)(program + 8));
          tokenWord = *descriptor;
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          hwInputRegister = (**(code **)(*hwDescription + 0x9c))(hwDescription,(short)tokenWord);
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          (**(code **)(*hwDescription + 0xa0))(&local_84,hwDescription,(short)tokenWord);
          registerFile2 = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(newInst4,0);
          pdVar32 = ((unsigned char *)0x4);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          ((int (*)())IRInst__setIntConstantOperand4)(newInst4,program,1,4,4,4,4);
          tokenWord = *pdVar30;
          registerFile2 = Program__registerFileOfIlType(program,*pdVar30 >> 0x10 & 0x3f);
          operandRecord2 = IRInst__getOperandRecord(newInst4,2);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
          *(uint *)(operandRecord2 + 8) = (uint)GH_F2U((float)((ushort)tokenWord));
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          local_98 = 0x10203;
          param_5 = newInst4;
          ((int (*)())Program__applySourceTokenToOperand)(program,&local_98,pdVar30,2,newInst4);
          DList__pushBack(list,newInst4);
          if ((pdVar28 != (dword *)0x0) && (*pdVar28 != 0)) {
            inst = IRInst__create(0xc6,*(undefined4 *)(program + 8));
            registerFile2 = Program__registerFileOfIlType(program,4);
            operandRecord2 = IRInst__getOperandRecord(inst,0);
            *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
            *(dword **)(operandRecord2 + 8) = pdVar25;
            registerFile2 = Program__registerFileOfIlType(program,4);
            operandRecord2 = IRInst__getOperandRecord(inst,1);
            *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
            pdVar30 = (dword *)((int)((unsigned char *)0x0) + 2);
            *(dword **)(operandRecord2 + 8) = pdVar25;
            pdVar18 = (dword *)(*pdVar28 << 2);
            param_5 = pdVar18;
            pdVar32 = pdVar18;
            ((int (*)())IRInst__setIntConstantOperand4)(inst,program,2,pdVar18,pdVar18,pdVar18,pdVar18);
            operandRecord2 = IRInst__getOperandRecord(inst,2);
            *(undefined4 *)(operandRecord2 + 0x10) = local_84;
            DList__pushBack(list,inst);
          }
          inst = IRInst__create(0xc6,*(undefined4 *)(program + 8));
          registerFile2 = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          registerFile2 = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile2;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
          *(undefined4 *)(operandRecord2 + 8) = hwInputRegister;
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0x10) = local_84;
          DList__pushBack(list,inst);
          inst = IRInst__create(0x68,*(undefined4 *)(program + 8));
          registerFile = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(undefined4 *)((int)inst + 0x130) = 0;
          pdVar17 = pdVar30;
LAB_000fc3f4:
          *(undefined4 *)((int)inst + 0x140) = 0x10203;
          registerFile = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          pvVar15 = (void *)0x0;
          *(undefined4 *)(operandRecord2 + 0x10) = 0;
          goto LAB_000fc74c;
        }
        descriptorWord = (uint)*(ushort *)((int)descriptor + (int)pdVar29 * 4 + 2);
        pdVar29 = (dword *)(uint)(ushort)*descriptor;
        if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
          pvVar15 = (void *)0x0;
          inst = IRInst__create(0x68,*(undefined4 *)(program + 8));
          registerFile = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(undefined4 *)((int)inst + 0x140) = 0x10203;
          *(uint *)((int)inst + 0x130) = descriptorWord;
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          hwInputRegister = (**(code **)(*hwDescription + 0x9c))(hwDescription,pdVar29);
          pdVar18 = *(dword **)(program + 8);
          (**(code **)(*(*(int * *)(pdVar18 + (0xc3))) + 0xa0))(&local_88);
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 8) = hwInputRegister;
          *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
          operandRecord2 = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = local_88;
          pdVar17 = pdVar29;
          if (descriptorWord == *argR8) {
            pdVar17 = *(dword **)(program + 8);
            uVar35 = (**(code **)(*(*(int * *)(pdVar17 + (0xc3))) + 0xa8))((*(int * *)(pdVar17 + (0xc3))),&local_98);
            pvVar15 = IRInst__create(0x31,*(undefined4 *)(program + 8));
            registerFile = Program__registerFileOfIlType(program,4);
            operandRecord2 = IRInst__getOperandRecord(pvVar15,0);
            *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
            *(dword **)(operandRecord2 + 8) = pdVar25;
            *(dword *)((int)pvVar15 + 0x9c) = argR8[1];
            operandRecord2 = IRInst__getOperandRecord(pvVar15,1);
            literalSelectWord = local_98;
            *(undefined4 *)(operandRecord2 + 0xc) = 0x1f;
            *(undefined4 *)(operandRecord2 + 8) = uVar35;
            operandRecord2 = IRInst__getOperandRecord(pvVar15,1);
            *(undefined4 *)(operandRecord2 + 0x10) = literalSelectWord;
          }
          goto LAB_000fc74c;
        }
        iVar20 = (int)pdVar29 * 4;
        movTableVector = *(uint **)(iVar20 + movByRegisterPtr);
        if (movTableVector == (uint *)0x0) {
          arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
          allocation = (undefined4 *)Arena__alloc(arenaB,0x14);
          movTableVector = allocation + 1;
          *allocation = arenaB;
          allocation[1] = 2;
          allocation[2] = 0;
          allocation[4] = arenaB;
          vectorData = Arena__alloc(arenaB,8);
          allocation[3] = vectorData;
          *(uint **)(iVar20 + movByRegisterPtr) = movTableVector;
          r4Sink = callResidualR4_3;
        }
        if (descriptorWord < *movTableVector) {
          movTableCount = movTableVector[1];
          if (movTableCount <= descriptorWord) {
            pdVar17 = (dword *)((descriptorWord - movTableCount) * 4 + 4);
            _memset(movTableCount * 4 + movTableVector[2],0,pdVar17);
            movTableVector[1] = descriptorWord + 1;
            r4Sink = callResidualR4_4;
          }
          uVar39 = CONCAT44(descriptorWord * 4 + movTableVector[2],r4Sink);
        }
        else {
          uVar39 = Vector__elementRefGrow(movTableVector,descriptorWord);
        }
        r4Sink = (undefined4)uVar39;
        if (*(int *)((ulonglong)uVar39 >> 0x20) == 0) {
          iVar6 = IRLoadVertex__new_109810(0xa4,*(undefined4 *)(program + 8));
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffff7fff;
          newTempIndexB = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndexB;
          operandRecord = IRInst__getOperandRecord(iVar6,0);
          *(int *)(operandRecord + 8) = newTempIndexB;
          *(undefined4 *)(operandRecord + 0xc) = 0;
          *(dword **)(iVar6 + 0x130) = pdVar29;
          *(uint *)(iVar6 + 300) = descriptorWord;
          pdVar17 = *(dword **)(program + 0x3a0);
          ((int (*)())Program__appendInst)(program,iVar6,pdVar17);
          movTableVector = *(uint **)(iVar20 + movByRegisterPtr);
          if (descriptorWord < *movTableVector) {
            movTableCount = movTableVector[1];
            r4Sink = callResidualR4_5;
            if (movTableCount <= descriptorWord) {
              pdVar17 = (dword *)((descriptorWord - movTableCount) * 4 + 4);
              _memset(movTableCount * 4 + movTableVector[2],0,pdVar17);
              movTableVector[1] = descriptorWord + 1;
              r4Sink = callResidualR4_6;
            }
            uVar39 = CONCAT44(descriptorWord * 4 + movTableVector[2],r4Sink);
          }
          else {
            uVar39 = Vector__elementRefGrow(movTableVector,descriptorWord);
          }
          r4Sink = (undefined4)uVar39;
          *(int *)((ulonglong)uVar39 >> 0x20) = iVar6;
        }
        movTableVector = *(uint **)(iVar20 + movByRegisterPtr);
        if (descriptorWord < *movTableVector) {
          movTableCount = movTableVector[1];
          if (movTableCount <= descriptorWord) {
            pdVar17 = (dword *)((descriptorWord - movTableCount) * 4 + 4);
            _memset(movTableCount * 4 + movTableVector[2],0,pdVar17);
            movTableVector[1] = descriptorWord + 1;
            r4Sink = callResidualR4_7;
          }
          uVar39 = CONCAT44(descriptorWord * 4 + movTableVector[2],r4Sink);
        }
        else {
          uVar39 = Vector__elementRefGrow(movTableVector,descriptorWord);
        }
        r4Sink = (undefined4)uVar39;
        pdVar25 = *(dword **)(*(int *)((ulonglong)uVar39 >> 0x20) + 0x94);
      }
      else {
        if (((pdVar18 != (dword *)0x0) && (pdVar30 == (dword *)0x0)) && (pdVar27 == (dword *)0x0)) {
          pdVar32 = ((unsigned char *)0x4);
          param_5 = pdVar25;
          ((int (*)())FUN_000f94dc)(program,list,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(program + 0x400));
          uVar1 = *(ushort *)((int)descriptor + (int)pdVar29 * 4 + 2);
          inst = IRInst__create(0x68,*(undefined4 *)(program + 8));
          registerFile = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(dword **)(operandRecord2 + 8) = pdVar25;
          *(uint *)((int)inst + 0x130) = (uint)uVar1;
          goto LAB_000fc3f4;
        }
LAB_000fc43c:
        ((int (*)())FUN_000f94dc)(program,list,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(program + 0x400));
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        swizzleWord = (uint)(ushort)*pdVar30;
        if (pdVar28 != (dword *)0x0) {
          inst = IRInst__create(0xc6,*(undefined4 *)(program + 8));
          registerFile = Program__registerFileOfIlType(program,4);
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(undefined4 *)((int)inst + 0x9c) = 0x10101;
          *(uint *)(operandRecord2 + 8) = newTempIndex2;
          uVar19 = *pdVar28;
          ((int (*)())IRInst__setIntConstantOperand4)(inst,program,1,uVar19,uVar19,uVar19,uVar19);
          registerFile = Program__registerFileOfIlType(program,*pdVar30 >> 0x10 & 0x3f);
          operandRecord2 = IRInst__getOperandRecord(inst,2);
          *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
          *(uint *)(operandRecord2 + 8) = swizzleWord;
          local_94[0] = 0x10203;
          ((int (*)())Program__applySourceTokenToOperand)(program,local_94,pdVar30,2,inst);
          DList__pushBack(list,inst);
          *pdVar30 = *pdVar30 & 0xffc0ffff | 0x40000;
          swizzleWord = newTempIndex2;
        }
        newInst2 = IRInst__create(0xe6,*(undefined4 *)(program + 8));
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(newInst2,0);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        newInst2[0x27] = 0x10101;
        pdVar18 = ((unsigned char *)0x4);
        param_5 = ((unsigned char *)0x4);
        pdVar32 = ((unsigned char *)0x4);
        *(uint *)(operandRecord2 + 8) = newTempIndex2;
        ((int (*)())IRInst__setIntConstantOperand4)(newInst2,program,1,4,4,4,4);
        registerFile = Program__registerFileOfIlType(program,*pdVar30 >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(newInst2,2);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(uint *)(operandRecord2 + 8) = swizzleWord;
        local_98 = 0x10203;
        if (pdVar28 == (dword *)0x0) {
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          param_5 = newInst2;
          ((int (*)())Program__applySourceTokenToOperand)(program,&local_98,pdVar30,2,newInst2);
          pdVar17 = pdVar30;
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(newInst2,2);
          *(undefined4 *)(operandRecord2 + 0x10) = 0;
        }
        DList__pushBack(list,newInst2);
        inst = IRInst__create(0xc6,*(undefined4 *)(program + 8));
        *(undefined4 *)((int)inst + 0x9c) = 0x10101;
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,2);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(uint *)(operandRecord2 + 8) = newTempIndex2;
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        pvVar15 = (void *)0x0;
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
        operandRecord2 = IRInst__getOperandRecord(inst,2);
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
        DList__pushBack(list,inst);
        inst = IRInst__create(0x68,*(undefined4 *)(program + 8));
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        *(undefined4 *)((int)inst + 0x130) = 0;
        *(undefined4 *)((int)inst + 0x140) = 0x10203;
        registerFile = Program__registerFileOfIlType(program,4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        *(dword **)(operandRecord2 + 8) = pdVar25;
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
LAB_000fc74c:
        DList__pushBack(list,inst);
        r4Sink = callResidualR4_8;
        if (pvVar15 != (void *)0x0) {
          DList__pushBack(list,pvVar15);
          r4Sink = callResidualR4_9;
        }
      }
      bVar3 = false;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
      *(short *)((int)descriptor + 2) = (short)pdVar25;
    }
  }
  if (hasExtensionWord == 0) goto code_r0x000fd490;
  descriptorWord = *descriptor;
  if (((descriptorWord & 0x400000) == 0) || ((descriptor[1] & 0x4444) == 0)) {
    bVar2 = false;
  }
  else {
    packedLaneSource0 = psnPackedLaneSource(descriptor,0);
    psnPackedLaneSourceResult = psnPackedLaneSource(descriptor,1);
    psnPackedLaneSourceResult2 = psnPackedLaneSource(descriptor,2);
    psnPackedLaneSourceResult3 = psnPackedLaneSource(descriptor,3);
    pdVar18 = local_94;
    pdVar25 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(program + 8) + 0x3ac) = pdVar25;
    inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    registerFile4 = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile4;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    local_94[0] = 0x10203;
    staleFprArg1 = (double)((double (*)())IRInst__literalForLane)(packedLaneSource0,0,&local_98,pdVar18);
    staleFprArg2 = (double)((double (*)())IRInst__literalForLane)(psnPackedLaneSourceResult,1,&local_98,pdVar18);
    staleFprArg3 = (double)((double (*)())IRInst__literalForLane)(psnPackedLaneSourceResult2,2,&local_98,pdVar18);
    staleFprArg4 = (double)((double (*)())IRInst__literalForLane)(psnPackedLaneSourceResult3,3,&local_98,pdVar18);
    dVar4 = local_94[0];
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(dword *)(operandRecord2 + 0x10) = dVar4;
    DList__pushBack(list,inst);
    inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,1,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4);
    *(undefined4 *)((int)inst + 0x9c) = local_98;
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    r4Sink = callResidualR4_10;
    pdVar31 = pdVar25;
    if ((descriptorWord & 0x400000) == 0) {
      registerType = 4;
      bVar2 = true;
    }
    else {
      registerType = 4;
      bVar2 = true;
      descriptor[1] = descriptor[1] & 0xffff8888 | 0x3210;
    }
  }
  if ((descriptorWord & 0x400000) == 0) goto code_r0x000fd490;
  puVar21 = (undefined1 *)descriptor[1];
  pdVar29 = descriptor + 1;
  if (((uint)puVar21 & 0xffff8888) == 0) goto code_r0x000fd490;
  pdVar26 = pdVar31;
  if (((ushort)*tokenWords - 0x8e < 0x10) && (((uint)puVar21 & 0x8888) != 0)) {
    descriptor[1] = (uint)puVar21 & 0xffff7777;
    pdVar26 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(program + 8);
      pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar26;
    }
    bVar2 = true;
    inst = IRInst__create(0xcb,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,0.0,0.0,0.0,0.0);
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(dword **)(operandRecord2 + 8) = pdVar31;
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    r4Sink = callResidualR4_11;
    registerType = 4;
    pdVar25 = pdVar26;
  }
  pdVar31 = pdVar26;
  if (((descriptorWord & 0x400000) != 0) && ((*pdVar29 & 0x10000) != 0)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(program + 8);
      pdVar31 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar31;
    }
    inst = IRInst__create(0x12,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    IROperand__setModifierBits((int)inst + 0xa4,1,1);
    if (!bVar2) {
      ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
    }
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    registerType = 4;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,1.0,1.0,1.0,1.0);
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    r4Sink = callResidualR4_12;
    pdVar25 = pdVar31;
  }
  if ((((descriptorWord & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) || ((*pdVar29 & 0x40000) == 0)) {
    if (((descriptorWord & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) {
      if (((descriptorWord & 0x400000) == 0) || ((*pdVar29 & 0x40000) == 0)) goto code_r0x000fcda8;
      if (!bVar2) {
        puVar21 = *(undefined1 **)(program + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      inst = IRInst__create(0x13,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      registerFile = Program__registerFileOfIlType(program,registerType);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(dword **)(operandRecord2 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
      }
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,2.0,2.0,2.0,2.0);
      pdVar31 = pdVar25;
    }
    else {
      if (!bVar2) {
        puVar21 = *(undefined1 **)(program + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      inst = IRInst__create(0x12,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar25;
      registerFile = Program__registerFileOfIlType(program,registerType);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(dword **)(operandRecord2 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
      }
      ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,0.5,0.5,0.5,0.5);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
      IROperand__setModifierBits((int)inst + 0xbc,1,1);
      pdVar31 = pdVar25;
    }
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    registerType = 4;
    bVar2 = true;
    r4Sink = callResidualR4_14;
    pdVar25 = pdVar31;
  }
  else {
    if (!bVar2) {
      puVar21 = *(undefined1 **)(program + 8);
      pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar25;
    }
    inst = IRInst__create(0x14,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar25;
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
    }
    registerType = 4;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,2.0,2.0,2.0,2.0);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    IROperand__setModifierBits((int)inst + 0xd4,1,1);
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    r4Sink = callResidualR4_13;
    pdVar31 = pdVar25;
  }
code_r0x000fcda8:
  pdVar26 = pdVar31;
  if (((descriptorWord & 0x400000) != 0) && ((*pdVar29 & 0x80000) != 0)) {
    puVar21 = *(undefined1 **)(program + 8);
    pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
    *(dword **)(puVar21 + 0x3ac) = pdVar26;
    inst = IRInst__create(0x26,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,1.0,1.0,1.0,1.0);
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,3);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      operandSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord2 + 0x10) = operandSelectWord;
    }
    DList__pushBack(list,inst);
    inst = IRInst__create(0x25,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    registerType = 4;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    operandRecord2 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar26;
    bVar2 = true;
    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    IROperand__setModifierBits((int)inst + 0xd4,1,1);
    DList__pushBack(list,inst);
    descriptorWord = *descriptor;
    r4Sink = callResidualR4_15;
    pdVar25 = pdVar26;
  }
  pdVar27 = pdVar26;
  if (((descriptorWord & 0x400000) != 0) && (hasExtensionWord = *pdVar29 >> 0x15 & 7, hasExtensionWord != 0)) {
    puVar21 = (undefined1 *)**(undefined4 **)(*(int *)(program + 8) + 0x30c);
    uVar39 = (**(code **)(puVar21 + 0xb4))();
    r4Sink = (undefined4)uVar39;
    if (((int)((ulonglong)uVar39 >> 0x20) == 0) ||
       ((pdVar17 = (dword *)(uint)(ushort)*tokenWords,
        (uint *)((int)&(*(GhidraMachOSection *)0x00000098).size + 2) < pdVar17 ||
        (pdVar17 != (dword *)((*(GhidraMachOSection *)0x00000054).sectname + 9))))) {
      if (hasExtensionWord == 4) {
code_r0x000fd284:
        descriptorWord = *descriptor;
      }
      else {
        if (hasExtensionWord == 1) {
          constantSelectWord2 = 0x10101;
          iVar20 = 1;
          constantSelectWord = 0x1000000;
        }
        else if (hasExtensionWord == 2) {
          constantSelectWord2 = 0x101;
          iVar20 = 2;
          constantSelectWord = 0x1010000;
        }
        else {
          if (hasExtensionWord != 3) goto code_r0x000fd284;
          constantSelectWord2 = 1;
          iVar20 = 3;
          constantSelectWord = 0x1010100;
        }
        inst = IRInst__create(0x40,*(undefined4 *)(program + 8));
        pdVar27 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3ac) + -1);
        *(dword **)(*(int *)(program + 8) + 0x3ac) = pdVar27;
        operandRecord3 = IRInst__getOperandRecord(inst,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(undefined4 *)((int)inst + 0x9c) = 0x1010100;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        registerFile3 = Program__registerFileOfIlType(program,registerType);
        operandRecord3 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord3 + 0xc) = registerFile3;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        newInst = IRInst__create(0x13,*(undefined4 *)(program + 8));
        operandRecord3 = IRInst__getOperandRecord(newInst,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        registerFile3 = Program__registerFileOfIlType(program,registerType);
        operandRecord3 = IRInst__getOperandRecord(newInst,1);
        *(undefined4 *)(operandRecord3 + 0xc) = registerFile3;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        inst2 = IRInst__create(0x31,*(undefined4 *)(program + 8));
        operandRecord3 = IRInst__getOperandRecord(inst2,0);
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        registerFile3 = Program__registerFileOfIlType(program,registerType);
        operandRecord3 = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(operandRecord3 + 0xc) = registerFile3;
        *(dword **)(operandRecord3 + 8) = pdVar26;
        if (!bVar2) {
          ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,newInst);
          operandRecord3 = IRInst__getOperandRecord(newInst,1);
          operandSelectWord3 = *(undefined4 *)(operandRecord3 + 0x10);
          operandRecord3 = IRInst__getOperandRecord(inst2,1);
          *(undefined4 *)(operandRecord3 + 0x10) = operandSelectWord3;
        }
        operandRecord3 = IRInst__getOperandRecord(newInst,2);
        puVar5 = PTR_DAT_001e8b8c;
        *(undefined4 *)(operandRecord3 + 0xc) = 0;
        uVar12 = *(undefined4 *)(puVar5 + 0xc);
        registerType = 4;
        *(dword **)(operandRecord3 + 8) = pdVar27;
        operandRecord3 = IRInst__getOperandRecord(newInst,2);
        *(undefined4 *)(operandRecord3 + 0x10) = uVar12;
        operandRecord3 = IRInst__getOperandRecord(newInst,1);
        puVar21 = &STACKARG(0xffffff30) + iVar20;
        local_80 = *(undefined4 *)(operandRecord3 + 0x10);
        bVar2 = true;
        uVar12 = *(undefined4 *)(puVar5 + (uint)*(byte *)((int)&local_80 + iVar20) * 4);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = uVar12;
        *(undefined4 *)((int)newInst + 0x9c) = constantSelectWord2;
        *(undefined4 *)((int)inst2 + 0x9c) = constantSelectWord;
        DList__pushBack(list,inst);
        DList__pushBack(list,newInst);
        DList__pushBack(list,inst2);
        descriptorWord = *descriptor;
        r4Sink = callResidualR4_17;
        pdVar25 = pdVar27;
      }
    }
    else if (hasExtensionWord == 3) {
      *(undefined4 *)(program + 0x47c) = 1;
      descriptorWord = *descriptor;
    }
    else {
      if (hasExtensionWord != 2) goto code_r0x000fd284;
      puVar21 = *(undefined1 **)(program + 8);
      *(undefined4 *)(program + 0x47c) = 1;
      bVar2 = true;
      pdVar27 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar27;
      newInst3 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(newInst3,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0;
      *(dword **)(operandRecord2 + 8) = pdVar27;
      registerFile = Program__registerFileOfIlType(program,registerType);
      operandRecord2 = IRInst__getOperandRecord(newInst3,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(dword **)(operandRecord2 + 8) = pdVar26;
      ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,newInst3);
      hwVirtualSlot88 = *(code **)(*newInst3 + 0x88);
      operandRecord2 = IRInst__getOperandRecord(newInst3,1);
      pdVar18 = (dword *)(uint)*(byte *)(operandRecord2 + 0x12);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 3);
      (*hwVirtualSlot88)(newInst3,1);
      DList__pushBack(list,newInst3);
      descriptorWord = *descriptor;
      r4Sink = callResidualR4_16;
      registerType = 4;
      pdVar25 = pdVar27;
    }
  }
  pdVar31 = pdVar27;
  if (((((descriptorWord & 0x400000) != 0) && ((*pdVar29 & 0x8888) != 0)) &&
      (descriptorWord = psnPackedNegateMask(descriptor,r4Sink,pdVar17,pdVar18,param_5,pdVar32,puVar21), descriptorWord != 0))
     && (descriptorWord != 0x8888)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      pdVar31 = (dword *)(*(int *)(*(int *)(program + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(program + 8) + 0x3ac) = pdVar31;
    }
    inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(dword **)(operandRecord2 + 8) = pdVar31;
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar27;
    if (!bVar2) {
      ((int (*)())IRInst__applyDescriptorSwizzle)(descriptor,inst);
    }
    if (((*descriptor & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) {
      IROperand__setModifierBits((int)inst + 0xa4,2,1);
    }
    DList__pushBack(list,inst);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    operandSelectWord2 = *(undefined4 *)(operandRecord2 + 0x10);
    inst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(dword **)(operandRecord2 + 8) = pdVar31;
    registerFile = Program__registerFileOfIlType(program,registerType);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
    *(dword **)(operandRecord2 + 8) = pdVar27;
    if (!bVar2) {
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = operandSelectWord2;
    }
    IROperand__setModifierBits((int)inst + 0xa4,1,1);
    if ((((*descriptor & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) &&
       (IROperand__setModifierBits((int)inst + 0xa4,2,1), (*descriptor & 0x400000) != 0)) {
      *pdVar29 = *pdVar29 & 0xffefffff;
    }
    *(uint *)((int)inst + 0x9c) =
         descriptorWord >> 0xf & 1 ^ 1 |
         (descriptorWord >> 0xb & 1 ^ 1) << 8 |
         (descriptorWord >> 7 & 1 ^ 1) << 0x10 | (descriptorWord >> 3 & 1 ^ 1) << 0x18;
    DList__pushBack(list,inst);
    if ((*descriptor & 0x400000) != 0) {
      *pdVar29 = *pdVar29 & 0xffff7777;
    }
    registerType = 4;
  }
code_r0x000fd490:
  if (bVar3) {
    *(short *)((int)descriptor + 2) = (short)pdVar31;
    *descriptor = registerType << 0x10 | *descriptor & 0xffc0ffff;
  }
  return;
}

/* Template__pushCallFrame @ 0xfd50c (188 bytes) */
int Template__pushCallFrame(program, templateBase, templateCursorPtr, frameBlock, calleeTemplate, vector)
  int program;
  undefined4 templateBase;
  undefined4 *templateCursorPtr;
  undefined4 frameBlock;
  undefined4 calleeTemplate;
  uint *vector;
{
  undefined4 templateCursor;
  undefined4 *allocation;
  int *piVar2;
  uint uVar3;
  undefined4 arenaB;
  
  arenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  allocation = (undefined4 *)Arena__alloc(arenaB,0x10);
  *allocation = arenaB;
  allocation[1] = templateBase;
  templateCursor = *templateCursorPtr;
  allocation[3] = frameBlock;
  allocation[2] = templateCursor;
  uVar3 = vector[1];
  if (uVar3 < *vector) {
    _memset(uVar3 * 4 + vector[2],0,4);
    piVar2 = (int *)(uVar3 * 4 + vector[2]);
    vector[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(vector,uVar3);
  }
  *piVar2 = (int)(allocation + 1);
  *templateCursorPtr = 0xffffffff;
  return calleeTemplate;
}

/* Program__translateILStream @ 0xfd5c8 (408 bytes) */
int Program__translateILStream(program, ilReader)
  int program;
  uint ******ilReader;
{
  bool hwFlag0x40Clear;
  bool hasPendingExtra;
  uint *****instWord0x98C;
  undefined1 *laneMaskPtr;
  int flushNodeC;
  int writtenLaneCount;
  int laneStep;
  int operandRecordY;
  int flagBit2Result;
  int destRegisterNumberB;
  int operandRecordX;
  int templateBase;
  uint declVectorSize;
  uint modifierBit9;
  undefined4 freedStorage;
  undefined4 registerMapB;
  undefined4 resourceOperandWord;
  int *cursorNext;
  uint ***sourceToken0Word;
  uint ***scopeEndBlock;
  undefined4 *ifCondInstAlloc;
  void *createdInstB;
  uint *declVectorSlot;
  uint *declVector;
  int copiedInst;
  int fetchInstWordD;
  int operandByteOffsetC;
  uint tokenIndexField;
  uint movVectorSize;
  uint declKindField;
  uint selectByteB;
  uint modifierBit10;
  int operandSelectValue;
  int scopeObjectB;
  int nextListNodeB;
  int compilerRef;
  uint ******sourceNumberB;
  uint ******rangeStartValueC;
  uint ******wordsLeft;
  uint ******newBlockC;
  uint ****stagedSelectCopy;
  uint ****sourceToken1Ptr;
  uint ****sourceToken0Ptr;
  uint ****scopeBlock;
  int *opcodeTableEntry;
  int *chainLastBlock;
  int *opcodeScanCursor;
  int *instOpcode0x94;
  int *pendingInstPtr;
  undefined4 *loopStackAlloc;
  undefined4 *bitmapClearCursor;
  undefined4 *bitmapAllocation;
  uint ******operandSelectRaw;
  uint ******sourceOperandNumber;
  uint ******operandIndexC;
  uint *scopeVectorB;
  uint *pendingVector;
  uint *selectTableEntry;
  uint *tokenCopyCursor;
  uint *****instWord0x98B;
  uint *****instWord0x94B;
  uint *****maxTextureStage;
  uint *****instListCursor;
  uint *****ifStackNewSlot;
  uint *****savedStagedSelect;
  uint *****ifStackTopSlot;
  uint *****immConstData;
  uint *****newBlockB;
  uint *****savedExtraWord;
  uint *****instWord0x94;
  uint *****instWord0x98;
  uint *****remappedKindValue;
  uint *****textureStageIndex;
  uint *****loopStackSizeB;
  uint *****blockInstList;
  uint *****ifBlock;
  uint *****fetchStateRef;
  uint *****fetchStateBlock;
  uint *****tokenValue;
  uint ******operandCountPlusOne;
  uint ******operandNumber;
  uint ******declRangeStart;
  uint ******extensionWordPtr;
  uint ******interpIndexValue;
  int flushNodeB;
  int operandIndexB;
  int flushNode;
  int loopRegisterEnd;
  int selectedLaneB;
  int firstWrittenLaneB;
  int continueTargetBlockB;
  int fetchInstWordC;
  int fetchInstWordB;
  int operandByteOffset;
  uint ******builtInstB;
  uint ******scopeVector;
  uint ******instOpcode0xb4;
  uint ******declRegister;
  uint ******createdMov;
  uint ******tokenCursor;
  uint ******interpIndexField;
  uint ******laneKindValue;
  uint ******destSelectWordCopy;
  uint ******operandLoopIndex;
  uint ******nextBlock;
  uint ******ifConditionRef;
  uint ******newBlock;
  uint ******continueBlock;
  uint ******createdInst0x12;
  uint ******breakBlock;
  uint ******opcodeTemplateTable;
  int rangeStartValue;
  int registerEnd;
  int firstRegisterIndex;
  int vtableSlot5Result;
  int opcodeFlagBit2;
  int opcodeRecordField;
  int loadedProgramValue;
  int cachedTempIndex;
  int breakTargetBlockB;
  int transformFailed;
  int optionResult;
  int literalAddr;
  int declRecordTable;
  int fetchOpcodeCode;
  int declaredKind;
  int tableOpcode;
  int scopeQueryResult;
  int savedRegisterIndex;
  int scopeObject;
  int enclosingScopeOpcode;
  int builtInst;
  int pendingInstB;
  int opcodeOperandCount;
  int exportVReg;
  int loadInterpRecord;
  int nextListNode;
  uint destTokenWord;
  uint loopRegisterNumber;
  uint scopeDepth;
  uint scopeTopIndex;
  uint loopTopIndex;
  uint loopDepth;
  uint vectorSize;
  uint interpMode;
  uint registerNumber;
  uint tokenModeField;
  uint selectIndex;
  uint modifierBit8;
  uint programInstIndex;
  uint conditionStackStorage;
  int selectedLane;
  int hwQueryResult;
  int firstWrittenLane;
  int usedBitmapWord;
  int firstSourceWordIndex;
  int immConstBuffInst;
  int destRegisterNumber;
  int laneKind;
  int pendingInst;
  int selectLaneByte;
  int ilRegisterRecordOffset;
  int registerRangeStart;
  int interpRecord;
  int programInstVector;
  int atFirstInst;
  int nextInstOk;
  int hwRegisterCount;
  int sourceRegisterIndexB;
  uint ***source0Token;
  uint ***source1Token;
  uint ***destOperandToken;
  undefined4 arenaA;
  undefined4 registerFileB;
  int loopCounterD;
  int optionEnabled;
  int virtualRegister43;
  int loopCounterC;
  int loopCounterB;
  int operandRecordC;
  int newTempIndex21;
  int operandRecordB;
  int loopCounter;
  int newTempIndex20;
  int operandRecordLast;
  undefined4 gradientYTemp;
  undefined4 coordTemp;
  undefined4 fetchResultTemp2;
  uint ******selectWord2;
  uint ******fetchInst2;
  undefined4 fetchIrOpcode;
  bool tokenBit25Clear2;
  uint *****samplerIndex2;
  bool tokenBit25Clear;
  bool sampleFlag4Clear;
  int *fetchInst;
  int registerRecordOffset;
  undefined4 cubeCoordTemp;
  undefined4 fetchCoordTemp;
  bool hasGradients;
  bool hasFirstExtraOperand;
  undefined2 *fetchDescriptor;
  uint samplerIndex;
  uint resourceId;
  uint sampleFlags;
  bool clearsInfoFlag1;
  bool isTranslationKind7;
  bool notLastIteration;
  uint bitmapByteOffset2;
  uint sourceRegisterIndex;
  uint conditionStackTopIndex;
  uint templateToken;
  uint ilRegisterIndex2;
  uint conditionStackCount;
  uint bitmapByteOffset;
  uint ilRegisterType;
  uint *swizzleTable;
  uint *****ifStackTopIndex;
  uint *****ifStackCount;
  uint *****trailingToken;
  uint *****modifierTokenWord;
  uint *****firstTokenWord;
  uint ******destinationToken;
  uint ******tokenWords;
  void *cmp1SInst;
  void *fetchTextureMapGradientsInst;
  void *mulFloatInst;
  void *roundNearestEvenInst;
  void *ldBufferInst;
  void *setGradientsVInst;
  void *mulAddFloatInst;
  void *recipIEEEInst;
  void *cubeInst;
  void *int2FInst;
  void *getResourceInst;
  void *movFloatInst;
  undefined4 *vectorElementSlot3;
  undefined4 *blockAllocation4;
  undefined4 *blockAllocation3;
  undefined4 *blockAllocation2;
  undefined4 *vectorAllocation2;
  undefined4 *instObject;
  undefined4 *instAllocation;
  undefined4 *vectorElementSlot;
  undefined4 *blockAllocation;
  int *setGradientsHInst;
  int *stackElement;
  int *movInst;
  int *mulAddInst;
  int *virtualRegister2;
  int *hwDescription;
  int registerMap2;
  int newTempIndex2;
  int operandRecord2;
  int registerIndex;
  int compiler;
  int newTempIndex;
  int operandRecord;
  int laneSelect;
  int registerFile2;
  int ilOpcode;
  bool laneUsedFlag;
  undefined4 irOpcode;
  undefined4 enclosingLoopHeader;
  undefined4 ifConditionInst;
  undefined4 comparisonKind;
  undefined4 selectWord;
  undefined4 remappedSelect;
  undefined4 continueTargetBlock;
  undefined4 breakTargetBlock;
  undefined4 opcodeRecordTable;
  undefined4 registerMap;
  undefined4 virtualRegister;
  undefined4 registerInfo;
  undefined4 registerFile;
  undefined4 translationKind;
  undefined4 compilerArenaA;
  undefined4 vectorStorage;
  bool setsInterpBit2;
  bool setsInterpBit4;
  byte ilRegisterIndex;
  float literalFloat;
  short registerIndex2;
  ushort saturateBit;
  undefined *remapTable;
  undefined *resourceOperandTable;
  uint bitmapWordCount;
  uint *****rewrittenSelect;
  uint *movVector;
  undefined4 *puVar13;
  undefined4 *vectorAllocation;
  uint *****ifStackStorage;
  void *pvVar16;
  uint movVectorSizeB;
  int *piVar18;
  uint ******interpRegisterNumber;
  int registerEndB;
  int laneLoopIndex;
  int iVar23;
  undefined4 *exportInst;
  int operandByteLimit;
  undefined2 *fetchDescriptor2;
  undefined4 registerFile27;
  undefined2 componentSelect;
  undefined4 *vectorElementSlot2;
  undefined4 *blockObject;
  uint ****chainLastBlockB;
  undefined4 *listAllocation;
  uint ******argR6;
  uint ******argR7;
  uint ******argR8;
  uint ***sourceToken1Word;
  int hwInfoObj;
  uint *listHeader;
  int *vectorSlotC;
  uint ******loopStackData;
  uint ******workInst;
  uint ******savedCurrentBlock;
  uint ******extWordCursor;
  undefined4 virtualRegisterB;
  uint ***firstSourceToken;
  int interpKind;
  uint movSlotIndex;
  uint ****destTokenPtr;
  undefined4 compilerArenaB;
  int hwOpcodeRecords;
  uint ******declRegisterNumber;
  uint ******ppppppuVar49;
  undefined4 virtualRegisterC;
  uint ****elseBlock;
  uint *****secondTokenWord;
  undefined1 *registerEndC;
  double literalValue;
  uint ****scopeLevel;
  uint *****previousBlock;
  uint *****currentBlock;
  int *templateCursor;
  undefined4 stagedSelectWord;
  uint ****lastDeclRegister;
  uint *****local_170;
  /* issue #64 live-repro (2nd instance, same function): DListNode__init(pendingListA=auStack_16c), two lines
   * below DListNode__init(pendingListB=auStack_154) which already got this fix, writes the same 6-word/0x18-byte
   * sentinel-list header (see the comment on auStack_154 just below) - word[2] (self-referential "next",
   * program[2] = program+3) is what `local_164`'s four loops read as the list head, same shape as
   * local_14c's. auStack_16c was declared only 8 bytes with local_164 as a separate scalar 8 bytes in;
   * live-confirmed the pointer this yields (local_164, still holding the list head's own address) is a
   * real puVar13 but reads back as MallocPreScribble's 0xAA fill - i.e. never received the init write,
   * same root cause as local_14c's, just missed by that fix since it's a second, independent instance.
   * Merged into one 0x18-byte buffer the same way, aliased back to the original name. */
  unsigned char auStack_16c [0x18];
#define local_164 (*(int *)(auStack_16c + 0x08))
  /* issue #64 live-repro: DListNode__init (called below via pendingListB=auStack_154) writes program[0]
   * through program[5] - 6 words, 0x18 bytes - into whatever auStack_154 points to, including a
   * self-referential empty-list-head init at program[2] (offset 8: *(auStack_154+8) = auStack_154+12).
   * auStack_154 was declared only 8 bytes; local_14c (used as a list head in four separate loops
   * later in this function) sits exactly at that offset-8 slot by its own hex name (0x154-0x14c=8),
   * and the 12 bytes after it (up to movByRegister, 0x154-0x13c=0x18) are the same buffer's remaining
   * two words, never individually named. Left separate, local_14c never receives its initializer at
   * all in the rebuild (confirmed live: read as garbage/uninitialized), corrupting every one of the
   * four unlink loops that use it as a list head - traced down to a crash in DList__unlink, a plain
   * linked-list unlink helper, dereferencing garbage. Merged into one 0x18-byte buffer. */
  unsigned char auStack_154 [0x18];
#define local_14c (*(int *)(auStack_154 + 0x08))
  uint *movByRegister;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 templateModeWord;
  int pendingListHead;
  uint ****local_118;
  undefined4 tempIndexCache;
  int sharedTempIndex;
  undefined4 composedSelectOut;
  uint ****markedSelectOut;
  undefined4 extraOperandTemp2;
  undefined4 extraOperandTemp1;
  undefined4 fetchResultTemp;
  uint fetchFlagBit;
  uint *****destOperandCount;
  int opcodeFallthrough;
  int writtenComponentCount;
  undefined4 opcodeVariantFlag;
  uint *conditionStack;
  int extraSeen;
  uint *****ifStack;
  uint *****outputSlotCounter;
  undefined4 *usedRegisterBitmap;
  uint literalValue3;
  uint literalValue2;
  uint literalValue1;
  uint literalValue0;
  uint mulAddLiteral3;
  uint *****mulAddLiteral2;
  uint *****mulAddLiteral1;
  uint mulAddLiteral0;
  uint ****scopeLevelPtr;
  undefined *constantsBaseB;
  int opcodeTableBase;
  undefined4 *selectWordPtr;
  undefined1 *pendingListA;
  undefined1 *pendingListB;
  int opcodeTableOffset;
  undefined *constantsBase;
  undefined *constantsBaseC;
  uint ****scopeLevelPtrCopy;
  
  hwInfoObj = *(int *)(*(int *)(program + 8) + 0x30c);
  literalValue3 = 0;
  literalValue2 = 0;
  *(uint *)(hwInfoObj + 8) = *(uint *)(hwInfoObj + 8) & 0xffffffdf;
  literalValue1 = 0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  hwRegisterCount = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50);
  bitmapWordCount = hwRegisterCount + 0x1fU >> 5;
  bitmapAllocation = (undefined4 *)Arena__alloc(compilerArenaB,bitmapWordCount * 4 + 0xc);
  usedRegisterBitmap = bitmapAllocation + 1;
  *bitmapAllocation = compilerArenaB;
  bitmapAllocation[1] = bitmapWordCount;
  bitmapAllocation[2] = hwRegisterCount;
  literalValue0 = 0;
  mulAddLiteral3 = 0;
  mulAddLiteral2 = (uint *****)0x0;
  mulAddLiteral1 = (uint *****)0x0;
  mulAddLiteral0 = 0;
  if (bitmapWordCount != 0) {
    bitmapClearCursor = usedRegisterBitmap;
    if (bitmapWordCount == 0) {
      bitmapWordCount = 1;
    }
    do {
      bitmapWordCount = bitmapWordCount - 1;
      bitmapClearCursor[2] = 0;
      bitmapClearCursor = bitmapClearCursor + 1;
    } while (bitmapWordCount != 0);
  }
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  loopStackAlloc = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  loopStackData = (uint ******)(loopStackAlloc + 1);
  *loopStackAlloc = compilerArenaB;
  loopStackAlloc[1] = 2;
  loopStackAlloc[4] = compilerArenaB;
  loopStackAlloc[2] = 0;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  loopStackAlloc[3] = vectorStorage;
  scopeLevel = (uint ****)0x0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  ifStack = (uint *****)(vectorAllocation + 1);
  *vectorAllocation = compilerArenaB;
  vectorAllocation[1] = 2;
  vectorAllocation[4] = compilerArenaB;
  vectorAllocation[2] = 0;
  ifStackStorage = (uint *****)Arena__alloc(compilerArenaB,8);
  ifStack[2] = (uint ****)ifStackStorage;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  conditionStack = vectorAllocation + 1;
  *vectorAllocation = compilerArenaB;
  vectorAllocation[1] = 2;
  vectorAllocation[2] = 0;
  vectorAllocation[4] = compilerArenaB;
  conditionStackStorage = Arena__alloc(compilerArenaB,8);
  conditionStack[2] = conditionStackStorage;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  vectorAllocation[1] = 2;
  *vectorAllocation = compilerArenaB;
  vectorAllocation[2] = 0;
  vectorAllocation[4] = compilerArenaB;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  vectorAllocation[3] = vectorStorage;
  *(undefined4 **)(program + 0x414) = vectorAllocation + 1;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  vectorAllocation[1] = 2;
  *vectorAllocation = compilerArenaB;
  vectorAllocation[2] = 0;
  vectorAllocation[4] = compilerArenaB;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  vectorAllocation[3] = vectorStorage;
  constantsBaseC = &DAT_001ad5d8;
  previousBlock = *(uint ******)(program + 0x3a0);
  local_128 = 0;
  local_170 = (uint *****)0x1010101;
  lastDeclRegister = (uint ****)0xffffffff;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  movByRegister = vectorAllocation + 1;
  blockAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
  *blockAllocation = compilerArenaA;
  newBlockC = (uint ******)(blockAllocation + 1);
  Block__ctor_ea020(newBlockC,*(undefined4 *)(program + 8));
  currentBlock = (uint *****)newBlockC;
  Program__insertBlockAfter(program,previousBlock,newBlockC);
  pendingListA = auStack_16c;
  Block__connect(previousBlock,currentBlock);
  pendingListB = auStack_154;
  previousBlock = currentBlock;
  DListNode__init(pendingListA);
  DListNode__init(pendingListB);
  *(undefined4 *)(program + 0x3d4) = 0;
  *(undefined4 *)(program + 0x3e4) = 0;
  ((int (*)())Program__loadDefaultConstants)(program,ilReader);
  outputSlotCounter = (uint *****)0x0;
  extraSeen = 0;
switchD_000fdaf0_caseD_2:
  nextInstOk = ILReader__nextInstruction(ilReader);
  if (nextInstOk == 0) {
code_r0x00103c40:
    Program__splitMixedSourceKinds(program);
    Block__connect(currentBlock,*(undefined4 *)(program + 0x3a8));
    *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 2;
    Program__splitCriticalEdges(program,*(undefined4 *)(program + 0x3a0),*(undefined4 *)(program + 0x3a8));
    if ((uint ******)ifStack != (uint ******)0x0) {
      Arena__free(ifStack[3],ifStack[2]);
      Arena__free(ifStack[-1],ifStack + -1);
    }
    if (loopStackData != (uint ******)0x0) {
      Arena__free(loopStackAlloc[4],loopStackAlloc[3]);
      Arena__free(*loopStackAlloc,loopStackAlloc);
    }
    if (usedRegisterBitmap != (undefined4 *)0x0) {
      Arena__free(usedRegisterBitmap[-1],usedRegisterBitmap + -1);
    }
    Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x378),*(undefined4 *)(program + 0x78));
    Program__noSuccessorHasMultipleSuccessors(program);
    return;
  }
  atFirstInst = FUN_000e43ec(ilReader);
  if (atFirstInst != 0) {
    programInstVector = *(int *)(program + 0x3c4);
    loopCounterC = 0;
    templateCursor = (int *)0x0;
    for (programInstIndex = 1; programInstIndex <= *(uint *)(programInstVector + 4); programInstIndex = programInstIndex + 1) {
      templateCursor = *(int **)(loopCounterC + *(int *)(programInstVector + 8));
      if ((templateCursor[5] & 1U) != 0) {
        (**(code **)(*templateCursor + 0x68))(templateCursor);
        pendingInstPtr = templateCursor;
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,1,templateCursor[0x29]);
        movVector = movByRegister;
        movSlotIndex = pendingInstPtr[0x50];
        if (movSlotIndex < *movByRegister) {
          movVectorSizeB = movByRegister[1];
          if (movVectorSizeB <= movSlotIndex) {
            _memset(movVectorSizeB * 4 + movByRegister[2],0,(movSlotIndex - movVectorSizeB) * 4 + 4);
            movVector[1] = movSlotIndex + 1;
          }
          vectorElementSlot = (undefined4 *)(movSlotIndex * 4 + movVector[2]);
        }
        else {
          vectorElementSlot = (undefined4 *)Vector__elementRefGrow(movByRegister,movSlotIndex);
        }
        *vectorElementSlot = movFloatInst;
        programInstVector = *(int *)(program + 0x3c4);
      }
      loopCounterC = loopCounterC + 4;
    }
    hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
    (**(code **)(*hwDescription + 0x17c))(hwDescription,program);
    ILReader__nextInstruction(ilReader);
  }
  tokenWords = ilReader + 0x23;
  *(undefined4 *)(program + 0x47c) = 0;
  ilOpcode = ILReader__currentOpcode(ilReader);
  if (ilOpcode == 0x52) {
    *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x100;
  }
  else if (((ilOpcode == 0x84) && ((*(uint *)(program + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(program + 0x30) & 0x200000) == 0)) goto code_r0x00103c40;
  compiler = *(int *)(program + 8);
  hwDescription = *(int **)(compiler + 0x30c);
  hwOpcodeRecords = hwDescription[3];
  translationKind = ((int (*)())OpcodeRecord__getTranslationKind)(ilOpcode,hwOpcodeRecords);
  switch(translationKind) {
  case 0:
  case 1:
    switch(ilOpcode) {
    case 0x14:
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        destTokenPtr = *ilReader[0x1b];
        registerFile2 = Program__registerFileOfIlType(program,(uint)*destTokenPtr >> 0x10 & 0x3f);
        compiler = *(int *)(program + 8);
        if (((((uint)*destTokenPtr & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((*(uint *)(*(int *)(compiler + 0x30c) + 8) & 0x80) != 0)) {
          firstRegisterIndex = 0xf;
        }
        else {
          firstRegisterIndex = (int)*(short *)((int)destTokenPtr + 2);
        }
        if (((((uint)*ilReader[0x1b][1] & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((*(uint *)(*(int *)(compiler + 0x30c) + 8) & 0x80) != 0)) {
          registerIndex = 0xf;
        }
        else {
          registerIndex = (int)*(short *)((int)ilReader[0x1b][1] + 2);
        }
        if (registerFile2 == 0x15) {
code_r0x000fed00:
          if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
            *(int *)(program + 1000) = firstRegisterIndex;
            *(undefined4 *)(program + 0x3e4) = 1;
            *(int *)(program + 0x3ec) = registerIndex + 1;
            *(int *)(program + 0x3f4) = registerFile2;
            if (((*(uint *)(program + 0x30) & 1) != 0) && (firstRegisterIndex < registerIndex + 1)) {
              do {
                argR6 = (uint ******)0x0;
                VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile2,firstRegisterIndex,0);
                firstRegisterIndex = firstRegisterIndex + 1;
              } while (firstRegisterIndex < *(int *)(program + 0x3ec));
            }
          }
          goto switchD_000fdaf0_caseD_2;
        }
        if (registerFile2 < 0x16) {
          if (registerFile2 != 0x14) goto switchD_000fdaf0_caseD_2;
        }
        else if (registerFile2 != 0x1a) {
          if (registerFile2 == 0x24) goto code_r0x000fed00;
          goto switchD_000fdaf0_caseD_2;
        }
        *(int *)(program + 1000) = firstRegisterIndex;
        *(undefined4 *)(program + 0x3e4) = 1;
        *(int *)(program + 0x3ec) = registerIndex + 1;
        *(int *)(program + 0x3f4) = registerFile2;
        if (((*(uint *)(program + 0x30) & 1) != 0) && (firstRegisterIndex < registerIndex + 1)) {
          do {
            argR6 = (uint ******)0x0;
            VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile2,firstRegisterIndex,0);
            firstRegisterIndex = firstRegisterIndex + 1;
          } while (firstRegisterIndex < *(int *)(program + 0x3ec));
        }
      }
    default:
      goto switchD_000fdaf0_caseD_2;
    case 0x16:
    case 0x18:
      if ((*(uint *)(*(int *)(compiler + 0x6c4) + 0x30) & 0x2000) != 0) {
        destOperandToken = **ilReader[0x19];
        ilRegisterType = (uint)destOperandToken >> 0x10 & 0x3f;
        if (((((uint)destOperandToken & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((hwDescription[2] & 0x80U) != 0)) {
          interpRegisterNumber = (uint ******)((int)((unsigned char *)0xc) + 3);
        }
        else {
          interpRegisterNumber = (uint ******)(int)*(short *)((int)*ilReader[0x19] + 2);
        }
        registerFile = Program__registerFileOfIlType(program,ilRegisterType);
        argR6 = (uint ******)Program__laneKindOfInterpSlot(program,ilRegisterType);
        interpRecord = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,interpRegisterNumber,0);
        interpRecord = *(int *)(interpRecord + 0x38);
        IRLoadInterp__setLane(interpRecord,0,(uint)*tokenWords >> 0x10 & 3,argR6,interpRegisterNumber);
        IRLoadInterp__setLane(interpRecord,1,(uint)*tokenWords >> 0x12 & 3,argR6,interpRegisterNumber);
        IRLoadInterp__setLane(interpRecord,2,(uint)*tokenWords >> 0x14 & 3,argR6,interpRegisterNumber);
        argR7 = interpRegisterNumber;
        IRLoadInterp__setLane(interpRecord,3,(uint)*tokenWords >> 0x16 & 3,argR6,interpRegisterNumber);
        firstTokenWord = *tokenWords;
        if (((uint)firstTokenWord & 0x1000000) != 0) {
          *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 1;
          firstTokenWord = *tokenWords;
        }
        *(uint *******)(interpRecord + 0x148) = interpRegisterNumber;
        *(uint *)(interpRecord + 0x140) = (uint)firstTokenWord >> 0x19 & 1;
        *(undefined4 *)(interpRecord + 0x144) = registerFile;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      laneKindValue = (uint ******)Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x1f);
      interpIndexValue = (uint ******)((uint)*tokenWords >> 0x15 & 0xff);
      if ((int)*tokenWords < 0) {
        modifierTokenWord = ilReader[0x24];
        modifierBit9 = (uint)modifierTokenWord >> 9 & 1;
        modifierBit8 = (uint)modifierTokenWord >> 8 & 1;
        modifierBit10 = (uint)modifierTokenWord >> 10 & 1;
        stagedSelectWord = (uint ******)
                    (CONCAT31(CONCAT21(CONCAT11((char)modifierTokenWord,(char)((uint)modifierTokenWord >> 2)),
                                       (char)((uint)modifierTokenWord >> 4)),
                              (char)((uint)modifierTokenWord >> 6)) & 0x3030303);
      }
      else {
        modifierBit8 = 0;
        modifierBit10 = 0;
        modifierBit9 = 0;
        stagedSelectWord = (uint ******)0x3030303;
      }
      registerIndex = (int)*(short *)((int)*ilReader[0x19] + 2);
      registerFile = Program__registerFileOfIlType(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
      registerRangeStart = *(int *)(program + 1000);
      if (registerIndex <= *(int *)(program + 1000)) {
        registerRangeStart = registerIndex;
      }
      registerEnd = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = registerRangeStart;
      if (registerEnd <= registerIndex) {
        registerEnd = registerIndex + 1;
      }
      *(int *)(program + 0x3ec) = registerEnd;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      argR6 = (uint ******)0x0;
      interpRecord = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,registerIndex,0);
      interpRecord = *(int *)(interpRecord + 0x38);
      if (modifierBit8 == 0) {
        *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 1;
      }
      if (modifierBit10 != 0) {
        *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 4;
      }
      if (modifierBit9 != 0) {
        *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 2;
      }
      selectWordPtr = &stagedSelectWord;
      loopCounterC = 0;
      do {
        if (*(byte *)(loopCounterC + (int)selectWordPtr) != 0) {
          argR6 = laneKindValue;
          argR7 = interpIndexValue;
          IRLoadInterp__setLane(interpRecord,loopCounterC,(uint)*(byte *)(loopCounterC + (int)selectWordPtr),laneKindValue,
                       interpIndexValue);
        }
        notLastIteration = loopCounterC != 3;
        loopCounterC = loopCounterC + 1;
      } while (notLastIteration);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      ilRegisterIndex = *(byte *)((int)ilReader + 0x8d);
      firstTokenWord = *tokenWords;
      ilRegisterRecordOffset = (uint)ilRegisterIndex * 0xc;
      *(uint *)(*(int *)(program + 0x78) + ilRegisterRecordOffset) = (uint)firstTokenWord >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) < (int)(uint)ilRegisterIndex) {
        Compiler__fail(*(int *)(program + 8),7);
      }
      bitmapByteOffset = ilRegisterIndex >> 3 & 0x1c;
      *(uint *)((int)usedRegisterBitmap + bitmapByteOffset + 8) =
           1 << (ilRegisterIndex & 0x1f) | *(uint *)((int)usedRegisterBitmap + bitmapByteOffset + 8);
      *(uint *)(ilRegisterRecordOffset + *(int *)(program + 0x78) + 8) = (uint)*tokenWords >> 0x1d & 1;
      hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
      interpKind = (**(code **)(*hwDescription + 0x48))(hwDescription,program,(uint)firstTokenWord >> 0x18 & 7);
      if (interpKind != 0) {
        *(int *)(ilRegisterRecordOffset + *(int *)(program + 0x78) + 4) = interpKind;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      DListNode__init(&templateModeWord);
      firstTokenWord = *tokenWords;
      argR7 = (uint ******)0x4050607;
      selectIndex = 0;
      if ((int)firstTokenWord < 0) {
        secondTokenWord = ilReader[0x24];
        laneUsedFlag = ((uint)secondTokenWord & 3) != 0;
        argR7 = *(uint *******)(constantsBaseC + -0x2bf8);
        if (laneUsedFlag) {
          argR7 = (uint ******)((uint)argR7 & 0xffffff | 0x4000000);
        }
        selectIndex = (uint)laneUsedFlag;
        if (((uint)secondTokenWord & 0xc) != 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        if (((uint)secondTokenWord & 0x30) != 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        if (((uint)secondTokenWord & 0xc0) != 0) {
          selectByteB = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectByteB | (uint)argR7 & 0xffffff00);
        }
      }
      argR6 = (uint ******)*ilReader[0x19];
      if (((uint)*argR6 & 0x400000) != 0) {
        argR7 = *(uint *******)(constantsBaseC + -0x2bf8);
        laneSelect = psnPackedLaneComponent(argR6,0);
        remapTable = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x1000000 | (uint)argR7 & 0xffffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,1);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,2);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        laneSelect = psnPackedLaneComponent(argR6,3);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          argR7 = (uint ******)(selectIndex + 4 | (uint)argR7 & 0xffffff00);
        }
      }
      registerIndex = (int)*(short *)((int)argR6 + 2);
      registerRangeStart = *(int *)(program + 0x3d8);
      if (registerIndex <= *(int *)(program + 0x3d8)) {
        registerRangeStart = registerIndex;
      }
      loopRegisterEnd = *(int *)(program + 0x3dc);
      *(int *)(program + 0x3d8) = registerRangeStart;
      if (loopRegisterEnd <= registerIndex) {
        loopRegisterEnd = registerIndex + 1;
      }
      *(int *)(program + 0x3dc) = loopRegisterEnd;
      hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
      argR8 = *(uint *******)(program + 0x3a0);
      (**(code **)(*hwDescription + 0x4c))(hwDescription,program,(uint)firstTokenWord >> 0x10 & 0x3f);
      nextListNode = *(int *)(pendingListHead + 8);
      pendingInst = pendingListHead;
      while (flushNode = nextListNode, flushNode != 0) {
        DList__unlink(pendingInst);
        ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
        pendingInst = flushNode;
        nextListNode = *(int *)(flushNode + 8);
      }
      templateModeWord = (uint *****)(PTR_DAT_001e8b48 + 8);
      local_118 = (uint ****)templateModeWord;
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      laneKind = Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x1f);
      interpIndexField = (uint ******)((uint)*tokenWords >> 0x15 & 0xff);
      stagedSelectWord = (uint ******)0x0;
      if ((int)*tokenWords < 0) {
        modifierTokenWord = ilReader[0x24];
        (*(unsigned short *)((unsigned char *)&(stagedSelectWord) + 2)) =
             (ushort)(((uint)(byte)((((uint)modifierTokenWord & 0xc0) == 0) << 1) << 0x14) >> 0x15);
        stagedSelectWord = (uint ******)
                    CONCAT13(((uint)modifierTokenWord & 3) == 0,
                             CONCAT12(((uint)modifierTokenWord & 0xc) == 0,(*(unsigned short *)((unsigned char *)&(stagedSelectWord) + 2))));
        (*(unsigned short *)((unsigned char *)&(stagedSelectWord) + 2)) = CONCAT11(((uint)modifierTokenWord & 0x30) == 0,(undefined1)stagedSelectWord);
      }
      registerIndex = (int)*(short *)((int)*ilReader[0x19] + 2);
      registerFile = Program__registerFileOfIlType(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
      if (laneKind == 0) {
        *(int *)(*(int *)(program + 0x3ac) + 0x44) = registerIndex;
      }
      else if (laneKind == 1) {
        *(int *)(*(int *)(program + 0x3ac) + 0x48) = registerIndex;
      }
      rangeStartValue = *(int *)(program + 1000);
      if (registerIndex <= *(int *)(program + 1000)) {
        rangeStartValue = registerIndex;
      }
      registerEndB = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = rangeStartValue;
      if (registerEndB <= registerIndex) {
        registerEndB = registerIndex + 1;
      }
      *(int *)(program + 0x3ec) = registerEndB;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      argR6 = (uint ******)0x0;
      virtualRegister2 = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,registerIndex,0);
      registerInfo = (**(code **)(*virtualRegister2 + 0x2c))();
      selectWordPtr = &stagedSelectWord;
      loopCounterC = 0;
      do {
        if (*(char *)(loopCounterC + (int)selectWordPtr) == '\0') {
          argR6 = interpIndexField;
          IRLoadInterp__setLaneKindAndIndex(registerInfo,loopCounterC,laneKind,interpIndexField);
        }
        notLastIteration = loopCounterC != 3;
        loopCounterC = loopCounterC + 1;
      } while (notLastIteration);
      goto switchD_000fdaf0_caseD_2;
    case 0x1c:
    case 0x1d:
    case 0x79:
      argR6 = (uint ******)ilReader[0x17];
      destOperandToken = **ilReader[0x19];
      registerIndex2 = *(short *)((int)*ilReader[0x19] + 2);
      if ((int)argR6 < 1) {
        argR6 = (uint ******)0x0;
      }
      else {
        tokenCopyCursor = &templateModeWord;
        tokenCursor = ilReader + (int)ilReader[0x16] + 0x23;
        wordsLeft = argR6;
        do {
          tokenValue = *tokenCursor;
          tokenCursor = tokenCursor + 1;
          *tokenCopyCursor = (uint)tokenValue;
          tokenCopyCursor = tokenCopyCursor + 1;
          wordsLeft = (uint ******)((int)wordsLeft - 1);
        } while (wordsLeft != (uint ******)0x0);
      }
      argR7 = (uint ******)&templateModeWord;
      ((int (*)())Program__createConstantVReg)(program,(uint)destOperandToken >> 0x10 & 0x3f,(int)registerIndex2,argR6,argR7);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      instOpcode0x94 = instAllocation + 1;
      IRInst__ctor_10502c(instOpcode0x94,0x94,*(undefined4 *)(program + 8));
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x2f,0,0);
      IRInst__setOperandRef(instOpcode0x94,0,virtualRegister);
      instAllocation[0x4c] = 0;
      ((int (*)())Program__appendInst)(program,instOpcode0x94,currentBlock);
      hasPendingExtra = extraSeen != 0;
      if (hasPendingExtra) {
        (**(code **)(*instOpcode0x94 + 0x90))(instOpcode0x94,virtualRegister);
      }
      firstTokenWord = *tokenWords;
      argR6 = (uint ******)((uint)firstTokenWord >> 0x17 & 0x3f);
      if (((unsigned char *)0x4) < argR6) {
        argR6 = (uint ******)0x0;
      }
      destTokenPtr = *ilReader[0x1b];
      registerIndex2 = *(short *)((int)destTokenPtr + 2);
      registerFileB = Program__registerFileOfIlType(program,(uint)*destTokenPtr >> 0x10 & 0x3f);
      source1Token = *ilReader[0x1b][1];
      if (((((uint)source1Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        destRegisterNumber = 0xf;
      }
      else {
        destRegisterNumber = (int)*(short *)((int)ilReader[0x1b][1] + 2);
      }
      registerFile27 = Program__registerFileOfIlType(program,(uint)source1Token >> 0x10 & 0x3f);
      virtualRegisterB = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x2b,0,0);
      mulAddInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFileB;
      *(int *)(operandRecord2 + 8) = (int)registerIndex2;
      stagedSelectWord = (uint ******)0x10203;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,destTokenPtr,1,mulAddInst);
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0;
      ((void (*)())IRInst__makeLiteralVec4Float)(mulAddInst,program,2,0.0,1.0,0.0,0.0);
      mulAddLiteral3 = (uint)(short)((ushort)((uint)firstTokenWord >> 0x10) & 0x3f);
      mulAddLiteral0 = mulAddLiteral3 | 0x120000;
      argR8 = (uint ******)(mulAddLiteral3 | 0x100000);
      argR7 = (uint ******)(mulAddLiteral3 | 0x110000);
      mulAddLiteral3 = mulAddLiteral3 | 0xf0000;
      mulAddLiteral2 = (uint *****)argR8;
      mulAddLiteral1 = (uint *****)argR7;
      ((int (*)())IRInst__makeLiteralVec4Int)(mulAddInst,program,3,mulAddLiteral0,argR7,argR8,mulAddLiteral3);
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0x2b;
      *(undefined4 *)(operandRecord2 + 8) = 0;
      ((int (*)())Program__appendInst)(program,mulAddInst,currentBlock);
      (**(code **)(*mulAddInst + 0x90))(mulAddInst,virtualRegister);
      if (hasPendingExtra) {
        (**(code **)(*mulAddInst + 0x90))(mulAddInst,virtualRegisterB);
      }
      IRInst__setHardwareRegisterAndAdd(mulAddInst,program,0x2b,0);
      mulAddInst[0x20] = 1;
      movInst = (int *)IRMov__new_1084b8(0x31,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(movInst,0);
      *(uint *******)(operandRecord2 + 8) = argR6;
      *(undefined4 *)(operandRecord2 + 0xc) = 0x2c;
      operandRecord2 = IRInst__getOperandRecord(movInst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile27;
      *(int *)(operandRecord2 + 8) = destRegisterNumber;
      (**(code **)(*movInst + 0x90))(movInst,virtualRegisterB);
      ((int (*)())Program__appendInst)(program,movInst,currentBlock);
      IRInst__setHardwareRegisterAndAdd(movInst,program,0x2c,argR6);
      extraSeen = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      firstTokenWord = *tokenWords;
      argR6 = (uint ******)*ilReader[0x19];
      argR7 = (uint ******)0x4050607;
      if (((uint)*argR6 & 0x400000) != 0) {
        argR7 = *(uint *******)(constantsBaseC + -0x2bf8);
        laneSelect = psnPackedLaneComponent(argR6,0);
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          argR7 = (uint ******)((uint)argR7 & 0xffffff | 0x4000000);
        }
        selectIndex = (uint)(*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0);
        laneSelect = psnPackedLaneComponent(argR6,1);
        remapTable = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,2);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          selectLaneByte = selectIndex + 4;
          selectIndex = selectIndex + 1;
          argR7 = (uint ******)(selectLaneByte * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        laneSelect = psnPackedLaneComponent(argR6,3);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          compiler = *(int *)(program + 8);
          argR7 = (uint ******)(selectIndex + 4 | (uint)argR7 & 0xffffff00);
        }
        else {
          compiler = *(int *)(program + 8);
        }
      }
      argR8 = (uint ******)currentBlock;
      (**(code **)(**(int **)(compiler + 0x30c) + 0x4c))
                (*(int **)(compiler + 0x30c),program,(uint)firstTokenWord >> 0x10 & 0x3f);
      goto switchD_000fdaf0_caseD_2;
    case 0x6e:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      trailingToken = ilReader[(int)ilReader[0x16] + 0x23];
      blockAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x134);
      *blockAllocation = compilerArenaA;
      newBlockB = (uint *****)(blockAllocation + 1);
      Block__ctor_ea148(newBlockB,*(undefined4 *)(program + 8));
      blockAllocation[0x4c] = trailingToken;
      blockAllocation[1] = PTR_DAT_001e8bd0 + 8;
      currentBlock = newBlockB;
      Program__insertBlockAfter(program,previousBlock,newBlockB);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation = compilerArenaA;
      newBlockC = (uint ******)(blockAllocation + 1);
      Block__ctor_ea020(newBlockC,*(undefined4 *)(program + 8));
      currentBlock = (uint *****)newBlockC;
      Program__insertBlockAfter(program,previousBlock,newBlockC);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar18 = (int *)Arena__alloc(*(undefined4 *)(compiler + 0x378),0xc);
      piVar18[1] = 0;
      piVar18[2] = 0;
      createdMov = IRInst__create(0x31,*(undefined4 *)(program + 8));
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      *piVar18 = newTempIndex2;
      operandRecord = IRInst__getOperandRecord(createdMov,0);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex2;
      stagedSelectWord = (uint ******)0x10203;
      argR8 = (uint ******)&lastDeclRegister;
      ((int (*)())FUN_000fb3d4)(program,pendingListB,tokenWords,*ilReader[0x1b],loopStackData,argR8,&movByRegister);
      source0Token = **ilReader[0x1b];
      if (((((uint)source0Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        destRegisterNumber = 0xf;
      }
      else {
        destRegisterNumber = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      registerFile = Program__registerFileOfIlType(program,(uint)source0Token >> 0x10 & 0x3f);
      operandRecord2 = IRInst__getOperandRecord(createdMov,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = destRegisterNumber;
      argR6 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR7 = createdMov;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*ilReader[0x1b],1,createdMov);
      nextListNode = *(int *)(local_14c + 8);
      pendingInst = local_14c;
      while (flushNodeC = nextListNode, flushNodeC != 0) {
        DList__unlink(pendingInst);
        ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
        pendingInst = flushNodeC;
        nextListNode = *(int *)(flushNodeC + 8);
      }
      ((int (*)())Program__appendInst)(program,createdMov,currentBlock);
      conditionStackCount = conditionStack[1];
      if (conditionStackCount < *conditionStack) {
        _memset(conditionStackCount * 4 + conditionStack[2],0,4);
        conditionStack[1] = conditionStackCount + 1;
        vectorSlotC = (int *)(conditionStackCount * 4 + conditionStack[2]);
      }
      else {
        vectorSlotC = (int *)Vector__elementRefGrow(conditionStack,conditionStackCount);
      }
      goto code_r0x000febe0;
    case 0x73:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      piVar18 = instAllocation + 1;
      IRInst__ctor_10502c(piVar18,0xf8,*(undefined4 *)(program + 8));
      instAllocation[0x4c] = ilReader[(int)ilReader[0x16] + 0x23];
      ((int (*)())Program__appendInst)(program,piVar18,currentBlock);
      break;
    case 0x76:
    case 0x77:
      if ((ilOpcode == 0x76) && ((int)*tokenWords < 0)) {
        immConstData = ilReader[10];
        argR6 = (uint ******)0x0;
        trailingToken = ilReader[(int)ilReader[0x16] + 0x23];
        virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x43,0xffffffff,0);
        immConstBuffInst = IRImmedConstBuff__new_109b74(0x10a,*(undefined4 *)(program + 8));
        *(int *)(program + 0x354) = immConstBuffInst;
        IRInst__setOperandRef(immConstBuffInst,0,virtualRegister);
        *(uint ******)(immConstBuffInst + 300) = immConstData + (int)trailingToken;
        Block__appendInst(*(undefined4 *)(program + 0x3a0),immConstBuffInst);
      }
      else {
        firstSourceWordIndex = 1;
        destTokenPtr = *ilReader[0x1b];
        sourceRegisterIndex = (uint)*(ushort *)((int)destTokenPtr + 2);
        ilRegisterType = (uint)*destTokenPtr >> 0x10 & 0x3f;
        if ((int)*destTokenPtr < 0) {
          firstSourceWordIndex = 2;
          sourceRegisterIndex = sourceRegisterIndex | (int)destTokenPtr[1] << 0x10;
        }
        firstSourceToken = destTokenPtr[firstSourceWordIndex];
        if (ilRegisterType == 0x1c) {
          declVector = *(uint **)(program + 0x90);
          if (declVector == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(compiler + 0x374);
            vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            declVector = vectorAllocation + 1;
            *vectorAllocation = compilerArenaA;
            vectorAllocation[1] = 2;
            vectorAllocation[2] = 0;
            vectorAllocation[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            vectorAllocation[3] = vectorStorage;
            *(uint **)(program + 0x90) = declVector;
          }
        }
        else {
          declVector = *(uint **)(program + 0x8c);
          if (declVector == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(compiler + 0x374);
            vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            declVector = vectorAllocation + 1;
            *vectorAllocation = compilerArenaA;
            vectorAllocation[1] = 2;
            vectorAllocation[2] = 0;
            vectorAllocation[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            vectorAllocation[3] = vectorStorage;
            *(uint **)(program + 0x8c) = declVector;
          }
        }
        if (sourceRegisterIndex < *declVector) {
          declVectorSize = declVector[1];
          if (declVectorSize <= sourceRegisterIndex) {
            _memset(declVectorSize * 4 + declVector[2],0,(sourceRegisterIndex - declVectorSize) * 4 + 4);
            declVector[1] = sourceRegisterIndex + 1;
          }
          declVectorSlot = (uint *)(sourceRegisterIndex * 4 + declVector[2]);
        }
        else {
          declVectorSlot = (uint *)Vector__elementRefGrow(declVector,sourceRegisterIndex);
        }
        *declVectorSlot = (uint)firstSourceToken;
        usedBitmapWord = (sourceRegisterIndex >> 3 & 0x1ffffffc) + *(int *)(program + 0x434);
        *(uint *)(usedBitmapWord + 8) = 1 << (sourceRegisterIndex & 0x1f) | *(uint *)(usedBitmapWord + 8);
        if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 8) != 0) {
          compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
          instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
          *instAllocation = compilerArenaA;
          instObject = instAllocation + 1;
          IRLoad__ctor_109a80(instObject,0xfa,*(undefined4 *)(program + 8));
          registerFile = Program__registerFileOfIlType(program,ilRegisterType);
          operandRecord = IRInst__getOperandRecord(instObject,0);
          *(undefined4 *)(operandRecord + 0xc) = registerFile;
          *(uint *)(operandRecord + 8) = sourceRegisterIndex;
          instAllocation[0x4c] = firstSourceToken;
          ((int (*)())Program__appendInst)(program,instObject,*(undefined4 *)(program + 0x3a0));
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x78:
      *(uint *)(program + 0x400) = (uint)*tokenWords >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7a:
      *(uint *)(program + 0x3f8) = (uint)*tokenWords >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7c:
      *(uint *)(program + 0x3fc) = (uint)*tokenWords >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7d:
      destTokenPtr = *ilReader[0x19];
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(program + 0x30) & 1) != 0) {
          stagedSelectWord = (uint ******)0x0;
          declRegister = (uint ******)(int)*(short *)((int)destTokenPtr + 2);
          registerFile = Program__registerFileOfIlType(program,(uint)*destTokenPtr >> 0x10 & 0x3f);
          laneKind = Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x3fff);
          if (laneKind == 0) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x44) = declRegister;
          }
          else if (laneKind == 1) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x48) = declRegister;
          }
          rangeStartValueC = *(uint *******)(program + 1000);
          if ((int)declRegister <= (int)*(uint *******)(program + 1000)) {
            rangeStartValueC = declRegister;
          }
          registerEndC = *(undefined1 **)(program + 0x3ec);
          *(uint *******)(program + 1000) = rangeStartValueC;
          if ((int)registerEndC <= (int)declRegister) {
            registerEndC = (undefined1 *)((int)declRegister + 1);
          }
          *(undefined1 **)(program + 0x3ec) = registerEndC;
          *(undefined4 *)(program + 0x3f4) = 0x24;
          if (laneKind == 0xd) {
            registerMap2 = *(int *)(program + 0x3ac);
            if (*(int *)(registerMap2 + 0x4c) == -1) {
              *(uint *******)(registerMap2 + 0x4c) = declRegister;
            }
            else {
              *(uint *******)(registerMap2 + 0x54) = declRegister;
            }
          }
          else if (laneKind == 0xe) {
            registerMap2 = *(int *)(program + 0x3ac);
            if (*(int *)(registerMap2 + 0x50) == -1) {
              *(uint *******)(registerMap2 + 0x50) = declRegister;
            }
            else {
              *(uint *******)(registerMap2 + 0x58) = declRegister;
            }
          }
          else if (laneKind == 0xb) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x5c) = declRegister;
          }
          else if (laneKind == 0xc) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x60) = declRegister;
          }
          else if (laneKind == 0xf) {
            *(uint *******)(*(int *)(program + 0x3ac) + 100) = declRegister;
          }
          argR6 = (uint ******)0x0;
          virtualRegister2 = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,declRegister,0);
          loadInterpRecord = (**(code **)(*virtualRegister2 + 0x2c))();
          selectWordPtr = &stagedSelectWord;
          *(uint *******)(loadInterpRecord + 0x140) = declRegister;
          loopCounterD = 0;
          do {
            if (*(char *)(loopCounterD + (int)selectWordPtr) == '\0') {
              argR6 = declRegister;
              IRLoadInterp__setLaneKindAndIndex(loadInterpRecord,loopCounterD,laneKind,declRegister);
            }
            notLastIteration = loopCounterD != 3;
            loopCounterD = loopCounterD + 1;
          } while (notLastIteration);
        }
      }
      else {
        argR7 = (uint ******)0x10203;
        argR6 = (uint ******)(uint)*(ushort *)((int)destTokenPtr + 2);
        argR8 = (uint ******)0x0;
        (**(code **)(*hwDescription + 0x54))(hwDescription,argR6,(uint)*tokenWords >> 0x10 & 0x3fff);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      declKindField = (uint)*tokenWords >> 0xe & 0x1f;
      laneKindValue = (uint ******)Program__lookupTable8b68(program,declKindField);
      tokenModeField = (uint)*tokenWords >> 0x13 & 7;
      if (tokenModeField == 3) {
        clearsInfoFlag1 = true;
        setsInterpBit4 = false;
        setsInterpBit2 = false;
      }
      else if (tokenModeField < 4) {
        if (tokenModeField == 1) {
          clearsInfoFlag1 = false;
          setsInterpBit4 = false;
          setsInterpBit2 = true;
        }
        else {
code_r0x000feeb8:
          clearsInfoFlag1 = false;
          setsInterpBit4 = false;
          setsInterpBit2 = false;
        }
      }
      else if (tokenModeField == 4) {
        clearsInfoFlag1 = false;
        setsInterpBit4 = true;
        setsInterpBit2 = false;
      }
      else {
        if (tokenModeField != 5) goto code_r0x000feeb8;
        clearsInfoFlag1 = true;
        setsInterpBit4 = true;
        setsInterpBit2 = false;
      }
      destinationToken = (uint ******)*ilReader[0x19];
      firstTokenWord = *destinationToken;
      if (((uint)firstTokenWord & 0x400000) == 0) {
        if (((uint)firstTokenWord & 0x2000000) == 0) {
          extWordCursor = (uint ******)0x0;
          extensionWordPtr = (uint ******)0x0;
        }
        else {
          extWordCursor = destinationToken + 1;
          extensionWordPtr = (uint ******)0x0;
        }
      }
      else {
        extensionWordPtr = destinationToken + 1;
        extWordCursor = (uint ******)0x0;
        if (((uint)firstTokenWord & 0x2000000) != 0) {
          extWordCursor = destinationToken + 2;
        }
      }
      if (((*(uint *)(program + 0x30) & 1) == 0) && ((*(uint *)(program + 0x30) & 0x2000) == 0)) {
        if (declKindField == 10) {
          lastDeclRegister = (uint ****)(uint)*(ushort *)((int)extWordCursor + 2);
          stagedSelectWord = (uint ******)0x10101;
          selectTableEntry = &stagedSelectWord;
          if (((uint)*extensionWordPtr & 3) == 1) {
            selectTableEntry = &DAT_001aa9d0;
          }
          swizzleTable = &stagedSelectWord;
          stagedSelectWord = (uint ******)*selectTableEntry;
          if (((uint)*extensionWordPtr & 0xc) == 4) {
            swizzleTable = &UNK_001aa9c4;
          }
          selectTableEntry = &stagedSelectWord;
          stagedSelectWord = (uint ******)*swizzleTable;
          if (((uint)*extensionWordPtr & 0x30) == 0x10) {
            selectTableEntry = &UNK_001aa9c0;
          }
          swizzleTable = &stagedSelectWord;
          stagedSelectWord = (uint ******)*selectTableEntry;
          if (((uint)*extensionWordPtr & 0xc0) == 0x40) {
            swizzleTable = &UNK_001aa9bc;
          }
          stagedSelectWord = (uint ******)*swizzleTable;
          local_170 = (uint *****)stagedSelectWord;
        }
      }
      else {
        ilRegisterType = (uint)firstTokenWord >> 0x10 & 0x3f;
        declRegisterNumber = (uint ******)(uint)*(ushort *)((int)destinationToken + 2);
        registerFile = Program__registerFileOfIlType(program,ilRegisterType);
        movVector = movByRegister;
        declRangeStart = *(uint *******)(program + 1000);
        if ((int)declRegisterNumber <= (int)*(uint *******)(program + 1000)) {
          declRangeStart = declRegisterNumber;
        }
        registerEndC = *(undefined1 **)(program + 0x3ec);
        *(uint *******)(program + 1000) = declRangeStart;
        if ((int)registerEndC <= (int)declRegisterNumber) {
          registerEndC = (undefined1 *)((int)declRegisterNumber + 1);
        }
        *(undefined1 **)(program + 0x3ec) = registerEndC;
        *(undefined4 *)(program + 0x3f4) = 0x24;
        argR7 = (uint ******)0x4050607;
        if ((*(uint *)(program + 0x30) & 1) == 0) {
          interpRecord = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,declRegisterNumber,0);
          interpRecord = *(int *)(interpRecord + 0x38);
          if (!clearsInfoFlag1) {
            *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 1;
          }
          if (setsInterpBit4) {
            *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 4;
          }
          if (setsInterpBit2) {
            *(uint *)(interpRecord + 0x13c) = *(uint *)(interpRecord + 0x13c) | 2;
          }
          loopCounterC = 0;
          do {
            argR6 = laneKindValue;
            argR7 = declRegisterNumber;
            IRLoadInterp__setLane(interpRecord,loopCounterC,1,laneKindValue,declRegisterNumber);
            notLastIteration = loopCounterC != 3;
            loopCounterC = loopCounterC + 1;
          } while (notLastIteration);
        }
        else if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
          argR8 = *(uint *******)(program + 0x3a0);
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          (**(code **)(*hwDescription + 0x4c))(hwDescription,program,declRegisterNumber);
          argR6 = destinationToken;
        }
        else if (ilRegisterType != 9) {
          registerNumber = (uint)*(ushort *)((int)extWordCursor + 2);
          if (registerNumber < *movByRegister) {
            movVectorSize = movByRegister[1];
            if (movVectorSize <= registerNumber) {
              _memset(movVectorSize * 4 + movByRegister[2],0,(registerNumber - movVectorSize) * 4 + 4);
              movVector[1] = registerNumber + 1;
            }
            vectorElementSlot = (undefined4 *)(registerNumber * 4 + movVector[2]);
          }
          else {
            vectorElementSlot = (undefined4 *)Vector__elementRefGrow(movByRegister,registerNumber);
          }
          ppppppuVar49 = (uint ******)*vectorElementSlot;
          argR6 = (uint ******)0x0;
          newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
          virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0,newTempIndex,0);
          IRInst__setOperandRef(ppppppuVar49,0,virtualRegister);
          goto code_r0x000ff070;
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x80:
      ilRegisterIndex = *(byte *)((int)ilReader + 0x8d);
      interpMode = (uint)*tokenWords >> 0x18 & 0xf;
      if (hwDescription[0x14] < (int)(uint)ilRegisterIndex) {
        Compiler__fail(compiler,7);
      }
      bitmapByteOffset2 = ilRegisterIndex >> 3 & 0x1c;
      ilRegisterRecordOffset = (uint)ilRegisterIndex * 0xc;
      *(uint *)((int)usedRegisterBitmap + bitmapByteOffset2 + 8) =
           1 << (ilRegisterIndex & 0x1f) | *(uint *)((int)usedRegisterBitmap + bitmapByteOffset2 + 8);
      *(undefined4 *)(*(int *)(program + 0x78) + ilRegisterRecordOffset) = 1;
      if (interpMode != 0) {
        *(uint *)(ilRegisterRecordOffset + *(int *)(program + 0x78) + 4) = interpMode;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      outputSlotCounter = (uint *****)((int)outputSlotCounter + 1);
      if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
        if (loopStackAlloc[2] != 0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x180000;
        }
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x80000;
        }
        createdInstB = IRInst__create(*(undefined4 *)
                                (ilOpcode * 0x24 + *(int *)(*(int *)(compiler + 0x30c) + 0xc)),compiler);
        operandRecord = IRInst__getOperandRecord(createdInstB,0);
        *(undefined4 *)(operandRecord + 0xc) = 0x2c;
        *(undefined4 *)(operandRecord + 8) = 0;
        *(undefined4 *)((int)createdInstB + 0x9c) = 0x10101;
        operandRecord = IRInst__getOperandRecord(createdInstB,1);
        *(undefined4 *)(operandRecord + 0xc) = 0x2c;
        *(undefined4 *)(operandRecord + 8) = 0;
        operandRecord = IRInst__getOperandRecord(createdInstB,1);
        *(undefined4 *)(operandRecord + 0x10) = 0;
        ((int (*)())Program__appendInst)(program,createdInstB,currentBlock);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x87:
      ilRegisterIndex2 = (uint)*(byte *)((int)ilReader + 0x8d);
      firstTokenWord = *tokenWords;
      if (*(int *)(program + 0x7c) < (int)ilRegisterIndex2) {
        *(uint *)(program + 0x7c) = ilRegisterIndex2;
      }
      *(uint *)(program + 0x84) = 1 << (ilRegisterIndex2 & 0x3f) | *(uint *)(program + 0x84);
      stagedSelectWord = (uint ******)0x10203;
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex = *(int *)(compiler + 0x3ac) + -1;
      *(int *)(compiler + 0x3ac) = newTempIndex;
      virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex,0);
      virtualRegisterC = *(undefined4 *)(program + 0x3ac);
      newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
      virtualRegisterC = VRegPool__findOrCreate(virtualRegisterC,0,newTempIndex,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,virtualRegisterC);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())Template__bindOperand)(program,5,1,ilReader,movFloatInst,1,0,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      getResourceInst = IRInst__create(0x109,*(undefined4 *)(program + 8));
      *(uint *)((int)getResourceInst + 0x134) = ilRegisterIndex2;
      IRInst__setOperandRef(getResourceInst,0,virtualRegister);
      IRInst__setOperandRef(getResourceInst,1,virtualRegisterC);
      ((int (*)())Program__appendInst)(program,getResourceInst,currentBlock);
      resourceOperandTable = PTR_DAT_001e8b8c;
      remapTable = PTR_DAT_001e8b64;
      stagedSelectWord = (uint ******)0x10203;
      if (((uint)firstTokenWord & 0x1f000000) != 0x1000000) {
        loopCounterB = 0;
        do {
          int2FInst = IRInst__create(0xe1,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(int2FInst,0,virtualRegister);
          IRInst__setOperandRef(int2FInst,1,virtualRegister);
          resourceOperandWord = *(undefined4 *)(resourceOperandTable + loopCounterB);
          *(undefined4 *)((int)int2FInst + 0x9c) = *(undefined4 *)(remapTable + loopCounterB);
          operandRecord2 = IRInst__getOperandRecord(int2FInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = resourceOperandWord;
          ((int (*)())Program__appendInst)(program,int2FInst,currentBlock);
          notLastIteration = loopCounterB != 0xc;
          loopCounterB = loopCounterB + 4;
        } while (notLastIteration);
      }
      ppppppuVar49 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = ppppppuVar49;
      ((int (*)())Template__bindOperand)(program,0,0,ilReader,ppppppuVar49,1,0,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar49,1,virtualRegister);
code_r0x000ff070:
      ((int (*)())Program__appendInst)(program,ppppppuVar49,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      instOpcode0xb4 = (uint ******)(instAllocation + 1);
      IRInst__ctor_10502c(instOpcode0xb4,0xb4,*(undefined4 *)(program + 8));
      if (((uint)*tokenWords & 0x3fff0000) != 0) {
        instAllocation[0x4c] = 1;
      }
      argR8 = (uint ******)&lastDeclRegister;
      ((int (*)())FUN_000fb3d4)(program,pendingListB,tokenWords,*ilReader[0x1b],loopStackData,argR8,&movByRegister);
      source0Token = **ilReader[0x1b];
      if (((((uint)source0Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        destRegisterNumber = 0xf;
      }
      else {
        destRegisterNumber = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      ilRegisterType = (uint)source0Token >> 0x10 & 0x3f;
      exportVReg = VRegPool__find(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
      if (exportVReg == 0) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *instAllocation = compilerArenaA;
        exportInst = instAllocation + 1;
        IRExport__ctor_108918(exportInst,*(undefined4 *)(program + 8));
        instAllocation[6] = instAllocation[6] | 0x10000;
        *(undefined4 **)(program + 0x350) = exportInst;
        instAllocation[0x28] = 0;
        exportVReg = VRegPool__create(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
        IRInst__setOperandRef(exportInst,0,exportVReg);
        IRInst__setOperandRef(exportInst,1,exportVReg);
        operandRecordX = IRInst__getOperandRecord(exportInst,1);
        *(undefined4 *)(operandRecordX + 0x10) = 0x10203;
        Block__appendInst(*(undefined4 *)(program + 0x3a8),exportInst);
        VReg__appendUser(exportVReg,exportInst);
        VReg__addUse(exportVReg,1,exportInst);
      }
      IRInst__setOperandRef(instOpcode0xb4,0,exportVReg);
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(instOpcode0xb4,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = destRegisterNumber;
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(instOpcode0xb4,2);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = destRegisterNumber;
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(instOpcode0xb4,3);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      selectWordPtr = &stagedSelectWord;
      *(int *)(operandRecord2 + 8) = destRegisterNumber;
      stagedSelectWord = (uint ******)0x10101;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],1,instOpcode0xb4);
      stagedSelectWord = (uint ******)0x2020202;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],2,instOpcode0xb4);
      argR6 = (uint ******)((int)((unsigned char *)0x0) + 3);
      stagedSelectWord = (uint ******)0x3030303;
      argR7 = instOpcode0xb4;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],3,instOpcode0xb4);
      nextListNode = *(int *)(local_14c + 8);
      pendingInst = local_14c;
      while (flushNodeC = nextListNode, flushNodeC != 0) {
        DList__unlink(pendingInst);
        ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
        pendingInst = flushNodeC;
        nextListNode = *(int *)(flushNodeC + 8);
      }
      ((int (*)())Program__appendInst)(program,instOpcode0xb4,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      piVar18 = instAllocation + 1;
      IRInst__ctor_10502c(piVar18,0x106,*(undefined4 *)(program + 8));
      ((int (*)())Program__appendInst)(program,piVar18,currentBlock);
    }
    pendingVector = *(uint **)(program + 0x414);
    vectorSize = pendingVector[1];
    if (vectorSize < *pendingVector) {
      _memset(vectorSize * 4 + pendingVector[2],0,4);
      vectorSlotC = (int *)(vectorSize * 4 + pendingVector[2]);
      pendingVector[1] = vectorSize + 1;
    }
    else {
      vectorSlotC = (int *)Vector__elementRefGrow(pendingVector,vectorSize);
    }
code_r0x000febe0:
    *vectorSlotC = (int)piVar18;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    isTranslationKind7 = false;
    break;
  case 5:
    constantsBaseB = &DAT_001ad5d8;
    constantsBase = &DAT_001ad5d8;
    templateBase = *(int *)(ilOpcode * 0x24 + hwOpcodeRecords + 0x18);
    templateModeWord = (uint *****)0x0;
    stagedSelectWord = (uint ******)0x10203;
    compilerArenaB = *(undefined4 *)(compiler + 0x378);
    vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    scopeVectorB = vectorAllocation + 1;
    *vectorAllocation = compilerArenaB;
    vectorAllocation[1] = 2;
    vectorAllocation[2] = 0;
    vectorAllocation[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    vectorAllocation[3] = vectorStorage;
    compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    vectorAllocation2 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    scopeVector = (uint ******)(vectorAllocation2 + 1);
    *vectorAllocation2 = compilerArenaB;
    vectorAllocation2[1] = 2;
    vectorAllocation2[2] = 0;
    vectorAllocation2[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    vectorAllocation2[3] = vectorStorage;
    templateCursor = (int *)0x0;
    _memcpy(&tempIndexCache,&UNK_001aaa2c,0x24);
    compilerRef = *(int *)(program + 8);
    operandNumber = (uint ******)0x0;
    opcodeRecordTable = *(undefined4 *)(*(int *)(compilerRef + 0x30c) + 0xc);
    destOperandCount = (uint *****)((int (*)())OpcodeRecord__getField8)(ilOpcode,opcodeRecordTable);
    opcodeOperandCount = ((int (*)())OpcodeRecord__getOperandCount)(ilOpcode,opcodeRecordTable);
    if (0 < (int)destOperandCount) {
      do {
        operandByteOffset = (int)operandNumber << 2;
        for (laneLoopIndex = 0;
            iVar23 = ((int (*)())OpcodeRecord__getOperandByte)(ilOpcode,operandNumber,
                                  *(undefined4 *)(*(int *)(compilerRef + 0x30c) + 0xc)), laneLoopIndex <= iVar23
            ; laneLoopIndex = laneLoopIndex + 1) {
          argR6 = loopStackData;
          argR7 = (uint ******)outputSlotCounter;
          ((int (*)())FUN_000f9a58)(program,pendingListA,*(undefined4 *)((int)ilReader[0x19] + operandByteOffset),loopStackData,
                       outputSlotCounter);
          compilerRef = *(int *)(program + 8);
          operandByteOffset = operandByteOffset + 0x14;
        }
        operandNumber = (uint ******)((int)operandNumber + 1);
      } while ((uint ******)destOperandCount != operandNumber);
    }
    operandIndexB = 0;
    if (0 < opcodeOperandCount) {
      do {
        operandByteOffsetC = operandIndexB << 2;
        laneMaskPtr = (undefined1 *)((int)destOperandCount + operandIndexB);
        for (iVar23 = 0;
            operandByteLimit = ((int (*)())OpcodeRecord__getOperandByte)(ilOpcode,laneMaskPtr,*(undefined4 *)(*(int *)(compilerRef + 0x30c) + 0xc)),
            iVar23 <= operandByteLimit; iVar23 = iVar23 + 1) {
          argR6 = *(uint *******)((int)ilReader[0x1b] + operandByteOffsetC);
          argR8 = (uint ******)&lastDeclRegister;
          argR7 = loopStackData;
          ((int (*)())FUN_000fb3d4)(program,pendingListB,tokenWords,argR6,loopStackData,argR8,&movByRegister);
          compilerRef = *(int *)(program + 8);
          operandByteOffsetC = operandByteOffsetC + 0x14;
        }
        operandIndexB = operandIndexB + 1;
      } while (opcodeOperandCount != operandIndexB);
    }
    nextListNodeB = *(int *)(local_14c + 8);
    pendingInstB = local_14c;
    while (flushNodeB = nextListNodeB, flushNodeB != 0) {
      DList__unlink(pendingInstB);
      ((int (*)())Program__appendInst)(program,pendingInstB,currentBlock);
      pendingInstB = flushNodeB;
      nextListNodeB = *(int *)(flushNodeB + 8);
    }
    opcodeVariantFlag = 0;
    workInst = (uint ******)0x0;
    operandIndexC = (uint ******)0x0;
code_r0x001005f4:
    savedCurrentBlock = (uint ******)currentBlock;
    opcodeTemplateTable = (uint ******)PTR_DAT_001e8bd4;
    templateToken = *(uint *)(templateBase + (int)templateCursor * 4);
    if (0x71 < templateToken) goto switchD_0010061c_caseD_0;
    switch(templateToken) {
    default:
      goto switchD_0010061c_caseD_0;
    case 1:
    case 0x13:
    case 0x33:
    case 0x39:
    case 0x3b:
    case 0x3c:
    case 0x3e:
    case 0x40:
    case 0x4c:
    case 0x5e:
      goto switchD_0010061c_caseD_1;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
      argR6 = ilReader;
      argR7 = workInst;
      argR8 = (uint ******)destOperandCount;
      builtInst = ((int (*)())Template__bindOperand)(program,templateToken - 2,operandIndexC,ilReader,workInst,destOperandCount,templateModeWord,
                            &stagedSelectWord,loopStackData,opcodeVariantFlag,currentBlock);
      if (builtInst != 0) {
        DList__pushFront(pendingListA,builtInst);
      }
      goto code_r0x001025c0;
    case 0x12:
      IROperand__setModifierBits(workInst + (int)operandIndexC * 6 + 0x23,2,1);
      goto code_r0x00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      tokenIndexField = (uint)*tokenWords >> 0x10 & 0x3fff;
      if (templateToken == 0x14) {
        argR7 = (uint ******)(PTR_DAT_001dc78c)[tokenIndexField];
      }
      else if (templateToken == 0x15) {
        argR7 = (uint ******)(PTR_DAT_001dc77c)[tokenIndexField];
      }
      else {
        argR7 = (uint ******)(PTR_DAT_001dc76c)[tokenIndexField];
      }
      goto code_r0x001022b4;
    case 0x17:
      enclosingScopeOpcode = ILReader__topScopeOpcode(ilReader);
      if ((enclosingScopeOpcode == 0x3e) || (enclosingScopeOpcode = ILReader__topScopeOpcode(ilReader), enclosingScopeOpcode == 0x71)) {
        loopDepth = loopStackAlloc[2];
        if (loopDepth != 0) {
          stackElement = (int *)0x0;
          if (loopDepth - 1 < loopDepth) {
            stackElement = (int *)((loopDepth - 1) * 4 + loopStackAlloc[3]);
          }
          scopeObject = *stackElement;
          ifStackCount = (uint *****)ifStack[1];
          opcodeTemplateTable = (uint ******)PTR_DAT_001e8bbc;
          if (ifStackCount != (uint *****)0x0) {
            ifStackTopSlot = (uint *****)0x0;
            if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
              ifStackTopSlot = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
            }
            if ((int)scopeLevel <= (int)(*ifStackTopSlot)[0x2e]) {
              breakTargetBlock = *(undefined4 *)(scopeObject + 0x154);
              arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
              blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x138);
              *blockAllocation4 = arenaA;
              breakBlock = (uint ******)(blockAllocation4 + 1);
              argR6 = *(uint *******)(program + 8);
              BreakBlock__ctor_ec0c8(breakBlock,scopeObject,*(undefined4 *)(scopeObject + 300),argR6);
              blockAllocation4[0x2f] = scopeLevel;
              Program__insertBlockAfter(program,previousBlock,breakBlock);
              Block__connect(previousBlock,breakBlock);
              Block__connect(breakBlock,breakTargetBlock);
              opcodeFallthrough = 0;
              *(int *)(scopeObject + 0x138) = *(int *)(scopeObject + 0x138) + 1;
              previousBlock = (uint *****)breakBlock;
              break;
            }
          }
          goto code_r0x00103718;
        }
      }
      else {
        enclosingScopeOpcode = ILReader__topScopeOpcode(ilReader);
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8bb4;
        if (enclosingScopeOpcode == 0x72) {
          stackElement = (int *)0x0;
          conditionStackTopIndex = conditionStack[1] - 1;
          if (conditionStackTopIndex < conditionStack[1]) {
            stackElement = (int *)(conditionStackTopIndex * 4 + conditionStack[2]);
          }
          *(int *)(*stackElement + 4) = *(int *)(*stackElement + 4) + 1;
code_r0x00103718:
          argR6 = (uint ******)0x0;
          argR8 = scopeVector;
          templateBase = ((int (*)())Template__pushCallFrame)(program,templateBase,&templateCursor,0,opcodeTemplateTable,scopeVector);
          argR7 = opcodeTemplateTable;
          goto code_r0x0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      templateCursor = (int *)((int)templateCursor + 1);
      templateToken = *(uint *)(templateBase + (int)templateCursor * 4);
      stagedSelectWord = (uint ******)
                  (templateToken << 0x18 | (templateToken & 0xff00) << 8 | templateToken >> 8 & 0xff00 | templateToken >> 0x18);
      opcodeFallthrough = 0;
      break;
    case 0x20:
      templateCursor = (int *)((int)templateCursor + 1);
      templateToken = *(uint *)(templateBase + (int)templateCursor * 4);
      argR7 = (uint ******)&templateModeWord;
      templateModeWord = (uint *****)
                  (templateToken << 0x18 | (templateToken & 0xff00) << 8 | templateToken >> 8 & 0xff00 | templateToken >> 0x18);
      opcodeFallthrough = 0;
      break;
    case 0x21:
      opcodeTemplateTable = (uint ******)0x0;
      switch((uint)*tokenWords >> 0x10 & 7) {
      case 0:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b80;
        break;
      case 1:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8bac;
        break;
      case 2:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8ba8;
        break;
      case 3:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8bcc;
        break;
      case 4:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b94;
        break;
      case 5:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      tokenModeField = (uint)*tokenWords >> 0x16 & 7;
      if (tokenModeField == 0) goto switchD_0010061c_caseD_1;
      createdInst0x12 = IRInst__create(0x12,*(undefined4 *)(program + 8));
      if (sharedTempIndex == 0) {
        sharedTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = sharedTempIndex;
      }
      savedRegisterIndex = sharedTempIndex;
      operandRecordLast = IRInst__getOperandRecord(createdInst0x12,0);
      *(int *)(operandRecordLast + 8) = savedRegisterIndex;
      *(undefined4 *)(operandRecordLast + 0xc) = 0;
      source0Token = **ilReader[0x1b];
      if (((((uint)source0Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        sourceRegisterIndexB = 0xf;
      }
      else {
        sourceRegisterIndexB = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      registerFile = Program__registerFileOfIlType(program,(uint)source0Token >> 0x10 & 0x3f);
      operandRecordB = IRInst__getOperandRecord(createdInst0x12,1);
      *(undefined4 *)(operandRecordB + 0xc) = registerFile;
      *(int *)(operandRecordB + 8) = sourceRegisterIndexB;
      argR6 = operandIndexC;
      argR7 = createdInst0x12;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*ilReader[0x1b],operandIndexC,createdInst0x12);
      if (tokenModeField == 2) {
        literalFloat = 1.0;
code_r0x001021c0:
        literalValue = (double)literalFloat;
        ((void (*)())IRInst__makeLiteralVec4Float)(createdInst0x12,program,2,literalValue,literalValue,literalValue,literalValue);
        IROperand__setModifierBits(createdInst0x12 + 0x2f,1,1);
      }
      else if (tokenModeField < 3) {
        if (tokenModeField == 1) {
          literalFloat = 0.5;
          goto code_r0x001021c0;
        }
      }
      else {
        if (tokenModeField == 3) {
          literalFloat = 0.5;
        }
        else {
          if (tokenModeField != 4) goto code_r0x00102220;
          literalFloat = 1.0;
        }
        literalValue = (double)literalFloat;
        ((void (*)())IRInst__makeLiteralVec4Float)(createdInst0x12,program,2,literalValue,literalValue,literalValue,literalValue);
      }
code_r0x00102220:
      ((int (*)())Program__appendInst)(program,createdInst0x12,currentBlock);
      operandRecordLast = IRInst__getOperandRecord(workInst,operandIndexC);
      *(int *)(operandRecordLast + 8) = savedRegisterIndex;
      *(undefined4 *)(operandRecordLast + 0xc) = 0;
      operandIndexC = (uint ******)((int)operandIndexC + 1);
      opcodeFallthrough = 0;
      templateCursor = (int *)((int)templateCursor + 1);
      break;
    case 0x23:
      opcodeTemplateTable = (uint ******)0x0;
      switch((uint)*tokenWords >> 0x10 & 7) {
      case 0:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8bc0;
        break;
      case 1:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b7c;
        break;
      case 2:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8ba4;
        break;
      case 3:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b90;
        break;
      case 4:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8bc4;
        break;
      case 5:
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (loopStackAlloc[2] != 0) {
        ifStackCount = (uint *****)ifStack[1];
        opcodeTemplateTable = (uint ******)PTR_DAT_001e8b78;
        if (ifStackCount != (uint *****)0x0) {
          ifStackTopSlot = (uint *****)0x0;
          if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
            ifStackTopSlot = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
          }
          if ((int)scopeLevel <= (int)(*ifStackTopSlot)[0x2e]) {
            loopTopIndex = loopStackAlloc[2] - 1;
            stackElement = (int *)0x0;
            if (loopTopIndex < (uint)loopStackAlloc[2]) {
              stackElement = (int *)(loopTopIndex * 4 + loopStackAlloc[3]);
            }
            scopeObject = *stackElement;
            arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
            continueTargetBlock = *(undefined4 *)(scopeObject + 0x150);
            blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x138);
            *blockAllocation4 = arenaA;
            continueBlock = (uint ******)(blockAllocation4 + 1);
            argR6 = *(uint *******)(program + 8);
            ContinueBlock__ctor_ec178(continueBlock,scopeObject,*(undefined4 *)(scopeObject + 300),argR6);
            blockAllocation4[0x2f] = scopeLevel;
            Program__insertBlockAfter(program,previousBlock,continueBlock);
            Block__connect(previousBlock,continueBlock);
            Block__connect(continueBlock,continueTargetBlock);
            opcodeFallthrough = 0;
            *(undefined4 *)(scopeObject + 0x13c) = 1;
            previousBlock = (uint *****)continueBlock;
            break;
          }
        }
        goto code_r0x00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      vectorElementSlot3 = (undefined4 *)0x0;
      scopeTopIndex = vectorAllocation[2] - 1;
      if (scopeTopIndex < (uint)vectorAllocation[2]) {
        vectorElementSlot3 = (undefined4 *)(scopeTopIndex * 4 + vectorAllocation[3]);
      }
      if (*(int *)*vectorElementSlot3 == 0) goto switchD_0010061c_caseD_1;
      opcodeScanCursor = (int *)((int)templateCursor * 4 + templateBase);
      do {
        cursorNext = templateCursor;
        if (*opcodeScanCursor == 0x37) {
          cursorNext = (int *)((int)templateCursor + 1);
          opcodeScanCursor = opcodeScanCursor + 1;
        }
        templateCursor = (int *)((int)cursorNext + 1);
        opcodeScanCursor = opcodeScanCursor + 1;
      } while (*opcodeScanCursor != 0x28);
      opcodeFallthrough = 0;
      templateCursor = cursorNext;
      break;
    case 0x27:
      ifStackTopSlot = (uint *****)0x0;
      ifStackTopIndex = (uint *****)((int)ifStack[1] - 1);
      if (ifStackTopIndex < ifStack[1]) {
        ifStackTopSlot = (uint *****)(ifStack[2] + (int)ifStackTopIndex);
      }
      scopeBlock = *ifStackTopSlot;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation4 = compilerArenaA;
      newBlock = (uint ******)(blockAllocation4 + 1);
      Block__ctor_ea020(newBlock,*(undefined4 *)(program + 8));
      blockAllocation4[0x2f] = scopeLevel;
      scopeBlock[0x4e] = (uint ***)newBlock;
      currentBlock = (uint *****)newBlock;
      Block__connect(scopeBlock,newBlock);
      Program__insertBlockAfter(program,previousBlock,currentBlock);
      goto code_r0x00103300;
    case 0x28:
      scopeDepth = vectorAllocation[2];
      stackElement = (int *)0x0;
      if (scopeDepth - 1 < scopeDepth) {
        stackElement = (int *)((scopeDepth - 1) * 4 + vectorAllocation[3]);
      }
      stackElement = (int *)*stackElement;
      Vector__removeAt(scopeVectorB,scopeDepth - 1);
joined_r0x00103afc:
      if (stackElement != (int *)0x0) {
        Arena__free(stackElement[-1],stackElement + -1);
        goto code_r0x00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      ifStackTopSlot = (uint *****)0x0;
      ifStackTopIndex = (uint *****)((int)ifStack[1] - 1);
      if (ifStackTopIndex < ifStack[1]) {
        ifStackTopSlot = (uint *****)(ifStack[2] + (int)ifStackTopIndex);
      }
      scopeBlock = *ifStackTopSlot;
      scopeEndBlock = scopeBlock[0x4f];
      scopeEndBlock[0x2e] = (uint **)scopeLevel;
      Program__insertBlockAfter(program,previousBlock,scopeEndBlock);
      chainLastBlock = (int *)Block__lastBlockOfChain_e7b9c(scopeBlock);
      chainLastBlock[0x2e] = (int)scopeLevel;
      scopeQueryResult = (**(code **)(*chainLastBlock + 0x38))();
      if ((scopeQueryResult == 0) && (scopeQueryResult = (**(code **)(*chainLastBlock + 0x3c))(chainLastBlock), scopeQueryResult == 0)) {
        Block__connect(chainLastBlock,scopeEndBlock);
      }
      chainLastBlockB = (uint ****)Block__lastBlockOfChain_e7a9c(scopeBlock);
      chainLastBlockB[0x2e] = (uint ***)scopeLevel;
      elseBlock = chainLastBlockB;
      if (chainLastBlockB == scopeBlock) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation4 = compilerArenaA;
        elseBlock = (uint ****)(blockAllocation4 + 1);
        Block__ctor_ea020(elseBlock,*(undefined4 *)(program + 8));
        blockAllocation4[0x2f] = scopeLevel;
        chainLastBlockB[0x4e] = (uint ***)elseBlock;
        Block__connect(chainLastBlockB,elseBlock);
        Program__insertBlockAfter(program,previousBlock,elseBlock);
      }
      scopeQueryResult = (*(code *)(*elseBlock)[0xe])(elseBlock);
      if ((scopeQueryResult == 0) && (scopeQueryResult = (*(code *)(*elseBlock)[0xf])(elseBlock), scopeQueryResult == 0)) {
        Block__connect(elseBlock,scopeEndBlock);
      }
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation4 = compilerArenaA;
      newBlock = (uint ******)(blockAllocation4 + 1);
      Block__ctor_ea020(newBlock,*(undefined4 *)(program + 8));
      blockAllocation4[0x2f] = scopeLevel;
      currentBlock = (uint *****)newBlock;
      Program__insertBlockAfter(program,scopeEndBlock,newBlock);
      Block__connect(scopeEndBlock,currentBlock);
      previousBlock = currentBlock;
      Vector__removeAt(ifStack,(int)ifStack[1] - 1);
      loopDepth = loopStackAlloc[2];
      if (loopDepth == 0) goto switchD_0010061c_caseD_1;
      stackElement = (int *)0x0;
      if (loopDepth - 1 < loopDepth) {
        stackElement = (int *)((loopDepth - 1) * 4 + loopStackAlloc[3]);
      }
      opcodeFallthrough = 0;
      *(int *)(*stackElement + 300) = *(int *)(*stackElement + 300) + -1;
      break;
    case 0x2a:
      scopeDepth = vectorAllocation2[2];
      if (scopeDepth != 0) {
        vectorElementSlot3 = (undefined4 *)0x0;
        if (scopeDepth - 1 < scopeDepth) {
          vectorElementSlot3 = (undefined4 *)((scopeDepth - 1) * 4 + vectorAllocation2[3]);
        }
        stackElement = (int *)*vectorElementSlot3;
        Vector__removeAt(scopeVector,scopeDepth - 1);
        if ((uint ******)stackElement[2] != (uint ******)0x0) {
          currentBlock = (uint *****)stackElement[2];
        }
        templateCursor = (int *)stackElement[1];
        templateBase = *stackElement;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      opcodeTableBase = 0x1dd5d8;
      if ((UNK_001dc660 == 0) || (ilOpcode == UNK_001dc660)) {
code_r0x00101020:
        opcodeTableOffset = 0;
      }
      else {
        opcodeTableEntry = &UNK_001dc66c;
        opcodeTableOffset = 0;
        do {
          tableOpcode = *opcodeTableEntry;
          opcodeTableOffset = opcodeTableOffset + 1;
          if (tableOpcode == 0) goto code_r0x00101020;
          opcodeTableEntry = opcodeTableEntry + 3;
        } while (ilOpcode != tableOpcode);
      }
      opcodeTableOffset = opcodeTableOffset * 0xc;
      sampleFlags = *(uint *)(opcodeTableOffset + 0x1dc664);
      if ((sampleFlags & 0x80) == 0) {
        resourceId = (uint)*(byte *)((int)ilReader + 0x8d);
        samplerIndex = resourceId;
      }
      else {
        resourceId = (uint)*tokenWords >> 0x18 & 0x1f;
        samplerIndex = (uint)*(byte *)((int)ilReader + 0x8d);
      }
      if (*(int *)(program + 0x7c) < (int)samplerIndex) {
        *(uint *)(program + 0x7c) = samplerIndex;
      }
      *(uint *)(program + 0x84) = 1 << (samplerIndex & 0x3f) | *(uint *)(program + 0x84);
      fetchDescriptor = (undefined2 *)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(fetchDescriptor,0,0x24);
      fetchDescriptor[6] = 3;
      fetchDescriptor[4] = 7;
      fetchDescriptor[9] = 1;
      fetchDescriptor[10] = 0;
      *(uint *)(fetchDescriptor + 0x10) = resourceId;
      *fetchDescriptor = 3;
      fetchDescriptor[1] = 3;
      fetchDescriptor[2] = 3;
      fetchDescriptor[3] = 7;
      fetchDescriptor[5] = 3;
      fetchDescriptor[7] = 1;
      fetchDescriptor[8] = 0;
      fetchDescriptor[0xb] = 0;
      fetchDescriptor[0xc] = 0;
      fetchDescriptor[0xd] = 0;
      fetchDescriptor[0xe] = 0;
      if ((int)*tokenWords < 0) {
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] & 7);
        *fetchDescriptor = componentSelect;
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 3 & 7);
        fetchDescriptor[1] = componentSelect;
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 0xc & 7);
        fetchDescriptor[2] = componentSelect;
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 6 & 7);
        fetchDescriptor[5] = componentSelect;
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 9 & 7);
        fetchDescriptor[6] = componentSelect;
        componentSelect = ((int (*)())remapSelectSmall)((uint)ilReader[0x25] >> 0xf & 7);
        fetchDescriptor[3] = componentSelect;
        fetchDescriptor[0xb] = (ushort)((uint)ilReader[0x25] >> 0x12) & 0x7f;
        if ((sampleFlags & 4) != 0) {
          fetchDescriptor[8] = ((ushort)((uint)ilReader[0x25] >> 0x19) & 1) + 1;
        }
      }
      if (ilReader[0x18] != (uint *****)0x0) {
        modifierTokenWord = ilReader[0x24];
        fetchDescriptor[0xc] = (ushort)modifierTokenWord & 0xff;
        fetchDescriptor[0xd] = (ushort)((uint)modifierTokenWord >> 8) & 0xff;
        fetchDescriptor[0xe] = (ushort)((uint)modifierTokenWord >> 0x10) & 0xff;
      }
      hasFirstExtraOperand = (sampleFlags & 1) != 0;
      fetchFlagBit = (uint)*tokenWords >> 0x18 & 1;
      fetchDescriptor[9] = (ushort)fetchFlagBit ^ 1;
      tokenBit25Clear = ((uint)*tokenWords >> 0x19 & 1) == 0;
      fetchDescriptor[7] = (ushort)tokenBit25Clear;
      if (hasFirstExtraOperand) {
        fetchDescriptor[8] = (ushort)(ilOpcode != 0x5f);
      }
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      fetchResultTemp = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,virtualRegister);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())Template__bindOperand)(program,5,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      if (hasFirstExtraOperand) {
        cubeCoordTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        extraOperandTemp1 = VRegPool__findOrCreate(cubeCoordTemp,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,extraOperandTemp1);
        ((int (*)())Template__bindOperand)(program,10,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      }
      else {
        extraOperandTemp1 = 0;
      }
      hasGradients = (sampleFlags >> 3 & 1) != 0;
      if (hasGradients) {
        cubeCoordTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        extraOperandTemp2 = VRegPool__findOrCreate(cubeCoordTemp,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,extraOperandTemp2);
        ((int (*)())Template__bindOperand)(program,0xe,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      }
      else {
        extraOperandTemp2 = 0;
      }
      if ((sampleFlags & 0x40) != 0) {
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,virtualRegister);
        IRInst__setOperandRef(movFloatInst,1,extraOperandTemp1);
        operandRecord2 = IRInst__getOperandRecord(movFloatInst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = 0;
        *(undefined4 *)((int)movFloatInst + 0x9c) = 0x1010100;
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      }
      registerRecordOffset = samplerIndex * 0xc;
      declaredKind = *(int *)(*(int *)(program + 0x78) + registerRecordOffset + 4);
      if ((declaredKind == 4) || (cubeCoordTemp = virtualRegister, declaredKind == 0xb)) {
        cubeCoordTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        cubeCoordTemp = VRegPool__findOrCreate(cubeCoordTemp,0,newTempIndex2,0);
        cubeInst = IRInst__create(0x1b,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(cubeInst,0,cubeCoordTemp);
        IRInst__setOperandRef(cubeInst,1,virtualRegister);
        stagedSelectWord = (uint ******)0x2020001;
        operandRecord2 = IRInst__getOperandRecord(cubeInst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = 0x2020001;
        IRInst__setOperandRef(cubeInst,2,virtualRegister);
        stagedSelectWord = (uint ******)0x1000202;
        operandRecord2 = IRInst__getOperandRecord(cubeInst,2);
        *(undefined4 *)(operandRecord2 + 0x10) = 0x1000202;
        ((int (*)())Program__appendInst)(program,cubeInst,currentBlock);
        recipIEEEInst = IRInst__create(0x40,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(recipIEEEInst,0,cubeCoordTemp);
        *(undefined4 *)((int)recipIEEEInst + 0x9c) = 0x1010001;
        IRInst__setOperandRef(recipIEEEInst,1,cubeCoordTemp);
        IROperand__setModifierBits((int)recipIEEEInst + 0xa4,2,1);
        operandRecord2 = IRInst__getOperandRecord(recipIEEEInst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = 0x2020202;
        ((int (*)())Program__appendInst)(program,recipIEEEInst,currentBlock);
        mulAddFloatInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(mulAddFloatInst,0,cubeCoordTemp);
        *(undefined1 *)((int)mulAddFloatInst + 0x9c) = 0;
        *(undefined1 *)((int)mulAddFloatInst + 0x9d) = 0;
        *(undefined1 *)((int)mulAddFloatInst + 0x9e) = 1;
        *(undefined1 *)((int)mulAddFloatInst + 0x9f) = 1;
        IRInst__setOperandRef(mulAddFloatInst,1,cubeCoordTemp);
        IRInst__setOperandRef(mulAddFloatInst,2,cubeCoordTemp);
        operandRecord2 = IRInst__getOperandRecord(mulAddFloatInst,2);
        *(undefined4 *)(operandRecord2 + 0x10) = 0x2020202;
        ((void (*)())IRInst__makeLiteralVec4Float)(mulAddFloatInst,program,3,1.5,1.5,1.5,1.5);
        ((int (*)())Program__appendInst)(program,mulAddFloatInst,currentBlock);
        movInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movInst,0,cubeCoordTemp);
        IRInst__setOperandRef(movInst,1,cubeCoordTemp);
        (**(code **)(*movInst + 0x88))(movInst,1,0,1);
        (**(code **)(*movInst + 0x88))(movInst,1,1,0);
        (**(code **)(*movInst + 0x88))(movInst,1,2,3);
        (**(code **)(*movInst + 0x88))(movInst,1,3,0);
        ((int (*)())Program__appendInst)(program,movInst,currentBlock);
        if (ilOpcode == 0x8b) {
          movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(movFloatInst,0,cubeCoordTemp);
          *(undefined1 *)((int)movFloatInst + 0x9e) = 1;
          *(undefined1 *)((int)movFloatInst + 0x9f) = 0;
          *(undefined1 *)((int)movFloatInst + 0x9c) = 1;
          *(undefined1 *)((int)movFloatInst + 0x9d) = 1;
          IRInst__setOperandRef(movFloatInst,1,virtualRegister);
          ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
        }
        hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
        (**(code **)(*hwDescription + 0x5c))(hwDescription,samplerIndex);
      }
      if (hasGradients) {
        setGradientsVInst = IRInst__create(0x73,*(undefined4 *)(program + 8));
        setGradientsHInst = IRInst__create(0x72,*(undefined4 *)(program + 8));
        virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x1e,0,0);
        IRInst__setOperandRef(setGradientsVInst,0,virtualRegister);
        IRInst__setOperandRef(setGradientsVInst,1,extraOperandTemp1);
        IRInst__setOperandRef(setGradientsHInst,0,virtualRegister);
        IRInst__setOperandRef(setGradientsHInst,1,extraOperandTemp2);
        (**(code **)(*setGradientsHInst + 0x90))(setGradientsHInst,virtualRegister);
        ((int (*)())Program__appendInst)(program,setGradientsVInst,currentBlock);
        ((int (*)())Program__appendInst)(program,setGradientsHInst,currentBlock);
      }
      else {
        virtualRegister = 0;
      }
      fetchCoordTemp = cubeCoordTemp;
      if (hasFirstExtraOperand) {
        sampleFlag4Clear = (sampleFlags >> 2 & 1) == 0;
        if (!sampleFlag4Clear) {
          fetchCoordTemp = *(undefined4 *)(program + 0x3ac);
          newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
          fetchCoordTemp = VRegPool__findOrCreate(fetchCoordTemp,0,newTempIndex2,0);
          movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(movFloatInst,0,fetchCoordTemp);
          *(undefined4 *)((int)movFloatInst + 0x9c) = 1;
          IRInst__setOperandRef(movFloatInst,1,cubeCoordTemp);
          ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
          movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(movFloatInst,0,fetchCoordTemp);
          *(undefined4 *)((int)movFloatInst + 0x9c) = 0x1010100;
          IRInst__setOperandRef(movFloatInst,1,extraOperandTemp1);
          ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
        }
      }
      else {
        sampleFlag4Clear = (sampleFlags >> 2 & 1) == 0;
      }
      fetchOpcodeCode = *(int *)(opcodeTableOffset + opcodeTableBase + -0xf70);
      if ((sampleFlag4Clear) || (tokenBit25Clear)) {
        if ((fetchOpcodeCode != 0xff) || (*(int *)(registerRecordOffset + *(int *)(program + 0x78) + 4) != 7))
        goto code_r0x001019bc;
        ldBufferInst = IRInst__create(0x104,*(undefined4 *)(program + 8));
        *(uint *)((int)ldBufferInst + 0x130) = samplerIndex;
        *(undefined4 *)((int)ldBufferInst + 0x140) = *(undefined4 *)(constantsBase + -0x2c30);
        IRInst__setOperandRef(ldBufferInst,0,fetchResultTemp);
        IRInst__setOperandRef(ldBufferInst,1,fetchCoordTemp);
        ((int (*)())Program__appendInst)(program,ldBufferInst,currentBlock);
      }
      else {
        fetchOpcodeCode = 0xae;
code_r0x001019bc:
        fetchInst = IRInst__create(fetchOpcodeCode,*(undefined4 *)(program + 8));
        fetchInst[0x4f] = (int)fetchDescriptor;
        fetchInst[0x4d] = samplerIndex;
        IRInst__setOperandRef(fetchInst,0,fetchResultTemp);
        IRInst__setOperandRef(fetchInst,1,fetchCoordTemp);
        if (hasGradients) {
          (**(code **)(*fetchInst + 0x90))(fetchInst,virtualRegister);
        }
        declRecordTable = *(int *)(program + 0x78);
        if (*(int *)(registerRecordOffset + declRecordTable + 4) == 8) {
          (**(code **)(*fetchInst + 0x88))(fetchInst,1,2,1);
          roundNearestEvenInst = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          fetchInstWordB = fetchInst[0x2b];
          fetchInstWordD = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,0);
          *(int *)(operandRecord2 + 0xc) = fetchInstWordD;
          *(int *)(operandRecord2 + 8) = fetchInstWordB;
          fetchInstWordB = fetchInst[0x2b];
          fetchInstWordD = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(int *)(operandRecord2 + 0xc) = fetchInstWordD;
          *(int *)(operandRecord2 + 8) = fetchInstWordB;
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = 0x1010101;
          *(undefined4 *)((int)roundNearestEvenInst + 0x9c) = 0x1000101;
          ((int (*)())Program__appendInst)(program,roundNearestEvenInst,currentBlock);
          declRecordTable = *(int *)(program + 0x78);
        }
        if (*(int *)(registerRecordOffset + declRecordTable + 4) == 9) {
          roundNearestEvenInst = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          fetchInstWordB = fetchInst[0x2b];
          fetchInstWordD = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,0);
          *(int *)(operandRecord2 + 0xc) = fetchInstWordD;
          *(int *)(operandRecord2 + 8) = fetchInstWordB;
          fetchInstWordB = fetchInst[0x2b];
          fetchInstWordD = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(int *)(operandRecord2 + 0xc) = fetchInstWordD;
          *(int *)(operandRecord2 + 8) = fetchInstWordB;
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = 0x2020202;
          *(undefined4 *)((int)roundNearestEvenInst + 0x9c) = 0x1010001;
          ((int (*)())Program__appendInst)(program,roundNearestEvenInst,currentBlock);
          declRecordTable = *(int *)(program + 0x78);
        }
        declRecordTable = ((int (*)())remapSelect1To0)(*(undefined4 *)(registerRecordOffset + declRecordTable));
        fetchInst[0x4e] = declRecordTable;
        *(short *)(fetchInst[0x4f] + 0x12) = (short)fetchFlagBit;
        ((int (*)())Program__appendInst)(program,fetchInst,currentBlock);
        if (*(int *)(registerRecordOffset + *(int *)(program + 0x78) + 8) != 0) {
          mulFloatInst = IRInst__create(0x13,*(undefined4 *)(program + 8));
          registerRecordOffset = fetchInst[0x25];
          fetchInstWordC = fetchInst[0x26];
          operandRecord2 = IRInst__getOperandRecord(mulFloatInst,0);
          *(int *)(operandRecord2 + 0xc) = fetchInstWordC;
          *(int *)(operandRecord2 + 8) = registerRecordOffset;
          registerRecordOffset = fetchInst[0x26];
          fetchInstWordB = fetchInst[0x25];
          operandRecord2 = IRInst__getOperandRecord(mulFloatInst,1);
          literalValue2 = (uint)(short)samplerIndex;
          *(int *)(operandRecord2 + 0xc) = registerRecordOffset;
          literalValue0 = literalValue2 | 0x130000;
          literalValue1 = literalValue2 | 0x130000;
          literalValue3 = literalValue2 | 0x130000;
          literalValue2 = literalValue2 | 0x130000;
          *(int *)(operandRecord2 + 8) = fetchInstWordB;
          ((int (*)())IRInst__makeLiteralVec4Int)(mulFloatInst,program,2,literalValue0,literalValue1,literalValue2,literalValue3);
          ((int (*)())Program__appendInst)(program,mulFloatInst,currentBlock);
        }
      }
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
      workInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = workInst;
      ((int (*)())Template__bindOperand)(program,0,0,ilReader,workInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(workInst,1,fetchResultTemp);
      goto code_r0x00101cbc;
    case 0x2d:
    case 0x2e:
      samplerIndex2 = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      fetchStateBlock = (uint *****)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(fetchStateBlock,0,0x24);
      *(undefined2 *)((int)fetchStateBlock + 0x12) = 1;
      *(undefined2 *)((int)fetchStateBlock + 0xe) = 1;
      *(undefined2 *)(fetchStateBlock + 5) = 0;
      *(undefined2 *)(fetchStateBlock + 4) = 0;
      *(undefined2 *)((int)fetchStateBlock + 0x16) = 0;
      *(undefined2 *)(fetchStateBlock + 6) = 0;
      *(undefined2 *)((int)fetchStateBlock + 0x1a) = 0;
      *(undefined2 *)(fetchStateBlock + 7) = 0;
      *(undefined2 *)(fetchStateBlock + 2) = 7;
      *(undefined2 *)(fetchStateBlock + 3) = 3;
      *(undefined2 *)fetchStateBlock = 3;
      *(undefined2 *)((int)fetchStateBlock + 2) = 3;
      *(undefined2 *)(fetchStateBlock + 1) = 3;
      *(undefined2 *)((int)fetchStateBlock + 6) = 7;
      *(undefined2 *)((int)fetchStateBlock + 10) = 3;
      *(ushort *)((int)fetchStateBlock + 0x12) =
           (ushort)(((uint)(byte)((((uint)*tokenWords & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      tokenBit25Clear2 = ((uint)*tokenWords >> 0x19 & 1) == 0;
      *(ushort *)((int)fetchStateBlock + 0xe) = (ushort)tokenBit25Clear2;
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      templateModeWord = (uint *****)0x1;
      savedStagedSelect = *(uint ******)(constantsBase + -0x2c30);
      stagedSelectWord = (uint ******)savedStagedSelect;
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,virtualRegister);
      *(undefined4 *)((int)movFloatInst + 0x9c) = 1;
      selectWordPtr = &stagedSelectWord;
      ((int (*)())Template__bindOperand)(program,5,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      templateModeWord = (uint *****)0x1010100;
      stagedSelectWord = (uint ******)savedStagedSelect;
      workInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(workInst,0,virtualRegister);
      workInst[0x27] = (uint *****)0x1010100;
      ((int (*)())Template__bindOperand)(program,10,1,ilReader,workInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,workInst,currentBlock);
      if (tokenBit25Clear2) {
        fetchIrOpcode = 0x76;
      }
      else {
        fetchIrOpcode = 0xae;
        if (templateToken == 0x2d) {
          Compiler__fail(*(undefined4 *)(program + 8),0xf);
          fetchIrOpcode = 0xae;
        }
      }
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
      selectWord2 = *(uint *******)(constantsBase + -0x2c30);
      stagedSelectWord = selectWord2;
      fetchInst2 = IRInst__create(fetchIrOpcode,*(undefined4 *)(program + 8));
      fetchInst2[0x4f] = fetchStateBlock;
      fetchInst2[0x4d] = samplerIndex2;
      if (*(int *)(program + 0x7c) < (int)samplerIndex2) {
        *(uint ******)(program + 0x7c) = samplerIndex2;
      }
      *(uint *)(program + 0x84) = 1 << ((uint)samplerIndex2 & 0x3f) | *(uint *)(program + 0x84);
      fetchStateRef = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)(*(int *)(program + 0x78) + (int)samplerIndex2 * 0xc))
      ;
      fetchInst2[0x4c] = samplerIndex2;
      fetchInst2[0x4e] = fetchStateRef;
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = fetchInst2;
      builtInst = ((int (*)())Template__bindOperand)(program,4,0,ilReader,fetchInst2,1,templateModeWord,selectWordPtr,loopStackData,1,
                            currentBlock);
      if (builtInst != 0) {
        DList__pushFront(pendingListA,builtInst);
      }
      IRInst__setOperandRef(fetchInst2,1,virtualRegister);
      operandRecord2 = IRInst__getOperandRecord(fetchInst2,1);
      *(uint *******)(operandRecord2 + 0x10) = selectWord2;
      fetchStateRef = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)samplerIndex2 * 0xc + *(int *)(program + 0x78)))
      ;
      fetchInst2[0x4e] = fetchStateRef;
      ((int (*)())Program__appendInst)(program,fetchInst2,currentBlock);
      goto code_r0x00101d1c;
    case 0x2f:
      ilRegisterIndex2 = (uint)*(byte *)((int)ilReader + 0x8d);
      fetchDescriptor2 = (undefined2 *)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(fetchDescriptor2,0,0x24);
      fetchDescriptor2[9] = 1;
      fetchDescriptor2[6] = 3;
      fetchDescriptor2[7] = 1;
      *fetchDescriptor2 = 3;
      fetchDescriptor2[1] = 3;
      fetchDescriptor2[2] = 3;
      fetchDescriptor2[5] = 3;
      fetchDescriptor2[4] = 7;
      fetchDescriptor2[10] = 0;
      fetchDescriptor2[3] = 7;
      fetchDescriptor2[8] = 0;
      fetchDescriptor2[0xb] = 0;
      fetchDescriptor2[0xc] = 0;
      fetchDescriptor2[0xd] = 0;
      fetchDescriptor2[0xe] = 0;
      saturateBit = (byte)((uint)*tokenWords >> 0x18) & 1;
      fetchDescriptor2[9] = saturateBit ^ 1;
      fetchDescriptor2[7] = (ushort)(((uint)(byte)((((uint)*tokenWords & 0x2000000) == 0) << 1) << 0x1c) >>
                           0x1d);
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      fetchResultTemp2 = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      coordTemp = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,coordTemp);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())Template__bindOperand)(program,5,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      virtualRegister = 0;
      if (ilOpcode == 0x5f) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,virtualRegister);
        ((int (*)())Template__bindOperand)(program,10,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
        gradientYTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        gradientYTemp = VRegPool__findOrCreate(gradientYTemp,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,gradientYTemp);
        ((int (*)())Template__bindOperand)(program,0xe,1,ilReader,movFloatInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      }
      else {
        gradientYTemp = 0;
      }
      fetchTextureMapGradientsInst = IRInst__create(0x78,*(undefined4 *)(program + 8));
      *(undefined2 **)((int)fetchTextureMapGradientsInst + 0x13c) = fetchDescriptor2;
      IRInst__setOperandRef(fetchTextureMapGradientsInst,0,fetchResultTemp2);
      IRInst__setOperandRef(fetchTextureMapGradientsInst,1,coordTemp);
      if (ilOpcode == 0x5f) {
        IRInst__setOperandRef(fetchTextureMapGradientsInst,2,virtualRegister);
        IRInst__setOperandRef(fetchTextureMapGradientsInst,3,gradientYTemp);
      }
      *(uint *)((int)fetchTextureMapGradientsInst + 0x134) = ilRegisterIndex2;
      if (*(int *)(program + 0x7c) < (int)ilRegisterIndex2) {
        *(uint *)(program + 0x7c) = ilRegisterIndex2;
      }
      *(uint *)(program + 0x84) = 1 << (ilRegisterIndex2 & 0x3f) | *(uint *)(program + 0x84);
      remappedSelect = ((int (*)())remapSelect1To0)(*(undefined4 *)(ilRegisterIndex2 * 0xc + *(int *)(program + 0x78)));
      *(undefined4 *)((int)fetchTextureMapGradientsInst + 0x138) = remappedSelect;
      *(uint *)((int)fetchTextureMapGradientsInst + 0x130) = ilRegisterIndex2;
      *(ushort *)(*(int *)((int)fetchTextureMapGradientsInst + 0x13c) + 0x12) = saturateBit;
      ((int (*)())Program__appendInst)(program,fetchTextureMapGradientsInst,currentBlock);
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
      workInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = workInst;
      ((int (*)())Template__bindOperand)(program,0,0,ilReader,workInst,1,templateModeWord,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(workInst,1,fetchResultTemp2);
code_r0x00101cbc:
      ((int (*)())Program__appendInst)(program,workInst,currentBlock);
      goto code_r0x00101d1c;
    case 0x30:
      literalAddr = templateBase + (int)templateCursor * 4;
      ((void (*)())IRInst__makeLiteralVec4Float)(workInst,program,operandIndexC,(double)*(float *)(literalAddr + 4),
                   (double)*(float *)(literalAddr + 8),(double)*(float *)(literalAddr + 0xc),
                   (double)*(float *)(literalAddr + 0x10));
      operandRecord2 = IRInst__getOperandRecord(workInst,operandIndexC);
      SelectWord__compose(&composedSelectOut,*(undefined4 *)(operandRecord2 + 0x10),stagedSelectWord);
      selectWord = composedSelectOut;
      operandRecord2 = IRInst__getOperandRecord(workInst,operandIndexC);
      *(undefined4 *)(operandRecord2 + 0x10) = selectWord;
      operandIndexC = (uint ******)((int)operandIndexC + 1);
      opcodeFallthrough = 0;
      templateCursor = templateCursor + 1;
      break;
    case 0x31:
      compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      listAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x10);
      *listAllocation = compilerArenaB;
      listHeader = listAllocation + 1;
      templateCursor = (int *)((int)templateCursor + 1);
      switch(*(undefined4 *)(templateBase + (int)templateCursor * 4)) {
      case 0x3f:
        *listHeader = (uint)*tokenWords >> 0x12 & 1;
        break;
      default:
        *listHeader = 0;
        break;
      case 0x5f:
        *listHeader = (uint)*tokenWords >> 0x18 & 1;
        break;
      case 0x67:
        *listHeader = 1;
      }
      scopeDepth = vectorAllocation[2];
      if (scopeDepth < *scopeVectorB) {
        _memset(scopeDepth * 4 + vectorAllocation[3],0,4);
        vectorAllocation[2] = scopeDepth + 1;
        vectorElementSlot3 = (undefined4 *)(scopeDepth * 4 + vectorAllocation[3]);
      }
      else {
        vectorElementSlot3 = (undefined4 *)Vector__elementRefGrow(scopeVectorB,scopeDepth);
      }
      opcodeFallthrough = 0;
      *vectorElementSlot3 = listHeader;
      break;
    case 0x32:
      ifConditionRef = (uint ******)0x0;
      ifStackCount = (uint *****)ifStack[1];
      if (ifStackCount != (uint *****)0x0) {
        ifStackTopSlot = (uint *****)0x0;
        if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
          ifStackTopSlot = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
        }
        ifConditionRef = (uint ******)*ifStackTopSlot;
        ifConditionRef[0x51] = (uint *****)0x0;
      }
      templateCursor = (int *)((int)templateCursor + 1);
      switch(*(undefined4 *)(templateBase + (int)templateCursor * 4)) {
      case 0x62:
        pvVar16 = IRInst__create(0x8b,*(undefined4 *)(program + 8));
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,1,1.0,1.0,1.0,1.0);
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,2,1.0,1.0,1.0,1.0);
        *(undefined4 *)((int)pvVar16 + 300) = 0;
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        ifBlock = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(ifBlock,pvVar16,ifConditionRef,0,argR7);
        break;
      case 99:
        compiler = *(int *)(program + 8);
        source0Token = **ilReader[0x1b];
        if (((((uint)source0Token & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((*(uint *)(*(int *)(compiler + 0x30c) + 8) & 0x80) != 0)) {
          sourceRegisterIndexB = 0xf;
        }
        else {
          sourceRegisterIndexB = (int)*(short *)((int)*ilReader[0x1b] + 2);
        }
        cmp1SInst = IRInst__create(0x8d,compiler);
        registerFile = Program__registerFileOfIlType(program,(uint)source0Token >> 0x10 & 0x3f);
        operandRecord2 = IRInst__getOperandRecord(cmp1SInst,1);
        *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
        remapTable = PTR_DAT_001e8b84;
        *(int *)(operandRecord2 + 8) = sourceRegisterIndexB;
        *(undefined4 *)((int)cmp1SInst + 300) = *(undefined4 *)remapTable;
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        ifBlock = (uint *****)(blockAllocation4 + 1);
        argR6 = *(uint *******)(program + 8);
        IfHeaderStatic__ctor_ebac8(ifBlock,cmp1SInst,ifConditionRef,argR6);
        Block__setField0xb8AndChildren(ifBlock,scopeLevel);
        IRInst__bindOperandRegisters(program,cmp1SInst);
        ifStackNewSlot = (uint *****)0x0;
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          blockAllocation4[0x53] = 0;
          ifStackNewSlot = (uint *****)ifStack[1];
        }
        if (ifStackNewSlot < *ifStack) {
          _memset(ifStack[2] + (int)ifStackNewSlot,0,4);
          ifStack[1] = (uint ****)((int)ifStackNewSlot + 1);
          ifStackNewSlot = (uint *****)(ifStack[2] + (int)ifStackNewSlot);
        }
        else {
          ifStackNewSlot = (uint *****)Vector__elementRefGrow(ifStack,ifStackNewSlot);
        }
        *ifStackNewSlot = (uint ****)ifBlock;
        loopDepth = loopStackAlloc[2];
        if (loopDepth == 0) goto code_r0x00103240;
        goto code_r0x00103214;
      case 100:
        sourceToken0Ptr = *ilReader[0x1b];
        sourceToken0Word = *sourceToken0Ptr;
        compiler = *(int *)(program + 8);
        if ((((uint)sourceToken0Word & 0x3f0000) == 0x100000) && (compiler != 0)) {
          hwDescription = *(int **)(compiler + 0x30c);
          if ((hwDescription[2] & 0x80U) == 0) goto code_r0x00100810;
          sourceRegisterIndexB = 0xf;
        }
        else {
          hwDescription = *(int **)(compiler + 0x30c);
code_r0x00100810:
          sourceRegisterIndexB = (int)*(short *)((int)sourceToken0Ptr + 2);
        }
        sourceToken1Ptr = ilReader[0x1b][1];
        sourceToken1Word = *sourceToken1Ptr;
        if (((((uint)sourceToken1Word & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((hwDescription[2] & 0x80U) != 0)) {
          registerIndex = 0xf;
        }
        else {
          registerIndex = (int)*(short *)((int)sourceToken1Ptr + 2);
        }
        argR8 = (uint ******)((uint)sourceToken1Word >> 0x10 & 0x3f);
        pvVar16 = (void *)(**(code **)(*hwDescription + 0x24))
                                    (hwDescription,(uint)*tokenWords >> 0x10 & 7,sourceRegisterIndexB,
                                     (uint)sourceToken0Word >> 0x10 & 0x3f,registerIndex,argR8,stagedSelectWord,ilReader);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        ifBlock = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(ifBlock,pvVar16,ifConditionRef,0,argR7);
        break;
      case 0x65:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        ifCondInstAlloc = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *ifCondInstAlloc = compilerArenaA;
        ifCondInstAlloc = ifCondInstAlloc + 1;
        IRInst__ctor_10502c(ifCondInstAlloc,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 6;
        goto code_r0x00102c90;
      case 0x66:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        ifCondInstAlloc = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *ifCondInstAlloc = compilerArenaA;
        ifCondInstAlloc = ifCondInstAlloc + 1;
        IRInst__ctor_10502c(ifCondInstAlloc,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 7;
code_r0x00102c90:
        ifCondInstAlloc[0x4b] = comparisonKind;
        argR7 = (uint ******)ifStack;
        argR8 = loopStackData;
        ifBlock = (uint *****)
                      ((int (*)())Program__createIfBlock)(program,ifCondInstAlloc,scopeLevel,ifConditionRef,ifStack,loopStackData,
                                   ilReader);
        argR6 = ifConditionRef;
        goto code_r0x00103240;
      default:
        ifBlock = (uint *****)0x0;
        goto code_r0x00103240;
      case 0x6f:
        conditionStackTopIndex = conditionStack[1] - 1;
        vectorElementSlot3 = (undefined4 *)0x0;
        if (conditionStackTopIndex < conditionStack[1]) {
          vectorElementSlot3 = (undefined4 *)(conditionStackTopIndex * 4 + conditionStack[2]);
        }
        hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
        argR8 = stagedSelectWord;
        ifConditionInst = (**(code **)(*hwDescription + 0x28))
                           (hwDescription,1,*(undefined4 *)*vectorElementSlot3,4,ilReader[(int)ilReader[0x16] + 0x23],
                            stagedSelectWord,ilReader,currentBlock);
        arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x15c);
        *blockAllocation4 = arenaA;
        ifBlock = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(ifBlock,ifConditionInst,ifConditionRef,0,argR7);
        conditionStackTopIndex = conditionStack[1] - 1;
        if (conditionStackTopIndex < conditionStack[1]) {
          stackElement = (int *)(conditionStackTopIndex * 4 + conditionStack[2]);
        }
        else {
          stackElement = (int *)0x0;
        }
        scopeObject = *stackElement;
        FUN_000e77f4(ifBlock,*(undefined4 *)(scopeObject + 8));
        *(uint ******)(scopeObject + 8) = ifBlock;
        Block__setField0xb8AndChildren(ifBlock,scopeLevel);
        IRInst__bindOperandRegisters(program,ifConditionInst);
        goto code_r0x0010319c;
      case 0x72:
        compiler = *(int *)(program + 8);
        source0Token = **ilReader[0x1b];
        if ((((uint)source0Token & 0x3f0000) == 0x100000) && (compiler != 0)) {
          hwDescription = *(int **)(compiler + 0x30c);
          if ((hwDescription[2] & 0x80U) == 0) goto code_r0x0010082c;
          registerIndex = 0xf;
        }
        else {
          hwDescription = *(int **)(compiler + 0x30c);
code_r0x0010082c:
          registerIndex = (int)*(short *)((int)*ilReader[0x1b] + 2);
        }
        argR8 = stagedSelectWord;
        pvVar16 = (void *)(**(code **)(*hwDescription + 0x28))
                                    (hwDescription,ilOpcode == 0x6f,registerIndex,(uint)source0Token >> 0x10 & 0x3f,0,
                                     stagedSelectWord,ilReader,currentBlock);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        ifBlock = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(ifBlock,pvVar16,ifConditionRef,0,argR7);
      }
      Block__setField0xb8AndChildren(ifBlock,scopeLevel);
      IRInst__bindOperandRegisters(program,pvVar16);
code_r0x0010319c:
      ifStackNewSlot = (uint *****)0x0;
      if ((uint *****)ifStack[1] != (uint *****)0x0) {
        ifBlock[0x52] = (uint ****)0x0;
        ifStackNewSlot = (uint *****)ifStack[1];
      }
      if (ifStackNewSlot < *ifStack) {
        _memset(ifStack[2] + (int)ifStackNewSlot,0,4);
        ifStack[1] = (uint ****)((int)ifStackNewSlot + 1);
        ifStackNewSlot = (uint *****)(ifStack[2] + (int)ifStackNewSlot);
      }
      else {
        ifStackNewSlot = (uint *****)Vector__elementRefGrow(ifStack,ifStackNewSlot);
      }
      *ifStackNewSlot = (uint ****)ifBlock;
      loopDepth = loopStackAlloc[2];
      if (loopDepth != 0) {
code_r0x00103214:
        stackElement = (int *)0x0;
        if (loopDepth - 1 < loopDepth) {
          stackElement = (int *)((loopDepth - 1) * 4 + loopStackAlloc[3]);
        }
        *(int *)(*stackElement + 300) = *(int *)(*stackElement + 300) + 1;
      }
code_r0x00103240:
      Program__insertBlockAfter(program,previousBlock,ifBlock);
      Block__connect(previousBlock,ifBlock);
      currentBlock = (uint *****)ifBlock[0x4d];
      previousBlock = ifBlock;
      Program__insertBlockAfter(program,ifBlock,currentBlock);
code_r0x00103300:
      opcodeFallthrough = 0;
      previousBlock = currentBlock;
      break;
    case 0x34:
      operandRecord2 = IRInst__getOperandRecord(workInst,operandIndexC);
      opcodeFallthrough = 0;
      operandIndexC = (uint ******)((int)operandIndexC + 1);
      *(undefined4 *)(operandRecord2 + 8) = 0;
      *(undefined4 *)(operandRecord2 + 0xc) = 0x21;
      break;
    case 0x35:
      stackElement = (int *)0x0;
      loopTopIndex = loopStackAlloc[2] - 1;
      if (loopTopIndex < (uint)loopStackAlloc[2]) {
        stackElement = (int *)(loopTopIndex * 4 + loopStackAlloc[3]);
      }
      scopeObjectB = *stackElement;
      optionResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),3);
      if ((optionResult == 0) || (optionResult = Program__isTrivialBranchRegion(program,scopeObjectB), optionResult == 0)) {
        argR6 = &previousBlock;
        argR7 = &currentBlock;
        argR8 = (uint ******)&scopeLevel;
        transformFailed = Program__unrollLoop(program,loopStackData,scopeObjectB,argR6,argR7,argR8);
        if (transformFailed != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x4c) < (int)scopeLevel) {
          Compiler__fail(*(int *)(program + 8),8);
        }
        continueTargetBlockB = *(int *)(scopeObjectB + 0x150);
        Program__insertBlockAfter(program,previousBlock,continueTargetBlockB);
        scopeQueryResult = (*(code *)(*previousBlock)[0xe])();
        if ((scopeQueryResult == 0) && (scopeQueryResult = (*(code *)(*previousBlock)[0xf])(), scopeQueryResult == 0)) {
          Block__connect(previousBlock,continueTargetBlockB);
        }
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation4 = compilerArenaA;
        blockObject = blockAllocation4 + 1;
        Block__ctor_ea020(blockObject,*(undefined4 *)(program + 8));
        Block__connect(scopeObjectB,blockObject);
        Program__insertBlockAfter(program,continueTargetBlockB,blockObject);
        breakTargetBlockB = *(int *)(scopeObjectB + 0x154);
        Block__connect(blockObject,breakTargetBlockB);
        Program__insertBlockAfter(program,blockObject,breakTargetBlockB);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation3 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation3 = compilerArenaA;
        newBlock = (uint ******)(blockAllocation3 + 1);
        Block__ctor_ea020(newBlock,*(undefined4 *)(program + 8));
        currentBlock = (uint *****)newBlock;
        Program__insertBlockAfter(program,breakTargetBlockB,newBlock);
        Block__connect(breakTargetBlockB,currentBlock);
        previousBlock = currentBlock;
        Vector__removeAt(loopStackData,loopStackAlloc[2] + -1);
        opcodeFallthrough = 0;
        *(uint *****)(continueTargetBlockB + 0xb8) = scopeLevel;
        scopeLevel = (uint ****)((int)scopeLevel - 1);
        *(uint *****)(breakTargetBlockB + 0xb8) = scopeLevel;
        blockAllocation4[0x2f] = scopeLevel;
        currentBlock[0x2e] = scopeLevel;
      }
      else {
        previousBlock = (uint *****)Block__findSimplePredecessor(scopeObjectB);
        if (*(int **)(scopeObjectB + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(scopeObjectB + 0x150) + 4))();
        }
        if (*(int **)(scopeObjectB + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(scopeObjectB + 0x154) + 4))();
        }
        Vector__removeValue(previousBlock[0x34],scopeObjectB);
        do {
          nextBlock = (uint ******)previousBlock[2];
          blockInstList = nextBlock[0x26];
          for (instListCursor = (uint *****)nextBlock[0x26][2]; instListCursor != (uint *****)0x0;
              instListCursor = (uint *****)instListCursor[2]) {
            if (((uint)blockInstList[5] & 1) != 0) {
              blockInstList[5] = (uint ****)((uint)blockInstList[5] & 0xfffffffe);
            }
            blockInstList = instListCursor;
          }
          DList__initSentinel(nextBlock + 0x24);
          DList__unlink(nextBlock);
          if (nextBlock != (uint ******)0x0) {
            (*(code *)(*nextBlock)[1])(nextBlock);
          }
        } while (nextBlock != (uint ******)currentBlock);
        opcodeFallthrough = 0;
        scopeLevel = (uint ****)((int)scopeLevel - 1);
        currentBlock = previousBlock;
      }
      break;
    case 0x36:
      loopDepth = loopStackAlloc[2];
      enclosingLoopHeader = 0;
      if (loopDepth != 0) {
        vectorElementSlot3 = (undefined4 *)0x0;
        if (loopDepth - 1 < loopDepth) {
          vectorElementSlot3 = (undefined4 *)((loopDepth - 1) * 4 + loopStackAlloc[3]);
        }
        enclosingLoopHeader = *vectorElementSlot3;
      }
      argR6 = (uint ******)(uint)(ilOpcode == 0x71);
      if (argR6 == (uint ******)0x0) {
        loopRegisterNumber = (uint)*(ushort *)((int)*ilReader[0x1b] + 2);
      }
      else {
        loopRegisterNumber = 0;
      }
      arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x15c);
      *blockAllocation4 = arenaA;
      blockObject = blockAllocation4 + 1;
      argR7 = *(uint *******)(program + 8);
      PostLoopFooter__ctor_ea828(blockObject,loopRegisterNumber,enclosingLoopHeader,argR6,argR7);
      blockAllocation4[0x2f] = scopeLevel;
      if (((uint)*tokenWords & 0x10000) != 0) {
        blockAllocation4[0x4e] = 1;
      }
      IRInst__bindOperandRegisters(program,blockAllocation4[0x53]);
      loopStackSizeB = (uint *****)loopStackAlloc[2];
      if (loopStackSizeB < *loopStackData) {
        _memset((int)loopStackSizeB * 4 + loopStackAlloc[3],0,4);
        loopStackAlloc[2] = (int)loopStackSizeB + 1;
        vectorElementSlot2 = (undefined4 *)((int)loopStackSizeB * 4 + loopStackAlloc[3]);
      }
      else {
        vectorElementSlot2 = (undefined4 *)Vector__elementRefGrow(loopStackData,loopStackSizeB);
      }
      *vectorElementSlot2 = blockObject;
      scopeLevel = (uint ****)((int)scopeLevel + 1);
      Program__insertBlockAfter(program,previousBlock,blockObject);
      Block__connect(previousBlock,blockObject);
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation2 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation2 = compilerArenaA;
      newBlock = (uint ******)(blockAllocation2 + 1);
      Block__ctor_ea020(newBlock,*(undefined4 *)(program + 8));
      blockAllocation2[0x2f] = scopeLevel;
      currentBlock = (uint *****)newBlock;
      Program__insertBlockAfter(program,blockObject,newBlock);
      Block__connect(blockObject,currentBlock);
      previousBlock = currentBlock;
      opcodeFallthrough = 0;
      blockAllocation4[0x4d] = *(undefined4 *)(*(int *)(program + 8) + 0x324);
      break;
    case 0x37:
      templateCursor = (int *)((int)templateCursor + 1);
      irOpcode = *(undefined4 *)(templateBase + (int)templateCursor * 4);
      if (*(int *)(program + 0x47c) != 0) {
        irOpcode = 0x75;
      }
      workInst = IRInst__create(irOpcode,*(undefined4 *)(program + 8));
      opcodeFallthrough = 0;
      break;
    case 0x38:
      opcodeVariantFlag = 1;
      goto code_r0x00101d1c;
    case 0x3a:
      opcodeFallthrough = 0;
      workInst[0x48] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x3d:
      IROperand__setModifierBits(workInst + (int)operandIndexC * 6 + 0x23,1,
                   (uint)workInst[(int)operandIndexC * 6 + 0x28] & 1 ^ 1);
      goto code_r0x00101d1c;
    case 0x42:
      templateCursor = (int *)((int)templateCursor + 1);
      literalValue = (double)*(float *)(templateBase + (int)templateCursor * 4);
      ((void (*)())IRInst__makeLiteralVec4Float)(workInst,program,operandIndexC,literalValue,literalValue,literalValue,literalValue);
      goto code_r0x001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      opcodeTemplateTable = (uint ******)
                     (PTR_s_IF_b_001dc2cc)[templateToken * 4 + ((uint)*tokenWords >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      opcodeTemplateTable = *(uint *******)((int)&PTR_DAT_001dc75c + ((uint)*tokenWords >> 0xe & 0xc));
switchD_00102044_default:
      argR6 = (uint ******)currentBlock;
      argR8 = scopeVector;
      templateBase = ((int (*)())Template__pushCallFrame)(program,templateBase,&templateCursor,currentBlock,opcodeTemplateTable,scopeVector);
      argR7 = opcodeTemplateTable;
code_r0x0010372c:
      opcodeFallthrough = 0;
      break;
    case 0x4b:
      if ((((uint)*tokenWords & 0x10000) == 0) ||
         (hwFlag0x40Clear = true, (*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x40) != 0)) {
        hwFlag0x40Clear = false;
      }
      argR7 = (uint ******)PTR_DAT_001e8b98;
      if (hwFlag0x40Clear) {
        argR7 = (uint ******)PTR_DAT_001e8b9c;
      }
code_r0x001022b4:
      argR6 = (uint ******)currentBlock;
      argR8 = scopeVector;
      templateBase = ((int (*)())Template__pushCallFrame)(program,templateBase,&templateCursor,currentBlock,argR7,scopeVector);
      goto code_r0x0010372c;
    case 0x4d:
      opcodeFallthrough = 0;
      *(ushort *)((int)workInst[0x4f] + 0x12) = (byte)((uint)*tokenWords >> 0x18) & 1;
      break;
    case 0x4e:
      opcodeTemplateTable = (uint ******)
                     ((int (*)())OpcodeTemplate__lookup)((uint)*tokenWords >> 0x10 & 7,*(undefined4 *)(program + 8),0);
      goto code_r0x00101f74;
    case 0x4f:
      templateCursor = (int *)((int)templateCursor + 1);
      ((void (*)())IRInst__setExtraFixed3_4_1048d4)(workInst,(double)*(float *)(templateBase + (int)templateCursor * 4));
      goto code_r0x00101d1c;
    case 0x50:
      templateCursor = (int *)((int)templateCursor + 1);
      ((void (*)())IRInst__setExtraFixed3_4_10490c)(workInst,(double)*(float *)(templateBase + (int)templateCursor * 4));
      goto code_r0x00101d1c;
    case 0x51:
      ilRegisterIndex = *(byte *)((int)ilReader + 0x8d);
      textureStageIndex = (uint *****)(uint)ilRegisterIndex;
      if ((*(uint *)((int)usedRegisterBitmap + (ilRegisterIndex >> 3 & 0x1c) + 8) >> (ilRegisterIndex & 0x1f) & 1) == 0) {
        Compiler__logf(*(undefined4 *)(program + 8),"TextureStage %d misses DCLPT\n",textureStageIndex,argR6
                     ,argR7,argR8,ilRegisterIndex & 0x1f,0);
      }
      maxTextureStage = *(uint ******)(program + 0x7c);
      if ((int)*(uint ******)(program + 0x7c) < (int)textureStageIndex) {
        maxTextureStage = textureStageIndex;
      }
      *(uint ******)(program + 0x7c) = maxTextureStage;
      *(uint *)(program + 0x84) = 1 << ((uint)textureStageIndex & 0x3f) | *(uint *)(program + 0x84);
      workInst[0x4d] = textureStageIndex;
      workInst[0x4c] = textureStageIndex;
      opcodeFallthrough = 0;
      remappedKindValue = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)textureStageIndex * 0xc + *(int *)(program + 0x78)))
      ;
      workInst[0x4e] = remappedKindValue;
      break;
    case 0x52:
      opcodeFallthrough = 0;
      workInst[0x4d] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      workInst[0x4c] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      break;
    case 0x53:
      opcodeTemplateTable = (uint ******)
                     ((int (*)())OpcodeTemplate__lookup)((uint)*tokenWords >> 0x10 & 7,*(undefined4 *)(program + 8),1);
code_r0x00101f74:
      if (opcodeTemplateTable != (uint ******)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      firstTokenWord = *tokenWords;
      registerIndex2 = *(short *)((int)*ilReader[0x19] + 2);
      ilRegisterType = (uint)**ilReader[0x19] >> 0x10 & 0x3f;
      Program__registerFileOfIlType(program,ilRegisterType);
      registerMapB = *(undefined4 *)(program + 0x3ac);
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      argR6 = (uint ******)0x0;
      virtualRegister43 = VRegPool__findOrCreate(registerMapB,registerFile,(int)registerIndex2,0);
      if (((uint)firstTokenWord >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      opcodeFallthrough = 0;
      *(undefined4 *)(virtualRegister43 + 0x30) = 1;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
      cachedTempIndex = (&tempIndexCache)[templateToken - 0x55];
      if (cachedTempIndex == 0) {
        cachedTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = cachedTempIndex;
        (&tempIndexCache)[templateToken - 0x55] = cachedTempIndex;
      }
      operandRecordLast = IRInst__getOperandRecord(workInst,operandIndexC);
      *(undefined4 *)(operandRecordLast + 0xc) = 0;
      *(int *)(operandRecordLast + 8) = cachedTempIndex;
      if (operandIndexC == (uint ******)0x0) {
        argR6 = (uint ******)0x0;
        argR7 = (uint ******)0x0;
        argR8 = workInst;
        ((int (*)())IRInst__applyDescriptorSelects)(program,loopStackData,templateModeWord,0,0,workInst,0);
      }
      else {
        argR6 = operandIndexC;
        argR7 = workInst;
        ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,0,operandIndexC,workInst);
      }
      goto code_r0x001025c0;
    case 0x60:
      vectorElementSlot3 = (undefined4 *)0x0;
      scopeTopIndex = vectorAllocation[2] - 1;
      if (scopeTopIndex < (uint)vectorAllocation[2]) {
        vectorElementSlot3 = (undefined4 *)(scopeTopIndex * 4 + vectorAllocation[3]);
      }
      if (*(int *)*vectorElementSlot3 != 0) goto switchD_0010061c_caseD_1;
      opcodeScanCursor = (int *)((int)templateCursor * 4 + templateBase);
      do {
        cursorNext = templateCursor;
        if (*opcodeScanCursor == 0x37) {
          cursorNext = (int *)((int)templateCursor + 1);
          opcodeScanCursor = opcodeScanCursor + 1;
        }
        templateCursor = (int *)((int)cursorNext + 1);
        opcodeScanCursor = opcodeScanCursor + 1;
      } while (*opcodeScanCursor != 0x26);
      opcodeFallthrough = 0;
      templateCursor = cursorNext;
      break;
    case 0x6a:
      Compiler__fail(*(undefined4 *)(program + 8),0xf);
      goto code_r0x00101d1c;
    case 0x6b:
      optionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),4);
      argR7 = (uint ******)PTR_DAT_001e8bd8;
      if (optionEnabled != 0) {
        argR7 = (uint ******)PTR_DAT_001e8bb0;
      }
      argR8 = scopeVector;
      templateBase = ((int (*)())Template__pushCallFrame)(program,templateBase,&templateCursor,savedCurrentBlock,argR7,scopeVector);
      argR6 = savedCurrentBlock;
      goto code_r0x0010372c;
    case 0x6c:
      (*(code *)(*workInst)[9])(workInst);
      opcodeFallthrough = 0;
      workInst[0x4b] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x6d:
      operandRecord2 = IRInst__getOperandRecord(workInst,1);
      operandSelectValue = *(int *)(operandRecord2 + 0x10);
      loadedProgramValue = *(int *)(constantsBase + -0x2c30);
      if (operandSelectValue != loadedProgramValue) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        argR6 = (uint ******)0x0;
        newTempIndex21 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex21;
        virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex21,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,1,virtualRegister);
        instWord0x94B = workInst[0x25];
        instWord0x98 = workInst[0x26];
        operandRecordB = IRInst__getOperandRecord(movFloatInst,0);
        *(uint ******)(operandRecordB + 0xc) = instWord0x98;
        *(uint ******)(operandRecordB + 8) = instWord0x94B;
        operandRecordB = IRInst__getOperandRecord(movFloatInst,1);
        *(int *)(operandRecordB + 0x10) = operandSelectValue;
        operandRecordB = IRInst__getOperandRecord(workInst,0);
        *(undefined4 *)((int)movFloatInst + 0x9c) = *(undefined4 *)(operandRecordB + 0x10);
        IRInst__setOperandRef(workInst,0,virtualRegister);
        FUN_000f32cc(&markedSelectOut,operandSelectValue);
        workInst[0x27] = (uint *****)markedSelectOut;
        operandRecordLast = IRInst__getOperandRecord(workInst,1);
        *(int *)(operandRecordLast + 0x10) = loadedProgramValue;
        DList__pushFront(pendingListA,movFloatInst);
        goto code_r0x00101d1c;
      }
switchD_0010061c_caseD_1:
      opcodeFallthrough = 0;
      break;
    case 0x6e:
      templateCursor = (int *)((int)templateCursor + 1);
      argR6 = *(uint *******)(templateBase + (int)templateCursor * 4);
      argR7 = argR6;
      argR8 = argR6;
      ((int (*)())IRInst__setIntConstantOperand4)(workInst,program,operandIndexC,argR6,argR6,argR6,argR6);
code_r0x001025c0:
      operandIndexC = (uint ******)((int)operandIndexC + 1);
      opcodeFallthrough = 0;
      break;
    case 0x70:
      conditionStackCount = conditionStack[1];
      stackElement = (int *)0x0;
      if (conditionStackCount - 1 < conditionStackCount) {
        stackElement = (int *)((conditionStackCount - 1) * 4 + conditionStack[2]);
      }
      if (*(int *)(*stackElement + 4) == 0) {
        vectorElementSlot3 = (undefined4 *)0x0;
        compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
        if (conditionStackCount - 1 < conditionStack[1]) {
          vectorElementSlot3 = (undefined4 *)((conditionStackCount - 1) * 4 + conditionStack[2]);
        }
        freedStorage = *vectorElementSlot3;
        Vector__removeAt(conditionStack,conditionStack[1] - 1);
        Arena__free(compilerArenaB,freedStorage);
      }
      else {
        stackElement = (int *)0x0;
        if (conditionStackCount - 1 < conditionStack[1]) {
          stackElement = (int *)((conditionStackCount - 1) * 4 + conditionStack[2]);
        }
        argR6 = (uint ******)0x0;
        *(int *)(*stackElement + 4) = *(int *)(*stackElement + 4) + -1;
        templateCursor = (int *)((int)templateCursor + -1);
        argR8 = scopeVector;
        templateBase = ((int (*)())Template__pushCallFrame)(program,templateBase,&templateCursor,0,opcodeTemplateTable,scopeVector);
        argR7 = opcodeTemplateTable;
      }
code_r0x00101d1c:
      opcodeFallthrough = 0;
      break;
    case 0x71:
      opcodeFallthrough = 0;
      workInst[0x50] = *(uint ******)(templateBase + ((int)templateCursor + 1) * 4);
      templateCursor = (int *)((int)templateCursor + 1);
    }
    goto code_r0x00103b34;
  case 7:
    isTranslationKind7 = true;
  }
  builtInstB = (uint ******)((int (*)())Program__createInstForIlOpcode)(program,ilOpcode,(uint)*tokenWords >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(program,pendingListA,*ilReader[0x19],loopStackData,outputSlotCounter);
  registerIndex2 = *(short *)((int)*ilReader[0x19] + 2);
  registerFile = Program__registerFileOfIlType(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
  operandRecord2 = IRInst__getOperandRecord(builtInstB,0);
  *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
  *(int *)(operandRecord2 + 8) = (int)registerIndex2;
  argR7 = (uint ******)0x0;
  argR6 = (uint ******)*ilReader[0x19];
  argR8 = builtInstB;
  ((int (*)())IRInst__applyDescriptorSelects)(program,loopStackData,0,argR6,0,builtInstB,0);
  opcodeRecordField = ((int (*)())OpcodeRecord__getOperandCount)(ilOpcode,*(undefined4 *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0xc));
  operandCountPlusOne = (uint ******)(opcodeRecordField + 1);
  if (1 < (int)operandCountPlusOne) {
    sourceOperandNumber = (uint ******)((int)((unsigned char *)0x0) + 1);
    loopCounterC = 0;
    constantsBase = &DAT_001ad5d8;
    do {
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      argR8 = (uint ******)&lastDeclRegister;
      ((int (*)())FUN_000fb3d4)(program,pendingListB,tokenWords,*(undefined4 *)(loopCounterC + (int)ilReader[0x1b]),
                   loopStackData,&lastDeclRegister,&movByRegister);
      destTokenWord = **(uint **)(loopCounterC + (int)ilReader[0x1b]);
      if ((((destTokenWord & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        destRegisterNumberB = 0xf;
      }
      else {
        destRegisterNumberB = (int)(short)**(uint **)(loopCounterC + (int)ilReader[0x1b]);
      }
      registerFile = Program__registerFileOfIlType(program,destTokenWord >> 0x10 & 0x3f);
      operandRecordLast = IRInst__getOperandRecord(builtInstB,sourceOperandNumber);
      *(undefined4 *)(operandRecordLast + 0xc) = registerFile;
      *(int *)(operandRecordLast + 8) = destRegisterNumberB;
      if ((!isTranslationKind7) &&
         (flagBit2Result = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),builtInstB), flagBit2Result != 0)) {
        if (sourceOperandNumber == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          selectTableEntry = &UNK_001aa9d4;
        }
        else {
          selectTableEntry = &DAT_001aa9cc;
        }
        stagedSelectWord = (uint ******)*selectTableEntry;
      }
      argR6 = sourceOperandNumber;
      argR7 = builtInstB;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*(undefined4 *)(loopCounterC + (int)ilReader[0x1b]),sourceOperandNumber,
                   builtInstB);
      sourceOperandNumber = (uint ******)((int)sourceOperandNumber + 1);
      loopCounterC = loopCounterC + 4;
    } while (operandCountPlusOne != sourceOperandNumber);
  }
  writtenComponentCount = IRInst__countWrittenComponents(builtInstB);
  if (isTranslationKind7) {
    newTempIndex20 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex20;
    instWord0x94B = builtInstB[0x25];
    instWord0x98 = builtInstB[0x26];
    operandRecord2 = IRInst__getOperandRecord(builtInstB,0);
    *(int *)(operandRecord2 + 8) = newTempIndex20;
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    opcodeFlagBit2 = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),builtInstB);
    operandRecordY = IRInst__getOperandRecord(builtInstB,0);
    operandSelectRaw = *(uint *******)(operandRecordY + 0x10);
    stagedSelectWord = operandSelectRaw;
    if (1 < writtenComponentCount) {
      scopeLevelPtr = (uint ****)&scopeLevel;
      laneStep = 0;
      scopeLevelPtrCopy = scopeLevelPtr;
      do {
        firstWrittenLaneB = SelectWord__firstWrittenComponent(stagedSelectWord);
        copiedInst = ((int (*)())Program__createInstForIlOpcode)(program,ilOpcode,(uint)*tokenWords >> 0x10 & 0x3fff);
        stagedSelectCopy = scopeLevelPtrCopy;
        if (0 < (int)operandCountPlusOne) {
          operandLoopIndex = (uint ******)0x0;
          do {
            argR6 = operandLoopIndex;
            IRInst__copyOperandFrom(copiedInst,operandLoopIndex,builtInstB,operandLoopIndex);
            if (opcodeFlagBit2 != 0) {
              operandRecordC = IRInst__getOperandRecord(copiedInst,operandLoopIndex);
              rewrittenSelect = *(uint ******)(operandRecordC + 0x10);
              if (operandLoopIndex == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
                templateModeWord = (uint *****)
                            CONCAT31((int3)((uint)rewrittenSelect >> 8),
                                     *(undefined1 *)((int)stagedSelectCopy + firstWrittenLaneB + 100));
              }
              else if (operandLoopIndex == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
                templateModeWord = (uint *****)
                            CONCAT13(*(undefined1 *)((int)stagedSelectCopy + firstWrittenLaneB + 100),
                                     (int3)rewrittenSelect);
              }
              else {
                templateModeWord = rewrittenSelect;
                if (operandLoopIndex == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
                  (*(unsigned short *)((unsigned char *)&(templateModeWord) + 0)) = (undefined2)((uint)rewrittenSelect >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(templateModeWord) + 2)) =
                       CONCAT11(*(undefined1 *)((int)stagedSelectCopy + firstWrittenLaneB + 100),(char)rewrittenSelect);
                }
              }
              rewrittenSelect = templateModeWord;
              iVar23 = IRInst__getOperandRecord(copiedInst,operandLoopIndex);
              *(uint ******)(iVar23 + 0x10) = rewrittenSelect;
            }
            operandLoopIndex = (uint ******)((int)operandLoopIndex + 1);
          } while (operandCountPlusOne != operandLoopIndex);
        }
        *(undefined4 *)(copiedInst + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + firstWrittenLaneB * 4);
        *(undefined1 *)((int)scopeLevelPtr + firstWrittenLaneB + 0x10) = 1;
        *(uint ******)(copiedInst + 0x120) = builtInstB[0x48];
        DList__pushBack(pendingListB,copiedInst);
        laneStep = laneStep + 1;
      } while (writtenComponentCount + -1 != laneStep);
    }
    builtInstB[0x27] = (uint *****)stagedSelectWord;
    if ((opcodeFlagBit2 != 0) && (firstWrittenLane = SelectWord__firstWrittenComponent(stagedSelectWord), 1 < (int)operandCountPlusOne)) {
      sourceNumberB = (uint ******)((int)((unsigned char *)0x0) + 1);
      do {
        operandRecord2 = IRInst__getOperandRecord(builtInstB,sourceNumberB);
        destSelectWordCopy = *(uint *******)(operandRecord2 + 0x10);
        tempIndexCache = destSelectWordCopy;
        if (sourceNumberB == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          tempIndexCache = (uint ******)
                      CONCAT31((int3)((uint)destSelectWordCopy >> 8),
                               *(undefined1 *)((int)&tempIndexCache + firstWrittenLane));
        }
        else if (sourceNumberB == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
          tempIndexCache = (uint ******)
                      CONCAT13(*(undefined1 *)((int)&tempIndexCache + firstWrittenLane),(int3)destSelectWordCopy);
        }
        else if (sourceNumberB == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
          (*(unsigned short *)((unsigned char *)&(tempIndexCache) + 0)) = (undefined2)((uint)destSelectWordCopy >> 0x10);
          (*(unsigned short *)((unsigned char *)&(tempIndexCache) + 2)) = CONCAT11(*(undefined1 *)((int)&tempIndexCache + firstWrittenLane),(char)destSelectWordCopy);
        }
        destSelectWordCopy = tempIndexCache;
        operandRecord2 = IRInst__getOperandRecord(builtInstB,sourceNumberB);
        sourceNumberB = (uint ******)((int)sourceNumberB + 1);
        *(uint *******)(operandRecord2 + 0x10) = destSelectWordCopy;
      } while (operandCountPlusOne != sourceNumberB);
    }
    movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord = IRInst__getOperandRecord(movFloatInst,0);
    *(uint ******)(operandRecord + 0xc) = instWord0x98;
    *(uint ******)(operandRecord + 8) = instWord0x94B;
    *(uint *******)((int)movFloatInst + 0x9c) = operandSelectRaw;
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    *(int *)(operandRecord + 8) = newTempIndex20;
    *(undefined4 *)(operandRecord + 0xc) = 0;
    DList__pushFront(pendingListA,movFloatInst);
  }
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  hwQueryResult = (**(code **)(*hwDescription + 0x34))(hwDescription,builtInstB);
  if (hwQueryResult == 0) {
code_r0x001002dc:
    movFloatInst = (void *)0x0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(builtInstB,0);
    writtenLaneCount = 0;
    loopCounterC = 0;
    stagedSelectWord = *(uint *******)(operandRecord + 0x10);
    argR8 = (uint ******)&tempIndexCache;
    tempIndexCache = *(uint *******)(operandRecord + 0x10);
    loopCounter = 4;
    argR7 = (uint ******)&stagedSelectWord;
    selectedLane = -1;
    do {
      selectedLaneB = selectedLane;
      if (*(char *)(loopCounterC + (int)argR8) == '\0') {
        selectedLaneB = loopCounterC;
        if ((writtenLaneCount != 0) && (selectedLaneB = selectedLane, 0 < writtenLaneCount)) {
          *(undefined1 *)(loopCounterC + (int)argR7) = 1;
        }
        writtenLaneCount = writtenLaneCount + 1;
      }
      loopCounterC = loopCounterC + 1;
      loopCounter = loopCounter + -1;
      selectedLane = selectedLaneB;
    } while (loopCounter != 0);
    if (writtenLaneCount < 2) goto code_r0x001002dc;
    loopCounterC = 4;
    builtInstB[0x27] = (uint *****)stagedSelectWord;
    loopCounterB = 0;
    argR7 = (uint ******)&templateModeWord;
    do {
      *(char *)(loopCounterB + (int)argR7) = (char)selectedLaneB;
      loopCounterB = loopCounterB + 1;
      loopCounterC = loopCounterC + -1;
    } while (loopCounterC != 0);
    movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    instWord0x94 = builtInstB[0x25];
    instWord0x98B = builtInstB[0x26];
    operandRecord = IRInst__getOperandRecord(movFloatInst,0);
    *(uint ******)(operandRecord + 0xc) = instWord0x98B;
    *(uint ******)(operandRecord + 8) = instWord0x94;
    instWord0x94B = builtInstB[0x25];
    *(uint *******)((int)movFloatInst + 0x9c) = tempIndexCache;
    instWord0x98C = builtInstB[0x26];
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    savedExtraWord = templateModeWord;
    *(uint ******)(operandRecord + 0xc) = instWord0x98C;
    *(uint ******)(operandRecord + 8) = instWord0x94B;
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    *(uint ******)(operandRecord + 0x10) = savedExtraWord;
  }
  nextListNode = *(int *)(local_14c + 8);
  pendingInst = local_14c;
  while (flushNodeC = nextListNode, flushNodeC != 0) {
    DList__unlink(pendingInst);
    ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
    pendingInst = flushNodeC;
    nextListNode = *(int *)(flushNodeC + 8);
  }
  ((int (*)())Program__appendInst)(program,builtInstB,currentBlock);
  if (movFloatInst != (void *)0x0) {
    ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
  }
  nextListNode = *(int *)(local_164 + 8);
  pendingInst = local_164;
  while (flushNodeC = nextListNode, flushNodeC != 0) {
    DList__unlink(pendingInst);
    ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
    pendingInst = flushNodeC;
    nextListNode = *(int *)(flushNodeC + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  opcodeFallthrough = 1;
code_r0x00103b34:
  if (workInst != (uint ******)0x0) {
code_r0x00103b3c:
    vtableSlot5Result = (*(code *)(*workInst)[5])(workInst);
    if ((uint ******)(vtableSlot5Result + 1U) == operandIndexC) {
      ((int (*)())Program__appendInst)(program,workInst,currentBlock);
      workInst = (uint ******)0x0;
      operandIndexC = (uint ******)0x0;
      stagedSelectWord = *(uint *******)(constantsBase + -0x2c30);
      templateModeWord = *(uint ******)(constantsBaseB + -0x2bfc);
    }
  }
  if (opcodeFallthrough != 0) goto code_r0x00103bb0;
  templateCursor = (int *)((int)templateCursor + 1);
  goto code_r0x001005f4;
code_r0x00103bb0:
  nextListNode = *(int *)(local_164 + 8);
  pendingInst = local_164;
  while (flushNodeC = nextListNode, flushNodeC != 0) {
    DList__unlink(pendingInst);
    ((int (*)())Program__appendInst)(program,pendingInst,currentBlock);
    pendingInst = flushNodeC;
    nextListNode = *(int *)(flushNodeC + 8);
  }
  if (scopeVectorB != (uint *)0x0) {
    Arena__free(vectorAllocation[4],vectorAllocation[3]);
    Arena__free(*vectorAllocation,vectorAllocation);
  }
  if (scopeVector != (uint ******)0x0) {
    Arena__free(vectorAllocation2[4],vectorAllocation2[3]);
    Arena__free(*vectorAllocation2,vectorAllocation2);
  }
  goto switchD_000fdaf0_caseD_2;
}
#undef local_14c
#undef local_164
