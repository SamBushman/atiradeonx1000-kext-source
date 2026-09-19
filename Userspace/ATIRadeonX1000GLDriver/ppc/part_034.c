#include "decls.h"

/* FUN_00134ab0 @ 0x134ab0 (8 bytes) */
int FUN_00134ab0(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x14);
}

/* FUN_00134ab8 @ 0x134ab8 (100 bytes) */
int FUN_00134ab8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    *param_3 = 0;
    *param_2 = 6;
    return;
  }
  *param_2 = 0;
  *param_3 = *(int *)(param_1 + 8);
  while( true ) {
    iVar1 = *param_2 + 7;
    if (*(int *)(param_1 + 4) <= iVar1) break;
    *param_2 = iVar1;
    *param_3 = *(int *)(*param_3 + 0x1c);
  }
  *param_2 = (*(int *)(param_1 + 4) - *param_2) + -1;
  return;
}

/* FUN_00134b1c @ 0x134b1c (60 bytes) */
int FUN_00134b1c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_3;
  if (param_2 < param_3) {
    iVar1 = param_2;
  }
  if (param_3 < param_2) {
    param_3 = param_2;
  }
  uVar2 = param_3 * (param_3 + -1);
  return iVar1 + ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
}

/* FUN_00134b58 @ 0x134b58 (76 bytes) */
int FUN_00134b58(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  uVar1 = ((int (*)())FUN_00134b1c)();
  iVar2 = (uVar1 >> 3 & 0x1ffffffc) + iVar2;
  *(uint *)(iVar2 + 8) = 1 << (uVar1 & 0x1f) | *(uint *)(iVar2 + 8);
  return;
}

/* FUN_00134ba4 @ 0x134ba4 (76 bytes) */
int FUN_00134ba4(param_1)
  int *param_1;
{
  uint uVar1;
  
  uVar1 = ((int (*)())FUN_00134b1c)();
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + *param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00134bf0 @ 0x134bf0 (40 bytes) */
int FUN_00134bf0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    uVar1 = FUN_001952d8(param_2,*(undefined4 *)(param_1 + 0x20));
    return uVar1;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x20));
}

/* FUN_00134c18 @ 0x134c18 (188 bytes) */
int FUN_00134c18(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = *(int *)(param_1 + 8);
  do {
    iVar2 = ((int (*)())FUN_00134bf0)(param_3,*(undefined4 *)(iVar3 * 4 + iVar4),1);
    if (iVar2 == param_2) {
      *(undefined4 *)(iVar3 * 4 + iVar4) = *(undefined4 *)(iVar4 + *(int *)(param_1 + 4) * 4);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
    }
    else if ((*(int *)(param_1 + 4) == (*(int *)(param_1 + 4) / 7) * 7) &&
            (*(int *)(iVar4 + 0x1c) != 0)) {
      iVar4 = *(int *)(iVar4 + 0x1c);
    }
    bVar1 = iVar3 != 6;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}

/* FUN_00134cd4 @ 0x134cd4 (20 bytes) */
int FUN_00134cd4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_00195330(param_2,param_3,*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00134ce8 @ 0x134ce8 (200 bytes) */
int FUN_00134ce8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((*(int *)(param_1 + 8) != 0) && (iVar2 = *(int *)(param_1 + 4), 0 < iVar2)) {
    iVar3 = 0;
    iVar4 = 0;
    iVar1 = 0;
    iVar5 = *(int *)(param_1 + 8);
    while( true ) {
      if (*(int *)(param_3 + param_2 * 4) ==
          *(int *)(param_3 +
                  *(int *)(*(int *)(iVar5 + (iVar4 + ((iVar4 / 7 + (iVar4 >> 0x1f)) - iVar1) * -7) *
                                            4) * 4 + *(int *)(param_4 + 0x20)) * 4)) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      iVar1 = iVar4 >> 0x1f;
      if (((0 < iVar4) && (iVar4 == (iVar4 / 7) * 7)) && (*(int *)(iVar5 + 0x1c) != 0)) {
        iVar5 = *(int *)(iVar5 + 0x1c);
      }
    }
    return iVar3;
  }
  return 0;
}

/* FUN_00134db0 @ 0x134db0 (56 bytes) */
int FUN_00134db0(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  do {
    piVar2[2] = 0;
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_00134de8 @ 0x134de8 (264 bytes) */
int FUN_00134de8(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  if (param_2[0x26] != 0xc) {
    iVar1 = (**(code **)(*param_2 + 0x50))(param_2);
    if ((iVar1 != 0) || (iVar1 = FUN_001054ec(param_2,0), *(int *)(iVar1 + 0x10) == DAT_001afffc)) {
      return 0;
    }
    if ((((param_2[0x26] != 0x37) && (param_2[0x20] != 0)) && (iVar1 = FUN_00126760(), iVar1 != 0))
       && ((((param_2[5] & 2U) == 0 && (iVar1 = (**(code **)(*param_2 + 0x50))(param_2), iVar1 == 0)
            ) && (((*(uint *)(param_1 + 0x30) & 0x400) != 0 || ((param_2[5] & 0x40U) == 0)))))) {
      return *(int *)(param_2[0x25] * 4 + *(int *)(param_1 + 0x458));
    }
  }
  return param_2[0x25];
}

/* FUN_00134ef4 @ 0x134ef4 (204 bytes) */
int FUN_00134ef4(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int param_4;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  iVar2 = *param_2;
  *param_2 = iVar2 + 1;
  if (iVar2 + 1 == 7) {
    *param_2 = 0;
    iVar2 = *param_3;
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(param_4 + 0x378);
      puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x24);
      *puVar1 = uVar3;
      *(undefined4 **)(param_1 + 8) = puVar1 + 1;
      puVar1[8] = 0;
      *param_3 = *(int *)(param_1 + 8);
    }
    else {
      if (*(int *)(iVar2 + 0x1c) == 0) {
        uVar3 = *(undefined4 *)(param_4 + 0x378);
        puVar1 = (undefined4 *)FUN_00193e18(uVar3,0x24);
        *puVar1 = uVar3;
        *(undefined4 **)(iVar2 + 0x1c) = puVar1 + 1;
        *(undefined4 *)(*(int *)(*param_3 + 0x1c) + 0x1c) = 0;
        iVar2 = *param_3;
      }
      *param_3 = *(int *)(iVar2 + 0x1c);
    }
  }
  return;
}

/* FUN_00134fc0 @ 0x134fc0 (80 bytes) */
int FUN_00134fc0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
{
  ((int (*)())FUN_00134ef4)(param_1,param_3,param_4,param_5);
  *(undefined4 *)(*param_4 + *param_3 * 4) = param_2;
  return;
}

/* FUN_00135010 @ 0x135010 (128 bytes) */
int FUN_00135010(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135090 @ 0x135090 (128 bytes) */
int FUN_00135090(param_1)
  int param_1;
{
  int iVar1;
  
  while (iVar1 = *(int *)(param_1 + 8), iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(iVar1 + 0x1c);
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_00135110 @ 0x135110 (148 bytes) */
int FUN_00135110(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_001351c4 @ 0x1351c4 (148 bytes) */
int FUN_001351c4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(int *)(param_2 * 4 + *(int *)(param_4 + 0x20)) = param_2;
  uVar2 = *(undefined4 *)(param_5 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  *puVar1 = uVar2;
  puVar1[1] = 2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[4] = (int)(puVar1 + 1);
  return;
}

/* FUN_00135278 @ 0x135278 (188 bytes) */
int FUN_00135278(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(*piVar2 + 4) = 0;
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  return;
}

/* FUN_00135334 @ 0x135334 (552 bytes) */
int FUN_00135334(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [28];
  
  if ((param_2 != param_3) && (iVar1 = ((int (*)())FUN_00134ba4)(), iVar1 == 0)) {
    ((int (*)())FUN_00134b58)(param_1,param_2,param_3);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_2 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_2) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_2 - uVar2) * 4 + 4);
        puVar4[1] = param_2 + 1;
      }
      puVar3 = (undefined4 *)(param_2 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_2);
    }
    ((int (*)())FUN_00134ab8)(*puVar3,auStack_38,auStack_34);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_2 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_2) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_2 - uVar2) * 4 + 4);
        puVar4[1] = param_2 + 1;
      }
      puVar3 = (undefined4 *)(param_2 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_2);
    }
    ((int (*)())FUN_00134fc0)(*puVar3,param_3,auStack_38,auStack_34,*(undefined4 *)(param_1 + 0x2c));
    puVar4 = *(uint **)(param_1 + 4);
    if (param_3 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_3) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_3 - uVar2) * 4 + 4);
        puVar4[1] = param_3 + 1;
      }
      puVar3 = (undefined4 *)(param_3 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_3);
    }
    ((int (*)())FUN_00134ab8)(*puVar3,auStack_38,auStack_34);
    puVar4 = *(uint **)(param_1 + 4);
    if (param_3 < *puVar4) {
      uVar2 = puVar4[1];
      if (uVar2 <= param_3) {
        _memset((void *)(uVar2 * 4 + puVar4[2]),0,(param_3 - uVar2) * 4 + 4);
        puVar4[1] = param_3 + 1;
      }
      puVar3 = (undefined4 *)(param_3 * 4 + puVar4[2]);
    }
    else {
      puVar3 = (undefined4 *)FUN_0019423c(puVar4,param_3);
    }
    ((int (*)())FUN_00134fc0)(*puVar3,param_2,auStack_38,auStack_34,*(undefined4 *)(param_1 + 0x2c));
  }
  return;
}

/* FUN_0013555c @ 0x13555c (296 bytes) */
int FUN_0013555c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  
  puVar11 = *(uint **)(param_1 + 4);
  if (param_3 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_3) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_3 - uVar2) * 4 + 4);
      puVar11[1] = param_3 + 1;
    }
    piVar3 = (int *)(param_3 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,param_3);
  }
  iVar7 = *piVar3;
  uVar4 = 0;
  iVar9 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar10 = -1;
    iVar8 = 0;
    uVar4 = 0;
    do {
      bVar1 = iVar10 == 6;
      iVar10 = iVar10 + 1;
      if (bVar1) {
        iVar9 = *(int *)(iVar9 + 0x1c);
        iVar10 = 0;
      }
      iVar5 = ((int (*)())FUN_00134bf0)(param_1,*(undefined4 *)(iVar9 + iVar10 * 4),1);
      if ((iVar5 != param_2) && (iVar6 = ((int (*)())FUN_00134ba4)(param_1,param_2,iVar5), iVar6 == 0)) {
        uVar4 = 1;
        ((int (*)())FUN_00135334)(param_1,param_2,iVar5);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(iVar7 + 4));
  }
  return uVar4;
}

/* FUN_00135684 @ 0x135684 (336 bytes) */
int FUN_00135684(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar5) {
    uVar1 = puVar5[1];
    puVar6 = puVar5;
    if (uVar1 <= param_2) {
      _memset((void *)(uVar1 * 4 + puVar5[2]),0,(param_2 - uVar1) * 4 + 4);
      puVar5[1] = param_2 + 1;
      puVar6 = *(uint **)(param_1 + 4);
    }
    piVar2 = (int *)(param_2 * 4 + puVar5[2]);
  }
  else {
    piVar2 = (int *)FUN_0019423c(puVar5);
    puVar6 = *(uint **)(param_1 + 4);
  }
  puVar5 = *(uint **)(*piVar2 + 0x10);
  if (param_3 < *puVar6) {
    uVar1 = puVar6[1];
    if (uVar1 <= param_3) {
      _memset((void *)(uVar1 * 4 + puVar6[2]),0,(param_3 - uVar1) * 4 + 4);
      puVar6[1] = param_3 + 1;
    }
    puVar4 = (undefined4 *)(param_3 * 4 + puVar6[2]);
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(puVar6,param_3);
  }
  uVar1 = puVar5[1];
  if (uVar1 < *puVar5) {
    _memset((void *)(uVar1 * 4 + puVar5[2]),0,4);
    puVar3 = (undefined4 *)(uVar1 * 4 + puVar5[2]);
    puVar5[1] = uVar1 + 1;
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar1);
  }
  *puVar3 = *puVar4;
  return;
}

/* FUN_001357d4 @ 0x1357d4 (300 bytes) */
int FUN_001357d4(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00135900 @ 0x135900 (300 bytes) */
int FUN_00135900(param_1)
  int param_1;
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x14));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x18));
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x10));
  if (0 < *(int *)(param_1 + 0xc)) {
    uVar3 = 0;
    do {
      puVar4 = *(uint **)(param_1 + 4);
      if (uVar3 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar3) {
          _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar3 - uVar1) * 4 + 4);
          puVar4[1] = uVar3 + 1;
        }
        piVar2 = (int *)(uVar3 * 4 + puVar4[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar4,uVar3);
      }
      uVar3 = uVar3 + 1;
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        ((int (*)())FUN_00135090)(iVar5);
        FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
      }
    } while ((int)uVar3 < *(int *)(param_1 + 0xc));
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar5 + -4),iVar5 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),*(undefined4 *)(param_1 + 0x20));
  return;
}

/* FUN_00135a2c @ 0x135a2c (500 bytes) */
int FUN_00135a2c(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [28];
  
  puVar11 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_2) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_2 - uVar2) * 4 + 4);
      puVar11[1] = param_2 + 1;
    }
    piVar3 = (int *)(param_2 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11);
  }
  iVar6 = *piVar3;
  iVar7 = param_1[2];
  if (param_1[2] == 0) {
    param_1[2] = *(int *)(iVar6 + 8);
  }
  else {
    do {
      iVar9 = iVar7;
      iVar7 = *(int *)(iVar9 + 0x1c);
    } while (iVar7 != 0);
    *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar6 + 8);
  }
  ((int (*)())FUN_00134ab8)(param_1,auStack_48,auStack_44);
  puVar11 = *(uint **)(param_3 + 4);
  if (param_2 < *puVar11) {
    uVar2 = puVar11[1];
    if (uVar2 <= param_2) {
      _memset((void *)(uVar2 * 4 + puVar11[2]),0,(param_2 - uVar2) * 4 + 4);
      puVar11[1] = param_2 + 1;
    }
    piVar3 = (int *)(param_2 * 4 + puVar11[2]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,param_2);
  }
  iVar7 = *piVar3;
  iVar9 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar10 = -1;
    iVar8 = 0;
    do {
      bVar1 = iVar10 == 6;
      iVar10 = iVar10 + 1;
      if (bVar1) {
        iVar9 = *(int *)(iVar9 + 0x1c);
        iVar10 = 0;
      }
      uVar4 = ((int (*)())FUN_00134bf0)(param_3,*(undefined4 *)(iVar9 + iVar10 * 4),1);
      iVar5 = ((int (*)())FUN_00134ba4)(param_3,*(undefined4 *)(*param_1 * 4 + *(int *)(param_3 + 0x20)),uVar4);
      if (iVar5 == 0) {
        ((int (*)())FUN_00134fc0)(param_1,uVar4,auStack_48,auStack_44,*(undefined4 *)(param_3 + 0x2c));
        ((int (*)())FUN_00134b58)(param_3,*(undefined4 *)(*param_1 * 4 + *(int *)(param_3 + 0x20)),uVar4);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(iVar7 + 4));
  }
  *(undefined4 *)(iVar6 + 8) = 0;
  *(undefined4 *)(iVar6 + 4) = 0;
  return;
}

/* FUN_00135c20 @ 0x135c20 (260 bytes) */
int FUN_00135c20(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = 1;
  if (param_2 != param_3) {
    iVar2 = ((int (*)())FUN_00134ba4)(param_1,param_3,param_2);
    uVar1 = 0;
    if (iVar2 == 0) {
      uVar5 = param_2;
      if ((int)param_3 < (int)param_2) {
        uVar5 = param_3;
      }
      if ((int)param_2 < (int)param_3) {
        param_2 = param_3;
      }
      puVar6 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar6) {
        uVar3 = puVar6[1];
        if (uVar3 <= uVar5) {
          _memset((void *)(uVar3 * 4 + puVar6[2]),0,(uVar5 - uVar3) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        puVar4 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        puVar4 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
      }
      ((int (*)())FUN_00135a2c)(*puVar4,param_2,param_1);
      ((int (*)())FUN_00134cd4)(param_1,uVar5,param_2);
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* FUN_00135d24 @ 0x135d24 (652 bytes) */
int FUN_00135d24(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint *param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  
  puVar10 = *(uint **)(param_1 + 4);
  if (param_2 < *puVar10) {
    uVar3 = puVar10[1];
    if (uVar3 <= param_2) {
      _memset((void *)(uVar3 * 4 + puVar10[2]),0,(param_2 - uVar3) * 4 + 4);
      puVar10[1] = param_2 + 1;
    }
    piVar4 = (int *)(param_2 * 4 + puVar10[2]);
  }
  else {
    piVar4 = (int *)FUN_0019423c(puVar10);
  }
  iVar7 = *piVar4;
  iVar8 = *(int *)(iVar7 + 8);
  if (0 < *(int *)(iVar7 + 4)) {
    iVar9 = -1;
    iVar6 = 0;
    do {
      bVar1 = iVar9 == 6;
      iVar9 = iVar9 + 1;
      if (bVar1) {
        iVar8 = *(int *)(iVar8 + 0x1c);
        iVar9 = 0;
      }
      puVar10 = *(uint **)(param_1 + 4);
      uVar3 = *(uint *)(iVar8 + iVar9 * 4);
      if (uVar3 < *puVar10) {
        uVar5 = puVar10[1];
        if (uVar5 <= uVar3) {
          _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
          puVar10[1] = uVar3 + 1;
        }
        piVar4 = (int *)(uVar3 * 4 + puVar10[2]);
      }
      else {
        piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
      }
      if (0 < *(int *)(*piVar4 + 0xc)) {
        iVar2 = uVar3 * 4;
        if (*(int *)(iVar2 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)) == param_5) {
          puVar10 = *(uint **)(param_1 + 4);
          if (uVar3 < *puVar10) {
            uVar5 = puVar10[1];
            if (uVar5 <= uVar3) {
              _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
              puVar10[1] = uVar3 + 1;
            }
            piVar4 = (int *)(iVar2 + puVar10[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
          }
          *(int *)(*piVar4 + 0xc) = *(int *)(*piVar4 + 0xc) + -1;
          puVar10 = *(uint **)(param_1 + 4);
          if (uVar3 < *puVar10) {
            uVar5 = puVar10[1];
            if (uVar5 <= uVar3) {
              _memset((void *)(uVar5 * 4 + puVar10[2]),0,(uVar3 - uVar5) * 4 + 4);
              puVar10[1] = uVar3 + 1;
            }
            piVar4 = (int *)(iVar2 + puVar10[2]);
          }
          else {
            piVar4 = (int *)FUN_0019423c(puVar10,uVar3);
          }
          if (*(int *)(*piVar4 + 0xc) == param_4 + -1) {
            uVar5 = param_3[1];
            if (uVar5 < *param_3) {
              _memset((void *)(uVar5 * 4 + param_3[2]),0,4);
              puVar10 = (uint *)(uVar5 * 4 + param_3[2]);
              param_3[1] = uVar5 + 1;
            }
            else {
              puVar10 = (uint *)FUN_0019423c(param_3,uVar5);
            }
            *puVar10 = uVar3;
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar7 + 4));
  }
  return;
}

/* FUN_00135fb0 @ 0x135fb0 (3828 bytes) */
int FUN_00135fb0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  undefined4 *puVar22;
  int *piVar23;
  uint uVar24;
  int *piVar25;
  int iVar26;
  uint uVar27;
  undefined4 uVar28;
  uint *puVar29;
  uint *puVar30;
  int iVar31;
  int local_5c;
  
  piVar6 = *(int **)(param_1 + 0x24);
  iVar3 = *piVar6;
  if (iVar3 != 0) {
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      piVar6[2] = 0;
      piVar6 = piVar6 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar21 = *(int *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x30c) + 0x14);
  iVar3 = iVar21 << 2;
  iVar7 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar8 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar9 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar6 = *(int **)(*(int *)(param_1 + 0x2c) + 0x30c);
  (**(code **)(*piVar6 + 0x130))(piVar6,iVar9);
  iVar10 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar6 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  iVar11 = FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  piVar12 = (int *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar3);
  if (iVar21 >= 1) {
    iVar3 = 0;
    iVar26 = 0;
    do {
      iVar4 = *(int *)(iVar26 + *(int *)(param_1 + 0x14));
      if (iVar4 < 1) {
        iVar4 = 1;
      }
      *(int *)(iVar7 + iVar26) = iVar4;
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,0x14);
      *puVar13 = uVar28;
      puVar13[1] = 2;
      puVar13[4] = uVar28;
      puVar13[2] = 0;
      uVar28 = FUN_00193e18(uVar28,8);
      puVar13[3] = uVar28;
      *(undefined4 **)(iVar10 + iVar26) = puVar13 + 1;
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,0x14);
      *puVar13 = uVar28;
      puVar13[1] = 2;
      puVar13[2] = 0;
      puVar13[4] = uVar28;
      uVar28 = FUN_00193e18(uVar28,8);
      puVar13[3] = uVar28;
      *(undefined4 **)((int)piVar6 + iVar26) = puVar13 + 1;
      iVar4 = *(int *)(iVar26 + iVar9);
      uVar28 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378);
      uVar27 = iVar4 + 0x1fU >> 5;
      puVar13 = (undefined4 *)FUN_00193e18(uVar28,uVar27 * 4 + 0xc);
      puVar22 = puVar13 + 1;
      *puVar13 = uVar28;
      puVar13[1] = uVar27;
      puVar13[2] = iVar4;
      if (uVar27 != 0) {
        puVar13 = puVar22;
        if (uVar27 == 0) {
          uVar27 = 1;
        }
        do {
          puVar13[2] = 0;
          puVar13 = puVar13 + 1;
          uVar27 = uVar27 - 1;
        } while (uVar27 != 0);
      }
      iVar3 = iVar3 + 1;
      *(undefined4 **)(iVar11 + iVar26) = puVar22;
      *(undefined4 *)((int)piVar12 + iVar26) = 0;
      *(undefined4 *)(iVar8 + iVar26) = 0;
      iVar26 = iVar26 + 4;
    } while (iVar21 != iVar3);
  }
  uVar27 = *(uint *)(param_1 + 8);
  if (0 < (int)uVar27) {
    iVar3 = 0;
    do {
      iVar26 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      iVar4 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(int *)(iVar26 + iVar4) =
           *(int *)(iVar26 + iVar4) -
           *(int *)(*(int *)(iVar26 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)) * 4 +
                   *(int *)(param_1 + 0x10));
      uVar27 = *(uint *)(param_1 + 8);
    } while (iVar3 < (int)uVar27);
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if ((int)uVar27 < iVar3) {
    uVar24 = uVar27 + 1;
    iVar4 = *(int *)(param_1 + 0x28);
    iVar26 = uVar27 << 2;
    uVar5 = uVar24;
    do {
      uVar17 = uVar5;
      if (uVar27 == *(uint *)(iVar26 + *(int *)(param_1 + 0x20))) {
        iVar3 = *(int *)(iVar26 + *(int *)(iVar4 + 0x45c));
        piVar12[iVar3] = piVar12[iVar3] + 1;
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar27 < *puVar29) {
          uVar5 = puVar29[1];
          puVar30 = puVar29;
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar29[1] = uVar24;
            puVar30 = *(uint **)(param_1 + 4);
          }
          piVar14 = (int *)(iVar26 + puVar29[2]);
        }
        else {
          piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
          puVar30 = *(uint **)(param_1 + 4);
        }
        iVar3 = *piVar14;
        if (uVar27 < *puVar30) {
          uVar5 = puVar30[1];
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar30[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar30[1] = uVar24;
          }
          puVar13 = (undefined4 *)(iVar26 + puVar30[2]);
        }
        else {
          puVar13 = (undefined4 *)FUN_0019423c(puVar30,uVar27);
        }
        uVar28 = ((int (*)())FUN_00134ce8)(*puVar13,uVar27,*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x45c),
                              param_1);
        *(undefined4 *)(iVar3 + 0xc) = uVar28;
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar27 < *puVar29) {
          uVar5 = puVar29[1];
          if (uVar5 <= uVar27) {
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
            puVar29[1] = uVar24;
          }
          piVar14 = (int *)(iVar26 + puVar29[2]);
        }
        else {
          piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
        }
        if (*(int *)(*piVar14 + 0xc) == 0) {
          puVar29 = (uint *)piVar6[*(int *)(iVar26 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c))];
          uVar5 = puVar29[1];
          if (uVar5 < *puVar29) {
LAB_001364b4:
            _memset((void *)(uVar5 * 4 + puVar29[2]),0,4);
            puVar30 = (uint *)(uVar5 * 4 + puVar29[2]);
            puVar29[1] = uVar5 + 1;
          }
          else {
LAB_001364e0:
            puVar30 = (uint *)FUN_0019423c(puVar29,uVar5);
          }
          *puVar30 = uVar27;
          iVar4 = *(int *)(param_1 + 0x28);
          iVar3 = *(int *)(param_1 + 0xc);
        }
        else {
          puVar29 = *(uint **)(param_1 + 4);
          if (uVar27 < *puVar29) {
            uVar5 = puVar29[1];
            if (uVar5 <= uVar27) {
              _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
              puVar29[1] = uVar24;
            }
            piVar14 = (int *)(iVar26 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar27);
          }
          iVar4 = *(int *)(param_1 + 0x28);
          iVar3 = *(int *)(iVar26 + *(int *)(iVar4 + 0x45c)) * 4;
          if (*(int *)(*piVar14 + 0xc) < *(int *)(iVar7 + iVar3)) {
            puVar29 = *(uint **)(iVar10 + iVar3);
            uVar5 = puVar29[1];
            if (uVar5 < *puVar29) goto LAB_001364b4;
            goto LAB_001364e0;
          }
          iVar3 = *(int *)(param_1 + 0xc);
        }
      }
      uVar24 = uVar24 + 1;
      iVar26 = iVar26 + 4;
      if (iVar3 <= (int)uVar17) goto LAB_0013651c;
      uVar5 = uVar17 + 1;
      uVar27 = uVar17;
    } while( true );
  }
  iVar4 = *(int *)(param_1 + 0x28);
LAB_0013651c:
  *(undefined4 *)(iVar4 + 0x25c) = 0;
  if (iVar21 < 1) {
    local_5c = 0;
  }
  else {
    iVar3 = 0;
    iVar26 = 0;
    local_5c = 0;
    piVar14 = piVar12;
    piVar23 = piVar6;
LAB_001367c0:
    while (*(int *)(*(int *)((int)piVar6 + iVar26) + 4) != *(int *)((int)piVar12 + iVar26)) {
      piVar25 = (int *)(iVar10 + iVar26);
      *(int *)(*(int *)(param_1 + 0x28) + 0x25c) = *(int *)(*(int *)(param_1 + 0x28) + 0x25c) + 1;
      iVar4 = *(int *)(iVar10 + iVar26);
      uVar27 = *(uint *)(iVar4 + 4);
      while (uVar27 != 0) {
        puVar29 = (uint *)0x0;
        if (uVar27 - 1 < uVar27) {
          puVar29 = (uint *)((uVar27 - 1) * 4 + *(int *)(iVar4 + 8));
        }
        uVar5 = *puVar29;
        FUN_00194208(iVar4,uVar27 - 1);
        puVar29 = *(uint **)(param_1 + 4);
        if (uVar5 < *puVar29) {
          uVar27 = puVar29[1];
          if (uVar27 <= uVar5) {
            _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
            puVar29[1] = uVar5 + 1;
          }
          piVar15 = (int *)(uVar5 * 4 + puVar29[2]);
        }
        else {
          piVar15 = (int *)FUN_0019423c(puVar29,uVar5);
        }
        *(undefined4 *)(*piVar15 + 0xc) = 0;
        puVar29 = (uint *)*piVar23;
        uVar27 = puVar29[1];
        if (uVar27 < *puVar29) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,4);
          puVar30 = (uint *)(uVar27 * 4 + puVar29[2]);
          puVar29[1] = uVar27 + 1;
        }
        else {
          puVar30 = (uint *)FUN_0019423c(puVar29,uVar27);
        }
        *puVar30 = uVar5;
        ((int (*)())FUN_00135d24)(param_1,uVar5,*piVar25,*(undefined4 *)(iVar7 + iVar26),iVar3);
        iVar4 = *piVar25;
        uVar27 = *(uint *)(iVar4 + 4);
      }
      if (*(int *)(*piVar23 + 4) != *piVar14) {
        *(int *)(iVar7 + iVar26) = *(int *)(iVar7 + iVar26) + 1;
        uVar27 = *(uint *)(param_1 + 8);
        iVar4 = *(int *)(param_1 + 0xc);
        if ((int)uVar27 < iVar4) {
          iVar16 = uVar27 << 2;
          do {
            if ((uVar27 == *(uint *)(iVar16 + *(int *)(param_1 + 0x20))) &&
               (iVar3 == *(int *)(iVar16 + *(int *)(*(int *)(param_1 + 0x28) + 0x45c)))) {
              puVar29 = *(uint **)(param_1 + 4);
              if (uVar27 < *puVar29) {
                uVar5 = puVar29[1];
                if (uVar5 <= uVar27) {
                  _memset((void *)(uVar5 * 4 + puVar29[2]),0,(uVar27 - uVar5) * 4 + 4);
                  puVar29[1] = uVar27 + 1;
                }
                piVar15 = (int *)(iVar16 + puVar29[2]);
              }
              else {
                piVar15 = (int *)FUN_0019423c(puVar29,uVar27);
              }
              if (*(int *)(*piVar15 + 0xc) == *(int *)(iVar7 + iVar26) + -1) {
                puVar29 = (uint *)*piVar25;
                uVar5 = puVar29[1];
                if (uVar5 < *puVar29) {
                  _memset((void *)(uVar5 * 4 + puVar29[2]),0,4);
                  puVar30 = (uint *)(uVar5 * 4 + puVar29[2]);
                  puVar29[1] = uVar5 + 1;
                }
                else {
                  puVar30 = (uint *)FUN_0019423c(puVar29,uVar5);
                }
                *puVar30 = uVar27;
                iVar4 = *(int *)(param_1 + 0xc);
              }
              else {
                iVar4 = *(int *)(param_1 + 0xc);
              }
            }
            uVar27 = uVar27 + 1;
            iVar16 = iVar16 + 4;
          } while ((int)uVar27 < iVar4);
        }
      }
    }
    iVar4 = *(int *)(iVar10 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x260) = 0;
    while (*(int *)(*piVar23 + 4) != 0) {
      piVar14 = *(int **)(iVar26 + iVar11);
      piVar25 = (int *)(iVar26 + iVar11);
      iVar4 = *piVar14;
      if (iVar4 != 0) {
        if (iVar4 == 0) {
          iVar4 = 1;
        }
        do {
          piVar14[2] = 0;
          piVar14 = piVar14 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar16 = *(int *)(param_1 + 0x28);
      iVar4 = iVar3 * 4;
      iVar31 = *(int *)(iVar4 + iVar16 + 0x43c);
      if (iVar31 < *(int *)(iVar4 + iVar16 + 0x448)) {
        do {
          iVar16 = FUN_001309dc(iVar16,iVar31);
          if (iVar16 == 0) {
            uVar27 = iVar31 - *(int *)(iVar4 + *(int *)(param_1 + 0x28) + 0x43c);
            iVar16 = (uVar27 >> 3 & 0x1ffffffc) + *piVar25;
            *(uint *)(iVar16 + 8) = 1 << (uVar27 & 0x1f) | *(uint *)(iVar16 + 8);
          }
          iVar16 = *(int *)(param_1 + 0x28);
          iVar31 = iVar31 + 1;
        } while (iVar31 < *(int *)(iVar4 + iVar16 + 0x448));
      }
      iVar16 = *piVar23;
      puVar29 = (uint *)0x0;
      uVar27 = *(uint *)(iVar16 + 4);
      if (uVar27 - 1 < uVar27) {
        puVar29 = (uint *)((uVar27 - 1) * 4 + *(int *)(iVar16 + 8));
      }
      uVar5 = *puVar29;
      FUN_00194208(iVar16,uVar27 - 1);
      puVar29 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar29) {
        uVar27 = puVar29[1];
        if (uVar27 <= uVar5) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
          puVar29[1] = uVar5 + 1;
        }
        piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
      }
      else {
        piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
      }
      iVar16 = *piVar14;
      iVar19 = *(int *)(iVar16 + 4);
      iVar31 = *(int *)(iVar16 + 8);
      if (0 < iVar19) {
        iVar20 = -1;
        iVar18 = 0;
        do {
          bVar1 = iVar20 == 6;
          iVar20 = iVar20 + 1;
          if (bVar1) {
            iVar31 = *(int *)(iVar31 + 0x1c);
            iVar20 = 0;
          }
          iVar2 = *(int *)(iVar31 + iVar20 * 4) * 4;
          if ((iVar3 == *(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x45c) + iVar2)) &&
             (uVar27 = *(uint *)(iVar2 + *(int *)(*(int *)(param_1 + 0x28) + 0x458)),
             -1 < (int)uVar27)) {
            iVar19 = (uVar27 >> 3 & 0x1ffffffc) + *piVar25;
            *(uint *)(iVar19 + 8) = 1 << (uVar27 & 0x1f) | *(uint *)(iVar19 + 8);
            iVar19 = *(int *)(iVar16 + 4);
          }
          iVar18 = iVar18 + 1;
        } while (iVar18 < iVar19);
      }
      puVar29 = *(uint **)(param_1 + 4);
      if (uVar5 < *puVar29) {
        uVar27 = puVar29[1];
        if (uVar27 <= uVar5) {
          _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
          puVar29[1] = uVar5 + 1;
        }
        piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
      }
      else {
        piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
      }
      uVar27 = *(uint *)(*(int *)(*piVar14 + 0x10) + 4);
      if (0 < (int)uVar27) {
        iVar16 = uVar5 * 4;
        uVar24 = 0;
        do {
          puVar29 = *(uint **)(param_1 + 4);
          if (uVar5 < *puVar29) {
            uVar17 = puVar29[1];
            if (uVar17 <= uVar5) {
              _memset((void *)(uVar17 * 4 + puVar29[2]),0,(uVar5 - uVar17) * 4 + 4);
              puVar29[1] = uVar5 + 1;
            }
            piVar14 = (int *)(iVar16 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
          }
          puVar29 = *(uint **)(*piVar14 + 0x10);
          if (uVar24 < *puVar29) {
            uVar17 = puVar29[1];
            if (uVar17 <= uVar24) {
              _memset((void *)(uVar17 * 4 + puVar29[2]),0,(uVar24 - uVar17) * 4 + 4);
              puVar29[1] = uVar24 + 1;
            }
            puVar13 = (undefined4 *)(uVar24 * 4 + puVar29[2]);
          }
          else {
            puVar13 = (undefined4 *)FUN_0019423c(puVar29,uVar24);
          }
          iVar31 = *(int *)(param_1 + 0x28);
          uVar17 = *(uint *)(*(int *)*puVar13 * 4 + *(int *)(iVar31 + 0x458));
          if ((-1 < (int)uVar17) &&
             ((*(uint *)((uVar17 >> 3 & 0x1ffffffc) + *piVar25 + 8) >> (uVar17 & 0x1f) & 1) == 0)) {
            *(int *)(iVar31 + 0x260) = *(int *)(iVar31 + 0x260) + 1;
            if (*(int *)(iVar8 + iVar26) < (int)(uVar17 + 1)) {
              *(uint *)(iVar8 + iVar26) = uVar17 + 1;
            }
            goto LAB_00136cac;
          }
          uVar24 = uVar24 + 1;
        } while (uVar27 != uVar24);
      }
      iVar31 = *piVar25;
      iVar16 = *(int *)(iVar31 + 4);
      if (iVar16 == 0) {
LAB_00136bb8:
        iVar4 = *(int *)(param_1 + 0x2c);
        if ((*(uint *)(*(int *)(iVar4 + 0x30c) + 8) & 0x8000) == 0) {
LAB_00136be0:
          FUN_000e1534(iVar4,4);
        }
        else {
          iVar4 = FUN_000e07dc(iVar4,0x48);
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x2c);
            goto LAB_00136be0;
          }
          puVar29 = *(uint **)(param_1 + 4);
          local_5c = local_5c + 1;
          if (uVar5 < *puVar29) {
            uVar27 = puVar29[1];
            if (uVar27 <= uVar5) {
              _memset((void *)(uVar27 * 4 + puVar29[2]),0,(uVar5 - uVar27) * 4 + 4);
              puVar29[1] = uVar5 + 1;
            }
            piVar14 = (int *)(uVar5 * 4 + puVar29[2]);
          }
          else {
            piVar14 = (int *)FUN_0019423c(puVar29,uVar5);
          }
          if (*(int *)(*piVar14 + 0x18) == 0) {
            iVar4 = (uVar5 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x24);
            *(uint *)(iVar4 + 8) = 1 << (uVar5 & 0x1f) | *(uint *)(iVar4 + 8);
          }
        }
      }
      else {
        if ((*(uint *)(iVar31 + 8) & 1) == 0) {
          uVar17 = 0;
          iVar31 = 1;
        }
        else {
          uVar17 = 0;
          do {
            uVar27 = uVar17;
            uVar17 = uVar27 + 1;
            iVar16 = iVar16 + -1;
            if (iVar16 == 0) goto LAB_00136bb8;
          } while ((*(uint *)((uVar17 >> 3 & 0x1ffffffc) + iVar31 + 8) >> (uVar17 & 0x1f) & 1) != 0)
          ;
          if (uVar17 == 0xffffffff) goto LAB_00136bb8;
          iVar31 = uVar27 + 2;
        }
        iVar16 = uVar5 << 2;
        if (*(int *)(iVar8 + iVar26) < iVar31) {
          *(int *)(iVar8 + iVar26) = iVar31;
        }
LAB_00136cac:
        *(uint *)(iVar16 + *(int *)(*(int *)(param_1 + 0x28) + 0x458)) = uVar17;
        FUN_00130444(*(int *)(param_1 + 0x28),
                     uVar17 + *(int *)(iVar4 + *(int *)(param_1 + 0x28) + 0x43c));
      }
    }
    iVar4 = *(int *)((int)piVar6 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar4 + 8));
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    iVar4 = *(int *)(iVar11 + iVar26);
    if (iVar4 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar4 + -4),iVar4 + -4);
    }
    iVar3 = iVar3 + 1;
    iVar26 = iVar26 + 4;
    if (iVar21 != iVar3) {
      piVar23 = (int *)((int)piVar6 + iVar26);
      piVar14 = (int *)((int)piVar12 + iVar26);
      goto LAB_001367c0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x470) = *(undefined4 *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 8);
  iVar21 = *(int *)(param_1 + 0xc);
  if (iVar3 < iVar21) {
    iVar26 = iVar3 << 2;
    do {
      iVar3 = iVar3 + 1;
      iVar21 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(undefined4 *)(iVar21 + iVar26) =
           *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + iVar26) * 4 + iVar21);
      iVar26 = iVar26 + 4;
      iVar21 = *(int *)(param_1 + 0xc);
    } while (iVar3 < iVar21);
  }
  if (0 < iVar21) {
    iVar3 = 0;
    do {
      iVar21 = iVar3 * 4;
      iVar3 = iVar3 + 1;
      iVar26 = *(int *)(*(int *)(param_1 + 0x28) + 0x458);
      *(int *)(iVar21 + iVar26) =
           *(int *)(iVar21 + iVar26) +
           *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x28) + 0x45c) + iVar21) * 4 +
                   *(int *)(param_1 + 0x10));
    } while (iVar3 < *(int *)(param_1 + 0xc));
  }
  FUN_000ed7e4(*(undefined4 *)(param_1 + 0x28),"color_graph");
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),piVar12);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar11);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),piVar6);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar10);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar9);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar8);
  FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x378),iVar7);
  return 0 < local_5c;
}

/* FUN_0013719c @ 0x13719c (692 bytes) */
int FUN_0013719c(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  
  param_1[2] = param_2;
  param_1[10] = param_4;
  *param_1 = 0;
  param_1[3] = param_3;
  param_1[0xb] = param_5;
  if (param_3 != 0) {
    iVar1 = FUN_00193e18(*(undefined4 *)(param_5 + 0x378),param_3 << 2);
    param_1[8] = iVar1;
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x14);
    *puVar2 = uVar6;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar6;
    uVar6 = FUN_00193e18(uVar6,8);
    puVar2[3] = uVar6;
    iVar4 = 0;
    iVar1 = param_1[3];
    param_1[1] = (int)(puVar2 + 1);
    if (0 < iVar1) {
      do {
        puVar5 = (uint *)param_1[1];
        uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
        puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x28);
        *puVar2 = uVar6;
        ((int (*)())FUN_001351c4)(puVar2 + 1,iVar4,0,param_1,param_1[0xb]);
        uVar7 = puVar5[1];
        if (uVar7 < *puVar5) {
          _memset((void *)(uVar7 * 4 + puVar5[2]),0,4);
          puVar3 = (undefined4 *)(uVar7 * 4 + puVar5[2]);
          puVar5[1] = uVar7 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar7);
        }
        *puVar3 = puVar2 + 1;
        iVar4 = iVar4 + 1;
        iVar1 = param_1[3];
      } while (iVar4 < iVar1);
    }
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    uVar7 = iVar1 * iVar1 - iVar1;
    iVar1 = ((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0);
    uVar7 = iVar1 + 0x1fU >> 5;
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,uVar7 * 4 + 0xc);
    puVar3 = puVar2 + 1;
    *puVar2 = uVar6;
    puVar2[1] = uVar7;
    puVar2[2] = iVar1;
    if (uVar7 != 0) {
      puVar2 = puVar3;
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      do {
        puVar2[2] = 0;
        puVar2 = puVar2 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *param_1 = (int)puVar3;
    iVar1 = *(int *)(*(int *)(param_1[0xb] + 0x30c) + 0x14) << 2;
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[4] = iVar4;
    (**(code **)(**(int **)(param_1[0xb] + 0x30c) + 0x134))(*(int **)(param_1[0xb] + 0x30c),iVar4);
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[6] = iVar4;
    iVar1 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    iVar4 = param_1[0xb];
    param_1[5] = iVar1;
    if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
      iVar1 = 0;
      do {
        iVar4 = iVar1 * 4;
        iVar1 = iVar1 + 1;
        *(undefined4 *)(param_1[6] + iVar4) = 0;
        *(undefined4 *)(param_1[5] + iVar4) = 0;
        iVar4 = param_1[0xb];
      } while (iVar1 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
    }
    uVar6 = *(undefined4 *)(iVar4 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
    puVar3[1] = 0x80;
    iVar1 = 0x80;
    *puVar3 = uVar6;
    puVar3[2] = 0x1000;
    puVar2 = puVar3 + 1;
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1[9] = (int)(puVar3 + 1);
  }
  return;
}

/* FUN_00137474 @ 0x137474 (512 bytes) */
int FUN_00137474(param_1)
  int *param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint *puVar11;
  
  iVar8 = param_1[3];
  iVar4 = iVar8 + 1;
  iVar9 = *param_1;
  param_1[3] = iVar4;
  uVar10 = *(undefined4 *)(param_1[0xb] + 0x378);
  uVar1 = iVar4 * iVar4 - iVar4;
  iVar4 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
  uVar1 = iVar4 + 0x1fU >> 5;
  puVar2 = (undefined4 *)FUN_00193e18(uVar10,uVar1 * 4 + 0xc);
  puVar6 = puVar2 + 1;
  *puVar2 = uVar10;
  puVar2[1] = uVar1;
  puVar2[2] = iVar4;
  if (uVar1 != 0) {
    puVar2 = puVar6;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  iVar5 = param_1[3];
  *param_1 = (int)puVar6;
  if (0 < (iVar4 - iVar5) + 1) {
    uVar1 = 0;
    do {
      uVar7 = uVar1 >> 3 & 0x1ffffffc;
      if ((*(uint *)(uVar7 + iVar9 + 8) >> (uVar1 & 0x1f) & 1) != 0) {
        iVar5 = uVar7 + *param_1;
        *(uint *)(iVar5 + 8) = 1 << (uVar1 & 0x1f) | *(uint *)(iVar5 + 8);
        iVar5 = param_1[3];
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < (iVar4 - iVar5) + 1);
  }
  if (iVar9 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar9 + -4),iVar9 + -4);
    iVar5 = param_1[3];
  }
  iVar9 = param_1[8];
  iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar5 << 2);
  param_1[8] = iVar4;
  if (0 < iVar8) {
    iVar5 = 0;
    iVar4 = iVar8;
    do {
      *(undefined4 *)(iVar5 + param_1[8]) = *(undefined4 *)(iVar9 + iVar5);
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  FUN_00193cc0(*(undefined4 *)(param_1[0xb] + 0x378),iVar9);
  puVar11 = (uint *)param_1[1];
  uVar10 = *(undefined4 *)(param_1[0xb] + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar10,0x28);
  *puVar2 = uVar10;
  ((int (*)())FUN_001351c4)(puVar2 + 1,iVar8,0,param_1,param_1[0xb]);
  uVar1 = puVar11[1];
  if (uVar1 < *puVar11) {
    _memset((void *)(uVar1 * 4 + puVar11[2]),0,4);
    piVar3 = (int *)(uVar1 * 4 + puVar11[2]);
    puVar11[1] = uVar1 + 1;
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar11,uVar1);
  }
  *piVar3 = (int)(puVar2 + 1);
  return;
}

/* FUN_00137694 @ 0x137694 (564 bytes) */
int FUN_00137694(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  
  iVar7 = param_1[3];
  param_2 = iVar7 + param_2;
  iVar6 = *param_1;
  param_1[3] = param_2;
  uVar8 = *(undefined4 *)(param_1[0xb] + 0x378);
  uVar10 = param_2 * param_2 - param_2;
  iVar11 = ((int)uVar10 >> 1) + (uint)((int)uVar10 < 0 && (uVar10 & 1) != 0);
  uVar10 = iVar11 + 0x1fU >> 5;
  puVar2 = (undefined4 *)FUN_00193e18(uVar8,uVar10 * 4 + 0xc);
  puVar4 = puVar2 + 1;
  *puVar2 = uVar8;
  puVar2[1] = uVar10;
  puVar2[2] = iVar11;
  if (uVar10 != 0) {
    puVar2 = puVar4;
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  *param_1 = (int)puVar4;
  if (0 < iVar7) {
    iVar11 = 0;
    while (iVar11 = iVar11 + 1, iVar7 != iVar11) {
      if (0 < iVar11) {
        iVar12 = 0;
        do {
          uVar10 = ((int (*)())FUN_00134b1c)(param_1,iVar12,iVar11);
          uVar5 = uVar10 >> 3 & 0x1ffffffc;
          if ((*(uint *)(uVar5 + iVar6 + 8) >> (uVar10 & 0x1f) & 1) != 0) {
            iVar1 = uVar5 + *param_1;
            *(uint *)(iVar1 + 8) = 1 << (uVar10 & 0x1f) | *(uint *)(iVar1 + 8);
          }
          iVar12 = iVar12 + 1;
        } while (iVar11 != iVar12);
      }
    }
  }
  iVar11 = param_1[8];
  iVar6 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),param_1[3] << 2);
  param_1[8] = iVar6;
  if (0 < iVar7) {
    iVar12 = 0;
    iVar6 = iVar7;
    do {
      *(undefined4 *)(iVar12 + param_1[8]) = *(undefined4 *)(iVar11 + iVar12);
      iVar12 = iVar12 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  FUN_00193cc0(*(undefined4 *)(param_1[0xb] + 0x378),iVar11);
  if (iVar7 < param_1[3]) {
    do {
      puVar9 = (uint *)param_1[1];
      uVar8 = *(undefined4 *)(param_1[0xb] + 0x378);
      puVar2 = (undefined4 *)FUN_00193e18(uVar8,0x28);
      *puVar2 = uVar8;
      ((int (*)())FUN_001351c4)(puVar2 + 1,iVar7,0,param_1,param_1[0xb]);
      uVar10 = puVar9[1];
      if (uVar10 < *puVar9) {
        _memset((void *)(uVar10 * 4 + puVar9[2]),0,4);
        piVar3 = (int *)(uVar10 * 4 + puVar9[2]);
        puVar9[1] = uVar10 + 1;
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar9,uVar10);
      }
      *piVar3 = (int)(puVar2 + 1);
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_1[3]);
  }
  return;
}

/* FUN_001378e8 @ 0x1378e8 (1420 bytes) */
int FUN_001378e8(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint *puVar10;
  
  iVar8 = *(int *)(*(int *)(param_2 + 0x6c4) + 900);
  iVar7 = *(int *)(iVar8 + 8);
  do {
    if (iVar7 == 0) {
      return;
    }
    piVar1 = (int *)(*(int **)(iVar8 + 0xa0))[1];
    piVar9 = *(int **)(iVar8 + 0xa0);
    if (piVar1 != (int *)0x0) {
      do {
        piVar5 = piVar1;
        if (((piVar9 == *(int **)(iVar8 + 0x98)) || ((piVar5[5] & 4U) == 0)) &&
           (iVar7 = *(int *)(iVar8 + 0xb8), piVar9 != (int *)0x0)) {
          piVar1 = piVar9;
          do {
            uVar2 = piVar1[5];
            if ((uVar2 & 1) != 0) {
              iVar3 = (**(code **)(*piVar1 + 0x7c))(piVar1);
              if (iVar3 == 0) {
                if (((piVar1[0x20] != 0) && (iVar3 = FUN_00126760(piVar1[0x26]), iVar3 != 0)) &&
                   (((piVar1[5] & 2U) == 0 &&
                    (iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar3 == 0)))) {
                  uVar2 = piVar1[0x25];
                  iVar3 = (**(code **)(*piVar1 + 0x40))(piVar1);
                  if ((iVar3 == 0) && (iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1), iVar3 == 0)) {
                    piVar1[5] = piVar1[5] | 0x20000000;
                    piVar5 = piVar1;
                    for (iVar3 = 1; iVar6 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar3 <= iVar6;
                        iVar3 = iVar3 + 1) {
                      if ((iVar3 < 1) || (iVar6 = FUN_00105594(piVar1,iVar3), iVar6 == 0)) {
                        iVar6 = piVar5[0x2c];
                      }
                      else {
                        iVar6 = FUN_00105594(piVar1,iVar3);
                        iVar6 = *(int *)(iVar6 + 0x98);
                      }
                      iVar6 = FUN_0012678c(iVar6);
                      if (iVar6 == 0) {
LAB_00137af8:
                        uVar4 = piVar1[5] & 0xdfffffff;
                        piVar1[5] = uVar4;
                        goto LAB_00137b2c;
                      }
                      FUN_001054ec(piVar1,iVar3);
                      piVar5 = piVar5 + 6;
                      iVar6 = FUN_00105dbc(piVar1,iVar3);
                      if (iVar6 != 0) goto LAB_00137af8;
                    }
                    uVar4 = piVar1[5];
                  }
                  else {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(undefined4 *)(*piVar5 + 0x20) = 0;
                    uVar4 = piVar1[5];
                  }
LAB_00137b2c:
                  if ((uVar4 & 0x20000000) != 0) {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(undefined4 *)(*piVar5 + 0x20) = 1;
                  }
                  puVar10 = *(uint **)(param_1 + 4);
                  if (uVar2 < *puVar10) {
                    uVar4 = puVar10[1];
                    if (uVar4 <= uVar2) {
                      _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                      puVar10[1] = uVar2 + 1;
                    }
                    piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                  }
                  else {
                    piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                  }
                  if (*(int *)(*piVar5 + 0x18) == 0) {
                    iVar3 = 0;
                    if (((piVar1[5] & 0x20000000U) == 0) &&
                       (iVar3 = iVar7 * 100, (piVar1[5] & 0x40U) != 0)) {
                      iVar3 = 0x7fffffff;
                    }
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    *(int *)(*piVar5 + 0x1c) = iVar3 + *(int *)(*piVar5 + 0x1c);
                  }
                }
                for (iVar3 = 1; iVar6 = (**(code **)(*piVar1 + 0x14))(piVar1), iVar3 <= iVar6;
                    iVar3 = iVar3 + 1) {
                  piVar5 = (int *)FUN_00105594(piVar1,iVar3);
                  uVar2 = piVar5[0x25];
                  if ((((piVar5[0x20] != 0) && (iVar6 = FUN_00126760(piVar5[0x26]), iVar6 != 0)) &&
                      ((piVar5[5] & 2U) == 0)) &&
                     (iVar6 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar6 == 0)) {
                    puVar10 = *(uint **)(param_1 + 4);
                    if (uVar2 < *puVar10) {
                      uVar4 = puVar10[1];
                      if (uVar4 <= uVar2) {
                        _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                        puVar10[1] = uVar2 + 1;
                      }
                      piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                    }
                    else {
                      piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                    }
                    if (*(int *)(*piVar5 + 0x18) == 0) {
                      puVar10 = *(uint **)(param_1 + 4);
                      if (uVar2 < *puVar10) {
                        uVar4 = puVar10[1];
                        if (uVar4 <= uVar2) {
                          _memset((void *)(uVar4 * 4 + puVar10[2]),0,(uVar2 - uVar4) * 4 + 4);
                          puVar10[1] = uVar2 + 1;
                        }
                        piVar5 = (int *)(uVar2 * 4 + puVar10[2]);
                      }
                      else {
                        piVar5 = (int *)FUN_0019423c(puVar10,uVar2);
                      }
                      *(int *)(*piVar5 + 0x1c) = iVar7 + *(int *)(*piVar5 + 0x1c);
                    }
                  }
                }
              }
              uVar2 = piVar1[5];
            }
            piVar1 = (int *)piVar1[2];
          } while ((piVar1 != (int *)0x0) && ((uVar2 & 4) != 0));
          piVar5 = (int *)piVar9[1];
        }
        piVar1 = (int *)piVar5[1];
        piVar9 = piVar5;
      } while ((int *)piVar5[1] != (int *)0x0);
      iVar7 = *(int *)(iVar8 + 8);
    }
    iVar8 = iVar7;
    iVar7 = *(int *)(iVar7 + 8);
  } while( true );
}

/* FUN_00137e74 @ 0x137e74 (36 bytes) */
int FUN_00137e74(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = param_2 * 4 + param_3;
  return *(uint *)((uVar1 >> 3 & 0x1ffffffc) + param_1 + 8) >> (uVar1 & 0x1f) & 1;
}

/* FUN_00137e98 @ 0x137e98 (124 bytes) */
int FUN_00137e98(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00105594();
  uVar1 = param_3;
  while( true ) {
    if (uVar1 == 0) {
      return 0;
    }
    if (((*(uint *)(param_3 + 0x14) & 1) != 0) && (param_3 == uVar2)) break;
    param_3 = *(uint *)(param_3 + 4);
    uVar1 = *(uint *)(param_3 + 0x14) & 4;
    if (param_3 == 0) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00137f14 @ 0x137f14 (364 bytes) */
int FUN_00137f14(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = param_2[0x21];
  if (0 < iVar1) {
    piVar3 = param_2 + iVar1 * 6 + 0x23;
    do {
      iVar6 = *piVar3;
      uVar4 = *(uint *)(iVar6 + 0x1c);
      if ((int)uVar4 < 0) {
        if (*(int *)(iVar6 + 4) == 0x2c) {
          *(undefined4 *)(param_1 + 0x3b4) = 1;
          *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 1;
        }
      }
      else {
        uVar5 = uVar4 >> 3 & 0x1ffffffc;
        if ((*(uint *)(uVar5 + param_3 + 8) >> (uVar4 & 0x1f) & 1) == 0) {
          iVar2 = uVar5 + *(int *)(param_1 + 0x3b0);
          *(uint *)(iVar2 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar2 + 8);
          *(uint *)(iVar6 + 0x24) = *(uint *)(iVar6 + 0x24) | 1;
        }
      }
      piVar3 = piVar3 + -6;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  if (((0 < param_2[0x20]) && ((param_2[5] & 2U) == 0)) &&
     (uVar4 = *(uint *)(param_2[0x23] + 0x1c), -1 < (int)uVar4)) {
    param_3 = (uVar4 >> 3 & 0x1ffffffc) + param_3;
    *(uint *)(param_3 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(param_3 + 8);
  }
  iVar1 = (**(code **)(*param_2 + 0x78))(param_2);
  if (iVar1 != 0) {
    iVar1 = param_2[0x29];
    uVar4 = *(uint *)(iVar1 + 0x1c);
    if (-1 < (int)uVar4) {
      iVar6 = (uVar4 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x3b0);
      *(uint *)(iVar6 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar6 + 8);
      *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 1;
    }
  }
  return;
}

/* FUN_00138080 @ 0x138080 (176 bytes) */
int FUN_00138080(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  piVar1 = (int *)FUN_000ec5b8();
  while( true ) {
    piVar1 = piVar1 + 1;
    iVar2 = FUN_00194034(param_1 + 0x37c);
    if (iVar2 < iVar3) break;
    iVar4 = *piVar1;
    iVar2 = *(int *)(iVar4 + 0x108);
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x100);
    *(undefined4 *)(iVar4 + 0x108) = 0;
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    iVar2 = *(int *)(iVar4 + 0x104);
    *(undefined4 *)(iVar4 + 0x100) = 0;
    if (iVar2 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
    }
    *(undefined4 *)(iVar4 + 0x104) = 0;
    iVar3 = iVar3 + 1;
  }
  return;
}

/* FUN_00138130 @ 0x138130 (272 bytes) */
int FUN_00138130(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
  piVar5 = puVar3 + 1;
  puVar3[1] = 0x80;
  iVar7 = 0x80;
  *puVar3 = uVar6;
  puVar3[2] = 0x1000;
  iVar4 = 0x80;
  piVar1 = piVar5;
  do {
    piVar1[2] = 0;
    piVar1 = piVar1 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = *(int *)(param_1 + 900);
  if (*(int *)(iVar7 + 8) != 0) {
    while( true ) {
      if (iVar4 != 0) {
        piVar1 = piVar5;
        if (iVar4 == 0) {
          iVar4 = 1;
        }
        do {
          piVar1[2] = 0;
          piVar1 = piVar1 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      iVar4 = *(int *)(iVar7 + 0x98);
      for (iVar2 = *(int *)(*(int *)(iVar7 + 0x98) + 8); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        if ((*(uint *)(iVar4 + 0x14) & 1) != 0) {
          ((int (*)())FUN_00137f14)(param_1,iVar4,piVar5);
          iVar2 = *(int *)(iVar4 + 8);
        }
        iVar4 = iVar2;
      }
      iVar7 = *(int *)(iVar7 + 8);
      if (*(int *)(iVar7 + 8) == 0) break;
      iVar4 = *piVar5;
    }
  }
  return;
}

/* FUN_00138240 @ 0x138240 (120 bytes) */
int FUN_00138240(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  do {
    iVar1 = FUN_001054ec(param_1,0);
    if (*(char *)(param_2 + iVar1 + 0x10) == '\0') {
      return 1;
    }
  } while (((*(uint *)(param_1 + 0x14) & 0x200) != 0) &&
          (param_1 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84)), param_1 != 0));
  return 0;
}

/* FUN_001382b8 @ 0x1382b8 (216 bytes) */
int FUN_001382b8(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  
  *param_3 = param_2;
LAB_001382d4:
  do {
    uVar2 = *param_3;
    iVar1 = FUN_001054ec(param_1,0);
    if (*(char *)(uVar2 + iVar1 + 0x10) == '\0') {
      if ((param_1[5] & 1U) != 0) {
        return param_1;
      }
      iVar1 = (**(code **)(*param_1 + 100))(param_1);
      if (iVar1 == 0) goto LAB_001382d4;
      uVar2 = *param_3;
      iVar1 = FUN_001054ec(param_1,1);
      *param_3 = (uint)*(byte *)(uVar2 + iVar1 + 0x10);
      param_1 = (int *)FUN_00105594(param_1,1);
    }
    else {
      if ((param_1[5] & 0x200U) == 0) {
        return (int *)0x0;
      }
      param_1 = (int *)FUN_00105594(param_1,param_1[0x21]);
    }
    if (param_1 == (int *)0x0) {
      return (int *)0x0;
    }
  } while( true );
}

/* FUN_00138390 @ 0x138390 (772 bytes) */
int FUN_00138390(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  undefined4 local_48;
  int *local_44;
  undefined4 local_38 [5];
  
  piVar9 = *(int **)(*(int *)(param_1 + 300) + 0x98);
  piVar5 = (int *)piVar9[2];
  if (piVar5 == (int *)0x0) {
    return;
  }
  do {
    piVar11 = piVar9;
    if (piVar9 != (int *)0x0) {
      do {
        uVar3 = piVar11[5];
        if ((uVar3 & 1) != 0) {
          for (iVar10 = 1; iVar7 = (**(code **)(*piVar11 + 0x14))(piVar11), iVar10 <= iVar7;
              iVar10 = iVar10 + 1) {
            piVar5 = (int *)FUN_00105594(piVar11,iVar10);
            if ((((piVar5[0x20] != 0) && (iVar7 = FUN_00126760(piVar5[0x26]), iVar7 != 0)) &&
                ((piVar5[5] & 2U) == 0)) &&
               (iVar7 = (**(code **)(*piVar5 + 0x50))(piVar5), iVar7 == 0)) {
              iVar7 = FUN_001054ec(piVar11,iVar10);
              FUN_000f3398(local_38,*(undefined4 *)(iVar7 + 0x10));
              iVar7 = 0;
              local_48 = local_38[0];
              iVar8 = 4;
              do {
                if (*(char *)((int)&local_48 + iVar7) != '\0') {
                  uVar3 = piVar5[0x25] * 4 + iVar7;
                  iVar6 = (uVar3 >> 3 & 0x1ffffffc) + param_2;
                  *(uint *)(iVar6 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)(iVar6 + 8);
                }
                iVar7 = iVar7 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
          }
          if (((piVar11[0x20] != 0) && (iVar10 = FUN_00126760(piVar11[0x26]), iVar10 != 0)) &&
             (((piVar11[5] & 2U) == 0 &&
              (iVar10 = (**(code **)(*piVar11 + 0x50))(piVar11), iVar10 == 0)))) {
            iVar10 = 0;
            do {
              iVar7 = FUN_001054ec(piVar11,0);
              if (*(char *)(iVar10 + iVar7 + 0x10) != '\x01') {
                uVar3 = piVar11[0x25] * 4 + iVar10;
                iVar7 = (uVar3 >> 3 & 0x1ffffffc) + param_2;
                *(uint *)(iVar7 + 8) = 1 << (uVar3 & 0x1f) | *(uint *)(iVar7 + 8);
              }
              bVar2 = iVar10 != 3;
              iVar10 = iVar10 + 1;
            } while (bVar2);
          }
          iVar10 = *(int *)(param_1 + 300);
          iVar7 = 0;
          local_44 = (int *)0x0;
          for (uVar3 = 1; uVar3 <= *(uint *)(*(int *)(iVar10 + 300) + 4); uVar3 = uVar3 + 1) {
            local_44 = *(int **)(iVar7 + *(int *)(*(int *)(iVar10 + 300) + 8));
            if ((local_44[5] & 1U) != 0) {
              iVar10 = (**(code **)(*local_44 + 0x60))();
              if (iVar10 == 0) {
                iVar10 = 0;
                do {
                  iVar8 = FUN_001054ec(piVar11,0);
                  if (*(char *)(iVar10 + iVar8 + 0x10) != '\x01') {
                    uVar4 = local_44[0x25] * 4 + iVar10;
                    iVar8 = (uVar4 >> 3 & 0x1ffffffc) + param_2;
                    *(uint *)(iVar8 + 8) = 1 << (uVar4 & 0x1f) | *(uint *)(iVar8 + 8);
                  }
                  bVar2 = iVar10 != 3;
                  iVar10 = iVar10 + 1;
                } while (bVar2);
              }
              iVar10 = *(int *)(param_1 + 300);
            }
            iVar7 = iVar7 + 4;
          }
          uVar3 = piVar11[5];
        }
        piVar11 = (int *)piVar11[2];
      } while ((piVar11 != (int *)0x0) && ((uVar3 & 4) != 0));
      piVar5 = (int *)piVar9[2];
    }
    do {
      piVar11 = piVar5;
      puVar1 = (uint *)(piVar9 + 5);
      piVar5 = (int *)piVar11[2];
      if (piVar5 == (int *)0x0) {
        return;
      }
      piVar9 = piVar11;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_00138694 @ 0x138694 (2336 bytes) */
int FUN_00138694(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int *piVar19;
  uint uVar20;
  undefined4 local_68;
  int local_64;
  undefined4 local_58 [3];
  
  param_2 = param_2 * 4;
  iVar16 = 1;
  *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) | 0x1000;
  iVar5 = FUN_000ec4f0(param_3);
  uVar13 = param_2 + 0x1fU >> 5;
  bVar2 = uVar13 != 0;
  iVar17 = uVar13 * 4 + 0xc;
  while( true ) {
    iVar10 = FUN_00194034(param_3 + 0x37c);
    if (iVar10 < iVar16) {
      puVar11 = (undefined4 *)FUN_000ec5b8(param_3);
      do {
        bVar2 = false;
        iVar5 = 1;
        puVar12 = puVar11;
        while( true ) {
          puVar12 = puVar12 + 1;
          iVar16 = FUN_00194034(param_3 + 0x37c);
          if (iVar16 < iVar5) break;
          piVar19 = (int *)*puVar12;
          iVar16 = (**(code **)(*piVar19 + 0x20))(piVar19);
          if (iVar16 == 0) {
            piVar4 = (int *)piVar19[0x41];
            iVar16 = *piVar4;
            if (iVar16 != 0) {
              if (iVar16 == 0) {
                iVar16 = 1;
              }
              do {
                piVar4[2] = 0;
                piVar4 = piVar4 + 1;
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            bVar3 = true;
            iVar16 = 0;
            local_64 = 0;
            for (uVar13 = 1; uVar13 <= *(uint *)(piVar19[0x34] + 4); uVar13 = uVar13 + 1) {
              local_64 = *(int *)(*(int *)(piVar19[0x34] + 8) + iVar16);
              if (local_64 != 0) {
                if (bVar3) {
                  piVar4 = (int *)piVar19[0x41];
                  iVar10 = *(int *)(local_64 + 0x100);
                  iVar17 = *piVar4;
                  if (iVar17 != 0) {
                    if (iVar17 == 0) {
                      iVar17 = 1;
                    }
                    do {
                      piVar9 = (int *)(iVar10 + 8);
                      iVar10 = iVar10 + 4;
                      piVar4[2] = *piVar9;
                      piVar4 = piVar4 + 1;
                      iVar17 = iVar17 + -1;
                    } while (iVar17 != 0);
                  }
                }
                else {
                  piVar4 = (int *)piVar19[0x41];
                  iVar10 = *(int *)(local_64 + 0x100);
                  iVar17 = *piVar4;
                  if (iVar17 != 0) {
                    if (iVar17 == 0) {
                      iVar17 = 1;
                    }
                    do {
                      puVar1 = (uint *)(iVar10 + 8);
                      iVar10 = iVar10 + 4;
                      piVar4[2] = piVar4[2] | *puVar1;
                      piVar4 = piVar4 + 1;
                      iVar17 = iVar17 + -1;
                    } while (iVar17 != 0);
                  }
                }
                bVar3 = false;
              }
              iVar16 = iVar16 + 4;
            }
            piVar4 = (int *)piVar19[0x41];
            bVar3 = false;
            iVar17 = piVar19[0x42];
            iVar10 = *piVar4;
            iVar16 = piVar19[0x40];
            if (iVar10 != 0) {
              bVar3 = false;
              if (iVar10 == 0) {
                iVar10 = 1;
              }
              do {
                uVar13 = piVar4[2] & ~*(uint *)(iVar17 + 8) | *(uint *)(iVar16 + 8);
                if (*(uint *)(iVar16 + 8) != uVar13) {
                  *(uint *)(iVar16 + 8) = uVar13;
                  bVar3 = true;
                }
                piVar4 = piVar4 + 1;
                iVar17 = iVar17 + 4;
                iVar16 = iVar16 + 4;
                iVar10 = iVar10 + -1;
              } while (iVar10 != 0);
            }
            bVar2 = bVar3 || bVar2;
          }
          iVar5 = iVar5 + 1;
        }
      } while (bVar2);
      return;
    }
    uVar18 = *(undefined4 *)(param_4 + 0x378);
    piVar19 = *(int **)(iVar5 + iVar16 * 4);
    puVar11 = (undefined4 *)FUN_00193e18(uVar18,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar18;
    puVar11[1] = uVar13;
    puVar11[2] = param_2;
    if (bVar2) {
      puVar11 = puVar12;
      uVar20 = uVar13;
      if (uVar13 == 0) {
        uVar20 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
    }
    piVar19[0x41] = (int)puVar12;
    uVar18 = *(undefined4 *)(param_4 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar18,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar18;
    puVar11[1] = uVar13;
    puVar11[2] = param_2;
    if (bVar2) {
      puVar11 = puVar12;
      uVar20 = uVar13;
      if (uVar13 == 0) {
        uVar20 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
    }
    piVar19[0x40] = (int)puVar12;
    uVar18 = *(undefined4 *)(param_4 + 0x378);
    puVar11 = (undefined4 *)FUN_00193e18(uVar18,iVar17);
    puVar12 = puVar11 + 1;
    *puVar11 = uVar18;
    puVar11[1] = uVar13;
    puVar11[2] = param_2;
    if (bVar2) {
      puVar11 = puVar12;
      uVar20 = uVar13;
      if (uVar13 == 0) {
        uVar20 = 1;
      }
      do {
        puVar11[2] = 0;
        puVar11 = puVar11 + 1;
        uVar20 = uVar20 - 1;
      } while (uVar20 != 0);
    }
    piVar4 = (int *)piVar19[0x26];
    piVar19[0x42] = (int)puVar12;
    if (piVar4[2] != 0) break;
LAB_00138d5c:
    iVar10 = (**(code **)(*piVar19 + 0x18))(piVar19);
    if (iVar10 != 0) {
      ((int (*)())FUN_00138390)(piVar19,piVar19[0x40]);
    }
    iVar16 = iVar16 + 1;
  }
  do {
    iVar10 = (**(code **)(*piVar4 + 0x7c))(piVar4);
    piVar9 = piVar4;
    if (iVar10 == 0) {
      do {
        uVar20 = piVar9[5];
        if (((uVar20 & 1) != 0) && (*(int *)(piVar9[0x22] + 8) != 0x8e)) {
          iVar10 = (**(code **)(*piVar9 + 0x34))(piVar9);
          if ((iVar10 == 0) &&
             (((iVar10 = (**(code **)(*piVar9 + 0x38))(piVar9), iVar10 == 0 &&
               (iVar10 = (**(code **)(*piVar9 + 0x60))(piVar9), iVar10 == 0)) &&
              (iVar10 = (**(code **)(*piVar9 + 0x5c))(piVar9), iVar10 == 0)))) {
            uVar20 = piVar9[5];
            iVar10 = piVar9[0x21];
            if ((uVar20 & 0x200) != 0) {
              iVar10 = iVar10 + -1;
            }
            if (0 < iVar10) {
              iVar14 = 1;
              do {
                piVar6 = (int *)FUN_00105594(piVar9,iVar14);
                if (((piVar6[0x20] != 0) && (iVar7 = FUN_00126760(piVar6[0x26]), iVar7 != 0)) &&
                   (((piVar6[5] & 2U) == 0 &&
                    ((iVar7 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar7 == 0 &&
                     (iVar7 = ((int (*)())FUN_00137e98)(piVar9,iVar14,piVar9), iVar7 == 0)))))) {
                  iVar7 = FUN_001054ec(piVar9,iVar14);
                  iVar15 = 0;
                  FUN_000f3398(local_58,*(undefined4 *)(iVar7 + 0x10));
                  local_68 = local_58[0];
                  iVar7 = piVar6[0x25];
                  uVar20 = iVar7 << 2;
                  do {
                    if ((*(char *)((int)&local_68 + iVar15) != '\0') &&
                       (iVar8 = ((int (*)())FUN_00137e74)(piVar19[0x42],iVar7,iVar15), iVar8 == 0)) {
                      iVar8 = (uVar20 >> 3 & 0x1ffffffc) + piVar19[0x40];
                      *(uint *)(iVar8 + 8) = 1 << (uVar20 & 0x1f) | *(uint *)(iVar8 + 8);
                    }
                    bVar3 = iVar15 != 3;
                    uVar20 = uVar20 + 1;
                    iVar15 = iVar15 + 1;
                  } while (bVar3);
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 <= iVar10);
              uVar20 = piVar9[5];
            }
            if ((uVar20 & 0x200) == 0) goto LAB_00138af0;
            piVar6 = (int *)FUN_00105594(piVar9,piVar9[0x21]);
            if ((((piVar6[0x20] != 0) && (iVar10 = FUN_00126760(piVar6[0x26]), iVar10 != 0)) &&
                ((piVar6[5] & 2U) == 0)) &&
               (iVar10 = (**(code **)(*piVar6 + 0x50))(piVar6), iVar10 == 0)) {
              iVar14 = piVar6[0x25];
              iVar10 = ((int (*)())FUN_00137e98)(piVar9,piVar9[0x21],piVar9);
              if (iVar10 == 0) {
                uVar20 = iVar14 << 2;
                iVar10 = 0;
                do {
                  iVar7 = FUN_001054ec(piVar9,0);
                  if (((*(char *)(iVar10 + iVar7 + 0x10) == '\x01') &&
                      (iVar7 = ((int (*)())FUN_00137e74)(piVar19[0x42],iVar14,iVar10), iVar7 == 0)) &&
                     (iVar7 = ((int (*)())FUN_00138240)(piVar6,iVar10), iVar7 != 0)) {
                    iVar7 = (uVar20 >> 3 & 0x1ffffffc) + piVar19[0x40];
                    *(uint *)(iVar7 + 8) = 1 << (uVar20 & 0x1f) | *(uint *)(iVar7 + 8);
                  }
                  bVar3 = iVar10 != 3;
                  uVar20 = uVar20 + 1;
                  iVar10 = iVar10 + 1;
                } while (bVar3);
              }
            }
          }
          uVar20 = piVar9[5];
        }
LAB_00138af0:
        piVar6 = piVar4;
      } while (((int *)piVar9[2] != (int *)0x0) && (piVar9 = (int *)piVar9[2], (uVar20 & 4) != 0));
      do {
        uVar20 = piVar6[5];
        if (((uVar20 & 1) != 0) && (*(int *)(piVar6[0x22] + 8) != 0x8e)) {
          iVar10 = (**(code **)(*piVar6 + 0x34))(piVar6);
          if ((((iVar10 == 0) && (iVar10 = (**(code **)(*piVar6 + 0x38))(piVar6), iVar10 == 0)) &&
              (iVar10 = (**(code **)(*piVar6 + 0x60))(piVar6), iVar10 == 0)) &&
             (iVar10 = (**(code **)(*piVar6 + 0x5c))(piVar6), iVar10 == 0)) {
            if ((piVar6[0x20] == 0) || (iVar10 = FUN_00126760(piVar6[0x26]), iVar10 == 0)) {
LAB_00138c50:
              uVar20 = piVar6[5];
            }
            else {
              uVar20 = piVar6[5];
              if ((uVar20 & 2) == 0) {
                iVar10 = (**(code **)(*piVar6 + 0x50))(piVar6);
                if (iVar10 == 0) {
                  iVar10 = 0;
                  do {
                    iVar14 = FUN_001054ec(piVar6,0);
                    if (*(char *)(iVar10 + iVar14 + 0x10) != '\x01') {
                      uVar20 = piVar6[0x25] * 4 + iVar10;
                      iVar14 = (uVar20 >> 3 & 0x1ffffffc) + piVar19[0x42];
                      *(uint *)(iVar14 + 8) = 1 << (uVar20 & 0x1f) | *(uint *)(iVar14 + 8);
                    }
                    bVar3 = iVar10 != 3;
                    iVar10 = iVar10 + 1;
                  } while (bVar3);
                }
                goto LAB_00138c50;
              }
            }
            if ((uVar20 & 0x200) == 0) goto LAB_00138d24;
            piVar9 = (int *)FUN_00105594(piVar6,piVar6[0x21]);
            if (((piVar9[0x20] != 0) && (iVar10 = FUN_00126760(piVar9[0x26]), iVar10 != 0)) &&
               (((piVar9[5] & 2U) == 0 &&
                (iVar10 = (**(code **)(*piVar9 + 0x50))(piVar9), iVar10 == 0)))) {
              iVar10 = 0;
              do {
                iVar14 = FUN_001054ec(piVar6,0);
                if ((*(char *)(iVar10 + iVar14 + 0x10) == '\x01') &&
                   (iVar14 = ((int (*)())FUN_00138240)(piVar9,iVar10), iVar14 != 0)) {
                  uVar20 = piVar6[0x25] * 4 + iVar10;
                  iVar14 = (uVar20 >> 3 & 0x1ffffffc) + piVar19[0x42];
                  *(uint *)(iVar14 + 8) = 1 << (uVar20 & 0x1f) | *(uint *)(iVar14 + 8);
                }
                bVar3 = iVar10 != 3;
                iVar10 = iVar10 + 1;
              } while (bVar3);
            }
          }
          uVar20 = piVar6[5];
        }
LAB_00138d24: ;
      } while (((int *)piVar6[2] != (int *)0x0) && (piVar6 = (int *)piVar6[2], (uVar20 & 4) != 0));
    }
    piVar9 = (int *)piVar4[2];
    piVar6 = piVar4;
    do {
      piVar4 = piVar9;
      puVar1 = (uint *)(piVar6 + 5);
      if ((int *)piVar4[2] == (int *)0x0) goto LAB_00138d5c;
      piVar9 = (int *)piVar4[2];
      piVar6 = piVar4;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_00138fb4 @ 0x138fb4 (84 bytes) */
int FUN_00138fb4(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
  (**(code **)(*piVar1 + 0x6c))(piVar1,param_1,param_4);
  FUN_0014846c(param_1,param_4);
  return;
}

/* FUN_00139008 @ 0x139008 (44 bytes) */
int FUN_00139008(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 4;
  iVar3 = 0;
  uVar2 = 0;
  do {
    uVar1 = uVar2 & 0x3f;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + (param_1 >> uVar1 & 1U);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return iVar3;
}

/* FUN_00139034 @ 0x139034 (40 bytes) */
int FUN_00139034(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x158);
  if (((iVar1 != param_3) && (iVar1 != param_4)) && (iVar1 != param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_0013905c @ 0x13905c (308 bytes) */
int FUN_0013905c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  (**(code **)(*param_2 + 0x14))(param_2);
  piVar1 = (int *)FUN_00105594(param_2,1);
  while (iVar2 = (**(code **)(*piVar1 + 0x60))(piVar1), iVar2 != 0) {
    piVar1 = (int *)FUN_00105594(piVar1,1);
  }
  piVar3 = (int *)FUN_00105594(param_2,2);
  while (iVar2 = (**(code **)(*piVar3 + 0x60))(piVar3), iVar2 != 0) {
    piVar3 = (int *)FUN_00105594(piVar3,1);
  }
  while( true ) {
    do {
      param_2 = (int *)param_2[1];
      iVar2 = (**(code **)(*param_2 + 0x60))(param_2);
    } while (iVar2 != 0);
    if (param_1 == param_2) break;
    if (((param_2 == piVar1) || (param_2 == piVar3)) ||
       (iVar2 = (**(code **)(*param_2 + 0x34))(param_2), iVar2 != 0)) {
      return 0;
    }
  }
  return 1;
}

/* FUN_00139190 @ 0x139190 (156 bytes) */
int FUN_00139190(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28;
  
  uVar1 = *(uint *)(param_1 + 4) - 1;
  piVar2 = (int *)0x0;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    piVar2 = (int *)(uVar1 * 4 + *(int *)(param_1 + 8));
  }
  local_28 = *piVar2;
  if ((char)local_28 == '\0') {
    return local_28 == param_2;
  }
  if (param_2 < 5) {
    iVar4 = 0;
    if (param_2 < 1) goto LAB_00139218;
  }
  else {
    param_2 = 4;
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    if (*(char *)((int)&local_28 + iVar3) != -1) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + 1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
LAB_00139218:
  return iVar4 < 2;
}

/* FUN_0013922c @ 0x13922c (104 bytes) */
int FUN_0013922c(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_28;
  
  piVar3 = (int *)0x0;
  uVar1 = *(uint *)(param_1 + 4) - 1;
  if (uVar1 < *(uint *)(param_1 + 4)) {
    piVar3 = (int *)(uVar1 * 4 + *(int *)(param_1 + 8));
  }
  local_28 = *piVar3;
  if ((char)local_28 == '\0') {
    return local_28;
  }
  iVar2 = 0;
  iVar4 = 4;
  do {
    if (*(char *)((int)&local_28 + iVar2) != -1) {
      return (int)*(char *)((int)&local_28 + iVar2);
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0;
}

/* FUN_00139294 @ 0x139294 (176 bytes) */
int FUN_00139294(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x2e] == 0) {
    do {
      while( true ) {
        param_1 = (int *)param_1[0x3c];
        if ((param_1 == param_2) || (param_1[0x2e] != 0)) goto LAB_0013932c;
        iVar1 = (**(code **)(*param_1 + 0x28))(param_1);
        if (iVar1 == 0) break;
        param_1 = (int *)FUN_000e9184(param_1[0x4b],0);
      }
      iVar1 = (**(code **)(*param_1 + 0x24))(param_1);
    } while (iVar1 == 0);
    uVar2 = 1;
  }
  else {
LAB_0013932c:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_00139344 @ 0x139344 (80 bytes) */
int FUN_00139344(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x69:
  case 0x6b:
  case 0x75:
  case 0x76:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xaf:
    return 1;
  default:
    return 0;
  }
}

/* FUN_001394b0 @ 0x1394b0 (496 bytes) */
int FUN_001394b0(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  piVar5 = *(int **)(param_1 + 0x3a0);
  piVar1 = (int *)(*(int **)(param_1 + 900))[2];
  if (piVar1 != (int *)0x0) {
    piVar3 = (int *)0x0;
    piVar4 = *(int **)(param_1 + 900);
    do {
      piVar2 = piVar1;
      iVar6 = *(int *)(piVar4[0x26] + 8);
      iVar8 = piVar4[0x26];
      if (iVar6 != 0) {
        do {
          iVar7 = iVar6;
          iVar6 = ((int (*)())FUN_00139344)(iVar8);
          if (iVar6 != 0) {
            piVar1 = (int *)FUN_00105594(iVar8,1);
            iVar6 = (**(code **)(*piVar1 + 0x4c))();
            piVar1 = piVar4;
            if (iVar6 != 0) {
              while (piVar1 != piVar5) {
                iVar6 = (**(code **)(*piVar1 + 0x24))(piVar1);
                if (iVar6 != 0) {
                  if (piVar3 == (int *)0x0) {
                    FUN_000e79a0(piVar5);
                    piVar3 = (int *)FUN_000e920c(piVar5,0);
                    iVar6 = (**(code **)(*piVar3 + 0x24))();
                    if (iVar6 == 0) {
                      (**(code **)(*piVar3 + 0x2c))(piVar3);
                    }
                  }
                  FUN_0010401c(iVar8);
                  *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 1;
                  FUN_000e7688(piVar3,iVar8);
                  break;
                }
                iVar6 = (**(code **)(*piVar1 + 0x28))(piVar1);
                if (iVar6 == 0) {
                  iVar6 = (**(code **)(*piVar1 + 0x2c))(piVar1);
                  if (iVar6 == 0) {
                    iVar6 = (**(code **)(*piVar1 + 0x34))(piVar1);
                    if (iVar6 != 0) {
                      piVar1 = (int *)FUN_000e7e90(piVar1[0x4b]);
                    }
                    goto LAB_00139654;
                  }
                  piVar1 = (int *)FUN_000e7e90(piVar1);
                }
                else {
                  piVar1 = (int *)FUN_000e9184(piVar1[0x4b],0);
LAB_00139654:
                  piVar1 = (int *)piVar1[0x3c];
                }
              }
            }
          }
          iVar6 = *(int *)(iVar7 + 8);
          iVar8 = iVar7;
        } while (iVar6 != 0);
        piVar2 = (int *)piVar4[2];
      }
      piVar1 = (int *)piVar2[2];
      piVar4 = piVar2;
    } while ((int *)piVar2[2] != (int *)0x0);
  }
  return;
}

/* FUN_001396a0 @ 0x1396a0 (48 bytes) */
int FUN_001396a0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x13) {
    return;
  }
  if (*(int *)(*(int *)(param_2 + 0x88) + 8) == 0x12) {
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x20000;
  return;
}

/* FUN_001396d0 @ 0x1396d0 (360 bytes) */
int FUN_001396d0(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_38;
  uint local_34;
  uint local_30 [4];
  
  iVar1 = (**(code **)(*param_2 + 0x5c))(param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_001054ec(param_2,0);
    FUN_000f31f8(&local_38,*(undefined4 *)(iVar1 + 0x10),param_2[3]);
    uVar3 = DAT_001b0020;
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2);
    if (param_3 <= iVar1) {
      FUN_000f3c30(&local_34,param_2,param_3,param_4,local_38);
      uVar3 = local_34;
    }
    FUN_000f31f8(local_30,DAT_001b0008,uVar3);
    iVar1 = FUN_00105594(param_2,param_3);
    if ((iVar1 != 0) &&
       (((*(int *)(iVar1 + 0x98) == 2 || (*(int *)(iVar1 + 0x98) == 0xc)) &&
        (iVar2 = (**(code **)(**(int **)(param_1 + 0x30c) + 0xec))
                           (*(int **)(param_1 + 0x30c),param_2,param_3,
                            local_30[0] << 0x18 | (local_30[0] >> 8 & 0xff) << 0x10 |
                            (local_30[0] >> 0x10 & 0xff) << 8 | local_30[0] >> 0x18,
                            *(undefined4 *)(param_4 + 8)), iVar2 != 0)))) {
      iVar2 = FUN_00105594(param_2,param_3);
      if (iVar1 == iVar2) {
        return 1;
      }
      *(uint *)(iVar2 + 0xc) = uVar3 | *(uint *)(iVar2 + 0xc);
      return 1;
    }
  }
  return 0;
}

/* FUN_00139838 @ 0x139838 (124 bytes) */
undefined4 FUN_00139838(double param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_48;
  float local_44;
  
  iVar1 = FUN_001054ec(param_2,0);
  iVar1 = FUN_000f5cf0(param_2,param_3,*(undefined4 *)(iVar1 + 0x10),&local_48);
  if (((iVar1 == 0) || ((double)local_44 != param_1)) || (uVar2 = 1, local_48 != 2)) {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_001398b4 @ 0x1398b4 (964 bytes) */
int FUN_001398b4(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [6];
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x29) {
    return 0;
  }
  iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,param_1,1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_00105594(param_1,2);
  iVar1 = *(int *)(iVar2 + 0x88);
  if ((*(int *)(iVar1 + 8) == 0x24) && ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) {
    iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar2,2);
    if ((iVar1 == 0) ||
       (((iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0e8,iVar2,3), iVar1 == 0 ||
         ((*(uint *)(iVar2 + 0xb8) & 1) != 0)) || ((*(uint *)(iVar2 + 0xb8) & 2) != 0)))) {
      iVar1 = *(int *)(iVar2 + 0x88);
      goto LAB_00139c2c;
    }
  }
  else {
LAB_00139c2c:
    if ((*(int *)(iVar1 + 8) == 0x28) && ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) {
      iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar2,2);
      if ((iVar1 != 0) &&
         (((*(uint *)(iVar2 + 0xb8) & 1) == 0 && ((*(uint *)(iVar2 + 0xb8) & 2) != 0)))) {
        uVar8 = 1;
        uVar6 = 0x27;
        goto LAB_00139978;
      }
      iVar1 = *(int *)(iVar2 + 0x88);
    }
    if ((*(int *)(iVar1 + 8) == 0x28) && ((*(uint *)(iVar2 + 0x14) & 0x200) == 0)) {
      iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar2,1);
      if ((iVar1 != 0) &&
         (((*(uint *)(iVar2 + 0xd0) & 1) == 0 && ((*(uint *)(iVar2 + 0xd0) & 2) == 0)))) {
        uVar8 = 2;
        uVar6 = 0x29;
        goto LAB_00139978;
      }
      iVar1 = *(int *)(iVar2 + 0x88);
    }
    if (*(int *)(iVar1 + 8) != 0x25) {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0x14) & 0x200) != 0) {
      return 0;
    }
    iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0d4,iVar2,2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = ((undefined4 (*)())FUN_00139838)((double)FLOAT_001aa0e8,iVar2,3);
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xb8) & 1) != 0) {
      return 0;
    }
    if ((*(uint *)(iVar2 + 0xb8) & 2) != 0) {
      return 0;
    }
  }
  uVar8 = 1;
  uVar6 = 0x29;
LAB_00139978:
  iVar1 = FUN_00105594(iVar2,uVar8);
  if (((((*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0x12) && ((*(uint *)(iVar1 + 0x14) & 0x200) == 0))
       && ((*(uint *)(iVar1 + 0xb8) & 1) == 0)) &&
      (((*(uint *)(iVar1 + 0xb8) & 2) == 0 && ((*(uint *)(iVar1 + 0xd0) & 1) != 0)))) &&
     ((*(uint *)(iVar1 + 0xd0) & 2) == 0)) {
    iVar3 = FUN_001054ec(param_1,2);
    uVar7 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_001054ec(iVar2,uVar8);
    FUN_000f2bdc(&local_48,*(undefined4 *)(iVar3 + 0x10),uVar7);
    iVar3 = FUN_001054ec(iVar1,1);
    FUN_000f2bdc(&local_44,*(undefined4 *)(iVar3 + 0x10),local_48);
    iVar3 = FUN_001054ec(iVar1,2);
    FUN_000f2bdc(local_40,*(undefined4 *)(iVar3 + 0x10),local_48);
    iVar3 = FUN_00105594(iVar1,1);
    FUN_00106004(param_1,1,iVar3,0,*(undefined4 *)(param_4 + 8));
    iVar4 = FUN_00105594(iVar1,2);
    iVar5 = FUN_0010497c(iVar2,param_4);
    if ((iVar5 == 0) || (iVar1 = FUN_0010497c(iVar1,param_4), iVar1 == 0)) {
      if (*(int *)(param_4 + 0x478) < *(int *)(iVar3 + 0x160)) {
        *(int *)(iVar3 + 0x160) = *(int *)(iVar3 + 0x160) + 1;
      }
      else {
        *(int *)(iVar3 + 0x160) = *(int *)(param_4 + 0x478) + 1;
      }
      if (*(int *)(param_4 + 0x478) < *(int *)(iVar4 + 0x160)) {
        *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + 1;
      }
      else {
        *(int *)(iVar4 + 0x160) = *(int *)(param_4 + 0x478) + 1;
      }
    }
    FUN_00106004(param_1,2,iVar4,0,*(undefined4 *)(param_4 + 8));
    iVar1 = FUN_001054ec(param_1,1);
    *(undefined4 *)(iVar1 + 0x10) = local_44;
    iVar1 = FUN_001054ec(param_1,2);
    *(undefined4 *)(iVar1 + 0x10) = local_40[0];
    uVar6 = FUN_00112f54(uVar6);
    *(undefined4 *)(param_1 + 0x88) = uVar6;
    FUN_00105894(iVar2,*(undefined4 *)(param_4 + 8));
  }
  return 0;
}

/* FUN_00139c78 @ 0x139c78 (200 bytes) */
int FUN_00139c78(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int *piVar2;
  
  if (((*(uint *)(param_1 + 0x14) & 1) != 0) &&
     ((param_2 == 0 || ((*(uint *)(param_2 + 0x14) & 1) != 0)))) {
    iVar1 = ((int (*)())FUN_001398b4)();
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x150) = *(int *)(param_4 + 0x474) + -1;
    }
    piVar2 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
    iVar1 = (**(code **)(*piVar2 + 0x70))(piVar2,param_2,param_3,param_1,param_4);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x150) = *(int *)(param_4 + 0x474) + -1;
    }
    FUN_001486e8(param_1,param_4);
    return;
  }
  return;
}

/* FUN_00139d40 @ 0x139d40 (556 bytes) */
int FUN_00139d40(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint local_48;
  uint local_44;
  int local_40;
  undefined4 local_3c;
  
  local_3c = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  local_44 = 0;
  local_48 = 2;
  local_40 = FUN_00193e18(local_3c,8);
  *(int *)(param_1 + 0x474) = *(int *)(param_1 + 0x474) + 1;
  iVar2 = *(int *)(param_1 + 900);
  for (iVar6 = *(int *)(*(int *)(param_1 + 900) + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    piVar4 = (int *)(*(int **)(iVar2 + 0x98))[2];
    piVar9 = *(int **)(iVar2 + 0x98);
    if (piVar4 != (int *)0x0) {
      do {
        piVar5 = piVar4;
        if ((piVar9[5] & 1U) != 0) {
          iVar6 = (**(code **)(*piVar9 + 0x30))(piVar9);
          uVar3 = local_44;
          if ((iVar6 != 0) && (*(int *)(param_1 + 0x474) != piVar9[0x54])) {
            piVar9[0x54] = *(int *)(param_1 + 0x474);
            if (local_44 < local_48) {
              iVar6 = local_44 * 4;
              _memset((void *)(iVar6 + local_40),0,4);
              local_44 = uVar3 + 1;
              puVar7 = (undefined4 *)(iVar6 + local_40);
            }
            else {
              puVar7 = (undefined4 *)FUN_0019423c(&local_48,local_44);
            }
            *puVar7 = piVar9;
            do {
              piVar4 = (int *)0x0;
              if (local_44 - 1 < local_44) {
                piVar4 = (int *)((local_44 - 1) * 4 + local_40);
              }
              iVar6 = *piVar4;
              FUN_00194208(&local_48);
              if (0 < *(int *)(iVar6 + 0x84)) {
                iVar10 = 1;
                do {
                  iVar8 = FUN_00105594(iVar6,iVar10);
                  uVar3 = local_44;
                  *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 0x2000;
                  if ((iVar8 != 0) && (*(int *)(param_1 + 0x474) != *(int *)(iVar8 + 0x150))) {
                    *(int *)(iVar8 + 0x150) = *(int *)(param_1 + 0x474);
                    if (local_44 < local_48) {
                      iVar1 = local_44 * 4;
                      _memset((void *)(iVar1 + local_40),0,4);
                      local_44 = uVar3 + 1;
                      piVar4 = (int *)(iVar1 + local_40);
                    }
                    else {
                      piVar4 = (int *)FUN_0019423c(&local_48,local_44);
                    }
                    *piVar4 = iVar8;
                  }
                  iVar10 = iVar10 + 1;
                } while (iVar10 <= *(int *)(iVar6 + 0x84));
              }
            } while (local_44 != 0);
          }
          piVar5 = (int *)piVar9[2];
        }
        piVar4 = (int *)piVar5[2];
        piVar9 = piVar5;
      } while ((int *)piVar5[2] != (int *)0x0);
      iVar6 = *(int *)(iVar2 + 8);
    }
    iVar2 = iVar6;
  }
  FUN_00193cc0(local_3c,local_40);
  return;
}

/* FUN_00139f84 @ 0x139f84 (700 bytes) */
int FUN_00139f84(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  int param_3;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  
  iVar3 = (**(code **)(*param_1 + 0x40))();
  if (iVar3 != 0) {
    return;
  }
  uVar4 = FUN_000e7804(param_1);
  uVar11 = param_2[1];
  if (uVar11 < *param_2) {
    _memset((void *)(uVar11 * 4 + param_2[2]),0,4);
    puVar5 = (undefined4 *)(uVar11 * 4 + param_2[2]);
    param_2[1] = uVar11 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(param_2,uVar11);
  }
  *puVar5 = uVar4;
  bVar8 = 0;
  uVar11 = param_2[1];
  bVar9 = 0;
  do {
    piVar6 = (int *)0x0;
    if (uVar11 - 1 < param_2[1]) {
      piVar6 = (int *)((uVar11 - 1) * 4 + param_2[2]);
    }
    iVar3 = *piVar6;
    FUN_00194208(param_2,param_2[1] - 1);
    if (0 < *(int *)(iVar3 + 0x84)) {
      iVar10 = 1;
      do {
        piVar6 = (int *)FUN_00105594(iVar3,iVar10);
        if (piVar6 != (int *)0x0) {
          iVar7 = (**(code **)(*piVar6 + 0x28))();
          if (iVar7 == 0) {
            iVar7 = (**(code **)(*piVar6 + 0x4c))(piVar6);
            if (iVar7 != 0) {
              bVar8 = 1;
            }
          }
          else {
            bVar9 = 1;
          }
          if ((bool)(bVar9 & bVar8)) {
            iVar7 = param_1[0x4d];
            iVar10 = param_1[0x4e];
            iVar3 = FUN_000e9294(param_1);
            if (iVar3 == 0) goto LAB_0013a198;
            piVar6 = *(int **)(iVar7 + 0x98);
            piVar1 = (int *)(*(int **)(iVar7 + 0x98))[2];
            goto joined_r0x0013a104;
          }
          if (param_3 != piVar6[0x54]) {
            piVar6[0x54] = param_3;
            uVar11 = param_2[1];
            if (uVar11 < *param_2) {
              _memset((void *)(uVar11 * 4 + param_2[2]),0,4);
              puVar5 = (undefined4 *)(uVar11 * 4 + param_2[2]);
              param_2[1] = uVar11 + 1;
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(param_2,uVar11);
            }
            *puVar5 = piVar6;
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 <= *(int *)(iVar3 + 0x84));
    }
    uVar11 = param_2[1];
  } while (uVar11 != 0);
LAB_0013a220:
  param_1[3] = param_1[3] | 0x400;
  return;
joined_r0x0013a104:
  if (piVar1 == (int *)0x0) goto LAB_0013a148;
  if ((piVar6[5] & 1U) != 0) {
    iVar3 = (**(code **)(*piVar6 + 0x28))(piVar6);
    if (iVar3 != 0) goto LAB_0013a220;
    piVar1 = (int *)piVar6[2];
  }
  piVar6 = piVar1;
  piVar1 = (int *)piVar1[2];
  goto joined_r0x0013a104;
LAB_0013a148:
  piVar6 = *(int **)(iVar10 + 0x98);
  piVar1 = (int *)piVar6[2];
  do {
    piVar2 = piVar1;
    if (piVar2 == (int *)0x0) {
LAB_0013a198:
      param_1[3] = param_1[3] | 0x800;
      return;
    }
    if ((piVar6[5] & 1U) != 0) {
      iVar3 = (**(code **)(*piVar6 + 0x28))(piVar6);
      if (iVar3 != 0) goto LAB_0013a220;
      piVar2 = (int *)piVar6[2];
    }
    piVar1 = (int *)piVar2[2];
    piVar6 = piVar2;
  } while( true );
}

/* FUN_0013a240 @ 0x13a240 (332 bytes) */
int FUN_0013a240(param_1)
  uint *param_1;
{
  char cVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_38;
  
  piVar3 = (int *)0x0;
  uVar2 = param_1[1] - 1;
  if (uVar2 < param_1[1]) {
    piVar3 = (int *)(uVar2 * 4 + param_1[2]);
  }
  iVar5 = *piVar3;
  FUN_00194208(param_1,param_1[1] - 1);
  local_38 = iVar5;
  iVar5 = local_38;
  (*(unsigned char *)((unsigned char *)&(local_38) + 3)) = (char)iVar5;
  local_38 = iVar5;
  if ((char)local_38 == '\0') {
    uVar2 = param_1[1];
    iVar5 = iVar5 + 1;
    if (uVar2 < *param_1) {
      _memset((void *)(uVar2 * 4 + param_1[2]),0,4);
      piVar3 = (int *)(uVar2 * 4 + param_1[2]);
      param_1[1] = uVar2 + 1;
    }
    else {
      piVar3 = (int *)FUN_0019423c(param_1,uVar2);
    }
    *piVar3 = iVar5;
  }
  else {
    pcVar4 = (char *)&local_38;
    iVar5 = 4;
    do {
      if (*pcVar4 != -1) {
        cVar1 = pcVar4[1];
        *pcVar4 = -1;
        iVar5 = local_38;
        uVar2 = param_1[1];
        if (uVar2 < *param_1) {
          _memset((void *)(uVar2 * 4 + param_1[2]),0,4);
          piVar3 = (int *)(uVar2 * 4 + param_1[2]);
          param_1[1] = uVar2 + 1;
        }
        else {
          piVar3 = (int *)FUN_0019423c(param_1,uVar2);
        }
        *piVar3 = iVar5;
        return (int)cVar1;
      }
      pcVar4 = pcVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar5 = 0;
  }
  return iVar5;
}

/* FUN_0013a38c @ 0x13a38c (696 bytes) */
int FUN_0013a38c(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_48;
  int local_44 [12];
  
  if (param_1 == 0) {
    return 1;
  }
  iVar10 = *(int *)(param_1 + 0x84);
  local_48 = 0xffffffff;
  if (iVar10 == 1) {
    uVar11 = param_2[1];
    local_48 = 0x1ffffff;
    if (uVar11 < *param_2) {
      _memset((void *)(uVar11 * 4 + param_2[2]),0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + param_2[2]);
      param_2[1] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(param_2,uVar11);
    }
    *puVar5 = 0x1ffffff;
    return 1;
  }
  if (4 < iVar10) {
    uVar11 = param_2[1];
    if (uVar11 < *param_2) {
      _memset((void *)(uVar11 * 4 + param_2[2]),0,4);
      puVar5 = (undefined4 *)(uVar11 * 4 + param_2[2]);
      param_2[1] = uVar11 + 1;
    }
    else {
      puVar5 = (undefined4 *)FUN_0019423c(param_2,uVar11);
    }
    *puVar5 = 1;
    return 1;
  }
  uVar6 = FUN_00105594(param_1,1);
  local_44[0] = FUN_00104054(uVar6,param_3);
  uVar6 = FUN_00105594(param_1,2);
  local_44[1] = FUN_00104054(uVar6,param_3);
  if (iVar10 == 2) {
    if (local_44[0] < local_44[1]) {
      (*(unsigned int *)((unsigned char *)&(local_48) + 1)) = CONCAT12(2,(*(unsigned short *)((unsigned char *)&(local_48) + 2)));
      local_48 = CONCAT13(1,(*(unsigned int *)((unsigned char *)&(local_48) + 1)));
    }
    else {
      (*(unsigned int *)((unsigned char *)&(local_48) + 1)) = CONCAT12(1,(*(unsigned short *)((unsigned char *)&(local_48) + 2)));
      local_48 = CONCAT13(2,(*(unsigned int *)((unsigned char *)&(local_48) + 1)));
    }
    goto LAB_0013a5cc;
  }
  uVar6 = FUN_00105594(param_1,3);
  local_44[2] = FUN_00104054(uVar6,param_3);
  if (iVar10 == 4) {
    uVar6 = FUN_00105594(param_1,4);
    local_44[3] = FUN_00104054(uVar6,param_3);
LAB_0013a528:
    iVar4 = 0;
    iVar12 = iVar10;
    do {
      *(char *)((int)local_44 + iVar4 + -4) = (char)(iVar4 + 1);
      iVar12 = iVar12 + -1;
      iVar4 = iVar4 + 1;
    } while (iVar12 != 0);
  }
  else if (0 < iVar10) goto LAB_0013a528;
  do {
    bVar3 = false;
    iVar7 = 0;
    iVar4 = 0;
    piVar9 = local_44;
    iVar12 = iVar10;
    if (iVar10 + -1 < 0) {
      iVar12 = 1;
    }
    while (iVar12 = iVar12 + -1, iVar12 != 0) {
      iVar8 = *piVar9;
      if (piVar9[1] < iVar8) {
        uVar2 = *(undefined1 *)((int)local_44 + iVar7 + -4);
        uVar1 = *(undefined1 *)((int)local_44 + iVar4 + -3);
        *piVar9 = piVar9[1];
        *(undefined1 *)((int)local_44 + iVar7 + -4) = uVar1;
        bVar3 = true;
        piVar9[1] = iVar8;
        *(undefined1 *)((int)local_44 + iVar4 + -3) = uVar2;
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + 1;
      piVar9 = piVar9 + 1;
    }
  } while (bVar3);
LAB_0013a5cc:
  uVar6 = local_48;
  uVar11 = param_2[1];
  if (uVar11 < *param_2) {
    _memset((void *)(uVar11 * 4 + param_2[2]),0,4);
    puVar5 = (undefined4 *)(uVar11 * 4 + param_2[2]);
    param_2[1] = uVar11 + 1;
  }
  else {
    puVar5 = (undefined4 *)FUN_0019423c(param_2,uVar11);
  }
  *puVar5 = uVar6;
  return (int)(*(unsigned char *)((unsigned char *)&(local_48) + 0));
}

/* FUN_0013a644 @ 0x13a644 (304 bytes) */
int FUN_0013a644(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  
  uVar6 = 0;
  puVar9 = *(uint **)(param_1 + 0x10);
  uVar2 = puVar9[1];
  if (uVar2 != 0) {
    uVar7 = 0;
    do {
      if (uVar7 < *puVar9) {
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + puVar9[2]),0,(uVar7 - uVar2) * 4 + 4);
          puVar9[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(uVar7 * 4 + puVar9[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(puVar9,uVar7);
      }
      uVar7 = uVar7 + 1;
      piVar10 = (int *)*puVar3;
      for (iVar8 = 1; iVar5 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar8 <= iVar5;
          iVar8 = iVar8 + 1) {
        iVar5 = FUN_00105594(piVar10,iVar8);
        if (param_1 == iVar5) {
          iVar5 = 0;
          do {
            iVar4 = FUN_001054ec(piVar10,iVar8);
            uVar2 = (uint)*(byte *)(iVar5 + iVar4 + 0x10);
            if (uVar2 != 4) {
              uVar6 = uVar6 | 1 << (uVar2 & 0x3f);
            }
            bVar1 = iVar5 != 3;
            iVar5 = iVar5 + 1;
          } while (bVar1);
        }
      }
      puVar9 = *(uint **)(param_1 + 0x10);
      uVar2 = puVar9[1];
    } while (uVar7 < uVar2);
  }
  return uVar6;
}

/* FUN_0013a774 @ 0x13a774 (304 bytes) */
int FUN_0013a774(param_1, param_2)
  int *param_1;
  uint param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  int iVar10;
  
  puVar9 = (uint *)param_1[4];
  uVar2 = puVar9[1];
  if (uVar2 != 0) {
    uVar7 = 0;
    do {
      if (uVar7 < *puVar9) {
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + puVar9[2]),0,(uVar7 - uVar2) * 4 + 4);
          puVar9[1] = uVar7 + 1;
        }
        puVar3 = (undefined4 *)(uVar7 * 4 + puVar9[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(puVar9,uVar7);
      }
      uVar8 = *puVar3;
      for (iVar10 = 1; iVar6 = (**(code **)(*param_1 + 0x14))(param_1), iVar10 <= iVar6;
          iVar10 = iVar10 + 1) {
        piVar4 = (int *)FUN_00105594(uVar8,iVar10);
        if (param_1 == piVar4) {
          iVar6 = 0;
          do {
            iVar5 = FUN_001054ec(uVar8,iVar10);
            uVar2 = (uint)*(byte *)(iVar6 + iVar5 + 0x10);
            if ((uVar2 != 4) && (param_2 = param_2 & ~(1 << (uVar2 & 0x3f)), param_2 == 0)) {
              return 0;
            }
            bVar1 = iVar6 != 3;
            iVar6 = iVar6 + 1;
          } while (bVar1);
        }
      }
      puVar9 = (uint *)param_1[4];
      uVar7 = uVar7 + 1;
      uVar2 = puVar9[1];
    } while (uVar7 < uVar2);
  }
  return param_2;
}

