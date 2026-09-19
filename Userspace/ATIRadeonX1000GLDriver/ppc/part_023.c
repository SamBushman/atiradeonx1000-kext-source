#include "decls.h"

/* FUN_000e9730 @ 0xe9730 (76 bytes) */
int FUN_000e9730(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  if (*(int *)(param_3 + 0xf0) == param_1) {
    *(undefined4 *)(param_3 + 0xf0) = *(undefined4 *)(param_1 + 0xf0);
  }
  FUN_000e93ac();
  FUN_000e7658(param_1);
  return 1;
}

/* FUN_000e977c @ 0xe977c (404 bytes) */
int FUN_000e977c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  uVar7 = 0;
  puVar8 = *(uint **)(param_1 + 0xd0);
  iVar5 = 0;
  for (uVar4 = 1; uVar4 <= puVar8[1]; uVar4 = uVar4 + 1) {
    if (*(int *)(iVar5 + puVar8[2]) != 0) {
      if (param_2 == *(int *)(iVar5 + puVar8[2])) {
        if (uVar7 < *puVar8) {
          uVar4 = puVar8[1];
          if (uVar4 <= uVar7) {
            _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar7 - uVar4) * 4 + 4);
            puVar8[1] = uVar7 + 1;
          }
          piVar2 = (int *)(uVar7 * 4 + puVar8[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar8,uVar7);
        }
        *piVar2 = param_3;
        break;
      }
      uVar7 = uVar7 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = *(int *)(param_2 + 0xd4);
  iVar3 = 0;
  uVar4 = 1;
  iVar6 = 0;
  do {
    if (*(uint *)(iVar5 + 4) < uVar4) {
LAB_000e9874:
      uVar4 = 1;
      iVar5 = 0;
      while( true ) {
        if (*(uint *)(*(int *)(param_3 + 0xd4) + 4) < uVar4) {
          FUN_000e8d5c(param_3,param_1);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(param_3 + 0xd4) + 8) + iVar5);
        if ((iVar3 != 0) && (param_1 == iVar3)) break;
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar5 + 8) + iVar6);
    if (iVar1 != 0) {
      if (param_1 == iVar1) {
        FUN_00194208(iVar5,iVar3);
        goto LAB_000e9874;
      }
      iVar3 = iVar3 + 1;
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + 4;
  } while( true );
}

/* FUN_000e9910 @ 0xe9910 (56 bytes) */
int FUN_000e9910(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())FUN_000e977c)();
  FUN_000e8e4c(param_4,param_2);
  return;
}

/* FUN_000e9948 @ 0xe9948 (404 bytes) */
int FUN_000e9948(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  uVar7 = 0;
  puVar8 = *(uint **)(param_1 + 0xd4);
  iVar5 = 0;
  for (uVar4 = 1; uVar4 <= puVar8[1]; uVar4 = uVar4 + 1) {
    if (*(int *)(iVar5 + puVar8[2]) != 0) {
      if (param_2 == *(int *)(iVar5 + puVar8[2])) {
        if (uVar7 < *puVar8) {
          uVar4 = puVar8[1];
          if (uVar4 <= uVar7) {
            _memset((void *)(uVar4 * 4 + puVar8[2]),0,(uVar7 - uVar4) * 4 + 4);
            puVar8[1] = uVar7 + 1;
          }
          piVar2 = (int *)(uVar7 * 4 + puVar8[2]);
        }
        else {
          piVar2 = (int *)FUN_0019423c(puVar8,uVar7);
        }
        *piVar2 = param_3;
        break;
      }
      uVar7 = uVar7 + 1;
    }
    iVar5 = iVar5 + 4;
  }
  iVar5 = *(int *)(param_2 + 0xd0);
  iVar3 = 0;
  uVar4 = 1;
  iVar6 = 0;
  do {
    if (*(uint *)(iVar5 + 4) < uVar4) {
LAB_000e9a40:
      uVar4 = 1;
      iVar5 = 0;
      while( true ) {
        if (*(uint *)(*(int *)(param_3 + 0xd0) + 4) < uVar4) {
          FUN_000e8dd4(param_3,param_1);
          return;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(param_3 + 0xd0) + 8) + iVar5);
        if ((iVar3 != 0) && (param_1 == iVar3)) break;
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 4;
      }
      return;
    }
    iVar1 = *(int *)(*(int *)(iVar5 + 8) + iVar6);
    if (iVar1 != 0) {
      if (param_1 == iVar1) {
        FUN_00194208(iVar5,iVar3);
        goto LAB_000e9a40;
      }
      iVar3 = iVar3 + 1;
    }
    uVar4 = uVar4 + 1;
    iVar6 = iVar6 + 4;
  } while( true );
}

/* FUN_000e9adc @ 0xe9adc (292 bytes) */
int FUN_000e9adc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  
  uVar1 = FUN_000e7fe0();
  puVar4 = *(uint **)(param_1 + 0xd0);
  if (uVar1 < *puVar4) {
    uVar2 = puVar4[1];
    if (uVar2 <= uVar1) {
      _memset((void *)(uVar2 * 4 + puVar4[2]),0,(uVar1 - uVar2) * 4 + 4);
      puVar4[1] = uVar1 + 1;
    }
    puVar3 = (undefined4 *)(uVar1 * 4 + puVar4[2]);
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar4,uVar1);
  }
  *puVar3 = param_3;
  uVar1 = FUN_000e803c(param_2,param_1);
  puVar4 = *(uint **)(param_2 + 0xd4);
  if (uVar1 < *puVar4) {
    uVar2 = puVar4[1];
    if (uVar2 <= uVar1) {
      _memset((void *)(uVar2 * 4 + puVar4[2]),0,(uVar1 - uVar2) * 4 + 4);
      puVar4[1] = uVar1 + 1;
    }
    puVar3 = (undefined4 *)(uVar1 * 4 + puVar4[2]);
  }
  else {
    puVar3 = (undefined4 *)FUN_0019423c(puVar4,uVar1);
  }
  *puVar3 = param_3;
  FUN_000e8d5c(param_3,param_1);
  FUN_000e8dd4(param_3,param_2);
  return;
}

/* FUN_000e9c00 @ 0xe9c00 (200 bytes) */
int FUN_000e9c00(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = *(uint **)(param_1 + 0xc4);
  uVar4 = puVar3[1];
  if (0 < (int)uVar4) {
    uVar2 = 0;
    uVar5 = uVar4;
    do {
      piVar1 = (int *)0x0;
      if (uVar2 < uVar4) {
        piVar1 = (int *)(uVar2 * 4 + puVar3[2]);
      }
      if (param_2 == *piVar1) goto LAB_000e9ca8;
      uVar2 = uVar2 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  if (uVar4 < *puVar3) {
    _memset((void *)(uVar4 * 4 + puVar3[2]),0,4);
    piVar1 = (int *)(uVar4 * 4 + puVar3[2]);
    puVar3[1] = uVar4 + 1;
  }
  else {
    piVar1 = (int *)FUN_0019423c(puVar3,uVar4);
  }
  *piVar1 = param_2;
LAB_000e9ca8:
  FUN_00123424(param_2,*(undefined4 *)(param_1 + 0xb0),param_3);
  return;
}

/* FUN_000e9cc8 @ 0xe9cc8 (160 bytes) */
int FUN_000e9cc8(param_1)
  int param_1;
{
  byte bVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x144) == 0) {
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0x148) + 0xa4) + 0x18);
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
    bVar1 = *(byte *)(*piVar2 + 0x15c);
    if ((((bVar1 & 1) != 0) && ((bVar1 & 2) != 0)) && ((bVar1 & 4) != 0)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000e9d68 @ 0xe9d68 (252 bytes) */
int FUN_000e9d68(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *param_1 = &PTR_FUN_001e9b08;
  param_1[3] = uVar1;
  FUN_001940a8(param_1 + 0x24);
  iVar2 = *(int *)(param_2 + 0xa8);
  uVar1 = *(undefined4 *)(param_2 + 0xac);
  param_1[0x2a] = iVar2;
  param_1[0x2b] = uVar1;
  iVar4 = *(int *)(iVar2 + 0x32c);
  param_1[0x2c] = iVar4;
  *(int *)(iVar2 + 0x32c) = iVar4 + 1;
  uVar3 = *(undefined4 *)(param_2 + 0x110);
  uVar1 = *(undefined4 *)(param_2 + 0xc0);
  uVar5 = *(undefined4 *)(param_2 + 0xdc);
  uVar6 = *(undefined4 *)(param_2 + 0x10c);
  param_1[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  param_1[0x30] = uVar1;
  param_1[0x37] = uVar5;
  param_1[0x3a] = 0x7fffffff;
  param_1[0x42] = 0;
  param_1[0x43] = uVar6;
  param_1[0x44] = uVar3;
  param_1[0x46] = 0xffffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  FUN_000e8a08(param_1);
  FUN_000e8938(param_1);
  uVar1 = FUN_000e8124(param_1[0x2b]);
  param_1[0x2d] = uVar1;
  return;
}

/* FUN_000e9e88 @ 0xe9e88 (88 bytes) */
int FUN_000e9e88(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x130);
  *puVar1 = uVar2;
  ((int (*)())FUN_000e9d68)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000e9f00 @ 0xe9f00 (252 bytes) */
int FUN_000e9f00(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = *(undefined4 *)(param_2 + 0xc);
  *param_1 = &PTR_FUN_001e9b08;
  param_1[3] = uVar1;
  FUN_001940a8(param_1 + 0x24);
  iVar2 = *(int *)(param_2 + 0xa8);
  uVar1 = *(undefined4 *)(param_2 + 0xac);
  param_1[0x2a] = iVar2;
  param_1[0x2b] = uVar1;
  iVar4 = *(int *)(iVar2 + 0x32c);
  param_1[0x2c] = iVar4;
  *(int *)(iVar2 + 0x32c) = iVar4 + 1;
  uVar3 = *(undefined4 *)(param_2 + 0x110);
  uVar1 = *(undefined4 *)(param_2 + 0xc0);
  uVar5 = *(undefined4 *)(param_2 + 0xdc);
  uVar6 = *(undefined4 *)(param_2 + 0x10c);
  param_1[0x2e] = *(undefined4 *)(param_2 + 0xb8);
  param_1[0x30] = uVar1;
  param_1[0x37] = uVar5;
  param_1[0x3a] = 0x7fffffff;
  param_1[0x42] = 0;
  param_1[0x43] = uVar6;
  param_1[0x44] = uVar3;
  param_1[0x46] = 0xffffffff;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  FUN_000e8a08(param_1);
  FUN_000e8938(param_1);
  uVar1 = FUN_000e8124(param_1[0x2b]);
  param_1[0x2d] = uVar1;
  return;
}

/* FUN_000ea020 @ 0xea020 (260 bytes) */
int FUN_000ea020(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_001e9b08;
  FUN_001940a8(param_1 + 0x24);
  param_1[0x2a] = param_2;
  param_1[0x2b] = 0;
  iVar3 = *(int *)(param_2 + 0x32c);
  param_1[0x2c] = iVar3;
  *(int *)(param_2 + 0x32c) = iVar3 + 1;
  param_1[0x3a] = 0x7fffffff;
  param_1[0x46] = 0xffffffff;
  param_1[0x4a] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0xffffffff;
  param_1[0x37] = 0;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  FUN_000e8a08(param_1);
  FUN_000e8938(param_1);
  iVar3 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e8124(*(undefined4 *)(param_1[0x2a] + 0x6c4));
  param_1[0x2d] = uVar2;
  return;
}

/* FUN_000ea148 @ 0xea148 (260 bytes) */
int FUN_000ea148(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_001e9b08;
  FUN_001940a8(param_1 + 0x24);
  param_1[0x2a] = param_2;
  param_1[0x2b] = 0;
  iVar3 = *(int *)(param_2 + 0x32c);
  param_1[0x2c] = iVar3;
  *(int *)(param_2 + 0x32c) = iVar3 + 1;
  param_1[0x3a] = 0x7fffffff;
  param_1[0x46] = 0xffffffff;
  param_1[0x4a] = 0;
  param_1[0x2e] = 0;
  param_1[0x30] = 0xffffffff;
  param_1[0x37] = 0;
  param_1[0x39] = 0x7fffffff;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  FUN_000e8a08(param_1);
  FUN_000e8938(param_1);
  iVar3 = 0x20;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = FUN_000e8124(*(undefined4 *)(param_1[0x2a] + 0x6c4));
  param_1[0x2d] = uVar2;
  return;
}

/* FUN_000ea270 @ 0xea270 (304 bytes) */
int FUN_000ea270(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = param_1[0x35];
  *param_1 = &PTR_FUN_001e9b08;
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x34];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3d];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3e];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x31];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_00193fb4(param_1 + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  param_1[0x24] = puVar1;
  param_1[0x27] = puVar1;
  *param_1 = puVar1;
  return;
}

/* FUN_000ea3c0 @ 0xea3c0 (136 bytes) */
int FUN_000ea3c0(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea148)();
  *param_1 = PTR_DAT_001e8b58 + 8;
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  puVar1[1] = 2;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[0x4b] = puVar1 + 1;
  return;
}

/* FUN_000ea478 @ 0xea478 (136 bytes) */
int FUN_000ea478(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea148)();
  *param_1 = PTR_DAT_001e8b58 + 8;
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x14);
  puVar1[1] = 2;
  *puVar1 = uVar2;
  puVar1[2] = 0;
  puVar1[4] = uVar2;
  uVar2 = FUN_00193e18(uVar2,8);
  puVar1[3] = uVar2;
  param_1[0x4b] = puVar1 + 1;
  return;
}

/* FUN_000ea530 @ 0xea530 (160 bytes) */
int FUN_000ea530(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_000ea148)();
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x50] = 0;
  param_1[0x52] = 1;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x51] = 1;
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x130);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea020)(puVar3,param_2);
  param_1[0x4d] = puVar3;
  FUN_000e8e4c(param_1,puVar3);
  return;
}

/* FUN_000ea600 @ 0xea600 (160 bytes) */
int FUN_000ea600(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  ((int (*)())FUN_000ea148)();
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x50] = 0;
  param_1[0x52] = 1;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x51] = 1;
  uVar2 = *(undefined4 *)(param_2 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x130);
  puVar3 = puVar1 + 1;
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea020)(puVar3,param_2);
  param_1[0x4d] = puVar3;
  FUN_000e8e4c(param_1,puVar3);
  return;
}

/* FUN_000ea6d0 @ 0xea6d0 (268 bytes) */
int FUN_000ea6d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea148)(param_1,param_5);
  param_1[0x4c] = param_2;
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x50] = param_3;
  param_1[0x52] = 1;
  param_1[0x55] = 0;
  param_1[0x4d] = param_4;
  param_1[0x4e] = 0;
  param_1[0x51] = 1;
  param_1[0x54] = 0;
  if (param_4 == 0) {
    uVar2 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x130);
    *puVar1 = uVar2;
    ((int (*)())FUN_000ea020)(puVar1 + 1,param_5);
    param_1[0x4d] = puVar1 + 1;
  }
  FUN_000e8e4c(param_1,param_1[0x4d]);
  FUN_000e7688(param_1,param_1[0x4c]);
  uVar2 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_5);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9d70;
  param_1[0x4f] = puVar1 + 1;
  return;
}

/* FUN_000ea828 @ 0xea828 (600 bytes) */
int FUN_000ea828(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  ((int (*)())FUN_000ea148)(param_1,param_5);
  param_1[0x50] = 0;
  *param_1 = &PTR_FUN_001e9bb8;
  param_1[0x53] = param_3;
  param_1[0x4b] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x51] = param_4;
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x134);
  *puVar1 = uVar5;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_5);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9c10;
  param_1[0x54] = puVar1 + 1;
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x134);
  puVar6 = puVar1 + 1;
  *puVar1 = uVar5;
  ((int (*)())FUN_000ea148)(puVar6,param_5);
  puVar1[0x4c] = param_1;
  *puVar6 = &PTR_FUN_001e9c68;
  param_1[0x55] = puVar6;
  FUN_000e8e4c(param_1[0x54],param_1);
  if (param_4 == 0) {
    uVar5 = FUN_001043f0(0x81,param_5);
    param_1[0x52] = uVar5;
    iVar2 = FUN_001054ec(uVar5,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),4,param_2,0);
    FUN_001046c8(param_1[0x52],1,uVar5);
  }
  else {
    uVar5 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x168);
    puVar6 = puVar1 + 1;
    *puVar1 = uVar5;
    FUN_0010502c(puVar6,0xfd,param_5);
    param_1[0x52] = puVar6;
    iVar2 = FUN_001054ec(puVar6,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    iVar2 = FUN_00127608(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),4,0,0);
    piVar3 = *(int **)(iVar2 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)FUN_0019423c(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar4 = *piVar3;
    *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;
    *(byte *)(iVar4 + 0x15c) = *(byte *)(iVar4 + 0x15c) | 1;
    *(undefined4 *)(iVar4 + 0x1c) = 3;
    FUN_001046c8(param_1[0x52],1,iVar2);
    uVar5 = DAT_001aa7fc;
    iVar2 = FUN_001054ec(param_1[0x52],1);
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
  }
  FUN_000e7688(param_1,param_1[0x52]);
  return;
}

/* FUN_000eaae8 @ 0xeaae8 (68 bytes) */
int FUN_000eaae8(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000ea148)();
  *param_1 = &PTR_FUN_001e9ed0;
  return;
}

/* FUN_000eab2c @ 0xeab2c (68 bytes) */
int FUN_000eab2c(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000ea148)();
  *param_1 = &PTR_FUN_001e9ed0;
  return;
}

/* FUN_000eab70 @ 0xeab70 (76 bytes) */
int FUN_000eab70(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000ea148)();
  param_1[0x4b] = param_1[0x32];
  *param_1 = &PTR_FUN_001e9f28;
  return;
}

/* FUN_000eabbc @ 0xeabbc (76 bytes) */
int FUN_000eabbc(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000ea148)();
  param_1[0x4b] = param_1[0x32];
  *param_1 = &PTR_FUN_001e9f28;
  return;
}

/* FUN_000eac08 @ 0xeac08 (88 bytes) */
int FUN_000eac08(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000e9f00)();
  uVar2 = *(undefined4 *)(param_2 + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  param_1[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *param_1 = puVar1;
  param_1[0x4b] = uVar2;
  return;
}

/* FUN_000eac60 @ 0xeac60 (88 bytes) */
int FUN_000eac60(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000e9f00)();
  uVar2 = *(undefined4 *)(param_2 + 300);
  puVar1 = PTR_DAT_001e8b54 + 8;
  param_1[0x4c] = *(undefined4 *)(param_2 + 0x130);
  *param_1 = puVar1;
  param_1[0x4b] = uVar2;
  return;
}

/* FUN_000eacb8 @ 0xeacb8 (80 bytes) */
int FUN_000eacb8(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9c68;
  return;
}

/* FUN_000ead08 @ 0xead08 (88 bytes) */
int FUN_000ead08(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eacb8)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000ead80 @ 0xead80 (80 bytes) */
int FUN_000ead80(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9c68;
  return;
}

/* FUN_000eadd0 @ 0xeadd0 (80 bytes) */
int FUN_000eadd0(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9c10;
  return;
}

/* FUN_000eae20 @ 0xeae20 (88 bytes) */
int FUN_000eae20(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eadd0)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eae98 @ 0xeae98 (80 bytes) */
int FUN_000eae98(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9c10;
  return;
}

/* FUN_000eaee8 @ 0xeaee8 (132 bytes) */
int FUN_000eaee8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())FUN_000e9f00)();
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  uVar4 = *(undefined4 *)(param_2 + 300);
  uVar6 = *(undefined4 *)(param_2 + 0x134);
  uVar5 = *(undefined4 *)(param_2 + 0x138);
  uVar3 = *(undefined4 *)(param_2 + 0x13c);
  uVar2 = *(undefined4 *)(param_2 + 0x140);
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9bb8;
  param_1[0x4b] = uVar4;
  param_1[0x4d] = uVar6;
  param_1[0x4e] = uVar5;
  param_1[0x4f] = uVar3;
  param_1[0x50] = uVar2;
  param_1[0x51] = uVar1;
  return;
}

/* FUN_000eaf6c @ 0xeaf6c (88 bytes) */
int FUN_000eaf6c(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x15c);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eaee8)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eafe4 @ 0xeafe4 (132 bytes) */
int FUN_000eafe4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  ((int (*)())FUN_000e9f00)();
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  uVar4 = *(undefined4 *)(param_2 + 300);
  uVar6 = *(undefined4 *)(param_2 + 0x134);
  uVar5 = *(undefined4 *)(param_2 + 0x138);
  uVar3 = *(undefined4 *)(param_2 + 0x13c);
  uVar2 = *(undefined4 *)(param_2 + 0x140);
  param_1[3] = param_1[3] | 0x20;
  *param_1 = &PTR_FUN_001e9bb8;
  param_1[0x4b] = uVar4;
  param_1[0x4d] = uVar6;
  param_1[0x4e] = uVar5;
  param_1[0x4f] = uVar3;
  param_1[0x50] = uVar2;
  param_1[0x51] = uVar1;
  return;
}

/* FUN_000eb068 @ 0xeb068 (68 bytes) */
int FUN_000eb068(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  *param_1 = &PTR_FUN_001e9d70;
  return;
}

/* FUN_000eb0ac @ 0xeb0ac (88 bytes) */
int FUN_000eb0ac(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eb068)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eb124 @ 0xeb124 (68 bytes) */
int FUN_000eb124(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000e9f00)();
  *param_1 = &PTR_FUN_001e9d70;
  return;
}

/* FUN_000eb168 @ 0xeb168 (104 bytes) */
int FUN_000eb168(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000e9f00)();
  uVar2 = *(undefined4 *)(param_2 + 0x148);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  param_1[0x55] = 0;
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x51] = uVar1;
  param_1[0x52] = uVar2;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  return;
}

/* FUN_000eb1d0 @ 0xeb1d0 (88 bytes) */
int FUN_000eb1d0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x15c);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eb168)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eb248 @ 0xeb248 (104 bytes) */
int FUN_000eb248(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000e9f00)();
  uVar2 = *(undefined4 *)(param_2 + 0x148);
  uVar1 = *(undefined4 *)(param_2 + 0x144);
  param_1[0x55] = 0;
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x51] = uVar1;
  param_1[0x52] = uVar2;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  return;
}

/* FUN_000eb2b0 @ 0xeb2b0 (80 bytes) */
int FUN_000eb2b0(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000e9f00)();
  param_1[0x4b] = *(undefined4 *)(param_2 + 300);
  *param_1 = &PTR_FUN_001e9b60;
  return;
}

/* FUN_000eb300 @ 0xeb300 (88 bytes) */
int FUN_000eb300(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eb2b0)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eb378 @ 0xeb378 (80 bytes) */
int FUN_000eb378(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  ((int (*)())FUN_000e9f00)();
  param_1[0x4b] = *(undefined4 *)(param_2 + 300);
  *param_1 = &PTR_FUN_001e9b60;
  return;
}

/* FUN_000eb3c8 @ 0xeb3c8 (600 bytes) */
int FUN_000eb3c8(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  ((int (*)())FUN_000ea148)(param_1,param_5);
  param_1[0x50] = 0;
  *param_1 = &PTR_FUN_001e9bb8;
  param_1[0x53] = param_3;
  param_1[0x4b] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x51] = param_4;
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x134);
  *puVar1 = uVar5;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_5);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9c10;
  param_1[0x54] = puVar1 + 1;
  uVar5 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x134);
  puVar6 = puVar1 + 1;
  *puVar1 = uVar5;
  ((int (*)())FUN_000ea148)(puVar6,param_5);
  puVar1[0x4c] = param_1;
  *puVar6 = &PTR_FUN_001e9c68;
  param_1[0x55] = puVar6;
  FUN_000e8e4c(param_1[0x54],param_1);
  if (param_4 == 0) {
    uVar5 = FUN_001043f0(0x81,param_5);
    param_1[0x52] = uVar5;
    iVar2 = FUN_001054ec(uVar5,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),4,param_2,0);
    FUN_001046c8(param_1[0x52],1,uVar5);
  }
  else {
    uVar5 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar5,0x168);
    puVar6 = puVar1 + 1;
    *puVar1 = uVar5;
    FUN_0010502c(puVar6,0xfd,param_5);
    param_1[0x52] = puVar6;
    iVar2 = FUN_001054ec(puVar6,0);
    *(undefined4 *)(iVar2 + 8) = param_2;
    *(undefined4 *)(iVar2 + 0xc) = 0x27;
    iVar2 = FUN_00127608(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),4,0,0);
    piVar3 = *(int **)(iVar2 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)FUN_0019423c(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar4 = *piVar3;
    *(undefined4 *)(iVar4 + 0x20) = 0xffffffff;
    *(byte *)(iVar4 + 0x15c) = *(byte *)(iVar4 + 0x15c) | 1;
    *(undefined4 *)(iVar4 + 0x1c) = 3;
    FUN_001046c8(param_1[0x52],1,iVar2);
    uVar5 = DAT_001aa7fc;
    iVar2 = FUN_001054ec(param_1[0x52],1);
    *(undefined4 *)(iVar2 + 0x10) = uVar5;
  }
  FUN_000e7688(param_1,param_1[0x52]);
  return;
}

/* FUN_000eb688 @ 0xeb688 (268 bytes) */
int FUN_000eb688(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea148)(param_1,param_5);
  param_1[0x4c] = param_2;
  *param_1 = &PTR_FUN_001e9cc0;
  param_1[0x50] = param_3;
  param_1[0x52] = 1;
  param_1[0x55] = 0;
  param_1[0x4d] = param_4;
  param_1[0x4e] = 0;
  param_1[0x51] = 1;
  param_1[0x54] = 0;
  if (param_4 == 0) {
    uVar2 = *(undefined4 *)(param_5 + 0x374);
    puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x130);
    *puVar1 = uVar2;
    ((int (*)())FUN_000ea020)(puVar1 + 1,param_5);
    param_1[0x4d] = puVar1 + 1;
  }
  FUN_000e8e4c(param_1,param_1[0x4d]);
  FUN_000e7688(param_1,param_1[0x4c]);
  uVar2 = *(undefined4 *)(param_5 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_5);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9d70;
  param_1[0x4f] = puVar1 + 1;
  return;
}

/* FUN_000eb7e0 @ 0xeb7e0 (68 bytes) */
int FUN_000eb7e0(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eb124)();
  *param_1 = &PTR_FUN_001e9dc8;
  return;
}

/* FUN_000eb824 @ 0xeb824 (68 bytes) */
int FUN_000eb824(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eb124)();
  *param_1 = &PTR_FUN_001e9dc8;
  return;
}

/* FUN_000eb868 @ 0xeb868 (88 bytes) */
int FUN_000eb868(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eb824)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eb8e0 @ 0xeb8e0 (68 bytes) */
int FUN_000eb8e0(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eb248)();
  *param_1 = &PTR_FUN_001e9d18;
  return;
}

/* FUN_000eb924 @ 0xeb924 (68 bytes) */
int FUN_000eb924(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eb248)();
  *param_1 = &PTR_FUN_001e9d18;
  return;
}

/* FUN_000eb968 @ 0xeb968 (88 bytes) */
int FUN_000eb968(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x15c);
  *puVar1 = uVar2;
  ((int (*)())FUN_000eb924)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000eb9e0 @ 0xeb9e0 (168 bytes) */
int FUN_000eb9e0(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea600)(param_1,param_4);
  param_1[0x4c] = param_2;
  *param_1 = &PTR_FUN_001e9d18;
  FUN_000e7688(param_1,param_2);
  param_1[0x50] = param_3;
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_4);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9dc8;
  param_1[0x4f] = puVar1 + 1;
  return;
}

/* FUN_000ebac8 @ 0xebac8 (168 bytes) */
int FUN_000ebac8(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  ((int (*)())FUN_000ea600)(param_1,param_4);
  param_1[0x4c] = param_2;
  *param_1 = &PTR_FUN_001e9d18;
  FUN_000e7688(param_1,param_2);
  param_1[0x50] = param_3;
  uVar2 = *(undefined4 *)(param_4 + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x134);
  *puVar1 = uVar2;
  ((int (*)())FUN_000ea148)(puVar1 + 1,param_4);
  puVar1[0x4c] = param_1;
  puVar1[1] = &PTR_FUN_001e9dc8;
  param_1[0x4f] = puVar1 + 1;
  return;
}

/* FUN_000ebbb0 @ 0xebbb0 (304 bytes) */
int FUN_000ebbb0(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = param_1[0x35];
  *param_1 = &PTR_FUN_001e9b08;
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x34];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3d];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3e];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x31];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_00193fb4(param_1 + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  param_1[0x24] = puVar1;
  param_1[0x27] = puVar1;
  *param_1 = puVar1;
  return;
}

/* FUN_000ebd00 @ 0xebd00 (340 bytes) */
int FUN_000ebd00(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = param_1[0x35];
  *param_1 = &PTR_FUN_001e9b08;
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x34];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3d];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x3e];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  iVar2 = param_1[0x31];
  if (iVar2 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
  }
  FUN_00193fb4(param_1 + 0x24);
  puVar1 = PTR_DAT_001e8b48 + 8;
  param_1[0x27] = puVar1;
  *param_1 = puVar1;
  param_1[0x24] = puVar1;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_000ebe70 @ 0xebe70 (68 bytes) */
int FUN_000ebe70(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eac60)();
  *param_1 = &PTR_FUN_001e9e20;
  return;
}

/* FUN_000ebeb4 @ 0xebeb4 (68 bytes) */
int FUN_000ebeb4(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eac60)();
  *param_1 = &PTR_FUN_001e9e20;
  return;
}

/* FUN_000ebef8 @ 0xebef8 (88 bytes) */
int FUN_000ebef8(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xa8) + 0x374);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0x138);
  *puVar1 = uVar2;
  ((int (*)())FUN_000ebeb4)(puVar1 + 1,param_1);
  return puVar1 + 1;
}

/* FUN_000ebf70 @ 0xebf70 (68 bytes) */
int FUN_000ebf70(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eac60)();
  *param_1 = &PTR_FUN_001e9e78;
  return;
}

/* FUN_000ebfb4 @ 0xebfb4 (68 bytes) */
int FUN_000ebfb4(param_1)
  undefined4 *param_1;
{
  ((int (*)())FUN_000eac60)();
  *param_1 = &PTR_FUN_001e9e78;
  return;
}

