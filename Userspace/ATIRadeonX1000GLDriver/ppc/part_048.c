#include "decls.h"

/* FUN_0017bc58 @ 0x17bc58 (288 bytes) */
int FUN_0017bc58(inst, param_2, param_3, param_4)
  undefined4 inst;
  uint param_2;
  int param_3;
  undefined4 param_4;
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
    if ((callResult == 0) && (FUN_000f3908(local_28,uVar4), (param_2 & local_28[0]) != DAT_001b01e0)) {
      return callResult2;
    }
    callResult2 = (int *)IRInst__getOperandSource(callResult2,3);
  }
  if ((param_3 != 0) && (piVar2 = (int *)IRInst__getOperandSource(inst,1), callResult2 != piVar2)) {
    IRInst__setOperandSource(inst,1,callResult2,0,param_4);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* FUN_0017bd78 @ 0x17bd78 (388 bytes) */
int FUN_0017bd78(ctx, param_2, param_3, param_4)
  int ctx;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 local_58;
  
  iVar4 = *(int *)(ctx + 0xb0);
  uVar8 = *(undefined4 *)(iVar4 + 4);
  uVar9 = *(undefined4 *)(iVar4 + 0x158);
  DList__unlink(iVar4);
  uVar13 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar5 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  iVar4 = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar14 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = IRInst__getOperandRecord(iVar4,param_2);
  iVar5 = *(int *)(ctx + 0xb0);
  bVar2 = *(byte *)(param_3 + iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar10 = *(undefined4 *)(param_2 * 4 + ctx + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar7 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + ctx + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar5,0,uVar13);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  *(undefined4 *)(iVar5 + 0x9c) = uVar11;
  *(undefined4 *)(iVar5 + 0x120) = uVar14;
  *(undefined4 *)(iVar5 + 0x124) = param_4;
  IRInst__setOperandRef(iVar5,1,uVar12);
  uVar11 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)bVar2 * 4);
  iVar4 = IRInst__getOperandRecord(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar11;
  IROperand__setModifierBits(iVar5 + 0xa4,1,uVar3 & 1);
  IROperand__setModifierBits(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = uVar10;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(iVar5,uVar7);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = local_58;
  }
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(uVar9,uVar8,iVar5);
  return iVar5;
}

/* FUN_0017bf70 @ 0x17bf70 (392 bytes) */
int FUN_0017bf70(ctx)
  int ctx;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
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
  iVar2 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0);
  iVar2 = *(int *)(iVar2 + 4);
  do {
    a3 = 1;
    a4 = 1;
    a5 = 0;
    iVar3 = FUN_00176854(ctx,loopRemaining,1,1,1,0);
    if (iVar3 != 0) {
      loopIndex = 0;
      piVar9 = &DAT_001e6134;
      iVar3 = loopRemaining * 4;
      do {
        if ((iVar2 == *(int *)((iVar3 + *piVar9) * 4 + ctx + 0x168)) &&
           (iVar2 == *(int *)((iVar3 + piVar9[1]) * 4 + ctx + 0x168))) {
          pfVar4 = (float *)FUN_00173360(*(undefined4 *)(ctx + 0x238),
                                         *(undefined4 *)((iVar3 + piVar9[2]) * 4 + ctx + 0x168))
          ;
          if ((double)*pfVar4 == 1.0) {
            iVar6 = *(int *)(*(int *)(ctx + 0xb0) + 0x124);
LAB_0017c0b0:
            ((int (*)())FUN_0017bd78)(ctx,(loopRemaining == 1) + 1,loopIndex,iVar6);
            FUN_001745ac(ctx);
            return 1;
          }
          iVar6 = ((int (*)())FUN_0010ab40)((double)*pfVar4);
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

/* FUN_0017c0f8 @ 0x17c0f8 (332 bytes) */
int FUN_0017c0f8(ctx)
  int ctx;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int loopRemaining;
  int iVar9;
  
  iVar1 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0);
  iVar9 = *(int *)(iVar1 + 4);
  iVar1 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0x3f800000);
  iVar2 = 1;
  iVar5 = *(int *)(iVar1 + 4);
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
          FUN_001745ac(ctx);
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
int FUN_0017c244(ctx, param_2)
  int ctx;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_58;
  
  iVar3 = *(int *)(ctx + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  DList__unlink(iVar3);
  uVar12 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar4 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  iVar3 = *(int *)(ctx + 0xb0);
  uVar10 = *(undefined4 *)(iVar4 + 0x10);
  uVar11 = *(undefined4 *)(param_2 * 0x18 + iVar3 + 0x8c);
  uVar13 = *(undefined4 *)(iVar3 + 0x120);
  uVar14 = *(undefined4 *)(iVar3 + 0x124);
  iVar3 = IRInst__getOperandRecord(iVar3,param_2);
  iVar4 = *(int *)(ctx + 0xb0);
  uVar15 = *(undefined4 *)(iVar3 + 0x10);
  uVar5 = *(uint *)(iVar4 + 0x14);
  uVar2 = *(uint *)(param_2 * 0x18 + iVar4 + 0xa0);
  uVar9 = *(undefined4 *)(param_2 * 4 + ctx + 0x210);
  bVar1 = (uVar5 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 4 + ctx + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 0x18 + iVar4 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar4 + 0x94);
  uVar17 = *(undefined4 *)(iVar4 + 0x98);
  FUN_00108448(iVar4,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar4,0,uVar12);
  *(undefined4 *)(iVar4 + 0x98) = uVar17;
  *(undefined4 *)(iVar4 + 0x94) = uVar16;
  *(undefined4 *)(iVar4 + 0x9c) = uVar10;
  *(undefined4 *)(iVar4 + 0x120) = uVar13;
  *(undefined4 *)(iVar4 + 0x124) = uVar14;
  IRInst__setOperandRef(iVar4,1,uVar11);
  iVar3 = IRInst__getOperandRecord(iVar4,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar15;
  IROperand__setModifierBits(iVar4 + 0xa4,1,uVar2 & 1);
  IROperand__setModifierBits(iVar4 + 0xa4,2,uVar2 >> 1 & 1);
  *(undefined4 *)(ctx + 0x214) = uVar9;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(iVar4,uVar6);
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = local_58;
  }
  if ((uVar5 & 0x200000) != 0) {
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(uVar8,uVar7,iVar4);
  return iVar4;
}

/* FUN_0017c41c @ 0x17c41c (136 bytes) */
int FUN_0017c41c(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = FUN_00179c44(ctx,2,3);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xe8);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(ctx,2);
      FUN_001745ac(ctx);
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
  undefined4 uVar4;
  
  a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
  iVar3 = (**(code **)(*a0 + 0x88))(a0);
  if (((iVar3 == 0) || (iVar3 = FUN_00179c44(ctx,2,3), iVar3 == 0)) ||
     (iVar3 = FUN_00179c44(ctx,1,3), iVar3 == 0)) {
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
      uVar4 = 1;
      goto LAB_0017c5b4;
    }
    if (uVar1 != 0) {
      return 0;
    }
  }
  ((int (*)())FUN_0017c244)(ctx,2);
  iVar3 = *(int *)(ctx + 0xb0);
  uVar4 = 2;
LAB_0017c5b4:
  IROperand__setModifierBits(iVar3 + 0xa4,uVar4,1);
  FUN_001745ac(ctx);
  return 1;
}

/* FUN_0017c5e0 @ 0x17c5e0 (404 bytes) */
int FUN_0017c5e0(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int loopIndex;
  int iVar9;
  
  bVar2 = false;
  iVar3 = FUN_00176324(0);
  loopIndex = 0;
  iVar7 = -1;
  iVar9 = ctx;
  do {
    iVar4 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    iVar6 = iVar7;
    if (*(char *)(loopIndex + iVar4 + 0x10) != '\x01') {
      iVar6 = *(int *)(iVar9 + 0x178);
      if (iVar6 < 0) {
        puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(ctx + 0x238),iVar6);
        iVar6 = FUN_00176324(*puVar5);
        iVar4 = *(int *)(ctx + 0xb0);
      }
      else {
        if (iVar6 < 1) {
          return 0;
        }
        iVar6 = FUN_00173330(*(undefined4 *)(ctx + 0x238),iVar6);
        iVar4 = *(int *)(ctx + 0xb0);
        iVar6 = *(int *)(iVar6 + 0xc);
        if ((*(uint *)(iVar4 + 0xb8) & 2) != 0) {
          iVar6 = (DAT_001e61d0)[iVar6];
        }
        bVar2 = true;
        if ((*(uint *)(iVar4 + 0xb8) & 1) != 0) {
          iVar6 = *(int *)(&DAT_001e61b8 + iVar6 * 4);
        }
      }
      iVar4 = IRInst__getCompareCondition(iVar4);
      iVar6 = *(int *)(&DAT_001e61e8 + (iVar4 * 6 + iVar6 * 0x30 + iVar3) * 4);
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
      FUN_001745ac(ctx);
      return 1;
    }
  } while( true );
}

/* FUN_0017c774 @ 0x17c774 (276 bytes) */
int FUN_0017c774(ctx)
  int ctx;
{
  bool bVar1;
  int iVar2;
  int loopIndex;
  undefined4 uVar4;
  
  loopIndex = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0x3f800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(ctx,uVar4,loopIndex);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017c244)(ctx,(loopIndex == 1) + 1);
      FUN_001745ac(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0xbf800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(ctx,uVar4,loopIndex);
    if (iVar2 != 0) {
      iVar2 = (loopIndex == 1) + 1;
      ((int (*)())FUN_0017c244)(ctx,iVar2);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   *(uint *)(iVar2 * 0x18 + *(int *)(ctx + 0xb0) + 0xa0) & 1 ^ 1);
      FUN_001745ac(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017c888 @ 0x17c888 (136 bytes) */
int FUN_0017c888(ctx)
  int ctx;
{
  uint uVar1;
  int callResult;
  uint uVar3;
  
  callResult = FUN_00179c44(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(ctx,1);
      FUN_001745ac(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c910 @ 0x17c910 (516 bytes) */
int FUN_0017c910(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int operandRecord;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int loopIndex;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *loopIndex2;
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
      loopIndex2 = local_64;
      iVar12 = 0x98;
      for (operandRecord = 1;
          iVar6 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= iVar6; operandRecord = operandRecord + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = FUN_00176324(*puVar5);
          *loopIndex2 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = *(int *)(iVar6 + 0xc);
          *loopIndex2 = iVar6;
          iVar7 = *(int *)(ctx + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopIndex2 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *loopIndex2 = *(int *)(&DAT_001e61b8 + *loopIndex2 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        loopIndex2 = loopIndex2 + 1;
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
      FUN_001745ac(ctx);
      return 1;
    }
  } while( true );
}

/* FUN_0017cb14 @ 0x17cb14 (516 bytes) */
int FUN_0017cb14(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int operandRecord;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int loopIndex;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *loopIndex2;
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
      loopIndex2 = local_64;
      iVar12 = 0x98;
      for (operandRecord = 1;
          iVar6 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
          operandRecord <= iVar6; operandRecord = operandRecord + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = FUN_00176324(*puVar5);
          *loopIndex2 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(ctx + 0x238),iVar6);
          iVar6 = *(int *)(iVar6 + 0xc);
          *loopIndex2 = iVar6;
          iVar7 = *(int *)(ctx + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopIndex2 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *loopIndex2 = *(int *)(&DAT_001e61b8 + *loopIndex2 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        loopIndex2 = loopIndex2 + 1;
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
      FUN_001745ac(ctx);
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
  
  callResult = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = FUN_00177064(param_1,uVar3,loopIndex);
    if (callResult != 0) {
      callResult = FUN_0017737c(param_1,0,3);
      if (callResult == 0) {
        ((int (*)())FUN_0017c244)(param_1,3);
      }
      else {
        FUN_00177548(param_1);
      }
      FUN_001745ac(param_1);
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
  callResult = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  uVar4 = *(undefined4 *)(callResult + 4);
  do {
    uVar3 = 2;
    do {
      callResult = FUN_00177064(param_1,uVar4,loopIndex);
      if (callResult != 0) {
        callResult = FUN_0017737c(param_1,0,uVar3);
        if (callResult == 0) {
          ((int (*)())FUN_0017c244)(param_1,uVar3);
        }
        else {
          FUN_00177548(param_1);
        }
        FUN_001745ac(param_1);
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
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int member0xb0;
  
  iVar3 = *(int *)(ctx + 0xb0);
  uVar8 = *(undefined4 *)(iVar3 + 4);
  uVar9 = *(undefined4 *)(iVar3 + 0x158);
  DList__unlink(iVar3);
  uVar13 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar3 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  uVar10 = *(undefined4 *)(member0xb0 + 0x120);
  uVar11 = *(undefined4 *)(member0xb0 + 0x124);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    uVar7 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar14 = *(undefined4 *)(member0xb0 + 0x94);
  uVar15 = *(undefined4 *)(member0xb0 + 0x98);
  FUN_00108448(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,uVar13);
  *(undefined4 *)(member0xb0 + 0x98) = uVar15;
  *(undefined4 *)(member0xb0 + 0x94) = uVar14;
  *(undefined4 *)(member0xb0 + 0x9c) = uVar12;
  *(undefined4 *)(member0xb0 + 0x120) = uVar10;
  *(undefined4 *)(member0xb0 + 0x124) = uVar11;
  IRInst__setOperandRef(member0xb0,1,*(undefined4 *)(param_2 + 0xc));
  uVar12 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  iVar3 = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar12;
  if (*(int *)(param_2 + 0x18) != 0) {
    IROperand__setModifierBits(member0xb0 + 0xa4,1,1);
  }
  *(undefined4 *)(member0xb0 + 0x120) = uVar10;
  *(undefined4 *)(member0xb0 + 0x124) = uVar11;
  piVar4 = *(int **)(*(int *)(member0xb0 + 0xa4) + 0x18);
  if (*piVar4 == 0) {
    puVar5 = (undefined4 *)Vector__elementRefGrow(piVar4,0);
  }
  else {
    if (piVar4[1] == 0) {
      *(undefined4 *)piVar4[2] = 0;
      piVar4[1] = 1;
    }
    puVar5 = (undefined4 *)piVar4[2];
  }
  *(undefined4 *)(ctx + 0x214) = *puVar5;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,uVar7);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar6;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(uVar9,uVar8,member0xb0);
  return member0xb0;
}

/* FUN_0017d06c @ 0x17d06c (368 bytes) */
int FUN_0017d06c(ctx, param_2, param_3, param_4)
  int ctx;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
  undefined4 arenaAt378;
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int member0xb0;
  
  iVar3 = *(int *)(ctx + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  DList__unlink(iVar3);
  uVar11 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar3 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar6 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar12 = *(undefined4 *)(member0xb0 + 0x94);
  uVar10 = *(undefined4 *)(member0xb0 + 0x98);
  FUN_00108448(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,uVar11);
  iVar3 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(member0xb0 + 0x94) = uVar12;
  *(undefined4 *)(member0xb0 + 0x98) = uVar10;
  *(undefined4 *)(member0xb0 + 0x9c) = uVar9;
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    puVar4 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *puVar4 = arenaAt378;
    puVar4 = puVar4 + 1;
    FUN_00173938(puVar4,param_2,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(puVar4);
    FUN_00173278(puVar4);
    FUN_00123424(iVar3,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar4);
  }
  IRInst__setOperandRef(member0xb0,1,iVar3);
  uVar9 = *param_3;
  iVar3 = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar9;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,param_4);
  *(int *)(ctx + 0x214) = param_2;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,uVar6);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar5;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200000;
  }
  Block__insertInstAfter(uVar8,uVar7,member0xb0);
  return member0xb0;
}

/* FUN_0017d26c @ 0x17d26c (196 bytes) */
int FUN_0017d26c(ctx, param_2)
  int ctx;
  undefined4 param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int operandRecord;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int member0xb0;
  undefined4 uVar12;
  int loopIndex;
  undefined4 uVar14;
  
  iVar3 = *(int *)(ctx + 0xb0);
  uVar6 = *(undefined4 *)(iVar3 + 4);
  uVar7 = *(undefined4 *)(iVar3 + 0x158);
  DList__unlink(iVar3);
  uVar10 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar3 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  member0xb0 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(member0xb0 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar8 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 4 + ctx + 0x210);
    uVar8 = *(undefined4 *)(*(int *)(member0xb0 + 0x84) * 0x18 + member0xb0 + 0x8c);
  }
  uVar12 = *(undefined4 *)(member0xb0 + 0x94);
  uVar14 = *(undefined4 *)(member0xb0 + 0x98);
  FUN_00108448(member0xb0,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(member0xb0,0,uVar10);
  *(undefined4 *)(member0xb0 + 0x94) = uVar12;
  *(undefined4 *)(member0xb0 + 0x98) = uVar14;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(member0xb0,uVar8);
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
  Block__insertInstAfter(uVar7,uVar6,member0xb0);
  return member0xb0;
}

/* FUN_0017d3f8 @ 0x17d3f8 (232 bytes) */
int FUN_0017d3f8(param_1)
  int param_1;
{
  undefined4 *loopIndex;
  int loopRemaining;
  undefined4 uVar3;
  int loopRemaining2;
  undefined4 local_28 [8];
  
  loopRemaining = FUN_00179c44(param_1,1,2);
  if (loopRemaining != 0) {
    loopRemaining = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(loopRemaining + 0xb8) & 1) == (*(uint *)(loopRemaining + 0xd0) & 1)) &&
       ((*(uint *)(loopRemaining + 0xb8) >> 1 & 1) == (*(uint *)(loopRemaining + 0xd0) >> 1 & 1))) {
      loopRemaining = ((bool (*)())FUN_0010b820)(loopRemaining,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar3 = 0x3f800000;
      if (loopRemaining == 0) {
        uVar3 = 0;
      }
      loopRemaining = 4;
      loopIndex = local_28;
      do {
        *loopIndex = 0x7ffffffe;
        loopIndex = loopIndex + 1;
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
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d4e0 @ 0x17d4e0 (156 bytes) */
int FUN_0017d4e0(ctx)
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
      FUN_001745ac(ctx);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d57c @ 0x17d57c (148 bytes) */
int FUN_0017d57c(param_1)
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
  
  callResult = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = FUN_00177064(param_1,uVar3,loopIndex);
    if (callResult != 0) {
      local_2c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_38);
      FUN_001745ac(param_1);
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
  
  callResult = FUN_00179c44(ctx,1,2);
  if (callResult != 0) {
    uVar3 = *(uint *)(*(int *)(ctx + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(ctx + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(ctx,&local_28);
      FUN_001745ac(ctx);
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
  float *loopIndex2;
  int iVar4;
  int loopIndex;
  int loopRemaining2;
  int *piVar7;
  undefined4 uVar8;
  undefined4 in_r7;
  undefined4 in_r8;
  float *loopIndex3;
  float fVar10;
  int loopRemaining;
  undefined4 local_58;
  uint local_54;
  float afStack_44 [3];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(loopIndex + 0x10));
  FUN_000f3340(local_34,0x10203,local_38);
  loopIndex = *(int *)(ctx + 0x238);
  local_58 = local_34[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),param_2,&local_58,in_r7
                     ,in_r8,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 4;
    loopIndex2 = (float *)&local_54;
    do {
      *loopIndex2 = GH_U2F(0x7fff0000U);
      loopIndex2 = loopIndex2 + 1;
      loopIndex = loopIndex + -1;
    } while (loopIndex != 0);
    loopIndex = 0;
    loopIndex2 = (float *)&local_54;
    loopIndex3 = param_2;
    do {
      loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
        *loopIndex2 = -*loopIndex3;
      }
      bVar1 = loopIndex != 3;
      loopIndex2 = loopIndex2 + 1;
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    piVar7 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
    loopIndex = (**(code **)(*piVar7 + 0x154))
                      (piVar7,*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),&local_54,&local_58
                      );
    if (loopIndex == 0) {
      fVar10 = GH_U2F(0x7fff0000U);
      loopIndex = 0;
      loopIndex2 = param_2;
      do {
        loopRemaining2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex + loopRemaining2 + 0x10) != '\x01') {
          FUN_00173e10(*(undefined4 *)(ctx + 0x238), *(unsigned int *)loopIndex2);
          if ((GH_F2U(fVar10) == 0x7fff0000U)) {
            fVar10 = *loopIndex2;
          }
          else if (fVar10 != *loopIndex2) {
            return 0;
          }
        }
        bVar1 = loopIndex != 3;
        loopIndex2 = loopIndex2 + 1;
        loopIndex = loopIndex + 1;
      } while (bVar1);
      loopIndex = FUN_00173e10(*(undefined4 *)(ctx + 0x238), GH_F2U(fVar10));
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
      loopRemaining2 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),*(undefined4 *)(loopIndex + 0x14));
      loopIndex2 = (float *)&local_54;
      if ((*(byte *)(loopRemaining2 + 8) & 1) == 0) {
        loopRemaining2 = ((int (*)())FUN_0017ce7c)(ctx,loopRemaining2);
      }
      else {
        do {
          *loopIndex2 = GH_U2F(0x7fff0000U);
          loopIndex2 = loopIndex2 + 1;
        } while (loopIndex2 != afStack_44);
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
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *loopIndex4;
  int loopIndex2;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *loopIndex3;
  int *piVar13;
  int loopIndex;
  int loopRemaining;
  int local_64 [9];
  
  loopIndex = 4;
  piVar10 = local_64 + 2;
  loopIndex4 = piVar10;
  do {
    *loopIndex4 = 0x7ffffffe;
    loopIndex4 = loopIndex4 + 1;
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
  loopIndex4 = piVar10;
  do {
    loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') {
      piVar13 = (int *)(loopRemaining + 8);
      loopIndex2 = 1;
      loopIndex3 = local_64;
      iVar11 = 0x98;
      do {
        *loopIndex3 = 0;
        iVar9 = *piVar13;
        if (iVar9 < 0) {
          puVar6 = (undefined4 *)FUN_00173360(*(undefined4 *)(ctx + 0x238),iVar9);
          iVar9 = FUN_00176324(*puVar6);
          *loopIndex3 = iVar9;
        }
        else {
          if (iVar9 < 1) goto LAB_0017dbc4;
          iVar9 = FUN_00173330(*(undefined4 *)(ctx + 0x238),iVar9);
          iVar7 = *(int *)(iVar9 + 0xc);
          *loopIndex3 = iVar7;
          iVar9 = *(int *)(ctx + 0xb0) + iVar11;
          uVar3 = *(uint *)(iVar9 + 0x20);
          if ((uVar3 & 2) != 0) {
            *loopIndex3 = (DAT_001e61d0)[iVar7];
            uVar3 = *(uint *)(iVar9 + 0x20);
          }
          if ((uVar3 & 1) == 0) {
            iVar9 = *loopIndex3;
            bVar2 = true;
          }
          else {
            bVar2 = true;
            iVar9 = *(int *)(&DAT_001e61b8 + *loopIndex3 * 4);
            *loopIndex3 = iVar9;
          }
        }
        iVar7 = local_64[0];
        if (iVar9 == 0) goto LAB_0017dbc4;
        bVar1 = loopIndex2 != 2;
        iVar11 = iVar11 + 0x18;
        loopIndex3 = loopIndex3 + 1;
        piVar13 = piVar13 + 4;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
      loopIndex2 = IRInst__getCompareCondition(*(undefined4 *)(ctx + 0xb0));
      loopIndex2 = *(int *)(&DAT_001e61e8 + (loopIndex2 * 6 + iVar7 * 0x30 + local_64[1]) * 4);
      if (loopIndex2 == 1) {
        *loopIndex4 = 0x3f800000;
      }
      else if (loopIndex2 == 2) {
        *loopIndex4 = 0;
      }
      else if (loopIndex2 == 0) goto LAB_0017dbc4;
    }
    bVar1 = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopIndex4 = loopIndex4 + 1;
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
    FUN_001745ac(ctx);
    uVar8 = 1;
  }
  return uVar8;
}

/* FUN_0017dbdc @ 0x17dbdc (1104 bytes) */
int FUN_0017dbdc(ctx, param_2)
  int ctx;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int loopRemaining;
  int loopIndex;
  int *loopIndex3;
  undefined4 uVar6;
  int loopIndex2;
  int local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c [6];
  
  uVar6 = *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8);
  iVar2 = FUN_00176564(uVar6);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_00176574(uVar6);
  if (iVar2 == 0) {
    loopIndex = FUN_00113174(uVar6,*(undefined4 *)(ctx + 0x238));
    if ((loopIndex == 0) ||
       (loopIndex = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
      loopIndex = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238));
      if (loopIndex == 0) {
        iVar2 = 0;
        loopIndex2 = 0;
        loopIndex = ctx;
        loopIndex3 = param_2;
        do {
          local_58[0] = 0;
          loopRemaining = FUN_001767d8(ctx,loopIndex2);
          if (loopRemaining != 0) {
            FUN_00176c40(local_3c,ctx,loopIndex2,local_58);
            *loopIndex3 = local_3c[0];
            if (local_3c[0] != 0x7ffffffe) {
              uVar6 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),local_3c[0]);
              *(undefined4 *)(loopIndex + 0x30) = uVar6;
            }
          }
          loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (local_58[0] != 0)) {
            iVar2 = 1;
          }
          bVar1 = loopIndex2 != 3;
          loopIndex3 = loopIndex3 + 1;
          loopIndex = loopIndex + 4;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
        loopIndex = 0;
        loopIndex3 = param_2;
        do {
          loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopIndex3 == 0x7ffffffe))
          goto LAB_0017dfa0;
          bVar1 = loopIndex != 3;
          loopIndex3 = loopIndex3 + 1;
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
        uVar6 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),local_40);
        loopRemaining = 4;
        loopIndex2 = 0;
        loopIndex = ctx;
        do {
          *(int *)((int)param_2 + loopIndex2) = local_40;
          loopIndex2 = loopIndex2 + 4;
          *(undefined4 *)(loopIndex + 0x30) = uVar6;
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
      uVar6 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),local_44);
      loopRemaining = 4;
      loopIndex2 = 0;
      loopIndex = ctx;
      do {
        *(int *)((int)param_2 + loopIndex2) = local_44;
        loopIndex2 = loopIndex2 + 4;
        *(undefined4 *)(loopIndex + 0x30) = uVar6;
        loopIndex = loopIndex + 4;
        loopRemaining = loopRemaining + -1;
      } while (loopRemaining != 0);
    }
  }
  else {
    iVar2 = 0;
    loopIndex2 = 0;
    loopIndex = ctx;
    loopIndex3 = param_2;
    do {
      local_58[0] = 0;
      loopRemaining = FUN_00178a98(ctx,loopIndex2);
      if (loopRemaining != 0) {
        FUN_00178e90(&local_48,ctx,loopIndex2,(uint)local_58);
        *loopIndex3 = local_48;
        if (local_48 != 0x7ffffffe) {
          uVar6 = FUN_00173e10(*(undefined4 *)(ctx + 0x238),local_48);
          *(undefined4 *)(loopIndex + 0x30) = uVar6;
        }
      }
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex2 + loopRemaining + 0x10) == '\0') && (local_58[0] != 0)) {
        iVar2 = 1;
      }
      bVar1 = loopIndex2 != 3;
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 4;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(int *)(loopIndex + 0x10) == 0x1010101) goto LAB_0017dfa0;
    loopIndex = 0;
    loopIndex3 = param_2;
    do {
      loopIndex2 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if ((*(char *)(loopIndex + loopIndex2 + 0x10) != '\x01') && (*loopIndex3 == 0x7ffffffe)) goto LAB_0017dfa0;
      bVar1 = loopIndex != 3;
      loopIndex3 = loopIndex3 + 1;
      loopIndex = loopIndex + 1;
    } while (bVar1);
  }
  bVar1 = false;
LAB_0017dd38:
  loopIndex = (**(code **)(**(int **)(ctx + 0xb0) + 100))(*(int **)(ctx + 0xb0));
  if ((loopIndex == 0) && (!bVar1)) {
    loopIndex = ((int (*)())FUN_0017d6ac)(ctx,param_2);
    if (loopIndex != 0) {
      FUN_001745ac(ctx);
      return 1;
    }
    loopIndex = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
    *(int *)(loopIndex + 0x138) = *(int *)(loopIndex + 0x138) + 1;
    if ((*(int *)(*(int *)(ctx + 0xb0) + 0x120) != 0) && (iVar2 == 0)) {
      *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x120) = 0;
      FUN_001745ac(ctx);
      return 0;
    }
  }
  return 0;
}

/* FUN_0017e02c @ 0x17e02c (268 bytes) */
int FUN_0017e02c(ctx, param_2, param_3)
  int ctx;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  iVar4 = *(int *)(ctx + 0xb0);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  uVar7 = *(undefined4 *)(iVar4 + 0x158);
  DList__unlink(iVar4);
  uVar15 = *(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c);
  iVar5 = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0);
  iVar4 = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  uVar13 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar9 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = IRInst__getOperandRecord(iVar4,param_2);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar14 = *(undefined4 *)(iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar11 = *(undefined4 *)(param_2 * 4 + ctx + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar8 = 0;
    uVar10 = 0;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + ctx + 0x210);
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar5 + 0x94);
  uVar17 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar5,0,uVar15);
  *(undefined4 *)(iVar5 + 0x94) = uVar16;
  *(undefined4 *)(iVar5 + 0x98) = uVar17;
  if (bVar1) {
    *(undefined4 *)(ctx + 0x218) = 0;
  }
  else {
    IRInst__appendSource(iVar5,uVar10);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x218) = uVar8;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar12;
  IRInst__setOperandRef(iVar5,1,uVar13);
  iVar4 = IRInst__getOperandRecord(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar14;
  IROperand__setModifierBits(iVar5 + 0xa4,1,uVar3 & 1);
  IROperand__setModifierBits(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar5 + 0x120) = uVar9;
  *(undefined4 *)(iVar5 + 0x124) = param_3;
  *(undefined4 *)(ctx + 0x214) = uVar11;
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  DList__insertAfter(iVar5,uVar2);
  *(undefined4 *)(iVar5 + 0x158) = uVar7;
  return;
}

/* FUN_0017e1f4 @ 0x17e1f4 (324 bytes) */
int FUN_0017e1f4(ctx)
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
      iVar2 = ((undefined4 (*)())FUN_0010aafc)(fparam_1);
      if (iVar2 != 0) {
        iVar2 = ((int (*)())FUN_0010ab40)(fparam_1);
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
          FUN_001745ac(ctx);
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
  int iVar1;
  int *a0;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a1;
  
  iVar1 = FUN_00179c44(ctx,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(ctx + 0xb0);
    if (((*(uint *)(iVar1 + 0xb8) & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((*(uint *)(iVar1 + 0xb8) >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      a0 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
      a1 = *(int *)(iVar1 + 0x124) + 1;
      iVar1 = (**(code **)(*a0 + 0xfc))(a0,a1,iVar1,in_r6,in_r7,in_r8,*(int *)(iVar1 + 0x124));
      if (iVar1 != 0) {
        ((int (*)())FUN_0017e02c)(ctx,2,a1);
        FUN_001745ac(ctx);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0017e3f4 @ 0x17e3f4 (348 bytes) */
int FUN_0017e3f4(ctx, param_2, param_3, param_4)
  int ctx;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  
  iVar5 = *(int *)(ctx + 0xb0);
  uVar2 = *(undefined4 *)(iVar5 + 4);
  uVar3 = *(undefined4 *)(iVar5 + 0x158);
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  uVar17 = *(undefined4 *)(iVar5 + 0x8c);
  iVar8 = IRInst__getOperandRecord(iVar5,0);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar9 = *(undefined4 *)(iVar8 + 0x10);
  uVar10 = *(undefined4 *)(param_3 * 0x18 + iVar5 + 0x8c);
  uVar13 = *(undefined4 *)(iVar5 + 0x120);
  uVar14 = *(undefined4 *)(iVar5 + 0x124);
  iVar8 = IRInst__getOperandRecord(iVar5,param_3);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(iVar8 + 0x10);
  uVar4 = *(uint *)(param_3 * 0x18 + iVar5 + 0xa0);
  uVar6 = *(undefined4 *)(param_4 * 0x18 + iVar5 + 0x8c);
  iVar5 = IRInst__getOperandRecord(iVar5,param_4);
  iVar8 = *(int *)(ctx + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  bVar1 = (*(uint *)(iVar8 + 0x14) & 0x200) == 0;
  uVar7 = *(uint *)(param_4 * 0x18 + iVar8 + 0xa0);
  uVar18 = *(undefined4 *)(param_3 * 4 + ctx + 0x210);
  uVar20 = *(undefined4 *)(param_4 * 4 + ctx + 0x210);
  if (bVar1) {
    uVar19 = 0;
    uVar21 = 0;
  }
  else {
    uVar19 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 4 + ctx + 0x210);
    uVar21 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 0x18 + iVar8 + 0x8c);
  }
  DList__unlink(iVar8);
  iVar5 = *(int *)(ctx + 0xb0);
  FUN_00108174(iVar5,param_2,*(undefined4 *)(ctx + 0x238));
  IRInst__setOperandRef(iVar5,0,uVar17);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  if (bVar1) {
    iVar8 = FUN_00122fa4(uVar17,*(undefined4 *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x3a0)
                        ,*(undefined4 *)(ctx + 0x238));
    *(undefined4 *)(ctx + 0x21c) = *(undefined4 *)(iVar8 + 0xb0);
  }
  else {
    IRInst__appendSource(iVar5,uVar21);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(ctx + 0x21c) = uVar19;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar9;
  *(undefined4 *)(iVar5 + 0x120) = uVar13;
  *(undefined4 *)(iVar5 + 0x124) = uVar14;
  IRInst__setOperandRef(iVar5,1,uVar10);
  iVar8 = IRInst__getOperandRecord(iVar5,1);
  *(undefined4 *)(iVar8 + 0x10) = uVar11;
  IROperand__setModifierBits(iVar5 + 0xa4,1,uVar4 & 1);
  IROperand__setModifierBits(iVar5 + 0xa4,2,uVar4 >> 1 & 1);
  IRInst__setOperandRef(iVar5,2,uVar6);
  iVar8 = IRInst__getOperandRecord(iVar5,2);
  *(undefined4 *)(iVar8 + 0x10) = uVar12;
  IROperand__setModifierBits(iVar5 + 0xbc,1,uVar7 & 1);
  IROperand__setModifierBits(iVar5 + 0xbc,2,uVar7 >> 1 & 1);
  *(undefined4 *)(ctx + 0x218) = uVar20;
  *(undefined4 *)(ctx + 0x214) = uVar18;
  DList__insertAfter(iVar5,uVar2);
  *(undefined4 *)(iVar5 + 0x158) = uVar3;
  return;
}

/* FUN_0017e658 @ 0x17e658 (112 bytes) */
int FUN_0017e658(param_1)
  int param_1;
{
  int callResult;
  
  callResult = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  callResult = FUN_00177064(param_1,*(undefined4 *)(callResult + 4),3);
  if (callResult != 0) {
    ((int (*)())FUN_0017e3f4)(param_1,0x13,1,2);
    FUN_001745ac(param_1);
  }
  return callResult != 0;
}

/* FUN_0017e6c8 @ 0x17e6c8 (280 bytes) */
int FUN_0017e6c8(ctx)
  int ctx;
{
  bool bVar1;
  int callResult;
  undefined4 uVar3;
  int loopIndex;
  
  callResult = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0x3f800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = FUN_00177064(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())FUN_0017e3f4)(ctx,0x12,(loopIndex == 1) + 1,3);
      FUN_001745ac(ctx);
      return 1;
    }
    bVar1 = loopIndex != 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  callResult = FUN_00173e10(*(undefined4 *)(ctx + 0x238),0xbf800000);
  loopIndex = 1;
  uVar3 = *(undefined4 *)(callResult + 4);
  do {
    callResult = FUN_00177064(ctx,uVar3,loopIndex);
    if (callResult != 0) {
      ((int (*)())FUN_0017e3f4)(ctx,0x12,(loopIndex == 1) + 1,3);
      IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(ctx + 0xb0) + 0xb8) ^ 1) & 1);
      FUN_001745ac(ctx);
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
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  uint uVar5;
  int loopRemaining;
  int *newInst;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int member0xb0;
  undefined4 uVar17;
  int *piVar18;
  undefined4 uVar19;
  int local_78;
  undefined4 local_74 [3];
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  int local_5c;
  int local_58;
  
  loopIndex = *(int *)(ctx + 0xb0);
  uVar19 = *(undefined4 *)(loopIndex + 0x158);
  uVar17 = *(undefined4 *)(loopIndex + 4);
  uVar9 = *(undefined4 *)(loopIndex + 0x94);
  uVar10 = *(undefined4 *)(loopIndex + 0x98);
  uVar15 = *(undefined4 *)(loopIndex + 0x8c);
  loopIndex = IRInst__getOperandRecord(loopIndex,0);
  local_78 = *(int *)(loopIndex + 0x10);
  loopIndex = *(int *)(ctx + 0xb0);
  local_58 = *(int *)(loopIndex + 0x120);
  local_5c = *(int *)(loopIndex + 0x124);
  uVar14 = *(undefined4 *)(loopIndex + 0xa4);
  loopRemaining = IRInst__getOperandRecord(loopIndex,1);
  loopIndex = *(int *)(ctx + 0xb0);
  uVar13 = *(undefined4 *)(loopRemaining + 0x10);
  uVar2 = *(uint *)(loopIndex + 0xb8);
  uVar12 = *(undefined4 *)(loopIndex + 0xbc);
  loopRemaining = IRInst__getOperandRecord(loopIndex,2);
  loopIndex = *(int *)(ctx + 0xb0);
  uVar11 = *(undefined4 *)(loopRemaining + 0x10);
  uVar3 = *(uint *)(loopIndex + 0xd0);
  uVar8 = *(undefined4 *)(loopIndex + 0xd4);
  loopIndex = IRInst__getOperandRecord(loopIndex,3);
  loopRemaining = *(int *)(ctx + 0xb0);
  local_68 = *(undefined4 *)(loopIndex + 0x10);
  uVar5 = *(uint *)(loopRemaining + 0xe8);
  bVar1 = (*(uint *)(loopRemaining + 0x14) >> 9 & 1) != 0;
  local_60 = uVar5 >> 1 & 1;
  if (bVar1) {
    local_64 = *(undefined4 *)(*(int *)(loopRemaining + 0x84) * 0x18 + loopRemaining + 0x8c);
  }
  else {
    local_64 = 0;
  }
  DList__unlink(loopRemaining);
  member0xb0 = *(int *)(ctx + 0xb0);
  FUN_00108174(member0xb0,0x13,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(uVar19,uVar17,member0xb0);
  newInst = (int *)IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(uVar19,*(undefined4 *)(ctx + 0xb0),newInst);
  loopIndex = *(int *)(ctx + 0x238);
  uVar17 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  loopRemaining = *(int *)(loopIndex + 0x3ac) + -1;
  *(int *)(loopIndex + 0x3ac) = loopRemaining;
  uVar17 = FUN_00127608(uVar17,0,loopRemaining,0);
  IRInst__setOperandRef(member0xb0,0,uVar17);
  IRInst__setOperandRef(member0xb0,1,uVar14);
  loopIndex = IRInst__getOperandRecord(member0xb0,1);
  *(undefined4 *)(loopIndex + 0x10) = uVar13;
  IROperand__setModifierBits(member0xb0 + 0xa4,1,uVar2 & 1);
  IROperand__setModifierBits(member0xb0 + 0xa4,2,uVar2 >> 1 & 1);
  IRInst__setOperandRef(member0xb0,2,uVar12);
  loopIndex = IRInst__getOperandRecord(member0xb0,2);
  *(undefined4 *)(loopIndex + 0x10) = uVar11;
  IROperand__setModifierBits(member0xb0 + 0xbc,1,uVar3 & 1);
  IROperand__setModifierBits(member0xb0 + 0xbc,2,uVar3 >> 1 & 1);
  *(undefined4 *)(member0xb0 + 0x94) = uVar9;
  *(undefined4 *)(member0xb0 + 0x98) = uVar10;
  *(int *)(member0xb0 + 0x9c) = local_78;
  FUN_0012306c(uVar17,member0xb0);
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
  IRInst__setOperandRef(newInst,0,uVar15);
  newInst[0x27] = local_78;
  IRInst__setOperandRef(newInst,1,uVar17);
  uVar9 = local_74[0];
  loopIndex = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(loopIndex + 0x10) = uVar9;
  IRInst__setOperandRef(newInst,2,uVar8);
  loopIndex = IRInst__getOperandRecord(newInst,2);
  *(undefined4 *)(loopIndex + 0x10) = local_68;
  IROperand__setModifierBits(newInst + 0x2f,1,uVar5 & 1);
  IROperand__setModifierBits(newInst + 0x2f,2,local_60);
  newInst[0x48] = local_58;
  newInst[0x49] = local_5c;
  FUN_0012306c(uVar15,newInst);
  loopIndex = 1;
  piVar18 = newInst;
  while( true ) {
    loopRemaining = (**(code **)(*newInst + 0x14))(newInst);
    if (loopRemaining < loopIndex) break;
    FUN_001236e4(piVar18[0x29],loopIndex,newInst);
    loopIndex = loopIndex + 1;
    piVar18 = piVar18 + 6;
  }
  if (bVar1) {
    IRInst__appendSource(member0xb0,local_64);
    *(uint *)(member0xb0 + 0x14) = *(uint *)(member0xb0 + 0x14) | 0x200;
    FUN_001236e4(local_64,*(undefined4 *)(member0xb0 + 0x84),member0xb0);
    IRInst__appendSource(newInst,uVar15);
    newInst[5] = newInst[5] | 0x200;
    FUN_001236e4(uVar15,newInst[0x21],newInst);
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  FUN_0017386c(ctx);
  return FUN_00173f1c(ctx);
}

/* FUN_0017ebb0 @ 0x17ebb0 (508 bytes) */
int FUN_0017ebb0(ctx, param_2, param_3, param_4)
  int ctx;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 arenaAt378;
  bool bVar1;
  undefined4 member0x21c;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *loopIndex2;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int loopIndex;
  undefined4 local_58;
  
  iVar3 = *(int *)(ctx + 0xb0);
  uVar14 = *(undefined4 *)(iVar3 + 4);
  uVar15 = *(undefined4 *)(iVar3 + 0x158);
  uVar12 = *(undefined4 *)(iVar3 + 0x94);
  uVar13 = *(undefined4 *)(iVar3 + 0x98);
  uVar9 = *(undefined4 *)(iVar3 + 0x8c);
  iVar5 = IRInst__getOperandRecord(iVar3,0);
  iVar3 = *(int *)(ctx + 0xb0);
  member0x21c = *(undefined4 *)(ctx + 0x21c);
  uVar17 = *(undefined4 *)(iVar3 + 0x124);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar16 = *(undefined4 *)(iVar3 + 0x120);
  uVar8 = *(undefined4 *)(iVar3 + 0xd4);
  iVar3 = IRInst__getOperandRecord(iVar3,3);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 0x10);
  uVar4 = *(uint *)(iVar5 + 0xe8);
  bVar1 = (*(uint *)(iVar5 + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + ctx + 0x210);
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  else {
    uVar10 = 0;
    local_58 = 0;
  }
  DList__unlink(iVar5);
  iVar3 = *(int *)(ctx + 0xb0);
  FUN_00108174(iVar3,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(uVar15,uVar14,iVar3);
  *(undefined4 *)(iVar3 + 0x120) = uVar16;
  *(undefined4 *)(iVar3 + 0x124) = uVar17;
  *(undefined4 *)(iVar3 + 0x94) = uVar12;
  *(undefined4 *)(iVar3 + 0x98) = uVar13;
  IRInst__setOperandRef(iVar3,0,uVar9);
  iVar5 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(iVar3 + 0x9c) = uVar11;
  if (*(int *)(*(int *)(iVar5 + 0x2c) + 4) == 0) {
    arenaAt378 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
    loopIndex2 = (undefined4 *)Arena__alloc(arenaAt378,0x240);
    *loopIndex2 = arenaAt378;
    loopIndex2 = loopIndex2 + 1;
    FUN_00173938(loopIndex2,param_2,*(undefined4 *)(ctx + 0x238));
    FUN_00174e0c(loopIndex2);
    FUN_00173278(loopIndex2);
    FUN_00123424(iVar5,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),loopIndex2);
  }
  IRInst__setOperandRef(iVar3,1,iVar5);
  iVar5 = IRInst__getOperandRecord(iVar3,1);
  *(undefined4 *)(iVar5 + 0x10) = param_3;
  IROperand__setModifierBits(iVar3 + 0xa4,1,param_4);
  IRInst__setOperandRef(iVar3,2,uVar8);
  iVar5 = IRInst__getOperandRecord(iVar3,2);
  *(undefined4 *)(iVar5 + 0x10) = uVar7;
  IROperand__setModifierBits(iVar3 + 0xbc,1,uVar4 & 1);
  IROperand__setModifierBits(iVar3 + 0xbc,2,uVar4 >> 1 & 1);
  if (bVar1) {
    IRInst__appendSource(iVar3,local_58);
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x200;
  }
  *(int *)(ctx + 0x214) = param_2;
  *(undefined4 *)(ctx + 0x218) = member0x21c;
  if (!bVar1) {
    uVar10 = 0;
  }
  *(undefined4 *)(ctx + 0x21c) = uVar10;
  FUN_0012306c(uVar9,iVar3);
  if (0 < *(int *)(iVar3 + 0x84)) {
    loopIndex = 1;
    iVar5 = iVar3;
    do {
      loopIndex2 = (undefined4 *)(iVar5 + 0xa4);
      iVar5 = iVar5 + 0x18;
      FUN_001236e4(*loopIndex2,loopIndex,iVar3);
      loopIndex = loopIndex + 1;
    } while (loopIndex <= *(int *)(iVar3 + 0x84));
  }
  _memset((void *)(ctx + 0xb4),0,0x15c);
  FUN_0017386c(ctx);
  FUN_00173f1c(ctx);
  return;
}

/* FUN_0017ee68 @ 0x17ee68 (468 bytes) */
int FUN_0017ee68(ctx)
  int ctx;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int loopIndex;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
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
  iVar5 = *(int *)(ctx + 0xb0);
  iVar18 = (loopIndex == 1) + 1;
  uVar9 = *(undefined4 *)(iVar5 + 0x8c);
  iVar11 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  loopIndex = IRInst__getOperandRecord(iVar5,0);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar10 = *(undefined4 *)(loopIndex + 0x10);
  uVar13 = *(undefined4 *)(iVar18 * 0x18 + iVar5 + 0x8c);
  uVar7 = *(undefined4 *)(iVar5 + 0x120);
  uVar8 = *(undefined4 *)(iVar5 + 0x124);
  loopIndex = IRInst__getOperandRecord(iVar5,iVar18);
  iVar5 = *(int *)(ctx + 0xb0);
  uVar14 = *(uint *)(loopIndex + 0x10);
  uVar12 = *(undefined4 *)(iVar18 * 4 + ctx + 0x210);
  bVar1 = (*(uint *)(iVar5 + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar6 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  else {
    uVar6 = 0;
  }
  uVar20 = *(undefined4 *)(iVar5 + 4);
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  uVar19 = *(undefined4 *)(iVar5 + 0x158);
  DList__unlink(iVar5);
  iVar18 = *(int *)(ctx + 0xb0);
  FUN_00108174(iVar18,0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(uVar19,uVar20,iVar18);
  loopIndex = *(int *)(ctx + 0x238);
  iVar5 = *(int *)(loopIndex + 0x3ac) + -1;
  uVar20 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
  *(int *)(loopIndex + 0x3ac) = iVar5;
  uVar20 = FUN_00127608(uVar20,0,iVar5,0);
  FUN_0012306c(uVar20,*(undefined4 *)(ctx + 0xb0));
  IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,uVar20);
  *(undefined4 *)(iVar18 + 0x94) = uVar15;
  *(undefined4 *)(iVar18 + 0x98) = uVar16;
  IRInst__setOperandRef(iVar18,1,uVar13);
  IRInst__setOperandRef(iVar18,2,uVar13);
  loopIndex = IRInst__create(0x12,*(undefined4 *)(ctx + 0x238));
  Block__insertInstAfter(uVar19,iVar18,loopIndex);
  IRInst__setOperandRef(loopIndex,0,uVar9);
  *(undefined4 *)(loopIndex + 0x94) = uVar15;
  *(undefined4 *)(loopIndex + 0x98) = uVar16;
  *(undefined4 *)(loopIndex + 0x9c) = uVar10;
  if (bVar1) {
    IRInst__appendSource(loopIndex,uVar6);
    *(uint *)(loopIndex + 0x14) = *(uint *)(loopIndex + 0x14) | 0x200;
  }
  *(undefined4 *)(loopIndex + 0x120) = uVar7;
  *(undefined4 *)(loopIndex + 0x124) = uVar8;
  *(undefined4 *)(ctx + 0x218) = uVar12;
  *(undefined4 *)(ctx + 0x214) = uVar12;
  puVar4 = PTR_DAT_001e8b8c;
  uVar2 = DAT_001b01d8;
  if (iVar11 == 0x1c) {
    uVar7 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar14 >> 0x16 & 0x3fc));
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffffff;
    iVar5 = IRInst__getOperandRecord(iVar18,1);
    uVar8 = *(undefined4 *)(puVar4 + (uVar14 >> 0xe & 0x3fc));
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    iVar5 = IRInst__getOperandRecord(iVar18,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
    IRInst__setOperandRef(loopIndex,1,uVar20);
    IRInst__setOperandRef(loopIndex,2,uVar13);
    uVar7 = *(undefined4 *)puVar4;
    iVar5 = IRInst__getOperandRecord(loopIndex,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    uVar7 = *(undefined4 *)(puVar4 + (uVar14 >> 6 & 0x3fc));
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = uVar7;
  }
  else if (iVar11 == 0x1d) {
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffff;
    iVar5 = IRInst__getOperandRecord(iVar18,1);
    uVar3 = DAT_001b01d8;
    *(uint *)(iVar5 + 0x10) = uVar14 & 0xff0000 | uVar14 & 0xff000000 | uVar2 & 0xffff;
    iVar5 = IRInst__getOperandRecord(iVar18,2);
    *(uint *)(iVar5 + 0x10) = (uVar14 & 0xff) << 0x10 | (uVar14 & 0xff00) << 0x10 | uVar3 & 0xffff;
    IRInst__setOperandRef(loopIndex,1,uVar20);
    IRInst__setOperandRef(loopIndex,2,uVar20);
    puVar4 = PTR_DAT_001e8b8c;
    uVar7 = *(undefined4 *)PTR_DAT_001e8b8c;
    iVar5 = IRInst__getOperandRecord(loopIndex,1);
    uVar8 = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    loopIndex = IRInst__getOperandRecord(loopIndex,2);
    *(undefined4 *)(loopIndex + 0x10) = uVar8;
  }
  FUN_001745ac(ctx);
  return 1;
}

/* FUN_0017f1f8 @ 0x17f1f8 (512 bytes) */
int FUN_0017f1f8(ctx)
  int ctx;
{
  bool bVar1;
  float *loopIndex2;
  int iVar3;
  float *pfVar4;
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
  loopIndex2 = local_54;
  do {
    *loopIndex2 = GH_U2F(0x7fff0000U);
    loopIndex2 = loopIndex2 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex2 = (float *)&local_64;
  do {
    *loopIndex2 = GH_U2F(0x7fff0000U);
    loopIndex2 = loopIndex2 + 1;
  } while (loopIndex2 != local_54);
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
    iVar3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    if (*(char *)(loopIndex + iVar3 + 0x10) != '\x01') {
      piVar6 = (int *)(loopRemaining + 8);
      loopIndex2 = local_54 + 1;
      do {
        iVar3 = *piVar6;
        if (-1 < iVar3) {
          return 0;
        }
        piVar6 = piVar6 + 4;
        pfVar4 = (float *)FUN_00173360(*(undefined4 *)(ctx + 0x238),iVar3);
        *loopIndex2 = *pfVar4;
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 != local_54 + 3);
      (&local_64)[loopIndex] = (uint)GH_F2U((float)((local_54[1] * local_54[2])));
    }
    bVar1 = loopIndex != 3;
    loopRemaining = loopRemaining + 4;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(loopIndex + 0x10));
  FUN_000f3340(local_34,0x10203,local_38);
  loopIndex = *(int *)(ctx + 0x238);
  local_68 = local_34[0];
  loopIndex = (**(code **)(**(int **)(loopIndex + 0x30c) + 0x154))
                    (*(int **)(loopIndex + 0x30c),*(undefined4 *)(loopIndex + 0x6c4),&local_64,&local_68,
                     in_r7,in_r8,loopIndex);
  if (loopIndex == 0) {
    loopIndex = 0;
    loopIndex2 = (float *)&local_64;
    do {
      loopRemaining = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (*(char *)(loopIndex + loopRemaining + 0x10) != '\x01') {
        *loopIndex2 = -*loopIndex2;
      }
      bVar1 = loopIndex != 3;
      loopIndex2 = loopIndex2 + 1;
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

/* FUN_0017f3f8 @ 0x17f3f8 (412 bytes) */
int FUN_0017f3f8(ctx, param_2)
  int ctx;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  int *a0;
  uint uVar5;
  int loopIndex;
  undefined4 local_38 [6];
  
  iVar3 = FUN_00179c44(ctx,1,2);
  if (iVar3 != 0) {
    iVar3 = *(int *)(ctx + 0xb0);
    if (((*(uint *)(iVar3 + 0xb8) & 1) != (*(uint *)(iVar3 + 0xd0) & 1)) &&
       ((*(uint *)(iVar3 + 0xb8) >> 1 & 1) == (*(uint *)(iVar3 + 0xd0) >> 1 & 1))) {
      bVar2 = true;
      iVar3 = IRInst__getOperandRecord(iVar3,0);
      uVar5 = 0;
      loopIndex = 0;
      local_38[0] = *(undefined4 *)(iVar3 + 0x10);
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
            FUN_001745ac(ctx);
            return 1;
          }
          puVar4 = (uint *)FUN_00173360(*(undefined4 *)(ctx + 0x238),*(int *)(iVar3 + 0x178));
          if (bVar2) {
            uVar5 = *puVar4 >> 0x1f;
            bVar2 = false;
          }
          else if (*puVar4 >> 0x1f != uVar5) goto LAB_0017f514;
        }
        bVar1 = loopIndex == 3;
        iVar3 = iVar3 + 4;
        loopIndex = loopIndex + 1;
        if (bVar1) {
          ((int (*)())FUN_0017c244)(ctx,1);
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,1,(uint)(param_2 == uVar5));
          IROperand__setModifierBits(*(int *)(ctx + 0xb0) + 0xa4,2,0);
          FUN_001745ac(ctx);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0017f594 @ 0x17f594 (8 bytes) */
int FUN_0017f594(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())FUN_0017f3f8)(param_1,1);
  return callResult;
}

/* FUN_0017f59c @ 0x17f59c (8 bytes) */
int FUN_0017f59c(param_1)
  undefined4 param_1;
{
  undefined4 callResult;
  
  callResult = ((int (*)())FUN_0017f3f8)(param_1,0);
  return callResult;
}

/* FUN_0017f5a4 @ 0x17f5a4 (488 bytes) */
int FUN_0017f5a4(ctx)
  int ctx;
{
  int loopIndex;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
  loopIndex = FUN_000f2e18(*(undefined4 *)(loopIndex + 0x10));
  if (loopIndex == 0) {
    piVar2 = (int *)IRInst__clone(*(undefined4 *)(ctx + 0xb0),*(undefined4 *)(ctx + 0x238),0)
    ;
    loopIndex = *(int *)(ctx + 0x238);
    uVar3 = *(undefined4 *)(*(int *)(loopIndex + 0x6c4) + 0x3ac);
    iVar4 = *(int *)(loopIndex + 0x3ac) + -1;
    *(int *)(loopIndex + 0x3ac) = iVar4;
    uVar3 = FUN_00127608(uVar3,0,iVar4,0);
    FUN_0012306c(uVar3,*(undefined4 *)(ctx + 0xb0));
    IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),0,uVar3);
    loopIndex = piVar2[0x23];
    *(undefined1 *)(*(int *)(ctx + 0xb0) + 0x9f) = 1;
    piVar2[0x27] = 0x1010100;
    FUN_0012306c(loopIndex,piVar2);
    loopIndex = 1;
    piVar5 = piVar2;
    while( true ) {
      iVar4 = (**(code **)(*piVar2 + 0x14))(piVar2);
      if (iVar4 < loopIndex) break;
      FUN_001236e4(piVar5[0x29],loopIndex,piVar2);
      loopIndex = loopIndex + 1;
      piVar5 = piVar5 + 6;
    }
    if ((*(uint *)(*(int *)(ctx + 0xb0) + 0x14) & 0x200) == 0) {
      IRInst__appendSource(*(int *)(ctx + 0xb0),uVar3);
      FUN_001236e4(uVar3,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x84),*(int *)(ctx + 0xb0));
      *(uint *)(*(int *)(ctx + 0xb0) + 0x14) =
           *(uint *)(*(int *)(ctx + 0xb0) + 0x14) | 0x200;
      loopIndex = FUN_00122fa4(uVar3,*(undefined4 *)
                                  (*(int *)(*(uint *)(ctx + 0x238) + 0x6c4) + 0x3a0),
                           *(uint *)(ctx + 0x238));
      *(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x84) * 4 + ctx + 0x210) =
           *(undefined4 *)(loopIndex + 0xb0);
      IRInst__appendSource(piVar2,uVar3);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
      piVar2[5] = piVar2[5] | 0x200;
    }
    else {
      IRInst__setOperandRef(piVar2,piVar2[0x21],uVar3);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
    }
    FUN_001745ac(ctx);
    Block__insertInstAfter(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),*(int *)(ctx + 0xb0),piVar2);
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
  int *loopIndex3;
  int *loopIndex4;
  int loopIndex2;
  int local_38 [8];
  
  if ((*(int *)(*(int *)(ctx + 0xb0) + 0x80) == 1) &&
     (loopIndex = IRInst__getOperandRecord(*(int *)(ctx + 0xb0),0), *(int *)(loopIndex + 0x10) == DAT_001b01d0)) {
    return 0;
  }
  loopIndex4 = local_38;
  loopIndex = 4;
  loopIndex3 = loopIndex4;
  do {
    *loopIndex3 = 0x7ffffffe;
    loopIndex3 = loopIndex3 + 1;
    loopIndex = loopIndex + -1;
  } while (loopIndex != 0);
  loopIndex2 = 4;
  loopIndex = 0;
  do {
    *(undefined4 *)(loopIndex + (int)loopIndex4) = 0x7ffffffe;
    loopIndex = loopIndex + 4;
    loopIndex2 = loopIndex2 + -1;
  } while (loopIndex2 != 0);
  loopIndex = ((int (*)())FUN_0017dbdc)(ctx,loopIndex4);
  if (loopIndex != 0) {
    return 0;
  }
  loopIndex3 = (int *)Opcode__getInfo(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8));
  loopIndex = (**(code **)(*loopIndex3 + 0x14))(loopIndex3,ctx,loopIndex4,*(undefined4 *)(ctx + 0x238));
  if (loopIndex == 0) {
    return 0;
  }
  loopIndex2 = *(int *)(ctx + 0xb0);
  loopIndex = *(int *)(*(int *)(loopIndex2 + 0x88) + 8);
  if (loopIndex == 0x1d) {
    FUN_00177ad0(ctx);
    loopIndex = ((int (*)())FUN_0017c0f8)(ctx);
    if (loopIndex != 0) {
      return 0;
    }
    loopIndex = FUN_0017ab4c(ctx);
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
      loopIndex = ((int (*)())FUN_0017c888)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017f594)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopIndex3 = loopIndex4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopIndex3 == 0x7ffffffe) && (loopIndex = FUN_00179e74(ctx,loopIndex2), loopIndex == 0)) {
            FUN_0017994c(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopIndex3 = loopIndex3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
    else if (loopIndex < 0x18) {
      if (loopIndex == 0x13) {
        FUN_00177ad0(ctx);
        loopIndex = ((int (*)())FUN_0017d57c)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())FUN_0017c774)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),0xc);
        if ((loopIndex != 0) && (loopIndex = ((int (*)())FUN_0017e1f4)(ctx), loopIndex != 0)) {
          return 0;
        }
        loopIndex2 = 0;
        loopIndex3 = loopIndex4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if ((*loopIndex3 == 0x7ffffffe) && (loopIndex = FUN_001768d4(ctx,loopIndex2), loopIndex == 0)) {
              FUN_00179f38(ctx,loopIndex2);
            }
          }
          bVar1 = loopIndex2 != 3;
          loopIndex3 = loopIndex3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
      }
      else {
        if (loopIndex != 0x14) goto LAB_0017fe28;
        FUN_00177ad0(ctx);
        loopIndex = ((int (*)())FUN_0017cd18)(ctx);
        if (loopIndex != 0) {
          return 0;
        }
        loopIndex = ((int (*)())FUN_0017e6c8)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())FUN_0017e658)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex = ((int (*)())FUN_0017f1f8)(ctx);
        if (loopIndex != 0) {
          return 1;
        }
        loopIndex2 = 0;
        loopIndex3 = loopIndex4;
        do {
          loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
          if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
            loopIndex = *(int *)(ctx + 0x238);
            if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if (*loopIndex3 == 0x7ffffffe) {
              FUN_00179db0(ctx,loopIndex2);
            }
          }
          bVar1 = loopIndex2 != 3;
          loopIndex3 = loopIndex3 + 1;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
      }
    }
    else {
      if (loopIndex != 0x19) {
        if (loopIndex == 0x1c) {
          FUN_00177ad0(ctx);
          loopIndex = ((int (*)())FUN_0017bf70)(ctx);
          if (loopIndex != 0) {
            return 0;
          }
          loopIndex = FUN_0017ab4c(ctx);
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
      loopIndex = ((int (*)())FUN_0017c888)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017f59c)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopIndex3 = loopIndex4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopIndex3 == 0x7ffffffe) && (loopIndex = FUN_00179e74(ctx,loopIndex2), loopIndex == 0)) {
            FUN_00179a34(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopIndex3 = loopIndex3 + 1;
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
      loopIndex = ((int (*)())FUN_0017c41c)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017c4a4)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopIndex3 = loopIndex4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopIndex3 == 0x7ffffffe) && (loopIndex = FUN_0017a034(ctx,loopIndex2), loopIndex == 0)) {
            FUN_001797d0(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopIndex3 = loopIndex3 + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (bVar1);
    }
    else {
      loopIndex = ((int (*)())FUN_0017d9b8)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex = ((int (*)())FUN_0017d3f8)(ctx);
      if (loopIndex != 0) {
        return 0;
      }
      loopIndex2 = 0;
      loopIndex3 = loopIndex4;
      do {
        loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
        if (*(char *)(loopIndex2 + loopIndex + 0x10) != '\x01') {
          loopIndex = *(int *)(ctx + 0x238);
          if (*(int *)(loopIndex + 0x658) <= *(int *)(*(int *)(loopIndex + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*loopIndex3 == 0x7ffffffe) && (loopIndex = FUN_00176954(ctx,loopIndex2), loopIndex == 0)) {
            FUN_00179894(ctx,loopIndex2);
          }
        }
        bVar1 = loopIndex2 != 3;
        loopIndex3 = loopIndex3 + 1;
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
  loopIndex = FUN_00113090(*(undefined4 *)(*(int *)(loopIndex2 + 0x88) + 8),loopIndex);
  if ((loopIndex == 0) &&
     (loopIndex = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(ctx + 0x238)), loopIndex == 0)) {
    loopIndex = 0;
    do {
      if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*loopIndex4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopIndex4,loopIndex);
      }
      bVar1 = loopIndex != 3;
      loopIndex4 = loopIndex4 + 1;
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
      if (*loopIndex4 != 0x7ffffffe) {
        FUN_001765a4(ctx,*loopIndex4,loopIndex);
      }
      bVar1 = loopIndex != 3;
      loopIndex4 = loopIndex4 + 1;
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
      iVar3 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
      if (((*(char *)(loopIndex + iVar3 + 0x10) != '\x01') && (*(int *)(loopIndex2 + 0x30) == 0)) &&
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
      loopIndex = FUN_000f30d4(*(undefined4 *)(loopIndex2 + 0x10));
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
    loopIndex = FUN_000f30d4(*(undefined4 *)(loopIndex2 + 0x10));
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

/* FUN_00180250 @ 0x180250 (1504 bytes) */
int FUN_00180250(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int loopIndex2;
  char *loopIndex5;
  int loopIndex3;
  int iVar10;
  int *loopIndex6;
  char *loopIndex4;
  undefined4 uVar13;
  int loopIndex;
  uint uVar15;
  uint uVar16;
  int *loopIndex7;
  uint *puVar18;
  int loopRemaining;
  int local_58;
  int local_54 [3];
  int local_48;
  int local_44 [7];
  
  loopIndex7 = *(int **)(ctx + 0xb0);
  if (*(int *)(loopIndex7[0x22] + 8) == 0x77) {
    iVar4 = IRInst__getOperandRecord(loopIndex7,1);
    local_54[0] = *(int *)(iVar4 + 0x10);
    bVar2 = false;
    loopIndex = 0;
    iVar4 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
    local_58 = *(int *)(iVar4 + 0x10);
    iVar4 = ctx;
    do {
      if (*(int *)(iVar4 + 0x178) < 0) {
        pfVar5 = (float *)FUN_00173360(*(undefined4 *)(ctx + 0x238),*(int *)(iVar4 + 0x178));
        local_44[1] = 0;
        if (0.0 <= *pfVar5) {
          if ((*(uint *)(*(int *)(*(int *)(ctx + 0x238) + 0x30c) + 8) & 0x1000) != 0) {
            *(undefined1 *)((int)local_54 + loopIndex) = 4;
            *(undefined1 *)((int)local_54 + loopIndex + -4) = 1;
          }
        }
        else {
          bVar2 = true;
        }
      }
      bVar1 = loopIndex != 3;
      iVar4 = iVar4 + 4;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    if (bVar2) {
      bVar2 = false;
      loopIndex = 0;
      iVar4 = ctx;
      do {
        if (((*(uint *)(*(int *)(*(int *)(ctx + 0x238) + 0x30c) + 8) & 0x1000) != 0) &&
           (*(int *)(iVar4 + 0x178) < 0)) {
          pfVar5 = (float *)FUN_00173360(*(int *)(ctx + 0x238),*(int *)(iVar4 + 0x178));
          local_44[1] = 0;
          if (*pfVar5 < 0.0) {
            if (bVar2) {
              *(undefined1 *)((int)local_54 + loopIndex) = 4;
              *(undefined1 *)((int)local_54 + loopIndex + -4) = 1;
            }
            bVar2 = true;
          }
        }
        bVar1 = loopIndex != 3;
        iVar4 = iVar4 + 4;
        loopIndex = loopIndex + 1;
      } while (bVar1);
    }
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
    iVar4 = local_54[0];
    if (local_54[0] == *(int *)(loopIndex + 0x10)) {
      loopIndex7 = *(int **)(ctx + 0xb0);
      goto LAB_001803f4;
    }
    uVar13 = 1;
    loopIndex = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),1);
    *(int *)(loopIndex + 0x10) = iVar4;
    *(int *)(*(int *)(ctx + 0xb0) + 0x9c) = local_58;
    loopIndex7 = *(int **)(ctx + 0xb0);
  }
  else {
LAB_001803f4:
    uVar13 = 0;
  }
  if (loopIndex7[0x20] == 0) {
LAB_001807f4:
    iVar4 = (**(code **)(*loopIndex7 + 0x68))(loopIndex7);
    if (iVar4 != 0) goto LAB_00180440;
  }
  else {
    iVar4 = FUN_00126760(loopIndex7[0x26]);
    if (((iVar4 == 0) || ((loopIndex7[5] & 2U) != 0)) ||
       (iVar4 = (**(code **)(*loopIndex7 + 0x50))(loopIndex7), iVar4 != 0)) {
      loopIndex7 = *(int **)(ctx + 0xb0);
      goto LAB_001807f4;
    }
LAB_00180440:
    iVar4 = (**(code **)(**(int **)(ctx + 0xb0) + 0x28))(*(int **)(ctx + 0xb0));
    if ((iVar4 == 0) || ((*(uint *)(*(int *)(*(int *)(ctx + 0x238) + 0x30c) + 8) & 0x800) != 0))
    {
      loopIndex7 = *(int **)(ctx + 0xb0);
      goto LAB_001804a4;
    }
  }
  loopIndex7 = *(int **)(ctx + 0xb0);
  if (*(int *)(loopIndex7[0x22] + 8) != 0x77) {
    return uVar13;
  }
  if ((*(uint *)(*(int *)(*(int *)(ctx + 0x238) + 0x30c) + 8) & 0x800) == 0) {
    return uVar13;
  }
LAB_001804a4:
  loopIndex = 1;
  iVar4 = ctx;
  do {
    iVar6 = (**(code **)(*loopIndex7 + 0x14))(loopIndex7);
    if (iVar6 < loopIndex) {
      return uVar13;
    }
    iVar6 = thunk_FUN_001268a4(*(undefined4 *)(loopIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x98));
    if (iVar6 != 0) {
      puVar18 = *(uint **)(*(int *)(loopIndex * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
      uVar15 = puVar18[1];
      uVar16 = uVar15 - 1;
      if (uVar16 < *puVar18) {
        if (uVar15 <= uVar16) {
          _memset(uVar15 * 4 + puVar18[2],0,(uVar16 - uVar15) * 4 + 4);
          puVar18[1] = uVar15;
        }
        loopIndex7 = (int *)(uVar16 * 4 + puVar18[2]);
      }
      else {
        loopIndex7 = (int *)Vector__elementRefGrow(puVar18,uVar16);
      }
      if ((*(int *)(*(int *)(*(int *)(*loopIndex7 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*loopIndex7 + 0xb4) != 0)) {
        iVar6 = FUN_001793d8(ctx,loopIndex,*(undefined4 *)(iVar4 + 0x228));
        if (iVar6 == 4) {
          iVar6 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),loopIndex);
          local_58 = *(int *)(iVar6 + 0x10);
          iVar6 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),loopIndex);
          local_54[0] = *(int *)(iVar6 + 0x10);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(ctx + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(local_44,local_54[0],*(undefined4 *)(iVar4 + 0x228));
            local_54[0] = local_44[0];
          }
          iVar6 = ctx + loopIndex * 4 + 0x220;
          iVar10 = ctx + loopIndex * 0x10 + 0x160;
          loopIndex5 = (char *)(iVar6 + 4);
          loopIndex7 = (int *)(iVar10 + 8);
          loopIndex2 = 0;
          do {
            if (*loopIndex5 != '\0') {
              loopRemaining = 4;
              loopIndex4 = (char *)(iVar6 + 4);
              loopIndex6 = (int *)(iVar10 + 8);
              loopIndex3 = 0;
              do {
                if (*loopIndex4 != '\0') {
                  if (loopIndex3 == loopIndex2) break;
                  if ((*loopIndex7 == *loopIndex6) &&
                     (cVar3 = *(char *)((int)local_54 + loopIndex3 + -4),
                     *(char *)((int)local_54 + loopIndex2) != cVar3)) {
                    *(char *)((int)local_54 + loopIndex2) = cVar3;
                    break;
                  }
                }
                loopIndex3 = loopIndex3 + 1;
                loopIndex4 = loopIndex4 + 1;
                loopIndex6 = loopIndex6 + 1;
                loopRemaining = loopRemaining + -1;
              } while (loopRemaining != 0);
            }
            bVar2 = loopIndex2 != 3;
            loopIndex5 = loopIndex5 + 1;
            loopIndex7 = loopIndex7 + 1;
            loopIndex2 = loopIndex2 + 1;
          } while (bVar2);
          if ((local_54[0] != local_58) &&
             (loopIndex7 = *(int **)(*(int *)(ctx + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopIndex7 + 0x104))
                               (loopIndex7,*(undefined4 *)(ctx + 0xb0),loopIndex,local_54,0),
             iVar6 = local_54[0], loopIndex2 != 0)) {
            loopIndex2 = *(int *)(ctx + 0xb0);
            if (loopIndex == 0) {
LAB_00180784:
              uVar13 = 1;
              *(int *)(loopIndex2 + 0x9c) = iVar6;
            }
            else {
              uVar13 = 1;
              loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
              *(int *)(loopIndex2 + 0x10) = iVar6;
            }
          }
        }
        else {
          local_58 = *(int *)(PTR_DAT_001e8b8c + iVar6 * 4);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(ctx + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(&local_48,local_58,*(undefined4 *)(iVar4 + 0x228));
            local_58 = local_48;
          }
          iVar6 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),loopIndex);
          if ((local_58 != *(int *)(iVar6 + 0x10)) &&
             (loopIndex7 = *(int **)(*(int *)(ctx + 0x238) + 0x30c),
             loopIndex2 = (**(code **)(*loopIndex7 + 0x104))
                               (loopIndex7,*(undefined4 *)(ctx + 0xb0),loopIndex,&local_58,0),
             iVar6 = local_58, loopIndex2 != 0)) {
            loopIndex2 = *(int *)(ctx + 0xb0);
            if (loopIndex == 0) goto LAB_00180784;
            uVar13 = 1;
            loopIndex2 = IRInst__getOperandRecord(loopIndex2,loopIndex);
            *(int *)(loopIndex2 + 0x10) = iVar6;
          }
        }
      }
    }
    loopIndex7 = *(int **)(ctx + 0xb0);
    loopIndex = loopIndex + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_00180830 @ 0x180830 (2472 bytes) */
int FUN_00180830(ctx)
  int ctx;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int loopIndex4;
  float *pfVar5;
  int loopIndex5;
  void *inst;
  int *callResult;
  void *inst2;
  int loopRemaining;
  undefined4 *loopIndex9;
  int *loopIndex7;
  int operandRecord;
  int loopIndex;
  undefined4 uVar15;
  int loopIndex2;
  int iVar17;
  uint uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  undefined4 uVar22;
  uint uVar23;
  int *loopIndex8;
  void *inst3;
  char *loopIndex6;
  uint *puVar27;
  int loopIndex3;
  double dVar29;
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
  
  if (*(int *)(*(int *)(ctx + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0xa8)) {
    return 0;
  }
  loopIndex8 = *(int **)(ctx + 0xb0);
  uVar15 = 0;
  for (iVar17 = 1; loopIndex4 = (**(code **)(*loopIndex8 + 0x14))(loopIndex8), iVar17 <= loopIndex4;
      iVar17 = iVar17 + 1) {
    loopIndex8 = *(int **)(ctx + 0xb0);
    if ((loopIndex8[iVar17 * 6 + 0x28] & 2U) != 0) {
      puVar27 = *(uint **)(loopIndex8[iVar17 * 6 + 0x23] + 0x2c);
      uVar21 = puVar27[1];
      uVar18 = uVar21 - 1;
      if (uVar18 < *puVar27) {
        if (uVar21 <= uVar18) {
          _memset(uVar21 * 4 + puVar27[2],0,(uVar18 - uVar21) * 4 + 4);
          puVar27[1] = uVar21;
          loopIndex8 = *(int **)(ctx + 0xb0);
        }
        loopIndex9 = (undefined4 *)(uVar18 * 4 + puVar27[2]);
      }
      else {
        loopIndex9 = (undefined4 *)Vector__elementRefGrow(puVar27,uVar18);
        loopIndex8 = *(int **)(ctx + 0xb0);
      }
      uVar22 = *loopIndex9;
      bVar2 = true;
      loopIndex6 = (char *)(iVar17 * 4 + ctx + 0x224);
      bVar3 = true;
      loopIndex4 = 0;
      do {
        if (*loopIndex6 != '\0') {
          iVar19 = IRInst__getOperandRecord(loopIndex8,iVar17);
          iVar19 = FUN_00176518(uVar22,(uint)*(byte *)(loopIndex4 + iVar19 + 0x10));
          if (iVar19 == 0) {
            iVar19 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),iVar17);
            iVar19 = FUN_001764fc(uVar22,(uint)*(byte *)(loopIndex4 + iVar19 + 0x10));
            if ((iVar19 == 0) || (!bVar3)) {
LAB_00180a10:
              loopIndex8 = *(int **)(ctx + 0xb0);
              goto LAB_00180a14;
            }
            loopIndex8 = *(int **)(ctx + 0xb0);
            bVar2 = false;
          }
          else {
            if (!bVar2) goto LAB_00180a10;
            loopIndex8 = *(int **)(ctx + 0xb0);
            bVar3 = false;
          }
        }
        bVar1 = loopIndex4 != 3;
        loopIndex6 = loopIndex6 + 1;
        loopIndex4 = loopIndex4 + 1;
      } while (bVar1);
      if (bVar2) {
        IROperand__setModifierBits(loopIndex8 + iVar17 * 6 + 0x23,2,0);
        loopIndex8 = *(int **)(ctx + 0xb0);
        uVar15 = 1;
      }
      else if ((bVar3) && ((loopIndex8[iVar17 * 6 + 0x28] & 1U) != 0)) {
        uVar15 = 1;
        IROperand__setModifierBits(loopIndex8 + iVar17 * 6 + 0x23,2,0);
        IROperand__setModifierBits(iVar17 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c,1,0);
        loopIndex8 = *(int **)(ctx + 0xb0);
      }
    }
LAB_00180a14: ;
  }
  iVar17 = Compiler__isOptionEnabled(*(undefined4 *)(ctx + 0x238),10);
  if (iVar17 != 0) {
    loopIndex4 = 0x18;
    iVar17 = ctx;
    for (iVar19 = 1;
        loopIndex5 = (**(code **)(**(int **)(ctx + 0xb0) + 0x14))(*(int **)(ctx + 0xb0)),
        iVar19 <= loopIndex5; iVar19 = iVar19 + 1) {
      loopIndex5 = FUN_00105dbc(*(undefined4 *)(ctx + 0xb0),iVar19);
      if (loopIndex5 == 2) {
        puVar27 = *(uint **)(*(int *)(loopIndex4 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
        uVar18 = puVar27[1];
        uVar21 = uVar18 - 1;
        if (uVar21 < *puVar27) {
          if (uVar18 <= uVar21) {
            _memset(uVar18 * 4 + puVar27[2],0,(uVar21 - uVar18) * 4 + 4);
            puVar27[1] = uVar18;
          }
          loopIndex8 = (int *)(uVar21 * 4 + puVar27[2]);
        }
        else {
          loopIndex8 = (int *)Vector__elementRefGrow(puVar27,uVar21);
        }
        loopIndex2 = *loopIndex8;
        loopIndex5 = *(int *)(loopIndex2 + 0x178);
        if (loopIndex5 < 0) {
          pfVar5 = (float *)FUN_00173360(*(undefined4 *)(ctx + 0x238),loopIndex5);
          if (*(int *)(*(int *)(loopIndex2 + 0xb0) + 300) == 0) {
            dVar29 = _floor((double)*pfVar5);
            loopIndex5 = (int)dVar29;
            local_80 = (longlong)loopIndex5;
          }
          else {
            dVar29 = _floor((double)*pfVar5 + 0.5);
            loopIndex5 = (int)dVar29;
            local_88 = (longlong)loopIndex5;
          }
          loopIndex2 = FUN_00105c5c(*(undefined4 *)(ctx + 0xb0),iVar19);
          loopIndex5 = loopIndex5 + loopIndex2;
          if (*(int *)(*(int *)(*(int *)(ctx + 0x238) + 0x30c) + 0x2c) <= loopIndex5) {
            loopIndex5 = 0;
          }
          loopIndex2 = *(int *)(ctx + 0xb0);
          uVar22 = *(undefined4 *)(*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x3ac);
          if ((iVar19 < 1) || (loopIndex = IRInst__getOperandSource(loopIndex2,iVar19), loopIndex == 0)) {
            uVar20 = *(undefined4 *)(loopIndex4 + loopIndex2 + 0x98);
          }
          else {
            loopIndex2 = IRInst__getOperandSource(loopIndex2,iVar19);
            uVar20 = *(undefined4 *)(loopIndex2 + 0x98);
          }
          loopIndex2 = FUN_00126708(uVar20);
          if (loopIndex2 == 0) {
            uVar22 = FUN_00127608(uVar22,0,loopIndex5,0);
          }
          else {
            uVar22 = FUN_00127608(uVar22,2,loopIndex5,0);
          }
          IRInst__setOperandRef(*(undefined4 *)(ctx + 0xb0),iVar19,uVar22);
          FUN_001236e4(uVar22,iVar19,*(undefined4 *)(ctx + 0xb0));
          loopIndex5 = FUN_00122fa4(uVar22,*(undefined4 *)
                                       (*(int *)(*(uint *)(ctx + 0x238) + 0x6c4) + 0x3a0),
                               *(uint *)(ctx + 0x238));
          *(undefined4 *)(iVar17 + 0x214) = *(undefined4 *)(loopIndex5 + 0xb0);
        }
      }
      loopIndex4 = loopIndex4 + 0x18;
      iVar17 = iVar17 + 4;
    }
  }
  loopIndex8 = *(int **)(ctx + 0xb0);
  if (loopIndex8[0x20] == 0) {
LAB_001818e8:
    if (((loopIndex8[5] & 2U) != 0) || (iVar17 = FUN_001789d4(loopIndex8), iVar17 != 0))
    goto LAB_00180cb4;
  }
  else {
    iVar17 = FUN_00126760(loopIndex8[0x26]);
    if (((iVar17 == 0) || ((loopIndex8[5] & 2U) != 0)) ||
       (iVar17 = (**(code **)(*loopIndex8 + 0x50))(loopIndex8), iVar17 != 0)) {
      loopIndex8 = *(int **)(ctx + 0xb0);
      goto LAB_001818e8;
    }
    loopIndex8 = *(int **)(ctx + 0xb0);
LAB_00180cb4:
    iVar17 = ctx;
    for (loopIndex4 = 1; iVar19 = (**(code **)(*loopIndex8 + 0x14))(loopIndex8), loopIndex4 <= iVar19;
        loopIndex4 = loopIndex4 + 1) {
      puVar27 = *(uint **)(*(int *)(loopIndex4 * 0x18 + *(int *)(ctx + 0xb0) + 0x8c) + 0x2c);
      uVar21 = puVar27[1];
      uVar18 = uVar21 - 1;
      if (uVar18 < *puVar27) {
        if (uVar21 <= uVar18) {
          _memset(uVar21 * 4 + puVar27[2],0,(uVar18 - uVar21) * 4 + 4);
          puVar27[1] = uVar21;
        }
        loopIndex8 = (int *)(uVar18 * 4 + puVar27[2]);
      }
      else {
        loopIndex8 = (int *)Vector__elementRefGrow(puVar27,uVar18);
      }
      loopIndex8 = *(int **)(*loopIndex8 + 0xb0);
      iVar19 = (**(code **)(*loopIndex8 + 0x74))(loopIndex8);
      if (((iVar19 != 0) && (*(int *)(loopIndex8[0x22] + 8) == 0xfb)) &&
         (iVar19 = FUN_00105dbc(*(undefined4 *)(ctx + 0xb0),loopIndex4), iVar19 == 0)) {
        iVar19 = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),loopIndex4);
        FUN_000f3398(&local_78,*(undefined4 *)(iVar19 + 0x10));
        local_9c = local_78;
        loopIndex7 = (int *)((int (*)())FUN_0017bc58)(loopIndex8,local_78,1,*(undefined4 *)(ctx + 0x238));
        if (loopIndex7 != (int *)0x0) {
          iVar19 = (**(code **)(*loopIndex7 + 0x40))(loopIndex7);
          if (iVar19 == 0) {
            iVar19 = IRInst__getOperandRecord(loopIndex7,0);
            FUN_000f3908(&local_74,*(undefined4 *)(iVar19 + 0x10));
            uVar18 = local_74;
            uVar21 = ~local_74;
            if (((uVar21 << 0x18 | (uVar21 & 0xff00) << 8 | uVar21 >> 8 & 0xff00 | uVar21 >> 0x18) &
                local_9c) == 0) {
              iVar19 = IRInst__getOperandSource(loopIndex7,1);
              *(int *)(iVar17 + 0x214) = iVar19;
              uVar20 = *(undefined4 *)(iVar19 + 0x8c);
              uVar22 = *(undefined4 *)(ctx + 0xb0);
            }
            else {
              inst = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
              IRInst__setOperandRef(inst,0,loopIndex8[0x23]);
              *(undefined4 *)((int)inst + 0x98) = 0;
              *(undefined4 *)((int)inst + 0x94) = *(undefined4 *)((int)inst + 0x14c);
              iVar19 = IRInst__getOperandSource(loopIndex7,1);
              IRInst__setOperandRef(inst,1,*(undefined4 *)(iVar19 + 0x8c));
              IRInst__setOperandSource(inst,1,iVar19,0,*(undefined4 *)(ctx + 0x238));
              uVar21 = ~(uVar18 & local_9c);
              FUN_000f3764(&local_70,uVar18 & local_9c);
              *(undefined4 *)((int)inst + 0x9c) = local_70;
              FUN_000f370c(&local_6c,local_70);
              uVar22 = local_6c;
              iVar19 = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(iVar19 + 0x10) = uVar22;
              iVar19 = 0;
              local_98 = (uint)inst;
              local_9c = (uVar21 << 0x18 | (uVar21 & 0xff00) << 8 | uVar21 >> 8 & 0xff00 |
                         uVar21 >> 0x18) & local_9c;
              if (local_9c == 0) {
LAB_00181100:
                loopIndex8 = aiStack_94 + iVar19 + -1;
                loopIndex5 = 0;
                do {
                  loopIndex = *loopIndex8;
                  Block__insertInstBefore(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),
                               *(int *)(ctx + 0xb0),loopIndex);
                  FUN_0012306c(*(undefined4 *)(loopIndex + 0x8c),loopIndex);
                  loopIndex2 = IRInst__getOperandSource(loopIndex,1);
                  FUN_001236e4(*(undefined4 *)(loopIndex2 + 0x8c),1,loopIndex);
                  uVar22 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x378);
                  loopIndex9 = (undefined4 *)Arena__alloc(uVar22,0x240);
                  *loopIndex9 = uVar22;
                  loopIndex9 = loopIndex9 + 1;
                  FUN_00173938(loopIndex9,loopIndex,*(undefined4 *)(ctx + 0x238));
                  loopIndex5 = loopIndex5 + 1;
                  loopIndex8 = loopIndex8 + -1;
                  FUN_0011e988(loopIndex9,*(undefined4 *)
                                        (*(int *)(*(int *)(ctx + 0x238) + 0x6c4) + 0x3a0));
                  FUN_00173f1c(loopIndex9);
                  FUN_00174e0c(loopIndex9);
                  FUN_00175b40(loopIndex9);
                  FUN_00173278(loopIndex9);
                  FUN_000e9c00(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),
                               *(undefined4 *)(loopIndex + 0x8c),loopIndex9);
                } while (iVar19 + 1 != loopIndex5);
              }
              else {
                loopIndex7 = aiStack_94;
                loopIndex5 = 1;
                inst3 = inst;
                do {
                  iVar19 = loopIndex5;
                  callResult = (int *)((int (*)())FUN_0017bc58)(loopIndex8,local_9c,0,*(undefined4 *)(ctx + 0x238));
                  if (callResult == (int *)0x0) goto LAB_00181220;
                  inst2 = IRInst__create(0x31,*(undefined4 *)(ctx + 0x238));
                  IRInst__setOperandRef(inst2,0,loopIndex8[0x23]);
                  *(undefined4 *)((int)inst2 + 0x98) = 0;
                  *(undefined4 *)((int)inst2 + 0x94) = *(undefined4 *)((int)inst2 + 0x14c);
                  IRInst__appendSource(inst3,*(undefined4 *)((int)inst2 + 0x8c));
                  IRInst__setExtraOperandSource(inst3,inst2,0,*(undefined4 *)(ctx + 0x238));
                  loopIndex5 = IRInst__getOperandRecord(callResult,0);
                  FUN_000f3908(&local_68,*(undefined4 *)(loopIndex5 + 0x10));
                  uVar18 = local_68 & local_9c;
                  FUN_000f3764(&local_64,uVar18);
                  *(undefined4 *)((int)inst2 + 0x9c) = local_64;
                  FUN_000f370c(&local_60,local_64);
                  uVar22 = local_60;
                  loopIndex5 = IRInst__getOperandRecord(inst2,1);
                  *(undefined4 *)(loopIndex5 + 0x10) = uVar22;
                  loopIndex5 = (**(code **)(*callResult + 0x40))(callResult);
                  if (loopIndex5 == 0) {
                    loopIndex5 = IRInst__getOperandSource(callResult,1);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(ctx + 0x238));
                  }
                  else {
                    loopIndex5 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
                    loopIndex5 = FUN_00123c08(loopIndex5,*(undefined4 *)(loopIndex5 + 0x3a0),0);
                    loopIndex5 = *(int *)(loopIndex5 + 0xb0);
                    IRInst__setOperandRef(inst2,1,*(undefined4 *)(loopIndex5 + 0x8c));
                    IRInst__setOperandSource(inst2,1,loopIndex5,0,*(undefined4 *)(ctx + 0x238));
                    local_9c = 0;
                  }
                  uVar18 = ~uVar18;
                  local_9c = (uVar18 << 0x18 | (uVar18 & 0xff00) << 8 | uVar18 >> 8 & 0xff00 |
                             uVar18 >> 0x18) & local_9c;
                  *loopIndex7 = (int)inst2;
                  loopIndex7 = loopIndex7 + 1;
                  loopIndex5 = iVar19 + 1;
                  inst3 = inst2;
                } while (local_9c != 0);
                if (iVar19 + 1 == 0) goto LAB_00181220;
                if (-1 < iVar19) goto LAB_00181100;
              }
              *(void **)(iVar17 + 0x214) = inst;
              uVar20 = *(undefined4 *)((int)inst + 0x8c);
              uVar22 = *(undefined4 *)(ctx + 0xb0);
            }
          }
          else {
            iVar19 = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
            iVar19 = FUN_00123c08(iVar19,*(undefined4 *)(iVar19 + 0x3a0),0);
            iVar19 = *(int *)(iVar19 + 0xb0);
            uVar22 = *(undefined4 *)(ctx + 0xb0);
            *(int *)(iVar17 + 0x214) = iVar19;
            uVar20 = *(undefined4 *)(iVar19 + 0x8c);
          }
          IRInst__setOperandRef(uVar22,loopIndex4,uVar20);
          FUN_001236e4(uVar20,loopIndex4,*(undefined4 *)(ctx + 0xb0));
        }
      }
LAB_00181220:
      loopIndex8 = *(int **)(ctx + 0xb0);
      iVar17 = iVar17 + 4;
    }
    loopIndex8 = *(int **)(ctx + 0xb0);
  }
  if (loopIndex8[0x20] != 0) {
    iVar17 = FUN_00126760(loopIndex8[0x26]);
    if (((iVar17 != 0) && ((loopIndex8[5] & 2U) == 0)) &&
       (iVar17 = (**(code **)(*loopIndex8 + 0x50))(loopIndex8), iVar17 == 0)) {
      loopIndex8 = *(int **)(ctx + 0xb0);
      goto code_r0x001812b0;
    }
    loopIndex8 = *(int **)(ctx + 0xb0);
  }
  if (((loopIndex8[5] & 2U) == 0) && (iVar17 = FUN_001789d4(loopIndex8), iVar17 == 0)) {
    return uVar15;
  }
code_r0x001812b0:
  loopIndex2 = 1;
  iVar19 = ctx + 0x170;
  loopIndex5 = ctx + 0x224;
  loopIndex4 = 4;
  iVar17 = ctx;
  do {
    loopIndex = (**(code **)(*loopIndex8 + 0x14))(loopIndex8);
    if (loopIndex < loopIndex2) {
      return uVar15;
    }
    loopIndex8 = *(int **)(ctx + 0xb0);
    uVar22 = *(undefined4 *)(loopIndex8[0x22] + 8);
    loopRemaining = FUN_00176564(uVar22);
    loopIndex = 0x7ffffffe;
    if (loopRemaining == 0) {
      loopIndex = FUN_00176574(uVar22);
      if (loopIndex == 0) {
        loopIndex = FUN_00113174(uVar22,*(undefined4 *)(ctx + 0x238));
        if (loopIndex == 0) {
          loopIndex = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(ctx + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(ctx + 0x238));
          if (loopIndex == 0) {
            FUN_001770e4(&local_50,ctx,loopIndex2);
            loopIndex8 = *(int **)(ctx + 0xb0);
            loopIndex = local_50;
          }
          else {
            FUN_001769f4(&local_54,ctx,loopIndex2);
            loopIndex8 = *(int **)(ctx + 0xb0);
            loopIndex = local_54;
          }
        }
        else {
          FUN_00178d78(&local_58,ctx,loopIndex2);
          loopIndex8 = *(int **)(ctx + 0xb0);
          loopIndex = local_58;
        }
      }
      else {
        FUN_00178c84(&local_5c,ctx,loopIndex2);
        loopIndex8 = *(int **)(ctx + 0xb0);
        loopIndex = local_5c;
      }
    }
    if ((loopIndex8[5] & 2U) == 0) {
code_r0x001813e0:
      if (((loopIndex8[loopIndex2 * 6 + 0x26] == 0x33) || (loopIndex8[loopIndex2 * 6 + 0x26] == 0xc)) ||
         (*(int *)(loopIndex5 + 4) == 0)) goto code_r0x001816c0;
      loopIndex6 = (char *)(loopIndex5 + 4);
      aiStack_94[2] = 0;
      loopIndex8 = (int *)(iVar19 + 8);
      local_98 = 0;
      bVar3 = true;
      aiStack_94[0] = 0;
      loopRemaining = 0;
      aiStack_94[1] = 0;
      do {
        if (*loopIndex6 != '\0') {
          if (*loopIndex8 < 0) {
            loopIndex9 = (undefined4 *)FUN_00173360(*(undefined4 *)(ctx + 0x238),*loopIndex8);
            *(undefined4 *)((int)aiStack_94 + loopRemaining + -4) = *loopIndex9;
          }
          else {
            bVar3 = false;
          }
        }
        bVar2 = loopRemaining != 0xc;
        loopIndex6 = loopIndex6 + 1;
        loopIndex8 = loopIndex8 + 1;
        loopRemaining = loopRemaining + 4;
      } while (bVar2);
      uVar22 = *(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4);
      FUN_000f3340(local_4c,0x10203,*(undefined4 *)(iVar17 + 0x228));
      local_9c = local_4c[0];
      if (loopIndex != 0x7ffffffe) {
        loopIndex8 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopIndex8 + 0x154))(loopIndex8,uVar22,&local_98,&local_9c);
        if (loopRemaining == 0) {
          loopIndex3 = 4;
          loopIndex6 = (char *)(loopIndex4 + ctx + 0x224);
          loopRemaining = 0;
          do {
            if (*loopIndex6 != '\0') {
              *(float *)(loopRemaining + (int)&local_98) = -*(float *)(loopRemaining + (int)&local_98);
            }
            loopIndex6 = loopIndex6 + 1;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + -1;
          } while (loopIndex3 != 0);
          goto code_r0x00181590;
        }
code_r0x001815cc:
        uVar20 = 0;
code_r0x001815d0:
        loopIndex8 = *(int **)(ctx + 0xb0);
        if (loopIndex8[loopIndex2 * 6 + 0x26] != *(int *)(loopRemaining + 0x98)) {
          loopIndex7 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
          loopIndex3 = (**(code **)(*loopIndex7 + 0x11c))(loopIndex7,loopIndex8,loopIndex2,loopRemaining,0,uVar20);
          if (loopIndex3 == 0) goto code_r0x001816bc;
          uVar15 = FUN_0017ae28(ctx,loopIndex2,loopRemaining,local_9c,uVar20,0,
                                *(undefined4 *)(ctx + 0x238));
          loopIndex3 = 0;
          *(undefined4 *)(iVar17 + 0x214) = uVar15;
          loopRemaining = ctx;
          do {
            operandRecord = IRInst__getOperandRecord(*(undefined4 *)(ctx + 0xb0),0);
            if (*(char *)(loopIndex3 + operandRecord + 0x10) == '\x01') {
              *(undefined4 *)(loopRemaining + 0x30) = 0;
            }
            bVar3 = loopIndex3 != 3;
            loopRemaining = loopRemaining + 4;
            loopIndex3 = loopIndex3 + 1;
          } while (bVar3);
          loopIndex8 = *(int **)(ctx + 0xb0);
          uVar15 = 1;
        }
        goto code_r0x001816c0;
      }
      if (bVar3) {
        loopIndex8 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        loopRemaining = (**(code **)(*loopIndex8 + 0x154))(loopIndex8,uVar22,&local_98,&local_9c);
        if (loopRemaining != 0) goto code_r0x001815cc;
        loopIndex3 = 4;
        loopIndex6 = (char *)(loopIndex4 + ctx + 0x224);
        loopRemaining = 0;
        do {
          if (*loopIndex6 != '\0') {
            *(float *)(loopRemaining + (int)&local_98) = -*(float *)(loopRemaining + (int)&local_98);
          }
          loopIndex6 = loopIndex6 + 1;
          loopRemaining = loopRemaining + 4;
          loopIndex3 = loopIndex3 + -1;
        } while (loopIndex3 != 0);
code_r0x00181590:
        loopIndex8 = *(int **)(*(int *)(ctx + 0x238) + 0x30c);
        uVar20 = 1;
        loopRemaining = (**(code **)(*loopIndex8 + 0x154))(loopIndex8,uVar22,&local_98,&local_9c);
        if (loopRemaining != 0) goto code_r0x001815d0;
code_r0x001816bc:
        loopIndex8 = *(int **)(ctx + 0xb0);
        goto code_r0x001816c0;
      }
      loopIndex8 = *(int **)(ctx + 0xb0);
    }
    else {
      loopRemaining = (**(code **)(**(int **)(*(int *)(ctx + 0x238) + 0x30c) + 0xbc))();
      if (loopRemaining != 0) {
        loopIndex8 = *(int **)(ctx + 0xb0);
        goto code_r0x001813e0;
      }
      loopIndex8 = *(int **)(ctx + 0xb0);
code_r0x001816c0:
      if (loopIndex != 0x7ffffffe) {
        if (*(int *)(loopIndex8[0x22] + 8) != 0x8e) {
          loopIndex6 = (char *)(loopIndex5 + 4);
          loopRemaining = 4;
          loopIndex = 0;
          do {
            if (*loopIndex6 != '\0') {
              loopRemaining = IRInst__getOperandRecord(loopIndex8,loopIndex2);
              loopIndex8 = *(int **)(ctx + 0xb0);
              uVar18 = (uint)*(byte *)(loopIndex + loopRemaining + 0x10);
              goto code_r0x00181700;
            }
            loopIndex = loopIndex + 1;
            loopIndex6 = loopIndex6 + 1;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
          uVar18 = 0;
code_r0x00181700:
          puVar27 = *(uint **)(loopIndex8[loopIndex2 * 6 + 0x23] + 0x2c);
          uVar21 = puVar27[1];
          uVar23 = uVar21 - 1;
          if (uVar23 < *puVar27) {
            if (uVar21 <= uVar23) {
              _memset(uVar21 * 4 + puVar27[2],0,(uVar23 - uVar21) * 4 + 4);
              puVar27[1] = uVar21;
            }
            loopIndex8 = (int *)(uVar23 * 4 + puVar27[2]);
          }
          else {
            loopIndex8 = (int *)Vector__elementRefGrow(puVar27,uVar23);
          }
          loopIndex8 = (int *)FUN_00173360(*(undefined4 *)(ctx + 0x238),
                                        *(undefined4 *)(uVar18 * 4 + *loopIndex8 + 0x20));
          loopIndex = *loopIndex8;
        }
        loopIndex8 = (int *)FUN_00173e10(*(undefined4 *)(ctx + 0x238),loopIndex);
        if (*loopIndex8 == 0) {
          loopIndex8 = *(int **)(ctx + 0xb0);
          if ((loopIndex8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            uVar15 = 1;
            IROperand__setModifierBits(loopIndex8 + loopIndex2 * 6 + 0x23,2,0);
            loopIndex8 = *(int **)(ctx + 0xb0);
          }
          if ((loopIndex8[loopIndex2 * 6 + 0x28] & 1U) != 0) {
            uVar15 = 1;
            IROperand__setModifierBits(loopIndex8 + loopIndex2 * 6 + 0x23,1,0);
            loopIndex8 = *(int **)(ctx + 0xb0);
          }
        }
        else if (*loopIndex8 < 1) {
          loopIndex8 = *(int **)(ctx + 0xb0);
          if ((loopIndex8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            uVar15 = 1;
            IROperand__setModifierBits(loopIndex8 + loopIndex2 * 6 + 0x23,2,0);
            loopIndex = *(int *)(ctx + 0xb0) + loopIndex2 * 0x18 + 0x80;
            IROperand__setModifierBits(loopIndex + 0xc,1,(*(uint *)(loopIndex + 0x20) ^ 1) & 1);
            loopIndex8 = *(int **)(ctx + 0xb0);
          }
        }
        else {
          loopIndex8 = *(int **)(ctx + 0xb0);
          if ((loopIndex8[loopIndex2 * 6 + 0x28] & 2U) != 0) {
            uVar15 = 1;
            IROperand__setModifierBits(loopIndex8 + loopIndex2 * 6 + 0x23,2,0);
            loopIndex8 = *(int **)(ctx + 0xb0);
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
int FUN_00181928(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = IRInst__hasSingleUse(param_1,param_3);
  if ((((iVar1 == 0) || (iVar1 = (**(code **)(*param_1 + 0x68))(param_1), iVar1 != 0)) ||
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
  
  if ((((inst[0x20] == 0) || (iVar1 = FUN_00126760(inst[0x26]), iVar1 == 0)) ||
      ((inst[5] & 2U) != 0)) || (iVar1 = (**(code **)(*inst + 0x50))(inst), iVar1 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000f3a30(inst);
  }
  if (((inst2[0x20] == 0) || (iVar2 = FUN_00126760(inst2[0x26]), iVar2 == 0)) ||
     (((inst2[5] & 2U) != 0 || (iVar2 = (**(code **)(*inst2 + 0x50))(inst2), iVar2 != 0)))) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_000f3a30(inst2);
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
  undefined4 *puVar3;
  int *piVar4;
  int loopIndex;
  int iVar6;
  uint uVar7;
  undefined4 arenaAt378;
  uint *puVar9;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
  if (iVar1 != 0) {
    loopIndex = 0;
    iVar6 = *(int *)(param_2 + 0x98);
    do {
      iVar2 = iVar1;
      if ((*(uint *)(iVar6 + 0x14) & 1) != 0) {
        *(int *)(iVar6 + 0x150) = loopIndex;
        arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
        puVar3 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
        *puVar3 = arenaAt378;
        puVar9 = (uint *)param_1[7];
        uVar7 = puVar9[1];
        if (uVar7 < *puVar9) {
          _memset(uVar7 * 4 + puVar9[2],0,4);
          piVar4 = (int *)(uVar7 * 4 + puVar9[2]);
          puVar9[1] = uVar7 + 1;
        }
        else {
          piVar4 = (int *)Vector__elementRefGrow(puVar9,uVar7);
        }
        *piVar4 = (int)(puVar3 + 1);
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
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  int loopIndex;
  uint *puVar11;
  
  iVar1 = *(int *)(param_2 + 0x98);
  for (loopIndex = *(int *)(*(int *)(param_2 + 0x98) + 8); loopIndex != 0; loopIndex = *(int *)(loopIndex + 8))
  {
    if ((*(uint *)(iVar1 + 0x14) & 1) != 0) {
      puVar11 = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(iVar1 + 0x150);
      if (uVar9 < *puVar11) {
        uVar3 = puVar11[1];
        if (uVar3 <= uVar9) {
          _memset(uVar3 * 4 + puVar11[2],0,(uVar9 - uVar3) * 4 + 4);
          puVar11[1] = uVar9 + 1;
        }
        puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
      }
      else {
        puVar4 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar9);
      }
      puVar4 = (undefined4 *)*puVar4;
      *puVar4 = 1;
      puVar4[1] = 1;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 1;
      if ((*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e) && (0 < *(int *)(iVar1 + 0x84))) {
        loopIndex = 1;
        do {
          iVar5 = IRInst__getOperandSource(iVar1,loopIndex);
          if (param_2 == *(int *)(iVar5 + 0x158)) {
            puVar11 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(iVar5 + 0x150);
            if (uVar9 < *puVar11) {
              uVar3 = puVar11[1];
              if (uVar3 <= uVar9) {
                _memset(uVar3 * 4 + puVar11[2],0,(uVar9 - uVar3) * 4 + 4);
                puVar11[1] = uVar9 + 1;
              }
              piVar6 = (int *)(uVar9 * 4 + puVar11[2]);
            }
            else {
              piVar6 = (int *)Vector__elementRefGrow(puVar11,uVar9);
            }
            iVar2 = *(int *)(*piVar6 + 4) + 1;
            iVar5 = puVar4[1];
            if ((int)puVar4[1] < iVar2) {
              iVar5 = iVar2;
            }
            puVar4[1] = iVar5;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(iVar1 + 0x84));
      }
      loopIndex = *(int *)(iVar1 + 8);
    }
    iVar1 = loopIndex;
  }
  *param_3 = 0;
  FUN_00172000(*(undefined4 *)(param_1 + 8));
  iVar1 = *(int *)(param_2 + 0xa0);
  for (loopIndex = *(int *)(*(int *)(param_2 + 0xa0) + 4); loopIndex != 0; loopIndex = *(int *)(loopIndex + 4))
  {
    if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e)) {
      puVar11 = *(uint **)(param_1 + 0x1c);
      uVar9 = *(uint *)(iVar1 + 0x150);
      if (uVar9 < *puVar11) {
        uVar3 = puVar11[1];
        if (uVar3 <= uVar9) {
          _memset(uVar3 * 4 + puVar11[2],0,(uVar9 - uVar3) * 4 + 4);
          puVar11[1] = uVar9 + 1;
        }
        puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
      }
      else {
        puVar4 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar9);
      }
      piVar6 = (int *)*puVar4;
      FUN_00172204(*(undefined4 *)(param_1 + 8),iVar1);
      if (0 < *(int *)(iVar1 + 0x84)) {
        loopIndex = 1;
        do {
          iVar5 = IRInst__getOperandSource(iVar1,loopIndex);
          if (param_2 == *(int *)(iVar5 + 0x158)) {
            puVar11 = *(uint **)(param_1 + 0x1c);
            uVar9 = *(uint *)(iVar5 + 0x150);
            if (uVar9 < *puVar11) {
              uVar3 = puVar11[1];
              if (uVar3 <= uVar9) {
                _memset(uVar3 * 4 + puVar11[2],0,(uVar9 - uVar3) * 4 + 4);
                puVar11[1] = uVar9 + 1;
              }
              puVar4 = (undefined4 *)(uVar9 * 4 + puVar11[2]);
            }
            else {
              puVar4 = (undefined4 *)Vector__elementRefGrow(puVar11,uVar9);
            }
            piVar7 = (int *)*puVar4;
            iVar5 = *piVar7;
            if (*piVar7 < *piVar6 + 1) {
              iVar5 = *piVar6 + 1;
            }
            piVar7[4] = loopIndex;
            *piVar7 = iVar5;
            piVar7[3] = iVar1;
            if (iVar5 < *param_3) {
              iVar5 = *param_3;
            }
            *param_3 = iVar5;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex <= *(int *)(iVar1 + 0x84));
      }
      loopIndex = *(int *)(iVar1 + 4);
    }
    iVar1 = loopIndex;
  }
  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 0x5c))(*(int **)(param_1 + 8));
  *param_4 = uVar8;
  return;
}

/* FUN_00181f00 @ 0x181f00 (220 bytes) */
int FUN_00181f00(compiler, param_2, inst)
  int *compiler;
  int param_2;
  int inst;
{
  undefined4 arenaAt378;
  bool bVar1;
  uint uVar2;
  int iVar3;
  int loopIndex3;
  undefined4 *vectorAlloc3;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc2;
  int *piVar8;
  uint uVar9;
  int loopIndex;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int loopRemaining;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  int loopIndex2;
  int iVar20;
  undefined4 uVar21;
  uint uVar22;
  uint *puVar23;
  uint *puVar24;
  int iVar25;
  uint uVar26;
  undefined1 auStack_88 [8];
  int local_80;
  uint local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  puVar16 = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[4] = arenaAt378;
  vectorAlloc3[2] = 0;
  uVar21 = Arena__alloc(arenaAt378,8);
  vectorAlloc3[3] = uVar21;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  puVar18 = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar21 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar21;
  arenaAt378 = *(undefined4 *)(*compiler + 0x378);
  vectorAlloc2 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  puVar17 = vectorAlloc2 + 1;
  *vectorAlloc2 = arenaAt378;
  vectorAlloc2[1] = 2;
  vectorAlloc2[2] = 0;
  vectorAlloc2[4] = arenaAt378;
  uVar21 = Arena__alloc(arenaAt378,8);
  uVar22 = vectorAlloc3[2];
  uVar2 = *puVar16;
  vectorAlloc2[3] = uVar21;
  if (uVar22 < uVar2) {
    _memset((void *)(uVar22 * 4 + vectorAlloc3[3]),0,4);
    piVar8 = (int *)(uVar22 * 4 + vectorAlloc3[3]);
    vectorAlloc3[2] = uVar22 + 1;
  }
  else {
    piVar8 = (int *)Vector__elementRefGrow(puVar16,uVar22);
  }
  *piVar8 = inst;
  while (uVar2 = vectorAlloc3[2], uVar2 != 0) {
    piVar8 = (int *)0x0;
    if (uVar2 - 1 < uVar2) {
      piVar8 = (int *)((uVar2 - 1) * 4 + vectorAlloc3[3]);
    }
    loopRemaining = *piVar8;
    loopIndex2 = 1;
    Vector__removeAt(puVar16,uVar2 - 1);
    puVar24 = (uint *)(loopRemaining + 0xb8);
    iVar3 = 0x18;
    do {
      loopIndex = IRInst__getOperandSource(loopRemaining,loopIndex2);
      if (param_2 == *(int *)(loopIndex + 0x158)) {
        puVar23 = (uint *)compiler[7];
        uVar2 = *(uint *)(loopIndex + 0x150);
        if (uVar2 < *puVar23) {
          uVar22 = puVar23[1];
          if (uVar22 <= uVar2) {
            _memset((void *)(uVar22 * 4 + puVar23[2]),0,(uVar2 - uVar22) * 4 + 4);
            puVar23[1] = uVar2 + 1;
          }
          piVar8 = (int *)(uVar2 * 4 + puVar23[2]);
        }
        else {
          piVar8 = (int *)Vector__elementRefGrow(puVar23,uVar2);
        }
        if (*(int *)(*piVar8 + 0x14) == 0) {
          if (((*puVar24 & 2) != 0) && (*(int *)(*(int *)(loopIndex + 0x88) + 8) == 0x13)) {
            loopIndex3 = 1;
            iVar13 = loopIndex + 0x98;
            do {
              IROperand__setModifierBits(iVar13 + 0xc,2,1);
              if ((*(uint *)(iVar13 + 0x20) & 1) != 0) {
                IROperand__setModifierBits(iVar13 + 0xc,1,0);
              }
              bVar1 = loopIndex3 != 2;
              iVar13 = iVar13 + 0x18;
              loopIndex3 = loopIndex3 + 1;
            } while (bVar1);
            IROperand__setModifierBits(iVar3 + loopRemaining + 0x8c,2,0);
          }
          uVar2 = *(uint *)(iVar3 + loopRemaining + 0xa0);
          if ((((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) &&
             (*(int *)(*(int *)(loopIndex + 0x88) + 8) == 0x12)) {
            loopIndex3 = 1;
            iVar13 = loopIndex + 0x98;
            do {
              IROperand__setModifierBits(iVar13 + 0xc,1,*(uint *)(iVar13 + 0x20) & 1 ^ 1);
              bVar1 = loopIndex3 != 2;
              iVar13 = iVar13 + 0x18;
              loopIndex3 = loopIndex3 + 1;
            } while (bVar1);
            IROperand__setModifierBits(iVar3 + loopRemaining + 0x8c,1,0);
          }
          uVar2 = vectorAlloc3[2];
          if (uVar2 < *puVar16) {
            _memset((void *)(uVar2 * 4 + vectorAlloc3[3]),0,4);
            piVar8 = (int *)(uVar2 * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = uVar2 + 1;
          }
          else {
            piVar8 = (int *)Vector__elementRefGrow(puVar16,uVar2);
          }
          *piVar8 = loopIndex;
        }
      }
      bVar1 = loopIndex2 != 2;
      iVar3 = iVar3 + 0x18;
      puVar24 = puVar24 + 6;
      loopIndex2 = loopIndex2 + 1;
    } while (bVar1);
    iVar3 = IRInst__getOperandRecord(loopRemaining,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 != 0) {
      iVar3 = IRInst__getOperandRecord(loopRemaining,2);
      FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    }
    iVar3 = IRInst__getOperandRecord(loopRemaining,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      iVar3 = IRInst__getOperandRecord(loopRemaining,2);
      iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
      if (iVar3 != 0) {
        uVar2 = vectorAlloc[2];
        if (uVar2 < *puVar18) {
          _memset((void *)(uVar2 * 4 + vectorAlloc[3]),0,4);
          piVar8 = (int *)(uVar2 * 4 + vectorAlloc[3]);
          vectorAlloc[2] = uVar2 + 1;
        }
        else {
          piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
        }
        *piVar8 = loopRemaining;
        uVar2 = vectorAlloc2[2];
        if (uVar2 < *puVar17) {
          _memset((void *)(uVar2 * 4 + vectorAlloc2[3]),0,4);
          puVar11 = (undefined4 *)(uVar2 * 4 + vectorAlloc2[3]);
          vectorAlloc2[2] = uVar2 + 1;
        }
        else {
          puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar2);
        }
        *puVar11 = 2;
      }
    }
    else {
      uVar2 = vectorAlloc[2];
      if (uVar2 < *puVar18) {
        _memset((void *)(uVar2 * 4 + vectorAlloc[3]),0,4);
        piVar8 = (int *)(uVar2 * 4 + vectorAlloc[3]);
        vectorAlloc[2] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
      }
      *piVar8 = loopRemaining;
      uVar2 = vectorAlloc2[2];
      if (uVar2 < *puVar17) {
        _memset((void *)(uVar2 * 4 + vectorAlloc2[3]),0,4);
        puVar11 = (undefined4 *)(uVar2 * 4 + vectorAlloc2[3]);
        vectorAlloc2[2] = uVar2 + 1;
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar2);
      }
      *puVar11 = 1;
    }
  }
  iVar3 = *(int *)(*(int *)(inst + 0x88) + 8);
  if ((iVar3 == 0x13) || (iVar3 == 0x14)) {
    local_5c = 0x13;
  }
  else {
    local_5c = 0x12;
    if (iVar3 != 0x12) {
      local_5c = 0;
    }
  }
  FUN_001940a8(auStack_88);
  iVar3 = vectorAlloc[2];
  uVar22 = iVar3 - 1;
  uVar2 = uVar22;
  if ((int)uVar22 < 1) {
    loopRemaining = 0;
  }
  else {
    loopIndex2 = uVar22 * 4;
    loopIndex3 = loopIndex2 + -4;
    loopRemaining = 0;
    loopIndex = iVar3;
    do {
      iVar13 = IRInst__create(local_5c,*compiler);
      uVar21 = DAT_001b0210;
      *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
      uVar14 = uVar2 - 1;
      *(undefined4 *)(iVar13 + 0x98) = 0;
      *(undefined4 *)(iVar13 + 0x9c) = uVar21;
      uVar26 = *puVar18;
      if (uVar14 < uVar26) {
        uVar9 = vectorAlloc[2];
        if (uVar9 <= uVar14) {
          _memset((void *)(uVar9 * 4 + vectorAlloc[3]),0,(uVar14 - uVar9) * 4 + 4);
          uVar26 = *puVar18;
          vectorAlloc[2] = uVar2;
        }
        piVar8 = (int *)(loopIndex3 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar14);
        uVar26 = *puVar18;
      }
      if (inst != *piVar8) {
        if (uVar14 < uVar26) {
          uVar9 = vectorAlloc[2];
          if (uVar9 <= uVar14) {
            _memset((void *)(uVar9 * 4 + vectorAlloc[3]),0,(uVar14 - uVar9) * 4 + 4);
            uVar26 = *puVar18;
            vectorAlloc[2] = uVar2;
          }
          piVar8 = (int *)(loopIndex3 + vectorAlloc[3]);
        }
        else {
          piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar14);
          uVar26 = *puVar18;
        }
        loopRemaining = loopRemaining + *(int *)(*piVar8 + 0x124);
      }
      if (uVar2 < uVar26) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc[2] = loopIndex;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
      }
      if (inst != *piVar8) {
        if (uVar2 < *puVar18) {
          uVar26 = vectorAlloc[2];
          if (uVar26 <= uVar2) {
            _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar2 - uVar26) * 4 + 4);
            vectorAlloc[2] = loopIndex;
          }
          piVar8 = (int *)(loopIndex2 + vectorAlloc[3]);
        }
        else {
          piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
        }
        loopRemaining = loopRemaining + *(int *)(*piVar8 + 0x124);
      }
      if (loopRemaining != 0) {
        iVar20 = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        if (loopRemaining < iVar20) {
          *(int *)(iVar13 + 0x124) = iVar20;
          loopRemaining = loopRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
        }
        else {
          iVar20 = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          if (iVar20 < loopRemaining) {
            *(int *)(iVar13 + 0x124) = iVar20;
            loopRemaining = loopRemaining - *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
          }
          else {
            *(int *)(iVar13 + 0x124) = loopRemaining;
            loopRemaining = 0;
          }
        }
      }
      if (uVar14 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc[2] = uVar2;
        }
        puVar11 = (undefined4 *)(loopIndex3 + vectorAlloc[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc2[2] = uVar2;
        }
        puVar11 = (undefined4 *)(loopIndex3 + vectorAlloc2[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar14);
      }
      uVar21 = IRInst__getOperandSource(uVar21,*puVar11);
      IRInst__setOperandSource(iVar13,1,uVar21,0,*compiler);
      if (uVar2 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc[2] = loopIndex;
        }
        puVar11 = (undefined4 *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc2[2] = loopIndex;
        }
        puVar11 = (undefined4 *)(loopIndex2 + vectorAlloc2[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar2);
      }
      uVar21 = IRInst__getOperandSource(uVar21,*puVar11);
      IRInst__setOperandSource(iVar13,2,uVar21,0,*compiler);
      if (uVar14 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc[2] = uVar2;
        }
        puVar11 = (undefined4 *)(loopIndex3 + vectorAlloc[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc2[2] = uVar2;
        }
        puVar11 = (undefined4 *)(loopIndex3 + vectorAlloc2[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar14);
      }
      iVar20 = IRInst__getOperandRecord(uVar21,*puVar11);
      FUN_000f33f8(&local_68,*(undefined4 *)(iVar20 + 0x10));
      uVar26 = local_68 & 0xff;
      if (uVar2 < *puVar18) {
        uVar9 = vectorAlloc[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + vectorAlloc[3]),0,(uVar2 - uVar9) * 4 + 4);
          vectorAlloc[2] = loopIndex;
        }
        puVar11 = (undefined4 *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar9 = vectorAlloc2[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + vectorAlloc2[3]),0,(uVar2 - uVar9) * 4 + 4);
          vectorAlloc2[2] = loopIndex;
        }
        puVar11 = (undefined4 *)(loopIndex2 + vectorAlloc2[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,uVar2);
      }
      iVar20 = IRInst__getOperandRecord(uVar21,*puVar11);
      FUN_000f33f8(&local_64,*(undefined4 *)(iVar20 + 0x10));
      uVar9 = local_64 & 0xff;
      iVar20 = IRInst__getOperandRecord(iVar13,1);
      *(uint *)(iVar20 + 0x10) = uVar26 | 0x4040400;
      iVar20 = IRInst__getOperandRecord(iVar13,2);
      *(uint *)(iVar20 + 0x10) = uVar9 | 0x4040400;
      if (uVar14 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc[2] = uVar2;
        }
        piVar8 = (int *)(loopIndex3 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc2[2] = uVar2;
        }
        piVar8 = (int *)(loopIndex3 + vectorAlloc2[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar17,uVar14);
      }
      IROperand__setModifierBits(iVar13 + 0xa4,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar2 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc[2] = loopIndex;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc2[2] = loopIndex;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc2[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar17,uVar2);
      }
      IROperand__setModifierBits(iVar13 + 0xbc,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar14 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc[2] = uVar2;
        }
        piVar8 = (int *)(loopIndex3 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar14 - uVar26) * 4 + 4);
          vectorAlloc2[2] = uVar2;
        }
        piVar8 = (int *)(loopIndex3 + vectorAlloc2[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar17,uVar14);
      }
      IROperand__setModifierBits(iVar13 + 0xa4,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      if (uVar2 < *puVar18) {
        uVar26 = vectorAlloc[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc[2] = loopIndex;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = vectorAlloc2[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + vectorAlloc2[3]),0,(uVar2 - uVar26) * 4 + 4);
          vectorAlloc2[2] = loopIndex;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc2[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar17,uVar2);
      }
      IROperand__setModifierBits(iVar13 + 0xbc,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      *(undefined4 *)(iVar13 + 0x150) = *(undefined4 *)(compiler[7] + 4);
      arenaAt378 = *(undefined4 *)(*compiler + 0x378);
      puVar11 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
      *puVar11 = arenaAt378;
      puVar24 = (uint *)compiler[7];
      uVar26 = puVar24[1];
      if (uVar26 < *puVar24) {
        _memset((void *)(uVar26 * 4 + puVar24[2]),0,4);
        piVar8 = (int *)(uVar26 * 4 + puVar24[2]);
        puVar24[1] = uVar26 + 1;
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar24,uVar26);
      }
      *piVar8 = (int)(puVar11 + 1);
      DList__pushBack(auStack_88,iVar13);
      uVar2 = uVar2 - 2;
      loopIndex2 = loopIndex2 + -8;
      loopIndex3 = loopIndex3 + -8;
      loopIndex = loopIndex + -2;
    } while (0 < (int)uVar2);
  }
  loopIndex2 = local_80;
  if (uVar2 == 0) {
    loopIndex = IRInst__create(local_5c,*compiler);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(loopIndex + 0x98) = 0;
    *(undefined4 *)(loopIndex + 0x94) = *(undefined4 *)(loopIndex + 0x14c);
    *(undefined4 *)(loopIndex + 0x9c) = uVar21;
    if (*puVar18 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar18,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      piVar8 = (int *)vectorAlloc[3];
    }
    if (inst != *piVar8) {
      if (*puVar18 == 0) {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,0);
      }
      else {
        if (vectorAlloc[2] == 0) {
          *(undefined4 *)vectorAlloc[3] = 0;
          vectorAlloc[2] = 1;
        }
        piVar8 = (int *)vectorAlloc[3];
      }
      loopRemaining = loopRemaining + *(int *)(*piVar8 + 0x124);
    }
    if (loopRemaining == 0) {
      loopIndex3 = *compiler;
      loopRemaining = 0;
    }
    else {
      loopIndex3 = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (loopRemaining < loopIndex3) {
        *(int *)(loopIndex + 0x124) = loopIndex3;
        loopIndex3 = *compiler;
        loopRemaining = loopRemaining - *(int *)(*(int *)(loopIndex3 + 0x30c) + 0x58);
      }
      else {
        loopIndex3 = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (loopIndex3 < loopRemaining) {
          *(int *)(loopIndex + 0x124) = loopIndex3;
          loopIndex3 = *compiler;
          loopRemaining = loopRemaining - *(int *)(*(int *)(loopIndex3 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(loopIndex + 0x124) = loopRemaining;
          loopRemaining = 0;
          loopIndex3 = *compiler;
        }
      }
    }
    IRInst__setOperandSource(loopIndex,1,loopIndex2,0,loopIndex3);
    uVar21 = UNK_001b020c;
    loopIndex3 = IRInst__getOperandRecord(loopIndex,1);
    *(undefined4 *)(loopIndex3 + 0x10) = uVar21;
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      puVar11 = (undefined4 *)vectorAlloc[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      puVar11 = (undefined4 *)vectorAlloc2[3];
    }
    uVar21 = IRInst__getOperandSource(uVar21,*puVar11);
    IRInst__setOperandSource(loopIndex,2,uVar21,0,*compiler);
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      puVar11 = (undefined4 *)vectorAlloc[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)Vector__elementRefGrow(puVar17,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      puVar11 = (undefined4 *)vectorAlloc2[3];
    }
    loopIndex3 = IRInst__getOperandRecord(uVar21,*puVar11);
    FUN_000f33f8(&local_60,*(undefined4 *)(loopIndex3 + 0x10));
    loopIndex3 = IRInst__getOperandRecord(loopIndex,2);
    *(uint *)(loopIndex3 + 0x10) = local_60 & 0xff | 0x4040400;
    if (*puVar18 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar18,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      piVar8 = (int *)vectorAlloc[3];
    }
    loopIndex3 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar17,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      piVar8 = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(loopIndex + 0xbc,1,*(uint *)(*piVar8 * 0x18 + loopIndex3 + 0xa0) & 1);
    if (*puVar18 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar18,0);
    }
    else {
      if (vectorAlloc[2] == 0) {
        *(undefined4 *)vectorAlloc[3] = 0;
        vectorAlloc[2] = 1;
      }
      piVar8 = (int *)vectorAlloc[3];
    }
    loopIndex3 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar17,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      piVar8 = (int *)vectorAlloc2[3];
    }
    IROperand__setModifierBits(loopIndex + 0xbc,2,*(uint *)(*piVar8 * 0x18 + loopIndex3 + 0xa0) >> 1 & 1);
    DList__pushBack(auStack_88,loopIndex);
    *(undefined4 *)(loopIndex + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    puVar11 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *puVar11 = arenaAt378;
    puVar24 = (uint *)compiler[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)Vector__elementRefGrow(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    loopIndex2 = *(int *)(loopIndex2 + 8);
  }
  while (loopIndex = *(int *)(loopIndex2 + 8), *(int *)(loopIndex + 8) != 0) {
    loopIndex3 = IRInst__create(local_5c,*compiler);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(loopIndex3 + 0x98) = 0;
    *(undefined4 *)(loopIndex3 + 0x94) = *(undefined4 *)(loopIndex3 + 0x14c);
    *(undefined4 *)(loopIndex3 + 0x9c) = uVar21;
    if (loopRemaining == 0) {
      iVar13 = *compiler;
    }
    else {
      iVar13 = *(int *)(*(int *)(*compiler + 0x30c) + 0x58);
      if (loopRemaining < iVar13) {
        *(int *)(loopIndex3 + 0x124) = iVar13;
        iVar13 = *compiler;
        loopRemaining = loopRemaining - *(int *)(*(int *)(iVar13 + 0x30c) + 0x58);
      }
      else {
        iVar13 = *(int *)(*(int *)(*compiler + 0x30c) + 0x5c);
        if (iVar13 < loopRemaining) {
          *(int *)(loopIndex3 + 0x124) = iVar13;
          iVar13 = *compiler;
          loopRemaining = loopRemaining - *(int *)(*(int *)(iVar13 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(loopIndex3 + 0x124) = loopRemaining;
          loopRemaining = 0;
          iVar13 = *compiler;
        }
      }
    }
    IRInst__setOperandSource(loopIndex3,1,loopIndex2,0,iVar13);
    IRInst__setOperandSource(loopIndex3,2,loopIndex,0,*compiler);
    uVar21 = UNK_001b020c;
    loopIndex2 = IRInst__getOperandRecord(loopIndex3,1);
    *(undefined4 *)(loopIndex2 + 0x10) = uVar21;
    loopIndex2 = IRInst__getOperandRecord(loopIndex3,2);
    *(undefined4 *)(loopIndex2 + 0x10) = uVar21;
    DList__pushBack(auStack_88,loopIndex3);
    *(undefined4 *)(loopIndex3 + 0x150) = *(undefined4 *)(compiler[7] + 4);
    arenaAt378 = *(undefined4 *)(*compiler + 0x378);
    puVar11 = (undefined4 *)Arena__alloc(arenaAt378,0x1c);
    *puVar11 = arenaAt378;
    puVar24 = (uint *)compiler[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)Vector__elementRefGrow(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    loopIndex2 = *(int *)(loopIndex + 8);
  }
  if (-1 < (int)uVar22) {
    loopIndex2 = uVar22 * 4;
    loopIndex = 0;
    loopRemaining = iVar3;
    do {
      uVar2 = *puVar18;
      uVar26 = uVar22 - loopIndex;
      if (uVar26 < uVar2) {
        uVar14 = vectorAlloc[2];
        if (uVar14 <= uVar26) {
          _memset((void *)(uVar14 * 4 + vectorAlloc[3]),0,(uVar26 - uVar14) * 4 + 4);
          uVar2 = *puVar18;
          vectorAlloc[2] = loopRemaining;
        }
        piVar8 = (int *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        piVar8 = (int *)Vector__elementRefGrow(puVar18,uVar26);
        uVar2 = *puVar18;
      }
      if (inst == *piVar8) goto code_r0x001836f0;
      if (uVar26 < uVar2) {
        uVar2 = vectorAlloc[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + vectorAlloc[3]),0,(uVar26 - uVar2) * 4 + 4);
          vectorAlloc[2] = loopRemaining;
        }
        puVar11 = (undefined4 *)(loopIndex2 + vectorAlloc[3]);
      }
      else {
        puVar11 = (undefined4 *)Vector__elementRefGrow(puVar18,uVar26);
      }
      piVar8 = (int *)*puVar11;
      if (uVar26 < *puVar17) {
        uVar2 = vectorAlloc2[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + vectorAlloc2[3]),0,(uVar26 - uVar2) * 4 + 4);
          vectorAlloc2[2] = loopRemaining;
        }
        piVar12 = (int *)(loopIndex2 + vectorAlloc2[3]);
      }
      else {
        piVar12 = (int *)Vector__elementRefGrow(puVar17,uVar26);
      }
      loopIndex3 = (*piVar12 == 1) + 1;
      IRInst__hasSingleUse(piVar8,compiler[1]);
      puVar24 = (uint *)compiler[7];
      uVar2 = piVar8[0x54];
      if (uVar2 < *puVar24) {
        uVar26 = puVar24[1];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar24[2]),0,(uVar2 - uVar26) * 4 + 4);
          puVar24[1] = uVar2 + 1;
        }
        piVar12 = (int *)(uVar2 * 4 + puVar24[2]);
      }
      else {
        piVar12 = (int *)Vector__elementRefGrow(puVar24,uVar2);
      }
      iVar25 = *(int *)(*piVar12 + 0x10);
      iVar20 = *(int *)(*piVar12 + 0xc);
      uVar21 = IRInst__getOperandSource(piVar8,loopIndex3);
      IRInst__setOperandSource(iVar20,iVar25,uVar21,0,*compiler);
      iVar13 = IRInst__getOperandRecord(piVar8,loopIndex3);
      uVar21 = *(undefined4 *)(iVar13 + 0x10);
      iVar13 = IRInst__getOperandRecord(iVar20,iVar25);
      *(undefined4 *)(iVar13 + 0x10) = uVar21;
      if ((*(uint *)(iVar25 * 0x18 + iVar20 + 0xa0) & 1) == 0) {
        uVar2 = piVar8[loopIndex3 * 6 + 0x28] & 1;
      }
      else {
        uVar2 = piVar8[loopIndex3 * 6 + 0x28] & 1U ^ 1;
      }
      iVar13 = iVar25 * 0x18 + iVar20 + 0x8c;
      IROperand__setModifierBits(iVar13,1,uVar2);
      IROperand__setModifierBits(iVar13,2,(uint)piVar8[loopIndex3 * 6 + 0x28] >> 1 & 1);
      (**(code **)(*piVar8 + 0xc))(piVar8,0,*compiler);
      loopIndex = loopIndex + 1;
      loopIndex2 = loopIndex2 + -4;
      loopRemaining = loopRemaining + -1;
    } while (loopIndex != iVar3);
  }
  uVar2 = *puVar18;
code_r0x001836f0:
  if (uVar2 == 0) {
    piVar8 = (int *)Vector__elementRefGrow(puVar18,0);
  }
  else {
    if (vectorAlloc[2] == 0) {
      *(undefined4 *)vectorAlloc[3] = 0;
      vectorAlloc[2] = 1;
    }
    piVar8 = (int *)vectorAlloc[3];
  }
  if (inst == *piVar8) {
    loopIndex2 = *(int *)(local_80 + 8);
    iVar3 = local_80;
    while (loopRemaining = loopIndex2, loopRemaining != 0) {
      DList__unlink(iVar3);
      Block__insertInstBefore(param_2,inst,iVar3);
      iVar3 = loopRemaining;
      loopIndex2 = *(int *)(loopRemaining + 8);
    }
    if (*puVar17 == 0) {
      piVar8 = (int *)Vector__elementRefGrow(puVar17,0);
    }
    else {
      if (vectorAlloc2[2] == 0) {
        *(undefined4 *)vectorAlloc2[3] = 0;
        vectorAlloc2[2] = 1;
      }
      piVar8 = (int *)vectorAlloc2[3];
    }
    loopIndex2 = *piVar8;
    IRInst__setOperandSource(inst,loopIndex2,*(undefined4 *)(inst + 4),0,*compiler);
    uVar21 = UNK_001b020c;
    iVar3 = IRInst__getOperandRecord(inst,loopIndex2);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    iVar3 = loopIndex2 * 0x18 + inst + 0x8c;
    IROperand__setModifierBits(iVar3,1,0);
    IROperand__setModifierBits(iVar3,2,0);
  }
  else {
    iVar3 = IRInst__create(local_5c,*compiler);
    *(undefined4 *)(iVar3 + 0x98) = 0;
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    loopIndex2 = IRInst__getOperandRecord(inst,0);
    *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(loopIndex2 + 0x10);
    uVar21 = IRInst__getOperandSource(inst,1);
    IRInst__setOperandSource(iVar3,1,uVar21,0,*compiler);
    uVar21 = IRInst__getOperandSource(inst,2);
    IRInst__setOperandSource(iVar3,2,uVar21,0,*compiler);
    loopIndex2 = IRInst__getOperandRecord(inst,1);
    uVar21 = *(undefined4 *)(loopIndex2 + 0x10);
    loopIndex2 = IRInst__getOperandRecord(iVar3,1);
    *(undefined4 *)(loopIndex2 + 0x10) = uVar21;
    loopIndex2 = IRInst__getOperandRecord(inst,2);
    uVar21 = *(undefined4 *)(loopIndex2 + 0x10);
    loopIndex2 = IRInst__getOperandRecord(iVar3,2);
    uVar2 = *(uint *)(inst + 0xb8);
    *(undefined4 *)(loopIndex2 + 0x10) = uVar21;
    IROperand__setModifierBits(iVar3 + 0xa4,1,uVar2 & 1);
    IROperand__setModifierBits(iVar3 + 0xbc,1,*(uint *)(inst + 0xd0) & 1);
    IROperand__setModifierBits(iVar3 + 0xa4,2,*(uint *)(inst + 0xb8) >> 1 & 1);
    IROperand__setModifierBits(iVar3 + 0xbc,2,*(uint *)(inst + 0xd0) >> 1 & 1);
    Block__insertInstBefore(param_2,inst,iVar3);
    IRInst__setOperandSource(inst,1,iVar3,0,*compiler);
    uVar21 = UNK_001b0208;
    iVar3 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    IROperand__setModifierBits(inst + 0xa4,1,0);
    IROperand__setModifierBits(inst + 0xa4,2,0);
    iVar3 = *(int *)(local_80 + 8);
    while (loopIndex2 = iVar3, loopIndex2 != 0) {
      DList__unlink(local_80);
      Block__insertInstBefore(param_2,inst,local_80);
      local_80 = loopIndex2;
      iVar3 = *(int *)(loopIndex2 + 8);
    }
    IRInst__setOperandSource(inst,2,*(undefined4 *)(inst + 4),0,*compiler);
    uVar21 = UNK_001b020c;
    iVar3 = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    IROperand__setModifierBits(inst + 0xbc,1,0);
    IROperand__setModifierBits(inst + 0xbc,2,0);
    FUN_000f35c4(inst);
  }
  if (puVar17 != (uint *)0x0) {
    Arena__free(vectorAlloc2[4],vectorAlloc2[3]);
    Arena__free(*vectorAlloc2,vectorAlloc2);
  }
  if (puVar18 != (uint *)0x0) {
    Arena__free(vectorAlloc[4],vectorAlloc[3]);
    Arena__free(*vectorAlloc,vectorAlloc);
  }
  if (puVar16 != (uint *)0x0) {
    Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
    Arena__free(*vectorAlloc3,vectorAlloc3);
  }
  return 1;
}

/* FUN_00183ac8 @ 0x183ac8 (212 bytes) */
int FUN_00183ac8(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint loopIndex;
  uint *puVar6;
  
  loopIndex = 0;
  puVar6 = *(uint **)(param_1 + 0x1c);
  uVar4 = puVar6[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (loopIndex < *puVar6) {
        uVar1 = puVar6[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + puVar6[2],0,(loopIndex - uVar1) * 4 + 4);
          puVar6[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + puVar6[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(puVar6,loopIndex);
      }
      loopIndex = loopIndex + 1;
      iVar3 = *piVar2;
      if (iVar3 != 0) {
        Arena__free(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (uVar4 == loopIndex) break;
      puVar6 = *(uint **)(param_1 + 0x1c);
    }
    puVar6 = *(uint **)(param_1 + 0x1c);
  }
  puVar6[1] = 0;
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
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int callResult;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int local_48;
  int local_44 [8];
  
  ((int (*)())FUN_00181ab0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
LAB_00183bcc:
  ((int (*)())FUN_00181b80)(param_1,param_2,&local_48,local_44,param_5,param_6,param_7);
  if ((local_48 < local_44[0]) &&
     (iVar1 = *(int *)(param_1 + 8),
     *(int *)(iVar1 + 0x14) < *(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10))) {
    iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
    iVar7 = *(int *)(param_2 + 0x98);
    if (iVar1 != 0) {
      do {
        iVar4 = iVar1;
        if ((*(uint *)(iVar7 + 0x14) & 1) != 0) {
          param_7 = *(int *)(iVar7 + 0x88);
          iVar1 = *(int *)(param_7 + 8);
          if ((iVar1 == 0x13) || (iVar1 == 0x14)) {
            iVar6 = 0x13;
          }
          else {
            iVar6 = 0x12;
            if (iVar1 != 0x12) goto LAB_00183fe8;
          }
          puVar9 = *(uint **)(param_1 + 0x1c);
          uVar8 = *(uint *)(iVar7 + 0x150);
          if (uVar8 < *puVar9) {
            uVar2 = puVar9[1];
            if (uVar2 <= uVar8) {
              _memset(uVar2 * 4 + puVar9[2],0,(uVar8 - uVar2) * 4 + 4);
              puVar9[1] = uVar8 + 1;
              param_7 = *(int *)(iVar7 + 0x88);
            }
            piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
          }
          else {
            piVar3 = (int *)Vector__elementRefGrow(puVar9,uVar8);
            param_7 = *(int *)(iVar7 + 0x88);
          }
          iVar1 = *piVar3;
          if ((((((iVar6 == *(int *)(param_7 + 8)) && (*(int *)(iVar7 + 0x120) == 0)) &&
                ((*(uint *)(iVar7 + 0x14) & 0x200) == 0)) &&
               (((iVar6 != 0x12 || (*(int *)(iVar7 + 0x124) == 0)) &&
                ((iVar4 = IRInst__getOperandRecord(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b021c &&
                 ((iVar4 = IRInst__getOperandRecord(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0218 &&
                  (iVar4 = IRInst__getOperandRecord(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0214)))))))) &&
              (iVar4 = IRInst__getOperandRecord(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0210)) &&
             ((((iVar4 = IRInst__hasSingleUse(iVar7,*(undefined4 *)(param_1 + 4)), iVar4 != 0 &&
                (iVar4 = *(int *)(iVar1 + 0xc), iVar4 != 0)) &&
               (iVar6 == *(int *)(*(int *)(iVar4 + 0x88) + 8))) &&
              ((iVar4 = FUN_000f31e8(iVar4,*(undefined4 *)(iVar1 + 0x10)), iVar4 != 0 &&
               ((iVar6 != 0x12 ||
                (param_7 = *(int *)(iVar1 + 0xc),
                (*(uint *)(*(int *)(iVar1 + 0x10) * 0x18 + param_7 + 0xa0) & 2) == 0)))))))) {
            *(undefined4 *)(iVar1 + 0x14) = 0;
          }
          iVar4 = IRInst__getOperandSource(iVar7,1);
          iVar6 = IRInst__getOperandSource(iVar7,2);
          callResult = IRInst__getOperandRecord(iVar7,1);
          callResult = FUN_000f2c5c(*(undefined4 *)(callResult + 0x10));
          if (callResult == 0) {
LAB_00183e40:
            callResult = IRInst__getOperandRecord(iVar7,1);
            callResult = FUN_000f2c5c(*(undefined4 *)(callResult + 0x10));
            if (callResult == 0) {
              callResult = IRInst__getOperandRecord(iVar7,2);
              callResult = FUN_000f2c5c(*(undefined4 *)(callResult + 0x10));
              if (callResult != 0) goto LAB_00183e78;
            }
          }
          else {
            callResult = IRInst__getOperandRecord(iVar7,2);
            callResult = FUN_000f2c5c(*(undefined4 *)(callResult + 0x10));
            if (callResult != 0) goto LAB_00183e40;
LAB_00183e78:
            *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
          }
          if (param_2 == *(int *)(iVar4 + 0x158)) {
            puVar9 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(iVar4 + 0x150);
            if (uVar8 < *puVar9) {
              uVar2 = puVar9[1];
              if (uVar2 <= uVar8) {
                _memset(uVar2 * 4 + puVar9[2],0,(uVar8 - uVar2) * 4 + 4);
                puVar9[1] = uVar8 + 1;
              }
              piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
            }
            else {
              piVar3 = (int *)Vector__elementRefGrow(puVar9,uVar8);
            }
            iVar4 = *piVar3;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (param_2 == *(int *)(iVar6 + 0x158)) {
            puVar9 = *(uint **)(param_1 + 0x1c);
            uVar8 = *(uint *)(iVar6 + 0x150);
            if (uVar8 < *puVar9) {
              uVar2 = puVar9[1];
              if (uVar2 <= uVar8) {
                _memset(uVar2 * 4 + puVar9[2],0,(uVar8 - uVar2) * 4 + 4);
                puVar9[1] = uVar8 + 1;
              }
              piVar3 = (int *)(uVar8 * 4 + puVar9[2]);
            }
            else {
              piVar3 = (int *)Vector__elementRefGrow(puVar9,uVar8);
            }
            iVar4 = *piVar3;
            if ((iVar4 != 0) && (*(int *)(iVar4 + 0x14) == 0)) {
              *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + *(int *)(iVar4 + 8);
            }
          }
          if (((*(int *)(iVar1 + 0x14) != 0) && (1 < *(int *)(iVar1 + 8))) &&
             (iVar1 = ((int (*)())FUN_00181f00)(param_1,param_2,iVar7), iVar1 != 0)) goto LAB_00183bcc;
          iVar4 = *(int *)(iVar7 + 8);
        }
LAB_00183fe8:
        iVar1 = *(int *)(iVar4 + 8);
        iVar7 = iVar4;
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
  undefined4 arenaAt378;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *vectorAlloc;
  char *extraout_r4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  uint loopIndex;
  
  param_1[1] = param_2;
  iVar3 = *(int *)(param_2 + 8);
  *param_1 = iVar3;
  iVar3 = FUN_0010ddcc(iVar3);
  param_1[2] = iVar3;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  vectorAlloc[1] = 2;
  *vectorAlloc = arenaAt378;
  vectorAlloc[2] = 0;
  vectorAlloc[4] = arenaAt378;
  uVar6 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar6;
  param_1[7] = (int)(vectorAlloc + 1);
  iVar3 = *(int *)(param_1[1] + 900);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != 0) {
    iVar1 = DList__count(iVar3 + 0x90);
    if (2 < iVar1) {
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
    iVar2 = *(int *)(*(int *)(iVar3 + 8) + iVar1);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      IRInst__getOperandRecord(iVar2,0);
      iVar3 = *(int *)(param_2 + 0x3c4);
    }
    iVar1 = iVar1 + 4;
  }
  return 1;
}

/* FUN_0018413c @ 0x18413c (224 bytes) */
int FUN_0018413c(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  undefined4 arenaAt378;
  uint uVar1;
  int *vectorAlloc2;
  undefined4 *vectorAlloc;
  undefined4 *vectorAlloc3;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int loopIndex;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  uint loopIndex2;
  
  loopIndex = *(int *)(*param_1 + 0x378);
  vectorAlloc2 = (int *)Arena__alloc(loopIndex,0x14);
  puVar8 = (uint *)(vectorAlloc2 + 1);
  *vectorAlloc2 = loopIndex;
  vectorAlloc2[1] = 2;
  vectorAlloc2[4] = loopIndex;
  vectorAlloc2[2] = 0;
  loopIndex = Arena__alloc(loopIndex,8);
  vectorAlloc2[3] = loopIndex;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  puVar10 = vectorAlloc + 1;
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar12 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar12;
  arenaAt378 = *(undefined4 *)(*param_1 + 0x378);
  vectorAlloc3 = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  puVar9 = vectorAlloc3 + 1;
  *vectorAlloc3 = arenaAt378;
  vectorAlloc3[1] = 2;
  vectorAlloc3[2] = 0;
  vectorAlloc3[4] = arenaAt378;
  uVar12 = Arena__alloc(arenaAt378,8);
  loopIndex2 = vectorAlloc2[2];
  uVar1 = *puVar8;
  vectorAlloc3[3] = uVar12;
  if (loopIndex2 < uVar1) {
    _memset((void *)(loopIndex2 * 4 + vectorAlloc2[3]),0,4);
    puVar5 = (undefined4 *)(loopIndex2 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = loopIndex2 + 1;
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(puVar8,loopIndex2);
  }
  *puVar5 = param_4;
  uVar1 = vectorAlloc[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + vectorAlloc[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + vectorAlloc[3]);
    vectorAlloc[2] = uVar1 + 1;
    goto code_r0x00184480;
  }
code_r0x00184474:
  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar1);
code_r0x00184480:
  *puVar5 = 1;
  do {
    uVar1 = vectorAlloc2[2];
    if (uVar1 == 0) {
      if (*puVar8 == 0) {
        puVar5 = (undefined4 *)Vector__elementRefGrow(puVar8,0);
      }
      else {
        _memset((void *)vectorAlloc2[3],0,4);
        puVar5 = (undefined4 *)vectorAlloc2[3];
        vectorAlloc2[2] = 1;
      }
      *puVar5 = param_4;
      uVar1 = vectorAlloc[2];
      if (uVar1 < *puVar10) {
        _memset((void *)(uVar1 * 4 + vectorAlloc[3]),0,4);
        puVar5 = (undefined4 *)(uVar1 * 4 + vectorAlloc[3]);
        vectorAlloc[2] = uVar1 + 1;
      }
      else {
        puVar5 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar1);
      }
      *puVar5 = 1;
      while (uVar1 = vectorAlloc2[2], uVar1 != 0) {
        puVar5 = (undefined4 *)0x0;
        if (uVar1 - 1 < uVar1) {
          puVar5 = (undefined4 *)((uVar1 - 1) * 4 + vectorAlloc2[3]);
        }
        piVar7 = (int *)*puVar5;
        loopIndex = ((int (*)())FUN_00181928)(piVar7,param_3,param_2);
        if ((loopIndex == 0) && (param_4 != piVar7)) {
          Vector__removeAt(puVar8,vectorAlloc2[2] + -1);
          Vector__removeAt(puVar10,vectorAlloc[2] + -1);
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
            Vector__removeAt(puVar8,vectorAlloc2[2] + -1);
            Vector__removeAt(puVar10,vectorAlloc[2] + -1);
            if (param_4 != piVar7) {
              DList__unlink(piVar7);
              Block__insertInstBefore(param_3,param_4,piVar7);
            }
          }
          else {
            uVar1 = (**(code **)(*piVar7 + 0x14))(piVar7);
            if (0 < (int)uVar1) {
              loopIndex = 1;
              do {
                uVar12 = IRInst__getOperandSource(piVar7,loopIndex);
                loopIndex2 = vectorAlloc3[2];
                if (loopIndex2 < *puVar9) {
                  _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
                  puVar5 = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                  vectorAlloc3[2] = loopIndex2 + 1;
                }
                else {
                  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex2);
                }
                loopIndex = loopIndex + 1;
                *puVar5 = uVar12;
              } while (loopIndex <= (int)uVar1);
            }
            FUN_001940f0(puVar9,FUN_001819b4);
            Vector__removeAt(puVar10,vectorAlloc[2] + -1);
            loopIndex2 = vectorAlloc[2];
            if (loopIndex2 < *puVar10) {
              _memset((void *)(loopIndex2 * 4 + vectorAlloc[3]),0,4);
              piVar7 = (int *)(loopIndex2 * 4 + vectorAlloc[3]);
              vectorAlloc[2] = loopIndex2 + 1;
            }
            else {
              piVar7 = (int *)Vector__elementRefGrow(puVar10,loopIndex2);
            }
            *piVar7 = uVar1 + 1;
            if (0 < (int)uVar1) {
              loopIndex2 = 0;
              do {
                if (loopIndex2 < *puVar9) {
                  uVar6 = vectorAlloc3[2];
                  if (uVar6 <= loopIndex2) {
                    _memset((void *)(uVar6 * 4 + vectorAlloc3[3]),0,(loopIndex2 - uVar6) * 4 + 4);
                    vectorAlloc3[2] = loopIndex2 + 1;
                  }
                  puVar5 = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
                }
                else {
                  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex2);
                }
                loopIndex2 = loopIndex2 + 1;
                uVar6 = vectorAlloc2[2];
                uVar12 = *puVar5;
                if (uVar6 < *puVar8) {
                  _memset((void *)(uVar6 * 4 + vectorAlloc2[3]),0,4);
                  puVar5 = (undefined4 *)(uVar6 * 4 + vectorAlloc2[3]);
                  vectorAlloc2[2] = uVar6 + 1;
                }
                else {
                  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar6);
                }
                *puVar5 = uVar12;
                uVar6 = vectorAlloc[2];
                if (uVar6 < *puVar10) {
                  _memset((void *)(uVar6 * 4 + vectorAlloc[3]),0,4);
                  puVar5 = (undefined4 *)(uVar6 * 4 + vectorAlloc[3]);
                  vectorAlloc[2] = uVar6 + 1;
                }
                else {
                  puVar5 = (undefined4 *)Vector__elementRefGrow(puVar10,uVar6);
                }
                *puVar5 = 1;
              } while (uVar1 != loopIndex2);
            }
            vectorAlloc3[2] = 0;
          }
        }
      }
      if (puVar9 != (uint *)0x0) {
        Arena__free(vectorAlloc3[4],vectorAlloc3[3]);
        Arena__free(*vectorAlloc3,vectorAlloc3);
      }
      if (puVar10 != (uint *)0x0) {
        Arena__free(vectorAlloc[4],vectorAlloc[3]);
        Arena__free(*vectorAlloc,vectorAlloc);
      }
      if (puVar8 == (uint *)0x0) {
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
    if (uVar1 - 1 < uVar1) {
      puVar5 = (undefined4 *)((uVar1 - 1) * 4 + vectorAlloc2[3]);
    }
    piVar14 = (int *)*puVar5;
    uVar1 = vectorAlloc[2] - 1;
    piVar7 = (int *)0x0;
    if (uVar1 < (uint)vectorAlloc[2]) {
      piVar7 = (int *)(uVar1 * 4 + vectorAlloc[3]);
    }
    iVar13 = *piVar7;
    loopIndex = ((int (*)())FUN_00181928)(piVar14,param_3,param_2);
    if ((loopIndex == 0) && (param_4 != piVar14)) {
      piVar14[0x54] = 0;
    }
    else {
      loopIndex = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (iVar13 <= loopIndex) break;
      uVar1 = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (0 < (int)uVar1) {
        loopIndex = 1;
        do {
          uVar12 = IRInst__getOperandSource(piVar14,loopIndex);
          loopIndex2 = vectorAlloc3[2];
          if (loopIndex2 < *puVar9) {
            _memset((void *)(loopIndex2 * 4 + vectorAlloc3[3]),0,4);
            puVar5 = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
            vectorAlloc3[2] = loopIndex2 + 1;
          }
          else {
            puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex2);
          }
          loopIndex = loopIndex + 1;
          *puVar5 = uVar12;
        } while (loopIndex <= (int)uVar1);
      }
      FUN_001940f0(puVar9,FUN_001819b4);
      if (0 < (int)uVar1) {
        loopIndex2 = 0;
        loopIndex = 0;
        do {
          if (loopIndex2 < *puVar9) {
            uVar6 = vectorAlloc3[2];
            if (uVar6 <= loopIndex2) {
              _memset((void *)(uVar6 * 4 + vectorAlloc3[3]),0,(loopIndex2 - uVar6) * 4 + 4);
              vectorAlloc3[2] = loopIndex2 + 1;
            }
            puVar5 = (undefined4 *)(loopIndex2 * 4 + vectorAlloc3[3]);
          }
          else {
            puVar5 = (undefined4 *)Vector__elementRefGrow(puVar9,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          piVar7 = (int *)*puVar5;
          if ((((piVar7[0x20] == 0) || (iVar13 = FUN_00126760(piVar7[0x26]), iVar13 == 0)) ||
              ((piVar7[5] & 2U) != 0)) ||
             (iVar13 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar13 != 0)) {
            iVar13 = 0;
          }
          else {
            iVar13 = FUN_000f3a30(piVar7);
          }
          loopIndex = loopIndex + iVar13;
          if (loopIndex <= piVar7[0x54]) {
            loopIndex = piVar7[0x54];
          }
        } while (uVar1 != loopIndex2);
      }
      else {
        loopIndex = 0;
      }
      vectorAlloc3[2] = 0;
      piVar14[0x54] = loopIndex;
    }
    Vector__removeAt(puVar8,vectorAlloc2[2] + -1);
    Vector__removeAt(puVar10,vectorAlloc[2] + -1);
  } while( true );
  uVar12 = IRInst__getOperandSource(piVar14,iVar13);
  uVar1 = vectorAlloc2[2];
  if (uVar1 < *puVar8) {
    _memset((void *)(uVar1 * 4 + vectorAlloc2[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + vectorAlloc2[3]);
    vectorAlloc2[2] = uVar1 + 1;
  }
  else {
    puVar5 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar1);
  }
  *puVar5 = uVar12;
  Vector__removeAt(puVar10,vectorAlloc[2] + -1);
  uVar1 = vectorAlloc[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + vectorAlloc[3]),0,4);
    piVar7 = (int *)(uVar1 * 4 + vectorAlloc[3]);
    vectorAlloc[2] = uVar1 + 1;
  }
  else {
    piVar7 = (int *)Vector__elementRefGrow(puVar10,uVar1);
  }
  *piVar7 = iVar13 + 1;
  uVar1 = vectorAlloc[2];
  if (*puVar10 <= uVar1) goto code_r0x00184474;
  _memset((void *)(uVar1 * 4 + vectorAlloc[3]),0,4);
  puVar5 = (undefined4 *)(uVar1 * 4 + vectorAlloc[3]);
  vectorAlloc[2] = uVar1 + 1;
  goto code_r0x00184480;
}

/* pass_minreg_order @ 0x184ab4 (280 bytes) */
int pass_minreg_order(param_1, program)
  undefined4 param_1;
  int program;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = *(int *)(program + 900);
  for (iVar2 = *(int *)(*(int *)(program + 900) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    piVar3 = (int *)(*(int **)(iVar1 + 0xa0))[1];
    piVar5 = *(int **)(iVar1 + 0xa0);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        iVar2 = (**(code **)(*piVar5 + 0x34))(piVar5);
        if ((((iVar2 == 0) && (iVar2 = (**(code **)(*piVar5 + 0x38))(piVar5), iVar2 == 0)) &&
            (iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5), 0 < iVar2)) &&
           (iVar2 = ((int (*)())FUN_00181928)(piVar5,iVar1,program), iVar2 == 0)) {
          ((int (*)())FUN_0018413c)(param_1,program,iVar1,piVar5);
        }
        piVar3 = (int *)piVar4[1];
        piVar5 = piVar4;
      } while (piVar3 != (int *)0x0);
      iVar2 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar2;
  }
  return FUN_000ed7e4(program,(int)"minreg_order");
}

/* FUN_00184bcc @ 0x184bcc (36 bytes) */
int FUN_00184bcc(param_1, param_2)
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
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int callResult;
  uint loopIndex;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = *(uint **)(param_1 + 0x10);
  uVar1 = puVar8[1];
  uVar7 = uVar1 - 1;
  if (-1 < (int)uVar7) {
    iVar6 = uVar7 * 4;
    loopIndex = 0;
    while( true ) {
      if (uVar7 < *puVar8) {
        uVar2 = puVar8[1];
        if (uVar2 <= uVar7) {
          _memset(uVar2 * 4 + puVar8[2],0,(uVar7 - uVar2) * 4 + 4);
          puVar8[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(iVar6 + puVar8[2]);
      }
      else {
        puVar3 = (undefined4 *)Vector__elementRefGrow(puVar8,uVar7);
      }
      callResult = (**(code **)(*(int *)*puVar3 + 0x24))((int *)*puVar3);
      if (callResult == 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
      uVar7 = uVar7 - 1;
      iVar6 = iVar6 + -4;
      if (uVar1 == loopIndex) break;
      puVar8 = *(uint **)(param_1 + 0x10);
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

/* FUN_00184d7c @ 0x184d7c (372 bytes) */
int FUN_00184d7c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int callResult;
  uint loopIndex;
  uint *puVar5;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    puVar5 = *(uint **)(param_1 + 0x10);
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar5) {
          if (uVar1 <= loopIndex) {
            _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
            puVar5[1] = loopIndex + 1;
          }
          puVar2 = (undefined4 *)(loopIndex * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)Vector__elementRefGrow(puVar5,loopIndex);
        }
        callResult = FUN_001470dc(*puVar2,param_2,0);
        if (callResult == 0) {
          return;
        }
        puVar5 = *(uint **)(param_1 + 0x10);
        loopIndex = loopIndex + 1;
        uVar1 = puVar5[1];
      } while ((int)loopIndex < (int)uVar1);
    }
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      loopIndex = 0;
      do {
        if (loopIndex < *puVar5) {
          if (uVar1 <= loopIndex) {
            _memset(uVar1 * 4 + puVar5[2],0,(loopIndex - uVar1) * 4 + 4);
            puVar5[1] = loopIndex + 1;
          }
          puVar2 = (undefined4 *)(loopIndex * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)Vector__elementRefGrow(puVar5,loopIndex);
        }
        loopIndex = loopIndex + 1;
        FUN_0014b82c(*puVar2,param_2,1,0);
        puVar5 = *(uint **)(param_1 + 0x10);
        uVar1 = puVar5[1];
      } while ((int)loopIndex < (int)uVar1);
    }
  }
  return;
}

/* FUN_00184ef0 @ 0x184ef0 (2440 bytes) */
int FUN_00184ef0(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  int param_3;
{
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
  int iVar16;
  int iVar17;
  uint loopIndex2;
  uint *loopIndex;
  uint *puVar20;
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
  int local_78;
  int local_74;
  int local_70;
  
  loopRemaining2 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_3);
  if ((((loopRemaining2 == 0) ||
       (piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
       loopRemaining2 = (**(code **)(*piVar5 + 0xfc))(piVar5,param_2 + param_1[0x49],0), loopRemaining2 == 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((param_1[0x48] != 0 || (loopRemaining2 = (**(code **)(*param_1 + 0x5c))(param_1), loopRemaining2 != 0)))) {
LAB_00185098:
    uVar8 = 0;
  }
  else {
    FUN_001940f0(param_1[4],FUN_00184bcc);
    loopIndex = (uint *)param_1[4];
    uVar6 = loopIndex[1];
    if (0 < (int)uVar6) {
      loopIndex2 = 0;
      do {
        if (loopIndex2 < *loopIndex) {
          if (uVar6 <= loopIndex2) {
            _memset(uVar6 * 4 + loopIndex[2],0,(loopIndex2 - uVar6) * 4 + 4);
            loopIndex[1] = loopIndex2 + 1;
          }
          puVar7 = (undefined4 *)(loopIndex2 * 4 + loopIndex[2]);
        }
        else {
          puVar7 = (undefined4 *)Vector__elementRefGrow(loopIndex,loopIndex2);
        }
        piVar5 = (int *)*puVar7;
        if ((((piVar5[5] & 0x200U) != 0) ||
            (loopRemaining2 = (**(code **)(*piVar5 + 0x28))(piVar5), loopRemaining2 != 0)) ||
           (loopRemaining2 = (**(code **)(*piVar5 + 0x5c))(piVar5), loopRemaining2 != 0)) goto LAB_00185098;
        loopRemaining2 = *(int *)(piVar5[0x22] + 8);
        if (loopRemaining2 == 0x31) {
LAB_001850bc:
          if ((((piVar5[0x21] != 2) || (piVar9 = (int *)IRInst__getOperandSource(piVar5,1), param_1 != piVar9))
              || (piVar9 = (int *)IRInst__getOperandSource(piVar5,2), param_1 != piVar9)) ||
             (piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
             loopRemaining2 = (**(code **)(*piVar9 + 0xfc))(piVar9,piVar5[0x49] + param_2 * -2,0), loopRemaining2 == 0
             )) {
LAB_001851b4:
            piVar9 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            loopRemaining2 = (**(code **)(*piVar9 + 0xfc))(piVar9,piVar5[0x49] - param_2,0);
            goto joined_r0x001851e0;
          }
        }
        else {
          if (0x31 < loopRemaining2) {
            if ((loopRemaining2 == 0x36) || (loopRemaining2 == 0x66)) goto LAB_001850bc;
            if (loopRemaining2 == 0x34) {
LAB_00185124:
              piVar9 = (int *)IRInst__getOperandSource(piVar5,1);
              if ((param_1 != piVar9) || (piVar9 = (int *)IRInst__getOperandSource(piVar5,2), param_1 != piVar9)
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
                loopIndex = &local_f4;
                do {
                  *loopIndex = 0x7ffffffe;
                  loopIndex = loopIndex + 1;
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
          loopRemaining2 = IRInst__getOperandRecord(piVar5,0);
          loopRemaining2 = FUN_000f5cf0(piVar5,2,*(undefined4 *)(loopRemaining2 + 0x10),&local_e4);
          fVar2 = local_e0;
          if (((loopRemaining2 == 0) || (local_e4 != 2)) ||
             (piVar5 = (int *)IRInst__getOperandSource(piVar5,1), param_1 != piVar5)) goto LAB_00185098;
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
          loopIndex = &local_f4;
          do {
            *loopIndex = 0x7ffffffe;
            loopIndex = loopIndex + 1;
          } while (&local_e4 != loopIndex);
          loopRemaining2 = 0;
          loopRemaining = 4;
          do {
            *(float *)(loopRemaining2 + (int)&local_f4) = fVar2 * fVar1;
            loopRemaining2 = loopRemaining2 + 4;
            loopRemaining = loopRemaining + -1;
          } while (loopRemaining != 0);
LAB_0018533c:
          piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          loopRemaining2 = (**(code **)(*piVar5 + 0xe8))
                            (piVar5,&local_f4,auStack_f8,0x10203,*(int *)(param_3 + 8));
joined_r0x001851e0:
          if (loopRemaining2 == 0) goto LAB_00185098;
        }
        loopIndex = (uint *)param_1[4];
        loopIndex2 = loopIndex2 + 1;
        uVar6 = loopIndex[1];
      } while ((int)loopIndex2 < (int)uVar6);
    }
    uVar6 = uVar6 - 1;
    if (-1 < (int)uVar6) {
      local_70 = param_2 << 1;
      do {
        if (0 < (int)uVar6) {
          loopIndex2 = uVar6 - 1;
          if (loopIndex2 < *loopIndex) {
            uVar3 = loopIndex[1];
            puVar20 = loopIndex;
            if (uVar3 <= loopIndex2) {
              _memset(uVar3 * 4 + loopIndex[2],0,(loopIndex2 - uVar3) * 4 + 4);
              loopIndex[1] = uVar6;
              puVar20 = (uint *)param_1[4];
            }
            piVar5 = (int *)(loopIndex2 * 4 + loopIndex[2]);
          }
          else {
            piVar5 = (int *)Vector__elementRefGrow(loopIndex,loopIndex2);
            puVar20 = (uint *)param_1[4];
          }
          loopRemaining2 = *piVar5;
          if (uVar6 < *puVar20) {
            loopIndex2 = puVar20[1];
            if (loopIndex2 <= uVar6) {
              _memset(loopIndex2 * 4 + puVar20[2],0,(uVar6 - loopIndex2) * 4 + 4);
              puVar20[1] = uVar6 + 1;
            }
            piVar5 = (int *)(uVar6 * 4 + puVar20[2]);
          }
          else {
            piVar5 = (int *)Vector__elementRefGrow(puVar20,uVar6);
          }
          if (loopRemaining2 != *piVar5) {
            loopIndex = (uint *)param_1[4];
            goto LAB_0018545c;
          }
          goto LAB_00185964;
        }
LAB_0018545c:
        if (uVar6 < *loopIndex) {
          loopIndex2 = loopIndex[1];
          if (loopIndex2 <= uVar6) {
            _memset(loopIndex2 * 4 + loopIndex[2],0,(uVar6 - loopIndex2) * 4 + 4);
            loopIndex[1] = uVar6 + 1;
          }
          puVar7 = (undefined4 *)(uVar6 * 4 + loopIndex[2]);
        }
        else {
          puVar7 = (undefined4 *)Vector__elementRefGrow(loopIndex,uVar6);
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
                FUN_000f5cf0(piVar5,2,*(undefined4 *)(loopRemaining2 + 0x10),&local_e4);
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
                ((void (*)())FUN_000f79c4)(piVar5,param_3,2,dVar22,dVar22,dVar22,dVar22);
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
              local_74 = piVar5[1];
              local_78 = piVar5[0x56];
              DList__unlink(piVar5);
              loopRemaining2 = IRInst__getOperandRecord(piVar5,0);
              local_84 = *(int *)(loopRemaining2 + 0x10);
              local_7c = piVar5[0x49];
              local_80 = piVar5[0x48];
              loopRemaining2 = IRInst__useCount(piVar5,param_3);
              loopRemaining = piVar5[4];
              piVar9 = (int *)IRInst__getOperandSource(piVar5,1);
              if (param_1 == piVar9) {
                iVar17 = 1;
                iVar16 = 2;
              }
              else {
                IRInst__getOperandSource(piVar5,2);
                iVar17 = 2;
                iVar16 = 1;
              }
              iVar13 = piVar5[iVar17 * 6 + 0x26];
              iVar12 = piVar5[iVar17 * 6 + 0x25];
              iVar10 = IRInst__getOperandRecord(piVar5,iVar17);
              loopIndex2 = piVar5[iVar17 * 6 + 0x28];
              uVar15 = *(undefined4 *)(iVar10 + 0x10);
              uVar8 = IRInst__getOperandSource(piVar5,iVar17);
              iVar14 = piVar5[iVar16 * 6 + 0x26];
              iVar10 = piVar5[iVar16 * 6 + 0x25];
              iVar17 = IRInst__getOperandRecord(piVar5,iVar16);
              local_88 = *(undefined4 *)(iVar17 + 0x10);
              uVar3 = piVar5[iVar16 * 6 + 0x28];
              operandVReg = IRInst__getOperandSource(piVar5,iVar16);
              (**(code **)(*piVar5 + 0xc))(piVar5,1,*(undefined4 *)(param_3 + 8));
              FUN_00108304(piVar5,0x14,*(undefined4 *)(param_3 + 8));
              piVar5[4] = loopRemaining;
              piVar5[0x25] = piVar5[0x53];
              piVar5[0x26] = 0;
              piVar5[0x27] = local_84;
              piVar5[0x48] = local_80;
              piVar5[0x49] = local_7c;
              piVar5[0x58] = loopRemaining2 + *(int *)(param_3 + 0x478);
              IRInst__setOperandSource(piVar5,1,uVar8,1,*(undefined4 *)(param_3 + 8));
              loopRemaining2 = IRInst__getOperandRecord(piVar5,1);
              *(int *)(loopRemaining2 + 0xc) = iVar13;
              *(int *)(loopRemaining2 + 8) = iVar12;
              loopRemaining2 = IRInst__getOperandRecord(piVar5,1);
              *(undefined4 *)(loopRemaining2 + 0x10) = uVar15;
              IROperand__setModifierBits(piVar5 + 0x29,2,loopIndex2 >> 1 & 1);
              IROperand__setModifierBits(piVar5 + 0x29,1,loopIndex2 & 1);
              IRInst__setOperandSource(piVar5,3,operandVReg,1,*(undefined4 *)(param_3 + 8));
              loopRemaining2 = IRInst__getOperandRecord(piVar5,3);
              *(int *)(loopRemaining2 + 0xc) = iVar14;
              *(int *)(loopRemaining2 + 8) = iVar10;
              loopRemaining2 = IRInst__getOperandRecord(piVar5,3);
              *(undefined4 *)(loopRemaining2 + 0x10) = local_88;
              IROperand__setModifierBits(piVar5 + 0x35,2,uVar3 >> 1 & 1);
              IROperand__setModifierBits(piVar5 + 0x35,1,uVar3 & 1);
              ((void (*)())FUN_000f79c4)(piVar5,param_3,2,dVar22,dVar22,dVar22,dVar22);
              Block__insertInstAfter(local_78,local_74,piVar5);
              goto LAB_00185964;
            }
            goto LAB_00185628;
          }
        }
LAB_00185964:
        uVar6 = uVar6 - 1;
        if ((int)uVar6 < 0) break;
        loopIndex = (uint *)param_1[4];
      } while( true );
    }
    uVar8 = 1;
    param_1[0x49] = param_2 + param_1[0x49];
  }
  return uVar8;
}

/* FUN_001859bc @ 0x1859bc (640 bytes) */
int FUN_001859bc(inst, param_2, param_3)
  int inst;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  int callResult;
  int *piVar4;
  int *operandVReg;
  undefined4 operandVReg2;
  undefined4 uVar7;
  undefined4 block;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 local_78;
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  
  callResult = IRInst__getOperandRecord(inst,1);
  uVar14 = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,2);
  uVar13 = *(undefined4 *)(callResult + 0x10);
  callResult = IRInst__getOperandRecord(inst,0);
  uVar12 = *(undefined4 *)(callResult + 0x10);
  if (((*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) &&
      (callResult = FUN_000f2c5c(uVar14), callResult != 0)) && (callResult = FUN_000f2c5c(uVar13), callResult != 0)) {
    piVar4 = (int *)IRInst__getOperandSource(inst,1);
    operandVReg = (int *)IRInst__getOperandSource(inst,2);
    if (((*(int *)(piVar4[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(piVar4,param_2), callResult != 0))
       && (((*(uint *)(inst + 0xb8) & 1) == 0 && ((*(uint *)(inst + 0xb8) & 2) == 0)))) {
      callResult = FUN_00146788(piVar4,param_2);
      iVar9 = 2;
      if (callResult != 0) goto LAB_00185afc;
    }
    if (((*(int *)(operandVReg[0x22] + 8) == 0x1c) && (callResult = IRInst__hasSingleUse(operandVReg,param_2), callResult != 0))
       && (((*(uint *)(inst + 0xd0) & 1) == 0 &&
           (((*(uint *)(inst + 0xd0) & 2) == 0 &&
            (callResult = FUN_00146788(operandVReg,param_2), callResult != 0)))))) {
      iVar9 = 1;
      piVar4 = operandVReg;
      uVar13 = uVar14;
LAB_00185afc:
      local_74 = IRInst__getOperandSource(inst,iVar9);
      uVar1 = *(uint *)(iVar9 * 0x18 + inst + 0xa0);
      iVar15 = 0;
      local_70 = uVar1 & 1;
      local_6c = uVar1 >> 1 & 1;
      callResult = IRInst__getOperandRecord(inst,iVar9);
      local_60 = *(undefined4 *)(callResult + 0x10);
      uVar14 = IRInst__getOperandSource(piVar4,1);
      uVar1 = piVar4[0x2e];
      callResult = IRInst__getOperandRecord(piVar4,1);
      local_64 = *(undefined4 *)(callResult + 0x10);
      operandVReg2 = IRInst__getOperandSource(piVar4,2);
      uVar2 = piVar4[0x34];
      callResult = IRInst__getOperandRecord(piVar4,2);
      local_68 = *(undefined4 *)(callResult + 0x10);
      uVar7 = *(undefined4 *)(inst + 4);
      block = *(undefined4 *)(inst + 0x158);
      callResult = IRInst__useCount(inst,param_2);
      uVar10 = *(undefined4 *)(inst + 0x120);
      uVar11 = *(undefined4 *)(inst + 0x124);
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        iVar15 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      DList__unlink(inst);
      FUN_00108304(inst,0xa3,param_3);
      *(undefined4 *)(inst + 0x98) = 0;
      *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
      *(undefined4 *)(inst + 0x9c) = uVar12;
      *(undefined4 *)(inst + 0x120) = uVar10;
      *(undefined4 *)(inst + 0x124) = uVar11;
      *(int *)(inst + 0x160) = callResult + *(int *)(param_2 + 0x478);
      if (iVar15 != 0) {
        IRInst__setExtraOperandSource(inst,iVar15,0,param_3);
      }
      Block__insertInstAfter(block,uVar7,inst);
      IRInst__setOperandSource(inst,1,uVar14,0,*(undefined4 *)(param_2 + 8));
      IROperand__setModifierBits(inst + 0xa4,1,uVar1 & 1);
      IROperand__setModifierBits(inst + 0xa4,2,uVar1 >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(callResult + 0x10) = local_64;
      IRInst__setOperandSource(inst,2,operandVReg2,0,*(undefined4 *)(param_2 + 8));
      IROperand__setModifierBits(inst + 0xbc,1,uVar2 & 1);
      IROperand__setModifierBits(inst + 0xbc,2,uVar2 >> 1 & 1);
      callResult = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(callResult + 0x10) = local_68;
      IRInst__setOperandSource(inst,3,local_74,0,*(undefined4 *)(param_2 + 8));
      IROperand__setModifierBits(inst + 0xd4,1,local_70);
      IROperand__setModifierBits(inst + 0xd4,2,local_6c);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = local_60;
      FUN_000f33f8(&local_78,uVar13);
      callResult = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(callResult + 0x10) = local_78;
                    
                    
      (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_2 + 8));
      return;
    }
  }
  return;
}

/* FUN_00185da4 @ 0x185da4 (1900 bytes) */
int FUN_00185da4(param_1, param_2, inst, inst2, inst3, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int *inst;
  int *inst2;
  int *inst3;
  int param_6;
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
  loopIndex = IRInst__getOperandRecord(inst,param_1);
  uVar7 = *(undefined4 *)(loopIndex + 0x10);
  FUN_000f2bdc(&local_58,uVar8,uVar7);
  local_68 = local_58;
  piVar4 = *(int **)(*(int *)(param_6 + 8) + 0x30c);
  loopIndex = (**(code **)(*piVar4 + 0x108))(piVar4,&local_68);
  if (loopIndex == 0) {
    *(int *)(param_6 + 0x20c) = *(int *)(param_6 + 0x20c) + 1;
    return 0;
  }
  if ((param_2 == 0) || ((inst[param_1 * 6 + 0x28] & 2U) != 0)) {
LAB_00185ea8:
    if (param_7 == 0) goto LAB_00185f24;
  }
  else {
    if ((*(int *)(inst2[0x22] + 8) == 0x9a) && (inst2[0x2c] == inst2[0x32])) {
      FUN_0010ac38(inst2,1,2,*(uint *)(param_6 + 8));
      param_2 = 0;
      goto LAB_00185ea8;
    }
    if (param_7 == 0) goto LAB_00185f24;
    loopIndex = (**(code **)(*inst + 0x60))(inst);
    if (loopIndex != 0) {
      return 0;
    }
    IROperand__setModifierBits(inst + param_1 * 6 + 0x23,1,inst[param_1 * 6 + 0x28] & 1U ^ 1);
  }
  uVar8 = local_68;
  loopIndex = IRInst__getOperandRecord(inst,param_1);
  *(undefined4 *)(loopIndex + 0x10) = uVar8;
  IRInst__setOperandSource(inst,param_1,inst2,0,*(undefined4 *)(param_6 + 8));
LAB_00185f24:
  bVar2 = param_7 != 0;
  FUN_000f32cc(&local_54,local_68);
  inst2[0x27] = local_54;
  if ((param_8 != 0) && (loopIndex = FUN_0018da48(inst,*(undefined4 *)(param_6 + 8)), loopIndex == 0)) {
    loopIndex = 0;
    for (loopIndex2 = 1; loopRemaining = (**(code **)(*inst + 0x14))(inst), loopIndex2 <= loopRemaining;
        loopIndex2 = loopIndex2 + 1) {
      loopRemaining = FUN_000f3b10(inst,loopIndex2);
      if (loopRemaining != 0) {
        loopRemaining = loopIndex + 1;
        loopIndex = loopIndex + 2;
        if (loopIndex2 != param_1) {
          loopIndex = loopRemaining;
        }
      }
      FUN_000f3b68(inst,loopIndex2);
    }
    if (3 < loopIndex) {
      for (loopIndex = 1; loopIndex2 = (**(code **)(*inst + 0x14))(inst), loopIndex <= loopIndex2;
          loopIndex = loopIndex + 1) {
        if (param_1 == loopIndex) {
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
          loopIndex2 = FUN_000f2c5c(local_64[0]);
          if (loopIndex2 != 0) {
            loopIndex2 = FUN_0011379c(*(undefined4 *)(param_6 + 8),operandVReg);
            if ((loopIndex2 == 0) || (loopIndex2 = IRInst__hasSingleUse(operandVReg,param_6), loopIndex2 == 0)) {
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
            loopIndex2 = FUN_001131c0(*(undefined4 *)(operandVReg[0x22] + 8),*(undefined4 *)(param_6 + 8));
            if (loopIndex2 != 0) {
              loopIndex2 = IRInst__hasSingleUse(operandVReg,param_6);
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
              if (loopIndex == param_1) {
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
  loopIndex = FUN_0018da48(inst,*(undefined4 *)(param_6 + 8));
  if ((loopIndex == 0) && (param_8 != 0)) {
    if (bVar2) {
      if (param_10 == 0) {
        IRInst__setOperandSource(inst,param_1,inst3,0,*(undefined4 *)(param_6 + 8));
      }
      else {
        IRInst__setOperandSource(inst,param_1,param_10,0,*(undefined4 *)(param_6 + 8));
      }
      loopIndex = IRInst__getOperandRecord(inst,param_1);
      *(undefined4 *)(loopIndex + 0x10) = uVar7;
      if ((param_2 != 0) && ((inst[param_1 * 6 + 0x28] & 2U) == 0)) {
        IROperand__setModifierBits(inst + param_1 * 6 + 0x23,1,inst[param_1 * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (param_10 == 0) {
      inst3[0x54] = *(int *)(param_6 + 0x474) + -1;
    }
    else {
      *(int *)(param_10 + 0x150) = *(int *)(param_6 + 0x474) + -1;
    }
    uVar7 = 0;
    *(int *)(param_6 + 0x208) = *(int *)(param_6 + 0x208) + 1;
  }
  else {
    if (bVar2) {
      *(int *)(param_6 + 0x200) = *(int *)(param_6 + 0x200) + 1;
      Block__insertInstBefore(inst[0x56],inst,inst2);
      inst2[0x58] = *(int *)(param_6 + 0x478) + 1;
    }
    loopIndex = IRInst__getOperandRecord(inst2,0);
    FUN_000f3908(&local_50,*(undefined4 *)(loopIndex + 0x10));
    FUN_000f3340(local_4c,0x10203,local_50);
    if (0 < inst2[0x21]) {
      loopIndex = 1;
      do {
        if (bVar2) {
          loopIndex2 = IRInst__getOperandSource(inst2,loopIndex);
          if (*(int *)(param_6 + 0x478) < *(int *)(loopIndex2 + 0x160)) {
            *(int *)(loopIndex2 + 0x160) = *(int *)(loopIndex2 + 0x160) + 1;
          }
          else {
            *(int *)(loopIndex2 + 0x160) = *(int *)(param_6 + 0x478) + 1;
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
        FUN_00105894(inst3,*(undefined4 *)(param_6 + 8));
      }
      else {
        *(uint *)(param_10 + 0x14) = *(uint *)(param_10 + 0x14) | 0x40000;
        FUN_00105894(param_10,*(undefined4 *)(param_6 + 8));
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

