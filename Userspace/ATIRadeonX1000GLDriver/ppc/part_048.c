#include "decls.h"

/* FUN_0017bc58 @ 0x17bc58 (288 bytes) */
int FUN_0017bc58(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_28 [3];
  
  piVar1 = (int *)FUN_00105594(param_1,1);
  while( true ) {
    iVar3 = (**(code **)(*piVar1 + 0x40))(piVar1);
    if (iVar3 != 0) {
      return piVar1;
    }
    iVar3 = FUN_001054ec(piVar1,0);
    uVar4 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_00176534(param_1,piVar1);
    if (iVar3 == 2) break;
    if ((iVar3 == 0) && (FUN_000f3908(local_28,uVar4), (param_2 & local_28[0]) != DAT_001b01e0)) {
      return piVar1;
    }
    piVar1 = (int *)FUN_00105594(piVar1,3);
  }
  if ((param_3 != 0) && (piVar2 = (int *)FUN_00105594(param_1,1), piVar1 != piVar2)) {
    FUN_00106004(param_1,1,piVar1,0,param_4);
    return (int *)0x0;
  }
  return (int *)0x0;
}

/* FUN_0017bd78 @ 0x17bd78 (388 bytes) */
int FUN_0017bd78(param_1, param_2, param_3, param_4)
  int param_1;
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
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar8 = *(undefined4 *)(iVar4 + 4);
  uVar9 = *(undefined4 *)(iVar4 + 0x158);
  FUN_0019401c(iVar4);
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar5 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar12 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar14 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = FUN_001054ec(iVar4,param_2);
  iVar5 = *(int *)(param_1 + 0xb0);
  bVar2 = *(byte *)(param_3 + iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar10 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar7 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar13);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  *(undefined4 *)(iVar5 + 0x9c) = uVar11;
  *(undefined4 *)(iVar5 + 0x120) = uVar14;
  *(undefined4 *)(iVar5 + 0x124) = param_4;
  FUN_001046c8(iVar5,1,uVar12);
  uVar11 = *(undefined4 *)(PTR_DAT_001e8b8c + (uint)bVar2 * 4);
  iVar4 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar11;
  FUN_00103d50(iVar5 + 0xa4,1,uVar3 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar10;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar5,uVar7);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_58;
  }
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar9,uVar8,iVar5);
  return iVar5;
}

/* FUN_0017bf70 @ 0x17bf70 (392 bytes) */
int FUN_0017bf70(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  iVar8 = 2;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar2 = *(int *)(iVar2 + 4);
  do {
    iVar3 = FUN_00176854(param_1,iVar8,1,1,1,0);
    if (iVar3 != 0) {
      iVar9 = 0;
      piVar10 = &DAT_001e6134;
      iVar3 = iVar8 * 4;
      do {
        if ((iVar2 == *(int *)((iVar3 + *piVar10) * 4 + param_1 + 0x168)) &&
           (iVar2 == *(int *)((iVar3 + piVar10[1]) * 4 + param_1 + 0x168))) {
          pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                                         *(undefined4 *)((iVar3 + piVar10[2]) * 4 + param_1 + 0x168)
                                        );
          if ((double)*pfVar4 == 1.0) {
            iVar7 = *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
LAB_0017c0b0:
            ((int (*)())FUN_0017bd78)(param_1,(iVar8 == 1) + 1,iVar9,iVar7);
            FUN_001745ac(param_1);
            return 1;
          }
          iVar7 = ((int (*)())FUN_0010ab40)((double)*pfVar4);
          if (iVar7 != 0) {
            piVar5 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
            iVar7 = iVar7 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
            iVar6 = (**(code **)(*piVar5 + 0xfc))(piVar5,iVar7);
            if (iVar6 != 0) goto LAB_0017c0b0;
          }
        }
        bVar1 = iVar9 != 2;
        piVar10 = piVar10 + 3;
        iVar9 = iVar9 + 1;
      } while (bVar1);
    }
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      return 0;
    }
  } while( true );
}

/* FUN_0017c0f8 @ 0x17c0f8 (332 bytes) */
int FUN_0017c0f8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar9 = *(int *)(iVar1 + 4);
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  iVar2 = 1;
  iVar5 = *(int *)(iVar1 + 4);
  iVar8 = 2;
  iVar1 = param_1 + 0x20;
  do {
    iVar7 = *(int *)(iVar1 + 0x16c);
    if ((((iVar9 == iVar7) && (iVar9 == *(int *)(iVar1 + 0x170))) &&
        (iVar9 == *(int *)(iVar1 + 0x174))) && (iVar5 == *(int *)(iVar1 + 0x168))) {
      uVar3 = 0;
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
      goto LAB_0017c1c4;
    }
    if (iVar9 == *(int *)(iVar1 + 0x168)) {
      iVar6 = *(int *)(iVar1 + 0x170);
      if (((iVar9 == iVar6) && (iVar6 == *(int *)(iVar1 + 0x174))) && (iVar5 == iVar7)) {
        uVar3 = 1;
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
        goto LAB_0017c1c4;
      }
      if (iVar9 == iVar7) {
        if ((iVar9 == *(int *)(iVar1 + 0x174)) && (iVar5 == iVar6)) {
          uVar3 = 2;
          uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
LAB_0017c1c4:
          ((int (*)())FUN_0017bd78)(param_1,iVar2,uVar3,uVar4);
          FUN_001745ac(param_1);
          return 1;
        }
        if ((iVar9 == iVar6) && (iVar5 == *(int *)(iVar1 + 0x174))) {
          uVar3 = 3;
          uVar4 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x124);
          goto LAB_0017c1c4;
        }
      }
    }
    iVar8 = iVar8 + -1;
    iVar1 = iVar1 + -0x10;
    if (iVar8 < 1) {
      return 0;
    }
    iVar2 = (iVar8 == 1) + 1;
  } while( true );
}

/* FUN_0017c244 @ 0x17c244 (356 bytes) */
int FUN_0017c244(param_1, param_2)
  int param_1;
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
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar12 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar4 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar10 = *(undefined4 *)(iVar4 + 0x10);
  uVar11 = *(undefined4 *)(param_2 * 0x18 + iVar3 + 0x8c);
  uVar13 = *(undefined4 *)(iVar3 + 0x120);
  uVar14 = *(undefined4 *)(iVar3 + 0x124);
  iVar3 = FUN_001054ec(iVar3,param_2);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar15 = *(undefined4 *)(iVar3 + 0x10);
  uVar5 = *(uint *)(iVar4 + 0x14);
  uVar2 = *(uint *)(param_2 * 0x18 + iVar4 + 0xa0);
  uVar9 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar5 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    local_58 = 0;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 4 + param_1 + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(iVar4 + 0x84) * 0x18 + iVar4 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar4 + 0x94);
  uVar17 = *(undefined4 *)(iVar4 + 0x98);
  FUN_00108448(iVar4,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar4,0,uVar12);
  *(undefined4 *)(iVar4 + 0x98) = uVar17;
  *(undefined4 *)(iVar4 + 0x94) = uVar16;
  *(undefined4 *)(iVar4 + 0x9c) = uVar10;
  *(undefined4 *)(iVar4 + 0x120) = uVar13;
  *(undefined4 *)(iVar4 + 0x124) = uVar14;
  FUN_001046c8(iVar4,1,uVar11);
  iVar3 = FUN_001054ec(iVar4,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar15;
  FUN_00103d50(iVar4 + 0xa4,1,uVar2 & 1);
  FUN_00103d50(iVar4 + 0xa4,2,uVar2 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar4,uVar6);
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_58;
  }
  if ((uVar5 & 0x200000) != 0) {
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar8,uVar7,iVar4);
  return iVar4;
}

/* FUN_0017c41c @ 0x17c41c (136 bytes) */
int FUN_0017c41c(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_00179c44(param_1,2,3);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xe8);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(param_1,2);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c4a4 @ 0x17c4a4 (316 bytes) */
int FUN_0017c4a4(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0x88))();
  if (((iVar3 == 0) || (iVar3 = FUN_00179c44(param_1,2,3), iVar3 == 0)) ||
     (iVar3 = FUN_00179c44(param_1,1,3), iVar3 == 0)) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0xb0);
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
      ((int (*)())FUN_0017c244)(param_1,2);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
      iVar3 = *(int *)(param_1 + 0xb0);
      uVar4 = 1;
      goto LAB_0017c5b4;
    }
    if (uVar1 != 0) {
      return 0;
    }
  }
  ((int (*)())FUN_0017c244)(param_1,2);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar4 = 2;
LAB_0017c5b4:
  FUN_00103d50(iVar3 + 0xa4,uVar4,1);
  FUN_001745ac(param_1);
  return 1;
}

/* FUN_0017c5e0 @ 0x17c5e0 (404 bytes) */
int FUN_0017c5e0(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  bVar2 = false;
  iVar3 = FUN_00176324(0);
  iVar8 = 0;
  iVar7 = -1;
  iVar9 = param_1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar6 = iVar7;
    if (*(char *)(iVar8 + iVar4 + 0x10) != '\x01') {
      iVar6 = *(int *)(iVar9 + 0x178);
      if (iVar6 < 0) {
        puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar6);
        iVar6 = FUN_00176324(*puVar5);
        iVar4 = *(int *)(param_1 + 0xb0);
      }
      else {
        if (iVar6 < 1) {
          return 0;
        }
        iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238),iVar6);
        iVar4 = *(int *)(param_1 + 0xb0);
        iVar6 = *(int *)(iVar6 + 0xc);
        if ((*(uint *)(iVar4 + 0xb8) & 2) != 0) {
          iVar6 = (DAT_001e61d0)[iVar6];
        }
        bVar2 = true;
        if ((*(uint *)(iVar4 + 0xb8) & 1) != 0) {
          iVar6 = *(int *)(&DAT_001e61b8 + iVar6 * 4);
        }
      }
      iVar4 = FUN_0010b5f8(iVar4);
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
    bVar1 = iVar8 == 3;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 1;
    iVar7 = iVar6;
    if (bVar1) {
      if (bVar2) {
        iVar7 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar7 + 0x134) = *(int *)(iVar7 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar6);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017c774 @ 0x17c774 (276 bytes) */
int FUN_0017c774(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar4,iVar3);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017c244)(param_1,(iVar3 == 1) + 1);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar3 != 2;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  iVar3 = 1;
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  uVar4 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar4,iVar3);
    if (iVar2 != 0) {
      iVar2 = (iVar3 == 1) + 1;
      ((int (*)())FUN_0017c244)(param_1,iVar2);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   *(uint *)(iVar2 * 0x18 + *(int *)(param_1 + 0xb0) + 0xa0) & 1 ^ 1);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar3 != 2;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017c888 @ 0x17c888 (136 bytes) */
int FUN_0017c888(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_00179c44(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      ((int (*)())FUN_0017c244)(param_1,1);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017c910 @ 0x17c910 (516 bytes) */
int FUN_0017c910(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int local_64 [10];
  
  bVar2 = false;
  iVar10 = 0;
  iVar11 = param_1 + 0x170;
  iVar8 = -1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(iVar10 + iVar4 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      piVar14 = local_64;
      iVar12 = 0x98;
      for (iVar4 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar4 <= iVar6;
          iVar4 = iVar4 + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar6 = FUN_00176324(*puVar5);
          *piVar14 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar6 = *(int *)(iVar6 + 0xc);
          *piVar14 = iVar6;
          iVar7 = *(int *)(param_1 + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar14 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *piVar14 = *(int *)(&DAT_001e61b8 + *piVar14 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        piVar14 = piVar14 + 1;
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
    bVar1 = iVar10 == 3;
    iVar11 = iVar11 + 4;
    iVar10 = iVar10 + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar9);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017cb14 @ 0x17cb14 (516 bytes) */
int FUN_0017cb14(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int local_64 [10];
  
  bVar2 = false;
  iVar10 = 0;
  iVar11 = param_1 + 0x170;
  iVar8 = -1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar9 = iVar8;
    if (*(char *)(iVar10 + iVar4 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar11 + 8);
      piVar14 = local_64;
      iVar12 = 0x98;
      for (iVar4 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar4 <= iVar6;
          iVar4 = iVar4 + 1) {
        iVar6 = *piVar13;
        if (iVar6 < 0) {
          puVar5 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar6 = FUN_00176324(*puVar5);
          *piVar14 = iVar6;
        }
        else {
          if (iVar6 < 1) {
            return 0;
          }
          iVar6 = FUN_00173330(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar6 = *(int *)(iVar6 + 0xc);
          *piVar14 = iVar6;
          iVar7 = *(int *)(param_1 + 0xb0) + iVar12;
          uVar3 = *(uint *)(iVar7 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar14 = (DAT_001e61d0)[iVar6];
            uVar3 = *(uint *)(iVar7 + 0x20);
          }
          bVar2 = true;
          if ((uVar3 & 1) != 0) {
            *piVar14 = *(int *)(&DAT_001e61b8 + *piVar14 * 4);
          }
        }
        iVar12 = iVar12 + 0x18;
        piVar14 = piVar14 + 1;
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
    bVar1 = iVar10 == 3;
    iVar11 = iVar11 + 4;
    iVar10 = iVar10 + 1;
    iVar8 = iVar9;
    if (bVar1) {
      if (iVar9 == -1) {
        iVar9 = 1;
      }
      if (bVar2) {
        iVar8 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
        *(int *)(iVar8 + 0x134) = *(int *)(iVar8 + 0x134) + 1;
      }
      ((int (*)())FUN_0017c244)(param_1,iVar9);
      FUN_001745ac(param_1);
      return 1;
    }
  } while( true );
}

/* FUN_0017cd18 @ 0x17cd18 (164 bytes) */
int FUN_0017cd18(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      iVar2 = FUN_0017737c(param_1,0,3);
      if (iVar2 == 0) {
        ((int (*)())FUN_0017c244)(param_1,3);
      }
      else {
        FUN_00177548(param_1);
      }
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017cdbc @ 0x17cdbc (192 bytes) */
int FUN_0017cdbc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = 1;
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  uVar4 = *(undefined4 *)(iVar1 + 4);
  do {
    uVar3 = 2;
    do {
      iVar1 = FUN_00177064(param_1,uVar4,iVar2);
      if (iVar1 != 0) {
        iVar1 = FUN_0017737c(param_1,0,uVar3);
        if (iVar1 == 0) {
          ((int (*)())FUN_0017c244)(param_1,uVar3);
        }
        else {
          FUN_00177548(param_1);
        }
        FUN_001745ac(param_1);
        return 1;
      }
      iVar2 = iVar2 + 1;
      if (2 < iVar2) {
        return 0;
      }
      uVar3 = 1;
    } while (iVar2 != 1);
  } while( true );
}

/* FUN_0017ce7c @ 0x17ce7c (284 bytes) */
int FUN_0017ce7c(param_1, param_2)
  int param_1;
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
  int iVar16;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar8 = *(undefined4 *)(iVar3 + 4);
  uVar9 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar13 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar16 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar16 + 0x14);
  uVar10 = *(undefined4 *)(iVar16 + 0x120);
  uVar11 = *(undefined4 *)(iVar16 + 0x124);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar6 = 0;
    uVar7 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(*(int *)(iVar16 + 0x84) * 4 + param_1 + 0x210);
    uVar7 = *(undefined4 *)(*(int *)(iVar16 + 0x84) * 0x18 + iVar16 + 0x8c);
  }
  uVar14 = *(undefined4 *)(iVar16 + 0x94);
  uVar15 = *(undefined4 *)(iVar16 + 0x98);
  FUN_00108448(iVar16,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar16,0,uVar13);
  *(undefined4 *)(iVar16 + 0x98) = uVar15;
  *(undefined4 *)(iVar16 + 0x94) = uVar14;
  *(undefined4 *)(iVar16 + 0x9c) = uVar12;
  *(undefined4 *)(iVar16 + 0x120) = uVar10;
  *(undefined4 *)(iVar16 + 0x124) = uVar11;
  FUN_001046c8(iVar16,1,*(undefined4 *)(param_2 + 0xc));
  uVar12 = *(undefined4 *)(PTR_DAT_001e8b8c + *(int *)(param_2 + 0x10) * 4);
  iVar3 = FUN_001054ec(iVar16,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar12;
  if (*(int *)(param_2 + 0x18) != 0) {
    FUN_00103d50(iVar16 + 0xa4,1,1);
  }
  *(undefined4 *)(iVar16 + 0x120) = uVar10;
  *(undefined4 *)(iVar16 + 0x124) = uVar11;
  piVar4 = *(int **)(*(int *)(iVar16 + 0xa4) + 0x18);
  if (*piVar4 == 0) {
    puVar5 = (undefined4 *)FUN_0019423c(piVar4,0);
  }
  else {
    if (piVar4[1] == 0) {
      *(undefined4 *)piVar4[2] = 0;
      piVar4[1] = 1;
    }
    puVar5 = (undefined4 *)piVar4[2];
  }
  *(undefined4 *)(param_1 + 0x214) = *puVar5;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar16,uVar7);
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar6;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar9,uVar8,iVar16);
  return iVar16;
}

/* FUN_0017d06c @ 0x17d06c (368 bytes) */
int FUN_0017d06c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
{
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
  int iVar13;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 4);
  uVar8 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar11 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar13 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar13 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar6 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar13 + 0x84) * 4 + param_1 + 0x210);
    uVar6 = *(undefined4 *)(*(int *)(iVar13 + 0x84) * 0x18 + iVar13 + 0x8c);
  }
  uVar12 = *(undefined4 *)(iVar13 + 0x94);
  uVar10 = *(undefined4 *)(iVar13 + 0x98);
  FUN_00108448(iVar13,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar13,0,uVar11);
  iVar3 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(iVar13 + 0x94) = uVar12;
  *(undefined4 *)(iVar13 + 0x98) = uVar10;
  *(undefined4 *)(iVar13 + 0x9c) = uVar9;
  if (*(int *)(*(int *)(iVar3 + 0x2c) + 4) == 0) {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
    puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x240);
    *puVar4 = uVar9;
    puVar4 = puVar4 + 1;
    FUN_00173938(puVar4,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00174e0c(puVar4);
    FUN_00173278(puVar4);
    FUN_00123424(iVar3,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar4);
  }
  FUN_001046c8(iVar13,1,iVar3);
  uVar9 = *param_3;
  iVar3 = FUN_001054ec(iVar13,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar9;
  FUN_00103d50(iVar13 + 0xa4,1,param_4);
  *(int *)(param_1 + 0x214) = param_2;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar13,uVar6);
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar5;
  }
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar13 + 0x14) = *(uint *)(iVar13 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar8,uVar7,iVar13);
  return iVar13;
}

/* FUN_0017d26c @ 0x17d26c (196 bytes) */
int FUN_0017d26c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar6 = *(undefined4 *)(iVar3 + 4);
  uVar7 = *(undefined4 *)(iVar3 + 0x158);
  FUN_0019401c(iVar3);
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar3 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  uVar2 = *(uint *)(iVar11 + 0x14);
  bVar1 = (uVar2 >> 9 & 1) == 0;
  if (bVar1) {
    uVar5 = 0;
    uVar8 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(iVar11 + 0x84) * 4 + param_1 + 0x210);
    uVar8 = *(undefined4 *)(*(int *)(iVar11 + 0x84) * 0x18 + iVar11 + 0x8c);
  }
  uVar12 = *(undefined4 *)(iVar11 + 0x94);
  uVar14 = *(undefined4 *)(iVar11 + 0x98);
  FUN_00108448(iVar11,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar11,0,uVar10);
  *(undefined4 *)(iVar11 + 0x94) = uVar12;
  *(undefined4 *)(iVar11 + 0x98) = uVar14;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar11,uVar8);
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar5;
  }
  *(undefined4 *)(iVar11 + 0x9c) = uVar9;
  iVar13 = 0;
  uVar9 = FUN_0017a130(1,param_2,iVar11,*(undefined4 *)(param_1 + 0x238));
  *(undefined4 *)(param_1 + 0x214) = uVar9;
  iVar3 = param_1;
  do {
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar13 + iVar4 + 0x10) == '\x01') {
      *(undefined4 *)(iVar3 + 0x30) = 0;
    }
    bVar1 = iVar13 != 3;
    iVar3 = iVar3 + 4;
    iVar13 = iVar13 + 1;
  } while (bVar1);
  if ((uVar2 & 0x200000) != 0) {
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200000;
  }
  FUN_000e7738(uVar7,uVar6,iVar11);
  return iVar11;
}

/* FUN_0017d3f8 @ 0x17d3f8 (232 bytes) */
int FUN_0017d3f8(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_28 [8];
  
  iVar2 = FUN_00179c44(param_1,1,2);
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(iVar2 + 0xb8) & 1) == (*(uint *)(iVar2 + 0xd0) & 1)) &&
       ((*(uint *)(iVar2 + 0xb8) >> 1 & 1) == (*(uint *)(iVar2 + 0xd0) >> 1 & 1))) {
      iVar2 = ((bool (*)())FUN_0010b820)(iVar2,(double)FLOAT_001aa0d4,(double)FLOAT_001aa0d4);
      uVar3 = 0x3f800000;
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      iVar2 = 4;
      puVar1 = local_28;
      do {
        *puVar1 = 0x7ffffffe;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = 0;
      iVar4 = 4;
      do {
        *(undefined4 *)(iVar2 + (int)local_28) = uVar3;
        iVar2 = iVar2 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      ((int (*)())FUN_0017d26c)(param_1,local_28);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d4e0 @ 0x17d4e0 (156 bytes) */
int FUN_0017d4e0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = FUN_00176fd4(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) == (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_28);
      FUN_001745ac(param_1);
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
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      local_2c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_38);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017d610 @ 0x17d610 (156 bytes) */
int FUN_0017d610(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = FUN_00179c44(param_1,1,2);
  if (iVar2 != 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar1 & 1) != (uVar3 & 1)) && ((uVar1 >> 1 & 1) == (uVar3 >> 1 & 1))) {
      local_1c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      ((int (*)())FUN_0017d26c)(param_1,&local_28);
      FUN_001745ac(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_0017d6ac @ 0x17d6ac (780 bytes) */
int FUN_0017d6ac(param_1, param_2)
  int param_1;
  float *param_2;
{
  bool bVar1;
  byte bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  float fVar10;
  int iVar11;
  undefined4 local_58;
  float local_54 [4];
  float afStack_44 [3];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  uVar8 = DAT_001b01d8;
  iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(iVar5 + 0x10));
  FUN_000f3340(local_34,uVar8,local_38);
  local_58 = local_34[0];
  piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
  iVar5 = (**(code **)(*piVar6 + 0x154))
                    (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),param_2,&local_58);
  if (iVar5 == 0) {
    iVar5 = 4;
    pfVar3 = local_54;
    do {
      *pfVar3 = NAN;
      pfVar3 = pfVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = 0;
    pfVar3 = local_54;
    pfVar9 = param_2;
    do {
      iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
        *pfVar3 = -*pfVar9;
      }
      bVar1 = iVar5 != 3;
      pfVar3 = pfVar3 + 1;
      pfVar9 = pfVar9 + 1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
    iVar5 = (**(code **)(*piVar6 + 0x154))
                      (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_54,&local_58)
    ;
    if (iVar5 == 0) {
      fVar10 = NAN;
      iVar5 = 0;
      pfVar3 = param_2;
      do {
        iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar7 + 0x10) != '\x01') {
          FUN_00173e10(*(undefined4 *)(param_1 + 0x238),*pfVar3);
          if (fVar10 == NAN) {
            fVar10 = *pfVar3;
          }
          else if (fVar10 != *pfVar3) {
            return 0;
          }
        }
        bVar1 = iVar5 != 3;
        pfVar3 = pfVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),fVar10);
      if (*(byte *)(iVar5 + 8) == 0) {
        return 0;
      }
      bVar2 = *(byte *)(iVar5 + 9);
      if (((((bVar2 & 1) == 0) && ((bVar2 & 2) == 0)) && ((bVar2 & 4) == 0)) && ((bVar2 & 8) == 0))
      {
        if ((*(byte *)(iVar5 + 8) & 1) == 0) {
          iVar5 = ((int (*)())FUN_0017ce7c)(param_1,iVar5);
          return iVar5;
        }
        iVar5 = 0;
        iVar7 = 4;
        do {
          *(float *)((int)param_2 + iVar5) = fVar10;
          iVar5 = iVar5 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar5 = ((int (*)())FUN_0017d26c)(param_1,param_2);
        return iVar5;
      }
      iVar7 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar5 + 0x14));
      pfVar3 = local_54;
      if ((*(byte *)(iVar7 + 8) & 1) == 0) {
        iVar7 = ((int (*)())FUN_0017ce7c)(param_1,iVar7);
      }
      else {
        do {
          *pfVar3 = NAN;
          pfVar3 = pfVar3 + 1;
        } while (pfVar3 != afStack_44);
        iVar4 = 0;
        iVar11 = 4;
        do {
          *(undefined4 *)(iVar4 + (int)local_54) = *(undefined4 *)(iVar7 + 0x14);
          iVar4 = iVar4 + 4;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar7 = ((int (*)())FUN_0017d26c)(param_1,local_54);
      }
      bVar2 = *(byte *)(iVar5 + 9);
      if ((bVar2 & 1) != 0) {
        FUN_00103d50(iVar7 + 0xa4,1,1);
        bVar2 = *(byte *)(iVar5 + 9);
      }
      if ((bVar2 & 2) != 0) {
        *(undefined4 *)(iVar7 + 0x124) = *(undefined4 *)(iVar5 + 0x1c);
        return iVar7;
      }
      return iVar7;
    }
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  iVar5 = ((int (*)())FUN_0017d06c)(param_1,iVar5,&local_58,uVar8);
  return iVar5;
}

/* FUN_0017d9b8 @ 0x17d9b8 (548 bytes) */
int FUN_0017d9b8(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int local_64 [9];
  
  iVar14 = 4;
  piVar10 = local_64 + 2;
  piVar4 = piVar10;
  do {
    *piVar4 = 0x7ffffffe;
    piVar4 = piVar4 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  iVar14 = 0;
  iVar15 = 4;
  do {
    *(undefined4 *)(iVar14 + (int)piVar10) = 0x7ffffffe;
    iVar14 = iVar14 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  bVar2 = false;
  iVar14 = 0;
  iVar15 = param_1 + 0x170;
  piVar4 = piVar10;
  do {
    iVar5 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar14 + iVar5 + 0x10) != '\x01') {
      piVar13 = (int *)(iVar15 + 8);
      iVar5 = 1;
      piVar12 = local_64;
      iVar11 = 0x98;
      do {
        *piVar12 = 0;
        iVar9 = *piVar13;
        if (iVar9 < 0) {
          puVar6 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar9);
          iVar9 = FUN_00176324(*puVar6);
          *piVar12 = iVar9;
        }
        else {
          if (iVar9 < 1) goto LAB_0017dbc4;
          iVar9 = FUN_00173330(*(undefined4 *)(param_1 + 0x238),iVar9);
          iVar7 = *(int *)(iVar9 + 0xc);
          *piVar12 = iVar7;
          iVar9 = *(int *)(param_1 + 0xb0) + iVar11;
          uVar3 = *(uint *)(iVar9 + 0x20);
          if ((uVar3 & 2) != 0) {
            *piVar12 = (DAT_001e61d0)[iVar7];
            uVar3 = *(uint *)(iVar9 + 0x20);
          }
          if ((uVar3 & 1) == 0) {
            iVar9 = *piVar12;
            bVar2 = true;
          }
          else {
            bVar2 = true;
            iVar9 = *(int *)(&DAT_001e61b8 + *piVar12 * 4);
            *piVar12 = iVar9;
          }
        }
        iVar7 = local_64[0];
        if (iVar9 == 0) goto LAB_0017dbc4;
        bVar1 = iVar5 != 2;
        iVar11 = iVar11 + 0x18;
        piVar12 = piVar12 + 1;
        piVar13 = piVar13 + 4;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      iVar5 = FUN_0010b5f8(*(undefined4 *)(param_1 + 0xb0));
      iVar5 = *(int *)(&DAT_001e61e8 + (iVar5 * 6 + iVar7 * 0x30 + local_64[1]) * 4);
      if (iVar5 == 1) {
        *piVar4 = 0x3f800000;
      }
      else if (iVar5 == 2) {
        *piVar4 = 0;
      }
      else if (iVar5 == 0) goto LAB_0017dbc4;
    }
    bVar1 = iVar14 != 3;
    iVar15 = iVar15 + 4;
    piVar4 = piVar4 + 1;
    iVar14 = iVar14 + 1;
  } while (bVar1);
  iVar14 = ((int (*)())FUN_0017d6ac)(param_1,piVar10);
  if (iVar14 == 0) {
LAB_0017dbc4:
    uVar8 = 0;
  }
  else {
    if (bVar2) {
      iVar14 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
      *(int *)(iVar14 + 0x134) = *(int *)(iVar14 + 0x134) + 1;
    }
    FUN_001745ac(param_1);
    uVar8 = 1;
  }
  return uVar8;
}

/* FUN_0017dbdc @ 0x17dbdc (1104 bytes) */
int FUN_0017dbdc(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int local_58 [4];
  int local_48;
  int local_44;
  int local_40;
  int local_3c [6];
  
  uVar6 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8);
  iVar2 = FUN_00176564(uVar6);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = FUN_00176574(uVar6);
  if (iVar2 == 0) {
    iVar4 = FUN_00113174(uVar6,*(undefined4 *)(param_1 + 0x238));
    if ((iVar4 == 0) ||
       (iVar4 = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(param_1 + 0x238)), iVar4 == 0)) {
      iVar4 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238));
      if (iVar4 == 0) {
        iVar2 = 0;
        iVar7 = 0;
        iVar4 = param_1;
        piVar5 = param_2;
        do {
          local_58[0] = 0;
          iVar3 = FUN_001767d8(param_1,iVar7);
          if (iVar3 != 0) {
            FUN_00176c40(local_3c,param_1,iVar7,local_58);
            *piVar5 = local_3c[0];
            if (local_3c[0] != 0x7ffffffe) {
              uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_3c[0]);
              *(undefined4 *)(iVar4 + 0x30) = uVar6;
            }
          }
          iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if ((*(char *)(iVar7 + iVar3 + 0x10) == '\0') && (local_58[0] != 0)) {
            iVar2 = 1;
          }
          bVar1 = iVar7 != 3;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 4;
          iVar7 = iVar7 + 1;
        } while (bVar1);
        iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(int *)(iVar4 + 0x10) == 0x1010101) goto LAB_0017dfa0;
        iVar4 = 0;
        piVar5 = param_2;
        do {
          iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if ((*(char *)(iVar4 + iVar7 + 0x10) != '\x01') && (*piVar5 == 0x7ffffffe))
          goto LAB_0017dfa0;
          bVar1 = iVar4 != 3;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
        } while (bVar1);
      }
      else {
        iVar4 = FUN_0017672c(param_1);
        if (iVar4 == 0) goto LAB_0017df9c;
        local_58[0] = iVar2;
        FUN_001781a4(&local_40,param_1,local_58);
        iVar2 = local_58[0];
        if (local_40 == 0x7ffffffe) goto LAB_0017dfa0;
        uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_40);
        iVar3 = 4;
        iVar7 = 0;
        iVar4 = param_1;
        do {
          *(int *)((int)param_2 + iVar7) = local_40;
          iVar7 = iVar7 + 4;
          *(undefined4 *)(iVar4 + 0x30) = uVar6;
          iVar4 = iVar4 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    else {
      iVar4 = FUN_00178b1c(param_1);
      if (iVar4 == 0) {
LAB_0017df9c:
        iVar2 = 0;
LAB_0017dfa0:
        bVar1 = true;
        goto LAB_0017dd38;
      }
      local_58[0] = iVar2;
      FUN_00176a94(&local_44,param_1,local_58);
      iVar2 = local_58[0];
      if (local_44 == 0x7ffffffe) goto LAB_0017dfa0;
      uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_44);
      iVar3 = 4;
      iVar7 = 0;
      iVar4 = param_1;
      do {
        *(int *)((int)param_2 + iVar7) = local_44;
        iVar7 = iVar7 + 4;
        *(undefined4 *)(iVar4 + 0x30) = uVar6;
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar2 = 0;
    iVar7 = 0;
    iVar4 = param_1;
    piVar5 = param_2;
    do {
      local_58[0] = 0;
      iVar3 = FUN_00178a98(param_1,iVar7);
      if (iVar3 != 0) {
        FUN_00178e90(&local_48,param_1,iVar7,(uint)local_58);
        *piVar5 = local_48;
        if (local_48 != 0x7ffffffe) {
          uVar6 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),local_48);
          *(undefined4 *)(iVar4 + 0x30) = uVar6;
        }
      }
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if ((*(char *)(iVar7 + iVar3 + 0x10) == '\0') && (local_58[0] != 0)) {
        iVar2 = 1;
      }
      bVar1 = iVar7 != 3;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar4 + 0x10) == 0x1010101) goto LAB_0017dfa0;
    iVar4 = 0;
    piVar5 = param_2;
    do {
      iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if ((*(char *)(iVar4 + iVar7 + 0x10) != '\x01') && (*piVar5 == 0x7ffffffe)) goto LAB_0017dfa0;
      bVar1 = iVar4 != 3;
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
  bVar1 = false;
LAB_0017dd38:
  iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 100))();
  if ((iVar4 == 0) && (!bVar1)) {
    iVar4 = ((int (*)())FUN_0017d6ac)(param_1,param_2);
    if (iVar4 != 0) {
      FUN_001745ac(param_1);
      return 1;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0x138) = *(int *)(iVar4 + 0x138) + 1;
    if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x120) != 0) && (iVar2 == 0)) {
      *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
      FUN_001745ac(param_1);
      return 0;
    }
  }
  return 0;
}

/* FUN_0017e02c @ 0x17e02c (268 bytes) */
int FUN_0017e02c(param_1, param_2, param_3)
  int param_1;
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
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar4 + 4);
  uVar7 = *(undefined4 *)(iVar4 + 0x158);
  FUN_0019401c(iVar4);
  uVar15 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar5 = FUN_001054ec(*(int *)(param_1 + 0xb0),0);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  uVar13 = *(undefined4 *)(param_2 * 0x18 + iVar4 + 0x8c);
  uVar9 = *(undefined4 *)(iVar4 + 0x120);
  iVar4 = FUN_001054ec(iVar4,param_2);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar14 = *(undefined4 *)(iVar4 + 0x10);
  uVar6 = *(uint *)(iVar5 + 0x14);
  uVar3 = *(uint *)(param_2 * 0x18 + iVar5 + 0xa0);
  uVar11 = *(undefined4 *)(param_2 * 4 + param_1 + 0x210);
  bVar1 = (uVar6 >> 9 & 1) == 0;
  if (bVar1) {
    uVar8 = 0;
    uVar10 = 0;
  }
  else {
    uVar8 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  uVar16 = *(undefined4 *)(iVar5 + 0x94);
  uVar17 = *(undefined4 *)(iVar5 + 0x98);
  FUN_00108448(iVar5,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar15);
  *(undefined4 *)(iVar5 + 0x94) = uVar16;
  *(undefined4 *)(iVar5 + 0x98) = uVar17;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_001049e8(iVar5,uVar10);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = uVar8;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar12;
  FUN_001046c8(iVar5,1,uVar13);
  iVar4 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar14;
  FUN_00103d50(iVar5 + 0xa4,1,uVar3 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar5 + 0x120) = uVar9;
  *(undefined4 *)(iVar5 + 0x124) = param_3;
  *(undefined4 *)(param_1 + 0x214) = uVar11;
  if ((uVar6 & 0x200000) != 0) {
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200000;
  }
  FUN_00193f74(iVar5,uVar2);
  *(undefined4 *)(iVar5 + 0x158) = uVar7;
  return;
}

/* FUN_0017e1f4 @ 0x17e1f4 (324 bytes) */
int FUN_0017e1f4(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  double fparam_1;
  float local_38 [7];
  
  iVar5 = 1;
  do {
    FUN_001770e4(local_38,param_1,iVar5);
    if (local_38[0] != NAN) {
      bVar1 = -1 < (int)local_38[0];
      if (bVar1) {
        fparam_1 = (double)local_38[0];
      }
      else {
        fparam_1 = -(double)local_38[0];
      }
      iVar2 = ((undefined4 (*)())FUN_0010aafc)(fparam_1);
      if (iVar2 != 0) {
        iVar2 = ((int (*)())FUN_0010ab40)(fparam_1);
        piVar4 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar2 = iVar2 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
        iVar3 = (**(code **)(*piVar4 + 0xfc))(piVar4,iVar2);
        if (iVar3 != 0) {
          iVar5 = (iVar5 == 1) + 1;
          if (!bVar1) {
            iVar3 = *(int *)(param_1 + 0xb0) + iVar5 * 0x18 + 0x80;
            FUN_00103d50(iVar3 + 0xc,1,(*(uint *)(iVar3 + 0x20) ^ 1) & 1);
          }
          ((int (*)())FUN_0017e02c)(param_1,iVar5,iVar2);
          FUN_001745ac(param_1);
          return 1;
        }
      }
    }
    bVar1 = iVar5 != 2;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e338 @ 0x17e338 (188 bytes) */
int FUN_0017e338(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_00179c44(param_1,1,2);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(iVar1 + 0xb8) & 1) == (*(uint *)(iVar1 + 0xd0) & 1)) &&
       ((*(uint *)(iVar1 + 0xb8) >> 1 & 1) == (*(uint *)(iVar1 + 0xd0) >> 1 & 1))) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
      iVar3 = *(int *)(iVar1 + 0x124) + 1;
      iVar1 = (**(code **)(*piVar2 + 0xfc))(piVar2,iVar3);
      if (iVar1 != 0) {
        ((int (*)())FUN_0017e02c)(param_1,2,iVar3);
        FUN_001745ac(param_1);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0017e3f4 @ 0x17e3f4 (348 bytes) */
int FUN_0017e3f4(param_1, param_2, param_3, param_4)
  int param_1;
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
  
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar5 + 4);
  uVar3 = *(undefined4 *)(iVar5 + 0x158);
  uVar15 = *(undefined4 *)(iVar5 + 0x94);
  uVar16 = *(undefined4 *)(iVar5 + 0x98);
  uVar17 = *(undefined4 *)(iVar5 + 0x8c);
  iVar8 = FUN_001054ec(iVar5,0);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar9 = *(undefined4 *)(iVar8 + 0x10);
  uVar10 = *(undefined4 *)(param_3 * 0x18 + iVar5 + 0x8c);
  uVar13 = *(undefined4 *)(iVar5 + 0x120);
  uVar14 = *(undefined4 *)(iVar5 + 0x124);
  iVar8 = FUN_001054ec(iVar5,param_3);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar8 + 0x10);
  uVar4 = *(uint *)(param_3 * 0x18 + iVar5 + 0xa0);
  uVar6 = *(undefined4 *)(param_4 * 0x18 + iVar5 + 0x8c);
  iVar5 = FUN_001054ec(iVar5,param_4);
  iVar8 = *(int *)(param_1 + 0xb0);
  uVar12 = *(undefined4 *)(iVar5 + 0x10);
  bVar1 = (*(uint *)(iVar8 + 0x14) & 0x200) == 0;
  uVar7 = *(uint *)(param_4 * 0x18 + iVar8 + 0xa0);
  uVar18 = *(undefined4 *)(param_3 * 4 + param_1 + 0x210);
  uVar20 = *(undefined4 *)(param_4 * 4 + param_1 + 0x210);
  if (bVar1) {
    uVar19 = 0;
    uVar21 = 0;
  }
  else {
    uVar19 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 4 + param_1 + 0x210);
    uVar21 = *(undefined4 *)(*(int *)(iVar8 + 0x84) * 0x18 + iVar8 + 0x8c);
  }
  FUN_0019401c(iVar8);
  iVar5 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar5,param_2,*(undefined4 *)(param_1 + 0x238));
  FUN_001046c8(iVar5,0,uVar17);
  *(undefined4 *)(iVar5 + 0x94) = uVar15;
  *(undefined4 *)(iVar5 + 0x98) = uVar16;
  if (bVar1) {
    iVar8 = FUN_00122fa4(uVar17,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0)
                        );
    *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(iVar8 + 0xb0);
  }
  else {
    FUN_001049e8(iVar5,uVar21);
    *(uint *)(iVar5 + 0x14) = *(uint *)(iVar5 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x21c) = uVar19;
  }
  *(undefined4 *)(iVar5 + 0x9c) = uVar9;
  *(undefined4 *)(iVar5 + 0x120) = uVar13;
  *(undefined4 *)(iVar5 + 0x124) = uVar14;
  FUN_001046c8(iVar5,1,uVar10);
  iVar8 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar8 + 0x10) = uVar11;
  FUN_00103d50(iVar5 + 0xa4,1,uVar4 & 1);
  FUN_00103d50(iVar5 + 0xa4,2,uVar4 >> 1 & 1);
  FUN_001046c8(iVar5,2,uVar6);
  iVar8 = FUN_001054ec(iVar5,2);
  *(undefined4 *)(iVar8 + 0x10) = uVar12;
  FUN_00103d50(iVar5 + 0xbc,1,uVar7 & 1);
  FUN_00103d50(iVar5 + 0xbc,2,uVar7 >> 1 & 1);
  *(undefined4 *)(param_1 + 0x218) = uVar20;
  *(undefined4 *)(param_1 + 0x214) = uVar18;
  FUN_00193f74(iVar5,uVar2);
  *(undefined4 *)(iVar5 + 0x158) = uVar3;
  return;
}

/* FUN_0017e658 @ 0x17e658 (112 bytes) */
int FUN_0017e658(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0);
  iVar1 = FUN_00177064(param_1,*(undefined4 *)(iVar1 + 4),3);
  if (iVar1 != 0) {
    ((int (*)())FUN_0017e3f4)(param_1,0x13,1,2);
    FUN_001745ac(param_1);
  }
  return iVar1 != 0;
}

/* FUN_0017e6c8 @ 0x17e6c8 (280 bytes) */
int FUN_0017e6c8(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017e3f4)(param_1,0x12,(iVar4 == 1) + 1,3);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  iVar2 = FUN_00173e10(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  iVar4 = 1;
  uVar3 = *(undefined4 *)(iVar2 + 4);
  do {
    iVar2 = FUN_00177064(param_1,uVar3,iVar4);
    if (iVar2 != 0) {
      ((int (*)())FUN_0017e3f4)(param_1,0x12,(iVar4 == 1) + 1,3);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(param_1 + 0xb0) + 0xb8) ^ 1) & 1);
      FUN_001745ac(param_1);
      return 1;
    }
    bVar1 = iVar4 != 2;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 0;
}

/* FUN_0017e7e0 @ 0x17e7e0 (604 bytes) */
int FUN_0017e7e0(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
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
  
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar19 = *(undefined4 *)(iVar4 + 0x158);
  uVar17 = *(undefined4 *)(iVar4 + 4);
  uVar9 = *(undefined4 *)(iVar4 + 0x94);
  uVar10 = *(undefined4 *)(iVar4 + 0x98);
  uVar15 = *(undefined4 *)(iVar4 + 0x8c);
  iVar4 = FUN_001054ec(iVar4,0);
  local_78 = *(int *)(iVar4 + 0x10);
  iVar4 = *(int *)(param_1 + 0xb0);
  local_58 = *(int *)(iVar4 + 0x120);
  local_5c = *(int *)(iVar4 + 0x124);
  uVar14 = *(undefined4 *)(iVar4 + 0xa4);
  iVar6 = FUN_001054ec(iVar4,1);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar13 = *(undefined4 *)(iVar6 + 0x10);
  uVar2 = *(uint *)(iVar4 + 0xb8);
  uVar12 = *(undefined4 *)(iVar4 + 0xbc);
  iVar6 = FUN_001054ec(iVar4,2);
  iVar4 = *(int *)(param_1 + 0xb0);
  uVar11 = *(undefined4 *)(iVar6 + 0x10);
  uVar3 = *(uint *)(iVar4 + 0xd0);
  uVar8 = *(undefined4 *)(iVar4 + 0xd4);
  iVar4 = FUN_001054ec(iVar4,3);
  iVar6 = *(int *)(param_1 + 0xb0);
  local_68 = *(undefined4 *)(iVar4 + 0x10);
  uVar5 = *(uint *)(iVar6 + 0xe8);
  bVar1 = (*(uint *)(iVar6 + 0x14) >> 9 & 1) != 0;
  local_60 = uVar5 >> 1 & 1;
  if (bVar1) {
    local_64 = *(undefined4 *)(*(int *)(iVar6 + 0x84) * 0x18 + iVar6 + 0x8c);
  }
  else {
    local_64 = 0;
  }
  FUN_0019401c(iVar6);
  iVar16 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar16,0x13,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,uVar17,iVar16);
  piVar7 = (int *)FUN_001043f0(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,*(undefined4 *)(param_1 + 0xb0),piVar7);
  iVar4 = *(int *)(param_1 + 0x238);
  uVar17 = *(undefined4 *)(*(int *)(iVar4 + 0x6c4) + 0x3ac);
  iVar6 = *(int *)(iVar4 + 0x3ac) + -1;
  *(int *)(iVar4 + 0x3ac) = iVar6;
  uVar17 = FUN_00127608(uVar17,0,iVar6,0);
  FUN_001046c8(iVar16,0,uVar17);
  FUN_001046c8(iVar16,1,uVar14);
  iVar4 = FUN_001054ec(iVar16,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar13;
  FUN_00103d50(iVar16 + 0xa4,1,uVar2 & 1);
  FUN_00103d50(iVar16 + 0xa4,2,uVar2 >> 1 & 1);
  FUN_001046c8(iVar16,2,uVar12);
  iVar4 = FUN_001054ec(iVar16,2);
  *(undefined4 *)(iVar4 + 0x10) = uVar11;
  FUN_00103d50(iVar16 + 0xbc,1,uVar3 & 1);
  FUN_00103d50(iVar16 + 0xbc,2,uVar3 >> 1 & 1);
  *(undefined4 *)(iVar16 + 0x94) = uVar9;
  *(undefined4 *)(iVar16 + 0x98) = uVar10;
  *(int *)(iVar16 + 0x9c) = local_78;
  FUN_0012306c(uVar17,iVar16);
  iVar4 = 0;
  local_74[0] = DAT_001b01dc;
  iVar6 = 4;
  do {
    if (*(char *)((int)local_74 + iVar4 + -4) == '\0') {
      *(char *)((int)local_74 + iVar4) = (char)iVar4;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_001046c8(piVar7,0,uVar15);
  piVar7[0x27] = local_78;
  FUN_001046c8(piVar7,1,uVar17);
  uVar9 = local_74[0];
  iVar4 = FUN_001054ec(piVar7,1);
  *(undefined4 *)(iVar4 + 0x10) = uVar9;
  FUN_001046c8(piVar7,2,uVar8);
  iVar4 = FUN_001054ec(piVar7,2);
  *(undefined4 *)(iVar4 + 0x10) = local_68;
  FUN_00103d50(piVar7 + 0x2f,1,uVar5 & 1);
  FUN_00103d50(piVar7 + 0x2f,2,local_60);
  piVar7[0x48] = local_58;
  piVar7[0x49] = local_5c;
  FUN_0012306c(uVar15,piVar7);
  iVar4 = 1;
  piVar18 = piVar7;
  while( true ) {
    iVar6 = (**(code **)(*piVar7 + 0x14))(piVar7);
    if (iVar6 < iVar4) break;
    FUN_001236e4(piVar18[0x29],iVar4,piVar7);
    iVar4 = iVar4 + 1;
    piVar18 = piVar18 + 6;
  }
  if (bVar1) {
    FUN_001049e8(iVar16,local_64);
    *(uint *)(iVar16 + 0x14) = *(uint *)(iVar16 + 0x14) | 0x200;
    FUN_001236e4(local_64,*(undefined4 *)(iVar16 + 0x84),iVar16);
    FUN_001049e8(piVar7,uVar15);
    piVar7[5] = piVar7[5] | 0x200;
    FUN_001236e4(uVar15,piVar7[0x21],piVar7);
  }
  _memset((void *)(param_1 + 0xb4),0,0x15c);
  FUN_0017386c(param_1);
  FUN_00173f1c(param_1);
  return;
}

/* FUN_0017ebb0 @ 0x17ebb0 (508 bytes) */
int FUN_0017ebb0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
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
  int iVar18;
  undefined4 local_58;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar14 = *(undefined4 *)(iVar3 + 4);
  uVar15 = *(undefined4 *)(iVar3 + 0x158);
  uVar12 = *(undefined4 *)(iVar3 + 0x94);
  uVar13 = *(undefined4 *)(iVar3 + 0x98);
  uVar9 = *(undefined4 *)(iVar3 + 0x8c);
  iVar5 = FUN_001054ec(iVar3,0);
  iVar3 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(param_1 + 0x21c);
  uVar17 = *(undefined4 *)(iVar3 + 0x124);
  uVar11 = *(undefined4 *)(iVar5 + 0x10);
  uVar16 = *(undefined4 *)(iVar3 + 0x120);
  uVar8 = *(undefined4 *)(iVar3 + 0xd4);
  iVar3 = FUN_001054ec(iVar3,3);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar7 = *(undefined4 *)(iVar3 + 0x10);
  uVar4 = *(uint *)(iVar5 + 0xe8);
  bVar1 = (*(uint *)(iVar5 + 0x14) >> 9 & 1) != 0;
  if (bVar1) {
    uVar10 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 4 + param_1 + 0x210);
    local_58 = *(undefined4 *)(*(int *)(iVar5 + 0x84) * 0x18 + iVar5 + 0x8c);
  }
  else {
    uVar10 = 0;
    local_58 = 0;
  }
  FUN_0019401c(iVar5);
  iVar3 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar3,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar15,uVar14,iVar3);
  *(undefined4 *)(iVar3 + 0x120) = uVar16;
  *(undefined4 *)(iVar3 + 0x124) = uVar17;
  *(undefined4 *)(iVar3 + 0x94) = uVar12;
  *(undefined4 *)(iVar3 + 0x98) = uVar13;
  FUN_001046c8(iVar3,0,uVar9);
  iVar5 = *(int *)(param_2 + 0x8c);
  *(undefined4 *)(iVar3 + 0x9c) = uVar11;
  if (*(int *)(*(int *)(iVar5 + 0x2c) + 4) == 0) {
    uVar11 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
    puVar6 = (undefined4 *)FUN_00193e18(uVar11,0x240);
    *puVar6 = uVar11;
    puVar6 = puVar6 + 1;
    FUN_00173938(puVar6,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00174e0c(puVar6);
    FUN_00173278(puVar6);
    FUN_00123424(iVar5,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar6);
  }
  FUN_001046c8(iVar3,1,iVar5);
  iVar5 = FUN_001054ec(iVar3,1);
  *(undefined4 *)(iVar5 + 0x10) = param_3;
  FUN_00103d50(iVar3 + 0xa4,1,param_4);
  FUN_001046c8(iVar3,2,uVar8);
  iVar5 = FUN_001054ec(iVar3,2);
  *(undefined4 *)(iVar5 + 0x10) = uVar7;
  FUN_00103d50(iVar3 + 0xbc,1,uVar4 & 1);
  FUN_00103d50(iVar3 + 0xbc,2,uVar4 >> 1 & 1);
  if (bVar1) {
    FUN_001049e8(iVar3,local_58);
    *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) | 0x200;
  }
  *(int *)(param_1 + 0x214) = param_2;
  *(undefined4 *)(param_1 + 0x218) = uVar2;
  if (!bVar1) {
    uVar10 = 0;
  }
  *(undefined4 *)(param_1 + 0x21c) = uVar10;
  FUN_0012306c(uVar9,iVar3);
  if (0 < *(int *)(iVar3 + 0x84)) {
    iVar18 = 1;
    iVar5 = iVar3;
    do {
      puVar6 = (undefined4 *)(iVar5 + 0xa4);
      iVar5 = iVar5 + 0x18;
      FUN_001236e4(*puVar6,iVar18,iVar3);
      iVar18 = iVar18 + 1;
    } while (iVar18 <= *(int *)(iVar3 + 0x84));
  }
  _memset((void *)(param_1 + 0xb4),0,0x15c);
  FUN_0017386c(param_1);
  FUN_00173f1c(param_1);
  return;
}

/* FUN_0017ee68 @ 0x17ee68 (468 bytes) */
int FUN_0017ee68(param_1)
  int param_1;
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
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  float local_58 [5];
  
  iVar17 = 1;
  while ((FUN_00178d78(local_58,param_1,iVar17), local_58[0] != FLOAT_001aa0e8 &&
         (local_58[0] != FLOAT_001aa114))) {
    bVar1 = iVar17 == 2;
    iVar17 = iVar17 + 1;
    if (bVar1) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar18 = (iVar17 == 1) + 1;
  uVar9 = *(undefined4 *)(iVar5 + 0x8c);
  iVar11 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  iVar17 = FUN_001054ec(iVar5,0);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar10 = *(undefined4 *)(iVar17 + 0x10);
  uVar13 = *(undefined4 *)(iVar18 * 0x18 + iVar5 + 0x8c);
  uVar7 = *(undefined4 *)(iVar5 + 0x120);
  uVar8 = *(undefined4 *)(iVar5 + 0x124);
  iVar17 = FUN_001054ec(iVar5,iVar18);
  iVar5 = *(int *)(param_1 + 0xb0);
  uVar14 = *(uint *)(iVar17 + 0x10);
  uVar12 = *(undefined4 *)(iVar18 * 4 + param_1 + 0x210);
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
  FUN_0019401c(iVar5);
  iVar18 = *(int *)(param_1 + 0xb0);
  FUN_00108174(iVar18,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,uVar20,iVar18);
  iVar17 = *(int *)(param_1 + 0x238);
  iVar5 = *(int *)(iVar17 + 0x3ac) + -1;
  uVar20 = *(undefined4 *)(*(int *)(iVar17 + 0x6c4) + 0x3ac);
  *(int *)(iVar17 + 0x3ac) = iVar5;
  uVar20 = FUN_00127608(uVar20,0,iVar5,0);
  FUN_0012306c(uVar20,*(undefined4 *)(param_1 + 0xb0));
  FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),0,uVar20);
  *(undefined4 *)(iVar18 + 0x94) = uVar15;
  *(undefined4 *)(iVar18 + 0x98) = uVar16;
  FUN_001046c8(iVar18,1,uVar13);
  FUN_001046c8(iVar18,2,uVar13);
  iVar17 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e7738(uVar19,iVar18,iVar17);
  FUN_001046c8(iVar17,0,uVar9);
  *(undefined4 *)(iVar17 + 0x94) = uVar15;
  *(undefined4 *)(iVar17 + 0x98) = uVar16;
  *(undefined4 *)(iVar17 + 0x9c) = uVar10;
  if (bVar1) {
    FUN_001049e8(iVar17,uVar6);
    *(uint *)(iVar17 + 0x14) = *(uint *)(iVar17 + 0x14) | 0x200;
  }
  *(undefined4 *)(iVar17 + 0x120) = uVar7;
  *(undefined4 *)(iVar17 + 0x124) = uVar8;
  *(undefined4 *)(param_1 + 0x218) = uVar12;
  *(undefined4 *)(param_1 + 0x214) = uVar12;
  puVar4 = PTR_DAT_001e8b8c;
  uVar2 = DAT_001b01d8;
  if (iVar11 == 0x1c) {
    uVar7 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar14 >> 0x16 & 0x3fc));
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffffff;
    iVar5 = FUN_001054ec(iVar18,1);
    uVar8 = *(undefined4 *)(puVar4 + (uVar14 >> 0xe & 0x3fc));
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    iVar5 = FUN_001054ec(iVar18,2);
    *(undefined4 *)(iVar5 + 0x10) = uVar8;
    FUN_001046c8(iVar17,1,uVar20);
    FUN_001046c8(iVar17,2,uVar13);
    uVar7 = *(undefined4 *)puVar4;
    iVar5 = FUN_001054ec(iVar17,1);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    uVar7 = *(undefined4 *)(puVar4 + (uVar14 >> 6 & 0x3fc));
    iVar17 = FUN_001054ec(iVar17,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar7;
  }
  else if (iVar11 == 0x1d) {
    *(uint *)(iVar18 + 0x9c) = DAT_001b01d0 & 0xffff;
    iVar5 = FUN_001054ec(iVar18,1);
    uVar3 = DAT_001b01d8;
    *(uint *)(iVar5 + 0x10) = uVar14 & 0xff0000 | uVar14 & 0xff000000 | uVar2 & 0xffff;
    iVar5 = FUN_001054ec(iVar18,2);
    *(uint *)(iVar5 + 0x10) = (uVar14 & 0xff) << 0x10 | (uVar14 & 0xff00) << 0x10 | uVar3 & 0xffff;
    FUN_001046c8(iVar17,1,uVar20);
    FUN_001046c8(iVar17,2,uVar20);
    puVar4 = PTR_DAT_001e8b8c;
    uVar7 = *(undefined4 *)PTR_DAT_001e8b8c;
    iVar5 = FUN_001054ec(iVar17,1);
    uVar8 = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)(iVar5 + 0x10) = uVar7;
    iVar17 = FUN_001054ec(iVar17,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar8;
  }
  FUN_001745ac(param_1);
  return 1;
}

/* FUN_0017f1f8 @ 0x17f1f8 (512 bytes) */
int FUN_0017f1f8(param_1)
  int param_1;
{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_68;
  float local_64 [4];
  float local_54 [7];
  undefined4 local_38;
  undefined4 local_34 [4];
  
  iVar7 = 5;
  pfVar2 = local_54;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  pfVar2 = local_64;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != local_54);
  iVar7 = 0;
  iVar8 = 4;
  do {
    *(undefined4 *)(iVar7 + (int)local_64) = 0x7ffffffe;
    iVar7 = iVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar7 = 0;
  iVar8 = param_1 + 0x170;
  do {
    iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar7 + iVar3 + 0x10) != '\x01') {
      piVar6 = (int *)(iVar8 + 8);
      pfVar2 = local_54 + 1;
      do {
        iVar3 = *piVar6;
        if (-1 < iVar3) {
          return 0;
        }
        piVar6 = piVar6 + 4;
        pfVar4 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar3);
        *pfVar2 = *pfVar4;
        pfVar2 = pfVar2 + 1;
      } while (pfVar2 != local_54 + 3);
      local_64[iVar7] = local_54[1] * local_54[2];
    }
    uVar5 = DAT_001b01d8;
    bVar1 = iVar7 != 3;
    iVar8 = iVar8 + 4;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  iVar7 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  FUN_000f3908(&local_38,*(undefined4 *)(iVar7 + 0x10));
  FUN_000f3340(local_34,uVar5,local_38);
  local_68 = local_34[0];
  piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
  iVar7 = (**(code **)(*piVar6 + 0x154))
                    (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_64,&local_68);
  if (iVar7 == 0) {
    iVar7 = 0;
    pfVar2 = local_64;
    do {
      iVar8 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar7 + iVar8 + 0x10) != '\x01') {
        *pfVar2 = -*pfVar2;
      }
      bVar1 = iVar7 != 3;
      pfVar2 = pfVar2 + 1;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    piVar6 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
    iVar7 = (**(code **)(*piVar6 + 0x154))
                      (piVar6,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4),local_64,&local_68)
    ;
    if (iVar7 == 0) {
      return 0;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  ((int (*)())FUN_0017ebb0)(param_1,iVar7,local_68,uVar5);
  return 1;
}

/* FUN_0017f3f8 @ 0x17f3f8 (412 bytes) */
int FUN_0017f3f8(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_38 [6];
  
  iVar3 = FUN_00179c44(param_1,1,2);
  if (iVar3 != 0) {
    iVar3 = *(int *)(param_1 + 0xb0);
    if (((*(uint *)(iVar3 + 0xb8) & 1) != (*(uint *)(iVar3 + 0xd0) & 1)) &&
       ((*(uint *)(iVar3 + 0xb8) >> 1 & 1) == (*(uint *)(iVar3 + 0xd0) >> 1 & 1))) {
      bVar2 = true;
      iVar3 = FUN_001054ec(iVar3,0);
      uVar5 = 0;
      iVar6 = 0;
      local_38[0] = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = param_1;
      do {
        if (*(char *)((int)local_38 + iVar6) == '\0') {
          if (-1 < *(int *)(iVar3 + 0x178)) {
LAB_0017f514:
            iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0x88))();
            if (iVar3 == 0) {
              return 0;
            }
            ((int (*)())FUN_0017c244)(param_1,1);
            FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
            FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,param_2 ^ 1);
            FUN_001745ac(param_1);
            return 1;
          }
          puVar4 = (uint *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar3 + 0x178));
          if (bVar2) {
            uVar5 = *puVar4 >> 0x1f;
            bVar2 = false;
          }
          else if (*puVar4 >> 0x1f != uVar5) goto LAB_0017f514;
        }
        bVar1 = iVar6 == 3;
        iVar3 = iVar3 + 4;
        iVar6 = iVar6 + 1;
        if (bVar1) {
          ((int (*)())FUN_0017c244)(param_1,1);
          FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,(uint)(param_2 == uVar5));
          FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,2,0);
          FUN_001745ac(param_1);
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
  undefined4 uVar1;
  
  uVar1 = ((int (*)())FUN_0017f3f8)(param_1,1);
  return uVar1;
}

/* FUN_0017f59c @ 0x17f59c (8 bytes) */
int FUN_0017f59c(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())FUN_0017f3f8)(param_1,0);
  return uVar1;
}

/* FUN_0017f5a4 @ 0x17f5a4 (488 bytes) */
int FUN_0017f5a4(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  iVar1 = FUN_000f2e18(*(undefined4 *)(iVar1 + 0x10));
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_0010445c(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0x238),0)
    ;
    iVar1 = *(int *)(param_1 + 0x238);
    uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x6c4) + 0x3ac);
    iVar4 = *(int *)(iVar1 + 0x3ac) + -1;
    *(int *)(iVar1 + 0x3ac) = iVar4;
    uVar3 = FUN_00127608(uVar3,0,iVar4,0);
    FUN_0012306c(uVar3,*(undefined4 *)(param_1 + 0xb0));
    FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),0,uVar3);
    iVar1 = piVar2[0x23];
    *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x9f) = 1;
    piVar2[0x27] = 0x1010100;
    FUN_0012306c(iVar1,piVar2);
    iVar1 = 1;
    piVar5 = piVar2;
    while( true ) {
      iVar4 = (**(code **)(*piVar2 + 0x14))(piVar2);
      if (iVar4 < iVar1) break;
      FUN_001236e4(piVar5[0x29],iVar1,piVar2);
      iVar1 = iVar1 + 1;
      piVar5 = piVar5 + 6;
    }
    if ((*(uint *)(*(int *)(param_1 + 0xb0) + 0x14) & 0x200) == 0) {
      FUN_001049e8(*(int *)(param_1 + 0xb0),uVar3);
      FUN_001236e4(uVar3,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x84),*(int *)(param_1 + 0xb0));
      *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) | 0x200;
      iVar1 = FUN_00122fa4(uVar3,*(undefined4 *)
                                  (*(int *)(*(uint *)(param_1 + 0x238) + 0x6c4) + 0x3a0),
                           *(uint *)(param_1 + 0x238));
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x84) * 4 + param_1 + 0x210) =
           *(undefined4 *)(iVar1 + 0xb0);
      FUN_001049e8(piVar2,uVar3);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
      piVar2[5] = piVar2[5] | 0x200;
    }
    else {
      FUN_001046c8(piVar2,piVar2[0x21],uVar3);
      FUN_001236e4(uVar3,piVar2[0x21],piVar2);
    }
    FUN_001745ac(param_1);
    FUN_000e7738(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),*(int *)(param_1 + 0xb0),piVar2);
    return;
  }
  return;
}

/* FUN_0017f78c @ 0x17f78c (96 bytes) */
int FUN_0017f78c(param_1)
  int param_1;
{
  int iVar1;
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x98) != 0x2c) &&
     (iVar1 = FUN_0011379c(*(undefined4 *)(param_1 + 0x238),*(int *)(param_1 + 0xb0)), iVar1 != 0))
  {
    ((int (*)())FUN_0017f5a4)(param_1);
    return;
  }
  return;
}

/* FUN_0017f7ec @ 0x17f7ec (1848 bytes) */
int FUN_0017f7ec(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_38 [8];
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x80) == 1) &&
     (iVar2 = FUN_001054ec(*(int *)(param_1 + 0xb0),0), *(int *)(iVar2 + 0x10) == DAT_001b01d0)) {
    return 0;
  }
  piVar4 = local_38;
  iVar2 = 4;
  piVar3 = piVar4;
  do {
    *piVar3 = 0x7ffffffe;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar5 = 4;
  iVar2 = 0;
  do {
    *(undefined4 *)(iVar2 + (int)piVar4) = 0x7ffffffe;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar2 = ((int (*)())FUN_0017dbdc)(param_1,piVar4);
  if (iVar2 != 0) {
    return 0;
  }
  piVar3 = (int *)FUN_00112f54(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8));
  iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3,param_1,piVar4,*(undefined4 *)(param_1 + 0x238));
  if (iVar2 == 0) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  if (iVar2 == 0x1d) {
    FUN_00177ad0(param_1);
    iVar2 = ((int (*)())FUN_0017c0f8)(param_1);
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = FUN_0017ab4c(param_1);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = FUN_001766bc(param_1);
joined_r0x0017f980:
    if (iVar2 != 0) {
      return 1;
    }
  }
  else if (iVar2 < 0x1e) {
    if (iVar2 == 0x17) {
      iVar2 = ((int (*)())FUN_0017cb14)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017c888)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017f594)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00179e74(param_1,iVar5), iVar2 == 0)) {
            FUN_0017994c(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
    else if (iVar2 < 0x18) {
      if (iVar2 == 0x13) {
        FUN_00177ad0(param_1);
        iVar2 = ((int (*)())FUN_0017d57c)(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = ((int (*)())FUN_0017c774)(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),0xc);
        if ((iVar2 != 0) && (iVar2 = ((int (*)())FUN_0017e1f4)(param_1), iVar2 != 0)) {
          return 0;
        }
        iVar5 = 0;
        piVar3 = piVar4;
        do {
          iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
            iVar2 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_001768d4(param_1,iVar5), iVar2 == 0)) {
              FUN_00179f38(param_1,iVar5);
            }
          }
          bVar1 = iVar5 != 3;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (bVar1);
      }
      else {
        if (iVar2 != 0x14) goto LAB_0017fe28;
        FUN_00177ad0(param_1);
        iVar2 = ((int (*)())FUN_0017cd18)(param_1);
        if (iVar2 != 0) {
          return 0;
        }
        iVar2 = ((int (*)())FUN_0017e6c8)(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar2 = ((int (*)())FUN_0017e658)(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar2 = ((int (*)())FUN_0017f1f8)(param_1);
        if (iVar2 != 0) {
          return 1;
        }
        iVar5 = 0;
        piVar3 = piVar4;
        do {
          iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
            iVar2 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
            goto LAB_0017fe30;
            if (*piVar3 == 0x7ffffffe) {
              FUN_00179db0(param_1,iVar5);
            }
          }
          bVar1 = iVar5 != 3;
          piVar3 = piVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (bVar1);
      }
    }
    else {
      if (iVar2 != 0x19) {
        if (iVar2 == 0x1c) {
          FUN_00177ad0(param_1);
          iVar2 = ((int (*)())FUN_0017bf70)(param_1);
          if (iVar2 != 0) {
            return 0;
          }
          iVar2 = FUN_0017ab4c(param_1);
          goto joined_r0x0017f980;
        }
LAB_0017fe28:
        iVar2 = *(int *)(param_1 + 0x238);
        goto LAB_0017fe34;
      }
      iVar2 = ((int (*)())FUN_0017c910)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017c888)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017f59c)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00179e74(param_1,iVar5), iVar2 == 0)) {
            FUN_00179a34(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
  }
  else if (iVar2 < 0x2b) {
    if (iVar2 < 0x27) {
      if (iVar2 < 0x24) goto LAB_0017fe28;
      iVar2 = ((int (*)())FUN_0017c5e0)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017c41c)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017c4a4)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_0017a034(param_1,iVar5), iVar2 == 0)) {
            FUN_001797d0(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
    else {
      iVar2 = ((int (*)())FUN_0017d9b8)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = ((int (*)())FUN_0017d3f8)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = 0;
      piVar3 = piVar4;
      do {
        iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar5 + iVar2 + 0x10) != '\x01') {
          iVar2 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar2 + 0x658) <= *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8))
          goto LAB_0017fe30;
          if ((*piVar3 == 0x7ffffffe) && (iVar2 = FUN_00176954(param_1,iVar5), iVar2 == 0)) {
            FUN_00179894(param_1,iVar5);
          }
        }
        bVar1 = iVar5 != 3;
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
    }
  }
  else {
    if (iVar2 == 0x8b) {
      iVar2 = FUN_0017a748(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_0017a3d4(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      FUN_00177748(param_1);
      iVar5 = *(int *)(param_1 + 0xb0);
      iVar2 = *(int *)(param_1 + 0x238);
      goto LAB_0017fe34;
    }
    if (iVar2 != 0x8c) goto LAB_0017fe28;
    iVar2 = FUN_0017a8a4(param_1);
    if (iVar2 != 0) {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar2 = *(int *)(param_1 + 0x238);
LAB_0017fe34:
  iVar2 = FUN_00113090(*(undefined4 *)(*(int *)(iVar5 + 0x88) + 8),iVar2);
  if ((iVar2 == 0) &&
     (iVar2 = FUN_001131c0(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238)), iVar2 == 0)) {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*piVar4 != 0x7ffffffe) {
        FUN_001765a4(param_1,*piVar4,iVar2);
      }
      bVar1 = iVar2 != 3;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  else {
    iVar2 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
        return 0;
      }
      if (*piVar4 != 0x7ffffffe) {
        FUN_001765a4(param_1,*piVar4,iVar2);
      }
      bVar1 = iVar2 != 3;
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  return 0;
LAB_0017fe30:
  iVar5 = *(int *)(param_1 + 0xb0);
  goto LAB_0017fe34;
}

/* FUN_00180154 @ 0x180154 (888 bytes) */
int FUN_00180154(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8)) {
  case 0x16:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    FUN_0017662c(param_1);
    iVar5 = 0;
    iVar6 = param_1;
    do {
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (((*(char *)(iVar5 + iVar3 + 0x10) != '\x01') && (*(int *)(iVar6 + 0x30) == 0)) &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) < 1)) {
        iVar3 = *(int *)(iVar6 + 0x40);
        if (iVar3 == 0) {
          iVar3 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
          *(int *)(iVar6 + 0x40) = iVar3;
        }
        *(undefined4 *)(iVar3 + 0x10) = 4;
      }
      bVar1 = iVar5 != 3;
      iVar6 = iVar6 + 4;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    return;
  default:
    return;
  case 0x1c:
    break;
  case 0x1d:
    iVar5 = 0;
    iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar6 + 0x10) != DAT_001b01d0) {
      iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      iVar5 = FUN_000f30d4(*(undefined4 *)(iVar6 + 0x10));
    }
    if (*(int *)(iVar5 * 4 + param_1 + 0x30) == 0) {
      uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
      uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
      if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
        iVar6 = 0;
        do {
          iVar3 = FUN_00179608(param_1,iVar6,1,2);
          if (iVar3 == 0) {
            return;
          }
          bVar1 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar1);
        iVar6 = *(int *)(iVar5 * 4 + param_1 + 0x40);
        if (iVar6 == 0) {
          iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
        }
        *(undefined4 *)(iVar6 + 0xc) = 4;
        iVar5 = 4;
        do {
          *(int *)(param_1 + 0x40) = iVar6;
          param_1 = param_1 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    return;
  }
  iVar5 = 0;
  iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
  if (*(int *)(iVar6 + 0x10) != DAT_001b01d0) {
    iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar5 = FUN_000f30d4(*(undefined4 *)(iVar6 + 0x10));
  }
  if (*(int *)(iVar5 * 4 + param_1 + 0x30) == 0) {
    uVar4 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    if (((uVar2 & 1) == (uVar4 & 1)) && ((uVar2 >> 1 & 1) == (uVar4 >> 1 & 1))) {
      iVar6 = 0;
      do {
        iVar3 = FUN_00179608(param_1,iVar6,1,2);
        if (iVar3 == 0) {
          return;
        }
        bVar1 = iVar6 != 2;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar6 = *(int *)(iVar5 * 4 + param_1 + 0x40);
      if (iVar6 == 0) {
        iVar6 = FUN_00174ce0(*(undefined4 *)(param_1 + 0x238),iVar5,param_1);
      }
      iVar5 = 4;
      *(undefined4 *)(iVar6 + 0xc) = 4;
      do {
        *(int *)(param_1 + 0x40) = iVar6;
        param_1 = param_1 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

/* FUN_00180250 @ 0x180250 (1504 bytes) */
int FUN_00180250(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  int iVar19;
  int local_58;
  int local_54 [3];
  int local_48;
  int local_44 [7];
  
  piVar17 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar17[0x22] + 8) == 0x77) {
    iVar4 = FUN_001054ec(piVar17,1);
    local_54[0] = *(int *)(iVar4 + 0x10);
    bVar2 = false;
    iVar14 = 0;
    iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    local_58 = *(int *)(iVar4 + 0x10);
    iVar4 = param_1;
    do {
      if (*(int *)(iVar4 + 0x178) < 0) {
        pfVar5 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar4 + 0x178));
        local_44[1] = 0;
        if (0.0 <= *pfVar5) {
          if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x1000) != 0) {
            *(undefined1 *)((int)local_54 + iVar14) = 4;
            *(undefined1 *)((int)local_54 + iVar14 + -4) = 1;
          }
        }
        else {
          bVar2 = true;
        }
      }
      bVar1 = iVar14 != 3;
      iVar4 = iVar4 + 4;
      iVar14 = iVar14 + 1;
    } while (bVar1);
    if (bVar2) {
      bVar2 = false;
      iVar14 = 0;
      iVar4 = param_1;
      do {
        if (((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x1000) != 0) &&
           (*(int *)(iVar4 + 0x178) < 0)) {
          pfVar5 = (float *)FUN_00173360(*(int *)(param_1 + 0x238),*(int *)(iVar4 + 0x178));
          local_44[1] = 0;
          if (*pfVar5 < 0.0) {
            if (bVar2) {
              *(undefined1 *)((int)local_54 + iVar14) = 4;
              *(undefined1 *)((int)local_54 + iVar14 + -4) = 1;
            }
            bVar2 = true;
          }
        }
        bVar1 = iVar14 != 3;
        iVar4 = iVar4 + 4;
        iVar14 = iVar14 + 1;
      } while (bVar1);
    }
    iVar14 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
    iVar4 = local_54[0];
    if (local_54[0] == *(int *)(iVar14 + 0x10)) {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001803f4;
    }
    uVar13 = 1;
    iVar14 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),1);
    *(int *)(iVar14 + 0x10) = iVar4;
    *(int *)(*(int *)(param_1 + 0xb0) + 0x9c) = local_58;
    piVar17 = *(int **)(param_1 + 0xb0);
  }
  else {
LAB_001803f4:
    uVar13 = 0;
  }
  if (piVar17[0x20] == 0) {
LAB_001807f4:
    iVar4 = (**(code **)(*piVar17 + 0x68))(piVar17);
    if (iVar4 != 0) goto LAB_00180440;
  }
  else {
    iVar4 = FUN_00126760(piVar17[0x26]);
    if (((iVar4 == 0) || ((piVar17[5] & 2U) != 0)) ||
       (iVar4 = (**(code **)(*piVar17 + 0x50))(piVar17), iVar4 != 0)) {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001807f4;
    }
LAB_00180440:
    iVar4 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x28))();
    if ((iVar4 == 0) || ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x800) != 0))
    {
      piVar17 = *(int **)(param_1 + 0xb0);
      goto LAB_001804a4;
    }
  }
  piVar17 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar17[0x22] + 8) != 0x77) {
    return uVar13;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 8) & 0x800) == 0) {
    return uVar13;
  }
LAB_001804a4:
  iVar14 = 1;
  iVar4 = param_1;
  do {
    iVar6 = (**(code **)(*piVar17 + 0x14))(piVar17);
    if (iVar6 < iVar14) {
      return uVar13;
    }
    iVar6 = thunk_FUN_001268a4(*(undefined4 *)(iVar14 * 0x18 + *(int *)(param_1 + 0xb0) + 0x98));
    if (iVar6 != 0) {
      puVar18 = *(uint **)(*(int *)(iVar14 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar15 = puVar18[1];
      uVar16 = uVar15 - 1;
      if (uVar16 < *puVar18) {
        if (uVar15 <= uVar16) {
          _memset(uVar15 * 4 + puVar18[2],0,(uVar16 - uVar15) * 4 + 4);
          puVar18[1] = uVar15;
        }
        piVar17 = (int *)(uVar16 * 4 + puVar18[2]);
      }
      else {
        piVar17 = (int *)FUN_0019423c(puVar18,uVar16);
      }
      if ((*(int *)(*(int *)(*(int *)(*piVar17 + 0xb0) + 0x88) + 8) != 0x8e) ||
         (*(int *)(*piVar17 + 0xb4) != 0)) {
        iVar6 = FUN_001793d8(param_1,iVar14,*(undefined4 *)(iVar4 + 0x228));
        if (iVar6 == 4) {
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          local_58 = *(int *)(iVar6 + 0x10);
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          local_54[0] = *(int *)(iVar6 + 0x10);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(local_44,local_54[0],*(undefined4 *)(iVar4 + 0x228));
            local_54[0] = local_44[0];
          }
          iVar6 = param_1 + iVar14 * 4 + 0x220;
          iVar10 = param_1 + iVar14 * 0x10 + 0x160;
          pcVar8 = (char *)(iVar6 + 4);
          piVar17 = (int *)(iVar10 + 8);
          iVar7 = 0;
          do {
            if (*pcVar8 != '\0') {
              iVar19 = 4;
              pcVar12 = (char *)(iVar6 + 4);
              piVar11 = (int *)(iVar10 + 8);
              iVar9 = 0;
              do {
                if (*pcVar12 != '\0') {
                  if (iVar9 == iVar7) break;
                  if ((*piVar17 == *piVar11) &&
                     (cVar3 = *(char *)((int)local_54 + iVar9 + -4),
                     *(char *)((int)local_54 + iVar7) != cVar3)) {
                    *(char *)((int)local_54 + iVar7) = cVar3;
                    break;
                  }
                }
                iVar9 = iVar9 + 1;
                pcVar12 = pcVar12 + 1;
                piVar11 = piVar11 + 1;
                iVar19 = iVar19 + -1;
              } while (iVar19 != 0);
            }
            bVar2 = iVar7 != 3;
            pcVar8 = pcVar8 + 1;
            piVar17 = piVar17 + 1;
            iVar7 = iVar7 + 1;
          } while (bVar2);
          if ((local_54[0] != local_58) &&
             (piVar17 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c),
             iVar7 = (**(code **)(*piVar17 + 0x104))
                               (piVar17,*(undefined4 *)(param_1 + 0xb0),iVar14,local_54,0),
             iVar6 = local_54[0], iVar7 != 0)) {
            iVar7 = *(int *)(param_1 + 0xb0);
            if (iVar14 == 0) {
LAB_00180784:
              uVar13 = 1;
              *(int *)(iVar7 + 0x9c) = iVar6;
            }
            else {
              uVar13 = 1;
              iVar7 = FUN_001054ec(iVar7,iVar14);
              *(int *)(iVar7 + 0x10) = iVar6;
            }
          }
        }
        else {
          local_58 = *(int *)(PTR_DAT_001e8b8c + iVar6 * 4);
          iVar6 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                               *(undefined4 *)(param_1 + 0x238));
          if (iVar6 == 0) {
            FUN_000f3340(&local_48,local_58,*(undefined4 *)(iVar4 + 0x228));
            local_58 = local_48;
          }
          iVar6 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar14);
          if ((local_58 != *(int *)(iVar6 + 0x10)) &&
             (piVar17 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c),
             iVar7 = (**(code **)(*piVar17 + 0x104))
                               (piVar17,*(undefined4 *)(param_1 + 0xb0),iVar14,&local_58,0),
             iVar6 = local_58, iVar7 != 0)) {
            iVar7 = *(int *)(param_1 + 0xb0);
            if (iVar14 == 0) goto LAB_00180784;
            uVar13 = 1;
            iVar7 = FUN_001054ec(iVar7,iVar14);
            *(int *)(iVar7 + 0x10) = iVar6;
          }
        }
      }
    }
    piVar17 = *(int **)(param_1 + 0xb0);
    iVar14 = iVar14 + 1;
    iVar4 = iVar4 + 4;
  } while( true );
}

/* FUN_00180830 @ 0x180830 (2472 bytes) */
int FUN_00180830(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined4 uVar21;
  uint uVar22;
  int *piVar23;
  float fVar24;
  char *pcVar25;
  uint *puVar26;
  int iVar27;
  double dVar28;
  uint local_9c;
  float local_98 [4];
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
  
  if (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8)) {
    return 0;
  }
  piVar23 = *(int **)(param_1 + 0xb0);
  uVar14 = 0;
  for (iVar16 = 1; iVar4 = (**(code **)(*piVar23 + 0x14))(piVar23), iVar16 <= iVar4;
      iVar16 = iVar16 + 1) {
    piVar23 = *(int **)(param_1 + 0xb0);
    if ((piVar23[iVar16 * 6 + 0x28] & 2U) != 0) {
      puVar26 = *(uint **)(piVar23[iVar16 * 6 + 0x23] + 0x2c);
      uVar20 = puVar26[1];
      uVar17 = uVar20 - 1;
      if (uVar17 < *puVar26) {
        if (uVar20 <= uVar17) {
          _memset(uVar20 * 4 + puVar26[2],0,(uVar17 - uVar20) * 4 + 4);
          puVar26[1] = uVar20;
          piVar23 = *(int **)(param_1 + 0xb0);
        }
        puVar10 = (undefined4 *)(uVar17 * 4 + puVar26[2]);
      }
      else {
        puVar10 = (undefined4 *)FUN_0019423c(puVar26,uVar17);
        piVar23 = *(int **)(param_1 + 0xb0);
      }
      uVar21 = *puVar10;
      bVar2 = true;
      pcVar25 = (char *)(iVar16 * 4 + param_1 + 0x224);
      bVar3 = true;
      iVar4 = 0;
      do {
        if (*pcVar25 != '\0') {
          iVar18 = FUN_001054ec(piVar23,iVar16);
          iVar18 = FUN_00176518(uVar21,(uint)*(byte *)(iVar4 + iVar18 + 0x10));
          if (iVar18 == 0) {
            iVar18 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar16);
            iVar18 = FUN_001764fc(uVar21,(uint)*(byte *)(iVar4 + iVar18 + 0x10));
            if ((iVar18 == 0) || (!bVar3)) {
LAB_00180a10:
              piVar23 = *(int **)(param_1 + 0xb0);
              goto LAB_00180a14;
            }
            piVar23 = *(int **)(param_1 + 0xb0);
            bVar2 = false;
          }
          else {
            if (!bVar2) goto LAB_00180a10;
            piVar23 = *(int **)(param_1 + 0xb0);
            bVar3 = false;
          }
        }
        bVar1 = iVar4 != 3;
        pcVar25 = pcVar25 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      if (bVar2) {
        FUN_00103d50(piVar23 + iVar16 * 6 + 0x23,2,0);
        piVar23 = *(int **)(param_1 + 0xb0);
        uVar14 = 1;
      }
      else if ((bVar3) && ((piVar23[iVar16 * 6 + 0x28] & 1U) != 0)) {
        uVar14 = 1;
        FUN_00103d50(piVar23 + iVar16 * 6 + 0x23,2,0);
        FUN_00103d50(iVar16 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c,1,0);
        piVar23 = *(int **)(param_1 + 0xb0);
      }
    }
LAB_00180a14: ;
  }
  iVar16 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),10);
  if (iVar16 != 0) {
    iVar4 = 0x18;
    iVar16 = param_1;
    for (iVar18 = 1; iVar6 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar18 <= iVar6;
        iVar18 = iVar18 + 1) {
      iVar6 = FUN_00105dbc(*(undefined4 *)(param_1 + 0xb0),iVar18);
      if (iVar6 == 2) {
        puVar26 = *(uint **)(*(int *)(iVar4 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
        uVar17 = puVar26[1];
        uVar20 = uVar17 - 1;
        if (uVar20 < *puVar26) {
          if (uVar17 <= uVar20) {
            _memset(uVar17 * 4 + puVar26[2],0,(uVar20 - uVar17) * 4 + 4);
            puVar26[1] = uVar17;
          }
          piVar23 = (int *)(uVar20 * 4 + puVar26[2]);
        }
        else {
          piVar23 = (int *)FUN_0019423c(puVar26,uVar20);
        }
        iVar15 = *piVar23;
        iVar6 = *(int *)(iVar15 + 0x178);
        if (iVar6 < 0) {
          pfVar5 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar6);
          if (*(int *)(*(int *)(iVar15 + 0xb0) + 300) == 0) {
            dVar28 = _floor((double)*pfVar5);
            iVar6 = (int)dVar28;
            local_80 = (longlong)iVar6;
          }
          else {
            dVar28 = _floor((double)*pfVar5 + 0.5);
            iVar6 = (int)dVar28;
            local_88 = (longlong)iVar6;
          }
          iVar15 = FUN_00105c5c(*(undefined4 *)(param_1 + 0xb0),iVar18);
          iVar6 = iVar6 + iVar15;
          if (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x30c) + 0x2c) <= iVar6) {
            iVar6 = 0;
          }
          iVar15 = *(int *)(param_1 + 0xb0);
          uVar21 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3ac);
          if ((iVar18 < 1) || (iVar13 = FUN_00105594(iVar15,iVar18), iVar13 == 0)) {
            uVar19 = *(undefined4 *)(iVar4 + iVar15 + 0x98);
          }
          else {
            iVar15 = FUN_00105594(iVar15,iVar18);
            uVar19 = *(undefined4 *)(iVar15 + 0x98);
          }
          iVar15 = FUN_00126708(uVar19);
          if (iVar15 == 0) {
            uVar21 = FUN_00127608(uVar21,0,iVar6,0);
          }
          else {
            uVar21 = FUN_00127608(uVar21,2,iVar6,0);
          }
          FUN_001046c8(*(undefined4 *)(param_1 + 0xb0),iVar18,uVar21);
          FUN_001236e4(uVar21,iVar18,*(undefined4 *)(param_1 + 0xb0));
          iVar6 = FUN_00122fa4(uVar21,*(undefined4 *)
                                       (*(int *)(*(uint *)(param_1 + 0x238) + 0x6c4) + 0x3a0),
                               *(uint *)(param_1 + 0x238));
          *(undefined4 *)(iVar16 + 0x214) = *(undefined4 *)(iVar6 + 0xb0);
        }
      }
      iVar4 = iVar4 + 0x18;
      iVar16 = iVar16 + 4;
    }
  }
  piVar23 = *(int **)(param_1 + 0xb0);
  if (piVar23[0x20] == 0) {
LAB_001818e8:
    if (((piVar23[5] & 2U) != 0) || (iVar16 = FUN_001789d4(piVar23), iVar16 != 0))
    goto LAB_00180cb4;
  }
  else {
    iVar16 = FUN_00126760(piVar23[0x26]);
    if (((iVar16 == 0) || ((piVar23[5] & 2U) != 0)) ||
       (iVar16 = (**(code **)(*piVar23 + 0x50))(piVar23), iVar16 != 0)) {
      piVar23 = *(int **)(param_1 + 0xb0);
      goto LAB_001818e8;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
LAB_00180cb4:
    iVar16 = param_1;
    for (iVar4 = 1; iVar18 = (**(code **)(*piVar23 + 0x14))(piVar23), iVar4 <= iVar18;
        iVar4 = iVar4 + 1) {
      puVar26 = *(uint **)(*(int *)(iVar4 * 0x18 + *(int *)(param_1 + 0xb0) + 0x8c) + 0x2c);
      uVar20 = puVar26[1];
      uVar17 = uVar20 - 1;
      if (uVar17 < *puVar26) {
        if (uVar20 <= uVar17) {
          _memset(uVar20 * 4 + puVar26[2],0,(uVar17 - uVar20) * 4 + 4);
          puVar26[1] = uVar20;
        }
        piVar23 = (int *)(uVar17 * 4 + puVar26[2]);
      }
      else {
        piVar23 = (int *)FUN_0019423c(puVar26,uVar17);
      }
      piVar23 = *(int **)(*piVar23 + 0xb0);
      iVar18 = (**(code **)(*piVar23 + 0x74))(piVar23);
      if (((iVar18 != 0) && (*(int *)(piVar23[0x22] + 8) == 0xfb)) &&
         (iVar18 = FUN_00105dbc(*(undefined4 *)(param_1 + 0xb0),iVar4), iVar18 == 0)) {
        iVar18 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),iVar4);
        FUN_000f3398(&local_78,*(undefined4 *)(iVar18 + 0x10));
        local_9c = local_78;
        piVar11 = (int *)((int (*)())FUN_0017bc58)(piVar23,local_78,1,*(undefined4 *)(param_1 + 0x238));
        if (piVar11 != (int *)0x0) {
          iVar18 = (**(code **)(*piVar11 + 0x40))();
          if (iVar18 == 0) {
            iVar18 = FUN_001054ec(piVar11,0);
            FUN_000f3908(&local_74,*(undefined4 *)(iVar18 + 0x10));
            uVar17 = local_74;
            uVar20 = ~local_74;
            if (((uVar20 << 0x18 | (uVar20 & 0xff00) << 8 | uVar20 >> 8 & 0xff00 | uVar20 >> 0x18) &
                local_9c) == 0) {
              iVar18 = FUN_00105594(piVar11,1);
              *(int *)(iVar16 + 0x214) = iVar18;
              uVar19 = *(undefined4 *)(iVar18 + 0x8c);
              uVar21 = *(undefined4 *)(param_1 + 0xb0);
            }
            else {
              fVar7 = (float)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
              FUN_001046c8(fVar7,0,piVar23[0x23]);
              *(undefined4 *)((int)fVar7 + 0x98) = 0;
              *(undefined4 *)((int)fVar7 + 0x94) = *(undefined4 *)((int)fVar7 + 0x14c);
              iVar18 = FUN_00105594(piVar11,1);
              FUN_001046c8(fVar7,1,*(undefined4 *)(iVar18 + 0x8c));
              FUN_00106004(fVar7,1,iVar18,0,*(undefined4 *)(param_1 + 0x238));
              uVar20 = ~(uVar17 & local_9c);
              FUN_000f3764(&local_70,uVar17 & local_9c);
              *(undefined4 *)((int)fVar7 + 0x9c) = local_70;
              FUN_000f370c(&local_6c,local_70);
              uVar21 = local_6c;
              iVar18 = FUN_001054ec(fVar7,1);
              *(undefined4 *)(iVar18 + 0x10) = uVar21;
              iVar18 = 0;
              local_98[0] = fVar7;
              local_9c = (uVar20 << 0x18 | (uVar20 & 0xff00) << 8 | uVar20 >> 8 & 0xff00 |
                         uVar20 >> 0x18) & local_9c;
              if (local_9c == 0) {
LAB_00181100:
                pfVar5 = local_98 + iVar18;
                iVar6 = 0;
                do {
                  fVar24 = *pfVar5;
                  FUN_000e7700(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                               *(int *)(param_1 + 0xb0),fVar24);
                  FUN_0012306c(*(undefined4 *)((int)fVar24 + 0x8c),fVar24);
                  iVar15 = FUN_00105594(fVar24,1);
                  FUN_001236e4(*(undefined4 *)(iVar15 + 0x8c),1,fVar24);
                  uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x378);
                  puVar10 = (undefined4 *)FUN_00193e18(uVar21,0x240);
                  *puVar10 = uVar21;
                  puVar10 = puVar10 + 1;
                  FUN_00173938(puVar10,fVar24,*(undefined4 *)(param_1 + 0x238));
                  iVar6 = iVar6 + 1;
                  pfVar5 = pfVar5 + -1;
                  FUN_0011e988(puVar10,*(undefined4 *)
                                        (*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x3a0));
                  FUN_00173f1c(puVar10);
                  FUN_00174e0c(puVar10);
                  FUN_00175b40(puVar10);
                  FUN_00173278(puVar10);
                  FUN_000e9c00(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),
                               *(undefined4 *)((int)fVar24 + 0x8c),puVar10);
                } while (iVar18 + 1 != iVar6);
              }
              else {
                pfVar5 = local_98;
                iVar6 = 1;
                fVar24 = fVar7;
                do {
                  iVar18 = iVar6;
                  pfVar5 = pfVar5 + 1;
                  piVar11 = (int *)((int (*)())FUN_0017bc58)(piVar23,local_9c,0,*(undefined4 *)(param_1 + 0x238))
                  ;
                  if (piVar11 == (int *)0x0) goto LAB_00181220;
                  fVar8 = (float)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 0x238));
                  FUN_001046c8(fVar8,0,piVar23[0x23]);
                  *(undefined4 *)((int)fVar8 + 0x98) = 0;
                  *(undefined4 *)((int)fVar8 + 0x94) = *(undefined4 *)((int)fVar8 + 0x14c);
                  FUN_001049e8(fVar24,*(undefined4 *)((int)fVar8 + 0x8c));
                  FUN_00106804(fVar24,fVar8,0,*(undefined4 *)(param_1 + 0x238));
                  iVar6 = FUN_001054ec(piVar11,0);
                  FUN_000f3908(&local_68,*(undefined4 *)(iVar6 + 0x10));
                  uVar17 = local_68 & local_9c;
                  FUN_000f3764(&local_64,uVar17);
                  *(undefined4 *)((int)fVar8 + 0x9c) = local_64;
                  FUN_000f370c(&local_60,local_64);
                  uVar21 = local_60;
                  iVar6 = FUN_001054ec(fVar8,1);
                  *(undefined4 *)(iVar6 + 0x10) = uVar21;
                  iVar6 = (**(code **)(*piVar11 + 0x40))(piVar11);
                  if (iVar6 == 0) {
                    iVar6 = FUN_00105594(piVar11,1);
                    FUN_001046c8(fVar8,1,*(undefined4 *)(iVar6 + 0x8c));
                    FUN_00106004(fVar8,1,iVar6,0,*(undefined4 *)(param_1 + 0x238));
                  }
                  else {
                    iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
                    iVar6 = FUN_00123c08(iVar6,*(undefined4 *)(iVar6 + 0x3a0),0);
                    iVar6 = *(int *)(iVar6 + 0xb0);
                    FUN_001046c8(fVar8,1,*(undefined4 *)(iVar6 + 0x8c));
                    FUN_00106004(fVar8,1,iVar6,0,*(undefined4 *)(param_1 + 0x238));
                    local_9c = 0;
                  }
                  uVar17 = ~uVar17;
                  local_9c = (uVar17 << 0x18 | (uVar17 & 0xff00) << 8 | uVar17 >> 8 & 0xff00 |
                             uVar17 >> 0x18) & local_9c;
                  *pfVar5 = fVar8;
                  iVar6 = iVar18 + 1;
                  fVar24 = fVar8;
                } while (local_9c != 0);
                if (iVar18 + 1 == 0) goto LAB_00181220;
                if (-1 < iVar18) goto LAB_00181100;
              }
              *(float *)(iVar16 + 0x214) = fVar7;
              uVar19 = *(undefined4 *)((int)fVar7 + 0x8c);
              uVar21 = *(undefined4 *)(param_1 + 0xb0);
            }
          }
          else {
            iVar18 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
            iVar18 = FUN_00123c08(iVar18,*(undefined4 *)(iVar18 + 0x3a0),0);
            iVar18 = *(int *)(iVar18 + 0xb0);
            uVar21 = *(undefined4 *)(param_1 + 0xb0);
            *(int *)(iVar16 + 0x214) = iVar18;
            uVar19 = *(undefined4 *)(iVar18 + 0x8c);
          }
          FUN_001046c8(uVar21,iVar4,uVar19);
          FUN_001236e4(uVar19,iVar4,*(undefined4 *)(param_1 + 0xb0));
        }
      }
LAB_00181220:
      piVar23 = *(int **)(param_1 + 0xb0);
      iVar16 = iVar16 + 4;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
  }
  if (piVar23[0x20] != 0) {
    iVar16 = FUN_00126760(piVar23[0x26]);
    if (((iVar16 != 0) && ((piVar23[5] & 2U) == 0)) &&
       (iVar16 = (**(code **)(*piVar23 + 0x50))(piVar23), iVar16 == 0)) {
      piVar23 = *(int **)(param_1 + 0xb0);
      goto code_r0x001812b0;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
  }
  if (((piVar23[5] & 2U) == 0) && (iVar16 = FUN_001789d4(piVar23), iVar16 == 0)) {
    return uVar14;
  }
code_r0x001812b0:
  iVar15 = 1;
  iVar18 = param_1 + 0x170;
  iVar6 = param_1 + 0x224;
  iVar4 = 4;
  iVar16 = param_1;
  do {
    iVar13 = (**(code **)(*piVar23 + 0x14))(piVar23);
    if (iVar13 < iVar15) {
      return uVar14;
    }
    piVar23 = *(int **)(param_1 + 0xb0);
    uVar21 = *(undefined4 *)(piVar23[0x22] + 8);
    iVar9 = FUN_00176564(uVar21);
    iVar13 = 0x7ffffffe;
    if (iVar9 == 0) {
      iVar13 = FUN_00176574(uVar21);
      if (iVar13 == 0) {
        iVar13 = FUN_00113174(uVar21,*(undefined4 *)(param_1 + 0x238));
        if (iVar13 == 0) {
          iVar13 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                                *(undefined4 *)(param_1 + 0x238));
          if (iVar13 == 0) {
            FUN_001770e4(&local_50,param_1,iVar15);
            piVar23 = *(int **)(param_1 + 0xb0);
            iVar13 = local_50;
          }
          else {
            FUN_001769f4(&local_54,param_1,iVar15);
            piVar23 = *(int **)(param_1 + 0xb0);
            iVar13 = local_54;
          }
        }
        else {
          FUN_00178d78(&local_58,param_1,iVar15);
          piVar23 = *(int **)(param_1 + 0xb0);
          iVar13 = local_58;
        }
      }
      else {
        FUN_00178c84(&local_5c,param_1,iVar15);
        piVar23 = *(int **)(param_1 + 0xb0);
        iVar13 = local_5c;
      }
    }
    if ((piVar23[5] & 2U) == 0) {
code_r0x001813e0:
      if (((piVar23[iVar15 * 6 + 0x26] == 0x33) || (piVar23[iVar15 * 6 + 0x26] == 0xc)) ||
         (*(int *)(iVar6 + 4) == 0)) goto code_r0x001816c0;
      pcVar25 = (char *)(iVar6 + 4);
      local_98[3] = 0.0;
      piVar23 = (int *)(iVar18 + 8);
      local_98[0] = 0.0;
      bVar3 = true;
      local_98[1] = 0.0;
      iVar9 = 0;
      local_98[2] = 0.0;
      do {
        if (*pcVar25 != '\0') {
          if (*piVar23 < 0) {
            puVar10 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*piVar23);
            *(undefined4 *)((int)local_98 + iVar9) = *puVar10;
          }
          else {
            bVar3 = false;
          }
        }
        bVar2 = iVar9 != 0xc;
        pcVar25 = pcVar25 + 1;
        piVar23 = piVar23 + 1;
        iVar9 = iVar9 + 4;
      } while (bVar2);
      uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4);
      FUN_000f3340(local_4c,0x10203,*(undefined4 *)(iVar16 + 0x228));
      local_9c = local_4c[0];
      if (iVar13 != 0x7ffffffe) {
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 == 0) {
          iVar27 = 4;
          pcVar25 = (char *)(iVar4 + param_1 + 0x224);
          iVar9 = 0;
          do {
            if (*pcVar25 != '\0') {
              *(float *)(iVar9 + (int)local_98) = -*(float *)(iVar9 + (int)local_98);
            }
            pcVar25 = pcVar25 + 1;
            iVar9 = iVar9 + 4;
            iVar27 = iVar27 + -1;
          } while (iVar27 != 0);
          goto code_r0x00181590;
        }
code_r0x001815cc:
        uVar19 = 0;
code_r0x001815d0:
        piVar23 = *(int **)(param_1 + 0xb0);
        if (piVar23[iVar15 * 6 + 0x26] != *(int *)(iVar9 + 0x98)) {
          piVar11 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
          iVar27 = (**(code **)(*piVar11 + 0x11c))(piVar11,piVar23,iVar15,iVar9,0,uVar19);
          if (iVar27 == 0) goto code_r0x001816bc;
          uVar14 = FUN_0017ae28(param_1,iVar15,iVar9,local_9c,uVar19,0,
                                *(undefined4 *)(param_1 + 0x238));
          iVar27 = 0;
          *(undefined4 *)(iVar16 + 0x214) = uVar14;
          iVar9 = param_1;
          do {
            iVar12 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
            if (*(char *)(iVar27 + iVar12 + 0x10) == '\x01') {
              *(undefined4 *)(iVar9 + 0x30) = 0;
            }
            bVar3 = iVar27 != 3;
            iVar9 = iVar9 + 4;
            iVar27 = iVar27 + 1;
          } while (bVar3);
          piVar23 = *(int **)(param_1 + 0xb0);
          uVar14 = 1;
        }
        goto code_r0x001816c0;
      }
      if (bVar3) {
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 != 0) goto code_r0x001815cc;
        iVar27 = 4;
        pcVar25 = (char *)(iVar4 + param_1 + 0x224);
        iVar9 = 0;
        do {
          if (*pcVar25 != '\0') {
            *(float *)(iVar9 + (int)local_98) = -*(float *)(iVar9 + (int)local_98);
          }
          pcVar25 = pcVar25 + 1;
          iVar9 = iVar9 + 4;
          iVar27 = iVar27 + -1;
        } while (iVar27 != 0);
code_r0x00181590:
        piVar23 = *(int **)(*(int *)(param_1 + 0x238) + 0x30c);
        uVar19 = 1;
        iVar9 = (**(code **)(*piVar23 + 0x154))(piVar23,uVar21,local_98,&local_9c);
        if (iVar9 != 0) goto code_r0x001815d0;
code_r0x001816bc:
        piVar23 = *(int **)(param_1 + 0xb0);
        goto code_r0x001816c0;
      }
      piVar23 = *(int **)(param_1 + 0xb0);
    }
    else {
      iVar9 = (**(code **)(**(int **)(*(int *)(param_1 + 0x238) + 0x30c) + 0xbc))();
      if (iVar9 != 0) {
        piVar23 = *(int **)(param_1 + 0xb0);
        goto code_r0x001813e0;
      }
      piVar23 = *(int **)(param_1 + 0xb0);
code_r0x001816c0:
      if (iVar13 != 0x7ffffffe) {
        if (*(int *)(piVar23[0x22] + 8) != 0x8e) {
          pcVar25 = (char *)(iVar6 + 4);
          iVar9 = 4;
          iVar13 = 0;
          do {
            if (*pcVar25 != '\0') {
              iVar9 = FUN_001054ec(piVar23,iVar15);
              piVar23 = *(int **)(param_1 + 0xb0);
              uVar17 = (uint)*(byte *)(iVar13 + iVar9 + 0x10);
              goto code_r0x00181700;
            }
            iVar13 = iVar13 + 1;
            pcVar25 = pcVar25 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          uVar17 = 0;
code_r0x00181700:
          puVar26 = *(uint **)(piVar23[iVar15 * 6 + 0x23] + 0x2c);
          uVar20 = puVar26[1];
          uVar22 = uVar20 - 1;
          if (uVar22 < *puVar26) {
            if (uVar20 <= uVar22) {
              _memset(uVar20 * 4 + puVar26[2],0,(uVar22 - uVar20) * 4 + 4);
              puVar26[1] = uVar20;
            }
            piVar23 = (int *)(uVar22 * 4 + puVar26[2]);
          }
          else {
            piVar23 = (int *)FUN_0019423c(puVar26,uVar22);
          }
          piVar23 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),
                                        *(undefined4 *)(uVar17 * 4 + *piVar23 + 0x20));
          iVar13 = *piVar23;
        }
        piVar23 = (int *)FUN_00173e10(*(undefined4 *)(param_1 + 0x238),iVar13);
        if (*piVar23 == 0) {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
          if ((piVar23[iVar15 * 6 + 0x28] & 1U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,1,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
        else if (*piVar23 < 1) {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            iVar13 = *(int *)(param_1 + 0xb0) + iVar15 * 0x18 + 0x80;
            FUN_00103d50(iVar13 + 0xc,1,(*(uint *)(iVar13 + 0x20) ^ 1) & 1);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
        else {
          piVar23 = *(int **)(param_1 + 0xb0);
          if ((piVar23[iVar15 * 6 + 0x28] & 2U) != 0) {
            uVar14 = 1;
            FUN_00103d50(piVar23 + iVar15 * 6 + 0x23,2,0);
            piVar23 = *(int **)(param_1 + 0xb0);
          }
        }
      }
    }
    iVar15 = iVar15 + 1;
    iVar4 = iVar4 + 4;
    iVar6 = iVar6 + 4;
    iVar18 = iVar18 + 0x10;
    iVar16 = iVar16 + 4;
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
  
  iVar1 = FUN_0010497c(param_1,param_3);
  if ((((iVar1 == 0) || (iVar1 = (**(code **)(*param_1 + 0x68))(param_1), iVar1 != 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((*(int *)(param_1[0x22] + 8) == 0x8e || (uVar2 = 1, param_1[0x56] != param_2)))) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001819b4 @ 0x1819b4 (252 bytes) */
int FUN_001819b4(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  if ((((param_1[0x20] == 0) || (iVar1 = FUN_00126760(param_1[0x26]), iVar1 == 0)) ||
      ((param_1[5] & 2U) != 0)) || (iVar1 = (**(code **)(*param_1 + 0x50))(param_1), iVar1 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000f3a30(param_1);
  }
  if (((param_2[0x20] == 0) || (iVar2 = FUN_00126760(param_2[0x26]), iVar2 == 0)) ||
     (((param_2[5] & 2U) != 0 || (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 != 0)))) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_000f3a30(param_2);
  }
  return param_2[0x54] - iVar2 < param_1[0x54] - iVar1;
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
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x98) + 8);
  if (iVar1 != 0) {
    iVar5 = 0;
    iVar6 = *(int *)(param_2 + 0x98);
    do {
      iVar2 = iVar1;
      if ((*(uint *)(iVar6 + 0x14) & 1) != 0) {
        *(int *)(iVar6 + 0x150) = iVar5;
        uVar8 = *(undefined4 *)(*param_1 + 0x378);
        puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x1c);
        *puVar3 = uVar8;
        puVar9 = (uint *)param_1[7];
        uVar7 = puVar9[1];
        if (uVar7 < *puVar9) {
          _memset(uVar7 * 4 + puVar9[2],0,4);
          piVar4 = (int *)(uVar7 * 4 + puVar9[2]);
          puVar9[1] = uVar7 + 1;
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar9,uVar7);
        }
        *piVar4 = (int)(puVar3 + 1);
        iVar5 = iVar5 + 1;
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
  int iVar10;
  uint *puVar11;
  
  iVar1 = *(int *)(param_2 + 0x98);
  for (iVar10 = *(int *)(*(int *)(param_2 + 0x98) + 8); iVar10 != 0; iVar10 = *(int *)(iVar10 + 8))
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
        puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
      }
      puVar4 = (undefined4 *)*puVar4;
      *puVar4 = 1;
      puVar4[1] = 1;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 1;
      if ((*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e) && (0 < *(int *)(iVar1 + 0x84))) {
        iVar10 = 1;
        do {
          iVar5 = FUN_00105594(iVar1,iVar10);
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
              piVar6 = (int *)FUN_0019423c(puVar11,uVar9);
            }
            iVar2 = *(int *)(*piVar6 + 4) + 1;
            iVar5 = puVar4[1];
            if ((int)puVar4[1] < iVar2) {
              iVar5 = iVar2;
            }
            puVar4[1] = iVar5;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 <= *(int *)(iVar1 + 0x84));
      }
      iVar10 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar10;
  }
  *param_3 = 0;
  FUN_00172000(*(undefined4 *)(param_1 + 8));
  iVar1 = *(int *)(param_2 + 0xa0);
  for (iVar10 = *(int *)(*(int *)(param_2 + 0xa0) + 4); iVar10 != 0; iVar10 = *(int *)(iVar10 + 4))
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
        puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
      }
      piVar6 = (int *)*puVar4;
      FUN_00172204(*(undefined4 *)(param_1 + 8),iVar1);
      if (0 < *(int *)(iVar1 + 0x84)) {
        iVar10 = 1;
        do {
          iVar5 = FUN_00105594(iVar1,iVar10);
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
              puVar4 = (undefined4 *)FUN_0019423c(puVar11,uVar9);
            }
            piVar7 = (int *)*puVar4;
            iVar5 = *piVar7;
            if (*piVar7 < *piVar6 + 1) {
              iVar5 = *piVar6 + 1;
            }
            piVar7[4] = iVar10;
            *piVar7 = iVar5;
            piVar7[3] = iVar1;
            if (iVar5 < *param_3) {
              iVar5 = *param_3;
            }
            *param_3 = iVar5;
          }
          iVar10 = iVar10 + 1;
        } while (iVar10 <= *(int *)(iVar1 + 0x84));
      }
      iVar10 = *(int *)(iVar1 + 4);
    }
    iVar1 = iVar10;
  }
  uVar8 = (**(code **)(**(int **)(param_1 + 8) + 0x5c))();
  *param_4 = uVar8;
  return;
}

/* FUN_00181f00 @ 0x181f00 (220 bytes) */
int FUN_00181f00(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  int iVar19;
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
  
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar5 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar16 = puVar5 + 1;
  *puVar5 = uVar21;
  puVar5[1] = 2;
  puVar5[4] = uVar21;
  puVar5[2] = 0;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar5[3] = uVar21;
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar6 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar18 = puVar6 + 1;
  *puVar6 = uVar21;
  puVar6[1] = 2;
  puVar6[4] = uVar21;
  puVar6[2] = 0;
  uVar21 = FUN_00193e18(uVar21,8);
  puVar6[3] = uVar21;
  uVar21 = *(undefined4 *)(*param_1 + 0x378);
  puVar7 = (undefined4 *)FUN_00193e18(uVar21,0x14);
  puVar17 = puVar7 + 1;
  *puVar7 = uVar21;
  puVar7[1] = 2;
  puVar7[2] = 0;
  puVar7[4] = uVar21;
  uVar21 = FUN_00193e18(uVar21,8);
  uVar22 = puVar5[2];
  uVar2 = *puVar16;
  puVar7[3] = uVar21;
  if (uVar22 < uVar2) {
    _memset((void *)(uVar22 * 4 + puVar5[3]),0,4);
    piVar8 = (int *)(uVar22 * 4 + puVar5[3]);
    puVar5[2] = uVar22 + 1;
  }
  else {
    piVar8 = (int *)FUN_0019423c(puVar16,uVar22);
  }
  *piVar8 = param_3;
  while (uVar2 = puVar5[2], uVar2 != 0) {
    piVar8 = (int *)0x0;
    if (uVar2 - 1 < uVar2) {
      piVar8 = (int *)((uVar2 - 1) * 4 + puVar5[3]);
    }
    iVar15 = *piVar8;
    iVar19 = 1;
    FUN_00194208(puVar16,uVar2 - 1);
    puVar24 = (uint *)(iVar15 + 0xb8);
    iVar3 = 0x18;
    do {
      iVar10 = FUN_00105594(iVar15,iVar19);
      if (param_2 == *(int *)(iVar10 + 0x158)) {
        puVar23 = (uint *)param_1[7];
        uVar2 = *(uint *)(iVar10 + 0x150);
        if (uVar2 < *puVar23) {
          uVar22 = puVar23[1];
          if (uVar22 <= uVar2) {
            _memset((void *)(uVar22 * 4 + puVar23[2]),0,(uVar2 - uVar22) * 4 + 4);
            puVar23[1] = uVar2 + 1;
          }
          piVar8 = (int *)(uVar2 * 4 + puVar23[2]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar23,uVar2);
        }
        if (*(int *)(*piVar8 + 0x14) == 0) {
          if (((*puVar24 & 2) != 0) && (*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x13)) {
            iVar4 = 1;
            iVar13 = iVar10 + 0x98;
            do {
              FUN_00103d50(iVar13 + 0xc,2,1);
              if ((*(uint *)(iVar13 + 0x20) & 1) != 0) {
                FUN_00103d50(iVar13 + 0xc,1,0);
              }
              bVar1 = iVar4 != 2;
              iVar13 = iVar13 + 0x18;
              iVar4 = iVar4 + 1;
            } while (bVar1);
            FUN_00103d50(iVar3 + iVar15 + 0x8c,2,0);
          }
          uVar2 = *(uint *)(iVar3 + iVar15 + 0xa0);
          if ((((uVar2 & 1) != 0) && ((uVar2 & 2) == 0)) &&
             (*(int *)(*(int *)(iVar10 + 0x88) + 8) == 0x12)) {
            iVar4 = 1;
            iVar13 = iVar10 + 0x98;
            do {
              FUN_00103d50(iVar13 + 0xc,1,*(uint *)(iVar13 + 0x20) & 1 ^ 1);
              bVar1 = iVar4 != 2;
              iVar13 = iVar13 + 0x18;
              iVar4 = iVar4 + 1;
            } while (bVar1);
            FUN_00103d50(iVar3 + iVar15 + 0x8c,1,0);
          }
          uVar2 = puVar5[2];
          if (uVar2 < *puVar16) {
            _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
            piVar8 = (int *)(uVar2 * 4 + puVar5[3]);
            puVar5[2] = uVar2 + 1;
          }
          else {
            piVar8 = (int *)FUN_0019423c(puVar16,uVar2);
          }
          *piVar8 = iVar10;
        }
      }
      bVar1 = iVar19 != 2;
      iVar3 = iVar3 + 0x18;
      puVar24 = puVar24 + 6;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    iVar3 = FUN_001054ec(iVar15,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 != 0) {
      iVar3 = FUN_001054ec(iVar15,2);
      FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    }
    iVar3 = FUN_001054ec(iVar15,1);
    iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
    if (iVar3 == 0) {
      iVar3 = FUN_001054ec(iVar15,2);
      iVar3 = FUN_000f2c5c(*(undefined4 *)(iVar3 + 0x10));
      if (iVar3 != 0) {
        uVar2 = puVar6[2];
        if (uVar2 < *puVar18) {
          _memset((void *)(uVar2 * 4 + puVar6[3]),0,4);
          piVar8 = (int *)(uVar2 * 4 + puVar6[3]);
          puVar6[2] = uVar2 + 1;
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
        }
        *piVar8 = iVar15;
        uVar2 = puVar7[2];
        if (uVar2 < *puVar17) {
          _memset((void *)(uVar2 * 4 + puVar7[3]),0,4);
          puVar11 = (undefined4 *)(uVar2 * 4 + puVar7[3]);
          puVar7[2] = uVar2 + 1;
        }
        else {
          puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
        }
        *puVar11 = 2;
      }
    }
    else {
      uVar2 = puVar6[2];
      if (uVar2 < *puVar18) {
        _memset((void *)(uVar2 * 4 + puVar6[3]),0,4);
        piVar8 = (int *)(uVar2 * 4 + puVar6[3]);
        puVar6[2] = uVar2 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      *piVar8 = iVar15;
      uVar2 = puVar7[2];
      if (uVar2 < *puVar17) {
        _memset((void *)(uVar2 * 4 + puVar7[3]),0,4);
        puVar11 = (undefined4 *)(uVar2 * 4 + puVar7[3]);
        puVar7[2] = uVar2 + 1;
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      *puVar11 = 1;
    }
  }
  iVar3 = *(int *)(*(int *)(param_3 + 0x88) + 8);
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
  iVar3 = puVar6[2];
  uVar22 = iVar3 - 1;
  uVar2 = uVar22;
  if ((int)uVar22 < 1) {
    iVar15 = 0;
  }
  else {
    iVar19 = uVar22 * 4;
    iVar4 = iVar19 + -4;
    iVar15 = 0;
    iVar10 = iVar3;
    do {
      iVar13 = FUN_001043f0(local_5c,*param_1);
      uVar21 = DAT_001b0210;
      *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
      uVar14 = uVar2 - 1;
      *(undefined4 *)(iVar13 + 0x98) = 0;
      *(undefined4 *)(iVar13 + 0x9c) = uVar21;
      uVar26 = *puVar18;
      if (uVar14 < uVar26) {
        uVar9 = puVar6[2];
        if (uVar9 <= uVar14) {
          _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar14 - uVar9) * 4 + 4);
          uVar26 = *puVar18;
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
        uVar26 = *puVar18;
      }
      if (param_3 != *piVar8) {
        if (uVar14 < uVar26) {
          uVar9 = puVar6[2];
          if (uVar9 <= uVar14) {
            _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar14 - uVar9) * 4 + 4);
            uVar26 = *puVar18;
            puVar6[2] = uVar2;
          }
          piVar8 = (int *)(iVar4 + puVar6[3]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
          uVar26 = *puVar18;
        }
        iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
      }
      if (uVar2 < uVar26) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      if (param_3 != *piVar8) {
        if (uVar2 < *puVar18) {
          uVar26 = puVar6[2];
          if (uVar26 <= uVar2) {
            _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
            puVar6[2] = iVar10;
          }
          piVar8 = (int *)(iVar19 + puVar6[3]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
        }
        iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
      }
      if (iVar15 != 0) {
        iVar20 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
        if (iVar15 < iVar20) {
          *(int *)(iVar13 + 0x124) = iVar20;
          iVar15 = iVar15 - *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
        }
        else {
          iVar20 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
          if (iVar20 < iVar15) {
            *(int *)(iVar13 + 0x124) = iVar20;
            iVar15 = iVar15 - *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
          }
          else {
            *(int *)(iVar13 + 0x124) = iVar15;
            iVar15 = 0;
          }
        }
      }
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar14);
      }
      uVar21 = FUN_00105594(uVar21,*puVar11);
      FUN_00106004(iVar13,1,uVar21,0,*param_1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      uVar21 = FUN_00105594(uVar21,*puVar11);
      FUN_00106004(iVar13,2,uVar21,0,*param_1);
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar14);
      }
      uVar21 = *puVar11;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        puVar11 = (undefined4 *)(iVar4 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar14);
      }
      iVar20 = FUN_001054ec(uVar21,*puVar11);
      FUN_000f33f8(&local_68,*(undefined4 *)(iVar20 + 0x10));
      uVar26 = local_68 & 0xff;
      if (uVar2 < *puVar18) {
        uVar9 = puVar6[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + puVar6[3]),0,(uVar2 - uVar9) * 4 + 4);
          puVar6[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar2);
      }
      uVar21 = *puVar11;
      if (uVar2 < *puVar17) {
        uVar9 = puVar7[2];
        if (uVar9 <= uVar2) {
          _memset((void *)(uVar9 * 4 + puVar7[3]),0,(uVar2 - uVar9) * 4 + 4);
          puVar7[2] = iVar10;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar7[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar17,uVar2);
      }
      iVar20 = FUN_001054ec(uVar21,*puVar11);
      FUN_000f33f8(&local_64,*(undefined4 *)(iVar20 + 0x10));
      uVar9 = local_64 & 0xff;
      iVar20 = FUN_001054ec(iVar13,1);
      *(uint *)(iVar20 + 0x10) = uVar26 | 0x4040400;
      iVar20 = FUN_001054ec(iVar13,2);
      *(uint *)(iVar20 + 0x10) = uVar9 | 0x4040400;
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar14);
      }
      FUN_00103d50(iVar13 + 0xa4,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar2);
      }
      FUN_00103d50(iVar13 + 0xbc,1,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) & 1);
      if (uVar14 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar6[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar14);
      }
      iVar20 = *piVar8;
      if (uVar14 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar14) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar14 - uVar26) * 4 + 4);
          puVar7[2] = uVar2;
        }
        piVar8 = (int *)(iVar4 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar14);
      }
      FUN_00103d50(iVar13 + 0xa4,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      if (uVar2 < *puVar18) {
        uVar26 = puVar6[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar6[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar6[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar2);
      }
      iVar20 = *piVar8;
      if (uVar2 < *puVar17) {
        uVar26 = puVar7[2];
        if (uVar26 <= uVar2) {
          _memset((void *)(uVar26 * 4 + puVar7[3]),0,(uVar2 - uVar26) * 4 + 4);
          puVar7[2] = iVar10;
        }
        piVar8 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar17,uVar2);
      }
      FUN_00103d50(iVar13 + 0xbc,2,*(uint *)(*piVar8 * 0x18 + iVar20 + 0xa0) >> 1 & 1);
      *(undefined4 *)(iVar13 + 0x150) = *(undefined4 *)(param_1[7] + 4);
      uVar21 = *(undefined4 *)(*param_1 + 0x378);
      puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
      *puVar11 = uVar21;
      puVar24 = (uint *)param_1[7];
      uVar26 = puVar24[1];
      if (uVar26 < *puVar24) {
        _memset((void *)(uVar26 * 4 + puVar24[2]),0,4);
        piVar8 = (int *)(uVar26 * 4 + puVar24[2]);
        puVar24[1] = uVar26 + 1;
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar24,uVar26);
      }
      *piVar8 = (int)(puVar11 + 1);
      FUN_00193f64(auStack_88,iVar13);
      uVar2 = uVar2 - 2;
      iVar19 = iVar19 + -8;
      iVar4 = iVar4 + -8;
      iVar10 = iVar10 + -2;
    } while (0 < (int)uVar2);
  }
  iVar19 = local_80;
  if (uVar2 == 0) {
    iVar10 = FUN_001043f0(local_5c,*param_1);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(iVar10 + 0x98) = 0;
    *(undefined4 *)(iVar10 + 0x94) = *(undefined4 *)(iVar10 + 0x14c);
    *(undefined4 *)(iVar10 + 0x9c) = uVar21;
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    if (param_3 != *piVar8) {
      if (*puVar18 == 0) {
        piVar8 = (int *)FUN_0019423c(puVar18,0);
      }
      else {
        if (puVar6[2] == 0) {
          *(undefined4 *)puVar6[3] = 0;
          puVar6[2] = 1;
        }
        piVar8 = (int *)puVar6[3];
      }
      iVar15 = iVar15 + *(int *)(*piVar8 + 0x124);
    }
    if (iVar15 == 0) {
      iVar4 = *param_1;
      iVar15 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
      if (iVar15 < iVar4) {
        *(int *)(iVar10 + 0x124) = iVar4;
        iVar4 = *param_1;
        iVar15 = iVar15 - *(int *)(*(int *)(iVar4 + 0x30c) + 0x58);
      }
      else {
        iVar4 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
        if (iVar4 < iVar15) {
          *(int *)(iVar10 + 0x124) = iVar4;
          iVar4 = *param_1;
          iVar15 = iVar15 - *(int *)(*(int *)(iVar4 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(iVar10 + 0x124) = iVar15;
          iVar15 = 0;
          iVar4 = *param_1;
        }
      }
    }
    FUN_00106004(iVar10,1,iVar19,0,iVar4);
    uVar21 = UNK_001b020c;
    iVar4 = FUN_001054ec(iVar10,1);
    *(undefined4 *)(iVar4 + 0x10) = uVar21;
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      puVar11 = (undefined4 *)puVar6[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      puVar11 = (undefined4 *)puVar7[3];
    }
    uVar21 = FUN_00105594(uVar21,*puVar11);
    FUN_00106004(iVar10,2,uVar21,0,*param_1);
    if (*puVar18 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      puVar11 = (undefined4 *)puVar6[3];
    }
    uVar21 = *puVar11;
    if (*puVar17 == 0) {
      puVar11 = (undefined4 *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      puVar11 = (undefined4 *)puVar7[3];
    }
    iVar4 = FUN_001054ec(uVar21,*puVar11);
    FUN_000f33f8(&local_60,*(undefined4 *)(iVar4 + 0x10));
    iVar4 = FUN_001054ec(iVar10,2);
    *(uint *)(iVar4 + 0x10) = local_60 & 0xff | 0x4040400;
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    iVar4 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    FUN_00103d50(iVar10 + 0xbc,1,*(uint *)(*piVar8 * 0x18 + iVar4 + 0xa0) & 1);
    if (*puVar18 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar18,0);
    }
    else {
      if (puVar6[2] == 0) {
        *(undefined4 *)puVar6[3] = 0;
        puVar6[2] = 1;
      }
      piVar8 = (int *)puVar6[3];
    }
    iVar4 = *piVar8;
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    FUN_00103d50(iVar10 + 0xbc,2,*(uint *)(*piVar8 * 0x18 + iVar4 + 0xa0) >> 1 & 1);
    FUN_00193f64(auStack_88,iVar10);
    *(undefined4 *)(iVar10 + 0x150) = *(undefined4 *)(param_1[7] + 4);
    uVar21 = *(undefined4 *)(*param_1 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
    *puVar11 = uVar21;
    puVar24 = (uint *)param_1[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)FUN_0019423c(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    iVar19 = *(int *)(iVar19 + 8);
  }
  while (iVar10 = *(int *)(iVar19 + 8), *(int *)(iVar10 + 8) != 0) {
    iVar4 = FUN_001043f0(local_5c,*param_1);
    uVar21 = DAT_001b0210;
    *(undefined4 *)(iVar4 + 0x98) = 0;
    *(undefined4 *)(iVar4 + 0x94) = *(undefined4 *)(iVar4 + 0x14c);
    *(undefined4 *)(iVar4 + 0x9c) = uVar21;
    if (iVar15 == 0) {
      iVar13 = *param_1;
    }
    else {
      iVar13 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x58);
      if (iVar15 < iVar13) {
        *(int *)(iVar4 + 0x124) = iVar13;
        iVar13 = *param_1;
        iVar15 = iVar15 - *(int *)(*(int *)(iVar13 + 0x30c) + 0x58);
      }
      else {
        iVar13 = *(int *)(*(int *)(*param_1 + 0x30c) + 0x5c);
        if (iVar13 < iVar15) {
          *(int *)(iVar4 + 0x124) = iVar13;
          iVar13 = *param_1;
          iVar15 = iVar15 - *(int *)(*(int *)(iVar13 + 0x30c) + 0x5c);
        }
        else {
          *(int *)(iVar4 + 0x124) = iVar15;
          iVar15 = 0;
          iVar13 = *param_1;
        }
      }
    }
    FUN_00106004(iVar4,1,iVar19,0,iVar13);
    FUN_00106004(iVar4,2,iVar10,0,*param_1);
    uVar21 = UNK_001b020c;
    iVar19 = FUN_001054ec(iVar4,1);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    iVar19 = FUN_001054ec(iVar4,2);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    FUN_00193f64(auStack_88,iVar4);
    *(undefined4 *)(iVar4 + 0x150) = *(undefined4 *)(param_1[7] + 4);
    uVar21 = *(undefined4 *)(*param_1 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar21,0x1c);
    *puVar11 = uVar21;
    puVar24 = (uint *)param_1[7];
    uVar2 = puVar24[1];
    if (uVar2 < *puVar24) {
      _memset((void *)(uVar2 * 4 + puVar24[2]),0,4);
      piVar8 = (int *)(uVar2 * 4 + puVar24[2]);
      puVar24[1] = uVar2 + 1;
    }
    else {
      piVar8 = (int *)FUN_0019423c(puVar24,uVar2);
    }
    *piVar8 = (int)(puVar11 + 1);
    iVar19 = *(int *)(iVar10 + 8);
  }
  if (-1 < (int)uVar22) {
    iVar19 = uVar22 * 4;
    iVar10 = 0;
    iVar15 = iVar3;
    do {
      uVar2 = *puVar18;
      uVar26 = uVar22 - iVar10;
      if (uVar26 < uVar2) {
        uVar14 = puVar6[2];
        if (uVar14 <= uVar26) {
          _memset((void *)(uVar14 * 4 + puVar6[3]),0,(uVar26 - uVar14) * 4 + 4);
          uVar2 = *puVar18;
          puVar6[2] = iVar15;
        }
        piVar8 = (int *)(iVar19 + puVar6[3]);
      }
      else {
        piVar8 = (int *)FUN_0019423c(puVar18,uVar26);
        uVar2 = *puVar18;
      }
      if (param_3 == *piVar8) goto code_r0x001836f0;
      if (uVar26 < uVar2) {
        uVar2 = puVar6[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + puVar6[3]),0,(uVar26 - uVar2) * 4 + 4);
          puVar6[2] = iVar15;
        }
        puVar11 = (undefined4 *)(iVar19 + puVar6[3]);
      }
      else {
        puVar11 = (undefined4 *)FUN_0019423c(puVar18,uVar26);
      }
      piVar8 = (int *)*puVar11;
      if (uVar26 < *puVar17) {
        uVar2 = puVar7[2];
        if (uVar2 <= uVar26) {
          _memset((void *)(uVar2 * 4 + puVar7[3]),0,(uVar26 - uVar2) * 4 + 4);
          puVar7[2] = iVar15;
        }
        piVar12 = (int *)(iVar19 + puVar7[3]);
      }
      else {
        piVar12 = (int *)FUN_0019423c(puVar17,uVar26);
      }
      iVar4 = (*piVar12 == 1) + 1;
      FUN_0010497c(piVar8,param_1[1]);
      puVar24 = (uint *)param_1[7];
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
        piVar12 = (int *)FUN_0019423c(puVar24,uVar2);
      }
      iVar25 = *(int *)(*piVar12 + 0x10);
      iVar20 = *(int *)(*piVar12 + 0xc);
      uVar21 = FUN_00105594(piVar8,iVar4);
      FUN_00106004(iVar20,iVar25,uVar21,0,*param_1);
      iVar13 = FUN_001054ec(piVar8,iVar4);
      uVar21 = *(undefined4 *)(iVar13 + 0x10);
      iVar13 = FUN_001054ec(iVar20,iVar25);
      *(undefined4 *)(iVar13 + 0x10) = uVar21;
      if ((*(uint *)(iVar25 * 0x18 + iVar20 + 0xa0) & 1) == 0) {
        uVar2 = piVar8[iVar4 * 6 + 0x28] & 1;
      }
      else {
        uVar2 = piVar8[iVar4 * 6 + 0x28] & 1U ^ 1;
      }
      iVar13 = iVar25 * 0x18 + iVar20 + 0x8c;
      FUN_00103d50(iVar13,1,uVar2);
      FUN_00103d50(iVar13,2,(uint)piVar8[iVar4 * 6 + 0x28] >> 1 & 1);
      (**(code **)(*piVar8 + 0xc))(piVar8,0,*param_1);
      iVar10 = iVar10 + 1;
      iVar19 = iVar19 + -4;
      iVar15 = iVar15 + -1;
    } while (iVar10 != iVar3);
  }
  uVar2 = *puVar18;
code_r0x001836f0:
  if (uVar2 == 0) {
    piVar8 = (int *)FUN_0019423c(puVar18,0);
  }
  else {
    if (puVar6[2] == 0) {
      *(undefined4 *)puVar6[3] = 0;
      puVar6[2] = 1;
    }
    piVar8 = (int *)puVar6[3];
  }
  if (param_3 == *piVar8) {
    iVar19 = *(int *)(local_80 + 8);
    iVar3 = local_80;
    while (iVar15 = iVar19, iVar15 != 0) {
      FUN_0019401c(iVar3);
      FUN_000e7700(param_2,param_3,iVar3);
      iVar3 = iVar15;
      iVar19 = *(int *)(iVar15 + 8);
    }
    if (*puVar17 == 0) {
      piVar8 = (int *)FUN_0019423c(puVar17,0);
    }
    else {
      if (puVar7[2] == 0) {
        *(undefined4 *)puVar7[3] = 0;
        puVar7[2] = 1;
      }
      piVar8 = (int *)puVar7[3];
    }
    iVar19 = *piVar8;
    FUN_00106004(param_3,iVar19,*(undefined4 *)(param_3 + 4),0,*param_1);
    uVar21 = UNK_001b020c;
    iVar3 = FUN_001054ec(param_3,iVar19);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    iVar3 = iVar19 * 0x18 + param_3 + 0x8c;
    FUN_00103d50(iVar3,1,0);
    FUN_00103d50(iVar3,2,0);
  }
  else {
    iVar3 = FUN_001043f0(local_5c,*param_1);
    *(undefined4 *)(iVar3 + 0x98) = 0;
    *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x14c);
    iVar19 = FUN_001054ec(param_3,0);
    *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar19 + 0x10);
    uVar21 = FUN_00105594(param_3,1);
    FUN_00106004(iVar3,1,uVar21,0,*param_1);
    uVar21 = FUN_00105594(param_3,2);
    FUN_00106004(iVar3,2,uVar21,0,*param_1);
    iVar19 = FUN_001054ec(param_3,1);
    uVar21 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = FUN_001054ec(iVar3,1);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    iVar19 = FUN_001054ec(param_3,2);
    uVar21 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = FUN_001054ec(iVar3,2);
    uVar2 = *(uint *)(param_3 + 0xb8);
    *(undefined4 *)(iVar19 + 0x10) = uVar21;
    FUN_00103d50(iVar3 + 0xa4,1,uVar2 & 1);
    FUN_00103d50(iVar3 + 0xbc,1,*(uint *)(param_3 + 0xd0) & 1);
    FUN_00103d50(iVar3 + 0xa4,2,*(uint *)(param_3 + 0xb8) >> 1 & 1);
    FUN_00103d50(iVar3 + 0xbc,2,*(uint *)(param_3 + 0xd0) >> 1 & 1);
    FUN_000e7700(param_2,param_3,iVar3);
    FUN_00106004(param_3,1,iVar3,0,*param_1);
    uVar21 = UNK_001b0208;
    iVar3 = FUN_001054ec(param_3,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    FUN_00103d50(param_3 + 0xa4,1,0);
    FUN_00103d50(param_3 + 0xa4,2,0);
    iVar3 = *(int *)(local_80 + 8);
    while (iVar19 = iVar3, iVar19 != 0) {
      FUN_0019401c(local_80);
      FUN_000e7700(param_2,param_3,local_80);
      local_80 = iVar19;
      iVar3 = *(int *)(iVar19 + 8);
    }
    FUN_00106004(param_3,2,*(undefined4 *)(param_3 + 4),0,*param_1);
    uVar21 = UNK_001b020c;
    iVar3 = FUN_001054ec(param_3,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar21;
    FUN_00103d50(param_3 + 0xbc,1,0);
    FUN_00103d50(param_3 + 0xbc,2,0);
    FUN_000f35c4(param_3);
  }
  if (puVar17 != (uint *)0x0) {
    FUN_00193cc0(puVar7[4],puVar7[3]);
    FUN_00193cc0(*puVar7,puVar7);
  }
  if (puVar18 != (uint *)0x0) {
    FUN_00193cc0(puVar6[4],puVar6[3]);
    FUN_00193cc0(*puVar6,puVar6);
  }
  if (puVar16 != (uint *)0x0) {
    FUN_00193cc0(puVar5[4],puVar5[3]);
    FUN_00193cc0(*puVar5,puVar5);
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
  uint uVar5;
  uint *puVar6;
  
  uVar5 = 0;
  puVar6 = *(uint **)(param_1 + 0x1c);
  uVar4 = puVar6[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (uVar5 < *puVar6) {
        uVar1 = puVar6[1];
        if (uVar1 <= uVar5) {
          _memset(uVar1 * 4 + puVar6[2],0,(uVar5 - uVar1) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        piVar2 = (int *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar6,uVar5);
      }
      uVar5 = uVar5 + 1;
      iVar3 = *piVar2;
      if (iVar3 != 0) {
        FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (uVar4 == uVar5) break;
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
  int iVar5;
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
            piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
            param_7 = *(int *)(iVar7 + 0x88);
          }
          iVar1 = *piVar3;
          if ((((((iVar6 == *(int *)(param_7 + 8)) && (*(int *)(iVar7 + 0x120) == 0)) &&
                ((*(uint *)(iVar7 + 0x14) & 0x200) == 0)) &&
               (((iVar6 != 0x12 || (*(int *)(iVar7 + 0x124) == 0)) &&
                ((iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b021c &&
                 ((iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0218 &&
                  (iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0214)))))))) &&
              (iVar4 = FUN_001054ec(iVar7,0), *(int *)(iVar4 + 0x10) != DAT_001b0210)) &&
             ((((iVar4 = FUN_0010497c(iVar7,*(undefined4 *)(param_1 + 4)), iVar4 != 0 &&
                (iVar4 = *(int *)(iVar1 + 0xc), iVar4 != 0)) &&
               (iVar6 == *(int *)(*(int *)(iVar4 + 0x88) + 8))) &&
              ((iVar4 = FUN_000f31e8(iVar4,*(undefined4 *)(iVar1 + 0x10)), iVar4 != 0 &&
               ((iVar6 != 0x12 ||
                (param_7 = *(int *)(iVar1 + 0xc),
                (*(uint *)(*(int *)(iVar1 + 0x10) * 0x18 + param_7 + 0xa0) & 2) == 0)))))))) {
            *(undefined4 *)(iVar1 + 0x14) = 0;
          }
          iVar4 = FUN_00105594(iVar7,1);
          iVar6 = FUN_00105594(iVar7,2);
          iVar5 = FUN_001054ec(iVar7,1);
          iVar5 = FUN_000f2c5c(*(undefined4 *)(iVar5 + 0x10));
          if (iVar5 == 0) {
LAB_00183e40:
            iVar5 = FUN_001054ec(iVar7,1);
            iVar5 = FUN_000f2c5c(*(undefined4 *)(iVar5 + 0x10));
            if (iVar5 == 0) {
              iVar5 = FUN_001054ec(iVar7,2);
              iVar5 = FUN_000f2c5c(*(undefined4 *)(iVar5 + 0x10));
              if (iVar5 != 0) goto LAB_00183e78;
            }
          }
          else {
            iVar5 = FUN_001054ec(iVar7,2);
            iVar5 = FUN_000f2c5c(*(undefined4 *)(iVar5 + 0x10));
            if (iVar5 != 0) goto LAB_00183e40;
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
              piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
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
              piVar3 = (int *)FUN_0019423c(puVar9,uVar8);
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
  ((int (*)())FUN_00183ac8)(param_1);
  return;
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
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  char *extraout_r4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  
  param_1[1] = param_2;
  iVar3 = *(int *)(param_2 + 8);
  *param_1 = iVar3;
  iVar3 = FUN_0010ddcc(iVar3);
  param_1[2] = iVar3;
  uVar6 = *(undefined4 *)(*param_1 + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar6,0x14);
  puVar4[1] = 2;
  *puVar4 = uVar6;
  puVar4[2] = 0;
  puVar4[4] = uVar6;
  uVar6 = FUN_00193e18(uVar6,8);
  puVar4[3] = uVar6;
  param_1[7] = (int)(puVar4 + 1);
  iVar3 = *(int *)(param_1[1] + 900);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != 0) {
    iVar1 = FUN_00194034(iVar3 + 0x90);
    if (2 < iVar1) {
      ((int (*)())FUN_00183b9c)(param_1,iVar3,param_3,param_4,param_5,param_6,param_7);
    }
    iVar3 = *(int *)(iVar3 + 8);
    iVar1 = *(int *)(iVar3 + 8);
  }
  iVar3 = param_1[7];
  if (iVar3 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
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
  for (uVar8 = 1; uVar8 <= *(uint *)(iVar3 + 4); uVar8 = uVar8 + 1) {
    iVar2 = *(int *)(*(int *)(iVar3 + 8) + iVar1);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      FUN_001054ec(iVar2,0);
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
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  
  iVar11 = *(int *)(*param_1 + 0x378);
  piVar2 = (int *)FUN_00193e18(iVar11,0x14);
  puVar8 = (uint *)(piVar2 + 1);
  *piVar2 = iVar11;
  piVar2[1] = 2;
  piVar2[4] = iVar11;
  piVar2[2] = 0;
  iVar11 = FUN_00193e18(iVar11,8);
  piVar2[3] = iVar11;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  puVar10 = puVar3 + 1;
  *puVar3 = uVar12;
  puVar3[1] = 2;
  puVar3[4] = uVar12;
  puVar3[2] = 0;
  uVar12 = FUN_00193e18(uVar12,8);
  puVar3[3] = uVar12;
  uVar12 = *(undefined4 *)(*param_1 + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar12,0x14);
  puVar9 = puVar4 + 1;
  *puVar4 = uVar12;
  puVar4[1] = 2;
  puVar4[2] = 0;
  puVar4[4] = uVar12;
  uVar12 = FUN_00193e18(uVar12,8);
  uVar15 = piVar2[2];
  uVar1 = *puVar8;
  puVar4[3] = uVar12;
  if (uVar15 < uVar1) {
    _memset((void *)(uVar15 * 4 + piVar2[3]),0,4);
    puVar5 = (undefined4 *)(uVar15 * 4 + piVar2[3]);
    piVar2[2] = uVar15 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar15);
  }
  *puVar5 = param_4;
  uVar1 = puVar3[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
    puVar3[2] = uVar1 + 1;
    goto code_r0x00184480;
  }
code_r0x00184474:
  puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar1);
code_r0x00184480:
  *puVar5 = 1;
  do {
    uVar1 = piVar2[2];
    if (uVar1 == 0) {
      if (*puVar8 == 0) {
        puVar5 = (undefined4 *)FUN_0019423c(puVar8,0);
      }
      else {
        _memset((void *)piVar2[3],0,4);
        puVar5 = (undefined4 *)piVar2[3];
        piVar2[2] = 1;
      }
      *puVar5 = param_4;
      uVar1 = puVar3[2];
      if (uVar1 < *puVar10) {
        _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
        puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
        puVar3[2] = uVar1 + 1;
      }
      else {
        puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar1);
      }
      *puVar5 = 1;
      while (uVar1 = piVar2[2], uVar1 != 0) {
        puVar5 = (undefined4 *)0x0;
        if (uVar1 - 1 < uVar1) {
          puVar5 = (undefined4 *)((uVar1 - 1) * 4 + piVar2[3]);
        }
        piVar7 = (int *)*puVar5;
        iVar11 = ((int (*)())FUN_00181928)(piVar7,param_3,param_2);
        if ((iVar11 == 0) && (param_4 != piVar7)) {
          FUN_00194208(puVar8,piVar2[2] + -1);
          FUN_00194208(puVar10,puVar3[2] + -1);
        }
        else {
          piVar14 = (int *)0x0;
          uVar1 = puVar3[2] - 1;
          if (uVar1 < (uint)puVar3[2]) {
            piVar14 = (int *)(uVar1 * 4 + puVar3[3]);
          }
          iVar13 = *piVar14;
          iVar11 = (**(code **)(*piVar7 + 0x14))(piVar7);
          if (iVar11 < iVar13) {
            FUN_00194208(puVar8,piVar2[2] + -1);
            FUN_00194208(puVar10,puVar3[2] + -1);
            if (param_4 != piVar7) {
              FUN_0019401c(piVar7);
              FUN_000e7700(param_3,param_4,piVar7);
            }
          }
          else {
            uVar1 = (**(code **)(*piVar7 + 0x14))(piVar7);
            if (0 < (int)uVar1) {
              iVar11 = 1;
              do {
                uVar12 = FUN_00105594(piVar7,iVar11);
                uVar15 = puVar4[2];
                if (uVar15 < *puVar9) {
                  _memset((void *)(uVar15 * 4 + puVar4[3]),0,4);
                  puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
                  puVar4[2] = uVar15 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
                }
                iVar11 = iVar11 + 1;
                *puVar5 = uVar12;
              } while (iVar11 <= (int)uVar1);
            }
            FUN_001940f0(puVar9,FUN_001819b4);
            FUN_00194208(puVar10,puVar3[2] + -1);
            uVar15 = puVar3[2];
            if (uVar15 < *puVar10) {
              _memset((void *)(uVar15 * 4 + puVar3[3]),0,4);
              piVar7 = (int *)(uVar15 * 4 + puVar3[3]);
              puVar3[2] = uVar15 + 1;
            }
            else {
              piVar7 = (int *)FUN_0019423c(puVar10,uVar15);
            }
            *piVar7 = uVar1 + 1;
            if (0 < (int)uVar1) {
              uVar15 = 0;
              do {
                if (uVar15 < *puVar9) {
                  uVar6 = puVar4[2];
                  if (uVar6 <= uVar15) {
                    _memset((void *)(uVar6 * 4 + puVar4[3]),0,(uVar15 - uVar6) * 4 + 4);
                    puVar4[2] = uVar15 + 1;
                  }
                  puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
                }
                uVar15 = uVar15 + 1;
                uVar6 = piVar2[2];
                uVar12 = *puVar5;
                if (uVar6 < *puVar8) {
                  _memset((void *)(uVar6 * 4 + piVar2[3]),0,4);
                  puVar5 = (undefined4 *)(uVar6 * 4 + piVar2[3]);
                  piVar2[2] = uVar6 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar6);
                }
                *puVar5 = uVar12;
                uVar6 = puVar3[2];
                if (uVar6 < *puVar10) {
                  _memset((void *)(uVar6 * 4 + puVar3[3]),0,4);
                  puVar5 = (undefined4 *)(uVar6 * 4 + puVar3[3]);
                  puVar3[2] = uVar6 + 1;
                }
                else {
                  puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar6);
                }
                *puVar5 = 1;
              } while (uVar1 != uVar15);
            }
            puVar4[2] = 0;
          }
        }
      }
      if (puVar9 != (uint *)0x0) {
        FUN_00193cc0(puVar4[4],puVar4[3]);
        FUN_00193cc0(*puVar4,puVar4);
      }
      if (puVar10 != (uint *)0x0) {
        FUN_00193cc0(puVar3[4],puVar3[3]);
        FUN_00193cc0(*puVar3,puVar3);
      }
      if (puVar8 == (uint *)0x0) {
        return;
      }
      FUN_00193cc0(piVar2[4],piVar2[3]);
      iVar11 = *piVar2;
      if ((*(int *)(iVar11 + 0x28) != 0) && (piVar7 = *(int **)(iVar11 + 0x14), piVar7 == piVar2)) {
        _memset(piVar7,0,*(int *)(iVar11 + 8) - (int)piVar7);
        *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(iVar11 + 0x14);
      }
      return;
    }
    puVar5 = (undefined4 *)0x0;
    if (uVar1 - 1 < uVar1) {
      puVar5 = (undefined4 *)((uVar1 - 1) * 4 + piVar2[3]);
    }
    piVar14 = (int *)*puVar5;
    uVar1 = puVar3[2] - 1;
    piVar7 = (int *)0x0;
    if (uVar1 < (uint)puVar3[2]) {
      piVar7 = (int *)(uVar1 * 4 + puVar3[3]);
    }
    iVar13 = *piVar7;
    iVar11 = ((int (*)())FUN_00181928)(piVar14,param_3,param_2);
    if ((iVar11 == 0) && (param_4 != piVar14)) {
      piVar14[0x54] = 0;
    }
    else {
      iVar11 = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (iVar13 <= iVar11) break;
      uVar1 = (**(code **)(*piVar14 + 0x14))(piVar14);
      if (0 < (int)uVar1) {
        iVar11 = 1;
        do {
          uVar12 = FUN_00105594(piVar14,iVar11);
          uVar15 = puVar4[2];
          if (uVar15 < *puVar9) {
            _memset((void *)(uVar15 * 4 + puVar4[3]),0,4);
            puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
            puVar4[2] = uVar15 + 1;
          }
          else {
            puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
          }
          iVar11 = iVar11 + 1;
          *puVar5 = uVar12;
        } while (iVar11 <= (int)uVar1);
      }
      FUN_001940f0(puVar9,FUN_001819b4);
      if (0 < (int)uVar1) {
        uVar15 = 0;
        iVar11 = 0;
        do {
          if (uVar15 < *puVar9) {
            uVar6 = puVar4[2];
            if (uVar6 <= uVar15) {
              _memset((void *)(uVar6 * 4 + puVar4[3]),0,(uVar15 - uVar6) * 4 + 4);
              puVar4[2] = uVar15 + 1;
            }
            puVar5 = (undefined4 *)(uVar15 * 4 + puVar4[3]);
          }
          else {
            puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar15);
          }
          uVar15 = uVar15 + 1;
          piVar7 = (int *)*puVar5;
          if ((((piVar7[0x20] == 0) || (iVar13 = FUN_00126760(piVar7[0x26]), iVar13 == 0)) ||
              ((piVar7[5] & 2U) != 0)) ||
             (iVar13 = (**(code **)(*piVar7 + 0x50))(piVar7), iVar13 != 0)) {
            iVar13 = 0;
          }
          else {
            iVar13 = FUN_000f3a30(piVar7);
          }
          iVar11 = iVar11 + iVar13;
          if (iVar11 <= piVar7[0x54]) {
            iVar11 = piVar7[0x54];
          }
        } while (uVar1 != uVar15);
      }
      else {
        iVar11 = 0;
      }
      puVar4[2] = 0;
      piVar14[0x54] = iVar11;
    }
    FUN_00194208(puVar8,piVar2[2] + -1);
    FUN_00194208(puVar10,puVar3[2] + -1);
  } while( true );
  uVar12 = FUN_00105594(piVar14,iVar13);
  uVar1 = piVar2[2];
  if (uVar1 < *puVar8) {
    _memset((void *)(uVar1 * 4 + piVar2[3]),0,4);
    puVar5 = (undefined4 *)(uVar1 * 4 + piVar2[3]);
    piVar2[2] = uVar1 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar8,uVar1);
  }
  *puVar5 = uVar12;
  FUN_00194208(puVar10,puVar3[2] + -1);
  uVar1 = puVar3[2];
  if (uVar1 < *puVar10) {
    _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
    piVar7 = (int *)(uVar1 * 4 + puVar3[3]);
    puVar3[2] = uVar1 + 1;
  }
  else {
    piVar7 = (int *)FUN_0019423c(puVar10,uVar1);
  }
  *piVar7 = iVar13 + 1;
  uVar1 = puVar3[2];
  if (*puVar10 <= uVar1) goto code_r0x00184474;
  _memset((void *)(uVar1 * 4 + puVar3[3]),0,4);
  puVar5 = (undefined4 *)(uVar1 * 4 + puVar3[3]);
  puVar3[2] = uVar1 + 1;
  goto code_r0x00184480;
}

/* FUN_00184ab4 @ 0x184ab4 (280 bytes) */
int FUN_00184ab4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = *(int *)(param_2 + 900);
  for (iVar2 = *(int *)(*(int *)(param_2 + 900) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    piVar3 = (int *)(*(int **)(iVar1 + 0xa0))[1];
    piVar5 = *(int **)(iVar1 + 0xa0);
    if (piVar3 != (int *)0x0) {
      do {
        piVar4 = piVar3;
        iVar2 = (**(code **)(*piVar5 + 0x34))(piVar5);
        if ((((iVar2 == 0) && (iVar2 = (**(code **)(*piVar5 + 0x38))(piVar5), iVar2 == 0)) &&
            (iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5), 0 < iVar2)) &&
           (iVar2 = ((int (*)())FUN_00181928)(piVar5,iVar1,param_2), iVar2 == 0)) {
          ((int (*)())FUN_0018413c)(param_1,param_2,iVar1,piVar5);
        }
        piVar3 = (int *)piVar4[1];
        piVar5 = piVar4;
      } while (piVar3 != (int *)0x0);
      iVar2 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar2;
  }
  FUN_000ed7e4(param_2,0x1a9fa8);
  return;
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
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = *(uint **)(param_1 + 0x10);
  uVar1 = puVar8[1];
  uVar7 = uVar1 - 1;
  if (-1 < (int)uVar7) {
    iVar6 = uVar7 * 4;
    uVar5 = 0;
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
        puVar3 = (undefined4 *)FUN_0019423c(puVar8,uVar7);
      }
      iVar4 = (**(code **)(*(int *)*puVar3 + 0x24))();
      if (iVar4 == 0) {
        return 0;
      }
      uVar5 = uVar5 + 1;
      uVar7 = uVar7 - 1;
      iVar6 = iVar6 + -4;
      if (uVar1 == uVar5) break;
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
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
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
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    puVar5 = *(uint **)(param_1 + 0x10);
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      uVar4 = 0;
      do {
        if (uVar4 < *puVar5) {
          if (uVar1 <= uVar4) {
            _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
            puVar5[1] = uVar4 + 1;
          }
          puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
        }
        iVar3 = FUN_001470dc(*puVar2,param_2,0);
        if (iVar3 == 0) {
          return;
        }
        puVar5 = *(uint **)(param_1 + 0x10);
        uVar4 = uVar4 + 1;
        uVar1 = puVar5[1];
      } while ((int)uVar4 < (int)uVar1);
    }
    uVar1 = puVar5[1];
    if (0 < (int)uVar1) {
      uVar4 = 0;
      do {
        if (uVar4 < *puVar5) {
          if (uVar1 <= uVar4) {
            _memset(uVar1 * 4 + puVar5[2],0,(uVar4 - uVar1) * 4 + 4);
            puVar5[1] = uVar4 + 1;
          }
          puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
        }
        else {
          puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
        }
        uVar4 = uVar4 + 1;
        FUN_0014b82c(*puVar2,param_2,1,0);
        puVar5 = *(uint **)(param_1 + 0x10);
        uVar1 = puVar5[1];
      } while ((int)uVar4 < (int)uVar1);
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
  float *pfVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint *puVar20;
  uint *puVar21;
  int iVar22;
  double dVar23;
  undefined1 auStack_f8 [4];
  float local_f4 [4];
  float local_e4;
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
  
  iVar5 = (**(code **)(*param_1 + 0x24))();
  if ((((iVar5 == 0) ||
       (piVar6 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
       iVar5 = (**(code **)(*piVar6 + 0xfc))(piVar6,param_2 + param_1[0x49],0), iVar5 == 0)) ||
      ((param_1[5] & 0x200U) != 0)) ||
     ((param_1[0x48] != 0 || (iVar5 = (**(code **)(*param_1 + 0x5c))(param_1), iVar5 != 0)))) {
LAB_00185098:
    uVar9 = 0;
  }
  else {
    FUN_001940f0(param_1[4],FUN_00184bcc);
    puVar20 = (uint *)param_1[4];
    uVar7 = puVar20[1];
    if (0 < (int)uVar7) {
      uVar19 = 0;
      do {
        if (uVar19 < *puVar20) {
          if (uVar7 <= uVar19) {
            _memset(uVar7 * 4 + puVar20[2],0,(uVar19 - uVar7) * 4 + 4);
            puVar20[1] = uVar19 + 1;
          }
          puVar8 = (undefined4 *)(uVar19 * 4 + puVar20[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(puVar20,uVar19);
        }
        piVar6 = (int *)*puVar8;
        if ((((piVar6[5] & 0x200U) != 0) ||
            (iVar5 = (**(code **)(*piVar6 + 0x28))(piVar6), iVar5 != 0)) ||
           (iVar5 = (**(code **)(*piVar6 + 0x5c))(piVar6), iVar5 != 0)) goto LAB_00185098;
        iVar5 = *(int *)(piVar6[0x22] + 8);
        if (iVar5 == 0x31) {
LAB_001850bc:
          if ((((piVar6[0x21] != 2) || (piVar10 = (int *)FUN_00105594(piVar6,1), param_1 != piVar10)
               ) || (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) ||
             (piVar10 = *(int **)(*(int *)(param_3 + 8) + 0x30c),
             iVar5 = (**(code **)(*piVar10 + 0xfc))(piVar10,piVar6[0x49] + param_2 * -2,0),
             iVar5 == 0)) {
LAB_001851b4:
            piVar10 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            iVar5 = (**(code **)(*piVar10 + 0xfc))(piVar10,piVar6[0x49] - param_2,0);
            goto joined_r0x001851e0;
          }
        }
        else {
          if (0x31 < iVar5) {
            if ((iVar5 == 0x36) || (iVar5 == 0x66)) goto LAB_001850bc;
            if (iVar5 == 0x34) {
LAB_00185124:
              piVar10 = (int *)FUN_00105594(piVar6,1);
              if ((param_1 != piVar10) ||
                 (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) {
                if ((int)param_2 < 0) {
                  uStack_c4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_c8 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_c4) - DOUBLE_001aa1e0);
                }
                else {
                  local_c0 = 0x43300000;
                  uStack_bc = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0);
                }
                iVar5 = 4;
                pfVar4 = local_f4;
                do {
                  *pfVar4 = NAN;
                  pfVar4 = pfVar4 + 1;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
                iVar5 = 0;
                iVar22 = 4;
                do {
                  *(float *)(iVar5 + (int)local_f4) = fVar2;
                  iVar5 = iVar5 + 4;
                  iVar22 = iVar22 + -1;
                } while (iVar22 != 0);
                goto LAB_0018533c;
              }
              goto LAB_001851b4;
            }
            goto LAB_00185098;
          }
          if (iVar5 == 0x13) goto LAB_001850bc;
          if (iVar5 != 0x14) {
            if (iVar5 == 0x12) goto LAB_00185124;
            goto LAB_00185098;
          }
          iVar5 = FUN_001054ec(piVar6,0);
          iVar5 = FUN_000f5cf0(piVar6,2,*(undefined4 *)(iVar5 + 0x10),&local_e4);
          fVar2 = local_e0;
          if (((iVar5 == 0) || (local_e4 != 2.8026e-45)) ||
             (piVar6 = (int *)FUN_00105594(piVar6,1), param_1 != piVar6)) goto LAB_00185098;
          if ((int)param_2 < 0) {
            uStack_b4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
            local_b8 = 0x43300000;
            fVar1 = (float)((double)CONCAT44(0x43300000,uStack_b4) - DOUBLE_001aa1e0);
          }
          else {
            local_b0 = 0x43300000;
            uStack_ac = 1 << (param_2 & 0x3f) ^ 0x80000000;
            fVar1 = FLOAT_001aa0e8 /
                    (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_001aa1e0);
          }
          pfVar4 = local_f4;
          do {
            *pfVar4 = NAN;
            pfVar4 = pfVar4 + 1;
          } while (&local_e4 != pfVar4);
          iVar5 = 0;
          iVar22 = 4;
          do {
            *(float *)(iVar5 + (int)local_f4) = fVar2 * fVar1;
            iVar5 = iVar5 + 4;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
LAB_0018533c:
          piVar6 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          iVar5 = (**(code **)(*piVar6 + 0xe8))(piVar6,local_f4,auStack_f8,DAT_001b0220);
joined_r0x001851e0:
          if (iVar5 == 0) goto LAB_00185098;
        }
        puVar20 = (uint *)param_1[4];
        uVar19 = uVar19 + 1;
        uVar7 = puVar20[1];
      } while ((int)uVar19 < (int)uVar7);
    }
    uVar7 = uVar7 - 1;
    if (-1 < (int)uVar7) {
      local_70 = param_2 << 1;
      do {
        if (0 < (int)uVar7) {
          uVar19 = uVar7 - 1;
          if (uVar19 < *puVar20) {
            uVar3 = puVar20[1];
            puVar21 = puVar20;
            if (uVar3 <= uVar19) {
              _memset(uVar3 * 4 + puVar20[2],0,(uVar19 - uVar3) * 4 + 4);
              puVar20[1] = uVar7;
              puVar21 = (uint *)param_1[4];
            }
            piVar6 = (int *)(uVar19 * 4 + puVar20[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar20,uVar19);
            puVar21 = (uint *)param_1[4];
          }
          iVar5 = *piVar6;
          if (uVar7 < *puVar21) {
            uVar19 = puVar21[1];
            if (uVar19 <= uVar7) {
              _memset(uVar19 * 4 + puVar21[2],0,(uVar7 - uVar19) * 4 + 4);
              puVar21[1] = uVar7 + 1;
            }
            piVar6 = (int *)(uVar7 * 4 + puVar21[2]);
          }
          else {
            piVar6 = (int *)FUN_0019423c(puVar21,uVar7);
          }
          if (iVar5 != *piVar6) {
            puVar20 = (uint *)param_1[4];
            goto LAB_0018545c;
          }
          goto LAB_00185964;
        }
LAB_0018545c:
        if (uVar7 < *puVar20) {
          uVar19 = puVar20[1];
          if (uVar19 <= uVar7) {
            _memset(uVar19 * 4 + puVar20[2],0,(uVar7 - uVar19) * 4 + 4);
            puVar20[1] = uVar7 + 1;
          }
          puVar8 = (undefined4 *)(uVar7 * 4 + puVar20[2]);
        }
        else {
          puVar8 = (undefined4 *)FUN_0019423c(puVar20,uVar7);
        }
        piVar6 = (int *)*puVar8;
        iVar5 = *(int *)(piVar6[0x22] + 8);
        if (iVar5 == 0x31) {
LAB_0018550c:
          if ((piVar6[0x21] == 2) &&
             ((piVar10 = (int *)FUN_00105594(piVar6,1), param_1 == piVar10 &&
              (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 == piVar10)))) {
            piVar6[0x49] = piVar6[0x49] - local_70;
          }
          else {
LAB_00185628:
            piVar6[0x49] = piVar6[0x49] - param_2;
          }
        }
        else {
          if (iVar5 < 0x32) {
            if (iVar5 != 0x13) {
              if (iVar5 == 0x14) {
                iVar5 = FUN_001054ec(piVar6,0);
                FUN_000f5cf0(piVar6,2,*(undefined4 *)(iVar5 + 0x10),&local_e4);
                if ((int)param_2 < 0) {
                  uStack_94 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                  local_98 = 0x43300000;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_94) - DOUBLE_001aa1e0);
                }
                else {
                  local_90 = 0x43300000;
                  uStack_8c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                  fVar2 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
                }
                dVar23 = (double)(local_e0 * fVar2);
                FUN_00103d50(piVar6 + 0x2f,1,0);
                FUN_00103d50(piVar6 + 0x2f,2,0);
                ((void (*)())FUN_000f79c4)(piVar6,param_3,2,dVar23,dVar23,dVar23,dVar23);
              }
              else if (iVar5 == 0x12) goto LAB_00185558;
              goto LAB_00185964;
            }
            goto LAB_0018550c;
          }
          if ((iVar5 == 0x36) || (iVar5 == 0x66)) goto LAB_0018550c;
          if (iVar5 == 0x34) {
LAB_00185558:
            piVar10 = (int *)FUN_00105594(piVar6,1);
            if ((param_1 != piVar10) ||
               (piVar10 = (int *)FUN_00105594(piVar6,2), param_1 != piVar10)) {
              if ((int)param_2 < 0) {
                uStack_a4 = 1 << (-param_2 & 0x3f) ^ 0x80000000;
                local_a8 = 0x43300000;
                fVar2 = (float)((double)CONCAT44(0x43300000,uStack_a4) - DOUBLE_001aa1e0);
              }
              else {
                local_a0 = 0x43300000;
                uStack_9c = 1 << (param_2 & 0x3f) ^ 0x80000000;
                fVar2 = FLOAT_001aa0e8 /
                        (float)((double)CONCAT44(0x43300000,uStack_9c) - DOUBLE_001aa1e0);
              }
              dVar23 = (double)fVar2;
              local_74 = piVar6[1];
              local_78 = piVar6[0x56];
              FUN_0019401c(piVar6);
              iVar5 = FUN_001054ec(piVar6,0);
              local_84 = *(int *)(iVar5 + 0x10);
              local_7c = piVar6[0x49];
              local_80 = piVar6[0x48];
              iVar5 = FUN_00104054(piVar6,param_3);
              iVar22 = piVar6[4];
              piVar10 = (int *)FUN_00105594(piVar6,1);
              if (param_1 == piVar10) {
                iVar18 = 1;
                iVar17 = 2;
              }
              else {
                FUN_00105594(piVar6,2);
                iVar18 = 2;
                iVar17 = 1;
              }
              iVar14 = piVar6[iVar18 * 6 + 0x26];
              iVar13 = piVar6[iVar18 * 6 + 0x25];
              iVar11 = FUN_001054ec(piVar6,iVar18);
              uVar19 = piVar6[iVar18 * 6 + 0x28];
              uVar16 = *(undefined4 *)(iVar11 + 0x10);
              uVar9 = FUN_00105594(piVar6,iVar18);
              iVar15 = piVar6[iVar17 * 6 + 0x26];
              iVar11 = piVar6[iVar17 * 6 + 0x25];
              iVar18 = FUN_001054ec(piVar6,iVar17);
              local_88 = *(undefined4 *)(iVar18 + 0x10);
              uVar3 = piVar6[iVar17 * 6 + 0x28];
              uVar12 = FUN_00105594(piVar6,iVar17);
              (**(code **)(*piVar6 + 0xc))(piVar6,1,*(undefined4 *)(param_3 + 8));
              FUN_00108304(piVar6,0x14,*(undefined4 *)(param_3 + 8));
              piVar6[4] = iVar22;
              piVar6[0x25] = piVar6[0x53];
              piVar6[0x26] = 0;
              piVar6[0x27] = local_84;
              piVar6[0x48] = local_80;
              piVar6[0x49] = local_7c;
              piVar6[0x58] = iVar5 + *(int *)(param_3 + 0x478);
              FUN_00106004(piVar6,1,uVar9,1,*(undefined4 *)(param_3 + 8));
              iVar5 = FUN_001054ec(piVar6,1);
              *(int *)(iVar5 + 0xc) = iVar14;
              *(int *)(iVar5 + 8) = iVar13;
              iVar5 = FUN_001054ec(piVar6,1);
              *(undefined4 *)(iVar5 + 0x10) = uVar16;
              FUN_00103d50(piVar6 + 0x29,2,uVar19 >> 1 & 1);
              FUN_00103d50(piVar6 + 0x29,1,uVar19 & 1);
              FUN_00106004(piVar6,3,uVar12,1,*(undefined4 *)(param_3 + 8));
              iVar5 = FUN_001054ec(piVar6,3);
              *(int *)(iVar5 + 0xc) = iVar15;
              *(int *)(iVar5 + 8) = iVar11;
              iVar5 = FUN_001054ec(piVar6,3);
              *(undefined4 *)(iVar5 + 0x10) = local_88;
              FUN_00103d50(piVar6 + 0x35,2,uVar3 >> 1 & 1);
              FUN_00103d50(piVar6 + 0x35,1,uVar3 & 1);
              ((void (*)())FUN_000f79c4)(piVar6,param_3,2,dVar23,dVar23,dVar23,dVar23);
              FUN_000e7738(local_78,local_74,piVar6);
              goto LAB_00185964;
            }
            goto LAB_00185628;
          }
        }
LAB_00185964:
        uVar7 = uVar7 - 1;
        if ((int)uVar7 < 0) break;
        puVar20 = (uint *)param_1[4];
      } while( true );
    }
    uVar9 = 1;
    param_1[0x49] = param_2 + param_1[0x49];
  }
  return uVar9;
}

/* FUN_001859bc @ 0x1859bc (640 bytes) */
int FUN_001859bc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
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
  
  iVar3 = FUN_001054ec(param_1,1);
  uVar14 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_1,2);
  uVar13 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_1,0);
  uVar12 = *(undefined4 *)(iVar3 + 0x10);
  if (((*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x12) &&
      (iVar3 = FUN_000f2c5c(uVar14), iVar3 != 0)) && (iVar3 = FUN_000f2c5c(uVar13), iVar3 != 0)) {
    piVar4 = (int *)FUN_00105594(param_1,1);
    piVar5 = (int *)FUN_00105594(param_1,2);
    if (((*(int *)(piVar4[0x22] + 8) == 0x1c) && (iVar3 = FUN_0010497c(piVar4,param_2), iVar3 != 0))
       && (((*(uint *)(param_1 + 0xb8) & 1) == 0 && ((*(uint *)(param_1 + 0xb8) & 2) == 0)))) {
      iVar3 = FUN_00146788(piVar4,param_2);
      iVar9 = 2;
      if (iVar3 != 0) goto LAB_00185afc;
    }
    if (((*(int *)(piVar5[0x22] + 8) == 0x1c) && (iVar3 = FUN_0010497c(piVar5,param_2), iVar3 != 0))
       && (((*(uint *)(param_1 + 0xd0) & 1) == 0 &&
           (((*(uint *)(param_1 + 0xd0) & 2) == 0 &&
            (iVar3 = FUN_00146788(piVar5,param_2), iVar3 != 0)))))) {
      iVar9 = 1;
      piVar4 = piVar5;
      uVar13 = uVar14;
LAB_00185afc:
      local_74 = FUN_00105594(param_1,iVar9);
      uVar1 = *(uint *)(iVar9 * 0x18 + param_1 + 0xa0);
      iVar15 = 0;
      local_70 = uVar1 & 1;
      local_6c = uVar1 >> 1 & 1;
      iVar3 = FUN_001054ec(param_1,iVar9);
      local_60 = *(undefined4 *)(iVar3 + 0x10);
      uVar14 = FUN_00105594(piVar4,1);
      uVar1 = piVar4[0x2e];
      iVar3 = FUN_001054ec(piVar4,1);
      local_64 = *(undefined4 *)(iVar3 + 0x10);
      uVar6 = FUN_00105594(piVar4,2);
      uVar2 = piVar4[0x34];
      iVar3 = FUN_001054ec(piVar4,2);
      local_68 = *(undefined4 *)(iVar3 + 0x10);
      uVar7 = *(undefined4 *)(param_1 + 4);
      uVar8 = *(undefined4 *)(param_1 + 0x158);
      iVar3 = FUN_00104054(param_1,param_2);
      uVar10 = *(undefined4 *)(param_1 + 0x120);
      uVar11 = *(undefined4 *)(param_1 + 0x124);
      if ((*(uint *)(param_1 + 0x14) & 0x200) != 0) {
        iVar15 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
      }
      FUN_0019401c(param_1);
      FUN_00108304(param_1,0xa3,param_3);
      *(undefined4 *)(param_1 + 0x98) = 0;
      *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
      *(undefined4 *)(param_1 + 0x9c) = uVar12;
      *(undefined4 *)(param_1 + 0x120) = uVar10;
      *(undefined4 *)(param_1 + 0x124) = uVar11;
      *(int *)(param_1 + 0x160) = iVar3 + *(int *)(param_2 + 0x478);
      if (iVar15 != 0) {
        FUN_00106804(param_1,iVar15,0,param_3);
      }
      FUN_000e7738(uVar8,uVar7,param_1);
      FUN_00106004(param_1,1,uVar14,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xa4,1,uVar1 & 1);
      FUN_00103d50(param_1 + 0xa4,2,uVar1 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,1);
      *(undefined4 *)(iVar3 + 0x10) = local_64;
      FUN_00106004(param_1,2,uVar6,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xbc,1,uVar2 & 1);
      FUN_00103d50(param_1 + 0xbc,2,uVar2 >> 1 & 1);
      iVar3 = FUN_001054ec(param_1,2);
      *(undefined4 *)(iVar3 + 0x10) = local_68;
      FUN_00106004(param_1,3,local_74,0,*(undefined4 *)(param_2 + 8));
      FUN_00103d50(param_1 + 0xd4,1,local_70);
      FUN_00103d50(param_1 + 0xd4,2,local_6c);
      iVar3 = FUN_001054ec(param_1,3);
      *(undefined4 *)(iVar3 + 0x10) = local_60;
      FUN_000f33f8(&local_78,uVar13);
      iVar3 = FUN_001054ec(param_1,3);
      *(undefined4 *)(iVar3 + 0x10) = local_78;
                    
                    
      (**(code **)(*piVar4 + 0xc))(piVar4,0,*(undefined4 *)(param_2 + 8));
      return;
    }
  }
  return;
}

/* FUN_00185da4 @ 0x185da4 (1900 bytes) */
int FUN_00185da4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
  int *param_5;
  int param_6;
  int param_7;
  int param_8;
  undefined4 *param_9;
  int param_10;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  undefined4 local_68;
  int local_64 [3];
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [4];
  
  iVar3 = FUN_001054ec(param_5,1);
  uVar8 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(param_3,param_1);
  uVar7 = *(undefined4 *)(iVar3 + 0x10);
  FUN_000f2bdc(&local_58,uVar8,uVar7);
  local_68 = local_58;
  piVar4 = *(int **)(*(int *)(param_6 + 8) + 0x30c);
  iVar3 = (**(code **)(*piVar4 + 0x108))(piVar4,&local_68);
  if (iVar3 == 0) {
    *(int *)(param_6 + 0x20c) = *(int *)(param_6 + 0x20c) + 1;
    return 0;
  }
  if ((param_2 == 0) || ((param_3[param_1 * 6 + 0x28] & 2U) != 0)) {
LAB_00185ea8:
    if (param_7 == 0) goto LAB_00185f24;
  }
  else {
    if ((*(int *)(param_4[0x22] + 8) == 0x9a) && (param_4[0x2c] == param_4[0x32])) {
      FUN_0010ac38(param_4,1,2,*(uint *)(param_6 + 8));
      param_2 = 0;
      goto LAB_00185ea8;
    }
    if (param_7 == 0) goto LAB_00185f24;
    iVar3 = (**(code **)(*param_3 + 0x60))(param_3);
    if (iVar3 != 0) {
      return 0;
    }
    FUN_00103d50(param_3 + param_1 * 6 + 0x23,1,param_3[param_1 * 6 + 0x28] & 1U ^ 1);
  }
  uVar8 = local_68;
  iVar3 = FUN_001054ec(param_3,param_1);
  *(undefined4 *)(iVar3 + 0x10) = uVar8;
  FUN_00106004(param_3,param_1,param_4,0,*(undefined4 *)(param_6 + 8));
LAB_00185f24:
  bVar2 = param_7 != 0;
  FUN_000f32cc(&local_54,local_68);
  param_4[0x27] = local_54;
  if ((param_8 != 0) && (iVar3 = FUN_0018da48(param_3,*(undefined4 *)(param_6 + 8)), iVar3 == 0)) {
    iVar3 = 0;
    for (iVar9 = 1; iVar5 = (**(code **)(*param_3 + 0x14))(param_3), iVar9 <= iVar5;
        iVar9 = iVar9 + 1) {
      iVar5 = FUN_000f3b10(param_3,iVar9);
      if (iVar5 != 0) {
        iVar5 = iVar3 + 1;
        iVar3 = iVar3 + 2;
        if (iVar9 != param_1) {
          iVar3 = iVar5;
        }
      }
      FUN_000f3b68(param_3,iVar9);
    }
    if (3 < iVar3) {
      for (iVar3 = 1; iVar9 = (**(code **)(*param_3 + 0x14))(param_3), iVar3 <= iVar9;
          iVar3 = iVar3 + 1) {
        if (param_1 == iVar3) {
          iVar9 = (**(code **)(*param_5 + 100))(param_5);
          if (iVar9 != 0) {
            piVar4 = (int *)FUN_00105594(param_5,1);
            goto LAB_0018601c;
          }
        }
        else {
          piVar4 = (int *)FUN_00105594(param_3,iVar3);
LAB_0018601c:
          iVar9 = FUN_001054ec(param_3,iVar3);
          local_64[0] = *(int *)(iVar9 + 0x10);
          iVar9 = FUN_000f2c5c(local_64[0]);
          if (iVar9 != 0) {
            iVar9 = FUN_0011379c(*(undefined4 *)(param_6 + 8),piVar4);
            if ((iVar9 == 0) || (iVar9 = FUN_0010497c(piVar4,param_6), iVar9 == 0)) {
              bVar1 = false;
            }
            else {
              iVar9 = FUN_000f2cac(local_64[0]);
              piVar4[0x27] = 0x1010100;
              for (iVar5 = 1; iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar5 <= iVar6;
                  iVar5 = iVar5 + 1) {
                pcVar10 = *(code **)(*piVar4 + 0x88);
                iVar6 = FUN_001054ec(piVar4,iVar5);
                (*pcVar10)(piVar4,iVar5,3,*(undefined1 *)(iVar9 + iVar6 + 0x10));
                (**(code **)(*piVar4 + 0x88))(piVar4,iVar5,iVar9,4);
              }
              iVar9 = 0;
              iVar5 = 4;
              do {
                if (*(char *)((int)local_64 + iVar9) != '\x04') {
                  *(undefined1 *)((int)local_64 + iVar9) = 3;
                }
                iVar6 = local_64[0];
                iVar9 = iVar9 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              if (iVar3 == 0) {
                bVar1 = true;
                param_3[0x27] = local_64[0];
              }
              else {
                iVar9 = FUN_001054ec(param_3,iVar3);
                bVar1 = true;
                *(int *)(iVar9 + 0x10) = iVar6;
              }
            }
            iVar9 = FUN_001131c0(*(undefined4 *)(piVar4[0x22] + 8),*(undefined4 *)(param_6 + 8));
            if (iVar9 != 0) {
              iVar9 = FUN_0010497c(piVar4,param_6);
              if (iVar9 == 0) {
                *(undefined1 *)((int)piVar4 + 0x9f) = 0;
              }
              else {
                piVar4[0x27] = 0x1010100;
              }
              iVar9 = 0;
              iVar5 = 4;
              do {
                if (*(char *)((int)local_64 + iVar9) != '\x04') {
                  *(undefined1 *)((int)local_64 + iVar9) = 3;
                }
                iVar6 = local_64[0];
                iVar9 = iVar9 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
              if (iVar3 == 0) {
                param_3[0x27] = local_64[0];
              }
              else {
                iVar9 = FUN_001054ec(param_3,iVar3);
                *(int *)(iVar9 + 0x10) = iVar6;
              }
LAB_001861f8:
              if (iVar3 == param_1) {
                param_4[0x27] = 0x1010100;
                for (iVar3 = 1; iVar9 = (**(code **)(*param_4 + 0x14))(param_4), iVar3 <= iVar9;
                    iVar3 = iVar3 + 1) {
                  if (iVar3 == 0) {
                    param_4[0x27] = 0x4040404;
                  }
                  else {
                    iVar9 = FUN_001054ec(param_4,iVar3);
                    *(undefined4 *)(iVar9 + 0x10) = 0x4040404;
                  }
                  (**(code **)(*param_4 + 0x88))(param_4,iVar3,3,3);
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
  iVar3 = FUN_0018da48(param_3,*(undefined4 *)(param_6 + 8));
  if ((iVar3 == 0) && (param_8 != 0)) {
    if (bVar2) {
      if (param_10 == 0) {
        FUN_00106004(param_3,param_1,param_5,0,*(undefined4 *)(param_6 + 8));
      }
      else {
        FUN_00106004(param_3,param_1,param_10,0,*(undefined4 *)(param_6 + 8));
      }
      iVar3 = FUN_001054ec(param_3,param_1);
      *(undefined4 *)(iVar3 + 0x10) = uVar7;
      if ((param_2 != 0) && ((param_3[param_1 * 6 + 0x28] & 2U) == 0)) {
        FUN_00103d50(param_3 + param_1 * 6 + 0x23,1,param_3[param_1 * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (param_10 == 0) {
      param_5[0x54] = *(int *)(param_6 + 0x474) + -1;
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
      FUN_000e7700(param_3[0x56],param_3,param_4);
      param_4[0x58] = *(int *)(param_6 + 0x478) + 1;
    }
    iVar3 = FUN_001054ec(param_4,0);
    FUN_000f3908(&local_50,*(undefined4 *)(iVar3 + 0x10));
    FUN_000f3340(local_4c,0x10203,local_50);
    if (0 < param_4[0x21]) {
      iVar3 = 1;
      do {
        if (bVar2) {
          iVar9 = FUN_00105594(param_4,iVar3);
          if (*(int *)(param_6 + 0x478) < *(int *)(iVar9 + 0x160)) {
            *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
          }
          else {
            *(int *)(iVar9 + 0x160) = *(int *)(param_6 + 0x478) + 1;
          }
        }
        iVar9 = (**(code **)(*param_4 + 0x14))(param_4);
        if (iVar3 <= iVar9) {
          if (iVar3 == 0) {
            param_4[0x27] = local_4c[0];
          }
          else {
            iVar9 = FUN_001054ec(param_4,iVar3);
            *(int *)(iVar9 + 0x10) = local_4c[0];
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= param_4[0x21]);
    }
    if (bVar2) {
      if (param_10 == 0) {
        param_5[5] = param_5[5] | 0x40000;
        FUN_00105894(param_5,*(undefined4 *)(param_6 + 8));
      }
      else {
        *(uint *)(param_10 + 0x14) = *(uint *)(param_10 + 0x14) | 0x40000;
        FUN_00105894(param_10,*(undefined4 *)(param_6 + 8));
        FUN_0019401c(param_5);
      }
    }
    uVar7 = 1;
    if (param_9 != (undefined4 *)0x0) {
      *param_9 = param_4;
    }
  }
  return uVar7;
}

