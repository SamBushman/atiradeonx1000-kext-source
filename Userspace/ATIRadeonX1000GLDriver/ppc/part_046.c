#include "decls.h"

/* FUN_001733a0 @ 0x1733a0 (156 bytes) */
int FUN_001733a0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00112f78(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(param_1 + 0x238));
  if (iVar1 != 0) {
    iVar3 = 4;
    iVar1 = param_1;
    iVar2 = param_1;
    do {
      if (*(char *)(iVar2 + 0x228) != '\0') {
        if (*(int *)(iVar1 + 0x178) < *(int *)(iVar1 + 0x188)) {
          return 0;
        }
        if (*(int *)(iVar1 + 0x188) < *(int *)(iVar1 + 0x178)) {
          FUN_00172a90(*(undefined4 *)(param_1 + 0xb0),param_1 + 0x210,
                       *(undefined4 *)(param_1 + 0x238));
          return 1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}

/* FUN_0017343c @ 0x17343c (304 bytes) */
int FUN_0017343c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  piVar3 = *(int **)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar1 = (**(code **)(*piVar3 + 0x18))(piVar3);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0xb0);
    uVar4 = piVar3[7];
    iVar1 = *(int *)(param_2 + 0x128);
    if ((((*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x12) && (*(int *)(iVar2 + 0x120) == 0)) &&
        ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) &&
       (((*(uint *)(iVar2 + 0xb8) & 1) != 0 && ((*(uint *)(iVar2 + 0xd0) & 1) == 0)))) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
      *(int *)(iVar2 + 0xa8) = *(int *)(iVar2 + 0xa8) + 1;
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xa4,1,0);
      FUN_00103d50(*(int *)(param_1 + 0xb0) + 0xbc,1,1);
      iVar1 = (uVar4 >> 3 & 0x1ffffffc) + iVar1;
      *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) | 0x200000;
      *(uint *)(iVar1 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar1 + 8);
      return;
    }
    iVar1 = (uVar4 >> 3 & 0x1ffffffc) + iVar1;
    *(uint *)(iVar1 + 8) =
         (-2 << (uVar4 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar4 & 0x1f)) & *(uint *)(iVar1 + 8);
  }
  return;
}

/* FUN_0017356c @ 0x17356c (176 bytes) */
int FUN_0017356c(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00113174(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(param_1 + 0x238));
  if (iVar1 == 0) {
    iVar2 = 1;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))();
    if (iVar1 != 0) {
      while( true ) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))();
        if (iVar1 < iVar2) {
          return 1;
        }
        iVar1 = ((int (*)())FUN_001763e4)(param_1,iVar2);
        if (iVar1 == 0) break;
        iVar2 = iVar2 + 1;
      }
    }
  }
  return 0;
}

/* FUN_0017361c @ 0x17361c (28 bytes) */
int FUN_0017361c(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x24U < 3;
}

/* FUN_00173638 @ 0x173638 (284 bytes) */
int FUN_00173638(param_1)
  int param_1;
{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x77) {
    iVar2 = FUN_001054ec(iVar2,0);
    if (*(int *)(iVar2 + 0x10) == DAT_001b01b4) {
      *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) =
           *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) & 0xfffffff7;
      piVar3 = *(int **)(param_1 + 0xb0);
      iVar2 = *(int *)(param_1 + 0x238);
      pcVar1 = *(code **)(*piVar3 + 0xc);
      goto LAB_00173718;
    }
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  if ((((*(uint *)(iVar2 + 0x14) & 2) == 0) || (*(int *)(iVar2 + 0x98) != 0x3b)) ||
     (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x334) != 0)) {
    return 0;
  }
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffef;
  iVar2 = *(int *)(param_1 + 0x238);
  if ((*(uint *)(*(int *)(iVar2 + 0x6c4) + 0x30) & 0x4000) == 0) {
    FUN_000ef970(*(int *)(iVar2 + 0x6c4),*(undefined4 *)(param_1 + 0xb0));
    iVar2 = *(int *)(param_1 + 0x238);
  }
  piVar3 = *(int **)(param_1 + 0xb0);
  pcVar1 = *(code **)(*piVar3 + 0xc);
LAB_00173718:
  (*pcVar1)(piVar3,0,iVar2);
  *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) = *(uint *)(*(int *)(param_1 + 0xb0) + 0x14) | 0x400;
  return 1;
}

/* FUN_00173754 @ 0x173754 (280 bytes) */
int FUN_00173754(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_28;
  undefined4 local_24 [6];
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),9);
  if (((iVar1 == 0) ||
      (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
       *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8))) ||
     (iVar1 = *(int *)(param_2 + 0xb0), (*(uint *)(iVar1 + 0x14) & 1) == 0)) {
LAB_00173854:
    uVar4 = 0;
  }
  else {
    iVar2 = FUN_001054ec(iVar1,0);
    local_28 = *(undefined4 *)(iVar2 + 0x10);
    iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    iVar2 = 0;
    local_24[0] = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if ((*(char *)((int)local_24 + iVar2) == '\0') &&
         (*(char *)((int)local_24 + iVar2 + -4) == '\x01')) goto LAB_00173854;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar2 + 0xa8) = *(int *)(iVar2 + 0xa8) + 1;
    iVar2 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar2 + 0x140) = *(int *)(iVar2 + 0x140) + 1;
    FUN_0017d06c(param_1,iVar1,&DAT_001b01bc,0);
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_0017386c @ 0x17386c (204 bytes) */
int FUN_0017386c(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_28 [4];
  
  piVar1 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar1[0x22] + 8) == 0x8e) {
    uVar2 = (**(code **)(*piVar1 + 0x7c))();
    iVar3 = FUN_0011e780(uVar2);
    if (iVar3 == 0) {
      return;
    }
    piVar1 = *(int **)(param_1 + 0xb0);
  }
  iVar3 = 1;
  iVar6 = param_1;
  while( true ) {
    iVar4 = (**(code **)(*piVar1 + 0x14))();
    if (iVar4 < iVar3) break;
    uVar2 = *(undefined4 *)(param_1 + 0xb0);
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4);
    iVar4 = FUN_001054ec(uVar2,0);
    FUN_000f3c30(local_28,uVar2,iVar3,uVar5,*(undefined4 *)(iVar4 + 0x10));
    piVar1 = *(int **)(param_1 + 0xb0);
    *(undefined4 *)(iVar6 + 0x228) = local_28[0];
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 4;
  }
  return;
}

/* FUN_00173938 @ 0x173938 (136 bytes) */
int FUN_00173938(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 4;
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  puVar1 = param_1;
  do {
    puVar1[8] = 0;
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1[0x1c] = 0;
    puVar1[0x18] = 0;
    puVar1[0x14] = 0;
    puVar1[0x28] = 0;
    puVar1[0x24] = 0;
    puVar1[0x20] = 0;
    puVar1[0xc] = 0;
    puVar1[0x10] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  ((int (*)())FUN_0017386c)(param_1);
  return;
}

/* FUN_001739c0 @ 0x1739c0 (136 bytes) */
int FUN_001739c0(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 4;
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  puVar1 = param_1;
  do {
    puVar1[8] = 0;
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1[0x1c] = 0;
    puVar1[0x18] = 0;
    puVar1[0x14] = 0;
    puVar1[0x28] = 0;
    puVar1[0x24] = 0;
    puVar1[0x20] = 0;
    puVar1[0xc] = 0;
    puVar1[0x10] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  ((int (*)())FUN_0017386c)(param_1);
  return;
}

/* FUN_00173a48 @ 0x173a48 (176 bytes) */
int FUN_00173a48(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00113174(*(undefined4 *)(param_1[0x22] + 8),param_2);
  if (iVar1 == 0) {
    iVar2 = 1;
    iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar1 != 0) {
      while( true ) {
        iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
        if (iVar1 < iVar2) {
          return 1;
        }
        iVar1 = FUN_001054ec(param_1,iVar2);
        iVar1 = FUN_000f2c5c(*(undefined4 *)(iVar1 + 0x10));
        if (iVar1 == 0) break;
        iVar2 = iVar2 + 1;
      }
    }
  }
  return 0;
}

/* FUN_00173af8 @ 0x173af8 (160 bytes) */
int FUN_00173af8(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_38 [9];
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x120) != 0) &&
     (iVar2 = FUN_0011379c(*(undefined4 *)(param_1 + 0x238),*(int *)(param_1 + 0xb0)), iVar2 != 0))
  {
    iVar2 = 0;
    do {
      iVar3 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      local_38[0] = *(undefined4 *)(iVar3 + 0x10);
      if ((*(char *)((int)local_38 + iVar2) == '\0') && (*param_2 != 0)) {
        return;
      }
      bVar1 = iVar2 != 3;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
  }
  return;
}

/* FUN_00173b98 @ 0x173b98 (324 bytes) */
int FUN_00173b98(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_2[0x22] + 8) == 0x8e) {
    FUN_000e9c00(param_3,param_2[0x23],param_1);
    (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_4 + 8));
    uVar1 = 1;
    param_2[5] = param_2[5] | 0x400;
    *(int *)(param_4 + 0x150) = *(int *)(param_4 + 0x150) + 1;
  }
  else if (((param_2[5] & 8U) == 0) && ((param_2[5] & 0x10U) == 0)) {
    if ((((param_2[0x20] != 0) && (iVar2 = FUN_00126760(param_2[0x26]), iVar2 != 0)) &&
        ((param_2[5] & 2U) == 0)) && (iVar2 = (**(code **)(*param_2 + 0x50))(param_2), iVar2 == 0))
    {
      FUN_000e9c00(param_3,param_2[0x23],param_1);
    }
    (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_4 + 8));
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
int FUN_00173cdc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 local_38 [4];
  undefined4 local_28 [4];
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),8);
  if ((iVar1 == 0) ||
     (*(int *)(*(int *)(param_1 + 0x238) + 0x658) <=
      *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0xa8))) {
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xb0);
    if ((*(uint *)(iVar1 + 0x14) & 1) == 0) {
      puVar7 = *(uint **)(*(int *)(iVar1 + 0x8c) + 0x2c);
      uVar5 = puVar7[1];
      uVar6 = uVar5 - 1;
      if (uVar6 < *puVar7) {
        if (uVar5 <= uVar6) {
          _memset((void *)(uVar5 * 4 + puVar7[2]),0,(uVar6 - uVar5) * 4 + 4);
          puVar7[1] = uVar5;
        }
        piVar2 = (int *)(uVar6 * 4 + puVar7[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar7,uVar6);
      }
      iVar1 = *(int *)(*piVar2 + 0xb0);
    }
    FUN_00173164(local_28,param_1,param_2);
    local_38[0] = local_28[0];
    iVar4 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0xa8) = *(int *)(iVar4 + 0xa8) + 1;
    iVar4 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
    *(int *)(iVar4 + 0x13c) = *(int *)(iVar4 + 0x13c) + 1;
    FUN_0017d06c(param_1,iVar1,local_38,0);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00173e10 @ 0x173e10 (268 bytes) */
int FUN_00173e10(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4) = 0;
  **(undefined4 **)(param_1 + 0x3f0) = param_2;
  puVar1 = (undefined4 *)
           FUN_00194834(*(undefined4 *)(param_1 + 0x3e4),*(undefined4 *)(param_1 + 0x3f0));
  if (puVar1 == (undefined4 *)0x0) {
    uVar5 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x2c);
    puVar1 = puVar2 + 1;
    *puVar2 = uVar5;
    puVar2[1] = param_2;
    puVar2[5] = 4;
    puVar2[8] = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 0xd) = 0;
    puVar2[4] = 0;
    puVar2[7] = 0;
    uVar5 = FUN_00172ee8(param_1);
    puVar2[2] = uVar5;
    FUN_00194d44(*(undefined4 *)(param_1 + 0x3e4),puVar1);
    FUN_00194d44(*(undefined4 *)(param_1 + 0x3e0),puVar1);
    puVar6 = *(uint **)(param_1 + 0x3d8);
    uVar4 = puVar6[1];
    if (uVar4 < *puVar6) {
      _memset((void *)(uVar4 * 4 + puVar6[2]),0,4);
      piVar3 = (int *)(uVar4 * 4 + puVar6[2]);
      puVar6[1] = uVar4 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar4);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00173f1c @ 0x173f1c (1680 bytes) */
int FUN_00173f1c(param_1)
  int param_1;
{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  uint *puVar14;
  char *pcVar15;
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  piVar12 = *(int **)(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(piVar12[0x22] + 8);
  if (piVar12[0x20] != 0) {
    iVar3 = FUN_00126760(piVar12[0x26]);
    if (((iVar3 == 0) || ((piVar12[5] & 2U) != 0)) ||
       (iVar3 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar3 != 0)) {
      piVar12 = *(int **)(param_1 + 0xb0);
    }
    else {
      piVar12 = *(int **)(param_1 + 0xb0);
      if ((piVar12[5] & 0x40U) == 0) {
        *(undefined4 *)(param_1 + 0xb8) = 0;
        *(undefined4 *)(param_1 + 0xbc) = 0;
        goto LAB_00173fa0;
      }
    }
    *(int *)(param_1 + 0xbc) = piVar12[0x25];
    *(int *)(param_1 + 0xb8) = piVar12[0x26];
  }
LAB_00173fa0:
  *(int *)(param_1 + 0xc0) = piVar12[0x48];
  *(int *)(param_1 + 0xc4) = piVar12[0x49];
  iVar3 = 1;
  iVar10 = param_1;
  while( true ) {
    iVar5 = (**(code **)(*piVar12 + 0x14))(piVar12);
    if (iVar5 < iVar3) break;
    uVar4 = FUN_00105c5c(*(undefined4 *)(param_1 + 0xb0),iVar3);
    piVar12 = *(int **)(param_1 + 0xb0);
    *(undefined4 *)(iVar10 + 0x1bc) = uVar4;
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + 4;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x7c))();
  if (iVar3 == 0) {
    iVar3 = FUN_00113090(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                         *(undefined4 *)(param_1 + 0x238));
    if (iVar3 != 0) {
      iVar10 = 1;
      iVar3 = FUN_0011320c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238));
      if (iVar3 == 0) {
        for (; iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(), iVar10 <= iVar3;
            iVar10 = iVar10 + 1) {
          iVar3 = *(int *)(param_1 + 0xb0);
          puVar14 = *(uint **)(*(int *)(iVar10 * 0x18 + iVar3 + 0x8c) + 0x2c);
          uVar11 = puVar14[1];
          uVar13 = uVar11 - 1;
          if (uVar13 < *puVar14) {
            if (uVar11 <= uVar13) {
              _memset((void *)(uVar11 * 4 + puVar14[2]),0,(uVar13 - uVar11) * 4 + 4);
              puVar14[1] = uVar11;
              iVar3 = *(int *)(param_1 + 0xb0);
            }
            piVar12 = (int *)(uVar13 * 4 + puVar14[2]);
          }
          else {
            piVar12 = (int *)FUN_0019423c(puVar14,uVar13);
            iVar3 = *(int *)(param_1 + 0xb0);
          }
          iVar5 = *piVar12;
          iVar3 = FUN_001054ec(iVar3,iVar10);
          local_58[0] = *(undefined4 *)(iVar3 + 0x10);
          piVar12 = (int *)(iVar10 * 0x10 + param_1 + 0x168);
          puVar14 = (uint *)(iVar10 * 0x20 + param_1 + 200);
          iVar3 = 0;
          do {
            if (*(byte *)((int)local_58 + iVar3) != 4) {
              iVar9 = *(int *)((uint)*(byte *)((int)local_58 + iVar3) * 4 + iVar5 + 0x20);
              if (iVar9 < 0) {
                puVar8 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar9);
                ((void (*)())FUN_0010b2dc)(&local_48,*(undefined4 *)(param_1 + 0xb0),iVar10,*puVar8);
                ((void (*)())FUN_0010b284)(&local_44,*(undefined4 *)(param_1 + 0xb0),iVar10,local_48);
                iVar9 = ((int (*)())FUN_00173e10)(*(undefined4 *)(param_1 + 0x238),local_44);
                iVar9 = *(int *)(iVar9 + 4);
              }
              else {
                iVar7 = *(int *)(param_1 + 0xb0) + iVar10 * 0x18 + 0x80;
                *puVar14 = *(uint *)(iVar7 + 0x20) & 1;
                puVar14[4] = *(uint *)(iVar7 + 0x20) >> 1 & 1;
              }
              *piVar12 = iVar9;
            }
            bVar1 = iVar3 != 3;
            piVar12 = piVar12 + 1;
            puVar14 = puVar14 + 1;
            iVar3 = iVar3 + 1;
          } while (bVar1);
        }
        goto LAB_00174410;
      }
    }
    piVar12 = *(int **)(param_1 + 0xb0);
    for (iVar3 = 1; iVar10 = (**(code **)(*piVar12 + 0x14))(piVar12), iVar3 <= iVar10;
        iVar3 = iVar3 + 1) {
      piVar12 = *(int **)(param_1 + 0xb0);
      puVar14 = *(uint **)(piVar12[iVar3 * 6 + 0x23] + 0x2c);
      uVar13 = puVar14[1];
      uVar11 = uVar13 - 1;
      if (uVar11 < *puVar14) {
        if (uVar13 <= uVar11) {
          _memset((void *)(uVar13 * 4 + puVar14[2]),0,(uVar11 - uVar13) * 4 + 4);
          puVar14[1] = uVar13;
          piVar12 = *(int **)(param_1 + 0xb0);
        }
        piVar6 = (int *)(uVar11 * 4 + puVar14[2]);
      }
      else {
        piVar6 = (int *)FUN_0019423c(puVar14,uVar11);
        piVar12 = *(int **)(param_1 + 0xb0);
      }
      iVar5 = *piVar6;
      pcVar15 = (char *)(iVar3 * 4 + param_1 + 0x224);
      piVar6 = (int *)(iVar3 * 0x10 + param_1 + 0x168);
      puVar14 = (uint *)(iVar3 * 0x20 + param_1 + 200);
      iVar9 = 0;
      iVar10 = param_1;
      do {
        if (*pcVar15 != '\0') {
          iVar7 = FUN_001054ec(piVar12,iVar3);
          uVar11 = (uint)*(byte *)(iVar9 + iVar7 + 0x10);
          if (uVar11 == 4) {
            piVar12 = *(int **)(param_1 + 0xb0);
            *(undefined4 *)(iVar10 + 0x30) = 0;
            *(undefined4 *)(iVar10 + 0x40) = 0;
          }
          else {
            iVar7 = *(int *)(uVar11 * 4 + iVar5 + 0x20);
            if (iVar7 < 0) {
              puVar8 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),iVar7);
              ((void (*)())FUN_0010b2dc)(&local_40,*(undefined4 *)(param_1 + 0xb0),iVar3,*puVar8);
              ((void (*)())FUN_0010b284)(local_3c,*(undefined4 *)(param_1 + 0xb0),iVar3,local_40);
              iVar7 = ((int (*)())FUN_00173e10)(*(undefined4 *)(param_1 + 0x238),local_3c[0]);
              piVar12 = *(int **)(param_1 + 0xb0);
              iVar7 = *(int *)(iVar7 + 4);
            }
            else {
              piVar12 = *(int **)(param_1 + 0xb0);
              *puVar14 = piVar12[iVar3 * 6 + 0x28] & 1;
              puVar14[4] = (uint)piVar12[iVar3 * 6 + 0x28] >> 1 & 1;
            }
            *piVar6 = iVar7;
          }
        }
        bVar1 = iVar9 != 3;
        pcVar15 = pcVar15 + 1;
        iVar10 = iVar10 + 4;
        piVar6 = piVar6 + 1;
        puVar14 = puVar14 + 1;
        iVar9 = iVar9 + 1;
      } while (bVar1);
    }
  }
  else {
    iVar10 = 1;
    if (0 < *(int *)(iVar3 + 0x84)) {
      do {
        iVar5 = FUN_00105594(iVar3,iVar10);
        if (iVar5 == 0) {
          iVar5 = 4;
          puVar8 = (undefined4 *)(iVar10 * 0x10 + param_1 + 0x168);
          do {
            *puVar8 = 0;
            puVar8 = puVar8 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        else {
          iVar9 = 4;
          puVar8 = (undefined4 *)(iVar10 * 0x10 + param_1 + 0x168);
          iVar5 = 0;
          do {
            puVar2 = (undefined4 *)(iVar5 + *(int *)(iVar10 * 4 + *(int *)(iVar3 + 0x138)));
            iVar5 = iVar5 + 4;
            *puVar8 = *puVar2;
            puVar8 = puVar8 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= *(int *)(iVar3 + 0x84));
    }
  }
LAB_00174410:
  piVar12 = *(int **)(param_1 + 0xb0);
  iVar5 = piVar12[0x4c];
  iVar10 = piVar12[0x4d];
  iVar3 = piVar12[0x4e];
  *(int *)(param_1 + 0x1cc) = piVar12[0x4b];
  *(int *)(param_1 + 0x1d0) = iVar5;
  *(int *)(param_1 + 0x1d4) = iVar10;
  *(int *)(param_1 + 0x1d8) = iVar3;
  iVar5 = piVar12[0x4f];
  iVar10 = piVar12[0x50];
  iVar3 = piVar12[0x51];
  *(int *)(param_1 + 0x1e8) = piVar12[0x52];
  *(int *)(param_1 + 0x1dc) = iVar5;
  *(int *)(param_1 + 0x1e0) = iVar10;
  *(int *)(param_1 + 0x1e4) = iVar3;
  iVar3 = (**(code **)(*piVar12 + 0x30))();
  if (iVar3 == 0) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x5c))();
    if (iVar3 == 0) {
      iVar3 = FUN_00172fb8(param_1);
      if (iVar3 == 0) {
        piVar12 = *(int **)(param_1 + 0xb0);
        if ((*(int *)(piVar12[0x22] + 8) == 0xf7) || (*(int *)(piVar12[0x22] + 8) == 0xb4)) {
          *(int *)(param_1 + 0x1d4) = piVar12[0x53];
        }
      }
      else {
        piVar12 = *(int **)(param_1 + 0xb0);
        *(int *)(param_1 + 0x1d4) = piVar12[0x53];
      }
    }
    else {
      piVar12 = *(int **)(param_1 + 0xb0);
      *(undefined1 *)(param_1 + 0x1ec) = 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1dc) = 0;
    _memcpy((void *)(param_1 + 0x1ec),*(void **)(*(int *)(param_1 + 0xb0) + 0x13c),0x24);
    piVar12 = *(int **)(param_1 + 0xb0);
  }
  iVar3 = (**(code **)(*piVar12 + 0x74))(piVar12);
  if (iVar3 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = *(undefined4 *)(param_1 + 0x188);
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x78))();
  if (iVar3 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = *(undefined4 *)(param_1 + 0x188);
  }
  return;
}

/* FUN_001745ac @ 0x1745ac (68 bytes) */
int FUN_001745ac(param_1)
  int param_1;
{
  _memset((void *)(param_1 + 0xb4),0,0x15c);
  ((int (*)())FUN_0017386c)(param_1);
  ((int (*)())FUN_00173f1c)(param_1);
  return;
}

/* FUN_001745f0 @ 0x1745f0 (216 bytes) */
int FUN_001745f0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),9);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = FUN_00180250(param_1);
    if (iVar1 != 0) {
      ((int (*)())FUN_001745ac)(param_1);
    }
    do {
      iVar1 = FUN_0017f7ec(param_1);
    } while (iVar1 != 0);
    iVar1 = FUN_0017b96c(param_1);
    if (iVar1 != 0) {
      ((int (*)())FUN_001745ac)(param_1);
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x24))();
    if ((iVar1 != 0) && (iVar1 = FUN_0017b12c(param_1), iVar1 != 0)) {
      ((int (*)())FUN_001745ac)(param_1);
    }
    iVar1 = FUN_00180830(param_1);
    uVar2 = 1;
    if (iVar1 != 0) {
      ((int (*)())FUN_001745ac)(param_1);
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_001746c8 @ 0x1746c8 (252 bytes) */
int FUN_001746c8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  **(undefined4 **)(param_1 + 0x3f4) = param_2;
  puVar1 = (undefined4 *)
           FUN_00194834(*(undefined4 *)(param_1 + 1000),*(undefined4 *)(param_1 + 0x3f4));
  if (puVar1 == (undefined4 *)0x0) {
    uVar5 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x34);
    puVar1 = puVar2 + 1;
    *puVar2 = uVar5;
    puVar2[3] = 0xffffffff;
    puVar2[0xc] = 0;
    puVar2[2] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[1] = param_2;
    puVar2[8] = 0;
    FUN_00194d44(*(undefined4 *)(param_1 + 1000),puVar1);
    puVar6 = *(uint **)(param_1 + 0x3dc);
    uVar4 = puVar6[1];
    if (uVar4 < *puVar6) {
      _memset((void *)(uVar4 * 4 + puVar6[2]),0,4);
      piVar3 = (int *)(uVar4 * 4 + puVar6[2]);
      puVar6[1] = uVar4 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar4);
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
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  if (param_3 <= (int)param_2) {
    iVar4 = param_2 << 2;
    do {
      puVar5 = *(uint **)(param_4 + 0x40c);
      if (param_2 < *puVar5) {
        uVar1 = puVar5[1];
        if (uVar1 <= param_2) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
          puVar5[1] = param_2 + 1;
        }
        puVar2 = (undefined4 *)(iVar4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar5,param_2);
      }
      iVar3 = FUN_00194834(*puVar2,param_1);
      if (iVar3 != 0) {
        return iVar3;
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
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  if (param_3 <= (int)param_2) {
    iVar4 = param_2 << 2;
    do {
      puVar5 = *(uint **)(param_4 + 0x408);
      if (param_2 < *puVar5) {
        uVar1 = puVar5[1];
        if (uVar1 <= param_2) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
          puVar5[1] = param_2 + 1;
        }
        puVar2 = (undefined4 *)(iVar4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar5,param_2);
      }
      iVar3 = FUN_00194834(*puVar2,param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
      param_2 = param_2 - 1;
      iVar4 = iVar4 + -4;
    } while (param_3 <= (int)param_2);
  }
  return 0;
}

/* FUN_0017494c @ 0x17494c (440 bytes) */
int FUN_0017494c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar11;
  
  iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 0x238),9);
  if ((iVar2 != 0) &&
     (iVar2 = *(int *)(param_1 + 0x238),
     *(int *)(*(int *)(iVar2 + 0x6c4) + 0xa8) < *(int *)(iVar2 + 0x658))) {
    uVar8 = *(undefined4 *)(iVar2 + 0x378);
    iVar6 = 0;
    puVar3 = (undefined4 *)FUN_00193e18(uVar8,0x240);
    *puVar3 = uVar8;
    puVar3[0x2d] = *(undefined4 *)(param_1 + 0xb0);
    puVar9 = puVar3 + 1;
    iVar2 = param_1;
    do {
      iVar4 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar6 + iVar4 + 0x10) == '\x01') {
        puVar9[8] = 3;
      }
      else {
        puVar9[8] = *(undefined4 *)(iVar2 + 0x20);
      }
      bVar1 = iVar6 != 3;
      puVar9 = puVar9 + 1;
      iVar2 = iVar2 + 4;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    iVar2 = ((int (*)())FUN_00174888)(puVar3 + 1,param_2,param_3,
                         *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x6c4));
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0xb0);
      if ((*(uint *)(iVar2 + 0x14) & 1) == 0) {
        puVar11 = *(uint **)(*(int *)(iVar2 + 0x8c) + 0x2c);
        uVar7 = puVar11[1];
        uVar10 = uVar7 - 1;
        if (uVar10 < *puVar11) {
          if (uVar7 <= uVar10) {
            _memset((void *)(uVar7 * 4 + puVar11[2]),0,(uVar10 - uVar7) * 4 + 4);
            puVar11[1] = uVar7;
          }
          piVar5 = (int *)(uVar10 * 4 + puVar11[2]);
        }
        else {
          piVar5 = (int *)FUN_0019423c(puVar11,uVar10);
        }
        iVar2 = *(int *)(*piVar5 + 0xb0);
      }
      iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
      *(int *)(iVar6 + 0xa8) = *(int *)(iVar6 + 0xa8) + 1;
      iVar6 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
      *(int *)(iVar6 + 0x144) = *(int *)(iVar6 + 0x144) + 1;
      FUN_0017d06c(param_1,iVar2,&DAT_001b01bc,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_00174b04 @ 0x174b04 (476 bytes) */
int FUN_00174b04(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  
  iVar10 = 1;
  iVar9 = 0x18;
  piVar2 = *(int **)(param_1 + 0xb0);
  puVar11 = *(uint **)(*(int *)(*(int *)(param_1 + 0x238) + 0x6c4) + 0x410);
  do {
    iVar5 = (**(code **)(*piVar2 + 0x14))();
    if (iVar5 < iVar10) {
      return;
    }
    piVar2 = *(int **)(iVar9 + *(int *)(param_1 + 0xb0) + 0x8c);
    iVar5 = (**(code **)(*piVar2 + 0x18))(piVar2);
    if ((iVar5 != 0) && (uVar8 = piVar2[7], param_3 <= (int)param_2)) {
      iVar5 = param_2 << 2;
      uVar12 = param_2;
      do {
        if (uVar12 < *puVar11) {
          uVar3 = puVar11[1];
          if (uVar3 <= uVar12) {
            _memset((void *)(uVar3 * 4 + puVar11[2]),0,(uVar12 - uVar3) * 4 + 4);
            puVar11[1] = uVar12 + 1;
          }
          piVar4 = (int *)(iVar5 + puVar11[2]);
        }
        else {
          piVar4 = (int *)FUN_0019423c(puVar11,uVar12);
        }
        iVar7 = *(int *)(*piVar4 + 0xc4);
        uVar3 = *(uint *)(iVar7 + 4);
        if (0 < (int)uVar3) {
          uVar6 = 0;
          uVar13 = uVar3;
          do {
            piVar1 = (int *)0x0;
            if (uVar6 < uVar3) {
              piVar1 = (int *)(uVar6 * 4 + *(int *)(iVar7 + 8));
            }
            if (piVar2 == (int *)*piVar1) {
              if ((*(uint *)((uVar8 >> 3 & 0x1ffffffc) + *(int *)(*piVar4 + 0x128) + 8) >>
                   (uVar8 & 0x1f) & 1) != 0) {
                piVar2 = *(int **)(param_1 + 0xb0);
                if ((*(uint *)((int)piVar2 + iVar9 + 0xa0) & 2) == 0) {
                  iVar5 = *(int *)(*(int *)(param_1 + 0x238) + 0x6c4);
                  *(int *)(iVar5 + 0xa8) = *(int *)(iVar5 + 0xa8) + 1;
                  iVar5 = *(int *)(param_1 + 0xb0) + iVar9 + 0x80;
                  FUN_00103d50(iVar5 + 0xc,1,*(uint *)(iVar5 + 0x20) & 1 ^ 1);
                  piVar2 = *(int **)(param_1 + 0xb0);
                }
                goto LAB_00174ca8;
              }
              break;
            }
            uVar6 = uVar6 + 1;
            uVar13 = uVar13 - 1;
          } while (uVar13 != 0);
        }
        uVar12 = uVar12 - 1;
        iVar5 = iVar5 + -4;
      } while (param_3 <= (int)uVar12);
    }
    piVar2 = *(int **)(param_1 + 0xb0);
LAB_00174ca8:
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x18;
  } while( true );
}

/* FUN_00174ce0 @ 0x174ce0 (300 bytes) */
int FUN_00174ce0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 4) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x3f4) + 8) = param_2;
  puVar1 = (undefined4 *)
           FUN_00194834(*(undefined4 *)(param_1 + 0x3ec),*(undefined4 *)(param_1 + 0x3f4));
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x34);
    puVar1 = puVar2 + 1;
    *puVar2 = uVar4;
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
    uVar4 = FUN_00172ed4(param_1);
    puVar2[2] = param_3;
    puVar2[1] = uVar4;
    puVar2[3] = param_2;
    FUN_00194d44(*(undefined4 *)(param_1 + 1000),puVar1);
    FUN_00194d44(*(undefined4 *)(param_1 + 0x3ec),puVar1);
    puVar6 = *(uint **)(param_1 + 0x3dc);
    uVar5 = puVar6[1];
    if (uVar5 < *puVar6) {
      _memset((void *)(uVar5 * 4 + puVar6[2]),0,4);
      piVar3 = (int *)(uVar5 * 4 + puVar6[2]);
      puVar6[1] = uVar5 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar5);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00174e0c @ 0x174e0c (2764 bytes) */
int FUN_00174e0c(param_1)
  int *param_1;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 local_68 [4];
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c [3];
  float local_30;
  
  piVar11 = (int *)param_1[0x2c];
  local_68[0] = DAT_001b01c0;
  local_68[1] = DAT_001b01c4;
  local_68[2] = DAT_001b01c8;
  local_68[3] = DAT_001b01cc;
  if (*(int *)(piVar11[0x22] + 8) == 0x8e) {
    uVar1 = (**(code **)(*piVar11 + 0x7c))(piVar11);
    iVar2 = FUN_0011e780(uVar1);
    if (iVar2 == 0) goto LAB_00174efc;
    piVar11 = (int *)param_1[0x2c];
  }
  iVar2 = FUN_001055cc(piVar11);
  if ((((iVar2 != 0) || (iVar2 = FUN_001045e4(param_1[0x2c]), iVar2 != 0)) ||
      (*(int *)(((int *)param_1[0x2c])[0x22] + 8) == 0xb4)) ||
     ((iVar2 = (**(code **)(*(int *)param_1[0x2c] + 0x6c))(), iVar2 != 0 ||
      (iVar2 = (**(code **)(*(int *)param_1[0x2c] + 0x58))(), iVar2 != 0)))) {
LAB_00174efc:
    iVar2 = 0;
    piVar11 = param_1;
    do {
      iVar9 = param_1[0x8e];
      uVar1 = FUN_00172ed4(iVar9);
      piVar3 = (int *)((int (*)())FUN_001746c8)(iVar9,uVar1);
      piVar3[2] = iVar2;
      piVar3[1] = (int)param_1;
      FUN_00194d44(*(undefined4 *)(param_1[0x8e] + 1000),piVar3);
      FUN_00194d44(*(undefined4 *)(param_1[0x8e] + 0x3ec),piVar3);
      bVar8 = iVar2 != 3;
      iVar2 = iVar2 + 1;
      *piVar11 = *piVar3;
      piVar11 = piVar11 + 1;
    } while (bVar8);
    return;
  }
  iVar2 = (**(code **)(*(int *)param_1[0x2c] + 0x60))();
  if (iVar2 != 0) {
    iVar9 = param_1[0x2c];
    iVar2 = 0;
    piVar11 = param_1;
    do {
      iVar9 = FUN_001054ec(iVar9,0);
      if (*(char *)(iVar2 + iVar9 + 0x10) == '\x01') {
        iVar9 = param_1[0x2c];
      }
      else {
        iVar9 = param_1[0x2c];
        if (0 < *(int *)(iVar9 + 0x84)) {
          iVar10 = 1;
          piVar3 = param_1 + iVar2 + 0x5e;
          do {
            iVar9 = FUN_001054ec(iVar9,iVar10);
            if (*(char *)(iVar2 + iVar9 + 0x10) != '\x04') {
              iVar9 = param_1[0x2c];
              *piVar11 = *piVar3;
              break;
            }
            iVar9 = param_1[0x2c];
            iVar10 = iVar10 + 1;
            piVar3 = piVar3 + 4;
          } while (iVar10 <= *(int *)(iVar9 + 0x84));
        }
      }
      bVar8 = iVar2 == 3;
      piVar11 = piVar11 + 1;
      iVar2 = iVar2 + 1;
      if (bVar8) {
        iVar2 = 0;
        piVar11 = param_1;
        while( true ) {
          iVar9 = FUN_001054ec(iVar9,0);
          if (*(char *)(iVar2 + iVar9 + 0x10) == '\x01') {
            *piVar11 = 2;
          }
          bVar8 = iVar2 == 3;
          piVar11 = piVar11 + 1;
          iVar2 = iVar2 + 1;
          if (bVar8) break;
          iVar9 = param_1[0x2c];
        }
        return;
      }
    } while( true );
  }
  iVar2 = (**(code **)(*(int *)param_1[0x2c] + 0x50))();
  if (iVar2 != 0) {
    iVar2 = 4;
    piVar11 = param_1;
    do {
      *piVar11 = 1;
      piVar11 = piVar11 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    goto LAB_001757ec;
  }
  iVar2 = (**(code **)(*(int *)param_1[0x2c] + 0x48))();
  if (iVar2 == 0) {
    iVar2 = param_1[0x2c];
  }
  else {
    iVar2 = param_1[0x2c];
    iVar9 = *(int *)(iVar2 + 0x98);
    if (((iVar9 == 2) || (iVar9 == 0xc)) || (iVar9 == 0x33)) {
      uVar7 = 0;
      piVar11 = param_1;
      while( true ) {
        if (((int)*(char *)(iVar2 + 0x15c) >> (uVar7 & 0x3f) & 1U) == 0) {
          piVar3 = (int *)((int (*)())FUN_00174ce0)(param_1[0x8e],uVar7,param_1);
          piVar11[0x10] = (int)piVar3;
          *piVar11 = *piVar3;
        }
        else {
          iVar2 = FUN_00179064(param_1,uVar7);
          *piVar11 = *(int *)(iVar2 + 4);
        }
        bVar8 = uVar7 == 3;
        piVar11 = piVar11 + 1;
        uVar7 = uVar7 + 1;
        if (bVar8) break;
        iVar2 = param_1[0x2c];
      }
      goto LAB_001757ec;
    }
  }
  iVar2 = FUN_00113090(*(undefined4 *)(*(int *)(iVar2 + 0x88) + 8),param_1[0x8e]);
  if ((((iVar2 == 0) ||
       (iVar2 = FUN_0011320c(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]),
       iVar2 != 0)) &&
      (iVar2 = FUN_001131c0(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]),
      iVar2 == 0)) &&
     ((iVar2 = ((int (*)())FUN_00173a48)(param_1[0x2c],param_1[0x8e]), iVar2 == 0 &&
      (iVar2 = ((int (*)())FUN_0017356c)(param_1), iVar2 == 0)))) {
    iVar2 = param_1[0x2c];
    iVar9 = FUN_00172f24(iVar2);
    if (iVar9 == 0) {
      uVar1 = 0;
      iVar10 = 0;
      iVar9 = 0;
      piVar11 = param_1;
      do {
        iVar2 = FUN_001054ec(iVar2,0);
        if (*(char *)(iVar10 + iVar2 + 0x10) != '\x01') {
          if (*(int *)(((int *)param_1[0x2c])[0x22] + 8) == 0x8e) {
            iVar2 = FUN_00179bbc(param_1,iVar10);
            if (iVar2 == 0) {
              piVar3 = (int *)((int (*)())FUN_00174ce0)(param_1[0x8e],iVar10,param_1);
              iVar2 = *piVar3;
            }
            else {
              iVar2 = piVar11[0x5e];
            }
            *piVar11 = iVar2;
          }
          else {
            iVar2 = (**(code **)(*(int *)param_1[0x2c] + 100))();
            if (iVar2 == 0) {
              iVar2 = ((int (*)())FUN_0017361c)(param_1[0x2c]);
              if ((iVar2 == 0) || (-1 < piVar11[0x5e])) {
                if (piVar11[0xc] != 0) {
                  *piVar11 = *(int *)(piVar11[0xc] + 4);
                  goto LAB_001757d8;
                }
              }
              else {
                pfVar5 = (float *)FUN_00173360(param_1[0x8e],piVar11[0x5e]);
                local_30 = *pfVar5;
                iVar2 = ((bool (*)())FUN_0010b820)(param_1[0x2c],(double)local_30,(double)FLOAT_001aa0d4);
                iVar2 = (iVar2 == 0) + 2;
                iVar12 = param_1[iVar2 * 4 + iVar10 + 0x5a];
                if (iVar12 < 0) {
                  puVar4 = (undefined4 *)FUN_00173360(param_1[0x8e],iVar12);
                  ((float * (*)())FUN_0010aee8)(&local_40,param_1[0x2c],*puVar4);
                  iVar2 = local_40;
                  ((void (*)())FUN_0010b118)(local_3c,param_1[0x2c],local_40);
                  iVar12 = local_3c[0];
                  if (local_3c[0] != iVar2) goto LAB_001756e4;
                  goto LAB_001756ec;
                }
                iVar6 = param_1[0x2c];
                if ((((*(int *)(iVar6 + 0x120) == 0) && (*(int *)(iVar6 + 0x124) == 0)) &&
                    (uVar7 = *(uint *)(iVar2 * 0x18 + iVar6 + 0xa0), (uVar7 & 1) == 0)) &&
                   ((uVar7 & 2) == 0)) goto LAB_00175760;
              }
LAB_001757a0:
              FUN_00178648(param_1,iVar10);
              FUN_00178338(param_1,iVar10,local_68);
              piVar3 = (int *)piVar11[0x10];
              *piVar11 = *piVar3;
              piVar11[0x20] = piVar3[3];
              piVar11[0x14] = piVar3[4];
            }
            else {
              iVar12 = piVar11[0x5e];
              if (iVar12 < 0) {
                puVar4 = (undefined4 *)FUN_00173360(param_1[0x8e],iVar12);
                ((float * (*)())FUN_0010aee8)(&local_48,param_1[0x2c],*puVar4);
                iVar2 = local_48;
                ((void (*)())FUN_0010b118)(&local_44,param_1[0x2c],local_48);
                iVar12 = local_44;
                if (local_44 != iVar2) {
LAB_001756e4:
                  uVar1 = 1;
                  iVar2 = iVar12;
                }
LAB_001756ec:
                iVar2 = ((int (*)())FUN_00173e10)(param_1[0x8e],iVar2);
                iVar12 = *(int *)(iVar2 + 4);
                iVar2 = FUN_001054ec(param_1[0x2c],0);
                if (*(char *)(iVar10 + iVar2 + 0x10) == '\0') {
                  *(undefined4 *)((int)local_68 + iVar9) = uVar1;
                }
                *piVar11 = iVar12;
              }
              else {
                iVar2 = param_1[0x2c];
                if (((*(int *)(iVar2 + 0x120) != 0) || (*(int *)(iVar2 + 0x124) != 0)) ||
                   (((*(uint *)(iVar2 + 0xb8) & 1) != 0 || ((*(uint *)(iVar2 + 0xb8) & 2) != 0))))
                goto LAB_001757a0;
LAB_00175760:
                *piVar11 = iVar12;
                iVar2 = FUN_00176ed4(param_1,iVar12);
                piVar11[0x20] = iVar2;
                iVar2 = FUN_00176f0c(param_1,iVar12);
                piVar11[0x14] = iVar2;
              }
            }
          }
        }
LAB_001757d8:
        bVar8 = iVar10 == 3;
        iVar9 = iVar9 + 4;
        piVar11 = piVar11 + 1;
        iVar10 = iVar10 + 1;
        if (bVar8) goto LAB_001757ec;
        iVar2 = param_1[0x2c];
      } while( true );
    }
  }
  else {
    iVar2 = param_1[0x2c];
  }
  iVar2 = FUN_001054ec(iVar2,0);
  iVar9 = 0;
  if (*(int *)(iVar2 + 0x10) != DAT_001b01b4) {
    iVar2 = FUN_001054ec(param_1[0x2c],0);
    iVar9 = FUN_000f30d4(*(undefined4 *)(iVar2 + 0x10));
  }
  iVar2 = (**(code **)(*(int *)param_1[0x2c] + 100))();
  if (iVar2 == 0) {
    iVar2 = ((int (*)())FUN_0017361c)(param_1[0x2c]);
    if (iVar2 == 0) {
      iVar2 = (param_1 + iVar9)[0xc];
      if (iVar2 != 0) {
LAB_0017547c:
        iVar10 = *(int *)(iVar2 + 4);
        iVar2 = 0;
        iVar9 = 0;
        goto LAB_001754f8;
      }
      FUN_00178648(param_1,iVar9);
      FUN_00178338(param_1,iVar9,local_68);
      iVar10 = 4;
      iVar2 = 0;
      piVar11 = param_1;
      do {
        piVar11[0x10] = (param_1 + iVar9)[0x10];
        piVar11 = piVar11 + 1;
        *(undefined4 *)((int)local_68 + iVar2) = local_68[iVar9];
        iVar2 = iVar2 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    else {
      piVar11 = param_1 + iVar9;
      if (piVar11[0x5e] < 0) {
        pfVar5 = (float *)FUN_00173360(param_1[0x8e],piVar11[0x5e]);
        local_30 = *pfVar5;
        iVar2 = ((bool (*)())FUN_0010b820)(param_1[0x2c],(double)local_30,(double)FLOAT_001aa0d4);
        iVar2 = (iVar2 == 0) + 2;
        iVar10 = param_1[iVar2 * 4 + iVar9 + 0x5a];
        if (iVar10 < 0) {
          bVar8 = false;
          puVar4 = (undefined4 *)FUN_00173360(param_1[0x8e],iVar10);
          ((float * (*)())FUN_0010aee8)(&local_50,param_1[0x2c],*puVar4);
          ((void (*)())FUN_0010b118)(&local_4c,param_1[0x2c],local_50);
          local_54 = local_4c;
          if (local_4c != local_50) goto LAB_00175348;
          goto LAB_00175350;
        }
        iVar12 = param_1[0x2c];
        if (((*(int *)(iVar12 + 0x120) == 0) && (*(int *)(iVar12 + 0x124) == 0)) &&
           ((uVar7 = *(uint *)(iVar2 * 0x18 + iVar12 + 0xa0), (uVar7 & 1) == 0 && ((uVar7 & 2) == 0)
            ))) goto LAB_001753c0;
        FUN_00178648(param_1,iVar9);
        FUN_00178338(param_1,iVar9,local_68);
        iVar2 = 4;
        iVar10 = 0;
        piVar11 = param_1;
        do {
          piVar11[0x10] = (param_1 + iVar9)[0x10];
          piVar11 = piVar11 + 1;
          *(undefined4 *)((int)local_68 + iVar10) = local_68[iVar9];
          iVar10 = iVar10 + 4;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else {
        iVar2 = piVar11[0xc];
        if (iVar2 != 0) goto LAB_0017547c;
        FUN_00178648(param_1,iVar9);
        FUN_00178338(param_1,iVar9,local_68);
        iVar10 = 4;
        iVar2 = 0;
        piVar3 = param_1;
        do {
          piVar3[0x10] = piVar11[0x10];
          piVar3 = piVar3 + 1;
          *(undefined4 *)((int)local_68 + iVar2) = local_68[iVar9];
          iVar2 = iVar2 + 4;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
      }
    }
    piVar11 = (int *)(param_1 + iVar9)[0x10];
    iVar9 = piVar11[4];
    iVar10 = *piVar11;
    iVar2 = piVar11[3];
  }
  else {
    iVar10 = param_1[iVar9 + 0x5e];
    if (iVar10 < 0) {
      bVar8 = false;
      puVar4 = (undefined4 *)FUN_00173360(param_1[0x8e],iVar10);
      ((float * (*)())FUN_0010aee8)(&local_58,param_1[0x2c],*puVar4);
      ((void (*)())FUN_0010b118)(&local_54,param_1[0x2c],local_58);
      local_50 = local_58;
      if (local_54 != local_58) {
LAB_00175348:
        bVar8 = true;
        local_50 = local_54;
      }
LAB_00175350:
      iVar2 = ((int (*)())FUN_00173e10)(param_1[0x8e],local_50);
      iVar10 = *(int *)(iVar2 + 4);
      if ((*(int *)(param_1[0x2c] + 0x120) == 0) || (bVar8)) {
        iVar2 = 0;
        iVar9 = 0;
      }
      else {
        iVar2 = 0;
        iVar9 = 0;
        *(undefined4 *)(param_1[0x2c] + 0x120) = 0;
      }
    }
    else {
      iVar2 = param_1[0x2c];
      if ((((*(int *)(iVar2 + 0x120) == 0) && (*(int *)(iVar2 + 0x124) == 0)) &&
          ((*(uint *)(iVar2 + 0xb8) & 1) == 0)) && ((*(uint *)(iVar2 + 0xb8) & 2) == 0)) {
LAB_001753c0:
        iVar2 = FUN_00176ed4(param_1,iVar10);
        iVar9 = FUN_00176f0c(param_1,iVar10);
      }
      else {
        FUN_00178648(param_1,iVar9);
        FUN_00178338(param_1,iVar9,local_68);
        piVar11 = (int *)param_1[iVar9 + 0x10];
        iVar9 = piVar11[4];
        iVar10 = *piVar11;
        iVar2 = piVar11[3];
      }
    }
  }
LAB_001754f8:
  iVar12 = 4;
  piVar11 = param_1;
  do {
    *piVar11 = iVar10;
    piVar11[0x20] = iVar2;
    piVar11[0x14] = iVar9;
    piVar11 = piVar11 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
LAB_001757ec:
  ((int (*)())FUN_00173af8)(param_1,local_68);
  FUN_0017729c(param_1);
  FUN_001771b0(param_1);
  return;
}

/* FUN_001758d8 @ 0x1758d8 (356 bytes) */
int FUN_001758d8(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  
  if (param_3 <= (int)param_2) {
    iVar7 = param_2 << 2;
    uVar6 = param_2;
    do {
      puVar5 = *(uint **)(param_4 + 0x404);
      if (uVar6 < *puVar5) {
        uVar3 = puVar5[1];
        if (uVar3 <= uVar6) {
          _memset((void *)(uVar3 * 4 + puVar5[2]),0,(uVar6 - uVar3) * 4 + 4);
          puVar5[1] = uVar6 + 1;
        }
        puVar4 = (undefined4 *)(iVar7 + puVar5[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar5,uVar6);
      }
      puVar4 = (undefined4 *)FUN_00194834(*puVar4,param_1);
      if (puVar4 != (undefined4 *)0x0) {
        iVar7 = 4;
        puVar2 = puVar4;
        do {
          uVar1 = *puVar2;
          puVar2 = puVar2 + 1;
          *param_1 = uVar1;
          param_1 = param_1 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        return puVar4;
      }
      uVar6 = uVar6 - 1;
      iVar7 = iVar7 + -4;
    } while (param_3 <= (int)uVar6);
  }
  ((int (*)())FUN_00174e0c)(param_1);
  puVar5 = *(uint **)(param_4 + 0x404);
  if (param_2 < *puVar5) {
    uVar6 = puVar5[1];
    if (uVar6 <= param_2) {
      _memset((void *)(uVar6 * 4 + puVar5[2]),0,(param_2 - uVar6) * 4 + 4);
      puVar5[1] = param_2 + 1;
    }
    puVar4 = (undefined4 *)(param_2 * 4 + puVar5[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(puVar5,param_2);
  }
  FUN_00194d44(*puVar4,param_1);
  return (undefined4 *)0x0;
}

/* FUN_00175a3c @ 0x175a3c (260 bytes) */
undefined4 * FUN_00175a3c(int param_1,undefined4 param_2,undefined4 param_3,double fparam_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4) = param_3;
  **(float **)(param_1 + 0x3f0) = (float)fparam_1;
  puVar1 = (undefined4 *)
           FUN_00194834(*(undefined4 *)(param_1 + 0x3e4),*(undefined4 *)(param_1 + 0x3f0));
  if (puVar1 == (undefined4 *)0x0) {
    uVar5 = *(undefined4 *)(param_1 + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar5,0x2c);
    puVar1 = puVar2 + 1;
    *puVar2 = uVar5;
    puVar2[1] = (float)fparam_1;
    puVar2[5] = 4;
    puVar2[8] = 0;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 0xd) = 0;
    puVar2[4] = 0;
    puVar2[7] = 0;
    puVar2[2] = param_3;
    FUN_00194d44(*(undefined4 *)(param_1 + 0x3e4),puVar1);
    FUN_00194d44(*(undefined4 *)(param_1 + 0x3e0),puVar1);
    puVar6 = *(uint **)(param_1 + 0x3d8);
    uVar4 = puVar6[1];
    if (uVar4 < *puVar6) {
      _memset((void *)(uVar4 * 4 + puVar6[2]),0,4);
      piVar3 = (int *)(uVar4 * 4 + puVar6[2]);
      puVar6[1] = uVar4 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(puVar6,uVar4);
    }
    *piVar3 = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00175b40 @ 0x175b40 (620 bytes) */
int FUN_00175b40(param_1)
  undefined4 *param_1;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 local_38 [7];
  
  iVar4 = param_1[0x2c];
  if ((*(uint *)(iVar4 + 0x14) & 0x200) == 0) {
    iVar4 = 4;
    do {
      param_1[4] = 1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    puVar12 = *(uint **)(*(int *)(*(int *)(iVar4 + 0x84) * 0x18 + iVar4 + 0x8c) + 0x2c);
    uVar10 = puVar12[1];
    uVar8 = uVar10 - 1;
    if (uVar8 < *puVar12) {
      if (uVar10 <= uVar8) {
        _memset((void *)(uVar10 * 4 + puVar12[2]),0,(uVar8 - uVar10) * 4 + 4);
        puVar12[1] = uVar10;
        iVar4 = param_1[0x2c];
      }
      piVar5 = (int *)(uVar8 * 4 + puVar12[2]);
    }
    else {
      piVar5 = (int *)FUN_0019423c(puVar12,uVar8);
      iVar4 = param_1[0x2c];
    }
    iVar11 = *piVar5;
    iVar4 = FUN_001054ec(iVar4,0);
    iVar9 = 0;
    local_38[0] = *(undefined4 *)(iVar4 + 0x10);
    puVar13 = param_1;
    do {
      uVar7 = *(undefined4 *)(iVar11 + 0x20);
      if (((*(char *)((int)local_38 + iVar9) == '\x01') &&
          (iVar4 = ((int (*)())FUN_00176264)(*puVar13,uVar7), iVar4 != 0)) &&
         (iVar4 = (**(code **)(*(int *)param_1[0x2c] + 100))(), iVar4 == 0)) {
        iVar4 = FUN_00113090(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]);
        if (iVar4 == 0) {
LAB_00175c7c:
          iVar6 = *(int *)(param_1[0x2c] + 0x88);
          iVar4 = FUN_001131c0(*(undefined4 *)(iVar6 + 8),param_1[0x8e]);
          if (iVar4 == 0) goto LAB_00175ce8;
        }
        else {
          iVar6 = *(int *)(param_1[0x2c] + 0x88);
          iVar4 = FUN_0011320c(*(undefined4 *)(iVar6 + 8),param_1[0x8e]);
          if (iVar4 != 0) goto LAB_00175c7c;
        }
        iVar4 = FUN_000e07dc(param_1[0x8e],0x30);
        if (((iVar4 == 0) || (iVar9 != 3)) &&
           (iVar4 = FUN_00113734(param_1[0x8e],param_1[0x2c],piVar5,in_r6,in_r7,in_r8,iVar6),
           iVar4 == 0)) {
          *(int *)(*(int *)(param_1[0x8e] + 0x6c4) + 0xa8) =
               *(int *)(*(int *)(param_1[0x8e] + 0x6c4) + 0xa8) + 1;
          *(undefined1 *)(iVar9 + param_1[0x2c] + 0x9c) = 0;
        }
      }
LAB_00175ce8:
      bVar1 = iVar9 != 3;
      uVar2 = *(undefined4 *)(iVar11 + 0x70);
      uVar3 = *(undefined4 *)(iVar11 + 0xa0);
      iVar9 = iVar9 + 1;
      puVar13[4] = uVar7;
      iVar11 = iVar11 + 4;
      puVar13[0x18] = uVar2;
      puVar13[0x24] = uVar3;
      puVar13 = puVar13 + 1;
    } while (bVar1);
    iVar4 = FUN_000f3154(param_1[0x2c]);
    if ((iVar4 == 0) && (iVar4 = FUN_001055cc(param_1[0x2c]), iVar4 == 0)) {
      *(int *)(*(int *)(param_1[0x8e] + 0x6c4) + 0xa8) =
           *(int *)(*(int *)(param_1[0x8e] + 0x6c4) + 0xa8) + 1;
      iVar4 = param_1[0x2c];
      FUN_00106004(iVar4,*(undefined4 *)(iVar4 + 0x84),0,0,param_1[0x8e]);
      *(int *)(iVar4 + 0x84) = *(int *)(iVar4 + 0x84) + -1;
      *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) & 0xfffffdff;
    }
  }
  return;
}

/* FUN_00175dac @ 0x175dac (1208 bytes) */
int FUN_00175dac(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  
  iVar1 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),7);
  if ((iVar1 == 0) || (*(int *)(*(int *)(param_1 + 8) + 0x654) <= *(int *)(param_1 + 0x14c))) {
LAB_00176244:
    uVar5 = 0;
  }
  else {
    FUN_00172a28(*param_4);
    ((int (*)())FUN_00173f1c)(*param_4);
    iVar1 = *param_4;
    if (*(int *)(*(int *)(*(int *)(iVar1 + 0xb0) + 0x88) + 8) == 0x8e) {
LAB_00175e58:
      iVar1 = ((int (*)())FUN_00173638)(iVar1);
      if (iVar1 == 0) {
        FUN_00180154(*param_4);
        iVar1 = ((int (*)())FUN_001733a0)(*param_4);
        if (iVar1 != 0) {
          ((int (*)())FUN_001745ac)(*param_4);
        }
        iVar1 = ((int (*)())FUN_001758d8)(*param_4,param_2,param_3,param_1);
        ((int (*)())FUN_00175b40)(*param_4);
        FUN_00173278(*param_4);
        iVar2 = ((int (*)())FUN_00174888)(*param_4,param_2,param_3,param_1);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(**(int **)(*param_4 + 0xb0) + 100))();
          if ((((iVar2 == 0) &&
               (iVar2 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))(), iVar2 == 0)) &&
              (iVar2 = FUN_00172fb8(*param_4), iVar2 == 0)) &&
             (iVar2 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),8), iVar2 != 0)) {
            iVar2 = ((int (*)())FUN_001747c4)(*param_4,param_2,param_3,param_1);
            if ((iVar2 != 0) && (iVar2 = ((int (*)())FUN_00173cdc)(*param_4,iVar2), iVar2 != 0)) {
              iVar7 = *(int *)(*param_4 + 0xb0);
              iVar2 = FUN_00122fa4(*(undefined4 *)(iVar7 + 0xa4),*(undefined4 *)(param_1 + 0x3a0));
              if ((iVar7 == *(int *)(iVar2 + 0xb0)) &&
                 (iVar2 = FUN_0011f2f8(param_1,*(undefined4 *)(*param_4 + 0xb0),param_5), iVar2 != 0
                 )) goto LAB_0017624c;
              goto LAB_001760e4;
            }
            iVar2 = *param_4;
            piVar6 = *(int **)(iVar2 + 0xb0);
            if (piVar6[0x20] != 0) {
              iVar2 = FUN_00126760(piVar6[0x26]);
              if (((iVar2 == 0) || ((piVar6[5] & 2U) != 0)) ||
                 (iVar2 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar2 != 0)) goto LAB_001760e4;
              puVar8 = *(uint **)(param_1 + 0x40c);
              if (param_2 < *puVar8) {
                uVar3 = puVar8[1];
                if (uVar3 <= param_2) {
                  _memset((void *)(uVar3 * 4 + puVar8[2]),0,(param_2 - uVar3) * 4 + 4);
                  puVar8[1] = param_2 + 1;
                }
                puVar4 = (undefined4 *)(param_2 * 4 + puVar8[2]);
              }
              else {
                puVar4 = (undefined4 *)FUN_0019423c(puVar8,param_2);
              }
              FUN_00194d44(*puVar4,*param_4);
              iVar2 = *param_4;
            }
          }
          else {
LAB_001760e4:
            iVar2 = *param_4;
          }
          iVar2 = (**(code **)(**(int **)(iVar2 + 0xb0) + 100))();
          if ((((iVar2 == 0) &&
               (iVar2 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))(), iVar2 == 0)) &&
              (iVar2 = FUN_00172fb8(*param_4), iVar2 == 0)) &&
             (((iVar1 != 0 && (iVar1 = ((int (*)())FUN_00173754)(*param_4,iVar1), iVar1 != 0)) ||
              (iVar1 = ((int (*)())FUN_0017494c)(*param_4,param_2,param_3), iVar1 != 0)))) {
            iVar2 = *(int *)(*param_4 + 0xb0);
            iVar1 = FUN_00122fa4(*(undefined4 *)(iVar2 + 0xa4),*(undefined4 *)(param_1 + 0x3a0));
            if ((iVar2 == *(int *)(iVar1 + 0xb0)) &&
               (iVar1 = FUN_0011f2f8(param_1,iVar2,param_5), iVar1 != 0)) goto LAB_0017624c;
          }
          iVar1 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))();
          if (iVar1 == 0) {
            puVar8 = *(uint **)(param_1 + 0x408);
            if (param_2 < *puVar8) {
              uVar3 = puVar8[1];
              if (uVar3 <= param_2) {
                _memset((void *)(uVar3 * 4 + puVar8[2]),0,(param_2 - uVar3) * 4 + 4);
                puVar8[1] = param_2 + 1;
              }
              puVar4 = (undefined4 *)(param_2 * 4 + puVar8[2]);
            }
            else {
              puVar4 = (undefined4 *)FUN_0019423c(puVar8,param_2);
            }
            FUN_00194d44(*puVar4,*param_4);
            return 0;
          }
          goto LAB_00176244;
        }
        iVar1 = ((int (*)())FUN_00173b98)(iVar2,*(undefined4 *)(*param_4 + 0xb0),param_5,param_1);
        if (iVar1 == 0) goto LAB_00176244;
        *param_4 = iVar2;
        iVar1 = (**(code **)(**(int **)(iVar2 + 0xb0) + 100))();
        if (iVar1 == 0) {
          iVar1 = *(int *)(*param_4 + 0xb0);
          if (*(int *)(iVar1 + 0x160) <= *(int *)(param_1 + 0x478)) {
            *(int *)(iVar1 + 0x160) = *(int *)(param_1 + 0x478) + 1;
            return 1;
          }
          *(int *)(iVar1 + 0x160) = *(int *)(iVar1 + 0x160) + 1;
          return 1;
        }
      }
    }
    else {
      iVar1 = ((int (*)())FUN_001745f0)(iVar1);
      if ((iVar1 == 0) ||
         (iVar1 = FUN_0011f2f8(param_1,*(undefined4 *)(*param_4 + 0xb0),param_5), iVar1 == 0)) {
        iVar1 = *param_4;
        goto LAB_00175e58;
      }
    }
LAB_0017624c:
    uVar5 = 1;
  }
  return uVar5;
}

/* FUN_00176264 @ 0x176264 (28 bytes) */
int FUN_00176264(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((param_1 == param_2) && (param_1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00176280 @ 0x176280 (28 bytes) */
int FUN_00176280(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined1 *)(param_2 + 8);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined1 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = uVar2;
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

/* FUN_001762bc @ 0x1762bc (4 bytes) */
int FUN_001762bc()
{
  return;
}

/* FUN_001762c0 @ 0x1762c0 (68 bytes) */
int FUN_001762c0(param_1)
  undefined4 param_1;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = 1;
  do {
    ((int (*)())FUN_001746c8)(param_1,iVar2);
    bVar1 = iVar2 != 3;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return;
}

/* FUN_00176304 @ 0x176304 (32 bytes) */
double FUN_00176304(double fparam_1)

{
  return (double)(float)(fparam_1 * (double)FLOAT_001aa1cc);
}

/* FUN_00176324 @ 0x176324 (44 bytes) */
int FUN_00176324(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return 3;
  }
  if (0 < param_1) {
    return 5;
  }
  if (param_1 < 0) {
    return 1;
  }
  return 0;
}

/* FUN_00176350 @ 0x176350 (148 bytes) */
undefined4 FUN_00176350(double fparam_1)

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

/* FUN_001763e4 @ 0x1763e4 (144 bytes) */
int FUN_001763e4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  
  pcVar6 = (char *)(param_2 * 4 + param_1 + 0x224);
  piVar5 = (int *)(param_2 * 0x10 + param_1 + 0x168);
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (*pcVar6 != '\0') {
      if (iVar3 == 0) {
        iVar3 = *piVar5;
      }
      else {
        iVar2 = ((int (*)())FUN_00176264)(iVar3,*piVar5);
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    bVar1 = iVar4 != 3;
    pcVar6 = pcVar6 + 1;
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  return 1;
}

/* FUN_00176474 @ 0x176474 (104 bytes) */
int FUN_00176474(undefined4 param_1,int param_2,int param_3,double fparam_1)

{
  bool bVar1;
  int iVar2;
  float *pfVar3;
  
  iVar2 = 1;
  pfVar3 = (float *)(param_2 + param_3 * 0x10 + -0xc);
  while( true ) {
    if ((double)*pfVar3 == fparam_1) {
      return iVar2 + 1;
    }
    if ((double)*pfVar3 == (double)FLOAT_001aa114) break;
    bVar1 = iVar2 == 3;
    pfVar3 = pfVar3 + 1;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      return 0;
    }
  }
  *pfVar3 = (float)fparam_1;
  return iVar2 + 1;
}

/* FUN_001764e0 @ 0x1764e0 (28 bytes) */
int FUN_001764e0(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_2 * 4 + param_1 + 0x70) == 4;
}

/* FUN_001764fc @ 0x1764fc (28 bytes) */
int FUN_001764fc(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(int *)(param_2 * 4 + param_1 + 0xa0) == 1;
}

/* FUN_00176518 @ 0x176518 (28 bytes) */
int FUN_00176518(param_1, param_2)
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
  undefined4 uVar1;
  
  uVar1 = ((int (*)())FUN_00173e10)(*(undefined4 *)(param_1 + 0x238),param_2);
  *(undefined4 *)(param_3 * 4 + param_1 + 0x30) = uVar1;
  return;
}

/* FUN_001765e4 @ 0x1765e4 (44 bytes) */
int FUN_001765e4(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  return *(undefined4 *)(&DAT_001e5f54 + (param_2 * 6 + param_3) * 4);
}

/* FUN_00176610 @ 0x176610 (28 bytes) */
int FUN_00176610(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((param_2 != 2) && (param_2 != 5)) {
    return 1;
  }
  return 0;
}

/* FUN_0017662c @ 0x17662c (144 bytes) */
int FUN_0017662c(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = param_1;
  do {
    iVar2 = FUN_001054ec(*(undefined4 *)(param_1 + 0xb0),0);
    if ((*(char *)(iVar3 + iVar2 + 0x10) != '\x01') && (*(int *)(iVar4 + 0x30) == 0)) {
      iVar2 = *(int *)(iVar4 + 0x40);
      if (iVar2 == 0) {
        iVar2 = ((int (*)())FUN_00174ce0)(*(undefined4 *)(param_1 + 0x238),iVar3,param_1);
        *(int *)(iVar4 + 0x40) = iVar2;
      }
      *(undefined4 *)(iVar2 + 0xc) = 4;
    }
    bVar1 = iVar3 != 3;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}

/* FUN_001766bc @ 0x1766bc (112 bytes) */
int FUN_001766bc(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_00173e10)(*(undefined4 *)(param_1 + 0x238),0);
  if ((*(int *)(iVar1 + 4) == *(int *)(param_1 + 0x184)) ||
     (uVar2 = 0, *(int *)(iVar1 + 4) == *(int *)(param_1 + 0x194))) {
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar2 = FUN_00112f54(0x1c);
    *(undefined4 *)(iVar1 + 0x88) = uVar2;
    ((int (*)())FUN_001745ac)(param_1);
    uVar2 = 1;
  }
  return uVar2;
}

/* FUN_0017672c @ 0x17672c (172 bytes) */
int FUN_0017672c(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  while( true ) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))();
    if (iVar1 < iVar2) {
      return 1;
    }
    iVar1 = FUN_0011346c(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(param_1 + 0xb0));
    if ((iVar1 == 0) || ((iVar1 = 3, iVar2 != 1 && (iVar1 = 1, iVar2 != 3)))) {
      iVar1 = 0;
    }
    if (-1 < *(int *)((iVar2 * 4 + iVar1) * 4 + param_1 + 0x168)) break;
    iVar2 = iVar2 + 1;
  }
  return 0;
}

/* FUN_001767d8 @ 0x1767d8 (124 bytes) */
int FUN_001767d8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 * 4 + param_1 + 0x178);
  iVar2 = 1;
  while( true ) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))();
    if (iVar1 < iVar2) {
      return 1;
    }
    iVar1 = *piVar3;
    piVar3 = piVar3 + 4;
    if (-1 < iVar1) break;
    iVar2 = iVar2 + 1;
  }
  return 0;
}

/* FUN_00176854 @ 0x176854 (128 bytes) */
int FUN_00176854(param_1, param_2, param_3, param_4, param_5, param_6)
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
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar2 = param_2 * 4 + param_1;
  piVar5 = (int *)(iVar2 + 0x178);
  iVar4 = 1;
  while ((-1 < *piVar5 ||
         (piVar3 = (int *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*piVar5), *piVar3 != 0))) {
    bVar1 = iVar4 == 2;
    piVar5 = piVar5 + 4;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      return 0;
    }
  }
  *(int **)(iVar2 + 0x30) = piVar3;
  return 1;
}

/* FUN_00176954 @ 0x176954 (160 bytes) */
int FUN_00176954(param_1, param_2)
  int param_1;
  int param_2;
{
  float *pfVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_2 * 4 + param_1;
  if ((*(int *)(iVar5 + 0x178) < 0) && (*(int *)(iVar5 + 0x188) < 0)) {
    pfVar1 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar5 + 0x178));
    pfVar2 = (float *)FUN_00173360(*(undefined4 *)(param_1 + 0x238),*(undefined4 *)(iVar5 + 0x188));
    iVar5 = ((bool (*)())FUN_0010b820)(*(undefined4 *)(param_1 + 0xb0),(double)*pfVar1,(double)*pfVar2);
    uVar4 = 0x3f800000;
    if (iVar5 == 0) {
      uVar4 = 0;
    }
    uVar3 = ((int (*)())FUN_00173e10)(*(undefined4 *)(param_1 + 0x238),uVar4);
    uVar4 = 1;
    *(undefined4 *)(param_2 * 4 + param_1 + 0x30) = uVar3;
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
  undefined4 *puVar2;
  
  iVar1 = FUN_0011346c(*(undefined4 *)(param_2 + 0x238),*(undefined4 *)(param_2 + 0xb0));
  if ((iVar1 == 0) || ((iVar1 = 3, param_3 != 1 && (iVar1 = 1, param_3 != 3)))) {
    iVar1 = 0;
  }
  iVar1 = *(int *)((param_3 * 4 + iVar1) * 4 + param_2 + 0x168);
  if (iVar1 < 0) {
    puVar2 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),iVar1);
    *param_1 = *puVar2;
  }
  else {
    *param_1 = 0x7ffffffe;
  }
  return param_1;
}

/* FUN_00176a94 @ 0x176a94 (428 bytes) */
int FUN_00176a94(param_1, param_2, param_3)
  float *param_1;
  int param_2;
  undefined4 *param_3;
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_78 [4];
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  float local_48;
  float local_44;
  float local_40;
  
  iVar7 = 4;
  *param_1 = NAN;
  puVar3 = local_78;
  do {
    *puVar3 = 0x7ffffffe;
    puVar3 = puVar3 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 4;
  puVar3 = local_68;
  do {
    *puVar3 = 0x7ffffffe;
    puVar3 = puVar3 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 4;
  puVar3 = local_58;
  do {
    *puVar3 = 0x7ffffffe;
    puVar3 = puVar3 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = 0;
  iVar7 = param_2;
  do {
    uVar2 = *(undefined4 *)(param_2 + 0x238);
    uVar5 = *(undefined4 *)(iVar7 + 0x178);
    *(undefined4 *)(iVar6 + (int)local_78) = 0;
    puVar3 = (undefined4 *)FUN_00173360(uVar2,uVar5);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_78) = *puVar3;
    }
    uVar2 = *(undefined4 *)(param_2 + 0x238);
    uVar5 = *(undefined4 *)(iVar7 + 0x188);
    *(undefined4 *)(iVar6 + (int)local_68) = 0;
    puVar3 = (undefined4 *)FUN_00173360(uVar2,uVar5);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_68) = *puVar3;
    }
    uVar2 = *(undefined4 *)(param_2 + 0x238);
    uVar5 = *(undefined4 *)(iVar7 + 0x198);
    *(undefined4 *)(iVar6 + (int)local_58) = 0;
    puVar3 = (undefined4 *)FUN_00173360(uVar2,uVar5);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar6 + (int)local_58) = *puVar3;
    }
    bVar1 = iVar6 != 0xc;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 4;
  } while (bVar1);
  *param_1 = NAN;
  piVar4 = *(int **)(*(int *)(param_2 + 0xb0) + 0x88);
  (**(code **)(*piVar4 + 8))
            (piVar4,param_1,local_78,local_68,local_58,*(undefined4 *)(param_2 + 0x238));
  local_40 = *param_1;
  if (local_40 != FLOAT_001aa1d0) {
    ((float * (*)())FUN_0010aee8)(&local_48,*(undefined4 *)(param_2 + 0xb0),local_40);
    *param_1 = local_48;
    ((void (*)())FUN_0010b118)(&local_44,*(undefined4 *)(param_2 + 0xb0),local_48);
    if (local_44 != *param_1) {
      *param_3 = 1;
      *param_1 = local_44;
    }
  }
  return param_1;
}

/* FUN_00176c40 @ 0x176c40 (300 bytes) */
int FUN_00176c40(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_48 [8];
  int local_28;
  int local_24 [2];
  
  iVar6 = 5;
  puVar4 = local_48;
  do {
    *puVar4 = 0x7ffffffe;
    puVar4 = puVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar4 = local_48;
  iVar6 = 1;
  *param_1 = 0x7ffffffe;
  puVar5 = (undefined4 *)(param_3 * 4 + param_2 + 0x178);
  while( true ) {
    puVar4 = puVar4 + 1;
    iVar2 = (**(code **)(**(int **)(param_2 + 0xb0) + 0x14))();
    if (iVar2 < iVar6) break;
    iVar6 = iVar6 + 1;
    puVar1 = (undefined4 *)FUN_00173360(*(undefined4 *)(param_2 + 0x238),*puVar5);
    *puVar4 = *puVar1;
    puVar5 = puVar5 + 4;
  }
  piVar3 = *(int **)(*(int *)(param_2 + 0xb0) + 0x88);
  (**(code **)(*piVar3 + 4))(piVar3,param_1,local_48,*(undefined4 *)(param_2 + 0x238));
  if (*param_1 != 0x7ffffffe) {
    ((float * (*)())FUN_0010aee8)(&local_28,*(undefined4 *)(param_2 + 0xb0),*param_1);
    *param_1 = local_28;
    ((void (*)())FUN_0010b118)(local_24,*(undefined4 *)(param_2 + 0xb0),local_28);
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
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((param_1 < 1) || (param_2 < 1)) || (iVar1 = FUN_00173330(param_3,param_1), iVar1 == 0)) ||
     ((iVar2 = FUN_00173330(param_3,param_2), iVar2 == 0 ||
      (((*(int *)(iVar1 + 0x20) == 0 || (param_2 != *(int *)(iVar1 + 0x24))) &&
       ((*(int *)(iVar2 + 0x20) == 0 || (param_1 != *(int *)(iVar2 + 0x24))))))))) {
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
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((param_1 < 1) || (param_2 < 1)) || (iVar1 = FUN_00173330(param_3,param_1), iVar1 == 0)) ||
     ((iVar2 = FUN_00173330(param_3,param_2), iVar2 == 0 ||
      (((*(int *)(iVar1 + 0x28) == 0 || (param_2 != *(int *)(iVar1 + 0x2c))) &&
       ((*(int *)(iVar2 + 0x28) == 0 || (param_1 != *(int *)(iVar2 + 0x2c))))))))) {
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
  ((int (*)())FUN_00176e20)(param_2,param_3,*(undefined4 *)(param_1 + 0x238));
  return;
}

