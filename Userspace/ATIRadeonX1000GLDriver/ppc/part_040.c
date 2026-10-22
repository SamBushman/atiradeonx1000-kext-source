#include "decls.h"

/* FUN_0012b35c @ 0x12b35c (156 bytes) */
int FUN_0012b35c(param_1, inst)
  undefined4 *param_1;
  undefined4 inst;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int operandRecord;
  
  iVar2 = FUN_000f3a30(inst);
  uVar3 = 0;
  if (iVar2 == 1) {
    param_1[0xd] = inst;
    param_1[0xe] = 0xffffffff;
    iVar2 = 0;
    do {
      operandRecord = FUN_001054ec(inst,0);
      if (*(char *)(iVar2 + operandRecord + 0x10) != '\x01') {
        param_1[0xe] = iVar2;
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    iVar2 = FUN_00104054(inst,param_1[0x10]);
    uVar3 = 1;
    if (iVar2 != 2) {
      *param_1 = 1;
    }
  }
  return uVar3;
}

/* FUN_0012b3f8 @ 0x12b3f8 (272 bytes) */
int FUN_0012b3f8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  
  switch(*(undefined4 *)(param_1 + 300)) {
  case 0:
    FUN_00103d50(param_2 + 0xa4,2,1);
    uVar1 = *(uint *)(param_2 + 0xb8);
    goto LAB_0012b4b0;
  case 1:
    FUN_00103d50(param_2 + 0xa4,2,1);
    FUN_00103d50(param_2 + 0xa4,1,*(uint *)(param_2 + 0xb8) & 1 ^ 1);
    break;
  case 2:
    FUN_00103d50(param_2 + 0xa4,1,*(uint *)(param_2 + 0xb8) & 1 ^ 1);
    break;
  default:
    return;
  case 4:
    break;
  case 5:
    uVar1 = *(uint *)(param_2 + 0xb8);
LAB_0012b4b0:
    FUN_00103d50(param_2 + 0xa4,1,uVar1 & 1 ^ 1);
    return;
  }
  FUN_0010ac38(param_2,2,3,param_3);
  return;
}

/* FUN_0012b520 @ 0x12b520 (192 bytes) */
int FUN_0012b520(param_1)
  int param_1;
{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint loopIndex;
  int iVar8;
  int iVar9;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  iVar6 = *(int *)(param_1 + 0x3a0);
  do {
    iVar9 = *(int *)(*(int *)(param_1 + 900) + 8);
    if (iVar9 == 0) {
      return;
    }
    bVar2 = false;
    iVar8 = *(int *)(param_1 + 900);
    do {
      if ((iVar6 != iVar8) && (iVar5 = FUN_000e79dc(iVar8), iVar5 == 0)) {
        iVar5 = 0;
        for (loopIndex = 1; loopIndex <= *(uint *)(*(int *)(iVar8 + 0xd0) + 4); loopIndex = loopIndex + 1) {
          iVar4 = *(int *)(iVar5 + *(int *)(*(int *)(iVar8 + 0xd0) + 8));
          if (iVar4 != 0) {
            puVar3 = *(undefined4 **)(iVar4 + 0xd4);
            local_38 = puVar3[3];
            local_44 = *puVar3;
            local_40 = puVar3[1];
            local_3c = puVar3[2];
            FUN_00194374(&local_44,iVar8);
            iVar4 = FUN_000e79dc(iVar4);
            if (iVar4 == 0) {
              bVar2 = true;
            }
            FUN_00193cc0(local_38,local_3c);
          }
          iVar5 = iVar5 + 4;
        }
        FUN_000e7658(iVar8);
      }
      piVar1 = (int *)(iVar9 + 8);
      iVar8 = iVar9;
      iVar9 = *piVar1;
    } while (*piVar1 != 0);
  } while (bVar2);
  return;
}

/* FUN_0012b64c @ 0x12b64c (92 bytes) */
int FUN_0012b64c(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000e9184(param_1,0);
  iVar2 = FUN_000e920c(param_1,0);
  *(undefined4 *)(*(int *)(iVar1 + 0xd0) + 4) = 0;
  *(undefined4 *)(*(int *)(iVar2 + 0xd4) + 4) = 0;
  return FUN_000e8e4c(iVar1,iVar2);
}

/* FUN_0012b6a8 @ 0x12b6a8 (224 bytes) */
int FUN_0012b6a8(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  int iVar3;
  int iVar4;
  undefined4 *allocation;
  undefined4 uVar6;
  int *callResult;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 arena;
  int iVar11;
  undefined8 uVar12;
  
  iVar2 = FUN_000f4a84(*(undefined4 *)(param_1[0x10] + 0x3ac),3,1,param_4,param_5,param_6,param_7);
  if (iVar2 < 0) {
LAB_0012ba38:
    arena = 0;
  }
  else {
    iVar3 = FUN_00105594(param_1[0xf],1);
    *(int *)(*(int *)(param_1[0xf] + 0x158) + 0x138) =
         *(int *)(*(int *)(param_1[0xf] + 0x158) + 0x138) + -1;
    iVar11 = *(int *)(param_1[0x10] + 0x478);
    iVar4 = FUN_00104054(iVar3,param_1[0x10]);
    *(int *)(iVar3 + 0x160) = iVar11 + iVar4 + -1;
    iVar3 = *(int *)(param_1[0x10] + 8);
    arena = *(undefined4 *)(iVar3 + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arena,0x168);
    puVar8 = allocation + 1;
    *allocation = arena;
    IRLoadConst__ctor_109938(puVar8,iVar3);
    FUN_000e7688(*(undefined4 *)(param_1[0x10] + 0x3a0),puVar8);
    allocation[0x26] = iVar2;
    allocation[0x27] = 4;
    *(byte *)(allocation + 0x58) = *(byte *)(allocation + 0x58) | 1;
    if (param_1[7] == 0) {
      allocation[8] = 5;
      allocation[9] = param_1[4];
      allocation[10] = param_1[5];
      allocation[0xb] = param_1[8];
      if (param_1[1] == 0) {
        allocation[0xc] = param_1[2];
      }
      else {
        allocation[0xc] = 0xffffffff;
      }
      allocation[0xd] = param_1[3];
    }
    else {
      if (param_1[1] == 0) goto LAB_0012ba38;
      allocation[8] = 3;
      allocation[9] = param_1[6];
    }
    arena = 0;
    FUN_00106004(param_1[0xf],1,puVar8,0,iVar3);
    iVar2 = FUN_000e9184(param_1[10],0);
    if (param_2 == 0) {
      iVar4 = FUN_000e920c(*(undefined4 *)(param_1[10] + 0x13c),0);
    }
    else {
      iVar4 = *(int *)(param_1[10] + 0x134);
      ((int (*)())FUN_0012b64c)(*(undefined4 *)(param_1[10] + 0x13c));
    }
    *(undefined4 *)(*(int *)(iVar2 + 0xd0) + 4) = 0;
    *(undefined4 *)(*(int *)(iVar4 + 0xd4) + 4) = 0;
    FUN_000e8e4c(iVar2,iVar4);
    iVar2 = FUN_000e920c(param_1[9],0);
    iVar4 = 0;
    iVar11 = 0;
    for (uVar9 = 1; uVar9 <= *(uint *)(*(int *)(iVar2 + 0xd4) + 4); uVar9 = uVar9 + 1) {
      iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 0xd4) + 8) + iVar11);
      if (iVar1 != 0) {
        if (iVar1 == param_1[9]) {
          FUN_00194208(*(undefined4 *)(iVar2 + 0xd4),iVar4);
          break;
        }
        iVar4 = iVar4 + 1;
      }
      iVar11 = iVar11 + 4;
    }
    if (param_2 == 0) {
      iVar4 = FUN_000e9184(param_1[9],0);
      FUN_000e7658(param_1[9]);
      iVar2 = param_1[10];
      uVar6 = extraout_r4_00;
      if (iVar4 != iVar2) {
        do {
          FUN_000e7658(iVar4);
          uVar12 = FUN_000e9184(iVar4,0);
          iVar4 = (int)((ulonglong)uVar12 >> 0x20);
          uVar6 = (undefined4)uVar12;
          iVar2 = param_1[10];
        } while (iVar2 != iVar4);
      }
      iVar4 = *(int *)(iVar2 + 0x13c);
      if (iVar2 != iVar4) {
        do {
          FUN_000e7658(iVar4);
          uVar12 = FUN_000e9184(iVar4,0);
          iVar4 = (int)((ulonglong)uVar12 >> 0x20);
          uVar6 = (undefined4)uVar12;
        } while (iVar4 != param_1[10]);
      }
    }
    else {
      FUN_000e7658(*(undefined4 *)(param_1[10] + 0x13c));
      uVar6 = FUN_000e9184(param_1[9],0);
      FUN_000e7658(uVar6);
      FUN_000e7658(param_1[9]);
      uVar6 = extraout_r4;
    }
    if (*param_1 == 0) {
      (**(code **)(*(int *)param_1[0xd] + 0xc))
                ((int *)param_1[0xd],0,*(undefined4 *)(param_1[0x10] + 8));
      uVar9 = param_1[0x10];
      puVar8 = *(undefined4 **)(uVar9 + 8);
      (**(code **)(*(int *)param_1[0xc] + 0xc))((int *)param_1[0xc],0);
      uVar6 = extraout_r4_01;
    }
    callResult = (int *)FUN_000e7804(param_1[10],uVar6,puVar8,arena,iVar3,param_6,uVar9);
    if (callResult != (int *)0x0) {
      (**(code **)(*callResult + 0xc))(callResult,0,*(undefined4 *)(param_1[0x10] + 8));
      *(undefined4 *)(param_1[10] + 0x130) = 0;
    }
    FUN_000e7658(param_1[10]);
    arena = 1;
  }
  return arena;
}

/* FUN_0012ba58 @ 0x12ba58 (240 bytes) */
int FUN_0012ba58(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000e79dc(param_2);
  if (((iVar1 == 2) && (*(int *)(param_2 + 0x13c) == 0)) && (0 < *(int *)(param_2 + 0x138))) {
    *(int *)(param_1 + 0x2c) = param_2;
    iVar1 = *(int *)(param_2 + 0x98);
    for (iVar2 = *(int *)(*(int *)(param_2 + 0x98) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x81)) {
        iVar2 = FUN_00105594(iVar1,1);
        if ((*(byte *)(iVar2 + 0x15c) & 1) == 0) {
          return 0;
        }
        if (*(int *)(iVar2 + 0x1c) != 3) {
          return 0;
        }
        iVar2 = *(int *)(iVar2 + 0x20);
        *(int *)(param_1 + 0x20) = iVar2;
        if ((iVar2 == 0xff) || (iVar2 == 0xffff)) {
          *(int *)(param_1 + 0x3c) = iVar1;
          return 1;
        }
        iVar2 = *(int *)(iVar1 + 8);
      }
      iVar1 = iVar2;
    }
  }
  return 0;
}

/* FUN_0012bb48 @ 0x12bb48 (296 bytes) */
int FUN_0012bb48(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint loopIndex;
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *allocation;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r5;
  int *piVar7;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a6;
  uint uVar8;
  int iVar9;
  undefined4 arena;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined8 uVar14;
  
  a6 = *(code **)(*param_2 + 0x24);
  (*a6)(param_2,param_2,in_r5,in_r6,in_r7,in_r8,a6);
  if ((param_2[3] & 0x400U) == 0) {
    iVar11 = param_2[0x4d];
    iVar12 = param_2[0x4e];
    uVar14 = FUN_000e7804(param_2,extraout_r4,in_r5,in_r6,in_r7,in_r8,a6);
    if (((((((int)((ulonglong)uVar14 >> 0x20) != 0) &&
           (iVar3 = FUN_000e7804(param_2,(int)uVar14,in_r5,in_r6,in_r7,in_r8,a6),
           *(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8b)) &&
          (iVar3 = FUN_000e9294(param_2), iVar3 != 0)) &&
         ((iVar3 = param_2[0x4f], param_2[0x43] == 0 && (param_2[0x44] == 0)))) &&
        ((((param_2[3] & 0x10U) == 0 &&
          ((*(int *)(iVar3 + 0x10c) == 0 && (*(int *)(iVar3 + 0x110) == 0)))) &&
         ((*(uint *)(iVar3 + 0xc) & 0x10) == 0)))) &&
       ((((*(int *)(iVar11 + 0x10c) == 0 && (*(int *)(iVar11 + 0x110) == 0)) &&
         ((*(uint *)(iVar11 + 0xc) & 0x10) == 0)) &&
        (((*(int *)(iVar12 + 0x10c) == 0 && (*(int *)(iVar12 + 0x110) == 0)) &&
         ((*(uint *)(iVar12 + 0xc) & 0x10) == 0)))))) {
      iVar9 = param_2[0x37];
      arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      allocation = (undefined4 *)FUN_00193e18(arena,0x130);
      *allocation = arena;
      piVar13 = allocation + 1;
      Block__ctor_ea020(piVar13,*(undefined4 *)(param_1 + 8));
      FUN_000ec370(param_1,param_2,piVar13);
      piVar7 = piVar13;
      FUN_000e8eac(param_2,iVar3,piVar13);
      iVar4 = FUN_000e7804(param_2,extraout_r4_00,piVar7,in_r6,in_r7,in_r8,a6);
      param_2[0x4c] = 0;
      uVar8 = *(uint *)(iVar4 + 0x14);
      *(undefined4 *)(iVar4 + 0x80) = 1;
      *(undefined4 *)(iVar4 + 0x94) = 0;
      *(undefined4 *)(iVar4 + 0x98) = 0x35;
      *(undefined4 *)(iVar4 + 0x9c) = 0;
      *(uint *)(iVar4 + 0x14) = uVar8 | 0x80000;
      if (iVar9 != 0) {
        *(uint *)(iVar4 + 0x14) = uVar8 | 0x81000;
      }
      FUN_0019401c(iVar4);
      FUN_000e7688(piVar13,iVar4);
      piVar7 = (int *)param_2[0x26];
      for (piVar2 = (int *)((int *)param_2[0x26])[2]; piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[2]) {
        iVar9 = (**(code **)(*piVar7 + 0x34))(piVar7);
        if ((iVar9 == 0) && (iVar9 = (**(code **)(*piVar7 + 0x38))(piVar7), iVar9 == 0)) {
          FUN_0019401c(piVar7);
          FUN_000e7700(piVar13,iVar4,piVar7);
        }
        piVar7 = piVar2;
      }
      iVar9 = *(int *)(iVar11 + 0xdc);
      piVar7 = *(int **)(iVar11 + 0x98);
      for (piVar2 = (int *)(*(int **)(iVar11 + 0x98))[2]; piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[2]) {
        iVar5 = (**(code **)(*piVar7 + 0x34))(piVar7);
        if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar7 + 0x38))(piVar7), iVar5 == 0)) {
          FUN_0019401c(piVar7);
          (**(code **)(*piVar7 + 0x94))(piVar7,iVar4,*(undefined4 *)(param_1 + 8));
          (**(code **)(*piVar7 + 0x84))(piVar7,2);
          FUN_000e7688(piVar13,piVar7);
          if (iVar9 != 0) {
            iVar9 = 1;
            if ((piVar7[5] & 0x10000U) == 0) {
              iVar9 = 0;
              piVar7[5] = piVar7[5] | 0x1000;
            }
          }
        }
        piVar7 = piVar2;
      }
      piVar7 = *(int **)(iVar12 + 0x98);
      for (piVar2 = (int *)(*(int **)(iVar12 + 0x98))[2]; piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[2]) {
        iVar5 = (**(code **)(*piVar7 + 0x34))(piVar7);
        if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar7 + 0x38))(piVar7), iVar5 == 0)) {
          FUN_0019401c(piVar7);
          (**(code **)(*piVar7 + 0x94))(piVar7,iVar4,*(undefined4 *)(param_1 + 8));
          (**(code **)(*piVar7 + 0x84))(piVar7,3);
          FUN_000e7688(piVar13,piVar7);
          if (iVar9 != 0) {
            iVar9 = 1;
            if ((piVar7[5] & 0x10000U) == 0) {
              iVar9 = 0;
              piVar7[5] = piVar7[5] | 0x1000;
            }
          }
        }
        piVar7 = piVar2;
      }
      bVar1 = *(int *)(iVar3 + 0xdc) == 0;
      piVar7 = *(int **)(iVar3 + 0x98);
      for (piVar2 = (int *)(*(int **)(iVar3 + 0x98))[2]; piVar2 != (int *)0x0;
          piVar2 = (int *)piVar2[2]) {
        iVar9 = (**(code **)(*piVar7 + 0x34))(piVar7);
        if ((iVar9 == 0) && (iVar9 = (**(code **)(*piVar7 + 0x38))(piVar7), iVar9 == 0)) {
          FUN_0019401c(piVar7);
          (**(code **)(*piVar7 + 0x94))(piVar7,iVar4,*(undefined4 *)(param_1 + 8));
          FUN_000e7688(piVar13,piVar7);
          if (!bVar1) {
            if ((piVar7[5] & 0x10000U) == 0) {
              piVar7[5] = piVar7[5] | 0x1000;
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
        }
        piVar7 = piVar2;
      }
      if (!bVar1) {
        iVar4 = 0;
        for (loopIndex = 1; loopIndex <= *(uint *)(allocation[0x35] + 4); loopIndex = loopIndex + 1) {
          iVar9 = *(int *)(*(int *)(allocation[0x35] + 8) + iVar4);
          if (iVar9 != 0) {
            *(undefined4 *)(iVar9 + 0xdc) = 1;
          }
          iVar4 = iVar4 + 4;
        }
      }
      FUN_000e7658(param_2);
      FUN_000e7658(iVar11);
      FUN_000e7658(iVar12);
      FUN_000e7658(iVar3);
      param_2 = piVar13;
    }
  }
  return param_2;
}

/* FUN_0012c0e4 @ 0x12c0e4 (80 bytes) */
int FUN_0012c0e4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  iVar2 = *(int *)(*(int *)(param_1 + 0x98) + 8);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (((*(uint *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x77))
    break;
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar2 + 8);
  }
  return 1;
}

/* FUN_0012c134 @ 0x12c134 (424 bytes) */
int FUN_0012c134(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  undefined8 uVar11;
  
  iVar4 = FUN_000e9294(param_2);
  if (iVar4 != 0) {
    iVar9 = *(int *)(param_2 + 0x134);
    iVar8 = *(int *)(param_2 + 0x138);
    iVar4 = ((int (*)())FUN_0012c0e4)(iVar9);
    if ((iVar4 == 0) && (iVar4 = ((int (*)())FUN_0012c0e4)(iVar8), iVar4 == 0)) {
      uVar7 = 3;
      uVar11 = FUN_000e0830(param_3,0,3);
      if ((int)((ulonglong)uVar11 >> 0x20) == 0) {
        if ((*(uint *)(param_2 + 0xc) & 0x800) == 0) {
          uVar11 = FUN_0012ae6c(iVar9,(int)uVar11,uVar7,param_4,param_5,param_6,param_7);
          if ((int)((ulonglong)uVar11 >> 0x20) != 0) {
            return 0;
          }
          iVar4 = FUN_0012ae6c(iVar8,(int)uVar11,uVar7,param_4,param_5,param_6,param_7);
          if (iVar4 != 0) {
            return 0;
          }
          uVar5 = FUN_00194034(iVar9 + 0x90);
          dVar10 = DOUBLE_001aa1e0;
          fVar2 = FLOAT_001aa108;
          uVar6 = FUN_00194034(iVar8 + 0x90);
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - dVar10) - fVar2;
        }
        else {
          uVar5 = FUN_00194034(iVar9 + 0x90);
          dVar10 = DOUBLE_001aa1e0;
          fVar2 = FLOAT_001aa108;
          uVar6 = FUN_00194034(iVar8 + 0x90);
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - dVar10) - fVar2;
        }
        fVar2 = (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - dVar10) - fVar2;
        fVar3 = fVar1;
        if (fVar1 - fVar2 < 0.0) {
          fVar3 = fVar2;
        }
        if (-(fVar1 - fVar2) < 0.0) {
          fVar2 = fVar3;
        }
        if (FLOAT_001aa1bc < fVar2) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_0012c2dc @ 0x12c2dc (244 bytes) */
int FUN_0012c2dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined8 uVar4;
  
  if ((0 < *(int *)(param_2 + 0x138)) || (*(int *)(param_2 + 0x13c) != 0)) {
    iVar1 = FUN_000e920c(param_2,0);
    iVar2 = FUN_00194034(iVar1 + 0x90);
    if (iVar2 < 3) {
      piVar3 = (int *)FUN_000e920c(iVar1,0);
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3);
      if (iVar2 != 0) {
        uVar4 = FUN_000e920c(iVar1,0);
        iVar1 = (int)((ulonglong)uVar4 >> 0x20);
        iVar2 = FUN_000e7804(iVar1,(int)uVar4,in_r5,in_r6,in_r7,in_r8,in_r9);
        if ((((*(uint *)(param_1 + 0x30) & 8) == 0) && (*(int *)(iVar2 + 0x84) == 2)) &&
           (*(int *)(iVar2 + 0xa4) == *(int *)(iVar2 + 0xbc))) {
          piVar3 = (int *)FUN_000e920c(*(undefined4 *)(iVar1 + 0x134),0);
          iVar1 = (**(code **)(*piVar3 + 0x38))(piVar3);
          if (iVar1 != 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0012c3d0 @ 0x12c3d0 (460 bytes) */
int FUN_0012c3d0(inst, param_2, param_3)
  int *inst;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = 1;
  piVar3 = inst;
  do {
    iVar2 = (**(code **)(*inst + 0x14))(inst);
    if (iVar2 < iVar5) {
      iVar5 = (**(code **)(*inst + 0x18))(inst);
      if ((iVar5 == 1) && (iVar5 = FUN_00105dbc(inst,0), iVar5 == 1)) {
        uVar6 = *(undefined4 *)(param_3 + 0x3ac);
        iVar5 = FUN_00105c5c(inst,0);
        piVar3 = (int *)FUN_00127608(uVar6,0x24,iVar5 + param_2,0);
        pcVar4 = *(code **)(*piVar3 + 0x28);
        iVar5 = FUN_001054ec(inst,0);
        uVar6 = (*pcVar4)(piVar3,*(undefined4 *)(iVar5 + 0x10),param_3);
        FUN_001046c8(inst,0,uVar6);
        if ((inst[5] & 2U) == 0) {
          inst[5] = inst[5] & 0xffffffef;
          FUN_000ef970(param_3,inst);
          return;
        }
      }
      return;
    }
    iVar2 = FUN_00105dbc(inst,iVar5);
    if (iVar2 == 1) {
      iVar2 = FUN_00105c5c(inst,iVar5);
      if (piVar3[0x2c] == 0x28) {
        uVar1 = *(undefined4 *)(param_3 + 0x3ac);
        uVar6 = 2;
      }
      else {
        if (piVar3[0x2c] != 0x29) goto LAB_0012c498;
        if ((*(uint *)(param_3 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_3 + 0x30) & 0x2000) == 0) goto LAB_0012c498;
          uVar1 = *(undefined4 *)(param_3 + 0x3ac);
          uVar6 = 0x24;
        }
        else {
          uVar6 = FUN_000ec208(param_3,5);
          uVar1 = *(undefined4 *)(param_3 + 0x3ac);
        }
      }
      uVar6 = FUN_00127608(uVar1,uVar6,param_2 + iVar2,0);
      FUN_001046c8(inst,iVar5,uVar6);
    }
LAB_0012c498:
    iVar5 = iVar5 + 1;
    piVar3 = piVar3 + 6;
  } while( true );
}

/* FUN_0012c59c @ 0x12c59c (548 bytes) */
int FUN_0012c59c(param_1, inst)
  int param_1;
  int *inst;
{
  int *operandVReg;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_28 [6];
  
  iVar2 = (**(code **)(*inst + 100))(inst,inst);
  if (iVar2 != 0) {
    for (iVar2 = 1; iVar3 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar3;
        iVar2 = iVar2 + 1) {
      if ((inst[iVar2 * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((inst[iVar2 * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      iVar3 = FUN_000f31e8(inst,iVar2);
      if (iVar3 == 0) {
        return 0;
      }
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if ((inst[0x20] != 0) &&
         (((iVar2 = FUN_00126760(inst[0x26]), iVar2 != 0 && ((inst[5] & 2U) == 0)) &&
          (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))) {
        iVar2 = 4;
        piVar4 = inst;
        do {
          if ((uint)(*(byte *)(piVar4 + 0x27) - 2) < 2) {
            return 0;
          }
          piVar4 = (int *)((int)piVar4 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      FUN_001054ec(inst,0);
      iVar2 = FUN_00105dbc(inst,0);
      if (((iVar2 == 0) && ((inst[5] & 2U) == 0)) && ((inst[5] & 0x200U) == 0)) {
        operandVReg = (int *)FUN_00105594(inst,1);
        iVar2 = (**(code **)(*operandVReg + 0x48))(operandVReg);
        if (iVar2 != 0) {
          iVar2 = FUN_001054ec(inst,1);
          local_28[0] = *(undefined4 *)(iVar2 + 0x10);
          uVar1 = (uint)*(byte *)((int)local_28 + *(int *)(param_1 + 0x38));
          if (((int)*(char *)(operandVReg + 0x57) >> (uVar1 & 0x3f) & 1U) == 0) {
            *(undefined4 *)(param_1 + 4) = 0;
            *(uint *)(param_1 + 0xc) = uVar1;
            *(int *)(param_1 + 8) = operandVReg[0x25];
            return 1;
          }
          if ((operandVReg[uVar1 * 6 + 7] == 2) && (GH_U2F((unsigned int)(operandVReg[uVar1 * 6 + 8])) == 0.0)) {
            *(undefined4 *)(param_1 + 4) = 1;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_0012c7c0 @ 0x12c7c0 (328 bytes) */
int FUN_0012c7c0(param_1, inst)
  undefined4 *param_1;
  int inst;
{
  int loopIndex2;
  bool bVar1;
  uint uVar2;
  int operandRecord;
  int *a0;
  int iVar4;
  int iVar5;
  int loopIndex;
  undefined4 local_38 [8];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x12) {
    loopIndex2 = 0;
    iVar4 = -1;
    loopIndex = 0;
    do {
      operandRecord = FUN_001054ec(inst,0);
      if (*(char *)(loopIndex + operandRecord + 0x10) != '\x01') {
        iVar4 = param_1[0xe];
        loopIndex2 = loopIndex2 + 1;
        if (iVar4 != loopIndex) {
          return 0;
        }
        if (1 < loopIndex2) {
          return 0;
        }
      }
      bVar1 = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (bVar1);
    iVar5 = FUN_00104054(inst,param_1[0x10]);
    if (1 < iVar5) {
      *param_1 = 1;
    }
    iVar5 = FUN_00105594(param_1[0xd],1);
    if (inst == iVar5) {
      a0 = (int *)FUN_00105594(iVar5,2);
      iVar5 = (**(code **)(*a0 + 0x48))(a0);
      if (iVar5 != 0) {
        iVar5 = FUN_001054ec(inst,2);
        local_38[0] = *(undefined4 *)(iVar5 + 0x10);
        uVar2 = (uint)*(byte *)((int)local_38 + iVar4);
        if (((((int)*(char *)(a0 + 0x57) >> (uVar2 & 0x3f) & 1U) != 0) && (a0[uVar2 * 6 + 7] == 2))
           && (GH_U2F((unsigned int)(a0[uVar2 * 6 + 8])) == 1.0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* FUN_0012c908 @ 0x12c908 (952 bytes) */
int FUN_0012c908(param_1, inst, param_3, param_4)
  int param_1;
  int inst;
  int param_3;
  int *param_4;
{
  byte bVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int *operandVReg;
  int *piVar6;
  int *piVar7;
  int callResult;
  uint uVar9;
  int iVar10;
  undefined4 local_38;
  int local_34;
  byte local_30 [8];
  longlong local_28;
  
  *param_4 = 0;
  if (inst == 0) {
    return 0;
  }
  iVar3 = *(int *)(*(int *)(inst + 0x88) + 8);
  if (iVar3 == 0x8b) {
    piVar7 = param_4;
    iVar3 = FUN_00105594(inst,1);
    if (iVar3 != *(int *)(param_1 + 0x34)) {
      return 0;
    }
    piVar6 = (int *)FUN_00105594(inst,2);
    iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_0010b5f8(inst);
    if (iVar3 != 3) {
      return 0;
    }
    iVar3 = FUN_001054ec(inst,2);
    local_38 = *(undefined4 *)(iVar3 + 0x10);
    bVar1 = *(byte *)((int)&local_38 + *(int *)(param_1 + 0x38));
    uVar9 = (uint)bVar1;
    *(uint *)(param_1 + 0x14) = uVar9;
    if (piVar6[0x26] == 0x33) {
      local_34 = piVar6[uVar9 * 6 + 8];
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3ac);
      local_30[0] = 4;
      local_30[1] = 4;
      local_30[2] = 4;
      local_30[3] = 4;
      local_30[uVar9] = bVar1;
      piVar6 = (int *)FUN_000f57f0(uVar4,&local_34,local_30,piVar7);
      *(uint *)(param_1 + 0x14) = (uint)local_30[*(int *)(param_1 + 0x14)];
      if (piVar6 == (int *)0x0) {
        return 0;
      }
    }
    *(int *)(param_1 + 0x10) = piVar6[0x25];
  }
  else {
    if (iVar3 != 0x8c) {
      return 0;
    }
    uVar4 = FUN_00105594(inst,1);
    operandVReg = (int *)FUN_00105594(uVar4,1);
    piVar6 = (int *)FUN_00105594(uVar4,2);
    iVar3 = (**(code **)(*operandVReg + 0x48))(operandVReg);
    piVar7 = operandVReg;
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*piVar6 + 0x48))(piVar6);
      if (iVar3 == 0) {
        return 0;
      }
      *param_4 = 1;
      piVar7 = piVar6;
      piVar6 = operandVReg;
    }
    if (piVar6 != *(int **)(param_1 + 0x34)) {
      return 0;
    }
    iVar3 = FUN_00104054(uVar4,*(undefined4 *)(param_1 + 0x40));
    if (iVar3 != 1) {
      return 0;
    }
    iVar3 = FUN_0010b5f8(uVar4);
    if (*param_4 == 0) {
      if (iVar3 != 2) {
        return 0;
      }
    }
    else if (iVar3 != 3) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if ((*(byte *)(piVar7 + 0x57) & 1) == 0) {
      *(int *)(param_1 + 0x10) = piVar7[0x25];
      iVar3 = FUN_001054ec(inst,1);
      local_38 = *(undefined4 *)(iVar3 + 0x10);
      *(uint *)(param_1 + 0x14) = (uint)*(byte *)((int)&local_38 + *(int *)(param_1 + 0x38));
      if (*param_4 == 0) {
        iVar3 = FUN_001054ec(uVar4,1);
        local_38 = *(undefined4 *)(iVar3 + 0x10);
      }
      else {
        iVar3 = FUN_001054ec(uVar4,2);
        local_38 = *(undefined4 *)(iVar3 + 0x10);
      }
      *(uint *)(param_1 + 0x14) = (uint)*(byte *)((int)&local_38 + *(int *)(param_1 + 0x14));
    }
    else {
      fVar2 = GH_U2F((unsigned int)(piVar7[8]));
      *(undefined4 *)(param_1 + 0x1c) = 1;
      local_28 = (longlong)(int)fVar2;
      *(int *)(param_1 + 0x18) = (int)fVar2;
    }
  }
  iVar3 = *(int *)(param_3 + 0x134);
  iVar10 = *(int *)(param_3 + 0x138);
  if (*param_4 == 0) {
    callResult = FUN_00194034(iVar3 + 0x90);
    if ((callResult < 3) && (iVar10 = FUN_00194034(iVar10 + 0x90), iVar10 < 3)) {
      piVar7 = (int *)FUN_000e920c(iVar3,0);
      iVar10 = (**(code **)(*piVar7 + 0x38))(piVar7);
      if (iVar10 != 0) {
        uVar4 = FUN_000e920c(iVar3,0);
        *(undefined4 *)(param_1 + 0x24) = uVar4;
LAB_0012cc9c:
        *(int *)(param_1 + 0x28) = param_3;
        return 1;
      }
    }
  }
  else {
    iVar3 = FUN_000e7770(iVar10);
    if ((iVar3 != 0) && (iVar3 = FUN_00194034(iVar10 + 0x90), iVar3 < 3)) {
      piVar7 = (int *)FUN_000e920c(iVar10,0);
      *(int **)(param_1 + 0x24) = piVar7;
      iVar3 = (**(code **)(*piVar7 + 0x38))(piVar7);
      if (iVar3 != 0) {
        uVar4 = FUN_000e920c(*(undefined4 *)(param_3 + 0x13c),0);
        iVar3 = FUN_000e7770(uVar4);
        if ((iVar3 != 0) &&
           (iVar3 = FUN_000e920c(uVar4,0), iVar3 == *(int *)(*(int *)(param_1 + 0x2c) + 0x150)))
        goto LAB_0012cc9c;
      }
    }
  }
  return 0;
}

/* pass_loop_trans @ 0x12ccc0 (740 bytes) */
int pass_loop_trans(program)
  int program;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  int *in_r5;
  int *in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int local_88;
  int local_84 [12];
  undefined4 local_54;
  int local_44;
  
  piVar7 = (int *)(*(int **)(program + 900))[2];
  if (piVar7 != (int *)0x0) {
    bVar1 = false;
    piVar9 = *(int **)(program + 900);
    local_44 = program;
    do {
      piVar8 = piVar7;
      iVar3 = (**(code **)(*piVar9 + 0x2c))(piVar9);
      if ((iVar3 != 0) && (iVar3 = ((int (*)())FUN_0012ba58)(local_84,piVar9), iVar3 != 0)) {
        local_84[0] = 0;
        iVar3 = piVar9[0x26];
        for (iVar2 = *(int *)(piVar9[0x26] + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          if ((*(int *)(*(int *)(iVar3 + 0x88) + 8) == 0x8e) &&
             (iVar4 = ((int (*)())FUN_0012b35c)(local_84,iVar3), iVar4 != 0)) {
            uVar5 = FUN_00105594(iVar3,2);
            iVar4 = ((int (*)())FUN_0012c59c)(local_84,uVar5);
            if (iVar4 != 0) {
              uVar5 = FUN_00105594(iVar3,1);
              iVar3 = ((int (*)())FUN_0012c7c0)(local_84,uVar5);
              if (iVar3 != 0) {
                local_54 = uVar5;
                piVar6 = (int *)FUN_000e920c(piVar9,0);
                iVar3 = (**(code **)(*piVar6 + 0x24))(piVar6);
                uVar5 = extraout_r4;
                piVar7 = in_r5;
                if (iVar3 == 0) {
                  iVar3 = FUN_000e7770(piVar6);
                  if (iVar3 != 0) {
                    iVar3 = FUN_00194034(piVar6 + 0x24);
                    if ((iVar3 < 3) || (iVar3 = FUN_00194034(piVar6 + 0x24), iVar3 == 3)) {
                      piVar6 = (int *)FUN_000e920c(piVar6,0);
                      iVar3 = (**(code **)(*piVar6 + 0x24))(piVar6);
                      uVar5 = extraout_r4_00;
                      piVar7 = in_r5;
                      if (iVar3 != 0) goto LAB_0012ce40;
                    }
                  }
                }
                else {
LAB_0012ce40:
                  in_r5 = piVar6;
                  uVar5 = FUN_000e7804(in_r5,uVar5,piVar7,in_r6,in_r7,in_r8,in_r9);
                  piVar7 = (int *)in_r5[0x4f];
                  in_r6 = &local_88;
                  local_88 = 0;
                  iVar3 = ((int (*)())FUN_0012c908)(local_84,uVar5,in_r5,in_r6);
                  if (iVar3 != 0) {
                    if ((local_88 == 0) && (piVar6 = (int *)piVar9[0x54], piVar7 != piVar6)) {
                      iVar3 = 0;
                      do {
                        iVar4 = (**(code **)(*piVar7 + 0x2c))(piVar7);
                        if (iVar4 == 0) {
                          iVar4 = (**(code **)(*piVar7 + 0x30))(piVar7);
                          if (iVar4 == 0) {
                            if (iVar3 == 0) {
                              (**(code **)(*piVar7 + 0x38))(piVar7);
                            }
                          }
                          else {
                            iVar3 = iVar3 + -1;
                          }
                        }
                        else {
                          iVar3 = iVar3 + 1;
                        }
                        piVar7 = (int *)piVar7[2];
                      } while (piVar6 != piVar7);
                    }
                    iVar3 = ((int (*)())FUN_0012b6a8)(local_84,local_88,in_r5,in_r6,in_r7,in_r8,in_r9);
                    bVar1 = bVar1 || iVar3 != 0;
                    if (iVar3 != 0) {
                      FUN_000ed7e4(program,(int)"loop_trans");
                    }
                  }
                }
              }
            }
          }
          iVar3 = iVar2;
        }
      }
      piVar7 = (int *)piVar8[2];
      piVar9 = piVar8;
    } while (piVar7 != (int *)0x0);
    if (bVar1) {
      FUN_000ec2e8(program);
      FUN_0013bd68(program,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_0012cfa4 @ 0x12cfa4 (820 bytes) */
int FUN_0012cfa4(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int *param_4;
{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with FUN_0019423c - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. FUN_0019423c unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_54_buf [0x10];
  #define vecCapacity (*(uint *)(local_54_buf + 0x00))
  #define vecCount (*(uint *)(local_54_buf + 0x04))
  #define vecData (*(int *)(local_54_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_54_buf + 0x0c))
  
  vecArena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = FUN_00193e18(vecArena,8);
  uVar7 = vecCount;
  if (vecCount < vecCapacity) {
    iVar8 = vecCount * 4;
    _memset(vecData + iVar8,0,4);
    vecCount = uVar7 + 1;
    puVar4 = (undefined4 *)(iVar8 + vecData);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(&vecCapacity,vecCount);
  }
  *puVar4 = param_3;
  while (vecCount != 0) {
    uVar7 = vecCount - 1;
    piVar2 = (int *)0x0;
    if (uVar7 < vecCount) {
      piVar2 = (int *)(uVar7 * 4 + vecData);
    }
    iVar8 = *piVar2;
    FUN_00194208(&vecCapacity,uVar7);
    piVar2 = *(int **)(iVar8 + 0x98);
    for (piVar3 = (int *)piVar2[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      if ((piVar2[5] & 1U) != 0) {
        iVar5 = (**(code **)(*piVar2 + 0x34))(piVar2);
        if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar2 + 0x38))(piVar2), iVar5 == 0)) {
          if (*(int *)(piVar2[0x22] + 8) != 0x8e) {
            piVar3 = piVar2;
            for (iVar5 = 1; iVar6 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar5 <= iVar6;
                iVar5 = iVar5 + 1) {
              FUN_001234d8(piVar3[0x29],piVar2);
              piVar3 = piVar3 + 6;
            }
          }
          (**(code **)(*piVar2 + 0xc))(piVar2,0,*(undefined4 *)(param_1 + 8));
        }
        piVar3 = (int *)piVar2[2];
      }
      piVar2 = piVar3;
    }
    iVar5 = 0;
    for (uVar7 = 1; iVar6 = *(int *)(iVar8 + 0xd0), uVar7 <= *(uint *)(iVar6 + 4); uVar7 = uVar7 + 1
        ) {
      piVar2 = *(int **)(*(int *)(iVar6 + 8) + iVar5);
      if ((((piVar2 != (int *)0x0) && (piVar2 != param_4)) && (piVar2 != param_2)) &&
         (((iVar6 = (**(code **)(*piVar2 + 0x38))(piVar2), iVar6 == 0 &&
           (iVar6 = (**(code **)(*piVar2 + 0x3c))(piVar2), iVar6 == 0)) &&
          (iVar6 = FUN_00194034(piVar2 + 0x24), uVar1 = vecCount, 2 < iVar6)))) {
        if (vecCount < vecCapacity) {
          iVar6 = vecCount * 4;
          _memset(iVar6 + vecData,0,4);
          vecCount = uVar1 + 1;
          puVar4 = (undefined4 *)(iVar6 + vecData);
        }
        else {
          puVar4 = (undefined4 *)FUN_0019423c(&vecCapacity,vecCount);
        }
        *puVar4 = piVar2;
      }
      iVar5 = iVar5 + 4;
    }
  }
  vecCount = 0;
  piVar2 = (int *)param_4[0x26];
  for (piVar3 = (int *)((int *)param_4[0x26])[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
    if ((piVar2[5] & 1U) != 0) {
      piVar3 = (int *)(**(code **)(*piVar2 + 0x7c))(piVar2);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0xc))(piVar3,0,*(undefined4 *)(param_1 + 8));
      }
      piVar3 = (int *)piVar2[2];
    }
    piVar2 = piVar3;
  }
  FUN_00194034(param_4 + 0x24);
  return FUN_00193cc0(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* pass_flatten_ifs @ 0x12d2f0 (1988 bytes) */
int pass_flatten_ifs(flattenPass)
  int flattenPass;
{
  int *operandVReg;
  bool changed;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 operandVReg2;
  undefined4 operandVReg3;
  undefined4 extraout_r4;
  uint in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar11;
  code *pcVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 uVar17;
  int *piVar18;
  int iVar19;
  int *node;
  int iVar21;
  int iVar22;
  int *piVar23;
  uint *puVar24;
  uint *puVar25;
  int iVar26;
  undefined8 uVar27;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  int local_60 [2];
  int local_58;
  int *local_54;
  
  node = *(int **)(flattenPass + 900);
  piVar23 = (int *)node[2];
  if (piVar23 != (int *)0x0) {
    changed = false;
    do {
      iVar5 = (**(code **)(*node + 0x28))(node);
      if ((iVar5 != 0) && (iVar5 = (**(code **)(*node + 0x40))(node), iVar5 == 0)) {
        iVar5 = *(int *)(flattenPass + 8);
        if (*(int *)(iVar5 + 0x6a8) <= *(int *)(*(int *)(iVar5 + 0x6c4) + 0x15c)) break;
        iVar16 = node[0x4b];
        iVar6 = (**(code **)(**(int **)(iVar5 + 0x30c) + 0x114))(*(int **)(iVar5 + 0x30c),iVar16);
        if (iVar6 == 0) break;
        uVar27 = FUN_000e87e4(iVar16,auStack_68);
        if ((int)((ulonglong)uVar27 >> 0x20) != 0) break;
        puVar24 = (uint *)node[0x35];
        iVar6 = *(int *)(iVar16 + 0x134);
        iVar21 = *(int *)(iVar16 + 0x138);
        if (*puVar24 == 0) {
          uVar27 = FUN_0019423c(puVar24,0);
          puVar25 = (uint *)node[0x35];
        }
        else {
          puVar25 = puVar24;
          if (puVar24[1] == 0) {
            *(undefined4 *)puVar24[2] = 0;
            puVar24[1] = 1;
            puVar25 = (uint *)node[0x35];
          }
          uVar27 = CONCAT44(puVar24[2],(int)uVar27);
        }
        uVar13 = (undefined4)uVar27;
        iVar22 = *(int *)((ulonglong)uVar27 >> 0x20);
        if (*puVar25 < 2) {
          uVar27 = FUN_0019423c(puVar25,1);
        }
        else {
          uVar7 = puVar25[1];
          if (uVar7 < 2) {
            iVar5 = (1 - uVar7) * 4 + 4;
            _memset(uVar7 * 4 + puVar25[2],0,iVar5);
            puVar25[1] = 2;
            uVar13 = extraout_r4;
          }
          uVar27 = CONCAT44(puVar25[2] + 4,uVar13);
        }
        piVar23 = *(int **)(iVar16 + 0xd4);
        iVar26 = *(int *)((ulonglong)uVar27 >> 0x20);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        local_58 = *(int *)((ulonglong)uVar27 >> 0x20);
        piVar23 = (int *)node[0x34];
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        iVar19 = *(int *)((ulonglong)uVar27 >> 0x20);
        piVar23 = *(int **)(local_58 + 0xd0);
        iVar11 = local_58;
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = iVar6;
        piVar23 = *(int **)(iVar6 + 0xd4);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = local_58;
        piVar23 = *(int **)(iVar19 + 0xd4);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = iVar26;
        piVar23 = *(int **)(iVar26 + 0xd0);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = iVar19;
        piVar23 = *(int **)(iVar22 + 0xd0);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = iVar21;
        piVar23 = *(int **)(iVar21 + 0xd4);
        if (*piVar23 == 0) {
          uVar27 = FUN_0019423c(piVar23,0);
        }
        else {
          if (piVar23[1] == 0) {
            *(undefined4 *)piVar23[2] = 0;
            piVar23[1] = 1;
          }
          uVar27 = CONCAT44(piVar23[2],(int)uVar27);
        }
        *(int *)((ulonglong)uVar27 >> 0x20) = iVar22;
        *(int *)(iVar6 + 0xf0) = local_58;
        *(int *)(iVar21 + 0xf0) = iVar22;
        *(int *)(iVar19 + 0xf0) = iVar26;
        piVar23 = (int *)FUN_000e7804(iVar16,(int)uVar27,iVar5,in_r6,in_r7,in_r8,iVar11);
        if (*(int *)(piVar23[0x22] + 8) == 0x8b) {
          iVar5 = FUN_0010b498(piVar23,2);
          if (iVar5 == 0) {
            iVar5 = FUN_0010b498(piVar23,1);
            if (iVar5 == 0) {
              piVar8 = FUN_001043f0(0x12,*(undefined4 *)(flattenPass + 8));
              piVar8[0x26] = 0;
              piVar8[0x25] = piVar8[0x53];
              uVar13 = FUN_001054ec(piVar23,1);
              FUN_001062c0(piVar8,1,uVar13,*(undefined4 *)(flattenPass + 8));
              uVar13 = FUN_001054ec(piVar23,2);
              in_r6 = *(uint *)(flattenPass + 8);
              FUN_001062c0(piVar8,2,uVar13,in_r6);
              FUN_00103d50(piVar8 + 0x2f,1,piVar23[0x34] & 1U ^ 1);
              FUN_000e76c4(iVar19,piVar8);
              FUN_00105f04(piVar8,flattenPass);
              uVar13 = 0x10203;
              for (iVar5 = 1; iVar6 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar5 <= iVar6;
                  iVar5 = iVar5 + 1) {
                operandVReg = (int *)FUN_00105594(piVar8,iVar5);
                iVar6 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                if (iVar6 != 0) {
                  FUN_0019401c(operandVReg);
                  FUN_000e7700(iVar19,piVar8,operandVReg);
                }
              }
              uVar7 = 0;
              uVar14 = 0;
              piVar18 = piVar8;
            }
            else {
              piVar18 = *(int **)(iVar19 + 200);
              piVar8 = (int *)FUN_00105594(piVar23,2);
              iVar5 = FUN_001054ec(piVar23,2);
              uVar13 = *(undefined4 *)(iVar5 + 0x10);
              uVar7 = piVar23[0x34] & 1;
              uVar14 = (uint)piVar23[0x34] >> 1 & 1;
              iVar5 = FUN_0010b5f8(piVar23);
              FUN_0010b914(piVar23,*(undefined4 *)(PTR_DAT_001e90f8 + iVar5 * 4));
            }
          }
          else {
            piVar18 = *(int **)(iVar19 + 200);
            piVar8 = (int *)FUN_00105594(piVar23,1);
            iVar5 = FUN_001054ec(piVar23,1);
            uVar13 = *(undefined4 *)(iVar5 + 0x10);
            uVar7 = piVar23[0x2e] & 1;
            uVar14 = (uint)piVar23[0x2e] >> 1 & 1;
          }
        }
        else {
          piVar18 = *(int **)(iVar19 + 200);
          piVar8 = (int *)FUN_00105594(piVar23,1);
          iVar6 = FUN_001054ec(piVar23,1);
          iVar5 = *(int *)(piVar8[0x22] + 8);
          uVar13 = *(undefined4 *)(iVar6 + 0x10);
          uVar7 = piVar23[0x2e] & 1U ^ 1;
          if ((((iVar5 == 0x27) || (iVar5 == 0x29)) || (iVar5 == 0x2a)) ||
             (uVar14 = 1, iVar5 == 0x28)) {
            uVar14 = 0;
          }
        }
        local_54 = node + 0x24;
        piVar2 = (int *)node[0x26];
        for (piVar3 = (int *)((int *)node[0x26])[2]; piVar3 != (int *)0x0;
            piVar3 = (int *)piVar3[2]) {
          if (*(int *)(piVar2[0x22] + 8) == 0x8e) {
            iVar5 = FUN_001054ec(piVar2,0);
            local_60[0] = *(int *)(iVar5 + 0x10);
            operandVReg2 = FUN_00105594(piVar2,1);
            operandVReg3 = FUN_00105594(piVar2,2);
            iVar6 = 4;
            iVar5 = 0;
            local_64 = uVar13;
            do {
              if (*(char *)((int)local_60 + iVar5) == '\x01') {
                *(undefined1 *)((int)local_60 + iVar5 + -4) = 4;
              }
              iVar5 = iVar5 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            iVar5 = FUN_001054ec(piVar2,1);
            uVar17 = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = FUN_001054ec(piVar2,2);
            uVar15 = *(undefined4 *)(iVar5 + 0x10);
            iVar5 = piVar2[0x58] - *(int *)(flattenPass + 0x478);
            if (iVar5 < 0) {
              iVar5 = 0;
            }
            iVar21 = piVar2[4];
            FUN_00105b24(piVar2,flattenPass);
            FUN_0019401c(piVar2);
            FUN_00108304(piVar2,0x25,*(undefined4 *)(flattenPass + 8));
            FUN_000e7738(iVar19,piVar18,piVar2);
            iVar6 = *(int *)(flattenPass + 0x478);
            piVar2[4] = iVar21;
            piVar2[0x58] = iVar5 + iVar6;
            piVar2[0x25] = piVar2[0x53];
            piVar2[0x26] = 0;
            piVar2[0x27] = local_60[0];
            FUN_00106004(piVar2,1,piVar8,*(uint *)(flattenPass + 0x30) >> 7 & 1,
                         *(undefined4 *)(flattenPass + 8));
            uVar4 = local_64;
            iVar5 = FUN_001054ec(piVar2,1);
            *(undefined4 *)(iVar5 + 0x10) = uVar4;
            FUN_00103d50(piVar2 + 0x29,1,uVar7);
            FUN_00103d50(piVar2 + 0x29,2,uVar14);
            FUN_00106004(piVar2,2,operandVReg2,*(uint *)(flattenPass + 0x30) >> 7 & 1,
                         *(undefined4 *)(flattenPass + 8));
            iVar5 = FUN_001054ec(piVar2,2);
            *(undefined4 *)(iVar5 + 0x10) = uVar17;
            in_r7 = *(undefined4 *)(flattenPass + 8);
            in_r6 = *(uint *)(flattenPass + 0x30) >> 7 & 1;
            FUN_00106004(piVar2,3,operandVReg3,in_r6,in_r7);
            iVar5 = FUN_001054ec(piVar2,3);
            *(undefined4 *)(iVar5 + 0x10) = uVar15;
            piVar18 = piVar2;
            if (*(int *)(piVar23[0x22] + 8) == 0x8b) {
              ((int (*)())FUN_0012b3f8)(piVar23,piVar2,*(undefined4 *)(flattenPass + 8));
            }
          }
          else {
            iVar5 = (**(code **)(*piVar2 + 0x34))(piVar2);
            if (iVar5 == 0) break;
          }
          piVar2 = piVar3;
        }
        FUN_000ef970(flattenPass,piVar23);
        piVar23[5] = piVar23[5] & 0xffffffef;
        pcVar12 = *(code **)(*piVar23 + 0xc);
        uVar13 = *(undefined4 *)(flattenPass + 8);
        (*pcVar12)(piVar23,*(uint *)(flattenPass + 0x30) >> 7 & 1);
        iVar5 = FUN_001049c4(piVar8,flattenPass,uVar13,in_r6,in_r7,in_r8,pcVar12);
        if (iVar5 != 0) {
          (**(code **)(*piVar8 + 0xc))
                    (piVar8,*(uint *)(flattenPass + 0x30) >> 7 & 1,*(undefined4 *)(flattenPass + 8));
        }
        *(undefined4 *)(iVar16 + 0x130) = 0;
        if ((*(int *)(iVar16 + 0x144) != 0) && (*(int *)(iVar16 + 0x140) != 0)) {
          *(undefined4 *)(*(int *)(iVar16 + 0x140) + 0x144) = 1;
        }
        FUN_000e7658(iVar16);
        piVar23 = (int *)local_54[2];
        for (piVar8 = (int *)((int *)local_54[2])[2]; piVar8 != (int *)0x0;
            piVar8 = (int *)piVar8[2]) {
          iVar5 = (**(code **)(*piVar23 + 0x34))(piVar23);
          if (iVar5 == 0) {
            iVar5 = (**(code **)(*piVar23 + 0x38))(piVar23);
            if (iVar5 != 0) break;
            FUN_0019401c(piVar23);
            FUN_000e7738(iVar19,piVar18,piVar23);
            piVar18 = piVar23;
          }
          piVar23 = piVar8;
        }
        FUN_000e7658(node);
        iVar5 = local_58;
        do {
          changed = true;
          iVar6 = FUN_000e7f38(iVar5);
          if (((iVar19 != iVar6) && (changed = false, iVar6 == 0)) ||
             (iVar6 = FUN_0012aef0(flattenPass,iVar5,iVar6), iVar6 == 0)) {
            iVar5 = *(int *)(iVar5 + 8);
          }
        } while ((!changed) && (iVar5 != iVar19));
        changed = true;
        piVar23 = *(int **)(local_58 + 8);
      }
      node = piVar23;
      piVar23 = (int *)node[2];
    } while (piVar23 != (int *)0x0);
    if (changed) {
      FUN_000ec2e8(flattenPass);
      FUN_000ed7e4(flattenPass,(int)"flatten_ifs");
      FUN_0013bd68(flattenPass,0);
    }
  }
  return;
}

/* FUN_0012dcf0 @ 0x12dcf0 (88 bytes) */
int FUN_0012dcf0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int callResult;
  
  callResult = FUN_000e0830(*(undefined4 *)(param_2 + 8),0,0);
  if (callResult == 0) {
    ((int (*)())pass_flatten_ifs)(param_2);
    return;
  }
  return;
}

/* FUN_0012dd58 @ 0x12dd58 (512 bytes) */
int FUN_0012dd58(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int a2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar5;
  uint loopIndex;
  undefined8 uVar7;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with FUN_0019423c - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. FUN_0019423c unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vecCapacity (*(uint *)(local_44_buf + 0x00))
  #define vecCount (*(uint *)(local_44_buf + 0x04))
  #define vecData (*(undefined4 * *)(local_44_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_44_buf + 0x0c))
  
  uVar5 = *(uint *)(param_1 + 8);
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  vecArena = *(undefined4 *)(uVar5 + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  a2 = param_3;
  vecData = (undefined4 *)FUN_00193e18(vecArena,8);
  iVar1 = FUN_000e9184(param_2,0);
  FUN_00194374(*(undefined4 *)(iVar1 + 0xd0),param_2);
  iVar2 = FUN_000e920c(param_3,0);
  FUN_00194374(*(undefined4 *)(iVar2 + 0xd4),param_3);
  FUN_000e8e4c(iVar1,iVar2);
  while( true ) {
    iVar1 = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(param_2[0x34] + 4); loopIndex = loopIndex + 1) {
      iVar2 = *(int *)(*(int *)(param_2[0x34] + 8) + iVar1);
      if (((iVar2 != 0) && (uVar5 = *(uint *)(param_1 + 0x474), uVar5 != *(uint *)(iVar2 + 0x118)))
         && (param_3 != iVar2)) {
        *(uint *)(iVar2 + 0x118) = uVar5;
        if (vecCount < vecCapacity) {
          uVar5 = vecCount + 1;
          vecData[vecCount] = 0;
          piVar3 = vecData + vecCount;
          vecCount = uVar5;
        }
        else {
          piVar3 = (int *)FUN_0019423c(&vecCapacity,vecCount);
        }
        *piVar3 = iVar2;
      }
      iVar1 = iVar1 + 4;
    }
    uVar7 = (**(code **)(*param_2 + 0x24))(param_2);
    if (((int)((ulonglong)uVar7 >> 0x20) != 0) &&
       (piVar3 = (int *)FUN_000e7804(param_2,(int)uVar7,a2,in_r6,in_r7,in_r8,uVar5),
       piVar3 != (int *)0x0)) {
      FUN_000ef970(param_1,piVar3);
      a2 = *(int *)(param_1 + 8);
      (**(code **)(*piVar3 + 0xc))(piVar3,*(uint *)(param_1 + 0x30) >> 7 & 1,a2);
      param_2[0x4c] = 0;
    }
    FUN_000e7658(param_2);
    if (vecCount == 0) break;
    puVar4 = vecData;
    if (vecCapacity == 0) {
      puVar4 = (undefined4 *)FUN_0019423c(&vecCapacity,0);
    }
    param_2 = (int *)*puVar4;
    if ((param_2 == (int *)0x0) || (iVar1 = FUN_00194374(&vecCapacity,param_2), iVar1 == 0)) break;
  }
  FUN_000e7658(param_3);
  return FUN_00193cc0(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0012df90 @ 0x12df90 (1216 bytes) */
int FUN_0012df90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  dword *param_3;
  int *param_4;
  int *param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *a0;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_r4;
  uint uVar8;
  undefined4 extraout_r4_00;
  undefined4 uVar9;
  dword *pdVar10;
  int *piVar11;
  undefined4 in_r8;
  int iVar12;
  int iVar13;
  uint *puVar14;
  int *piVar15;
  undefined8 uVar16;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with FUN_0019423c - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. FUN_0019423c unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_64_buf [0x10];
  #define vecCapacity (*(uint *)(local_64_buf + 0x00))
  #define vecCount (*(uint *)(local_64_buf + 0x04))
  #define vecData (*(int *)(local_64_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_64_buf + 0x0c))
  
  if (param_2[0x53] == 1) {
    iVar13 = param_2[0x4e];
  }
  else {
    iVar13 = param_2[0x4d];
  }
  iVar12 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  vecArena = *(undefined4 *)(iVar12 + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  pdVar10 = param_3;
  piVar5 = param_4;
  piVar11 = param_5;
  vecData = FUN_00193e18(vecArena,8);
  uVar8 = vecCount;
  if (vecCount < vecCapacity) {
    iVar6 = vecCount * 4;
    pdVar10 = ((unsigned char *)0x4);
    _memset(vecData + iVar6,0,4);
    vecCount = uVar8 + 1;
    uVar16 = CONCAT44(iVar6 + vecData,extraout_r4);
  }
  else {
    uVar16 = FUN_0019423c(&vecCapacity,vecCount);
  }
  uVar9 = (undefined4)uVar16;
  *(int *)((ulonglong)uVar16 >> 0x20) = iVar13;
  *(undefined4 *)(iVar13 + 0x118) = *(undefined4 *)(param_1 + 0x474);
  while (vecCount != 0) {
    uVar8 = vecCount - 1;
    puVar1 = (undefined4 *)0x0;
    if (uVar8 < vecCount) {
      puVar1 = (undefined4 *)(uVar8 * 4 + vecData);
    }
    piVar15 = (int *)*puVar1;
    FUN_00194208(&vecCapacity,uVar8);
    iVar13 = (**(code **)(*piVar15 + 0x38))(piVar15);
    if ((iVar13 == 0) && (iVar13 = (**(code **)(*piVar15 + 0x3c))(piVar15), iVar13 == 0)) {
      iVar13 = 0;
      for (uVar8 = 1; uVar8 <= *(uint *)(piVar15[0x34] + 4); uVar8 = uVar8 + 1) {
        a0 = *(int **)(iVar13 + *(int *)(piVar15[0x34] + 8));
        if ((((a0 != (int *)0x0) && (*(int *)(param_1 + 0x474) != a0[0x46])) &&
            ((dword *)a0 != param_3)) && (a0 != param_2)) {
          iVar6 = (**(code **)(*a0 + 0x38))(a0);
          if ((iVar6 != 0) || (iVar6 = (**(code **)(*a0 + 0x3c))(a0), iVar6 != 0)) {
            piVar2 = (int *)a0[0x34];
            if (*piVar2 == 0) {
              piVar2 = (int *)FUN_0019423c(piVar2,0);
            }
            else {
              if (piVar2[1] == 0) {
                *(undefined4 *)piVar2[2] = 0;
                piVar2[1] = 1;
              }
              piVar2 = (int *)piVar2[2];
            }
            iVar6 = *piVar2;
            uVar3 = FUN_000e803c(iVar6,a0);
            puVar14 = *(uint **)(iVar6 + 0xd4);
            if (uVar3 < *puVar14) {
              uVar4 = puVar14[1];
              if (uVar4 <= uVar3) {
                pdVar10 = (dword *)((uVar3 - uVar4) * 4 + 4);
                _memset(uVar4 * 4 + puVar14[2],0,pdVar10);
                puVar14[1] = uVar3 + 1;
              }
              puVar1 = (undefined4 *)(uVar3 * 4 + puVar14[2]);
            }
            else {
              puVar1 = (undefined4 *)FUN_0019423c(puVar14,uVar3);
            }
            *puVar1 = 0;
          }
          uVar3 = vecCount;
          a0[0x46] = *(int *)(param_1 + 0x474);
          if (vecCount < vecCapacity) {
            iVar6 = vecCount * 4;
            pdVar10 = ((unsigned char *)0x4);
            _memset(iVar6 + vecData,0,4);
            vecCount = uVar3 + 1;
            puVar1 = (undefined4 *)(iVar6 + vecData);
          }
          else {
            puVar1 = (undefined4 *)FUN_0019423c(&vecCapacity,vecCount);
          }
          *puVar1 = a0;
        }
        iVar13 = iVar13 + 4;
      }
    }
    FUN_00194034(piVar15 + 0x24);
    FUN_000e7658(piVar15);
    uVar9 = extraout_r4_00;
  }
  piVar5 = (int *)FUN_000e7804(param_2,uVar9,pdVar10,piVar5,piVar11,in_r8,iVar12);
  param_2[0x4c] = 0;
  FUN_000ef970(param_1,piVar5);
  (**(code **)(*piVar5 + 0xc))(piVar5,0,*(undefined4 *)(param_1 + 8));
  FUN_00194034(param_2 + 0x24);
  iVar12 = FUN_000e7e90(param_2);
  iVar6 = FUN_000e7f38(param_3);
  iVar13 = param_2[0x53];
  iVar7 = FUN_000e920c(param_2,(uint)(iVar13 != 1));
  *param_4 = iVar7;
  piVar5 = *(int **)(iVar7 + 0xd4);
  if (*piVar5 == 0) {
    piVar5 = (int *)FUN_0019423c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  *piVar5 = iVar12;
  piVar5 = *(int **)(iVar12 + 0xd0);
  if (*piVar5 == 0) {
    piVar5 = (int *)FUN_0019423c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  *piVar5 = *param_4;
  iVar13 = FUN_000e9184(param_3,(uint)(iVar13 != 1));
  *param_5 = iVar13;
  piVar5 = *(int **)(iVar13 + 0xd0);
  if (*piVar5 == 0) {
    piVar5 = (int *)FUN_0019423c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  *piVar5 = iVar6;
  piVar5 = *(int **)(iVar6 + 0xd4);
  if (*piVar5 == 0) {
    piVar5 = (int *)FUN_0019423c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  *piVar5 = *param_5;
  FUN_000e7658(param_2);
  FUN_000e7658(param_3);
  FUN_000ec2e8(param_1);
  return FUN_00193cc0(vecArena,vecData);
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* FUN_0012e488 @ 0x12e488 (172 bytes) */
int FUN_0012e488(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *allocation;
  undefined4 *puVar4;
  undefined4 arena;
  
  puVar1 = (undefined4 *)FUN_000e920c(param_2,0);
  iVar2 = FUN_00194034(puVar1 + 0x24);
  if ((2 < iVar2) || (iVar2 = FUN_000e7770(puVar1), puVar4 = puVar1, iVar2 == 0)) {
    arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arena,0x130);
    *allocation = arena;
    puVar4 = allocation + 1;
    Block__ctor_ea020(puVar4,*(undefined4 *)(param_1 + 8));
    allocation[0x2f] = *(undefined4 *)(param_2 + 0xb8);
    FUN_000ec3ac(param_1,param_2,puVar4);
    FUN_000e977c(param_2,puVar1,puVar4);
    FUN_000e8e4c(puVar4,puVar1);
  }
  return puVar4;
}

/* FUN_0012e56c @ 0x12e56c (660 bytes) */
int FUN_0012e56c(param_1, param_2, compiler)
  undefined4 param_1;
  int *param_2;
  int compiler;
{
  undefined4 arenaAt3742;
  undefined *puVar1;
  int iVar2;
  undefined4 *allocation;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 arena;
  undefined4 arenaAt374;
  undefined4 *puVar15;
  
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,param_2,compiler);
  if (iVar2 != 0) {
    arena = *(undefined4 *)(compiler + 0x374);
    iVar7 = param_2[0x4b];
    uVar5 = *(undefined4 *)(compiler + 0x6c4);
    allocation = (undefined4 *)FUN_00193e18(arena,0x168);
    puVar6 = allocation + 1;
    *allocation = arena;
    IRInst__ctor_10502c(puVar6,0x8c,compiler);
    allocation[0x4c] = 6;
    iVar2 = FUN_001054ec(puVar6,1);
    puVar1 = PTR_DAT_001e8b8c;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    arena = *(undefined4 *)puVar1;
    *(undefined4 *)(iVar2 + 8) = param_1;
    iVar2 = FUN_001054ec(puVar6,1);
    *(undefined4 *)(iVar2 + 0x10) = arena;
    uVar11 = *(undefined4 *)(iVar7 + 0xb8);
    arena = FUN_000e920c(iVar7,0);
    arenaAt374 = *(undefined4 *)(compiler + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
    puVar8 = allocation + 1;
    *allocation = arenaAt374;
    Block__ctor_ea020(puVar8,compiler);
    allocation[0x2f] = uVar11;
    FUN_000ec3ac(uVar5,iVar7,puVar8);
    FUN_000e977c(iVar7,arena,puVar8);
    uVar11 = FUN_0012b140(iVar7);
    arenaAt374 = *(undefined4 *)(compiler + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
    puVar10 = allocation + 1;
    *allocation = arenaAt374;
    Block__ctor_ea020(puVar10,compiler);
    arenaAt374 = *(undefined4 *)(compiler + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x138);
    puVar9 = allocation + 1;
    *allocation = arenaAt374;
    BreakBlock__ctor_ec0c8(puVar9,iVar7,1,compiler);
    arenaAt374 = *(undefined4 *)(compiler + 0x374);
    allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x15c);
    puVar12 = allocation + 1;
    *allocation = arenaAt374;
    IfHeader__ctor_ea6d0(puVar12,puVar6,uVar11,puVar10,compiler);
    arenaAt3742 = *(undefined4 *)(compiler + 0x374);
    puVar4 = (undefined4 *)FUN_00193e18(arenaAt3742,0x134);
    puVar15 = puVar4 + 1;
    *puVar4 = arenaAt3742;
    Block__ctor_ea148(puVar15,compiler);
    puVar4[0x4c] = puVar12;
    *puVar15 = PTR_DAT_001e9130 + 8;
    allocation[0x4e] = puVar10;
    allocation[0x4f] = puVar9;
    allocation[0x50] = puVar15;
    FUN_000ec3ac(uVar5,puVar8,puVar12);
    FUN_000ec3ac(uVar5,puVar12,puVar10);
    FUN_000ec3ac(uVar5,puVar10,puVar9);
    FUN_000ec3ac(uVar5,puVar9,puVar15);
    FUN_000e8e4c(puVar8,puVar12);
    FUN_000e8e4c(puVar12,puVar10);
    FUN_000e8e4c(puVar12,puVar9);
    FUN_000e8e4c(puVar10,puVar15);
    FUN_000e8e4c(puVar9,*(undefined4 *)(iVar7 + 0x154));
    FUN_000e8e4c(puVar15,arena);
    FUN_000ed63c(uVar5,puVar6);
    return;
  }
  return;
}

/* FUN_0012e8c0 @ 0x12e8c0 (304 bytes) */
int FUN_0012e8c0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar6;
  
  piVar1 = param_2;
  do {
    if (piVar1 == param_3) {
      return;
    }
    piVar1 = (int *)FUN_000e920c(param_2,0);
    iVar2 = FUN_0012aef0(param_1,param_2,piVar1);
    if (iVar2 == 0) {
      param_2 = (int *)param_2[2];
    }
    iVar2 = (**(code **)(*param_2 + 0x28))(param_2);
    if (((iVar2 != 0) || (iVar2 = (**(code **)(*param_2 + 0x34))(param_2), iVar2 != 0)) &&
       (iVar2 = FUN_000e7f38(param_2), iVar2 == 0)) {
      uVar3 = FUN_000e920c(param_2,0);
      arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      allocation = (undefined4 *)FUN_00193e18(arena,0x130);
      *allocation = arena;
      puVar6 = allocation + 1;
      Block__ctor_ea020(puVar6,*(undefined4 *)(param_1 + 8));
      allocation[0x2f] = param_2[0x2e];
      FUN_000ec3ac(param_1,param_2,puVar6);
      FUN_000e9adc(param_2,uVar3,puVar6);
    }
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (((iVar2 != 0) || (iVar2 = (**(code **)(*param_2 + 0x2c))(param_2), iVar2 != 0)) &&
       (iVar2 = FUN_000e7e90(param_2), iVar2 == 0)) {
      uVar3 = FUN_000e9184(param_2,0);
      arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      allocation = (undefined4 *)FUN_00193e18(arena,0x130);
      *allocation = arena;
      puVar6 = allocation + 1;
      Block__ctor_ea020(puVar6,*(undefined4 *)(param_1 + 8));
      allocation[0x2f] = param_2[0x2e];
      FUN_000ec370(param_1,param_2,puVar6);
      FUN_000e9adc(uVar3,param_2,puVar6);
    }
  } while (param_2 != param_3);
  return;
}

/* FUN_0012eacc @ 0x12eacc (1428 bytes) */
int FUN_0012eacc(param_1)
  int param_1;
{
  undefined4 arenaAt374;
  undefined4 arenaAt3742;
  undefined4 arenaAt3743;
  undefined4 *blockAlloc2;
  undefined4 *blockAlloc;
  undefined4 *instAlloc;
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *allocation;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 arena;
  uint loopIndex;
  double fparam_1;
  
  if (*(int *)(*(int *)(param_1 + 0x414) + 4) == 0) {
    return;
  }
  arena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  allocation = (undefined4 *)FUN_00193e18(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  arena = FUN_00193e18(arena,8);
  allocation[3] = arena;
  iVar23 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar23;
  arena = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  iVar5 = FUN_001054ec(arena,0);
  *(int *)(iVar5 + 8) = iVar23;
  fparam_1 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(iVar5 + 0xc) = 0;
  ((void (*)())FUN_000f79c4)(arena,param_1,1,fparam_1,fparam_1,fparam_1,fparam_1);
  FUN_000f92fc(param_1,arena,*(undefined4 *)(param_1 + 0x3a0));
  iVar24 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar24;
  iVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  iVar23 = FUN_001054ec(iVar5,0);
  *(undefined4 *)(iVar23 + 0xc) = 0;
  *(int *)(iVar23 + 8) = iVar24;
  FUN_000f7870(iVar5,param_1,1,0xffffffff,0xffffffff,0xffffffff,0xffffffff);
  FUN_000f92fc(param_1,iVar5,*(undefined4 *)(param_1 + 0x3a0));
  do {
    iVar23 = *(int *)(param_1 + 0x414);
    uVar11 = *(uint *)(iVar23 + 4);
    if (uVar11 == 0) {
      piVar12 = *(int **)(param_1 + 0x3a0);
      piVar14 = *(int **)(param_1 + 0x3a8);
      piVar3 = piVar12;
      do {
        if (piVar3 == piVar14) {
          return;
        }
        piVar3 = (int *)FUN_000e920c(piVar12,0);
        iVar5 = FUN_0012aef0(param_1,piVar12,piVar3);
        if (iVar5 == 0) {
          piVar12 = (int *)piVar12[2];
        }
        iVar5 = (**(code **)(*piVar12 + 0x28))(piVar12);
        if (((iVar5 != 0) || (iVar5 = (**(code **)(*piVar12 + 0x34))(piVar12), iVar5 != 0)) &&
           (iVar5 = FUN_000e7f38(piVar12), iVar5 == 0)) {
          arena = FUN_000e920c(piVar12,0);
          arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
          *allocation = arenaAt374;
          puVar8 = allocation + 1;
          Block__ctor_ea020(puVar8,*(undefined4 *)(param_1 + 8));
          allocation[0x2f] = piVar12[0x2e];
          FUN_000ec3ac(param_1,piVar12,puVar8);
          FUN_000e9adc(piVar12,arena,puVar8);
        }
        iVar5 = (**(code **)(*piVar12 + 0x24))(piVar12);
        if (((iVar5 != 0) || (iVar5 = (**(code **)(*piVar12 + 0x2c))(piVar12), iVar5 != 0)) &&
           (iVar5 = FUN_000e7e90(piVar12), iVar5 == 0)) {
          arena = FUN_000e9184(piVar12,0);
          arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          allocation = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
          *allocation = arenaAt374;
          puVar8 = allocation + 1;
          Block__ctor_ea020(puVar8,*(undefined4 *)(param_1 + 8));
          allocation[0x2f] = piVar12[0x2e];
          FUN_000ec370(param_1,piVar12,puVar8);
          FUN_000e9adc(arena,piVar12,puVar8);
        }
      } while (piVar12 != piVar14);
      return;
    }
    piVar12 = (int *)0x0;
    if (uVar11 - 1 < uVar11) {
      piVar12 = (int *)((uVar11 - 1) * 4 + *(int *)(iVar23 + 8));
    }
    iVar24 = *piVar12;
    FUN_00194208(iVar23,uVar11 - 1);
    uVar19 = *(undefined4 *)(iVar24 + 0x158);
    iVar23 = FUN_0012b140(uVar19);
    uVar20 = *(undefined4 *)(iVar23 + 0x13c);
    uVar11 = (uint)(*(int *)(*(int *)(iVar24 + 0x88) + 8) != 0xf8);
    if (uVar11 == 0) {
      uVar15 = *(undefined4 *)(iVar24 + 300);
      uVar16 = 0;
      iVar6 = FUN_0012ac58(uVar15,uVar20);
LAB_0012ed5c:
      uVar17 = 0;
      if (iVar6 != 0) {
        uVar17 = FUN_0012b248(arena,iVar6,param_1);
      }
    }
    else {
      do {
        iVar23 = FUN_0012b140(iVar23);
      } while (*(int *)(iVar23 + 0x150) == 0);
      uVar22 = allocation[2];
      loopIndex = 0;
      if (uVar22 != 0) {
        do {
          if (loopIndex < (uint)allocation[1]) {
            if (uVar22 <= loopIndex) {
              _memset(uVar22 * 4 + allocation[3],0,(loopIndex - uVar22) * 4 + 4);
              allocation[2] = loopIndex + 1;
            }
            piVar12 = (int *)(loopIndex * 4 + allocation[3]);
          }
          else {
            piVar12 = (int *)FUN_0019423c(allocation + 1,loopIndex);
          }
          if (*piVar12 == iVar23) {
            bVar1 = true;
            goto LAB_0012ed24;
          }
          uVar22 = allocation[2];
          loopIndex = loopIndex + 1;
        } while (loopIndex < uVar22);
      }
      bVar1 = false;
LAB_0012ed24:
      iVar6 = *(int *)(iVar23 + 0x134);
      uVar16 = *(undefined4 *)(iVar23 + 0x13c);
      uVar15 = 0xffffffff;
      if (!bVar1) goto LAB_0012ed5c;
      iVar23 = FUN_000e83bc(uVar19);
      uVar17 = *(undefined4 *)(iVar23 + 0x94);
    }
    uVar7 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar23 = FUN_001054ec(uVar7,0);
    uVar13 = *(undefined4 *)(iVar5 + 0x8c);
    *(undefined4 *)(iVar23 + 0xc) = 0;
    *(undefined4 *)(iVar23 + 8) = uVar17;
    FUN_001046c8(uVar7,1,uVar13);
    FUN_000ed63c(param_1,uVar7);
    FUN_000e7738(uVar19,iVar24,uVar7);
    FUN_0019401c(iVar24);
    while( true ) {
      while( true ) {
        uVar20 = ((int (*)())FUN_0012e488)(param_1,uVar20);
        iVar23 = FUN_000e920c(uVar20,0);
        iVar24 = FUN_0012afe8(uVar11,uVar15,iVar23,uVar16);
        uVar20 = FUN_0012b140(iVar23);
        if (iVar23 != iVar24) break;
        ((int (*)())FUN_0012e56c)(uVar17,iVar23,*(undefined4 *)(param_1 + 8));
        uVar20 = FUN_0012ae1c(iVar23);
      }
      if (iVar24 == 0) break;
      arenaAt3742 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      instAlloc = (undefined4 *)FUN_00193e18(arenaAt3742,0x168);
      *instAlloc = arenaAt3742;
      puVar18 = instAlloc + 1;
      IRInst__ctor_10502c(puVar18,0x8c,*(undefined4 *)(param_1 + 8));
      instAlloc[0x4c] = 6;
      iVar6 = FUN_001054ec(puVar18,1);
      puVar2 = PTR_DAT_001e8b8c;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      uVar19 = *(undefined4 *)puVar2;
      *(undefined4 *)(iVar6 + 8) = uVar17;
      iVar6 = FUN_001054ec(puVar18,1);
      *(undefined4 *)(iVar6 + 0x10) = uVar19;
      uVar19 = FUN_000e9184(iVar24,0);
      puVar9 = (undefined4 *)FUN_000e9184(iVar23,0);
      arenaAt3743 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      uVar7 = *(undefined4 *)(iVar23 + 0xb8);
      puVar10 = (undefined4 *)FUN_00193e18(arenaAt3743,0x15c);
      *puVar10 = arenaAt3743;
      puVar21 = puVar10 + 1;
      IfHeader__ctor_ea6d0(puVar21,puVar18,uVar20,iVar23,*(undefined4 *)(param_1 + 8));
      iVar6 = FUN_000e7770(puVar9);
      puVar8 = puVar9;
      if (iVar6 == 0) {
        arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        blockAlloc = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
        *blockAlloc = arenaAt374;
        puVar8 = blockAlloc + 1;
        Block__ctor_ea020(puVar8,*(undefined4 *)(param_1 + 8));
        FUN_000e977c(puVar9,iVar23,puVar8);
        FUN_000e9948(puVar21,iVar23,puVar8);
        FUN_000ec3ac(param_1,puVar9,puVar8);
      }
      FUN_000ec3ac(param_1,puVar8,puVar21);
      arenaAt374 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      blockAlloc2 = (undefined4 *)FUN_00193e18(arenaAt374,0x130);
      *blockAlloc2 = arenaAt374;
      puVar9 = blockAlloc2 + 1;
      Block__ctor_ea020(puVar9,*(undefined4 *)(param_1 + 8));
      puVar10[0x4f] = puVar9;
      FUN_000ec3ac(param_1,uVar19,puVar9);
      uVar20 = puVar10[0x50];
      FUN_000ec3ac(param_1,puVar9,uVar20);
      FUN_000e78c0(puVar21,uVar7);
      FUN_000e8e4c(puVar21,puVar9);
      FUN_000e977c(puVar8,iVar23,puVar21);
      FUN_000e8e4c(puVar9,uVar20);
      FUN_000e977c(uVar19,iVar24,uVar20);
      FUN_000e8e4c(uVar20,iVar24);
      FUN_000ed63c(param_1,puVar18);
      ((int (*)())FUN_0012e56c)(uVar17,iVar24,*(undefined4 *)(param_1 + 8));
      uVar20 = FUN_0012ae1c(iVar24);
    }
  } while( true );
}

/* FUN_0012f0f8 @ 0x12f0f8 (3356 bytes) */
int FUN_0012f0f8(pass, param_2, param_3, param_4, param_5, param_6)
  int pass;
  int param_2;
  int param_3;
  int *param_4;
  int *param_5;
  int *param_6;
{
  int isLoopHeader;
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *allocation;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  int *piVar18;
  int *piVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  undefined4 arena;
  int *piVar27;
  uint *puVar28;
  undefined8 isIfHeader;
  int iStack0000001c;
  int local_68;
  int local_64;
  undefined4 local_60;
  
  piVar19 = param_6;
  iStack0000001c = param_2;
  iVar5 = FUN_000e07dc(*(undefined4 *)(pass + 8),2);
  if ((((iVar5 != 0) && (iVar5 = FUN_000e9cc8(param_3), iVar5 != 0)) &&
      (*(int *)(param_3 + 0x138) < 1)) && (*(int *)(param_3 + 0x13c) == 0)) {
    iVar6 = FUN_000e8c7c(param_3);
    iVar7 = FUN_000e8c14(param_3);
    iVar8 = FUN_000e8bac(param_3);
    arena = *(undefined4 *)(pass + 8);
    iVar5 = iVar8;
    iVar4 = param_3;
    iVar9 = FUN_0012aa78(arena,iVar6,iVar7,iVar8,param_3);
    if (iVar9 == 0) {
      FUN_0012aae0(arena,iVar6);
      *(int *)(pass + 0x98) = *(int *)(pass + 0x98) + 1;
      iVar10 = FUN_000e7e90(param_3);
      local_60 = *(undefined4 *)(param_3 + 8);
      iVar9 = *param_4;
      if (iVar6 == 0) {
        while (param_3 != iVar9) {
          iVar5 = *(int *)(iVar9 + 4);
          piVar19 = *(int **)(iVar9 + 0x98);
          for (piVar27 = (int *)(*(int **)(iVar9 + 0x98))[2]; piVar27 != (int *)0x0;
              piVar27 = (int *)piVar27[2]) {
            if ((piVar19[5] & 1U) != 0) {
              iVar4 = (**(code **)(*piVar19 + 0x34))(piVar19);
              if ((iVar4 == 0) && (iVar4 = (**(code **)(*piVar19 + 0x38))(piVar19), iVar4 == 0)) {
                iVar4 = 1;
                piVar27 = piVar19;
                while( true ) {
                  iVar7 = (**(code **)(*piVar19 + 0x14))(piVar19);
                  if (iVar7 < iVar4) break;
                  iVar4 = iVar4 + 1;
                  FUN_001234d8(piVar27[0x29],piVar19);
                  piVar27 = piVar27 + 6;
                }
                (**(code **)(*piVar19 + 0xc))(piVar19,0,*(undefined4 *)(pass + 8));
                piVar27 = (int *)piVar19[2];
              }
              else {
                piVar27 = (int *)piVar19[2];
              }
            }
            piVar19 = piVar27;
          }
          FUN_000e7658(iVar9);
          iVar9 = iVar5;
        }
        *param_4 = iVar10;
        local_60 = *(undefined4 *)(param_3 + 8);
      }
      else {
        if ((1 < iVar6) && (param_3 != iVar9)) {
          iVar23 = 0;
          iVar25 = param_3;
          do {
            iVar25 = *(int *)(iVar25 + 8);
            *(int *)(iVar25 + 0xc0) = iVar23;
            iVar23 = iVar23 + 1;
          } while (iVar9 != iVar25);
        }
        bVar2 = param_3 != iVar9;
        iVar23 = *(int *)(param_3 + 0x14c);
        iVar25 = param_3;
        bVar1 = bVar2;
        while (bVar1) {
          piVar27 = *(int **)(iVar25 + 8);
          piVar27[0x2e] = piVar27[0x2e] + -1;
          iVar11 = (**(code **)(*piVar27 + 0x2c))(piVar27);
          if ((iVar11 != 0) && (param_3 == piVar27[0x53])) {
            piVar27[0x53] = iVar23;
          }
          iVar25 = *(int *)(iVar25 + 8);
          bVar1 = iVar9 != iVar25;
        }
        arena = *(undefined4 *)(*(int *)(pass + 8) + 0x378);
        allocation = (undefined4 *)FUN_00193e18(arena,0x14);
        puVar28 = allocation + 1;
        allocation[1] = 2;
        *allocation = arena;
        allocation[2] = 0;
        allocation[4] = arena;
        arena = FUN_00193e18(arena,8);
        allocation[3] = arena;
        if (1 < iVar6) {
          local_68 = 1;
          iVar25 = iVar9;
          local_64 = iVar7;
          do {
            local_64 = local_64 + iVar8;
            if (bVar2) {
              iVar23 = param_3;
              uVar24 = 0;
              do {
                uVar21 = uVar24;
                piVar27 = *(int **)(iVar23 + 8);
                iVar11 = (**(code **)(*piVar27 + 8))(piVar27);
                if (uVar21 < *puVar28) {
                  uVar24 = allocation[2];
                  if (uVar24 <= uVar21) {
                    _memset(uVar24 * 4 + allocation[3],0,(uVar21 - uVar24) * 4 + 4);
                    allocation[2] = uVar21 + 1;
                  }
                  piVar18 = (int *)(uVar21 * 4 + allocation[3]);
                }
                else {
                  piVar18 = (int *)FUN_0019423c(puVar28,uVar21);
                }
                *piVar18 = iVar11;
                piVar18 = (int *)piVar27[0x26];
                for (piVar14 = (int *)((int *)piVar27[0x26])[2]; piVar14 != (int *)0x0;
                    piVar14 = (int *)piVar14[2]) {
                  uVar24 = piVar18[5] & 1;
                  if (uVar24 != 0) {
                    iVar22 = (**(code **)(*piVar18 + 0x34))(piVar18);
                    if (iVar22 == 0) {
                      iVar22 = (**(code **)(*piVar18 + 0x38))(piVar18);
                      if (iVar22 != 0) break;
                      iVar22 = 0;
                      iVar3 = FUN_0010445c(piVar18,*(undefined4 *)(pass + 8),0);
                      if ((*(int *)(param_3 + 0x134) == 0) &&
                         (iVar13 = FUN_0012ab04(iVar3), iVar13 != 0)) {
                        iVar22 = pass;
                        ((int (*)())FUN_0012c3d0)(iVar3,local_64,pass);
                      }
                      if ((*(uint *)(iVar3 + 0x14) & 0x10) != 0) {
                        FUN_000ee9ac(pass,iVar3);
                      }
                      isIfHeader = (**(code **)(*piVar27 + 0x24))(piVar27);
                      if (((int)((ulonglong)isIfHeader >> 0x20) != 0) &&
                         (piVar14 = (int *)FUN_000e7804(piVar27,(int)isIfHeader,iVar22,iVar5,iVar4,
                                                        piVar19,uVar24), piVar18 == piVar14)) {
                        *(int *)(iVar11 + 0x130) = iVar3;
                      }
                      isLoopHeader = (**(code **)(*piVar27 + 0x2c))(piVar27);
                      if ((isLoopHeader != 0) && (piVar18 == (int *)piVar27[0x52])) {
                        *(int *)(iVar11 + 0x148) = iVar3;
                      }
                      FUN_000f92fc(pass,iVar3,iVar11);
                      piVar14 = (int *)piVar18[2];
                    }
                    else {
                      piVar14 = (int *)piVar18[2];
                    }
                  }
                  piVar18 = piVar14;
                }
                FUN_000ec3ac(pass,*param_4,iVar11);
                *param_4 = iVar11;
                iVar23 = *(int *)(iVar23 + 8);
                uVar24 = uVar21 + 1;
              } while (iVar9 != iVar23);
            }
            else {
              uVar21 = 0xffffffff;
            }
            iVar23 = *(int *)(param_3 + 8);
            if (0 < (int)uVar21) {
              uVar24 = 0;
              iVar11 = 1;
              do {
                if (uVar24 < *puVar28) {
                  uVar15 = allocation[2];
                  if (uVar15 <= uVar24) {
                    _memset(uVar15 * 4 + allocation[3],0,(uVar24 - uVar15) * 4 + 4);
                    allocation[2] = iVar11;
                  }
                }
                else {
                  FUN_0019423c(puVar28,uVar24);
                }
                iVar22 = 0;
                for (uVar15 = 1; uVar15 <= *(uint *)(*(int *)(iVar23 + 0xd0) + 4);
                    uVar15 = uVar15 + 1) {
                  iVar3 = *(int *)(iVar22 + *(int *)(*(int *)(iVar23 + 0xd0) + 8));
                  if (iVar3 != 0) {
                    uVar20 = *puVar28;
                    if (uVar24 < uVar20) {
                      uVar16 = allocation[2];
                      if (uVar16 <= uVar24) {
                        _memset(uVar16 * 4 + allocation[3],0,(uVar24 - uVar16) * 4 + 4);
                        uVar20 = *puVar28;
                        allocation[2] = iVar11;
                      }
                      puVar17 = (undefined4 *)(uVar24 * 4 + allocation[3]);
                    }
                    else {
                      puVar17 = (undefined4 *)FUN_0019423c(puVar28,uVar24);
                      uVar20 = *puVar28;
                    }
                    arena = *puVar17;
                    uVar16 = *(uint *)(iVar3 + 0xc0);
                    if (uVar16 < uVar20) {
                      uVar20 = allocation[2];
                      if (uVar20 <= uVar16) {
                        _memset(uVar20 * 4 + allocation[3],0,(uVar16 - uVar20) * 4 + 4);
                        allocation[2] = uVar16 + 1;
                      }
                      puVar17 = (undefined4 *)(uVar16 * 4 + allocation[3]);
                    }
                    else {
                      puVar17 = (undefined4 *)FUN_0019423c(puVar28,uVar16);
                    }
                    FUN_000e8e4c(arena,*puVar17);
                  }
                  iVar22 = iVar22 + 4;
                }
                uVar24 = uVar24 + 1;
                iVar23 = *(int *)(iVar23 + 8);
                iVar11 = iVar11 + 1;
              } while (uVar21 != uVar24);
            }
            if (*puVar28 == 0) {
              puVar17 = (undefined4 *)FUN_0019423c(puVar28,0);
            }
            else {
              if (allocation[2] == 0) {
                *(undefined4 *)allocation[3] = 0;
                allocation[2] = 1;
              }
              puVar17 = (undefined4 *)allocation[3];
            }
            FUN_000e8e4c(iVar25,*puVar17);
            iVar25 = param_3;
            bVar1 = bVar2;
            while (bVar1) {
              iVar23 = *(int *)(iVar25 + 8);
              uVar24 = *(uint *)(iVar23 + 0xc0);
              if (uVar24 < *puVar28) {
                uVar21 = allocation[2];
                if (uVar21 <= uVar24) {
                  _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                  allocation[2] = uVar24 + 1;
                }
                puVar17 = (undefined4 *)(uVar24 * 4 + allocation[3]);
              }
              else {
                puVar17 = (undefined4 *)FUN_0019423c(puVar28,uVar24);
              }
              piVar27 = (int *)*puVar17;
              iVar11 = (**(code **)(*piVar27 + 0x24))(piVar27);
              if (iVar11 == 0) {
                iVar11 = (**(code **)(*piVar27 + 0x28))(piVar27);
                if (iVar11 == 0) {
                  iVar11 = (**(code **)(*piVar27 + 0x2c))(piVar27);
                  if (iVar11 == 0) {
                    iVar11 = (**(code **)(*piVar27 + 0x30))(piVar27);
                    if (((iVar11 != 0) ||
                        (iVar11 = (**(code **)(*piVar27 + 0x34))(piVar27), iVar11 != 0)) ||
                       (iVar11 = (**(code **)(*piVar27 + 0x38))(piVar27), iVar11 != 0))
                    goto LAB_0012fafc;
                    (**(code **)(*piVar27 + 0x3c))(piVar27);
                  }
                  else {
                    uVar24 = *(uint *)(*(int *)(iVar23 + 0x150) + 0xc0);
                    if (uVar24 < *puVar28) {
                      uVar21 = allocation[2];
                      if (uVar21 <= uVar24) {
                        _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                        allocation[2] = uVar24 + 1;
                      }
                      piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                    }
                    else {
                      piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                    }
                    iVar23 = *(int *)(iVar23 + 0x154);
                    piVar27[0x54] = *piVar18;
                    uVar24 = *(uint *)(iVar23 + 0xc0);
                    if (uVar24 < *puVar28) {
                      uVar21 = allocation[2];
                      if (uVar21 <= uVar24) {
                        _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                        allocation[2] = uVar24 + 1;
                      }
                      piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                    }
                    else {
                      piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                    }
                    piVar27[0x55] = *piVar18;
                  }
                }
                else {
LAB_0012fafc:
                  uVar24 = *(uint *)(*(int *)(iVar23 + 300) + 0xc0);
                  if (uVar24 < *puVar28) {
                    uVar21 = allocation[2];
                    if (uVar21 <= uVar24) {
                      _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                      allocation[2] = uVar24 + 1;
                    }
                    piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                  }
                  else {
                    piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                  }
                  piVar27[0x4b] = *piVar18;
                }
              }
              else {
                uVar24 = *(uint *)(*(int *)(iVar23 + 0x13c) + 0xc0);
                if (uVar24 < *puVar28) {
                  uVar21 = allocation[2];
                  if (uVar21 <= uVar24) {
                    _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                    allocation[2] = uVar24 + 1;
                  }
                  piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                }
                else {
                  piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                }
                iVar11 = *(int *)(iVar23 + 0x134);
                piVar27[0x4f] = *piVar18;
                uVar24 = *(uint *)(iVar11 + 0xc0);
                if (uVar24 < *puVar28) {
                  uVar21 = allocation[2];
                  if (uVar21 <= uVar24) {
                    _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                    allocation[2] = uVar24 + 1;
                  }
                  piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                }
                else {
                  piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                }
                iVar23 = *(int *)(iVar23 + 0x138);
                piVar27[0x4d] = *piVar18;
                uVar24 = *(uint *)(iVar23 + 0xc0);
                if (uVar24 < *puVar28) {
                  uVar21 = allocation[2];
                  if (uVar21 <= uVar24) {
                    _memset(uVar21 * 4 + allocation[3],0,(uVar24 - uVar21) * 4 + 4);
                    allocation[2] = uVar24 + 1;
                  }
                  piVar18 = (int *)(uVar24 * 4 + allocation[3]);
                }
                else {
                  piVar18 = (int *)FUN_0019423c(puVar28,uVar24);
                }
                piVar27[0x4e] = *piVar18;
              }
              iVar25 = *(int *)(iVar25 + 8);
              bVar1 = iVar9 != iVar25;
            }
            local_68 = local_68 + 1;
            iVar25 = *param_4;
          } while (iVar6 != local_68);
        }
        iVar5 = param_3;
        if (*(int *)(param_3 + 0x134) == 0) {
          while (bVar2) {
            iVar25 = *(int *)(iVar5 + 8);
            iVar4 = *(int *)(*(int *)(iVar25 + 0x98) + 8);
            iVar8 = *(int *)(iVar25 + 0x98);
            if (iVar4 != 0) {
              do {
                iVar25 = iVar4;
                if ((*(uint *)(iVar8 + 0x14) & 1) != 0) {
                  iVar4 = FUN_0012ab04(iVar8);
                  if (iVar4 == 0) {
                    iVar25 = *(int *)(iVar8 + 8);
                  }
                  else {
                    ((int (*)())FUN_0012c3d0)(iVar8,iVar7,pass);
                    iVar25 = *(int *)(iVar8 + 8);
                  }
                }
                iVar4 = *(int *)(iVar25 + 8);
                iVar8 = iVar25;
              } while (*(int *)(iVar25 + 8) != 0);
              iVar25 = *(int *)(iVar5 + 8);
            }
            bVar2 = iVar9 != iVar25;
            iVar5 = iVar25;
          }
        }
      }
      FUN_00194208(iStack0000001c,*(int *)(iStack0000001c + 4) + -1);
      *param_6 = *param_6 + -1;
      piVar19 = *(int **)(param_3 + 0x98);
      piVar27 = (int *)(*(int **)(param_3 + 0x98))[2];
      do {
        if (piVar27 == (int *)0x0) {
          FUN_000e93ac(param_3,iVar10,local_60);
          if (iVar6 == 0) {
            FUN_000e79d0(iVar10);
          }
          else {
            FUN_000e79d0(iVar10);
            FUN_000e79dc(local_60);
          }
          piVar19 = *(int **)(param_3 + 0x150);
          if (piVar19 != (int *)0x0) {
            (**(code **)(*piVar19 + 4))(piVar19);
          }
          piVar19 = *(int **)(param_3 + 0x154);
          if (piVar19 != (int *)0x0) {
            (**(code **)(*piVar19 + 4))(piVar19);
          }
          FUN_000e7658(param_3);
          arena = *(undefined4 *)(*(int *)(pass + 8) + 0x374);
          allocation = (undefined4 *)FUN_00193e18(arena,0x130);
          *allocation = arena;
          Block__ctor_ea020(allocation + 1,*(undefined4 *)(pass + 8));
          *param_5 = (int)(allocation + 1);
          allocation[0x2f] = *param_6;
          FUN_000ec3ac(pass,*param_4,*param_5);
          FUN_000e8e4c(*param_4,*param_5);
          ((int (*)())FUN_0012e8c0)(pass,iVar10,*param_4);
          *param_4 = *param_5;
          return 1;
        }
        if ((piVar19[5] & 1U) != 0) {
          iVar5 = (**(code **)(*piVar19 + 0x3c))(piVar19);
          if (iVar5 == 0) {
            if (*(int *)(piVar19[0x22] + 4) == 3) {
              if (*(int *)(param_3 + 0x134) == 0) goto LAB_0012fc9c;
              FUN_001234d8(piVar19[0x29],piVar19);
              FUN_0019401c(piVar19);
              iVar5 = *(int *)(param_3 + 0x14c);
              FUN_001046c8(piVar19,1,*(undefined4 *)(*(int *)(iVar5 + 0x148) + 0x8c));
              FUN_000ed63c(pass,piVar19);
              FUN_000e7688(iVar5,piVar19);
              piVar27 = (int *)piVar19[2];
            }
            else {
              piVar27 = (int *)piVar19[2];
            }
          }
          else {
LAB_0012fc9c:
            FUN_001234d8(piVar19[0x29],piVar19);
            (**(code **)(*piVar19 + 0xc))(piVar19,0,*(undefined4 *)(pass + 8));
            piVar27 = (int *)piVar19[2];
          }
        }
        piVar19 = piVar27;
        piVar27 = (int *)piVar27[2];
      } while( true );
    }
  }
  return 0;
}

/* FUN_0012fe8c @ 0x12fe8c (476 bytes) */
int FUN_0012fe8c(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint loopIndex;
  undefined4 uVar6;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with FUN_0019423c - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. FUN_0019423c unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_44_buf [0x10];
  #define vecCapacity (*(uint *)(local_44_buf + 0x00))
  #define vecCount (*(uint *)(local_44_buf + 0x04))
  #define vecData (*(undefined4 * *)(local_44_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_44_buf + 0x0c))
  
  iVar2 = FUN_00194034(param_3 + 0x90);
  if (2 < iVar2) {
    return 0;
  }
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  vecArena = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  vecCount = 0;
  vecCapacity = 2;
  vecData = (undefined4 *)FUN_00193e18(vecArena,8);
  do {
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_00194034(param_2 + 0x24);
      if (((2 < iVar2) || (iVar2 = (**(code **)(*param_2 + 0x38))(param_2), iVar2 != 0)) ||
         (iVar2 = (**(code **)(*param_2 + 0x3c))(param_2), iVar2 != 0)) goto LAB_00130080;
    }
    else {
      iVar2 = FUN_00194034(param_2 + 0x24);
      if (3 < iVar2) {
LAB_00130080:
        uVar6 = 0;
        goto code_r0x0013008c;
      }
    }
    iVar2 = 0;
    for (loopIndex = 1; loopIndex <= *(uint *)(param_2[0x34] + 4); loopIndex = loopIndex + 1) {
      iVar1 = *(int *)(*(int *)(param_2[0x34] + 8) + iVar2);
      if (((iVar1 != 0) && (*(int *)(param_1 + 0x474) != *(int *)(iVar1 + 0x118))) &&
         (param_3 != iVar1)) {
        *(int *)(iVar1 + 0x118) = *(int *)(param_1 + 0x474);
        if (vecCount < vecCapacity) {
          vecData[vecCount] = 0;
          piVar3 = vecData + vecCount;
          vecCount = vecCount + 1;
        }
        else {
          piVar3 = (int *)FUN_0019423c(&vecCapacity,vecCount);
        }
        *piVar3 = iVar1;
      }
      iVar2 = iVar2 + 4;
    }
    if (vecCount == 0) {
LAB_00130088:
      uVar6 = 1;
code_r0x0013008c:
      FUN_00193cc0(vecArena,vecData);
      return uVar6;
    }
    puVar4 = vecData;
    if (vecCapacity == 0) {
      puVar4 = (undefined4 *)FUN_0019423c(&vecCapacity,0);
    }
    param_2 = (int *)*puVar4;
    if ((param_2 == (int *)0x0) || (iVar2 = FUN_00194374(&vecCapacity,param_2), iVar2 == 0))
    goto LAB_00130088;
  } while( true );
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena

/* pass_remove_empty_graphs @ 0x1300b0 (836 bytes) */
int pass_remove_empty_graphs(program)
  int program;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *in_r9;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined8 uVar10;
  
  while( true ) {
    piVar8 = (int *)(*(int **)(program + 900))[2];
    if (piVar8 == (int *)0x0) break;
    bVar1 = false;
    piVar9 = *(int **)(program + 900);
    do {
      piVar3 = piVar8;
      iVar2 = (**(code **)(*piVar9 + 0x24))(piVar9);
      if (iVar2 == 0) {
        iVar2 = FUN_000e7770(piVar9);
        if ((((iVar2 != 0) && (iVar2 = FUN_00194034(piVar9 + 0x24), iVar2 < 3)) &&
            (iVar2 = FUN_000e79dc(piVar9), iVar2 == 1)) &&
           (iVar2 = FUN_000e79d0(piVar9), iVar2 == 1)) {
          piVar4 = (int *)FUN_000e9184(piVar9,0);
          piVar8 = (int *)FUN_000e920c(piVar9,0);
          iVar2 = FUN_000e7770(piVar4);
          if (((iVar2 != 0) || (iVar2 = (**(code **)(*piVar4 + 0x1c))(piVar4), iVar2 != 0)) &&
             ((iVar2 = FUN_000e7770(piVar8), iVar2 != 0 ||
              (iVar2 = (**(code **)(*piVar8 + 0x20))(piVar8), iVar2 != 0)))) {
            FUN_000e9730(piVar9,piVar4,piVar8);
            goto LAB_0013037c;
          }
        }
      }
      else {
        iVar5 = piVar9[0x4f];
        iVar7 = piVar9[0x4d];
        iVar6 = piVar9[0x4e];
        iVar2 = iVar5;
        uVar10 = ((int (*)())FUN_0012fe8c)(program,piVar9,iVar5);
        if ((int)((ulonglong)uVar10 >> 0x20) == 0) {
          iVar2 = FUN_000e07dc(*(undefined4 *)(program + 8),0x21);
          if (((iVar2 != 0) && (iVar2 = FUN_000e79a0(iVar7), iVar2 == 0)) &&
             ((iVar2 = FUN_000e920c(iVar7,0), iVar2 == iVar5 &&
              ((iVar2 = FUN_00194034(iVar7 + 0x90), iVar2 < 3 &&
               (iVar2 = FUN_00194034(iVar6 + 0x90), 2 < iVar2)))))) {
            FUN_0012abd8(program,piVar9);
            piVar3 = (int *)piVar9[0x4d];
            bVar1 = true;
          }
        }
        else {
          piVar8 = (int *)FUN_000e7804(piVar9,(int)uVar10,iVar2,in_r6,in_r7,in_r8,in_r9);
          if (piVar8 != (int *)0x0) {
            FUN_000ef970(program,piVar8);
            piVar8[5] = piVar8[5] & 0xffffffef;
            in_r9 = *(code **)(*piVar8 + 0xc);
            (*in_r9)(piVar8,*(uint *)(program + 0x30) >> 7 & 1,*(undefined4 *)(program + 8),in_r6,
                     in_r7,in_r8,in_r9);
            piVar9[0x4c] = 0;
          }
          piVar9[3] = piVar9[3] | 0x100;
          piVar3 = (int *)FUN_000e9184(piVar9,0);
          iVar2 = piVar9[0x3c];
          FUN_00194374(piVar3[0x34],piVar9);
          piVar8 = (int *)FUN_000e7f38(iVar5);
          FUN_00194374(piVar8[0x35],iVar5);
          FUN_000e8e4c(piVar3,piVar8);
          piVar8[0x3c] = iVar2;
          ((int (*)())FUN_0012dd58)(program,piVar9,iVar5);
          (**(code **)(*piVar3 + 0x48))(piVar3);
          (**(code **)(*piVar8 + 0x48))(piVar8);
          iVar2 = FUN_0012aef0(program,piVar3,piVar8);
          if (iVar2 == 0) {
LAB_0013037c:
            bVar1 = true;
            piVar3 = piVar8;
          }
          else {
            piVar3 = (int *)FUN_000e920c(piVar3,0);
            bVar1 = true;
          }
        }
      }
      piVar8 = (int *)piVar3[2];
      piVar9 = piVar3;
    } while ((int *)piVar3[2] != (int *)0x0);
    if (!bVar1) break;
    *(undefined4 *)(program + 0x394) = 0;
    *(undefined4 *)(program + 0x398) = 0;
    *(undefined4 *)(program + 0x39c) = 0;
    iVar2 = FUN_000e07dc(*(undefined4 *)(program + 8),0x11);
    if (iVar2 != 0) {
      FUN_0013bd68(program,0);
    }
  }
  return FUN_000ed7e4(program,(int)"remove_empty_graphs");
}

/* FUN_001303f4 @ 0x1303f4 (48 bytes) */
int FUN_001303f4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 4;
  do {
    if (*(int *)(iVar1 + param_2) == param_1) {
      return 1;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_00130424 @ 0x130424 (32 bytes) */
int FUN_00130424(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x3c4) + 1;
  *(int *)(*(int *)(param_1 + 0x2c) + 0x3c4) = iVar1;
  return iVar1 + *(int *)(param_1 + 8);
}

/* FUN_00130444 @ 0x130444 (52 bytes) */
int FUN_00130444(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x42c);
  *(uint *)(iVar1 + 8) =
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f)) & *(uint *)(iVar1 + 8);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x8000;
  return;
}

/* FUN_00130478 @ 0x130478 (44 bytes) */
int FUN_00130478(param_1, param_2)
  int param_1;
  uint param_2;
{
  if ((*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x42c) + 8) >> (param_2 & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* FUN_001304a4 @ 0x1304a4 (200 bytes) */
int FUN_001304a4(param_1)
  int param_1;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = *(int *)(param_1 + 8);
  piVar4 = *(int **)(iVar3 + 0x30c);
  iVar1 = (**(code **)(*piVar4 + 0x138))(piVar4,iVar3);
  iVar2 = (**(code **)(*piVar4 + 0x140))(piVar4,iVar3);
  iVar3 = (**(code **)(*piVar4 + 0x13c))(piVar4,iVar3);
  iVar3 = iVar1 + iVar2 + iVar3;
  if (0 < iVar3) {
    loopIndex = 0;
    do {
      iVar2 = ((int (*)())FUN_00130478)(param_1,loopIndex);
      if (iVar2 == 0) {
        iVar5 = iVar5 + 1;
      }
      loopIndex = loopIndex + 1;
    } while (iVar3 != loopIndex);
  }
  return iVar5;
}

/* FUN_0013056c @ 0x13056c (40 bytes) */
int FUN_0013056c(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x42c);
  *(uint *)(iVar1 + 8) = 1 << (param_2 & 0x1f) | *(uint *)(iVar1 + 8);
  return;
}

/* FUN_00130594 @ 0x130594 (136 bytes) */
int FUN_00130594(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int callResult;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_2 * 4 + param_1;
  iVar4 = -1;
  iVar1 = *(int *)(iVar3 + 0x448);
  iVar5 = *(int *)(iVar3 + 0x43c);
  iVar3 = iVar5;
  if (iVar5 < iVar1) {
    do {
      callResult = ((int (*)())FUN_00130478)(param_1,iVar3);
      if ((callResult == 0) && (iVar4 < iVar3)) {
        iVar4 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
    if (-1 < iVar4) {
      iVar4 = iVar4 - iVar5;
    }
  }
  return iVar4;
}

/* FUN_0013061c @ 0x13061c (116 bytes) */
int FUN_0013061c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int callResult;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2 * 4 + param_1;
  iVar4 = 0;
  iVar1 = *(int *)(iVar3 + 0x448);
  iVar3 = *(int *)(iVar3 + 0x43c);
  if (iVar3 < iVar1) {
    do {
      callResult = ((int (*)())FUN_00130478)(param_1,iVar3);
      if (callResult == 0) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  return iVar4;
}

/* FUN_00130690 @ 0x130690 (152 bytes) */
int FUN_00130690(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int callResult;
  
  iVar1 = ((int (*)())FUN_0013061c)(param_1,param_2);
  if (param_2 == 1) {
    iVar1 = iVar1 + 0x20;
  }
  callResult = ((int (*)())FUN_00130478)(param_1,iVar1);
  if (callResult == 0) {
    FUN_000e1534(*(undefined4 *)(param_1 + 8),4);
  }
  ((int (*)())FUN_00130444)(param_1,iVar1);
  *(int *)(*(int *)(param_1 + 0x470) * 4 + *(int *)(param_1 + 0x458)) = iVar1;
  *(int *)(*(int *)(param_1 + 0x470) * 4 + *(int *)(param_1 + 0x45c)) = param_2;
  iVar1 = *(int *)(param_1 + 0x470);
  *(int *)(param_1 + 0x470) = iVar1 + 1;
  return iVar1;
}

/* FUN_00130728 @ 0x130728 (164 bytes) */
int FUN_00130728(param_1)
  int *param_1;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (**(code **)(*param_1 + 0x34))(param_1);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    piVar1 = param_1;
    if (iVar3 == 0) {
      do {
        param_1 = piVar1;
        piVar1 = (int *)param_1[1];
      } while ((((int *)param_1[1])[5] & 4U) != 0);
    }
    else {
      uVar2 = param_1[5];
      while ((uVar2 & 0x1000) == 0) {
        param_1 = (int *)param_1[1];
        uVar2 = param_1[5];
      }
    }
  }
  return param_1;
}

/* FUN_001307cc @ 0x1307cc (44 bytes) */
int FUN_001307cc(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 callResult;
  
  iVar1 = ((int (*)())FUN_00130728)(param_1);
  callResult = ((int (*)())FUN_00130728)(*(undefined4 *)(iVar1 + 4));
  return callResult;
}

/* FUN_001307f8 @ 0x1307f8 (228 bytes) */
int FUN_001307f8(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = (**(code **)(*param_1 + 0x38))(param_1);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(*param_1 + 0x28))(param_1);
    if (iVar3 == 0) {
      uVar4 = param_1[5];
      while ((uVar4 & 4) != 0) {
        param_1 = (int *)param_1[2];
        uVar4 = param_1[5];
      }
    }
    else {
      iVar3 = (**(code **)(*param_1 + 0x74))(param_1);
      if (iVar3 == 0) {
        uVar4 = (**(code **)(*param_1 + 0x78))(param_1);
        piVar2 = param_1;
        while (piVar1 = piVar2, uVar4 == 0) {
          piVar2 = (int *)piVar1[2];
          uVar4 = piVar2[5] & 0x1000;
          param_1 = piVar1;
        }
      }
    }
  }
  return param_1;
}

/* FUN_001308e0 @ 0x1308e0 (36 bytes) */
int FUN_001308e0(param_1)
  undefined4 param_1;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_001307f8)(param_1);
  return *(undefined4 *)(iVar1 + 8);
}

/* FUN_00130904 @ 0x130904 (64 bytes) */
int FUN_00130904(param_1)
  undefined4 param_1;
{
  int iVar1;
  undefined4 callResult;
  
  iVar1 = ((int (*)())FUN_001307cc)(param_1);
  if ((*(uint *)(iVar1 + 0x14) & 0x4000000) != 0) {
    iVar1 = ((int (*)())FUN_001307cc)(param_1);
  }
  callResult = ((int (*)())FUN_001307f8)(iVar1);
  return callResult;
}

/* FUN_00130944 @ 0x130944 (20 bytes) */
int FUN_00130944(param_1)
  int param_1;
{
  return *(uint *)(param_1 + 0x98) < 2;
}

/* FUN_00130958 @ 0x130958 (36 bytes) */
int FUN_00130958(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_0013097c @ 0x13097c (64 bytes) */
int FUN_0013097c(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 << 2;
  iVar2 = 4;
  do {
    if ((*(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1) != 0) {
      return 1;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}

/* FUN_001309bc @ 0x1309bc (32 bytes) */
int FUN_001309bc(param_1, param_2)
  int param_1;
  uint param_2;
{
  return *(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x24) + 8) >> (param_2 & 0x1f) &
         1;
}

/* FUN_001309dc @ 0x1309dc (44 bytes) */
int FUN_001309dc(param_1, param_2)
  int param_1;
  uint param_2;
{
  if ((*(uint *)((param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x430) + 8) >> (param_2 & 0x1f) &
      1) != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00130a08 @ 0x130a08 (112 bytes) */
int FUN_00130a08(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  
  iVar1 = ((int (*)())FUN_00130728)(param_1);
  piVar2 = *(int **)(iVar1 + 4);
  while( true ) {
    iVar1 = (**(code **)(*piVar2 + 0x74))(piVar2);
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    if (*(int *)(piVar2[0x30] + 0x13c) == param_2) break;
    piVar2 = (int *)piVar2[1];
  }
  return piVar2;
}

/* FUN_00130a78 @ 0x130a78 (68 bytes) */
int FUN_00130a78(param_1, param_2)
  uint param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = param_1;
  while( true ) {
    if (uVar2 == 0) {
      return 0;
    }
    puVar1 = (uint *)(param_1 + 0x14);
    if (((*puVar1 & 1) != 0) && (*(int *)(param_1 + 0x14c) == *(int *)(param_2 + 0x14c))) break;
    param_1 = *(uint *)(param_1 + 8);
    uVar2 = *puVar1 & 4;
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* FUN_00130abc @ 0x130abc (280 bytes) */
int FUN_00130abc(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  int *a0;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  int *a0_00;
  int *piVar6;
  undefined8 uVar7;
  
  a0 = (int *)((int (*)())FUN_001307cc)(param_1);
  uVar7 = ((int (*)())FUN_00130728)(param_1);
  piVar2 = (int *)((ulonglong)uVar7 >> 0x20);
  iVar3 = (**(code **)(*a0 + 0x24))(a0,(int)uVar7,param_3);
  if (((iVar3 != 0) && ((a0[5] & 0x4000000U) == 0)) &&
     (a0_00 = piVar2, uVar4 = extraout_r4, piVar6 = piVar2, (piVar2[5] & 0x1000U) == 0)) {
    do {
      if (piVar6 == (int *)0x0) {
        return;
      }
      uVar1 = a0_00[5];
      if ((uVar1 & 1) != 0) {
        piVar6 = a0_00 + 0x29;
        for (iVar3 = 1; iVar5 = (**(code **)(*a0_00 + 0x14))(a0_00,uVar4,param_3), iVar3 <= iVar5;
            iVar3 = iVar3 + 1) {
          uVar4 = FUN_00105594(a0_00,iVar3);
          uVar7 = ((int (*)())FUN_00130a78)(a0,uVar4);
          uVar4 = (undefined4)uVar7;
          if ((int)((ulonglong)uVar7 >> 0x20) != 0) {
            param_3 = 1;
            piVar2[5] = piVar2[5] | 0x10000000;
            FUN_00103d50(piVar6,4,1);
            uVar4 = extraout_r4_00;
          }
          piVar6 = piVar6 + 6;
        }
        uVar1 = a0_00[5];
        uVar4 = extraout_r4_01;
      }
      a0_00 = (int *)a0_00[2];
      piVar6 = (int *)(uVar1 & 4);
    } while (a0_00 != (int *)0x0);
  }
  return;
}

/* FUN_00130bd4 @ 0x130bd4 (40 bytes) */
int FUN_00130bd4(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x430);
  *(uint *)(iVar1 + 8) =
       (-2 << (param_2 & 0x1f) | 0xfffffffeU >> 0x20 - (param_2 & 0x1f)) & *(uint *)(iVar1 + 8);
  return;
}

/* FUN_00130bfc @ 0x130bfc (144 bytes) */
int FUN_00130bfc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x14);
  if (*(int *)(param_2 + 0x98) != 0) {
    if (*(int *)(param_2 + 0x98) == 1) {
      return 1;
    }
    return -1;
  }
  if ((*(uint *)(param_2 + 0x14) & 0x40) == 0) {
    return 0;
  }
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      if ((*(int *)(param_1 + 0x43c) <= *(int *)(param_2 + 0x94)) &&
         (*(int *)(param_2 + 0x94) < *(int *)(param_1 + 0x448))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return -1;
}

/* FUN_00130c8c @ 0x130c8c (276 bytes) */
int FUN_00130c8c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
{
  undefined4 uVar1;
  int iVar2;
  int callResult;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = ((int (*)())FUN_00130728)(param_2);
  iVar6 = *(int *)(*(int *)(param_1 + 0x2c) + 0x6c4);
  callResult = FUN_001043f0(0x31,*(int *)(param_1 + 0x2c));
  uVar1 = *(undefined4 *)(param_3 + 0x98);
  *(int *)(callResult + 0x94) = *param_4;
  *(undefined4 *)(callResult + 0x98) = uVar1;
  FUN_00106004(callResult,1,param_3,0,*(undefined4 *)(param_1 + 0x2c));
  uVar1 = *(undefined4 *)(iVar2 + 4);
  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) & 0xffffffbf | 0x80000000;
  piVar4 = *(int **)(*(int *)(param_1 + 0x2c) + 0x30c);
  iVar5 = (**(code **)(*piVar4 + 0x150))(piVar4,uVar1);
  if (iVar5 != 0) {
    *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x1000;
  }
  FUN_000e7700(*(undefined4 *)(iVar2 + 0x158),iVar2,callResult);
  *(undefined4 *)(*param_4 * 4 + *(int *)(iVar6 + 0x45c)) = 0;
  *(undefined4 *)(*param_4 * 4 + *(int *)(iVar6 + 0x458)) = 0xffffffff;
  **(int **)(param_1 + 0x18) = **(int **)(param_1 + 0x18) + 1;
  *param_4 = *param_4 + 1;
  return callResult;
}

/* FUN_00130da0 @ 0x130da0 (200 bytes) */
int FUN_00130da0(param_1, inst, param_3, param_4, param_5)
  undefined4 param_1;
  int inst;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  int callResult;
  
  uVar1 = FUN_00105594(inst,param_3);
  callResult = FUN_0010445c(uVar1,param_5,0);
  if ((*(uint *)(inst + 0x14) & 0x40) == 0) {
    uVar1 = ((int (*)())FUN_00130424)(param_1);
    *(undefined4 *)(callResult + 0x98) = 0;
    *(undefined4 *)(callResult + 0x94) = uVar1;
  }
  FUN_000e7738(*(undefined4 *)(param_4 + 0x158),param_4,callResult);
  *(uint *)(callResult + 0x14) = *(uint *)(callResult + 0x14) | 0x8000000;
  FUN_00106004(inst,param_3,callResult,0,param_5);
  *(uint *)(inst + 0x18) = *(uint *)(inst + 0x18) | 1;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffeffb | 0x8000000;
  return callResult;
}

/* FUN_00130e68 @ 0x130e68 (88 bytes) */
int FUN_00130e68(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
  if ((iVar1 != 0) || (uVar2 = 0, *(int *)(param_1[0x22] + 8) == 0x93)) {
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_00130ec0 @ 0x130ec0 (72 bytes) */
int FUN_00130ec0(param_1, param_2, compiler)
  undefined4 param_1;
  undefined4 param_2;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar3;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)FUN_00193e18(arena,0x168);
  puVar3 = allocation + 1;
  *allocation = arena;
  FUN_00109a80(puVar3,0xfa,compiler);
  allocation[0x4d] = param_1;
  allocation[0x27] = 0x3b;
  allocation[0x4e] = param_2;
  allocation[0x26] = param_1;
  FUN_000e7688(*(undefined4 *)(*(int *)(compiler + 0x6c4) + 0x3a0),puVar3);
  return puVar3;
}

/* FUN_00130f64 @ 0x130f64 (72 bytes) */
int FUN_00130f64(param_1, param_2, compiler)
  undefined4 param_1;
  undefined4 param_2;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  undefined4 *puVar3;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)FUN_00193e18(arena,0x168);
  puVar3 = allocation + 1;
  *allocation = arena;
  FUN_00109a80(puVar3,0x79,compiler);
  allocation[0x4d] = param_1;
  allocation[0x27] = 0x3c;
  allocation[0x50] = param_2;
  allocation[0x26] = param_2;
  FUN_000e76c4(*(undefined4 *)(*(int *)(compiler + 0x6c4) + 0x3a0),puVar3);
  return puVar3;
}

/* FUN_00131008 @ 0x131008 (452 bytes) */
int FUN_00131008(param_1, inst, param_3)
  int param_1;
  int *inst;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 operandVReg;
  undefined4 uVar4;
  int *a0;
  int iVar5;
  int loopIndex;
  undefined4 local_48;
  undefined1 auStack_44 [12];
  undefined4 local_38 [5];
  
  iVar2 = FUN_001054ec(inst,param_3);
  FUN_000f3398(local_38,*(undefined4 *)(iVar2 + 0x10));
  local_48 = local_38[0];
  operandVReg = FUN_00105594(inst,param_3);
  iVar2 = 0;
  do {
    if ((auStack_44[iVar2 + -4] != '\0') &&
       (uVar4 = FUN_001382b8(operandVReg,iVar2,auStack_44), -1 < param_1)) {
      loopIndex = 0;
      a0 = inst;
      do {
        do {
          do {
            a0 = (int *)((int (*)())FUN_001307cc)(a0);
          } while ((a0[5] & 0x4000000U) != 0);
          iVar5 = (**(code **)(*a0 + 0x34))(a0);
        } while ((((iVar5 != 0) || (iVar5 = (**(code **)(*a0 + 0x68))(a0), iVar5 != 0)) ||
                 (*(int *)(a0[0x22] + 8) == 0x8e)) ||
                ((iVar5 = (**(code **)(*a0 + 0x74))(a0), iVar5 != 0 ||
                 (iVar5 = (**(code **)(*a0 + 0x78))(a0), iVar5 != 0))));
        loopIndex = loopIndex + 1;
        iVar5 = (**(code **)(*(int *)inst[0x56] + 0x24))((int *)inst[0x56]);
        if ((iVar5 == 0) &&
           ((iVar5 = (**(code **)(*(int *)inst[0x56] + 0x2c))((int *)inst[0x56]), iVar5 == 0
            && (a0[0x56] != inst[0x56])))) {
          return 1;
        }
        iVar5 = ((int (*)())FUN_00130a78)(a0,uVar4);
        if (iVar5 != 0) {
          return 0;
        }
      } while (loopIndex <= param_1);
    }
    bVar1 = iVar2 == 3;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      return 1;
    }
  } while( true );
}

/* FUN_001311cc @ 0x1311cc (88 bytes) */
int FUN_001311cc(param_1, param_2, param_3, param_4, param_5, compiler)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int compiler;
{
  undefined4 *allocation;
  int operandRecord;
  undefined4 arena;
  undefined4 *puVar4;
  
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)FUN_00193e18(arena,0x168);
  puVar4 = allocation + 1;
  *allocation = arena;
  FUN_00107980(puVar4,0xfb,compiler);
  arena = UNK_001affe4;
  allocation[0x27] = 0;
  allocation[0x28] = arena;
  allocation[0x26] = param_1;
  FUN_00106004(puVar4,1,param_3,0,compiler);
  arena = UNK_001affe0;
  operandRecord = FUN_001054ec(puVar4,1);
  *(undefined4 *)(operandRecord + 0x10) = arena;
  FUN_00106004(puVar4,2,param_4,0,compiler);
  arena = UNK_001affdc;
  operandRecord = FUN_001054ec(puVar4,2);
  *(undefined4 *)(operandRecord + 0x10) = arena;
  FUN_000e7738(*(undefined4 *)(param_5 + 0x158),param_5,puVar4);
  allocation[6] = allocation[6] | 0x8001000;
  return puVar4;
}

/* FUN_001312f4 @ 0x1312f4 (228 bytes) */
int FUN_001312f4(inst, param_2, param_3, param_4, compiler)
  int inst;
  int param_2;
  undefined4 param_3;
  int param_4;
  int compiler;
{
  bool bVar1;
  int operandRecord;
  int operandRecord2;
  undefined4 *allocation;
  int iVar5;
  undefined4 arena;
  undefined4 *puVar7;
  undefined4 local_48 [4];
  undefined4 local_38;
  undefined4 local_34 [3];
  
  operandRecord = FUN_001054ec(inst,0);
  local_48[0] = *(undefined4 *)(operandRecord + 0x10);
  if (((*(uint *)(inst + 0x14) & 0x200) != 0) &&
     (operandRecord = FUN_00105594(inst,*(undefined4 *)(inst + 0x84)), operandRecord != 0)) {
    iVar5 = 0;
    do {
      operandRecord2 = FUN_001054ec(inst,0);
      if ((*(char *)(iVar5 + operandRecord2 + 0x10) == '\x01') &&
         (operandRecord2 = FUN_00138240(operandRecord,iVar5), operandRecord2 != 0)) {
        *(undefined1 *)((int)local_48 + iVar5) = 0;
      }
      bVar1 = iVar5 != 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  FUN_000f370c(&local_38,local_48[0]);
  arena = *(undefined4 *)(compiler + 0x374);
  allocation = (undefined4 *)FUN_00193e18(arena,0x168);
  puVar7 = allocation + 1;
  *allocation = arena;
  FUN_001071fc(puVar7,0xfc,compiler);
  arena = *(undefined4 *)(param_2 + 0x94);
  allocation[0x27] = 0x3b;
  allocation[0x26] = arena;
  FUN_000f36b8(local_34,local_38);
  allocation[0x28] = local_34[0];
  FUN_00106004(puVar7,1,inst,0,compiler);
  operandRecord = FUN_001054ec(puVar7,1);
  *(undefined4 *)(operandRecord + 0x10) = local_38;
  FUN_00106004(puVar7,2,param_3,0,compiler);
  arena = UNK_001affdc;
  operandRecord = FUN_001054ec(puVar7,2);
  *(undefined4 *)(operandRecord + 0x10) = arena;
  FUN_00106004(puVar7,3,param_2,0,compiler);
  arena = *(undefined4 *)(param_4 + 0x158);
  allocation[6] = allocation[6] | 0x1000;
  FUN_00193f74(puVar7,param_4);
  allocation[0x57] = arena;
  return;
}

/* FUN_001314b8 @ 0x1314b8 (320 bytes) */
int FUN_001314b8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  *(int *)(param_1 + 0x468) = *(int *)(*(int *)(param_1 + 8) + 0x3c4) + 1;
  iVar1 = ((int (*)())FUN_001304a4)(param_1);
  iVar4 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x46c) = iVar1;
  *(int *)(param_1 + 0x464) = iVar1 + *(int *)(param_1 + 0x468);
  piVar5 = *(int **)(iVar4 + 0x30c);
  iVar1 = (**(code **)(*piVar5 + 0x138))(piVar5,iVar4);
  iVar2 = (**(code **)(*piVar5 + 0x140))(piVar5,iVar4);
  iVar4 = (**(code **)(*piVar5 + 0x13c))(piVar5,iVar4);
  iVar4 = iVar1 + iVar2 + iVar4;
  iVar1 = *(int *)(param_1 + 0x464);
  if (*(int *)(param_1 + 0x464) <= iVar4) {
    iVar1 = iVar4;
  }
  if (iVar1 < 0x1000) {
    iVar1 = 0x1000;
  }
  iVar2 = iVar1 << 2;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x458) = uVar3;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x45c) = uVar3;
  uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2);
  *(undefined4 *)(param_1 + 0x460) = uVar3;
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar4 + *(int *)(param_1 + 0x460)) = 0xffffffff;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0012c134");
asm(".set FUN_0012c134, _FUN_0012c134");
asm(".globl FUN_0012dcf0");
asm(".set FUN_0012dcf0, _FUN_0012dcf0");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_001307f8");
asm(".set _thunk_FUN_001307f8, _FUN_001307f8");
