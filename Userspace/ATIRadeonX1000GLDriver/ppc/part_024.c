#include "decls.h"

/* FUN_000ebff8 @ 0xebff8 (64 bytes) */
int FUN_000ebff8(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x138);
  *puVar1 = uVar2;
  FUN_000ebfb4(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000ec070 @ 0xec070 (88 bytes) */
int FUN_000ec070(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ea148(param_1,param_4);
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  *param_1 = &PTR_FUN_001e9e20;
  return;
}

/* FUN_000ec0c8 @ 0xec0c8 (88 bytes) */
int FUN_000ec0c8(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ea148(param_1,param_4);
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  *param_1 = &PTR_FUN_001e9e20;
  return;
}

/* FUN_000ec120 @ 0xec120 (88 bytes) */
int FUN_000ec120(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ea148(param_1,param_4);
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  *param_1 = &PTR_FUN_001e9e78;
  return;
}

/* FUN_000ec178 @ 0xec178 (88 bytes) */
int FUN_000ec178(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000ea148(param_1,param_4);
  param_1[0x4b] = param_2;
  param_1[0x4c] = param_3;
  *param_1 = &PTR_FUN_001e9e78;
  return;
}

/* FUN_000ec1d0 @ 0xec1d0 (20 bytes) */
int FUN_000ec1d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x3ac);
  iVar2 = FUN_00127534(uVar1,0x13,0,0);
  if (iVar2 == 0) {
    FUN_001275a0(uVar1,0x13,0,0);
    return;
  }
  return;
}

/* FUN_000ec1ec @ 0xec1ec (28 bytes) */
int FUN_000ec1ec(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
                    
                    
  (**(code **)(*piVar1 + 100))(piVar1,param_1);
  return;
}

/* FUN_000ec208 @ 0xec208 (80 bytes) */
int FUN_000ec208(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 * 8 + *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 4) + 4);
  if (iVar1 == -1) {
    FUN_000e1534(*(int *)(param_1 + 8),0xf);
  }
  return iVar1;
}

/* FUN_000ec258 @ 0xec258 (36 bytes) */
int FUN_000ec258(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b5c + param_2 * 4);
}

/* FUN_000ec27c @ 0xec27c (36 bytes) */
int FUN_000ec27c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b68 + param_2 * 4);
}

/* FUN_000ec2a0 @ 0xec2a0 (36 bytes) */
int FUN_000ec2a0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b6c + param_2 * 4);
}

/* FUN_000ec2c4 @ 0xec2c4 (36 bytes) */
int FUN_000ec2c4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(undefined4 *)(PTR_DAT_001e8b60 + param_2 * 4);
}

/* FUN_000ec2e8 @ 0xec2e8 (136 bytes) */
int FUN_000ec2e8(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x394) != 0) {
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x394));
    *(undefined4 *)(param_1 + 0x394) = 0;
  }
  if (*(int *)(param_1 + 0x398) != 0) {
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x398));
    *(undefined4 *)(param_1 + 0x398) = 0;
  }
  if (*(int *)(param_1 + 0x39c) != 0) {
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x39c));
    *(undefined4 *)(param_1 + 0x39c) = 0;
  }
  return;
}

/* FUN_000ec370 @ 0xec370 (60 bytes) */
int FUN_000ec370(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193f44(param_3,param_2);
  *(undefined4 *)(param_3 + 0xac) = param_1;
  ((int (*)())FUN_000ec2e8)(param_1);
  return;
}

/* FUN_000ec3ac @ 0xec3ac (60 bytes) */
int FUN_000ec3ac(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193f74(param_3,param_2);
  *(undefined4 *)(param_3 + 0xac) = param_1;
  ((int (*)())FUN_000ec2e8)(param_1);
  return;
}

/* FUN_000ec3e8 @ 0xec3e8 (68 bytes) */
int FUN_000ec3e8(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_00193f94(param_1 + 0x37c,param_2);
  ((int (*)())FUN_000ec2e8)(param_1);
  *(int *)(param_2 + 0xac) = param_1;
  ((int (*)())FUN_000ec2e8)(param_1);
  return;
}

/* FUN_000ec42c @ 0xec42c (60 bytes) */
int FUN_000ec42c(param_1, param_2)
  int param_1;
  int param_2;
{
  FUN_00193f64(param_1 + 0x37c,param_2);
  *(int *)(param_2 + 0xac) = param_1;
  ((int (*)())FUN_000ec2e8)(param_1);
  return;
}

/* FUN_000ec468 @ 0xec468 (136 bytes) */
int FUN_000ec468(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x394) != 0) {
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(int *)(param_1 + 0x394));
  }
  uVar1 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),param_3 * 4 + 4);
  uVar3 = 0;
  *(undefined4 *)(param_1 + 0x394) = uVar1;
  iVar2 = 0;
  do {
    uVar3 = uVar3 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x394) + iVar2) = *(undefined4 *)(param_2 + iVar2);
    iVar2 = iVar2 + 4;
  } while (uVar3 <= param_3);
  return;
}

/* FUN_000ec4f0 @ 0xec4f0 (124 bytes) */
int FUN_000ec4f0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(param_1 + 0x394);
  if (iVar1 == 0) {
    uVar3 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x2c);
    *puVar2 = uVar3;
    puVar4 = puVar2 + 1;
    FUN_000f7cd8(puVar4,param_1);
    FUN_000f816c(puVar4,*(undefined4 *)(param_1 + 0x3a0));
    ((int (*)())FUN_000ec468)(param_1,puVar2[7],puVar2[8]);
    FUN_000f8044(puVar4);
    if (puVar4 == (undefined4 *)0x0) {
      iVar1 = *(int *)(param_1 + 0x394);
    }
    else {
      FUN_00193cc0(*puVar2,puVar2);
      iVar1 = *(int *)(param_1 + 0x394);
    }
  }
  return iVar1;
}

/* FUN_000ec5b8 @ 0xec5b8 (160 bytes) */
int FUN_000ec5b8(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x398);
  if (iVar2 == 0) {
    iVar2 = FUN_00194034(param_1 + 0x37c);
    uVar3 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar2 * 4 + 4);
    *(undefined4 *)(param_1 + 0x398) = uVar3;
    puVar4 = (undefined4 *)((int (*)())FUN_000ec4f0)(param_1);
    **(undefined4 **)(param_1 + 0x398) = *puVar4;
    if (0 < iVar2) {
      puVar4 = puVar4 + iVar2;
      iVar5 = 1;
      do {
        iVar1 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        uVar3 = *puVar4;
        puVar4 = puVar4 + -1;
        *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x398)) = uVar3;
      } while (iVar5 <= iVar2);
    }
    iVar2 = *(int *)(param_1 + 0x398);
  }
  return iVar2;
}

/* FUN_000ec658 @ 0xec658 (88 bytes) */
int FUN_000ec658(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != 0) {
    iVar1 = FUN_00194034(iVar3 + 0x90);
    iVar3 = *(int *)(iVar3 + 8);
    iVar2 = iVar2 + iVar1;
    iVar1 = *(int *)(iVar3 + 8);
  }
  return iVar2;
}

/* FUN_000ec6b0 @ 0xec6b0 (120 bytes) */
int FUN_000ec6b0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 900);
  iVar1 = *(int *)(iVar2 + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_000e79dc(iVar2);
    if ((1 < iVar1) || (iVar1 = FUN_000e79d0(iVar2), 1 < iVar1)) break;
    iVar2 = *(int *)(iVar2 + 8);
    iVar1 = *(int *)(iVar2 + 8);
  }
  return 1;
}

/* FUN_000ec728 @ 0xec728 (444 bytes) */
int FUN_000ec728(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  
  iVar1 = *(int *)(param_1 + 900);
  for (iVar8 = *(int *)(*(int *)(param_1 + 900) + 8); iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    iVar7 = *(int *)(*(int *)(iVar1 + 0x98) + 8);
    iVar10 = *(int *)(iVar1 + 0x98);
    if (iVar7 != 0) {
      do {
        iVar8 = iVar7;
        if (((*(uint *)(iVar10 + 0x14) & 1) != 0) && (iVar7 = *(int *)(iVar10 + 0x84), 0 < iVar7)) {
          iVar4 = 0;
          iVar6 = 0;
          iVar5 = iVar10;
          iVar11 = iVar7;
          do {
            if (*(int *)(iVar5 + 0xb0) - 2U < 3) {
              iVar6 = iVar6 + 1;
            }
            else if (*(int *)(iVar5 + 0xb0) == 0xc) {
              iVar4 = iVar4 + 1;
            }
            iVar5 = iVar5 + 0x18;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          if ((iVar6 != 0) && (iVar4 != 0)) {
            iVar5 = 0;
            iVar8 = iVar10;
            do {
              iVar5 = iVar5 + 1;
              if (((*(int *)(iVar8 + 0xb0) - 2U < 3) && (iVar4 >= iVar6)) ||
                 ((*(int *)(iVar8 + 0xb0) == 0xc && (iVar4 < iVar6)))) {
                uVar2 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
                uVar3 = *(undefined4 *)(param_1 + 0x3ac);
                uVar9 = *(undefined4 *)(iVar8 + 0xa4);
                iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
                *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar11;
                uVar3 = FUN_00127608(uVar3,0,iVar11,0);
                FUN_001046c8(uVar2,0,uVar3);
                FUN_001046c8(uVar2,1,uVar9);
                FUN_001235b8(uVar9,iVar10,uVar2);
                FUN_001046c8(iVar10,iVar5,uVar3);
                FUN_000e7700(*(undefined4 *)(iVar10 + 0x158),iVar10,uVar2);
              }
              iVar8 = iVar8 + 0x18;
            } while (iVar7 != iVar5);
            iVar8 = *(int *)(iVar10 + 8);
          }
        }
        iVar7 = *(int *)(iVar8 + 8);
        iVar10 = iVar8;
      } while (*(int *)(iVar8 + 8) != 0);
      iVar8 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar8;
  }
  return;
}

/* FUN_000ec8e4 @ 0xec8e4 (60 bytes) */
int FUN_000ec8e4(param_1)
  int param_1;
{
  FUN_0012740c(*(undefined4 *)(param_1 + 0x3ac));
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;
  return;
}

/* FUN_000ec920 @ 0xec920 (240 bytes) */
int FUN_000ec920(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  bool bVar9;
  
  puVar2 = (undefined4 *)((int (*)())FUN_000ec5b8)(param_1);
  do {
    bVar9 = false;
    iVar6 = 1;
    puVar7 = puVar2;
    while( true ) {
      puVar7 = puVar7 + 1;
      iVar3 = FUN_00194034(param_1 + 0x37c);
      if (iVar3 < iVar6) break;
      piVar8 = (int *)*puVar7;
      iVar3 = (**(code **)(*piVar8 + 0x20))(piVar8);
      if (iVar3 == 0) {
        iVar3 = piVar8[3];
        iVar5 = 0;
        for (uVar4 = 1; uVar4 <= *(uint *)(piVar8[0x34] + 4); uVar4 = uVar4 + 1) {
          iVar1 = *(int *)(*(int *)(piVar8[0x34] + 8) + iVar5);
          if (iVar1 != 0) {
            piVar8[3] = *(uint *)(iVar1 + 0xc) & 3 | piVar8[3];
          }
          iVar5 = iVar5 + 4;
        }
        bVar9 = iVar3 != piVar8[3];
      }
      iVar6 = iVar6 + 1;
    }
  } while (bVar9);
  return;
}

/* FUN_000eca10 @ 0xeca10 (192 bytes) */
int FUN_000eca10(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if ((((iVar1 != 0) || (iVar1 = (**(code **)(*param_2 + 0x28))(param_2), iVar1 != 0)) ||
      (iVar1 = (**(code **)(*param_2 + 0x60))(param_2), iVar1 != 0)) ||
     ((iVar1 = (**(code **)(*param_2 + 0x5c))(param_2), iVar1 != 0 ||
      (uVar2 = 0, *(int *)(param_2[0x22] + 8) == 0x84)))) {
    uVar2 = 1;
  }
  return uVar2 ^ 1;
}

/* FUN_000ecad0 @ 0xecad0 (192 bytes) */
int FUN_000ecad0(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2);
  if ((((iVar1 != 0) || (iVar1 = (**(code **)(*param_2 + 0x28))(param_2), iVar1 != 0)) ||
      (iVar1 = (**(code **)(*param_2 + 0x60))(param_2), iVar1 != 0)) ||
     ((iVar1 = (**(code **)(*param_2 + 0x5c))(param_2), iVar1 != 0 ||
      (uVar2 = 0, *(int *)(param_2[0x22] + 8) == 0x84)))) {
    uVar2 = 1;
  }
  return uVar2 ^ 1;
}

/* FUN_000ecb90 @ 0xecb90 (140 bytes) */
int FUN_000ecb90(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0011379c(param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x88) + 8);
    iVar1 = FUN_00113090(uVar2,param_2);
    if (((iVar1 == 0) || (iVar1 = FUN_0011320c(uVar2,param_2), iVar1 != 0)) &&
       (iVar1 = FUN_001131c0(uVar2,param_2), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_000ecc1c @ 0xecc1c (268 bytes) */
int FUN_000ecc1c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x60))();
  if (iVar1 != 0) {
    iVar1 = FUN_0010497c(param_1,*(undefined4 *)(param_3 + 0x6c4));
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_0010c47c(param_1,param_3);
    if (iVar1 == 0) {
      return 0;
    }
    param_1 = (int *)FUN_00105594(param_1,1);
  }
  iVar1 = FUN_0010497c(param_1,*(undefined4 *)(param_3 + 0x6c4));
  if ((((iVar1 != 0) &&
       (iVar1 = (**(code **)(**(int **)(param_3 + 0x30c) + 0x44))
                          (*(int **)(param_3 + 0x30c),param_1), iVar1 != 0)) &&
      ((*(uint *)(param_1[0x56] + 0xc) & 8) != 0)) &&
     ((iVar1 = FUN_000f2d18(param_2,DAT_001aa804), iVar1 != 0 ||
      (iVar1 = ((int (*)())FUN_000ecb90)(param_1,param_3), iVar1 != 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_000ecd28 @ 0xecd28 (424 bytes) */
int FUN_000ecd28(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_28 [2];
  
  piVar2 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
  FUN_00106004(piVar2,1,param_2,0,*(undefined4 *)(param_1 + 8));
  FUN_0010469c(piVar2,param_1,param_4,param_5);
  (**(code **)(*piVar2 + 0x94))(piVar2,param_3,*(undefined4 *)(param_1 + 8));
  FUN_000f3258(local_28,param_6);
  piVar2[0x27] = local_28[0];
  iVar3 = FUN_001054ec(piVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = param_6;
  iVar3 = param_2[0x56];
  if (iVar3 == param_3[0x56]) {
    piVar4 = *(int **)(iVar3 + 0x98);
    for (piVar1 = (int *)(*(int **)(iVar3 + 0x98))[2]; piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[2]) {
      if ((piVar4[5] & 1U) != 0) {
        if (piVar4 == param_3) break;
        if (piVar4 == param_2) goto LAB_000ece34;
      }
      piVar4 = piVar1;
    }
  }
  else if ((*(uint *)(iVar3 + 0xc) & 8) == 0) goto LAB_000ece34;
  param_3 = param_2;
LAB_000ece34:
  piVar4 = (int *)param_3[0x56];
  iVar3 = (**(code **)(*piVar4 + 0x2c))(piVar4);
  if (iVar3 != 0) {
    FUN_000e76c4(piVar4[0x55],piVar2);
    return;
  }
  iVar3 = (**(code **)(*param_3 + 0x7c))(param_3);
  if (iVar3 != 0) {
    FUN_000e8424(piVar4,piVar2);
    return;
  }
  FUN_000e7738(piVar4,param_3,piVar2);
  return;
}

/* FUN_000eced0 @ 0xeced0 (140 bytes) */
int FUN_000eced0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar4,0x168);
  *puVar3 = uVar4;
  FUN_0010502c(puVar3 + 1,0x93,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x33c) = puVar3 + 1;
  puVar3[0x27] = 0x2d;
  puVar3[0x26] = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  *(uint *)(*(int *)(param_1 + 0x3a0) + 0xc) = *(uint *)(*(int *)(param_1 + 0x3a0) + 0xc) | 8;
  FUN_000e76c4(*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x33c));
  iVar1 = *(int *)(param_1 + 900);
  for (iVar2 = *(int *)(*(int *)(param_1 + 900) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 8;
    iVar1 = iVar2;
  }
  return;
}

/* FUN_000ecfac @ 0xecfac (312 bytes) */
int FUN_000ecfac(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x430);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x42c);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c8);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c4);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3ac);
  if (iVar1 != 0) {
    FUN_00127470(iVar1);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x460));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x45c));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x458));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x394));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x398));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x39c));
  FUN_00193fb4((undefined4 *)(param_1 + 0x37c));
  puVar2 = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(param_1 + 0x37c) = puVar2;
  *(undefined **)(param_1 + 0x388) = puVar2;
  return;
}

/* FUN_000ed124 @ 0xed124 (312 bytes) */
int FUN_000ed124(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x430);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x42c);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c8);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3c4);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x3ac);
  if (iVar1 != 0) {
    FUN_00127470(iVar1);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x460));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x45c));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x458));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x394));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x398));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),*(undefined4 *)(param_1 + 0x39c));
  FUN_00193fb4((undefined4 *)(param_1 + 0x37c));
  puVar2 = PTR_DAT_001e8b48 + 8;
  *(undefined4 *)(param_1 + 0x37c) = puVar2;
  *(undefined **)(param_1 + 0x388) = puVar2;
  return;
}

/* FUN_000ed29c @ 0xed29c (264 bytes) */
int FUN_000ed29c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  double fparam_1;
  undefined4 uStack_38;
  undefined4 auStack_34 [8];
  
  if (param_2 == 0) {
    FUN_000e1534(param_4,0xf);
  }
  iVar1 = FUN_001054ec(param_2,0);
  if (*(int *)(iVar1 + 0x10) != DAT_001aa800) {
    iVar2 = FUN_001043f0(0x31,param_4);
    fparam_1 = (double)FLOAT_001aa0d4;
    ((void (*)())FUN_000f79c4)(iVar2,*(undefined4 *)(param_4 + 0x6c4),1,fparam_1,fparam_1,fparam_1,
                 (double)FLOAT_001aa0e8);
    FUN_001046c8(iVar2,0,*(undefined4 *)(param_2 + 0xa4));
    iVar3 = FUN_001054ec(param_2,0);
    iVar1 = 0;
    auStack_34[0] = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      *(byte *)((int)auStack_34 + iVar1 + -4) =
           (byte)(-(*(byte *)((int)auStack_34 + iVar1) ^ 1) >> 0x1f);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(iVar2 + 0x9c) = uStack_38;
    FUN_000e76c4(*(undefined4 *)(param_2 + 0x158),iVar2);
    *(int *)(param_2 + 0x9c) = DAT_001aa800;
  }
  return;
}

/* FUN_000ed63c @ 0xed63c (424 bytes) */
int FUN_000ed63c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  int iVar8;
  
  if (*(int *)(param_2 + 0x80) != 0) {
    piVar1 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),*(undefined4 *)(param_2 + 0x98),
                                 *(undefined4 *)(param_2 + 0x94),0);
    pcVar7 = *(code **)(*piVar1 + 0x28);
    iVar2 = FUN_001054ec(param_2,0);
    piVar3 = (int *)(*pcVar7)(piVar1,*(undefined4 *)(iVar2 + 0x10),param_1);
    if ((piVar3 == (int *)0x0) || (piVar1 == piVar3)) {
      FUN_0012306c(piVar1,param_2);
      FUN_001046c8(param_2,0,piVar1);
    }
    else {
      FUN_0012306c(piVar3,param_2);
      FUN_001046c8(param_2,0,piVar3);
      if ((*(uint *)(param_1 + 0x30) & 0x4000) != 0) {
        FUN_000e7738(*(undefined4 *)(param_2 + 0x158),param_2,piVar1[0xc]);
      }
    }
  }
  if (0 < *(int *)(param_2 + 0x84)) {
    iVar5 = 1;
    iVar2 = param_2;
    do {
      iVar4 = *(int *)(iVar2 + 0xb0);
      if (iVar4 == 0x1c) {
        iVar8 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar8;
        uVar6 = *(undefined4 *)(iVar2 + 0xb0);
        iVar4 = FUN_001054ec(param_2,iVar5);
        *(int *)(iVar4 + 8) = iVar8;
        *(undefined4 *)(iVar4 + 0xc) = uVar6;
        iVar4 = *(int *)(iVar2 + 0xb0);
      }
      piVar1 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar4,
                                   *(undefined4 *)(iVar2 + 0xac),0);
      piVar3 = (int *)(**(code **)(*piVar1 + 0x28))(piVar1,DAT_001aa80c,param_1);
      if (piVar3 != (int *)0x0) {
        piVar1 = piVar3;
      }
      FUN_001236e4(piVar1,iVar5,param_2);
      FUN_001046c8(param_2,iVar5,piVar1);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar5 <= *(int *)(param_2 + 0x84));
  }
  return;
}

/* FUN_000ed7e4 @ 0xed7e4 (184 bytes) */
int FUN_000ed7e4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 extraout_r4;
  int iVar3;
  int *a0;
  uint uVar4;
  
  a0 = *(int **)(param_1 + 900);
  iVar1 = a0[2];
  while (iVar1 != 0) {
    (**(code **)(*a0 + 0x48))(a0,param_2);
    a0 = (int *)a0[2];
    param_2 = extraout_r4;
    iVar1 = a0[2];
  }
  iVar1 = *(int *)(param_1 + 0x3c4);
  iVar3 = 0;
  for (uVar4 = 1; uVar4 <= *(uint *)(iVar1 + 4); uVar4 = uVar4 + 1) {
    iVar2 = *(int *)(*(int *)(iVar1 + 8) + iVar3);
    if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
      FUN_001054ec(iVar2,0);
      iVar1 = *(int *)(param_1 + 0x3c4);
    }
    iVar3 = iVar3 + 4;
  }
  return 1;
}

/* FUN_000ed89c @ 0xed89c (852 bytes) */
int FUN_000ed89c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  int local_58;
  int local_54;
  int local_50 [6];
  
  iVar2 = *(int *)(param_1 + 900);
  iVar5 = *(int *)(*(int *)(param_1 + 900) + 8);
  do {
    if (iVar5 == 0) {
      return;
    }
    piVar3 = (int *)(*(int **)(iVar2 + 0x98))[2];
    if (piVar3 != (int *)0x0) {
      piVar12 = (int *)0x0;
      piVar15 = (int *)0x0;
      bVar1 = true;
      piVar10 = *(int **)(iVar2 + 0x98);
      do {
        piVar4 = piVar3;
        if ((piVar10[5] & 1U) != 0) {
          iVar13 = piVar10[0x2c];
          iVar5 = (**(code **)(*piVar10 + 0x28))(piVar10);
          if (((iVar5 == 0) || (iVar5 = (**(code **)(*piVar10 + 0x2c))(piVar10), iVar5 == 0)) ||
             ((iVar13 != 0x1f && (((iVar13 != 0xd && (iVar13 != 0xe)) && (iVar13 != 0xf)))))) {
            piVar4 = (int *)piVar10[2];
          }
          else {
            uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            puVar6 = (undefined4 *)FUN_00193e18(uVar16,0x18);
            *puVar6 = uVar16;
            puVar6[5] = piVar12;
            puVar6[2] = piVar10;
            piVar10[0x4d] = 1;
            iVar5 = FUN_001054ec(piVar10,1);
            iVar5 = *(int *)(iVar5 + 0x10);
            FUN_00104364(piVar10,&local_58,&local_54,local_50);
            puVar6[3] = local_54;
            puVar6[4] = local_50[0];
            piVar3 = piVar15;
            if (!bVar1) {
              do {
                if (((*piVar3 == local_58) && (iVar13 == piVar3[1])) && (piVar3[2] == iVar5)) {
                  if (local_54 < piVar3[5]) {
                    piVar3[3] = (int)piVar10;
                    piVar3[5] = local_54;
                  }
                  if (piVar3[6] < local_54 + local_50[0]) {
                    piVar3[6] = local_54 + local_50[0];
                  }
                  piVar3[4] = piVar3[4] + 1;
                  goto LAB_000eda98;
                }
                piVar12 = piVar3 + 0xb;
                piVar3 = (int *)*piVar12;
              } while ((int *)*piVar12 != (int *)0x0);
            }
            uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
            puVar7 = (undefined4 *)FUN_00193e18(uVar16,0x34);
            *puVar7 = uVar16;
            piVar3 = puVar7 + 1;
            bVar1 = piVar3 == (int *)0x0;
            puVar7[2] = iVar13;
            puVar7[1] = local_58;
            puVar7[3] = iVar5;
            puVar7[6] = local_54;
            puVar7[0xc] = piVar15;
            puVar7[7] = local_54 + local_50[0];
            puVar7[5] = 1;
            puVar7[4] = piVar10;
            piVar15 = piVar3;
LAB_000eda98:
            puVar6[1] = piVar3;
            piVar4 = (int *)piVar10[2];
            piVar12 = puVar6 + 1;
          }
        }
        piVar3 = (int *)piVar4[2];
        piVar10 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      if (!bVar1) {
        do {
          uVar16 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x22,0,0);
          piVar3 = (int *)0x0;
          do {
            iVar5 = piVar15[3];
            piVar10 = (int *)piVar15[0xb];
            piVar15[7] = iVar5;
            piVar15[0xb] = 0;
            uVar14 = *(undefined4 *)(iVar5 + 0x8c);
            iVar5 = FUN_001054ec(iVar5,0);
            uVar11 = *(undefined4 *)(iVar5 + 0x10);
            FUN_001046c8(piVar15[7],0,uVar16);
            *(undefined4 *)(piVar15[7] + 0x9c) = DAT_001aa800;
            FUN_0012306c(uVar16,piVar15[7]);
            uVar17 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            puVar6 = (undefined4 *)FUN_00193e18(uVar17,0x168);
            *puVar6 = uVar17;
            puVar7 = puVar6 + 1;
            FUN_00109e28(puVar7,0x84,*(undefined4 *)(param_1 + 8));
            FUN_001046c8(puVar7,0,uVar14);
            puVar6[0x28] = uVar11;
            FUN_001046c8(puVar7,1,uVar16);
            FUN_0012306c(uVar14,puVar7);
            FUN_001236e4(uVar16,1,puVar7);
            FUN_000e7738(iVar2,piVar15[7],puVar7);
            *(undefined4 **)(piVar15[7] + 0x138) = puVar7;
            piVar15[9] = piVar15[5];
            piVar15[8] = (int)puVar7;
            piVar15[10] = 0;
            *(undefined4 *)(piVar15[7] + 0x13c) = 0;
            if (8 < piVar15[6] - piVar15[5]) {
              piVar15[0xb] = (int)piVar3;
              piVar15[5] = piVar15[6] + 1;
              piVar15[6] = 0;
              piVar15[3] = 0;
              piVar15[4] = 0;
              piVar3 = piVar15;
            }
            piVar15 = piVar10;
          } while (piVar10 != (int *)0x0);
          piVar10 = (int *)0x0;
          piVar15 = piVar12;
          while (piVar12 = piVar10, piVar15 != (int *)0x0) {
            iVar18 = *piVar15;
            piVar4 = (int *)piVar15[4];
            piVar15[4] = 0;
            iVar13 = piVar15[1];
            iVar9 = piVar15[2];
            iVar8 = piVar15[3];
            iVar5 = (iVar9 + iVar8) - *(int *)(iVar18 + 0x24);
            piVar10 = piVar12;
            if (iVar13 == *(int *)(iVar18 + 0x1c)) {
              piVar15 = piVar4;
              if (*(int *)(iVar18 + 0x28) < iVar5) {
                *(int *)(iVar18 + 0x28) = iVar5;
                *(int *)(iVar13 + 0x13c) = iVar5;
              }
            }
            else if (iVar5 < 9) {
              if (*(int *)(iVar18 + 0x28) < iVar5) {
                *(int *)(iVar18 + 0x28) = iVar5;
                *(int *)(*(int *)(iVar18 + 0x1c) + 0x13c) = iVar5;
                iVar13 = piVar15[1];
              }
              FUN_0019401c(iVar13);
              FUN_00193f74(piVar15[1],*(undefined4 *)(iVar18 + 0x20));
              FUN_001049e8(piVar15[1],uVar16);
              FUN_001236e4(uVar16,*(undefined4 *)(piVar15[1] + 0x84),piVar15[1]);
              piVar15 = piVar4;
            }
            else {
              if (iVar9 < *(int *)(iVar18 + 0x14)) {
                *(int *)(iVar18 + 0xc) = iVar13;
                *(int *)(iVar18 + 0x14) = piVar15[2];
                iVar9 = piVar15[2];
                iVar8 = piVar15[3];
              }
              if (*(int *)(iVar18 + 0x18) < iVar9 + iVar8) {
                *(int *)(iVar18 + 0x18) = iVar9 + iVar8;
              }
              *(int *)(iVar18 + 0x10) = *(int *)(iVar18 + 0x10) + 1;
              piVar15[4] = (int)piVar12;
              piVar10 = piVar15;
              piVar15 = piVar4;
            }
          }
          piVar15 = piVar3;
        } while (piVar3 != (int *)0x0);
      }
      iVar5 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  } while( true );
}

/* FUN_000edd98 @ 0xedd98 (1216 bytes) */
int FUN_000edd98(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[0xc] = 0;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xab] = 0;
  param_1[0xcc] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xdd] = 0;
  FUN_001940a8(param_1 + 0xdf);
  iVar4 = 0x10;
  param_1[0xfa] = 0x7fffffff;
  param_1[0xfe] = 1;
  param_1[0xf6] = 0x7fffffff;
  param_1[0x10a] = 0xffffffff;
  param_1[0x11f] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe9] = 0;
  param_1[0xed] = 0;
  param_1[0xf0] = 0;
  param_1[0xf3] = 0;
  param_1[0xf5] = 0;
  param_1[0xf7] = 0xffffffff;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  param_1[0xfb] = 0xffffffff;
  param_1[0xfc] = 0;
  param_1[0x11d] = 0;
  param_1[0x11e] = 0;
  puVar1 = param_1;
  do {
    puVar1[0xe] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[0xac] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x6c);
  *puVar1 = uVar3;
  FUN_001272cc(puVar1 + 1,param_1[2]);
  param_1[0xeb] = puVar1 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x20c);
  puVar2[1] = 0x80;
  iVar4 = 0x80;
  *puVar2 = uVar3;
  puVar2[2] = 0x1000;
  puVar1 = puVar2 + 1;
  do {
    puVar1[2] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xec] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x8c);
  puVar2[1] = 0x20;
  *puVar2 = uVar3;
  puVar2[2] = 0x400;
  iVar4 = 0x20;
  puVar1 = puVar2 + 1;
  do {
    puVar1[2] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xef] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x14);
  *puVar1 = uVar3;
  puVar1[1] = 2;
  puVar1[4] = uVar3;
  puVar1[2] = 0;
  uVar3 = FUN_00193e18(uVar3,8);
  puVar1[3] = uVar3;
  param_1[0xf1] = puVar1 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x14);
  *puVar1 = uVar3;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar3;
  uVar3 = FUN_00193e18(uVar3,8);
  puVar1[3] = uVar3;
  iVar4 = 4;
  param_1[0xf2] = puVar1 + 1;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1[8] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xde] = 0;
  return;
}

/* FUN_000ee29c @ 0xee29c (1216 bytes) */
int FUN_000ee29c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[0xc] = 0;
  param_1[0x1f] = 0xffffffff;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  param_1[0x82] = 0;
  param_1[0x83] = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  param_1[0x89] = 0;
  param_1[0x8a] = 0;
  param_1[0x8b] = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0;
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[0xa5] = 0;
  param_1[0xa6] = 0;
  param_1[0xa7] = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xab] = 0;
  param_1[0xcc] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd1] = 0;
  param_1[0xd2] = 0;
  param_1[0xd3] = 0;
  param_1[0xd4] = 0;
  param_1[0xd6] = 0;
  param_1[0xd7] = 0;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0xda] = 0;
  param_1[0xdd] = 0;
  FUN_001940a8(param_1 + 0xdf);
  iVar4 = 0x10;
  param_1[0xfa] = 0x7fffffff;
  param_1[0xfe] = 1;
  param_1[0xf6] = 0x7fffffff;
  param_1[0x10a] = 0xffffffff;
  param_1[0x11f] = 0;
  param_1[0xe5] = 0;
  param_1[0xe6] = 0;
  param_1[0xe7] = 0;
  param_1[0xe9] = 0;
  param_1[0xed] = 0;
  param_1[0xf0] = 0;
  param_1[0xf3] = 0;
  param_1[0xf5] = 0;
  param_1[0xf7] = 0xffffffff;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  param_1[0xfb] = 0xffffffff;
  param_1[0xfc] = 0;
  param_1[0x11d] = 0;
  param_1[0x11e] = 0;
  puVar1 = param_1;
  do {
    puVar1[0xe] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[0xac] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x6c);
  *puVar1 = uVar3;
  FUN_001272cc(puVar1 + 1,param_1[2]);
  param_1[0xeb] = puVar1 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x20c);
  puVar2[1] = 0x80;
  iVar4 = 0x80;
  *puVar2 = uVar3;
  puVar2[2] = 0x1000;
  puVar1 = puVar2 + 1;
  do {
    puVar1[2] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xec] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar2 = (undefined4 *)FUN_00193e18(uVar3,0x8c);
  puVar2[1] = 0x20;
  *puVar2 = uVar3;
  puVar2[2] = 0x400;
  iVar4 = 0x20;
  puVar1 = puVar2 + 1;
  do {
    puVar1[2] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xef] = puVar2 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x14);
  *puVar1 = uVar3;
  puVar1[1] = 2;
  puVar1[4] = uVar3;
  puVar1[2] = 0;
  uVar3 = FUN_00193e18(uVar3,8);
  puVar1[3] = uVar3;
  param_1[0xf1] = puVar1 + 1;
  uVar3 = *(undefined4 *)(param_1[2] + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x14);
  *puVar1 = uVar3;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar3;
  uVar3 = FUN_00193e18(uVar3,8);
  puVar1[3] = uVar3;
  iVar4 = 4;
  param_1[0xf2] = puVar1 + 1;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1[8] = 0;
    puVar1 = puVar1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  param_1[0xde] = 0;
  return;
}

/* FUN_000ee7a0 @ 0xee7a0 (144 bytes) */
int FUN_000ee7a0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int local_138 [69];
  
  iVar1 = *(int *)(param_1 + 8);
  if (-1 < *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c)) {
    iVar5 = 0;
    piVar3 = local_138;
    do {
      uVar7 = *(undefined4 *)(iVar1 + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar7,0x14);
      *puVar2 = uVar7;
      puVar2[1] = 2;
      puVar2[4] = uVar7;
      puVar2[2] = 0;
      uVar7 = FUN_00193e18(uVar7,8);
      puVar2[3] = uVar7;
      iVar5 = iVar5 + 1;
      *piVar3 = (int)(puVar2 + 1);
      piVar3 = piVar3 + 1;
      iVar1 = *(int *)(param_1 + 8);
    } while (iVar5 <= *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c));
  }
  iVar1 = *(int *)(param_1 + 900);
  iVar5 = *(int *)(iVar1 + 8);
  while (iVar5 != 0) {
    puVar8 = (uint *)local_138[*(int *)(iVar1 + 0xb8)];
    uVar6 = puVar8[1];
    if (uVar6 < *puVar8) {
      _memset((void *)(uVar6 * 4 + puVar8[2]),0,4);
      piVar3 = (int *)(uVar6 * 4 + puVar8[2]);
      puVar8[1] = uVar6 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar8,uVar6);
    }
    *piVar3 = iVar1;
    iVar1 = *(int *)(iVar1 + 8);
    iVar5 = *(int *)(iVar1 + 8);
  }
  iVar1 = FUN_00194034(param_1 + 0x37c);
  iVar5 = iVar1 + -1;
  uVar7 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),iVar1 * 4 + 4);
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x39c) = uVar7;
  if (-1 < *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c)) {
    iVar4 = 0;
    do {
      iVar10 = iVar5 << 2;
      iVar9 = local_138[iVar4];
      uVar6 = *(uint *)(iVar9 + 4);
      if (uVar6 != 0) {
        do {
          iVar1 = *(int *)(param_1 + 0x39c);
          puVar2 = (undefined4 *)0x0;
          if (uVar6 - 1 < uVar6) {
            puVar2 = (undefined4 *)((uVar6 - 1) * 4 + *(int *)(iVar9 + 8));
          }
          uVar7 = *puVar2;
          iVar5 = iVar5 + -1;
          FUN_00194208(iVar9,uVar6 - 1);
          *(undefined4 *)(iVar10 + iVar1) = uVar7;
          uVar6 = *(uint *)(iVar9 + 4);
          iVar10 = iVar10 + -4;
        } while (uVar6 != 0);
        iVar1 = *(int *)(param_1 + 8);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= *(int *)(*(int *)(iVar1 + 0x30c) + 0x4c));
  }
  return *(undefined4 *)(param_1 + 0x39c);
}

/* FUN_000ee9ac @ 0xee9ac (120 bytes) */
int FUN_000ee9ac(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x3c4);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000eea24 @ 0xeea24 (556 bytes) */
int FUN_000eea24(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (((*(uint *)(param_1 + 0x30) & 1) != 0) &&
     (iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xe4))(),
     *(int *)(param_1 + 0x3d4) != 0)) {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x2000) == 0) {
      iVar1 = iVar3;
      if ((*(int *)(param_1 + 0x3e4) != 0) && (iVar1 = *(int *)(param_1 + 0x3ec), iVar1 <= iVar3)) {
        iVar1 = iVar3 + 1;
      }
      iVar3 = *(int *)(param_1 + 0x3d8);
      *(int *)(param_1 + 0x3e0) = iVar1 - iVar3;
      if (iVar3 < *(int *)(param_1 + 0x3dc)) {
        do {
          uVar7 = *(undefined4 *)(param_1 + 0x3ac);
          uVar4 = ((int (*)())FUN_000ec208)(param_1,5);
          iVar1 = FUN_00127534(uVar7,uVar4,iVar3,0);
          if (iVar1 != 0) {
            iVar5 = 0;
            for (uVar6 = 1; uVar6 <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); uVar6 = uVar6 + 1) {
              iVar2 = *(int *)(iVar5 + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())FUN_000ee9ac)(param_1,iVar2);
              }
              iVar5 = iVar5 + 4;
            }
            *(int *)(iVar1 + 0x10) = iVar3 + *(int *)(param_1 + 0x3e0);
            *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 2;
            FUN_00130444(param_1,iVar3 + *(int *)(param_1 + 0x3e0));
            FUN_00130bd4(param_1,iVar3 + *(int *)(param_1 + 0x3e0));
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x3dc));
      }
    }
    else {
      iVar3 = *(int *)(param_1 + 0x3d8);
      if (iVar3 < *(int *)(param_1 + 0x3dc)) {
        do {
          uVar7 = *(undefined4 *)(param_1 + 0x3ac);
          uVar4 = ((int (*)())FUN_000ec208)(param_1,5);
          iVar1 = FUN_00127534(uVar7,uVar4,iVar3,0);
          if (iVar1 != 0) {
            iVar5 = 0;
            for (uVar6 = 1; uVar6 <= *(uint *)(*(int *)(iVar1 + 0x18) + 4); uVar6 = uVar6 + 1) {
              iVar2 = *(int *)(iVar5 + *(int *)(*(int *)(iVar1 + 0x18) + 8));
              if ((*(uint *)(iVar2 + 0x14) & 1) != 0) {
                *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 0x10;
                ((int (*)())FUN_000ee9ac)(param_1,iVar2);
              }
              iVar5 = iVar5 + 4;
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0x3dc));
      }
    }
  }
  return;
}

/* FUN_000eec50 @ 0xeec50 (1072 bytes) */
int FUN_000eec50(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int *piVar12;
  double dVar13;
  
  if (*(int *)(param_1 + 0x3e4) != 0) {
    piVar12 = *(int **)(*(int *)(param_1 + 0x3a0) + 0x98);
    for (piVar1 = (int *)piVar12[2]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if ((piVar12[5] & 1U) != 0) {
        iVar7 = (**(code **)(*piVar12 + 0x4c))(piVar12);
        if (iVar7 != 0) {
          if ((((*(int *)(param_1 + 0x3e4) != 0) && (piVar12[0x51] == *(int *)(param_1 + 0x3f4))) &&
              (*(int *)(param_1 + 1000) <= piVar12[0x52])) &&
             (piVar12[0x52] < *(int *)(param_1 + 0x3ec))) {
            piVar12[5] = piVar12[5] | 0x10;
            ((int (*)())FUN_000ee9ac)(param_1,piVar12);
            piVar1 = (int *)piVar12[2];
            goto LAB_000eed14;
          }
        }
        piVar1 = (int *)piVar12[2];
      }
LAB_000eed14:
      piVar12 = piVar1;
    }
    *(int *)(param_1 + 0x3f0) = -*(int *)(param_1 + 1000);
  }
  if ((*(int *)(param_1 + 0x348) == 0) && (*(int *)(param_1 + 0x350) == 0)) {
    iVar7 = *(int *)(param_1 + 0x34c);
    if (iVar7 != 0) goto LAB_000eee08;
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar8 = (undefined4 *)FUN_00193e18(uVar9,0x168);
    *puVar8 = uVar9;
    puVar11 = puVar8 + 1;
    FUN_00108918(puVar11,*(undefined4 *)(param_1 + 8));
    *(undefined4 **)(param_1 + 0x348) = puVar11;
    iVar7 = FUN_001054ec(puVar11,0);
    uVar9 = DAT_001aa800;
    dVar13 = (double)FLOAT_001aa0d4;
    *(undefined4 *)(iVar7 + 0xc) = 9;
    *(undefined4 *)(iVar7 + 8) = 0;
    puVar8[0x28] = uVar9;
    ((void (*)())FUN_000f79c4)(puVar11,param_1,1,dVar13,dVar13,dVar13,dVar13);
    FUN_000f92fc(param_1,puVar11,*(undefined4 *)(param_1 + 0x3a8));
  }
  iVar7 = *(int *)(param_1 + 0x34c);
  if (iVar7 == 0) {
    return;
  }
LAB_000eee08:
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x4000) == 0) {
    return;
  }
  iVar2 = FUN_001043f0(0x17,*(undefined4 *)(param_1 + 8));
  FUN_001046c8(iVar2,1,*(undefined4 *)(iVar7 + 0xa4));
  iVar3 = FUN_001054ec(iVar7,1);
  dVar13 = (double)FLOAT_001aa0d4;
  uVar9 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_001054ec(iVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar9;
  ((void (*)())FUN_000f79c4)(iVar2,param_1,2,0.5000000596046448,dVar13,dVar13,dVar13);
  uVar9 = *(undefined4 *)(param_1 + 0x3ac);
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
  uVar4 = FUN_00127608(uVar9,0,iVar3,0);
  FUN_001046c8(iVar2,0,uVar4);
  uVar9 = DAT_001aa800;
  *(undefined4 *)(iVar2 + 0x120) = 1;
  *(undefined4 *)(iVar2 + 0x9c) = uVar9;
  iVar3 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
  FUN_001046c8(iVar3,1,*(undefined4 *)(iVar7 + 0xa4));
  iVar5 = FUN_001054ec(iVar7,1);
  uVar10 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = FUN_001054ec(iVar3,1);
  *(undefined4 *)(iVar5 + 0x10) = uVar10;
  ((void (*)())FUN_000f79c4)(iVar3,param_1,2,0.9999999403953552,dVar13,dVar13,dVar13);
  uVar10 = *(undefined4 *)(param_1 + 0x3ac);
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
  uVar10 = FUN_00127608(uVar10,0,iVar5,0);
  FUN_001046c8(iVar3,0,uVar10);
  *(undefined4 *)(iVar3 + 0x120) = 1;
  *(undefined4 *)(iVar3 + 0x9c) = uVar9;
  iVar5 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
  FUN_001046c8(iVar5,1,uVar4);
  uVar4 = DAT_001aa810;
  iVar6 = FUN_001054ec(iVar5,1);
  *(undefined4 *)(iVar6 + 0x10) = uVar4;
  ((void (*)())FUN_000f79c4)(iVar5,param_1,2,0.9999999403953552,dVar13,dVar13,dVar13);
  FUN_001046c8(iVar5,3,uVar10);
  iVar6 = FUN_001054ec(iVar5,3);
  *(undefined4 *)(iVar6 + 0x10) = uVar4;
  uVar4 = *(undefined4 *)(param_1 + 0x3ac);
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
  uVar4 = FUN_00127608(uVar4,0,iVar6,0);
  FUN_001046c8(iVar5,0,uVar4);
  *(undefined4 *)(iVar5 + 0x120) = 0;
  *(undefined4 *)(iVar5 + 0x9c) = uVar9;
  FUN_001046c8(iVar7,1,uVar4);
  uVar9 = *(undefined4 *)(iVar7 + 0x158);
  FUN_000e7700(uVar9,iVar7,iVar5);
  FUN_000e7700(uVar9,iVar5,iVar3);
  FUN_000e7700(uVar9,iVar3,iVar2);
  return;
}

/* FUN_000eee4c @ 0xeee4c (492 bytes) */
int FUN_000eee4c(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  code *pcVar10;
  int iVar11;
  int *piVar12;
  
  iVar1 = *(int *)(param_1 + 900);
  iVar3 = *(int *)(*(int *)(param_1 + 900) + 8);
  do {
    if (iVar3 == 0) {
      return;
    }
    piVar2 = (int *)(*(int **)(iVar1 + 0x98))[2];
    piVar12 = *(int **)(iVar1 + 0x98);
    if (piVar2 != (int *)0x0) {
      do {
        piVar4 = piVar2;
        if ((piVar12[5] & 1U) != 0) {
          iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xcc))();
          if (iVar3 == 0) {
            if (*(int *)(piVar12[0x22] + 8) == 0x77) {
              uVar9 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x30,0,0);
              FUN_001046c8(piVar12,0,uVar9);
              piVar12[5] = piVar12[5] | 0x10;
              FUN_0012306c(uVar9,piVar12);
              ((int (*)())FUN_000ee9ac)(param_1,piVar12);
            }
          }
          else if ((((piVar12[5] & 2U) != 0) && (iVar3 = FUN_0010406c(piVar12[0x26]), iVar3 == 9))
                  && (iVar3 = FUN_00127534(*(undefined4 *)(param_1 + 0x3ac),0x21,0,0), iVar3 != 0))
          {
            FUN_001049e8(piVar12,iVar3);
          }
          iVar3 = piVar12[0x26];
          if (iVar3 == 0x2a) {
            iVar3 = *(int *)(param_1 + 1000);
            piVar2 = piVar12;
            if (iVar3 < *(int *)(param_1 + 0x3ec)) {
              do {
                piVar4 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),
                                             *(undefined4 *)(param_1 + 0x3f4),iVar3,0);
                uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
                puVar5 = (undefined4 *)FUN_00193e18(uVar9,0x168);
                *puVar5 = uVar9;
                piVar8 = puVar5 + 1;
                FUN_00109e28(piVar8,0x84,*(undefined4 *)(param_1 + 8));
                puVar5[0x4b] = iVar3;
                pcVar10 = *(code **)(*piVar4 + 0x28);
                iVar6 = FUN_001054ec(piVar12,0);
                iVar6 = (*pcVar10)(piVar4,*(undefined4 *)(iVar6 + 0x10),param_1);
                iVar7 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xd8))();
                if (iVar7 != 0) {
                  *(int *)(iVar6 + 0x10) = iVar3;
                  *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 2;
                  FUN_00130444(param_1,iVar3);
                  FUN_00130bd4(param_1,iVar3);
                }
                iVar11 = piVar12[0x23];
                FUN_001046c8(piVar8,0,iVar6);
                iVar3 = iVar3 + 1;
                iVar7 = FUN_001054ec(piVar12,0);
                puVar5[0x28] = *(undefined4 *)(iVar7 + 0x10);
                FUN_0012306c(iVar6,piVar8);
                FUN_001046c8(piVar8,1,iVar11);
                FUN_001236e4(iVar11,1,piVar8);
                FUN_001049e8(piVar8,iVar6);
                FUN_001236e4(iVar6,2,piVar8);
                FUN_000e7738(iVar1,piVar2,piVar8);
                iVar6 = (**(code **)(*piVar4 + 0x2c))(piVar4);
                *(undefined4 *)(iVar6 + 0x144) = 1;
                piVar2 = piVar8;
              } while (iVar3 < *(int *)(param_1 + 0x3ec));
              piVar4 = (int *)puVar5[3];
            }
            else {
LAB_000ef1c8:
              piVar4 = (int *)piVar12[2];
            }
          }
          else {
            if ((piVar12[0x21] == 0) || ((iVar3 != 0x3b && (iVar3 != 0x2c)))) {
              if ((piVar12[0x20] == 0) ||
                 ((iVar3 = FUN_000f3154(piVar12), iVar3 == 0 ||
                  (iVar3 = (**(code **)(*piVar12 + 0x4c))(piVar12), iVar3 != 0))))
              goto LAB_000ef1c8;
              iVar3 = piVar12[0x23];
              FUN_001049e8(piVar12,iVar3);
            }
            else {
              iVar3 = piVar12[0x23];
              iVar6 = piVar12[0x21] + 1;
              piVar12[0x21] = iVar6;
              FUN_001046c8(piVar12,iVar6,iVar3);
            }
            FUN_001236e4(iVar3,piVar12[0x21],piVar12);
            piVar4 = (int *)piVar12[2];
          }
        }
        piVar2 = (int *)piVar4[2];
        piVar12 = piVar4;
      } while ((int *)piVar4[2] != (int *)0x0);
      iVar3 = *(int *)(iVar1 + 8);
    }
    iVar1 = iVar3;
    iVar3 = *(int *)(iVar3 + 8);
  } while( true );
}

/* FUN_000ef204 @ 0xef204 (660 bytes) */
int FUN_000ef204(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x16c))();
  iVar4 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x31);
  if (iVar4 == 0) {
    iVar4 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x33);
    if (iVar4 != 0) {
      piVar8 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
      for (piVar2 = (int *)piVar8[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
        if ((piVar8[5] & 1U) != 0) {
          iVar4 = (**(code **)(*piVar8 + 0x68))(piVar8);
          if ((((iVar4 != 0) && (piVar8[0x26] != 7)) &&
              (*(int *)(*(int *)(piVar8[0x22] + 8) * 0x38 + iVar3 + 0x34) == 0)) &&
             (iVar4 = FUN_000f3a30(piVar8), 1 < iVar4)) {
            iVar5 = 0;
            piVar2 = (int *)PTR_DAT_001e8b64;
            do {
              iVar6 = FUN_001054ec(piVar8,0);
              if (*(char *)(iVar5 + iVar6 + 0x10) != '\x01') {
                if (iVar4 < 2) {
                  piVar8[0x27] = *piVar2;
                }
                else {
                  iVar6 = FUN_0010445c(piVar8,*(undefined4 *)(param_1 + 8),0);
                  *(int *)(iVar6 + 0x9c) = *piVar2;
                  FUN_000e7700(*(undefined4 *)(param_1 + 0x3a8),piVar8,iVar6);
                  ((int (*)())FUN_000ee9ac)(param_1,iVar6);
                }
                iVar4 = iVar4 + -1;
              }
              bVar1 = iVar5 != 3;
              piVar2 = piVar2 + 1;
              iVar5 = iVar5 + 1;
            } while (bVar1);
          }
          piVar2 = (int *)piVar8[2];
        }
        piVar8 = piVar2;
      }
    }
  }
  else {
    piVar8 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
    for (piVar2 = (int *)piVar8[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      if ((piVar8[5] & 1U) != 0) {
        iVar4 = (**(code **)(*piVar8 + 0x68))(piVar8);
        if (((iVar4 != 0) && (iVar4 = piVar8[0x26], iVar4 != 6)) &&
           ((iVar4 != 7 &&
            ((iVar4 != 0x2c && (*(int *)(*(int *)(piVar8[0x22] + 8) * 0x38 + iVar3 + 0x34) == 0)))))
           ) {
          iVar4 = FUN_001054ec(piVar8,0);
          uVar7 = *(uint *)(iVar4 + 0x10);
          iVar4 = FUN_000f2e18(uVar7);
          if (iVar4 == 0) {
            iVar5 = FUN_0010445c(piVar8,*(undefined4 *)(param_1 + 8),0);
            iVar4 = DAT_001aa814;
            *(uint *)(iVar5 + 0x9c) = uVar7 & 0xffffff00 | 1;
            piVar8[0x27] = iVar4;
            FUN_000e7700(*(undefined4 *)(param_1 + 0x3a8),piVar8,iVar5);
            ((int (*)())FUN_000ee9ac)(param_1,iVar5);
            piVar2 = (int *)piVar8[2];
            goto LAB_000ef344;
          }
        }
        piVar2 = (int *)piVar8[2];
      }
LAB_000ef344:
      piVar8 = piVar2;
    }
  }
  return;
}

/* FUN_000ef498 @ 0xef498 (860 bytes) */
int FUN_000ef498(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  char *extraout_r4;
  undefined4 extraout_r4_00;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar7 = *(int *)(param_1 + 8);
  piVar8 = *(int **)(iVar7 + 0x30c);
  iVar2 = (**(code **)(*piVar8 + 0x138))(piVar8,iVar7);
  iVar3 = (**(code **)(*piVar8 + 0x140))(piVar8,iVar7);
  iVar7 = (**(code **)(*piVar8 + 0x13c))(piVar8,iVar7);
  iVar7 = iVar2 + iVar3 + iVar7;
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  uVar11 = iVar7 + 0x1fU >> 5;
  iVar2 = uVar11 * 4 + 0xc;
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,iVar2);
  piVar8 = puVar4 + 1;
  *puVar4 = uVar9;
  puVar4[1] = uVar11;
  puVar4[2] = iVar7;
  if (uVar11 != 0) {
    piVar1 = piVar8;
    uVar10 = uVar11;
    if (uVar11 == 0) {
      uVar10 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  *(int **)(param_1 + 0x42c) = piVar8;
  iVar3 = *piVar8;
  if (iVar3 != 0) {
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      piVar8[2] = -1;
      piVar8 = piVar8 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,iVar2);
  piVar8 = puVar4 + 1;
  *puVar4 = uVar9;
  puVar4[1] = uVar11;
  puVar4[2] = iVar7;
  if (uVar11 != 0) {
    piVar1 = piVar8;
    if (uVar11 == 0) {
      uVar11 = 1;
    }
    do {
      piVar1[2] = 0;
      piVar1 = piVar1 + 1;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  *(int **)(param_1 + 0x430) = piVar8;
  iVar2 = *piVar8;
  if (iVar2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    do {
      piVar8[2] = -1;
      piVar8 = piVar8 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar5 = (undefined4 *)FUN_00193e18(uVar9,0x8c);
  puVar5[1] = 0x20;
  iVar2 = 0x20;
  *puVar5 = uVar9;
  puVar5[2] = 0x400;
  puVar4 = puVar5 + 1;
  do {
    puVar4[2] = 0;
    puVar4 = puVar4 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 **)(param_1 + 0x434) = puVar5 + 1;
  *(undefined4 *)(param_1 + 0x43c) = 0;
  iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x138))();
  *(int *)(param_1 + 0x448) = iVar2;
  *(int *)(param_1 + 0x440) = iVar2;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x140))();
  iVar2 = iVar2 + iVar3;
  *(int *)(param_1 + 0x44c) = iVar2;
  *(int *)(param_1 + 0x444) = iVar2;
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x13c))();
  *(int *)(param_1 + 0x450) = iVar2 + iVar3;
  uVar9 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),
                       *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50) * 0xc);
  *(undefined4 *)(param_1 + 0x78) = uVar9;
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x134);
  *puVar4 = uVar9;
  puVar4 = puVar4 + 1;
  FUN_000eab70(puVar4,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x3a0) = puVar4;
  ((int (*)())FUN_000ec3e8)(param_1,puVar4);
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar4 = (undefined4 *)FUN_00193e18(uVar9,0x130);
  *puVar4 = uVar9;
  puVar4 = puVar4 + 1;
  FUN_000eaae8(puVar4,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x3a8) = puVar4;
  ((int (*)())FUN_000ec42c)(param_1,puVar4);
  FUN_00127994(*(undefined4 *)(param_1 + 0x3ac),*(uint *)(param_1 + 0x30) & 1);
  (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x10))();
  FUN_000fd5c8(param_1,param_2);
  if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
    if ((*(uint *)(param_1 + 0x30) & 0x2000) == 0) {
      uVar9 = 2;
      iVar2 = 2;
    }
    else {
      uVar9 = 1;
      iVar2 = 1;
    }
  }
  else {
    uVar9 = 0;
    iVar2 = 0;
  }
  piVar8 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  (**(code **)(*piVar8 + 0x14))(piVar8,uVar9);
  if (iVar2 == 1) {
    ((int (*)())FUN_000eec50)(param_1,extraout_r4_00);
  }
  else if ((iVar2 == 2) || (iVar2 == 0)) {
    piVar8 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar8 + 0xac))(piVar8,*(undefined4 *)(param_1 + 0x358),param_1);
  }
  ((int (*)())FUN_000ef204)(param_1);
  FUN_0012eacc(param_1);
  ((int (*)())FUN_000eee4c)(param_1);
  ((int (*)())FUN_000eea24)(param_1);
  FUN_00138130(param_1);
  pcVar6 = "non_local_set";
  piVar8 = *(int **)(param_1 + 900);
  iVar2 = piVar8[2];
  while (iVar2 != 0) {
    (**(code **)(*piVar8 + 0x48))(piVar8,pcVar6);
    piVar8 = (int *)piVar8[2];
    pcVar6 = extraout_r4;
    iVar2 = piVar8[2];
  }
  iVar2 = *(int *)(param_1 + 0x3c4);
  iVar3 = 0;
  for (uVar11 = 1; uVar11 <= *(uint *)(iVar2 + 4); uVar11 = uVar11 + 1) {
    iVar7 = *(int *)(*(int *)(iVar2 + 8) + iVar3);
    if ((*(uint *)(iVar7 + 0x14) & 1) != 0) {
      FUN_001054ec(iVar7,0);
      iVar2 = *(int *)(param_1 + 0x3c4);
    }
    iVar3 = iVar3 + 4;
  }
  return 1;
}

/* FUN_000ef8f8 @ 0xef8f8 (120 bytes) */
int FUN_000ef8f8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  
  puVar3 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar3[1];
  if (uVar2 < *puVar3) {
    _memset(uVar2 * 4 + puVar3[2],0,4);
    puVar1 = (undefined4 *)(uVar2 * 4 + puVar3[2]);
    puVar3[1] = uVar2 + 1;
  }
  else {
    puVar1 = (undefined4 *)FUN_0019423c(puVar3,uVar2);
  }
  *puVar1 = param_2;
  return;
}

/* FUN_000ef970 @ 0xef970 (220 bytes) */
int FUN_000ef970(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = *(uint **)(param_1 + 0x3c4);
  uVar1 = puVar5[1];
  if (uVar1 != 0) {
    uVar3 = 0;
    do {
      if (uVar3 < *puVar5) {
        puVar6 = puVar5;
        if (uVar1 <= uVar3) {
          _memset(uVar1 * 4 + puVar5[2],0,(uVar3 - uVar1) * 4 + 4);
          puVar5[1] = uVar3 + 1;
          puVar6 = *(uint **)(param_1 + 0x3c4);
        }
        piVar2 = (int *)(uVar3 * 4 + puVar5[2]);
        puVar5 = puVar6;
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar5,uVar3);
        puVar5 = *(uint **)(param_1 + 0x3c4);
      }
      uVar4 = uVar3 + 1;
      if (*piVar2 == param_2) {
        FUN_00194208(puVar5,uVar3);
        puVar5 = *(uint **)(param_1 + 0x3c4);
      }
      uVar1 = puVar5[1];
      uVar3 = uVar4;
    } while (uVar4 < uVar1);
  }
  return;
}

/* FUN_000efa4c @ 0xefa4c (164 bytes) */
int FUN_000efa4c(param_1)
  int param_1;
{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar10,0x14);
  puVar9 = puVar3 + 1;
  *puVar3 = uVar10;
  puVar3[1] = 2;
  puVar3[2] = 0;
  puVar3[4] = uVar10;
  uVar10 = FUN_00193e18(uVar10,8);
  puVar3[3] = uVar10;
  uVar10 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar4 = (undefined4 *)FUN_00193e18(uVar10,0x14);
  puVar7 = puVar4 + 1;
  *puVar4 = uVar10;
  puVar4[1] = 2;
  puVar4[2] = 0;
  puVar4[4] = uVar10;
  uVar10 = FUN_00193e18(uVar10,8);
  puVar4[3] = uVar10;
  iVar13 = *(int *)(param_1 + 900);
  for (iVar6 = *(int *)(*(int *)(param_1 + 900) + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    *(undefined4 *)(iVar13 + 0x118) = 0;
    iVar13 = iVar6;
  }
  uVar11 = puVar3[2];
  uVar10 = *(undefined4 *)(param_1 + 0x3a0);
  if (uVar11 < *puVar9) {
    _memset((void *)(uVar11 * 4 + puVar3[3]),0,4);
    puVar5 = (undefined4 *)(uVar11 * 4 + puVar3[3]);
    puVar3[2] = uVar11 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(puVar9,uVar11);
  }
  *puVar5 = uVar10;
  *(undefined4 *)(*(int *)(param_1 + 0x3a0) + 0x118) = 1;
code_r0x000efd60:
  uVar11 = puVar3[2];
  if (uVar11 == 0) {
    FUN_00193fa4(param_1 + 0x37c);
    iVar13 = puVar4[2];
    while (iVar13 != 0) {
      puVar3 = (undefined4 *)0x0;
      if (iVar13 - 1U < (uint)puVar4[2]) {
        puVar3 = (undefined4 *)((iVar13 - 1U) * 4 + puVar4[3]);
      }
      uVar10 = *puVar3;
      FUN_00194208(puVar7,puVar4[2] - 1);
      FUN_00193f64(param_1 + 0x37c,uVar10);
      ((int (*)())FUN_000ec2e8)(param_1);
      iVar13 = puVar4[2];
    }
    return;
  }
  piVar2 = (int *)0x0;
  if (uVar11 - 1 < uVar11) {
    piVar2 = (int *)((uVar11 - 1) * 4 + puVar3[3]);
  }
  iVar13 = *piVar2;
  FUN_00194208(puVar9,uVar11 - 1);
  uVar11 = puVar3[2];
  if (uVar11 < *puVar9) {
    _memset((void *)(uVar11 * 4 + puVar3[3]),0,4);
    piVar2 = (int *)(uVar11 * 4 + puVar3[3]);
    puVar3[2] = uVar11 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar9,uVar11);
  }
  *piVar2 = iVar13;
  iVar6 = FUN_000e79e8(iVar13);
  if (iVar6 != 0) goto code_r0x000efc2c;
  goto code_r0x000efce4;
code_r0x000efc2c:
  bVar1 = true;
  iVar6 = 0;
  for (uVar11 = 1; uVar11 <= *(uint *)(*(int *)(iVar13 + 0xd0) + 4); uVar11 = uVar11 + 1) {
    iVar8 = *(int *)(iVar6 + *(int *)(*(int *)(iVar13 + 0xd0) + 8));
    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x118) == 0)) {
      uVar12 = puVar3[2];
      if (uVar12 < *puVar9) {
        _memset((void *)(uVar12 * 4 + puVar3[3]),0,4);
        piVar2 = (int *)(uVar12 * 4 + puVar3[3]);
        puVar3[2] = uVar12 + 1;
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar9,uVar12);
      }
      *piVar2 = iVar8;
      bVar1 = false;
      *(undefined4 *)(iVar8 + 0x118) = 1;
    }
    iVar6 = iVar6 + 4;
  }
  if (bVar1) {
code_r0x000efce4:
    uVar11 = puVar3[2];
    puVar5 = (undefined4 *)0x0;
    if (uVar11 - 1 < uVar11) {
      puVar5 = (undefined4 *)((uVar11 - 1) * 4 + puVar3[3]);
    }
    uVar10 = *puVar5;
    FUN_00194208(puVar9,uVar11 - 1);
    uVar11 = puVar4[2];
    if (uVar11 < *puVar7) {
      _memset((void *)(uVar11 * 4 + puVar4[3]),0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + puVar4[3]);
      puVar4[2] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(puVar7,uVar11);
    }
    *puVar5 = uVar10;
  }
  goto code_r0x000efd60;
}

/* FUN_000efde4 @ 0xefde4 (536 bytes) */
int FUN_000efde4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar2 = (undefined4 *)FUN_00193e18(uVar9,0x168);
    *puVar2 = uVar9;
    puVar2 = puVar2 + 1;
    FUN_0010502c(puVar2,0x95,*(undefined4 *)(param_1 + 8));
  }
  else {
    uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar2 = (undefined4 *)FUN_00193e18(uVar9,0x168);
    *puVar2 = uVar9;
    puVar2 = puVar2 + 1;
    FUN_0010502c(puVar2,0x96,*(undefined4 *)(param_1 + 8));
  }
  *(undefined4 **)(param_1 + 0x33c) = puVar2;
  iVar5 = *(int *)(param_1 + 0x33c);
  *(undefined4 *)(iVar5 + 0x98) = 0x2d;
  *(undefined4 *)(iVar5 + 0x94) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x33c) + 300) = 0;
  iVar5 = *(int *)(param_1 + 0x3a8);
  *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 8;
  do {
    iVar7 = iVar5;
    iVar5 = *(int *)(iVar7 + 0xf0);
    if (iVar5 == 0) goto LAB_000eff14;
    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
    uVar6 = *(uint *)(iVar5 + 0xc);
  } while ((((uVar6 & 2) == 0) && ((uVar6 & 1) == 0)) && ((uVar6 & 4) == 0));
  if (*(int *)(*(int *)(iVar7 + 0xd4) + 4) == 1) {
    *(uint *)(iVar5 + 0xc) = uVar6 | 8;
    iVar7 = iVar5;
  }
LAB_000eff14:
  piVar4 = *(int **)(iVar7 + 0x98);
  piVar1 = (int *)(*(int **)(iVar7 + 0x98))[2];
  do {
    if (piVar1 == (int *)0x0) {
LAB_000eff98:
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
      if (*(int *)(param_1 + 0x344) != 0) {
        (**(code **)(**(int **)(param_1 + 0x33c) + 0x94))
                  (*(int **)(param_1 + 0x33c),*(int *)(param_1 + 0x344),*(undefined4 *)(param_1 + 8)
                  );
      }
      uVar9 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar9,0x14);
      puVar8 = puVar2 + 1;
      *puVar2 = uVar9;
      puVar2[1] = 2;
      puVar2[4] = uVar9;
      puVar2[2] = 0;
      uVar9 = FUN_00193e18(uVar9,8);
      iVar5 = 0;
      puVar2[3] = uVar9;
      for (uVar6 = 1; uVar6 <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); uVar6 = uVar6 + 1) {
        uVar9 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + iVar5);
        uVar10 = puVar2[2];
        if (uVar10 < *puVar8) {
          _memset((void *)(uVar10 * 4 + puVar2[3]),0,4);
          puVar3 = (undefined4 *)(uVar10 * 4 + puVar2[3]);
          puVar2[2] = uVar10 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar8,uVar10);
        }
        iVar5 = iVar5 + 4;
        *puVar3 = uVar9;
      }
      while (puVar2[2] != 0) {
        if (*puVar8 == 0) {
          piVar4 = (int *)FUN_0019423c(puVar8,0);
        }
        else {
          piVar4 = (int *)puVar2[3];
        }
        iVar7 = *piVar4;
        FUN_00194208(puVar8,0);
        iVar5 = 0;
        *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | 8;
        for (uVar6 = 1; uVar6 <= *(uint *)(*(int *)(iVar7 + 0xf4) + 4); uVar6 = uVar6 + 1) {
          uVar9 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0xf4) + 8) + iVar5);
          uVar10 = puVar2[2];
          if (uVar10 < *puVar8) {
            _memset((void *)(uVar10 * 4 + puVar2[3]),0,4);
            puVar3 = (undefined4 *)(uVar10 * 4 + puVar2[3]);
            puVar2[2] = uVar10 + 1;
          }
          else {
            puVar3 = (undefined4 *)FUN_0019423c(puVar8,uVar10);
          }
          iVar5 = iVar5 + 4;
          *puVar3 = uVar9;
        }
      }
      return;
    }
    if ((piVar4[5] & 1U) != 0) {
      iVar5 = (**(code **)(*piVar4 + 0x7c))(piVar4);
      if ((iVar5 == 0) && (iVar5 = (**(code **)(*piVar4 + 0x34))(piVar4), iVar5 == 0)) {
        FUN_000e7700(iVar7,piVar4,*(undefined4 *)(param_1 + 0x33c));
        goto LAB_000eff98;
      }
      piVar1 = (int *)piVar4[2];
    }
    piVar4 = piVar1;
    piVar1 = (int *)piVar1[2];
  } while( true );
}

/* FUN_000f019c @ 0xf019c (292 bytes) */
int FUN_000f019c(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int *piVar11;
  undefined4 uVar12;
  
  if (((*(uint *)(param_1 + 0x30) & 0x4000) != 0) && ((*(uint *)(param_1 + 0x30) & 0x80000) == 0)) {
    uVar3 = (*(uint **)(param_1 + 0x3c4))[1];
    if (uVar3 == 0) {
      iVar8 = 0;
    }
    else {
      uVar2 = 0;
      iVar8 = 0;
      puVar9 = *(uint **)(param_1 + 0x3c4);
      do {
        if (uVar2 < *puVar9) {
          puVar10 = puVar9;
          if (uVar3 <= uVar2) {
            _memset(uVar3 * 4 + puVar9[2],0,(uVar2 - uVar3) * 4 + 4);
            puVar9[1] = uVar2 + 1;
            puVar10 = *(uint **)(param_1 + 0x3c4);
          }
          piVar7 = (int *)(uVar2 * 4 + puVar9[2]);
        }
        else {
          piVar7 = (int *)FUN_0019423c(puVar9,uVar2);
          puVar10 = *(uint **)(param_1 + 0x3c4);
        }
        uVar2 = uVar2 + 1;
        if (*(int *)(*piVar7 + 0x98) == 0x2c) {
          iVar8 = *piVar7;
        }
        uVar3 = puVar10[1];
        puVar9 = puVar10;
      } while (uVar2 < uVar3);
    }
    uVar12 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar4 = (undefined4 *)FUN_00193e18(uVar12,0x14);
    *puVar4 = uVar12;
    puVar4[1] = 2;
    puVar4[2] = 0;
    puVar4[4] = uVar12;
    uVar12 = FUN_00193e18(uVar12,8);
    puVar4[3] = uVar12;
    iVar5 = FUN_00105594(iVar8,1);
    while (*(int *)(iVar5 + 0x84) != 0) {
      iVar1 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
      if ((iVar1 == 0xf7) || (iVar1 == 0x107)) {
        uVar3 = puVar4[2];
        if (uVar3 < (uint)puVar4[1]) {
          _memset(uVar3 * 4 + puVar4[3],0,4);
          puVar4[2] = uVar3 + 1;
          piVar7 = (int *)(uVar3 * 4 + puVar4[3]);
        }
        else {
          piVar7 = (int *)FUN_0019423c(puVar4 + 1,uVar3);
        }
        *piVar7 = iVar5;
        iVar5 = FUN_00105594(iVar5,1);
      }
      else if (iVar1 == 0xf9) {
        iVar5 = FUN_00105594(iVar5,2);
      }
      else {
        if (iVar1 == 0x8e) {
          return;
        }
        iVar5 = FUN_00105594(iVar5,1);
      }
    }
    uVar3 = puVar4[2];
    if (*(int *)(param_1 + 0x3f8) < (int)uVar3) {
      uVar2 = uVar3 - *(int *)(param_1 + 0x3f8);
      puVar6 = (undefined4 *)0x0;
      if (uVar2 < uVar3) {
        puVar6 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
      }
      piVar11 = (int *)*puVar6;
      piVar7 = (int *)FUN_00105594(iVar8,1);
      while (piVar11 != piVar7) {
        iVar5 = *(int *)(piVar7[0x22] + 8);
        if (((iVar5 == 0xf7) || (iVar5 == 0x107)) || (iVar5 != 0xf9)) {
          (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(param_1 + 8));
          piVar7 = (int *)FUN_00105594(piVar7,1);
        }
        else {
          (**(code **)(*piVar7 + 0xc))(piVar7,0,*(undefined4 *)(param_1 + 8));
          piVar7 = (int *)FUN_00105594(piVar7,2);
        }
      }
      FUN_00106004(iVar8,1,piVar11,0,*(undefined4 *)(param_1 + 8));
      FUN_00105334(iVar8,2,piVar11,*(undefined4 *)(param_1 + 8));
      return;
    }
  }
  return;
}

/* FUN_000f04d4 @ 0xf04d4 (724 bytes) */
int FUN_000f04d4(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
  double fparam_1;
  
  iVar4 = (**(code **)(*param_2 + 0x68))(param_2);
  if ((iVar4 == 0) && (iVar4 = (**(code **)(*param_2 + 100))(param_2), iVar4 != 0)) {
    for (iVar4 = 1; iVar5 = (**(code **)(*param_2 + 0x14))(param_2), iVar4 <= iVar5;
        iVar4 = iVar4 + 1) {
      if ((((param_2[iVar4 * 6 + 0x28] & 1U) != 0) || ((param_2[iVar4 * 6 + 0x28] & 2U) != 0)) ||
         (iVar5 = FUN_000f31e8(param_2,iVar4), iVar5 == 0)) goto LAB_000f0628;
    }
    if ((param_2[0x48] == 0) && (param_2[0x49] == 0)) {
      if (((param_2[0x20] != 0) &&
          ((iVar4 = FUN_00126760(param_2[0x26]), iVar4 != 0 && ((param_2[5] & 2U) == 0)))) &&
         (iVar4 = (**(code **)(*param_2 + 0x50))(param_2), iVar4 == 0)) {
        iVar4 = 4;
        piVar6 = param_2;
        do {
          if (*(byte *)(piVar6 + 0x27) - 2 < 2) goto LAB_000f0628;
          piVar6 = (int *)((int)piVar6 + 1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      FUN_001054ec(param_2,0);
      FUN_00105dbc(param_2,0);
    }
  }
LAB_000f0628:
  piVar6 = (int *)FUN_00105594(param_2,1);
  iVar4 = 0;
  uVar8 = 0xffffffff;
  bVar2 = true;
  fVar7 = 0.0;
  (**(code **)(*piVar6 + 0x48))();
  do {
    iVar5 = FUN_001054ec(param_2,0);
    if (*(char *)(iVar4 + iVar5 + 0x10) != '\x01') {
      iVar5 = FUN_001054ec(param_2,1);
      uVar9 = (uint)*(byte *)(iVar4 + iVar5 + 0x10);
      if ((((int)*(char *)(piVar6 + 0x57) >> (uVar9 & 0x3f) & 1U) == 0) ||
         (iVar5 = ((undefined4 (*)())FUN_0010aafc)((double)(float)piVar6[uVar9 * 6 + 8]), iVar5 == 0)) {
        bVar2 = false;
      }
      else if (uVar8 == 0xffffffff) {
        fVar7 = (float)piVar6[uVar9 * 6 + 8];
        uVar8 = uVar9;
      }
      else if (fVar7 != (float)piVar6[uVar9 * 6 + 8]) {
        return 0;
      }
    }
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if (bVar2) {
    iVar4 = ((int (*)())FUN_0010ab40)((double)(float)piVar6[uVar8 * 6 + 8]);
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    iVar5 = (**(code **)(*piVar6 + 0xfc))(piVar6,iVar4,param_2);
    if (iVar5 != 0) {
      fparam_1 = (double)FLOAT_001aa0e8;
      ((void (*)())FUN_000f79c4)(param_2,*(undefined4 *)(*(int *)(param_1 + 8) + 0x6c4),1,fparam_1,fparam_1,
                   fparam_1,fparam_1);
      uVar3 = DAT_001aa804;
      param_2[0x49] = iVar4;
      iVar4 = FUN_001054ec(param_2,1);
      *(undefined4 *)(iVar4 + 0x10) = uVar3;
      return 1;
    }
  }
  return 0;
}

/* FUN_000f07a8 @ 0xf07a8 (464 bytes) */
int FUN_000f07a8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  int local_88;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [4];
  undefined4 local_74 [7];
  int local_58;
  int local_54;
  undefined4 local_50;
  int local_4c [6];
  
  iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xb8))();
  if ((((iVar3 == 0) && ((param_3[5] & 8U) == 0)) &&
      (iVar3 = (**(code **)(*param_3 + 0x18))(param_3), iVar3 < 2)) &&
     (iVar3 = (**(code **)(*param_3 + 0x14))(param_3), iVar3 != 0)) {
    piVar8 = (int *)FUN_00105594(param_3,1);
    iVar3 = (**(code **)(*param_3 + 0x68))(param_3);
    if (((iVar3 != 0) || (iVar3 = (**(code **)(*param_3 + 100))(param_3), iVar3 != 0)) &&
       (((param_3[0x2e] & 1U) == 0 && ((param_3[0x2e] & 2U) == 0)))) {
      iVar3 = FUN_001054ec(param_3,1);
      uVar16 = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = FUN_001054ec(param_3,0);
      FUN_000f3908(&local_50,*(undefined4 *)(iVar3 + 0x10));
      FUN_000f3340(local_4c,uVar16,local_50);
      local_88 = local_4c[0];
      iVar3 = ((int (*)())FUN_000ecc1c)(piVar8,local_4c[0],*(undefined4 *)(param_1 + 8));
      if (iVar3 != 0) {
        iVar3 = (**(code **)(*piVar8 + 0x60))(piVar8);
        if (iVar3 != 0) {
          piVar8 = (int *)FUN_0010cb48(piVar8,*(undefined4 *)(param_1 + 8));
          FUN_00106004(param_3,1,piVar8,0,*(undefined4 *)(param_1 + 8));
        }
        iVar3 = param_3[0x26];
        uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        iVar10 = param_3[0x25];
        puVar4 = (undefined4 *)FUN_00193e18(uVar16,0x14);
        puVar11 = puVar4 + 1;
        *puVar4 = uVar16;
        puVar4[1] = 2;
        puVar4[4] = uVar16;
        puVar4[2] = 0;
        uVar16 = FUN_00193e18(uVar16,8);
        puVar4[3] = uVar16;
        uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        puVar5 = (undefined4 *)FUN_00193e18(uVar16,0x14);
        puVar12 = puVar5 + 1;
        *puVar5 = uVar16;
        puVar5[1] = 2;
        puVar5[2] = 0;
        puVar5[4] = uVar16;
        uVar16 = FUN_00193e18(uVar16,8);
        uVar2 = puVar4[1];
        uVar13 = puVar4[2];
        puVar5[3] = uVar16;
        if (uVar13 < uVar2) {
          _memset((void *)(uVar13 * 4 + puVar4[3]),0,4);
          puVar4[2] = uVar13 + 1;
          puVar6 = (undefined4 *)(uVar13 * 4 + puVar4[3]);
        }
        else {
          puVar6 = (undefined4 *)FUN_0019423c(puVar11,uVar13);
        }
        iVar15 = local_88;
        *puVar6 = piVar8;
        uVar2 = puVar5[2];
        if (uVar2 < *puVar12) {
          _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
          piVar8 = (int *)(uVar2 * 4 + puVar5[3]);
          puVar5[2] = uVar2 + 1;
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar12,uVar2);
        }
        *piVar8 = iVar15;
        *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
code_r0x000f1384:
        do {
          while( true ) {
            do {
              do {
                uVar2 = puVar4[2];
                if (uVar2 == 0) {
                  (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
                  if (puVar11 != (uint *)0x0) {
                    FUN_00193cc0(puVar4[4],puVar4[3]);
                    FUN_00193cc0(*puVar4,puVar4);
                  }
                  if (puVar12 == (uint *)0x0) {
                    return;
                  }
                  FUN_00193cc0(puVar5[4],puVar5[3]);
                  FUN_00193cc0(*puVar5,puVar5);
                  return;
                }
                puVar6 = (undefined4 *)0x0;
                if (uVar2 - 1 < uVar2) {
                  puVar6 = (undefined4 *)((uVar2 - 1) * 4 + puVar4[3]);
                }
                piVar8 = (int *)*puVar6;
                FUN_00194208(puVar11,uVar2 - 1);
                uVar2 = puVar5[2];
                piVar14 = (int *)0x0;
                if (uVar2 - 1 < uVar2) {
                  piVar14 = (int *)((uVar2 - 1) * 4 + puVar5[3]);
                }
                iVar15 = *piVar14;
                FUN_00194208(puVar12,uVar2 - 1);
                local_88 = iVar15;
                iVar15 = ((int (*)())FUN_000ecc1c)(piVar8,iVar15,*(undefined4 *)(param_1 + 8));
                if ((iVar15 != 0) && (iVar15 = (**(code **)(*piVar8 + 0x60))(piVar8), iVar15 != 0))
                {
                  piVar8 = (int *)FUN_0010cb48(piVar8,*(undefined4 *)(param_1 + 8));
                }
              } while ((*(int *)(param_1 + 0x474) == piVar8[0x54]) &&
                      (*(int *)(piVar8[0x22] + 8) == 0x8e));
              piVar8[0x54] = *(int *)(param_1 + 0x474);
              iVar15 = (**(code **)(*piVar8 + 0x50))(piVar8);
            } while (iVar15 != 0);
            local_80 = local_88;
            local_84 = local_88;
            iVar15 = FUN_001054ec(piVar8,0);
            iVar9 = 0;
            local_7c = *(undefined4 *)(iVar15 + 0x10);
            iVar15 = 4;
            do {
              if (*(byte *)((int)&local_88 + iVar9) != 4) {
                if (auStack_78[*(byte *)((int)&local_88 + iVar9) - 4] == '\x01') {
                  *(undefined1 *)((int)&local_84 + iVar9) = 4;
                }
                else {
                  *(undefined1 *)((int)&local_80 + iVar9) = 4;
                }
              }
              iVar7 = local_80;
              iVar9 = iVar9 + 1;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
            if (local_84 != UNK_001aa808) break;
            if (((piVar8[5] & 0x200U) != 0) && (local_84 != local_80)) {
              uVar2 = puVar5[2];
              if (uVar2 < *puVar12) {
                _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
                puVar5[2] = uVar2 + 1;
                piVar14 = (int *)(uVar2 * 4 + puVar5[3]);
              }
              else {
                piVar14 = (int *)FUN_0019423c(puVar12,uVar2);
              }
              *piVar14 = iVar7;
              uVar16 = FUN_00105594(piVar8,piVar8[0x21]);
              uVar2 = puVar4[2];
              if (uVar2 < *puVar11) {
                _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
                puVar4[2] = uVar2 + 1;
                puVar6 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
              }
              else {
                puVar6 = (undefined4 *)FUN_0019423c(puVar11,uVar2);
              }
              *puVar6 = uVar16;
            }
          }
          iVar15 = ((int (*)())FUN_000ecc1c)(piVar8,local_84,*(undefined4 *)(param_1 + 8));
          if (iVar15 != 0) {
            iVar9 = (**(code **)(*piVar8 + 0x7c))(piVar8);
            iVar15 = local_80;
            if (iVar9 == 0) {
              if (((piVar8[5] & 0x200U) != 0) && (local_80 != UNK_001aa808)) {
                uVar2 = puVar5[2];
                if (uVar2 < *puVar12) {
                  _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
                  puVar5[2] = uVar2 + 1;
                  piVar14 = (int *)(uVar2 * 4 + puVar5[3]);
                }
                else {
                  piVar14 = (int *)FUN_0019423c(puVar12,uVar2);
                }
                *piVar14 = iVar15;
                uVar16 = FUN_00105594(piVar8,piVar8[0x21]);
                uVar2 = puVar4[2];
                if (uVar2 < *puVar11) {
                  _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
                  puVar4[2] = uVar2 + 1;
                  puVar6 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
                }
                else {
                  puVar6 = (undefined4 *)FUN_0019423c(puVar11,uVar2);
                }
                *puVar6 = uVar16;
                FUN_00106004(piVar8,piVar8[0x21],0,0,*(undefined4 *)(param_1 + 8));
                piVar8[0x21] = piVar8[0x21] + -1;
                piVar8[5] = piVar8[5] & 0xfffffdff;
              }
              iVar15 = (**(code **)(*piVar8 + 100))(piVar8);
              if (iVar15 != 0) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  if ((((piVar8[iVar15 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar8[iVar15 * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = FUN_000f31e8(piVar8,iVar15), iVar9 == 0)) goto code_r0x000f101c;
                }
                if ((piVar8[0x48] == 0) && (piVar8[0x49] == 0)) {
                  if (((piVar8[0x20] != 0) &&
                      ((iVar15 = FUN_00126760(piVar8[0x26]), iVar15 != 0 && ((piVar8[5] & 2U) == 0))
                      )) && (iVar15 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar15 == 0)) {
                    iVar15 = 4;
                    piVar14 = piVar8;
                    do {
                      if (*(byte *)(piVar14 + 0x27) - 2 < 2) goto code_r0x000f101c;
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar15 = iVar15 + -1;
                    } while (iVar15 != 0);
                  }
                  FUN_001054ec(piVar8,0);
                  iVar15 = FUN_00105dbc(piVar8,0);
                  if ((iVar15 == 0) && ((piVar8[5] & 2U) == 0)) {
                    uVar16 = FUN_00105594(piVar8,1);
                    iVar9 = ((int (*)())FUN_000ecc1c)(uVar16,local_84,*(undefined4 *)(param_1 + 8));
                    iVar15 = local_84;
                    if (iVar9 != 0) {
                      uVar2 = puVar5[2];
                      if (uVar2 < *puVar12) {
                        _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
                        puVar5[2] = uVar2 + 1;
                        piVar14 = (int *)(uVar2 * 4 + puVar5[3]);
                      }
                      else {
                        piVar14 = (int *)FUN_0019423c(puVar12,uVar2);
                      }
                      *piVar14 = iVar15;
                      uVar16 = FUN_00105594(piVar8,1);
                      uVar2 = puVar4[2];
                      if (uVar2 < *puVar11) {
                        _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
                        puVar4[2] = uVar2 + 1;
                        puVar6 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
                      }
                      else {
                        puVar6 = (undefined4 *)FUN_0019423c(puVar11,uVar2);
                      }
                      *puVar6 = uVar16;
                      goto code_r0x000f1140;
                    }
                  }
                }
              }
code_r0x000f101c:
              FUN_0010469c(piVar8,param_1,iVar3,iVar10);
              (**(code **)(*piVar8 + 0x94))(piVar8,param_2,*(undefined4 *)(param_1 + 8));
              FUN_000f3258(&local_58,local_84);
              uVar16 = DAT_001aa804;
              piVar8[0x27] = local_58;
              iVar15 = FUN_000f2d18(local_84,uVar16);
              if ((iVar15 == 0) &&
                 (iVar15 = FUN_0011379c(*(undefined4 *)(param_1 + 8),piVar8), iVar15 != 0)) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  iVar9 = FUN_001054ec(piVar8,iVar15);
                  ((int (*)())FUN_000f2bdc)(&local_54,*(undefined4 *)(iVar9 + 0x10),local_84);
                  iVar9 = local_54;
                  if (iVar15 == 0) {
                    piVar8[0x27] = local_54;
                  }
                  else {
                    iVar7 = FUN_001054ec(piVar8,iVar15);
                    *(int *)(iVar7 + 0x10) = iVar9;
                  }
                }
              }
              iVar15 = (**(code **)(*piVar8 + 100))(piVar8);
              if (iVar15 != 0) {
                for (iVar15 = 1; iVar9 = (**(code **)(*piVar8 + 0x14))(piVar8), iVar15 <= iVar9;
                    iVar15 = iVar15 + 1) {
                  if ((((piVar8[iVar15 * 6 + 0x28] & 1U) != 0) ||
                      ((piVar8[iVar15 * 6 + 0x28] & 2U) != 0)) ||
                     (iVar9 = FUN_000f31e8(piVar8,iVar15), iVar9 == 0)) goto code_r0x000f1384;
                }
                if ((piVar8[0x48] == 0) && (piVar8[0x49] == 0)) {
                  if (((piVar8[0x20] != 0) &&
                      ((iVar15 = FUN_00126760(piVar8[0x26]), iVar15 != 0 && ((piVar8[5] & 2U) == 0))
                      )) && (iVar15 = (**(code **)(*piVar8 + 0x50))(piVar8), iVar15 == 0)) {
                    iVar15 = 4;
                    piVar14 = piVar8;
                    do {
                      if (*(byte *)(piVar14 + 0x27) - 2 < 2) goto code_r0x000f1384;
                      piVar14 = (int *)((int)piVar14 + 1);
                      iVar15 = iVar15 + -1;
                    } while (iVar15 != 0);
                  }
                  FUN_001054ec(piVar8,0);
                  iVar15 = FUN_00105dbc(piVar8,0);
                  if (iVar15 == 0) {
                    piVar14 = (int *)FUN_00105594(piVar8,1);
                    iVar15 = (**(code **)(*piVar14 + 0x48))();
                    if (iVar15 != 0) {
                      iVar15 = 4;
                      puVar6 = local_74;
                      do {
                        *puVar6 = 0x7ffffffe;
                        puVar6 = puVar6 + 1;
                        iVar15 = iVar15 + -1;
                      } while (iVar15 != 0);
                      local_74[0] = 0x3f800000;
                      local_74[3] = 0x3f800000;
                      local_74[2] = 0x3f800000;
                      local_74[1] = 0x3f800000;
                      piVar14 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
                      iVar15 = (**(code **)(*piVar14 + 0xe8))
                                         (piVar14,local_74,auStack_78,DAT_001aa804);
                      if (iVar15 != 0) {
                        ((int (*)())FUN_000f04d4)(param_1,piVar8);
                      }
                    }
                  }
                }
              }
            }
            else {
              iVar15 = piVar8[0x21];
              if (0 < iVar15) {
                iVar9 = 1;
                bVar1 = true;
                do {
                  piVar14 = (int *)FUN_00105594(piVar8,iVar9);
                  iVar15 = (**(code **)(*piVar14 + 0x7c))();
                  if ((iVar15 != 0) ||
                     (iVar15 = ((int (*)())FUN_000ecc1c)(piVar14,local_84,*(undefined4 *)(param_1 + 8)),
                     iVar15 == 0)) {
                    bVar1 = false;
                  }
                  iVar15 = piVar8[0x21];
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= iVar15);
                if (!bVar1) goto code_r0x000f0d0c;
              }
              iVar9 = 1;
              if (0 < iVar15) {
                do {
                  iVar15 = local_88;
                  uVar2 = puVar5[2];
                  if (uVar2 < *puVar12) {
                    _memset((void *)(uVar2 * 4 + puVar5[3]),0,4);
                    puVar5[2] = uVar2 + 1;
                    piVar14 = (int *)(uVar2 * 4 + puVar5[3]);
                  }
                  else {
                    piVar14 = (int *)FUN_0019423c(puVar12,uVar2);
                  }
                  *piVar14 = iVar15;
                  uVar16 = FUN_00105594(piVar8,iVar9);
                  uVar2 = puVar4[2];
                  if (uVar2 < *puVar11) {
                    _memset((void *)(uVar2 * 4 + puVar4[3]),0,4);
                    puVar4[2] = uVar2 + 1;
                    puVar6 = (undefined4 *)(uVar2 * 4 + puVar4[3]);
                  }
                  else {
                    puVar6 = (undefined4 *)FUN_0019423c(puVar11,uVar2);
                  }
                  *puVar6 = uVar16;
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= piVar8[0x21]);
              }
code_r0x000f1140:
              (**(code **)(*piVar8 + 0xc))(piVar8,0,*(undefined4 *)(param_1 + 8));
            }
            goto code_r0x000f1384;
          }
code_r0x000f0d0c:
          ((int (*)())FUN_000ecd28)(param_1,piVar8,param_2,iVar3,iVar10,local_88);
        } while( true );
      }
    }
  }
  (**(code **)(*param_3 + 0x94))(param_3,param_2,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f14f8 @ 0xf14f8 (132 bytes) */
int FUN_000f14f8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  bool bVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [3];
  
  uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x168);
  *puVar3 = uVar14;
  FUN_0010502c(puVar3 + 1,0x93,*(undefined4 *)(param_1 + 8));
  *(undefined4 **)(param_1 + 0x340) = puVar3 + 1;
  puVar3[0x27] = 0x2e;
  puVar3[0x26] = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 0;
  iVar4 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),0x23);
  if (iVar4 == 0) {
    if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (param_2 != (int *)0x0)) {
      FUN_000e76c4(param_2[0x56],*(undefined4 *)(param_1 + 0x340));
      (**(code **)(*param_2 + 0x94))
                (param_2,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
      if (param_3 != (int *)0x0) {
        *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 1;
        uVar11 = *(undefined4 *)(param_1 + 8);
        UNRECOVERED_JUMPTABLE = *(code **)(*param_3 + 0x94);
        uVar14 = *(undefined4 *)(param_1 + 0x340);
        param_2 = param_3;
        goto LAB_000f1940;
      }
    }
  }
  else if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (param_2 != (int *)0x0)) {
    iVar4 = param_2[0x56];
    if (param_3 == (int *)0x0) {
      piVar5 = (int *)FUN_00105594(param_2,1);
      iVar6 = FUN_001054ec(param_2,1);
      iVar12 = *(int *)(iVar6 + 0x10);
      iVar6 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xb8))();
      if (((iVar6 == 0) && (iVar6 = (**(code **)(*piVar5 + 0x7c))(piVar5), iVar6 == 0)) &&
         ((((iVar6 = FUN_0011379c(*(undefined4 *)(param_1 + 8),piVar5), iVar6 != 0 &&
            ((iVar6 = piVar5[0x58] - *(int *)(param_1 + 0x478), iVar6 < 0 || (iVar6 < 2)))) &&
           (iVar6 = (**(code **)(*piVar5 + 0x28))(piVar5), iVar6 == 0)) &&
          ((piVar5[0x21] != 0 && (iVar12 == DAT_001aa804)))))) {
        iVar4 = FUN_001054ec(param_2,0);
        uVar14 = *(undefined4 *)(iVar4 + 0x10);
        ((int (*)())FUN_000ef970)(param_1,param_2);
        (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
        iVar6 = piVar5[0x56];
        FUN_0010469c(piVar5,param_1,6,0);
        (**(code **)(*piVar5 + 0x94))
                  (piVar5,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
        iVar4 = FUN_001054ec(piVar5,0);
        FUN_000f302c(&local_44,uVar14,*(undefined4 *)(iVar4 + 0x10));
        uVar2 = piVar5[5];
        iVar4 = local_44;
        do {
          if ((uVar2 & 0x200) == 0) {
code_r0x000e76c4:
            iVar4 = *(int *)(param_1 + 0x340);
            FUN_00193f74(iVar4,*(undefined4 *)(iVar6 + 200));
            *(int *)(iVar4 + 0x158) = iVar6;
            return;
          }
          piVar7 = (int *)FUN_00105594(piVar5,piVar5[0x21]);
          FUN_00106004(piVar5,piVar5[0x21],0,0,*(undefined4 *)(param_1 + 8));
          iVar12 = *piVar7;
          piVar5[0x21] = piVar5[0x21] + -1;
          piVar5[5] = piVar5[5] & 0xfffffdff;
          iVar12 = (**(code **)(iVar12 + 0x7c))(piVar7);
          if ((((iVar12 != 0) ||
               (iVar12 = FUN_0011379c(*(undefined4 *)(param_1 + 8),piVar7), iVar12 == 0)) ||
              ((iVar12 = piVar7[0x58] - *(int *)(param_1 + 0x478), -1 < iVar12 && (1 < iVar12)))) ||
             (((iVar6 != piVar7[0x56] ||
               (iVar12 = (**(code **)(*piVar7 + 0x28))(piVar7), iVar12 != 0)) || (piVar7[0x21] == 0)
              ))) {
            piVar8 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
            FUN_00106004(piVar8,1,piVar7,0,*(undefined4 *)(param_1 + 8));
            (**(code **)(*piVar8 + 0x94))
                      (piVar8,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
            FUN_0010469c(piVar8,param_1,6,0);
            piVar8[0x27] = iVar4;
            FUN_000e7700(iVar6,piVar5,piVar8);
            goto code_r0x000e76c4;
          }
          (**(code **)(*piVar7 + 0x94))
                    (piVar7,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
          FUN_0010469c(piVar7,param_1,6,0);
          iVar12 = FUN_001054ec(piVar7,0);
          FUN_000f302c(&local_40,iVar4,*(undefined4 *)(iVar12 + 0x10));
          uVar2 = piVar7[5];
          piVar5 = piVar7;
          iVar4 = local_40;
        } while( true );
      }
      FUN_000e8424(iVar4,*(undefined4 *)(param_1 + 0x340));
      uVar11 = *(undefined4 *)(param_1 + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*param_2 + 0x94);
      uVar14 = *(undefined4 *)(param_1 + 0x340);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x340) + 300) = 1;
      piVar5 = (int *)FUN_00105594(param_2,1);
      piVar7 = (int *)FUN_00105594(param_3,1);
      if ((((piVar5[0x56] == piVar7[0x56]) &&
           (iVar6 = (**(code **)(*piVar5 + 0x7c))(piVar5), iVar6 == 0)) &&
          (iVar6 = (**(code **)(*piVar7 + 0x7c))(piVar7), iVar6 == 0)) &&
         ((piVar5[0x21] != 0 && (piVar7[0x21] != 0)))) {
        uVar2 = (uint)(1 < *(int *)(param_1 + 0x478));
        if (((((int)(piVar5[0x58] - uVar2) < 0) || (piVar5[0x58] == uVar2)) &&
            (((iVar6 = piVar7[0x58] - *(int *)(param_1 + 0x478), iVar6 < 0 || (iVar6 < 2)) &&
             (iVar6 = (**(code **)(*piVar5 + 0x28))(piVar5), iVar6 == 0)))) &&
           (iVar6 = (**(code **)(*piVar7 + 0x28))(piVar7), iVar6 == 0)) {
          iVar6 = piVar5[0x56];
          iVar4 = FUN_001054ec(param_2,0);
          uVar13 = *(undefined4 *)(iVar4 + 0x10);
          uVar14 = 6;
          iVar4 = FUN_001054ec(param_3,0);
          uVar11 = *(undefined4 *)(iVar4 + 0x10);
          ((int (*)())FUN_000ef970)(param_1,param_3);
          iVar12 = 0;
          ((int (*)())FUN_000ef970)(param_1,param_2);
          (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_1 + 8));
          (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
          FUN_000e76c4(iVar6,*(undefined4 *)(param_1 + 0x340));
          iVar4 = FUN_001054ec(piVar5,0);
          FUN_000f302c(&local_3c,uVar13,*(undefined4 *)(iVar4 + 0x10));
          do {
            (**(code **)(*piVar5 + 0x94))
                      (piVar5,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
            FUN_0010469c(piVar5,param_1,uVar14,0);
            uVar2 = piVar5[5];
            iVar4 = local_3c;
            while ((uVar2 & 0x200) != 0) {
              piVar8 = (int *)FUN_00105594(piVar5,piVar5[0x21]);
              iVar9 = (**(code **)(*piVar8 + 0x7c))();
              if ((((iVar9 != 0) ||
                   (iVar9 = FUN_0011379c(*(undefined4 *)(param_1 + 8),piVar8), iVar9 == 0)) ||
                  ((iVar9 = piVar8[0x58] - *(int *)(param_1 + 0x478), -1 < iVar9 && (1 < iVar9))))
                 || (((iVar6 != piVar8[0x56] ||
                      (iVar9 = (**(code **)(*piVar8 + 0x28))(piVar8), iVar9 != 0)) ||
                     (piVar8[0x21] == 0)))) {
                piVar10 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
                FUN_00106004(piVar10,1,piVar8,0,*(undefined4 *)(param_1 + 8));
                FUN_0010469c(piVar10,param_1,uVar14,0);
                (**(code **)(*piVar10 + 0x94))
                          (piVar10,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
                piVar10[0x27] = iVar4;
                FUN_000e7700(iVar6,piVar5,piVar10);
                break;
              }
              (**(code **)(*piVar8 + 0x94))
                        (piVar8,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
              FUN_0010469c(piVar8,param_1,uVar14,0);
              iVar9 = FUN_001054ec(piVar8,0);
              FUN_000f302c(local_38,iVar4,*(undefined4 *)(iVar9 + 0x10));
              iVar4 = local_38[0];
              piVar5 = piVar8;
              uVar2 = piVar8[5];
            }
            iVar4 = FUN_001054ec(piVar7,0);
            uVar14 = 7;
            FUN_000f302c(&local_48,uVar11,*(undefined4 *)(iVar4 + 0x10));
            bVar1 = iVar12 == 1;
            iVar12 = iVar12 + 1;
            local_3c = local_48;
            piVar5 = piVar7;
            if (bVar1) {
              return;
            }
          } while( true );
        }
      }
      FUN_000e8424(iVar4,*(undefined4 *)(param_1 + 0x340));
      (**(code **)(*param_2 + 0x94))
                (param_2,*(undefined4 *)(param_1 + 0x340),*(undefined4 *)(param_1 + 8));
      uVar11 = *(undefined4 *)(param_1 + 8);
      UNRECOVERED_JUMPTABLE = *(code **)(*param_3 + 0x94);
      uVar14 = *(undefined4 *)(param_1 + 0x340);
      param_2 = param_3;
    }
LAB_000f1940:
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_2,uVar14,uVar11);
    return;
  }
  return;
}

/* FUN_000f1d7c @ 0xf1d7c (3008 bytes) */
int FUN_000f1d7c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  char local_8c;
  char cStack_8b;
  char cStack_8a;
  char cStack_89;
  uint local_88;
  uint local_84;
  int local_80;
  undefined4 local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  int local_38 [2];
  
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  local_4c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_54 = 0;
  local_58 = 2;
  iVar11 = param_3[0x26];
  iVar10 = param_3[0x25];
  local_50 = FUN_00193e18(local_4c,8);
  local_7c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_84 = 0;
  local_88 = 2;
  local_80 = FUN_00193e18(local_7c,8);
  local_6c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_74 = 0;
  local_78 = 2;
  local_70 = FUN_00193e18(local_6c,8);
  local_5c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_64 = 0;
  local_68 = 2;
  local_60 = FUN_00193e18(local_5c,8);
  uVar8 = local_54;
  if (local_54 < local_58) {
    iVar4 = local_54 * 4;
    _memset(iVar4 + local_50,0,4);
    local_54 = uVar8 + 1;
    puVar2 = (undefined4 *)(iVar4 + local_50);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(&local_58,local_54);
  }
  uVar8 = local_84;
  *puVar2 = param_3;
  if (local_84 < local_88) {
    iVar4 = local_84 * 4;
    _memset(iVar4 + local_80,0,4);
    local_84 = uVar8 + 1;
    puVar2 = (undefined4 *)(iVar4 + local_80);
  }
  else {
    puVar2 = (undefined4 *)FUN_0019423c(&local_88,local_84);
  }
  *puVar2 = 1;
  piVar3 = (int *)FUN_00105594(param_3,1);
  bVar1 = true;
  uVar8 = local_54;
LAB_000f26b0:
  do {
    while( true ) {
      if (uVar8 == 0) {
        iVar4 = FUN_001054ec(param_3,0);
        FUN_000f3908(&local_40,*(undefined4 *)(iVar4 + 0x10));
        while (local_74 != 0) {
          uVar8 = local_74 - 1;
          puVar2 = (undefined4 *)0x0;
          if (uVar8 < local_74) {
            puVar2 = (undefined4 *)(uVar8 * 4 + local_70);
          }
          piVar12 = (int *)*puVar2;
          FUN_00194208(&local_78,uVar8);
          piVar3 = (int *)0x0;
          uVar8 = local_64 - 1;
          if (uVar8 < local_64) {
            piVar3 = (int *)(uVar8 * 4 + local_60);
          }
          iVar4 = *piVar3;
          FUN_00194208(&local_68,uVar8);
          piVar3 = (int *)FUN_00105594(piVar12,iVar4);
          if ((piVar3[0x26] != iVar11) && (iVar5 = (**(code **)(*piVar3 + 0x50))(), iVar5 == 0)) {
            uVar8 = piVar3[3];
            iVar5 = FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
            FUN_00106004(iVar5,1,piVar3,0,*(undefined4 *)(param_1 + 8));
            FUN_0010469c(iVar5,param_1,iVar11,iVar10);
            FUN_000f31f8(&local_3c,DAT_001aa800,local_40 & uVar8);
            *(undefined4 *)(iVar5 + 0x9c) = local_3c;
            FUN_000f4698(iVar5,1,param_1);
            iVar6 = FUN_001055cc(piVar12);
            if (iVar6 == 0) {
              iVar6 = (**(code **)(*piVar12 + 0x7c))(piVar12);
              if (iVar6 == 0) {
                FUN_00106004(piVar12,iVar4,iVar5,0,*(undefined4 *)(param_1 + 8));
                FUN_000e7700(piVar12[0x56],piVar12,iVar5);
              }
              else {
                FUN_00106004(piVar12,iVar4,iVar5,0,*(undefined4 *)(param_1 + 8));
                uVar7 = FUN_000e9184(piVar12[0x56],iVar4 + -1);
                FUN_000e7688(uVar7,iVar5);
              }
            }
            else {
              FUN_00106804(piVar12,iVar5,0,*(undefined4 *)(param_1 + 8));
              FUN_000e7738(piVar3[0x56],piVar3,iVar5);
            }
          }
        }
        iVar10 = FUN_00105594(param_3,1);
        uVar8 = local_40 & *(uint *)(iVar10 + 0xc);
        FUN_000f31f8(local_38,DAT_001aa800,uVar8);
        param_3[0x27] = local_38[0];
        FUN_000f4698(param_3,1,param_1);
        cStack_89 = (char)uVar8;
        cStack_8a = (char)(uVar8 >> 8);
        cStack_8b = (char)(uVar8 >> 0x10);
        local_8c = (char)(uVar8 >> 0x18);
        if (((cStack_89 == '\0' && cStack_8a == '\0') && cStack_8b == '\0') && local_8c == '\0') {
          (**(code **)(*param_3 + 0xc))(param_3,0,*(undefined4 *)(param_1 + 8));
        }
        else {
          ((int (*)())FUN_000f07a8)(param_1,param_2,param_3);
        }
        FUN_00193cc0(local_5c,local_60);
        FUN_00193cc0(local_6c,local_70);
        FUN_00193cc0(local_7c,local_80);
        FUN_00193cc0(local_4c,local_50);
        return;
      }
      if (!bVar1) break;
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
        bVar1 = false;
      }
      else if (*(int *)(param_1 + 0x474) == piVar3[0x54]) {
LAB_000f26a4:
        bVar1 = false;
      }
      else {
        piVar3[0x54] = *(int *)(param_1 + 0x474);
        iVar4 = FUN_001054ec(piVar3,0);
        FUN_000f3908(&local_48,*(undefined4 *)(iVar4 + 0x10));
        piVar3[3] = local_48;
        iVar4 = (**(code **)(*piVar3 + 0x7c))(piVar3);
        uVar8 = local_54;
        if (iVar4 == 0) {
          iVar4 = FUN_00104fd0(piVar3);
          uVar8 = local_54;
          if (iVar4 == 0) {
            if ((piVar3[5] & 0x200U) == 0) goto LAB_000f26a4;
            if (local_54 < local_58) {
              iVar4 = local_54 * 4;
              _memset(iVar4 + local_50,0,4);
              local_54 = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + local_50);
            }
            else {
              puVar2 = (undefined4 *)FUN_0019423c(&local_58,local_54);
            }
            uVar8 = local_84;
            *puVar2 = piVar3;
            iVar4 = piVar3[0x21];
            if (local_84 < local_88) {
              iVar5 = local_84 * 4;
              _memset(iVar5 + local_80,0,4);
              local_84 = uVar8 + 1;
              piVar12 = (int *)(iVar5 + local_80);
            }
            else {
              piVar12 = (int *)FUN_0019423c(&local_88,local_84);
            }
            *piVar12 = iVar4;
            piVar3 = (int *)FUN_00105594(piVar3,piVar3[0x21]);
          }
          else {
            if (local_54 < local_58) {
              iVar4 = local_54 * 4;
              _memset(iVar4 + local_50,0,4);
              local_54 = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + local_50);
            }
            else {
              puVar2 = (undefined4 *)FUN_0019423c(&local_58,local_54);
            }
            uVar8 = local_84;
            *puVar2 = piVar3;
            if (local_84 < local_88) {
              iVar4 = local_84 * 4;
              _memset(iVar4 + local_80,0,4);
              local_84 = uVar8 + 1;
              puVar2 = (undefined4 *)(iVar4 + local_80);
            }
            else {
              puVar2 = (undefined4 *)FUN_0019423c(&local_88,local_84);
            }
            *puVar2 = 2;
            piVar3 = (int *)FUN_00105594(piVar3,2);
          }
        }
        else {
          if (local_54 < local_58) {
            iVar4 = local_54 * 4;
            _memset(iVar4 + local_50,0,4);
            local_54 = uVar8 + 1;
            puVar2 = (undefined4 *)(iVar4 + local_50);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(&local_58,local_54);
          }
          uVar8 = local_84;
          *puVar2 = piVar3;
          if (local_84 < local_88) {
            iVar4 = local_84 * 4;
            _memset(iVar4 + local_80,0,4);
            local_84 = uVar8 + 1;
            puVar2 = (undefined4 *)(iVar4 + local_80);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(&local_88,local_84);
          }
          *puVar2 = 1;
          piVar3 = (int *)FUN_00105594(piVar3,1);
        }
LAB_000f2690:
        bVar1 = true;
        uVar8 = local_54;
      }
    }
    uVar9 = uVar8 - 1;
    puVar2 = (undefined4 *)0x0;
    if (uVar9 < uVar8) {
      puVar2 = (undefined4 *)(uVar9 * 4 + local_50);
    }
    bVar1 = piVar3 != (int *)0x0;
    piVar3 = (int *)*puVar2;
    if (bVar1) {
      piVar12 = (int *)0x0;
      uVar8 = local_84 - 1;
      if (uVar8 < local_84) {
        piVar12 = (int *)(uVar8 * 4 + local_80);
      }
      if (*piVar12 != piVar3[0x21]) {
        piVar12 = (int *)0x0;
        if (uVar8 < local_84) {
          piVar12 = (int *)(uVar8 * 4 + local_80);
        }
        iVar4 = *piVar12;
        FUN_00194208(&local_88,uVar8);
        uVar8 = local_84;
        if (local_84 < local_88) {
          iVar5 = local_84 * 4;
          _memset(iVar5 + local_80,0,4);
          local_84 = uVar8 + 1;
          piVar12 = (int *)(iVar5 + local_80);
        }
        else {
          piVar12 = (int *)FUN_0019423c(&local_88,local_84);
        }
        *piVar12 = iVar4 + 1;
        piVar3 = (int *)FUN_00105594(piVar3,iVar4 + 1);
        goto LAB_000f2690;
      }
    }
    FUN_00194208(&local_58,uVar9);
    FUN_00194208(&local_88,local_84 - 1);
    iVar4 = FUN_001054ec(piVar3,0);
    FUN_000f3908(&local_44,*(undefined4 *)(iVar4 + 0x10));
    uVar8 = local_44;
    iVar4 = FUN_001055cc(piVar3);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*piVar3 + 0x7c))(piVar3);
      if (iVar4 == 0) {
        iVar4 = FUN_00104fd0(piVar3);
        if (iVar4 != 0) {
          iVar4 = FUN_00105594(piVar3,2);
          iVar5 = FUN_00105594(piVar3,3);
          uVar9 = ~*(uint *)(iVar4 + 0xc);
          if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18)
              ) == 0) {
            uVar9 = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
                         uVar9 >> 0x18)) == 0) goto LAB_000f25ac;
            FUN_0010c010(piVar3,3,*(undefined4 *)(param_1 + 8));
          }
          else {
            FUN_0010c010(piVar3,2,*(undefined4 *)(param_1 + 8));
          }
          FUN_0010469c(piVar3,param_1,iVar11,iVar10);
          uVar9 = local_74;
          if (local_74 < local_78) {
            iVar4 = local_74 * 4;
            _memset(iVar4 + local_70,0,4);
            local_74 = uVar9 + 1;
            puVar2 = (undefined4 *)(iVar4 + local_70);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(&local_78,local_74);
          }
          uVar9 = local_64;
          *puVar2 = piVar3;
          if (local_64 < local_68) {
            iVar4 = local_64 * 4;
            _memset(iVar4 + local_60,0,4);
            local_64 = uVar9 + 1;
            puVar2 = (undefined4 *)(iVar4 + local_60);
          }
          else {
            puVar2 = (undefined4 *)FUN_0019423c(&local_68,local_64);
          }
          *puVar2 = 3;
          piVar3[3] = 0;
        }
LAB_000f25ac:
        if ((piVar3[5] & 0x200U) != 0) {
          iVar4 = FUN_00105594(piVar3,piVar3[0x21]);
          piVar3[3] = uVar8 | *(uint *)(iVar4 + 0xc);
          if (*(int *)(iVar4 + 0x98) == iVar11) {
            FUN_00106004(piVar3,piVar3[0x21],0,0,*(undefined4 *)(param_1 + 8));
            piVar3[0x21] = piVar3[0x21] + -1;
            piVar3[5] = piVar3[5] & 0xfffffdff;
          }
        }
      }
      else {
        iVar4 = 1;
        if (0 < piVar3[0x21]) {
          do {
            iVar5 = FUN_00105594(piVar3,iVar4);
            uVar9 = ~*(uint *)(iVar5 + 0xc);
            if ((uVar8 & (uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 |
                         uVar9 >> 0x18)) != 0) {
              FUN_0010469c(piVar3,param_1,iVar11,iVar10);
              piVar3[3] = 0;
              if (0 < piVar3[0x21]) {
                iVar4 = 1;
                do {
                  iVar5 = FUN_00105594(piVar3,iVar4);
                  uVar9 = local_74;
                  if ((uVar8 & *(uint *)(iVar5 + 0xc)) != 0) {
                    if (local_74 < local_78) {
                      iVar5 = local_74 * 4;
                      _memset(iVar5 + local_70,0,4);
                      local_74 = uVar9 + 1;
                      puVar2 = (undefined4 *)(iVar5 + local_70);
                    }
                    else {
                      puVar2 = (undefined4 *)FUN_0019423c(&local_78,local_74);
                    }
                    uVar9 = local_64;
                    *puVar2 = piVar3;
                    if (local_64 < local_68) {
                      iVar5 = local_64 * 4;
                      _memset(iVar5 + local_60,0,4);
                      local_64 = uVar9 + 1;
                      piVar12 = (int *)(iVar5 + local_60);
                    }
                    else {
                      piVar12 = (int *)FUN_0019423c(&local_68,local_64);
                    }
                    *piVar12 = iVar4;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar4 <= piVar3[0x21]);
              }
              break;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 <= piVar3[0x21]);
        }
      }
LAB_000f260c:
      bVar1 = false;
      uVar8 = local_54;
      goto LAB_000f26b0;
    }
    FUN_0010469c(piVar3,param_1,iVar11,iVar10);
    iVar4 = FUN_00105594(piVar3,piVar3[0x21]);
    uVar9 = local_74;
    piVar3[3] = 0;
    if ((uVar8 & *(uint *)(iVar4 + 0xc)) == 0) goto LAB_000f260c;
    if (local_74 < local_78) {
      iVar4 = local_74 * 4;
      _memset(iVar4 + local_70,0,4);
      local_74 = uVar9 + 1;
      puVar2 = (undefined4 *)(iVar4 + local_70);
    }
    else {
      puVar2 = (undefined4 *)FUN_0019423c(&local_78,local_74);
    }
    uVar8 = local_64;
    *puVar2 = piVar3;
    iVar4 = piVar3[0x21];
    if (local_64 < local_68) {
      iVar5 = local_64 * 4;
      _memset(iVar5 + local_60,0,4);
      local_64 = uVar8 + 1;
      piVar12 = (int *)(iVar5 + local_60);
    }
    else {
      piVar12 = (int *)FUN_0019423c(&local_68,local_64);
    }
    *piVar12 = iVar4;
    bVar1 = false;
    uVar8 = local_54;
  } while( true );
}

/* FUN_000f29f4 @ 0xf29f4 (488 bytes) */
int FUN_000f29f4(param_1)
  int param_1;
{
  int iVar1;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  
  FUN_0010ea30(param_1);
  ((int (*)())FUN_000ed7e4)(param_1,"assign_slots");
  iVar2 = **(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar1 = (**(code **)(iVar2 + 0xd8))();
  if (iVar1 == 0) {
    ((int (*)())FUN_000eced0)(param_1);
    piVar8 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
    for (piVar9 = (int *)piVar8[2]; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
      iVar1 = (**(code **)(*piVar8 + 0x68))(piVar8);
      if (iVar1 != 0) {
        if (piVar8[0x51] == 0) {
          ((int (*)())FUN_000f07a8)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar8);
        }
        else {
          ((int (*)())FUN_000f1d7c)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar8);
        }
      }
      piVar8 = piVar9;
    }
  }
  else {
    ((int (*)())FUN_000ec920)(param_1);
    ((int (*)())FUN_000efde4)(param_1,extraout_r4,in_r5,in_r6,in_r7,in_r8,iVar2);
    piVar9 = *(int **)(*(int *)(param_1 + 0x3a8) + 0x98);
    piVar8 = (int *)piVar9[2];
    if (piVar8 == (int *)0x0) {
      piVar6 = (int *)0x0;
      piVar4 = (int *)0x0;
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      piVar3 = (int *)0x0;
      piVar5 = (int *)0x0;
      do {
        piVar7 = piVar8;
        iVar2 = (**(code **)(*piVar9 + 0x68))(piVar9);
        piVar4 = piVar3;
        piVar6 = piVar5;
        if (((iVar2 != 0) && (piVar6 = piVar9, piVar9[0x4f] != 6)) &&
           (piVar4 = piVar9, piVar6 = piVar5, piVar9[0x4f] != 7)) {
          iVar1 = iVar1 + 1;
          ((int (*)())FUN_000f07a8)(param_1,*(undefined4 *)(param_1 + 0x33c),piVar9);
          piVar4 = piVar3;
        }
        piVar8 = (int *)piVar7[2];
        piVar3 = piVar4;
        piVar5 = piVar6;
        piVar9 = piVar7;
      } while (piVar8 != (int *)0x0);
    }
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = iVar1 + -1;
    }
    *(int *)(*(int *)(param_1 + 0x33c) + 300) = iVar2;
    if (piVar6 != (int *)0x0) {
      ((int (*)())FUN_000f14f8)(param_1,piVar6,piVar4);
    }
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x800;
  ((int (*)())FUN_000ec1ec)(param_1);
  ((int (*)())FUN_000ed7e4)(param_1,"mark_io");
  return;
}

/* FUN_000f2bdc @ 0xf2bdc (128 bytes) */
int FUN_000f2bdc(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined4 uStack0000001c;
  byte bStack00000020;
  byte bStack00000021;
  byte bStack00000022;
  
  uStack0000001c = param_2;
  (*(unsigned char *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)) = param_3;
  bStack00000022 = (byte)(param_3 >> 8);
  bStack00000021 = (byte)(param_3 >> 0x10);
  bStack00000020 = (byte)(param_3 >> 0x18);
  *param_1 = (uint)bStack00000020 << 0x18 | (uint)bStack00000021 << 0x10 | (uint)bStack00000022 << 8
             | param_3 & 0xff;
  if (bStack00000020 < 4) {
    *(undefined1 *)param_1 = *(undefined1 *)((int)&STACKARG(0x1c) + (uint)bStack00000020);
  }
  if (bStack00000021 < 4) {
    *(undefined1 *)((int)param_1 + 1) =
         *(undefined1 *)((int)&STACKARG(0x1c) + (uint)bStack00000021);
  }
  if (bStack00000022 < 4) {
    *(undefined1 *)((int)param_1 + 2) =
         *(undefined1 *)((int)&STACKARG(0x1c) + (uint)bStack00000022);
  }
  if (3 < (param_3 & 0xff)) {
    return;
  }
  *(undefined1 *)((int)param_1 + 3) = *(undefined1 *)((int)&STACKARG(0x1c) + (param_3 & 0xff));
  return;
}

/* FUN_000f2c5c @ 0xf2c5c (80 bytes) */
int FUN_000f2c5c(param_1)
  undefined4 param_1;
{
  char cVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uStack00000018;
  
  uStack00000018 = param_1;
  iVar5 = 4;
  pcVar2 = (char *)&STACKARG(0x18);
  cVar3 = '\x04';
  while (((cVar1 = *pcVar2, cVar4 = cVar3, cVar1 == '\x04' || (cVar4 = cVar1, cVar3 == '\x04')) ||
         (cVar4 = cVar3, cVar1 == cVar3))) {
    pcVar2 = pcVar2 + 1;
    iVar5 = iVar5 + -1;
    cVar3 = cVar4;
    if (iVar5 == 0) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000f2cac @ 0xf2cac (92 bytes) */
int FUN_000f2cac(param_1)
  undefined4 param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack00000018;
  
  uStack00000018 = param_1;
  ((int (*)())FUN_000f2c5c)(param_1);
  iVar3 = 4;
  iVar2 = 0;
  pcVar1 = (char *)&STACKARG(0x18);
  do {
    if (*pcVar1 != '\x04') {
      return (uint)*(byte *)((int)&STACKARG(0x18) + iVar2);
    }
    iVar2 = iVar2 + 1;
    pcVar1 = pcVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0xffffffff;
}

/* FUN_000f2d08 @ 0xf2d08 (16 bytes) */
int FUN_000f2d08(param_1)
  uint param_1;
{
  return param_1 < 4;
}

