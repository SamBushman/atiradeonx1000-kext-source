#include "decls.h"

/* ValueKey__canonicalizeCommutativeOperands @ 0x1733a0 (156 bytes) */
int ValueKey__canonicalizeCommutativeOperands(ctx)
  int ctx;
{
  int flagBit0Result;
  int iVar1;
  int loopIndex;
  int loopRemaining;
  
  flagBit0Result = OpcodeTraits__flagBit0(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(ctx + 0x238));
  if (flagBit0Result != 0) {
    loopRemaining = 4;
    iVar1 = ctx;
    loopIndex = ctx;
    do {
      if (*(char *)(loopIndex + 0x228) != '\0') {
        if (*(int *)(iVar1 + 0x178) < *(int *)(iVar1 + 0x188)) {
          return 0;
        }
        if (*(int *)(iVar1 + 0x188) < *(int *)(iVar1 + 0x178)) {
          ValueKey__swapSources12(*(undefined4 *)(ctx + 0xb0),ctx + 0x210,
                       *(undefined4 *)(ctx + 0x238));
          return 1;
        }
      }
      loopIndex = loopIndex + 1;
      iVar1 = iVar1 + 4;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
  }
  return 0;
}

/* FUN_0017343c @ 0x17343c (304 bytes) */
int FUN_0017343c(ctx, param_2)
  int ctx;
  int param_2;
{
  int vcall18Result;
  int iVar1;
  int iVar2;
  int *a0;
  uint uVar3;
  
  a0 = *(int **)(*(int *)(ctx + 0xb0) + 0x8c);
  vcall18Result = (**(code **)(*a0 + 0x18))(a0,param_2);
  if (vcall18Result != 0) {
    iVar2 = *(int *)(ctx + 0xb0);
    uVar3 = a0[7];
    iVar1 = *(int *)(param_2 + 0x128);
    if ((((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) && (*(int *)(iVar2 + 0x120) == 0)) &&
        ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) &&
       (((*(uint *)(iVar2 + 0xb8) & 1) != 0 && ((*(uint *)(iVar2 + 0xd0) & 1) == 0)))) {
      iVar2 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(iVar2 + 0xa8) = *(int *)(iVar2 + 0xa8) + 1;
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,0);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xbc,1,1);
      iVar1 = (uVar3 >> 3 & 0x1ffffffc) + iVar1;
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x200000;
      *(uint *)(iVar1 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)(iVar1 + 8);
      return;
    }
    iVar1 = (uVar3 >> 3 & 0x1ffffffc) + iVar1;
    *(uint *)(iVar1 + 8) =
         (-2 << (uVar3 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar3 & 0x1f)) & *(uint *)(iVar1 + 8);
  }
  return;
}

/* FUN_0017356c @ 0x17356c (176 bytes) */
int FUN_0017356c(ctx)
  int ctx;
{
  int callResult;
  int loopIndex;
  
  callResult = OpcodeTraits__flagBit7(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(ctx + 0x238));
  if (callResult == 0) {
    loopIndex = 1;
    callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (callResult != 0) {
      while( true ) {
        callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
        if (callResult < loopIndex) {
          return 1;
        }
        callResult = ((int (*)())ValueKey__rowLanesAllEqual)(ctx,loopIndex);
        if (callResult == 0) break;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return 0;
}

/* IRInst__isCndFloatOp @ 0x17361c (28 bytes) */
int IRInst__isCndFloatOp(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x24U < 3;
}

/* FUN_00173638 @ 0x173638 (284 bytes) */
int FUN_00173638(ctx)
  int ctx;
{
  int inst;
  int operandRecord;
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  inst = *(int *)(ctx + 0xb0);
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x77) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    if (*(int *)(operandRecord + 0x10) == DAT_001b01b4) {
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0xfffffff7;
      piVar3 = *(int **)(ctx + 0xb0);
      iVar2 = *(int *)(ctx + 0x238);
      pcVar1 = *(code **)(*piVar3 + 0xc);
      goto LAB_00173718;
    }
    inst = *(int *)(ctx + 0xb0);
  }
  if ((((*(uint *)(inst + 0x14) & 2) == 0) || (*(int *)(inst + 0x98) != 0x3b)) ||
     (*(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x334) != 0)) {
    return 0;
  }
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffffef;
  iVar2 = *(int *)(ctx + 0x238);
  if ((*(uint *)(*(int *)(iVar2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    Program__removeInst(*(int *)(iVar2 + 0x6c4),*(undefined4 *)(ctx + 0xb0));
    iVar2 = *(int *)(ctx + 0x238);
  }
  piVar3 = *(int **)(ctx + 0xb0);
  pcVar1 = *(code **)(*piVar3 + 0xc);
LAB_00173718:
  (*pcVar1)(piVar3,0,iVar2);
  *(uint *)(*(int *)(ctx + 0xb0) + 0x14) = *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x400;
  return 1;
}

/* FUN_00173754 @ 0x173754 (280 bytes) */
int FUN_00173754(ctx, param_2)
  int ctx;
  int param_2;
{
  int inst;
  int loopIndex;
  int loopRemaining;
  undefined4 uVar4;
  undefined4 local_28;
  undefined4 local_24 [6];
  
  inst = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  if (((inst == 0) ||
      (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8))) ||
     (inst = *(int *)(param_2 + 0xb0), (*(uint *)(inst + 0x14) & 1) == 0)) {
LAB_00173854:
    uVar4 = 0;
  }
  else {
    loopIndex = IRInst__getOperandRecord(inst,0);
    local_28 = *(undefined4 *)(loopIndex + 0x10);
    loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopIndex = 0;
    local_24[0] = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = 4;
    do {
      if ((*(char *)((int)local_24 + loopIndex) == '\0') &&
         (*(char *)((int)local_24 + loopIndex + -4) == '\x01')) goto LAB_00173854;
      loopIndex = loopIndex + 1;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopIndex + 0xa8) = *(int *)(loopIndex + 0xa8) + 1;
    loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopIndex + 0x140) = *(int *)(loopIndex + 0x140) + 1;
    FUN_0017d06c(ctx,inst,&DAT_001b01bc,0);
    uVar4 = 1;
  }
  return uVar4;
}

/* ValueKey__fillSourceLaneUsage @ 0x17386c (204 bytes) */
int ValueKey__fillSourceLaneUsage(ctx)
  int ctx;
{
  undefined4 inst2;
  int *a0;
  undefined4 inst;
  int loopIndex;
  int callResult;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_28 [4];
  
  a0 = *(int **)(ctx + 0xb0);
  if (*(int *)(a0[0x22] + 8) == 0x8e) {
    inst = (**(code **)(*a0 + 0x7c))(a0);
    loopIndex = IRInst__allSourcesDefined(inst);
    if (loopIndex == 0) {
      return;
    }
    a0 = *(int **)(ctx + 0xb0);
  }
  loopIndex = 1;
  iVar5 = ctx;
  while( true ) {
    callResult = (**(code **)(*a0 + 0x14))(a0);
    if (callResult < loopIndex) break;
    inst2 = *(undefined4 *)(ctx + 0xb0);
    uVar4 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4);
    callResult = IRInst__getOperandRecord(inst2,0);
    IRInst__computeSourceLaneMask(local_28,inst2,loopIndex,uVar4,*(undefined4 *)(callResult + 0x10));
    a0 = *(int **)(ctx + 0xb0);
    *(undefined4 *)(iVar5 + 0x228) = local_28[0];
    loopIndex = loopIndex + 1;
    iVar5 = iVar5 + 4;
  }
  return;
}

/* ValueKey__init @ 0x173938 (136 bytes) */
int ValueKey__init(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *loopPtr;
  int loopRemaining;
  
  loopRemaining = 4;
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  loopPtr = param_1;
  do {
    loopPtr[8] = 0;
    loopPtr[4] = 0;
    *loopPtr = 0;
    loopPtr[0x1c] = 0;
    loopPtr[0x18] = 0;
    loopPtr[0x14] = 0;
    loopPtr[0x28] = 0;
    loopPtr[0x24] = 0;
    loopPtr[0x20] = 0;
    loopPtr[0xc] = 0;
    loopPtr[0x10] = 0;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  return ((int (*)())ValueKey__fillSourceLaneUsage)(param_1);
}

/* ValueKey__initCopy @ 0x1739c0 (136 bytes) */
int ValueKey__initCopy(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *loopPtr;
  int loopRemaining;
  
  loopRemaining = 4;
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  loopPtr = param_1;
  do {
    loopPtr[8] = 0;
    loopPtr[4] = 0;
    *loopPtr = 0;
    loopPtr[0x1c] = 0;
    loopPtr[0x18] = 0;
    loopPtr[0x14] = 0;
    loopPtr[0x28] = 0;
    loopPtr[0x24] = 0;
    loopPtr[0x20] = 0;
    loopPtr[0xc] = 0;
    loopPtr[0x10] = 0;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  return ((int (*)())ValueKey__fillSourceLaneUsage)(param_1);
}

/* FUN_00173a48 @ 0x173a48 (176 bytes) */
int FUN_00173a48(inst, compiler)
  int *inst;
  undefined4 compiler;
{
  int callResult;
  int loopIndex;
  
  callResult = OpcodeTraits__flagBit7(*(undefined4 *)(inst[0x22] + 8),compiler);
  if (callResult == 0) {
    loopIndex = 1;
    callResult = (**(code **)(*inst + 0x14))(inst);
    if (callResult != 0) {
      while( true ) {
        callResult = (**(code **)(*inst + 0x14))(inst);
        if (callResult < loopIndex) {
          return 1;
        }
        callResult = IRInst__getOperandRecord(inst,loopIndex);
        callResult = SelectWord__isSplat(*(undefined4 *)(callResult + 0x10));
        if (callResult == 0) break;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return 0;
}

/* FUN_00173af8 @ 0x173af8 (160 bytes) */
int FUN_00173af8(ctx, param_2)
  int ctx;
  int *param_2;
{
  bool moreComponents;
  int loopIndex;
  int operandRecord;
  undefined4 local_38 [9];
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) &&
     (loopIndex = FUN_0011379c(*(undefined4 *)(ctx + 0x238),*(int *)(ctx + 0xb0)), loopIndex != 0))
  {
    loopIndex = 0;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      local_38[0] = *(undefined4 *)(operandRecord + 0x10);
      if ((*(char *)((int)local_38 + loopIndex) == '\0') && (*param_2 != 0)) {
        return;
      }
      moreComponents = loopIndex != 3;
      param_2 = param_2 + 1;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
  }
  return;
}

/* Program__eliminateRedundantInst @ 0x173b98 (324 bytes) */
int Program__eliminateRedundantInst(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  
  if (*(int *)(param_2[0x22] + 8) == 0x8e) {
    iVar3 = param_4;
    Block__recordDefinition(param_3,param_2[0x23],param_1);
    (**(code **)(*param_2 + 0xc))
              (param_2,0,*(undefined4 *)(param_4 + 8),iVar3,in_r7,in_r8,*(code **)(*param_2 + 0xc));
    uVar1 = 1;
    param_2[5] = param_2[5] | 0x400;
    *(int *)(param_4 + 0x150) = *(int *)(param_4 + 0x150) + 1;
  }
  else if (((param_2[5] & 8U) == 0) && ((param_2[5] & 0x10U) == 0)) {
    iVar3 = param_4;
    if ((((param_2[0x20] != 0) && (iVar2 = RegKind__flagBit0(param_2[0x26]), iVar2 != 0)) &&
        ((param_2[5] & 2U) == 0)) && (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0))
    {
      Block__recordDefinition(param_3,param_2[0x23],param_1);
    }
    (**(code **)(*param_2 + 0xc))
              (param_2,0,*(undefined4 *)(param_4 + 8),iVar3,in_r7,in_r8,*(code **)(*param_2 + 0xc));
    uVar1 = 1;
    param_2[5] = param_2[5] | 0x400;
    *(int *)(param_4 + 0x14c) = *(int *)(param_4 + 0x14c) + 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_00173cdc @ 0x173cdc (308 bytes) */
int FUN_00173cdc(ctx, param_2)
  int ctx;
  int param_2;
{
  int isOptionEnabled;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint vectorFilledCount;
  uint uVar6;
  uint *vector;
  undefined4 local_38 [4];
  undefined4 local_28 [4];
  
  isOptionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),8);
  if ((isOptionEnabled == 0) ||
     (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8))) {
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xb0);
    if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
      vector = *(uint **)(*(int *)(iVar1 + 0x8c) + 0x2c);
      vectorFilledCount = vector[1];
      uVar6 = vectorFilledCount - 1;
      if (uVar6 < *vector) {
        if (vectorFilledCount <= uVar6) {
          _memset(vectorFilledCount * 4 + vector[2],0,(uVar6 - vectorFilledCount) * 4 + 4);
          vector[1] = vectorFilledCount;
        }
        piVar2 = (int *)(uVar6 * 4 + vector[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(vector,uVar6);
      }
      iVar1 = *(int *)(*piVar2 + 0xb0);
    }
    ValueKey__computeSwizzleTo(local_28,ctx,param_2);
    local_38[0] = local_28[0];
    iVar4 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0xa8) = *(int *)(iVar4 + 0xa8) + 1;
    iVar4 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0x13c) = *(int *)(iVar4 + 0x13c) + 1;
    FUN_0017d06c(ctx,iVar1,local_38,0);
    uVar3 = 1;
  }
  return uVar3;
}

/* Compiler__valueNumberForExpr @ 0x173e10 (268 bytes) */
int Compiler__valueNumberForExpr(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 arenaAt378;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint vectorFilledCount;
  undefined4 nextNegativeValueNumberResult;
  uint *vector;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4) = 0;
  **(undefined4 **)(param_1 + 0x3f0) = param_2;
  puVar1 = (undefined4 *)
           HashTable__find(*(undefined4 *)(param_1 + 0x3e4),*(undefined4 *)(param_1 + 0x3f0));
  if (puVar1 == (undefined4 *)0x0) {
    arenaAt378 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)Arena__alloc(arenaAt378,0x2c);
    puVar1 = puVar2 + 1;
    *puVar2 = arenaAt378;
    puVar2[1] = param_2;
    puVar2[5] = 4;
    puVar2[8] = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 0xd) = 0;
    puVar2[4] = 0;
    puVar2[7] = 0;
    nextNegativeValueNumberResult = Compiler__nextNegativeValueNumber(param_1);
    puVar2[2] = nextNegativeValueNumberResult;
    HashTable__insert(*(undefined4 *)(param_1 + 0x3e4),puVar1);
    HashTable__insert(*(undefined4 *)(param_1 + 0x3e0),puVar1);
    vector = *(uint **)(param_1 + 0x3d8);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      piVar3 = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* ValueKey__fill @ 0x173f1c (1680 bytes) */
int ValueKey__fill(ctx)
  int ctx;
{
  undefined8 operandSource;
  bool moreComponents;
  dword *operandIndex2;
  bool bVar1;
  undefined4 *puVar2;
  int loopIndex;
  undefined4 uVar4;
  int loopIndex2;
  int *loopPtr6;
  int loopRemaining;
  undefined4 *loopPtr8;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  dword *in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  int loopIndex3;
  dword dVar10;
  dword *operandIndex;
  uint uVar12;
  int *loopPtr5;
  uint uVar14;
  uint *loopPtr7;
  char *loopPtr4;
  undefined8 vcall14Result;
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  loopPtr5 = *(int **)(ctx + 0xb0);
  *(undefined4 *)(ctx + 0xb4) = *(undefined4 *)(loopPtr5[0x22] + 8);
  if (loopPtr5[0x20] != 0) {
    loopIndex = RegKind__flagBit0(loopPtr5[0x26]);
    if (((loopIndex == 0) || ((loopPtr5[5] & 2U) != 0)) ||
       (loopIndex = (**(code **)(*loopPtr5 + 0x50))(loopPtr5), loopIndex != 0)) {
      loopPtr5 = *(int **)(ctx + 0xb0);
    }
    else {
      loopPtr5 = *(int **)(ctx + 0xb0);
      if ((loopPtr5[5] & 0x40U) == 0) {
        *(undefined4 *)(ctx + 0xb8) = 0;
        *(undefined4 *)(ctx + 0xbc) = 0;
        goto LAB_00173fa0;
      }
    }
    *(int *)(ctx + 0xbc) = loopPtr5[0x25];
    *(int *)(ctx + 0xb8) = loopPtr5[0x26];
  }
LAB_00173fa0:
  *(int *)(ctx + 0xc0) = loopPtr5[0x48];
  *(int *)(ctx + 0xc4) = loopPtr5[0x49];
  loopIndex = 1;
  loopIndex3 = ctx;
  while( true ) {
    loopIndex2 = (**(code **)(*loopPtr5 + 0x14))(loopPtr5);
    if (loopIndex2 < loopIndex) break;
    uVar4 = IRInst__getDefiningField128(*(undefined4 *)(ctx + 0xb0),loopIndex);
    loopPtr5 = *(int **)(ctx + 0xb0);
    *(undefined4 *)(loopIndex3 + 0x1bc) = uVar4;
    loopIndex = loopIndex + 1;
    loopIndex3 = loopIndex3 + 4;
  }
  loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 0x7c))(*(int **)(ctx + 0xb0));
  if (loopIndex == 0) {
    loopIndex = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                         *(undefined4 *)(ctx + 0x238));
    if (loopIndex != 0) {
      operandIndex = ((unsigned char *)0x0);
      loopIndex = OpcodeTraits__flagBit9(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238));
      if (loopIndex == 0) {
        while( true ) {
          operandIndex = (dword *)((int)operandIndex + 1);
          loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
          uVar4 = extraout_r4_00;
          if (loopIndex < (int)operandIndex) break;
          loopIndex = *(int *)(ctx + 0xb0);
          loopPtr7 = *(uint **)(*(int *)((int)operandIndex * 0x18 + loopIndex + 0x8c) + 0x2c);
          uVar12 = loopPtr7[1];
          uVar14 = uVar12 - 1;
          if (uVar14 < *loopPtr7) {
            if (uVar12 <= uVar14) {
              _memset(uVar12 * 4 + loopPtr7[2],0,(uVar14 - uVar12) * 4 + 4);
              loopPtr7[1] = uVar12;
              loopIndex = *(int *)(ctx + 0xb0);
            }
            in_r5 = (dword *)(uVar14 * 4 + loopPtr7[2]);
          }
          else {
            in_r5 = (dword *)Vector__elementRefGrow(loopPtr7,uVar14);
            loopIndex = *(int *)(ctx + 0xb0);
          }
          dVar10 = *in_r5;
          loopIndex = IRInst__getOperandRecord(loopIndex,operandIndex);
          local_58[0] = *(undefined4 *)(loopIndex + 0x10);
          loopPtr5 = (int *)((int)operandIndex * 0x10 + ctx + 0x168);
          loopPtr7 = (uint *)((int)operandIndex * 0x20 + ctx + 200);
          loopIndex = 0;
          do {
            if (*(byte *)((int)local_58 + loopIndex) != 4) {
              loopIndex3 = *(int *)((uint)*(byte *)((int)local_58 + loopIndex) * 4 + dVar10 + 0x20);
              if (loopIndex3 < 0) {
                loopPtr8 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),loopIndex3);
                IRInst__applyAbsModifier(&local_48,*(undefined4 *)(ctx + 0xb0),operandIndex,*loopPtr8);
                in_r5 = operandIndex;
                in_r6 = local_48;
                IRInst__applyNegateModifier(&local_44,*(undefined4 *)(ctx + 0xb0),operandIndex,local_48);
                loopIndex3 = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),local_44);
                loopIndex3 = *(int *)(loopIndex3 + 4);
              }
              else {
                loopIndex2 = *(int *)(ctx + 0xb0) + (int)operandIndex * 0x18 + 0x80;
                *loopPtr7 = *(uint *)(loopIndex2 + 0x20) & 1;
                loopPtr7[4] = *(uint *)(loopIndex2 + 0x20) >> 1 & 1;
              }
              *loopPtr5 = loopIndex3;
            }
            moreComponents = loopIndex != 3;
            loopPtr5 = loopPtr5 + 1;
            loopPtr7 = loopPtr7 + 1;
            loopIndex = loopIndex + 1;
          } while (moreComponents);
        }
        goto LAB_00174410;
      }
    }
    loopPtr5 = *(int **)(ctx + 0xb0);
    operandIndex2 = ((unsigned char *)0x0);
    while( true ) {
      operandIndex2 = (dword *)((int)operandIndex2 + 1);
      vcall14Result = (**(code **)(*loopPtr5 + 0x14))(loopPtr5);
      uVar4 = (undefined4)vcall14Result;
      if ((int)((ulonglong)vcall14Result >> 0x20) < (int)operandIndex2) break;
      loopPtr5 = *(int **)(ctx + 0xb0);
      loopPtr7 = *(uint **)(loopPtr5[(int)operandIndex2 * 6 + 0x23] + 0x2c);
      uVar14 = loopPtr7[1];
      uVar12 = uVar14 - 1;
      if (uVar12 < *loopPtr7) {
        if (uVar14 <= uVar12) {
          in_r5 = (dword *)((uVar12 - uVar14) * 4 + 4);
          _memset(uVar14 * 4 + loopPtr7[2],0,in_r5);
          loopPtr7[1] = uVar14;
          loopPtr5 = *(int **)(ctx + 0xb0);
        }
        loopPtr6 = (int *)(uVar12 * 4 + loopPtr7[2]);
      }
      else {
        loopPtr6 = (int *)Vector__elementRefGrow(loopPtr7,uVar12);
        loopPtr5 = *(int **)(ctx + 0xb0);
      }
      loopIndex3 = *loopPtr6;
      loopPtr4 = (char *)((int)operandIndex2 * 4 + ctx + 0x224);
      loopPtr6 = (int *)((int)operandIndex2 * 0x10 + ctx + 0x168);
      loopPtr7 = (uint *)((int)operandIndex2 * 0x20 + ctx + 200);
      loopIndex2 = 0;
      loopIndex = ctx;
      do {
        if (*loopPtr4 != '\0') {
          loopRemaining = IRInst__getOperandRecord(loopPtr5,operandIndex2);
          uVar12 = (uint)*(byte *)(loopIndex2 + loopRemaining + 0x10);
          if (uVar12 == 4) {
            loopPtr5 = *(int **)(ctx + 0xb0);
            *(undefined4 *)(loopIndex + 0x30) = 0;
            *(undefined4 *)(loopIndex + 0x40) = 0;
          }
          else {
            loopRemaining = *(int *)(uVar12 * 4 + loopIndex3 + 0x20);
            if (loopRemaining < 0) {
              loopPtr8 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),loopRemaining);
              IRInst__applyAbsModifier(&local_40,*(undefined4 *)(ctx + 0xb0),operandIndex2,*loopPtr8);
              in_r5 = operandIndex2;
              in_r6 = local_40;
              IRInst__applyNegateModifier(local_3c,*(undefined4 *)(ctx + 0xb0),operandIndex2,local_40);
              loopRemaining = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),local_3c[0]);
              loopPtr5 = *(int **)(ctx + 0xb0);
              loopRemaining = *(int *)(loopRemaining + 4);
            }
            else {
              loopPtr5 = *(int **)(ctx + 0xb0);
              *loopPtr7 = loopPtr5[(int)operandIndex2 * 6 + 0x28] & 1;
              loopPtr7[4] = (uint)loopPtr5[(int)operandIndex2 * 6 + 0x28] >> 1 & 1;
            }
            *loopPtr6 = loopRemaining;
          }
        }
        bVar1 = loopIndex2 != 3;
        loopPtr4 = loopPtr4 + 1;
        loopIndex = loopIndex + 4;
        loopPtr6 = loopPtr6 + 1;
        loopPtr7 = loopPtr7 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
  }
  else {
    loopIndex3 = 1;
    uVar4 = extraout_r4;
    if (0 < *(int *)(loopIndex + 0x84)) {
      do {
        operandSource = IRInst__getOperandSource(loopIndex,loopIndex3);
        uVar4 = (undefined4)operandSource;
        if ((int)((ulonglong)operandSource >> 0x20) == 0) {
          loopIndex2 = 4;
          loopPtr8 = (undefined4 *)(loopIndex3 * 0x10 + ctx + 0x168);
          do {
            *loopPtr8 = 0;
            loopPtr8 = loopPtr8 + 1;
            loopIndex2 = loopIndex2 + -1;
          } while (loopIndex2 != 0);
        }
        else {
          loopRemaining = 4;
          loopPtr8 = (undefined4 *)(loopIndex3 * 0x10 + ctx + 0x168);
          loopIndex2 = 0;
          do {
            puVar2 = (undefined4 *)(loopIndex2 + *(int *)(loopIndex3 * 4 + *(int *)(loopIndex + 0x138)));
            loopIndex2 = loopIndex2 + 4;
            *loopPtr8 = *puVar2;
            loopPtr8 = loopPtr8 + 1;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
        }
        loopIndex3 = loopIndex3 + 1;
      } while (loopIndex3 <= *(int *)(loopIndex + 0x84));
    }
  }
LAB_00174410:
  loopPtr5 = *(int **)(ctx + 0xb0);
  loopIndex2 = loopPtr5[0x4c];
  loopIndex3 = loopPtr5[0x4d];
  loopIndex = loopPtr5[0x4e];
  *(int *)(ctx + 0x1cc) = loopPtr5[0x4b];
  *(int *)(ctx + 0x1d0) = loopIndex2;
  *(int *)(ctx + 0x1d4) = loopIndex3;
  *(int *)(ctx + 0x1d8) = loopIndex;
  loopIndex2 = loopPtr5[0x4f];
  loopIndex3 = loopPtr5[0x50];
  loopIndex = loopPtr5[0x51];
  *(int *)(ctx + 0x1e8) = loopPtr5[0x52];
  *(int *)(ctx + 0x1dc) = loopIndex2;
  *(int *)(ctx + 0x1e0) = loopIndex3;
  *(int *)(ctx + 0x1e4) = loopIndex;
  loopIndex = (**(code **)(*loopPtr5 + 0x30))
                    (loopPtr5,uVar4,in_r5,in_r6,in_r7,loopIndex,ctx + 0x1cc,loopIndex3);
  if (loopIndex == 0) {
    loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 0x5c))(*(int **)(ctx + 0xb0));
    if (loopIndex == 0) {
      loopIndex = FUN_00172fb8(ctx);
      if (loopIndex == 0) {
        loopPtr5 = *(int **)(ctx + 0xb0);
        if ((*(int *)(loopPtr5[0x22] + 8) == 0xf7) || (*(int *)(loopPtr5[0x22] + 8) == 0xb4)) {
          *(int *)(ctx + 0x1d4) = loopPtr5[0x53];
        }
      }
      else {
        loopPtr5 = *(int **)(ctx + 0xb0);
        *(int *)(ctx + 0x1d4) = loopPtr5[0x53];
      }
    }
    else {
      loopPtr5 = *(int **)(ctx + 0xb0);
      *(undefined1 *)(ctx + 0x1ec) = 1;
    }
  }
  else {
    *(undefined4 *)(ctx + 0x1dc) = 0;
    _memcpy(ctx + 0x1ec,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x13c),0x24);
    loopPtr5 = *(int **)(ctx + 0xb0);
  }
  loopIndex = (**(code **)(*loopPtr5 + 0x74))(loopPtr5);
  if (loopIndex != 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = *(undefined4 *)(ctx + 0x188);
  }
  loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 0x78))(*(int **)(ctx + 0xb0));
  if (loopIndex != 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = *(undefined4 *)(ctx + 0x188);
  }
  return;
}

/* ValueKey__rebuild @ 0x1745ac (68 bytes) */
int ValueKey__rebuild(valueKey)
  int valueKey;
{
  _memset(valueKey + 0xb4,0,0x15c);
  ((int (*)())ValueKey__fillSourceLaneUsage)(valueKey);
  return ((int (*)())ValueKey__fill)(valueKey);
}

/* FUN_001745f0 @ 0x1745f0 (216 bytes) */
int FUN_001745f0(ctx)
  int ctx;
{
  int callResult;
  undefined4 uVar2;
  
  callResult = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  uVar2 = 0;
  if (callResult != 0) {
    callResult = ValueKey__canonicalizeConstantSources(ctx);
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    do {
      callResult = FUN_0017f7ec(ctx);
    } while (callResult != 0);
    callResult = FUN_0017b96c(ctx);
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    callResult = (**(code **)(**(int **)(ctx + 0xb0) + 0x24))(*(int **)(ctx + 0xb0));
    if ((callResult != 0) && (callResult = ValueKey__mixLiteralSources(ctx), callResult != 0)) {
      ((int (*)())ValueKey__rebuild)(ctx);
    }
    callResult = ValueKey__simplifyModifiersAndAddressing(ctx);
    uVar2 = 1;
    if (callResult != 0) {
      ((int (*)())ValueKey__rebuild)(ctx);
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_001746c8 @ 0x1746c8 (252 bytes) */
int FUN_001746c8(compiler, param_2)
  int compiler;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *allocation;
  int *piVar3;
  uint vectorFilledCount;
  undefined4 arena;
  uint *vector;
  
  **(undefined4 **)(compiler + 0x3f4) = param_2;
  puVar1 = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + COMP_pointerSet),*(undefined4 *)(compiler + 0x3f4));
  if (puVar1 == (undefined4 *)0x0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x34);
    puVar1 = allocation + 1;
    *allocation = arena;
    allocation[3] = 0xffffffff;
    allocation[0xc] = 0;
    allocation[2] = 0;
    allocation[4] = 0;
    allocation[5] = 0;
    allocation[6] = 0;
    allocation[7] = 0;
    allocation[9] = 0;
    allocation[10] = 0;
    allocation[0xb] = 0;
    allocation[1] = param_2;
    allocation[8] = 0;
    HashTable__insert(*(undefined4 *)(compiler + COMP_pointerSet),puVar1);
    vector = *(uint **)(compiler + 0x3dc);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      piVar3 = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_001747c4 @ 0x1747c4 (196 bytes) */
int FUN_001747c4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint vectorFilledCount;
  undefined4 *puVar2;
  int callResult;
  int iVar4;
  uint *vector;
  
  if (param_3 <= (int)param_2) {
    iVar4 = param_2 << 2;
    do {
      vector = *(uint **)(param_4 + 0x40c);
      if (param_2 < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= param_2) {
          _memset(vectorFilledCount * 4 + vector[2],0,(param_2 - vectorFilledCount) * 4 + 4);
          vector[1] = param_2 + 1;
        }
        puVar2 = (undefined4 *)(iVar4 + vector[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(vector,param_2);
      }
      callResult = HashTable__find(*puVar2,param_1);
      if (callResult != 0) {
        return callResult;
      }
      param_2 = param_2 - 1;
      iVar4 = iVar4 + -4;
    } while (param_3 <= (int)param_2);
  }
  return 0;
}

/* FUN_00174888 @ 0x174888 (196 bytes) */
int FUN_00174888(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint vectorFilledCount;
  undefined4 *puVar2;
  int callResult;
  int iVar4;
  uint *vector;
  
  if (param_3 <= (int)param_2) {
    iVar4 = param_2 << 2;
    do {
      vector = *(uint **)(param_4 + 0x408);
      if (param_2 < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= param_2) {
          _memset(vectorFilledCount * 4 + vector[2],0,(param_2 - vectorFilledCount) * 4 + 4);
          vector[1] = param_2 + 1;
        }
        puVar2 = (undefined4 *)(iVar4 + vector[2]);
      }
      else {
        puVar2 = (undefined4 *)Vector__elementRefGrow(vector,param_2);
      }
      callResult = HashTable__find(*puVar2,param_1);
      if (callResult != 0) {
        return callResult;
      }
      param_2 = param_2 - 1;
      iVar4 = iVar4 + -4;
    } while (param_3 <= (int)param_2);
  }
  return 0;
}

/* FUN_0017494c @ 0x17494c (440 bytes) */
int FUN_0017494c(ctx, param_2, param_3)
  int ctx;
  undefined4 param_2;
  undefined4 param_3;
{
  bool moreComponents;
  int iVar2;
  undefined4 *allocation;
  int operandRecord;
  int *piVar5;
  int loopIndex;
  uint vectorFilledCount;
  undefined4 arena;
  undefined4 *loopPtr2;
  uint uVar10;
  uint *vector;
  
  iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),9);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(ctx + 0x238),
     *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8) < *(int *)(iVar2 + 0x658))) {
    arena = *(undefined4 *)(iVar2 + 0x378);
    loopIndex = 0;
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    *allocation = arena;
    allocation[0x2d] = *(undefined4 *)(ctx + 0xb0);
    loopPtr2 = allocation + 1;
    iVar2 = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
        loopPtr2[8] = 3;
      }
      else {
        loopPtr2[8] = *(undefined4 *)(iVar2 + 0x20);
      }
      moreComponents = loopIndex != 3;
      loopPtr2 = loopPtr2 + 1;
      iVar2 = iVar2 + 4;
      loopIndex = loopIndex + 1;
    } while (moreComponents);
    iVar2 = ((int (*)())FUN_00174888)(allocation + 1,param_2,param_3,
                         *(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4));
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0xb0);
      if ((*(uint *)(iVar2 + 0x14) & 1) == 0) {
        vector = *(uint **)(*(int *)(iVar2 + 0x8c) + 0x2c);
        vectorFilledCount = vector[1];
        uVar10 = vectorFilledCount - 1;
        if (uVar10 < *vector) {
          if (vectorFilledCount <= uVar10) {
            _memset(vectorFilledCount * 4 + vector[2],0,(uVar10 - vectorFilledCount) * 4 + 4);
            vector[1] = vectorFilledCount;
          }
          piVar5 = (int *)(uVar10 * 4 + vector[2]);
        }
        else {
          piVar5 = (int *)Vector__elementRefGrow(vector,uVar10);
        }
        iVar2 = *(int *)(*piVar5 + 0xb0);
      }
      loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(loopIndex + 0xa8) = *(int *)(loopIndex + 0xa8) + 1;
      loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
      *(int *)(loopIndex + 0x144) = *(int *)(loopIndex + 0x144) + 1;
      FUN_0017d06c(ctx,iVar2,&DAT_001b01bc,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_00174b04 @ 0x174b04 (476 bytes) */
int FUN_00174b04(ctx, param_2, param_3)
  int ctx;
  uint param_2;
  int param_3;
{
  int vcall18Result;
  int vcall14Result;
  uint vectorFilledCount;
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint loopIndex2;
  int iVar7;
  uint uVar8;
  int iVar9;
  int loopIndex;
  uint *vector;
  uint uVar12;
  uint uVar13;
  
  loopIndex = 1;
  iVar9 = 0x18;
  piVar2 = *(int **)(ctx + 0xb0);
  vector = *(uint **)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x410);
  do {
    vcall14Result = (**(code **)(*piVar2 + 0x14))(piVar2);
    if (vcall14Result < loopIndex) {
      return;
    }
    piVar2 = *(int **)(iVar9 + *(int *)(ctx + 0xb0) + 0x8c);
    vcall18Result = (**(code **)(*piVar2 + 0x18))(piVar2);
    if ((vcall18Result != 0) && (uVar8 = piVar2[7], param_3 <= (int)param_2)) {
      iVar5 = param_2 << 2;
      uVar12 = param_2;
      do {
        if (uVar12 < *vector) {
          vectorFilledCount = vector[1];
          if (vectorFilledCount <= uVar12) {
            _memset(vectorFilledCount * 4 + vector[2],0,(uVar12 - vectorFilledCount) * 4 + 4);
            vector[1] = uVar12 + 1;
          }
          piVar4 = (int *)(iVar5 + vector[2]);
        }
        else {
          piVar4 = (int *)Vector__elementRefGrow(vector,uVar12);
        }
        iVar7 = *(int *)(*piVar4 + 0xc4);
        uVar3 = *(uint *)(iVar7 + 4);
        if (0 < (int)uVar3) {
          loopIndex2 = 0;
          uVar13 = uVar3;
          do {
            piVar1 = (int *)0x0;
            if (loopIndex2 < uVar3) {
              piVar1 = (int *)(loopIndex2 * 4 + *(int *)(iVar7 + 8));
            }
            if (piVar2 == (int *)*piVar1) {
              if ((*(uint *)((uVar8 >> 3 & 0x1ffffffc) + *(int *)(*piVar4 + 0x128) + 8) >>
                   (uVar8 & 0x1f) & 1) != 0) {
                piVar2 = *(int **)(ctx + 0xb0);
                if ((*(uint *)((int)piVar2 + iVar9 + 0xa0) & 2) == 0) {
                  iVar5 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
                  *(int *)(iVar5 + 0xa8) = *(int *)(iVar5 + 0xa8) + 1;
                  iVar5 = *(int *)(ctx + 0xb0) + iVar9 + 0x80;
                  IROperand__setModifierBits(iVar5 + 0xc,1,*(uint *)(iVar5 + 0x20) & 1 ^ 1);
                  piVar2 = *(int **)(ctx + 0xb0);
                }
                goto LAB_00174ca8;
              }
              break;
            }
            loopIndex2 = loopIndex2 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
        uVar12 = uVar12 - 1;
        iVar5 = iVar5 + -4;
      } while (param_3 <= (int)uVar12);
    }
    piVar2 = *(int **)(ctx + 0xb0);
LAB_00174ca8:
    loopIndex = loopIndex + 1;
    iVar9 = iVar9 + 0x18;
  } while( true );
}

/* FUN_00174ce0 @ 0x174ce0 (300 bytes) */
int FUN_00174ce0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 arenaAt378;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 nextValueNumberResult;
  uint vectorFilledCount;
  uint *vector;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 4) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 8) = param_2;
  puVar1 = (undefined4 *)
           HashTable__find(*(undefined4 *)(param_1 + 0x3ec),*(undefined4 *)(param_1 + 0x3f4));
  if (puVar1 == (undefined4 *)0x0) {
    arenaAt378 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)Arena__alloc(arenaAt378,0x34);
    puVar1 = puVar2 + 1;
    *puVar2 = arenaAt378;
    puVar2[3] = 0xffffffff;
    puVar2[8] = 0;
    puVar2[1] = 0;
    puVar2[0xc] = 0;
    puVar2[2] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    nextValueNumberResult = Compiler__nextValueNumber(param_1);
    puVar2[2] = param_3;
    puVar2[1] = nextValueNumberResult;
    puVar2[3] = param_2;
    HashTable__insert(*(undefined4 *)(param_1 + 1000),puVar1);
    HashTable__insert(*(undefined4 *)(param_1 + 0x3ec),puVar1);
    vector = *(uint **)(param_1 + 0x3dc);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      piVar3 = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00174e0c @ 0x174e0c (2764 bytes) */
int FUN_00174e0c(valueKey)
  int *valueKey;
{
  int returnZero_172f24Result;
  bool isLast;
  bool moreComponents;
  undefined4 inst2;
  int inst;
  undefined4 nextValueNumberResult;
  int operandRecord;
  undefined4 uVar1;
  int loopIndex2;
  int *loopPtr4;
  undefined4 *exprRecordForValueNumberResultB;
  float *exprRecordForValueNumberResult;
  int iVar6;
  uint loopIndex5;
  bool bVar8;
  int iVar9;
  int loopIndex;
  int *loopPtr3;
  int loopRemaining;
  int local_68 [5];
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c [3];
  float local_30;
  
  loopPtr3 = (int *)valueKey[0x2c];
  local_68[0] = 1;
  local_68[1] = 1;
  local_68[2] = 1;
  local_68[3] = 1;
  if (*(int *)(loopPtr3[0x22] + 8) == 0x8e) {
    inst2 = (**(code **)(*loopPtr3 + 0x7c))(loopPtr3);
    loopIndex2 = IRInst__allSourcesDefined(inst2);
    if (loopIndex2 == 0) goto LAB_00174efc;
    loopPtr3 = (int *)valueKey[0x2c];
  }
  loopIndex2 = IRInst__isProjectionOfOpcode2a(loopPtr3);
  if ((((loopIndex2 != 0) || (loopIndex2 = IRInst__isProjectionOfClass26or3a(valueKey[0x2c]), loopIndex2 != 0)) ||
      (loopPtr3 = (int *)valueKey[0x2c], *(int *)(loopPtr3[0x22] + 8) == 0xb4)) ||
     ((loopIndex2 = (**(code **)(*loopPtr3 + 0x6c))(loopPtr3), loopIndex2 != 0 ||
      (loopIndex2 = (**(code **)(*(int *)valueKey[0x2c] + 0x58))((int *)valueKey[0x2c]), loopIndex2 != 0)))) {
LAB_00174efc:
    loopIndex2 = 0;
    loopPtr3 = valueKey;
    do {
      iVar9 = valueKey[0x8e];
      nextValueNumberResult = Compiler__nextValueNumber(iVar9);
      loopPtr4 = (int *)((int (*)())FUN_001746c8)(iVar9,nextValueNumberResult);
      loopPtr4[2] = loopIndex2;
      loopPtr4[1] = (int)valueKey;
      HashTable__insert(*(undefined4 *)(valueKey[0x8e] + 1000),loopPtr4);
      HashTable__insert(*(undefined4 *)(valueKey[0x8e] + 0x3ec),loopPtr4);
      moreComponents = loopIndex2 != 3;
      loopIndex2 = loopIndex2 + 1;
      *loopPtr3 = *loopPtr4;
      loopPtr3 = loopPtr3 + 1;
    } while (moreComponents);
    return;
  }
  loopIndex2 = (**(code **)(*(int *)valueKey[0x2c] + 0x60))((int *)valueKey[0x2c]);
  if (loopIndex2 != 0) {
    inst = valueKey[0x2c];
    loopIndex2 = 0;
    loopPtr3 = valueKey;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (*(char *)(loopIndex2 + operandRecord + 0x10) == '\x01') {
        inst = valueKey[0x2c];
      }
      else {
        inst = valueKey[0x2c];
        if (0 < *(int *)(inst + 0x84)) {
          loopIndex = 1;
          loopPtr4 = valueKey + loopIndex2 + 0x5e;
          do {
            operandRecord = IRInst__getOperandRecord(inst,loopIndex);
            if (*(char *)(loopIndex2 + operandRecord + 0x10) != '\x04') {
              inst = valueKey[0x2c];
              *loopPtr3 = *loopPtr4;
              break;
            }
            inst = valueKey[0x2c];
            loopIndex = loopIndex + 1;
            loopPtr4 = loopPtr4 + 4;
          } while (loopIndex <= *(int *)(inst + 0x84));
        }
      }
      isLast = loopIndex2 == 3;
      loopPtr3 = loopPtr3 + 1;
      loopIndex2 = loopIndex2 + 1;
      if (isLast) {
        loopIndex2 = 0;
        loopPtr3 = valueKey;
        while( true ) {
          operandRecord = IRInst__getOperandRecord(inst,0);
          if (*(char *)(loopIndex2 + operandRecord + 0x10) == '\x01') {
            *loopPtr3 = 2;
          }
          isLast = loopIndex2 == 3;
          loopPtr3 = loopPtr3 + 1;
          loopIndex2 = loopIndex2 + 1;
          if (isLast) break;
          inst = valueKey[0x2c];
        }
        return;
      }
    } while( true );
  }
  loopIndex2 = (**(code **)(*(int *)valueKey[0x2c] + 0x50))((int *)valueKey[0x2c]);
  if (loopIndex2 != 0) {
    loopIndex2 = 4;
    loopPtr3 = valueKey;
    do {
      *loopPtr3 = 1;
      loopPtr3 = loopPtr3 + 1;
      loopIndex2 = loopIndex2 + -1;
    } while (loopIndex2 != 0);
    goto LAB_001757ec;
  }
  loopIndex2 = (**(code **)(*(int *)valueKey[0x2c] + 0x48))((int *)valueKey[0x2c]);
  if (loopIndex2 == 0) {
    loopIndex2 = valueKey[0x2c];
  }
  else {
    loopIndex2 = valueKey[0x2c];
    iVar9 = *(int *)(loopIndex2 + 0x98);
    if (((iVar9 == 2) || (iVar9 == 0xc)) || (iVar9 == 0x33)) {
      loopIndex5 = 0;
      loopPtr3 = valueKey;
      while( true ) {
        if (((int)*(char *)(loopIndex2 + 0x15c) >> (loopIndex5 & 0x3f) & 1U) == 0) {
          loopPtr4 = (int *)((int (*)())FUN_00174ce0)(valueKey[0x8e],loopIndex5,valueKey);
          loopPtr3[0x10] = (int)loopPtr4;
          *loopPtr3 = *loopPtr4;
        }
        else {
          loopIndex2 = FUN_00179064(valueKey,loopIndex5);
          *loopPtr3 = *(int *)(loopIndex2 + 4);
        }
        isLast = loopIndex5 == 3;
        loopPtr3 = loopPtr3 + 1;
        loopIndex5 = loopIndex5 + 1;
        if (isLast) break;
        loopIndex2 = valueKey[0x2c];
      }
      goto LAB_001757ec;
    }
  }
  loopIndex2 = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(loopIndex2 + 0x88) + 8),valueKey[0x8e]);
  if ((((loopIndex2 == 0) ||
       (loopIndex2 = OpcodeTraits__flagBit9(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]),
       loopIndex2 != 0)) &&
      (loopIndex2 = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]),
      loopIndex2 == 0)) &&
     ((loopIndex2 = ((int (*)())FUN_00173a48)(valueKey[0x2c],valueKey[0x8e]), loopIndex2 == 0 &&
      (loopIndex2 = ((int (*)())FUN_0017356c)(valueKey), loopIndex2 == 0)))) {
    loopIndex2 = valueKey[0x2c];
    returnZero_172f24Result = returnZero_172f24(loopIndex2);
    if (returnZero_172f24Result == 0) {
      uVar1 = 0;
      loopIndex = 0;
      iVar9 = 0;
      loopPtr3 = valueKey;
      do {
        loopIndex2 = IRInst__getOperandRecord(loopIndex2,0);
        if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
          loopPtr4 = (int *)valueKey[0x2c];
          if (*(int *)(loopPtr4[0x22] + 8) == 0x8e) {
            loopIndex2 = FUN_00179bbc(valueKey,loopIndex);
            if (loopIndex2 == 0) {
              loopPtr4 = (int *)((int (*)())FUN_00174ce0)(valueKey[0x8e],loopIndex,valueKey);
              loopIndex2 = *loopPtr4;
            }
            else {
              loopIndex2 = loopPtr3[0x5e];
            }
            *loopPtr3 = loopIndex2;
          }
          else {
            loopIndex2 = (**(code **)(*loopPtr4 + 100))(loopPtr4);
            if (loopIndex2 == 0) {
              loopIndex2 = ((int (*)())IRInst__isCndFloatOp)(valueKey[0x2c]);
              if ((loopIndex2 == 0) || (-1 < loopPtr3[0x5e])) {
                if (loopPtr3[0xc] != 0) {
                  *loopPtr3 = *(int *)(loopPtr3[0xc] + 4);
                  goto LAB_001757d8;
                }
              }
              else {
                exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopPtr3[0x5e]);
                local_30 = *exprRecordForValueNumberResult;
                loopIndex2 = ((bool (*)())evaluateCompareFloats)(valueKey[0x2c],(double)local_30,0.0);
                loopIndex2 = (loopIndex2 == 0) + 2;
                loopRemaining = valueKey[loopIndex2 * 4 + loopIndex + 0x5a];
                if (loopRemaining < 0) {
                  exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopRemaining);
                  IRInst__scaleByOutputScale(&local_40,valueKey[0x2c],*exprRecordForValueNumberResultB);
                  loopIndex2 = local_40;
                  IRInst__clampOutputValue(local_3c,valueKey[0x2c],local_40);
                  loopRemaining = local_3c[0];
                  if (local_3c[0] != loopIndex2) goto LAB_001756e4;
                  goto LAB_001756ec;
                }
                iVar6 = valueKey[0x2c];
                if ((((*(int *)(iVar6 + 0x120) == 0) && (*(int *)(iVar6 + 0x124) == 0)) &&
                    (loopIndex5 = *(uint *)(loopIndex2 * 0x18 + iVar6 + 0xa0), (loopIndex5 & 1) == 0)) &&
                   ((loopIndex5 & 2) == 0)) goto LAB_00175760;
              }
LAB_001757a0:
              FUN_00178648(valueKey,loopIndex);
              FUN_00178338(valueKey,loopIndex,local_68);
              loopPtr4 = (int *)loopPtr3[0x10];
              *loopPtr3 = *loopPtr4;
              loopPtr3[0x20] = loopPtr4[3];
              loopPtr3[0x14] = loopPtr4[4];
            }
            else {
              loopRemaining = loopPtr3[0x5e];
              if (loopRemaining < 0) {
                exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopRemaining);
                IRInst__scaleByOutputScale(&local_48,valueKey[0x2c],*exprRecordForValueNumberResultB);
                loopIndex2 = local_48;
                IRInst__clampOutputValue(&local_44,valueKey[0x2c],local_48);
                loopRemaining = local_44;
                if (local_44 != loopIndex2) {
LAB_001756e4:
                  uVar1 = 1;
                  loopIndex2 = loopRemaining;
                }
LAB_001756ec:
                loopIndex2 = ((int (*)())Compiler__valueNumberForExpr)(valueKey[0x8e],loopIndex2);
                loopRemaining = *(int *)(loopIndex2 + 4);
                loopIndex2 = IRInst__getOperandRecord(valueKey[0x2c],0);
                if (*(char *)(loopIndex + loopIndex2 + 0x10) == '\0') {
                  *(undefined4 *)((int)local_68 + iVar9) = uVar1;
                }
                *loopPtr3 = loopRemaining;
              }
              else {
                loopIndex2 = valueKey[0x2c];
                if (((*(int *)(loopIndex2 + 0x120) != 0) || (*(int *)(loopIndex2 + 0x124) != 0)) ||
                   (((*(uint *)(loopIndex2 + 0xb8) & 1) != 0 || ((*(uint *)(loopIndex2 + 0xb8) & 2) != 0))))
                goto LAB_001757a0;
LAB_00175760:
                *loopPtr3 = loopRemaining;
                loopIndex2 = FUN_00176ed4(valueKey,loopRemaining);
                loopPtr3[0x20] = loopIndex2;
                loopIndex2 = FUN_00176f0c(valueKey,loopRemaining);
                loopPtr3[0x14] = loopIndex2;
              }
            }
          }
        }
LAB_001757d8:
        isLast = loopIndex == 3;
        iVar9 = iVar9 + 4;
        loopPtr3 = loopPtr3 + 1;
        loopIndex = loopIndex + 1;
        if (isLast) goto LAB_001757ec;
        loopIndex2 = valueKey[0x2c];
      } while( true );
    }
  }
  else {
    loopIndex2 = valueKey[0x2c];
  }
  loopIndex2 = IRInst__getOperandRecord(loopIndex2,0);
  iVar9 = 0;
  if (*(int *)(loopIndex2 + 0x10) != 0x1010101) {
    loopIndex2 = IRInst__getOperandRecord(valueKey[0x2c],0);
    iVar9 = SelectWord__firstWrittenComponent(*(undefined4 *)(loopIndex2 + 0x10));
  }
  loopIndex2 = (**(code **)(*(int *)valueKey[0x2c] + 100))((int *)valueKey[0x2c]);
  if (loopIndex2 == 0) {
    loopIndex2 = ((int (*)())IRInst__isCndFloatOp)(valueKey[0x2c]);
    if (loopIndex2 == 0) {
      loopIndex2 = (valueKey + iVar9)[0xc];
      if (loopIndex2 != 0) {
LAB_0017547c:
        loopIndex = *(int *)(loopIndex2 + 4);
        loopIndex2 = 0;
        iVar9 = 0;
        goto LAB_001754f8;
      }
      FUN_00178648(valueKey,iVar9);
      FUN_00178338(valueKey,iVar9,local_68);
      loopIndex = 4;
      loopIndex2 = 0;
      loopPtr3 = valueKey;
      do {
        loopPtr3[0x10] = (valueKey + iVar9)[0x10];
        loopPtr3 = loopPtr3 + 1;
        *(int *)((int)local_68 + loopIndex2) = local_68[iVar9];
        loopIndex2 = loopIndex2 + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
    }
    else {
      loopPtr3 = valueKey + iVar9;
      if (loopPtr3[0x5e] < 0) {
        exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopPtr3[0x5e]);
        local_30 = *exprRecordForValueNumberResult;
        loopIndex2 = ((bool (*)())evaluateCompareFloats)(valueKey[0x2c],(double)local_30,0.0);
        loopIndex2 = (loopIndex2 == 0) + 2;
        loopIndex = valueKey[loopIndex2 * 4 + iVar9 + 0x5a];
        if (loopIndex < 0) {
          bVar8 = false;
          exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopIndex);
          IRInst__scaleByOutputScale(&local_50,valueKey[0x2c],*exprRecordForValueNumberResultB);
          IRInst__clampOutputValue(&local_4c,valueKey[0x2c],local_50);
          local_54 = local_4c;
          if (local_4c != local_50) goto LAB_00175348;
          goto LAB_00175350;
        }
        loopRemaining = valueKey[0x2c];
        if (((*(int *)(loopRemaining + 0x120) == 0) && (*(int *)(loopRemaining + 0x124) == 0)) &&
           ((loopIndex5 = *(uint *)(loopIndex2 * 0x18 + loopRemaining + 0xa0), (loopIndex5 & 1) == 0 && ((loopIndex5 & 2) == 0)
            ))) goto LAB_001753c0;
        FUN_00178648(valueKey,iVar9);
        FUN_00178338(valueKey,iVar9,local_68);
        loopIndex2 = 4;
        loopIndex = 0;
        loopPtr3 = valueKey;
        do {
          loopPtr3[0x10] = (valueKey + iVar9)[0x10];
          loopPtr3 = loopPtr3 + 1;
          *(int *)((int)local_68 + loopIndex) = local_68[iVar9];
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + -1;
        } while (loopIndex2 != 0);
      }
      else {
        loopIndex2 = loopPtr3[0xc];
        if (loopIndex2 != 0) goto LAB_0017547c;
        FUN_00178648(valueKey,iVar9);
        FUN_00178338(valueKey,iVar9,local_68);
        loopIndex = 4;
        loopIndex2 = 0;
        loopPtr4 = valueKey;
        do {
          loopPtr4[0x10] = loopPtr3[0x10];
          loopPtr4 = loopPtr4 + 1;
          *(int *)((int)local_68 + loopIndex2) = local_68[iVar9];
          loopIndex2 = loopIndex2 + 4;
          loopIndex = loopIndex + -1;
        } while (loopIndex != 0);
      }
    }
    loopPtr3 = (int *)(valueKey + iVar9)[0x10];
    iVar9 = loopPtr3[4];
    loopIndex = *loopPtr3;
    loopIndex2 = loopPtr3[3];
  }
  else {
    loopIndex = valueKey[iVar9 + 0x5e];
    if (loopIndex < 0) {
      bVar8 = false;
      exprRecordForValueNumberResultB = (undefined4 *)Compiler__exprRecordForValueNumber(valueKey[0x8e],loopIndex);
      IRInst__scaleByOutputScale(local_68 + 4,valueKey[0x2c],*exprRecordForValueNumberResultB);
      IRInst__clampOutputValue(&local_54,valueKey[0x2c],local_68[4]);
      local_50 = local_68[4];
      if (local_54 != local_68[4]) {
LAB_00175348:
        bVar8 = true;
        local_50 = local_54;
      }
LAB_00175350:
      loopIndex2 = ((int (*)())Compiler__valueNumberForExpr)(valueKey[0x8e],local_50);
      loopIndex = *(int *)(loopIndex2 + 4);
      if ((*(int *)(valueKey[0x2c] + 0x120) == 0) || (bVar8)) {
        loopIndex2 = 0;
        iVar9 = 0;
      }
      else {
        loopIndex2 = 0;
        iVar9 = 0;
        *(undefined4 *)(valueKey[0x2c] + 0x120) = 0;
      }
    }
    else {
      loopIndex2 = valueKey[0x2c];
      if ((((*(int *)(loopIndex2 + 0x120) == 0) && (*(int *)(loopIndex2 + 0x124) == 0)) &&
          ((*(uint *)(loopIndex2 + 0xb8) & 1) == 0)) && ((*(uint *)(loopIndex2 + 0xb8) & 2) == 0)) {
LAB_001753c0:
        loopIndex2 = FUN_00176ed4(valueKey,loopIndex);
        iVar9 = FUN_00176f0c(valueKey,loopIndex);
      }
      else {
        FUN_00178648(valueKey,iVar9);
        FUN_00178338(valueKey,iVar9,local_68);
        loopPtr3 = (int *)valueKey[iVar9 + 0x10];
        iVar9 = loopPtr3[4];
        loopIndex = *loopPtr3;
        loopIndex2 = loopPtr3[3];
      }
    }
  }
LAB_001754f8:
  loopRemaining = 4;
  loopPtr3 = valueKey;
  do {
    *loopPtr3 = loopIndex;
    loopPtr3[0x20] = loopIndex2;
    loopPtr3[0x14] = iVar9;
    loopPtr3 = loopPtr3 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
LAB_001757ec:
  ((int (*)())FUN_00173af8)(valueKey,local_68);
  FUN_0017729c(valueKey);
  FUN_001771b0(valueKey);
  return;
}

/* FUN_001758d8 @ 0x1758d8 (356 bytes) */
int FUN_001758d8(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint vectorFilledCount2;
  uint *vector2;
  undefined4 *foundEntry;
  undefined4 uVar1;
  undefined4 *loopPtr;
  uint vectorFilledCount;
  undefined4 *puVar4;
  uint *vector;
  uint uVar6;
  int loopRemaining;
  
  if (param_3 <= (int)param_2) {
    loopRemaining = param_2 << 2;
    uVar6 = param_2;
    do {
      vector = *(uint **)(param_4 + 0x404);
      if (uVar6 < *vector) {
        vectorFilledCount = vector[1];
        if (vectorFilledCount <= uVar6) {
          _memset(vectorFilledCount * 4 + vector[2],0,(uVar6 - vectorFilledCount) * 4 + 4);
          vector[1] = uVar6 + 1;
        }
        puVar4 = (undefined4 *)(loopRemaining + vector[2]);
      }
      else {
        puVar4 = (undefined4 *)Vector__elementRefGrow(vector,uVar6);
      }
      foundEntry = (undefined4 *)HashTable__find(*puVar4,param_1);
      if (foundEntry != (undefined4 *)0x0) {
        loopRemaining = 4;
        loopPtr = foundEntry;
        do {
          uVar1 = *loopPtr;
          loopPtr = loopPtr + 1;
          *param_1 = uVar1;
          param_1 = param_1 + 1;
          loopRemaining = loopRemaining + -1;
        } while (loopRemaining != 0);
        return foundEntry;
      }
      uVar6 = uVar6 - 1;
      loopRemaining = loopRemaining + -4;
    } while (param_3 <= (int)uVar6);
  }
  ((int (*)())FUN_00174e0c)(param_1);
  vector2 = *(uint **)(param_4 + 0x404);
  if (param_2 < *vector2) {
    vectorFilledCount2 = vector2[1];
    if (vectorFilledCount2 <= param_2) {
      _memset(vectorFilledCount2 * 4 + vector2[2],0,(param_2 - vectorFilledCount2) * 4 + 4);
      vector2[1] = param_2 + 1;
    }
    puVar4 = (undefined4 *)(param_2 * 4 + vector2[2]);
  }
  else {
    puVar4 = (undefined4 *)Vector__elementRefGrow(vector2,param_2);
  }
  HashTable__insert(*puVar4,param_1);
  return (undefined4 *)0x0;
}

/* FUN_00175a3c @ 0x175a3c (260 bytes) */
undefined4 * FUN_00175a3c(int compiler,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  undefined4 *puVar1;
  undefined4 *allocation;
  int *piVar3;
  uint vectorFilledCount;
  undefined4 arena;
  uint *vector;
  
  *(undefined4 *)(*(int *)(compiler + 0x3f0) + 4) = param_3;
  **(float **)(compiler + 0x3f0) = (float)fparam_1;
  puVar1 = (undefined4 *)
           HashTable__find(*(undefined4 *)(compiler + 0x3e4),*(undefined4 *)(compiler + 0x3f0));
  if (puVar1 == (undefined4 *)0x0) {
    arena = *(undefined4 *)(compiler + 0x378);
    allocation = (undefined4 *)Arena__alloc(arena,0x2c);
    puVar1 = allocation + 1;
    *allocation = arena;
    allocation[1] = (float)fparam_1;
    allocation[5] = 4;
    allocation[8] = 0;
    *(undefined1 *)(allocation + 3) = 0;
    *(undefined1 *)((int)allocation + 0xd) = 0;
    allocation[4] = 0;
    allocation[7] = 0;
    allocation[2] = param_3;
    HashTable__insert(*(undefined4 *)(compiler + 0x3e4),puVar1);
    HashTable__insert(*(undefined4 *)(compiler + 0x3e0),puVar1);
    vector = *(uint **)(compiler + 0x3d8);
    vectorFilledCount = vector[1];
    if (vectorFilledCount < *vector) {
      _memset(vectorFilledCount * 4 + vector[2],0,4);
      piVar3 = (int *)(vectorFilledCount * 4 + vector[2]);
      vector[1] = vectorFilledCount + 1;
    }
    else {
      piVar3 = (int *)Vector__elementRefGrow(vector,vectorFilledCount);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00175b40 @ 0x175b40 (620 bytes) */
int FUN_00175b40(valueKey)
  undefined4 *valueKey;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int loopRemaining;
  int *piVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int loopIndex;
  uint vectorFilledCount;
  int iVar11;
  uint *vector;
  undefined4 *loopPtr2;
  undefined4 local_38 [7];
  
  loopRemaining = valueKey[0x2c];
  if ((*(uint *)(loopRemaining + 0x14) & 0x200) == 0) {
    loopRemaining = 4;
    do {
      valueKey[4] = 1;
      valueKey = valueKey + 1;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
  }
  else {
    vector = *(uint **)(*(int *)(*(int *)(loopRemaining + 0x84) * 0x18 + loopRemaining + 0x8c) + 0x2c);
    vectorFilledCount = vector[1];
    uVar8 = vectorFilledCount - 1;
    if (uVar8 < *vector) {
      if (vectorFilledCount <= uVar8) {
        _memset(vectorFilledCount * 4 + vector[2],0,(uVar8 - vectorFilledCount) * 4 + 4);
        vector[1] = vectorFilledCount;
        loopRemaining = valueKey[0x2c];
      }
      piVar5 = (int *)(uVar8 * 4 + vector[2]);
    }
    else {
      piVar5 = (int *)Vector__elementRefGrow(vector,uVar8);
      loopRemaining = valueKey[0x2c];
    }
    iVar11 = *piVar5;
    loopRemaining = IRInst__getOperandRecord(loopRemaining,0);
    loopIndex = 0;
    local_38[0] = *(undefined4 *)(loopRemaining + 0x10);
    loopPtr2 = valueKey;
    do {
      uVar7 = *(undefined4 *)(iVar11 + 0x20);
      if (((*(char *)((int)local_38 + loopIndex) == '\x01') &&
          (loopRemaining = ((int (*)())Ptr__equalNonNull)(*loopPtr2,uVar7), loopRemaining != 0)) &&
         (loopRemaining = (**(code **)(*(int *)valueKey[0x2c] + 100))((int *)valueKey[0x2c]), loopRemaining == 0)) {
        loopRemaining = OpcodeTraits__flagBit2(*(undefined4 *)(*(int *)(valueKey[0x2c] + 0x88) + 8),valueKey[0x8e]);
        if (loopRemaining == 0) {
LAB_00175c7c:
          iVar6 = *(int *)(valueKey[0x2c] + 0x88);
          loopRemaining = OpcodeTraits__flagBit8(*(undefined4 *)(iVar6 + 8),valueKey[0x8e]);
          if (loopRemaining == 0) goto LAB_00175ce8;
        }
        else {
          iVar6 = *(int *)(valueKey[0x2c] + 0x88);
          loopRemaining = OpcodeTraits__flagBit9(*(undefined4 *)(iVar6 + 8),valueKey[0x8e]);
          if (loopRemaining != 0) goto LAB_00175c7c;
        }
        loopRemaining = Compiler__isOptionEnabled(valueKey[0x8e],0x30);
        if (((loopRemaining == 0) || (loopIndex != 3)) &&
           (loopRemaining = FUN_00113734(valueKey[0x8e],valueKey[0x2c],piVar5,in_r6,in_r7,in_r8,iVar6),
           loopRemaining == 0)) {
          *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) =
               *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) + 1;
          *(undefined1 *)(loopIndex + valueKey[0x2c] + 0x9c) = 0;
        }
      }
LAB_00175ce8:
      bVar1 = loopIndex != 3;
      uVar2 = *(undefined4 *)(iVar11 + 0x70);
      uVar3 = *(undefined4 *)(iVar11 + 0xa0);
      loopIndex = loopIndex + 1;
      loopPtr2[4] = uVar7;
      iVar11 = iVar11 + 4;
      loopPtr2[0x18] = uVar2;
      loopPtr2[0x24] = uVar3;
      loopPtr2 = loopPtr2 + 1;
    } while (bVar1);
    loopRemaining = IRInst__writesAllLanes(valueKey[0x2c]);
    if ((loopRemaining == 0) && (loopRemaining = IRInst__isProjectionOfOpcode2a(valueKey[0x2c]), loopRemaining == 0)) {
      *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) =
           *(int *)(*(int *)(valueKey[0x8e] + 0x6c4) + 0xa8) + 1;
      loopRemaining = valueKey[0x2c];
      IRInst__setOperandSource(loopRemaining,*(undefined4 *)(loopRemaining + 0x84),0,0,valueKey[0x8e]);
      *(int *)(loopRemaining + 0x84) = *(int *)(loopRemaining + 0x84) + -1;
      *(uint *)(loopRemaining + 0x14) = *(uint *)(loopRemaining + 0x14) & 0xfffffdff;
    }
  }
  return;
}

/* Program__valueNumberInst @ 0x175dac (1208 bytes) */
int Program__valueNumberInst(program, valueNumber, param_3, keyRef, param_5)
  int program;
  uint valueNumber;
  undefined4 param_3;
  int *keyRef;
  undefined4 param_5;
{
  int valueKey2;
  int currentDefinition2;
  int currentDefinition;
  int valueKey;
  uint *vector2;
  int inst;
  int eliminateRedundantInstResult;
  int canonicalizeCommutativeOperandsResult;
  int valueNumberEnabled;
  int iVar1;
  int iVar2;
  uint vectorFilledCount;
  undefined4 *vectorElementRef;
  undefined4 result;
  int *keyInst2;
  int keyInst;
  uint *vector;
  
  valueNumberEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),7);
  if ((valueNumberEnabled == 0) || (*(int *)(*(int *)(program + 8) + 0x654) <= *(int *)(program + 0x14c))) {
LAB_00176244:
    result = 0;
  }
  else {
    ValueKey__maybeRefineSources(*keyRef);
    ((int (*)())ValueKey__fill)(*keyRef);
    valueKey = *keyRef;
    if (*(int *)(*(int *)(*(int *)(valueKey + 0xb0) + 0x88) + 8) == 0x8e) {
LAB_00175e58:
      valueKey = ((int (*)())FUN_00173638)(valueKey);
      if (valueKey == 0) {
        FUN_00180154(*keyRef);
        canonicalizeCommutativeOperandsResult = ((int (*)())ValueKey__canonicalizeCommutativeOperands)(*keyRef);
        if (canonicalizeCommutativeOperandsResult != 0) {
          ((int (*)())ValueKey__rebuild)(*keyRef);
        }
        iVar1 = ((int (*)())FUN_001758d8)(*keyRef,valueNumber,param_3,program);
        ((int (*)())FUN_00175b40)(*keyRef);
        ValueKey__propagateLaneValues(*keyRef);
        iVar2 = ((int (*)())FUN_00174888)(*keyRef,valueNumber,param_3,program);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(**(int **)(*keyRef + 0xb0) + 100))(*(int **)(*keyRef + 0xb0));
          if ((((iVar2 == 0) &&
               (iVar2 = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))
                                  (*(int **)(*keyRef + 0xb0)), iVar2 == 0)) &&
              (iVar2 = FUN_00172fb8(*keyRef), iVar2 == 0)) &&
             (iVar2 = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),8), iVar2 != 0)) {
            iVar2 = ((int (*)())FUN_001747c4)(*keyRef,valueNumber,param_3,program);
            if ((iVar2 != 0) && (iVar2 = ((int (*)())FUN_00173cdc)(*keyRef,iVar2), iVar2 != 0)) {
              keyInst = *(int *)(*keyRef + 0xb0);
              currentDefinition2 = VReg__currentDefinition(*(undefined4 *)(keyInst + 0xa4),*(undefined4 *)(program + 0x3a0),
                                   *(uint *)(program + 8));
              if ((keyInst == *(int *)(currentDefinition2 + 0xb0)) &&
                 (currentDefinition2 = Program__tryEliminateRedundantCopy(program,*(undefined4 *)(*keyRef + 0xb0),param_5), currentDefinition2 != 0
                 )) goto LAB_0017624c;
              goto LAB_001760e4;
            }
            valueKey2 = *keyRef;
            keyInst2 = *(int **)(valueKey2 + 0xb0);
            if (keyInst2[0x20] != 0) {
              iVar2 = RegKind__flagBit0(keyInst2[0x26]);
              if (((iVar2 == 0) || ((keyInst2[5] & 2U) != 0)) ||
                 (iVar2 = (**(code **)(*keyInst2 + 0x50))(keyInst2), iVar2 != 0)) goto LAB_001760e4;
              vector = *(uint **)(program + 0x40c);
              if (valueNumber < *vector) {
                vectorFilledCount = vector[1];
                if (vectorFilledCount <= valueNumber) {
                  _memset(vectorFilledCount * 4 + vector[2],0,(valueNumber - vectorFilledCount) * 4 + 4);
                  vector[1] = valueNumber + 1;
                }
                vectorElementRef = (undefined4 *)(valueNumber * 4 + vector[2]);
              }
              else {
                vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector,valueNumber);
              }
              HashTable__insert(*vectorElementRef,*keyRef);
              valueKey2 = *keyRef;
            }
          }
          else {
LAB_001760e4:
            valueKey2 = *keyRef;
          }
          valueKey2 = (**(code **)(**(int **)(valueKey2 + 0xb0) + 100))(*(int **)(valueKey2 + 0xb0));
          if ((((valueKey2 == 0) &&
               (valueKey2 = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))
                                  (*(int **)(*keyRef + 0xb0)), valueKey2 == 0)) &&
              (valueKey2 = FUN_00172fb8(*keyRef), valueKey2 == 0)) &&
             (((iVar1 != 0 && (iVar1 = ((int (*)())FUN_00173754)(*keyRef,iVar1), iVar1 != 0)) ||
              (iVar1 = ((int (*)())FUN_0017494c)(*keyRef,valueNumber,param_3), iVar1 != 0)))) {
            inst = *(int *)(*keyRef + 0xb0);
            currentDefinition = VReg__currentDefinition(*(undefined4 *)(inst + 0xa4),*(undefined4 *)(program + 0x3a0),
                                 *(uint *)(program + 8));
            if ((inst == *(int *)(currentDefinition + 0xb0)) &&
               (currentDefinition = Program__tryEliminateRedundantCopy(program,inst,param_5), currentDefinition != 0)) goto LAB_0017624c;
          }
          iVar1 = (**(code **)(**(int **)(*keyRef + 0xb0) + 0x68))(*(int **)(*keyRef + 0xb0));
          if (iVar1 == 0) {
            vector2 = *(uint **)(program + 0x408);
            if (valueNumber < *vector2) {
              vectorFilledCount = vector2[1];
              if (vectorFilledCount <= valueNumber) {
                _memset(vectorFilledCount * 4 + vector2[2],0,(valueNumber - vectorFilledCount) * 4 + 4);
                vector2[1] = valueNumber + 1;
              }
              vectorElementRef = (undefined4 *)(valueNumber * 4 + vector2[2]);
            }
            else {
              vectorElementRef = (undefined4 *)Vector__elementRefGrow(vector2,valueNumber);
            }
            HashTable__insert(*vectorElementRef,*keyRef);
            return 0;
          }
          goto LAB_00176244;
        }
        eliminateRedundantInstResult = ((int (*)())Program__eliminateRedundantInst)(iVar2,*(undefined4 *)(*keyRef + 0xb0),param_5,program);
        if (eliminateRedundantInstResult == 0) goto LAB_00176244;
        *keyRef = iVar2;
        iVar1 = (**(code **)(**(int **)(iVar2 + 0xb0) + 100))(*(int **)(iVar2 + 0xb0));
        if (iVar1 == 0) {
          iVar1 = *(int *)(*keyRef + 0xb0);
          if (*(int *)(iVar1 + 0x160) <= *(int *)(program + 0x478)) {
            *(int *)(iVar1 + 0x160) = *(int *)(program + 0x478) + 1;
            return 1;
          }
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + 1;
          return 1;
        }
      }
    }
    else {
      valueKey = ((int (*)())FUN_001745f0)(valueKey);
      if ((valueKey == 0) ||
         (valueKey = Program__tryEliminateRedundantCopy(program,*(undefined4 *)(*keyRef + 0xb0),param_5), valueKey == 0)) {
        valueKey = *keyRef;
        goto LAB_00175e58;
      }
    }
LAB_0017624c:
    result = 1;
  }
  return result;
}

/* Ptr__equalNonNull @ 0x176264 (28 bytes) */
int Ptr__equalNonNull(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((param_1 == param_2) && (param_1 != 0)) {
    return 1;
  }
  return 0;
}

/* IROperand__copyRegisterAndSelect @ 0x176280 (28 bytes) */
int IROperand__copyRegisterAndSelect(dstRecord, srcRecord)
  int dstRecord;
  int srcRecord;
{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined1 *)(srcRecord + 8);
  uVar2 = *(undefined4 *)(srcRecord + 0xc);
  *(undefined4 *)(dstRecord + 0x10) = *(undefined4 *)(srcRecord + 0x10);
  *(undefined1 *)(dstRecord + 8) = uVar1;
  *(undefined4 *)(dstRecord + 0xc) = uVar2;
  return;
}

/* FUN_0017629c @ 0x17629c (32 bytes) */
int FUN_0017629c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x30c) + 300))(*(int **)(param_2 + 0x30c),param_1,param_2);
  return;
}

/* noop_1762bc @ 0x1762bc (4 bytes) */
int noop_1762bc()
{
  return;
}

/* FUN_001762c0 @ 0x1762c0 (68 bytes) */
int FUN_001762c0(param_1)
  undefined4 param_1;
{
  bool moreComponents;
  int loopIndex;
  
  loopIndex = 1;
  do {
    ((int (*)())FUN_001746c8)(param_1,loopIndex);
    moreComponents = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* KhanPs__vslot56_scaleFloat @ 0x176304 (32 bytes) */
double KhanPs__vslot56_scaleFloat(double fparam_1)
{
  return (double)(float)(fparam_1 * (double)FLOAT_001aa1cc);
}

/* signToCompareCode @ 0x176324 (44 bytes) */
int signToCompareCode(value)
  int value;
{
  if (value == 0) {
    return 3;
  }
  if (0 < value) {
    return 5;
  }
  if (value < 0) {
    return 1;
  }
  return 0;
}

/* classifyConstantRange @ 0x176350 (148 bytes) */
undefined4 classifyConstantRange(double fparam_1)
{
  if (fparam_1 == (double)FLOAT_001aa0e8) {
    return 1;
  }
  if (fparam_1 == (double)FLOAT_001aa114) {
    return 3;
  }
  if (fparam_1 == (double)FLOAT_001aa0d4) {
    return 2;
  }
  if (((double)FLOAT_001aa0d4 <= fparam_1) && (fparam_1 <= (double)FLOAT_001aa0e8)) {
    return 4;
  }
  if ((double)FLOAT_001aa114 <= fparam_1) {
    if (fparam_1 <= (double)FLOAT_001aa0d4) {
      return 5;
    }
  }
  return 0;
}

/* ValueKey__rowLanesAllEqual @ 0x1763e4 (144 bytes) */
int ValueKey__rowLanesAllEqual(param_1, param_2)
  int param_1;
  int param_2;
{
  bool moreComponents;
  int callResult;
  int iVar3;
  int loopIndex;
  int *loopPtr3;
  char *loopPtr2;
  
  loopPtr2 = (char *)(param_2 * 4 + param_1 + 0x224);
  loopPtr3 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  loopIndex = 0;
  do {
    if (*loopPtr2 != '\0') {
      if (iVar3 == 0) {
        iVar3 = *loopPtr3;
      }
      else {
        callResult = ((int (*)())Ptr__equalNonNull)(iVar3,*loopPtr3);
        if (callResult == 0) {
          return 0;
        }
      }
    }
    moreComponents = loopIndex != 3;
    loopPtr2 = loopPtr2 + 1;
    loopPtr3 = loopPtr3 + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return 1;
}

/* ValueKey__findOrInsertLiteral @ 0x176474 (104 bytes) */
int ValueKey__findOrInsertLiteral(undefined4 param_1,int param_2,int param_3,double fparam_1)
{
  bool isLast;
  int loopIndex;
  float *loopPtr2;
  
  loopIndex = 1;
  loopPtr2 = (float *)(param_2 + param_3 * 0x10 + -0xc);
  while( true ) {
    if ((double)*loopPtr2 == fparam_1) {
      return loopIndex + 1;
    }
    if ((double)*loopPtr2 == (double)FLOAT_001aa114) break;
    isLast = loopIndex == 3;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 0;
    }
  }
  *loopPtr2 = (float)fparam_1;
  return loopIndex + 1;
}

/* FUN_001764e0 @ 0x1764e0 (28 bytes) */
int FUN_001764e0(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_2 * 4 + param_1 + 0x70) == 4;
}

/* ValueKey__sourceKindIs1 @ 0x1764fc (28 bytes) */
int ValueKey__sourceKindIs1(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_2 * 4 + param_1 + 0xa0) == 1;
}

/* ValueKey__sourceKindIs4 @ 0x176518 (28 bytes) */
int ValueKey__sourceKindIs4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_2 * 4 + param_1 + 0xa0) == 4;
}

/* FUN_00176534 @ 0x176534 (48 bytes) */
int FUN_00176534(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 300) == *(int *)(param_2 + 300)) {
    return 0;
  }
  if ((*(int *)(param_1 + 300) < 0) && (*(int *)(param_2 + 300) < 0)) {
    return 1;
  }
  return 2;
}

/* FUN_00176564 @ 0x176564 (16 bytes) */
int FUN_00176564(param_1)
  int param_1;
{
  return param_1 == 0xf9;
}

/* FUN_00176574 @ 0x176574 (48 bytes) */
int FUN_00176574(param_1)
  int param_1;
{
  if (param_1 == 0x32) {
    return 1;
  }
  if (param_1 < 0x33) {
    if (param_1 == 0x1f) {
      return 1;
    }
  }
  else if (param_1 - 0xa7U < 2) {
    return 1;
  }
  return 0;
}

/* FUN_001765a4 @ 0x1765a4 (64 bytes) */
int FUN_001765a4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 valueNumberForExprResult;
  
  valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(param_1 + 0x238),param_2);
  *(undefined4 *)(param_3 * 4 + param_1 + 0x30) = valueNumberForExprResult;
  return;
}

/* FudoPs__vslot12_lookupTable6x @ 0x1765e4 (44 bytes) */
int FudoPs__vslot12_lookupTable6x(this, param_2, param_3)
  undefined4 this;
  int param_2;
  int param_3;
{
  return *(undefined4 *)(&DAT_001e5f54 + (param_2 * 6 + param_3) * 4);
}

/* FudoPs__vslot11_isNotType2Or5 @ 0x176610 (28 bytes) */
int FudoPs__vslot11_isNotType2Or5(this, param_2)
  undefined4 this;
  int param_2;
{
  if ((param_2 != 2) && (param_2 != 5)) {
    return 1;
  }
  return 0;
}

/* FUN_0017662c @ 0x17662c (144 bytes) */
int FUN_0017662c(ctx)
  int ctx;
{
  int operandRecord;
  bool moreComponents;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  loopIndex = 0;
  iVar4 = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if ((*(char *)(loopIndex + operandRecord + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
      iVar2 = *(int *)(iVar4 + 0x40);
      if (iVar2 == 0) {
        iVar2 = ((int (*)())FUN_00174ce0)(*(undefined4 *)(ctx + 0x238),loopIndex,ctx);
        *(int *)(iVar4 + 0x40) = iVar2;
      }
      *(undefined4 *)(iVar2 + 0xc) = 4;
    }
    moreComponents = loopIndex != 3;
    iVar4 = iVar4 + 4;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* FUN_001766bc @ 0x1766bc (112 bytes) */
int FUN_001766bc(ctx)
  int ctx;
{
  int valueNumberForExprResult;
  undefined4 opcodeInfo;
  int iVar1;
  undefined4 uVar2;
  
  valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),0);
  if ((*(int *)(valueNumberForExprResult + 4) == *(int *)(ctx + 0x184)) ||
     (uVar2 = 0, *(int *)(valueNumberForExprResult + 4) == *(int *)(ctx + 0x194))) {
    iVar1 = *(int *)(ctx + 0xb0);
    opcodeInfo = Opcode__getInfo(0x1c);
    *(undefined4 *)(iVar1 + 0x88) = opcodeInfo;
    ((int (*)())ValueKey__rebuild)(ctx);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0017672c @ 0x17672c (172 bytes) */
int FUN_0017672c(ctx)
  int ctx;
{
  int iVar1;
  int loopIndex;
  
  loopIndex = 1;
  while( true ) {
    iVar1 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (iVar1 < loopIndex) {
      return 1;
    }
    iVar1 = OpcodeTraits__instFlagBit2(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(ctx + 0xb0));
    if ((iVar1 == 0) || ((iVar1 = 3, loopIndex != 1 && (iVar1 = 1, loopIndex != 3)))) {
      iVar1 = 0;
    }
    if (-1 < *(int *)((loopIndex * 4 + iVar1) * 4 + ctx + 0x168)) break;
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* FUN_001767d8 @ 0x1767d8 (124 bytes) */
int FUN_001767d8(ctx, param_2)
  int ctx;
  int param_2;
{
  int iVar1;
  int loopIndex;
  int *piVar3;
  
  piVar3 = (int *)(param_2 * 4 + ctx + 0x178);
  loopIndex = 1;
  while( true ) {
    iVar1 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0));
    if (iVar1 < loopIndex) {
      return 1;
    }
    iVar1 = *piVar3;
    piVar3 = piVar3 + 4;
    if (-1 < iVar1) break;
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* ValueKey__lanesAreUnset @ 0x176854 (128 bytes) */
int ValueKey__lanesAreUnset(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  if (((((param_3 == 0) || (*(int *)(param_2 * 0x10 + param_1 + 0x168) < 0)) &&
       ((param_4 == 0 || (*(int *)(param_2 * 0x10 + param_1 + 0x16c) < 0)))) &&
      ((param_5 == 0 || (*(int *)(param_2 * 0x10 + param_1 + 0x170) < 0)))) &&
     ((param_6 == 0 || (*(int *)(param_2 * 0x10 + param_1 + 0x174) < 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_001768d4 @ 0x1768d4 (128 bytes) */
int FUN_001768d4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool isLast;
  int iVar2;
  int *exprRecordForValueNumberResult;
  int loopIndex;
  int *piVar5;
  
  iVar2 = param_2 * 4 + param_1;
  piVar5 = (int *)(iVar2 + 0x178);
  loopIndex = 1;
  while ((-1 < *piVar5 ||
         (exprRecordForValueNumberResult = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_1 + 0x238),*piVar5), *exprRecordForValueNumberResult != 0))) {
    isLast = loopIndex == 2;
    piVar5 = piVar5 + 4;
    loopIndex = loopIndex + 1;
    if (isLast) {
      return 0;
    }
  }
  *(int **)(iVar2 + 0x30) = exprRecordForValueNumberResult;
  return 1;
}

/* FUN_00176954 @ 0x176954 (160 bytes) */
int FUN_00176954(ctx, param_2)
  int ctx;
  int param_2;
{
  float *exprRecordForValueNumberResult;
  float *exprRecordForValueNumberResultB;
  undefined4 valueNumberForExprResult;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_2 * 4 + ctx;
  if ((*(int *)(iVar5 + 0x178) < 0) && (*(int *)(iVar5 + 0x188) < 0)) {
    exprRecordForValueNumberResult = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(iVar5 + 0x178));
    exprRecordForValueNumberResultB = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar5 + 0x188));
    iVar5 = ((bool (*)())evaluateCompareFloats)(*(undefined4 *)(ctx + 0xb0),(double)*exprRecordForValueNumberResult,(double)*exprRecordForValueNumberResultB);
    uVar4 = 0x3f800000;
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    valueNumberForExprResult = ((int (*)())Compiler__valueNumberForExpr)(*(undefined4 *)(ctx + 0x238),uVar4);
    uVar4 = 1;
    *(undefined4 *)(param_2 * 4 + ctx + 0x30) = valueNumberForExprResult;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_001769f4 @ 0x1769f4 (160 bytes) */
int FUN_001769f4(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *exprRecordForValueNumberResult;
  
  iVar1 = OpcodeTraits__instFlagBit2(*(undefined4 *)(param_2 + 0x238),*(undefined4 *)(param_2 + 0xb0));
  if ((iVar1 == 0) || ((iVar1 = 3, param_3 != 1 && (iVar1 = 1, param_3 != 3)))) {
    iVar1 = 0;
  }
  iVar1 = *(int *)((param_3 * 4 + iVar1) * 4 + param_2 + 0x168);
  if (iVar1 < 0) {
    exprRecordForValueNumberResult = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar1);
    *param_1 = *exprRecordForValueNumberResult;
  }
  else {
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_00176a94 @ 0x176a94 (428 bytes) */
int FUN_00176a94(param_1, valueKey, param_3)
  float *param_1;
  int valueKey;
  undefined4 *param_3;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *loopPtr;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int loopRemaining;
  undefined4 local_78 [4];
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  float local_48;
  float local_44;
  float param_3_w;
  
  loopRemaining = 4;
  *param_1 = GH_U2F(0x7fff0000U);
  loopPtr = local_78;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 4;
  loopPtr = local_68;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 4;
  loopPtr = local_58;
  do {
    *loopPtr = 0x7ffffffe;
    loopPtr = loopPtr + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  iVar6 = 0;
  loopRemaining = valueKey;
  do {
    uVar2 = *(undefined4 *)(valueKey + 0x238);
    uVar5 = *(undefined4 *)(loopRemaining + 0x178);
    *(undefined4 *)(iVar6 + (int)local_78) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(uVar2,uVar5);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_78) = *loopPtr;
    }
    uVar2 = *(undefined4 *)(valueKey + 0x238);
    uVar5 = *(undefined4 *)(loopRemaining + 0x188);
    *(undefined4 *)(iVar6 + (int)local_68) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(uVar2,uVar5);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_68) = *loopPtr;
    }
    uVar2 = *(undefined4 *)(valueKey + 0x238);
    uVar5 = *(undefined4 *)(loopRemaining + 0x198);
    *(undefined4 *)(iVar6 + (int)local_58) = 0;
    loopPtr = (undefined4 *)Compiler__exprRecordForValueNumber(uVar2,uVar5);
    if (loopPtr != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_58) = *loopPtr;
    }
    bVar1 = iVar6 != 0xc;
    loopRemaining = loopRemaining + 4;
    iVar6 = iVar6 + 4;
  } while (bVar1);
  *param_1 = GH_U2F(0x7fff0000U);
  piVar4 = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  (**(code **)(*piVar4 + 8))
            (piVar4,param_1,local_78,local_68,local_58,*(undefined4 *)(valueKey + 0x238));
  param_3_w = *param_1;
  if (param_3_w != FLOAT_001aa1d0) {
    IRInst__scaleByOutputScale(&local_48,*(undefined4 *)(valueKey + 0xb0),param_3_w);
    *param_1 = local_48;
    IRInst__clampOutputValue(&local_44,*(undefined4 *)(valueKey + 0xb0),local_48);
    if (local_44 != *param_1) {
      *param_3 = 1;
      *param_1 = local_44;
    }
  }
  return param_1;
}

/* FUN_00176c40 @ 0x176c40 (300 bytes) */
int FUN_00176c40(param_1, valueKey, param_3, param_4)
  int *param_1;
  int valueKey;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *exprRecordForValueNumberResult;
  int callResult;
  int *a0;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *loopPtr2;
  code *a6;
  undefined4 *puVar4;
  int loopIndex;
  undefined4 local_48 [8];
  int local_28;
  int local_24 [2];
  
  loopIndex = 5;
  loopPtr2 = local_48;
  do {
    *loopPtr2 = 0x7ffffffe;
    loopPtr2 = loopPtr2 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopPtr2 = local_48;
  loopIndex = 1;
  *param_1 = 0x7ffffffe;
  puVar4 = (undefined4 *)(param_3 * 4 + valueKey + 0x178);
  while( true ) {
    loopPtr2 = loopPtr2 + 1;
    callResult = (**(code **)(**(int **)(valueKey + 0xb0) + 0x14))(*(int **)(valueKey + 0xb0));
    if (callResult < loopIndex) break;
    loopIndex = loopIndex + 1;
    exprRecordForValueNumberResult = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(valueKey + 0x238),*puVar4);
    *loopPtr2 = *exprRecordForValueNumberResult;
    puVar4 = puVar4 + 4;
  }
  a0 = *(int **)(*(int *)(valueKey + 0xb0) + 0x88);
  a6 = *(code **)(*a0 + 4);
  (*a6)(a0,param_1,local_48,*(undefined4 *)(valueKey + 0x238),in_r7,in_r8,a6);
  if (*param_1 != 0x7ffffffe) {
    IRInst__scaleByOutputScale(&local_28,*(undefined4 *)(valueKey + 0xb0),*param_1);
    *param_1 = local_28;
    IRInst__clampOutputValue(local_24,*(undefined4 *)(valueKey + 0xb0),local_28);
    if (local_24[0] != *param_1) {
      *param_4 = 1;
      *param_1 = local_24[0];
    }
  }
  return param_1;
}

/* FUN_00176d6c @ 0x176d6c (160 bytes) */
int FUN_00176d6c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int findInPtrSetResult;
  int findInPtrSetResultB;
  undefined4 uVar3;
  
  if ((((param_1 < 1) || (param_2 < 1)) || (findInPtrSetResult = Compiler__findInPtrSet(param_3,param_1), findInPtrSetResult == 0)) ||
     ((findInPtrSetResultB = Compiler__findInPtrSet(param_3,param_2), findInPtrSetResultB == 0 ||
      (((*(int *)(findInPtrSetResult + 0x20) == 0 || (param_2 != *(int *)(findInPtrSetResult + 0x24))) &&
       ((*(int *)(findInPtrSetResultB + 0x20) == 0 || (param_1 != *(int *)(findInPtrSetResultB + 0x24))))))))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00176e20 @ 0x176e20 (160 bytes) */
int FUN_00176e20(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int findInPtrSetResult;
  int findInPtrSetResultB;
  undefined4 uVar3;
  
  if ((((param_1 < 1) || (param_2 < 1)) || (findInPtrSetResult = Compiler__findInPtrSet(param_3,param_1), findInPtrSetResult == 0)) ||
     ((findInPtrSetResultB = Compiler__findInPtrSet(param_3,param_2), findInPtrSetResultB == 0 ||
      (((*(int *)(findInPtrSetResult + 0x28) == 0 || (param_2 != *(int *)(findInPtrSetResult + 0x2c))) &&
       ((*(int *)(findInPtrSetResultB + 0x28) == 0 || (param_1 != *(int *)(findInPtrSetResultB + 0x2c))))))))) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00176ec0 @ 0x176ec0 (20 bytes) */
int FUN_00176ec0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 callResult;
  
  callResult = ((int (*)())FUN_00176e20)(param_2,param_3,*(undefined4 *)(param_1 + 0x238));
  return callResult;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00176304");
asm(".set FUN_00176304, _KhanPs__vslot56_scaleFloat");
asm(".globl FUN_001765e4");
asm(".set FUN_001765e4, _FudoPs__vslot12_lookupTable6x");
asm(".globl FUN_00176610");
asm(".set FUN_00176610, _FudoPs__vslot11_isNotType2Or5");
