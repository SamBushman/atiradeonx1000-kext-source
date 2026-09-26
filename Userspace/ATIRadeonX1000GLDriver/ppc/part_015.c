#include "decls.h"

/* FUN_000a1090 @ 0xa1090 (200 bytes) */
int FUN_000a1090(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0x10;
  iVar3 = param_1;
  do {
    uVar1 = 0;
    if (*(char *)(param_2 + iVar4) != '\0') {
      uVar1 = 2;
      if ((*param_3 != 1) && (uVar1 = 1, *param_3 != 2)) {
        uVar1 = 8;
      }
    }
    *(undefined4 *)(iVar3 + 0x48) = uVar1;
    iVar4 = iVar4 + 1;
    param_3 = param_3 + 1;
    iVar3 = iVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar3 = *(int *)(((unsigned char *)0x00001154) + param_1);
  if (*(int *)(iVar3 + 4) != 0) {
    uVar2 = 0;
    iVar4 = 0;
    do {
      iVar5 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar4 + *(int *)(iVar3 + 0x88) + 0x70));
      if (iVar5 != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar5) = 1;
        iVar3 = *(int *)(((unsigned char *)0x00001154) + param_1);
      }
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x78;
    } while (uVar2 < *(uint *)(iVar3 + 4));
  }
  *(undefined4 *)(param_1 + 0x27bc) = 0;
  return;
}

/* FUN_000a1160 @ 0xa1160 (48 bytes) */
int FUN_000a1160(param_1)
  int param_1;
{
  if (((param_1 != -0x1134) && (*(int *)(((unsigned char *)0x00001144) + param_1) != 0)) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001144) + param_1) + 0x74) != '\0')) {
    return ((unsigned char *)0x00001135)[param_1];
  }
  return 0;
}

/* FUN_000a11a0 @ 0xa11a0 (64 bytes) */
int FUN_000a11a0(param_1)
  int param_1;
{
  int iVar1;
  
  if (((param_1 != -0x1134) && (iVar1 = *(int *)(((unsigned char *)0x00001144) + param_1), iVar1 != 0)) &&
     (*(char *)(iVar1 + 0x74) != '\0')) {
    if (*(char *)(iVar1 + 0x6c) != '\0') {
      return 3;
    }
    return 1;
  }
  return 0;
}

/* FUN_000a11f0 @ 0xa11f0 (192 bytes) */
int FUN_000a11f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  ((unsigned char *)0x00001135)[param_1] = 0;
  if (param_3 < 1) {
    return;
  }
  uVar1 = *(ushort *)(((unsigned char *)0x00001148) + param_1);
  iVar4 = 0;
  do {
    uVar6 = (uint)uVar1;
    if (uVar1 != 0) {
      iVar5 = 0;
      if ((uVar1 == 0) || (uVar6 == 0x80000000)) {
        uVar6 = 1;
      }
      do {
        iVar2 = (iVar5 + iVar4 * (uint)uVar1) * 0xc;
        if ((*(char *)(iVar2 + *(int *)(param_2 + 0xc)) != '\0') &&
           (uVar3 = *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 8) - 0x84c0, uVar3 < 8)) {
          ((unsigned char *)0x00001135)[param_1] = (byte)(1 << (uVar3 & 0x3f)) | ((unsigned char *)0x00001135)[param_1];
        }
        iVar5 = iVar5 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    iVar4 = iVar4 + 1;
  } while (param_3 != iVar4);
  return;
}

/* FUN_000a12b0 @ 0xa12b0 (52 bytes) */
int FUN_000a12b0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_2 != 0) && (((unsigned char *)0x00001134)[param_1] == '\0')) {
    iVar1 = **(int **)(((unsigned char *)0x00001154) + param_1);
    **(int **)(((unsigned char *)0x00001154) + param_1) = param_2 + iVar1;
    return iVar1;
  }
  return 0;
}

/* FUN_000a12f0 @ 0xa12f0 (612 bytes) */
int FUN_000a12f0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar7 = *(int *)(((unsigned char *)0x00001154) + param_1);
    uVar6 = 0;
    iVar4 = 0;
    uVar5 = *(uint *)(iVar7 + 4);
    bVar1 = true;
    iVar3 = 0;
    while (uVar6 < uVar5) {
      if (!bVar1) goto LAB_000a1378;
      if (param_2 == *(int *)(iVar3 + *(int *)(iVar7 + 0x88))) {
        bVar1 = false;
      }
      else {
        iVar4 = iVar4 + 0x78;
        uVar6 = uVar6 + 1;
        iVar3 = iVar4;
      }
    }
    if (bVar1) {
      if ((uVar5 & 7) == 0) {
        uVar2 = (**(code **)(param_1 + 0x10))(1,uVar5 * 0x78 + 0x3c0);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar7 + 0x88),*(int *)(iVar7 + 4) * 0x78);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x88));
        *(undefined4 *)(iVar7 + 0x88) = uVar2;
        uVar5 = *(uint *)(iVar7 + 4);
      }
      ((int (*)())FUN_000a2920)(param_1,uVar5 * 0x78 + *(int *)(iVar7 + 0x88));
      *(int *)(*(int *)(iVar7 + 4) * 0x78 + *(int *)(iVar7 + 0x88)) = param_2;
      *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
      *(uint *)(((unsigned char *)0x00001140) + param_1) = uVar6;
      uVar5 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x44) = uVar5 & 0xffffbfff;
      if ((uVar5 & 0x32000) == 0x30000) {
        *(uint *)(param_1 + 0x44) = uVar5 & 0xfffebfff;
      }
      ((unsigned char *)0x00001136)[param_1] = 1;
    }
    else {
LAB_000a1378:
      iVar4 = *(int *)(iVar7 + 0x88);
      if (uVar6 != *(uint *)(((unsigned char *)0x00001140) + param_1)) {
        ((unsigned char *)0x00001136)[param_1] = 1;
      }
      *(uint *)(((unsigned char *)0x00001140) + param_1) = uVar6;
      if (*(char *)(iVar3 + iVar4 + 0x6c) == '\0') {
        uVar5 = *(uint *)(param_1 + 0x44);
        *(uint *)(param_1 + 0x44) = uVar5 & 0xffffbfff;
        if ((uVar5 & 0x32000) == 0x30000) {
          *(uint *)(param_1 + 0x44) = uVar5 & 0xfffebfff;
        }
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x44);
        uVar6 = uVar5 >> 1 & 0x4000 | uVar5 & 0xffffbfff;
        *(uint *)(param_1 + 0x44) = uVar6;
        if ((uVar5 & 0x32000) == 0x20000) {
          *(uint *)(param_1 + 0x44) = uVar6 | 0x10000;
        }
      }
    }
    iVar3 = iVar3 + *(int *)(iVar7 + 0x88);
    *(int *)(((unsigned char *)0x00001144) + param_1) = iVar3;
    ((int (*)())FUN_000a11f0)(param_1,iVar3,*(undefined4 *)(iVar3 + 4));
    if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* FUN_000a1570 @ 0xa1570 (312 bytes) */
int FUN_000a1570(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((((unsigned char *)0x00001134)[param_1] == '\0') && (param_2 != 0)) {
    iVar4 = *(int *)(((unsigned char *)0x00001154) + param_1);
    if (param_2 == **(int **)(((unsigned char *)0x00001144) + param_1)) {
      ((int (*)())FUN_000a12f0)(param_1,0);
    }
    uVar3 = 0;
    iVar2 = 0;
    bVar1 = true;
    while (uVar3 < *(uint *)(iVar4 + 4)) {
      if (!bVar1) goto LAB_000a161c;
      if (param_2 == *(int *)(iVar2 + *(int *)(iVar4 + 0x88))) {
        bVar1 = false;
      }
      else {
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 0x78;
      }
    }
    if (!bVar1) {
LAB_000a161c:
      ((int (*)())FUN_000a2bb0)(param_1,uVar3 * 0x78 + *(int *)(iVar4 + 0x88));
      iVar2 = uVar3 * 0x78 + *(int *)(iVar4 + 0x88);
      _memmove(iVar2,iVar2 + 0x78,(*(int *)(iVar4 + 4) - uVar3) * 0x78 + -0x78);
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + -1;
      if (uVar3 < *(uint *)(((unsigned char *)0x00001140) + param_1)) {
        iVar2 = *(uint *)(((unsigned char *)0x00001140) + param_1) - 1;
        *(int *)(((unsigned char *)0x00001140) + param_1) = iVar2;
        *(int *)(((unsigned char *)0x00001144) + param_1) = iVar2 * 0x78 + *(int *)(iVar4 + 0x88);
      }
    }
  }
  return;
}

/* FUN_000a16b0 @ 0xa16b0 (148 bytes) */
int FUN_000a16b0(param_1)
  int param_1;
{
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    ((unsigned char *)0x00001134)[param_1] = 1;
    ((int (*)())FUN_000a2bb0)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1));
    ((int (*)())FUN_000a2920)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1));
    if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
    }
  }
  return;
}

/* FUN_000a1750 @ 0xa1750 (772 bytes) */
int FUN_000a1750(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  iVar13 = *(int *)(((unsigned char *)0x00001144) + param_1);
  if ((byte)((unsigned char *)0x00001138)[param_1] == 1) {
    bVar2 = false;
    iVar12 = 0;
    iVar7 = 0;
    iVar6 = 0;
    iVar11 = 0;
    iVar5 = 0;
    iVar3 = 0;
    iVar4 = 0;
    bVar1 = 0 < **(int **)(iVar13 + 0x14);
    while ((bVar1 || (iVar7 < **(int **)(iVar13 + 0x20)))) {
      if ((iVar6 < *(int *)(iVar13 + 0x18)) &&
         ((bVar1 && (iVar8 = iVar4 + *(int *)(iVar13 + 0x10), iVar5 == *(int *)(iVar8 + 0x44))))) {
        if (((*(int *)(iVar8 + 0x14) == 0x8577) ||
            (((*(int *)(iVar8 + 0x14) == 0x896d || (*(int *)(iVar8 + 0x24) == 0x8577)) ||
             (*(int *)(iVar8 + 0x24) == 0x896d)))) ||
           ((*(int *)(iVar8 + 0x34) == 0x8577 || (*(int *)(iVar8 + 0x34) == 0x896d)))) {
          bVar2 = true;
        }
        iVar12 = iVar12 + 1;
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x4c;
        iVar5 = iVar5 + 1;
        bVar1 = iVar12 < **(int **)(iVar13 + 0x14);
      }
      if (((iVar11 < *(int *)(iVar13 + 0x24)) && (iVar7 < **(int **)(iVar13 + 0x20))) &&
         (iVar8 = iVar3 + *(int *)(iVar13 + 0x1c), iVar5 == *(int *)(iVar8 + 0x44))) {
        if (((((*(int *)(iVar8 + 0x14) == 0x8577) || (*(int *)(iVar8 + 0x14) == 0x896d)) ||
             (*(int *)(iVar8 + 0x24) == 0x8577)) ||
            ((*(int *)(iVar8 + 0x24) == 0x896d || (*(int *)(iVar8 + 0x34) == 0x8577)))) ||
           (*(int *)(iVar8 + 0x34) == 0x896d)) {
          bVar2 = true;
        }
        iVar11 = iVar11 + 1;
        iVar3 = iVar3 + 0x4c;
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 1;
      }
    }
    if (bVar2) {
      *(undefined4 *)(iVar13 + 4) = 1;
      ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
      goto LAB_000a1914;
    }
  }
  *(uint *)(iVar13 + 4) = (byte)((unsigned char *)0x00001138)[param_1] + 1;
LAB_000a1914:
  ((int (*)())FUN_000a11f0)(param_1,*(int *)(((unsigned char *)0x00001144) + param_1),
               *(undefined4 *)(*(int *)(((unsigned char *)0x00001144) + param_1) + 4));
  ((unsigned char *)0x00001136)[param_1] = 1;
  ((unsigned char *)0x00001134)[param_1] = 0;
  iVar3 = (**(code **)(((unsigned char *)0x00001164) + param_1))(param_1);
  if (iVar3 == 0) {
    ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  }
  ((unsigned char *)0x00001137)[param_1] = 0;
  ((unsigned char *)0x00001138)[param_1] = 0;
  if (*(char *)(iVar13 + 0x6c) == '\0') {
    uVar9 = *(uint *)(param_1 + 0x44);
    uVar10 = uVar9 & 0xffffbfff;
    *(uint *)(param_1 + 0x44) = uVar10;
    if ((uVar9 & 0x32000) == 0x30000) {
      uVar10 = uVar9 & 0xfffebfff;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x44) = uVar10;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
    }
  }
  else {
    uVar9 = *(uint *)(param_1 + 0x44);
    uVar10 = uVar9 >> 1 & 0x4000 | uVar9 & 0xffffbfff;
    *(uint *)(param_1 + 0x44) = uVar10;
    if ((uVar9 & 0x32000) == 0x20000) {
      uVar10 = uVar10 | 0x10000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x44) = uVar10;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
    }
  }
  if ((uVar10 & 0x22000) == 0x20000) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  return;
}

/* FUN_000a1a60 @ 0xa1a60 (328 bytes) */
int FUN_000a1a60(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  uVar2 = (uint)(byte)((unsigned char *)0x00001138)[param_1] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[param_1] >> 0x1f);
  if (((uVar2 < (byte)((unsigned char *)0x00001150)[param_1]) && (param_2 - 0x8921U < 6)) &&
     (param_4 - 0x8976U < 4)) {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[param_1] < (int)(param_3 - 0x84c0U)) goto LAB_000a1b60;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar2 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a1b60;
    iVar1 = ((int (*)())FUN_000a2d60)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),uVar2,param_2,param_3,0,
                         param_4);
    if (iVar1 != 0) {
      if (((unsigned char *)0x00001137)[param_1] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[param_1] = 0;
      ((unsigned char *)0x00001138)[param_1] = ((unsigned char *)0x00001138)[param_1] + '\x01';
      return;
    }
  }
LAB_000a1b60:
  ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  return;
}

/* FUN_000a1bc0 @ 0xa1bc0 (328 bytes) */
int FUN_000a1bc0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  uVar2 = (uint)(byte)((unsigned char *)0x00001138)[param_1] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[param_1] >> 0x1f);
  if (((uVar2 < (byte)((unsigned char *)0x00001150)[param_1]) && (param_2 - 0x8921U < 6)) &&
     (param_4 - 0x8976U < 4)) {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[param_1] < (int)(param_3 - 0x84c0U)) goto LAB_000a1cc0;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar2 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a1cc0;
    iVar1 = ((int (*)())FUN_000a2d60)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),uVar2,param_2,param_3,1,
                         param_4);
    if (iVar1 != 0) {
      if (((unsigned char *)0x00001137)[param_1] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[param_1] = 0;
      ((unsigned char *)0x00001138)[param_1] = ((unsigned char *)0x00001138)[param_1] + '\x01';
      return;
    }
  }
LAB_000a1cc0:
  ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  return;
}

/* FUN_000a1d20 @ 0xa1d20 (156 bytes) */
int FUN_000a1d20(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,0,0,0,0,0,0);
  }
  return;
}

/* FUN_000a1dc0 @ 0xa1dc0 (168 bytes) */
int FUN_000a1dc0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,param_9,param_10,param_11,0,0,0);
  }
  return;
}

/* FUN_000a1e70 @ 0xa1e70 (176 bytes) */
int FUN_000a1e70(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,param_9,param_10,param_11,param_12,param_13,param_14);
  }
  return;
}

/* FUN_000a1f20 @ 0xa1f20 (144 bytes) */
int FUN_000a1f20(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,0,0,0,0,0,0);
  }
  return;
}

/* FUN_000a1fb0 @ 0xa1fb0 (160 bytes) */
int FUN_000a1fb0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,param_9,param_10,0,0,0);
  }
  return;
}

/* FUN_000a2050 @ 0xa2050 (168 bytes) */
int FUN_000a2050(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),
                 (uint)(byte)((unsigned char *)0x00001138)[param_1],param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,param_9,param_10,param_11,param_12,param_13);
  }
  return;
}

/* FUN_000a2100 @ 0xa2100 (192 bytes) */
int FUN_000a2100(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  if (7 < param_2 - 0x8941U) {
    ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
    return;
  }
  ((int (*)())FUN_000a3490)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),param_2,param_3,
               (uint)(byte)((unsigned char *)0x00001134)[param_1]);
  if (((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) &&
     ((*(uint *)(param_1 + 0x38) & 0x2000) != 0)) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
  }
  return;
}

/* FUN_000a21d0 @ 0xa21d0 (100 bytes) */
int FUN_000a21d0(param_1)
  int param_1;
{
  (**(code **)(((unsigned char *)0x0000115c) + param_1))(param_1);
  ((unsigned char *)0x00001134)[param_1] = 0;
  ((unsigned char *)0x00001136)[param_1] = 1;
  ((unsigned char *)0x00001138)[param_1] = 0;
  ((unsigned char *)0x00001137)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001140) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001144) + param_1) =
       *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x88);
  return;
}

/* FUN_000a2240 @ 0xa2240 (232 bytes) */
int FUN_000a2240(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(((unsigned char *)0x00001154) + param_1);
  ((int (*)())FUN_000a2bb0)(param_1,iVar4 + 0x10);
  if (*(int *)(iVar4 + 4) != 0) {
    uVar2 = 0;
    iVar3 = 0;
    do {
      uVar2 = uVar2 + 1;
      iVar1 = iVar3 + *(int *)(iVar4 + 0x88);
      iVar3 = iVar3 + 0x78;
      ((int (*)())FUN_000a2bb0)(param_1,iVar1);
    } while (uVar2 < *(uint *)(iVar4 + 4));
  }
  *(undefined4 *)(iVar4 + 4) = 0;
  if (*(int *)(iVar4 + 0x88) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar4 + 0x88));
    *(undefined4 *)(iVar4 + 0x88) = 0;
  }
  if (*(int *)(iVar4 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar4 + 0xc));
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  (**(code **)(param_1 + 0x18))(iVar4);
  *(undefined4 *)(((unsigned char *)0x00001154) + param_1) = 0;
  return;
}

/* FUN_000a2330 @ 0xa2330 (120 bytes) */
int FUN_000a2330(param_1)
  int param_1;
{
  *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) == 0) {
    (**(code **)(((unsigned char *)0x00001160) + param_1))(param_1);
    ((int (*)())FUN_000a2240)(param_1);
    return;
  }
  return;
}

/* FUN_000a23c0 @ 0xa23c0 (356 bytes) */
int FUN_000a23c0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) == 0) {
    ((int (*)())FUN_000a2240)(param_1);
  }
  iVar6 = *(int *)(((unsigned char *)0x00001154) + param_2);
  ((unsigned char *)0x00001138)[param_1] = 0;
  ((unsigned char *)0x00001137)[param_1] = 0;
  ((unsigned char *)0x00001134)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001140) + param_1) = 0;
  *(int *)(((unsigned char *)0x00001154) + param_1) = iVar6;
  iVar1 = *(int *)(iVar6 + 0x8c);
  *(int *)(((unsigned char *)0x0000113c) + param_1) = iVar1;
  *(int *)(iVar6 + 0x8c) = iVar1 + 1;
  *(undefined4 *)(((unsigned char *)0x00001144) + param_1) = *(undefined4 *)(iVar6 + 0x88);
  uVar4 = *(undefined4 *)(iVar6 + 0x80);
  *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 1;
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar6 + 0x8c),4);
  *(undefined4 *)(iVar6 + 0x80) = uVar2;
  _memcpy(uVar2,uVar4,*(int *)(iVar6 + 0x8c) * 4 + -4);
  (**(code **)(param_1 + 0x18))(uVar4);
  if (*(int *)(iVar6 + 4) != 0) {
    uVar3 = 0;
    iVar1 = 0;
    do {
      uVar3 = uVar3 + 1;
      iVar5 = iVar1 + *(int *)(iVar6 + 0x88);
      uVar4 = *(undefined4 *)(iVar5 + 0x70);
      uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar6 + 0x8c),4);
      *(undefined4 *)(iVar5 + 0x70) = uVar2;
      iVar5 = *(int *)(iVar6 + 0x88) + iVar1;
      iVar1 = iVar1 + 0x78;
      _memcpy(*(undefined4 *)(iVar5 + 0x70),uVar4,*(int *)(iVar6 + 0x8c) * 4 + -4);
      (**(code **)(param_1 + 0x18))(uVar4);
    } while (uVar3 < *(uint *)(iVar6 + 4));
  }
  return;
}

/* FUN_000a2530 @ 0xa2530 (288 bytes) */
int FUN_000a2530(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  *(undefined4 *)(((unsigned char *)0x0000113c) + param_1) = 0;
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x3c0);
  puVar2 = (undefined1 *)
           (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1) * 0x14);
  if (puVar2 != (undefined1 *)0x0) {
    if (*(short *)(((unsigned char *)0x0000114a) + param_1) != 0) {
      iVar4 = 0;
      puVar3 = puVar2;
      do {
        iVar4 = iVar4 + 1;
        *(undefined4 *)(puVar3 + 0x10) = 0x3f800000;
        *puVar3 = 0;
        *(undefined4 *)(puVar3 + 4) = 0x3f800000;
        *(undefined4 *)(puVar3 + 8) = 0x3f800000;
        *(undefined4 *)(puVar3 + 0xc) = 0x3f800000;
        puVar3 = puVar3 + 0x14;
      } while (iVar4 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1));
    }
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) = 1;
    *(undefined4 **)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x88) = puVar1;
    *(undefined1 **)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc) = puVar2;
    **(undefined4 **)(((unsigned char *)0x00001154) + param_1) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 4) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x8c) = 1;
    ((int (*)())FUN_000a2920)(param_1,puVar1);
    *puVar1 = 0;
    ((int (*)())FUN_000a2920)(param_1,*(int *)(((unsigned char *)0x00001154) + param_1) + 0x10);
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x10) = 0;
  }
  return;
}

/* FUN_000a2660 @ 0xa2660 (392 bytes) */
int FUN_000a2660(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  
  if (((((((5 < param_3 - 0x8921) && (7 < param_3 - 0x8941)) && (param_3 != 0)) &&
        ((param_3 != 1 && (param_3 != 0x8577)))) && (param_3 != 0x896d)) ||
      (((*param_6 = param_3, param_4 != 0 && (param_4 != 0x1903)) &&
       ((param_4 != 0x1904 && ((param_4 != 0x1905 && (param_4 != 0x1906)))))))) ||
     (param_6[3] = param_4, (param_5 & 0xfffffff0) != 0)) {
    return 0;
  }
  param_6[2] = param_5;
  param_6[1] = 0;
  if (param_3 < 2) {
    param_6[3] = 0;
    if (param_3 == 0) {
      if ((param_5 & 2) != 0) {
        param_5 = param_5 & 0xfffffffd;
        param_3 = 1;
      }
    }
    else if ((param_3 == 1) && ((param_5 & 2) != 0)) {
      param_5 = param_5 & 0xfffffffd;
      param_3 = 0;
    }
    uVar1 = param_5;
    if ((((param_5 & 8) != 0) ||
        ((uVar2 = param_5, param_3 == 0 &&
         (uVar1 = param_5 & 0xfffffffa, uVar2 = uVar1, (param_5 & 8) != 0)))) &&
       ((uVar2 = uVar1, (uVar1 & 1) != 0 && (uVar2 = uVar1 & 0xfffffff6, param_3 == 0)))) {
      if ((uVar1 & 4) == 0) {
        uVar2 = uVar2 | 4;
        param_3 = 1;
      }
      else {
        param_3 = 1;
        uVar2 = uVar1 & 0xfffffff2;
      }
    }
    param_6[2] = uVar2;
    *param_6 = param_3;
  }
  if (param_3 == 0x896d) {
    *(undefined1 *)(param_2 + 0x6c) = 1;
    return 1;
  }
  return 1;
}

/* FUN_000a27f0 @ 0xa27f0 (272 bytes) */
int FUN_000a27f0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
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
  
  if (*(byte *)(param_1 + 4) == 0xffffffff) {
    iVar3 = 0;
    iVar6 = 0;
  }
  else {
    iVar8 = 0;
    iVar9 = 0;
    iVar7 = 0;
    iVar11 = 0;
    iVar10 = 0;
    do {
      iVar4 = *(int *)(iVar10 + *(int *)(param_2 + 0x14));
      iVar5 = *(int *)(iVar10 + *(int *)(param_2 + 0x20));
      iVar3 = 0;
      iVar6 = 0;
      bVar1 = 0 < iVar4;
      bVar2 = 0 < iVar5;
      while ((bVar1 || (bVar2))) {
        if ((iVar8 < *(int *)(param_2 + 0x18)) &&
           ((bVar1 && (iVar7 == *(int *)(iVar8 * 0x4c + *(int *)(param_2 + 0x10) + 0x44))))) {
          iVar3 = iVar3 + 1;
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 1;
          bVar1 = iVar3 < iVar4;
        }
        if (((iVar9 < *(int *)(param_2 + 0x24)) && (bVar2)) &&
           (iVar7 == *(int *)(iVar9 * 0x4c + *(int *)(param_2 + 0x1c) + 0x44))) {
          iVar6 = iVar6 + 1;
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 1;
          bVar2 = iVar6 < iVar5;
        }
      }
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 4;
    } while (iVar11 != *(byte *)(param_1 + 4) + 1);
  }
  *param_3 = iVar3;
  *param_4 = iVar6;
  return;
}

/* FUN_000a2910 @ 0xa2910 (8 bytes) */
int FUN_000a2910(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined1 *)(param_1 + 0x74) = (undefined1)param_2;
  return;
}

/* FUN_000a2920 @ 0xa2920 (648 bytes) */
int FUN_000a2920(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  *(undefined1 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 1;
  *(undefined4 *)(param_2 + 0x18) = 0;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + param_1) * 0x4c,param_2);
  *(undefined4 *)(param_2 + 0x10) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)(byte)((unsigned char *)0x00001150)[param_1] << 2);
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + param_1) * 0x4c);
  *(undefined4 *)(param_2 + 0x1c) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)(byte)((unsigned char *)0x00001150)[param_1] << 2);
  *(undefined4 *)(param_2 + 0x20) = uVar3;
  uVar1 = 0;
  if (((unsigned char *)0x00001150)[param_1] != '\0') {
    iVar6 = 0;
    do {
      iVar4 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(*(int *)(param_2 + 0x14) + iVar4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x20) + iVar4) = 0;
      uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
    } while (iVar6 < (int)uVar1);
  }
  uVar3 = (**(code **)(param_1 + 0xc))(*(ushort *)(((unsigned char *)0x00001148) + param_1) * uVar1 * 0xc);
  *(undefined4 *)(param_2 + 0xc) = uVar3;
  uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
  if (uVar1 != 0) {
    uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
    iVar6 = 0;
    do {
      iVar4 = 0;
      if (uVar2 != 0) {
        do {
          iVar7 = iVar4 + 0x84c0;
          iVar5 = iVar4 + iVar6 * uVar2;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 * 0xc;
          *(undefined1 *)(*(int *)(param_2 + 0xc) + iVar5) = 0;
          *(undefined1 *)(iVar5 + *(int *)(param_2 + 0xc) + 1) = 1;
          *(int *)(iVar5 + *(int *)(param_2 + 0xc) + 8) = iVar7;
          uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
        } while (iVar4 < (int)uVar2);
        uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
        uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar1);
  }
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1) * 0x14);
  *(undefined4 *)(param_2 + 0x28) = uVar3;
  if (*(short *)(((unsigned char *)0x0000114a) + param_1) != 0) {
    iVar6 = 0;
    iVar4 = 0;
    do {
      iVar6 = iVar6 + 1;
      *(undefined1 *)(*(int *)(param_2 + 0x28) + iVar4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 4) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 8) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 0xc) = 0x3f800000;
      iVar5 = *(int *)(param_2 + 0x28) + iVar4;
      iVar4 = iVar4 + 0x14;
      *(undefined4 *)(iVar5 + 0x10) = 0x3f800000;
    } while (iVar6 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1));
  }
  uVar3 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x8c),4)
  ;
  *(undefined4 *)(param_2 + 0x70) = uVar3;
  ((int (*)())FUN_000a2910)(param_2,1);
  return;
}

/* FUN_000a2bb0 @ 0xa2bb0 (400 bytes) */
int FUN_000a2bb0(param_1, param_2)
  int param_1;
  int param_2;
{
  int a0;
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x10));
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x1c));
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x20));
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  if (*(int *)(param_2 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  if (*(int *)(param_2 + 0x28) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x28));
    *(undefined4 *)(param_2 + 0x28) = 0;
  }
  a0 = *(int *)(param_2 + 0x70);
  if (a0 != 0) {
    iVar1 = *(int *)(((unsigned char *)0x00001154) + param_1);
    uVar2 = 0;
    if (*(int *)(iVar1 + 0x8c) != 0) {
      do {
        if (*(int *)(uVar2 * 4 + a0) != 0) {
          *(undefined4 *)(uVar2 * 4 + a0) = 0;
          (**(code **)(((unsigned char *)0x00001158) + param_1))(param_1);
          a0 = *(int *)(param_2 + 0x70);
          iVar1 = *(int *)(((unsigned char *)0x00001154) + param_1);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(iVar1 + 0x8c));
    }
    (**(code **)(param_1 + 0x18))(a0);
    *(undefined4 *)(param_2 + 0x70) = 0;
  }
  return;
}

/* FUN_000a2d60 @ 0xa2d60 (276 bytes) */
int FUN_000a2d60(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_2 + 0xc);
  iVar2 = ((uint)*(ushort *)(((unsigned char *)0x00001148) + param_1) * param_3 + param_4 + -0x8921) * 0xc;
  pcVar3 = pcVar4 + iVar2;
  if (pcVar4[iVar2] != '\0') {
    return 0;
  }
  iVar1 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1) * (uint)(byte)((unsigned char *)0x00001150)[param_1];
  do {
    if (iVar1 == 0) {
      *pcVar3 = '\x01';
      *(undefined1 *)(iVar2 + *(int *)(param_2 + 0xc) + 1) = (undefined1)param_6;
      *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 8) = param_5;
      *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 4) = param_7;
      return 1;
    }
    if ((*pcVar4 != '\0') && (*(int *)(pcVar4 + 8) == param_5)) {
      if ((param_7 == 0x8976) || (param_7 == 0x8978)) {
        if (*(int *)(pcVar4 + 4) == 0x8977) {
          return 0;
        }
        if (*(int *)(pcVar4 + 4) == 0x8979) {
          return 0;
        }
      }
      else {
        if (*(int *)(pcVar4 + 4) == 0x8976) {
          return 0;
        }
        if (*(int *)(pcVar4 + 4) == 0x8978) {
          return 0;
        }
      }
    }
    pcVar4 = pcVar4 + 0xc;
    iVar1 = iVar1 + -1;
  } while( true );
}

/* FUN_000a2e90 @ 0xa2e90 (708 bytes) */
int FUN_000a2e90(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
  int param_12;
  undefined4 param_13;
  int param_14;
  int param_15;
  undefined4 param_16;
{
  int iVar1;
  int iVar2;
  undefined1 *a5;
  int local_98;
  undefined1 auStack_94 [4];
  int local_90;
  int local_8c;
  uint local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  int local_4c;
  int local_48;
  
  ((int (*)())FUN_000a27f0)((*(unsigned char *)0x00001134) + param_1,param_2,&local_98,auStack_94);
  if (((((param_3 < (int)(uint)(byte)((unsigned char *)0x00001150)[param_1]) &&
        (local_98 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + param_1))) && (param_4 - 0x8961U < 0xc))
      && (((1 << (param_4 - 0x8961U & 0x3f) & 0xffdU) != 0 &&
          (local_90 = param_4,
          iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_8,param_9,param_10,auStack_7c), iVar1 != 0))))
     && (iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_11,param_12,param_13,auStack_6c), iVar1 != 0)) {
    a5 = auStack_5c;
    iVar1 = param_15;
    iVar2 = ((int (*)())FUN_000a2660)(param_1,param_2,param_14,param_15,param_16,a5);
    if ((((iVar2 != 0) && (param_5 - 0x8921U < 6)) &&
        ((((7 < param_8 - 0x8941U ||
           (((7 < param_11 - 0x8941U || (7 < param_14 - 0x8941U)) || (param_8 == param_11)))) ||
          ((param_8 == param_14 || (param_11 == param_14)))) &&
         (((param_7 & 0xffffffbf & (param_7 & 0xffffffbf) - 1) == 0 &&
          ((((param_8 != 0x896d || (param_9 != 0x1906)) &&
            ((param_11 != 0x896d || (param_12 != 0x1906)))) &&
           ((param_14 != 0x896d || (param_15 != 0x1906)))))))))) &&
       ((param_4 != 0x8967 ||
        (((param_8 != 0x896d || ((param_9 != 0 && (param_9 != 0x1906)))) &&
         ((param_11 != 0x896d || ((param_12 != 0 && (param_12 != 0x1906)))))))))) {
      if (7 < param_6) {
        return 0;
      }
      local_4c = *(int *)(param_2 + 8);
      *(int *)(param_2 + 8) = local_4c + 1;
      local_80 = 0;
      local_8c = param_5;
      local_88 = param_6;
      local_84 = param_7;
      local_48 = param_3;
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (*(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),&local_90,0x4c,iVar1,
                 param_16,a5,*(int *)(param_2 + 0x10));
      *(int *)(param_3 * 4 + *(int *)(param_2 + 0x14)) =
           *(int *)(param_3 * 4 + *(int *)(param_2 + 0x14)) + 1;
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
      return 1;
    }
  }
  ((int (*)())FUN_000a2910)(param_2,0);
  return 0;
}

/* FUN_000a3160 @ 0xa3160 (804 bytes) */
int FUN_000a3160(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
  int param_11;
  undefined4 param_12;
  int param_13;
  int param_14;
  undefined4 param_15;
{
  int iVar1;
  int iVar2;
  undefined1 *a5;
  undefined1 auStack_98 [4];
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  int local_4c;
  int local_48;
  
  ((int (*)())FUN_000a27f0)((*(unsigned char *)0x00001134) + param_1,param_2,auStack_98,&local_94);
  if (((((param_3 < (int)(uint)(byte)((unsigned char *)0x00001150)[param_1]) &&
        (local_94 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + param_1))) && (param_4 - 0x8961U < 0xc))
      && (((1 << (param_4 - 0x8961U & 0x3f) & 0xffdU) != 0 &&
          (local_90 = param_4,
          iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_7,param_8,param_9,auStack_7c), iVar1 != 0))))
     && (iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_10,param_11,param_12,auStack_6c), iVar1 != 0)) {
    a5 = auStack_5c;
    iVar1 = param_14;
    iVar2 = ((int (*)())FUN_000a2660)(param_1,param_2,param_13,param_14,param_15,a5);
    if (((((((iVar2 != 0) && (param_5 - 0x8921U < 6)) &&
           ((((7 < param_7 - 0x8941U ||
              (((7 < param_10 - 0x8941U || (7 < param_13 - 0x8941U)) || (param_7 == param_10)))) ||
             ((param_7 == param_13 || (param_10 == param_13)))) &&
            ((param_6 & 0xffffffbf & (param_6 & 0xffffffbf) - 1) == 0)))) &&
          (((1 < param_4 - 0x8966U && (param_4 != 0x896c)) ||
           ((0 < *(int *)(param_2 + 0x18) &&
            (((iVar2 = *(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),
              *(int *)(iVar2 + -8) == *(int *)(param_2 + 8) + -1 &&
              (param_3 == *(int *)(iVar2 + -4))) && (param_4 == *(int *)(iVar2 + -0x4c))))))))) &&
         (((param_4 == 0x8967 || (*(int *)(param_2 + 0x18) < 2)) ||
          ((iVar2 = *(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),
           *(int *)(iVar2 + -8) != *(int *)(param_2 + 8) + -1 ||
           ((param_3 != *(int *)(iVar2 + -4) || (*(int *)(iVar2 + -0x4c) != 0x8967)))))))) &&
        (((param_7 != 0x896d || ((param_8 != 0 && (param_8 != 0x1906)))) &&
         ((param_10 != 0x896d || ((param_11 != 0 && (param_11 != 0x1906)))))))) &&
       ((param_13 != 0x896d || ((param_14 != 0 && (param_14 != 0x1906)))))) {
      local_4c = *(int *)(param_2 + 8);
      *(int *)(param_2 + 8) = local_4c + 1;
      local_80 = 0;
      local_88 = 0;
      local_8c = param_5;
      local_84 = param_6;
      local_48 = param_3;
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (*(int *)(param_2 + 0x24) * 0x4c + *(int *)(param_2 + 0x1c),&local_90,0x4c,iVar1,
                 param_15,a5,*(int *)(param_2 + 0x1c));
      *(int *)(param_3 * 4 + *(int *)(param_2 + 0x20)) =
           *(int *)(param_3 * 4 + *(int *)(param_2 + 0x20)) + 1;
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      return 1;
    }
  }
  ((int (*)())FUN_000a2910)(param_2,0);
  return 0;
}

/* FUN_000a3490 @ 0xa3490 (196 bytes) */
int FUN_000a3490(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_3 + -0x8941;
  if ((-1 < iVar1) && (iVar1 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1))) {
    if (param_5 != 0) {
      iVar1 = iVar1 * 0x14;
      *(undefined1 *)(*(int *)(param_2 + 0x28) + iVar1) = 1;
      *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x28) + 4) = *param_4;
      *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x28) + 8) = param_4[1];
      *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x28) + 0xc) = param_4[2];
      *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x28) + 0x10) = param_4[3];
      return 1;
    }
    iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc);
    *(undefined1 *)(iVar1 * 0x14 + iVar2) = 1;
    iVar2 = iVar1 * 0x14 + iVar2;
    *(undefined4 *)(iVar2 + 4) = *param_4;
    *(undefined4 *)(iVar2 + 8) = param_4[1];
    *(undefined4 *)(iVar2 + 0xc) = param_4[2];
    *(undefined4 *)(iVar2 + 0x10) = param_4[3];
    return 1;
  }
  return 0;
}

/* FUN_000a3560 @ 0xa3560 (164 bytes) */
uint FUN_000a3560(int param_1,double fparam_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(((unsigned char *)0x000013e0) + param_1);
  if ((double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e0) + param_1) ^ 0x80000000) -
                     DOUBLE_001aa1e0) < fparam_1) {
    uVar1 = *(uint *)(((unsigned char *)0x000013e4) + param_1);
    if (fparam_1 <
        (double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + param_1) ^ 0x80000000)
                       - DOUBLE_001aa1e0)) {
      uVar1 = (uint)(int)(fparam_1 + (double)FLOAT_001aa10c);
    }
  }
  return uVar1;
}

/* FUN_000a3610 @ 0xa3610 (88 bytes) */
int FUN_000a3610(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)((unsigned char *)0x000013b7)[param_1];
  uVar1 = 1 << (uVar3 & 0x3f);
  if ((param_2 & uVar1) == 0) {
    iVar2 = uVar3 + 1;
    do {
      uVar3 = uVar3 - 1;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        uVar1 = 1 << (uVar3 & 0x3f);
        break;
      }
      uVar1 = 1 << (uVar3 & 0x3f);
    } while ((param_2 & uVar1) == 0);
  }
  if ((int)param_2 <= (int)uVar1) {
    return uVar1;
  }
  return uVar1 << 1;
}

/* FUN_000a3670 @ 0xa3670 (48 bytes) */
int FUN_000a3670(param_1)
  int param_1;
{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    uVar1 = *(uint *)(param_1 + 0xe8) & 1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x44) & 0x80;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}

/* FUN_000a36b0 @ 0xa36b0 (212 bytes) */
int FUN_000a36b0(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  
  if (param_2 != 0) {
    fVar1 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e0e) + *(int *)(*(int *)(param_1 + 4) + 0x10)) == 0x1102) {
      fVar1 = FLOAT_001aa108;
    }
    return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250
                        ) * FLOAT_001aa10c * (fVar1 + *(float *)(param_1 + 0xe0)));
  }
  return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250)
               * FLOAT_001aa10c * *(float *)(param_1 + 0xe0));
}

/* FUN_000a3790 @ 0xa3790 (716 bytes) */
void FUN_000a3790(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  char cStack_19;
  
  dVar5 = (double)FLOAT_001aa0e8;
  if (dVar5 <= fparam_1) {
    dVar5 = (double)(float)((double)CONCAT44(0x43300000,(int)fparam_1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  iVar4 = 0;
  dVar8 = (double)FLOAT_001aa0e8;
  iVar3 = ((int)param_3 >> 1) + (uint)((int)param_3 < 0 && (param_3 & 1) != 0);
  dVar6 = dVar8;
  if ((float)(fparam_1 - dVar8) < 0.0) {
    dVar6 = fparam_1;
  }
  if (-(float)(fparam_1 - dVar8) < 0.0) {
    fparam_1 = dVar6;
  }
  dVar6 = (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar7 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)(dVar6 / (double)(float)(dVar5 + (double)
                                                  FLOAT_001aa108)) ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar5 = (double)(float)(fparam_1 *
                         (double)(float)(dVar8 / (double)(float)(dVar7 * (double)(float)(dVar7 - 
                                                  dVar8))));
  if (0 < iVar3) {
    do {
      dVar8 = (double)FLOAT_001aa0d4;
      if (dVar7 <= dVar8) {
LAB_000a39f0:
        fVar1 = (float)(dVar8 * (double)FLOAT_001aa0f0);
      }
      else {
        uVar2 = 0;
        dVar9 = dVar8;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)((double)(float)((double)CONCAT44(
                                                  0x43300000,uVar2 + iVar4 ^ 0x80000000) -
                                                  DOUBLE_001aa1e0) - dVar7) ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * dVar9 + dVar8);
          }
          uVar2 = uVar2 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        uVar2 = 0;
        dVar9 = (double)FLOAT_001aa0d4;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,uVar2 + iVar4 ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * (double)((float)(dVar7 - dVar9) - FLOAT_001aa0e8) +
                                   dVar8);
          }
          uVar2 = uVar2 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        fVar1 = FLOAT_001aa0f0;
        if (dVar8 <= (double)FLOAT_001aa0e8) goto LAB_000a39f0;
      }
      cStack_19 = (char)(int)(fVar1 + FLOAT_001aa10c);
      *(char *)(iVar4 + param_4) = cStack_19;
    } while ((cStack_19 != -1) && (iVar4 = iVar4 + 1, iVar3 != iVar4));
  }
  *param_5 = iVar4;
  return;
}

/* FUN_000a3a60 @ 0xa3a60 (372 bytes) */
void FUN_000a3a60(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar5 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  dVar7 = (double)FLOAT_001aa0e8;
  if (dVar7 <= fparam_1) {
    dVar7 = (double)(float)((double)CONCAT44(0x43300000,(int)fparam_1 ^ 0x80000000) -
                           DOUBLE_001aa1e0);
  }
  dVar8 = (double)FLOAT_001aa0e8;
  uVar6 = 0;
  dVar9 = dVar8;
  if ((float)(fparam_1 - dVar8) < 0.0) {
    dVar9 = fparam_1;
  }
  if (-(float)(fparam_1 - dVar8) < 0.0) {
    fparam_1 = dVar9;
  }
  fVar1 = (float)((double)CONCAT44(0x43300000,
                                   (int)(((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000)
                                                 - DOUBLE_001aa1e0) * FLOAT_001aa10c) /
                                        (float)(dVar7 + dVar8)) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar1 = fVar1 + fVar1;
  fVar3 = FLOAT_001aa0f0 / fVar1;
  fVar2 = FLOAT_001aa0d4;
  while (fVar2 < fVar1) {
    *(char *)(param_4 + uVar6) = (char)(int)((float)(fparam_1 * (double)fVar3) * fVar2 + fVar4);
    uVar6 = uVar6 + 1;
    fVar2 = (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - dVar5);
  }
  if ((int)uVar6 < (int)(((int)param_3 >> 1) + (uint)((int)param_3 < 0 && (param_3 & 1) != 0))) {
    *(undefined1 *)(uVar6 + param_4) = 0xff;
  }
  *param_5 = uVar6;
  return;
}

/* FUN_000a3be0 @ 0xa3be0 (2056 bytes) */
int FUN_000a3be0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint param_1;
  int param_2;
  uint param_3;
  undefined4 param_4;
  uint param_5;
  undefined4 *param_6;
  undefined4 param_7;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  if (*(int *)(param_1 + 0x277c) == param_2) {
    return;
  }
  *(int *)(param_1 + 0x277c) = param_2;
  bVar1 = *(int *)(param_1 + 0x2768) == 0;
  uVar10 = (uint)*(ushort *)(param_1 + 0x1b52);
  *(uint *)(param_1 + 0x1b50) = uVar10;
  if (bVar1) {
    if ((*(uint *)(param_1 + 0x44) & 0x20000000) == 0) {
      return;
    }
  }
  else if ((param_2 != 0) || ((*(uint *)(param_1 + 0x44) & 0x20000000) == 0)) {
    *(uint *)(param_1 + 0x1b50) = uVar10;
    param_5 = param_2 * 4 + *(int *)(param_1 + 0x2768);
    uVar14 = *(uint *)(&DAT_001aa7a8 + param_2 * 4);
    *(uint *)(param_1 + 0x1b50) =
         uVar10 | *(int *)(param_5 + 0xe8) << (*(int *)(param_1 + 0x276c) * 2 + 0x10U & 0x3f);
    uVar5 = *(uint *)(param_5 + 0x110);
    *(uint *)(param_1 + 0x1b64) = uVar14 & 3 | *(uint *)(param_1 + 0x1b64) & 0xfffffffc;
    *(undefined4 *)(param_1 + 0x1b68) = 0;
    param_6 = (undefined4 *)(uVar5 & 0x10 | *(uint *)(param_1 + 0x1a64) & 0xffffffef);
    *(undefined4 **)(param_1 + 0x1a64) = param_6;
    FUN_0004b190(param_1,*(undefined4 *)(param_5 + 0xc0));
  }
  *(undefined4 *)(param_1 + 0x1ba8) = *(undefined4 *)(param_1 + 0x1ba0);
  if (!bVar1) goto LAB_000a41d0;
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    FUN_000900a0(param_1);
  }
  else {
    FUN_00064720(param_1);
  }
  (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
  uVar5 = *(uint *)(param_1 + 0x44);
  uVar14 = *(uint *)(param_1 + 0x1ba4);
  *(uint *)(param_1 + 0x1ba0) = uVar14;
  bVar2 = (uVar5 >> 0x1d & 1) == 0;
  *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
  if ((bVar2) || ((*(uint *)(param_1 + 0x8c) & 0x40000000) != 0)) {
    if ((uVar5 & 0x40000000) == 0) {
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
    else if ((!bVar2) && ((*(uint *)(param_1 + 0x8c) & 0x40000000) != 0)) {
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
  }
  else {
    if (param_2 == 0) {
      if ((uVar5 & 0x20000) == 0) {
        if (((unsigned char *)0x000013b2)[param_1] == '\0') goto LAB_000a40f0;
        uVar10 = 0;
        param_3 = 0;
        uVar15 = 0;
        uVar7 = 0x10;
        uVar9 = 0;
        uVar5 = param_1;
        do {
          if ((((*(uint *)(uVar5 + 0x48) & 0x1f) == 0) ||
              ((1 << (param_3 & 0x3f) & *(uint *)(param_1 + 0xec)) == 0)) ||
             (*(int *)(((unsigned char *)0x000013f8) + uVar5) == 0)) {
            iVar16 = (int)(char)uVar10;
            iVar11 = param_3 * 4 + param_1;
            param_5 = iVar16 + 2;
            *(uint *)(iVar11 + 0x1ee8) =
                 (iVar16 + 3) * 0x40000 & 0xfc0000U |
                 param_5 * 0x1000 & 0x3f000 |
                 (iVar16 + 1) * 0x40 & 0xfc0U |
                 uVar10 & 0x3f | *(uint *)(iVar11 + 0x1ee8) & 0xff000000;
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (uVar7 & 0x3f));
            *(uint *)(param_1 + 0x1bc0) = *(uint *)(param_1 + 0x1bc0) & ~(1 << (uVar9 & 0x3f));
            uVar10 = uVar10 + (*(uint *)(param_1 + 0x1ba0) >> (uVar15 & 0x3f) & 7);
          }
          else {
            iVar16 = uVar10 + 1;
            *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) | 0x10;
            *(uint *)(param_1 + 0x1b50) = 1 << (uVar7 & 0x3f) | *(uint *)(param_1 + 0x1b50);
            *(uint *)(param_1 + 0x1bc0) = 1 << (uVar9 & 0x3f) | *(uint *)(param_1 + 0x1bc0);
            iVar11 = param_3 * 4 + param_1;
            uVar14 = uVar14 & ~(7 << (uVar15 & 0x3f));
            uVar4 = uVar10 & 0x3f;
            uVar10 = uVar10 + 2;
            *(uint *)(iVar11 + 0x1ee8) =
                 iVar16 * 0x40 & 0xfc0U | uVar4 | *(uint *)(iVar11 + 0x1ee8) & 0xff000000 | 0xffe000
            ;
          }
          param_3 = param_3 + 1;
          uVar5 = uVar5 + 4;
          uVar15 = uVar15 + 3;
          uVar7 = uVar7 + 2;
          uVar9 = uVar9 + 2;
        } while ((int)param_3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
      }
      else {
        if ((uVar5 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[param_1];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[param_1];
        }
        uVar5 = *(uint *)(param_1 + 0xec);
        if (((unsigned char *)0x000013b2)[param_1] == '\0') {
LAB_000a40f0:
          uVar5 = 0;
          goto LAB_000a40f4;
        }
        uVar10 = 0;
        param_3 = 0;
        uVar15 = 0;
        uVar7 = 0x10;
        uVar9 = 0;
        param_5 = param_1 + 0x1ee0;
        do {
          if (((bVar3 & uVar5) >> (param_3 & 0x3f) & 1) == 0) {
            iVar11 = (int)(char)uVar10;
            *(uint *)(param_5 + 8) =
                 (iVar11 + 3) * 0x40000 & 0xfc0000U |
                 (iVar11 + 2) * 0x1000 & 0x3f000U |
                 (iVar11 + 1) * 0x40 & 0xfc0U | uVar10 & 0x3f | *(uint *)(param_5 + 8) & 0xff000000;
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (uVar7 & 0x3f));
            *(uint *)(param_1 + 0x1bc0) = *(uint *)(param_1 + 0x1bc0) & ~(1 << (uVar9 & 0x3f));
            uVar10 = uVar10 + (*(uint *)(param_1 + 0x1ba0) >> (uVar15 & 0x3f) & 7);
          }
          else {
            *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) | 0x10;
            *(uint *)(param_1 + 0x1b50) = 1 << (uVar7 & 0x3f) | *(uint *)(param_1 + 0x1b50);
            iVar11 = uVar10 + 1;
            *(uint *)(param_1 + 0x1bc0) = 1 << (uVar9 & 0x3f) | *(uint *)(param_1 + 0x1bc0);
            uVar14 = uVar14 & ~(7 << (uVar15 & 0x3f));
            uVar4 = uVar10 & 0x3f;
            uVar10 = uVar10 + 2;
            *(uint *)(param_5 + 8) =
                 iVar11 * 0x40 & 0xfc0U | uVar4 | *(uint *)(param_5 + 8) & 0xff000000 | 0xffe000;
          }
          param_3 = param_3 + 1;
          param_5 = param_5 + 4;
          uVar15 = uVar15 + 3;
          uVar7 = uVar7 + 2;
          uVar9 = uVar9 + 2;
        } while ((int)param_3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
      }
      uVar5 = uVar10 & 0xff;
    }
    else {
      if (*(int *)(param_1 + 0x2768) != 0) goto LAB_000a40f0;
      if ((uVar5 & 0x20000) == 0) {
        uVar5 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        if (uVar5 == 0) goto LAB_000a40d4;
        uVar10 = 0;
        iVar11 = 0;
        param_5 = param_1;
        do {
          if (((*(uint *)(param_5 + 0x48) & 0x1f) != 0) && (*(int *)(((unsigned char *)0x000013f8) + param_5) != 0))
          {
            iVar12 = (int)(char)uVar10;
            iVar16 = iVar11 * 4 + param_1;
            *(uint *)(iVar16 + 0x1ee8) =
                 (iVar12 + 3) * 0x40000 & 0xfc0000U |
                 (iVar12 + 2) * 0x1000 & 0x3f000U |
                 (iVar12 + 1) * 0x40 & 0xfc0U |
                 uVar10 & 0x3f | *(uint *)(iVar16 + 0x1ee8) & 0xff000000;
            uVar5 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
          }
          uVar7 = iVar11 * 3;
          iVar11 = iVar11 + 1;
          param_5 = param_5 + 4;
          uVar10 = uVar10 + (*(uint *)(param_1 + 0x1ba0) >> (uVar7 & 0x3f) & 7);
        } while (iVar11 < (int)uVar5);
      }
      else {
        if ((uVar5 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[param_1];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[param_1];
        }
        param_3 = (uint)bVar3;
        uVar5 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        if (uVar5 == 0) {
LAB_000a40d4:
          uVar10 = 0;
        }
        else {
          uVar10 = 0;
          uVar7 = 0;
          param_5 = 0;
          iVar11 = param_1 + 0x1ee0;
          do {
            if ((bVar3 >> (uVar7 & 0x3f) & 1) != 0) {
              iVar16 = (int)(char)uVar10;
              *(uint *)(iVar11 + 8) =
                   (iVar16 + 3) * 0x40000 & 0xfc0000U |
                   (iVar16 + 2) * 0x1000 & 0x3f000U |
                   (iVar16 + 1) * 0x40 & 0xfc0U | uVar10 & 0x3f | *(uint *)(iVar11 + 8) & 0xff000000
              ;
              uVar5 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
            }
            uVar7 = uVar7 + 1;
            iVar11 = iVar11 + 4;
            uVar9 = param_5 & 0x3f;
            param_5 = param_5 + 3;
            uVar10 = uVar10 + (*(uint *)(param_1 + 0x1ba0) >> uVar9 & 7);
          } while ((int)uVar7 < (int)uVar5);
        }
      }
      uVar5 = uVar10 & 0xff;
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
LAB_000a40f4:
    *(uint *)(param_1 + 0x1f2c) = uVar5 & 0x7f | *(uint *)(param_1 + 0x1f2c) & 0xffffff80;
    puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xd);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8;
    param_6 = puVar8 + 5;
    iVar11 = 0;
    *puVar8 = ((unsigned char *)0x000010c0U);
    iVar16 = 8;
    uVar13 = *(undefined4 *)(param_1 + 0x1f2c);
    puVar8[2] = 0x825;
    puVar8[1] = uVar13;
    puVar8[3] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar8[4] = *(uint *)(param_1 + 0x1f28) | 0x70000;
    uVar5 = param_1;
    do {
      puVar8 = (undefined4 *)(uVar5 + 0x1ee8);
      uVar5 = uVar5 + 4;
      *(undefined4 *)((int)param_6 + iVar11) = *puVar8;
      iVar11 = iVar11 + 4;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    iVar11 = *(int *)(0x00002748 + param_1 + 4);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar11 + 0x34;
    (*UNRECOVERED_JUMPTABLE)(param_1,iVar11 + 0x34);
  }
  *(uint *)(param_1 + 0x1ba8) = uVar14;
LAB_000a41d0:
  puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xc);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8;
  *puVar8 = ((unsigned char *)0x00001002U);
  uVar13 = *(undefined4 *)(param_1 + 0x1b50);
  puVar8[2] = 0x825;
  puVar8[1] = uVar13;
  uVar13 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar8[4] = ((unsigned char *)0x00001007U);
  puVar8[3] = uVar13;
  uVar13 = *(undefined4 *)(param_1 + 0x1a64);
  puVar8[6] = ((unsigned char *)0x0000108eU);
  puVar8[5] = uVar13;
  uVar13 = *(undefined4 *)(param_1 + 0x1b64);
  puVar8[8] = ((unsigned char *)0x00001098U);
  puVar8[7] = uVar13;
  uVar13 = *(undefined4 *)(param_1 + 0x1b68);
  puVar8[10] = ((unsigned char *)0x000010c0U);
  puVar8[9] = uVar13;
  puVar8[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
  iVar11 = *(int *)(0x00002748 + param_1 + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = iVar11 + 0x30;
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar11 + 0x30,param_3,uVar10,param_5,param_6,uVar13);
  if (*(char *)(param_1 + 0x1868) != '\0') {
    puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
    *puVar8 = 0x7101d;
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8 + 1;
    iVar11 = 8;
    uVar10 = param_1;
    do {
      puVar6 = *(undefined4 **)(0x00002748 + param_1 + 4);
      puVar8 = (undefined4 *)(uVar10 + 0x1ee8);
      uVar10 = uVar10 + 4;
      *puVar6 = *puVar8;
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    (**(code **)(param_1 + 0x275c))(param_1);
  }
  if (bVar1) {
    (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  }
  if (*(int *)(param_1 + 0x1ba8) == *(int *)(param_1 + 0x1ba0)) {
    return;
  }
  puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar8;
  *puVar8 = ((unsigned char *)0x00001001U);
  *(undefined4 *)(*(int *)(0x00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1ba8);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_000a43f0 @ 0xa43f0 (148 bytes) */
int FUN_000a43f0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2764);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xbc) != 0) {
      FUN_00030a50(param_1,*(undefined4 *)(*(int *)(iVar1 + 0xbc) + 0x7c));
    }
    iVar2 = *(int *)(iVar1 + 0x138);
    (**(code **)(param_1 + 0x18))(iVar1);
    iVar1 = iVar2;
  }
  *(undefined4 *)(param_1 + 0x2778) = 0;
  *(undefined4 *)(param_1 + 0x2764) = 0;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  return;
}

/* FUN_000a4490 @ 0xa4490 (184 bytes) */
int FUN_000a4490(param_1)
  int param_1;
{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2764); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x138)) {
    if ((*(int *)(iVar1 + 0xbc) != 0) && (-1 < *(int *)(param_1 + 0x276c))) {
      FUN_000309c0(param_1,0,*(int *)(param_1 + 0x276c));
    }
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(ushort *)(param_1 + 0x32) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x32);
  *(ushort *)(param_1 + 0x34) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  return;
}

/* FUN_000a4550 @ 0xa4550 (372 bytes) */
int FUN_000a4550(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
  uVar1 = *(uint *)(iVar5 + 4);
  if (uVar1 != 0) {
    uVar3 = 0;
    iVar4 = 0;
    do {
      iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar4 + *(int *)(iVar5 + 0x88) + 0x70));
      if (iVar2 != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
        uVar1 = *(uint *)(iVar5 + 4);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x78;
    } while (uVar3 < uVar1);
  }
  iVar5 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  uVar1 = *(uint *)(iVar5 + 4);
  if (uVar1 != 0) {
    uVar3 = 0;
    iVar4 = 0;
    do {
      iVar2 = iVar4 + *(int *)(iVar5 + 8);
      if ((*(int *)(iVar2 + 4) == 0x8804) &&
         (iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                          *(int *)(*(int *)(iVar2 + 0x14) + 0x70)), iVar2 != 0)) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
        uVar1 = *(uint *)(iVar5 + 4);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (uVar3 < uVar1);
  }
  FUN_0004b190(param_1,0);
  *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
  *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  ((int (*)())FUN_000a4490)(param_1);
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(ushort *)(param_1 + 0x34) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x276c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  return;
}

/* FUN_000a46d0 @ 0xa46d0 (144 bytes) */
int FUN_000a46d0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x2768) != 0) {
    FUN_000309c0(param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2768) + 0xbc) + 0x7c),
                 *(undefined4 *)(param_1 + 0x276c));
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
    *(ushort *)(param_1 + 0x32) =
         (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x32);
    *(ushort *)(param_1 + 0x34) =
         (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  }
  return 1;
}

/* FUN_000a4760 @ 0xa4760 (8 bytes) */
int FUN_000a4760(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x29ac);
}

/* FUN_000a4770 @ 0xa4770 (504 bytes) */
int FUN_000a4770(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 8);
  iVar7 = *(int *)(iVar5 + 0x10);
  if (((((unsigned char *)0x00002e2d)[iVar7] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (iVar5 = FUN_0001a010(iVar5,*(undefined4 *)(iVar5 + 0x26a0),param_3,param_4,param_5,param_6,
                           param_7), iVar5 != 0)) {
    uVar4 = *(uint *)(((unsigned char *)0x000013e0) + param_1);
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    if (((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar1) &&
       (uVar4 = *(uint *)(((unsigned char *)0x000013e4) + param_1),
       fVar1 < (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + param_1) ^ 0x80000000)
                      - DOUBLE_001aa1e0))) {
      uVar4 = (uint)(int)(fVar1 + FLOAT_001aa10c);
    }
    uVar4 = iVar6 * uVar4 >> 1;
  }
  else {
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    fVar2 = *(float *)(((unsigned char *)0x000013e8) + param_1);
    fVar3 = fVar2;
    if ((fVar2 < fVar1) &&
       (fVar3 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar1 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
      fVar3 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
              (float)((double)CONCAT44(0x43300000,
                                       (int)((fVar1 - fVar2) / *(float *)(((unsigned char *)0x000013f0) + param_1) +
                                            FLOAT_001aa10c) ^ 0x80000000) - DOUBLE_001aa1e0) + fVar2
      ;
    }
    fVar1 = fVar3;
    if (fVar3 - FLOAT_001aa0e8 < 0.0) {
      fVar1 = FLOAT_001aa0e8;
    }
    if (-(fVar3 - FLOAT_001aa0e8) < 0.0) {
      fVar1 = fVar3;
    }
    fVar2 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e10) + iVar7) == 0x1102) {
      fVar2 = FLOAT_001aa108;
    }
    uVar4 = (uint)(int)((float)((double)CONCAT44(0x43300000,iVar6) - DOUBLE_001aa250) * FLOAT_001aa10c *
                  (fVar1 + fVar2));
  }
  return uVar4;
}

/* FUN_000a4980 @ 0xa4980 (4768 bytes) */
int FUN_000a4980(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  char cVar2;
  undefined1 *puVar3;
  float fVar4;
  float fVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  char cVar14;
  undefined1 uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  undefined2 uVar20;
  int iVar19;
  undefined4 uVar21;
  uint extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  uint extraout_r4_02;
  uint extraout_r4_03;
  char *pcVar22;
  int *piVar23;
  undefined4 in_r8;
  char *pcVar24;
  uint uVar25;
  uint uVar26;
  undefined4 uVar27;
  undefined1 *puVar28;
  undefined4 uVar29;
  uint uVar30;
  char cVar31;
  char cVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  int iVar36;
  undefined4 uVar37;
  int iVar38;
  char *pcVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  uint uVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined8 uVar47;
  undefined8 uVar48;
  ulonglong uVar49;
  float fVar50;
  double in_stack_fffffeb8;
  double in_stack_fffffec0;
  double in_stack_fffffec8;
  double in_stack_fffffed0;
  double in_stack_fffffed8;
  int local_118 [4];
  longlong local_108;
  undefined4 local_100;
  uint uStack_fc;
  longlong local_f8;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  longlong local_d8;
  undefined4 local_d0;
  uint uStack_cc;
  undefined4 local_c8;
  uint uStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  longlong local_b8;
  undefined4 local_b0;
  uint uStack_ac;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  
  uVar25 = *(uint *)(param_1 + 0x44);
  if ((uVar25 & 0x60020000) != 0x40000000) {
    iVar40 = *(int *)(param_1 + 4);
    if ((((unsigned char *)0x00002e2d)[*(int *)(iVar40 + 0x10)] != '\0') && ((uVar25 & 0x20000) == 0)) {
      iVar40 = FUN_0001a010(iVar40,*(undefined4 *)(iVar40 + 0x26a0),param_3,param_4,param_5,in_r8,
                            uVar25);
      if (iVar40 == 0) goto LAB_000a4a50;
      iVar40 = *(int *)(param_1 + 4);
    }
    iVar40 = *(int *)(iVar40 + 0x10);
    if ((((((unsigned char *)0x00002e2c)[iVar40] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
        (*(short *)(((unsigned char *)0x00002e28) + iVar40) == -1)) &&
       (((((unsigned char *)0x00003178)[iVar40] == '\0' || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
        ((*(short *)(((unsigned char *)0x00003170) + iVar40) != 0x1b02 &&
         (*(short *)(((unsigned char *)0x00003172) + iVar40) != 0x1b02)))))) {
      if (*(int *)(param_1 + 0x2768) == 0) {
        return 0;
      }
      ((int (*)())FUN_000a4550)(param_1);
      return 0;
    }
  }
LAB_000a4a50:
  uVar25 = *(uint *)(param_1 + 0x276c);
  uVar26 = *(uint *)(param_1 + 0x38);
  if (-1 < (int)uVar25) {
    uVar16 = uVar26 & 0x10310e | (int)(uint)*(ushort *)(param_1 + 0x34) >> (uVar25 & 0x3f) & 1U;
  }
  else {
    uVar16 = 1;
  }
  if (uVar16 == 0 && *(int *)(param_1 + 0x2458) == 0) {
    return 0;
  }
  uVar30 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  uVar16 = uVar30 - 1;
  if (-1 < (int)uVar16) {
    puVar17 = (uint *)(uVar16 * 4 + param_1 + 0x48);
    do {
      if ((((*puVar17 & 0x1f) == 0) || (puVar17[0x4ec] == 0)) &&
         ((uVar34 = *(uint *)(param_1 + 0x44), (uVar34 & 0x2000) == 0 ||
          (((((int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar16 & 0x3f) & 1U) == 0 &&
            (((uVar34 & 0x800) == 0 || ((byte)((unsigned char *)0x000011d1)[param_1] != uVar16)))) &&
           (((uVar34 & 0x400) == 0 || ((byte)((unsigned char *)0x000011d2)[param_1] != uVar16)))))))) break;
      uVar16 = uVar16 - 1;
      puVar17 = puVar17 + -1;
      uVar30 = uVar30 - 1;
    } while (uVar30 != 0);
  }
  if (-1 < (int)uVar25) {
    pcVar24 = (char *)(1 << (uVar25 & 0x3f));
  }
  else {
    pcVar24 = (char *)0x0;
  }
  if (-1 < (int)uVar16) {
    pcVar24 = (char *)((uint)pcVar24 | 1 << (uVar16 & 0x3f));
  }
  if (pcVar24 != (char *)0x0) {
    uVar26 = uVar26 | 0x200;
    *(uint *)(param_1 + 0x38) = uVar26;
    *(ushort *)(param_1 + 0x32) = (ushort)pcVar24 | *(ushort *)(param_1 + 0x32);
    *(ushort *)(param_1 + 0x34) = (ushort)pcVar24 | *(ushort *)(param_1 + 0x34);
  }
  *(uint *)(param_1 + 0x276c) = uVar16;
  if ((int)uVar16 < 0) goto LAB_000a52dc;
  iVar40 = *(int *)(param_1 + 4);
  cVar2 = *(char *)(param_1 + 0x245b);
  iVar38 = *(int *)(iVar40 + 0x10);
  uVar16 = *(uint *)(param_1 + 0x44) & 0x60020000 ^ 0x40000000;
  pcVar22 = (char *)-uVar16;
  iVar40 = FUN_0001a010(iVar40,*(undefined4 *)(iVar40 + 0x26a0),param_3,param_4,pcVar22,pcVar24,
                        uVar26);
  uVar47 = ((int (*)())FUN_000a36b0)(param_1,(uint)(iVar40 == 0));
  uVar21 = (undefined4)uVar47;
  iVar41 = *(int *)(param_1 + 4);
  sVar6 = *(short *)(((unsigned char *)0x00002e0e) + iVar38);
  uVar25 = *(uint *)(iVar41 + 0x10);
  if ((((unsigned char *)0x00002e2d)[uVar25] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) {
LAB_000a4c38:
    cVar14 = '\0';
  }
  else {
    uVar48 = FUN_0001a010(iVar41,*(undefined4 *)(iVar41 + 0x26a0),param_3,param_4,pcVar22,pcVar24,
                          uVar25);
    uVar21 = (undefined4)uVar48;
    if ((int)((ulonglong)uVar48 >> 0x20) != 0) {
      iVar41 = *(int *)(param_1 + 4);
      goto LAB_000a4c38;
    }
    iVar41 = *(int *)(param_1 + 4);
    cVar14 = '\x01';
  }
  if (((((unsigned char *)0x00002e2c)[*(int *)(iVar41 + 0x10)] == '\0') ||
      ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (cVar31 = '\x01', *(short *)(((unsigned char *)0x00002e28) + *(int *)(iVar41 + 0x10)) == -1)) {
    cVar31 = '\0';
  }
  iVar41 = ((int (*)())FUN_000a4770)(param_1,uVar21,param_3,param_4,pcVar22,pcVar24,uVar25);
  fVar4 = *(float *)(((unsigned char *)0x00002e20) + iVar38);
  fVar5 = *(float *)(((unsigned char *)0x000013e8) + param_1);
  sVar7 = *(short *)(((unsigned char *)0x00002e10) + iVar38);
  fVar11 = fVar5;
  if ((fVar5 < fVar4) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar4 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
    pcVar22 = "ram[";
    pcVar24 = "ram[";
    local_100 = 0x43300000;
    uStack_fc = (uint)(int)((fVar4 - fVar5) / *(float *)(((unsigned char *)0x000013f0) + param_1) + 0.5);
    local_108 = (longlong)(int)uStack_fc;
    uStack_fc = uStack_fc ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
             (float)((double)CONCAT44(0x43300000,uStack_fc) - 4503601774854144.0) + fVar5;
  }
  iVar42 = *(int *)(param_1 + 4);
  sVar8 = *(short *)(((unsigned char *)0x00002e28) + iVar38);
  iVar18 = *(int *)(iVar42 + 0x10);
  if (((((unsigned char *)0x00003178)[iVar18] == '\0') ||
      (uVar25 = *(uint *)(param_1 + 0x44) & 0x20000, uVar25 != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar18) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + iVar18) != 0x1b02)))) {
    cVar32 = '\0';
  }
  else {
    cVar32 = '\x01';
  }
  uVar9 = *(ushort *)(((unsigned char *)0x00003172) + iVar38);
  uVar10 = *(ushort *)(((unsigned char *)0x00003170) + iVar38);
  if (cVar2 != '\0') {
    cVar31 = '\x01';
    cVar32 = '\x01';
  }
  pcVar39 = *(char **)(param_1 + 0x2764);
  if (pcVar39 != (char *)0x0) {
    do {
      if ((((bool)*pcVar39 == (uVar16 == 0)) &&
          (((uVar16 != 0 ||
            ((((uint)(byte)pcVar39[1] == (uint)(iVar40 == 0) &&
              ((int)((ulonglong)uVar47 >> 0x20) == *(int *)(pcVar39 + 4))) &&
             ((sVar6 == 0x1102) == (bool)pcVar39[8])))) &&
           ((pcVar39[0x14] == cVar14 && (pcVar39[0x15] == cVar31)))))) &&
         (((cVar14 == '\0' && (cVar31 == '\0')) ||
          ((((iVar41 == *(int *)(pcVar39 + 0x18) && ((sVar7 == 0x1102) == (bool)pcVar39[0x1c])) &&
            ((cVar14 == '\0' ||
             ((2.0 <= *(float *)(pcVar39 + 0x20) || (fVar11 == *(float *)(pcVar39 + 0x20))))))) &&
           ((cVar31 == '\0' || (*(short *)(pcVar39 + 0x28) == sVar8)))))))) {
        if ((uint)uVar10 == *(uint *)(pcVar39 + 0xb4)) {
          uVar26 = *(uint *)(pcVar39 + 0xb8);
          if (uVar9 != uVar26) goto LAB_000a4e54;
        }
        else {
          uVar26 = *(uint *)(pcVar39 + 0xb8);
LAB_000a4e54:
          if ((uVar10 != uVar26) || ((uint)uVar9 != *(uint *)(pcVar39 + 0xb4))) goto LAB_000a4e90;
        }
        if (pcVar39[0x2a] == cVar32) {
          if (cVar32 == '\0') goto LAB_000a5b9c;
          param_3 = 0x80;
          iVar18 = _memcmp(pcVar39 + 0x2c,((unsigned char *)0x000030e8) + iVar38,0x80);
          if (iVar18 == 0) goto LAB_000a5b9c;
        }
      }
LAB_000a4e90:
      pcVar39 = *(char **)(pcVar39 + 0x138);
    } while (pcVar39 != (char *)0x0);
  }
  if (*(int *)(param_1 + 0x2778) == 0x100) {
    ((int (*)())FUN_000a43f0)(param_1);
    iVar42 = *(int *)(param_1 + 4);
  }
  iVar40 = *(int *)(iVar42 + 0x10);
  cVar2 = *(char *)(param_1 + 0x245b);
  pcVar39 = (char *)(**(code **)(param_1 + 0x10))(1,0x13c);
  if (pcVar39 == (char *)0x0) goto LAB_000a52dc;
  *pcVar39 = (*(uint *)(param_1 + 0x44) & 0x60020000) == 0x40000000;
  uVar47 = FUN_0001a010(*(int *)(param_1 + 4),*(undefined4 *)(*(int *)(param_1 + 4) + 0x26a0),
                        param_3,param_4,pcVar22,pcVar24,uVar25);
  uVar21 = (undefined4)uVar47;
  pcVar39[1] = (int)((ulonglong)uVar47 >> 0x20) == 0;
  pcVar39[8] = *(short *)(((unsigned char *)0x00002e0e) + iVar40) == 0x1102;
  iVar38 = *(int *)(param_1 + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(iVar38 + 0x10)] == '\0') ||
     (pcVar22 = (char *)(*(uint *)(param_1 + 0x44) & 0x20000), pcVar22 != (char *)0x0)) {
LAB_000a4f50:
    cVar14 = '\0';
  }
  else {
    uVar47 = FUN_0001a010(iVar38,*(undefined4 *)(iVar38 + 0x26a0),param_3,param_4,0,pcVar24,uVar25);
    uVar21 = (undefined4)uVar47;
    cVar14 = '\x01';
    if ((int)((ulonglong)uVar47 >> 0x20) != 0) goto LAB_000a4f50;
  }
  pcVar39[0x14] = cVar14;
  pcVar39[0x1c] = *(short *)(((unsigned char *)0x00002e10) + iVar40) == 0x1102;
  fVar4 = *(float *)(((unsigned char *)0x00002e20) + iVar40);
  fVar5 = *(float *)(((unsigned char *)0x000013e8) + param_1);
  fVar11 = fVar5;
  if ((fVar5 < fVar4) &&
     (fVar11 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar4 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
    pcVar22 = "ram[";
    pcVar24 = "ram[";
    local_f0 = 0x43300000;
    uStack_ec = (uint)(int)((fVar4 - fVar5) / *(float *)(((unsigned char *)0x000013f0) + param_1) + 0.5);
    local_f8 = (longlong)(int)uStack_ec;
    uStack_ec = uStack_ec ^ 0x80000000;
    fVar11 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
             (float)((double)CONCAT44(0x43300000,uStack_ec) - 4503601774854144.0) + fVar5;
  }
  *(float *)(pcVar39 + 0x20) = fVar11;
  iVar38 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[iVar38] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (uVar27 = 1, *(short *)(((unsigned char *)0x00002e28) + iVar38) == -1)) {
    uVar27 = 0;
  }
  pcVar39[0x15] = (char)uVar27;
  iVar38 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[iVar38] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar38) != 0x1b02 &&
      (*(short *)(((unsigned char *)0x00003172) + iVar38) != 0x1b02)))) {
    cVar14 = '\0';
  }
  else {
    cVar14 = '\x01';
  }
  pcVar39[0x2a] = cVar14;
  *(uint *)(pcVar39 + 0xb4) = (uint)*(ushort *)(((unsigned char *)0x00003170) + iVar40);
  *(uint *)(pcVar39 + 0xb8) = (uint)*(ushort *)(((unsigned char *)0x00003172) + iVar40);
  if (cVar2 != '\0') {
    pcVar39[0x2a] = '\x01';
    pcVar39[0x15] = '\x01';
  }
  if (*pcVar39 == '\0') {
    if ((*(int *)(pcVar39 + 0xb4) == 0x1b00) || (*(int *)(pcVar39 + 0xb8) == 0x1b00))
    goto LAB_000a5108;
    iVar38 = 0;
    uVar25 = 0;
  }
  else {
    uVar47 = ((int (*)())FUN_000a36b0)(param_1,(uint)(byte)pcVar39[1]);
    iVar41 = (int)((ulonglong)uVar47 >> 0x20);
    uVar21 = (undefined4)uVar47;
    iVar38 = iVar41 << 2;
    *(int *)(pcVar39 + 4) = iVar41;
    if (iVar38 < 1) {
LAB_000a5108:
      iVar38 = 0;
      uVar25 = 1;
    }
    else {
      uVar25 = 1;
    }
  }
  iVar41 = iVar38;
  iVar18 = iVar38;
  if ((*(uint *)(pcVar39 + 0x14) & 0xffff0000) == 0) {
    if ((*(int *)(pcVar39 + 0xb4) == 0x1b01) || (*(int *)(pcVar39 + 0xb8) == 0x1b01))
    goto LAB_000a5188;
  }
  else {
    uVar20 = 0xffff;
    if (((unsigned char *)0x00002e2c)[iVar40] != '\0') {
      uVar20 = *(undefined2 *)(((unsigned char *)0x00002e28) + iVar40);
    }
    *(undefined2 *)(pcVar39 + 0x28) = uVar20;
    iVar42 = ((int (*)())FUN_000a4770)(param_1,uVar21,param_3,param_4,pcVar22,pcVar24,uVar27);
    *(int *)(pcVar39 + 0x18) = iVar42;
    if (iVar38 < iVar42 << 2) {
      iVar41 = iVar42 << 2;
    }
    if (iVar38 < 0x10) {
      iVar18 = 0x10;
    }
LAB_000a5188:
    uVar25 = uVar25 + 1;
    iVar38 = iVar41;
  }
  if (pcVar39[0x2a] != '\0') {
    param_3 = 0x80;
    (**(code **)(((unsigned char *)0x00001344) + param_1))(pcVar39 + 0x2c,((unsigned char *)0x000030e8) + iVar40,0x80);
    *(undefined4 *)(pcVar39 + 0xac) = *(undefined4 *)(param_1 + 0x2770);
    *(undefined4 *)(pcVar39 + 0xb0) = *(undefined4 *)(param_1 + 0x2774);
    if (iVar38 < 0x20) {
      iVar38 = 0x20;
    }
    if (iVar18 < 0x20) {
      iVar18 = 0x20;
    }
    uVar25 = uVar25 + 1;
  }
  uVar21 = ((int (*)())FUN_000a3610)(param_1,iVar38,param_3,param_4,pcVar22,pcVar24,uVar27);
  uVar27 = ((int (*)())FUN_000a3610)(param_1,iVar18,param_3,param_4,pcVar22,pcVar24,uVar27);
  uVar26 = uVar25;
  if (1 < uVar25) {
    uVar26 = 4;
  }
  uVar37 = *(undefined4 *)(param_1 + 4);
  if (uVar25 < 2) {
    uVar29 = 3;
  }
  else {
    uVar29 = 1;
  }
  pcVar24 = (char *)0x1;
  uVar47 = FUN_00030c50(param_1,uVar21,uVar27,uVar26,0x1909,1,((unsigned char *)0x00001401U),uVar29);
  iVar40 = (int)((ulonglong)uVar47 >> 0x20);
  uVar16 = (uint)uVar47;
  iVar38 = 0;
  if (iVar40 != 0) {
    FUN_0002ddf0(uVar37,iVar40);
    iVar41 = *(int *)(iVar40 + 0x30);
    iVar38 = iVar40 + 0x3c;
    pcVar24 = (char *)0x2600;
    *(undefined1 *)(iVar40 + 0x39) = 0xff;
    *(undefined2 *)(iVar40 + 0x74) = *(undefined2 *)(iVar41 + 0xb0);
    *(undefined2 *)(iVar40 + 0x7c) = *(undefined2 *)(iVar41 + 0xac);
    *(uint *)(iVar40 + 0xc0) = (uint)*(ushort *)(iVar41 + 0xae) * (uint)*(ushort *)(iVar41 + 0xac);
    uVar21 = *(undefined4 *)(iVar41 + 0xb4);
    *(undefined2 *)(iVar40 + 0xa2) = 0x2600;
    *(uint *)(iVar40 + 0x50) = *(uint *)(iVar40 + 0x50) & 0xfffe01ff | 0x8a00;
    *(uint *)(iVar40 + 0x54) = *(uint *)(iVar40 + 0x54) & 0xfffffffc | 1;
    *(undefined2 *)(iVar40 + 0xa0) = 0x2600;
    *(undefined4 *)(iVar40 + 0xbc) = uVar21;
    uVar16 = extraout_r4;
  }
  *(int *)(pcVar39 + 0xbc) = iVar38;
  if (iVar38 != 0) {
    iVar40 = *(int *)(iVar38 + 0x80);
    if (*pcVar39 == '\0') {
      if (1 < uVar25) {
        _memset(iVar40,0xff,*(undefined4 *)(iVar38 + 0x84));
        uVar16 = extraout_r4_03;
      }
    }
    else {
      uVar33 = (uint)*(ushort *)(iVar38 + 0x3c);
      uVar35 = (uint)*(ushort *)(iVar38 + 0x3a);
      local_e8 = 0x43300000;
      uVar30 = *(int *)(pcVar39 + 4) * 2;
      uVar34 = *(int *)(pcVar39 + 4) << 2;
      uStack_e4 = uVar30 ^ 0x80000000;
      bVar1 = pcVar39[1] == '\0';
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_e4) - 4503601774854144.0);
      if (bVar1) {
        uVar49 = (ulonglong)uVar16;
        fVar5 = 0.0;
      }
      else {
        uVar49 = (**(code **)(param_1 + 0xc))(uVar30);
        uVar16 = (uint)(uVar49 >> 0x20);
        bVar1 = uVar16 == 0;
        if (bVar1) {
          fVar5 = 0.0;
        }
        else {
          uVar26 = uVar16;
          if ((*(uint *)(param_1 + 0xe8) & 1) == 0) {
            dVar45 = (double)*(float *)(param_1 + 0xe0);
            if (pcVar39[8] != '\0') goto LAB_000a53ac;
            ((void (*)())FUN_000a3a60)(param_1,(int)uVar49,uVar34,uVar16,local_118,dVar45,in_f2,in_f3,in_f4,in_f5,
                         in_f6,in_f7,in_f8,in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8,
                         in_stack_fffffed0,in_stack_fffffed8);
            uVar21 = extraout_r4_01;
          }
          else {
            dVar45 = (double)*(float *)(param_1 + 0x104);
LAB_000a53ac:
            ((void (*)())FUN_000a3790)(param_1,(int)uVar49,uVar34,uVar16,local_118,dVar45,in_f2,in_f3,in_f4,in_f5,
                         in_f6,in_f7,in_f8,in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8,
                         in_stack_fffffed0);
            uVar21 = extraout_r4_00;
          }
          uVar49 = CONCAT44(uVar16,uVar21);
          local_e0 = 0x43300000;
          uStack_dc = uVar30 - local_118[0] ^ 0x80000000;
          fVar5 = (float)((double)CONCAT44(0x43300000,uStack_dc) - 4503601774854144.0) - 0.5;
          fVar5 = fVar5 * fVar5;
        }
      }
      iVar38 = (int)(uVar49 >> 0x20);
      uVar16 = (uint)uVar49;
      pcVar24 = "ram[";
      fVar11 = 0.5 - fVar4;
      if (bVar1) {
        if (uVar33 != 0) {
          uVar30 = 0;
          fVar5 = fVar11;
          do {
            if (uVar35 != 0) {
              iVar38 = 0;
              uVar43 = uVar35;
              fVar12 = fVar11;
              do {
                uVar15 = 0xff;
                if (fVar4 * fVar4 <= fVar12 * fVar12 + fVar5 * fVar5) {
                  uVar15 = 0;
                }
                *(undefined1 *)(iVar40 + iVar38) = uVar15;
                iVar38 = iVar38 + 1;
                fVar12 = fVar12 + 1.0;
                uVar43 = uVar43 - 1;
              } while (uVar43 != 0);
            }
            pcVar24 = "ram[";
            uVar30 = uVar30 + 1;
            iVar40 = iVar40 + uVar35;
            fVar5 = fVar5 + 1.0;
          } while (uVar33 != uVar30);
        }
      }
      else {
        if (uVar33 != 0) {
          uVar16 = 0;
          fVar12 = fVar11;
          do {
            if (uVar35 != 0) {
              uVar30 = 0;
              fVar13 = fVar11;
              do {
                fVar50 = fVar13 * fVar13 + fVar12 * fVar12;
                if (fVar5 <= fVar50) {
                  if (fVar4 * fVar4 <= fVar50) {
                    *(undefined1 *)(iVar40 + uVar30) = 0;
                  }
                  else {
                    fVar50 = _sqrtf(fVar50);
                    iVar41 = (int)((fVar4 - fVar50) + 0.5);
                    local_d8 = (longlong)iVar41;
                    *(undefined1 *)(iVar40 + uVar30) = *(undefined1 *)(iVar38 + iVar41);
                  }
                }
                else {
                  *(undefined1 *)(iVar40 + uVar30) = 0xff;
                }
                uVar30 = uVar30 + 1;
                fVar13 = fVar13 + 1.0;
              } while (uVar35 != uVar30);
            }
            uVar16 = uVar16 + 1;
            iVar40 = iVar40 + uVar35;
            fVar12 = fVar12 + 1.0;
          } while (uVar33 != uVar16);
        }
        pcVar24 = "ram[";
        (**(code **)(param_1 + 0x18))(iVar38);
        uVar16 = extraout_r4_02;
      }
      uStack_cc = uVar34 ^ 0x80000000;
      uStack_c4 = uVar35 ^ 0x80000000;
      local_d0 = 0x43300000;
      uStack_bc = uVar33 ^ 0x80000000;
      local_c8 = 0x43300000;
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_cc) - 4503601774854144.0);
      *(float *)(pcVar39 + 0xc) =
           fVar4 / (float)((double)CONCAT44(0x43300000,uStack_c4) - 4503601774854144.0);
      local_c0 = 0x43300000;
      *(float *)(pcVar39 + 0x10) =
           fVar4 / (float)((double)CONCAT44(0x43300000,uStack_bc) - 4503601774854144.0);
    }
    iVar38 = *(int *)(pcVar39 + 0xbc);
    iVar40 = *(int *)(iVar38 + 0x80);
    if (1 < uVar25) {
      iVar40 = iVar40 + *(int *)(iVar38 + 0x84);
    }
    piVar23 = (int *)(*(uint *)(pcVar39 + 0x14) & 0xffff0000);
    if (piVar23 == (int *)0x0) {
      if (1 < uVar25) {
        _memset(iVar40,0xff,*(undefined4 *)(iVar38 + 0x84));
        goto LAB_000a58ec;
      }
    }
    else {
      uVar34 = (uint)*(ushort *)(iVar38 + 0x3a);
      iVar18 = *(int *)(pcVar39 + 0x18);
      iVar42 = (int)(uint)*(ushort *)(iVar38 + 0x3c) >> 4;
      iVar41 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      uVar30 = iVar18 * 4;
      uVar33 = iVar40 + uVar34 * (*(ushort *)(iVar38 + 0x3c) - 1);
      if (pcVar39[0x14] == '\0') {
        _memset(uVar33,0xff,uVar34);
        pcVar39[0x24] = '?';
        pcVar39[0x25] = -0x80;
        pcVar39[0x26] = '\0';
        pcVar39[0x27] = '\0';
      }
      else {
        uVar26 = uVar33;
        if (pcVar39[0x1c] == '\0') {
          dVar44 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar41);
          dVar46 = (double)*(float *)(((unsigned char *)0x000013e8) + param_1);
          dVar45 = dVar46;
          if ((dVar46 < dVar44) &&
             (dVar45 = (double)*(float *)(((unsigned char *)0x000013ec) + param_1),
             dVar44 < (double)*(float *)(((unsigned char *)0x000013ec) + param_1))) {
            local_a0 = 0x43300000;
            uStack_9c = (uint)(int)((float)((double)(float)(dVar44 - dVar46) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + param_1)) + 0.5);
            local_a8 = (longlong)(int)uStack_9c;
            uStack_9c = uStack_9c ^ 0x80000000;
            dVar45 = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + param_1) *
                                     (double)(float)((double)CONCAT44(0x43300000,uStack_9c) -
                                                    4503601774854144.0) + dVar46);
          }
          piVar23 = local_118;
          ((void (*)())FUN_000a3a60)(param_1,uVar16,uVar30,uVar33,piVar23,dVar45,in_f2,in_f3,in_f4,in_f5,in_f6,
                       in_f7,in_f8,in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8,
                       in_stack_fffffed0,in_stack_fffffed8);
        }
        else {
          dVar44 = (double)*(float *)(((unsigned char *)0x00002e20) + iVar41);
          dVar46 = (double)*(float *)(((unsigned char *)0x000013e8) + param_1);
          dVar45 = dVar46;
          if ((dVar46 < dVar44) &&
             (dVar45 = (double)*(float *)(((unsigned char *)0x000013ec) + param_1),
             dVar44 < (double)*(float *)(((unsigned char *)0x000013ec) + param_1))) {
            local_b0 = 0x43300000;
            uStack_ac = (uint)(int)((float)((double)(float)(dVar44 - dVar46) /
                                      (double)*(float *)(((unsigned char *)0x000013f0) + param_1)) + 0.5);
            local_b8 = (longlong)(int)uStack_ac;
            uStack_ac = uStack_ac ^ 0x80000000;
            dVar45 = (double)(float)((double)*(float *)(((unsigned char *)0x000013f0) + param_1) *
                                     (double)(float)((double)CONCAT44(0x43300000,uStack_ac) -
                                                    4503601774854144.0) + dVar46);
          }
          piVar23 = local_118;
          ((void (*)())FUN_000a3790)(param_1,uVar16,uVar30,uVar33,piVar23,dVar45,in_f2,in_f3,in_f4,in_f5,in_f6,
                       in_f7,in_f8,in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8,
                       in_stack_fffffed0);
        }
        if (0 < local_118[0]) {
          iVar38 = 0;
          puVar28 = (undefined1 *)(uVar33 + uVar30);
          do {
            puVar3 = (undefined1 *)(iVar38 + uVar33);
            iVar38 = iVar38 + 1;
            puVar28 = puVar28 + -1;
            *puVar28 = *puVar3;
          } while (iVar38 < local_118[0]);
        }
        _memset(uVar33 + local_118[0],0xff,uVar30 + local_118[0] * -2);
        _memset((undefined1 *)(uVar33 + uVar30),0,uVar34 + iVar18 * -4);
        uStack_94 = uVar30 ^ 0x80000000;
        uStack_8c = uVar34 ^ 0x80000000;
        local_90 = 0x43300000;
        local_98 = 0x43300000;
        *(float *)(pcVar39 + 0x24) =
             (float)((double)CONCAT44(0x43300000,uStack_94) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,uStack_8c) - 4503601774854144.0);
      }
      iVar38 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      if (((((unsigned char *)0x00002e2c)[iVar38] == '\0') ||
          (piVar23 = (int *)(*(uint *)(param_1 + 0x44) & 0x20000), piVar23 != (int *)0x0)) ||
         (uVar16 = (uint)*(ushort *)(((unsigned char *)0x00002e28) + iVar38), uVar16 == 0xffff)) {
        uVar16 = 0xffff;
      }
      iVar38 = 0;
      do {
        pcVar24 = (char *)(uVar16 & 1);
        if (pcVar24 == (char *)0x0) {
          iVar41 = iVar40 + uVar34 * iVar42;
          _memset(iVar40,0,uVar34 * iVar42);
        }
        else {
          iVar18 = iVar42;
          if (iVar38 == 0xf) {
            iVar18 = iVar42 + -1;
          }
          iVar41 = iVar40;
          if (0 < iVar18) {
            iVar36 = 0;
            do {
              iVar36 = iVar36 + 1;
              iVar41 = iVar40 + uVar34;
              (**(code **)(((unsigned char *)0x00001344) + param_1))(iVar40,uVar33,uVar34);
              iVar40 = iVar41;
            } while (iVar18 != iVar36);
          }
        }
        bVar1 = iVar38 != 0xf;
        uVar16 = uVar16 >> 1;
        iVar38 = iVar38 + 1;
        iVar40 = iVar41;
      } while (bVar1);
LAB_000a58ec:
      iVar38 = *(int *)(pcVar39 + 0xbc);
    }
    iVar40 = *(int *)(iVar38 + 0x80);
    if (1 < uVar25) {
      iVar40 = iVar40 + *(int *)(iVar38 + 0x84) * 2;
    }
    if (pcVar39[0x2a] == '\0') {
      if (1 < uVar25) {
        _memset(iVar40,0xff,*(undefined4 *)(iVar38 + 0x84));
        goto LAB_000a59f4;
      }
    }
    else {
      uVar16 = (uint)*(ushort *)(iVar38 + 0x3a);
      iVar41 = 0x20;
      piVar23 = *(int **)(pcVar39 + 0xac);
      uVar25 = *(uint *)(pcVar39 + 0xb0);
      pcVar24 = (char *)((int)(uint)*(ushort *)(iVar38 + 0x3c) >> 5);
      iVar38 = (int)uVar16 >> 5;
      do {
        iVar18 = 0;
        uVar26 = 0;
        do {
          uVar15 = 0xff;
          if ((1 << ((uint)piVar23 & 0x3f) & *(uint *)(pcVar39 + (0x1f - uVar25) * 4 + 0x2c)) == 0)
          {
            uVar15 = 0;
          }
          iVar42 = uVar26 + iVar40;
          if (pcVar24 != (char *)0x0) {
            pcVar22 = (char *)0x0;
            do {
              if (iVar38 != 0) {
                iVar19 = 0;
                iVar36 = iVar38;
                do {
                  *(undefined1 *)(iVar42 + iVar19) = uVar15;
                  iVar19 = iVar19 + 1;
                  iVar36 = iVar36 + -1;
                } while (iVar36 != 0);
              }
              pcVar22 = pcVar22 + 1;
              iVar42 = iVar42 + uVar16;
            } while (pcVar24 != pcVar22);
          }
          bVar1 = iVar18 != 0x1f;
          uVar26 = uVar26 + iVar38;
          iVar18 = iVar18 + 1;
          piVar23 = (int *)((int)piVar23 + 1U & 0x1f);
        } while (bVar1);
        iVar41 = iVar41 + -1;
        iVar40 = iVar40 + uVar16 * (int)pcVar24;
        uVar25 = uVar25 + 1 & 0x1f;
      } while (iVar41 != 0);
LAB_000a59f4:
      iVar38 = *(int *)(pcVar39 + 0xbc);
    }
    iVar40 = FUN_000341a0(param_1,*(undefined4 *)(iVar38 + 0x7c),*(undefined4 *)(param_1 + 0x276c),
                          uVar26,piVar23,pcVar24);
    if (iVar40 != 0) {
      uVar25 = (uint)*(byte *)(*(int *)(pcVar39 + 0xbc) + 0x31);
      pcVar39[0xf8] = '\0';
      pcVar39[0xf9] = '\0';
      pcVar39[0xfa] = '\0';
      pcVar39[0xfb] = '\0';
      pcVar39[0xd0] = '\0';
      pcVar39[0xd1] = '\0';
      pcVar39[0xd2] = '\0';
      pcVar39[0xd3] = '\0';
      iVar40 = 1 - ((int)-(uVar25 ^ 2) >> 0x1f);
      if ((*pcVar39 == '\0') && (uVar25 != 3)) {
        pcVar39[0xe8] = '\0';
        pcVar39[0xe9] = '\0';
        pcVar39[0xea] = '\0';
        pcVar39[0xeb] = '\0';
        pcVar39[0xc0] = '\0';
        pcVar39[0xc1] = '\0';
        pcVar39[0xc2] = '\0';
        pcVar39[0xc3] = '\0';
      }
      else {
        pcVar39[0xc0] = '\0';
        pcVar39[0xc1] = '\0';
        pcVar39[0xc2] = '\0';
        pcVar39[0xc3] = '\x02';
        pcVar39[0xe8] = '\0';
        pcVar39[0xe9] = '\0';
        pcVar39[0xea] = '\0';
        pcVar39[0xeb] = '\x01';
        if ((*(int *)(pcVar39 + 0xb4) == 0x1b00) || (*(int *)(pcVar39 + 0xb8) == 0x1b00)) {
          *(uint *)(pcVar39 + 0xd0) = uVar25;
          *(int *)(pcVar39 + 0xf8) = iVar40;
        }
      }
      if (((*(uint *)(pcVar39 + 0x14) & 0xffff0000) == 0) && (uVar25 != 3)) {
        pcVar39[0xec] = '\0';
        pcVar39[0xed] = '\0';
        pcVar39[0xee] = '\0';
        pcVar39[0xef] = '\0';
        pcVar39[0xc4] = '\0';
        pcVar39[0xc5] = '\0';
        pcVar39[0xc6] = '\0';
        pcVar39[199] = '\0';
      }
      else {
        *(uint *)(pcVar39 + 0xc4) = uVar25;
        *(int *)(pcVar39 + 0xec) = iVar40;
        if ((*(int *)(pcVar39 + 0xb4) == 0x1b01) || (*(int *)(pcVar39 + 0xb8) == 0x1b01)) {
          *(uint *)(pcVar39 + 0xd0) = uVar25;
          *(int *)(pcVar39 + 0xf8) = iVar40;
        }
      }
      if ((pcVar39[0x2a] != 0) || (uVar25 == 3)) {
        *(uint *)(pcVar39 + 0xd0) = uVar25;
        *(int *)(pcVar39 + 0xf8) = iVar40;
      }
      uVar26 = (uint)((*(uint *)(pcVar39 + 0x14) & 0xffff0000) != 0) * 0x10 |
               *(uint *)(pcVar39 + 0x114) & 0xffffffef;
      uVar27 = *(undefined4 *)(pcVar39 + 0xf8);
      uVar25 = -(uint)(byte)pcVar39[0x2a] >> 0x1b & 0x10 | *(uint *)(pcVar39 + 0x120) & 0xffffffef;
      uVar21 = *(undefined4 *)(pcVar39 + 0xd0);
      *(undefined4 *)(pcVar39 + 0xcc) = *(undefined4 *)(pcVar39 + 0xc4);
      *(undefined4 *)(pcVar39 + 200) = *(undefined4 *)(pcVar39 + 0xc4);
      *(undefined4 *)(pcVar39 + 0xf4) = *(undefined4 *)(pcVar39 + 0xec);
      *(undefined4 *)(pcVar39 + 0xf0) = *(undefined4 *)(pcVar39 + 0xec);
      *(undefined4 *)(pcVar39 + 0x10c) = uVar27;
      *(uint *)(pcVar39 + 0x11c) = uVar26;
      *(uint *)(pcVar39 + 0x134) = uVar25;
      *(uint *)(pcVar39 + 0x120) = uVar25;
      *(uint *)(pcVar39 + 0x124) = uVar25;
      *(uint *)(pcVar39 + 0x128) = uVar25;
      *(uint *)(pcVar39 + 300) = uVar25;
      *(uint *)(pcVar39 + 0x130) = uVar25;
      *(undefined4 *)(pcVar39 + 0xe4) = uVar21;
      *(undefined4 *)(pcVar39 + 0xd4) = uVar21;
      *(undefined4 *)(pcVar39 + 0xfc) = uVar27;
      *(undefined4 *)(pcVar39 + 0xd8) = uVar21;
      *(undefined4 *)(pcVar39 + 0x100) = uVar27;
      *(undefined4 *)(pcVar39 + 0xdc) = uVar21;
      *(undefined4 *)(pcVar39 + 0x104) = uVar27;
      *(undefined4 *)(pcVar39 + 0xe0) = uVar21;
      *(undefined4 *)(pcVar39 + 0x108) = uVar27;
      *(uint *)(pcVar39 + 0x114) = uVar26;
      *(uint *)(pcVar39 + 0x118) = uVar26;
      *(uint *)(pcVar39 + 0x110) = *(uint *)(pcVar39 + 0x110) & 0xffffffef;
      *(undefined4 *)(pcVar39 + 0x138) = *(undefined4 *)(param_1 + 0x2764);
      *(undefined4 *)(param_1 + 0x2764) = pcVar39;
      *(int *)(param_1 + 0x2778) = *(int *)(param_1 + 0x2778) + 1;
LAB_000a5b9c:
      *(char **)(param_1 + 0x2768) = pcVar39;
      ((int (*)())FUN_000a46d0)(param_1);
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(ushort *)(param_1 + 0x34) =
           (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
      return 0;
    }
  }
  _free(pcVar39);
LAB_000a52dc:
  ((int (*)())FUN_000a4550)(param_1);
  return 1;
}

/* FUN_000a5c40 @ 0xa5c40 (624 bytes) */
int FUN_000a5c40(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  fVar1 = *(float *)(((unsigned char *)0x00002da8) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    uVar7 = (int)(fVar1 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar7 = (uint)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002dac) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar2 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar2 = (int)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002da0) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar3 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar3 = (int)fVar1;
  }
  fVar1 = *(float *)(((unsigned char *)0x00002da4) + iVar5) * 255.0;
  if (2.1474836e+09 <= fVar1) {
    iVar5 = (int)(fVar1 - 2.1474836e+09) + -0x80000000;
  }
  else {
    iVar5 = (int)fVar1;
  }
  *(uint *)(param_1 + 0x1a94) = uVar7 | iVar2 << 0x18 | iVar3 << 0x10 | iVar5 << 8;
  puVar4 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,0xd,in_r5,in_r6,in_r7,in_r8,*(code **)(param_1 + 0x2758));
  iVar5 = *(int *)(param_1 + 4);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
  puVar6 = *(uint **)(iVar5 + 0x1d8);
  *puVar6 = (int)puVar4 - (int)puVar6 >> 2 | *puVar6;
  *(undefined4 **)(iVar5 + 0x1d8) = puVar4;
  *puVar4 = 0x4000000;
  puVar4[3] = ((unsigned char *)0x00001393U);
  puVar4[4] = 10;
  puVar4[5] = ((unsigned char *)0x00001385U);
  uVar8 = *(undefined4 *)(param_1 + 0x1a94);
  puVar4[7] = 0xc0023800;
  puVar4[0xb] = ((unsigned char *)0x00001380U);
  puVar4[0xc] = 0;
  puVar4[8] = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[6] = uVar8;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4 + 0xd;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0xd);
  return;
}

/* FUN_000a5ec0 @ 0xa5ec0 (620 bytes) */
int FUN_000a5ec0(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  int iVar10;
  
  uVar4 = *(uint *)(param_1 + 0x1a4c);
  iVar6 = *(int *)(param_1 + 0x1a60);
  *(uint *)(param_1 + 0x1a4c) = uVar4 & 0xfffeffff;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0x2a50);
  if (iVar10 == 1) {
    uVar7 = *(uint *)(param_1 + 0x44);
    if ((uVar7 & 0x10000000) == 0) {
      *(undefined4 *)(param_1 + 0x1a68) = 0x66666666;
      *(undefined4 *)(param_1 + 0x1a6c) = 0x6666666;
      *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
      goto LAB_000a6110;
    }
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x44);
  }
  iVar10 = iVar10 >> 1;
  iVar2 = (iVar10 + -1) * 4;
  uVar3 = *(uint *)(&DAT_001aa7e8 + iVar2);
  *(uint *)(param_1 + 0x2354) = *(uint *)(param_1 + 0x2354) & 0xfffffffe;
  uVar4 = (uint)(iVar10 == 3) << 0x11 | uVar4 & 0xfffcffff;
  *(undefined4 *)(param_1 + 0x1a6c) = *(undefined4 *)(&DAT_001aa7d0 + iVar2);
  *(uint *)(param_1 + 0x1a4c) = uVar4;
  uVar5 = *(undefined4 *)(&DAT_001aa7dc + iVar2);
  *(uint *)(param_1 + 0x1a60) = (uVar3 & 3) << 1 | 1;
  *(undefined4 *)(param_1 + 0x1a68) = uVar5;
  if ((uVar7 & 0x10000000) == 0) {
    cVar9 = '\0';
    uVar3 = 0;
    fVar1 = FLOAT_001aa0e8;
  }
  else {
    fVar1 = *(float *)(param_1 + 0x438);
    cVar9 = *(char *)(param_1 + 0x43c);
    uVar3 = uVar7 >> 0x19 & 1;
    *(uint *)(param_1 + 0x1a4c) = uVar7 >> 0xb & 0x10000 | uVar4;
  }
  uVar4 = *(uint *)(*(int *)(param_1 + 4) + 0x2a50);
  if (uVar3 == 0) {
    uVar4 = (1 << (uVar4 & 0x3f)) - 1;
    uVar4 = uVar4 | uVar4 * 0x40000 | uVar4 * 0x1000 | uVar4 * 0x40;
  }
  else {
    uVar8 = 0;
    uVar7 = (uint)(int)(fVar1 * FLOAT_001aa104 *
                   (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa10c);
    uVar3 = uVar7 & 3;
    uVar7 = (int)uVar7 >> 2;
    if (cVar9 != '\0') {
      uVar8 = (1 << (uVar4 & 0x3f)) - 1;
    }
    uVar4 = uVar8 ^ (1 << (uVar7 + (uVar3 != 0) & 0x3f)) - 1U |
            (uVar8 ^ (1 << (uVar7 & 0x3f)) - 1U) << 0x12 |
            (uVar8 ^ (1 << (uVar7 + (1 < uVar3) & 0x3f)) - 1U) << 0xc |
            (uVar8 ^ (1 << (uVar7 + (2 < uVar3) & 0x3f)) - 1U) << 6;
  }
  *(uint *)(param_1 + 0x1b60) = uVar4;
LAB_000a6110:
  uVar4 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar4 | 0x80200;
  if (iVar6 != *(int *)(param_1 + 0x1a60)) {
    *(uint *)(param_1 + 0x1930) = uVar4 | 0x2080340;
  }
  return;
}

/* FUN_000a6140 @ 0xa6140 (896 bytes) */
int FUN_000a6140(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  uint *a6;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  FUN_00086a80(param_1,param_3);
  *(undefined4 *)(param_1 + 0x1ba0) = 3;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1b84) = 0;
  *(undefined4 *)(param_1 + 0x1b50) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x1b74) = 0x1c000;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  if ((param_2 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x1a50) = 0;
    *(undefined4 *)(param_1 + 0x1ab8) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1ab8) = 0;
  }
  if ((param_2 & 0x1000) != 0) {
    *(undefined4 *)(param_1 + 0x1aec) = 0;
  }
  **(undefined4 **)(param_1 + 0x2440) = 0;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffff0f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffe0ff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffdfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffbfff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffff7fff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xff0fffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xe0ffffff | 0x1000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) | 0x20000000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xbfffffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0x7fffffff;
  **(undefined4 **)(param_1 + 0x2444) = 0;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  a6 = *(uint **)(param_1 + 0x2444);
  *a6 = *a6 & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff | 0xf0000000;
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x20,param_3,0xf,2,1,a6,3);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
  puVar3 = puVar1 + 0x1a;
  *puVar1 = 0x887;
  uVar2 = *(undefined4 *)(param_1 + 0x1b74);
  puVar1[2] = 0x82c;
  puVar1[1] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b84);
  puVar1[4] = ((unsigned char *)0x000010aeU);
  puVar1[3] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b30);
  puVar1[6] = ((unsigned char *)0x00001002U);
  puVar1[5] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b50);
  puVar1[8] = 0x824;
  puVar1[7] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar1[10] = 0x825;
  puVar1[9] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar1[0xc] = 0x82d;
  puVar1[0xb] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x248c);
  puVar1[0xe] = 0x854;
  puVar1[0xd] = uVar2;
  uVar2 = **(undefined4 **)(param_1 + 0x2440);
  puVar1[0x10] = 0x878;
  puVar1[0xf] = uVar2;
  uVar2 = **(undefined4 **)(param_1 + 0x2444);
  puVar1[0x12] = ((unsigned char *)0x000012f0U);
  puVar1[0x11] = uVar2;
  puVar1[0x13] = *(undefined4 *)(param_1 + 0x1aec);
  puVar1[0x14] = ((unsigned char *)0x000012f6U);
  uVar2 = *(undefined4 *)(param_1 + 0x1a50);
  puVar1[0x16] = ((unsigned char *)0x000010faU);
  puVar1[0x15] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1b60);
  puVar1[0x18] = ((unsigned char *)0x000013c5U);
  puVar1[0x17] = uVar2;
  puVar1[0x19] = *(undefined4 *)(param_1 + 0x1ab8);
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar1[0x1a] = ((unsigned char *)0x000013c5U);
    puVar3 = puVar1 + 0x1c;
    puVar1[0x1b] = *(undefined4 *)(param_1 + 0x1ab8);
  }
  *puVar3 = ((unsigned char *)0x00001048U);
  uVar2 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar3[2] = ((unsigned char *)0x00001047U);
  puVar3[1] = uVar2;
  puVar3[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 4);
  return;
}

/* FUN_000a64d0 @ 0xa64d0 (36 bytes) */
int FUN_000a64d0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x150);
  iVar2 = *(int *)(param_1 + 4) + 0x30;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  *(undefined1 *)(iVar2 + 0xc5) = 1;
  return;
}

/* FUN_000a6500 @ 0xa6500 (828 bytes) */
int FUN_000a6500(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  uint uVar5;
  undefined4 in_r7;
  uint uVar6;
  undefined4 in_r8;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = *(int *)(param_1 + 4);
  iVar11 = *(int *)(iVar12 + 0x10);
  uVar3 = FUN_0004e990(param_1);
  uVar8 = *(uint *)(iVar12 + 0x154) & 0x30000;
  if ((uVar8 == 0x20000) || (uVar8 == 0x30000)) {
    iVar10 = 0x18;
  }
  else {
    if (uVar8 == 0x10000) {
      iVar10 = 0x10;
      *(uint *)(param_1 + 0x1ae4) = uVar3 | uVar3 << 0x10;
      goto LAB_000a6564;
    }
    iVar10 = 0;
  }
  *(uint *)(param_1 + 0x1ae4) = uVar3 << 8;
LAB_000a6564:
  uVar8 = *(uint *)(((unsigned char *)0x00002db4) + iVar11);
  *(uint *)(param_1 + 0x1ae4) = *(uint *)(param_1 + 0x1ae4) | uVar8;
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1a,in_r5,in_r6,in_r7,in_r8,uVar8)
  ;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
  puVar7 = puVar4 + 0xc;
  puVar1 = *(uint **)(iVar12 + 0x1d8);
  *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(iVar12 + 0x1d8) = puVar4;
  puVar4[8] = 0xc0023200;
  puVar4[0xb] = 0;
  *puVar4 = 0x5000000;
  puVar4[6] = ((unsigned char *)0x000013c6U);
  puVar4[1] = param_2;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[9] = 0;
  puVar4[10] = 0;
  puVar4[7] = 3;
  if (param_2 != 0) {
    if (*(char *)(param_1 + 0x2451) == '\0') {
      uVar3 = uVar3 >> (iVar10 - 8U & 0x3f);
      uVar8 = uVar3 | uVar3 << 0x18 | uVar3 << 0x10 | uVar3 << 8;
    }
    else {
      uVar8 = 0xffffffff;
      if ((uVar3 < 0xffffff) && (uVar8 = 0, uVar3 != 0)) {
        uVar8 = iVar10 - 1;
        uVar5 = *(uint *)(param_1 + 0x1ab0) >> 0xc & 7;
        uVar2 = (1 << uVar5) - 1;
        if ((*(uint *)(param_1 + 0x1ab0) & 0x8000) == 0) {
          uVar6 = 0;
          for (; (1 << (uVar8 & 0x3f) & uVar3 * uVar2) != 0; uVar8 = uVar8 - 1) {
            uVar6 = uVar6 + 1;
          }
        }
        else {
          uVar6 = 0;
          for (; (uVar3 * uVar2 & 1 << (uVar8 & 0x3f)) == 0; uVar8 = uVar8 - 1) {
            uVar6 = uVar6 + 1;
          }
        }
        uVar3 = uVar3 * uVar2;
        if (uVar6 < uVar2) {
          uVar3 = uVar3 * 2;
          uVar2 = uVar6;
        }
        uVar8 = (uVar3 & ~((1 << (uVar2 & 0x3f)) + -1 << (iVar10 - uVar2 & 0x3f))) >>
                ((uVar5 + (iVar10 - uVar2)) - 8 & 0x3f) | uVar2 << (8 - uVar5 & 0x3f);
        uVar3 = uVar8 & 0xff;
        uVar8 = uVar3 | uVar3 << 8 | uVar3 << 0x10 | uVar8 << 0x18;
      }
    }
    uVar3 = *(uint *)(param_1 + 0x1ab8);
    puVar9 = puVar4 + 0xe;
    *puVar7 = ((unsigned char *)0x000013c5U);
    uVar3 = uVar3 | 1;
    puVar4[0xd] = uVar3;
    if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
      puVar4[0xf] = uVar3;
      puVar4[0xe] = ((unsigned char *)0x000013c5U);
      puVar9 = puVar4 + 0x10;
    }
    puVar7 = puVar9 + 6;
    puVar4[2] = (int)puVar9 - (int)puVar4 >> 2;
    *puVar9 = 0xc0023700;
    puVar9[2] = 0;
    puVar9[3] = uVar8;
    puVar9[1] = 0;
    puVar9[4] = ((unsigned char *)0x000013c5U);
    puVar9[5] = *(undefined4 *)(param_1 + 0x1ab8);
    if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
      puVar9[6] = ((unsigned char *)0x000013c5U);
      puVar7 = puVar9 + 8;
      puVar9[7] = *(undefined4 *)(param_1 + 0x1ab8);
    }
  }
  puVar4[3] = (int)puVar7 + (4 - (int)puVar4) >> 2;
  *puVar7 = ((unsigned char *)0x000013caU);
  puVar7[1] = *(undefined4 *)(param_1 + 0x1ae4);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar7 + 2;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar7 + 2);
  return;
}

/* FUN_000a6860 @ 0xa6860 (1096 bytes) */
int FUN_000a6860(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  float fVar8;
  float fVar12;
  float fVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 extraout_r4;
  int iVar16;
  undefined *puVar17;
  undefined4 *puVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  double dVar22;
  undefined1 auStack_128 [144];
  undefined4 local_98;
  uint uStack_94;
  undefined4 local_90;
  uint uStack_8c;
  undefined4 local_88;
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  longlong local_70;
  longlong local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  longlong local_58;
  longlong local_50;
  float fVar9;
  float fVar10;
  float fVar11;
  
  local_80 = 0x43300000;
  local_98 = 0x43300000;
  local_90 = 0x43300000;
  local_88 = 0x43300000;
  uStack_94 = *(int *)(((unsigned char *)0x00001358) + param_1) - *(int *)(((unsigned char *)0x000013d8) + param_1) ^ 0x80000000;
  uStack_8c = *(int *)(((unsigned char *)0x00001360) + param_1) - *(int *)(((unsigned char *)0x000013d8) + param_1) ^ 0x80000000;
  uStack_84 = *(int *)(((unsigned char *)0x0000135c) + param_1) - *(int *)(((unsigned char *)0x000013dc) + param_1) ^ 0x80000000;
  uStack_7c = *(int *)(((unsigned char *)0x00001364) + param_1) - *(int *)(((unsigned char *)0x000013dc) + param_1) ^ 0x80000000;
  dVar22 = *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_94) - DOUBLE_001aa1e0);
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_7c) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_84) - DOUBLE_001aa1e0);
  if (((param_2 & 0x400) == 0) || (iVar20 = 1, ((unsigned char *)0x00001491)[param_1] == '\0')) {
    iVar20 = 0;
  }
  if (((param_2 & 0x100) == 0) || (iVar21 = 1, ((unsigned char *)0x00001490)[param_1] == '\0')) {
    iVar21 = 0;
  }
  iVar16 = iVar21;
  FUN_00086ba0(param_1,0,iVar21,iVar20,auStack_128);
  if ((iVar21 == 0) && (iVar20 != 0)) {
    uVar15 = 0x25;
    if (*(char *)(param_1 + 0x2802) != '\0') {
      uVar15 = 0x23;
    }
    puVar14 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar15);
    cVar7 = *(char *)(param_1 + 0x2802);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar14;
    if (cVar7 == '\0') {
      *puVar14 = 0x5c8;
      puVar14[1] = 0x10000000;
      puVar14 = puVar14 + 2;
      *(undefined1 *)(param_1 + 0x2802) = 1;
    }
    puVar14 = (undefined4 *)FUN_00083c90(param_1,puVar14);
    uStack_74 = *(undefined4 *)(param_1 + 8);
    local_78 = 0x43300000;
    *(undefined4 **)(param_1 + 0x2794) = puVar14;
    fVar11 = FLOAT_001aa194;
    fVar10 = FLOAT_001aa190;
    fVar9 = FLOAT_001aa18c;
    fVar8 = FLOAT_001aa188;
    fVar13 = (fVar5 + fVar4) * FLOAT_001aa10c;
    fVar12 = (fVar2 + fVar3) * FLOAT_001aa10c;
    fVar6 = (float)((double)CONCAT44(0x43300000,uStack_74) - DOUBLE_001aa250);
    uVar1 = (uint)(int)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar5));
    local_70 = (longlong)(int)uVar1;
    iVar20 = (int)(fVar6 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar3 - fVar2));
    local_68 = (longlong)iVar20;
    puVar14[2] = 0x82c;
    *puVar14 = ((unsigned char *)0x00001087U);
    puVar14[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  }
  else {
    uVar15 = 0x25;
    if (*(char *)(param_1 + 0x2802) != '\0') {
      uVar15 = 0x23;
    }
    puVar14 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar15);
    cVar7 = *(char *)(param_1 + 0x2802);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar14;
    if (cVar7 == '\0') {
      *puVar14 = 0x5c8;
      puVar14[1] = 0x10000000;
      puVar14 = puVar14 + 2;
      *(undefined1 *)(param_1 + 0x2802) = 1;
    }
    puVar14 = (undefined4 *)FUN_00083c90(param_1,puVar14);
    uStack_5c = *(undefined4 *)(param_1 + 8);
    local_60 = 0x43300000;
    *(undefined4 **)(param_1 + 0x2794) = puVar14;
    fVar11 = FLOAT_001aa194;
    fVar10 = FLOAT_001aa190;
    fVar9 = FLOAT_001aa18c;
    fVar8 = FLOAT_001aa188;
    fVar13 = (fVar5 + fVar4) * FLOAT_001aa10c;
    fVar12 = (fVar2 + fVar3) * FLOAT_001aa10c;
    fVar6 = (float)((double)CONCAT44(0x43300000,uStack_5c) - DOUBLE_001aa250);
    uVar1 = (uint)(int)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar5));
    local_58 = (longlong)(int)uVar1;
    iVar20 = (int)(fVar6 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar3 - fVar2));
    local_50 = (longlong)iVar20;
    puVar14[2] = 0x82c;
    *puVar14 = ((unsigned char *)0x00001087U);
    puVar14[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  }
  puVar18 = puVar14 + 0x10;
  uVar19 = 0xc0083500;
  puVar17 = ((unsigned char *)0x00001087U);
  uVar15 = *(undefined4 *)(param_1 + 0x1b84);
  puVar14[4] = 0xc0083500;
  puVar14[5] = 0x10031;
  puVar14[6] = fVar12;
  puVar14[7] = fVar13;
  puVar14[8] = (float)dVar22;
  puVar14[10] = fVar8;
  puVar14[0xb] = fVar9;
  puVar14[3] = uVar15;
  puVar14[0xc] = fVar10;
  puVar14[0xd] = fVar11;
  puVar14[0xe] = ((unsigned char *)0x00001087U);
  puVar14[9] = 0x3f800000;
  puVar14[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar18;
  (**(code **)(param_1 + 0x275c))(param_1,puVar18);
  FUN_0009d3b0(param_1,extraout_r4,iVar16,puVar17,puVar18,uVar19,iVar20);
  FUN_000872e0(param_1,auStack_128);
  return;
}

/* FUN_000a6cb0 @ 0xa6cb0 (656 bytes) */
int FUN_000a6cb0(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  code *pcVar2;
  uint *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar6 = *(int *)(param_1 + 4);
  cVar5 = ((unsigned char *)0x00003190)[*(int *)(iVar6 + 0x10)];
  if (cVar5 != '\0') {
    if ((((*(int *)(param_1 + 0x440) == 0) && (*(int *)(param_1 + 0x444) == 0)) &&
        (*(int *)(iVar6 + 0x160) == *(int *)(param_1 + 0x44c))) &&
       (*(int *)(iVar6 + 0x15c) == *(int *)(param_1 + 0x448))) {
      cVar5 = '\0';
    }
  }
  uVar7 = *(uint *)(iVar6 + 0x154);
  iVar10 = iVar6 + 0x30;
  if (*(int *)(iVar6 + 0x150) != 0) {
    iVar10 = *(int *)(iVar6 + 0x150);
  }
  if ((uVar7 & 0x40) == 0) {
    bVar1 = (param_2 >> 8 & 1) == 0;
LAB_000a6d70:
    if ((uVar7 & 0x80) == 0) {
      uVar8 = param_2 >> 10 & 1;
LAB_000a6db0:
      if (cVar5 == '\0') {
        if (bVar1) {
          uVar9 = 0;
        }
        else if (((*(char *)(param_1 + 0x247c) == '\0') || ((uVar7 & 0x40) == 0)) ||
                (((uVar7 & 0x30000) == 0x10000 && ((uVar7 & 0x1000) != 0)))) {
          uVar9 = 0;
          *(undefined1 *)(iVar10 + 0xc5) = 1;
        }
        else {
          uVar9 = 1;
          *(undefined1 *)(iVar10 + 0xc5) = 0;
          *(undefined1 *)(iVar10 + 0xc4) = 1;
        }
        iVar6 = (**(code **)(param_1 + 0x2758))(param_1,3000);
        pcVar2 = *(code **)(param_1 + 0x275c);
        *(int *)(0x00002748 + param_1 + 4) = iVar6;
        (*pcVar2)(param_1,iVar6);
        iVar10 = *(int *)(0x00002748 + param_1 + 4);
        ((int (*)())FUN_000a6500)(param_1,uVar9);
        *(int *)(iVar6 + 0x10) = *(int *)(0x00002748 + param_1 + 4) - iVar10 >> 2;
        ((int (*)())FUN_000a6860)(param_1,param_2);
        *(int *)(iVar6 + 0x14) = *(int *)(param_1 + 0x2794) - iVar10 >> 2;
        goto LAB_000a6ebc;
      }
    }
    else {
      uVar8 = param_2 >> 10 & 1;
      if ((uVar8 != 0) || ((*(uint *)(param_1 + 0x8c) & 0x20000000) == 0)) goto LAB_000a6db0;
    }
    if (!bVar1) {
      *(undefined1 *)(iVar10 + 0xc5) = 1;
    }
  }
  else {
    bVar1 = (param_2 >> 8 & 1) == 0;
    if (!bVar1) goto LAB_000a6d70;
  }
  uVar8 = param_2 >> 10 & 1;
  ((int (*)())FUN_000a6860)(param_1,param_2);
LAB_000a6ebc:
  if (uVar8 != 0) {
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x20000000;
  }
  iVar6 = *(int *)(param_1 + 4);
  FUN_0004ce30(param_1);
  puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,5);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4;
  puVar3 = *(uint **)(iVar6 + 0x1d8);
  *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(iVar6 + 0x1d8) = puVar4;
  *puVar4 = 0x2f000000;
  puVar4[1] = (*(unsigned char *)0x000010e9);
  uVar9 = *(undefined4 *)(param_1 + 0x1ae0);
  puVar4[3] = ((unsigned char *)0x000013c7U);
  puVar4[2] = uVar9;
  puVar4[4] = *(undefined4 *)(param_1 + 0x1ab0);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4 + 5;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 5);
  return;
}

/* FUN_000a6f70 @ 0xa6f70 (8 bytes) */
int FUN_000a6f70(param_1)
  undefined4 param_1;
{
  return (int)_calloc(param_1,1);
}

/* FUN_000a6f80 @ 0xa6f80 (4 bytes) */
int FUN_000a6f80()
{
  return;
}

/* FUN_000a6f90 @ 0xa6f90 (168 bytes) */
void FUN_000a6f90(float *param_1,float *param_2,double fparam_1)
{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar1 = FLOAT_001aa0d4;
  fVar2 = *param_2;
  dVar3 = (double)(param_2[2] * param_2[2] + fVar2 * fVar2 + param_2[1] * param_2[1]);
  if (dVar3 <= (double)FLOAT_001aa0d4) {
    param_1[2] = FLOAT_001aa0d4;
    *param_1 = fVar1;
    param_1[1] = fVar1;
  }
  else {
    dVar3 = _sqrt(dVar3);
    fVar1 = (float)(DOUBLE_001aa200 / dVar3);
    *param_1 = fVar2 * fVar1;
    param_1[1] = fVar1 * param_2[1];
    param_1[2] = fVar1 * param_2[2];
  }
  return;
}

/* FUN_000a7050 @ 0xa7050 (2324 bytes) */
int FUN_000a7050(param_1)
  int param_1;
{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  code *a4;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  
  iVar9 = param_1 + 0x240;
  uVar7 = 0x3e000000;
  *(undefined1 *)(param_1 + 0x26b) = 0;
  puVar2 = PTR_001e8a58;
  a4 = FUN_000a6f70;
  *(undefined **)(param_1 + 0x250) = PTR_001e8b14;
  *(undefined **)(param_1 + 0x254) = puVar2;
  puVar2 = PTR_001e8aa4;
  *(undefined **)(param_1 + 600) = PTR_001e8a3c;
  *(undefined **)(((unsigned char *)0x00001584) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e8aa8;
  *(undefined **)(param_1 + 0x2998) = PTR_FUN_001e8ab0;
  *(undefined **)(param_1 + 0x299c) = puVar2;
  puVar2 = PTR_FUN_001e8ae0;
  *(undefined **)(((unsigned char *)0x000014c0) + param_1) = PTR_FUN_001e8acc;
  *(undefined **)(((unsigned char *)0x000014c8) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e8ae8;
  *(undefined **)(((unsigned char *)0x000014d0) + param_1) = PTR_FUN_001e8abc;
  *(undefined **)(((unsigned char *)0x000014c4) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e8b38;
  *(undefined **)(((unsigned char *)0x000014cc) + param_1) = PTR_FUN_001e8a2c;
  *(undefined **)(((unsigned char *)0x000014d4) + param_1) = puVar2;
  *(undefined4 *)(((unsigned char *)0x00001604) + param_1) = 0x3f800000;
  *(undefined4 *)(((unsigned char *)0x00001628) + param_1) = 0x3e000000;
  puVar3 = PTR_FUN_001e8b28;
  puVar2 = PTR_FUN_001e8a48;
  *(code **)(param_1 + 0x24c) = FUN_000a6f70;
  *(int *)(param_1 + 0x244) = param_1;
  *(undefined4 *)(((unsigned char *)0x0000162c) + param_1) = 0x42800000;
  *(undefined4 *)(((unsigned char *)0x00001608) + param_1) = 0x42800000;
  *(undefined4 *)((int)((unsigned char *)0x00001624) + param_1) = 0x80;
  *(int *)(param_1 + 0x25c) = iVar9;
  *(undefined **)(((unsigned char *)0x000014e8) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x000014d8) + param_1) = puVar3;
  *(undefined4 *)(((unsigned char *)0x0000145c) + param_1) = 0;
  puVar2 = PTR_FUN_001e8a18;
  *(undefined **)(((unsigned char *)0x000014dc) + param_1) = PTR_FUN_001e8aa0;
  *(undefined **)(((unsigned char *)0x000014e4) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x000014e0) + param_1) = PTR_FUN_001e8b00;
  *(undefined **)(((unsigned char *)0x000014ec) + param_1) = PTR_FUN_001e8a08;
  ((unsigned char *)0x000015f4)[param_1] = 4;
  ((unsigned char *)0x000015f5)[param_1] = 8;
  ((unsigned char *)0x000015f7)[param_1] = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001630) + param_1) = 0x3e000000;
  ((unsigned char *)0x000015f3)[param_1] = 1;
  *(undefined4 *)(((unsigned char *)0x00001408) + param_1) = 0xffff;
  *(undefined2 *)(((unsigned char *)0x000015fe) + param_1) = 0x100;
  *(undefined4 *)(((unsigned char *)0x00001614) + param_1) = 0x40;
  ((unsigned char *)0x000015f8)[param_1] = ((unsigned char *)0x00002b7c)[param_1];
  *(undefined4 *)((*(unsigned char *)0x00001618) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000161c) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x0000160c) + param_1) = 0x3e000000;
  *(undefined4 *)((*(unsigned char *)0x00001610) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x00001620) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x000013f8) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001400) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x00001404) + param_1) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x000013fc) + param_1) = 0x20;
  uVar6 = ((int (*)())FUN_000a6f70)(0xa8);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined4 *)(((unsigned char *)0x000016dc) + param_1) = 0x20;
  *(undefined4 *)(((unsigned char *)0x000013ac) + param_1) = uVar6;
  uVar11 = (*pcVar4)(0x90);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(int *)(((unsigned char *)0x00001394) + param_1) = (int)((ulonglong)uVar11 >> 0x20);
  *(undefined2 *)(((unsigned char *)0x0000138a) + param_1) = 8;
  *(undefined2 *)(((unsigned char *)0x00001388) + param_1) = 6;
  ((unsigned char *)0x00001390)[param_1] = 2;
  *(undefined2 *)(((unsigned char *)0x0000138e) + param_1) = 8;
  *(undefined2 *)(((unsigned char *)0x0000138c) + param_1) = 0x10;
  uVar6 = (*pcVar4)(0x14,(int)uVar11,in_r5,in_r6,a4,uVar7,pcVar4);
  uVar8 = *(uint *)(param_1 + 0x2cc);
  *(undefined4 *)(((unsigned char *)0x0000136c) + param_1) = uVar6;
  ((unsigned char *)0x000015f0)[param_1] = 8;
  ((unsigned char *)0x000015f6)[param_1] = 0x10;
  *(undefined4 *)(param_1 + 0x2d4) = 0;
  ((unsigned char *)0x000015f2)[param_1] = 8;
  ((unsigned char *)0x000015f1)[param_1] = 0x10;
  *(undefined4 *)(param_1 + 0x29a8) = 0;
  *(undefined4 *)(param_1 + 0x29a4) = 0;
  *(undefined4 *)(param_1 + 0x29b0) = 0;
  *(undefined4 *)(param_1 + 0x29b4) = 0;
  *(undefined4 *)(param_1 + 0x29b8) = 0;
  *(undefined1 *)(param_1 + 0x262d) = 0;
  *(undefined1 *)(param_1 + 0x2690) = 0;
  *(undefined4 *)(param_1 + 0x1a48) = 0;
  *(undefined4 *)(param_1 + 0x248) = 0xc;
  *(undefined4 *)(((unsigned char *)0x00001600) + param_1) = 3;
  *(undefined4 *)(param_1 + 0x1b74) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29ac) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x29bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1b70) = 0xffffffff;
  iVar10 = 0x10;
  uVar6 = 0;
  *(uint *)(param_1 + 0x2cc) = uVar8 & 0xc02fffff | 0x40200000;
  *(undefined4 *)(param_1 + 0x1ef8) = 0xaaaaaaaa;
  iVar5 = iVar9;
  do {
    *(undefined4 *)(iVar5 + 0x98) = 0;
    iVar5 = iVar5 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  *(undefined1 *)(param_1 + 0x2d1) = 0;
  uVar8 = *(uint *)(param_1 + 0x284);
  iVar5 = *(int *)(param_1 + 0x244);
  *(uint *)(param_1 + 0x1ae4) = *(uint *)(param_1 + 0x1ae4) & 0xffffffef;
  *(uint *)(param_1 + 0x2cc) = *(uint *)(param_1 + 0x2cc) & 0xfff5ffff;
  ((unsigned char *)0x000016d0)[param_1] = (byte)(*(uint *)(param_1 + 0x154) >> 6) & 1;
  *(uint *)(param_1 + 0x284) = uVar8 & 0xff8220ff;
  ((unsigned char *)0x000016d1)[param_1] = (byte)(*(uint *)(param_1 + 0x154) >> 7) & 1;
  *(undefined1 *)(iVar5 + 0xf6) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x244) + 0xf5) = 1;
  *(undefined1 *)(param_1 + 0x269) = 0;
  *(undefined4 *)(((unsigned char *)0x00001634) + param_1) = 0x100;
  *(undefined4 *)(param_1 + 0x2694) = 0;
  *(undefined **)(param_1 + 0x2168) = ((unsigned char *)0x0000101dU);
  *(undefined4 *)(0x00002688 + param_1) = 0x200;
  *(undefined4 *)(param_1 + 0x1e20) = 0x400;
  *(undefined4 *)(param_1 + 0x268c) = 0x406;
  iVar5 = *(int *)(param_1 + 0x244);
  uVar8 = *(uint *)(iVar5 + 0x24) & 0x7ff00000;
  if ((((uVar8 == 0x800000) || (uVar8 == 0x100000)) || (uVar8 == 0x200000)) || (uVar8 == 0x400000))
  {
    *(undefined4 *)(param_1 + 0x1e20) = 0x600;
    *(undefined4 *)(0x00002688 + param_1) = 0x400;
    *(undefined4 *)(param_1 + 0x268c) = 0x606;
    *(undefined4 *)(((unsigned char *)0x00001634) + param_1) = 0x400;
    *(undefined **)(param_1 + 0x2168) = ((unsigned char *)0x0000101dU);
    uVar8 = *(uint *)(iVar5 + 0x24) & 0x7ff00000;
    if (uVar8 == 0x800000) {
      *(uint *)(param_1 + 0x2694) = *(uint *)(param_1 + 0x2694) | 0x80000000;
    }
    else if (uVar8 == 0x100000) {
      *(uint *)(param_1 + 0x2694) = *(uint *)(param_1 + 0x2694) | 0x40000000;
    }
    else if (uVar8 == 0x200000) {
      *(uint *)(param_1 + 0x2694) = *(uint *)(param_1 + 0x2694) | 0x8000000;
    }
    else if (uVar8 == 0x400000) {
      *(uint *)(param_1 + 0x2694) = *(uint *)(param_1 + 0x2694) | 0x2000000;
    }
  }
  uVar7 = 0;
  FUN_000b6020(iVar9,0,0);
  *(undefined1 *)(param_1 + 0x1aa9) = 0;
  *(undefined1 *)(param_1 + 0x1aa8) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  FUN_000ab900(iVar9);
  puVar2 = PTR_FUN_001e8b18;
  cVar1 = *(char *)(param_1 + 0x1aa8);
  *(undefined **)(((unsigned char *)0x000014f0) + param_1) = PTR_FUN_001e8a20;
  *(undefined **)(((unsigned char *)0x000014f4) + param_1) = puVar2;
  if (cVar1 == '\0') {
    *(undefined **)(((unsigned char *)0x000014f8) + param_1) = PTR_FUN_001e8a60;
  }
  else {
    *(undefined **)(((unsigned char *)0x000014f8) + param_1) = PTR_FUN_001e8af4;
  }
  puVar2 = PTR_FUN_001e8ac4;
  *(undefined **)(((unsigned char *)0x0000157c) + param_1) = PTR_FUN_001e8a44;
  *(undefined **)(((unsigned char *)0x00001580) + param_1) = puVar2;
  puVar3 = PTR_FUN_001e8aac;
  puVar2 = PTR_FUN_001e8a38;
  if (cVar1 == '\0') {
    *(undefined4 *)(((unsigned char *)0x0000151c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x000014fc) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001514) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001518) + param_1) = 0;
    puVar2 = PTR_FUN_001e8b20;
    *(undefined **)(((unsigned char *)0x00001500) + param_1) = PTR_FUN_001e8a84;
    *(undefined **)(((unsigned char *)0x00001510) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a4c;
    *(undefined **)(((unsigned char *)0x00001504) + param_1) = PTR_FUN_001e8a14;
    *(undefined **)(((unsigned char *)0x00001524) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8b30;
    *(undefined **)(((unsigned char *)0x00001520) + param_1) = PTR_FUN_001e8b0c;
    *(undefined **)(((unsigned char *)0x0000152c) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a30;
    *(undefined **)(((unsigned char *)0x00001528) + param_1) = PTR_FUN_001e8af8;
    *(undefined **)(((unsigned char *)0x00001534) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a5c;
    *(undefined **)(((unsigned char *)0x00001530) + param_1) = PTR_FUN_001e8a80;
    *(undefined **)(((unsigned char *)0x0000153c) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a28;
    *(undefined **)(((unsigned char *)0x00001538) + param_1) = PTR_FUN_001e8aec;
    *(undefined **)(((unsigned char *)0x00001544) + param_1) = puVar2;
    *(undefined **)(((unsigned char *)0x00001540) + param_1) = PTR_FUN_001e8a90;
    *(undefined **)(((unsigned char *)0x00001548) + param_1) = PTR_FUN_001e8a24;
    *(undefined **)(((unsigned char *)0x0000154c) + param_1) = PTR_FUN_001e8a1c;
    puVar2 = PTR_FUN_001e8a34;
    *(undefined **)(((unsigned char *)0x00001550) + param_1) = PTR_FUN_001e8a78;
    *(undefined **)(((unsigned char *)0x00001554) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a00;
    *(undefined **)(((unsigned char *)0x00001558) + param_1) = PTR_FUN_001e8b2c;
    *(undefined **)(((unsigned char *)0x0000155c) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8b24;
    *(undefined **)(((unsigned char *)0x00001560) + param_1) = PTR_FUN_001e8a8c;
    *(undefined **)(((unsigned char *)0x00001564) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8ad4;
    *(undefined **)(((unsigned char *)0x00001568) + param_1) = PTR_FUN_001e89f8;
    *(undefined **)(((unsigned char *)0x0000156c) + param_1) = puVar2;
  }
  else {
    *(undefined4 *)(((unsigned char *)0x00001520) + param_1) = 0;
    *(undefined **)(((unsigned char *)0x000014fc) + param_1) = puVar3;
    *(undefined **)(((unsigned char *)0x00001500) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a50;
    *(undefined **)(((unsigned char *)0x00001510) + param_1) = PTR_FUN_001e8ad0;
    *(undefined **)(((unsigned char *)0x00001504) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8b34;
    *(undefined **)(((unsigned char *)0x00001514) + param_1) = PTR_FUN_001e8b08;
    *(undefined **)(((unsigned char *)0x00001518) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a64;
    *(undefined **)(((unsigned char *)0x0000151c) + param_1) = PTR_FUN_001e8a70;
    *(undefined **)(((unsigned char *)0x00001528) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8ac0;
    *(undefined **)(((unsigned char *)0x00001524) + param_1) = PTR_FUN_001e8a10;
    *(undefined **)(((unsigned char *)0x00001530) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a7c;
    *(undefined **)(((unsigned char *)0x0000152c) + param_1) = PTR_FUN_001e8a74;
    *(undefined **)(((unsigned char *)0x00001538) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8ab4;
    *(undefined **)(((unsigned char *)0x00001534) + param_1) = PTR_FUN_001e8af0;
    *(undefined **)(((unsigned char *)0x00001540) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8adc;
    *(undefined **)(((unsigned char *)0x0000153c) + param_1) = PTR_FUN_001e8a0c;
    *(undefined **)(((unsigned char *)0x00001544) + param_1) = PTR_FUN_001e8a40;
    *(undefined **)(((unsigned char *)0x00001548) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a98;
    *(undefined **)(((unsigned char *)0x0000154c) + param_1) = PTR_FUN_001e8b10;
    *(undefined **)(((unsigned char *)0x00001550) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8a9c;
    *(undefined **)(((unsigned char *)0x00001554) + param_1) = PTR_FUN_001e8a54;
    *(undefined **)(((unsigned char *)0x00001558) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8ab8;
    *(undefined **)(((unsigned char *)0x0000155c) + param_1) = PTR_FUN_001e8b04;
    *(undefined **)(((unsigned char *)0x00001560) + param_1) = puVar2;
    puVar2 = PTR_FUN_001e8ad8;
    *(undefined **)(((unsigned char *)0x00001564) + param_1) = PTR_FUN_001e8a94;
    *(undefined **)(((unsigned char *)0x00001568) + param_1) = puVar2;
    *(undefined **)(((unsigned char *)0x0000156c) + param_1) = PTR_FUN_001e8b1c;
  }
  *(code **)(((unsigned char *)0x00001588) + param_1) = FUN_000a6f90;
  FUN_0009bd60(iVar9,0x80);
  pcVar4 = *(code **)(param_1 + 0x250);
  *(undefined1 *)(param_1 + 0x2691) = 0;
  *(undefined1 *)(param_1 + 0x365) = 0;
  *(undefined1 *)(param_1 + 0x36b) = 1;
  *(undefined2 *)(param_1 + 0x20ac) = 1;
  *(undefined1 *)(param_1 + 0x366) = 1;
  *(undefined1 *)(param_1 + 0x364) = 1;
  *(undefined4 *)(param_1 + 0x37c) = 1;
  ((unsigned char *)0x00002b81)[param_1] = 1;
  uVar7 = (*pcVar4)(1,((unsigned char *)0x00003754U),uVar7,in_r6,a4,uVar6,0);
  *(undefined4 *)(param_1 + 0x20a0) = uVar7;
  FUN_0004ab60(iVar9);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x20a0)) = 0xffff;
  *(undefined4 *)(((unsigned char *)0x0000135c) + param_1) = 5;
  uVar7 = (**(code **)(param_1 + 0x250))(1,0x14);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined2 *)(((unsigned char *)0x00001350) + param_1) = 5;
  *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = uVar7;
  uVar7 = (*pcVar4)(10);
  *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = uVar7;
  iVar5 = (uint)*(ushort *)(((unsigned char *)0x00001350) + param_1) << 1;
  _memset(uVar7,0xff,iVar5);
  pcVar4 = *(code **)(param_1 + 0x24c);
  *(undefined4 *)(0x000020b4 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x20b8) = 0x10;
  uVar6 = (*pcVar4)(0x40,a1,iVar5,in_r6,a4,uVar6,pcVar4);
  *(undefined4 *)(param_1 + 0x20bc) = uVar6;
  FUN_0004f720(iVar9);
  puVar2 = PTR_FUN_001e8afc;
  *(undefined **)(((unsigned char *)0x000013e0) + param_1) = PTR_FUN_001e89c4;
  *(undefined **)(((unsigned char *)0x00001398) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e89fc;
  *(code **)(((unsigned char *)0x0000139c) + param_1) = FUN_000a6f80;
  puVar3 = PTR_FUN_001e8a6c;
  *(undefined **)(((unsigned char *)0x000014b4) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e8a68;
  *(undefined **)(((unsigned char *)0x000014b8) + param_1) = puVar3;
  puVar3 = PTR_FUN_001e8a88;
  *(undefined **)(((unsigned char *)0x000014bc) + param_1) = puVar2;
  *(undefined **)(((unsigned char *)0x00001464) + param_1) = puVar3;
  ((int (*)())FUN_000a2530)(iVar9);
  FUN_000a0ef0(iVar9);
  FUN_0008f760(iVar9);
  *(undefined1 *)(param_1 + 0x26f) = 1;
  puVar2 = PTR_FUN_001e8a04;
  *(undefined **)(((unsigned char *)0x00001570) + param_1) = PTR_FUN_001e8ac8;
  *(undefined **)(((unsigned char *)0x00001574) + param_1) = puVar2;
  puVar2 = PTR_FUN_001e89f4;
  *(undefined **)(((unsigned char *)0x00001578) + param_1) = PTR_DAT_001e8ae4;
  *(undefined **)(((unsigned char *)0x00002b8c) + param_1) = puVar2;
  return;
}

/* FUN_000a7970 @ 0xa7970 (240 bytes) */
int FUN_000a7970(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + 0x240;
  ((int (*)())FUN_000a4490)(iVar1);
  ((int (*)())FUN_000a43f0)(iVar1);
  FUN_000b5fb0(iVar1);
  FUN_0004b710(iVar1);
  FUN_0009c700(iVar1);
  if (*(int *)(((unsigned char *)0x00001358) + param_1) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(((unsigned char *)0x00001358) + param_1));
    *(undefined4 *)(((unsigned char *)0x00001358) + param_1) = 0;
  }
  if (*(int *)(((unsigned char *)0x00001354) + param_1) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(((unsigned char *)0x00001354) + param_1));
    *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
  }
  if (*(int *)(param_1 + 0x20bc) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x20bc));
    *(undefined4 *)(param_1 + 0x20b8) = 0;
    *(undefined4 *)(param_1 + 0x20bc) = 0;
    *(undefined4 *)(0x000020b4 + param_1) = 0;
  }
  FUN_000a0c60(iVar1);
  if (*(int *)(param_1 + 0x1aa4) != 0) {
    (**(code **)(param_1 + 600))(*(int *)(param_1 + 0x1aa4));
    *(undefined4 *)(param_1 + 0x1aa4) = 0;
  }
  return;
}

/* FUN_000a7a60 @ 0xa7a60 (496 bytes) */
int FUN_000a7a60(param_1)
  int param_1;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  puVar1 = PTR_DAT_001e88c8;
  iVar7 = param_1 + 0x240;
  ((unsigned char *)0x000015f8)[param_1] = ((unsigned char *)0x00002b7c)[param_1];
  uVar5 = *(uint *)(param_1 + 0x1ae4);
  uVar2 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18);
  uVar4 = *(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x1c);
  *(uint *)(param_1 + 0x1ae4) = uVar5 & 0xffc0003f;
  piVar3 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  uVar2 = uVar4 >> 0xe & 0xc000 |
          uVar4 >> 0x12 & 0x3000 | (uVar2 & 6) << 9 | (uVar2 & 0x18) << 5 | uVar2 >> 5 & 0x1f;
  if (piVar3 == (int *)0x0) {
    uVar4 = 0;
    iVar8 = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(((unsigned char *)0x00002dba) + uVar4 * 2 + *(int *)(param_1 + 0x10)) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(param_1 + 0x1ae4) =
             ((*(uint *)(param_1 + 0x1ae4) >> 6 | 1 << (uVar4 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(param_1 + 0x1ae4) & 0xffc0003f;
      }
      uVar4 = uVar4 + 1;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  else {
    uVar4 = 0;
    iVar8 = 4;
    iVar6 = iVar7;
    do {
      if (*(short *)(uVar4 * 2 + *piVar3 + 0x90) == 0) {
        *(undefined4 *)(iVar6 + 0x233c) = 0xf;
      }
      else {
        *(uint *)(iVar6 + 0x233c) = uVar2;
        *(uint *)(param_1 + 0x1ae4) =
             ((*(uint *)(param_1 + 0x1ae4) >> 6 | 1 << (uVar4 & 0x3f)) & 0xffff) << 6 |
             *(uint *)(param_1 + 0x1ae4) & 0xffc0003f;
      }
      uVar4 = uVar4 + 1;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  uVar4 = *(uint *)(param_1 + 0x1ae4);
  uVar2 = uVar4 >> 6 & 0xffff;
  if (*(int *)(((unsigned char *)0x00001448) + uVar2 * 4 + iVar7) == 0) {
    FUN_000b6020(iVar7,0,uVar2);
    uVar4 = *(uint *)(param_1 + 0x1ae4);
  }
  if ((((uVar5 >> 6 & 0xffff) != (uVar4 >> 6 & 0xffff)) && ((uVar4 & 0x3fffc0) != 0)) &&
     (((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] == '\0')) {
    FUN_000b6580(iVar7,0);
    (**(code **)(((unsigned char *)0x00002b8c) + param_1))(iVar7,*(undefined4 *)(param_1 + 0x209c));
  }
  *(uint *)(param_1 + 0x1b70) = *(uint *)(param_1 + 0x1b70) | 0x40;
  return;
}

/* FUN_000a7c60 @ 0xa7c60 (176 bytes) */
int FUN_000a7c60(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
  *(undefined1 *)(param_1 + 0x2d) = 0xf;
  *(undefined1 *)(param_1 + 0x2e) = 3;
  *(undefined1 *)(param_1 + 0x30) = 7;
  *(undefined1 *)(param_1 + 0x2c) = 0xff;
  *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
  *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
  *(undefined2 *)(param_1 + 0x32) = 0xffff;
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
  *(undefined4 *)(param_1 + 0x180c) = 5;
  *(undefined4 *)(param_1 + 0x1810) = 0x1f;
  *(undefined1 *)(param_1 + 0x2a) = 1;
  if (uVar2 != 0) {
    iVar1 = param_1;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    do {
      *(undefined1 *)(iVar1 + 0x1814) = 0x3f;
      *(undefined1 *)(iVar1 + 0x181c) = 3;
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  return;
}

