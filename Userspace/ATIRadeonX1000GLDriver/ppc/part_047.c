#include "decls.h"

/* FUN_00176ed4 @ 0x176ed4 (56 bytes) */
int FUN_00176ed4(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (0 < param_2) {
    iVar2 = Compiler__findInPtrSet(*(undefined4 *)(param_1 + 0x238),param_2);
    uVar1 = *(undefined4 *)(iVar2 + 0xc);
  }
  return uVar1;
}

/* FUN_00176f0c @ 0x176f0c (56 bytes) */
int FUN_00176f0c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (0 < param_2) {
    iVar2 = Compiler__findInPtrSet(*(undefined4 *)(param_1 + 0x238),param_2);
    uVar1 = *(undefined4 *)(iVar2 + 0x10);
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
  undefined4 *loopIndex2;
  undefined4 *loopIndex3;
  
  loopIndex2 = (undefined4 *)(param_2 * 0x10 + ctx + 0x168);
  loopIndex3 = (undefined4 *)(param_3 * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176d6c(*loopIndex2,*loopIndex3,*(undefined4 *)(ctx + 0x238)), iVar2 != 0))) {
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
    loopIndex3 = loopIndex3 + 1;
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
  undefined4 *loopIndex2;
  undefined4 *loopIndex3;
  
  loopIndex2 = (undefined4 *)(param_2 * 0x10 + ctx + 0x168);
  loopIndex3 = (undefined4 *)(param_3 * 0x10 + ctx + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = FUN_00176e20(*loopIndex2,*loopIndex3,*(undefined4 *)(ctx + 0x238)), iVar2 != 0))) {
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
    loopIndex3 = loopIndex3 + 1;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00177064 @ 0x177064 (128 bytes) */
int FUN_00177064(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  int *loopIndex2;
  
  loopIndex2 = (int *)(param_3 * 0x10 + param_1 + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' || (*loopIndex2 == param_2))) {
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
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
  undefined4 *puVar5;
  int iVar6;
  int loopIndex;
  int *loopIndex2;
  
  iVar6 = 0;
  bVar1 = false;
  bVar2 = true;
  loopIndex2 = (int *)(param_3 * 0x10 + param_2 + 0x168);
  loopIndex = 0;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(param_2 + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if (bVar2) {
        iVar6 = *loopIndex2;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*loopIndex2 != iVar6) goto LAB_00177184;
    }
    bVar3 = loopIndex != 3;
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + 1;
  } while (bVar3);
  if (bVar1) {
    puVar5 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar6);
    *param_1 = *puVar5;
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
  float *pfVar3;
  int iVar4;
  int loopIndex;
  int *loopIndex2;
  
  loopIndex = 0;
  loopIndex2 = param_1;
  do {
    operandRecord = IRInst__getOperandRecord(param_1[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      if ((float *)loopIndex2[0xc] == (float *)0x0) {
        iVar2 = *loopIndex2;
        if (iVar2 < 0) {
          pfVar3 = (float *)Compiler__exprRecordForValueNumber(param_1[0x8e],iVar2);
          iVar2 = ((undefined4 (*)())FUN_00176350)((double)*pfVar3);
        }
        else {
          iVar4 = loopIndex2[0x10];
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
        iVar2 = ((undefined4 (*)())FUN_00176350)((double)*(float *)loopIndex2[0xc]);
      }
LAB_00177254:
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        loopIndex2[0x14] = iVar2;
      }
      else {
        loopIndex2[0x14] = (DAT_001e6158)[iVar2];
      }
    }
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
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
  int *loopIndex2;
  
  loopIndex = 0;
  loopIndex2 = param_1;
  do {
    operandRecord = IRInst__getOperandRecord(param_1[0x2c],0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      puVar3 = (undefined4 *)loopIndex2[0xc];
      if (puVar3 == (undefined4 *)0x0) {
        iVar2 = *loopIndex2;
        if (iVar2 < 0) {
          puVar3 = (undefined4 *)Compiler__exprRecordForValueNumber(param_1[0x8e],iVar2);
          goto LAB_00177304;
        }
        iVar4 = loopIndex2[0x10];
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
        iVar2 = FUN_00176324(*puVar3);
      }
      if (*(int *)(param_1[0x2c] + 0x120) == 0) {
        loopIndex2[0x20] = iVar2;
      }
      else {
        loopIndex2[0x20] = (DAT_001e61a0)[iVar2];
      }
    }
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
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
  int *loopIndex2;
  int *loopIndex3;
  
  loopIndex2 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  loopIndex3 = (int *)(param_3 * 0x10 + param_1 + 0x168);
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' || (*loopIndex2 == *loopIndex3))) {
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
    loopIndex3 = loopIndex3 + 1;
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
  int *loopIndex2;
  int loopIndex;
  
  loopIndex2 = (int *)(param_2 * 0x10 + ctx + 0x168);
  exprRecord = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),GH_F2U((float)fparam_1));
  loopIndex = 0;
  while ((iVar3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0),
         *(char *)(loopIndex + iVar3 + 0x10) == '\x01' || (*loopIndex2 == *(int *)(exprRecord + 4)))) {
    bVar1 = loopIndex == 3;
    loopIndex2 = loopIndex2 + 1;
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
  int operandRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  iVar2 = *(int *)(ctx + 0xb0);
  if ((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) {
    if (((*(uint *)(iVar2 + 0xb8) & 2) == 0) && ((*(uint *)(iVar2 + 0xb8) & 1) != 0)) {
      loopIndex = 0;
      iVar4 = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(iVar2,0);
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
        iVar2 = *(int *)(ctx + 0xb0);
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
  bool bVar1;
  uint uVar2;
  int callResult;
  int *piVar4;
  int iVar5;
  int operandRecord;
  undefined4 *puVar7;
  int iVar8;
  int loopIndex;
  int iVar10;
  float local_38 [2];
  float local_30;
  
  callResult = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
  ((int (*)())FUN_001770e4)(local_38,ctx,2);
  local_30 = local_38[0];
  if ((local_38[0] == FLOAT_001aa0d4) &&
     (piVar4 = *(int **)(*(int *)(ctx + 0x238) + 0x30c),
     iVar5 = (**(code **)(*piVar4 + 0x2c))(piVar4,callResult), iVar5 == 0)) {
    loopIndex = 0;
    iVar5 = 0;
    iVar10 = ctx;
    do {
      operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      iVar8 = iVar5;
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        iVar8 = *(int *)(iVar10 + 0x178);
        if (iVar8 < 0) {
          puVar7 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar8);
          iVar8 = FUN_00176324(*puVar7);
        }
        else {
          if (iVar8 < 1) {
            return;
          }
          iVar8 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar8);
          iVar8 = *(int *)(iVar8 + 0xc);
          uVar2 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
          if ((uVar2 & 2) != 0) {
            iVar8 = (DAT_001e61d0)[iVar8];
          }
          if ((uVar2 & 1) != 0) {
            iVar8 = *(int *)(&DAT_001e61b8 + iVar8 * 4);
          }
        }
        if (iVar8 == 0) {
          return;
        }
        if ((iVar5 != 0) && (bVar1 = iVar8 != iVar5, iVar8 = iVar5, bVar1)) {
          return;
        }
      }
      bVar1 = loopIndex != 3;
      iVar10 = iVar10 + 4;
      loopIndex = loopIndex + 1;
      iVar5 = iVar8;
    } while (bVar1);
    piVar4 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    iVar5 = (**(code **)(*piVar4 + 0x30))(piVar4,callResult,iVar8);
    if (callResult != iVar5) {
      IRInst__setCompareCondition(*(undefined4 *)(ctx + 0xb0),iVar5);
      return;
    }
  }
  return;
}

/* FUN_001778e0 @ 0x1778e0 (272 bytes) */
int FUN_001778e0(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int loopIndex;
  double dVar6;
  
  iVar2 = *(int *)(ctx + 0xb0);
  if ((((*(int *)(iVar2 + 0x120) == 0) && ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) &&
      ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) && (*(int *)(iVar2 + 0x124) != 0)) {
    loopIndex = 0;
    iVar4 = ctx;
    while( true ) {
      operandRecord = IRInst__getOperandRecord(iVar2,0);
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
        dVar6 = (double)((double (*)())FUN_0010aad4)(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x124));
        *(float *)(iVar2 + 0x1c) = (float)dVar6;
      }
      bVar1 = loopIndex == 3;
      iVar4 = iVar4 + 4;
      loopIndex = loopIndex + 1;
      if (bVar1) break;
      iVar2 = *(int *)(ctx + 0xb0);
    }
  }
  return;
}

/* FUN_001779f0 @ 0x1779f0 (224 bytes) */
int FUN_001779f0(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  iVar2 = *(int *)(ctx + 0xb0);
  if ((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) {
    if (((*(uint *)(iVar2 + 0xb8) & 1) == 0) && ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) {
      loopIndex = 0;
      iVar4 = ctx;
      while( true ) {
        operandRecord = IRInst__getOperandRecord(iVar2,0);
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
        iVar2 = *(int *)(ctx + 0xb0);
      }
    }
  }
  return;
}

/* FUN_00177ad0 @ 0x177ad0 (124 bytes) */
int FUN_00177ad0(ctx)
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
    FUN_001745ac(ctx);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00177b4c @ 0x177b4c (388 bytes) */
int FUN_00177b4c(ctx, param_2, param_3)
  int ctx;
  int param_2;
  int param_3;
{
  int operandRecord;
  int callResult;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar5 = param_2 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_2);
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
  Block__insertInstAfter(uVar4,iVar2,callResult);
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
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
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
  Block__insertInstAfter(uVar4,iVar2,callResult);
  return callResult;
}

/* FUN_00177e14 @ 0x177e14 (528 bytes) */
int FUN_00177e14(ctx, param_2, param_3, param_4, param_5)
  int ctx;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int operandRecord;
  undefined *puVar1;
  int callResult;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(param_2,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b64 + param_5 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar4;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar6 = param_3 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(param_3 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_3);
  puVar1 = PTR_DAT_001e8b8c;
  uVar4 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)*(byte *)(param_5 + operandRecord + 0x10) * 4);
  operandRecord = IRInst__getOperandRecord(callResult,1);
  *(undefined4 *)(operandRecord + 0x10) = uVar4;
  IROperand__setModifierBits(callResult + 0xa4,2,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) >> 1 & 1);
  IROperand__setModifierBits(callResult + 0xa4,1,*(uint *)(*(int *)(ctx + 0xb0) + iVar6 + 0x20) & 1);
  iVar6 = param_4 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,2,*(undefined4 *)(param_4 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_4);
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
  Block__insertInstAfter(uVar5,iVar3,callResult);
  return callResult;
}

/* FUN_00178024 @ 0x178024 (384 bytes) */
int FUN_00178024(ctx, param_2, param_3, param_4)
  int ctx;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int operandRecord;
  int callResult;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
  callResult = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(callResult,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
  uVar3 = *(undefined4 *)(PTR_DAT_001e8b64 + param_3 * 4);
  *(undefined4 *)(callResult + 0x94) = *(undefined4 *)(callResult + 0x14c);
  *(undefined4 *)(callResult + 0x9c) = uVar3;
  *(undefined4 *)(callResult + 0x98) = 0;
  iVar5 = param_2 * 0x18 + 0x80;
  IRInst__setOperandRef(callResult,1,*(undefined4 *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c));
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_2);
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
  Block__insertInstAfter(uVar4,iVar2,callResult);
  return callResult;
}

/* FUN_001781a4 @ 0x1781a4 (404 bytes) */
int FUN_001781a4(param_1, param_2, param_3)
  float *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *loopIndex2;
  int iVar2;
  int *loopIndex;
  int iVar4;
  int loopRemaining;
  undefined4 local_68 [6];
  int local_50 [6];
  float local_38;
  float local_34 [2];
  
  loopRemaining = 5;
  *param_1 = GH_U2F(0x7fff0000U);
  loopIndex2 = local_68;
  do {
    *loopIndex2 = 0x7ffffffe;
    loopIndex2 = loopIndex2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopIndex = local_50;
  iVar4 = 4;
  for (loopRemaining = 1;
      iVar2 = (**(code **)(**(int **)(param_2 + 0xb0) + 0x14))(*(int **)(param_2 + 0xb0)),
      loopRemaining <= iVar2; loopRemaining = loopRemaining + 1) {
    iVar2 = OpcodeTraits__instFlagBit2(*(undefined4 *)(param_2 + 0x238),*(undefined4 *)(param_2 + 0xb0));
    if (iVar2 == 0) {
      *loopIndex = 0;
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
    iVar2 = *loopIndex;
    loopIndex = loopIndex + 1;
    loopIndex2 = (undefined4 *)
             Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),
                          *(undefined4 *)((iVar4 + iVar2) * 4 + param_2 + 0x168));
    *(undefined4 *)(iVar4 + (int)local_68) = *loopIndex2;
    iVar4 = iVar4 + 4;
  }
  loopIndex = *(int **)(*(int *)(param_2 + 0xb0) + 0x88);
  (**(code **)(*loopIndex + 4))(loopIndex,param_1,local_68,*(undefined4 *)(param_2 + 0x238));
  if (*param_1 != 2.1474836e+09) {
    FUN_0010aee8(&local_38,*(undefined4 *)(param_2 + 0xb0),*param_1);
    *param_1 = local_38;
    FUN_0010b118(local_34,*(undefined4 *)(param_2 + 0xb0),local_38);
    if (local_34[0] != *param_1) {
      *param_3 = 1;
      *param_1 = local_34[0];
    }
  }
  return param_1;
}

/* FUN_00178338 @ 0x178338 (656 bytes) */
int FUN_00178338(ctx, param_2, param_3)
  int ctx;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *loopIndex;
  int local_54 [9];
  
  iVar1 = param_2 * 4;
  if (*(int *)(iVar1 + ctx + 0x30) == 0) {
    piVar8 = (int *)(iVar1 + ctx + 0x178);
    loopIndex = local_54;
    iVar6 = 0x98;
    for (iVar7 = 1;
        iVar4 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        iVar7 <= iVar4; iVar7 = iVar7 + 1) {
      iVar4 = *piVar8;
      if (iVar4 < 0) {
        pfVar3 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar4);
        iVar4 = ((undefined4 (*)())FUN_00176350)((double)*pfVar3);
        *loopIndex = iVar4;
      }
      else if (iVar4 < 1) {
        *loopIndex = 0;
      }
      else {
        iVar4 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar4);
        iVar4 = *(int *)(iVar4 + 0x10);
        *loopIndex = iVar4;
        iVar5 = *(int *)(ctx + 0xb0) + iVar6;
        uVar2 = *(uint *)(iVar5 + 0x20);
        if ((uVar2 & 2) != 0) {
          *loopIndex = *(int *)(&DAT_001e6188 + iVar4 * 4);
          uVar2 = *(uint *)(iVar5 + 0x20);
        }
        if ((uVar2 & 1) != 0) {
          *loopIndex = *(int *)(&DAT_001e6170 + *loopIndex * 4);
        }
      }
      iVar6 = iVar6 + 0x18;
      loopIndex = loopIndex + 1;
      piVar8 = piVar8 + 4;
    }
    iVar6 = *(int *)(ctx + 0xb0);
    switch(*(undefined4 *)(*(int *)(iVar6 + 0x88) + 8)) {
    case 0x12:
      local_54[0] = *(int *)(&DAT_001e5bf4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x13:
      local_54[0] = *(int *)(&DAT_001e5ad4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    default:
      local_54[0] = 0;
      break;
    case 0x17:
      local_54[0] = *(int *)(&DAT_001e5a44 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x19:
      local_54[0] = *(int *)(&DAT_001e59b4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      local_54[0] = *(int *)(&DAT_001e5b64 + (local_54[1] * 6 + local_54[2]) * 4);
      break;
    case 0x31: ;
    }
    if ((0 < *(int *)(iVar6 + 0x124)) && (local_54[0] != 2)) {
      local_54[0] = 0;
    }
    iVar7 = local_54[0];
    if (*(int *)(iVar6 + 0x120) != 0) {
      iVar7 = (DAT_001e6158)[local_54[0]];
      if (local_54[0] == iVar7) {
        *(undefined4 *)(iVar1 + param_3) = 0;
        iVar7 = local_54[0];
      }
      else {
        *(undefined4 *)(iVar1 + param_3) = 1;
      }
    }
    iVar6 = *(int *)(iVar1 + ctx + 0x40);
    if (iVar6 == 0) {
      iVar6 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),param_2,ctx);
      *(int *)(iVar1 + ctx + 0x40) = iVar6;
    }
    *(int *)(iVar6 + 0x10) = iVar7;
  }
  return;
}

/* FUN_00178648 @ 0x178648 (708 bytes) */
int FUN_00178648(ctx, param_2)
  int ctx;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *loopIndex;
  int local_54 [9];
  
  iVar2 = param_2 * 4 + ctx;
  if (*(int *)(iVar2 + 0x30) == 0) {
    piVar8 = (int *)(iVar2 + 0x178);
    loopIndex = local_54;
    iVar2 = 0x98;
    iVar6 = 0x98;
    for (iVar7 = 1;
        iVar4 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        iVar7 <= iVar4; iVar7 = iVar7 + 1) {
      iVar4 = *piVar8;
      if (iVar4 < 0) {
        puVar3 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar4);
        iVar4 = FUN_00176324(*puVar3);
        *loopIndex = iVar4;
      }
      else {
        if (iVar4 < 1) {
          *loopIndex = 0;
          iVar4 = *(int *)(ctx + 0xb0) + iVar2;
          uVar1 = *(uint *)(iVar4 + 0x20);
          if ((uVar1 & 2) != 0) {
            *loopIndex = DAT_001e61d0[0];
            uVar1 = *(uint *)(iVar4 + 0x20);
          }
        }
        else {
          iVar4 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar4);
          iVar4 = *(int *)(iVar4 + 0xc);
          *loopIndex = iVar4;
          iVar5 = *(int *)(ctx + 0xb0) + iVar6;
          uVar1 = *(uint *)(iVar5 + 0x20);
          if ((uVar1 & 2) != 0) {
            *loopIndex = (DAT_001e61d0)[iVar4];
            uVar1 = *(uint *)(iVar5 + 0x20);
          }
        }
        if ((uVar1 & 1) != 0) {
          *loopIndex = *(int *)(&DAT_001e61b8 + *loopIndex * 4);
        }
      }
      iVar6 = iVar6 + 0x18;
      iVar2 = iVar2 + 0x18;
      loopIndex = loopIndex + 1;
      piVar8 = piVar8 + 4;
    }
    switch(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8)) {
    case 0x12:
      iVar2 = *(int *)(&DAT_001e5ec4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x13:
      iVar2 = *(int *)(&DAT_001e5c84 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x14:
      iVar2 = *(int *)(&DAT_001e5ec4 +
                      (*(int *)(&DAT_001e5c84 + (local_54[0] * 6 + local_54[1]) * 4) * 6 +
                      local_54[2]) * 4);
      break;
    default:
      iVar2 = 0;
      break;
    case 0x17:
      iVar2 = *(int *)(&DAT_001e5da4 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x19:
      iVar2 = *(int *)(&DAT_001e5d14 + (local_54[0] * 6 + local_54[1]) * 4);
      break;
    case 0x24:
    case 0x25:
    case 0x26:
      iVar2 = *(int *)(&DAT_001e5e34 + (local_54[1] * 6 + local_54[2]) * 4);
      break;
    case 0x31:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
      iVar2 = local_54[0];
    }
    if (*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) {
      iVar2 = (DAT_001e61a0)[iVar2];
    }
    iVar7 = param_2 * 4 + ctx;
    iVar6 = *(int *)(iVar7 + 0x40);
    if (iVar6 == 0) {
      iVar6 = FUN_00174ce0(*(undefined4 *)(ctx + 0x238),param_2,ctx);
      *(int *)(iVar7 + 0x40) = iVar6;
    }
    *(int *)(iVar6 + 0xc) = iVar2;
  }
  return;
}

/* FUN_001789d4 @ 0x1789d4 (28 bytes) */
int FUN_001789d4(param_1)
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
  int *loopIndex4;
  undefined4 uVar4;
  int loopIndex2;
  int loopIndex3;
  
  loopIndex4 = *(int **)(ctx + 0xb0);
  loopIndex = *(int *)(loopIndex4[0x22] + 8);
  if (loopIndex == 0x1c) {
    for (loopIndex = 1; loopIndex2 = (**(code **)(*loopIndex4 + 0x14))(loopIndex4), loopIndex <= loopIndex2; loopIndex = loopIndex + 1
        ) {
      loopIndex2 = 0;
      loopIndex4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
      do {
        if (-1 < *loopIndex4) goto LAB_00178b50;
        bVar1 = loopIndex2 != 2;
        loopIndex4 = loopIndex4 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      loopIndex4 = *(int **)(ctx + 0xb0);
    }
LAB_00178bc4:
    uVar4 = 1;
  }
  else {
    if (loopIndex < 0x1d) {
      if (loopIndex == 0x18) {
LAB_00178b6c:
        for (loopIndex = 1; loopIndex2 = (**(code **)(*loopIndex4 + 0x14))(loopIndex4), loopIndex <= loopIndex2;
            loopIndex = loopIndex + 1) {
          loopIndex2 = 4;
          loopIndex4 = (int *)(loopIndex * 0x10 + ctx + 0x168);
          do {
            if (-1 < *loopIndex4) goto LAB_00178b50;
            loopIndex4 = loopIndex4 + 1;
            loopIndex2 = loopIndex2 + -1;
          } while (loopIndex2 != 0);
          loopIndex4 = *(int **)(ctx + 0xb0);
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
          loopIndex4 = (int *)(loopIndex2 + 8);
          loopIndex3 = 0;
          do {
            if (-1 < *loopIndex4) goto LAB_00178b50;
            bVar1 = loopIndex3 != 1;
            loopIndex4 = loopIndex4 + 1;
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
  undefined4 *puVar2;
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
      puVar2 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar1);
      *param_1 = *puVar2;
      return param_1;
    }
  }
LAB_00178d10:
  *param_1 = 0x7ffffffe;
  return param_1;
}

/* FUN_00178d78 @ 0x178d78 (280 bytes) */
int FUN_00178d78(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 0xb0) + 0x88) + 8);
  if (iVar1 == 0x1c) {
    iVar1 = param_3 * 0x10 + param_2;
    iVar3 = *(int *)(iVar1 + 0x168);
    if ((iVar3 != *(int *)(iVar1 + 0x16c)) || (iVar3 != *(int *)(iVar1 + 0x170))) goto LAB_00178de8;
  }
  else {
    if (iVar1 < 0x1d) {
      if (iVar1 != 0x18) goto LAB_00178de8;
    }
    else if (iVar1 != 0x1d) {
      if (iVar1 != 0x1e) goto LAB_00178de8;
      if (param_3 - 1U < 2) {
        iVar1 = param_3 * 0x10 + param_2;
        iVar3 = *(int *)(iVar1 + 0x168);
        if (iVar3 != *(int *)(iVar1 + 0x16c)) goto LAB_00178de8;
      }
      else {
        iVar3 = *(int *)(param_3 * 0x10 + param_2 + 0x170);
      }
      goto LAB_00178e60;
    }
    iVar1 = param_3 * 0x10 + param_2;
    iVar3 = *(int *)(iVar1 + 0x168);
    if (((iVar3 != *(int *)(iVar1 + 0x16c)) || (iVar3 != *(int *)(iVar1 + 0x170))) ||
       (iVar3 != *(int *)(iVar1 + 0x174))) goto LAB_00178de8;
  }
LAB_00178e60:
  if (iVar3 < 0) {
    puVar2 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar3);
    *param_1 = *puVar2;
    return param_1;
  }
LAB_00178de8:
  *param_1 = 0x7ffffffe;
  return param_1;
}

/* FUN_00178e90 @ 0x178e90 (468 bytes) */
int FUN_00178e90(param_1, param_2, param_3, param_4)
  float *param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *loopIndex;
  int loopRemaining;
  double dVar6;
  double dVar7;
  float local_58 [15];
  
  loopRemaining = 5;
  loopIndex = local_58;
  do {
    *loopIndex = GH_U2F(0x7fff0000U);
    loopIndex = loopIndex + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  *param_1 = GH_U2F(0x7fff0000U);
  if (*(int *)(*(int *)(*(int *)(param_2 + 0xb0) + 0x88) + 8) == 0x32) {
    if (param_3 == 1) {
      loopIndex = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),
                                     *(undefined4 *)(param_2 + 0x178));
      fVar3 = *loopIndex;
      fVar1 = fVar3;
      if (fVar3 < 0.0) {
        fVar1 = 0.0;
      }
      fVar2 = 0.0;
      if (-fVar3 < 0.0) {
        fVar2 = fVar1;
      }
      *param_1 = fVar2;
    }
    else {
      if (param_3 < 2) {
        if (param_3 != 0) {
          return param_1;
        }
      }
      else {
        if (param_3 == 2) {
          loopIndex = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),
                                         *(undefined4 *)(param_2 + 0x178));
          local_58[0] = *loopIndex;
          loopIndex = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),
                                         *(undefined4 *)(param_2 + 0x17c));
          local_58[1] = *loopIndex;
          if ((0.0 < local_58[0]) && (0.0 < local_58[1])) {
            loopIndex = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),
                                           *(undefined4 *)(param_2 + 0x184));
            local_58[3] = *loopIndex;
            fVar1 = -128.0;
            if (-128.0 <= local_58[3]) {
              fVar3 = 128.0;
              if (local_58[3] - 128.0 < 0.0) {
                fVar3 = local_58[3];
              }
              fVar1 = local_58[3];
              if (-(local_58[3] - 128.0) < 0.0) {
                fVar1 = fVar3;
              }
            }
            dVar6 = _log((double)local_58[1]);
            dVar7 = _log(2.0);
            dVar6 = _pow(2.0,(double)(fVar1 * (float)(dVar6 / dVar7)));
            *param_1 = (float)dVar6;
            return param_1;
          }
          *param_1 = 0.0;
          return param_1;
        }
        if (param_3 != 3) {
          return param_1;
        }
      }
      *param_1 = 1.0;
    }
  }
  return param_1;
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
int FUN_00179138(ctx, param_2)
  int ctx;
  int param_2;
{
  undefined4 arenaAt378;
  int iVar1;
  int callResult;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  
  callResult = IRLoadConst__vslot73(0xa2,*(undefined4 *)(ctx + 0x238));
  iVar1 = *(int *)(ctx + 0x238);
  uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x6c4) + 0x3ac);
  iVar5 = *(int *)(iVar1 + 0x3b0) + -1;
  *(int *)(iVar1 + 0x3b0) = iVar5;
  iVar1 = FUN_00127608(uVar3,0x36,iVar5,0);
  FUN_0012306c(iVar1,callResult);
  piVar6 = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
  iVar5 = (**(code **)(*piVar6 + 0x24))(piVar6);
  if (iVar5 == 0) {
    Block__insertInstBefore(piVar6,*(undefined4 *)(ctx + 0xb0),callResult);
  }
  else {
    Block__appendInst(piVar6[1],callResult);
  }
  if (*(int *)(*(int *)(iVar1 + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    puVar4 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *puVar4 = arenaAt378;
    ValueKey__init(puVar4 + 1,callResult,*(undefined4 *)(ctx + 0x238));
    Block__recordDefinition(piVar6,iVar1,puVar4 + 1);
  }
  *(undefined4 *)(callResult + 300) = 1;
  *(undefined4 *)(callResult + 0x84) = 1;
  IRInst__setOperandRef(callResult,0,iVar1);
  uVar3 = *(undefined4 *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c);
  IRInst__setOperandRef(callResult,1,uVar3);
  iVar5 = param_2 * 4 + ctx;
  VReg__addUse(uVar3,1,callResult);
  IRInst__setOperandSource(callResult,1,*(undefined4 *)(iVar5 + 0x210),0,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),param_2,iVar1);
  VReg__addUse(iVar1,param_2,*(undefined4 *)(ctx + 0xb0));
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
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  a0 = *(int **)(ctx + 0xb0);
  puVar5 = *(uint **)(a0[param_2 * 6 + 0x23] + 0x2c);
  uVar4 = puVar5[1];
  uVar3 = uVar4 - 1;
  if (uVar3 < *puVar5) {
    if (uVar4 <= uVar3) {
      _memset(uVar4 * 4 + puVar5[2],0,(uVar3 - uVar4) * 4 + 4);
      puVar5[1] = uVar4;
      a0 = *(int **)(ctx + 0xb0);
    }
    piVar2 = (int *)(uVar3 * 4 + puVar5[2]);
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar5,uVar3);
    a0 = *(int **)(ctx + 0xb0);
  }
  iVar6 = *piVar2;
  callResult = (**(code **)(*a0 + 100))(a0);
  if ((callResult != 0) &&
     (callResult = OpcodeTraits__flagBit8(*(undefined4 *)(*(int *)(*(int *)(iVar6 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), callResult != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_001793d8 @ 0x1793d8 (560 bytes) */
int FUN_001793d8(ctx, param_2, param_3)
  int ctx;
  int param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { ctx, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint loopIndex4;
  int iVar6;
  char *loopIndex2;
  uint uVar8;
  int loopIndex;
  int *loopIndex3;
  uint *puVar11;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  loopIndex3 = (int *)(param_2 * 0x10 + ctx + 0x168);
  iVar4 = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  loopIndex2 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
  do {
    if (*loopIndex2 != '\0') {
      if (iVar4 == 0) {
        iVar4 = *loopIndex3;
      }
      else {
        loopIndex = Ptr__equalNonNull(iVar4,*loopIndex3);
        if (loopIndex == 0) {
          return 4;
        }
      }
    }
    loopIndex2 = loopIndex2 + 1;
    loopIndex3 = loopIndex3 + 1;
  } while (loopIndex2 != &(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  puVar11 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  loopIndex4 = puVar11[1];
  uVar8 = loopIndex4 - 1;
  if (uVar8 < *puVar11) {
    if (loopIndex4 <= uVar8) {
      _memset(loopIndex4 * 4 + puVar11[2],0,(uVar8 - loopIndex4) * 4 + 4);
      puVar11[1] = loopIndex4;
    }
    loopIndex3 = (int *)(uVar8 * 4 + puVar11[2]);
  }
  else {
    loopIndex3 = (int *)Vector__elementRefGrow(puVar11,uVar8);
  }
  iVar6 = *loopIndex3;
  loopIndex4 = 0;
  loopIndex = iVar6;
  do {
    iVar2 = IRInst__getOperandRecord(*(undefined4 *)(iVar6 + 0xb0),0);
    if (*(char *)(loopIndex4 + iVar2 + 0x10) != '\x01') {
      iVar2 = *(int *)(loopIndex + 0x20);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        FUN_0010b2dc(&local_38,*(undefined4 *)(ctx + 0xb0),param_2,*puVar3);
        FUN_0010b284(&local_34,*(undefined4 *)(ctx + 0xb0),param_2,local_38);
        iVar2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_34);
        iVar2 = *(int *)(iVar2 + 4);
      }
      if (iVar2 == iVar4) {
        return loopIndex4;
      }
    }
    bVar1 = loopIndex4 != 3;
    loopIndex = loopIndex + 4;
    loopIndex4 = loopIndex4 + 1;
  } while (bVar1);
  loopIndex = 0;
  do {
    iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + iVar2 + 0x10) != '\x01') {
      iVar2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_2);
      loopIndex4 = (uint)*(byte *)(loopIndex + iVar2 + 0x10);
      iVar2 = *(int *)(loopIndex4 * 4 + iVar6 + 0x20);
      if (iVar2 < 0) {
        puVar3 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        FUN_0010b2dc(&local_30,*(undefined4 *)(ctx + 0xb0),param_2,*puVar3);
        FUN_0010b284(local_2c,*(undefined4 *)(ctx + 0xb0),param_2,local_30);
        iVar2 = Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),local_2c[0]);
        iVar2 = *(int *)(iVar2 + 4);
      }
      if (iVar2 == iVar4) {
        return loopIndex4;
      }
    }
    bVar1 = loopIndex == 3;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 4;
    }
  } while( true );
}

/* FUN_00179608 @ 0x179608 (456 bytes) */
int FUN_00179608(ctx, param_2, param_3, param_4)
  int ctx;
  int param_2;
  int param_3;
  int param_4;
{
  int operandRecord2;
  int operandRecord;
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 callResult;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  
  operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),param_3);
  bVar1 = *(byte *)(param_2 + operandRecord + 0x10);
  iVar3 = *(int *)((param_3 * 4 + param_2) * 4 + ctx + 0x168);
  if (iVar3 < 0) {
    iVar4 = *(int *)(ctx + 0xb0);
    if (*(int *)(*(int *)(iVar4 + 0x88) + 8) != 0x8e) {
      puVar8 = *(uint **)(*(int *)(param_3 * 0x18 + iVar4 + 0x8c) + 0x2c);
      uVar7 = puVar8[1];
      uVar6 = uVar7 - 1;
      if (uVar6 < *puVar8) {
        if (uVar7 <= uVar6) {
          _memset(uVar7 * 4 + puVar8[2],0,(uVar6 - uVar7) * 4 + 4);
          puVar8[1] = uVar7;
          iVar4 = *(int *)(ctx + 0xb0);
        }
        piVar2 = (int *)(uVar6 * 4 + puVar8[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar8,uVar6);
        iVar4 = *(int *)(ctx + 0xb0);
      }
      iVar3 = *(int *)((uint)bVar1 * 4 + *piVar2 + 0x20);
    }
  }
  else {
    iVar4 = *(int *)(ctx + 0xb0);
  }
  operandRecord2 = IRInst__getOperandRecord(iVar4,param_4);
  bVar1 = *(byte *)(param_2 + operandRecord2 + 0x10);
  iVar4 = *(int *)((param_4 * 4 + param_2) * 4 + ctx + 0x168);
  if ((iVar4 < 0) && (*(int *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8) != 0x8e)) {
    puVar8 = *(uint **)(*(int *)(param_4 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
    uVar6 = puVar8[1];
    uVar7 = uVar6 - 1;
    if (uVar7 < *puVar8) {
      if (uVar6 <= uVar7) {
        _memset(uVar6 * 4 + puVar8[2],0,(uVar7 - uVar6) * 4 + 4);
        puVar8[1] = uVar6;
      }
      piVar2 = (int *)(uVar7 * 4 + puVar8[2]);
    }
    else {
      piVar2 = (int *)Vector__elementRefGrow(puVar8,uVar7);
    }
    iVar4 = *(int *)((uint)bVar1 * 4 + *piVar2 + 0x20);
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
  undefined4 uVar3;
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
        uVar3 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar2 + 0x198));
        *(undefined4 *)(iVar2 + 0x30) = uVar3;
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00179894 @ 0x179894 (184 bytes) */
int FUN_00179894(ctx, param_2)
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
      iVar1 = ((bool (*)())FUN_0010b820)(iVar1,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
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
  int *piVar3;
  undefined4 uVar4;
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
        piVar3 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          uVar4 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)
                                (((1 - (*piVar3 >> 0x1f)) * 4 + param_2) * 4 + ctx + 0x168));
          *(undefined4 *)(iVar6 + 0x30) = uVar4;
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
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = ((int (*)())FUN_00179608)(ctx,param_2,1,2);
  if (iVar2 != 0) {
    uVar5 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar5 & 1)) && ((uVar1 >> 1 & 1) == (uVar5 >> 1 & 1))) {
      iVar2 = *(int *)(param_2 * 4 + ctx + 0x178);
      if (iVar2 < 0) {
        piVar3 = (int *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar2);
        iVar2 = 1;
        if (0 < *piVar3) {
          iVar2 = 2;
        }
        if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) == 0) &&
           (*(int *)(*(int *)(ctx + 0xb0) + 0x124) == 0)) {
          uVar4 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                               *(undefined4 *)((iVar2 * 4 + param_2) * 4 + ctx + 0x168));
          *(undefined4 *)(param_2 * 4 + ctx + 0x30) = uVar4;
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

/* FUN_00179c44 @ 0x179c44 (124 bytes) */
int FUN_00179c44(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  
  loopIndex = 0;
  while ((iVar2 = IRInst__getOperandRecord(*(undefined4 *)(param_1 + 0xb0),0),
         *(char *)(loopIndex + iVar2 + 0x10) == '\x01' ||
         (iVar2 = ((int (*)())FUN_00179608)(param_1,loopIndex,param_2,param_3), iVar2 != 0))) {
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
  undefined4 uVar5;
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
    uVar5 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + param_2) * 4 + ctx + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = uVar5;
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
  undefined4 uVar4;
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
    uVar4 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar2 + 0x198));
    *(undefined4 *)(iVar2 + 0x30) = uVar4;
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
  undefined4 uVar2;
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
        uVar2 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(iVar1 + 0x178));
        *(undefined4 *)(iVar1 + 0x30) = uVar2;
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
  undefined4 uVar5;
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
    uVar5 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),
                         *(undefined4 *)((loopIndex * 4 + param_2) * 4 + ctx + 0x168));
    *(undefined4 *)(iVar3 + 0x30) = uVar5;
    return 1;
  }
  return 1;
}

/* FUN_0017a034 @ 0x17a034 (252 bytes) */
int FUN_0017a034(ctx, param_2)
  int ctx;
  int param_2;
{
  undefined4 uVar1;
  uint uVar2;
  float *pfVar3;
  float *exprRecord;
  int iVar5;
  int member0xb0;
  int iVar7;
  
  iVar7 = param_2 * 4 + ctx;
  uVar1 = 0;
  if (*(int *)(iVar7 + 0x178) < 0) {
    pfVar3 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),*(int *)(iVar7 + 0x178));
    exprRecord = (float *)Compiler__valueNumberForExpr(*(undefined4 *)(ctx + 0x238),0);
    iVar5 = ((bool (*)())FUN_0010b820)(*(undefined4 *)(ctx + 0xb0),(double)*pfVar3,(double)*exprRecord);
    member0xb0 = *(int *)(ctx + 0xb0);
    iVar5 = (iVar5 == 0) + 2;
    if ((((*(int *)(member0xb0 + 0x120) == 0) && (*(int *)(member0xb0 + 0x124) == 0)) &&
        (uVar2 = *(uint *)(iVar5 * 0x18 + member0xb0 + 0xa0), (uVar2 & 1) == 0)) && ((uVar2 & 2) == 0)) {
      iVar5 = *(int *)((iVar5 * 4 + param_2) * 4 + ctx + 0x168);
      if (iVar5 < 0) {
        uVar1 = Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar5);
        *(undefined4 *)(iVar7 + 0x30) = uVar1;
        return 1;
      }
      uVar1 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar5);
      *(undefined4 *)(iVar7 + 0x40) = uVar1;
      return 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0017a130 @ 0x17a130 (284 bytes) */
int FUN_0017a130(param_1, param_2, inst, compiler)
  int param_1;
  float *param_2;
  int inst;
  int compiler;
{
  int operandRecord;
  undefined4 arenaAt378;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = DAT_001b01d8;
  if (param_1 == 0) {
    *(undefined4 *)(inst + 0x9c) = DAT_001b01d8;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,param_1);
    *(undefined4 *)(operandRecord + 0x10) = uVar4;
  }
  ((void (*)())FUN_000f79c4)(inst,*(undefined4 *)(compiler + COMP_currentProgram),param_1,(double)*param_2,(double)param_2[1],
               (double)param_2[2],(double)param_2[3]);
  piVar1 = *(int **)(*(int *)(param_1 * 0x18 + inst + 0x8c) + 0x18);
  if (*piVar1 == 0) {
    piVar1 = (int *)Vector__elementRefGrow(piVar1,0);
  }
  else {
    if (piVar1[1] == 0) {
      *(undefined4 *)piVar1[2] = 0;
      piVar1[1] = 1;
    }
    piVar1 = (int *)piVar1[2];
  }
  iVar5 = *piVar1;
  iVar3 = *(int *)(iVar5 + 0x8c);
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(compiler + COMP_arenaB);
    puVar2 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    puVar6 = puVar2 + 1;
    *puVar2 = arenaAt378;
    ValueKey__init(puVar6,iVar5,compiler);
    FUN_00174e0c(puVar6);
    ValueKey__propagateLaneValues(puVar6);
    VReg__pushDefinition(iVar3,*(undefined4 *)(*(int *)(iVar5 + 0x158) + 0xb0),puVar6);
  }
  IRInst__setOperandRef(inst,param_1,iVar3);
  return iVar5;
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
    FUN_00104be8(member0xb0,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x214) = uVar3;
    ((void (*)())FUN_000f79c4)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1,(double)*param_2
                 ,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
    FUN_00104be8(*(undefined4 *)(ctx + 0xb0),2);
    local_24 = DAT_001b01ec;
    local_28 = DAT_001b01e8;
    local_20 = DAT_001b01f0;
    local_1c = DAT_001b01f4;
    uVar3 = ((int (*)())FUN_0017a130)(2,&local_28,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x218) = uVar3;
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  else if (iVar1 == 0x8c) {
    FUN_00104be8(member0xb0,1);
    uVar3 = ((int (*)())FUN_0017a130)(1,param_2,*(undefined4 *)(ctx + 0xb0),param_3);
    *(undefined4 *)(ctx + 0x214) = uVar3;
    ((void (*)())FUN_000f79c4)(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(param_3 + 0x6c4),1,(double)*param_2
                 ,(double)param_2[1],(double)param_2[2],(double)param_2[3]);
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 300) = 0;
  }
  return;
}

/* FUN_0017a3d4 @ 0x17a3d4 (884 bytes) */
int FUN_0017a3d4(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float *loopIndex3;
  float *loopIndex4;
  int loopIndex2;
  float *pfVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  int *piVar14;
  int *loopIndex5;
  bool bVar16;
  int loopIndex;
  int loopRemaining;
  int local_94 [2];
  float local_8c [9];
  int local_68;
  
  loopIndex = 4;
  pfVar12 = local_8c + 3;
  loopIndex3 = pfVar12;
  do {
    *loopIndex3 = GH_U2F(0x7fff0000U);
    loopIndex3 = loopIndex3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex = 0;
  loopRemaining = 4;
  do {
    *(undefined4 *)(loopIndex + (int)pfVar12) = 0;
    loopIndex = loopIndex + 4;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  bVar16 = false;
  local_68 = 1;
  loopIndex = 0;
  loopRemaining = ctx + 0x170;
  loopIndex3 = pfVar12;
  fVar3 = FLOAT_001aa114;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    loopIndex4 = local_8c;
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      do {
        *loopIndex4 = GH_U2F(0x7fff0000U);
        loopIndex4 = loopIndex4 + 1;
      } while (pfVar12 != loopIndex4);
      piVar14 = (int *)(loopRemaining + 8);
      bVar2 = true;
      loopIndex2 = 1;
      loopIndex5 = local_94;
      iVar13 = 0x98;
      loopIndex4 = local_8c;
      do {
        loopIndex4 = loopIndex4 + 1;
        *loopIndex5 = 0;
        iVar11 = *piVar14;
        if (iVar11 < 0) {
          pfVar9 = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar11);
          *loopIndex4 = *pfVar9;
          iVar11 = FUN_00176324(*(unsigned int *)pfVar9);
          *loopIndex5 = iVar11;
        }
        else {
          if (iVar11 < 1) {
            return 0;
          }
          iVar11 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar11);
          iVar10 = *(int *)(iVar11 + 0xc);
          *loopIndex5 = iVar10;
          iVar11 = *(int *)(ctx + 0xb0) + iVar13;
          uVar4 = *(uint *)(iVar11 + 0x20);
          if ((uVar4 & 2) != 0) {
            *loopIndex5 = (DAT_001e61d0)[iVar10];
            uVar4 = *(uint *)(iVar11 + 0x20);
          }
          if ((uVar4 & 1) == 0) {
            iVar11 = *loopIndex5;
            bVar16 = true;
            bVar2 = false;
          }
          else {
            bVar16 = true;
            bVar2 = false;
            iVar11 = *(int *)(&DAT_001e61b8 + *loopIndex5 * 4);
            *loopIndex5 = iVar11;
          }
        }
        iVar10 = local_94[0];
        if (iVar11 == 0) {
          return 0;
        }
        bVar1 = loopIndex2 != 2;
        iVar13 = iVar13 + 0x18;
        loopIndex5 = loopIndex5 + 1;
        piVar14 = piVar14 + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      if (bVar2) {
        loopIndex2 = ((bool (*)())FUN_0010b820)(*(undefined4 *)(ctx + 0xb0),(double)local_8c[1],(double)local_8c[2]
                            );
        fVar5 = 0.0;
        if (loopIndex2 == 0) {
LAB_0017a608:
          fVar5 = 1.0;
        }
        *loopIndex3 = fVar5;
      }
      else {
        loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
        loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + iVar10 * 0x30 + local_94[1]) * 4);
        if (loopIndex2 == 1) {
          *loopIndex3 = 0.0;
        }
        else {
          if (loopIndex2 == 2) goto LAB_0017a608;
          if (loopIndex2 == 0) {
            return 0;
          }
        }
      }
      if (fVar3 == FLOAT_001aa114) {
        fVar3 = *loopIndex3;
      }
      else if (*loopIndex3 != fVar3) {
        local_68 = 0;
      }
    }
    bVar2 = loopIndex == 3;
    loopRemaining = loopRemaining + 4;
    loopIndex3 = loopIndex3 + 1;
    loopIndex = loopIndex + 1;
    if (bVar2) {
      if (bVar16) {
        loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
        *(int *)(loopIndex + 0x134) = *(int *)(loopIndex + 0x134) + 1;
      }
      ((int (*)())FUN_0017a294)(ctx,pfVar12,*(undefined4 *)(ctx + 0x238));
      loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
      if ((loopIndex != 0) && (local_68 != 0)) {
        loopIndex5 = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
        bVar16 = fVar3 != FLOAT_001aa0d4;
        loopIndex = (**(code **)(*loopIndex5 + 0x24))(loopIndex5);
        if (loopIndex != 0) {
          if (bVar16) {
            loopIndex = loopIndex5[0x4d];
          }
          else {
            loopIndex = loopIndex5[0x4e];
          }
          FUN_0012cfa4(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),loopIndex5,loopIndex,
                       loopIndex5[0x4f]);
          if (bVar16) {
            loopIndex = 2;
          }
          else {
            loopIndex = 1;
          }
          loopIndex5[0x53] = loopIndex;
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
  undefined4 *loopIndex2;
  int loopRemaining;
  int iVar5;
  uint uVar6;
  undefined4 *loopIndex3;
  int loopIndex;
  undefined4 local_38 [8];
  
  loopRemaining = ((int (*)())FUN_00179c44)(ctx,1,2);
  if (loopRemaining != 0) {
    uVar6 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar6 & 1)) && ((uVar2 >> 1 & 1) == (uVar6 >> 1 & 1))) {
      loopIndex3 = local_38;
      loopRemaining = 4;
      loopIndex2 = loopIndex3;
      do {
        *loopIndex2 = 0x7ffffffe;
        loopIndex2 = loopIndex2 + 1;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
      loopRemaining = 0;
      loopIndex = 4;
      do {
        *(undefined4 *)(loopRemaining + (int)loopIndex3) = 0;
        loopRemaining = loopRemaining + 4;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      loopRemaining = FUN_00176324(0);
      loopIndex = 0;
      do {
        operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
          iVar5 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
          if (*(int *)(&DAT_001e61e8 + (iVar5 * 6 + loopRemaining * 0x31) * 4) == 1) {
            *loopIndex3 = 0;
          }
          else if (*(int *)(&DAT_001e61e8 + (iVar5 * 6 + loopRemaining * 0x31) * 4) == 2) {
            *loopIndex3 = 0x3f800000;
          }
        }
        bVar1 = loopIndex != 3;
        loopIndex3 = loopIndex3 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      ((int (*)())FUN_0017a294)(ctx,local_38,*(undefined4 *)(ctx + 0x238));
      FUN_001745ac(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017a8a4 @ 0x17a8a4 (680 bytes) */
int FUN_0017a8a4(ctx)
  int ctx;
{
  int operandRecord;
  bool bVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  uint *loopIndex2;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int loopIndex;
  int *piVar11;
  int loopRemaining;
  int loopRemaining2;
  uint local_58;
  
  loopRemaining = 4;
  loopIndex2 = &local_58;
  do {
    *loopIndex2 = 0x7ffffffe;
    loopIndex2 = loopIndex2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  loopRemaining = 0;
  loopRemaining2 = 4;
  do {
    *(undefined4 *)(loopRemaining + (int)&local_58) = 0;
    loopRemaining = loopRemaining + 4;
    loopRemaining2 = loopRemaining2 + -1;
  } while (loopRemaining2 != 0);
  loopRemaining2 = FUN_00176324(0);
  bVar3 = false;
  fVar2 = -1.0;
  bVar4 = true;
  loopIndex = 0;
  iVar9 = 0;
  loopRemaining = ctx;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
      iVar6 = *(int *)(loopRemaining + 0x178);
      if (iVar6 < 0) {
        puVar7 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(ctx + 0x238),iVar6);
        iVar6 = FUN_00176324(*puVar7);
        iVar8 = *(int *)(ctx + 0xb0);
      }
      else {
        if (iVar6 < 1) {
          return 0;
        }
        iVar6 = Compiler__findInPtrSet(*(undefined4 *)(ctx + 0x238),iVar6);
        iVar8 = *(int *)(ctx + 0xb0);
        iVar6 = *(int *)(iVar6 + 0xc);
        if ((*(uint *)(iVar8 + 0xb8) & 2) != 0) {
          iVar6 = (DAT_001e61d0)[iVar6];
        }
        bVar3 = true;
        if ((*(uint *)(iVar8 + 0xb8) & 1) != 0) {
          iVar6 = *(int *)(&DAT_001e61b8 + iVar6 * 4);
        }
      }
      iVar8 = IRInst__getCompareCondition(iVar8);
      iVar6 = *(int *)(&DAT_001e61e8 + (iVar8 * 6 + iVar6 * 0x30 + loopRemaining2) * 4);
      if (iVar6 == 1) {
        *(undefined4 *)(iVar9 + (int)&local_58) = 0;
      }
      else if (iVar6 == 2) {
        *(undefined4 *)(iVar9 + (int)&local_58) = 0x3f800000;
      }
      else if (iVar6 == 0) {
        return 0;
      }
      if (fVar2 == -1.0) {
        fVar2 = *(float *)(iVar9 + (int)&local_58);
      }
      else if (*(float *)(iVar9 + (int)&local_58) != fVar2) {
        bVar4 = false;
      }
    }
    bVar1 = loopIndex != 3;
    iVar9 = iVar9 + 4;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  if (bVar3) {
    loopRemaining = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopRemaining + 0x134) = *(int *)(loopRemaining + 0x134) + 1;
  }
  ((int (*)())FUN_0017a294)(ctx,&local_58,*(undefined4 *)(ctx + 0x238));
  loopRemaining = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xd);
  if ((loopRemaining != 0) && (bVar4)) {
    piVar11 = *(int **)(*(int *)(ctx + 0xb0) + 0x158);
    loopRemaining = (**(code **)(*piVar11 + 0x24))(piVar11);
    if (loopRemaining != 0) {
      if (fVar2 != 0.0) {
        loopRemaining = piVar11[0x4d];
      }
      else {
        loopRemaining = piVar11[0x4e];
      }
      FUN_0012cfa4(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),piVar11,loopRemaining,piVar11[0x4f]);
      if (fVar2 != 0.0) {
        loopRemaining = 2;
      }
      else {
        loopRemaining = 1;
      }
      piVar11[0x53] = loopRemaining;
      return 1;
    }
  }
  return 1;
}

/* FUN_0017ab4c @ 0x17ab4c (472 bytes) */
int FUN_0017ab4c(ctx)
  int ctx;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int *a0;
  int iVar5;
  int loopIndex;
  undefined4 *loopIndex2;
  double fparam_1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48 [7];
  
  loopIndex = 1;
  iVar5 = 0x98;
  loopIndex2 = (undefined4 *)(ctx + 0x214);
  do {
    ((int (*)())FUN_00178d78)(local_48,ctx,loopIndex);
    if ((GH_F2U(local_48[0]) != 0x7ffffffeU)) {
      bVar1 = -1 < (int)GH_F2U(local_48[0]);
      if (bVar1) {
        fparam_1 = (double)local_48[0];
      }
      else {
        fparam_1 = -(double)local_48[0];
      }
      if ((fparam_1 != 1.0) && (iVar2 = ((undefined4 (*)())FUN_0010aafc)(fparam_1), iVar2 != 0)) {
        iVar2 = ((int (*)())FUN_0010ab40)(fparam_1);
        a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        iVar2 = iVar2 + *(int *)(*(int *)(ctx + 0xb0) + 0x124);
        iVar3 = (**(code **)(*a0 + 0xfc))(a0,iVar2,*(int *)(ctx + 0xb0),in_r6,in_r7,in_r8,a0);
        if (iVar3 != 0) {
          local_58 = 0x3f800000;
          local_54 = 0x3f800000;
          local_50 = 0x3f800000;
          local_4c = 0x3f800000;
          uVar4 = ((int (*)())FUN_0017a130)(loopIndex,&local_58,*(undefined4 *)(ctx + 0xb0),
                               *(undefined4 *)(ctx + 0x238));
          iVar3 = *(int *)(ctx + 0xb0);
          *loopIndex2 = uVar4;
          *(int *)(iVar3 + 0x124) = iVar2;
          IROperand__setModifierBits(iVar5 + *(int *)(ctx + 0xb0) + 0xc,1,0);
          IROperand__setModifierBits(iVar5 + *(int *)(ctx + 0xb0) + 0xc,2,0);
          if (!bVar1) {
            iVar5 = *(int *)(ctx + 0xb0) + ((loopIndex == 1) - 1) * 0x18 + 0xb0;
            IROperand__setModifierBits(iVar5 + 0xc,1,(*(uint *)(iVar5 + 0x20) ^ 1) & 1);
          }
          FUN_001745ac(ctx);
          return 1;
        }
      }
    }
    bVar1 = loopIndex != 2;
    loopIndex2 = loopIndex2 + 1;
    iVar5 = iVar5 + 0x18;
    loopIndex = loopIndex + 1;
  } while (bVar1);
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
  undefined4 uVar4;
  int loopRemaining;
  undefined4 local_38 [8];
  
  uVar4 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158);
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
  Block__insertInstAfter(uVar4,iVar1,callResult);
  return callResult;
}

/* FUN_0017ae28 @ 0x17ae28 (172 bytes) */
int FUN_0017ae28(ctx, param_2, param_3, param_4, param_5, param_6, compiler)
  int ctx;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int compiler;
{
  int operandRecord;
  undefined4 *allocation;
  undefined4 arena;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(param_3 + 0x8c);
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x240);
    puVar4 = allocation + 1;
    *allocation = arena;
    ValueKey__init(puVar4,param_3,compiler);
    FUN_00174e0c(puVar4);
    ValueKey__propagateLaneValues(puVar4);
    VReg__pushDefinition(iVar3,*(undefined4 *)(*(int *)(param_3 + 0x158) + 0xb0),puVar4);
  }
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),param_2,iVar3);
  if (param_2 == 0) {
    *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x9c) = param_4;
  }
  else {
    operandRecord = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),param_2);
    *(undefined4 *)(operandRecord + 0x10) = param_4;
  }
  iVar3 = param_2 * 0x18 + 0x80;
  IROperand__setModifierBits(iVar3 + *(int *)(ctx + 0xb0) + 0xc,1,param_5);
  IROperand__setModifierBits(iVar3 + *(int *)(ctx + 0xb0) + 0xc,2,param_6);
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
  undefined4 *puVar5;
  int iVar6;
  int *loopIndex2;
  undefined4 local_28 [6];
  
  loopIndex2 = (int *)(param_3 * 0x10 + param_2 + 0x168);
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
        iVar6 = *loopIndex2;
        bVar1 = iVar6 < 0;
        bVar2 = iVar6 == 0;
      }
      else if (*loopIndex2 != iVar6) goto LAB_0017affc;
    }
    loopIndex = loopIndex + 1;
    loopIndex2 = loopIndex2 + 1;
    loopRemaining = loopRemaining + -1;
  } while (loopRemaining != 0);
  if (bVar1) {
    puVar5 = (undefined4 *)Compiler__exprRecordForValueNumber(*(undefined4 *)(param_2 + 0x238),iVar6);
    *param_1 = *puVar5;
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
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = *(uint **)(*(int *)(param_2 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
  uVar3 = puVar5[1];
  uVar4 = uVar3 - 1;
  if (uVar4 < *puVar5) {
    if (uVar3 <= uVar4) {
      _memset(uVar3 * 4 + puVar5[2],0,(uVar4 - uVar3) * 4 + 4);
      puVar5[1] = uVar3;
    }
    piVar1 = (int *)(uVar4 * 4 + puVar5[2]);
  }
  else {
    piVar1 = (int *)Vector__elementRefGrow(puVar5,uVar4);
  }
  iVar6 = *piVar1;
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
  undefined4 sourceDef;
  int operandRecord;
  int operandRecord2;
  bool bVar1;
  byte bVar2;
  int *piVar3;
  undefined4 uVar4;
  int loopIndex2;
  int iVar6;
  int loopIndex3;
  int *loopIndex7;
  float *literalRecord;
  int iVar10;
  int *loopIndex5;
  int *loopIndex6;
  undefined4 *loopIndex8;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a6;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined1 *loopIndex9;
  uint uVar18;
  char *loopIndex4;
  uint *puVar20;
  int loopIndex;
  double fparam_1;
  undefined8 uVar22;
  int local_138 [6];
  undefined1 local_120 [4];
  int local_11c [4];
  undefined4 local_10c [4];
  undefined4 uStack_fc;
  undefined4 local_f8 [5];
  undefined4 local_e4 [23];
  float local_88;
  int changed;
  int *local_80;
  undefined1 *local_7c;
  int *local_78;
  undefined *local_74;
  undefined4 *local_70;
  undefined *local_6c;
  int *local_68;
  
  loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0xb);
  if (((loopIndex2 == 0) || (loopIndex2 = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0x3a), loopIndex2 == 0)) ||
     (*(int *)(*(int *)(key + 0x238) + 0x664) <=
      *(int *)(*(int *)(*(int *)(key + 0x238) + 0x6c4) + 0x228))) {
    changed = 0;
  }
  else {
    local_70 = local_e4;
    loopIndex2 = 0;
    do {
      loopIndex8 = local_70 + loopIndex2 * 4;
      loopIndex = 4;
      do {
        *loopIndex8 = 0xbf800000;
        loopIndex8 = loopIndex8 + 1;
        loopIndex = loopIndex + -1;
      } while (loopIndex != 0);
      bVar1 = loopIndex2 != 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
    local_74 = &DAT_001ab134;
    local_7c = local_120;
    loopIndex = 5;
    local_6c = &DAT_001ab134;
    loopIndex2 = 0;
    do {
      *(undefined4 *)((int)local_138 + loopIndex2 + 4) = 0;
      loopIndex9 = local_7c;
      *(undefined4 *)((int)local_10c + loopIndex2) = 0x1010101;
      *(undefined4 *)(loopIndex9 + loopIndex2) = 0;
      *(undefined4 *)((int)local_f8 + loopIndex2) = 0x4040404;
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopIndex7 = local_138 + 2;
    loopIndex6 = local_11c;
    local_68 = local_138;
    loopIndex = key + 0x170;
    iVar14 = key + 0x224;
    loopIndex2 = 0x18;
    changed = 0;
    local_80 = loopIndex7;
    local_78 = loopIndex6;
    for (iVar15 = 1;
        loopIndex3 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        iVar15 <= loopIndex3; iVar15 = iVar15 + 1) {
      loopIndex3 = *(int *)(key + 0xb0);
      if ((iVar15 < 1) || (iVar10 = IRInst__getOperandSource(loopIndex3,iVar15), iVar10 == 0)) {
        uVar4 = *(undefined4 *)(loopIndex2 + loopIndex3 + 0x98);
      }
      else {
        loopIndex3 = IRInst__getOperandSource(loopIndex3,iVar15);
        uVar4 = *(undefined4 *)(loopIndex3 + 0x98);
      }
      loopIndex3 = RegKind__flagBit6(uVar4);
      if (loopIndex3 == 0) {
        loopIndex4 = (char *)(iVar14 + 4);
        loopIndex5 = (int *)(loopIndex + 8);
        loopIndex3 = 0;
        do {
          if (*loopIndex4 != '\0') {
            operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),iVar15);
            piVar3 = local_68;
            bVar2 = *(byte *)(loopIndex3 + operandRecord2 + 0x10);
            iVar10 = (uint)bVar2 + iVar15 * 4;
            *(undefined1 *)((int)local_68 + iVar10 + 0x2c) = 0;
            *(byte *)((int)local_68 + iVar10 + 0x40) = bVar2;
            if (*loopIndex5 < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),*loopIndex5);
              iVar6 = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                ((double)*literalRecord);
              if (iVar6 != 0) {
                if (*loopIndex7 == 0) {
                  iVar6 = ((int (*)())FUN_00179138)(key,iVar15);
                  *loopIndex7 = iVar6;
                  *loopIndex6 = 1;
                  changed = 1;
                }
                uVar22 = ((int (*)())FUN_00176474)(iVar6,local_70,iVar15,(double)*literalRecord);
                iVar6 = (int)((ulonglong)uVar22 >> 0x20);
                if (*loopIndex6 < iVar6) {
                  ((void (*)())FUN_0010bd50)(*loopIndex7,(int)uVar22,iVar6,*(undefined4 *)(key + 0x238),
                               (double)*literalRecord);
                  *loopIndex6 = iVar6;
                }
                a6 = *(code **)(*(int *)*loopIndex7 + 0x88);
                (*a6)((int *)*loopIndex7,iVar6,(uint)bVar2,loopIndex3,in_r7,in_r8,a6);
                *(undefined1 *)((int)piVar3 + iVar10 + 0x40) = 4;
              }
            }
          }
          bVar1 = loopIndex3 != 3;
          loopIndex4 = loopIndex4 + 1;
          loopIndex5 = loopIndex5 + 1;
          loopIndex3 = loopIndex3 + 1;
        } while (bVar1);
      }
      loopIndex2 = loopIndex2 + 0x18;
      iVar14 = iVar14 + 4;
      loopIndex = loopIndex + 0x10;
      loopIndex7 = loopIndex7 + 1;
      loopIndex6 = loopIndex6 + 1;
    }
    loopIndex2 = 0;
    loopIndex = 5;
    do {
      loopIndex9 = local_7c;
      if (*(int *)((int)local_138 + loopIndex2 + 4) == 0) {
        uVar4 = *(undefined4 *)(((unsigned char *)0x000050a8) + (int)local_74);
        *(undefined4 *)((int)local_10c + loopIndex2) = *(undefined4 *)(((unsigned char *)0x0000509c) + (int)local_6c);
        *(undefined4 *)(loopIndex9 + loopIndex2) = 0;
        *(undefined4 *)((int)local_f8 + loopIndex2) = uVar4;
      }
      loopIndex2 = loopIndex2 + 4;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopIndex7 = *(int **)(key + 0xb0);
    if ((((loopIndex7[5] & 0x200U) != 0) && (loopIndex7[0x48] == 0)) && (loopIndex7[0x49] == 0)) {
      loopIndex2 = ((int (*)())FUN_001789f0)(key);
      if (loopIndex2 != 0) {
        loopIndex = 0;
        loopIndex2 = key;
        do {
          operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
          if (*(char *)(loopIndex + operandRecord + 0x10) == '\x01') {
            iVar14 = *(int *)(key + 0xb0);
            puVar20 = *(uint **)(*(int *)(*(int *)(iVar14 + 0x84) * 0x18 + iVar14 + 0x8c) + 0x2c);
            uVar18 = puVar20[1];
            uVar16 = uVar18 - 1;
            if (uVar16 < *puVar20) {
              if (uVar18 <= uVar16) {
                _memset(uVar18 * 4 + puVar20[2],0,(uVar16 - uVar18) * 4 + 4);
                puVar20[1] = uVar18;
                iVar14 = *(int *)(key + 0xb0);
              }
              loopIndex7 = (int *)(uVar16 * 4 + puVar20[2]);
            }
            else {
              loopIndex7 = (int *)Vector__elementRefGrow(puVar20,uVar16);
              iVar14 = *(int *)(key + 0xb0);
            }
            iVar15 = *loopIndex7;
            operandRecord = IRInst__getOperandRecord(iVar14,0);
            local_138[0] = *(int *)(operandRecord + 0x10);
            iVar14 = *(int *)(loopIndex * 4 + iVar15 + 0x20);
            if (iVar14 < 0) {
              literalRecord = (float *)Compiler__exprRecordForValueNumber(*(undefined4 *)(key + 0x238),iVar14);
              iVar14 = (**(code **)(**(int **)(*(int *)(key + 0x238) + 0x30c) + 0xf0))
                                 ((double)*literalRecord);
              if (iVar14 != 0) {
                loopIndex7 = local_80;
                loopIndex6 = local_78;
                for (iVar14 = 1;
                    iVar15 = (**(code **)(**(int **)(key + 0xb0) + 0x14))
                                       (*(int **)(key + 0xb0)), iVar14 <= iVar15;
                    iVar14 = iVar14 + 1) {
                  if (*loopIndex7 == 0) {
                    loopIndex3 = ((int (*)())FUN_00179138)(key,iVar14);
                    iVar15 = iVar14 * 4;
                    *loopIndex7 = loopIndex3;
                    *loopIndex6 = 1;
                    loopIndex9 = (undefined1 *)((int)local_f8 + iVar14 * 4);
                    loopIndex8 = local_10c + iVar14;
                    loopIndex3 = 0;
                    do {
                      if (*(char *)((int)local_138 + loopIndex3) == '\0') {
                        operandRecord2 = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),iVar14);
                        *loopIndex9 = *(undefined1 *)(loopIndex3 + operandRecord2 + 0x10);
                        *(undefined1 *)loopIndex8 = 0;
                        (**(code **)(**(int **)(key + 0xb0) + 0x88))
                                  (*(int **)(key + 0xb0),iVar14,loopIndex3,loopIndex3);
                      }
                      bVar1 = loopIndex3 != 3;
                      loopIndex9 = loopIndex9 + 1;
                      loopIndex8 = (undefined4 *)((int)loopIndex8 + 1);
                      loopIndex3 = loopIndex3 + 1;
                    } while (bVar1);
                    changed = 1;
                  }
                  else {
                    iVar15 = iVar14 << 2;
                  }
                  uVar4 = FUN_0010b93c(&local_88, *(undefined4 *)(key + 0xb0), iVar14, *(unsigned int *)literalRecord, *(undefined4 *)(key + 0x238));
                  fparam_1 = (double)local_88;
                  uVar22 = ((int (*)())FUN_00176474)(uVar4,local_70,iVar14,fparam_1);
                  loopIndex3 = (int)((ulonglong)uVar22 >> 0x20);
                  if (*loopIndex6 < loopIndex3) {
                    ((void (*)())FUN_0010bd50)(*loopIndex7,(int)uVar22,loopIndex3,*(undefined4 *)(key + 0x238),fparam_1
                                );
                    *loopIndex6 = loopIndex3;
                  }
                  loopIndex6 = loopIndex6 + 1;
                  iVar10 = FUN_000f3108(*(undefined4 *)((int)local_10c + iVar15));
                  loopIndex5 = (int *)*loopIndex7;
                  loopIndex7 = loopIndex7 + 1;
                  (**(code **)(*loopIndex5 + 0x88))(loopIndex5,loopIndex3,iVar10,iVar10);
                  *(undefined1 *)((int)local_10c + iVar10 + iVar15) = 0;
                  (**(code **)(**(int **)(key + 0xb0) + 0x88))
                            (*(int **)(key + 0xb0),iVar14,loopIndex,iVar10);
                }
                *(undefined1 *)(loopIndex + *(int *)(key + 0xb0) + 0x9c) = 0;
                *(float **)(loopIndex2 + 0x30) = literalRecord;
              }
            }
          }
          bVar1 = loopIndex != 3;
          loopIndex2 = loopIndex2 + 4;
          loopIndex = loopIndex + 1;
        } while (bVar1);
      }
      loopIndex7 = *(int **)(key + 0xb0);
    }
    loopIndex2 = 1;
    while (loopIndex = (**(code **)(*loopIndex7 + 0x14))(loopIndex7), loopIndex2 <= loopIndex) {
      loopIndex = loopIndex2 + 1;
      iVar14 = local_138[loopIndex];
      if (iVar14 != 0) {
        *(int *)(iVar14 + 0x9c) = local_11c[loopIndex2 + 4];
        uVar4 = (&uStack_fc)[loopIndex];
        loopIndex2 = IRInst__getOperandRecord(iVar14,1);
        *(undefined4 *)(loopIndex2 + 0x10) = uVar4;
        FUN_0010c37c(iVar14,*(undefined4 *)(key + 0x238));
      }
      loopIndex7 = *(int **)(key + 0xb0);
      loopIndex2 = loopIndex;
    }
    loopIndex7 = local_138 + 2;
    for (loopIndex2 = 1;
        loopIndex = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        loopIndex2 <= loopIndex; loopIndex2 = loopIndex2 + 1) {
      loopIndex = *loopIndex7;
      if (loopIndex != 0) {
        loopIndex6 = (int *)IRInst__getOperandSource(loopIndex,1);
        iVar14 = (**(code **)(*loopIndex6 + 0x60))(loopIndex6);
        if (iVar14 != 0) {
          sourceDef = IRInst__getOperandSource(loopIndex,1);
          FUN_0010c670(sourceDef,loopIndex,*(undefined4 *)(key + 0x238));
        }
      }
      loopIndex7 = loopIndex7 + 1;
    }
    loopIndex7 = local_138 + 2;
    loopIndex = 0x18;
    loopIndex2 = key;
    for (iVar14 = 1;
        iVar15 = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
        iVar14 <= iVar15; iVar14 = iVar14 + 1) {
      iVar15 = *loopIndex7;
      if (iVar15 != 0) {
        puVar20 = *(uint **)(*(int *)(loopIndex + *(int *)(key + 0xb0) + 0x8c) + 0x2c);
        uVar16 = puVar20[1];
        uVar18 = uVar16 - 1;
        if (uVar18 < *puVar20) {
          if (uVar16 <= uVar18) {
            _memset(uVar16 * 4 + puVar20[2],0,(uVar18 - uVar16) * 4 + 4);
            puVar20[1] = uVar16;
          }
          loopIndex8 = (undefined4 *)(uVar18 * 4 + puVar20[2]);
        }
        else {
          loopIndex8 = (undefined4 *)Vector__elementRefGrow(puVar20,uVar18);
        }
        uVar4 = *loopIndex8;
        ValueKey__fillSourceLaneUsage(uVar4);
        ValueKey__fill(uVar4);
        FUN_00174e0c(uVar4);
        FUN_00175b40(uVar4);
        ValueKey__propagateLaneValues(uVar4);
        *(int *)(loopIndex2 + 0x214) = iVar15;
      }
      loopIndex7 = loopIndex7 + 1;
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
  bool bVar1;
  bool bVar2;
  int loopIndex3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int loopIndex;
  uint *puVar12;
  int loopIndex2;
  undefined4 local_38 [8];
  
  if ((*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) ||
     (loopIndex3 = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0)), loopIndex3 == 0
     )) {
    return 0;
  }
  loopIndex3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
  loopIndex3 = FUN_000f3190(*(undefined4 *)(loopIndex3 + 0x10));
  if (loopIndex3 == 0) {
    loopIndex3 = *(int *)(ctx + 0xb0);
    puVar12 = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    uVar9 = puVar12[1];
    uVar7 = uVar9 - 1;
    if (uVar7 < *puVar12) {
      if (uVar9 <= uVar7) {
        _memset(uVar9 * 4 + puVar12[2],0,(uVar7 - uVar9) * 4 + 4);
        puVar12[1] = uVar9;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      piVar4 = (int *)(uVar7 * 4 + puVar12[2]);
    }
    else {
      piVar4 = (int *)Vector__elementRefGrow(puVar12,uVar7);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    iVar10 = *piVar4;
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
    puVar12 = *(uint **)(*(int *)(loopIndex3 + 0xa4) + 0x2c);
    uVar9 = puVar12[1];
    uVar7 = uVar9 - 1;
    if (uVar7 < *puVar12) {
      if (uVar9 <= uVar7) {
        _memset(uVar9 * 4 + puVar12[2],0,(uVar7 - uVar9) * 4 + 4);
        puVar12[1] = uVar9;
        loopIndex3 = *(int *)(ctx + 0xb0);
      }
      puVar5 = (undefined4 *)(uVar7 * 4 + puVar12[2]);
    }
    else {
      puVar5 = (undefined4 *)Vector__elementRefGrow(puVar12,uVar7);
      loopIndex3 = *(int *)(ctx + 0xb0);
    }
    uVar7 = *(uint *)(loopIndex3 + 0xb8);
    loopIndex = 0;
    uVar8 = *puVar5;
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

