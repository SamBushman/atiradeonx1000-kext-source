#include "decls.h"

/* FUN_00053dc0 @ 0x53dc0 (20 bytes) */
int FUN_00053dc0(param_1, param_2)
  int param_1;
  int param_2;
{
  *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 8) + param_2;
  return;
}

/* FUN_00053de0 @ 0x53de0 (268 bytes) */
int FUN_00053de0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 8) == param_2) {
    FUN_00053b60(param_1,0);
  }
  uVar5 = 0;
  iVar3 = 0;
  bVar1 = true;
  while (uVar5 < *(uint *)(iVar4 + 4)) {
    if (!bVar1) goto LAB_00053e6c;
    if (param_2 == *(int *)(iVar3 + *(int *)(iVar4 + 0xc) + 8)) {
      bVar1 = false;
    }
    else {
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 0x7c;
    }
  }
  if (!bVar1) {
LAB_00053e6c:
    if (*(int *)(uVar5 * 0x7c + *(int *)(iVar4 + 0xc) + 0xc) == 0) {
      ((int (*)())FUN_00055300)(param_1);
      pvVar2 = (void *)(uVar5 * 0x7c + *(int *)(iVar4 + 0xc));
      _memmove(pvVar2,(void *)((int)pvVar2 + 0x7c),(*(int *)(iVar4 + 4) - uVar5) * 0x7c - 0x7c);
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
      if (uVar5 < *(uint *)(((unsigned char *)0x00001188) + param_1)) {
        iVar3 = *(uint *)(((unsigned char *)0x00001188) + param_1) - 1;
        *(int *)(((unsigned char *)0x00001188) + param_1) = iVar3;
        *(int *)(((unsigned char *)0x00001168) + param_1) = iVar3 * 0x7c + *(int *)(iVar4 + 0xc);
      }
    }
  }
  return;
}

/* FUN_00053ef0 @ 0x53ef0 (12 bytes) */
int FUN_00053ef0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  ((int (*)())FUN_00053de0)();
  return;
}

/* FUN_00053f00 @ 0x53f00 (124 bytes) */
int FUN_00053f00(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    ((int (*)())FUN_000553c0)(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,0);
  }
  return;
}

/* FUN_00053f80 @ 0x53f80 (124 bytes) */
int FUN_00053f80(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    ((int (*)())FUN_000553c0)(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,param_5);
  }
  return;
}

/* FUN_00054000 @ 0x54000 (128 bytes) */
int FUN_00054000(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    ((int (*)())FUN_000553c0)(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,&DAT_001db9a8,
                 param_4,&DAT_001db998,param_5);
  }
  return;
}

/* FUN_00054080 @ 0x54080 (276 bytes) */
int FUN_00054080(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  int iVar1;
  int iVar2;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 - 0x87d5U < 0xb)) && (0x87d4 < param_5)) &&
      ((param_5 < 0x87e0 && (0x87d4 < param_6)))) &&
     ((param_6 < 0x87e0 && ((0x87d4 < param_7 && (param_7 < 0x87e0)))))) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    local_28 = param_4;
    local_24 = param_5;
    local_20 = param_6;
    local_1c = param_7;
    iVar1 = ((int (*)())FUN_000553c0)(param_1,iVar2,0x879a,param_2,&DAT_001db9a8,param_3,&local_28,0);
    if ((iVar1 != 0) && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)((param_2 - 0x879dU) + iVar2 + 0x44) = 1;
    }
  }
  return;
}

/* FUN_000541a0 @ 0x541a0 (196 bytes) */
int FUN_000541a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if ((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 < 2)) && (param_5 < 2)) &&
     ((param_6 < 2 && (param_7 < 2)))) {
    local_28 = param_4;
    local_24 = param_5;
    local_20 = param_6;
    local_1c = param_7;
    ((int (*)())FUN_000553c0)(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),0x879b,param_2,&local_28,param_3,
                 &DAT_001db998,0);
  }
  return;
}

/* FUN_00054270 @ 0x54270 (308 bytes) */
int FUN_00054270(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  
  if ((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 < 4)) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    iVar1 = ((int (*)())FUN_000553c0)(param_1,iVar2,0x879c,param_2,&DAT_001db9a8,param_3,&DAT_001db998,0);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar2 + 0x14) * 0x74 + *(int *)(iVar2 + 0x18);
      iVar2 = ((int (*)())FUN_000550e0)(iVar2 + 0x1c,iVar1 + -0x70);
      if (iVar2 == 0x87bf) {
        if (param_4 == 1) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
        }
        else if (param_4 == 0) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
        }
        else if (param_4 == 2) {
          *(undefined4 *)(iVar1 + -0x5c) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
        }
        else if (param_4 == 3) {
          *(undefined4 *)(iVar1 + -0x60) = 0;
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
        }
      }
      *(uint *)(iVar1 + -0x34) = param_4;
    }
  }
  return;
}

/* FUN_000543b0 @ 0x543b0 (164 bytes) */
int FUN_000543b0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  int iVar1;
  int iVar2;
  
  if ((((unsigned char *)0x00001170)[param_1] != '\0') && (param_4 < 4)) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    iVar1 = ((int (*)())FUN_000553c0)(param_1,iVar2,0x879d,param_2,&DAT_001db9a8,param_3,&DAT_001db998,0);
    if (iVar1 != 0) {
      *(uint *)(*(int *)(iVar2 + 0x14) * 0x74 + *(int *)(iVar2 + 0x18) + -0x34) = param_4;
    }
  }
  return;
}

/* FUN_00054460 @ 0x54460 (8 bytes) */
int FUN_00054460()
{
  FUN_00053340();
  return;
}

/* FUN_00054470 @ 0x54470 (272 bytes) */
int FUN_00054470(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    iVar3 = *piVar2;
    *param_3 = piVar2[0x22];
    *param_4 = *(int *)(param_1 + 0x2448) + *(int *)(iVar3 + 0x14);
    iVar1 = *(int *)(iVar3 + 0x2b8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      *(int *)(iVar3 + 0x2b8) = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  else {
    piVar2 = (int *)**(undefined4 **)
                      (*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    *param_3 = piVar2[0x49];
    *param_4 = *(int *)(param_1 + 0x2448) + *piVar2;
    iVar1 = piVar2[0x4f6];
    if (iVar1 == 0) {
      iVar1 = (**(code **)(param_1 + 0xc))(0x80c);
      piVar2[0x4f6] = iVar1;
      *param_2 = iVar1;
      return 1;
    }
  }
  *param_2 = iVar1;
  return 0;
}

/* FUN_00054590 @ 0x54590 (288 bytes) */
int FUN_00054590(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if (param_3 == 0) {
    iVar9 = 0;
    iVar8 = 0;
    iVar7 = 0;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    iVar7 = 0;
    iVar9 = 0;
    iVar8 = 0;
    puVar6 = param_2;
    do {
      iVar2 = *param_4;
      param_4 = param_4 + 1;
      iVar2 = *(int *)(iVar2 * 4 + *(int *)(iVar1 + 0x24)) * 0x54 + *(int *)(iVar1 + 0x20);
      if (*(char *)(iVar2 + 0x3d) == '\0') {
        if (iVar5 < (int)param_2[0x200]) {
          iVar9 = iVar9 + 1;
        }
        else if (iVar5 < (int)param_2[0x201]) {
          iVar7 = iVar7 + 1;
        }
        else {
          iVar8 = iVar8 + 1;
        }
      }
      else {
        uVar3 = puVar6[1];
        param_2[iVar4 * 2] = *puVar6;
        param_2[iVar4 * 2 + 1] = uVar3;
        *(char *)(param_2 + iVar4 * 2) = (char)*(undefined4 *)(iVar2 + 4);
        param_2[iVar4 * 2 + 1] = *(undefined4 *)(iVar2 + 0x38);
        iVar4 = iVar4 + 1;
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    iVar7 = iVar7 + iVar9;
  }
  param_2[0x200] = param_2[0x200] - iVar9;
  param_2[0x201] = param_2[0x201] - iVar7;
  param_2[0x202] = param_2[0x202] - (iVar8 + iVar7);
  return;
}

/* FUN_000546d0 @ 0x546d0 (284 bytes) */
int FUN_000546d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,0);
  (**(code **)(((unsigned char *)0x000011a4) + param_1))(param_1,param_2,*(undefined4 *)(((unsigned char *)0x0000118c) + param_1));
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  if (*(int *)(param_2 + 0x1c) != 0) {
    uVar3 = 0;
    iVar2 = 0;
    do {
      uVar3 = uVar3 + 1;
      iVar1 = iVar2 + *(int *)(param_2 + 0x20);
      iVar2 = iVar2 + 0x54;
      *(undefined1 *)(iVar1 + 0x3d) = 0;
    } while (uVar3 < *(uint *)(param_2 + 0x1c));
  }
  (**(code **)(((unsigned char *)0x00001194) + param_1))(param_1,param_2);
  (**(code **)(((unsigned char *)0x0000119c) + param_1))(param_1,param_2);
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(param_2 + 100);
  return;
}

/* FUN_000547f0 @ 0x547f0 (324 bytes) */
int FUN_000547f0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 - 0x1400U < 0xb) {
    iVar3 = *(int *)(((unsigned char *)0x00001168) + param_1);
    if ((*(char *)(param_1 + 0x31) != '\0') &&
       (*(char *)(*(int *)(iVar3 + 4) + *(int *)(((unsigned char *)0x0000118c) + param_1)) != '\0')) {
      ((int (*)())FUN_000546d0)(param_1,iVar3);
    }
    iVar2 = ((int (*)())FUN_00055a30)(iVar3 + 0x1c,param_2);
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0x28) == 0x87c3)) && (*(char *)(iVar2 + 0x44) == '\0')) {
      puVar1 = *(undefined4 **)(iVar2 + 0x38);
      *puVar1 = *param_4;
      puVar1[1] = param_4[1];
      puVar1[2] = param_4[2];
      puVar1[3] = param_4[3];
      *(undefined1 *)(iVar2 + 0x44) = 1;
      iVar2 = ((int (*)())FUN_00055a30)(iVar3 + 0x1c,param_2);
      if ((iVar2 != 0) && (*(char *)(iVar2 + 0x3d) != '\0')) {
        (**(code **)(*(int *)(iVar2 + 0x24) * 4 + param_1 + -0x20bac))(param_1,iVar3,iVar2);
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* FUN_00054940 @ 0x54940 (56 bytes) */
int FUN_00054940(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == 0x87e2) {
    uVar1 = FUN_00053220(param_1,0,0,0x87bf,0x87c1,0);
    return uVar1;
  }
  return 0;
}

/* FUN_00054980 @ 0x54980 (260 bytes) */
int FUN_00054980(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(iVar4 + 4) != 0) {
    uVar5 = 0;
    iVar6 = 0;
    do {
      uVar5 = uVar5 + 1;
      iVar3 = iVar6 + *(int *)(iVar4 + 0xc);
      iVar6 = iVar6 + 0x7c;
      ((int (*)())FUN_00055300)(param_1,iVar3);
    } while (uVar5 < *(uint *)(iVar4 + 4));
  }
  iVar3 = 0;
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 4) = 0;
  ((int (*)())FUN_000551f0)(param_1,iVar4 + 0x14);
  iVar6 = iVar4;
  do {
    iVar2 = *(int *)(iVar6 + 0x28);
    while (iVar2 != 0) {
      *(int *)(iVar6 + 0x28) = *(int *)(iVar2 + 0xc);
      (**(code **)(param_1 + 0x18))();
      iVar2 = *(int *)(iVar6 + 0x28);
    }
    bVar1 = iVar3 != 0x1f;
    iVar6 = iVar6 + 4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  (**(code **)(param_1 + 0x18))(iVar4);
  *(undefined4 *)(((unsigned char *)0x0000116c) + param_1) = 0;
  return;
}

/* FUN_00054a90 @ 0x54a90 (120 bytes) */
int FUN_00054a90(param_1)
  int param_1;
{
  (**(code **)(((unsigned char *)0x000011a8) + param_1))();
  **(int **)(((unsigned char *)0x0000116c) + param_1) = **(int **)(((unsigned char *)0x0000116c) + param_1) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + param_1) == 0) {
    ((int (*)())FUN_00054980)(param_1);
    return;
  }
  return;
}

/* FUN_00054b20 @ 0x54b20 (240 bytes) */
int FUN_00054b20(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = (**(code **)(param_1 + 0xc))(0x7c0);
  puVar2[9] = 0;
  puVar2[3] = uVar1;
  *puVar2 = 1;
  puVar2[1] = 1;
  puVar2[2] = 1;
  puVar2[4] = 1;
  ((int (*)())FUN_00055b50)(param_1,uVar1);
  *(undefined4 *)(puVar2[3] + 8) = 0;
  ((unsigned char *)0x00001170)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x000011b4) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000118c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001168) + param_1) = puVar2[3];
  (**(code **)(((unsigned char *)0x000011a0) + param_1))(param_1);
  puVar2[9] = 0;
  ((int (*)())FUN_00055a60)(param_1,puVar2 + 5);
  iVar3 = 0x20;
  do {
    puVar2[10] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_00054c10 @ 0x54c10 (388 bytes) */
int FUN_00054c10(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  
  **(int **)(((unsigned char *)0x0000116c) + param_1) = **(int **)(((unsigned char *)0x0000116c) + param_1) + -1;
  if (**(int **)(((unsigned char *)0x0000116c) + param_1) == 0) {
    ((int (*)())FUN_00054980)();
  }
  piVar6 = *(int **)(((unsigned char *)0x0000116c) + param_2);
  iVar1 = piVar6[4];
  *(int *)(((unsigned char *)0x0000118c) + param_1) = iVar1;
  piVar6[4] = iVar1 + 1;
  ((unsigned char *)0x00001170)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = 0;
  *(int **)(((unsigned char *)0x0000116c) + param_1) = piVar6;
  *(int *)(((unsigned char *)0x00001168) + param_1) = piVar6[3];
  *piVar6 = *piVar6 + 1;
  if (piVar6[1] != 0) {
    uVar3 = 0;
    iVar1 = 0;
    do {
      iVar5 = piVar6[3];
      uVar3 = uVar3 + 1;
      pvVar4 = *(void **)(iVar1 + iVar5);
      uVar2 = (**(code **)(param_1 + 0x10))(piVar6[4],4);
      *(undefined4 *)(iVar1 + iVar5) = uVar2;
      _memcpy(*(void **)(piVar6[3] + iVar1),pvVar4,piVar6[4] * 4 - 4);
      (**(code **)(param_1 + 0x18))(pvVar4);
      (**(code **)(((unsigned char *)0x000011a4) + param_1))
                (param_1,iVar1 + piVar6[3],*(undefined4 *)(((unsigned char *)0x0000118c) + param_1));
      iVar5 = piVar6[3];
      pvVar4 = *(void **)(iVar1 + iVar5 + 4);
      uVar2 = (**(code **)(param_1 + 0x10))(piVar6[4],1);
      *(undefined4 *)(iVar1 + iVar5 + 4) = uVar2;
      iVar5 = piVar6[3] + iVar1;
      iVar1 = iVar1 + 0x7c;
      _memcpy(*(void **)(iVar5 + 4),pvVar4,piVar6[4] - 1);
      (**(code **)(param_1 + 0x18))(pvVar4);
    } while (uVar3 < (uint)piVar6[1]);
  }
  return;
}

/* FUN_00054da0 @ 0x54da0 (36 bytes) */
int FUN_00054da0(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (*(uint *)(param_1 + 0xc) <= param_2) {
    return 0;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 8));
}

/* FUN_00054dd0 @ 0x54dd0 (376 bytes) */
int FUN_00054dd0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  void *param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2;
  if ((uVar2 & 0x3f) == 0) {
    uVar2 = (**(code **)(param_1 + 0xc))(((unsigned char *)0x00001500) + uVar2 * 0x54);
    if (uVar2 != 0) {
      if (param_2[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar2,param_2[1],*param_2 * 0x54);
        (**(code **)(param_1 + 0x18))(param_2[1]);
      }
      param_2[1] = uVar2;
      uVar2 = *param_2;
      goto LAB_00054e60;
    }
LAB_00054f2c:
    uVar2 = 0;
  }
  else {
LAB_00054e60:
    _memcpy((void *)(param_2[1] + uVar2 * 0x54),param_3,0x54);
    uVar1 = *(uint *)((int)param_3 + 0x20);
    *(undefined1 *)(uVar2 * 0x54 + param_2[1] + 0x3c) = 0;
    if (param_2[3] <= uVar1) {
      uVar1 = (**(code **)(param_1 + 0x10))(uVar1 + 0x40,4);
      if (uVar1 == 0) goto LAB_00054f2c;
      if (param_2[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar1,param_2[2],param_2[3] << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar1;
      param_2[3] = *(int *)((int)param_3 + 0x20) + 0x40;
      uVar1 = *(uint *)((int)param_3 + 0x20);
    }
    *(uint *)(uVar1 * 4 + param_2[2]) = uVar2;
    *param_2 = *param_2 + 1;
  }
  return uVar2;
}

/* FUN_00054f50 @ 0x54f50 (380 bytes) */
int FUN_00054f50(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  if (param_3 == 0) {
    param_5[1] = 0;
    *param_5 = 0;
    goto LAB_000550a0;
  }
  iVar9 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  uVar1 = param_3 & 0x7fffffff;
  *(byte *)(param_5 + 6) = (byte)(param_3 >> 0x1f);
  iVar4 = ((int (*)())FUN_00054da0)(iVar9 + 0x14,uVar1);
  if (iVar4 == 0) {
    iVar5 = ((int (*)())FUN_00054da0)(param_2 + 0x1c,uVar1);
    if (iVar5 == 0) {
      return 0;
    }
  }
  else {
    param_2 = param_2 + 0x1c;
    iVar5 = ((int (*)())FUN_00054da0)(param_2,uVar1);
    if (iVar5 == 0) {
      iVar5 = *(int *)(iVar9 + 0x18);
      iVar8 = iVar4 * 0x54;
      if (*(int *)(iVar5 + iVar8 + 0x30) == 0) {
        uVar2 = *(uint *)(iVar5 + iVar8 + 0x34);
        if (uVar2 < 2) {
          iVar5 = ((int (*)())FUN_00054dd0)(param_1,param_2);
          goto LAB_00055088;
        }
      }
      else {
        iVar4 = ((int (*)())FUN_00054da0)(iVar9 + 0x14);
        iVar8 = iVar4 * 0x54;
        uVar2 = *(uint *)(iVar5 + iVar8 + 0x34);
      }
      if (uVar2 != 0) {
        iVar4 = iVar4 * 0x54;
        uVar2 = 0;
        do {
          iVar5 = iVar4 + iVar5;
          uVar2 = uVar2 + 1;
          iVar4 = iVar4 + 0x54;
          ((int (*)())FUN_00054dd0)(param_1,param_2,iVar5);
          iVar5 = *(int *)(iVar9 + 0x18);
        } while (uVar2 < *(uint *)(iVar8 + iVar5 + 0x34));
      }
      iVar5 = ((int (*)())FUN_00054da0)(param_2,uVar1);
    }
  }
LAB_00055088:
  param_5[1] = iVar5;
  *param_5 = 2;
LAB_000550a0:
  uVar6 = param_4[1];
  uVar7 = param_4[2];
  uVar3 = param_4[3];
  param_5[2] = *param_4;
  param_5[3] = uVar6;
  param_5[4] = uVar7;
  param_5[5] = uVar3;
  return 1;
}

/* FUN_000550e0 @ 0x550e0 (244 bytes) */
int FUN_000550e0(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*param_2 == 1) {
    uVar1 = param_2[1];
    if (uVar1 < 0x6111) {
      if (0x610e < uVar1) {
        return 0x87bf;
      }
      if (uVar1 == 0x610e) {
        return 0x87be;
      }
    }
    else if (0x8799 < uVar1) {
      if (uVar1 < 0x87a5) {
        return 0x87bf;
      }
      if (uVar1 == 0x87bd) {
        return 0x87be;
      }
    }
  }
  else if (*param_2 == 2) {
    iVar3 = param_2[1] * 0x54 + *(int *)(param_1 + 4);
    uVar1 = *(uint *)(iVar3 + 0x28);
    if ((0x87c0 < uVar1) && ((uVar1 < 0x87c5 || (uVar1 == 0xffffffff)))) {
      iVar2 = *(int *)(iVar3 + 0x24);
      if (iVar2 != 0x87bf) {
        if (iVar2 == 0x87c0) {
          return 0x87c0;
        }
        if (iVar2 != 0x87be) {
          return 0;
        }
        if (*(char *)(iVar3 + 0x44) == '\0') {
          return 0x87be;
        }
        if (*(int *)(iVar3 + 0x48) != 0xf) {
          return 0x87be;
        }
      }
      return 0x87bf;
    }
  }
  return 0;
}

/* FUN_000551f0 @ 0x551f0 (244 bytes) */
int FUN_000551f0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = param_2[1];
  if (uVar2 != 0) {
    uVar3 = *param_2;
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        iVar1 = uVar4 * 0x54 + uVar2;
        if ((*(int *)(iVar1 + 0x38) != 0) && (*(char *)(iVar1 + 0x3c) != '\0')) {
          (**(code **)(param_1 + 0x18))();
          *(undefined4 *)(uVar4 * 0x54 + param_2[1] + 0x38) = 0;
          uVar2 = param_2[1];
          uVar3 = *param_2;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    (**(code **)(param_1 + 0x18))(uVar2);
    *param_2 = 0;
    param_2[1] = 0;
    (**(code **)(param_1 + 0x18))(param_2[2]);
    param_2[3] = 0;
    param_2[2] = 0;
  }
  return;
}

/* FUN_00055300 @ 0x55300 (184 bytes) */
int FUN_00055300(param_1, param_2)
  int param_1;
  int *param_2;
{
  (**(code **)(((unsigned char *)0x000011ac) + param_1))(param_1,param_2,1);
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0x18))();
    *param_2 = 0;
  }
  if (param_2[1] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[1] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[6] = 0;
    param_2[5] = 0;
  }
  ((int (*)())FUN_000551f0)(param_1,param_2 + 7);
  return;
}

/* FUN_000553c0 @ 0x553c0 (556 bytes) */
int FUN_000553c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  
  uVar2 = *(uint *)(param_2 + 0x14);
  if ((uVar2 & 0x3f) == 0) {
    iVar3 = (**(code **)(param_1 + 0xc))(uVar2 * 0x74 + 0x1d00);
    if (iVar3 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (iVar3,*(int *)(param_2 + 0x18),*(int *)(param_2 + 0x14) * 0x74);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x18));
    }
    *(int *)(param_2 + 0x18) = iVar3;
    uVar2 = *(uint *)(param_2 + 0x14);
  }
  iVar3 = uVar2 * 0x74 + *(int *)(param_2 + 0x18);
  if (0x20 < param_3 - 0x8782U) {
    return 0;
  }
  *(int *)(uVar2 * 0x74 + *(int *)(param_2 + 0x18)) = param_3;
  if (param_4 < 0x879d) {
    if ((param_4 < 0x879a) && (2 < param_4 - 0x610e)) {
LAB_00055500:
      iVar5 = ((int (*)())FUN_00054da0)(param_2 + 0x1c,param_4);
      if (iVar5 == 0) {
        return 0;
      }
      iVar4 = *(int *)(iVar5 * 0x54 + *(int *)(param_2 + 0x20) + 0x28);
      if ((iVar4 != 0x87c4) && (iVar4 != -1)) {
        return 0;
      }
      *(int *)(iVar3 + 8) = iVar5;
      *(undefined4 *)(iVar3 + 4) = 2;
      goto LAB_00055550;
    }
  }
  else if (param_4 < 0x87a5) {
    if ((int)(uint)(byte)((unsigned char *)0x000013b0)[param_1] <= (int)(param_4 - 0x879d)) {
      return 0;
    }
  }
  else if (param_4 != 0x87bd) goto LAB_00055500;
  *(uint *)(iVar3 + 8) = param_4;
  *(undefined4 *)(iVar3 + 4) = 1;
LAB_00055550:
  uVar1 = *param_5;
  uVar6 = param_5[1];
  uVar7 = param_5[2];
  *(undefined4 *)(iVar3 + 0x18) = param_5[3];
  *(undefined4 *)(iVar3 + 0xc) = uVar1;
  *(undefined4 *)(iVar3 + 0x10) = uVar6;
  *(undefined4 *)(iVar3 + 0x14) = uVar7;
  iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_6,param_7,iVar3 + 0x20);
  if (((iVar5 != 0) &&
      (iVar5 = ((int (*)())FUN_00054f50)(param_1,param_2,param_8,in_stack_00000038,iVar3 + 0x3c), iVar5 != 0)) &&
     (iVar3 = ((int (*)())FUN_00054f50)(param_1,param_2,in_stack_0000003c,in_stack_00000040,iVar3 + 0x58),
     iVar3 != 0)) {
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
    return 1;
  }
  return 0;
}

/* FUN_00055610 @ 0x55610 (1008 bytes) */
int FUN_00055610(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  uint param_7;
  int param_8;
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  if (*(int *)(iVar5 + 0x24) < 0) {
LAB_00055a00:
    uVar3 = 0;
  }
  else {
    uVar4 = *param_2;
    if ((uVar4 & 0x3f) == 0) {
      uVar4 = (**(code **)(param_1 + 0xc))(((unsigned char *)0x00001500) + uVar4 * 0x54);
      if (uVar4 == 0) goto LAB_00055a00;
      if (param_2[1] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar4,param_2[1],*param_2 * 0x54);
        (**(code **)(param_1 + 0x18))(param_2[1]);
      }
      param_2[1] = uVar4;
      uVar4 = *param_2;
    }
    if (param_4 == -4) {
      *(undefined4 *)(param_2[1] + uVar4 * 0x54 + 0x28) = 0x87c1;
      *(undefined1 *)(uVar4 * 0x54 + param_2[1] + 0x3c) = 0;
    }
    else if (param_4 == -3) {
      iVar6 = uVar4 * 0x54;
      *(undefined4 *)(param_2[1] + iVar6 + 0x28) = 0x87c2;
      *(int *)(iVar6 + param_2[1] + 0x38) =
           param_8 * 0x10 + *(int *)(((unsigned char *)0x00004308) + *(int *)(*(int *)(param_1 + 4) + 0x10));
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
    }
    else if (param_4 == -2) {
      iVar6 = uVar4 * 0x54;
      *(undefined4 *)(param_2[1] + iVar6 + 0x28) = 0x87c2;
      *(int *)(iVar6 + param_2[1] + 0x38) =
           param_8 * 0x10 +
           *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x18c) + 0x18);
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
    }
    else {
      iVar6 = uVar4 * 0x54;
      *(int *)(param_2[1] + iVar6 + 0x28) = param_4;
      if (param_3 == 0x87bf) {
        uVar3 = 0x10;
      }
      else if (param_3 == 0x87c0) {
        uVar3 = 0x40;
      }
      else {
        if (param_3 != 0x87be) {
          *(undefined4 *)(iVar6 + param_2[1] + 0x38) = 0;
          *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 0;
          goto LAB_00055870;
        }
        uVar3 = 4;
      }
      uVar2 = param_2[1];
      uVar3 = (**(code **)(param_1 + 0xc))(uVar3);
      *(undefined4 *)(iVar6 + uVar2 + 0x38) = uVar3;
      *(undefined1 *)(iVar6 + param_2[1] + 0x3c) = 1;
    }
LAB_00055870:
    iVar6 = uVar4 * 0x54;
    *(undefined4 *)(param_2[1] + iVar6 + 0x20) = *(undefined4 *)(iVar5 + 0x24);
    *(int *)(param_2[1] + iVar6 + 0x24) = param_3;
    *(undefined4 *)(param_2[1] + iVar6 + 0x2c) = param_5;
    if ((param_6 != 0) || (1 < param_7)) {
      iVar1 = iVar6 + param_2[1];
      if (param_6 == 0) {
        param_6 = *(int *)(iVar1 + 0x20);
      }
    }
    else {
      iVar1 = param_2[1] + iVar6;
    }
    *(int *)(iVar1 + 0x30) = param_6;
    *(uint *)(param_2[1] + iVar6 + 0x34) = param_7;
    *(undefined1 *)(param_2[1] + iVar6 + 0x3d) = 0;
    *(undefined4 *)(param_2[1] + iVar6 + 0x40) = 0xffffffff;
    *(undefined1 *)(param_2[1] + iVar6 + 0x44) = 0;
    uVar2 = *(uint *)(iVar5 + 0x24);
    if (param_2[3] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0x10))(uVar2 + 0x40,4);
      if (uVar2 == 0) goto LAB_00055a00;
      if (param_2[2] != 0) {
        (**(code **)(((unsigned char *)0x00001344) + param_1))(uVar2,param_2[2],param_2[3] << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      param_2[3] = *(int *)(iVar5 + 0x24) + 0x40;
      uVar2 = *(uint *)(iVar5 + 0x24);
    }
    *(uint *)(uVar2 * 4 + param_2[2]) = uVar4;
    *param_2 = *param_2 + 1;
    iVar1 = *(int *)(iVar5 + 0x24) + 1;
    *(int *)(iVar5 + 0x24) = iVar1;
    if (iVar1 == 0x610e) {
      *(undefined4 *)(iVar5 + 0x24) = 0x6111;
    }
    else if (iVar1 == 0x879a) {
      *(undefined4 *)(iVar5 + 0x24) = 0x87be;
    }
    uVar3 = *(undefined4 *)(param_2[1] + iVar6 + 0x20);
  }
  return uVar3;
}

/* FUN_00055a30 @ 0x55a30 (48 bytes) */
int FUN_00055a30(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    iVar1 = *(int *)(param_2 * 4 + *(int *)(param_1 + 8)) * 0x54 + *(int *)(param_1 + 4);
  }
  return iVar1;
}

/* FUN_00055a60 @ 0x55a60 (220 bytes) */
int FUN_00055a60(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24);
  if (iVar2 == 0) {
    uVar1 = ((int (*)())FUN_00055610)(param_1,param_2,0x87c0,0x87c2,0x87e1,0,0,0);
    iVar2 = ((int (*)())FUN_00055a30)(param_2,uVar1);
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined1 *)(iVar2 + 0x44) = 1;
    *(undefined4 *)(iVar2 + 0x48) = 0x87e3;
    *(undefined4 *)(iVar2 + 0x50) = 0x80;
  }
  else {
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = 0;
    ((int (*)())FUN_00055610)(param_1,param_2,0x87be,0x87c1,0x87e1,0,0,0);
    *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x24) = iVar2;
  }
  return;
}

/* FUN_00055b50 @ 0x55b50 (428 bytes) */
int FUN_00055b50(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10),4)
  ;
  *param_2 = uVar2;
  (**(code **)(((unsigned char *)0x000011a4) + param_1))(param_1,param_2,0xffffffff);
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10),1)
  ;
  param_2[1] = uVar2;
  if (0 < *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10)) {
    iVar3 = 0;
    do {
      *(undefined1 *)(param_2[1] + iVar3) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0x10));
  }
  *(undefined1 *)(param_2 + 4) = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  ((int (*)())FUN_00055a60)(param_1,param_2 + 7);
  param_2[0xc] = 0;
  param_2[0xb] = 0;
  if (((unsigned char *)0x000013b0)[param_1] != '\0') {
    iVar3 = 0;
    puVar1 = param_2;
    do {
      *(undefined1 *)(puVar1 + 0xd) = 0;
      *(undefined1 *)(puVar1 + 0x11) = 1;
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b0)[param_1]);
  }
  iVar3 = 4;
  *(undefined1 *)(param_2 + 0x1b) = 0;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  puVar1 = param_2;
  do {
    *(undefined1 *)((int)puVar1 + 0x6d) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 8;
  puVar1 = param_2;
  do {
    *(undefined1 *)((int)puVar1 + 0x71) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)((int)param_2 + 0x7b) = 0;
  *(undefined1 *)((int)param_2 + 0x79) = 0;
  *(undefined1 *)((int)param_2 + 0x7a) = 0;
  return;
}

/* FUN_00055d00 @ 0x55d00 (148 bytes) */
int FUN_00055d00(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  uVar3 = *(uint *)(iVar4 + 4);
  if (uVar3 != 0) {
    uVar5 = 0;
    iVar7 = 0;
    do {
      iVar2 = iVar7 + *(int *)(iVar4 + 8);
      if (*(int *)(iVar2 + 4) == 0x8620) {
        puVar6 = *(undefined4 **)(iVar2 + 0x14);
        uVar1 = FUN_00053b00(param_1,*puVar6);
        puVar6[0x2a] = uVar1;
        uVar3 = *(uint *)(iVar4 + 4);
      }
      uVar5 = uVar5 + 1;
      iVar7 = iVar7 + 0x18;
    } while (uVar5 < uVar3);
  }
  return;
}

/* FUN_00055da0 @ 0x55da0 (1756 bytes) */
int FUN_00055da0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (*(int *)(param_4 + 0x28) == 0x87c2) {
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x224) = *(int *)(param_3 + 0x224) + 1;
    }
    else {
      *(int *)(param_3 + 0x22c) = *(int *)(param_3 + 0x22c) + 1;
    }
    iVar4 = *(int *)(param_4 + 0x24);
    *(undefined1 *)(param_4 + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_00055f28;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x58) - 3U) {
        if (!bVar1) goto LAB_00055fac;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_00055fac:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x58);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (*(int *)(param_4 + 0x28) != 0x87c3) {
      return;
    }
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar4 = *(int *)(param_4 + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x58)) {
        if (!bVar1) goto LAB_00055f2c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_00055f28:
      if (bVar1) {
        *(undefined1 *)(param_2 + 0x10) = uVar6;
        iVar4 = *(int *)(param_3 + 0x58);
        uVar9 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
        *(undefined4 *)(param_3 + 0x54) = uVar9;
        *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
        goto LAB_000562e8;
      }
LAB_00055f2c:
      *(uint *)(param_4 + 4) = uVar7;
      goto LAB_00055f30;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x58) - 3U) {
        if (!bVar1) goto LAB_0005636c;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0005636c:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x54) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x58);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x54) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return;
    }
    if (iVar4 != 0x87be) {
      return;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x58)) {
      if (!bVar1) goto LAB_0005618c;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x54) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (bVar1) {
    *(char *)(param_2 + 0x10) = (char)uVar9;
    iVar4 = *(int *)(param_3 + 0x58);
    uVar5 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
    (**(code **)(((unsigned char *)0x00001344) + param_1))
              (uVar5,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
    *(undefined4 *)(param_3 + 0x54) = uVar5;
    *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
    *(undefined4 *)(param_4 + 8) = uVar9;
LAB_000562e8:
    *(int *)(param_4 + 4) = iVar4;
    *(undefined1 *)(iVar4 * 0x28 + *(int *)(param_3 + 0x54) + 0x10) = 1;
    return;
  }
LAB_0005618c:
  *(uint *)(param_4 + 4) = uVar7;
  *(undefined4 *)(param_4 + 8) = 0;
LAB_00055f30:
  *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x54) + 0x10) = 1;
  return;
}

/* FUN_000564c0 @ 0x564c0 (1668 bytes) */
int FUN_000564c0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*param_4 != 2) {
    return;
  }
  iVar10 = param_4[1];
  iVar11 = iVar10 * 0x54 + *(int *)(param_2 + 0x20);
  if (*(int *)(iVar11 + 0x28) != 0x87c4) {
    return;
  }
  bVar1 = *(char *)(iVar11 + 0x3d) == '\0';
  if (!bVar1) {
    return;
  }
  *(undefined1 *)(iVar11 + 0x3d) = 1;
  *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
  iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(param_2 + 0x20) + 0x24);
  if (iVar7 == 0x87bf) {
    uVar9 = 0;
    uVar6 = 0;
    while (uVar9 < *(uint *)(param_3 + 0x50)) {
      if (!bVar1) goto LAB_000567d8;
      if (*(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) == '\0') {
        uVar6 = 1;
        bVar1 = false;
      }
      else {
        uVar9 = uVar9 + 1;
      }
    }
    if (bVar1) {
      *(undefined1 *)(param_2 + 0x10) = uVar6;
      uVar9 = *(uint *)(param_3 + 0x50);
      uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
      *(undefined4 *)(param_3 + 0x4c) = uVar4;
      iVar7 = uVar9 * 0x28;
      *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
      *(uint *)(iVar11 + 4) = uVar9;
      *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
      *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x24) = iVar10;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
LAB_00056918:
      *(uint *)(param_3 + 0x2ac) = uVar9 + 1;
      return;
    }
LAB_000567d8:
    *(uint *)(iVar11 + 4) = uVar9;
    iVar11 = uVar9 * 0x28;
    *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar11 + 0x10) = 1;
    *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
    *(int *)(iVar11 + *(int *)(param_3 + 0x4c) + 0x24) = iVar10;
    if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
      return;
    }
  }
  else {
    if (iVar7 == 0x87c0) {
      uVar9 = 0;
      while (uVar9 < *(int *)(param_3 + 0x50) - 3U) {
        if (!bVar1) goto LAB_00056978;
        if (*(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar9 = uVar9 + 1;
        }
      }
      if (!bVar1) {
LAB_00056978:
        iVar7 = uVar9 * 0x28;
        iVar8 = iVar7 + *(int *)(param_3 + 0x4c);
        if (((*(char *)(iVar8 + 0x38) == '\0') && (*(char *)(iVar8 + 0x60) == '\0')) &&
           (*(char *)(iVar8 + 0x88) == '\0')) {
          iVar8 = 0;
          iVar12 = 4;
          do {
            iVar2 = uVar9 + iVar8;
            iVar8 = iVar8 + 1;
            *(int *)(iVar11 + 0x10) = iVar2;
            iVar11 = iVar11 + 4;
            *(undefined1 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x10) = 1;
            *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 4;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x1c) = iVar10;
            *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x20) = iVar10;
            iVar2 = iVar7 + *(int *)(param_3 + 0x4c);
            iVar7 = iVar7 + 0x28;
            *(int *)(iVar2 + 0x24) = iVar10;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
          if (uVar9 + 3 < *(uint *)(param_3 + 0x2ac)) {
            return;
          }
          *(uint *)(param_3 + 0x2ac) = uVar9 + 4;
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar12 = *(int *)(param_3 + 0x50);
      uVar4 = (**(code **)(param_1 + 0x10))(iVar12 + 0x10,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
      *(undefined4 *)(param_3 + 0x4c) = uVar4;
      iVar8 = iVar12 * 0x28;
      iVar2 = 4;
      iVar7 = 0;
      *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
      do {
        iVar3 = iVar12 + iVar7;
        iVar7 = iVar7 + 1;
        *(int *)(iVar11 + 0x10) = iVar3;
        iVar11 = iVar11 + 4;
        *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x10) = 1;
        *(undefined4 *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x14) = 4;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x18) = iVar10;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x1c) = iVar10;
        *(int *)(*(int *)(param_3 + 0x4c) + iVar8 + 0x20) = iVar10;
        iVar3 = *(int *)(param_3 + 0x4c) + iVar8;
        iVar8 = iVar8 + 0x28;
        *(int *)(iVar3 + 0x24) = iVar10;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (iVar12 + 3U < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
      *(int *)(param_3 + 0x2ac) = iVar12 + 4;
      return;
    }
    if (iVar7 != 0x87be) {
      return;
    }
    uVar5 = *(uint *)(param_3 + 0x50);
    uVar9 = 0;
    bVar1 = false;
    iVar7 = 0;
    while (uVar9 < uVar5) {
      if (bVar1) goto LAB_000565ec;
      iVar8 = iVar7 + *(int *)(param_3 + 0x4c);
      if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
        uVar9 = uVar9 + 1;
        iVar7 = iVar7 + 0x28;
        bVar1 = false;
      }
    }
    if (bVar1) {
LAB_000565ec:
      *(uint *)(iVar11 + 4) = uVar9;
      iVar7 = uVar9 * 0x28;
      *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x14);
      iVar11 = iVar7 + *(int *)(param_3 + 0x4c);
      *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
      iVar7 = iVar7 + *(int *)(param_3 + 0x4c);
      *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
    }
    else {
      if (uVar5 == 0) {
LAB_000566c8:
        *(undefined1 *)(param_2 + 0x10) = 0;
        uVar9 = *(uint *)(param_3 + 0x50);
        uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
        *(undefined4 *)(param_3 + 0x4c) = uVar4;
        iVar7 = uVar9 * 0x28;
        *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
        *(undefined4 *)(iVar11 + 8) = 0;
        *(uint *)(iVar11 + 4) = uVar9;
        *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
        *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 1;
        *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
        if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
          return;
        }
        goto LAB_00056918;
      }
      uVar9 = 0;
      do {
        bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x4c) + 0x10) != '\0';
        if (bVar1) {
          uVar9 = uVar9 + 1;
        }
        if (uVar5 <= uVar9) {
          if (bVar1) goto LAB_000566c8;
          break;
        }
      } while (bVar1);
      *(uint *)(iVar11 + 4) = uVar9;
      iVar7 = uVar9 * 0x28;
      *(undefined4 *)(iVar11 + 8) = 0;
      *(undefined1 *)(*(int *)(param_3 + 0x4c) + iVar7 + 0x10) = 1;
      *(undefined4 *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x14) = 1;
      *(int *)(iVar7 + *(int *)(param_3 + 0x4c) + 0x18) = iVar10;
      if (uVar9 < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
    }
  }
  *(uint *)(param_3 + 0x2ac) = uVar9 + 1;
  return;
}

/* FUN_00056b80 @ 0x56b80 (80 bytes) */
int FUN_00056b80(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_00056be0 @ 0x56be0 (816 bytes) */
int FUN_00056be0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  bool bVar21;
  
  iVar17 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  uVar14 = *(uint *)(iVar17 + 0x50);
  if (uVar14 != 0) {
    uVar15 = param_3 + 1;
    uVar12 = 0;
    iVar16 = 0;
    do {
      iVar19 = iVar16 + *(int *)(iVar17 + 0x4c);
      if (*(char *)(iVar19 + 0x10) != '\0') {
        iVar13 = *(int *)(iVar19 + 0x18);
        if (((((iVar13 != 0) || (*(int *)(iVar19 + 0x1c) != 0)) || (*(int *)(iVar19 + 0x20) != 0))
            || (*(int *)(iVar19 + 0x24) != 0)) && (uVar7 = param_2[5], uVar15 < uVar7)) {
          bVar8 = 0;
          bVar9 = 0;
          bVar10 = 0;
          iVar20 = uVar15 * 0x74 + param_2[6];
          bVar11 = 0;
          bVar5 = true;
          uVar18 = uVar15;
          do {
            iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x20,iVar19);
            if (((iVar6 == 0) && (iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x3c,iVar19), iVar6 == 0)) &&
               (iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 0x58,iVar19), iVar6 == 0)) {
              iVar6 = ((int (*)())FUN_00056b80)(iVar20 + 4,iVar19);
              if (iVar6 != 0) {
                iVar6 = *(int *)(iVar20 + 8);
                if (*(int *)(iVar6 * 0x54 + param_2[8] + 0x24) == 0x87be) {
                  bVar1 = iVar13 == iVar6;
                  bVar2 = iVar6 == *(int *)(iVar19 + 0x1c);
                  bVar3 = iVar6 == *(int *)(iVar19 + 0x20);
                  bVar4 = iVar6 == *(int *)(iVar19 + 0x24);
                }
                else {
                  bVar1 = *(byte *)(iVar20 + 0xf);
                  bVar2 = *(byte *)(iVar20 + 0x13);
                  bVar3 = *(byte *)(iVar20 + 0x17);
                  bVar4 = *(byte *)(iVar20 + 0x1b);
                }
                bVar11 = bVar11 | bVar4;
                bVar10 = bVar10 | bVar3;
                bVar9 = bVar9 | bVar2;
                bVar8 = bVar8 | bVar1;
                if (((bVar8 != 0) && (bVar9 != 0)) && (bVar10 != 0)) {
                  bVar21 = bVar11 != 0;
                  goto LAB_00056e00;
                }
              }
              bVar21 = false;
            }
            else {
              bVar5 = false;
              bVar21 = true;
            }
LAB_00056e00:
            uVar18 = uVar18 + 1;
          } while ((uVar18 != uVar7) && (iVar20 = iVar20 + 0x74, !bVar21));
          if (!bVar5) goto LAB_00056ef0;
        }
        *(undefined1 *)(iVar13 * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x1c) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x20) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)
         (*(int *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x24) * 0x54 + param_2[8] + 0x3d) = 0;
        *(undefined1 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x10) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x14) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x18) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x1c) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x20) = 0;
        *(undefined4 *)(iVar16 + *(int *)(iVar17 + 0x4c) + 0x24) = 0;
        param_2[0x19] = param_2[0x19] + -1;
        uVar14 = *(uint *)(iVar17 + 0x50);
      }
LAB_00056ef0:
      uVar12 = uVar12 + 1;
      iVar16 = iVar16 + 0x28;
    } while (uVar12 < uVar14);
  }
  return;
}

/* FUN_00056f20 @ 0x56f20 (988 bytes) */
int FUN_00056f20(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  uint *param_3;
  uint *param_4;
  uint param_5;
  uint param_6;
  int param_7;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar6 = *param_4;
  param_5 = param_5 & 0x3f;
  uVar1 = (param_6 & 1) << 6;
  iVar9 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  *param_4 = uVar1 | param_5 | uVar6 & 0xefffff00;
  uVar2 = (param_3[2] & 1) << 0x14;
  *param_4 = uVar2 | uVar1 | param_5 | uVar6 & 0xefefff00;
  uVar3 = (param_3[3] & 1) << 0x15;
  *param_4 = uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xefcfff00;
  uVar4 = (param_3[4] & 1) << 0x16;
  *param_4 = uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef8fff00;
  uVar5 = (param_3[5] & 1) << 0x17;
  *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0fff00;
  uVar7 = *param_3;
  if (uVar7 == 2) {
    iVar9 = param_3[1] * 0x54 + param_2[8];
    if (*(int *)(iVar9 + 0x28) == 0x87c4) {
      iVar8 = *(int *)(iVar9 + 0x24);
      if (iVar8 == 0x87bf) {
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(iVar9 + 4) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7;
      }
      else if (iVar8 == 0x87c0) {
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(param_7 * 4 + iVar9 + 0x10) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7;
      }
      else {
        if (iVar8 != 0x87be) {
          return 0;
        }
        *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
        uVar7 = (*(uint *)(iVar9 + 4) & 0x7f) << 0xd;
        param_5 = param_5 | uVar6 & 0xef001000;
        *param_4 = uVar7 | uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5;
        iVar9 = *(int *)(iVar9 + 8);
        if (iVar9 == 1) {
          uVar7 = uVar7 | uVar3 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else if (iVar9 == 0) {
          uVar7 = uVar7 | uVar2 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else if (iVar9 == 2) {
          uVar7 = uVar7 | uVar4 | uVar1 | param_5;
          *param_4 = uVar7;
        }
        else {
          if (iVar9 != 3) {
            return 0;
          }
          uVar7 = uVar7 | uVar5 | uVar1 | param_5;
          *param_4 = uVar7;
        }
      }
    }
    else {
      if (*(int *)(iVar9 + 0x28) != -1) {
        return 0;
      }
      uVar7 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x100;
      *param_4 = uVar7;
    }
  }
  else if (uVar7 < 3) {
    if (uVar7 != 1) {
      return 0;
    }
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x200;
    uVar7 = param_3[1];
    if (uVar7 == 0x879b) {
      uVar7 = (*(uint *)(iVar9 + 0x1ec) & 0x7f) << 0xd |
              uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
      *param_4 = uVar7;
    }
    else if (uVar7 < 0x879c) {
      if (uVar7 == 0x610f) {
        if (*(char *)((int)param_2 + 0x6f) != '\0') {
          uVar7 = (*(uint *)(iVar9 + 500) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
      }
      else {
        if (uVar7 < 0x6110) {
          if (uVar7 != 0x610e) {
            return 0;
          }
          if (*(char *)((int)param_2 + 0x79) == '\0') {
            *param_4 = uVar5 | uVar4 | uVar3 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          }
          else {
            *param_4 = (*(uint *)(iVar9 + 0x1fc) & 0x7f) << 0xd |
                       uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          }
          uVar7 = *param_4 & 0xff1fffff;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
        if (uVar7 != 0x6110) {
          if (uVar7 != 0x879a) {
            return 0;
          }
          uVar7 = (*(uint *)(iVar9 + 0x1e8) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
        if (*(char *)(param_2 + 0x1c) != '\0') {
          uVar7 = (*(uint *)(iVar9 + 0x1f8) & 0x7f) << 0xd |
                  uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
          *param_4 = uVar7;
          goto LAB_00057320;
        }
      }
      uVar7 = uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
      *param_4 = uVar7;
    }
    else if (uVar7 < 0x87a5) {
      if (uVar7 < 0x879d) {
        uVar7 = (*(uint *)(iVar9 + 0x1f0) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
        *param_4 = uVar7;
        if (*(char *)(iVar9 + 0x42) != '\0') {
          uVar7 = *param_4 & 0xff7fffff;
          *param_4 = uVar7;
        }
      }
      else {
        uVar7 = (*(uint *)(uVar7 * 4 + iVar9 + -0x21c74) & 0x7f) << 0xd |
                uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x200;
        *param_4 = uVar7;
      }
    }
    else {
      if (uVar7 != 0x87bd) {
        return 0;
      }
      *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x300;
      uVar2 = (*(uint *)(iVar9 + 0x1f0) & 0x7f) << 0xd;
      param_5 = param_5 | uVar6 & 0xef001000;
      *param_4 = uVar2 | uVar5 | uVar1 | param_5 | 0x300;
      uVar7 = (*(byte *)(iVar9 + 0x42) & 1) << 0x17 | uVar2 | uVar1 | param_5 | 0x300;
      *param_4 = uVar7;
    }
  }
  else if (uVar7 == 3) {
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000;
    uVar7 = (param_3[1] & 0x7f) << 0xd |
            uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000;
    *param_4 = uVar7;
  }
  else {
    if (uVar7 != 5) {
      return 0;
    }
    *param_4 = uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef0ff000 | 0x100;
    uVar7 = (param_3[1] & 0x7f) << 0xd |
            uVar5 | uVar4 | uVar3 | uVar2 | uVar1 | param_5 | uVar6 & 0xef001000 | 0x100;
    *param_4 = uVar7;
  }
LAB_00057320:
  *param_4 = uVar7 & 0x1fffefff;
  return 1;
}

/* FUN_00057340 @ 0x57340 (1768 bytes) */
int FUN_00057340(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  switch(param_3[2]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = *param_4 & 0xffff1fff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = *param_4 & 0xffff1fff | 0x2000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = *param_4 & 0xffff1fff | 0x4000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = *param_4 & 0xffff1fff | 0x6000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = *param_4 & 0xffff1fff | 0x8000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = *param_4 & 0xffff1fff | 0xa000;
    *param_4 = uVar4;
    break;
  default:
    goto LAB_00057ae0;
  }
  if (10 < param_3[2] - 0x87d5) {
LAB_00057ae0:
    return 0;
  }
  uVar5 = 1 << (param_3[2] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x2000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xfdffffff;
    *param_4 = uVar4;
  }
  switch(param_3[3]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xfff8ffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xfff8ffff | 0x10000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xfff8ffff | 0x20000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xfff8ffff | 0x30000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xfff8ffff | 0x40000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xfff8ffff | 0x50000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[3] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[3] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x4000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xfbffffff;
    *param_4 = uVar4;
  }
  switch(param_3[4]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xffc7ffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xffc7ffff | 0x80000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xffc7ffff | 0x100000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xffc7ffff | 0x180000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xffc7ffff | 0x200000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xffc7ffff | 0x280000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[4] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[4] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x8000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xf7ffffff;
    *param_4 = uVar4;
  }
  switch(param_3[5]) {
  case 0x87d5:
  case 0x87d9:
    uVar4 = uVar4 & 0xfe3fffff;
    *param_4 = uVar4;
    break;
  case 0x87d6:
  case 0x87da:
    uVar4 = uVar4 & 0xfe3fffff | 0x400000;
    *param_4 = uVar4;
    break;
  case 0x87d7:
  case 0x87db:
    uVar4 = uVar4 & 0xfe3fffff | 0x800000;
    *param_4 = uVar4;
    break;
  case 0x87d8:
  case 0x87dc:
    uVar4 = uVar4 & 0xfe3fffff | 0xc00000;
    *param_4 = uVar4;
    break;
  case 0x87dd:
    uVar4 = uVar4 & 0xfe3fffff | 0x1000000;
    *param_4 = uVar4;
    break;
  case 0x87de:
  case 0x87df:
    uVar4 = uVar4 & 0xfe3fffff | 0x1400000;
    *param_4 = uVar4;
    break;
  default:
    return 0;
  }
  if (10 < param_3[5] - 0x87d5) {
    return 0;
  }
  uVar5 = 1 << (param_3[5] - 0x87d5 & 0x3f);
  if ((uVar5 & 0x30f) == 0) {
    if ((uVar5 & 0x4f0) == 0) {
      return 0;
    }
    uVar4 = uVar4 | 0x10000000;
    *param_4 = uVar4;
  }
  else {
    uVar4 = uVar4 & 0xefffffff;
    *param_4 = uVar4;
  }
  uVar5 = *param_3;
  if (uVar5 != 2) {
    if (uVar5 < 3) {
      if (uVar5 != 0) {
        return 0;
      }
      uVar5 = uVar4 & 0xffffe018;
      *param_4 = uVar5;
    }
    else if (uVar5 == 3) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (param_3[1] & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
    }
    else {
      if (uVar5 != 4) {
        return 0;
      }
      *param_4 = uVar4 & 0xfffffff8 | 2;
      uVar5 = (param_3[1] & 0xff) << 5 | uVar4 & 0xffffe018 | 2;
      *param_4 = uVar5;
    }
    goto LAB_00057aa0;
  }
  iVar7 = param_3[1] * 0x54;
  iVar8 = iVar7 + *(int *)(param_2 + 4);
  uVar5 = *(uint *)(iVar8 + 0x28);
  if (uVar5 < 0x87c4) {
    if (uVar5 < 0x87c2) {
      if (uVar5 != 0x87c1) {
        return 0;
      }
      iVar6 = *(int *)(iVar8 + 0x24);
      if (iVar6 == 0x87bf) {
        *param_4 = uVar4 & 0xfffffff8 | 1;
        uVar1 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
        uVar5 = uVar1 | uVar4 & 0xffffe018 | 1;
        *param_4 = uVar5;
        iVar7 = iVar7 + *(int *)(param_2 + 4);
        if ((*(char *)(iVar7 + 0x44) != '\0') && (*(int *)(iVar7 + 0x48) == 1)) {
          uVar5 = uVar1 | uVar4 & 0xfe3fe018 | 1 | 0x1000000;
          *param_4 = uVar5;
        }
        goto LAB_00057aa0;
      }
      if (iVar6 != 0x87c0) {
        if (iVar6 != 0x87be) {
          return 0;
        }
        *param_4 = uVar4 & 0xfffffff8 | 1;
        uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
        *param_4 = uVar5 | uVar4 & 0xffffe018 | 1;
        uVar1 = (*(uint *)(iVar8 + 8) & 7) << 0xd;
        *param_4 = uVar1 | uVar5 | uVar4 & 0xffff0018 | 1;
        iVar7 = iVar7 + *(int *)(param_2 + 4);
        if ((*(char *)(iVar7 + 0x44) == '\0') || (*(int *)(iVar7 + 0x48) != 0xf)) {
          uVar2 = (*(uint *)(iVar8 + 8) & 7) << 0x10;
          *param_4 = uVar2 | uVar1 | uVar5 | uVar4 & 0xfff80018 | 1;
          uVar3 = (*(uint *)(iVar8 + 8) & 7) << 0x13;
          *param_4 = uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xffc00018 | 1;
          uVar5 = (*(uint *)(iVar8 + 8) & 7) << 0x16 |
                  uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xfe000018 | 1;
          *param_4 = uVar5;
        }
        else {
          uVar5 = uVar1 | uVar5 | uVar4 & 0xfe000018 | 1 | 0x1640000;
          *param_4 = uVar5;
        }
        uVar5 = uVar5 & 0xe1ffffff;
        *param_4 = uVar5;
        goto LAB_00057aa0;
      }
      uVar4 = uVar4 & 0xfffffff8 | 1;
    }
    else {
      iVar7 = *(int *)(iVar8 + 0x24);
      if (iVar7 == 0x87bf) {
        *param_4 = uVar4 & 0xfffffff8 | 2;
        uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5 | uVar4 & 0xffffe018 | 2;
        *param_4 = uVar5;
        goto LAB_00057aa0;
      }
      if (iVar7 != 0x87c0) {
        uVar4 = uVar4 & 0xfffffff8 | 2;
        if (iVar7 != 0x87be) {
          return 0;
        }
        goto LAB_000579dc;
      }
      uVar4 = uVar4 & 0xfffffff8 | 2;
    }
    *param_4 = uVar4;
    uVar5 = (*(uint *)(param_5 * 4 + iVar8 + 0x10) & 0xff) << 5 | uVar4 & 0xffffe01f;
    *param_4 = uVar5;
  }
  else {
    if (uVar5 != 0x87c4) {
      return 0;
    }
    iVar7 = *(int *)(iVar8 + 0x24);
    if (iVar7 == 0x87bf) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
      goto LAB_00057aa0;
    }
    if (iVar7 == 0x87c0) {
      *param_4 = uVar4 & 0xfffffff8;
      uVar5 = (*(uint *)(param_5 * 4 + iVar8 + 0x10) & 0xff) << 5 | uVar4 & 0xffffe018;
      *param_4 = uVar5;
      goto LAB_00057aa0;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar4 = uVar4 & 0xfffffff8;
LAB_000579dc:
    *param_4 = uVar4;
    uVar5 = (*(uint *)(iVar8 + 4) & 0xff) << 5;
    *param_4 = uVar5 | uVar4 & 0xffffe01f;
    uVar1 = (*(uint *)(iVar8 + 8) & 7) << 0xd;
    *param_4 = uVar1 | uVar5 | uVar4 & 0xffff001f;
    uVar2 = (*(uint *)(iVar8 + 8) & 7) << 0x10;
    *param_4 = uVar2 | uVar1 | uVar5 | uVar4 & 0xfff8001f;
    uVar3 = (*(uint *)(iVar8 + 8) & 7) << 0x13;
    *param_4 = uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xffc0001f;
    uVar5 = (*(uint *)(iVar8 + 8) & 7) << 0x16 | uVar3 | uVar2 | uVar1 | uVar5 | uVar4 & 0xe000001f;
    *param_4 = uVar5;
  }
LAB_00057aa0:
  if (*(char *)(param_3 + 6) == '\0') {
    uVar5 = uVar5 & 0x9fffffef;
    *param_4 = uVar5;
  }
  else {
    uVar5 = uVar5 & 0x9fffffff | 0x10;
    *param_4 = uVar5;
  }
  *param_4 = uVar5 & 0x7fffffff;
  return 1;
}

/* FUN_00057af0 @ 0x57af0 (144 bytes) */
int FUN_00057af0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((*param_2 == 2) && (*param_3 == 2)) {
    if (param_2[1] != param_3[1]) {
      iVar1 = *(int *)(param_2[1] * 0x54 + *(int *)(param_1 + 4) + 0x28);
      iVar2 = *(int *)(param_3[1] * 0x54 + *(int *)(param_1 + 4) + 0x28);
      if (((iVar1 == 0x87c1) && (iVar2 == 0x87c1)) ||
         ((iVar1 - 0x87c2U < 2 && (iVar2 - 0x87c2U < 2)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00057b80 @ 0x57b80 (360 bytes) */
int FUN_00057b80(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  bVar1 = true;
  uVar4 = 0;
  iVar2 = 0;
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  while( true ) {
    if (*(uint *)(iVar6 + 0x50) <= uVar5) {
      if (bVar1) {
        *(char *)(param_2 + 4) = (char)uVar4;
        uVar5 = *(uint *)(iVar6 + 0x50);
        iVar2 = (**(code **)(param_1 + 0x10))(uVar5 + 0x10,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (iVar2,*(undefined4 *)(iVar6 + 0x4c),*(int *)(iVar6 + 0x50) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x4c));
        iVar3 = uVar5 * 0x28;
        *(int *)(iVar6 + 0x4c) = iVar2;
        *(int *)(iVar6 + 0x50) = *(int *)(iVar6 + 0x50) + 0x10;
        *(undefined1 *)(iVar2 + iVar3 + 0x10) = 1;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x14) = 4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x18) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x1c) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x20) = uVar4;
        *(undefined4 *)(iVar3 + *(int *)(iVar6 + 0x4c) + 0x24) = uVar4;
        param_2[0x19] = param_2[0x19] + 1;
      }
      return uVar5;
    }
    if (!bVar1) break;
    if (*(char *)(iVar2 + *(int *)(iVar6 + 0x4c) + 0x10) == '\0') {
      uVar4 = 1;
      bVar1 = false;
    }
    else {
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 0x28;
    }
  }
  return uVar5;
}

/* FUN_00057cf0 @ 0x57cf0 (1532 bytes) */
int FUN_00057cf0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined1 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 uStack_64;
  
  piVar5 = param_2 + 7;
  iVar4 = param_3 + 4;
  uVar1 = ((int (*)())FUN_000550e0)(piVar5,iVar4);
  if (0x87bd < uVar1) {
    if (uVar1 < 0x87c0) {
      iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar6 = *(int *)(iVar3 + 0x18);
      if (0x100 < iVar6 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar6 = *(int *)(iVar3 + 0x18);
        if (*(uint *)(iVar3 + 0x20) < iVar6 + 2U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar2,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
          *(undefined4 *)(iVar3 + 0x1c) = uVar2;
          iVar6 = *(int *)(iVar3 + 0x18);
          *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
        }
      }
      uStack_94 = 0;
      uStack_8c = 0;
      uStack_90 = 1;
      uStack_88 = 0;
      uStack_84 = 0;
      uStack_80 = 0;
      iVar3 = iVar6 * 0x10 + *(int *)(iVar3 + 0x1c);
      uStack_98 = 5;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_98,iVar3,0xd,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,param_3 + 0x20,iVar3 + 4,0);
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
      *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
      ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar3 + 0x10,3,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,param_3 + 0x3c,iVar3 + 0x14,0);
      uVar1 = *(uint *)(iVar3 + 0x14);
      if ((uVar1 & 7) != 2) {
        *(undefined1 *)(param_2 + 4) = 0;
        uVar1 = *(uint *)(iVar3 + 0x14);
      }
      *(uint *)(iVar3 + 0x14) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar3 + 0x1c) = uVar1;
      *(uint *)(iVar3 + 0x18) = uVar1;
      return 2;
    }
    if (uVar1 == 0x87c0) {
      iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar3 = *(int *)(iVar6 + 0x18);
      if (0x100 < iVar3 + 7U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar3 = *(int *)(iVar6 + 0x18);
        if (*(uint *)(iVar6 + 0x20) < iVar3 + 7U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar6 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar2,*(undefined4 *)(iVar6 + 0x1c),*(int *)(iVar6 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0x1c));
          *(undefined4 *)(iVar6 + 0x1c) = uVar2;
          iVar3 = *(int *)(iVar6 + 0x18);
          *(int *)(iVar6 + 0x20) = *(int *)(iVar6 + 0x20) + 0x10;
        }
      }
      iVar6 = iVar3 * 0x10 + *(int *)(iVar6 + 0x1c);
      iVar3 = param_3 + 0x3c;
      uVar2 = ((int (*)())FUN_00057b80)(param_1,param_2);
      uStack_98 = 3;
      uStack_90 = 1;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_84 = 0;
      uStack_80 = 0;
      uStack_94 = uVar2;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_98,iVar6,1,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,param_3 + 0x20,iVar6 + 4,0);
      uVar1 = *(uint *)(iVar6 + 4) & 0xfe001fff | 0x16da000;
      *(uint *)(iVar6 + 4) = uVar1;
      *(uint *)(iVar6 + 0xc) = uVar1;
      *(uint *)(iVar6 + 8) = uVar1;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_98,iVar6 + 0x10,2,0,0);
      uStack_7c = 3;
      uStack_64 = 0;
      uStack_68 = 0x87d5;
      uStack_74 = 0x87d5;
      uStack_70 = 0x87d5;
      uStack_6c = 0x87d5;
      uStack_78 = uVar2;
      ((int (*)())FUN_00057340)(param_2,piVar5,&uStack_7c,iVar6 + 0x14,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,param_3 + 0x20,iVar6 + 0x18,0);
      *(undefined4 *)(iVar6 + 0x1c) = *(undefined4 *)(iVar6 + 0x18);
      uStack_98 = 5;
      uStack_90 = 1;
      uStack_94 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_84 = 0;
      uStack_80 = 0;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_98,iVar6 + 0x20,0xd,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,&uStack_7c,iVar6 + 0x24,0);
      *(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)(iVar6 + 0x24);
      *(undefined4 *)(iVar6 + 0x28) = *(undefined4 *)(iVar6 + 0x24);
      ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar6 + 0x30,3,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar5,iVar3,iVar6 + 0x34,0);
      uVar1 = *(uint *)(iVar6 + 0x34);
      if ((uVar1 & 7) != 2) {
        *(undefined1 *)(param_2 + 4) = 0;
        uVar1 = *(uint *)(iVar6 + 0x34);
      }
      *(uint *)(iVar6 + 0x34) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x3c) = uVar1;
      *(uint *)(iVar6 + 0x38) = uVar1;
      ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar6 + 0x40,3,0,1);
      ((int (*)())FUN_00057340)(param_2,piVar5,iVar3,iVar6 + 0x44,1);
      uVar1 = *(uint *)(iVar6 + 0x44);
      *(uint *)(iVar6 + 0x44) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x4c) = uVar1;
      *(uint *)(iVar6 + 0x48) = uVar1;
      ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar6 + 0x50,3,0,2);
      ((int (*)())FUN_00057340)(param_2,piVar5,iVar3,iVar6 + 0x54,2);
      uVar1 = *(uint *)(iVar6 + 0x54);
      *(uint *)(iVar6 + 0x54) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x5c) = uVar1;
      *(uint *)(iVar6 + 0x58) = uVar1;
      ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar6 + 0x60,3,0,3);
      ((int (*)())FUN_00057340)(param_2,piVar5,iVar3,iVar6 + 100,3);
      uVar1 = *(uint *)(iVar6 + 100);
      *(uint *)(iVar6 + 100) = uVar1 & 0x9fffffff | 0x10;
      uVar1 = uVar1 & 0x9e001fff | 0x1248010;
      *(uint *)(iVar6 + 0x6c) = uVar1;
      *(uint *)(iVar6 + 0x68) = uVar1;
      return 7;
    }
  }
  return 0xffffffff;
}

/* FUN_00058300 @ 0x58300 (332 bytes) */
int FUN_00058300(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *(int *)(iVar4 + 0x18);
  if (0x100 < iVar3 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar3 = *(int *)(iVar4 + 0x18);
    if (*(uint *)(iVar4 + 0x20) < iVar3 + 1U) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar4 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar2,*(undefined4 *)(iVar4 + 0x1c),*(int *)(iVar4 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x1c));
      *(undefined4 *)(iVar4 + 0x1c) = uVar2;
      iVar3 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x10;
    }
  }
  iVar3 = iVar3 * 0x10 + *(int *)(iVar4 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar3,3,0,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar3 + 4,0);
  uVar1 = *(uint *)(iVar3 + 4);
  *(uint *)(iVar3 + 4) = uVar1 | 0x1e000000;
  uVar1 = uVar1 & 0xe0001fff | 0x1248000;
  *(uint *)(iVar3 + 0xc) = uVar1;
  *(uint *)(iVar3 + 8) = uVar1;
  return 1;
}

/* FUN_00058450 @ 0x58450 (872 bytes) */
int FUN_00058450(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  piVar7 = param_2 + 7;
  iVar4 = param_3 + 4;
  iVar5 = param_3 + 0x20;
  param_3 = param_3 + 0x3c;
  ((int (*)())FUN_000550e0)(piVar7,iVar4);
  iVar2 = ((int (*)())FUN_00057af0)(piVar7,iVar5,param_3);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar6 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar6 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar6 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar6 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar6 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar6 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar2,1,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar7,iVar5,iVar2 + 4,0);
    *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfe3fffff | 0x1000000;
    ((int (*)())FUN_00057340)(param_2,piVar7,param_3,iVar2 + 8,0);
    uVar3 = 1;
    uVar1 = *(uint *)(iVar2 + 8) & 0xfe3fffff | 0x1000000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar6 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar6 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar6 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar6 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar6 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar6 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar7,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,iVar4,iVar2 + 0x10,1,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87dd;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar7,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar7,param_3,iVar2 + 0x18,0);
    uVar3 = 2;
    uVar1 = *(uint *)(iVar2 + 0x18) & 0xfe3fffff | 0x1000000;
    *(uint *)(iVar2 + 0x1c) = uVar1;
    *(uint *)(iVar2 + 0x18) = uVar1;
  }
  return uVar3;
}

/* FUN_000587d0 @ 0x587d0 (824 bytes) */
int FUN_000587d0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,1,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,1,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_00058b10 @ 0x58b10 (824 bytes) */
int FUN_00058b10(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,2,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,2,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_00058e50 @ 0x58e50 (824 bytes) */
int FUN_00058e50(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,3,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_00059190 @ 0x59190 (2512 bytes) */
int FUN_00059190(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  
  piVar8 = param_2 + 7;
  iVar6 = param_3 + 0x20;
  puVar5 = (undefined4 *)(param_3 + 0x3c);
  iVar2 = ((int (*)())FUN_00057af0)(piVar8,iVar6,puVar5);
  if (iVar2 == 0) {
    iVar4 = param_3 + 0x58;
    iVar2 = ((int (*)())FUN_00057af0)(piVar8,iVar6,iVar4);
    if ((iVar2 == 0) && (iVar2 = ((int (*)())FUN_00057af0)(piVar8,puVar5,iVar4), iVar2 == 0)) {
      iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar7 = *(int *)(iVar2 + 0x18);
      if (0x100 < iVar7 + 1U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar7 = *(int *)(iVar2 + 0x18);
        if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
          *(undefined4 *)(iVar2 + 0x1c) = uVar3;
          iVar7 = *(int *)(iVar2 + 0x18);
          *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
        }
      }
      iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
      ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,4,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar6,iVar2 + 4,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,puVar5,iVar2 + 8,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar4,iVar2 + 0xc,0);
      uVar3 = 1;
    }
    else {
      iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar7 = *(int *)(iVar2 + 0x18);
      if (0x100 < iVar7 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar7 = *(int *)(iVar2 + 0x18);
        if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
          *(undefined4 *)(iVar2 + 0x1c) = uVar3;
          iVar7 = *(int *)(iVar2 + 0x18);
          *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
        }
      }
      iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
      uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
      uStack_80 = 3;
      uStack_68 = 0;
      uStack_6c = 1;
      uStack_78 = 1;
      uStack_74 = 1;
      uStack_70 = 1;
      uStack_7c = uVar3;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_80,iVar2,2,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar6,iVar2 + 4,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,puVar5,iVar2 + 8,0);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
      ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,3,0,0);
      uStack_64 = 3;
      uStack_4c = 0;
      uStack_5c = 0x87d5;
      uStack_58 = 0x87d6;
      uStack_54 = 0x87d7;
      uStack_50 = 0x87d8;
      uStack_60 = uVar3;
      ((int (*)())FUN_00057340)(param_2,piVar8,&uStack_64,iVar2 + 0x14,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar4,iVar2 + 0x18,0);
      uVar3 = 2;
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
    }
  }
  else {
    iVar4 = param_3 + 0x58;
    iVar2 = ((int (*)())FUN_00057af0)(piVar8,iVar6,iVar4);
    if ((iVar2 == 0) || (iVar2 = ((int (*)())FUN_00057af0)(piVar8,puVar5,iVar4), iVar2 == 0)) {
      iVar2 = ((int (*)())FUN_00057af0)(piVar8,puVar5,iVar4);
      if (iVar2 == 0) {
        iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        iVar7 = *(int *)(iVar2 + 0x18);
        if (0x100 < iVar7 + 2U) {
          *(undefined1 *)(param_2 + 4) = 0;
          iVar7 = *(int *)(iVar2 + 0x18);
          if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
            uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
            (**(code **)(((unsigned char *)0x00001344) + param_1))
                      (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
            *(undefined4 *)(iVar2 + 0x1c) = uVar3;
            iVar7 = *(int *)(iVar2 + 0x18);
            *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
          }
        }
        iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
        uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
        uStack_64 = 3;
        uStack_4c = 0;
        uStack_50 = 1;
        uStack_5c = 1;
        uStack_58 = 1;
        uStack_54 = 1;
        uStack_60 = uVar3;
        ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_64,iVar2,3,0,0);
        ((int (*)())FUN_00057340)(param_2,piVar8,iVar6,iVar2 + 4,0);
        uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
        *(uint *)(iVar2 + 0xc) = uVar1;
        *(uint *)(iVar2 + 8) = uVar1;
        ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,4,0,0);
        uStack_80 = 3;
        uStack_68 = 0;
        uStack_78 = 0x87d5;
        uStack_74 = 0x87d6;
        uStack_70 = 0x87d7;
        uStack_6c = 0x87d8;
        uStack_7c = uVar3;
        ((int (*)())FUN_00057340)(param_2,piVar8,&uStack_80,iVar2 + 0x14,0);
      }
      else {
        iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        iVar7 = *(int *)(iVar2 + 0x18);
        if (0x100 < iVar7 + 2U) {
          *(undefined1 *)(param_2 + 4) = 0;
          iVar7 = *(int *)(iVar2 + 0x18);
          if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
            uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
            (**(code **)(((unsigned char *)0x00001344) + param_1))
                      (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
            *(undefined4 *)(iVar2 + 0x1c) = uVar3;
            iVar7 = *(int *)(iVar2 + 0x18);
            *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
          }
        }
        iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
        uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
        uStack_b8 = 3;
        uStack_a0 = 0;
        uStack_a4 = 1;
        uStack_b0 = 1;
        uStack_ac = 1;
        uStack_a8 = 1;
        uStack_b4 = uVar3;
        ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_b8,iVar2,3,0,0);
        ((int (*)())FUN_00057340)(param_2,piVar8,puVar5,iVar2 + 4,0);
        uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
        *(uint *)(iVar2 + 0xc) = uVar1;
        *(uint *)(iVar2 + 8) = uVar1;
        ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,4,0,0);
        ((int (*)())FUN_00057340)(param_2,piVar8,iVar6,iVar2 + 0x14,0);
        uStack_9c = 3;
        uStack_84 = 0;
        uStack_94 = 0x87d5;
        uStack_90 = 0x87d6;
        uStack_8c = 0x87d7;
        uStack_88 = 0x87d8;
        puVar5 = &uStack_9c;
        uStack_98 = uVar3;
      }
      ((int (*)())FUN_00057340)(param_2,piVar8,puVar5,iVar2 + 0x18,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar4,iVar2 + 0x1c,0);
      uVar3 = 2;
    }
    else {
      iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
      iVar7 = *(int *)(iVar2 + 0x18);
      if (0x100 < iVar7 + 3U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar7 = *(int *)(iVar2 + 0x18);
        if (*(uint *)(iVar2 + 0x20) < iVar7 + 3U) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
          *(undefined4 *)(iVar2 + 0x1c) = uVar3;
          iVar7 = *(int *)(iVar2 + 0x18);
          *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
        }
      }
      iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
      uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
      uStack_b8 = 3;
      uStack_a0 = 0;
      uStack_a4 = 1;
      uStack_b0 = 1;
      uStack_ac = 1;
      uStack_a8 = 1;
      uStack_b4 = uVar3;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_b8,iVar2,3,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar6,iVar2 + 4,0);
      uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
      *(uint *)(iVar2 + 0xc) = uVar1;
      *(uint *)(iVar2 + 8) = uVar1;
      ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_b8,iVar2 + 0x10,2,0,0);
      uStack_9c = 3;
      uStack_84 = 0;
      uStack_90 = 0x87d6;
      uStack_94 = 0x87d5;
      uStack_8c = 0x87d7;
      uStack_88 = 0x87d8;
      uStack_98 = uVar3;
      ((int (*)())FUN_00057340)(param_2,piVar8,&uStack_9c,iVar2 + 0x14,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,puVar5,iVar2 + 0x18,0);
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
      ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x20,3,0,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,&uStack_9c,iVar2 + 0x24,0);
      ((int (*)())FUN_00057340)(param_2,piVar8,iVar4,iVar2 + 0x28,0);
      uVar3 = 3;
      *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar2 + 0x28);
    }
  }
  return uVar3;
}

/* FUN_00059b80 @ 0x59b80 (304 bytes) */
int FUN_00059b80(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,6,0,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_00059cb0 @ 0x59cb0 (824 bytes) */
int FUN_00059cb0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,7,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_60 = 0;
    local_64 = 1;
    local_70 = 1;
    local_6c = 1;
    local_68 = 1;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,7,0,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_00059ff0 @ 0x59ff0 (824 bytes) */
int FUN_00059ff0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,8,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,8,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005a330 @ 0x5a330 (824 bytes) */
int FUN_0005a330(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,9,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,9,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005a670 @ 0x5a670 (824 bytes) */
int FUN_0005a670(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,10,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    uStack_78 = 3;
    uStack_60 = 0;
    uStack_64 = 1;
    uStack_70 = 1;
    uStack_6c = 1;
    uStack_68 = 1;
    uStack_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,10,0,0);
    uStack_5c = 3;
    uStack_44 = 0;
    uStack_54 = 0x87d5;
    uStack_50 = 0x87d6;
    uStack_4c = 0x87d7;
    uStack_48 = 0x87d8;
    uStack_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005a9b0 @ 0x5a9b0 (1112 bytes) */
int FUN_0005a9b0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  
  iVar5 = param_3 + 0x20;
  piVar6 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  uVar2 = ((int (*)())FUN_00057b80)();
  iVar3 = ((int (*)())FUN_00057af0)(piVar6,iVar5,iVar4);
  uStack_84 = uVar2;
  uStack_68 = uVar2;
  if (iVar3 == 0) {
    iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar3 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar3 + 0x18);
      if (*(uint *)(iVar3 + 0x20) < iVar7 + 2U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0x1c) = uVar2;
        iVar7 = *(int *)(iVar3 + 0x18);
        *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      }
    }
    uStack_74 = 1;
    uStack_80 = 1;
    uStack_7c = 1;
    uStack_78 = 1;
    uStack_88 = 3;
    iVar3 = iVar7 * 0x10 + *(int *)(iVar3 + 0x1c);
    uStack_70 = 0;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_88,iVar3,7,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar3 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar3 + 8,0);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 8);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar3 + 0x10,8,0,0);
    uStack_6c = 3;
    uStack_54 = 0;
    uStack_64 = 0x87d5;
    uStack_60 = 0x87d6;
    uStack_5c = 0x87d7;
    uStack_58 = 0x87d8;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_6c,iVar3 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,param_3 + 0x58,iVar3 + 0x18,0);
    uVar2 = 2;
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar3 + 0x18);
  }
  else {
    iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar3 + 0x18);
    if (0x100 < iVar7 + 3U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar3 + 0x18);
      if (*(uint *)(iVar3 + 0x20) < iVar7 + 3U) {
        uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
        *(undefined4 *)(iVar3 + 0x1c) = uVar2;
        iVar7 = *(int *)(iVar3 + 0x18);
        *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      }
    }
    uStack_74 = 1;
    uStack_80 = 1;
    uStack_7c = 1;
    uStack_78 = 1;
    uStack_88 = 3;
    iVar3 = iVar7 * 0x10 + *(int *)(iVar3 + 0x1c);
    uStack_70 = 0;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_88,iVar3,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar5,iVar3 + 4,0);
    uVar1 = *(uint *)(iVar3 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar3 + 0xc) = uVar1;
    *(uint *)(iVar3 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_88,iVar3 + 0x10,7,0,0);
    uStack_6c = 3;
    uStack_54 = 0;
    uStack_60 = 0x87d6;
    uStack_64 = 0x87d5;
    uStack_5c = 0x87d7;
    uStack_58 = 0x87d8;
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_6c,iVar3 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,iVar4,iVar3 + 0x18,0);
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar3 + 0x18);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar3 + 0x20,8,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,&uStack_6c,iVar3 + 0x24,0);
    ((int (*)())FUN_00057340)(param_2,piVar6,param_3 + 0x58,iVar3 + 0x28,0);
    uVar2 = 3;
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(iVar3 + 0x28);
  }
  return uVar2;
}

/* FUN_0005ae10 @ 0x5ae10 (512 bytes) */
int FUN_0005ae10(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar4 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar4 + 2U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar4 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar4 + 2U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar4 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  piVar2 = param_2 + 7;
  iVar3 = iVar4 * 0x10 + *(int *)(iVar3 + 0x1c);
  uVar1 = ((int (*)())FUN_00057b80)(param_1,param_2);
  uStack_78 = 3;
  uStack_60 = 0;
  uStack_64 = 1;
  uStack_70 = 1;
  uStack_6c = 1;
  uStack_68 = 1;
  uStack_74 = uVar1;
  ((int (*)())FUN_00056f20)(param_1,param_2,&uStack_78,iVar3,6,0,0);
  ((int (*)())FUN_00057340)(param_2,piVar2,param_3 + 0x20,iVar3 + 4,0);
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar3 + 0x10,3,0,0);
  ((int (*)())FUN_00057340)(param_2,piVar2,param_3 + 0x20,iVar3 + 0x14,0);
  uStack_5c = 3;
  uStack_44 = 0;
  uStack_54 = 0x87d9;
  uStack_50 = 0x87da;
  uStack_4c = 0x87db;
  uStack_48 = 0x87dc;
  uStack_58 = uVar1;
  ((int (*)())FUN_00057340)(param_2,piVar2,&uStack_5c,iVar3 + 0x18,0);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar3 + 0x18);
  return 2;
}

/* FUN_0005b010 @ 0x5b010 (932 bytes) */
int FUN_0005b010(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack00000020;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  
  iVar7 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar8 = *(int *)(iVar7 + 0x18);
  iStack00000020 = param_3;
  if (0x100 < iVar8 + 4U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar8 = *(int *)(iVar7 + 0x18);
    if (*(uint *)(iVar7 + 0x20) < iVar8 + 4U) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar7 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar3,*(undefined4 *)(iVar7 + 0x1c),*(int *)(iVar7 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x1c));
      *(undefined4 *)(iVar7 + 0x1c) = uVar3;
      iVar8 = *(int *)(iVar7 + 0x18);
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + 0x10;
    }
  }
  piVar5 = param_2 + 7;
  iVar9 = iVar8 * 0x10 + *(int *)(iVar7 + 0x1c);
  iVar8 = ((int (*)())FUN_00057b80)(param_1,param_2);
  iVar6 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar4 = iStack00000020 + 0x20;
  iVar7 = iVar8 * 0x28 + *(int *)(iVar6 + 0x4c);
  uVar1 = *(undefined1 *)(iVar7 + 0x10);
  *(undefined1 *)(iVar7 + 0x10) = 1;
  uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
  *(undefined1 *)(iVar8 * 0x28 + *(int *)(iVar6 + 0x4c) + 0x10) = uVar1;
  local_98 = 3;
  local_90 = 1;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_94 = iVar8;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9,0xb,1,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar9 + 4,0);
  uVar2 = *(uint *)(iVar9 + 4) & 0xfe001fff | 0x1f6da000;
  *(uint *)(iVar9 + 0xc) = uVar2;
  *(uint *)(iVar9 + 4) = uVar2;
  *(uint *)(iVar9 + 8) = uVar2;
  local_98 = 3;
  local_90 = 1;
  local_8c = 1;
  local_88 = 1;
  local_84 = 1;
  local_80 = 0;
  local_94 = iVar8;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9 + 0x10,3,0,0);
  local_7c = 3;
  local_74 = 0x87d5;
  local_70 = 0x87d5;
  local_6c = 0x87d5;
  local_68 = 0x87d5;
  local_64 = 0;
  local_78 = iVar8;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x14,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar9 + 0x18,0);
  *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar9 + 0x18);
  local_84 = 1;
  local_98 = 3;
  local_90 = 1;
  local_8c = 1;
  local_88 = 1;
  local_80 = 0;
  local_94 = uVar3;
  ((int (*)())FUN_00056f20)(param_1,param_2,&local_98,iVar9 + 0x20,6,0,0);
  local_74 = 0x87d5;
  local_7c = 3;
  local_64 = 0;
  local_70 = 0x87d6;
  local_6c = 0x87d7;
  local_68 = 0x87d8;
  local_78 = iVar8;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x24,0);
  *(undefined4 *)(iVar9 + 0x2c) = *(undefined4 *)(iVar9 + 0x24);
  *(undefined4 *)(iVar9 + 0x28) = *(undefined4 *)(iVar9 + 0x24);
  ((int (*)())FUN_00056f20)(param_1,param_2,iStack00000020 + 4,iVar9 + 0x30,3,0,0);
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x34,0);
  local_7c = 3;
  local_64 = 0;
  local_74 = 0x87d9;
  local_70 = 0x87da;
  local_6c = 0x87db;
  local_68 = 0x87dc;
  local_78 = uVar3;
  ((int (*)())FUN_00057340)(param_2,piVar5,&local_7c,iVar9 + 0x38,0);
  *(undefined4 *)(iVar9 + 0x3c) = *(undefined4 *)(iVar9 + 0x38);
  return 4;
}

/* FUN_0005b3c0 @ 0x5b3c0 (304 bytes) */
int FUN_0005b3c0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,0xb,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_0005b4f0 @ 0x5b4f0 (304 bytes) */
int FUN_0005b4f0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,0xc,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_0005b620 @ 0x5b620 (824 bytes) */
int FUN_0005b620(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44;
  
  iVar6 = param_3 + 0x20;
  piVar5 = param_2 + 7;
  iVar4 = param_3 + 0x3c;
  iVar2 = ((int (*)())FUN_00057af0)(piVar5,iVar6,iVar4);
  if (iVar2 == 0) {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 1U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 1U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,5,1,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar2 + 4,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar2 + 8,0);
    uVar3 = 1;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 8);
  }
  else {
    iVar2 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    iVar7 = *(int *)(iVar2 + 0x18);
    if (0x100 < iVar7 + 2U) {
      *(undefined1 *)(param_2 + 4) = 0;
      iVar7 = *(int *)(iVar2 + 0x18);
      if (*(uint *)(iVar2 + 0x20) < iVar7 + 2U) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar2 + 0x20) * 0x10 + 0x100);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar3,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x20) << 4);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = uVar3;
        iVar7 = *(int *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + 0x10;
      }
    }
    iVar2 = iVar7 * 0x10 + *(int *)(iVar2 + 0x1c);
    uVar3 = ((int (*)())FUN_00057b80)(param_1,param_2);
    local_78 = 3;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    local_64 = 1;
    local_60 = 0;
    local_74 = uVar3;
    ((int (*)())FUN_00056f20)(param_1,param_2,&local_78,iVar2,3,0,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar6,iVar2 + 4,0);
    uVar1 = *(uint *)(iVar2 + 4) & 0xfe001fff | 0x1248000;
    *(uint *)(iVar2 + 0xc) = uVar1;
    *(uint *)(iVar2 + 8) = uVar1;
    ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2 + 0x10,5,1,0);
    local_5c = 3;
    local_44 = 0;
    local_54 = 0x87d5;
    local_50 = 0x87d6;
    local_4c = 0x87d7;
    local_48 = 0x87d8;
    local_58 = uVar3;
    ((int (*)())FUN_00057340)(param_2,piVar5,&local_5c,iVar2 + 0x14,0);
    ((int (*)())FUN_00057340)(param_2,piVar5,iVar4,iVar2 + 0x18,0);
    uVar3 = 2;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
  }
  return uVar3;
}

/* FUN_0005b960 @ 0x5b960 (304 bytes) */
int FUN_0005b960(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,6,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

/* FUN_0005ba90 @ 0x5ba90 (304 bytes) */
int FUN_0005ba90(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      iVar2 = *(int *)(iVar3 + 0x18);
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
    }
  }
  iVar2 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00056f20)(param_1,param_2,param_3 + 4,iVar2,8,1,0);
  ((int (*)())FUN_00057340)(param_2,param_2 + 7,param_3 + 0x20,iVar2 + 4,0);
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 4);
  *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 4);
  return 1;
}

