#include "decls.h"

/* FUN_00051ea5 @ 0x51ea5 (22 bytes) */
int FUN_00051ea5(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x1168) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x1168) + 0x10) = 0;
  }
  return;
}

/* FUN_00051ebb @ 0x51ebb (199 bytes) */
int FUN_00051ebb(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x1168);
  if ((iVar1 == 0) || (param_2 != *(int *)(iVar1 + 8))) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x116c) + 4);
    if (iVar1 == 0) {
LAB_00051f35:
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      param_3[4] = 0;
      return;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x116c) + 0xc);
    iVar3 = 0;
    do {
      iVar4 = 0;
      if (*(int *)(iVar2 + 8) == param_2) {
        iVar4 = iVar2;
      }
      iVar3 = iVar3 + 1;
      if (iVar3 == iVar1) {
        if (iVar4 == 0) goto LAB_00051f35;
        break;
      }
      iVar2 = iVar2 + 0x7c;
    } while (iVar4 == 0);
    *param_3 = *(undefined4 *)(iVar4 + 0x54);
    param_3[1] = *(int *)(iVar4 + 0x5c) + *(int *)(iVar4 + 0x60);
    param_3[2] = *(undefined4 *)(iVar4 + 100);
    param_3[3] = *(undefined4 *)(iVar4 + 0x58);
    param_3[4] = *(undefined4 *)(iVar4 + 0x68);
  }
  else {
    *param_3 = *(undefined4 *)(iVar1 + 0x54);
    param_3[1] = *(int *)(iVar1 + 0x5c) + *(int *)(iVar1 + 0x60);
    param_3[2] = *(undefined4 *)(iVar1 + 100);
    param_3[3] = *(undefined4 *)(iVar1 + 0x58);
    param_3[4] = *(undefined4 *)(iVar1 + 0x68);
  }
  return;
}

/* FUN_00051f82 @ 0x51f82 (75 bytes) */
int FUN_00051f82(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x1168);
  if ((iVar2 != 0) && (*(byte *)(param_1 + 0x13b0) != 0)) {
    uVar1 = 0;
    uVar3 = 0;
    do {
      if (*(char *)(iVar2 + 0x71) != '\0') {
        uVar3 = uVar3 | 1 << ((byte)uVar1 & 0x1f);
      }
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 1;
    } while (uVar1 < *(byte *)(param_1 + 0x13b0));
    return uVar3;
  }
  return 0;
}

/* FUN_00051fcd @ 0x51fcd (247 bytes) */
int FUN_00051fcd(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_3 + param_2 & 0x1f;
  piVar2 = *(int **)(*(int *)(param_1 + 0x116c) + 0x28 + uVar3 * 4);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      iVar4 = *(int *)(param_1 + 0x116c) + 0x14;
      iVar1 = ((int (*)())FUN_00053d4c)(param_1,iVar4,param_4,param_5,0x87e1,0,0,param_3);
      if (iVar1 == 0) {
        return 0;
      }
      iVar4 = ((int (*)())FUN_000540d3)(iVar4,iVar1);
      *(int *)(iVar4 + 0x48) = param_2;
      *(int *)(iVar4 + 0x4c) = param_3;
      *(undefined4 *)(iVar4 + 0x50) = param_6;
      *(undefined1 *)(iVar4 + 0x44) = 1;
      piVar2 = (int *)(**(code **)(param_1 + 0xc))(0x10);
      *piVar2 = param_2;
      piVar2[1] = param_3;
      piVar2[2] = iVar1;
      piVar2[3] = *(int *)(*(int *)(param_1 + 0x116c) + 0x28 + uVar3 * 4);
      *(int **)(*(int *)(param_1 + 0x116c) + 0x28 + uVar3 * 4) = piVar2;
      return iVar1;
    }
    if ((param_2 == *piVar2) && (param_3 == piVar2[1])) break;
    piVar2 = (int *)piVar2[3];
  }
  return piVar2[2];
}

/* FUN_000520c4 @ 0x520c4 (331 bytes) */
int FUN_000520c4(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  undefined4 uVar1;
  int local_14;
  uint local_10;
  
  if (((param_2 - 0x87beU < 3) &&
      (((((param_3 - 0x87c1U < 2 || (param_3 == 0x87c4)) || (param_3 == 0x87c3)) ||
        ((param_3 == -3 || (param_3 == -2)))) || (param_3 == -1)))) && (param_4 - 0x87e0U < 2)) {
    if (((param_3 - 0x87c3U < 2) || (param_3 == -3)) || ((param_3 == -2 || (param_3 == -1)))) {
      if (*(char *)(param_1 + 0x1170) == '\0') goto LAB_00052113;
      local_14 = *(int *)(param_1 + 0x1168) + 0x1c;
    }
    else {
      local_14 = *(int *)(param_1 + 0x116c) + 0x14;
    }
    uVar1 = ((int (*)())FUN_00053d4c)(param_1,local_14,param_2,param_3,param_4,0,param_5,param_6);
    if (1 < param_5) {
      local_10 = 1;
      do {
        ((int (*)())FUN_00053d4c)(param_1,local_14,param_2,param_3,param_4,uVar1,param_5 - local_10,
                     local_10 + param_6);
        local_10 = local_10 + 1;
      } while (param_5 != local_10);
    }
  }
  else {
LAB_00052113:
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_0005220f @ 0x5220f (244 bytes) */
int FUN_0005220f(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  byte *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18 [3];
  
  iVar2 = *(int *)(param_1 + 0x1168) + 0x1c;
  local_18[0] = 0xfffffffd;
  local_18[1] = 0x87c3;
  local_18[2] = 0x87c2;
  uVar1 = ((int (*)())FUN_00053d4c)(param_1,iVar2,0x87bf,local_18[*param_3],0x87e1,0,param_2,*param_4);
  *param_5 = uVar1;
  if (param_2 < 2) {
    return;
  }
  uVar3 = 1;
  do {
    uVar1 = ((int (*)())FUN_00053d4c)(param_1,iVar2,0x87bf,local_18[param_3[uVar3]],0x87e1,*param_5,
                         param_2 - uVar3,param_4[uVar3]);
    param_5[uVar3] = uVar1;
    uVar3 = uVar3 + 1;
  } while (param_2 != uVar3);
  return;
}

/* FUN_00052303 @ 0x52303 (29 bytes) */
int FUN_00052303()
{
  undefined4 uStack00000004;
  
  uStack00000004 = 0x87e1;
  ((int (*)())FUN_000520c4)();
  return;
}

/* FUN_00052320 @ 0x52320 (47 bytes) */
int FUN_00052320()
{
  ((int (*)())FUN_00051fcd)(0x87bf,0xfffffffc,0);
  return;
}

/* FUN_0005234f @ 0x5234f (113 bytes) */
int FUN_0005234f(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (*(char *)(param_1 + 0x1170) != '\0') {
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,param_4,param_5,param_6,0
                 ,&DAT_001ee590,0,&DAT_001ee590);
  }
  return;
}

/* FUN_000523c0 @ 0x523c0 (115 bytes) */
int FUN_000523c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (*(char *)(param_1 + 0x1170) != '\0') {
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,param_4,param_5,param_6,
                 param_7,param_8,0,&DAT_001ee590);
  }
  return;
}

/* FUN_00052433 @ 0x52433 (103 bytes) */
int FUN_00052433(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
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
  if (*(char *)(param_1 + 0x1170) == '\0') {
    return;
  }
  ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,param_4,param_5,param_6,
               param_7,param_8,param_9,param_10);
  return;
}

/* FUN_0005249a @ 0x5249a (238 bytes) */
int FUN_0005249a(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  int iVar1;
  char cVar2;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (((((*(char *)(param_1 + 0x1170) != '\0') && (param_5 - 0x87d5U < 0xb)) && (0x87d4 < param_6))
      && ((param_6 < 0x87e0 && (0x87d4 < param_7)))) &&
     ((param_7 < 0x87e0 && ((0x87d4 < param_8 && (param_8 < 0x87e0)))))) {
    iVar1 = *(int *)(param_1 + 0x1168);
    local_1c = param_5;
    local_18 = param_6;
    local_14 = param_7;
    local_10 = param_8;
    cVar2 = ((int (*)())FUN_00053b5b)(param_1,iVar1,0x879a,param_2,param_3,param_4,&local_1c,0,&DAT_001ee590,0,
                         &DAT_001ee590);
    if ((cVar2 != '\0') && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)(param_2 + -0x8759 + iVar1) = 1;
    }
  }
  return;
}

/* FUN_00052588 @ 0x52588 (136 bytes) */
int FUN_00052588(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x1170) == '\0') {
    *(undefined1 *)(param_1 + 0x1170) = 1;
    uVar1 = *(undefined4 *)(param_1 + 0x1168);
    ((int (*)())FUN_00053ae3)(param_1,uVar1);
    ((int (*)())FUN_000541f3)(param_1,uVar1);
    *(undefined4 *)(param_1 + 0x1174) = 0;
    *(undefined4 *)(param_1 + 0x117c) = 0;
    *(undefined4 *)(param_1 + 0x1178) = 0;
    *(undefined4 *)(param_1 + 0x1180) = 0;
    *(undefined4 *)(param_1 + 0x1184) = 0;
    if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
      return;
    }
  }
  return;
}

/* FUN_00052610 @ 0x52610 (155 bytes) */
int FUN_00052610(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1170) != '\0') {
    *(undefined1 *)(param_1 + 0x1170) = 0;
    iVar1 = *(int *)(param_1 + 0x1168);
    FUN_000b7a8e(param_1,iVar1);
    (**(code **)(param_1 + 0x1190))(param_1,iVar1);
    (**(code **)(param_1 + 0x1194))(param_1,iVar1);
    (**(code **)(param_1 + 0x119c))(param_1,iVar1);
    *(undefined4 *)(param_1 + 0x1174) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(param_1 + 0x117c) = *(undefined4 *)(iVar1 + 0x58);
    *(undefined4 *)(param_1 + 0x1178) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(param_1 + 0x1180) = *(undefined4 *)(iVar1 + 0x60);
    *(undefined4 *)(param_1 + 0x1184) = *(undefined4 *)(iVar1 + 100);
    if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
      return;
    }
  }
  return;
}

/* FUN_000526ab @ 0x526ab (67 bytes) */
int FUN_000526ab(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (param_2 == *(int *)(*(int *)(param_1 + 0xc) + 8)) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(param_1 + 0xc) + 0x84);
    iVar2 = 0;
    while (iVar2 = iVar2 + 1, iVar2 != *(int *)(param_1 + 4)) {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x1f;
      if (param_2 == iVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* FUN_000526ee @ 0x526ee (65 bytes) */
int FUN_000526ee(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x116c);
  iVar2 = ((int (*)())FUN_000526ab)();
  if (-1 < iVar2) {
    return iVar2 * 0x7c + *(int *)(iVar1 + 0xc);
  }
  return 0;
}

/* FUN_0005272f @ 0x5272f (549 bytes) */
int FUN_0005272f(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  iVar5 = *(int *)(param_1 + 0x116c);
  iVar3 = *(int *)(*(int *)(param_1 + 0x1168) + 0xc);
  if (iVar3 != 0) {
    *(int *)(*(int *)(param_1 + 0x1168) + 0xc) = iVar3 + -1;
  }
  if (*(char *)(param_1 + 0x1170) == '\0') {
    iVar3 = ((int (*)())FUN_000526ab)();
    if (iVar3 < 0) {
      uVar6 = *(uint *)(iVar5 + 4);
      if ((uVar6 & 0xf) == 0) {
        iVar3 = (**(code **)(param_1 + 0xc))(uVar6 * 0x7c + 0x7c0);
        if (iVar3 == 0) {
          return;
        }
        (**(code **)(param_1 + 0x1344))
                  (iVar3,*(undefined4 *)(iVar5 + 0xc),*(int *)(iVar5 + 4) * 0x7c);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0xc));
        *(int *)(iVar5 + 0xc) = iVar3;
        ((int (*)())FUN_00054338)(param_1);
        uVar6 = *(uint *)(iVar5 + 4);
      }
      ((int (*)())FUN_000541f3)(param_1,uVar6 * 0x7c + *(int *)(iVar5 + 0xc));
      *(undefined4 *)(*(int *)(iVar5 + 4) * 0x7c + 8 + *(int *)(iVar5 + 0xc)) = param_2;
      *(undefined4 *)(param_1 + 0x1188) = *(undefined4 *)(iVar5 + 4);
      *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
      *(undefined4 *)(param_1 + 0x1174) = 0;
      *(undefined4 *)(param_1 + 0x117c) = 0;
      *(undefined4 *)(param_1 + 0x1178) = 0;
      *(undefined4 *)(param_1 + 0x1180) = 0;
      *(undefined4 *)(param_1 + 0x1184) = 0;
    }
    else {
      iVar4 = iVar3 * 0x7c + *(int *)(iVar5 + 0xc);
      *(int *)(param_1 + 0x1188) = iVar3;
      *(undefined4 *)(param_1 + 0x1174) = *(undefined4 *)(iVar4 + 0x54);
      *(undefined4 *)(param_1 + 0x117c) = *(undefined4 *)(iVar4 + 0x58);
      *(undefined4 *)(param_1 + 0x1178) = *(undefined4 *)(iVar4 + 0x5c);
      *(undefined4 *)(param_1 + 0x1180) = *(undefined4 *)(iVar4 + 0x60);
      *(undefined4 *)(param_1 + 0x1184) = *(undefined4 *)(iVar4 + 100);
    }
    iVar5 = *(int *)(param_1 + 0x1188) * 0x7c + *(int *)(iVar5 + 0xc);
    *(int *)(param_1 + 0x1168) = iVar5;
    piVar1 = (int *)(iVar5 + 0xc);
    *piVar1 = *piVar1 + 1;
    if ((*(byte *)(param_1 + 0x45) & 1) != 0) {
      bVar2 = *(byte *)(param_1 + 0x18a4);
      if ((*(byte *)(param_1 + 0x45) & 8) == 0) {
        if ((((*(byte *)(param_1 + 0x44) & 1) == 0) ||
            (*(short *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x2d48) != -0x7e06)) &&
           ((*(ushort *)(param_1 + 0x44) & 0x101) != 0x100)) {
          bVar7 = false;
        }
        else {
          bVar7 = true;
        }
      }
      else {
        bVar7 = *(char *)(*(int *)(param_1 + 0x1168) + 0x6e) != '\0';
      }
      *(byte *)(param_1 + 0x18a4) = bVar2 & 0xfb | bVar7 << 2;
      if ((bool)(bVar2 >> 2 & 1) != bVar7) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
        *(undefined1 *)(param_1 + 0x29) = 1;
        return;
      }
    }
  }
  return;
}

/* FUN_00052954 @ 0x52954 (9 bytes) */
int FUN_00052954()
{
  ((int (*)())FUN_0005272f)();
  return;
}

/* FUN_0005295d @ 0x5295d (25 bytes) */
int FUN_0005295d(param_1, param_2)
  int param_1;
  int param_2;
{
  *(int *)(*(int *)(param_1 + 0x116c) + 8) = *(int *)(*(int *)(param_1 + 0x116c) + 8) + param_2;
  return;
}

/* FUN_00052976 @ 0x52976 (280 bytes) */
int FUN_00052976(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x116c);
  if (*(int *)(*(int *)(param_1 + 0x1168) + 8) == param_2) {
    ((int (*)())FUN_0005272f)(param_1,0);
  }
  uVar5 = 0;
  bVar2 = false;
  iVar3 = 0;
  while (uVar5 < *(uint *)(iVar1 + 4)) {
    while( true ) {
      if (bVar2) goto LAB_000529da;
      if (param_2 == *(int *)(iVar3 + 8 + *(int *)(iVar1 + 0xc))) break;
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 0x7c;
      if (*(uint *)(iVar1 + 4) <= uVar5) goto LAB_000529d6;
    }
    bVar2 = true;
  }
LAB_000529d6:
  if (bVar2) {
LAB_000529da:
    iVar3 = uVar5 * 0x7c + *(int *)(iVar1 + 0xc);
    if (*(int *)(iVar3 + 0xc) == 0) {
      ((int (*)())FUN_00053ae3)(param_1,iVar3);
      pvVar4 = (void *)(*(int *)(iVar1 + 0xc) + uVar5 * 0x7c);
      _memmove(pvVar4,(void *)((int)pvVar4 + 0x7c),(*(int *)(iVar1 + 4) - uVar5) * 0x7c - 0x7c);
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + -1;
      if (uVar5 < *(uint *)(param_1 + 0x1188)) {
        iVar3 = *(uint *)(param_1 + 0x1188) - 1;
        *(int *)(param_1 + 0x1188) = iVar3;
        *(int *)(param_1 + 0x1168) = iVar3 * 0x7c + *(int *)(iVar1 + 0xc);
        return;
      }
    }
  }
  return;
}

/* FUN_00052a8e @ 0x52a8e (18 bytes) */
int FUN_00052a8e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  ((int (*)())FUN_00052976)();
  return;
}

/* FUN_00052aa0 @ 0x52aa0 (113 bytes) */
int FUN_00052aa0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  if (*(char *)(param_1 + 0x1170) != '\0') {
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,&DAT_001ee5a0,param_4,
                 &DAT_001ee590,0,&DAT_001ee590,0,&DAT_001ee590);
  }
  return;
}

/* FUN_00052b11 @ 0x52b11 (112 bytes) */
int FUN_00052b11(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if (*(char *)(param_1 + 0x1170) != '\0') {
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,&DAT_001ee5a0,param_4,
                 &DAT_001ee590,param_5,&DAT_001ee590,0,&DAT_001ee590);
  }
  return;
}

/* FUN_00052b81 @ 0x52b81 (111 bytes) */
int FUN_00052b81(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (*(char *)(param_1 + 0x1170) != '\0') {
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),param_2,param_3,&DAT_001ee5a0,param_4,
                 &DAT_001ee590,param_5,&DAT_001ee590,param_6,&DAT_001ee590);
  }
  return;
}

/* FUN_00052bf0 @ 0x52bf0 (241 bytes) */
int FUN_00052bf0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  int iVar1;
  char cVar2;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (((((*(char *)(param_1 + 0x1170) != '\0') && (param_4 - 0x87d5U < 0xb)) && (0x87d4 < param_5))
      && ((param_5 < 0x87e0 && (0x87d4 < param_6)))) &&
     ((param_6 < 0x87e0 && ((0x87d4 < param_7 && (param_7 < 0x87e0)))))) {
    iVar1 = *(int *)(param_1 + 0x1168);
    local_1c = param_4;
    local_18 = param_5;
    local_14 = param_6;
    local_10 = param_7;
    cVar2 = ((int (*)())FUN_00053b5b)(param_1,iVar1,0x879a,param_2,&DAT_001ee5a0,param_3,&local_1c,0,
                         &DAT_001ee590,0,&DAT_001ee590);
    if ((cVar2 != '\0') && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)(param_2 + -0x8759 + iVar1) = 1;
    }
  }
  return;
}

/* FUN_00052ce1 @ 0x52ce1 (164 bytes) */
int FUN_00052ce1(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if ((((*(char *)(param_1 + 0x1170) != '\0') && (param_4 < 2)) && (param_5 < 2)) &&
     ((param_6 < 2 && (param_7 < 2)))) {
    local_1c = param_4;
    local_18 = param_5;
    local_14 = param_6;
    local_10 = param_7;
    ((int (*)())FUN_00053b5b)(param_1,*(undefined4 *)(param_1 + 0x1168),0x879b,param_2,&local_1c,param_3,
                 &DAT_001ee590,0,&DAT_001ee590,0,&DAT_001ee590);
  }
  return;
}

/* FUN_00052d85 @ 0x52d85 (303 bytes) */
int FUN_00052d85(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  int iVar1;
  char cVar2;
  int iVar3;
  
  if ((*(char *)(param_1 + 0x1170) != '\0') && (param_4 < 4)) {
    iVar3 = *(int *)(param_1 + 0x1168);
    cVar2 = ((int (*)())FUN_00053b5b)(param_1,iVar3,&UINT_0000879c,param_2,&DAT_001ee5a0,param_3,&DAT_001ee590,0,
                         &DAT_001ee590,0,&DAT_001ee590);
    if (cVar2 != '\0') {
      iVar1 = *(int *)(iVar3 + 0x18) + *(int *)(iVar3 + 0x14) * 0x74;
      iVar3 = ((int (*)())FUN_00053994)(iVar3 + 0x1c,iVar1 + -0x70);
      if (iVar3 == 0x87bf) {
        if (param_4 == 1) {
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
          *(undefined4 *)(iVar1 + -0x5c) = 0;
        }
        else if (param_4 == 0) {
          *(undefined4 *)(iVar1 + -100) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
          *(undefined4 *)(iVar1 + -0x5c) = 0;
        }
        else if (param_4 == 2) {
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
          *(undefined4 *)(iVar1 + -0x5c) = 0;
        }
        else if (param_4 == 3) {
          *(undefined4 *)(iVar1 + -0x68) = 0;
          *(undefined4 *)(iVar1 + -100) = 0;
          *(undefined4 *)(iVar1 + -0x60) = 0;
        }
      }
      *(uint *)(iVar1 + -0x34) = param_4;
      return;
    }
  }
  return;
}

/* FUN_00052eb4 @ 0x52eb4 (160 bytes) */
int FUN_00052eb4(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
{
  int iVar1;
  char cVar2;
  
  if ((*(char *)(param_1 + 0x1170) != '\0') && (param_4 < 4)) {
    iVar1 = *(int *)(param_1 + 0x1168);
    cVar2 = ((int (*)())FUN_00053b5b)(param_1,iVar1,0x879d,param_2,&DAT_001ee5a0,param_3,&DAT_001ee590,0,
                         &DAT_001ee590,0,&DAT_001ee590);
    if (cVar2 != '\0') {
      *(uint *)(*(int *)(iVar1 + 0x14) * 0x74 + *(int *)(iVar1 + 0x18) + -0x34) = param_4;
      return;
    }
  }
  return;
}

/* FUN_00052f54 @ 0x52f54 (39 bytes) */
int FUN_00052f54()
{
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  
  uStack0000000c = 0;
  uStack00000008 = in_stack_00000014;
  uStack00000004 = in_stack_00000010;
  ((int (*)())FUN_000520c4)();
  return;
}

/* FUN_00052f7b @ 0x52f7b (191 bytes) */
int FUN_00052f7b(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int *param_3;
  int *param_4;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x1868) == '\0') {
    piVar1 = *(int **)(**(int **)(param_1 + 0x1168) + *(int *)(param_1 + 0x118c) * 4);
    iVar2 = *piVar1;
    *param_3 = piVar1[0x22];
    *param_4 = *(int *)(param_1 + 0x2448) + *(int *)(iVar2 + 0x14);
    iVar3 = *(int *)(iVar2 + 0x2b8);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_1 + 0xc))(0x80c);
      *(int *)(iVar2 + 0x2b8) = iVar3;
      *param_2 = iVar3;
      return 1;
    }
  }
  else {
    piVar1 = (int *)**(int **)(**(int **)(param_1 + 0x1168) + *(int *)(param_1 + 0x118c) * 4);
    *param_3 = piVar1[0x49];
    *param_4 = *(int *)(param_1 + 0x2448) + *piVar1;
    iVar3 = piVar1[0x4f6];
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_1 + 0xc))(0x80c);
      piVar1[0x4f6] = iVar3;
      *param_2 = iVar3;
      return 1;
    }
  }
  *param_2 = iVar3;
  return 0;
}

/* FUN_0005303a @ 0x5303a (295 bytes) */
int FUN_0005303a(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar2 = *(int *)(param_1 + 0x1168);
  if (param_3 != 0) {
    local_10 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    puVar4 = param_2;
    puVar5 = param_2;
    do {
      iVar1 = *(int *)(iVar2 + 0x20) +
              *(int *)(*(int *)(iVar2 + 0x24) + *(int *)(param_4 + local_10 * 4) * 4) * 0x54;
      if (*(char *)(iVar1 + 0x3d) == '\0') {
        if (local_10 < (int)param_2[0x200]) {
          local_18 = local_18 + 1;
        }
        else if (local_10 < (int)param_2[0x201]) {
          local_1c = local_1c + 1;
        }
        else {
          local_14 = local_14 + 1;
        }
      }
      else {
        uVar3 = puVar5[1];
        *puVar4 = *puVar5;
        puVar4[1] = uVar3;
        *(char *)puVar4 = (char)*(undefined4 *)(iVar1 + 4);
        puVar4[1] = *(undefined4 *)(iVar1 + 0x38);
        puVar4 = puVar4 + 2;
      }
      puVar5 = puVar5 + 2;
      local_10 = local_10 + 1;
    } while (local_10 != param_3);
    param_2[0x200] = param_2[0x200] - local_18;
    param_2[0x201] = param_2[0x201] - (local_1c + local_18);
    param_2[0x202] = param_2[0x202] - (local_1c + local_18 + local_14);
    return;
  }
  param_2[0x200] = param_2[0x200];
  param_2[0x201] = param_2[0x201];
  param_2[0x202] = param_2[0x202];
  return;
}

/* FUN_00053161 @ 0x53161 (189 bytes) */
int FUN_00053161(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  (**(code **)(param_1 + 0x11ac))(param_1,param_2,0);
  (**(code **)(param_1 + 0x11a4))(param_1,param_2,*(undefined4 *)(param_1 + 0x118c));
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x58) = 0;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  if (*(int *)(param_2 + 0x1c) != 0) {
    uVar1 = 0;
    iVar2 = 0;
    do {
      *(undefined1 *)(iVar2 + 0x3d + *(int *)(param_2 + 0x20)) = 0;
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 0x54;
    } while (uVar1 < *(uint *)(param_2 + 0x1c));
  }
  (**(code **)(param_1 + 0x1194))(param_1,param_2);
  (**(code **)(param_1 + 0x119c))(param_1,param_2);
  *(undefined4 *)(param_1 + 0x1174) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_1 + 0x117c) = *(undefined4 *)(param_2 + 0x58);
  *(undefined4 *)(param_1 + 0x1178) = *(undefined4 *)(param_2 + 0x5c);
  *(undefined4 *)(param_1 + 0x1180) = *(undefined4 *)(param_2 + 0x60);
  *(undefined4 *)(param_1 + 0x1184) = *(undefined4 *)(param_2 + 100);
  return;
}

/* FUN_0005321e @ 0x5321e (243 bytes) */
int FUN_0005321e(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_3 - 0x1400U < 0xb) {
    iVar1 = *(int *)(param_1 + 0x1168);
    if ((*(char *)(param_1 + 0x31) != '\0') &&
       (*(char *)(*(int *)(iVar1 + 4) + *(int *)(param_1 + 0x118c)) != '\0')) {
      ((int (*)())FUN_00053161)(param_1,iVar1);
    }
    iVar3 = ((int (*)())FUN_000540d3)(iVar1 + 0x1c,param_2);
    if (((iVar3 != 0) && (*(int *)(iVar3 + 0x28) == 0x87c3)) && (*(char *)(iVar3 + 0x44) == '\0')) {
      puVar2 = *(undefined4 **)(iVar3 + 0x38);
      *puVar2 = *param_4;
      puVar2[1] = param_4[1];
      puVar2[2] = param_4[2];
      puVar2[3] = param_4[3];
      *(undefined1 *)(iVar3 + 0x44) = 1;
      iVar3 = ((int (*)())FUN_000540d3)(iVar1 + 0x1c,param_2);
      if ((iVar3 != 0) && (*(char *)(iVar3 + 0x3d) != '\0')) {
        (**(code **)(param_1 + -0x20bac + *(int *)(iVar3 + 0x24) * 4))(param_1,iVar1,iVar3);
      }
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 1;
      return;
    }
  }
  return;
}

/* FUN_00053311 @ 0x53311 (56 bytes) */
int FUN_00053311(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 != 0x87e2) {
    return 0;
  }
  uVar1 = ((int (*)())FUN_00051fcd)(0x87bf,0x87c1,0);
  return uVar1;
}

/* FUN_00053349 @ 0x53349 (201 bytes) */
int FUN_00053349(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_1 + 0x116c);
  if (*(int *)(iVar1 + 4) != 0) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      ((int (*)())FUN_00053ae3)(param_1,iVar3 + *(int *)(iVar1 + 0xc));
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x7c;
    } while (uVar4 < *(uint *)(iVar1 + 4));
  }
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0xc));
  *(undefined4 *)(iVar1 + 4) = 0;
  ((int (*)())FUN_00053a3f)(param_1,iVar1 + 0x14);
  local_10 = 0x20;
  iVar3 = iVar1;
  do {
    iVar2 = *(int *)(iVar3 + 0x28);
    while (iVar2 != 0) {
      *(int *)(iVar3 + 0x28) = *(int *)(iVar2 + 0xc);
      (**(code **)(param_1 + 0x18))(iVar2);
      iVar2 = *(int *)(iVar3 + 0x28);
    }
    iVar3 = iVar3 + 4;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  (**(code **)(param_1 + 0x18))(iVar1);
  *(undefined4 *)(param_1 + 0x116c) = 0;
  return;
}

/* FUN_00053412 @ 0x53412 (58 bytes) */
int FUN_00053412(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x11a8))(param_1);
  **(int **)(param_1 + 0x116c) = **(int **)(param_1 + 0x116c) + -1;
  if (**(int **)(param_1 + 0x116c) != 0) {
    return;
  }
  ((int (*)())FUN_00053349)();
  return;
}

/* FUN_0005344c @ 0x5344c (227 bytes) */
int FUN_0005344c(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x116c);
  uVar1 = (**(code **)(param_1 + 0xc))(0x7c0);
  puVar2[3] = uVar1;
  puVar2[1] = 1;
  puVar2[2] = 1;
  puVar2[4] = 1;
  *puVar2 = 1;
  puVar2[9] = 0;
  ((int (*)())FUN_000541f3)(param_1,uVar1);
  *(undefined4 *)(puVar2[3] + 8) = 0;
  *(undefined4 *)(param_1 + 0x11b4) = 0;
  *(undefined1 *)(param_1 + 0x1170) = 0;
  *(undefined4 *)(param_1 + 0x1188) = 0;
  *(undefined4 *)(param_1 + 0x1174) = 0;
  *(undefined4 *)(param_1 + 0x117c) = 0;
  *(undefined4 *)(param_1 + 0x1178) = 0;
  *(undefined4 *)(param_1 + 0x1180) = 0;
  *(undefined4 *)(param_1 + 0x1184) = 0;
  *(undefined4 *)(param_1 + 0x118c) = 0;
  *(undefined4 *)(param_1 + 0x1168) = puVar2[3];
  (**(code **)(param_1 + 0x11a0))(param_1);
  puVar2[9] = 0;
  ((int (*)())FUN_000540f9)(param_1,puVar2 + 5);
  iVar3 = 0x20;
  do {
    puVar2[10] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

/* FUN_0005352f @ 0x5352f (363 bytes) */
int FUN_0005352f(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  uint local_14;
  int local_10;
  
  **(int **)(param_1 + 0x116c) = **(int **)(param_1 + 0x116c) + -1;
  if (**(int **)(param_1 + 0x116c) == 0) {
    ((int (*)())FUN_00053349)();
  }
  piVar1 = *(int **)(param_2 + 0x116c);
  iVar2 = piVar1[4];
  *(int *)(param_1 + 0x118c) = iVar2;
  piVar1[4] = iVar2 + 1;
  *(undefined1 *)(param_1 + 0x1170) = 0;
  *(undefined4 *)(param_1 + 0x1188) = 0;
  *(int **)(param_1 + 0x116c) = piVar1;
  *(int *)(param_1 + 0x1168) = piVar1[3];
  *piVar1 = *piVar1 + 1;
  if (piVar1[1] == 0) {
    return;
  }
  local_14 = 0;
  local_10 = 0;
  do {
    iVar2 = piVar1[3];
    pvVar3 = *(void **)(local_10 + iVar2);
    uVar4 = (**(code **)(param_1 + 0x10))(piVar1[4],4);
    *(undefined4 *)(local_10 + iVar2) = uVar4;
    _memcpy(*(void **)(piVar1[3] + local_10),pvVar3,piVar1[4] * 4 - 4);
    (**(code **)(param_1 + 0x18))(pvVar3);
    (**(code **)(param_1 + 0x11a4))(param_1,local_10 + piVar1[3],*(undefined4 *)(param_1 + 0x118c));
    iVar2 = piVar1[3];
    pvVar3 = *(void **)(local_10 + iVar2 + 4);
    uVar4 = (**(code **)(param_1 + 0x10))(piVar1[4],1);
    *(undefined4 *)(local_10 + iVar2 + 4) = uVar4;
    _memcpy(*(void **)(local_10 + 4 + piVar1[3]),pvVar3,piVar1[4] - 1);
    (**(code **)(param_1 + 0x18))(pvVar3);
    local_14 = local_14 + 1;
    local_10 = local_10 + 0x7c;
  } while (local_14 < (uint)piVar1[1]);
  return;
}

/* FUN_0005369a @ 0x5369a (26 bytes) */
int FUN_0005369a(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    return *(undefined4 *)(*(int *)(param_1 + 8) + param_2 * 4);
  }
  return 0;
}

/* FUN_000536b4 @ 0x536b4 (324 bytes) */
int FUN_000536b4(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  void *param_3;
{
  uint uVar1;
  uint local_10;
  
  local_10 = *param_2;
  if ((local_10 & 0x3f) == 0) {
    uVar1 = (**(code **)(param_1 + 0xc))(local_10 * 0x54 + 0x1500);
    if (uVar1 != 0) {
      if (param_2[1] != 0) {
        (**(code **)(param_1 + 0x1344))(uVar1,param_2[1],*param_2 * 0x54);
        (**(code **)(param_1 + 0x18))(param_2[1]);
      }
      param_2[1] = uVar1;
      local_10 = *param_2;
      goto LAB_000536c9;
    }
LAB_000537ec:
    local_10 = 0;
  }
  else {
LAB_000536c9:
    _memcpy((void *)(param_2[1] + local_10 * 0x54),param_3,0x54);
    *(undefined1 *)(local_10 * 0x54 + 0x3c + param_2[1]) = 0;
    uVar1 = *(uint *)((int)param_3 + 0x20);
    if (param_2[3] <= uVar1) {
      uVar1 = (**(code **)(param_1 + 0x10))(uVar1 + 0x40,4);
      if (uVar1 == 0) goto LAB_000537ec;
      if (param_2[2] != 0) {
        (**(code **)(param_1 + 0x1344))(uVar1,param_2[2],param_2[3] << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar1;
      param_2[3] = *(int *)((int)param_3 + 0x20) + 0x40;
      uVar1 = *(uint *)((int)param_3 + 0x20);
    }
    *(uint *)(param_2[2] + uVar1 * 4) = local_10;
    *param_2 = *param_2 + 1;
  }
  return local_10;
}

/* FUN_000537f8 @ 0x537f8 (412 bytes) */
int FUN_000537f8(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_24;
  uint local_1c;
  int local_18;
  
  if (param_3 == 0) {
    *param_5 = 0;
    param_5[1] = 0;
    goto LAB_0005381a;
  }
  iVar1 = *(int *)(param_1 + 0x116c);
  *(byte *)(param_5 + 6) = (byte)(param_3 >> 0x1f);
  param_3 = param_3 & 0x7fffffff;
  iVar2 = ((int (*)())FUN_0005369a)(iVar1 + 0x14,param_3);
  if (iVar2 == 0) {
    iVar3 = ((int (*)())FUN_0005369a)(param_2 + 0x1c,param_3);
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    param_2 = param_2 + 0x1c;
    iVar3 = ((int (*)())FUN_0005369a)(param_2,param_3);
    if (iVar3 == 0) {
      local_24 = *(int *)(iVar1 + 0x18);
      local_18 = iVar2 * 0x54;
      iVar3 = local_24 + local_18;
      if (*(int *)(iVar3 + 0x30) == 0) {
        if (*(uint *)(iVar3 + 0x34) < 2) {
          iVar3 = ((int (*)())FUN_000536b4)(param_1,param_2,iVar3);
          goto LAB_00053891;
        }
      }
      else {
        iVar2 = ((int (*)())FUN_0005369a)(iVar1 + 0x14,*(int *)(iVar3 + 0x30));
        local_18 = iVar2 * 0x54;
        iVar3 = local_24 + local_18;
      }
      if (*(int *)(iVar3 + 0x34) != 0) {
        iVar2 = iVar2 * 0x54;
        local_1c = 0;
        do {
          ((int (*)())FUN_000536b4)(param_1,param_2,iVar2 + local_24);
          local_1c = local_1c + 1;
          local_24 = *(int *)(iVar1 + 0x18);
          iVar2 = iVar2 + 0x54;
        } while (local_1c < *(uint *)(local_18 + 0x34 + local_24));
      }
      iVar3 = ((int (*)())FUN_0005369a)(param_2,param_3);
    }
  }
LAB_00053891:
  *param_5 = 2;
  param_5[1] = iVar3;
LAB_0005381a:
  param_5[2] = *param_4;
  param_5[3] = param_4[1];
  param_5[4] = param_4[2];
  param_5[5] = param_4[3];
  return 1;
}

/* FUN_00053994 @ 0x53994 (171 bytes) */
int FUN_00053994(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*param_2 == 1) {
    uVar2 = param_2[1];
    if (uVar2 < 0x6111) {
      if (0x610e < uVar2) {
        return 0x87bf;
      }
      if (uVar2 == 0x610e) {
        return 0x87be;
      }
    }
    else if (0x8799 < uVar2) {
      if (uVar2 < 0x87a5) {
        return 0x87bf;
      }
      if (uVar2 == 0x87bd) {
        return 0x87be;
      }
    }
  }
  else if (*param_2 == 2) {
    iVar1 = *(int *)(param_1 + 4) + param_2[1] * 0x54;
    uVar2 = *(uint *)(iVar1 + 0x28);
    if ((0x87c0 < uVar2) && ((uVar2 < 0x87c5 || (uVar2 == 0xffffffff)))) {
      iVar3 = *(int *)(iVar1 + 0x24);
      if (iVar3 != 0x87bf) {
        if (iVar3 == 0x87c0) {
          return 0x87c0;
        }
        if (iVar3 != 0x87be) {
          return 0;
        }
        if (*(char *)(iVar1 + 0x44) == '\0') {
          return 0x87be;
        }
        if (*(int *)(iVar1 + 0x48) != 0xf) {
          return 0x87be;
        }
      }
      return 0x87bf;
    }
  }
  return 0;
}

/* FUN_00053a3f @ 0x53a3f (164 bytes) */
int FUN_00053a3f(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2[1] != 0) {
    if (*param_2 == 0) {
      uVar2 = param_2[1];
    }
    else {
      uVar4 = 0;
      iVar3 = 0;
      uVar2 = param_2[1];
      do {
        iVar1 = *(int *)(iVar3 + uVar2 + 0x38);
        if ((iVar1 != 0) && (*(char *)(iVar3 + uVar2 + 0x3c) != '\0')) {
          (**(code **)(param_1 + 0x18))(iVar1);
          *(undefined4 *)(iVar3 + 0x38 + param_2[1]) = 0;
          uVar2 = param_2[1];
        }
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x54;
      } while (uVar4 < *param_2);
    }
    (**(code **)(param_1 + 0x18))(uVar2);
    param_2[1] = 0;
    *param_2 = 0;
    (**(code **)(param_1 + 0x18))(param_2[2]);
    param_2[2] = 0;
    param_2[3] = 0;
  }
  return;
}

/* FUN_00053ae3 @ 0x53ae3 (120 bytes) */
int FUN_00053ae3(param_1, param_2)
  int param_1;
  int *param_2;
{
  (**(code **)(param_1 + 0x11ac))(param_1,param_2,1);
  if (*param_2 != 0) {
    (**(code **)(param_1 + 0x18))(*param_2);
    *param_2 = 0;
  }
  if (param_2[1] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[1]);
    param_2[1] = 0;
  }
  if (param_2[6] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[6]);
    param_2[5] = 0;
    param_2[6] = 0;
  }
  ((int (*)())FUN_00053a3f)();
  return;
}

/* FUN_00053b5b @ 0x53b5b (497 bytes) */
int FUN_00053b5b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
  int *param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_2 + 0x14);
  if ((uVar5 & 0x3f) == 0) {
    iVar4 = (**(code **)(param_1 + 0xc))(uVar5 * 0x74 + 0x1d00);
    if (iVar4 == 0) {
      return 0;
    }
    if (*(int *)(param_2 + 0x18) != 0) {
      (**(code **)(param_1 + 0x1344))
                (iVar4,*(int *)(param_2 + 0x18),*(int *)(param_2 + 0x14) * 0x74);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x18));
    }
    *(int *)(param_2 + 0x18) = iVar4;
    uVar5 = *(uint *)(param_2 + 0x14);
  }
  piVar1 = (int *)(*(int *)(param_2 + 0x18) + uVar5 * 0x74);
  if (0x20 < param_3 - 0x8782U) {
    return 0;
  }
  *piVar1 = param_3;
  if (&UINT_0000879c < param_4) {
    if (param_4 < (uint *)0x87a5) {
      if ((int)(uint)*(byte *)(param_1 + 0x13b0) <= (int)param_4 + -0x879d) {
        return 0;
      }
      piVar1[1] = 1;
      piVar1[2] = (int)param_4;
      goto LAB_00053c27;
    }
    if (param_4 == (uint *)0x87bd) goto LAB_00053c1a;
  }
  else if (((uint *)0x8799 < param_4) || ((int)param_4 - 0x610eU < 3)) {
LAB_00053c1a:
    piVar1[1] = 1;
    piVar1[2] = (int)param_4;
    goto LAB_00053c27;
  }
  iVar4 = ((int (*)())FUN_0005369a)(param_2 + 0x1c,param_4);
  if (iVar4 == 0) {
    return 0;
  }
  iVar2 = *(int *)(*(int *)(param_2 + 0x20) + 0x28 + iVar4 * 0x54);
  if ((iVar2 != 0x87c4) && (iVar2 != -1)) {
    return 0;
  }
  piVar1[1] = 2;
  piVar1[2] = iVar4;
LAB_00053c27:
  piVar1[3] = *param_5;
  piVar1[4] = param_5[1];
  piVar1[5] = param_5[2];
  piVar1[6] = param_5[3];
  cVar3 = ((int (*)())FUN_000537f8)(param_7,piVar1 + 8);
  if (((cVar3 != '\0') && (cVar3 = ((int (*)())FUN_000537f8)(param_9,piVar1 + 0xf), cVar3 != '\0')) &&
     (cVar3 = ((int (*)())FUN_000537f8)(param_11,piVar1 + 0x16), cVar3 != '\0')) {
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
    return 1;
  }
  return 0;
}

/* FUN_00053d4c @ 0x53d4c (903 bytes) */
int FUN_00053d4c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x116c);
  if (*(int *)(iVar1 + 0x24) < 0) {
    return 0;
  }
  uVar3 = *param_2;
  if ((uVar3 & 0x3f) == 0) {
    uVar3 = (**(code **)(param_1 + 0xc))(uVar3 * 0x54 + 0x1500);
    if (uVar3 == 0) {
      return 0;
    }
    if (param_2[1] != 0) {
      (**(code **)(param_1 + 0x1344))(uVar3,param_2[1],*param_2 * 0x54);
      (**(code **)(param_1 + 0x18))(param_2[1]);
    }
    param_2[1] = uVar3;
    uVar3 = *param_2;
  }
  if (param_4 == -4) {
    *(undefined4 *)(param_2[1] + 0x28 + uVar3 * 0x54) = 0x87c1;
    *(undefined1 *)(uVar3 * 0x54 + 0x3c + param_2[1]) = 0;
  }
  else if (param_4 == -3) {
    iVar2 = uVar3 * 0x54;
    *(undefined4 *)(param_2[1] + 0x28 + iVar2) = 0x87c2;
    *(int *)(iVar2 + 0x38 + param_2[1]) =
         param_8 * 0x10 + *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x4308);
    *(undefined1 *)(iVar2 + 0x3c + param_2[1]) = 0;
  }
  else if (param_4 == -2) {
    iVar2 = uVar3 * 0x54;
    *(undefined4 *)(param_2[1] + 0x28 + iVar2) = 0x87c2;
    *(int *)(iVar2 + 0x38 + param_2[1]) =
         param_8 * 0x10 +
         *(int *)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 0x18) + 0x18c) + 0x18);
    *(undefined1 *)(iVar2 + 0x3c + param_2[1]) = 0;
  }
  else {
    iVar2 = uVar3 * 0x54;
    *(int *)(param_2[1] + 0x28 + iVar2) = param_4;
    if (param_3 == 0x87bf) {
      uVar6 = 0x10;
    }
    else if (param_3 == 0x87c0) {
      uVar6 = 0x40;
    }
    else {
      if (param_3 != 0x87be) {
        *(undefined4 *)(iVar2 + 0x38 + param_2[1]) = 0;
        *(undefined1 *)(iVar2 + 0x3c + param_2[1]) = 0;
        goto LAB_00053e89;
      }
      uVar6 = 4;
    }
    uVar5 = param_2[1];
    uVar6 = (**(code **)(param_1 + 0xc))(uVar6);
    *(undefined4 *)(iVar2 + uVar5 + 0x38) = uVar6;
    *(undefined1 *)(iVar2 + 0x3c + param_2[1]) = 1;
  }
LAB_00053e89:
  iVar2 = uVar3 * 0x54;
  *(undefined4 *)(param_2[1] + 0x20 + iVar2) = *(undefined4 *)(iVar1 + 0x24);
  *(int *)(param_2[1] + 0x24 + iVar2) = param_3;
  *(undefined4 *)(param_2[1] + 0x2c + iVar2) = param_5;
  if ((param_6 == 0) && (param_7 < 2)) {
    *(undefined4 *)(param_2[1] + 0x30 + iVar2) = 0;
  }
  else {
    if (param_6 == 0) {
      param_6 = *(int *)(iVar2 + param_2[1] + 0x20);
    }
    *(int *)(iVar2 + param_2[1] + 0x30) = param_6;
  }
  *(uint *)(param_2[1] + 0x34 + iVar2) = param_7;
  *(undefined1 *)(param_2[1] + 0x3d + iVar2) = 0;
  *(undefined4 *)(param_2[1] + 0x40 + iVar2) = 0xffffffff;
  *(undefined1 *)(param_2[1] + 0x44 + iVar2) = 0;
  uVar5 = *(uint *)(iVar1 + 0x24);
  if (param_2[3] <= uVar5) {
    uVar5 = (**(code **)(param_1 + 0x10))(uVar5 + 0x40,4);
    if (uVar5 == 0) {
      return 0;
    }
    if (param_2[2] != 0) {
      (**(code **)(param_1 + 0x1344))(uVar5,param_2[2],param_2[3] << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar5;
    param_2[3] = *(int *)(iVar1 + 0x24) + 0x40;
    uVar5 = *(uint *)(iVar1 + 0x24);
  }
  *(uint *)(param_2[2] + uVar5 * 4) = uVar3;
  *param_2 = *param_2 + 1;
  iVar4 = *(int *)(iVar1 + 0x24) + 1;
  *(int *)(iVar1 + 0x24) = iVar4;
  if (iVar4 == 0x610e) {
    *(undefined4 *)(iVar1 + 0x24) = 0x6111;
  }
  else if (iVar4 == 0x879a) {
    *(undefined4 *)(iVar1 + 0x24) = 0x87be;
  }
  return *(undefined4 *)(param_2[1] + 0x20 + iVar2);
}

/* FUN_000540d3 @ 0x540d3 (38 bytes) */
int FUN_000540d3(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (param_2 < *(uint *)(param_1 + 0xc)) {
    return *(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 8) + param_2 * 4) * 0x54;
  }
  return 0;
}

/* FUN_000540f9 @ 0x540f9 (250 bytes) */
int FUN_000540f9(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  iVar2 = *(int *)(*(int *)(param_1 + 0x116c) + 0x24);
  if (iVar2 == 0) {
    uVar1 = ((int (*)())FUN_00053d4c)(param_1,param_2,0x87c0,0x87c2,0x87e1,0,0,0);
    iVar2 = ((int (*)())FUN_000540d3)(param_2,uVar1);
    *(undefined4 *)(iVar2 + 0x48) = 0x87e3;
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x50) = 0x80;
    *(undefined1 *)(iVar2 + 0x44) = 1;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x116c) + 0x24) = 0;
  ((int (*)())FUN_00053d4c)(param_1,param_2,0x87be,0x87c1,0x87e1,0,0,0);
  *(int *)(*(int *)(param_1 + 0x116c) + 0x24) = iVar2;
  return;
}

/* FUN_000541f3 @ 0x541f3 (325 bytes) */
int FUN_000541f3(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  uVar1 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(param_1 + 0x116c) + 0x10),4);
  *param_2 = uVar1;
  (**(code **)(param_1 + 0x11a4))(param_1,param_2,0xffffffff);
  uVar1 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(param_1 + 0x116c) + 0x10),1);
  param_2[1] = uVar1;
  if (0 < *(int *)(*(int *)(param_1 + 0x116c) + 0x10)) {
    iVar2 = 0;
    do {
      *(undefined1 *)(param_2[1] + iVar2) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(*(int *)(param_1 + 0x116c) + 0x10));
  }
  *(undefined1 *)(param_2 + 4) = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  ((int (*)())FUN_000540f9)(param_1,param_2 + 7);
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  if (*(char *)(param_1 + 0x13b0) != '\0') {
    iVar2 = 0;
    puVar3 = param_2;
    do {
      *(undefined1 *)(puVar3 + 0xd) = 0;
      *(undefined1 *)(puVar3 + 0x11) = 1;
      iVar2 = iVar2 + 1;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x13b0));
  }
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  *(undefined1 *)(param_2 + 0x1b) = 0;
  iVar2 = 4;
  puVar3 = param_2;
  do {
    *(undefined1 *)((int)puVar3 + 0x6d) = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 8;
  puVar3 = param_2;
  do {
    *(undefined1 *)((int)puVar3 + 0x71) = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)((int)param_2 + 0x79) = 0;
  *(undefined1 *)((int)param_2 + 0x7a) = 0;
  *(undefined1 *)((int)param_2 + 0x7b) = 0;
  return;
}

/* FUN_00054338 @ 0x54338 (118 bytes) */
int FUN_00054338(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint local_10;
  
  iVar1 = *(int *)(param_1 + 0x112c);
  if (*(int *)(iVar1 + 4) != 0) {
    local_10 = 0;
    iVar5 = 0;
    do {
      while (iVar3 = iVar5 + *(int *)(iVar1 + 8), *(int *)(iVar3 + 4) == 0x8620) {
        puVar2 = *(undefined4 **)(iVar3 + 0x14);
        uVar4 = ((int (*)())FUN_000526ee)(param_1,*puVar2);
        puVar2[0x2a] = uVar4;
        local_10 = local_10 + 1;
        iVar5 = iVar5 + 0x18;
        if (*(uint *)(iVar1 + 4) <= local_10) {
          return;
        }
      }
      local_10 = local_10 + 1;
      iVar5 = iVar5 + 0x18;
    } while (local_10 < *(uint *)(iVar1 + 4));
  }
  return;
}

/* FUN_000543b0 @ 0x543b0 (1456 bytes) */
int FUN_000543b0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  uint local_14;
  
  if (*(int *)(param_4 + 0x28) == 0x87c2) {
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x224) = *(int *)(param_3 + 0x224) + 1;
    }
    else {
      *(int *)(param_3 + 0x22c) = *(int *)(param_3 + 0x22c) + 1;
    }
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar3 = *(int *)(param_4 + 0x24);
    if (iVar3 == 0x87bf) {
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      bVar1 = false;
      iVar3 = 0;
      for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x58); uVar5 = uVar5 + 1) {
        while( true ) {
          if (bVar1) goto LAB_000545fc;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
          bVar1 = true;
          if (*(uint *)(param_3 + 0x58) <= uVar5) goto LAB_00054641;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_00054641:
      if (bVar1) goto LAB_000545fc;
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar3 = *(int *)(param_3 + 0x58);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      goto LAB_00054698;
    }
    if (iVar3 == 0x87c0) {
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      uVar5 = *(int *)(param_3 + 0x58) - 3;
      bVar1 = false;
      iVar3 = 0;
      for (local_1c = 0; local_1c < uVar5; local_1c = local_1c + 1) {
        while( true ) {
          if (bVar1) goto LAB_000546f6;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
          bVar1 = true;
          if (uVar5 <= local_1c) goto LAB_000546f2;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_000546f2:
      if (bVar1) {
LAB_000546f6:
        iVar3 = local_1c * 0x28;
        iVar4 = iVar3 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          do {
            *(uint *)(param_4 + 0x10) = local_1c + iVar4;
            *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3) = 1;
            iVar4 = iVar4 + 1;
            param_4 = param_4 + 4;
            iVar3 = iVar3 + 0x28;
          } while (iVar4 != 4);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar4 = *(int *)(param_3 + 0x58);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar2;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      iVar3 = iVar4 * 0x28;
      iVar6 = 0;
      do {
        *(int *)(param_4 + 0x10) = iVar4 + iVar6;
        *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3) = 1;
        iVar6 = iVar6 + 1;
        param_4 = param_4 + 4;
        iVar3 = iVar3 + 0x28;
      } while (iVar6 != 4);
      return;
    }
    if (iVar3 != 0x87be) {
      return;
    }
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    bVar1 = false;
    iVar3 = 0;
    for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x58); uVar5 = uVar5 + 1) {
      while( true ) {
        if (bVar1) goto LAB_0005445d;
        if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
        bVar1 = true;
        if (*(uint *)(param_3 + 0x58) <= uVar5) goto LAB_00054455;
      }
      iVar3 = iVar3 + 0x28;
    }
LAB_00054455:
    if (bVar1) goto LAB_0005445d;
    *(undefined1 *)(param_2 + 0x10) = 0;
    iVar3 = *(int *)(param_3 + 0x58);
    uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x10,0x28);
    (**(code **)(param_1 + 0x1344))
              (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
  }
  else {
    if (*(int *)(param_4 + 0x28) != 0x87c3) {
      return;
    }
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar3 = *(int *)(param_4 + 0x24);
    if (iVar3 == 0x87bf) {
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
      bVar1 = false;
      iVar3 = 0;
      for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x58); uVar5 = uVar5 + 1) {
        while( true ) {
          if (bVar1) goto LAB_000545fc;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
          bVar1 = true;
          if (*(uint *)(param_3 + 0x58) <= uVar5) goto LAB_00054595;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_00054595:
      if (bVar1) {
LAB_000545fc:
        *(uint *)(param_4 + 4) = uVar5;
        *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + uVar5 * 0x28) = 1;
        return;
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar3 = *(int *)(param_3 + 0x58);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
LAB_00054698:
      *(undefined4 *)(param_3 + 0x54) = uVar2;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      *(int *)(param_4 + 4) = iVar3;
      *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3 * 0x28) = 1;
      return;
    }
    if (iVar3 == 0x87c0) {
      *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 4;
      uVar5 = *(int *)(param_3 + 0x58) - 3;
      bVar1 = false;
      iVar3 = 0;
      for (local_14 = 0; local_14 < uVar5; local_14 = local_14 + 1) {
        while( true ) {
          if (bVar1) goto LAB_00054825;
          if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
          bVar1 = true;
          if (uVar5 <= local_14) goto LAB_00054821;
        }
        iVar3 = iVar3 + 0x28;
      }
LAB_00054821:
      if (bVar1) {
LAB_00054825:
        iVar3 = local_14 * 0x28;
        iVar4 = iVar3 + *(int *)(param_3 + 0x54);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          do {
            *(uint *)(param_4 + 0x10) = local_14 + iVar4;
            *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3) = 1;
            iVar4 = iVar4 + 1;
            param_4 = param_4 + 4;
            iVar3 = iVar3 + 0x28;
          } while (iVar4 != 4);
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar4 = *(int *)(param_3 + 0x58);
      uVar2 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
      *(undefined4 *)(param_3 + 0x54) = uVar2;
      *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
      iVar3 = iVar4 * 0x28;
      iVar6 = 0;
      do {
        *(int *)(param_4 + 0x10) = iVar4 + iVar6;
        *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3) = 1;
        iVar6 = iVar6 + 1;
        param_4 = param_4 + 4;
        iVar3 = iVar3 + 0x28;
      } while (iVar6 != 4);
      return;
    }
    if (iVar3 != 0x87be) {
      return;
    }
    *(int *)(param_3 + 0x5c) = *(int *)(param_3 + 0x5c) + 1;
    bVar1 = false;
    iVar3 = 0;
    for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x58); uVar5 = uVar5 + 1) {
      while( true ) {
        if (bVar1) goto LAB_0005445d;
        if (*(char *)(iVar3 + 0x10 + *(int *)(param_3 + 0x54)) != '\0') break;
        bVar1 = true;
        if (*(uint *)(param_3 + 0x58) <= uVar5) goto LAB_000544dd;
      }
      iVar3 = iVar3 + 0x28;
    }
LAB_000544dd:
    if (bVar1) {
LAB_0005445d:
      *(uint *)(param_4 + 4) = uVar5;
      *(undefined4 *)(param_4 + 8) = 0;
      *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + uVar5 * 0x28) = 1;
      return;
    }
    *(undefined1 *)(param_2 + 0x10) = 0;
    iVar3 = *(int *)(param_3 + 0x58);
    uVar2 = (**(code **)(param_1 + 0x10))(iVar3 + 0x10,0x28);
    (**(code **)(param_1 + 0x1344))
              (uVar2,*(undefined4 *)(param_3 + 0x54),*(int *)(param_3 + 0x58) * 0x28);
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x54));
  }
  *(undefined4 *)(param_3 + 0x54) = uVar2;
  *(int *)(param_3 + 0x58) = *(int *)(param_3 + 0x58) + 0x10;
  *(int *)(param_4 + 4) = iVar3;
  *(undefined4 *)(param_4 + 8) = 0;
  *(undefined1 *)(*(int *)(param_3 + 0x54) + 0x10 + iVar3 * 0x28) = 1;
  return;
}

/* FUN_00054960 @ 0x54960 (1334 bytes) */
int FUN_00054960(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int local_54;
  int local_50;
  uint local_2c;
  int local_28;
  uint local_18;
  
  if (*param_4 != 2) {
    return;
  }
  iVar2 = param_4[1];
  local_54 = *(int *)(param_2 + 0x20) + iVar2 * 0x54;
  if (*(int *)(local_54 + 0x28) != 0x87c4) {
    return;
  }
  if (*(char *)(local_54 + 0x3d) != '\0') {
    return;
  }
  *(undefined1 *)(local_54 + 0x3d) = 1;
  *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
  iVar8 = *(int *)(iVar2 * 0x54 + 0x24 + *(int *)(param_2 + 0x20));
  if (iVar8 != 0x87bf) {
    if (iVar8 == 0x87c0) {
      uVar5 = *(int *)(param_3 + 0x50) - 3;
      bVar10 = false;
      for (uVar7 = 0; uVar7 < uVar5; uVar7 = uVar7 + 1) {
        while( true ) {
          if (bVar10) goto LAB_00054b3f;
          if (*(char *)(*(int *)(param_3 + 0x4c) + 0x10 + uVar7 * 0x28) != '\0') break;
          bVar10 = true;
          if (uVar5 <= uVar7) goto LAB_00054b35;
        }
      }
LAB_00054b35:
      if (bVar10) {
LAB_00054b3f:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x4c);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          local_28 = 0;
          local_50 = local_54;
          do {
            *(uint *)(local_50 + 0x10) = local_28 + uVar7;
            *(undefined1 *)(iVar8 + 0x10 + *(int *)(param_3 + 0x4c)) = 1;
            *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x4c)) = 4;
            *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x4c)) = iVar2;
            *(int *)(iVar8 + 0x1c + *(int *)(param_3 + 0x4c)) = iVar2;
            *(int *)(iVar8 + 0x20 + *(int *)(param_3 + 0x4c)) = iVar2;
            *(int *)(iVar8 + 0x24 + *(int *)(param_3 + 0x4c)) = iVar2;
            local_28 = local_28 + 1;
            local_50 = local_50 + 4;
            iVar8 = iVar8 + 0x28;
          } while (local_28 != 4);
          if (uVar7 + 3 < *(uint *)(param_3 + 0x2ac)) {
            return;
          }
          *(uint *)(param_3 + 0x2ac) = uVar7 + 4;
          return;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar4 = *(int *)(param_3 + 0x50);
      uVar6 = (**(code **)(param_1 + 0x10))(iVar4 + 0x10,0x28);
      (**(code **)(param_1 + 0x1344))
                (uVar6,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
      *(undefined4 *)(param_3 + 0x4c) = uVar6;
      *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
      iVar8 = iVar4 * 0x28;
      iVar9 = 0;
      do {
        *(int *)(local_54 + 0x10) = iVar4 + iVar9;
        *(undefined1 *)(*(int *)(param_3 + 0x4c) + 0x10 + iVar8) = 1;
        *(undefined4 *)(*(int *)(param_3 + 0x4c) + 0x14 + iVar8) = 4;
        *(int *)(*(int *)(param_3 + 0x4c) + 0x18 + iVar8) = iVar2;
        *(int *)(*(int *)(param_3 + 0x4c) + 0x1c + iVar8) = iVar2;
        *(int *)(*(int *)(param_3 + 0x4c) + 0x20 + iVar8) = iVar2;
        *(int *)(*(int *)(param_3 + 0x4c) + 0x24 + iVar8) = iVar2;
        iVar9 = iVar9 + 1;
        local_54 = local_54 + 4;
        iVar8 = iVar8 + 0x28;
      } while (iVar9 != 4);
      if (iVar4 + 3U < *(uint *)(param_3 + 0x2ac)) {
        return;
      }
      *(int *)(param_3 + 0x2ac) = iVar4 + 4;
      return;
    }
    if (iVar8 != 0x87be) {
      return;
    }
    uVar5 = *(uint *)(param_3 + 0x50);
    local_18 = 0;
    iVar8 = 0;
LAB_000549e4:
    bVar10 = false;
    bVar3 = false;
    do {
      if (uVar5 <= local_18) {
        if (bVar3) {
LAB_00054a10:
          *(uint *)(local_54 + 4) = local_18;
          iVar8 = local_18 * 0x28;
          *(undefined4 *)(local_54 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x4c) + 0x14 + iVar8);
          iVar4 = iVar8 + *(int *)(param_3 + 0x4c);
          *(int *)(iVar4 + 0x18 + *(int *)(iVar4 + 0x14) * 4) = iVar2;
          piVar1 = (int *)(iVar8 + *(int *)(param_3 + 0x4c) + 0x14);
          *piVar1 = *piVar1 + 1;
          if (local_18 < *(uint *)(param_3 + 0x2ac)) {
            return;
          }
          goto LAB_00054a4e;
        }
        if (uVar5 == 0) goto LAB_00054db1;
        local_2c = 0;
        goto LAB_00054d91;
      }
      if (bVar10) goto LAB_00054a10;
      iVar4 = iVar8 + *(int *)(param_3 + 0x4c);
      if ((*(char *)(iVar4 + 0x10) == '\0') || (3 < *(uint *)(iVar4 + 0x14))) goto LAB_00054a5c;
      bVar10 = true;
      bVar3 = true;
    } while( true );
  }
  bVar10 = false;
  for (uVar5 = 0; uVar5 < *(uint *)(param_3 + 0x50); uVar5 = uVar5 + 1) {
    while( true ) {
      if (bVar10) goto LAB_00054aa1;
      if (*(char *)(*(int *)(param_3 + 0x4c) + 0x10 + uVar5 * 0x28) != '\0') break;
      bVar10 = true;
      if (*(uint *)(param_3 + 0x50) <= uVar5) goto LAB_00054a97;
    }
  }
LAB_00054a97:
  if (bVar10) {
LAB_00054aa1:
    *(uint *)(local_54 + 4) = uVar5;
    iVar8 = uVar5 * 0x28;
    *(undefined1 *)(*(int *)(param_3 + 0x4c) + 0x10 + iVar8) = 1;
    *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x4c)) = 4;
    *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x4c)) = iVar2;
    *(int *)(iVar8 + 0x1c + *(int *)(param_3 + 0x4c)) = iVar2;
    *(int *)(iVar8 + 0x20 + *(int *)(param_3 + 0x4c)) = iVar2;
    *(int *)(iVar8 + 0x24 + *(int *)(param_3 + 0x4c)) = iVar2;
    if (uVar5 < *(uint *)(param_3 + 0x2ac)) {
      return;
    }
    *(uint *)(param_3 + 0x2ac) = uVar5 + 1;
    return;
  }
  *(undefined1 *)(param_2 + 0x10) = 0;
  local_18 = *(uint *)(param_3 + 0x50);
  uVar6 = (**(code **)(param_1 + 0x10))(local_18 + 0x10,0x28);
  (**(code **)(param_1 + 0x1344))
            (uVar6,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
  *(undefined4 *)(param_3 + 0x4c) = uVar6;
  *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
  *(uint *)(local_54 + 4) = local_18;
  iVar8 = local_18 * 0x28;
  *(undefined1 *)(*(int *)(param_3 + 0x4c) + 0x10 + iVar8) = 1;
  *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x4c)) = 4;
  *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x4c)) = iVar2;
  *(int *)(iVar8 + 0x1c + *(int *)(param_3 + 0x4c)) = iVar2;
  *(int *)(iVar8 + 0x20 + *(int *)(param_3 + 0x4c)) = iVar2;
  *(int *)(iVar8 + 0x24 + *(int *)(param_3 + 0x4c)) = iVar2;
  if (local_18 < *(uint *)(param_3 + 0x2ac)) {
    return;
  }
  goto LAB_00054a4e;
LAB_00054db1:
  *(undefined1 *)(param_2 + 0x10) = 0;
  local_18 = *(uint *)(param_3 + 0x50);
  uVar6 = (**(code **)(param_1 + 0x10))(local_18 + 0x10,0x28);
  (**(code **)(param_1 + 0x1344))
            (uVar6,*(undefined4 *)(param_3 + 0x4c),*(int *)(param_3 + 0x50) * 0x28);
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x4c));
  *(undefined4 *)(param_3 + 0x4c) = uVar6;
  *(int *)(param_3 + 0x50) = *(int *)(param_3 + 0x50) + 0x10;
  *(uint *)(local_54 + 4) = local_18;
  *(undefined4 *)(local_54 + 8) = 0;
  iVar8 = local_18 * 0x28;
  *(undefined1 *)(*(int *)(param_3 + 0x4c) + 0x10 + iVar8) = 1;
  *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x4c)) = 1;
  *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x4c)) = iVar2;
  if (local_18 < *(uint *)(param_3 + 0x2ac)) {
    return;
  }
  goto LAB_00054a4e;
LAB_00054a5c:
  local_18 = local_18 + 1;
  iVar8 = iVar8 + 0x28;
  goto LAB_000549e4;
  while (bVar10) {
LAB_00054d91:
    bVar10 = *(char *)(*(int *)(param_3 + 0x4c) + 0x10 + local_2c * 0x28) != '\0';
    if (bVar10) {
      local_2c = local_2c + 1;
    }
    if (uVar5 <= local_2c) {
      if (bVar10) goto LAB_00054db1;
      break;
    }
  }
  *(uint *)(local_54 + 4) = local_2c;
  *(undefined4 *)(local_54 + 8) = 0;
  iVar8 = local_2c * 0x28;
  *(undefined1 *)(*(int *)(param_3 + 0x4c) + 0x10 + iVar8) = 1;
  *(undefined4 *)(iVar8 + 0x14 + *(int *)(param_3 + 0x4c)) = 1;
  *(int *)(iVar8 + 0x18 + *(int *)(param_3 + 0x4c)) = iVar2;
  local_18 = local_2c;
  if (local_2c < *(uint *)(param_3 + 0x2ac)) {
    return;
  }
LAB_00054a4e:
  *(uint *)(param_3 + 0x2ac) = local_18 + 1;
  return;
}

/* FUN_00054e96 @ 0x54e96 (42 bytes) */
int FUN_00054e96(param_1, param_2)
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

/* FUN_00054ec0 @ 0x54ec0 (679 bytes) */
int FUN_00054ec0(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  uint local_24;
  uint local_20;
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  int local_10;
  
  iVar1 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  if (*(int *)(iVar1 + 0x50) != 0) {
    local_24 = 0;
    local_10 = 0;
    uVar7 = param_3 + 1;
    do {
      while (iVar9 = local_10 + *(int *)(iVar1 + 0x4c), *(char *)(iVar9 + 0x10) != '\0') {
        iVar2 = *(int *)(iVar9 + 0x18);
        if (((((iVar2 != 0) || (*(int *)(iVar9 + 0x1c) != 0)) || (*(int *)(iVar9 + 0x20) != 0)) ||
            (*(int *)(iVar9 + 0x24) != 0)) && (uVar3 = param_2[5], uVar7 < uVar3)) {
          iVar8 = param_2[6] + uVar7 * 0x74;
          local_18 = 0;
          local_17 = 0;
          local_16 = 0;
          local_15 = 0;
          bVar5 = true;
          local_20 = uVar7;
          do {
            cVar6 = ((int (*)())FUN_00054e96)();
            if (((cVar6 == '\0') && (cVar6 = ((int (*)())FUN_00054e96)(), cVar6 == '\0')) &&
               (cVar6 = ((int (*)())FUN_00054e96)(), cVar6 == '\0')) {
              cVar6 = ((int (*)())FUN_00054e96)();
              if (cVar6 != '\0') {
                iVar4 = *(int *)(iVar8 + 8);
                if (*(int *)(param_2[8] + 0x24 + iVar4 * 0x54) == 0x87be) {
                  bVar11 = iVar2 == iVar4;
                  bVar12 = iVar4 == *(int *)(iVar9 + 0x1c);
                  bVar13 = iVar4 == *(int *)(iVar9 + 0x20);
                  bVar14 = iVar4 == *(int *)(iVar9 + 0x24);
                }
                else {
                  bVar11 = *(byte *)(iVar8 + 0xc);
                  bVar12 = *(byte *)(iVar8 + 0x10);
                  bVar13 = *(byte *)(iVar8 + 0x14);
                  bVar14 = *(byte *)(iVar8 + 0x18);
                }
                local_15 = local_15 | bVar14;
                local_16 = local_16 | bVar13;
                local_17 = local_17 | bVar12;
                local_18 = local_18 | bVar11;
                if (((local_18 != 0) && (local_17 != 0)) && (local_16 != 0)) {
                  bVar10 = local_15 != 0;
                  goto LAB_00054f7e;
                }
              }
              bVar10 = false;
            }
            else {
              bVar5 = false;
              bVar10 = true;
            }
LAB_00054f7e:
            local_20 = local_20 + 1;
          } while ((local_20 != uVar3) && (iVar8 = iVar8 + 0x74, !bVar10));
          if (!bVar5) break;
        }
        *(undefined1 *)(param_2[8] + 0x3d + iVar2 * 0x54) = 0;
        *(undefined1 *)
         (param_2[8] + 0x3d + *(int *)(local_10 + 0x1c + *(int *)(iVar1 + 0x4c)) * 0x54) = 0;
        *(undefined1 *)
         (param_2[8] + 0x3d + *(int *)(local_10 + 0x20 + *(int *)(iVar1 + 0x4c)) * 0x54) = 0;
        *(undefined1 *)
         (param_2[8] + 0x3d + *(int *)(local_10 + 0x24 + *(int *)(iVar1 + 0x4c)) * 0x54) = 0;
        *(undefined1 *)(local_10 + 0x10 + *(int *)(iVar1 + 0x4c)) = 0;
        *(undefined4 *)(local_10 + 0x14 + *(int *)(iVar1 + 0x4c)) = 0;
        *(undefined4 *)(local_10 + 0x18 + *(int *)(iVar1 + 0x4c)) = 0;
        *(undefined4 *)(local_10 + 0x1c + *(int *)(iVar1 + 0x4c)) = 0;
        *(undefined4 *)(local_10 + 0x20 + *(int *)(iVar1 + 0x4c)) = 0;
        *(undefined4 *)(local_10 + 0x24 + *(int *)(iVar1 + 0x4c)) = 0;
        param_2[0x19] = param_2[0x19] + -1;
        local_24 = local_24 + 1;
        local_10 = local_10 + 0x28;
        if (*(uint *)(iVar1 + 0x50) <= local_24) {
          return;
        }
      }
      local_24 = local_24 + 1;
      local_10 = local_10 + 0x28;
    } while (local_24 < *(uint *)(iVar1 + 0x50));
  }
  return;
}

/* FUN_00055167 @ 0x55167 (1117 bytes) */
int FUN_00055167(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
  int param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar1 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  *param_4 = param_5 & 0x3f | *param_4 & 0xffffff80 | (param_6 & 1) << 6;
  *(byte *)param_4 = (byte)*param_4 & 0x7f;
  *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xef;
  uVar4 = ((byte)param_3[2] & 1) << 0x14;
  uVar9 = *param_4;
  *param_4 = uVar9 & 0xffefffff | uVar4;
  uVar5 = ((byte)param_3[3] & 1) << 0x15;
  *param_4 = uVar9 & 0xffcfffff | uVar4 | uVar5;
  uVar6 = ((byte)param_3[4] & 1) << 0x16;
  *param_4 = uVar9 & 0xff8fffff | uVar4 | uVar5 | uVar6;
  uVar7 = ((byte)param_3[5] & 1) << 0x17;
  *param_4 = uVar9 & 0xff0fffff | uVar4 | uVar5 | uVar6 | uVar7;
  uVar8 = *param_3;
  if (uVar8 == 2) {
    iVar1 = param_2[8] + param_3[1] * 0x54;
    if (*(int *)(iVar1 + 0x28) != 0x87c4) {
      if (*(int *)(iVar1 + 0x28) != -1) {
        return 0;
      }
      uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x100;
      *param_4 = uVar9;
      goto LAB_0005530d;
    }
    iVar2 = *(int *)(iVar1 + 0x24);
    if (iVar2 != 0x87bf) {
      if (iVar2 == 0x87c0) {
        *param_4 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7;
        uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 |
                (*(byte *)(iVar1 + 0x10 + param_7 * 4) & 0x7f) << 0xd;
        *param_4 = uVar9;
      }
      else {
        if (iVar2 != 0x87be) {
          return 0;
        }
        *param_4 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7;
        *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 |
                   (*(byte *)(iVar1 + 4) & 0x7f) << 0xd;
        iVar1 = *(int *)(iVar1 + 8);
        if (iVar1 == 1) {
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x2f;
          uVar9 = *param_4;
        }
        else if (iVar1 == 0) {
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x1f;
          uVar9 = *param_4;
        }
        else if (iVar1 == 2) {
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x4f;
          uVar9 = *param_4;
        }
        else {
          if (iVar1 != 3) {
            return 0;
          }
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x8f;
          uVar9 = *param_4;
        }
      }
      goto LAB_0005530d;
    }
    *param_4 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7;
    bVar3 = *(byte *)(iVar1 + 4);
  }
  else {
    if (uVar8 < 3) {
      if (uVar8 != 1) {
        return 0;
      }
      uVar10 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7;
      *param_4 = uVar10 | 0x200;
      uVar8 = param_3[1];
      if (uVar8 == 0x879b) {
        uVar8 = (uint)*(byte *)(iVar1 + 0x1ec);
      }
      else if (uVar8 < 0x879c) {
        if (uVar8 == 0x610f) {
          if (*(char *)((int)param_2 + 0x6f) == '\0') {
            *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200;
            *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0xf;
            uVar9 = *param_4;
          }
          else {
            uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200 |
                    (*(byte *)(iVar1 + 500) & 0x7f) << 0xd;
            *param_4 = uVar9;
          }
          goto LAB_0005530d;
        }
        if (uVar8 < 0x6110) {
          if (uVar8 != 0x610e) {
            return 0;
          }
          if (*(char *)((int)param_2 + 0x79) == '\0') {
            *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200;
            bVar3 = *(byte *)((int)param_4 + 2) & 0xef;
            *(byte *)((int)param_4 + 2) = bVar3;
          }
          else {
            *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200 |
                       (*(byte *)(iVar1 + 0x1fc) & 0x7f) << 0xd;
            bVar3 = *(byte *)((int)param_4 + 2);
          }
          *(byte *)((int)param_4 + 2) = bVar3 & 0x1f;
          uVar9 = *param_4;
          goto LAB_0005530d;
        }
        if (uVar8 != 0x6110) {
          if (uVar8 != 0x879a) {
            return 0;
          }
          uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200 |
                  (*(byte *)(iVar1 + 0x1e8) & 0x7f) << 0xd;
          *param_4 = uVar9;
          goto LAB_0005530d;
        }
        if ((char)param_2[0x1c] == '\0') {
          *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200;
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0xf;
          uVar9 = *param_4;
          goto LAB_0005530d;
        }
        uVar8 = (uint)*(byte *)(iVar1 + 0x1f8);
      }
      else {
        if (0x87a4 < uVar8) {
          if (uVar8 != 0x87bd) {
            return 0;
          }
          *param_4 = uVar10 | 0x300;
          *param_4 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x300 |
                     (*(byte *)(iVar1 + 0x1f0) & 0x7f) << 0xd;
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x8f;
          uVar9 = *param_4 & 0xff7fffff | (*(byte *)(iVar1 + 0x42) & 1) << 0x17;
          *param_4 = uVar9;
          goto LAB_0005530d;
        }
        if (uVar8 < 0x879d) {
          uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200 |
                  (*(byte *)(iVar1 + 0x1f0) & 0x7f) << 0xd;
          *param_4 = uVar9;
          if (*(char *)(iVar1 + 0x42) != '\0') {
            *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) & 0x7f;
            uVar9 = *param_4;
          }
          goto LAB_0005530d;
        }
        uVar8 = (uint)*(byte *)(iVar1 + -0x21c74 + uVar8 * 4);
      }
      uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x200 | (uVar8 & 0x7f) << 0xd;
      *param_4 = uVar9;
      goto LAB_0005530d;
    }
    if (uVar8 != 3) {
      if (uVar8 != 5) {
        return 0;
      }
      *param_4 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x100;
      uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | 0x100 |
              ((byte)param_3[1] & 0x7f) << 0xd;
      *param_4 = uVar9;
      goto LAB_0005530d;
    }
    *param_4 = uVar9 & 0xff0ff0ff | uVar4 | uVar5 | uVar6 | uVar7;
    bVar3 = (byte)param_3[1];
  }
  uVar9 = uVar9 & 0xff0010ff | uVar4 | uVar5 | uVar6 | uVar7 | (bVar3 & 0x7f) << 0xd;
  *param_4 = uVar9;
LAB_0005530d:
  *param_4 = uVar9 & 0x9fffffff;
  *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0x7f;
  *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) & 0xef;
  return 1;
}

/* FUN_000555c4 @ 0x555c4 (1489 bytes) */
int FUN_000555c4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  switch(param_3[2]) {
  case 0x87d5:
  case 0x87d9:
    *param_4 = *param_4 & 0xffff1fff;
    break;
  case 0x87d6:
  case 0x87da:
    *param_4 = *param_4 & 0xffff1fff | 0x2000;
    break;
  case 0x87d7:
  case 0x87db:
    *param_4 = *param_4 & 0xffff1fff | 0x4000;
    break;
  case 0x87d8:
  case 0x87dc:
    *param_4 = *param_4 & 0xffff1fff | 0x6000;
    break;
  case 0x87dd:
    *param_4 = *param_4 & 0xffff1fff | 0x8000;
    break;
  case 0x87de:
  case 0x87df:
    *param_4 = *param_4 & 0xffff1fff | 0xa000;
    break;
  default:
    goto LAB_00055622;
  }
  if (10 < param_3[2] - 0x87d5) {
LAB_00055622:
    return 0;
  }
  uVar3 = 1 << ((byte)(param_3[2] - 0x87d5) & 0x1f);
  if ((uVar3 & 0x30f) == 0) {
    if ((uVar3 & 0x4f0) == 0) {
      return 0;
    }
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) | 2;
  }
  else {
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xfd;
  }
  switch(param_3[3]) {
  case 0x87d5:
  case 0x87d9:
    *param_4 = *param_4 & 0xfff8ffff;
    break;
  case 0x87d6:
  case 0x87da:
    *param_4 = *param_4 & 0xfff8ffff | 0x10000;
    break;
  case 0x87d7:
  case 0x87db:
    *param_4 = *param_4 & 0xfff8ffff | 0x20000;
    break;
  case 0x87d8:
  case 0x87dc:
    *param_4 = *param_4 & 0xfff8ffff | 0x30000;
    break;
  case 0x87dd:
    *param_4 = *param_4 & 0xfff8ffff | 0x40000;
    break;
  case 0x87de:
  case 0x87df:
    *param_4 = *param_4 & 0xfff8ffff | 0x50000;
    break;
  default:
    return 0;
  }
  if (10 < param_3[3] - 0x87d5) {
    return 0;
  }
  uVar3 = 1 << ((byte)(param_3[3] - 0x87d5) & 0x1f);
  if ((uVar3 & 0x30f) == 0) {
    if ((uVar3 & 0x4f0) == 0) {
      return 0;
    }
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) | 4;
  }
  else {
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xfb;
  }
  switch(param_3[4]) {
  case 0x87d5:
  case 0x87d9:
    *param_4 = *param_4 & 0xffc7ffff;
    break;
  case 0x87d6:
  case 0x87da:
    *param_4 = *param_4 & 0xffc7ffff | 0x80000;
    break;
  case 0x87d7:
  case 0x87db:
    *param_4 = *param_4 & 0xffc7ffff | 0x100000;
    break;
  case 0x87d8:
  case 0x87dc:
    *param_4 = *param_4 & 0xffc7ffff | 0x180000;
    break;
  case 0x87dd:
    *param_4 = *param_4 & 0xffc7ffff | 0x200000;
    break;
  case 0x87de:
  case 0x87df:
    *param_4 = *param_4 & 0xffc7ffff | 0x280000;
    break;
  default:
    return 0;
  }
  if (10 < param_3[4] - 0x87d5) {
    return 0;
  }
  uVar3 = 1 << ((byte)(param_3[4] - 0x87d5) & 0x1f);
  if ((uVar3 & 0x30f) == 0) {
    if ((uVar3 & 0x4f0) == 0) {
      return 0;
    }
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) | 8;
  }
  else {
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xf7;
  }
  switch(param_3[5]) {
  case 0x87d5:
  case 0x87d9:
    *param_4 = *param_4 & 0xfe3fffff;
    break;
  case 0x87d6:
  case 0x87da:
    *param_4 = *param_4 & 0xfe3fffff | 0x400000;
    break;
  case 0x87d7:
  case 0x87db:
    *param_4 = *param_4 & 0xfe3fffff | 0x800000;
    break;
  case 0x87d8:
  case 0x87dc:
    *param_4 = *param_4 & 0xfe3fffff | 0xc00000;
    break;
  case 0x87dd:
    *param_4 = *param_4 & 0xfe3fffff | 0x1000000;
    break;
  case 0x87de:
  case 0x87df:
    *param_4 = *param_4 & 0xfe3fffff | 0x1400000;
    break;
  default:
    return 0;
  }
  if (10 < param_3[5] - 0x87d5) {
    return 0;
  }
  uVar3 = 1 << ((byte)(param_3[5] - 0x87d5) & 0x1f);
  if ((uVar3 & 0x30f) == 0) {
    if ((uVar3 & 0x4f0) == 0) {
      return 0;
    }
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) | 0x10;
  }
  else {
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xef;
  }
  uVar3 = *param_3;
  if (uVar3 == 2) {
    iVar6 = param_3[1] * 0x54;
    iVar7 = iVar6 + *(int *)(param_2 + 4);
    uVar3 = *(uint *)(iVar7 + 0x28);
    if (uVar3 < 0x87c4) {
      if (uVar3 < 0x87c2) {
        if (uVar3 != 0x87c1) {
          return 0;
        }
        iVar2 = *(int *)(iVar7 + 0x24);
        if (iVar2 == 0x87bf) {
          uVar3 = *param_4;
          *param_4 = uVar3 & 0xfffffff8 | 1;
          uVar8 = (uint)*(byte *)(iVar7 + 4) << 5;
          *param_4 = uVar3 & 0xffffe018 | 1 | uVar8;
          iVar6 = iVar6 + *(int *)(param_2 + 4);
          if ((*(char *)(iVar6 + 0x44) != '\0') && (*(int *)(iVar6 + 0x48) == 1)) {
            *param_4 = uVar3 & 0xfe3fe018 | 1 | uVar8 | 0x1000000;
          }
          goto LAB_0005590b;
        }
        if (iVar2 != 0x87c0) {
          if (iVar2 != 0x87be) {
            return 0;
          }
          uVar8 = *param_4;
          *param_4 = uVar8 & 0xfffffff8 | 1;
          uVar4 = (uint)*(byte *)(iVar7 + 4) << 5;
          *param_4 = uVar8 & 0xffffe018 | 1 | uVar4;
          uVar5 = (*(byte *)(iVar7 + 8) & 7) << 0xd;
          uVar3 = uVar8 & 0xffff0018 | 1 | uVar4 | uVar5;
          *param_4 = uVar3;
          iVar6 = iVar6 + *(int *)(param_2 + 4);
          if ((*(char *)(iVar6 + 0x44) == '\0') || (*(int *)(iVar6 + 0x48) != 0xf)) {
            bVar1 = *(byte *)(iVar7 + 8);
            goto LAB_00055a65;
          }
          *param_4 = uVar8 & 0xfe000018 | 1 | uVar4 | uVar5 | 0x1640000;
          goto LAB_00055a98;
        }
        uVar3 = *param_4 & 0xfffffff8 | 1;
        *param_4 = uVar3;
        uVar8 = (uint)*(byte *)(iVar7 + 0x10 + param_5 * 4);
      }
      else {
        iVar6 = *(int *)(iVar7 + 0x24);
        if (iVar6 == 0x87bf) {
          uVar3 = *param_4 & 0xfffffff8 | 2;
          *param_4 = uVar3;
          uVar8 = (uint)*(byte *)(iVar7 + 4);
        }
        else {
          if (iVar6 != 0x87c0) {
            if (iVar6 != 0x87be) {
              return 0;
            }
            uVar3 = *param_4 & 0xfffffff8 | 2;
            goto LAB_00055b16;
          }
          uVar3 = *param_4 & 0xfffffff8 | 2;
          *param_4 = uVar3;
          uVar8 = (uint)*(byte *)(iVar7 + 0x10 + param_5 * 4);
        }
      }
    }
    else {
      if (uVar3 != 0x87c4) {
        return 0;
      }
      iVar6 = *(int *)(iVar7 + 0x24);
      if (iVar6 == 0x87bf) {
        uVar3 = *param_4 & 0xfffffff8;
        *param_4 = uVar3;
        uVar8 = (uint)*(byte *)(iVar7 + 4);
      }
      else {
        if (iVar6 != 0x87c0) {
          if (iVar6 != 0x87be) {
            return 0;
          }
          uVar3 = *param_4 & 0xfffffff8;
LAB_00055b16:
          *param_4 = uVar3;
          uVar8 = (uint)*(byte *)(iVar7 + 4) << 5;
          *param_4 = uVar3 & 0xffffe01f | uVar8;
          uVar3 = uVar3 & 0xffff001f | uVar8 | (*(byte *)(iVar7 + 8) & 7) << 0xd;
          *param_4 = uVar3;
          bVar1 = *(byte *)(iVar7 + 8);
LAB_00055a65:
          uVar8 = (bVar1 & 7) << 0x10;
          *param_4 = uVar3 & 0xfff8ffff | uVar8;
          uVar4 = (*(byte *)(iVar7 + 8) & 7) << 0x13;
          *param_4 = uVar3 & 0xffc0ffff | uVar8 | uVar4;
          *param_4 = uVar3 & 0xfe00ffff | uVar8 | uVar4 | (*(byte *)(iVar7 + 8) & 7) << 0x16;
LAB_00055a98:
          *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xe1;
          goto LAB_0005590b;
        }
        uVar3 = *param_4 & 0xfffffff8;
        *param_4 = uVar3;
        uVar8 = (uint)*(byte *)(iVar7 + 0x10 + param_5 * 4);
      }
    }
  }
  else {
    if (uVar3 < 3) {
      if (uVar3 != 0) {
        return 0;
      }
      *param_4 = *param_4 & 0xffffe018;
      goto LAB_0005590b;
    }
    if (uVar3 == 3) {
      uVar3 = *param_4 & 0xfffffff8;
      *param_4 = uVar3;
      uVar8 = (uint)(byte)param_3[1];
    }
    else {
      if (uVar3 != 4) {
        return 0;
      }
      uVar3 = *param_4 & 0xfffffff8 | 2;
      *param_4 = uVar3;
      uVar8 = (uint)(byte)param_3[1];
    }
  }
  *param_4 = uVar3 & 0xffffe01f | uVar8 << 5;
LAB_0005590b:
  if ((char)param_3[6] == '\0') {
    *(byte *)param_4 = (byte)*param_4 & 0xef;
    *param_4 = *param_4 & 0x9fffffff;
  }
  else {
    *(byte *)param_4 = (byte)*param_4 | 0x10;
    *param_4 = *param_4 & 0x9fffffff;
  }
  *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0x7f;
  return 1;
}

/* FUN_00055c4a @ 0x55c4a (112 bytes) */
int FUN_00055c4a(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  
  if ((*param_2 == 2) && (*param_3 == 2)) {
    if (param_2[1] != param_3[1]) {
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x28 + param_2[1] * 0x54);
      iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x28 + param_3[1] * 0x54);
      if (((iVar1 == 0x87c1) && (iVar2 == 0x87c1)) ||
         ((iVar1 - 0x87c2U < 2 && (iVar2 - 0x87c2U < 2)))) {
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00055cba @ 0x55cba (270 bytes) */
int FUN_00055cba(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint local_10;
  
  iVar1 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  bVar3 = false;
  iVar5 = 0;
  for (local_10 = 0; local_10 < *(uint *)(iVar1 + 0x50); local_10 = local_10 + 1) {
    while( true ) {
      if (bVar3) {
        return local_10;
      }
      if (*(char *)(iVar5 + 0x10 + *(int *)(iVar1 + 0x4c)) != '\0') break;
      bVar3 = true;
      if (*(uint *)(iVar1 + 0x50) <= local_10) goto LAB_00055d03;
    }
    iVar5 = iVar5 + 0x28;
  }
LAB_00055d03:
  if (bVar3) {
    return local_10;
  }
  *(undefined1 *)(param_2 + 4) = 0;
  uVar2 = *(uint *)(iVar1 + 0x50);
  iVar5 = (**(code **)(param_1 + 0x10))(uVar2 + 0x10,0x28);
  (**(code **)(param_1 + 0x1344))(iVar5,*(undefined4 *)(iVar1 + 0x4c),*(int *)(iVar1 + 0x50) * 0x28)
  ;
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x4c));
  *(int *)(iVar1 + 0x4c) = iVar5;
  *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + 0x10;
  iVar4 = uVar2 * 0x28;
  *(undefined1 *)(iVar5 + 0x10 + iVar4) = 1;
  *(undefined4 *)(iVar4 + 0x14 + *(int *)(iVar1 + 0x4c)) = 4;
  *(undefined4 *)(iVar4 + 0x18 + *(int *)(iVar1 + 0x4c)) = 0;
  *(undefined4 *)(iVar4 + 0x1c + *(int *)(iVar1 + 0x4c)) = 0;
  *(undefined4 *)(iVar4 + 0x20 + *(int *)(iVar1 + 0x4c)) = 0;
  *(undefined4 *)(iVar4 + 0x24 + *(int *)(iVar1 + 0x4c)) = 0;
  param_2[0x19] = param_2[0x19] + 1;
  return uVar2;
}

/* FUN_00055dc8 @ 0x55dc8 (1726 bytes) */
int FUN_00055dc8(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = ((int (*)())FUN_00053994)(param_2 + 7,param_3 + 4);
  if (0x87bd < uVar1) {
    if (uVar1 < 0x87c0) {
      iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
      iVar4 = *(int *)(iVar5 + 0x18);
      if (0x100 < iVar4 + 2U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar4 = *(int *)(iVar5 + 0x18);
        if (*(uint *)(iVar5 + 0x20) < iVar4 + 2U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
          (**(code **)(param_1 + 0x1344))
                    (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
          *(undefined4 *)(iVar5 + 0x1c) = uVar2;
          *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
          iVar4 = *(int *)(iVar5 + 0x18);
        }
      }
      iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
      ((int (*)())FUN_00055167)(iVar5,0xd,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 4,0);
      *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 4);
      ((int (*)())FUN_00055167)(iVar5 + 0x10,3,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 0x14,0);
      bVar3 = *(byte *)(iVar5 + 0x14);
      if ((bVar3 & 7) != 2) {
        *(undefined1 *)(param_2 + 4) = 0;
        bVar3 = *(byte *)(iVar5 + 0x14);
      }
      *(byte *)(iVar5 + 0x14) = bVar3 | 0x10;
      *(byte *)(iVar5 + 0x17) = *(byte *)(iVar5 + 0x17) & 0x9f;
      *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(iVar5 + 0x14);
      *(byte *)(iVar5 + 0x19) = *(byte *)(iVar5 + 0x19) & 0x1f | 0x80;
      *(byte *)(iVar5 + 0x1a) = *(byte *)(iVar5 + 0x1a) & 0xc0 | 0x24;
      *(ushort *)(iVar5 + 0x1a) = *(ushort *)(iVar5 + 0x1a) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
      return 2;
    }
    if (uVar1 == 0x87c0) {
      iVar5 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
      iVar4 = *(int *)(iVar5 + 0x18);
      if (0x100 < iVar4 + 7U) {
        *(undefined1 *)(param_2 + 4) = 0;
        iVar4 = *(int *)(iVar5 + 0x18);
        if (*(uint *)(iVar5 + 0x20) < iVar4 + 7U) {
          uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar5 + 0x20) * 0x10 + 0x100);
          (**(code **)(param_1 + 0x1344))
                    (uVar2,*(undefined4 *)(iVar5 + 0x1c),*(int *)(iVar5 + 0x20) << 4);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0x1c));
          *(undefined4 *)(iVar5 + 0x1c) = uVar2;
          *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + 0x10;
          iVar4 = *(int *)(iVar5 + 0x18);
        }
      }
      iVar5 = iVar4 * 0x10 + *(int *)(iVar5 + 0x1c);
      ((int (*)())FUN_00055cba)();
      ((int (*)())FUN_00055167)(iVar5,1,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 4,0);
      *(byte *)(iVar5 + 5) = *(byte *)(iVar5 + 5) & 0x1f | 0xa0;
      *(byte *)(iVar5 + 6) = *(byte *)(iVar5 + 6) & 0xc0 | 0x2d;
      *(ushort *)(iVar5 + 6) = *(ushort *)(iVar5 + 6) & 0xfe3f | 0x140;
      *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(iVar5 + 4);
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 4);
      ((int (*)())FUN_00055167)(iVar5 + 0x10,2,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 0x14,0);
      ((int (*)())FUN_000555c4)(iVar5 + 0x18,0);
      *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(iVar5 + 0x18);
      ((int (*)())FUN_00055167)(iVar5 + 0x20,0xd,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 0x24,0);
      *(undefined4 *)(iVar5 + 0x28) = *(undefined4 *)(iVar5 + 0x24);
      *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)(iVar5 + 0x24);
      ((int (*)())FUN_00055167)(iVar5 + 0x30,3,0,0);
      ((int (*)())FUN_000555c4)(iVar5 + 0x34,0);
      bVar3 = *(byte *)(iVar5 + 0x34);
      if ((bVar3 & 7) != 2) {
        *(undefined1 *)(param_2 + 4) = 0;
        bVar3 = *(byte *)(iVar5 + 0x34);
      }
      *(byte *)(iVar5 + 0x34) = bVar3 | 0x10;
      *(byte *)(iVar5 + 0x37) = *(byte *)(iVar5 + 0x37) & 0x9f;
      *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar5 + 0x34);
      *(byte *)(iVar5 + 0x39) = *(byte *)(iVar5 + 0x39) & 0x1f | 0x80;
      *(byte *)(iVar5 + 0x3a) = *(byte *)(iVar5 + 0x3a) & 0xc0 | 0x24;
      *(ushort *)(iVar5 + 0x3a) = *(ushort *)(iVar5 + 0x3a) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x38);
      ((int (*)())FUN_00055167)(iVar5 + 0x40,3,0,1);
      ((int (*)())FUN_000555c4)(iVar5 + 0x44,1);
      *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x10;
      *(byte *)(iVar5 + 0x47) = *(byte *)(iVar5 + 0x47) & 0x9f;
      *(undefined4 *)(iVar5 + 0x48) = *(undefined4 *)(iVar5 + 0x44);
      *(byte *)(iVar5 + 0x49) = *(byte *)(iVar5 + 0x49) & 0x1f | 0x80;
      *(byte *)(iVar5 + 0x4a) = *(byte *)(iVar5 + 0x4a) & 0xc0 | 0x24;
      *(ushort *)(iVar5 + 0x4a) = *(ushort *)(iVar5 + 0x4a) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar5 + 0x4c) = *(undefined4 *)(iVar5 + 0x48);
      ((int (*)())FUN_00055167)(iVar5 + 0x50,3,0,2);
      ((int (*)())FUN_000555c4)(iVar5 + 0x54,2);
      *(byte *)(iVar5 + 0x54) = *(byte *)(iVar5 + 0x54) | 0x10;
      *(byte *)(iVar5 + 0x57) = *(byte *)(iVar5 + 0x57) & 0x9f;
      *(undefined4 *)(iVar5 + 0x58) = *(undefined4 *)(iVar5 + 0x54);
      *(byte *)(iVar5 + 0x59) = *(byte *)(iVar5 + 0x59) & 0x1f | 0x80;
      *(byte *)(iVar5 + 0x5a) = *(byte *)(iVar5 + 0x5a) & 0xc0 | 0x24;
      *(ushort *)(iVar5 + 0x5a) = *(ushort *)(iVar5 + 0x5a) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar5 + 0x58);
      ((int (*)())FUN_00055167)(iVar5 + 0x60,3,0,3);
      ((int (*)())FUN_000555c4)(iVar5 + 100,3);
      *(byte *)(iVar5 + 100) = *(byte *)(iVar5 + 100) | 0x10;
      *(byte *)(iVar5 + 0x67) = *(byte *)(iVar5 + 0x67) & 0x9f;
      *(undefined4 *)(iVar5 + 0x68) = *(undefined4 *)(iVar5 + 100);
      *(byte *)(iVar5 + 0x69) = *(byte *)(iVar5 + 0x69) & 0x1f | 0x80;
      *(byte *)(iVar5 + 0x6a) = *(byte *)(iVar5 + 0x6a) & 0xc0 | 0x24;
      *(ushort *)(iVar5 + 0x6a) = *(ushort *)(iVar5 + 0x6a) & 0xfe3f | 0x100;
      *(undefined4 *)(iVar5 + 0x6c) = *(undefined4 *)(iVar5 + 0x68);
      return 7;
    }
  }
  return 0xffffffff;
}

/* FUN_00056486 @ 0x56486 (292 bytes) */
int FUN_00056486(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = **(int **)(*param_2 + *(int *)(param_1 + 0x118c) * 4);
  iVar2 = *(int *)(iVar3 + 0x18);
  if (0x100 < iVar2 + 1U) {
    *(undefined1 *)(param_2 + 4) = 0;
    iVar2 = *(int *)(iVar3 + 0x18);
    if (*(uint *)(iVar3 + 0x20) < iVar2 + 1U) {
      uVar1 = (**(code **)(param_1 + 0xc))(*(uint *)(iVar3 + 0x20) * 0x10 + 0x100);
      (**(code **)(param_1 + 0x1344))
                (uVar1,*(undefined4 *)(iVar3 + 0x1c),*(int *)(iVar3 + 0x20) << 4);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar3 + 0x1c));
      *(undefined4 *)(iVar3 + 0x1c) = uVar1;
      *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 0x10;
      iVar2 = *(int *)(iVar3 + 0x18);
    }
  }
  iVar3 = iVar2 * 0x10 + *(int *)(iVar3 + 0x1c);
  ((int (*)())FUN_00055167)(iVar3,3,0,0);
  ((int (*)())FUN_000555c4)(iVar3 + 4,0);
  *(byte *)(iVar3 + 7) = *(byte *)(iVar3 + 7) | 0x1e;
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(byte *)(iVar3 + 9) = *(byte *)(iVar3 + 9) & 0x1f | 0x80;
  *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & 0xc0 | 0x24;
  *(ushort *)(iVar3 + 10) = *(ushort *)(iVar3 + 10) & 0xfe3f | 0x100;
  *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & 0xe1;
  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 8);
  return 1;
}

