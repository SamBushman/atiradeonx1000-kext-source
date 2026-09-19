#include "decls.h"

/* FUN_000f7b10 @ 0xf7b10 (228 bytes) */
int FUN_000f7b10(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uVar2 = 0;
  if (param_1[1] != 0) {
    uVar3 = 0;
    uVar2 = param_1[1];
    iStack0000001c = param_2;
    iStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    do {
      if (uVar3 < *param_1) {
        if (uVar2 <= uVar3) {
          _memset((void *)(uVar2 * 4 + param_1[2]),0,(uVar3 - uVar2) * 4 + 4);
          param_1[1] = uVar3 + 1;
        }
        puVar1 = (undefined4 *)(uVar3 * 4 + param_1[2]);
      }
      else {
        puVar1 = (undefined4 *)FUN_0019423c(param_1,uVar3);
      }
      if ((*(int *)*puVar1 == param_2) && (((int *)*puVar1)[1] == param_3)) {
        return uVar3;
      }
      uVar2 = param_1[1];
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return uVar2;
}

/* FUN_000f7bf4 @ 0xf7bf4 (228 bytes) */
int FUN_000f7bf4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[8] = param_2;
  iVar1 = FUN_00194034(param_2 + 0x37c);
  param_1[7] = iVar1;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = iVar1 * 4 + 4;
  param_1[9] = iVar3;
  uVar2 = FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = uVar2;
  return;
}

/* FUN_000f7cd8 @ 0xf7cd8 (228 bytes) */
int FUN_000f7cd8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[8] = param_2;
  iVar1 = FUN_00194034(param_2 + 0x37c);
  param_1[7] = iVar1;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = iVar1 * 4 + 4;
  param_1[9] = iVar3;
  uVar2 = FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = uVar2;
  return;
}

/* FUN_000f7dbc @ 0xf7dbc (352 bytes) */
int FUN_000f7dbc(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  piVar2 = (int *)FUN_000ec5b8(*(undefined4 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar4 = 1;
    do {
      piVar2 = piVar2 + 1;
      iVar6 = *piVar2;
      iVar5 = *(int *)(iVar6 + 0xe4);
      iVar7 = 0;
      for (uVar9 = 1; uVar9 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4); uVar9 = uVar9 + 1) {
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xd0) + 8));
        if ((iVar3 != 0) && (iVar5 != *(int *)(*(int *)(iVar3 + 0xe4) * 4 + *(int *)(param_1 + 8))))
        {
          FUN_000e910c(iVar6,iVar3);
        }
        iVar7 = iVar7 + 4;
      }
      iVar7 = 0;
      for (uVar9 = 1; uVar9 <= *(uint *)(*(int *)(iVar6 + 0xf4) + 4); uVar9 = uVar9 + 1) {
        iVar8 = 0;
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xf4) + 8));
        for (uVar10 = 1; iVar1 = *(int *)(iVar3 + 0xf8), uVar10 <= *(uint *)(iVar1 + 4);
            uVar10 = uVar10 + 1) {
          if (iVar5 != *(int *)(*(int *)(*(int *)(iVar8 + *(int *)(iVar1 + 8)) + 0xe4) * 4 +
                               *(int *)(param_1 + 8))) {
            FUN_000e910c(iVar6);
          }
          iVar8 = iVar8 + 4;
        }
        iVar7 = iVar7 + 4;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(uint *)(param_1 + 0x1c));
  }
  return;
}

/* FUN_000f7f1c @ 0xf7f1c (296 bytes) */
int FUN_000f7f1c(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = uVar4 * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= (uint)param_1[7]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f8044 @ 0xf8044 (296 bytes) */
int FUN_000f8044(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = uVar4 * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= (uint)param_1[7]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f816c @ 0xf816c (576 bytes) */
int FUN_000f816c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  
  *(int *)(param_1[8] + 0x474) = *(int *)(param_1[8] + 0x474) + 1;
  uVar7 = *(undefined4 *)(param_1[9] + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar7,0x14);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar7;
  puVar2[1] = 2;
  puVar2[4] = uVar7;
  puVar2[2] = 0;
  uVar7 = FUN_00193e18(uVar7,8);
  puVar2[3] = uVar7;
  *(undefined4 *)(param_2 + 0xe4) = 1;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[6]) = param_2;
  uVar8 = puVar2[2];
  if (uVar8 < (uint)puVar2[1]) {
    _memset((void *)(uVar8 * 4 + puVar2[3]),0,4);
    puVar2[2] = uVar8 + 1;
    piVar3 = (int *)(uVar8 * 4 + puVar2[3]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar6,uVar8);
  }
  *piVar3 = param_2;
  iVar5 = 2;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[1]) = *(int *)(param_2 + 0xe4);
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[4]) = *(int *)(param_2 + 0xe4);
  while( true ) {
    while( true ) {
      iVar4 = FUN_000e80cc(param_2,*(undefined4 *)(param_1[8] + 0x474));
      if (iVar4 == 0) break;
      uVar8 = puVar2[2];
      if (uVar8 < *puVar6) {
        _memset((void *)(uVar8 * 4 + puVar2[3]),0,4);
        puVar2[2] = uVar8 + 1;
        piVar3 = (int *)(uVar8 * 4 + puVar2[3]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar6,uVar8);
      }
      *piVar3 = iVar4;
      iVar1 = iVar5 * 4;
      *(int *)(iVar4 + 0xe4) = iVar5;
      iVar5 = iVar5 + 1;
      *(undefined4 *)(iVar1 + *param_1) = *(undefined4 *)(param_2 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[6]) = iVar4;
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(param_1[8] + 0x474);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[1]) = *(int *)(iVar4 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[4]) = *(int *)(iVar4 + 0xe4);
      param_2 = iVar4;
    }
    uVar8 = puVar2[2];
    if (uVar8 == 0) break;
    piVar3 = (int *)0x0;
    if (uVar8 - 1 < uVar8) {
      piVar3 = (int *)((uVar8 - 1) * 4 + puVar2[3]);
    }
    param_2 = *piVar3;
    FUN_00194208(puVar6,uVar8 - 1);
  }
  if (puVar6 != (uint *)0x0) {
    FUN_00193cc0(puVar2[4],puVar2[3]);
    FUN_00193cc0(*puVar2,puVar2);
    return;
  }
  return;
}

/* FUN_000f83cc @ 0xf83cc (412 bytes) */
int FUN_000f83cc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  int *piVar10;
  
  uVar9 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar9,0x14);
  puVar8 = puVar3 + 1;
  *puVar3 = uVar9;
  puVar3[1] = 2;
  puVar3[2] = 0;
  puVar3[4] = uVar9;
  uVar9 = FUN_00193e18(uVar9,8);
  puVar3[3] = uVar9;
  iVar7 = *(int *)(param_1 + 0xc);
  while (*(int *)(*(int *)(param_2 * 4 + iVar7) * 4 + iVar7) != 0) {
    uVar2 = puVar3[2];
    if (uVar2 < *puVar8) {
      _memset((void *)(uVar2 * 4 + puVar3[3]),0,4);
      piVar10 = (int *)(uVar2 * 4 + puVar3[3]);
      puVar3[2] = uVar2 + 1;
    }
    else {
      piVar10 = (int *)FUN_0019423c(puVar8,uVar2);
    }
    *piVar10 = param_2;
    iVar7 = *(int *)(param_1 + 0xc);
    param_2 = *(int *)(param_2 * 4 + iVar7);
  }
  while (puVar3[2] != 0) {
    uVar2 = puVar3[2] - 1;
    piVar10 = (int *)0x0;
    if (uVar2 < (uint)puVar3[2]) {
      piVar10 = (int *)(uVar2 * 4 + puVar3[3]);
    }
    iVar7 = *piVar10;
    FUN_00194208(puVar8,puVar3[2] - 1);
    iVar5 = *(int *)(param_1 + 0xc);
    iVar7 = iVar7 * 4;
    iVar6 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(iVar5 + iVar7) * 4;
    iVar4 = *(int *)(iVar6 + iVar1);
    if (*(uint *)(iVar4 * 4 + *(int *)(param_1 + 4)) <
        *(uint *)(*(int *)(iVar7 + iVar6) * 4 + *(int *)(param_1 + 4))) {
      *(int *)(iVar7 + iVar6) = iVar4;
      iVar5 = *(int *)(param_1 + 0xc);
    }
    *(undefined4 *)(iVar7 + iVar5) = *(undefined4 *)(iVar1 + iVar5);
  }
  if (puVar8 == (uint *)0x0) {
    return;
  }
  FUN_00193cc0(puVar3[4],puVar3[3]);
  FUN_00193cc0(*puVar3,puVar3);
  return;
}

/* FUN_000f8588 @ 0xf8588 (72 bytes) */
int FUN_000f8588(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0) {
    ((int (*)())FUN_000f83cc)();
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10));
}

/* FUN_000f85d0 @ 0xf85d0 (740 bytes) */
int FUN_000f85d0(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  
  iVar5 = *(int *)(param_1[8] + 0x3a0);
  if (*(int *)(iVar5 + 0xe4) == 0) {
    iVar4 = *(int *)(param_1[8] + 900);
    for (iVar7 = *(int *)(iVar4 + 8); iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      *(undefined4 *)(iVar4 + 0xe8) = *(undefined4 *)(iVar4 + 0xe4);
      iVar4 = iVar7;
    }
  }
  ((int (*)())FUN_000f816c)(param_1,iVar5);
  FUN_000ec468(param_1[8],param_1[6],param_1[7]);
  uVar6 = param_1[7];
  if (1 < uVar6) {
    iVar4 = uVar6 << 2;
    do {
      iVar8 = 0;
      iVar7 = *(int *)(param_1[6] + iVar4);
      for (uVar11 = 1; iVar2 = *(int *)(iVar7 + 0xd4), uVar11 <= *(uint *)(iVar2 + 4);
          uVar11 = uVar11 + 1) {
        iVar2 = *(int *)(iVar8 + *(int *)(iVar2 + 8));
        if (iVar2 != 0) {
          iVar9 = param_1[1];
          iVar2 = ((int (*)())FUN_000f8588)(param_1,*(undefined4 *)(iVar2 + 0xe4));
          uVar1 = *(uint *)(iVar2 * 4 + iVar9);
          if (uVar1 < *(uint *)(iVar4 + param_1[1])) {
            *(uint *)(iVar4 + param_1[1]) = uVar1;
          }
        }
        iVar8 = iVar8 + 4;
      }
      uVar10 = *(undefined4 *)(param_1[9] + 0x378);
      puVar3 = (undefined4 *)FUN_00193e18(uVar10,0xc);
      *puVar3 = uVar10;
      puVar3[1] = uVar6;
      puVar3[2] = 0;
      puVar3[2] = *(undefined4 *)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]);
      *(undefined4 **)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]) = puVar3 + 1;
      *(undefined4 *)(iVar4 + param_1[3]) = *(undefined4 *)(iVar4 + *param_1);
      for (piVar12 = *(int **)(*(int *)(iVar4 + *param_1) * 4 + param_1[5]); piVar12 != (int *)0x0;
          piVar12 = (int *)piVar12[1]) {
        iVar7 = *piVar12 * 4;
        iVar8 = ((int (*)())FUN_000f8588)(param_1,*piVar12);
        iVar2 = *(int *)(param_1[1] + iVar7);
        if (iVar2 == *(int *)(iVar8 * 4 + param_1[1])) {
          *(int *)(iVar7 + param_1[2]) = iVar2;
        }
        else {
          *(int *)(iVar7 + param_1[2]) = iVar8;
        }
      }
      uVar6 = uVar6 - 1;
      iVar4 = iVar4 + -4;
    } while (1 < uVar6);
  }
  *(undefined4 *)(param_1[2] + 4) = 0;
  uVar6 = param_1[7];
  if (1 < uVar6) {
    uVar11 = 2;
    do {
      iVar4 = uVar11 * 4;
      iVar7 = param_1[2];
      if (*(int *)(iVar4 + iVar7) != *(int *)(iVar4 + param_1[1])) {
        *(undefined4 *)(iVar4 + iVar7) = *(undefined4 *)(*(int *)(iVar4 + iVar7) * 4 + iVar7);
        uVar6 = param_1[7];
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 <= uVar6);
  }
  if (uVar6 != 0) {
    iVar8 = param_1[6];
    iVar7 = 0;
    uVar6 = 1;
    iVar4 = 4;
    while( true ) {
      *(int *)(*(int *)(iVar4 + iVar8) + 0xf0) = iVar7;
      if (iVar7 != 0) {
        FUN_000e8ce4();
      }
      uVar6 = uVar6 + 1;
      if ((uint)param_1[7] < uVar6) break;
      if (uVar6 == 1) {
        iVar8 = param_1[6];
        iVar7 = 0;
        iVar4 = 4;
      }
      else {
        iVar4 = uVar6 * 4;
        iVar8 = param_1[6];
        iVar7 = *(int *)(*(int *)(iVar4 + param_1[2]) * 4 + iVar8);
      }
    }
  }
  ((int (*)())FUN_000f7dbc)(param_1);
  if (*(int *)(iVar5 + 0xe8) == 0) {
    iVar5 = *(int *)(param_1[8] + 900);
    for (iVar4 = *(int *)(*(int *)(param_1[8] + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8))
    {
      *(undefined4 *)(iVar5 + 0xe4) = *(undefined4 *)(iVar5 + 0xe8);
      iVar5 = iVar4;
    }
  }
  return;
}

/* FUN_000f88b4 @ 0xf88b4 (140 bytes) */
int FUN_000f88b4(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x2c);
  *puVar1 = uVar2;
  puVar3 = puVar1 + 1;
  ((int (*)())FUN_000f7cd8)(puVar3,param_1);
  ((int (*)())FUN_000f85d0)(puVar3);
  if (puVar3 == (undefined4 *)0x0) {
    return;
  }
  ((int (*)())FUN_000f8044)(puVar3);
  FUN_00193cc0(*puVar1,puVar1);
  return;
}

/* FUN_000f8960 @ 0xf8960 (16 bytes) */
int FUN_000f8960(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 8);
}

/* FUN_000f8970 @ 0xf8970 (16 bytes) */
int FUN_000f8970(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 4);
}

/* FUN_000f8980 @ 0xf8980 (20 bytes) */
int FUN_000f8980(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + param_1 * 0x24 + param_3 + 0x1c);
}

/* FUN_000f8994 @ 0xf8994 (16 bytes) */
int FUN_000f8994(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0xc);
}

/* FUN_000f89a4 @ 0xf89a4 (16 bytes) */
int FUN_000f89a4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0x10);
}

/* FUN_000f89e8 @ 0xf89e8 (36 bytes) */
int FUN_000f89e8(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  return 2 - (uint)(param_1 == 2);
}

/* FUN_000f8a0c @ 0xf8a0c (36 bytes) */
int FUN_000f8a0c(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  if (param_1 == 2) {
    return 1;
  }
  return 3;
}

/* FUN_000f8a30 @ 0xf8a30 (112 bytes) */
double FUN_000f8a30(int param_1,int param_2,int param_3,int param_4)

{
  undefined *puVar1;
  double dVar2;
  
  puVar1 = PTR_DAT_001e8bb8;
  if (param_1 == 4) {
    dVar2 = (double)FLOAT_001aa0d4;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  if (param_1 == 5) {
    dVar2 = (double)FLOAT_001aa0e8;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  *(undefined1 *)(param_3 + param_2) = 1;
  dVar2 = (double)FLOAT_001aa0d4;
  *(char *)(param_4 + param_2) = (char)*(undefined4 *)(puVar1 + param_1 * 4);
  return dVar2;
}

/* FUN_000f8aa0 @ 0xf8aa0 (488 bytes) */
int FUN_000f8aa0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  uint *param_3;
  int param_4;
  int *param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char local_38 [32];
  
  local_38[0] = '\0';
  local_38[1] = 1;
  local_38[2] = 2;
  local_38[3] = 3;
  uVar3 = *param_2;
  if (param_3 != (uint *)0x0) {
    uVar2 = *param_3;
    if ((uVar2 & 0x400000) != 0) {
      uVar1 = param_3[1];
      if ((uVar1 >> 3 & 1 & uVar1 >> 7 & 1 & uVar1 >> 0xb & 1 & uVar1 >> 0xf & 1) != 0) {
        ((int (*)())FUN_00103d50)(param_5 + param_4 * 6 + 0x23,1,param_5[param_4 * 6 + 0x28] & 1U ^ 1);
        uVar2 = *param_3;
      }
    }
    if (((uVar2 & 0x400000) != 0) && ((param_3[1] & 0x100000) != 0)) {
      ((int (*)())FUN_00103d50)(param_5 + param_4 * 6 + 0x23,2,1);
    }
    local_38[0] = FUN_0019e9fc(param_3,0);
    local_38[1] = FUN_0019e9fc(param_3,1);
    local_38[2] = FUN_0019e9fc(param_3,2);
    local_38[3] = FUN_0019e9fc(param_3,3);
  }
  (**(code **)(*param_5 + 0x88))(param_5,param_4,0,(int)local_38[uVar3 >> 0x18]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,1,(int)local_38[uVar3 >> 0x10 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,2,(int)local_38[uVar3 >> 8 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,3,(int)local_38[uVar3 & 0xff]);
  *param_2 = DAT_001aa9a8;
  return;
}

/* FUN_000f8c88 @ 0xf8c88 (64 bytes) */
int FUN_000f8c88(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + -0x30;
  if ((1 < iVar1) && (iVar1 = 2, param_1 != 0x5f)) {
    iVar1 = param_1 + -0x74;
  }
  return *(undefined4 *)(&DAT_001aa9e4 + iVar1 * 4);
}

/* FUN_000f8ccc @ 0xf8ccc (132 bytes) */
int FUN_000f8ccc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xdc))(*(int **)(param_2 + 0x30c));
  if (iVar1 == 0) {
    puVar2 = (PTR_DAT_001e9f7c)[param_1 * 3];
  }
  else if (param_3 == 0) {
    puVar2 = (PTR_DAT_001e9f80)[param_1 * 3];
  }
  else {
    puVar2 = (PTR_DAT_001e9f78)[param_1 * 3];
  }
  return puVar2;
}

/* FUN_000f8d50 @ 0xf8d50 (568 bytes) */
int FUN_000f8d50(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  undefined *puVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  code *pcVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  undefined4 uStack00000020;
  char local_38 [28];
  
  uStack00000020 = param_3;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  if (param_4 != (uint *)0x0) {
    uVar6 = *param_4;
    if ((uVar6 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3f4) = *(undefined4 *)(param_6 + 0x98);
        *(undefined4 *)(param_1 + 0x3e4) = 1;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x3ac);
      uVar10 = *(undefined4 *)(param_6 + 0x94);
      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar4;
      iVar4 = FUN_00127608(uVar5,0x2a,iVar4,0);
      *(undefined4 *)(iVar4 + 0x30) = uVar10;
      FUN_001046c8(param_6,0,iVar4);
      uVar6 = *param_4;
    }
    if (((uVar6 & 0x400000) != 0) && ((param_4[1] & 0x100) != 0)) {
      piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      pcVar9 = *(code **)(*piVar11 + 0x78);
      uVar5 = FUN_000ec208(param_1,uVar6 >> 0x10 & 0x3f);
      iVar4 = (*pcVar9)(piVar11,uVar5);
      if (iVar4 == 0) {
        iVar4 = FUN_000ec208(param_1,*param_4 >> 0x10 & 0x3f);
        if (iVar4 != 9) {
          FUN_000ec208(param_1,*param_4 >> 0x10 & 0x3f);
        }
      }
      else {
        *(undefined4 *)(param_6 + 0x120) = 1;
      }
    }
    iVar4 = FUN_0019e990(param_4,0);
    puVar1 = PTR_DAT_001e8bc8;
    local_38[0] = (char)*(undefined4 *)(PTR_DAT_001e8bc8 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,1);
    local_38[1] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,2);
    local_38[2] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,3);
    local_38[3] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
  }
  if (param_7 == 0) {
    iVar12 = 4;
    iVar4 = 0;
    pcVar8 = (char *)&STACKARG(0x20);
    do {
      cVar3 = local_38[iVar4];
      if (*pcVar8 != '\0') {
        cVar3 = *pcVar8;
      }
      *(char *)(param_6 + 0x9c) = cVar3;
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
      param_6 = param_6 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  else {
    iVar12 = 4;
    iVar4 = 0;
    puVar7 = (undefined1 *)&STACKARG(0x20);
    do {
      uVar2 = 1;
      if (local_38[iVar4] != '\x01') {
        uVar2 = *puVar7;
      }
      *(undefined1 *)(param_6 + 0x9c) = uVar2;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      param_6 = param_6 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}

/* FUN_000f8f88 @ 0xf8f88 (176 bytes) */
int FUN_000f8f88(param_1, param_2)
  uint *param_1;
  int *param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_001e8bb8;
  iVar4 = 0;
  do {
    iVar3 = FUN_0019e9fc(param_1,iVar4);
    (**(code **)(*param_2 + 0x88))(param_2,1,iVar4,*(undefined4 *)(puVar2 + iVar3 * 4));
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if ((*param_1 & 0x400000) != 0) {
    param_1[1] = param_1[1] & 0xffff8888 | 0x3210;
  }
  return;
}

/* FUN_000f9038 @ 0xf9038 (264 bytes) */
int FUN_000f9038(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  uVar1 = ((int (*)())FUN_001043f0)(0x17,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  iVar2 = FUN_001054ec(uVar1,1);
  dVar3 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  FUN_000f79c4(dVar3,dVar3,dVar3,dVar3,uVar1,param_1,2);
  FUN_00193f64(param_3,uVar1);
  uVar1 = ((int (*)())FUN_001043f0)(0x19,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  iVar2 = FUN_001054ec(uVar1,1);
  dVar3 = (double)FLOAT_001aa0e8;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  FUN_000f79c4(dVar3,dVar3,dVar3,dVar3,uVar1,param_1,2);
  FUN_00193f64(param_3,uVar1);
  return uVar1;
}

/* FUN_000f9140 @ 0xf9140 (284 bytes) */
int FUN_000f9140(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc);
  iVar3 = (**(code **)(param_2 * 0x24 + iVar3 + 0x14))
                    (*(undefined4 *)(param_2 * 0x24 + iVar3),*(int *)(param_1 + 8));
  if ((param_3 != 0) &&
     (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xb0))(), iVar1 != 0)) {
    switch(param_2) {
    case 0x22:
      uVar2 = FUN_00112f54(0xdf);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x23:
      uVar2 = FUN_00112f54(0xde);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x40:
      uVar2 = FUN_00112f54(0xf0);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x41:
      uVar2 = FUN_00112f54(0xb7);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x44:
      uVar2 = FUN_00112f54(0xb8);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x49:
      uVar2 = FUN_00112f54(0xb6);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
    }
  }
  return iVar3;
}

/* FUN_000f92fc @ 0xf92fc (480 bytes) */
int FUN_000f92fc(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2);
  if ((iVar2 != 0) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar3 + 0x168))(piVar3,param_1,param_2), iVar2 != 0)) {
    uVar4 = ((int (*)())FUN_001043f0)(0x13,*(undefined4 *)(param_1 + 8));
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
    iVar2 = FUN_001054ec(uVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
    uVar1 = param_2[0x4d];
    FUN_000f771c(uVar4,param_1,1,uVar1 & 0xffff | 0x60000,uVar1 & 0xffff | 0x70000,
                 uVar1 & 0xffff | 0x70000,uVar1 & 0xffff | 0x70000);
    iVar6 = param_2[0x2b];
    iVar8 = param_2[0x2c];
    iVar2 = FUN_001054ec(uVar4,2);
    *(int *)(iVar2 + 0xc) = iVar8;
    *(int *)(iVar2 + 8) = iVar6;
    ((int (*)())FUN_000f92fc)(param_1,uVar4,param_3);
    iVar2 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar2,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar4 = DAT_001aaa20;
    *(int *)(iVar6 + 8) = iVar5;
    *(undefined4 *)(iVar2 + 0x9c) = uVar4;
    iVar8 = param_2[0x2b];
    iVar7 = param_2[0x2c];
    iVar6 = FUN_001054ec(iVar2,1);
    *(int *)(iVar6 + 8) = iVar8;
    *(int *)(iVar6 + 0xc) = iVar7;
    ((int (*)())FUN_000f92fc)(param_1,iVar2,param_3);
    iVar2 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
  }
  FUN_000e7688(param_3,param_2);
  FUN_000ed63c(param_1,param_2);
                    
                    
  (**(code **)(*param_2 + 8))(param_2,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f94dc @ 0xf94dc (1268 bytes) */
int FUN_000f94dc(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  
  if (*(int *)(param_1 + 0x374) == 0) {
    uVar9 = 0;
    switch(param_7) {
    case 0:
      uVar9 = 1;
      break;
    case 1:
      uVar9 = 2;
      break;
    case 2:
      uVar9 = 3;
      break;
    case 3:
      uVar9 = 4;
      break;
    case 4:
      uVar9 = 6;
    }
    FUN_000e79d0(*(undefined4 *)(param_1 + 0x3a0));
    uVar2 = FUN_000e920c(*(undefined4 *)(param_1 + 0x3a0),0);
    uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x168);
    *puVar3 = uVar14;
    puVar12 = puVar3 + 1;
    FUN_00109cfc(puVar12,0x83,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(puVar12,0);
    *(undefined4 *)(iVar4 + 0xc) = 0x39;
    *(undefined4 *)(iVar4 + 8) = 0;
    uVar1 = uVar9;
    if (3 < uVar9) {
      uVar1 = 3;
    }
    puVar3[0x22] = uVar1;
    puVar10 = (undefined4 *)0x0;
    if (uVar9 != 0) {
      uVar1 = 0;
      iVar4 = 1;
      iVar11 = -2;
      do {
        iVar13 = uVar1 + 2;
        iVar5 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_00130478(param_1,iVar13);
        iVar6 = FUN_001054ec(iVar5,0);
        uVar14 = DAT_001aa9d0;
        *(int *)(iVar6 + 8) = iVar13;
        *(undefined4 *)(iVar6 + 0xc) = 0x10;
        *(undefined4 *)(iVar5 + 0x9c) = uVar14;
        FUN_00130444(param_1,iVar13);
        FUN_00130bd4(param_1,iVar13);
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        uVar14 = (**(code **)(*piVar7 + 0x9c))(piVar7,uVar1);
        iVar6 = FUN_001054ec(iVar5,1);
        *(undefined4 *)(iVar6 + 8) = uVar14;
        *(undefined4 *)(iVar6 + 0xc) = 0x1f;
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar7 + 0xa0))(local_58,piVar7,uVar1);
        uVar14 = local_58[0];
        iVar6 = FUN_001054ec(iVar5,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar14;
        ((int (*)())FUN_000f92fc)(param_1,iVar5,uVar2);
        if ((int)uVar1 < 3) {
          FUN_001046c8(puVar12,iVar4,*(undefined4 *)(iVar5 + 0x8c));
          uVar14 = DAT_001aa9cc;
          if (iVar4 == 0) {
            puVar3[0x28] = DAT_001aa9cc;
          }
          else {
            iVar5 = FUN_001054ec(puVar12,iVar4);
            *(undefined4 *)(iVar5 + 0x10) = uVar14;
          }
        }
        else {
          if (puVar10 == (undefined4 *)0x0) {
            uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            puVar8 = (undefined4 *)FUN_00193e18(uVar14,0x168);
            *puVar8 = uVar14;
            puVar10 = puVar8 + 1;
            FUN_00109cfc(puVar10,0x83,*(undefined4 *)(param_1 + 8));
            iVar6 = FUN_001054ec(puVar10,0);
            *(undefined4 *)(iVar6 + 0xc) = 0x39;
            uVar14 = 4;
            *(undefined4 *)(iVar6 + 8) = 1;
            if (uVar9 == 4) {
              uVar14 = 2;
            }
            puVar8[0x22] = uVar14;
          }
          FUN_001046c8(puVar10,iVar11,*(undefined4 *)(iVar5 + 0x8c));
          uVar14 = DAT_001aa9cc;
          if (iVar11 == 0) {
            puVar10[0x27] = DAT_001aa9cc;
          }
          else {
            iVar5 = FUN_001054ec(puVar10,iVar11);
            *(undefined4 *)(iVar5 + 0x10) = uVar14;
          }
        }
        uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar8 = (undefined4 *)FUN_00193e18(uVar14,0x168);
        *puVar8 = uVar14;
        puVar8 = puVar8 + 1;
        FUN_00109428(puVar8,0x7a,*(undefined4 *)(param_1 + 8));
        iVar5 = FUN_001054ec(puVar8,0);
        *(undefined4 *)(iVar5 + 0xc) = 0x10;
        uVar1 = uVar1 + 1;
        *(int *)(iVar5 + 8) = iVar13;
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + 1;
        ((int (*)())FUN_000f92fc)(param_1,puVar8,*(undefined4 *)(param_1 + 0x3a0));
      } while (uVar9 != uVar1);
    }
    ((int (*)())FUN_000f92fc)(param_1,puVar12,uVar2);
    if (puVar10 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 0x374) = puVar12;
    }
    else {
      uVar14 = 2;
      if (uVar9 != 4) {
        uVar14 = 4;
      }
      FUN_001046c8(puVar10,uVar14,puVar3[0x24]);
      ((int (*)())FUN_000f92fc)(param_1,puVar10,uVar2);
      *(undefined4 **)(param_1 + 0x374) = puVar10;
    }
  }
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar3 = uVar2;
  puVar12 = puVar3 + 1;
  FUN_00109e28(puVar12,0x84,*(undefined4 *)(param_1 + 8));
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3b4) + 1;
  *(int *)(*(int *)(param_1 + 8) + 0x3b4) = iVar5;
  iVar4 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x3a,iVar5,0);
  *(undefined4 *)(iVar4 + 0x30) = 2;
  FUN_001046c8(puVar12,0,iVar4);
  uVar9 = *param_3;
  uVar2 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
  iVar4 = FUN_001054ec(puVar12,1);
  local_68[0] = DAT_001aa9a8;
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(uint *)(iVar4 + 8) = (uint)(ushort)uVar9;
  ((int (*)())FUN_000f8aa0)(param_1,local_68,param_3,1,puVar12);
  puVar3[0x4d] = 1;
  FUN_00193f64(param_2,puVar12);
  iVar4 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
  uVar14 = FUN_000ec208(param_1,param_6);
  iVar11 = FUN_001054ec(iVar4,0);
  uVar2 = DAT_001aa9d0;
  *(undefined4 *)(iVar11 + 0xc) = uVar14;
  *(undefined4 *)(iVar11 + 8) = param_5;
  *(undefined4 *)(iVar4 + 0x9c) = uVar2;
  iVar11 = FUN_001054ec(iVar4,1);
  *(undefined4 *)(iVar11 + 0xc) = 0x3a;
  *(int *)(iVar11 + 8) = iVar5;
  FUN_001049e8(iVar4,*(undefined4 *)(*(int *)(param_1 + 0x374) + 0x8c),*(undefined4 *)(param_1 + 8))
  ;
  FUN_00193f64(param_2,iVar4);
  return;
}

/* FUN_000f9a58 @ 0xf9a58 (3748 bytes) */
int FUN_000f9a58(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  bool bVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  int *piVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  double dVar22;
  undefined4 local_68;
  undefined4 local_64 [7];
  
  iVar7 = (int)(short)*param_3;
  uVar9 = *param_3 >> 0x10 & 0x3f;
  if (((*param_3 & 0x400000) == 0) || (uVar12 = param_3[1] >> 9 & 0xf, uVar12 == 0)) {
    iVar2 = 0;
    iVar19 = 0;
  }
  else {
    iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
    *(short *)((int)param_3 + 2) = (short)iVar19;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    iVar2 = ((int (*)())FUN_001043f0)(0x13,*(undefined4 *)(param_1 + 8));
    iVar3 = FUN_001054ec(iVar2,0);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar19;
    iVar3 = FUN_001054ec(iVar2,1);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    dVar22 = (double)*(float *)(&DAT_001aa9fc + uVar12 * 4);
    *(int *)(iVar3 + 8) = iVar19;
    FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,iVar2,param_1,2);
    FUN_00193f64(param_2,iVar2);
  }
  uVar12 = 0;
  uVar16 = 0;
  do {
    iVar3 = FUN_0019e990(param_3,uVar16);
    bVar1 = uVar16 != 3;
    uVar12 = uVar12 | (uint)(iVar3 == 2) << (uVar16 & 0x3f);
    uVar16 = uVar16 + 1;
  } while (bVar1);
  if (uVar12 != 0) {
    if (iVar2 == 0) {
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
      *(short *)((int)param_3 + 2) = (short)iVar19;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    iVar2 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    iVar3 = FUN_001054ec(iVar2,0);
    dVar22 = (double)FLOAT_001aa0d4;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar19;
    FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,iVar2,param_1,1);
    iVar21 = 4;
    uVar16 = 0;
    iVar3 = iVar2;
    do {
      if (((int)uVar12 >> (uVar16 & 0x3f) & 1U) == 0) {
        *(undefined1 *)(iVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar3 + 0x9c) = 0;
      }
      uVar16 = uVar16 + 1;
      iVar3 = iVar3 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
    FUN_00193f64(param_2,iVar2);
  }
  uVar12 = 0;
  uVar16 = 0;
  do {
    iVar3 = FUN_0019e990(param_3,uVar16);
    bVar1 = uVar16 != 3;
    uVar12 = uVar12 | (uint)(iVar3 == 3) << (uVar16 & 0x3f);
    uVar16 = uVar16 + 1;
  } while (bVar1);
  if (uVar12 != 0) {
    if (iVar2 == 0) {
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
      *(short *)((int)param_3 + 2) = (short)iVar19;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    iVar2 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    iVar3 = FUN_001054ec(iVar2,0);
    dVar22 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar19;
    FUN_000f79c4(dVar22,dVar22,dVar22,dVar22,iVar2,param_1,1);
    iVar21 = 4;
    uVar16 = 0;
    iVar3 = iVar2;
    do {
      if (((int)uVar12 >> (uVar16 & 0x3f) & 1U) == 0) {
        *(undefined1 *)(iVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar3 + 0x9c) = 0;
      }
      uVar16 = uVar16 + 1;
      iVar3 = iVar3 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
    FUN_00193f64(param_2,iVar2);
  }
  uVar12 = DAT_001aa9dc;
  if ((*param_3 & 0x400000) != 0) {
    uVar12 = param_3[1];
    uVar12 = (uint)((uVar12 & 0xc0) == 0) |
             (uint)((uVar12 & 0x30) == 0) << 8 |
             (uint)((uVar12 & 0xc) == 0) << 0x10 | (uint)((uVar12 & 3) == 0) << 0x18;
  }
  iVar3 = FUN_0019eb30(param_3);
  if (iVar3 != 0) {
    iVar2 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    iVar3 = FUN_001054ec(iVar2,0);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar19;
    iVar3 = FUN_001054ec(iVar2,1);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar19;
    FUN_00193f64(param_2,iVar2);
  }
  uVar16 = *param_3;
  if (((uVar16 & 0x400000) == 0) || ((param_3[1] & 0x100) == 0)) {
LAB_000f9f08:
    bVar1 = false;
  }
  else {
    piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    pcVar13 = *(code **)(*piVar17 + 0x78);
    uVar4 = FUN_000ec208(param_1,uVar9);
    iVar3 = (*pcVar13)(piVar17,uVar4);
    if (iVar3 == 0) {
      iVar19 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      if (iVar19 == 9) {
        uVar16 = *param_3;
        goto LAB_000f9f08;
      }
      FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      uVar16 = *param_3;
      bVar1 = false;
    }
    else {
      iVar3 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x80))();
      if (iVar3 == 0) {
        if (iVar2 == 0) {
          iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
          *(short *)((int)param_3 + 2) = (short)iVar19;
          *param_3 = *param_3 & 0xffc0ffff | 0x40000;
        }
        iVar2 = ((int (*)())FUN_000f9038)(param_1,iVar19,param_2);
        uVar16 = *param_3;
        if ((uVar16 & 0x400000) == 0) goto LAB_000f9f08;
        bVar1 = false;
        param_3[1] = param_3[1] & 0xfffffeff;
      }
      else {
        uVar16 = *param_3;
        bVar1 = true;
      }
    }
  }
  if (iVar2 != 0) {
    if ((uVar16 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        uVar4 = FUN_000ec208(param_1,uVar9);
        *(undefined4 *)(param_1 + 0x3f4) = uVar4;
      }
      else {
        FUN_000ec208(param_1,uVar9);
      }
      uVar4 = *(undefined4 *)(param_1 + 0x3ac);
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar19;
      iVar19 = FUN_00127608(uVar4,0x2a,iVar19,0);
      *(int *)(iVar19 + 0x30) = iVar7;
      FUN_001046c8(iVar2,0,iVar19);
      *param_3 = *param_3 & 0xfe7fffff;
    }
    else {
      uVar4 = FUN_000ec208(param_1,uVar9);
      iVar19 = FUN_001054ec(iVar2,0);
      *(undefined4 *)(iVar19 + 0xc) = uVar4;
      *(int *)(iVar19 + 8) = iVar7;
    }
    if (bVar1) {
      *(undefined4 *)(iVar2 + 0x120) = 1;
    }
    if ((*param_3 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xfffffeff;
    }
    iVar19 = 0;
    do {
      iVar3 = FUN_0019e990(param_3,iVar19);
      if (iVar3 == 0) {
        *(undefined1 *)(iVar2 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar2 + 0x9c) = 0;
      }
      bVar1 = iVar19 != 3;
      iVar2 = iVar2 + 1;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    uVar16 = *param_3;
    if ((uVar16 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xffffff00 | 0x55;
    }
  }
  if ((uVar9 != 0x1f) || ((*(uint *)(param_1 + 0x30) & 0x4000) == 0)) {
    bVar1 = false;
    bVar6 = false;
  }
  else {
    bVar1 = true;
    bVar6 = true;
  }
  if (((undefined4 *)(uVar16 & 0x3f0000) != &DAT_001b0000) && (!bVar1)) goto LAB_000fa744;
  iVar2 = 1;
  iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
  uVar16 = *param_3;
  uVar11 = (uint)(ushort)*param_3;
  uVar10 = uVar16 >> 0x10 & 0x3f;
  if ((int)uVar16 < 0) {
    iVar2 = 2;
    uVar11 = uVar11 | param_3[1] << 0x10;
  }
  if ((uVar16 & 0x400000) != 0) {
    iVar2 = iVar2 + 1;
  }
  if ((uVar16 & 0x1800000) == 0x1000000) {
    puVar8 = param_3 + iVar2;
    if (!bVar6) {
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar5 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar5 = uVar4;
      puVar20 = puVar5 + 1;
      FUN_001071fc(puVar20,0xfc,*(undefined4 *)(param_1 + 8));
      uVar4 = FUN_000ec208(param_1,uVar10);
      iVar3 = FUN_001054ec(puVar20,0);
      *(undefined4 *)(iVar3 + 0xc) = uVar4;
      *(uint *)(iVar3 + 8) = uVar11;
      uVar4 = FUN_000ec208(param_1,4);
      iVar3 = FUN_001054ec(puVar20,1);
      puVar5[0x28] = uVar12;
      *(undefined4 *)(iVar3 + 0xc) = uVar4;
      *(int *)(iVar3 + 8) = iVar19;
      if ((*param_3 & 0x4000000) == 0) goto LAB_000fa1bc;
      iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
      uVar16 = param_3[iVar2 + 2];
      uVar4 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(param_1 + 8));
      uVar15 = FUN_000ec208(param_1,4);
      iVar2 = FUN_001054ec(uVar4,0);
      *(undefined4 *)(iVar2 + 0xc) = uVar15;
      *(int *)(iVar2 + 8) = iVar3;
      uVar12 = *puVar8;
      uVar15 = FUN_000ec208(param_1,*puVar8 >> 0x10 & 0x3f);
      iVar2 = FUN_001054ec(uVar4,1);
      *(undefined4 *)(iVar2 + 0xc) = uVar15;
      *(uint *)(iVar2 + 8) = (uint)(ushort)uVar12;
      FUN_000f7870(uVar4,param_1,2,uVar16,uVar16,uVar16,uVar16);
      FUN_00193f64(param_2,uVar4);
      uVar4 = FUN_000ec208(param_1,4);
      iVar2 = FUN_001054ec(puVar20,2);
      *(undefined4 *)(iVar2 + 0xc) = uVar4;
      *(int *)(iVar2 + 8) = iVar3;
    }
    else {
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar5 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar5 = uVar4;
      puVar20 = puVar5 + 1;
      FUN_00108a50(puVar20,0xf9,*(undefined4 *)(param_1 + 8));
      puVar5[0x28] = uVar12;
      puVar5[0x22] = 2;
      if ((*param_3 & 0x4000000) != 0) {
        uVar11 = uVar11 + param_3[iVar2 + 2];
      }
      puVar5[0x51] = uVar11;
      puVar5[0x50] = 0x24;
      uVar4 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar20,0,uVar4);
      iVar2 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(int *)(iVar2 + 8) = iVar19;
LAB_000fa1bc:
      uVar12 = *puVar8;
      uVar4 = FUN_000ec208(param_1,*puVar8 >> 0x10 & 0x3f);
      iVar2 = FUN_001054ec(puVar20,2);
      *(undefined4 *)(iVar2 + 0xc) = uVar4;
      *(uint *)(iVar2 + 8) = (uint)(ushort)uVar12;
      if (bVar6) goto LAB_000fa4f8;
    }
    uVar4 = FUN_000ec208(param_1,uVar10);
    iVar2 = FUN_001054ec(puVar20,3);
    local_64[0] = DAT_001aa9a8;
    *(undefined4 *)(iVar2 + 0xc) = uVar4;
    *(uint *)(iVar2 + 8) = uVar11;
    ((int (*)())FUN_000f8aa0)(param_1,local_64,puVar8,2,puVar20);
  }
  else if ((uVar16 & 0x1800000) == 0) {
    uVar14 = 0;
    if ((uVar16 & 0x4000000) != 0) {
      uVar14 = param_3[iVar2];
    }
    if (bVar6) {
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar5 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar5 = uVar4;
      puVar20 = puVar5 + 1;
      FUN_00108770(puVar20,*(undefined4 *)(param_1 + 8));
      puVar5[0x28] = uVar12;
      puVar5[0x50] = 0x24;
      puVar5[0x51] = uVar11;
      uVar4 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar20,0,uVar4);
      iVar2 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(int *)(iVar2 + 8) = iVar19;
    }
    else {
      uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar5 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar5 = uVar4;
      puVar20 = puVar5 + 1;
      FUN_001071fc(puVar20,0xfc,*(undefined4 *)(param_1 + 8));
      uVar4 = FUN_000ec208(param_1,uVar10);
      iVar2 = FUN_001054ec(puVar20,0);
      *(undefined4 *)(iVar2 + 0xc) = uVar4;
      *(uint *)(iVar2 + 8) = uVar11;
      uVar4 = FUN_000ec208(param_1,4);
      iVar2 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar2 + 0xc) = uVar4;
      *(int *)(iVar2 + 8) = iVar19;
      FUN_000f7870(puVar20,param_1,2,uVar14,uVar14,uVar14,uVar14);
      puVar5[0x28] = uVar12;
    }
  }
  else {
    puVar20 = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  iVar2 = FUN_001054ec(puVar20,2);
  local_68 = *(undefined4 *)(iVar2 + 0x10);
  piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar2 = (**(code **)(*piVar17 + 0x104))(piVar17,puVar20,2,&local_68,0);
  if (iVar2 == 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
    uVar4 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    uVar18 = puVar20[0x32];
    uVar15 = puVar20[0x31];
    iVar2 = FUN_001054ec(uVar4,1);
    *(undefined4 *)(iVar2 + 0xc) = uVar18;
    *(undefined4 *)(iVar2 + 8) = uVar15;
    uVar15 = FUN_000ec208(param_1,4);
    iVar2 = FUN_001054ec(uVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = uVar15;
    *(int *)(iVar2 + 8) = iVar3;
    iVar2 = FUN_001054ec(puVar20,2);
    uVar15 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = FUN_001054ec(uVar4,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar15;
    FUN_00193f64(param_2,uVar4);
    uVar4 = FUN_000ec208(param_1,4);
    iVar2 = FUN_001054ec(puVar20,2);
    *(undefined4 *)(iVar2 + 0xc) = uVar4;
    *(int *)(iVar2 + 8) = iVar3;
    uVar4 = DAT_001aa9cc;
    iVar2 = FUN_001054ec(puVar20,2);
    *(undefined4 *)(iVar2 + 0x10) = uVar4;
  }
  if ((!bVar6) &&
     (piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar17 + 0x104))(piVar17,puVar20,1,&local_68,0), iVar2 == 0)) {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
    uVar4 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    uVar18 = puVar20[0x2c];
    uVar15 = puVar20[0x2b];
    iVar2 = FUN_001054ec(uVar4,1);
    *(undefined4 *)(iVar2 + 0xc) = uVar18;
    *(undefined4 *)(iVar2 + 8) = uVar15;
    uVar15 = FUN_000ec208(param_1,4);
    iVar2 = FUN_001054ec(uVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = uVar15;
    *(int *)(iVar2 + 8) = iVar3;
    iVar2 = FUN_001054ec(puVar20,1);
    uVar15 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = FUN_001054ec(uVar4,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar15;
    FUN_00193f64(param_2,uVar4);
    uVar4 = FUN_000ec208(param_1,4);
    iVar2 = FUN_001054ec(puVar20,1);
    *(undefined4 *)(iVar2 + 0xc) = uVar4;
    *(int *)(iVar2 + 8) = iVar3;
    uVar4 = DAT_001aa9a8;
    iVar2 = FUN_001054ec(puVar20,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar4;
  }
  FUN_00193f64(param_2,puVar20);
  *param_3 = *param_3 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 2) = (short)iVar19;
LAB_000fa744:
  if ((uVar9 == 0x1f) && ((*(uint *)(param_1 + 0x30) & 0x200000) != 0)) {
    iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar3;
    uVar15 = ((int (*)())FUN_001043f0)(0xcc,*(undefined4 *)(param_1 + 8));
    iVar2 = FUN_001054ec(uVar15,0);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar3;
    iVar2 = FUN_001054ec(uVar15,1);
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0x1f;
    uVar4 = DAT_001aa9b0;
    iVar2 = FUN_001054ec(uVar15,1);
    *(undefined4 *)(iVar2 + 0x10) = uVar4;
    if (param_5 == 1) {
      FUN_000f7870(uVar15,param_1,2,1,1,1,1);
    }
    else if (param_5 < 2) {
      if (param_5 == 0) {
        FUN_000f7870(uVar15,param_1,2,0,0,0,0);
      }
    }
    else if (param_5 == 2) {
      FUN_000f7870(uVar15,param_1,2,2,2,2,2);
    }
    else if (param_5 == 3) {
      FUN_000f7870(uVar15,param_1,2,3,3,3,3);
    }
    FUN_00193f64(param_2,uVar15);
    uVar4 = ((int (*)())FUN_001043f0)(0x24,*(undefined4 *)(param_1 + 8));
    uVar15 = FUN_000ec208(param_1,0x1f);
    iVar2 = FUN_001054ec(uVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = uVar15;
    *(int *)(iVar2 + 8) = iVar7;
    iVar2 = FUN_001054ec(uVar4,1);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar3;
    uVar15 = FUN_000ec208(param_1,4);
    iVar2 = FUN_001054ec(uVar4,2);
    *(undefined4 *)(iVar2 + 0xc) = uVar15;
    *(int *)(iVar2 + 8) = iVar19;
    uVar15 = FUN_000ec208(param_1,0x1f);
    iVar2 = FUN_001054ec(uVar4,3);
    *(undefined4 *)(iVar2 + 0xc) = uVar15;
    *(int *)(iVar2 + 8) = iVar7;
    FUN_00193f64(param_2,uVar4);
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_3 + 2) = (short)iVar19;
  }
  return;
}

/* FUN_000fa958 @ 0xfa958 (1132 bytes) */
int FUN_000fa958(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 local_48;
  undefined4 local_44;
  
  uVar11 = *(uint *)(PTR_DAT_001e8b88 + param_2 * 4);
  if (param_3 != 0) {
    uVar8 = uVar11 >> 0x1c & 1;
LAB_000fabd8:
    if (uVar8 == 0) {
      puVar5 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                         *(int *)(param_4 + 0x6c));
      puVar10 = puVar5;
    }
    else {
      puVar5 = (uint *)0x0;
      puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                          *(int *)(param_4 + 100));
      local_44 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_44) + 0)),(short)*puVar10);
      local_44 = *puVar10 & 0x1800000 | *puVar10 & 0x3f0000 | local_44 & 0xfe40ffff;
      puVar10 = &local_44;
    }
    uVar8 = *puVar10 >> 0x10 & 0x3f;
    iVar3 = *(int *)(param_1 + 8);
    if ((((*puVar10 & 0x3f0000) == 0x100000) && (iVar3 != 0)) &&
       ((*(uint *)(*(int *)(iVar3 + 0x30c) + 8) & 0x80) != 0)) {
      iVar7 = 0xf;
    }
    else {
      iVar7 = (int)(short)*puVar10;
    }
    if ((uVar8 == 0x12) && ((uVar11 & 0x3800000) != 0)) {
      iVar7 = 0;
      uVar8 = 0x13;
    }
    if (((uVar11 >> 0x1b & 1) == 0) && ((uVar8 == 1 || (uVar8 == 0x22)))) {
      iVar1 = *(int *)(iVar3 + 0x3ac) + -1;
      *(int *)(iVar3 + 0x3ac) = iVar1;
      uVar2 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      iVar3 = FUN_001054ec(uVar2,0);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(int *)(iVar3 + 8) = iVar1;
      uVar9 = FUN_000ec208(param_1,uVar8);
      iVar3 = FUN_001054ec(uVar2,1);
      *(undefined4 *)(iVar3 + 0xc) = uVar9;
      *(int *)(iVar3 + 8) = iVar7;
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar10,param_3,uVar2);
      ((int (*)())FUN_000f92fc)(param_1,uVar2,in_stack_00000040);
      uVar8 = 4;
      *puVar10 = *puVar10 & 0xfe3fffff;
      *(short *)((int)puVar10 + 2) = (short)iVar1;
      *puVar10 = *puVar10 & 0xffc0ffff | 0x40000;
      iVar7 = iVar1;
    }
    else {
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar5,param_3,param_5);
    }
    uVar2 = FUN_000ec208(param_1,uVar8);
    iVar3 = FUN_001054ec(param_5,param_3);
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    *(int *)(iVar3 + 8) = iVar7;
    return 0;
  }
  uVar8 = 0;
  if ((uVar11 >> 0x1c & 1) == 0) goto LAB_000fabd8;
  puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 + *(int *)(param_4 + 100));
  iVar7 = (int)(short)*puVar10;
  uVar8 = *puVar10 >> 0x10 & 0x3f;
  uVar2 = FUN_000ec208(param_1,uVar8);
  iVar3 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  *(int *)(iVar3 + 8) = iVar7;
  ((int (*)())FUN_000f8d50)(param_1,in_stack_00000038,param_7,puVar10,0,param_5,in_stack_0000003c);
  iVar3 = FUN_00113734(*(undefined4 *)(param_1 + 8),param_5);
  if (iVar3 != 0) {
    iVar4 = FUN_001054ec(param_5,0);
    iVar6 = 0;
    iVar3 = 0;
    iVar1 = 0;
    local_48 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = 4;
    do {
      if (*(char *)((int)&local_48 + iVar1) == '\0') {
        iVar6 = iVar6 + 1;
        iVar3 = iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (1 < iVar6) {
      local_44 = DAT_001aa9e0;
      *(undefined1 *)((int)&local_44 + iVar3) = 0;
      uVar9 = *(undefined4 *)(iVar3 * 4 + 0x1dc7bc);
      iVar3 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,0);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      *(undefined4 *)(iVar3 + 0x9c) = local_48;
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar9;
      *(uint *)(param_5 + 0x9c) = local_44;
      goto LAB_000fab1c;
    }
  }
  iVar3 = 0;
LAB_000fab1c:
  if ((uVar11 >> 0x1a & 1) != 0) {
    return iVar3;
  }
  iVar4 = FUN_001054ec(param_5,0);
  iVar1 = DAT_001aa9dc;
  if (*(int *)(iVar4 + 0x10) == DAT_001aa9dc) {
    return iVar3;
  }
  iVar3 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
  uVar2 = FUN_000ec208(param_1,uVar8);
  iVar4 = FUN_001054ec(iVar3,0);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(int *)(iVar4 + 8) = iVar7;
  iVar7 = FUN_001054ec(iVar3,1);
  *(undefined4 *)(iVar7 + 0xc) = 0;
  *(int *)(iVar7 + 8) = iVar6;
  iVar7 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar7 + 0xc) = 0;
  *(int *)(iVar7 + 8) = iVar6;
  iVar7 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar7 + 0x10);
  *(int *)(param_5 + 0x9c) = iVar1;
  return iVar3;
}

/* FUN_000fadc4 @ 0xfadc4 (448 bytes) */
int FUN_000fadc4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  uint *param_5;
  int param_6;
  undefined4 param_7;
{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_48 [8];
  
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar7,0x15c);
  *puVar3 = uVar7;
  puVar6 = puVar3 + 1;
  FUN_000ea6d0(puVar6,param_2,param_4,0,*(undefined4 *)(param_1 + 8));
  FUN_000e78c0(puVar6,param_3);
  local_48[0] = DAT_001aa9a8;
  ((int (*)())FUN_000fa958)(param_1,5,1,param_7,param_2,1,DAT_001aa9dc,local_48);
  iVar4 = FUN_001054ec(param_2,1);
  iVar2 = 0;
  iVar9 = 4;
  (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0)) = (undefined1)((uint)*(undefined4 *)(iVar4 + 0x10) >> 0x18);
  uVar1 = (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0));
  local_48[0] = *(undefined4 *)(iVar4 + 0x10);
  do {
    *(undefined1 *)((int)local_48 + iVar2) = uVar1;
    uVar7 = local_48[0];
    iVar2 = iVar2 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar2 = FUN_001054ec(param_2,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar7;
  FUN_000ed63c(param_1,param_2);
  uVar8 = 0;
  if (param_5[1] != 0) {
    puVar3[0x53] = 0;
    uVar8 = param_5[1];
  }
  if (uVar8 < *param_5) {
    _memset((void *)(uVar8 * 4 + param_5[2]),0,4);
    piVar5 = (int *)(uVar8 * 4 + param_5[2]);
    param_5[1] = uVar8 + 1;
  }
  else {
    piVar5 = (int *)FUN_0019423c(param_5,uVar8);
  }
  *piVar5 = (int)puVar6;
  uVar8 = *(uint *)(param_6 + 4);
  if (uVar8 != 0) {
    piVar5 = (int *)0x0;
    if (uVar8 - 1 < uVar8) {
      piVar5 = (int *)((uVar8 - 1) * 4 + *(int *)(param_6 + 8));
    }
    *(int *)(*piVar5 + 300) = *(int *)(*piVar5 + 300) + 1;
  }
  return puVar6;
}

/* FUN_000fafa4 @ 0xfafa4 (652 bytes) */
int FUN_000fafa4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar8 = *(undefined4 *)(param_1 + 0x3ac);
  uVar3 = FUN_000ec208();
  iVar4 = FUN_00127608(uVar8,uVar3,param_3,0);
  piVar5 = *(int **)(iVar4 + 0x18);
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
  iVar4 = *(int *)(param_1 + 0x3ac);
  iVar6 = *piVar5;
  puVar7 = *(uint **)(iVar4 + 0x20);
  uVar9 = puVar7[1];
  if (uVar9 < *puVar7) {
    _memset((void *)(uVar9 * 4 + puVar7[2]),0,4);
    piVar5 = (int *)(uVar9 * 4 + puVar7[2]);
    puVar7[1] = uVar9 + 1;
  }
  else {
    piVar5 = (int *)FUN_0019423c(puVar7,uVar9);
  }
  *piVar5 = iVar6;
  *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
  if (param_2 == 1) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 2;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_4 < 1) {
        bVar2 = *(byte *)(iVar6 + 0x15c);
      }
      else {
        uVar9 = 0;
        iVar4 = iVar6;
        do {
          uVar3 = *param_5;
          *(undefined4 *)(iVar4 + 0x1c) = 4;
          *(undefined4 *)(iVar4 + 0x20) = uVar3;
          uVar1 = uVar9 & 0x3f;
          uVar9 = uVar9 + 1;
          iVar4 = iVar4 + 0x18;
          bVar2 = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
          *(byte *)(iVar6 + 0x15c) = bVar2;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      uVar3 = *(undefined4 *)(iVar6 + 0x20);
      *(undefined4 *)(iVar6 + 100) = 4;
      *(byte *)(iVar6 + 0x15c) = bVar2 | 0xe;
      *(undefined4 *)(iVar6 + 0x68) = uVar3;
      *(undefined4 *)(iVar6 + 0x38) = uVar3;
      *(undefined4 *)(iVar6 + 0x50) = uVar3;
      *(undefined4 *)(iVar6 + 0x34) = 4;
      *(undefined4 *)(iVar6 + 0x4c) = 4;
    }
  }
  else if (param_2 == 2) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 3;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if ((param_2 == 0x1d) && (0 < param_4)) {
    uVar9 = 0;
    iVar4 = iVar6;
    do {
      uVar3 = param_5[uVar9];
      *(undefined4 *)(iVar4 + 0x1c) = 3;
      *(undefined4 *)(iVar4 + 0x20) = uVar3;
      uVar1 = uVar9 & 0x3f;
      uVar9 = uVar9 + 1;
      iVar4 = iVar4 + 0x18;
      *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

/* FUN_000fb230 @ 0xfb230 (420 bytes) */
int FUN_000fb230(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  uVar2 = *(uint *)(param_1 + 0x30) & 1 | *(uint *)(param_1 + 0x30) >> 0xe & 1;
  iVar1 = FUN_000d9fc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da070(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,1,&local_48);
      FUN_000e4724(param_2,iVar4,local_48 != 0);
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,0,iVar4,1,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9fa0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da028(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_48);
      FUN_000e4450(param_2,iVar4,local_48,local_44,local_40,local_3c);
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,2,iVar4,4,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9f80(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000d9fe0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_38);
      ((void (*)())FUN_000e4780)((double)local_38,(double)local_34,(double)local_30,(double)local_2c,param_2,iVar4
                  );
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,1,iVar4,4,&local_38);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  return;
}

/* FUN_000fb3d4 @ 0xfb3d4 (8428 bytes) */
int FUN_000fb3d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  int param_5;
  uint *param_6;
  int param_7;
{
  undefined2 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  uint *puVar20;
  uint *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint *puVar26;
  uint *puVar27;
  uint uVar28;
  uint uVar29;
  undefined4 *puVar30;
  uint uVar31;
  uint uVar32;
  undefined4 uVar33;
  code *pcVar34;
  undefined8 uVar35;
  undefined8 uVar36;
  undefined8 uVar37;
  double dVar38;
  undefined8 uVar39;
  undefined4 local_98;
  undefined4 local_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  
  uVar39 = FUN_001a3264();
  iVar18 = (int)((ulonglong)uVar39 >> 0x20);
  uVar19 = (undefined4)uVar39;
  uVar23 = *param_4;
  uVar24 = uVar23 >> 0x16 & 1;
  iVar22 = *(int *)(iVar18 + 8);
  if ((((uVar23 & 0x3f0000) == 0x100000) && (iVar22 != 0)) &&
     ((*(uint *)(*(int *)(iVar22 + 0x30c) + 8) & 0x80) != 0)) {
    uVar32 = 0xf;
  }
  else {
    uVar32 = (uint)(short)*param_4;
  }
  uVar25 = uVar23 >> 0x10 & 0x3f;
  uVar28 = uVar32;
  if ((uVar23 & 0x1800000) == 0x800000) {
    iVar6 = 8;
    if (uVar24 == 0) {
      iVar6 = 4;
    }
    uVar23 = *(uint *)(iVar6 + (int)param_4);
    uVar1 = *(undefined2 *)((int)param_4 + iVar6 + 2);
    if ((uVar23 & 0x10000) == 0) {
      uVar28 = *(int *)(iVar22 + 0x3b4) + 1;
      *(uint *)(iVar22 + 0x3b4) = uVar28;
      iVar22 = FUN_00127608(*(undefined4 *)(iVar18 + 0x3ac),0x26,uVar28,0);
      *(uint *)(iVar22 + 0x30) = uVar32;
      uVar9 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x374);
      puVar10 = (undefined4 *)FUN_00193e18(uVar9,0x168);
      *puVar10 = uVar9;
      puVar30 = puVar10 + 1;
      FUN_00109e28(puVar30,0x84,*(undefined4 *)(iVar18 + 8));
      FUN_001046c8(puVar30,0,iVar22);
      uVar25 = 0x22;
      iVar22 = FUN_00127608(*(undefined4 *)(iVar18 + 0x3ac),0x25,uVar1,0);
      FUN_001046c8(puVar30,1,iVar22);
      uVar9 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar23 >> 0x11 & 7) * 4);
      iVar6 = FUN_001054ec(puVar30,1);
      *(undefined4 *)(iVar6 + 0x10) = uVar9;
      puVar10[0x4c] = *(undefined4 *)(iVar22 + 0x30);
      FUN_00193f64(uVar19,puVar30);
    }
    else {
      piVar8 = (int *)0x0;
      uVar23 = *(uint *)(param_5 + 4) - 1;
      if (uVar23 < *(uint *)(param_5 + 4)) {
        piVar8 = (int *)(uVar23 * 4 + *(int *)(param_5 + 8));
      }
      iVar22 = *piVar8;
      *(undefined4 *)(iVar22 + 0x140) = 1;
      uVar9 = FUN_000e7d5c(iVar22);
      uVar9 = FUN_00127608(*(undefined4 *)(iVar18 + 0x3ac),0x27,uVar9,0);
      if (uVar25 == 1) {
        uVar28 = *(int *)(*(int *)(iVar18 + 8) + 0x3b8) + 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3b8) = uVar28;
        iVar6 = FUN_00127608(*(undefined4 *)(iVar18 + 0x3ac),0x28,uVar28,0);
        *(uint *)(iVar6 + 0x30) = uVar32;
        uVar33 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x374);
        puVar10 = (undefined4 *)FUN_00193e18(uVar33,0x168);
        *puVar10 = uVar33;
        puVar10 = puVar10 + 1;
        FUN_0010502c(puVar10,0x82,*(undefined4 *)(iVar18 + 8));
        FUN_001046c8(puVar10,0,iVar6);
        FUN_001046c8(puVar10,1,uVar9);
        uVar25 = 0x23;
        FUN_000e7688(iVar22,puVar10);
        FUN_0012306c(iVar6,puVar10);
        FUN_001236e4(uVar9,1,puVar10);
      }
      else {
        if ((*(uint *)(iVar18 + 0x30) & 1) == 0) {
          if ((*(uint *)(iVar18 + 0x30) & 0x2000) != 0) {
            if (*(int *)(iVar18 + 0x3e4) == 0) {
              *(undefined4 *)(iVar18 + 0x3e4) = 1;
              uVar33 = FUN_000ec208(iVar18,uVar25);
              *(undefined4 *)(iVar18 + 0x3f4) = uVar33;
            }
            else {
              FUN_000ec208(iVar18,uVar25);
            }
          }
        }
        else {
          *(undefined4 *)(iVar18 + 0x3d4) = 1;
        }
        uVar28 = *(int *)(*(int *)(iVar18 + 8) + 0x3bc) + 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3bc) = uVar28;
        uVar11 = *(undefined4 *)(iVar18 + 0x3ac);
        uVar33 = FUN_000ec208(iVar18,0x24);
        iVar6 = FUN_00127608(uVar11,uVar33,uVar28,0);
        *(uint *)(iVar6 + 0x30) = uVar32;
        uVar33 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x374);
        puVar10 = (undefined4 *)FUN_00193e18(uVar33,0x168);
        *puVar10 = uVar33;
        puVar10 = puVar10 + 1;
        FUN_0010502c(puVar10,0x82,*(undefined4 *)(iVar18 + 8));
        FUN_001046c8(puVar10,0,iVar6);
        FUN_001046c8(puVar10,1,uVar9);
        uVar25 = 0x24;
        FUN_000e7688(iVar22,puVar10);
        FUN_0012306c(iVar6,puVar10);
        FUN_001236e4(uVar9,1,puVar10);
      }
    }
    uVar23 = *param_4 & 0xfe7fffff;
    *param_4 = uVar23;
  }
  if (((uVar23 & 0x3f0000) == 0x1c0000) &&
     ((*(uint *)(*(int *)(*(int *)(iVar18 + 8) + 0x30c) + 8) & 8) == 0)) {
    *param_4 = uVar23 & 0xffc0ffff | 0x10000;
    puVar20 = param_4;
    if ((uVar23 & 0x400000) != 0) {
      puVar20 = param_4 + 1;
    }
    bVar4 = false;
    *(short *)((int)param_4 + 2) = (short)puVar20[1];
    uVar23 = *param_4 & 0xfbffffff;
    *param_4 = uVar23;
  }
  else {
    bVar4 = true;
  }
  if ((uVar25 == 0x20) && (bVar3 = true, (uVar23 & 0x1800000) == 0x1000000)) {
LAB_000fb800:
    uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
    *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
    uVar23 = *param_4;
    uVar31 = uVar23 >> 0x10 & 0x3f;
    if (!bVar3) {
      uVar9 = 0xfe;
      if (uVar31 != 0x1c) {
        uVar9 = 0xfb;
      }
    }
    else {
      uVar9 = 0x10b;
    }
    iVar22 = 1;
    uVar29 = uVar28;
    if ((int)uVar23 < 0) {
      iVar22 = 2;
      uVar29 = uVar28 | param_4[1] << 0x10;
    }
    if ((uVar23 & 0x400000) != 0) {
      iVar22 = iVar22 + 1;
    }
    if ((uVar23 & 0x1800000) == 0x1000000) {
      puVar20 = param_4 + iVar22;
      if (!bVar3) {
        uVar33 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x374);
        puVar10 = (undefined4 *)FUN_00193e18(uVar33,0x168);
        *puVar10 = uVar33;
        puVar10 = puVar10 + 1;
        FUN_00107980(puVar10,uVar9,*(undefined4 *)(iVar18 + 8));
        uVar9 = FUN_000ec208(iVar18,uVar31);
        uVar33 = 2;
        iVar6 = FUN_001054ec(puVar10,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(uint *)(iVar6 + 8) = uVar29;
      }
      else {
        uVar33 = 1;
        puVar10 = (undefined4 *)((int (*)())FUN_001043f0)(uVar9,*(undefined4 *)(iVar18 + 8));
        uVar9 = DAT_001aa9a8;
        puVar10[0x27] = DAT_001aa9dc;
        puVar10[0x50] = uVar9;
        puVar10[0x21] = 2;
        uVar9 = FUN_000ec208(iVar18,uVar31);
        iVar6 = FUN_001054ec(puVar10,2);
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(undefined4 *)(iVar6 + 8) = 0xffffffff;
      }
      uVar9 = FUN_000ec208(iVar18,4);
      iVar6 = FUN_001054ec(puVar10,0);
      *(undefined4 *)(iVar6 + 0xc) = uVar9;
      *(uint *)(iVar6 + 8) = uVar32;
      if ((*param_4 & 0x4000000) == 0) {
        uVar23 = *puVar20;
        uVar9 = FUN_000ec208(iVar18,*puVar20 >> 0x10 & 0x3f);
        iVar22 = FUN_001054ec(puVar10,uVar33);
        *(undefined4 *)(iVar22 + 0xc) = uVar9;
        *(uint *)(iVar22 + 8) = (uint)(ushort)uVar23;
      }
      else {
        uVar31 = param_4[iVar22 + 2];
        uVar9 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(iVar18 + 8));
        uVar11 = FUN_000ec208(iVar18,4);
        iVar22 = FUN_001054ec(uVar9,0);
        *(undefined4 *)(iVar22 + 0xc) = uVar11;
        *(uint *)(iVar22 + 8) = uVar32;
        uVar23 = *puVar20;
        uVar11 = FUN_000ec208(iVar18,*puVar20 >> 0x10 & 0x3f);
        iVar22 = FUN_001054ec(uVar9,1);
        *(undefined4 *)(iVar22 + 0xc) = uVar11;
        *(uint *)(iVar22 + 8) = (uint)(ushort)uVar23;
        FUN_000f7870(uVar9,iVar18,2,uVar31,uVar31,uVar31,uVar31);
        FUN_00193f64(uVar19,uVar9);
        uVar9 = FUN_000ec208(iVar18,4);
        iVar22 = FUN_001054ec(puVar10,uVar33);
        *(undefined4 *)(iVar22 + 0xc) = uVar9;
        *(uint *)(iVar22 + 8) = uVar32;
      }
      local_98 = DAT_001aa9a8;
      ((int (*)())FUN_000f8aa0)(iVar18,&local_98,puVar20,uVar33,puVar10);
    }
    else if ((uVar23 & 0x1800000) == 0) {
      uVar23 = param_4[iVar22];
      uVar33 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x374);
      puVar10 = (undefined4 *)FUN_00193e18(uVar33,0x168);
      *puVar10 = uVar33;
      puVar10 = puVar10 + 1;
      FUN_00107980(puVar10,uVar9,*(undefined4 *)(iVar18 + 8));
      uVar9 = FUN_000ec208(iVar18,4);
      iVar22 = FUN_001054ec(puVar10,0);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(uint *)(iVar22 + 8) = uVar32;
      uVar9 = FUN_000ec208(iVar18,uVar31);
      iVar22 = FUN_001054ec(puVar10,1);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(uint *)(iVar22 + 8) = uVar29;
      FUN_000f7870(puVar10,iVar18,2,uVar23,uVar23,uVar23,uVar23);
      uVar33 = 1;
    }
    else {
      puVar10 = (undefined4 *)0x0;
      uVar33 = 1;
    }
    iVar22 = FUN_001054ec(puVar10,uVar33);
    local_94[0] = *(undefined4 *)(iVar22 + 0x10);
    piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
    iVar22 = (**(code **)(*piVar8 + 0x104))(piVar8,puVar10,uVar33,local_94,0);
    if (iVar22 == 0) {
      iVar6 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(iVar18 + 8) + 0x3ac) = iVar6;
      uVar9 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
      uVar11 = puVar10[0x32];
      uVar33 = puVar10[0x31];
      iVar22 = FUN_001054ec(uVar9,1);
      *(undefined4 *)(iVar22 + 0xc) = uVar11;
      *(undefined4 *)(iVar22 + 8) = uVar33;
      uVar33 = FUN_000ec208(iVar18,4);
      iVar22 = FUN_001054ec(uVar9,0);
      *(undefined4 *)(iVar22 + 0xc) = uVar33;
      *(int *)(iVar22 + 8) = iVar6;
      iVar22 = FUN_001054ec(puVar10,2);
      uVar33 = *(undefined4 *)(iVar22 + 0x10);
      iVar22 = FUN_001054ec(uVar9,1);
      *(undefined4 *)(iVar22 + 0x10) = uVar33;
      FUN_00193f64(uVar19,uVar9);
      uVar9 = FUN_000ec208(iVar18,4);
      iVar22 = FUN_001054ec(puVar10,2);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(int *)(iVar22 + 8) = iVar6;
      uVar9 = DAT_001aa9cc;
      iVar22 = FUN_001054ec(puVar10,2);
      *(undefined4 *)(iVar22 + 0x10) = uVar9;
    }
    FUN_00193f64(uVar19,puVar10);
    bVar4 = false;
    *param_4 = *param_4 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_4 + 2) = (short)uVar32;
  }
  else {
    if (((undefined4 *)(uVar23 & 0x3f0000) == (undefined4 *)0x1c0000) ||
       ((undefined4 *)(uVar23 & 0x3f0000) == &DAT_001b0000)) {
      bVar3 = false;
      goto LAB_000fb800;
    }
    uVar32 = 0;
    if ((uVar23 & 0x2000000) != 0) {
      uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
      uVar23 = *param_4;
      if ((uVar23 & 0x400000) == 0) {
        iVar22 = 1;
        iVar15 = 1;
        iVar6 = 2;
      }
      else {
        iVar22 = 2;
        iVar15 = 2;
        iVar6 = 3;
      }
      if ((uVar23 & 0x1800000) == 0x1000000) {
        puVar20 = param_4 + iVar15;
        puVar21 = param_4 + iVar6;
        iVar15 = iVar22 + 2;
        if ((uVar23 & 0x4000000) == 0) {
          iVar6 = iVar22 + 3;
          iVar22 = iVar15;
        }
        else {
          iVar15 = iVar22 + 3;
          iVar6 = iVar22 + 4;
          iVar22 = iVar15;
        }
      }
      else {
        puVar20 = (uint *)0x0;
        puVar21 = (uint *)0x0;
      }
      if ((param_4[iVar15] & 0x1800000) == 0x1000000) {
        puVar27 = param_4 + iVar6;
        puVar26 = (uint *)0x0;
        puVar7 = param_4 + iVar22 + 2;
        if ((param_4[iVar15] & 0x4000000) != 0) {
          puVar26 = param_4 + iVar22 + 3;
        }
      }
      else {
        puVar27 = (uint *)0x0;
        puVar7 = (uint *)0x0;
        puVar26 = (uint *)0x0;
      }
      if (puVar20 == (uint *)0x0) {
        if (puVar27 != (uint *)0x0) {
          if ((puVar21 != (uint *)0x0) || (puVar7 == (uint *)0x0)) goto LAB_000fc43c;
          uVar9 = ((int (*)())FUN_001043f0)(0xe6,*(undefined4 *)(iVar18 + 8));
          uVar23 = *param_4;
          piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
          uVar33 = (**(code **)(*piVar8 + 0x9c))(piVar8,(short)uVar23);
          piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
          (**(code **)(*piVar8 + 0xa0))(&local_84,piVar8,(short)uVar23);
          uVar11 = FUN_000ec208(iVar18,4);
          iVar22 = FUN_001054ec(uVar9,0);
          *(undefined4 *)(iVar22 + 0xc) = uVar11;
          *(uint *)(iVar22 + 8) = uVar32;
          FUN_000f7870(uVar9,iVar18,1,4,4,4,4);
          uVar23 = *puVar27;
          uVar11 = FUN_000ec208(iVar18,*puVar27 >> 0x10 & 0x3f);
          iVar22 = FUN_001054ec(uVar9,2);
          local_98 = DAT_001aa9a8;
          *(undefined4 *)(iVar22 + 0xc) = uVar11;
          *(uint *)(iVar22 + 8) = (uint)(ushort)uVar23;
          ((int (*)())FUN_000f8aa0)(iVar18,&local_98,puVar27,2,uVar9);
          FUN_00193f64(uVar19,uVar9);
          if ((puVar26 != (uint *)0x0) && (*puVar26 != 0)) {
            uVar9 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(iVar18 + 8));
            uVar11 = FUN_000ec208(iVar18,4);
            iVar22 = FUN_001054ec(uVar9,0);
            *(undefined4 *)(iVar22 + 0xc) = uVar11;
            *(uint *)(iVar22 + 8) = uVar32;
            uVar11 = FUN_000ec208(iVar18,4);
            iVar22 = FUN_001054ec(uVar9,1);
            *(undefined4 *)(iVar22 + 0xc) = uVar11;
            *(uint *)(iVar22 + 8) = uVar32;
            iVar22 = *puVar26 << 2;
            FUN_000f7870(uVar9,iVar18,2,iVar22,iVar22,iVar22,iVar22);
            iVar22 = FUN_001054ec(uVar9,2);
            *(undefined4 *)(iVar22 + 0x10) = local_84;
            FUN_00193f64(uVar19,uVar9);
          }
          uVar9 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(iVar18 + 8));
          uVar11 = FUN_000ec208(iVar18,4);
          iVar22 = FUN_001054ec(uVar9,0);
          *(undefined4 *)(iVar22 + 0xc) = uVar11;
          *(uint *)(iVar22 + 8) = uVar32;
          uVar11 = FUN_000ec208(iVar18,4);
          iVar22 = FUN_001054ec(uVar9,1);
          *(undefined4 *)(iVar22 + 0xc) = uVar11;
          *(uint *)(iVar22 + 8) = uVar32;
          iVar22 = FUN_001054ec(uVar9,2);
          *(undefined4 *)(iVar22 + 0xc) = 0x1f;
          *(undefined4 *)(iVar22 + 8) = uVar33;
          iVar22 = FUN_001054ec(uVar9,2);
          *(undefined4 *)(iVar22 + 0x10) = local_84;
          FUN_00193f64(uVar19,uVar9);
          iVar22 = ((int (*)())FUN_001043f0)(0x68,*(undefined4 *)(iVar18 + 8));
          uVar33 = FUN_000ec208(iVar18,4);
          iVar6 = FUN_001054ec(iVar22,0);
          uVar9 = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar33;
          *(uint *)(iVar6 + 8) = uVar32;
          *(undefined4 *)(iVar22 + 0x130) = 0;
LAB_000fc3f4:
          *(undefined4 *)(iVar22 + 0x140) = uVar9;
          uVar33 = FUN_000ec208(iVar18,4);
          iVar6 = FUN_001054ec(iVar22,1);
          uVar9 = DAT_001aa9cc;
          *(undefined4 *)(iVar6 + 0xc) = uVar33;
          *(uint *)(iVar6 + 8) = uVar32;
          iVar15 = FUN_001054ec(iVar22,1);
          iVar6 = 0;
          *(undefined4 *)(iVar15 + 0x10) = uVar9;
          goto LAB_000fc74c;
        }
        uVar31 = (uint)*(ushort *)((int)param_4 + iVar15 * 4 + 2);
        uVar23 = (uint)(ushort)*param_4;
        if ((*(uint *)(iVar18 + 0x30) & 0x40000) == 0) {
          iVar6 = 0;
          iVar22 = ((int (*)())FUN_001043f0)(0x68,*(undefined4 *)(iVar18 + 8));
          uVar33 = FUN_000ec208(iVar18,4);
          iVar15 = FUN_001054ec(iVar22,0);
          uVar9 = DAT_001aa9a8;
          *(undefined4 *)(iVar15 + 0xc) = uVar33;
          *(uint *)(iVar15 + 8) = uVar32;
          *(undefined4 *)(iVar22 + 0x140) = uVar9;
          *(uint *)(iVar22 + 0x130) = uVar31;
          piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
          uVar9 = (**(code **)(*piVar8 + 0x9c))(piVar8,uVar23);
          piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
          (**(code **)(*piVar8 + 0xa0))(&local_88,piVar8,uVar23);
          iVar15 = FUN_001054ec(iVar22,1);
          *(undefined4 *)(iVar15 + 8) = uVar9;
          *(undefined4 *)(iVar15 + 0xc) = 0x1f;
          iVar15 = FUN_001054ec(iVar22,1);
          *(undefined4 *)(iVar15 + 0x10) = local_88;
          if (uVar31 == *param_6) {
            piVar8 = *(int **)(*(int *)(iVar18 + 8) + 0x30c);
            uVar33 = (**(code **)(*piVar8 + 0xa8))(piVar8,&local_98);
            iVar6 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
            uVar9 = FUN_000ec208(iVar18,4);
            iVar15 = FUN_001054ec(iVar6,0);
            *(undefined4 *)(iVar15 + 0xc) = uVar9;
            *(uint *)(iVar15 + 8) = uVar32;
            *(uint *)(iVar6 + 0x9c) = param_6[1];
            iVar15 = FUN_001054ec(iVar6,1);
            uVar9 = local_98;
            *(undefined4 *)(iVar15 + 0xc) = 0x1f;
            *(undefined4 *)(iVar15 + 8) = uVar33;
            iVar15 = FUN_001054ec(iVar6,1);
            *(undefined4 *)(iVar15 + 0x10) = uVar9;
          }
          goto LAB_000fc74c;
        }
        iVar22 = uVar23 * 4;
        puVar20 = *(uint **)(iVar22 + param_7);
        if (puVar20 == (uint *)0x0) {
          uVar9 = *(undefined4 *)(*(int *)(iVar18 + 8) + 0x378);
          puVar10 = (undefined4 *)FUN_00193e18(uVar9,0x14);
          puVar20 = puVar10 + 1;
          *puVar10 = uVar9;
          puVar10[1] = 2;
          puVar10[2] = 0;
          puVar10[4] = uVar9;
          uVar9 = FUN_00193e18(uVar9,8);
          puVar10[3] = uVar9;
          *(uint **)(iVar22 + param_7) = puVar20;
        }
        if (uVar31 < *puVar20) {
          uVar32 = puVar20[1];
          if (uVar32 <= uVar31) {
            _memset((void *)(uVar32 * 4 + puVar20[2]),0,(uVar31 - uVar32) * 4 + 4);
            puVar20[1] = uVar31 + 1;
          }
          piVar8 = (int *)(uVar31 * 4 + puVar20[2]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar20,uVar31);
        }
        if (*piVar8 == 0) {
          iVar6 = FUN_00109810(0xa4,*(undefined4 *)(iVar18 + 8));
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffff7fff;
          iVar16 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(iVar18 + 8) + 0x3ac) = iVar16;
          iVar15 = FUN_001054ec(iVar6,0);
          *(int *)(iVar15 + 8) = iVar16;
          *(undefined4 *)(iVar15 + 0xc) = 0;
          *(uint *)(iVar6 + 0x130) = uVar23;
          *(uint *)(iVar6 + 300) = uVar31;
          ((int (*)())FUN_000f92fc)(iVar18,iVar6,*(undefined4 *)(iVar18 + 0x3a0));
          puVar20 = *(uint **)(iVar22 + param_7);
          if (uVar31 < *puVar20) {
            uVar23 = puVar20[1];
            if (uVar23 <= uVar31) {
              _memset((void *)(uVar23 * 4 + puVar20[2]),0,(uVar31 - uVar23) * 4 + 4);
              puVar20[1] = uVar31 + 1;
            }
            piVar8 = (int *)(uVar31 * 4 + puVar20[2]);
          }
          else {
            piVar8 = (int *)FUN_0019423c(puVar20,uVar31);
          }
          *piVar8 = iVar6;
        }
        puVar20 = *(uint **)(iVar22 + param_7);
        if (uVar31 < *puVar20) {
          uVar23 = puVar20[1];
          if (uVar23 <= uVar31) {
            _memset((void *)(uVar23 * 4 + puVar20[2]),0,(uVar31 - uVar23) * 4 + 4);
            puVar20[1] = uVar31 + 1;
          }
          piVar8 = (int *)(uVar31 * 4 + puVar20[2]);
        }
        else {
          piVar8 = (int *)FUN_0019423c(puVar20,uVar31);
        }
        uVar32 = *(uint *)(*piVar8 + 0x94);
      }
      else {
        if (((puVar21 != (uint *)0x0) && (puVar27 == (uint *)0x0)) && (puVar7 == (uint *)0x0)) {
          ((int (*)())FUN_000f94dc)(iVar18,uVar19,puVar20,puVar21,uVar32,4,*(undefined4 *)(iVar18 + 0x400));
          uVar2 = *(ushort *)((int)param_4 + iVar15 * 4 + 2);
          iVar22 = ((int (*)())FUN_001043f0)(0x68,*(undefined4 *)(iVar18 + 8));
          uVar33 = FUN_000ec208(iVar18,4);
          iVar6 = FUN_001054ec(iVar22,0);
          uVar9 = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar33;
          *(uint *)(iVar6 + 8) = uVar32;
          *(uint *)(iVar22 + 0x130) = (uint)uVar2;
          goto LAB_000fc3f4;
        }
LAB_000fc43c:
        ((int (*)())FUN_000f94dc)(iVar18,uVar19,puVar20,puVar21,uVar32,4,*(undefined4 *)(iVar18 + 0x400));
        uVar31 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar31;
        uVar23 = (uint)(ushort)*puVar27;
        if (puVar26 != (uint *)0x0) {
          iVar22 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(iVar18 + 8));
          uVar33 = FUN_000ec208(iVar18,4);
          iVar6 = FUN_001054ec(iVar22,0);
          uVar9 = DAT_001aa9d0;
          *(undefined4 *)(iVar6 + 0xc) = uVar33;
          *(undefined4 *)(iVar22 + 0x9c) = uVar9;
          *(uint *)(iVar6 + 8) = uVar31;
          uVar29 = *puVar26;
          FUN_000f7870(iVar22,iVar18,1,uVar29,uVar29,uVar29,uVar29);
          uVar9 = FUN_000ec208(iVar18,*puVar27 >> 0x10 & 0x3f);
          iVar6 = FUN_001054ec(iVar22,2);
          local_94[0] = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar9;
          *(uint *)(iVar6 + 8) = uVar23;
          ((int (*)())FUN_000f8aa0)(iVar18,local_94,puVar27,2,iVar22);
          FUN_00193f64(uVar19,iVar22);
          *puVar27 = *puVar27 & 0xffc0ffff | 0x40000;
          uVar23 = uVar31;
        }
        iVar22 = ((int (*)())FUN_001043f0)(0xe6,*(undefined4 *)(iVar18 + 8));
        uVar33 = FUN_000ec208(iVar18,4);
        iVar6 = FUN_001054ec(iVar22,0);
        uVar9 = DAT_001aa9d0;
        *(undefined4 *)(iVar6 + 0xc) = uVar33;
        *(undefined4 *)(iVar22 + 0x9c) = uVar9;
        *(uint *)(iVar6 + 8) = uVar31;
        FUN_000f7870(iVar22,iVar18,1,4,4,4,4);
        uVar9 = FUN_000ec208(iVar18,*puVar27 >> 0x10 & 0x3f);
        iVar6 = FUN_001054ec(iVar22,2);
        local_98 = DAT_001aa9a8;
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(uint *)(iVar6 + 8) = uVar23;
        uVar9 = DAT_001aa9cc;
        if (puVar26 == (uint *)0x0) {
          ((int (*)())FUN_000f8aa0)(iVar18,&local_98,puVar27,2,iVar22);
        }
        else {
          iVar6 = FUN_001054ec(iVar22,2);
          *(undefined4 *)(iVar6 + 0x10) = uVar9;
        }
        FUN_00193f64(uVar19,iVar22);
        iVar22 = ((int (*)())FUN_001043f0)(0xc6,*(undefined4 *)(iVar18 + 8));
        *(undefined4 *)(iVar22 + 0x9c) = DAT_001aa9d0;
        uVar9 = FUN_000ec208(iVar18,4);
        iVar6 = FUN_001054ec(iVar22,0);
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(uint *)(iVar6 + 8) = uVar32;
        uVar9 = FUN_000ec208(iVar18,4);
        iVar6 = FUN_001054ec(iVar22,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(uint *)(iVar6 + 8) = uVar32;
        uVar9 = FUN_000ec208(iVar18,4);
        iVar6 = FUN_001054ec(iVar22,2);
        *(undefined4 *)(iVar6 + 0xc) = uVar9;
        *(uint *)(iVar6 + 8) = uVar31;
        uVar33 = DAT_001aa9cc;
        iVar15 = FUN_001054ec(iVar22,1);
        iVar6 = 0;
        *(undefined4 *)(iVar15 + 0x10) = uVar33;
        iVar15 = FUN_001054ec(iVar22,2);
        *(undefined4 *)(iVar15 + 0x10) = uVar33;
        FUN_00193f64(uVar19,iVar22);
        iVar22 = ((int (*)())FUN_001043f0)(0x68,*(undefined4 *)(iVar18 + 8));
        uVar11 = FUN_000ec208(iVar18,4);
        iVar15 = FUN_001054ec(iVar22,0);
        uVar9 = DAT_001aa9a8;
        *(undefined4 *)(iVar15 + 0xc) = uVar11;
        *(uint *)(iVar15 + 8) = uVar32;
        *(undefined4 *)(iVar22 + 0x130) = 0;
        *(undefined4 *)(iVar22 + 0x140) = uVar9;
        uVar9 = FUN_000ec208(iVar18,4);
        iVar15 = FUN_001054ec(iVar22,1);
        *(undefined4 *)(iVar15 + 0xc) = uVar9;
        *(uint *)(iVar15 + 8) = uVar32;
        iVar15 = FUN_001054ec(iVar22,1);
        *(undefined4 *)(iVar15 + 0x10) = uVar33;
LAB_000fc74c:
        FUN_00193f64(uVar19,iVar22);
        if (iVar6 != 0) {
          FUN_00193f64(uVar19,iVar6);
        }
      }
      bVar4 = false;
      *param_4 = *param_4 & 0xffc0ffff | 0x40000;
      *(short *)((int)param_4 + 2) = (short)uVar32;
    }
  }
  if (uVar24 == 0) goto LAB_000fd490;
  uVar23 = *param_4;
  if (((uVar23 & 0x400000) == 0) || ((param_4[1] & 0x4444) == 0)) {
    bVar3 = false;
  }
  else {
    uVar9 = FUN_0019e9fc(param_4,0);
    uVar33 = FUN_0019e9fc(param_4,1);
    uVar11 = FUN_0019e9fc(param_4,2);
    uVar12 = FUN_0019e9fc(param_4,3);
    uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
    *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
    uVar13 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
    iVar22 = FUN_001054ec(uVar13,0);
    *(undefined4 *)(iVar22 + 0xc) = 0;
    *(uint *)(iVar22 + 8) = uVar32;
    uVar14 = FUN_000ec208(iVar18,uVar25);
    iVar22 = FUN_001054ec(uVar13,1);
    local_94[0] = DAT_001aa9a8;
    *(undefined4 *)(iVar22 + 0xc) = uVar14;
    *(uint *)(iVar22 + 8) = uVar28;
    uVar39 = ((double (*)())FUN_000f8a30)(uVar9,0,&local_98,local_94);
    uVar35 = ((double (*)())FUN_000f8a30)(uVar33,1,&local_98,local_94);
    uVar36 = ((double (*)())FUN_000f8a30)(uVar11,2,&local_98,local_94);
    uVar37 = ((double (*)())FUN_000f8a30)(uVar12,3,&local_98,local_94);
    uVar9 = local_94[0];
    iVar22 = FUN_001054ec(uVar13,1);
    *(undefined4 *)(iVar22 + 0x10) = uVar9;
    FUN_00193f64(uVar19,uVar13);
    iVar22 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar32;
    FUN_000f79c4(uVar39,uVar35,uVar36,uVar37,iVar22,iVar18,1);
    *(undefined4 *)(iVar22 + 0x9c) = local_98;
    FUN_00193f64(uVar19,iVar22);
    uVar23 = *param_4;
    uVar28 = uVar32;
    if ((uVar23 & 0x400000) == 0) {
      uVar25 = 4;
      bVar3 = true;
    }
    else {
      uVar25 = 4;
      bVar3 = true;
      param_4[1] = param_4[1] & 0xffff8888 | 0x3210;
    }
  }
  if ((uVar23 & 0x400000) == 0) goto LAB_000fd490;
  uVar24 = param_4[1];
  puVar20 = param_4 + 1;
  if ((uVar24 & 0xffff8888) == 0) goto LAB_000fd490;
  uVar31 = uVar28;
  if ((*(ushort *)(param_3 + 2) - 0x8e < 0x10) && ((uVar24 & 0x8888) != 0)) {
    param_4[1] = uVar24 & 0xffff7777;
    uVar31 = uVar32;
    if (!bVar3) {
      uVar31 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar31;
    }
    bVar3 = true;
    uVar9 = ((int (*)())FUN_001043f0)(0xcb,*(undefined4 *)(iVar18 + 8));
    iVar22 = FUN_001054ec(uVar9,0);
    dVar38 = (double)FLOAT_001aa0d4;
    *(undefined4 *)(iVar22 + 0xc) = 0;
    *(uint *)(iVar22 + 8) = uVar31;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,uVar9,iVar18,2);
    uVar33 = FUN_000ec208(iVar18,uVar25);
    iVar22 = FUN_001054ec(uVar9,1);
    *(uint *)(iVar22 + 8) = uVar28;
    *(undefined4 *)(iVar22 + 0xc) = uVar33;
    FUN_00193f64(uVar19,uVar9);
    uVar23 = *param_4;
    uVar25 = 4;
    uVar32 = uVar31;
  }
  uVar24 = uVar31;
  if (((uVar23 & 0x400000) != 0) && ((*puVar20 & 0x10000) != 0)) {
    uVar24 = uVar32;
    if (!bVar3) {
      uVar24 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar24;
    }
    iVar22 = ((int (*)())FUN_001043f0)(0x12,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar24;
    uVar9 = FUN_000ec208(iVar18,uVar25);
    iVar6 = FUN_001054ec(iVar22,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar9;
    *(uint *)(iVar6 + 8) = uVar31;
    ((int (*)())FUN_00103d50)(iVar22 + 0xa4,1,1);
    if (!bVar3) {
      ((int (*)())FUN_000f8f88)(param_4,iVar22);
    }
    dVar38 = (double)FLOAT_001aa0e8;
    uVar25 = 4;
    bVar3 = true;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar22,iVar18,2);
    FUN_00193f64(uVar19,iVar22);
    uVar23 = *param_4;
    uVar32 = uVar24;
  }
  if ((((uVar23 & 0x400000) == 0) || ((*puVar20 & 0x20000) == 0)) || ((*puVar20 & 0x40000) == 0)) {
    if (((uVar23 & 0x400000) == 0) || ((*puVar20 & 0x20000) == 0)) {
      if (((uVar23 & 0x400000) == 0) || ((*puVar20 & 0x40000) == 0)) goto LAB_000fcda8;
      if (!bVar3) {
        uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
      }
      iVar6 = ((int (*)())FUN_001043f0)(0x13,*(undefined4 *)(iVar18 + 8));
      iVar22 = FUN_001054ec(iVar6,0);
      *(undefined4 *)(iVar22 + 0xc) = 0;
      *(uint *)(iVar22 + 8) = uVar32;
      uVar9 = FUN_000ec208(iVar18,uVar25);
      iVar22 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(uint *)(iVar22 + 8) = uVar24;
      if (!bVar3) {
        ((int (*)())FUN_000f8f88)(param_4,iVar6);
      }
      dVar38 = (double)FLOAT_001aa108;
      FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar6,iVar18,2);
      uVar24 = uVar32;
    }
    else {
      if (!bVar3) {
        uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
      }
      iVar6 = ((int (*)())FUN_001043f0)(0x12,*(undefined4 *)(iVar18 + 8));
      iVar22 = FUN_001054ec(iVar6,0);
      *(undefined4 *)(iVar22 + 0xc) = 0;
      *(uint *)(iVar22 + 8) = uVar32;
      uVar9 = FUN_000ec208(iVar18,uVar25);
      iVar22 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(uint *)(iVar22 + 8) = uVar24;
      if (!bVar3) {
        ((int (*)())FUN_000f8f88)(param_4,iVar6);
      }
      dVar38 = (double)FLOAT_001aa10c;
      FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar6,iVar18,2);
      ((int (*)())FUN_00103d50)(iVar6 + 0xbc,1,1);
      uVar24 = uVar32;
    }
    FUN_00193f64(uVar19,iVar6);
    uVar23 = *param_4;
    uVar25 = 4;
    bVar3 = true;
    uVar32 = uVar24;
  }
  else {
    if (!bVar3) {
      uVar32 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar32;
    }
    iVar22 = ((int (*)())FUN_001043f0)(0x14,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar32;
    uVar9 = FUN_000ec208(iVar18,uVar25);
    iVar6 = FUN_001054ec(iVar22,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar9;
    *(uint *)(iVar6 + 8) = uVar24;
    if (!bVar3) {
      ((int (*)())FUN_000f8f88)(param_4,iVar22);
    }
    dVar38 = (double)FLOAT_001aa108;
    uVar25 = 4;
    bVar3 = true;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar22,iVar18,2);
    dVar38 = (double)FLOAT_001aa0e8;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar22,iVar18,3);
    ((int (*)())FUN_00103d50)(iVar22 + 0xd4,1,1);
    FUN_00193f64(uVar19,iVar22);
    uVar23 = *param_4;
    uVar24 = uVar32;
  }
LAB_000fcda8:
  uVar28 = uVar24;
  if (((uVar23 & 0x400000) != 0) && ((*puVar20 & 0x80000) != 0)) {
    uVar28 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
    *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar28;
    uVar9 = ((int (*)())FUN_001043f0)(0x26,*(undefined4 *)(iVar18 + 8));
    iVar22 = FUN_001054ec(uVar9,0);
    *(undefined4 *)(iVar22 + 0xc) = 0;
    *(uint *)(iVar22 + 8) = uVar28;
    uVar33 = FUN_000ec208(iVar18,uVar25);
    iVar22 = FUN_001054ec(uVar9,1);
    dVar38 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar22 + 0xc) = uVar33;
    *(uint *)(iVar22 + 8) = uVar24;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,uVar9,iVar18,2);
    uVar33 = FUN_000ec208(iVar18,uVar25);
    iVar22 = FUN_001054ec(uVar9,3);
    *(undefined4 *)(iVar22 + 0xc) = uVar33;
    *(uint *)(iVar22 + 8) = uVar24;
    if (!bVar3) {
      ((int (*)())FUN_000f8f88)(param_4,uVar9);
      iVar22 = FUN_001054ec(uVar9,1);
      uVar33 = *(undefined4 *)(iVar22 + 0x10);
      iVar22 = FUN_001054ec(uVar9,3);
      *(undefined4 *)(iVar22 + 0x10) = uVar33;
    }
    FUN_00193f64(uVar19,uVar9);
    iVar22 = ((int (*)())FUN_001043f0)(0x25,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar28;
    iVar6 = FUN_001054ec(iVar22,1);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar25 = 4;
    *(uint *)(iVar6 + 8) = uVar28;
    iVar6 = FUN_001054ec(iVar22,2);
    dVar38 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar28;
    bVar3 = true;
    FUN_000f79c4(dVar38,dVar38,dVar38,dVar38,iVar22,iVar18,3);
    ((int (*)())FUN_00103d50)(iVar22 + 0xd4,1,1);
    FUN_00193f64(uVar19,iVar22);
    uVar23 = *param_4;
    uVar32 = uVar28;
  }
  uVar24 = uVar28;
  if (((uVar23 & 0x400000) != 0) && (uVar31 = *puVar20 >> 0x15 & 7, uVar31 != 0)) {
    iVar22 = (**(code **)(**(int **)(*(int *)(iVar18 + 8) + 0x30c) + 0xb4))();
    if ((iVar22 == 0) || ((0xbe < *(ushort *)(param_3 + 2) || (*(ushort *)(param_3 + 2) != 0x5d))))
    {
      if (uVar31 == 4) {
LAB_000fd284:
        uVar23 = *param_4;
      }
      else {
        if (uVar31 == 1) {
          iVar22 = 1;
          uVar9 = DAT_001aaa28;
          uVar33 = DAT_001aa9d0;
        }
        else if (uVar31 == 2) {
          iVar22 = 2;
          uVar9 = DAT_001aaa20;
          uVar33 = DAT_001aaa24;
        }
        else {
          if (uVar31 != 3) goto LAB_000fd284;
          iVar22 = 3;
          uVar9 = DAT_001aaa18;
          uVar33 = DAT_001aaa1c;
        }
        iVar6 = ((int (*)())FUN_001043f0)(0x40,*(undefined4 *)(iVar18 + 8));
        uVar24 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar24;
        iVar15 = FUN_001054ec(iVar6,0);
        uVar11 = DAT_001aa9bc;
        *(undefined4 *)(iVar15 + 0xc) = 0;
        *(undefined4 *)(iVar6 + 0x9c) = uVar11;
        *(uint *)(iVar15 + 8) = uVar24;
        uVar11 = FUN_000ec208(iVar18,uVar25);
        iVar15 = FUN_001054ec(iVar6,1);
        *(undefined4 *)(iVar15 + 0xc) = uVar11;
        *(uint *)(iVar15 + 8) = uVar28;
        iVar15 = ((int (*)())FUN_001043f0)(0x13,*(undefined4 *)(iVar18 + 8));
        iVar16 = FUN_001054ec(iVar15,0);
        *(undefined4 *)(iVar16 + 0xc) = 0;
        *(uint *)(iVar16 + 8) = uVar24;
        uVar11 = FUN_000ec208(iVar18,uVar25);
        iVar16 = FUN_001054ec(iVar15,1);
        *(undefined4 *)(iVar16 + 0xc) = uVar11;
        *(uint *)(iVar16 + 8) = uVar28;
        iVar16 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
        iVar17 = FUN_001054ec(iVar16,0);
        *(undefined4 *)(iVar17 + 0xc) = 0;
        *(uint *)(iVar17 + 8) = uVar24;
        uVar11 = FUN_000ec208(iVar18,uVar25);
        iVar17 = FUN_001054ec(iVar16,1);
        *(undefined4 *)(iVar17 + 0xc) = uVar11;
        *(uint *)(iVar17 + 8) = uVar28;
        if (!bVar3) {
          ((int (*)())FUN_000f8f88)(param_4,iVar15);
          iVar17 = FUN_001054ec(iVar15,1);
          uVar11 = *(undefined4 *)(iVar17 + 0x10);
          iVar17 = FUN_001054ec(iVar16,1);
          *(undefined4 *)(iVar17 + 0x10) = uVar11;
        }
        iVar17 = FUN_001054ec(iVar15,2);
        puVar5 = PTR_DAT_001e8b8c;
        *(undefined4 *)(iVar17 + 0xc) = 0;
        uVar11 = *(undefined4 *)(puVar5 + 0xc);
        uVar25 = 4;
        *(uint *)(iVar17 + 8) = uVar24;
        iVar17 = FUN_001054ec(iVar15,2);
        *(undefined4 *)(iVar17 + 0x10) = uVar11;
        iVar17 = FUN_001054ec(iVar15,1);
        local_80 = *(undefined4 *)(iVar17 + 0x10);
        bVar3 = true;
        uVar11 = *(undefined4 *)(puVar5 + (uint)*(byte *)((int)&local_80 + iVar22) * 4);
        iVar22 = FUN_001054ec(iVar6,1);
        *(undefined4 *)(iVar22 + 0x10) = uVar11;
        *(undefined4 *)(iVar15 + 0x9c) = uVar33;
        *(undefined4 *)(iVar16 + 0x9c) = uVar9;
        FUN_00193f64(uVar19,iVar6);
        FUN_00193f64(uVar19,iVar15);
        FUN_00193f64(uVar19,iVar16);
        uVar23 = *param_4;
        uVar32 = uVar24;
      }
    }
    else if (uVar31 == 3) {
      *(undefined4 *)(iVar18 + 0x47c) = 1;
      uVar23 = *param_4;
    }
    else {
      if (uVar31 != 2) goto LAB_000fd284;
      *(undefined4 *)(iVar18 + 0x47c) = 1;
      bVar3 = true;
      uVar24 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar24;
      piVar8 = (int *)((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
      iVar22 = FUN_001054ec(piVar8,0);
      *(undefined4 *)(iVar22 + 0xc) = 0;
      *(uint *)(iVar22 + 8) = uVar24;
      uVar9 = FUN_000ec208(iVar18,uVar25);
      iVar22 = FUN_001054ec(piVar8,1);
      *(undefined4 *)(iVar22 + 0xc) = uVar9;
      *(uint *)(iVar22 + 8) = uVar28;
      ((int (*)())FUN_000f8f88)(param_4,piVar8);
      pcVar34 = *(code **)(*piVar8 + 0x88);
      iVar22 = FUN_001054ec(piVar8,1);
      (*pcVar34)(piVar8,1,3,*(undefined1 *)(iVar22 + 0x12));
      FUN_00193f64(uVar19,piVar8);
      uVar23 = *param_4;
      uVar25 = 4;
      uVar32 = uVar24;
    }
  }
  uVar28 = uVar24;
  if (((((uVar23 & 0x400000) != 0) && ((*puVar20 & 0x8888) != 0)) &&
      (uVar23 = FUN_0019eaa4(param_4), uVar23 != 0)) && (uVar23 != 0x8888)) {
    uVar28 = uVar32;
    if (!bVar3) {
      uVar28 = *(int *)(*(int *)(iVar18 + 8) + 0x3ac) - 1;
      *(uint *)(*(int *)(iVar18 + 8) + 0x3ac) = uVar28;
    }
    iVar22 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(uint *)(iVar6 + 8) = uVar28;
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar9 = FUN_000ec208(iVar18,uVar25);
    iVar6 = FUN_001054ec(iVar22,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar9;
    *(uint *)(iVar6 + 8) = uVar24;
    if (!bVar3) {
      ((int (*)())FUN_000f8f88)(param_4,iVar22);
    }
    if (((*param_4 & 0x400000) != 0) && ((*puVar20 & 0x100000) != 0)) {
      ((int (*)())FUN_00103d50)(iVar22 + 0xa4,2,1);
    }
    FUN_00193f64(uVar19,iVar22);
    iVar22 = FUN_001054ec(iVar22,1);
    uVar33 = *(undefined4 *)(iVar22 + 0x10);
    iVar22 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(iVar18 + 8));
    iVar6 = FUN_001054ec(iVar22,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(uint *)(iVar6 + 8) = uVar28;
    uVar9 = FUN_000ec208(iVar18,uVar25);
    iVar18 = FUN_001054ec(iVar22,1);
    *(undefined4 *)(iVar18 + 0xc) = uVar9;
    *(uint *)(iVar18 + 8) = uVar24;
    if (!bVar3) {
      iVar18 = FUN_001054ec(iVar22,1);
      *(undefined4 *)(iVar18 + 0x10) = uVar33;
    }
    ((int (*)())FUN_00103d50)(iVar22 + 0xa4,1,1);
    if ((((*param_4 & 0x400000) != 0) && ((*puVar20 & 0x100000) != 0)) &&
       (((int (*)())FUN_00103d50)(iVar22 + 0xa4,2,1), (*param_4 & 0x400000) != 0)) {
      *puVar20 = *puVar20 & 0xffefffff;
    }
    *(uint *)(iVar22 + 0x9c) =
         uVar23 >> 0xf & 1 ^ 1 |
         (uVar23 >> 0xb & 1 ^ 1) << 8 |
         (uVar23 >> 7 & 1 ^ 1) << 0x10 | (uVar23 >> 3 & 1 ^ 1) << 0x18;
    FUN_00193f64(uVar19,iVar22);
    if ((*param_4 & 0x400000) != 0) {
      *puVar20 = *puVar20 & 0xffff7777;
    }
    uVar25 = 4;
  }
LAB_000fd490:
  if (bVar4) {
    *(short *)((int)param_4 + 2) = (short)uVar28;
    *param_4 = uVar25 << 0x10 | *param_4 & 0xffc0ffff;
  }
  return;
}

/* FUN_000fd50c @ 0xfd50c (188 bytes) */
int FUN_000fd50c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint *param_6;
{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x10);
  *puVar1 = uVar4;
  puVar1[1] = param_2;
  uVar4 = *param_3;
  puVar1[3] = param_4;
  puVar1[2] = uVar4;
  uVar3 = param_6[1];
  if (uVar3 < *param_6) {
    _memset((void *)(uVar3 * 4 + param_6[2]),0,4);
    piVar2 = (int *)(uVar3 * 4 + param_6[2]);
    param_6[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(param_6,uVar3);
  }
  *piVar2 = (int)(puVar1 + 1);
  *param_3 = 0xffffffff;
  return param_5;
}

/* FUN_000fd5c8 @ 0xfd5c8 (24388 bytes) */
int FUN_000fd5c8(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  ushort uVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined1 uVar9;
  uint uVar10;
  uint uVar11;
  undefined *puVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  int *piVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 *puVar22;
  undefined2 *puVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined2 uVar30;
  undefined4 *puVar27;
  undefined4 *puVar28;
  int *piVar29;
  undefined4 *puVar31;
  int iVar32;
  uint *puVar33;
  int *piVar34;
  uint *puVar35;
  undefined *puVar36;
  uint *puVar37;
  int iVar38;
  uint *puVar39;
  int iVar40;
  int iVar41;
  uint uVar42;
  int iVar43;
  undefined4 uVar44;
  int iVar45;
  undefined4 *puVar46;
  int iVar47;
  undefined4 uVar48;
  double dVar49;
  int local_188;
  int *local_184;
  int *local_180;
  int *local_17c;
  undefined4 local_178;
  uint local_174;
  undefined *local_170;
  undefined1 auStack_16c [8];
  int local_164;
  undefined1 auStack_154 [8];
  int local_14c;
  uint *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_11c;
  undefined *local_118;
  undefined4 local_104;
  int local_100;
  undefined4 local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  uint local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  undefined4 local_b4;
  uint *local_b0;
  int local_ac;
  uint *local_a8;
  int local_a4;
  undefined4 *local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int *local_7c;
  undefined *local_78;
  undefined *local_74;
  undefined4 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  int local_64;
  undefined *local_60;
  undefined *local_5c;
  int *local_58;
  
  iVar32 = *(int *)(*(int *)(param_1 + 8) + 0x30c);
  local_9c = 0;
  local_98 = 0;
  *(uint *)(iVar32 + 8) = *(uint *)(iVar32 + 8) & 0xffffffdf;
  local_94 = 0;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  iVar32 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50);
  uVar10 = iVar32 + 0x1fU >> 5;
  puVar14 = (undefined4 *)FUN_00193e18(uVar44,uVar10 * 4 + 0xc);
  local_a0 = puVar14 + 1;
  *puVar14 = uVar44;
  puVar14[1] = uVar10;
  puVar14[2] = iVar32;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  if (uVar10 != 0) {
    puVar14 = local_a0;
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    do {
      uVar10 = uVar10 - 1;
      puVar14[2] = 0;
      puVar14 = puVar14 + 1;
    } while (uVar10 != 0);
  }
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar44,0x14);
  puVar35 = puVar14 + 1;
  *puVar14 = uVar44;
  puVar14[1] = 2;
  puVar14[4] = uVar44;
  puVar14[2] = 0;
  uVar44 = FUN_00193e18(uVar44,8);
  puVar14[3] = uVar44;
  local_188 = 0;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
  local_a8 = puVar15 + 1;
  *puVar15 = uVar44;
  puVar15[1] = 2;
  puVar15[4] = uVar44;
  puVar15[2] = 0;
  uVar10 = FUN_00193e18(uVar44,8);
  local_a8[2] = uVar10;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
  local_b0 = puVar15 + 1;
  *puVar15 = uVar44;
  puVar15[1] = 2;
  puVar15[2] = 0;
  puVar15[4] = uVar44;
  uVar10 = FUN_00193e18(uVar44,8);
  local_b0[2] = uVar10;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
  puVar15[1] = 2;
  *puVar15 = uVar44;
  puVar15[2] = 0;
  puVar15[4] = uVar44;
  uVar44 = FUN_00193e18(uVar44,8);
  puVar15[3] = uVar44;
  *(undefined4 **)(param_1 + 0x414) = puVar15 + 1;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
  puVar15[1] = 2;
  *puVar15 = uVar44;
  puVar15[2] = 0;
  puVar15[4] = uVar44;
  uVar44 = FUN_00193e18(uVar44,8);
  puVar15[3] = uVar44;
  local_5c = &DAT_001ad5d8;
  local_184 = *(int **)(param_1 + 0x3a0);
  local_128 = 0;
  local_170 = DAT_001aa9e0;
  local_174 = 0xffffffff;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  local_13c = puVar15 + 1;
  puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x130);
  *puVar15 = uVar44;
  piVar17 = puVar15 + 1;
  FUN_000ea020(piVar17,*(undefined4 *)(param_1 + 8));
  local_180 = piVar17;
  FUN_000ec3ac(param_1,local_184,piVar17);
  local_6c = auStack_16c;
  FUN_000e8e4c(local_184,local_180);
  local_68 = auStack_154;
  local_184 = local_180;
  FUN_001940a8(local_6c);
  FUN_001940a8(local_68);
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  ((int (*)())FUN_000fb230)(param_1,param_2);
  local_a4 = 0;
  local_ac = 0;
switchD_000fdaf0_caseD_2:
  iVar32 = FUN_000e5e70(param_2);
  if (iVar32 == 0) {
LAB_00103c40:
    FUN_000ec728(param_1);
    FUN_000e8e4c(local_180,*(undefined4 *)(param_1 + 0x3a8));
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
    FUN_0012e8c0(param_1,*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x3a8));
    if (local_a8 != (uint *)0x0) {
      FUN_00193cc0(local_a8[3],local_a8[2]);
      FUN_00193cc0(local_a8[-1],local_a8 + -1);
    }
    if (puVar35 != (uint *)0x0) {
      FUN_00193cc0(puVar14[4],puVar14[3]);
      FUN_00193cc0(*puVar14,puVar14);
    }
    if (local_a0 != (undefined4 *)0x0) {
      FUN_00193cc0(local_a0[-1],local_a0 + -1);
    }
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),*(undefined4 *)(param_1 + 0x78));
    FUN_0011e894(param_1);
    return;
  }
  iVar32 = FUN_000e43ec(param_2);
  if (iVar32 != 0) {
    iVar32 = *(int *)(param_1 + 0x3c4);
    iVar40 = 0;
    local_17c = (int *)0x0;
    for (uVar10 = 1; uVar10 <= *(uint *)(iVar32 + 4); uVar10 = uVar10 + 1) {
      local_17c = *(int **)(iVar40 + *(int *)(iVar32 + 8));
      if ((local_17c[5] & 1U) != 0) {
        (**(code **)(*local_17c + 0x68))(local_17c);
        piVar17 = local_17c;
        uVar44 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar44,1,local_17c[0x29]);
        puVar37 = local_13c;
        uVar42 = piVar17[0x50];
        if (uVar42 < *local_13c) {
          uVar16 = local_13c[1];
          if (uVar16 <= uVar42) {
            _memset((void *)(uVar16 * 4 + local_13c[2]),0,(uVar42 - uVar16) * 4 + 4);
            puVar37[1] = uVar42 + 1;
          }
          puVar15 = (undefined4 *)(uVar42 * 4 + puVar37[2]);
        }
        else {
          puVar15 = (undefined4 *)FUN_0019423c(local_13c,uVar42);
        }
        *puVar15 = uVar44;
        iVar32 = *(int *)(param_1 + 0x3c4);
      }
      iVar40 = iVar40 + 4;
    }
    piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar17 + 0x17c))(piVar17,param_1);
    FUN_000e5e70(param_2);
  }
  puVar37 = (uint *)(param_2 + 0x8c);
  *(undefined4 *)(param_1 + 0x47c) = 0;
  iVar32 = FUN_000e4408(param_2);
  if (iVar32 == 0x52) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100;
  }
  else if (((iVar32 == 0x84) && ((*(uint *)(param_1 + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(param_1 + 0x30) & 0x200000) == 0)) goto LAB_00103c40;
  iVar40 = *(int *)(param_1 + 8);
  piVar17 = *(int **)(iVar40 + 0x30c);
  iVar45 = piVar17[3];
  uVar44 = ((int (*)())FUN_000f89a4)(iVar32,iVar45);
  switch(uVar44) {
  case 0:
  case 1:
    switch(iVar32) {
    case 0x14:
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        puVar37 = (uint *)**(undefined4 **)(param_2 + 0x6c);
        iVar32 = FUN_000ec208(param_1,*puVar37 >> 0x10 & 0x3f);
        iVar40 = *(int *)(param_1 + 8);
        if ((((*puVar37 & 0x3f0000) == 0x100000) && (iVar40 != 0)) &&
           ((*(uint *)(*(int *)(iVar40 + 0x30c) + 8) & 0x80) != 0)) {
          iVar45 = 0xf;
        }
        else {
          iVar45 = (int)(short)*puVar37;
        }
        puVar37 = *(uint **)(*(int *)(param_2 + 0x6c) + 4);
        if ((((*puVar37 & 0x3f0000) == 0x100000) && (iVar40 != 0)) &&
           ((*(uint *)(*(int *)(iVar40 + 0x30c) + 8) & 0x80) != 0)) {
          iVar40 = 0xf;
        }
        else {
          iVar40 = (int)(short)*puVar37;
        }
        if (iVar32 == 0x15) {
LAB_000fed00:
          if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
            *(int *)(param_1 + 1000) = iVar45;
            *(undefined4 *)(param_1 + 0x3e4) = 1;
            *(int *)(param_1 + 0x3ec) = iVar40 + 1;
            *(int *)(param_1 + 0x3f4) = iVar32;
            if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar45 < iVar40 + 1)) {
              do {
                FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar32,iVar45,0);
                iVar45 = iVar45 + 1;
              } while (iVar45 < *(int *)(param_1 + 0x3ec));
            }
          }
          goto switchD_000fdaf0_caseD_2;
        }
        if (iVar32 < 0x16) {
          if (iVar32 != 0x14) goto switchD_000fdaf0_caseD_2;
        }
        else if (iVar32 != 0x1a) {
          if (iVar32 == 0x24) goto LAB_000fed00;
          goto switchD_000fdaf0_caseD_2;
        }
        *(int *)(param_1 + 1000) = iVar45;
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        *(int *)(param_1 + 0x3ec) = iVar40 + 1;
        *(int *)(param_1 + 0x3f4) = iVar32;
        if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar45 < iVar40 + 1)) {
          do {
            FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar32,iVar45,0);
            iVar45 = iVar45 + 1;
          } while (iVar45 < *(int *)(param_1 + 0x3ec));
        }
      }
    default:
      goto switchD_000fdaf0_caseD_2;
    case 0x16:
    case 0x18:
      if ((*(uint *)(*(int *)(iVar40 + 0x6c4) + 0x30) & 0x2000) != 0) {
        uVar10 = *(uint *)**(int **)(param_2 + 100);
        uVar42 = uVar10 >> 0x10 & 0x3f;
        if ((((uVar10 & 0x3f0000) == 0x100000) && (iVar40 != 0)) && ((piVar17[2] & 0x80U) != 0)) {
          iVar32 = 0xf;
        }
        else {
          iVar32 = (int)(short)*(uint *)**(int **)(param_2 + 100);
        }
        uVar44 = FUN_000ec208(param_1,uVar42);
        uVar48 = FUN_000ec2a0(param_1,uVar42);
        iVar40 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar44,iVar32,0);
        iVar40 = *(int *)(iVar40 + 0x38);
        ((int (*)())FUN_001041d0)(iVar40,0,*puVar37 >> 0x10 & 3,uVar48,iVar32);
        ((int (*)())FUN_001041d0)(iVar40,1,*puVar37 >> 0x12 & 3,uVar48,iVar32);
        ((int (*)())FUN_001041d0)(iVar40,2,*puVar37 >> 0x14 & 3,uVar48,iVar32);
        ((int (*)())FUN_001041d0)(iVar40,3,*puVar37 >> 0x16 & 3,uVar48,iVar32);
        uVar10 = *puVar37;
        if ((uVar10 & 0x1000000) != 0) {
          *(uint *)(iVar40 + 0x13c) = *(uint *)(iVar40 + 0x13c) | 1;
          uVar10 = *puVar37;
        }
        *(int *)(iVar40 + 0x148) = iVar32;
        *(uint *)(iVar40 + 0x140) = uVar10 >> 0x19 & 1;
        *(undefined4 *)(iVar40 + 0x144) = uVar44;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      uVar44 = FUN_000ec27c(param_1,*puVar37 >> 0x10 & 0x1f);
      uVar10 = *puVar37;
      if ((int)uVar10 < 0) {
        uVar11 = *(uint *)(param_2 + 0x90);
        uVar18 = uVar11 >> 9 & 1;
        uVar42 = uVar11 >> 8 & 1;
        uVar16 = uVar11 >> 10 & 1;
        local_178 = (undefined *)
                    (CONCAT31(CONCAT21(CONCAT11((char)uVar11,(char)(uVar11 >> 2)),
                                       (char)(uVar11 >> 4)),(char)(uVar11 >> 6)) & 0x3030303);
      }
      else {
        uVar42 = 0;
        uVar16 = 0;
        uVar18 = 0;
        local_178 = (undefined *)0x3030303;
      }
      iVar40 = (int)(short)*(uint *)**(undefined4 **)(param_2 + 100);
      uVar48 = FUN_000ec208(param_1,*(uint *)**(undefined4 **)(param_2 + 100) >> 0x10 & 0x3f);
      iVar32 = *(int *)(param_1 + 1000);
      if (iVar40 <= *(int *)(param_1 + 1000)) {
        iVar32 = iVar40;
      }
      iVar45 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar32;
      if (iVar45 <= iVar40) {
        iVar45 = iVar40 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar45;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      iVar32 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,iVar40,0);
      iVar32 = *(int *)(iVar32 + 0x38);
      if (uVar42 == 0) {
        *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 1;
      }
      if (uVar16 != 0) {
        *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 4;
      }
      if (uVar18 != 0) {
        *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 2;
      }
      local_70 = &local_178;
      iVar40 = 0;
      do {
        if (*(char *)(iVar40 + (int)local_70) != '\0') {
          ((int (*)())FUN_001041d0)(iVar32,iVar40,*(char *)(iVar40 + (int)local_70),uVar44,uVar10 >> 0x15 & 0xff)
          ;
        }
        bVar1 = iVar40 != 3;
        iVar40 = iVar40 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      bVar4 = *(byte *)(param_2 + 0x8d);
      uVar10 = *puVar37;
      iVar32 = (uint)bVar4 * 0xc;
      *(uint *)(*(int *)(param_1 + 0x78) + iVar32) = uVar10 >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50) < (int)(uint)bVar4) {
        FUN_000e1534(*(int *)(param_1 + 8),7);
      }
      uVar42 = bVar4 >> 3 & 0x1c;
      *(uint *)((int)local_a0 + uVar42 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar42 + 8);
      *(uint *)(iVar32 + *(int *)(param_1 + 0x78) + 8) = *puVar37 >> 0x1d & 1;
      piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      iVar40 = (**(code **)(*piVar17 + 0x48))(piVar17,param_1,uVar10 >> 0x18 & 7);
      if (iVar40 != 0) {
        *(int *)(iVar32 + *(int *)(param_1 + 0x78) + 4) = iVar40;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      FUN_001940a8(&local_124);
      uVar42 = *puVar37;
      uVar16 = 0;
      uVar10 = DAT_001aa9c8;
      if ((int)uVar42 < 0) {
        uVar18 = *(uint *)(param_2 + 0x90);
        bVar1 = (uVar18 & 3) != 0;
        uVar10 = *(uint *)(local_5c + -0x2bf8);
        if (bVar1) {
          uVar10 = uVar10 & 0xffffff | 0x4000000;
        }
        uVar16 = (uint)bVar1;
        if ((uVar18 & 0xc) != 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x10000 | uVar10 & 0xff00ffff;
        }
        if ((uVar18 & 0x30) != 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x100 | uVar10 & 0xffff00ff;
        }
        if ((uVar18 & 0xc0) != 0) {
          uVar18 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = uVar18 | uVar10 & 0xffffff00;
        }
      }
      puVar37 = (uint *)**(undefined4 **)(param_2 + 100);
      if ((*puVar37 & 0x400000) != 0) {
        uVar10 = *(uint *)(local_5c + -0x2bf8);
        iVar32 = FUN_0019e990(puVar37,0);
        puVar36 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar32 * 4) == 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x1000000 | uVar10 & 0xffffff;
        }
        iVar32 = FUN_0019e990(puVar37,1);
        if (*(int *)(puVar36 + iVar32 * 4) == 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x10000 | uVar10 & 0xff00ffff;
        }
        iVar32 = FUN_0019e990(puVar37,2);
        if (*(int *)(puVar36 + iVar32 * 4) == 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x100 | uVar10 & 0xffff00ff;
        }
        iVar32 = FUN_0019e990(puVar37,3);
        if (*(int *)(puVar36 + iVar32 * 4) == 0) {
          uVar10 = uVar16 + 4 | uVar10 & 0xffffff00;
        }
      }
      iVar40 = (int)(short)*puVar37;
      iVar32 = *(int *)(param_1 + 0x3d8);
      if (iVar40 <= *(int *)(param_1 + 0x3d8)) {
        iVar32 = iVar40;
      }
      iVar45 = *(int *)(param_1 + 0x3dc);
      *(int *)(param_1 + 0x3d8) = iVar32;
      if (iVar45 <= iVar40) {
        iVar45 = iVar40 + 1;
      }
      *(int *)(param_1 + 0x3dc) = iVar45;
      piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      (**(code **)(*piVar17 + 0x4c))
                (piVar17,param_1,uVar42 >> 0x10 & 0x3f,puVar37,uVar10,
                 *(undefined4 *)(param_1 + 0x3a0),1,0);
      iVar40 = *(int *)(local_11c + 8);
      iVar32 = local_11c;
      while (iVar45 = iVar40, iVar45 != 0) {
        FUN_0019401c(iVar32);
        ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
        iVar32 = iVar45;
        iVar40 = *(int *)(iVar45 + 8);
      }
      local_124 = PTR_DAT_001e8b48 + 8;
      local_118 = local_124;
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      iVar32 = FUN_000ec27c(param_1,*puVar37 >> 0x10 & 0x1f);
      uVar10 = *puVar37;
      local_178 = DAT_001aa9dc;
      if ((int)uVar10 < 0) {
        uVar42 = *(uint *)(param_2 + 0x90);
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = (ushort)(((uint)(byte)(((uVar42 & 0xc0) == 0) << 1) << 0x14) >> 0x15);
        local_178 = (undefined *)
                    CONCAT13((uVar42 & 3) == 0,CONCAT12((uVar42 & 0xc) == 0,(*(unsigned short *)((unsigned char *)&(local_178) + 2))));
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = CONCAT11((uVar42 & 0x30) == 0,(undefined1)local_178);
      }
      iVar40 = (int)(short)*(uint *)**(undefined4 **)(param_2 + 100);
      uVar44 = FUN_000ec208(param_1,*(uint *)**(undefined4 **)(param_2 + 100) >> 0x10 & 0x3f);
      if (iVar32 == 0) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x44) = iVar40;
      }
      else if (iVar32 == 1) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x48) = iVar40;
      }
      iVar45 = *(int *)(param_1 + 1000);
      if (iVar40 <= *(int *)(param_1 + 1000)) {
        iVar45 = iVar40;
      }
      iVar38 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar45;
      if (iVar38 <= iVar40) {
        iVar38 = iVar40 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar38;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      piVar17 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar44,iVar40,0);
      uVar44 = (**(code **)(*piVar17 + 0x2c))();
      local_70 = &local_178;
      iVar40 = 0;
      do {
        if (*(char *)(iVar40 + (int)local_70) == '\0') {
          ((int (*)())FUN_00104104)(uVar44,iVar40,iVar32,uVar10 >> 0x15 & 0xff);
        }
        bVar1 = iVar40 != 3;
        iVar40 = iVar40 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x1c:
    case 0x1d:
    case 0x79:
      iVar32 = *(int *)(param_2 + 0x5c);
      uVar42 = *(uint *)**(undefined4 **)(param_2 + 100);
      uVar10 = *(uint *)**(undefined4 **)(param_2 + 100);
      if (iVar32 < 1) {
        iVar32 = 0;
      }
      else {
        puVar22 = &local_124;
        puVar15 = (undefined4 *)(*(int *)(param_2 + 0x58) * 4 + param_2 + 0x8c);
        iVar40 = iVar32;
        do {
          uVar44 = *puVar15;
          puVar15 = puVar15 + 1;
          *puVar22 = uVar44;
          puVar22 = puVar22 + 1;
          iVar40 = iVar40 + -1;
        } while (iVar40 != 0);
      }
      ((int (*)())FUN_000fafa4)(param_1,uVar42 >> 0x10 & 0x3f,(int)(short)uVar10,iVar32,&local_124);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      uVar44 = *(undefined4 *)(iVar40 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
      *puVar15 = uVar44;
      piVar17 = puVar15 + 1;
      FUN_0010502c(piVar17,0x94,*(undefined4 *)(param_1 + 8));
      uVar44 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2f,0,0);
      FUN_001046c8(piVar17,0,uVar44);
      puVar15[0x4c] = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      bVar1 = local_ac != 0;
      if (bVar1) {
        (**(code **)(*piVar17 + 0x90))(piVar17,uVar44);
      }
      uVar10 = *puVar37;
      uVar42 = uVar10 >> 0x17 & 0x3f;
      if (4 < uVar42) {
        uVar42 = 0;
      }
      puVar33 = (uint *)**(undefined4 **)(param_2 + 0x6c);
      uVar16 = *puVar33;
      uVar48 = FUN_000ec208(param_1,*puVar33 >> 0x10 & 0x3f);
      puVar37 = *(uint **)(*(int *)(param_2 + 0x6c) + 4);
      uVar18 = *puVar37;
      if ((((uVar18 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar32 = 0xf;
      }
      else {
        iVar32 = (int)(short)*puVar37;
      }
      uVar24 = FUN_000ec208(param_1,uVar18 >> 0x10 & 0x3f);
      uVar25 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2b,0,0);
      piVar17 = (int *)((int (*)())FUN_001043f0)(0x14,*(undefined4 *)(param_1 + 8));
      iVar40 = FUN_001054ec(piVar17,1);
      *(undefined4 *)(iVar40 + 0xc) = uVar48;
      local_178 = DAT_001aa9a8;
      *(int *)(iVar40 + 8) = (int)(short)uVar16;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,puVar33,1,piVar17);
      uVar48 = DAT_001aa9cc;
      iVar40 = FUN_001054ec(piVar17,1);
      *(undefined4 *)(iVar40 + 0x10) = uVar48;
      dVar49 = (double)FLOAT_001aa0d4;
      FUN_000f79c4(dVar49,(double)FLOAT_001aa0e8,dVar49,dVar49,piVar17,param_1,2);
      local_8c = (uint)(short)((ushort)(uVar10 >> 0x10) & 0x3f);
      local_80 = local_8c | 0x120000;
      local_88 = local_8c | 0x100000;
      local_84 = local_8c | 0x110000;
      local_8c = local_8c | 0xf0000;
      FUN_000f771c(piVar17,param_1,3,local_80,local_84,local_88,local_8c);
      iVar40 = FUN_001054ec(piVar17,0);
      *(undefined4 *)(iVar40 + 0xc) = 0x2b;
      *(undefined4 *)(iVar40 + 8) = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      (**(code **)(*piVar17 + 0x90))(piVar17,uVar44);
      if (bVar1) {
        (**(code **)(*piVar17 + 0x90))(piVar17,uVar25);
      }
      FUN_0010469c(piVar17,param_1,0x2b,0);
      piVar17[0x20] = 1;
      piVar17 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
      iVar40 = FUN_001054ec(piVar17,0);
      *(uint *)(iVar40 + 8) = uVar42;
      *(undefined4 *)(iVar40 + 0xc) = 0x2c;
      iVar40 = FUN_001054ec(piVar17,1);
      *(undefined4 *)(iVar40 + 0xc) = uVar24;
      *(int *)(iVar40 + 8) = iVar32;
      (**(code **)(*piVar17 + 0x90))(piVar17,uVar25);
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      FUN_0010469c(piVar17,param_1,0x2c,uVar42);
      local_ac = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      uVar42 = *puVar37;
      puVar37 = (uint *)**(undefined4 **)(param_2 + 100);
      uVar10 = DAT_001aa9c8;
      if ((*puVar37 & 0x400000) != 0) {
        uVar10 = *(uint *)(local_5c + -0x2bf8);
        iVar32 = FUN_0019e990(puVar37,0);
        if (*(int *)(PTR_DAT_001e8bc8 + iVar32 * 4) == 0) {
          uVar10 = uVar10 & 0xffffff | 0x4000000;
        }
        uVar16 = (uint)(*(int *)(PTR_DAT_001e8bc8 + iVar32 * 4) == 0);
        iVar32 = FUN_0019e990(puVar37,1);
        puVar36 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar32 * 4) == 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x10000 | uVar10 & 0xff00ffff;
        }
        iVar32 = FUN_0019e990(puVar37,2);
        if (*(int *)(puVar36 + iVar32 * 4) == 0) {
          iVar32 = uVar16 + 4;
          uVar16 = uVar16 + 1;
          uVar10 = iVar32 * 0x100 | uVar10 & 0xffff00ff;
        }
        iVar32 = FUN_0019e990(puVar37,3);
        if (*(int *)(puVar36 + iVar32 * 4) == 0) {
          iVar40 = *(int *)(param_1 + 8);
          uVar10 = uVar16 + 4 | uVar10 & 0xffffff00;
        }
        else {
          iVar40 = *(int *)(param_1 + 8);
        }
      }
      (**(code **)(**(int **)(iVar40 + 0x30c) + 0x4c))
                (*(int **)(iVar40 + 0x30c),param_1,uVar42 >> 0x10 & 0x3f,puVar37,uVar10,local_180,0,
                 **(undefined4 **)(param_2 + 0x6c));
      goto switchD_000fdaf0_caseD_2;
    case 0x6e:
      uVar44 = *(undefined4 *)(iVar40 + 0x374);
      uVar48 = *(undefined4 *)(*(int *)(param_2 + 0x58) * 4 + param_2 + 0x8c);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x134);
      *puVar15 = uVar44;
      piVar17 = puVar15 + 1;
      FUN_000ea148(piVar17,*(undefined4 *)(param_1 + 8));
      puVar15[0x4c] = uVar48;
      puVar15[1] = PTR_DAT_001e8bd0 + 8;
      local_180 = piVar17;
      FUN_000ec3ac(param_1,local_184,piVar17);
      FUN_000e8e4c(local_184,local_180);
      local_184 = local_180;
      uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x130);
      *puVar15 = uVar44;
      piVar17 = puVar15 + 1;
      FUN_000ea020(piVar17,*(undefined4 *)(param_1 + 8));
      local_180 = piVar17;
      FUN_000ec3ac(param_1,local_184,piVar17);
      FUN_000e8e4c(local_184,local_180);
      local_184 = local_180;
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar17 = (int *)FUN_00193e18(*(undefined4 *)(iVar40 + 0x378),0xc);
      piVar17[1] = 0;
      piVar17[2] = 0;
      uVar44 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      iVar40 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar40;
      *piVar17 = iVar40;
      iVar32 = FUN_001054ec(uVar44,0);
      *(undefined4 *)(iVar32 + 0xc) = 0;
      *(int *)(iVar32 + 8) = iVar40;
      local_178 = DAT_001aa9a8;
      ((int (*)())FUN_000fb3d4)(param_1,local_68,puVar37,**(undefined4 **)(param_2 + 0x6c),puVar35,&local_174,
                   &local_13c);
      uVar10 = *(uint *)**(undefined4 **)(param_2 + 0x6c);
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar32 = 0xf;
      }
      else {
        iVar32 = (int)(short)*(uint *)**(undefined4 **)(param_2 + 0x6c);
      }
      uVar48 = FUN_000ec208(param_1,uVar10 >> 0x10 & 0x3f);
      iVar40 = FUN_001054ec(uVar44,1);
      *(undefined4 *)(iVar40 + 0xc) = uVar48;
      *(int *)(iVar40 + 8) = iVar32;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,**(undefined4 **)(param_2 + 0x6c),1,uVar44);
      iVar40 = *(int *)(local_14c + 8);
      iVar32 = local_14c;
      while (iVar45 = iVar40, iVar45 != 0) {
        FUN_0019401c(iVar32);
        ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
        iVar32 = iVar45;
        iVar40 = *(int *)(iVar45 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,uVar44,local_180);
      uVar10 = local_b0[1];
      if (uVar10 < *local_b0) {
        _memset((void *)(uVar10 * 4 + local_b0[2]),0,4);
        local_b0[1] = uVar10 + 1;
        piVar13 = (int *)(uVar10 * 4 + local_b0[2]);
      }
      else {
        piVar13 = (int *)FUN_0019423c(local_b0,uVar10);
      }
      goto LAB_000febe0;
    case 0x73:
      uVar44 = *(undefined4 *)(iVar40 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
      *puVar15 = uVar44;
      piVar17 = puVar15 + 1;
      FUN_0010502c(piVar17,0xf8,*(undefined4 *)(param_1 + 8));
      puVar15[0x4c] = *(undefined4 *)(*(int *)(param_2 + 0x58) * 4 + param_2 + 0x8c);
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      break;
    case 0x76:
    case 0x77:
      if ((iVar32 == 0x76) && ((int)*puVar37 < 0)) {
        iVar45 = *(int *)(param_2 + 0x28);
        iVar32 = *(int *)(*(int *)(param_2 + 0x58) * 4 + param_2 + 0x8c);
        uVar44 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x43,0xffffffff,0);
        iVar40 = FUN_00109b74(0x10a,*(undefined4 *)(param_1 + 8));
        *(int *)(param_1 + 0x354) = iVar40;
        FUN_001046c8(iVar40,0,uVar44);
        *(int *)(iVar40 + 300) = iVar32 * 4 + iVar45;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a0),iVar40);
      }
      else {
        iVar32 = 1;
        puVar37 = (uint *)**(undefined4 **)(param_2 + 0x6c);
        uVar42 = (uint)(ushort)*puVar37;
        uVar10 = *puVar37 >> 0x10 & 0x3f;
        if ((int)*puVar37 < 0) {
          iVar32 = 2;
          uVar42 = uVar42 | puVar37[1] << 0x10;
        }
        uVar16 = puVar37[iVar32];
        if (uVar10 == 0x1c) {
          puVar37 = *(uint **)(param_1 + 0x90);
          if (puVar37 == (uint *)0x0) {
            uVar44 = *(undefined4 *)(iVar40 + 0x374);
            puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
            puVar37 = puVar15 + 1;
            *puVar15 = uVar44;
            puVar15[1] = 2;
            puVar15[2] = 0;
            puVar15[4] = uVar44;
            uVar44 = FUN_00193e18(uVar44,8);
            puVar15[3] = uVar44;
            *(uint **)(param_1 + 0x90) = puVar37;
          }
        }
        else {
          puVar37 = *(uint **)(param_1 + 0x8c);
          if (puVar37 == (uint *)0x0) {
            uVar44 = *(undefined4 *)(iVar40 + 0x374);
            puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
            puVar37 = puVar15 + 1;
            *puVar15 = uVar44;
            puVar15[1] = 2;
            puVar15[2] = 0;
            puVar15[4] = uVar44;
            uVar44 = FUN_00193e18(uVar44,8);
            puVar15[3] = uVar44;
            *(uint **)(param_1 + 0x8c) = puVar37;
          }
        }
        if (uVar42 < *puVar37) {
          uVar18 = puVar37[1];
          if (uVar18 <= uVar42) {
            _memset((void *)(uVar18 * 4 + puVar37[2]),0,(uVar42 - uVar18) * 4 + 4);
            puVar37[1] = uVar42 + 1;
          }
          puVar37 = (uint *)(uVar42 * 4 + puVar37[2]);
        }
        else {
          puVar37 = (uint *)FUN_0019423c(puVar37,uVar42);
        }
        *puVar37 = uVar16;
        iVar32 = (uVar42 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x434);
        *(uint *)(iVar32 + 8) = 1 << (uVar42 & 0x1f) | *(uint *)(iVar32 + 8);
        if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) != 0) {
          uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
          *puVar15 = uVar44;
          puVar22 = puVar15 + 1;
          FUN_00109a80(puVar22,0xfa,*(undefined4 *)(param_1 + 8));
          uVar44 = FUN_000ec208(param_1,uVar10);
          iVar32 = FUN_001054ec(puVar22,0);
          *(undefined4 *)(iVar32 + 0xc) = uVar44;
          *(uint *)(iVar32 + 8) = uVar42;
          puVar15[0x4c] = uVar16;
          ((int (*)())FUN_000f92fc)(param_1,puVar22,*(undefined4 *)(param_1 + 0x3a0));
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x78:
      *(uint *)(param_1 + 0x400) = *puVar37 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7a:
      *(uint *)(param_1 + 0x3f8) = *puVar37 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7c:
      *(uint *)(param_1 + 0x3fc) = *puVar37 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7d:
      puVar33 = (uint *)**(undefined4 **)(param_2 + 100);
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
          local_178 = DAT_001aa9dc;
          iVar40 = (int)(short)*puVar33;
          uVar44 = FUN_000ec208(param_1,*puVar33 >> 0x10 & 0x3f);
          iVar32 = FUN_000ec27c(param_1,*puVar37 >> 0x10 & 0x3fff);
          if (iVar32 == 0) {
            *(int *)(*(int *)(param_1 + 0x3ac) + 0x44) = iVar40;
          }
          else if (iVar32 == 1) {
            *(int *)(*(int *)(param_1 + 0x3ac) + 0x48) = iVar40;
          }
          iVar45 = *(int *)(param_1 + 1000);
          if (iVar40 <= *(int *)(param_1 + 1000)) {
            iVar45 = iVar40;
          }
          iVar38 = *(int *)(param_1 + 0x3ec);
          *(int *)(param_1 + 1000) = iVar45;
          if (iVar38 <= iVar40) {
            iVar38 = iVar40 + 1;
          }
          *(int *)(param_1 + 0x3ec) = iVar38;
          *(undefined4 *)(param_1 + 0x3f4) = 0x24;
          if (iVar32 == 0xd) {
            iVar45 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar45 + 0x4c) == -1) {
              *(int *)(iVar45 + 0x4c) = iVar40;
            }
            else {
              *(int *)(iVar45 + 0x54) = iVar40;
            }
          }
          else if (iVar32 == 0xe) {
            iVar45 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar45 + 0x50) == -1) {
              *(int *)(iVar45 + 0x50) = iVar40;
            }
            else {
              *(int *)(iVar45 + 0x58) = iVar40;
            }
          }
          else if (iVar32 == 0xb) {
            *(int *)(*(int *)(param_1 + 0x3ac) + 0x5c) = iVar40;
          }
          else if (iVar32 == 0xc) {
            *(int *)(*(int *)(param_1 + 0x3ac) + 0x60) = iVar40;
          }
          else if (iVar32 == 0xf) {
            *(int *)(*(int *)(param_1 + 0x3ac) + 100) = iVar40;
          }
          piVar17 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar44,iVar40,0);
          iVar45 = (**(code **)(*piVar17 + 0x2c))();
          local_70 = &local_178;
          *(int *)(iVar45 + 0x140) = iVar40;
          iVar38 = 0;
          do {
            if (*(char *)(iVar38 + (int)local_70) == '\0') {
              ((int (*)())FUN_00104104)(iVar45,iVar38,iVar32,iVar40);
            }
            bVar1 = iVar38 != 3;
            iVar38 = iVar38 + 1;
          } while (bVar1);
        }
      }
      else {
        (**(code **)(*piVar17 + 0x54))
                  (piVar17,(short)*puVar33,*puVar37 >> 0x10 & 0x3fff,(short)*puVar33,DAT_001aa9a8,0,
                   0,0);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      uVar42 = *puVar37 >> 0xe & 0x1f;
      uVar44 = FUN_000ec27c(param_1,uVar42);
      uVar10 = *puVar37 >> 0x13 & 7;
      if (uVar10 == 3) {
        bVar1 = true;
        bVar2 = false;
        bVar3 = false;
      }
      else if (uVar10 < 4) {
        if (uVar10 == 1) {
          bVar1 = false;
          bVar2 = false;
          bVar3 = true;
        }
        else {
LAB_000feeb8:
          bVar1 = false;
          bVar2 = false;
          bVar3 = false;
        }
      }
      else if (uVar10 == 4) {
        bVar1 = false;
        bVar2 = true;
        bVar3 = false;
      }
      else {
        if (uVar10 != 5) goto LAB_000feeb8;
        bVar1 = true;
        bVar2 = true;
        bVar3 = false;
      }
      puVar37 = (uint *)**(undefined4 **)(param_2 + 100);
      uVar10 = *puVar37;
      if ((uVar10 & 0x400000) == 0) {
        if ((uVar10 & 0x2000000) == 0) {
          puVar39 = (uint *)0x0;
          puVar33 = (uint *)0x0;
        }
        else {
          puVar39 = puVar37 + 1;
          puVar33 = (uint *)0x0;
        }
      }
      else {
        puVar33 = puVar37 + 1;
        puVar39 = (uint *)0x0;
        if ((uVar10 & 0x2000000) != 0) {
          puVar39 = puVar37 + 2;
        }
      }
      if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) == 0)) {
        if (uVar42 == 10) {
          local_174 = (uint)(ushort)*puVar39;
          local_178 = (undefined *)DAT_001aa9d0;
          puVar37 = &local_178;
          if ((*puVar33 & 3) == 1) {
            puVar37 = &DAT_001aa9d0;
          }
          puVar39 = &local_178;
          local_178 = (undefined *)*puVar37;
          if ((*puVar33 & 0xc) == 4) {
            puVar39 = &DAT_001aa9c4;
          }
          puVar37 = &local_178;
          local_178 = (undefined *)*puVar39;
          if ((*puVar33 & 0x30) == 0x10) {
            puVar37 = &DAT_001aa9c0;
          }
          puVar39 = &local_178;
          local_178 = (undefined *)*puVar37;
          if ((*puVar33 & 0xc0) == 0x40) {
            puVar39 = (uint *)&DAT_001aa9bc;
          }
          local_178 = (undefined *)*puVar39;
          local_170 = local_178;
        }
      }
      else {
        uVar16 = uVar10 >> 0x10 & 0x3f;
        uVar42 = (uint)(ushort)*puVar37;
        uVar48 = FUN_000ec208(param_1,uVar16);
        puVar33 = local_13c;
        uVar10 = *(uint *)(param_1 + 1000);
        if ((int)uVar42 <= (int)*(uint *)(param_1 + 1000)) {
          uVar10 = uVar42;
        }
        iVar32 = *(int *)(param_1 + 0x3ec);
        *(uint *)(param_1 + 1000) = uVar10;
        if (iVar32 <= (int)uVar42) {
          iVar32 = uVar42 + 1;
        }
        *(int *)(param_1 + 0x3ec) = iVar32;
        *(undefined4 *)(param_1 + 0x3f4) = 0x24;
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          iVar32 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,uVar42,0,DAT_001aa9c8);
          iVar32 = *(int *)(iVar32 + 0x38);
          if (!bVar1) {
            *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 1;
          }
          if (bVar2) {
            *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 4;
          }
          if (bVar3) {
            *(uint *)(iVar32 + 0x13c) = *(uint *)(iVar32 + 0x13c) | 2;
          }
          iVar40 = 0;
          do {
            ((int (*)())FUN_001041d0)(iVar32,iVar40,1,uVar44,uVar42);
            bVar1 = iVar40 != 3;
            iVar40 = iVar40 + 1;
          } while (bVar1);
        }
        else if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar17 + 0x4c))
                    (piVar17,param_1,uVar42,puVar37,DAT_001aa9c8,*(undefined4 *)(param_1 + 0x3a0),1,
                     0);
        }
        else if (uVar16 != 9) {
          uVar10 = (uint)(ushort)*puVar39;
          if (uVar10 < *local_13c) {
            uVar42 = local_13c[1];
            if (uVar42 <= uVar10) {
              _memset((void *)(uVar42 * 4 + local_13c[2]),0,(uVar10 - uVar42) * 4 + 4);
              puVar33[1] = uVar10 + 1;
            }
            puVar15 = (undefined4 *)(uVar10 * 4 + puVar33[2]);
          }
          else {
            puVar15 = (undefined4 *)FUN_0019423c(local_13c,uVar10);
          }
          uVar48 = *puVar15;
          iVar32 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar32;
          uVar44 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0,iVar32,0);
          FUN_001046c8(uVar48,0,uVar44);
          goto LAB_000ff070;
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x80:
      bVar4 = *(byte *)(param_2 + 0x8d);
      uVar10 = *puVar37 >> 0x18 & 0xf;
      if (piVar17[0x14] < (int)(uint)bVar4) {
        FUN_000e1534(iVar40,7);
      }
      uVar42 = bVar4 >> 3 & 0x1c;
      iVar32 = (uint)bVar4 * 0xc;
      *(uint *)((int)local_a0 + uVar42 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar42 + 8);
      *(undefined4 *)(*(int *)(param_1 + 0x78) + iVar32) = 1;
      if (uVar10 != 0) {
        *(uint *)(iVar32 + *(int *)(param_1 + 0x78) + 4) = uVar10;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      local_a4 = local_a4 + 1;
      if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
        if (puVar14[2] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x180000;
        }
        if (local_a8[1] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80000;
        }
        iVar32 = ((int (*)())FUN_001043f0)(*(undefined4 *)
                               (iVar32 * 0x24 + *(int *)(*(int *)(iVar40 + 0x30c) + 0xc)),iVar40);
        iVar40 = FUN_001054ec(iVar32,0);
        uVar10 = DAT_001aa9d0;
        *(undefined4 *)(iVar40 + 0xc) = 0x2c;
        *(undefined4 *)(iVar40 + 8) = 0;
        *(uint *)(iVar32 + 0x9c) = uVar10;
        iVar40 = FUN_001054ec(iVar32,1);
        *(undefined4 *)(iVar40 + 0xc) = 0x2c;
        *(undefined4 *)(iVar40 + 8) = 0;
        uVar44 = DAT_001aa9cc;
        iVar40 = FUN_001054ec(iVar32,1);
        *(undefined4 *)(iVar40 + 0x10) = uVar44;
        ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x87:
      uVar42 = (uint)*(byte *)(param_2 + 0x8d);
      uVar10 = *puVar37;
      if (*(int *)(param_1 + 0x7c) < (int)uVar42) {
        *(uint *)(param_1 + 0x7c) = uVar42;
      }
      puVar36 = DAT_001aa9a8;
      *(uint *)(param_1 + 0x84) = 1 << (uVar42 & 0x3f) | *(uint *)(param_1 + 0x84);
      puVar12 = DAT_001aa9dc;
      local_178 = puVar36;
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar32 = *(int *)(iVar40 + 0x3ac) + -1;
      *(int *)(iVar40 + 0x3ac) = iVar32;
      uVar44 = FUN_00127608(uVar44,0,iVar32,0);
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar32 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar32;
      uVar48 = FUN_00127608(uVar48,0,iVar32,0);
      uVar24 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar24,0,uVar48);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar24,1,puVar12,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar24,local_180);
      iVar32 = ((int (*)())FUN_001043f0)(0x109,*(undefined4 *)(param_1 + 8));
      *(uint *)(iVar32 + 0x134) = uVar42;
      FUN_001046c8(iVar32,0,uVar44);
      FUN_001046c8(iVar32,1,uVar48);
      ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
      puVar8 = PTR_DAT_001e8b8c;
      puVar7 = PTR_DAT_001e8b64;
      local_178 = puVar36;
      if ((uVar10 & 0x1f000000) != 0x1000000) {
        iVar32 = 0;
        do {
          iVar40 = ((int (*)())FUN_001043f0)(0xe1,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar40,0,uVar44);
          FUN_001046c8(iVar40,1,uVar44);
          uVar48 = *(undefined4 *)(puVar8 + iVar32);
          *(undefined4 *)(iVar40 + 0x9c) = *(undefined4 *)(puVar7 + iVar32);
          iVar45 = FUN_001054ec(iVar40,1);
          *(undefined4 *)(iVar45 + 0x10) = uVar48;
          ((int (*)())FUN_000f92fc)(param_1,iVar40,local_180);
          bVar1 = iVar32 != 0xc;
          iVar32 = iVar32 + 4;
        } while (bVar1);
      }
      uVar48 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,uVar48,1,puVar12,local_70);
      FUN_001046c8(uVar48,1,uVar44);
LAB_000ff070:
      ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      uVar44 = *(undefined4 *)(iVar40 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
      *puVar15 = uVar44;
      puVar22 = puVar15 + 1;
      FUN_0010502c(puVar22,0xb4,*(undefined4 *)(param_1 + 8));
      if ((*puVar37 & 0x3fff0000) != 0) {
        puVar15[0x4c] = 1;
      }
      ((int (*)())FUN_000fb3d4)(param_1,local_68,puVar37,**(undefined4 **)(param_2 + 0x6c),puVar35,&local_174,
                   &local_13c);
      uVar10 = *(uint *)**(undefined4 **)(param_2 + 0x6c);
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar32 = 0xf;
      }
      else {
        iVar32 = (int)(short)*(uint *)**(undefined4 **)(param_2 + 0x6c);
      }
      uVar10 = uVar10 >> 0x10 & 0x3f;
      iVar40 = FUN_00127534(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
      if (iVar40 == 0) {
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
        *puVar15 = uVar44;
        puVar46 = puVar15 + 1;
        FUN_00108918(puVar46,*(undefined4 *)(param_1 + 8));
        puVar36 = DAT_001aa9dc;
        puVar15[6] = puVar15[6] | 0x10000;
        *(undefined4 **)(param_1 + 0x350) = puVar46;
        puVar15[0x28] = puVar36;
        iVar40 = FUN_001275a0(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
        FUN_001046c8(puVar46,0,iVar40);
        FUN_001046c8(puVar46,1,iVar40);
        puVar36 = DAT_001aa9a8;
        iVar45 = FUN_001054ec(puVar46,1);
        *(undefined **)(iVar45 + 0x10) = puVar36;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a8),puVar46);
        FUN_0012306c(iVar40,puVar46);
        FUN_001236e4(iVar40,1,puVar46);
      }
      FUN_001046c8(puVar22,0,iVar40);
      uVar44 = FUN_000ec208(param_1,uVar10);
      iVar40 = FUN_001054ec(puVar22,1);
      *(undefined4 *)(iVar40 + 0xc) = uVar44;
      *(int *)(iVar40 + 8) = iVar32;
      uVar44 = FUN_000ec208(param_1,uVar10);
      iVar40 = FUN_001054ec(puVar22,2);
      *(undefined4 *)(iVar40 + 0xc) = uVar44;
      *(int *)(iVar40 + 8) = iVar32;
      uVar44 = FUN_000ec208(param_1,uVar10);
      iVar40 = FUN_001054ec(puVar22,3);
      *(undefined4 *)(iVar40 + 0xc) = uVar44;
      puVar36 = DAT_001aa9a8;
      local_70 = &local_178;
      *(int *)(iVar40 + 8) = iVar32;
      (*(unsigned char *)((unsigned char *)&(local_178) + 1)) = (undefined1)((uint)puVar36 >> 0x10);
      uVar9 = (*(unsigned char *)((unsigned char *)&(local_178) + 1));
      (*(unsigned short *)((unsigned char *)&(local_178) + 0)) = (undefined2)((uint)puVar36 >> 0x10);
      (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = CONCAT11(uVar9,uVar9);
      ((int (*)())FUN_000f8aa0)(param_1,local_70,**(undefined4 **)(param_2 + 0x6c),1,puVar22);
      local_178 = (undefined *)DAT_001aa9d8;
      ((int (*)())FUN_000f8aa0)(param_1,local_70,**(undefined4 **)(param_2 + 0x6c),2,puVar22);
      local_178 = DAT_001aa9d4;
      ((int (*)())FUN_000f8aa0)(param_1,local_70,**(undefined4 **)(param_2 + 0x6c),3,puVar22);
      iVar40 = *(int *)(local_14c + 8);
      iVar32 = local_14c;
      while (iVar45 = iVar40, iVar45 != 0) {
        FUN_0019401c(iVar32);
        ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
        iVar32 = iVar45;
        iVar40 = *(int *)(iVar45 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,puVar22,local_180);
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      uVar44 = *(undefined4 *)(iVar40 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x168);
      *puVar15 = uVar44;
      piVar17 = puVar15 + 1;
      FUN_0010502c(piVar17,0x106,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
    }
    puVar37 = *(uint **)(param_1 + 0x414);
    uVar10 = puVar37[1];
    if (uVar10 < *puVar37) {
      _memset((void *)(uVar10 * 4 + puVar37[2]),0,4);
      piVar13 = (int *)(uVar10 * 4 + puVar37[2]);
      puVar37[1] = uVar10 + 1;
    }
    else {
      piVar13 = (int *)FUN_0019423c(puVar37,uVar10);
    }
LAB_000febe0:
    *piVar13 = (int)piVar17;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    bVar1 = false;
    break;
  case 5:
    local_78 = &DAT_001ad5d8;
    local_60 = &DAT_001ad5d8;
    iVar45 = *(int *)(iVar32 * 0x24 + iVar45 + 0x18);
    local_124 = DAT_001aa9dc;
    local_178 = DAT_001aa9a8;
    uVar44 = *(undefined4 *)(iVar40 + 0x378);
    puVar15 = (undefined4 *)FUN_00193e18(uVar44,0x14);
    puVar33 = puVar15 + 1;
    *puVar15 = uVar44;
    puVar15[1] = 2;
    puVar15[2] = 0;
    puVar15[4] = uVar44;
    uVar44 = FUN_00193e18(uVar44,8);
    puVar15[3] = uVar44;
    uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar22 = (undefined4 *)FUN_00193e18(uVar44,0x14);
    puVar46 = puVar22 + 1;
    *puVar22 = uVar44;
    puVar22[1] = 2;
    puVar22[2] = 0;
    puVar22[4] = uVar44;
    uVar44 = FUN_00193e18(uVar44,8);
    puVar22[3] = uVar44;
    local_17c = (int *)0x0;
    _memcpy(&local_104,&DAT_001aaa2c,0x24);
    iVar43 = *(int *)(param_1 + 8);
    iVar38 = 0;
    uVar44 = *(undefined4 *)(*(int *)(iVar43 + 0x30c) + 0xc);
    local_c0 = ((int (*)())FUN_000f8960)(iVar32,uVar44);
    iVar40 = ((int (*)())FUN_000f8970)(iVar32,uVar44);
    if (0 < local_c0) {
      do {
        iVar41 = iVar38 << 2;
        for (iVar19 = 0;
            iVar20 = ((int (*)())FUN_000f8980)(iVar32,iVar38,*(undefined4 *)(*(int *)(iVar43 + 0x30c) + 0xc)),
            iVar19 <= iVar20; iVar19 = iVar19 + 1) {
          ((int (*)())FUN_000f9a58)(param_1,local_6c,*(undefined4 *)(*(int *)(param_2 + 100) + iVar41),puVar35,
                       local_a4);
          iVar43 = *(int *)(param_1 + 8);
          iVar41 = iVar41 + 0x14;
        }
        iVar38 = iVar38 + 1;
      } while (local_c0 != iVar38);
    }
    iVar38 = 0;
    if (0 < iVar40) {
      do {
        iVar41 = iVar38 << 2;
        iVar20 = local_c0 + iVar38;
        for (iVar19 = 0;
            iVar47 = ((int (*)())FUN_000f8980)(iVar32,iVar20,*(undefined4 *)(*(int *)(iVar43 + 0x30c) + 0xc)),
            iVar19 <= iVar47; iVar19 = iVar19 + 1) {
          ((int (*)())FUN_000fb3d4)(param_1,local_68,puVar37,*(undefined4 *)(*(int *)(param_2 + 0x6c) + iVar41),
                       puVar35,&local_174,&local_13c);
          iVar43 = *(int *)(param_1 + 8);
          iVar41 = iVar41 + 0x14;
        }
        iVar38 = iVar38 + 1;
      } while (iVar40 != iVar38);
    }
    iVar38 = *(int *)(local_14c + 8);
    iVar40 = local_14c;
    while (iVar43 = iVar38, iVar43 != 0) {
      FUN_0019401c(iVar40);
      ((int (*)())FUN_000f92fc)(param_1,iVar40,local_180);
      iVar40 = iVar43;
      iVar38 = *(int *)(iVar43 + 8);
    }
    local_b4 = 0;
    piVar17 = (int *)0x0;
    iVar40 = 0;
LAB_001005f4:
    piVar13 = local_180;
    puVar36 = PTR_DAT_001e8bd4;
    uVar10 = *(uint *)(iVar45 + (int)local_17c * 4);
    if (0x71 < uVar10) goto switchD_0010061c_caseD_0;
    switch(uVar10) {
    default:
      goto switchD_0010061c_caseD_0;
    case 1:
    case 0x13:
    case 0x33:
    case 0x39:
    case 0x3b:
    case 0x3c:
    case 0x3e:
    case 0x40:
    case 0x4c:
    case 0x5e:
      goto switchD_0010061c_caseD_1;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
      iVar38 = ((int (*)())FUN_000fa958)(param_1,uVar10 - 2,iVar40,param_2,piVar17,local_c0,local_124,&local_178)
      ;
      if (iVar38 != 0) {
        FUN_00193f94(local_6c,iVar38);
      }
      goto LAB_001025c0;
    case 0x12:
      ((int (*)())FUN_00103d50)(piVar17 + iVar40 * 6 + 0x23,2,1);
      goto LAB_00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      uVar42 = *puVar37 >> 0x10 & 0x3fff;
      if (uVar10 == 0x14) {
        puVar36 = (PTR_DAT_001dc78c)[uVar42];
      }
      else if (uVar10 == 0x15) {
        puVar36 = (PTR_DAT_001dc77c)[uVar42];
      }
      else {
        puVar36 = (PTR_DAT_001dc76c)[uVar42];
      }
      goto LAB_001022b4;
    case 0x17:
      iVar38 = FUN_000e47f4(param_2);
      if ((iVar38 == 0x3e) || (iVar38 = FUN_000e47f4(param_2), iVar38 == 0x71)) {
        uVar10 = puVar14[2];
        if (uVar10 != 0) {
          piVar13 = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            piVar13 = (int *)((uVar10 - 1) * 4 + puVar14[3]);
          }
          iVar38 = *piVar13;
          uVar10 = local_a8[1];
          puVar36 = PTR_DAT_001e8bbc;
          if (uVar10 != 0) {
            piVar13 = (int *)0x0;
            if (uVar10 - 1 < uVar10) {
              piVar13 = (int *)((uVar10 - 1) * 4 + local_a8[2]);
            }
            if (local_188 <= *(int *)(*piVar13 + 0xb8)) {
              uVar44 = *(undefined4 *)(iVar38 + 0x154);
              uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
              puVar31 = (undefined4 *)FUN_00193e18(uVar48,0x138);
              *puVar31 = uVar48;
              piVar13 = puVar31 + 1;
              FUN_000ec0c8(piVar13,iVar38,*(undefined4 *)(iVar38 + 300),*(undefined4 *)(param_1 + 8)
                          );
              puVar31[0x2f] = local_188;
              FUN_000ec3ac(param_1,local_184,piVar13);
              FUN_000e8e4c(local_184,piVar13);
              FUN_000e8e4c(piVar13,uVar44);
              local_bc = 0;
              *(int *)(iVar38 + 0x138) = *(int *)(iVar38 + 0x138) + 1;
              local_184 = piVar13;
              break;
            }
          }
          goto LAB_00103718;
        }
      }
      else {
        iVar38 = FUN_000e47f4(param_2);
        puVar36 = PTR_DAT_001e8bb4;
        if (iVar38 == 0x72) {
          piVar13 = (int *)0x0;
          uVar10 = local_b0[1] - 1;
          if (uVar10 < local_b0[1]) {
            piVar13 = (int *)(uVar10 * 4 + local_b0[2]);
          }
          *(int *)(*piVar13 + 4) = *(int *)(*piVar13 + 4) + 1;
LAB_00103718:
          iVar45 = ((int (*)())FUN_000fd50c)(param_1,iVar45,&local_17c,0,puVar36,puVar46);
          goto LAB_0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      local_17c = (int *)((int)local_17c + 1);
      uVar10 = *(uint *)(iVar45 + (int)local_17c * 4);
      local_178 = (undefined *)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      local_bc = 0;
      break;
    case 0x20:
      local_17c = (int *)((int)local_17c + 1);
      uVar10 = *(uint *)(iVar45 + (int)local_17c * 4);
      local_124 = (undefined *)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      local_bc = 0;
      break;
    case 0x21:
      puVar36 = (undefined *)0x0;
      switch(*puVar37 >> 0x10 & 7) {
      case 0:
        puVar36 = PTR_DAT_001e8b80;
        break;
      case 1:
        puVar36 = PTR_DAT_001e8bac;
        break;
      case 2:
        puVar36 = PTR_DAT_001e8ba8;
        break;
      case 3:
        puVar36 = PTR_DAT_001e8bcc;
        break;
      case 4:
        puVar36 = PTR_DAT_001e8b94;
        break;
      case 5:
        puVar36 = PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      uVar10 = *puVar37 >> 0x16 & 7;
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      iVar38 = ((int (*)())FUN_001043f0)(0x12,*(undefined4 *)(param_1 + 8));
      if (local_100 == 0) {
        local_100 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = local_100;
      }
      iVar43 = local_100;
      iVar41 = FUN_001054ec(iVar38,0);
      *(int *)(iVar41 + 8) = iVar43;
      *(undefined4 *)(iVar41 + 0xc) = 0;
      uVar42 = *(uint *)**(undefined4 **)(param_2 + 0x6c);
      if ((((uVar42 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar41 = 0xf;
      }
      else {
        iVar41 = (int)(short)*(uint *)**(undefined4 **)(param_2 + 0x6c);
      }
      uVar44 = FUN_000ec208(param_1,uVar42 >> 0x10 & 0x3f);
      iVar19 = FUN_001054ec(iVar38,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar44;
      *(int *)(iVar19 + 8) = iVar41;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,**(undefined4 **)(param_2 + 0x6c),iVar40,iVar38);
      fVar5 = FLOAT_001aa0e8;
      if (uVar10 == 2) {
LAB_001021c0:
        dVar49 = (double)fVar5;
        FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,iVar38,param_1,2);
        ((int (*)())FUN_00103d50)(iVar38 + 0xbc,1,1);
      }
      else if (uVar10 < 3) {
        fVar5 = FLOAT_001aa10c;
        if (uVar10 == 1) goto LAB_001021c0;
      }
      else {
        fVar5 = FLOAT_001aa10c;
        if ((uVar10 == 3) || (fVar5 = FLOAT_001aa0e8, uVar10 == 4)) {
          dVar49 = (double)fVar5;
          FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,iVar38,param_1,2);
        }
      }
      ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      iVar38 = FUN_001054ec(piVar17,iVar40);
      *(int *)(iVar38 + 8) = iVar43;
      *(undefined4 *)(iVar38 + 0xc) = 0;
      iVar40 = iVar40 + 1;
      local_bc = 0;
      local_17c = (int *)((int)local_17c + 1);
      break;
    case 0x23:
      puVar36 = (undefined *)0x0;
      switch(*puVar37 >> 0x10 & 7) {
      case 0:
        puVar36 = PTR_DAT_001e8bc0;
        break;
      case 1:
        puVar36 = PTR_DAT_001e8b7c;
        break;
      case 2:
        puVar36 = PTR_DAT_001e8ba4;
        break;
      case 3:
        puVar36 = PTR_DAT_001e8b90;
        break;
      case 4:
        puVar36 = PTR_DAT_001e8bc4;
        break;
      case 5:
        puVar36 = PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (puVar14[2] != 0) {
        uVar10 = local_a8[1];
        puVar36 = PTR_DAT_001e8b78;
        if (uVar10 != 0) {
          piVar13 = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            piVar13 = (int *)((uVar10 - 1) * 4 + local_a8[2]);
          }
          if (local_188 <= *(int *)(*piVar13 + 0xb8)) {
            uVar10 = puVar14[2] - 1;
            piVar13 = (int *)0x0;
            if (uVar10 < (uint)puVar14[2]) {
              piVar13 = (int *)(uVar10 * 4 + puVar14[3]);
            }
            iVar38 = *piVar13;
            uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            uVar44 = *(undefined4 *)(iVar38 + 0x150);
            puVar31 = (undefined4 *)FUN_00193e18(uVar48,0x138);
            *puVar31 = uVar48;
            piVar13 = puVar31 + 1;
            FUN_000ec178(piVar13,iVar38,*(undefined4 *)(iVar38 + 300),*(undefined4 *)(param_1 + 8));
            puVar31[0x2f] = local_188;
            FUN_000ec3ac(param_1,local_184,piVar13);
            FUN_000e8e4c(local_184,piVar13);
            FUN_000e8e4c(piVar13,uVar44);
            local_bc = 0;
            *(undefined4 *)(iVar38 + 0x13c) = 1;
            local_184 = piVar13;
            break;
          }
        }
        goto LAB_00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      puVar31 = (undefined4 *)0x0;
      uVar10 = puVar15[2] - 1;
      if (uVar10 < (uint)puVar15[2]) {
        puVar31 = (undefined4 *)(uVar10 * 4 + puVar15[3]);
      }
      if (*(int *)*puVar31 == 0) goto switchD_0010061c_caseD_1;
      piVar13 = (int *)((int)local_17c * 4 + iVar45);
      do {
        piVar34 = local_17c;
        if (*piVar13 == 0x37) {
          piVar34 = (int *)((int)local_17c + 1);
          piVar13 = piVar13 + 1;
        }
        local_17c = (int *)((int)piVar34 + 1);
        piVar13 = piVar13 + 1;
      } while (*piVar13 != 0x28);
      local_bc = 0;
      local_17c = piVar34;
      break;
    case 0x27:
      piVar13 = (int *)0x0;
      uVar10 = local_a8[1] - 1;
      if (uVar10 < local_a8[1]) {
        piVar13 = (int *)(uVar10 * 4 + local_a8[2]);
      }
      iVar38 = *piVar13;
      uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x130);
      *puVar31 = uVar44;
      piVar13 = puVar31 + 1;
      FUN_000ea020(piVar13,*(undefined4 *)(param_1 + 8));
      puVar31[0x2f] = local_188;
      *(int **)(iVar38 + 0x138) = piVar13;
      local_180 = piVar13;
      FUN_000e8e4c(iVar38,piVar13);
      FUN_000ec3ac(param_1,local_184,local_180);
      goto LAB_00103300;
    case 0x28:
      uVar10 = puVar15[2];
      piVar13 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar13 = (int *)((uVar10 - 1) * 4 + puVar15[3]);
      }
      piVar13 = (int *)*piVar13;
      FUN_00194208(puVar33,uVar10 - 1);
joined_r0x00103afc:
      if (piVar13 != (int *)0x0) {
        FUN_00193cc0(piVar13[-1],piVar13 + -1);
        goto LAB_00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      puVar31 = (undefined4 *)0x0;
      uVar10 = local_a8[1] - 1;
      if (uVar10 < local_a8[1]) {
        puVar31 = (undefined4 *)(uVar10 * 4 + local_a8[2]);
      }
      piVar34 = (int *)*puVar31;
      iVar43 = piVar34[0x4f];
      *(int *)(iVar43 + 0xb8) = local_188;
      FUN_000ec3ac(param_1,local_184,iVar43);
      piVar13 = (int *)FUN_000e7b9c(piVar34);
      piVar13[0x2e] = local_188;
      iVar38 = (**(code **)(*piVar13 + 0x38))();
      if ((iVar38 == 0) && (iVar38 = (**(code **)(*piVar13 + 0x3c))(piVar13), iVar38 == 0)) {
        FUN_000e8e4c(piVar13,iVar43);
      }
      piVar29 = (int *)FUN_000e7a9c(piVar34);
      piVar29[0x2e] = local_188;
      piVar13 = piVar29;
      if (piVar29 == piVar34) {
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x130);
        *puVar31 = uVar44;
        piVar13 = puVar31 + 1;
        FUN_000ea020(piVar13,*(undefined4 *)(param_1 + 8));
        puVar31[0x2f] = local_188;
        piVar29[0x4e] = (int)piVar13;
        FUN_000e8e4c(piVar29,piVar13);
        FUN_000ec3ac(param_1,local_184,piVar13);
      }
      iVar38 = (**(code **)(*piVar13 + 0x38))(piVar13);
      if ((iVar38 == 0) && (iVar38 = (**(code **)(*piVar13 + 0x3c))(piVar13), iVar38 == 0)) {
        FUN_000e8e4c(piVar13,iVar43);
      }
      uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x130);
      *puVar31 = uVar44;
      piVar13 = puVar31 + 1;
      FUN_000ea020(piVar13,*(undefined4 *)(param_1 + 8));
      puVar31[0x2f] = local_188;
      local_180 = piVar13;
      FUN_000ec3ac(param_1,iVar43,piVar13);
      FUN_000e8e4c(iVar43,local_180);
      local_184 = local_180;
      FUN_00194208(local_a8,local_a8[1] - 1);
      uVar10 = puVar14[2];
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      piVar13 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar13 = (int *)((uVar10 - 1) * 4 + puVar14[3]);
      }
      local_bc = 0;
      *(int *)(*piVar13 + 300) = *(int *)(*piVar13 + 300) + -1;
      break;
    case 0x2a:
      uVar10 = puVar22[2];
      if (uVar10 != 0) {
        puVar31 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar31 = (undefined4 *)((uVar10 - 1) * 4 + puVar22[3]);
        }
        piVar13 = (int *)*puVar31;
        FUN_00194208(puVar46,uVar10 - 1);
        if ((int *)piVar13[2] != (int *)0x0) {
          local_180 = (int *)piVar13[2];
        }
        local_17c = (int *)piVar13[1];
        iVar45 = *piVar13;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      local_74 = &DAT_001dd5d8;
      if ((DAT_001dc660 == 0) || (iVar32 == DAT_001dc660)) {
LAB_00101020:
        local_64 = 0;
      }
      else {
        piVar17 = &DAT_001dc66c;
        local_64 = 0;
        do {
          iVar38 = *piVar17;
          local_64 = local_64 + 1;
          if (iVar38 == 0) goto LAB_00101020;
          piVar17 = piVar17 + 3;
        } while (iVar32 != iVar38);
      }
      local_64 = local_64 * 0xc;
      uVar10 = *(uint *)(&DAT_001dc664 + local_64);
      if ((uVar10 & 0x80) == 0) {
        uVar16 = (uint)*(byte *)(param_2 + 0x8d);
        uVar42 = uVar16;
      }
      else {
        uVar16 = *puVar37 >> 0x18 & 0x1f;
        uVar42 = (uint)*(byte *)(param_2 + 0x8d);
      }
      if (*(int *)(param_1 + 0x7c) < (int)uVar42) {
        *(uint *)(param_1 + 0x7c) = uVar42;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar42 & 0x3f) | *(uint *)(param_1 + 0x84);
      puVar23 = (undefined2 *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(puVar23,0,0x24);
      puVar23[6] = 3;
      puVar23[4] = 7;
      puVar23[9] = 1;
      puVar23[10] = 0;
      *(uint *)(puVar23 + 0x10) = uVar16;
      *puVar23 = 3;
      puVar23[1] = 3;
      puVar23[2] = 3;
      puVar23[3] = 7;
      puVar23[5] = 3;
      puVar23[7] = 1;
      puVar23[8] = 0;
      puVar23[0xb] = 0;
      puVar23[0xc] = 0;
      puVar23[0xd] = 0;
      puVar23[0xe] = 0;
      if ((int)*puVar37 < 0) {
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) & 7);
        *puVar23 = uVar30;
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) >> 3 & 7);
        puVar23[1] = uVar30;
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) >> 0xc & 7);
        puVar23[2] = uVar30;
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) >> 6 & 7);
        puVar23[5] = uVar30;
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) >> 9 & 7);
        puVar23[6] = uVar30;
        uVar30 = ((int (*)())FUN_000f8a0c)(*(uint *)(param_2 + 0x94) >> 0xf & 7);
        puVar23[3] = uVar30;
        puVar23[0xb] = (ushort)((uint)*(undefined4 *)(param_2 + 0x94) >> 0x12) & 0x7f;
        if ((uVar10 & 4) != 0) {
          puVar23[8] = ((ushort)((uint)*(undefined4 *)(param_2 + 0x94) >> 0x19) & 1) + 1;
        }
      }
      if (*(int *)(param_2 + 0x60) != 0) {
        uVar44 = *(undefined4 *)(param_2 + 0x90);
        puVar23[0xc] = (ushort)uVar44 & 0xff;
        puVar23[0xd] = (ushort)((uint)uVar44 >> 8) & 0xff;
        puVar23[0xe] = (ushort)((uint)uVar44 >> 0x10) & 0xff;
      }
      bVar1 = (uVar10 & 1) != 0;
      local_c4 = *puVar37 >> 0x18 & 1;
      puVar23[9] = (ushort)local_c4 ^ 1;
      bVar2 = (*puVar37 >> 0x19 & 1) == 0;
      puVar23[7] = (ushort)bVar2;
      if (bVar1) {
        puVar23[8] = (ushort)(iVar32 != 0x5f);
      }
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
      local_c8 = FUN_00127608(uVar44,0,iVar38,0);
      local_178 = *(undefined **)(local_60 + -0x2c30);
      local_124 = *(undefined **)(local_78 + -0x2bfc);
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
      uVar44 = FUN_00127608(uVar44,0,iVar38,0);
      uVar48 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar48,0,uVar44);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar48,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
      if (bVar1) {
        uVar48 = *(undefined4 *)(param_1 + 0x3ac);
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        local_cc = FUN_00127608(uVar48,0,iVar38,0);
        uVar48 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar48,0,local_cc);
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,uVar48,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
      }
      else {
        local_cc = 0;
      }
      bVar3 = (uVar10 >> 3 & 1) != 0;
      if (bVar3) {
        uVar48 = *(undefined4 *)(param_1 + 0x3ac);
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        local_d0 = FUN_00127608(uVar48,0,iVar38,0);
        uVar48 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar48,0,local_d0);
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,uVar48,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
      }
      else {
        local_d0 = 0;
      }
      if ((uVar10 & 0x40) != 0) {
        iVar38 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar38,0,uVar44);
        FUN_001046c8(iVar38,1,local_cc);
        uVar48 = DAT_001aa9cc;
        iVar43 = FUN_001054ec(iVar38,1);
        *(undefined4 *)(iVar43 + 0x10) = uVar48;
        *(int *)(iVar38 + 0x9c) = DAT_001aa9bc;
        ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      }
      iVar43 = uVar42 * 0xc;
      iVar38 = *(int *)(*(int *)(param_1 + 0x78) + iVar43 + 4);
      if ((iVar38 == 4) || (uVar48 = uVar44, iVar38 == 0xb)) {
        uVar48 = *(undefined4 *)(param_1 + 0x3ac);
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        uVar48 = FUN_00127608(uVar48,0,iVar38,0);
        uVar24 = ((int (*)())FUN_001043f0)(0x1b,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar24,0,uVar48);
        FUN_001046c8(uVar24,1,uVar44);
        local_178 = (undefined *)0x2020001;
        iVar38 = FUN_001054ec(uVar24,1);
        *(undefined4 *)(iVar38 + 0x10) = 0x2020001;
        FUN_001046c8(uVar24,2,uVar44);
        local_178 = (undefined *)0x1000202;
        iVar38 = FUN_001054ec(uVar24,2);
        *(undefined4 *)(iVar38 + 0x10) = 0x1000202;
        ((int (*)())FUN_000f92fc)(param_1,uVar24,local_180);
        iVar38 = ((int (*)())FUN_001043f0)(0x40,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar38,0,uVar48);
        *(undefined4 *)(iVar38 + 0x9c) = DAT_001aa9b4;
        FUN_001046c8(iVar38,1,uVar48);
        ((int (*)())FUN_00103d50)(iVar38 + 0xa4,2,1);
        uVar16 = DAT_001aa9d8;
        iVar41 = FUN_001054ec(iVar38,1);
        *(uint *)(iVar41 + 0x10) = uVar16;
        ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
        iVar38 = ((int (*)())FUN_001043f0)(0x14,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar38,0,uVar48);
        *(undefined1 *)(iVar38 + 0x9c) = 0;
        *(undefined1 *)(iVar38 + 0x9d) = 0;
        *(undefined1 *)(iVar38 + 0x9e) = 1;
        *(undefined1 *)(iVar38 + 0x9f) = 1;
        FUN_001046c8(iVar38,1,uVar48);
        FUN_001046c8(iVar38,2,uVar48);
        iVar41 = FUN_001054ec(iVar38,2);
        *(uint *)(iVar41 + 0x10) = uVar16;
        dVar49 = (double)FLOAT_001aa128;
        FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,iVar38,param_1,3);
        ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
        piVar17 = (int *)((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(piVar17,0,uVar48);
        FUN_001046c8(piVar17,1,uVar48);
        (**(code **)(*piVar17 + 0x88))(piVar17,1,0,1);
        (**(code **)(*piVar17 + 0x88))(piVar17,1,1,0);
        (**(code **)(*piVar17 + 0x88))(piVar17,1,2,3);
        (**(code **)(*piVar17 + 0x88))(piVar17,1,3,0);
        ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
        if (iVar32 == 0x8b) {
          iVar38 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar38,0,uVar48);
          *(undefined1 *)(iVar38 + 0x9e) = 1;
          *(undefined1 *)(iVar38 + 0x9f) = 0;
          *(undefined1 *)(iVar38 + 0x9c) = 1;
          *(undefined1 *)(iVar38 + 0x9d) = 1;
          FUN_001046c8(iVar38,1,uVar44);
          ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
        }
        piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar17 + 0x5c))(piVar17,uVar42);
      }
      if (bVar3) {
        uVar44 = ((int (*)())FUN_001043f0)(0x73,*(undefined4 *)(param_1 + 8));
        piVar17 = (int *)((int (*)())FUN_001043f0)(0x72,*(undefined4 *)(param_1 + 8));
        uVar24 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x1e,0,0);
        FUN_001046c8(uVar44,0,uVar24);
        FUN_001046c8(uVar44,1,local_cc);
        FUN_001046c8(piVar17,0,uVar24);
        FUN_001046c8(piVar17,1,local_d0);
        (**(code **)(*piVar17 + 0x90))(piVar17,uVar24);
        ((int (*)())FUN_000f92fc)(param_1,uVar44,local_180);
        ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      }
      else {
        uVar24 = 0;
      }
      uVar44 = uVar48;
      if (bVar1) {
        bVar1 = (uVar10 >> 2 & 1) == 0;
        if (!bVar1) {
          uVar44 = *(undefined4 *)(param_1 + 0x3ac);
          iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
          uVar44 = FUN_00127608(uVar44,0,iVar38,0);
          iVar38 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar38,0,uVar44);
          *(undefined4 *)(iVar38 + 0x9c) = DAT_001aa9b8;
          FUN_001046c8(iVar38,1,uVar48);
          ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
          iVar38 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar38,0,uVar44);
          *(int *)(iVar38 + 0x9c) = DAT_001aa9bc;
          FUN_001046c8(iVar38,1,local_cc);
          ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
        }
      }
      else {
        bVar1 = (uVar10 >> 2 & 1) == 0;
      }
      iVar38 = *(int *)(local_74 + local_64 + -0xf70);
      if ((bVar1) || (bVar2)) {
        if ((iVar38 != 0xff) || (*(int *)(iVar43 + *(int *)(param_1 + 0x78) + 4) != 7))
        goto LAB_001019bc;
        iVar38 = ((int (*)())FUN_001043f0)(0x104,*(undefined4 *)(param_1 + 8));
        *(uint *)(iVar38 + 0x130) = uVar42;
        *(undefined4 *)(iVar38 + 0x140) = *(undefined4 *)(local_60 + -0x2c30);
        FUN_001046c8(iVar38,0,local_c8);
        FUN_001046c8(iVar38,1,uVar44);
        ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      }
      else {
        iVar38 = 0xae;
LAB_001019bc:
        piVar17 = (int *)((int (*)())FUN_001043f0)(iVar38,*(undefined4 *)(param_1 + 8));
        piVar17[0x4f] = (int)puVar23;
        piVar17[0x4d] = uVar42;
        FUN_001046c8(piVar17,0,local_c8);
        FUN_001046c8(piVar17,1,uVar44);
        if (bVar3) {
          (**(code **)(*piVar17 + 0x90))(piVar17,uVar24);
        }
        iVar38 = *(int *)(param_1 + 0x78);
        if (*(int *)(iVar43 + iVar38 + 4) == 8) {
          (**(code **)(*piVar17 + 0x88))(piVar17,1,2,1);
          iVar38 = ((int (*)())FUN_001043f0)(0xbe,*(undefined4 *)(param_1 + 8));
          iVar19 = piVar17[0x2b];
          iVar20 = piVar17[0x2c];
          iVar41 = FUN_001054ec(iVar38,0);
          *(int *)(iVar41 + 0xc) = iVar20;
          *(int *)(iVar41 + 8) = iVar19;
          iVar19 = piVar17[0x2b];
          iVar20 = piVar17[0x2c];
          iVar41 = FUN_001054ec(iVar38,1);
          *(int *)(iVar41 + 0xc) = iVar20;
          *(int *)(iVar41 + 8) = iVar19;
          uVar44 = DAT_001aa9b0;
          iVar41 = FUN_001054ec(iVar38,1);
          *(undefined4 *)(iVar41 + 0x10) = uVar44;
          *(undefined4 *)(iVar38 + 0x9c) = DAT_001aa9ac;
          ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
          iVar38 = *(int *)(param_1 + 0x78);
        }
        if (*(int *)(iVar43 + iVar38 + 4) == 9) {
          iVar38 = ((int (*)())FUN_001043f0)(0xbe,*(undefined4 *)(param_1 + 8));
          iVar19 = piVar17[0x2b];
          iVar20 = piVar17[0x2c];
          iVar41 = FUN_001054ec(iVar38,0);
          *(int *)(iVar41 + 0xc) = iVar20;
          *(int *)(iVar41 + 8) = iVar19;
          iVar19 = piVar17[0x2b];
          iVar20 = piVar17[0x2c];
          iVar41 = FUN_001054ec(iVar38,1);
          *(int *)(iVar41 + 0xc) = iVar20;
          *(int *)(iVar41 + 8) = iVar19;
          uVar10 = DAT_001aa9d8;
          iVar41 = FUN_001054ec(iVar38,1);
          *(uint *)(iVar41 + 0x10) = uVar10;
          *(undefined4 *)(iVar38 + 0x9c) = DAT_001aa9b4;
          ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
          iVar38 = *(int *)(param_1 + 0x78);
        }
        iVar38 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(iVar43 + iVar38));
        piVar17[0x4e] = iVar38;
        *(short *)(piVar17[0x4f] + 0x12) = (short)local_c4;
        ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
        if (*(int *)(iVar43 + *(int *)(param_1 + 0x78) + 8) != 0) {
          uVar44 = ((int (*)())FUN_001043f0)(0x13,*(undefined4 *)(param_1 + 8));
          iVar43 = piVar17[0x25];
          iVar41 = piVar17[0x26];
          iVar38 = FUN_001054ec(uVar44,0);
          *(int *)(iVar38 + 0xc) = iVar41;
          *(int *)(iVar38 + 8) = iVar43;
          iVar43 = piVar17[0x26];
          iVar41 = piVar17[0x25];
          iVar38 = FUN_001054ec(uVar44,1);
          local_98 = (uint)(short)uVar42;
          *(int *)(iVar38 + 0xc) = iVar43;
          local_90 = local_98 | 0x130000;
          local_94 = local_98 | 0x130000;
          local_9c = local_98 | 0x130000;
          local_98 = local_98 | 0x130000;
          *(int *)(iVar38 + 8) = iVar41;
          FUN_000f771c(uVar44,param_1,2,local_90,local_94,local_98,local_9c);
          ((int (*)())FUN_000f92fc)(param_1,uVar44,local_180);
        }
      }
      local_178 = *(undefined **)(local_60 + -0x2c30);
      local_124 = *(undefined **)(local_78 + -0x2bfc);
      piVar17 = (int *)((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,piVar17,1,local_124,local_70);
      FUN_001046c8(piVar17,1,local_c8);
      goto LAB_00101cbc;
    case 0x2d:
    case 0x2e:
      uVar16 = (uint)*(byte *)(param_2 + 0x8d);
      puVar23 = (undefined2 *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(puVar23,0,0x24);
      puVar23[9] = 1;
      puVar23[7] = 1;
      puVar23[10] = 0;
      puVar23[8] = 0;
      puVar23[0xb] = 0;
      puVar23[0xc] = 0;
      puVar23[0xd] = 0;
      puVar23[0xe] = 0;
      puVar23[4] = 7;
      puVar23[6] = 3;
      *puVar23 = 3;
      puVar23[1] = 3;
      puVar23[2] = 3;
      puVar23[3] = 7;
      puVar23[5] = 3;
      puVar23[9] = (ushort)(((uint)(byte)(((*puVar37 & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      bVar1 = (*puVar37 >> 0x19 & 1) == 0;
      puVar23[7] = (ushort)bVar1;
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
      uVar48 = FUN_00127608(uVar44,0,iVar38,0);
      uVar44 = DAT_001aa9b8;
      local_124 = (undefined *)DAT_001aa9b8;
      uVar42 = *(uint *)(local_60 + -0x2c30);
      local_178 = (undefined *)uVar42;
      iVar38 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(iVar38,0,uVar48);
      *(undefined4 *)(iVar38 + 0x9c) = uVar44;
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,iVar38,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      iVar38 = DAT_001aa9bc;
      local_124 = (undefined *)DAT_001aa9bc;
      local_178 = (undefined *)uVar42;
      piVar17 = (int *)((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(piVar17,0,uVar48);
      piVar17[0x27] = iVar38;
      ((int (*)())FUN_000fa958)(param_1,10,1,param_2,piVar17,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      if (bVar1) {
        uVar44 = 0x76;
      }
      else {
        uVar44 = 0xae;
        if (uVar10 == 0x2d) {
          FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
          uVar44 = 0xae;
        }
      }
      local_124 = *(undefined **)(local_78 + -0x2bfc);
      puVar36 = *(undefined **)(local_60 + -0x2c30);
      local_178 = puVar36;
      iVar38 = ((int (*)())FUN_001043f0)(uVar44,*(undefined4 *)(param_1 + 8));
      *(undefined2 **)(iVar38 + 0x13c) = puVar23;
      *(uint *)(iVar38 + 0x134) = uVar16;
      if (*(int *)(param_1 + 0x7c) < (int)uVar16) {
        *(uint *)(param_1 + 0x7c) = uVar16;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar16 & 0x3f) | *(uint *)(param_1 + 0x84);
      uVar44 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(*(int *)(param_1 + 0x78) + uVar16 * 0xc));
      *(uint *)(iVar38 + 0x130) = uVar16;
      *(undefined4 *)(iVar38 + 0x138) = uVar44;
      iVar43 = ((int (*)())FUN_000fa958)(param_1,4,0,param_2,iVar38,1,local_124,local_70);
      if (iVar43 != 0) {
        FUN_00193f94(local_6c,iVar43);
      }
      FUN_001046c8(iVar38,1,uVar48);
      iVar43 = FUN_001054ec(iVar38,1);
      *(undefined **)(iVar43 + 0x10) = puVar36;
      uVar44 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(uVar16 * 0xc + *(int *)(param_1 + 0x78)));
      *(undefined4 *)(iVar38 + 0x138) = uVar44;
      ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      goto LAB_00101d1c;
    case 0x2f:
      uVar10 = (uint)*(byte *)(param_2 + 0x8d);
      puVar23 = (undefined2 *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(puVar23,0,0x24);
      puVar23[9] = 1;
      puVar23[6] = 3;
      puVar23[7] = 1;
      *puVar23 = 3;
      puVar23[1] = 3;
      puVar23[2] = 3;
      puVar23[5] = 3;
      puVar23[4] = 7;
      puVar23[10] = 0;
      puVar23[3] = 7;
      puVar23[8] = 0;
      puVar23[0xb] = 0;
      puVar23[0xc] = 0;
      puVar23[0xd] = 0;
      puVar23[0xe] = 0;
      uVar6 = (byte)(*puVar37 >> 0x18) & 1;
      puVar23[9] = uVar6 ^ 1;
      puVar23[7] = (ushort)(((uint)(byte)(((*puVar37 & 0x2000000) == 0) << 1) << 0x1c) >> 0x1d);
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
      uVar48 = FUN_00127608(uVar44,0,iVar38,0);
      local_178 = *(undefined **)(local_60 + -0x2c30);
      local_124 = *(undefined **)(local_78 + -0x2bfc);
      uVar44 = *(undefined4 *)(param_1 + 0x3ac);
      iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
      uVar24 = FUN_00127608(uVar44,0,iVar38,0);
      uVar44 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar44,0,uVar24);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar44,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar44,local_180);
      uVar44 = 0;
      if (iVar32 == 0x5f) {
        uVar44 = *(undefined4 *)(param_1 + 0x3ac);
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        uVar44 = FUN_00127608(uVar44,0,iVar38,0);
        uVar25 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar25,0,uVar44);
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,uVar25,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar25,local_180);
        uVar25 = *(undefined4 *)(param_1 + 0x3ac);
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        uVar25 = FUN_00127608(uVar25,0,iVar38,0);
        uVar26 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar26,0,uVar25);
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,uVar26,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar26,local_180);
      }
      else {
        uVar25 = 0;
      }
      iVar38 = ((int (*)())FUN_001043f0)(0x78,*(undefined4 *)(param_1 + 8));
      *(undefined2 **)(iVar38 + 0x13c) = puVar23;
      FUN_001046c8(iVar38,0,uVar48);
      FUN_001046c8(iVar38,1,uVar24);
      if (iVar32 == 0x5f) {
        FUN_001046c8(iVar38,2,uVar44);
        FUN_001046c8(iVar38,3,uVar25);
      }
      *(uint *)(iVar38 + 0x134) = uVar10;
      if (*(int *)(param_1 + 0x7c) < (int)uVar10) {
        *(uint *)(param_1 + 0x7c) = uVar10;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(param_1 + 0x84);
      uVar44 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(uVar10 * 0xc + *(int *)(param_1 + 0x78)));
      *(undefined4 *)(iVar38 + 0x138) = uVar44;
      *(uint *)(iVar38 + 0x130) = uVar10;
      *(ushort *)(*(int *)(iVar38 + 0x13c) + 0x12) = uVar6;
      ((int (*)())FUN_000f92fc)(param_1,iVar38,local_180);
      local_178 = *(undefined **)(local_60 + -0x2c30);
      local_124 = *(undefined **)(local_78 + -0x2bfc);
      piVar17 = (int *)((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,piVar17,1,local_124,local_70);
      FUN_001046c8(piVar17,1,uVar48);
LAB_00101cbc:
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      goto LAB_00101d1c;
    case 0x30:
      iVar38 = iVar45 + (int)local_17c * 4;
      FUN_000f79c4((double)*(float *)(iVar38 + 4),(double)*(float *)(iVar38 + 8),
                   (double)*(float *)(iVar38 + 0xc),(double)*(float *)(iVar38 + 0x10),piVar17,
                   param_1,iVar40);
      iVar38 = FUN_001054ec(piVar17,iVar40);
      FUN_000f2bdc(&local_d8,*(undefined4 *)(iVar38 + 0x10),local_178);
      uVar44 = local_d8;
      iVar38 = FUN_001054ec(piVar17,iVar40);
      *(undefined4 *)(iVar38 + 0x10) = uVar44;
      iVar40 = iVar40 + 1;
      local_bc = 0;
      local_17c = local_17c + 1;
      break;
    case 0x31:
      uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x10);
      *puVar31 = uVar44;
      puVar39 = puVar31 + 1;
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar45 + (int)local_17c * 4)) {
      case 0x3f:
        *puVar39 = *puVar37 >> 0x12 & 1;
        break;
      default:
        *puVar39 = 0;
        break;
      case 0x5f:
        *puVar39 = *puVar37 >> 0x18 & 1;
        break;
      case 0x67:
        *puVar39 = 1;
      }
      uVar10 = puVar15[2];
      if (uVar10 < *puVar33) {
        _memset((void *)(uVar10 * 4 + puVar15[3]),0,4);
        puVar15[2] = uVar10 + 1;
        puVar31 = (undefined4 *)(uVar10 * 4 + puVar15[3]);
      }
      else {
        puVar31 = (undefined4 *)FUN_0019423c(puVar33,uVar10);
      }
      local_bc = 0;
      *puVar31 = puVar39;
      break;
    case 0x32:
      iVar38 = 0;
      uVar10 = local_a8[1];
      if (uVar10 != 0) {
        piVar13 = (int *)0x0;
        if (uVar10 - 1 < uVar10) {
          piVar13 = (int *)((uVar10 - 1) * 4 + local_a8[2]);
        }
        iVar38 = *piVar13;
        *(undefined4 *)(iVar38 + 0x144) = 0;
      }
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar45 + (int)local_17c * 4)) {
      case 0x62:
        iVar43 = ((int (*)())FUN_001043f0)(0x8b,*(undefined4 *)(param_1 + 8));
        dVar49 = (double)FLOAT_001aa0e8;
        FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,iVar43,param_1,1);
        dVar49 = (double)FLOAT_001aa0e8;
        FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,iVar43,param_1,2);
        *(undefined4 *)(iVar43 + 300) = 0;
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x15c);
        *puVar31 = uVar44;
        piVar13 = puVar31 + 1;
        FUN_000ea6d0(piVar13,iVar43,iVar38,0,*(undefined4 *)(param_1 + 8));
        break;
      case 99:
        uVar10 = *(uint *)**(int **)(param_2 + 0x6c);
        if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
           ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)(short)*(uint *)**(int **)(param_2 + 0x6c);
        }
        iVar41 = ((int (*)())FUN_001043f0)(0x8d);
        uVar44 = FUN_000ec208(param_1,uVar10 >> 0x10 & 0x3f);
        iVar19 = FUN_001054ec(iVar41,1);
        *(undefined4 *)(iVar19 + 0xc) = uVar44;
        puVar36 = PTR_DAT_001e8b84;
        *(int *)(iVar19 + 8) = iVar43;
        *(undefined4 *)(iVar41 + 300) = *(undefined4 *)puVar36;
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x15c);
        *puVar31 = uVar44;
        piVar13 = puVar31 + 1;
        FUN_000ebac8(piVar13,iVar41,iVar38,*(undefined4 *)(param_1 + 8));
        FUN_000e78c0(piVar13,local_188);
        FUN_000ed63c(param_1,iVar41);
        uVar10 = 0;
        if (local_a8[1] != 0) {
          puVar31[0x53] = 0;
          uVar10 = local_a8[1];
        }
        if (uVar10 < *local_a8) {
          _memset((void *)(uVar10 * 4 + local_a8[2]),0,4);
          local_a8[1] = uVar10 + 1;
          piVar34 = (int *)(uVar10 * 4 + local_a8[2]);
        }
        else {
          piVar34 = (int *)FUN_0019423c(local_a8,uVar10);
        }
        *piVar34 = (int)piVar13;
        uVar10 = puVar14[2];
        if (uVar10 == 0) goto LAB_00103240;
        goto LAB_00103214;
      case 100:
        puVar39 = (uint *)**(int **)(param_2 + 0x6c);
        uVar10 = *puVar39;
        iVar43 = *(int *)(param_1 + 8);
        if (((uVar10 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar13 = *(int **)(iVar43 + 0x30c);
          if ((piVar13[2] & 0x80U) == 0) goto LAB_00100810;
          iVar41 = 0xf;
        }
        else {
          piVar13 = *(int **)(iVar43 + 0x30c);
LAB_00100810:
          iVar41 = (int)(short)*puVar39;
        }
        puVar39 = (uint *)(*(int **)(param_2 + 0x6c))[1];
        uVar42 = *puVar39;
        if ((((uVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) && ((piVar13[2] & 0x80U) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)(short)*puVar39;
        }
        iVar43 = (**(code **)(*piVar13 + 0x24))
                           (piVar13,*puVar37 >> 0x10 & 7,iVar41,uVar10 >> 0x10 & 0x3f,iVar43,
                            uVar42 >> 0x10 & 0x3f,local_178,param_2);
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x15c);
        *puVar31 = uVar44;
        piVar13 = puVar31 + 1;
        FUN_000ea6d0(piVar13,iVar43,iVar38,0,*(undefined4 *)(param_1 + 8));
        break;
      case 0x65:
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x168);
        *puVar31 = uVar44;
        puVar31 = puVar31 + 1;
        FUN_0010502c(puVar31,0x8c,*(undefined4 *)(param_1 + 8));
        uVar44 = 6;
        goto LAB_00102c90;
      case 0x66:
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x168);
        *puVar31 = uVar44;
        puVar31 = puVar31 + 1;
        FUN_0010502c(puVar31,0x8c,*(undefined4 *)(param_1 + 8));
        uVar44 = 7;
LAB_00102c90:
        puVar31[0x4b] = uVar44;
        piVar13 = (int *)((int (*)())FUN_000fadc4)(param_1,puVar31,local_188,iVar38,local_a8,puVar35,param_2);
        goto LAB_00103240;
      default:
        piVar13 = (int *)0x0;
        goto LAB_00103240;
      case 0x6f:
        uVar10 = local_b0[1] - 1;
        puVar31 = (undefined4 *)0x0;
        if (uVar10 < local_b0[1]) {
          puVar31 = (undefined4 *)(uVar10 * 4 + local_b0[2]);
        }
        piVar13 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        uVar44 = (**(code **)(*piVar13 + 0x28))
                           (piVar13,1,*(undefined4 *)*puVar31,4,
                            *(undefined4 *)(*(int *)(param_2 + 0x58) * 4 + param_2 + 0x8c),local_178
                            ,param_2,local_180);
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
        *puVar31 = uVar48;
        piVar13 = puVar31 + 1;
        FUN_000ea6d0(piVar13,uVar44,iVar38,0,*(undefined4 *)(param_1 + 8));
        uVar10 = local_b0[1] - 1;
        if (uVar10 < local_b0[1]) {
          piVar34 = (int *)(uVar10 * 4 + local_b0[2]);
        }
        else {
          piVar34 = (int *)0x0;
        }
        iVar38 = *piVar34;
        FUN_000e77f4(piVar13,*(undefined4 *)(iVar38 + 8));
        *(int **)(iVar38 + 8) = piVar13;
        FUN_000e78c0(piVar13,local_188);
        FUN_000ed63c(param_1,uVar44);
        goto LAB_0010319c;
      case 0x72:
        iVar43 = *(int *)(param_1 + 8);
        uVar10 = *(uint *)**(int **)(param_2 + 0x6c);
        if (((uVar10 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar13 = *(int **)(iVar43 + 0x30c);
          if ((piVar13[2] & 0x80U) == 0) goto LAB_0010082c;
          iVar43 = 0xf;
        }
        else {
          piVar13 = *(int **)(iVar43 + 0x30c);
LAB_0010082c:
          iVar43 = (int)(short)*(uint *)**(int **)(param_2 + 0x6c);
        }
        iVar43 = (**(code **)(*piVar13 + 0x28))
                           (piVar13,iVar32 == 0x6f,iVar43,uVar10 >> 0x10 & 0x3f,0,local_178,param_2,
                            local_180);
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x15c);
        *puVar31 = uVar44;
        piVar13 = puVar31 + 1;
        FUN_000ea6d0(piVar13,iVar43,iVar38,0,*(undefined4 *)(param_1 + 8));
      }
      FUN_000e78c0(piVar13,local_188);
      FUN_000ed63c(param_1,iVar43);
LAB_0010319c:
      uVar10 = 0;
      if (local_a8[1] != 0) {
        piVar13[0x52] = 0;
        uVar10 = local_a8[1];
      }
      if (uVar10 < *local_a8) {
        _memset((void *)(uVar10 * 4 + local_a8[2]),0,4);
        local_a8[1] = uVar10 + 1;
        piVar34 = (int *)(uVar10 * 4 + local_a8[2]);
      }
      else {
        piVar34 = (int *)FUN_0019423c(local_a8,uVar10);
      }
      *piVar34 = (int)piVar13;
      uVar10 = puVar14[2];
      if (uVar10 != 0) {
LAB_00103214:
        piVar34 = (int *)0x0;
        if (uVar10 - 1 < uVar10) {
          piVar34 = (int *)((uVar10 - 1) * 4 + puVar14[3]);
        }
        *(int *)(*piVar34 + 300) = *(int *)(*piVar34 + 300) + 1;
      }
LAB_00103240:
      FUN_000ec3ac(param_1,local_184,piVar13);
      FUN_000e8e4c(local_184,piVar13);
      local_180 = (int *)piVar13[0x4d];
      local_184 = piVar13;
      FUN_000ec3ac(param_1,piVar13);
LAB_00103300:
      local_bc = 0;
      local_184 = local_180;
      break;
    case 0x34:
      iVar38 = FUN_001054ec(piVar17,iVar40);
      local_bc = 0;
      iVar40 = iVar40 + 1;
      *(undefined4 *)(iVar38 + 8) = 0;
      *(undefined4 *)(iVar38 + 0xc) = 0x21;
      break;
    case 0x35:
      piVar13 = (int *)0x0;
      uVar10 = puVar14[2] - 1;
      if (uVar10 < (uint)puVar14[2]) {
        piVar13 = (int *)(uVar10 * 4 + puVar14[3]);
      }
      iVar43 = *piVar13;
      iVar38 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),3);
      if ((iVar38 == 0) || (iVar38 = FUN_0012c2dc(param_1,iVar43), iVar38 == 0)) {
        iVar38 = FUN_0012f0f8(param_1,puVar35,iVar43,&local_184,&local_180,&local_188);
        if (iVar38 != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x4c) < local_188) {
          FUN_000e1534(*(int *)(param_1 + 8),8);
        }
        iVar41 = *(int *)(iVar43 + 0x150);
        FUN_000ec3ac(param_1,local_184,iVar41);
        iVar38 = (**(code **)(*local_184 + 0x38))();
        if ((iVar38 == 0) && (iVar38 = (**(code **)(*local_184 + 0x3c))(), iVar38 == 0)) {
          FUN_000e8e4c(local_184,iVar41);
        }
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar44,0x130);
        *puVar31 = uVar44;
        puVar28 = puVar31 + 1;
        FUN_000ea020(puVar28,*(undefined4 *)(param_1 + 8));
        FUN_000e8e4c(iVar43,puVar28);
        FUN_000ec3ac(param_1,iVar41,puVar28);
        iVar38 = *(int *)(iVar43 + 0x154);
        FUN_000e8e4c(puVar28,iVar38);
        FUN_000ec3ac(param_1,puVar28,iVar38);
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar28 = (undefined4 *)FUN_00193e18(uVar44,0x130);
        *puVar28 = uVar44;
        piVar13 = puVar28 + 1;
        FUN_000ea020(piVar13,*(undefined4 *)(param_1 + 8));
        local_180 = piVar13;
        FUN_000ec3ac(param_1,iVar38,piVar13);
        FUN_000e8e4c(iVar38,local_180);
        local_184 = local_180;
        FUN_00194208(puVar35,puVar14[2] + -1);
        local_bc = 0;
        *(int *)(iVar41 + 0xb8) = local_188;
        local_188 = local_188 + -1;
        *(int *)(iVar38 + 0xb8) = local_188;
        puVar31[0x2f] = local_188;
        local_180[0x2e] = local_188;
      }
      else {
        local_184 = (int *)FUN_000e7e90(iVar43);
        if (*(int **)(iVar43 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(iVar43 + 0x150) + 4))();
        }
        if (*(int **)(iVar43 + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(iVar43 + 0x154) + 4))();
        }
        FUN_00194374(local_184[0x34],iVar43);
        do {
          piVar13 = (int *)local_184[2];
          iVar38 = piVar13[0x26];
          for (iVar43 = *(int *)(piVar13[0x26] + 8); iVar43 != 0; iVar43 = *(int *)(iVar43 + 8)) {
            if ((*(uint *)(iVar38 + 0x14) & 1) != 0) {
              *(uint *)(iVar38 + 0x14) = *(uint *)(iVar38 + 0x14) & 0xfffffffe;
            }
            iVar38 = iVar43;
          }
          FUN_00193fa4();
          FUN_0019401c(piVar13);
          if (piVar13 != (int *)0x0) {
            (**(code **)(*piVar13 + 4))(piVar13);
          }
        } while (piVar13 != local_180);
        local_bc = 0;
        local_188 = local_188 + -1;
        local_180 = local_184;
      }
      break;
    case 0x36:
      uVar10 = puVar14[2];
      uVar44 = 0;
      if (uVar10 != 0) {
        puVar31 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar31 = (undefined4 *)((uVar10 - 1) * 4 + puVar14[3]);
        }
        uVar44 = *puVar31;
      }
      if (iVar32 == 0x71) {
        uVar30 = 0;
      }
      else {
        uVar30 = *(undefined2 *)(**(int **)(param_2 + 0x6c) + 2);
      }
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar31 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
      *puVar31 = uVar48;
      puVar28 = puVar31 + 1;
      FUN_000ea828(puVar28,uVar30,uVar44,iVar32 == 0x71,*(undefined4 *)(param_1 + 8));
      puVar31[0x2f] = local_188;
      if ((*puVar37 & 0x10000) != 0) {
        puVar31[0x4e] = 1;
      }
      FUN_000ed63c(param_1,puVar31[0x53]);
      uVar10 = puVar14[2];
      if (uVar10 < *puVar35) {
        _memset((void *)(uVar10 * 4 + puVar14[3]),0,4);
        puVar14[2] = uVar10 + 1;
        puVar27 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      else {
        puVar27 = (undefined4 *)FUN_0019423c(puVar35,uVar10);
      }
      *puVar27 = puVar28;
      local_188 = local_188 + 1;
      FUN_000ec3ac(param_1,local_184,puVar28);
      FUN_000e8e4c(local_184,puVar28);
      uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar27 = (undefined4 *)FUN_00193e18(uVar44,0x130);
      *puVar27 = uVar44;
      piVar13 = puVar27 + 1;
      FUN_000ea020(piVar13,*(undefined4 *)(param_1 + 8));
      puVar27[0x2f] = local_188;
      local_180 = piVar13;
      FUN_000ec3ac(param_1,puVar28,piVar13);
      FUN_000e8e4c(puVar28,local_180);
      local_184 = local_180;
      local_bc = 0;
      puVar31[0x4d] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x324);
      break;
    case 0x37:
      local_17c = (int *)((int)local_17c + 1);
      uVar44 = *(undefined4 *)(iVar45 + (int)local_17c * 4);
      if (*(int *)(param_1 + 0x47c) != 0) {
        uVar44 = 0x75;
      }
      piVar17 = (int *)((int (*)())FUN_001043f0)(uVar44,*(undefined4 *)(param_1 + 8));
      local_bc = 0;
      break;
    case 0x38:
      local_b4 = 1;
      goto LAB_00101d1c;
    case 0x3a:
      local_bc = 0;
      piVar17[0x48] = 1;
      goto LAB_00103b3c;
    case 0x3d:
      ((int (*)())FUN_00103d50)(piVar17 + iVar40 * 6 + 0x23,1,piVar17[iVar40 * 6 + 0x28] & 1U ^ 1);
      goto LAB_00101d1c;
    case 0x42:
      local_17c = (int *)((int)local_17c + 1);
      dVar49 = (double)*(float *)(iVar45 + (int)local_17c * 4);
      FUN_000f79c4(dVar49,dVar49,dVar49,dVar49,piVar17,param_1,iVar40);
      goto LAB_001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      puVar36 = (PTR_s_IF_b_001dc2cc)[uVar10 * 4 + (*puVar37 >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      puVar36 = *(undefined **)((int)&PTR_DAT_001dc75c + (*puVar37 >> 0xe & 0xc));
switchD_00102044_default:
      iVar45 = ((int (*)())FUN_000fd50c)(param_1,iVar45,&local_17c,local_180,puVar36,puVar46);
LAB_0010372c:
      local_bc = 0;
      break;
    case 0x4b:
      if (((*puVar37 & 0x10000) == 0) ||
         (bVar1 = true, (*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x40) != 0)) {
        bVar1 = false;
      }
      puVar36 = PTR_DAT_001e8b98;
      if (bVar1) {
        puVar36 = PTR_DAT_001e8b9c;
      }
LAB_001022b4:
      iVar45 = ((int (*)())FUN_000fd50c)(param_1,iVar45,&local_17c,local_180,puVar36,puVar46);
      goto LAB_0010372c;
    case 0x4d:
      local_bc = 0;
      *(ushort *)(piVar17[0x4f] + 0x12) = (byte)(*puVar37 >> 0x18) & 1;
      break;
    case 0x4e:
      puVar36 = (undefined *)((int (*)())FUN_000f8ccc)(*puVar37 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),0);
      goto LAB_00101f74;
    case 0x4f:
      local_17c = (int *)((int)local_17c + 1);
      FUN_001048d4((double)*(float *)(iVar45 + (int)local_17c * 4),piVar17);
      goto LAB_00101d1c;
    case 0x50:
      local_17c = (int *)((int)local_17c + 1);
      FUN_0010490c((double)*(float *)(iVar45 + (int)local_17c * 4),piVar17);
      goto LAB_00101d1c;
    case 0x51:
      bVar4 = *(byte *)(param_2 + 0x8d);
      uVar10 = (uint)bVar4;
      if ((*(uint *)((int)local_a0 + (bVar4 >> 3 & 0x1c) + 8) >> (bVar4 & 0x1f) & 1) == 0) {
        FUN_000e0e0c(*(undefined4 *)(param_1 + 8),"TextureStage %d misses DCLPT\n",uVar10);
      }
      uVar42 = *(uint *)(param_1 + 0x7c);
      if ((int)*(uint *)(param_1 + 0x7c) < (int)uVar10) {
        uVar42 = uVar10;
      }
      *(uint *)(param_1 + 0x7c) = uVar42;
      *(uint *)(param_1 + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(param_1 + 0x84);
      piVar17[0x4d] = uVar10;
      piVar17[0x4c] = uVar10;
      local_bc = 0;
      iVar38 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(uVar10 * 0xc + *(int *)(param_1 + 0x78)));
      piVar17[0x4e] = iVar38;
      break;
    case 0x52:
      local_bc = 0;
      piVar17[0x4d] = (uint)*(byte *)(param_2 + 0x8d);
      piVar17[0x4c] = (uint)*(byte *)(param_2 + 0x8d);
      break;
    case 0x53:
      puVar36 = (undefined *)((int (*)())FUN_000f8ccc)(*puVar37 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),1);
LAB_00101f74:
      if (puVar36 != (undefined *)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      uVar42 = *puVar37;
      uVar10 = *(uint *)**(undefined4 **)(param_2 + 100);
      uVar16 = *(uint *)**(undefined4 **)(param_2 + 100) >> 0x10 & 0x3f;
      FUN_000ec208(param_1,uVar16);
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      uVar44 = FUN_000ec208(param_1,uVar16);
      iVar38 = FUN_00127608(uVar48,uVar44,(int)(short)uVar10,0);
      if ((uVar42 >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      local_bc = 0;
      *(undefined4 *)(iVar38 + 0x30) = 1;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
      iVar38 = (&local_104)[uVar10 - 0x55];
      if (iVar38 == 0) {
        iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
        (&local_104)[uVar10 - 0x55] = iVar38;
      }
      iVar43 = FUN_001054ec(piVar17,iVar40);
      *(undefined4 *)(iVar43 + 0xc) = 0;
      *(int *)(iVar43 + 8) = iVar38;
      if (iVar40 == 0) {
        ((int (*)())FUN_000f8d50)(param_1,puVar35,local_124,0,0,piVar17,0);
      }
      else {
        ((int (*)())FUN_000f8aa0)(param_1,&local_178,0,iVar40,piVar17);
      }
      goto LAB_001025c0;
    case 0x60:
      puVar31 = (undefined4 *)0x0;
      uVar10 = puVar15[2] - 1;
      if (uVar10 < (uint)puVar15[2]) {
        puVar31 = (undefined4 *)(uVar10 * 4 + puVar15[3]);
      }
      if (*(int *)*puVar31 != 0) goto switchD_0010061c_caseD_1;
      piVar13 = (int *)((int)local_17c * 4 + iVar45);
      do {
        piVar34 = local_17c;
        if (*piVar13 == 0x37) {
          piVar34 = (int *)((int)local_17c + 1);
          piVar13 = piVar13 + 1;
        }
        local_17c = (int *)((int)piVar34 + 1);
        piVar13 = piVar13 + 1;
      } while (*piVar13 != 0x26);
      local_bc = 0;
      local_17c = piVar34;
      break;
    case 0x6a:
      FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
      goto LAB_00101d1c;
    case 0x6b:
      iVar38 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),4);
      puVar36 = PTR_DAT_001e8bd8;
      if (iVar38 != 0) {
        puVar36 = PTR_DAT_001e8bb0;
      }
      iVar45 = ((int (*)())FUN_000fd50c)(param_1,iVar45,&local_17c,piVar13,puVar36,puVar46);
      goto LAB_0010372c;
    case 0x6c:
      (**(code **)(*piVar17 + 0x24))(piVar17);
      local_bc = 0;
      piVar17[0x4b] = 1;
      goto LAB_00103b3c;
    case 0x6d:
      iVar38 = FUN_001054ec(piVar17,1);
      iVar43 = *(int *)(iVar38 + 0x10);
      iVar38 = *(int *)(local_60 + -0x2c30);
      if (iVar43 != iVar38) {
        uVar44 = *(undefined4 *)(param_1 + 0x3ac);
        iVar41 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar41;
        uVar44 = FUN_00127608(uVar44,0,iVar41,0);
        iVar41 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar41,1,uVar44);
        iVar47 = piVar17[0x25];
        iVar20 = piVar17[0x26];
        iVar19 = FUN_001054ec(iVar41,0);
        *(int *)(iVar19 + 0xc) = iVar20;
        *(int *)(iVar19 + 8) = iVar47;
        iVar19 = FUN_001054ec(iVar41,1);
        *(int *)(iVar19 + 0x10) = iVar43;
        iVar19 = FUN_001054ec(piVar17,0);
        *(undefined4 *)(iVar41 + 0x9c) = *(undefined4 *)(iVar19 + 0x10);
        FUN_001046c8(piVar17,0,uVar44);
        FUN_000f32cc(&local_d4,iVar43);
        piVar17[0x27] = local_d4;
        iVar43 = FUN_001054ec(piVar17,1);
        *(int *)(iVar43 + 0x10) = iVar38;
        FUN_00193f94(local_6c,iVar41);
        goto LAB_00101d1c;
      }
switchD_0010061c_caseD_1:
      local_bc = 0;
      break;
    case 0x6e:
      local_17c = (int *)((int)local_17c + 1);
      uVar44 = *(undefined4 *)(iVar45 + (int)local_17c * 4);
      FUN_000f7870(piVar17,param_1,iVar40,uVar44,uVar44,uVar44,uVar44);
LAB_001025c0:
      iVar40 = iVar40 + 1;
      local_bc = 0;
      break;
    case 0x70:
      uVar10 = local_b0[1];
      piVar13 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar13 = (int *)((uVar10 - 1) * 4 + local_b0[2]);
      }
      if (*(int *)(*piVar13 + 4) == 0) {
        puVar31 = (undefined4 *)0x0;
        uVar44 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        if (uVar10 - 1 < local_b0[1]) {
          puVar31 = (undefined4 *)((uVar10 - 1) * 4 + local_b0[2]);
        }
        uVar48 = *puVar31;
        FUN_00194208(local_b0,local_b0[1] - 1);
        FUN_00193cc0(uVar44,uVar48);
      }
      else {
        piVar13 = (int *)0x0;
        if (uVar10 - 1 < local_b0[1]) {
          piVar13 = (int *)((uVar10 - 1) * 4 + local_b0[2]);
        }
        *(int *)(*piVar13 + 4) = *(int *)(*piVar13 + 4) + -1;
        local_17c = (int *)((int)local_17c + -1);
        iVar45 = ((int (*)())FUN_000fd50c)(param_1,iVar45,&local_17c,0,puVar36,puVar46);
      }
LAB_00101d1c:
      local_bc = 0;
      break;
    case 0x71:
      local_bc = 0;
      piVar17[0x50] = *(int *)(iVar45 + ((int)local_17c + 1) * 4);
      local_17c = (int *)((int)local_17c + 1);
    }
    goto LAB_00103b34;
  case 7:
    bVar1 = true;
  }
  iVar40 = ((int (*)())FUN_000f9140)(param_1,iVar32,*puVar37 >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(param_1,local_6c,**(undefined4 **)(param_2 + 100),puVar35,local_a4);
  uVar10 = *(uint *)**(undefined4 **)(param_2 + 100);
  uVar44 = FUN_000ec208(param_1,*(uint *)**(undefined4 **)(param_2 + 100) >> 0x10 & 0x3f);
  iVar45 = FUN_001054ec(iVar40,0);
  *(undefined4 *)(iVar45 + 0xc) = uVar44;
  *(int *)(iVar45 + 8) = (int)(short)uVar10;
  ((int (*)())FUN_000f8d50)(param_1,puVar35,DAT_001aa9dc,**(undefined4 **)(param_2 + 100),0,iVar40,0);
  iVar45 = ((int (*)())FUN_000f8970)(iVar32,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc));
  iVar45 = iVar45 + 1;
  if (1 < iVar45) {
    iVar38 = 1;
    iVar43 = 0;
    local_60 = &DAT_001ad5d8;
    do {
      local_178 = *(undefined **)(local_60 + -0x2c30);
      ((int (*)())FUN_000fb3d4)(param_1,local_68,puVar37,*(undefined4 *)(iVar43 + *(int *)(param_2 + 0x6c)),
                   puVar35,&local_174,&local_13c);
      puVar33 = *(uint **)(iVar43 + *(int *)(param_2 + 0x6c));
      uVar10 = *puVar33;
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar41 = 0xf;
      }
      else {
        iVar41 = (int)(short)*puVar33;
      }
      uVar44 = FUN_000ec208(param_1,uVar10 >> 0x10 & 0x3f);
      iVar19 = FUN_001054ec(iVar40,iVar38);
      *(undefined4 *)(iVar19 + 0xc) = uVar44;
      *(int *)(iVar19 + 8) = iVar41;
      if ((!bVar1) && (iVar41 = FUN_0011346c(*(undefined4 *)(param_1 + 8),iVar40), iVar41 != 0)) {
        if (iVar38 == 1) {
          puVar33 = (uint *)&DAT_001aa9d4;
        }
        else {
          puVar33 = &DAT_001aa9cc;
        }
        local_178 = (undefined *)*puVar33;
      }
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,*(undefined4 *)(iVar43 + *(int *)(param_2 + 0x6c)),iVar38,
                   iVar40);
      iVar38 = iVar38 + 1;
      iVar43 = iVar43 + 4;
    } while (iVar45 != iVar38);
  }
  local_b8 = FUN_000f3a30(iVar40);
  if (bVar1) {
    iVar41 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar41;
    uVar48 = *(undefined4 *)(iVar40 + 0x94);
    uVar44 = *(undefined4 *)(iVar40 + 0x98);
    iVar38 = FUN_001054ec(iVar40,0);
    *(int *)(iVar38 + 8) = iVar41;
    *(undefined4 *)(iVar38 + 0xc) = 0;
    iVar38 = FUN_0011346c(*(undefined4 *)(param_1 + 8),iVar40);
    iVar43 = FUN_001054ec(iVar40,0);
    puVar36 = *(undefined **)(iVar43 + 0x10);
    local_178 = puVar36;
    if (1 < local_b8) {
      local_7c = &local_188;
      iVar43 = 0;
      local_58 = local_7c;
      do {
        iVar19 = FUN_000f30d4(local_178);
        iVar20 = ((int (*)())FUN_000f9140)(param_1,iVar32,*puVar37 >> 0x10 & 0x3fff);
        piVar17 = local_58;
        if (0 < iVar45) {
          iVar47 = 0;
          do {
            FUN_00105e54(iVar20,iVar47,iVar40,iVar47);
            if (iVar38 != 0) {
              iVar21 = FUN_001054ec(iVar20,iVar47);
              puVar12 = *(undefined **)(iVar21 + 0x10);
              if (iVar47 == 1) {
                local_124 = (undefined *)
                            CONCAT31((int3)((uint)puVar12 >> 8),
                                     *(undefined1 *)((int)piVar17 + iVar19 + 100));
              }
              else if (iVar47 == 2) {
                local_124 = (undefined *)
                            CONCAT13(*(undefined1 *)((int)piVar17 + iVar19 + 100),(int3)puVar12);
              }
              else {
                local_124 = puVar12;
                if (iVar47 == 3) {
                  (*(unsigned short *)((unsigned char *)&(local_124) + 0)) = (undefined2)((uint)puVar12 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(local_124) + 2)) =
                       CONCAT11(*(undefined1 *)((int)piVar17 + iVar19 + 100),(char)puVar12);
                }
              }
              puVar12 = local_124;
              iVar21 = FUN_001054ec(iVar20,iVar47);
              *(undefined **)(iVar21 + 0x10) = puVar12;
            }
            iVar47 = iVar47 + 1;
          } while (iVar45 != iVar47);
        }
        *(undefined4 *)(iVar20 + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + iVar19 * 4);
        *(undefined1 *)((int)local_7c + iVar19 + 0x10) = 1;
        *(undefined4 *)(iVar20 + 0x120) = *(undefined4 *)(iVar40 + 0x120);
        FUN_00193f64(local_68,iVar20);
        iVar43 = iVar43 + 1;
      } while (local_b8 + -1 != iVar43);
    }
    *(undefined **)(iVar40 + 0x9c) = local_178;
    if ((iVar38 != 0) && (iVar32 = FUN_000f30d4(local_178), 1 < iVar45)) {
      iVar38 = 1;
      do {
        iVar43 = FUN_001054ec(iVar40,iVar38);
        puVar12 = *(undefined **)(iVar43 + 0x10);
        local_104 = puVar12;
        if (iVar38 == 1) {
          local_104 = (undefined *)
                      CONCAT31((int3)((uint)puVar12 >> 8),*(undefined1 *)((int)&local_104 + iVar32))
          ;
        }
        else if (iVar38 == 2) {
          local_104 = (undefined *)CONCAT13(*(undefined1 *)((int)&local_104 + iVar32),(int3)puVar12)
          ;
        }
        else if (iVar38 == 3) {
          (*(unsigned short *)((unsigned char *)&(local_104) + 0)) = (undefined2)((uint)puVar12 >> 0x10);
          (*(unsigned short *)((unsigned char *)&(local_104) + 2)) = CONCAT11(*(undefined1 *)((int)&local_104 + iVar32),(char)puVar12);
        }
        puVar12 = local_104;
        iVar43 = FUN_001054ec(iVar40,iVar38);
        iVar38 = iVar38 + 1;
        *(undefined **)(iVar43 + 0x10) = puVar12;
      } while (iVar45 != iVar38);
    }
    iVar32 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    iVar45 = FUN_001054ec(iVar32,0);
    *(undefined4 *)(iVar45 + 0xc) = uVar44;
    *(undefined4 *)(iVar45 + 8) = uVar48;
    *(undefined **)(iVar32 + 0x9c) = puVar36;
    iVar45 = FUN_001054ec(iVar32,1);
    *(int *)(iVar45 + 8) = iVar41;
    *(undefined4 *)(iVar45 + 0xc) = 0;
    FUN_00193f94(local_6c,iVar32);
  }
  piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar32 = (**(code **)(*piVar17 + 0x34))(piVar17,iVar40);
  if (iVar32 == 0) {
LAB_001002dc:
    iVar32 = 0;
  }
  else {
    iVar32 = FUN_001054ec(iVar40,0);
    iVar38 = 0;
    iVar45 = 0;
    local_178 = *(undefined **)(iVar32 + 0x10);
    local_104 = *(undefined **)(iVar32 + 0x10);
    iVar43 = 4;
    iVar32 = -1;
    do {
      iVar41 = iVar32;
      if (*(char *)((int)&local_104 + iVar45) == '\0') {
        iVar41 = iVar45;
        if ((iVar38 != 0) && (iVar41 = iVar32, 0 < iVar38)) {
          *(undefined1 *)((int)&local_178 + iVar45) = 1;
        }
        iVar38 = iVar38 + 1;
      }
      iVar45 = iVar45 + 1;
      iVar43 = iVar43 + -1;
      iVar32 = iVar41;
    } while (iVar43 != 0);
    if (iVar38 < 2) goto LAB_001002dc;
    iVar45 = 4;
    *(undefined **)(iVar40 + 0x9c) = local_178;
    iVar32 = 0;
    do {
      *(char *)((int)&local_124 + iVar32) = (char)iVar41;
      iVar32 = iVar32 + 1;
      iVar45 = iVar45 + -1;
    } while (iVar45 != 0);
    iVar32 = ((int (*)())FUN_001043f0)(0x31,*(undefined4 *)(param_1 + 8));
    uVar44 = *(undefined4 *)(iVar40 + 0x94);
    uVar48 = *(undefined4 *)(iVar40 + 0x98);
    iVar45 = FUN_001054ec(iVar32,0);
    *(undefined4 *)(iVar45 + 0xc) = uVar48;
    *(undefined4 *)(iVar45 + 8) = uVar44;
    uVar44 = *(undefined4 *)(iVar40 + 0x94);
    *(undefined **)(iVar32 + 0x9c) = local_104;
    uVar48 = *(undefined4 *)(iVar40 + 0x98);
    iVar45 = FUN_001054ec(iVar32,1);
    puVar36 = local_124;
    *(undefined4 *)(iVar45 + 0xc) = uVar48;
    *(undefined4 *)(iVar45 + 8) = uVar44;
    iVar45 = FUN_001054ec(iVar32,1);
    *(undefined **)(iVar45 + 0x10) = puVar36;
  }
  iVar38 = *(int *)(local_14c + 8);
  iVar45 = local_14c;
  while (iVar43 = iVar38, iVar43 != 0) {
    FUN_0019401c(iVar45);
    ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
    iVar45 = iVar43;
    iVar38 = *(int *)(iVar43 + 8);
  }
  ((int (*)())FUN_000f92fc)(param_1,iVar40,local_180);
  if (iVar32 != 0) {
    ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
  }
  iVar40 = *(int *)(local_164 + 8);
  iVar32 = local_164;
  while (iVar45 = iVar40, iVar45 != 0) {
    FUN_0019401c(iVar32);
    ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
    iVar32 = iVar45;
    iVar40 = *(int *)(iVar45 + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  local_bc = 1;
LAB_00103b34:
  if (piVar17 != (int *)0x0) {
LAB_00103b3c:
    iVar38 = (**(code **)(*piVar17 + 0x14))(piVar17);
    if (iVar38 + 1 == iVar40) {
      ((int (*)())FUN_000f92fc)(param_1,piVar17,local_180);
      piVar17 = (int *)0x0;
      iVar40 = 0;
      local_178 = *(undefined **)(local_60 + -0x2c30);
      local_124 = *(undefined **)(local_78 + -0x2bfc);
    }
  }
  if (local_bc != 0) goto LAB_00103bb0;
  local_17c = (int *)((int)local_17c + 1);
  goto LAB_001005f4;
LAB_00103bb0:
  iVar40 = *(int *)(local_164 + 8);
  iVar32 = local_164;
  while (iVar45 = iVar40, iVar45 != 0) {
    FUN_0019401c(iVar32);
    ((int (*)())FUN_000f92fc)(param_1,iVar32,local_180);
    iVar32 = iVar45;
    iVar40 = *(int *)(iVar45 + 8);
  }
  if (puVar33 != (uint *)0x0) {
    FUN_00193cc0(puVar15[4],puVar15[3]);
    FUN_00193cc0(*puVar15,puVar15);
  }
  if (puVar46 != (undefined4 *)0x0) {
    FUN_00193cc0(puVar22[4],puVar22[3]);
    FUN_00193cc0(*puVar22,puVar22);
  }
  goto switchD_000fdaf0_caseD_2;
}

/* FUN_00103d50 @ 0x103d50 (40 bytes) */
int FUN_00103d50(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  if (param_3 != 0) {
    *(uint *)(param_1 + 0x14) = param_2 | *(uint *)(param_1 + 0x14);
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
  return;
}

/* FUN_00103d78 @ 0x103d78 (220 bytes) */
int FUN_00103d78(double param_1,undefined4 param_2,int param_3,uint param_4)

{
  float fVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  uVar2 = 1 << (param_3 - 1U & 0x3f);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,-uVar2 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa114 /
                  (float)((double)CONCAT44(0x43300000,1 << (param_4 - 1 & 0x3f) ^ 0x80000000) -
                         DOUBLE_001aa1e0));
  fVar1 = (float)(dVar3 - param_1);
  dVar4 = param_1;
  if (fVar1 < 0.0) {
    dVar4 = dVar3;
  }
  if (-fVar1 < 0.0) {
    dVar4 = param_1;
  }
  fVar1 = (float)(dVar4 - dVar5);
  dVar3 = dVar4;
  if (fVar1 < 0.0) {
    dVar3 = dVar5;
  }
  if (-fVar1 < 0.0) {
    dVar3 = dVar4;
  }
  return (int)(dVar3 * (double)(float)((double)CONCAT44(0x43300000,
                                                        1 << (param_4 & 0x3f) ^ 0x80000000) -
                                      DOUBLE_001aa1e0));
}

/* FUN_00103e54 @ 0x103e54 (28 bytes) */
double FUN_00103e54(void)

{
  return (double)FLOAT_001aa0d4;
}

/* FUN_00103e84 @ 0x103e84 (56 bytes) */
int FUN_00103e84(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = DAT_001af9c0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = DAT_001af9bc;
  return;
}

/* FUN_00103ebc @ 0x103ebc (92 bytes) */
int FUN_00103ebc(param_1, param_2, param_3, param_4)
  void *param_1;
  void *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  _memcpy(param_2,param_1,0x164);
  if (param_4 == 0) {
    iVar1 = *(int *)(param_3 + 0x324);
    *(int *)((int)param_2 + 0x14c) = iVar1;
    *(int *)(param_3 + 0x324) = iVar1 + 1;
  }
  return param_2;
}

/* FUN_00103f18 @ 0x103f18 (44 bytes) */
int FUN_00103f18(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  uint param_3;
{
  *param_2 = param_3;
  if ((param_3 & 1) != 0) {
    param_2[1] = *(uint *)(param_1 + 0x160);
  }
  if ((*param_2 & 2) == 0) {
    return;
  }
  param_2[2] = *(uint *)(param_1 + 0x14c);
  return;
}

/* FUN_00103f44 @ 0x103f44 (64 bytes) */
int FUN_00103f44(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if ((uVar1 & 1) != 0) {
    *(uint *)(param_1 + 0x160) = param_2[1];
    uVar1 = *param_2;
    param_2[1] = 0;
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x14c) = param_2[2];
  }
  *param_2 = 0;
  param_2[2] = 0;
  return;
}

/* FUN_00103f84 @ 0x103f84 (100 bytes) */
int FUN_00103f84(param_1, param_2)
  void *param_1;
  void *param_2;
{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0;
  local_28 = 0;
  local_24 = 0;
  ((int (*)())FUN_00103f18)(param_1,&local_28,0xffffffff);
  _memcpy(param_1,param_2,0x164);
  ((int (*)())FUN_00103f44)(param_1,&local_28);
  return;
}

/* FUN_0010401c @ 0x10401c (56 bytes) */
int FUN_0010401c(param_1)
  int param_1;
{
  FUN_0019401c();
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  return;
}

/* FUN_00104054 @ 0x104054 (24 bytes) */
int FUN_00104054(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x478);
  if (-1 < iVar1) {
    return iVar1;
  }
  return 0;
}

/* FUN_0010406c @ 0x10406c (68 bytes) */
int FUN_0010406c(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return 0x16;
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) == 0) {
    return param_1;
  }
  return 0x15;
}

/* FUN_001040b0 @ 0x1040b0 (84 bytes) */
int FUN_001040b0(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return '\x04';
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + param_1 * 0x10 + 4) & 0x800) != 0) {
    return '\x03';
  }
  return (param_1 == 7) + '\x01';
}

/* FUN_00104104 @ 0x104104 (124 bytes) */
int FUN_00104104(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = (param_3 & 0xff) << 0x10 | param_4 & 0xffff;
  return;
}

/* FUN_00104180 @ 0x104180 (80 bytes) */
int FUN_00104180(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001041d0 @ 0x1041d0 (156 bytes) */
int FUN_001041d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 < 2) {
    if (param_2 != 0) {
      return;
    }
    *(uint *)(param_1 + 300) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 == 2) {
    *(uint *)(param_1 + 0x134) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *(uint *)(param_1 + 0x138) = param_3 << 0x18 | (param_4 & 0xff) << 0x10 | param_5 & 0xffff;
  return;
}

/* FUN_0010426c @ 0x10426c (80 bytes) */
int FUN_0010426c(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_001042bc @ 0x1042bc (116 bytes) */
int FUN_001042bc(param_1, param_2)
  int *param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = (char *)((int)param_1 + param_2 + 0xb4);
  iVar3 = 1;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < iVar3) {
      return -1;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 0x18;
    if (cVar1 != '\x04') break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

/* FUN_00104330 @ 0x104330 (52 bytes) */
int FUN_00104330(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0x1f;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001af9c0;
  return;
}

/* FUN_00104364 @ 0x104364 (24 bytes) */
int FUN_00104364(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 4;
  return;
}

/* FUN_001043a0 @ 0x1043a0 (80 bytes) */
int FUN_001043a0()
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0x15;
  piVar2 = &DAT_001ea500;
  do {
    iVar1 = *piVar2;
    piVar2 = piVar2 + 2;
    if (iVar1 != iVar3) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 1;
}

/* FUN_001043f0 @ 0x1043f0 (108 bytes) */
int FUN_001043f0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00113388();
  iVar1 = (**(code **)(&DAT_001ea4fc + iVar1 * 8))(param_1,param_2);
  uVar2 = FUN_00112f54(param_1);
  *(undefined4 *)(iVar1 + 0x88) = uVar2;
  return iVar1;
}

/* FUN_0010445c @ 0x10445c (132 bytes) */
int FUN_0010445c(param_1, param_2, param_3)
  void *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00193e18(*(undefined4 *)(param_2 + 0x374),0x168);
  *puVar2 = *(undefined4 *)(param_2 + 0x374);
  _memcpy(puVar2 + 1,param_1,0x164);
  if (param_3 == 0) {
    iVar1 = *(int *)(param_2 + 0x324);
    puVar2[0x54] = iVar1;
    *(int *)(param_2 + 0x324) = iVar1 + 1;
  }
  puVar2[0x57] = 0;
  puVar2[3] = 0;
  puVar2[2] = 0;
  return puVar2 + 1;
}

/* FUN_001044e0 @ 0x1044e0 (60 bytes) */
int FUN_001044e0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_00193cc0(*(undefined4 *)(param_3 + 0x374),*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

/* FUN_0010453c @ 0x10453c (168 bytes) */
int FUN_0010453c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  if (*(int *)(param_1 + 0x98) == 0x33) {
    pbVar4 = (byte *)&STACKARG(0x20);
    do {
      uVar1 = (uint)*pbVar4;
      if ((uVar1 != 4) &&
         ((((int)*(char *)(param_1 + 0x15c) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (iVar2 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xf0))
                             ((double)*(float *)(uVar1 * 0x18 + param_1 + 0x20)), iVar2 == 0))))
      goto LAB_001045cc;
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != &STACKARG(0x24));
    uVar3 = 1;
  }
  else {
LAB_001045cc:
    uVar3 = 0;
  }
  return uVar3;
}

