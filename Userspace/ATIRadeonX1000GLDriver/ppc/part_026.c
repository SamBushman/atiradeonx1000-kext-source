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
int Compiler__getOrCreateLoadConstN(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *compiler;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 arena;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *allocation;
  int *piVar5;
  undefined4 *puVar6;
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
   * called below as aiStack_9c[param_2] with param_2 observed as 4, one past this array's declared
   * 4 elements; local_8c (assigned right after, from compiler[5]) sits exactly at the missing 5th
   * index by its own hex offset (0x9c-0x8c=0x10). Extended to 5 elements; local_8c aliased to
   * index 4. */
  int aiStack_9c [5];
#define local_8c aiStack_9c[4]
  undefined4 local_88 [29];
  
  aiStack_9c[1] = compiler[2];
  aiStack_9c[2] = compiler[3];
  loopCounterB = 4;
  loopCounter = 0;
  loopIndex = 0;
  local_88[0] = param_3;
  local_88[1] = param_4;
  aiStack_9c[3] = compiler[4];
  local_8c = compiler[5];
  puVar6 = local_88;
  do {
    if ((int)loopIndex < param_2) {
      *(byte *)(compiler[10] + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(compiler[10] + 0x15c);
      uVar1 = *(undefined4 *)((int)puVar6 + loopCounter);
      iVar2 = loopCounter + 0x10 + compiler[10];
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_88 + loopCounter + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(compiler[10] + 0x15c) = *(byte *)(compiler[10] + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f))
      ;
    }
    loopIndex = loopIndex + 1;
    loopCounter = loopCounter + 0x18;
    loopCounterB = loopCounterB + -1;
  } while (loopCounterB != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  puVar3 = (undefined4 *)HashTable__find(aiStack_9c[param_2],compiler[10]);
  if (puVar3 == (undefined4 *)0x0) {
    arena = *(undefined4 *)(*compiler + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    puVar3 = allocation + 1;
    IRLoadConst__ctor_109938(puVar3,*compiler);
    if ((*(uint *)(*(int *)(*compiler + 0x6c4) + 0x30) & 0x10000) == 0) {
      uVar1 = FUN_000f4a5c(compiler);
      allocation[0x26] = uVar1;
      allocation[0x27] = 0xc;
    }
    else {
      uVar1 = Emitter__allocateConstantSlot(compiler,local_88[0],0,puVar6,loopCounter,loopIndex,*compiler);
      allocation[0x26] = uVar1;
      allocation[0x27] = 0xc;
    }
    loopIndex = 0;
    loopCounterB = 4;
    puVar6 = allocation + 5;
    loopCounter = 0;
    do {
      if ((int)loopIndex < param_2) {
        *(byte *)(allocation + 0x58) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(allocation + 0x58);
        uVar1 = *(undefined4 *)((int)local_88 + loopCounter);
        puVar6[4] = *(undefined4 *)((int)local_88 + loopCounter + 4);
        puVar6[3] = uVar1;
      }
      else {
        *(byte *)(allocation + 0x58) = *(byte *)(allocation + 0x58) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x18;
      puVar6 = puVar6 + 6;
      loopCounterB = loopCounterB + -1;
    } while (loopCounterB != 0);
    piVar5 = *(int **)(*(int *)(*compiler + 0x6c4) + 0x3a0);
    (**(code **)(*piVar5 + 0xc))(piVar5,puVar3);
    ((int (*)())ConstRecord__insertSwizzleVariants)(compiler,param_2,puVar3);
  }
  return puVar3;
}
#undef local_8c

/* FUN_000f5248 @ 0xf5248 (376 bytes) */
int FUN_000f5248(compiler, constVec0, constVec1, constVec2, constVec3, constVec4, constVec5, constVec6)
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
  uint loopCounterC;
  int loopCounter;
  bool bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint loopIndex;
  uint *puVar9;
  int iVar10;
  int loopCounterB;
  undefined4 local_38 [8];
  
  if (registerMap[7] != 0) {
    loopIndex = 0;
    do {
      puVar9 = (uint *)registerMap[8];
      if (loopIndex < *puVar9) {
        uVar4 = puVar9[1];
        if (uVar4 <= loopIndex) {
          _memset(uVar4 * 4 + puVar9[2],0,(loopIndex - uVar4) * 4 + 4);
          puVar9[1] = loopIndex + 1;
        }
        piVar5 = (int *)(loopIndex * 4 + puVar9[2]);
      }
      else {
        piVar5 = (int *)Vector__elementRefGrow(puVar9,loopIndex);
      }
      iVar10 = *piVar5;
      loopCounter = 0;
      pcVar7 = selectBytes;
      do {
        if (*pcVar7 != '\x04') {
          loopCounterC = 0;
          loopCounterB = 4;
          iVar3 = iVar10;
          while (((((int)*(char *)(iVar10 + 0x15c) >> (loopCounterC & 0x3f) & 1U) == 0 ||
                  (*(int *)(iVar3 + 0x1c) != 2)) ||
                 (*(float *)(iVar3 + 0x20) != *(float *)(values + loopCounter)))) {
            loopCounterC = loopCounterC + 1;
            iVar3 = iVar3 + 0x18;
            loopCounterB = loopCounterB + -1;
            if (loopCounterB == 0) goto LAB_000f59bc;
          }
        }
        bVar1 = loopCounter != 0xc;
        pcVar7 = pcVar7 + 1;
        loopCounter = loopCounter + 4;
      } while (bVar1);
      loopCounter = 0;
      local_38[0] = *(undefined4 *)selectBytes;
      pcVar7 = selectBytes;
      do {
        uVar4 = (uint)*(byte *)((int)local_38 + loopCounter);
        if (((uVar4 != 4) && (((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0)) &&
           (fVar2 = *(float *)(values + loopCounter * 4),
           *(float *)(uVar4 * 0x18 + iVar10 + 0x20) != fVar2)) {
          loopCounterB = 4;
          loopCounterC = 0;
          iVar3 = iVar10;
          do {
            if (((((int)*(char *)(iVar10 + 0x15c) >> (loopCounterC & 0x3f) & 1U) != 0) &&
                (*(int *)(iVar3 + 0x1c) == 2)) && (*(float *)(iVar3 + 0x20) == fVar2)) {
              *pcVar7 = (char)loopCounterC;
              break;
            }
            loopCounterC = loopCounterC + 1;
            iVar3 = iVar3 + 0x18;
            loopCounterB = loopCounterB + -1;
          } while (loopCounterB != 0);
        }
        bVar1 = loopCounter != 3;
        pcVar7 = pcVar7 + 1;
        loopCounter = loopCounter + 1;
      } while (bVar1);
      iVar6 = (**(code **)(**(int **)(*registerMap + 0x30c) + 0x100))
                        (*(int **)(*registerMap + 0x30c),selectBytes);
      if (iVar6 != 0) {
        *(undefined4 *)(iVar10 + 0x9c) = DAT_001aa860;
        return iVar10;
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
  int operandRecord;
  int sourceDef;
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int loopCounter;
  double dVar9;
  
  iVar3 = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(program + 8),inst2);
  if (iVar3 == 0) goto LAB_000f5a8c;
  uVar2 = *(uint *)(operandIndex * 0x18 + inst + 0xa0) & 1;
  IRInst__getOperandRecord(inst2,0);
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  iVar3 = *(int *)(sourceDef + 0x98);
  if (iVar3 == 0xc) {
LAB_000f5b30:
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    piVar7 = *(int **)(*(int *)(program + 8) + 0x30c);
    loopCounter = 0;
    do {
      operandRecord = IRInst__getOperandRecord(inst2,0);
      if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
        operandRecord = IRInst__getOperandRecord(inst,operandIndex);
        uVar6 = (uint)*(byte *)(loopCounter + operandRecord + 0x10);
        if (uVar6 != 4) {
          if (((int)*(char *)(sourceDef + 0x15c) >> (uVar6 & 0x3f) & 1U) == 0) goto LAB_000f5a8c;
          if (uVar2 == 0) {
            dVar9 = (double)*(float *)(uVar6 * 0x18 + sourceDef + 0x20);
          }
          else {
            dVar9 = -(double)*(float *)(uVar6 * 0x18 + sourceDef + 0x20);
          }
          iVar5 = (**(code **)(*piVar7 + 0xf0))(dVar9,piVar7);
          if (iVar5 == 0) goto LAB_000f5a8c;
        }
      }
      bVar1 = loopCounter != 3;
      loopCounter = loopCounter + 1;
    } while (bVar1);
LAB_000f5b28:
    uVar4 = 1;
  }
  else {
    if (iVar3 == 0x33) {
      if (uVar2 == 0) {
        sourceDef = IRInst__getOperandSource(inst,operandIndex);
        loopCounter = 0;
        piVar7 = *(int **)(*(int *)(program + 8) + 0x30c);
        do {
          operandRecord = IRInst__getOperandRecord(inst2,0);
          if (*(char *)(loopCounter + operandRecord + 0x10) != '\x01') {
            iVar5 = IRInst__getOperandRecord(inst,operandIndex);
            uVar2 = (uint)*(byte *)(loopCounter + iVar5 + 0x10);
            if ((uVar2 != 4) &&
               (iVar5 = (**(code **)(*piVar7 + 0xf0))
                                  ((double)*(float *)(uVar2 * 0x18 + sourceDef + 0x20),piVar7),
               iVar5 == 0)) goto LAB_000f5a8c;
          }
          bVar1 = loopCounter != 3;
          loopCounter = loopCounter + 1;
        } while (bVar1);
        goto LAB_000f5b28;
      }
    }
    else if (iVar3 == 2) goto LAB_000f5b30;
LAB_000f5a8c:
    uVar4 = 0;
  }
  return uVar4;
}

/* IRInst__sourceMatchesConstant @ 0xf5c0c (228 bytes) */
int IRInst__sourceMatchesConstant(inst, operandIndex, param_3, param_4)
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 param_3;
  int *param_4;
{
  int loopCounter;
  int operandRecord;
  unsigned int ghidra_home[8] = { inst, operandIndex, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  int *a0;
  int iVar2;
  undefined4 uVar3;
  int loopCounterB;
  char *pcVar5;
  undefined4 local_38 [9];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  iVar2 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar2 == 0) {
LAB_000f5cd8:
    uVar3 = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    pcVar5 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    local_38[0] = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    do {
      if (((*pcVar5 == '\0') && (uVar1 = (uint)*(byte *)((int)local_38 + loopCounterB), uVar1 < 4)) &&
         ((((int)*(char *)(a0 + 0x57) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (a0[uVar1 * 6 + 8] != *param_4)))) goto LAB_000f5cd8;
      loopCounterB = loopCounterB + 1;
      pcVar5 = pcVar5 + 1;
      param_4 = param_4 + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    uVar3 = 1;
  }
  return uVar3;
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

/* FUN_000f5e8c @ 0xf5e8c (264 bytes) */
int FUN_000f5e8c(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int loopCounter;
  int operandRecord;
  int *a0;
  int iVar1;
  undefined4 uVar2;
  int loopCounterB;
  uint uVar4;
  undefined4 local_38;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  iVar1 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar1 == 0) {
LAB_000f5f7c:
    uVar2 = 0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    loopCounterB = 0;
    local_38 = *(undefined4 *)(operandRecord + 0x10);
    loopCounter = 4;
    do {
      uVar4 = (uint)*(byte *)((int)&local_38 + loopCounterB);
      if (uVar4 < 4) {
        local_30 = GH_U2F((unsigned int)(a0[uVar4 * 6 + 8]));
        local_2c = a0[uVar4 * 6 + 9];
        local_28 = a0[uVar4 * 6 + 10];
        local_34 = a0[uVar4 * 6 + 7];
        local_20 = a0[uVar4 * 6 + 0xc];
        local_24 = a0[uVar4 * 6 + 0xb];
        if (((a0[uVar4 * 6 + 7] != 2) || (((int)*(char *)(a0 + 0x57) >> (uVar4 & 0x3f) & 1U) == 0))
           || (GH_U2F((unsigned int)(a0[uVar4 * 6 + 8])) < 0.0)) goto LAB_000f5f7c;
      }
      loopCounterB = loopCounterB + 1;
      loopCounter = loopCounter + -1;
    } while (loopCounter != 0);
    uVar2 = 1;
  }
  return uVar2;
}

/* RegisterMap__findConstVectorExact @ 0xf5f94 (304 bytes) */
int RegisterMap__findConstVectorExact(registerMap, values, selectBytes, param_4, param_5, param_6, param_7)
  int registerMap;
  int values;
  byte *selectBytes;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int loopCounter;
  byte *pbVar6;
  uint loopIndex;
  uint *puVar8;
  int loopCounterB;
  
  if (*(int *)(registerMap + 0x1c) != 0) {
    loopIndex = 0;
    do {
      puVar8 = *(uint **)(registerMap + 0x20);
      if (loopIndex < *puVar8) {
        uVar1 = puVar8[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar8[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar8[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar8[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar8,loopIndex);
      }
      iVar3 = *piVar2;
      loopCounterB = 4;
      loopCounter = 0;
      pbVar6 = selectBytes;
      while ((uVar1 = (uint)*pbVar6, uVar1 == 4 ||
             (((((int)*(char *)(iVar3 + 0x15c) >> (uVar1 & 0x3f) & 1U) != 0 &&
               (iVar4 = uVar1 * 0x18 + iVar3, *(int *)(iVar4 + 0x1c) == 2)) &&
              (*(float *)(iVar4 + 0x20) == *(float *)(loopCounter + values)))))) {
        pbVar6 = pbVar6 + 1;
        loopCounter = loopCounter + 4;
        loopCounterB = loopCounterB + -1;
        if (loopCounterB == 0) {
          *(undefined4 *)(iVar3 + 0x9c) = DAT_001aa860;
          return iVar3;
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
int Compiler__getOrCreateConstVectorN(owner, param_2, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5)
  int owner;
  int param_2;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
{
  int loopCounterC;
  int loopCounterB;
  int loopCounter;
  int foundEntry;
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint loopIndex;
  int iVar6;
  int iVar7;
  int loopCounterD;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  /* issue #64 live-repro: called below as auStack_8c[param_2] with param_2 observed as 4 - one
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
  undefined4 local_78 [26];
  
  auStack_8c[1] = *(undefined4 *)(owner + 8);
  auStack_8c[2] = *(undefined4 *)(owner + 0xc);
  loopCounterC = 4;
  loopCounterB = 0;
  loopIndex = 0;
  local_78[0] = operandWord0;
  local_78[1] = operandWord1;
  auStack_8c[3] = *(undefined4 *)(owner + 0x10);
  local_7c = *(undefined4 *)(owner + 0x14);
  do {
    if ((int)loopIndex < param_2) {
      *(byte *)(*(int *)(owner + 0x28) + 0x15c) =
           (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(*(int *)(owner + 0x28) + 0x15c);
      uVar1 = *(undefined4 *)((int)local_78 + loopCounterB);
      iVar2 = loopCounterB + 0x10 + *(int *)(owner + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_78 + loopCounterB + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
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
  foundEntry = HashTable__find(auStack_8c[param_2],*(undefined4 *)(owner + 0x28));
  if (foundEntry == 0) {
    uVar1 = FUN_000f4a5c(owner);
    iVar4 = VRegPool__create(owner,0xc,uVar1,0);
    piVar3 = *(int **)(iVar4 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)Vector__elementRefGrow(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar7 = *piVar3;
    loopCounterD = 4;
    loopIndex = 0;
    iVar6 = iVar7 + 0x10;
    loopCounter = 0;
    do {
      if ((int)loopIndex < param_2) {
        *(byte *)(iVar7 + 0x15c) = (byte)(1 << (loopIndex & 0x3f)) | *(byte *)(iVar7 + 0x15c);
        uVar1 = *(undefined4 *)((int)local_78 + loopCounter);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)((int)local_78 + loopCounter + 4);
        *(undefined4 *)(iVar6 + 0xc) = uVar1;
      }
      else {
        *(byte *)(iVar7 + 0x15c) = *(byte *)(iVar7 + 0x15c) & ~(byte)(1 << (loopIndex & 0x3f));
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x18;
      iVar6 = iVar6 + 0x18;
      loopCounterD = loopCounterD + -1;
    } while (loopCounterD != 0);
    ((int (*)())ConstRecord__insertSwizzleVariants)(owner,param_2,iVar7);
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
  uint loopCounterE;
  uint loopCounterD;
  int loopCounterC;
  int loopCounter;
  undefined4 *allocation;
  undefined4 arena;
  unsigned int ghidra_home[8] = { program, constWords, selectWord, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int loopCounterB;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  int local_98;
  int local_94 [30];
  
  puVar10 = (undefined4 *)0x0;
  iVar9 = *(int *)(program + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectWord;
  iVar2 = (**(code **)(**(int **)(iVar9 + 0x30c) + 0xe8))
                    (*(int **)(iVar9 + 0x30c),constWords,&local_98,selectWord,iVar9);
  if (iVar2 != 0) {
    FUN_000f4a24(constWords,local_94);
    iVar2 = *(int *)(program + 0x3ac);
    loopCounterE = 0;
    uVar11 = *(uint *)(*(int *)(iVar2 + 0x18) + 4);
    if (0 < (int)uVar11) {
      while( true ) {
        puVar14 = *(uint **)(iVar2 + 0x18);
        if (loopCounterE < *puVar14) {
          uVar3 = puVar14[1];
          if (uVar3 <= loopCounterE) {
            _memset(uVar3 * 4 + puVar14[2],0,(loopCounterE - uVar3) * 4 + 4);
            puVar14[1] = loopCounterE + 1;
          }
          piVar5 = (int *)(loopCounterE * 4 + puVar14[2]);
        }
        else {
          piVar5 = (int *)Vector__elementRefGrow(puVar14,loopCounterE);
        }
        puVar10 = (undefined4 *)*piVar5;
        if (puVar10[0x4b] == local_98) {
          pcVar7 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
          puVar6 = puVar10 + 4;
          loopCounterB = 0;
          loopCounter = 4;
          while ((*pcVar7 == '\x04' ||
                 ((puVar6[3] == *(int *)((int)local_94 + loopCounterB) &&
                  (puVar6[4] == *(int *)((int)local_94 + loopCounterB + 4)))))) {
            loopCounter = loopCounter + -1;
            loopCounterB = loopCounterB + 0x18;
            puVar6 = puVar6 + 6;
            pcVar7 = pcVar7 + 1;
            if (loopCounter == 0) {
              if (puVar10 != (undefined4 *)0x0) {
                return puVar10;
              }
              goto LAB_000f6b68;
            }
          }
        }
        loopCounterE = loopCounterE + 1;
        if (uVar11 == loopCounterE) break;
        iVar2 = *(int *)(program + 0x3ac);
      }
    }
LAB_000f6b68:
    if ((*(uint *)(program + 0x30) & 8) == 0) {
      uVar12 = *(undefined4 *)(program + 0x3ac);
      uVar4 = FUN_000f4a5c(uVar12);
      iVar2 = VRegPool__create(uVar12,0x33,uVar4,0);
      piVar5 = *(int **)(iVar2 + 0x18);
      if (*piVar5 == 0) {
        piVar5 = (int *)Vector__elementRefGrow(piVar5,0);
      }
      else {
        if (piVar5[1] == 0) {
          *(undefined4 *)piVar5[2] = 0;
          piVar5[1] = 1;
        }
        piVar5 = (int *)piVar5[2];
      }
      puVar10 = (undefined4 *)*piVar5;
    }
    else {
      arena = *(undefined4 *)(iVar9 + 0x374);
      allocation = (undefined4 *)Arena__alloc(arena,0x168);
      *allocation = arena;
      puVar10 = allocation + 1;
      IRLoadConst__ctor_109938(puVar10,*(undefined4 *)(program + 8));
      uVar4 = FUN_000f4a5c(*(undefined4 *)(program + 0x3ac));
      allocation[0x26] = uVar4;
      allocation[0x27] = 0x33;
      (**(code **)(**(int **)(program + 0x3a0) + 0xc))(*(int **)(program + 0x3a0),puVar10);
    }
    puVar10[0x4b] = local_98;
    puVar14 = *(uint **)(*(int *)(program + 0x3ac) + 0x18);
    uVar11 = puVar14[1];
    if (uVar11 < *puVar14) {
      _memset(uVar11 * 4 + puVar14[2],0,4);
      piVar5 = (int *)(uVar11 * 4 + puVar14[2]);
      puVar14[1] = uVar11 + 1;
    }
    else {
      piVar5 = (int *)Vector__elementRefGrow(puVar14,uVar11);
    }
    *piVar5 = (int)puVar10;
    loopCounterC = 4;
    loopCounterD = 0;
    puVar6 = puVar10 + 4;
    loopCounter = 0;
    do {
      puVar1 = (undefined4 *)((int)local_94 + loopCounter);
      uVar4 = *(undefined4 *)((int)local_94 + loopCounter + 4);
      loopCounter = loopCounter + 0x18;
      puVar6[3] = *puVar1;
      puVar6[4] = uVar4;
      uVar13 = loopCounterD & 0x3f;
      loopCounterD = loopCounterD + 1;
      puVar6 = puVar6 + 6;
      *(byte *)(puVar10 + 0x57) = (byte)(1 << uVar13) | *(byte *)(puVar10 + 0x57);
      loopCounterC = loopCounterC + -1;
    } while (loopCounterC != 0);
  }
  return puVar10;
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
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int **ppiVar5;
  int loopCounterB;
  int iVar7;
  undefined4 loadConstSource;
  int *piVar9;
  uint *operandB;
  int iVar11;
  uint *operandA;
  undefined4 compiler;
  bool notLastWord;
  int iVar15;
  int local_288;
  undefined1 auStack_284 [4];
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
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
    ppiVar5 = operandPtrTable + 7;
    do {
      *ppiVar5 = (int *)0x7ffffffe;
      ppiVar5 = ppiVar5 + 1;
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
      local_288 = *(int *)(existingInstRecord + 0x10);
      if (local_288 != DAT_001aa860) {
        loopCounterB = 0;
        do {
          operandRecord = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
          if (*(byte *)(loopCounterB + operandRecord + 0x10) < 4) {
            operandRecord = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
            uVar3 = (uint)*(byte *)(loopCounterB + operandRecord + 0x10);
            auStack_284[uVar3 - 4] = 0;
            *(byte *)(existingConstInst + uVar3 + 0xc) =
                 (byte)(1 << (uVar3 & 0x3f)) | *(byte *)(existingConstInst + uVar3 + 0xc);
          }
          notLastWord = loopCounterB != 3;
          loopCounterB = loopCounterB + 1;
        } while (notLastWord);
        *(int *)(existingConstInst + 0x9c) = local_288;
      }
      return;
    }
  }
  piVar9 = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  local_27c = DAT_001aa868;
  operandPtrTable[0] = &constOperand1Kind;
  ppiVar5 = &local_274;
  iVar15 = 0;
  operandPtrTable[1] = &constOperand2Kind;
  operandPtrTable[2] = &constOperand3Kind;
  operandPtrTable[6] = (int *)PTR_DAT_001e8b70;
  local_274 = piVar9;
  operandPtrTable[3] = (int *)PTR_DAT_001e8b70;
  operandPtrTable[4] = (int *)PTR_DAT_001e8b70;
  operandPtrTable[5] = (int *)PTR_DAT_001e8b70;
  uniqueCount = 0;
LAB_000f6f18:
  do {
    iVar7 = uniqueCount;
    *(char *)((int)&local_27c + iVar15) = (char)iVar7;
    uniqueCount = iVar7 + 1;
    operandPtrTable[iVar7 + 3] = piVar9;
LAB_000f6f58:
    iVar4 = 4 - iVar15;
    do {
      iVar11 = iVar15;
      iVar15 = iVar11 + 1;
      ppiVar5 = ppiVar5 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        local_278 = DAT_001aa868;
        if (0 < uniqueCount) {
          do {
            iVar11 = iVar7 + 1;
            loopCounter = 0;
            loopCounterD = 0;
            ppiVar5 = operandPtrTable + 4;
            if (iVar7 < 0) {
              iVar11 = 1;
            }
            while (iVar11 = iVar11 + -1, iVar11 != 0) {
              operandA = (uint *)ppiVar5[-1];
              operandB = (uint *)*ppiVar5;
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
                uVar2 = *(undefined1 *)((int)&local_278 + loopCounter);
                uVar1 = *(undefined1 *)((int)&local_278 + loopCounterD + 1);
                *ppiVar5 = (int *)operandA;
                *(undefined1 *)((int)&local_278 + loopCounterD + 1) = uVar2;
                ppiVar5[-1] = (int *)operandB;
                *(undefined1 *)((int)&local_278 + loopCounter) = uVar1;
              }
              loopCounter = loopCounter + 1;
              ppiVar5 = ppiVar5 + 1;
              loopCounterD = loopCounterD + 1;
            }
            moreToSort = 0 < iVar7;
            iVar7 = iVar7 + -1;
          } while (moreToSort);
          loopCounterC = 0;
          iVar15 = uniqueCount;
          do {
            auStack_284[*(byte *)((int)&local_278 + loopCounterC)] = (char)loopCounterC;
            loopCounterC = loopCounterC + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        loopCounterD = 0;
        loopCounterC = 4;
        do {
          *(undefined1 *)((int)&local_280 + loopCounterD) =
               auStack_284[*(byte *)((int)&local_27c + loopCounterD)];
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
          loadConstSource = ((int (*)())FUN_000f5248)(*(undefined4 *)(program + 0x3ac),loadConst4Op0Kind,loadConst4Op0Value,loadConst4Op0Word2,
                               loadConst4Op0Word3,loadConst4Op0Word4,loadConst4Op0Word5,loadConst4Op1Kind);
          programFlags = *(uint *)(program + 0x30);
        }
        IRInst__setOperandSource(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),loadConstSource,programFlags >> 7 & 1,compiler);
LAB_000f76c8:
        operandRecordB = IRInst__getOperandRecord(inst,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
        *(undefined4 *)(operandRecordB + 0x10) = local_280;
        return;
      }
    } while (uniqueCount < 0);
    if (uniqueCount != 0) {
      piVar9 = *ppiVar5;
      loopCounter = 0;
      while ((*operandPtrTable[loopCounter + 3] != *piVar9 || (operandPtrTable[loopCounter + 3][1] != piVar9[1]))) {
        loopCounter = loopCounter + 1;
        if (uniqueCount < loopCounter) goto LAB_000f6f58;
        if (loopCounter == uniqueCount) goto LAB_000f6f18;
      }
      *(char *)((int)&local_27c + iVar11 + 1) = (char)loopCounter;
      goto LAB_000f6f58;
    }
    piVar9 = *ppiVar5;
  } while( true );
}

/* IRInst__makeLiteralVec4Int @ 0xf771c (340 bytes) */
int IRInst__makeLiteralVec4Int(param_1, program, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 program;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  return ((int (*)())IRInst__setConstantOperand)(param_1,program,param_3,1,param_4,local_b0,local_ac,local_a8,local_a4,1,param_5,
               local_98,local_94,local_90,local_8c,1,param_6,local_80,local_7c,local_78,local_74,1,param_7);
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
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  return ((int (*)())IRInst__setConstantOperand)(inst,program,operandIndex,3,value0,local_b0,local_ac,local_a8,local_a4,3,value1,
               local_98,local_94,local_90,local_8c,3,value2,local_80,local_7c,local_78,local_74,3,value3);
}

/* the raw 32-bit pattern of a float, as the stock passes it in a general register / stack word (`stfs f1,0xec(r1); lwz r7,0xec(r1)`) */
#ifndef FBITS
#define FBITS(x) ({ float fbits_ = (float)(x); *(unsigned int *)&fbits_; })
#endif
/* IRInst__makeLiteralVec4Float @ 0xf79c4 (332 bytes) */
void IRInst__makeLiteralVec4Float(undefined4 param_1,undefined4 param_2,undefined4 param_3,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4)
{
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  ((int (*)())IRInst__setConstantOperand)(param_1,param_2,param_3,2,FBITS(staleFprArg1),local_a0,local_9c,local_98,local_94,2,
               FBITS(staleFprArg2),local_88,local_84,local_80,local_7c,2,FBITS(staleFprArg3),local_70,
               local_6c,local_68,local_64,2,FBITS(staleFprArg4));
  return;
}

/* FUN_000f7b10 @ 0xf7b10 (228 bytes) */
int FUN_000f7b10(vector, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *vector;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  uint uVar2;
  uint loopIndex;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uVar2 = 0;
  if (vector[1] != 0) {
    loopIndex = 0;
    uVar2 = vector[1];
    iStack0000001c = param_2;
    iStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    do {
      if (loopIndex < *vector) {
        if (uVar2 <= loopIndex) {
          _memset(uVar2 * 4 + vector[2],0,(loopIndex - uVar2) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        puVar1 = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        puVar1 = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      if ((*(int *)*puVar1 == param_2) && (((int *)*puVar1)[1] == param_3)) {
        return loopIndex;
      }
      uVar2 = vector[1];
      loopIndex = loopIndex + 1;
    } while (loopIndex < uVar2);
  }
  return uVar2;
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
  int iVar1;
  int *piVar2;
  int iVar3;
  uint loopIndex;
  int iVar5;
  int iVar6;
  int loopCounter;
  int loopCounterB;
  uint loopIndex2;
  uint uVar10;
  
  piVar2 = (int *)Program__getBlocksArray(*(undefined4 *)(domInfo + 0x20));
  if (*(int *)(domInfo + 0x1c) != 0) {
    loopIndex = 1;
    do {
      piVar2 = piVar2 + 1;
      iVar6 = *piVar2;
      iVar5 = *(int *)(iVar6 + 0xe4);
      loopCounter = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4); loopIndex2 = loopIndex2 + 1) {
        iVar3 = *(int *)(loopCounter + *(int *)(*(int *)(iVar6 + 0xd0) + 8));
        if ((iVar3 != 0) && (iVar5 != *(int *)(*(int *)(iVar3 + 0xe4) * 4 + *(int *)(domInfo + 8))))
        {
          FUN_000e910c(iVar6,iVar3);
        }
        loopCounter = loopCounter + 4;
      }
      loopCounter = 0;
      for (loopIndex2 = 1; loopIndex2 <= *(uint *)(*(int *)(iVar6 + 0xf4) + 4); loopIndex2 = loopIndex2 + 1) {
        loopCounterB = 0;
        iVar3 = *(int *)(loopCounter + *(int *)(*(int *)(iVar6 + 0xf4) + 8));
        for (uVar10 = 1; iVar1 = *(int *)(iVar3 + 0xf8), uVar10 <= *(uint *)(iVar1 + 4);
            uVar10 = uVar10 + 1) {
          iVar1 = *(int *)(loopCounterB + *(int *)(iVar1 + 8));
          if (iVar5 != *(int *)(*(int *)(iVar1 + 0xe4) * 4 + *(int *)(domInfo + 8))) {
            FUN_000e910c(iVar6,iVar1);
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
  int iVar1;
  int *allocation;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  *(int *)(domInfo[8] + 0x474) = *(int *)(domInfo[8] + 0x474) + 1;
  arena = *(int *)(domInfo[9] + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  puVar5 = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  *(undefined4 *)(rootBlock + 0xe4) = 1;
  *(undefined4 *)(*domInfo + 4) = 0;
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[6]) = rootBlock;
  uVar7 = allocation[2];
  if (uVar7 < (uint)allocation[1]) {
    _memset((void *)(uVar7 * 4 + allocation[3]),0,4);
    allocation[2] = uVar7 + 1;
    piVar3 = (int *)(uVar7 * 4 + allocation[3]);
  }
  else {
    piVar3 = (int *)Vector__elementRefGrow(puVar5,uVar7);
  }
  *piVar3 = rootBlock;
  loopCounter = 2;
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[1]) = *(int *)(rootBlock + 0xe4);
  *(int *)(*(int *)(rootBlock + 0xe4) * 4 + domInfo[4]) = *(int *)(rootBlock + 0xe4);
  while( true ) {
    while( true ) {
      iVar4 = FUN_000e80cc(rootBlock,*(undefined4 *)(domInfo[8] + 0x474));
      if (iVar4 == 0) break;
      uVar7 = allocation[2];
      if (uVar7 < *puVar5) {
        _memset((void *)(uVar7 * 4 + allocation[3]),0,4);
        allocation[2] = uVar7 + 1;
        piVar3 = (int *)(uVar7 * 4 + allocation[3]);
      }
      else {
        piVar3 = (int *)Vector__elementRefGrow(puVar5,uVar7);
      }
      *piVar3 = iVar4;
      iVar1 = loopCounter * 4;
      *(int *)(iVar4 + 0xe4) = loopCounter;
      loopCounter = loopCounter + 1;
      *(undefined4 *)(iVar1 + *domInfo) = *(undefined4 *)(rootBlock + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + domInfo[6]) = iVar4;
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(domInfo[8] + 0x474);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + domInfo[1]) = *(int *)(iVar4 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + domInfo[4]) = *(int *)(iVar4 + 0xe4);
      rootBlock = iVar4;
    }
    uVar7 = allocation[2];
    if (uVar7 == 0) break;
    piVar3 = (int *)0x0;
    if (uVar7 - 1 < uVar7) {
      piVar3 = (int *)((uVar7 - 1) * 4 + allocation[3]);
    }
    rootBlock = *piVar3;
    Vector__removeAt(puVar5,uVar7 - 1);
  }
  if (puVar5 != (uint *)0x0) {
    Arena__free(allocation[4],allocation[3]);
    iVar6 = *allocation;
    if ((*(int *)(iVar6 + 0x28) != 0) && (piVar3 = *(int **)(iVar6 + 0x14), piVar3 == allocation)) {
      _memset(piVar3,0,*(int *)(iVar6 + 8) - (int)piVar3);
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 0x14);
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
  int vectorData;
  int arena;
  int iVar1;
  uint uVar2;
  int *allocation;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  
  arena = *(int *)(*(int *)(domInfo + 0x24) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x14);
  puVar8 = (uint *)(allocation + 1);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  iVar9 = *(int *)(domInfo + 0xc);
  while (*(int *)(*(int *)(vertex * 4 + iVar9) * 4 + iVar9) != 0) {
    uVar2 = allocation[2];
    if (uVar2 < *puVar8) {
      _memset((void *)(uVar2 * 4 + allocation[3]),0,4);
      piVar4 = (int *)(uVar2 * 4 + allocation[3]);
      allocation[2] = uVar2 + 1;
    }
    else {
      piVar4 = (int *)Vector__elementRefGrow(puVar8,uVar2);
    }
    *piVar4 = vertex;
    iVar9 = *(int *)(domInfo + 0xc);
    vertex = *(int *)(vertex * 4 + iVar9);
  }
  while (allocation[2] != 0) {
    uVar2 = allocation[2] - 1;
    piVar4 = (int *)0x0;
    if (uVar2 < (uint)allocation[2]) {
      piVar4 = (int *)(uVar2 * 4 + allocation[3]);
    }
    iVar9 = *piVar4;
    Vector__removeAt(puVar8,allocation[2] - 1);
    iVar6 = *(int *)(domInfo + 0xc);
    iVar9 = iVar9 * 4;
    iVar7 = *(int *)(domInfo + 0x10);
    iVar1 = *(int *)(iVar6 + iVar9) * 4;
    iVar5 = *(int *)(iVar7 + iVar1);
    if (*(uint *)(iVar5 * 4 + *(int *)(domInfo + 4)) <
        *(uint *)(*(int *)(iVar9 + iVar7) * 4 + *(int *)(domInfo + 4))) {
      *(int *)(iVar9 + iVar7) = iVar5;
      iVar6 = *(int *)(domInfo + 0xc);
    }
    *(undefined4 *)(iVar9 + iVar6) = *(undefined4 *)(iVar1 + iVar6);
  }
  if (puVar8 == (uint *)0x0) {
    return;
  }
  Arena__free(allocation[4],allocation[3]);
  iVar9 = *allocation;
  if ((*(int *)(iVar9 + 0x28) != 0) && (piVar4 = *(int **)(iVar9 + 0x14), piVar4 == allocation)) {
    _memset(piVar4,0,*(int *)(iVar9 + 8) - (int)piVar4);
    *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(iVar9 + 0x14);
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
  FUN_000ec468(domInfo[8],domInfo[6],domInfo[7]);
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
        FUN_000e8ce4(idomBlock,vertexBlock);
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

/* FUN_000f88b4 @ 0xf88b4 (104 bytes) */
int FUN_000f88b4(param_1)
  int param_1;
{
  int arena;
  int *allocation;
  int *piVar2;
  int iVar3;
  
  arena = *(int *)(*(int *)(param_1 + 8) + 0x378);
  allocation = (int *)Arena__alloc(arena,0x2c);
  *allocation = arena;
  piVar2 = allocation + 1;
  ((int (*)())DominatorTree__ctor_f7cd8)(piVar2,param_1);
  ((int (*)())DominatorTree__compute)(piVar2);
  if (piVar2 == (int *)0x0) {
    return;
  }
  ((int (*)())DominatorTree__free)(piVar2);
  iVar3 = *allocation;
  if ((*(int *)(iVar3 + 0x28) != 0) && (piVar2 = *(int **)(iVar3 + 0x14), piVar2 == allocation)) {
    _memset(piVar2,0,*(int *)(iVar3 + 8) - (int)piVar2);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
  }
  return;
}

/* FUN_000f8960 @ 0xf8960 (16 bytes) */
int FUN_000f8960(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 8);
}

/* FUN_000f8970 @ 0xf8970 (16 bytes) */
int FUN_000f8970(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 4);
}

/* FUN_000f8980 @ 0xf8980 (20 bytes) */
int FUN_000f8980(ilOpcode, param_2, param_3)
  int ilOpcode;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + ilOpcode * 0x24 + param_3 + 0x1c);
}

/* FUN_000f8994 @ 0xf8994 (16 bytes) */
int FUN_000f8994(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0xc);
}

/* FUN_000f89a4 @ 0xf89a4 (16 bytes) */
int FUN_000f89a4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0x10);
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
  uint uVar1;
  int *a4;
  undefined4 staleArgR8;
  uint uVar2;
  uint uVar3;
  char local_38 [32];
  
  local_38[0] = '\0';
  local_38[1] = 1;
  local_38[2] = 2;
  local_38[3] = 3;
  uVar3 = *selectWordPtr;
  a4 = inst;
  if (descriptor != (uint *)0x0) {
    uVar2 = *descriptor;
    if ((uVar2 & 0x400000) != 0) {
      uVar1 = descriptor[1];
      if ((uVar1 >> 3 & 1 & uVar1 >> 7 & 1 & uVar1 >> 0xb & 1 & uVar1 >> 0xf & 1) != 0) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
        uVar2 = *descriptor;
      }
    }
    if (((uVar2 & 0x400000) != 0) && ((descriptor[1] & 0x100000) != 0)) {
      IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,2,1);
    }
    local_38[0] = psnPackedLaneSource(descriptor,0);
    local_38[1] = psnPackedLaneSource(descriptor,1);
    local_38[2] = psnPackedLaneSource(descriptor,2);
    local_38[3] = psnPackedLaneSource(descriptor,3);
  }
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,0,(int)local_38[uVar3 >> 0x18],a4,staleArgR8,*(code **)(*inst + 0x88));
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,1,(int)local_38[uVar3 >> 0x10 & 0xff],a4,staleArgR8,
             *(code **)(*inst + 0x88));
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,2,(int)local_38[uVar3 >> 8 & 0xff],a4,staleArgR8,*(code **)(*inst + 0x88)
            );
  (**(code **)(*inst + 0x88))
            (inst,operandIndex,3,(int)local_38[uVar3 & 0xff],a4,staleArgR8,*(code **)(*inst + 0x88));
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

/* FUN_000f8ccc @ 0xf8ccc (132 bytes) */
int FUN_000f8ccc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xdc))
                    (*(int **)(param_2 + 0x30c),param_2,param_3);
  if (iVar1 == 0) {
    puVar2 = (PTR_DAT_001e9f7c)[param_1 * 3];
  }
  else if (param_3 == 0) {
    puVar2 = (PTR_DAT_001e9f80)[param_1 * 3];
  }
  else {
    puVar2 = (PTR_DAT_001e9f78)[param_1 * 3];
  }
  return puVar2;
}

/* IRInst__applyDescriptorSelects @ 0xf8d50 (568 bytes) */
int IRInst__applyDescriptorSelects(program, param_2, overrideSelects, descriptor, param_5, inst, forceOnes)
  int program;
  undefined4 param_2;
  undefined4 overrideSelects;
  uint *descriptor;
  undefined4 param_5;
  int inst;
  int forceOnes;
{
  int laneComponent;
  int hwHasFeature;
  undefined4 registerFileB;
  int loopCounter;
  int registerFile;
  unsigned int ghidra_home[8] = { program, param_2, overrideSelects, descriptor, param_5, inst, forceOnes, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
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

/* FUN_000f9038 @ 0xf9038 (264 bytes) */
int FUN_000f9038(param_1, param_2, list)
  int param_1;
  undefined4 param_2;
  undefined4 list;
{
  undefined4 inst;
  int operandRecord;
  double dVar3;
  
  inst = IRInst__create(0x17,*(undefined4 *)(param_1 + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  operandRecord = IRInst__getOperandRecord(inst,1);
  dVar3 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,dVar3,dVar3,dVar3,dVar3);
  DList__pushBack(list,inst);
  inst = IRInst__create(0x19,*(undefined4 *)(param_1 + 8));
  operandRecord = IRInst__getOperandRecord(inst,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  operandRecord = IRInst__getOperandRecord(inst,1);
  dVar3 = (double)FLOAT_001aa0e8;
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = param_2;
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,param_1,2,dVar3,dVar3,dVar3,dVar3);
  DList__pushBack(list,inst);
  return inst;
}

/* FUN_000f9140 @ 0xf9140 (284 bytes) */
int FUN_000f9140(program, ilOpcode, param_3)
  int program;
  int ilOpcode;
  int param_3;
{
  int *a0;
  int iVar1;
  undefined4 opcodeInfo;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0xc);
  iVar3 = (**(code **)(ilOpcode * 0x24 + iVar3 + 0x14))
                    (*(undefined4 *)(ilOpcode * 0x24 + iVar3),*(int *)(program + 8),param_3,staleArgR6,
                     staleArgR7,staleArgR8,iVar3);
  if ((param_3 != 0) &&
     (a0 = *(int **)(*(int *)(program + 8) + 0x30c), iVar1 = (**(code **)(*a0 + 0xb0))(a0),
     iVar1 != 0)) {
    switch(ilOpcode) {
    case 0x22:
      opcodeInfo = Opcode__getInfo(0xdf);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x23:
      opcodeInfo = Opcode__getInfo(0xde);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x40:
      opcodeInfo = Opcode__getInfo(0xf0);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x41:
      opcodeInfo = Opcode__getInfo(0xb7);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x44:
      opcodeInfo = Opcode__getInfo(0xb8);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
      break;
    case 0x49:
      opcodeInfo = Opcode__getInfo(0xb6);
      *(undefined4 *)(iVar3 + 0x88) = opcodeInfo;
    }
  }
  return iVar3;
}

/* Program__appendInst @ 0xf92fc (480 bytes) */
int Program__appendInst(program, inst, block)
  int program;
  int *inst;
  undefined4 block;
{
  int operandRecord;
  uint uVar1;
  int iVar2;
  int *piVar3;
  void *inst2;
  int newTempIndex;
  int iVar6;
  int iVar7;
  
  iVar2 = (**(code **)(*inst + 0x30))(inst,inst,block);
  if ((iVar2 != 0) &&
     (piVar3 = *(int **)(*(int *)(program + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar3 + 0x168))(piVar3,program,inst), iVar2 != 0)) {
    inst2 = IRInst__create(0x13,*(undefined4 *)(program + 8));
    newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex;
    uVar1 = inst[0x4d];
    ((int (*)())IRInst__makeLiteralVec4Int)(inst2,program,1,uVar1 & 0xffff | 0x60000,uVar1 & 0xffff | 0x70000,
                 uVar1 & 0xffff | 0x70000,uVar1 & 0xffff | 0x70000);
    iVar6 = inst[0x2b];
    iVar7 = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,2);
    *(int *)(operandRecord + 0xc) = iVar7;
    *(int *)(operandRecord + 8) = iVar6;
    ((int (*)())Program__appendInst)(program,inst2,block);
    inst2 = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord = IRInst__getOperandRecord(inst2,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newTempIndex;
    *(undefined4 *)((int)inst2 + 0x9c) = 0x1010000;
    iVar6 = inst[0x2b];
    iVar7 = inst[0x2c];
    operandRecord = IRInst__getOperandRecord(inst2,1);
    *(int *)(operandRecord + 8) = iVar6;
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
int FUN_000f94dc(program, list, descriptor, param_4, param_5, param_6, param_7)
  int program;
  undefined4 list;
  uint *descriptor;
  undefined4 param_4;
  undefined4 param_5;
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
  *(undefined4 *)(operandRecord2 + 8) = param_5;
  *(undefined4 *)((int)inst + 0x9c) = 0x10101;
  operandRecord2 = IRInst__getOperandRecord(inst,1);
  *(undefined4 *)(operandRecord2 + 0xc) = 0x3a;
  *(int *)(operandRecord2 + 8) = inputTempId;
  IRInst__appendSource(inst,*(undefined4 *)(*(int *)(program + 0x374) + 0x8c));
  DList__pushBack(list,inst);
  return;
}

/* FUN_000f9a58 @ 0xf9a58 (2736 bytes) */
int FUN_000f9a58(pass, list, descriptor, param_4, param_5)
  int pass;
  undefined4 list;
  uint *descriptor;
  undefined4 param_4;
  int param_5;
{
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
  bool bVar1;
  bool bVar2;
  void *writeMaskCursor;
  void *setupInst;
  int iVar5;
  undefined4 registerFile;
  undefined4 *allocation;
  int destRegisterIndex;
  uint *sourceDescriptor;
  uint destRegisterType;
  uint uVar11;
  uint uVar12;
  int newTempIndex2;
  uint uVar14;
  code *pcVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined4 uVar19;
  int iVar20;
  undefined4 *puVar21;
  double staleFprArg1;
  undefined4 local_68;
  undefined4 local_64 [7];
  
  destRegisterIndex = (int)(short)*descriptor;
  destRegisterType = *descriptor >> 0x10 & 0x3f;
  if (((*descriptor & 0x400000) == 0) || (uVar14 = descriptor[1] >> 9 & 0xf, uVar14 == 0)) {
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
    staleFprArg1 = (double)*(float *)(&DAT_001aa9fc + uVar14 * 4);
    *(int *)(operandRecord2 + 8) = laneIndex;
    ((void (*)())IRInst__makeLiteralVec4Float)(setupInst,pass,2,staleFprArg1,staleFprArg1,staleFprArg1,staleFprArg1);
    DList__pushBack(list,setupInst);
  }
  uVar14 = 0;
  loopCounter = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,loopCounter);
    bVar1 = loopCounter != 3;
    uVar14 = uVar14 | (uint)(psnPackedLaneComponentResult == 2) << (loopCounter & 0x3f);
    loopCounter = loopCounter + 1;
  } while (bVar1);
  if (uVar14 != 0) {
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
      if (((int)uVar14 >> (loopCounter & 0x3f) & 1U) == 0) {
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
  uVar14 = 0;
  loopCounter = 0;
  do {
    psnPackedLaneComponentResult = psnPackedLaneComponent(descriptor,loopCounter);
    bVar1 = loopCounter != 3;
    uVar14 = uVar14 | (uint)(psnPackedLaneComponentResult == 3) << (loopCounter & 0x3f);
    loopCounter = loopCounter + 1;
  } while (bVar1);
  if (uVar14 != 0) {
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
      if (((int)uVar14 >> (loopCounter & 0x3f) & 1U) == 0) {
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
  uVar14 = 0;
  if ((*descriptor & 0x400000) != 0) {
    uVar14 = descriptor[1];
    uVar14 = (uint)((uVar14 & 0xc0) == 0) |
             (uint)((uVar14 & 0x30) == 0) << 8 |
             (uint)((uVar14 & 0xc) == 0) << 0x10 | (uint)((uVar14 & 3) == 0) << 0x18;
  }
  iVar5 = FUN_0019eb30(descriptor);
  if (iVar5 != 0) {
    setupInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(setupInst,0);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    operandRecord2 = IRInst__getOperandRecord(setupInst,1);
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    *(int *)(operandRecord2 + 8) = laneIndex;
    DList__pushBack(list,setupInst);
  }
  uVar17 = *descriptor;
  if (((uVar17 & 0x400000) == 0) || ((descriptor[1] & 0x100) == 0)) {
LAB_000f9f08:
    bVar1 = false;
  }
  else {
    piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
    pcVar15 = *(code **)(*piVar18 + 0x78);
    registerFile = Program__registerFileOfIlType(pass,destRegisterType);
    iVar5 = (*pcVar15)(piVar18,registerFile);
    if (iVar5 == 0) {
      destRegisterFile = Program__registerFileOfIlType(pass,*descriptor >> 0x10 & 0x3f);
      if (destRegisterFile == 9) {
        uVar17 = *descriptor;
        goto LAB_000f9f08;
      }
      Program__registerFileOfIlType(pass,*descriptor >> 0x10 & 0x3f);
      uVar17 = *descriptor;
      bVar1 = false;
    }
    else {
      piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
      iVar5 = (**(code **)(*piVar18 + 0x80))(piVar18);
      if (iVar5 == 0) {
        if (setupInst == (void *)0x0) {
          laneIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(pass + 8) + 0x3ac) = laneIndex;
          *(short *)((int)descriptor + 2) = (short)laneIndex;
          *descriptor = *descriptor & 0xffc0ffff | 0x40000;
        }
        setupInst = (void *)((int (*)())FUN_000f9038)(pass,laneIndex,list);
        uVar17 = *descriptor;
        if ((uVar17 & 0x400000) == 0) goto LAB_000f9f08;
        bVar1 = false;
        descriptor[1] = descriptor[1] & 0xfffffeff;
      }
      else {
        uVar17 = *descriptor;
        bVar1 = true;
      }
    }
  }
  if (setupInst != (void *)0x0) {
    if ((uVar17 & 0x1800000) == 0x800000) {
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
    if (bVar1) {
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
      bVar1 = laneIndex != 3;
      setupInst = (void *)((int)setupInst + 1);
      laneIndex = laneIndex + 1;
    } while (bVar1);
    uVar17 = *descriptor;
    if ((uVar17 & 0x400000) != 0) {
      descriptor[1] = descriptor[1] & 0xffffff00 | 0x55;
    }
  }
  if ((destRegisterType != 0x1f) || ((*(uint *)(pass + 0x30) & 0x4000) == 0)) {
    bVar1 = false;
    bVar2 = false;
  }
  else {
    bVar1 = true;
    bVar2 = true;
  }
  if (((undefined4 *)(uVar17 & 0x3f0000) != 0x001b0000) && (!bVar1)) goto LAB_000fa744;
  sourceNumber = 1;
  newTempIndex = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex;
  uVar17 = *descriptor;
  uVar12 = (uint)(ushort)*descriptor;
  uVar11 = uVar17 >> 0x10 & 0x3f;
  if ((int)uVar17 < 0) {
    sourceNumber = 2;
    uVar12 = uVar12 | descriptor[1] << 0x10;
  }
  if ((uVar17 & 0x400000) != 0) {
    sourceNumber = sourceNumber + 1;
  }
  if ((uVar17 & 0x1800000) == 0x1000000) {
    sourceDescriptor = descriptor + sourceNumber;
    if (!bVar2) {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      puVar21 = allocation + 1;
      IRMemStore__ctor_1071fc(puVar21,0xfc,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,uVar11);
      operandRecord3 = IRInst__getOperandRecord(puVar21,0);
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(uint *)(operandRecord3 + 8) = uVar12;
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord3 = IRInst__getOperandRecord(puVar21,1);
      allocation[0x28] = uVar14;
      *(undefined4 *)(operandRecord3 + 0xc) = registerFile;
      *(int *)(operandRecord3 + 8) = newTempIndex;
      if ((*descriptor & 0x4000000) == 0) goto LAB_000fa1bc;
      newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
      uVar17 = descriptor[sourceNumber + 2];
      newInst = IRInst__create(0xc6,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(newInst,0);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex2;
      uVar14 = *sourceDescriptor;
      registerFile = Program__registerFileOfIlType(pass,*sourceDescriptor >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(newInst,1);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = (uint)(ushort)uVar14;
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,uVar17,uVar17,uVar17,uVar17);
      DList__pushBack(list,newInst);
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(puVar21,2);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex2;
    }
    else {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      puVar21 = allocation + 1;
      IRGeomExport__ctor_108a50(puVar21,0xf9,*(undefined4 *)(pass + 8));
      allocation[0x28] = uVar14;
      allocation[0x22] = 2;
      if ((*descriptor & 0x4000000) != 0) {
        uVar12 = uVar12 + descriptor[sourceNumber + 2];
      }
      allocation[0x51] = uVar12;
      allocation[0x50] = 0x24;
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(puVar21,0,virtualRegister);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex;
LAB_000fa1bc:
      uVar14 = *sourceDescriptor;
      registerFile = Program__registerFileOfIlType(pass,*sourceDescriptor >> 0x10 & 0x3f);
      operandRecord = IRInst__getOperandRecord(puVar21,2);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = (uint)(ushort)uVar14;
      if (bVar2) goto LAB_000fa4f8;
    }
    registerFile = Program__registerFileOfIlType(pass,uVar11);
    operandRecord = IRInst__getOperandRecord(puVar21,3);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(uint *)(operandRecord + 8) = uVar12;
    local_64[0] = 0x10203;
    ((int (*)())Program__applySourceTokenToOperand)(pass,local_64,sourceDescriptor,2,puVar21);
  }
  else if ((uVar17 & 0x1800000) == 0) {
    uVar16 = 0;
    if ((uVar17 & 0x4000000) != 0) {
      uVar16 = descriptor[sourceNumber];
    }
    if (bVar2) {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      puVar21 = allocation + 1;
      IRGeomExport__ctor_108770(puVar21,*(undefined4 *)(pass + 8));
      allocation[0x28] = uVar14;
      allocation[0x50] = 0x24;
      allocation[0x51] = uVar12;
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(*(int *)(*(int *)(pass + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      IRInst__setOperandRef(puVar21,0,virtualRegister);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex;
    }
    else {
      arenaA = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
      allocation = (undefined4 *)Arena__alloc(arenaA,0x168);
      *allocation = arenaA;
      puVar21 = allocation + 1;
      IRMemStore__ctor_1071fc(puVar21,0xfc,*(undefined4 *)(pass + 8));
      registerFile = Program__registerFileOfIlType(pass,uVar11);
      operandRecord = IRInst__getOperandRecord(puVar21,0);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(uint *)(operandRecord + 8) = uVar12;
      registerFile = Program__registerFileOfIlType(pass,4);
      operandRecord = IRInst__getOperandRecord(puVar21,1);
      *(undefined4 *)(operandRecord + 0xc) = registerFile;
      *(int *)(operandRecord + 8) = newTempIndex;
      ((int (*)())IRInst__setIntConstantOperand4)(puVar21,pass,2,uVar16,uVar16,uVar16,uVar16);
      allocation[0x28] = uVar14;
    }
  }
  else {
    puVar21 = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  operandRecord = IRInst__getOperandRecord(puVar21,2);
  local_68 = *(undefined4 *)(operandRecord + 0x10);
  piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c);
  iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,2,&local_68,0);
  if (iVar20 == 0) {
    newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    uVar19 = puVar21[0x32];
    instWord0xc4 = puVar21[0x31];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = uVar19;
    *(undefined4 *)(operandRecord + 8) = instWord0xc4;
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(puVar21,2);
    operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
    DList__pushBack(list,newInst);
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(puVar21,2);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    iVar20 = IRInst__getOperandRecord(puVar21,2);
    *(undefined4 *)(iVar20 + 0x10) = 0;
  }
  if ((!bVar2) &&
     (piVar18 = *(int **)(*(int *)(pass + 8) + 0x30c),
     iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,1,&local_68,0), iVar20 == 0)) {
    newTempIndex2 = *(int *)(*(int *)(pass + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(pass + 8) + 0x3ac) = newTempIndex2;
    newInst = IRInst__create(0x31,*(undefined4 *)(pass + 8));
    uVar19 = puVar21[0x2c];
    instWord0xac = puVar21[0x2b];
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0xc) = uVar19;
    *(undefined4 *)(operandRecord + 8) = instWord0xac;
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(newInst,0);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    operandSelectWord = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newInst,1);
    *(undefined4 *)(operandRecord + 0x10) = operandSelectWord;
    DList__pushBack(list,newInst);
    registerFile = Program__registerFileOfIlType(pass,4);
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    *(undefined4 *)(operandRecord + 0xc) = registerFile;
    *(int *)(operandRecord + 8) = newTempIndex2;
    operandRecord = IRInst__getOperandRecord(puVar21,1);
    *(undefined4 *)(operandRecord + 0x10) = 0x10203;
  }
  DList__pushBack(list,puVar21);
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
    if (param_5 == 1) {
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,1,1,1,1);
    }
    else if (param_5 < 2) {
      if (param_5 == 0) {
        ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,0,0,0,0);
      }
    }
    else if (param_5 == 2) {
      ((int (*)())IRInst__setIntConstantOperand4)(newInst,pass,2,2,2,2,2);
    }
    else if (param_5 == 3) {
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

/* FUN_000fa958 @ 0xfa958 (1132 bytes) */
int FUN_000fa958(program, opcodeIndex, operandIndex, translateState, inst, param_6, param_7, param_8, param_9, param_10, block)
  int program;
  int opcodeIndex;
  int operandIndex;
  int translateState;
  int inst;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
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
  undefined4 uVar2;
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
  undefined4 local_44;
  
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
      local_44 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_44) + 0)),(short)*descriptor);
      local_44 = *descriptor & 0x1800000 | *descriptor & 0x3f0000 | local_44 & 0xfe40ffff;
      descriptor = &local_44;
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
      ((int (*)())Program__applySourceTokenToOperand)(program,param_8,descriptor,operandIndex,newInst2);
      ((int (*)())Program__appendInst)(program,newInst2,block);
      registerType = 4;
      *descriptor = *descriptor & 0xfe3fffff;
      *(short *)((int)descriptor + 2) = (short)splitTempIndex;
      *descriptor = *descriptor & 0xffc0ffff | 0x40000;
      registerIndex = splitTempIndex;
    }
    else {
      ((int (*)())Program__applySourceTokenToOperand)(program,param_8,sourceDescriptorPtr,operandIndex,inst);
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
  uVar2 = 0;
  *(int *)(operandRecord + 8) = registerIndex2;
  foldedResult = inst;
  ((int (*)())IRInst__applyDescriptorSelects)(program,param_9,param_7,destDescriptor,0,inst,param_10);
  foldedResult = OpcodeTraits__instFlagBit2_113734(*(undefined4 *)(program + 8),inst,param_7,destDescriptor,uVar2,foldedResult,param_10);
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
      local_44 = DAT_001aa9e0;
      *(undefined1 *)((int)&local_44 + resultInst) = 0;
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
      *(uint *)(inst + 0x9c) = local_44;
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
  ((int (*)())FUN_000fa958)(program,5,1,sourceArg,inst,1,DAT_001aa9dc,local_48,scopeStack,1,ifHeader);
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
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  programKindSet = *(uint *)(program + 0x30) & 1 | *(uint *)(program + 0x30) >> 0xe & 1;
  boolConstCount = FUN_000d9fc0(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < boolConstCount) {
    constIndex = 0;
    do {
      FUN_000da070(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,1,&local_48);
      ILReader__appendBoolConst(ilReader,constIndex,(uint)(local_48 != 0));
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,0,constIndex,1,&local_48);
      constIndex = nextConstIndex;
    } while (boolConstCount != nextConstIndex);
  }
  intConstCount = FUN_000d9fa0(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < intConstCount) {
    constIndex = 0;
    do {
      FUN_000da028(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,4,&local_48);
      ILReader__appendIntConst(ilReader,constIndex,local_48,local_44,local_40,local_3c);
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,2,constIndex,4,&local_48);
      constIndex = nextConstIndex;
    } while (intConstCount != nextConstIndex);
  }
  floatConstCount = FUN_000d9f80(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet);
  if (0 < floatConstCount) {
    constIndex = 0;
    do {
      FUN_000d9fe0(*(undefined4 *)(*(int *)(program + 8) + 0x398),programKindSet,constIndex,4,&local_38);
      ((void (*)())ILReader__appendFloatConst)(ilReader,constIndex,(double)local_38,(double)local_34,(double)local_30,(double)local_2c
                  );
      nextConstIndex = constIndex + 1;
      ((int (*)())Program__createConstantVReg)(program,1,constIndex,4,&local_38);
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
      virtualRegister = FUN_000e7d5c(iVar20);
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

/* FUN_000fd50c @ 0xfd50c (188 bytes) */
int FUN_000fd50c(program, param_2, templateCursorPtr, param_4, param_5, vector)
  int program;
  undefined4 param_2;
  undefined4 *templateCursorPtr;
  undefined4 param_4;
  undefined4 param_5;
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
  allocation[1] = param_2;
  templateCursor = *templateCursorPtr;
  allocation[3] = param_4;
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
  return param_5;
}

/* FUN_000fd5c8 @ 0xfd5c8 (408 bytes) */
int FUN_000fd5c8(program, ilReader)
  int program;
  uint ******ilReader;
{
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
  bool bVar1;
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
  bool bVar2;
  bool bVar3;
  byte ilRegisterIndex;
  float fVar5;
  short registerIndex2;
  ushort saturateBit;
  undefined *remapTable;
  undefined *puVar9;
  uint uVar10;
  uint *****pppppuVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *vectorAllocation;
  uint *****pppppuVar15;
  void *pvVar16;
  uint uVar17;
  int *piVar18;
  uint ******ppppppuVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  undefined2 *fetchDescriptor2;
  undefined4 registerFile27;
  undefined2 componentSelect;
  undefined4 *vectorElementSlot2;
  undefined4 *blockObject;
  uint ****ppppuVar30;
  undefined4 *puVar32;
  uint ******argR6;
  uint ******argR7;
  uint ******argR8;
  uint ***pppuVar33;
  int iVar34;
  uint *puVar35;
  int *piVar36;
  uint ******loopStackData;
  uint ******ppppppuVar38;
  uint ******ppppppuVar39;
  uint ******ppppppuVar40;
  undefined4 virtualRegisterB;
  uint ***pppuVar42;
  int iVar43;
  uint uVar44;
  uint ****ppppuVar45;
  undefined4 compilerArenaB;
  int iVar47;
  uint ******ppppppuVar48;
  uint ******ppppppuVar49;
  undefined4 uVar50;
  uint ****ppppuVar51;
  uint *****pppppuVar52;
  undefined1 *puVar53;
  double dVar54;
  uint ****scopeLevel;
  uint *****previousBlock;
  uint *****currentBlock;
  int *templateCursor;
  undefined4 stagedSelectWord;
  uint ****local_174;
  uint *****local_170;
  /* issue #64 live-repro (2nd instance, same function): DListNode__init(local_6c=auStack_16c), two lines
   * below DListNode__init(local_68=auStack_154) which already got this fix, writes the same 6-word/0x18-byte
   * sentinel-list header (see the comment on auStack_154 just below) - word[2] (self-referential "next",
   * program[2] = program+3) is what `local_164`'s four loops read as the list head, same shape as
   * local_14c's. auStack_16c was declared only 8 bytes with local_164 as a separate scalar 8 bytes in;
   * live-confirmed the pointer this yields (local_164, still holding the list head's own address) is a
   * real puVar13 but reads back as MallocPreScribble's 0xAA fill - i.e. never received the init write,
   * same root cause as local_14c's, just missed by that fix since it's a second, independent instance.
   * Merged into one 0x18-byte buffer the same way, aliased back to the original name. */
  unsigned char auStack_16c [0x18];
#define local_164 (*(int *)(auStack_16c + 0x08))
  /* issue #64 live-repro: DListNode__init (called below via local_68=auStack_154) writes program[0]
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
  undefined4 local_124;
  int local_11c;
  uint ****local_118;
  undefined4 local_104;
  int local_100;
  undefined4 local_d8;
  uint ****local_d4;
  undefined4 extraOperandTemp2;
  undefined4 extraOperandTemp1;
  undefined4 fetchResultTemp;
  uint local_c4;
  uint *****destOperandCount;
  int local_bc;
  int local_b8;
  undefined4 local_b4;
  uint *conditionStack;
  int local_ac;
  uint *****ifStack;
  uint *****local_a4;
  undefined4 *usedRegisterBitmap;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint *****local_88;
  uint *****local_84;
  uint local_80;
  uint ****local_7c;
  undefined *local_78;
  int local_74;
  undefined4 *selectWordPtr;
  undefined1 *local_6c;
  undefined1 *local_68;
  int local_64;
  undefined *local_60;
  undefined *local_5c;
  uint ****local_58;
  
  iVar34 = *(int *)(*(int *)(program + 8) + 0x30c);
  local_9c = 0;
  local_98 = 0;
  *(uint *)(iVar34 + 8) = *(uint *)(iVar34 + 8) & 0xffffffdf;
  local_94 = 0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  iVar34 = *(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50);
  uVar10 = iVar34 + 0x1fU >> 5;
  puVar13 = (undefined4 *)Arena__alloc(compilerArenaB,uVar10 * 4 + 0xc);
  usedRegisterBitmap = puVar13 + 1;
  *puVar13 = compilerArenaB;
  puVar13[1] = uVar10;
  puVar13[2] = iVar34;
  local_90 = 0;
  local_8c = 0;
  local_88 = (uint *****)0x0;
  local_84 = (uint *****)0x0;
  local_80 = 0;
  if (uVar10 != 0) {
    puVar13 = usedRegisterBitmap;
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    do {
      uVar10 = uVar10 - 1;
      puVar13[2] = 0;
      puVar13 = puVar13 + 1;
    } while (uVar10 != 0);
  }
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  puVar13 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  loopStackData = (uint ******)(puVar13 + 1);
  *puVar13 = compilerArenaB;
  puVar13[1] = 2;
  puVar13[4] = compilerArenaB;
  puVar13[2] = 0;
  vectorStorage = Arena__alloc(compilerArenaB,8);
  puVar13[3] = vectorStorage;
  scopeLevel = (uint ****)0x0;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  ifStack = (uint *****)(vectorAllocation + 1);
  *vectorAllocation = compilerArenaB;
  vectorAllocation[1] = 2;
  vectorAllocation[4] = compilerArenaB;
  vectorAllocation[2] = 0;
  pppppuVar15 = (uint *****)Arena__alloc(compilerArenaB,8);
  ifStack[2] = (uint ****)pppppuVar15;
  compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
  conditionStack = vectorAllocation + 1;
  *vectorAllocation = compilerArenaB;
  vectorAllocation[1] = 2;
  vectorAllocation[2] = 0;
  vectorAllocation[4] = compilerArenaB;
  uVar10 = Arena__alloc(compilerArenaB,8);
  conditionStack[2] = uVar10;
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
  local_5c = &DAT_001ad5d8;
  previousBlock = *(uint ******)(program + 0x3a0);
  local_128 = 0;
  local_170 = (uint *****)0x1010101;
  local_174 = (uint ****)0xffffffff;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
  movByRegister = vectorAllocation + 1;
  blockAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
  *blockAllocation = compilerArenaA;
  ppppppuVar49 = (uint ******)(blockAllocation + 1);
  Block__ctor_ea020(ppppppuVar49,*(undefined4 *)(program + 8));
  currentBlock = (uint *****)ppppppuVar49;
  Program__insertBlockAfter(program,previousBlock,ppppppuVar49);
  local_6c = auStack_16c;
  Block__connect(previousBlock,currentBlock);
  local_68 = auStack_154;
  previousBlock = currentBlock;
  DListNode__init(local_6c);
  DListNode__init(local_68);
  *(undefined4 *)(program + 0x3d4) = 0;
  *(undefined4 *)(program + 0x3e4) = 0;
  ((int (*)())Program__loadDefaultConstants)(program,ilReader);
  local_a4 = (uint *****)0x0;
  local_ac = 0;
switchD_000fdaf0_caseD_2:
  iVar34 = ILReader__nextInstruction(ilReader);
  if (iVar34 == 0) {
code_r0x00103c40:
    Program__splitMixedSourceKinds(program);
    Block__connect(currentBlock,*(undefined4 *)(program + 0x3a8));
    *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 2;
    FUN_0012e8c0(program,*(undefined4 *)(program + 0x3a0),*(undefined4 *)(program + 0x3a8));
    if ((uint ******)ifStack != (uint ******)0x0) {
      Arena__free(ifStack[3],ifStack[2]);
      Arena__free(ifStack[-1],ifStack + -1);
    }
    if (loopStackData != (uint ******)0x0) {
      Arena__free(puVar13[4],puVar13[3]);
      Arena__free(*puVar13,puVar13);
    }
    if (usedRegisterBitmap != (undefined4 *)0x0) {
      Arena__free(usedRegisterBitmap[-1],usedRegisterBitmap + -1);
    }
    Arena__free(*(undefined4 *)(*(int *)(program + 8) + 0x378),*(undefined4 *)(program + 0x78));
    FUN_0011e894(program);
    return;
  }
  iVar34 = FUN_000e43ec(ilReader);
  if (iVar34 != 0) {
    iVar34 = *(int *)(program + 0x3c4);
    loopCounterC = 0;
    templateCursor = (int *)0x0;
    for (uVar10 = 1; uVar10 <= *(uint *)(iVar34 + 4); uVar10 = uVar10 + 1) {
      templateCursor = *(int **)(loopCounterC + *(int *)(iVar34 + 8));
      if ((templateCursor[5] & 1U) != 0) {
        (**(code **)(*templateCursor + 0x68))(templateCursor);
        piVar18 = templateCursor;
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,1,templateCursor[0x29]);
        puVar12 = movByRegister;
        uVar44 = piVar18[0x50];
        if (uVar44 < *movByRegister) {
          uVar17 = movByRegister[1];
          if (uVar17 <= uVar44) {
            _memset(uVar17 * 4 + movByRegister[2],0,(uVar44 - uVar17) * 4 + 4);
            puVar12[1] = uVar44 + 1;
          }
          vectorElementSlot = (undefined4 *)(uVar44 * 4 + puVar12[2]);
        }
        else {
          vectorElementSlot = (undefined4 *)Vector__elementRefGrow(movByRegister,uVar44);
        }
        *vectorElementSlot = movFloatInst;
        iVar34 = *(int *)(program + 0x3c4);
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
  iVar47 = hwDescription[3];
  translationKind = ((int (*)())FUN_000f89a4)(ilOpcode,iVar47);
  switch(translationKind) {
  case 0:
  case 1:
    switch(ilOpcode) {
    case 0x14:
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        ppppuVar45 = *ilReader[0x1b];
        registerFile2 = Program__registerFileOfIlType(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
        compiler = *(int *)(program + 8);
        if (((((uint)*ppppuVar45 & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((*(uint *)(*(int *)(compiler + 0x30c) + 8) & 0x80) != 0)) {
          iVar47 = 0xf;
        }
        else {
          iVar47 = (int)*(short *)((int)ppppuVar45 + 2);
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
            *(int *)(program + 1000) = iVar47;
            *(undefined4 *)(program + 0x3e4) = 1;
            *(int *)(program + 0x3ec) = registerIndex + 1;
            *(int *)(program + 0x3f4) = registerFile2;
            if (((*(uint *)(program + 0x30) & 1) != 0) && (iVar47 < registerIndex + 1)) {
              do {
                argR6 = (uint ******)0x0;
                VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile2,iVar47,0);
                iVar47 = iVar47 + 1;
              } while (iVar47 < *(int *)(program + 0x3ec));
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
        *(int *)(program + 1000) = iVar47;
        *(undefined4 *)(program + 0x3e4) = 1;
        *(int *)(program + 0x3ec) = registerIndex + 1;
        *(int *)(program + 0x3f4) = registerFile2;
        if (((*(uint *)(program + 0x30) & 1) != 0) && (iVar47 < registerIndex + 1)) {
          do {
            argR6 = (uint ******)0x0;
            VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile2,iVar47,0);
            iVar47 = iVar47 + 1;
          } while (iVar47 < *(int *)(program + 0x3ec));
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
          ppppppuVar19 = (uint ******)((int)((unsigned char *)0xc) + 3);
        }
        else {
          ppppppuVar19 = (uint ******)(int)*(short *)((int)*ilReader[0x19] + 2);
        }
        registerFile = Program__registerFileOfIlType(program,ilRegisterType);
        argR6 = (uint ******)Program__laneKindOfInterpSlot(program,ilRegisterType);
        iVar34 = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar19,0);
        iVar34 = *(int *)(iVar34 + 0x38);
        IRLoadInterp__setLane(iVar34,0,(uint)*tokenWords >> 0x10 & 3,argR6,ppppppuVar19);
        IRLoadInterp__setLane(iVar34,1,(uint)*tokenWords >> 0x12 & 3,argR6,ppppppuVar19);
        IRLoadInterp__setLane(iVar34,2,(uint)*tokenWords >> 0x14 & 3,argR6,ppppppuVar19);
        argR7 = ppppppuVar19;
        IRLoadInterp__setLane(iVar34,3,(uint)*tokenWords >> 0x16 & 3,argR6,ppppppuVar19);
        firstTokenWord = *tokenWords;
        if (((uint)firstTokenWord & 0x1000000) != 0) {
          *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          firstTokenWord = *tokenWords;
        }
        *(uint *******)(iVar34 + 0x148) = ppppppuVar19;
        *(uint *)(iVar34 + 0x140) = (uint)firstTokenWord >> 0x19 & 1;
        *(undefined4 *)(iVar34 + 0x144) = registerFile;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      ppppppuVar19 = (uint ******)Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x1f);
      ppppppuVar38 = (uint ******)((uint)*tokenWords >> 0x15 & 0xff);
      if ((int)*tokenWords < 0) {
        modifierTokenWord = ilReader[0x24];
        uVar17 = (uint)modifierTokenWord >> 9 & 1;
        uVar10 = (uint)modifierTokenWord >> 8 & 1;
        uVar44 = (uint)modifierTokenWord >> 10 & 1;
        stagedSelectWord = (uint ******)
                    (CONCAT31(CONCAT21(CONCAT11((char)modifierTokenWord,(char)((uint)modifierTokenWord >> 2)),
                                       (char)((uint)modifierTokenWord >> 4)),
                              (char)((uint)modifierTokenWord >> 6)) & 0x3030303);
      }
      else {
        uVar10 = 0;
        uVar44 = 0;
        uVar17 = 0;
        stagedSelectWord = (uint ******)0x3030303;
      }
      registerIndex = (int)*(short *)((int)*ilReader[0x19] + 2);
      registerFile = Program__registerFileOfIlType(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
      iVar34 = *(int *)(program + 1000);
      if (registerIndex <= *(int *)(program + 1000)) {
        iVar34 = registerIndex;
      }
      iVar47 = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = iVar34;
      if (iVar47 <= registerIndex) {
        iVar47 = registerIndex + 1;
      }
      *(int *)(program + 0x3ec) = iVar47;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      argR6 = (uint ******)0x0;
      iVar34 = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,registerIndex,0);
      iVar34 = *(int *)(iVar34 + 0x38);
      if (uVar10 == 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
      }
      if (uVar44 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
      }
      if (uVar17 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
      }
      selectWordPtr = &stagedSelectWord;
      loopCounterC = 0;
      do {
        if (*(byte *)(loopCounterC + (int)selectWordPtr) != 0) {
          argR6 = ppppppuVar19;
          argR7 = ppppppuVar38;
          IRLoadInterp__setLane(iVar34,loopCounterC,(uint)*(byte *)(loopCounterC + (int)selectWordPtr),ppppppuVar19,
                       ppppppuVar38);
        }
        notLastIteration = loopCounterC != 3;
        loopCounterC = loopCounterC + 1;
      } while (notLastIteration);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      ilRegisterIndex = *(byte *)((int)ilReader + 0x8d);
      firstTokenWord = *tokenWords;
      iVar34 = (uint)ilRegisterIndex * 0xc;
      *(uint *)(*(int *)(program + 0x78) + iVar34) = (uint)firstTokenWord >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x50) < (int)(uint)ilRegisterIndex) {
        Compiler__fail(*(int *)(program + 8),7);
      }
      bitmapByteOffset = ilRegisterIndex >> 3 & 0x1c;
      *(uint *)((int)usedRegisterBitmap + bitmapByteOffset + 8) =
           1 << (ilRegisterIndex & 0x1f) | *(uint *)((int)usedRegisterBitmap + bitmapByteOffset + 8);
      *(uint *)(iVar34 + *(int *)(program + 0x78) + 8) = (uint)*tokenWords >> 0x1d & 1;
      hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
      iVar43 = (**(code **)(*hwDescription + 0x48))(hwDescription,program,(uint)firstTokenWord >> 0x18 & 7);
      if (iVar43 != 0) {
        *(int *)(iVar34 + *(int *)(program + 0x78) + 4) = iVar43;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      DListNode__init(&local_124);
      firstTokenWord = *tokenWords;
      argR7 = (uint ******)0x4050607;
      uVar10 = 0;
      if ((int)firstTokenWord < 0) {
        pppppuVar52 = ilReader[0x24];
        bVar1 = ((uint)pppppuVar52 & 3) != 0;
        argR7 = *(uint *******)(local_5c + -0x2bf8);
        if (bVar1) {
          argR7 = (uint ******)((uint)argR7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)bVar1;
        if (((uint)pppppuVar52 & 0xc) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        if (((uint)pppppuVar52 & 0x30) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        if (((uint)pppppuVar52 & 0xc0) != 0) {
          uVar44 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(uVar44 | (uint)argR7 & 0xffffff00);
        }
      }
      argR6 = (uint ******)*ilReader[0x19];
      if (((uint)*argR6 & 0x400000) != 0) {
        argR7 = *(uint *******)(local_5c + -0x2bf8);
        laneSelect = psnPackedLaneComponent(argR6,0);
        remapTable = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x1000000 | (uint)argR7 & 0xffffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,1);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,2);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        laneSelect = psnPackedLaneComponent(argR6,3);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          argR7 = (uint ******)(uVar10 + 4 | (uint)argR7 & 0xffffff00);
        }
      }
      registerIndex = (int)*(short *)((int)argR6 + 2);
      iVar34 = *(int *)(program + 0x3d8);
      if (registerIndex <= *(int *)(program + 0x3d8)) {
        iVar34 = registerIndex;
      }
      iVar47 = *(int *)(program + 0x3dc);
      *(int *)(program + 0x3d8) = iVar34;
      if (iVar47 <= registerIndex) {
        iVar47 = registerIndex + 1;
      }
      *(int *)(program + 0x3dc) = iVar47;
      hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
      argR8 = *(uint *******)(program + 0x3a0);
      (**(code **)(*hwDescription + 0x4c))(hwDescription,program,(uint)firstTokenWord >> 0x10 & 0x3f);
      iVar43 = *(int *)(local_11c + 8);
      iVar34 = local_11c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      local_124 = (uint *****)(PTR_DAT_001e8b48 + 8);
      local_118 = (uint ****)local_124;
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      iVar34 = Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x1f);
      ppppppuVar19 = (uint ******)((uint)*tokenWords >> 0x15 & 0xff);
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
      if (iVar34 == 0) {
        *(int *)(*(int *)(program + 0x3ac) + 0x44) = registerIndex;
      }
      else if (iVar34 == 1) {
        *(int *)(*(int *)(program + 0x3ac) + 0x48) = registerIndex;
      }
      iVar47 = *(int *)(program + 1000);
      if (registerIndex <= *(int *)(program + 1000)) {
        iVar47 = registerIndex;
      }
      iVar20 = *(int *)(program + 0x3ec);
      *(int *)(program + 1000) = iVar47;
      if (iVar20 <= registerIndex) {
        iVar20 = registerIndex + 1;
      }
      *(int *)(program + 0x3ec) = iVar20;
      *(undefined4 *)(program + 0x3f4) = 0x24;
      argR6 = (uint ******)0x0;
      virtualRegister2 = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,registerIndex,0);
      registerInfo = (**(code **)(*virtualRegister2 + 0x2c))();
      selectWordPtr = &stagedSelectWord;
      loopCounterC = 0;
      do {
        if (*(char *)(loopCounterC + (int)selectWordPtr) == '\0') {
          argR6 = ppppppuVar19;
          IRLoadInterp__setLaneKindAndIndex(registerInfo,loopCounterC,iVar34,ppppppuVar19);
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
        puVar12 = &local_124;
        ppppppuVar19 = ilReader + (int)ilReader[0x16] + 0x23;
        ppppppuVar49 = argR6;
        do {
          pppppuVar15 = *ppppppuVar19;
          ppppppuVar19 = ppppppuVar19 + 1;
          *puVar12 = (uint)pppppuVar15;
          puVar12 = puVar12 + 1;
          ppppppuVar49 = (uint ******)((int)ppppppuVar49 - 1);
        } while (ppppppuVar49 != (uint ******)0x0);
      }
      argR7 = (uint ******)&local_124;
      ((int (*)())Program__createConstantVReg)(program,(uint)destOperandToken >> 0x10 & 0x3f,(int)registerIndex2,argR6,argR7);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      piVar18 = instAllocation + 1;
      IRInst__ctor_10502c(piVar18,0x94,*(undefined4 *)(program + 8));
      virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x2f,0,0);
      IRInst__setOperandRef(piVar18,0,virtualRegister);
      instAllocation[0x4c] = 0;
      ((int (*)())Program__appendInst)(program,piVar18,currentBlock);
      bVar1 = local_ac != 0;
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,virtualRegister);
      }
      firstTokenWord = *tokenWords;
      argR6 = (uint ******)((uint)firstTokenWord >> 0x17 & 0x3f);
      if (((unsigned char *)0x4) < argR6) {
        argR6 = (uint ******)0x0;
      }
      ppppuVar45 = *ilReader[0x1b];
      registerIndex2 = *(short *)((int)ppppuVar45 + 2);
      registerFileB = Program__registerFileOfIlType(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
      source1Token = *ilReader[0x1b][1];
      if (((((uint)source1Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)ilReader[0x1b][1] + 2);
      }
      registerFile27 = Program__registerFileOfIlType(program,(uint)source1Token >> 0x10 & 0x3f);
      virtualRegisterB = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x2b,0,0);
      mulAddInst = IRInst__create(0x14,*(undefined4 *)(program + 8));
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFileB;
      *(int *)(operandRecord2 + 8) = (int)registerIndex2;
      stagedSelectWord = (uint ******)0x10203;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,ppppuVar45,1,mulAddInst);
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0;
      ((void (*)())IRInst__makeLiteralVec4Float)(mulAddInst,program,2,0.0,1.0,0.0,0.0);
      local_8c = (uint)(short)((ushort)((uint)firstTokenWord >> 0x10) & 0x3f);
      local_80 = local_8c | 0x120000;
      argR8 = (uint ******)(local_8c | 0x100000);
      argR7 = (uint ******)(local_8c | 0x110000);
      local_8c = local_8c | 0xf0000;
      local_88 = (uint *****)argR8;
      local_84 = (uint *****)argR7;
      ((int (*)())IRInst__makeLiteralVec4Int)(mulAddInst,program,3,local_80,argR7,argR8,local_8c);
      operandRecord2 = IRInst__getOperandRecord(mulAddInst,0);
      *(undefined4 *)(operandRecord2 + 0xc) = 0x2b;
      *(undefined4 *)(operandRecord2 + 8) = 0;
      ((int (*)())Program__appendInst)(program,mulAddInst,currentBlock);
      (**(code **)(*mulAddInst + 0x90))(mulAddInst,virtualRegister);
      if (bVar1) {
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
      *(int *)(operandRecord2 + 8) = iVar34;
      (**(code **)(*movInst + 0x90))(movInst,virtualRegisterB);
      ((int (*)())Program__appendInst)(program,movInst,currentBlock);
      IRInst__setHardwareRegisterAndAdd(movInst,program,0x2c,argR6);
      local_ac = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      firstTokenWord = *tokenWords;
      argR6 = (uint ******)*ilReader[0x19];
      argR7 = (uint ******)0x4050607;
      if (((uint)*argR6 & 0x400000) != 0) {
        argR7 = *(uint *******)(local_5c + -0x2bf8);
        laneSelect = psnPackedLaneComponent(argR6,0);
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          argR7 = (uint ******)((uint)argR7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)(*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0);
        laneSelect = psnPackedLaneComponent(argR6,1);
        remapTable = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + laneSelect * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x10000 | (uint)argR7 & 0xff00ffff);
        }
        laneSelect = psnPackedLaneComponent(argR6,2);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          argR7 = (uint ******)(iVar34 * 0x100 | (uint)argR7 & 0xffff00ff);
        }
        laneSelect = psnPackedLaneComponent(argR6,3);
        if (*(int *)(remapTable + laneSelect * 4) == 0) {
          compiler = *(int *)(program + 8);
          argR7 = (uint ******)(uVar10 + 4 | (uint)argR7 & 0xffffff00);
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
      pppppuVar52 = (uint *****)(blockAllocation + 1);
      Block__ctor_ea148(pppppuVar52,*(undefined4 *)(program + 8));
      blockAllocation[0x4c] = trailingToken;
      blockAllocation[1] = PTR_DAT_001e8bd0 + 8;
      currentBlock = pppppuVar52;
      Program__insertBlockAfter(program,previousBlock,pppppuVar52);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation = compilerArenaA;
      ppppppuVar49 = (uint ******)(blockAllocation + 1);
      Block__ctor_ea020(ppppppuVar49,*(undefined4 *)(program + 8));
      currentBlock = (uint *****)ppppppuVar49;
      Program__insertBlockAfter(program,previousBlock,ppppppuVar49);
      Block__connect(previousBlock,currentBlock);
      previousBlock = currentBlock;
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar18 = (int *)Arena__alloc(*(undefined4 *)(compiler + 0x378),0xc);
      piVar18[1] = 0;
      piVar18[2] = 0;
      ppppppuVar19 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      *piVar18 = newTempIndex2;
      operandRecord = IRInst__getOperandRecord(ppppppuVar19,0);
      *(undefined4 *)(operandRecord + 0xc) = 0;
      *(int *)(operandRecord + 8) = newTempIndex2;
      stagedSelectWord = (uint ******)0x10203;
      argR8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,tokenWords,*ilReader[0x1b],loopStackData,argR8,&movByRegister);
      source0Token = **ilReader[0x1b];
      if (((((uint)source0Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      registerFile = Program__registerFileOfIlType(program,(uint)source0Token >> 0x10 & 0x3f);
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = iVar34;
      argR6 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR7 = ppppppuVar19;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*ilReader[0x1b],1,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())Program__appendInst)(program,ppppppuVar19,currentBlock);
      conditionStackCount = conditionStack[1];
      if (conditionStackCount < *conditionStack) {
        _memset(conditionStackCount * 4 + conditionStack[2],0,4);
        conditionStack[1] = conditionStackCount + 1;
        piVar36 = (int *)(conditionStackCount * 4 + conditionStack[2]);
      }
      else {
        piVar36 = (int *)Vector__elementRefGrow(conditionStack,conditionStackCount);
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
        pppppuVar52 = ilReader[10];
        argR6 = (uint ******)0x0;
        trailingToken = ilReader[(int)ilReader[0x16] + 0x23];
        virtualRegister = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),0x43,0xffffffff,0);
        iVar34 = IRImmedConstBuff__new_109b74(0x10a,*(undefined4 *)(program + 8));
        *(int *)(program + 0x354) = iVar34;
        IRInst__setOperandRef(iVar34,0,virtualRegister);
        *(uint ******)(iVar34 + 300) = pppppuVar52 + (int)trailingToken;
        Block__appendInst(*(undefined4 *)(program + 0x3a0),iVar34);
      }
      else {
        iVar34 = 1;
        ppppuVar45 = *ilReader[0x1b];
        sourceRegisterIndex = (uint)*(ushort *)((int)ppppuVar45 + 2);
        ilRegisterType = (uint)*ppppuVar45 >> 0x10 & 0x3f;
        if ((int)*ppppuVar45 < 0) {
          iVar34 = 2;
          sourceRegisterIndex = sourceRegisterIndex | (int)ppppuVar45[1] << 0x10;
        }
        pppuVar42 = ppppuVar45[iVar34];
        if (ilRegisterType == 0x1c) {
          puVar12 = *(uint **)(program + 0x90);
          if (puVar12 == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(compiler + 0x374);
            vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            puVar12 = vectorAllocation + 1;
            *vectorAllocation = compilerArenaA;
            vectorAllocation[1] = 2;
            vectorAllocation[2] = 0;
            vectorAllocation[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            vectorAllocation[3] = vectorStorage;
            *(uint **)(program + 0x90) = puVar12;
          }
        }
        else {
          puVar12 = *(uint **)(program + 0x8c);
          if (puVar12 == (uint *)0x0) {
            compilerArenaA = *(undefined4 *)(compiler + 0x374);
            vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x14);
            puVar12 = vectorAllocation + 1;
            *vectorAllocation = compilerArenaA;
            vectorAllocation[1] = 2;
            vectorAllocation[2] = 0;
            vectorAllocation[4] = compilerArenaA;
            vectorStorage = Arena__alloc(compilerArenaA,8);
            vectorAllocation[3] = vectorStorage;
            *(uint **)(program + 0x8c) = puVar12;
          }
        }
        if (sourceRegisterIndex < *puVar12) {
          uVar17 = puVar12[1];
          if (uVar17 <= sourceRegisterIndex) {
            _memset(uVar17 * 4 + puVar12[2],0,(sourceRegisterIndex - uVar17) * 4 + 4);
            puVar12[1] = sourceRegisterIndex + 1;
          }
          puVar12 = (uint *)(sourceRegisterIndex * 4 + puVar12[2]);
        }
        else {
          puVar12 = (uint *)Vector__elementRefGrow(puVar12,sourceRegisterIndex);
        }
        *puVar12 = (uint)pppuVar42;
        iVar34 = (sourceRegisterIndex >> 3 & 0x1ffffffc) + *(int *)(program + 0x434);
        *(uint *)(iVar34 + 8) = 1 << (sourceRegisterIndex & 0x1f) | *(uint *)(iVar34 + 8);
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
          instAllocation[0x4c] = pppuVar42;
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
      ppppuVar45 = *ilReader[0x19];
      if ((*(uint *)(program + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(program + 0x30) & 1) != 0) {
          stagedSelectWord = (uint ******)0x0;
          ppppppuVar19 = (uint ******)(int)*(short *)((int)ppppuVar45 + 2);
          registerFile = Program__registerFileOfIlType(program,(uint)*ppppuVar45 >> 0x10 & 0x3f);
          iVar34 = Program__lookupTable8b68(program,(uint)*tokenWords >> 0x10 & 0x3fff);
          if (iVar34 == 0) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x44) = ppppppuVar19;
          }
          else if (iVar34 == 1) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x48) = ppppppuVar19;
          }
          ppppppuVar49 = *(uint *******)(program + 1000);
          if ((int)ppppppuVar19 <= (int)*(uint *******)(program + 1000)) {
            ppppppuVar49 = ppppppuVar19;
          }
          puVar53 = *(undefined1 **)(program + 0x3ec);
          *(uint *******)(program + 1000) = ppppppuVar49;
          if ((int)puVar53 <= (int)ppppppuVar19) {
            puVar53 = (undefined1 *)((int)ppppppuVar19 + 1);
          }
          *(undefined1 **)(program + 0x3ec) = puVar53;
          *(undefined4 *)(program + 0x3f4) = 0x24;
          if (iVar34 == 0xd) {
            registerMap2 = *(int *)(program + 0x3ac);
            if (*(int *)(registerMap2 + 0x4c) == -1) {
              *(uint *******)(registerMap2 + 0x4c) = ppppppuVar19;
            }
            else {
              *(uint *******)(registerMap2 + 0x54) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xe) {
            registerMap2 = *(int *)(program + 0x3ac);
            if (*(int *)(registerMap2 + 0x50) == -1) {
              *(uint *******)(registerMap2 + 0x50) = ppppppuVar19;
            }
            else {
              *(uint *******)(registerMap2 + 0x58) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xb) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x5c) = ppppppuVar19;
          }
          else if (iVar34 == 0xc) {
            *(uint *******)(*(int *)(program + 0x3ac) + 0x60) = ppppppuVar19;
          }
          else if (iVar34 == 0xf) {
            *(uint *******)(*(int *)(program + 0x3ac) + 100) = ppppppuVar19;
          }
          argR6 = (uint ******)0x0;
          virtualRegister2 = (int *)VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar19,0);
          iVar43 = (**(code **)(*virtualRegister2 + 0x2c))();
          selectWordPtr = &stagedSelectWord;
          *(uint *******)(iVar43 + 0x140) = ppppppuVar19;
          loopCounterD = 0;
          do {
            if (*(char *)(loopCounterD + (int)selectWordPtr) == '\0') {
              argR6 = ppppppuVar19;
              IRLoadInterp__setLaneKindAndIndex(iVar43,loopCounterD,iVar34,ppppppuVar19);
            }
            notLastIteration = loopCounterD != 3;
            loopCounterD = loopCounterD + 1;
          } while (notLastIteration);
        }
      }
      else {
        argR7 = (uint ******)0x10203;
        argR6 = (uint ******)(uint)*(ushort *)((int)ppppuVar45 + 2);
        argR8 = (uint ******)0x0;
        (**(code **)(*hwDescription + 0x54))(hwDescription,argR6,(uint)*tokenWords >> 0x10 & 0x3fff);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      uVar44 = (uint)*tokenWords >> 0xe & 0x1f;
      ppppppuVar19 = (uint ******)Program__lookupTable8b68(program,uVar44);
      uVar10 = (uint)*tokenWords >> 0x13 & 7;
      if (uVar10 == 3) {
        clearsInfoFlag1 = true;
        bVar3 = false;
        bVar2 = false;
      }
      else if (uVar10 < 4) {
        if (uVar10 == 1) {
          clearsInfoFlag1 = false;
          bVar3 = false;
          bVar2 = true;
        }
        else {
code_r0x000feeb8:
          clearsInfoFlag1 = false;
          bVar3 = false;
          bVar2 = false;
        }
      }
      else if (uVar10 == 4) {
        clearsInfoFlag1 = false;
        bVar3 = true;
        bVar2 = false;
      }
      else {
        if (uVar10 != 5) goto code_r0x000feeb8;
        clearsInfoFlag1 = true;
        bVar3 = true;
        bVar2 = false;
      }
      destinationToken = (uint ******)*ilReader[0x19];
      firstTokenWord = *destinationToken;
      if (((uint)firstTokenWord & 0x400000) == 0) {
        if (((uint)firstTokenWord & 0x2000000) == 0) {
          ppppppuVar40 = (uint ******)0x0;
          ppppppuVar38 = (uint ******)0x0;
        }
        else {
          ppppppuVar40 = destinationToken + 1;
          ppppppuVar38 = (uint ******)0x0;
        }
      }
      else {
        ppppppuVar38 = destinationToken + 1;
        ppppppuVar40 = (uint ******)0x0;
        if (((uint)firstTokenWord & 0x2000000) != 0) {
          ppppppuVar40 = destinationToken + 2;
        }
      }
      if (((*(uint *)(program + 0x30) & 1) == 0) && ((*(uint *)(program + 0x30) & 0x2000) == 0)) {
        if (uVar44 == 10) {
          local_174 = (uint ****)(uint)*(ushort *)((int)ppppppuVar40 + 2);
          stagedSelectWord = (uint ******)0x10101;
          puVar12 = &stagedSelectWord;
          if (((uint)*ppppppuVar38 & 3) == 1) {
            puVar12 = &DAT_001aa9d0;
          }
          swizzleTable = &stagedSelectWord;
          stagedSelectWord = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc) == 4) {
            swizzleTable = &UNK_001aa9c4;
          }
          puVar12 = &stagedSelectWord;
          stagedSelectWord = (uint ******)*swizzleTable;
          if (((uint)*ppppppuVar38 & 0x30) == 0x10) {
            puVar12 = &UNK_001aa9c0;
          }
          swizzleTable = &stagedSelectWord;
          stagedSelectWord = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc0) == 0x40) {
            swizzleTable = &UNK_001aa9bc;
          }
          stagedSelectWord = (uint ******)*swizzleTable;
          local_170 = (uint *****)stagedSelectWord;
        }
      }
      else {
        ilRegisterType = (uint)firstTokenWord >> 0x10 & 0x3f;
        ppppppuVar48 = (uint ******)(uint)*(ushort *)((int)destinationToken + 2);
        registerFile = Program__registerFileOfIlType(program,ilRegisterType);
        puVar12 = movByRegister;
        ppppppuVar38 = *(uint *******)(program + 1000);
        if ((int)ppppppuVar48 <= (int)*(uint *******)(program + 1000)) {
          ppppppuVar38 = ppppppuVar48;
        }
        puVar53 = *(undefined1 **)(program + 0x3ec);
        *(uint *******)(program + 1000) = ppppppuVar38;
        if ((int)puVar53 <= (int)ppppppuVar48) {
          puVar53 = (undefined1 *)((int)ppppppuVar48 + 1);
        }
        *(undefined1 **)(program + 0x3ec) = puVar53;
        *(undefined4 *)(program + 0x3f4) = 0x24;
        argR7 = (uint ******)0x4050607;
        if ((*(uint *)(program + 0x30) & 1) == 0) {
          iVar34 = VRegPool__findOrCreate(*(undefined4 *)(program + 0x3ac),registerFile,ppppppuVar48,0);
          iVar34 = *(int *)(iVar34 + 0x38);
          if (!clearsInfoFlag1) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          }
          if (bVar3) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
          }
          if (bVar2) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
          }
          loopCounterC = 0;
          do {
            argR6 = ppppppuVar19;
            argR7 = ppppppuVar48;
            IRLoadInterp__setLane(iVar34,loopCounterC,1,ppppppuVar19,ppppppuVar48);
            notLastIteration = loopCounterC != 3;
            loopCounterC = loopCounterC + 1;
          } while (notLastIteration);
        }
        else if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
          argR8 = *(uint *******)(program + 0x3a0);
          hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
          (**(code **)(*hwDescription + 0x4c))(hwDescription,program,ppppppuVar48);
          argR6 = destinationToken;
        }
        else if (ilRegisterType != 9) {
          uVar10 = (uint)*(ushort *)((int)ppppppuVar40 + 2);
          if (uVar10 < *movByRegister) {
            uVar44 = movByRegister[1];
            if (uVar44 <= uVar10) {
              _memset(uVar44 * 4 + movByRegister[2],0,(uVar10 - uVar44) * 4 + 4);
              puVar12[1] = uVar10 + 1;
            }
            vectorElementSlot = (undefined4 *)(uVar10 * 4 + puVar12[2]);
          }
          else {
            vectorElementSlot = (undefined4 *)Vector__elementRefGrow(movByRegister,uVar10);
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
      uVar10 = (uint)*tokenWords >> 0x18 & 0xf;
      if (hwDescription[0x14] < (int)(uint)ilRegisterIndex) {
        Compiler__fail(compiler,7);
      }
      bitmapByteOffset2 = ilRegisterIndex >> 3 & 0x1c;
      iVar34 = (uint)ilRegisterIndex * 0xc;
      *(uint *)((int)usedRegisterBitmap + bitmapByteOffset2 + 8) =
           1 << (ilRegisterIndex & 0x1f) | *(uint *)((int)usedRegisterBitmap + bitmapByteOffset2 + 8);
      *(undefined4 *)(*(int *)(program + 0x78) + iVar34) = 1;
      if (uVar10 != 0) {
        *(uint *)(iVar34 + *(int *)(program + 0x78) + 4) = uVar10;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      local_a4 = (uint *****)((int)local_a4 + 1);
      if ((*(uint *)(program + 0x30) & 0x40000) == 0) {
        if (puVar13[2] != 0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x180000;
        }
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          *(uint *)(program + 0x30) = *(uint *)(program + 0x30) | 0x80000;
        }
        pvVar16 = IRInst__create(*(undefined4 *)
                                (ilOpcode * 0x24 + *(int *)(*(int *)(compiler + 0x30c) + 0xc)),compiler);
        operandRecord = IRInst__getOperandRecord(pvVar16,0);
        *(undefined4 *)(operandRecord + 0xc) = 0x2c;
        *(undefined4 *)(operandRecord + 8) = 0;
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x10101;
        operandRecord = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(operandRecord + 0xc) = 0x2c;
        *(undefined4 *)(operandRecord + 8) = 0;
        operandRecord = IRInst__getOperandRecord(pvVar16,1);
        *(undefined4 *)(operandRecord + 0x10) = 0;
        ((int (*)())Program__appendInst)(program,pvVar16,currentBlock);
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
      uVar50 = *(undefined4 *)(program + 0x3ac);
      newTempIndex = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex;
      uVar50 = VRegPool__findOrCreate(uVar50,0,newTempIndex,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,uVar50);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,movFloatInst,1,0,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      getResourceInst = IRInst__create(0x109,*(undefined4 *)(program + 8));
      *(uint *)((int)getResourceInst + 0x134) = ilRegisterIndex2;
      IRInst__setOperandRef(getResourceInst,0,virtualRegister);
      IRInst__setOperandRef(getResourceInst,1,uVar50);
      ((int (*)())Program__appendInst)(program,getResourceInst,currentBlock);
      puVar9 = PTR_DAT_001e8b8c;
      remapTable = PTR_DAT_001e8b64;
      stagedSelectWord = (uint ******)0x10203;
      if (((uint)firstTokenWord & 0x1f000000) != 0x1000000) {
        loopCounterB = 0;
        do {
          int2FInst = IRInst__create(0xe1,*(undefined4 *)(program + 8));
          IRInst__setOperandRef(int2FInst,0,virtualRegister);
          IRInst__setOperandRef(int2FInst,1,virtualRegister);
          uVar50 = *(undefined4 *)(puVar9 + loopCounterB);
          *(undefined4 *)((int)int2FInst + 0x9c) = *(undefined4 *)(remapTable + loopCounterB);
          operandRecord2 = IRInst__getOperandRecord(int2FInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = uVar50;
          ((int (*)())Program__appendInst)(program,int2FInst,currentBlock);
          notLastIteration = loopCounterB != 0xc;
          loopCounterB = loopCounterB + 4;
        } while (notLastIteration);
      }
      ppppppuVar49 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = ppppppuVar49;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar49,1,0,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar49,1,virtualRegister);
code_r0x000ff070:
      ((int (*)())Program__appendInst)(program,ppppppuVar49,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      ppppppuVar19 = (uint ******)(instAllocation + 1);
      IRInst__ctor_10502c(ppppppuVar19,0xb4,*(undefined4 *)(program + 8));
      if (((uint)*tokenWords & 0x3fff0000) != 0) {
        instAllocation[0x4c] = 1;
      }
      argR8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,tokenWords,*ilReader[0x1b],loopStackData,argR8,&movByRegister);
      source0Token = **ilReader[0x1b];
      if (((((uint)source0Token & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*ilReader[0x1b] + 2);
      }
      ilRegisterType = (uint)source0Token >> 0x10 & 0x3f;
      iVar43 = VRegPool__find(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
      if (iVar43 == 0) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *instAllocation = compilerArenaA;
        puVar24 = instAllocation + 1;
        IRExport__ctor_108918(puVar24,*(undefined4 *)(program + 8));
        instAllocation[6] = instAllocation[6] | 0x10000;
        *(undefined4 **)(program + 0x350) = puVar24;
        instAllocation[0x28] = 0;
        iVar43 = VRegPool__create(*(undefined4 *)(program + 0x3ac),0x2c,0,0);
        IRInst__setOperandRef(puVar24,0,iVar43);
        IRInst__setOperandRef(puVar24,1,iVar43);
        iVar47 = IRInst__getOperandRecord(puVar24,1);
        *(undefined4 *)(iVar47 + 0x10) = 0x10203;
        Block__appendInst(*(undefined4 *)(program + 0x3a8),puVar24);
        VReg__appendUser(iVar43,puVar24);
        VReg__addUse(iVar43,1,puVar24);
      }
      IRInst__setOperandRef(ppppppuVar19,0,iVar43);
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,1);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = iVar34;
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,2);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      *(int *)(operandRecord2 + 8) = iVar34;
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,3);
      *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
      selectWordPtr = &stagedSelectWord;
      *(int *)(operandRecord2 + 8) = iVar34;
      stagedSelectWord = (uint ******)0x10101;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],1,ppppppuVar19);
      stagedSelectWord = (uint ******)0x2020202;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],2,ppppppuVar19);
      argR6 = (uint ******)((int)((unsigned char *)0x0) + 3);
      stagedSelectWord = (uint ******)0x3030303;
      argR7 = ppppppuVar19;
      ((int (*)())Program__applySourceTokenToOperand)(program,selectWordPtr,*ilReader[0x1b],3,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        DList__unlink(iVar34);
        ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())Program__appendInst)(program,ppppppuVar19,currentBlock);
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      compilerArenaA = *(undefined4 *)(compiler + 0x374);
      instAllocation = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
      *instAllocation = compilerArenaA;
      piVar18 = instAllocation + 1;
      IRInst__ctor_10502c(piVar18,0x106,*(undefined4 *)(program + 8));
      ((int (*)())Program__appendInst)(program,piVar18,currentBlock);
    }
    puVar12 = *(uint **)(program + 0x414);
    uVar10 = puVar12[1];
    if (uVar10 < *puVar12) {
      _memset(uVar10 * 4 + puVar12[2],0,4);
      piVar36 = (int *)(uVar10 * 4 + puVar12[2]);
      puVar12[1] = uVar10 + 1;
    }
    else {
      piVar36 = (int *)Vector__elementRefGrow(puVar12,uVar10);
    }
code_r0x000febe0:
    *piVar36 = (int)piVar18;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    isTranslationKind7 = false;
    break;
  case 5:
    local_78 = &DAT_001ad5d8;
    local_60 = &DAT_001ad5d8;
    iVar47 = *(int *)(ilOpcode * 0x24 + iVar47 + 0x18);
    local_124 = (uint *****)0x0;
    stagedSelectWord = (uint ******)0x10203;
    compilerArenaB = *(undefined4 *)(compiler + 0x378);
    vectorAllocation = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    puVar12 = vectorAllocation + 1;
    *vectorAllocation = compilerArenaB;
    vectorAllocation[1] = 2;
    vectorAllocation[2] = 0;
    vectorAllocation[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    vectorAllocation[3] = vectorStorage;
    compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
    vectorAllocation2 = (undefined4 *)Arena__alloc(compilerArenaB,0x14);
    ppppppuVar19 = (uint ******)(vectorAllocation2 + 1);
    *vectorAllocation2 = compilerArenaB;
    vectorAllocation2[1] = 2;
    vectorAllocation2[2] = 0;
    vectorAllocation2[4] = compilerArenaB;
    vectorStorage = Arena__alloc(compilerArenaB,8);
    vectorAllocation2[3] = vectorStorage;
    templateCursor = (int *)0x0;
    _memcpy(&local_104,&UNK_001aaa2c,0x24);
    iVar20 = *(int *)(program + 8);
    ppppppuVar38 = (uint ******)0x0;
    opcodeRecordTable = *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc);
    destOperandCount = (uint *****)((int (*)())FUN_000f8960)(ilOpcode,opcodeRecordTable);
    iVar43 = ((int (*)())FUN_000f8970)(ilOpcode,opcodeRecordTable);
    if (0 < (int)destOperandCount) {
      do {
        iVar21 = (int)ppppppuVar38 << 2;
        for (iVar22 = 0;
            iVar23 = ((int (*)())FUN_000f8980)(ilOpcode,ppppppuVar38,
                                  *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)), iVar22 <= iVar23
            ; iVar22 = iVar22 + 1) {
          argR6 = loopStackData;
          argR7 = (uint ******)local_a4;
          ((int (*)())FUN_000f9a58)(program,local_6c,*(undefined4 *)((int)ilReader[0x19] + iVar21),loopStackData,
                       local_a4);
          iVar20 = *(int *)(program + 8);
          iVar21 = iVar21 + 0x14;
        }
        ppppppuVar38 = (uint ******)((int)ppppppuVar38 + 1);
      } while ((uint ******)destOperandCount != ppppppuVar38);
    }
    iVar21 = 0;
    if (0 < iVar43) {
      do {
        iVar22 = iVar21 << 2;
        puVar53 = (undefined1 *)((int)destOperandCount + iVar21);
        for (iVar23 = 0;
            iVar25 = ((int (*)())FUN_000f8980)(ilOpcode,puVar53,*(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)),
            iVar23 <= iVar25; iVar23 = iVar23 + 1) {
          argR6 = *(uint *******)((int)ilReader[0x1b] + iVar22);
          argR8 = (uint ******)&local_174;
          argR7 = loopStackData;
          ((int (*)())FUN_000fb3d4)(program,local_68,tokenWords,argR6,loopStackData,argR8,&movByRegister);
          iVar20 = *(int *)(program + 8);
          iVar22 = iVar22 + 0x14;
        }
        iVar21 = iVar21 + 1;
      } while (iVar43 != iVar21);
    }
    iVar20 = *(int *)(local_14c + 8);
    iVar43 = local_14c;
    while (iVar21 = iVar20, iVar21 != 0) {
      DList__unlink(iVar43);
      ((int (*)())Program__appendInst)(program,iVar43,currentBlock);
      iVar43 = iVar21;
      iVar20 = *(int *)(iVar21 + 8);
    }
    local_b4 = 0;
    ppppppuVar38 = (uint ******)0x0;
    ppppppuVar40 = (uint ******)0x0;
code_r0x001005f4:
    ppppppuVar39 = (uint ******)currentBlock;
    ppppppuVar48 = (uint ******)PTR_DAT_001e8bd4;
    templateToken = *(uint *)(iVar47 + (int)templateCursor * 4);
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
      argR7 = ppppppuVar38;
      argR8 = (uint ******)destOperandCount;
      iVar43 = ((int (*)())FUN_000fa958)(program,templateToken - 2,ppppppuVar40,ilReader,ppppppuVar38,destOperandCount,local_124,
                            &stagedSelectWord,loopStackData,local_b4,currentBlock);
      if (iVar43 != 0) {
        DList__pushFront(local_6c,iVar43);
      }
      goto code_r0x001025c0;
    case 0x12:
      IROperand__setModifierBits(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,2,1);
      goto code_r0x00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      uVar44 = (uint)*tokenWords >> 0x10 & 0x3fff;
      if (templateToken == 0x14) {
        argR7 = (uint ******)(PTR_DAT_001dc78c)[uVar44];
      }
      else if (templateToken == 0x15) {
        argR7 = (uint ******)(PTR_DAT_001dc77c)[uVar44];
      }
      else {
        argR7 = (uint ******)(PTR_DAT_001dc76c)[uVar44];
      }
      goto code_r0x001022b4;
    case 0x17:
      iVar43 = FUN_000e47f4(ilReader);
      if ((iVar43 == 0x3e) || (iVar43 = FUN_000e47f4(ilReader), iVar43 == 0x71)) {
        uVar10 = puVar13[2];
        if (uVar10 != 0) {
          stackElement = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            stackElement = (int *)((uVar10 - 1) * 4 + puVar13[3]);
          }
          iVar43 = *stackElement;
          ifStackCount = (uint *****)ifStack[1];
          ppppppuVar48 = (uint ******)PTR_DAT_001e8bbc;
          if (ifStackCount != (uint *****)0x0) {
            pppppuVar52 = (uint *****)0x0;
            if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
              pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
            }
            if ((int)scopeLevel <= (int)(*pppppuVar52)[0x2e]) {
              breakTargetBlock = *(undefined4 *)(iVar43 + 0x154);
              arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
              blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x138);
              *blockAllocation4 = arenaA;
              ppppppuVar48 = (uint ******)(blockAllocation4 + 1);
              argR6 = *(uint *******)(program + 8);
              BreakBlock__ctor_ec0c8(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),argR6);
              blockAllocation4[0x2f] = scopeLevel;
              Program__insertBlockAfter(program,previousBlock,ppppppuVar48);
              Block__connect(previousBlock,ppppppuVar48);
              Block__connect(ppppppuVar48,breakTargetBlock);
              local_bc = 0;
              *(int *)(iVar43 + 0x138) = *(int *)(iVar43 + 0x138) + 1;
              previousBlock = (uint *****)ppppppuVar48;
              break;
            }
          }
          goto code_r0x00103718;
        }
      }
      else {
        iVar43 = FUN_000e47f4(ilReader);
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bb4;
        if (iVar43 == 0x72) {
          stackElement = (int *)0x0;
          conditionStackTopIndex = conditionStack[1] - 1;
          if (conditionStackTopIndex < conditionStack[1]) {
            stackElement = (int *)(conditionStackTopIndex * 4 + conditionStack[2]);
          }
          *(int *)(*stackElement + 4) = *(int *)(*stackElement + 4) + 1;
code_r0x00103718:
          argR6 = (uint ******)0x0;
          argR8 = ppppppuVar19;
          iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&templateCursor,0,ppppppuVar48,ppppppuVar19);
          argR7 = ppppppuVar48;
          goto code_r0x0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      templateCursor = (int *)((int)templateCursor + 1);
      templateToken = *(uint *)(iVar47 + (int)templateCursor * 4);
      stagedSelectWord = (uint ******)
                  (templateToken << 0x18 | (templateToken & 0xff00) << 8 | templateToken >> 8 & 0xff00 | templateToken >> 0x18);
      local_bc = 0;
      break;
    case 0x20:
      templateCursor = (int *)((int)templateCursor + 1);
      templateToken = *(uint *)(iVar47 + (int)templateCursor * 4);
      argR7 = (uint ******)&local_124;
      local_124 = (uint *****)
                  (templateToken << 0x18 | (templateToken & 0xff00) << 8 | templateToken >> 8 & 0xff00 | templateToken >> 0x18);
      local_bc = 0;
      break;
    case 0x21:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*tokenWords >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b80;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bac;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba8;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bcc;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b94;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      uVar10 = (uint)*tokenWords >> 0x16 & 7;
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      ppppppuVar48 = IRInst__create(0x12,*(undefined4 *)(program + 8));
      if (local_100 == 0) {
        local_100 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = local_100;
      }
      iVar43 = local_100;
      operandRecordLast = IRInst__getOperandRecord(ppppppuVar48,0);
      *(int *)(operandRecordLast + 8) = iVar43;
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
      operandRecordB = IRInst__getOperandRecord(ppppppuVar48,1);
      *(undefined4 *)(operandRecordB + 0xc) = registerFile;
      *(int *)(operandRecordB + 8) = sourceRegisterIndexB;
      argR6 = ppppppuVar40;
      argR7 = ppppppuVar48;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*ilReader[0x1b],ppppppuVar40,ppppppuVar48);
      if (uVar10 == 2) {
        fVar5 = 1.0;
code_r0x001021c0:
        dVar54 = (double)fVar5;
        ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar48,program,2,dVar54,dVar54,dVar54,dVar54);
        IROperand__setModifierBits(ppppppuVar48 + 0x2f,1,1);
      }
      else if (uVar10 < 3) {
        if (uVar10 == 1) {
          fVar5 = 0.5;
          goto code_r0x001021c0;
        }
      }
      else {
        if (uVar10 == 3) {
          fVar5 = 0.5;
        }
        else {
          if (uVar10 != 4) goto code_r0x00102220;
          fVar5 = 1.0;
        }
        dVar54 = (double)fVar5;
        ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar48,program,2,dVar54,dVar54,dVar54,dVar54);
      }
code_r0x00102220:
      ((int (*)())Program__appendInst)(program,ppppppuVar48,currentBlock);
      operandRecordLast = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(int *)(operandRecordLast + 8) = iVar43;
      *(undefined4 *)(operandRecordLast + 0xc) = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
      templateCursor = (int *)((int)templateCursor + 1);
      break;
    case 0x23:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*tokenWords >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc0;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b7c;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba4;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b90;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc4;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (puVar13[2] != 0) {
        ifStackCount = (uint *****)ifStack[1];
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b78;
        if (ifStackCount != (uint *****)0x0) {
          pppppuVar52 = (uint *****)0x0;
          if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
            pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
          }
          if ((int)scopeLevel <= (int)(*pppppuVar52)[0x2e]) {
            uVar10 = puVar13[2] - 1;
            stackElement = (int *)0x0;
            if (uVar10 < (uint)puVar13[2]) {
              stackElement = (int *)(uVar10 * 4 + puVar13[3]);
            }
            iVar43 = *stackElement;
            arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
            continueTargetBlock = *(undefined4 *)(iVar43 + 0x150);
            blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x138);
            *blockAllocation4 = arenaA;
            ppppppuVar48 = (uint ******)(blockAllocation4 + 1);
            argR6 = *(uint *******)(program + 8);
            ContinueBlock__ctor_ec178(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),argR6);
            blockAllocation4[0x2f] = scopeLevel;
            Program__insertBlockAfter(program,previousBlock,ppppppuVar48);
            Block__connect(previousBlock,ppppppuVar48);
            Block__connect(ppppppuVar48,continueTargetBlock);
            local_bc = 0;
            *(undefined4 *)(iVar43 + 0x13c) = 1;
            previousBlock = (uint *****)ppppppuVar48;
            break;
          }
        }
        goto code_r0x00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      vectorElementSlot3 = (undefined4 *)0x0;
      uVar10 = vectorAllocation[2] - 1;
      if (uVar10 < (uint)vectorAllocation[2]) {
        vectorElementSlot3 = (undefined4 *)(uVar10 * 4 + vectorAllocation[3]);
      }
      if (*(int *)*vectorElementSlot3 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)templateCursor * 4 + iVar47);
      do {
        piVar36 = templateCursor;
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)templateCursor + 1);
          piVar18 = piVar18 + 1;
        }
        templateCursor = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x28);
      local_bc = 0;
      templateCursor = piVar36;
      break;
    case 0x27:
      pppppuVar52 = (uint *****)0x0;
      ifStackTopIndex = (uint *****)((int)ifStack[1] - 1);
      if (ifStackTopIndex < ifStack[1]) {
        pppppuVar52 = (uint *****)(ifStack[2] + (int)ifStackTopIndex);
      }
      ppppuVar45 = *pppppuVar52;
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation4 = compilerArenaA;
      ppppppuVar48 = (uint ******)(blockAllocation4 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      blockAllocation4[0x2f] = scopeLevel;
      ppppuVar45[0x4e] = (uint ***)ppppppuVar48;
      currentBlock = (uint *****)ppppppuVar48;
      Block__connect(ppppuVar45,ppppppuVar48);
      Program__insertBlockAfter(program,previousBlock,currentBlock);
      goto code_r0x00103300;
    case 0x28:
      uVar10 = vectorAllocation[2];
      stackElement = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        stackElement = (int *)((uVar10 - 1) * 4 + vectorAllocation[3]);
      }
      stackElement = (int *)*stackElement;
      Vector__removeAt(puVar12,uVar10 - 1);
joined_r0x00103afc:
      if (stackElement != (int *)0x0) {
        Arena__free(stackElement[-1],stackElement + -1);
        goto code_r0x00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      pppppuVar52 = (uint *****)0x0;
      ifStackTopIndex = (uint *****)((int)ifStack[1] - 1);
      if (ifStackTopIndex < ifStack[1]) {
        pppppuVar52 = (uint *****)(ifStack[2] + (int)ifStackTopIndex);
      }
      ppppuVar45 = *pppppuVar52;
      pppuVar42 = ppppuVar45[0x4f];
      pppuVar42[0x2e] = (uint **)scopeLevel;
      Program__insertBlockAfter(program,previousBlock,pppuVar42);
      piVar18 = (int *)Block__lastBlockOfChain_e7b9c(ppppuVar45);
      piVar18[0x2e] = (int)scopeLevel;
      iVar43 = (**(code **)(*piVar18 + 0x38))();
      if ((iVar43 == 0) && (iVar43 = (**(code **)(*piVar18 + 0x3c))(piVar18), iVar43 == 0)) {
        Block__connect(piVar18,pppuVar42);
      }
      ppppuVar30 = (uint ****)Block__lastBlockOfChain_e7a9c(ppppuVar45);
      ppppuVar30[0x2e] = (uint ***)scopeLevel;
      ppppuVar51 = ppppuVar30;
      if (ppppuVar30 == ppppuVar45) {
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation4 = compilerArenaA;
        ppppuVar51 = (uint ****)(blockAllocation4 + 1);
        Block__ctor_ea020(ppppuVar51,*(undefined4 *)(program + 8));
        blockAllocation4[0x2f] = scopeLevel;
        ppppuVar30[0x4e] = (uint ***)ppppuVar51;
        Block__connect(ppppuVar30,ppppuVar51);
        Program__insertBlockAfter(program,previousBlock,ppppuVar51);
      }
      iVar43 = (*(code *)(*ppppuVar51)[0xe])(ppppuVar51);
      if ((iVar43 == 0) && (iVar43 = (*(code *)(*ppppuVar51)[0xf])(ppppuVar51), iVar43 == 0)) {
        Block__connect(ppppuVar51,pppuVar42);
      }
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation4 = compilerArenaA;
      ppppppuVar48 = (uint ******)(blockAllocation4 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      blockAllocation4[0x2f] = scopeLevel;
      currentBlock = (uint *****)ppppppuVar48;
      Program__insertBlockAfter(program,pppuVar42,ppppppuVar48);
      Block__connect(pppuVar42,currentBlock);
      previousBlock = currentBlock;
      Vector__removeAt(ifStack,(int)ifStack[1] - 1);
      uVar10 = puVar13[2];
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      stackElement = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        stackElement = (int *)((uVar10 - 1) * 4 + puVar13[3]);
      }
      local_bc = 0;
      *(int *)(*stackElement + 300) = *(int *)(*stackElement + 300) + -1;
      break;
    case 0x2a:
      uVar10 = vectorAllocation2[2];
      if (uVar10 != 0) {
        vectorElementSlot3 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          vectorElementSlot3 = (undefined4 *)((uVar10 - 1) * 4 + vectorAllocation2[3]);
        }
        stackElement = (int *)*vectorElementSlot3;
        Vector__removeAt(ppppppuVar19,uVar10 - 1);
        if ((uint ******)stackElement[2] != (uint ******)0x0) {
          currentBlock = (uint *****)stackElement[2];
        }
        templateCursor = (int *)stackElement[1];
        iVar47 = *stackElement;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      local_74 = 0x1dd5d8;
      if ((UNK_001dc660 == 0) || (ilOpcode == UNK_001dc660)) {
code_r0x00101020:
        local_64 = 0;
      }
      else {
        piVar18 = &UNK_001dc66c;
        local_64 = 0;
        do {
          iVar43 = *piVar18;
          local_64 = local_64 + 1;
          if (iVar43 == 0) goto code_r0x00101020;
          piVar18 = piVar18 + 3;
        } while (ilOpcode != iVar43);
      }
      local_64 = local_64 * 0xc;
      sampleFlags = *(uint *)(local_64 + 0x1dc664);
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
      local_c4 = (uint)*tokenWords >> 0x18 & 1;
      fetchDescriptor[9] = (ushort)local_c4 ^ 1;
      tokenBit25Clear = ((uint)*tokenWords >> 0x19 & 1) == 0;
      fetchDescriptor[7] = (ushort)tokenBit25Clear;
      if (hasFirstExtraOperand) {
        fetchDescriptor[8] = (ushort)(ilOpcode != 0x5f);
      }
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      fetchResultTemp = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,virtualRegister);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      if (hasFirstExtraOperand) {
        cubeCoordTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        extraOperandTemp1 = VRegPool__findOrCreate(cubeCoordTemp,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,extraOperandTemp1);
        ((int (*)())FUN_000fa958)(program,10,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
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
        ((int (*)())FUN_000fa958)(program,0xe,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
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
      iVar43 = *(int *)(*(int *)(program + 0x78) + registerRecordOffset + 4);
      if ((iVar43 == 4) || (cubeCoordTemp = virtualRegister, iVar43 == 0xb)) {
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
      iVar43 = *(int *)(local_64 + local_74 + -0xf70);
      if ((sampleFlag4Clear) || (tokenBit25Clear)) {
        if ((iVar43 != 0xff) || (*(int *)(registerRecordOffset + *(int *)(program + 0x78) + 4) != 7))
        goto code_r0x001019bc;
        ldBufferInst = IRInst__create(0x104,*(undefined4 *)(program + 8));
        *(uint *)((int)ldBufferInst + 0x130) = samplerIndex;
        *(undefined4 *)((int)ldBufferInst + 0x140) = *(undefined4 *)(local_60 + -0x2c30);
        IRInst__setOperandRef(ldBufferInst,0,fetchResultTemp);
        IRInst__setOperandRef(ldBufferInst,1,fetchCoordTemp);
        ((int (*)())Program__appendInst)(program,ldBufferInst,currentBlock);
      }
      else {
        iVar43 = 0xae;
code_r0x001019bc:
        fetchInst = IRInst__create(iVar43,*(undefined4 *)(program + 8));
        fetchInst[0x4f] = (int)fetchDescriptor;
        fetchInst[0x4d] = samplerIndex;
        IRInst__setOperandRef(fetchInst,0,fetchResultTemp);
        IRInst__setOperandRef(fetchInst,1,fetchCoordTemp);
        if (hasGradients) {
          (**(code **)(*fetchInst + 0x90))(fetchInst,virtualRegister);
        }
        iVar43 = *(int *)(program + 0x78);
        if (*(int *)(registerRecordOffset + iVar43 + 4) == 8) {
          (**(code **)(*fetchInst + 0x88))(fetchInst,1,2,1);
          roundNearestEvenInst = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          iVar21 = fetchInst[0x2b];
          iVar22 = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,0);
          *(int *)(operandRecord2 + 0xc) = iVar22;
          *(int *)(operandRecord2 + 8) = iVar21;
          iVar21 = fetchInst[0x2b];
          iVar22 = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(int *)(operandRecord2 + 0xc) = iVar22;
          *(int *)(operandRecord2 + 8) = iVar21;
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = 0x1010101;
          *(undefined4 *)((int)roundNearestEvenInst + 0x9c) = 0x1000101;
          ((int (*)())Program__appendInst)(program,roundNearestEvenInst,currentBlock);
          iVar43 = *(int *)(program + 0x78);
        }
        if (*(int *)(registerRecordOffset + iVar43 + 4) == 9) {
          roundNearestEvenInst = IRInst__create(0xbe,*(undefined4 *)(program + 8));
          iVar21 = fetchInst[0x2b];
          iVar22 = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,0);
          *(int *)(operandRecord2 + 0xc) = iVar22;
          *(int *)(operandRecord2 + 8) = iVar21;
          iVar21 = fetchInst[0x2b];
          iVar22 = fetchInst[0x2c];
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(int *)(operandRecord2 + 0xc) = iVar22;
          *(int *)(operandRecord2 + 8) = iVar21;
          operandRecord2 = IRInst__getOperandRecord(roundNearestEvenInst,1);
          *(undefined4 *)(operandRecord2 + 0x10) = 0x2020202;
          *(undefined4 *)((int)roundNearestEvenInst + 0x9c) = 0x1010001;
          ((int (*)())Program__appendInst)(program,roundNearestEvenInst,currentBlock);
          iVar43 = *(int *)(program + 0x78);
        }
        iVar43 = ((int (*)())remapSelect1To0)(*(undefined4 *)(registerRecordOffset + iVar43));
        fetchInst[0x4e] = iVar43;
        *(short *)(fetchInst[0x4f] + 0x12) = (short)local_c4;
        ((int (*)())Program__appendInst)(program,fetchInst,currentBlock);
        if (*(int *)(registerRecordOffset + *(int *)(program + 0x78) + 8) != 0) {
          mulFloatInst = IRInst__create(0x13,*(undefined4 *)(program + 8));
          registerRecordOffset = fetchInst[0x25];
          iVar21 = fetchInst[0x26];
          operandRecord2 = IRInst__getOperandRecord(mulFloatInst,0);
          *(int *)(operandRecord2 + 0xc) = iVar21;
          *(int *)(operandRecord2 + 8) = registerRecordOffset;
          registerRecordOffset = fetchInst[0x26];
          iVar21 = fetchInst[0x25];
          operandRecord2 = IRInst__getOperandRecord(mulFloatInst,1);
          local_98 = (uint)(short)samplerIndex;
          *(int *)(operandRecord2 + 0xc) = registerRecordOffset;
          local_90 = local_98 | 0x130000;
          local_94 = local_98 | 0x130000;
          local_9c = local_98 | 0x130000;
          local_98 = local_98 | 0x130000;
          *(int *)(operandRecord2 + 8) = iVar21;
          ((int (*)())IRInst__makeLiteralVec4Int)(mulFloatInst,program,2,local_90,local_94,local_98,local_9c);
          ((int (*)())Program__appendInst)(program,mulFloatInst,currentBlock);
        }
      }
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar38,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar38,1,fetchResultTemp);
      goto code_r0x00101cbc;
    case 0x2d:
    case 0x2e:
      samplerIndex2 = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = (uint *****)Arena__alloc(*(undefined4 *)(*(int *)(program + 8) + 0x374),0x24);
      _memset(pppppuVar15,0,0x24);
      *(undefined2 *)((int)pppppuVar15 + 0x12) = 1;
      *(undefined2 *)((int)pppppuVar15 + 0xe) = 1;
      *(undefined2 *)(pppppuVar15 + 5) = 0;
      *(undefined2 *)(pppppuVar15 + 4) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x16) = 0;
      *(undefined2 *)(pppppuVar15 + 6) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x1a) = 0;
      *(undefined2 *)(pppppuVar15 + 7) = 0;
      *(undefined2 *)(pppppuVar15 + 2) = 7;
      *(undefined2 *)(pppppuVar15 + 3) = 3;
      *(undefined2 *)pppppuVar15 = 3;
      *(undefined2 *)((int)pppppuVar15 + 2) = 3;
      *(undefined2 *)(pppppuVar15 + 1) = 3;
      *(undefined2 *)((int)pppppuVar15 + 6) = 7;
      *(undefined2 *)((int)pppppuVar15 + 10) = 3;
      *(ushort *)((int)pppppuVar15 + 0x12) =
           (ushort)(((uint)(byte)((((uint)*tokenWords & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      tokenBit25Clear2 = ((uint)*tokenWords >> 0x19 & 1) == 0;
      *(ushort *)((int)pppppuVar15 + 0xe) = (ushort)tokenBit25Clear2;
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      local_124 = (uint *****)0x1;
      pppppuVar52 = *(uint ******)(local_60 + -0x2c30);
      stagedSelectWord = (uint ******)pppppuVar52;
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,virtualRegister);
      *(undefined4 *)((int)movFloatInst + 0x9c) = 1;
      selectWordPtr = &stagedSelectWord;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      local_124 = (uint *****)0x1010100;
      stagedSelectWord = (uint ******)pppppuVar52;
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(ppppppuVar38,0,virtualRegister);
      ppppppuVar38[0x27] = (uint *****)0x1010100;
      ((int (*)())FUN_000fa958)(program,10,1,ilReader,ppppppuVar38,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,ppppppuVar38,currentBlock);
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
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      selectWord2 = *(uint *******)(local_60 + -0x2c30);
      stagedSelectWord = selectWord2;
      fetchInst2 = IRInst__create(fetchIrOpcode,*(undefined4 *)(program + 8));
      fetchInst2[0x4f] = pppppuVar15;
      fetchInst2[0x4d] = samplerIndex2;
      if (*(int *)(program + 0x7c) < (int)samplerIndex2) {
        *(uint ******)(program + 0x7c) = samplerIndex2;
      }
      *(uint *)(program + 0x84) = 1 << ((uint)samplerIndex2 & 0x3f) | *(uint *)(program + 0x84);
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)(*(int *)(program + 0x78) + (int)samplerIndex2 * 0xc))
      ;
      fetchInst2[0x4c] = samplerIndex2;
      fetchInst2[0x4e] = pppppuVar15;
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = fetchInst2;
      iVar43 = ((int (*)())FUN_000fa958)(program,4,0,ilReader,fetchInst2,1,local_124,selectWordPtr,loopStackData,1,
                            currentBlock);
      if (iVar43 != 0) {
        DList__pushFront(local_6c,iVar43);
      }
      IRInst__setOperandRef(fetchInst2,1,virtualRegister);
      operandRecord2 = IRInst__getOperandRecord(fetchInst2,1);
      *(uint *******)(operandRecord2 + 0x10) = selectWord2;
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)samplerIndex2 * 0xc + *(int *)(program + 0x78)))
      ;
      fetchInst2[0x4e] = pppppuVar15;
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
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      registerMap = *(undefined4 *)(program + 0x3ac);
      newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
      coordTemp = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
      movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
      IRInst__setOperandRef(movFloatInst,0,coordTemp);
      selectWordPtr = &stagedSelectWord;
      ((int (*)())FUN_000fa958)(program,5,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
      virtualRegister = 0;
      if (ilOpcode == 0x5f) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,virtualRegister);
        ((int (*)())FUN_000fa958)(program,10,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
        ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
        gradientYTemp = *(undefined4 *)(program + 0x3ac);
        newTempIndex2 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex2;
        gradientYTemp = VRegPool__findOrCreate(gradientYTemp,0,newTempIndex2,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,0,gradientYTemp);
        ((int (*)())FUN_000fa958)(program,0xe,1,ilReader,movFloatInst,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
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
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
      ppppppuVar38 = IRInst__create(0x31,*(undefined4 *)(program + 8));
      argR8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      argR6 = ilReader;
      argR7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(program,0,0,ilReader,ppppppuVar38,1,local_124,selectWordPtr,loopStackData,1,currentBlock);
      IRInst__setOperandRef(ppppppuVar38,1,fetchResultTemp2);
code_r0x00101cbc:
      ((int (*)())Program__appendInst)(program,ppppppuVar38,currentBlock);
      goto code_r0x00101d1c;
    case 0x30:
      iVar43 = iVar47 + (int)templateCursor * 4;
      ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar38,program,ppppppuVar40,(double)*(float *)(iVar43 + 4),
                   (double)*(float *)(iVar43 + 8),(double)*(float *)(iVar43 + 0xc),
                   (double)*(float *)(iVar43 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      SelectWord__compose(&local_d8,*(undefined4 *)(operandRecord2 + 0x10),stagedSelectWord);
      selectWord = local_d8;
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(operandRecord2 + 0x10) = selectWord;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
      templateCursor = templateCursor + 1;
      break;
    case 0x31:
      compilerArenaB = *(undefined4 *)(*(int *)(program + 8) + 0x378);
      puVar32 = (undefined4 *)Arena__alloc(compilerArenaB,0x10);
      *puVar32 = compilerArenaB;
      puVar35 = puVar32 + 1;
      templateCursor = (int *)((int)templateCursor + 1);
      switch(*(undefined4 *)(iVar47 + (int)templateCursor * 4)) {
      case 0x3f:
        *puVar35 = (uint)*tokenWords >> 0x12 & 1;
        break;
      default:
        *puVar35 = 0;
        break;
      case 0x5f:
        *puVar35 = (uint)*tokenWords >> 0x18 & 1;
        break;
      case 0x67:
        *puVar35 = 1;
      }
      uVar10 = vectorAllocation[2];
      if (uVar10 < *puVar12) {
        _memset(uVar10 * 4 + vectorAllocation[3],0,4);
        vectorAllocation[2] = uVar10 + 1;
        vectorElementSlot3 = (undefined4 *)(uVar10 * 4 + vectorAllocation[3]);
      }
      else {
        vectorElementSlot3 = (undefined4 *)Vector__elementRefGrow(puVar12,uVar10);
      }
      local_bc = 0;
      *vectorElementSlot3 = puVar35;
      break;
    case 0x32:
      ppppppuVar48 = (uint ******)0x0;
      ifStackCount = (uint *****)ifStack[1];
      if (ifStackCount != (uint *****)0x0) {
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)((int)ifStackCount - 1U) < ifStackCount) {
          pppppuVar52 = (uint *****)(ifStack[2] + (int)((int)ifStackCount - 1U));
        }
        ppppppuVar48 = (uint ******)*pppppuVar52;
        ppppppuVar48[0x51] = (uint *****)0x0;
      }
      templateCursor = (int *)((int)templateCursor + 1);
      switch(*(undefined4 *)(iVar47 + (int)templateCursor * 4)) {
      case 0x62:
        pvVar16 = IRInst__create(0x8b,*(undefined4 *)(program + 8));
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,1,1.0,1.0,1.0,1.0);
        ((void (*)())IRInst__makeLiteralVec4Float)(pvVar16,program,2,1.0,1.0,1.0,1.0);
        *(undefined4 *)((int)pvVar16 + 300) = 0;
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        pppppuVar15 = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,argR7);
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
        pppppuVar15 = (uint *****)(blockAllocation4 + 1);
        argR6 = *(uint *******)(program + 8);
        IfHeaderStatic__ctor_ebac8(pppppuVar15,cmp1SInst,ppppppuVar48,argR6);
        Block__setField0xb8AndChildren(pppppuVar15,scopeLevel);
        IRInst__bindOperandRegisters(program,cmp1SInst);
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)ifStack[1] != (uint *****)0x0) {
          blockAllocation4[0x53] = 0;
          pppppuVar52 = (uint *****)ifStack[1];
        }
        if (pppppuVar52 < *ifStack) {
          _memset(ifStack[2] + (int)pppppuVar52,0,4);
          ifStack[1] = (uint ****)((int)pppppuVar52 + 1);
          pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar52);
        }
        else {
          pppppuVar52 = (uint *****)Vector__elementRefGrow(ifStack,pppppuVar52);
        }
        *pppppuVar52 = (uint ****)pppppuVar15;
        uVar10 = puVar13[2];
        if (uVar10 == 0) goto code_r0x00103240;
        goto code_r0x00103214;
      case 100:
        ppppuVar45 = *ilReader[0x1b];
        pppuVar42 = *ppppuVar45;
        compiler = *(int *)(program + 8);
        if ((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (compiler != 0)) {
          hwDescription = *(int **)(compiler + 0x30c);
          if ((hwDescription[2] & 0x80U) == 0) goto code_r0x00100810;
          sourceRegisterIndexB = 0xf;
        }
        else {
          hwDescription = *(int **)(compiler + 0x30c);
code_r0x00100810:
          sourceRegisterIndexB = (int)*(short *)((int)ppppuVar45 + 2);
        }
        ppppuVar45 = ilReader[0x1b][1];
        pppuVar33 = *ppppuVar45;
        if (((((uint)pppuVar33 & 0x3f0000) == 0x100000) && (compiler != 0)) &&
           ((hwDescription[2] & 0x80U) != 0)) {
          registerIndex = 0xf;
        }
        else {
          registerIndex = (int)*(short *)((int)ppppuVar45 + 2);
        }
        argR8 = (uint ******)((uint)pppuVar33 >> 0x10 & 0x3f);
        pvVar16 = (void *)(**(code **)(*hwDescription + 0x24))
                                    (hwDescription,(uint)*tokenWords >> 0x10 & 7,sourceRegisterIndexB,
                                     (uint)pppuVar42 >> 0x10 & 0x3f,registerIndex,argR8,stagedSelectWord,ilReader);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x15c);
        *blockAllocation4 = compilerArenaA;
        pppppuVar15 = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,argR7);
        break;
      case 0x65:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *puVar32 = compilerArenaA;
        puVar32 = puVar32 + 1;
        IRInst__ctor_10502c(puVar32,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 6;
        goto code_r0x00102c90;
      case 0x66:
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        puVar32 = (undefined4 *)Arena__alloc(compilerArenaA,0x168);
        *puVar32 = compilerArenaA;
        puVar32 = puVar32 + 1;
        IRInst__ctor_10502c(puVar32,0x8c,*(undefined4 *)(program + 8));
        comparisonKind = 7;
code_r0x00102c90:
        puVar32[0x4b] = comparisonKind;
        argR7 = (uint ******)ifStack;
        argR8 = loopStackData;
        pppppuVar15 = (uint *****)
                      ((int (*)())Program__createIfBlock)(program,puVar32,scopeLevel,ppppppuVar48,ifStack,loopStackData,
                                   ilReader);
        argR6 = ppppppuVar48;
        goto code_r0x00103240;
      default:
        pppppuVar15 = (uint *****)0x0;
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
        pppppuVar15 = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,ifConditionInst,ppppppuVar48,0,argR7);
        conditionStackTopIndex = conditionStack[1] - 1;
        if (conditionStackTopIndex < conditionStack[1]) {
          stackElement = (int *)(conditionStackTopIndex * 4 + conditionStack[2]);
        }
        else {
          stackElement = (int *)0x0;
        }
        iVar43 = *stackElement;
        FUN_000e77f4(pppppuVar15,*(undefined4 *)(iVar43 + 8));
        *(uint ******)(iVar43 + 8) = pppppuVar15;
        Block__setField0xb8AndChildren(pppppuVar15,scopeLevel);
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
        pppppuVar15 = (uint *****)(blockAllocation4 + 1);
        argR6 = (uint ******)0x0;
        argR7 = *(uint *******)(program + 8);
        IfHeader__ctor_ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,argR7);
      }
      Block__setField0xb8AndChildren(pppppuVar15,scopeLevel);
      IRInst__bindOperandRegisters(program,pvVar16);
code_r0x0010319c:
      pppppuVar52 = (uint *****)0x0;
      if ((uint *****)ifStack[1] != (uint *****)0x0) {
        pppppuVar15[0x52] = (uint ****)0x0;
        pppppuVar52 = (uint *****)ifStack[1];
      }
      if (pppppuVar52 < *ifStack) {
        _memset(ifStack[2] + (int)pppppuVar52,0,4);
        ifStack[1] = (uint ****)((int)pppppuVar52 + 1);
        pppppuVar52 = (uint *****)(ifStack[2] + (int)pppppuVar52);
      }
      else {
        pppppuVar52 = (uint *****)Vector__elementRefGrow(ifStack,pppppuVar52);
      }
      *pppppuVar52 = (uint ****)pppppuVar15;
      uVar10 = puVar13[2];
      if (uVar10 != 0) {
code_r0x00103214:
        stackElement = (int *)0x0;
        if (uVar10 - 1 < uVar10) {
          stackElement = (int *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        *(int *)(*stackElement + 300) = *(int *)(*stackElement + 300) + 1;
      }
code_r0x00103240:
      Program__insertBlockAfter(program,previousBlock,pppppuVar15);
      Block__connect(previousBlock,pppppuVar15);
      currentBlock = (uint *****)pppppuVar15[0x4d];
      previousBlock = pppppuVar15;
      Program__insertBlockAfter(program,pppppuVar15,currentBlock);
code_r0x00103300:
      local_bc = 0;
      previousBlock = currentBlock;
      break;
    case 0x34:
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      local_bc = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      *(undefined4 *)(operandRecord2 + 8) = 0;
      *(undefined4 *)(operandRecord2 + 0xc) = 0x21;
      break;
    case 0x35:
      stackElement = (int *)0x0;
      uVar10 = puVar13[2] - 1;
      if (uVar10 < (uint)puVar13[2]) {
        stackElement = (int *)(uVar10 * 4 + puVar13[3]);
      }
      iVar20 = *stackElement;
      iVar43 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),3);
      if ((iVar43 == 0) || (iVar43 = FUN_0012c2dc(program,iVar20), iVar43 == 0)) {
        argR6 = &previousBlock;
        argR7 = &currentBlock;
        argR8 = (uint ******)&scopeLevel;
        iVar43 = FUN_0012f0f8(program,loopStackData,iVar20,argR6,argR7,argR8);
        if (iVar43 != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0x4c) < (int)scopeLevel) {
          Compiler__fail(*(int *)(program + 8),8);
        }
        iVar21 = *(int *)(iVar20 + 0x150);
        Program__insertBlockAfter(program,previousBlock,iVar21);
        iVar43 = (*(code *)(*previousBlock)[0xe])();
        if ((iVar43 == 0) && (iVar43 = (*(code *)(*previousBlock)[0xf])(), iVar43 == 0)) {
          Block__connect(previousBlock,iVar21);
        }
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation4 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation4 = compilerArenaA;
        blockObject = blockAllocation4 + 1;
        Block__ctor_ea020(blockObject,*(undefined4 *)(program + 8));
        Block__connect(iVar20,blockObject);
        Program__insertBlockAfter(program,iVar21,blockObject);
        iVar43 = *(int *)(iVar20 + 0x154);
        Block__connect(blockObject,iVar43);
        Program__insertBlockAfter(program,blockObject,iVar43);
        compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
        blockAllocation3 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
        *blockAllocation3 = compilerArenaA;
        ppppppuVar48 = (uint ******)(blockAllocation3 + 1);
        Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
        currentBlock = (uint *****)ppppppuVar48;
        Program__insertBlockAfter(program,iVar43,ppppppuVar48);
        Block__connect(iVar43,currentBlock);
        previousBlock = currentBlock;
        Vector__removeAt(loopStackData,puVar13[2] + -1);
        local_bc = 0;
        *(uint *****)(iVar21 + 0xb8) = scopeLevel;
        scopeLevel = (uint ****)((int)scopeLevel - 1);
        *(uint *****)(iVar43 + 0xb8) = scopeLevel;
        blockAllocation4[0x2f] = scopeLevel;
        currentBlock[0x2e] = scopeLevel;
      }
      else {
        previousBlock = (uint *****)Block__findSimplePredecessor(iVar20);
        if (*(int **)(iVar20 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x150) + 4))();
        }
        if (*(int **)(iVar20 + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x154) + 4))();
        }
        Vector__removeValue(previousBlock[0x34],iVar20);
        do {
          ppppppuVar48 = (uint ******)previousBlock[2];
          pppppuVar15 = ppppppuVar48[0x26];
          for (pppppuVar52 = (uint *****)ppppppuVar48[0x26][2]; pppppuVar52 != (uint *****)0x0;
              pppppuVar52 = (uint *****)pppppuVar52[2]) {
            if (((uint)pppppuVar15[5] & 1) != 0) {
              pppppuVar15[5] = (uint ****)((uint)pppppuVar15[5] & 0xfffffffe);
            }
            pppppuVar15 = pppppuVar52;
          }
          DList__initSentinel(ppppppuVar48 + 0x24);
          DList__unlink(ppppppuVar48);
          if (ppppppuVar48 != (uint ******)0x0) {
            (*(code *)(*ppppppuVar48)[1])(ppppppuVar48);
          }
        } while (ppppppuVar48 != (uint ******)currentBlock);
        local_bc = 0;
        scopeLevel = (uint ****)((int)scopeLevel - 1);
        currentBlock = previousBlock;
      }
      break;
    case 0x36:
      uVar10 = puVar13[2];
      enclosingLoopHeader = 0;
      if (uVar10 != 0) {
        vectorElementSlot3 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          vectorElementSlot3 = (undefined4 *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        enclosingLoopHeader = *vectorElementSlot3;
      }
      argR6 = (uint ******)(uint)(ilOpcode == 0x71);
      if (argR6 == (uint ******)0x0) {
        uVar10 = (uint)*(ushort *)((int)*ilReader[0x1b] + 2);
      }
      else {
        uVar10 = 0;
      }
      arenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation4 = (undefined4 *)Arena__alloc(arenaA,0x15c);
      *blockAllocation4 = arenaA;
      blockObject = blockAllocation4 + 1;
      argR7 = *(uint *******)(program + 8);
      PostLoopFooter__ctor_ea828(blockObject,uVar10,enclosingLoopHeader,argR6,argR7);
      blockAllocation4[0x2f] = scopeLevel;
      if (((uint)*tokenWords & 0x10000) != 0) {
        blockAllocation4[0x4e] = 1;
      }
      IRInst__bindOperandRegisters(program,blockAllocation4[0x53]);
      pppppuVar15 = (uint *****)puVar13[2];
      if (pppppuVar15 < *loopStackData) {
        _memset((int)pppppuVar15 * 4 + puVar13[3],0,4);
        puVar13[2] = (int)pppppuVar15 + 1;
        vectorElementSlot2 = (undefined4 *)((int)pppppuVar15 * 4 + puVar13[3]);
      }
      else {
        vectorElementSlot2 = (undefined4 *)Vector__elementRefGrow(loopStackData,pppppuVar15);
      }
      *vectorElementSlot2 = blockObject;
      scopeLevel = (uint ****)((int)scopeLevel + 1);
      Program__insertBlockAfter(program,previousBlock,blockObject);
      Block__connect(previousBlock,blockObject);
      compilerArenaA = *(undefined4 *)(*(int *)(program + 8) + 0x374);
      blockAllocation2 = (undefined4 *)Arena__alloc(compilerArenaA,0x130);
      *blockAllocation2 = compilerArenaA;
      ppppppuVar48 = (uint ******)(blockAllocation2 + 1);
      Block__ctor_ea020(ppppppuVar48,*(undefined4 *)(program + 8));
      blockAllocation2[0x2f] = scopeLevel;
      currentBlock = (uint *****)ppppppuVar48;
      Program__insertBlockAfter(program,blockObject,ppppppuVar48);
      Block__connect(blockObject,currentBlock);
      previousBlock = currentBlock;
      local_bc = 0;
      blockAllocation4[0x4d] = *(undefined4 *)(*(int *)(program + 8) + 0x324);
      break;
    case 0x37:
      templateCursor = (int *)((int)templateCursor + 1);
      irOpcode = *(undefined4 *)(iVar47 + (int)templateCursor * 4);
      if (*(int *)(program + 0x47c) != 0) {
        irOpcode = 0x75;
      }
      ppppppuVar38 = IRInst__create(irOpcode,*(undefined4 *)(program + 8));
      local_bc = 0;
      break;
    case 0x38:
      local_b4 = 1;
      goto code_r0x00101d1c;
    case 0x3a:
      local_bc = 0;
      ppppppuVar38[0x48] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x3d:
      IROperand__setModifierBits(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,1,
                   (uint)ppppppuVar38[(int)ppppppuVar40 * 6 + 0x28] & 1 ^ 1);
      goto code_r0x00101d1c;
    case 0x42:
      templateCursor = (int *)((int)templateCursor + 1);
      dVar54 = (double)*(float *)(iVar47 + (int)templateCursor * 4);
      ((void (*)())IRInst__makeLiteralVec4Float)(ppppppuVar38,program,ppppppuVar40,dVar54,dVar54,dVar54,dVar54);
      goto code_r0x001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      ppppppuVar48 = (uint ******)
                     (PTR_s_IF_b_001dc2cc)[templateToken * 4 + ((uint)*tokenWords >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      ppppppuVar48 = *(uint *******)((int)&PTR_DAT_001dc75c + ((uint)*tokenWords >> 0xe & 0xc));
switchD_00102044_default:
      argR6 = (uint ******)currentBlock;
      argR8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&templateCursor,currentBlock,ppppppuVar48,ppppppuVar19);
      argR7 = ppppppuVar48;
code_r0x0010372c:
      local_bc = 0;
      break;
    case 0x4b:
      if ((((uint)*tokenWords & 0x10000) == 0) ||
         (bVar1 = true, (*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x40) != 0)) {
        bVar1 = false;
      }
      argR7 = (uint ******)PTR_DAT_001e8b98;
      if (bVar1) {
        argR7 = (uint ******)PTR_DAT_001e8b9c;
      }
code_r0x001022b4:
      argR6 = (uint ******)currentBlock;
      argR8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&templateCursor,currentBlock,argR7,ppppppuVar19);
      goto code_r0x0010372c;
    case 0x4d:
      local_bc = 0;
      *(ushort *)((int)ppppppuVar38[0x4f] + 0x12) = (byte)((uint)*tokenWords >> 0x18) & 1;
      break;
    case 0x4e:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*tokenWords >> 0x10 & 7,*(undefined4 *)(program + 8),0);
      goto code_r0x00101f74;
    case 0x4f:
      templateCursor = (int *)((int)templateCursor + 1);
      ((void (*)())IRInst__setExtraFixed3_4_1048d4)(ppppppuVar38,(double)*(float *)(iVar47 + (int)templateCursor * 4));
      goto code_r0x00101d1c;
    case 0x50:
      templateCursor = (int *)((int)templateCursor + 1);
      ((void (*)())IRInst__setExtraFixed3_4_10490c)(ppppppuVar38,(double)*(float *)(iVar47 + (int)templateCursor * 4));
      goto code_r0x00101d1c;
    case 0x51:
      ilRegisterIndex = *(byte *)((int)ilReader + 0x8d);
      pppppuVar15 = (uint *****)(uint)ilRegisterIndex;
      if ((*(uint *)((int)usedRegisterBitmap + (ilRegisterIndex >> 3 & 0x1c) + 8) >> (ilRegisterIndex & 0x1f) & 1) == 0) {
        Compiler__logf(*(undefined4 *)(program + 8),"TextureStage %d misses DCLPT\n",pppppuVar15,argR6
                     ,argR7,argR8,ilRegisterIndex & 0x1f,0);
      }
      pppppuVar52 = *(uint ******)(program + 0x7c);
      if ((int)*(uint ******)(program + 0x7c) < (int)pppppuVar15) {
        pppppuVar52 = pppppuVar15;
      }
      *(uint ******)(program + 0x7c) = pppppuVar52;
      *(uint *)(program + 0x84) = 1 << ((uint)pppppuVar15 & 0x3f) | *(uint *)(program + 0x84);
      ppppppuVar38[0x4d] = pppppuVar15;
      ppppppuVar38[0x4c] = pppppuVar15;
      local_bc = 0;
      pppppuVar15 = (uint *****)
                    ((int (*)())remapSelect1To0)(*(undefined4 *)((int)pppppuVar15 * 0xc + *(int *)(program + 0x78)))
      ;
      ppppppuVar38[0x4e] = pppppuVar15;
      break;
    case 0x52:
      local_bc = 0;
      ppppppuVar38[0x4d] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      ppppppuVar38[0x4c] = (uint *****)(uint)*(byte *)((int)ilReader + 0x8d);
      break;
    case 0x53:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*tokenWords >> 0x10 & 7,*(undefined4 *)(program + 8),1);
code_r0x00101f74:
      if (ppppppuVar48 != (uint ******)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      firstTokenWord = *tokenWords;
      registerIndex2 = *(short *)((int)*ilReader[0x19] + 2);
      ilRegisterType = (uint)**ilReader[0x19] >> 0x10 & 0x3f;
      Program__registerFileOfIlType(program,ilRegisterType);
      uVar50 = *(undefined4 *)(program + 0x3ac);
      registerFile = Program__registerFileOfIlType(program,ilRegisterType);
      argR6 = (uint ******)0x0;
      virtualRegister43 = VRegPool__findOrCreate(uVar50,registerFile,(int)registerIndex2,0);
      if (((uint)firstTokenWord >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      local_bc = 0;
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
      iVar43 = (&local_104)[templateToken - 0x55];
      if (iVar43 == 0) {
        iVar43 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = iVar43;
        (&local_104)[templateToken - 0x55] = iVar43;
      }
      operandRecordLast = IRInst__getOperandRecord(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(operandRecordLast + 0xc) = 0;
      *(int *)(operandRecordLast + 8) = iVar43;
      if (ppppppuVar40 == (uint ******)0x0) {
        argR6 = (uint ******)0x0;
        argR7 = (uint ******)0x0;
        argR8 = ppppppuVar38;
        ((int (*)())IRInst__applyDescriptorSelects)(program,loopStackData,local_124,0,0,ppppppuVar38,0);
      }
      else {
        argR6 = ppppppuVar40;
        argR7 = ppppppuVar38;
        ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,0,ppppppuVar40,ppppppuVar38);
      }
      goto code_r0x001025c0;
    case 0x60:
      vectorElementSlot3 = (undefined4 *)0x0;
      uVar10 = vectorAllocation[2] - 1;
      if (uVar10 < (uint)vectorAllocation[2]) {
        vectorElementSlot3 = (undefined4 *)(uVar10 * 4 + vectorAllocation[3]);
      }
      if (*(int *)*vectorElementSlot3 != 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)templateCursor * 4 + iVar47);
      do {
        piVar36 = templateCursor;
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)templateCursor + 1);
          piVar18 = piVar18 + 1;
        }
        templateCursor = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x26);
      local_bc = 0;
      templateCursor = piVar36;
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
      argR8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&templateCursor,ppppppuVar39,argR7,ppppppuVar19);
      argR6 = ppppppuVar39;
      goto code_r0x0010372c;
    case 0x6c:
      (*(code *)(*ppppppuVar38)[9])(ppppppuVar38);
      local_bc = 0;
      ppppppuVar38[0x4b] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x6d:
      operandRecord2 = IRInst__getOperandRecord(ppppppuVar38,1);
      iVar20 = *(int *)(operandRecord2 + 0x10);
      iVar43 = *(int *)(local_60 + -0x2c30);
      if (iVar20 != iVar43) {
        registerMap = *(undefined4 *)(program + 0x3ac);
        argR6 = (uint ******)0x0;
        newTempIndex21 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex21;
        virtualRegister = VRegPool__findOrCreate(registerMap,0,newTempIndex21,0);
        movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandRef(movFloatInst,1,virtualRegister);
        pppppuVar52 = ppppppuVar38[0x25];
        pppppuVar15 = ppppppuVar38[0x26];
        operandRecordB = IRInst__getOperandRecord(movFloatInst,0);
        *(uint ******)(operandRecordB + 0xc) = pppppuVar15;
        *(uint ******)(operandRecordB + 8) = pppppuVar52;
        operandRecordB = IRInst__getOperandRecord(movFloatInst,1);
        *(int *)(operandRecordB + 0x10) = iVar20;
        operandRecordB = IRInst__getOperandRecord(ppppppuVar38,0);
        *(undefined4 *)((int)movFloatInst + 0x9c) = *(undefined4 *)(operandRecordB + 0x10);
        IRInst__setOperandRef(ppppppuVar38,0,virtualRegister);
        FUN_000f32cc(&local_d4,iVar20);
        ppppppuVar38[0x27] = (uint *****)local_d4;
        operandRecordLast = IRInst__getOperandRecord(ppppppuVar38,1);
        *(int *)(operandRecordLast + 0x10) = iVar43;
        DList__pushFront(local_6c,movFloatInst);
        goto code_r0x00101d1c;
      }
switchD_0010061c_caseD_1:
      local_bc = 0;
      break;
    case 0x6e:
      templateCursor = (int *)((int)templateCursor + 1);
      argR6 = *(uint *******)(iVar47 + (int)templateCursor * 4);
      argR7 = argR6;
      argR8 = argR6;
      ((int (*)())IRInst__setIntConstantOperand4)(ppppppuVar38,program,ppppppuVar40,argR6,argR6,argR6,argR6);
code_r0x001025c0:
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      local_bc = 0;
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
        uVar50 = *vectorElementSlot3;
        Vector__removeAt(conditionStack,conditionStack[1] - 1);
        Arena__free(compilerArenaB,uVar50);
      }
      else {
        stackElement = (int *)0x0;
        if (conditionStackCount - 1 < conditionStack[1]) {
          stackElement = (int *)((conditionStackCount - 1) * 4 + conditionStack[2]);
        }
        argR6 = (uint ******)0x0;
        *(int *)(*stackElement + 4) = *(int *)(*stackElement + 4) + -1;
        templateCursor = (int *)((int)templateCursor + -1);
        argR8 = ppppppuVar19;
        iVar47 = ((int (*)())FUN_000fd50c)(program,iVar47,&templateCursor,0,ppppppuVar48,ppppppuVar19);
        argR7 = ppppppuVar48;
      }
code_r0x00101d1c:
      local_bc = 0;
      break;
    case 0x71:
      local_bc = 0;
      ppppppuVar38[0x50] = *(uint ******)(iVar47 + ((int)templateCursor + 1) * 4);
      templateCursor = (int *)((int)templateCursor + 1);
    }
    goto code_r0x00103b34;
  case 7:
    isTranslationKind7 = true;
  }
  ppppppuVar19 = (uint ******)((int (*)())FUN_000f9140)(program,ilOpcode,(uint)*tokenWords >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(program,local_6c,*ilReader[0x19],loopStackData,local_a4);
  registerIndex2 = *(short *)((int)*ilReader[0x19] + 2);
  registerFile = Program__registerFileOfIlType(program,(uint)**ilReader[0x19] >> 0x10 & 0x3f);
  operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,0);
  *(undefined4 *)(operandRecord2 + 0xc) = registerFile;
  *(int *)(operandRecord2 + 8) = (int)registerIndex2;
  argR7 = (uint ******)0x0;
  argR6 = (uint ******)*ilReader[0x19];
  argR8 = ppppppuVar19;
  ((int (*)())IRInst__applyDescriptorSelects)(program,loopStackData,0,argR6,0,ppppppuVar19,0);
  iVar43 = ((int (*)())FUN_000f8970)(ilOpcode,*(undefined4 *)(*(int *)(*(int *)(program + 8) + 0x30c) + 0xc));
  ppppppuVar38 = (uint ******)(iVar43 + 1);
  if (1 < (int)ppppppuVar38) {
    ppppppuVar40 = (uint ******)((int)((unsigned char *)0x0) + 1);
    loopCounterC = 0;
    local_60 = &DAT_001ad5d8;
    do {
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      argR8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(program,local_68,tokenWords,*(undefined4 *)(loopCounterC + (int)ilReader[0x1b]),
                   loopStackData,&local_174,&movByRegister);
      uVar10 = **(uint **)(loopCounterC + (int)ilReader[0x1b]);
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(program + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar47 = 0xf;
      }
      else {
        iVar47 = (int)(short)**(uint **)(loopCounterC + (int)ilReader[0x1b]);
      }
      registerFile = Program__registerFileOfIlType(program,uVar10 >> 0x10 & 0x3f);
      operandRecordLast = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar40);
      *(undefined4 *)(operandRecordLast + 0xc) = registerFile;
      *(int *)(operandRecordLast + 8) = iVar47;
      if ((!isTranslationKind7) &&
         (iVar47 = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),ppppppuVar19), iVar47 != 0)) {
        if (ppppppuVar40 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          puVar12 = &UNK_001aa9d4;
        }
        else {
          puVar12 = &DAT_001aa9cc;
        }
        stagedSelectWord = (uint ******)*puVar12;
      }
      argR6 = ppppppuVar40;
      argR7 = ppppppuVar19;
      ((int (*)())Program__applySourceTokenToOperand)(program,&stagedSelectWord,*(undefined4 *)(loopCounterC + (int)ilReader[0x1b]),ppppppuVar40,
                   ppppppuVar19);
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      loopCounterC = loopCounterC + 4;
    } while (ppppppuVar38 != ppppppuVar40);
  }
  local_b8 = IRInst__countWrittenComponents(ppppppuVar19);
  if (isTranslationKind7) {
    newTempIndex20 = *(int *)(*(int *)(program + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(program + 8) + 0x3ac) = newTempIndex20;
    pppppuVar52 = ppppppuVar19[0x25];
    pppppuVar15 = ppppppuVar19[0x26];
    operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,0);
    *(int *)(operandRecord2 + 8) = newTempIndex20;
    *(undefined4 *)(operandRecord2 + 0xc) = 0;
    iVar43 = OpcodeTraits__instFlagBit2(*(undefined4 *)(program + 8),ppppppuVar19);
    iVar47 = IRInst__getOperandRecord(ppppppuVar19,0);
    ppppppuVar40 = *(uint *******)(iVar47 + 0x10);
    stagedSelectWord = ppppppuVar40;
    if (1 < local_b8) {
      local_7c = (uint ****)&scopeLevel;
      iVar47 = 0;
      local_58 = local_7c;
      do {
        iVar21 = SelectWord__firstWrittenComponent(stagedSelectWord);
        iVar22 = ((int (*)())FUN_000f9140)(program,ilOpcode,(uint)*tokenWords >> 0x10 & 0x3fff);
        ppppuVar45 = local_58;
        if (0 < (int)ppppppuVar38) {
          ppppppuVar48 = (uint ******)0x0;
          do {
            argR6 = ppppppuVar48;
            IRInst__copyOperandFrom(iVar22,ppppppuVar48,ppppppuVar19,ppppppuVar48);
            if (iVar43 != 0) {
              operandRecordC = IRInst__getOperandRecord(iVar22,ppppppuVar48);
              pppppuVar11 = *(uint ******)(operandRecordC + 0x10);
              if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
                local_124 = (uint *****)
                            CONCAT31((int3)((uint)pppppuVar11 >> 8),
                                     *(undefined1 *)((int)ppppuVar45 + iVar21 + 100));
              }
              else if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
                local_124 = (uint *****)
                            CONCAT13(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),
                                     (int3)pppppuVar11);
              }
              else {
                local_124 = pppppuVar11;
                if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
                  (*(unsigned short *)((unsigned char *)&(local_124) + 0)) = (undefined2)((uint)pppppuVar11 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(local_124) + 2)) =
                       CONCAT11(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),(char)pppppuVar11);
                }
              }
              pppppuVar11 = local_124;
              iVar23 = IRInst__getOperandRecord(iVar22,ppppppuVar48);
              *(uint ******)(iVar23 + 0x10) = pppppuVar11;
            }
            ppppppuVar48 = (uint ******)((int)ppppppuVar48 + 1);
          } while (ppppppuVar38 != ppppppuVar48);
        }
        *(undefined4 *)(iVar22 + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + iVar21 * 4);
        *(undefined1 *)((int)local_7c + iVar21 + 0x10) = 1;
        *(uint ******)(iVar22 + 0x120) = ppppppuVar19[0x48];
        DList__pushBack(local_68,iVar22);
        iVar47 = iVar47 + 1;
      } while (local_b8 + -1 != iVar47);
    }
    ppppppuVar19[0x27] = (uint *****)stagedSelectWord;
    if ((iVar43 != 0) && (iVar34 = SelectWord__firstWrittenComponent(stagedSelectWord), 1 < (int)ppppppuVar38)) {
      ppppppuVar49 = (uint ******)((int)((unsigned char *)0x0) + 1);
      do {
        operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar49);
        ppppppuVar48 = *(uint *******)(operandRecord2 + 0x10);
        local_104 = ppppppuVar48;
        if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          local_104 = (uint ******)
                      CONCAT31((int3)((uint)ppppppuVar48 >> 8),
                               *(undefined1 *)((int)&local_104 + iVar34));
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
          local_104 = (uint ******)
                      CONCAT13(*(undefined1 *)((int)&local_104 + iVar34),(int3)ppppppuVar48);
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
          (*(unsigned short *)((unsigned char *)&(local_104) + 0)) = (undefined2)((uint)ppppppuVar48 >> 0x10);
          (*(unsigned short *)((unsigned char *)&(local_104) + 2)) = CONCAT11(*(undefined1 *)((int)&local_104 + iVar34),(char)ppppppuVar48);
        }
        ppppppuVar48 = local_104;
        operandRecord2 = IRInst__getOperandRecord(ppppppuVar19,ppppppuVar49);
        ppppppuVar49 = (uint ******)((int)ppppppuVar49 + 1);
        *(uint *******)(operandRecord2 + 0x10) = ppppppuVar48;
      } while (ppppppuVar38 != ppppppuVar49);
    }
    movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    operandRecord = IRInst__getOperandRecord(movFloatInst,0);
    *(uint ******)(operandRecord + 0xc) = pppppuVar15;
    *(uint ******)(operandRecord + 8) = pppppuVar52;
    *(uint *******)((int)movFloatInst + 0x9c) = ppppppuVar40;
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    *(int *)(operandRecord + 8) = newTempIndex20;
    *(undefined4 *)(operandRecord + 0xc) = 0;
    DList__pushFront(local_6c,movFloatInst);
  }
  hwDescription = *(int **)(*(int *)(program + 8) + 0x30c);
  iVar34 = (**(code **)(*hwDescription + 0x34))(hwDescription,ppppppuVar19);
  if (iVar34 == 0) {
code_r0x001002dc:
    movFloatInst = (void *)0x0;
  }
  else {
    operandRecord = IRInst__getOperandRecord(ppppppuVar19,0);
    iVar47 = 0;
    loopCounterC = 0;
    stagedSelectWord = *(uint *******)(operandRecord + 0x10);
    argR8 = (uint ******)&local_104;
    local_104 = *(uint *******)(operandRecord + 0x10);
    loopCounter = 4;
    argR7 = (uint ******)&stagedSelectWord;
    iVar34 = -1;
    do {
      iVar21 = iVar34;
      if (*(char *)(loopCounterC + (int)argR8) == '\0') {
        iVar21 = loopCounterC;
        if ((iVar47 != 0) && (iVar21 = iVar34, 0 < iVar47)) {
          *(undefined1 *)(loopCounterC + (int)argR7) = 1;
        }
        iVar47 = iVar47 + 1;
      }
      loopCounterC = loopCounterC + 1;
      loopCounter = loopCounter + -1;
      iVar34 = iVar21;
    } while (loopCounter != 0);
    if (iVar47 < 2) goto code_r0x001002dc;
    loopCounterC = 4;
    ppppppuVar19[0x27] = (uint *****)stagedSelectWord;
    loopCounterB = 0;
    argR7 = (uint ******)&local_124;
    do {
      *(char *)(loopCounterB + (int)argR7) = (char)iVar21;
      loopCounterB = loopCounterB + 1;
      loopCounterC = loopCounterC + -1;
    } while (loopCounterC != 0);
    movFloatInst = IRInst__create(0x31,*(undefined4 *)(program + 8));
    pppppuVar15 = ppppppuVar19[0x25];
    pppppuVar52 = ppppppuVar19[0x26];
    operandRecord = IRInst__getOperandRecord(movFloatInst,0);
    *(uint ******)(operandRecord + 0xc) = pppppuVar52;
    *(uint ******)(operandRecord + 8) = pppppuVar15;
    pppppuVar52 = ppppppuVar19[0x25];
    *(uint *******)((int)movFloatInst + 0x9c) = local_104;
    pppppuVar11 = ppppppuVar19[0x26];
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    pppppuVar15 = local_124;
    *(uint ******)(operandRecord + 0xc) = pppppuVar11;
    *(uint ******)(operandRecord + 8) = pppppuVar52;
    operandRecord = IRInst__getOperandRecord(movFloatInst,1);
    *(uint ******)(operandRecord + 0x10) = pppppuVar15;
  }
  iVar43 = *(int *)(local_14c + 8);
  iVar34 = local_14c;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  ((int (*)())Program__appendInst)(program,ppppppuVar19,currentBlock);
  if (movFloatInst != (void *)0x0) {
    ((int (*)())Program__appendInst)(program,movFloatInst,currentBlock);
  }
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  local_bc = 1;
code_r0x00103b34:
  if (ppppppuVar38 != (uint ******)0x0) {
code_r0x00103b3c:
    iVar43 = (*(code *)(*ppppppuVar38)[5])(ppppppuVar38);
    if ((uint ******)(iVar43 + 1U) == ppppppuVar40) {
      ((int (*)())Program__appendInst)(program,ppppppuVar38,currentBlock);
      ppppppuVar38 = (uint ******)0x0;
      ppppppuVar40 = (uint ******)0x0;
      stagedSelectWord = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint ******)(local_78 + -0x2bfc);
    }
  }
  if (local_bc != 0) goto code_r0x00103bb0;
  templateCursor = (int *)((int)templateCursor + 1);
  goto code_r0x001005f4;
code_r0x00103bb0:
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    DList__unlink(iVar34);
    ((int (*)())Program__appendInst)(program,iVar34,currentBlock);
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  if (puVar12 != (uint *)0x0) {
    Arena__free(vectorAllocation[4],vectorAllocation[3]);
    Arena__free(*vectorAllocation,vectorAllocation);
  }
  if (ppppppuVar19 != (uint ******)0x0) {
    Arena__free(vectorAllocation2[4],vectorAllocation2[3]);
    Arena__free(*vectorAllocation2,vectorAllocation2);
  }
  goto switchD_000fdaf0_caseD_2;
}
#undef local_14c
#undef local_164
