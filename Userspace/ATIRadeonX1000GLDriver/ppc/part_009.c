#include "decls.h"

/* FUN_00090840 @ 0x90840 (264 bytes) */
int FUN_00090840(param_1)
  int param_1;
{
  uint uVar1;
  float fVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar3;
  bool bVar4;
  
  fVar2 = FLOAT_001aa0e8;
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xfffeffff;
    *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xfffffcff | 0x43f;
  }
  else {
    bVar4 = *(float *)(param_1 + 0x2814) != FLOAT_001aa0e8;
    uVar1 = *(uint *)(param_1 + 0x1b84) & 0xfffffbc0;
    *(uint *)(param_1 + 0x1b84) = uVar1 | 0x300;
    if ((bVar4) || (*(float *)(param_1 + 0x2818) != fVar2)) {
      *(uint *)(param_1 + 0x1b84) = uVar1 | 0x305;
    }
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) | 0x10000;
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
  *puVar3 = 0x82c;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b84);
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = 0x887;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b74);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x10;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_00090960 @ 0x90960 (48 bytes) */
int FUN_00090960(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    return;
  }
  *(undefined1 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1cc) = 0;
  ((int (*)())FUN_00090840)();
  return;
}

/* FUN_00090990 @ 0x90990 (772 bytes) */
int FUN_00090990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 0x10);
  if ((*(int *)(((unsigned char *)0x00003e28) + iVar4) == 0) || (bVar1 = true, ((unsigned char *)0x000013a8)[param_1] != '\0')) {
    bVar1 = false;
  }
  if ((((((*(char *)(iVar3 + 0x21) != '\0') && ((param_2[3] & 0x10000000) == 0)) &&
        ((*(int *)(*(int *)(iVar3 + 0x18) + 0x198) == 0 || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
       ((((unsigned char *)0x00004304)[iVar4] == '\0' || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
      (("}J3x})+x|B;x}k"[iVar4 + 2] == '\0' || ("}J3x})+x|B;x}k"[iVar4 + 6] == '\0')))) && (!bVar1))
  {
    if (*(char *)(iVar3 + 0x20) == '\0') {
      *(undefined1 *)(iVar3 + 0x20) = 1;
      *(undefined1 *)(param_1 + 299) = 1;
      *(undefined1 *)(param_1 + 0x125) = 0;
      *(undefined1 *)(param_1 + 0x126) = 0;
      *(undefined1 *)(param_1 + 0x124) = 0;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xbfffffff;
      param_2[4] = 0xffffffff;
      *param_2 = 0xffffffff;
      param_2[2] = param_2[2] | 0xfffffffd;
      param_2[1] = param_2[1] | 0x3ffffff;
      param_2[3] = param_2[3] | 0x7ffffff;
      *(undefined1 *)(param_1 + 0x2c) = 0xff;
      *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
      *(undefined1 *)(param_1 + 0x2d) = 0xf;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined2 *)(param_1 + 0x34) = 0xffff;
      *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
      *(undefined1 *)(param_1 + 0x2a) = 1;
      *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
      *(undefined2 *)(param_1 + 0x32) = 0xffff;
      *(undefined1 *)(param_1 + 0x2e) = 3;
      *(undefined1 *)(param_1 + 0x30) = 7;
      *(undefined4 *)(param_1 + 0x180c) = 5;
      *(undefined4 *)(param_1 + 0x1810) = 0x1f;
      uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
      if (uVar2 != 0) {
        iVar3 = param_1;
        if (uVar2 == 0) {
          uVar2 = 1;
        }
        do {
          *(undefined1 *)(iVar3 + 0x1814) = 0x3f;
          *(undefined1 *)(iVar3 + 0x181c) = 3;
          iVar3 = iVar3 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(undefined1 *)(param_1 + 0x2803) = 1;
      *(undefined1 *)(param_1 + 0x23ec) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined1 *)(param_1 + 0x247d) = 1;
      *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
      return;
    }
    return;
  }
  if (*(char *)(iVar3 + 0x20) != '\0') {
    *(undefined1 *)(iVar3 + 0x20) = 0;
    *(undefined1 *)(param_1 + 299) = 1;
    *(undefined1 *)(param_1 + 0x126) = 1;
    *(undefined1 *)(param_1 + 0x124) = 1;
    *(undefined1 *)(param_1 + 0x125) = 0;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
    param_2[4] = 0xffffffff;
    *param_2 = 0xffffffff;
    param_2[2] = param_2[2] | 0xfffffffd;
    param_2[1] = param_2[1] | 0x3ffffff;
    param_2[3] = param_2[3] | 0x7ffffff;
    *(undefined1 *)(param_1 + 0x2c) = 0xff;
    *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
    *(undefined1 *)(param_1 + 0x2d) = 0xf;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined2 *)(param_1 + 0x34) = 0xffff;
    *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
    *(undefined1 *)(param_1 + 0x2a) = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
    *(undefined2 *)(param_1 + 0x32) = 0xffff;
    *(undefined1 *)(param_1 + 0x2e) = 3;
    *(undefined1 *)(param_1 + 0x30) = 7;
    *(undefined4 *)(param_1 + 0x180c) = 5;
    *(undefined4 *)(param_1 + 0x1810) = 0x1f;
    uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar2 != 0) {
      iVar4 = param_1;
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      do {
        *(undefined1 *)(iVar4 + 0x1814) = 0x3f;
        *(undefined1 *)(iVar4 + 0x181c) = 3;
        iVar4 = iVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    *(undefined1 *)(param_1 + 0x2803) = 1;
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined1 *)(param_1 + 0x247d) = 1;
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
  }
  *(undefined4 *)(iVar3 + 0x1cc) = 0;
  return;
}

/* FUN_00090ca0 @ 0x90ca0 (1240 bytes) */
int FUN_00090ca0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *param_3 = param_2;
  if (param_2 == 1) {
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      iVar5 = param_1;
      do {
        if (((*(char *)(iVar5 + 0x6c4) == '\0') && (*(char *)(iVar5 + 0x6c5) == '\0')) &&
           (*(char *)(iVar5 + 0x6c6) == '\0')) {
          param_3[1] = uVar7;
          iVar3 = DAT_001dbd90;
          iVar5 = DAT_001dbd8c;
          iVar6 = DAT_001dbd88;
          iVar4 = uVar7 * 4 + param_1;
          param_3[2] = DAT_001dbd84;
          param_3[5] = iVar3;
          param_3[3] = iVar6;
          param_3[4] = iVar5;
          iVar3 = DAT_001dbd80;
          iVar5 = DAT_001dbd7c;
          iVar6 = DAT_001dbd78;
          param_3[6] = DAT_001dbd74;
          param_3[9] = iVar3;
          param_3[7] = iVar6;
          param_3[8] = iVar5;
          *(undefined1 *)(iVar4 + 0x6c6) = 1;
          *(undefined1 *)(iVar4 + 0x6c4) = 1;
          *(undefined1 *)(iVar4 + 0x6c5) = 1;
          if (uVar7 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
          goto LAB_00090e50;
        }
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else if (param_2 == 0) {
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      iVar5 = param_1;
      do {
        if (((*(char *)(iVar5 + 0x6c4) == '\0') && (*(char *)(iVar5 + 0x6c5) == '\0')) &&
           ((*(char *)(iVar5 + 0x6c6) == '\0' && (*(char *)(iVar5 + 0x6c7) == '\0')))) {
          param_3[1] = uVar7;
          iVar3 = DAT_001dbd30;
          iVar5 = DAT_001dbd2c;
          iVar6 = DAT_001dbd28;
          iVar4 = uVar7 * 4 + param_1;
          param_3[2] = DAT_001dbd24;
          param_3[5] = iVar3;
          param_3[3] = iVar6;
          param_3[4] = iVar5;
          iVar3 = DAT_001dbd20;
          iVar5 = DAT_001dbd1c;
          iVar6 = DAT_001dbd18;
          param_3[6] = DAT_001dbd14;
          param_3[9] = iVar3;
          param_3[7] = iVar6;
          param_3[8] = iVar5;
          *(undefined1 *)(iVar4 + 0x6c7) = 1;
          *(undefined1 *)(iVar4 + 0x6c4) = 1;
          *(undefined1 *)(iVar4 + 0x6c5) = 1;
          *(undefined1 *)(iVar4 + 0x6c6) = 1;
          if (uVar7 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
LAB_00090e50:
          *(uint *)(param_1 + 0x3d0) = uVar7 + 1;
          return 0;
        }
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    if (param_2 != 2) {
      return 4;
    }
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      if (*(char *)(param_1 + 0x6c4) == '\0') {
LAB_00090e7c:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd10;
        iVar5 = DAT_001dbd0c;
        iVar6 = DAT_001dbd08;
        param_3[2] = DAT_001dbd04;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001fa600;
        iVar5 = DAT_001fa5fc;
        iVar6 = DAT_001fa5f8;
        param_3[9] = DAT_001fa604;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c4) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      else if (*(char *)(param_1 + 0x6c5) == '\0') {
LAB_00090efc:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd70;
        iVar5 = DAT_001dbd6c;
        iVar6 = DAT_001dbd68;
        param_3[2] = DAT_001dbd64;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcec;
        iVar5 = DAT_001dbce8;
        iVar6 = DAT_001dbce4;
        param_3[9] = DAT_001dbcf0;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c5) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      else if (*(char *)(param_1 + 0x6c6) == '\0') {
LAB_00090f7c:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd60;
        iVar5 = DAT_001dbd5c;
        iVar6 = DAT_001dbd58;
        param_3[2] = DAT_001dbd54;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcfc;
        iVar5 = DAT_001dbcf8;
        iVar6 = DAT_001dbcf4;
        param_3[9] = DAT_001dbd00;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c6) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) {
LAB_00091070:
          *(uint *)(param_1 + 0x3d0) = uVar7 + 1;
          return 0;
        }
      }
      else {
        cVar2 = *(char *)(param_1 + 0x6c7);
        iVar5 = param_1;
        while (cVar2 != '\0') {
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + -1;
          if (iVar6 == 0) goto LAB_00091090;
          if (*(char *)(iVar5 + 0x6c8) == '\0') goto LAB_00090e7c;
          if (*(char *)(iVar5 + 0x6c9) == '\0') goto LAB_00090efc;
          if (*(char *)(iVar5 + 0x6ca) == '\0') goto LAB_00090f7c;
          pcVar1 = (char *)(iVar5 + 0x6cb);
          iVar5 = iVar5 + 4;
          cVar2 = *pcVar1;
        }
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd50;
        iVar5 = DAT_001dbd4c;
        iVar6 = DAT_001dbd48;
        param_3[2] = DAT_001dbd44;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcdc;
        iVar5 = DAT_001dbcd8;
        iVar6 = DAT_001dbcd4;
        param_3[9] = DAT_001dbce0;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c7) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      return 0;
    }
  }
LAB_00091090:
  param_3[1] = -1;
  iVar3 = DAT_001fa614;
  iVar5 = DAT_001fa610;
  iVar6 = DAT_001fa60c;
  param_3[2] = DAT_001fa608;
  param_3[5] = iVar3;
  param_3[3] = iVar6;
  param_3[4] = iVar5;
  iVar3 = DAT_001dbd40;
  iVar5 = DAT_001dbd3c;
  iVar6 = DAT_001dbd38;
  param_3[6] = DAT_001dbd34;
  param_3[9] = iVar3;
  param_3[7] = iVar6;
  param_3[8] = iVar5;
  return 7;
}

/* FUN_000911a0 @ 0x911a0 (316 bytes) */
int FUN_000911a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 1) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  if (iVar1 == 0) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  iVar1 = param_2[6];
  if (iVar1 != 1) {
    if (iVar1 == 0) {
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        return;
      }
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
      return;
    }
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
  return;
}

/* FUN_000912f0 @ 0x912f0 (208 bytes) */
int FUN_000912f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int *param_5;
{
  uint uVar1;
  
  uVar1 = param_2 - 8;
  if (uVar1 < 2) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    if (param_3 == 1) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2dc);
    }
    else if (param_3 == 0) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2d8);
    }
    else if (param_3 == 2) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2e0);
    }
    else {
      if (param_3 != 3) {
        return 4;
      }
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2ec);
    }
  }
  else {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_5 = *(int *)(param_2 * 4 + param_1 + 0xc);
  }
  return (uint)(*param_5 == -1) << 1;
}

/* FUN_000913e0 @ 0x913e0 (224 bytes) */
int FUN_000913e0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 2) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_4 = *(int *)(param_1 + 0x58);
  }
  else {
    if (3 < param_2) {
      return 4;
    }
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    *param_4 = *(int *)((param_2 & 1) * 4 + param_1 + 800);
  }
  uVar2 = 2;
  if (*param_4 != -1) {
    iVar1 = (param_2 & 1) * 4;
    uVar2 = 0;
    *param_5 = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[1] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[2] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[3] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
  }
  return uVar2;
}

/* FUN_000914e0 @ 0x914e0 (492 bytes) */
int FUN_000914e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000916d0 @ 0x916d0 (420 bytes) */
int FUN_000916d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd44,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091880 @ 0x91880 (248 bytes) */
int FUN_00091880(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x510) == -1) {
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)();
      }
      else {
        ((int (*)())FUN_000914e0)();
      }
      iVar4 = *(int *)(param_1 + 0x3f8);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x50c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x510),
                 param_1 + 0x514,**(undefined4 **)(param_1 + 0x3ec),iVar4);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091980 @ 0x91980 (176 bytes) */
int FUN_00091980(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x6a0) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x69c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001314) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x6a0),
                 param_1 + 0x6a4,param_2,param_3,&DAT_001dbcd4,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091a30 @ 0x91a30 (352 bytes) */
int FUN_00091a30(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x444);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x448);
      iVar2 = *(int *)(param_1 + 0xc4);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091b90 @ 0x91b90 (460 bytes) */
int FUN_00091b90(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x498) != -1) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x12a) == '\0') {
    iVar4 = *(int *)(param_1 + 4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x494);
    if (iVar1 != 0) {
      return 7;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x448);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091a30)();
      iVar4 = *(int *)(param_1 + 0x448);
      if (iVar4 == -1) {
        return 2;
      }
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3ec);
    _memcpy((void *)(param_1 + 0x494),(void *)(param_1 + 0x444),0x28);
  }
  iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
  if (iVar1 != 0) {
    return 7;
  }
  uVar7 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = **(undefined4 **)(param_1 + 0x3ec);
  uVar6 = *(undefined4 *)(param_1 + 0x498);
  (**(code **)(((unsigned char *)0x000012e4) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar2,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x00001318) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar5,local_64,auStack_50,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x000012ec) + iVar3))
            (param_1,uVar7,uVar6,&DAT_001dbd84,uVar5,local_64,auStack_50,&DAT_001fa5e8);
  ((int (*)())FUN_000911a0)(param_1,auStack_68);
  return 0;
}

/* FUN_00091d70 @ 0x91d70 (300 bytes) */
int FUN_00091d70(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x470) == -1) {
    if (*(char *)(iVar2 + 0x12a) == '\0') {
      iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x46c);
      if (iVar1 != 0) {
        return 7;
      }
    }
    else {
      if ((*(int *)(param_1 + 0x448) == -1) && (((int (*)())FUN_00091a30)(), *(int *)(param_1 + 0x448) == -1)) {
        return 2;
      }
      _memcpy((void *)(param_1 + 0x46c),(void *)(param_1 + 0x444),0x28);
    }
    (**(code **)(((unsigned char *)0x000012ec) + iVar2))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x470),
               &DAT_001dbd84,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8),
               *(undefined4 *)(param_1 + 0x344),&DAT_001fa5f8);
  }
  return 0;
}

/* FUN_00091eb0 @ 0x91eb0 (648 bytes) */
int FUN_00091eb0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = 0;
  iVar6 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x560) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x55c);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x560);
      uVar3 = *(undefined4 *)(param_1 + 0x5c);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
      if (param_2 < 4) {
        if (param_3 == 0) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd74,&DAT_001fa5e8);
          uVar1 = 0;
        }
        else {
          local_58 = DAT_001fa608;
          local_48 = DAT_001dbd74;
          local_54 = DAT_001fa60c;
          local_4c = DAT_001fa614;
          local_50 = DAT_001fa610;
          local_3c = DAT_001dbd80;
          local_44 = DAT_001dbd78;
          local_40 = DAT_001dbd7c;
          if (param_2 == 1) {
            local_40 = 4;
            local_44 = 4;
            local_54 = 1;
          }
          else if (param_2 == 0) {
            local_40 = 4;
            local_58 = 1;
            local_48 = 4;
            local_44 = 4;
          }
          else if (param_2 == 2) {
            local_50 = 1;
            local_40 = 4;
          }
          else if (param_2 == 3) {
            local_4c = 1;
          }
          local_30 = 1;
          local_38 = 1;
          local_34 = 1;
          local_2c = 0;
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&local_48,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar6))
                    (param_1,uVar4,uVar5,&local_58,**(undefined4 **)(param_1 + 0x3ec),uVar5,
                     &DAT_001dbdb4,&local_38);
          uVar1 = 0;
        }
      }
      else {
        (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                  (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd14,&DAT_001fa5e8);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* FUN_00092150 @ 0x92150 (200 bytes) */
int FUN_00092150(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar4 = *(int *)(param_1 + 0x510);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091880)();
      iVar4 = *(int *)(param_1 + 0x510);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x534);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001318) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x538),
                 param_1 + 0x53c,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x524,
                 &DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092220 @ 0x92220 (296 bytes) */
int FUN_00092220(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) != -1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x538);
  if (iVar4 == -1) {
    ((int (*)())FUN_00092150)();
    iVar4 = *(int *)(param_1 + 0x538);
    if (iVar4 != -1) goto LAB_0009226c;
LAB_00092320:
    uVar1 = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(param_1 + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)(param_1);
      }
      else {
        ((int (*)())FUN_000914e0)(param_1);
      }
      if (*(int *)(param_1 + 0x3f8) == -1) goto LAB_00092320;
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x41c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x54c);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092350 @ 0x92350 (512 bytes) */
int FUN_00092350(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [40];
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4c0) != -1) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x420);
  if (iVar3 == -1) {
    ((int (*)())FUN_00092220)();
    iVar3 = *(int *)(param_1 + 0x420);
    if (iVar3 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar2 + 0x128) == '\0') {
    if (*(char *)(iVar2 + 300) == '\0') {
      if (*(int *)(param_1 + 0x448) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091a30)(param_1);
      iVar4 = *(int *)(param_1 + 0x448);
    }
    else {
      if (*(int *)(param_1 + 0x470) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091d70)(param_1);
      iVar4 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    if (*(int *)(param_1 + 0x498) != -1) goto LAB_00092420;
    ((int (*)())FUN_00091b90)(param_1);
    iVar4 = *(int *)(param_1 + 0x498);
  }
  if (iVar4 == -1) {
    return 2;
  }
LAB_00092420:
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x4bc);
  if (iVar4 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x4c0);
    iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
    if (iVar4 == 0) {
      uVar6 = **(undefined4 **)(param_1 + 0x3ec);
      uVar5 = **(undefined4 **)(param_1 + 0x3f0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                (param_1,uVar5,local_64,auStack_60,uVar6,iVar3,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f8) + iVar2))
                (param_1,uVar5,uVar1,&DAT_001dbd84,uVar6,local_64,auStack_50,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_68);
      return 0;
    }
  }
  return 7;
}

/* FUN_00092570 @ 0x92570 (796 bytes) */
int FUN_00092570(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88[0];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4e8) == -1) {
    if ((*(int *)(param_1 + 0x4c0) == -1) && (((int (*)())FUN_00092350)(), *(int *)(param_1 + 0x4c0) == -1)) {
      return 2;
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x4e4);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x4e8);
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_a8);
      if (iVar2 == 0) {
        iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_80);
        if (iVar2 == 0) {
          uVar5 = **(undefined4 **)(param_1 + 0x3ec);
          uVar4 = **(undefined4 **)(param_1 + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&DAT_001dbdb4,&DAT_001fa5e8);
          local_d8 = 4;
          local_d4 = 4;
          local_cc = 4;
          local_d0 = local_88[0];
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&local_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + iVar3))
                    (param_1,uVar4,local_7c,auStack_78,uVar5,local_7c,&DAT_001dbdb4,&DAT_001dbd94);
          local_c8 = *(undefined4 *)(param_1 + 0x4d4);
          local_c4 = *(undefined4 *)(param_1 + 0x4d8);
          local_b0 = 4;
          local_d0 = 4;
          local_cc = 4;
          local_d8 = local_90;
          local_d4 = local_8c;
          local_c0 = 4;
          local_bc = 4;
          local_b8[0] = local_68;
          local_b4 = local_64;
          local_ac = local_5c;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_d8,&DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_a8);
          ((int (*)())FUN_000911a0)(param_1,auStack_80);
          return 0;
        }
      }
    }
    uVar1 = 7;
  }
  return uVar1;
}

/* FUN_000928a0 @ 0x928a0 (792 bytes) */
int FUN_000928a0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  
  uVar4 = 0;
  iVar10 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    puVar2 = *(undefined4 **)(param_1 + 0x3ec);
    uVar4 = *(undefined4 *)(param_1 + 0x330);
    uVar8 = **(undefined4 **)(param_1 + 0x3f0);
    uVar6 = puVar2[2];
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar10 + 4) + 0x10)) == -0x7bae) {
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar10) & 4) == 0) {
          ((int (*)())FUN_000916d0)();
        }
        else {
          ((int (*)())FUN_000914e0)();
        }
        iVar3 = *(int *)(param_1 + 0x3f8);
        if (iVar3 == -1) {
          return 2;
        }
        puVar2 = *(undefined4 **)(param_1 + 0x3ec);
      }
      uVar9 = *puVar2;
      puVar2 = &DAT_001dbcf4;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x54);
      uVar9 = puVar2[1];
      iVar3 = *(int *)(param_1 + 0x50);
      if (iVar1 == 1) {
        puVar2 = &DAT_001dbce4;
      }
      else if (iVar1 == 0) {
        puVar2 = &DAT_001fa5f8;
      }
      else if (iVar1 == 2) {
        puVar2 = &DAT_001dbcf4;
      }
      else if (iVar1 == 3) {
        puVar2 = &DAT_001dbcd4;
      }
      else {
        puVar2 = &DAT_001dbd14;
      }
    }
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x584);
    if (iVar1 == 0) {
      uVar7 = *(undefined4 *)(param_1 + 0x588);
      iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
      if (iVar1 == 0) {
        iVar5 = *(int *)(param_1 + 0x3d4);
        iVar1 = *(int *)(*(int *)(iVar5 + 4) + 0x10);
        if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
           (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5)) {
          (**(code **)(((unsigned char *)0x000012e4) + iVar5))(param_1,uVar8,local_64,auStack_60,uVar9,iVar3);
        }
        else {
          (**(code **)(((unsigned char *)0x000012ec) + iVar5))(param_1,uVar8,local_64,auStack_60,uVar9,iVar3,puVar2)
          ;
        }
        uVar9 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012ec) + iVar10))
                  (param_1,uVar8,local_64,auStack_60,uVar6,uVar4,&DAT_001dbcf4);
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = (undefined4 *)(param_1 + 0x58c);
          if (-1 < *(int *)(iVar10 + 0x44)) {
            uVar7 = *(undefined4 *)(param_1 + 0x70);
            puVar2 = &DAT_001dbd44;
            uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
          }
        }
        else {
          uVar7 = *(undefined4 *)(param_1 + 0x70);
          puVar2 = &DAT_001dbd04;
          uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        }
        (**(code **)(((unsigned char *)0x00001320) + iVar10))
                  (param_1,uVar8,uVar7,puVar2,uVar9,local_64,auStack_50,&DAT_001fa5e8);
        ((int (*)())FUN_000911a0)(param_1,auStack_68);
        return 0;
      }
    }
    uVar4 = 7;
  }
  return uVar4;
}

/* FUN_00092bf0 @ 0x92bf0 (328 bytes) */
int FUN_00092bf0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if (param_2 < 3) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(0x1998);
    *(int *)((int)pvVar1 + 0x3d4) = param_1;
    _memset(pvVar1,-1,0x68);
    _memset((void *)((int)pvVar1 + 0x68),-1,0x3c);
    _memset((void *)((int)pvVar1 + 0xa4),-1,0x324);
    *(uint *)((int)pvVar1 + 0x3d8) = param_2;
    *(undefined4 *)((int)pvVar1 + 0x3e0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3c8) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3cc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3d0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3e4) = *(undefined4 *)(&DAT_001dbeac + param_2 * 4);
    *(undefined4 *)((int)pvVar1 + 1000) = *(undefined4 *)(&DAT_001dbea4 + param_2 * 4);
    *(undefined **)((int)pvVar1 + 0x3ec) = (PTR_DAT_001dbe84)[param_2];
    *(undefined **)((int)pvVar1 + 0x3f0) = (PTR_DAT_001dbe3c)[param_2];
    _memset((void *)((int)pvVar1 + 0x3f4),-1,0x2d0);
    _memset((void *)((int)pvVar1 + 0x6c4),0,0x80);
    *(undefined1 *)((int)pvVar1 + 0x744) = param_3;
    *(code **)((int)pvVar1 + 0x748) = FUN_00090ca0;
    *(code **)((int)pvVar1 + 0x74c) = FUN_000911a0;
    if (*(code **)(((unsigned char *)0x000012d4) + param_1) != (code *)0x0) {
      (**(code **)(((unsigned char *)0x000012d4) + param_1))(param_1,pvVar1);
    }
  }
  return pvVar1;
}

/* FUN_00092d40 @ 0x92d40 (340 bytes) */
int FUN_00092d40(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if ((param_1[0x1a] != -1) && (iVar3 = *param_1, iVar3 != -1)) {
    if (param_2 != 0) {
      if (7 < param_3) {
        return 3;
      }
      if (param_1[param_3 + 0x21] == -1) {
        return 2;
      }
    }
    iVar1 = param_1[0xf5];
    uVar2 = *(undefined4 *)(param_1[0xfb] + 4);
    (**(code **)(((unsigned char *)0x000012e8) + iVar1))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar2,iVar3,
               &DAT_001dbd14,&DAT_001fa5e8);
    if (((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) ||
       (((int (*)())FUN_00091980)(param_1,uVar2,iVar3), param_1[0x1a8] != -1)) {
      if (param_2 != 0) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar1))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],
                   &DAT_001dbd24,uVar2,iVar3,&DAT_001dbd14,&DAT_001fa5e8);
      }
      return 0;
    }
  }
  return 2;
}

/* FUN_00092ea0 @ 0x92ea0 (324 bytes) */
int FUN_00092ea0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == 3) {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x74);
    if ((iVar3 == -1) || (iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc), iVar5 == -1)) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
  }
  else {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x7c);
    if (iVar3 == -1) {
      return 2;
    }
    iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc);
    if (iVar5 == -1) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
  }
  if ((iVar1 == 0) && (iVar3 == *(int *)(param_1 + 0x70))) {
    puVar4 = &DAT_001dbd84;
  }
  else {
    puVar4 = &DAT_001dbd24;
  }
  (**(code **)(((unsigned char *)0x000012e8) + iVar6))
            (param_1,uVar2,iVar3,puVar4,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar5,
             &DAT_001dbd14,&DAT_001fa5e8);
  return 0;
}

/* FUN_00093000 @ 0x93000 (288 bytes) */
int FUN_00093000(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  if (7 < param_2) {
    return 3;
  }
  iVar2 = param_2 * 4 + param_1;
  iVar3 = *(int *)(iVar2 + 0x84);
  if (((iVar3 != -1) && (iVar2 = *(int *)(iVar2 + 0x2c), iVar2 != -1)) &&
     ((bVar1 = *(char *)(param_1 + 0x744) == '\0', bVar1 || (*(int *)(param_1 + 0xa4) != -1)))) {
    if (bVar1) {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))();
      return 0;
    }
    if (*(int *)(param_1 + 0x6a0) != -1) {
      (**(code **)(((unsigned char *)0x000012ec) + *(int *)(param_1 + 0x3d4)))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),iVar3,&DAT_001dbd24,
                 *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar2,&DAT_001dbd14);
      return 0;
    }
  }
  return 2;
}

/* FUN_00093130 @ 0x93130 (168 bytes) */
int FUN_00093130(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x6c) == -1) || (*(int *)(param_1 + 0x4c) == -1)) {
      uVar1 = 2;
    }
    else {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x1c),*(int *)(param_1 + 0x6c),
                 &DAT_001dbd24,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                 *(int *)(param_1 + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000931e0 @ 0x931e0 (404 bytes) */
int FUN_000931e0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x70);
    if ((iVar1 == -1) || (*(int *)(param_1 + 0x50) == -1)) {
      uVar3 = 2;
    }
    else if ((*(uint *)(param_1 + 0x54) < 4) &&
            ((((*(int *)(param_1 + 0x3d8) != 0 || (iVar1 == *(int *)(param_1 + 0x74))) ||
              (iVar1 == *(int *)(param_1 + 0x78))) ||
             ((iVar1 == *(int *)(param_1 + 0x7c) || (iVar1 == *(int *)(param_1 + 0x80))))))) {
      uVar3 = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 1;
      if (-1 < *(int *)(*(int *)(param_1 + 0x3d4) + 0x44)) {
        iVar1 = *(int *)(param_1 + 0x54);
        if (iVar1 == 1) {
          puVar4 = &DAT_001dbce4;
        }
        else if (iVar1 == 0) {
          puVar4 = &DAT_001fa5f8;
        }
        else if (iVar1 == 2) {
          puVar4 = &DAT_001dbcf4;
        }
        else if (iVar1 == 3) {
          puVar4 = &DAT_001dbcd4;
        }
        else {
          puVar4 = &DAT_001dbd14;
        }
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = &DAT_001dbd44;
        }
        else {
          puVar2 = &DAT_001dbd04;
        }
        (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
                   *(undefined4 *)(param_1 + 0x70),puVar2,
                   *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(undefined4 *)(param_1 + 0x50),
                   puVar4,&DAT_001fa5e8);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

/* FUN_00093510 @ 0x93510 (1220 bytes) */
int FUN_00093510(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined1 auStack_e8 [4];
  undefined4 local_e4;
  undefined1 auStack_c0 [4];
  undefined4 local_bc;
  undefined1 auStack_98 [4];
  undefined4 local_94;
  undefined *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined1 *local_5c;
  int *local_58;
  undefined1 *local_54;
  
  if (param_1 == 0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar2 = 0;
    iVar3 = param_1;
    uVar9 = param_3;
    do {
      iVar1 = *(int *)(param_2 + iVar2 * 4);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_1 + 4);
      }
      else {
        if (iVar1 != 1) {
          return 3;
        }
        iVar1 = *(int *)(param_1 + 100);
      }
      if (iVar1 == -1) {
        return 2;
      }
      if (*(int *)(iVar3 + 0xc4) == -1) {
        return 2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar3 = *(int *)(param_2 + param_3 * 4);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 4);
    }
    else {
      if (iVar3 != 1) {
        return 3;
      }
      iVar3 = *(int *)(param_1 + 100);
    }
    if (iVar3 == -1) {
      return 2;
    }
    if (*(int *)(param_3 * 4 + param_1 + 0xc4) == -1) {
      return 2;
    }
  }
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) != -1) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x560) == -1) &&
     (((int (*)())FUN_00091eb0)(param_1,param_3,param_4), *(int *)(param_1 + 0x560) == -1)) {
    return 2;
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    param_3 = param_3 + 1;
  }
  iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x444);
  if ((iVar2 == 0) && (iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_e8), iVar2 == 0)) {
    local_5c = auStack_c0;
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_5c);
    if (iVar2 == 0) {
      local_54 = auStack_98;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_54);
      if (iVar2 == 0) {
        puVar7 = *(undefined4 **)(param_1 + 0x3ec);
        uVar6 = puVar7[2];
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        if (param_3 == 0) {
          local_68 = &DAT_001e3520;
          local_64 = &DAT_001e3520;
          local_60 = &DAT_001e3520;
LAB_0009388c:
          uVar8 = *puVar7;
          uVar6 = *(undefined4 *)(param_1 + 0x448);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_68 + -0x781c,uVar8,local_e4,&DAT_001dbd14,
                     &DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_64 + -0x77bc,uVar8,local_bc,&DAT_001dbd14,
                     &DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,uVar6,local_60 + -0x77cc,uVar8,local_94,&DAT_001dbd14,
                     &DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_e8);
          ((int (*)())FUN_000911a0)(param_1,local_5c);
          ((int (*)())FUN_000911a0)(param_1,local_54);
          return 0;
        }
        local_58 = (int *)(param_1 + 0xc4);
        local_68 = &DAT_001e3520;
        local_64 = &DAT_001e3520;
        local_60 = &DAT_001e3520;
LAB_00093754:
        uVar9 = 0;
        puVar7 = (undefined4 *)(local_68 + -0x781c);
        piVar5 = local_58;
        do {
          iVar2 = *piVar5;
          uVar9 = uVar9 + 1;
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_e4,puVar7,uVar6,iVar2,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_bc,puVar7,uVar6,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_94,puVar7,uVar6,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8);
          if (param_3 <= uVar9) {
            puVar7 = *(undefined4 **)(param_1 + 0x3ec);
            goto LAB_0009388c;
          }
          if (uVar9 == 1) {
            puVar7 = (undefined4 *)(local_64 + -0x77bc);
          }
          else {
            if (uVar9 == 0) goto LAB_00093754;
            if (uVar9 == 2) {
              puVar7 = (undefined4 *)(local_60 + -0x77cc);
            }
            else {
              puVar7 = (undefined4 *)0x0;
              if (uVar9 == 3) {
                puVar7 = &DAT_001dbd44;
              }
            }
          }
          piVar5 = piVar5 + 1;
        } while( true );
      }
    }
  }
  return 7;
}

/* FUN_000939e0 @ 0x939e0 (52 bytes) */
int FUN_000939e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 4) != -1) && (*(int *)(param_1 + 0x344) != -1)) {
      uVar1 = ((int (*)())FUN_00091d70)();
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* FUN_00093a20 @ 0x93a20 (24 bytes) */
int FUN_00093a20(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) != -1) {
    uVar1 = ((int (*)())FUN_00091b90)();
    return uVar1;
  }
  return 2;
}

/* FUN_00093a40 @ 0x93a40 (3576 bytes) */
int FUN_00093a40(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  uint param_6;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined *puVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uStack0000002c;
  undefined1 auStack_1c8 [4];
  int local_1c4;
  undefined1 auStack_1a0 [4];
  undefined4 local_19c;
  undefined1 auStack_178 [4];
  int local_174;
  undefined1 auStack_150 [4];
  undefined4 local_14c;
  undefined1 auStack_128 [4];
  undefined4 local_124 [9];
  undefined1 auStack_100 [4];
  undefined4 local_fc;
  undefined1 auStack_d8 [4];
  undefined4 local_d4;
  undefined1 auStack_b0 [4];
  undefined4 local_ac;
  undefined *local_88[0];
  undefined1 *local_84;
  undefined *local_80;
  undefined1 *local_7c;
  undefined1 *local_78;
  undefined *local_74;
  undefined1 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  undefined *local_64;
  undefined *local_60;
  undefined *local_5c;
  undefined *local_58;
  undefined *local_54;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar4 = 0;
    piVar6 = param_1;
    uVar15 = param_3;
    do {
      iVar2 = *(int *)(param_2 + iVar4 * 4);
      if (iVar2 == 0) {
        iVar2 = *param_1;
      }
      else {
        if (iVar2 != 1) {
          return 3;
        }
        iVar2 = param_1[0x18];
      }
      if (iVar2 == -1) {
        return 2;
      }
      if (piVar6[0x29] == -1) {
        return 2;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
      uVar15 = uVar15 - 1;
    } while (uVar15 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar4 = *(int *)(param_2 + param_3 * 4);
    if (iVar4 == 0) {
      iVar4 = *param_1;
    }
    else {
      if (iVar4 != 1) {
        return 3;
      }
      iVar4 = param_1[0x18];
    }
    if (iVar4 == -1) {
      return 2;
    }
    if (param_1[param_3 + 0x29] == -1) {
      return 2;
    }
  }
  if (param_1[0x1a] != -1) {
    bVar1 = param_5 == 0;
    if (!bVar1) {
      if (7 < param_6) {
        return 3;
      }
      if (param_1[param_6 + 0x21] == -1) {
        return 2;
      }
    }
    iVar4 = param_1[0xf5];
    uStack0000002c = param_6;
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar4) & 4) == 0) {
      if ((param_1[0x158] != -1) || (((int (*)())FUN_00091eb0)(param_1,param_3,param_4), param_1[0x158] != -1)) {
        if ((param_3 < 4) && (param_4 != 0)) {
          param_3 = param_3 + 1;
        }
        local_68 = auStack_1a0;
        iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_68);
        if ((iVar2 == 0) && (iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_1c8), iVar2 == 0)) {
          local_84 = auStack_150;
          iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_84);
          if (iVar2 == 0) {
            local_7c = auStack_128;
            iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_7c);
            if (iVar2 == 0) {
              uVar8 = *(undefined4 *)param_1[0xfc];
              uVar7 = *(undefined4 *)param_1[0xfb];
              uVar13 = ((undefined4 *)param_1[0xfb])[2];
              if (param_3 == 0) {
LAB_000944c4:
                if (bVar1) {
                  uVar8 = *(undefined4 *)(param_1[0xfc] + 8);
                  iVar2 = param_1[0x1a];
                }
                else {
                  iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_178);
                  if (iVar2 != 0) {
                    return 7;
                  }
                  uVar8 = *(undefined4 *)param_1[0xfc];
                  iVar2 = local_174;
                }
                local_88[0] = &DAT_001e3a54;
                local_80 = &DAT_001f3a54;
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd04,uVar7,local_19c,&DAT_001dbd14,
                           &DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd64,uVar7,local_1c4,&DAT_001dbd14,
                           &DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,iVar2,&DAT_001dbd54,uVar7,local_14c,&DAT_001dbd14,
                           &DAT_001fa5e8);
                if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,local_124[0],&DAT_001dbd14,
                             &DAT_001fa5e8);
                  ((int (*)())FUN_000911a0)(param_1,local_68);
                  ((int (*)())FUN_000911a0)(param_1,auStack_1c8);
                  ((int (*)())FUN_000911a0)(param_1,local_84);
                  ((int (*)())FUN_000911a0)(param_1,local_7c);
                }
                else {
                  (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                            (param_1,*(undefined4 *)param_1[0xfc],local_19c,&DAT_001dbd44,uVar7,
                             local_124[0],&DAT_001dbd14,&DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,uVar8,iVar2,&DAT_001dbd44,uVar7,local_19c,&DAT_001dbcd4,
                             &DAT_001fa5e8);
                  ((int (*)())FUN_00091980)(param_1,uVar7,local_19c);
                  ((int (*)())FUN_000911a0)(param_1,local_68);
                  ((int (*)())FUN_000911a0)(param_1,auStack_1c8);
                  ((int (*)())FUN_000911a0)(param_1,local_84);
                  ((int (*)())FUN_000911a0)(param_1,local_7c);
                  if (param_1[0x1a8] == -1) {
                    ((int (*)())FUN_000911a0)(param_1,auStack_178);
                    return 2;
                  }
                }
                if (!bVar1) {
                  puVar11 = local_88[0] + -0x7d40;
                  puVar10 = local_80 + 0x6b94;
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,
                             uVar7,local_174,puVar11,puVar10);
                  (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                            (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),
                             param_1[uStack0000002c + 0x21],&DAT_001dbd24,uVar7,local_174,puVar11,
                             puVar10);
                  ((int (*)())FUN_000911a0)(param_1,auStack_178);
                }
                return 0;
              }
              local_88[0] = &DAT_001e3a54;
              local_80 = &DAT_001f3a54;
              local_74 = &DAT_001e3a54;
LAB_00094348:
              uVar15 = 0;
              puVar3 = (undefined4 *)(local_74 + -0x7d50);
              piVar6 = param_1 + 0x29;
              do {
                iVar2 = *piVar6;
                uVar15 = uVar15 + 1;
                puVar11 = local_88[0] + -0x7d40;
                puVar10 = local_80 + 0x6b94;
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_19c,puVar3,uVar13,iVar2,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_1c4,puVar3,uVar13,iVar2 + 1,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_14c,puVar3,uVar13,iVar2 + 2,puVar11,puVar10);
                (**(code **)(((unsigned char *)0x000012e4) + iVar4))
                          (param_1,uVar8,local_124[0],puVar3,uVar13,iVar2 + 3,puVar11,puVar10);
                if (param_3 <= uVar15) goto LAB_000944c4;
                if (uVar15 == 1) {
                  puVar3 = &DAT_001dbd64;
                }
                else {
                  if (uVar15 == 0) goto LAB_00094348;
                  if (uVar15 == 2) {
                    puVar3 = &DAT_001dbd54;
                  }
                  else {
                    puVar3 = (undefined4 *)0x0;
                    if (uVar15 == 3) {
                      puVar3 = &DAT_001dbd44;
                    }
                  }
                }
                piVar6 = piVar6 + 1;
              } while( true );
            }
          }
        }
        return 7;
      }
    }
    else if ((param_1[0x158] != -1) || (((int (*)())FUN_00091eb0)(param_1,param_3,param_4), param_1[0x158] != -1)
            ) {
      if ((param_3 < 4) && (param_4 != 0)) {
        param_3 = param_3 + 1;
      }
      local_7c = auStack_128;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_7c);
      if (iVar2 != 0) {
        return 7;
      }
      local_78 = auStack_100;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_78);
      if (iVar2 != 0) {
        return 7;
      }
      local_70 = auStack_d8;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_70);
      if (iVar2 != 0) {
        return 7;
      }
      local_6c = auStack_b0;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,local_6c);
      if (iVar2 != 0) {
        return 7;
      }
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_1c8);
      if (iVar2 != 0) {
        return 7;
      }
      puVar5 = (undefined4 *)param_1[0xfb];
      puVar3 = (undefined4 *)param_1[0xfc];
      uVar7 = *puVar5;
      uVar13 = *puVar3;
      uVar8 = puVar5[2];
      if (param_3 == 0) {
        local_54 = &DAT_001e3a54;
        local_88[0] = &DAT_001e3a54;
        local_80 = &DAT_001f3a54;
        local_64 = &DAT_001e3a54;
        local_58 = &DAT_001e3a54;
        local_5c = &DAT_001e3a54;
        local_60 = &DAT_001f3a54;
      }
      else {
        local_54 = &DAT_001e3a54;
        local_88[0] = &DAT_001e3a54;
        local_80 = &DAT_001f3a54;
        local_64 = &DAT_001e3a54;
        local_5c = &DAT_001e3a54;
        local_58 = &DAT_001e3a54;
        uVar15 = 0;
        local_60 = &DAT_001f3a54;
        puVar3 = local_124;
        piVar6 = param_1;
        do {
          iVar2 = piVar6[0x29];
          uVar14 = *puVar3;
          uVar15 = uVar15 + 1;
          piVar6 = piVar6 + 1;
          puVar3 = puVar3 + 10;
          (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8
                    );
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8
                    );
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8
                    );
          (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                    (param_1,uVar13,uVar14,&DAT_001dbd24,uVar8,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
        } while (param_3 != uVar15);
        puVar3 = (undefined4 *)param_1[0xfc];
        puVar5 = (undefined4 *)param_1[0xfb];
      }
      iVar2 = local_1c4;
      if (bVar1) {
        uVar8 = puVar3[2];
        iVar9 = param_1[0x1a];
      }
      else {
        uVar8 = *puVar3;
        iVar9 = local_1c4;
      }
      uVar13 = *puVar5;
      puVar12 = local_80 + 0x6b94;
      puVar11 = local_88[0] + -0x7d40;
      puVar10 = local_54 + -0x7d30;
      (**(code **)(((unsigned char *)0x000012ec) + iVar4))
                (param_1,uVar13,local_1c4,puVar10,uVar7,local_ac,puVar11,puVar12);
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,local_d4,puVar11,puVar12);
      (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                (param_1,uVar13,iVar2,puVar10,uVar7,local_fc,puVar11,puVar12);
      if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar8,iVar9,puVar10,uVar7,local_124[0],puVar11,puVar12);
      }
      else {
        (**(code **)(((unsigned char *)0x000012f4) + iVar4))
                  (param_1,uVar13,iVar2,puVar10,uVar7,local_124[0],puVar11,puVar12);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                    (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar10,uVar7,
                     local_1c4,puVar11,puVar12);
        }
        ((int (*)())FUN_00091980)(param_1,uVar7,local_1c4);
        if (param_1[0x1a8] == -1) {
          ((int (*)())FUN_000911a0)(param_1,local_7c);
          ((int (*)())FUN_000911a0)(param_1,local_78);
          ((int (*)())FUN_000911a0)(param_1,local_70);
          ((int (*)())FUN_000911a0)(param_1,local_6c);
          ((int (*)())FUN_000911a0)(param_1,auStack_1c8);
          return 2;
        }
      }
      if (!bVar1) {
        puVar12 = local_54 + -0x7d30;
        puVar11 = local_88[0] + -0x7d40;
        puVar10 = local_80 + 0x6b94;
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],puVar12,uVar7,local_1c4,
                   puVar11,puVar10);
        (**(code **)(((unsigned char *)0x000012e8) + iVar4))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[uStack0000002c + 0x21],
                   puVar12,uVar7,local_1c4,puVar11,puVar10);
      }
      ((int (*)())FUN_000911a0)(param_1,local_7c);
      ((int (*)())FUN_000911a0)(param_1,local_78);
      ((int (*)())FUN_000911a0)(param_1,local_70);
      ((int (*)())FUN_000911a0)(param_1,local_6c);
      ((int (*)())FUN_000911a0)(param_1,auStack_1c8);
      return 0;
    }
  }
  return 2;
}

/* FUN_00094840 @ 0x94840 (3400 bytes) */
int FUN_00094840(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  code *pcVar7;
  undefined4 *puVar8;
  code *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined **ppuVar12;
  uint uVar13;
  undefined1 auStack_1b8 [4];
  undefined4 local_1b4;
  undefined1 auStack_190 [4];
  undefined4 local_18c;
  undefined1 auStack_168 [4];
  undefined4 local_164;
  undefined1 auStack_140 [4];
  undefined4 local_13c [9];
  undefined1 auStack_118 [4];
  undefined4 local_114;
  undefined1 auStack_f0 [4];
  undefined4 local_ec;
  undefined1 auStack_c8 [4];
  undefined4 local_c4;
  undefined1 *local_98;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined **local_8c;
  code *local_88[0];
  undefined1 *local_84;
  code *local_80;
  undefined **local_7c;
  code *local_78;
  code *local_74;
  code *local_70;
  code *local_6c;
  code *local_68;
  code *local_64;
  undefined1 *local_60;
  code *local_5c;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (4 < param_3) {
    return 4;
  }
  if (param_3 != 0) {
    iVar2 = 0;
    piVar4 = param_1;
    uVar13 = param_3;
    do {
      iVar1 = *(int *)(param_2 + iVar2 * 4);
      if (iVar1 == 0) {
        iVar1 = *param_1;
      }
      else {
        if (iVar1 != 1) {
          return 3;
        }
        iVar1 = param_1[0x18];
      }
      if (iVar1 == -1) {
        return 2;
      }
      if (piVar4[0x2d] == -1) {
        return 2;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  if ((param_3 < 4) && (param_4 != 0)) {
    iVar2 = *(int *)(param_2 + param_3 * 4);
    if (iVar2 == 0) {
      iVar2 = *param_1;
    }
    else {
      if (iVar2 != 1) {
        return 3;
      }
      iVar2 = param_1[0x18];
    }
    if (iVar2 == -1) {
      return 2;
    }
    if (param_1[param_3 + 0x2d] == -1) {
      return 2;
    }
  }
  iVar2 = param_1[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + iVar2) & 4) == 0) {
    if (param_1[0xfe] != -1) {
      return 0;
    }
    iVar1 = param_1[0x158];
    if (iVar1 == -1) {
      ((int (*)())FUN_00091eb0)(param_1,param_3,param_4);
      iVar1 = param_1[0x158];
      if (iVar1 == -1) {
        return 2;
      }
    }
    if ((param_3 < 4) && (param_4 != 0)) {
      param_3 = param_3 + 1;
    }
    iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0xfd);
    if ((iVar3 == 0) && (iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_1b8), iVar3 == 0)) {
      iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_190);
      if (iVar3 == 0) {
        local_60 = auStack_168;
        iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,local_60);
        if (iVar3 == 0) {
          local_98 = auStack_140;
          iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,local_98);
          if (iVar3 == 0) {
            puVar8 = (undefined4 *)param_1[0xfb];
            uVar6 = puVar8[2];
            uVar5 = *(undefined4 *)param_1[0xfc];
            if ((param_3 < 3) && (param_5 != 0)) {
              if (param_3 != 0) {
                local_88[0] = FUN_001d4850;
                local_8c = &PTR_LAB_001f4850;
                local_6c = FUN_001d4850;
                local_68 = FUN_001d4850;
                local_64 = FUN_001d4850;
                local_70 = FUN_001d4850;
                do {
                  uVar13 = 0;
                  uVar10 = local_1b4;
                  piVar4 = param_1 + 0x2d;
                  while( true ) {
                    iVar3 = *piVar4;
                    uVar13 = uVar13 + 1;
                    pcVar7 = local_88[0] + 0x74c4;
                    ppuVar12 = local_8c + 0x1766;
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_6c + 0x74b4,uVar6,iVar3,pcVar7,ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_68 + 0x7514,uVar6,iVar3 + 1,pcVar7,
                               ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_64 + 0x7504,uVar6,iVar3 + 2,pcVar7,
                               ppuVar12);
                    (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                              (param_1,uVar5,uVar10,local_70 + 0x74f4,uVar6,iVar3 + 3,pcVar7,
                               ppuVar12);
                    if (param_3 <= uVar13) {
                      puVar8 = (undefined4 *)param_1[0xfb];
                      goto LAB_0009510c;
                    }
                    if (uVar13 == 0) break;
                    uVar10 = 0;
                    if (uVar13 == 1) {
                      uVar10 = local_18c;
                    }
                    piVar4 = piVar4 + 1;
                  }
                } while( true );
              }
              local_88[0] = FUN_001d4850;
              local_8c = &PTR_LAB_001f4850;
LAB_0009510c:
              uVar6 = *puVar8;
              iVar3 = param_1[0xfe];
              ppuVar12 = local_8c + 0x1766;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001fa5f8,ppuVar12);
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar5,iVar3,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbce4,ppuVar12);
            }
            else {
              if (param_3 != 0) {
                local_88[0] = FUN_001d4850;
                local_8c = &PTR_LAB_001f4850;
                local_6c = FUN_001d4850;
                local_68 = FUN_001d4850;
                local_64 = FUN_001d4850;
                local_70 = FUN_001d4850;
LAB_00095234:
                uVar13 = 0;
                pcVar7 = local_6c + 0x74b4;
                piVar4 = param_1 + 0x2d;
                do {
                  iVar1 = *piVar4;
                  uVar13 = uVar13 + 1;
                  pcVar9 = local_88[0] + 0x74c4;
                  ppuVar12 = local_8c + 0x1766;
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_1b4,pcVar7,uVar6,iVar1,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_18c,pcVar7,uVar6,iVar1 + 1,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_164,pcVar7,uVar6,iVar1 + 2,pcVar9,ppuVar12);
                  (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                            (param_1,uVar5,local_13c[0],pcVar7,uVar6,iVar1 + 3,pcVar9,ppuVar12);
                  if (param_3 <= uVar13) {
                    puVar8 = (undefined4 *)param_1[0xfb];
                    goto LAB_000953b4;
                  }
                  if (uVar13 == 1) {
                    pcVar7 = local_68 + 0x7514;
                  }
                  else {
                    if (uVar13 == 0) goto LAB_00095234;
                    if (uVar13 == 2) {
                      pcVar7 = local_64 + 0x7504;
                    }
                    else {
                      pcVar7 = (code *)0x0;
                      if (uVar13 == 3) {
                        pcVar7 = local_70 + 0x74f4;
                      }
                    }
                  }
                  piVar4 = piVar4 + 1;
                } while( true );
              }
              local_88[0] = FUN_001d4850;
              local_8c = &PTR_LAB_001f4850;
              local_6c = FUN_001d4850;
              local_68 = FUN_001d4850;
              local_64 = FUN_001d4850;
              local_70 = FUN_001d4850;
LAB_000953b4:
              uVar6 = *puVar8;
              iVar1 = param_1[0xfe];
              pcVar7 = local_88[0] + 0x74c4;
              ppuVar12 = local_8c + 0x1766;
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_6c + 0x74b4,uVar6,local_1b4,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_68 + 0x7514,uVar6,local_18c,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_64 + 0x7504,uVar6,local_164,pcVar7,ppuVar12);
              (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                        (param_1,uVar5,iVar1,local_70 + 0x74f4,uVar6,local_13c[0],pcVar7,ppuVar12);
            }
            ((int (*)())FUN_000911a0)(param_1,auStack_1b8);
            ((int (*)())FUN_000911a0)(param_1,auStack_190);
            ((int (*)())FUN_000911a0)(param_1,local_60);
            ((int (*)())FUN_000911a0)(param_1,local_98);
            return 0;
          }
        }
      }
    }
  }
  else {
    if (param_1[0xfe] != -1) {
      return 0;
    }
    if ((param_1[0x158] == -1) && (((int (*)())FUN_00091eb0)(param_1,param_3,param_4), param_1[0x158] == -1)) {
      return 2;
    }
    if ((param_3 < 4) && (param_4 != 0)) {
      param_3 = param_3 + 1;
    }
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0xfd);
    if (iVar1 == 0) {
      local_98 = auStack_140;
      iVar1 = ((int (*)())FUN_00090ca0)(param_1,0,local_98);
      if (iVar1 == 0) {
        local_94 = auStack_118;
        iVar1 = ((int (*)())FUN_00090ca0)(param_1,0,local_94);
        if (iVar1 == 0) {
          local_90 = auStack_f0;
          iVar1 = ((int (*)())FUN_00090ca0)(param_1,0,local_90);
          if (iVar1 == 0) {
            local_84 = auStack_c8;
            iVar1 = ((int (*)())FUN_00090ca0)(param_1,0,local_84);
            if (iVar1 == 0) {
              puVar8 = (undefined4 *)param_1[0xfb];
              uVar5 = *puVar8;
              uVar10 = *(undefined4 *)param_1[0xfc];
              uVar6 = puVar8[2];
              if (param_3 == 0) {
                local_5c = FUN_001d4850;
                local_88[0] = FUN_001d4850;
                local_8c = &PTR_LAB_001f4850;
                local_80 = FUN_001d4850;
                local_74 = FUN_001d4850;
                local_78 = FUN_001d4850;
                local_7c = &PTR_LAB_001f4850;
              }
              else {
                local_5c = FUN_001d4850;
                local_88[0] = FUN_001d4850;
                local_8c = &PTR_LAB_001f4850;
                local_80 = FUN_001d4850;
                local_78 = FUN_001d4850;
                local_74 = FUN_001d4850;
                uVar13 = 0;
                local_7c = &PTR_LAB_001f4850;
                puVar8 = local_13c;
                piVar4 = param_1;
                do {
                  iVar1 = piVar4[0x2d];
                  uVar11 = *puVar8;
                  uVar13 = uVar13 + 1;
                  piVar4 = piVar4 + 1;
                  puVar8 = puVar8 + 10;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 3,&DAT_001dbd14,
                             &DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 2,&DAT_001dbd14,
                             &DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1 + 1,&DAT_001dbd14,
                             &DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                            (param_1,uVar10,uVar11,&DAT_001dbd24,uVar6,iVar1,&DAT_001dbd14,
                             &DAT_001fa5e8);
                } while (param_3 != uVar13);
                puVar8 = (undefined4 *)param_1[0xfb];
              }
              iVar1 = param_1[0xfe];
              uVar6 = *puVar8;
              ppuVar12 = local_8c + 0x1766;
              pcVar7 = local_5c + 0x74d4;
              pcVar9 = local_88[0] + 0x74c4;
              (**(code **)(((unsigned char *)0x000012ec) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_c4,pcVar9,ppuVar12);
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_ec,pcVar9,ppuVar12);
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_114,pcVar9,ppuVar12);
              (**(code **)(((unsigned char *)0x000012f4) + iVar2))
                        (param_1,uVar6,iVar1,pcVar7,uVar5,local_13c[0],pcVar9,ppuVar12);
              ((int (*)())FUN_000911a0)(param_1,local_98);
              ((int (*)())FUN_000911a0)(param_1,local_94);
              ((int (*)())FUN_000911a0)(param_1,local_90);
              ((int (*)())FUN_000911a0)(param_1,local_84);
              return 0;
            }
          }
        }
      }
    }
  }
  return 7;
}

/* FUN_000955e0 @ 0x955e0 (40 bytes) */
int FUN_000955e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1 != 0) && (uVar1 = 2, *(int *)(param_1 + 0x5c) != -1)) {
    uVar1 = ((int (*)())FUN_00091eb0)();
    return uVar1;
  }
  return uVar1;
}

/* FUN_00095610 @ 0x95610 (1840 bytes) */
int FUN_00095610(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  
  if (param_1 == 0) {
    return 1;
  }
  if ((*(int *)(param_1 + 0x68) == -1) || (*(int *)(param_1 + 0xd4) == -1)) {
LAB_00095d30:
    uVar5 = 2;
  }
  else {
    bVar1 = param_2 == 0;
    if (!bVar1) {
      if (7 < param_3) {
        return 3;
      }
      if (*(int *)(param_3 * 4 + param_1 + 0x84) == -1) goto LAB_00095d30;
    }
    iVar7 = *(int *)(param_1 + 0x3d4);
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar7) & 4) == 0) {
      if ((*(int *)(param_1 + 0x3f8) == -1) &&
         (((int (*)())FUN_000916d0)(param_1), *(int *)(param_1 + 0x3f8) == -1)) goto LAB_00095d30;
      if (bVar1) {
        uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
        uVar5 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_a8);
        if (iVar2 != 0) {
          return 7;
        }
        uVar6 = **(undefined4 **)(param_1 + 0x3f0);
        uVar5 = local_a4;
      }
      iVar2 = *(int *)(param_1 + 0xd4);
      uVar4 = **(undefined4 **)(param_1 + 0x3ec);
      uVar8 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd04,uVar8,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd64,uVar8,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                (param_1,uVar6,uVar5,&DAT_001dbd54,uVar8,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
        (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                  (param_1,uVar6,uVar5,&DAT_001dbd44,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        uVar9 = **(undefined4 **)(param_1 + 0x3f0);
        iVar3 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_80);
        if (iVar3 != 0) {
          return 7;
        }
        (**(code **)(((unsigned char *)0x000012e4) + iVar7))
                  (param_1,uVar9,local_7c,&DAT_001dbd44,uVar8,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8)
        ;
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,uVar6,uVar5,&DAT_001dbd44,uVar4,local_7c,&DAT_001dbcd4,&DAT_001fa5e8);
        ((int (*)())FUN_00091980)(param_1,uVar4,local_7c);
        ((int (*)())FUN_000911a0)(param_1,auStack_80);
        if (*(int *)(param_1 + 0x6a0) == -1) goto LAB_00095d30;
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,local_a4,
                   &DAT_001dbd14,&DAT_001fa5e8);
        goto LAB_00095d10;
      }
    }
    else {
      uVar5 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(int *)(param_1 + 0x3f8) == -1) &&
         (((int (*)())FUN_000914e0)(param_1), *(int *)(param_1 + 0x3f8) == -1)) goto LAB_00095d30;
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_a8);
      uVar6 = local_a4;
      if (iVar2 != 0) {
        return 7;
      }
      if (bVar1) {
        uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8);
        uVar8 = *(undefined4 *)(param_1 + 0x68);
      }
      else {
        uVar4 = **(undefined4 **)(param_1 + 0x3f0);
        uVar8 = local_a4;
      }
      iVar2 = *(int *)(param_1 + 0xd4);
      uVar9 = **(undefined4 **)(param_1 + 0x3ec);
      uVar10 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      (**(code **)(((unsigned char *)0x000012ec) + iVar7))
                (param_1,uVar9,local_a4,&DAT_001dbd24,uVar10,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                (param_1,uVar9,uVar6,&DAT_001dbd24,uVar10,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                (param_1,uVar9,uVar6,&DAT_001dbd24,uVar10,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(param_1 + 0x744) == '\0') || (*(int *)(param_1 + 0x6a0) != -1)) {
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,uVar4,uVar8,&DAT_001dbd24,uVar10,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        (**(code **)(((unsigned char *)0x000012f4) + iVar7))
                  (param_1,**(undefined4 **)(param_1 + 0x3ec),local_a4,&DAT_001dbd24,uVar10,iVar2,
                   &DAT_001dbd14,&DAT_001fa5e8);
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                     *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                     &DAT_001fa5e8);
        }
        ((int (*)())FUN_00091980)(param_1,uVar5,local_a4);
        if (*(int *)(param_1 + 0x6a0) == -1) {
          ((int (*)())FUN_000911a0)(param_1,auStack_a8);
          return 2;
        }
      }
      if (!bVar1) {
        uVar5 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 8),
                   *(undefined4 *)(param_1 + 0x68),&DAT_001dbd24,uVar5,local_a4,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + iVar7))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
                   *(undefined4 *)(param_3 * 4 + param_1 + 0x84),&DAT_001dbd24,uVar5,local_a4,
                   &DAT_001dbd14,&DAT_001fa5e8);
      }
LAB_00095d10:
      ((int (*)())FUN_000911a0)(param_1,auStack_a8);
    }
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_00095dd0 @ 0x95dd0 (1792 bytes) */
int FUN_00095dd0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 auStack_a8 [4];
  int local_a4;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (((param_1[0x1a] == -1) || (iVar8 = param_1[0x29], iVar8 == -1)) || (*param_1 == -1)) {
    return 2;
  }
  bVar1 = param_2 == 0;
  if (!bVar1) {
    if (7 < param_3) {
      return 3;
    }
    if (param_1[param_3 + 0x21] == -1) {
      return 2;
    }
  }
  iVar5 = param_1[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + iVar5) & 4) == 0) {
    if (bVar1) {
      uVar4 = *(undefined4 *)(param_1[0xfc] + 8);
      iVar2 = param_1[0x1a];
    }
    else {
      iVar8 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_a8);
      if (iVar8 != 0) {
        return 7;
      }
      iVar8 = param_1[0x29];
      uVar4 = *(undefined4 *)param_1[0xfc];
      iVar2 = local_a4;
    }
    uVar3 = *(undefined4 *)(param_1[0xfb] + 8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd04,uVar3,iVar8,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd64,uVar3,iVar8 + 1,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar5))
              (param_1,uVar4,iVar2,&DAT_001dbd54,uVar3,iVar8 + 2,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
      (**(code **)(((unsigned char *)0x000012e4) + iVar5))
                (param_1,uVar4,iVar2,&DAT_001dbd44,uVar3,iVar8 + 3,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      uVar9 = *(undefined4 *)param_1[0xfc];
      uVar7 = *(undefined4 *)param_1[0xfb];
      iVar6 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_80);
      if (iVar6 != 0) {
        return 7;
      }
      (**(code **)(((unsigned char *)0x000012e4) + iVar5))
                (param_1,uVar9,local_7c,&DAT_001dbd44,uVar3,iVar8 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,uVar4,iVar2,&DAT_001dbd44,uVar7,local_7c,&DAT_001dbcd4,&DAT_001fa5e8);
      ((int (*)())FUN_00091980)(param_1,uVar7,local_7c);
      ((int (*)())FUN_000911a0)(param_1,auStack_80);
      if (param_1[0x1a8] == -1) {
        return 2;
      }
    }
    if (bVar1) {
      return 0;
    }
    uVar4 = *(undefined4 *)param_1[0xfb];
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,local_a4
               ,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e8) + iVar5))
              (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24,
               uVar4,local_a4,&DAT_001dbd14,&DAT_001fa5e8);
  }
  else {
    uVar4 = *(undefined4 *)param_1[0xfb];
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_a8);
    iVar8 = local_a4;
    if (iVar2 != 0) {
      return 7;
    }
    if (bVar1) {
      uVar3 = *(undefined4 *)(param_1[0xfc] + 8);
      iVar2 = param_1[0x1a];
    }
    else {
      uVar3 = *(undefined4 *)param_1[0xfc];
      iVar2 = local_a4;
    }
    iVar6 = param_1[0x29];
    uVar9 = *(undefined4 *)param_1[0xfb];
    uVar7 = ((undefined4 *)param_1[0xfb])[2];
    (**(code **)(((unsigned char *)0x000012ec) + iVar5))
              (param_1,uVar9,local_a4,&DAT_001dbd24,uVar7,iVar6 + 3,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012f4) + iVar5))
              (param_1,uVar9,iVar8,&DAT_001dbd24,uVar7,iVar6 + 2,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012f4) + iVar5))
              (param_1,uVar9,iVar8,&DAT_001dbd24,uVar7,iVar6 + 1,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) {
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,uVar3,iVar2,&DAT_001dbd24,uVar7,iVar6,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      (**(code **)(((unsigned char *)0x000012f4) + iVar5))
                (param_1,*(undefined4 *)param_1[0xfb],local_a4,&DAT_001dbd24,uVar7,iVar6,
                 &DAT_001dbd14,&DAT_001fa5e8);
      if (bVar1) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                   local_a4,&DAT_001dbd14,&DAT_001fa5e8);
      }
      ((int (*)())FUN_00091980)(param_1,uVar4,local_a4);
      if (param_1[0x1a8] == -1) {
        ((int (*)())FUN_000911a0)(param_1,auStack_a8);
        return 2;
      }
    }
    if (!bVar1) {
      uVar4 = *(undefined4 *)param_1[0xfb];
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar4,
                 local_a4,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + iVar5))
                (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],&DAT_001dbd24
                 ,uVar4,local_a4,&DAT_001dbd14,&DAT_001fa5e8);
    }
  }
  ((int (*)())FUN_000911a0)(param_1,auStack_a8);
  return 0;
}

/* FUN_00096500 @ 0x96500 (52 bytes) */
int FUN_00096500(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0xc4) != -1) && (*(int *)(param_1 + 4) != -1)) {
      uVar1 = ((int (*)())FUN_00091a30)();
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* FUN_00096540 @ 0x96540 (172 bytes) */
int FUN_00096540(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())FUN_000928a0)();
  return uVar1;
}

/* FUN_00096600 @ 0x96600 (1872 bytes) */
int FUN_00096600(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  uint param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined *puVar18;
  undefined4 uStack00000020;
  undefined1 auStack_b8 [4];
  undefined4 local_b4;
  undefined1 auStack_90 [4];
  undefined4 local_8c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  
  bVar2 = param_5 == 0;
  uStack00000020 = param_3;
  if ((bVar2) && (param_7 == 0)) {
    uVar6 = ((int (*)())FUN_00093000)();
    return uVar6;
  }
  if (param_1 == 0) {
    return 1;
  }
  if (((7 < param_2) || (7 < param_4)) || (7 < param_6)) {
    return 3;
  }
  iVar3 = param_2 * 4;
  if (((*(int *)(iVar3 + param_1 + 0x84) == -1) || (*(int *)(iVar3 + param_1 + 0x2c) == -1)) ||
     ((bVar1 = *(char *)(param_1 + 0x744) != '\0', bVar1 && (*(int *)(param_1 + 0xa4) == -1)))) {
    return 2;
  }
  iVar11 = *(int *)(param_1 + 0x3d4);
  if ((bVar1) || ((param_7 != 0 && (!bVar2)))) {
    iVar7 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_b8);
    if (iVar7 != 0) {
      return 7;
    }
    cVar5 = *(char *)(param_1 + 0x744);
    local_5c = 1;
  }
  else {
    local_5c = 0;
    cVar5 = '\0';
  }
  bVar1 = param_7 == 0;
  if (cVar5 == '\0') {
    if (bVar1) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = 0;
      local_b4 = 0;
    }
    else if (bVar2) {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      local_b4 = *(undefined4 *)(iVar3 + param_1 + 0x84);
      uVar12 = puVar8[5];
    }
    else {
      puVar8 = *(undefined4 **)(param_1 + 0x3f0);
      uVar12 = *puVar8;
    }
    uVar15 = puVar8[5];
    uVar6 = *(undefined4 *)(iVar3 + param_1 + 0x84);
    if (bVar1) {
      local_60 = 0;
      local_68 = 0;
      local_64 = 0;
      goto LAB_00096b24;
    }
    local_60 = 0;
    local_68 = 0;
    local_64 = 0;
    uVar17 = local_b4;
  }
  else {
    if (bVar1) {
      local_64 = local_b4;
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      local_60 = 0;
      uVar6 = local_b4;
      local_68 = uVar15;
      goto LAB_00096b24;
    }
    uVar12 = **(undefined4 **)(param_1 + 0x3f0);
    uVar17 = local_b4;
    if (bVar2) {
      local_64 = local_b4;
      uVar15 = 0;
      local_60 = 0;
      uVar6 = 0;
      local_68 = uVar12;
    }
    else {
      if (*(int *)(param_1 + 0x6a0) == -1) {
        if (local_5c == 0) {
          return 2;
        }
        ((int (*)())FUN_000911a0)(param_1,auStack_b8);
        return 2;
      }
      iVar7 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_90);
      if (iVar7 != 0) {
        if (local_5c == 0) {
          return 7;
        }
        ((int (*)())FUN_000911a0)(param_1,auStack_b8);
        return 7;
      }
      local_64 = local_8c;
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      local_60 = 1;
      uVar6 = local_8c;
      local_68 = uVar15;
    }
  }
  if (((((param_7 & 7) == 0) || ((param_7 & 0x38) == 0)) || ((param_7 & 0x1c0) == 0)) ||
     ((param_7 & 0xe00) == 0)) {
    (**(code **)(((unsigned char *)0x000012e8) + iVar11))
              (param_1,uVar12,uVar17,&DAT_001dbd24,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
               *(undefined4 *)(iVar3 + param_1 + 0x2c),&DAT_001dbd14,&DAT_001fa5e8);
  }
  uVar16 = 0;
  puVar18 = &DAT_001dbdfc;
  puVar8 = (undefined4 *)(param_2 * 0x10 + param_1 + 0x348);
  do {
    uVar4 = param_7 >> (uVar16 & 0x3f) & 7;
    if (uVar4 == 0) goto switchD_0009696c_default;
    puVar9 = *(undefined4 **)(param_1 + 0x3ec);
    iVar7 = *(int *)(param_1 + 0x3d4);
    uVar13 = *puVar8;
    uVar14 = puVar9[2];
    switch(uVar4) {
    case 1:
      if (*(int *)(param_1 + 0x3f8) == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar7) & 4) == 0) {
          ((int (*)())FUN_000916d0)(param_1);
        }
        else {
          ((int (*)())FUN_000914e0)(param_1);
        }
      }
      goto LAB_000969f0;
    case 2:
LAB_000969f0:
      (**(code **)(((unsigned char *)0x000012e4) + iVar7))(param_1,uVar12,uVar17,puVar18,uVar14,uVar13);
      goto switchD_0009696c_default;
    case 3:
      iVar10 = *(int *)(param_1 + 0x4e8);
      uVar13 = *puVar9;
      if (iVar10 == -1) {
        ((int (*)())FUN_00092570)(param_1);
        iVar10 = *(int *)(param_1 + 0x4e8);
      }
      break;
    case 4:
      uVar13 = *puVar9;
      if (*(char *)(iVar7 + 0x128) == '\0') {
        if (*(char *)(iVar7 + 300) == '\0') {
          iVar10 = *(int *)(param_1 + 0x448);
          if (iVar10 == -1) {
            ((int (*)())FUN_00091a30)(param_1);
            iVar10 = *(int *)(param_1 + 0x448);
          }
        }
        else {
          iVar10 = *(int *)(param_1 + 0x470);
          if (iVar10 == -1) {
            ((int (*)())FUN_00091d70)(param_1);
            iVar10 = *(int *)(param_1 + 0x470);
          }
        }
      }
      else {
        iVar10 = *(int *)(param_1 + 0x498);
        if (iVar10 == -1) {
          ((int (*)())FUN_00091b90)(param_1);
          iVar10 = *(int *)(param_1 + 0x498);
        }
      }
      break;
    case 5:
      iVar10 = *(int *)(param_1 + 0x4c0);
      uVar13 = *puVar9;
      if (iVar10 == -1) {
        ((int (*)())FUN_00092350)(param_1);
        iVar10 = *(int *)(param_1 + 0x4c0);
      }
      break;
    default:
      goto switchD_0009696c_default;
    }
    (**(code **)(((unsigned char *)0x000012e8) + iVar7))
              (param_1,uVar12,uVar17,puVar18,uVar13,iVar10,&DAT_001dbd14,&DAT_001fa5e8);
switchD_0009696c_default:
    bVar1 = uVar16 != 9;
    puVar18 = puVar18 + 0x10;
    puVar8 = puVar8 + 1;
    uVar16 = uVar16 + 3;
  } while (bVar1);
LAB_00096b24:
  if (!bVar2) {
    iVar7 = *(int *)(param_6 * 4 + param_1 + 0xd8);
    uVar17 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd04,uVar17,iVar7,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd64,uVar17,iVar7 + 1,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd54,uVar17,iVar7 + 2,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + iVar11))
              (param_1,uVar15,uVar6,&DAT_001dbd44,uVar17,iVar7 + 3,&DAT_001dbd14,&DAT_001fa5e8);
  }
  if (*(char *)(param_1 + 0x744) != '\0') {
    (**(code **)(((unsigned char *)0x000012ec) + iVar11))
              (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),
               *(undefined4 *)(iVar3 + param_1 + 0x84),&DAT_001dbd24,local_68,local_64,&DAT_001dbd14
              );
  }
  if (local_5c != 0) {
    ((int (*)())FUN_000911a0)(param_1,auStack_b8);
  }
  if (local_60 != 0) {
    ((int (*)())FUN_000911a0)(param_1,auStack_90);
  }
  return 0;
}

/* FUN_00096d80 @ 0x96d80 (1700 bytes) */
int FUN_00096d80(param_1)
  int param_1;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined4 local_98;
  undefined1 auStack_94 [4];
  int local_90;
  undefined1 auStack_8c [4];
  int local_88 [4];
  undefined4 local_78 [4];
  int local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  int local_58;
  
  iVar5 = 1;
  if (param_1 != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    uVar18 = 0;
    iVar15 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
    iVar5 = iVar16;
    iVar20 = param_1;
    do {
      iVar6 = ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar5 + 0x270),0,auStack_8c,auStack_94);
      if (iVar6 != 0) {
        return iVar6;
      }
      iVar6 = ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar5 + 0x278),1,auStack_8c,auStack_94);
      if (iVar6 != 0) {
        return iVar6;
      }
      if ((*(int *)(iVar16 + 0x13c) == 1) && (*(int *)(iVar20 + 0x2f8) == -1)) goto LAB_00097408;
      uVar18 = uVar18 + 1;
      iVar5 = iVar5 + 4;
      iVar20 = iVar20 + 0x24;
    } while (uVar18 <= (byte)"}J3x})+x|B;x}k"[iVar15 + 4]);
    if (*(int *)(param_1 + 0x328) == -1) {
LAB_00097408:
      iVar5 = 2;
    }
    else {
      iVar16 = *(int *)(param_1 + 0x3d4);
      uVar18 = 0;
      iVar6 = 0;
      iVar15 = (*(undefined4 **)(param_1 + 0x3ec))[2];
      uVar13 = **(undefined4 **)(param_1 + 0x3ec);
      local_5c = local_88[0] + 2;
      uVar12 = **(undefined4 **)(param_1 + 0x3f0);
      iVar20 = *(int *)(*(int *)(iVar16 + 4) + 0x10);
      iVar5 = iVar16;
      do {
        puVar11 = (undefined4 *)(iVar5 + 0x278);
        uVar18 = uVar18 + 1;
        iVar5 = iVar5 + 4;
        ((int (*)())FUN_000912f0)(param_1,*puVar11,1,(int)local_88[0] + iVar6,iVar6 + (int)local_5c);
        iVar6 = iVar6 + 4;
      } while (uVar18 <= (byte)"}J3x})+x|B;x}k"[iVar20 + 4]);
      if ((((byte)"}J3x})+x|B;x}k"[iVar20 + 4] == 0) || (local_88[0] != local_88[1])) ||
         (bVar1 = true, local_88[2] != local_88[3])) {
        bVar1 = false;
      }
      bVar1 = !bVar1;
      local_64 = &local_90;
      local_60 = param_1 + 0x5ac;
      local_58 = 0x1d6d90;
      local_68 = 0x1d6d90;
      uVar18 = 0;
      iVar14 = 0;
      iVar10 = 0;
      iVar5 = param_1;
      iVar6 = iVar16;
      iVar19 = param_1;
      do {
        iVar7 = ((int (*)())FUN_00090ca0)(param_1,0,local_60 + iVar10);
        if (iVar7 != 0) {
          return 7;
        }
        iVar7 = *(int *)((int)local_88[0] + iVar14);
        uVar17 = *(undefined4 *)(iVar19 + 0x5b0);
        *(undefined4 *)((int)local_78 + iVar14) = uVar17;
        if (iVar15 == iVar7) {
          iVar7 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x64c + iVar10);
          if (iVar7 != 0) {
            return 7;
          }
          *(undefined4 *)(iVar19 + 0x64c) = uVar13;
          puVar4 = PTR_DAT_001e9778;
          puVar3 = PTR_DAT_001e9774;
          puVar2 = PTR_DAT_001e9770;
          (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                    (param_1,uVar12,*(undefined4 *)(iVar19 + 0x650),PTR_DAT_001e9770,iVar15,
                     *(undefined4 *)(iVar14 + (int)local_5c),PTR_DAT_001e9774,PTR_DAT_001e9778);
          ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar6 + 0x270),0,&local_90,&local_98);
          if (iVar15 == local_90) {
            local_98 = *(undefined4 *)(iVar5 + 0x2f8);
            (**(code **)(((unsigned char *)0x000012e8) + iVar16))
                      (param_1,uVar12,uVar17,puVar2,iVar15,local_98,puVar3,puVar4);
          }
          else {
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,PTR_DAT_001e9770,uVar13,*(undefined4 *)(iVar19 + 0x650)
                       ,PTR_DAT_001e9774,PTR_DAT_001e9778);
          }
          if (*(int *)(param_1 + 0x32c) != -1) {
            uVar8 = *(undefined4 *)(iVar19 + 0x650);
            uVar9 = uVar13;
            iVar7 = local_58;
LAB_00097360:
            (**(code **)(((unsigned char *)0x000012f4) + iVar16))
                      (param_1,uVar12,uVar17,((unsigned char *)0x00004ff4) + iVar7,uVar9,uVar8,PTR_DAT_001e9774,
                       PTR_DAT_001e9778);
          }
        }
        else {
          *(int *)(iVar19 + 0x64c) = iVar7;
          uVar9 = *(undefined4 *)(iVar14 + (int)local_5c);
          puVar11 = (undefined4 *)(iVar14 + (int)local_5c);
          *(undefined4 *)(iVar19 + 0x650) = uVar9;
          if (((bVar1) || (uVar18 == 0)) &&
             ((**(code **)(((unsigned char *)0x000012ec) + iVar16))
                        (param_1,uVar12,uVar17,PTR_DAT_001e9770,iVar7,uVar9,PTR_DAT_001e9774,
                         PTR_DAT_001e9778), bVar1)) {
            ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar6 + 0x270),0,&local_90,&local_98);
            uVar9 = uVar17;
LAB_000972c8:
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,uVar9,PTR_DAT_001e9770,uVar13,uVar9,PTR_DAT_001e9774,
                       PTR_DAT_001e9778);
          }
          else if (uVar18 == 1) {
            ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar16 + 0x274),0,local_64,&local_98);
            uVar9 = local_78[0];
            (**(code **)(((unsigned char *)0x000012f0) + iVar16))
                      (param_1,uVar12,local_78[1],PTR_DAT_001e9770,uVar13,local_78[0],
                       PTR_DAT_001e9774,PTR_DAT_001e9778);
            ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar16 + 0x270),0,local_64,&local_98);
            goto LAB_000972c8;
          }
          if ((*(int *)(param_1 + 0x32c) != -1) && ((bVar1 || (uVar18 == 0)))) {
            uVar9 = *(undefined4 *)((int)local_88[0] + iVar14);
            uVar8 = *puVar11;
            iVar7 = local_68;
            goto LAB_00097360;
          }
        }
        if (*(char *)(iVar16 + 0x12d) != '\0') {
          if (*(short *)("}J3x})+x|B;x}k" + iVar20) == -0x7e06) {
            iVar7 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x5fc + iVar10);
            if (iVar7 != 0) {
              return 7;
            }
          }
          else {
            _memcpy((void *)(iVar19 + 0x5fc),(void *)(iVar19 + 0x5ac),0x28);
          }
        }
        uVar18 = uVar18 + 1;
        iVar10 = iVar10 + 0x28;
        iVar19 = iVar19 + 0x28;
        iVar14 = iVar14 + 4;
        iVar5 = iVar5 + 0x24;
        iVar6 = iVar6 + 4;
      } while (uVar18 <= (byte)"}J3x})+x|B;x}k"[iVar20 + 4]);
      iVar5 = 0;
    }
  }
  return iVar5;
}

/* FUN_00097440 @ 0x97440 (4212 bytes) */
int FUN_00097440(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined *puVar19;
  uint uVar20;
  undefined4 uVar21;
  int iVar22;
  undefined1 *puVar23;
  int iStack00000020;
  int iStack00000024;
  int iStack0000002c;
  int iStack00000030;
  int local_1b8;
  int local_1b4;
  undefined1 auStack_1b0 [4];
  undefined1 auStack_1ac [4];
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 auStack_198 [16];
  undefined1 auStack_188 [4];
  undefined4 local_184;
  undefined1 auStack_180 [16];
  undefined1 auStack_170 [16];
  undefined1 auStack_160 [4];
  undefined4 local_15c;
  undefined1 auStack_158 [16];
  undefined1 auStack_148 [16];
  undefined1 auStack_138 [4];
  undefined4 local_134;
  undefined1 auStack_110 [4];
  undefined4 local_10c;
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [16];
  undefined1 auStack_e8 [4];
  undefined4 local_e4;
  undefined1 auStack_e0 [16];
  undefined1 auStack_d0 [56];
  uint local_98;
  uint local_94;
  int local_90;
  int local_8c;
  int local_88[0];
  int local_84;
  int local_80;
  int local_7c;
  undefined1 *local_78;
  undefined1 *local_74;
  undefined4 *local_70;
  int *local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  
  iVar16 = param_1 + 0xf8 + param_2 * 0x3c;
  iVar10 = *(int *)(param_1 + 0x3d4);
  iVar18 = *(int *)(*(int *)(iVar10 + 4) + 0x10);
  if ((*(int *)(iVar16 + 0x24) == -1) || ((param_5 == 2 && (*(int *)(iVar16 + 4) == -1)))) {
LAB_000984b0:
    iVar10 = 2;
  }
  else {
    if (param_6 == 2) {
      iVar3 = (byte)"}J3x})+x|B;x}k"[iVar18 + 4] + 1;
      iVar8 = iVar16;
      do {
        if ((*(int *)(iVar8 + 0xc) == -1) && (*(int *)(iVar16 + 8) == -1)) goto LAB_000984b0;
        iVar8 = iVar8 + 4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    bVar1 = param_7 == 0;
    iStack00000020 = param_3;
    iStack00000024 = param_4;
    iStack0000002c = param_6;
    iStack00000030 = param_7;
    if (!bVar1) {
      uVar20 = 0;
      do {
        iVar8 = ((int (*)())FUN_000913e0)(param_1,*(undefined4 *)(iVar10 + 0x290),auStack_1b0,auStack_1ac,
                             auStack_198);
        if (iVar8 != 0) {
          return iVar8;
        }
        uVar20 = uVar20 + 1;
        iVar10 = iVar10 + 4;
      } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar18 + 4]);
      if (("}J3x})+x|B;x}k"[iVar18 + 5] == '\0') && (*(int *)(iVar16 + 0x28) == -1))
      goto LAB_000984b0;
    }
    if (iStack00000030 == 2) {
      iVar18 = (byte)"}J3x})+x|B;x}k"[iVar18 + 4] + 1;
      iVar10 = iVar16;
      do {
        if ((*(int *)(iVar10 + 0x18) == -1) && (*(int *)(iVar16 + 0x14) == -1)) goto LAB_000984b0;
        iVar10 = iVar10 + 4;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
    }
    iVar18 = *(int *)(param_1 + 0x3d4);
    iVar10 = *(int *)(*(int *)(iVar18 + 4) + 0x10);
    if (*(char *)(iVar18 + 0x128) == '\0') {
      if (*(char *)(iVar18 + 300) == '\0') {
        if (*(char *)(iVar18 + 0x12a) == '\0') {
          iVar8 = *(int *)(param_1 + 4);
        }
        else {
          if (*(int *)(param_1 + 0x448) != -1) goto LAB_00097650;
          ((int (*)())FUN_00091a30)(param_1);
          iVar8 = *(int *)(param_1 + 0x448);
        }
      }
      else {
        if (*(int *)(param_1 + 0x470) != -1) goto LAB_00097650;
        ((int (*)())FUN_00091d70)(param_1);
        iVar8 = *(int *)(param_1 + 0x470);
      }
LAB_0009763c:
      if (iVar8 == -1) goto LAB_000984b0;
    }
    else if (*(int *)(param_1 + 0x498) == -1) {
      ((int (*)())FUN_00091b90)(param_1);
      iVar8 = *(int *)(param_1 + 0x498);
      goto LAB_0009763c;
    }
LAB_00097650:
    local_64 = auStack_160;
    iVar8 = ((int (*)())FUN_00090ca0)(param_1,2,local_64);
    if (iVar8 == 0) {
      uVar15 = **(undefined4 **)(param_1 + 0x3f0);
      iVar8 = (*(int **)(param_1 + 0x3ec))[2];
      iVar3 = **(int **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + iVar18))
                (param_1,uVar15,local_15c,auStack_158,iVar8,*(undefined4 *)(iVar16 + 0x24),
                 &DAT_001dbd74,&DAT_001fa5e8);
      if ((param_5 != 0) && (param_5 != 3)) {
        uVar20 = 0;
        iVar22 = param_1;
        do {
          uVar5 = *(undefined4 *)(iVar22 + 0x5b0);
          if (param_5 == 1) {
            (**(code **)(((unsigned char *)0x000012f0) + iVar18))
                      (param_1,uVar15,uVar5,&DAT_001dbd84,iVar3,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
          }
          else {
            (**(code **)(((unsigned char *)0x000012f4) + iVar18))
                      (param_1,uVar15,uVar5,&DAT_001dbd84,*(undefined4 *)(iVar22 + 0x64c),
                       *(undefined4 *)(iVar22 + 0x650),&DAT_001dbd14,&DAT_001fa5e8);
          }
          uVar20 = uVar20 + 1;
          iVar22 = iVar22 + 0x28;
        } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar10 + 4]);
      }
      puVar23 = auStack_e8;
      uVar20 = 0;
      local_74 = puVar23;
      do {
        iVar22 = ((int (*)())FUN_00090ca0)(param_1,1,puVar23);
        if (iVar22 != 0) goto LAB_000984a0;
        uVar20 = uVar20 + 1;
        puVar23 = puVar23 + 0x28;
      } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar10 + 4]);
      if (bVar1) {
        local_70 = &local_e4;
        local_60 = auStack_148;
        do {
          uVar20 = 0;
          puVar11 = local_70;
          do {
            iVar22 = uVar20 * 0x28;
            uVar20 = uVar20 + 1;
            (**(code **)(((unsigned char *)0x0000132c) + iVar18))
                      (param_1,uVar15,*puVar11,local_74 + iVar22 + 8,iVar3,local_15c,&DAT_001dbd34);
            if ((byte)"}J3x})+x|B;x}k"[iVar10 + 4] < uVar20) goto LAB_00097bd4;
            puVar11 = puVar11 + 10;
          } while (uVar20 != 0);
        } while( true );
      }
      local_78 = auStack_110;
      iVar22 = ((int (*)())FUN_00090ca0)(param_1,2,local_78);
      if (iVar22 == 0) {
        local_68 = auStack_188;
        iVar22 = ((int (*)())FUN_00090ca0)(param_1,2,local_68);
        if (iVar22 == 0) {
          if ("}J3x})+x|B;x}k"[iVar10 + 5] == '\0') {
            local_70 = &local_e4;
            local_6c = &local_1b4;
            local_60 = auStack_148;
            (**(code **)(((unsigned char *)0x000012e4) + iVar18))
                      (param_1,uVar15,local_10c,auStack_108,iVar8,*(undefined4 *)(iVar16 + 0x28));
LAB_00097a58:
            puVar12 = (undefined4 *)(iVar18 + 0x290);
            puVar19 = &DAT_001fa5e8;
            uVar20 = 0;
            puVar11 = local_70;
LAB_00097a68:
            ((int (*)())FUN_000913e0)(param_1,*puVar12,&local_1b8,local_6c,&local_1a8);
            iVar22 = uVar20 * 0x28;
            uVar20 = uVar20 + 1;
            (**(code **)(((unsigned char *)0x0000132c) + iVar18))
                      (param_1,uVar15,*puVar11,local_74 + iVar22 + 8,iVar3,local_10c,auStack_f8,
                       puVar19);
            if (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar10 + 4]) goto LAB_00097a40;
            ((int (*)())FUN_000911a0)(param_1,local_78);
            ((int (*)())FUN_000911a0)(param_1,local_68);
LAB_00097bd4:
            local_90 = 0x1d7454;
            local_8c = 0x1d7454;
            local_80 = 0x1d7454;
            bVar2 = iStack00000020 == 0;
            local_88[0] = 0x1d7454;
            local_94 = 0x81fa;
            local_98 = 0;
            local_84 = 0x1d7454;
            local_7c = 0x1d7454;
            puVar11 = local_70;
            iVar22 = iVar18;
            iVar13 = param_1;
            iVar14 = iVar16;
            iVar17 = param_1;
            while (bVar1) {
              if (((!bVar2) && (*(char *)(iVar18 + 0x12d) != '\0')) &&
                 (*(ushort *)("}J3x})+x|B;x}k" + iVar10) == local_94)) {
                (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                          (param_1,uVar15,*(undefined4 *)(iVar17 + 0x600),((unsigned char *)0x00004930) + local_90,
                           iVar3,*(undefined4 *)(iVar17 + 0x600),((unsigned char *)0x000048c0) + local_8c,
                           &DAT_001fa5e8);
              }
LAB_000980d0:
              if (iStack0000002c == 0) {
                if (iStack00000024 != 0) {
                  uVar21 = *(undefined4 *)(iVar13 + 0x74);
                  uVar5 = *(undefined4 *)(iVar17 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar22 + 0x280),2,&local_1b8,&local_1b4);
                  local_19c = 3;
                  local_1a0 = 5;
                  local_1a8 = 5;
                  local_1a4 = 5;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                            (param_1,uVar7,uVar21,((unsigned char *)0x000048d0) + local_84,iVar3,uVar5,
                             ((unsigned char *)0x00004970) + local_7c,&DAT_001fa5e8);
                }
              }
              else {
                uVar5 = *(undefined4 *)(iVar17 + 0x5b0);
                if (iStack00000024 == 0) {
                  uVar21 = **(undefined4 **)(param_1 + 0x3f0);
                  puVar19 = ((unsigned char *)0x00004930) + local_90;
                }
                else {
                  uVar5 = *(undefined4 *)(iVar13 + 0x74);
                  uVar21 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  puVar19 = ((unsigned char *)0x000048d0) + local_84;
                }
                if (*(int *)(iVar14 + 0xc) == -1) {
                  ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar22 + 0x280),2,&local_1b8,&local_1b4);
                }
                iVar4 = local_1b8;
                iVar6 = local_1b4;
                if ((iStack0000002c == 1) ||
                   (iVar4 = iVar8, iVar6 = *(int *)(iVar14 + 0xc), *(int *)(iVar14 + 0xc) != -1)) {
                  (**(code **)(((unsigned char *)0x000012f4) + iVar18))
                            (param_1,uVar21,uVar5,puVar19,iVar4,iVar6,((unsigned char *)0x000048c0) + local_8c,
                             &DAT_001fa5e8);
                }
                else {
                  local_5c = auStack_138;
                  iVar4 = ((int (*)())FUN_00090ca0)(param_1,0,local_5c);
                  if (iVar4 != 0) goto LAB_000984a0;
                  if (iVar8 == local_1b8) {
                    (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                              (param_1,uVar15,local_134,puVar19,iVar8,local_1b4,PTR_DAT_001e977c,
                               &DAT_001fa5e8);
                    puVar9 = ((unsigned char *)0x00004970) + local_7c;
                    uVar7 = *(undefined4 *)(iVar16 + 8);
                    iVar4 = iVar8;
                  }
                  else {
                    (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                              (param_1,uVar15,local_134,puVar19,iVar8,*(undefined4 *)(iVar16 + 8),
                               ((unsigned char *)0x00004970) + local_7c,&DAT_001fa5e8);
                    uVar7 = *puVar11;
                    puVar9 = ((unsigned char *)0x00004998) + local_80;
                    iVar4 = iVar3;
                  }
                  (**(code **)(((unsigned char *)0x000012f4) + iVar18))
                            (param_1,uVar21,uVar5,puVar19,iVar4,uVar7,puVar9,&DAT_001fa5e8);
                  ((int (*)())FUN_000911a0)(param_1,local_5c);
                }
              }
              puVar23 = local_74;
              puVar11 = puVar11 + 10;
              iVar13 = iVar13 + 4;
              iVar17 = iVar17 + 0x28;
              iVar22 = iVar22 + 4;
              iVar14 = iVar14 + 4;
              local_98 = local_98 + 1;
              if ((byte)"}J3x})+x|B;x}k"[iVar10 + 4] < local_98) {
                uVar20 = 0;
                ((int (*)())FUN_000911a0)(param_1,local_64);
                do {
                  uVar20 = uVar20 + 1;
                  ((int (*)())FUN_000911a0)(param_1,puVar23);
                  puVar23 = puVar23 + 0x28;
                } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar10 + 4]);
                return 0;
              }
            }
            uVar5 = *(undefined4 *)(iVar17 + 0x600);
            if (*(int *)(iVar14 + 0x18) == -1) {
              ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar22 + 0x288),3,&local_1b8,&local_1b4);
            }
            if (iStack00000030 == 1) {
              iVar4 = local_1b8;
              iVar6 = local_1b4;
              if ((!bVar2) && (*(ushort *)("}J3x})+x|B;x}k" + iVar10) == local_94))
              goto LAB_00097d1c;
LAB_00097d70:
              (**(code **)(((unsigned char *)0x000012f4) + iVar18))
                        (param_1,uVar15,uVar5,((unsigned char *)0x00004930) + local_90,iVar4,iVar6,PTR_DAT_001e977c,
                         &DAT_001fa5e8);
              goto LAB_000980d0;
            }
            iVar6 = *(int *)(iVar14 + 0x18);
            if (iVar6 != -1) {
              iVar4 = iVar8;
              if ((bVar2) || (*(ushort *)("}J3x})+x|B;x}k" + iVar10) != local_94))
              goto LAB_00097d70;
LAB_00097d1c:
              (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                        (param_1,uVar15,uVar5,((unsigned char *)0x00004930) + local_90,iVar4,iVar6,
                         ((unsigned char *)0x000048c0) + local_8c,&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            local_5c = auStack_138;
            iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,local_5c);
            if (iVar4 == 0) {
              if (iVar8 == local_1b8) {
                (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                          (param_1,uVar15,local_134,PTR_DAT_001e9780,iVar8,local_1b4,
                           PTR_DAT_001e977c,PTR_DAT_001e9784);
                if ((!bVar2) && (*(ushort *)("}J3x})+x|B;x}k" + iVar10) == local_94)) {
                  uVar21 = *(undefined4 *)(iVar16 + 0x14);
                  iVar4 = iVar8;
                  puVar19 = PTR_DAT_001e977c;
                  goto LAB_00097fd4;
                }
                uVar21 = *(undefined4 *)(iVar16 + 0x14);
                iVar4 = iVar8;
                puVar19 = PTR_DAT_001e977c;
LAB_00098038:
                (**(code **)(((unsigned char *)0x000012f4) + iVar18))
                          (param_1,uVar15,uVar5,&DAT_001dbd84,iVar4,uVar21,puVar19,&DAT_001fa5e8);
              }
              else {
                (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                          (param_1,uVar15,local_134,PTR_DAT_001e9780,iVar8,
                           *(undefined4 *)(iVar16 + 0x14),PTR_DAT_001e977c,PTR_DAT_001e9784);
                if ((bVar2) || (*(ushort *)("}J3x})+x|B;x}k" + iVar10) != local_94)) {
                  uVar21 = *puVar11;
                  puVar19 = ((unsigned char *)0x000048a0) + local_88[0];
                  iVar4 = iVar3;
                  goto LAB_00098038;
                }
                uVar21 = *puVar11;
                puVar19 = ((unsigned char *)0x000048a0) + local_88[0];
                iVar4 = iVar3;
LAB_00097fd4:
                (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                          (param_1,uVar15,uVar5,PTR_DAT_001e9780,iVar4,uVar21,puVar19,
                           PTR_DAT_001e9784);
              }
              ((int (*)())FUN_000911a0)(param_1,local_5c);
              goto LAB_000980d0;
            }
            goto LAB_000984a0;
          }
          if ((*(int *)(param_1 + 0x420) != -1) ||
             (((int (*)())FUN_00092220)(param_1), *(int *)(param_1 + 0x420) != -1)) {
            local_6c = &local_1b4;
            local_70 = &local_e4;
            (**(code **)(((unsigned char *)0x000012f0) + iVar18))
                      (param_1,uVar15,local_e4,auStack_e0,iVar8,*(undefined4 *)(iVar16 + 0x24),
                       &DAT_001dbd14,&DAT_001fa5e8);
            local_60 = auStack_148;
            (**(code **)(((unsigned char *)0x000012e4) + iVar18))
                      (param_1,uVar15,local_10c,auStack_108,iVar3,local_e4,auStack_d0,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x000012e4) + iVar18))
                      (param_1,uVar15,local_184,auStack_180,iVar3,local_e4,auStack_d0,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x00001318) + iVar18))
                      (param_1,uVar15,local_10c,auStack_108,iVar3,local_10c,auStack_f8,&DAT_001fa5e8
                      );
            (**(code **)(((unsigned char *)0x000012ec) + iVar18))
                      (param_1,uVar15,local_10c,auStack_108,iVar3,local_184,auStack_170,
                       &DAT_001fa5e8);
            goto LAB_00097a58;
          }
          goto LAB_000984b0;
        }
      }
    }
LAB_000984a0:
    iVar10 = 7;
  }
  return iVar10;
LAB_00097a40:
  puVar12 = puVar12 + 1;
  puVar11 = puVar11 + 10;
  puVar19 = &DAT_001dbd94;
  if (uVar20 == 0) goto LAB_00097a58;
  goto LAB_00097a68;
}

/* FUN_00098500 @ 0x98500 (6432 bytes) */
int FUN_00098500(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined *puVar21;
  undefined4 uVar22;
  undefined1 *puVar23;
  undefined4 *puVar24;
  undefined1 *puVar25;
  int iStack00000020;
  int iStack00000024;
  int in_stack_00000038;
  int in_stack_0000003c;
  int local_228;
  undefined1 auStack_224 [4];
  undefined1 auStack_220 [4];
  int local_21c;
  undefined1 auStack_218 [16];
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  int local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined1 auStack_1e8 [4];
  undefined4 local_1e4;
  undefined1 auStack_1e0 [32];
  undefined1 auStack_1c0 [4];
  undefined4 local_1bc;
  undefined1 auStack_1b8 [16];
  undefined1 auStack_1a8 [16];
  undefined1 auStack_198 [4];
  undefined4 local_194;
  undefined1 auStack_190 [16];
  undefined1 auStack_180 [16];
  undefined1 auStack_170 [4];
  undefined4 local_16c;
  undefined1 auStack_168 [16];
  undefined1 auStack_158 [16];
  undefined1 auStack_148 [4];
  undefined4 local_144;
  undefined1 auStack_140 [32];
  undefined1 auStack_120 [4];
  undefined4 local_11c;
  undefined1 auStack_118 [16];
  undefined1 auStack_108 [16];
  undefined1 auStack_f8 [4];
  undefined4 local_f4;
  undefined1 auStack_f0 [16];
  undefined1 auStack_e0 [56];
  uint local_a8;
  int local_a4;
  undefined1 *local_a0;
  uint local_9c;
  code *local_98;
  code *local_94;
  code *local_90;
  code *local_8c;
  code *local_88[0];
  undefined1 *local_84;
  code *local_80;
  undefined1 *local_7c;
  undefined1 *local_78;
  code *local_74;
  undefined1 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  undefined *local_64;
  code *local_60;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar16 = param_1 + 0xf8 + param_2 * 0x3c;
  if (*(int *)(iVar16 + 0x24) == -1) {
    return 2;
  }
  bVar1 = param_5 != 0;
  if (bVar1) {
    if (param_6 == 0) {
      iVar4 = *(int *)(iVar16 + 0x2c);
    }
    else {
      iVar4 = *(int *)(iVar16 + 0x34);
    }
    if (iVar4 == -1) {
      return 2;
    }
  }
  iVar4 = *(int *)(param_1 + 0x3d4);
  iVar18 = *(int *)(*(int *)(iVar4 + 4) + 0x10);
  if (((unsigned char *)0x0000150c)[param_2 * 0x6c + iVar4] != '\0') {
    if (*(int *)(iVar16 + 0x28) == -1) {
      return 2;
    }
    if (*(int *)(iVar16 + 0x30) == -1) {
      return 2;
    }
    if ((*(float *)(param_2 * 0x80 + iVar18 + 0x251c) != FLOAT_001aa0d4) &&
       (*(int *)(iVar16 + 0x38) == -1)) {
      return 2;
    }
  }
  if ((param_8 == 2) && (*(int *)(iVar16 + 4) == -1)) {
    return 2;
  }
  if (in_stack_00000038 == 2) {
    iVar5 = (byte)"}J3x})+x|B;x}k"[iVar18 + 4] + 1;
    iVar9 = iVar16;
    do {
      if ((*(int *)(iVar9 + 0xc) == -1) && (*(int *)(iVar16 + 8) == -1)) {
        return 2;
      }
      iVar9 = iVar9 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  bVar2 = in_stack_0000003c == 0;
  iStack00000020 = param_3;
  iStack00000024 = param_4;
  if (!bVar2) {
    uVar20 = 0;
    do {
      iVar9 = ((int (*)())FUN_000913e0)(param_1,*(undefined4 *)(iVar4 + 0x290),auStack_224,auStack_220,
                           auStack_218);
      if (iVar9 != 0) {
        return iVar9;
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar18 + 4]);
  }
  if (in_stack_0000003c == 2) {
    iVar18 = (byte)"}J3x})+x|B;x}k"[iVar18 + 4] + 1;
    iVar4 = iVar16;
    do {
      if ((*(int *)(iVar4 + 0x18) == -1) && (*(int *)(iVar16 + 0x14) == -1)) {
        return 2;
      }
      iVar4 = iVar4 + 4;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
  }
  local_84 = auStack_1e8;
  iVar9 = *(int *)(param_1 + 0x3d4);
  iVar18 = *(int *)(*(int *)(iVar9 + 4) + 0x10);
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,local_84);
  if (iVar4 != 0) {
    return 7;
  }
  local_7c = auStack_198;
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,local_7c);
  if (iVar4 != 0) {
    return 7;
  }
  local_70 = auStack_148;
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,local_70);
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_120);
  if (iVar4 != 0) {
    return 7;
  }
  iVar4 = *(int *)(param_1 + 0x3f8);
  if (iVar4 == -1) {
    if ((*(uint *)(((unsigned char *)0x000013c0) + iVar9) & 4) == 0) {
      ((int (*)())FUN_000916d0)(param_1);
    }
    else {
      ((int (*)())FUN_000914e0)(param_1);
    }
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar9 + 0x128) == '\0') {
    if (*(char *)(iVar9 + 300) == '\0') {
      if (*(int *)(param_1 + 0x448) != -1) goto LAB_00098818;
      ((int (*)())FUN_00091a30)(param_1);
      iVar5 = *(int *)(param_1 + 0x448);
    }
    else {
      if (*(int *)(param_1 + 0x470) != -1) goto LAB_00098818;
      ((int (*)())FUN_00091d70)(param_1);
      iVar5 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    if (*(int *)(param_1 + 0x498) != -1) goto LAB_00098818;
    ((int (*)())FUN_00091b90)(param_1);
    iVar5 = *(int *)(param_1 + 0x498);
  }
  if (iVar5 == -1) {
    return 2;
  }
LAB_00098818:
  iVar5 = (*(int **)(param_1 + 0x3ec))[2];
  uVar15 = **(undefined4 **)(param_1 + 0x3f0);
  iVar17 = **(int **)(param_1 + 0x3ec);
  if (param_7 == 0) {
    local_64 = &DAT_001f8514;
    local_60 = FUN_001d8514;
    local_80 = FUN_001d8514;
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (param_1,uVar15,local_1e4,auStack_1e0,iVar17,iVar4,&DAT_001dbcd4,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (param_1,uVar15,local_1e4,auStack_1e0,iVar5,*(undefined4 *)(iVar16 + 0x24),
               &DAT_001dbcd4,((unsigned char *)0x00003880) + (int)local_80);
  }
  else {
    local_64 = &DAT_001f8514;
    local_60 = FUN_001d8514;
    local_80 = FUN_001d8514;
    (**(code **)(((unsigned char *)0x000012f4) + iVar9))
              (param_1,uVar15,local_1e4,auStack_1e0,iVar17,iVar4,&DAT_001dbcd4);
  }
  local_6c = auStack_108;
  local_74 = FUN_001d8514;
  puVar21 = ((unsigned char *)0x000020d4) + (int)local_64;
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (param_1,uVar15,local_194,&DAT_001dbd04,iVar17,local_1e4,&DAT_001dbd74,puVar21);
  (**(code **)(((unsigned char *)0x00001318) + iVar9))
            (param_1,uVar15,local_11c,auStack_118,iVar17,local_194,&DAT_001fa5f8,puVar21);
  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
            (param_1,uVar15,local_1e4,auStack_1e0,iVar17,local_11c,local_6c,puVar21);
  if ((bVar1) && (param_6 == 0)) {
    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
              (param_1,uVar15,local_194,&DAT_001dbd64,iVar17,local_11c,local_6c,puVar21);
    local_1f4 = 1;
    local_1f0 = 5;
    local_1ec = 4;
    local_1f8 = param_6;
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (param_1,uVar15,local_11c,auStack_118,iVar5,*(undefined4 *)(iVar16 + 0x2c),
               &DAT_001dbd74,puVar21);
    (**(code **)(((unsigned char *)0x00001314) + iVar9))
              (param_1,uVar15,local_11c,auStack_118,iVar17,local_11c,local_6c,puVar21);
  }
  if (((unsigned char *)0x0000150c)[param_2 * 0x6c + iVar9] == '\0') {
    local_a0 = auStack_120;
    if (bVar1) {
      if (param_6 == 0) {
        local_a4 = 1;
      }
      else {
        local_a4 = 1;
        (**(code **)(((unsigned char *)0x000012e8) + iVar9))
                  (param_1,uVar15,local_11c,auStack_118,iVar5,*(undefined4 *)(iVar16 + 0x34),
                   local_60 + 0x3800,((unsigned char *)0x000020d4) + (int)local_64);
      }
    }
    else {
      local_a4 = 0;
    }
  }
  else {
    iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_1c0);
    if (iVar4 != 0) {
      return 7;
    }
    puVar21 = ((unsigned char *)0x000020d4) + (int)local_64;
    (**(code **)(((unsigned char *)0x000012e4) + iVar9))
              (param_1,uVar15,local_1bc,auStack_1b8,iVar5,*(undefined4 *)(iVar16 + 0x28),
               ((unsigned char *)0x00003860) + (int)local_74,puVar21);
    if (*(float *)(param_2 * 0x80 + iVar18 + 0x251c) == FLOAT_001aa0d4) {
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (param_1,uVar15,local_1bc,auStack_1b8,iVar17,local_1bc,auStack_1a8,puVar21);
    }
    else {
      iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_170);
      if (iVar4 != 0) {
        return 7;
      }
      (**(code **)(((unsigned char *)0x0000130c) + iVar9))
                (param_1,uVar15,local_16c,auStack_168,iVar17,local_1bc,auStack_1a8,puVar21);
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (param_1,uVar15,local_1bc,auStack_1b8,iVar17,local_1bc,auStack_1a8,puVar21);
      (**(code **)(((unsigned char *)0x00001324) + iVar9))
                (param_1,uVar15,local_1bc,auStack_1b8,iVar17,local_1bc,auStack_1a8,puVar21);
      ((int (*)())FUN_000911a0)(param_1,auStack_170);
    }
    if (bVar1) {
      if (param_6 == 0) {
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,uVar15,local_1bc,auStack_1b8,iVar17,local_1bc,auStack_1a8);
      }
      else {
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,uVar15,local_1bc,auStack_1b8,iVar17,local_1bc,auStack_1a8,
                   ((unsigned char *)0x000020d4) + (int)local_64);
      }
    }
    local_a0 = auStack_1c0;
    ((int (*)())FUN_000911a0)(param_1,auStack_120);
    local_a4 = 1;
  }
  puVar21 = ((unsigned char *)0x000020d4) + (int)local_64;
  (**(code **)(((unsigned char *)0x000012e4) + iVar9))
            (param_1,uVar15,local_144,auStack_140,iVar17,local_1e4,((unsigned char *)0x00003860) + (int)local_74,
             puVar21);
  ((int (*)())FUN_000911a0)(param_1,local_7c);
  if ((param_8 != 0) && (param_8 != 3)) {
    uVar20 = 0;
    bVar1 = local_a4 == 0;
    iVar4 = param_1;
    do {
      uVar19 = *(undefined4 *)(iVar4 + 0x5b0);
      uVar22 = *(undefined4 *)(iVar4 + 0x64c);
      if (param_8 == 1) {
        if (bVar1) {
          (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                    (param_1,uVar15,uVar19,&DAT_001dbd84,uVar22,*(undefined4 *)(iVar4 + 0x650),
                     &DAT_001dbd14,puVar21);
        }
        else {
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
LAB_00099084:
          (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                    (param_1,uVar15,uVar19,&DAT_001dbd84,uVar22,uVar7,&DAT_001dbd14,puVar21);
        }
      }
      else {
        if (bVar1) {
          uVar7 = *(undefined4 *)(iVar4 + 0x650);
          goto LAB_00099084;
        }
        iVar12 = ((int (*)())FUN_00090ca0)(param_1,0,local_7c);
        if (iVar12 != 0) {
          return 7;
        }
        (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                  (param_1,uVar15,local_194,&DAT_001dbd24,uVar22,*(undefined4 *)(iVar4 + 0x650),
                   &DAT_001dbd14,puVar21);
        (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                  (param_1,uVar15,uVar19,&DAT_001dbd84,iVar17,local_194,&DAT_001dbd14,puVar21);
        ((int (*)())FUN_000911a0)(param_1,local_7c);
      }
      uVar20 = uVar20 + 1;
      iVar4 = iVar4 + 0x28;
    } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar18 + 4]);
  }
  puVar23 = auStack_f8;
  uVar20 = 0;
  local_68 = puVar23;
  do {
    iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,puVar23);
    if (iVar4 != 0) {
      return 7;
    }
    uVar20 = uVar20 + 1;
    puVar23 = puVar23 + 0x28;
  } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar18 + 4]);
  if (bVar2) {
    do {
      uVar20 = 0;
      puVar11 = &local_f4;
      do {
        iVar4 = uVar20 * 0x28;
        uVar20 = uVar20 + 1;
        (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                  (param_1,uVar15,*puVar11,local_68 + iVar4 + 8,iVar17,local_144,&DAT_001dbd34);
        if ((byte)"}J3x})+x|B;x}k"[iVar18 + 4] < uVar20) goto LAB_000994dc;
        puVar11 = puVar11 + 10;
      } while (uVar20 != 0);
    } while( true );
  }
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,local_7c);
  if (iVar4 == 0) {
    local_78 = auStack_170;
    iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,local_78);
    if (iVar4 == 0) {
      if ("}J3x})+x|B;x}k"[iVar18 + 5] == '\0') {
        local_1f8 = DAT_001aa798;
        local_1f4 = DAT_001aa79c;
        local_1ec = DAT_001aa7a4;
        local_1f0 = DAT_001aa7a0;
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (param_1,uVar15,local_f4,auStack_f0,iVar17,local_1e4,local_60 + 0x3800);
      }
      else {
        if ((*(int *)(param_1 + 0x420) == -1) &&
           (((int (*)())FUN_00092220)(param_1), *(int *)(param_1 + 0x420) == -1)) {
          return 2;
        }
        (**(code **)(((unsigned char *)0x000012f0) + iVar9))
                  (param_1,uVar15,local_f4,auStack_f0,iVar17,local_1e4,local_60 + 0x3800,
                   ((unsigned char *)0x000020d4) + (int)local_64);
      }
      puVar21 = ((unsigned char *)0x000020d4) + (int)local_64;
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (param_1,uVar15,local_194,auStack_190,iVar17,local_f4,auStack_e0,puVar21);
      (**(code **)(((unsigned char *)0x000012e4) + iVar9))
                (param_1,uVar15,local_16c,auStack_168,iVar17,local_f4,auStack_e0,puVar21);
      (**(code **)(((unsigned char *)0x00001318) + iVar9))
                (param_1,uVar15,local_194,auStack_190,iVar17,local_194,auStack_180,puVar21);
      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                (param_1,uVar15,local_194,auStack_190,iVar17,local_16c,auStack_158,puVar21);
      do {
        uVar20 = 0;
        puVar21 = ((unsigned char *)0x000020d4) + (int)local_64;
        puVar11 = (undefined4 *)(iVar9 + 0x290);
        puVar24 = &local_f4;
        do {
          ((int (*)())FUN_000913e0)(param_1,*puVar11,&local_228,&local_21c,&local_208);
          iVar4 = uVar20 * 0x28;
          uVar20 = uVar20 + 1;
          (**(code **)(((unsigned char *)0x0000132c) + iVar9))
                    (param_1,uVar15,*puVar24,local_68 + iVar4 + 8,iVar17,local_194,auStack_180,
                     puVar21);
          if ((byte)"}J3x})+x|B;x}k"[iVar18 + 4] < uVar20) {
            ((int (*)())FUN_000911a0)(param_1,local_7c);
            ((int (*)())FUN_000911a0)(param_1,local_78);
LAB_000994dc:
            puVar11 = &local_f4;
            local_98 = FUN_001d8514;
            local_94 = FUN_001d8514;
            bVar1 = local_a4 != 0;
            local_8c = FUN_001d8514;
            bVar3 = iStack00000020 == 0;
            local_9c = 0x81fa;
            local_a8 = 0;
            local_90 = FUN_001d8514;
            puVar23 = local_68 + 8;
            local_88[0] = FUN_001d8514;
            iVar4 = iVar9;
            iVar12 = param_1;
            iVar13 = param_1;
            iVar14 = iVar16;
            do {
              if (bVar1) {
                (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                          (param_1,uVar15,*puVar11,puVar23,iVar17,*(undefined4 *)(local_a0 + 4),
                           local_a0 + 0x18,&DAT_001fa5e8);
              }
              if (bVar2) {
                if (((!bVar3) && (*(char *)(iVar9 + 0x12d) != '\0')) &&
                   (*(ushort *)("}J3x})+x|B;x}k" + iVar18) == local_9c)) {
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (param_1,uVar15,*(undefined4 *)(iVar13 + 0x600),
                             ((unsigned char *)0x00003870) + (int)local_98,iVar17,*(undefined4 *)(iVar13 + 0x600),
                             local_60 + 0x3800,&DAT_001fa5e8);
                }
              }
              else {
                uVar19 = *(undefined4 *)(iVar13 + 0x600);
                if (*(int *)(iVar14 + 0x18) == -1) {
                  ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar4 + 0x288),3,&local_228,&local_21c);
                }
                if (in_stack_0000003c == 1) {
                  iVar6 = local_228;
                  iVar8 = local_21c;
                  if ((!bVar3) && (*(ushort *)("}J3x})+x|B;x}k" + iVar18) == local_9c))
                  goto LAB_0009966c;
LAB_000996c0:
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,uVar15,uVar19,((unsigned char *)0x00003870) + (int)local_98,iVar6,iVar8,
                             PTR_DAT_001e9788,&DAT_001fa5e8);
                }
                else {
                  iVar8 = *(int *)(iVar14 + 0x18);
                  if (iVar8 == -1) {
                    iVar6 = ((int (*)())FUN_00090ca0)(param_1,1,local_7c);
                    if (iVar6 != 0) {
                      return 7;
                    }
                    if (iVar5 == local_228) {
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,uVar15,local_194,PTR_DAT_001e978c,iVar5,local_21c,
                                 PTR_DAT_001e9788,PTR_DAT_001e9790);
                      if ((bVar3) || (*(ushort *)("}J3x})+x|B;x}k" + iVar18) != local_9c)) {
                        uVar22 = *(undefined4 *)(iVar16 + 0x14);
                        iVar6 = iVar5;
                        puVar21 = PTR_DAT_001e9788;
                        goto LAB_00099980;
                      }
                      uVar22 = *(undefined4 *)(iVar16 + 0x14);
                      iVar6 = iVar5;
                      puVar21 = PTR_DAT_001e9788;
LAB_0009991c:
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,uVar15,uVar19,PTR_DAT_001e978c,iVar6,uVar22,puVar21,
                                 PTR_DAT_001e9790);
                    }
                    else {
                      (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                                (param_1,uVar15,local_194,PTR_DAT_001e978c,iVar5,
                                 *(undefined4 *)(iVar16 + 0x14),PTR_DAT_001e9788,PTR_DAT_001e9790);
                      if ((!bVar3) && (*(ushort *)("}J3x})+x|B;x}k" + iVar18) == local_9c)) {
                        uVar22 = *puVar11;
                        puVar21 = ((unsigned char *)0x000037e0) + (int)local_94;
                        iVar6 = iVar17;
                        goto LAB_0009991c;
                      }
                      uVar22 = *puVar11;
                      puVar21 = ((unsigned char *)0x000037e0) + (int)local_94;
                      iVar6 = iVar17;
LAB_00099980:
                      (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                                (param_1,uVar15,uVar19,&DAT_001dbd84,iVar6,uVar22,puVar21,
                                 &DAT_001fa5e8);
                    }
                    ((int (*)())FUN_000911a0)(param_1,local_7c);
                  }
                  else {
                    iVar6 = iVar5;
                    if ((bVar3) || (*(ushort *)("}J3x})+x|B;x}k" + iVar18) != local_9c))
                    goto LAB_000996c0;
LAB_0009966c:
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,uVar15,uVar19,((unsigned char *)0x00003870) + (int)local_98,iVar6,iVar8,
                               local_60 + 0x3800,&DAT_001fa5e8);
                  }
                }
              }
              if (in_stack_00000038 == 0) {
                if (iStack00000024 != 0) {
                  uVar22 = *(undefined4 *)(iVar12 + 0x74);
                  uVar19 = *(undefined4 *)(iVar13 + 0x5b0);
                  uVar7 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar4 + 0x280),2,&local_228,&local_21c);
                  local_1fc = 3;
                  local_200 = 5;
                  local_208 = 5;
                  local_204 = 5;
                  (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                            (param_1,uVar7,uVar22,((unsigned char *)0x00003810) + (int)local_90,iVar17,uVar19,
                             ((unsigned char *)0x000038b0) + (int)local_88[0],&DAT_001fa5e8);
                }
              }
              else {
                uVar19 = *(undefined4 *)(iVar13 + 0x5b0);
                if (iStack00000024 == 0) {
                  uVar22 = **(undefined4 **)(param_1 + 0x3f0);
                  puVar21 = ((unsigned char *)0x00003870) + (int)local_98;
                }
                else {
                  uVar19 = *(undefined4 *)(iVar12 + 0x74);
                  uVar22 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
                  puVar21 = ((unsigned char *)0x00003810) + (int)local_90;
                }
                if (*(int *)(iVar14 + 0xc) == -1) {
                  ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar4 + 0x280),2,&local_228,&local_21c);
                }
                iVar6 = local_228;
                iVar8 = local_21c;
                if ((in_stack_00000038 == 1) ||
                   (iVar6 = iVar5, iVar8 = *(int *)(iVar14 + 0xc), *(int *)(iVar14 + 0xc) != -1)) {
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,uVar22,uVar19,puVar21,iVar6,iVar8,local_60 + 0x3800,
                             &DAT_001fa5e8);
                }
                else {
                  iVar6 = ((int (*)())FUN_00090ca0)(param_1,0,local_7c);
                  if (iVar6 != 0) {
                    return 7;
                  }
                  if (iVar5 == local_228) {
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,uVar15,local_194,puVar21,iVar5,local_21c,PTR_DAT_001e9788,
                               &DAT_001fa5e8);
                    uVar7 = *(undefined4 *)(iVar16 + 8);
                    puVar10 = ((unsigned char *)0x000038b0) + (int)local_88[0];
                    iVar6 = iVar5;
                  }
                  else {
                    (**(code **)(((unsigned char *)0x000012ec) + iVar9))
                              (param_1,uVar15,local_194,puVar21,iVar5,*(undefined4 *)(iVar16 + 8),
                               ((unsigned char *)0x000038b0) + (int)local_88[0],&DAT_001fa5e8);
                    uVar7 = *puVar11;
                    puVar10 = ((unsigned char *)0x000038d8) + (int)local_8c;
                    iVar6 = iVar17;
                  }
                  (**(code **)(((unsigned char *)0x000012f4) + iVar9))
                            (param_1,uVar22,uVar19,puVar21,iVar6,uVar7,puVar10,&DAT_001fa5e8);
                  ((int (*)())FUN_000911a0)(param_1,local_7c);
                }
              }
              puVar25 = local_68;
              puVar23 = puVar23 + 0x28;
              puVar11 = puVar11 + 10;
              iVar12 = iVar12 + 4;
              iVar13 = iVar13 + 0x28;
              iVar4 = iVar4 + 4;
              iVar14 = iVar14 + 4;
              local_a8 = local_a8 + 1;
              if ((byte)"}J3x})+x|B;x}k"[iVar18 + 4] < local_a8) {
                uVar20 = 0;
                ((int (*)())FUN_000911a0)(param_1,local_84);
                ((int (*)())FUN_000911a0)(param_1,local_70);
                ((int (*)())FUN_000911a0)(param_1,local_a0);
                do {
                  uVar20 = uVar20 + 1;
                  ((int (*)())FUN_000911a0)(param_1,puVar25);
                  puVar25 = puVar25 + 0x28;
                } while (uVar20 <= (byte)"}J3x})+x|B;x}k"[iVar18 + 4]);
                return 0;
              }
            } while( true );
          }
          puVar11 = puVar11 + 1;
          puVar24 = puVar24 + 10;
          puVar21 = ((unsigned char *)0x00003880) + (int)local_80;
        } while (uVar20 != 0);
      } while( true );
    }
  }
  return 7;
}

/* FUN_00099e50 @ 0x99e50 (1796 bytes) */
int FUN_00099e50(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  int local_d0;
  int local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar5 = 4;
  switch(param_2) {
  case 0:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
  case 2:
    iVar3 = *(int *)(param_1 + 0x334);
    break;
  case 1:
    iVar3 = *(int *)(param_1 + 0x4c);
    break;
  case 3:
    if (*(int *)(param_1 + 0x4c) == -1) {
      return 2;
    }
  case 4:
    iVar3 = *(int *)(param_1 + 0x334);
    goto joined_r0x00099f10;
  default:
    goto switchD_00099ea8_default;
  }
  if (iVar3 == -1) {
    return 2;
  }
  iVar3 = *(int *)(param_1 + 0x338);
joined_r0x00099f10:
  if (iVar3 == -1) {
    return 2;
  }
  if (*(int *)(param_1 + 0x340) == -1) {
    return 2;
  }
  if (*(int *)(param_1 + 0x6c) == -1) {
    return 2;
  }
  iVar10 = *(int *)(param_1 + 0x3d4);
  iVar3 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_80);
  bVar1 = param_2 < 3;
  if (iVar3 != 0) {
    return 7;
  }
  if ((bVar1) && (iVar3 = ((int (*)())FUN_00090ca0)(param_1,1,auStack_a8), iVar3 != 0)) {
    return 7;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x3ec);
  local_58 = (*(undefined4 **)(param_1 + 0x3f0))[7];
  uVar8 = puVar4[2];
  uVar7 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = *puVar4;
  uVar9 = puVar4[1];
  if (param_2 == 0) {
    (**(code **)(((unsigned char *)0x000012ec) + iVar10))
              (param_1,uVar7,local_a4,&DAT_001dbd54,uVar9,*(undefined4 *)(param_1 + 0x4c),
               &DAT_001fa5f8);
  }
  if (bVar1) {
    if ((*(int *)(param_1 + 0x510) == -1) &&
       (((int (*)())FUN_00091880)(param_1), *(int *)(param_1 + 0x510) == -1)) {
      return 2;
    }
    uVar6 = *(undefined4 *)(param_1 + 0x338);
    if (param_3 == 0) {
      iVar3 = *(int *)(param_1 + 0x538);
      if (iVar3 == -1) {
        ((int (*)())FUN_00092150)(param_1);
        iVar3 = *(int *)(param_1 + 0x538);
        if (iVar3 == -1) {
          return 2;
        }
      }
      local_d8 = 1;
      local_d4 = 1;
      local_e0 = 4;
      local_dc = 4;
      local_e4 = 5;
      local_e8 = *(undefined4 *)(param_1 + 0x54c);
      local_d0 = param_3;
      local_cc = param_3;
      (**(code **)(((unsigned char *)0x000012ec) + iVar10))
                (param_1,uVar7,local_a4,&local_d8,uVar5,iVar3,&local_e8,&DAT_001fa5e8);
      local_e8 = 1;
      local_e0 = 5;
      local_dc = 4;
      local_e4 = param_3;
      (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                (param_1,uVar7,local_7c,auStack_78,uVar8,uVar6,&DAT_001dbd74,&DAT_001fa5e8);
    }
    else {
      local_e8 = *(undefined4 *)(param_1 + 0x524);
      local_e0 = 5;
      local_dc = 4;
      local_e4 = 4;
      (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                (param_1,uVar7,local_7c,auStack_78,uVar8,uVar6,&DAT_001dbd74);
    }
    (**(code **)(((unsigned char *)0x00001318) + iVar10))
              (param_1,uVar7,local_7c,auStack_78,uVar5,local_7c,&local_68,&DAT_001fa5e8);
  }
  uVar6 = local_7c;
  switch(param_2) {
  case 0:
    bVar2 = false;
    local_c8 = DAT_001dbcf4;
    local_c4 = DAT_001dbcf8;
    local_f4 = local_64;
    local_c0 = DAT_001dbcfc;
    local_bc = DAT_001dbd00;
    local_f8 = local_68;
    local_ec = local_5c;
    local_f0 = local_60;
    uVar9 = uVar5;
    uVar11 = local_a4;
    break;
  case 1:
    uVar11 = *(undefined4 *)(param_1 + 0x4c);
    bVar2 = false;
    local_c8 = DAT_001fa5f8;
    local_c4 = DAT_001fa5fc;
    local_f4 = local_64;
    local_c0 = DAT_001fa600;
    local_bc = DAT_001fa604;
    local_f8 = local_68;
    local_ec = local_5c;
    local_f0 = local_60;
    break;
  case 2:
    local_c4 = local_64;
    local_c8 = local_68;
    local_bc = local_5c;
    local_c0 = local_60;
    goto LAB_0009a3bc;
  case 3:
    local_7c = *(undefined4 *)(param_1 + 0x4c);
    local_c8 = DAT_001fa5f8;
    local_bc = DAT_001fa604;
    local_c4 = DAT_001fa5fc;
    local_c0 = DAT_001fa600;
    uVar5 = uVar9;
    goto LAB_0009a3bc;
  case 4:
    local_7c = *(undefined4 *)(param_1 + 0x340);
    local_c8 = DAT_001dbdb4;
    local_bc = DAT_001dbdc0;
    local_c4 = DAT_001dbdb8;
    local_c0 = DAT_001dbdbc;
    uVar5 = uVar8;
LAB_0009a3bc:
    bVar2 = true;
    local_f8 = DAT_001dbcf4;
    local_f4 = DAT_001dbcf8;
    local_f0 = DAT_001dbcfc;
    local_ec = DAT_001dbd00;
    uVar9 = uVar5;
    uVar11 = local_7c;
    uVar5 = uVar8;
    uVar6 = *(undefined4 *)(param_1 + 0x334);
    break;
  default:
    bVar2 = false;
    uVar9 = 0;
    uVar11 = 0;
    uVar5 = 0;
    uVar6 = 0;
  }
  if (bVar1) {
    ((int (*)())FUN_000911a0)(param_1,auStack_a8);
  }
  local_b8[0] = 0;
  local_b0 = 4;
  local_b4 = 4;
  local_ac = 1;
  if (bVar2) {
    iVar3 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_a8);
    if (iVar3 != 0) {
      return 7;
    }
    (**(code **)(((unsigned char *)0x000012e8) + iVar10))
              (param_1,uVar7,local_a4,auStack_a0,uVar5,uVar6,&local_f8,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012fc) + iVar10))
              (param_1,local_58,*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,uVar9,uVar11,&local_c8
               ,&DAT_001fa5e8);
    ((int (*)())FUN_000911a0)(param_1,auStack_a8);
  }
  else {
    (**(code **)(((unsigned char *)0x000012fc) + iVar10))
              (param_1,local_58,*(undefined4 *)(param_1 + 0x6c),&DAT_001dbd24,uVar9,uVar11,&local_c8
               ,&DAT_001fa5e8);
  }
  ((int (*)())FUN_000911a0)(param_1,auStack_80);
  uVar5 = 0;
switchD_00099ea8_default:
  return uVar5;
}

/* FUN_0009a590 @ 0x9a590 (848 bytes) */
int FUN_0009a590(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar7 = *(int *)(param_1 + 0x70);
  if (iVar7 != -1) {
    iVar8 = *(int *)(param_1 + 0x3d4);
    uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
      iVar9 = *(int *)(param_1 + 0x3f8);
      if (iVar9 == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar8) & 4) == 0) {
          ((int (*)())FUN_000916d0)();
        }
        else {
          ((int (*)())FUN_000914e0)();
        }
        iVar9 = *(int *)(param_1 + 0x3f8);
        if (iVar9 == -1) {
          return 2;
        }
        iVar8 = *(int *)(param_1 + 0x3d4);
      }
      iVar3 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
      uVar5 = **(undefined4 **)(param_1 + 0x3ec);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar3) != -0x7bae) ||
         (*(short *)(((unsigned char *)0x00002e08) + iVar3) == -0x7aa4)) {
        (**(code **)(((unsigned char *)0x00001304) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbcf4,&DAT_001fa5e8);
        return 0;
      }
      if (*(short *)(((unsigned char *)0x00002e08) + iVar3) != -0x7aa5) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbcf4,&DAT_001dbd94);
        return 0;
      }
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      iVar3 = ((int (*)())FUN_00090ca0)(param_1,1,auStack_68);
      if (iVar3 == 0) {
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar4,local_64,&DAT_001dbd04,uVar5,iVar9,&DAT_001dbd74,&DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x00001318) + iVar8))
                  (param_1,uVar4,local_64,&DAT_001dbd64,uVar5,local_64,&DAT_001fa5f8,&DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,uVar5,local_64,&DAT_001dbec4,&DAT_001fa5e8);
        ((int (*)())FUN_000911a0)(param_1,auStack_68);
        return 0;
      }
      return 7;
    }
    if (*(int *)(param_1 + 0x50) != -1) {
      uVar1 = *(uint *)(param_1 + 0x54);
      if (uVar1 < 4) {
        if (uVar1 == 2) {
          puVar2 = &DAT_001dbcf4;
        }
        else if (uVar1 == 3) {
          puVar2 = &DAT_001dbcd4;
        }
        else if (uVar1 == 1) {
          puVar2 = &DAT_001dbce4;
        }
        else {
          puVar2 = &DAT_001fa5f8;
        }
        (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                  (param_1,uVar6,iVar7,&DAT_001dbd04,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                   *(int *)(param_1 + 0x50),puVar2,&DAT_001fa5e8);
        return 0;
      }
      return 3;
    }
  }
  return 2;
}

/* FUN_0009a910 @ 0x9a910 (120 bytes) */
int FUN_0009a910(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)) != (code *)0x0) {
    (**(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)))(*(int *)(param_1 + 0x3d4),param_1);
  }
  if ((*(int *)(param_1 + 0x3d8) != 0) ||
     (uVar1 = 6, *(uint *)(param_1 + 0x3cc) <= *(uint *)(param_1 + 0x3e4))) {
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_0009a990 @ 0x9a990 (104 bytes) */
int FUN_0009a990(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x3c8) != 0) {
      (**(code **)(param_1 + 0x18))();
    }
    (**(code **)(param_1 + 0x18))(param_2);
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_0009aa00 @ 0x9aa00 (1232 bytes) */
int FUN_0009aa00(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8[0];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [24];
  undefined4 local_88[0];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  
  iVar11 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) != -1) {
    return 0;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x3ec);
  uVar4 = *(undefined4 *)(param_1 + 0x330);
  uVar8 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = puVar2[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar11 + 4) + 0x10)) == -0x7bae) {
    iVar3 = *(int *)(param_1 + 0x3f8);
    if (iVar3 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar11) & 4) == 0) {
        ((int (*)())FUN_000916d0)();
      }
      else {
        ((int (*)())FUN_000914e0)();
      }
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        return 2;
      }
      puVar2 = *(undefined4 **)(param_1 + 0x3ec);
    }
    uVar12 = *puVar2;
    puVar2 = &DAT_001dbcf4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x54);
    uVar12 = puVar2[1];
    iVar3 = *(int *)(param_1 + 0x50);
    if (iVar1 == 1) {
      puVar2 = &DAT_001dbce4;
    }
    else if (iVar1 == 0) {
      puVar2 = &DAT_001fa5f8;
    }
    else if (iVar1 == 2) {
      puVar2 = &DAT_001dbcf4;
    }
    else if (iVar1 == 3) {
      puVar2 = &DAT_001dbcd4;
    }
    else {
      puVar2 = &DAT_001dbd14;
    }
  }
  iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x584);
  if (iVar1 == 0) {
    uVar9 = *(undefined4 *)(param_1 + 0x588);
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_a8);
    if (iVar1 == 0) {
      iVar10 = *(int *)(param_1 + 0x3d4);
      iVar1 = *(int *)(*(int *)(iVar10 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar1) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
          uVar6 = **(undefined4 **)(param_1 + 0x3f0);
          uVar7 = **(undefined4 **)(param_1 + 0x3ec);
          iVar1 = ((int (*)())FUN_00090ca0)(param_1,1,auStack_80);
          if (iVar1 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                    (param_1,uVar6,local_7c,&DAT_001dbd04,uVar12,iVar3,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar10))
                    (param_1,uVar6,local_7c,&DAT_001dbd64,uVar7,local_7c,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                    (param_1,uVar8,local_a4,auStack_a0,uVar7,local_7c,&DAT_001dbec4,&DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_80);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar10))
                    (param_1,uVar8,local_a4,auStack_a0,uVar12,iVar3,puVar2,&DAT_001dbd94);
        }
      }
      else {
        (**(code **)(((unsigned char *)0x00001304) + iVar10))
                  (param_1,uVar8,local_a4,auStack_a0,uVar12,iVar3,puVar2,&DAT_001fa5e8);
      }
      uVar12 = **(undefined4 **)(param_1 + 0x3ec);
      local_ac = 4;
      local_c8 = 4;
      local_c0 = 2;
      local_c4 = 1;
      local_bc = 4;
      local_b8[0] = 4;
      local_b4 = 5;
      local_b0 = local_88[0];
      if (*(int *)(param_1 + 0x3d8) != 0) {
        (**(code **)(((unsigned char *)0x000012e4) + iVar11))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
                   *(undefined4 *)(param_1 + 0x70),&DAT_001dbd04,uVar5,uVar4,&local_c8);
        ((int (*)())FUN_000911a0)(param_1,auStack_a8);
        return 0;
      }
      puVar2 = (undefined4 *)(param_1 + 0x58c);
      (**(code **)(((unsigned char *)0x000012e4) + iVar11))(param_1,uVar8,uVar9,puVar2,uVar5,uVar4,&local_c8);
      ((int (*)())FUN_000911a0)(param_1,auStack_a8);
      uVar4 = uVar9;
      if (-1 < *(int *)(iVar11 + 0x44)) {
        uVar4 = *(undefined4 *)(param_1 + 0x70);
        puVar2 = &DAT_001dbd44;
        uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      }
      (**(code **)(((unsigned char *)0x00001328) + iVar11))(param_1,uVar8,uVar4,puVar2,uVar12,uVar9,param_1 + 0x59c)
      ;
      return 0;
    }
  }
  return 7;
}

/* FUN_0009af00 @ 0x9af00 (172 bytes) */
int FUN_0009af00(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())FUN_0009aa00)();
  return uVar1;
}

/* FUN_0009afc0 @ 0x9afc0 (1084 bytes) */
int FUN_0009afc0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined1 auStack_90 [16];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  
  iVar13 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) != -1) {
    return 0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x3ec);
  uVar6 = *(undefined4 *)(param_1 + 0x330);
  uVar11 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = puVar3[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar13 + 4) + 0x10)) == -0x7bae) {
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar13) & 4) == 0) {
        ((int (*)())FUN_000916d0)();
      }
      else {
        ((int (*)())FUN_000914e0)();
      }
      iVar4 = *(int *)(param_1 + 0x3f8);
      if (iVar4 == -1) {
        return 2;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x3ec);
    }
    uVar12 = *puVar3;
    puVar3 = &DAT_001dbcf4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x54);
    uVar12 = puVar3[1];
    iVar4 = *(int *)(param_1 + 0x50);
    if (iVar2 == 1) {
      puVar3 = &DAT_001dbce4;
    }
    else if (iVar2 == 0) {
      puVar3 = &DAT_001fa5f8;
    }
    else if (iVar2 == 2) {
      puVar3 = &DAT_001dbcf4;
    }
    else if (iVar2 == 3) {
      puVar3 = &DAT_001dbcd4;
    }
    else {
      puVar3 = &DAT_001dbd14;
    }
  }
  iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x584);
  if (iVar2 == 0) {
    uVar9 = *(undefined4 *)(param_1 + 0x588);
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_a8);
    uVar1 = local_a4;
    if (iVar2 == 0) {
      iVar10 = *(int *)(param_1 + 0x3d4);
      iVar2 = *(int *)(*(int *)(iVar10 + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + iVar2) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + iVar2) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + iVar2) == -0x7aa5) {
          uVar7 = **(undefined4 **)(param_1 + 0x3f0);
          uVar8 = **(undefined4 **)(param_1 + 0x3ec);
          iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,auStack_80);
          if (iVar2 != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                    (param_1,uVar7,local_7c,&DAT_001dbd04,uVar12,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar10))
                    (param_1,uVar7,local_7c,&DAT_001dbd64,uVar8,local_7c,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          (**(code **)(((unsigned char *)0x000012e4) + iVar10))
                    (param_1,uVar11,uVar1,auStack_a0,uVar8,local_7c,&DAT_001dbec4,&DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_80);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + iVar10))
                    (param_1,uVar11,local_a4,auStack_a0,uVar12,iVar4,puVar3,&DAT_001dbd94);
        }
      }
      else {
        (**(code **)(((unsigned char *)0x00001304) + iVar10))
                  (param_1,uVar11,local_a4,auStack_a0,uVar12,iVar4,puVar3,&DAT_001fa5e8);
      }
      uVar12 = **(undefined4 **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012ec) + iVar13))
                (param_1,uVar11,local_a4,auStack_a0,uVar5,uVar6,&DAT_001dbcf4);
      if (*(int *)(param_1 + 0x3d8) == 0) {
        puVar3 = (undefined4 *)(param_1 + 0x58c);
        if (-1 < *(int *)(iVar13 + 0x44)) {
          uVar9 = *(undefined4 *)(param_1 + 0x70);
          puVar3 = &DAT_001dbd44;
          uVar11 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        }
      }
      else {
        uVar9 = *(undefined4 *)(param_1 + 0x70);
        puVar3 = &DAT_001dbd04;
        uVar11 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
      }
      (**(code **)(((unsigned char *)0x00001320) + iVar13))
                (param_1,uVar11,uVar9,puVar3,uVar12,local_a4,auStack_90,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_a8);
      return 0;
    }
  }
  return 7;
}

/* FUN_0009b430 @ 0x9b430 (848 bytes) */
int FUN_0009b430(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined *puVar13;
  undefined4 uVar14;
  undefined4 local_88[0];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  undefined *local_68;
  undefined *local_64;
  undefined4 *local_60;
  undefined *local_5c;
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar11 = *(int *)(param_1 + 0x3d4);
    local_60 = &local_80;
    uVar5 = 0;
    uVar3 = **(undefined4 **)(param_1 + 0x3ec);
    iVar6 = *(int *)(*(int *)(iVar11 + 4) + 0x10);
    local_68 = &DAT_001db440;
    local_64 = &DAT_001db440;
    local_5c = &DAT_001db440;
    iVar8 = param_1;
    iVar9 = iVar11;
    iVar10 = param_1;
    do {
      uVar12 = *(undefined4 *)(iVar10 + 0x5b0);
      uVar7 = *(undefined4 *)(iVar10 + 0x600);
      uVar14 = *(undefined4 *)(iVar8 + 0x74);
      ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar9 + 0x280),2,&local_88,&local_84);
      local_80 = 5;
      local_7c = 5;
      local_78 = 5;
      local_74 = 3;
      if (param_2 == 0) {
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc),uVar14,local_68 + 0x8e4,
                   uVar3,uVar12,local_64 + 0x984,&DAT_001fa5e8);
      }
      if ((((*(short *)("}J3x})+x|B;x}k" + iVar6) == -0x7e06) && (*(char *)(iVar11 + 0x12d) != '\0')
           ) || (((*(uint *)(iVar11 + 0x44) & 0x1000000) != 0 && (*(char *)(iVar11 + 0x121) == '\0')
                 ))) || ((*(uint *)(iVar11 + 0x44) & 0xa10000) != 0)) {
        iVar4 = *(int *)(iVar8 + 0x7c);
        uVar12 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
        ((int (*)())FUN_000912f0)(param_1,*(undefined4 *)(iVar9 + 0x288),3,&local_88,&local_84);
        if (((*(short *)("}J3x})+x|B;x}k" + iVar6) != -0x7e06) ||
            (*(char *)(iVar11 + 0x12d) == '\0')) || (param_2 == 0)) {
          puVar13 = local_5c + 0x964;
          uVar7 = local_84;
          uVar14 = local_88[0];
        }
        else {
          puVar13 = local_64 + 0x984;
          uVar14 = uVar3;
        }
        if ((((*(uint *)(iVar11 + 0x44) & 0x1000000) != 0) && (*(char *)(iVar11 + 0x121) == '\0'))
           && ((*(int *)(param_1 + 0x3d8) == 0 && (iVar4 == *(int *)(param_1 + 0x70))))) {
          if (*(char *)(iVar11 + 0x12e) == '\0') {
            if (*(int *)(param_1 + 0x588) == -1) {
              sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar6);
              if (sVar1 == 0x801) {
                ((int (*)())FUN_000928a0)(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              else if (sVar1 == 0x2601) {
                ((int (*)())FUN_0009aa00)(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              else {
                if (sVar1 != 0x800) {
                  return 2;
                }
                ((int (*)())FUN_0009afc0)(param_1);
                iVar2 = *(int *)(param_1 + 0x588);
              }
              if (iVar2 == -1) {
                return 2;
              }
            }
            local_74 = *(int *)(param_1 + 0x5a8);
          }
          else {
            local_74 = *(int *)(param_1 + 0x54);
            if (local_74 != 1) {
              if (local_74 == 0) {
                local_74 = 0;
              }
              else if ((local_74 != 2) && (local_74 != 3)) {
                local_74 = 3;
              }
            }
          }
        }
        (**(code **)(((unsigned char *)0x000012ec) + iVar11))
                  (param_1,uVar12,iVar4,local_68 + 0x8e4,uVar14,uVar7,puVar13,&DAT_001fa5e8);
      }
      uVar5 = uVar5 + 1;
      iVar10 = iVar10 + 0x28;
      iVar8 = iVar8 + 4;
      iVar9 = iVar9 + 4;
    } while (uVar5 <= (byte)"}J3x})+x|B;x}k"[iVar6 + 4]);
    uVar3 = 0;
  }
  return uVar3;
}

/* FUN_0009b790 @ 0x9b790 (172 bytes) */
int FUN_0009b790(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x330) == -1) || (iVar2 = *(int *)(param_1 + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(param_1 + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(param_1 + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(param_1 + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(param_1 + 0x3d8) == 0) && (iVar2 != *(int *)(param_1 + 0x74))) &&
      (iVar2 != *(int *)(param_1 + 0x78))) &&
     ((iVar2 != *(int *)(param_1 + 0x7c) && (iVar2 != *(int *)(param_1 + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())FUN_0009afc0)();
  return uVar1;
}

/* FUN_0009b850 @ 0x9b850 (892 bytes) */
int FUN_0009b850(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 < 8) {
    iVar7 = *(int *)(param_2 * 4 + param_1 + 0x84);
    if (iVar7 != -1) {
      iVar8 = *(int *)(param_1 + 0x3d4);
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14);
      local_74 = DAT_001dbda8;
      local_78 = DAT_001dbda4;
      local_70 = DAT_001dbdac;
      local_6c = DAT_001dbdb0;
      if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar8 + 4) + 0x10)) == -0x7bae) {
        iVar5 = *(int *)(param_1 + 0x3f8);
        if (iVar5 != -1) {
LAB_0009b914:
          uVar4 = **(undefined4 **)(param_1 + 0x3ec);
          local_78 = 2;
          iVar1 = *(int *)(*(int *)(iVar8 + 4) + 0x10);
          if (*(short *)(((unsigned char *)0x00002e06) + iVar1) != -0x7bae) {
            (**(code **)(((unsigned char *)0x00001304) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&local_78,&DAT_001fa5e8);
            return 0;
          }
          if (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5) {
            uVar3 = **(undefined4 **)(param_1 + 0x3ec);
            uVar2 = **(undefined4 **)(param_1 + 0x3f0);
            iVar1 = ((int (*)())FUN_00090ca0)(param_1,1,auStack_68);
            if (iVar1 != 0) {
              return 7;
            }
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar2,local_64,&DAT_001dbd04,uVar4,iVar5,&DAT_001dbd74,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x00001318) + iVar8))
                      (param_1,uVar2,local_64,&DAT_001dbd64,uVar3,local_64,&DAT_001fa5f8,
                       &DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012e4) + iVar8))
                      (param_1,uVar6,iVar7,&DAT_001dbd24,uVar3,local_64,&DAT_001dbec4,&DAT_001fa5e8)
            ;
            ((int (*)())FUN_000911a0)(param_1,auStack_68);
            return 0;
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,uVar4,iVar5,&local_78,&DAT_001dbd94);
          return 0;
        }
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar8) & 4) == 0) {
          ((int (*)())FUN_000916d0)();
        }
        else {
          ((int (*)())FUN_000914e0)();
        }
        iVar5 = *(int *)(param_1 + 0x3f8);
        if (iVar5 != -1) {
          iVar8 = *(int *)(param_1 + 0x3d4);
          goto LAB_0009b914;
        }
      }
      else if (*(int *)(param_1 + 0x50) != -1) {
        local_78 = *(uint *)(param_1 + 0x54);
        if (local_78 < 4) {
          if (local_78 != 1) {
            if (local_78 == 0) {
              local_78 = 0;
            }
            else if ((local_78 != 2) && (local_78 != 3)) {
              local_78 = 4;
            }
          }
          (**(code **)(((unsigned char *)0x000012e8) + iVar8))
                    (param_1,uVar6,iVar7,&DAT_001dbd24,
                     *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(int *)(param_1 + 0x50),
                     &local_78,&DAT_001fa5e8);
          return 0;
        }
        goto LAB_0009bbb0;
      }
    }
    uVar6 = 2;
  }
  else {
LAB_0009bbb0:
    uVar6 = 3;
  }
  return uVar6;
}

/* FUN_0009bd00 @ 0x9bd00 (96 bytes) */
int FUN_0009bd00(param_1)
  int param_1;
{
  ushort uVar1;
  int *piVar2;
  
  uVar1 = *(ushort *)(((unsigned char *)0x000013be) + param_1);
  piVar2 = (int *)(**(code **)(param_1 + 0xc))((uint)uVar1 * 8 + 0xc);
  piVar2[2] = 0;
  *piVar2 = (int)(piVar2 + 3);
  piVar2[1] = (int)(piVar2 + 3 + uVar1);
  return;
}

/* FUN_0009bd60 @ 0x9bd60 (160 bytes) */
int FUN_0009bd60(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x131) = param_2;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined1 *)(param_1 + 0x125) = 0;
  *(undefined1 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined1 *)(param_1 + 0x12d) = 0;
  *(undefined1 **)(((unsigned char *)0x000012cc) + param_1) = ((unsigned char *)0x0009bbf0);
  *(undefined1 **)(((unsigned char *)0x000012c8) + param_1) = ((unsigned char *)0x0009bc10);
  iVar2 = 8;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x150) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = param_1 + 0x3a0;
  iVar2 = 8;
  do {
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xffffff;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 299) = 0;
  *(undefined1 *)(param_1 + 0x126) = 0;
  return;
}

/* FUN_0009be00 @ 0x9be00 (2216 bytes) */
int FUN_0009be00(param_1)
  int param_1;
{
  char cVar1;
  char cVar2;
  char cVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  float fVar7;
  undefined4 uVar8;
  char cVar9;
  undefined1 uVar11;
  int iVar10;
  byte bVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 uVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  bool bVar24;
  int iVar25;
  byte *pbVar26;
  int iVar27;
  int iVar28;
  
  iVar16 = param_1 + 0x124;
  cVar1 = *(char *)(param_1 + 0x12f);
  iVar28 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  cVar9 = *(char *)(iVar28 + 0x24ad);
  cVar2 = *(char *)(iVar28 + 0x24ae);
  if (-1 < *(int *)(param_1 + 0x44)) {
    if ((*(uint *)(param_1 + 0x8c) & 0xc000000) != 0) {
      *(char *)(param_1 + 300) = cVar2;
      return;
    }
    *(undefined1 *)(param_1 + 300) = 0;
    return;
  }
  puVar22 = (uint *)(param_1 + 0x1874);
  cVar3 = "}J3x})+x|B;x}k"[iVar28 + 5];
  bVar24 = *(short *)("}J3x})+x|B;x}k" + iVar28) == -0x7e06;
  uVar23 = (uint)bVar24;
  uVar8 = *(undefined4 *)
           (&DAT_001dbed4 +
           (uint)(byte)"}J3x})+x|B;x}k"[iVar28 + 3] *
           ((*(ushort *)(((unsigned char *)0x00002d44) + iVar28) & 1 | *(ushort *)(((unsigned char *)0x00002d44) + iVar28) >> 2 & 2)
           + ((*(ushort *)(((unsigned char *)0x00002d46) + iVar28) >> 8 & 4) +
             (*(ushort *)(((unsigned char *)0x00002d46) + iVar28) & 0xf)) * 3 + 1) * 4);
  *(undefined4 *)(param_1 + 0x26c) = uVar8;
  if (*(int *)(param_1 + 0x13c) != 1) {
    uVar8 = 0;
  }
  *(undefined4 *)(param_1 + 0x1890) = uVar8;
  *(undefined1 *)(param_1 + 0x12f) = 0;
  if ((cVar3 != '\0') && (cVar2 == '\0')) {
    *(undefined1 *)(param_1 + 300) = 0;
    if ((*(uint *)(param_1 + 0x40) & 0x10000) != 0) {
      uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
      if (uVar21 != 0) {
        iVar15 = param_1;
        if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
          uVar21 = 1;
        }
        do {
          *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
          iVar15 = iVar15 + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
    }
    goto LAB_0009bfa0;
  }
  if (((*(uint *)(param_1 + 0x8c) >> 0x1a & 1) != 0 || (*(uint *)(param_1 + 0x8c) >> 0x1b & 1) != 0)
     && ((*(uint *)(param_1 + 0x40) & 0x10000) != 0)) {
    uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar21 != 0) {
      iVar15 = param_1;
      if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
        uVar21 = 1;
      }
      do {
        *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
        iVar15 = iVar15 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
  }
  if ((cVar2 == '\0') || (cVar9 != '\0')) {
    cVar9 = *(char *)(param_1 + 0x12f);
LAB_0009bf34:
    uVar11 = 0;
  }
  else {
    cVar9 = *(char *)(param_1 + 0x12f);
    uVar11 = 1;
    if (cVar9 != '\0') goto LAB_0009bf34;
  }
  *(undefined1 *)(param_1 + 300) = uVar11;
  if (cVar1 != cVar9) {
    uVar21 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar21 != 0) {
      iVar15 = param_1;
      if ((uVar21 == 0) || (uVar21 == 0x80000000)) {
        uVar21 = 1;
      }
      do {
        *(byte *)(iVar15 + 0x1814) = *(byte *)(iVar15 + 0x1814) | 0x18;
        iVar15 = iVar15 + 1;
        uVar21 = uVar21 - 1;
      } while (uVar21 != 0);
    }
  }
LAB_0009bfa0:
  if ((*(uint *)(param_1 + 0x180c) & 1) != 0) {
    *(uint *)(param_1 + 0x180c) = *(uint *)(param_1 + 0x180c) & 0xfffffffe;
  }
  fVar7 = FLOAT_001aa0e8;
  uVar21 = *(uint *)(param_1 + 0x88);
  if (uVar21 != 0) {
    iVar27 = 0;
    bVar6 = false;
    iVar25 = 0;
    iVar15 = param_1;
    puVar17 = puVar22;
    iVar19 = iVar16;
    do {
      if ((uVar21 & 1) != 0) {
        pbVar26 = (byte *)(iVar15 + 0x1814);
        iVar13 = iVar27 * 0x80 + iVar28 + 0x24c0;
        puVar14 = (undefined4 *)(((unsigned char *)0x000014a4) + iVar25 + param_1);
        if (*(byte *)(iVar15 + 0x1814) != 0) {
          if ((*(byte *)(iVar15 + 0x1814) & 1) != 0) {
            fVar5 = *(float *)(iVar27 * 0x80 + iVar28 + 0x24c0);
            if (((fVar5 == FLOAT_001aa0d4) && (*(float *)(iVar13 + 4) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 8) == FLOAT_001aa0d4)) {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff;
            }
            else if (((fVar5 == FLOAT_001aa0e8) && (*(float *)(iVar13 + 4) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 8) == FLOAT_001aa0e8)) {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0x40000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff | 0x2000;
            }
            else if (((*(float *)(iVar13 + 0x50) == fVar7) &&
                     (*(float *)(iVar13 + 0x54) == FLOAT_001aa0d4)) &&
                    ((*(float *)(iVar13 + 0x58) == FLOAT_001aa0d4 &&
                     (*(char *)(puVar14 + 0x1a) == '\0')))) {
              bVar6 = true;
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0xc0000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) | 0x6000;
            }
            else {
              iVar10 = iVar27 * 4 + iVar16;
              *(uint *)(iVar10 + 0x284) = *(uint *)(iVar10 + 0x284) & 0x3fffffff | 0x80000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0x9fff | 0x4000;
            }
          }
          iVar10 = iVar27 * 4;
          bVar12 = *pbVar26;
          if ((bVar12 & 2) != 0) {
            if (((*(float *)(iVar13 + 0x10) == FLOAT_001aa0d4) &&
                (*(float *)(iVar13 + 0x14) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 0x18) == FLOAT_001aa0d4)) {
              *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff;
              bVar12 = *pbVar26;
            }
            else if (((*(float *)(iVar13 + 0x10) == FLOAT_001aa0e8) &&
                     (*(float *)(iVar13 + 0x14) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 0x18) == FLOAT_001aa0e8)) {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff | 0x10000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff | 0x800;
              bVar12 = *pbVar26;
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xcfffffff | 0x20000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xe7ff | 0x1000;
              bVar12 = *pbVar26;
            }
          }
          if ((bVar12 & 4) != 0) {
            if (((*(float *)(iVar13 + 0x20) == FLOAT_001aa0d4) &&
                (*(float *)(iVar13 + 0x24) == FLOAT_001aa0d4)) &&
               (*(float *)(iVar13 + 0x28) == FLOAT_001aa0d4)) {
              *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999;
              bVar12 = *pbVar26;
            }
            else if (((*(float *)(iVar13 + 0x20) == FLOAT_001aa0e8) &&
                     (*(float *)(iVar13 + 0x24) == FLOAT_001aa0e8)) &&
                    (*(float *)(iVar13 + 0x28) == FLOAT_001aa0e8)) {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff | 0x4000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999 | 0x200;
              bVar12 = *pbVar26;
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xf3ffffff | 0x8000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 63999 | 0x400;
              bVar12 = *pbVar26;
            }
          }
          if ((bVar12 & 0x20) != 0) {
            if ((*(float *)(iVar13 + 0x54) == FLOAT_001aa0d4) &&
               (*(float *)(iVar13 + 0x58) == FLOAT_001aa0d4)) {
              if ((*(float *)(iVar13 + 0x50) == fVar7) ||
                 (*(float *)(iVar13 + 0x50) == FLOAT_001aa0d4)) {
                *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) & 0xfcffffff
                ;
                *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xffe7;
              }
              else {
                *(uint *)(iVar10 + iVar16 + 0x284) = *(uint *)(iVar10 + iVar16 + 0x284) | 0x3000000;
                *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) | 0x18;
                *(byte *)(iVar15 + 0x181c) = *(byte *)(iVar15 + 0x181c) | 4;
              }
            }
            else {
              *(uint *)(iVar10 + iVar16 + 0x284) =
                   *(uint *)(iVar10 + iVar16 + 0x284) & 0xfeffffff | 0x2000000;
              *(ushort *)(puVar17 + 8) = *(ushort *)(puVar17 + 8) & 0xfff7 | 0x10;
            }
          }
          if (*(float *)(iVar13 + 0x3c) == FLOAT_001aa0d4) {
            if (*(char *)(param_1 + 0x12f) == '\0') {
              uVar8 = puVar14[0x15];
              uVar18 = puVar14[0x16];
              uVar20 = puVar14[0x17];
              *(undefined4 *)(iVar19 + 0x174) = puVar14[0x14];
              *(undefined4 *)(iVar19 + 0x178) = uVar8;
              *(undefined4 *)(iVar19 + 0x17c) = uVar18;
              *(undefined4 *)(iVar19 + 0x180) = uVar20;
              uVar8 = puVar14[0x10];
              uVar18 = puVar14[0x11];
              uVar20 = puVar14[0x12];
              *(undefined4 *)(iVar19 + 0x200) = puVar14[0x13];
              *(undefined4 *)(iVar19 + 500) = uVar8;
              *(undefined4 *)(iVar19 + 0x1f8) = uVar18;
              *(undefined4 *)(iVar19 + 0x1fc) = uVar20;
            }
            else {
              uVar8 = puVar14[0xd];
              uVar18 = puVar14[0xe];
              uVar20 = puVar14[0xf];
              *(undefined4 *)(iVar19 + 0x174) = puVar14[0xc];
              *(undefined4 *)(iVar19 + 0x178) = uVar8;
              *(undefined4 *)(iVar19 + 0x17c) = uVar18;
              *(undefined4 *)(iVar19 + 0x180) = uVar20;
              uVar8 = puVar14[8];
              uVar18 = puVar14[9];
              uVar20 = puVar14[10];
              *(undefined4 *)(iVar19 + 0x200) = puVar14[0xb];
              *(undefined4 *)(iVar19 + 500) = uVar8;
              *(undefined4 *)(iVar19 + 0x1f8) = uVar18;
              *(undefined4 *)(iVar19 + 0x1fc) = uVar20;
            }
          }
          else {
            uVar8 = *puVar14;
            uVar18 = puVar14[2];
            uVar20 = puVar14[3];
            *(undefined4 *)(iVar19 + 0x178) = puVar14[1];
            *(undefined4 *)(iVar19 + 0x174) = uVar8;
            *(undefined4 *)(iVar19 + 0x17c) = uVar18;
            *(undefined4 *)(iVar19 + 0x180) = uVar20;
            fVar5 = (float)puVar14[4];
            fVar4 = (float)puVar14[5];
            *(float *)(iVar19 + 0x1fc) = -(float)puVar14[6];
            *(float *)(iVar19 + 500) = -fVar5;
            *(float *)(iVar19 + 0x1f8) = -fVar4;
            *(uint *)(iVar10 + iVar16 + 0x284) =
                 (uint)(*(float *)(iVar13 + 0x3c) == fVar7) << 0x17 |
                 *(uint *)(iVar10 + iVar16 + 0x284) & 0xff7fffff;
          }
          *pbVar26 = 0;
        }
        if (*(char *)(iVar15 + 0x181c) != '\0') {
          *(undefined1 *)(iVar15 + 0x181c) = 0;
        }
        uVar23 = uVar23 | -(*(uint *)(iVar27 * 4 + iVar16 + 0x284) >> 0x1a & 3) >> 0x1f;
      }
      bVar24 = SUB41(uVar23,0);
      uVar21 = uVar21 >> 1;
      iVar27 = iVar27 + 1;
      iVar25 = iVar25 + 0x6c;
      puVar17 = (uint *)((int)puVar17 + 2);
      iVar15 = iVar15 + 1;
      iVar19 = iVar19 + 0x10;
    } while (uVar21 != 0);
    if (bVar6) {
      *(undefined4 *)(param_1 + 0x3a0) = 0;
      *(undefined4 *)(param_1 + 0x398) = 0;
      *(undefined4 *)(param_1 + 0x39c) = 0;
      *puVar22 = *puVar22 | 4;
      uVar23 = *(uint *)(param_1 + 0x88);
      if (uVar23 != 0) {
        iVar16 = 0x24c0;
        puVar22 = (uint *)(param_1 + 0x3a8);
        do {
          if (((uVar23 & 1) != 0) && (*puVar22 >> 0x1e == 3)) {
            *(float *)(param_1 + 0x398) = *(float *)(param_1 + 0x398) + *(float *)(iVar28 + iVar16);
            *(float *)(param_1 + 0x39c) =
                 *(float *)(param_1 + 0x39c) + *(float *)(iVar28 + iVar16 + 4);
            *(float *)(param_1 + 0x3a0) =
                 *(float *)(param_1 + 0x3a0) + *(float *)(iVar28 + iVar16 + 8);
          }
          uVar23 = uVar23 >> 1;
          puVar22 = puVar22 + 1;
          iVar16 = iVar16 + 0x80;
        } while (uVar23 != 0);
      }
    }
  }
  *(bool *)(param_1 + 0x12d) = bVar24;
  return;
}

/* FUN_0009c700 @ 0x9c700 (248 bytes) */
int FUN_0009c700(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  if (*(int *)(((unsigned char *)0x0000111c) + param_1) != 0) {
    do {
      iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
      iVar1 = uVar3 * 4;
      iVar4 = *(int *)(iVar1 + iVar2);
      while (iVar4 != 0) {
        *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(iVar4 + 0x5c);
        ((int (*)())FUN_0009a990)(param_1,*(undefined4 *)(iVar4 + 0x54));
        if (*(int *)(iVar4 + 0x4c) != 0) {
          (**(code **)(param_1 + 0x18))();
        }
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar4 + 0x50));
        (**(code **)(param_1 + 0x18))(iVar4);
        iVar2 = *(int *)(((unsigned char *)0x00001118) + param_1);
        iVar4 = *(int *)(iVar1 + iVar2);
      }
      uVar3 = uVar3 + 1;
      *(undefined4 *)(iVar1 + iVar2) = 0;
    } while (uVar3 < *(uint *)(((unsigned char *)0x0000111c) + param_1));
  }
  *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x3c8) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  return;
}

/* FUN_0009c800 @ 0x9c800 (744 bytes) */
int FUN_0009c800(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  undefined4 *param_7;
  int param_8;
{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  
  pvVar6 = (void *)(**(code **)(param_1 + 0xc))(0x60);
  uVar8 = *(uint *)(param_1 + 0x3c8);
  if (1000000 < uVar8) {
    ((int (*)())FUN_0009c700)(param_1);
    uVar8 = *(uint *)(param_1 + 0x3c8);
  }
  if (((unsigned char *)0x00001120)[param_1] == '\0') {
    puVar9 = param_2 + 0xc;
    uVar4 = 0;
    puVar2 = param_2;
    while (puVar2 + 0xb <= puVar9) {
      uVar4 = uVar4 ^ *puVar2 ^ (puVar2[1] << 3 | puVar2[1] >> 0x1d) ^
              (puVar2[2] << 6 | puVar2[2] >> 0x1a) ^ (puVar2[3] << 9 | puVar2[3] >> 0x17) ^
              (puVar2[4] << 0xc | puVar2[4] >> 0x14) ^ (puVar2[5] << 0xf | puVar2[5] >> 0x11) ^
              (puVar2[6] << 0x12 | puVar2[6] >> 0xe) ^ (puVar2[7] << 0x15 | puVar2[7] >> 0xb) ^
              (puVar2[8] << 0x18 | puVar2[8] >> 8) ^ (puVar2[9] << 0x1b | puVar2[9] >> 5) ^
              (puVar2[10] << 0x1e | puVar2[10] >> 2);
      puVar2 = puVar2 + 0xb;
    }
    puVar10 = puVar2 + 5;
    if (puVar9 < puVar10) {
      uVar5 = 0;
      puVar10 = puVar2;
    }
    else {
      uVar5 = 0xf;
      uVar4 = uVar4 ^ *puVar2 ^ (puVar2[1] << 3 | puVar2[1] >> 0x1d) ^
              (puVar2[2] << 6 | puVar2[2] >> 0x1a) ^ (puVar2[3] << 9 | puVar2[3] >> 0x17) ^
              (puVar2[4] << 0xc | puVar2[4] >> 0x14);
    }
    for (; puVar10 < puVar9; puVar10 = puVar10 + 1) {
      uVar1 = uVar5 & 0x1f;
      uVar5 = uVar5 + 3;
      uVar4 = uVar4 ^ (*puVar10 << uVar1 | *puVar10 >> 0x20 - uVar1);
    }
    iVar11 = uVar4 - (uVar4 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                     *(uint *)(((unsigned char *)0x0000111c) + param_1);
  }
  else {
    uVar4 = *param_2 + param_2[2] + param_2[3];
    iVar11 = uVar4 - (uVar4 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                     *(uint *)(((unsigned char *)0x0000111c) + param_1);
  }
  *(uint *)((int)pvVar6 + 0x30) = uVar8;
  *(int *)(param_1 + 0x3c8) = *(int *)(param_1 + 0x3c8) + 1;
  _memcpy(pvVar6,param_2,0x30);
  *(undefined4 *)((int)pvVar6 + 0x3c) = param_4;
  *(undefined4 *)((int)pvVar6 + 0x40) = param_5;
  *(int *)((int)pvVar6 + 0x54) = param_3;
  uVar3 = *(undefined4 *)(param_3 + 0x3d0);
  *(int *)((int)pvVar6 + 0x48) = param_6;
  *(undefined4 *)((int)pvVar6 + 0x44) = uVar3;
  if (param_7 == (undefined4 *)0x0) {
    iVar7 = ((int (*)())FUN_0009bd00)(param_1);
    *(int *)((int)pvVar6 + 0x50) = iVar7;
    *(undefined4 *)(iVar7 + 8) = 0;
    *(undefined4 *)((int)pvVar6 + 0x4c) = 0;
    *(undefined1 *)((int)pvVar6 + 0x58) = 0;
  }
  else {
    *(undefined4 **)((int)pvVar6 + 0x50) = param_7;
    if (((param_7[2] == 1) && (*(int *)*param_7 == 0)) && (*(int *)param_7[1] == 0)) {
      *(undefined1 *)((int)pvVar6 + 0x58) = 1;
      *(undefined4 *)((int)pvVar6 + 0x4c) = 0;
    }
    else {
      *(undefined1 *)((int)pvVar6 + 0x58) = 0;
      uVar3 = (**(code **)(param_1 + 0xc))(param_6 << 4);
      *(undefined4 *)((int)pvVar6 + 0x4c) = uVar3;
    }
  }
  *(undefined1 *)((int)pvVar6 + 0x59) = param_8;
  *(undefined4 *)((int)pvVar6 + 0x5c) =
       *(undefined4 *)(*(int *)(((unsigned char *)0x00001118) + param_1) + iVar11 * 4);
  *(void **)(iVar11 * 4 + *(int *)(((unsigned char *)0x00001118) + param_1)) = pvVar6;
  return pvVar6;
}

/* FUN_0009cb10 @ 0x9cb10 (280 bytes) */
int FUN_0009cb10(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [4];
  
  iVar4 = *(int *)(param_2 + 0x54);
  pvVar1 = (void *)(**(code **)(param_1 + 0xc))(param_4 * *(int *)(iVar4 + 0x3cc));
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar4 + 0x3c8);
  uVar3 = *(undefined4 *)(iVar4 + 0x3cc);
  *(int **)(param_3 + 0x1c) = &local_38;
  *(undefined4 **)(param_3 + 0x28) = &local_34;
  *(void **)(param_3 + 0x18) = pvVar1;
  *(undefined4 **)(param_3 + 0x2c) = &local_30;
  *(undefined4 *)(param_3 + 8) = uVar3;
  *(undefined4 **)(param_3 + 0x30) = local_2c;
  iVar2 = FUN_0007c760(param_3);
  if (iVar2 == 0) {
    _memcpy(*(void **)(iVar4 + 0x3c8),pvVar1,param_4 * local_38);
    *(int *)(iVar4 + 0x3cc) = local_38;
    *(undefined4 *)(param_2 + 0x38) = local_30;
    *(undefined4 *)(param_2 + 0x44) = local_2c[0];
    *(undefined4 *)(param_2 + 0x34) = local_34;
  }
  else {
    _memcpy(*(void **)(iVar4 + 0x3c8),pvVar1,param_4 * *(int *)(iVar4 + 0x3cc));
  }
  (**(code **)(param_1 + 0x18))(pvVar1);
  return iVar2 == 0;
}

/* FUN_0009cc30 @ 0x9cc30 (712 bytes) */
int FUN_0009cc30(param_1)
  int param_1;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  bool bVar20;
  uint uVar21;
  ushort *puVar22;
  int iVar23;
  bool bVar24;
  int iVar25;
  
  iVar23 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(iVar23 + 0x24ad) == '\0') {
    uVar18 = *(uint *)(param_1 + 0x44);
    bVar20 = false;
    bVar4 = false;
    uVar21 = 0;
  }
  else {
    uVar18 = *(uint *)(param_1 + 0x44);
    if (((int)uVar18 < 0) && (uVar21 = *(uint *)(param_1 + 0x88), uVar21 != 0)) {
      bVar20 = false;
      bVar4 = false;
      iVar19 = iVar23;
      do {
        if ((uVar21 & 1) != 0) {
          bVar24 = *(float *)(iVar19 + 0x24fc) == FLOAT_001aa0d4;
          bVar4 = (bool)(bVar24 | bVar4);
          bVar20 = (bool)(!bVar24 | bVar20);
        }
        uVar21 = uVar21 >> 1;
        iVar19 = iVar19 + 0x80;
      } while (uVar21 != 0);
    }
    else {
      bVar20 = false;
      bVar4 = false;
    }
    uVar21 = -(*(uint *)(param_1 + 0x8c) & 0xc000000) >> 0x1f;
  }
  uVar15 = *(uint *)(param_1 + 0x1874);
  uVar2 = ((byte)"}J3x})+x|B;x}k"[iVar23 + 5] & 1) << 0x1d;
  uVar3 = (*(byte *)(param_1 + 300) & 1) << 0x1a;
  *(uint *)(param_1 + 0x1874) = uVar3 | uVar2 | uVar15 & 0xdbffffff;
  if (((uVar21 != 0) || (bVar20)) || (iVar19 = 0, bVar4)) {
    iVar19 = 1;
  }
  uVar21 = iVar19 << 0x18;
  uVar16 = uVar21 | uVar3 | uVar2 | uVar15 & 0xdaffffff;
  *(uint *)(param_1 + 0x1874) = uVar16;
  if ((int)uVar18 < 0) {
    uVar18 = *(uint *)(param_1 + 0x88);
    iVar25 = 8;
    *(uint *)(param_1 + 0x1874) = uVar16 | 0x800;
    fVar14 = FLOAT_001aa0e8;
    fVar13 = FLOAT_001aa0d4;
    puVar22 = (ushort *)(param_1 + 0x1894);
    iVar17 = 0;
    iVar19 = param_1 + 0x3a8;
    uVar16 = (uint)(*(short *)("}J3x})+x|B;x}k" + iVar23) == -0x7e06) << 10;
    *(uint *)(param_1 + 0x1874) = uVar16 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafffbff | 0x800;
    *(uint *)(param_1 + 0x1874) =
         (*(byte *)(param_1 + 0x12d) & 1) << 8 |
         ((byte)"}J3x})+x|B;x}k"[iVar23 + 4] & 1) << 9 |
         uVar16 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafff8ff | 0x800;
    do {
      if ((uVar18 & 1) == 0) {
        *puVar22 = 0;
      }
      else {
        uVar1 = *puVar22;
        *puVar22 = uVar1 | 0x8000;
        uVar8 = (ushort)((uint)*(undefined4 *)(iVar19 + iVar17) >> 0x11) & 0x6000;
        *puVar22 = uVar8 | uVar1 & 0x9fff | 0x8000;
        uVar9 = (*(byte *)(iVar19 + iVar17) & 0x30) << 7;
        *puVar22 = uVar8 | uVar1 & 0x87ff | 0x8000 | uVar9;
        uVar10 = (*(byte *)(iVar19 + iVar17) & 0xc) << 7;
        *puVar22 = uVar8 | uVar1 & 0x81ff | 0x8000 | uVar9 | uVar10;
        uVar5 = (ushort)(*(float *)(iVar23 + 0x24fc) != fVar13) << 8;
        *puVar22 = uVar8 | uVar1 & 0x80ff | 0x8000 | uVar9 | uVar10 | uVar5;
        uVar6 = (ushort)(*(float *)(iVar23 + 0x24fc) == fVar14) << 7;
        *puVar22 = uVar8 | uVar1 & 0x807f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6;
        uVar11 = ((byte)((unsigned char *)0x0000150c)[param_1] & 1) << 6;
        *puVar22 = uVar8 | uVar1 & 0x803f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 | uVar11;
        uVar7 = (ushort)(*(float *)(iVar23 + 0x251c) != fVar13) << 5;
        *puVar22 = uVar8 | uVar1 & 0x801f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 | uVar11 | uVar7
        ;
        uVar12 = (ushort)((uint)*(undefined4 *)(iVar19 + iVar17) >> 0x15) & 0x10;
        *puVar22 = uVar12 | uVar8 | uVar1 & 0x800f | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 |
                            uVar11 | uVar7;
        *puVar22 = uVar12 | uVar8 | uVar1 & 0x8007 | 0x8000 | uVar9 | uVar10 | uVar5 | uVar6 |
                            uVar11 | uVar7 | (*(byte *)(iVar19 + iVar17) & 1) << 3;
      }
      uVar18 = uVar18 >> 1;
      puVar22 = puVar22 + 1;
      iVar17 = iVar17 + 4;
      iVar23 = iVar23 + 0x80;
      param_1 = param_1 + 0x6c;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  else {
    iVar23 = 8;
    *(uint *)(param_1 + 0x1874) =
         -(uVar18 & 0xa10000) >> 0x18 & 0x80 | uVar21 | uVar3 | uVar2 | uVar15 & 0xdafff07f;
    do {
      *(undefined2 *)(param_1 + 0x1894) = 0;
      param_1 = param_1 + 2;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
  }
  return;
}

/* FUN_0009cf10 @ 0x9cf10 (224 bytes) */
int FUN_0009cf10(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((*(uint *)(param_1 + 0x44) & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    uVar3 = 2;
    if ((sVar1 != 0x801) && (uVar3 = 3, sVar1 != 0x2601)) {
      uVar3 = (uint)(sVar1 == 0x800);
    }
    *(uint *)(param_1 + 0x1874) =
         (uint)(*(short *)(((unsigned char *)0x00002e06) + iVar2) == -0x7baf) << 4 |
         uVar3 << 5 | *(uint *)(param_1 + 0x1874) & 0xffffff8f;
    sVar1 = *(short *)(((unsigned char *)0x00002e08) + iVar2);
    if (sVar1 == -0x7aa5) {
      uVar3 = 2;
    }
    else if (sVar1 == -0x7aa4) {
      uVar3 = 0;
    }
    else if (sVar1 == 0x2502) {
      uVar3 = 1;
    }
    *(uint *)(param_1 + 0x1878) = uVar3 << 0x12 | *(uint *)(param_1 + 0x1878) & 0xfff3ffff;
    return;
  }
  *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffff8f;
  *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xfff3ffff;
  return;
}

/* FUN_0009cff0 @ 0x9cff0 (132 bytes) */
int FUN_0009cff0(param_1)
  int param_1;
{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((unsigned char *)0x00004301)[iVar4] != '\0') && (*(byte *)(param_1 + 0x91) != 0)) {
    uVar3 = *(uint *)(param_1 + 0x1874);
    bVar1 = ((unsigned char *)0x000013a9)[param_1];
    bVar2 = ((unsigned char *)0x000013aa)[param_1];
    *(uint *)(param_1 + 0x1874) = uVar3 | 0x8000000;
    *(uint *)(param_1 + 0x1874) =
         (bVar2 & 1) << 0xf |
         (bVar1 & 1) << 0x10 |
         (*(byte *)(param_1 + 0x91) & 7) << 0x11 |
         (uint)(*(char *)(param_1 + 0x90) == '\x02') << 0x14 |
         (*(uint *)(param_1 + 0x8c) & 0x80000) << 2 |
         ((byte)((unsigned char *)0x00004302)[iVar4] & 1) << 0x16 | uVar3 & 0xff807fff | 0x8000000;
    return;
  }
  *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xf7807fff;
  return;
}

/* FUN_0009d080 @ 0x9d080 (596 bytes) */
int FUN_0009d080(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  *(undefined1 *)(param_1 + 0x128) = 0;
  *(undefined1 *)(param_1 + 0x129) = 0;
  *(undefined1 *)(param_1 + 0x130) = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  if (*(int *)(param_1 + 0x44) < 0) {
    if (*(int *)(param_1 + 0x13c) == 1) {
      uVar4 = *(uint *)(param_1 + 0x26c);
      *(undefined4 *)(param_1 + 0x290) = 2;
      *(uint *)(param_1 + 0x278) = uVar4 >> 4 & 0xf;
      *(uint *)(param_1 + 0x270) = uVar4 & 0xf;
      *(uint *)(param_1 + 0x280) = uVar4 >> 8 & 0xf;
      *(uint *)(param_1 + 0x28c) = uVar4 >> 0x1c;
      *(uint *)(param_1 + 0x288) = uVar4 >> 0xc & 0xf;
      *(uint *)(param_1 + 0x274) = uVar4 >> 0x10 & 0xf;
      *(uint *)(param_1 + 0x27c) = uVar4 >> 0x14 & 0xf;
      *(undefined4 *)(param_1 + 0x294) = 3;
      *(uint *)(param_1 + 0x284) = uVar4 >> 0x18 & 0xf;
    }
    else {
      *(undefined4 *)(param_1 + 0x280) = 2;
      *(undefined4 *)(param_1 + 0x288) = 3;
      *(undefined4 *)(param_1 + 0x290) = 0;
      *(undefined4 *)(param_1 + 0x294) = 1;
      *(undefined4 *)(param_1 + 0x274) = 4;
      *(undefined4 *)(param_1 + 0x27c) = 5;
      *(undefined4 *)(param_1 + 0x270) = 0;
      *(undefined4 *)(param_1 + 0x278) = 1;
      *(undefined4 *)(param_1 + 0x284) = 6;
      *(undefined4 *)(param_1 + 0x28c) = 7;
    }
    fVar3 = FLOAT_001aa0d4;
    uVar4 = *(uint *)(param_1 + 0x88);
    if (uVar4 != 0) {
      bVar1 = false;
      bVar2 = false;
      puVar9 = (uint *)(param_1 + 0x3a8);
      iVar8 = iVar6;
      do {
        if ((uVar4 & 1) != 0) {
          if ((((*puVar9 & 0xc000000) == 0) || (*(short *)("}J3x})+x|B;x}k" + iVar6) != -0x7e06)) ||
             (bVar7 = 1, "}J3x})+x|B;x}k"[iVar6 + 5] == '\0')) {
            bVar7 = 0;
          }
          *(byte *)(param_1 + 0x130) = bVar7 | *(byte *)(param_1 + 0x130);
          bVar10 = *(float *)(iVar8 + 0x24fc) == fVar3;
          bVar1 = (bool)(bVar10 | bVar1);
          bVar2 = (bool)(!bVar10 | bVar2);
        }
        uVar4 = uVar4 >> 1;
        puVar9 = puVar9 + 1;
        iVar8 = iVar8 + 0x80;
      } while (uVar4 != 0);
      goto LAB_0009d228;
    }
  }
  bVar1 = false;
  bVar2 = false;
LAB_0009d228:
  uVar4 = *(uint *)(param_1 + 0x8c) >> 0x1b & 1 | *(uint *)(param_1 + 0x8c) >> 0x1a & 1;
  if ((uVar4 == 0) || (bVar7 = 1, "}J3x})+x|B;x}k"[iVar6 + 5] == '\0')) {
    bVar7 = 0;
  }
  bVar7 = *(byte *)(param_1 + 0x130) | bVar7;
  *(byte *)(param_1 + 0x130) = bVar7;
  *(byte *)(param_1 + 0x129) = bVar2 | bVar7;
  if ((((uVar4 == 0) && (!bVar2)) && (!bVar1)) || (uVar5 = 1, *(char *)(iVar6 + 0x24ad) == '\0')) {
    uVar5 = 0;
  }
  *(undefined1 *)(param_1 + 0x128) = uVar5;
  if ((*(char *)(param_1 + 0x12f) != '\0') || (bVar7 = 1, -1 < *(int *)(param_1 + 0x44))) {
    bVar7 = 0;
  }
  *(byte *)(param_1 + 0x12a) = bVar7 | (byte)uVar4;
  return;
}

