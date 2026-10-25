#include "decls.h"

/* FUN_0017bc58 @ 0x17bc58 (288 bytes) */
int FUN_0017bc58(inst, param_2, param_3, compilerCtx)
  undefined4 inst;
  uint param_2;
  int param_3;
  undefined4 compilerCtx;
{
  int *callResult2;
  int *piVar2;
  int callResult;
  undefined4 uVar4;
  uint local_28 [3];
  
  callResult2 = (int *)IRInst__getOperandSource(inst,1);
  while( true ) {
    callResult = (**(code **)(*callResult2 + 0x40))(callResult2);
    if (callResult != 0) {
      return callResult2;
    }
    callResult = IRInst__getOperandRecord(callResult2,0);
    uVar4 = *(undefined4 *)(callResult + 0x10);
    callResult = FUN_00176534(inst,callResult2);
    if (callResult == 2) break;
    if ((callResult == 0) && (WriteMask__fromSelectWord(local_28,uVar4), (param_2 & local_28[0]) != DAT_001b01e0)) {
      return callResult2;
    }
    callResult2 = (int *)IRInst__getOperandSource(callResult2,3);
  }
  if ((param_3 != 0) && (piVar2 = (int *)IRInst__getOperandSource(inst,1), callResult2 != piVar2)) {
    IRInst__setOperandSource(inst,1,callResult2,0,compilerCtx);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* FUN_0017bd78 @ 0x17bd78 (388 bytes) */
int FUN_0017bd78(ctx, operandIndex, param_3, param_4)
  int ctx;
  int operandIndex;
  int param_3;
  undefined4 param_4;
{
  int inst;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int node;
  int inst2;
  uint instFlags;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 operandRef;
  undefined4 operandRef2;
  undefined4 saturate;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 local_58;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  inst2 = *(int *)(ctx + 0xb0);
  bVar2 = *(byte *)(param_3 + operandRecord + 0x10);
  instFlags = *(uint *)(inst2 + 0x14);
  uVar3 = *(uint *)(operandIndex * 0x18 + inst2 + 0xa0);
  uVar10 = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  bVar1 = (instFlags >> 9 & 1) == 0;
  if (bVar1) {
    operandRef3 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 0x18 + inst2 + 0x8c);
  }
  destRegister = *(undefined4 *)(inst2 + 0x94);
  destRegisterOffset = *(undefined4 *)(inst2 + 0x98);
  IRInst__reinitAsMov(inst2,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(inst2,0,operandRef2);
  *(undefined4 *)(inst2 + 0x94) = destRegister;
  *(undefined4 *)(inst2 + 0x98) = destRegisterOffset;
  *(undefined4 *)(inst2 + 0x9c) = uVar11;
  *(undefined4 *)(inst2 + 0x120) = saturate;
  *(undefined4 *)(inst2 + 0x124) = param_4;
  IRInst__setOperandRef(inst2,1,operandRef);
  uVar11 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)bVar2 * 4);
  operandRecord = IRInst__getOperandRecord(inst2,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar11;
  IROperand__setModifierBits(inst2 + 0xa4,1,uVar3 & 1);
  IROperand__setModifierBits(inst2 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = uVar10;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(inst2,operandRef3);
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = local_58;
  }
  if ((instFlags & 0x200000) != 0) {
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,inst2);
  return inst2;
}

/* ValueKey__foldDot3SingleLaneSource @ 0x17bf70 (392 bytes) */
int ValueKey__foldDot3SingleLaneSource(ctx)
  int ctx;
{
  int lanesAreUnset;
  int exprRecord;
  bool bVar1;
  int iVar2;
  int iVar3;
  float *exprRecord2;
  int *a0;
  int iVar5;
  undefined4 a3;
  int iVar6;
  undefined4 a4;
  undefined4 a5;
  code *a6;
  int loopRemaining;
  int loopIndex;
  int *piVar9;
  
  loopRemaining = 2;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  iVar2 = *(int *)(exprRecord + 4);
  do {
    a3 = 1;
    a4 = 1;
    a5 = 0;
    lanesAreUnset = ValueKey__lanesAreUnset(ctx,loopRemaining,1,1,1,0);
    if (lanesAreUnset != 0) {
      loopIndex = 0;
      piVar9 = &DAT_001e6134;
      iVar3 = loopRemaining * 4;
      do {
        if ((iVar2 == *(int *)((iVar3 + *piVar9) * 4 + ctx + 0x168)) &&
           (iVar2 == *(int *)((iVar3 + piVar9[1]) * 4 + ctx + 0x168))) {
          exprRecord2 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                                         *(undefined4 *)((iVar3 + piVar9[2]) * 4 + ctx + 0x168))
          ;
          if ((double)*exprRecord2 == 1.0) {
            iVar6 = *(int *)(*(int *)(ctx + 0xb0) + 0x124);
LAB_0017c0b0:
            ((int (*)())FUN_0017bd78)(ctx,(loopRemaining == 1) + 1,loopIndex,iVar6);
            ValueKey__rebuild(ctx);
            return 1;
          }
          iVar6 = ((int (*)())outputScaleExponent)((double)*exprRecord2);
          if (iVar6 != 0) {
            a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
            iVar6 = iVar6 + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
            a6 = *(code **)(*a0 + 0xfc);
            iVar5 = (*a6)(a0,iVar6,*(int *)(ctx + 0xb0),a3,a4,a5,a6);
            if (iVar5 != 0) goto LAB_0017c0b0;
          }
        }
        bVar1 = loopIndex != 2;
        piVar9 = piVar9 + 3;
        loopIndex = loopIndex + 1;
      } while (bVar1);
    }
    loopRemaining = loopRemaining + -1;
    if (loopRemaining == 0) {
      return 0;
    }
  } while( true );
}

/* ValueKey__foldDot4UnitVectorSource @ 0x17c0f8 (332 bytes) */
int ValueKey__foldDot4UnitVectorSource(ctx)
  int ctx;
{
  int exprRecord;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int loopRemaining;
  int iVar9;
  
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
  iVar9 = *(int *)(exprRecord + 4);
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  iVar2 = 1;
  iVar5 = *(int *)(exprRecord + 4);
  loopRemaining = 2;
  iVar1 = ctx + 0x20;
  do {
    iVar7 = *(int *)(iVar1 + 0x16c);
    if ((((iVar9 == iVar7) && (iVar9 == *(int *)(iVar1 + 0x170))) &&
        (iVar9 == *(int *)(iVar1 + 0x174))) && (iVar5 == *(int *)(iVar1 + 0x168))) {
      uVar3 = 0;
      uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
      goto LAB_0017c1c4;
    }
    if (iVar9 == *(int *)(iVar1 + 0x168)) {
      iVar6 = *(int *)(iVar1 + 0x170);
      if (((iVar9 == iVar6) && (iVar6 == *(int *)(iVar1 + 0x174))) && (iVar5 == iVar7)) {
        uVar3 = 1;
        uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
        goto LAB_0017c1c4;
      }
      if (iVar9 == iVar7) {
        if ((iVar9 == *(int *)(iVar1 + 0x174)) && (iVar5 == iVar6)) {
          uVar3 = 2;
          uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
LAB_0017c1c4:
          ((int (*)())FUN_0017bd78)(ctx,iVar2,uVar3,uVar4);
          ValueKey__rebuild(ctx);
          return 1;
        }
        if ((iVar9 == iVar6) && (iVar5 == *(int *)(iVar1 + 0x174))) {
          uVar3 = 3;
          uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124);
          goto LAB_0017c1c4;
        }
      }
    }
    loopRemaining = loopRemaining + -1;
    iVar1 = iVar1 + -0x10;
    if (loopRemaining < 1) {
      return 0;
    }
    iVar2 = (loopRemaining == 1) + 1;
  } while( true );
}

/* FUN_0017c244 @ 0x17c244 (356 bytes) */
int FUN_0017c244(ctx, operandIndex)
  int ctx;
  int operandIndex;
{
  int inst;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  uint uVar2;
  int node;
  int inst2;
  uint instFlags;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 operandRef;
  undefined4 operandRef2;
  undefined4 saturate;
  undefined4 resultScaleCode;
  undefined4 uVar15;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 local_58;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  uVar10 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  resultScaleCode = *(undefined4 *)(inst + 0x124);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  inst2 = *(int *)(ctx + 0xb0);
  uVar15 = *(undefined4 *)(operandRecord + 0x10);
  instFlags = *(uint *)(inst2 + 0x14);
  uVar2 = *(uint *)(operandIndex * 0x18 + inst2 + 0xa0);
  uVar9 = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  bVar1 = (instFlags >> 9 & 1) == 0;
  if (bVar1) {
    operandRef3 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(inst2 + 0x84) * 0x18 + inst2 + 0x8c);
  }
  destRegister = *(undefined4 *)(inst2 + 0x94);
  destRegisterOffset = *(undefined4 *)(inst2 + 0x98);
  IRInst__reinitAsMov(inst2,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(inst2,0,operandRef2);
  *(undefined4 *)(inst2 + 0x98) = destRegisterOffset;
  *(undefined4 *)(inst2 + 0x94) = destRegister;
  *(undefined4 *)(inst2 + 0x9c) = uVar10;
  *(undefined4 *)(inst2 + 0x120) = saturate;
  *(undefined4 *)(inst2 + 0x124) = resultScaleCode;
  IRInst__setOperandRef(inst2,1,operandRef);
  operandRecord = IRInst__getOperandRecord(inst2,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar15;
  IROperand__setModifierBits(inst2 + 0xa4,1,uVar2 & 1);
  IROperand__setModifierBits(inst2 + 0xa4,2,uVar2 >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = uVar9;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(inst2,operandRef3);
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = local_58;
  }
  if ((instFlags & 0x200000) != 0) {
    *(uint *)(inst2 + 0x14) = *(uint *)(inst2 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,inst2);
  return inst2;
}

/* ValueKey__replaceWithSource2IfSourcesEqual23 @ 0x17c41c (136 bytes) */
int ValueKey__replaceWithSource2IfSourcesEqual23(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,2,3);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xe8);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(ctx,2);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c4a4 @ 0x17c4a4 (316 bytes) */
int FUN_0017c4a4(ctx)
  int ctx;
{
  uint uVar1;
  uint uVar2;
  int *a0;
  int iVar3;
  undefined4 mask;
  
  a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
  iVar3 = (**(code **)(*a0 + 0x88))(a0);
  if (((iVar3 == 0) || (iVar3 = Inst__allWrittenLanesSatisfy(ctx,2,3), iVar3 == 0)) ||
     (iVar3 = Inst__allWrittenLanesSatisfy(ctx,1,3), iVar3 == 0)) {
    return 0;
  }
  iVar3 = *(int *)(ctx + 0xb0);
  if ((*(uint *)(iVar3 + 0xb8) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xd0) & 2) != 0) {
    return 0;
  }
  if ((*(uint *)(iVar3 + 0xe8) & 2) != 0) {
    return 0;
  }
  uVar1 = *(uint *)(iVar3 + 0xe8) & 1;
  uVar2 = *(uint *)(iVar3 + 0xd0) & 1;
  if ((*(uint *)(iVar3 + 0xb8) & 1) == 0) {
    if (uVar2 != 0) {
      return 0;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  else {
    if (uVar2 == 0) {
      if (uVar1 == 0) {
        return 0;
      }
      ((int (*)())FUN_0017c244)(ctx,2);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,1);
      iVar3 = *(int *)(ctx + 0xb0);
      mask = 1;
      goto LAB_0017c5b4;
    }
    if (uVar1 != 0) {
      return 0;
    }
  }
  ((int (*)())FUN_0017c244)(ctx,2);
  iVar3 = *(int *)(ctx + 0xb0);
  mask = 2;
LAB_0017c5b4:
  IROperand__setModifierBits(iVar3 + 0xa4,mask,1);
  ValueKey__rebuild(ctx);
  return 1;
}

/* FUN_0017c5e0 @ 0x17c5e0 (404 bytes) */
int FUN_0017c5e0(ctx)
  int ctx;
{
  int findInPtrSetResult;
  int compareCondition;
  int operandRecord;
  bool bVar1;
  bool bVar2;
  int compareCode;
  int inst;
  undefined4 *exprRecord;
  int iVar6;
  int iVar7;
  int loopIndex;
  int iVar9;
  
  bVar2 = false;
  compareCode = signToCompareCode(0);
  loopIndex = 0;
  iVar7 = -1;
  iVar9 = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    iVar6 = iVar7;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      iVar6 = *(int *)(iVar9 + 0x178);
      if (iVar6 < 0) {
        exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar6);
        iVar6 = signToCompareCode(*exprRecord);
        inst = *(int *)(ctx + 0xb0);
      }
      else {
        if (iVar6 < 1) {
          return 0;
        }
        findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar6);
        inst = *(int *)(ctx + 0xb0);
        iVar6 = *(int *)(findInPtrSetResult + 0xc);
        if ((*(uint *)(inst + 0xb8) & 2) != 0) {
          iVar6 = (DAT_001e61d0)[iVar6];
        }
        bVar2 = true;
        if ((*(uint *)(inst + 0xb8) & 1) != 0) {
          iVar6 = *(int *)(&DAT_001e61b8 + iVar6 * 4);
        }
      }
      compareCondition = IRInst__getCompareCondition(inst);
      iVar6 = *(int *)(&DAT_001e61e8 + (compareCondition * 6 + iVar6 * 0x30 + compareCode) * 4);
      if (iVar6 == 1) {
        iVar6 = 2;
      }
      else if (iVar6 == 2) {
        iVar6 = 3;
      }
      else {
        if (iVar6 == 0) {
          return 0;
        }
        iVar6 = 0;
      }
      if ((iVar7 != -1) && (bVar1 = iVar6 != iVar7, iVar6 = iVar7, bVar1)) {
        return 0;
      }
    }
    bVar1 = loopIndex == 3;
    iVar9 = iVar9 + 4;
    loopIndex = loopIndex + 1;
    iVar7 = iVar6;
    if (bVar1) {
      if (bVar2) {
        iVar7 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(ctx,iVar6);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* ValueKey__foldMulByPlusMinusOne @ 0x17c774 (276 bytes) */
int ValueKey__foldMulByPlusMinusOne(ctx)
  int ctx;
{
  int lanesAllMatch;
  int exprRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  undefined4 uVar4;
  
  loopIndex = 1;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  uVar4 = *(undefined4 *)(exprRecord + 4);
  do {
    lanesAllMatch = Inst__writtenLanesAllMatchValue(ctx,uVar4,loopIndex);
    if (lanesAllMatch != 0) {
      ((int (*)())FUN_0017c244)(ctx,(loopIndex == 1) + 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = 1;
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0xbf800000);
  uVar4 = *(undefined4 *)(exprRecord + 4);
  do {
    lanesAllMatch = Inst__writtenLanesAllMatchValue(ctx,uVar4,loopIndex);
    if (lanesAllMatch != 0) {
      iVar2 = (loopIndex == 1) + 1;
      ((int (*)())FUN_0017c244)(ctx,iVar2);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   *(uint *)(iVar2 * 0x18 + *(int *)(ctx + 0xb0) + 0xa0) & 1 ^ 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* ValueKey__replaceWithSource1IfSourcesEqual @ 0x17c888 (136 bytes) */
int ValueKey__replaceWithSource1IfSourcesEqual(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(ctx,1);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c910 @ 0x17c910 (516 bytes) */
int FUN_0017c910(ctx)
  int ctx;
{
  int findInPtrSetResult;
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int operandRecord;
  undefined4 *exprRecord;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int loopIndex;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *loopPtr2;
  int local_64 [10];
  
  bVar2 = false;
  loopIndex = 0;
  iVar11 = ctx + 0x170;
  iVar8 = -1;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      loopPtr2 = local_64;
      iVar12 = 0x98;
      for (operandRecord = 1;
          iVar6 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= iVar6; operandRecord = operandRecord + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = signToCompareCode(*exprRecord);
          *loopPtr2 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr2 = iVar6;
          iVar7 = *(int *)(ctx + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopPtr2 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *loopPtr2 = *(int *)(&DAT_001e61b8 + *loopPtr2 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        loopPtr2 = loopPtr2 + 1;
        piVar13 = piVar13 + 4;
      }
      if ((local_64[0] != 3) || (local_64[1] != 3)) {
        iVar9 = *(int *)(&DAT_001e6014 + (local_64[0] * 6 + local_64[1]) * 4);
        if (iVar9 == 1) {
          iVar9 = 1;
        }
        else if (iVar9 == 2) {
          iVar9 = 2;
        }
        else {
          if (iVar9 == 0) {
            return 0;
          }
          iVar9 = 0;
        }
        if ((iVar8 != -1) && (bVar1 = iVar9 != iVar8, iVar9 = iVar8, bVar1)) {
          return 0;
        }
      }
    }
    bVar1 = loopIndex == 3;
    iVar11 = iVar11 + 4;
    loopIndex = loopIndex + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(ctx,iVar9);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* FUN_0017cb14 @ 0x17cb14 (516 bytes) */
int FUN_0017cb14(ctx)
  int ctx;
{
  int findInPtrSetResult;
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int operandRecord;
  undefined4 *exprRecord;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int loopIndex;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *loopPtr2;
  int local_64 [10];
  
  bVar2 = false;
  loopIndex = 0;
  iVar11 = ctx + 0x170;
  iVar8 = -1;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      loopPtr2 = local_64;
      iVar12 = 0x98;
      for (operandRecord = 1;
          iVar6 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= iVar6; operandRecord = operandRecord + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = signToCompareCode(*exprRecord);
          *loopPtr2 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr2 = iVar6;
          iVar7 = *(int *)(ctx + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopPtr2 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *loopPtr2 = *(int *)(&DAT_001e61b8 + *loopPtr2 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        loopPtr2 = loopPtr2 + 1;
        piVar13 = piVar13 + 4;
      }
      if ((local_64[0] != 3) || (local_64[1] != 3)) {
        iVar9 = *(int *)(&DAT_001e60a4 + (local_64[0] * 6 + local_64[1]) * 4);
        if (iVar9 == 1) {
          iVar9 = 1;
        }
        else if (iVar9 == 2) {
          iVar9 = 2;
        }
        else {
          if (iVar9 == 0) {
            return 0;
          }
          iVar9 = 0;
        }
        if ((iVar8 != -1) && (bVar1 = iVar9 != iVar8, iVar9 = iVar8, bVar1)) {
          return 0;
        }
      }
    }
    bVar1 = loopIndex == 3;
    iVar11 = iVar11 + 4;
    loopIndex = loopIndex + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(ctx,iVar9);
      ValueKey__rebuild(ctx);
      return 1;
    }
  } while( true );
}

/* FUN_0017cd18 @ 0x17cd18 (164 bytes) */
int FUN_0017cd18(param_1)
  int param_1;
{
  bool bVar1;
  int callResult;
  undefined4 uVar3;
  int loopIndex;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(param_1 + 0x238),0);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(param_1,uVar3,loopIndex);
    if (callResult != 0) {
      callResult = FUN_0017737c(param_1,0,3);
      if (callResult == 0) {
        ((int (*)())FUN_0017c244)(param_1,3);
      }
      else {
        FUN_00177548(param_1);
      }
      ValueKey__rebuild(param_1);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017cdbc @ 0x17cdbc (192 bytes) */
int FUN_0017cdbc(param_1)
  int param_1;
{
  int callResult;
  int loopIndex;
  undefined4 uVar3;
  undefined4 uVar4;
  
  loopIndex = 1;
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(param_1 + 0x238),0);
  uVar4 = *(undefined4 *)(callResult + 4);
  do {
    uVar3 = 2;
    do {
      callResult = Inst__writtenLanesAllMatchValue(param_1,uVar4,loopIndex);
      if (callResult != 0) {
        callResult = FUN_0017737c(param_1,0,uVar3);
        if (callResult == 0) {
          ((int (*)())FUN_0017c244)(param_1,uVar3);
        }
        else {
          FUN_00177548(param_1);
        }
        ValueKey__rebuild(param_1);
        return 1;
      }
      loopIndex = loopIndex + 1;
      if (2 < loopIndex) {
        return 0;
      }
      uVar3 = 1;
    } while (loopIndex != 1);
  } while( true );
}

/* FUN_0017ce7c @ 0x17ce7c (284 bytes) */
int FUN_0017ce7c(ctx, param_2)
  int ctx;
  int param_2;
{
  int operandRecord;
  bool bVar1;
  uint uVar2;
  int node;
  int *vector;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 operandRef2;
  undefined4 afterInst;
  undefined4 block;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 operandRef;
  undefined4 uVar14;
  undefined4 uVar15;
  int member0xb0;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(operandRecord + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  uVar10 = *(undefined4 *)(member0xb0 + 0x120);
  uVar11 = *(undefined4 *)(member0xb0 + 0x124);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    operandRef2 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar14 = *(undefined4 *)(member0xb0 + 0x94);
  uVar15 = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef);
  *(undefined4 *)(member0xb0 + 0x98) = uVar15;
  *(undefined4 *)(member0xb0 + 0x94) = uVar14;
  *(undefined4 *)(member0xb0 + 0x9c) = uVar12;
  *(undefined4 *)(member0xb0 + 0x120) = uVar10;
  *(undefined4 *)(member0xb0 + 0x124) = uVar11;
  IRInst__setOperandRef(member0xb0,1,*(undefined4 *)(param_2 + 0xc));
  uVar12 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar12;
  if (*(int *)(param_2 + 0x18) != 0) {
    IROperand__setModifierBits(member0xb0 + 0xa4,1,1);
  }
  *(undefined4 *)(member0xb0 + 0x120) = uVar10;
  *(undefined4 *)(member0xb0 + 0x124) = uVar11;
  vector = *(int **)(*(int *)(member0xb0 + 0xa4) + 0x18);
  if (*vector == 0) {
    puVar5 = (undefined4 *)Vector__elementRefGrow(vector,0);
  }
  else {
    if (vector[1] == 0) {
      *(undefined4 *)vector[2] = 0;
      vector[1] = 1;
    }
    puVar5 = (undefined4 *)vector[2];
  }
  *(undefined4 *)(ctx + 0x214) = *puVar5;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef2);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar6;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* FUN_0017d06c @ 0x17d06c (368 bytes) */
int FUN_0017d06c(ctx, param_2, param_3, negateFlag)
  int ctx;
  int param_2;
  undefined4 *param_3;
  undefined4 negateFlag;
{
  int operandRef;
  int operandRecord;
  undefined4 arenaAt378;
  bool bVar1;
  uint uVar2;
  int node;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 operandRef3;
  undefined4 afterInst;
  undefined4 block;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 operandRef2;
  undefined4 uVar12;
  int member0xb0;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef2 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(operandRecord + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    operandRef3 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar12 = *(undefined4 *)(member0xb0 + 0x94);
  uVar10 = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef2);
  operandRef = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(member0xb0 + 0x94) = uVar12;
  *(undefined4 *)(member0xb0 + 0x98) = uVar10;
  *(undefined4 *)(member0xb0 + 0x9c) = uVar9;
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    puVar4 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *puVar4 = arenaAt378;
    puVar4 = puVar4 + 1;
    ValueKey__init(puVar4,param_2,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(puVar4);
    ValueKey__propagateLaneValues(puVar4);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar4);
  }
  IRInst__setOperandRef(member0xb0,1,operandRef);
  uVar9 = *param_3;
  operandRecord = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar9;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,negateFlag);
  *(int *)(ctx + 0x214) = param_2;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef3);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar5;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* FUN_0017d26c @ 0x17d26c (196 bytes) */
int FUN_0017d26c(ctx, param_2)
  int ctx;
  undefined4 param_2;
{
  int node;
  int operandRecord2;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int operandRecord;
  undefined4 uVar5;
  undefined4 afterInst;
  undefined4 block;
  undefined4 operandRef2;
  undefined4 uVar9;
  undefined4 operandRef;
  int member0xb0;
  undefined4 uVar12;
  int loopIndex;
  undefined4 uVar14;
  
  node = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(node + 4);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(operandRecord2 + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    operandRef2 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar12 = *(undefined4 *)(member0xb0 + 0x94);
  uVar14 = *(undefined4 *)(member0xb0 + 0x98);
  IRInst__reinitAsMov(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,operandRef);
  *(undefined4 *)(member0xb0 + 0x94) = uVar12;
  *(undefined4 *)(member0xb0 + 0x98) = uVar14;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,operandRef2);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar5;
  }
  *(undefined4 *)(member0xb0 + 0x9c) = uVar9;
  loopIndex = 0;
  uVar9 = FUN_0017a130(1,param_2,member0xb0,*(undefined4 *)(ctx + 0x238));
  *(undefined4 *)(ctx + 0x214) = uVar9;
  iVar3 = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
      *(undefined4 *)(iVar3 + 0x30) = 0;
    }
    bVar1 = loopIndex != 3;
    iVar3 = iVar3 + 4;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(block,afterInst,member0xb0);
  return member0xb0;
}

/* ValueKey__foldCompareSameSourcesToConstant @ 0x17d3f8 (232 bytes) */
int ValueKey__foldCompareSameSourcesToConstant(param_1)
  int param_1;
{
  undefined4 *loopPtr;
  int loopRemaining;
  undefined4 uVar3;
  int loopRemaining2;
  undefined4 local_28 [8];
  
  loopRemaining = Inst__allWrittenLanesSatisfy(param_1,1,2);
  if (loopRemaining != 0) {
    loopRemaining = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(loopRemaining + 0xb8) & 1) == (*(uint *)(loopRemaining + 0xd0) & 1)) &&
       ((*(uint *)(loopRemaining + 0xb8) >> 1 & 1) == (*(uint *)(loopRemaining + 0xd0) >> 1 & 1))) {
      loopRemaining = ((bool (*)())evaluateCompareFloats)(loopRemaining,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar3 = 0x3f800000;
      if (loopRemaining == 0) {
        uVar3 = 0;
      }
      loopRemaining = 4;
      loopPtr = local_28;
      do {
        *loopPtr = 0x7ffffffe;
        loopPtr = loopPtr + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining = 0;
      loopRemaining2 = 4;
      do {
        *(undefined4 *)(loopRemaining + (int)local_28) = uVar3;
        loopRemaining = loopRemaining + 4;
        loopRemaining2 = loopRemaining2 + -1;
      } while (loopRemaining2 != 0);
      ((int (*)())FUN_0017d26c)(param_1,local_28);
      ValueKey__rebuild(param_1);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__replaceWithZeroIfSourcesEqual @ 0x17d4e0 (156 bytes) */
int ValueKey__replaceWithZeroIfSourcesEqual(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  callResult = FUN_00176fd4(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(ctx,&local_28);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* ValueKey__foldMulByZero @ 0x17d57c (148 bytes) */
int ValueKey__foldMulByZero(param_1)
  int param_1;
{
  bool bVar1;
  int callResult;
  undefined4 uVar3;
  int loopIndex;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(param_1 + 0x238),0);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(param_1,uVar3,loopIndex);
    if (callResult != 0) {
      local_2c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_38);
      ValueKey__rebuild(param_1);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017d610 @ 0x17d610 (156 bytes) */
int FUN_0017d610(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  callResult = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(ctx,&local_28);
      ValueKey__rebuild(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d6ac @ 0x17d6ac (780 bytes) */
int FUN_0017d6ac(ctx, param_2)
  int ctx;
  float *param_2;
{
  bool bVar1;
  byte bVar2;
  float *loopPtr2;
  int iVar4;
  int loopIndex;
  int loopRemaining2;
  int *piVar7;
  undefined4 uVar8;
  undefined4 in_r7;
  undefined4 in_r8;
  float *loopPtr3;
  float fVar10;
  int loopRemaining;
  undefined4 local_58;
  uint local_54;
  float afStack_44 [3];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  WriteMask__fromSelectWord(&local_38,*(undefined4 *)(loopIndex + 0x10));
  SelectWord__maskUnused(local_34,0x10203,local_38);
  loopIndex = *(int *)(ctx + 0x238);
  local_58 = local_34[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),param_2,&local_58,in_r7
                     ,in_r8,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 4;
    loopPtr2 = (float *)&local_54;
    do {
      *loopPtr2 = GH_U2F(0x7fff0000U);
      loopPtr2 = loopPtr2 + 1;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopIndex = 0;
    loopPtr2 = (float *)&local_54;
    loopPtr3 = param_2;
    do {
      loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
        *loopPtr2 = -*loopPtr3;
      }
      bVar1 = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    piVar7 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    loopIndex = (**(code **)(*piVar7 + 0x154))
                      (piVar7,*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),&local_54,&local_58
                      );
    if (loopIndex == 0) {
      fVar10 = GH_U2F(0x7fff0000U);
      loopIndex = 0;
      loopPtr2 = param_2;
      do {
        loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
          Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238), *(unsigned int *)loopPtr2);
          if ((GH_F2U(fVar10) == 0x7fff0000U)) {
            fVar10 = *loopPtr2;
          }
          else if (fVar10 != *loopPtr2) {
            return 0;
          }
        }
        bVar1 = loopIndex != 3;
        loopPtr2 = loopPtr2 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      loopIndex = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238), GH_F2U(fVar10));
      if (*(byte *)(loopIndex + 8) == 0) {
        return 0;
      }
      bVar2 = *(byte *)(loopIndex + 9);
      if (((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && ((bVar2 & 4) == 0)) && ((bVar2 & 8) == 0))
      {
        if ((*(byte *)(loopIndex + 8) & 1) == 0) {
          loopIndex = ((int (*)())FUN_0017ce7c)(ctx,loopIndex);
          return loopIndex;
        }
        loopIndex = 0;
        loopRemaining2 = 4;
        do {
          *(float *)((int)param_2 + loopIndex) = fVar10;
          loopIndex = loopIndex + 4;
          loopRemaining2 = loopRemaining2 + -1;
        } while (loopRemaining2 != 0);
        loopIndex = ((int (*)())FUN_0017d26c)(ctx,param_2);
        return loopIndex;
      }
      loopRemaining2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(loopIndex + 0x14));
      loopPtr2 = (float *)&local_54;
      if ((*(byte *)(loopRemaining2 + 8) & 1) == 0) {
        loopRemaining2 = ((int (*)())FUN_0017ce7c)(ctx,loopRemaining2);
      }
      else {
        do {
          *loopPtr2 = GH_U2F(0x7fff0000U);
          loopPtr2 = loopPtr2 + 1;
        } while (loopPtr2 != afStack_44);
        iVar4 = 0;
        loopRemaining = 4;
        do {
          *(undefined4 *)(iVar4 + (int)&local_54) = *(undefined4 *)(loopRemaining2 + 0x14);
          iVar4 = iVar4 + 4;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
        loopRemaining2 = ((int (*)())FUN_0017d26c)(ctx,&local_54);
      }
      bVar2 = *(byte *)(loopIndex + 9);
      if ((bVar2 & 1) != 0) {
        IROperand__setModifierBits(loopRemaining2 + 0xa4,1,1);
        bVar2 = *(byte *)(loopIndex + 9);
      }
      if ((bVar2 & 2) != 0) {
        *(undefined4 *)(loopRemaining2 + 0x124) = *(undefined4 *)(loopIndex + 0x1c);
        return loopRemaining2;
      }
      return loopRemaining2;
    }
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  loopIndex = ((int (*)())FUN_0017d06c)(ctx,loopIndex,&local_58,uVar8);
  return loopIndex;
}

/* FUN_0017d9b8 @ 0x17d9b8 (548 bytes) */
int FUN_0017d9b8(ctx)
  int ctx;
{
  int findInPtrSetResult;
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *loopPtr4;
  int loopIndex2;
  undefined4 *exprRecord;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *loopPtr3;
  int *piVar13;
  int loopIndex;
  int loopRemaining;
  int local_64 [9];
  
  loopIndex = 4;
  piVar10 = local_64 + 2;
  loopPtr4 = piVar10;
  do {
    *loopPtr4 = 0x7ffffffe;
    loopPtr4 = loopPtr4 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)piVar10) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  bVar2 = false;
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  loopPtr4 = piVar10;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      piVar13 = (int *)(loopRemaining + 8);
      loopIndex2 = 1;
      loopPtr3 = local_64;
      iVar11 = 0x98;
      do {
        *loopPtr3 = 0;
        iVar9 = *piVar13;
        if (iVar9 < 0) {
          exprRecord = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar9);
          iVar9 = signToCompareCode(*exprRecord);
          *loopPtr3 = iVar9;
        }
        else {
          if (iVar9 < 1) goto LAB_0017dbc4;
          findInPtrSetResult = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar9);
          iVar7 = *(int *)(findInPtrSetResult + 0xc);
          *loopPtr3 = iVar7;
          iVar9 = *(int *)(ctx + 0xb0) + iVar11;
          uVar3 = *(uint *)(iVar9 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopPtr3 = (DAT_001e61d0)[iVar7];
            uVar3 = *(uint *)(iVar9 + 0x20);
          }
          if ((uVar3 & 1) == 0) {
            iVar9 = *loopPtr3;
            bVar2 = true;
          }
          else {
            bVar2 = true;
            iVar9 = *(int *)(&DAT_001e61b8 + *loopPtr3 * 4);
            *loopPtr3 = iVar9;
          }
        }
        iVar7 = local_64[0];
        if (iVar9 == 0) goto LAB_0017dbc4;
        bVar1 = loopIndex2 != 2;
        iVar11 = iVar11 + 0x18;
        loopPtr3 = loopPtr3 + 1;
        piVar13 = piVar13 + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
      loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + iVar7 * 0x30 + local_64[1]) * 4);
      if (loopIndex2 == 1) {
        *loopPtr4 = 0x3f800000;
      }
      else if (loopIndex2 == 2) {
        *loopPtr4 = 0;
      }
      else if (loopIndex2 == 0) goto LAB_0017dbc4;
    }
    bVar1 = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopPtr4 = loopPtr4 + 1;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = ((int (*)())FUN_0017d6ac)(ctx,piVar10);
  if (loopIndex == 0) {
LAB_0017dbc4:
    uVar8 = 0;
  }
  else {
    if (bVar2) {
      loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(loopIndex + 0x134) = *(int *)(loopIndex + 0x134) + 1;
    }
    ValueKey__rebuild(ctx);
    uVar8 = 1;
  }
  return uVar8;
}

/* FUN_0017dbdc @ 0x17dbdc (1104 bytes) */
int FUN_0017dbdc(ctx, param_2)
  int ctx;
  int *param_2;
{
  undefined4 exprRecord;
  bool bVar1;
  int iVar2;
  int loopRemaining;
  int loopIndex;
  int *loopPtr3;
  undefined4 opcode;
  int loopIndex2;
  int local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c [6];
  
  opcode = *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8);
  iVar2 = FUN_00176564(opcode);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_00176574(opcode);
  if (iVar2 == 0) {
    loopIndex = OpcodeTraits__flagBit7(opcode,*(undefined4 *)(ctx + 0x238));
    if ((loopIndex == 0) ||
       (loopIndex = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
      loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238));
      if (loopIndex == 0) {
        iVar2 = 0;
        loopIndex2 = 0;
        loopIndex = ctx;
        loopPtr3 = param_2;
        do {
          local_58[0] = 0;
          loopRemaining = FUN_001767d8(ctx,loopIndex2);
          if (loopRemaining != 0) {
            FUN_00176c40(local_3c,ctx,loopIndex2,local_58);
            *loopPtr3 = local_3c[0];
            if (local_3c[0] != 0x7ffffffe) {
              exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_3c[0]);
              *(undefined4 *)(loopIndex + 0x30) = exprRecord;
            }
          }
          loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (local_58[0] != 0)) {
            iVar2 = 1;
          }
          bVar1 = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
        loopIndex = 0;
        loopPtr3 = param_2;
        do {
          loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopPtr3 == 0x7ffffffe))
          goto LAB_0017dfa0;
          bVar1 = loopIndex != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex = loopIndex + 1;
        } while (bVar1);
      }
      else {
        loopIndex = FUN_0017672c(ctx);
        if (loopIndex == 0) goto LAB_0017df9c;
        local_58[0] = iVar2;
        FUN_001781a4(&local_40,ctx,local_58);
        iVar2 = local_58[0];
        if (local_40 == 0x7ffffffe) goto LAB_0017dfa0;
        exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_40);
        loopRemaining = 4;
        loopIndex2 = 0;
        loopIndex = ctx;
        do {
          *(int *)((int)param_2 + loopIndex2) = local_40;
          loopIndex2 = loopIndex2 + 4;
          *(undefined4 *)(loopIndex + 0x30) = exprRecord;
          loopIndex = loopIndex + 4;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
      }
    }
    else {
      loopIndex = FUN_00178b1c(ctx);
      if (loopIndex == 0) {
LAB_0017df9c:
        iVar2 = 0;
LAB_0017dfa0:
        bVar1 = true;
        goto LAB_0017dd38;
      }
      local_58[0] = iVar2;
      FUN_00176a94(&local_44,ctx,local_58);
      iVar2 = local_58[0];
      if (local_44 == 0x7ffffffe) goto LAB_0017dfa0;
      exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_44);
      loopRemaining = 4;
      loopIndex2 = 0;
      loopIndex = ctx;
      do {
        *(int *)((int)param_2 + loopIndex2) = local_44;
        loopIndex2 = loopIndex2 + 4;
        *(undefined4 *)(loopIndex + 0x30) = exprRecord;
        loopIndex = loopIndex + 4;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
    }
  }
  else {
    iVar2 = 0;
    loopIndex2 = 0;
    loopIndex = ctx;
    loopPtr3 = param_2;
    do {
      local_58[0] = 0;
      loopRemaining = FUN_00178a98(ctx,loopIndex2);
      if (loopRemaining != 0) {
        FUN_00178e90(&local_48,ctx,loopIndex2,(uint)local_58);
        *loopPtr3 = local_48;
        if (local_48 != 0x7ffffffe) {
          exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_48);
          *(undefined4 *)(loopIndex + 0x30) = exprRecord;
        }
      }
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (local_58[0] != 0)) {
        iVar2 = 1;
      }
      bVar1 = loopIndex2 != 3;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
    loopIndex = 0;
    loopPtr3 = param_2;
    do {
      loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopPtr3 == 0x7ffffffe)) goto LAB_0017dfa0;
      bVar1 = loopIndex != 3;
      loopPtr3 = loopPtr3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  bVar1 = false;
LAB_0017dd38:
  loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0));
  if ((loopIndex == 0) && (!bVar1)) {
    loopIndex = ((int (*)())FUN_0017d6ac)(ctx,param_2);
    if (loopIndex != 0) {
      ValueKey__rebuild(ctx);
      return 1;
    }
    loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopIndex + 0x138) = *(int *)(loopIndex + 0x138) + 1;
    if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) && (iVar2 == 0)) {
      *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
      ValueKey__rebuild(ctx);
      return 0;
    }
  }
  return 0;
}

/* FUN_0017e02c @ 0x17e02c (268 bytes) */
int FUN_0017e02c(ctx, operandIndex, param_3)
  int ctx;
  int operandIndex;
  undefined4 param_3;
{
  int inst;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  undefined4 ref;
  uint uVar3;
  int node;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 saturate;
  undefined4 operandRef;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 operandRef2;
  undefined4 uVar14;
  undefined4 operandRef3;
  undefined4 uVar16;
  undefined4 uVar17;
  
  node = *(int *)(ctx + 0xb0);
  ref = *(undefined4 *)(node + 4);
  uVar7 = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  operandRef3 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  inst = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(operandRecord2 + 0x10);
  operandRef2 = *(undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  saturate = *(undefined4 *)(inst + 0x120);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar14 = *(undefined4 *)(operandRecord + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(operandIndex * 0x18 + iVar5 + 0xa0);
  uVar11 = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar8 = 0;
    operandRef = 0;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + ctx + 0x210);
    operandRef = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar5 + 0x94);
  uVar17 = *(undefined4 *)(iVar5 + 0x98);
  IRInst__reinitAsMov(iVar5,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar5,0,operandRef3);
  *(undefined4 *)(iVar5 + 0x94) = uVar16;
  *(undefined4 *)(iVar5 + 0x98) = uVar17;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(iVar5,operandRef);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar8;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar12;
  IRInst__setOperandRef(iVar5,1,operandRef2);
  operandRecord = IRInst__getOperandRecord(iVar5,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar14;
  IROperand__setModifierBits(iVar5 + 0xa4,1,uVar3 & 1);
  IROperand__setModifierBits(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar5 + 0x120) = saturate;
  *(undefined4 *)(iVar5 + 0x124) = param_3;
  *(undefined4 *)(ctx + 0x214) = uVar11;
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  DList__insertAfter(iVar5,ref);
  *(undefined4 *)(iVar5 + 0x158) = uVar7;
  return;
}

/* ValueKey__foldMulPowerOfTwoIntoOutputScale @ 0x17e1f4 (324 bytes) */
int ValueKey__foldMulPowerOfTwoIntoOutputScale(ctx)
  int ctx;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *a0;
  int loopIndex;
  double fparam_1;
  float local_38 [7];
  
  loopIndex = 1;
  do {
    FUN_001770e4(local_38,ctx,loopIndex);
    if ((GH_F2U(local_38[0]) != 0x7fff0000U)) {
      bVar1 = -1 < (int)GH_F2U(local_38[0]);
      if (bVar1) {
        fparam_1 = (double)local_38[0];
      }
      else {
        fparam_1 = -(double)local_38[0];
      }
      iVar2 = ((undefined4 (*)())isOutputScaleValue)(fparam_1);
      if (iVar2 != 0) {
        iVar2 = ((int (*)())outputScaleExponent)(fparam_1);
        a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        iVar2 = iVar2 + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
        iVar3 = (**(code **)(*a0 + 0xfc))(a0,iVar2,*(int *)(ctx + 0xb0),in_r6,in_r7,in_r8,a0);
        if (iVar3 != 0) {
          loopIndex = (loopIndex == 1) + 1;
          if (!bVar1) {
            iVar3 = *(int *)(ctx + 0xb0) + loopIndex * 0x18 + 0x80;
            IROperand__setModifierBits(iVar3 + 0xc,1,(*(uint *)(iVar3 + 0x20) ^ 1) & 1);
          }
          ((int (*)())FUN_0017e02c)(ctx,loopIndex,iVar2);
          ValueKey__rebuild(ctx);
          return 1;
        }
      }
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e338 @ 0x17e338 (188 bytes) */
int FUN_0017e338(ctx)
  int ctx;
{
  int lanesAllSatisfy;
  int iVar1;
  int *a0;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a1;
  
  lanesAllSatisfy = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (lanesAllSatisfy != 0) {
    iVar1 = *(int *)(ctx + 0xb0);
    if (((*(uint *)(iVar1 + 0xb8) & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((*(uint *)(iVar1 + 0xb8) >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
      a1 = *(int *)(iVar1 + 0x124) + 1;
      iVar1 = (**(code **)(*a0 + 0xfc))(a0,a1,iVar1,in_r6,in_r7,in_r8,*(int *)(iVar1 + 0x124));
      if (iVar1 != 0) {
        ((int (*)())FUN_0017e02c)(ctx,2,a1);
        ValueKey__rebuild(ctx);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0017e3f4 @ 0x17e3f4 (348 bytes) */
int FUN_0017e3f4(ctx, param_2, operandIndex, operandIndex2)
  int ctx;
  undefined4 param_2;
  int operandIndex;
  int operandIndex2;
{
  int inst3;
  int inst2;
  int inst;
  int currentDefinition;
  int operandRecord;
  int operandRecord2;
  bool bVar1;
  undefined4 ref;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 operandRef4;
  uint uVar7;
  int node;
  undefined4 uVar9;
  undefined4 operandRef;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 saturate;
  undefined4 resultScaleCode;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 operandRef2;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 operandRef3;
  
  inst = *(int *)(ctx + 0xb0);
  ref = *(undefined4 *)(inst + 4);
  uVar3 = *(undefined4 *)(inst + 0x158);
  destRegister = *(undefined4 *)(inst + 0x94);
  destRegisterOffset = *(undefined4 *)(inst + 0x98);
  operandRef2 = *(undefined4 *)(inst + 0x8c);
  operandRecord = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(operandRecord + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst2 + 0x8c);
  saturate = *(undefined4 *)(inst2 + 0x120);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  operandRecord = IRInst__getOperandRecord(inst2,operandIndex);
  inst3 = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(operandRecord + 0x10);
  uVar4 = *(uint *)(operandIndex * 0x18 + inst3 + 0xa0);
  operandRef4 = *(undefined4 *)(operandIndex2 * 0x18 + inst3 + 0x8c);
  operandRecord2 = IRInst__getOperandRecord(inst3,operandIndex2);
  node = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(operandRecord2 + 0x10);
  bVar1 = (*(uint *)(node + 0x14) & 0x200) == 0;
  uVar7 = *(uint *)(operandIndex2 * 0x18 + node + 0xa0);
  uVar18 = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  uVar20 = *(undefined4 *)(operandIndex2 * 4 + ctx + 0x210);
  if (bVar1) {
    uVar19 = 0;
    operandRef3 = 0;
  }
  else {
    uVar19 = *(undefined4 *)(*(int *)(node + 0x84) * 4 + ctx + 0x210);
    operandRef3 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  DList__unlink(node);
  iVar5 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(iVar5,param_2,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar5,0,operandRef2);
  *(undefined4 *)(iVar5 + 0x94) = destRegister;
  *(undefined4 *)(iVar5 + 0x98) = destRegisterOffset;
  if (bVar1) {
    currentDefinition = VReg__currentDefinition(operandRef2,*(undefined4 *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x3a0)
                        ,*(undefined4 *)(ctx + 0x238));
    *(undefined4 *)(ctx + 0x21c) = *(undefined4 *)(currentDefinition + 0xb0);
  }
  else {
    IRInst__appendSource(iVar5,operandRef3);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x21c) = uVar19;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar9;
  *(undefined4 *)(iVar5 + 0x120) = saturate;
  *(undefined4 *)(iVar5 + 0x124) = resultScaleCode;
  IRInst__setOperandRef(iVar5,1,operandRef);
  operandRecord = IRInst__getOperandRecord(iVar5,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar11;
  IROperand__setModifierBits(iVar5 + 0xa4,1,uVar4 & 1);
  IROperand__setModifierBits(iVar5 + 0xa4,2,uVar4 >> 1 & 1);
  IRInst__setOperandRef(iVar5,2,operandRef4);
  operandRecord = IRInst__getOperandRecord(iVar5,2);
  *(undefined4 *)(operandRecord + 0x10) = uVar12;
  IROperand__setModifierBits(iVar5 + 0xbc,1,uVar7 & 1);
  IROperand__setModifierBits(iVar5 + 0xbc,2,uVar7 >> 1 & 1);
  *(undefined4 *)(ctx + 0x218) = uVar20;
  *(undefined4 *)(ctx + 0x214) = uVar18;
  DList__insertAfter(iVar5,ref);
  *(undefined4 *)(iVar5 + 0x158) = uVar3;
  return;
}

/* ValueKey__foldMadZeroAddend @ 0x17e658 (112 bytes) */
int ValueKey__foldMadZeroAddend(param_1)
  int param_1;
{
  int callResult;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(param_1 + 0x238),0);
  callResult = Inst__writtenLanesAllMatchValue(param_1,*(undefined4 *)(callResult + 4),3);
  if (callResult != 0) {
    ((int (*)())FUN_0017e3f4)(param_1,0x13,1,2);
    ValueKey__rebuild(param_1);
  }
  return callResult != 0;
}

/* ValueKey__foldMadByPlusMinusOne @ 0x17e6c8 (280 bytes) */
int ValueKey__foldMadByPlusMinusOne(ctx)
  int ctx;
{
  bool bVar1;
  int callResult;
  undefined4 uVar3;
  int loopIndex;
  
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0x3f800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())FUN_0017e3f4)(ctx,0x12,(loopIndex == 1) + 1,3);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  callResult = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0xbf800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = Inst__writtenLanesAllMatchValue(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())FUN_0017e3f4)(ctx,0x12,(loopIndex == 1) + 1,3);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(ctx + 0xb0) + 0xb8) ^ 1) & 1);
      ValueKey__rebuild(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e7e0 @ 0x17e7e0 (604 bytes) */
int FUN_0017e7e0(ctx)
  int ctx;
{
  undefined4 operandRef5;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  uint uVar5;
  int loopRemaining;
  int *newInst;
  undefined4 operandRef6;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 operandRef2;
  undefined4 uVar13;
  undefined4 operandRef3;
  undefined4 operandRef4;
  int member0xb0;
  undefined4 afterInst;
  int *piVar18;
  undefined4 block;
  int local_78;
  undefined4 local_74 [3];
  undefined4 local_68;
  undefined4 operandRef;
  uint absFlag;
  int local_5c;
  int local_58;
  
  loopIndex = *(int *)(ctx + 0xb0);
  block = *(undefined4 *)(loopIndex + 0x158);
  afterInst = *(undefined4 *)(loopIndex + 4);
  uVar9 = *(undefined4 *)(loopIndex + 0x94);
  uVar10 = *(undefined4 *)(loopIndex + 0x98);
  operandRef4 = *(undefined4 *)(loopIndex + 0x8c);
  loopIndex = IRInst__getOperandRecord(loopIndex,0);
  local_78 = *(int *)(loopIndex + 0x10);
  loopIndex = *(int *)(ctx + 0xb0);
  local_58 = *(int *)(loopIndex + 0x120);
  local_5c = *(int *)(loopIndex + 0x124);
  operandRef3 = *(undefined4 *)(loopIndex + 0xa4);
  loopRemaining = IRInst__getOperandRecord(loopIndex,1);
  loopIndex = *(int *)(ctx + 0xb0);
  uVar13 = *(undefined4 *)(loopRemaining + 0x10);
  uVar2 = *(uint *)(loopIndex + 0xb8);
  operandRef2 = *(undefined4 *)(loopIndex + 0xbc);
  loopRemaining = IRInst__getOperandRecord(loopIndex,2);
  loopIndex = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(loopRemaining + 0x10);
  uVar3 = *(uint *)(loopIndex + 0xd0);
  operandRef6 = *(undefined4 *)(loopIndex + 0xd4);
  loopIndex = IRInst__getOperandRecord(loopIndex,3);
  loopRemaining = *(int *)(ctx + 0xb0);
  local_68 = *(undefined4 *)(loopIndex + 0x10);
  uVar5 = *(uint *)(loopRemaining + 0xe8);
  bVar1 = (*(uint *)(loopRemaining + 0x14) >> 9 & 1) != 0;
  absFlag = uVar5 >> 1 & 1;
  if (bVar1) {
    operandRef = *(undefined4 *)(*(int *)(loopRemaining + 0x84) * 0x18 + loopRemaining + 0x8c);
  }
  else {
    operandRef = 0;
  }
  DList__unlink(loopRemaining);
  member0xb0 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(member0xb0,0x13,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,member0xb0);
  newInst = (int *)IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,*(undefined4 *)(ctx + 0xb0),newInst);
  loopIndex = *(int *)(ctx + 0x238);
  operandRef5 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  loopRemaining = *(int *)(loopIndex + 0x3ac) + -1;
  *(int *)(loopIndex + 0x3ac) = loopRemaining;
  operandRef5 = FUN_00127608(operandRef5,0,loopRemaining,0);
  IRInst__setOperandRef(member0xb0,0,operandRef5);
  IRInst__setOperandRef(member0xb0,1,operandRef3);
  loopIndex = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(loopIndex + 0x10) = uVar13;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,uVar2 & 1);
  IROperand__setModifierBits(member0xb0 + 0xa4,2,uVar2 >> 1 & 1);
  IRInst__setOperandRef(member0xb0,2,operandRef2);
  loopIndex = IRInst__getOperandRecord(member0xb0,2);
  *(undefined4 *)(loopIndex + 0x10) = uVar11;
  IROperand__setModifierBits(member0xb0 + 0xbc,1,uVar3 & 1);
  IROperand__setModifierBits(member0xb0 + 0xbc,2,uVar3 >> 1 & 1);
  *(undefined4 *)(member0xb0 + 0x94) = uVar9;
  *(undefined4 *)(member0xb0 + 0x98) = uVar10;
  *(int *)(member0xb0 + 0x9c) = local_78;
  FUN_0012306c(operandRef5,member0xb0);
  loopIndex = 0;
  local_74[0] = DAT_001b01dc;
  loopRemaining = 4;
  do {
    if (*(char *)((int)local_74 + loopIndex + -4) == '\0') {
      *(char *)((int)local_74 + loopIndex) = (char)loopIndex;
    }
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  IRInst__setOperandRef(newInst,0,operandRef4);
  newInst[0x27] = local_78;
  IRInst__setOperandRef(newInst,1,operandRef5);
  uVar9 = local_74[0];
  loopIndex = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(loopIndex + 0x10) = uVar9;
  IRInst__setOperandRef(newInst,2,operandRef6);
  loopIndex = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(loopIndex + 0x10) = local_68;
  IROperand__setModifierBits(newInst + 0x2f,1,uVar5 & 1);
  IROperand__setModifierBits(newInst + 0x2f,2,absFlag);
  newInst[0x48] = local_58;
  newInst[0x49] = local_5c;
  FUN_0012306c(operandRef4,newInst);
  loopIndex = 1;
  piVar18 = newInst;
  while( true ) {
    loopRemaining = (**(code **)(*newInst + 0x14))(newInst);
    if (loopRemaining < loopIndex) break;
    VReg__addUse(piVar18[0x29],loopIndex,newInst);
    loopIndex = loopIndex + 1;
    piVar18 = piVar18 + 6;
  }
  if (bVar1) {
    IRInst__appendSource(member0xb0,operandRef);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    VReg__addUse(operandRef,*(undefined4 *)(member0xb0 + 0x84),member0xb0);
    IRInst__appendSource(newInst,operandRef4);
    newInst[5] = newInst[5] | 0x200;
    VReg__addUse(operandRef4,newInst[0x21],newInst);
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  ValueKey__fillSourceLaneUsage(ctx);
  return ValueKey__fill(ctx);
}

/* FUN_0017ebb0 @ 0x17ebb0 (508 bytes) */
int FUN_0017ebb0(ctx, param_2, param_3, negateFlag)
  int ctx;
  int param_2;
  undefined4 param_3;
  undefined4 negateFlag;
{
  int operandRef;
  int node;
  int inst3;
  int inst2;
  int operandRecord;
  int operandRecord2;
  undefined4 arenaAt378;
  bool bVar1;
  undefined4 member0x21c;
  int inst;
  uint uVar4;
  int iVar5;
  undefined4 *loopPtr2;
  undefined4 uVar7;
  undefined4 operandRef3;
  undefined4 operandRef4;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 destRegister;
  undefined4 destRegisterOffset;
  undefined4 afterInst;
  undefined4 block;
  undefined4 saturate;
  undefined4 resultScaleCode;
  int loopIndex;
  undefined4 operandRef2;
  
  inst = *(int *)(ctx + 0xb0);
  afterInst = *(undefined4 *)(inst + 4);
  block = *(undefined4 *)(inst + 0x158);
  destRegister = *(undefined4 *)(inst + 0x94);
  destRegisterOffset = *(undefined4 *)(inst + 0x98);
  operandRef4 = *(undefined4 *)(inst + 0x8c);
  operandRecord = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  member0x21c = *(undefined4 *)(ctx + 0x21c);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  uVar11 = *(undefined4 *)(operandRecord + 0x10);
  saturate = *(undefined4 *)(inst2 + 0x120);
  operandRef3 = *(undefined4 *)(inst2 + 0xd4);
  operandRecord2 = IRInst__getOperandRecord(inst2,3);
  node = *(int *)(ctx + 0xb0);
  uVar7 = *(undefined4 *)(operandRecord2 + 0x10);
  uVar4 = *(uint *)(node + 0xe8);
  bVar1 = (*(uint *)(node + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar10 = *(undefined4 *)(*(int *)(node + 0x84) * 4 + ctx + 0x210);
    operandRef2 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  else {
    uVar10 = 0;
    operandRef2 = 0;
  }
  DList__unlink(node);
  inst3 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(inst3,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,inst3);
  *(undefined4 *)(inst3 + 0x120) = saturate;
  *(undefined4 *)(inst3 + 0x124) = resultScaleCode;
  *(undefined4 *)(inst3 + 0x94) = destRegister;
  *(undefined4 *)(inst3 + 0x98) = destRegisterOffset;
  IRInst__setOperandRef(inst3,0,operandRef4);
  operandRef = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(inst3 + 0x9c) = uVar11;
  if (*(int *)(*(int *)(operandRef + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    loopPtr2 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *loopPtr2 = arenaAt378;
    loopPtr2 = loopPtr2 + 1;
    ValueKey__init(loopPtr2,param_2,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(loopPtr2);
    ValueKey__propagateLaneValues(loopPtr2);
    VReg__pushDefinition(operandRef,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),loopPtr2);
  }
  IRInst__setOperandRef(inst3,1,operandRef);
  operandRecord = IRInst__getOperandRecord(inst3,1);
  *(undefined4 *)(operandRecord + 0x10) = param_3;
  IROperand__setModifierBits(inst3 + 0xa4,1,negateFlag);
  IRInst__setOperandRef(inst3,2,operandRef3);
  operandRecord = IRInst__getOperandRecord(inst3,2);
  *(undefined4 *)(operandRecord + 0x10) = uVar7;
  IROperand__setModifierBits(inst3 + 0xbc,1,uVar4 & 1);
  IROperand__setModifierBits(inst3 + 0xbc,2,uVar4 >> 1 & 1);
  if (bVar1) {
    IRInst__appendSource(inst3,operandRef2);
    *(uint *)(inst3 + 0x14) = *(uint *)(inst3 + 0x14) | 0x200;
  }
  *(int *)(ctx + 0x214) = param_2;
  *(undefined4 *)(ctx + 0x218) = member0x21c;
  if (!bVar1) {
    uVar10 = 0;
  }
  *(undefined4 *)(ctx + 0x21c) = uVar10;
  FUN_0012306c(operandRef4,inst3);
  if (0 < *(int *)(inst3 + 0x84)) {
    loopIndex = 1;
    iVar5 = inst3;
    do {
      loopPtr2 = (undefined4 *)(iVar5 + 0xa4);
      iVar5 = iVar5 + 0x18;
      VReg__addUse(*loopPtr2,loopIndex,inst3);
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(inst3 + 0x84));
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  ValueKey__fillSourceLaneUsage(ctx);
  ValueKey__fill(ctx);
  return;
}

/* FUN_0017ee68 @ 0x17ee68 (468 bytes) */
int FUN_0017ee68(ctx)
  int ctx;
{
  undefined4 resultScaleCode;
  undefined4 saturate;
  undefined4 operandRef2;
  int node;
  int inst2;
  int inst;
  int operandIndex;
  int operandRecord;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 operandRef3;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 operandRef4;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 operandRef;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int loopIndex;
  int iVar18;
  undefined4 block;
  undefined4 afterInst;
  float local_58 [5];
  
  loopIndex = 1;
  while ((FUN_00178d78(local_58,ctx,loopIndex), local_58[0] != FLOAT_001aa0e8 &&
         (local_58[0] != FLOAT_001aa114))) {
    bVar1 = loopIndex == 2;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 0;
    }
  }
  inst = *(int *)(ctx + 0xb0);
  operandIndex = (loopIndex == 1) + 1;
  operandRef4 = *(undefined4 *)(inst + 0x8c);
  iVar11 = *(int *)(*(int *)(inst + 0x88) + 8);
  loopIndex = IRInst__getOperandRecord(inst,0);
  inst2 = *(int *)(ctx + 0xb0);
  uVar10 = *(undefined4 *)(loopIndex + 0x10);
  operandRef = *(undefined4 *)(operandIndex * 0x18 + inst2 + 0x8c);
  saturate = *(undefined4 *)(inst2 + 0x120);
  resultScaleCode = *(undefined4 *)(inst2 + 0x124);
  loopIndex = IRInst__getOperandRecord(inst2,operandIndex);
  node = *(int *)(ctx + 0xb0);
  uVar14 = *(uint *)(loopIndex + 0x10);
  uVar12 = *(undefined4 *)(operandIndex * 4 + ctx + 0x210);
  bVar1 = (*(uint *)(node + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    operandRef3 = *(undefined4 *)(*(int *)(node + 0x84) * 0x18 + node + 0x8c);
  }
  else {
    operandRef3 = 0;
  }
  afterInst = *(undefined4 *)(node + 4);
  uVar15 = *(undefined4 *)(node + 0x94);
  uVar16 = *(undefined4 *)(node + 0x98);
  block = *(undefined4 *)(node + 0x158);
  DList__unlink(node);
  iVar18 = *(int *)(ctx + 0xb0);
  IRInst__reinitAsBinary(iVar18,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,afterInst,iVar18);
  loopIndex = *(int *)(ctx + 0x238);
  iVar5 = *(int *)(loopIndex + 0x3ac) + -1;
  operandRef2 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  *(int *)(loopIndex + 0x3ac) = iVar5;
  operandRef2 = FUN_00127608(operandRef2,0,iVar5,0);
  FUN_0012306c(operandRef2,*(undefined4 *)(ctx + 0xb0));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,operandRef2);
  *(undefined4 *)(iVar18 + 0x94) = uVar15;
  *(undefined4 *)(iVar18 + 0x98) = uVar16;
  IRInst__setOperandRef(iVar18,1,operandRef);
  IRInst__setOperandRef(iVar18,2,operandRef);
  loopIndex = IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(block,iVar18,loopIndex);
  IRInst__setOperandRef(loopIndex,0,operandRef4);
  *(undefined4 *)(loopIndex + 0x94) = uVar15;
  *(undefined4 *)(loopIndex + 0x98) = uVar16;
  *(undefined4 *)(loopIndex + 0x9c) = uVar10;
  if (bVar1) {
    IRInst__appendSource(loopIndex,operandRef3);
    *(uint *)(loopIndex + 0x14) = *(uint *)(loopIndex + 0x14) | 0x200;
  }
  *(undefined4 *)(loopIndex + 0x120) = saturate;
  *(undefined4 *)(loopIndex + 0x124) = resultScaleCode;
  *(undefined4 *)(ctx + 0x218) = uVar12;
  *(undefined4 *)(ctx + 0x214) = uVar12;
  puVar4 = PTR_DAT_001e8b8c;
  uVar2 = DAT_001b01d8;
  if (iVar11 == 0x1c) {
    uVar7 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar14 >> 0x16 & 0x3fc));
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffffff;
    operandRecord = IRInst__getOperandRecord(iVar18,1);
    uVar8 = *(undefined4 *)(puVar4 + (uVar14 >> 0xe & 0x3fc));
    *(undefined4 *)(operandRecord + 0x10) = uVar7;
    operandRecord = IRInst__getOperandRecord(iVar18,2);
    *(undefined4 *)(operandRecord + 0x10) = uVar8;
    IRInst__setOperandRef(loopIndex,1,operandRef2);
    IRInst__setOperandRef(loopIndex,2,operandRef);
    uVar7 = *(undefined4 *)puVar4;
    operandRecord = IRInst__getOperandRecord(loopIndex,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar7;
    uVar7 = *(undefined4 *)(puVar4 + (uVar14 >> 6 & 0x3fc));
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = uVar7;
  }
  else if (iVar11 == 0x1d) {
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffff;
    operandRecord = IRInst__getOperandRecord(iVar18,1);
    uVar3 = DAT_001b01d8;
    *(uint *)(operandRecord + 0x10) = uVar14 & 0xff0000 | uVar14 & 0xff000000 | uVar2 & 0xffff;
    operandRecord = IRInst__getOperandRecord(iVar18,2);
    *(uint *)(operandRecord + 0x10) = (uVar14 & 0xff) << 0x10 | (uVar14 & 0xff00) << 0x10 | uVar3 & 0xffff;
    IRInst__setOperandRef(loopIndex,1,operandRef2);
    IRInst__setOperandRef(loopIndex,2,operandRef2);
    puVar4 = PTR_DAT_001e8b8c;
    uVar7 = *(undefined4 *)PTR_DAT_001e8b8c;
    operandRecord = IRInst__getOperandRecord(loopIndex,1);
    uVar8 = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)(operandRecord + 0x10) = uVar7;
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = uVar8;
  }
  ValueKey__rebuild(ctx);
  return 1;
}

/* FUN_0017f1f8 @ 0x17f1f8 (512 bytes) */
int FUN_0017f1f8(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  float *loopPtr2;
  int iVar3;
  float *exprRecord;
  undefined4 uVar5;
  undefined4 in_r7;
  undefined4 in_r8;
  int *piVar6;
  int loopIndex;
  int loopRemaining;
  undefined4 local_68;
  uint local_64;
  float local_54 [7];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  loopIndex = 5;
  loopPtr2 = local_54;
  do {
    *loopPtr2 = GH_U2F(0x7fff0000U);
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopPtr2 = (float *)&local_64;
  do {
    *loopPtr2 = GH_U2F(0x7fff0000U);
    loopPtr2 = loopPtr2 + 1;
  } while (loopPtr2 != local_54);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)&local_64) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      piVar6 = (int *)(loopRemaining + 8);
      loopPtr2 = local_54 + 1;
      do {
        iVar3 = *piVar6;
        if (-1 < iVar3) {
          return 0;
        }
        piVar6 = piVar6 + 4;
        exprRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar3);
        *loopPtr2 = *exprRecord;
        loopPtr2 = loopPtr2 + 1;
      } while (loopPtr2 != local_54 + 3);
      (&local_64)[loopIndex] = (uint)GH_F2U((float)((local_54[1] * local_54[2])));
    }
    bVar1 = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  WriteMask__fromSelectWord(&local_38,*(undefined4 *)(loopIndex + 0x10));
  SelectWord__maskUnused(local_34,0x10203,local_38);
  loopIndex = *(int *)(ctx + 0x238);
  local_68 = local_34[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),&local_64,&local_68,
                     in_r7,in_r8,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 0;
    loopPtr2 = (float *)&local_64;
    do {
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining + 0x10) != '\x01') {
        *loopPtr2 = -*loopPtr2;
      }
      bVar1 = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    piVar6 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    loopIndex = (**(code **)(*piVar6 + 0x154))
                      (piVar6,*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),&local_64,&local_68
                      );
    if (loopIndex == 0) {
      return 0;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  ((int (*)())FUN_0017ebb0)(ctx,loopIndex,local_68,uVar5);
  return 1;
}

/* ValueKey__foldMinMaxOfNegatedPair @ 0x17f3f8 (412 bytes) */
int ValueKey__foldMinMaxOfNegatedPair(ctx, param_2)
  int ctx;
  uint param_2;
{
  int lanesAllSatisfy;
  int inst;
  int operandRecord;
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *exprRecord;
  int *a0;
  uint uVar5;
  int loopIndex;
  undefined4 local_38 [6];
  
  lanesAllSatisfy = Inst__allWrittenLanesSatisfy(ctx,1,2);
  if (lanesAllSatisfy != 0) {
    inst = *(int *)(ctx + 0xb0);
    if (((*(uint *)(inst + 0xb8) & 1) != (*(uint *)(inst + 0xd0) & 1)) &&
       ((*(uint *)(inst + 0xb8) >> 1 & 1) == (*(uint *)(inst + 0xd0) >> 1 & 1))) {
      bVar2 = true;
      operandRecord = IRInst__getOperandRecord(inst,0);
      uVar5 = 0;
      loopIndex = 0;
      local_38[0] = *(undefined4 *)(operandRecord + 0x10);
      iVar3 = ctx;
      do {
        if (*(char *)((int)local_38 + loopIndex) == '\0') {
          if (-1 < *(int *)(iVar3 + 0x178)) {
LAB_0017f514:
            a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
            iVar3 = (**(code **)(*a0 + 0x88))(a0);
            if (iVar3 == 0) {
              return 0;
            }
            ((int (*)())FUN_0017c244)(ctx,1);
            IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,1);
            IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,param_2 ^ 1);
            ValueKey__rebuild(ctx);
            return 1;
          }
          exprRecord = (uint *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(iVar3 + 0x178));
          if (bVar2) {
            uVar5 = *exprRecord >> 0x1f;
            bVar2 = false;
          }
          else if (*exprRecord >> 0x1f != uVar5) goto LAB_0017f514;
        }
        bVar1 = loopIndex == 3;
        iVar3 = iVar3 + 4;
        loopIndex = loopIndex + 1;
        if (bVar1) {
          ((int (*)())FUN_0017c244)(ctx,1);
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,(uint)(param_2 == uVar5));
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,0);
          ValueKey__rebuild(ctx);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* ValueKey__foldMaxOfNegatedPair @ 0x17f594 (8 bytes) */
int ValueKey__foldMaxOfNegatedPair(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())ValueKey__foldMinMaxOfNegatedPair)(param_1,1);
  return callResult;
}

/* ValueKey__foldMinOfNegatedPair @ 0x17f59c (8 bytes) */
int ValueKey__foldMinOfNegatedPair(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())ValueKey__foldMinMaxOfNegatedPair)(param_1,0);
  return callResult;
}

/* FUN_0017f5a4 @ 0x17f5a4 (488 bytes) */
int FUN_0017f5a4(ctx)
  int ctx;
{
  int loopIndex;
  int *inst;
  undefined4 operandRef;
  int iVar4;
  int *piVar5;
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  loopIndex = FUN_000f2e18(*(undefined4 *)(loopIndex + 0x10));
  if (loopIndex == 0) {
    inst = (int *)IRInst__clone(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(ctx + 0x238),0)
    ;
    loopIndex = *(int *)(ctx + 0x238);
    operandRef = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
    iVar4 = *(int *)(loopIndex + 0x3ac) + -1;
    *(int *)(loopIndex + 0x3ac) = iVar4;
    operandRef = FUN_00127608(operandRef,0,iVar4,0);
    FUN_0012306c(operandRef,*(undefined4 *)(ctx + 0xb0));
    IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,operandRef);
    loopIndex = inst[0x23];
    *(undefined1 *)(*(int *)(ctx + 0xb0) + 0x9f) = 1;
    inst[0x27] = 0x1010100;
    FUN_0012306c(loopIndex,inst);
    loopIndex = 1;
    piVar5 = inst;
    while( true ) {
      iVar4 = (**(code **)(*inst + 0x14))(inst);
      if (iVar4 < loopIndex) break;
      VReg__addUse(piVar5[0x29],loopIndex,inst);
      loopIndex = loopIndex + 1;
      piVar5 = piVar5 + 6;
    }
    if ((*(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0x200) == 0) {
      IRInst__appendSource(*(int *)(ctx + 0xb0),operandRef);
      VReg__addUse(operandRef,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x84),*(int *)(ctx + 0xb0));
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x200;
      loopIndex = VReg__currentDefinition(operandRef,*(undefined4 *)
                                  (*(int *)(*(uint *)(ctx + 0x238) + 0x6c4) + 0x3a0),
                           *(uint *)(ctx + 0x238));
      *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x84) * 4 + ctx + 0x210) =
           *(undefined4 *)(loopIndex + 0xb0);
      IRInst__appendSource(inst,operandRef);
      VReg__addUse(operandRef,inst[0x21],inst);
      inst[5] = inst[5] | 0x200;
    }
    else {
      IRInst__setOperandRef(inst,inst[0x21],operandRef);
      VReg__addUse(operandRef,inst[0x21],inst);
    }
    ValueKey__rebuild(ctx);
    Block__insertInstAfter(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),*(int *)(ctx + 0xb0),inst);
    return;
  }
  return;
}

/* FUN_0017f78c @ 0x17f78c (96 bytes) */
int FUN_0017f78c(ctx)
  int ctx;
{
  int iVar1;
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x98) != 0x2c) &&
     (iVar1 = FUN_0011379c(*(undefined4 *)(ctx + 0x238),*(int *)(ctx + 0xb0)), iVar1 != 0))
  {
    ((int (*)())FUN_0017f5a4)(ctx);
    return;
  }
  return;
}

/* FUN_0017f7ec @ 0x17f7ec (1848 bytes) */
int FUN_0017f7ec(ctx)
  int ctx;
{
  bool bVar1;
  int loopIndex;
  int *loopPtr3;
  int *loopPtr4;
  int loopIndex2;
  int local_38 [8];
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x80) == 1) &&
     (loopIndex = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0), *(int *)(loopIndex + 0x10) == DAT_001b01d0)) {
    return 0;
  }
  loopPtr4 = local_38;
  loopIndex = 4;
  loopPtr3 = loopPtr4;
  do {
    *loopPtr3 = 0x7ffffffe;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex2 = 4;
  loopIndex = 0;
  do {
    *(undefined4 *)(loopIndex + (int)loopPtr4) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopIndex2 = loopIndex2 + -1;
  } while (loopIndex2 != 0);
  loopIndex = ((int (*)())FUN_0017dbdc)(ctx,loopPtr4);
  if (loopIndex != 0) {
    return 0;
  }
  loopPtr3 = (int *)Opcode__getInfo(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8));
  loopIndex = (**(code **)(*loopPtr3 + 0x14))(loopPtr3,ctx,loopPtr4,*(undefined4 *)(ctx + 0x238));
  if (loopIndex == 0) {
    return 0;
  }
  loopIndex2 = *(int *)(ctx + 0xb0);
  loopIndex = *(int *)(*(int *)(loopIndex2 + 0x88) + 8);
  if (loopIndex == 0x1d) {
    ValueKey__cancelNegatedSourcePair(ctx);
    loopIndex = ((int (*)())ValueKey__foldDot4UnitVectorSource)(ctx);
    if (loopIndex != 0) {
      return 0;
    }
    loopIndex = ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx);
    if (loopIndex != 0) {
      return 1;
    }
    loopIndex = FUN_001766bc(ctx);
joined_r0x0017f980:
    if (loopIndex != 0) {
      return 1;
    }
  }
  else if (loopIndex < 0x1e) {
    if (loopIndex == 0x17) {
      loopIndex = ((int (*)())FUN_0017cb14)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource1IfSourcesEqual)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldMaxOfNegatedPair)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_00179e74(ctx,loopIndex2), loopIndex == 0)) {
            FUN_0017994c(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
    else if (loopIndex < 0x18) {
      if (loopIndex == 0x13) {
        ValueKey__cancelNegatedSourcePair(ctx);
        loopIndex = ((int (*)())ValueKey__foldMulByZero)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())ValueKey__foldMulByPlusMinusOne)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xc);
        if ((loopIndex != 0) && (loopIndex = ((int (*)())ValueKey__foldMulPowerOfTwoIntoOutputScale)(ctx), loopIndex != 0)) {
          return 0;
        }
        loopIndex2 = 0;
        loopPtr3 = loopPtr4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_001768d4(ctx,loopIndex2), loopIndex == 0)) {
              FUN_00179f38(ctx,loopIndex2);
            }
          }
          bVar1 = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
      }
      else {
        if (loopIndex != 0x14) goto LAB_0017fe28;
        ValueKey__cancelNegatedSourcePair(ctx);
        loopIndex = ((int (*)())FUN_0017cd18)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())ValueKey__foldMadByPlusMinusOne)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())ValueKey__foldMadZeroAddend)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())FUN_0017f1f8)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex2 = 0;
        loopPtr3 = loopPtr4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if (*loopPtr3 == 0x7ffffffe) {
              FUN_00179db0(ctx,loopIndex2);
            }
          }
          bVar1 = loopIndex2 != 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
      }
    }
    else {
      if (loopIndex != 0x19) {
        if (loopIndex == 0x1c) {
          ValueKey__cancelNegatedSourcePair(ctx);
          loopIndex = ((int (*)())ValueKey__foldDot3SingleLaneSource)(ctx);
          if (loopIndex != 0) {
            return 0;
          }
          loopIndex = ValueKey__foldDotPowerOfTwoIntoOutputScale(ctx);
          goto joined_r0x0017f980;
        }
LAB_0017fe28:
        loopIndex = *(int *)(ctx + 0x238);
        goto LAB_0017fe34;
      }
      loopIndex = ((int (*)())FUN_0017c910)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource1IfSourcesEqual)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldMinOfNegatedPair)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_00179e74(ctx,loopIndex2), loopIndex == 0)) {
            FUN_00179a34(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
  }
  else if (loopIndex < 0x2b) {
    if (loopIndex < 0x27) {
      if (loopIndex < 0x24) goto LAB_0017fe28;
      loopIndex = ((int (*)())FUN_0017c5e0)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__replaceWithSource2IfSourcesEqual23)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017c4a4)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_0017a034(ctx,loopIndex2), loopIndex == 0)) {
            FUN_001797d0(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
    else {
      loopIndex = ((int (*)())FUN_0017d9b8)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())ValueKey__foldCompareSameSourcesToConstant)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopPtr3 = loopPtr4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopPtr3 == 0x7ffffffe) && (loopIndex = FUN_00176954(ctx,loopIndex2), loopIndex == 0)) {
            ValueKey__foldCompareSameSourcesValueNumber(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
  }
  else {
    if (loopIndex == 0x8b) {
      loopIndex = FUN_0017a748(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = FUN_0017a3d4(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      FUN_00177748(ctx);
      loopIndex2 = *(int *)(ctx + 0xb0);
      loopIndex = *(int *)(ctx + 0x238);
      goto LAB_0017fe34;
    }
    if (loopIndex != 0x8c) goto LAB_0017fe28;
    loopIndex = FUN_0017a8a4(ctx);
    if (loopIndex != 0) {
      return 0;
    }
  }
  loopIndex2 = *(int *)(ctx + 0xb0);
  loopIndex = *(int *)(ctx + 0x238);
LAB_0017fe34:
  loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(loopIndex2 + 0x88) + 8),loopIndex);
  if ((loopIndex == 0) &&
     (loopIndex = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
    loopIndex = 0;
    do {
      if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*loopPtr4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopPtr4,loopIndex);
      }
      bVar1 = loopIndex != 3;
      loopPtr4 = loopPtr4 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  else {
    loopIndex = 0;
    do {
      if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*loopPtr4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopPtr4,loopIndex);
      }
      bVar1 = loopIndex != 3;
      loopPtr4 = loopPtr4 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  return 0;
LAB_0017fe30:
  loopIndex2 = *(int *)(ctx + 0xb0);
  goto LAB_0017fe34;
}

/* FUN_00180154 @ 0x180154 (888 bytes) */
int FUN_00180154(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int loopIndex;
  int loopIndex2;
  
  switch(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8)) {
  case 0x16:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    FUN_0017662c(ctx);
    loopIndex = 0;
    loopIndex2 = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(loopIndex2 + 0x30) == 0)) &&
         (*(int *)(*(int *)(ctx + 0xb0) + 0x124) < 1)) {
        iVar3 = *(int *)(loopIndex2 + 0x40);
        if (iVar3 == 0) {
          iVar3 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
          *(int *)(loopIndex2 + 0x40) = iVar3;
        }
        *(undefined4 *)(iVar3 + 0x10) = 4;
      }
      bVar1 = loopIndex != 3;
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    return;
  default:
    return;
  case 0x1c:
    break;
  case 0x1d:
    loopIndex = 0;
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(int *)(loopIndex2 + 0x10) != DAT_001b01d0) {
      loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      loopIndex = SelectWord__firstWrittenComponent(*(undefined4 *)(loopIndex2 + 0x10));
    }
    if (*(int *)(loopIndex * 4 + ctx + 0x30) == 0) {
      uVar4 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
      uVar2 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
      if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
        loopIndex2 = 0;
        do {
          iVar3 = FUN_00179608(ctx,loopIndex2,1,2);
          if (iVar3 == 0) {
            return;
          }
          bVar1 = loopIndex2 != 3;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
        loopIndex2 = *(int *)(loopIndex * 4 + ctx + 0x40);
        if (loopIndex2 == 0) {
          loopIndex2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        }
        *(undefined4 *)(loopIndex2 + 0xc) = 4;
        loopIndex = 4;
        do {
          *(int *)(ctx + 0x40) = loopIndex2;
          ctx = ctx + 4;
          loopIndex = loopIndex + -1;
        } while (loopIndex != 0);
      }
    }
    return;
  }
  loopIndex = 0;
  loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  if (*(int *)(loopIndex2 + 0x10) != DAT_001b01d0) {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopIndex = SelectWord__firstWrittenComponent(*(undefined4 *)(loopIndex2 + 0x10));
  }
  if (*(int *)(loopIndex * 4 + ctx + 0x30) == 0) {
    uVar4 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      loopIndex2 = 0;
      do {
        iVar3 = FUN_00179608(ctx,loopIndex2,1,2);
        if (iVar3 == 0) {
          return;
        }
        bVar1 = loopIndex2 != 2;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      loopIndex2 = *(int *)(loopIndex * 4 + ctx + 0x40);
      if (loopIndex2 == 0) {
        loopIndex2 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
      }
      loopIndex = 4;
      *(undefined4 *)(loopIndex2 + 0xc) = 4;
      do {
        *(int *)(ctx + 0x40) = loopIndex2;
        ctx = ctx + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
    }
  }
  return;
}

/* ValueKey__canonicalizeConstantSources @ 0x180250 (1504 bytes) */
int ValueKey__canonicalizeConstantSources(key)
  int key;
{
  int flagBit0;
  int flagBit2Result;
  int operandRecord2;
  int operandRecord;
  bool bVar1;
  bool hasNegativeConstant;
  char cVar3;
  int iVar4;
  float *constantRecord;
  int iVar6;
  int loopIndex2;
  char *loopPtr5;
  int loopIndex3;
  int iVar10;
  int *loopPtr6;
  char *loopPtr4;
  undefined4 changed;
  int loopIndex;
  uint vectorFilledCount;
  uint uVar16;
  int *loopPtr7;
  uint *vector;
  int loopRemaining;
  int local_58;
  int local_54 [3];
  int local_48;
  int local_44 [7];
  
  loopPtr7 = *(int **)(key + 0xb0);
  if (*(int *)(loopPtr7[0x22] + 8) == 0x77) {
    operandRecord = IRInst__getOperandRecord(loopPtr7,1);
    local_54[0] = *(int *)(operandRecord + 0x10);
    hasNegativeConstant = false;
    loopIndex = 0;
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
    local_58 = *(int *)(operandRecord + 0x10);
    iVar4 = key;
    do {
      if (*(int *)(iVar4 + 0x178) < 0) {
        constantRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*(int *)(iVar4 + 0x178));
        local_44[1] = 0;
        if (0.0 <= *constantRecord) {
          if ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x1000) != 0) {
            *(undefined1 *)((int)local_54 + loopIndex) = 4;
            *(undefined1 *)((int)local_54 + loopIndex + -4) = 1;
          }
        }
        else {
          hasNegativeConstant = true;
        }
      }
      bVar1 = loopIndex != 3;
      iVar4 = iVar4 + 4;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    if (hasNegativeConstant) {
      hasNegativeConstant = false;
      loopIndex = 0;
      iVar4 = key;
      do {
        if (((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x1000) != 0) &&
           (*(int *)(iVar4 + 0x178) < 0)) {
          constantRecord = (float *)Compiler__exprRecordForValueNumber(*(int *)(key + 0x238),*(int *)(iVar4 + 0x178));
          local_44[1] = 0;
          if (*constantRecord < 0.0) {
            if (hasNegativeConstant) {
              *(undefined1 *)((int)local_54 + loopIndex) = 4;
              *(undefined1 *)((int)local_54 + loopIndex + -4) = 1;
            }
            hasNegativeConstant = true;
          }
        }
        bVar1 = loopIndex != 3;
        iVar4 = iVar4 + 4;
        loopIndex = loopIndex + 1;
      } while (bVar1);
    }
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),1);
    iVar4 = local_54[0];
    if (local_54[0] == *(int *)(loopIndex + 0x10)) {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001803f4;
    }
    changed = 1;
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),1);
    *(int *)(loopIndex + 0x10) = iVar4;
    *(int *)(*(int *)(key + 0xb0) + 0x9c) = local_58;
    loopPtr7 = *(int **)(key + 0xb0);
  }
  else {
LAB_001803f4:
    changed = 0;
  }
  if (loopPtr7[0x20] == 0) {
LAB_001807f4:
    iVar4 = (**(code **)(*loopPtr7 + 0x68))(loopPtr7);
    if (iVar4 != 0) goto LAB_00180440;
  }
  else {
    flagBit0 = RegKind__flagBit0(loopPtr7[0x26]);
    if (((flagBit0 == 0) || ((loopPtr7[5] & 2U) != 0)) ||
       (flagBit0 = (**(code **)(*loopPtr7 + 0x50))(loopPtr7), flagBit0 != 0)) {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001807f4;
    }
LAB_00180440:
    iVar4 = (**(code **)(**(int **)(key + 0xb0) + 0x28))(*(int **)(key + 0xb0));
    if ((iVar4 == 0) || ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x800) != 0))
    {
      loopPtr7 = *(int **)(key + 0xb0);
      goto LAB_001804a4;
    }
  }
  loopPtr7 = *(int **)(key + 0xb0);
  if (*(int *)(loopPtr7[0x22] + 8) != 0x77) {
    return changed;
  }
  if ((*(uint *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 8) & 0x800) == 0) {
    return changed;
  }
LAB_001804a4:
  loopIndex = 1;
  iVar4 = key;
  do {
    iVar6 = (**(code **)(*loopPtr7 + 0x14))(loopPtr7);
    if (iVar6 < loopIndex) {
      return changed;
    }
    iVar6 = thunk_FUN_001268a4(*(undefined4 *)(loopIndex * 0x18 + *(int *)(key + 0xb0) + 0x98));
    if (iVar6 != 0) {
      vector = *(uint **)(*(int *)(loopIndex * 0x18 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
      vectorFilledCount = vector[1];
      uVar16 = vectorFilledCount - 1;
      if (uVar16 < *vector) {
        if (vectorFilledCount <= uVar16) {
          _memset(vectorFilledCount * 4 + vector[2],0,(uVar16 - vectorFilledCount) * 4 + 4);
          vector[1] = vectorFilledCount;
        }
        loopPtr7 = (int *)(uVar16 * 4 + vector[2]);
      }
      else {
        loopPtr7 = (int *)Vector__elementRefGrow(vector,uVar16);
      }
      if ((*(int *)(*(int *)(*(int *)(*loopPtr7 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*loopPtr7 + 0xb4) != 0)) {
        iVar6 = FUN_001793d8(key,loopIndex,*(undefined4 *)(iVar4 + 0x228));
        if (iVar6 == 4) {
          operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          local_58 = *(int *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          local_54[0] = *(int *)(operandRecord2 + 0x10);
          flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(key + 0x238));
          if (flagBit2Result == 0) {
            SelectWord__maskUnused(local_44,local_54[0],*(undefined4 *)(iVar4 + 0x228));
            local_54[0] = local_44[0];
          }
          iVar6 = key + loopIndex * 4 + 0x220;
          iVar10 = key + loopIndex * 0x10 + 0x160;
          loopPtr5 = (char *)(iVar6 + 4);
          loopPtr7 = (int *)(iVar10 + 8);
          loopIndex2 = 0;
          do {
            if (*loopPtr5 != '\0') {
              loopRemaining = 4;
              loopPtr4 = (char *)(iVar6 + 4);
              loopPtr6 = (int *)(iVar10 + 8);
              loopIndex3 = 0;
              do {
                if (*loopPtr4 != '\0') {
                  if (loopIndex3 == loopIndex2) break;
                  if ((*loopPtr7 == *loopPtr6) &&
                     (cVar3 = *(char *)((int)local_54 + loopIndex3 + -4),
                     *(char *)((int)local_54 + loopIndex2) != cVar3)) {
                    *(char *)((int)local_54 + loopIndex2) = cVar3;
                    break;
                  }
                }
                loopIndex3 = loopIndex3 + 1;
                loopPtr4 = loopPtr4 + 1;
                loopPtr6 = loopPtr6 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
            }
            hasNegativeConstant = loopIndex2 != 3;
            loopPtr5 = loopPtr5 + 1;
            loopPtr7 = loopPtr7 + 1;
            loopIndex2 = loopIndex2 + 1;
          } while (hasNegativeConstant);
          if ((local_54[0] != local_58) &&
             (loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopPtr7 + 0x104))
                               (loopPtr7,*(undefined4 *)(key + 0xb0),loopIndex,local_54,0),
             iVar6 = local_54[0], loopIndex2 != 0)) {
            loopIndex2 = *(int *)(key + 0xb0);
            if (loopIndex == 0) {
LAB_00180784:
              changed = 1;
              *(int *)(loopIndex2 + 0x9c) = iVar6;
            }
            else {
              changed = 1;
              loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
              *(int *)(loopIndex2 + 0x10) = iVar6;
            }
          }
        }
        else {
          local_58 = *(int *)(PTR_DAT_001e8b8c + iVar6 * 4);
          flagBit2Result = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(key + 0x238));
          if (flagBit2Result == 0) {
            SelectWord__maskUnused(&local_48,local_58,*(undefined4 *)(iVar4 + 0x228));
            local_58 = local_48;
          }
          iVar6 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex);
          if ((local_58 != *(int *)(iVar6 + 0x10)) &&
             (loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopPtr7 + 0x104))
                               (loopPtr7,*(undefined4 *)(key + 0xb0),loopIndex,&local_58,0),
             iVar6 = local_58, loopIndex2 != 0)) {
            loopIndex2 = *(int *)(key + 0xb0);
            if (loopIndex == 0) goto LAB_00180784;
            changed = 1;
            loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
            *(int *)(loopIndex2 + 0x10) = iVar6;
          }
        }
      }
    }
    loopPtr7 = *(int **)(key + 0xb0);
    loopIndex = loopIndex + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* ValueKey__simplifyModifiersAndAddressing @ 0x180830 (2472 bytes) */
int ValueKey__simplifyModifiersAndAddressing(key)
  int key;
{
  int operandRecord2;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  undefined4 opcode;
  undefined4 arena;
  undefined4 inst1;
  undefined4 operandRef2;
  undefined4 operandRef;
  uint *vector4;
  uint *vector3;
  uint *vector2;
  int newSource;
  int operandIndex;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int loopIndex4;
  float *addressRecord;
  int loopIndex5;
  void *inst;
  int *callResult;
  void *inst2;
  int loopRemaining;
  undefined4 *loopPtr9;
  int *loopPtr7;
  int operandRecord;
  int loopIndex;
  undefined4 changed;
  int loopIndex2;
  int iVar17;
  uint uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  undefined4 uVar22;
  uint uVar23;
  int *loopPtr8;
  void *inst3;
  char *loopPtr6;
  uint *vector;
  int loopIndex3;
  double floorValue;
  uint local_9c;
  uint local_98;
  int aiStack_94 [3];
  longlong local_88;
  longlong local_80;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c [3];
  
  if (*(int *)(*(int *)(key + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0xa8)) {
    return 0;
  }
  loopPtr8 = *(int **)(key + 0xb0);
  changed = 0;
  for (operandIndex = 1; loopIndex4 = (**(code **)(*loopPtr8 + 0x14))(loopPtr8), operandIndex <= loopIndex4;
      operandIndex = operandIndex + 1) {
    loopPtr8 = *(int **)(key + 0xb0);
    if ((loopPtr8[operandIndex * 6 + 0x28] & 2U) != 0) {
      vector = *(uint **)(loopPtr8[operandIndex * 6 + 0x23] + 0x2c);
      vectorFilledCount2 = vector[1];
      uVar18 = vectorFilledCount2 - 1;
      if (uVar18 < *vector) {
        if (vectorFilledCount2 <= uVar18) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(uVar18 - vectorFilledCount2) * 4 + 4);
          vector[1] = vectorFilledCount2;
          loopPtr8 = *(int **)(key + 0xb0);
        }
        loopPtr9 = (undefined4 *)(uVar18 * 4 + vector[2]);
      }
      else {
        loopPtr9 = (undefined4 *)Vector__elementRefGrow(vector,uVar18);
        loopPtr8 = *(int **)(key + 0xb0);
      }
      uVar22 = *loopPtr9;
      bVar2 = true;
      loopPtr6 = (char *)(operandIndex * 4 + key + 0x224);
      bVar3 = true;
      loopIndex4 = 0;
      do {
        if (*loopPtr6 != '\0') {
          iVar19 = IRInst__getOperandRecord(loopPtr8,operandIndex);
          iVar19 = ValueKey__sourceKindIs4(uVar22,(uint)*(byte *)(loopIndex4 + iVar19 + 0x10));
          if (iVar19 == 0) {
            iVar19 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),operandIndex);
            iVar19 = ValueKey__sourceKindIs1(uVar22,(uint)*(byte *)(loopIndex4 + iVar19 + 0x10));
            if ((iVar19 == 0) || (!bVar3)) {
LAB_00180a10:
              loopPtr8 = *(int **)(key + 0xb0);
              goto LAB_00180a14;
            }
            loopPtr8 = *(int **)(key + 0xb0);
            bVar2 = false;
          }
          else {
            if (!bVar2) goto LAB_00180a10;
            loopPtr8 = *(int **)(key + 0xb0);
            bVar3 = false;
          }
        }
        bVar1 = loopIndex4 != 3;
        loopPtr6 = loopPtr6 + 1;
        loopIndex4 = loopIndex4 + 1;
      } while (bVar1);
      if (bVar2) {
        IROperand__setModifierBits(loopPtr8 + operandIndex * 6 + 0x23,2,0);
        loopPtr8 = *(int **)(key + 0xb0);
        changed = 1;
      }
      else if ((bVar3) && ((loopPtr8[operandIndex * 6 + 0x28] & 1U) != 0)) {
        changed = 1;
        IROperand__setModifierBits(loopPtr8 + operandIndex * 6 + 0x23,2,0);
        IROperand__setModifierBits(operandIndex * 0x18 + *(int *)(key + 0xb0) + 0x8c,1,0);
        loopPtr8 = *(int **)(key + 0xb0);
      }
    }
LAB_00180a14: ;
  }
  iVar17 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),10);
  if (iVar17 != 0) {
    loopIndex4 = 0x18;
    iVar17 = key;
    for (iVar19 = 1;
        loopIndex5 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        iVar19 <= loopIndex5; iVar19 = iVar19 + 1) {
      loopIndex5 = IRInst__operandKindClass(*(undefined4 *)(key + 0xb0),iVar19);
      if (loopIndex5 == 2) {
        vector2 = *(uint **)(*(int *)(loopIndex4 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
        vectorFilledCount = vector2[1];
        uVar21 = vectorFilledCount - 1;
        if (uVar21 < *vector2) {
          if (vectorFilledCount <= uVar21) {
            _memset(vectorFilledCount * 4 + vector2[2],0,(uVar21 - vectorFilledCount) * 4 + 4);
            vector2[1] = vectorFilledCount;
          }
          loopPtr8 = (int *)(uVar21 * 4 + vector2[2]);
        }
        else {
          loopPtr8 = (int *)Vector__elementRefGrow(vector2,uVar21);
        }
        loopIndex2 = *loopPtr8;
        loopIndex5 = *(int *)(loopIndex2 + 0x178);
        if (loopIndex5 < 0) {
          addressRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),loopIndex5);
          if (*(int *)(*(int *)(loopIndex2 + 0xb0) + 300) == 0) {
            floorValue = _floor((double)*addressRecord);
            loopIndex5 = (int)floorValue;
            local_80 = (longlong)loopIndex5;
          }
          else {
            floorValue = _floor((double)*addressRecord + 0.5);
            loopIndex5 = (int)floorValue;
            local_88 = (longlong)loopIndex5;
          }
          loopIndex2 = IRInst__getDefiningField128(*(undefined4 *)(key + 0xb0),iVar19);
          loopIndex5 = loopIndex5 + loopIndex2;
          if (*(int *)(*(int *)(*(int *)(key + 0x238) + 0x30c) + 0x2c) <= loopIndex5) {
            loopIndex5 = 0;
          }
          loopIndex2 = *(int *)(key + 0xb0);
          operandRef2 = *(undefined4 *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x3ac);
          if ((iVar19 < 1) || (loopIndex = IRInst__getOperandSource(loopIndex2,iVar19), loopIndex == 0)) {
            uVar20 = *(undefined4 *)(loopIndex4 + loopIndex2 + 0x98);
          }
          else {
            loopIndex2 = IRInst__getOperandSource(loopIndex2,iVar19);
            uVar20 = *(undefined4 *)(loopIndex2 + 0x98);
          }
          loopIndex2 = RegKind__flagBit7(uVar20);
          if (loopIndex2 == 0) {
            operandRef2 = FUN_00127608(operandRef2,0,loopIndex5,0);
          }
          else {
            operandRef2 = FUN_00127608(operandRef2,2,loopIndex5,0);
          }
          IRInst__setOperandRef(*(undefined4 *)(key + 0xb0),iVar19,operandRef2);
          VReg__addUse(operandRef2,iVar19,*(undefined4 *)(key + 0xb0));
          loopIndex5 = VReg__currentDefinition(operandRef2,*(undefined4 *)
                                       (*(int *)(*(uint *)(key + 0x238) + 0x6c4) + 0x3a0),
                               *(uint *)(key + 0x238));
          *(undefined4 *)(iVar17 + 0x214) = *(undefined4 *)(loopIndex5 + 0xb0);
        }
      }
      loopIndex4 = loopIndex4 + 0x18;
      iVar17 = iVar17 + 4;
    }
  }
  loopPtr8 = *(int **)(key + 0xb0);
  if (loopPtr8[0x20] == 0) {
LAB_001818e8:
    if (((loopPtr8[5] & 2U) != 0) || (iVar17 = IRInst__isOpcode8bOr8c(loopPtr8), iVar17 != 0))
    goto LAB_00180cb4;
  }
  else {
    iVar17 = RegKind__flagBit0(loopPtr8[0x26]);
    if (((iVar17 == 0) || ((loopPtr8[5] & 2U) != 0)) ||
       (iVar17 = (**(code **)(*loopPtr8 + 0x50))(loopPtr8), iVar17 != 0)) {
      loopPtr8 = *(int **)(key + 0xb0);
      goto LAB_001818e8;
    }
    loopPtr8 = *(int **)(key + 0xb0);
LAB_00180cb4:
    iVar17 = key;
    for (loopIndex4 = 1; iVar19 = (**(code **)(*loopPtr8 + 0x14))(loopPtr8), loopIndex4 <= iVar19;
        loopIndex4 = loopIndex4 + 1) {
      vector3 = *(uint **)(*(int *)(loopIndex4 * 0x18 + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
      vectorFilledCount3 = vector3[1];
      uVar18 = vectorFilledCount3 - 1;
      if (uVar18 < *vector3) {
        if (vectorFilledCount3 <= uVar18) {
          _memset(vectorFilledCount3 * 4 + vector3[2],0,(uVar18 - vectorFilledCount3) * 4 + 4);
          vector3[1] = vectorFilledCount3;
        }
        loopPtr8 = (int *)(uVar18 * 4 + vector3[2]);
      }
      else {
        loopPtr8 = (int *)Vector__elementRefGrow(vector3,uVar18);
      }
      loopPtr8 = *(int **)(*loopPtr8 + 0xb0);
      iVar19 = (**(code **)(*loopPtr8 + 0x74))(loopPtr8);
      if (((iVar19 != 0) && (*(int *)(loopPtr8[0x22] + 8) == 0xfb)) &&
         (iVar19 = IRInst__operandKindClass(*(undefined4 *)(key + 0xb0),loopIndex4), iVar19 == 0)) {
        iVar19 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),loopIndex4);
        SelectWord__readMask(&local_78,*(undefined4 *)(iVar19 + 0x10));
        local_9c = local_78;
        loopPtr7 = (int *)((int (*)())FUN_0017bc58)(loopPtr8,local_78,1,*(undefined4 *)(key + 0x238));
        if (loopPtr7 != (int *)0x0) {
          iVar19 = (**(code **)(*loopPtr7 + 0x40))(loopPtr7);
          if (iVar19 == 0) {
            operandRecord2 = IRInst__getOperandRecord(loopPtr7,0);
            WriteMask__fromSelectWord(&local_74,*(undefined4 *)(operandRecord2 + 0x10));
            uVar18 = local_74;
            uVar21 = ~local_74;
            if (((uVar21 << 0x18 | (uVar21 & 0xff00) << 8 | uVar21 >> 8 & 0xff00 | uVar21 >> 0x18) &
                local_9c) == 0) {
              iVar19 = IRInst__getOperandSource(loopPtr7,1);
              *(int *)(iVar17 + 0x214) = iVar19;
              operandRef = *(undefined4 *)(iVar19 + 0x8c);
              inst1 = *(undefined4 *)(key + 0xb0);
            }
            else {
              inst = IRInst__create(0x31,*(undefined4 *)(key + 0x238));
              IRInst__setOperandRef(inst,0,loopPtr8[0x23]);
              *(undefined4 *)((int)inst + 0x98) = 0;
              *(undefined4 *)((int)inst + 0x94) = *(undefined4 *)((int)inst + 0x14c);
              newSource = IRInst__getOperandSource(loopPtr7,1);
              IRInst__setOperandRef(inst,1,*(undefined4 *)(newSource + 0x8c));
              IRInst__setOperandSource(inst,1,newSource,0,*(undefined4 *)(key + 0x238));
              uVar21 = ~(uVar18 & local_9c);
              laneBytes__clearSetLanes(&local_70,uVar18 & local_9c);
              *(undefined4 *)((int)inst + 0x9c) = local_70;
              FUN_000f370c(&local_6c,local_70);
              uVar22 = local_6c;
              operandRecord2 = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(operandRecord2 + 0x10) = uVar22;
              iVar19 = 0;
              local_98 = (uint)inst;
              local_9c = (uVar21 << 0x18 | (uVar21 & 0xff00) << 8 | uVar21 >> 8 & 0xff00 |
                         uVar21 >> 0x18) & local_9c;
              if (local_9c == 0) {
LAB_00181100:
                loopPtr8 = aiStack_94 + iVar19 + -1;
                loopIndex5 = 0;
                do {
                  loopIndex = *loopPtr8;
                  Block__insertInstBefore(*(undefined4 *)(*(int *)(key + 0xb0) + 0x158),
                               *(int *)(key + 0xb0),loopIndex);
                  FUN_0012306c(*(undefined4 *)(loopIndex + 0x8c),loopIndex);
                  loopIndex2 = IRInst__getOperandSource(loopIndex,1);
                  VReg__addUse(*(undefined4 *)(loopIndex2 + 0x8c),1,loopIndex);
                  arena = *(undefined4 *)(*(int *)(key + 0x238) + 0x378);
                  loopPtr9 = (undefined4 *)Arena__alloc(arena,0x240);
                  *loopPtr9 = arena;
                  loopPtr9 = loopPtr9 + 1;
                  ValueKey__init(loopPtr9,loopIndex,*(undefined4 *)(key + 0x238));
                  loopIndex5 = loopIndex5 + 1;
                  loopPtr8 = loopPtr8 + -1;
                  ValueKey__loadSourceDefinitions(loopPtr9,*(undefined4 *)
                                        (*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x3a0));
                  ValueKey__fill(loopPtr9);
                  FUN_00174e0c(loopPtr9);
                  FUN_00175b40(loopPtr9);
                  ValueKey__propagateLaneValues(loopPtr9);
                  Block__recordDefinition(*(undefined4 *)(*(int *)(key + 0xb0) + 0x158),
                               *(undefined4 *)(loopIndex + 0x8c),loopPtr9);
                } while (iVar19 + 1 != loopIndex5);
              }
              else {
                loopPtr7 = aiStack_94;
                loopIndex5 = 1;
                inst3 = inst;
                do {
                  iVar19 = loopIndex5;
                  callResult = (int *)((int (*)())FUN_0017bc58)(loopPtr8,local_9c,0,*(undefined4 *)(key + 0x238));
                  if (callResult == (int *)0x0) goto LAB_00181220;
                  inst2 = IRInst__create(0x31,*(undefined4 *)(key + 0x238));
                  IRInst__setOperandRef(inst2,0,loopPtr8[0x23]);
                  *(undefined4 *)((int)inst2 + 0x98) = 0;
                  *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
                  IRInst__appendSource(inst3,*(undefined4 *)((int)inst2 + 0x8c));
                  IRInst__setExtraOperandSource(inst3,inst2,0,*(undefined4 *)(key + 0x238));
                  loopIndex5 = IRInst__getOperandRecord(callResult,0);
                  WriteMask__fromSelectWord(&local_68,*(undefined4 *)(loopIndex5 + 0x10));
                  uVar18 = local_68 & local_9c;
                  laneBytes__clearSetLanes(&local_64,uVar18);
                  *(undefined4 *)((int)inst2 + 0x9c) = local_64;
                  FUN_000f370c(&local_60,local_64);
                  uVar22 = local_60;
                  loopIndex5 = IRInst__getOperandRecord(inst2,1);
                  *(undefined4 *)(loopIndex5 + 0x10) = uVar22;
                  loopIndex5 = (**(code **)(*callResult + 0x40))(callResult);
                  if (loopIndex5 == 0) {
                    loopIndex5 = IRInst__getOperandSource(callResult,1);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(key + 0x238));
                  }
                  else {
                    loopIndex5 = *(int *)(*(int *)(key + 0x238) + 0x6c4);
                    loopIndex5 = FUN_00123c08(loopIndex5,*(undefined4 *)(loopIndex5 + 0x3a0),0);
                    loopIndex5 = *(int *)(loopIndex5 + 0xb0);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(key + 0x238));
                    local_9c = 0;
                  }
                  uVar18 = ~uVar18;
                  local_9c = (uVar18 << 0x18 | (uVar18 & 0xff00) << 8 | uVar18 >> 8 & 0xff00 |
                             uVar18 >> 0x18) & local_9c;
                  *loopPtr7 = (int)inst2;
                  loopPtr7 = loopPtr7 + 1;
                  loopIndex5 = iVar19 + 1;
                  inst3 = inst2;
                } while (local_9c != 0);
                if (iVar19 + 1 == 0) goto LAB_00181220;
                if (-1 < iVar19) goto LAB_00181100;
              }
              *(void **)(iVar17 + 0x214) = inst;
              operandRef = *(undefined4 *)((int)inst + 0x8c);
              inst1 = *(undefined4 *)(key + 0xb0);
            }
          }
          else {
            iVar19 = *(int *)(*(int *)(key + 0x238) + 0x6c4);
            iVar19 = FUN_00123c08(iVar19,*(undefined4 *)(iVar19 + 0x3a0),0);
            iVar19 = *(int *)(iVar19 + 0xb0);
            inst1 = *(undefined4 *)(key + 0xb0);
            *(int *)(iVar17 + 0x214) = iVar19;
            operandRef = *(undefined4 *)(iVar19 + 0x8c);
          }
          IRInst__setOperandRef(inst1,loopIndex4,operandRef);
          VReg__addUse(operandRef,loopIndex4,*(undefined4 *)(key + 0xb0));
        }
      }
LAB_00181220:
      loopPtr8 = *(int **)(key + 0xb0);
      iVar17 = iVar17 + 4;
    }
    loopPtr8 = *(int **)(key + 0xb0);
  }
  if (loopPtr8[0x20] != 0) {
    iVar17 = RegKind__flagBit0(loopPtr8[0x26]);
    if (((iVar17 != 0) && ((loopPtr8[5] & 2U) == 0)) &&
       (iVar17 = (**(code **)(*loopPtr8 + 0x50))(loopPtr8), iVar17 == 0)) {
      loopPtr8 = *(int **)(key + 0xb0);
      goto code_r0x001812b0;
    }
    loopPtr8 = *(int **)(key + 0xb0);
  }
  if (((loopPtr8[5] & 2U) == 0) && (iVar17 = IRInst__isOpcode8bOr8c(loopPtr8), iVar17 == 0)) {
    return changed;
  }
code_r0x001812b0:
  loopIndex2 = 1;
  iVar19 = key + 0x170;
  loopIndex5 = key + 0x224;
  loopIndex4 = 4;
  iVar17 = key;
  do {
    loopIndex = (**(code **)(*loopPtr8 + 0x14))(loopPtr8);
    if (loopIndex < loopIndex2) {
      return changed;
    }
    loopPtr8 = *(int **)(key + 0xb0);
    opcode = *(undefined4 *)(loopPtr8[0x22] + 8);
    loopRemaining = FUN_00176564(opcode);
    loopIndex = 0x7ffffffe;
    if (loopRemaining == 0) {
      loopIndex = FUN_00176574(opcode);
      if (loopIndex == 0) {
        loopIndex = OpcodeTraits__flagBit7(opcode,*(undefined4 *)(key + 0x238));
        if (loopIndex == 0) {
          loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(key + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(key + 0x238));
          if (loopIndex == 0) {
            FUN_001770e4(&local_50,key,loopIndex2);
            loopPtr8 = *(int **)(key + 0xb0);
            loopIndex = local_50;
          }
          else {
            FUN_001769f4(&local_54,key,loopIndex2);
            loopPtr8 = *(int **)(key + 0xb0);
            loopIndex = local_54;
          }
        }
        else {
          FUN_00178d78(&local_58,key,loopIndex2);
          loopPtr8 = *(int **)(key + 0xb0);
          loopIndex = local_58;
        }
      }
      else {
        FUN_00178c84(&local_5c,key,loopIndex2);
        loopPtr8 = *(int **)(key + 0xb0);
        loopIndex = local_5c;
      }
    }
    if ((loopPtr8[5] & 2U) == 0) {
code_r0x001813e0:
      if (((loopPtr8[loopIndex2 * 6 + 0x26] == 0x33) || (loopPtr8[loopIndex2 * 6 + 0x26] == 0xc)) ||
         (*(int *)(loopIndex5 + 4) == 0)) goto code_r0x001816c0;
      loopPtr6 = (char *)(loopIndex5 + 4);
      aiStack_94[2] = 0;
      loopPtr8 = (int *)(iVar19 + 8);
      local_98 = 0;
      bVar3 = true;
      aiStack_94[0] = 0;
      loopRemaining = 0;
      aiStack_94[1] = 0;
      do {
        if (*loopPtr6 != '\0') {
          if (*loopPtr8 < 0) {
            loopPtr9 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*loopPtr8);
            *(undefined4 *)((int)aiStack_94 + loopRemaining + -4) = *loopPtr9;
          }
          else {
            bVar3 = false;
          }
        }
        bVar2 = loopRemaining != 0xc;
        loopPtr6 = loopPtr6 + 1;
        loopPtr8 = loopPtr8 + 1;
        loopRemaining = loopRemaining + 4;
      } while (bVar2);
      uVar22 = *(undefined4 *)(*(int *)(key + 0x238) + 0x6c4);
      SelectWord__maskUnused(local_4c,0x10203,*(undefined4 *)(iVar17 + 0x228));
      local_9c = local_4c[0];
      if (loopIndex != 0x7ffffffe) {
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,uVar22,&local_98,&local_9c);
        if (loopRemaining == 0) {
          loopIndex3 = 4;
          loopPtr6 = (char *)(loopIndex4 + key + 0x224);
          loopRemaining = 0;
          do {
            if (*loopPtr6 != '\0') {
              *(float *)(loopRemaining + (int)&local_98) = -*(float *)(loopRemaining + (int)&local_98);
            }
            loopPtr6 = loopPtr6 + 1;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + -1;
          } while (loopIndex3 != 0);
          goto code_r0x00181590;
        }
code_r0x001815cc:
        uVar20 = 0;
code_r0x001815d0:
        loopPtr8 = *(int **)(key + 0xb0);
        if (loopPtr8[loopIndex2 * 6 + 0x26] != *(int *)(loopRemaining + 0x98)) {
          loopPtr7 = *(int **)(*(int *)(key + 0x238) + 0x30c);
          loopIndex3 = (**(code **)(*loopPtr7 + 0x11c))(loopPtr7,loopPtr8,loopIndex2,loopRemaining,0,uVar20);
          if (loopIndex3 == 0) goto code_r0x001816bc;
          changed = FUN_0017ae28(key,loopIndex2,loopRemaining,local_9c,uVar20,0,
                                *(undefined4 *)(key + 0x238));
          loopIndex3 = 0;
          *(undefined4 *)(iVar17 + 0x214) = changed;
          loopRemaining = key;
          do {
            operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
            if (*(char *)(loopIndex3 + operandRecord + 0x10) == '\x01') {
              *(undefined4 *)(loopRemaining + 0x30) = 0;
            }
            bVar3 = loopIndex3 != 3;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + 1;
          } while (bVar3);
          loopPtr8 = *(int **)(key + 0xb0);
          changed = 1;
        }
        goto code_r0x001816c0;
      }
      if (bVar3) {
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,uVar22,&local_98,&local_9c);
        if (loopRemaining != 0) goto code_r0x001815cc;
        loopIndex3 = 4;
        loopPtr6 = (char *)(loopIndex4 + key + 0x224);
        loopRemaining = 0;
        do {
          if (*loopPtr6 != '\0') {
            *(float *)(loopRemaining + (int)&local_98) = -*(float *)(loopRemaining + (int)&local_98);
          }
          loopPtr6 = loopPtr6 + 1;
          loopRemaining = loopRemaining + 4;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
code_r0x00181590:
        loopPtr8 = *(int **)(*(int *)(key + 0x238) + 0x30c);
        uVar20 = 1;
        loopRemaining = (**(code **)(*loopPtr8 + 0x154))(loopPtr8,uVar22,&local_98,&local_9c);
        if (loopRemaining != 0) goto code_r0x001815d0;
code_r0x001816bc:
        loopPtr8 = *(int **)(key + 0xb0);
        goto code_r0x001816c0;
      }
      loopPtr8 = *(int **)(key + 0xb0);
    }
    else {
      loopRemaining = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xbc))();
      if (loopRemaining != 0) {
        loopPtr8 = *(int **)(key + 0xb0);
        goto code_r0x001813e0;
      }
      loopPtr8 = *(int **)(key + 0xb0);
code_r0x001816c0:
      if (loopIndex != 0x7ffffffe) {
        if (*(int *)(loopPtr8[0x22] + 8) != 0x8e) {
          loopPtr6 = (char *)(loopIndex5 + 4);
          loopRemaining = 4;
          loopIndex = 0;
          do {
            if (*loopPtr6 != '\0') {
              loopRemaining = IRInst__getOperandRecord(loopPtr8,loopIndex2);
              loopPtr8 = *(int **)(key + 0xb0);
              uVar18 = (uint)*(byte *)(loopIndex + loopRemaining + 0x10);
              goto code_r0x00181700;
            }
            loopIndex = loopIndex + 1;
            loopPtr6 = loopPtr6 + 1;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
          uVar18 = 0;
code_r0x00181700:
          vector4 = *(uint **)(loopPtr8[loopIndex2 * 6 + 0x23] + 0x2c);
          vectorFilledCount4 = vector4[1];
          uVar23 = vectorFilledCount4 - 1;
          if (uVar23 < *vector4) {
            if (vectorFilledCount4 <= uVar23) {
              _memset(vectorFilledCount4 * 4 + vector4[2],0,(uVar23 - vectorFilledCount4) * 4 + 4);
              vector4[1] = vectorFilledCount4;
            }
            loopPtr8 = (int *)(uVar23 * 4 + vector4[2]);
          }
          else {
            loopPtr8 = (int *)Vector__elementRefGrow(vector4,uVar23);
          }
          loopPtr8 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),
                                        *(undefined4 *)(uVar18 * 4 + *loopPtr8 + 0x20));
          loopIndex = *loopPtr8;
        }
        loopPtr8 = (int *)Compiler__valueNumberForExpr(*(undefined4 *)(key + 0x238),loopIndex);
        if (*loopPtr8 == 0) {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 1U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,1,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
        else if (*loopPtr8 < 1) {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopIndex = *(int *)(key + 0xb0) + loopIndex2 * 0x18 + 0x80;
            IROperand__setModifierBits(loopIndex + 0xc,1,(*(uint *)(loopIndex + 0x20) ^ 1) & 1);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
        else {
          loopPtr8 = *(int **)(key + 0xb0);
          if ((loopPtr8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            changed = 1;
            IROperand__setModifierBits(loopPtr8 + loopIndex2 * 6 + 0x23,2,0);
            loopPtr8 = *(int **)(key + 0xb0);
          }
        }
      }
    }
    loopIndex2 = loopIndex2 + 1;
    loopIndex4 = loopIndex4 + 4;
    loopIndex5 = loopIndex5 + 4;
    iVar19 = iVar19 + 0x10;
    iVar17 = iVar17 + 4;
  } while( true );
}

/* FUN_00181928 @ 0x181928 (140 bytes) */
int FUN_00181928(param_1, param_2, program)
  int *param_1;
  int param_2;
  undefined4 program;
{
  int hasSingleUse;
  undefined4 uVar2;
  
  hasSingleUse = IRInst__hasSingleUse(param_1,program);
  if ((((hasSingleUse == 0) || (hasSingleUse = (**(code **)(*param_1 + 0x68))(param_1), hasSingleUse != 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((*(int *)(param_1[0x22] + 8) == 0x8e || (uVar2 = 1, param_1[0x56] != param_2)))) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001819b4 @ 0x1819b4 (252 bytes) */
int FUN_001819b4(inst, inst2)
  int *inst;
  int *inst2;
{
  int iVar1;
  int iVar2;
  
  if ((((inst[0x20] == 0) || (iVar1 = RegKind__flagBit0(inst[0x26]), iVar1 == 0)) ||
      ((inst[5] & 2U) != 0)) || (iVar1 = (**(code **)(*inst + 0x50))(inst), iVar1 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = IRInst__countWrittenComponents(inst);
  }
  if (((inst2[0x20] == 0) || (iVar2 = RegKind__flagBit0(inst2[0x26]), iVar2 == 0)) ||
     (((inst2[5] & 2U) != 0 || (iVar2 = (**(code **)(*inst2 + 0x50))(inst2), iVar2 != 0)))) {
    iVar2 = 0;
  }
  else {
    iVar2 = IRInst__countWrittenComponents(inst2);
  }
  return inst2[0x54] - iVar2 < inst[0x54] - iVar1;
}

/* FUN_00181ab0 @ 0x181ab0 (208 bytes) */
int FUN_00181ab0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int iVar2;
  undefined4 *allocation;
  int *elementRef;
  int loopIndex;
  int iVar6;
  uint vectorFilledCount;
  undefined4 arenaAt378;
  uint *vector;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
  if (iVar1 != 0) {
    loopIndex = 0;
    iVar6 = *(int *)(param_2 + 0x98);
    do {
      iVar2 = iVar1;
      if ((*(uint *)(iVar6 + 0x14) & 1) != 0) {
        *(int *)(iVar6 + 0x150) = loopIndex;
        arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
        allocation = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
        *allocation = arenaAt378;
        vector = (uint *)param_1[7];
        vectorFilledCount = vector[1];
        if (vectorFilledCount < *vector) {
          _memset(vectorFilledCount * 4 + vector[2],0,4);
          elementRef = (int *)(vectorFilledCount * 4 + vector[2]);
          vector[1] = vectorFilledCount + 1;
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
        }
        *elementRef = (int)(allocation + 1);
        loopIndex = loopIndex + 1;
        iVar2 = *(int *)(iVar6 + 8);
      }
      iVar1 = *(int *)(iVar2 + 8);
      iVar6 = iVar2;
    } while (*(int *)(iVar2 + 8) != 0);
  }
  return;
}

/* FUN_00181b80 @ 0x181b80 (896 bytes) */
int FUN_00181b80(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *elementRef2;
  int *elementRef;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint *vector4;
  uint *vector3;
  uint *vector2;
  int inst2;
  int sourceDef;
  int inst;
  int iVar2;
  uint vectorFilledCount;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  int loopIndex;
  uint *vector;
  
  inst = *(int *)(param_2 + 0x98);
  for (loopIndex = *(int *)(*(int *)(param_2 + 0x98) + 8); loopIndex != 0; loopIndex = *(int *)(loopIndex + 8))
  {
    if ((*(uint *)(inst + 0x14) & 1) != 0) {
      vector = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(inst + 0x150);
      if (uVar9 < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= uVar9) {
          _memset(vectorFilledCount * 4 + vector[2],0,(uVar9 - vectorFilledCount) * 4 + 4);
          vector[1] = uVar9 + 1;
        }
        puVar4 = (undefined4 *)(uVar9 * 4 + vector[2]);
      }
      else {
        puVar4 = (undefined4 *)Vector__elementRefGrow(vector,uVar9);
      }
      puVar4 = (undefined4 *)*puVar4;
      *puVar4 = 1;
      puVar4[1] = 1;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 1;
      if ((*(int *)(*(int *)(inst + 0x88) + 8) != 0x8e) && (0 < *(int *)(inst + 0x84))) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst,loopIndex);
          if (param_2 == *(int *)(sourceDef + 0x158)) {
            vector2 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(sourceDef + 0x150);
            if (uVar9 < *vector2) {
              vectorFilledCount2 = vector2[1];
              if (vectorFilledCount2 <= uVar9) {
                _memset(vectorFilledCount2 * 4 + vector2[2],0,(uVar9 - vectorFilledCount2) * 4 + 4);
                vector2[1] = uVar9 + 1;
              }
              elementRef = (int *)(uVar9 * 4 + vector2[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector2,uVar9);
            }
            iVar2 = *(int *)(*elementRef + 4) + 1;
            iVar5 = puVar4[1];
            if ((int)puVar4[1] < iVar2) {
              iVar5 = iVar2;
            }
            puVar4[1] = iVar5;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(inst + 0x84));
      }
      loopIndex = *(int *)(inst + 8);
    }
    inst = loopIndex;
  }
  *param_3 = 0;
  SchedModel__resetCounters(*(undefined4 *)(param_1 + 8));
  inst2 = *(int *)(param_2 + 0xa0);
  for (loopIndex = *(int *)(*(int *)(param_2 + 0xa0) + 4); loopIndex != 0; loopIndex = *(int *)(loopIndex + 4))
  {
    if (((*(uint *)(inst2 + 0x14) & 1) != 0) && (*(int *)(*(int *)(inst2 + 0x88) + 8) != 0x8e)) {
      vector3 = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(inst2 + 0x150);
      if (uVar9 < *vector3) {
        vectorFilledCount3 = vector3[1];
        if (vectorFilledCount3 <= uVar9) {
          _memset(vectorFilledCount3 * 4 + vector3[2],0,(uVar9 - vectorFilledCount3) * 4 + 4);
          vector3[1] = uVar9 + 1;
        }
        elementRef2 = (undefined4 *)(uVar9 * 4 + vector3[2]);
      }
      else {
        elementRef2 = (undefined4 *)Vector__elementRefGrow(vector3,uVar9);
      }
      piVar6 = (int *)*elementRef2;
      FUN_00172204(*(undefined4 *)(param_1 + 8),inst2);
      if (0 < *(int *)(inst2 + 0x84)) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst2,loopIndex);
          if (param_2 == *(int *)(sourceDef + 0x158)) {
            vector4 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(sourceDef + 0x150);
            if (uVar9 < *vector4) {
              vectorFilledCount4 = vector4[1];
              if (vectorFilledCount4 <= uVar9) {
                _memset(vectorFilledCount4 * 4 + vector4[2],0,(uVar9 - vectorFilledCount4) * 4 + 4);
                vector4[1] = uVar9 + 1;
              }
              elementRef2 = (undefined4 *)(uVar9 * 4 + vector4[2]);
            }
            else {
              elementRef2 = (undefined4 *)Vector__elementRefGrow(vector4,uVar9);
            }
            piVar7 = (int *)*elementRef2;
            iVar5 = *piVar7;
            if (*piVar7 < *piVar6 + 1) {
              iVar5 = *piVar6 + 1;
            }
            piVar7[4] = loopIndex;
            *piVar7 = iVar5;
            piVar7[3] = inst2;
            if (iVar5 < *param_3) {
              iVar5 = *param_3;
            }
            *param_3 = iVar5;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(inst2 + 0x84));
      }
      loopIndex = *(int *)(inst2 + 4);
    }
    inst2 = loopIndex;
  }
  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 0x5c))(*(int **)(param_1 + 8));
  *param_4 = uVar8;
  return;
}

/* FUN_00181f00 @ 0x181f00 (220 bytes) */
int FUN_00181f00(compiler, block, inst)
  int *compiler;
  int block;
  int inst;
{
  int lookaheadNode2;
  int nextNode;
  int scaleRemaining;
  int rightNode;
  int firstJoinInst;
  int indexPlusOne;
  int sourceInst;
  undefined4 savedSelectWord;
  undefined4 selectConstC;
  undefined4 selectConstB;
  uint entryIndex;
  uint instSlotIndex;
  uint operandFlags;
  uint worklistSize;
  int lookaheadNode3;
  int moveNode;
  int instOpcode;
  int entryInst;
  int scaleHiLoop;
  int scaleHiTail;
  int scaleLoTail;
  int otherOperand;
  int joinInst;
  int listedInst;
  int operandRecord6;
  int scaleHiPair;
  int scaleLoPair;
  int compilerPtr;
  int prevByteOffset;
  int operandRecord7;
  int useOperandIndex;
  int lookaheadNode;
  int elementByteOffset2;
  int operandRecord5;
  int leftNode;
  int elementByteOffset;
  uint vectorCapacity2;
  uint vectorCapacity;
  undefined4 *allocation2;
  int *elementRef3;
  int isSplat;
  uint source1Flags;
  uint vectorSize6;
  uint vectorSize5;
  uint vectorSize4;
  uint vectorSize3;
  uint vectorFilledCount5;
  uint vectorFilledCount4;
  uint vectorFilledCount3;
  uint vectorSize2;
  uint vectorFilledCount2;
  uint vectorFilledCount;
  int vectorSize1;
  uint vectorSize;
  uint vectorSizeB;
  uint vectorSizeC;
  undefined4 *elementRefB;
  int *elementRef;
  undefined4 inst8;
  undefined4 inst7;
  undefined4 inst6;
  undefined4 inst5;
  undefined4 inst4;
  undefined4 inst3;
  uint negateFlag;
  uint *vector8;
  uint *vector7;
  uint *vector6;
  uint *vector5;
  int *inst2;
  int operandRecord4;
  int inst1;
  int operandRecord1;
  int compilerCtx;
  undefined4 allocation;
  undefined4 sourceDef;
  int newInst2;
  int operandRecord;
  int operandRecord2;
  int operandRecord3;
  int newInst;
  undefined4 arenaAt378;
  bool moreOperands;
  uint pairLoopIndex;
  int operandByteOffset;
  int modifierLoopIndex;
  undefined4 *vectorAlloc3;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc2;
  int *lastElementRef;
  uint lane2Select;
  int entryOrdinal;
  undefined4 *elementRef4;
  int *elementRef2;
  int operandPtr;
  uint prevIndex;
  int currentInst;
  uint *vector;
  uint *vector2;
  uint *vector3;
  int operandSlot;
  int scaleLoLoop;
  undefined4 selectConstA;
  uint lastIndex;
  uint *vector4;
  uint *operandFlagsPtr;
  int operandIndex;
  uint lane1Select;
  undefined1 chainList [8];
  int listNode;
  uint laneSelect3;
  uint laneSelect2;
  uint laneSelect1;
  undefined4 opcode;
  
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[4] = arenaAt378;
  vectorAlloc3[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc3[3] = allocation;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector3 = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc2 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector2 = vectorAlloc2 + 1;
  *vectorAlloc2 = arenaAt378;
  vectorAlloc2[1] = 2;
  vectorAlloc2[2] = 0;
  vectorAlloc2[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorSize2 = vectorAlloc3[2];
  worklistSize = *vector;
  vectorAlloc2[3] = allocation;
  if (vectorSize2 < worklistSize) {
    _memset((void *)(vectorSize2 * 4 + vectorAlloc3[3]),0,4);
    elementRef3 = (int *)(vectorSize2 * 4 + vectorAlloc3[3]);
    vectorAlloc3[2] = vectorSize2 + 1;
  }
  else {
    elementRef3 = (int *)Vector__elementRefGrow(vector,vectorSize2);
  }
  *elementRef3 = inst;
  while (worklistSize = vectorAlloc3[2], worklistSize != 0) {
    lastElementRef = (int *)0x0;
    if (worklistSize - 1 < worklistSize) {
      lastElementRef = (int *)((worklistSize - 1) * 4 + vectorAlloc3[3]);
    }
    currentInst = *lastElementRef;
    operandSlot = 1;
    Vector__removeAt(vector,worklistSize - 1);
    operandFlagsPtr = (uint *)(currentInst + 0xb8);
    operandByteOffset = 0x18;
    do {
      sourceInst = IRInst__getOperandSource(currentInst,operandSlot);
      if (block == *(int *)(sourceInst + 0x158)) {
        vector4 = (uint *)compiler[7];
        worklistSize = *(uint *)(sourceInst + 0x150);
        if (worklistSize < *vector4) {
          vectorFilledCount3 = vector4[1];
          if (vectorFilledCount3 <= worklistSize) {
            _memset((void *)(vectorFilledCount3 * 4 + vector4[2]),0,(worklistSize - vectorFilledCount3) * 4 + 4);
            vector4[1] = worklistSize + 1;
          }
          elementRef3 = (int *)(worklistSize * 4 + vector4[2]);
        }
        else {
          elementRef3 = (int *)Vector__elementRefGrow(vector4,worklistSize);
        }
        if (*(int *)(*elementRef3 + 0x14) == 0) {
          if (((*operandFlagsPtr & 2) != 0) && (*(int *)(*(int *)(sourceInst + 0x88) + 8) == 0x13)) {
            modifierLoopIndex = 1;
            operandPtr = sourceInst + 0x98;
            do {
              IROperand__setModifierBits(operandPtr + 0xc,2,1);
              if ((*(uint *)(operandPtr + 0x20) & 1) != 0) {
                IROperand__setModifierBits(operandPtr + 0xc,1,0);
              }
              moreOperands = modifierLoopIndex != 2;
              operandPtr = operandPtr + 0x18;
              modifierLoopIndex = modifierLoopIndex + 1;
            } while (moreOperands);
            IROperand__setModifierBits(operandByteOffset + currentInst + 0x8c,2,0);
          }
          operandFlags = *(uint *)(operandByteOffset + currentInst + 0xa0);
          if ((((operandFlags & 1) != 0) && ((operandFlags & 2) == 0)) &&
             (*(int *)(*(int *)(sourceInst + 0x88) + 8) == 0x12)) {
            modifierLoopIndex = 1;
            operandPtr = sourceInst + 0x98;
            do {
              IROperand__setModifierBits(operandPtr + 0xc,1,*(uint *)(operandPtr + 0x20) & 1 ^ 1);
              moreOperands = modifierLoopIndex != 2;
              operandPtr = operandPtr + 0x18;
              modifierLoopIndex = modifierLoopIndex + 1;
            } while (moreOperands);
            IROperand__setModifierBits(operandByteOffset + currentInst + 0x8c,1,0);
          }
          worklistSize = vectorAlloc3[2];
          if (worklistSize < *vector) {
            _memset((void *)(worklistSize * 4 + vectorAlloc3[3]),0,4);
            elementRef3 = (int *)(worklistSize * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = worklistSize + 1;
          }
          else {
            elementRef3 = (int *)Vector__elementRefGrow(vector,worklistSize);
          }
          *elementRef3 = sourceInst;
        }
      }
      moreOperands = operandSlot != 2;
      operandByteOffset = operandByteOffset + 0x18;
      operandFlagsPtr = operandFlagsPtr + 6;
      operandSlot = operandSlot + 1;
    } while (moreOperands);
    operandRecord = IRInst__getOperandRecord(currentInst,1);
    isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    if (isSplat != 0) {
      operandRecord = IRInst__getOperandRecord(currentInst,2);
      SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    }
    operandRecord = IRInst__getOperandRecord(currentInst,1);
    isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
    if (isSplat == 0) {
      operandRecord = IRInst__getOperandRecord(currentInst,2);
      isSplat = SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
      if (isSplat != 0) {
        vectorSize = vectorAlloc[2];
        if (vectorSize < *vector3) {
          _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
          elementRef3 = (int *)(vectorSize * 4 + vectorAlloc[3]);
          vectorAlloc[2] = vectorSize + 1;
        }
        else {
          elementRef3 = (int *)Vector__elementRefGrow(vector3,vectorSize);
        }
        *elementRef3 = currentInst;
        worklistSize = vectorAlloc2[2];
        if (worklistSize < *vector2) {
          _memset((void *)(worklistSize * 4 + vectorAlloc2[3]),0,4);
          elementRef4 = (undefined4 *)(worklistSize * 4 + vectorAlloc2[3]);
          vectorAlloc2[2] = worklistSize + 1;
        }
        else {
          elementRef4 = (undefined4 *)Vector__elementRefGrow(vector2,worklistSize);
        }
        *elementRef4 = 2;
      }
    }
    else {
      vectorSize = vectorAlloc[2];
      if (vectorSize < *vector3) {
        _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
        elementRef3 = (int *)(vectorSize * 4 + vectorAlloc[3]);
        vectorAlloc[2] = vectorSize + 1;
      }
      else {
        elementRef3 = (int *)Vector__elementRefGrow(vector3,vectorSize);
      }
      *elementRef3 = currentInst;
      worklistSize = vectorAlloc2[2];
      if (worklistSize < *vector2) {
        _memset((void *)(worklistSize * 4 + vectorAlloc2[3]),0,4);
        elementRef4 = (undefined4 *)(worklistSize * 4 + vectorAlloc2[3]);
        vectorAlloc2[2] = worklistSize + 1;
      }
      else {
        elementRef4 = (undefined4 *)Vector__elementRefGrow(vector2,worklistSize);
      }
      *elementRef4 = 1;
    }
  }
  instOpcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if ((instOpcode == 0x13) || (instOpcode == 0x14)) {
    opcode = 0x13;
  }
  else {
    opcode = 0x12;
    if (instOpcode != 0x12) {
      opcode = 0;
    }
  }
  DListNode__init(chainList);
  vectorSize1 = vectorAlloc[2];
  lastIndex = vectorSize1 - 1;
  pairLoopIndex = lastIndex;
  if ((int)lastIndex < 1) {
    scaleRemaining = 0;
  }
  else {
    elementByteOffset = lastIndex * 4;
    prevByteOffset = elementByteOffset + -4;
    scaleRemaining = 0;
    indexPlusOne = vectorSize1;
    do {
      newInst = IRInst__create(opcode,*compiler);
      selectConstA = DAT_001b0210;
      *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
      prevIndex = pairLoopIndex - 1;
      *(undefined4 *)(newInst + 0x98) = 0;
      *(undefined4 *)(newInst + 0x9c) = selectConstA;
      vectorCapacity2 = *vector3;
      if (prevIndex < vectorCapacity2) {
        vectorSize3 = vectorAlloc[2];
        if (vectorSize3 <= prevIndex) {
          _memset((void *)(vectorSize3 * 4 + vectorAlloc[3]),0,(prevIndex - vectorSize3) * 4 + 4);
          vectorCapacity2 = *vector3;
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
        vectorCapacity2 = *vector3;
      }
      if (inst != *elementRef) {
        if (prevIndex < vectorCapacity2) {
          vectorSize4 = vectorAlloc[2];
          if (vectorSize4 <= prevIndex) {
            _memset((void *)(vectorSize4 * 4 + vectorAlloc[3]),0,(prevIndex - vectorSize4) * 4 + 4);
            vectorCapacity2 = *vector3;
            vectorAlloc[2] = pairLoopIndex;
          }
          elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
          vectorCapacity2 = *vector3;
        }
        scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
      }
      if (pairLoopIndex < vectorCapacity2) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      if (inst != *elementRef) {
        if (pairLoopIndex < *vector3) {
          vectorSizeB = vectorAlloc[2];
          if (vectorSizeB <= pairLoopIndex) {
            _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
            vectorAlloc[2] = indexPlusOne;
          }
          elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
        }
        scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
      }
      if (scaleRemaining != 0) {
        scaleLoLoop = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        if (scaleRemaining < scaleLoLoop) {
          *(int *)(newInst + 0x124) = scaleLoLoop;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        }
        else {
          scaleHiLoop = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          if (scaleHiLoop < scaleRemaining) {
            *(int *)(newInst + 0x124) = scaleHiLoop;
            scaleRemaining = scaleRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          }
          else {
            *(int *)(newInst + 0x124) = scaleRemaining;
            scaleRemaining = 0;
          }
        }
      }
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,prevIndex);
      }
      inst3 = *elementRefB;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,prevIndex);
      }
      sourceDef = IRInst__getOperandSource(inst3,*elementRefB);
      IRInst__setOperandSource(newInst,1,sourceDef,0,*compiler);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      inst4 = *elementRefB;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      sourceDef = IRInst__getOperandSource(inst4,*elementRefB);
      IRInst__setOperandSource(newInst,2,sourceDef,0,*compiler);
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,prevIndex);
      }
      inst5 = *elementRefB;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRefB = (undefined4 *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,prevIndex);
      }
      operandRecord2 = IRInst__getOperandRecord(inst5,*elementRefB);
      FUN_000f33f8(&laneSelect3,*(undefined4 *)(operandRecord2 + 0x10));
      lane1Select = laneSelect3 & 0xff;
      if (pairLoopIndex < *vector3) {
        vectorSize5 = vectorAlloc[2];
        if (vectorSize5 <= pairLoopIndex) {
          _memset((void *)(vectorSize5 * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSize5) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      inst6 = *elementRefB;
      if (pairLoopIndex < *vector2) {
        vectorSize6 = vectorAlloc2[2];
        if (vectorSize6 <= pairLoopIndex) {
          _memset((void *)(vectorSize6 * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSize6) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRefB = (undefined4 *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      operandRecord2 = IRInst__getOperandRecord(inst6,*elementRefB);
      FUN_000f33f8(&laneSelect2,*(undefined4 *)(operandRecord2 + 0x10));
      lane2Select = laneSelect2 & 0xff;
      operandRecord2 = IRInst__getOperandRecord(newInst,1);
      *(uint *)(operandRecord2 + 0x10) = lane1Select | 0x4040400;
      operandRecord2 = IRInst__getOperandRecord(newInst,2);
      *(uint *)(operandRecord2 + 0x10) = lane2Select | 0x4040400;
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
      }
      entryInst = *elementRef;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,prevIndex);
      }
      IROperand__setModifierBits(newInst + 0xa4,1,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) & 1);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      entryInst = *elementRef;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      IROperand__setModifierBits(newInst + 0xbc,1,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) & 1);
      if (prevIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,prevIndex);
      }
      entryInst = *elementRef;
      if (prevIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= prevIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(prevIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = pairLoopIndex;
        }
        elementRef = (int *)(prevByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,prevIndex);
      }
      IROperand__setModifierBits(newInst + 0xa4,2,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) >> 1 & 1);
      if (pairLoopIndex < *vector3) {
        vectorSizeB = vectorAlloc[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,pairLoopIndex);
      }
      entryInst = *elementRef;
      if (pairLoopIndex < *vector2) {
        vectorSizeB = vectorAlloc2[2];
        if (vectorSizeB <= pairLoopIndex) {
          _memset((void *)(vectorSizeB * 4 + vectorAlloc2[3]),0,(pairLoopIndex - vectorSizeB) * 4 + 4);
          vectorAlloc2[2] = indexPlusOne;
        }
        elementRef = (int *)(elementByteOffset + vectorAlloc2[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector2,pairLoopIndex);
      }
      IROperand__setModifierBits(newInst + 0xbc,2,*(uint *)(*elementRef * 0x18 + entryInst + 0xa0) >> 1 & 1);
      *(undefined4 *)(newInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
      arenaAt378 = *(undefined4 *)(*compiler + 0x378);
      allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
      *allocation2 = arenaAt378;
      vector5 = (uint *)compiler[7];
      vectorFilledCount4 = vector5[1];
      if (vectorFilledCount4 < *vector5) {
        _memset((void *)(vectorFilledCount4 * 4 + vector5[2]),0,4);
        elementRef3 = (int *)(vectorFilledCount4 * 4 + vector5[2]);
        vector5[1] = vectorFilledCount4 + 1;
      }
      else {
        elementRef3 = (int *)Vector__elementRefGrow(vector5,vectorFilledCount4);
      }
      *elementRef3 = (int)(allocation2 + 1);
      DList__pushBack(chainList,newInst);
      pairLoopIndex = pairLoopIndex - 2;
      elementByteOffset = elementByteOffset + -8;
      prevByteOffset = prevByteOffset + -8;
      indexPlusOne = indexPlusOne + -2;
    } while (0 < (int)pairLoopIndex);
  }
  leftNode = listNode;
  if (pairLoopIndex == 0) {
    firstJoinInst = IRInst__create(opcode,*compiler);
    selectConstA = DAT_001b0210;
    *(undefined4 *)(firstJoinInst + 0x98) = 0;
    *(undefined4 *)(firstJoinInst + 0x94) = *(undefined4 *)(firstJoinInst + 0x14c);
    *(undefined4 *)(firstJoinInst + 0x9c) = selectConstA;
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    if (inst != *elementRef) {
      if (*vector3 == 0) {
        elementRef = (int *)Vector__elementRefGrow(vector3,0);
      }
      else {
        if (vectorAlloc[2] == 0) {
          *(undefined4 *)vectorAlloc[3] = 0;
          vectorAlloc[2] = 1;
        }
        elementRef = (int *)vectorAlloc[3];
      }
      scaleRemaining = scaleRemaining + *(int *)(*elementRef + 0x124);
    }
    if (scaleRemaining == 0) {
      compilerPtr = *compiler;
      scaleRemaining = 0;
    }
    else {
      scaleLoPair = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (scaleRemaining < scaleLoPair) {
        *(int *)(firstJoinInst + 0x124) = scaleLoPair;
        compilerPtr = *compiler;
        scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerPtr + 0x30c) + 0x58);
      }
      else {
        scaleHiPair = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (scaleHiPair < scaleRemaining) {
          *(int *)(firstJoinInst + 0x124) = scaleHiPair;
          compilerPtr = *compiler;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerPtr + 0x30c) + 0x5c);
        }
        else {
          *(int *)(firstJoinInst + 0x124) = scaleRemaining;
          scaleRemaining = 0;
          compilerPtr = *compiler;
        }
      }
    }
    IRInst__setOperandSource(firstJoinInst,1,leftNode,0,compilerPtr);
    selectConstB = UNK_001b020c;
    operandRecord6 = IRInst__getOperandRecord(firstJoinInst,1);
    *(undefined4 *)(operandRecord6 + 0x10) = selectConstB;
    if (*vector3 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc[3];
    }
    inst7 = *elementRefB;
    if (*vector2 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc2[3];
    }
    sourceDef = IRInst__getOperandSource(inst7,*elementRefB);
    IRInst__setOperandSource(firstJoinInst,2,sourceDef,0,*compiler);
    if (*vector3 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc[3];
    }
    inst8 = *elementRefB;
    if (*vector2 == 0) {
      elementRefB = (undefined4 *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRefB = (undefined4 *)vectorAlloc2[3];
    }
    operandRecord6 = IRInst__getOperandRecord(inst8,*elementRefB);
    FUN_000f33f8(&laneSelect1,*(undefined4 *)(operandRecord6 + 0x10));
    operandRecord6 = IRInst__getOperandRecord(firstJoinInst,2);
    *(uint *)(operandRecord6 + 0x10) = laneSelect1 & 0xff | 0x4040400;
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    listedInst = *elementRef;
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(firstJoinInst + 0xbc,1,*(uint *)(*elementRef * 0x18 + listedInst + 0xa0) & 1);
    if (*vector3 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector3,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      elementRef = (int *)vectorAlloc[3];
    }
    listedInst = *elementRef;
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(firstJoinInst + 0xbc,2,*(uint *)(*elementRef * 0x18 + listedInst + 0xa0) >> 1 & 1);
    DList__pushBack(chainList,firstJoinInst);
    *(undefined4 *)(firstJoinInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *allocation2 = arenaAt378;
    vector6 = (uint *)compiler[7];
    vectorFilledCount = vector6[1];
    if (vectorFilledCount < *vector6) {
      _memset((void *)(vectorFilledCount * 4 + vector6[2]),0,4);
      elementRef3 = (int *)(vectorFilledCount * 4 + vector6[2]);
      vector6[1] = vectorFilledCount + 1;
    }
    else {
      elementRef3 = (int *)Vector__elementRefGrow(vector6,vectorFilledCount);
    }
    *elementRef3 = (int)(allocation2 + 1);
    leftNode = *(int *)(leftNode + 8);
  }
  while (rightNode = *(int *)(leftNode + 8), *(int *)(rightNode + 8) != 0) {
    joinInst = IRInst__create(opcode,*compiler);
    selectConstA = DAT_001b0210;
    *(undefined4 *)(joinInst + 0x98) = 0;
    *(undefined4 *)(joinInst + 0x94) = *(undefined4 *)(joinInst + 0x14c);
    *(undefined4 *)(joinInst + 0x9c) = selectConstA;
    if (scaleRemaining == 0) {
      compilerCtx = *compiler;
    }
    else {
      scaleLoTail = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (scaleRemaining < scaleLoTail) {
        *(int *)(joinInst + 0x124) = scaleLoTail;
        compilerCtx = *compiler;
        scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerCtx + 0x30c) + 0x58);
      }
      else {
        scaleHiTail = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (scaleHiTail < scaleRemaining) {
          *(int *)(joinInst + 0x124) = scaleHiTail;
          compilerCtx = *compiler;
          scaleRemaining = scaleRemaining - *(int *)(*(int *)(compilerCtx + 0x30c) + 0x5c);
        }
        else {
          *(int *)(joinInst + 0x124) = scaleRemaining;
          scaleRemaining = 0;
          compilerCtx = *compiler;
        }
      }
    }
    IRInst__setOperandSource(joinInst,1,leftNode,0,compilerCtx);
    IRInst__setOperandSource(joinInst,2,rightNode,0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord5 = IRInst__getOperandRecord(joinInst,1);
    *(undefined4 *)(operandRecord5 + 0x10) = selectConstB;
    operandRecord5 = IRInst__getOperandRecord(joinInst,2);
    *(undefined4 *)(operandRecord5 + 0x10) = selectConstB;
    DList__pushBack(chainList,joinInst);
    *(undefined4 *)(joinInst + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    allocation2 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *allocation2 = arenaAt378;
    vector7 = (uint *)compiler[7];
    vectorFilledCount2 = vector7[1];
    if (vectorFilledCount2 < *vector7) {
      _memset((void *)(vectorFilledCount2 * 4 + vector7[2]),0,4);
      elementRef3 = (int *)(vectorFilledCount2 * 4 + vector7[2]);
      vector7[1] = vectorFilledCount2 + 1;
    }
    else {
      elementRef3 = (int *)Vector__elementRefGrow(vector7,vectorFilledCount2);
    }
    *elementRef3 = (int)(allocation2 + 1);
    leftNode = *(int *)(rightNode + 8);
  }
  if (-1 < (int)lastIndex) {
    elementByteOffset2 = lastIndex * 4;
    entryOrdinal = 0;
    scaleRemaining = vectorSize1;
    do {
      vectorCapacity = *vector3;
      entryIndex = lastIndex - entryOrdinal;
      if (entryIndex < vectorCapacity) {
        vectorSizeC = vectorAlloc[2];
        if (vectorSizeC <= entryIndex) {
          _memset((void *)(vectorSizeC * 4 + vectorAlloc[3]),0,(entryIndex - vectorSizeC) * 4 + 4);
          vectorCapacity = *vector3;
          vectorAlloc[2] = scaleRemaining;
        }
        elementRef = (int *)(elementByteOffset2 + vectorAlloc[3]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector3,entryIndex);
        vectorCapacity = *vector3;
      }
      if (inst == *elementRef) goto code_r0x001836f0;
      if (entryIndex < vectorCapacity) {
        vectorSize = vectorAlloc[2];
        if (vectorSize <= entryIndex) {
          _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,(entryIndex - vectorSize) * 4 + 4);
          vectorAlloc[2] = scaleRemaining;
        }
        elementRefB = (undefined4 *)(elementByteOffset2 + vectorAlloc[3]);
      }
      else {
        elementRefB = (undefined4 *)Vector__elementRefGrow(vector3,entryIndex);
      }
      inst2 = (int *)*elementRefB;
      if (entryIndex < *vector2) {
        vectorSize = vectorAlloc2[2];
        if (vectorSize <= entryIndex) {
          _memset((void *)(vectorSize * 4 + vectorAlloc2[3]),0,(entryIndex - vectorSize) * 4 + 4);
          vectorAlloc2[2] = scaleRemaining;
        }
        elementRef2 = (int *)(elementByteOffset2 + vectorAlloc2[3]);
      }
      else {
        elementRef2 = (int *)Vector__elementRefGrow(vector2,entryIndex);
      }
      otherOperand = (*elementRef2 == 1) + 1;
      IRInst__hasSingleUse(inst2,compiler[1]);
      vector8 = (uint *)compiler[7];
      instSlotIndex = inst2[0x54];
      if (instSlotIndex < *vector8) {
        vectorFilledCount5 = vector8[1];
        if (vectorFilledCount5 <= instSlotIndex) {
          _memset((void *)(vectorFilledCount5 * 4 + vector8[2]),0,(instSlotIndex - vectorFilledCount5) * 4 + 4);
          vector8[1] = instSlotIndex + 1;
        }
        elementRef2 = (int *)(instSlotIndex * 4 + vector8[2]);
      }
      else {
        elementRef2 = (int *)Vector__elementRefGrow(vector8,instSlotIndex);
      }
      operandIndex = *(int *)(*elementRef2 + 0x10);
      inst1 = *(int *)(*elementRef2 + 0xc);
      sourceDef = IRInst__getOperandSource(inst2,otherOperand);
      IRInst__setOperandSource(inst1,operandIndex,sourceDef,0,*compiler);
      operandRecord3 = IRInst__getOperandRecord(inst2,otherOperand);
      savedSelectWord = *(undefined4 *)(operandRecord3 + 0x10);
      operandRecord3 = IRInst__getOperandRecord(inst1,operandIndex);
      *(undefined4 *)(operandRecord3 + 0x10) = savedSelectWord;
      if ((*(uint *)(operandIndex * 0x18 + inst1 + 0xa0) & 1) == 0) {
        negateFlag = inst2[otherOperand * 6 + 0x28] & 1;
      }
      else {
        negateFlag = inst2[otherOperand * 6 + 0x28] & 1U ^ 1;
      }
      operandRecord1 = operandIndex * 0x18 + inst1 + 0x8c;
      IROperand__setModifierBits(operandRecord1,1,negateFlag);
      IROperand__setModifierBits(operandRecord1,2,(uint)inst2[otherOperand * 6 + 0x28] >> 1 & 1);
      (**(code **)(*inst2 + 0xc))(inst2,0,*compiler);
      entryOrdinal = entryOrdinal + 1;
      elementByteOffset2 = elementByteOffset2 + -4;
      scaleRemaining = scaleRemaining + -1;
    } while (entryOrdinal != vectorSize1);
  }
  vectorCapacity = *vector3;
code_r0x001836f0:
  if (vectorCapacity == 0) {
    elementRef = (int *)Vector__elementRefGrow(vector3,0);
  }
  else {
    if (vectorAlloc[2] == 0) {
      *(undefined4 *)vectorAlloc[3] = 0;
      vectorAlloc[2] = 1;
    }
    elementRef = (int *)vectorAlloc[3];
  }
  if (inst == *elementRef) {
    lookaheadNode = *(int *)(listNode + 8);
    moveNode = listNode;
    while (nextNode = lookaheadNode, nextNode != 0) {
      DList__unlink(moveNode);
      Block__insertInstBefore(block,inst,moveNode);
      moveNode = nextNode;
      lookaheadNode = *(int *)(nextNode + 8);
    }
    if (*vector2 == 0) {
      elementRef = (int *)Vector__elementRefGrow(vector2,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      elementRef = (int *)vectorAlloc2[3];
    }
    useOperandIndex = *elementRef;
    IRInst__setOperandSource(inst,useOperandIndex,*(undefined4 *)(inst + 4),0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord = IRInst__getOperandRecord(inst,useOperandIndex);
    *(undefined4 *)(operandRecord + 0x10) = selectConstB;
    operandRecord4 = useOperandIndex * 0x18 + inst + 0x8c;
    IROperand__setModifierBits(operandRecord4,1,0);
    IROperand__setModifierBits(operandRecord4,2,0);
  }
  else {
    newInst2 = IRInst__create(opcode,*compiler);
    *(undefined4 *)(newInst2 + 0x98) = 0;
    *(undefined4 *)(newInst2 + 0x94) = *(undefined4 *)(newInst2 + 0x14c);
    operandRecord7 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(newInst2 + 0x9c) = *(undefined4 *)(operandRecord7 + 0x10);
    sourceDef = IRInst__getOperandSource(inst,1);
    IRInst__setOperandSource(newInst2,1,sourceDef,0,*compiler);
    sourceDef = IRInst__getOperandSource(inst,2);
    IRInst__setOperandSource(newInst2,2,sourceDef,0,*compiler);
    operandRecord7 = IRInst__getOperandRecord(inst,1);
    savedSelectWord = *(undefined4 *)(operandRecord7 + 0x10);
    operandRecord7 = IRInst__getOperandRecord(newInst2,1);
    *(undefined4 *)(operandRecord7 + 0x10) = savedSelectWord;
    operandRecord7 = IRInst__getOperandRecord(inst,2);
    savedSelectWord = *(undefined4 *)(operandRecord7 + 0x10);
    operandRecord7 = IRInst__getOperandRecord(newInst2,2);
    source1Flags = *(uint *)(inst + 0xb8);
    *(undefined4 *)(operandRecord7 + 0x10) = savedSelectWord;
    IROperand__setModifierBits(newInst2 + 0xa4,1,source1Flags & 1);
    IROperand__setModifierBits(newInst2 + 0xbc,1,*(uint *)(inst + 0xd0) & 1);
    IROperand__setModifierBits(newInst2 + 0xa4,2,*(uint *)(inst + 0xb8) >> 1 & 1);
    IROperand__setModifierBits(newInst2 + 0xbc,2,*(uint *)(inst + 0xd0) >> 1 & 1);
    Block__insertInstBefore(block,inst,newInst2);
    IRInst__setOperandSource(inst,1,newInst2,0,*compiler);
    selectConstC = UNK_001b0208;
    operandRecord = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord + 0x10) = selectConstC;
    IROperand__setModifierBits(inst + 0xa4,1,0);
    IROperand__setModifierBits(inst + 0xa4,2,0);
    lookaheadNode3 = *(int *)(listNode + 8);
    while (lookaheadNode2 = lookaheadNode3, lookaheadNode2 != 0) {
      DList__unlink(listNode);
      Block__insertInstBefore(block,inst,listNode);
      listNode = lookaheadNode2;
      lookaheadNode3 = *(int *)(lookaheadNode2 + 8);
    }
    IRInst__setOperandSource(inst,2,*(undefined4 *)(inst + 4),0,*compiler);
    selectConstB = UNK_001b020c;
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = selectConstB;
    IROperand__setModifierBits(inst + 0xbc,1,0);
    IROperand__setModifierBits(inst + 0xbc,2,0);
    IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
  }
  if (vector2 != (uint *)0x0) {
    Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
    Arena__free(*vectorAlloc2,vectorAlloc2);
  }
  if (vector3 != (uint *)0x0) {
    Arena__free(vectorAlloc[4],vectorAlloc[3]);
    Arena__free(*vectorAlloc,vectorAlloc);
  }
  if (vector != (uint *)0x0) {
    Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
    Arena__free(*vectorAlloc3,vectorAlloc3);
  }
  return 1;
}

/* FUN_00183ac8 @ 0x183ac8 (212 bytes) */
int FUN_00183ac8(param_1)
  int param_1;
{
  uint vectorFilledCount;
  int *elementRef;
  int iVar3;
  uint vectorFilledCount2;
  uint loopIndex;
  uint *vector;
  
  loopIndex = 0;
  vector = *(uint **)(param_1 + 0x1c);
  vectorFilledCount2 = vector[1];
  if (0 < (int)vectorFilledCount2) {
    while( true ) {
      if (loopIndex < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= loopIndex) {
          _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        elementRef = (int *)(loopIndex * 4 + vector[2]);
      }
      else {
        elementRef = (int *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar3 = *elementRef;
      if (iVar3 != 0) {
        Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (vectorFilledCount2 == loopIndex) break;
      vector = *(uint **)(param_1 + 0x1c);
    }
    vector = *(uint **)(param_1 + 0x1c);
  }
  vector[1] = 0;
  return;
}

/* FUN_00183b9c @ 0x183b9c (1152 bytes) */
int FUN_00183b9c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  uint vectorFilledCount3;
  uint vectorFilledCount2;
  uint *vector3;
  uint *vector2;
  int sourceDef2;
  int sourceDef;
  int iVar1;
  uint vectorFilledCount;
  int *elementRef;
  int iVar4;
  int callResult;
  int iVar6;
  int inst;
  uint uVar8;
  uint *vector;
  int local_48;
  int local_44 [8];
  
  ((int (*)())FUN_00181ab0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
LAB_00183bcc:
  ((int (*)())FUN_00181b80)(param_1,param_2,&local_48,local_44,param_5,param_6,param_7);
  if ((local_48 < local_44[0]) &&
     (iVar1 = *(int *)(param_1 + 8),
     *(int *)(iVar1 + 0x14) < *(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10))) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
    inst = *(int *)(param_2 + 0x98);
    if (iVar1 != 0) {
      do {
        iVar4 = iVar1;
        if ((*(uint *)(inst + 0x14) & 1) != 0) {
          param_7 = *(int *)(inst + 0x88);
          iVar1 = *(int *)(param_7 + 8);
          if ((iVar1 == 0x13) || (iVar1 == 0x14)) {
            iVar6 = 0x13;
          }
          else {
            iVar6 = 0x12;
            if (iVar1 != 0x12) goto LAB_00183fe8;
          }
          vector = *(uint **)(param_1 + 0x1c);
          uVar8 = *(uint *)(inst + 0x150);
          if (uVar8 < *vector) {
            vectorFilledCount = vector[1];
            if (vectorFilledCount <= uVar8) {
              _memset(vectorFilledCount * 4 + vector[2],0,(uVar8 - vectorFilledCount) * 4 + 4);
              vector[1] = uVar8 + 1;
              param_7 = *(int *)(inst + 0x88);
            }
            elementRef = (int *)(uVar8 * 4 + vector[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vector,uVar8);
            param_7 = *(int *)(inst + 0x88);
          }
          iVar1 = *elementRef;
          if ((((((iVar6 == *(int *)(param_7 + 8)) && (*(int *)(inst + 0x120) == 0)) &&
                ((*(uint *)(inst + 0x14) & 0x200) == 0)) &&
               (((iVar6 != 0x12 || (*(int *)(inst + 0x124) == 0)) &&
                ((iVar4 = IRInst__getOperandRecord(inst,0), *(int *)(iVar4 + 0x10) != DAT_001b021c &&
                 ((iVar4 = IRInst__getOperandRecord(inst,0), *(int *)(iVar4 + 0x10) != DAT_001b0218 &&
                  (iVar4 = IRInst__getOperandRecord(inst,0), *(int *)(iVar4 + 0x10) != DAT_001b0214)))))))) &&
              (iVar4 = IRInst__getOperandRecord(inst,0), *(int *)(iVar4 + 0x10) != DAT_001b0210)) &&
             ((((iVar4 = IRInst__hasSingleUse(inst,*(undefined4 *)(param_1 + 4)), iVar4 != 0 &&
                (iVar4 = *(int *)(iVar1 + 0xc), iVar4 != 0)) &&
               (iVar6 == *(int *)(*(int *)(iVar4 + 0x88) + 8))) &&
              ((iVar4 = IRInst__isSourceSelectIdentity(iVar4,*(undefined4 *)(iVar1 + 0x10)), iVar4 != 0 &&
               ((iVar6 != 0x12 ||
                (param_7 = *(int *)(iVar1 + 0xc),
                (*(uint *)(*(int *)(iVar1 + 0x10) * 0x18 + param_7 + 0xa0) & 2) == 0)))))))) {
            *(undefined4 *)(iVar1 + 0x14) = 0;
          }
          sourceDef = IRInst__getOperandSource(inst,1);
          sourceDef2 = IRInst__getOperandSource(inst,2);
          callResult = IRInst__getOperandRecord(inst,1);
          callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
          if (callResult == 0) {
LAB_00183e40:
            callResult = IRInst__getOperandRecord(inst,1);
            callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
            if (callResult == 0) {
              callResult = IRInst__getOperandRecord(inst,2);
              callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
              if (callResult != 0) goto LAB_00183e78;
            }
          }
          else {
            callResult = IRInst__getOperandRecord(inst,2);
            callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
            if (callResult != 0) goto LAB_00183e40;
LAB_00183e78:
            *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
          }
          if (param_2 == *(int *)(sourceDef + 0x158)) {
            vector2 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(sourceDef + 0x150);
            if (uVar8 < *vector2) {
              vectorFilledCount2 = vector2[1];
              if (vectorFilledCount2 <= uVar8) {
                _memset(vectorFilledCount2 * 4 + vector2[2],0,(uVar8 - vectorFilledCount2) * 4 + 4);
                vector2[1] = uVar8 + 1;
              }
              elementRef = (int *)(uVar8 * 4 + vector2[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector2,uVar8);
            }
            iVar4 = *elementRef;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (param_2 == *(int *)(sourceDef2 + 0x158)) {
            vector3 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(sourceDef2 + 0x150);
            if (uVar8 < *vector3) {
              vectorFilledCount3 = vector3[1];
              if (vectorFilledCount3 <= uVar8) {
                _memset(vectorFilledCount3 * 4 + vector3[2],0,(uVar8 - vectorFilledCount3) * 4 + 4);
                vector3[1] = uVar8 + 1;
              }
              elementRef = (int *)(uVar8 * 4 + vector3[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(vector3,uVar8);
            }
            iVar4 = *elementRef;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (((*(int *)(iVar1 + 0x14) != 0) && (1 < *(int *)(iVar1 + 8))) &&
             (iVar1 = ((int (*)())FUN_00181f00)(param_1,param_2,inst), iVar1 != 0)) goto LAB_00183bcc;
          iVar4 = *(int *)(inst + 8);
        }
LAB_00183fe8:
        iVar1 = *(int *)(iVar4 + 8);
        inst = iVar4;
        if (*(int *)(iVar4 + 8) == 0) break;
      } while( true );
    }
  }
  return ((int (*)())FUN_00183ac8)(param_1);
}

/* FUN_0018401c @ 0x18401c (144 bytes) */
int FUN_0018401c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int resourceModel;
  int listCount;
  undefined4 arenaAt378;
  int iVar1;
  int inst;
  int iVar3;
  undefined4 *vectorAlloc;
  char *extraout_r4;
  char *pcVar5;
  undefined4 allocation;
  int *piVar7;
  uint loopIndex;
  
  param_1[1] = param_2;
  iVar3 = *(int *)(param_2 + 8);
  *param_1 = iVar3;
  resourceModel = Compiler__getResourceModel(iVar3);
  param_1[2] = resourceModel;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vectorAlloc[1] = 2;
  *vectorAlloc = arenaAt378;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  param_1[7] = (int)(vectorAlloc + 1);
  iVar3 = *(int *)(param_1[1] + 900);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != 0) {
    listCount = DList__count(iVar3 + 0x90);
    if (2 < listCount) {
      ((int (*)())FUN_00183b9c)(param_1,iVar3,param_3,param_4,param_5,param_6,param_7);
    }
    iVar3 = *(int *)(iVar3 + 8);
    iVar1 = *(int *)(iVar3 + 8);
  }
  iVar3 = param_1[7];
  if (iVar3 != 0) {
    Arena__free(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
  }
  pcVar5 = "height_reduction";
  piVar7 = *(int **)(param_2 + 900);
  iVar3 = piVar7[2];
  while (iVar3 != 0) {
    (**(code **)(*piVar7 + 0x48))(piVar7,pcVar5);
    piVar7 = (int *)piVar7[2];
    pcVar5 = extraout_r4;
    iVar3 = piVar7[2];
  }
  iVar3 = *(int *)(param_2 + 0x3c4);
  iVar1 = 0;
  for (loopIndex = 1; loopIndex <= *(uint *)(iVar3 + 4); loopIndex = loopIndex + 1) {
    inst = *(int *)(*(int *)(iVar3 + 8) + iVar1);
    if ((*(uint *)(inst + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(inst,0);
      iVar3 = *(int *)(param_2 + 0x3c4);
    }
    iVar1 = iVar1 + 4;
  }
  return 1;
}

/* FUN_0018413c @ 0x18413c (224 bytes) */
int FUN_0018413c(param_1, param_2, block, beforeInst)
  int *param_1;
  undefined4 param_2;
  undefined4 block;
  int *beforeInst;
{
  uint vectorCapacity;
  undefined4 *elementRef;
  uint vectorSize8;
  uint vectorSize7;
  uint vectorSize6;
  uint vectorSize4;
  uint vectorSize3;
  uint vectorSize2;
  uint vectorSize;
  int *inst;
  int operandIndex;
  undefined4 allocation;
  undefined4 sourceDef;
  undefined4 arenaAt378;
  uint uVar1;
  int *vectorAlloc2;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc3;
  undefined4 *puVar5;
  uint vectorSize5;
  int *piVar7;
  uint *vector2;
  uint *vector3;
  uint *vector;
  int loopIndex;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  uint loopIndex2;
  
  loopIndex = *(int *)(*param_1 + 0x378);
  vectorAlloc2 = (int *)Arena__alloc(loopIndex,0x14);
  vector2 = (uint *)(vectorAlloc2 + 1);
  *vectorAlloc2 = loopIndex;
  vectorAlloc2[1] = 2;
  vectorAlloc2[4] = loopIndex;
  vectorAlloc2[2] = 0;
  loopIndex = Arena__alloc(loopIndex,8);
  vectorAlloc2[3] = loopIndex;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  allocation = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = allocation;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vector3 = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[2] = 0;
  vectorAlloc3[4] = arenaAt378;
  allocation = Arena__alloc(arenaAt378,8);
  loopIndex2 = vectorAlloc2[2];
  vectorCapacity = *vector2;
  vectorAlloc3[3] = allocation;
  if (loopIndex2 < vectorCapacity) {
    _memset((void *)(loopIndex2 * 4 + vectorAlloc2[3]),0,4);
    elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = loopIndex2 + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector2,loopIndex2);
  }
  *elementRef = beforeInst;
  vectorSize = vectorAlloc[2];
  if (vectorSize < *vector) {
    _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
    elementRef = (undefined4 *)(vectorSize * 4 + vectorAlloc[3]);
    vectorAlloc[2] = vectorSize + 1;
    goto code_r0x00184480;
  }
code_r0x00184474:
  elementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorSize);
code_r0x00184480:
  *elementRef = 1;
  do {
    vectorSize2 = vectorAlloc2[2];
    if (vectorSize2 == 0) {
      if (*vector2 == 0) {
        elementRef = (undefined4 *)Vector__elementRefGrow(vector2,0);
      }
      else {
        _memset((void *)vectorAlloc2[3],0,4);
        elementRef = (undefined4 *)vectorAlloc2[3];
        vectorAlloc2[2] = 1;
      }
      *elementRef = beforeInst;
      uVar1 = vectorAlloc[2];
      if (uVar1 < *vector) {
        _memset((void *)(uVar1 * 4 + vectorAlloc[3]),0,4);
        elementRef = (undefined4 *)(uVar1 * 4 + vectorAlloc[3]);
        vectorAlloc[2] = uVar1 + 1;
      }
      else {
        elementRef = (undefined4 *)Vector__elementRefGrow(vector,uVar1);
      }
      *elementRef = 1;
      while (uVar1 = vectorAlloc2[2], uVar1 != 0) {
        puVar5 = (undefined4 *)0x0;
        if (uVar1 - 1 < uVar1) {
          puVar5 = (undefined4 *)((uVar1 - 1) * 4 + vectorAlloc2[3]);
        }
        piVar7 = (int *)*puVar5;
        loopIndex = ((int (*)())FUN_00181928)(piVar7,block,param_2);
        if ((loopIndex == 0) && (beforeInst != piVar7)) {
          Vector__removeAt(vector2,vectorAlloc2[2] + -1);
          Vector__removeAt(vector,vectorAlloc[2] + -1);
        }
        else {
          piVar14 = (int *)0x0;
          uVar1 = vectorAlloc[2] - 1;
          if (uVar1 < (uint)vectorAlloc[2]) {
            piVar14 = (int *)(uVar1 * 4 + vectorAlloc[3]);
          }
          iVar13 = *piVar14;
          loopIndex = (**(code **)(*piVar7 + 0x14))(piVar7);
          if (loopIndex < iVar13) {
            Vector__removeAt(vector2,vectorAlloc2[2] + -1);
            Vector__removeAt(vector,vectorAlloc[2] + -1);
            if (beforeInst != piVar7) {
              DList__unlink(piVar7);
              Block__insertInstBefore(block,beforeInst,piVar7);
            }
          }
          else {
            uVar1 = (**(code **)(*piVar7 + 0x14))(piVar7);
            if (0 < (int)uVar1) {
              loopIndex = 1;
              do {
                sourceDef = IRInst__getOperandSource(piVar7,loopIndex);
                loopIndex2 = vectorAlloc3[2];
                if (loopIndex2 < *vector3) {
                  _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
                  elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                  vectorAlloc3[2] = loopIndex2 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
                }
                loopIndex = loopIndex + 1;
                *elementRef = sourceDef;
              } while (loopIndex <= (int)uVar1);
            }
            Vector__shellSort(vector3,FUN_001819b4);
            Vector__removeAt(vector,vectorAlloc[2] + -1);
            loopIndex2 = vectorAlloc[2];
            if (loopIndex2 < *vector) {
              _memset((void *)(loopIndex2 * 4 + vectorAlloc[3]),0,4);
              piVar7 = (int *)(loopIndex2 * 4 + vectorAlloc[3]);
              vectorAlloc[2] = loopIndex2 + 1;
            }
            else {
              piVar7 = (int *)Vector__elementRefGrow(vector,loopIndex2);
            }
            *piVar7 = uVar1 + 1;
            if (0 < (int)uVar1) {
              loopIndex2 = 0;
              do {
                if (loopIndex2 < *vector3) {
                  vectorSize5 = vectorAlloc3[2];
                  if (vectorSize5 <= loopIndex2) {
                    _memset((void *)(vectorSize5 * 4 + vectorAlloc3[3]),0,(loopIndex2 - vectorSize5) * 4 + 4);
                    vectorAlloc3[2] = loopIndex2 + 1;
                  }
                  elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
                }
                loopIndex2 = loopIndex2 + 1;
                vectorSize6 = vectorAlloc2[2];
                uVar12 = *elementRef;
                if (vectorSize6 < *vector2) {
                  _memset((void *)(vectorSize6 * 4 + vectorAlloc2[3]),0,4);
                  elementRef = (undefined4 *)(vectorSize6 * 4 + vectorAlloc2[3]);
                  vectorAlloc2[2] = vectorSize6 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector2,vectorSize6);
                }
                *elementRef = uVar12;
                vectorSize7 = vectorAlloc[2];
                if (vectorSize7 < *vector) {
                  _memset((void *)(vectorSize7 * 4 + vectorAlloc[3]),0,4);
                  elementRef = (undefined4 *)(vectorSize7 * 4 + vectorAlloc[3]);
                  vectorAlloc[2] = vectorSize7 + 1;
                }
                else {
                  elementRef = (undefined4 *)Vector__elementRefGrow(vector,vectorSize7);
                }
                *elementRef = 1;
              } while (uVar1 != loopIndex2);
            }
            vectorAlloc3[2] = 0;
          }
        }
      }
      if (vector3 != (uint *)0x0) {
        Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
        Arena__free(*vectorAlloc3,vectorAlloc3);
      }
      if (vector != (uint *)0x0) {
        Arena__free(vectorAlloc[4],vectorAlloc[3]);
        Arena__free(*vectorAlloc,vectorAlloc);
      }
      if (vector2 == (uint *)0x0) {
        return;
      }
      Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
      loopIndex = *vectorAlloc2;
      if ((*(int *)(loopIndex + 0x28) != 0) && (piVar7 = *(int **)(loopIndex + 0x14), piVar7 == vectorAlloc2)) {
        _memset(piVar7,0,*(int *)(loopIndex + 8) - (int)piVar7);
        *(undefined4 *)(loopIndex + 8) = *(undefined4 *)(loopIndex + 0x14);
      }
      return;
    }
    puVar5 = (undefined4 *)0x0;
    if (vectorSize2 - 1 < vectorSize2) {
      puVar5 = (undefined4 *)((vectorSize2 - 1) * 4 + vectorAlloc2[3]);
    }
    inst = (int *)*puVar5;
    uVar1 = vectorAlloc[2] - 1;
    piVar7 = (int *)0x0;
    if (uVar1 < (uint)vectorAlloc[2]) {
      piVar7 = (int *)(uVar1 * 4 + vectorAlloc[3]);
    }
    operandIndex = *piVar7;
    loopIndex = ((int (*)())FUN_00181928)(inst,block,param_2);
    if ((loopIndex == 0) && (beforeInst != inst)) {
      inst[0x54] = 0;
    }
    else {
      loopIndex = (**(code **)(*inst + 0x14))(inst);
      if (operandIndex <= loopIndex) break;
      uVar1 = (**(code **)(*inst + 0x14))(inst);
      if (0 < (int)uVar1) {
        loopIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(inst,loopIndex);
          loopIndex2 = vectorAlloc3[2];
          if (loopIndex2 < *vector3) {
            _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
            elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = loopIndex2 + 1;
          }
          else {
            elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
          }
          loopIndex = loopIndex + 1;
          *elementRef = sourceDef;
        } while (loopIndex <= (int)uVar1);
      }
      Vector__shellSort(vector3,FUN_001819b4);
      if (0 < (int)uVar1) {
        loopIndex2 = 0;
        loopIndex = 0;
        do {
          if (loopIndex2 < *vector3) {
            vectorSize8 = vectorAlloc3[2];
            if (vectorSize8 <= loopIndex2) {
              _memset((void *)(vectorSize8 * 4 + vectorAlloc3[3]),0,(loopIndex2 - vectorSize8) * 4 + 4);
              vectorAlloc3[2] = loopIndex2 + 1;
            }
            elementRef = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
          }
          else {
            elementRef = (undefined4 *)Vector__elementRefGrow(vector3,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          piVar7 = (int *)*elementRef;
          if ((((piVar7[0x20] == 0) || (operandIndex = RegKind__flagBit0(piVar7[0x26]), operandIndex == 0)) ||
              ((piVar7[5] & 2U) != 0)) ||
             (operandIndex = (**(code **)(*piVar7 + 0x50))(piVar7), operandIndex != 0)) {
            operandIndex = 0;
          }
          else {
            operandIndex = IRInst__countWrittenComponents(piVar7);
          }
          loopIndex = loopIndex + operandIndex;
          if (loopIndex <= piVar7[0x54]) {
            loopIndex = piVar7[0x54];
          }
        } while (uVar1 != loopIndex2);
      }
      else {
        loopIndex = 0;
      }
      vectorAlloc3[2] = 0;
      inst[0x54] = loopIndex;
    }
    Vector__removeAt(vector2,vectorAlloc2[2] + -1);
    Vector__removeAt(vector,vectorAlloc[2] + -1);
  } while( true );
  sourceDef = IRInst__getOperandSource(inst,operandIndex);
  vectorSize3 = vectorAlloc2[2];
  if (vectorSize3 < *vector2) {
    _memset((void *)(vectorSize3 * 4 + vectorAlloc2[3]),0,4);
    elementRef = (undefined4 *)(vectorSize3 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = vectorSize3 + 1;
  }
  else {
    elementRef = (undefined4 *)Vector__elementRefGrow(vector2,vectorSize3);
  }
  *elementRef = sourceDef;
  Vector__removeAt(vector,vectorAlloc[2] + -1);
  vectorSize4 = vectorAlloc[2];
  if (vectorSize4 < *vector) {
    _memset((void *)(vectorSize4 * 4 + vectorAlloc[3]),0,4);
    piVar7 = (int *)(vectorSize4 * 4 + vectorAlloc[3]);
    vectorAlloc[2] = vectorSize4 + 1;
  }
  else {
    piVar7 = (int *)Vector__elementRefGrow(vector,vectorSize4);
  }
  *piVar7 = operandIndex + 1;
  vectorSize = vectorAlloc[2];
  if (*vector <= vectorSize) goto code_r0x00184474;
  _memset((void *)(vectorSize * 4 + vectorAlloc[3]),0,4);
  elementRef = (undefined4 *)(vectorSize * 4 + vectorAlloc[3]);
  vectorAlloc[2] = vectorSize + 1;
  goto code_r0x00184480;
}

/* pass_minreg_order @ 0x184ab4 (280 bytes) */
int pass_minreg_order(scheduler, program)
  undefined4 scheduler;
  int program;
{
  int block;
  int nextBlock;
  int *nextInst;
  int *currentInst;
  int *inst;
  
  block = *(int *)(program + PROG_blockListHead);
  for (nextBlock = *(int *)(*(int *)(program + PROG_blockListHead) + 8); nextBlock != 0; nextBlock = *(int *)(nextBlock + 8)) {
    nextInst = (int *)(*(int **)(block + 0xa0))[1];
    inst = *(int **)(block + 0xa0);
    if (nextInst != (int *)0x0) {
      do {
        currentInst = nextInst;
        nextBlock = (**(code **)(*inst + 0x34))(inst);
        if ((((nextBlock == 0) && (nextBlock = (**(code **)(*inst + 0x38))(inst), nextBlock == 0)) &&
            (nextBlock = (**(code **)(*inst + 0x14))(inst), 0 < nextBlock)) &&
           (nextBlock = ((int (*)())FUN_00181928)(inst,block,program), nextBlock == 0)) {
          ((int (*)())FUN_0018413c)(scheduler,program,block,inst);
        }
        nextInst = (int *)currentInst[1];
        inst = currentInst;
      } while (nextInst != (int *)0x0);
      nextBlock = *(int *)(block + 8);
    }
    block = nextBlock;
  }
  return Program__beginPass(program,(int)"minreg_order");
}

/* compareIntsAscending @ 0x184bcc (36 bytes) */
int compareIntsAscending(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 == param_2) {
    return 0;
  }
  if (param_2 < param_1) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00184bf0 @ 0x184bf0 (232 bytes) */
int FUN_00184bf0(param_1)
  int param_1;
{
  uint vectorFilledCount;
  uint vectorFilledCount2;
  undefined4 *puVar3;
  int callResult;
  uint loopIndex;
  int iVar6;
  uint uVar7;
  uint *vector;
  
  vector = *(uint **)(param_1 + 0x10);
  vectorFilledCount = vector[1];
  uVar7 = vectorFilledCount - 1;
  if (-1 < (int)uVar7) {
    iVar6 = uVar7 * 4;
    loopIndex = 0;
    while( true ) {
      if (uVar7 < *vector) {
        vectorFilledCount2 = vector[1];
        if (vectorFilledCount2 <= uVar7) {
          _memset(vectorFilledCount2 * 4 + vector[2],0,(uVar7 - vectorFilledCount2) * 4 + 4);
          vector[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(iVar6 + vector[2]);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(vector,uVar7);
      }
      callResult = (**(code **)(*(int *)*puVar3 + 0x24))((int *)*puVar3);
      if (callResult == 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
      uVar7 = uVar7 - 1;
      iVar6 = iVar6 + -4;
      if (vectorFilledCount == loopIndex) break;
      vector = *(uint **)(param_1 + 0x10);
    }
  }
  return 1;
}

/* FUN_00184cd8 @ 0x184cd8 (164 bytes) */
int FUN_00184cd8(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_3);
  if (((iVar1 == 0) ||
      (piVar2 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
      iVar1 = (**(code **)(*piVar2 + 0xfc))(piVar2,param_1[0x49] + -1,param_1), iVar1 == 0)) ||
     ((iVar1 = *(int *)(param_1[0x22] + 8), iVar1 != 0x13 && ((iVar1 != 0x1c && (iVar1 != 0x1d))))))
  {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

/* Inst__splitAndMerge @ 0x184d7c (372 bytes) */
int Inst__splitAndMerge(param_1, program)
  int param_1;
  undefined4 program;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  undefined4 *elementRef;
  int callResult;
  uint loopIndex;
  uint *vector;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    vector = *(uint **)(param_1 + 0x10);
    vectorFilledCount = vector[1];
    if (0 < (int)vectorFilledCount) {
      loopIndex = 0;
      do {
        if (loopIndex < *vector) {
          if (vectorFilledCount <= loopIndex) {
            _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex - vectorFilledCount) * 4 + 4);
            vector[1] = loopIndex + 1;
          }
          elementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
        }
        else {
          elementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
        }
        callResult = Inst__canFuseAddMul(*elementRef,program,0);
        if (callResult == 0) {
          return;
        }
        vector = *(uint **)(param_1 + 0x10);
        loopIndex = loopIndex + 1;
        vectorFilledCount = vector[1];
      } while ((int)loopIndex < (int)vectorFilledCount);
    }
    vectorFilledCount2 = vector[1];
    if (0 < (int)vectorFilledCount2) {
      loopIndex = 0;
      do {
        if (loopIndex < *vector) {
          if (vectorFilledCount2 <= loopIndex) {
            _memset(vectorFilledCount2 * 4 + vector[2],0,(loopIndex - vectorFilledCount2) * 4 + 4);
            vector[1] = loopIndex + 1;
          }
          elementRef = (undefined4 *)(loopIndex * 4 + vector[2]);
        }
        else {
          elementRef = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
        }
        loopIndex = loopIndex + 1;
        Inst__collapseAddOfMulToMad(*elementRef,program,1,0);
        vector = *(uint **)(param_1 + 0x10);
        vectorFilledCount2 = vector[1];
      } while ((int)loopIndex < (int)vectorFilledCount2);
    }
  }
  return;
}

/* FUN_00184ef0 @ 0x184ef0 (2440 bytes) */
int FUN_00184ef0(param_1, param_2, program)
  int *param_1;
  uint param_2;
  int program;
{
  int *elementRef;
  int *inst;
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  float fVar1;
  float fVar2;
  uint uVar3;
  int loopRemaining2;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  undefined4 operandVReg;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int operandIndex;
  int operandIndex2;
  uint loopIndex2;
  uint *loopPtr;
  uint *vector;
  int loopRemaining;
  double dVar22;
  undefined1 auStack_f8 [4];
  uint local_f4;
  uint local_e4;
  float local_e0;
  undefined4 local_c8;
  uint uStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8;
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  int local_84;
  int local_80;
  int local_7c;
  int block;
  int afterInst;
  int local_70;
  
  loopRemaining2 = (**(code **)(*param_1 + 0x24))(param_1,param_2,program);
  if ((((loopRemaining2 == 0) ||
       (piVar5 = *(int **)(*(int *)(program + 8) + 0x30c),
       loopRemaining2 = (**(code **)(*piVar5 + 0xfc))(piVar5,param_2 + param_1[0x49],0), loopRemaining2 == 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((param_1[0x48] != 0 || (loopRemaining2 = (**(code **)(*param_1 + 0x5c))(param_1), loopRemaining2 != 0)))) {
LAB_00185098:
    uVar8 = 0;
  }
  else {
    Vector__shellSort(param_1[4],compareIntsAscending);
    loopPtr = (uint *)param_1[4];
    uVar6 = loopPtr[1];
    if (0 < (int)uVar6) {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < *loopPtr) {
          if (uVar6 <= loopIndex2) {
            _memset(uVar6 * 4 + loopPtr[2],0,(loopIndex2 - uVar6) * 4 + 4);
            loopPtr[1] = loopIndex2 + 1;
          }
          puVar7 = (undefined4 *)(loopIndex2 * 4 + loopPtr[2]);
        }
        else {
          puVar7 = (undefined4 *)Vector__elementRefGrow(loopPtr,loopIndex2);
        }
        inst = (int *)*puVar7;
        if ((((inst[5] & 0x200U) != 0) ||
            (loopRemaining2 = (**(code **)(*inst + 0x28))(inst), loopRemaining2 != 0)) ||
           (loopRemaining2 = (**(code **)(*inst + 0x5c))(inst), loopRemaining2 != 0)) goto LAB_00185098;
        loopRemaining2 = *(int *)(inst[0x22] + 8);
        if (loopRemaining2 == 0x31) {
LAB_001850bc:
          if ((((inst[0x21] != 2) || (piVar9 = (int *)IRInst__getOperandSource(inst,1), param_1 != piVar9))
              || (piVar9 = (int *)IRInst__getOperandSource(inst,2), param_1 != piVar9)) ||
             (piVar9 = *(int **)(*(int *)(program + 8) + 0x30c),
             loopRemaining2 = (**(code **)(*piVar9 + 0xfc))(piVar9,inst[0x49] + param_2 * -2,0), loopRemaining2 == 0
             )) {
LAB_001851b4:
            piVar9 = *(int **)(*(int *)(program + 8) + 0x30c);
            loopRemaining2 = (**(code **)(*piVar9 + 0xfc))(piVar9,inst[0x49] - param_2,0);
            goto joined_r0x001851e0;
          }
        }
        else {
          if (0x31 < loopRemaining2) {
            if ((loopRemaining2 == 0x36) || (loopRemaining2 == 0x66)) goto LAB_001850bc;
            if (loopRemaining2 == 0x34) {
LAB_00185124:
              piVar9 = (int *)IRInst__getOperandSource(inst,1);
              if ((param_1 != piVar9) || (piVar9 = (int *)IRInst__getOperandSource(inst,2), param_1 != piVar9)
                 ) {
                if ((int)param_2 < 0) {
                  uStack_c4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_c8 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_c4) - 4503601774854144.0);
                }
                else {
                  local_c0 = 0x43300000;
                  uStack_bc = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_bc) - 4503601774854144.0)
                  ;
                }
                loopRemaining2 = 4;
                loopPtr = &local_f4;
                do {
                  *loopPtr = 0x7ffffffe;
                  loopPtr = loopPtr + 1;
                  loopRemaining2 = loopRemaining2 + -1;
                } while (loopRemaining2 != 0);
                loopRemaining2 = 0;
                loopRemaining = 4;
                do {
                  *(float *)(loopRemaining2 + (int)&local_f4) = fVar2;
                  loopRemaining2 = loopRemaining2 + 4;
                  loopRemaining = loopRemaining + -1;
                } while (loopRemaining != 0);
                goto LAB_0018533c;
              }
              goto LAB_001851b4;
            }
            goto LAB_00185098;
          }
          if (loopRemaining2 == 0x13) goto LAB_001850bc;
          if (loopRemaining2 != 0x14) {
            if (loopRemaining2 == 0x12) goto LAB_00185124;
            goto LAB_00185098;
          }
          loopRemaining2 = IRInst__getOperandRecord(inst,0);
          loopRemaining2 = IRInst__getUniformSourceConstant(inst,2,*(undefined4 *)(loopRemaining2 + 0x10),&local_e4);
          fVar2 = local_e0;
          if (((loopRemaining2 == 0) || (local_e4 != 2)) ||
             (inst = (int *)IRInst__getOperandSource(inst,1), param_1 != inst)) goto LAB_00185098;
          if ((int)param_2 < 0) {
            uStack_b4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
            local_b8 = 0x43300000;
            fVar1 = (float)((double)CONCAT44(0x43300000,uStack_b4) - 4503601774854144.0);
          }
          else {
            local_b0 = 0x43300000;
            uStack_ac = 1 << (param_2 & 0x3f) ^ 0x80000000;
            fVar1 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_ac) - 4503601774854144.0);
          }
          loopPtr = &local_f4;
          do {
            *loopPtr = 0x7ffffffe;
            loopPtr = loopPtr + 1;
          } while (&local_e4 != loopPtr);
          loopRemaining2 = 0;
          loopRemaining = 4;
          do {
            *(float *)(loopRemaining2 + (int)&local_f4) = fVar2 * fVar1;
            loopRemaining2 = loopRemaining2 + 4;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
LAB_0018533c:
          piVar5 = *(int **)(*(int *)(program + 8) + 0x30c);
          loopRemaining2 = (**(code **)(*piVar5 + 0xe8))
                            (piVar5,&local_f4,auStack_f8,0x10203,*(int *)(program + 8));
joined_r0x001851e0:
          if (loopRemaining2 == 0) goto LAB_00185098;
        }
        loopPtr = (uint *)param_1[4];
        loopIndex2 = loopIndex2 + 1;
        uVar6 = loopPtr[1];
      } while ((int)loopIndex2 < (int)uVar6);
    }
    uVar6 = uVar6 - 1;
    if (-1 < (int)uVar6) {
      local_70 = param_2 << 1;
      do {
        if (0 < (int)uVar6) {
          loopIndex2 = uVar6 - 1;
          if (loopIndex2 < *loopPtr) {
            uVar3 = loopPtr[1];
            vector = loopPtr;
            if (uVar3 <= loopIndex2) {
              _memset(uVar3 * 4 + loopPtr[2],0,(loopIndex2 - uVar3) * 4 + 4);
              loopPtr[1] = uVar6;
              vector = (uint *)param_1[4];
            }
            piVar5 = (int *)(loopIndex2 * 4 + loopPtr[2]);
          }
          else {
            piVar5 = (int *)Vector__elementRefGrow(loopPtr,loopIndex2);
            vector = (uint *)param_1[4];
          }
          loopRemaining2 = *piVar5;
          if (uVar6 < *vector) {
            loopIndex2 = vector[1];
            if (loopIndex2 <= uVar6) {
              _memset(loopIndex2 * 4 + vector[2],0,(uVar6 - loopIndex2) * 4 + 4);
              vector[1] = uVar6 + 1;
            }
            elementRef = (int *)(uVar6 * 4 + vector[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vector,uVar6);
          }
          if (loopRemaining2 != *elementRef) {
            loopPtr = (uint *)param_1[4];
            goto LAB_0018545c;
          }
          goto LAB_00185964;
        }
LAB_0018545c:
        if (uVar6 < *loopPtr) {
          loopIndex2 = loopPtr[1];
          if (loopIndex2 <= uVar6) {
            _memset(loopIndex2 * 4 + loopPtr[2],0,(uVar6 - loopIndex2) * 4 + 4);
            loopPtr[1] = uVar6 + 1;
          }
          puVar7 = (undefined4 *)(uVar6 * 4 + loopPtr[2]);
        }
        else {
          puVar7 = (undefined4 *)Vector__elementRefGrow(loopPtr,uVar6);
        }
        piVar5 = (int *)*puVar7;
        loopRemaining2 = *(int *)(piVar5[0x22] + 8);
        if (loopRemaining2 == 0x31) {
LAB_0018550c:
          if ((piVar5[0x21] == 2) &&
             ((piVar9 = (int *)IRInst__getOperandSource(piVar5,1), param_1 == piVar9 &&
              (piVar9 = (int *)IRInst__getOperandSource(piVar5,2), param_1 == piVar9)))) {
            piVar5[0x49] = piVar5[0x49] - local_70;
          }
          else {
LAB_00185628:
            piVar5[0x49] = piVar5[0x49] - param_2;
          }
        }
        else {
          if (loopRemaining2 < 0x32) {
            if (loopRemaining2 != 0x13) {
              if (loopRemaining2 == 0x14) {
                loopRemaining2 = IRInst__getOperandRecord(piVar5,0);
                IRInst__getUniformSourceConstant(piVar5,2,*(undefined4 *)(loopRemaining2 + 0x10),&local_e4);
                if ((int)param_2 < 0) {
                  uStack_94 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_98 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_94) - 4503601774854144.0);
                }
                else {
                  local_90 = 0x43300000;
                  uStack_8c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_8c) - 4503601774854144.0)
                  ;
                }
                dVar22 = (double)(local_e0 * fVar2);
                IROperand__setModifierBits(piVar5 + 0x2f,1,0);
                IROperand__setModifierBits(piVar5 + 0x2f,2,0);
                ((void (*)())IRInst__makeLiteralVec4Float)(piVar5,program,2,dVar22,dVar22,dVar22,dVar22);
              }
              else if (loopRemaining2 == 0x12) goto LAB_00185558;
              goto LAB_00185964;
            }
            goto LAB_0018550c;
          }
          if ((loopRemaining2 == 0x36) || (loopRemaining2 == 0x66)) goto LAB_0018550c;
          if (loopRemaining2 == 0x34) {
LAB_00185558:
            piVar9 = (int *)IRInst__getOperandSource(piVar5,1);
            if ((param_1 != piVar9) || (piVar9 = (int *)IRInst__getOperandSource(piVar5,2), param_1 != piVar9))
            {
              if ((int)param_2 < 0) {
                uStack_a4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                local_a8 = 0x43300000;
                fVar2 = (float)((double)CONCAT44(0x43300000,uStack_a4) - 4503601774854144.0);
              }
              else {
                local_a0 = 0x43300000;
                uStack_9c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                fVar2 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_9c) - 4503601774854144.0);
              }
              dVar22 = (double)fVar2;
              afterInst = piVar5[1];
              block = piVar5[0x56];
              DList__unlink(piVar5);
              loopRemaining2 = IRInst__getOperandRecord(piVar5,0);
              local_84 = *(int *)(loopRemaining2 + 0x10);
              local_7c = piVar5[0x49];
              local_80 = piVar5[0x48];
              loopRemaining2 = IRInst__useCount(piVar5,program);
              loopRemaining = piVar5[4];
              piVar9 = (int *)IRInst__getOperandSource(piVar5,1);
              if (param_1 == piVar9) {
                operandIndex2 = 1;
                operandIndex = 2;
              }
              else {
                IRInst__getOperandSource(piVar5,2);
                operandIndex2 = 2;
                operandIndex = 1;
              }
              iVar13 = piVar5[operandIndex2 * 6 + 0x26];
              iVar12 = piVar5[operandIndex2 * 6 + 0x25];
              operandRecord2 = IRInst__getOperandRecord(piVar5,operandIndex2);
              loopIndex2 = piVar5[operandIndex2 * 6 + 0x28];
              uVar15 = *(undefined4 *)(operandRecord2 + 0x10);
              sourceDef = IRInst__getOperandSource(piVar5,operandIndex2);
              iVar14 = piVar5[operandIndex * 6 + 0x26];
              iVar10 = piVar5[operandIndex * 6 + 0x25];
              operandRecord = IRInst__getOperandRecord(piVar5,operandIndex);
              local_88 = *(undefined4 *)(operandRecord + 0x10);
              uVar3 = piVar5[operandIndex * 6 + 0x28];
              operandVReg = IRInst__getOperandSource(piVar5,operandIndex);
              (**(code **)(*piVar5 + 0xc))(piVar5,1,*(undefined4 *)(program + 8));
              IRInst__reinitAsTrinary(piVar5,0x14,*(undefined4 *)(program + 8));
              piVar5[4] = loopRemaining;
              piVar5[0x25] = piVar5[0x53];
              piVar5[0x26] = 0;
              piVar5[0x27] = local_84;
              piVar5[0x48] = local_80;
              piVar5[0x49] = local_7c;
              piVar5[0x58] = loopRemaining2 + *(int *)(program + 0x478);
              IRInst__setOperandSource(piVar5,1,sourceDef,1,*(undefined4 *)(program + 8));
              loopRemaining2 = IRInst__getOperandRecord(piVar5,1);
              *(int *)(loopRemaining2 + 0xc) = iVar13;
              *(int *)(loopRemaining2 + 8) = iVar12;
              loopRemaining2 = IRInst__getOperandRecord(piVar5,1);
              *(undefined4 *)(loopRemaining2 + 0x10) = uVar15;
              IROperand__setModifierBits(piVar5 + 0x29,2,loopIndex2 >> 1 & 1);
              IROperand__setModifierBits(piVar5 + 0x29,1,loopIndex2 & 1);
              IRInst__setOperandSource(piVar5,3,operandVReg,1,*(undefined4 *)(program + 8));
              loopRemaining2 = IRInst__getOperandRecord(piVar5,3);
              *(int *)(loopRemaining2 + 0xc) = iVar14;
              *(int *)(loopRemaining2 + 8) = iVar10;
              loopRemaining2 = IRInst__getOperandRecord(piVar5,3);
              *(undefined4 *)(loopRemaining2 + 0x10) = local_88;
              IROperand__setModifierBits(piVar5 + 0x35,2,uVar3 >> 1 & 1);
              IROperand__setModifierBits(piVar5 + 0x35,1,uVar3 & 1);
              ((void (*)())IRInst__makeLiteralVec4Float)(piVar5,program,2,dVar22,dVar22,dVar22,dVar22);
              Block__insertInstAfter(block,afterInst,piVar5);
              goto LAB_00185964;
            }
            goto LAB_00185628;
          }
        }
LAB_00185964:
        uVar6 = uVar6 - 1;
        if ((int)uVar6 < 0) break;
        loopPtr = (uint *)param_1[4];
      } while( true );
    }
    uVar8 = 1;
    param_1[0x49] = param_2 + param_1[0x49];
  }
  return uVar8;
}

/* Inst__tryDp3Add @ 0x1859bc (640 bytes) */
int Inst__tryDp3Add(inst, program, compiler)
  int inst;
  int program;
  undefined4 compiler;
{
  uint dotSrc1Flags;
  undefined4 sourceDef;
  uint addendFlags;
  uint dotSrc2Flags;
  int callResult;
  int *dotInst;
  int *operandVReg;
  undefined4 operandVReg2;
  undefined4 prevNode;
  undefined4 block;
  int addendIndex;
  undefined4 saturate;
  undefined4 resultScale;
  undefined4 destSelect;
  undefined4 addendSelect;
  undefined4 src1Select;
  int extraSource;
  undefined4 addendSelect3;
  undefined4 addendDef;
  uint addendNegate;
  uint addendAbs;
  undefined4 dotSrc2Select;
  undefined4 dotSrc1Select;
  undefined4 addendOperandSelect;
  
  callResult = IRInst__getOperandRecord(inst,1);
  src1Select = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,2);
  addendSelect = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,0);
  destSelect = *(undefined4 *)(callResult + 0x10);
  if (((*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) &&
      (callResult = SelectWord__isSplat(src1Select), callResult != 0)) && (callResult = SelectWord__isSplat(addendSelect), callResult != 0)) {
    dotInst = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,2);
    if (((*(int *)(dotInst[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(dotInst,program), callResult != 0))
       && (((*(uint *)(inst + 0xb8) & 1) == 0 && ((*(uint *)(inst + 0xb8) & 2) == 0)))) {
      callResult = FUN_00146788(dotInst,program);
      addendIndex = 2;
      if (callResult != 0) goto LAB_00185afc;
    }
    if (((*(int *)(operandVReg[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(operandVReg,program), callResult != 0))
       && (((*(uint *)(inst + 0xd0) & 1) == 0 &&
           (((*(uint *)(inst + 0xd0) & 2) == 0 &&
            (callResult = FUN_00146788(operandVReg,program), callResult != 0)))))) {
      addendIndex = 1;
      dotInst = operandVReg;
      addendSelect = src1Select;
LAB_00185afc:
      addendDef = IRInst__getOperandSource(inst,addendIndex);
      addendFlags = *(uint *)(addendIndex * 0x18 + inst + 0xa0);
      extraSource = 0;
      addendNegate = addendFlags & 1;
      addendAbs = addendFlags >> 1 & 1;
      callResult = IRInst__getOperandRecord(inst,addendIndex);
      addendOperandSelect = *(undefined4 *)(callResult + 0x10);
      sourceDef = IRInst__getOperandSource(dotInst,1);
      dotSrc1Flags = dotInst[0x2e];
      callResult = IRInst__getOperandRecord(dotInst,1);
      dotSrc1Select = *(undefined4 *)(callResult + 0x10);
      operandVReg2 = IRInst__getOperandSource(dotInst,2);
      dotSrc2Flags = dotInst[0x34];
      callResult = IRInst__getOperandRecord(dotInst,2);
      dotSrc2Select = *(undefined4 *)(callResult + 0x10);
      prevNode = *(undefined4 *)(inst + 4);
      block = *(undefined4 *)(inst + 0x158);
      callResult = IRInst__useCount(inst,program);
      saturate = *(undefined4 *)(inst + 0x120);
      resultScale = *(undefined4 *)(inst + 0x124);
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        extraSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      DList__unlink(inst);
      IRInst__reinitAsTrinary(inst,0xa3,compiler);
      *(undefined4 *)(inst + 0x98) = 0;
      *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
      *(undefined4 *)(inst + 0x9c) = destSelect;
      *(undefined4 *)(inst + 0x120) = saturate;
      *(undefined4 *)(inst + 0x124) = resultScale;
      *(int *)(inst + 0x160) = callResult + *(int *)(program + 0x478);
      if (extraSource != 0) {
        IRInst__setExtraOperandSource(inst,extraSource,0,compiler);
      }
      Block__insertInstAfter(block,prevNode,inst);
      IRInst__setOperandSource(inst,1,sourceDef,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xa4,1,dotSrc1Flags & 1);
      IROperand__setModifierBits(inst + 0xa4,2,dotSrc1Flags >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(callResult + 0x10) = dotSrc1Select;
      IRInst__setOperandSource(inst,2,operandVReg2,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xbc,1,dotSrc2Flags & 1);
      IROperand__setModifierBits(inst + 0xbc,2,dotSrc2Flags >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(callResult + 0x10) = dotSrc2Select;
      IRInst__setOperandSource(inst,3,addendDef,0,*(undefined4 *)(program + 8));
      IROperand__setModifierBits(inst + 0xd4,1,addendNegate);
      IROperand__setModifierBits(inst + 0xd4,2,addendAbs);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = addendOperandSelect;
      FUN_000f33f8(&addendSelect3,addendSelect);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = addendSelect3;
                    
                    
      (**(code **)(*dotInst + 0xc))(dotInst,0,*(undefined4 *)(program + 8));
      return;
    }
  }
  return;
}

/* FUN_00185da4 @ 0x185da4 (1900 bytes) */
int FUN_00185da4(operandIndex, param_2, inst, inst2, inst3, program, param_7, param_8, param_9, param_10)
  int operandIndex;
  int param_2;
  int *inst;
  int *inst2;
  int *inst3;
  int program;
  int param_7;
  int param_8;
  undefined4 *param_9;
  int param_10;
{
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  int loopIndex;
  int *piVar4;
  int loopRemaining;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int loopIndex2;
  code *pcVar10;
  undefined4 local_68;
  int local_64 [3];
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [4];
  
  loopIndex = IRInst__getOperandRecord(inst3,1);
  uVar8 = *(undefined4 *)(loopIndex + 0x10);
  loopIndex = IRInst__getOperandRecord(inst,operandIndex);
  uVar7 = *(undefined4 *)(loopIndex + 0x10);
  SelectWord__compose(&local_58,uVar8,uVar7);
  local_68 = local_58;
  piVar4 = *(int **)(*(int *)(program + 8) + 0x30c);
  loopIndex = (**(code **)(*piVar4 + 0x108))(piVar4,&local_68);
  if (loopIndex == 0) {
    *(int *)(program + 0x20c) = *(int *)(program + 0x20c) + 1;
    return 0;
  }
  if ((param_2 == 0) || ((inst[operandIndex * 6 + 0x28] & 2U) != 0)) {
LAB_00185ea8:
    if (param_7 == 0) goto LAB_00185f24;
  }
  else {
    if ((*(int *)(inst2[0x22] + 8) == 0x9a) && (inst2[0x2c] == inst2[0x32])) {
      IRInst__swapOperands(inst2,1,2,*(uint *)(program + 8));
      param_2 = 0;
      goto LAB_00185ea8;
    }
    if (param_7 == 0) goto LAB_00185f24;
    loopIndex = (**(code **)(*inst + 0x60))(inst);
    if (loopIndex != 0) {
      return 0;
    }
    IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
  }
  uVar8 = local_68;
  loopIndex = IRInst__getOperandRecord(inst,operandIndex);
  *(undefined4 *)(loopIndex + 0x10) = uVar8;
  IRInst__setOperandSource(inst,operandIndex,inst2,0,*(undefined4 *)(program + 8));
LAB_00185f24:
  bVar2 = param_7 != 0;
  FUN_000f32cc(&local_54,local_68);
  inst2[0x27] = local_54;
  if ((param_8 != 0) && (loopIndex = SchedModel__instructionFitsAlone(inst,*(undefined4 *)(program + 8)), loopIndex == 0)) {
    loopIndex = 0;
    for (loopIndex2 = 1; loopRemaining = (**(code **)(*inst + 0x14))(inst), loopIndex2 <= loopRemaining;
        loopIndex2 = loopIndex2 + 1) {
      loopRemaining = FUN_000f3b10(inst,loopIndex2);
      if (loopRemaining != 0) {
        loopRemaining = loopIndex + 1;
        loopIndex = loopIndex + 2;
        if (loopIndex2 != operandIndex) {
          loopIndex = loopRemaining;
        }
      }
      FUN_000f3b68(inst,loopIndex2);
    }
    if (3 < loopIndex) {
      for (loopIndex = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex <= loopIndex2;
          loopIndex = loopIndex + 1) {
        if (operandIndex == loopIndex) {
          loopIndex2 = (**(code **)(*inst3 + 100))(inst3);
          if (loopIndex2 != 0) {
            operandVReg = (int *)IRInst__getOperandSource(inst3,1);
            goto LAB_0018601c;
          }
        }
        else {
          operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
LAB_0018601c:
          loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
          local_64[0] = *(int *)(loopIndex2 + 0x10);
          loopIndex2 = SelectWord__isSplat(local_64[0]);
          if (loopIndex2 != 0) {
            loopIndex2 = FUN_0011379c(*(undefined4 *)(program + 8),operandVReg);
            if ((loopIndex2 == 0) || (loopIndex2 = IRInst__hasSingleUse(operandVReg,program), loopIndex2 == 0)) {
              bVar1 = false;
            }
            else {
              loopIndex2 = FUN_000f2cac(local_64[0]);
              operandVReg[0x27] = 0x1010100;
              for (loopRemaining = 1; iVar6 = (**(code **)(*operandVReg + 0x14))(operandVReg), loopRemaining <= iVar6;
                  loopRemaining = loopRemaining + 1) {
                pcVar10 = *(code **)(*operandVReg + 0x88);
                iVar6 = IRInst__getOperandRecord(operandVReg,loopRemaining);
                (*pcVar10)(operandVReg,loopRemaining,3,*(undefined1 *)(loopIndex2 + iVar6 + 0x10));
                (**(code **)(*operandVReg + 0x88))(operandVReg,loopRemaining,loopIndex2,4);
              }
              loopIndex2 = 0;
              loopRemaining = 4;
              do {
                if (*(char *)((int)local_64 + loopIndex2) != '\x04') {
                  *(undefined1 *)((int)local_64 + loopIndex2) = 3;
                }
                iVar6 = local_64[0];
                loopIndex2 = loopIndex2 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
              if (loopIndex == 0) {
                bVar1 = true;
                inst[0x27] = local_64[0];
              }
              else {
                loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
                bVar1 = true;
                *(int *)(loopIndex2 + 0x10) = iVar6;
              }
            }
            loopIndex2 = OpcodeTraits__flagBit8(*(undefined4 *)(operandVReg[0x22] + 8),*(undefined4 *)(program + 8));
            if (loopIndex2 != 0) {
              loopIndex2 = IRInst__hasSingleUse(operandVReg,program);
              if (loopIndex2 == 0) {
                *(undefined1 *)((int)operandVReg + 0x9f) = 0;
              }
              else {
                operandVReg[0x27] = 0x1010100;
              }
              loopIndex2 = 0;
              loopRemaining = 4;
              do {
                if (*(char *)((int)local_64 + loopIndex2) != '\x04') {
                  *(undefined1 *)((int)local_64 + loopIndex2) = 3;
                }
                iVar6 = local_64[0];
                loopIndex2 = loopIndex2 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
              if (loopIndex == 0) {
                inst[0x27] = local_64[0];
              }
              else {
                loopIndex2 = IRInst__getOperandRecord(inst,loopIndex);
                *(int *)(loopIndex2 + 0x10) = iVar6;
              }
LAB_001861f8:
              if (loopIndex == operandIndex) {
                inst2[0x27] = 0x1010100;
                for (loopIndex = 1; loopIndex2 = (**(code **)(*inst2 + 0x14))(inst2), loopIndex <= loopIndex2;
                    loopIndex = loopIndex + 1) {
                  if (loopIndex == 0) {
                    inst2[0x27] = 0x4040404;
                  }
                  else {
                    loopIndex2 = IRInst__getOperandRecord(inst2,loopIndex);
                    *(undefined4 *)(loopIndex2 + 0x10) = 0x4040404;
                  }
                  (**(code **)(*inst2 + 0x88))(inst2,loopIndex,3,3);
                }
              }
              break;
            }
            if (bVar1) goto LAB_001861f8;
          }
        }
      }
    }
  }
  loopIndex = SchedModel__instructionFitsAlone(inst,*(undefined4 *)(program + 8));
  if ((loopIndex == 0) && (param_8 != 0)) {
    if (bVar2) {
      if (param_10 == 0) {
        IRInst__setOperandSource(inst,operandIndex,inst3,0,*(undefined4 *)(program + 8));
      }
      else {
        IRInst__setOperandSource(inst,operandIndex,param_10,0,*(undefined4 *)(program + 8));
      }
      loopIndex = IRInst__getOperandRecord(inst,operandIndex);
      *(undefined4 *)(loopIndex + 0x10) = uVar7;
      if ((param_2 != 0) && ((inst[operandIndex * 6 + 0x28] & 2U) == 0)) {
        IROperand__setModifierBits(inst + operandIndex * 6 + 0x23,1,inst[operandIndex * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (param_10 == 0) {
      inst3[0x54] = *(int *)(program + 0x474) + -1;
    }
    else {
      *(int *)(param_10 + 0x150) = *(int *)(program + 0x474) + -1;
    }
    uVar7 = 0;
    *(int *)(program + 0x208) = *(int *)(program + 0x208) + 1;
  }
  else {
    if (bVar2) {
      *(int *)(program + 0x200) = *(int *)(program + 0x200) + 1;
      Block__insertInstBefore(inst[0x56],inst,inst2);
      inst2[0x58] = *(int *)(program + 0x478) + 1;
    }
    loopIndex = IRInst__getOperandRecord(inst2,0);
    WriteMask__fromSelectWord(&local_50,*(undefined4 *)(loopIndex + 0x10));
    SelectWord__maskUnused(local_4c,0x10203,local_50);
    if (0 < inst2[0x21]) {
      loopIndex = 1;
      do {
        if (bVar2) {
          loopIndex2 = IRInst__getOperandSource(inst2,loopIndex);
          if (*(int *)(program + 0x478) < *(int *)(loopIndex2 + 0x160)) {
            *(int *)(loopIndex2 + 0x160) = *(int *)(loopIndex2 + 0x160) + 1;
          }
          else {
            *(int *)(loopIndex2 + 0x160) = *(int *)(program + 0x478) + 1;
          }
        }
        loopIndex2 = (**(code **)(*inst2 + 0x14))(inst2);
        if (loopIndex <= loopIndex2) {
          if (loopIndex == 0) {
            inst2[0x27] = local_4c[0];
          }
          else {
            loopIndex2 = IRInst__getOperandRecord(inst2,loopIndex);
            *(int *)(loopIndex2 + 0x10) = local_4c[0];
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst2[0x21]);
    }
    if (bVar2) {
      if (param_10 == 0) {
        inst3[5] = inst3[5] | 0x40000;
        IRInst__dropCounterAndDeleteIfUnused(inst3,*(undefined4 *)(program + 8));
      }
      else {
        *(uint *)(param_10 + 0x14) = *(uint *)(param_10 + 0x14) | 0x40000;
        IRInst__dropCounterAndDeleteIfUnused(param_10,*(undefined4 *)(program + 8));
        DList__unlink(inst3);
      }
    }
    uVar7 = 1;
    if (param_9 != (undefined4 *)0x0) {
      *param_9 = inst2;
    }
  }
  return uVar7;
}

