#include "decls.h"

/* FUN_00176ed4 @ 0x176ed4 (56 bytes) */
int FUN_00176ed4(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int findInPtrSetResult;
  
  uVar1 = 0;
  if (0 < param_2) {
    findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(param_1 + 0x238),param_2);
    uVar1 = *(undefined4 *)(findInPtrSetResult + 0xc);
  }
  return uVar1;
}

/* FUN_00176f0c @ 0x176f0c (56 bytes) */
int FUN_00176f0c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int findInPtrSetResult;
  
  uVar1 = 0;
  if (0 < param_2) {
    findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(param_1 + 0x238),param_2);
    uVar1 = *(undefined4 *)(findInPtrSetResult + 0x10);
  }
  return uVar1;
}

/* FUN_00176f44 @ 0x176f44 (144 bytes) */
int FUN_00176f44(ctx, param_2, param_3)
  int ctx;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  undefined4 *loopPtr2;
  undefined4 *loopPtr3;
  
  loopPtr2 = (undefined4 *)(param_2 * 0x10 + ctx + 0x168);
  loopPtr3 = (undefined4 *)(param_3 * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176d6c(*loopPtr2,*loopPtr3,*(undefined4 *)(ctx + 0x238)), iVar2 != 0))) {
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00176fd4 @ 0x176fd4 (144 bytes) */
int FUN_00176fd4(ctx, param_2, param_3)
  int ctx;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  undefined4 *loopPtr2;
  undefined4 *loopPtr3;
  
  loopPtr2 = (undefined4 *)(param_2 * 0x10 + ctx + 0x168);
  loopPtr3 = (undefined4 *)(param_3 * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176e20(*loopPtr2,*loopPtr3,*(undefined4 *)(ctx + 0x238)), iVar2 != 0))) {
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* Inst__writtenLanesAllMatchValue @ 0x177064 (128 bytes) */
int Inst__writtenLanesAllMatchValue(valueKey, value, row)
  int valueKey;
  int value;
  int row;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  int *loopPtr2;
  
  loopPtr2 = (int *)(row * 0x10 + valueKey + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(valueKey + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' || (*loopPtr2 == value))) {
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001770e4 @ 0x1770e4 (204 bytes) */
int FUN_001770e4(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int operandRecord;
  undefined4 *exprRecord;
  int iVar6;
  int loopIndex;
  int *loopPtr2;
  
  iVar6 = 0;
  bVar1 = false;
  bVar2 = true;
  loopPtr2 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(param_2 + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if (bVar2) {
        iVar6 = *loopPtr2;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*loopPtr2 != iVar6) goto LAB_00177184;
    }
    bVar3 = loopIndex != 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
  } while (bVar3);
  if (bVar1) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar6);
    *param_1 = *exprRecord;
  }
  else {
LAB_00177184:
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_001771b0 @ 0x1771b0 (236 bytes) */
int FUN_001771b0(param_1)
  int *param_1;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  float *exprRecord;
  int iVar4;
  int loopIndex;
  int *loopPtr2;
  
  loopIndex = 0;
  loopPtr2 = param_1;
  do {
    operandRecord = IRInst__getOperandRecord(param_1[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if ((float *)loopPtr2[0xc] == (float *)0x0) {
        iVar2 = *loopPtr2;
        if (iVar2 < 0) {
          exprRecord = (float *)Compiler__exprRecordForValueNumber(param_1[0x8e],iVar2);
          iVar2 = ((undefined4 (*)())classifyConstantRange)((double)*exprRecord);
        }
        else {
          iVar4 = loopPtr2[0x10];
          if (iVar4 == 0) {
            if (iVar2 < 1) {
              iVar2 = 0;
              goto LAB_00177254;
            }
            iVar4 = Compiler__findInPtrSet(param_1[0x8e],iVar2);
          }
          iVar2 = *(int *)(iVar4 + 0x10);
        }
      }
      else {
        iVar2 = ((undefined4 (*)())classifyConstantRange)((double)*(float *)loopPtr2[0xc]);
      }
LAB_00177254:
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        loopPtr2[0x14] = iVar2;
      }
      else {
        loopPtr2[0x14] = (DAT_001e6158)[iVar2];
      }
    }
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0017729c @ 0x17729c (224 bytes) */
int FUN_0017729c(param_1)
  int *param_1;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int loopIndex;
  int *loopPtr2;
  
  loopIndex = 0;
  loopPtr2 = param_1;
  do {
    operandRecord = IRInst__getOperandRecord(param_1[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      puVar3 = (undefined4 *)loopPtr2[0xc];
      if (puVar3 == (undefined4 *)0x0) {
        iVar2 = *loopPtr2;
        if (iVar2 < 0) {
          puVar3 = (undefined4 *)Compiler__exprRecordForValueNumber(param_1[0x8e],iVar2);
          goto LAB_00177304;
        }
        iVar4 = loopPtr2[0x10];
        if (iVar4 == 0) {
          if (0 < iVar2) {
            iVar4 = Compiler__findInPtrSet(param_1[0x8e],iVar2);
            goto LAB_00177330;
          }
          iVar2 = 0;
        }
        else {
LAB_00177330:
          iVar2 = *(int *)(iVar4 + 0xc);
        }
      }
      else {
LAB_00177304:
        iVar2 = signToCompareCode(*puVar3);
      }
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        loopPtr2[0x20] = iVar2;
      }
      else {
        loopPtr2[0x20] = (DAT_001e61a0)[iVar2];
      }
    }
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0017737c @ 0x17737c (144 bytes) */
int FUN_0017737c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  int *loopPtr2;
  int *loopPtr3;
  
  loopPtr2 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  loopPtr3 = (int *)(param_3 * 0x10 + param_1 + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' || (*loopPtr2 == *loopPtr3))) {
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_0017740c @ 0x17740c (156 bytes) */
undefined4 FUN_0017740c(int ctx,int param_2,double fparam_1)
{
  bool bVar1;
  int exprRecord;
  int iVar3;
  int *loopPtr2;
  int loopIndex;
  
  loopPtr2 = (int *)(param_2 * 0x10 + ctx + 0x168);
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),GH_F2U((float)fparam_1));
  loopIndex = 0;
  while ((iVar3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar3 + 0x10) == '\x01' || (*loopPtr2 == *(int *)(exprRecord + 4)))) {
    bVar1 = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00177548 @ 0x177548 (144 bytes) */
int FUN_00177548(ctx)
  int ctx;
{
  bool bVar1;
  int operandRecord;
  int loopIndex;
  
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) == '\0') {
      *(undefined1 *)(loopIndex + *(int *)(ctx + 0xb0) + 0x9c) = 1;
    }
    bVar1 = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = *(int *)(ctx + 0xb0);
  if ((*(uint *)(loopIndex + 0x14) & 0x200) == 0) {
    IRInst__appendSource(loopIndex,*(undefined4 *)(loopIndex + 0x8c));
    return;
  }
  return;
}

/* FUN_001775d8 @ 0x1775d8 (224 bytes) */
int FUN_001775d8(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  inst = *(int *)(ctx + 0xb0);
  if ((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) {
    if (((*(uint *)(inst + 0xb8) & 2) == 0) && ((*(uint *)(inst + 0xb8) & 1) != 0)) {
      loopIndex = 0;
      iVar4 = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
          iVar2 = *(int *)(iVar4 + 0x40);
          if (iVar2 == 0) {
            iVar2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
            *(int *)(iVar4 + 0x40) = iVar2;
          }
          *(int *)(iVar2 + 4) = ctx;
          *(int *)(*(int *)(iVar4 + 0x40) + 8) = loopIndex;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x20) = 1;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x24) = *(undefined4 *)(iVar4 + 0x178);
        }
        bVar1 = loopIndex == 3;
        iVar4 = iVar4 + 4;
        loopIndex = loopIndex + 1;
        if (bVar1) break;
        inst = *(int *)(ctx + 0xb0);
      }
    }
  }
  return;
}

/* FUN_001776b8 @ 0x1776b8 (144 bytes) */
int FUN_001776b8(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int callResult;
  undefined4 exprRecord;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_2 * 4 + ctx;
  callResult = FUN_00176ec0(ctx,*(undefined4 *)(iVar5 + 0x178),*(undefined4 *)(iVar5 + 0x188));
  if (callResult != 0) {
    uVar4 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar4 & 1)) && ((uVar1 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
      *(undefined4 *)(iVar5 + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* FUN_00177748 @ 0x177748 (408 bytes) */
int FUN_00177748(ctx)
  int ctx;
{
  int prevLaneClass;
  int condition;
  int findInPtrSetResult;
  bool laneFlag;
  uint operandFlags;
  int callResult;
  int *hwLimits;
  int conditionSupported;
  int operandRecord;
  undefined4 *exprRecord;
  int laneClass;
  int loopIndex;
  int laneEntryPtr;
  float compareConstOut [2];
  float compareConst;
  
  callResult = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
  ((int (*)())FUN_001770e4)(compareConstOut,ctx,2);
  compareConst = compareConstOut[0];
  if ((compareConstOut[0] == FLOAT_001aa0d4) &&
     (hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c),
     conditionSupported = (**(code **)(*hwLimits + 0x2c))(hwLimits,callResult), conditionSupported == 0)) {
    loopIndex = 0;
    prevLaneClass = 0;
    laneEntryPtr = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      laneClass = prevLaneClass;
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        laneClass = *(int *)(laneEntryPtr + 0x178);
        if (laneClass < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneClass);
          laneClass = signToCompareCode(*exprRecord);
        }
        else {
          if (laneClass < 1) {
            return;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),laneClass);
          laneClass = *(int *)(findInPtrSetResult + 0xc);
          operandFlags = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
          if ((operandFlags & 2) != 0) {
            laneClass = (DAT_001e61d0)[laneClass];
          }
          if ((operandFlags & 1) != 0) {
            laneClass = *(int *)(&DAT_001e61b8 + laneClass * 4);
          }
        }
        if (laneClass == 0) {
          return;
        }
        if ((prevLaneClass != 0) && (laneFlag = laneClass != prevLaneClass, laneClass = prevLaneClass, laneFlag)) {
          return;
        }
      }
      laneFlag = loopIndex != 3;
      laneEntryPtr = laneEntryPtr + 4;
      loopIndex = loopIndex + 1;
      prevLaneClass = laneClass;
    } while (laneFlag);
    hwLimits = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    condition = (**(code **)(*hwLimits + 0x30))(hwLimits,callResult,laneClass);
    if (callResult != condition) {
      IRInst__setCompareCondition(*(undefined4 *)(ctx + 0xb0),condition);
      return;
    }
  }
  return;
}

/* FUN_001778e0 @ 0x1778e0 (272 bytes) */
int FUN_001778e0(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int loopIndex;
  double dVar6;
  
  inst = *(int *)(ctx + 0xb0);
  if ((((*(int *)(inst + 0x120) == 0) && ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
      ((*(uint *)(inst + 0xb8) & 2) == 0)) && (*(int *)(inst + 0x124) != 0)) {
    loopIndex = 0;
    iVar4 = ctx;
    while( true ) {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
        if (*(int *)(iVar4 + 0x40) == 0) {
          uVar3 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
          *(undefined4 *)(iVar4 + 0x40) = uVar3;
        }
        iVar2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        *(int *)(iVar4 + 0x40) = iVar2;
        *(int *)(iVar2 + 4) = ctx;
        *(int *)(*(int *)(iVar4 + 0x40) + 8) = loopIndex;
        *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x14) = 1;
        *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x18) = *(undefined4 *)(iVar4 + 0x178);
        iVar2 = *(int *)(iVar4 + 0x40);
        dVar6 = (double)((double (*)())outputScaleFromExponent)(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124));
        *(float *)(iVar2 + 0x1c) = (float)dVar6;
      }
      bVar1 = loopIndex == 3;
      iVar4 = iVar4 + 4;
      loopIndex = loopIndex + 1;
      if (bVar1) break;
      inst = *(int *)(ctx + 0xb0);
    }
  }
  return;
}

/* FUN_001779f0 @ 0x1779f0 (224 bytes) */
int FUN_001779f0(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  inst = *(int *)(ctx + 0xb0);
  if ((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) {
    if (((*(uint *)(inst + 0xb8) & 1) == 0) && ((*(uint *)(inst + 0xb8) & 2) == 0)) {
      loopIndex = 0;
      iVar4 = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
          iVar2 = *(int *)(iVar4 + 0x40);
          if (iVar2 == 0) {
            iVar2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
            *(int *)(iVar4 + 0x40) = iVar2;
          }
          *(int *)(iVar2 + 4) = ctx;
          *(int *)(*(int *)(iVar4 + 0x40) + 8) = loopIndex;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x28) = 1;
          *(undefined4 *)(*(int *)(iVar4 + 0x40) + 0x2c) = *(undefined4 *)(iVar4 + 0x178);
        }
        bVar1 = loopIndex == 3;
        iVar4 = iVar4 + 4;
        loopIndex = loopIndex + 1;
        if (bVar1) break;
        inst = *(int *)(ctx + 0xb0);
      }
    }
  }
  return;
}

/* ValueKey__cancelNegatedSourcePair @ 0x177ad0 (124 bytes) */
int ValueKey__cancelNegatedSourcePair(ctx)
  int ctx;
{
  int member0xb0;
  undefined4 uVar2;
  
  member0xb0 = *(int *)(ctx + 0xb0);
  if (((*(uint *)(member0xb0 + 0xb8) & 1) == 0) || ((*(uint *)(member0xb0 + 0xd0) & 1) == 0)) {
    uVar2 = 0;
  }
  else {
    IROperand__setModifierBits(member0xb0 + 0xa4,1,0);
    IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xbc,1,0);
    ValueKey__rebuild(ctx);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00177b4c @ 0x177b4c (388 bytes) */
int FUN_00177b4c(ctx, operandIndex, param_3)
  int ctx;
  int operandIndex;
  int param_3;
{
  int operandRecord;
  int callResult;
  int iVar2;
  undefined4 uVar3;
  undefined4 block;
  int iVar5;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar5 = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_3 + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar3;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + iVar5 + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + iVar5 + 0x20) & 1);
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(param_3 + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    IRInst__appendSource(iVar2,*(undefined4 *)(iVar2 + 0x8c));
    iVar2 = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,iVar2,callResult);
  return callResult;
}

/* FUN_00177cd0 @ 0x177cd0 (324 bytes) */
int FUN_00177cd0(ctx, param_2, param_3)
  int ctx;
  int param_2;
  int param_3;
{
  int operandRecord;
  int callResult;
  int iVar2;
  undefined4 uVar3;
  undefined4 block;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x98) = 0;
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(param_2 + 0xc));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar3;
  if (*(int *)(param_2 + 0x18) != 0) {
    IROperand__setModifierBits(callResult + 0xa4,1,1);
  }
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(param_3 + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    IRInst__appendSource(iVar2,*(undefined4 *)(iVar2 + 0x8c));
    iVar2 = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,iVar2,callResult);
  return callResult;
}

/* FUN_00177e14 @ 0x177e14 (528 bytes) */
int FUN_00177e14(ctx, opcode, operandIndex, operandIndex2, param_5)
  int ctx;
  undefined4 opcode;
  int operandIndex;
  int operandIndex2;
  int param_5;
{
  int operandRecord;
  undefined *puVar1;
  int callResult;
  int iVar3;
  undefined4 uVar4;
  undefined4 block;
  int iVar6;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(opcode,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b64 + param_5 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar4;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar6 = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  puVar1 = PTR_DAT_001e8b8c;
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_5 + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar4;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) & 1);
  iVar6 = operandIndex2 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,2,*(undefined4 *)(operandIndex2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex2);
  uVar4 = *(undefined4 *)(puVar1 + (uint)*(byte *)(param_5 + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,2);
  *(undefined4 *)(operandRecord + 0x10) = uVar4;
  IROperand__setModifierBits(callResult + 0xbc,2,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xbc,1,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) & 1);
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120);
  *(undefined4 *)(callResult + 0x124) = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(param_5 + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  iVar3 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar3 + 0x14) & 0x200) == 0) {
    IRInst__appendSource(iVar3,*(undefined4 *)(iVar3 + 0x8c));
    iVar3 = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,iVar3,callResult);
  return callResult;
}

/* FUN_00178024 @ 0x178024 (384 bytes) */
int FUN_00178024(ctx, operandIndex, param_3, param_4)
  int ctx;
  int operandIndex;
  int param_3;
  undefined4 param_4;
{
  int operandRecord;
  int callResult;
  int iVar2;
  undefined4 uVar3;
  undefined4 block;
  int iVar5;
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar5 = operandIndex * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_3 + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar3;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + iVar5 + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + iVar5 + 0x20) & 1);
  iVar2 = *(int *)(ctx + 0xb0);
  *(undefined4 *)(callResult + 0x124) = param_4;
  *(undefined4 *)(callResult + 0x120) = *(undefined4 *)(iVar2 + 0x120);
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(param_3 + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  iVar2 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar2 + 0x14) & 0x200) == 0) {
    IRInst__appendSource(iVar2,*(undefined4 *)(iVar2 + 0x8c));
    iVar2 = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,iVar2,callResult);
  return callResult;
}

/* FUN_001781a4 @ 0x1781a4 (404 bytes) */
int FUN_001781a4(param_1, valueKey, param_3)
  float *param_1;
  int valueKey;
  undefined4 *param_3;
{
  int instFlagBit2Result;
  undefined4 *loopPtr2;
  int iVar2;
  int *loopPtr;
  int iVar4;
  int loopRemaining;
  undefined4 local_68 [6];
  int local_50 [6];
  float local_38;
  float local_34 [2];
  
  loopRemaining = 5;
  *param_1 = GH_U2F(0x7fff0000U);
  loopPtr2 = local_68;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopPtr = local_50;
  iVar4 = 4;
  for (loopRemaining = 1;
      iVar2 = (**(code **)(**(int **)(valueKey + 0xb0) + 0x14))(*(int **)(valueKey + 0xb0)),
      loopRemaining <= iVar2; loopRemaining = loopRemaining + 1) {
    instFlagBit2Result = OpcodeTraits__instFlagBit2(*(undefined4 *)(valueKey + 0x238),*(undefined4 *)(valueKey + 0xb0));
    if (instFlagBit2Result == 0) {
      *loopPtr = 0;
    }
    else if (loopRemaining == 2) {
      local_50[1] = 0;
    }
    else if (loopRemaining == 3) {
      local_50[2] = 1;
    }
    else if (loopRemaining == 1) {
      local_50[0] = 3;
    }
    iVar2 = *loopPtr;
    loopPtr = loopPtr + 1;
    loopPtr2 = (undefined4 *)
             Compiler__exprRecordForValueNumber(*(undefined4 *)(valueKey + 0x238),
                          *(undefined4 *)((iVar4 + iVar2) * 4 + valueKey + 0x168));
    *(undefined4 *)(iVar4 + (int)local_68) = *loopPtr2;
    iVar4 = iVar4 + 4;
  }
  loopPtr = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  (**(code **)(*loopPtr + 4))(loopPtr,param_1,local_68,*(undefined4 *)(valueKey + 0x238));
  if (*param_1 != 2.1474836e+09) {
    IRInst__scaleByOutputScale(&local_38,*(undefined4 *)(valueKey + 0xb0),*param_1);
    *param_1 = local_38;
    IRInst__clampOutputValue(local_34,*(undefined4 *)(valueKey + 0xb0),local_38);
    if (local_34[0] != *param_1) {
      *param_3 = 1;
      *param_1 = local_34[0];
    }
  }
  return param_1;
}

/* FUN_00178338 @ 0x178338 (656 bytes) */
int FUN_00178338(ctx, lane, clampFlagsOut)
  int ctx;
  int lane;
  int clampFlagsOut;
{
  int valueNumber;
  int resultClass;
  int laneNode;
  int keyInst;
  int findInPtrSetResult;
  int laneByteOffset;
  uint operandFlags;
  float *exprRecord;
  int operandCount;
  int operandRecAddr;
  int operandRecOffset;
  int operandNumber;
  int *valueNumberPtr;
  int *loopPtr;
  int operandClass [9];
  
  laneByteOffset = lane * 4;
  if (*(int *)(laneByteOffset + ctx + 0x30) == 0) {
    valueNumberPtr = (int *)(laneByteOffset + ctx + 0x178);
    loopPtr = operandClass;
    operandRecOffset = 0x98;
    for (operandNumber = 1;
        operandCount = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        operandNumber <= operandCount; operandNumber = operandNumber + 1) {
      valueNumber = *valueNumberPtr;
      if (valueNumber < 0) {
        exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = ((undefined4 (*)())classifyConstantRange)((double)*exprRecord);
        *loopPtr = valueNumber;
      }
      else if (valueNumber < 1) {
        *loopPtr = 0;
      }
      else {
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = *(int *)(findInPtrSetResult + 0x10);
        *loopPtr = valueNumber;
        operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
        operandFlags = *(uint *)(operandRecAddr + 0x20);
        if ((operandFlags & 2) != 0) {
          *loopPtr = *(int *)(&DAT_001e6188 + valueNumber * 4);
          operandFlags = *(uint *)(operandRecAddr + 0x20);
        }
        if ((operandFlags & 1) != 0) {
          *loopPtr = *(int *)(&DAT_001e6170 + *loopPtr * 4);
        }
      }
      operandRecOffset = operandRecOffset + 0x18;
      loopPtr = loopPtr + 1;
      valueNumberPtr = valueNumberPtr + 4;
    }
    keyInst = *(int *)(ctx + 0xb0);
    switch(*(undefined4 *)(*(int *)(keyInst + 0x88) + 8)) {
    case 0x12:
      operandClass[0] = *(int *)(&DAT_001e5bf4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x13:
      operandClass[0] = *(int *)(&DAT_001e5ad4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    default:
      operandClass[0] = 0;
      break;
    case 0x17:
      operandClass[0] = *(int *)(&DAT_001e5a44 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x19:
      operandClass[0] = *(int *)(&DAT_001e59b4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      operandClass[0] = *(int *)(&DAT_001e5b64 + (operandClass[1] * 6 + operandClass[2]) * 4);
      break;
    case 0x31: ;
    }
    if ((0 < *(int *)(keyInst + 0x124)) && (operandClass[0] != 2)) {
      operandClass[0] = 0;
    }
    resultClass = operandClass[0];
    if (*(int *)(keyInst + 0x120) != 0) {
      resultClass = (DAT_001e6158)[operandClass[0]];
      if (operandClass[0] == resultClass) {
        *(undefined4 *)(laneByteOffset + clampFlagsOut) = 0;
        resultClass = operandClass[0];
      }
      else {
        *(undefined4 *)(laneByteOffset + clampFlagsOut) = 1;
      }
    }
    laneNode = *(int *)(laneByteOffset + ctx + 0x40);
    if (laneNode == 0) {
      laneNode = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),lane,ctx);
      *(int *)(laneByteOffset + ctx + 0x40) = laneNode;
    }
    *(int *)(laneNode + 0x10) = resultClass;
  }
  return;
}

/* FUN_00178648 @ 0x178648 (708 bytes) */
int FUN_00178648(ctx, lane)
  int ctx;
  int lane;
{
  int valueNumber;
  int laneEntryPtr2;
  int laneNode;
  int resultClass;
  int operandRecOffset;
  int findInPtrSetResult;
  uint operandFlags;
  int laneEntryPtr;
  undefined4 *exprRecord;
  int operandCount;
  int operandRecAddr;
  int operandRecOffset2;
  int operandNumber;
  int *valueNumberPtr;
  int *loopPtr;
  int operandClass [9];
  
  laneEntryPtr = lane * 4 + ctx;
  if (*(int *)(laneEntryPtr + 0x30) == 0) {
    valueNumberPtr = (int *)(laneEntryPtr + 0x178);
    loopPtr = operandClass;
    operandRecOffset = 0x98;
    operandRecOffset2 = 0x98;
    for (operandNumber = 1;
        operandCount = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        operandNumber <= operandCount; operandNumber = operandNumber + 1) {
      valueNumber = *valueNumberPtr;
      if (valueNumber < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
        valueNumber = signToCompareCode(*exprRecord);
        *loopPtr = valueNumber;
      }
      else {
        if (valueNumber < 1) {
          *loopPtr = 0;
          valueNumber = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(valueNumber + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr = DAT_001e61d0[0];
            operandFlags = *(uint *)(valueNumber + 0x20);
          }
        }
        else {
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
          valueNumber = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr = valueNumber;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset2;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr = (DAT_001e61d0)[valueNumber];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
        }
        if ((operandFlags & 1) != 0) {
          *loopPtr = *(int *)(&DAT_001e61b8 + *loopPtr * 4);
        }
      }
      operandRecOffset2 = operandRecOffset2 + 0x18;
      operandRecOffset = operandRecOffset + 0x18;
      loopPtr = loopPtr + 1;
      valueNumberPtr = valueNumberPtr + 4;
    }
    switch(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8)) {
    case 0x12:
      resultClass = *(int *)(&DAT_001e5ec4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x13:
      resultClass = *(int *)(&DAT_001e5c84 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x14:
      resultClass = *(int *)(&DAT_001e5ec4 +
                      (*(int *)(&DAT_001e5c84 + (operandClass[0] * 6 + operandClass[1]) * 4) * 6 +
                      operandClass[2]) * 4);
      break;
    default:
      resultClass = 0;
      break;
    case 0x17:
      resultClass = *(int *)(&DAT_001e5da4 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x19:
      resultClass = *(int *)(&DAT_001e5d14 + (operandClass[0] * 6 + operandClass[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      resultClass = *(int *)(&DAT_001e5e34 + (operandClass[1] * 6 + operandClass[2]) * 4);
      break;
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
      resultClass = operandClass[0];
    }
    if (*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) {
      resultClass = (DAT_001e61a0)[resultClass];
    }
    laneEntryPtr2 = lane * 4 + ctx;
    laneNode = *(int *)(laneEntryPtr2 + 0x40);
    if (laneNode == 0) {
      laneNode = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),lane,ctx);
      *(int *)(laneEntryPtr2 + 0x40) = laneNode;
    }
    *(int *)(laneNode + 0xc) = resultClass;
  }
  return;
}

/* IRInst__isOpcode8bOr8c @ 0x1789d4 (28 bytes) */
int IRInst__isOpcode8bOr8c(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x8bU < 2;
}

/* FUN_001789f0 @ 0x1789f0 (168 bytes) */
int FUN_001789f0(ctx)
  int ctx;
{
  int *a0;
  int callResult;
  uint uVar2;
  int loopIndex;
  
  a0 = *(int **)(ctx + 0xb0);
  uVar2 = *(int *)(a0[0x22] + 8) - 0x12;
  if ((uVar2 < 0x20) && (loopIndex = 1, (1 << (uVar2 & 0x3f) & 0x800000a7U) != 0)) {
    while( true ) {
      callResult = (**(code **)(*a0 + 0x14))(a0);
      if (callResult < loopIndex) {
        return 1;
      }
      a0 = *(int **)(ctx + 0xb0);
      if (((a0[loopIndex * 6 + 0x28] & 1U) != 0) || ((a0[loopIndex * 6 + 0x28] & 2U) != 0)) break;
      loopIndex = loopIndex + 1;
    }
  }
  return 0;
}

/* FUN_00178a98 @ 0x178a98 (132 bytes) */
int FUN_00178a98(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_2 == 1) {
      return *(uint *)(param_1 + 0x178) >> 0x1f;
    }
    if (param_2 < 2) {
      if (param_2 == 0) {
        return 1;
      }
    }
    else {
      if (param_2 == 2) {
        if (((*(int *)(param_1 + 0x178) < 0) && (*(int *)(param_1 + 0x180) < 0)) &&
           (*(int *)(param_1 + 0x184) < 0)) {
          return 1;
        }
        return 0;
      }
      if (param_2 == 3) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00178b1c @ 0x178b1c (360 bytes) */
int FUN_00178b1c(ctx)
  int ctx;
{
  bool bVar1;
  int loopIndex;
  int *loopPtr4;
  undefined4 uVar4;
  int loopIndex2;
  int loopIndex3;
  
  loopPtr4 = *(int **)(ctx + 0xb0);
  loopIndex = *(int *)(loopPtr4[0x22] + 8);
  if (loopIndex == 0x1c) {
    for (loopIndex = 1; loopIndex2 = (**(code **)(*loopPtr4 + 0x14))(loopPtr4), loopIndex <= loopIndex2; loopIndex = loopIndex + 1
        ) {
      loopIndex2 = 0;
      loopPtr4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
      do {
        if (-1 < *loopPtr4) goto LAB_00178b50;
        bVar1 = loopIndex2 != 2;
        loopPtr4 = loopPtr4 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      loopPtr4 = *(int **)(ctx + 0xb0);
    }
LAB_00178bc4:
    uVar4 = 1;
  }
  else {
    if (loopIndex < 0x1d) {
      if (loopIndex == 0x18) {
LAB_00178b6c:
        for (loopIndex = 1; loopIndex2 = (**(code **)(*loopPtr4 + 0x14))(loopPtr4), loopIndex <= loopIndex2;
            loopIndex = loopIndex + 1) {
          loopIndex2 = 4;
          loopPtr4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
          do {
            if (-1 < *loopPtr4) goto LAB_00178b50;
            loopPtr4 = loopPtr4 + 1;
            loopIndex2 = loopIndex2 + -1;
          } while (loopIndex2 != 0);
          loopPtr4 = *(int **)(ctx + 0xb0);
        }
        goto LAB_00178bc4;
      }
    }
    else {
      if (loopIndex == 0x1d) goto LAB_00178b6c;
      if (loopIndex == 0x1e) {
        loopIndex = 1;
        loopIndex2 = ctx + 0x170;
        do {
          loopPtr4 = (int *)(loopIndex2 + 8);
          loopIndex3 = 0;
          do {
            if (-1 < *loopPtr4) goto LAB_00178b50;
            bVar1 = loopIndex3 != 1;
            loopPtr4 = loopPtr4 + 1;
            loopIndex3 = loopIndex3 + 1;
          } while (bVar1);
          bVar1 = loopIndex != 2;
          loopIndex2 = loopIndex2 + 0x10;
          loopIndex = loopIndex + 1;
        } while (bVar1);
        if (*(int *)(ctx + 0x1a0) < 0) goto LAB_00178bc4;
      }
    }
LAB_00178b50:
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_00178c84 @ 0x178c84 (244 bytes) */
int FUN_00178c84(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *exprRecord;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_2 + 0xb0);
  if (*(int *)(piVar4[0x22] + 8) == 0x32) {
    iVar1 = (**(code **)(*piVar4 + 0x14))(piVar4);
    if (iVar1 == 1) {
      iVar3 = param_3 * 0x10 + param_2;
      iVar1 = *(int *)(iVar3 + 0x168);
      if ((iVar1 != *(int *)(iVar3 + 0x16c)) || (iVar1 != *(int *)(iVar3 + 0x174)))
      goto LAB_00178d10;
    }
    else {
      if (iVar1 != 3) goto LAB_00178d10;
      if (param_3 == 2) {
        iVar1 = *(int *)(param_2 + 0x18c);
      }
      else if (param_3 == 3) {
        iVar1 = *(int *)(param_2 + 0x1a4);
      }
      else {
        if (param_3 != 1) goto LAB_00178d10;
        iVar1 = *(int *)(param_2 + 0x178);
      }
    }
    if (iVar1 < 0) {
      exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar1);
      *param_1 = *exprRecord;
      return param_1;
    }
  }
LAB_00178d10:
  *param_1 = 0x7ffffffe;
  return param_1;
}

/* FUN_00178d78 @ 0x178d78 (280 bytes) */
int FUN_00178d78(resultOut, key, operandNumber)
  undefined4 *resultOut;
  int key;
  int operandNumber;
{
  int operandEntryPtr;
  int opcode;
  undefined4 *exprRecord;
  int splatValueNumber;
  
  opcode = *(int *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8);
  if (opcode == 0x1c) {
    operandEntryPtr = operandNumber * 0x10 + key;
    splatValueNumber = *(int *)(operandEntryPtr + 0x168);
    if ((splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) || (splatValueNumber != *(int *)(operandEntryPtr + 0x170))) goto LAB_00178de8;
  }
  else {
    if (opcode < 0x1d) {
      if (opcode != 0x18) goto LAB_00178de8;
    }
    else if (opcode != 0x1d) {
      if (opcode != 0x1e) goto LAB_00178de8;
      if (operandNumber - 1U < 2) {
        operandEntryPtr = operandNumber * 0x10 + key;
        splatValueNumber = *(int *)(operandEntryPtr + 0x168);
        if (splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) goto LAB_00178de8;
      }
      else {
        splatValueNumber = *(int *)(operandNumber * 0x10 + key + 0x170);
      }
      goto LAB_00178e60;
    }
    operandEntryPtr = operandNumber * 0x10 + key;
    splatValueNumber = *(int *)(operandEntryPtr + 0x168);
    if (((splatValueNumber != *(int *)(operandEntryPtr + 0x16c)) || (splatValueNumber != *(int *)(operandEntryPtr + 0x170))) ||
       (splatValueNumber != *(int *)(operandEntryPtr + 0x174))) goto LAB_00178de8;
  }
LAB_00178e60:
  if (splatValueNumber < 0) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),splatValueNumber);
    *resultOut = *exprRecord;
    return resultOut;
  }
LAB_00178de8:
  *resultOut = 0x7ffffffe;
  return resultOut;
}

/* ValueKey__evalLitLane @ 0x178e90 (468 bytes) */
int ValueKey__evalLitLane(resultOut, key, lane, staleArg4)
  float *resultOut;
  int key;
  int lane;
  uint staleArg4;
{
  float clampHigh;
  float clampedExponent;
  float clampedX;
  float laneOneResult;
  float xValue;
  float *loopPtr;
  int loopRemaining;
  double logOrPow;
  double logTwo;
  float litInputs [15];
  
  loopRemaining = 5;
  loopPtr = litInputs;
  do {
    *loopPtr = GH_U2F(0x7fff0000U);
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  *resultOut = GH_U2F(0x7fff0000U);
  if (*(int *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8) == 0x32) {
    if (lane == 1) {
      loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                     *(undefined4 *)(key + 0x178));
      xValue = *loopPtr;
      clampedX = xValue;
      if (xValue < 0.0) {
        clampedX = 0.0;
      }
      laneOneResult = 0.0;
      if (-xValue < 0.0) {
        laneOneResult = clampedX;
      }
      *resultOut = laneOneResult;
    }
    else {
      if (lane < 2) {
        if (lane != 0) {
          return resultOut;
        }
      }
      else {
        if (lane == 2) {
          loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                         *(undefined4 *)(key + 0x178));
          litInputs[0] = *loopPtr;
          loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                         *(undefined4 *)(key + 0x17c));
          litInputs[1] = *loopPtr;
          if ((0.0 < litInputs[0]) && (0.0 < litInputs[1])) {
            loopPtr = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                           *(undefined4 *)(key + 0x184));
            litInputs[3] = *loopPtr;
            clampedExponent = -128.0;
            if (-128.0 <= litInputs[3]) {
              clampHigh = 128.0;
              if (litInputs[3] - 128.0 < 0.0) {
                clampHigh = litInputs[3];
              }
              clampedExponent = litInputs[3];
              if (-(litInputs[3] - 128.0) < 0.0) {
                clampedExponent = clampHigh;
              }
            }
            logOrPow = _log((double)litInputs[1]);
            logTwo = _log(2.0);
            logOrPow = _pow(2.0,(double)(clampedExponent * (float)(logOrPow / logTwo)));
            *resultOut = (float)logOrPow;
            return resultOut;
          }
          *resultOut = 0.0;
          return resultOut;
        }
        if (lane != 3) {
          return resultOut;
        }
      }
      *resultOut = 1.0;
    }
  }
  return resultOut;
}

/* FUN_00179064 @ 0x179064 (212 bytes) */
int FUN_00179064(ctx, param_2)
  int ctx;
  int param_2;
{
  byte bVar1;
  undefined4 uVar2;
  int callResult;
  undefined4 uVar4;
  
  (**(code **)(**(int **)(ctx + 0xb0) + 0x48))(*(int **)(ctx + 0xb0),param_2);
  uVar4 = *(undefined4 *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x20);
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),uVar4);
  if ((((*(char *)(callResult + 8) != '\0') && (bVar1 = *(byte *)(callResult + 9), (bVar1 & 1) == 0)) &&
      ((bVar1 & 2) == 0)) && (((bVar1 & 4) == 0 && ((bVar1 & 8) == 0)))) {
    return callResult;
  }
  *(undefined1 *)(callResult + 8) = 2;
  uVar2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  *(int *)(callResult + 0x10) = param_2;
  *(undefined4 *)(callResult + 0xc) = uVar2;
  *(undefined4 *)(callResult + 0x14) = uVar4;
  *(undefined1 *)(callResult + 9) = 0;
  *(undefined4 *)(callResult + 0x1c) = 0;
  *(undefined4 *)(callResult + 0x18) = 0;
  FUN_0017629c(callResult,*(undefined4 *)(ctx + 0x238));
  return callResult;
}

/* FUN_00179138 @ 0x179138 (240 bytes) */
int FUN_00179138(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  undefined4 operandRef2;
  int operandRef;
  undefined4 arenaAt378;
  int iVar1;
  int callResult;
  undefined4 uVar3;
  undefined4 *allocation;
  int iVar5;
  int *block;
  
  callResult = IRLoadConst__vslot73(0xa2,*(undefined4 *)(ctx + 0x238));
  iVar1 = *(int *)(ctx + 0x238);
  uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x6c4) + 0x3ac);
  iVar5 = *(int *)(iVar1 + 0x3b0) + -1;
  *(int *)(iVar1 + 0x3b0) = iVar5;
  operandRef = VRegPool__findOrCreate(uVar3,0x36,iVar5,0);
  VReg__appendUser(operandRef,callResult);
  block = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
  iVar5 = (**(code **)(*block + 0x24))(block);
  if (iVar5 == 0) {
    Block__insertInstBefore(block,*(undefined4 *)(ctx + 0xb0),callResult);
  }
  else {
    Block__appendInst(block[1],callResult);
  }
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    allocation = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *allocation = arenaAt378;
    ValueKey__init(allocation + 1,callResult,*(undefined4 *)(ctx + 0x238));
    Block__recordDefinition(block,operandRef,allocation + 1);
  }
  *(undefined4 *)(callResult + 300) = 1;
  *(undefined4 *)(callResult + 0x84) = 1;
  IRInst__setOperandRef(callResult,0,operandRef);
  operandRef2 = *(undefined4 *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c);
  IRInst__setOperandRef(callResult,1,operandRef2);
  iVar5 = operandIndex * 4 + ctx;
  VReg__addUse(operandRef2,1,callResult);
  IRInst__setOperandSource(callResult,1,*(undefined4 *)(iVar5 + 0x210),0,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),operandIndex,operandRef);
  VReg__addUse(operandRef,operandIndex,*(undefined4 *)(ctx + 0xb0));
  *(int *)(iVar5 + 0x210) = callResult;
  return callResult;
}

/* FUN_001792f0 @ 0x1792f0 (232 bytes) */
int FUN_001792f0(ctx, param_2)
  int ctx;
  int param_2;
{
  int *a0;
  int callResult;
  int *elementRef;
  uint uVar3;
  uint vectorFilledCount;
  uint *vector;
  int iVar6;
  
  a0 = *(int **)(ctx + 0xb0);
  vector = *(uint **)(a0[param_2 * 6 + 0x23] + 0x2c);
  vectorFilledCount = vector[1];
  uVar3 = vectorFilledCount - 1;
  if (uVar3 < *vector) {
    if (vectorFilledCount <= uVar3) {
      _memset(vectorFilledCount * 4 + vector[2],0,(uVar3 - vectorFilledCount) * 4 + 4);
      vector[1] = vectorFilledCount;
      a0 = *(int **)(ctx + 0xb0);
    }
    elementRef = (int *)(uVar3 * 4 + vector[2]);
  }
  else {
    elementRef = (int *)Vector__elementRefGrow(vector,uVar3);
    a0 = *(int **)(ctx + 0xb0);
  }
  iVar6 = *elementRef;
  callResult = (**(code **)(*a0 + 100))(a0);
  if ((callResult != 0) &&
     (callResult = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(iVar6 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), callResult != 0)) {
    return 1;
  }
  return 0;
}

/* ValueKey__findLaneWithSameValue @ 0x1793d8 (560 bytes) */
int ValueKey__findLaneWithSameValue(ctx, operandIndex, laneEnableFlags)
  int ctx;
  int operandIndex;
  undefined4 laneEnableFlags;
{
  int laneValueNumber2;
  bool isLastLane;
  int operandRecord;
  unsigned int ghidra_home[8] = { ctx, operandIndex, laneEnableFlags, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool moreLanes;
  int laneValueNumber;
  undefined4 *exprRecord;
  int commonValueNumber;
  uint loopIndex4;
  int definingKey;
  char *loopPtr2;
  uint lastIndex;
  int loopIndex;
  int *loopPtr3;
  uint *vector;
  undefined4 absOut;
  undefined4 negatedOut;
  undefined4 absOut2;
  undefined4 negatedOut2 [4];
  
  loopPtr3 = (int *)(operandIndex * 0x10 + ctx + 0x168);
  commonValueNumber = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = laneEnableFlags;
  loopPtr2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*loopPtr2 != '\0') {
      if (commonValueNumber == 0) {
        commonValueNumber = *loopPtr3;
      }
      else {
        loopIndex = Ptr__equalNonNull(commonValueNumber,*loopPtr3);
        if (loopIndex == 0) {
          return 4;
        }
      }
    }
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
  } while (loopPtr2 != &(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  vector = *(uint **)(*(int *)(operandIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  loopIndex4 = vector[1];
  lastIndex = loopIndex4 - 1;
  if (lastIndex < *vector) {
    if (loopIndex4 <= lastIndex) {
      _memset(loopIndex4 * 4 + vector[2],0,(lastIndex - loopIndex4) * 4 + 4);
      vector[1] = loopIndex4;
    }
    loopPtr3 = (int *)(lastIndex * 4 + vector[2]);
  }
  else {
    loopPtr3 = (int *)Vector__elementRefGrow(vector,lastIndex);
  }
  definingKey = *loopPtr3;
  loopIndex4 = 0;
  loopIndex = definingKey;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(definingKey + 0xb0),0);
    if (*(char *)(loopIndex4 + operandRecord + 0x10) != '\x01') {
      laneValueNumber = *(int *)(loopIndex + 0x20);
      if (laneValueNumber < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneValueNumber);
        IRInst__applyAbsModifier(&absOut,*(undefined4 *)(ctx + 0xb0),operandIndex,*exprRecord);
        IRInst__applyNegateModifier(&negatedOut,*(undefined4 *)(ctx + 0xb0),operandIndex,absOut);
        laneValueNumber = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),negatedOut);
        laneValueNumber = *(int *)(laneValueNumber + 4);
      }
      if (laneValueNumber == commonValueNumber) {
        return loopIndex4;
      }
    }
    moreLanes = loopIndex4 != 3;
    loopIndex = loopIndex + 4;
    loopIndex4 = loopIndex4 + 1;
  } while (moreLanes);
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
      loopIndex4 = (uint)*(byte *)(loopIndex + operandRecord + 0x10);
      laneValueNumber2 = *(int *)(loopIndex4 * 4 + definingKey + 0x20);
      if (laneValueNumber2 < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),laneValueNumber2);
        IRInst__applyAbsModifier(&absOut2,*(undefined4 *)(ctx + 0xb0),operandIndex,*exprRecord);
        IRInst__applyNegateModifier(negatedOut2,*(undefined4 *)(ctx + 0xb0),operandIndex,absOut2);
        laneValueNumber2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),negatedOut2[0]);
        laneValueNumber2 = *(int *)(laneValueNumber2 + 4);
      }
      if (laneValueNumber2 == commonValueNumber) {
        return loopIndex4;
      }
    }
    isLastLane = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (isLastLane) {
      return 4;
    }
  } while( true );
}

/* FUN_00179608 @ 0x179608 (456 bytes) */
int FUN_00179608(ctx, param_2, operandIndex, operandIndex2)
  int ctx;
  int param_2;
  int operandIndex;
  int operandIndex2;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  uint *vector2;
  int inst;
  int operandRecord2;
  int operandRecord;
  byte bVar1;
  int *elementRef;
  int iVar3;
  int iVar4;
  undefined4 callResult;
  uint uVar6;
  uint uVar7;
  uint *vector;
  
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),operandIndex);
  bVar1 = *(byte *)(param_2 + operandRecord + 0x10);
  iVar3 = *(int *)((operandIndex * 4 + param_2) * 4 + ctx + 0x168);
  if (iVar3 < 0) {
    inst = *(int *)(ctx + 0xb0);
    if (*(int *)(*(int *)(inst + 0x88) + 8) != 0x8e) {
      vector = *(uint **)(*(int *)(operandIndex * 0x18 + inst + 0x8c) + 0x2c);
      vectorFilledCount2 = vector[1];
      uVar6 = vectorFilledCount2 - 1;
      if (uVar6 < *vector) {
        if (vectorFilledCount2 <= uVar6) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(uVar6 - vectorFilledCount2) * 4 + 4);
          vector[1] = vectorFilledCount2;
          inst = *(int *)(ctx + 0xb0);
        }
        elementRef = (int *)(uVar6 * 4 + vector[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector,uVar6);
        inst = *(int *)(ctx + 0xb0);
      }
      iVar3 = *(int *)((uint)bVar1 * 4 + *elementRef + 0x20);
    }
  }
  else {
    inst = *(int *)(ctx + 0xb0);
  }
  operandRecord2 = IRInst__getOperandRecord(inst,operandIndex2);
  bVar1 = *(byte *)(param_2 + operandRecord2 + 0x10);
  iVar4 = *(int *)((operandIndex2 * 4 + param_2) * 4 + ctx + 0x168);
  if ((iVar4 < 0) && (*(int *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8) != 0x8e)) {
    vector2 = *(uint **)(*(int *)(operandIndex2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
    vectorFilledCount = vector2[1];
    uVar7 = vectorFilledCount - 1;
    if (uVar7 < *vector2) {
      if (vectorFilledCount <= uVar7) {
        _memset(vectorFilledCount * 4 + vector2[2],0,(uVar7 - vectorFilledCount) * 4 + 4);
        vector2[1] = vectorFilledCount;
      }
      elementRef = (int *)(uVar7 * 4 + vector2[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vector2,uVar7);
    }
    iVar4 = *(int *)((uint)bVar1 * 4 + *elementRef + 0x20);
  }
  callResult = Ptr__equalNonNull(iVar3,iVar4);
  return callResult;
}

/* FUN_001797d0 @ 0x1797d0 (196 bytes) */
int FUN_001797d0(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 exprRecordForValueNumberResult;
  uint uVar4;
  
  iVar2 = ((int (*)())FUN_00179608)(ctx,param_2,2,3);
  if (iVar2 != 0) {
    iVar2 = *(int *)(ctx + 0xb0);
    uVar4 = *(uint *)(iVar2 + 0xe8);
    uVar1 = *(uint *)(iVar2 + 0xd0) & 1;
    if ((uVar1 == (uVar4 & 1)) && ((*(uint *)(iVar2 + 0xd0) >> 1 & 1) == (uVar4 >> 1 & 1))) {
      if ((*(int *)(iVar2 + 0x120) == 0) &&
         (((*(int *)(iVar2 + 0x124) == 0 && (uVar1 == 0)) && ((uVar4 & 2) == 0)))) {
        iVar2 = param_2 * 4 + ctx;
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar2 + 0x198));
        *(undefined4 *)(iVar2 + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldCompareSameSourcesValueNumber @ 0x179894 (184 bytes) */
int ValueKey__foldCompareSameSourcesValueNumber(ctx, param_2)
  int ctx;
  int param_2;
{
  undefined4 exprRecord;
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(ctx + 0xb0);
    if (((*(uint *)(iVar1 + 0xb8) & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((*(uint *)(iVar1 + 0xb8) >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      iVar1 = ((bool (*)())evaluateCompareFloats)(iVar1,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar2 = 0x3f800000;
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),uVar2);
      *(undefined4 *)(param_2 * 4 + ctx + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* FUN_0017994c @ 0x17994c (232 bytes) */
int FUN_0017994c(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int *exprRecord;
  undefined4 exprRecordForValueNumberResult;
  uint uVar5;
  int iVar6;
  
  iVar2 = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (iVar2 != 0) {
    uVar5 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar5 & 1)) && ((uVar1 >> 1 & 1) == (uVar5 >> 1 & 1))) {
      iVar6 = param_2 * 4 + ctx;
      iVar2 = *(int *)(iVar6 + 0x178);
      if (iVar2 < 0) {
        exprRecord = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)
                                (((1 - (*exprRecord >> 0x1f)) * 4 + param_2) * 4 + ctx + 0x168));
          *(undefined4 *)(iVar6 + 0x30) = exprRecordForValueNumberResult;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00179a34 @ 0x179a34 (244 bytes) */
int FUN_00179a34(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int *exprRecord;
  undefined4 exprRecordForValueNumberResult;
  uint uVar5;
  
  iVar2 = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (iVar2 != 0) {
    uVar5 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar5 & 1)) && ((uVar1 >> 1 & 1) == (uVar5 >> 1 & 1))) {
      iVar2 = *(int *)(param_2 * 4 + ctx + 0x178);
      if (iVar2 < 0) {
        exprRecord = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        iVar2 = 1;
        if (0 < *exprRecord) {
          iVar2 = 2;
        }
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)((iVar2 * 4 + param_2) * 4 + ctx + 0x168));
          *(undefined4 *)(param_2 * 4 + ctx + 0x30) = exprRecordForValueNumberResult;
          return 1;
        }
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00179b28 @ 0x179b28 (148 bytes) */
int FUN_00179b28(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int callResult;
  undefined4 exprRecord;
  uint uVar4;
  
  callResult = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (callResult != 0) {
    uVar4 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar4 & 1)) && ((uVar1 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
      *(undefined4 *)(param_2 * 4 + ctx + 0x30) = exprRecord;
      return 1;
    }
  }
  return 0;
}

/* FUN_00179bbc @ 0x179bbc (136 bytes) */
int FUN_00179bbc(ctx, param_2)
  int ctx;
  undefined4 param_2;
{
  int loopIndex;
  int callResult;
  
  loopIndex = *(int *)(*(int *)(ctx + 0xb0) + 0x84);
  if ((loopIndex != 1) && (1 < loopIndex)) {
    loopIndex = 2;
    do {
      callResult = ((int (*)())FUN_00179608)(ctx,param_2,loopIndex + -1,loopIndex);
      if (callResult == 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(*(int *)(ctx + 0xb0) + 0x84));
  }
  return 1;
}

/* Inst__allWrittenLanesSatisfy @ 0x179c44 (124 bytes) */
int Inst__allWrittenLanesSatisfy(valueKey, param_2, param_3)
  int valueKey;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(valueKey + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = ((int (*)())FUN_00179608)(valueKey,loopIndex,param_2,param_3), iVar2 != 0))) {
    bVar1 = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00179cc0 @ 0x179cc0 (240 bytes) */
int FUN_00179cc0(ctx, param_2)
  int ctx;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 exprRecordForValueNumberResult;
  int member0xb0;
  int loopIndex;
  int *piVar8;
  
  loopIndex = 1;
  iVar3 = param_2 * 4 + ctx;
  piVar8 = (int *)(iVar3 + 0x178);
  while ((-1 < *piVar8 ||
         (piVar4 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*piVar8), *piVar4 != 0))) {
    bVar1 = loopIndex == 2;
    piVar8 = piVar8 + 4;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 0;
    }
  }
  member0xb0 = *(int *)(ctx + 0xb0);
  loopIndex = (loopIndex == 1) + 1;
  if ((((*(int *)(member0xb0 + 0x120) == 0) && (*(int *)(member0xb0 + 0x124) == 0)) &&
      (uVar2 = *(uint *)(loopIndex * 0x18 + member0xb0 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)) {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + param_2) * 4 + ctx + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* FUN_00179db0 @ 0x179db0 (196 bytes) */
int FUN_00179db0(ctx, param_2)
  int ctx;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 exprRecordForValueNumberResult;
  int loopIndex;
  int *piVar6;
  
  iVar2 = param_2 * 4 + ctx;
  piVar6 = (int *)(iVar2 + 0x178);
  loopIndex = 1;
  while ((-1 < *piVar6 ||
         (piVar3 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*piVar6), *piVar3 != 0))) {
    bVar1 = loopIndex == 2;
    piVar6 = piVar6 + 4;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 0;
    }
  }
  loopIndex = *(int *)(ctx + 0xb0);
  if ((((*(int *)(loopIndex + 0x120) == 0) && (*(int *)(loopIndex + 0x124) == 0)) &&
      ((*(uint *)(loopIndex + 0xe8) & 1) == 0)) && ((*(uint *)(loopIndex + 0xe8) & 2) == 0)) {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar2 + 0x198));
    *(undefined4 *)(iVar2 + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* FUN_00179e74 @ 0x179e74 (196 bytes) */
int FUN_00179e74(ctx, param_2)
  int ctx;
  int param_2;
{
  int iVar1;
  undefined4 exprRecordForValueNumberResult;
  uint uVar3;
  
  iVar1 = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(ctx + 0xb0);
    uVar3 = *(uint *)(iVar1 + 0xb8);
    if (((uVar3 & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((uVar3 >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      if ((*(int *)(iVar1 + 0x120) == 0) &&
         (((*(int *)(iVar1 + 0x124) == 0 && ((uVar3 & 1) == 0)) && ((uVar3 & 2) == 0)))) {
        iVar1 = param_2 * 4 + ctx;
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar1 + 0x178));
        *(undefined4 *)(iVar1 + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179f38 @ 0x179f38 (252 bytes) */
int FUN_00179f38(ctx, param_2)
  int ctx;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  float *pfVar4;
  undefined4 exprRecordForValueNumberResult;
  int member0xb0;
  int loopIndex;
  int *piVar8;
  
  loopIndex = 1;
  iVar3 = param_2 * 4 + ctx;
  piVar8 = (int *)(iVar3 + 0x178);
  while ((-1 < *piVar8 ||
         (pfVar4 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*piVar8), *pfVar4 != 1.0))
        ) {
    bVar1 = loopIndex == 2;
    piVar8 = piVar8 + 4;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 0;
    }
  }
  member0xb0 = *(int *)(ctx + 0xb0);
  loopIndex = (loopIndex == 1) + 1;
  if ((*(int *)(member0xb0 + 0x120) == 0) &&
     (((*(int *)(member0xb0 + 0x124) == 0 &&
       (uVar2 = *(uint *)(loopIndex * 0x18 + member0xb0 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0))))
  {
    exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + param_2) * 4 + ctx + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = exprRecordForValueNumberResult;
    return 1;
  }
  return 1;
}

/* FUN_0017a034 @ 0x17a034 (252 bytes) */
int FUN_0017a034(ctx, param_2)
  int ctx;
  int param_2;
{
  undefined4 findInPtrSetResult;
  undefined4 exprRecordForValueNumberResult;
  undefined4 uVar1;
  uint uVar2;
  float *exprRecord2;
  float *exprRecord;
  int iVar5;
  int member0xb0;
  int iVar7;
  
  iVar7 = param_2 * 4 + ctx;
  uVar1 = 0;
  if (*(int *)(iVar7 + 0x178) < 0) {
    exprRecord2 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(iVar7 + 0x178));
    exprRecord = (float *)Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
    iVar5 = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)*exprRecord2,(double)*exprRecord);
    member0xb0 = *(int *)(ctx + 0xb0);
    iVar5 = (iVar5 == 0) + 2;
    if ((((*(int *)(member0xb0 + 0x120) == 0) && (*(int *)(member0xb0 + 0x124) == 0)) &&
        (uVar2 = *(uint *)(iVar5 * 0x18 + member0xb0 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)) {
      iVar5 = *(int *)((iVar5 * 4 + param_2) * 4 + ctx + 0x168);
      if (iVar5 < 0) {
        exprRecordForValueNumberResult = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar5);
        *(undefined4 *)(iVar7 + 0x30) = exprRecordForValueNumberResult;
        return 1;
      }
      findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar5);
      *(undefined4 *)(iVar7 + 0x40) = findInPtrSetResult;
      return 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0017a130 @ 0x17a130 (284 bytes) */
int FUN_0017a130(operandIndex, param_2, inst, compiler)
  int operandIndex;
  float *param_2;
  int inst;
  int compiler;
{
  int operandRecord;
  undefined4 arenaAt378;
  int *vector;
  undefined4 *allocation;
  int operandRef;
  undefined4 uVar4;
  int vectorCapacity;
  undefined4 *puVar6;
  
  uVar4 = DAT_001b01d8;
  if (operandIndex == 0) {
    *(undefined4 *)(inst + 0x9c) = DAT_001b01d8;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = uVar4;
  }
  ((void (*)())IRInst__makeLiteralVec4Float)(inst,*(undefined4 *)(compiler + COMP_currentProgram),operandIndex,(double)*param_2,(double)param_2[1],
               (double)param_2[2],(double)param_2[3]);
  vector = *(int **)(*(int *)(operandIndex * 0x18 + inst + 0x8c) + 0x18);
  if (*vector == 0) {
    vector = (int *)Vector__elementRefGrow(vector,0);
  }
  else {
    if (vector[1] == 0) {
      *(undefined4 *)vector[2] = 0;
      vector[1] = 1;
    }
    vector = (int *)vector[2];
  }
  vectorCapacity = *vector;
  operandRef = *(int *)(vectorCapacity + 0x8c);
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    puVar6 = allocation + 1;
    *allocation = arenaAt378;
    ValueKey__init(puVar6,vectorCapacity,compiler);
    FUN_00174e0c(puVar6);
    ValueKey__propagateLaneValues(puVar6);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(vectorCapacity + 0x158) + 0xb0),puVar6);
  }
  IRInst__setOperandRef(inst,operandIndex,operandRef);
  return vectorCapacity;
}

/* FUN_0017a294 @ 0x17a294 (320 bytes) */
int FUN_0017a294(ctx, param_2, param_3)
  int ctx;
  float *param_2;
  int param_3;
{
  int iVar1;
  int member0xb0;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  member0xb0 = *(int *)(ctx + 0xb0);
  iVar1 = *(int *)(*(int *)(member0xb0 + 0x88) + 8);
  if (iVar1 == 0x8b) {
    IRInst__initOperandRecord(member0xb0,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x214) = uVar3;
    ((void (*)())IRInst__makeLiteralVec4Float)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1,(double)*param_2
                 ,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
    IRInst__initOperandRecord(*(undefined4 *)(ctx + 0xb0),2);
    local_24 = DAT_001b01ec;
    local_28 = DAT_001b01e8;
    local_20 = DAT_001b01f0;
    local_1c = DAT_001b01f4;
    uVar3 = ((int (*)())FUN_0017a130)(2,&local_28,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x218) = uVar3;
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  else if (iVar1 == 0x8c) {
    IRInst__initOperandRecord(member0xb0,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x214) = uVar3;
    ((void (*)())IRInst__makeLiteralVec4Float)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1,(double)*param_2
                 ,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  return;
}

/* FUN_0017a3d4 @ 0x17a3d4 (884 bytes) */
int FUN_0017a3d4(ctx)
  int ctx;
{
  int operandRecAddr;
  int operandClass;
  int firstOperandClass;
  bool isLastLane;
  bool branchTaken;
  int findInPtrSetResult;
  bool moreOperands;
  bool allOperandsFloatConst;
  float foldedResult;
  uint operandFlags;
  float laneResult;
  float *loopPtr3;
  float *loopPtr4;
  int loopIndex2;
  float *exprRecord;
  int compareClass;
  int valueNumber;
  float *laneResults;
  int operandRecOffset;
  int *valueNumberPtr;
  int *loopPtr5;
  bool usedUniformConstant;
  int loopIndex;
  int loopRemaining;
  int operandClasses [2];
  float laneConstants [9];
  int lanesAgree;
  
  loopIndex = 4;
  laneResults = laneConstants + 3;
  loopPtr3 = laneResults;
  do {
    *loopPtr3 = GH_U2F(0x7fff0000U);
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)laneResults) = 0;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  usedUniformConstant = false;
  lanesAgree = 1;
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  loopPtr3 = laneResults;
  foldedResult = FLOAT_001aa114;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopPtr4 = laneConstants;
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      do {
        *loopPtr4 = GH_U2F(0x7fff0000U);
        loopPtr4 = loopPtr4 + 1;
      } while (laneResults != loopPtr4);
      valueNumberPtr = (int *)(loopRemaining + 8);
      allOperandsFloatConst = true;
      loopIndex2 = 1;
      loopPtr5 = operandClasses;
      operandRecOffset = 0x98;
      loopPtr4 = laneConstants;
      do {
        loopPtr4 = loopPtr4 + 1;
        *loopPtr5 = 0;
        valueNumber = *valueNumberPtr;
        if (valueNumber < 0) {
          exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),valueNumber);
          *loopPtr4 = *exprRecord;
          operandClass = signToCompareCode(*(unsigned int *)exprRecord);
          *loopPtr5 = operandClass;
        }
        else {
          if (valueNumber < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),valueNumber);
          compareClass = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr5 = compareClass;
          operandRecAddr = *(int *)(ctx + 0xb0) + operandRecOffset;
          operandFlags = *(uint *)(operandRecAddr + 0x20);
          if ((operandFlags & 2) != 0) {
            *loopPtr5 = (DAT_001e61d0)[compareClass];
            operandFlags = *(uint *)(operandRecAddr + 0x20);
          }
          if ((operandFlags & 1) == 0) {
            operandClass = *loopPtr5;
            usedUniformConstant = true;
            allOperandsFloatConst = false;
          }
          else {
            usedUniformConstant = true;
            allOperandsFloatConst = false;
            operandClass = *(int *)(&DAT_001e61b8 + *loopPtr5 * 4);
            *loopPtr5 = operandClass;
          }
        }
        firstOperandClass = operandClasses[0];
        if (operandClass == 0) {
          return 0;
        }
        moreOperands = loopIndex2 != 2;
        operandRecOffset = operandRecOffset + 0x18;
        loopPtr5 = loopPtr5 + 1;
        valueNumberPtr = valueNumberPtr + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (moreOperands);
      if (allOperandsFloatConst) {
        loopIndex2 = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)laneConstants[1],(double)laneConstants[2]
                            );
        laneResult = 0.0;
        if (loopIndex2 == 0) {
LAB_0017a608:
          laneResult = 1.0;
        }
        *loopPtr3 = laneResult;
      }
      else {
        loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
        loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + firstOperandClass * 0x30 + operandClasses[1]) * 4);
        if (loopIndex2 == 1) {
          *loopPtr3 = 0.0;
        }
        else {
          if (loopIndex2 == 2) goto LAB_0017a608;
          if (loopIndex2 == 0) {
            return 0;
          }
        }
      }
      if (foldedResult == FLOAT_001aa114) {
        foldedResult = *loopPtr3;
      }
      else if (*loopPtr3 != foldedResult) {
        lanesAgree = 0;
      }
    }
    isLastLane = loopIndex == 3;
    loopRemaining = loopRemaining + 4;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
    if (isLastLane) {
      if (usedUniformConstant) {
        loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(loopIndex + 0x134) = *(int *)(loopIndex + 0x134) + 1;
      }
      ((int (*)())FUN_0017a294)(ctx,laneResults,*(undefined4 *)(ctx + 0x238));
      loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
      if ((loopIndex != 0) && (lanesAgree != 0)) {
        loopPtr5 = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
        branchTaken = foldedResult != FLOAT_001aa0d4;
        loopIndex = (**(code **)(*loopPtr5 + 0x24))(loopPtr5);
        if (loopIndex != 0) {
          if (branchTaken) {
            loopIndex = loopPtr5[0x4d];
          }
          else {
            loopIndex = loopPtr5[0x4e];
          }
          Program__removeDeadRegion(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),loopPtr5,loopIndex,
                       loopPtr5[0x4f]);
          if (branchTaken) {
            loopIndex = 2;
          }
          else {
            loopIndex = 1;
          }
          loopPtr5[0x53] = loopIndex;
          return 1;
        }
      }
      return 1;
    }
  } while( true );
}

/* FUN_0017a748 @ 0x17a748 (348 bytes) */
int FUN_0017a748(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  uint uVar2;
  undefined4 *loopPtr2;
  int loopRemaining;
  int compareCondition;
  uint uVar6;
  undefined4 *loopPtr3;
  int loopIndex;
  undefined4 local_38 [8];
  
  loopRemaining = ((int (*)())Inst__allWrittenLanesSatisfy)(ctx,1,2);
  if (loopRemaining != 0) {
    uVar6 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar6 & 1)) && ((uVar2 >> 1 & 1) == (uVar6 >> 1 & 1))) {
      loopPtr3 = local_38;
      loopRemaining = 4;
      loopPtr2 = loopPtr3;
      do {
        *loopPtr2 = 0x7ffffffe;
        loopPtr2 = loopPtr2 + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining = 0;
      loopIndex = 4;
      do {
        *(undefined4 *)(loopRemaining + (int)loopPtr3) = 0;
        loopRemaining = loopRemaining + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      loopRemaining = signToCompareCode(0);
      loopIndex = 0;
      do {
        operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
          compareCondition = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
          if (*(int *)(&DAT_001e61e8 + (compareCondition * 6 + loopRemaining * 0x31) * 4) == 1) {
            *loopPtr3 = 0;
          }
          else if (*(int *)(&DAT_001e61e8 + (compareCondition * 6 + loopRemaining * 0x31) * 4) == 2) {
            *loopPtr3 = 0x3f800000;
          }
        }
        bVar1 = loopIndex != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      ((int (*)())FUN_0017a294)(ctx,local_38,*(undefined4 *)(ctx + 0x238));
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017a8a4 @ 0x17a8a4 (680 bytes) */
int FUN_0017a8a4(ctx)
  int ctx;
{
  int compareCondition;
  int findInPtrSetResult;
  int operandRecord;
  bool moreLanes;
  float foldedResult;
  bool usedUniformConstant;
  bool lanesAgree;
  uint *loopPtr2;
  int compareResultOrClass;
  undefined4 *exprRecord;
  int inst;
  int laneByteOffset;
  int loopIndex;
  int *blockRef;
  int loopRemaining;
  int loopRemaining2;
  uint laneResults;
  
  loopRemaining = 4;
  loopPtr2 = &laneResults;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 0;
  loopRemaining2 = 4;
  do {
    *(undefined4 *)(loopRemaining + (int)&laneResults) = 0;
    loopRemaining = loopRemaining + 4;
    loopRemaining2 = loopRemaining2 + -1;
  } while (loopRemaining2 != 0);
  loopRemaining2 = signToCompareCode(0);
  usedUniformConstant = false;
  foldedResult = -1.0;
  lanesAgree = true;
  loopIndex = 0;
  laneByteOffset = 0;
  loopRemaining = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      compareResultOrClass = *(int *)(loopRemaining + 0x178);
      if (compareResultOrClass < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),compareResultOrClass);
        compareResultOrClass = signToCompareCode(*exprRecord);
        inst = *(int *)(ctx + 0xb0);
      }
      else {
        if (compareResultOrClass < 1) {
          return 0;
        }
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),compareResultOrClass);
        inst = *(int *)(ctx + 0xb0);
        compareResultOrClass = *(int *)(findInPtrSetResult + 0xc);
        if ((*(uint *)(inst + 0xb8) & 2) != 0) {
          compareResultOrClass = (DAT_001e61d0)[compareResultOrClass];
        }
        usedUniformConstant = true;
        if ((*(uint *)(inst + 0xb8) & 1) != 0) {
          compareResultOrClass = *(int *)(&DAT_001e61b8 + compareResultOrClass * 4);
        }
      }
      compareCondition = IRInst__getCompareCondition(inst);
      compareResultOrClass = *(int *)(&DAT_001e61e8 + (compareCondition * 6 + compareResultOrClass * 0x30 + loopRemaining2) * 4);
      if (compareResultOrClass == 1) {
        *(undefined4 *)(laneByteOffset + (int)&laneResults) = 0;
      }
      else if (compareResultOrClass == 2) {
        *(undefined4 *)(laneByteOffset + (int)&laneResults) = 0x3f800000;
      }
      else if (compareResultOrClass == 0) {
        return 0;
      }
      if (foldedResult == -1.0) {
        foldedResult = *(float *)(laneByteOffset + (int)&laneResults);
      }
      else if (*(float *)(laneByteOffset + (int)&laneResults) != foldedResult) {
        lanesAgree = false;
      }
    }
    moreLanes = loopIndex != 3;
    laneByteOffset = laneByteOffset + 4;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (moreLanes);
  if (usedUniformConstant) {
    loopRemaining = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopRemaining + 0x134) = *(int *)(loopRemaining + 0x134) + 1;
  }
  ((int (*)())FUN_0017a294)(ctx,&laneResults,*(undefined4 *)(ctx + 0x238));
  loopRemaining = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
  if ((loopRemaining != 0) && (lanesAgree)) {
    blockRef = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
    loopRemaining = (**(code **)(*blockRef + 0x24))(blockRef);
    if (loopRemaining != 0) {
      if (foldedResult != 0.0) {
        loopRemaining = blockRef[0x4d];
      }
      else {
        loopRemaining = blockRef[0x4e];
      }
      Program__removeDeadRegion(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),blockRef,loopRemaining,blockRef[0x4f]);
      if (foldedResult != 0.0) {
        loopRemaining = 2;
      }
      else {
        loopRemaining = 1;
      }
      blockRef[0x53] = loopRemaining;
      return 1;
    }
  }
  return 1;
}

/* ValueKey__foldDotPowerOfTwoIntoOutputScale @ 0x17ab4c (472 bytes) */
int ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx)
  int ctx;
{
  int operandRecAddr;
  int keyInst;
  bool moreOperands;
  bool notNegative;
  int scaleCodeOrFlag;
  int limitsOk;
  undefined4 literalValueNumber;
  undefined4 staleArg4;
  undefined4 staleArg5;
  undefined4 staleArg6;
  int *a0;
  int operandRecOffset;
  int loopIndex;
  undefined4 *loopPtr2;
  double absValue;
  undefined4 unitConst0;
  undefined4 unitConst1;
  undefined4 unitConst2;
  undefined4 unitConst3;
  float laneValue [7];
  
  loopIndex = 1;
  operandRecOffset = 0x98;
  loopPtr2 = (undefined4 *)(ctx + 0x214);
  do {
    ((int (*)())FUN_00178d78)(laneValue,ctx,loopIndex);
    if ((GH_F2U(laneValue[0]) != 0x7ffffffeU)) {
      notNegative = -1 < (int)GH_F2U(laneValue[0]);
      if (notNegative) {
        absValue = (double)laneValue[0];
      }
      else {
        absValue = -(double)laneValue[0];
      }
      if ((absValue != 1.0) && (scaleCodeOrFlag = ((undefined4 (*)())isOutputScaleValue)(absValue), scaleCodeOrFlag != 0)) {
        scaleCodeOrFlag = ((int (*)())outputScaleExponent)(absValue);
        a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        scaleCodeOrFlag = scaleCodeOrFlag + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
        limitsOk = (**(code **)(*a0 + 0xfc))(a0,scaleCodeOrFlag,*(int *)(ctx + 0xb0),staleArg4,staleArg5,staleArg6,a0);
        if (limitsOk != 0) {
          unitConst0 = 0x3f800000;
          unitConst1 = 0x3f800000;
          unitConst2 = 0x3f800000;
          unitConst3 = 0x3f800000;
          literalValueNumber = ((int (*)())FUN_0017a130)(loopIndex,&unitConst0,*(undefined4 *)(ctx + 0xb0),
                               *(undefined4 *)(ctx + 0x238));
          keyInst = *(int *)(ctx + 0xb0);
          *loopPtr2 = literalValueNumber;
          *(int *)(keyInst + 0x124) = scaleCodeOrFlag;
          IROperand__setModifierBits(operandRecOffset + *(int *)(ctx + 0xb0) + 0xc,1,0);
          IROperand__setModifierBits(operandRecOffset + *(int *)(ctx + 0xb0) + 0xc,2,0);
          if (!notNegative) {
            operandRecAddr = *(int *)(ctx + 0xb0) + ((loopIndex == 1) - 1) * 0x18 + 0xb0;
            IROperand__setModifierBits(operandRecAddr + 0xc,1,(*(uint *)(operandRecAddr + 0x20) ^ 1) & 1);
          }
          ValueKey__rebuild(ctx);
          return 1;
        }
      }
    }
    moreOperands = loopIndex != 2;
    loopPtr2 = loopPtr2 + 1;
    operandRecOffset = operandRecOffset + 0x18;
    loopIndex = loopIndex + 1;
  } while (moreOperands);
  return 0;
}

/* FUN_0017ad24 @ 0x17ad24 (260 bytes) */
int FUN_0017ad24(ctx, param_2, param_3)
  int ctx;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int callResult;
  undefined4 uVar3;
  undefined4 block;
  int loopRemaining;
  undefined4 local_38 [8];
  
  block = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  iVar1 = 0;
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  loopRemaining = 4;
  *(undefined4 *)(callResult + 0x98) = 0;
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  do {
    *(undefined4 *)(iVar1 + (int)local_38) = param_2;
    iVar1 = iVar1 + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  ((int (*)())FUN_0017a130)(1,local_38,callResult,*(undefined4 *)(ctx + 0x238));
  IRInst__appendSource(callResult,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  *(undefined1 *)(param_3 + *(int *)(ctx + 0xb0) + 0x9c) = 1;
  iVar1 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar1 + 0x14) & 0x200) == 0) {
    IRInst__appendSource(iVar1,*(undefined4 *)(iVar1 + 0x8c));
    iVar1 = *(int *)(ctx + 0xb0);
  }
  Block__insertInstAfter(block,iVar1,callResult);
  return callResult;
}

/* FUN_0017ae28 @ 0x17ae28 (172 bytes) */
int FUN_0017ae28(ctx, operandIndex, param_3, param_4, negateFlag, absFlag, compiler)
  int ctx;
  int operandIndex;
  int param_3;
  undefined4 param_4;
  undefined4 negateFlag;
  undefined4 absFlag;
  int compiler;
{
  int operandRef;
  int operandRecord;
  undefined4 *allocation;
  undefined4 arena;
  int iVar3;
  undefined4 *puVar4;
  
  operandRef = *(int *)(param_3 + 0x8c);
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    puVar4 = allocation + 1;
    *allocation = arena;
    ValueKey__init(puVar4,param_3,compiler);
    FUN_00174e0c(puVar4);
    ValueKey__propagateLaneValues(puVar4);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(param_3 + 0x158) + 0xb0),puVar4);
  }
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),operandIndex,operandRef);
  if (operandIndex == 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x9c) = param_4;
  }
  else {
    operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),operandIndex);
    *(undefined4 *)(operandRecord + 0x10) = param_4;
  }
  iVar3 = operandIndex * 0x18 + 0x80;
  IROperand__setModifierBits(iVar3 + *(int *)(ctx + 0xb0) + 0xc,1,negateFlag);
  IROperand__setModifierBits(iVar3 + *(int *)(ctx + 0xb0) + 0xc,2,absFlag);
  return param_3;
}

/* FUN_0017af58 @ 0x17af58 (200 bytes) */
int FUN_0017af58(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  int loopIndex;
  int loopRemaining;
  undefined4 *exprRecord;
  int iVar6;
  int *loopPtr2;
  undefined4 local_28 [6];
  
  loopPtr2 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(param_2 + 0xb0),0);
  iVar6 = 0;
  bVar1 = false;
  bVar2 = true;
  loopIndex = 0;
  local_28[0] = *(undefined4 *)(loopRemaining + 0x10);
  loopRemaining = 4;
  do {
    if (*(char *)((int)local_28 + loopIndex) != '\x01') {
      if (bVar2) {
        iVar6 = *loopPtr2;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*loopPtr2 != iVar6) goto LAB_0017affc;
    }
    loopIndex = loopIndex + 1;
    loopPtr2 = loopPtr2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  if (bVar1) {
    exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar6);
    *param_1 = *exprRecord;
  }
  else {
LAB_0017affc:
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_0017b020 @ 0x17b020 (268 bytes) */
int FUN_0017b020(ctx, param_2)
  int ctx;
  int param_2;
{
  int *elementRef;
  int *piVar1;
  int iVar2;
  uint vectorFilledCount;
  uint uVar4;
  uint *vector;
  int iVar6;
  
  vector = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  vectorFilledCount = vector[1];
  uVar4 = vectorFilledCount - 1;
  if (uVar4 < *vector) {
    if (vectorFilledCount <= uVar4) {
      _memset(vectorFilledCount * 4 + vector[2],0,(uVar4 - vectorFilledCount) * 4 + 4);
      vector[1] = vectorFilledCount;
    }
    elementRef = (int *)(uVar4 * 4 + vector[2]);
  }
  else {
    elementRef = (int *)Vector__elementRefGrow(vector,uVar4);
  }
  iVar6 = *elementRef;
  piVar1 = *(int **)(iVar6 + 0xb0);
  iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
  if (((iVar2 != 0) &&
      (iVar2 = IRInst__getOperandRecord(*(undefined4 *)(iVar6 + 0xb0),0), *(int *)(iVar2 + 0x10) == 0)) &&
     (iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1), *(int *)(iVar2 + 0x10) == 0x10203)) {
    return 1;
  }
  return 0;
}

/* ValueKey__mixLiteralSources @ 0x17b12c (2112 bytes) */
int ValueKey__mixLiteralSources(key)
  int key;
{
  int slotOffset;
  undefined4 operandKey;
  undefined4 savedIdentitySelect;
  undefined4 foldedHandle;
  undefined4 defaultSelectWord;
  int literalIndex;
  int operandNumber;
  int isForwardableMov;
  int isRepresentable;
  int valueNumber;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  uint *vector2;
  int inst2;
  int operandIndex;
  int inst;
  int firstUnwrittenComponentResult;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  bool moreIterations;
  byte laneSelectByte;
  int *literalMovTableBase;
  undefined4 operandRegisterKind;
  int loopIndex2;
  int movOrFlag;
  int loopIndex3;
  int *loopPtr7;
  float *literalRecord;
  int operandSource;
  int *loopPtr5;
  int *loopPtr6;
  undefined4 *loopPtr8;
  undefined4 staleArg5;
  undefined4 staleArg6;
  code *a6;
  int laneUsedPtr;
  int operandIndex2;
  uint lastEntryIndex;
  undefined1 *loopPtr9;
  uint lastEntryIndex2;
  char *loopPtr4;
  uint *vector;
  int loopIndex;
  double literalValueArg;
  undefined8 literalResult;
  int literalMovTable [6];
  undefined1 literalCountPad [4];
  int literalCountByOperand [4];
  undefined4 identitySelects [4];
  undefined4 identitySelectsTail;
  undefined4 defaultSelects [5];
  undefined4 literalPool [23];
  float foldedValue;
  int changed;
  int *literalMovAlias;
  undefined1 *literalCountPadAlias;
  int *literalCountAlias;
  undefined *picBaseB;
  undefined4 *literalPoolAlias;
  undefined *picBaseA;
  int *literalMovTableAlias;
  
  loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0xb);
  if (((loopIndex2 == 0) || (loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0x3a), loopIndex2 == 0)) ||
     (*(int *)(*(int *)(key + 0x238) + 0x664) <=
      *(int *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x228))) {
    changed = 0;
  }
  else {
    literalPoolAlias = literalPool;
    loopIndex2 = 0;
    do {
      loopPtr8 = literalPoolAlias + loopIndex2 * 4;
      loopIndex = 4;
      do {
        *loopPtr8 = 0xbf800000;
        loopPtr8 = loopPtr8 + 1;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      moreIterations = loopIndex2 != 4;
      loopIndex2 = loopIndex2 + 1;
    } while (moreIterations);
    picBaseB = &DAT_001ab134;
    literalCountPadAlias = literalCountPad;
    loopIndex = 5;
    picBaseA = &DAT_001ab134;
    loopIndex2 = 0;
    do {
      *(undefined4 *)((int)literalMovTable + loopIndex2 + 4) = 0;
      loopPtr9 = literalCountPadAlias;
      *(undefined4 *)((int)identitySelects + loopIndex2) = 0x1010101;
      *(undefined4 *)(loopPtr9 + loopIndex2) = 0;
      *(undefined4 *)((int)defaultSelects + loopIndex2) = 0x4040404;
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopPtr7 = literalMovTable + 2;
    loopPtr6 = literalCountByOperand;
    literalMovTableAlias = literalMovTable;
    loopIndex = key + 0x170;
    laneUsedPtr = key + 0x224;
    loopIndex2 = 0x18;
    changed = 0;
    literalMovAlias = loopPtr7;
    literalCountAlias = loopPtr6;
    for (operandIndex2 = 1;
        loopIndex3 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        operandIndex2 <= loopIndex3; operandIndex2 = operandIndex2 + 1) {
      loopIndex3 = *(int *)(key + 0xb0);
      if ((operandIndex2 < 1) || (operandSource = IRInst__getOperandSource(loopIndex3,operandIndex2), operandSource == 0)) {
        operandRegisterKind = *(undefined4 *)(loopIndex2 + loopIndex3 + 0x98);
      }
      else {
        loopIndex3 = IRInst__getOperandSource(loopIndex3,operandIndex2);
        operandRegisterKind = *(undefined4 *)(loopIndex3 + 0x98);
      }
      loopIndex3 = RegKind__flagBit6(operandRegisterKind);
      if (loopIndex3 == 0) {
        loopPtr4 = (char *)(laneUsedPtr + 4);
        loopPtr5 = (int *)(loopIndex + 8);
        loopIndex3 = 0;
        do {
          if (*loopPtr4 != '\0') {
            operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex2);
            literalMovTableBase = literalMovTableAlias;
            laneSelectByte = *(byte *)(loopIndex3 + operandRecord2 + 0x10);
            slotOffset = (uint)laneSelectByte + operandIndex2 * 4;
            *(undefined1 *)((int)literalMovTableAlias + slotOffset + 0x2c) = 0;
            *(byte *)((int)literalMovTableAlias + slotOffset + 0x40) = laneSelectByte;
            if (*loopPtr5 < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*loopPtr5);
              movOrFlag = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                ((double)*literalRecord);
              if (movOrFlag != 0) {
                if (*loopPtr7 == 0) {
                  movOrFlag = ((int (*)())FUN_00179138)(key,operandIndex2);
                  *loopPtr7 = movOrFlag;
                  *loopPtr6 = 1;
                  changed = 1;
                }
                literalResult = ((int (*)())ValueKey__findOrInsertLiteral)(movOrFlag,literalPoolAlias,operandIndex2,(double)*literalRecord);
                literalIndex = (int)((ulonglong)literalResult >> 0x20);
                if (*loopPtr6 < literalIndex) {
                  ((void (*)())IRInst__setLiteralOperandAndSource)(*loopPtr7,(int)literalResult,literalIndex,*(undefined4 *)(key + 0x238),
                               (double)*literalRecord);
                  *loopPtr6 = literalIndex;
                }
                a6 = *(code **)(*(int *)*loopPtr7 + 0x88);
                (*a6)((int *)*loopPtr7,literalIndex,(uint)laneSelectByte,loopIndex3,staleArg5,staleArg6,a6);
                *(undefined1 *)((int)literalMovTableBase + slotOffset + 0x40) = 4;
              }
            }
          }
          moreIterations = loopIndex3 != 3;
          loopPtr4 = loopPtr4 + 1;
          loopPtr5 = loopPtr5 + 1;
          loopIndex3 = loopIndex3 + 1;
        } while (moreIterations);
      }
      loopIndex2 = loopIndex2 + 0x18;
      laneUsedPtr = laneUsedPtr + 4;
      loopIndex = loopIndex + 0x10;
      loopPtr7 = loopPtr7 + 1;
      loopPtr6 = loopPtr6 + 1;
    }
    loopIndex2 = 0;
    loopIndex = 5;
    do {
      loopPtr9 = literalCountPadAlias;
      if (*(int *)((int)literalMovTable + loopIndex2 + 4) == 0) {
        defaultSelectWord = *(undefined4 *)(((unsigned char *)0x000050a8) + (int)picBaseB);
        *(undefined4 *)((int)identitySelects + loopIndex2) = *(undefined4 *)(((unsigned char *)0x0000509c) + (int)picBaseA);
        *(undefined4 *)(loopPtr9 + loopIndex2) = 0;
        *(undefined4 *)((int)defaultSelects + loopIndex2) = defaultSelectWord;
      }
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopPtr7 = *(int **)(key + 0xb0);
    if ((((loopPtr7[5] & 0x200U) != 0) && (loopPtr7[0x48] == 0)) && (loopPtr7[0x49] == 0)) {
      loopIndex2 = ((int (*)())FUN_001789f0)(key);
      if (loopIndex2 != 0) {
        loopIndex = 0;
        loopIndex2 = key;
        do {
          operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
          if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
            inst = *(int *)(key + 0xb0);
            vector = *(uint **)(*(int *)(*(int *)(inst + 0x84) * 0x18 + inst + 0x8c) + 0x2c);
            vectorFilledCount2 = vector[1];
            lastEntryIndex = vectorFilledCount2 - 1;
            if (lastEntryIndex < *vector) {
              if (vectorFilledCount2 <= lastEntryIndex) {
                _memset(vectorFilledCount2 * 4 + vector[2],0,(lastEntryIndex - vectorFilledCount2) * 4 + 4);
                vector[1] = vectorFilledCount2;
                inst = *(int *)(key + 0xb0);
              }
              loopPtr7 = (int *)(lastEntryIndex * 4 + vector[2]);
            }
            else {
              loopPtr7 = (int *)Vector__elementRefGrow(vector,lastEntryIndex);
              inst = *(int *)(key + 0xb0);
            }
            operandIndex2 = *loopPtr7;
            operandRecord = IRInst__getOperandRecord(inst,0);
            literalMovTable[0] = *(int *)(operandRecord + 0x10);
            valueNumber = *(int *)(loopIndex * 4 + operandIndex2 + 0x20);
            if (valueNumber < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),valueNumber);
              isRepresentable = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                 ((double)*literalRecord);
              if (isRepresentable != 0) {
                loopPtr7 = literalMovAlias;
                loopPtr6 = literalCountAlias;
                for (operandIndex = 1;
                    operandIndex2 = (**(code **)(**(int **)(key + 0xb0) + 0x14))
                                       (*(int **)(key + 0xb0)), operandIndex <= operandIndex2;
                    operandIndex = operandIndex + 1) {
                  if (*loopPtr7 == 0) {
                    loopIndex3 = ((int (*)())FUN_00179138)(key,operandIndex);
                    operandIndex2 = operandIndex * 4;
                    *loopPtr7 = loopIndex3;
                    *loopPtr6 = 1;
                    loopPtr9 = (undefined1 *)((int)defaultSelects + operandIndex * 4);
                    loopPtr8 = identitySelects + operandIndex;
                    loopIndex3 = 0;
                    do {
                      if (*(char *)((int)literalMovTable + loopIndex3) == '\0') {
                        operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex);
                        *loopPtr9 = *(undefined1 *)(loopIndex3 + operandRecord2 + 0x10);
                        *(undefined1 *)loopPtr8 = 0;
                        (**(code **)(**(int **)(key + 0xb0) + 0x88))
                                  (*(int **)(key + 0xb0),operandIndex,loopIndex3,loopIndex3);
                      }
                      moreIterations = loopIndex3 != 3;
                      loopPtr9 = loopPtr9 + 1;
                      loopPtr8 = (undefined4 *)((int)loopPtr8 + 1);
                      loopIndex3 = loopIndex3 + 1;
                    } while (moreIterations);
                    changed = 1;
                  }
                  else {
                    operandIndex2 = operandIndex << 2;
                  }
                  foldedHandle = IRInst__foldCompareConstResult(&foldedValue, *(undefined4 *)(key + 0xb0), operandIndex, *(unsigned int *)literalRecord, *(undefined4 *)(key + 0x238));
                  literalValueArg = (double)foldedValue;
                  literalResult = ((int (*)())ValueKey__findOrInsertLiteral)(foldedHandle,literalPoolAlias,operandIndex,literalValueArg);
                  loopIndex3 = (int)((ulonglong)literalResult >> 0x20);
                  if (*loopPtr6 < loopIndex3) {
                    ((void (*)())IRInst__setLiteralOperandAndSource)(*loopPtr7,(int)literalResult,loopIndex3,*(undefined4 *)(key + 0x238),literalValueArg
                                );
                    *loopPtr6 = loopIndex3;
                  }
                  loopPtr6 = loopPtr6 + 1;
                  firstUnwrittenComponentResult = SelectWord__firstUnwrittenComponent(*(undefined4 *)((int)identitySelects + operandIndex2));
                  loopPtr5 = (int *)*loopPtr7;
                  loopPtr7 = loopPtr7 + 1;
                  (**(code **)(*loopPtr5 + 0x88))(loopPtr5,loopIndex3,firstUnwrittenComponentResult,firstUnwrittenComponentResult);
                  *(undefined1 *)((int)identitySelects + firstUnwrittenComponentResult + operandIndex2) = 0;
                  (**(code **)(**(int **)(key + 0xb0) + 0x88))
                            (*(int **)(key + 0xb0),operandIndex,loopIndex,firstUnwrittenComponentResult);
                }
                *(undefined1 *)(loopIndex + *(int *)(key + 0xb0) + 0x9c) = 0;
                *(float **)(loopIndex2 + 0x30) = literalRecord;
              }
            }
          }
          moreIterations = loopIndex != 3;
          loopIndex2 = loopIndex2 + 4;
          loopIndex = loopIndex + 1;
        } while (moreIterations);
      }
      loopPtr7 = *(int **)(key + 0xb0);
    }
    loopIndex2 = 1;
    while (loopIndex = (**(code **)(*loopPtr7 + 0x14))(loopPtr7), loopIndex2 <= loopIndex) {
      loopIndex = loopIndex2 + 1;
      inst2 = literalMovTable[loopIndex];
      if (inst2 != 0) {
        *(int *)(inst2 + 0x9c) = literalCountByOperand[loopIndex2 + 4];
        savedIdentitySelect = (&identitySelectsTail)[loopIndex];
        loopIndex2 = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(loopIndex2 + 0x10) = savedIdentitySelect;
        IRInst__removeDefaultSelectOperands(inst2,*(undefined4 *)(key + 0x238));
      }
      loopPtr7 = *(int **)(key + 0xb0);
      loopIndex2 = loopIndex;
    }
    loopPtr7 = literalMovTable + 2;
    for (loopIndex2 = 1;
        loopIndex = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        loopIndex2 <= loopIndex; loopIndex2 = loopIndex2 + 1) {
      loopIndex = *loopPtr7;
      if (loopIndex != 0) {
        loopPtr6 = (int *)IRInst__getOperandSource(loopIndex,1);
        isForwardableMov = (**(code **)(*loopPtr6 + 0x60))(loopPtr6);
        if (isForwardableMov != 0) {
          sourceDef = IRInst__getOperandSource(loopIndex,1);
          FUN_0010c670(sourceDef,loopIndex,*(undefined4 *)(key + 0x238));
        }
      }
      loopPtr7 = loopPtr7 + 1;
    }
    loopPtr7 = literalMovTable + 2;
    loopIndex = 0x18;
    loopIndex2 = key;
    for (operandNumber = 1;
        operandIndex2 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        operandNumber <= operandIndex2; operandNumber = operandNumber + 1) {
      operandIndex2 = *loopPtr7;
      if (operandIndex2 != 0) {
        vector2 = *(uint **)(*(int *)(loopIndex + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
        vectorFilledCount = vector2[1];
        lastEntryIndex2 = vectorFilledCount - 1;
        if (lastEntryIndex2 < *vector2) {
          if (vectorFilledCount <= lastEntryIndex2) {
            _memset(vectorFilledCount * 4 + vector2[2],0,(lastEntryIndex2 - vectorFilledCount) * 4 + 4);
            vector2[1] = vectorFilledCount;
          }
          loopPtr8 = (undefined4 *)(lastEntryIndex2 * 4 + vector2[2]);
        }
        else {
          loopPtr8 = (undefined4 *)Vector__elementRefGrow(vector2,lastEntryIndex2);
        }
        operandKey = *loopPtr8;
        ValueKey__fillSourceLaneUsage(operandKey);
        ValueKey__fill(operandKey);
        FUN_00174e0c(operandKey);
        FUN_00175b40(operandKey);
        ValueKey__propagateLaneValues(operandKey);
        *(int *)(loopIndex2 + 0x214) = operandIndex2;
      }
      loopPtr7 = loopPtr7 + 1;
      loopIndex = loopIndex + 0x18;
      loopIndex2 = loopIndex2 + 4;
    }
    if (changed != 0) {
      loopIndex2 = 4;
      do {
        loopIndex2 = loopIndex2 + -1;
      } while (loopIndex2 != 0);
    }
  }
  return changed;
}

/* FUN_0017b96c @ 0x17b96c (748 bytes) */
int FUN_0017b96c(ctx)
  int ctx;
{
  uint vectorFilledCount2;
  uint *vector2;
  bool bVar1;
  bool bVar2;
  int loopIndex3;
  int *elementRef;
  undefined4 *elementRef2;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint vectorFilledCount;
  int iVar10;
  int loopIndex;
  uint *vector;
  int loopIndex2;
  undefined4 local_38 [8];
  
  if ((*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) ||
     (loopIndex3 = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0)), loopIndex3 == 0
     )) {
    return 0;
  }
  loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
  loopIndex3 = SelectWord__isIdentity(*(undefined4 *)(loopIndex3 + 0x10));
  if (loopIndex3 == 0) {
    loopIndex3 = *(int *)(ctx + 0xb0);
    vector = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    vectorFilledCount = vector[1];
    uVar7 = vectorFilledCount - 1;
    if (uVar7 < *vector) {
      if (vectorFilledCount <= uVar7) {
        _memset(vectorFilledCount * 4 + vector[2],0,(uVar7 - vectorFilledCount) * 4 + 4);
        vector[1] = vectorFilledCount;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      elementRef = (int *)(uVar7 * 4 + vector[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vector,uVar7);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    iVar10 = *elementRef;
    bVar2 = true;
    loopIndex2 = 0;
    loopIndex = iVar10;
    while( true ) {
      loopIndex3 = IRInst__getOperandRecord(loopIndex3,0);
      if (*(char *)(loopIndex2 + loopIndex3 + 0x10) != '\x01') {
        loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
        loopIndex3 = Ptr__equalNonNull(*(undefined4 *)
                              ((uint)*(byte *)(loopIndex2 + loopIndex3 + 0x10) * 4 + iVar10 + 0x20),
                             *(undefined4 *)(loopIndex + 0x20));
        if (loopIndex3 == 0) {
          bVar2 = false;
        }
      }
      bVar1 = loopIndex2 == 3;
      loopIndex = loopIndex + 4;
      loopIndex2 = loopIndex2 + 1;
      if (bVar1) break;
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    if (bVar2) {
      loopIndex3 = 0;
      local_38[0] = 0x4040404;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex3 + loopIndex + 0x10) != '\x01') {
          *(char *)((int)local_38 + loopIndex3) = (char)loopIndex3;
        }
        uVar8 = local_38[0];
        bVar2 = loopIndex3 != 3;
        loopIndex3 = loopIndex3 + 1;
      } while (bVar2);
      uVar6 = 1;
      loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
      *(undefined4 *)(loopIndex3 + 0x10) = uVar8;
      goto LAB_0017bb2c;
    }
  }
  uVar6 = 0;
LAB_0017bb2c:
  loopIndex3 = *(int *)(ctx + 0xb0);
  if ((*(int *)(loopIndex3 + 0x120) != 0) && (*(int *)(loopIndex3 + 0x124) == 0)) {
    vector2 = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    vectorFilledCount2 = vector2[1];
    uVar7 = vectorFilledCount2 - 1;
    if (uVar7 < *vector2) {
      if (vectorFilledCount2 <= uVar7) {
        _memset(vectorFilledCount2 * 4 + vector2[2],0,(uVar7 - vectorFilledCount2) * 4 + 4);
        vector2[1] = vectorFilledCount2;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      elementRef2 = (undefined4 *)(uVar7 * 4 + vector2[2]);
    }
    else {
      elementRef2 = (undefined4 *)Vector__elementRefGrow(vector2,uVar7);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    uVar7 = *(uint *)(loopIndex3 + 0xb8);
    loopIndex = 0;
    uVar8 = *elementRef2;
    while( true ) {
      loopIndex3 = IRInst__getOperandRecord(loopIndex3,0);
      if (*(char *)(loopIndex + loopIndex3 + 0x10) != '\x01') {
        loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
        loopIndex3 = FUN_001764e0(uVar8,(uint)*(byte *)(loopIndex + loopIndex3 + 0x10));
        if (loopIndex3 == 0) {
          return uVar6;
        }
        if ((uVar7 & 1) != 0) {
          return uVar6;
        }
      }
      bVar2 = loopIndex == 3;
      loopIndex = loopIndex + 1;
      if (bVar2) break;
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    uVar6 = 1;
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
  }
  return uVar6;
}

