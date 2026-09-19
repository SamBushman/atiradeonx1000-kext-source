#include "decls.h"

/* FUN_00194618 @ 0x194618 (264 bytes) */
int FUN_00194618(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  puVar5 = *(uint **)((uVar1 & *param_1 - 1U) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
      }
      puVar2 = (undefined4 *)*puVar2;
      iVar3 = (*(code *)param_1[3])(*puVar2,param_2);
      if (iVar3 == 0) {
  return puVar2;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}

/* FUN_00194720 @ 0x194720 (276 bytes) */
int FUN_00194720(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
      }
      iVar3 = (*(code *)param_1[3])(*puVar2,param_2);
      if (iVar3 == 0) {
        FUN_00194208(puVar5,uVar4);
        return;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return;
}

/* FUN_00194834 @ 0x194834 (260 bytes) */
int FUN_00194834(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 uVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  puVar5 = *(uint **)((*param_1 - 1U & uVar1) * 4 + param_1[2]);
  if ((puVar5 != (uint *)0x0) && (uVar1 = puVar5[1], uVar1 != 0)) {
    uVar4 = 0;
    do {
      if (uVar4 < *puVar5) {
        if (uVar1 <= uVar4) {
          _memset((void *)(uVar1 * 4 + puVar5[2]),0,(uVar4 - uVar1) * 4 + 4);
          puVar5[1] = uVar4 + 1;
        }
        puVar2 = (undefined4 *)(uVar4 * 4 + puVar5[2]);
      }
      else {
        puVar2 = (undefined4 *)FUN_0019423c(puVar5,uVar4);
      }
      uVar6 = *puVar2;
      iVar3 = (*(code *)param_1[3])(uVar6,param_2);
      if (iVar3 == 0) {
        return uVar6;
      }
      uVar1 = puVar5[1];
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return 0;
}

/* FUN_00194938 @ 0x194938 (348 bytes) */
int FUN_00194938(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = param_1[3];
  if ((int)uVar5 < 0) {
    uVar5 = param_1[1];
    do {
      uVar5 = uVar5 + 1;
      param_1[1] = uVar5;
      if (*(uint *)*param_1 <= uVar5) {
        param_1[4] = 0;
        return;
      }
      puVar4 = *(uint **)(uVar5 * 4 + ((uint *)*param_1)[2]);
      param_1[2] = puVar4;
    } while ((puVar4 == (uint *)0x0) || (uVar1 = puVar4[1], uVar1 == 0));
    uVar5 = uVar1 - 1;
    param_1[3] = uVar1 - 2;
    if (uVar5 < *puVar4) {
      uVar3 = puVar4[1];
      if (uVar3 <= uVar5) {
        _memset((void *)(uVar3 * 4 + puVar4[2]),0,(uVar5 - uVar3) * 4 + 4);
        puVar4[1] = uVar1;
      }
      puVar2 = (undefined4 *)(uVar5 * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)FUN_0019423c(puVar4,uVar5);
    }
  }
  else {
    puVar4 = (uint *)param_1[2];
    param_1[3] = uVar5 - 1;
    if (uVar5 < *puVar4) {
      uVar1 = puVar4[1];
      if (uVar1 <= uVar5) {
        _memset((void *)(uVar1 * 4 + puVar4[2]),0,(uVar5 - uVar1) * 4 + 4);
        puVar4[1] = uVar5 + 1;
      }
      puVar2 = (undefined4 *)(uVar5 * 4 + puVar4[2]);
    }
    else {
      puVar2 = (undefined4 *)FUN_0019423c(puVar4,uVar5);
    }
  }
  param_1[4] = *puVar2;
  return;
}

/* FUN_00194a94 @ 0x194a94 (20 bytes) */
int FUN_00194a94(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  param_1[3] = 0xffffffff;
  param_1[1] = 0xffffffff;
  ((int (*)())FUN_00194938)();
  return;
}

/* FUN_00194aa8 @ 0x194aa8 (608 bytes) */
int FUN_00194aa8(param_1)
  uint *param_1;
{
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar5 = *param_1;
  *param_1 = uVar5 << 1;
  pvVar1 = (void *)FUN_00193e18(param_1[5],uVar5 << 3);
  _memset(pvVar1,0,*param_1 << 2);
  if (0 < (int)uVar5) {
    uVar8 = 0;
    puVar7 = (undefined4 *)((int)pvVar1 + uVar5 * 4);
    iVar6 = 0;
    do {
      puVar13 = *(uint **)(param_1[2] + iVar6);
      if (puVar13 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)FUN_00193e18(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = FUN_00193e18(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)((int)pvVar1 + iVar6) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)FUN_00193e18(uVar17,0x14);
        *puVar2 = uVar17;
        puVar14 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = FUN_00193e18(uVar17,8);
        puVar2[3] = uVar17;
        uVar11 = 0;
        *puVar7 = puVar14;
        uVar10 = puVar13[1];
        puVar9 = *(uint **)((int)pvVar1 + iVar6);
        iVar12 = uVar10 << 2;
        uVar17 = uVar10;
        while( true ) {
          iVar12 = iVar12 + -4;
          uVar16 = uVar17 - 1;
          if (uVar10 == uVar11) break;
          if (uVar16 < *puVar13) {
            uVar3 = puVar13[1];
            if (uVar3 <= uVar16) {
              _memset((void *)(uVar3 * 4 + puVar13[2]),0,(uVar16 - uVar3) * 4 + 4);
              puVar13[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar12 + puVar13[2]);
          }
          else {
            puVar4 = (undefined4 *)FUN_0019423c(puVar13,uVar16);
          }
          uVar15 = *puVar4;
          uVar17 = (*(code *)param_1[4])(uVar15);
          if (uVar8 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar9[1];
            if (uVar17 < *puVar9) {
              _memset((void *)(uVar17 * 4 + puVar9[2]),0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar9[2]);
              puVar9[1] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)FUN_0019423c(puVar9,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar14) {
              _memset((void *)(uVar17 * 4 + puVar2[3]),0,4);
              puVar4 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar4 = (undefined4 *)FUN_0019423c(puVar14,uVar17);
            }
          }
          *puVar4 = uVar15;
          uVar11 = uVar11 + 1;
          uVar17 = uVar16;
        }
      }
      uVar8 = uVar8 + 1;
      iVar6 = iVar6 + 4;
      puVar7 = puVar7 + 1;
    } while (uVar5 != uVar8);
  }
  param_1[2] = (uint)pvVar1;
  return;
}

/* FUN_00194d44 @ 0x194d44 (224 bytes) */
int FUN_00194d44(param_1, param_2)
  uint *param_1;
  undefined4 param_2;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  uVar4 = param_1[2];
  iVar5 = (*param_1 - 1 & uVar1) * 4;
  if (*(int *)(iVar5 + uVar4) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)FUN_00193e18(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = FUN_00193e18(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar5 + uVar4) = puVar2 + 1;
    uVar4 = param_1[2];
  }
  iVar5 = *(int *)(iVar5 + uVar4);
  puVar3 = (undefined4 *)FUN_001942d4(iVar5,0);
  *puVar3 = param_2;
  if (*param_1 < *(uint *)(iVar5 + 4)) {
    ((int (*)())FUN_00194aa8)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_00194e44 @ 0x194e44 (608 bytes) */
int FUN_00194e44(param_1)
  uint *param_1;
{
  void *pvVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  
  uVar6 = *param_1;
  *param_1 = uVar6 << 1;
  pvVar1 = (void *)FUN_00193e18(param_1[5],uVar6 << 3);
  _memset(pvVar1,0,*param_1 << 2);
  if (uVar6 != 0) {
    uVar9 = 0;
    puVar8 = (undefined4 *)((int)pvVar1 + uVar6 * 4);
    iVar7 = 0;
    do {
      puVar14 = *(uint **)(param_1[2] + iVar7);
      if (puVar14 != (uint *)0x0) {
        uVar17 = param_1[5];
        puVar2 = (uint *)FUN_00193e18(uVar17,0x14);
        *puVar2 = uVar17;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[4] = uVar17;
        puVar2[2] = 0;
        uVar17 = FUN_00193e18(uVar17,8);
        puVar2[3] = uVar17;
        *(uint **)((int)pvVar1 + iVar7) = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2 = (uint *)FUN_00193e18(uVar17,0x14);
        *puVar2 = uVar17;
        puVar15 = puVar2 + 1;
        uVar17 = param_1[5];
        puVar2[1] = 2;
        puVar2[2] = 0;
        puVar2[4] = uVar17;
        uVar17 = FUN_00193e18(uVar17,8);
        puVar2[3] = uVar17;
        uVar12 = 0;
        *puVar8 = puVar15;
        uVar11 = puVar14[1];
        puVar10 = *(uint **)((int)pvVar1 + iVar7);
        iVar13 = uVar11 << 2;
        uVar17 = uVar11;
        while( true ) {
          iVar13 = iVar13 + -4;
          uVar16 = uVar17 - 1;
          if (uVar11 == uVar12) break;
          if (uVar16 < *puVar14) {
            uVar3 = puVar14[1];
            if (uVar3 <= uVar16) {
              _memset((void *)(uVar3 * 4 + puVar14[2]),0,(uVar16 - uVar3) * 4 + 4);
              puVar14[1] = uVar17;
            }
            puVar4 = (undefined4 *)(iVar13 + puVar14[2]);
          }
          else {
            puVar4 = (undefined4 *)FUN_0019423c(puVar14,uVar16);
          }
          puVar4 = (undefined4 *)*puVar4;
          uVar17 = (*(code *)param_1[4])(*puVar4);
          if (uVar9 == (uVar17 & *param_1 - 1)) {
            uVar17 = puVar10[1];
            if (uVar17 < *puVar10) {
              _memset((void *)(uVar17 * 4 + puVar10[2]),0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar10[2]);
              puVar10[1] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(puVar10,uVar17);
            }
          }
          else {
            uVar17 = puVar2[2];
            if (uVar17 < *puVar15) {
              _memset((void *)(uVar17 * 4 + puVar2[3]),0,4);
              puVar5 = (undefined4 *)(uVar17 * 4 + puVar2[3]);
              puVar2[2] = uVar17 + 1;
            }
            else {
              puVar5 = (undefined4 *)FUN_0019423c(puVar15,uVar17);
            }
          }
          *puVar5 = puVar4;
          uVar12 = uVar12 + 1;
          uVar17 = uVar16;
        }
      }
      uVar9 = uVar9 + 1;
      iVar7 = iVar7 + 4;
      puVar8 = puVar8 + 1;
    } while (uVar6 != uVar9);
  }
  param_1[2] = (uint)pvVar1;
  return;
}

/* FUN_001950e0 @ 0x1950e0 (472 bytes) */
int FUN_001950e0(param_1, param_2, param_3)
  uint *param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  uVar1 = (*(code *)param_1[4])(param_2);
  uVar5 = param_1[2];
  iVar4 = (uVar1 & *param_1 - 1) * 4;
  if (*(int *)(iVar4 + uVar5) == 0) {
    uVar1 = param_1[5];
    puVar2 = (uint *)FUN_00193e18(uVar1,0x14);
    *puVar2 = uVar1;
    uVar1 = param_1[5];
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar1;
    uVar1 = FUN_00193e18(uVar1,8);
    puVar2[3] = uVar1;
    *(uint **)(iVar4 + uVar5) = puVar2 + 1;
    uVar5 = param_1[2];
  }
  uVar1 = param_1[5];
  puVar6 = *(uint **)(iVar4 + uVar5);
  puVar2 = (uint *)FUN_00193e18(uVar1,0xc);
  *puVar2 = uVar1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  uVar1 = puVar6[1];
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      if (uVar5 < *puVar6) {
        if (uVar1 <= uVar5) {
          _memset((void *)(uVar1 * 4 + puVar6[2]),0,(uVar5 - uVar1) * 4 + 4);
          puVar6[1] = uVar5 + 1;
        }
        puVar3 = (undefined4 *)(uVar5 * 4 + puVar6[2]);
      }
      else {
        puVar3 = (undefined4 *)FUN_0019423c(puVar6,uVar5);
      }
      uVar5 = uVar5 + 1;
      puVar3 = (undefined4 *)*puVar3;
      iVar4 = (*(code *)param_1[3])(*puVar3,param_2);
      if (((iVar4 == 0) && (param_3 == puVar3[1])) && (puVar2 + 1 != (uint *)0x0)) {
        FUN_00193cc0(*puVar2,puVar2);
      }
      uVar1 = puVar6[1];
    } while (uVar5 < uVar1);
  }
  puVar3 = (undefined4 *)FUN_001942d4(puVar6,0);
  *puVar3 = puVar2 + 1;
  if (*param_1 < puVar6[1]) {
    ((int (*)())FUN_00194e44)(param_1);
  }
  param_1[1] = param_1[1] + 1;
  return;
}

/* FUN_001952d8 @ 0x1952d8 (88 bytes) */
int FUN_001952d8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + param_1 * 4);
  iVar3 = param_1;
  if (param_1 != iVar2) {
    do {
      iVar3 = *(int *)(param_2 + iVar2 * 4);
      iVar2 = *(int *)(iVar3 * 4 + param_2);
    } while (iVar3 != iVar2);
    if (param_1 != iVar3) {
      iVar2 = param_1 << 2;
      do {
        iVar1 = *(int *)(param_2 + iVar2);
        iVar2 = iVar1 * 4;
        *(int *)(param_2 + iVar2) = iVar3;
      } while (iVar3 != iVar1);
    }
  }
  *(int *)(param_1 * 4 + param_2) = iVar3;
  return;
}

/* FUN_00195330 @ 0x195330 (12 bytes) */
int FUN_00195330(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 * 4 + param_3) = param_1;
  return;
}

/* FUN_0019533c @ 0x19533c (16 bytes) */
int FUN_0019533c(param_1)
  int param_1;
{
  if (-1 < param_1) {
    return param_1;
  }
  return 3 - param_1;
}

/* FUN_0019534c @ 0x19534c (108 bytes) */
int FUN_0019534c(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (((((param_1 >> 0x18 != 3) || (param_2 >> 0x18 == 0)) &&
       (((param_1 >> 0x10 & 0xff) != 3 || ((param_2 >> 0x10 & 0xff) == 0)))) &&
      (((param_1 >> 8 & 0xff) != 3 || ((param_2 >> 8 & 0xff) == 0)))) &&
     (((param_1 & 0xff) != 3 || ((param_2 & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}

/* FUN_001953b8 @ 0x1953b8 (108 bytes) */
int FUN_001953b8(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (((((2 < param_1 >> 0x18) || (param_2 >> 0x18 == 0)) &&
       ((2 < (param_1 >> 0x10 & 0xff) || ((param_2 >> 0x10 & 0xff) == 0)))) &&
      ((2 < (param_1 >> 8 & 0xff) || ((param_2 >> 8 & 0xff) == 0)))) &&
     ((2 < (param_1 & 0xff) || ((param_2 & 0xff) == 0)))) {
    return 0;
  }
  return 1;
}

/* FUN_00195424 @ 0x195424 (56 bytes) */
int FUN_00195424(param_1)
  uint param_1;
{
  return ((param_1 >> 8 & 0xff) == 0) << 2 |
         ((param_1 >> 0x10 & 0xff) == 0) << 1 | param_1 >> 0x18 == 0;
}

/* FUN_0019545c @ 0x19545c (20 bytes) */
int FUN_0019545c(param_1, param_2)
  uint param_1;
  int param_2;
{
  return param_1 | (uint)(param_2 != 0) * 2;
}

/* FUN_00195474 @ 0x195474 (256 bytes) */
int FUN_00195474(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar2 != 0) {
    param_1[6] = 1;
  }
  iVar2 = param_1[0x18];
  (**(code **)(*param_2 + 0x44))(param_2,param_1[4]);
  param_1[6] = 0;
  if (param_2[0x37] != 0) {
    if (iVar2 == param_1[0x18]) {
      iVar2 = param_2[0x34];
      iVar4 = 0;
      for (uVar3 = 1; uVar3 <= *(uint *)(iVar2 + 4); uVar3 = uVar3 + 1) {
        iVar1 = *(int *)(*(int *)(iVar2 + 8) + iVar4);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0xdc) = 1;
        }
        iVar4 = iVar4 + 4;
      }
    }
    if (param_1[0x23] == 1) {
      (**(code **)(*param_1 + 0x148))(param_1);
    }
  }
  return;
}

/* FUN_001955c0 @ 0x1955c0 (16 bytes) */
int FUN_001955c0(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x104))();
  return;
}

/* FUN_00195650 @ 0x195650 (76 bytes) */
int FUN_00195650(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  param_2 = param_2 * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + param_2) & 2) != 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + param_2 + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + param_2 + 4) * 0x38 + 0xc);
}

/* FUN_0019569c @ 0x19569c (76 bytes) */
int FUN_0019569c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  param_2 = param_2 * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + param_2) & 2) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + param_2 + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + param_2 + 4) * 0x38 + 0xc);
}

/* FUN_0019581c @ 0x19581c (260 bytes) */
int FUN_0019581c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_5 & 0xffffff00 | 4;
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac0);
  if (iVar1 == 0) {
    iVar1 = FUN_000f2d18(uVar2,DAT_001b2abc);
    if (iVar1 == 0) {
      iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab8);
      if (iVar1 == 0) {
        iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab4);
        if (iVar1 == 0) {
          iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac4);
          if (iVar1 != 0) {
            *(undefined4 *)(param_2 * 4 + param_3) = 0x13;
          }
        }
        else {
          *(undefined4 *)(param_2 * 4 + param_3) = 0x12;
        }
      }
      else {
        *(undefined4 *)(param_2 * 4 + param_3) = 0x11;
      }
    }
    else {
      *(undefined4 *)(param_2 * 4 + param_3) = 0x10;
    }
  }
  else {
    *(undefined4 *)(param_2 * 4 + param_3) = 0xf;
  }
  return;
}

/* FUN_0019598c @ 0x19598c (112 bytes) */
int FUN_0019598c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  int iVar1;
  
  iVar1 = FUN_000f2d18(param_6 & 0xffffff00 | 4,DAT_001b2ac4);
  if (iVar1 == 0) {
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x1d;
  }
  else {
    *(int *)(param_2 * 4 + param_3) = param_5 + 0xc;
  }
  return;
}

/* FUN_001959fc @ 0x1959fc (336 bytes) */
int FUN_001959fc(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_6 & 0xffffff00 | 4;
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac0);
  if (iVar1 != 0) {
    *(int *)(param_2 * 4 + param_3) = param_5 << 2;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2abc);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 1;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab8);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 2;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab4);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 3;
    return;
  }
  uVar2 = param_6 >> 0x18;
  if (uVar2 == 1) {
LAB_00195b1c:
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x17;
  }
  else {
    if (uVar2 != 3) {
      if ((uVar2 == 2) || ((param_6 >> 0x10 & 0xff) == 0)) {
        *(int *)(param_2 * 4 + param_3) = param_5 + 0x1a;
        return;
      }
      if ((param_6 >> 8 & 0xff) == 0) goto LAB_00195b1c;
    }
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x1d;
  }
  return;
}

/* FUN_00195cec @ 0x195cec (644 bytes) */
int FUN_00195cec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = (undefined1)param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58)) = 3;
  if (param_2 != -1) goto LAB_00195f08;
  if (param_3 == 0x31) {
LAB_00195e0c:
    uVar3 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) = 0x11;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = 0x10;
    goto LAB_00195f08;
  }
  if (param_3 < 0x32) {
    if (param_3 != 0x13) {
      if (param_3 == 0x25) {
LAB_00195e48:
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar3 = *(undefined1 *)(iVar2 + 0x39);
        *(undefined1 *)(iVar2 + 0x39) = *(undefined1 *)(iVar2 + 0x3a);
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar1 = *(undefined1 *)(iVar2 + 0x3c);
        *(undefined1 *)(iVar4 + 0x3c) = *(undefined1 *)(iVar4 + 0x3d);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x3a) = *(undefined1 *)(iVar2 + 0x3b);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x3d) = *(undefined1 *)(iVar2 + 0x3e);
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = uVar3;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3e) = uVar1;
        if (param_3 == 0x9d) {
          uVar3 = 5;
        }
        else {
          uVar3 = 6;
        }
        goto LAB_00195f08;
      }
      if (param_3 != 0x12) goto LAB_00195d6c;
LAB_00195d94:
      uVar3 = 0;
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x3b) = *(undefined1 *)(iVar2 + 0x3a);
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x3e) = *(undefined1 *)(iVar2 + 0x3d);
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) = 0x11;
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3d) = 0;
      goto LAB_00195f08;
    }
  }
  else if (param_3 != 0x36) {
    if (param_3 < 0x37) {
      if (param_3 == 0x34) goto LAB_00195d94;
    }
    else {
      if (param_3 == 0x66) goto LAB_00195e0c;
      if (param_3 == 0x9d) goto LAB_00195e48;
    }
LAB_00195d6c:
    uVar3 = 0xff;
    goto LAB_00195f08;
  }
  uVar3 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = 0x10;
LAB_00195f08:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x40) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x42) = 1;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 0x58);
  uVar3 = ((int (*)())FUN_0019533c)(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x41) = uVar3;
  return;
}

/* FUN_00196070 @ 0x196070 (320 bytes) */
int FUN_00196070(param_1)
  int *param_1;
{
  void *pvVar1;
  
  if (param_1[0x1d] == 0) {
    pvVar1 = (void *)(param_1[0x16] + param_1[0x18] * 0x48);
    _memcpy((void *)((int)pvVar1 + 0x48),pvVar1,0x48);
    _memset((void *)(param_1[0x18] * 0x48 + param_1[0x16]),0,0x48);
    param_1[0x18] = 2;
    param_1[0x1d] = 1;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x18] = param_1[0x18] + 1;
  return;
}

/* FUN_001961c8 @ 0x1961c8 (296 bytes) */
int FUN_001961c8(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(int *)(param_1[0x17] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x17] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  iVar2 = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x80);
  *(undefined4 *)(param_1[0x17] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  uVar3 = iVar2 + 1;
  uVar1 = *(uint *)(param_1[0x17] + 0x9364);
  if (uVar3 < uVar1) {
    uVar3 = uVar1;
  }
  *(uint *)(param_1[0x17] + 0x9364) = uVar3;
  iVar4 = 0;
  iVar2 = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (iVar2 != 0) {
    iVar4 = iVar2 + -1;
  }
  if (param_1[0x18] == param_1[0x1d] + 1) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar4);
  return;
}

/* FUN_00196370 @ 0x196370 (64 bytes) */
int FUN_00196370(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if ((*(int *)(param_3 + 0x98) == 2) || (*(int *)(param_3 + 0x98) == 0xc)) {
    iVar1 = param_1[0x1e];
    if (param_1[0x1e] < param_2) {
      iVar1 = param_2;
    }
    param_1[0x1e] = iVar1;
  }
                    
                    
  (**(code **)(*param_1 + 0x88))(param_1,param_3);
  return;
}

/* FUN_0019649c @ 0x19649c (128 bytes) */
int FUN_0019649c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_3);
  iVar2 = (**(code **)(*piVar1 + 0x80))();
  if (*(int *)(iVar2 + 0xb4) == DAT_001b2ab0) {
    *(uint *)(*(int *)(param_1 + 0x5c) + 0x936c) =
         1 << (*(uint *)(iVar2 + 0x148) & 0x3f) | *(uint *)(*(int *)(param_1 + 0x5c) + 0x936c);
  }
  return;
}

/* FUN_0019651c @ 0x19651c (640 bytes) */
int FUN_0019651c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = 0;
  uVar9 = 0;
  do {
    iVar2 = FUN_001054ec(param_2,0);
    if (*(char *)(uVar9 + iVar2 + 0x10) == '\x01') {
      uVar6 = uVar6 | 1 << (uVar9 & 0x3f);
    }
    bVar1 = uVar9 != 3;
    uVar9 = uVar9 + 1;
  } while (bVar1);
  iVar2 = *(int *)(param_2 + 0x144);
  if ((iVar2 == 0x16) || (iVar2 == 0x17)) {
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = FUN_0010e40c(iVar2,*(undefined4 *)(param_2 + 0x148));
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
    uVar5 = 1;
  }
  else if (iVar2 == 0x1b) {
    uVar5 = 1;
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = *(undefined4 *)(param_2 + 0x148);
    iVar2 = FUN_000d9f3c(*(undefined4 *)(param_1[3] + 0x398),0);
    if (iVar2 == 0) {
      uVar5 = 3;
    }
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
  }
  else {
    if (iVar2 != 0x23) {
      pcVar7 = *(code **)(*param_1 + 200);
      uVar9 = *(uint *)(param_2 + 0x148);
      iVar2 = param_1[0x26];
      uVar3 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
      (*pcVar7)(param_1,iVar2,uVar9,1,uVar3,(*(uint *)(param_2 + 0x13c) ^ 1) & 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1[0x26],uVar6);
      iVar2 = param_1[3];
      param_1[0x26] = param_1[0x26] + 1;
      if (*(int *)(*(int *)(iVar2 + 0x6c4) + 0x80) < (int)uVar9) {
        *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x80) = uVar9;
        iVar2 = param_1[3];
      }
      *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88) =
           1 << (uVar9 & 0x3f) | *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88);
      iVar2 = param_1[0x25];
      goto LAB_0019675c;
    }
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = *(undefined4 *)(param_2 + 0x148);
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
    uVar5 = 2;
  }
  (*pcVar7)(param_1,iVar8,uVar3,uVar5,uVar4,0);
  (**(code **)(*param_1 + 0xd0))(param_1,param_1[0x25],uVar6);
  iVar2 = param_1[0x25] + 1;
  param_1[0x25] = iVar2;
LAB_0019675c:
  if (iVar2 <= param_1[0x26]) {
    iVar2 = param_1[0x26];
  }
  param_1[0x1d] = iVar2 + -1;
  param_1[0x18] = iVar2;
  return;
}

/* FUN_0019679c @ 0x19679c (188 bytes) */
int FUN_0019679c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_2,param_3);
  if (((((piVar1[0x20] == 0) || (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 == 0)) ||
       ((piVar1[5] & 2U) != 0)) || (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 != 0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0)) {
    return;
  }
  thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  return;
}

/* FUN_00196858 @ 0x196858 (640 bytes) */
int FUN_00196858(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar4;
  int iVar3;
  uint *puVar5;
  int iVar6;
  int in_stack_00000038;
  
  iVar6 = 1;
  bVar1 = in_stack_00000038 == 0;
  puVar5 = (uint *)(param_2 + 0x2e);
  do {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < iVar6) {
      return;
    }
    bVar2 = iVar6 != 1;
    if (bVar2) {
      if (iVar6 == 2) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) =
               (char)*(undefined4 *)(param_4 + 8);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) =
               (char)*(undefined4 *)(param_7 + 8);
        }
      }
      else if ((iVar6 == 3) && (bVar1)) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) =
               (char)*(undefined4 *)(param_4 + 0xc);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) =
               (char)*(undefined4 *)(param_7 + 0xc);
        }
      }
    }
    else {
      if (param_3 != 0) {
        *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2a) =
             (char)*(undefined4 *)(param_4 + 4);
      }
      if (param_6 != 0) {
        *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x39) =
             (char)*(undefined4 *)(param_7 + 4);
      }
    }
    uVar4 = ((int (*)())FUN_0019545c)(*puVar5 & 1,*puVar5 >> 1 & 1);
    if (param_6 != 0) {
      if (bVar1) {
        if (!bVar2) goto LAB_001969d4;
        if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3d) = uVar4
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3e) = uVar4
          ;
        }
      }
      else if (iVar6 == 3) {
LAB_001969d4:
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3c) = uVar4;
      }
    }
    if (param_3 != 0) {
      if (bVar2) {
        if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2e) = uVar4
          ;
        }
        else if ((iVar6 == 3) && (bVar1)) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2f) = uVar4
          ;
        }
      }
      else {
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2d) = uVar4;
      }
    }
    iVar6 = iVar6 + 1;
    puVar5 = puVar5 + 6;
  } while( true );
}

/* FUN_00196ad8 @ 0x196ad8 (644 bytes) */
int FUN_00196ad8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = (undefined1)param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58)) = 3;
  if (param_2 != -1) goto LAB_00196cf4;
  if (param_3 == 0x31) {
LAB_00196bf8:
    uVar3 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) = 0x15;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = 0x14;
    goto LAB_00196cf4;
  }
  if (param_3 < 0x32) {
    if (param_3 != 0x13) {
      if (param_3 == 0x25) {
LAB_00196c34:
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar3 = *(undefined1 *)(iVar2 + 0x2a);
        *(undefined1 *)(iVar2 + 0x2a) = *(undefined1 *)(iVar2 + 0x2b);
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar1 = *(undefined1 *)(iVar2 + 0x2d);
        *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x2b) = *(undefined1 *)(iVar2 + 0x2c);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(iVar2 + 0x2f);
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = uVar3;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2f) = uVar1;
        if (param_3 == 0x9d) {
          uVar3 = 7;
        }
        else {
          uVar3 = 8;
        }
        goto LAB_00196cf4;
      }
      if (param_3 != 0x12) goto LAB_00196b58;
LAB_00196b80:
      uVar3 = 0;
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x2c) = *(undefined1 *)(iVar2 + 0x2b);
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x2f) = *(undefined1 *)(iVar2 + 0x2e);
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) = 0x15;
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2e) = 0;
      goto LAB_00196cf4;
    }
  }
  else if (param_3 != 0x36) {
    if (param_3 < 0x37) {
      if (param_3 == 0x34) goto LAB_00196b80;
    }
    else {
      if (param_3 == 0x66) goto LAB_00196bf8;
      if (param_3 == 0x9d) goto LAB_00196c34;
    }
LAB_00196b58:
    uVar3 = 0xff;
    goto LAB_00196cf4;
  }
  uVar3 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = 0x14;
LAB_00196cf4:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x31) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x33) = 1;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 0x58);
  uVar3 = ((int (*)())FUN_0019533c)(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x32) = uVar3;
  return;
}

/* FUN_00196d5c @ 0x196d5c (96 bytes) */
int FUN_00196d5c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0xac);
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb6a0;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_00196dbc @ 0x196dbc (64 bytes) */
int FUN_00196dbc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  param_1[0x17] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00196dfc @ 0x196dfc (64 bytes) */
int FUN_00196dfc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  param_1[0x17] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00196e3c @ 0x196e3c (84 bytes) */
int FUN_00196e3c(param_1)
  undefined4 *param_1;
{
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  *param_1 = PTR_DAT_001e914c + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_00196e90 @ 0x196e90 (872 bytes) */
int FUN_00196e90(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_28 [3];
  
  iVar2 = *(int *)(param_2[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) || (iVar9 = 1, iVar2 == 0xa1)) {
    iVar2 = FUN_001054ec(param_2,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = FUN_001054ec(param_2,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = FUN_001054ec(param_2,0), *(char *)(iVar2 + 0x12) == '\0')) {
      uVar4 = FUN_00105594(param_2,1);
      iVar2 = FUN_0018d388(param_3,uVar4,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_001054ec(param_2,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      uVar4 = FUN_00105594(param_2,1);
      iVar2 = FUN_0018d388(param_3,uVar4,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar9 <= iVar2; iVar9 = iVar9 + 1) {
      piVar5 = (int *)FUN_00105594(param_2,iVar9);
      iVar6 = (**(code **)(*piVar5 + 0x60))();
      piVar3 = param_2;
      iVar2 = iVar9;
      if (iVar6 != 0) {
        piVar7 = (int *)FUN_00105594(piVar5,1);
        piVar3 = piVar5;
        iVar2 = 1;
        piVar5 = piVar7;
      }
      iVar2 = FUN_001054ec(piVar3,iVar2);
      FUN_000f3398(local_28,*(undefined4 *)(iVar2 + 0x10));
      uVar1 = local_28[0];
      iVar2 = (**(code **)(*piVar5 + 0x5c))(piVar5);
      if (iVar2 == 0) {
        if ((piVar5[0x26] != 0x33) || (piVar5[0x4b] == 3)) {
          if ((uVar1 & 0xffffff00) == 0) {
            if ((uVar1 & 0xff) == 0) goto LAB_001971a8;
            iVar2 = FUN_0018c7f4(param_3,piVar5,1);
          }
          else if ((uVar1 & 0xff) == 0) {
            iVar2 = FUN_0018c7f4(param_3,piVar5,0);
          }
          else {
            iVar2 = FUN_0018c980(param_3,piVar5,piVar5);
          }
joined_r0x00197160:
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
      else {
        if ((uVar1 & 0xffffff00) != 0) {
          iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar5,1);
            iVar2 = FUN_0018d388(param_3,uVar4,0);
          }
          else {
            uVar4 = FUN_00105594(piVar5,1);
            uVar8 = FUN_00105594(piVar5,2);
            iVar2 = FUN_0018cdd8(param_3,uVar4,uVar8,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((uVar1 & 0xff) != 0) {
          iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar5,1);
            iVar2 = FUN_0018d388(param_3,uVar4,1);
          }
          else {
            uVar4 = FUN_00105594(piVar5,1);
            uVar8 = FUN_00105594(piVar5,2);
            iVar2 = FUN_0018cdd8(param_3,uVar4,uVar8,1);
          }
          goto joined_r0x00197160;
        }
      }
LAB_001971a8: ;
    }
  }
  return 1;
}

/* FUN_001971f8 @ 0x1971f8 (1652 bytes) */
int FUN_001971f8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  code *pcVar15;
  int local_88;
  undefined1 auStack_84 [60];
  undefined4 local_48 [2];
  
  piVar14 = *(int **)(param_2 + 8);
  bVar3 = false;
  if (piVar14[2] == 0) {
    return;
  }
  do {
    iVar11 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar11 != 0) {
      FUN_000e1534(param_1[3],5);
    }
    iVar11 = param_1[3];
    if (**(int **)(iVar11 + 0x6c4) == 0) {
      piVar12 = (int *)FUN_000e3b88(param_1[4],param_2,piVar14,&local_88);
      if ((piVar12 == (int *)0x0) || (local_88 == 0)) {
        iVar11 = param_1[3];
      }
      else {
        iVar11 = param_1[3];
        piVar14 = piVar12;
      }
    }
    iVar11 = FUN_00106cf8(piVar14,*(undefined4 *)(iVar11 + 0x6c4));
    piVar12 = piVar14;
    if ((((iVar11 == 0) || (uVar9 = piVar14[5], (uVar9 & 4) != 0)) || ((int)uVar9 < 0)) ||
       ((uVar9 & 0x1000) != 0)) {
      FUN_00189560(auStack_84);
      if (piVar14 == (int *)0x0) {
        bVar5 = false;
      }
      else {
        bVar5 = false;
        piVar10 = piVar14;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            if ((uVar9 & 0x80) != 0) {
              bVar5 = true;
            }
            if ((uVar9 & 0x10000) == 0) {
              ((int (*)())FUN_00196e90)(param_1,piVar10,auStack_84);
              uVar9 = piVar10[5];
            }
          }
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
      }
      FUN_0018c1c8(auStack_84,param_1 + 7);
      if (piVar14 == (int *)0x0) {
LAB_00197808:
        piVar10 = (int *)piVar14[2];
      }
      else {
        bVar2 = false;
        bVar8 = false;
        bVar6 = false;
        bVar7 = false;
        piVar10 = piVar14;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            iVar11 = piVar10[0x47];
            pcVar15 = *(code **)(*param_1 + 0x13c);
            FUN_00105d04(local_48,piVar10);
            (*pcVar15)(param_1,iVar11,local_48[0]);
            if ((piVar10[5] & 0x10000U) == 0) {
              if ((piVar10[5] & 2U) != 0) {
                piVar13 = (int *)FUN_00105594(piVar10,1);
                iVar11 = (**(code **)(*piVar13 + 0x50))();
                if ((iVar11 != 0) &&
                   (iVar11 = FUN_001054ec(piVar10,0), *(int *)(iVar11 + 0x10) == DAT_001b2acc))
                goto LAB_00197784;
              }
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 == 0) {
                if (!bVar2) {
                  bVar2 = true;
                  (**(code **)(*param_1 + 0xc0))(param_1);
                }
                if (param_1[0x23] == 0) {
                  *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x3cc) = 1;
                  param_1[0x23] = 2;
                }
                else if (param_1[0x23] == 1) {
                  param_1[0x23] = 2;
                  (**(code **)(*param_1 + 0x148))(param_1);
                }
                bVar4 = !bVar3;
                if (bVar4) {
                  bVar6 = true;
                  goto LAB_00197624;
                }
                bVar6 = true;
              }
              else {
                iVar11 = param_1[0x23];
                if (iVar11 == 0) {
                  param_1[0x23] = 1;
                  (**(code **)(*param_1 + 0x134))(param_1);
                }
                else {
                  if (iVar11 != 2) {
                    if ((iVar11 != 1) || ((piVar10[5] & 0x1000U) == 0)) goto LAB_0019752c;
                    (**(code **)(*param_1 + 0x148))(param_1);
                  }
                  param_1[0x23] = 1;
                  (**(code **)(*param_1 + 0x134))(param_1);
                  (**(code **)(*param_1 + 0x138))(param_1);
                }
LAB_0019752c:
                bVar3 = false;
                bVar7 = true;
                bVar4 = true;
LAB_00197624:
                if (*(int *)(piVar10[0x22] + 8) == 0xb4) {
                  piVar10[5] = piVar10[5] | 0x1000;
                }
              }
              (**(code **)(*piVar10 + 0x1c))(piVar10,param_1,0,param_1[3]);
              if (bVar4) {
                if ((((piVar10[5] & 0x1000U) != 0) || (param_3 != 0)) || ((piVar10[5] & 2U) != 0)) {
                  (**(code **)(*param_1 + 0x14c))(param_1);
                  iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
                  if (iVar11 == 0) {
                    bVar3 = true;
                    param_3 = 0;
                    goto LAB_001976d0;
                  }
                }
                bVar3 = false;
                param_3 = 0;
              }
LAB_001976d0:
              if (bVar5) {
                (**(code **)(*param_1 + 0x114))(param_1);
              }
              if (param_1[6] != 0) {
                (**(code **)(*param_1 + 0x140))(param_1);
              }
              (**(code **)(*piVar10 + 0x20))(piVar10,param_1,0,param_1[3]);
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 != 0) {
                param_1[0x1a] = param_1[0x1a] + 1;
                (**(code **)(*param_1 + 0x15c))(param_1);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
            else {
              iVar11 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (iVar11 != 0) {
                bVar8 = true;
              }
              iVar11 = (**(code **)(*piVar10 + 0x48))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())FUN_001955c0)(param_1,piVar10,param_1[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x4c))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())FUN_0019651c)(param_1,piVar10,param_1[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x38))(piVar10);
              if ((iVar11 != 0) && (param_1[0x23] == 1)) {
                (**(code **)(*param_1 + 0x148))(param_1);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
LAB_00197784:
            uVar9 = piVar10[5];
          }
LAB_00197788:
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
        if (bVar6) {
          (**(code **)(*param_1 + 0x15c))(param_1);
          param_1[0x19] = param_1[0x19] + 1;
          piVar10 = (int *)piVar14[2];
        }
        else {
          if ((bVar7) || (!bVar8)) goto LAB_00197808;
          (**(code **)(*param_1 + 0x110))(param_1);
          piVar10 = (int *)piVar14[2];
        }
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
      piVar10 = (int *)piVar14[2];
    }
    do {
      piVar14 = piVar10;
      puVar1 = (uint *)(piVar12 + 5);
      if ((int *)piVar14[2] == (int *)0x0) {
        return;
      }
      piVar10 = (int *)piVar14[2];
      piVar12 = piVar14;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_0019786c @ 0x19786c (672 bytes) */
int FUN_0019786c(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 *param_5;
  undefined4 *param_6;
{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  
  *param_3 = 0;
  param_3[1] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  iVar8 = *(int *)(*(int *)(param_4 + 0x88) + 8);
  if (iVar8 == 0x35) {
    FUN_00103d50(param_4 + 0xbc,1,*(uint *)(param_4 + 0xd0) & 1 ^ 1);
    uVar3 = FUN_00112f54(0x34);
    iVar8 = 0x34;
    *(undefined4 *)(param_4 + 0x88) = uVar3;
  }
  uVar7 = *(undefined4 *)(PTR_DAT_001e913c + iVar8 * 0x38 + 0x34);
  uVar3 = ((int (*)())FUN_00195650)(param_1[0x29],iVar8);
  *param_5 = uVar3;
  uVar3 = ((int (*)())FUN_0019569c)(param_1[0x29],iVar8);
  *param_6 = uVar3;
  iVar8 = FUN_001054ec(param_4,0);
  param_1[0x28] = *(int *)(iVar8 + 0x10);
  switch(uVar7) {
  case 0:
    if (*(char *)(param_1 + 0x28) == '\0') {
      cVar2 = *(char *)((int)param_1 + 0xa1);
      cVar6 = *(char *)((int)param_1 + 0xa2);
LAB_001979d4:
      uVar4 = 1;
    }
    else {
      cVar2 = *(char *)((int)param_1 + 0xa1);
      if (cVar2 == '\0') {
        cVar6 = *(char *)((int)param_1 + 0xa2);
        goto LAB_001979d4;
      }
      cVar6 = *(char *)((int)param_1 + 0xa2);
      uVar4 = 0;
      if (cVar6 == '\0') goto LAB_001979d4;
    }
    cVar1 = *(char *)((int)param_1 + 0xa3);
    if (cVar1 == '\0') {
      uVar4 = uVar4 | 2;
    }
    if (*(char *)(param_1 + 0x28) == '\0') {
      uVar5 = 0xff;
    }
    else {
      uVar5 = 0;
    }
    *(undefined1 *)param_2 = uVar5;
    uVar5 = 0xff;
    if (cVar2 != '\0') {
      uVar5 = 0;
    }
    *(undefined1 *)((int)param_2 + 1) = uVar5;
    uVar5 = 0xff;
    if (cVar6 != '\0') {
      uVar5 = 0;
    }
    *(undefined1 *)((int)param_2 + 2) = uVar5;
    uVar5 = 0xff;
    if (cVar1 != '\0') {
      uVar5 = 0;
    }
    goto LAB_00197b18;
  case 1:
    uVar4 = 5;
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      uVar4 = 7;
      *param_6 = 1;
    }
    *(undefined1 *)((int)param_2 + 6) = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    break;
  case 2:
    uVar4 = 1;
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      uVar4 = 3;
      *param_6 = 1;
    }
    *(undefined1 *)((int)param_2 + 2) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
    break;
  case 3:
    uVar4 = 3;
    goto LAB_00197aa4;
  default:
    uVar4 = 0;
    break;
  case 5:
    if (((*(char *)(param_1 + 0x28) == '\0') || (*(char *)((int)param_1 + 0xa1) == '\0')) ||
       (uVar4 = 2, *(char *)((int)param_1 + 0xa2) == '\0')) {
      *param_5 = 10;
      (**(code **)(*param_1 + 0x150))(param_1,10);
      uVar4 = 0xb;
    }
    uVar5 = 0xff;
LAB_00197b18:
    *(undefined1 *)((int)param_3 + 3) = uVar5;
    break;
  case 8:
    uVar4 = 0x13;
LAB_00197aa4:
    *param_6 = 1;
    *(undefined1 *)((int)param_3 + 3) = 0xff;
    *(undefined1 *)((int)param_2 + 2) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
  }
  return uVar4;
}

/* FUN_00197b30 @ 0x197b30 (692 bytes) */
int FUN_00197b30(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  undefined2 uVar4;
  int iVar2;
  int iVar3;
  byte bVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = (int *)FUN_00105594(param_2,1);
  uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  iVar2 = (**(code **)(**(int **)(param_4 + 0x30c) + 0x7c))(*(int **)(param_4 + 0x30c),param_2);
  if (iVar2 == 0) {
    FUN_001054ec(param_2,0);
  }
  *(undefined4 *)(param_1[0x18] * 0x48 + param_1[0x16]) = 2;
  *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xe) = uVar4;
  iVar2 = *(int *)(param_2 + 0x134);
  iVar6 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  if (iVar6 != 0x77) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = (char)iVar2;
    iVar7 = param_1[0x18];
    iVar3 = param_1[0x16];
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),param_2);
    *(undefined2 *)(iVar7 * 0x48 + iVar3 + 0xc) = uVar4;
  }
  else {
    *(undefined2 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0xc) = 0;
    *(undefined4 *)(param_1[0x17] + 0x9370) = 1;
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x19) = 0;
  }
  iVar3 = (**(code **)(*piVar1 + 0x80))(piVar1);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 * 4 + param_1[0x17] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + iVar6 * 0x38 + 0xc);
  }
  bVar5 = 0xc;
  iVar2 = *(int *)(iVar2 * 0xc + *(int *)(*(int *)(param_4 + 0x6c4) + 0x78) + 4);
  if (((iVar2 != 2) && (bVar5 = 8, iVar2 != 3)) && (bVar5 = 0, iVar2 == 1)) {
    bVar5 = 0xe;
  }
  if (iVar6 != 0x77) {
    if (iVar6 - 0x75U < 2) {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5 & 7;
    }
    else {
      *(byte *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = bVar5;
    }
  }
  else {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x16] + 0x1f) = 0;
  }
  piVar1 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar1 + 0x80))();
  if (iVar2 != 0) {
                    
                    
    (**(code **)(*param_1 + 0x154))(param_1,1,param_2,param_4);
    return;
  }
  return;
}

/* FUN_00197de4 @ 0x197de4 (232 bytes) */
int FUN_00197de4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  iVar3 = FUN_00105594(param_5);
  iVar4 = FUN_001054ec(param_5,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + iVar5);
    if (uVar2 < 4) goto LAB_00197e50;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = 0;
LAB_00197e50:
  fVar1 = *(float *)(uVar2 * 0x18 + iVar3 + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x14;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x16;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x15;
  }
  return;
}

/* FUN_00197ecc @ 0x197ecc (232 bytes) */
int FUN_00197ecc(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38 [9];
  
  iVar3 = FUN_00105594(param_5);
  iVar4 = FUN_001054ec(param_5,param_2);
  iVar5 = 0;
  local_38[0] = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = 4;
  do {
    uVar2 = (uint)*(byte *)((int)local_38 + iVar5);
    if (uVar2 < 4) goto LAB_00197f38;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = 0;
LAB_00197f38:
  fVar1 = *(float *)(uVar2 * 0x18 + iVar3 + 0x20);
  if (fVar1 == FLOAT_001aa0d4) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x10;
  }
  else if (fVar1 == FLOAT_001aa10c) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x12;
  }
  else if (fVar1 == FLOAT_001aa0e8) {
    *(undefined4 *)(param_2 * 4 + param_3) = 0x11;
  }
  return;
}

/* FUN_00198084 @ 0x198084 (296 bytes) */
int FUN_00198084(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_4 + 0x98);
  iVar4 = *(int *)(param_4 + 0x94);
  if (iVar6 == 9) {
    iVar1 = iVar4 + 1;
    iVar3 = *(int *)(*(int *)(param_1 + 0x5c) + 0x9374);
    if (iVar1 <= iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(*(int *)(param_1 + 0x5c) + 0x9374) = iVar1;
  }
  uVar5 = (undefined1)iVar4;
  if ((param_2 != 0) && (iVar6 != 8)) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x16) = uVar5;
    iVar3 = *(int *)(param_1 + 0x60);
    iVar4 = *(int *)(param_1 + 0x58);
    iVar1 = FUN_001054ec(param_4,0);
    uVar2 = ((int (*)())FUN_00195424)(*(undefined4 *)(iVar1 + 0x10));
    *(undefined1 *)(iVar3 * 0x48 + iVar4 + 0x15) = uVar2;
  }
  if (param_3 != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x22) = uVar5;
    if (iVar6 == 8) {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x23) = 1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x60);
      iVar4 = *(int *)(param_1 + 0x58);
      iVar6 = FUN_001054ec(param_4,0);
      *(bool *)(iVar1 * 0x48 + iVar4 + 0x21) = *(char *)(iVar6 + 0x13) == '\0';
    }
  }
  return;
}

/* FUN_001981ac @ 0x1981ac (8500 bytes) */
int FUN_001981ac(param_1, param_2)
  int *param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  int *piVar19;
  int iVar20;
  uint uVar21;
  undefined4 uVar22;
  int *piVar23;
  int *piVar24;
  byte in_xer_so;
  int iVar25;
  undefined4 local_f8;
  undefined4 local_f4;
  int local_f0;
  undefined4 local_ec [4];
  undefined4 local_dc [4];
  undefined1 local_cc [16];
  undefined4 local_bc [4];
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_9c;
  undefined4 local_98;
  int local_88;
  uint local_84;
  int *local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  int local_64;
  undefined *local_60;
  undefined1 *local_5c;
  
  uVar10 = ((int (*)())FUN_0019786c)(param_1,&local_9c,&local_ac,param_2,&local_f8,&local_f4);
  local_6c = uVar10 & 1;
  local_70 = uVar10 >> 1 & 1;
  local_68 = *(int *)(param_2[0x22] + 8);
  local_5c = local_cc;
  iVar25 = 4;
  local_78 = uVar10 >> 4 & 1;
  local_74 = uVar10 >> 2 & 1;
  iVar8 = 0;
  do {
    *(undefined4 *)(iVar8 + (int)local_bc) = 0;
    *(undefined4 *)(iVar8 + (int)local_dc) = 0;
    *(undefined4 *)(iVar8 + (int)local_ec) = 0;
    *(undefined4 *)(local_5c + iVar8) = 0;
    iVar8 = iVar8 + 4;
    iVar25 = iVar25 + -1;
  } while (iVar25 != 0);
  iVar8 = (**(code **)(*param_2 + 0x14))(param_2);
  uVar6 = local_6c;
  uVar10 = local_70;
  if (local_68 == 0xb4) {
    iVar8 = 3;
LAB_00198290:
    iVar25 = 1;
    piVar19 = param_2 + 0x26;
    bVar1 = local_6c != 0;
    bVar2 = local_70 != 0;
    local_64 = (uint)(byte)(((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 |
                            (local_78 == 0) << 1 | in_xer_so & 1) << 0x1c;
    local_60 = &DAT_001b81b8;
    do {
      iVar11 = FUN_001054ec(param_2,iVar25);
      iVar11 = *(int *)(iVar11 + 0x10);
      local_f0 = -1;
      piVar12 = (int *)FUN_00105594(param_2,iVar25);
      iVar20 = *(int *)(local_60 + -0x56f8);
      iVar13 = (**(code **)(*piVar12 + 0x60))();
      if (iVar13 == 0) {
        local_7c = 0;
        local_80 = (int *)0x0;
      }
      else {
        local_80 = piVar12;
        iVar11 = FUN_001054ec(piVar12,1);
        uVar17 = *(undefined4 *)(iVar11 + 0x10);
        iVar11 = FUN_001054ec(param_2,iVar25);
        iVar20 = *(int *)(iVar11 + 0x10);
        FUN_000f2bdc(&local_88,uVar17,iVar20);
        iVar11 = local_88;
        piVar12 = (int *)FUN_00105594(local_80,1);
        FUN_00106004(param_2,iVar25,piVar12,0,param_1[3]);
        if (iVar25 == 0) {
          local_7c = 1;
          param_2[0x27] = iVar11;
        }
        else {
          iVar13 = FUN_001054ec(param_2,iVar25);
          *(int *)(iVar13 + 0x10) = iVar11;
          local_7c = 1;
        }
      }
      if (piVar12[0x26] != 0x2c) {
        if (piVar12[0x26] == 0x29) {
          local_f0 = (**(code **)(*param_1 + 0x158))(param_1,param_2,iVar25,param_1[3]);
LAB_0019852c:
          bVar3 = iVar25 == 3;
          bVar5 = (byte)((uint)local_64 >> 0x18);
          if ((bVar3) && (!(bool)(bVar5 >> 5 & 1))) {
            local_ec[2] = 0x11;
          }
          if (bVar1) {
            uVar17 = local_9c;
            if (bVar3) {
              if (!(bool)(bVar5 >> 5 & 1)) goto LAB_00199cdc;
              if (local_74 != 0) {
                uVar17 = local_98;
              }
            }
            iVar15 = ((int (*)())FUN_0019534c)(iVar11,uVar17);
            iVar16 = ((int (*)())FUN_001953b8)(iVar11,uVar17);
            local_bc[iVar25] = 0x14;
            iVar13 = iVar25;
            if (iVar15 == 0) {
              if (iVar16 != 0) {
                uVar21 = 1;
                piVar23 = param_1 + 0xe;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar14[7];
                  iVar15 = uVar21 - 1;
                  if ((piVar12 == piVar24) ||
                     ((((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                           (piVar24[0x20] != 0)) &&
                          ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                           ((piVar24[5] & 2U) == 0)))) &&
                         ((iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0 &&
                          ((piVar12[0x20] != 0 &&
                           (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))))) &&
                        ((piVar12[5] & 2U) == 0)) &&
                       (((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                         ((*(uint *)(piVar14[7] + 0x14) & 0x40) != 0)) &&
                        ((piVar12[5] & 0x40U) != 0)))) &&
                      (*(int *)(piVar14[7] + 0x94) == piVar12[0x25])))) {
                    uVar9 = param_1[0x20];
                    *piVar23 = local_f0;
                    param_1[0x20] = 1 << (uVar21 & 0x3f) | uVar9;
                    goto LAB_00199c88;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  piVar14 = piVar14 + 1;
                  uVar21 = uVar21 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_00199c88:
                pcVar7 = *(code **)(*param_1 + 0xf8);
                goto joined_r0x00199c90;
              }
            }
            else {
              if (iVar16 == 0) {
                uVar21 = 1;
                piVar23 = param_1 + 0x12;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar14[10];
                  iVar15 = uVar21 - 1;
                  if ((piVar12 == piVar24) ||
                     ((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                         ((piVar24[0x20] != 0 &&
                          ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                           ((piVar24[5] & 2U) == 0)))))) &&
                        (iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0)) &&
                       (((piVar12[0x20] != 0 && (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0))
                        && ((piVar12[5] & 2U) == 0)))) &&
                      (((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                        ((*(uint *)(piVar14[10] + 0x14) & 0x40) != 0)) &&
                       (((piVar12[5] & 0x40U) != 0 &&
                        (*(int *)(piVar14[10] + 0x94) == piVar12[0x25])))))))) {
                    uVar9 = param_1[0x21];
                    *piVar23 = local_f0;
                    param_1[0x21] = 1 << (uVar21 & 0x3f) | uVar9;
                    goto LAB_00199b44;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  piVar14 = piVar14 + 1;
                  uVar21 = uVar21 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_00199b44:
                pcVar7 = *(code **)(*param_1 + 0xf4);
              }
              else {
                uVar21 = 1;
                piVar23 = param_1;
                piVar14 = param_1;
                do {
                  piVar24 = (int *)piVar23[7];
                  iVar15 = uVar21 - 1;
                  if (((piVar12 == piVar24) ||
                      ((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                        ((piVar24[0x20] != 0 &&
                         ((((((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                              ((piVar24[5] & 2U) == 0)) &&
                             (iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0)) &&
                            ((piVar12[0x20] != 0 &&
                             (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))) &&
                           ((piVar12[5] & 2U) == 0)) &&
                          ((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                           ((*(uint *)(piVar23[7] + 0x14) & 0x40) != 0)))))))) &&
                       (((piVar12[5] & 0x40U) != 0 && (*(int *)(piVar23[7] + 0x94) == piVar12[0x25])
                        ))))) &&
                     ((piVar24 = (int *)piVar23[10], piVar12 == piVar24 ||
                      ((((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                          (piVar24[0x20] != 0)) &&
                         ((iVar16 = FUN_00126760(piVar24[0x26]), iVar16 != 0 &&
                          ((piVar24[5] & 2U) == 0)))) &&
                        (((iVar16 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar16 == 0 &&
                          ((piVar12[0x20] != 0 &&
                           (iVar16 = FUN_00126760(piVar12[0x26]), iVar16 != 0)))) &&
                         ((piVar12[5] & 2U) == 0)))) &&
                       ((((iVar16 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar16 == 0 &&
                          ((*(uint *)(piVar23[10] + 0x14) & 0x40) != 0)) &&
                         ((piVar12[5] & 0x40U) != 0)) &&
                        (*(int *)(piVar23[10] + 0x94) == piVar12[0x25])))))))) {
                    uVar18 = param_1[0x20];
                    uVar9 = param_1[0x21];
                    uVar21 = 1 << (uVar21 & 0x3f);
                    piVar14[0x12] = local_f0;
                    param_1[0x20] = uVar21 | uVar18;
                    param_1[0x21] = uVar21 | uVar9;
                    piVar14[0xe] = local_f0;
                    goto LAB_001999e8;
                  }
                  bVar4 = uVar21 != 3;
                  piVar23 = piVar23 + 1;
                  uVar21 = uVar21 + 1;
                  piVar14 = piVar14 + 1;
                } while (bVar4);
                iVar15 = 3;
LAB_001999e8:
                (**(code **)(*param_1 + 0xf4))(param_1,iVar25,local_bc,local_dc,iVar15,iVar11);
                pcVar7 = *(code **)(*param_1 + 0xf8);
joined_r0x00199c90:
                if (bVar3) {
                  if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                    iVar13 = 3;
                  }
                  else {
                    iVar13 = 1;
                  }
                }
              }
              (*pcVar7)(param_1,iVar13,local_bc,local_dc,iVar15,iVar11);
            }
          }
LAB_00199cdc:
          if (bVar2) {
            iVar11 = FUN_001054ec(param_2,iVar25);
            uVar22 = *(undefined4 *)(iVar11 + 0x10);
            uVar17 = local_ac;
            if ((bVar3) && (local_74 != 0)) {
              uVar17 = local_a8;
            }
            iVar11 = ((int (*)())FUN_0019534c)(uVar22,uVar17);
            iVar13 = ((int (*)())FUN_001953b8)(uVar22,uVar17);
            local_ec[iVar25] = 0x10;
            if (iVar11 != 0) {
              uVar21 = 1;
              piVar23 = param_1 + 0x12;
              piVar14 = param_1;
              do {
                piVar24 = (int *)piVar14[10];
                iVar11 = uVar21 - 1;
                if ((piVar12 == piVar24) ||
                   ((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) &&
                     ((piVar24[0x20] != 0 &&
                      ((((iVar15 = FUN_00126760(piVar24[0x26]), iVar15 != 0 &&
                         ((piVar24[5] & 2U) == 0)) &&
                        (iVar15 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar15 == 0)) &&
                       ((piVar12[0x20] != 0 && (iVar15 = FUN_00126760(piVar12[0x26]), iVar15 != 0)))
                       ))))) &&
                    ((((piVar12[5] & 2U) == 0 &&
                      ((iVar15 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar15 == 0 &&
                       ((*(uint *)(piVar14[10] + 0x14) & 0x40) != 0)))) &&
                     (((piVar12[5] & 0x40U) != 0 && (*(int *)(piVar14[10] + 0x94) == piVar12[0x25]))
                     )))))) {
                  uVar9 = param_1[0x21];
                  *piVar23 = local_f0;
                  param_1[0x21] = 1 << (uVar21 & 0x3f) | uVar9;
                  goto LAB_00199e60;
                }
                bVar4 = uVar21 != 3;
                piVar23 = piVar23 + 1;
                piVar14 = piVar14 + 1;
                uVar21 = uVar21 + 1;
              } while (bVar4);
              iVar11 = 3;
LAB_00199e60:
              iVar15 = iVar25;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  iVar15 = 3;
                }
                else {
                  iVar15 = 1;
                }
              }
              (**(code **)(*param_1 + 0xfc))(param_1,iVar15,local_ec,local_5c,iVar11,uVar22);
            }
            if (iVar13 != 0) {
              uVar21 = 1;
              piVar23 = param_1 + 0xe;
              piVar14 = param_1;
              do {
                piVar24 = (int *)piVar14[7];
                iVar11 = uVar21 - 1;
                if ((piVar12 == piVar24) ||
                   (((((piVar24 != (int *)0x0 && (piVar12 != (int *)0x0)) && (piVar24[0x20] != 0))
                     && ((((iVar13 = FUN_00126760(piVar24[0x26]), iVar13 != 0 &&
                           ((piVar24[5] & 2U) == 0)) &&
                          ((iVar13 = (**(code **)(*piVar24 + 0x50))(piVar24), iVar13 == 0 &&
                           ((piVar12[0x20] != 0 &&
                            (iVar13 = FUN_00126760(piVar12[0x26]), iVar13 != 0)))))) &&
                         ((piVar12[5] & 2U) == 0)))) &&
                    ((((iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar13 == 0 &&
                       ((*(uint *)(piVar14[7] + 0x14) & 0x40) != 0)) && ((piVar12[5] & 0x40U) != 0))
                     && (*(int *)(piVar14[7] + 0x94) == piVar12[0x25])))))) {
                  uVar9 = param_1[0x20];
                  *piVar23 = local_f0;
                  param_1[0x20] = 1 << (uVar21 & 0x3f) | uVar9;
                  goto LAB_00199fdc;
                }
                bVar4 = uVar21 != 3;
                piVar23 = piVar23 + 1;
                piVar14 = piVar14 + 1;
                uVar21 = uVar21 + 1;
              } while (bVar4);
              iVar11 = 3;
LAB_00199fdc:
              iVar13 = iVar25;
              if (bVar3) {
                if ((bool)((byte)((uint)local_64 >> 0x1d) & 1)) {
                  iVar13 = 3;
                }
                else {
                  iVar13 = 1;
                }
              }
              (**(code **)(*param_1 + 0x100))(param_1,iVar13,local_ec,local_5c,iVar11,uVar22);
            }
          }
        }
        else {
          if ((((piVar12[0x20] != 0) && (iVar13 = FUN_00126760(), iVar13 != 0)) &&
              ((piVar12[5] & 2U) == 0)) &&
             (iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12), iVar13 == 0)) {
            local_f0 = FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),piVar12);
            iVar13 = (**(code **)(*piVar12 + 0x80))(piVar12);
            if (iVar13 != 0) {
              (**(code **)(*param_1 + 0x154))(param_1,iVar25,param_2,param_1[3]);
            }
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x50))(piVar12);
          if (iVar13 != 0) {
            local_f0 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),piVar12);
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x48))(piVar12);
          if (iVar13 != 0) {
            if (piVar12[0x26] == 0x33) {
              iVar13 = (**(code **)(*param_1 + 0xdc))(param_1,piVar12,&local_f0);
              if (iVar13 == 0) {
                if ((iVar25 != 3) || ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
                  if (bVar1) {
                    (**(code **)(*param_1 + 0xd4))(param_1,iVar25,local_bc,local_dc,param_2);
                  }
                  if (bVar2) {
                    (**(code **)(*param_1 + 0xd8))(param_1,iVar25,local_ec,local_5c,param_2);
                  }
                }
                else {
                  local_ec[2] = 0x11;
                  (**(code **)(*param_1 + 0xd8))(param_1,3,local_ec,local_5c,param_2);
                  local_ec[1] = local_ec[3];
                }
                goto LAB_0019a030;
              }
            }
            else {
              local_f0 = piVar12[0x25];
              ((int (*)())FUN_00196370)(param_1,local_f0,piVar12);
              local_f0 = (**(code **)(*param_1 + 0xe0))(param_1,local_f0);
            }
            goto LAB_0019852c;
          }
          iVar13 = (**(code **)(*piVar12 + 0x5c))(piVar12);
          if (iVar13 == 0) goto LAB_0019852c;
          if ((iVar25 != 3) || ((bool)((byte)((uint)local_64 >> 0x1d) & 1))) {
            if (bVar1) {
              (**(code **)(*param_1 + 0xec))(param_1,iVar25,local_bc,local_dc,iVar11);
            }
            if (bVar2) {
              (**(code **)(*param_1 + 0xf0))(param_1,iVar25,local_ec,local_5c,iVar11);
            }
          }
          else {
            local_ec[2] = 0x11;
            (**(code **)(*param_1 + 0xf0))(param_1,1,local_ec,local_5c,iVar11);
          }
          FUN_000f3398(&local_84,iVar11);
          uVar21 = local_84 & 0xff;
          bVar3 = (local_84 & 0xffffff00) == 0;
          iVar13 = *(int *)(piVar12[0x22] + 8);
          iVar11 = (**(code **)(*piVar12 + 0x14))(piVar12);
          if (!bVar3) {
            param_1[0x20] = iVar11 * 4 - 2U | param_1[0x20];
            (**(code **)(*param_1 + 0xe4))
                      (param_1,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc));
          }
          bVar4 = -1 < (int)-uVar21;
          if (!bVar4) {
            param_1[0x21] = iVar11 * 4 - 2U | param_1[0x21];
            (**(code **)(*param_1 + 0xe8))
                      (param_1,*(undefined4 *)(PTR_DAT_001e913c + iVar13 * 0x38 + 0xc));
          }
          if (iVar11 < 2) {
            if (iVar11 != 1) goto LAB_0019a030;
            piVar14 = (int *)FUN_00105594(piVar12,1);
            if ((((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                ((piVar14[5] & 2U) != 0)) ||
               (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) {
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_001994a8;
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar13 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,1);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,1);
                ((int (*)())FUN_00196370)(param_1,uVar22,uVar17);
                iVar13 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_001994a8:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,1);
              iVar13 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            if (!bVar3) {
              iVar11 = FUN_00105594(piVar12,1);
              if ((((((iVar11 != param_1[7]) && (iVar11 = FUN_00105594(piVar12,1), iVar11 != 0)) &&
                    ((param_1[7] != 0 &&
                     ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))) &&
                   ((piVar14[5] & 2U) == 0)) &&
                  (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                    (piVar14 = (int *)param_1[7], piVar14[0x20] != 0)) &&
                   (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))) &&
                 ((((piVar14[5] & 2U) == 0 &&
                   (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                  ((iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0 &&
                   ((*(uint *)(param_1[7] + 0x14) & 0x40) != 0)))))) {
                FUN_00105594(piVar12,1);
              }
              param_1[0xe] = iVar13;
            }
            if (!bVar4) {
              iVar11 = FUN_00105594(piVar12,1);
              if (((((iVar11 != param_1[10]) && (iVar11 = FUN_00105594(piVar12,1), iVar11 != 0)) &&
                   ((param_1[10] != 0 &&
                    (((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)) &&
                     ((piVar14[5] & 2U) == 0)))))) &&
                  ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                   (piVar14 = (int *)param_1[10], piVar14[0x20] != 0)))) &&
                 ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                  ((((piVar14[5] & 2U) == 0 &&
                    (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                   ((iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0 &&
                    ((*(uint *)(param_1[10] + 0x14) & 0x40) != 0)))))))) {
                FUN_00105594(piVar12,1);
              }
              param_1[0x12] = iVar13;
            }
          }
          else {
            piVar14 = (int *)FUN_00105594(piVar12,1);
            if ((((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                ((piVar14[5] & 2U) != 0)) ||
               (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) {
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_00198950;
              piVar14 = (int *)FUN_00105594(piVar12,1);
              iVar15 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,1);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,1);
                ((int (*)())FUN_00196370)(param_1,uVar22,uVar17);
                iVar15 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_00198950:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,1);
              iVar15 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            piVar14 = (int *)FUN_00105594(piVar12,2);
            if (((piVar14[0x20] == 0) || (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
               (((piVar14[5] & 2U) != 0 ||
                (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)))) {
              piVar14 = (int *)FUN_00105594(piVar12,2);
              iVar11 = (**(code **)(*piVar14 + 0x50))();
              if (iVar11 != 0) goto LAB_00198a1c;
              piVar14 = (int *)FUN_00105594(piVar12,2);
              iVar16 = 0;
              iVar11 = (**(code **)(*piVar14 + 0x48))();
              if (iVar11 != 0) {
                iVar11 = FUN_00105594(piVar12,2);
                uVar22 = *(undefined4 *)(iVar11 + 0x94);
                uVar17 = FUN_00105594(piVar12,2);
                ((int (*)())FUN_00196370)(param_1,uVar22,uVar17);
                iVar16 = (**(code **)(*param_1 + 0xe0))(param_1,uVar22);
              }
            }
            else {
LAB_00198a1c:
              uVar22 = *(undefined4 *)(param_1[3] + 0x6c4);
              uVar17 = FUN_00105594(piVar12,2);
              iVar16 = thunk_FUN_00134de8(uVar22,uVar17);
            }
            if (bVar3) {
LAB_00198f54:
              bVar3 = false;
            }
            else {
              iVar11 = FUN_00105594(piVar12,1);
              if (((iVar11 != param_1[8]) &&
                  (((((iVar11 = FUN_00105594(piVar12,1), iVar11 == 0 || (param_1[8] == 0)) ||
                     ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] == 0 ||
                      (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 ||
                        ((piVar14[5] & 2U) != 0)) ||
                       (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)))))) ||
                    ((piVar14 = (int *)param_1[8], piVar14[0x20] == 0 ||
                     (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)))) ||
                   (((piVar14[5] & 2U) != 0 ||
                    (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                      (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(param_1[8] + 0x14) & 0x40) == 0 ||
                      (iVar11 = FUN_00105594(piVar12,1),
                      *(int *)(iVar11 + 0x94) != *(int *)(param_1[8] + 0x94))))))))))) ||
                 ((iVar11 = FUN_00105594(piVar12,2), iVar11 != param_1[7] &&
                  ((((iVar11 = FUN_00105594(piVar12,2), iVar11 == 0 || (param_1[7] == 0)) ||
                    (piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] == 0)) ||
                   (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 || ((piVar14[5] & 2U) != 0))
                    || ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                          ((piVar14 = (int *)param_1[7], piVar14[0x20] == 0 ||
                           (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)))) ||
                         ((piVar14[5] & 2U) != 0)) ||
                        ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                           (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) == 0
                           )) || ((*(uint *)(param_1[7] + 0x14) & 0x40) == 0)) ||
                         (iVar11 = FUN_00105594(piVar12,2),
                         *(int *)(iVar11 + 0x94) != *(int *)(param_1[7] + 0x94))))))))))))) {
                iVar11 = FUN_00105594(piVar12,1);
                if (((iVar11 == param_1[7]) ||
                    ((((iVar11 = FUN_00105594(piVar12,1), iVar11 != 0 && (param_1[7] != 0)) &&
                      ((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                       ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                        ((piVar14[5] & 2U) == 0)))))) &&
                     (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                       ((((piVar14 = (int *)param_1[7], piVar14[0x20] != 0 &&
                          (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)) &&
                         ((piVar14[5] & 2U) == 0)) &&
                        ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                         (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                        )))) && (((*(uint *)(param_1[7] + 0x14) & 0x40) != 0 &&
                                 (iVar11 = FUN_00105594(piVar12,1),
                                 *(int *)(iVar11 + 0x94) == *(int *)(param_1[7] + 0x94))))))))) &&
                   ((iVar11 = FUN_00105594(piVar12,2), iVar11 == param_1[8] ||
                    (((((iVar11 = FUN_00105594(piVar12,2), iVar11 != 0 && (param_1[8] != 0)) &&
                       ((piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] != 0 &&
                        (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                          ((piVar14[5] & 2U) == 0)) &&
                         (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)))))) &&
                      ((piVar14 = (int *)param_1[8], piVar14[0x20] != 0 &&
                       (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))) &&
                     (((piVar14[5] & 2U) == 0 &&
                      (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                        (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                       && (((*(uint *)(param_1[8] + 0x14) & 0x40) != 0 &&
                           (iVar11 = FUN_00105594(piVar12,2),
                           *(int *)(iVar11 + 0x94) == *(int *)(param_1[8] + 0x94))))))))))))) {
                  param_1[0xe] = iVar15;
                  param_1[0xf] = iVar16;
                  if ((iVar13 == 0x9a) && (bVar3 = true, (piVar19[8] & 2U) == 0)) goto LAB_00198f58;
                }
                goto LAB_00198f54;
              }
              bVar3 = false;
              param_1[0xf] = iVar15;
              param_1[0xe] = iVar16;
            }
LAB_00198f58:
            if (bVar4) {
LAB_0019941c:
              bVar4 = false;
            }
            else {
              iVar11 = FUN_00105594(piVar12,1);
              if (((iVar11 != param_1[0xb]) &&
                  (((((((iVar11 = FUN_00105594(piVar12,1), iVar11 == 0 || (param_1[0xb] == 0)) ||
                       (piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] == 0)) ||
                      ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 ||
                       ((piVar14[5] & 2U) != 0)))) ||
                     (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0)) ||
                    (((piVar14 = (int *)param_1[0xb], piVar14[0x20] == 0 ||
                      (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                     (((piVar14[5] & 2U) != 0 ||
                      (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                        (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) == 0))
                       || ((*(uint *)(param_1[0xb] + 0x14) & 0x40) == 0)))))))) ||
                   (iVar11 = FUN_00105594(piVar12,1),
                   *(int *)(iVar11 + 0x94) != *(int *)(param_1[0xb] + 0x94))))) ||
                 ((iVar11 = FUN_00105594(piVar12,2), iVar11 != param_1[10] &&
                  ((((iVar11 = FUN_00105594(piVar12,2), iVar11 == 0 || (param_1[10] == 0)) ||
                    ((piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] == 0 ||
                     ((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0 || ((piVar14[5] & 2U) != 0)
                      ))))) ||
                   (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                     (((piVar14 = (int *)param_1[10], piVar14[0x20] == 0 ||
                       (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 == 0)) ||
                      ((piVar14[5] & 2U) != 0)))) ||
                    (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 != 0 ||
                      (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) == 0)) ||
                     (((*(uint *)(param_1[10] + 0x14) & 0x40) == 0 ||
                      (iVar11 = FUN_00105594(piVar12,2),
                      *(int *)(iVar11 + 0x94) != *(int *)(param_1[10] + 0x94))))))))))))) {
                iVar11 = FUN_00105594(piVar12,1);
                if (((iVar11 == param_1[10]) ||
                    ((((iVar11 = FUN_00105594(piVar12,1), iVar11 != 0 && (param_1[10] != 0)) &&
                      (((piVar14 = (int *)FUN_00105594(piVar12,1), piVar14[0x20] != 0 &&
                        ((((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                           ((piVar14[5] & 2U) == 0)) &&
                          (iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0)) &&
                         ((piVar14 = (int *)param_1[10], piVar14[0x20] != 0 &&
                          (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))) &&
                       ((piVar14[5] & 2U) == 0)))) &&
                     (((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                       (iVar11 = FUN_00105594(piVar12,1), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                      && (((*(uint *)(param_1[10] + 0x14) & 0x40) != 0 &&
                          (iVar11 = FUN_00105594(piVar12,1),
                          *(int *)(iVar11 + 0x94) == *(int *)(param_1[10] + 0x94))))))))) &&
                   ((iVar11 = FUN_00105594(piVar12,2), iVar11 == param_1[0xb] ||
                    (((((iVar11 = FUN_00105594(piVar12,2), iVar11 != 0 && (param_1[0xb] != 0)) &&
                       (piVar14 = (int *)FUN_00105594(piVar12,2), piVar14[0x20] != 0)) &&
                      (((iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0 &&
                        ((piVar14[5] & 2U) == 0)) &&
                       ((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                        ((piVar14 = (int *)param_1[0xb], piVar14[0x20] != 0 &&
                         (iVar11 = FUN_00126760(piVar14[0x26]), iVar11 != 0)))))))) &&
                     (((piVar14[5] & 2U) == 0 &&
                      ((((iVar11 = (**(code **)(*piVar14 + 0x50))(piVar14), iVar11 == 0 &&
                         (iVar11 = FUN_00105594(piVar12,2), (*(uint *)(iVar11 + 0x14) & 0x40) != 0))
                        && ((*(uint *)(param_1[0xb] + 0x14) & 0x40) != 0)) &&
                       (iVar11 = FUN_00105594(piVar12,2),
                       *(int *)(iVar11 + 0x94) == *(int *)(param_1[0xb] + 0x94))))))))))) {
                  param_1[0x12] = iVar15;
                  param_1[0x13] = iVar16;
                  if ((iVar13 == 0x9a) && (bVar4 = true, (piVar19[8] & 2U) == 0)) goto LAB_00199420;
                }
                goto LAB_0019941c;
              }
              bVar4 = false;
              param_1[0x13] = iVar15;
              param_1[0x12] = iVar16;
            }
LAB_00199420:
            if ((bVar3) || (bVar4)) {
              FUN_00103d50(piVar19 + 3,1,piVar19[8] & 1U ^ 1);
            }
          }
        }
LAB_0019a030:
        if (local_7c != 0) {
          if (bVar2) {
            (**(code **)(*param_1 + 0x10c))(param_1,iVar25,local_5c,local_80,iVar20);
          }
          if (bVar1) {
            (**(code **)(*param_1 + 0x108))(param_1,iVar25,local_dc,local_80,iVar20);
          }
          FUN_00106004(param_2,iVar25,local_80,0,param_1[3]);
          if (iVar25 == 0) {
            param_2[0x27] = iVar20;
          }
          else {
            iVar11 = FUN_001054ec(param_2,iVar25);
            *(int *)(iVar11 + 0x10) = iVar20;
          }
        }
      }
      iVar25 = iVar25 + 1;
      piVar19 = piVar19 + 6;
    } while (iVar25 <= iVar8);
  }
  else if (0 < iVar8) goto LAB_00198290;
  (**(code **)(*param_1 + 0x118))(param_1,param_1[0x20],param_1 + 0xd,param_1[0x21],param_1 + 0x11);
  (**(code **)(*param_1 + 0x11c))
            (param_1,param_2,local_6c,local_bc,local_dc,local_70,local_ec,local_5c);
  if (param_2[0x26] == 0x2c) {
LAB_0019a1f4:
    pcVar7 = *(code **)(*param_1 + 0x124);
  }
  else {
    if ((((param_2[0x20] != 0) && (iVar8 = FUN_00126760(), iVar8 != 0)) &&
        (((param_2[5] & 2U) == 0 && (iVar8 = (**(code **)(*param_2 + 0x50))(param_2), iVar8 == 0))))
       || (iVar8 = (**(code **)(*param_2 + 0x50))(param_2), iVar8 != 0)) {
      pcVar7 = *(code **)(*param_1 + 0x120);
      uVar17 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
      (*pcVar7)(param_1,local_6c,local_70,param_2,uVar17);
      goto LAB_0019a230;
    }
    if ((param_2[5] & 2U) != 0) goto LAB_0019a1f4;
    if ((param_2[5] & 0x80000U) == 0) goto LAB_0019a230;
    pcVar7 = *(code **)(*param_1 + 0x128);
  }
  (*pcVar7)(param_1,local_6c,local_70,param_2);
LAB_0019a230:
  if (uVar6 != 0) {
    (**(code **)(*param_1 + 300))(param_1,local_f8,local_68,param_2);
  }
  if (uVar10 != 0) {
    (**(code **)(*param_1 + 0x130))(param_1,local_f4,local_68,param_2);
  }
  return;
}

/* FUN_0019a2e0 @ 0x19a2e0 (16 bytes) */
int FUN_0019a2e0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < param_1) {
    return param_1;
  }
  return param_2;
}

/* FUN_0019a368 @ 0x19a368 (28 bytes) */
int FUN_0019a368(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44) + 3) = 0;
  return;
}

/* FUN_0019a384 @ 0x19a384 (56 bytes) */
int FUN_0019a384(param_1)
  int param_1;
{
  ((int (*)())FUN_0019a368)();
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_0019a3bc @ 0x19a3bc (172 bytes) */
int FUN_0019a3bc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x58),
               *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x58));
  FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x78);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (*(int *)(param_1 + 0x74) * 100) / iVar1;
    }
    FUN_000e0e0c(*(undefined4 *)(param_1 + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",iVar1,
                 *(int *)(param_1 + 0x74),iVar2);
    return;
  }
  return;
}

/* FUN_0019a538 @ 0x19a538 (48 bytes) */
int FUN_0019a538(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(uint *)(PTR_DAT_001e9140 + *(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38) >> 2 & 1;
}

/* FUN_0019a568 @ 0x19a568 (176 bytes) */
int FUN_0019a568(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_2 * 5 + *(int *)(param_1 + 0x1c)) * 4;
  iVar1 = *(int *)(&DAT_001e6668 + iVar2);
  iVar2 = *(int *)(&DAT_001e66cc + iVar2);
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
  }
  else if (iVar2 < 1) {
    if (iVar2 < 0) {
      iVar2 = -iVar2;
      iVar1 = *(int *)(param_1 + 0x58);
      do {
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(param_1 + 0x58) = iVar1;
    }
  }
  else {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 1;
      ((int (*)())FUN_0019a384)(param_1);
    } while (iVar1 != iVar2);
  }
  return;
}

/* FUN_0019a618 @ 0x19a618 (120 bytes) */
int FUN_0019a618(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  FUN_000e0e0c(*(int *)(param_1 + 0xc),"next_sp = %d, max = %d\n",*(undefined4 *)(param_1 + 0x58),
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40));
  if ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) < *(int *)(param_1 + 0x58)) ||
     (uVar1 = 0, 0x10 < *(int *)(param_1 + 0x5c))) {
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0019a6a0 @ 0x19a6a0 (80 bytes) */
int FUN_0019a6a0(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000e2c78(param_2,param_1,param_1[3]);
                    
                    
  (**(code **)(*param_1 + 0x88))(param_1,param_2);
  return;
}

/* FUN_0019a6f0 @ 0x19a6f0 (192 bytes) */
int FUN_0019a6f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  float fVar1;
  
  *param_3 = 0;
  if (3 < param_2) {
    if (param_2 < 6) {
      return 4;
    }
    if (param_2 == 6) {
      return 5;
    }
  }
  fVar1 = *(float *)(param_2 * 0x18 + param_1 + 0x20);
  if (fVar1 == FLOAT_001aa0e8) {
    return 5;
  }
  if ((fVar1 != FLOAT_001aa0d4) && (fVar1 == FLOAT_001aa114)) {
    *param_3 = 1;
    return 5;
  }
  return 4;
}

/* FUN_0019a7b0 @ 0x19a7b0 (92 bytes) */
int FUN_0019a7b0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  if (((param_2 != 2) && (puVar2 = (undefined4 *)(param_1 + 0xc), param_2 != 3)) &&
     (puVar2 = (undefined4 *)0x0, param_2 == 1)) {
    puVar2 = (undefined4 *)(param_1 + 4);
  }
  puVar1 = (undefined4 *)(param_1 + 8);
  if (((param_3 != 2) && (puVar1 = (undefined4 *)(param_1 + 0xc), param_3 != 3)) &&
     (puVar1 = (undefined4 *)0x0, param_3 == 1)) {
    puVar1 = (undefined4 *)(param_1 + 4);
  }
  *puVar1 = *puVar2;
  return;
}

/* FUN_0019a80c @ 0x19a80c (156 bytes) */
int FUN_0019a80c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_2,1);
  iVar2 = (**(code **)(*piVar1 + 0x50))();
  if ((iVar2 != 0) && (*(int *)(param_2 + 0x144) != 0)) {
    return;
  }
                    
                    
  (**(code **)(*param_1 + 0x38))(param_1,param_2,param_3,param_4);
  return;
}

/* FUN_0019a8d4 @ 0x19a8d4 (128 bytes) */
int FUN_0019a8d4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60)) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 8) =
         *(undefined4 *)(param_1 + 0x1c);
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a954 @ 0x19a954 (92 bytes) */
int FUN_0019a954(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(*(int *)(param_1 + 0x70) * 0xc + *(int *)(param_1 + 0x60) + 4) =
         *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019a9b0 @ 0x19a9b0 (44 bytes) */
int FUN_0019a9b0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x58);
  iVar1 = *(int *)(param_1 + 0x5c) * 0x1c + *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  *(undefined4 *)(iVar1 + 0x10) = uVar2;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  return;
}

/* FUN_0019a9dc @ 0x19a9dc (160 bytes) */
int FUN_0019a9dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((1 < *(int *)(param_2 + 0x130)) && (*(int *)(param_1 + 0x5c) != 0x10)) {
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x1c);
    iVar1 = *(int *)(param_2 + 300);
    *(int *)(param_1 + 0x70) = iVar1;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 * 0xc + *(int *)(param_1 + 0x60));
    ((int (*)())FUN_0019a568)(param_1,4);
    iVar1 = *(int *)(param_1 + 0x70) * 0xc;
    ((int (*)())FUN_0019a9b0)(param_1,*(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60)),
                 *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x60) + 4));
    *(undefined4 *)(param_1 + 100) = 1;
  }
  return;
}

/* FUN_0019aa7c @ 0x19aa7c (92 bytes) */
int FUN_0019aa7c(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 100) != 0) {
    ((int (*)())FUN_0019a568)(param_1,3);
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x6c);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  return;
}

