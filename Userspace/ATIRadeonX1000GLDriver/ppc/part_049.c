#include "decls.h"

/* FUN_00186510 @ 0x186510 (1400 bytes) */
int FUN_00186510(inst, param_2, param_3, compiler)
  int inst;
  undefined4 *param_2;
  undefined4 *param_3;
  int compiler;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  char *loopIndex5;
  int loopIndex2;
  int loopIndex3;
  uint uVar7;
  int loopIndex4;
  int *inst1;
  int *loopIndex6;
  undefined1 *puVar11;
  int loopIndex;
  int local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  undefined4 local_64;
  int local_60;
  undefined4 uStack_5c;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  loopIndex2 = IRInst__getOperandRecord(inst,1);
  local_60 = *(int *)(loopIndex2 + 0x10);
  loopIndex2 = IRInst__getOperandRecord(inst,2);
  local_78 = *(int *)(loopIndex2 + 0x10);
  if (local_60 == local_78) {
    return 1;
  }
  loopIndex2 = IRInst__getOperandRecord(inst,0);
  loopIndex4 = 0;
  local_64 = *(undefined4 *)(loopIndex2 + 0x10);
  do {
    loopIndex2 = 0;
    loopIndex5 = &DAT_001b0228 + loopIndex4 * 4;
    loopIndex = 4;
    while ((*(char *)((int)&local_64 + loopIndex2) != '\0' ||
           ((*(char *)((int)&local_78 + loopIndex2) == *(char *)((int)&local_60 + loopIndex2) &&
            (*(char *)((int)&local_78 + loopIndex2) == *loopIndex5))))) {
      loopIndex2 = loopIndex2 + 1;
      loopIndex5 = loopIndex5 + 1;
      loopIndex = loopIndex + -1;
      if (loopIndex == 0) {
        return 1;
      }
    }
    bVar1 = loopIndex4 != 4;
    loopIndex4 = loopIndex4 + 1;
  } while (bVar1);
  loopIndex2 = IRInst__isSourceSelectIdentity(inst,1);
  if ((loopIndex2 == 0) && (loopIndex2 = IRInst__isSourceSelectIdentity(inst,2), loopIndex2 == 0)) {
    *(int *)(*(int *)(compiler + 0x6c4) + 0x204) = *(int *)(*(int *)(compiler + 0x6c4) + 0x204) + 1;
    return 0;
  }
  inst1 = (int *)*param_2;
  loopIndex4 = 1;
  loopIndex6 = (int *)*param_3;
  loopIndex2 = IRInst__isSourceSelectIdentity(inst,1);
  if (loopIndex2 != 0) {
    loopIndex4 = 2;
    local_60 = local_78;
    inst1 = loopIndex6;
  }
  loopIndex = *(int *)(compiler + 0x6c4);
  loopIndex2 = IRInst__getOperandRecord(inst,0);
  local_74 = *(uint *)(loopIndex2 + 0x10);
  loopIndex2 = IRInst__getOperandRecord(inst1,0);
  local_70 = *(uint *)(loopIndex2 + 0x10);
  local_6c = DAT_001b0224;
  if ((inst1[5] & 0x200U) != 0) {
    *(int *)(*(int *)(compiler + 0x6c4) + 0x204) = *(int *)(*(int *)(compiler + 0x6c4) + 0x204) + 1;
    loopIndex2 = IRInst__getOperandRecord(inst1,inst1[0x21]);
    loopIndex3 = 0;
    local_6c = *(int *)(loopIndex2 + 0x10);
    loopIndex2 = 4;
    do {
      if ((*(byte *)((int)&local_60 + loopIndex3) != 4) &&
         (*(char *)((int)&local_6c + (uint)*(byte *)((int)&local_60 + loopIndex3)) != '\x04')) {
        bVar1 = false;
        goto LAB_00186708;
      }
      loopIndex3 = loopIndex3 + 1;
      loopIndex2 = loopIndex2 + -1;
    } while (loopIndex2 != 0);
  }
  bVar1 = true;
LAB_00186708:
  local_68 = DAT_001b0220;
  if (bVar1) {
    loopIndex2 = FUN_0011379c(compiler,inst1);
    if (loopIndex2 == 0) {
      loopIndex2 = OpcodeTraits__flagBit8(*(undefined4 *)(inst1[0x22] + 8),compiler);
      if (loopIndex2 == 0) goto LAB_00186a60;
      loopIndex2 = IRInst__hasSingleUse(inst1,loopIndex);
      uVar3 = DAT_001b0220;
      if (loopIndex2 == 0) {
        loopIndex2 = 0;
        loopIndex3 = 4;
        do {
          if (((*(char *)((int)&local_74 + loopIndex2) == '\0') &&
              (*(char *)((int)&local_70 + loopIndex2) != '\0')) &&
             ((*(char *)((int)&local_70 + loopIndex2) != '\x01' ||
              (*(char *)((int)&local_6c + loopIndex2) != '\x04')))) goto LAB_00186a60;
          loopIndex2 = loopIndex2 + 1;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      inst1[0x27] = local_68;
      WriteMask__fromSelectWord(&local_40,local_68);
      SelectWord__maskUnused(local_3c,uVar3,local_40);
    }
    else {
      loopIndex2 = IRInst__hasSingleUse(inst1,loopIndex);
      if (loopIndex2 == 0) {
        loopIndex2 = 0;
        loopIndex3 = 4;
        do {
          if ((*(char *)((int)&local_74 + loopIndex2) == '\0') &&
             ((*(char *)((int)&local_70 + loopIndex2) != '\x01' ||
              (*(char *)((int)&local_6c + loopIndex2) != '\x04')))) goto LAB_00186a60;
          loopIndex2 = loopIndex2 + 1;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
        uVar7 = (local_74 << 0x18 | (local_74 >> 8 & 0xff) << 0x10 | (local_74 >> 0x10 & 0xff) << 8
                | local_74 >> 0x18) &
                (local_70 << 0x18 | (local_70 >> 8 & 0xff) << 0x10 | (local_70 >> 0x10 & 0xff) << 8
                | local_70 >> 0x18);
        local_68 = uVar7 << 0x18 | (uVar7 & 0xff00) << 8 | uVar7 >> 8 & 0xff00 | uVar7 >> 0x18;
      }
      else {
        local_68 = local_74;
      }
      loopIndex2 = FUN_000f2e18(local_68);
      if (loopIndex2 == 0) goto LAB_00186a60;
      loopIndex3 = 1;
      inst1[0x27] = local_68;
      loopIndex2 = IRInst__hasSingleUse(inst1,loopIndex);
      if (loopIndex2 == 0) {
        for (; loopIndex2 = (**(code **)(*inst1 + 0x14))(inst1), loopIndex3 <= loopIndex2; loopIndex3 = loopIndex3 + 1) {
          loopIndex2 = IRInst__getOperandRecord(inst1,loopIndex3);
          (&uStack_5c)[loopIndex3] = *(undefined4 *)(loopIndex2 + 0x10);
        }
      }
      else {
        loopIndex6 = local_58;
        for (; loopIndex2 = (**(code **)(*inst1 + 0x14))(inst1), loopIndex3 <= loopIndex2; loopIndex3 = loopIndex3 + 1) {
          *loopIndex6 = DAT_001b0224;
          loopIndex6 = loopIndex6 + 1;
        }
      }
      loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
      loopIndex = 0;
      local_64 = *(undefined4 *)(loopIndex2 + 0x10);
      do {
        if (*(char *)((int)&local_74 + loopIndex) == '\0') {
          loopIndex2 = 1;
          puVar11 = (undefined1 *)((int)local_58 + loopIndex);
          while( true ) {
            loopIndex3 = (**(code **)(*inst1 + 0x14))(inst1);
            if (loopIndex3 < loopIndex2) break;
            bVar2 = *(byte *)((int)&local_64 + loopIndex);
            loopIndex3 = IRInst__getOperandRecord(inst1,loopIndex2);
            *puVar11 = *(undefined1 *)((uint)bVar2 + loopIndex3 + 0x10);
            loopIndex2 = loopIndex2 + 1;
            puVar11 = puVar11 + 4;
          }
        }
        bVar1 = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      loopIndex6 = local_58;
      for (loopIndex2 = 1; loopIndex = (**(code **)(*inst1 + 0x14))(inst1), uVar3 = DAT_001b0220,
          loopIndex2 <= loopIndex; loopIndex2 = loopIndex2 + 1) {
        loopIndex = *loopIndex6;
        if (loopIndex2 == 0) {
          inst1[0x27] = loopIndex;
        }
        else {
          loopIndex3 = IRInst__getOperandRecord(inst1,loopIndex2);
          *(int *)(loopIndex3 + 0x10) = loopIndex;
        }
        loopIndex6 = loopIndex6 + 1;
      }
      WriteMask__fromSelectWord(&local_48,local_74);
      SelectWord__maskUnused(&local_44,uVar3,local_48);
      local_3c[0] = local_44;
    }
    if (loopIndex4 == 0) {
      uVar3 = 1;
      *(undefined4 *)(inst + 0x9c) = local_3c[0];
    }
    else {
      loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
      uVar3 = 1;
      *(undefined4 *)(loopIndex2 + 0x10) = local_3c[0];
    }
  }
  else {
LAB_00186a60:
    uVar3 = 0;
    *(int *)(loopIndex + 0x204) = *(int *)(loopIndex + 0x204) + 1;
  }
  return uVar3;
}

/* FUN_00186a88 @ 0x186a88 (2816 bytes) */
int FUN_00186a88(inst, operandIndex, inst2, program, param_5, param_6, param_7)
  int *inst;
  int operandIndex;
  int *inst2;
  int program;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int sourceRegKindIsConstant;
  int operandKindIsConstant;
  int constantLaneResult;
  int lanesRemaining;
  int programCopy;
  int *originalInst2;
  uint negate;
  uint inst2Flags;
  int commitResult;
  int *operandSource2;
  int operandSource;
  undefined4 sourceRegKind;
  undefined4 createOwner;
  undefined4 presubOpcode;
  undefined4 compiler;
  undefined4 newRegId;
  int destRecord;
  int *constantKindPtr;
  int uniformConstantFound;
  int *selectWord;
  int *laneCursor;
  undefined4 programValueTable;
  int firstSourceIsPresub;
  int source1Record;
  int laneNumber;
  int lanesLeft;
  int operandRecord;
  int opcodeInfo;
  int *producerSource;
  int sourceNumber;
  int selectsLeft;
  int isUndefined;
  int flagBit0Result;
  int operandNumber;
  int isMov;
  int isFetch;
  int isPresub;
  int numSources;
  undefined4 sourceDef;
  bool isFloatConstant;
  uint laneSelect;
  uint otherNegate;
  int loopIndex;
  int loopIndex2;
  int *loopIndex4;
  int loopRemaining;
  void *inst3;
  undefined4 uVar9;
  undefined4 compilerCtx;
  int *destSelectCursor;
  int *loopIndex3;
  undefined4 destSelect;
  undefined4 valueNumberTable;
  int *local_a8;
  int *local_a4 [10];
  int constLanes [4];
  int constantKind;
  float constantValue;
  
  local_a4[9] = (int *)0x3f800000;
  local_a4[5] = (int *)0x3f000000;
  local_a4[6] = (int *)0x3f800000;
  local_a4[7] = (int *)0x3f800000;
  local_a4[8] = (int *)0x3f800000;
  local_a4[2] = (int *)0x3f000000;
  local_a4[3] = (int *)0x3f000000;
  local_a4[4] = (int *)0x3f000000;
  if (inst == (int *)0x0) {
    return 0;
  }
  programCopy = program;
  compilerCtx = param_5;
  uVar9 = param_6;
  IRInst__getOperandSource(inst,operandIndex);
  numSources = (**(code **)(*inst + 0x14))(inst);
  if (numSources < operandIndex) {
    return 0;
  }
  isPresub = (**(code **)(*inst + 0x5c))(inst);
  if (isPresub != 0) {
    return 0;
  }
  isFetch = (**(code **)(*inst + 0x28))(inst);
  if (isFetch != 0) {
    return 0;
  }
  if ((inst[5] & 2U) != 0) {
    return 0;
  }
  isMov = (**(code **)(*inst + 100))(inst);
  if (isMov != 0) {
    for (operandNumber = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), operandNumber <= loopIndex2;
        operandNumber = operandNumber + 1) {
      if ((((inst[operandNumber * 6 + 0x28] & 1U) != 0) || ((inst[operandNumber * 6 + 0x28] & 2U) != 0)) ||
         (loopIndex2 = IRInst__isSourceSelectIdentity(inst,operandNumber), loopIndex2 == 0)) goto LAB_001874d4;
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) &&
          ((flagBit0Result = RegKind__flagBit0(inst[0x26]), flagBit0Result != 0 && ((inst[5] & 2U) == 0)))) &&
         (isUndefined = (**(code **)(*inst + 0x50))(inst), isUndefined == 0)) {
        selectsLeft = 4;
        destSelectCursor = inst;
        do {
          if ((uint)(*(byte *)(destSelectCursor + 0x27) - 2) < 2) goto LAB_001874d4;
          destSelectCursor = (int *)((int)destSelectCursor + 1);
          selectsLeft = selectsLeft + -1;
        } while (selectsLeft != 0);
      }
      IRInst__getOperandRecord(inst,0);
      loopIndex = FUN_00105dbc(inst,0);
      if (((loopIndex == 0) && ((inst[5] & 2U) == 0)) && ((inst[5] & 0x200U) == 0)) {
        return 0;
      }
    }
  }
LAB_001874d4:
  if (*(int *)(inst[0x22] + 8) == 0x8e) {
    return 0;
  }
  isPresub = (**(code **)(*inst2 + 0x5c))(inst2);
  if (isPresub != 0) {
    return 0;
  }
  if (inst2[0x48] != 0) {
    return 0;
  }
  loopIndex = ((int (*)())FUN_001897fc)(inst,operandIndex);
  if (loopIndex != 0) {
    return 0;
  }
  inst2Flags = inst2[5];
  originalInst2 = (int *)0x0;
  if ((inst2Flags & 0x200) != 0) {
    loopIndex2 = inst2[1];
    DList__unlink(inst2);
    local_a8 = (int *)IRInst__clone(inst2,*(undefined4 *)(program + 8),1);
    loopIndex = FUN_00162dfc(&local_a8,1,program);
    if (loopIndex == 0) {
      Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),loopIndex2,inst2);
      return 0;
    }
    Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),loopIndex2,local_a8);
    Block__insertInstAfter(*(undefined4 *)(loopIndex2 + 0x158),local_a8,inst2);
    inst2Flags = local_a8[5];
    originalInst2 = inst2;
    inst2 = local_a8;
  }
  if ((inst2Flags & 0x200) != 0) {
    return 0;
  }
  if (0 < inst2[0x21]) {
    sourceNumber = 1;
    do {
      producerSource = (int *)IRInst__getOperandSource(inst2,sourceNumber);
      loopIndex2 = (**(code **)(*producerSource + 0x60))(producerSource);
      if (loopIndex2 != 0) {
        return 0;
      }
      sourceNumber = sourceNumber + 1;
    } while (sourceNumber <= inst2[0x21]);
  }
  loopIndex2 = IRInst__getOperandRecord(inst2,0);
  opcodeInfo = inst2[0x22];
  destSelect = *(undefined4 *)(loopIndex2 + 0x10);
  if (*(int *)(opcodeInfo + 8) == 0x12) {
    local_a8 = (int *)IRInst__getOperandSource(inst2,1);
    sourceRegKindIsConstant = FUN_001267b8(local_a8[0x26]);
    if (sourceRegKindIsConstant == 0) {
      if (local_a8[0x26] == 0x33) {
        operandRecord = IRInst__getOperandRecord(inst2,1);
        loopIndex2 = 0;
        local_a4[0] = *(int **)(operandRecord + 0x10);
        lanesLeft = 4;
        laneCursor = constLanes;
        do {
          laneSelect = (uint)*(byte *)(loopIndex2 + (int)local_a4);
          if (laneSelect != 4) {
            *laneCursor = local_a8[laneSelect * 6 + 8];
          }
          loopIndex2 = loopIndex2 + 1;
          laneCursor = laneCursor + 1;
          lanesLeft = lanesLeft + -1;
        } while (lanesLeft != 0);
        valueNumberTable = *(undefined4 *)(program + 0x3ac);
        local_a8 = (int *)FUN_000f5f94(valueNumberTable,constLanes,local_a4,programCopy,compilerCtx,uVar9,laneCursor);
        if (local_a8 == (int *)0x0) {
          local_a8 = (int *)FUN_000f57f0(valueNumberTable,constLanes,local_a4,programCopy);
        }
        selectWord = local_a4[0];
        if (local_a8 == (int *)0x0) {
          return 0;
        }
        source1Record = IRInst__getOperandRecord(inst2,1);
        *(int **)(source1Record + 0x10) = selectWord;
        compilerCtx = *(undefined4 *)(program + 8);
        IRInst__setOperandSource(inst2,1,local_a8,0,compilerCtx);
      }
      else {
        local_a8 = (int *)0x0;
      }
    }
    if (local_a8 == (int *)0x0) {
      return 0;
    }
    firstSourceIsPresub = (**(code **)(*local_a8 + 0x5c))(local_a8);
    if (firstSourceIsPresub != 0) {
      return 0;
    }
    if ((inst2[0x2e] & 2U) != 0) {
      return 0;
    }
    if (inst2[0x49] != 0) {
      return 0;
    }
    constantKindPtr = &constantKind;
    uniformConstantFound = IRInst__getUniformSourceConstant(inst2,2,destSelect,constantKindPtr);
    if ((uniformConstantFound == 0) || (isFloatConstant = true, constantKind != 2)) {
      isFloatConstant = false;
    }
    if (isFloatConstant) {
      if ((constantValue == 1.0) || (constantValue == -1.0)) {
        negate = (uint)(constantValue == -1.0);
        if (negate == (inst2[0x2e] & 1U)) {
          return 0;
        }
        inst3 = IRInst__create(0x9c,*(undefined4 *)(program + 8));
        newRegId = *(undefined4 *)((int)inst3 + 0x14c);
        destRecord = IRInst__getOperandRecord(inst3,0);
        *(undefined4 *)(destRecord + 0xc) = 0x31;
        *(undefined4 *)(destRecord + 8) = newRegId;
        compiler = *(undefined4 *)(program + 8);
        loopIndex4 = local_a8;
        goto LAB_00187498;
      }
      if ((((constantValue == 0.5) || (constantValue == -0.5)) &&
          (uniformConstantFound = FUN_00184cd8(inst,operandIndex,program), uniformConstantFound != 0)) &&
         ((inst2[0x2e] & 1U) == (uint)(constantValue == 0.5))) {
        inst3 = IRInst__create(0x99,*(undefined4 *)(program + 8));
        newRegId = *(undefined4 *)((int)inst3 + 0x14c);
        destRecord = IRInst__getOperandRecord(inst3,0);
        *(undefined4 *)(destRecord + 0xc) = 0x31;
        *(undefined4 *)(destRecord + 8) = newRegId;
        sourceDef = IRInst__getOperandSource(inst2,1);
        IRInst__setOperandSource(inst3,1,sourceDef,0,*(undefined4 *)(program + 8));
        commitResult = FUN_00185da4(operandIndex,(uint)(constantValue == -0.5),inst,inst3,inst2,program,param_5
                             ,param_6,param_7,originalInst2);
        if (commitResult != 0) {
          inst[0x49] = inst[0x49] + -1;
          return commitResult;
        }
        return 0;
      }
    }
    local_a4[1] = (int *)IRInst__getOperandSource(inst2,2);
    loopRemaining = FUN_001267b8(local_a4[1][0x26]);
    if (loopRemaining == 0) {
      if (local_a4[1][0x26] == 0x33) {
        source1Record = IRInst__getOperandRecord(inst2,2);
        laneNumber = 0;
        local_a4[0] = *(int **)(source1Record + 0x10);
        lanesRemaining = 4;
        loopIndex3 = constLanes;
        do {
          laneSelect = (uint)*(byte *)(laneNumber + (int)local_a4);
          if (laneSelect != 4) {
            *loopIndex3 = local_a4[1][laneSelect * 6 + 8];
          }
          laneNumber = laneNumber + 1;
          loopIndex3 = loopIndex3 + 1;
          lanesRemaining = lanesRemaining + -1;
        } while (lanesRemaining != 0);
        programValueTable = *(undefined4 *)(program + 0x3ac);
        local_a4[1] = (int *)FUN_000f5f94(programValueTable,constLanes,local_a4,constantKindPtr,compilerCtx,uVar9,loopIndex3);
        if (local_a4[1] == (int *)0x0) {
          local_a4[1] = (int *)FUN_000f57f0(programValueTable,constLanes,local_a4,constantKindPtr);
        }
        selectWord = local_a4[0];
        if (local_a4[1] == (int *)0x0) {
          return 0;
        }
        loopRemaining = IRInst__getOperandRecord(inst2,2);
        *(int **)(loopRemaining + 0x10) = selectWord;
        IRInst__setOperandSource(inst2,2,local_a4[1],0,*(undefined4 *)(program + 8));
      }
      else {
        local_a4[1] = (int *)0x0;
      }
    }
    if (((local_a4[1] == (int *)0x0) || ((inst2[0x34] & 2U) != 0)) ||
       ((loopRemaining = (**(code **)(*local_a4[1] + 0x5c))(local_a4[1]), loopRemaining != 0 ||
        (loopRemaining = ((int (*)())FUN_00186510)(inst2,&local_a8,local_a4 + 1,*(undefined4 *)(program + 8)),
        loopRemaining == 0)))) {
      return 0;
    }
    if ((inst2[0x2e] & 1U) == (inst2[0x34] & 1U)) {
      createOwner = *(undefined4 *)(program + 8);
      presubOpcode = 0x9b;
    }
    else {
      createOwner = *(undefined4 *)(program + 8);
      presubOpcode = 0x9a;
    }
    inst3 = IRInst__create(presubOpcode,createOwner);
    newRegId = *(undefined4 *)((int)inst3 + 0x14c);
    destRecord = IRInst__getOperandRecord(inst3,0);
    *(undefined4 *)(destRecord + 0xc) = 0x31;
    *(undefined4 *)(destRecord + 8) = newRegId;
    IRInst__setOperandSource(inst3,1,local_a8,0,*(undefined4 *)(program + 8));
    IRInst__setOperandSource(inst3,2,local_a4[1],0,*(undefined4 *)(program + 8));
    negate = inst2[0x2e] & 1;
  }
  else {
    if (*(int *)(opcodeInfo + 8) == 0x31) {
      operandSource = IRInst__getOperandSource(inst2,1);
      sourceRegKind = 0;
      if (operandSource != 0) {
        operandSource = IRInst__getOperandSource(inst2,1);
        sourceRegKind = *(undefined4 *)(operandSource + 0x98);
      }
      operandKindIsConstant = FUN_001267b8(sourceRegKind);
      if ((operandKindIsConstant != 0) && ((inst2[0x2e] & 2U) == 0)) {
        operandSource2 = (int *)IRInst__getOperandSource(inst2,1);
        firstSourceIsPresub = (**(code **)(*operandSource2 + 0x5c))(operandSource2);
        if ((firstSourceIsPresub == 0) && (inst2[0x49] == 1)) {
          if ((inst2[0x2e] & 1U) == 0) {
            if ((inst2[0x34] & 1U) == 0) goto LAB_001872f8;
LAB_001872f0:
            negate = 1;
          }
          else {
            if ((inst2[0x34] & 1U) == 0) goto LAB_001872f0;
LAB_001872f8:
            negate = 0;
          }
          inst3 = IRInst__create(0x9b,*(undefined4 *)(program + 8));
          newRegId = *(undefined4 *)((int)inst3 + 0x14c);
          destRecord = IRInst__getOperandRecord(inst3,0);
          *(undefined4 *)(destRecord + 0xc) = 0x31;
          *(undefined4 *)(destRecord + 8) = newRegId;
          sourceDef = IRInst__getOperandSource(inst2,1);
          IRInst__setOperandSource(inst3,1,sourceDef,0,*(undefined4 *)(program + 8));
          sourceDef = IRInst__getOperandSource(inst2,1);
          IRInst__setOperandSource(inst3,2,sourceDef,0,*(undefined4 *)(program + 8));
          goto LAB_0018754c;
        }
      }
      opcodeInfo = inst2[0x22];
    }
    if (*(int *)(opcodeInfo + 8) != 0x14) {
      return 0;
    }
    operandSource = IRInst__getOperandSource(inst2,1);
    if (operandSource == 0) {
      sourceRegKind = 0;
    }
    else {
      operandSource = IRInst__getOperandSource(inst2,1);
      sourceRegKind = *(undefined4 *)(operandSource + 0x98);
    }
    operandKindIsConstant = FUN_001267b8(sourceRegKind);
    if (operandKindIsConstant == 0) {
      return 0;
    }
    if ((inst2[0x2e] & 2U) != 0) {
      return 0;
    }
    operandSource2 = (int *)IRInst__getOperandSource(inst2,1);
    firstSourceIsPresub = (**(code **)(*operandSource2 + 0x5c))(operandSource2);
    if (firstSourceIsPresub != 0) {
      return 0;
    }
    constantLaneResult = IRInst__sourceMatchesConstant(inst2,2,destSelect,local_a4 + 6);
    if (constantLaneResult == 0) {
      return 0;
    }
    constantLaneResult = IRInst__sourceMatchesConstant(inst2,3,destSelect,local_a4 + 2);
    if (constantLaneResult == 0) {
      return 0;
    }
    if (inst2[0x49] != 1) {
      return 0;
    }
    negate = inst2[0x3a] & 1;
    if ((inst2[0x2e] & 1U) == 0) {
      if ((inst2[0x34] & 1U) == 0) goto LAB_0018744c;
LAB_00187444:
      otherNegate = 1;
    }
    else {
      if ((inst2[0x34] & 1U) == 0) goto LAB_00187444;
LAB_0018744c:
      otherNegate = 0;
    }
    if (otherNegate == negate) {
      return 0;
    }
    inst3 = IRInst__create(0x99,*(undefined4 *)(program + 8));
    newRegId = *(undefined4 *)((int)inst3 + 0x14c);
    destRecord = IRInst__getOperandRecord(inst3,0);
    *(undefined4 *)(destRecord + 0xc) = 0x31;
    *(undefined4 *)(destRecord + 8) = newRegId;
    loopIndex4 = (int *)IRInst__getOperandSource(inst2,1);
    compiler = *(undefined4 *)(program + 8);
LAB_00187498:
    IRInst__setOperandSource(inst3,1,loopIndex4,0,compiler);
  }
LAB_0018754c:
  commitResult = FUN_00185da4(operandIndex,negate,inst,inst3,inst2,program,param_5,param_6,param_7,originalInst2)
  ;
  return commitResult;
}

/* Inst__r300ReassociateAddPair @ 0x1875a8 (1328 bytes) */
int Inst__r300ReassociateAddPair(inst, srcIndex, inst2, program)
  int *inst;
  int srcIndex;
  int inst2;
  int program;
{
  undefined4 otherSelect;
  undefined4 inst2Src2Select;
  undefined4 maskSelectConst;
  int otherIndex;
  int *operandVReg3;
  uint inst2Src2Negate;
  uint otherNegate;
  uint srcFlags;
  int callResult;
  int *otherModBase;
  int *operandVReg;
  int *operandVReg2;
  uint inst2Src2Abs;
  uint otherAbs;
  undefined4 destSelect;
  int inst2Src2ModBase;
  undefined4 srcSelect;
  int instDestSelect;
  undefined4 composedSelect1;
  undefined4 composedSelect2;
  undefined4 destWriteMask;
  int maskedSelect [5];
  
  if ((((((inst != (int *)0x0) && (*(int *)(*(int *)(inst2 + 0x88) + 8) == 0x12)) &&
        (*(int *)(inst[0x22] + 8) == 0x12)) &&
       (((callResult = IRInst__hasSingleUse(inst2,program), callResult != 0 && (*(int *)(inst2 + 0x120) == 0)) &&
        ((*(int *)(inst2 + 0x124) == 0 && ((inst[0x48] == 0 && (inst[0x49] == 0)))))))) &&
      ((inst[5] & 0x200U) == 0)) &&
     (((*(uint *)(inst2 + 0x14) & 0x200) == 0 && ((*(uint *)(inst2 + 0x14) & 0x40000) == 0)))) {
    callResult = IRInst__getOperandRecord(inst,0);
    instDestSelect = *(int *)(callResult + 0x10);
    callResult = IRInst__getOperandRecord(inst2,0);
    if (instDestSelect != *(int *)(callResult + 0x10)) {
      callResult = IRInst__getOperandRecord(inst2,0);
      callResult = SelectWord__isSingleComponentConstant(*(undefined4 *)(callResult + 0x10));
      if (callResult == 0) goto LAB_00187a90;
    }
    callResult = IRInst__isSourceSelectIdentity(inst,srcIndex);
    if (callResult == 0) {
      callResult = (**(code **)(*inst + 0x60))(inst);
      if (callResult != 0) {
        return 0;
      }
      callResult = IRInst__getOperandRecord(inst,srcIndex);
      srcSelect = *(undefined4 *)(callResult + 0x10);
      callResult = IRInst__getOperandRecord(inst,0);
      destSelect = *(undefined4 *)(callResult + 0x10);
      *(undefined4 *)(inst2 + 0x9c) = destSelect;
      callResult = IRInst__getOperandRecord(inst2,1);
      SelectWord__compose(&composedSelect1,*(undefined4 *)(callResult + 0x10),srcSelect);
      callResult = IRInst__getOperandRecord(inst2,1);
      *(undefined4 *)(callResult + 0x10) = composedSelect1;
      callResult = IRInst__getOperandRecord(inst2,2);
      SelectWord__compose(&composedSelect2,*(undefined4 *)(callResult + 0x10),srcSelect);
      callResult = IRInst__getOperandRecord(inst2,2);
      maskSelectConst = DAT_001b0220;
      *(undefined4 *)(callResult + 0x10) = composedSelect2;
      WriteMask__fromSelectWord(&destWriteMask,destSelect);
      SelectWord__maskUnused(maskedSelect,maskSelectConst,destWriteMask);
      if (srcIndex == 0) {
        inst[0x27] = maskedSelect[0];
      }
      else {
        callResult = IRInst__getOperandRecord(inst,srcIndex);
        *(int *)(callResult + 0x10) = maskedSelect[0];
      }
    }
    operandVReg3 = (int *)IRInst__getOperandSource(inst2,1);
    IRInst__getOperandRecord(inst2,1);
    operandVReg = (int *)IRInst__getOperandSource(inst2,2);
    inst2Src2Negate = *(uint *)(inst2 + 0xd0) & 1;
    inst2Src2Abs = *(uint *)(inst2 + 0xd0) >> 1 & 1;
    callResult = IRInst__getOperandRecord(inst2,2);
    inst2Src2Select = *(undefined4 *)(callResult + 0x10);
    otherIndex = (srcIndex == 1) + 1;
    operandVReg2 = (int *)IRInst__getOperandSource(inst,otherIndex);
    otherNegate = inst[otherIndex * 6 + 0x28] & 1;
    otherAbs = (uint)inst[otherIndex * 6 + 0x28] >> 1 & 1;
    callResult = IRInst__getOperandRecord(inst,otherIndex);
    otherSelect = *(undefined4 *)(callResult + 0x10);
    callResult = (**(code **)(*operandVReg3 + 0x5c))(operandVReg3);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg + 0x5c))(operandVReg);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
    if (callResult != 0) {
      return 0;
    }
    callResult = (**(code **)(*operandVReg2 + 0x48))(operandVReg2);
    if ((((callResult != 0) && (callResult = (**(code **)(*operandVReg3 + 0x48))(operandVReg3), callResult == 0)) &&
        (callResult = (**(code **)(*operandVReg + 0x48))(operandVReg), callResult == 0)) &&
       ((inst[srcIndex * 6 + 0x28] & 2U) == 0)) {
      inst2Src2ModBase = inst2 + 0xbc;
      IRInst__setOperandSource(inst2,2,operandVReg2,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst2Src2ModBase,1,otherNegate);
      IROperand__setModifierBits(inst2Src2ModBase,2,otherAbs);
      otherModBase = inst + otherIndex * 6 + 0x23;
      callResult = IRInst__getOperandRecord(inst2,2);
      *(undefined4 *)(callResult + 0x10) = otherSelect;
      IRInst__setOperandSource(inst,otherIndex,operandVReg,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(otherModBase,1,inst2Src2Negate);
      IROperand__setModifierBits(otherModBase,2,inst2Src2Abs);
      callResult = IRInst__getOperandRecord(inst,otherIndex);
      srcFlags = inst[srcIndex * 6 + 0x28];
      *(undefined4 *)(callResult + 0x10) = inst2Src2Select;
      if ((srcFlags & 1) != 0) {
        IROperand__setModifierBits(inst2Src2ModBase,1,*(uint *)(inst2 + 0xd0) & 1 ^ 1);
        IROperand__setModifierBits(otherModBase,1,inst[otherIndex * 6 + 0x28] & 1U ^ 1);
      }
      callResult = ((int (*)())FUN_00186a88)(inst,srcIndex,inst2,program,1,1,0);
      if (callResult != 0) {
        return 1;
      }
      IRInst__setOperandSource(inst2,2,operandVReg,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst2Src2ModBase,1,inst2Src2Negate);
      IROperand__setModifierBits(inst2Src2ModBase,2,inst2Src2Abs);
      callResult = IRInst__getOperandRecord(inst2,2);
      *(undefined4 *)(callResult + 0x10) = inst2Src2Select;
      IRInst__setOperandSource(inst,otherIndex,operandVReg2,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(otherModBase,1,otherNegate);
      IROperand__setModifierBits(otherModBase,2,otherAbs);
      callResult = IRInst__getOperandRecord(inst,otherIndex);
      *(undefined4 *)(callResult + 0x10) = otherSelect;
    }
  }
LAB_00187a90:
  callResult = ((int (*)())FUN_00186a88)(inst,srcIndex,inst2,program,1,1,0);
  if (callResult == 0) {
    return 0;
  }
  return 1;
}

/* FUN_00187ad8 @ 0x187ad8 (1996 bytes) */
int FUN_00187ad8(inst, program)
  undefined4 inst;
  int program;
{
  int operandNumber;
  int selectOperand;
  int *foldedInst;
  uint *newSourceUseList;
  uint *sourceUseList;
  undefined4 compiler;
  int *userSlot;
  int userByteOffset;
  int programLevel;
  int *commonOperand;
  int *otherOperand;
  int useByteOffset;
  int sourceIsSplatConstantResult2;
  int sourceIsSplatConstantResult;
  int sourceDef;
  int operandRecord2;
  int *operandVReg;
  bool moreLanes;
  int cndOpcode;
  uint useCount;
  int opcodeInfo;
  int *callResult;
  int splatCheckResult;
  uint loopIndex4;
  int *useSlot;
  int *operandVReg3;
  int *operandVReg2;
  int *piVar11;
  undefined4 operandRecord;
  int cndBlock;
  int levelOffset;
  undefined4 *appendSlot;
  int userRegId;
  int userField124;
  uint useIndex;
  uint loopIndex2;
  int extraSource;
  undefined4 cndOperandNumber;
  uint loopIndex3;
  int loopIndex;
  uint *useList;
  code *setLaneSelect;
  int userInst;
  int userField120;
  undefined4 cndOperandSelect;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_80;
  int otherSelect;
  undefined4 userBlock;
  undefined4 userNext;
  int cndPrev;
  uint otherNegate;
  uint otherAbs;
  undefined4 otherSource;
  undefined4 *destRecordCopy;
  
  callResult = (int *)FUN_001922c4(0,0,inst,program);
  cndOpcode = *(int *)(callResult[0x22] + 8);
  if (((cndOpcode != 0x24) && (cndOpcode != 0x25)) && (cndOpcode != 0x26)) {
    return;
  }
  sourceIsSplatConstantResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(callResult,2,(double)FLOAT_001aa0e8);
  splatCheckResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(callResult,2,(double)FLOAT_001aa0d4);
  if ((splatCheckResult == 0) || (splatCheckResult = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(callResult,3,(double)FLOAT_001aa0e8), splatCheckResult == 0)) {
    sourceIsSplatConstantResult2 = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(callResult,3,(double)FLOAT_001aa0d4);
    if (sourceIsSplatConstantResult2 == 0) {
      return;
    }
    if (sourceIsSplatConstantResult == 0) {
      return;
    }
  }
  if ((callResult[5] & 0x200U) != 0) {
    return;
  }
  useList = (uint *)callResult[4];
  useCount = useList[1];
  useIndex = useCount - 1;
  if (-1 < (int)useIndex) {
    useByteOffset = useIndex * 4;
    loopIndex2 = 0;
    commonOperand = (int *)0x0;
    loopIndex3 = useIndex;
    do {
      if (loopIndex3 < *useList) {
        loopIndex4 = useList[1];
        if (loopIndex4 <= loopIndex3) {
          _memset(loopIndex4 * 4 + useList[2],0,(loopIndex3 - loopIndex4) * 4 + 4);
          useList[1] = loopIndex3 + 1;
        }
        useSlot = (int *)(useByteOffset + useList[2]);
      }
      else {
        useSlot = (int *)Vector__elementRefGrow(useList,loopIndex3);
      }
      userInst = *useSlot;
      opcodeInfo = *(int *)(userInst + 0x88);
      otherOperand = commonOperand;
      if (*(int *)(opcodeInfo + 8) != 0x13) {
        if (*(int *)(opcodeInfo + 8) == 0x14) {
          operandVReg3 = (int *)IRInst__getOperandSource(userInst,1);
          if ((callResult == operandVReg3) || (operandVReg3 = (int *)IRInst__getOperandSource(userInst,2), callResult == operandVReg3))
          goto LAB_00187ce4;
          opcodeInfo = *(int *)(userInst + 0x88);
        }
        if (*(int *)(opcodeInfo + 8) == 0x12) {
          operandVReg3 = (int *)IRInst__getOperandSource(userInst,1);
          operandVReg2 = (int *)IRInst__getOperandSource(userInst,2);
          otherOperand = operandVReg2;
          if (((callResult != operandVReg3) && (otherOperand = operandVReg3, callResult != operandVReg2)) ||
             ((commonOperand != (int *)0x0 && (commonOperand != otherOperand)))) goto LAB_00187cfc;
        }
      }
LAB_00187ce4:
      loopIndex2 = loopIndex2 + 1;
      loopIndex3 = loopIndex3 - 1;
      useByteOffset = useByteOffset + -4;
      if (loopIndex2 == useCount) goto LAB_00187cfc;
      useList = (uint *)callResult[4];
      commonOperand = otherOperand;
    } while( true );
  }
LAB_00187d00:
  programLevel = *(int *)(program + 0x478);
  if (-1 < (int)useIndex) {
    userByteOffset = useIndex * 4;
    loopIndex3 = 0;
    do {
      if (useIndex < *useList) {
        loopIndex2 = useList[1];
        if (loopIndex2 <= useIndex) {
          _memset(loopIndex2 * 4 + useList[2],0,(useIndex - loopIndex2) * 4 + 4);
          useList[1] = useIndex + 1;
        }
        userSlot = (int *)(userByteOffset + useList[2]);
      }
      else {
        userSlot = (int *)Vector__elementRefGrow(useList,useIndex);
      }
      userInst = *userSlot;
      if (*(int *)(*(int *)(userInst + 0x88) + 8) == 0x13) {
        operandVReg = (int *)IRInst__getOperandSource(userInst,1);
        if (callResult == operandVReg) {
          cndOperandNumber = 1;
          loopIndex = 2;
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(userInst,2);
          if (callResult != operandVReg) {
            if ((*(uint *)(userInst + 0x14) & 0x200) != 0) {
              IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84));
            }
            goto LAB_00188244;
          }
          cndOperandNumber = 2;
          loopIndex = 1;
        }
        destRecordCopy = &local_94;
        extraSource = 0;
        *(int *)(program + 500) = *(int *)(program + 500) + 1;
        Vector__removeAt(callResult[4],useIndex);
        callResult[0x58] = callResult[0x58] + -1;
        local_80 = 0;
        local_94 = 0;
        local_90 = 0;
        operandRecord = IRInst__getOperandRecord(userInst,0);
        IROperand__copyFrom(destRecordCopy,operandRecord);
        otherSource = IRInst__getOperandSource(userInst,loopIndex);
        IRInst__setOperandSource(userInst,loopIndex,0,1,*(undefined4 *)(program + 8));
        operandRecord2 = IRInst__getOperandRecord(userInst,loopIndex);
        otherSelect = *(int *)(operandRecord2 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(userInst,cndOperandNumber);
        cndOperandSelect = *(undefined4 *)(operandRecord2 + 0x10);
        loopIndex2 = *(uint *)(loopIndex * 0x18 + userInst + 0xa0);
        otherNegate = loopIndex2 & 1;
        otherAbs = loopIndex2 >> 1 & 1;
        cndPrev = callResult[1];
        userNext = *(undefined4 *)(userInst + 8);
        userBlock = *(undefined4 *)(userInst + 0x158);
        cndBlock = callResult[0x56];
        loopIndex = *(int *)(userInst + 0x10);
        DList__unlink(callResult);
        DList__unlink(userInst);
        userRegId = *(int *)(userInst + 0x14c);
        userField120 = *(int *)(userInst + 0x120);
        userField124 = *(int *)(userInst + 0x124);
        if ((*(uint *)(userInst + 0x14) & 0x200) != 0) {
          extraSource = IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84));
          compiler = *(undefined4 *)(program + 8);
          sourceDef = IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84));
          sourceUseList = *(uint **)(sourceDef + 0x10);
          loopIndex2 = sourceUseList[1];
          if (0 < (int)loopIndex2) {
            loopIndex4 = 0;
            do {
              if (loopIndex4 < *sourceUseList) {
                if (loopIndex2 <= loopIndex4) {
                  _memset(loopIndex2 * 4 + sourceUseList[2],0,(loopIndex4 - loopIndex2) * 4 + 4);
                  sourceUseList[1] = loopIndex4 + 1;
                }
                piVar11 = (int *)(loopIndex4 * 4 + sourceUseList[2]);
              }
              else {
                piVar11 = (int *)Vector__elementRefGrow(sourceUseList,loopIndex4);
              }
              if (userInst == *piVar11) {
                Vector__removeAt(sourceUseList,loopIndex4);
                sourceDef = IRInst__getOperandSource(userInst,*(undefined4 *)(userInst + 0x84));
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                break;
              }
              loopIndex2 = sourceUseList[1];
              loopIndex4 = loopIndex4 + 1;
            } while ((int)loopIndex4 < (int)loopIndex2);
          }
          IRInst__setOperandSource(userInst,*(undefined4 *)(userInst + 0x84),0,1,compiler);
          *(int *)(userInst + 0x84) = *(int *)(userInst + 0x84) + -1;
          *(uint *)(userInst + 0x14) = *(uint *)(userInst + 0x14) & 0xfffffdff;
        }
        levelOffset = *(int *)(userInst + 0x160) - programLevel;
        if (levelOffset < 0) {
          levelOffset = 0;
        }
        foldedInst = (int *)IRInst__cloneInto(callResult,userInst,*(undefined4 *)(program + 8),1);
        selectOperand = (sourceIsSplatConstantResult == 0) + 2;
        IRInst__getOrCreateOperandRecord(foldedInst,0,destRecordCopy,*(undefined4 *)(program + 8));
        foldedInst[0x53] = userRegId;
        Block__insertInstAfter(cndBlock,cndPrev,callResult);
        Block__insertInstBefore(userBlock,userNext,foldedInst);
        foldedInst[0x48] = userField120;
        foldedInst[0x49] = userField124;
        if (extraSource != 0) {
          IRInst__setExtraOperandSource(foldedInst,extraSource,1,*(undefined4 *)(program + 8));
        }
        foldedInst[4] = loopIndex;
        IRInst__setOperandSource(foldedInst,selectOperand,otherSource,1,*(undefined4 *)(program + 8));
        foldedInst[0x58] = programLevel + levelOffset;
        if (selectOperand == 0) {
          foldedInst[0x27] = otherSelect;
        }
        else {
          loopIndex = IRInst__getOperandRecord(foldedInst,selectOperand);
          *(int *)(loopIndex + 0x10) = otherSelect;
        }
        IROperand__setModifierBits(foldedInst + selectOperand * 6 + 0x23,2,otherAbs);
        IROperand__setModifierBits(foldedInst + selectOperand * 6 + 0x23,1,otherNegate);
        loopIndex = IRInst__getOperandSource(foldedInst,1);
        if (programLevel < *(int *)(loopIndex + 0x160)) {
          *(int *)(loopIndex + 0x160) = *(int *)(loopIndex + 0x160) + 1;
        }
        else {
          *(int *)(loopIndex + 0x160) = programLevel + 1;
        }
        newSourceUseList = *(uint **)(loopIndex + 0x10);
        loopIndex2 = newSourceUseList[1];
        if (loopIndex2 < *newSourceUseList) {
          _memset(loopIndex2 * 4 + newSourceUseList[2],0,4);
          appendSlot = (undefined4 *)(loopIndex2 * 4 + newSourceUseList[2]);
          newSourceUseList[1] = loopIndex2 + 1;
        }
        else {
          appendSlot = (undefined4 *)Vector__elementRefGrow(newSourceUseList,loopIndex2);
        }
        *appendSlot = foldedInst;
        loopIndex = 0;
        do {
          loopIndex2 = (uint)*(byte *)((int)&cndOperandSelect + loopIndex);
          operandRecord2 = IRInst__getOperandRecord(foldedInst,0);
          if (*(char *)(loopIndex + operandRecord2 + 0x10) == '\x01') {
            loopIndex2 = 4;
          }
          for (operandNumber = 1; extraSource = (**(code **)(*foldedInst + 0x14))(foldedInst), operandNumber <= extraSource;
              operandNumber = operandNumber + 1) {
            if (selectOperand != operandNumber) {
              if (loopIndex2 == 4) {
                (**(code **)(*foldedInst + 0x88))(foldedInst,operandNumber,loopIndex,4);
              }
              else {
                setLaneSelect = *(code **)(*foldedInst + 0x88);
                extraSource = IRInst__getOperandRecord(callResult,operandNumber);
                (*setLaneSelect)(foldedInst,operandNumber,loopIndex,*(undefined1 *)(loopIndex2 + extraSource + 0x10));
              }
            }
          }
          moreLanes = loopIndex != 3;
          loopIndex = loopIndex + 1;
        } while (moreLanes);
      }
LAB_00188244:
      loopIndex3 = loopIndex3 + 1;
      useIndex = useIndex - 1;
      userByteOffset = userByteOffset + -4;
      if (loopIndex3 == useCount) goto code_r0x00188258;
      useList = (uint *)callResult[4];
    } while( true );
  }
LAB_0018825c:
  if (useList[1] == 0) {
    (**(code **)(*callResult + 0xc))(callResult,1,*(undefined4 *)(program + 8));
  }
  return;
LAB_00187cfc:
  useList = (uint *)callResult[4];
  goto LAB_00187d00;
code_r0x00188258:
  useList = (uint *)callResult[4];
  goto LAB_0018825c;
}

/* Inst__r300Peephole_1882a4 @ 0x1882a4 (408 bytes) */
int Inst__r300Peephole_1882a4(inst, compiler)
  int *inst;
  int compiler;
{
  int scaleAccepted;
  int operandRecord;
  bool moreLanes;
  float uniformValue;
  int loopIndex;
  int *a0;
  int isScalable;
  uint firstComponent;
  uint readComponent;
  
  loopIndex = (**(code **)(*inst + 0x68))(inst,compiler);
  if (loopIndex != 0) {
    a0 = (int *)IRInst__getOperandSource(inst,1);
    loopIndex = (**(code **)(*a0 + 0x40))(a0);
    if (loopIndex != 0) {
      firstComponent = 0xffffffff;
      uniformValue = 0.0;
      loopIndex = 0;
      do {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
          operandRecord = IRInst__getOperandRecord(inst,1);
          readComponent = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
          if (((int)*(char *)(a0 + 0x57) >> (readComponent & 0x3f) & 1U) == 0) {
            return;
          }
          isScalable = ((undefined4 (*)())isOutputScaleValue)((double)GH_U2F((unsigned int)(a0[readComponent * 6 + 8])));
          if (isScalable == 0) {
            return;
          }
          if (firstComponent == 0xffffffff) {
            uniformValue = GH_U2F((unsigned int)(a0[readComponent * 6 + 8]));
            firstComponent = readComponent;
          }
          else if (GH_U2F((unsigned int)(a0[readComponent * 6 + 8])) != uniformValue) {
            return;
          }
        }
        moreLanes = loopIndex != 3;
        loopIndex = loopIndex + 1;
      } while (moreLanes);
      loopIndex = ((int (*)())outputScaleExponent)((double)GH_U2F((unsigned int)(a0[firstComponent * 6 + 8])));
      scaleAccepted = (**(code **)(**(int **)(compiler + COMP_target) + 0xfc))(*(int **)(compiler + COMP_target),loopIndex,0);
      if (scaleAccepted != 0) {
        ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + COMP_currentProgram),1,1.0,1.0,1.0,1.0);
        inst[0x49] = loopIndex;
        loopIndex = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(loopIndex + 0x10) = 0x10203;
      }
    }
  }
  return;
}

/* KhanPs__peepholeCombine @ 0x18843c (1328 bytes) */
int KhanPs__peepholeCombine(this, inst, consumerSrcIndex, inst2, program, passThroughR8, passThroughR9)
  undefined4 this;
  int inst;
  int consumerSrcIndex;
  int *inst2;
  undefined4 *program;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  int callResult;
  int *curInst;
  int *inst3;
  undefined4 *programAlias4;
  undefined4 *programAlias5;
  undefined4 changedFlag;
  undefined4 foldStatus [7];
  
  changedFlag = 0;
  foldStatus[0] = 0;
  programAlias5 = program;
  callResult = Compiler__isOptionEnabled(program[2],0x1b);
  if (callResult == 0) {
LAB_00188508:
    callResult = Compiler__isOptionEnabled(program[2],0x1c);
    if (callResult != 0) {
      callResult = Inst__mergeComponentMovsIntoCnd(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
      }
      callResult = Inst__collapseIntoExtraSourceDispatch(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
      }
      callResult = (**(code **)(*inst2 + 0x14))(inst2);
      if ((consumerSrcIndex <= callResult) && (callResult = Inst__collapseAlgebraic_00158264(inst,consumerSrcIndex,inst2,program), callResult != 0))
      {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
        if (inst2 == (int *)0x0) goto LAB_00188950;
        changedFlag = 1;
      }
      callResult = Inst__collapseAlgebraic_00155a60(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseMulOfAddWithUnitConstant(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseMadOfMulToDot2Add(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseThreeComponentSumToDot3(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseAddOfScaledMov(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseMadWithDot2AddToDot3(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseMulOfExps(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseClampToSaturate(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Compiler__isOptionEnabled(program[2],0x3c);
      if ((callResult != 0) && (callResult = Inst__hoistScalarMulOutOfDot(inst,consumerSrcIndex,inst2,program), callResult != 0)) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__collapseDot3VectorTimesScaledVector(inst2,program);
      if (callResult != 0) {
        inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      }
      callResult = Inst__distributeResultScale(inst2,program);
      if (callResult != 0) {
        changedFlag = 1;
      }
    }
    callResult = FUN_0015546c(inst,consumerSrcIndex,inst2,(uint)program);
    if (callResult != 0) {
      changedFlag = 1;
      inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
    }
    inst3 = inst2;
    programAlias4 = program;
    callResult = FUN_00155654(inst,consumerSrcIndex,inst2,program);
    curInst = inst2;
    if (callResult != 0) {
      changedFlag = 1;
      curInst = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
      inst3 = inst2;
    }
    callResult = Compiler__isOptionEnabled(program[2],0x1d);
    if ((((callResult != 0) &&
         (callResult = Inst__tryCollapseSimilar(curInst,program,inst3,programAlias4,programAlias5,passThroughR8,passThroughR9), callResult != 0)) &&
        (callResult = (**(code **)(*curInst + 100))(curInst), callResult != 0)) &&
       ((inst != 0 && (callResult = Inst__foldProducerIntoConsumer(inst,consumerSrcIndex,curInst,program,foldStatus), callResult != 0)
        ))) {
      curInst = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,curInst);
      if (curInst == (int *)0x0) goto LAB_00188950;
    }
    callResult = Compiler__isOptionEnabled(program[2],0x39);
    if (callResult != 0) {
      ((int (*)())Inst__r300Peephole_1882a4)(curInst,program[2]);
    }
    callResult = FUN_00159b58(curInst,1,program);
    if (callResult != 0) {
      curInst = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,curInst);
    }
    callResult = Compiler__isOptionEnabled(program[2],0x39);
    if ((callResult != 0) && (callResult = ((int (*)())Inst__r300ReassociateAddPair)(inst,consumerSrcIndex,curInst,program), callResult != 0)) {
      changedFlag = 1;
      curInst = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,curInst);
    }
    callResult = Compiler__isOptionEnabled(program[2],0x3b);
    if ((callResult != 0) && ((curInst[5] & 1U) != 0)) {
      Inst__tryDp3Add(curInst,program,program[2]);
    }
  }
  else {
    changedFlag = (**(code **)(*inst2 + 100))(inst2);
    callResult = Inst__tryCopyPropagate(inst2,program,foldStatus);
    if (callResult == 0) {
LAB_001884c8:
      if (inst != 0) {
        programAlias5 = foldStatus;
        callResult = Inst__foldProducerIntoConsumer(inst,consumerSrcIndex,inst2,program,programAlias5);
        if (callResult != 0) {
          inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
          if (inst2 == (int *)0x0) goto LAB_00188950;
        }
      }
      goto LAB_00188508;
    }
    inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerSrcIndex,inst2);
    if (inst2 != (int *)0x0) goto LAB_001884c8;
LAB_00188950:
    changedFlag = 1;
  }
  return changedFlag;
}

/* Inst__movAndShiftUseVector @ 0x18896c (1208 bytes) */
int Inst__movAndShiftUseVector(inst, program)
  int *inst;
  int program;
{
  undefined4 compilerCtx;
  uint *vector2;
  int operandIndex;
  int isSourceSelectIdentity;
  int isIdentity;
  undefined4 sourceDef2;
  int *sourceDef3;
  int operandRecord2;
  int useCount;
  int operandRecord3;
  int sourceDef;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *operandVReg;
  int operandRecord;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint loopIndex;
  uint *vector;
  int *inst1;
  undefined4 local_58;
  undefined4 local_54;
  int local_48;
  undefined4 local_44;
  int local_38 [5];
  
  if (*(int *)(inst[0x22] + 8) != 0x31) {
    return;
  }
  sourceDef = IRInst__getOperandSource(inst,1);
  uVar2 = 0;
  if (sourceDef != 0) {
    sourceDef = IRInst__getOperandSource(inst,1);
    uVar2 = *(undefined4 *)(sourceDef + 0x98);
  }
  iVar1 = FUN_001267b8(uVar2);
  if (iVar1 == 0) {
    return;
  }
  sourceDef3 = (int *)IRInst__getOperandSource(inst,1);
  iVar1 = (**(code **)(*sourceDef3 + 0x5c))(sourceDef3);
  if (iVar1 != 0) {
    return;
  }
  if ((inst[5] & 0x200U) != 0) {
    return;
  }
  if (inst[0x48] != 0) {
    return;
  }
  sourceDef3 = (int *)IRInst__getOperandSource(inst,1);
  iVar1 = (**(code **)(*sourceDef3 + 0x48))(sourceDef3);
  if (iVar1 != 0) {
    return;
  }
  if (inst[0x49] == 0) {
    return;
  }
  if (((inst[0x2e] & 1U) == 0) && ((inst[0x2e] & 2U) == 0)) {
    operandRecord3 = IRInst__getOperandRecord(inst,1);
    isIdentity = SelectWord__isIdentity(*(undefined4 *)(operandRecord3 + 0x10));
    if (isIdentity != 0) goto LAB_00188a5c;
  }
  iVar1 = FUN_00184bf0(inst);
  if (iVar1 == 0) {
    return;
  }
LAB_00188a5c:
  sourceDef2 = IRInst__getOperandSource(inst,1);
  iVar1 = FUN_00184ef0(sourceDef2,inst[0x49],program);
  if (iVar1 != 0) {
    *(int *)(program + 0x160) = *(int *)(program + 0x160) + 1;
    sourceDef2 = IRInst__getOperandSource(inst,1);
    vector = (uint *)inst[4];
    uVar9 = vector[1] - 1;
    if (-1 < (int)uVar9) {
      do {
        if (uVar9 < *vector) {
          uVar4 = vector[1];
          if (uVar4 <= uVar9) {
            _memset(uVar4 * 4 + vector[2],0,(uVar9 - uVar4) * 4 + 4);
            vector[1] = uVar9 + 1;
          }
          puVar5 = (undefined4 *)(uVar9 * 4 + vector[2]);
        }
        else {
          puVar5 = (undefined4 *)Vector__elementRefGrow(vector,uVar9);
        }
        inst1 = (int *)*puVar5;
        piVar3 = inst1 + 0x20;
        for (operandIndex = 0; iVar8 = (**(code **)(*inst1 + 0x14))(inst1), operandIndex <= iVar8;
            operandIndex = operandIndex + 1) {
          operandVReg = (int *)IRInst__getOperandSource(inst1,operandIndex);
          if (inst == operandVReg) {
            uVar9 = uVar9 - 1;
            operandRecord2 = IRInst__getOperandRecord(operandVReg,1);
            uVar10 = *(undefined4 *)(operandRecord2 + 0x10);
            operandRecord2 = IRInst__getOperandRecord(inst1,operandIndex);
            SelectWord__compose(local_38,uVar10,*(undefined4 *)(operandRecord2 + 0x10));
            iVar8 = local_38[0];
            if ((*(int *)(inst1[0x22] + 8) != 0x8e) ||
               (((operandRecord = SelectWord__isIdentity(local_38[0]), operandRecord != 0 && ((inst[0x2e] & 1U) == 0)) &&
                ((inst[0x2e] & 2U) == 0)))) {
              IRInst__setOperandSource(inst1,operandIndex,sourceDef2,1,*(undefined4 *)(program + 8));
              if (operandIndex == 0) {
                inst1[0x27] = iVar8;
              }
              else {
                operandRecord = IRInst__getOperandRecord(inst1,operandIndex);
                *(int *)(operandRecord + 0x10) = iVar8;
              }
              IROperand__setModifierBits(piVar3 + 3,2,(uint)inst[0x2e] >> 1 & 1);
              if ((inst[0x2e] & 1U) != 0) {
                IROperand__setModifierBits(piVar3 + 3,1,piVar3[8] & 1U ^ 1);
              }
            }
          }
          piVar3 = piVar3 + 6;
        }
        if (((inst1[5] & 0x200U) != 0) &&
           (piVar3 = (int *)IRInst__getOperandSource(inst1,inst1[0x21]), inst == piVar3)) {
          isSourceSelectIdentity = IRInst__isSourceSelectIdentity(piVar3,1);
          if (isSourceSelectIdentity != 0) {
            local_44 = 0;
            local_58 = 0;
            local_54 = 0;
            IRInst__readLastOperand(inst1,&local_58);
            compilerCtx = *(undefined4 *)(program + 8);
            sourceDef = IRInst__getOperandSource(inst1,inst1[0x21]);
            vector2 = *(uint **)(sourceDef + 0x10);
            uVar4 = vector2[1];
            if (0 < (int)uVar4) {
              loopIndex = 0;
              do {
                if (loopIndex < *vector2) {
                  if (uVar4 <= loopIndex) {
                    _memset(uVar4 * 4 + vector2[2],0,(loopIndex - uVar4) * 4 + 4);
                    vector2[1] = loopIndex + 1;
                  }
                  piVar3 = (int *)(loopIndex * 4 + vector2[2]);
                }
                else {
                  piVar3 = (int *)Vector__elementRefGrow(vector2,loopIndex);
                }
                if (inst1 == (int *)*piVar3) {
                  Vector__removeAt(vector2,loopIndex);
                  sourceDef = IRInst__getOperandSource(inst1,inst1[0x21]);
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                  break;
                }
                uVar4 = vector2[1];
                loopIndex = loopIndex + 1;
              } while ((int)loopIndex < (int)uVar4);
            }
            IRInst__setOperandSource(inst1,inst1[0x21],0,1,compilerCtx);
            inst1[0x21] = inst1[0x21] + -1;
            inst1[5] = inst1[5] & 0xfffffdff;
            IRInst__setExtraOperandSource(inst1,sourceDef2,1,*(undefined4 *)(program + 8));
            iVar1 = local_48;
            if (inst1[0x21] == 0) {
              inst1[0x27] = local_48;
            }
            else {
              iVar8 = IRInst__getOperandRecord(inst1,inst1[0x21]);
              *(int *)(iVar8 + 0x10) = iVar1;
            }
          }
          uVar9 = uVar9 - 1;
        }
        if ((int)uVar9 < 0) break;
        vector = (uint *)inst[4];
      } while( true );
    }
    useCount = IRInst__useCount(inst,program);
    if (useCount == 0) {
      DList__unlink(inst);
      (**(code **)(*inst + 0xc))(inst,1,*(undefined4 *)(program + 8));
    }
  }
  return;
}

/* KhanPs__vslot27_optimizeInstruction @ 0x188e24 (256 bytes) */
int KhanPs__vslot27_optimizeInstruction(this, inst, program)
  undefined4 this;
  int inst;
  int program;
{
  int callResult;
  
  if ((*(uint *)(inst + 0x14) & 1) != 0) {
    ((int (*)())FUN_00187ad8)(inst,program);
    callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x36);
    if ((callResult == 0) || (Inst__splitAndMerge(inst,program), (*(uint *)(inst + 0x14) & 1) != 0)) {
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x15);
      if (callResult != 0) {
        Inst__reassociate_150b94(inst,program);
        Inst__reassociate_14e6e4(inst,program);
      }
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x16);
      if ((callResult != 0) && (callResult = IRInst__hasSingleUse(inst,program), callResult == 0)) {
        Inst__takeOutCommonFactor(inst,program);
      }
      callResult = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x14);
      if (callResult != 0) {
        ((int (*)())Inst__movAndShiftUseVector)(inst,program);
        return;
      }
    }
  }
  return;
}

/* KhanVs__vslot29_swapIfArmsWhenNotFlattenable @ 0x188f24 (200 bytes) */
int KhanVs__vslot29_swapIfArmsWhenNotFlattenable(this, program)
  undefined4 this;
  int program;
{
  int iVar1;
  int block;
  int *ifHeader;
  undefined1 auStack_28 [24];
  
  ifHeader = *(int **)(program + 900);
  iVar1 = ifHeader[2];
  while (iVar1 != 0) {
    iVar1 = (**(code **)(*ifHeader + 0x24))(ifHeader);
    if (iVar1 != 0) {
      block = ifHeader[0x4d];
      iVar1 = DList__count(block + 0x90);
      if ((((iVar1 < 3) && (iVar1 = Block__successorCount(block), iVar1 == 1)) &&
          (iVar1 = Block__getSuccessor(block,0), iVar1 == ifHeader[0x4f])) &&
         (iVar1 = IfHeader__canFlatten(ifHeader,auStack_28), iVar1 == 0)) {
        ifHeader = (int *)IfHeader__swapArms(program,ifHeader);
      }
    }
    ifHeader = (int *)ifHeader[2];
    iVar1 = ifHeader[2];
  }
  return;
}

/* KhanVs__peepholeCombine @ 0x188fec (1280 bytes) */
int KhanVs__peepholeCombine(this, inst, consumerOperandArg, inst2, program, passThroughR8, hwLimitsOrArg)
  undefined4 this;
  int inst;
  int *consumerOperandArg;
  int *inst2;
  int *program;
  undefined4 passThroughR8;
  int hwLimitsOrArg;
{
  int callResult;
  int *currentProducerA;
  int *currentProducerB;
  int *lastRewritten;
  int *producerAlias;
  int *programAlias;
  undefined4 changedFlag;
  int foldStatus [8];
  
  changedFlag = 0;
  foldStatus[0] = 0;
  lastRewritten = consumerOperandArg;
  producerAlias = inst2;
  programAlias = program;
  callResult = Compiler__isOptionEnabled(program[2],0x1b);
  if (callResult != 0) {
    changedFlag = (**(code **)(*inst2 + 100))(inst2);
    lastRewritten = foldStatus;
    callResult = Inst__tryCopyPropagate(inst2,program,lastRewritten);
    currentProducerA = inst2;
    if ((callResult != 0) &&
       (currentProducerA = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2), lastRewritten = inst2,
       currentProducerA == (int *)0x0)) {
      return 1;
    }
    inst2 = currentProducerA;
    if (inst != 0) {
      programAlias = foldStatus;
      lastRewritten = currentProducerA;
      producerAlias = program;
      callResult = Inst__foldProducerIntoConsumer(inst,consumerOperandArg,currentProducerA,program,programAlias);
      if ((callResult != 0) &&
         (inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerA), lastRewritten = currentProducerA,
         inst2 == (int *)0x0)) {
        return 1;
      }
    }
  }
  callResult = Compiler__isOptionEnabled(program[2],0x1c);
  if (callResult != 0) {
    hwLimitsOrArg = **(int **)(program[2] + 0x30c);
    callResult = (**(code **)(hwLimitsOrArg + 0x84))(*(int **)(program[2] + 0x30c));
    if (((callResult != 0) && (callResult = Inst__mergeComponentMovsIntoCnd(inst2,program), callResult != 0)) &&
       (inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
      return 1;
    }
    callResult = Inst__collapseIntoExtraSourceDispatch(inst2,program);
    if ((callResult != 0) &&
       (inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
      return 1;
    }
    callResult = (**(code **)(*inst2 + 0x14))(inst2);
    if (((int)consumerOperandArg <= callResult) &&
       (callResult = Inst__collapseAlgebraic_00158264(inst,consumerOperandArg,inst2,program), callResult != 0)) {
      inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
      if (inst2 == (int *)0x0) {
        return 1;
      }
      changedFlag = 1;
    }
    callResult = Inst__collapseAlgebraic_00155a60(inst2,program);
    if (callResult != 0) {
      inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
    }
    callResult = Inst__collapseMulOfAddWithUnitConstant(inst2,program);
    if (callResult != 0) {
      inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
    }
    lastRewritten = (int *)0x0;
    producerAlias = (int *)((int)((unsigned char *)0x0) + 1);
    callResult = Inst__collapseAddOfMulToMad(inst2,program,0,1);
    currentProducerA = inst2;
    if (callResult != 0) {
      currentProducerA = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
      lastRewritten = inst2;
    }
    callResult = Inst__collapseAddIntoMadMulAddend(currentProducerA,program);
    currentProducerB = currentProducerA;
    if (callResult != 0) {
      callResult = (**(code **)(*currentProducerA + 100))(currentProducerA);
      if (((callResult != 0) && ((currentProducerA[5] & 0x200U) == 0)) && (inst != 0)) {
        programAlias = foldStatus;
        producerAlias = program;
        Inst__foldProducerIntoConsumer(inst,consumerOperandArg,currentProducerA,program,programAlias);
      }
      currentProducerB = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerA);
      if (currentProducerB == (int *)0x0) {
        return 1;
      }
      changedFlag = 1;
      lastRewritten = currentProducerA;
    }
    callResult = Inst__collapseAddOfScaledMov(currentProducerB,program);
    currentProducerA = currentProducerB;
    if (callResult != 0) {
      currentProducerA = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerB);
      lastRewritten = currentProducerB;
    }
    callResult = Inst__collapseAlgebraic_0015ceb0(currentProducerA,program);
    currentProducerB = currentProducerA;
    if (callResult != 0) {
      currentProducerB = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerA);
      lastRewritten = currentProducerA;
    }
    callResult = Inst__mergeAddAndMadSharedOperands(currentProducerB,program);
    currentProducerA = currentProducerB;
    if (callResult != 0) {
      currentProducerA = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerB);
      lastRewritten = currentProducerB;
    }
    callResult = Inst__mergeMovAndMadByLanes(currentProducerA,program);
    currentProducerB = currentProducerA;
    if (callResult != 0) {
      currentProducerB = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerA);
      lastRewritten = currentProducerA;
    }
    callResult = Inst__collapseAlgebraic_0015c6d4(currentProducerB,program);
    currentProducerA = currentProducerB;
    if (callResult != 0) {
      currentProducerA = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerB);
      lastRewritten = currentProducerB;
    }
    callResult = Inst__collapseMulSplatByDotOnes(currentProducerA,program);
    currentProducerB = currentProducerA;
    if (callResult != 0) {
      currentProducerB = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerA);
      lastRewritten = currentProducerA;
    }
    callResult = Inst__collapseClampToSaturate(currentProducerB,program);
    inst2 = currentProducerB;
    if (callResult != 0) {
      inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,currentProducerB);
      lastRewritten = currentProducerB;
    }
  }
  callResult = Compiler__isOptionEnabled(program[2],0x1d);
  if ((((callResult != 0) &&
       (callResult = Inst__tryCollapseSimilar(inst2,program,lastRewritten,producerAlias,programAlias,passThroughR8,hwLimitsOrArg), callResult != 0)) &&
      ((callResult = (**(code **)(*inst2 + 100))(inst2), callResult != 0 &&
       ((inst != 0 &&
        (callResult = Inst__foldProducerIntoConsumer(inst,consumerOperandArg,inst2,program,foldStatus), callResult != 0)))))) &&
     (inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2), inst2 == (int *)0x0)) {
    return 1;
  }
  callResult = Compiler__isOptionEnabled(program[2],0x3a);
  if (callResult == 0) {
    return changedFlag;
  }
  if ((program[0x8a] < *(int *)(program[2] + 0x664)) &&
     (callResult = Inst__tryMix(inst,consumerOperandArg,inst2,program), callResult != 0)) {
    changedFlag = 1;
    inst2 = (int *)IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
  }
  callResult = FUN_0015f44c(inst,consumerOperandArg,inst2,program);
  if (callResult != 0) {
    IRInst__getOperandSourceOrDefault(inst,consumerOperandArg,inst2);
    return 1;
  }
  return changedFlag;
}

/* KhanVs__vslot27_optimizeInstruction @ 0x1894ec (116 bytes) */
int KhanVs__vslot27_optimizeInstruction(this, inst, program)
  undefined4 this;
  int inst;
  int program;
{
  int iVar1;
  
  if (((*(uint *)(inst + 0x14) & 1) != 0) &&
     (iVar1 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x15), iVar1 != 0)) {
    Inst__reassociate_150b94(inst,program);
    Inst__reassociate_14e6e4(inst,program);
    return;
  }
  return;
}

/* PackState__reset @ 0x189560 (64 bytes) */
int PackState__reset(state)
  undefined4 *state;
{
  bool bVar1;
  int loopIndex;
  
  loopIndex = 0;
  state[5] = 0;
  *state = 0;
  state[1] = 0;
  state[2] = 0;
  state[3] = 0;
  state[4] = 0;
  do {
    bVar1 = loopIndex != 2;
    state[6] = 0;
    state[9] = 0;
    loopIndex = loopIndex + 1;
    state[0xc] = 0;
    state = state + 1;
  } while (bVar1);
  return;
}

/* PackState__copy @ 0x1895a0 (100 bytes) */
int PackState__copy(dest, source)
  undefined4 *dest;
  undefined4 *source;
{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int loopIndex;
  
  uVar4 = *source;
  dest[2] = source[2];
  uVar3 = source[3];
  *dest = uVar4;
  loopIndex = 0;
  dest[3] = uVar3;
  uVar4 = source[1];
  dest[4] = source[4];
  uVar3 = source[5];
  dest[1] = uVar4;
  dest[5] = uVar3;
  do {
    bVar2 = loopIndex != 2;
    loopIndex = loopIndex + 1;
    dest[6] = source[6];
    puVar1 = source + 9;
    uVar3 = source[0xc];
    source = source + 1;
    dest[9] = *puVar1;
    dest[0xc] = uVar3;
    dest = dest + 1;
  } while (bVar2);
  return;
}

/* R520SchedModel__vslot2_reset @ 0x189604 (40 bytes) */
int R520SchedModel__vslot2_reset(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  return ((int (*)())PackState__reset)(param_1 + 0x28);
}

/* KhanPs__vslot31_isNotTextureFetch @ 0x18962c (52 bytes) */
int KhanPs__vslot31_isNotTextureFetch(this, inst)
  undefined4 this;
  int *inst;
{
  uint uVar1;
  
  uVar1 = (**(code **)(*inst + 0x30))(inst,inst);
  return uVar1 ^ 1;
}

/* KhanPs__vslot65_isEncodableSourceSwizzle @ 0x189660 (152 bytes) */
int KhanPs__vslot65_isEncodableSourceSwizzle(this, param_2, param_3, param_4, param_5)
  int *this;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  int iVar1;
  undefined4 callResult;
  
  if (((param_5 != (int *)0x0) && (iVar1 = (**(code **)(*param_5 + 0x4c))(param_5), iVar1 != 0)) &&
     (*param_4 == 0x10304)) {
    return 1;
  }
                    
                    
  callResult = (**(code **)(*this + 0x100))(this,param_4);
  return callResult;
}

/* SelectWord__isDefaultAfterCanonicalise @ 0x1896f8 (108 bytes) */
int SelectWord__isDefaultAfterCanonicalise(param_1)
  uint param_1;
{
  return *(uint *)(&DAT_001b0244 +
                  ((param_1 >> 0x18) * 0x7d + (param_1 >> 0x10 & 0xff) * 0x19 +
                   (param_1 >> 8 & 0xff) * 5 + (param_1 & 0xff)) * 0x10) ==
         ((uint)(byte)DAT_001b2a68 << 0x18 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 2)) << 0x10 |
          (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 1)) << 8 | (uint)(*(unsigned char *)((unsigned char *)&(DAT_001b2a68) + 0)));
}

/* SelectWord__matchesDefaultPattern @ 0x18976c (28 bytes) */
int SelectWord__matchesDefaultPattern(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = SelectWord__areCompatible(param_1,DAT_001b2a64);
  return callResult;
}

/* SelectWord__matchesAnyKnownPattern @ 0x189788 (104 bytes) */
int SelectWord__matchesAnyKnownPattern(param_1)
  undefined4 param_1;
{
  int callResult;
  undefined4 *loopIndex;
  
  loopIndex = &DAT_001b2994;
  do {
    callResult = SelectWord__areCompatible(*loopIndex,param_1);
    if (callResult != 0) {
      return 1;
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex != (undefined4 *)&UNK_001b29e4);
  return 0;
}

/* KhanPs__vslot66_callHelper189788 @ 0x1897f0 (8 bytes) */
int KhanPs__vslot66_callHelper189788(this, param_2)
  undefined4 this;
  undefined4 *param_2;
{
  return ((int (*)())SelectWord__matchesAnyKnownPattern)(*param_2);
}

/* FUN_001897fc @ 0x1897fc (68 bytes) */
int FUN_001897fc(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int operandVReg;
  bool bVar2;
  
  operandVReg = IRInst__getOperandSource(inst,operandIndex);
  bVar2 = false;
  if (*(int *)(operandVReg + 0x98) == 0x33) {
    bVar2 = *(int *)(operandVReg + 300) != 3;
  }
  return bVar2;
}

/* SchedModel__fitsConstantLimit @ 0x189840 (364 bytes) */
int SchedModel__fitsConstantLimit(schedModel, instA, instB, inlineLimit, otherLimit)
  int schedModel;
  int *instA;
  int *instB;
  int inlineLimit;
  int otherLimit;
{
  int *a0;
  int loopRemaining;
  int loopIndex;
  int loopRemaining2;
  int iVar4;
  int operandIndex;
  int *inst;
  int *local_58 [12];
  
  iVar4 = 0;
  do {
    loopRemaining2 = 2;
    inst = instA;
    do {
      for (operandIndex = 1; loopRemaining = (**(code **)(*inst + 0x14))(inst), operandIndex <= loopRemaining;
          operandIndex = operandIndex + 1) {
        a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
        loopRemaining = (**(code **)(*a0 + 0x60))(a0);
        if (loopRemaining == 0) {
LAB_001898e0:
          loopRemaining = (**(code **)(*a0 + 0x48))(a0);
          if ((loopRemaining != 0) && (a0[0x4b] == 3)) {
            if (iVar4 < 1) {
LAB_00189934:
              loopRemaining = iVar4 + 1;
              local_58[iVar4] = a0;
              iVar4 = loopRemaining;
              if (inlineLimit + otherLimit < loopRemaining) {
                return 0;
              }
            }
            else if (local_58[0] != a0) {
              loopIndex = 0;
              loopRemaining = iVar4;
              do {
                loopIndex = loopIndex + 1;
                loopRemaining = loopRemaining + -1;
                if (loopRemaining == 0) goto LAB_00189934;
              } while (a0 != local_58[loopIndex]);
            }
          }
        }
        else {
          loopRemaining = IRInst__hasSingleUse(a0,*(undefined4 *)(*(int *)(schedModel + 8) + 0x6c4));
          if (loopRemaining != 0) {
            a0 = (int *)IRInst__getOperandSource(a0,1);
            goto LAB_001898e0;
          }
        }
      }
      loopRemaining2 = loopRemaining2 + -1;
      if (loopRemaining2 == 0) {
        return 1;
      }
      inst = instB;
    } while (loopRemaining2 != 2);
  } while( true );
}

/* SchedModel__assignConstantSelectors @ 0x1899ac (568 bytes) */
int SchedModel__assignConstantSelectors(schedModel, instA, instB, param_4, inlineLimit)
  int schedModel;
  int *instA;
  int *instB;
  undefined4 param_4;
  int inlineLimit;
{
  int *operandVReg;
  bool bVar1;
  int *piVar2;
  int *a0;
  int loopIndex;
  int operandIndex;
  int loopIndex2;
  int loopIndex3;
  int operandIndex2;
  int loopIndex4;
  int *inst2;
  int *inst;
  int *local_68 [13];
  
  loopIndex2 = 0;
  do {
    loopIndex3 = 0;
    inst = instA;
    do {
      operandIndex2 = 1;
      if (inst != (int *)0x0) {
        for (; operandIndex = (**(code **)(*inst + 0x14))(inst), operandIndex2 <= operandIndex; operandIndex2 = operandIndex2 + 1) {
          a0 = (int *)IRInst__getOperandSource(inst,operandIndex2);
          loopIndex = (**(code **)(*a0 + 0x60))(a0);
          operandIndex = operandIndex2;
          inst2 = inst;
          if (loopIndex == 0) {
LAB_00189a60:
            loopIndex = (**(code **)(*a0 + 0x48))(a0);
            if ((loopIndex != 0) && (a0[0x4b] == 3)) {
              if (loopIndex2 < 1) {
                loopIndex = 0;
LAB_00189ab0:
                local_68[loopIndex2] = a0;
                loopIndex2 = loopIndex2 + 1;
              }
              else {
                loopIndex = 0;
                loopIndex4 = loopIndex2;
                piVar2 = local_68[0];
                while (a0 != piVar2) {
                  loopIndex = loopIndex + 1;
                  loopIndex4 = loopIndex4 + -1;
                  if (loopIndex4 == 0) goto LAB_00189ab0;
                  piVar2 = local_68[loopIndex];
                }
              }
              loopIndex4 = 0;
              if (loopIndex < inlineLimit) {
                do {
                  loopIndex = IRInst__getOperandRecord(inst2,operandIndex);
                  if (*(char *)(loopIndex4 + loopIndex + 0x10) != '\x04') {
                    (**(code **)(*inst2 + 0x88))(inst2,operandIndex,loopIndex4,3);
                  }
                  bVar1 = loopIndex4 != 3;
                  loopIndex4 = loopIndex4 + 1;
                } while (bVar1);
                *(undefined1 *)((int)a0 + 0x9f) = 0;
              }
              else {
                do {
                  loopIndex = IRInst__getOperandRecord(inst2,operandIndex);
                  if (*(char *)(loopIndex4 + loopIndex + 0x10) != '\x04') {
                    (**(code **)(*inst2 + 0x88))(inst2,operandIndex,loopIndex4,0);
                  }
                  bVar1 = loopIndex4 != 3;
                  loopIndex4 = loopIndex4 + 1;
                } while (bVar1);
                *(undefined1 *)(a0 + 0x27) = 0;
              }
            }
          }
          else {
            operandIndex = IRInst__hasSingleUse(a0,*(undefined4 *)(*(int *)(schedModel + 8) + 0x6c4));
            if (operandIndex != 0) {
              operandVReg = (int *)IRInst__getOperandSource(a0,1);
              operandIndex = 1;
              inst2 = a0;
              a0 = operandVReg;
              goto LAB_00189a60;
            }
          }
        }
      }
      bVar1 = loopIndex3 == 1;
      loopIndex3 = loopIndex3 + 1;
      if (bVar1) {
        return;
      }
      inst = instB;
    } while (loopIndex3 != 0);
  } while( true );
}

/* R300SchedModel__vslot15 @ 0x189be4 (64 bytes) */
int R300SchedModel__vslot15(this, param_2)
  undefined4 this;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if ((iVar1 == 0x1e) || (iVar1 == 0x1d)) {
    return 1;
  }
  if ((iVar1 != 0x1c) && (iVar1 != 0xa3)) {
    return 0;
  }
  return 2;
}

/* FUN_00189c24 @ 0x189c24 (188 bytes) */
int FUN_00189c24(inst)
  int *inst;
{
  int operandRecord;
  int sourceDef;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = 0;
  (**(code **)(*inst + 0x5c))(inst);
  iVar4 = *(int *)(inst[0x22] + 8);
  sourceDef = IRInst__getOperandSource(inst,1);
  uVar3 = *(uint *)(sourceDef + 0x94);
  iVar1 = (**(code **)(*inst + 0x14))(inst);
  if (1 < iVar1) {
    sourceDef = IRInst__getOperandSource(inst,2);
    uVar2 = *(uint *)(sourceDef + 0x94) & 0xfff;
  }
  operandRecord = IRInst__getOperandRecord(inst,0);
  return uVar2 | iVar4 << 0x19 | -(*(byte *)(operandRecord + 0x13) ^ 1) >> 7 & 0x1000000 |
                 (uVar3 & 0xfff) << 0xc;
}

/* FUN_00189ce0 @ 0x189ce0 (276 bytes) */
int FUN_00189ce0(inst, inst2)
  int *inst;
  int *inst2;
{
  char cVar1;
  int callResult;
  int operandVReg;
  
  callResult = (**(code **)(*inst + 0x5c))(inst,inst2);
  if (callResult != 0) {
    (**(code **)(*inst2 + 0x5c))(inst2);
  }
  if (*(int *)(inst[0x22] + 8) == *(int *)(inst2[0x22] + 8)) {
    callResult = IRInst__getOperandRecord(inst,0);
    cVar1 = *(char *)(callResult + 0x13);
    callResult = IRInst__getOperandRecord(inst2,0);
    if (cVar1 == *(char *)(callResult + 0x13)) {
      callResult = IRInst__getOperandSource(inst,1);
      operandVReg = IRInst__getOperandSource(inst2,1);
      if (callResult == operandVReg) {
        callResult = (**(code **)(*inst + 0x14))(inst);
        if (1 < callResult) {
          callResult = IRInst__getOperandSource(inst,2);
          operandVReg = IRInst__getOperandSource(inst2,2);
          if (callResult != operandVReg) {
            return 0xffffffff;
          }
        }
        return 0;
      }
    }
  }
  return 0xffffffff;
}

/* FUN_00189df4 @ 0x189df4 (480 bytes) */
int FUN_00189df4(inst, param_2, param_3)
  int *inst;
  int *param_2;
  int *param_3;
{
  int operandRecord;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*inst + 0x28))(inst,param_2,param_3);
  if ((iVar2 == 0) && (*(int *)(inst[0x22] + 4) != 1)) {
    iVar4 = *(int *)(inst[0x22] + 8);
    iVar2 = iVar4;
    if ((iVar4 - 0x1cU < 3) || (iVar4 == 0xa3)) {
      if (((iVar4 == 0x1d) || (iVar4 == 0xa3)) ||
         (iVar4 = IRInst__getOperandRecord(inst,0), *(char *)(iVar4 + 0x13) == '\0')) {
        iVar4 = 0x97;
      }
      else {
        iVar4 = -1;
      }
LAB_00189f70:
      if (iVar2 < 0) goto LAB_00189f94;
LAB_00189f84:
      if (*param_2 < 0) {
        *param_2 = iVar2;
        goto LAB_00189f94;
      }
    }
    else {
      if (((((iVar4 != 0x37) && (iVar4 != 0x3a)) &&
           ((iVar4 != 0x3b && ((iVar4 != 0x3e && (iVar4 != 0x3f)))))) && (iVar4 != 0x40)) &&
         ((((iVar4 != 0x41 && (iVar4 != 0x42)) && (iVar4 != 0x43)) &&
          ((iVar4 != 0x4c && (iVar4 != 0x4d)))))) {
        iVar2 = IRInst__getOperandRecord(inst,0);
        uVar1 = *(uint *)(iVar2 + 0x10);
        if ((uVar1 >> 0x18 == 0) ||
           (((uVar1 >> 0x10 & 0xff) == 0 || (iVar2 = -1, (uVar1 >> 8 & 0xff) == 0)))) {
          iVar2 = iVar4;
        }
        if ((uVar1 & 0xff) != 0) {
          iVar4 = -1;
        }
        goto LAB_00189f70;
      }
      operandRecord = IRInst__getOperandRecord(inst,0);
      uVar1 = *(uint *)(operandRecord + 0x10);
      if (((uVar1 >> 0x18 == 0) || ((uVar1 >> 0x10 & 0xff) == 0)) || ((uVar1 >> 8 & 0xff) == 0)) {
        iVar2 = 0x98;
        goto LAB_00189f84;
      }
LAB_00189f94:
      if (iVar4 < 0) goto LAB_00189fb4;
      if (*param_3 < 0) {
        *param_3 = iVar4;
        return 1;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_00189fb4:
    uVar3 = 1;
  }
  return uVar3;
}

/* R300SchedModel__vslot19 @ 0x189fd4 (172 bytes) */
int R300SchedModel__vslot19(this, inst, param_3, param_4, param_5, param_6, param_7)
  undefined4 this;
  int *inst;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int callResult;
  undefined4 resourceClass;
  int vectorSlotUse;
  int scalarSlotUse [7];
  
  scalarSlotUse[0] = -1;
  vectorSlotUse = -1;
  if ((inst[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*inst + 0x28))(inst);
    if (callResult == 0) {
      ((int (*)())FUN_00189df4)(inst,&vectorSlotUse,scalarSlotUse);
      if (vectorSlotUse < 0) {
        if (-1 < scalarSlotUse[0]) {
          return 2;
        }
        goto LAB_0018a060;
      }
      if (scalarSlotUse[0] < 0) {
        return 1;
      }
    }
    resourceClass = 3;
  }
  else {
LAB_0018a060:
    resourceClass = 0;
  }
  return resourceClass;
}

/* R300SchedModel__vslot34 @ 0x18a080 (364 bytes) */
int R300SchedModel__vslot34(this, inst)
  undefined4 this;
  int *inst;
{
  undefined4 selectWord;
  int source1Select;
  int callResult;
  undefined4 matchesDefaultPattern;
  int *a0;
  int operandNumber;
  
  callResult = (**(code **)(*inst + 0x30))(inst,inst);
  if (callResult != 0) {
    callResult = IRInst__getOperandRecord(inst,1);
    matchesDefaultPattern = ((int (*)())SelectWord__matchesDefaultPattern)(*(undefined4 *)(callResult + 0x10));
    return matchesDefaultPattern;
  }
  operandNumber = 1;
  callResult = (**(code **)(*inst + 0x5c))(inst);
  if (callResult == 0) {
    for (; callResult = (**(code **)(*inst + 0x14))(inst), operandNumber <= callResult; operandNumber = operandNumber + 1) {
      callResult = IRInst__getOperandRecord(inst,operandNumber);
      selectWord = *(undefined4 *)(callResult + 0x10);
      a0 = (int *)IRInst__getOperandSource(inst,operandNumber);
      callResult = (**(code **)(*a0 + 0x5c))(a0);
      if (callResult == 0) {
        callResult = ((int (*)())SelectWord__isDefaultAfterCanonicalise)(selectWord);
      }
      else {
        callResult = ((int (*)())SelectWord__matchesAnyKnownPattern)(selectWord);
      }
      if (callResult == 0) {
        return 0;
      }
    }
  }
  else {
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult != 1) {
      callResult = IRInst__getOperandRecord(inst,1);
      source1Select = *(int *)(callResult + 0x10);
      callResult = IRInst__getOperandRecord(inst,2);
      if (source1Select != *(int *)(callResult + 0x10)) {
        return 0;
      }
    }
  }
  return 1;
}

/* R300SchedModel__vslot26 @ 0x18a1ec (596 bytes) */
int R300SchedModel__vslot26(this, inst, operandNumber, selectsOut, groupCount)
  undefined4 this;
  int *inst;
  int operandNumber;
  int selectsOut;
  int *groupCount;
{
  int tableRow;
  int selectIsNative;
  int sourceIsPresub;
  int numSources;
  int isSourceSelectIdentity;
  int isPresub;
  int isFetch;
  int operandRecord;
  int *a0;
  int tableEntry;
  uint entryWord;
  uint selectWord;
  
  *groupCount = 0;
  operandRecord = IRInst__getOperandRecord(inst,operandNumber);
  selectWord = *(uint *)(operandRecord + 0x10);
  isFetch = (**(code **)(*inst + 0x28))(inst);
  if (isFetch == 0) {
    isPresub = (**(code **)(*inst + 0x5c))(inst);
    if (isPresub != 0) {
      isSourceSelectIdentity = IRInst__isSourceSelectIdentity(inst,1);
      if (isSourceSelectIdentity == 0) {
        return;
      }
      numSources = (**(code **)(*inst + 0x14))(inst);
      if (numSources == 1) {
        return;
      }
      IRInst__isSourceSelectIdentity(inst,2);
      return;
    }
    a0 = (int *)IRInst__getOperandSource(inst,operandNumber);
    sourceIsPresub = (**(code **)(*a0 + 0x5c))(a0);
    if (sourceIsPresub == 0) {
      selectIsNative = ((int (*)())SelectWord__isDefaultAfterCanonicalise)(selectWord);
    }
    else {
      selectIsNative = ((int (*)())SelectWord__matchesAnyKnownPattern)(selectWord);
    }
  }
  else {
    if (operandNumber != 1) {
      return;
    }
    selectIsNative = ((int (*)())SelectWord__matchesDefaultPattern)(selectWord);
  }
  if (selectIsNative == 0) {
    tableRow = ((selectWord >> 0x18) * 0x7d + (selectWord >> 0x10 & 0xff) * 0x19 + (selectWord >> 8 & 0xff) * 5 +
            (selectWord & 0xff)) * 4;
    for (tableEntry = *(int *)(&DAT_001b0240 + (tableRow + *groupCount) * 4); tableEntry != 0x4040404;
        tableEntry = *(int *)(&DAT_001b0240 + (tableRow + tableEntry + 1) * 4)) {
      entryWord = *(uint *)(&DAT_001b0240 + (tableRow + *groupCount) * 4);
      *(uint *)(*groupCount * 4 + selectsOut) =
           entryWord << 0x18 | (entryWord & 0xff00) << 8 | entryWord >> 8 & 0xff00 | entryWord >> 0x18;
      tableEntry = *groupCount;
      *groupCount = tableEntry + 1;
    }
    if (selectWord >> 0x18 != 4) {
      selectWord = selectWord & 0xffffff;
    }
    if ((selectWord >> 0x10 & 0xff) != 4) {
      selectWord = selectWord & 0xff00ffff | 0x10000;
    }
    if ((selectWord >> 8 & 0xff) != 4) {
      selectWord = selectWord & 0xffff00ff | 0x200;
    }
    if ((selectWord & 0xff) != 4) {
      selectWord = selectWord & 0xffffff00 | 3;
    }
    operandRecord = IRInst__getOperandRecord(inst,operandNumber);
    *(uint *)(operandRecord + 0x10) = selectWord;
  }
  return;
}

/* R300SchedModel__vslot28 @ 0x18a440 (232 bytes) */
int R300SchedModel__vslot28(this, program)
  int *this;
  int program;
{
  int source1Record;
  int fullSelect;
  int destRecord;
  undefined4 mergedSelect;
  undefined4 sourceSelect;
  uint laneSelectWord;
  uint bucketCountWord;
  uint sourceNegate;
  int operandRecord;
  undefined4 arenaAt378;
  int *operandVReg;
  char laneSelect;
  int *inst;
  uint bucketCount;
  int *nextInst;
  undefined4 *hashAlloc;
  undefined4 operandVReg2;
  int *callResult;
  int loopIndex2;
  int loopRemaining;
  int operandIndex;
  int virtualReg;
  int regKind;
  int destSelect;
  int block;
  uint *hashSet;
  undefined4 bucketArray;
  uint loopIndex3;
  int loopIndex;
  double literalValue;
  undefined4 local_78;
  int local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  block = *(int *)(program + 900);
  if (*(int *)(block + 8) != 0) {
    local_5c = 0x18a450;
    local_58 = 0x18a450;
    do {
      arenaAt378 = *(undefined4 *)(this[2] + 0x378);
      hashAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
      hashSet = hashAlloc + 1;
      *hashAlloc = arenaAt378;
      hashAlloc[4] = local_5c + -0x770;
      bucketCount = 1;
      loopIndex = 0x20;
      hashAlloc[1] = 1;
      hashAlloc[5] = local_58 + -0x82c;
      hashAlloc[6] = arenaAt378;
      do {
        bucketCount = bucketCount << 1;
        if (0xf < bucketCount) break;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      *hashSet = bucketCount;
      hashAlloc[2] = 0;
      bucketArray = Arena__alloc(arenaAt378,*hashSet << 2);
      hashAlloc[3] = bucketArray;
      _memset(bucketArray,0,*hashSet << 2);
      inst = *(int **)(block + 0x98);
      for (nextInst = (int *)(*(int **)(block + 0x98))[2]; nextInst != (int *)0x0;
          nextInst = (int *)nextInst[2]) {
        if ((inst[5] & 1U) != 0) {
          if ((*(int *)(inst[0x22] + 8) == 0x31) || (*(int *)(inst[0x22] + 8) == 0x30)) {
            operandVReg = (int *)IRInst__getOperandSource(inst,1);
            loopIndex = (**(code **)(*operandVReg + 0x5c))();
            if ((loopIndex != 0) && ((inst[0x2e] & 2U) == 0)) {
              operandVReg = (int *)IRInst__getOperandSource(inst,1);
              loopIndex = inst[0x49];
              if (*(int *)(operandVReg[0x22] + 8) == 0x99) {
                loopIndex = loopIndex + 1;
              }
              operandIndex = (**(code **)(**(int **)(this[2] + 0x30c) + 0xfc))
                                 (*(int **)(this[2] + 0x30c),loopIndex,0);
              if (operandIndex != 0) {
                loopRemaining = inst[1];
                loopIndex2 = 0;
                virtualReg = inst[0x25];
                regKind = inst[0x26];
                operandRecord = IRInst__getOperandRecord(inst,0);
                destSelect = *(int *)(operandRecord + 0x10);
                operandRecord = IRInst__getOperandRecord(inst,1);
                loopIndex3 = inst[5];
                sourceNegate = inst[0x2e] & 1;
                sourceSelect = *(undefined4 *)(operandRecord + 0x10);
                operandIndex = inst[0x48];
                if ((loopIndex3 & 0x200) != 0) {
                  loopIndex2 = IRInst__getOperandSource(inst,inst[0x21]);
                }
                DList__unlink(inst);
                IRInst__reinitAsBinary(inst,0x12,*(undefined4 *)(program + 8));
                inst[0x27] = destSelect;
                inst[0x48] = operandIndex;
                inst[0x49] = loopIndex;
                inst[0x25] = virtualReg;
                inst[0x26] = regKind;
                if ((loopIndex3 & 0x40) == 0) {
                  inst[5] = inst[5] & 0xffffffbf;
                }
                else {
                  inst[5] = inst[5] | 0x40;
                }
                if ((loopIndex3 & 2) != 0) {
                  IRInst__setHardwareRegisterAndAdd(inst,*(undefined4 *)(this[2] + 0x6c4),regKind,virtualReg);
                }
                if (loopIndex2 != 0) {
                  IRInst__setExtraOperandSource(inst,loopIndex2,0,this[2]);
                }
                Block__insertInstAfter(block,loopRemaining,inst);
                loopIndex = *(int *)(operandVReg[0x22] + 8);
                if (loopIndex == 0x9a) {
                  operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                  IRInst__setOperandSource(inst,1,operandVReg2,0,this[2]);
                  operandVReg2 = IRInst__getOperandSource(operandVReg,2);
                  IRInst__setOperandSource(inst,2,operandVReg2,0,this[2]);
                  loopIndex = IRInst__getOperandRecord(inst,1);
                  *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                  loopIndex = IRInst__getOperandRecord(inst,2);
                  *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                  IROperand__setModifierBits(inst + 0x29,1,sourceNegate);
                  IROperand__setModifierBits(inst + 0x2f,1,sourceNegate ^ 1);
                }
                else {
                  if (loopIndex < 0x9b) {
                    if (loopIndex != 0x99) goto code_r0x0018a910;
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(inst,1,operandVReg2,0,this[2]);
                    literalValue = (double)FLOAT_001aa10c;
                    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,literalValue,literalValue,literalValue,literalValue);
                    loopIndex = IRInst__getOperandRecord(inst,1);
                    *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                    loopIndex3 = sourceNegate ^ 1;
                  }
                  else if (loopIndex == 0x9b) {
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(inst,1,operandVReg2,0,this[2]);
                    operandVReg2 = IRInst__getOperandSource(operandVReg,2);
                    IRInst__setOperandSource(inst,2,operandVReg2,0,this[2]);
                    loopIndex = IRInst__getOperandRecord(inst,1);
                    *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                    loopIndex = IRInst__getOperandRecord(inst,2);
                    *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                    loopIndex3 = sourceNegate;
                  }
                  else {
                    if (loopIndex != 0x9c) goto code_r0x0018a910;
                    operandVReg2 = IRInst__getOperandSource(operandVReg,1);
                    IRInst__setOperandSource(inst,1,operandVReg2,0,this[2]);
                    literalValue = (double)FLOAT_001aa0e8;
                    ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,2,literalValue,literalValue,literalValue,literalValue);
                    loopIndex = IRInst__getOperandRecord(inst,1);
                    *(undefined4 *)(loopIndex + 0x10) = sourceSelect;
                    loopIndex3 = sourceNegate ^ 1;
                  }
                  IROperand__setModifierBits(inst + 0x29,1,loopIndex3);
                  IROperand__setModifierBits(inst + 0x2f,1,sourceNegate);
                }
code_r0x0018a910:
                (**(code **)(*operandVReg + 0xc))(operandVReg,0,this[2]);
                nextInst = (int *)inst[2];
                goto code_r0x0018aab8;
              }
            }
          }
          for (loopIndex = 1; operandIndex = (**(code **)(*inst + 0x14))(inst), loopIndex <= operandIndex;
              loopIndex = loopIndex + 1) {
            operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
            operandIndex = (**(code **)(*operandVReg + 0x5c))();
            if (operandIndex != 0) {
              callResult = (int *)HashTable__find(hashSet,operandVReg);
              if (callResult == (int *)0x0) {
                HashTable__insert(hashSet,operandVReg);
              }
              else if (operandVReg != callResult) {
                destRecord = IRInst__getOperandRecord(callResult,0);
                local_74[0] = *(int *)(destRecord + 0x10);
                loopRemaining = IRInst__getOperandRecord(operandVReg,0);
                fullSelect = DAT_001b2a64;
                loopIndex2 = 0;
                local_78 = *(undefined4 *)(loopRemaining + 0x10);
                loopRemaining = 4;
                do {
                  laneSelect = *(char *)((int)local_74 + loopIndex2 + -4);
                  if (laneSelect != '\x01') {
                    *(char *)((int)local_74 + loopIndex2) = laneSelect;
                  }
                  loopIndex2 = loopIndex2 + 1;
                  loopRemaining = loopRemaining + -1;
                } while (loopRemaining != 0);
                callResult[0x27] = local_74[0];
                WriteMask__fromSelectWord(&local_68,local_74[0]);
                SelectWord__maskUnused(&local_64,fullSelect,local_68);
                mergedSelect = local_64;
                source1Record = IRInst__getOperandRecord(callResult,1);
                *(undefined4 *)(source1Record + 0x10) = mergedSelect;
                operandIndex = (**(code **)(*callResult + 0x14))(callResult);
                if (1 < operandIndex) {
                  operandIndex = IRInst__getOperandRecord(callResult,2);
                  *(undefined4 *)(operandIndex + 0x10) = mergedSelect;
                }
                IRInst__setOperandSource(inst,loopIndex,callResult,0,this[2]);
                (**(code **)(*operandVReg + 0xc))(operandVReg,0,this[2]);
              }
            }
          }
          nextInst = (int *)inst[2];
        }
code_r0x0018aab8:
        inst = nextInst;
      }
      if (hashSet != (uint *)0x0) {
        bucketCountWord = *hashSet;
        if (bucketCountWord == 0) {
          loopIndex = hashAlloc[3];
        }
        else {
          loopIndex = hashAlloc[3];
          loopIndex3 = 0;
          do {
            operandIndex = *(int *)(loopIndex3 * 4 + loopIndex);
            if (operandIndex != 0) {
              Arena__free(hashAlloc[6],operandIndex);
              bucketCountWord = *hashSet;
              loopIndex = hashAlloc[3];
            }
            loopIndex3 = loopIndex3 + 1;
          } while (loopIndex3 < bucketCountWord);
        }
        Arena__free(hashAlloc[6],loopIndex);
        Arena__free(*hashAlloc,hashAlloc);
      }
      inst = *(int **)(block + 0x98);
      for (nextInst = (int *)(*(int **)(block + 0x98))[2]; nextInst != (int *)0x0;
          nextInst = (int *)nextInst[2]) {
        if ((inst[5] & 1U) != 0) {
          operandIndex = 1;
          loopIndex = Compiler__isOptionEnabled(this[2],0x41);
          if (loopIndex != 0) {
            for (; loopIndex = (**(code **)(*inst + 0x14))(inst), operandIndex <= loopIndex;
                operandIndex = operandIndex + 1) {
              operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
              loopIndex = (**(code **)(*operandVReg + 0x80))();
              loopIndex2 = IRInst__getOperandRecord(inst,operandIndex);
              FUN_000f39d0(&local_60,*(undefined4 *)(loopIndex2 + 0x10));
              laneSelectWord = local_60;
              loopIndex2 = IRInst__getOperandRecord(inst,operandIndex);
              loopIndex3 = *(uint *)(loopIndex2 + 0x10);
              if ((((loopIndex != 0) &&
                   (((loopRemaining = IRInst__getOperandRecord(loopIndex,0), loopIndex2 = _UNK_001b2a7c,
                     *(char *)(loopRemaining + 0x12) == '\x01' || (*(int *)(loopIndex + 0xb4) == _UNK_001b2a7c)
                     ) && ((laneSelectWord >> 8 & 0xff) != 0)))) && ((loopIndex3 >> 8 & 0xff) == 3)) &&
                 (((laneSelectWord >> 0x18 != 0 && (loopIndex3 >> 0x18 == 0)) ||
                  (((laneSelectWord >> 0x10 & 0xff) != 0 && ((loopIndex3 >> 0x10 & 0xff) == 1)))))) {
                *(undefined1 *)(loopIndex + 0xe) = 1;
                *(int *)(loopIndex + 0xb4) = loopIndex2;
                *(undefined1 *)(loopIndex + 0x9e) = 0;
                loopIndex = DAT_001b2a64;
                if (operandIndex == 0) {
                  inst[0x27] = DAT_001b2a64;
                }
                else {
                  loopIndex2 = IRInst__getOperandRecord(inst,operandIndex);
                  *(int *)(loopIndex2 + 0x10) = loopIndex;
                }
              }
            }
          }
          if (*(int *)(inst[0x22] + 8) == 0x8e) {
            nextInst = (int *)inst[2];
          }
          else {
            (**(code **)(*this + 0x6c))(this,inst);
            nextInst = (int *)inst[2];
          }
        }
        inst = nextInst;
      }
      block = *(int *)(block + 8);
    } while (*(int *)(block + 8) != 0);
  }
  return;
}

/* R300SchedModel__vslot16 @ 0x18ad08 (1204 bytes) */
int R300SchedModel__vslot16(this, inst, trialSelect, resultLane)
  int *this;
  int inst;
  int *trialSelect;
  undefined4 *resultLane;
{
  int trialSelectNext;
  int newInstVtable;
  int canAdd;
  int operandRecord2;
  int opcode;
  int *newInst;
  undefined4 operandRecord;
  undefined4 in_r7;
  undefined4 in_r8;
  code *setSourceSelect;
  int trialSelectValue;
  
  opcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (opcode == 0x1c) {
    newInst = IRInst__create(0x13,this[2]);
    newInst[0x25] = newInst[0x53];
    newInst[0x27] = 0x1010100;
    newInst[0x26] = 0;
    *resultLane = 3;
    operandRecord = IRInst__getOperandRecord(inst,1);
    IRInst__getOrCreateOperandRecord(newInst,1,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,2);
    IRInst__getOrCreateOperandRecord(newInst,2,operandRecord,this[2]);
    newInst[3] = 0;
    *(undefined1 *)((int)newInst + 0xf) = 1;
    *trialSelect = 2;
    do {
      operandRecord2 = IRInst__getOperandRecord(newInst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      trialSelectValue = *trialSelect;
      setSourceSelect = *(code **)(*newInst + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      (*setSourceSelect)(newInst,1,3,*(undefined1 *)(trialSelectValue + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(newInst,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      trialSelectValue = *trialSelect;
      setSourceSelect = *(code **)(*newInst + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      (*setSourceSelect)(newInst,2,3,*(undefined1 *)(trialSelectValue + operandRecord2 + 0x10));
      canAdd = (**(code **)(*this + 0xc))(this,newInst);
      if (canAdd != 0) {
        return newInst;
      }
    } while (((*(uint *)(*(int *)(this[2] + 0x30c) + 8) & 0x400) != 0) &&
            (canAdd = *trialSelect, *trialSelect = canAdd + -1, -1 < canAdd + -1));
  }
  else {
    if (opcode != 0x1e) {
      if (opcode != 0x1d) {
        return (int *)0x0;
      }
      newInst = IRInst__create(0x1c,this[2]);
      newInst[0x25] = newInst[0x53];
      newInst[0x27] = 0x10101;
      newInst[0x26] = 0;
      *resultLane = 1;
      *trialSelect = 3;
      operandRecord = IRInst__getOperandRecord(inst,1);
      IRInst__getOrCreateOperandRecord(newInst,1,operandRecord,this[2]);
      operandRecord = IRInst__getOperandRecord(inst,2);
      IRInst__getOrCreateOperandRecord(newInst,2,operandRecord,this[2]);
      (**(code **)(*newInst + 0x88))(newInst,1,3,4);
      (**(code **)(*newInst + 0x88))(newInst,2,3,4,in_r7,in_r8,*(code **)(*newInst + 0x88));
      newInst[3] = 0;
      *(undefined1 *)(newInst + 3) = 1;
      canAdd = (**(code **)(*this + 0xc))(this,newInst);
      if (canAdd != 0) {
        return newInst;
      }
      newInstVtable = *newInst;
      goto LAB_0018b190;
    }
    newInst = IRInst__create(0x14,this[2]);
    newInst[0x25] = newInst[0x53];
    newInst[0x27] = 0x1010100;
    newInst[0x26] = 0;
    *resultLane = 3;
    operandRecord = IRInst__getOperandRecord(inst,1);
    IRInst__getOrCreateOperandRecord(newInst,1,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,2);
    IRInst__getOrCreateOperandRecord(newInst,2,operandRecord,this[2]);
    operandRecord = IRInst__getOperandRecord(inst,3);
    IRInst__getOrCreateOperandRecord(newInst,3,operandRecord,this[2]);
    newInst[3] = 0;
    *(undefined1 *)((int)newInst + 0xf) = 1;
    *trialSelect = 1;
    do {
      operandRecord2 = IRInst__getOperandRecord(newInst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      trialSelectValue = *trialSelect;
      setSourceSelect = *(code **)(*newInst + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      (*setSourceSelect)(newInst,1,3,*(undefined1 *)(trialSelectValue + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(newInst,2);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      trialSelectValue = *trialSelect;
      setSourceSelect = *(code **)(*newInst + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      (*setSourceSelect)(newInst,2,3,*(undefined1 *)(trialSelectValue + operandRecord2 + 0x10));
      operandRecord2 = IRInst__getOperandRecord(newInst,3);
      *(undefined4 *)(operandRecord2 + 0x10) = 0x4040404;
      setSourceSelect = *(code **)(*newInst + 0x88);
      operandRecord2 = IRInst__getOperandRecord(inst,3);
      (*setSourceSelect)(newInst,3,3,*(undefined1 *)(operandRecord2 + 0x12));
      canAdd = (**(code **)(*this + 0xc))(this,newInst);
      if (canAdd != 0) {
        return newInst;
      }
      trialSelectNext = *trialSelect;
      *trialSelect = trialSelectNext + -1;
    } while (-1 < trialSelectNext + -1);
  }
  newInstVtable = *newInst;
LAB_0018b190:
  (**(code **)(newInstVtable + 4))(newInst);
  return (int *)0x0;
}

/* FUN_0018b1bc @ 0x18b1bc (1176 bytes) */
int FUN_0018b1bc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *vector2;
  int *inst;
  bool bVar1;
  bool bVar2;
  undefined4 *loopIndex5;
  undefined1 *loopIndex6;
  uint loopIndex8;
  int *piVar6;
  int loopIndex3;
  uint uVar8;
  int *a0;
  undefined4 in_r8;
  int loopIndex4;
  int loopIndex;
  uint uVar11;
  uint uVar12;
  uint loopIndex7;
  int loopIndex2;
  uint *vector;
  
  bVar1 = param_3 <= param_4;
  if (bVar1) {
    loopIndex5 = (undefined4 *)(param_3 * 4 + param_2 + 0x48);
    loopIndex4 = param_3;
    do {
      loopIndex4 = loopIndex4 + 1;
      *loopIndex5 = 0;
      loopIndex5 = loopIndex5 + 1;
    } while (loopIndex4 <= param_4);
  }
  vector = *(uint **)(param_2 + 0x40);
  loopIndex7 = 0;
  uVar11 = vector[1];
  loopIndex4 = param_5;
  if (0 < (int)uVar11) {
    while( true ) {
      if (loopIndex7 < *vector) {
        loopIndex8 = vector[1];
        if (loopIndex8 <= loopIndex7) {
          _memset(loopIndex8 * 4 + vector[2],0,(loopIndex7 - loopIndex8) * 4 + 4);
          vector[1] = loopIndex7 + 1;
        }
        piVar6 = (int *)(loopIndex7 * 4 + vector[2]);
      }
      else {
        piVar6 = (int *)Vector__elementRefGrow(vector,loopIndex7);
      }
      loopIndex7 = loopIndex7 + 1;
      loopIndex2 = *piVar6;
      if (*(int *)(loopIndex2 + 8) == 0) {
        if (bVar1) {
          loopIndex6 = (undefined1 *)(param_3 + loopIndex2 + 0x18);
          loopIndex = param_3;
          do {
            loopIndex = loopIndex + 1;
            *loopIndex6 = 0;
            loopIndex6 = loopIndex6 + 1;
          } while (loopIndex <= param_4);
        }
        *(undefined1 *)(param_5 + loopIndex2 + 0x18) = 1;
        loopIndex = param_5 * 4 + param_2;
        *(int *)(loopIndex + 0x48) = *(int *)(loopIndex + 0x48) + 1;
        loopIndex = *(int *)(loopIndex2 + 4);
        inst = *(int **)(loopIndex + 0x38);
        if ((inst[5] & 0x200U) != 0) {
          IRInst__getOperandSource(inst,inst[0x21]);
        }
        (**(code **)(*inst + 0x28))(inst);
        loopIndex3 = (**(code **)(*inst + 0x5c))(inst);
        if (loopIndex3 == 0) {
          a0 = (int *)IRInst__getOperandSource(inst,*(undefined4 *)(loopIndex2 + 0x10));
          loopIndex = (**(code **)(*a0 + 0x60))(a0);
          if (loopIndex == 0) {
            loopIndex = 0;
            do {
              loopIndex3 = IRInst__getOperandRecord(inst,*(undefined4 *)(loopIndex2 + 0x10));
              loopIndex8 = (uint)*(byte *)(loopIndex + loopIndex3 + 0x10);
              if ((param_3 <= (int)loopIndex8) && ((int)loopIndex8 <= param_4)) {
                (**(code **)(*inst + 0x88))(inst,*(undefined4 *)(loopIndex2 + 0x10),loopIndex,param_5);
              }
              bVar2 = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (bVar2);
          }
        }
        else {
          loopIndex2 = (**(code **)(*inst + 0x14))(inst);
          if (1 < loopIndex2) {
            IRInst__getOperandSource(inst,1);
            IRInst__getOperandSource(inst,2);
          }
          if (bVar1) {
            loopIndex6 = (undefined1 *)((int)inst + param_3 + 0xc);
            loopIndex2 = param_3;
            do {
              loopIndex6[0x90] = 1;
              loopIndex3 = *inst;
              *loopIndex6 = 0;
              (**(code **)(loopIndex3 + 0x88))(inst,1,loopIndex2,4);
              loopIndex3 = (**(code **)(*inst + 0x14))(inst);
              if (loopIndex3 == 2) {
                (**(code **)(*inst + 0x88))(inst,2,loopIndex2,4);
              }
              loopIndex2 = loopIndex2 + 1;
              loopIndex6 = loopIndex6 + 1;
            } while (loopIndex2 <= param_4);
          }
          loopIndex3 = param_5 + (int)inst;
          *(undefined1 *)(loopIndex3 + 0x9c) = 0;
          loopIndex2 = *inst;
          *(undefined1 *)(loopIndex3 + 0xc) = 1;
          (**(code **)(loopIndex2 + 0x88))(inst,1,param_5,param_5,loopIndex4,in_r8,loopIndex3);
          loopIndex2 = (**(code **)(*inst + 0x14))(inst);
          if (loopIndex2 == 2) {
            (**(code **)(*inst + 0x88))(inst,2,param_5,param_5);
          }
          if (bVar1) {
            loopIndex5 = (undefined4 *)(param_3 * 4 + loopIndex + 0x48);
            loopIndex2 = param_3;
            do {
              loopIndex2 = loopIndex2 + 1;
              *loopIndex5 = 0;
              loopIndex5 = loopIndex5 + 1;
            } while (loopIndex2 <= param_4);
          }
          vector2 = *(uint **)(loopIndex + 0x40);
          loopIndex8 = 0;
          uVar12 = vector2[1];
          if (0 < (int)uVar12) {
            while( true ) {
              if (loopIndex8 < *vector2) {
                uVar8 = vector2[1];
                if (uVar8 <= loopIndex8) {
                  _memset(uVar8 * 4 + vector2[2],0,(loopIndex8 - uVar8) * 4 + 4);
                  vector2[1] = loopIndex8 + 1;
                }
                piVar6 = (int *)(loopIndex8 * 4 + vector2[2]);
              }
              else {
                piVar6 = (int *)Vector__elementRefGrow(vector2,loopIndex8);
              }
              loopIndex8 = loopIndex8 + 1;
              loopIndex2 = *piVar6;
              if (*(int *)(loopIndex2 + 8) == 0) {
                if (bVar1) {
                  loopIndex6 = (undefined1 *)(param_3 + loopIndex2 + 0x18);
                  loopIndex3 = param_3;
                  do {
                    loopIndex3 = loopIndex3 + 1;
                    *loopIndex6 = 0;
                    loopIndex6 = loopIndex6 + 1;
                  } while (loopIndex3 <= param_4);
                }
                *(undefined1 *)(param_5 + loopIndex2 + 0x18) = 1;
                loopIndex2 = param_5 * 4 + loopIndex;
                *(int *)(loopIndex2 + 0x48) = *(int *)(loopIndex2 + 0x48) + 1;
              }
              if (uVar12 == loopIndex8) break;
              vector2 = *(uint **)(loopIndex + 0x40);
            }
          }
        }
      }
      if (uVar11 == loopIndex7) break;
      vector = *(uint **)(param_2 + 0x40);
    }
  }
  return;
}

/* R300SchedModel__vslot11 @ 0x18b654 (888 bytes) */
int R300SchedModel__vslot11(this, node, writerArrays)
  int *this;
  int node;
  int writerArrays;
{
  int sourceNumber;
  int targetLane;
  int operandRecord;
  bool lastScan;
  undefined1 laneSelect;
  uint groupMaskWord;
  int groupReg;
  int writerNode;
  undefined4 in_r7;
  undefined4 in_r8;
  byte *groupBytes;
  int loopIndex;
  int *nodeInst;
  int loopRemaining;
  undefined4 freeLanes;
  
  groupBytes = *(byte **)(node + 0x60);
  freeLanes = 0x1010101;
  if (groupBytes != (byte *)0x0) {
    groupMaskWord = 0x1010101 -
            ((uint)groupBytes[3] << 0x18 | (uint)groupBytes[2] << 0x10 | (uint)groupBytes[1] << 8 |
            (uint)*groupBytes);
    freeLanes = groupMaskWord * 0x1000000 | (groupMaskWord & 0xff00) << 8 | groupMaskWord >> 8 & 0xff00 | groupMaskWord >> 0x18;
    groupReg = *(int *)(*(int *)(node + 0x60) + 4);
    if (-1 < groupReg) {
      loopRemaining = 4;
      loopIndex = 0;
      in_r8 = 0;
      do {
        writerNode = *(int *)(groupReg * 4 + *(int *)(writerArrays + loopIndex * 4));
        if ((writerNode != 0) && (*(int *)(loopIndex * 4 + writerNode + 0x48) != 0)) {
          *(undefined1 *)((int)&freeLanes + loopIndex) = 0;
        }
        loopIndex = loopIndex + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
    }
  }
  if (freeLanes == 0) {
    return 0;
  }
  nodeInst = *(int **)(node + 0x38);
  IRInst__countWrittenComponents(nodeInst);
  operandRecord = IRInst__getOperandRecord(nodeInst,0);
  if (*(char *)(operandRecord + 0x13) == '\0') {
    if (freeLanes == 0x1010101) {
      loopIndex = this[0x1a];
      this[0x1a] = loopIndex + 1;
      if (2 < loopIndex + 1) {
        this[0x1a] = 0;
      }
    }
    else {
      loopIndex = 0;
      while (*(char *)((int)&freeLanes + loopIndex) == '\0') {
        lastScan = loopIndex == 2;
        loopIndex = loopIndex + 1;
        if (lastScan) {
          return 0;
        }
      }
    }
    if (loopIndex == -1) {
      return 0;
    }
    targetLane = 3;
  }
  else {
    if ((char)freeLanes == '\0') {
      return 0;
    }
    operandRecord = IRInst__getOperandRecord(nodeInst,0);
    loopIndex = 3;
    targetLane = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord + 0x10));
  }
  *(undefined1 *)((int)nodeInst + targetLane + 0x9c) = 1;
  *(undefined1 *)((int)nodeInst + targetLane + 0xc) = 0;
  sourceNumber = 1;
  *(undefined1 *)((int)nodeInst + loopIndex + 0x9c) = 0;
  loopRemaining = nodeInst[0x22];
  *(undefined1 *)((int)nodeInst + loopIndex + 0xc) = 1;
  if (*(int *)(PTR_DAT_001e913c + *(int *)(loopRemaining + 8) * 0x38 + 0x34) == 0) {
    for (; loopRemaining = (**(code **)(*nodeInst + 0x14))(nodeInst), sourceNumber <= loopRemaining; sourceNumber = sourceNumber + 1) {
      loopRemaining = IRInst__getOperandRecord(nodeInst,sourceNumber);
      laneSelect = *(undefined1 *)(targetLane + loopRemaining + 0x10);
      (**(code **)(*nodeInst + 0x88))(nodeInst,sourceNumber,targetLane,4,in_r7,in_r8,targetLane + loopRemaining);
      (**(code **)(*nodeInst + 0x88))(nodeInst,sourceNumber,loopIndex,laneSelect);
    }
  }
  loopRemaining = (**(code **)(*this + 0xc))(this,*(undefined4 *)(node + 0x38));
  if (loopRemaining == 0) {
    *(undefined1 *)((int)nodeInst + targetLane + 0x9c) = 0;
    *(undefined1 *)((int)nodeInst + targetLane + 0xc) = 1;
    sourceNumber = 1;
    *(undefined1 *)((int)nodeInst + loopIndex + 0x9c) = 1;
    loopRemaining = nodeInst[0x22];
    *(undefined1 *)((int)nodeInst + loopIndex + 0xc) = 0;
    if (*(int *)(PTR_DAT_001e913c + *(int *)(loopRemaining + 8) * 0x38 + 0x34) == 0) {
      for (; loopRemaining = (**(code **)(*nodeInst + 0x14))(nodeInst), sourceNumber <= loopRemaining; sourceNumber = sourceNumber + 1) {
        loopRemaining = IRInst__getOperandRecord(nodeInst,sourceNumber);
        laneSelect = *(undefined1 *)(loopIndex + loopRemaining + 0x10);
        (**(code **)(*nodeInst + 0x88))(nodeInst,sourceNumber,loopIndex,4,in_r7,in_r8,loopIndex + loopRemaining);
        (**(code **)(*nodeInst + 0x88))(nodeInst,sourceNumber,targetLane,laneSelect);
      }
    }
    return 0;
  }
  *(uint *)(node + 0x58) = (loopIndex == 3) + 1;
  if (*(int *)(node + 0x60) != 0) {
    *(undefined1 *)(*(int *)(node + 0x60) + loopIndex) = 1;
  }
  ((int (*)())FUN_0018b1bc)(this,node,targetLane,targetLane,loopIndex);
  return 1;
}

/* R300SchedModel__vslot14 @ 0x18b9cc (712 bytes) */
int R300SchedModel__vslot14(this, node)
  int this;
  int node;
{
  int lastLane;
  int destRecord;
  int operandRecord2;
  undefined1 laneSelect;
  uint instFlags;
  undefined1 *loopIndex2;
  int flagBit0Result;
  int operandRecord;
  undefined4 in_r7;
  undefined4 in_r8;
  int loopIndex;
  int a2;
  int opcodeCategory;
  int resultLane;
  int *nodeInst;
  
  nodeInst = *(int **)(node + 0x38);
  if ((nodeInst[0x20] == 0) || (flagBit0Result = RegKind__flagBit0(nodeInst[0x26]), flagBit0Result == 0)) {
    instFlags = nodeInst[5];
  }
  else {
    instFlags = nodeInst[5];
    if ((instFlags & 2) == 0) {
      (**(code **)(*nodeInst + 0x50))(nodeInst);
      instFlags = nodeInst[5];
    }
  }
  if (((instFlags & 2) == 0) && (flagBit0Result = (**(code **)(*nodeInst + 0x5c))(nodeInst), flagBit0Result == 0)) {
    (**(code **)(*nodeInst + 0x28))(nodeInst);
  }
  opcodeCategory = *(int *)(PTR_DAT_001e913c + *(int *)(nodeInst[0x22] + 8) * 0x38 + 0x34);
  destRecord = IRInst__getOperandRecord(nodeInst,0);
  if (*(char *)(destRecord + 0x13) == '\0') {
    if ((opcodeCategory == 0) && (destRecord = IRInst__countWrittenComponents(nodeInst), 1 < destRecord)) {
      operandRecord2 = IRInst__getOperandRecord(nodeInst,0);
      a2 = 3;
      resultLane = SelectWord__firstUnwrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
      lastLane = 3;
    }
    else {
      resultLane = *(int *)(this + 0x68);
      *(int *)(this + 0x68) = resultLane + 1;
      if (resultLane + 1 < 3) {
        a2 = 3;
        lastLane = 3;
      }
      else {
        a2 = 3;
        *(undefined4 *)(this + 0x68) = 0;
        lastLane = 3;
      }
    }
  }
  else if (opcodeCategory == 5) {
    a2 = 0;
    resultLane = 3;
    lastLane = 2;
  }
  else {
    operandRecord2 = IRInst__getOperandRecord(nodeInst,0);
    resultLane = 3;
    a2 = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
    lastLane = a2;
  }
  loopIndex2 = (undefined1 *)((int)nodeInst + a2 + 0xc);
  loopIndex = a2;
  do {
    loopIndex = loopIndex + 1;
    loopIndex2[0x90] = 1;
    *loopIndex2 = 0;
    loopIndex2 = loopIndex2 + 1;
  } while (loopIndex <= lastLane);
  *(undefined1 *)((int)nodeInst + resultLane + 0xc) = 1;
  *(undefined1 *)((int)nodeInst + resultLane + 0x9c) = 0;
  *(uint *)(node + 0x58) = (resultLane == 3) + 1;
  if (((opcodeCategory - 1U < 2) || (opcodeCategory == 5)) || (loopIndex = 1, a2 != lastLane)) {
    *(undefined4 *)(node + 0x5c) = 0;
  }
  else {
    for (; operandRecord = (**(code **)(*nodeInst + 0x14))(nodeInst), loopIndex <= operandRecord; loopIndex = loopIndex + 1) {
      operandRecord = IRInst__getOperandRecord(nodeInst,loopIndex);
      laneSelect = *(undefined1 *)(a2 + operandRecord + 0x10);
      (**(code **)(*nodeInst + 0x88))(nodeInst,loopIndex,a2,4,in_r7,in_r8,a2 + operandRecord);
      (**(code **)(*nodeInst + 0x88))(nodeInst,loopIndex,resultLane,laneSelect);
    }
    if ((opcodeCategory == 0) && (opcodeCategory = IRInst__countWrittenComponents(nodeInst), 1 < opcodeCategory)) {
      *(undefined4 *)(node + 0x5c) = 0;
    }
  }
  return ((int (*)())FUN_0018b1bc)(this,node,a2,lastLane,resultLane);
}

/* FUN_0018bc94 @ 0x18bc94 (1332 bytes) */
int FUN_0018bc94(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  int *loopIndex5;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *loopIndex6;
  int loopIndex2;
  int *loopIndex7;
  int *loopIndex8;
  int iVar10;
  int *loopIndex3;
  int loopIndex;
  int *piVar13;
  int *loopIndex4;
  int *piVar15;
  int local_68 [10];
  
  if (param_2 < 3) {
    loopIndex2 = param_2 * 4 + param_1;
    if (*(int *)(loopIndex2 + 0x30) == 0) {
      loopIndex2 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
      if (loopIndex2 != 0) goto LAB_0018c1b0;
    }
    else {
      loopIndex3 = param_3 + 3;
      loopIndex7 = param_4 + 3;
      loopIndex6 = param_4;
      loopIndex8 = param_3;
      do {
        loopIndex4 = (int *)*loopIndex8;
        if ((((loopIndex4 == (int *)0x0) || (loopIndex4 == *(int **)(loopIndex2 + 0x18))) ||
            ((((*(int **)(loopIndex2 + 0x18) != (int *)0x0 &&
               ((loopIndex4[0x20] != 0 && (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)))) &&
              ((loopIndex4[5] & 2U) == 0)) &&
             ((((((iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0 &&
                  (loopIndex4 = *(int **)(loopIndex2 + 0x18), loopIndex4[0x20] != 0)) &&
                 (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)) &&
                (((loopIndex4[5] & 2U) == 0 &&
                 (iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0)))) &&
               ((*(uint *)(*loopIndex8 + 0x14) & 0x40) != 0)) &&
              (((*(uint *)(*(int *)(loopIndex2 + 0x18) + 0x14) & 0x40) != 0 &&
               (*(int *)(*loopIndex8 + 0x94) == *(int *)(*(int *)(loopIndex2 + 0x18) + 0x94))))))))) &&
           (((loopIndex4 = (int *)*loopIndex3, loopIndex4 == (int *)0x0 ||
             (loopIndex4 == *(int **)(loopIndex2 + 0x24))) ||
            (((((*(int **)(loopIndex2 + 0x24) != (int *)0x0 && (loopIndex4[0x20] != 0)) &&
               (iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0)) &&
              ((((loopIndex4[5] & 2U) == 0 &&
                (iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0)) &&
               (loopIndex4 = *(int **)(loopIndex2 + 0x24), loopIndex4[0x20] != 0)))) &&
             (((iVar3 = RegKind__flagBit0(loopIndex4[0x26]), iVar3 != 0 && ((loopIndex4[5] & 2U) == 0)) &&
              ((iVar3 = (**(code **)(*loopIndex4 + 0x50))(loopIndex4), iVar3 == 0 &&
               ((((*(uint *)(*loopIndex3 + 0x14) & 0x40) != 0 &&
                 ((*(uint *)(*(int *)(loopIndex2 + 0x24) + 0x14) & 0x40) != 0)) &&
                (*(int *)(*loopIndex3 + 0x94) == *(int *)(*(int *)(loopIndex2 + 0x24) + 0x94))))))))))))) {
          *loopIndex8 = *(int *)(loopIndex2 + 0x18);
          *loopIndex3 = *(int *)(loopIndex2 + 0x24);
          *loopIndex6 = *loopIndex6 + 1;
          *loopIndex7 = *loopIndex7 + 1;
          iVar3 = ((int (*)())FUN_0018bc94)(param_1,param_2 + 1,param_3,param_4);
          if (iVar3 != 0) goto LAB_0018c1b0;
          *loopIndex6 = *loopIndex6 + -1;
          iVar3 = *loopIndex7 + -1;
          *loopIndex7 = iVar3;
          if (*loopIndex6 == 0) {
            *loopIndex8 = 0;
            iVar3 = *loopIndex7;
          }
          if (iVar3 == 0) {
            *loopIndex3 = 0;
          }
        }
        loopIndex8 = loopIndex8 + 1;
        loopIndex3 = loopIndex3 + 1;
        loopIndex7 = loopIndex7 + 1;
        loopIndex6 = loopIndex6 + 1;
      } while (param_3 + 3 != loopIndex8);
    }
LAB_0018bf4c:
    uVar4 = 0;
  }
  else {
    loopIndex7 = param_4 + 3;
    loopIndex4 = local_68;
    loopIndex6 = loopIndex7;
    loopIndex8 = param_4;
    loopIndex3 = loopIndex4;
    do {
      loopIndex2 = *loopIndex8;
      loopIndex8 = loopIndex8 + 1;
      *loopIndex3 = loopIndex2;
      loopIndex2 = *loopIndex6;
      loopIndex6 = loopIndex6 + 1;
      loopIndex3[3] = loopIndex2;
      loopIndex3 = loopIndex3 + 1;
    } while (loopIndex3 != local_68 + 3);
    loopIndex2 = 0;
    iVar3 = param_1 + 0x10;
    do {
      piVar13 = (int *)(iVar3 + 8);
      iVar10 = 0;
      loopIndex6 = param_4;
      loopIndex8 = param_3;
      do {
        if ((*(int *)(param_1 + 0x30) == 0) && (*piVar13 != 0)) {
          loopIndex = 0;
          loopIndex5 = loopIndex8;
          do {
            if (((int *)*loopIndex5 != (int *)0x0) &&
               ((piVar15 = (int *)*piVar13, (int *)*loopIndex5 == piVar15 ||
                ((((piVar15 != (int *)0x0 && (piVar15[0x20] != 0)) &&
                  (iVar5 = RegKind__flagBit0(piVar15[0x26]), iVar5 != 0)) &&
                 ((((((piVar15[5] & 2U) == 0 &&
                     (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                    ((piVar15 = (int *)*loopIndex5, piVar15[0x20] != 0 &&
                     ((iVar5 = RegKind__flagBit0(piVar15[0x26]), iVar5 != 0 && ((piVar15[5] & 2U) == 0)))
                     ))) && (iVar5 = (**(code **)(*piVar15 + 0x50))(piVar15), iVar5 == 0)) &&
                  ((((*(uint *)(*piVar13 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(*loopIndex5 + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar13 + 0x94) == *(int *)(*loopIndex5 + 0x94))))))))))) {
              loopIndex6[loopIndex] = loopIndex6[loopIndex] + 1;
              goto LAB_0018c0d4;
            }
            bVar1 = loopIndex != 2;
            loopIndex5 = loopIndex5 + 1;
            loopIndex = loopIndex + 1;
          } while (bVar1);
          loopIndex = 0;
          loopIndex5 = loopIndex8;
          while (*loopIndex5 != 0) {
            bVar1 = loopIndex == 2;
            loopIndex5 = loopIndex5 + 1;
            loopIndex = loopIndex + 1;
            if (bVar1) {
              loopIndex6 = param_3 + 3;
              do {
                iVar3 = *loopIndex4;
                *param_4 = iVar3;
                loopIndex2 = loopIndex4[3];
                *loopIndex7 = loopIndex2;
                if (iVar3 == 0) {
                  *param_3 = 0;
                }
                if (loopIndex2 == 0) {
                  *loopIndex6 = 0;
                }
                loopIndex4 = loopIndex4 + 1;
                param_4 = param_4 + 1;
                loopIndex7 = loopIndex7 + 1;
                loopIndex6 = loopIndex6 + 1;
                param_3 = param_3 + 1;
              } while (loopIndex3 != loopIndex4);
              goto LAB_0018bf4c;
            }
          }
          loopIndex8[loopIndex] = *piVar13;
          loopIndex6[loopIndex] = loopIndex6[loopIndex] + 1;
        }
LAB_0018c0d4:
        bVar1 = iVar10 != 0xc;
        piVar13 = piVar13 + 3;
        loopIndex6 = loopIndex6 + 3;
        loopIndex8 = loopIndex8 + 3;
        iVar10 = iVar10 + 0xc;
      } while (bVar1);
      bVar1 = loopIndex2 != 2;
      iVar3 = iVar3 + 4;
      param_1 = param_1 + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
LAB_0018c1b0:
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_0018c1c8 @ 0x18c1c8 (1440 bytes) */
int FUN_0018c1c8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *loopIndex;
  int callResult;
  int *loopIndex2;
  int *loopIndex3;
  int *piVar5;
  int *loopRemaining;
  int *piVar7;
  int local_58 [3];
  int local_4c [9];
  
  piVar5 = param_2 + 3;
  loopIndex3 = local_58;
  loopIndex = piVar5;
  loopIndex2 = param_2;
  do {
    *loopIndex3 = 0;
    loopIndex3[3] = 0;
    loopIndex3 = loopIndex3 + 1;
    *loopIndex2 = 0;
    *loopIndex = 0;
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + 1;
  } while (loopIndex3 != local_4c);
  if (*param_1 != 0) {
    *param_2 = *param_1;
    local_58[0] = local_58[0] + 1;
  }
  if (param_1[1] != 0) {
    *piVar5 = param_1[1];
    local_4c[0] = local_4c[0] + 1;
  }
  loopIndex = param_1;
  loopIndex2 = param_1;
  do {
    loopIndex3 = param_1;
    loopRemaining = param_1;
    if ((param_1[2] == 0) || (param_1[3] == 0)) {
LAB_0018c498:
      do {
        if ((param_1[4] == 0) || (param_1[5] == 0)) {
LAB_0018c6a0:
          callResult = ((int (*)())FUN_0018bc94)(param_1,0,param_2,local_58);
          if (callResult != 0) {
            return 1;
          }
          local_4c[0] = local_4c[0] + -1;
          if (local_4c[0] == 0) {
            *piVar5 = 0;
          }
          local_4c[1] = local_4c[1] + -1;
          if (local_4c[1] == 0) {
            param_2[4] = 0;
          }
        }
        else {
          piVar7 = (int *)*piVar5;
          if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)loopRemaining[5])) ||
              ((((((int *)loopRemaining[5] != (int *)0x0 && (piVar7[0x20] != 0)) &&
                 (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
                (((piVar7[5] & 2U) == 0 &&
                 (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)))) &&
               ((piVar7 = (int *)loopRemaining[5], piVar7[0x20] != 0 &&
                (((callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0 && ((piVar7[5] & 2U) == 0)) &&
                 ((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
                  ((((*(uint *)(*piVar5 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(loopRemaining[5] + 0x14) & 0x40) != 0)) &&
                   (*(int *)(*piVar5 + 0x94) == *(int *)(loopRemaining[5] + 0x94))))))))))))) &&
             (((piVar7 = (int *)param_2[4], piVar7 == (int *)0x0 || (piVar7 == (int *)loopIndex3[4])) ||
              (((int *)loopIndex3[4] != (int *)0x0 &&
               ((((piVar7[0x20] != 0 && (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
                 (((piVar7[5] & 2U) == 0 &&
                  (((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
                    (piVar7 = (int *)loopIndex3[4], piVar7[0x20] != 0)) &&
                   (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)))))) &&
                ((((piVar7[5] & 2U) == 0 &&
                  (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)) &&
                 (((*(uint *)(param_2[4] + 0x14) & 0x40) != 0 &&
                  (((*(uint *)(loopIndex3[4] + 0x14) & 0x40) != 0 &&
                   (*(int *)(param_2[4] + 0x94) == *(int *)(loopIndex3[4] + 0x94))))))))))))))) {
            *piVar5 = loopRemaining[5];
            local_4c[1] = local_4c[1] + 1;
            local_4c[0] = local_4c[0] + 1;
            param_2[4] = loopIndex3[4];
            goto LAB_0018c6a0;
          }
        }
        loopRemaining = loopRemaining + -1;
        loopIndex3 = loopIndex3 + 1;
      } while (param_1 + -2 != loopRemaining);
      local_58[0] = local_58[0] + -1;
      if (local_58[0] == 0) {
        *param_2 = 0;
      }
      local_58[1] = local_58[1] + -1;
      if (local_58[1] == 0) {
        param_2[1] = 0;
      }
    }
    else {
      piVar7 = (int *)*param_2;
      if ((((piVar7 == (int *)0x0) || (piVar7 == (int *)loopIndex2[3])) ||
          (((((((int *)loopIndex2[3] != (int *)0x0 && (piVar7[0x20] != 0)) &&
              (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
             (((piVar7[5] & 2U) == 0 && (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0))
             )) && (piVar7 = (int *)loopIndex2[3], piVar7[0x20] != 0)) &&
           ((((callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0 && ((piVar7[5] & 2U) == 0)) &&
             (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0)) &&
            ((((*(uint *)(*param_2 + 0x14) & 0x40) != 0 &&
              ((*(uint *)(loopIndex2[3] + 0x14) & 0x40) != 0)) &&
             (*(int *)(*param_2 + 0x94) == *(int *)(loopIndex2[3] + 0x94))))))))) &&
         (((piVar7 = (int *)param_2[1], piVar7 == (int *)0x0 || (piVar7 == (int *)loopIndex[2])) ||
          (((((int *)loopIndex[2] != (int *)0x0 &&
             ((piVar7[0x20] != 0 && (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)))) &&
            ((piVar7[5] & 2U) == 0)) &&
           (((((callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0 &&
               (piVar7 = (int *)loopIndex[2], piVar7[0x20] != 0)) &&
              (callResult = RegKind__flagBit0(piVar7[0x26]), callResult != 0)) &&
             (((piVar7[5] & 2U) == 0 && (callResult = (**(code **)(*piVar7 + 0x50))(piVar7), callResult == 0))
             )) && (((*(uint *)(param_2[1] + 0x14) & 0x40) != 0 &&
                    (((*(uint *)(loopIndex[2] + 0x14) & 0x40) != 0 &&
                     (*(int *)(param_2[1] + 0x94) == *(int *)(loopIndex[2] + 0x94))))))))))))) {
        *param_2 = loopIndex2[3];
        local_58[0] = local_58[0] + 1;
        local_58[1] = local_58[1] + 1;
        param_2[1] = loopIndex[2];
        goto LAB_0018c498;
      }
    }
    loopIndex2 = loopIndex2 + -1;
    loopIndex = loopIndex + 1;
    if (param_1 + -2 == loopIndex2) {
      return 0;
    }
  } while( true );
}

/* PackState__countFreeSlots @ 0x18c768 (140 bytes) */
int PackState__countFreeSlots(state, freeCounts)
  undefined4 state;
  int *freeCounts;
{
  int callResult;
  int *loopIndex;
  int local_38 [3];
  int local_2c [9];
  
  callResult = ((int (*)())FUN_0018c1c8)(state,local_38);
  freeCounts[1] = 0;
  *freeCounts = 0;
  if (callResult != 0) {
    loopIndex = local_38;
    do {
      if (*loopIndex == 0) {
        *freeCounts = *freeCounts + 1;
      }
      if (loopIndex[3] == 0) {
        freeCounts[1] = freeCounts[1] + 1;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex != local_2c);
  }
  return callResult;
}

/* FUN_0018c7f4 @ 0x18c7f4 (396 bytes) */
int FUN_0018c7f4(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int loopIndex;
  int *loopIndex2;
  
  loopIndex2 = (int *)(param_3 * 0xc + param_1 + 0x18);
  loopIndex = 0;
  while (((int *)*loopIndex2 == (int *)0x0 ||
         ((param_2 != (int *)*loopIndex2 &&
          (((((param_2 == (int *)0x0 || (param_2[0x20] == 0)) ||
             (iVar2 = RegKind__flagBit0(param_2[0x26]), iVar2 == 0)) ||
            (((((param_2[5] & 2U) != 0 ||
               (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)) ||
              ((piVar3 = (int *)*loopIndex2, piVar3[0x20] == 0 ||
               ((iVar2 = RegKind__flagBit0(piVar3[0x26]), iVar2 == 0 || ((piVar3[5] & 2U) != 0)))))) ||
             (iVar2 = (**(code **)(*piVar3 + 0x50))(piVar3), iVar2 != 0)))) ||
           ((((param_2[5] & 0x40U) == 0 || ((*(uint *)(*loopIndex2 + 0x14) & 0x40) == 0)) ||
            (param_2[0x25] != *(int *)(*loopIndex2 + 0x94)))))))))) {
    bVar1 = loopIndex == 2;
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      loopIndex = 0;
      loopIndex2 = (int *)(param_3 * 0xc + param_1 + 0x18);
      do {
        if (*loopIndex2 == 0) {
          *(int **)((param_3 * 3 + loopIndex) * 4 + param_1 + 0x18) = param_2;
          return 1;
        }
        bVar1 = loopIndex != 2;
        loopIndex2 = loopIndex2 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      return 0;
    }
  }
  return 1;
}

/* FUN_0018c980 @ 0x18c980 (1112 bytes) */
int FUN_0018c980(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  bool bVar1;
  int loopIndex;
  undefined4 uVar3;
  int loopIndex2;
  int iVar5;
  int iVar6;
  int *loopIndex3;
  int *piVar8;
  
  loopIndex2 = 0;
  iVar6 = param_1;
  while (*(int *)(iVar6 + 0x30) != 0) {
    loopIndex3 = *(int **)(iVar6 + 0x18);
    if (((param_2 == loopIndex3) ||
        ((((((loopIndex3 != (int *)0x0 && (param_2 != (int *)0x0)) && (loopIndex3[0x20] != 0)) &&
           ((loopIndex = RegKind__flagBit0(loopIndex3[0x26]), loopIndex != 0 && ((loopIndex3[5] & 2U) == 0)))) &&
          ((((loopIndex = (**(code **)(*loopIndex3 + 0x50))(loopIndex3), loopIndex == 0 &&
             ((param_2[0x20] != 0 && (loopIndex = RegKind__flagBit0(param_2[0x26]), loopIndex != 0)))) &&
            ((param_2[5] & 2U) == 0)) &&
           (((loopIndex = (**(code **)(*param_2 + 0x50))(param_2), loopIndex == 0 &&
             ((*(uint *)(*(int *)(iVar6 + 0x18) + 0x14) & 0x40) != 0)) &&
            ((param_2[5] & 0x40U) != 0)))))) &&
         (*(int *)(*(int *)(iVar6 + 0x18) + 0x94) == param_2[0x25])))) &&
       ((loopIndex3 = *(int **)(iVar6 + 0x24), param_3 == loopIndex3 ||
        (((((loopIndex3 != (int *)0x0 && (param_3 != (int *)0x0)) &&
           ((loopIndex3[0x20] != 0 &&
            ((loopIndex = RegKind__flagBit0(loopIndex3[0x26]), loopIndex != 0 && ((loopIndex3[5] & 2U) == 0)))))) &&
          (loopIndex = (**(code **)(*loopIndex3 + 0x50))(loopIndex3), loopIndex == 0)) &&
         (((((param_3[0x20] != 0 && (loopIndex = RegKind__flagBit0(param_3[0x26]), loopIndex != 0)) &&
            ((param_3[5] & 2U) == 0)) &&
           ((loopIndex = (**(code **)(*param_3 + 0x50))(param_3), loopIndex == 0 &&
            ((*(uint *)(*(int *)(iVar6 + 0x24) + 0x14) & 0x40) != 0)))) &&
          (((param_3[5] & 0x40U) != 0 && (*(int *)(*(int *)(iVar6 + 0x24) + 0x94) == param_3[0x25]))
          )))))))) goto LAB_0018cdb8;
    bVar1 = loopIndex2 == 2;
    iVar6 = iVar6 + 4;
    loopIndex2 = loopIndex2 + 1;
    if (bVar1) goto LAB_0018cdb8;
  }
  loopIndex = loopIndex2 + 1;
  iVar6 = loopIndex2 * 4 + param_1;
  iVar5 = *(int *)(iVar6 + 0x18);
  loopIndex2 = *(int *)(iVar6 + 0x24);
  *(undefined4 *)(iVar6 + 0x30) = 1;
  *(int **)(iVar6 + 0x18) = param_2;
  *(int **)(iVar6 + 0x24) = param_3;
  if (loopIndex < 3) {
    loopIndex3 = (int *)(loopIndex * 4 + param_1 + 0x18);
    do {
      piVar8 = (int *)*loopIndex3;
      if ((piVar8 != (int *)0x0) &&
         ((param_2 == piVar8 ||
          ((((param_2 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            (iVar6 = RegKind__flagBit0(piVar8[0x26]), iVar6 != 0)) &&
           (((((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             && ((param_2[0x20] != 0 &&
                 ((iVar6 = RegKind__flagBit0(param_2[0x26]), iVar6 != 0 && ((param_2[5] & 2U) == 0))))))
            && ((iVar6 = (**(code **)(*param_2 + 0x50))(param_2), iVar6 == 0 &&
                ((((*(uint *)(*loopIndex3 + 0x14) & 0x40) != 0 && ((param_2[5] & 0x40U) != 0)) &&
                 (*(int *)(*loopIndex3 + 0x94) == param_2[0x25])))))))))))) {
        *loopIndex3 = 0;
      }
      piVar8 = (int *)loopIndex3[3];
      if ((piVar8 != (int *)0x0) &&
         ((param_3 == piVar8 ||
          ((((param_3 != (int *)0x0 && (piVar8[0x20] != 0)) &&
            ((iVar6 = RegKind__flagBit0(piVar8[0x26]), iVar6 != 0 &&
             (((piVar8[5] & 2U) == 0 && (iVar6 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar6 == 0))
             )))) && (((param_3[0x20] != 0 &&
                       ((((iVar6 = RegKind__flagBit0(param_3[0x26]), iVar6 != 0 &&
                          ((param_3[5] & 2U) == 0)) &&
                         (iVar6 = (**(code **)(*param_3 + 0x50))(param_3), iVar6 == 0)) &&
                        (((*(uint *)(loopIndex3[3] + 0x14) & 0x40) != 0 && ((param_3[5] & 0x40U) != 0)))
                        ))) && (*(int *)(loopIndex3[3] + 0x94) == param_3[0x25])))))))) {
        loopIndex3[3] = 0;
      }
      bVar1 = loopIndex != 2;
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  if (((iVar5 == 0) || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,iVar5,0), iVar6 != 0)) &&
     ((loopIndex2 == 0 || (iVar6 = ((int (*)())FUN_0018c7f4)(param_1,loopIndex2,1), iVar6 != 0)))) {
LAB_0018cdb8:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0018cdd8 @ 0x18cdd8 (1456 bytes) */
int FUN_0018cdd8(sourceState, sourceA, sourceB, slot)
  int sourceState;
  int *sourceA;
  int *sourceB;
  int slot;
{
  int *pairEntry;
  int *singleSource;
  int regTestResult;
  undefined4 result;
  int iVar3;
  int *pairSecond;
  int pairOffset;
  int *pairFirst;
  
  pairOffset = slot * 8;
  iVar3 = pairOffset + sourceState;
  pairFirst = *(int **)(iVar3 + 8);
  if ((pairFirst == (int *)0x0) || (pairSecond = *(int **)(iVar3 + 0xc), pairSecond == (int *)0x0)) {
    iVar3 = slot * 4;
    singleSource = *(int **)(iVar3 + sourceState);
    if ((((singleSource == (int *)0x0) || (singleSource == sourceA)) ||
        (((((((sourceA != (int *)0x0 && (singleSource[0x20] != 0)) &&
             (regTestResult = RegKind__flagBit0(singleSource[0x26]), regTestResult != 0)) &&
            ((((singleSource[5] & 2U) == 0 && (regTestResult = (**(code **)(*singleSource + 0x50))(singleSource), regTestResult == 0))
             && (sourceA[0x20] != 0)))) &&
           ((regTestResult = RegKind__flagBit0(sourceA[0x26]), regTestResult != 0 && ((sourceA[5] & 2U) == 0)))) &&
          ((regTestResult = (**(code **)(*sourceA + 0x50))(sourceA), regTestResult == 0 &&
           ((((*(uint *)(*(int *)(iVar3 + sourceState) + 0x14) & 0x40) != 0 &&
             ((sourceA[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar3 + sourceState) + 0x94) == sourceA[0x25])))))) ||
         ((singleSource = *(int **)(iVar3 + sourceState), sourceB == singleSource ||
          ((((singleSource != (int *)0x0 && (sourceB != (int *)0x0)) &&
            (((singleSource[0x20] != 0 &&
              ((regTestResult = RegKind__flagBit0(singleSource[0x26]), regTestResult != 0 && ((singleSource[5] & 2U) == 0)))) &&
             (regTestResult = (**(code **)(*singleSource + 0x50))(singleSource), regTestResult == 0)))) &&
           (((((sourceB[0x20] != 0 && (regTestResult = RegKind__flagBit0(sourceB[0x26]), regTestResult != 0)) &&
              ((sourceB[5] & 2U) == 0)) &&
             ((regTestResult = (**(code **)(*sourceB + 0x50))(sourceB), regTestResult == 0 &&
              ((*(uint *)(*(int *)(iVar3 + sourceState) + 0x14) & 0x40) != 0)))) &&
            (((sourceB[5] & 0x40U) != 0 &&
             (*(int *)(*(int *)(iVar3 + sourceState) + 0x94) == sourceB[0x25])))))))))))) &&
       ((iVar3 = ((int (*)())FUN_0018c7f4)(sourceState,sourceA,slot), iVar3 != 0 &&
        (iVar3 = ((int (*)())FUN_0018c7f4)(sourceState,sourceB,slot), iVar3 != 0)))) {
      *(int **)(pairOffset + sourceState + 0xc) = sourceB;
      *(int **)(pairOffset + sourceState + 8) = sourceA;
      return 1;
    }
LAB_0018d170:
    result = 0;
  }
  else {
    if (pairFirst == sourceA) {
LAB_0018cee8:
      if ((sourceB != pairSecond) &&
         ((((pairSecond == (int *)0x0 || (sourceB == (int *)0x0)) ||
           ((pairSecond[0x20] == 0 ||
            ((regTestResult = RegKind__flagBit0(pairSecond[0x26]), regTestResult == 0 || ((pairSecond[5] & 2U) != 0)))))) ||
          (((regTestResult = (**(code **)(*pairSecond + 0x50))(pairSecond), regTestResult != 0 ||
            ((((sourceB[0x20] == 0 || (regTestResult = RegKind__flagBit0(sourceB[0x26]), regTestResult == 0)) ||
              ((sourceB[5] & 2U) != 0)) ||
             ((regTestResult = (**(code **)(*sourceB + 0x50))(sourceB), regTestResult != 0 ||
              ((*(uint *)(*(int *)(iVar3 + 0xc) + 0x14) & 0x40) == 0)))))) ||
           (((sourceB[5] & 0x40U) == 0 || (*(int *)(*(int *)(iVar3 + 0xc) + 0x94) != sourceB[0x25]))
           )))))) goto LAB_0018cfbc;
    }
    else {
      if (((((sourceA != (int *)0x0) && (pairFirst[0x20] != 0)) &&
           (regTestResult = RegKind__flagBit0(pairFirst[0x26]), regTestResult != 0)) &&
          ((((pairFirst[5] & 2U) == 0 && (regTestResult = (**(code **)(*pairFirst + 0x50))(pairFirst), regTestResult == 0))
           && ((sourceA[0x20] != 0 &&
               ((regTestResult = RegKind__flagBit0(sourceA[0x26]), regTestResult != 0 && ((sourceA[5] & 2U) == 0))))))))
         && ((regTestResult = (**(code **)(*sourceA + 0x50))(sourceA), regTestResult == 0 &&
             ((((*(uint *)(*(int *)(iVar3 + 8) + 0x14) & 0x40) != 0 && ((sourceA[5] & 0x40U) != 0))
              && (*(int *)(*(int *)(iVar3 + 8) + 0x94) == sourceA[0x25])))))) {
        pairSecond = *(int **)(iVar3 + 0xc);
        goto LAB_0018cee8;
      }
LAB_0018cfbc:
      pairOffset = pairOffset + sourceState;
      pairEntry = *(int **)(pairOffset + 8);
      if (((sourceB != pairEntry) &&
          (((((pairEntry == (int *)0x0 || (sourceB == (int *)0x0)) ||
             ((pairEntry[0x20] == 0 ||
              (((iVar3 = RegKind__flagBit0(pairEntry[0x26]), iVar3 == 0 || ((pairEntry[5] & 2U) != 0)) ||
               (iVar3 = (**(code **)(*pairEntry + 0x50))(pairEntry), iVar3 != 0)))))) ||
            ((sourceB[0x20] == 0 || (iVar3 = RegKind__flagBit0(sourceB[0x26]), iVar3 == 0)))) ||
           (((sourceB[5] & 2U) != 0 ||
            (((iVar3 = (**(code **)(*sourceB + 0x50))(sourceB), iVar3 != 0 ||
              ((*(uint *)(*(int *)(pairOffset + 8) + 0x14) & 0x40) == 0)) ||
             (((sourceB[5] & 0x40U) == 0 || (*(int *)(*(int *)(pairOffset + 8) + 0x94) != sourceB[0x25]))
             )))))))) ||
         ((pairEntry = *(int **)(pairOffset + 0xc), sourceA != pairEntry &&
          (((((pairEntry == (int *)0x0 || (sourceA == (int *)0x0)) || (pairEntry[0x20] == 0)) ||
            ((iVar3 = RegKind__flagBit0(pairEntry[0x26]), iVar3 == 0 || ((pairEntry[5] & 2U) != 0)))) ||
           ((((iVar3 = (**(code **)(*pairEntry + 0x50))(pairEntry), iVar3 != 0 ||
              ((sourceA[0x20] == 0 || (iVar3 = RegKind__flagBit0(sourceA[0x26]), iVar3 == 0)))) ||
             ((sourceA[5] & 2U) != 0)) ||
            ((((iVar3 = (**(code **)(*sourceA + 0x50))(sourceA), iVar3 != 0 ||
               ((*(uint *)(*(int *)(pairOffset + 0xc) + 0x14) & 0x40) == 0)) ||
              ((sourceA[5] & 0x40U) == 0)) ||
             (*(int *)(*(int *)(pairOffset + 0xc) + 0x94) != sourceA[0x25])))))))))) goto LAB_0018d170;
    }
    result = 1;
  }
  return result;
}

/* FUN_0018d388 @ 0x18d388 (300 bytes) */
int FUN_0018d388(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int callResult;
  int *piVar3;
  
  iVar1 = param_3 * 4;
  piVar3 = *(int **)(iVar1 + param_1);
  if (piVar3 == (int *)0x0) {
    callResult = ((int (*)())FUN_0018c7f4)(param_1,param_2,param_3);
    if (callResult != 0) {
      *(int **)(iVar1 + param_1) = param_2;
      return 1;
    }
  }
  else if ((piVar3 == param_2) ||
          (((((param_2 != (int *)0x0 && (piVar3[0x20] != 0)) &&
             (callResult = RegKind__flagBit0(piVar3[0x26]), callResult != 0)) &&
            (((((piVar3[5] & 2U) == 0 && (callResult = (**(code **)(*piVar3 + 0x50))(piVar3), callResult == 0)
               ) && ((param_2[0x20] != 0 &&
                     ((callResult = RegKind__flagBit0(param_2[0x26]), callResult != 0 && ((param_2[5] & 2U) == 0)))
                     ))) && (callResult = (**(code **)(*param_2 + 0x50))(param_2), callResult == 0)))) &&
           ((((*(uint *)(*(int *)(iVar1 + param_1) + 0x14) & 0x40) != 0 &&
             ((param_2[5] & 0x40U) != 0)) &&
            (*(int *)(*(int *)(iVar1 + param_1) + 0x94) == param_2[0x25])))))) {
    return 1;
  }
  return 0;
}

/* FUN_0018d4b4 @ 0x18d4b4 (1428 bytes) */
int FUN_0018d4b4(inst, param_2, param_3, param_4, compiler)
  int *inst;
  int *param_2;
  int *param_3;
  int *param_4;
  int compiler;
{
  int *laneMask;
  int operandIndex2;
  int operandIndex;
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 operandVReg;
  int *operandVReg2;
  int iVar6;
  int *a0;
  int *a3;
  int a4;
  undefined4 in_r8;
  int iVar7;
  uint uVar8;
  int *inst1;
  undefined8 operandVReg3;
  int local_68;
  float local_64;
  uint local_48;
  uint local_44;
  uint local_40 [5];
  
  iVar2 = *(int *)(inst[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) ||
     (operandIndex2 = 1, laneMask = param_3, a3 = param_4, a4 = compiler, iVar2 == 0xa1)) {
    piVar3 = (int *)IRInst__getOperandSource(inst,1);
    iVar2 = (**(code **)(*piVar3 + 0x5c))(piVar3);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x12) == '\0')) {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*inst + 0x14))(inst), operandIndex2 <= iVar2; operandIndex2 = operandIndex2 + 1) {
      operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIndex2);
      iVar2 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if (iVar2 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg2,1);
        (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      }
      iVar6 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
      if (iVar6 != 0) {
        if (((operandVReg2[0x56] != 0) && (inst[0x56] != 0)) && (inst[0x56] != operandVReg2[0x56])) {
          DList__unlink(operandVReg2);
          laneMask = operandVReg2;
          Block__insertInstAfter(inst[0x56],inst[1],operandVReg2);
        }
        iVar6 = *(int *)(operandVReg2[0x22] + 8);
        if (iVar2 == 0) {
          iVar2 = IRInst__getOperandRecord(inst,operandIndex2);
          SelectWord__readMask(&local_44,*(undefined4 *)(iVar2 + 0x10));
          uVar8 = local_44;
        }
        else {
          operandVReg = IRInst__getOperandSource(inst,operandIndex2);
          iVar2 = IRInst__getOperandRecord(operandVReg,1);
          SelectWord__readMask(&local_48,*(undefined4 *)(iVar2 + 0x10));
          uVar8 = local_48;
        }
        if ((uVar8 & 0xffffff00) != 0) {
          if ((-1 < *param_2) && (iVar6 != *param_2)) {
            return 0;
          }
          *param_2 = iVar6;
          iVar2 = (**(code **)(*operandVReg2 + 0x14))(operandVReg2);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            laneMask = (int *)0x0;
            iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,0);
          }
          else {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            laneMask = (int *)IRInst__getOperandSource(operandVReg2,2);
            a3 = (int *)0x0;
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,operandVReg,laneMask,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((uVar8 & 0xff) != 0) {
          if ((-1 < *param_3) && (iVar6 != *param_3)) {
            return 0;
          }
          *param_3 = iVar6;
          iVar2 = (**(code **)(*operandVReg2 + 0x14))(operandVReg2);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            laneMask = (int *)((int)((unsigned char *)0x0) + 1);
            iVar2 = ((int (*)())FUN_0018d388)(param_4,operandVReg,1);
          }
          else {
            operandVReg = IRInst__getOperandSource(operandVReg2,1);
            laneMask = (int *)IRInst__getOperandSource(operandVReg2,2);
            a3 = (int *)((int)((unsigned char *)0x0) + 1);
            iVar2 = ((int (*)())FUN_0018cdd8)(param_4,operandVReg,laneMask,1);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
    }
    for (operandIndex = 1; operandIndex2 = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandIndex2;
        operandIndex = operandIndex + 1) {
      operandVReg2 = (int *)IRInst__getOperandSource(inst,operandIndex);
      iVar7 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
      if (iVar7 == 0) {
        bVar1 = false;
        inst1 = inst;
        a0 = operandVReg2;
        operandIndex2 = operandIndex;
LAB_0018d948:
        iVar6 = (**(code **)(*a0 + 0x5c))(a0);
        if ((iVar6 == 0) && ((bVar1 || (a0[0x26] != 0x33)))) {
          operandIndex2 = IRInst__getOperandRecord(inst1,operandIndex2);
          SelectWord__readMask(local_40,*(undefined4 *)(operandIndex2 + 0x10));
          if ((local_40[0] & 0xffffff00) == 0) {
            if ((local_40[0] & 0xff) == 0) goto LAB_0018da08;
            laneMask = (int *)((int)((unsigned char *)0x0) + 1);
            operandIndex2 = ((int (*)())FUN_0018c7f4)(param_4,a0,1);
          }
          else if ((local_40[0] & 0xff) == 0) {
            laneMask = (int *)0x0;
            operandIndex2 = ((int (*)())FUN_0018c7f4)(param_4,a0,0);
          }
          else {
            operandIndex2 = ((int (*)())FUN_0018c980)(param_4,a0,a0);
            laneMask = a0;
          }
          if (operandIndex2 == 0) {
            return 0;
          }
        }
      }
      else {
        operandVReg3 = IRInst__getOperandSource(operandVReg2,1);
        a0 = (int *)((ulonglong)operandVReg3 >> 0x20);
        (**(code **)(*a0 + 0x60))(a0,(int)operandVReg3,laneMask,a3,a4,in_r8,*(code **)(*a0 + 0x60));
        inst1 = operandVReg2;
        if (a0[0x26] != 0x33) {
LAB_0018d93c:
          bVar1 = false;
          operandIndex2 = 1;
          goto LAB_0018d948;
        }
        iVar7 = IRInst__getOperandRecord(operandVReg2,0);
        laneMask = *(int **)(iVar7 + 0x10);
        a3 = &local_68;
        operandIndex2 = IRInst__getUniformSourceConstant(operandVReg2,1,laneMask,a3);
        if (((operandIndex2 == 0) || (local_68 != 2)) ||
           (operandIndex2 = (**(code **)(**(int **)(compiler + COMP_target) + 0xf0))((double)local_64), operandIndex2 == 0)
           ) {
          iVar7 = IRInst__hasSingleUse(operandVReg2,*(undefined4 *)(compiler + COMP_currentProgram));
          if (iVar7 == 0) {
            bVar1 = true;
            operandIndex2 = 1;
            goto LAB_0018d948;
          }
          goto LAB_0018d93c;
        }
      }
LAB_0018da08: ;
    }
  }
  return 1;
}

/* SchedModel__instructionFitsAlone @ 0x18da48 (116 bytes) */
int SchedModel__instructionFitsAlone(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int callResult;
  undefined4 uVar2;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [8];
  undefined1 auStack_58 [72];
  
  local_64 = 0xffffffff;
  local_68 = 0xffffffff;
  ((int (*)())PackState__reset)(auStack_58);
  callResult = ((int (*)())FUN_0018d4b4)(param_1,&local_68,&local_64,auStack_58,param_2);
  uVar2 = 0;
  if (callResult != 0) {
    uVar2 = ((int (*)())PackState__countFreeSlots)(auStack_58,auStack_60);
  }
  return uVar2;
}

/* R300SchedModel__tryRewriteConsumerSelects @ 0x18dabc (1680 bytes) */
int R300SchedModel__tryRewriteConsumerSelects(this, node)
  int *this;
  int node;
{
  uint undoSelectLength;
  uint undoOperandLength;
  uint undoInstLength;
  uint selectByte;
  uint vectorLength2;
  undefined4 undoSelectWord;
  uint undoSelectIndex;
  uint undoOperandIndex;
  uint undoInstIndex;
  uint *successorVector2;
  undefined4 *undoSelectRef;
  undefined4 *undoSelectSlot;
  undefined4 *undoOperandSlot;
  int *undoOperandRef;
  int *undoInstRef;
  int *consumerInst;
  undefined4 replacementSelect;
  int selectLow;
  int selectHigh;
  int traitsClass;
  int consumerIsFetchOrExport;
  int undoCountOffset2;
  int undoCountOffset;
  int consumerNumSources;
  int undoInst;
  int operandRecord3;
  int operandRecord2;
  int sourceDef;
  bool notLastComponent;
  bool changedAny;
  int inst1;
  int writtenComponentCount;
  undefined4 failedFlag;
  uint vectorLength;
  int *edgeRef;
  int loopIndex;
  int *a0;
  int operandRecord;
  undefined4 *undoInstSlot;
  uint successorCount;
  uint loopIndex2;
  int edgeByteOffset;
  int inst;
  uint loopIndex3;
  int edge;
  undefined4 undoOperandIndex2;
  undefined4 oldSelectWord;
  uint *successorVector;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - undoInstCapacity/undoInstCount/undoInstData/undoInstArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define undoInstCapacity (*(uint *)(local_78_buf + 0x00))
  #define undoInstCount (*(uint *)(local_78_buf + 0x04))
  #define undoInstData (*(int *)(local_78_buf + 0x08))
  #define undoInstArena (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - undoOperandCapacity/undoOperandCount/undoOperandData/undoOperandArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define undoOperandCapacity (*(uint *)(local_68_buf + 0x00))
  #define undoOperandCount (*(uint *)(local_68_buf + 0x04))
  #define undoOperandData (*(int *)(local_68_buf + 0x08))
  #define undoOperandArena (*(undefined4 *)(local_68_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - undoSelectCapacity/undoSelectCount/undoSelectData/undoSelectArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_58_buf [0x10];
  #define undoSelectCapacity (*(uint *)(local_58_buf + 0x00))
  #define undoSelectCount (*(uint *)(local_58_buf + 0x04))
  #define undoSelectData (*(int *)(local_58_buf + 0x08))
  #define undoSelectArena (*(undefined4 *)(local_58_buf + 0x0c))
  
  inst = *(int *)(node + 0x38);
  traitsClass = (**(code **)(*this + 0x30))(this,inst);
  if ((traitsClass == 0) ||
     ((traitsClass = *(int *)(PTR_DAT_001e913c + *(int *)(*(int *)(inst + 0x88) + 8) * 0x38 + 0x34),
      *(int *)(node + 0x60) != 0 && (writtenComponentCount = IRInst__countWrittenComponents(inst), writtenComponentCount != 1)))) {
    failedFlag = 0;
  }
  else {
    operandRecord3 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(operandRecord3 + 0x13) == '\0') {
      if (traitsClass == 0) {
        operandRecord2 = IRInst__getOperandRecord(inst,0);
        selectLow = 3;
        replacementSelect = SelectWord__firstUnwrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
        selectHigh = 3;
      }
      else if (traitsClass - 1U < 2) {
        selectLow = 3;
        replacementSelect = 0;
        selectHigh = 3;
      }
      else {
        selectLow = 3;
        replacementSelect = 0xffffffff;
        selectHigh = 3;
      }
    }
    else if ((traitsClass == 5) && (*(int *)(node + 0x60) == 0)) {
      selectLow = 0;
      replacementSelect = 3;
      selectHigh = 2;
    }
    else {
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      replacementSelect = 3;
      selectLow = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
      selectHigh = selectLow;
    }
    undoInstArena = *(undefined4 *)(this[2] + 0x378);
    undoInstCount = 0;
    undoInstCapacity = 2;
    undoInstData = Arena__alloc(undoInstArena,8);
    undoOperandArena = *(undefined4 *)(this[2] + 0x378);
    undoOperandCount = 0;
    undoOperandCapacity = 2;
    undoOperandData = Arena__alloc(undoOperandArena,8);
    undoSelectArena = *(undefined4 *)(this[2] + 0x378);
    undoSelectCount = 0;
    undoSelectCapacity = 2;
    undoSelectData = Arena__alloc(undoSelectArena,8);
    successorVector = *(uint **)(node + 0x40);
    successorCount = successorVector[1];
    if (0 < (int)successorCount) {
      loopIndex3 = 0;
      loopIndex2 = 1;
      edgeByteOffset = 0;
      do {
        if (loopIndex3 < *successorVector) {
          vectorLength = successorVector[1];
          if (vectorLength <= loopIndex3) {
            _memset(vectorLength * 4 + successorVector[2],0,(loopIndex3 - vectorLength) * 4 + 4);
            successorVector[1] = loopIndex2;
          }
          edgeRef = (int *)(edgeByteOffset + successorVector[2]);
        }
        else {
          edgeRef = (int *)Vector__elementRefGrow(successorVector,loopIndex3);
        }
        edge = *edgeRef;
        if (*(int *)(edge + 8) == 0) {
          successorVector2 = *(uint **)(node + 0x40);
          if (loopIndex3 < *successorVector2) {
            vectorLength2 = successorVector2[1];
            if (vectorLength2 <= loopIndex3) {
              _memset(vectorLength2 * 4 + successorVector2[2],0,(loopIndex3 - vectorLength2) * 4 + 4);
              successorVector2[1] = loopIndex2;
            }
            consumerInst = (int *)(edgeByteOffset + successorVector2[2]);
          }
          else {
            consumerInst = (int *)Vector__elementRefGrow(successorVector2,loopIndex3);
          }
          consumerInst = *(int **)(*(int *)(*consumerInst + 4) + 0x38);
          if ((((consumerInst[5] & 0x200U) == 0) ||
              (loopIndex = IRInst__getOperandSource(consumerInst,consumerInst[0x21]), inst != loopIndex)) &&
             ((loopIndex = (**(code **)(*consumerInst + 0x28))(consumerInst), loopIndex == 0 ||
              ((*(uint *)(*(int *)(this[2] + 0x30c) + 8) & 0x800) != 0)))) {
            loopIndex = (**(code **)(*consumerInst + 0x5c))(consumerInst);
            if (loopIndex != 0) {
              consumerNumSources = (**(code **)(*consumerInst + 0x14))(consumerInst);
              if (1 < consumerNumSources) {
                sourceDef = IRInst__getOperandSource(consumerInst,1);
                loopIndex = IRInst__getOperandSource(consumerInst,2);
                if (sourceDef != loopIndex) goto LAB_0018dda4;
              }
              goto LAB_0018e058;
            }
            loopIndex = *(int *)(consumerInst[0x22] + 8);
            if ((((loopIndex == 0x9e) || (loopIndex == 0xa0)) || (loopIndex == 0x9f)) || (loopIndex == 0xa1))
            goto LAB_0018dda4;
            loopIndex = *(int *)(edge + 0x10);
            if ((loopIndex < 1) || (*(int *)(edge + 0x14) != 0)) {
              a0 = (int *)IRInst__getOperandSource(consumerInst,loopIndex);
              loopIndex = (**(code **)(*a0 + 0x5c))(a0);
              if (loopIndex != 0) {
                loopIndex = *(int *)(edge + 0x10);
                goto LAB_0018de84;
              }
            }
            else {
LAB_0018de84:
              loopIndex = IRInst__getOperandRecord(consumerInst,loopIndex);
              oldSelectWord = *(undefined4 *)(loopIndex + 0x10);
              changedAny = false;
              loopIndex = 0;
              do {
                operandRecord = IRInst__getOperandRecord(consumerInst,*(undefined4 *)(edge + 0x10));
                selectByte = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                if ((selectLow <= (int)selectByte) && ((int)selectByte <= selectHigh)) {
                  (**(code **)(*consumerInst + 0x88))(consumerInst,*(undefined4 *)(edge + 0x10),loopIndex,replacementSelect);
                  changedAny = true;
                }
                undoInstLength = undoInstCount;
                notLastComponent = loopIndex != 3;
                loopIndex = loopIndex + 1;
              } while (notLastComponent);
              if (changedAny) {
                if (undoInstCount < undoInstCapacity) {
                  loopIndex = undoInstCount * 4;
                  _memset(loopIndex + undoInstData,0,4);
                  undoInstCount = undoInstLength + 1;
                  undoInstSlot = (undefined4 *)(loopIndex + undoInstData);
                }
                else {
                  undoInstSlot = (undefined4 *)Vector__elementRefGrow(&undoInstCapacity,undoInstCount);
                }
                undoOperandLength = undoOperandCount;
                *undoInstSlot = consumerInst;
                undoOperandIndex2 = *(undefined4 *)(edge + 0x10);
                if (undoOperandCount < undoOperandCapacity) {
                  undoCountOffset = undoOperandCount * 4;
                  _memset(undoCountOffset + undoOperandData,0,4);
                  undoOperandCount = undoOperandLength + 1;
                  undoOperandSlot = (undefined4 *)(undoCountOffset + undoOperandData);
                }
                else {
                  undoOperandSlot = (undefined4 *)Vector__elementRefGrow(&undoOperandCapacity,undoOperandCount);
                }
                undoSelectLength = undoSelectCount;
                *undoOperandSlot = undoOperandIndex2;
                if (undoSelectCount < undoSelectCapacity) {
                  undoCountOffset2 = undoSelectCount * 4;
                  _memset(undoCountOffset2 + undoSelectData,0,4);
                  undoSelectCount = undoSelectLength + 1;
                  undoSelectSlot = (undefined4 *)(undoCountOffset2 + undoSelectData);
                }
                else {
                  undoSelectSlot = (undefined4 *)Vector__elementRefGrow(&undoSelectCapacity,undoSelectCount);
                }
                *undoSelectSlot = oldSelectWord;
              }
            }
            consumerIsFetchOrExport = (**(code **)(*consumerInst + 0x5c))(consumerInst);
            if (((consumerIsFetchOrExport != 0) || (consumerIsFetchOrExport = (**(code **)(*consumerInst + 0x60))(consumerInst), consumerIsFetchOrExport != 0)) ||
               ((consumerIsFetchOrExport = (**(code **)(*this + 0x88))(this,consumerInst), consumerIsFetchOrExport != 0 &&
                (consumerIsFetchOrExport = ((int (*)())SchedModel__instructionFitsAlone)(consumerInst,this[2]), consumerIsFetchOrExport != 0)))) goto LAB_0018e058;
          }
LAB_0018dda4:
          failedFlag = 0;
          goto LAB_0018e110;
        }
LAB_0018e058:
        loopIndex3 = loopIndex3 + 1;
        loopIndex2 = loopIndex2 + 1;
        edgeByteOffset = edgeByteOffset + 4;
        if (successorCount == loopIndex3) break;
        successorVector = *(uint **)(node + 0x40);
      } while( true );
    }
    failedFlag = 1;
LAB_0018e110:
    while (undoInstCount != 0) {
      undoInstIndex = undoInstCount - 1;
      undoInstRef = (int *)0x0;
      if (undoInstIndex < undoInstCount) {
        undoInstRef = (int *)(undoInstIndex * 4 + undoInstData);
      }
      inst1 = *undoInstRef;
      Vector__removeAt(&undoInstCapacity,undoInstIndex);
      undoOperandRef = (int *)0x0;
      undoOperandIndex = undoOperandCount - 1;
      if (undoOperandIndex < undoOperandCount) {
        undoOperandRef = (int *)(undoOperandIndex * 4 + undoOperandData);
      }
      undoInst = *undoOperandRef;
      Vector__removeAt(&undoOperandCapacity,undoOperandIndex);
      undoSelectRef = (undefined4 *)0x0;
      undoSelectIndex = undoSelectCount - 1;
      if (undoSelectIndex < undoSelectCount) {
        undoSelectRef = (undefined4 *)(undoSelectIndex * 4 + undoSelectData);
      }
      undoSelectWord = *undoSelectRef;
      Vector__removeAt(&undoSelectCapacity,undoSelectIndex);
      if (undoInst == 0) {
        *(undefined4 *)(inst1 + 0x9c) = undoSelectWord;
      }
      else {
        operandRecord2 = IRInst__getOperandRecord(inst1,undoInst);
        *(undefined4 *)(operandRecord2 + 0x10) = undoSelectWord;
      }
    }
    Arena__free(undoSelectArena,undoSelectData);
    Arena__free(undoOperandArena,undoOperandData);
    Arena__free(undoInstArena,undoInstData);
  }
  return failedFlag;
}
#undef undoInstCapacity
#undef undoInstCount
#undef undoInstData
#undef undoInstArena
#undef undoOperandCapacity
#undef undoOperandCount
#undef undoOperandData
#undef undoOperandArena
#undef undoSelectCapacity
#undef undoSelectCount
#undef undoSelectData
#undef undoSelectArena

/* R300SchedModel__legalizeInstruction @ 0x18e1a8 (1724 bytes) */
int R300SchedModel__legalizeInstruction(this, inst)
  int *this;
  int *inst;
{
  undefined4 presubSource2;
  undefined4 foldedSource;
  undefined4 inputSource;
  undefined4 presubSource1;
  undefined4 selectWord;
  undefined4 movSource;
  undefined4 result;
  undefined4 identitySelect;
  int *candidateSource;
  int *splitSource;
  int *destSelectCursor;
  int *operandSource;
  undefined4 *stackAppendSlot;
  int pushByteOffset;
  int appendByteOffset;
  int flagBit13Result;
  int operandRecord;
  int splatCheck;
  int producerOpcode;
  int hasSingleUse;
  int isLoadConst;
  int flagBit12Result;
  int *targetInst;
  int *stackTopSlot;
  int *sourceDef;
  int *topSlot;
  int *pushSlot;
  bool moreSwizzleBytes;
  bool laneSelected;
  bool noMovYet;
  bool moreLanes;
  bool moreComponents;
  bool pushUpFailed;
  bool hasMarkedMov;
  float zeroLiteral;
  int loopIndex4;
  int *insertedMov;
  int loopIndex5;
  int iVar8;
  undefined4 *listAppendSlot;
  int *inst2;
  int *constRecordCursor;
  int loopIndex;
  undefined4 newNegate;
  int loopIndex2;
  int block;
  undefined4 mixInnerSource;
  int program;
  uint *loopIndex6;
  undefined4 presubSelect1;
  int loopIndex3;
  uint loopIndex7;
  double literalValue;
  int swizzleGroupCount;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - walkStackCapacity/walkStackCount/walkStackData/local_88 are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_94_buf [0x10];
  #define walkStackCapacity (*(uint *)(local_94_buf + 0x00))
  #define walkStackCount (*(uint *)(local_94_buf + 0x04))
  #define walkStackData (*(int *)(local_94_buf + 0x08))
  #define local_88 (*(undefined4 *)(local_94_buf + 0x0c))
  uint local_84 [7];
  undefined4 clearedSelectFirst;
  undefined4 clearedSelectMiddle;
  int clearedSelectLast;
  undefined4 clearedSelectTemp [3];
  
  block = inst[0x56];
  program = *(int *)(this[2] + 0x6c4);
  loopIndex4 = Compiler__isOptionEnabled(this[2],0x40);
  if (((loopIndex4 == 0) || (*(int *)(inst[0x22] + 8) != 0x77)) || ((inst[5] & 0x2000000U) != 0)) {
    insertedMov = (int *)0x0;
  }
  else {
    local_88 = *(undefined4 *)(this[2] + 0x378);
    walkStackCount = 0;
    walkStackCapacity = 2;
    walkStackData = Arena__alloc(local_88,8);
    local_84[3] = *(undefined4 *)(this[2] + 0x378);
    local_84[1] = 0;
    local_84[0] = 2;
    local_84[2] = Arena__alloc(local_84[3],8);
    loopIndex2 = *(int *)(program + 0x474) + 1;
    *(int *)(program + 0x474) = loopIndex2;
    loopIndex4 = IRInst__getOperandSource(inst,1);
    *(int *)(loopIndex4 + 0x150) = loopIndex2;
    if (walkStackCount < walkStackCapacity) {
      loopIndex5 = walkStackCount * 4;
      loopIndex7 = walkStackCount + 1;
      _memset(loopIndex5 + walkStackData,0,4);
      pushSlot = (int *)(loopIndex5 + walkStackData);
      walkStackCount = loopIndex7;
    }
    else {
      pushSlot = (int *)Vector__elementRefGrow(&walkStackCapacity,walkStackCount);
    }
    *pushSlot = loopIndex4;
    pushUpFailed = false;
    hasMarkedMov = false;
    do {
      loopIndex7 = walkStackCount - 1;
      topSlot = (int *)0x0;
      if (loopIndex7 < walkStackCount) {
        topSlot = (int *)(loopIndex7 * 4 + walkStackData);
      }
      loopIndex3 = *topSlot;
      Vector__removeAt(&walkStackCapacity,loopIndex7);
      loopIndex5 = OpcodeTraits__flagBit12(*(undefined4 *)(*(int *)(loopIndex3 + 0x88) + 8),this[2]);
      if (loopIndex5 != 0) goto LAB_0018e6f8;
      loopIndex5 = OpcodeTraits__flagBit13(*(undefined4 *)(*(int *)(loopIndex3 + 0x88) + 8),this[2]);
      if (loopIndex5 != 0) {
        loopIndex5 = *(int *)(*(int *)(loopIndex3 + 0x88) + 8);
        if (((loopIndex5 == 0x24) || (loopIndex5 == 0x25)) || (loopIndex = 1, loopIndex5 == 0x26)) {
          loopIndex = 2;
        }
        if (loopIndex <= *(int *)(loopIndex3 + 0x84)) {
          loopIndex5 = loopIndex * 0x18;
          loopIndex6 = (uint *)(loopIndex5 + loopIndex3 + 0xa0);
          do {
            sourceDef = (int *)IRInst__getOperandSource(loopIndex3,loopIndex);
            if (loopIndex2 != sourceDef[0x54]) {
              sourceDef[0x54] = loopIndex2;
              flagBit12Result = OpcodeTraits__flagBit12(*(undefined4 *)(sourceDef[0x22] + 8),this[2]);
              if (flagBit12Result != 0) {
LAB_0018e6e0:
                pushUpFailed = true;
                break;
              }
              if ((*loopIndex6 & 1) != 0) {
                isLoadConst = (**(code **)(*sourceDef + 0x48))(sourceDef);
                if (isLoadConst == 0) {
                  hasSingleUse = IRInst__hasSingleUse(sourceDef,program);
                  if (hasSingleUse == 0) goto LAB_0018e6e0;
                  producerOpcode = *(int *)(sourceDef[0x22] + 8);
                  if (producerOpcode == 0x31) {
LAB_0018e4e0:
                    IROperand__setModifierBits(sourceDef + 0x29,1,sourceDef[0x2e] & 1U ^ 1);
                  }
                  else if (producerOpcode == 0x12) {
                    IROperand__setModifierBits(sourceDef + 0x29,1,sourceDef[0x2e] & 1U ^ 1);
                    IROperand__setModifierBits(sourceDef + 0x2f,1,sourceDef[0x34] & 1U ^ 1);
                  }
                  else {
                    if (producerOpcode == 0x13) goto LAB_0018e4e0;
                    if (producerOpcode == 0x14) {
                      IROperand__setModifierBits(sourceDef + 0x29,1,sourceDef[0x2e] & 1U ^ 1);
                    }
                    else {
                      if (((producerOpcode != 0x24) && (producerOpcode != 0x25)) && (producerOpcode != 0x26))
                      goto LAB_0018e6e0;
                      splatCheck = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(sourceDef,2,(double)FLOAT_001aa0d4);
                      if (splatCheck == 0) {
                        IROperand__setModifierBits(sourceDef + 0x2f,1,sourceDef[0x34] & 1U ^ 1);
                      }
                      splatCheck = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(sourceDef,3,(double)FLOAT_001aa0d4);
                      if (splatCheck != 0) goto LAB_0018e5a0;
                    }
                    IROperand__setModifierBits(sourceDef + 0x35,1,sourceDef[0x3a] & 1U ^ 1);
                  }
LAB_0018e5a0:
                  newNegate = 0;
                }
                else {
                  splatCheck = ((undefined4 (*)())IRInst__sourceIsSplatConstant)(loopIndex3,loopIndex,(double)FLOAT_001aa0d4);
                  zeroLiteral = FLOAT_001aa0d4;
                  if (splatCheck != 0) goto LAB_0018e5a0;
                  loopIndex7 = 0;
                  constRecordCursor = sourceDef;
                  do {
                    operandRecord = IRInst__getOperandRecord(sourceDef,0);
                    if ((*(char *)(loopIndex7 + operandRecord + 0x10) != '\x01') &&
                       (((((int)*(char *)(sourceDef + 0x57) >> (loopIndex7 & 0x3f) & 1U) == 0 ||
                         (constRecordCursor[7] != 2)) || (GH_U2F((unsigned int)(constRecordCursor[8])) == zeroLiteral)))) goto LAB_0018e6e0;
                    moreComponents = loopIndex7 != 3;
                    constRecordCursor = constRecordCursor + 6;
                    loopIndex7 = loopIndex7 + 1;
                  } while (moreComponents);
                  if (pushUpFailed) goto LAB_0018e6e0;
                  newNegate = 1;
                }
                IROperand__setModifierBits(loopIndex5 + loopIndex3 + 0x8c,1,newNegate);
              }
              flagBit13Result = OpcodeTraits__flagBit13(*(undefined4 *)(sourceDef[0x22] + 8),this[2]);
              if (flagBit13Result == 0) {
                if (*(int *)(sourceDef[0x22] + 8) == 0x31) {
                  iVar8 = IRInst__getOperandSource(sourceDef,1);
                  iVar8 = OpcodeTraits__flagBit12(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),this[2]);
                  if (iVar8 == 0) {
                    iVar8 = IRInst__getOperandSource(sourceDef,1);
                    iVar8 = OpcodeTraits__flagBit13(*(undefined4 *)(*(int *)(iVar8 + 0x88) + 8),this[2]);
                    if (iVar8 == 0) goto LAB_0018e6c4;
                  }
                  loopIndex7 = local_84[1];
                  if (local_84[1] < local_84[0]) {
                    appendByteOffset = local_84[1] * 4;
                    _memset(appendByteOffset + local_84[2],0,4);
                    local_84[1] = loopIndex7 + 1;
                    listAppendSlot = (undefined4 *)(appendByteOffset + local_84[2]);
                  }
                  else {
                    listAppendSlot = (undefined4 *)Vector__elementRefGrow(local_84,local_84[1]);
                  }
                  *listAppendSlot = sourceDef;
                  hasMarkedMov = true;
                }
              }
              else {
                if (walkStackCount < walkStackCapacity) {
                  pushByteOffset = walkStackCount * 4;
                  loopIndex7 = walkStackCount + 1;
                  _memset(pushByteOffset + walkStackData,0,4);
                  stackAppendSlot = (undefined4 *)(pushByteOffset + walkStackData);
                  walkStackCount = loopIndex7;
                }
                else {
                  stackAppendSlot = (undefined4 *)Vector__elementRefGrow(&walkStackCapacity,walkStackCount);
                }
                *stackAppendSlot = sourceDef;
              }
            }
LAB_0018e6c4:
            loopIndex = loopIndex + 1;
            loopIndex5 = loopIndex5 + 0x18;
            loopIndex6 = loopIndex6 + 6;
          } while (loopIndex <= *(int *)(loopIndex3 + 0x84));
        }
      }
    } while (walkStackCount != 0);
    if (pushUpFailed) {
LAB_0018e6f8:
      *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
      insertedMov = (int *)IRInst__create(0x31,this[2]);
      insertedMov[0x26] = 0;
      insertedMov[0x25] = insertedMov[0x53];
      IRInst__setOperandSource(insertedMov,1,loopIndex4,0,this[2]);
      IRInst__setOperandSource(inst,1,insertedMov,0,this[2]);
      identitySelect = DAT_001b2a68;
      insertedMov[0x27] = DAT_001b2a80;
      loopIndex4 = IRInst__getOperandRecord(insertedMov,1);
      *(undefined4 *)(loopIndex4 + 0x10) = identitySelect;
      loopIndex4 = 0;
      do {
        loopIndex2 = IRInst__getOperandRecord(inst,1);
        loopIndex7 = (uint)*(byte *)(loopIndex4 + loopIndex2 + 0x10);
        if (loopIndex7 != 4) {
          (**(code **)(*insertedMov + 0x88))(insertedMov,1,loopIndex7,loopIndex7);
          *(undefined1 *)((int)insertedMov + loopIndex7 + 0x9c) = 0;
        }
        moreLanes = loopIndex4 != 3;
        loopIndex4 = loopIndex4 + 1;
      } while (moreLanes);
      Block__insertInstBefore(block,inst,insertedMov);
      insertedMov[5] = insertedMov[5] | 0x80000000;
    }
    else {
      if (hasMarkedMov) {
        while (local_84[1] != 0) {
          loopIndex7 = local_84[1] - 1;
          stackTopSlot = (int *)0x0;
          if (loopIndex7 < local_84[1]) {
            stackTopSlot = (int *)(loopIndex7 * 4 + local_84[2]);
          }
          loopIndex4 = *stackTopSlot;
          Vector__removeAt(local_84,loopIndex7);
          *(uint *)(loopIndex4 + 0x14) = *(uint *)(loopIndex4 + 0x14) | 0x80000000;
        }
      }
      insertedMov = (int *)0x0;
    }
    Arena__free(local_84[3],local_84[2]);
    Arena__free(local_88,walkStackData);
  }
  result = 0;
  loopIndex4 = (**(code **)(*inst + 0x28))(inst);
  if (loopIndex4 != 0) {
    noMovYet = insertedMov == (int *)0x0;
    for (loopIndex4 = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex4 <= loopIndex2;
        loopIndex4 = loopIndex4 + 1) {
      operandSource = (int *)IRInst__getOperandSource(inst,loopIndex4);
      loopIndex2 = (**(code **)(*operandSource + 0x60))();
      if (loopIndex2 == 0) {
code_r0x0018e934:
        operandSource = (int *)IRInst__getOperandSource(inst,loopIndex4);
        loopIndex2 = (**(code **)(*operandSource + 0x48))();
        if (loopIndex2 == 0) {
          operandSource = (int *)IRInst__getOperandSource(inst,loopIndex4);
          loopIndex2 = (**(code **)(*operandSource + 0x60))();
          if ((loopIndex2 == 0) &&
             ((((inst[loopIndex4 * 6 + 0x28] & 2U) == 0 && ((inst[loopIndex4 * 6 + 0x28] & 1U) == 0)) ||
              (loopIndex2 = FUN_00148d8c(inst,program), loopIndex2 != 0)))) goto code_r0x0018eb5c;
        }
        loopIndex5 = 0;
        *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
        inst2 = (int *)IRInst__create(0x31,this[2]);
        inst2[0x26] = 0;
        inst2[0x25] = inst2[0x53];
        movSource = IRInst__getOperandSource(inst,loopIndex4);
        IRInst__setOperandSource(inst2,1,movSource,0,this[2]);
        IROperand__setModifierBits(inst2 + 0x29,2,(uint)inst[loopIndex4 * 6 + 0x28] >> 1 & 1);
        IROperand__setModifierBits(inst2 + 0x29,1,inst[loopIndex4 * 6 + 0x28] & 1);
        loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
        selectWord = *(undefined4 *)(loopIndex2 + 0x10);
        loopIndex2 = IRInst__getOperandRecord(inst2,1);
        walkStackCapacity = DAT_001b2a64;
        *(undefined4 *)(loopIndex2 + 0x10) = selectWord;
        destSelectCursor = inst2;
        do {
          loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
          if (*(char *)(loopIndex5 + loopIndex2 + 0x10) == '\x04') {
            *(undefined1 *)(destSelectCursor + 0x27) = 1;
            *(undefined1 *)((int)&walkStackCapacity + loopIndex5) = 4;
          }
          moreSwizzleBytes = loopIndex5 != 3;
          destSelectCursor = (int *)((int)destSelectCursor + 1);
          loopIndex5 = loopIndex5 + 1;
        } while (moreSwizzleBytes);
        Block__insertInstBefore(block,inst,inst2);
        IRInst__setOperandSource(inst,loopIndex4,inst2,0,this[2]);
        IROperand__setModifierBits(inst + loopIndex4 * 6 + 0x23,2,0);
        IROperand__setModifierBits(inst + loopIndex4 * 6 + 0x23,1,0);
        loopIndex7 = walkStackCapacity;
        loopIndex2 = IRInst__getOperandRecord(inst,loopIndex4);
        *(uint *)(loopIndex2 + 0x10) = loopIndex7;
        if (noMovYet) {
          noMovYet = inst2 == (int *)0x0;
          result = 1;
          insertedMov = inst2;
        }
        else {
          result = 1;
        }
      }
      else {
        mixInnerSource = IRInst__getOperandSource(inst,loopIndex4);
        mixInnerSource = IRInst__getOperandSource(mixInnerSource,1);
        loopIndex2 = IRInst__hasSingleUse(mixInnerSource,*(undefined4 *)(this[2] + 0x6c4));
        if (loopIndex2 == 0) goto code_r0x0018e934;
        inputSource = IRInst__getOperandSource(inst,loopIndex4);
        loopIndex2 = FUN_0010c47c(inputSource,this[2]);
        if (loopIndex2 == 0) goto code_r0x0018e934;
        foldedSource = IRInst__getOperandSource(inst,loopIndex4);
        foldedSource = FUN_0010cb48(foldedSource,this[2]);
        IRInst__setOperandSource(inst,loopIndex4,foldedSource,0,this[2]);
      }
code_r0x0018eb5c: ;
    }
    if (!noMovYet) {
      inst = insertedMov;
    }
  }
  targetInst = inst;
  if (((*(int *)(inst[0x22] + 8) == 0x9e) || (*(int *)(inst[0x22] + 8) == 0xa0)) &&
     ((loopIndex4 = IRInst__isSourceSelectIdentity(inst,1), loopIndex4 == 0 ||
      (((inst[0x2e] & 1U) != 0 || ((inst[0x2e] & 2U) != 0)))))) {
    *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
    targetInst = (int *)IRInst__create(0x31,this[2]);
    targetInst[0x26] = 0;
    targetInst[0x25] = targetInst[0x53];
    loopIndex4 = IRInst__getOperandRecord(inst,0);
    selectWord = *(undefined4 *)(loopIndex4 + 0x10);
    loopIndex4 = IRInst__getOperandRecord(targetInst,0);
    *(undefined4 *)(loopIndex4 + 0x10) = selectWord;
    movSource = IRInst__getOperandSource(inst,1);
    IRInst__setOperandSource(targetInst,1,movSource,0,this[2]);
    IROperand__setModifierBits(targetInst + 0x29,2,(uint)inst[0x2e] >> 1 & 1);
    IROperand__setModifierBits(targetInst + 0x29,1,inst[0x2e] & 1);
    loopIndex4 = IRInst__getOperandRecord(inst,1);
    selectWord = *(undefined4 *)(loopIndex4 + 0x10);
    loopIndex4 = IRInst__getOperandRecord(targetInst,1);
    *(undefined4 *)(loopIndex4 + 0x10) = selectWord;
    Block__insertInstBefore(block,inst,targetInst);
    IRInst__setOperandSource(inst,1,targetInst,0,this[2]);
    IROperand__setModifierBits(inst + 0x29,2,0);
    IROperand__setModifierBits(inst + 0x29,1,0);
    loopIndex7 = DAT_001b2a64;
    loopIndex4 = IRInst__getOperandRecord(inst,1);
    loopIndex2 = 0;
    *(uint *)(loopIndex4 + 0x10) = loopIndex7;
    do {
      loopIndex4 = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex2 + loopIndex4 + 0x10) == '\x01') {
        (**(code **)(*inst + 0x88))(inst,1,loopIndex2,4);
      }
      moreLanes = loopIndex2 != 3;
      loopIndex2 = loopIndex2 + 1;
    } while (moreLanes);
    result = 1;
  }
  loopIndex2 = 1;
  loopIndex4 = (**(code **)(*this + 0x88))(this,targetInst);
  if (loopIndex4 == 0) {
    for (; loopIndex4 = (**(code **)(*targetInst + 0x14))(targetInst), loopIndex2 <= loopIndex4; loopIndex2 = loopIndex2 + 1) {
      swizzleGroupCount = 0;
      (**(code **)(*this + 0x68))(this,targetInst,loopIndex2,local_84,&swizzleGroupCount,this[2]);
      if (swizzleGroupCount != 0) {
        if ((*(int *)(targetInst[0x22] + 8) == 0x31) || (*(int *)(targetInst[0x22] + 8) == 0x30)) {
          *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
          loopIndex4 = IRInst__create(0x31,this[2]);
          IRInst__copyBodyFrom(loopIndex4,targetInst);
          loopIndex7 = local_84[0];
          loopIndex5 = IRInst__getOperandRecord(loopIndex4,1);
          *(uint *)(loopIndex5 + 0x10) = loopIndex7;
          SelectWord__clearReadComponents(&clearedSelectFirst,local_84[0]);
          *(undefined4 *)(loopIndex4 + 0x9c) = clearedSelectFirst;
          Block__insertInstBefore(block,targetInst,loopIndex4);
          loopIndex5 = swizzleGroupCount + -1;
          if (1 < loopIndex5) {
            loopIndex3 = 1;
            loopIndex6 = local_84;
            do {
              loopIndex6 = loopIndex6 + 1;
              loopIndex5 = IRInst__create(0x31,this[2]);
              IRInst__copyBodyFrom(loopIndex5,targetInst);
              loopIndex7 = *loopIndex6;
              loopIndex = IRInst__getOperandRecord(loopIndex5,1);
              *(uint *)(loopIndex + 0x10) = loopIndex7;
              SelectWord__clearReadComponents(&clearedSelectMiddle,*loopIndex6);
              *(undefined4 *)(loopIndex5 + 0x9c) = clearedSelectMiddle;
              Block__insertInstBefore(block,targetInst,loopIndex5);
              if ((targetInst[5] & 2U) == 0) {
                IRInst__setExtraOperandSource(loopIndex5,loopIndex4,0,this[2]);
                loopIndex4 = loopIndex5;
              }
              loopIndex3 = loopIndex3 + 1;
              *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
              loopIndex5 = swizzleGroupCount + -1;
            } while (loopIndex3 < loopIndex5);
          }
          loopIndex7 = local_84[loopIndex5];
          loopIndex5 = IRInst__getOperandRecord(targetInst,1);
          *(uint *)(loopIndex5 + 0x10) = loopIndex7;
          SelectWord__clearReadComponents(&clearedSelectLast,(&local_88)[swizzleGroupCount]);
          targetInst[0x27] = clearedSelectLast;
          if ((targetInst[5] & 2U) == 0) {
            IRInst__setExtraOperandSource(targetInst,loopIndex4,0,this[2]);
          }
        }
        else {
          splitSource = (int *)IRInst__getOperandSource(targetInst,loopIndex2);
          loopIndex4 = 0;
          if (0 < swizzleGroupCount) {
            loopIndex3 = 0;
            loopIndex6 = local_84;
            loopIndex5 = loopIndex4;
            do {
              *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
              loopIndex4 = IRInst__create(0x31,this[2]);
              *(undefined4 *)(loopIndex4 + 0x98) = 0;
              *(undefined4 *)(loopIndex4 + 0x94) = *(undefined4 *)(loopIndex4 + 0x14c);
              IRInst__setOperandSource(loopIndex4,1,splitSource,0,this[2]);
              loopIndex7 = *loopIndex6;
              loopIndex = IRInst__getOperandRecord(loopIndex4,1);
              *(uint *)(loopIndex + 0x10) = loopIndex7;
              SelectWord__clearReadComponents(clearedSelectTemp,*loopIndex6);
              *(undefined4 *)(loopIndex4 + 0x9c) = clearedSelectTemp[0];
              if (loopIndex5 == 0) {
                if ((((splitSource[0x20] != 0) && (loopIndex5 = RegKind__flagBit0(splitSource[0x26]), loopIndex5 != 0)) &&
                    ((splitSource[5] & 2U) == 0)) &&
                   (loopIndex5 = (**(code **)(*splitSource + 0x50))(splitSource), loopIndex5 == 0)) {
                  loopIndex = 4;
                  laneSelected = false;
                  loopIndex7 = 0;
                  loopIndex5 = loopIndex4;
                  do {
                    if (loopIndex7 == *(byte *)(loopIndex7 + (int)local_84)) {
                      *(undefined1 *)(loopIndex5 + 0x9c) = 1;
                      laneSelected = true;
                    }
                    loopIndex7 = loopIndex7 + 1;
                    loopIndex5 = loopIndex5 + 1;
                    loopIndex = loopIndex + -1;
                  } while (loopIndex != 0);
                  if (laneSelected) {
                    IRInst__setExtraOperandSource(loopIndex4,splitSource,0,this[2]);
                  }
                }
              }
              else {
                IRInst__setExtraOperandSource(loopIndex4,loopIndex5,0,this[2]);
              }
              loopIndex5 = IRInst__getOperandRecord(loopIndex4,0);
              if (*(int *)(loopIndex5 + 0x10) == DAT_001b2a80) {
                loopIndex4 = IRInst__getOperandSource(loopIndex4,*(undefined4 *)(loopIndex4 + 0x84));
              }
              else {
                Block__insertInstBefore(block,targetInst,loopIndex4);
              }
              loopIndex3 = loopIndex3 + 1;
              loopIndex6 = loopIndex6 + 1;
              loopIndex5 = loopIndex4;
            } while (loopIndex3 < swizzleGroupCount);
          }
          IRInst__setOperandSource(targetInst,loopIndex2,loopIndex4,0,this[2]);
        }
      }
    }
    result = 1;
  }
  program = 1;
  loopIndex4 = ((int (*)())SchedModel__instructionFitsAlone)(targetInst,this[2]);
  if (loopIndex4 == 0) {
    for (; loopIndex4 = (**(code **)(*targetInst + 0x14))(targetInst), program <= loopIndex4; program = program + 1) {
      candidateSource = (int *)IRInst__getOperandSource(targetInst,program);
      loopIndex4 = (**(code **)(*candidateSource + 0x60))();
      if (loopIndex4 != 0) {
        candidateSource = (int *)IRInst__getOperandSource(candidateSource,1);
      }
      loopIndex4 = (**(code **)(*candidateSource + 0x5c))(candidateSource);
      if (loopIndex4 != 0) {
        presubSource1 = IRInst__getOperandSource(candidateSource,1);
        loopIndex4 = IRInst__getOperandRecord(candidateSource,0);
        loopIndex2 = *(int *)(loopIndex4 + 0x10);
        loopIndex4 = IRInst__getOperandRecord(candidateSource,1);
        presubSelect1 = *(undefined4 *)(loopIndex4 + 0x10);
        presubSource2 = 0;
        loopIndex4 = (**(code **)(*candidateSource + 0x14))(candidateSource);
        if (1 < loopIndex4) {
          presubSource2 = IRInst__getOperandSource(candidateSource,2);
          loopIndex4 = IRInst__getOperandRecord(candidateSource,2);
          block = *(int *)(loopIndex4 + 0x10);
        }
        loopIndex4 = candidateSource[1];
        loopIndex5 = *(int *)(candidateSource[0x22] + 8);
        DList__unlink(candidateSource);
        if (loopIndex5 != 0x99) {
          IRInst__reinitAsBinary(candidateSource,0x12,this[2]);
        }
        else {
          IRInst__reinitAsTrinary(candidateSource,0x14,this[2]);
        }
        loopIndex = candidateSource[0x53];
        loopIndex3 = IRInst__getOperandRecord(candidateSource,0);
        *(undefined4 *)(loopIndex3 + 0xc) = 0;
        *(int *)(loopIndex3 + 8) = loopIndex;
        candidateSource[0x27] = loopIndex2;
        IRInst__setOperandSource(candidateSource,1,presubSource1,0,this[2]);
        loopIndex2 = IRInst__getOperandRecord(candidateSource,1);
        *(undefined4 *)(loopIndex2 + 0x10) = presubSelect1;
        if (loopIndex5 != 0x99) {
          if (loopIndex5 == 0x9c) {
            literalValue = (double)FLOAT_001aa0e8;
            ((void (*)())IRInst__makeLiteralVec4Float)(candidateSource,*(undefined4 *)(this[2] + 0x6c4),2,literalValue,literalValue,literalValue,literalValue);
            IROperand__setModifierBits(candidateSource + 0x29,1,1);
          }
          else {
            IRInst__setOperandSource(candidateSource,2,presubSource2,0,this[2]);
            loopIndex2 = IRInst__getOperandRecord(candidateSource,2);
            *(int *)(loopIndex2 + 0x10) = block;
            IROperand__setModifierBits(candidateSource + 0x2f,1,(uint)(loopIndex5 == 0x9a));
          }
        }
        else {
          IROperand__setModifierBits(candidateSource + 0x29,1,1);
          literalValue = (double)FLOAT_001aa0e8;
          ((void (*)())IRInst__makeLiteralVec4Float)(candidateSource,*(undefined4 *)(this[2] + 0x6c4),2,literalValue,literalValue,literalValue,literalValue);
          literalValue = (double)FLOAT_001aa10c;
          ((void (*)())IRInst__makeLiteralVec4Float)(candidateSource,*(undefined4 *)(this[2] + 0x6c4),3,literalValue,literalValue,literalValue,literalValue);
          candidateSource[0x49] = 1;
        }
        Block__insertInstAfter(*(undefined4 *)(loopIndex4 + 0x158),loopIndex4,candidateSource);
        loopIndex4 = ((int (*)())SchedModel__instructionFitsAlone)(targetInst,this[2]);
        if (loopIndex4 != 0) break;
      }
    }
    result = 1;
  }
  return result;
}
#undef walkStackCapacity
#undef walkStackCount
#undef walkStackData
#undef local_88

/* R520SchedModel__vslot4_addInstruction @ 0x18f42c (304 bytes) */
int R520SchedModel__vslot4_addInstruction(schedModel, inst)
  int schedModel;
  int *inst;
{
  int callResult;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  
  if ((inst[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*inst + 0x28))(inst);
    if (callResult == 0) {
      ((int (*)())FUN_00189df4)(inst,schedModel + 0x18,schedModel + 0x20);
      ((int (*)())FUN_0018d4b4)(inst,schedModel + 0x1c,schedModel + 0x24,schedModel + 0x28,*(undefined4 *)(schedModel + 8)
                  );
      ((int (*)())PackState__countFreeSlots)(schedModel + 0x28,&local_38);
      uVar2 = 0;
      if (*(int *)(schedModel + 100) != 0) {
        ((int (*)())SchedModel__fitsConstantLimit)(schedModel,*(int *)(schedModel + 100),inst,local_38,local_34);
        uVar2 = *(undefined4 *)(schedModel + 100);
      }
      ((int (*)())SchedModel__assignConstantSelectors)(schedModel,uVar2,inst,local_38,local_34);
      if (*(int *)(schedModel + 100) == 0) {
        *(int **)(schedModel + 100) = inst;
      }
      if (*(int *)(schedModel + 0x18) < 0) {
        if (*(int *)(schedModel + 0x20) < 0) {
          *(undefined4 *)(schedModel + 4) = 0;
        }
        else {
          *(undefined4 *)(schedModel + 4) = 2;
        }
      }
      else if (*(int *)(schedModel + 0x20) < 0) {
        *(undefined4 *)(schedModel + 4) = 1;
      }
      else {
        *(undefined4 *)(schedModel + 4) = 3;
      }
    }
    else {
      *(undefined4 *)(schedModel + 4) = 4;
    }
  }
  return;
}

/* R520SchedModel__vslot3_canAddInstruction @ 0x18f55c (280 bytes) */
int R520SchedModel__vslot3_canAddInstruction(schedModel, inst)
  int schedModel;
  int *inst;
{
  int callResult;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [80];
  
  if ((inst[5] & 0x8000U) == 0) {
    callResult = (**(code **)(*inst + 0x28))(inst);
    if (callResult != 0) {
      return *(int *)(schedModel + 4) == 0;
    }
    local_78 = *(undefined4 *)(schedModel + 0x18);
    local_74 = *(undefined4 *)(schedModel + 0x1c);
    local_70 = *(undefined4 *)(schedModel + 0x20);
    local_6c = *(undefined4 *)(schedModel + 0x24);
    ((int (*)())PackState__copy)(auStack_60,schedModel + 0x28);
    callResult = ((int (*)())FUN_00189df4)(inst,&local_78,&local_70);
    if ((((callResult == 0) ||
         (callResult = ((int (*)())FUN_0018d4b4)(inst,&local_74,&local_6c,auStack_60,*(undefined4 *)(schedModel + 8)),
         callResult == 0)) || (callResult = ((int (*)())PackState__countFreeSlots)(auStack_60,&local_68), callResult == 0)) ||
       ((*(int *)(schedModel + 100) != 0 &&
        (callResult = ((int (*)())SchedModel__fitsConstantLimit)(schedModel,*(int *)(schedModel + 100),inst,local_68,local_64), callResult == 0
        )))) {
      return false;
    }
  }
  return true;
}

/* R300SchedModel__vslot12 @ 0x18f674 (432 bytes) */
int R300SchedModel__vslot12(this, inst)
  int this;
  int *inst;
{
  uint uVar1;
  int callResult;
  int operandRecord;
  
  if (((((((inst[0x20] != 0) && (callResult = RegKind__flagBit0(inst[0x26]), callResult != 0)) &&
         ((inst[5] & 2U) == 0)) &&
        ((callResult = (**(code **)(*inst + 0x50))(inst), callResult == 0 &&
         (uVar1 = inst[5], (uVar1 & 0x20) == 0)))) &&
       (((uVar1 & 0x40) == 0 &&
        (((uVar1 & 2) == 0 && (callResult = (**(code **)(*inst + 0x5c))(inst), callResult == 0)))))) &&
      (callResult = (**(code **)(*inst + 0x28))(inst), callResult == 0)) &&
     ((((callResult = *(int *)(inst[0x22] + 8), callResult != 0x9e && (callResult != 0xa0)) && (callResult != 0x9f))
      && (((callResult != 0xa1 && (callResult = *(int *)(PTR_DAT_001e913c + callResult * 0x38 + 0x34), callResult != 3))
          && (callResult != 8)))))) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(char *)(operandRecord + 0x13) == '\0') {
      if ((callResult != 5) &&
         ((callResult != 0 ||
          ((callResult = IRInst__countWrittenComponents(inst), callResult != 4 &&
           ((callResult < 2 || ((*(uint *)(*(int *)(*(int *)(this + 8) + 0x30c) + 8) & 0x400) != 0))))
          )))) {
        return 1;
      }
    }
    else if ((*(char *)(operandRecord + 0x13) == '\x01') && (1 < callResult - 1U)) {
      if (callResult == 5) {
        return 1;
      }
      callResult = IRInst__countWrittenComponents(inst);
      if (callResult < 2) {
        return 1;
      }
    }
  }
  return 0;
}

/* R300VSchedModel__vslot2_reset @ 0x18f824 (44 bytes) */
int R300VSchedModel__vslot2_reset(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x28) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 4;
  *(undefined4 *)(param_1 + 0x24) = 4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  return;
}

/* FUN_0018f850 @ 0x18f850 (200 bytes) */
int FUN_0018f850(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_2[1];
  if (*param_2 == iVar2) {
    iVar3 = *param_3;
    bVar1 = iVar3 != param_3[1];
    if ((bVar1) && (iVar2 != 0)) {
      return 0;
    }
    if (iVar2 == param_2[2]) {
      if (iVar2 == 0) {
        if ((((param_4 == 0) && (bVar1)) && (iVar3 != param_3[2])) && (param_3[1] != param_3[2])) {
          return 0;
        }
      }
      else {
        if (bVar1) {
          return 0;
        }
        if (iVar3 != param_3[2]) {
          return 0;
        }
      }
    }
  }
  else {
    iVar3 = param_2[2];
    if (*param_2 == iVar3) {
      if (*param_3 == param_3[2]) {
        return 1;
      }
    }
    else {
      if (iVar2 != iVar3) {
        return 1;
      }
      iVar3 = iVar2;
      if (param_3[1] == param_3[2]) {
        return 1;
      }
    }
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 1;
}

/* R300VSchedModel__vslot13 @ 0x18f918 (108 bytes) */
int R300VSchedModel__vslot13(this, param_2)
  int *this;
  int param_2;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = (**(code **)(*this + 0x30))(this,*(undefined4 *)(param_2 + 0x38));
  if ((callResult == 0) ||
     ((*(int *)(param_2 + 0x60) != 0 && (*(int *)(*(int *)(param_2 + 0x60) + 8) != 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

/* R300VSchedModel__vslot28 @ 0x18f984 (596 bytes) */
int R300VSchedModel__vslot28(this, program, param_3, param_4, param_5, param_6, param_7)
  int *this;
  int program;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int numSources;
  int slot12Result;
  int opcodeInfo;
  int inst;
  int flagBit2Result;
  int *operandVReg;
  bool moreComponents;
  int nextBlock;
  int loopIndex;
  int *prevInst;
  int *inst2;
  int operandRecord;
  uint source2Select;
  uint source1Select;
  int block;
  
  block = *(int *)(program + 900);
  nextBlock = *(int *)(block + 8);
  do {
    if (nextBlock == 0) {
      return;
    }
    inst = *(int *)(block + 0x98);
    for (loopIndex = *(int *)(*(int *)(block + 0x98) + 8); loopIndex != 0; loopIndex = *(int *)(loopIndex + 8)) {
      if ((*(uint *)(inst + 0x14) & 1) != 0) {
        loopIndex = *(int *)(inst + 0x88);
        if (*(int *)(loopIndex + 8) != 0x8e) {
          (**(code **)(*this + 0x6c))(this,inst);
          loopIndex = *(int *)(inst + 0x88);
        }
        if ((*(int *)(loopIndex + 8) == 0x31) || (*(int *)(loopIndex + 8) == 0x30)) {
          operandVReg = (int *)IRInst__getOperandSource(inst,1);
          loopIndex = (**(code **)(*operandVReg + 0x50))(operandVReg);
          if (loopIndex != 0) {
            loopIndex = *(int *)(inst + 8);
            *(undefined4 *)(inst + 0x9c) = 0x1010101;
            goto LAB_0018fa5c;
          }
        }
        loopIndex = *(int *)(inst + 8);
      }
LAB_0018fa5c:
      inst = loopIndex;
    }
    inst2 = *(int **)(block + 0xa0);
    for (prevInst = (int *)(*(int **)(block + 0xa0))[1]; prevInst != (int *)0x0;
        prevInst = (int *)prevInst[1]) {
      if ((inst2[5] & 1U) != 0) {
        opcodeInfo = inst2[0x22];
        if ((*(int *)(opcodeInfo + 8) == 0x31) || (*(int *)(opcodeInfo + 8) == 0x13)) {
          slot12Result = (**(code **)(*this + 0x30))(this,inst2);
          if (slot12Result == 0) {
            opcodeInfo = inst2[0x22];
          }
          else {
            source1Select = 0xffffffff;
            source2Select = 0xffffffff;
            loopIndex = 0;
            numSources = (**(code **)(*inst2 + 0x14))(inst2);
            do {
              operandRecord = IRInst__getOperandRecord(inst2,0);
              if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
                operandRecord = IRInst__getOperandRecord(inst2,1);
                source1Select = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                if (numSources == 2) {
                  operandRecord = IRInst__getOperandRecord(inst2,2);
                  source2Select = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
                }
              }
              moreComponents = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (moreComponents);
            FUN_0010bb9c(inst2,source1Select,source2Select,0,0,this[2]);
            opcodeInfo = inst2[0x22];
          }
        }
        flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(opcodeInfo + 8),this[2]);
        if ((flagBit2Result == 0) || (inst2[0x26] != 0)) {
          prevInst = (int *)inst2[1];
        }
        else {
          prevInst = (int *)inst2[1];
          inst2[0x26] = 1;
        }
      }
      inst2 = prevInst;
    }
    block = *(int *)(block + 8);
    nextBlock = *(int *)(block + 8);
  } while( true );
}

/* R300VSchedModel__vslot14 @ 0x18fbd8 (348 bytes) */
int R300VSchedModel__vslot14(this, node)
  int *this;
  int node;
{
  int numSources;
  bool moreComponents;
  int opcode;
  int operandRecord;
  undefined4 resourceClass;
  uint source2Select;
  uint source1Select;
  int loopIndex;
  int *nodeInst;
  
  (**(code **)(*this + 0x34))(this,node);
  nodeInst = *(int **)(node + 0x38);
  opcode = *(int *)(nodeInst[0x22] + 8);
  if ((opcode == 0x66) || (opcode == 0x36)) {
    FUN_0010bc78(nodeInst,this[2]);
    nodeInst[0x26] = 0;
  }
  else if ((opcode == 0x31) || (*(int *)(nodeInst[0x22] + 8) == 0x13)) {
    source1Select = 0xffffffff;
    source2Select = 0xffffffff;
    loopIndex = 0;
    numSources = (**(code **)(*nodeInst + 0x14))(nodeInst);
    do {
      operandRecord = IRInst__getOperandRecord(nodeInst,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        operandRecord = IRInst__getOperandRecord(nodeInst,1);
        source1Select = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
        if (numSources == 2) {
          operandRecord = IRInst__getOperandRecord(nodeInst,2);
          source2Select = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
        }
      }
      moreComponents = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    FUN_0010bb9c(nodeInst,source1Select,source2Select,0,0,this[2]);
    nodeInst[0x26] = 1;
  }
  resourceClass = (**(code **)(*this + 0x4c))(this,nodeInst);
  *(undefined4 *)(node + 0x58) = resourceClass;
  return;
}

/* R300VSchedModel__vslot17 @ 0x18fd34 (972 bytes) */
int R300VSchedModel__vslot17(this, node)
  int *this;
  int node;
{
  bool moreLanes2;
  int sourceNumber;
  bool moreLanes;
  int *consumerInst;
  uint succEdgeCount;
  int targetComponent;
  int opcodeCategory;
  int isUndefined;
  int flagBit2Result;
  bool moreComponents;
  bool multipleWritten;
  undefined1 laneByte;
  uint instFlags;
  int flagBit0Result;
  int loopIndex2;
  int writtenComp;
  uint vectorCount;
  int *succSlot;
  int *operandVReg;
  int operandRecord;
  undefined4 resourceClass;
  int prevWrittenComp;
  uint loopIndex3;
  int loopIndex;
  uint *succEdges;
  int *nodeInst;
  
  nodeInst = *(int **)(node + 0x38);
  if (((((*(int *)(node + 0x60) == 0) && (nodeInst[0x20] != 0)) &&
       (flagBit0Result = RegKind__flagBit0(nodeInst[0x26]), flagBit0Result != 0)) &&
      (((nodeInst[5] & 2U) == 0 && (isUndefined = (**(code **)(*nodeInst + 0x50))(nodeInst), isUndefined == 0))))
     && ((instFlags = nodeInst[5], (instFlags & 0x20) == 0 && (((instFlags & 0x40) == 0 && ((instFlags & 2) == 0)))))
     ) {
    opcodeCategory = *(int *)(PTR_DAT_001e9140 + *(int *)(nodeInst[0x22] + 8) * 0x38 + 0x34);
    if ((opcodeCategory == 0) ||
       ((((opcodeCategory == 5 || (opcodeCategory == 1)) || (opcodeCategory == 2)) || ((opcodeCategory == 3 || (opcodeCategory == 8)))))) {
      multipleWritten = false;
      loopIndex = 0;
      prevWrittenComp = -1;
      do {
        loopIndex2 = IRInst__getOperandRecord(nodeInst,0);
        writtenComp = prevWrittenComp;
        if ((*(char *)(loopIndex + loopIndex2 + 0x10) == '\0') && (writtenComp = loopIndex, -1 < prevWrittenComp)) {
          flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(nodeInst[0x22] + 8),this[2]);
          if (flagBit2Result == 0) {
            return;
          }
          multipleWritten = true;
          writtenComp = prevWrittenComp;
        }
        moreComponents = loopIndex != 3;
        loopIndex = loopIndex + 1;
        prevWrittenComp = writtenComp;
      } while (moreComponents);
      targetComponent = this[0xe];
      this[0xe] = targetComponent + 1;
      if (3 < targetComponent + 1) {
        this[0xe] = 0;
      }
      if ((targetComponent != writtenComp) || (multipleWritten)) {
        loopIndex2 = 4;
        loopIndex = node;
        do {
          *(undefined4 *)(loopIndex + 0x48) = 0;
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + -1;
        } while (loopIndex2 != 0);
        succEdges = *(uint **)(node + 0x40);
        loopIndex3 = 0;
        succEdgeCount = succEdges[1];
        if (0 < (int)succEdgeCount) {
          while( true ) {
            if (loopIndex3 < *succEdges) {
              vectorCount = succEdges[1];
              if (vectorCount <= loopIndex3) {
                _memset(vectorCount * 4 + succEdges[2],0,(loopIndex3 - vectorCount) * 4 + 4);
                succEdges[1] = loopIndex3 + 1;
              }
              succSlot = (int *)(loopIndex3 * 4 + succEdges[2]);
            }
            else {
              succSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex3);
            }
            loopIndex3 = loopIndex3 + 1;
            loopIndex = *succSlot;
            if (*(int *)(loopIndex + 8) == 0) {
              *(undefined4 *)(loopIndex + 0x18) = 0;
              *(undefined1 *)(targetComponent + loopIndex + 0x18) = 1;
              loopIndex2 = targetComponent * 4 + node;
              *(int *)(loopIndex2 + 0x48) = *(int *)(loopIndex2 + 0x48) + 1;
              consumerInst = *(int **)(*(int *)(loopIndex + 4) + 0x38);
              for (loopIndex = 1; loopIndex2 = (**(code **)(*consumerInst + 0x14))(consumerInst), loopIndex <= loopIndex2;
                  loopIndex = loopIndex + 1) {
                operandVReg = (int *)IRInst__getOperandSource(consumerInst,loopIndex);
                if (nodeInst == operandVReg) {
                  loopIndex2 = 0;
                  do {
                    operandRecord = IRInst__getOperandRecord(consumerInst,loopIndex);
                    if (*(char *)(loopIndex2 + operandRecord + 0x10) != '\x04') {
                      (**(code **)(*consumerInst + 0x88))(consumerInst,loopIndex,loopIndex2,targetComponent);
                    }
                    moreLanes = loopIndex2 != 3;
                    loopIndex2 = loopIndex2 + 1;
                  } while (moreLanes);
                }
              }
            }
            if (succEdgeCount == loopIndex3) break;
            succEdges = *(uint **)(node + 0x40);
          }
        }
        nodeInst[0x27] = DAT_001b2a84;
        *(undefined1 *)((int)nodeInst + targetComponent + 0x9c) = 0;
        nodeInst[3] = 0;
        *(undefined1 *)((int)nodeInst + targetComponent + 0xc) = 1;
        if (opcodeCategory == 0) {
          for (sourceNumber = 1; targetComponent = (**(code **)(*nodeInst + 0x14))(nodeInst), sourceNumber <= targetComponent;
              sourceNumber = sourceNumber + 1) {
            targetComponent = IRInst__getOperandRecord(nodeInst,sourceNumber);
            loopIndex = 0;
            laneByte = *(undefined1 *)(writtenComp + targetComponent + 0x10);
            do {
              (**(code **)(*nodeInst + 0x88))(nodeInst,sourceNumber,loopIndex,laneByte);
              moreLanes2 = loopIndex != 3;
              loopIndex = loopIndex + 1;
            } while (moreLanes2);
          }
        }
        resourceClass = (**(code **)(*this + 0x4c))(this,nodeInst);
        *(undefined4 *)(node + 0x58) = resourceClass;
      }
    }
  }
  return;
}

/* FUN_00190100 @ 0x190100 (728 bytes) */
int FUN_00190100(param_1, inst, operandIndex, param_4, param_5)
  undefined4 param_1;
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 *param_4;
  int *param_5;
{
  int *a0;
  int callResult;
  undefined4 uVar2;
  int iVar3;
  
  a0 = (int *)IRInst__getOperandSource(inst,operandIndex);
  callResult = (**(code **)(*a0 + 0x60))(a0);
  if (callResult != 0) {
    a0 = (int *)IRInst__getOperandSource(a0,1);
  }
  switch(a0[0x26]) {
  case 0:
    if ((a0[5] & 0x40U) == 0) {
      *param_5 = a0[0x25] + 0x80;
    }
    else {
      *param_5 = a0[0x25];
    }
    uVar2 = 1;
    *param_4 = 0;
    break;
  case 1:
    if ((a0[5] & 0x40U) == 0) {
      *param_5 = a0[0x25] + 0x80;
    }
    else {
      *param_5 = a0[0x25];
    }
    uVar2 = 1;
    *param_4 = 3;
    break;
  case 2:
    uVar2 = 1;
    *param_5 = a0[0x25];
    *param_4 = 2;
    break;
  default:
    uVar2 = 0;
    break;
  case 0xc:
    uVar2 = 1;
    *param_5 = a0[0x25] + 0x700;
    *param_4 = 2;
    break;
  case 0x26:
    callResult = IRInst__getOperandSource(a0,1);
    *param_5 = *(int *)(callResult + 0x14c) << 10;
    callResult = IRInst__getOperandRecord(a0,1);
    callResult = SelectWord__areCompatible(*(undefined4 *)(callResult + 0x10),0);
    if (callResult == 0) {
      callResult = IRInst__getOperandRecord(a0,1);
      callResult = SelectWord__areCompatible(*(undefined4 *)(callResult + 0x10),0x1010101);
      if (callResult == 0) {
        callResult = IRInst__getOperandRecord(a0,1);
        callResult = SelectWord__areCompatible(*(undefined4 *)(callResult + 0x10),0x2020202);
        if (callResult == 0) {
          callResult = IRInst__getOperandRecord(a0,1);
          callResult = SelectWord__areCompatible(*(undefined4 *)(callResult + 0x10),0x3030303);
          if (callResult != 0) {
            iVar3 = *param_5;
            callResult = IRInst__getDefiningField128(a0,0);
            *param_5 = iVar3 + callResult + 0x400;
          }
        }
        else {
          iVar3 = *param_5;
          callResult = IRInst__getDefiningField128(a0,0);
          *param_5 = iVar3 + callResult + 0x300;
        }
      }
      else {
        iVar3 = *param_5;
        callResult = IRInst__getDefiningField128(a0,0);
        *param_5 = iVar3 + callResult + 0x200;
      }
    }
    else {
      iVar3 = *param_5;
      callResult = IRInst__getDefiningField128(a0,0);
      *param_5 = iVar3 + callResult + 0x100;
    }
    uVar2 = 1;
    *param_4 = 2;
    break;
  case 0x28:
    callResult = IRInst__getDefiningField128(inst,operandIndex);
    uVar2 = 1;
    *param_5 = callResult + 0x500;
    *param_4 = 2;
    break;
  case 0x29:
    callResult = IRInst__getDefiningField128(inst,operandIndex);
    uVar2 = 1;
    *param_5 = callResult + 0x600;
    *param_4 = 1;
    break;
  case 0x37:
    uVar2 = 1;
    *param_5 = a0[0x25];
    *param_4 = 1;
  }
  return uVar2;
}

/* R300VSchedModel__vslot4_addInstruction @ 0x1904b8 (528 bytes) */
int R300VSchedModel__vslot4_addInstruction(this, inst)
  int *this;
  int *inst;
{
  int callResult;
  undefined4 sourceSlot;
  int *bankWord;
  int *indexWord;
  
  callResult = (**(code **)(*this + 0x4c))(this,inst);
  if (callResult == 0) {
    return;
  }
  if (callResult == 3) {
    this[7] = *(int *)(inst[0x22] + 8);
    this[6] = *(int *)(inst[0x22] + 8);
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult < 1) {
      return;
    }
    ((int (*)())FUN_00190100)(this,inst,1,this + 8,this + 0xb);
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult < 2) {
      return;
    }
    ((int (*)())FUN_00190100)(this,inst,2,this + 9,this + 0xc);
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult < 3) {
      return;
    }
    sourceSlot = 3;
  }
  else {
    if (callResult != 2) {
      this[6] = *(int *)(inst[0x22] + 8);
      if (inst[0x26] == 1) {
        this[7] = *(int *)(inst[0x22] + 8);
      }
      callResult = (**(code **)(*inst + 0x14))(inst);
      if (callResult < 1) {
        return;
      }
      ((int (*)())FUN_00190100)(this,inst,1,this + 8,this + 0xb);
      callResult = (**(code **)(*inst + 0x14))(inst);
      if (callResult < 2) {
        return;
      }
      sourceSlot = 2;
      bankWord = this + 9;
      indexWord = this + 0xc;
      goto LAB_0019060c;
    }
    this[7] = *(int *)(inst[0x22] + 8);
    if (inst[0x26] != 1) {
      this[6] = *(int *)(inst[0x22] + 8);
    }
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult < 1) {
      return;
    }
    sourceSlot = 1;
  }
  bankWord = this + 10;
  indexWord = this + 0xd;
LAB_0019060c:
  ((int (*)())FUN_00190100)(this,inst,sourceSlot,bankWord,indexWord);
  return;
}

/* R300VSchedModel__vslot3_canAddInstruction @ 0x1906c8 (712 bytes) */
int R300VSchedModel__vslot3_canAddInstruction(this, inst)
  int *this;
  int *inst;
{
  int numSources;
  int resourceClass;
  int callResult;
  undefined4 fits;
  undefined4 in_r5;
  undefined4 in_r6;
  int slot0Bank;
  int slot1Bank;
  int slot2Bank;
  int slot0Index;
  int slot1Index;
  int slot2Index [5];
  
  slot0Bank = this[8];
  slot1Bank = this[9];
  slot2Bank = this[10];
  slot0Index = this[0xb];
  slot1Index = this[0xc];
  slot2Index[0] = this[0xd];
  resourceClass = (**(code **)(*this + 0x4c))
                    (this,inst,in_r5,in_r6,*this,slot2Index[0],slot2Bank,slot1Index);
  if (resourceClass == 0) {
LAB_0019092c:
    fits = 1;
  }
  else {
    if (resourceClass == 3) {
      if ((this[7] < 0) && (this[6] < 0)) {
        numSources = (**(code **)(*inst + 0x14))(inst);
        if (0 < numSources) {
          ((int (*)())FUN_00190100)(this,inst,1,&slot0Bank,&slot0Index);
          numSources = (**(code **)(*inst + 0x14))(inst);
          if (1 < numSources) {
            ((int (*)())FUN_00190100)(this,inst,2,&slot1Bank,&slot1Index);
            numSources = (**(code **)(*inst + 0x14))(inst);
            if (2 < numSources) {
              ((int (*)())FUN_00190100)(this,inst,3,&slot2Bank,slot2Index);
            }
          }
          callResult = ((int (*)())FUN_0018f850)(this,&slot0Bank,&slot0Index,
                               (uint)(*(int *)(inst[0x22] + 8) == 0x14));
          goto joined_r0x00190928;
        }
        goto LAB_0019092c;
      }
    }
    else if (resourceClass == 2) {
      if ((this[7] < 0) && ((this[6] < 0 || (inst[0x26] == 1)))) {
        numSources = (**(code **)(*inst + 0x14))(inst);
        if (0 < numSources) {
          ((int (*)())FUN_00190100)(this,inst,1,&slot2Bank,slot2Index);
          callResult = ((int (*)())FUN_0018f850)(this,&slot0Bank,&slot0Index,0);
joined_r0x00190928:
          if (callResult == 0) goto LAB_00190854;
        }
        goto LAB_0019092c;
      }
    }
    else if ((this[6] < 0) && ((this[7] < 0 || (inst[0x26] != 1)))) {
      numSources = (**(code **)(*inst + 0x14))(inst);
      if (0 < numSources) {
        ((int (*)())FUN_00190100)(this,inst,1,&slot0Bank,&slot0Index);
        numSources = (**(code **)(*inst + 0x14))(inst);
        if (1 < numSources) {
          ((int (*)())FUN_00190100)(this,inst,2,&slot1Bank,&slot1Index);
        }
        callResult = ((int (*)())FUN_0018f850)(this,&slot0Bank,&slot0Index,0);
        goto joined_r0x00190928;
      }
      goto LAB_0019092c;
    }
LAB_00190854:
    fits = 0;
  }
  return fits;
}

/* R300VSchedModel__vslot27 @ 0x190990 (1256 bytes) */
int R300VSchedModel__vslot27(this, inst)
  int this;
  int *inst;
{
  int canonicalMov2;
  int canonicalMov;
  int scanIndex2;
  int scanIndex;
  int nextSeenBank1;
  int seenIndexBank2;
  int seenIndexBank1;
  int levelOffset;
  undefined4 instSrc2Record;
  undefined4 newSrc2Record;
  undefined4 destSelect;
  int destRecord;
  undefined4 src3Record;
  undefined4 src2Record;
  int src1Record;
  undefined4 usedMask;
  int operandRecord;
  int numSources;
  int operandNumber;
  int *operandCursor;
  int supportsAbs;
  void *operandVReg;
  int *target;
  int iVar2;
  uint callResult2;
  undefined4 sourceDef;
  void *callResult;
  void *inst2;
  void *inst3;
  int operandIndex;
  int numSources3;
  int numSources2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int compiler;
  int program;
  undefined4 changed;
  int block;
  int loopIndex;
  int nextSeenBank2;
  int sourceBank;
  int sourceIndex;
  int otherBank;
  int otherIndex;
  uint local_98;
  uint local_94;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c [6];
  
  changed = 0;
  compiler = *(int *)(this + 8);
  block = inst[0x56];
  program = *(int *)(compiler + 0x6c4);
  (**(code **)(**(int **)(compiler + 0x30c) + 0x80))
            (*(int **)(compiler + 0x30c),inst,in_r5,in_r6,in_r7,in_r8,compiler);
  target = *(int **)(*(int *)(this + 8) + 0x30c);
  supportsAbs = (**(code **)(*target + 0x88))(target);
  if (supportsAbs == 0) {
    operandCursor = inst + 0x26;
    for (operandNumber = 1; numSources = (**(code **)(*inst + 0x14))(inst), operandNumber <= numSources;
        operandNumber = operandNumber + 1) {
      if ((operandCursor[8] & 2U) != 0) {
        numSources = OpcodeTraits__flagBit10(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(this + 8));
        if (numSources == 0) {
          sourceDef = IRInst__getOperandSource(inst,operandNumber);
          callResult = IRInst__create(0x17,*(undefined4 *)(this + 8));
          *(undefined4 *)((int)callResult + 0x98) = 0;
          *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
          operandRecord = IRInst__getOperandRecord(inst,operandNumber);
          SelectWord__readMask(&local_68,*(undefined4 *)(operandRecord + 0x10));
          usedMask = local_68;
          SelectWord__selectWhereMasked(&local_64,0,local_68);
          *(undefined4 *)((int)callResult + 0xc) = usedMask;
          *(undefined4 *)((int)callResult + 0x9c) = local_64;
          IROperand__setModifierBits((int)callResult + 0xa4,1,0);
          IROperand__setModifierBits((int)callResult + 0xbc,1,1);
          IRInst__setOperandSource(callResult,1,sourceDef,0,*(undefined4 *)(this + 8));
          IRInst__setOperandSource(callResult,2,sourceDef,0,*(undefined4 *)(this + 8));
          numSources = FUN_00165604(block,callResult);
          if (*(int *)(numSources + 0x158) == 0) {
            *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
            Block__insertInstBefore(block,inst,numSources);
          }
          IRInst__setOperandSource(inst,operandNumber,numSources,0,*(undefined4 *)(this + 8));
        }
        changed = 1;
        IROperand__setModifierBits(operandCursor + 3,2,0);
      }
      operandCursor = operandCursor + 6;
    }
  }
  target = *(int **)(*(int *)(this + 8) + 0x30c);
  callResult2 = (**(code **)(*target + 0x84))(target);
  if ((callResult2 == 0) && (*(int *)(inst[0x22] + 8) == 0x25)) {
    local_98 = callResult2;
    local_94 = callResult2;
    local_84 = callResult2;
    local_80 = callResult2;
    local_7c = callResult2;
    local_6c = callResult2;
    src2Record = IRInst__getOperandRecord(inst,2);
    IROperand__copyFrom(&local_80,src2Record);
    src3Record = IRInst__getOperandRecord(inst,3);
    IROperand__copyFrom(&local_98,src3Record);
    callResult = IRInst__create(0x29,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)callResult + 0x98) = 0;
    *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
    src1Record = IRInst__getOperandRecord(inst,1);
    SelectWord__readMask(&local_60,*(undefined4 *)(src1Record + 0x10));
    SelectWord__selectWhereMasked(&local_5c,0,local_60);
    *(undefined4 *)((int)callResult + 0x9c) = local_5c;
    *(int *)((int)callResult + 0xc) = local_60;
    IRInst__copyOperandFrom(callResult,1,inst,1);
    ((void (*)())IRInst__makeLiteralVec4Float)(callResult,program,2,0.0,0.0,0.0,0.0);
    *(int *)((int)callResult + 0x160) = *(int *)(program + 0x478) + 2;
    Block__insertInstBefore(block,inst,callResult);
    inst2 = IRInst__create(0x12,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)inst2 + 0x98) = 0;
    *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
    destRecord = IRInst__getOperandRecord(callResult,0);
    destSelect = *(undefined4 *)(destRecord + 0x10);
    *(int *)((int)inst2 + 0xc) = local_60;
    *(undefined4 *)((int)inst2 + 0x9c) = destSelect;
    IRInst__setOperandSource(inst2,1,callResult,0,*(undefined4 *)(this + 8));
    IROperand__setModifierBits((int)inst2 + 0xa4,1,1);
    ((void (*)())IRInst__makeLiteralVec4Float)(inst2,program,2,1.0,1.0,1.0,1.0);
    *(int *)((int)inst2 + 0x160) = *(int *)(program + 0x478) + 1;
    Block__insertInstBefore(block,inst,inst2);
    inst3 = IRInst__create(0x13,*(undefined4 *)(this + 8));
    *(undefined4 *)((int)inst3 + 0x98) = 0;
    *(undefined4 *)((int)inst3 + 0x94) = *(undefined4 *)((int)inst3 + 0x14c);
    destRecord = IRInst__getOperandRecord(callResult,0);
    destSelect = *(undefined4 *)(destRecord + 0x10);
    *(int *)((int)inst3 + 0xc) = local_60;
    *(undefined4 *)((int)inst3 + 0x9c) = destSelect;
    IRInst__setOperandSource(inst3,1,callResult,0,*(undefined4 *)(this + 8));
    newSrc2Record = IRInst__getOperandRecord(inst3,2);
    IROperand__copyFrom(newSrc2Record,&local_80);
    *(int *)((int)inst3 + 0x160) = *(int *)(program + 0x478) + 1;
    Block__insertInstBefore(block,inst,inst3);
    levelOffset = inst[0x58] - *(int *)(program + 0x478);
    if (levelOffset < 0) {
      levelOffset = 0;
    }
    DList__unlink(inst);
    IRInst__reinitAsTrinary(inst,0x14,*(undefined4 *)(program + 8));
    inst[0x26] = 0;
    inst[0x25] = inst[0x53];
    iVar2 = IRInst__getOperandRecord(callResult,0);
    iVar2 = *(int *)(iVar2 + 0x10);
    inst[3] = local_60;
    inst[0x27] = iVar2;
    IRInst__setOperandSource(inst,1,inst2,0,*(undefined4 *)(this + 8));
    instSrc2Record = IRInst__getOperandRecord(inst,2);
    IROperand__copyFrom(instSrc2Record,&local_98);
    IRInst__setOperandSource(inst,3,inst3,0,*(undefined4 *)(this + 8));
    inst[0x58] = levelOffset + *(int *)(program + 0x478);
    Block__insertInstAfter(block,inst3,inst);
  }
  loopIndex = 1;
  seenIndexBank1 = -1;
  seenIndexBank2 = -1;
  do {
    numSources2 = (**(code **)(*inst + 0x14))(inst);
    if (numSources2 < loopIndex) {
      return changed;
    }
    sourceDef = IRInst__getOperandSource(inst,loopIndex);
    operandIndex = ((int (*)())FUN_00190100)(this,inst,loopIndex,&sourceBank,&sourceIndex);
    nextSeenBank1 = seenIndexBank1;
    nextSeenBank2 = seenIndexBank2;
    if (operandIndex != 0) {
      if (sourceBank == 2) {
        nextSeenBank2 = sourceIndex;
        if ((seenIndexBank2 < 0) || (seenIndexBank2 == sourceIndex)) goto code_r0x0019125c;
        callResult = IRInst__create(0x31,*(undefined4 *)(this + 8));
        *(undefined4 *)((int)callResult + 0x98) = 0;
        *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
        IRInst__setOperandSource(callResult,1,sourceDef,0,*(undefined4 *)(this + 8));
        local_98 = 0;
        for (scanIndex = 1; operandIndex = (**(code **)(*inst + 0x14))(inst), scanIndex <= operandIndex;
            scanIndex = scanIndex + 1) {
          operandIndex = ((int (*)())FUN_00190100)(this,inst,scanIndex,&otherBank,&otherIndex);
          if (((operandIndex != 0) && (otherBank == sourceBank)) && (otherIndex == sourceIndex)) {
            operandIndex = IRInst__getOperandRecord(inst,scanIndex);
            SelectWord__readMask(&local_58,*(undefined4 *)(operandIndex + 0x10));
            local_98 = local_58 | local_98;
            IRInst__setOperandSource(inst,scanIndex,callResult,0,*(undefined4 *)(this + 8));
          }
        }
        operandIndex = 1;
        SelectWord__selectWhereMasked(&local_54,0,local_98);
        *(undefined4 *)((int)callResult + 0x9c) = local_54;
        *(uint *)((int)callResult + 0xc) = local_98;
        canonicalMov = FUN_00165604(block,callResult);
        if (*(int *)(canonicalMov + 0x158) == 0) {
          changed = 1;
          *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
          Block__insertInstBefore(block,inst,canonicalMov);
        }
        else {
          for (; numSources3 = (**(code **)(*inst + 0x14))(inst), operandIndex <= numSources3; operandIndex = operandIndex + 1)
          {
            operandVReg = (void *)IRInst__getOperandSource(inst,operandIndex);
            if (callResult == operandVReg) {
              IRInst__setOperandSource(inst,operandIndex,canonicalMov,0,*(undefined4 *)(this + 8));
            }
          }
          changed = 1;
        }
      }
      nextSeenBank2 = seenIndexBank2;
      if (((sourceBank == 1) && (nextSeenBank1 = sourceIndex, -1 < seenIndexBank1)) && (seenIndexBank1 != sourceIndex)) {
        callResult = IRInst__create(0x31,*(undefined4 *)(this + 8));
        *(undefined4 *)((int)callResult + 0x98) = 0;
        *(undefined4 *)((int)callResult + 0x94) = *(undefined4 *)((int)callResult + 0x14c);
        IRInst__setOperandSource(callResult,1,sourceDef,0,*(undefined4 *)(this + 8));
        local_98 = 0;
        for (scanIndex2 = 1; nextSeenBank2 = (**(code **)(*inst + 0x14))(inst), scanIndex2 <= nextSeenBank2;
            scanIndex2 = scanIndex2 + 1) {
          otherBank = 4;
          nextSeenBank2 = ((int (*)())FUN_00190100)(this,inst,scanIndex2,&otherBank,&otherIndex);
          if (((nextSeenBank2 != 0) && (otherBank == sourceBank)) && (otherIndex == sourceIndex)) {
            nextSeenBank2 = IRInst__getOperandRecord(inst,scanIndex2);
            SelectWord__readMask(&local_50,*(undefined4 *)(nextSeenBank2 + 0x10));
            local_98 = local_50 | local_98;
            IRInst__setOperandSource(inst,scanIndex2,callResult,0,*(undefined4 *)(this + 8));
          }
        }
        scanIndex = 1;
        SelectWord__selectWhereMasked(local_4c,0,local_98);
        *(undefined4 *)((int)callResult + 0x9c) = local_4c[0];
        *(uint *)((int)callResult + 0xc) = local_98;
        canonicalMov2 = FUN_00165604(block,callResult);
        if (*(int *)(canonicalMov2 + 0x158) == 0) {
          changed = 1;
          *(int *)(program + 0x238) = *(int *)(program + 0x238) + 1;
          Block__insertInstBefore(block,inst,canonicalMov2);
          nextSeenBank1 = seenIndexBank1;
          nextSeenBank2 = seenIndexBank2;
        }
        else {
          for (; operandIndex = (**(code **)(*inst + 0x14))(inst), scanIndex <= operandIndex;
              scanIndex = scanIndex + 1) {
            operandVReg = (void *)IRInst__getOperandSource(inst,scanIndex);
            if (callResult == operandVReg) {
              IRInst__setOperandSource(inst,scanIndex,canonicalMov2,0,*(undefined4 *)(this + 8));
            }
          }
          changed = 1;
          nextSeenBank1 = seenIndexBank1;
          nextSeenBank2 = seenIndexBank2;
        }
      }
    }
code_r0x0019125c:
    loopIndex = loopIndex + 1;
    seenIndexBank1 = nextSeenBank1;
    seenIndexBank2 = nextSeenBank2;
  } while( true );
}

/* R300VSchedModel__vslot19 @ 0x191298 (724 bytes) */
int R300VSchedModel__vslot19(this, inst)
  int this;
  int *inst;
{
  int isUndefined;
  int flagBit0Result;
  int src2Record;
  int src3Select;
  int src3Record;
  int operandNumber;
  int numSources;
  int flagBit2Result;
  int schedulerAllocRegEnabled;
  int iVar1;
  int numSources2;
  int *callResult;
  int *callResult2;
  int *operandVReg;
  
  if ((inst[5] & 0x8000U) != 0) {
    return 0;
  }
  flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(inst[0x22] + 8),*(undefined4 *)(this + 8));
  if (flagBit2Result == 0) {
    numSources = (**(code **)(*inst + 0x14))(inst);
    if ((numSources < 3) && (*(int *)(inst[0x22] + 8) != 0x32)) {
      return 1;
    }
  }
  else {
    iVar1 = IRInst__countWrittenComponents(inst);
    if (((iVar1 < 2) && (iVar1 = *(int *)(inst[0x22] + 8), iVar1 != 0xa5)) &&
       (((*(uint *)(*(int *)(*(int *)(this + 8) + 0x30c) + 8) & 0x10000) != 0 ||
        ((iVar1 != 0x4c && (iVar1 != 0x4d)))))) {
      for (operandNumber = 0; numSources2 = (**(code **)(*inst + 0x14))(inst), operandNumber <= numSources2;
          operandNumber = operandNumber + 1) {
        numSources2 = FUN_00105dbc(inst,operandNumber);
        if (numSources2 != 0) {
          return 3;
        }
      }
      numSources = (**(code **)(*inst + 0x14))(inst);
      if (1 < numSources) {
        callResult = (int *)IRInst__getOperandSource(inst,1);
        callResult2 = (int *)IRInst__getOperandSource(inst,2);
        numSources = (**(code **)(*inst + 0x14))(inst);
        if (2 < numSources) {
          operandVReg = (int *)IRInst__getOperandSource(inst,3);
          if (callResult2 != operandVReg) {
            return 3;
          }
          src3Record = IRInst__getOperandRecord(inst,3);
          src3Select = *(int *)(src3Record + 0x10);
          src2Record = IRInst__getOperandRecord(inst,2);
          if (src3Select != *(int *)(src2Record + 0x10)) {
            return 3;
          }
          if ((inst[0x3a] & 1U) != (inst[0x34] & 1U)) {
            return 3;
          }
        }
        if (callResult != callResult2) {
          if (callResult[0x20] == 0) {
            return 3;
          }
          flagBit0Result = RegKind__flagBit0(callResult[0x26]);
          if (flagBit0Result == 0) {
            return 3;
          }
          if ((callResult[5] & 2U) != 0) {
            return 3;
          }
          isUndefined = (**(code **)(*callResult + 0x50))(callResult);
          if (isUndefined != 0) {
            return 3;
          }
          if (callResult2[0x20] == 0) {
            return 3;
          }
          flagBit0Result = RegKind__flagBit0(callResult2[0x26]);
          if (flagBit0Result == 0) {
            return 3;
          }
          if ((callResult2[5] & 2U) != 0) {
            return 3;
          }
          isUndefined = (**(code **)(*callResult2 + 0x50))(callResult2);
          if (isUndefined != 0) {
            return 3;
          }
          if (callResult[0x26] != callResult2[0x26]) {
            return 3;
          }
          if (((callResult[5] & 0x40U) != 0) && ((callResult2[5] & 0x40U) != 0)) {
            if (callResult[0x25] != callResult2[0x25]) {
              return 3;
            }
            return 2;
          }
          schedulerAllocRegEnabled = Compiler__isOptionEnabled(*(undefined4 *)(this + 8),0x25);
          if (schedulerAllocRegEnabled == 0) {
            return 3;
          }
          if ((callResult[5] & 0x20U) != 0) {
            return 3;
          }
          if ((callResult2[5] & 0x20U) != 0) {
            return 3;
          }
          return 2;
        }
      }
      return 2;
    }
  }
  return 3;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0018843c");
asm(".set FUN_0018843c, _KhanPs__peepholeCombine");
asm(".globl FUN_00188e24");
asm(".set FUN_00188e24, _KhanPs__vslot27_optimizeInstruction");
asm(".globl FUN_00188f24");
asm(".set FUN_00188f24, _KhanVs__vslot29_swapIfArmsWhenNotFlattenable");
asm(".globl FUN_00188fec");
asm(".set FUN_00188fec, _KhanVs__peepholeCombine");
asm(".globl FUN_001894ec");
asm(".set FUN_001894ec, _KhanVs__vslot27_optimizeInstruction");
asm(".globl FUN_00189604");
asm(".set FUN_00189604, _R520SchedModel__vslot2_reset");
asm(".globl FUN_0018962c");
asm(".set FUN_0018962c, _KhanPs__vslot31_isNotTextureFetch");
asm(".globl FUN_00189660");
asm(".set FUN_00189660, _KhanPs__vslot65_isEncodableSourceSwizzle");
asm(".globl FUN_001896f8");
asm(".set FUN_001896f8, _SelectWord__isDefaultAfterCanonicalise");
asm(".globl FUN_001897f0");
asm(".set FUN_001897f0, _KhanPs__vslot66_callHelper189788");
asm(".globl FUN_00189be4");
asm(".set FUN_00189be4, _R300SchedModel__vslot15");
asm(".globl FUN_00189fd4");
asm(".set FUN_00189fd4, _R300SchedModel__vslot19");
asm(".globl FUN_0018a080");
asm(".set FUN_0018a080, _R300SchedModel__vslot34");
asm(".globl FUN_0018a1ec");
asm(".set FUN_0018a1ec, _R300SchedModel__vslot26");
asm(".globl FUN_0018a440");
asm(".set FUN_0018a440, _R300SchedModel__vslot28");
asm(".globl FUN_0018ad08");
asm(".set FUN_0018ad08, _R300SchedModel__vslot16");
asm(".globl FUN_0018b654");
asm(".set FUN_0018b654, _R300SchedModel__vslot11");
asm(".globl FUN_0018b9cc");
asm(".set FUN_0018b9cc, _R300SchedModel__vslot14");
asm(".globl FUN_0018dabc");
asm(".set FUN_0018dabc, _R300SchedModel__tryRewriteConsumerSelects");
asm(".globl FUN_0018e1a8");
asm(".set FUN_0018e1a8, _R300SchedModel__legalizeInstruction");
asm(".globl FUN_0018f42c");
asm(".set FUN_0018f42c, _R520SchedModel__vslot4_addInstruction");
asm(".globl FUN_0018f55c");
asm(".set FUN_0018f55c, _R520SchedModel__vslot3_canAddInstruction");
asm(".globl FUN_0018f674");
asm(".set FUN_0018f674, _R300SchedModel__vslot12");
asm(".globl FUN_0018f824");
asm(".set FUN_0018f824, _R300VSchedModel__vslot2_reset");
asm(".globl FUN_0018f918");
asm(".set FUN_0018f918, _R300VSchedModel__vslot13");
asm(".globl FUN_0018f984");
asm(".set FUN_0018f984, _R300VSchedModel__vslot28");
asm(".globl FUN_0018fbd8");
asm(".set FUN_0018fbd8, _R300VSchedModel__vslot14");
asm(".globl FUN_0018fd34");
asm(".set FUN_0018fd34, _R300VSchedModel__vslot17");
asm(".globl FUN_001904b8");
asm(".set FUN_001904b8, _R300VSchedModel__vslot4_addInstruction");
asm(".globl FUN_001906c8");
asm(".set FUN_001906c8, _R300VSchedModel__vslot3_canAddInstruction");
asm(".globl FUN_00190990");
asm(".set FUN_00190990, _R300VSchedModel__vslot27");
asm(".globl FUN_00191298");
asm(".set FUN_00191298, _R300VSchedModel__vslot19");
