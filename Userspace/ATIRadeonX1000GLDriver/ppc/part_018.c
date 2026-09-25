#include "decls.h"

/* FUN_000c73c0 @ 0xc73c0 (144 bytes) */
int FUN_000c73c0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = 0;
  iVar6 = 8;
  iVar1 = param_1;
  do {
    uVar4 = *(uint *)(iVar1 + 0xc);
    if (uVar4 != 0) {
      uVar2 = 0;
      if ((uVar4 & 1) == 0) {
        do {
          uVar2 = uVar2 + 1;
          uVar5 = 1 << (uVar2 & 0x3f);
        } while ((uVar4 & uVar5) == 0);
        uVar5 = ~uVar5;
      }
      else {
        uVar5 = 0xfffffffe;
      }
      iVar1 = iVar3 * 4 + param_1;
      *(uint *)(iVar1 + 0xc) = uVar5 & *(uint *)(iVar1 + 0xc);
      return uVar2 + iVar3 * 0x20;
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return -1;
}

/* FUN_000c7460 @ 0xc7460 (468 bytes) */
int FUN_000c7460(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  uint *param_3;
  uint param_4;
  undefined4 *param_5;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  
  if ((1 << (param_4 & 0x3f) & *(uint *)(param_1 + 0x70)) == 0) {
    return param_5;
  }
  *param_5 = 0x51;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[2] = 0x40;
  param_5[1] = uVar2 & 0xffff | 0x440000;
  param_5[3] = (*(ushort *)param_2 & 0x3f) << 0x10 | (uint)(ushort)*param_2 | 0x400000;
  if ((*param_2 & 0x400000) == 0) {
    puVar4 = ((unsigned char *)0x00005555);
    goto LAB_000c7584;
  }
  uVar3 = 1;
  uVar2 = *param_3 >> 0x15 & 7;
  if (uVar2 != 1) {
    if (uVar2 < 2) {
      uVar3 = 5;
      if (uVar2 != 0) {
LAB_000c7520:
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 2;
      if (uVar2 != 2) {
        if (uVar2 != 3) goto LAB_000c7520;
        uVar3 = 3;
      }
    }
  }
  puVar4 = (undefined *)(uVar3 << 0xc | uVar3 << 8 | uVar3 << 4 | uVar3);
LAB_000c7584:
  param_5[4] = puVar4;
  param_5[5] = 0x49;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[7] = 0x110;
  param_5[6] = uVar2 & 0xffff | 0x440000;
  uVar2 = *(uint *)(param_1 + 0x184);
  param_5[9] = ((unsigned char *)0x00003333);
  param_5[8] = uVar2 & 0xffff | 0x440000;
  uVar1 = *(ushort *)param_2;
  uVar2 = *param_2;
  param_5[0xb] = 0x2222;
  param_5[10] = (uint)(ushort)uVar2 | (uVar1 & 0x3f) << 0x10 | 0x400000;
  return param_5 + 0xc;
}

/* FUN_000c7650 @ 0xc7650 (680 bytes) */
int FUN_000c7650(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  uint *param_4;
  uint param_5;
  int param_6;
  uint *param_7;
  undefined4 param_8;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  if ((1 << (param_5 & 0x3f) & *(uint *)(param_1 + 0x70)) != 0) {
    *param_7 = 0x5b;
    iVar2 = param_5 * 4;
    uVar7 = *(uint *)(param_1 + 0x180);
    param_7[2] = 0x10;
    param_7[1] = uVar7 & 0xffff | 0x440000;
    uVar5 = 0xd;
    uVar7 = *(uint *)(param_1 + 0x184);
    param_7[4] = 0x2222;
    param_7[3] = uVar7 & 0xffff | 0x440000;
    uVar1 = *(ushort *)param_3;
    uVar7 = *param_3;
    param_7[6] = 0x2222;
    param_7[5] = (uint)(ushort)uVar7 | (uVar1 & 0x3f) << 0x10 | 0x400000;
    switch(*(undefined4 *)(iVar2 + param_1 + 0x138)) {
    case 0x200:
    case 0x202:
    case 0x207:
      uVar5 = 0x1000d;
      break;
    case 0x201:
      uVar5 = 0x5000d;
      break;
    case 0x203:
      uVar5 = 0x4000d;
      break;
    case 0x204:
      uVar5 = 0x3000d;
      break;
    case 0x205:
      uVar5 = 0xd;
      break;
    case 0x206:
      uVar5 = 0x2000d;
    }
    param_7[7] = uVar5;
    if (param_6 == 0) {
      uVar7 = *param_3;
    }
    else {
      uVar7 = *param_3 | 0x400000;
      *param_3 = uVar7;
    }
    param_7[8] = uVar7;
    puVar6 = param_7 + 9;
    if (param_6 != 0) {
      puVar6 = param_7 + 10;
      param_7[9] = *param_4;
    }
    *puVar6 = *(uint *)(param_1 + 0x180) & 0xffff | 0x440000;
    iVar3 = *(int *)(iVar2 + param_1 + 0x138);
    if ((iVar3 == 0x200) || (iVar3 != 0x207)) {
      puVar4 = (undefined *)0x2222;
    }
    else {
      puVar4 = ((unsigned char *)0x00004444);
    }
    puVar6[1] = (uint)puVar4;
    param_7 = puVar6 + 6;
    uVar7 = *param_3;
    puVar6[3] = (uint)((unsigned char *)0x00005555);
    puVar6[2] = (ushort)uVar7 | 0x440000;
    uVar7 = *(uint *)(iVar2 + param_1 + 0xb8);
    puVar6[5] = 0x2222;
    puVar6[4] = uVar7 & 0xffff | 0x410000;
  }
  return param_7;
}

/* FUN_000c7930 @ 0xc7930 (2004 bytes) */
int FUN_000c7930(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(param_2 + 0x22fc) != 0) {
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x47;
        uVar1 = *(uint *)(iVar2 + 0x21e0);
        param_1[2] = 0x115;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        param_7 = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
        param_1[3] = param_7;
        param_1 = param_1 + 4;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar2 = *(int *)(param_2 + 0x22fc);
    if (iVar2 == 2) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[4] = 0x2222;
      param_1[3] = uVar1 & 0xffff | param_7 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x2d;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[9] = 0x101;
      param_1[8] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xb] = 0x8888;
      param_1[10] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0xc;
    }
    else if (iVar2 == 3) {
      *param_1 = 0x49;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[4] = ((unsigned char *)0x00003333);
      param_1[3] = uVar1 & 0xffff | param_7 & 0xffc00000 | 0x10000 | 0x400000;
      uVar4 = 0;
      param_1[5] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[6] = uVar4;
      param_1[7] = 0x49;
      param_1[8] = *(uint *)(param_2 + 0x2300) & 0xffff | 0x40000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xb] = 0x2d;
      uVar1 = uVar1 & 0xffff | 0x40000;
      param_1[10] = uVar1;
      param_1[9] = uVar1;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xd] = 0x101;
      param_1[0xc] = uVar1 & 0xffff | 0x440000;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[0xf] = 0x8888;
      param_1[0xe] = uVar1 & 0xffff | 0x440000;
      param_1 = param_1 + 0x10;
    }
    else if (iVar2 == 1) {
      *param_1 = 0x40;
      uVar1 = *(uint *)(param_2 + 0x2300);
      param_1[2] = 0x101;
      uVar4 = 0;
      param_1[1] = uVar1 & 0xffff | 0x440000;
      param_1[3] = *(uint *)(param_2 + 0x68) & 0xffff | 0x510000;
      if (*(int *)(param_2 + 0x230c) == 0) {
        uVar4 = 0x100000;
      }
      param_1[4] = uVar4;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[6] = 0;
      param_1[5] = uVar1 & 0xffff | 0x410000;
      uVar1 = *(uint *)(param_2 + 0x2304);
      param_1[8] = ((unsigned char *)0x00001111);
      param_1[7] = uVar1 & 0xffff | 0x410000;
      param_1 = param_1 + 9;
    }
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x3f;
        uVar1 = *(uint *)(param_2 + 0x21e0);
        param_1[2] = 0x15;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        uVar1 = *(uint *)(param_2 + 0x2300);
        param_1[4] = 0;
        param_1[3] = uVar1 & 0xffff | 0x440000;
        param_1[5] = *(uint *)(param_2 + 0x21e0) & 0xffff | 0x40000;
        param_1[6] = *(uint *)(param_2 + 0x2308) & 0xffff | 0x10000;
        param_1 = param_1 + 7;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    iVar5 = 4;
    iVar2 = param_2;
    do {
      if (*(int *)(iVar2 + 0x21f0) != 0) {
        *param_1 = 0x49;
        uVar1 = *(uint *)(iVar2 + 0x21e0);
        param_1[2] = 0x40;
        param_1[1] = uVar1 & 0xffff | 0x440000;
        param_1[3] = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
        uVar1 = *(uint *)(param_2 + 0x21dc);
        param_1[5] = 0;
        param_1[4] = uVar1 & 0xffff | 0x440000;
        param_1 = param_1 + 6;
      }
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar1 = 0;
  iVar5 = 4;
  iVar2 = param_2;
  do {
    if (*(int *)(iVar2 + 0x21f0) != 0) {
      *param_1 = 0x47;
      param_1[1] = uVar1 & 0xffff | 0x170000;
      param_1[2] = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
      param_1 = param_1 + 3;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (((*(int *)(param_2 + 0x220c) != 0) && (*(int *)(param_2 + 0x2204) != 0)) &&
     (*(int *)(param_2 + 0x2234) == 0)) {
    if (*(int *)(param_2 + 0x2210) == 0xffff) {
      *param_1 = 0x47;
      param_1[1] = 0x530000;
      param_1[2] = 0x40;
    }
    else {
      *param_1 = 0x47;
      uVar1 = *(uint *)(param_2 + 0x2210);
      param_1[2] = 1;
      param_1[1] = uVar1 & 0xffff | 0x510000;
    }
    uVar1 = *(uint *)(param_2 + 0x2208);
    param_1[4] = 0;
    param_1[3] = uVar1 & 0xffff | 0x440000;
    param_1 = param_1 + 5;
  }
  if (((*(int *)(param_2 + 0x2218) != 0) || (*(int *)(param_2 + 0x2220) != 0)) ||
     (puVar3 = param_1, *(int *)(param_2 + 0x2234) == 0)) {
    if ((*(int *)(param_2 + 0x2214) == 0) && (*(int *)(param_2 + 0x221c) != 0)) {
      *param_1 = 0x47;
      param_1[2] = 0x10000;
      param_1[1] = 0x120000;
      param_1 = param_1 + 3;
    }
    puVar3 = param_1;
    if (*(int *)(param_2 + 0x2234) == 0) {
      *param_1 = 0x47;
      param_1[1] = 0xe0000;
      param_1[2] = *(uint *)(param_2 + 0x2200) & 0xffff | 0x40000;
      puVar3 = param_1 + 3;
      if (*(int *)(param_2 + 0x2310) != 0) {
        param_1[3] = 0x47;
        param_1[4] = *(uint *)(param_2 + 0x2314) & 0xffff | 0x110000;
        param_1[5] = *(uint *)(param_2 + 0x2200) & 0xffff | 0x40000;
        puVar3 = param_1 + 6;
      }
    }
  }
  return puVar3;
}

/* FUN_000c8110 @ 0xc8110 (1252 bytes) */
int FUN_000c8110(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x21e0) = uVar3;
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x21e4) = uVar3;
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x21e8) = uVar3;
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x21ec) = uVar3;
  if (*(int *)(param_2 + 0x2324) != 0) {
    uVar3 = FUN_000c73a0(param_2);
    *(undefined4 *)(param_2 + 9000) = uVar3;
  }
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x2200) = uVar3;
  uVar12 = FUN_000c73a0(param_2);
  *(int *)(param_2 + 0x2208) = (int)((ulonglong)uVar12 >> 0x20);
  if (*(int *)(param_2 + 100) != 0) {
    uVar3 = FUN_000c7350(param_2,(int)uVar12,param_3,param_4,param_5,param_6,param_7,param_8);
    *(undefined4 *)(param_2 + 0x68) = uVar3;
  }
  if (*(int *)(param_2 + 0x22fc) != 0) {
    uVar3 = FUN_000c73a0(param_2);
    *(undefined4 *)(param_2 + 0x2300) = uVar3;
    uVar3 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x2304) = uVar3;
    uVar3 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x2308) = uVar3;
    *param_1 = 0x1ff0016;
    param_1[1] = *(uint *)(param_2 + 0x68) & 0xffff | 0x110000;
    param_1 = param_1 + 2;
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    uVar3 = FUN_000c73a0(param_2);
    *(undefined4 *)(param_2 + 0x21dc) = uVar3;
    *param_1 = 0x1ff0016;
    param_1[1] = *(uint *)(param_2 + 0x21d4) & 0xffff | 0x110000;
    param_1[2] = *(int *)(param_2 + 0x21d4) << 0x10 | 0xb000019;
    param_1 = param_1 + 3;
  }
  if (*(int *)(param_2 + 0x4c) != 0) {
    uVar3 = FUN_000c73a0(param_2);
    *(undefined4 *)(param_2 + 0x54) = uVar3;
    uVar3 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x58) = uVar3;
    uVar12 = ((int (*)())FUN_000c73c0)(param_2);
    *(int *)(param_2 + 0x5c) = (int)((ulonglong)uVar12 >> 0x20);
    uVar3 = FUN_000c7350(param_2,(int)uVar12,param_3,param_4,param_5,param_6,param_7,param_8);
    *(undefined4 *)(param_2 + 0x60) = uVar3;
    *param_1 = 0x1ff0016;
    uVar6 = *(uint *)(param_2 + 0x60);
    param_1[2] = 0x51;
    param_1[1] = uVar6 & 0xffff | 0x110000;
    uVar6 = *(uint *)(param_2 + 0x54);
    param_1[4] = 0x40;
    param_1[3] = uVar6 & 0xffff | 0x440000;
    uVar3 = *(undefined4 *)(param_2 + 0x60);
    param_1[6] = 0x49;
    local_58 = CONCAT22(0x11,(short)uVar3);
    param_1[5] = local_58;
    uVar6 = *(uint *)(param_2 + 0x54);
    param_1[8] = 0x15;
    param_1[7] = uVar6 & 0xffff | 0x440000;
    uVar3 = *(undefined4 *)(param_2 + 0x54);
    param_1[10] = (uint)((unsigned char *)0x00003333);
    local_58 = CONCAT22(4,(short)uVar3);
    param_1[9] = local_58 | 0x400000;
    uVar3 = *(undefined4 *)(param_2 + 0x60);
    param_1[0xc] = 0x40;
    local_54 = CONCAT22(0x11,(short)uVar3);
    param_1[0xb] = local_54;
    uVar6 = *(uint *)(param_2 + 0x54);
    param_1[0xe] = 0x15;
    param_1[0xd] = uVar6 & 0xffff | 0x440000;
    local_58 = CONCAT22(4,(short)*(undefined4 *)(param_2 + 0x54));
    param_1[0xf] = local_58;
    local_54 = CONCAT22(1,(short)*(undefined4 *)(param_2 + 0x58));
    param_1[0x10] = local_54;
    local_50 = CONCAT22(1,(short)*(undefined4 *)(param_2 + 0x5c));
    param_1[0x11] = local_50;
    param_1 = param_1 + 0x12;
  }
  if (*(int *)(param_2 + 0x2234) != 0) {
    uVar2 = *(uint *)(param_2 + 0x70);
    uVar6 = *(uint *)(param_2 + 0x74);
    uVar7 = 0;
    uVar8 = 0;
    iVar9 = param_2;
    do {
      uVar10 = 1 << (uVar8 & 0x3f);
      if (((uVar2 | uVar6) & uVar10) != 0) {
        uVar3 = ((int (*)())FUN_000c73c0)(param_2);
        *(undefined4 *)(iVar9 + 0xb8) = uVar3;
        if (uVar7 == 0) {
          uVar7 = 1;
        }
      }
      if ((uVar10 & *(uint *)(param_2 + 0x74)) != 0) {
        uVar3 = FUN_000c73a0(param_2);
        *(undefined4 *)(param_2 + 0x184) = uVar3;
        if (uVar7 < 2) {
          uVar7 = 2;
        }
      }
      bVar1 = uVar8 != 0xf;
      iVar9 = iVar9 + 4;
      uVar8 = uVar8 + 1;
    } while (bVar1);
    if (uVar7 != 0) {
      uVar6 = 0;
      iVar9 = param_2;
      do {
        uVar6 = uVar6 + 1;
        uVar3 = FUN_000c73a0(param_2);
        *(undefined4 *)(iVar9 + 0x17c) = uVar3;
        iVar9 = iVar9 + 4;
      } while (uVar6 != uVar7);
    }
  }
  if (*(int *)(param_2 + 0x21d0) != 0) {
    *param_1 = (*(uint *)(param_2 + 0x21d4) & 0x3fff) << 0x10 | 0x5d;
    param_1[1] = *(uint *)(param_2 + 0x21dc) & 0xffff | 0x40000;
    local_58 = CONCAT22(0x11,(short)*(undefined4 *)(param_2 + 0x21d8));
    param_1[2] = local_58;
    param_1 = param_1 + 3;
  }
  iVar5 = 0;
  iVar11 = 0x10;
  iVar9 = param_2;
  do {
    *(int *)(iVar9 + 0x232c) = iVar5;
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar2 = *(uint *)(param_2 + 8);
  puVar4 = (uint *)(param_2 + 0x232c);
  uVar6 = 0;
  iVar9 = 0x10;
  do {
    if ((1 << (uVar6 & 0x3f) & uVar2) == 0) {
      *puVar4 = uVar6;
      puVar4 = puVar4 + 1;
    }
    uVar6 = uVar6 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  return param_1;
}

/* FUN_000c8600 @ 0xc8600 (316 bytes) */
int FUN_000c8600(param_1, param_2, param_3, param_4, param_5)
  uint param_1;
  int param_2;
  int *param_3;
  uint param_4;
  int param_5;
{
  int iVar1;
  
  if ((int)param_1 < *param_3) {
    iVar1 = param_3[1];
  }
  else {
    iVar1 = param_3[1];
    if (iVar1 < (int)param_1) goto LAB_000c8650;
    *param_3 = param_1 + 1;
  }
  if (((int)param_1 <= iVar1) && (*param_3 <= (int)param_1)) {
    param_3[1] = param_1 - 1;
  }
LAB_000c8650:
  if (param_2 == 0x17) {
    param_3[param_1 + 0x87c] = 1;
    if (((((param_4 & 3) != 1) && ((param_4 & 0xc) != 4)) && ((param_4 & 0x30) != 0x10)) &&
       (((param_4 & 0xc0) != 0x40 && (param_5 != 0)))) {
      return;
    }
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x18) {
    param_3[0x88a] = 1;
    param_3[0x889] = 1;
    return;
  }
  if (param_2 == 0x12) {
    param_3[param_1 + 0x885] = 1;
    return;
  }
  if (param_2 == 0x13) {
    param_3[param_1 + 0x887] = 1;
    return;
  }
  if (param_2 != 0x10) {
    if (param_2 != 0x11) {
      return;
    }
    if (param_3[0x8c7] < (int)param_1) {
      param_3[0x8c7] = param_1;
    }
    param_3[2] = 1 << (param_1 & 0x3f) | param_3[2];
    return;
  }
  param_3[0x883] = 1;
  return;
}

/* FUN_000c8760 @ 0xc8760 (104 bytes) */
int FUN_000c8760(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((undefined *)(uVar1 & 0x3f0000) == ((unsigned char *)0x00160000)) {
    *param_1 = uVar1 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_1 + 2) = (short)*(undefined4 *)(param_3 + 0x54);
    uVar1 = *param_1;
  }
  if ((uVar1 & 0x3f0000) != 0xf0000) {
    return;
  }
  *(short *)((int)param_1 + 2) =
       (short)*(undefined4 *)((uint)(ushort)*param_1 * 4 + param_3 + 0x232c);
  return;
}

/* FUN_000c87d0 @ 0xc87d0 (296 bytes) */
int FUN_000c87d0(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = *param_1;
  uVar4 = (uint)(ushort)*param_1;
  uVar3 = uVar1 >> 0x10 & 0x3f;
  iVar2 = (int)uVar4 >> 5;
  if (uVar3 != 1) {
    if (uVar3 == 2) {
      if ((uVar1 & 0x1800000) == 0) {
        iVar2 = iVar2 * 4 + param_3;
        *(uint *)(iVar2 + 0x2c) =
             (-2 << (uVar4 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar4 & 0x1f)) & *(uint *)(iVar2 + 0x2c)
        ;
        uVar1 = *param_1;
        goto LAB_000c88e4;
      }
      iVar5 = 8;
      iVar2 = param_3;
      do {
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        iVar2 = iVar2 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    else {
      if (uVar3 == 3) {
        if (uVar4 != 0) {
          *(undefined4 *)(param_3 + 0x21c8) = 5;
          uVar1 = *param_1;
        }
        goto LAB_000c88e4;
      }
      if (uVar3 != 0x15) goto LAB_000c88e4;
      *(undefined4 *)(param_3 + 0x21c8) = 5;
    }
  }
  else {
    if ((uVar1 & 0x1800000) == 0) {
      iVar5 = iVar2 * 4 + param_3;
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & ~(1 << (uVar4 + iVar2 * -0x20 & 0x3f));
      uVar1 = *param_1;
      goto LAB_000c88e4;
    }
    iVar5 = 8;
    iVar2 = param_3;
    do {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar1 = *param_1;
LAB_000c88e4:
  if ((uVar1 & 0x1800000) == 0) {
    return;
  }
  if (uVar3 == 1) {
    *(undefined4 *)(FUN_0000222c + param_3 + 4) = 1;
    return;
  }
  *(undefined4 *)(param_3 + 0x21c8) = 4;
  return;
}

/* FUN_000c8910 @ 0xc8910 (400 bytes) */
int FUN_000c8910(param_1, param_2, param_3, param_4)
  uint *param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34 [6];
  
  puVar4 = param_1 + 1;
  uVar3 = *param_1;
  if (param_2 != 0) {
    uVar5 = param_1[1];
    puVar4 = param_1 + 2;
    uVar1 = param_4;
    if ((uVar5 & 0x400000) != 0) {
      uVar1 = param_1[2];
      puVar4 = param_1 + 3;
    }
    ((int (*)())FUN_000c8600)(uVar5 & 0xffff,uVar5 >> 0x10 & 0x3f,param_4,uVar1,uVar5 >> 0x16 & 1);
    if (((uVar3 & 0xffff) == 0x48) && ((uVar5 & 0xffff) != 0)) {
      *(undefined4 *)(param_4 + 0x21c8) = 5;
    }
    if ((uVar5 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
      *(undefined4 *)(param_4 + 0x21c8) = 4;
    }
  }
  if (0 < param_3) {
    local_48 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_48 & 0x400000) != 0) {
      local_3c = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if ((local_48 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_48,&local_3c,param_4);
  }
  if (1 < param_3) {
    local_44 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_44 & 0x400000) != 0) {
      local_38 = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if ((local_44 & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_44,&local_38,param_4);
  }
  puVar2 = puVar4;
  if (2 < param_3) {
    local_40 = *puVar4;
    puVar2 = puVar4 + 1;
    if ((local_40 & 0x400000) != 0) {
      local_34[0] = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    if ((local_40 & 0x1800000) != 0) {
      puVar2 = puVar2 + 1;
    }
    ((int (*)())FUN_000c87d0)(&local_40,local_34,param_4);
  }
  return puVar2;
}

/* FUN_000c8aa0 @ 0xc8aa0 (780 bytes) */
int FUN_000c8aa0(param_1, param_2, param_3, param_4, param_5)
  undefined4 *param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44 [8];
  
  puVar6 = (undefined4 *)*param_2;
  puVar5 = (undefined4 *)*param_1;
  puVar4 = puVar5 + 1;
  puVar7 = puVar6 + 1;
  *puVar5 = *puVar6;
  if (param_3 != 0) {
    uVar8 = puVar6[1];
    puVar7 = puVar6 + 2;
    uVar2 = uVar8 & 0x3f0000;
    if (uVar2 == 0x170000) {
      iVar3 = (uVar8 & 0xffff) * 4 + param_5;
      *(undefined4 *)(iVar3 + 0x21f0) = 1;
      uVar8 = *(uint *)(iVar3 + 0x21e0) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0x100000) {
      uVar8 = *(uint *)(param_5 + 0x2208) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
    }
    else if (uVar2 == 0xe0000) {
      if (*(int *)(param_5 + 0x2234) == 0) {
        uVar8 = *(uint *)(param_5 + 0x2200) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xd0000) {
      if ((*(int *)(param_5 + 0x2234) == 0) && (*(int *)(param_5 + 0x2324) != 0)) {
        uVar8 = *(uint *)(param_5 + 9000) & 0xffff | uVar8 & 0xffc00000 | 0x40000;
      }
    }
    else if (uVar2 == 0xf0000) {
      uVar8 = *(uint *)((uVar8 & 0xffff) * 4 + param_5 + 0x232c) & 0xffff | uVar8 & 0xffff0000;
    }
    *(uint *)(param_5 + 0x2318) = uVar8;
    *puVar4 = uVar8;
    puVar4 = puVar5 + 2;
    if ((uVar8 & 0x400000) != 0) {
      uVar2 = *puVar7;
      puVar4 = puVar5 + 3;
      puVar7 = puVar6 + 3;
      puVar5[2] = uVar2;
    }
  }
  if (0 < param_4) {
    local_58 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_58 & 0x400000) != 0) {
      local_4c = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_58,&local_4c,param_5);
    *puVar4 = local_58;
    puVar1 = puVar4 + 1;
    if ((local_58 & 0x400000) != 0) {
      puVar4[1] = local_4c;
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_58 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (1 < param_4) {
    local_54 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_54 & 0x400000) != 0) {
      local_48 = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_54,&local_48,param_5);
    *puVar4 = local_54;
    puVar1 = puVar4 + 1;
    if ((local_54 & 0x400000) != 0) {
      puVar4[1] = local_48;
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_54 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (2 < param_4) {
    local_50 = *puVar7;
    puVar1 = puVar7 + 1;
    if ((local_50 & 0x400000) != 0) {
      local_44[0] = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&local_50,local_44,param_5);
    *puVar4 = local_50;
    puVar1 = puVar4 + 1;
    if ((local_50 & 0x400000) != 0) {
      puVar4[1] = local_44[0];
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if ((local_50 & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  *param_1 = puVar4;
  *param_2 = puVar7;
  return puVar7;
}

/* FUN_000c8de0 @ 0xc8de0 (76 bytes) */
int FUN_000c8de0(param_1, param_2)
  undefined4 *param_1;
  void *param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  
  pvVar2 = _malloc(0x28);
  uVar1 = *param_1;
  *param_1 = pvVar2;
  *(undefined4 *)((int)pvVar2 + 0x24) = uVar1;
  _memcpy(pvVar2,param_2,0x24);
  return;
}

/* FUN_000c8e30 @ 0xc8e30 (28 bytes) */
void FUN_000c8e30(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  int iVar1;
  
  iVar1 = param_2 * 0x10 + param_1;
  *(float *)(iVar1 + 0x98) = (float)fparam_4;
  *(float *)(iVar1 + 0x8c) = (float)fparam_1;
  *(float *)(iVar1 + 0x90) = (float)fparam_2;
  *(float *)(iVar1 + 0x94) = (float)fparam_3;
  return;
}

/* FUN_000c8e50 @ 0xc8e50 (7396 bytes) */
int FUN_000c8e50(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  uint *******param_3;
{
  bool bVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  byte *pbVar5;
  undefined *puVar6;
  uint uVar7;
  void *pvVar8;
  uint *******pppppppuVar9;
  undefined4 uVar10;
  uint ******ppppppuVar11;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  char *pcVar15;
  uint ******ppppppuVar16;
  void *pvVar17;
  undefined4 *puVar18;
  void *pvVar19;
  uint *******pppppppuVar20;
  uint *puVar21;
  uint *******pppppppuVar22;
  uint uVar23;
  uint uVar24;
  char cVar26;
  uint ******ppppppuVar25;
  uint *******pppppppuVar27;
  uint *puVar28;
  undefined4 *puVar29;
  uint ******ppppppuVar30;
  uint ******unaff_r14;
  uint ******unaff_r15;
  uint *puVar31;
  uint unaff_r20;
  uint *******pppppppuVar32;
  uint unaff_r21;
  uint *puVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  int iVar37;
  int iVar38;
  undefined1 *puVar39;
  int iVar40;
  uint *******local_2bb8;
  uint *local_2bb4;
  uint ******local_2bb0;
  uint local_2bac [2];
  uint *******local_2ba4;
  uint local_2ba0 [2];
  uint ******local_2b98;
  uint ******local_2b94;
  uint ******local_2b8c [3];
  undefined1 auStack_2b80 [12];
  uint ******local_2b74;
  uint ******local_2b70;
  uint ******local_2b68;
  uint local_2b64;
  uint local_2b60;
  uint local_2b5c;
  undefined4 local_2b58 [4];
  undefined4 local_2b48;
  undefined4 local_2b44;
  undefined4 local_2b40;
  undefined4 local_2b3c;
  undefined4 local_2b38 [4];
  undefined4 local_2b28;
  undefined4 local_2b24;
  undefined4 local_2b20;
  undefined4 local_2b1c;
  undefined1 auStack_2b18 [76];
  uint *local_2acc;
  int local_2ac8;
  undefined4 local_2ac0 [8];
  undefined4 local_2aa0 [16];
  void *local_2a60;
  undefined1 auStack_2a5c [72];
  undefined4 local_2a14;
  undefined4 local_2a10;
  uint local_2a08;
  uint local_2a04;
  void *local_29fc;
  void *local_29f8;
  uint ******local_2958;
  undefined1 uStack_2954;
  char local_2953 [3];
  byte abStack_2950 [764];
  uint ******local_2654;
  char local_2650 [576];
  undefined4 local_2410;
  uint *local_240c;
  int *local_2408;
  uint ******local_2400;
  uint ******local_23fc;
  uint ******local_23ec;
  uint ******local_23e8;
  undefined4 local_23e4;
  uint local_23e0;
  undefined4 local_23dc [4];
  undefined4 local_23cc;
  undefined4 local_23c8;
  undefined4 local_23c4;
  undefined4 local_23c0;
  undefined4 local_23bc [4];
  undefined4 local_23ac;
  undefined4 local_23a8;
  undefined4 local_23a4;
  undefined4 local_23a0;
  int local_239c;
  uint ******local_2398;
  undefined4 local_2384;
  uint local_2378;
  uint local_2374;
  int aiStack_22f0 [32];
  uint local_2270;
  uint local_2260 [6];
  undefined1 auStack_2248 [8];
  float local_2240 [1024];
  uint local_1240 [8];
  int aiStack_1220 [1024];
  uint *******local_220;
  int local_218;
  int local_1f8 [5];
  uint local_1e4;
  int local_1dc;
  uint local_1d8;
  int local_1d4;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  uint *******local_1b4;
  undefined4 local_1b0 [16];
  undefined4 local_170 [16];
  uint auStack_130 [17];
  int local_ec;
  uint local_d8;
  uint local_d4;
  undefined4 local_cc;
  int local_c8;
  uint local_c4;
  undefined4 local_7c;
  longlong local_78;
  uint ******local_70;
  uint *local_6c;
  uint ******local_60;
  
  iVar40 = 8;
  iVar12 = 0;
  do {
    *(undefined4 *)((int)local_2b38 + iVar12) = 0xffffffff;
    *(undefined4 *)((int)local_2b58 + iVar12) = 0xffffffff;
    iVar12 = iVar12 + 4;
    iVar40 = iVar40 + -1;
  } while (iVar40 != 0);
  pppppppuVar20 = param_3;
  pvVar17 = _malloc(0x400);
  uVar23 = *(uint *)(param_1 + 0x44);
  local_218 = 0;
  if ((uVar23 & 0x2000) == 0) {
    local_1e4 = uVar23 >> 0x18 & 1;
    local_1d8 = 0xffff;
  }
  else {
    local_1e4 = uVar23 >> 0xb & 1;
    if (local_1e4 == 0) {
      local_1d8 = 0xffff;
    }
    else {
      local_1d8 = (uint)(byte)((unsigned char *)0x000011d1)[param_1];
    }
  }
  puVar33 = (uint *)*param_2;
  local_d8 = uVar23 >> 10 & 1;
  iVar40 = 8;
  local_23e4 = 0xffff;
  local_d4 = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
  local_c4 = (uint)(param_2[6] == 0);
  local_23c0 = local_2b1c;
  iVar12 = param_2[1];
  local_23c4 = local_2b20;
  local_23c8 = local_2b24;
  local_1b4 = (uint *******)0x0;
  local_ec = 0;
  local_cc = 0;
  local_7c = 0;
  local_23cc = local_2b28;
  local_23dc[3] = local_2b38[3];
  local_23e8 = (uint ******)0x0;
  local_239c = 0;
  local_2384 = 0;
  local_23dc[2] = local_2b38[2];
  local_23dc[1] = local_2b38[1];
  local_23dc[0] = local_2b38[0];
  local_23a0 = local_2b3c;
  local_2270 = 0;
  local_1b8 = 0;
  local_23e0 = 0;
  local_220 = (uint *******)0x0;
  local_1f8[0] = 0;
  local_23a8 = local_2b44;
  local_23a4 = local_2b40;
  local_1f8[1] = 0;
  local_1f8[2] = 0;
  local_1f8[3] = 0;
  local_1d4 = 0;
  local_23bc[3] = local_2b58[3];
  local_23ac = local_2b48;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1dc = 0;
  local_23bc[1] = local_2b58[1];
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_23bc[2] = local_2b58[2];
  puVar31 = local_2260;
  local_6c = puVar31;
  local_23bc[0] = local_2b58[0];
  do {
    *puVar31 = 0;
    puVar31[0x408] = 0;
    puVar31 = puVar31 + 1;
    iVar40 = iVar40 + -1;
  } while (iVar40 != 0);
  puVar18 = local_1b0;
  iVar40 = 0x10;
  do {
    *puVar18 = 0;
    puVar18[0x10] = 0;
    puVar18 = puVar18 + 1;
    iVar40 = iVar40 + -1;
  } while (iVar40 != 0);
  iVar38 = 0;
  iVar40 = 0;
  uVar23 = 0;
  puVar31 = puVar33;
switchD_000c90cc_caseD_15:
  local_2bb4 = puVar31 + 2;
  puVar28 = local_2bb4;
switchD_000c90cc_caseD_18:
  puVar31 = puVar28;
  if (puVar31 < puVar33 + iVar12) goto code_r0x000c90a4;
  if (local_220 != (uint *******)0x0) {
    puVar31 = (uint *)0x0;
    uVar35 = 0;
    goto LAB_000ca6bc;
  }
  iVar38 = (iVar38 + iVar12) * 4;
  local_2398 = local_23e8;
  if (local_239c != 0) {
    iVar38 = iVar38 + 0x48;
  }
  uVar35 = iVar38 + iVar40 * 4;
  bVar4 = local_218 != 0;
  if (bVar4) {
    uVar35 = uVar35 + 0x14;
  }
  uVar34 = uVar35;
  if ((local_1f8[0] != 0) && (uVar34 = uVar35 + 0xc, bVar4)) {
    uVar34 = uVar35 + 0x24;
  }
  uVar35 = uVar34;
  if ((local_1f8[1] != 0) && (uVar35 = uVar34 + 0xc, bVar4)) {
    uVar35 = uVar34 + 0x24;
  }
  uVar34 = uVar35;
  if ((local_1f8[2] != 0) && (uVar34 = uVar35 + 0xc, bVar4)) {
    uVar34 = uVar35 + 0x24;
  }
  uVar24 = uVar34;
  if ((local_1f8[3] != 0) && (uVar24 = uVar34 + 0xc, bVar4)) {
    uVar24 = uVar34 + 0x24;
  }
  if (((local_1dc != 0) && (local_1e4 != 0)) && (local_1b4 == (uint *******)0x0)) {
    uVar24 = uVar24 + 0x14;
  }
  if (local_ec == 1) {
    uVar24 = uVar24 + 0x24;
  }
  else if (local_ec == 2) {
    uVar24 = uVar24 + 0x30;
  }
  else if (local_ec == 3) {
    uVar24 = uVar24 + 0x40;
  }
  else if (local_ec == 0) goto LAB_000c99d4;
  uVar24 = uVar24 + 8;
  piVar13 = local_1f8;
  iVar40 = 4;
  do {
    if (*piVar13 != 0) {
      uVar24 = uVar24 + 0x2c;
    }
    piVar13 = piVar13 + 1;
    iVar40 = iVar40 + -1;
  } while (iVar40 != 0);
LAB_000c99d4:
  if (((local_1d0 != 0) || (local_1c8 != 0)) || (uVar35 = uVar24, local_1b4 == (uint *******)0x0)) {
    if ((local_1d4 == 0) && (local_1cc != 0)) {
      uVar24 = uVar24 + 0xc;
    }
    uVar35 = uVar24;
    if ((local_1b4 == (uint *******)0x0) && (uVar35 = uVar24 + 0xc, local_d8 != 0)) {
      uVar35 = uVar24 + 0x18;
    }
  }
  bVar4 = true;
  pppppppuVar22 = local_1b4;
  pppppppuVar27 = local_220;
  puVar31 = _malloc(uVar35 + 0x10);
  *puVar31 = *puVar33;
  local_2bb4 = puVar33 + 2;
  puVar31[1] = puVar33[1];
  puVar28 = local_2bb4;
  pppppppuVar32 = (uint *******)(puVar31 + 2);
  goto switchD_000c9ab8_caseD_18;
code_r0x000c90a4:
  pppppppuVar20 = (uint *******)*puVar31;
  puVar28 = puVar31;
  switch((uint)pppppppuVar20 & 0xffff) {
  default:
    goto switchD_000c90cc_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    uVar10 = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    uVar10 = 1;
    goto LAB_000c9340;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_2bb4 = puVar31 + 1;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar10 = 0;
LAB_000c9340:
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 2);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar10,2,&local_23e8);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    local_2bb4 = puVar31 + 2;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    local_2bb4 = puVar31 + 3;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 3);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,3,&local_23e8);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    local_2bb4 = puVar31 + *(ushort *)((int)puVar31 + 6) + 2;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    local_2bb4 = puVar31 + 3;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    local_2bb4 = puVar31 + 1;
    pppppppuVar20 = &local_23e8;
    uVar35 = puVar31[1];
    puVar6 = (undefined *)(uVar35 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar20,0,0);
    if (puVar6 == ((unsigned char *)0x00160000)) {
      local_239c = 1;
    }
    else if (puVar6 == (undefined *)0x110000) {
      local_23e0 = 1 << (uVar35 & 0x3f) | local_23e0;
    }
    else if (puVar6 == (undefined *)0xf0000) {
      uVar23 = uVar23 | 1 << (uVar35 & 0x3f);
    }
    else if (puVar6 == (undefined *)0x100000) {
      local_2384 = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    uVar34 = (uint)pppppppuVar20 >> 0x1b & 3;
    uVar35 = (uint)pppppppuVar20 >> 0x10 & 0xff;
    if ((uVar34 == 2) || ((uVar34 == 0 && (auStack_130[uVar35] == 2)))) {
      local_2270 = 1 << ((uint)pppppppuVar20 >> 0x10 & 0x3f) | local_2270;
    }
    pppppppuVar20 = (uint *******)((uint)pppppppuVar20 >> 0x18 & 7);
    FUN_000c7270(&local_23e8,uVar35,pppppppuVar20);
    local_2bb4 = local_2bb4 + 1;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    local_2bb4 = puVar31 + 1;
    if ((int)pppppppuVar20 < 0) {
      local_2bb4 = puVar31 + 2;
    }
LAB_000c9564:
    local_2bb4 = local_2bb4 + 1;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    local_2bb4 = puVar31 + 1;
    uVar34 = puVar31[1];
    uVar35 = uVar34 >> 0x10 & 0x3f;
    if (uVar35 == 1) {
      pppppppuVar20 = &local_2b68;
      local_2b68 = (uint ******)puVar31[2];
      local_2b64 = puVar31[3];
      local_2b60 = puVar31[4];
      local_2bb4 = puVar31 + 6;
      local_2b5c = puVar31[5];
      FUN_000c7290(&local_23e8,uVar34 & 0xffff,pppppppuVar20);
      puVar28 = local_2bb4;
    }
    else {
      puVar28 = local_2bb4;
      if (uVar35 == 2) {
        pppppppuVar20 = &local_2b68;
        local_2b68 = (uint ******)puVar31[2];
        local_2b64 = puVar31[3];
        local_2b60 = puVar31[4];
        local_2bb4 = puVar31 + 6;
        local_2b5c = puVar31[5];
        FUN_000c72f0(&local_23e8,uVar34 & 0xffff,pppppppuVar20);
        puVar28 = local_2bb4;
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 2);
    iVar38 = iVar38 + 5;
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,2,&local_23e8);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    pppppppuVar20 = &local_23e8;
    local_2bb4 = puVar31 + 2;
    local_2b8c[0] = (uint ******)puVar31[1];
    ((int (*)())FUN_000c87d0)(local_2b8c,auStack_2b80,pppppppuVar20);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar31,0,1,&local_23e8);
    local_1bc = 1;
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    uVar10 = 0;
    break;
  case 0x5d:
    local_2bb4 = puVar31 + 2;
    local_c8 = local_c8 + 1;
    uVar35 = puVar31[1];
    uVar34 = *puVar31;
    if ((((uVar34 & 0xc000000) == 0x4000000) ||
        (((uVar34 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar40 = iVar40 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_2374;
      uVar34 = *puVar31;
    }
    if ((int)uVar34 < 0) {
      local_2bb4 = puVar31 + 3;
      uVar34 = *puVar31;
    }
    if ((uVar34 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r21 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    pppppppuVar20 = &local_23e8;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar20,unaff_r21,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_2378) != 0) {
      iVar40 = iVar40 + 4;
    }
    local_2b74 = (uint ******)*local_2bb4;
    puVar31 = local_2bb4 + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2bb0 = (uint ******)local_2bb4[1];
      puVar31 = local_2bb4 + 2;
    }
    local_2bb4 = puVar31;
    ((int (*)())FUN_000c87d0)(&local_2b74,&local_2bb0,pppppppuVar20);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    local_2bb4 = puVar31 + 2;
    local_c8 = local_c8 + 1;
    uVar35 = puVar31[1];
    uVar34 = *puVar31;
    if ((((uVar34 & 0xc000000) == 0x4000000) ||
        (((uVar34 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar40 = iVar40 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_2374;
      uVar34 = *puVar31;
    }
    if ((int)uVar34 < 0) {
      local_2bb4 = puVar31 + 3;
      uVar34 = *puVar31;
    }
    if ((uVar34 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r20 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    pppppppuVar20 = &local_23e8;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar20,unaff_r20,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_2378) != 0) {
      iVar40 = iVar40 + 4;
    }
    local_2bb0 = (uint ******)*local_2bb4;
    puVar31 = local_2bb4 + 1;
    if (((uint)local_2bb0 & 0x400000) != 0) {
      local_2ba4 = (uint *******)local_2bb4[1];
      puVar31 = local_2bb4 + 2;
    }
    local_2bac[0] = *puVar31;
    local_2bb4 = puVar31 + 1;
    if ((local_2bac[0] & 0x400000) != 0) {
      local_2ba0[0] = puVar31[1];
      local_2bb4 = puVar31 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_2bb0,&local_2ba4,pppppppuVar20);
    ((int (*)())FUN_000c87d0)(local_2bac,local_2ba0,pppppppuVar20);
    puVar28 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  }
  pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
  local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar10,1,&local_23e8);
  puVar28 = local_2bb4;
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  local_2bb8 = pppppppuVar32;
  puVar21 = puVar28;
  pppppppuVar32 = local_2bb8;
  if (puVar33 + iVar12 <= puVar21) {
    uVar35 = uVar35 >> 2;
    local_23e0 = uVar23 | local_23e0;
LAB_000ca6bc:
    if (local_220 != (uint *******)0x0) {
      return local_220;
    }
    param_3[0x1587] = (uint ******)0x0;
    iVar12 = 0;
    param_3[0x1589] = (uint ******)0x0;
    param_3[0x1502] = (uint ******)0x0;
    pppppppuVar20 = param_3 + 0x1000;
    puVar39 = auStack_2248;
    pppppppuVar22 = param_3 + 0x1004;
    puVar33 = local_6c;
    do {
      pppppppuVar32 = pppppppuVar22 + 1;
      puVar28 = (uint *)(puVar39 + 8);
      pppppppuVar27 = pppppppuVar20 + 1;
      iVar40 = 0x20;
      uVar23 = 0;
      do {
        if ((1 << (uVar23 & 0x3f) & *puVar33) == 0) {
          *(undefined1 *)pppppppuVar32 = 0;
        }
        else {
          *pppppppuVar27 = (uint ******)*puVar28;
          pppppppuVar27[1] = (uint ******)puVar28[1];
          pppppppuVar27[2] = (uint ******)puVar28[2];
          ppppppuVar11 = (uint ******)puVar28[3];
          *(undefined1 *)(pppppppuVar27 + 4) = 1;
          pppppppuVar27[3] = ppppppuVar11;
          if (param_3[0x1502] < (uint ******)(iVar12 + uVar23)) {
            param_3[0x1502] = (uint ******)(iVar12 + uVar23);
          }
        }
        uVar23 = uVar23 + 1;
        pppppppuVar32 = pppppppuVar32 + 5;
        puVar28 = puVar28 + 4;
        pppppppuVar27 = pppppppuVar27 + 5;
        iVar40 = iVar40 + -1;
      } while (iVar40 != 0);
      bVar4 = iVar12 != 0xe0;
      pppppppuVar22 = pppppppuVar22 + 0xa0;
      puVar39 = puVar39 + 0x200;
      pppppppuVar20 = pppppppuVar20 + 0xa0;
      puVar33 = puVar33 + 1;
      iVar12 = iVar12 + 0x20;
    } while (bVar4);
    if ((int)param_3[0x1587] < (int)param_3[0x1502]) {
      param_3[0x1587] = param_3[0x1502];
    }
    _memset(auStack_2b18,0,0xbc);
    _memset(auStack_2a5c,0,0x674);
    pvVar19 = (void *)(**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x1870));
    local_2ac8 = uVar35 << 2;
    puVar29 = local_23dc;
    puVar18 = local_2ac0;
    iVar12 = 8;
    local_2a60 = pvVar19;
    do {
      uVar10 = *puVar29;
      uVar14 = puVar29[8];
      puVar29 = puVar29 + 1;
      *puVar18 = uVar10;
      puVar18[8] = uVar14;
      puVar18 = puVar18 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    local_2410 = 0x400;
    local_2acc = puVar31;
    local_240c = _malloc(0x40000);
    local_2408 = _malloc(0x40000);
    local_2a10 = 0x40;
    local_29f8 = _malloc(0x900);
    local_2a14 = 0x40;
    local_29fc = _malloc(0x900);
    cVar26 = '\0';
    pcVar15 = local_2953;
    iVar12 = 0x40;
    do {
      *pcVar15 = cVar26;
      pcVar15 = pcVar15 + 0xc;
      cVar26 = cVar26 + '\x01';
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    iVar12 = *(int *)(param_1 + 0x186c);
    if (iVar12 == 0) {
      FUN_000c6ff0(param_1,1);
      iVar12 = *(int *)(param_1 + 0x186c);
    }
    iVar12 = ((int (*)())FUN_000cd1b0)(iVar12,auStack_2b18,auStack_2a5c);
    if (iVar12 != 0) {
      return (uint *******)((int)&MACH_HEADER.magic + 2);
    }
    param_3[0x1000] = local_2400;
    if (local_2400 != (uint ******)0x0) {
      puVar33 = local_240c;
      pppppppuVar20 = param_3;
      if (local_2400 == (uint ******)0x0) {
        local_2400 = (uint ******)0x1;
      }
      do {
        ppppppuVar11 = (uint ******)*puVar33;
        ppppppuVar16 = (uint ******)puVar33[1];
        ppppppuVar25 = (uint ******)puVar33[2];
        ppppppuVar30 = (uint ******)puVar33[3];
        puVar33 = puVar33 + 4;
        *pppppppuVar20 = ppppppuVar11;
        pppppppuVar20[1] = ppppppuVar16;
        pppppppuVar20[2] = ppppppuVar25;
        pppppppuVar20[3] = ppppppuVar30;
        pppppppuVar20 = pppppppuVar20 + 4;
        local_2400 = (uint ******)((int)local_2400 - 1);
      } while (local_2400 != (uint ******)0x0);
    }
    ppppppuVar11 = param_3[0x1502];
    if (ppppppuVar11 < local_23ec) {
      param_3[0x1502] = local_23ec;
      param_3[0x1501] = (uint ******)((int)local_23ec + 1);
      ppppppuVar11 = local_23ec;
    }
    else {
      param_3[0x1501] = (uint ******)((int)ppppppuVar11 + 1);
    }
    if ((uint ******)0xff < ppppppuVar11) {
      param_3[0x1502] = (uint ******)0xff;
    }
    if ((uint ******)0x100 < param_3[0x1501]) {
      param_3[0x1501] = (uint ******)0x100;
    }
    if (local_2a04 == 0) goto LAB_000caa4c;
    uVar35 = 0;
    iVar12 = 0;
    uVar23 = local_2a04;
    do {
      iVar40 = iVar12 + (int)local_29f8;
      if (*(int *)(iVar40 + 8) == 0x16) {
        uVar34 = *(uint *)(iVar40 + 0x10);
        iVar37 = *(int *)(iVar12 + (int)local_29f8);
        iVar38 = ((int)uVar34 >> 5) + (uint)((int)uVar34 < 0 && (uVar34 & 0x1f) != 0);
        if ((1 << (uVar34 + iVar38 * -0x20 & 0x3f) & local_2260[iVar38]) == 0) goto LAB_000caa2c;
        iVar38 = FUN_000c7240(*(undefined4 *)(iVar40 + 4));
        iVar40 = FUN_000c7240(*(undefined4 *)(iVar40 + 0xc));
        local_78 = (longlong)(int)local_2240[uVar34 * 4 + iVar40];
        aiStack_1220[iVar37 * 4 + iVar38] = (int)local_2240[uVar34 * 4 + iVar40];
      }
      else if (*(int *)(iVar40 + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())FUN_000c8de0)(param_3 + 0x1589,iVar40);
        uVar23 = local_2a04;
      }
      uVar35 = uVar35 + 1;
      iVar12 = iVar12 + 0x24;
      if (uVar23 <= uVar35) {
LAB_000caa4c:
        if (local_2a08 != 0) {
          uVar35 = 0;
          iVar12 = 0;
          uVar23 = local_2a08;
          do {
            pvVar8 = local_29fc;
            if (*(int *)((int)local_29fc + iVar12 + 8) == 1) {
              ppppppuVar16 = *(uint *******)(iVar12 + (int)local_29fc);
              iVar40 = FUN_000c7240(*(undefined4 *)((int)local_29fc + iVar12 + 4));
              ppppppuVar11 = *(uint *******)((int)pvVar8 + iVar12 + 0x14);
              *(undefined1 *)(param_3 + (int)(((unsigned char *)0x00001005) + (int)ppppppuVar16 * 5)) = 1;
              param_3[(int)(((unsigned char *)0x00001001) + (int)ppppppuVar16 * 5 + iVar40)] = ppppppuVar11;
              uVar23 = local_2a08;
              if (param_3[0x1502] < ppppppuVar16) {
                param_3[0x1502] = ppppppuVar16;
              }
            }
            uVar35 = uVar35 + 1;
            iVar12 = iVar12 + 0x24;
          } while (uVar35 < uVar23);
        }
        ppppppuVar11 = (uint ******)0x0;
        *(undefined1 *)(param_3 + 0x1507) = 0;
        param_3[0x1506] = (uint ******)0x0;
        param_3[0x151d] = (uint ******)0x0;
        param_3[0x151e] = (uint ******)0x0;
        param_3[0x1503] = local_2958;
        param_3[0x1504] = local_2654;
        param_3[0x1505] = local_23fc;
        param_3[0x1588] = (uint ******)0x0;
        if (local_2654 == (uint ******)0x0) {
          ppppppuVar11 = param_3[0x151d];
        }
        else {
          pcVar15 = local_2650;
          if (local_2654 == (uint ******)0x0) {
            local_2654 = (uint ******)0x1;
          }
          do {
            cVar26 = *pcVar15;
            if (cVar26 == '\x01') {
              ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 0x10000);
              param_3[0x151d] = ppppppuVar11;
            }
            else if (cVar26 == '\0') {
              ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 1);
              *(undefined1 *)(param_3 + 0x1507) = 1;
              param_3[0x151d] = ppppppuVar11;
            }
            else if (cVar26 == '\x02') {
              cVar26 = pcVar15[1];
              if (cVar26 == '\x01') {
                ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 4);
                param_3[0x151d] = ppppppuVar11;
              }
              else if (cVar26 == '\0') {
                ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 2);
                param_3[0x151d] = ppppppuVar11;
              }
              else if (cVar26 == '\x02') {
                ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 8);
                param_3[0x151d] = ppppppuVar11;
              }
              else if (cVar26 == '\x03') {
                ppppppuVar11 = (uint ******)((uint)ppppppuVar11 | 0x10);
                param_3[0x151d] = ppppppuVar11;
              }
            }
            else if (cVar26 == '\x05') {
              param_3[0x151e] =
                   (uint ******)(4 << ((uint)(byte)pcVar15[1] * 3 & 0x3f) | (uint)param_3[0x151e]);
              param_3[0x1588] =
                   (uint ******)(4 << ((uint)(byte)pcVar15[1] * 3 & 0x3f) | (uint)param_3[0x1588]);
            }
            pcVar15 = pcVar15 + 0xc;
            local_2654 = (uint ******)((int)local_2654 - 1);
          } while (local_2654 != (uint ******)0x0);
        }
        if (((uint)ppppppuVar11 & 0x18) != 0) {
          param_3[0x151d] = (uint ******)((uint)ppppppuVar11 | 0x1c);
        }
        pppppppuVar20 = param_3 + 0x1571;
        iVar12 = 0x16;
        do {
          *pppppppuVar20 = (uint ******)0x16;
          pppppppuVar20 = pppppppuVar20 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        ppppppuVar11 = param_3[0x1503];
        if (ppppppuVar11 != (uint ******)0x0) {
          puVar39 = &uStack_2954;
          ppppppuVar16 = ppppppuVar11;
          if (ppppppuVar11 == (uint ******)0x0) {
            ppppppuVar16 = (uint ******)0x1;
          }
          do {
            pbVar2 = puVar39 + 1;
            pbVar5 = puVar39 + (int)(abStack_2950 + -(int)&uStack_2954);
            puVar39 = puVar39 + 0xc;
            param_3[(int)(((unsigned char *)0x00001571) + *pbVar2)] = (uint ******)(uint)*pbVar5;
            ppppppuVar16 = (uint ******)((int)ppppppuVar16 + -1);
          } while (ppppppuVar16 != (uint ******)0x0);
        }
        if (ppppppuVar11 < (uint ******)0x2) {
          if (ppppppuVar11 == (uint ******)0x0) {
            param_3[0x1571] = (uint ******)0x0;
            param_3[0x1572] = (uint ******)0x1;
          }
          else if (param_3[0x1571] == (uint ******)0x0) {
            param_3[0x1572] = (uint ******)0x1;
          }
          else {
            param_3[0x1572] = (uint ******)0x0;
          }
        }
        iVar12 = *local_2408;
        param_3[0x1520] = (uint ******)0x0;
        param_3[0x151f] = (uint ******)(uint)(iVar12 != 0);
        if (((uint ******)(uint)(iVar12 != 0) != (uint ******)0x0) &&
           (iVar12 = *local_2408, 0 < iVar12)) {
          pppppppuVar20 = param_3 + 0x1531;
          ppppppuVar11 = (uint ******)0x0;
          do {
            pppppppuVar20[0x20] = (uint ******)0x0;
            *pppppppuVar20 = (uint ******)0x0;
            pppppppuVar20[0x10] = (uint ******)0x0;
            if (local_2408[(int)ppppppuVar11 * 7 + 3] == 0x3e) {
              param_3[0x1520] =
                   (uint ******)(2 << (((uint)ppppppuVar11 & 0x1f) << 1) | (uint)param_3[0x1520]);
              *(char *)((int)param_3 + (int)ppppppuVar11 * 4 + 0x5547) =
                   (char)aiStack_1220[local_2408[(int)ppppppuVar11 * 7 + 4] * 4 + 1];
              *(char *)((int)param_3 + (int)ppppppuVar11 * 4 + 0x5546) =
                   (char)aiStack_1220[local_2408[(int)ppppppuVar11 * 7 + 4] * 4 + 2];
              *(short *)((int)param_3 + (int)ppppppuVar11 * 4 + 0x54c6) =
                   (short)local_2408[(int)ppppppuVar11 * 7 + 5];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001531) + (int)ppppppuVar11)) =
                   (short)aiStack_1220[local_2408[(int)ppppppuVar11 * 7 + 4] * 4];
              *(short *)((int)param_3 + (int)ppppppuVar11 * 4 + 0x5506) =
                   (short)local_2408[(int)ppppppuVar11 * 7 + 7];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001541) + (int)ppppppuVar11)) =
                   (short)local_2408[(int)ppppppuVar11 * 7 + 5] + 1;
              param_3[(int)(((unsigned char *)0x00001561) + local_2408[(int)ppppppuVar11 * 7 + 4])] = ppppppuVar11;
            }
            ppppppuVar11 = (uint ******)((int)ppppppuVar11 + 1);
            pppppppuVar20 = pppppppuVar20 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        if (local_240c != (uint *)0x0) {
          _free(local_240c);
        }
        if (pvVar17 != (void *)0x0) {
          _free(pvVar17);
        }
        if (local_2408 != (int *)0x0) {
          _free(local_2408);
        }
        if (puVar31 != (uint *)0x0) {
          _free(puVar31);
        }
        if (pvVar19 != (void *)0x0) {
          _free(pvVar19);
        }
        if (local_29f8 != (void *)0x0) {
          _free(local_29f8);
        }
        if (local_29fc != (void *)0x0) {
          _free(local_29fc);
        }
        return (uint *******)0x0;
      }
    } while( true );
  }
  ppppppuVar11 = (uint ******)*puVar21;
  uVar34 = (uint)ppppppuVar11 & 0xffff;
  if (100 < uVar34) {
switchD_000c90cc_caseD_0:
                    
    _exit(0);
  }
  iVar40 = uVar34 * 4;
  puVar28 = puVar21;
  switch(uVar34) {
  case 0:
  case 0x17:
  case 0x1b:
  case 0x36:
  case 0x42:
  case 0x43:
  case 0x4f:
  case 0x5f:
  case 0x60:
  case 0x61:
    goto switchD_000c90cc_caseD_0;
  default:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,puVar21,pppppppuVar22,
                                iVar40,pppppppuVar27);
    }
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,1,&local_23e8);
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,puVar21,pppppppuVar22,
                                iVar40,pppppppuVar27);
    }
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,2,&local_23e8);
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_2bb4 = puVar21 + 1;
    *local_2bb8 = ppppppuVar11;
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar20 = (uint *******)0x0;
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,0,2,&local_23e8);
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_2bb8 = ppppppuVar11;
    local_2bb4 = puVar21 + 2;
    local_2bb8[1] = (uint ******)puVar21[1];
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8 + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_2bb8 = ppppppuVar11;
    local_2bb8[1] = (uint ******)puVar21[1];
    local_2bb4 = puVar21 + 3;
    local_2bb8[2] = (uint ******)puVar21[2];
    puVar28 = local_2bb4;
    pppppppuVar27 = local_2bb8 + 3;
    pppppppuVar32 = local_2bb8 + 3;
    goto switchD_000c9ab8_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,puVar21,pppppppuVar22,
                                iVar40,pppppppuVar27);
    }
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,3,&local_23e8);
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    local_2bb4 = puVar21 + 2;
    *local_2bb8 = ppppppuVar11;
    local_2bb8[1] = (uint ******)puVar21[1];
    pppppppuVar32 = local_2bb8 + 2;
    for (uVar34 = (uint)*(ushort *)((int)puVar21 + 6); puVar28 = local_2bb4, uVar34 != 0;
        uVar34 = uVar34 - 1) {
      ppppppuVar11 = (uint ******)*local_2bb4;
      local_2bb4 = local_2bb4 + 1;
      *pppppppuVar32 = ppppppuVar11;
      pppppppuVar32 = pppppppuVar32 + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    local_2bb4 = puVar21 + 1;
    if (((uint)ppppppuVar11 & 0x18000000) == 0) {
      uVar34 = *(uint *)((int)auStack_130 + ((uint)ppppppuVar11 >> 0xe & 0x3fc));
      if (uVar34 != 2) {
        uVar34 = 1;
      }
      ppppppuVar11 = (uint ******)((uVar34 & 3) << 0x1b | (uint)ppppppuVar11 & 0xe7ffffff);
    }
    *local_2bb8 = ppppppuVar11;
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    local_2bb4 = puVar21 + 1;
    *local_2bb8 = ppppppuVar11;
    pppppppuVar27 = local_2bb8 + 1;
    if ((int)ppppppuVar11 < 0) {
      ppppppuVar11 = (uint ******)*local_2bb4;
      local_2bb4 = puVar21 + 2;
      local_2bb8[1] = ppppppuVar11;
      pppppppuVar27 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar27;
    ppppppuVar11 = (uint ******)*local_2bb4;
    local_2bb4 = local_2bb4 + 1;
    *local_2bb8 = ppppppuVar11;
    puVar28 = local_2bb4;
    pppppppuVar27 = pppppppuVar32;
    pppppppuVar32 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    local_2bb4 = puVar21 + 1;
    pppppppuVar20 = local_2bb8 + 1;
    *local_2bb8 = ppppppuVar11;
    puVar28 = local_2bb4;
    pppppppuVar32 = pppppppuVar20;
    if ((puVar21[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_2bb8[1] = (uint ******)puVar21[1];
      pppppppuVar22 = local_2bb8 + 6;
      local_2bb8[2] = (uint ******)puVar21[2];
      local_2bb8[3] = (uint ******)puVar21[3];
      local_2bb8[4] = (uint ******)puVar21[4];
      local_2bb4 = puVar21 + 6;
      local_2bb8[5] = (uint ******)puVar21[5];
      puVar28 = local_2bb4;
      pppppppuVar27 = local_2bb8 + 5;
      pppppppuVar32 = pppppppuVar22;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    local_2bb4 = puVar21 + 1;
    puVar18 = (undefined4 *)
              ((int (*)())FUN_000c7930)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,local_2bb4,pppppppuVar22,
                           iVar40);
    *puVar18 = ppppppuVar11;
    puVar28 = local_2bb4;
    pppppppuVar32 = (uint *******)(puVar18 + 1);
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    pppppppuVar20 = &local_23e8;
    *local_2bb8 = ppppppuVar11;
    local_2bb4 = puVar21 + 2;
    local_2b8c[0] = (uint ******)puVar21[1];
    local_2bb8 = local_2bb8 + 1;
    ((int (*)())FUN_000c8760)(local_2b8c,auStack_2b80,pppppppuVar20);
    *local_2bb8 = local_2b8c[0];
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar20 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar20 = (uint *******)((int)&MACH_HEADER.magic + 1);
    break;
  case 0x5d:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,puVar21,pppppppuVar22,
                                iVar40,pppppppuVar27);
      puVar21 = local_2bb4;
    }
    ppppppuVar11 = (uint ******)*puVar21;
    puVar28 = puVar21 + 1;
    uVar34 = (uint)ppppppuVar11 >> 0x10;
    uVar24 = uVar34 & 0xff;
    bVar3 = ((uint)ppppppuVar11 & 0x80000000) != 0;
    if (bVar3) {
      puVar28 = puVar21 + 2;
      ppppppuVar16 = (uint ******)puVar21[1];
    }
    else {
      ppppppuVar16 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar11 >> 0x1e & 1) != 0;
    if (bVar1) {
      ppppppuVar25 = (uint ******)*puVar28;
      puVar28 = puVar28 + 1;
    }
    else {
      ppppppuVar25 = (uint ******)0x0;
    }
    local_2ba4 = (uint *******)*puVar28;
    puVar21 = puVar28 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar21 = puVar28 + 2;
      unaff_r15 = (uint ******)puVar28[1];
    }
    local_2b74 = (uint ******)*puVar21;
    local_2bb4 = puVar21 + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2b98 = (uint ******)puVar21[1];
      local_2bb4 = puVar21 + 2;
    }
    uVar7 = (uint)ppppppuVar11 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca0e4:
      if (local_2378 << (uVar34 & 0x3f) == 0) {
        local_70 = (uint ******)&local_2b74;
        pppppppuVar32 = (uint *******)0x0;
        uVar36 = 1 << (uVar34 & 0x3f);
        ppppppuVar30 = (uint ******)&local_2b98;
      }
      else {
        local_60 = (uint ******)&local_2b98;
        local_70 = (uint ******)&local_2b74;
        local_2bb8 = (uint *******)((int (*)())FUN_000c7460)(&local_23e8,local_70,local_60,uVar24,local_2bb8);
        ppppppuVar30 = local_60;
        if (((uint)local_2ba4 & 0x400000) == 0) {
          pppppppuVar32 = (uint *******)0x0;
          uVar36 = 1 << (uVar34 & 0x3f);
        }
        else {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          pppppppuVar32 = (uint *******)((int)&MACH_HEADER.magic + 1);
          uVar36 = 1 << (uVar34 & 0x3f);
          local_2bb0 = unaff_r15;
        }
      }
    }
    else if (uVar7 == 0x8000000) {
      uVar36 = 1 << (uVar34 & 0x3f);
      if ((uVar36 & local_2374) != 0) goto LAB_000ca0e4;
      local_70 = (uint ******)&local_2b74;
      pppppppuVar32 = (uint *******)0x0;
      ppppppuVar30 = (uint ******)&local_2b98;
    }
    else {
      pppppppuVar32 = (uint *******)0x0;
      uVar36 = 1 << (uVar34 & 0x3f);
      local_70 = (uint ******)&local_2b74;
      ppppppuVar30 = (uint ******)&local_2b98;
    }
    pppppppuVar20 = &local_23e8;
    ((int (*)())FUN_000c8760)(local_70,ppppppuVar30,&local_23e8);
    *local_2bb8 = ppppppuVar11;
    pppppppuVar27 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = ppppppuVar16;
      pppppppuVar27 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar27;
    if (bVar1) {
      *local_2bb8 = ppppppuVar25;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = (uint ******)local_2ba4;
    pppppppuVar27 = local_2bb8 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r15;
      pppppppuVar27 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar27;
    *local_2bb8 = local_2b74;
    pppppppuVar27 = (uint *******)((uint)local_2b74 & 0x400000);
    pppppppuVar9 = local_2bb8 + 1;
    if (pppppppuVar27 != (uint *******)0x0) {
      local_2bb8[1] = local_2b98;
      pppppppuVar9 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar9;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar36 & local_2374) != 0)))) &&
       (local_2378 << (uVar34 & 0x3f) != 0)) {
      pppppppuVar20 = (uint *******)&local_2ba4;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_23e8,local_70,pppppppuVar20,&local_2bb0,uVar24,pppppppuVar32,
                                local_2bb8,pppppppuVar27);
      pppppppuVar22 = pppppppuVar32;
    }
    uVar36 = uVar36 & local_2378;
    ppppppuVar11 = unaff_r15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar20,puVar21,puVar21,pppppppuVar22,
                                iVar40,pppppppuVar27);
      puVar21 = local_2bb4;
    }
    ppppppuVar11 = (uint ******)*puVar21;
    puVar28 = puVar21 + 1;
    uVar34 = (uint)ppppppuVar11 >> 0x10;
    uVar24 = uVar34 & 0xff;
    bVar3 = ((uint)ppppppuVar11 & 0x80000000) != 0;
    if (bVar3) {
      puVar28 = puVar21 + 2;
      ppppppuVar16 = (uint ******)puVar21[1];
    }
    else {
      ppppppuVar16 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar11 & 0x40000000) != 0;
    if (bVar1) {
      ppppppuVar25 = (uint ******)*puVar28;
      puVar28 = puVar28 + 1;
    }
    else {
      ppppppuVar25 = (uint ******)0x0;
    }
    local_2ba4 = (uint *******)*puVar28;
    puVar21 = puVar28 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar21 = puVar28 + 2;
      unaff_r14 = (uint ******)puVar28[1];
    }
    local_2b98 = (uint ******)*puVar21;
    puVar28 = puVar21 + 1;
    if (((uint)local_2b98 & 0x400000) != 0) {
      local_2b74 = (uint ******)puVar21[1];
      puVar28 = puVar21 + 2;
    }
    local_2b94 = (uint ******)*puVar28;
    local_2bb4 = puVar28 + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      local_2b70 = (uint ******)puVar28[1];
      local_2bb4 = puVar28 + 2;
    }
    uVar7 = (uint)ppppppuVar11 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca3b8:
      if (local_2378 << (uVar34 & 0x3f) != 0) {
        pppppppuVar20 = &local_2b74;
        local_2bb8 = (uint *******)
                     ((int (*)())FUN_000c7460)(&local_23e8,&local_2b98,pppppppuVar20,uVar24,local_2bb8);
        if (((uint)local_2ba4 & 0x400000) != 0) {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          pppppppuVar22 = (uint *******)((int)&MACH_HEADER.magic + 1);
          uVar36 = 1 << (uVar34 & 0x3f);
          local_2bb0 = unaff_r14;
          goto LAB_000ca414;
        }
      }
LAB_000ca3ec:
      pppppppuVar22 = (uint *******)0x0;
      uVar36 = 1 << (uVar34 & 0x3f);
    }
    else {
      if (uVar7 != 0x8000000) goto LAB_000ca3ec;
      pppppppuVar22 = (uint *******)0x0;
      uVar36 = 1 << (uVar34 & 0x3f);
      if ((uVar36 & local_2374) != 0) goto LAB_000ca3b8;
    }
LAB_000ca414:
    *local_2bb8 = ppppppuVar11;
    pppppppuVar27 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = ppppppuVar16;
      pppppppuVar27 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar27;
    if (bVar1) {
      *local_2bb8 = ppppppuVar25;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = (uint ******)local_2ba4;
    pppppppuVar27 = local_2bb8 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r14;
      pppppppuVar27 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar27;
    *local_2bb8 = local_2b98;
    pppppppuVar27 = (uint *******)((uint)local_2b98 & 0x400000);
    pppppppuVar32 = local_2bb8 + 1;
    if (pppppppuVar27 != (uint *******)0x0) {
      local_2bb8[1] = local_2b74;
      pppppppuVar32 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar32;
    *local_2bb8 = local_2b94;
    pppppppuVar32 = local_2bb8 + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      local_2bb8[1] = local_2b70;
      pppppppuVar32 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar32;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar36 & local_2374) != 0)))) &&
       (pppppppuVar27 = (uint *******)(local_2378 << (uVar34 & 0x3f)),
       pppppppuVar27 != (uint *******)0x0)) {
      pppppppuVar20 = (uint *******)&local_2ba4;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_23e8,&local_2b98,pppppppuVar20,&local_2bb0,uVar24,
                                pppppppuVar22,local_2bb8,pppppppuVar27);
    }
    uVar36 = uVar36 & local_2378;
    ppppppuVar11 = unaff_r14;
joined_r0x000ca538:
    puVar28 = local_2bb4;
    pppppppuVar32 = local_2bb8;
    if (uVar36 != 0) {
      pppppppuVar22 = local_2bb8 + 1;
      *local_2bb8 = (uint ******)0x47;
      pppppppuVar27 = local_2ba4;
      if (((uint)local_2ba4 & 0x400000) == 0) {
        pppppppuVar27 = (uint *******)((uint)local_2ba4 | 0x400000);
        ppppppuVar11 = (uint ******)0x55;
      }
      if (aiStack_22f0[uVar24] == 0x1906) {
        if (((uint)ppppppuVar11 & 3) == 1) {
          ppppppuVar11 = (uint ******)((uint)ppppppuVar11 & 0xfffffffc | 2);
        }
        if (((uint)ppppppuVar11 & 0xc) == 4) {
          ppppppuVar11 = (uint ******)((uint)ppppppuVar11 & 0xfffffff3 | 8);
        }
        if (((uint)ppppppuVar11 & 0x30) == 0x10) {
          ppppppuVar11 = (uint ******)((uint)ppppppuVar11 & 0xffffffcf | 0x20);
        }
      }
      else if ((aiStack_22f0[uVar24] == 0x1909) && (((uint)ppppppuVar11 & 0xc0) == 0x40)) {
        ppppppuVar11 = (uint ******)((uint)ppppppuVar11 & 0xffffff3f | 0xc0);
      }
      *pppppppuVar22 = (uint ******)pppppppuVar27;
      local_2bb8[2] = ppppppuVar11;
      local_2bb8[3] = (uint ******)((uint)pppppppuVar27 & 0x3fffff);
      pppppppuVar32 = local_2bb8 + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,pppppppuVar20,1,&local_23e8);
  puVar28 = local_2bb4;
  pppppppuVar32 = local_2bb8;
  goto switchD_000c9ab8_caseD_18;
}

/* FUN_000cae90 @ 0xcae90 (7760 bytes) */
int FUN_000cae90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  uint *******param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  bool bVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  undefined *puVar8;
  uint uVar9;
  float fVar10;
  uint *******pppppppuVar11;
  uint uVar12;
  int iVar13;
  uint ******ppppppuVar14;
  uint ******ppppppuVar15;
  int iVar16;
  uint ******ppppppuVar17;
  void *pvVar18;
  void *pvVar19;
  int *piVar20;
  uint *******pppppppuVar21;
  uint uVar22;
  uint *puVar23;
  uint *puVar24;
  int iVar25;
  uint *******in_r8;
  byte *pbVar26;
  int iVar27;
  uint uVar28;
  uint *******pppppppuVar29;
  undefined4 uVar30;
  int iVar31;
  char *pcVar32;
  int *piVar33;
  undefined4 uVar34;
  uint ******unaff_r14;
  uint ******unaff_r15;
  uint *puVar35;
  uint uVar36;
  uint unaff_r19;
  uint *******pppppppuVar37;
  undefined1 *puVar38;
  uint unaff_r20;
  undefined1 *puVar39;
  uint ******ppppppuVar40;
  uint *puVar41;
  float *pfVar42;
  uint uVar43;
  int iVar44;
  int *piVar45;
  undefined4 *puVar46;
  int iVar47;
  uint *local_c1f8;
  uint *******local_c1f4;
  uint *******local_c1f0;
  uint local_c1ec [2];
  uint ******local_c1e4;
  uint local_c1e0 [2];
  uint ******local_c1d8;
  uint ******local_c1d4;
  uint ******local_c1cc;
  uint ******local_c1c8;
  uint ******local_c1c0 [3];
  undefined1 auStack_c1b4 [12];
  uint ******local_c1a8;
  uint local_c1a4;
  uint local_c1a0;
  uint local_c19c;
  uint local_c198 [4];
  undefined4 local_c188 [4];
  undefined4 local_c178;
  undefined4 local_c174;
  undefined4 local_c170;
  undefined4 local_c16c;
  uint local_c168 [4];
  undefined4 local_c158;
  undefined4 local_c154;
  undefined4 local_c150;
  undefined4 local_c14c;
  undefined1 auStack_c148 [72];
  uint *local_c100;
  uint *local_c0fc;
  int local_c0f8;
  uint local_c0f0 [8];
  uint local_c0d0 [16];
  void *local_c090;
  uint ******local_c08c;
  undefined4 local_c088;
  uint local_c084;
  uint local_c080 [4];
  undefined4 local_c070;
  undefined4 local_c06c;
  undefined4 local_c068;
  undefined4 local_c064;
  uint local_c060 [4];
  undefined4 local_c050;
  undefined4 local_c04c;
  undefined4 local_c048;
  undefined4 local_c044;
  int local_c040;
  uint ******local_c03c;
  int local_c034;
  int local_c030;
  uint local_c02c;
  int local_c028;
  int local_c024;
  int local_c020;
  uint local_c01c;
  uint local_c018;
  undefined4 local_bfd4;
  uint local_bf94 [16];
  uint local_bf54 [16];
  uint local_bf14;
  uint local_bf04 [6];
  undefined1 auStack_beec [4104];
  uint local_aee4 [6];
  undefined1 auStack_aecc [4104];
  int local_9ec4;
  int local_9ebc;
  uint ******local_9eb8;
  undefined4 local_9eb4;
  int local_9e9c [5];
  int local_9e88;
  int local_9e80;
  int local_9e78;
  int local_9e74;
  int local_9e70;
  int local_9e6c;
  undefined4 local_9e68;
  int local_9e64;
  int local_9e60;
  undefined4 local_9e5c;
  uint *******local_9e58;
  int local_9e54 [16];
  int local_9e14 [16];
  uint local_9dd4 [17];
  uint ******local_9d90;
  int local_9d88;
  int local_9d84;
  undefined4 local_9d80;
  int local_9d7c;
  undefined4 local_9d70;
  int local_9d6c;
  undefined4 local_9d20;
  undefined1 auStack_9d1c [72];
  undefined4 local_9cd4;
  uint local_9cc8;
  void *local_9cbc;
  uint local_9c84 [27];
  int local_9c18;
  char local_9c14 [1348];
  undefined1 auStack_96d0 [37816];
  int iStack_318;
  uint *******local_88;
  uint ******local_84;
  int *local_80;
  uint ******local_70;
  
  iVar47 = 8;
  iVar13 = 0;
  do {
    *(undefined4 *)((int)local_c168 + iVar13) = 0xffffffff;
    *(undefined4 *)((int)local_c188 + iVar13) = 0;
    iVar13 = iVar13 + 4;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  bVar3 = param_1 == 0;
  local_c168[0] = local_c168[0] & 0xffff0000;
  pppppppuVar21 = param_3;
  pvVar18 = _malloc(0x400);
  local_9d20 = 0;
  local_c018 = 0;
  local_9d70 = 0;
  local_9d6c = 0;
  if (bVar3) {
    local_c01c = 0;
  }
  else {
    in_r8 = (uint *******)0x0;
    iVar47 = 0x10;
    local_c018 = 0;
    local_c01c = 0;
    puVar35 = local_bf94;
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    iVar13 = param_1;
    do {
      iVar27 = *(int *)(((unsigned char *)0x000013f8) + iVar13);
      if ((iVar27 != 0) && (*(short *)(iVar27 + 0x38) == 0x1902)) {
        uVar22 = 1 << ((uint)in_r8 & 0x3f);
        local_c01c = uVar22 | local_c01c;
        *puVar35 = (uint)*(ushort *)(iVar27 + 0x58);
        puVar35[0x10] = (uint)*(ushort *)(iVar27 + 0x5c);
        if (*(short *)(iVar27 + 0x5a) != 0) {
          local_c018 = uVar22 | local_c018;
        }
      }
      in_r8 = (uint *******)((int)in_r8 + 1);
      iVar13 = iVar13 + 4;
      puVar35 = puVar35 + 1;
      iVar47 = iVar47 + -1;
    } while (iVar47 != 0);
  }
  if (*(char *)(param_3 + 0x46) == '\0') {
    local_9ebc = 0;
  }
  else {
    local_9eb8 = param_3[0x2b];
    local_9ebc = 1;
    if (bVar3) {
      local_9eb4 = 0;
    }
    else {
      local_9eb4 = *(undefined4 *)(param_1 + 0x276c);
    }
  }
  iVar13 = 0;
  puVar35 = local_9dd4;
  iVar47 = 0x10;
  do {
    *puVar35 = 0;
    if ((!bVar3) && (*(int *)(((unsigned char *)0x000013f8) + iVar13 * 4 + *param_2) != 0)) {
      *puVar35 = (uint)*(byte *)(*(int *)(((unsigned char *)0x000013f8) + iVar13 * 4 + *param_2) + 0x30);
    }
    iVar13 = iVar13 + 1;
    puVar35 = puVar35 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  local_9e58 = (uint *******)((int)&MACH_HEADER.magic + 1);
  local_9e88 = 0;
  local_9d90 = param_3[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != -0x7baf)) {
    local_9d80 = 0;
  }
  else {
    local_9d80 = 1;
  }
  puVar41 = (uint *)*param_4;
  local_c08c = (uint ******)0x0;
  local_c028 = 0;
  local_c088 = 0xffff;
  local_c064 = local_c14c;
  local_c068 = local_c150;
  local_c06c = local_c154;
  local_c070 = local_c158;
  local_c080[3] = local_c168[3];
  local_c080[2] = local_c168[2];
  local_c080[1] = local_c168[1];
  local_c080[0] = local_c168[0];
  local_c044 = local_c16c;
  local_c048 = local_c170;
  iVar13 = param_4[1];
  local_c04c = local_c174;
  local_c050 = local_c178;
  local_c040 = 0;
  local_c060[3] = local_c188[3];
  local_c060[2] = local_c188[2];
  local_c084 = 0;
  local_9e5c = 0;
  local_bf14 = 0;
  local_9ec4 = 0;
  local_9e9c[0] = 0;
  local_9e9c[1] = 0;
  local_9e9c[2] = 0;
  local_9e9c[3] = 0;
  local_9e78 = 0;
  local_9e74 = 0;
  local_9e70 = 0;
  local_9e6c = 0;
  local_9e80 = 0;
  local_9e68 = 0;
  local_9e64 = 0;
  local_9e60 = 0;
  local_c060[1] = local_c188[1];
  local_c060[0] = local_c188[0];
  puVar35 = local_bf04;
  iVar47 = 8;
  do {
    *puVar35 = 0;
    puVar35[0x408] = 0;
    puVar35 = puVar35 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  local_80 = local_9e54;
  iVar47 = 0x10;
  piVar20 = local_80;
  do {
    *piVar20 = 0;
    piVar20[0x10] = 0;
    piVar20 = piVar20 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  iVar47 = 0;
  iVar27 = 0;
  uVar22 = 0;
  puVar35 = puVar41;
switchD_000cb23c_caseD_15:
  local_c1f8 = puVar35 + 2;
  puVar24 = local_c1f8;
switchD_000cb23c_caseD_18:
  puVar35 = puVar24;
  if (puVar35 < puVar41 + iVar13) goto code_r0x000cb214;
  if (local_9ec4 != 0) {
    puVar35 = (uint *)0x0;
    uVar36 = 0;
    goto LAB_000cc88c;
  }
  iVar47 = (iVar13 + iVar47) * 4;
  local_c03c = local_c08c;
  if (local_c040 != 0) {
    iVar47 = iVar47 + 0x48;
  }
  uVar36 = iVar47 + iVar27 * 4;
  bVar5 = local_9ebc != 0;
  if (bVar5) {
    uVar36 = uVar36 + 0x14;
  }
  uVar12 = uVar36;
  if ((local_9e9c[0] != 0) && (uVar12 = uVar36 + 0xc, bVar5)) {
    uVar12 = uVar36 + 0x24;
  }
  uVar36 = uVar12;
  if ((local_9e9c[1] != 0) && (uVar36 = uVar12 + 0xc, bVar5)) {
    uVar36 = uVar12 + 0x24;
  }
  uVar12 = uVar36;
  if ((local_9e9c[2] != 0) && (uVar12 = uVar36 + 0xc, bVar5)) {
    uVar12 = uVar36 + 0x24;
  }
  uVar28 = uVar12;
  if ((local_9e9c[3] != 0) && (uVar28 = uVar12 + 0xc, bVar5)) {
    uVar28 = uVar12 + 0x24;
  }
  if (((local_9e80 != 0) && (local_9e88 != 0)) && (local_9e58 == (uint *******)0x0)) {
    uVar28 = uVar28 + 0x14;
  }
  if (local_9d90 == (uint ******)0x1) {
    uVar28 = uVar28 + 0x24;
  }
  else if (local_9d90 == (uint ******)0x2) {
    uVar28 = uVar28 + 0x30;
  }
  else if (local_9d90 == (uint ******)0x3) {
    uVar28 = uVar28 + 0x40;
  }
  else if (local_9d90 == (uint ******)0x0) goto LAB_000cbb64;
  uVar28 = uVar28 + 8;
  piVar20 = local_9e9c;
  iVar47 = 4;
  do {
    if (*piVar20 != 0) {
      uVar28 = uVar28 + 0x2c;
    }
    piVar20 = piVar20 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
LAB_000cbb64:
  if (((local_9e74 != 0) || (local_9e6c != 0)) || (uVar36 = uVar28, local_9e58 == (uint *******)0x0)
     ) {
    if ((local_9e78 == 0) && (local_9e70 != 0)) {
      uVar28 = uVar28 + 0xc;
    }
    uVar36 = uVar28;
    if ((local_9e58 == (uint *******)0x0) && (uVar36 = uVar28 + 0xc, local_9d7c != 0)) {
      uVar36 = uVar28 + 0x18;
    }
  }
  bVar5 = true;
  pppppppuVar29 = local_9e58;
  puVar35 = _malloc(uVar36 + 0x10);
  *puVar35 = *puVar41;
  local_c1f8 = puVar41 + 2;
  puVar35[1] = puVar41[1];
  puVar24 = local_c1f8;
  pppppppuVar37 = (uint *******)(puVar35 + 2);
  goto switchD_000cbc48_caseD_18;
code_r0x000cb214:
  pppppppuVar21 = (uint *******)*puVar35;
  puVar24 = puVar35;
  switch((uint)pppppppuVar21 & 0xffff) {
  default:
    goto switchD_000cb23c_caseD_0;
  case 1:
  case 2:
  case 4:
  case 5:
  case 0xb:
  case 0xe:
  case 0x12:
  case 0x1e:
  case 0x25:
  case 0x26:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x47:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x50:
  case 0x51:
  case 0x54:
  case 0x55:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
  case 0x62:
  case 99:
    uVar30 = 1;
    break;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    uVar30 = 1;
    goto LAB_000cb4b0;
  case 6:
  case 0x10:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar35 + 1;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar30 = 0;
LAB_000cb4b0:
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 2);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar35,uVar30,2,&local_c08c);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    local_c1f8 = puVar35 + 2;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    local_c1f8 = puVar35 + 3;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 3);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar35,1,3,&local_c08c);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    local_c1f8 = puVar35 + *(ushort *)((int)puVar35 + 6) + 2;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    local_c1f8 = puVar35 + 3;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    local_c1f8 = puVar35 + 1;
    pppppppuVar21 = &local_c08c;
    uVar36 = puVar35[1];
    puVar8 = (undefined *)(uVar36 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar36 & 0xffff,uVar36 >> 0x10 & 0x3f,pppppppuVar21,0,0);
    if (puVar8 == ((unsigned char *)0x00160000)) {
      local_c040 = 1;
    }
    else if (puVar8 == (undefined *)0x110000) {
      local_c084 = 1 << (uVar36 & 0x3f) | local_c084;
    }
    else if (puVar8 == (undefined *)0xf0000) {
      uVar22 = uVar22 | 1 << (uVar36 & 0x3f);
    }
    else if (puVar8 == (undefined *)0x100000) {
      local_c028 = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar12 = (uint)pppppppuVar21 >> 0x1b & 3;
    uVar36 = (uint)pppppppuVar21 >> 0x10 & 0xff;
    if ((uVar12 == 2) || ((uVar12 == 0 && (local_9dd4[uVar36] == 2)))) {
      local_bf14 = 1 << ((uint)pppppppuVar21 >> 0x10 & 0x3f) | local_bf14;
    }
    pppppppuVar21 = (uint *******)((uint)pppppppuVar21 >> 0x18 & 7);
    FUN_000c7270(&local_c08c,uVar36,pppppppuVar21);
    local_c1f8 = local_c1f8 + 1;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    local_c1f8 = puVar35 + 1;
    if ((int)pppppppuVar21 < 0) {
      local_c1f8 = puVar35 + 2;
    }
LAB_000cb6d4:
    local_c1f8 = local_c1f8 + 1;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    local_c1f8 = puVar35 + 1;
    uVar12 = puVar35[1];
    uVar36 = uVar12 >> 0x10 & 0x3f;
    if (uVar36 == 1) {
      pppppppuVar21 = &local_c1a8;
      local_c1a8 = (uint ******)puVar35[2];
      local_c1a4 = puVar35[3];
      local_c1a0 = puVar35[4];
      local_c1f8 = puVar35 + 6;
      local_c19c = puVar35[5];
      FUN_000c7290(&local_c08c,uVar12 & 0xffff,pppppppuVar21);
      puVar24 = local_c1f8;
    }
    else {
      puVar24 = local_c1f8;
      if (uVar36 == 2) {
        pppppppuVar21 = &local_c1a8;
        local_c1a8 = (uint ******)puVar35[2];
        local_c1a4 = puVar35[3];
        local_c1a0 = puVar35[4];
        local_c1f8 = puVar35 + 6;
        local_c19c = puVar35[5];
        FUN_000c72f0(&local_c08c,uVar12 & 0xffff,pppppppuVar21);
        puVar24 = local_c1f8;
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 2);
    iVar47 = iVar47 + 5;
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar35,1,2,&local_c08c);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    pppppppuVar21 = &local_c08c;
    local_c1f8 = puVar35 + 2;
    local_c1c0[0] = (uint ******)puVar35[1];
    ((int (*)())FUN_000c87d0)(local_c1c0,auStack_c1b4,pppppppuVar21);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar35,0,1,&local_c08c);
    local_9e60 = 1;
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar30 = 0;
    break;
  case 0x5d:
    local_c1f8 = puVar35 + 2;
    local_9d6c = local_9d6c + 1;
    uVar36 = puVar35[1];
    uVar12 = *puVar35;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar35 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar35 + 1) & 0x3f) != 0)) {
      iVar27 = iVar27 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar35 + 1) & 0x3f) | local_c018;
      uVar12 = *puVar35;
    }
    if ((int)uVar12 < 0) {
      local_c1f8 = puVar35 + 3;
      uVar12 = *puVar35;
    }
    if ((uVar12 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar36 & 0x400000) != 0) {
      unaff_r20 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar36 & 0xffff,uVar36 >> 0x10 & 0x3f,local_88,unaff_r20,uVar36 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar35 + 1) & 0x3f) & local_c01c) != 0) {
      iVar27 = iVar27 + 4;
    }
    local_c1e4 = (uint ******)*local_c1f8;
    puVar35 = local_c1f8 + 1;
    if (((uint)local_c1e4 & 0x400000) != 0) {
      local_c1f0 = (uint *******)local_c1f8[1];
      puVar35 = local_c1f8 + 2;
    }
    local_c1f8 = puVar35;
    pppppppuVar21 = local_88;
    ((int (*)())FUN_000c87d0)(&local_c1e4,&local_c1f0,local_88);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    local_c1f8 = puVar35 + 2;
    local_9d6c = local_9d6c + 1;
    uVar36 = puVar35[1];
    uVar12 = *puVar35;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar35 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar35 + 1) & 0x3f) != 0)) {
      iVar27 = iVar27 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar35 + 1) & 0x3f) | local_c018;
      uVar12 = *puVar35;
    }
    if ((int)uVar12 < 0) {
      local_c1f8 = puVar35 + 3;
      uVar12 = *puVar35;
    }
    if ((uVar12 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar36 & 0x400000) != 0) {
      unaff_r19 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar36 & 0xffff,uVar36 >> 0x10 & 0x3f,local_88,unaff_r19,uVar36 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar35 + 1) & 0x3f) & local_c01c) != 0) {
      iVar27 = iVar27 + 4;
    }
    local_c1f0 = (uint *******)*local_c1f8;
    puVar35 = local_c1f8 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1e4 = (uint ******)local_c1f8[1];
      puVar35 = local_c1f8 + 2;
    }
    local_c1ec[0] = *puVar35;
    local_c1f8 = puVar35 + 1;
    if ((local_c1ec[0] & 0x400000) != 0) {
      local_c1e0[0] = puVar35[1];
      local_c1f8 = puVar35 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_c1f0,&local_c1e4,local_88);
    pppppppuVar21 = local_88;
    ((int (*)())FUN_000c87d0)(local_c1ec,local_c1e0,local_88);
    puVar24 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  }
  pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
  local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar35,uVar30,1,&local_c08c);
  puVar24 = local_c1f8;
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  local_c1f4 = pppppppuVar37;
  puVar23 = puVar24;
  pppppppuVar37 = local_c1f4;
  if (puVar41 + iVar13 <= puVar23) {
    uVar36 = uVar36 >> 2;
    local_c084 = uVar22 | local_c084;
LAB_000cc88c:
    if (local_9ec4 != 0) {
      _free(puVar35);
      return local_9ec4;
    }
    if ((local_c040 == 0) || (local_c02c == 0x11)) {
      *(undefined1 *)(param_2 + 0x7a6) = 0;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7a6) = 1;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 1;
      param_2[0x7a4] = local_c02c + 2;
      param_3[0x2e] = (uint ******)(local_c034 + param_2[0x7c7]);
      param_3[0x2f] = (uint ******)(local_c030 + param_2[0x7c7]);
    }
    if ((local_c028 == 0) || (local_c024 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      param_2[0x7a3] = local_c024 + 2;
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
    }
    if (local_9d90 == (uint ******)0x0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = local_c020;
      param_3[0x38] = (uint ******)(local_9d88 + param_2[0x7c7]);
      param_3[0x39] = (uint ******)(local_9d84 + param_2[0x7c7]);
      *(undefined1 *)(param_2 + 0x7a8) = 1;
    }
    if (local_9e64 == 0) {
      *(undefined1 *)((int)param_2 + 0x1efd) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1efd) = 1;
    }
    if (local_9e60 == 0) {
      *(undefined1 *)(param_2 + 0x7c1) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7c1) = 1;
    }
    iVar13 = 8;
    uVar22 = 0;
    pppppppuVar29 = param_3 + 0x2c;
    pppppppuVar21 = param_3;
    do {
      if ((1 << (uVar22 & 0x3f) & local_c084) == 0) {
        *(undefined1 *)(pppppppuVar21 + 0x2c) = 0;
      }
      else if ((local_c040 == 0) || (local_c02c != uVar22)) {
        *(undefined1 *)(pppppppuVar21 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)pppppppuVar29 = 0;
      }
      uVar22 = uVar22 + 1;
      pppppppuVar29 = (uint *******)((int)pppppppuVar29 + 1);
      pppppppuVar21 = (uint *******)((int)pppppppuVar21 + 1);
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    param_2[0x7a9] = 0;
    param_3[0x36] = (uint ******)0x0;
    uVar22 = 0;
    iVar13 = 0x10;
    *(undefined4 *)(((unsigned char *)0x000010e0) + (int)*param_3) = local_bfd4;
    piVar20 = local_80;
    piVar45 = param_2;
    piVar33 = param_2;
    do {
      uVar12 = 1 << (uVar22 & 0x3f);
      if ((uVar12 & local_bf14) == 0) {
        *(undefined1 *)(piVar33 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar33 + 0x582) = 1;
      }
      if ((uVar12 & local_c01c) == 0) {
        *(undefined1 *)(piVar33 + 0x586) = 0;
      }
      else {
        *(undefined1 *)(piVar33 + 0x586) = 1;
        param_2[0x7a9] = 1;
        piVar45[0x7aa] = piVar20[-0x860] + param_2[0x7c7];
      }
      uVar22 = uVar22 + 1;
      piVar45[0x572] = *piVar20;
      piVar45 = piVar45 + 1;
      piVar2 = piVar20 + 0x10;
      piVar20 = piVar20 + 1;
      *(char *)(piVar33 + 0x56e) = (char)*piVar2;
      fVar10 = FLOAT_001aa0e8;
      piVar33 = (int *)((int)piVar33 + 1);
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar13 = 0;
    piVar20 = param_2;
    piVar45 = param_2;
    do {
      if (((!bVar3) && (*(char *)(piVar45 + 0x586) != '\0')) &&
         (iVar47 = *(int *)(((unsigned char *)0x000013f8) + iVar13 * 4 + *param_2), iVar47 != 0)) {
        ((void (*)())FUN_000c8e30)(*param_3,(int)param_3[0x36] + (piVar20[0x7aa] - param_2[0x7c7]),
                     (double)(fVar10 / *(float *)(iVar47 + 0x44)),
                     (double)(fVar10 / *(float *)(iVar47 + 0x48)),(double)*(float *)(iVar47 + 0x50),
                     (double)FLOAT_001aa0e8);
      }
      bVar5 = iVar13 != 0xf;
      piVar20 = piVar20 + 1;
      piVar45 = (int *)((int)piVar45 + 1);
      iVar13 = iVar13 + 1;
    } while (bVar5);
    local_88 = &local_c08c;
    iVar13 = 0;
    puVar41 = local_aee4;
    puVar39 = auStack_beec;
    puVar38 = auStack_aecc;
    do {
      puVar46 = (undefined4 *)(puVar38 + 8);
      pfVar42 = (float *)(puVar39 + 8);
      uVar22 = 0;
      iVar47 = iVar13 << 2;
      do {
        uVar12 = 1 << (uVar22 & 0x3f);
        if ((uVar12 & puVar41[-0x408]) != 0) {
          ((void (*)())FUN_000c8e30)(*param_3,iVar13 + uVar22,(double)*pfVar42,(double)pfVar42[1],
                       (double)pfVar42[2],(double)pfVar42[3]);
        }
        if ((uVar12 & *puVar41) != 0) {
          uVar34 = puVar46[1];
          uVar30 = *puVar46;
          iVar27 = iVar47 + (int)*param_3;
          ((unsigned char *)0x000036c9)[iVar27] = (char)puVar46[2];
          ((unsigned char *)0x000036cb)[iVar27] = (char)uVar30;
          ((unsigned char *)0x000036ca)[iVar27] = (char)uVar34;
        }
        bVar3 = uVar22 != 0x1f;
        iVar47 = iVar47 + 4;
        puVar46 = puVar46 + 4;
        pfVar42 = pfVar42 + 4;
        uVar22 = uVar22 + 1;
      } while (bVar3);
      bVar3 = iVar13 != 0xe0;
      puVar38 = puVar38 + 0x200;
      puVar39 = puVar39 + 0x200;
      puVar41 = puVar41 + 1;
      iVar13 = iVar13 + 0x20;
    } while (bVar3);
    *(uint *)(((unsigned char *)0x00003748) + (int)*param_3) = local_aee4[0];
    _memset(auStack_c148,0,0xbc);
    _memset(auStack_9d1c,0,0x9c88);
    pvVar19 = _malloc(param_5[1]);
    if (pvVar19 == (void *)0x0) {
      return -1;
    }
    _memset(pvVar19,0,param_5[1]);
    local_c0f8 = uVar36 << 2;
    puVar24 = local_c080;
    puVar41 = local_c0f0;
    iVar13 = 8;
    local_c090 = pvVar19;
    do {
      uVar22 = *puVar24;
      uVar36 = puVar24[8];
      puVar24 = puVar24 + 1;
      *puVar41 = uVar22;
      puVar41[8] = uVar36;
      puVar41 = puVar41 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    local_c100 = local_c198;
    local_9cd4 = 0x40;
    local_c198[0] = local_c198[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar35;
    local_9cbc = _malloc(0x900);
    iVar13 = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (iVar13 != 0) {
      return 2;
    }
    iVar13 = 0;
    puVar38 = auStack_96d0;
    do {
      _memcpy((void *)((int)param_3[3] + iVar13),puVar38,0x48);
      ppppppuVar15 = param_3[3];
      if ((*(int *)(iVar13 + (int)ppppppuVar15) == 1) &&
         (*(char *)((int)ppppppuVar15 + iVar13 + 8) == '\x0f')) {
        *(char *)((int)ppppppuVar15 + iVar13 + 8) = (char)local_c024;
      }
      iVar13 = iVar13 + 0x48;
      puVar38 = puVar38 + 0x48;
    } while (iVar13 != 0x9360);
    iVar27 = 0;
    iVar13 = 0;
    iVar47 = 0;
    iVar44 = 0x1a20;
    piVar20 = param_2 + 0x594;
    do {
      uVar22 = *(uint *)((int)local_9c84 + iVar13) | *(uint *)((int)local_88 + iVar13 + 0x188);
      *(uint *)(((unsigned char *)0x000010b8) + (int)(*param_3 + iVar27)) = uVar22;
      if (uVar22 != 0) {
        iVar25 = param_2[0x7c7];
        pbVar26 = (byte *)(piVar20 + 2);
        piVar45 = (int *)((int)param_2 + iVar44);
        iVar31 = iVar47;
        do {
          bVar7 = (byte)uVar22;
          uVar22 = uVar22 >> 1;
          iVar16 = iVar31 + iVar25;
          *pbVar26 = bVar7 & 1;
          iVar31 = iVar31 + 1;
          pbVar26 = pbVar26 + 1;
          *piVar45 = iVar16;
          piVar45 = piVar45 + 1;
        } while (uVar22 != 0);
      }
      bVar3 = iVar27 != 7;
      iVar13 = iVar13 + 4;
      iVar47 = iVar47 + 0x20;
      piVar20 = piVar20 + 8;
      iVar44 = iVar44 + 0x80;
      iVar27 = iVar27 + 1;
    } while (bVar3);
    if (*(int *)(((unsigned char *)0x000010b8) + (int)*param_3) == 0) {
      *(undefined4 *)(((unsigned char *)0x000010d8) + (int)*param_3) = 0;
    }
    for (; iStack_318 != 0; iStack_318 = iStack_318 + -1) {
    }
    if (local_9cc8 != 0) {
      uVar36 = 0;
      uVar22 = local_9cc8;
      do {
        piVar20 = (int *)(uVar36 * 0x24 + (int)local_9cbc);
        switch(piVar20[2]) {
        case 1:
          iVar13 = piVar20[1];
          ppppppuVar15 = *param_3;
          iVar47 = *piVar20;
          if (iVar13 == 1) {
            ppppppuVar17 = ppppppuVar15 + iVar47 * 4 + 0x24;
          }
          else if (iVar13 == 0) {
            ppppppuVar17 = ppppppuVar15 + iVar47 * 4 + 0x23;
          }
          else if (iVar13 == 2) {
            ppppppuVar17 = ppppppuVar15 + iVar47 * 4 + 0x25;
          }
          else {
            ppppppuVar17 = (uint ******)0x0;
            if (iVar13 == 3) {
              ppppppuVar17 = ppppppuVar15 + iVar47 * 4 + 0x26;
            }
          }
          *ppppppuVar17 = (uint *****)piVar20[5];
          uVar22 = local_9cc8;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())FUN_000c8de0)(param_3 + 0x48,piVar20);
          uVar22 = local_9cc8;
        }
        uVar36 = uVar36 + 1;
      } while (uVar36 < uVar22);
    }
    if (local_9c18 != 0) {
      iVar13 = 0;
      pcVar32 = local_9c14;
      if (local_9c18 == 0) {
        local_9c18 = 1;
      }
      do {
        cVar6 = *pcVar32;
        pcVar32 = pcVar32 + 0xc;
        if (cVar6 != '\x02') {
          iVar13 = iVar13 + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_c024 + 2;
        }
        local_9c18 = local_9c18 + -1;
      } while (local_9c18 != 0);
      iVar47 = 1;
      if (8 < iVar13) goto LAB_000ccf90;
    }
    iVar47 = 0;
LAB_000ccf90:
    iVar27 = 0x10;
    iVar13 = 0;
    do {
      param_3[1][iVar13 * 4 + 0x42] = (uint *****)0x0;
      param_3[1][iVar13 * 4 + 0x43] = (uint *****)0x1;
      param_3[1][iVar13 * 4 + 0x44] = (uint *****)0x2;
      param_3[1][iVar13 * 4 + 0x45] = (uint *****)0x3;
      iVar27 = iVar27 + -1;
      iVar13 = iVar13 + 1;
    } while (iVar27 != 0);
    _free(local_9cbc);
    _free(pvVar19);
    if (pvVar18 != (void *)0x0) {
      _free(pvVar18);
    }
    if (puVar35 != (uint *)0x0) {
      _free(puVar35);
    }
    return iVar47;
  }
  ppppppuVar15 = (uint ******)*puVar23;
  uVar12 = (uint)ppppppuVar15 & 0xffff;
  if (100 < uVar12) {
switchD_000cb23c_caseD_0:
                    
    _exit(0);
  }
  puVar24 = puVar23;
  switch(uVar12) {
  case 0:
  case 0x17:
  case 0x1b:
  case 0x36:
  case 0x42:
  case 0x43:
  case 0x4f:
  case 0x5f:
  case 0x60:
  case 0x61:
    goto switchD_000cb23c_caseD_0;
  default:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar21,puVar23,puVar23,in_r8,local_88,
                                pppppppuVar29);
    }
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,1,local_88);
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 3:
  case 0xc:
  case 0x13:
  case 0x1f:
  case 0x20:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x49:
  case 0x4e:
  case 0x52:
  case 0x56:
  case 0x5b:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar21,puVar23,puVar23,in_r8,local_88,
                                pppppppuVar29);
    }
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,2,local_88);
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar23 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar21 = (uint *******)0x0;
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,0,2,&local_c08c);
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_c1f4 = ppppppuVar15;
    local_c1f8 = puVar23 + 2;
    local_c1f4[1] = (uint ******)puVar23[1];
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4 + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_c1f4 = ppppppuVar15;
    local_c1f4[1] = (uint ******)puVar23[1];
    local_c1f8 = puVar23 + 3;
    local_c1f4[2] = (uint ******)puVar23[2];
    puVar24 = local_c1f8;
    pppppppuVar29 = local_c1f4 + 3;
    pppppppuVar37 = local_c1f4 + 3;
    goto switchD_000cbc48_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar21,puVar23,puVar23,in_r8,local_88,
                                pppppppuVar29);
    }
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,3,local_88);
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    local_c1f8 = puVar23 + 2;
    *local_c1f4 = ppppppuVar15;
    local_c1f4[1] = (uint ******)puVar23[1];
    pppppppuVar37 = local_c1f4 + 2;
    for (uVar12 = (uint)*(ushort *)((int)puVar23 + 6); puVar24 = local_c1f8, uVar12 != 0;
        uVar12 = uVar12 - 1) {
      ppppppuVar15 = (uint ******)*local_c1f8;
      local_c1f8 = local_c1f8 + 1;
      *pppppppuVar37 = ppppppuVar15;
      pppppppuVar37 = pppppppuVar37 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    local_c1f8 = puVar23 + 1;
    if (((uint)ppppppuVar15 & 0x18000000) == 0) {
      uVar12 = *(uint *)((int)local_9dd4 + ((uint)ppppppuVar15 >> 0xe & 0x3fc));
      if (uVar12 != 2) {
        uVar12 = 1;
      }
      ppppppuVar15 = (uint ******)((uVar12 & 3) << 0x1b | (uint)ppppppuVar15 & 0xe7ffffff);
    }
    *local_c1f4 = ppppppuVar15;
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    local_c1f8 = puVar23 + 1;
    *local_c1f4 = ppppppuVar15;
    pppppppuVar29 = local_c1f4 + 1;
    if ((int)ppppppuVar15 < 0) {
      ppppppuVar15 = (uint ******)*local_c1f8;
      local_c1f8 = puVar23 + 2;
      local_c1f4[1] = ppppppuVar15;
      pppppppuVar29 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar29;
    ppppppuVar15 = (uint ******)*local_c1f8;
    local_c1f8 = local_c1f8 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar24 = local_c1f8;
    pppppppuVar29 = pppppppuVar37;
    pppppppuVar37 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    local_c1f8 = puVar23 + 1;
    pppppppuVar21 = local_c1f4 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar24 = local_c1f8;
    pppppppuVar37 = pppppppuVar21;
    if ((puVar23[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_c1f4[1] = (uint ******)puVar23[1];
      in_r8 = local_c1f4 + 6;
      local_c1f4[2] = (uint ******)puVar23[2];
      local_c1f4[3] = (uint ******)puVar23[3];
      local_c1f4[4] = (uint ******)puVar23[4];
      local_c1f8 = puVar23 + 6;
      local_c1f4[5] = (uint ******)puVar23[5];
      puVar24 = local_c1f8;
      pppppppuVar29 = local_c1f4 + 5;
      pppppppuVar37 = in_r8;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    local_c1f8 = puVar23 + 1;
    puVar46 = (undefined4 *)
              ((int (*)())FUN_000c7930)(local_c1f4,&local_c08c,pppppppuVar21,puVar23,local_c1f8,in_r8,uVar12 * 4)
    ;
    *puVar46 = ppppppuVar15;
    puVar24 = local_c1f8;
    pppppppuVar37 = (uint *******)(puVar46 + 1);
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    pppppppuVar21 = &local_c08c;
    *local_c1f4 = ppppppuVar15;
    local_c1f8 = puVar23 + 2;
    local_c1c0[0] = (uint ******)puVar23[1];
    local_c1f4 = local_c1f4 + 1;
    ((int (*)())FUN_000c8760)(local_c1c0,auStack_c1b4,pppppppuVar21);
    *local_c1f4 = local_c1c0[0];
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar21 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar21 = (uint *******)((int)&MACH_HEADER.magic + 1);
    break;
  case 0x5d:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar21,puVar23,puVar23,in_r8,local_88,
                                pppppppuVar29);
      puVar23 = local_c1f8;
    }
    ppppppuVar15 = (uint ******)*puVar23;
    puVar24 = puVar23 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar28 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar24 = puVar23 + 2;
      ppppppuVar17 = (uint ******)puVar23[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 >> 0x1e & 1) != 0;
    if (bVar1) {
      ppppppuVar40 = (uint ******)*puVar24;
      puVar24 = puVar24 + 1;
    }
    else {
      ppppppuVar40 = (uint ******)0x0;
    }
    local_c1f0 = (uint *******)*puVar24;
    puVar23 = puVar24 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar23 = puVar24 + 2;
      unaff_r15 = (uint ******)puVar24[1];
    }
    local_c1cc = (uint ******)*puVar23;
    local_c1f8 = puVar23 + 1;
    if (((uint)local_c1cc & 0x400000) != 0) {
      local_c1d8 = (uint ******)puVar23[1];
      local_c1f8 = puVar23 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc2a4:
      if (local_c01c << (uVar12 & 0x3f) == 0) {
        local_84 = (uint ******)&local_c1cc;
        pppppppuVar37 = (uint *******)0x0;
        uVar43 = 1 << (uVar12 & 0x3f);
        ppppppuVar14 = (uint ******)&local_c1d8;
      }
      else {
        local_84 = (uint ******)&local_c1cc;
        local_70 = (uint ******)&local_c1d8;
        local_c1f4 = (uint *******)((int (*)())FUN_000c7460)(local_88,local_84,local_70,uVar28,local_c1f4);
        ppppppuVar14 = local_70;
        if (((uint)local_c1f0 & 0x400000) == 0) {
          pppppppuVar37 = (uint *******)0x0;
          uVar43 = 1 << (uVar12 & 0x3f);
        }
        else {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          pppppppuVar37 = (uint *******)((int)&MACH_HEADER.magic + 1);
          uVar43 = 1 << (uVar12 & 0x3f);
          local_c1e4 = unaff_r15;
        }
      }
    }
    else if (uVar9 == 0x8000000) {
      uVar43 = 1 << (uVar12 & 0x3f);
      if ((uVar43 & local_c018) != 0) goto LAB_000cc2a4;
      local_84 = (uint ******)&local_c1cc;
      pppppppuVar37 = (uint *******)0x0;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    else {
      pppppppuVar37 = (uint *******)0x0;
      uVar43 = 1 << (uVar12 & 0x3f);
      local_84 = (uint ******)&local_c1cc;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    pppppppuVar21 = local_88;
    ((int (*)())FUN_000c8760)(local_84,ppppppuVar14,local_88);
    *local_c1f4 = ppppppuVar15;
    pppppppuVar29 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = ppppppuVar17;
      pppppppuVar29 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar29;
    if (bVar1) {
      *local_c1f4 = ppppppuVar40;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = (uint ******)local_c1f0;
    pppppppuVar29 = local_c1f4 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r15;
      pppppppuVar29 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar29;
    *local_c1f4 = local_c1cc;
    pppppppuVar29 = (uint *******)((uint)local_c1cc & 0x400000);
    pppppppuVar11 = local_c1f4 + 1;
    if (pppppppuVar29 != (uint *******)0x0) {
      local_c1f4[1] = local_c1d8;
      pppppppuVar11 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar11;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar43 & local_c018) != 0)))) &&
       (local_c01c << (uVar12 & 0x3f) != 0)) {
      pppppppuVar21 = (uint *******)&local_c1f0;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c7650)(local_88,local_84,pppppppuVar21,&local_c1e4,uVar28,pppppppuVar37,
                                local_c1f4,pppppppuVar29);
      in_r8 = pppppppuVar37;
    }
    uVar43 = uVar43 & local_c01c;
    ppppppuVar15 = unaff_r15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,&local_c08c,pppppppuVar21,puVar23,puVar23,in_r8,
                                uVar12 * 4,pppppppuVar29);
      puVar23 = local_c1f8;
    }
    ppppppuVar15 = (uint ******)*puVar23;
    puVar24 = puVar23 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar28 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar24 = puVar23 + 2;
      ppppppuVar17 = (uint ******)puVar23[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 & 0x40000000) != 0;
    if (bVar1) {
      ppppppuVar40 = (uint ******)*puVar24;
      puVar24 = puVar24 + 1;
    }
    else {
      ppppppuVar40 = (uint ******)0x0;
    }
    local_c1f0 = (uint *******)*puVar24;
    puVar23 = puVar24 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar23 = puVar24 + 2;
      unaff_r14 = (uint ******)puVar24[1];
    }
    local_c1d8 = (uint ******)*puVar23;
    puVar24 = puVar23 + 1;
    if (((uint)local_c1d8 & 0x400000) != 0) {
      local_c1cc = (uint ******)puVar23[1];
      puVar24 = puVar23 + 2;
    }
    local_c1d4 = (uint ******)*puVar24;
    local_c1f8 = puVar24 + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      local_c1c8 = (uint ******)puVar24[1];
      local_c1f8 = puVar24 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc588:
      if (local_c01c << (uVar12 & 0x3f) != 0) {
        pppppppuVar21 = &local_c1cc;
        local_c1f4 = (uint *******)
                     ((int (*)())FUN_000c7460)(&local_c08c,&local_c1d8,pppppppuVar21,uVar28,local_c1f4);
        if (((uint)local_c1f0 & 0x400000) != 0) {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          in_r8 = (uint *******)((int)&MACH_HEADER.magic + 1);
          uVar43 = 1 << (uVar12 & 0x3f);
          local_c1e4 = unaff_r14;
          goto LAB_000cc5e4;
        }
      }
LAB_000cc5bc:
      in_r8 = (uint *******)0x0;
      uVar43 = 1 << (uVar12 & 0x3f);
    }
    else {
      if (uVar9 != 0x8000000) goto LAB_000cc5bc;
      in_r8 = (uint *******)0x0;
      uVar43 = 1 << (uVar12 & 0x3f);
      if ((uVar43 & local_c018) != 0) goto LAB_000cc588;
    }
LAB_000cc5e4:
    *local_c1f4 = ppppppuVar15;
    pppppppuVar29 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = ppppppuVar17;
      pppppppuVar29 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar29;
    if (bVar1) {
      *local_c1f4 = ppppppuVar40;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = (uint ******)local_c1f0;
    pppppppuVar29 = local_c1f4 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r14;
      pppppppuVar29 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar29;
    *local_c1f4 = local_c1d8;
    pppppppuVar29 = (uint *******)((uint)local_c1d8 & 0x400000);
    pppppppuVar37 = local_c1f4 + 1;
    if (pppppppuVar29 != (uint *******)0x0) {
      local_c1f4[1] = local_c1cc;
      pppppppuVar37 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar37;
    *local_c1f4 = local_c1d4;
    pppppppuVar37 = local_c1f4 + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      local_c1f4[1] = local_c1c8;
      pppppppuVar37 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar37;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar43 & local_c018) != 0)))) &&
       (local_c01c << (uVar12 & 0x3f) != 0)) {
      pppppppuVar21 = (uint *******)&local_c1f0;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_c08c,&local_c1d8,pppppppuVar21,&local_c1e4,uVar28,in_r8,
                                local_c1f4,pppppppuVar29);
    }
    uVar43 = uVar43 & local_c01c;
    ppppppuVar15 = unaff_r14;
joined_r0x000cc708:
    puVar24 = local_c1f8;
    pppppppuVar37 = local_c1f4;
    if (uVar43 != 0) {
      in_r8 = local_c1f4 + 1;
      *local_c1f4 = (uint ******)0x47;
      pppppppuVar29 = local_c1f0;
      if (((uint)local_c1f0 & 0x400000) == 0) {
        pppppppuVar29 = (uint *******)((uint)local_c1f0 | 0x400000);
        ppppppuVar15 = (uint ******)0x55;
      }
      if (local_bf94[uVar28] == 0x1906) {
        if (((uint)ppppppuVar15 & 3) == 1) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xfffffffc | 2);
        }
        if (((uint)ppppppuVar15 & 0xc) == 4) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xfffffff3 | 8);
        }
        if (((uint)ppppppuVar15 & 0x30) == 0x10) {
          ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffffcf | 0x20);
        }
      }
      else if ((local_bf94[uVar28] == 0x1909) && (((uint)ppppppuVar15 & 0xc0) == 0x40)) {
        ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffff3f | 0xc0);
      }
      *in_r8 = (uint ******)pppppppuVar29;
      local_c1f4[2] = ppppppuVar15;
      local_c1f4[3] = (uint ******)((uint)pppppppuVar29 & 0x3fffff);
      pppppppuVar37 = local_c1f4 + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,pppppppuVar21,1,&local_c08c);
  puVar24 = local_c1f8;
  pppppppuVar37 = local_c1f4;
  goto switchD_000cbc48_caseD_18;
}

/* FUN_000cd05c @ 0xcd05c (176 bytes) */
int FUN_000cd05c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if ((((((param_1 == 0) || (*(code **)(param_1 + 0x30) == (code *)0x0)) ||
        (*(int *)(param_1 + 0x34) == 0)) ||
       ((*(int *)(param_1 + 0x38) == 0 || (*(int *)(param_1 + 0x40) == 0)))) ||
      ((*(int *)(param_1 + 0x44) == 0 ||
       ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x4c) == 0)))))) ||
     ((param_2 == 0 ||
      (iVar1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x2c),0x44), iVar1 == 0)))) {
    iVar1 = 0;
  }
  else {
    FUN_000da0c0(iVar1,param_1);
    iVar2 = FUN_000da420(iVar1);
    if (iVar2 != 0) {
      FUN_000da458(iVar1,1);
      (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x2c),iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

/* FUN_000cd15c @ 0xcd15c (84 bytes) */
int FUN_000cd15c(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *unaff_r30;
  byte in_cr0;
  
  uVar1 = 3;
  if (!(bool)(in_cr0 >> 1 & 1)) {
    pcVar2 = (code *)*unaff_r30;
    uVar1 = unaff_r30[1];
    FUN_000da458(param_1,1);
    (*pcVar2)(uVar1,unaff_r30);
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_000cd1b0 @ 0xcd1b0 (20 bytes) */
int FUN_000cd1b0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_000da394(param_1,param_2,param_3);
    return uVar1;
  }
  return 3;
}

/* FUN_000cd1c4 @ 0xcd1c4 (92 bytes) */
int FUN_000cd1c4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  if (param_1 == 0) {
    return 3;
  }
  iStack00000018 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x3c) = param_4;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  if (iStack00000018 != 0) {
    uStack00000028 = *(undefined4 *)(param_2 + 0x54);
    uStack00000024 = *(undefined4 *)(param_3 + 0x4c);
    uStack00000020 = *(undefined4 *)(param_2 + 0x4c);
    *(int *)(iStack00000018 + 0x398) = param_1;
    iStack0000001c = param_4;
    FUN_000e0ca8(iStack00000018);
    do {
      iVar1 = _setjmp(*(int **)(iStack00000018 + 4));
      if (iVar1 == 0) {
        FUN_000e1888(iStack00000018);
        FUN_000e0cd0(iStack00000018,uStack00000028);
        iVar1 = FUN_00193b3c(uStack00000020,uStack00000024,iStack00000018);
        *(int *)(iStack00000018 + 0x524) = iStack0000001c;
        *(undefined4 *)(iStack0000001c + 0xf8) = 0;
        *(undefined4 *)(iStack0000001c + 0xfc) =
             *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
        FUN_000e2094(iStack00000018,iVar1);
        if (iVar1 != 0) {
          FUN_00193be8(iVar1);
          FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
        }
      }
      *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
      *(undefined4 *)(iStack00000018 + 0x484) = 0;
      *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
      *(undefined4 *)(iStack00000018 + 0x488) = 0;
      iVar1 = *(int *)(iStack00000018 + 0x314);
      FUN_000e0e28(iStack00000018);
      FUN_000e1fe4(iStack00000018,0);
    } while ((iVar1 != 0) && (iVar2 = FUN_000e161c(iStack00000018,iVar1), iVar2 != 0));
    return iVar1;
  }
  return 2;
}

/* FUN_000cd1d8 @ 0xcd1d8 (20 bytes) */
int FUN_000cd1d8(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return 3;
  }
  return 0;
}

/* FUN_000cd1ec @ 0xcd1ec (40 bytes) */
int FUN_000cd1ec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uStack00000024;
  
  uStack00000024 = param_4;
  ((int (*)())FUN_000cd388)(param_1,param_2,param_3,&STACKARG(0x24));
  return;
}

/* FUN_000cd214 @ 0xcd214 (40 bytes) */
int FUN_000cd214(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cd404)(param_1,param_2,&STACKARG(0x20),param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000cd23c @ 0xcd23c (40 bytes) */
int FUN_000cd23c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack00000028;
  
  uStack00000028 = param_5;
  ((int (*)())FUN_000cdba4)(param_1,param_2,param_3,param_4,&STACKARG(0x28),param_6,param_7);
  return;
}

/* FUN_000cd264 @ 0xcd264 (40 bytes) */
int FUN_000cd264(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cdbe4)(param_1,param_2,&STACKARG(0x20),param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000cd290 @ 0xcd290 (88 bytes) */
int FUN_000cd290(param_1)
  undefined4 param_1;
{
  switch(param_1) {
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
    return 1;
  case 0x1d:
  case 0x38:
  case 0x3a:
  case 0x3b:
    return 2;
  default:
    return 0;
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
    return 3;
  }
}

/* FUN_000cd388 @ 0xcd388 (28 bytes) */
int FUN_000cd388(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_4 == 0) {
    return;
  }
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  FUN_000e06d8(param_1,param_2,param_3,param_4);
  return;
}

/* FUN_000cd3a4 @ 0xcd3a4 (96 bytes) */
int FUN_000cd3a4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  (*(code *)*param_2)(param_1,"",param_3,&STACKARG(0x24));
  return;
}

/* FUN_000cd404 @ 0xcd404 (1952 bytes) */
int FUN_000cd404(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int *param_2;
  int param_3;
  undefined4 param_4;
  char *param_5;
  undefined1 *param_6;
  undefined1 *param_7;
  undefined1 *param_8;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char acStack_238 [128];
  undefined1 auStack_1b8 [128];
  undefined1 auStack_138 [128];
  undefined1 auStack_b8 [144];
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"; ------------- SC_SRCSHADER Dump ------------------\r\n",param_4,
               param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntVSConst = %d\r\n",param_2[3],param_5,
               param_6,param_7,param_8);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntPSConst = %d\r\n",param_2[4],param_5,
               param_6,param_7,param_8);
  uVar2 = param_2[5];
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntGSConst = %d\r\n",uVar2,param_5,param_6,
               param_7,param_8);
  if (((param_2[3] != 0) && (*param_2 != 0)) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer VS Constants",uVar2,param_5,
                   param_6,param_7,param_8), param_2[3] != 0)) {
    uVar4 = 0;
    do {
      uVar2 = uVar4;
      iVar3 = uVar2 * 0x10 + *param_2;
      param_5 = *(char **)(uVar2 * 0x10 + *param_2);
      param_6 = *(undefined1 **)(iVar3 + 4);
      param_7 = *(undefined1 **)(iVar3 + 8);
      uVar4 = uVar2 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar2,param_5,
                   param_6,param_7,param_8);
    } while (uVar4 < (uint)param_2[3]);
  }
  if ((param_2[4] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer PS Constants",uVar2,param_5,
                   param_6,param_7,param_8), param_2[4] != 0)) {
    uVar4 = 0;
    do {
      uVar2 = uVar4;
      iVar3 = uVar2 * 0x10 + param_2[1];
      param_5 = *(char **)(uVar2 * 0x10 + param_2[1]);
      param_6 = *(undefined1 **)(iVar3 + 4);
      param_7 = *(undefined1 **)(iVar3 + 8);
      uVar4 = uVar2 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar2,param_5,
                   param_6,param_7,param_8);
    } while (uVar4 < (uint)param_2[4]);
  }
  if ((param_2[5] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer GS Constants",uVar2,param_5,
                   param_6,param_7,param_8), param_2[5] != 0)) {
    uVar2 = 0;
    do {
      iVar3 = uVar2 * 0x10 + param_2[2];
      param_5 = *(char **)(uVar2 * 0x10 + param_2[2]);
      param_6 = *(undefined1 **)(iVar3 + 4);
      param_7 = *(undefined1 **)(iVar3 + 8);
      uVar4 = uVar2 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar2,param_5,
                   param_6,param_7,param_8);
      uVar2 = uVar4;
    } while (uVar4 < (uint)param_2[5]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolVSConst = %d\r\n",param_2[9],param_5,
               param_6,param_7,param_8);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolPSConst = %d\r\n",param_2[10],param_5,
               param_6,param_7,param_8);
  uVar2 = param_2[0xb];
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolGSConst = %d\r\n",uVar2,param_5,param_6,
               param_7,param_8);
  if (param_2[9] == 0) goto LAB_000cd7d0;
  if (param_2[6] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool VS Constants",uVar2,param_5,param_6,
                 param_7,param_8);
    if (param_2[9] == 0) goto LAB_000cd7d0;
    uVar4 = 0;
    do {
      param_7 = (undefined1 *)param_2[6];
      if (*(int *)(param_7 + uVar4 * 4) == 0) {
        param_5 = "FALSE";
      }
      else {
        param_5 = "TRUE";
      }
      uVar2 = uVar4;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar4,param_5,param_6,param_7,
                   param_8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)param_2[9]);
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if (param_2[7] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool PS Constants",uVar2,param_5,param_6,
                 param_7,param_8);
    if (param_2[10] != 0) {
      uVar4 = 0;
      do {
        param_7 = (undefined1 *)param_2[7];
        if (*(int *)(param_7 + uVar4 * 4) == 0) {
          param_5 = "FALSE";
        }
        else {
          param_5 = "TRUE";
        }
        uVar2 = uVar4;
        ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar4,param_5,param_6,param_7,
                     param_8);
        uVar4 = uVar4 + 1;
      } while (uVar4 < (uint)param_2[10]);
    }
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if ((param_2[8] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool GS Constants",uVar2,param_5,param_6
                   ,param_7,param_8), param_2[0xb] != 0)) {
    uVar2 = 0;
    do {
      param_7 = (undefined1 *)param_2[8];
      if (*(int *)(param_7 + uVar2 * 4) == 0) {
        param_5 = "FALSE";
      }
      else {
        param_5 = "TRUE";
      }
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar2,param_5,param_6,param_7,
                   param_8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)param_2[0xb]);
  }
LAB_000cd7d0:
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatVSConst = %d\r\n",param_2[0xf],param_5,
               param_6,param_7,param_8);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatPSConst = %d\r\n",param_2[0x10],param_5,
               param_6,param_7,param_8);
  uVar2 = param_2[0x11];
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatGSConst = %d\r\n",uVar2,param_5,param_6,
               param_7,param_8);
  if (((param_2[0xf] != 0) && (param_2[0xc] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float VS Constants",uVar2,
                           param_5,param_6,param_7,param_8), param_2[0xf] != 0)) {
    uVar4 = 0;
    do {
      uVar2 = uVar4;
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,acStack_238);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_138);
      ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_b8);
      param_5 = acStack_238;
      uVar4 = uVar2 + 1;
      param_6 = auStack_1b8;
      param_7 = auStack_138;
      param_8 = auStack_b8;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           auStack_1b8,auStack_138,auStack_b8);
    } while (uVar4 < (uint)param_2[0xf]);
  }
  if (((param_2[0x10] != 0) && (param_2[0xd] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float PS Constants",uVar2,
                           param_5,param_6,param_7,param_8), param_2[0x10] != 0)) {
    uVar4 = 0;
    do {
      uVar2 = uVar4;
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,acStack_238);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_138);
      ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_b8);
      param_5 = acStack_238;
      uVar4 = uVar2 + 1;
      param_6 = auStack_1b8;
      param_7 = auStack_138;
      param_8 = auStack_b8;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           auStack_1b8,auStack_138,auStack_b8);
    } while (uVar4 < (uint)param_2[0x10]);
  }
  if (((param_2[0x11] != 0) && (param_2[0xe] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float GS Constants",uVar2,
                           param_5,param_6,param_7,param_8), param_2[0x11] != 0)) {
    uVar2 = 0;
    do {
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,acStack_238);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8);
      uVar1 = ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_138);
      ((int (*)())FUN_000cdc3c)(uVar1,10,auStack_b8);
      param_5 = acStack_238;
      uVar4 = uVar2 + 1;
      param_6 = auStack_1b8;
      param_7 = auStack_138;
      param_8 = auStack_b8;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           auStack_1b8,auStack_138,auStack_b8);
      uVar2 = uVar4;
    } while (uVar4 < (uint)param_2[0x11]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"u32Copts = 0x%08X",param_2[0x15],param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"fConstantsAvailable = %d",param_2[0x16],param_2[0x17],param_2[0x18],
               param_2[0x19],param_2[0x1a]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"iConstantsAvailable = %d",param_2[0x1e],param_2[0x1f],param_2[0x20],
               param_2[0x21],param_2[0x22]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"bConstantsAvailable = %d",param_2[0x26],param_2[0x27],param_2[0x28],
               param_2[0x29],param_2[0x2a]);
  return;
}

/* FUN_000cdba4 @ 0xcdba4 (64 bytes) */
int FUN_000cdba4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (param_2 == 0) {
    return;
  }
  if (param_5 == 0) {
    return;
  }
  if (2 < *(int *)(param_2 + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(param_2 + 0xf8) == 0) {
    ((int (*)())FUN_000d035c)(param_1,param_2,param_3,param_5,param_5,param_6,param_2);
    return;
  }
  if (*(int *)(param_2 + 0xf8) != 1) {
    return;
  }
  FUN_000d4e8c(param_1,param_2,param_3,param_5,param_5,param_6,param_2);
  return;
}

/* FUN_000cdbe4 @ 0xcdbe4 (60 bytes) */
int FUN_000cdbe4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (param_2 == 0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  if (2 < *(int *)(param_2 + 0xfc) - 1U) {
    return;
  }
  if (*(int *)(param_2 + 0xf8) == 0) {
    ((int (*)())FUN_000d0304)(param_1,param_2,param_3,param_4,param_5,param_6,param_2);
    return;
  }
  if (*(int *)(param_2 + 0xf8) != 1) {
    return;
  }
  FUN_000d4e64();
  return;
}

/* FUN_000cdc20 @ 0xcdc20 (4 bytes) */
int FUN_000cdc20()
{
  return;
}

/* FUN_000cdc24 @ 0xcdc24 (24 bytes) */
int FUN_000cdc24(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x4c) == 0) {
    return 1;
  }
  return *(undefined1 *)(*(int *)(param_1 + 0x4c) + 5);
}

/* FUN_000cdc3c @ 0xcdc3c (996 bytes) */
int FUN_000cdc3c(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  char *param_3;
{
  double dVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  double in_f1;
  double dVar12;
  double dVar13;
  double dVar14;
  uint local_98;
  
  pcVar6 = _ecvt(in_f1,param_1,param_2,param_2);
  if ((1 - (int)param_2 < 1) && (-1 < (int)param_2)) {
    *param_3 = '0';
    param_3[1] = '.';
    uVar9 = 2;
    if (*pcVar6 != '\0') {
      iVar7 = 0;
      pcVar8 = pcVar6;
      do {
        if (iVar7 == -1) {
          param_3[uVar9] = '.';
          uVar9 = uVar9 + 1;
        }
        iVar7 = iVar7 + 1;
        param_3[uVar9] = *pcVar8;
        uVar9 = uVar9 + 1;
        pcVar8 = pcVar6 + iVar7;
      } while (pcVar6[iVar7] != '\0');
    }
    param_3[uVar9] = '\0';
    cVar5 = *param_3;
    uVar11 = uVar9;
    if (cVar5 != '\0') {
      iVar7 = 0;
      do {
        if (cVar5 != '0') {
          if (cVar5 == '.') {
            uVar11 = uVar9;
            if (iVar7 + 2U < uVar9) {
              uVar11 = iVar7 + 2U;
            }
          }
          else {
            uVar11 = iVar7 + 1;
          }
        }
        iVar7 = iVar7 + 1;
        cVar5 = param_3[iVar7];
      } while (cVar5 != '\0');
    }
    param_3[uVar11] = '\0';
  }
  else {
    *param_3 = *pcVar6;
    param_3[1] = '.';
    iVar7 = 2;
    cVar5 = pcVar6[1];
    if (cVar5 != '\0') {
      pcVar8 = param_3 + 2;
      iVar3 = 1;
      do {
        *pcVar8 = cVar5;
        iVar3 = iVar3 + 1;
        cVar5 = pcVar6[iVar3];
        iVar7 = iVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar5 != '\0');
    }
    param_3[iVar7] = 'e';
    param_3[iVar7 + 1] = '-';
    local_98 = 1;
    dVar12 = (double)_log((double)(float)(4503601774854145.0 - DOUBLE_001aa1e0));
    dVar13 = (double)_log(DOUBLE_001aa238);
    dVar2 = DOUBLE_001aa1e8;
    dVar1 = DOUBLE_001aa1e0;
    dVar12 = dVar12 / dVar13;
    if (DOUBLE_001aa1e8 <= dVar12) {
      uVar9 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar9 = (uint)dVar12;
    }
    uVar10 = 0;
    pcVar6 = param_3 + iVar7 + 2;
    uVar11 = uVar9;
    do {
      dVar14 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - dVar1;
      dVar13 = (double)_pow(DOUBLE_001aa238,dVar14);
      dVar12 = DOUBLE_001aa238;
      if (dVar2 <= dVar13) {
        uVar4 = (int)(dVar13 - dVar2) + 0x80000000;
      }
      else {
        uVar4 = (uint)dVar13;
      }
      cVar5 = (char)(local_98 / uVar4);
      *pcVar6 = cVar5 + '0';
      dVar12 = (double)_pow(dVar12,dVar14);
      if (DOUBLE_001aa1e8 <= dVar12) {
        iVar3 = (int)(dVar12 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar3 = (int)dVar12;
      }
      uVar10 = uVar10 + 1;
      pcVar6 = pcVar6 + 1;
      uVar11 = uVar11 - 1;
      local_98 = local_98 - cVar5 * iVar3;
    } while (uVar10 <= uVar9);
    param_3[uVar10 + iVar7 + 2] = '\0';
  }
  return param_3;
}

/* FUN_000ce020 @ 0xce020 (24 bytes) */
int FUN_000ce020(param_1)
  undefined4 *param_1;
{
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

/* FUN_000ce038 @ 0xce038 (24 bytes) */
int FUN_000ce038(param_1)
  undefined4 *param_1;
{
  param_1[3] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

/* FUN_000ce050 @ 0xce050 (248 bytes) */
int FUN_000ce050(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  char cVar1;
  char *pcVar2;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_a4 [152];
  
  if (*(int *)(param_1 + 8) != 0) {
    uStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    uStack00000034 = param_8;
    FUN_001a34d4(acStack_a4,param_2,&STACKARG(0x20),param_4,param_5,param_6,param_7,param_8);
    pcVar2 = _strchr(acStack_a4,0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    FUN_001a32d0(acStack_a4,"%s\n",acStack_a4,param_4,param_5,param_6,param_7,param_8);
    (*(code *)**(undefined4 **)(param_1 + 8))
              (*(undefined4 *)(param_1 + 0xc),"",acStack_a4,&STACKARG(0x20));
  }
  return;
}

/* FUN_000ce148 @ 0xce148 (464 bytes) */
int FUN_000ce148(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 in_r10;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char acStack_48 [32];
  
  uVar6 = *param_2;
  uVar2 = uVar6 & 0x1e000000;
  uVar9 = uVar6 & 0x80000010;
  uVar3 = uVar6 & 0xf;
  uVar4 = uVar6 & 0x1ffe000;
  *param_3 = '\0';
  uVar8 = uVar6 >> 0x1d;
  uVar10 = uVar6 >> 5;
  if (uVar2 == 0x1e000000) {
    uVar7 = 0;
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = '-';
    (param_3 + sVar5)[1] = '\0';
  }
  else {
    uVar7 = -uVar2 >> 0x1f;
  }
  if (uVar3 == 1) {
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = 'v';
    (param_3 + sVar5)[1] = '\0';
  }
  else if (uVar3 == 0) {
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = 'r';
    (param_3 + sVar5)[1] = '\0';
  }
  else if (uVar3 == 2) {
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = 'c';
    (param_3 + sVar5)[1] = '\0';
  }
  else if (uVar3 == 3) {
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = 't';
    (param_3 + sVar5)[1] = '\0';
  }
  else {
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = '?';
    (param_3 + sVar5)[1] = '\0';
  }
  FUN_001a32d0(acStack_48,"%d",uVar10 & 0xff,in_r6,in_r7,in_r8,uVar6,in_r10);
  if (uVar9 == 0) {
    _strcat(param_3,acStack_48);
  }
  else {
    if (uVar9 == 0x10) {
      sVar5 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar5,"[a0",4);
    }
    else {
      sVar5 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar5,"[i0",4);
    }
    switch(uVar8 & 3) {
    case 0:
      _strcat(param_3,".x");
      break;
    case 1:
      _strcat(param_3,".y");
      break;
    case 2:
      _strcat(param_3,".z");
      break;
    case 3:
      _strcat(param_3,".w");
      break;
    default:
      _strcat(param_3,".?");
    }
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = '+';
    (param_3 + sVar5)[1] = '\0';
    _strcat(param_3,acStack_48);
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = ']';
    (param_3 + sVar5)[1] = '\0';
  }
  if ((uVar4 != 0xd10000) || (uVar7 != 0)) {
    uVar8 = 0;
    sVar5 = _strlen(param_3);
    (param_3 + sVar5)[0] = '.';
    (param_3 + sVar5)[1] = '\0';
    uVar10 = 0xd;
    do {
      if (((uVar2 & 0x2000000 << (uVar8 & 0x3f)) != 0) && (uVar7 != 0)) {
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = '-';
        (param_3 + sVar5)[1] = '\0';
      }
      switch((uVar4 & 7 << (uVar10 & 0x3f)) >> (uVar10 & 0x3f)) {
      case 0:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = 'x';
        (param_3 + sVar5)[1] = '\0';
        break;
      case 1:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = 'y';
        (param_3 + sVar5)[1] = '\0';
        break;
      case 2:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = 'z';
        (param_3 + sVar5)[1] = '\0';
        break;
      case 3:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = 'w';
        (param_3 + sVar5)[1] = '\0';
        break;
      case 4:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = '0';
        (param_3 + sVar5)[1] = '\0';
        break;
      case 5:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = '1';
        (param_3 + sVar5)[1] = '\0';
        break;
      default:
        sVar5 = _strlen(param_3);
        (param_3 + sVar5)[0] = '?';
        (param_3 + sVar5)[1] = '\0';
      }
      bVar1 = uVar8 != 3;
      uVar10 = uVar10 + 3;
      uVar8 = uVar8 + 1;
    } while (bVar1);
  }
  return param_2 + 1;
}

/* FUN_000ce4e4 @ 0xce4e4 (48 bytes) */
int FUN_000ce4e4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((*param_2 & 1) == 0) {
    return;
  }
  ((int (*)())FUN_000ce050)(param_1,";    v%d = dx v%d",(uint)*(byte *)(param_2 + 1),
               (uint)*(byte *)((int)param_2 + 1),param_5,param_6,param_7,0xce4ec);
  return;
}

/* FUN_000ce514 @ 0xce514 (864 bytes) */
int FUN_000ce514(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  bool bVar1;
  byte bVar2;
  char *acVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  undefined1 *puVar10;
  uint uVar11;
  int iVar12;
  char local_218 [12];
  uint local_20c [5];
  char local_1f8 [4];
  char local_1f4;
  char acStack_1f3 [3];
  char local_1f0;
  char acStack_1ef [3];
  char local_1ec;
  undefined1 auStack_1b8 [128];
  undefined1 auStack_138 [64];
  undefined1 auStack_f8 [64];
  undefined1 auStack_b8 [64];
  char acStack_78 [76];
  
  if ((*(uint *)param_2 & 1) != 0) {
    acVar3 = acStack_1ef;
    switch(*param_2) {
    case '\0':
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pos_001a62cc) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_pos_001a62cc) + 5));
      local_1f4 = s_IL_pos_001a62cc[4];
      pcVar7 = "IL_pos";
      break;
    case '\x01':
      param_8 = (uint)(byte)s_IL_pointsize_001a62d4[0xc];
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 8));
      local_1ec = s_IL_pointsize_001a62d4[0xc];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      break;
    case '\x02':
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 4));
      local_1f0 = s_IL_color_001a62e4[8];
      local_1f0 = CONCAT13(local_1f0,acVar3);
      pcVar7 = "IL_color";
      break;
    case '\x03':
      param_8 = (uint)(byte)s_IL_backcolor_001a62f0[0xc];
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 8));
      local_1ec = s_IL_backcolor_001a62f0[0xc];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      break;
    case '\x04':
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_fog_001a6300) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_fog_001a6300) + 5));
      local_1f4 = s_IL_fog_001a6300[4];
      pcVar7 = "IL_fog";
      break;
    case '\x05':
      param_8 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      local_1f0 = s_IL_generic_001a6308[8];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      break;
    default:
      param_8 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      local_1f0 = s_IL_unknown_001a6314[8];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
    }
    FUN_001a32d0(local_218 + 4,"%d",(uint)(byte)param_2[1],param_4,param_5,param_6,pcVar7,param_8);
    builtin_strncpy(local_218,"xyzw",4);
    uVar11 = *(uint *)param_2 >> 4;
    iVar5 = 0;
    bVar1 = false;
    uVar9 = 0;
    uVar4 = 1;
    pcVar8 = local_218;
    iVar12 = 4;
    pcVar7 = param_2;
    do {
      if ((uVar11 & 0xf & 1 << (uVar9 & 0x3f)) != 0) {
        bVar2 = pcVar7[4];
        *(uint *)(pcVar8 + 0x10) = (uint)bVar2;
        if ((iVar5 != 0) && ((uint)bVar2 != *(uint *)(pcVar8 + 0xc))) {
          bVar1 = true;
        }
        iVar5 = iVar5 + 1;
        pcVar8 = pcVar8 + 4;
      }
      uVar9 = uVar9 + 1;
      pcVar7 = pcVar7 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    if (bVar1) {
      uVar11 = 0;
      puVar10 = auStack_138;
      pcVar6 = param_2;
      do {
        if ((*(uint *)param_2 >> 4 & 0xf & 1 << (uVar11 & 0x3f)) == 0) {
          auStack_138[uVar11 * 0x40] = 0;
        }
        else {
          FUN_001a32d0(puVar10,"o%d.%c ",(uint)(byte)pcVar6[4],(int)local_218[(byte)pcVar6[8]],uVar4
                       ,iVar5,pcVar7,pcVar8);
        }
        bVar1 = uVar11 != 3;
        puVar10 = puVar10 + 0x40;
        pcVar6 = pcVar6 + 1;
        uVar11 = uVar11 + 1;
      } while (bVar1);
      pcVar6 = acStack_78;
      FUN_001a32d0(auStack_1b8,"%s%s%s%s",auStack_138,auStack_f8,auStack_b8,pcVar6,pcVar7,pcVar8);
    }
    else {
      iVar5 = 0x5f;
      if ((uVar11 & 1) != 0) {
        iVar5 = (int)local_218[(byte)param_2[8]];
      }
      iVar12 = 0x5f;
      if ((uVar11 & 2) != 0) {
        iVar12 = (int)local_218[(byte)param_2[9]];
      }
      pcVar6 = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((uVar11 & 4) != 0) {
        pcVar6 = (char *)(int)local_218[(byte)param_2[10]];
      }
      pcVar7 = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((uVar11 & 8) != 0) {
        pcVar7 = (char *)(int)local_218[(byte)param_2[0xb]];
      }
      FUN_001a32d0(auStack_1b8,"o%d.%c%c%c%c",(uint)(byte)param_2[4],iVar5,iVar12,pcVar6,pcVar7,
                   pcVar8);
    }
    ((int (*)())FUN_000ce050)(param_1,";    %s = %s%s",auStack_1b8,local_1f8,local_218 + 4,pcVar6,pcVar7,pcVar8);
  }
  return;
}

/* FUN_000ce88c @ 0xce88c (480 bytes) */
int FUN_000ce88c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  ((int (*)())FUN_000ce050)(param_1,"",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";                 VS Data",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Input Semantic Mappings",param_3,param_4,param_5,param_6,param_7,param_8);
  if (*(int *)(param_2 + 0x104) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No input mappings",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    iVar4 = 0;
    iVar3 = param_2 + 0x108;
    do {
      param_3 = iVar4;
      ((int (*)())FUN_000ce4e4)(param_1,iVar3,iVar4,param_4,param_5,param_6,param_7);
      bVar1 = iVar4 != 0x3f;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Output Semantic Mappings",param_3,param_4,param_5,param_6,param_7,param_8)
  ;
  if (*(int *)(param_2 + 0x408) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No output mappings",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    iVar4 = 0;
    iVar3 = param_2 + 0x40c;
    do {
      param_3 = iVar4;
      ((int (*)())FUN_000ce514)(param_1,iVar3,iVar4,param_4,param_5,param_6,param_7,param_8);
      bVar1 = iVar4 != 0x2f;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Num Insts = %d",*(undefined4 *)(param_2 + 0x65c),param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Max Temp = %d",*(int *)(param_2 + 0x660) + -1,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Max AltTemp = %d",*(int *)(param_2 + 0x664) + -1,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Max Constants = %d",*(int *)(param_2 + 0x670) + -1,param_4,param_5,param_6
               ,param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,"; Last Pos Inst = %d",*(undefined4 *)(param_2 + 0x668),param_4,param_5,
               param_6,param_7,param_8);
  uVar2 = *(undefined4 *)(param_2 + 0x66c);
  ((int (*)())FUN_000ce050)(param_1,"; Last Src Inst = %d",uVar2,param_4,param_5,param_6,param_7,param_8);
  if (*(int *)(param_2 + 0x658) != 0) {
    ((int (*)())FUN_000ce050)(param_1,"; Shader uses relative addressing",uVar2,param_4,param_5,param_6,param_7,
                 param_8);
  }
  return 1;
}

/* FUN_000cea6c @ 0xcea6c (408 bytes) */
int FUN_000cea6c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined2 uVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  char acStack_38 [28];
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(s_ox_001a64a8) + 1));
  uVar6 = *param_2;
  pcVar4 = (char *)(uVar6 >> 8 & 0xf);
  if (pcVar4 < "") {
    pcVar5 = (char *)(0);
    switch((int)pcVar4) {
    case 0x0:
      param_3[0] = 'r';
      param_3[1] = '\0';
      break;
    case 0x1:
      param_3[0] = 'a';
      param_3[1] = '\0';
      break;
    case 0x2:
      param_3[0] = 'o';
      param_3[1] = '\0';
      break;
    case 0x3:
      pcVar5 = "ox";
      *param_3 = s_ox_001a64a8[0];
      *(undefined2 *)(param_3 + 1) = uVar1;
      break;
    case 4:
      param_3[0] = 't';
      param_3[1] = '\0';
      break;
    case 5:
      param_3[0] = 'v';
      param_3[1] = '\0';
    }
  }
  else {
    param_3[0] = '?';
    param_3[1] = '\0';
    pcVar5 = pcVar4;
  }
  FUN_001a32d0(acStack_38,"%d",uVar6 >> 0xd & 0x7f,param_4,param_5,param_6,pcVar5,param_8);
  if ((uVar6 & 0x80001000) == 0) {
    _strcat(param_3,acStack_38);
  }
  else {
    if ((uVar6 & 0x80001000) == 0x80000000) {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[a0",4);
    }
    else {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[i0",4);
    }
    switch(uVar6 >> 0x1d & 3) {
    case 0:
      _strcat(param_3,".x");
      break;
    case 1:
      _strcat(param_3,".y");
      break;
    case 2:
      _strcat(param_3,".z");
      break;
    case 3:
      _strcat(param_3,".w");
      break;
    default:
      _strcat(param_3,".?");
    }
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '+';
    (param_3 + sVar3)[1] = '\0';
    _strcat(param_3,acStack_38);
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = ']';
    (param_3 + sVar3)[1] = '\0';
  }
  if ((uVar6 & 0x40) == 0) {
    uVar2 = uVar6 & 0x1000000;
  }
  else {
    uVar2 = uVar6 & 0x2000000;
  }
  if (uVar2 != 0) {
    _strcat(param_3,"_sat");
  }
  if ((uVar6 & 0xf00000) != 0xf00000) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '.';
    (param_3 + sVar3)[1] = '\0';
    if ((uVar6 & 0x100000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'x';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar6 & 0x200000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'y';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar6 & 0x400000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'z';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar6 & 0x800000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'w';
      (param_3 + sVar3)[1] = '\0';
    }
  }
  return param_2 + 1;
}

/* FUN_000ced58 @ 0xced58 (1288 bytes) */
int FUN_000ced58(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  char *param_4;
  char *param_5;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 in_r8;
  int iVar7;
  undefined4 in_r10;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  char acStack_48 [5];
  char acStack_43 [23];
  
  uVar2 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 4));
  iVar7 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  uVar12 = *param_2;
  uVar9 = param_2[-3];
  uVar10 = uVar12 & 0x18000000;
  uVar3 = uVar12 >> 0x15 & 0xf | (uVar12 & 4) << 2 | 0x40;
  uVar11 = uVar12 & 0xf;
  uVar8 = uVar3 - 0x40;
  *(undefined4 *)param_3 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  *(undefined4 *)(param_3 + 4) = uVar2;
  pcVar5 = param_4;
  pcVar6 = param_5;
  if (uVar8 < 0x1d) {
    iVar7 = 0;
    switch(uVar3) {
    case 0x40:
      _strcat(param_3,"NOPme     ");
      break;
    case 0x41:
      _strcat(param_3,"EXPP      ");
      break;
    case 0x42:
      _strcat(param_3,"LOGP      ");
      break;
    case 0x43:
      _strcat(param_3,"EXPPE     ");
      break;
    case 0x44:
      _strcat(param_3,"LIT       ");
      break;
    case 0x45:
      _strcat(param_3,"POW       ");
      break;
    case 0x46:
      _strcat(param_3,"RCP       ");
      break;
    case 0x47:
      _strcat(param_3,"RCPFF     ");
      break;
    case 0x48:
      _strcat(param_3,"RSQ       ");
      break;
    case 0x49:
      _strcat(param_3,"RSQFF     ");
      break;
    case 0x4a:
      _strcat(param_3,"MULme     ");
      break;
    case 0x4b:
      _strcat(param_3,"EXP       ");
      break;
    case 0x4c:
      _strcat(param_3,"LOG       ");
      break;
    case 0x4d:
      _strcat(param_3,"POWB      ");
      break;
    case 0x4e:
      _strcat(param_3,"POWB1     ");
      break;
    case 0x4f:
      _strcat(param_3,"POW01     ");
      break;
    case 0x50:
      _strcat(param_3,"SIN       ");
      break;
    case 0x51:
      _strcat(param_3,"COS       ");
      break;
    case 0x52:
      _strcat(param_3,"LOGIE3    ");
      break;
    case 0x53:
      _strcat(param_3,"RCPIE3    ");
      break;
    case 0x54:
      _strcat(param_3,"RSQIE3    ");
      break;
    case 0x55:
      _strcat(param_3,"Prd_EQ    ");
      break;
    case 0x56:
      _strcat(param_3,"Prd_GT    ");
      break;
    case 0x57:
      _strcat(param_3,"Prd_GTE   ");
      break;
    case 0x58:
      _strcat(param_3,"Prd_NEQ   ");
      break;
    case 0x59:
      _strcat(param_3,"Prd_CLR   ");
      break;
    case 0x5a:
      _strcat(param_3,"Prd_INV   ");
      break;
    case 0x5b:
      _strcat(param_3,"Prd_POP   ");
      break;
    case 0x5c:
      _strcat(param_3,"Prd_RSTOR ");
    }
  }
  else {
    _strcat(param_3,"ERROR     ");
  }
  param_4[0] = 't';
  param_4[1] = '\0';
  FUN_001a32d0(acStack_48,"%d",uVar12 >> 0x13 & 3,pcVar5,pcVar6,in_r8,iVar7,in_r10);
  if ((uVar9 & 0x2000000) != 0) {
    _strcat(param_4,"_sat");
  }
  _strcat(param_4,acStack_48);
  sVar4 = _strlen(param_4);
  (param_4 + sVar4)[0] = '.';
  (param_4 + sVar4)[1] = '\0';
  if (uVar10 == 0) {
    sVar4 = _strlen(param_4);
    (param_4 + sVar4)[0] = 'x';
    (param_4 + sVar4)[1] = '\0';
  }
  else if (uVar10 == 0x8000000) {
    sVar4 = _strlen(param_4);
    (param_4 + sVar4)[0] = 'y';
    (param_4 + sVar4)[1] = '\0';
  }
  else if (uVar10 == 0x10000000) {
    sVar4 = _strlen(param_4);
    (param_4 + sVar4)[0] = 'z';
    (param_4 + sVar4)[1] = '\0';
  }
  else if (uVar10 == 0x18000000) {
    sVar4 = _strlen(param_4);
    (param_4 + sVar4)[0] = 'w';
    (param_4 + sVar4)[1] = '\0';
  }
  sVar4 = _strlen(param_4);
  (param_4 + sVar4)[0] = ',';
  (param_4 + sVar4)[1] = '\0';
  if (uVar11 == 1) {
    param_5[0] = 'v';
    param_5[1] = '\0';
  }
  else if (uVar11 == 0) {
    param_5[0] = 'r';
    param_5[1] = '\0';
  }
  else if (uVar11 == 2) {
    param_5[0] = 'c';
    param_5[1] = '\0';
  }
  else if (uVar11 == 3) {
    param_5[0] = 't';
    param_5[1] = '\0';
  }
  else {
    param_5[0] = '?';
    param_5[1] = '\0';
  }
  FUN_001a32d0(acStack_43,"%d",uVar12 >> 5 & 0xff,pcVar5,pcVar6,in_r8,iVar7,in_r10);
  _strcat(param_5,acStack_43);
  uVar10 = uVar12 & 0x6000000;
  if (((uVar12 & 0x7e000) != 0x10000) || (uVar10 != 0)) {
    uVar11 = 0;
    sVar4 = _strlen(param_5);
    (param_5 + sVar4)[0] = '.';
    (param_5 + sVar4)[1] = '\0';
    uVar3 = 0xd;
    do {
      if (((uVar10 & 0x2000000 << (uVar11 & 0x3f)) != 0) && (uVar10 != 0)) {
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = '-';
        (param_5 + sVar4)[1] = '\0';
      }
      switch((uVar12 & 0x7e000 & 7 << (uVar3 & 0x3f)) >> (uVar3 & 0x3f)) {
      case 0:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = 'x';
        (param_5 + sVar4)[1] = '\0';
        break;
      case 1:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = 'y';
        (param_5 + sVar4)[1] = '\0';
        break;
      case 2:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = 'z';
        (param_5 + sVar4)[1] = '\0';
        break;
      case 3:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = 'w';
        (param_5 + sVar4)[1] = '\0';
        break;
      case 4:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = '0';
        (param_5 + sVar4)[1] = '\0';
        break;
      case 5:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = '1';
        (param_5 + sVar4)[1] = '\0';
        break;
      default:
        sVar4 = _strlen(param_5);
        (param_5 + sVar4)[0] = '?';
        (param_5 + sVar4)[1] = '\0';
      }
      bVar1 = uVar11 != 1;
      uVar3 = uVar3 + 3;
      uVar11 = uVar11 + 1;
    } while (bVar1);
  }
  return param_2 + 1;
}

/* FUN_000cf2ec @ 0xcf2ec (1952 bytes) */
int FUN_000cf2ec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  uint uVar1;
  undefined4 local_18;
  
  uVar1 = *param_2;
  *param_4 = 0;
  if ((uVar1 & 0x10000000) != 0) {
    *param_4 = 1;
  }
  if ((uVar1 & 0x4000000) == 0) {
    builtin_strncpy(param_3,"   ",4);
  }
  else if ((uVar1 & 0x8000000) == 0) {
    builtin_strncpy(param_3,"!p ",4);
  }
  else {
    builtin_strncpy(param_3," p ",4);
  }
  switch(uVar1 & 0xff) {
  case 0:
    _strcat(param_3,"NOPve     ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 1:
    _strcat(param_3,"DP4       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 2:
    _strcat(param_3,"MULve     ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 3:
    _strcat(param_3,"ADD       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 4:
    _strcat(param_3,"MAD       ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 5:
    _strcat(param_3,"DST       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 6:
    _strcat(param_3,"FRC       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 7:
    _strcat(param_3,"MAX       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 8:
    _strcat(param_3,"MIN       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 9:
    _strcat(param_3,"SGE       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 10:
    _strcat(param_3,"SLT       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xb:
    _strcat(param_3,"M2xADD    ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xc:
    _strcat(param_3,"MULCLAMP  ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0xd:
    _strcat(param_3,"F2F_FLR   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0xe:
    _strcat(param_3,"F2F_RND   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0xf:
    _strcat(param_3,"PrdEQ_PSH ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x10:
    _strcat(param_3,"PrdGT_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x11:
    _strcat(param_3,"PrdGTE_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x12:
    _strcat(param_3,"PrdNEQ_PSH");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x13:
    _strcat(param_3,"CND_WR_EQ ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x14:
    _strcat(param_3,"CND_WR_GT");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x15:
    _strcat(param_3,"CND_WR_GTE");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x16:
    _strcat(param_3,"CND_WR_NEQ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x17:
    _strcat(param_3,"CND_MUX_EQ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x18:
    _strcat(param_3,"CND_MUX_GT");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x19:
    _strcat(param_3,"CND_MUX_GTE");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x1a:
    _strcat(param_3,"SGT       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x1b:
    _strcat(param_3,"SEQ       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x1c:
    _strcat(param_3,"SNE       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  default:
    _strcat(param_3,"ERROR     ");
    local_18 = 1;
    break;
  case 0x40:
    _strcat(param_3,"NOPme     ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 0x41:
    _strcat(param_3,"EXPP      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x42:
    _strcat(param_3,"LOGP      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x43:
    _strcat(param_3,"EXPPE     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x44:
    _strcat(param_3,"LIT       ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x45:
    _strcat(param_3,"POW       ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x46:
    _strcat(param_3,"RCP       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x47:
    _strcat(param_3,"RCPFF     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x48:
    _strcat(param_3,"RSQ       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x49:
    _strcat(param_3,"RSQFF     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4a:
    _strcat(param_3,"MULme     ");
    local_18 = 0;
    *param_5 = 2;
    break;
  case 0x4b:
    _strcat(param_3,"EXP       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4c:
    _strcat(param_3,"LOG       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4d:
    _strcat(param_3,"POWB      ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4e:
    _strcat(param_3,"POWB1     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x4f:
    _strcat(param_3,"POW01     ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x50:
    _strcat(param_3,"SIN       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x51:
    _strcat(param_3,"COS       ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x55:
    _strcat(param_3,"Prd_EQ    ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x58:
    _strcat(param_3,"Prd_NEQ   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x59:
    _strcat(param_3,"Prd_CLR   ");
    local_18 = 0;
    *param_5 = 0;
    break;
  case 0x5a:
    _strcat(param_3,"Prd_INV   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x5b:
    _strcat(param_3,"Prd_POP   ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x5c:
    _strcat(param_3,"Prd_RSTOR ");
    local_18 = 0;
    *param_5 = 1;
    break;
  case 0x80:
    _strcat(param_3,"MADmac    ");
    local_18 = 0;
    *param_5 = 3;
    break;
  case 0x81:
    _strcat(param_3,"M2xADDmac ");
    local_18 = 0;
    *param_5 = 2;
  }
  return local_18;
}

/* FUN_000cfc94 @ 0xcfc94 (144 bytes) */
int FUN_000cfc94(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if (param_2 == 0x3e) {
    return "loop   ";
  }
  if (param_2 < 0x3f) {
    if (param_2 == 0x35) {
      return "ifnz  ";
    }
    if (param_2 < 0x36) {
      if (param_2 == 8) {
        return "call   ";
      }
      if (param_2 == 9) {
        return "callnz ";
      }
    }
  }
  else if (param_2 == 0x53) {
    return "ret    ";
  }
  return "unknown";
}

/* FUN_000cfd24 @ 0xcfd24 (524 bytes) */
int FUN_000cfd24(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = param_2[2];
  if (uVar8 == 0x35) {
    iVar7 = param_2[3];
    if (*param_2 == 0) {
      pcVar2 = "!=";
    }
    else {
      pcVar2 = "==";
    }
    iVar4 = param_2[6];
    pcVar3 = "          CF- IF  B%d %s 0, if = %d, else = %d, endif = %d";
    pcVar5 = (char *)(param_2[4] + 1);
    iVar6 = param_2[5] + 1;
LAB_000cfef0:
    ((int (*)())FUN_000ce050)(param_1,pcVar3,iVar7,pcVar2,pcVar5,iVar6,iVar4,param_8);
    return;
  }
  if (uVar8 < 0x36) {
    if (uVar8 == 0x27) {
      return;
    }
    if (uVar8 < 0x28) {
      if (uVar8 == 8) {
        iVar6 = param_2[6];
        iVar4 = param_2[4];
        iVar7 = param_2[5];
        pcVar2 = "          CF- CALL at %d, subroutine from %d to %d";
        goto LAB_000cfe3c;
      }
      if (uVar8 == 9) {
        iVar7 = param_2[4];
        pcVar2 = (char *)param_2[3];
        if (*param_2 == 0) {
          pcVar5 = "!=";
        }
        else {
          pcVar5 = "==";
        }
        iVar4 = param_2[6];
        iVar6 = param_2[5];
        pcVar3 = "          CF- CALL at %d if B%d %s 0, subroutine from %d to %d";
        goto LAB_000cfef0;
      }
    }
    else if (uVar8 == 0x29) {
      return;
    }
  }
  else {
    if (uVar8 == 0x3e) {
      if (param_2[1] == 0) {
        iVar6 = param_2[6];
        iVar4 = param_2[3];
        pcVar2 = "          CF- Loop I%d first in loop = %d last in loop = %d";
        iVar7 = param_2[4] + 1;
      }
      else {
        iVar6 = param_2[6];
        iVar4 = param_2[3];
        pcVar2 = "          CF- Rep  I%d first in loop = %d last in loop = %d";
        iVar7 = param_2[4] + 1;
      }
      goto LAB_000cfe3c;
    }
    if (uVar8 == 0x53) {
      return;
    }
  }
  iVar7 = *param_2;
  uVar1 = ((int (*)())FUN_000cfc94)(param_1,uVar8);
  param_6 = param_2[3];
  ((int (*)())FUN_000ce050)(param_1,"\nNot = %d, op=%s(%d), reg =%d",iVar7,uVar1,uVar8,param_6,param_7,param_8);
  iVar7 = param_2[4];
  ((int (*)())FUN_000ce050)(param_1," ifinst = %d begInst= %d callinst = %d",iVar7,iVar7,iVar7,param_6,param_7,
               param_8);
  ((int (*)())FUN_000ce050)(param_1," else=%d, labelinst=%d",param_2[5],param_2[5],iVar7,param_6,param_7,param_8)
  ;
  iVar4 = param_2[6];
  pcVar2 = " endif= %d , endinst = %d, retinst = %d";
  iVar7 = iVar4;
  iVar6 = iVar4;
LAB_000cfe3c:
  ((int (*)())FUN_000ce050)(param_1,pcVar2,iVar4,iVar7,iVar6,param_6,param_7,param_8);
  return;
}

/* FUN_000cff30 @ 0xcff30 (252 bytes) */
int FUN_000cff30(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  undefined4 param_2;
  char *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  char acStack_98 [120];
  
  *param_3 = '\0';
  iVar1 = *param_1;
  piVar6 = *(int **)(iVar1 + 0x654);
  uVar3 = param_4;
  uVar5 = param_5;
  if ((piVar6 == (int *)0x0) || (iVar7 = *piVar6, iVar7 < 1)) {
    piVar4 = (int *)param_1[1];
  }
  else {
    piVar4 = (int *)param_1[1];
    iVar8 = 0;
    while( true ) {
      iVar1 = iVar8 * 0x1c + *(int *)(iVar1 + 0x654);
      piVar6 = (int *)(*(int *)(iVar1 + 0x14) + 1);
      if (piVar6 == piVar4) {
        ((int (*)())FUN_000cfd24)(param_1,iVar1 + 4,piVar4,uVar3,uVar5,param_6,piVar6,param_8);
        piVar4 = (int *)param_1[1];
      }
      iVar8 = iVar8 + 1;
      if (iVar7 == iVar8) break;
      iVar1 = *param_1;
    }
  }
  FUN_001a32d0(acStack_98,"%3d:",piVar4,uVar3,uVar5,param_6,piVar6,param_8);
  _strcat(param_3,acStack_98);
  param_1[1] = param_1[1] + 1;
  sVar2 = _strlen(param_3);
  uVar3 = ((int (*)())FUN_000cf2ec)(param_1,param_2,param_3 + sVar2,param_4,param_5);
  return uVar3;
}

/* FUN_000d002c @ 0xd002c (728 bytes) */
int FUN_000d002c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined1 *param_3;
  int *param_4;
  int *param_5;
  char *param_6;
  undefined1 *param_7;
  undefined4 param_8;
{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_d8;
  int local_d4;
  int aiStack_d0 [5];
  undefined1 auStack_ba [22];
  undefined1 auStack_a4 [22];
  char acStack_8e [22];
  int aiStack_78 [12];
  
  iVar7 = *(int *)(param_2 + 0x650);
  iVar5 = *(int *)(param_2 + 0x65c);
  *param_1 = param_2;
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";              VS Disassembly             ",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  if (iVar5 != 0) {
    iVar6 = 0;
    do {
      param_4 = &local_d8;
      param_5 = &local_d4;
      iVar2 = ((int (*)())FUN_000cff30)(param_1,iVar7,auStack_ba,param_4,&local_d4,param_6,param_7,param_8);
      param_3 = auStack_ba;
      if (iVar2 == 0) {
        if (local_d8 == 0) {
          uVar3 = ((int (*)())FUN_000cea6c)(param_1,iVar7,aiStack_78,param_4,param_5,param_6,param_7,param_8);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,aiStack_d0);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_8e);
          iVar7 = ((int (*)())FUN_000ce148)(param_1,uVar3,auStack_a4);
          if (local_d4 == 1) {
            sVar4 = _strlen((char *)aiStack_78);
            *(undefined2 *)((int)aiStack_78 + sVar4) = 0x2c00;
            param_4 = aiStack_78;
            param_5 = aiStack_d0;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",auStack_ba,aiStack_78,aiStack_d0,param_6,param_7,
                         param_8);
          }
          else if (local_d4 == 0) {
            param_4 = aiStack_78;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s",auStack_ba,aiStack_78,param_5,param_6,param_7,param_8);
          }
          else if (local_d4 == 2) {
            sVar4 = _strlen((char *)aiStack_78);
            *(undefined2 *)((int)aiStack_78 + sVar4) = 0x2c00;
            sVar4 = _strlen((char *)aiStack_d0);
            *(undefined2 *)((int)aiStack_d0 + sVar4) = 0x2c00;
            param_4 = aiStack_78;
            param_5 = aiStack_d0;
            param_6 = acStack_8e;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,aiStack_78,aiStack_d0,acStack_8e,
                         param_7,param_8);
          }
          else {
            sVar4 = _strlen((char *)aiStack_78);
            *(undefined2 *)((int)aiStack_78 + sVar4) = 0x2c00;
            sVar4 = _strlen((char *)aiStack_d0);
            *(undefined2 *)((int)aiStack_d0 + sVar4) = 0x2c00;
            sVar4 = _strlen(acStack_8e);
            pcVar1 = acStack_8e + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            param_4 = aiStack_78;
            param_5 = aiStack_d0;
            param_6 = acStack_8e;
            param_7 = auStack_a4;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s%s",auStack_ba,aiStack_78,aiStack_d0,acStack_8e,
                         auStack_a4,param_8);
          }
        }
        else {
          uVar3 = ((int (*)())FUN_000cea6c)(param_1,iVar7,aiStack_78,param_4,param_5,param_6,param_7,param_8);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,aiStack_d0);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_8e);
          sVar4 = _strlen((char *)aiStack_78);
          *(undefined2 *)((int)aiStack_78 + sVar4) = 0x2c00;
          sVar4 = _strlen((char *)aiStack_d0);
          *(undefined2 *)((int)aiStack_d0 + sVar4) = 0x2c00;
          param_6 = acStack_8e;
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,aiStack_78,aiStack_d0,acStack_8e,
                       param_7,param_8);
          iVar7 = ((int (*)())FUN_000ced58)(param_1,uVar3,auStack_ba,aiStack_78,aiStack_d0);
          param_4 = aiStack_78;
          param_5 = aiStack_d0;
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",auStack_ba,aiStack_78,aiStack_d0,param_6,param_7,
                       param_8);
        }
      }
      else {
        iVar7 = iVar7 + 0x10;
        ((int (*)())FUN_000ce050)(param_1,"%s",auStack_ba,param_4,param_5,param_6,param_7,param_8);
      }
      iVar6 = iVar6 + 1;
    } while (iVar5 != iVar6);
  }
  ((int (*)())FUN_000ce050)(param_1,"",param_3,param_4,param_5,param_6,param_7,param_8);
  param_1[1] = 0;
  return 1;
}

/* FUN_000d0304 @ 0xd0304 (60 bytes) */
int FUN_000d0304(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 in_r10;
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = param_3;
  ((int (*)())FUN_000ce038)(auStack_38);
  local_30 = param_3;
  local_2c = param_1;
  ((int (*)())FUN_000ce88c)(auStack_38,param_2,uVar1,param_4,param_5,param_6,param_7,in_r10);
  return 0;
}

/* FUN_000d035c @ 0xd035c (60 bytes) */
int FUN_000d035c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 in_r10;
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = param_4;
  ((int (*)())FUN_000ce038)(auStack_38);
  local_30 = param_4;
  local_2c = param_1;
  ((int (*)())FUN_000d002c)(auStack_38,param_2,param_3,uVar1,param_5,param_6,param_7,in_r10);
  return 0;
}

/* FUN_000d03b4 @ 0xd03b4 (152 bytes) */
int FUN_000d03b4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined1 auStack_124 [280];
  
  if (DAT_001fa61c != (undefined4 *)0x0) {
    uStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    uStack00000034 = param_8;
    FUN_001a34d4(auStack_124,param_2,&STACKARG(0x20),param_4,param_5,param_6,param_7,param_8);
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",auStack_124,&STACKARG(0x20));
  }
  return;
}

/* FUN_000d0450 @ 0xd0450 (56 bytes) */
int FUN_000d0450(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((param_2 & 0x8000) != 0) {
    FUN_001a32d0(param_1,"c%02u",param_2 & 0xffff7fff,param_4,param_5,param_6,param_7,0xd0458);
    return;
  }
  FUN_001a32d0(param_1,"r%02u",param_2,param_4,param_5,param_6,param_7,0xd0458);
  return;
}

/* FUN_000d0488 @ 0xd0488 (552 bytes) */
int FUN_000d0488(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  int in_stack_00000038;
  char local_38 [6];
  undefined1 auStack_32 [22];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  if (param_8 < 0x20) {
    iVar7 = 0;
    switch(param_8) {
    default:
      ((int (*)())FUN_000d0450)(local_38,param_2,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0x18:
    case 0x1b:
      ((int (*)())FUN_000d0450)(local_38,param_3,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x19:
    case 0x1c:
      ((int (*)())FUN_000d0450)(local_38,param_4,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xc:
      ((int (*)())FUN_000d0450)(local_38,param_5,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xd:
      ((int (*)())FUN_000d0450)(local_38,param_6,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xe:
      ((int (*)())FUN_000d0450)(local_38,param_7,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      local_38[0] = s_srcp_001a6fa0[0];
      local_38[1] = s_srcp_001a6fa0[1];
      local_38[2] = s_srcp_001a6fa0[2];
      local_38[3] = s_srcp_001a6fa0[3];
      local_38[4] = s_srcp_001a6fa0[4];
      break;
    case 0x14:
      builtin_strncpy(local_38,"0.0",4);
      break;
    case 0x15:
      builtin_strncpy(local_38,"1.0",4);
      break;
    case 0x16:
      builtin_strncpy(local_38,"0.5",4);
      break;
    case 0x1d:
      ((int (*)())FUN_000d0450)(local_38,param_5,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(auStack_32,param_2,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0x1e:
      uVar6 = param_3;
      ((int (*)())FUN_000d0450)(local_38,param_6,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(auStack_32,param_3,uVar6,param_4,param_5,param_6,iVar7);
      break;
    case 0x1f:
      uVar6 = param_4;
      ((int (*)())FUN_000d0450)(local_38,param_7,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(auStack_32,param_4,param_3,uVar6,param_5,param_6,iVar7);
    }
  }
  else {
    builtin_strncpy(local_38,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (param_8 < 0x20) {
                    
                    
    (*(code *)(((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + param_8 * 4)))();
    return;
  }
  _strcpy(param_1 + sVar5,local_38);
  sVar5 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar5)[0] = ')';
    (param_1 + sVar5)[1] = '\0';
  }
  return;
}

/* FUN_000d0888 @ 0xd0888 (464 bytes) */
int FUN_000d0888(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  int iVar6;
  int in_stack_00000038;
  char local_28 [24];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  if (param_8 < 0x13) {
    iVar6 = 0;
    switch(param_8) {
    case 0:
    case 1:
    case 2:
      ((int (*)())FUN_000d0450)(local_28,param_2,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 3:
    case 4:
    case 5:
      ((int (*)())FUN_000d0450)(local_28,param_3,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 6:
    case 7:
    case 8:
      ((int (*)())FUN_000d0450)(local_28,param_4,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 9:
      ((int (*)())FUN_000d0450)(local_28,param_5,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 10:
      ((int (*)())FUN_000d0450)(local_28,param_6,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 0xb:
      ((int (*)())FUN_000d0450)(local_28,param_7,param_3,param_4,param_5,param_6,iVar6);
      break;
    default:
      local_28[0] = s_srcp_001a6fa0[0];
      local_28[1] = s_srcp_001a6fa0[1];
      local_28[2] = s_srcp_001a6fa0[2];
      local_28[3] = s_srcp_001a6fa0[3];
      local_28[4] = s_srcp_001a6fa0[4];
      break;
    case 0x10:
      builtin_strncpy(local_28,"0.0",4);
      break;
    case 0x11:
      builtin_strncpy(local_28,"1.0",4);
      break;
    case 0x12:
      builtin_strncpy(local_28,"0.5",4);
    }
  }
  else {
    builtin_strncpy(local_28,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (param_8 < 0x10) {
                    
                    
    (*(code *)(((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + param_8 * 4)))();
    return;
  }
  _strcpy(param_1 + sVar5,local_28);
  sVar5 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar5)[0] = ')';
    (param_1 + sVar5)[1] = '\0';
  }
  return;
}

/* FUN_000d0b68 @ 0xd0b68 (1344 bytes) */
int FUN_000d0b68(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar12 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar12 != 0)) {
    piVar7 = (int *)(param_1 + 0x90);
    uVar11 = 1;
    do {
      uVar11 = uVar11 + 1;
      if (*piVar7 != 1) goto LAB_000d0bfc;
      piVar7 = piVar7 + 0x12;
    } while (uVar11 <= uVar12);
LAB_000d0bd8:
    uVar10 = 0;
    uVar9 = 0;
    bVar3 = true;
  }
  else {
    uVar11 = 1;
LAB_000d0bfc:
    if (uVar12 < uVar11) goto LAB_000d0bd8;
    uVar10 = 0;
    bVar3 = true;
    puVar17 = (uint *)(param_1 + uVar11 * 0x48);
    uVar16 = 0;
    uVar13 = 0;
    bVar1 = false;
    uVar9 = 0;
    uVar15 = uVar11;
    do {
      uVar4 = *puVar17;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if (uVar4 != 2) goto LAB_000d0c50;
          param_7 = (uint)*(byte *)((int)puVar17 + 0x1b);
          uVar10 = uVar10 | *(byte *)(puVar17 + 1) | param_7;
          if (*(char *)((int)puVar17 + 0x1a) != '\0') {
            uVar9 = uVar9 | -(puVar17[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          uVar10 = uVar10 | *(byte *)(puVar17 + 1);
        }
      }
      else if (uVar4 == 5) {
        uVar10 = uVar10 | *(byte *)(puVar17 + 1);
        if (bVar3) {
          if ((*(char *)((int)puVar17 + 0xe) != '\0') || (*(char *)((int)puVar17 + 0x11) != '\0')) {
            bVar1 = true;
          }
          uVar4 = puVar17[4] & 0xff00ff00;
          if ((uVar4 != 0) &&
             ((*(ushort *)(puVar17 + 3) < uVar13 || (*(char *)((int)puVar17 + 0x19) != '\0')))) {
            bVar1 = true;
          }
          uVar5 = (uint)*(byte *)(puVar17 + 5);
          uVar8 = (uint)*(byte *)((int)puVar17 + 0x15);
          param_7 = uVar5;
          if ((uVar4 != 0) && (param_7 = uVar8, uVar4 == 0x100ff00)) {
            uVar5 = uVar8;
          }
          uVar4 = param_7;
          if ((uVar5 == 1) || (uVar4 = uVar5, uVar5 != 0)) {
            if (uVar4 == 2) goto LAB_000d0d60;
            if (uVar4 == 1) {
              uVar16 = uVar16 - *(byte *)((int)puVar17 + 0x13);
            }
          }
          else if (param_7 == 2) {
LAB_000d0d60:
            uVar16 = uVar16 + 1;
          }
          bVar3 = !bVar1;
          if (4 < uVar16) {
            bVar1 = true;
            bVar3 = false;
          }
        }
      }
      else {
LAB_000d0c50:
        ((int (*)())FUN_000d03b4)(0,"Bad Instruction Type!",param_3,param_4,param_5,param_6,param_7,param_8);
      }
      uVar15 = uVar15 + 1;
      uVar13 = uVar13 + 1;
      puVar17 = puVar17 + 0x12;
    } while (uVar15 <= uVar12);
    if (uVar13 != 0) goto LAB_000d0be8;
  }
  uVar13 = 1;
LAB_000d0be8:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)uVar13 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (uVar11 <= uVar12) {
    bVar1 = uVar10 != 0;
    puVar17 = (uint *)(param_1 + uVar11 * 0x48);
    puVar14 = (undefined1 *)((int)puVar17 + -3);
    uVar13 = 0;
    uVar15 = 100000;
    uVar16 = uVar11;
    do {
      uVar5 = *puVar17;
      uVar4 = uVar15;
      if (uVar5 < 5) {
        if (uVar5 < 3) {
          if (uVar5 == 2) {
            if (uVar9 == 0) {
              *(undefined1 *)((int)puVar17 + 0x1e) = 1;
              *(undefined1 *)((int)puVar17 + 0x1d) = 7;
              puVar17[5] = puVar17[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar17 + 0x1f);
            param_7 = (uint)bVar2;
            if (param_7 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar17[5] = puVar17[5] >> 2 & 0x300000 | puVar17[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar17[5] = puVar17[5] >> 4 & 0xc0000 | puVar17[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar17[5] = puVar17[5] >> 6 & 0x30000 | puVar17[5] & 0xfffcffff;
              }
            }
            uVar4 = uVar16;
            if (((!bVar1) && (*(char *)(puVar17 + 8) != '\0')) && (uVar15 != 100000)) {
              iVar6 = param_1 + uVar15 * 0x48;
              *(undefined1 *)(iVar6 + 4) = 1;
              *(undefined1 *)(iVar6 + 0x1b) = 1;
              *(undefined1 *)(puVar17 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar17 + 0x15) == '\0') &&
              (param_7 = puVar17[8] & 0xff00ff, param_7 == 0)) &&
             (uVar13 != *(ushort *)(param_1 + 0x12))) {
            *puVar17 = 4;
          }
          if ((bVar1) || (uVar15 == 100000)) {
LAB_000d1004:
            uVar4 = 100000;
          }
          else {
            iVar6 = param_1 + uVar15 * 0x48;
            *(undefined1 *)(iVar6 + 4) = 1;
            *(undefined1 *)(iVar6 + 0x1b) = 1;
            *(undefined1 *)(puVar17 + 1) = 1;
            uVar4 = 100000;
          }
        }
      }
      else if (uVar5 == 5) {
        if ((!bVar1) && (uVar15 != 100000)) {
          iVar6 = param_1 + uVar15 * 0x48;
          *(undefined1 *)(iVar6 + 4) = 1;
          *(undefined1 *)(iVar6 + 0x1b) = 1;
          *(undefined1 *)(puVar17 + 1) = 1;
        }
        if ((byte)(*(byte *)((int)puVar17 + 0x12) & 0xf0) ==
            (byte)(*(byte *)((int)puVar17 + 0x12) << 4)) goto LAB_000d1004;
        if (uVar13 == 0) {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test is first US instruction",param_3,param_4,param_5,
                       param_6,param_7,param_8);
          uVar4 = 100000;
        }
        else if (*(int *)(puVar14 + -0x45) - 3U < 2) {
          *puVar14 = 1;
          uVar4 = 100000;
        }
        else {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test follows non-ALU instruction",param_3,param_4,param_5,
                       param_6,param_7,param_8);
          uVar4 = 100000;
        }
      }
      uVar16 = uVar16 + 1;
      uVar13 = uVar13 + 1;
      puVar17 = puVar17 + 0x12;
      puVar14 = puVar14 + 0x48;
      uVar15 = uVar4;
    } while (uVar16 <= uVar12);
    if (((uVar13 != 0) &&
        (iVar6 = (*(ushort *)(param_1 + 0x12) + uVar11) * 0x48, *(int *)(param_1 + iVar6) == 3)) &&
       (uVar10 == 0)) {
      *(undefined1 *)(param_1 + iVar6 + 4) = 1;
    }
  }
  if (((uVar9 != 0) || (uVar10 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(char *)(param_1 + 0xf) = (char)param_2;
  return;
}

/* FUN_000d10a8 @ 0xd10a8 (52 bytes) */
int FUN_000d10a8(param_1)
  uint param_1;
{
  if ((((param_1 & 0xe000) != 0x6000) && ((param_1 & 0x1c00) != 0xc00)) &&
     ((param_1 & 0x380) != 0x180)) {
    return 0;
  }
  return 1;
}

/* FUN_000d10dc @ 0xd10dc (712 bytes) */
double FUN_000d10dc(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1)
{
  bool bVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  char local_98 [10];
  undefined1 local_8e;
  undefined1 local_8d;
  char local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined4 local_88;
  uint uStack_84;
  longlong local_80;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  longlong local_68;
  undefined4 local_60;
  uint uStack_5c;
  longlong local_58;
  float local_50;
  
  if ((param_2 & 0x8000) == 0) {
    if ((param_2 & 0x4000) == 0) {
      if ((param_2 & 0x2000) == 0) {
        FUN_001a32d0(param_1,"r%02u",param_2,param_4,param_5,param_6,param_7,param_8);
      }
      else {
        dVar9 = (double)((double (*)())FUN_000da78c)(param_2 & 0xffffdfff,fparam_1);
        dVar3 = DOUBLE_001aa238;
        dVar2 = DOUBLE_001aa1e0;
        if (dVar9 == (double)FLOAT_001aa0d4) {
          local_98[0] = ' ';
          local_98[2] = 0x2e;
          iVar8 = 7;
          local_98[1] = '0';
          iVar4 = 3;
          iVar6 = 0x30;
          do {
            local_98[iVar4] = '0';
            iVar4 = iVar4 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          local_8d = 0x2b;
          local_8b = 0x30;
          local_8c = '0';
        }
        else {
          if (dVar9 < (double)FLOAT_001aa0d4) {
            dVar9 = -dVar9;
            local_98[0] = '-';
          }
          else {
            local_98[0] = '+';
          }
          local_50 = (float)dVar9;
          local_88 = 0x43300000;
          uStack_84 = ((uint)local_50 >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,uStack_84) - DOUBLE_001aa1e0);
          dVar10 = (double)_log();
          dVar11 = (double)_log(dVar3);
          dVar10 = (double)_floor(dVar10 / dVar11);
          local_78 = 0x43300000;
          uVar7 = (uint)dVar10;
          local_80 = (longlong)(int)uVar7;
          uStack_74 = uVar7 ^ 0x80000000;
          dVar11 = (double)_pow(dVar3,(double)CONCAT44(0x43300000,uStack_74) - dVar2);
          dVar10 = DOUBLE_001aa298;
          dVar11 = dVar9 / dVar11 + DOUBLE_001aa298;
          if (dVar3 <= dVar11) {
            uVar7 = uVar7 + 1;
            local_70 = 0x43300000;
            uStack_6c = uVar7 ^ 0x80000000;
            dVar11 = (double)_pow(dVar3,(double)CONCAT44(0x43300000,uStack_6c) - dVar2);
            dVar11 = dVar9 / dVar11 + dVar10;
          }
          dVar9 = (double)_floor(dVar11);
          uVar5 = (uint)dVar9;
          local_68 = (longlong)(int)uVar5;
          local_98[2] = 0x2e;
          iVar6 = 3;
          local_98[1] = (char)uVar5 + '0';
          do {
            uStack_5c = uVar5 ^ 0x80000000;
            local_60 = 0x43300000;
            dVar11 = (dVar11 - ((double)CONCAT44(0x43300000,uStack_5c) - dVar2)) * dVar3;
            dVar9 = (double)_floor(dVar11);
            bVar1 = iVar6 != 9;
            uVar5 = (uint)dVar9;
            local_58 = (longlong)(int)uVar5;
            local_98[iVar6] = (char)uVar5 + '0';
            iVar6 = iVar6 + 1;
          } while (bVar1);
          if ((int)uVar7 < 0) {
            uVar7 = -uVar7;
            local_8d = 0x2d;
          }
          else {
            local_8d = 0x2b;
          }
          local_8c = (char)((int)uVar7 / 10) + '0';
          iVar6 = (int)uVar7 % 10 + 0x30;
          local_8b = (undefined1)iVar6;
        }
        local_8e = 0x45;
        local_8a = 0;
        FUN_001a32d0(param_1,"(%s)",local_98,param_4,param_5,param_6,iVar6,param_8);
      }
    }
    else {
      FUN_001a32d0(param_1,"r[AL+%02u]",param_2 & 0xffffbfff,param_4,param_5,param_6,param_7,param_8
                  );
    }
  }
  else {
    FUN_001a32d0(param_1,"c%02u",param_2 & 0xffff7fff,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}

/* FUN_000d13a4 @ 0xd13a4 (640 bytes) */
double FUN_000d13a4(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,char *param_7,int param_8,double fparam_1)
{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  int iVar13;
  double fparam_1_00;
  int in_stack_00000038;
  ushort in_stack_0000003e;
  int in_stack_00000040;
  char local_58 [44];
  
  cVar5 = s______001a6f98[4];
  cVar4 = s_nab__001a6f90[4];
  cVar3 = s_abs__001a6f88[4];
  cVar2 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    pcVar12 = "neg(";
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
    pcVar12 = param_7;
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar3;
    pcVar12 = "abs(";
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar4;
    pcVar12 = "nab(";
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar5;
    pcVar12 = "???(";
  }
  uVar9 = param_4;
  iVar13 = param_8;
  if (in_stack_00000040 - 0xbU < 2) {
LAB_000d14bc:
    ((double (*)())FUN_000d10dc)(local_58,param_2,param_3,uVar9,param_5,param_6,pcVar12,iVar13,fparam_1);
  }
  else {
    uVar8 = param_3;
    uVar10 = param_5;
    uVar11 = param_6;
    iVar6 = ((int (*)())FUN_000d10a8)((uint)in_stack_0000003e);
    if (iVar6 == 0) {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(local_58,param_3,uVar8,uVar9,uVar10,uVar11,pcVar12,iVar13,fparam_1_00);
        goto LAB_000d1518;
      }
      param_3 = uVar8;
      param_5 = uVar10;
      param_6 = uVar11;
      fparam_1 = fparam_1_00;
      if (param_8 == 0) goto LAB_000d14bc;
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_58,param_4,uVar8,uVar9,uVar10,uVar11,pcVar12,iVar13,fparam_1_00);
        goto LAB_000d1518;
      }
    }
    else {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(local_58,param_6,uVar8,uVar9,uVar10,uVar11,pcVar12,iVar13,fparam_1_00);
        goto LAB_000d1518;
      }
      if (param_8 == 0) {
        ((double (*)())FUN_000d10dc)(local_58,param_5,uVar8,uVar9,uVar10,uVar11,pcVar12,iVar13,fparam_1_00);
        goto LAB_000d1518;
      }
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_58,param_7,uVar8,uVar9,uVar10,uVar11,pcVar12,iVar13,fparam_1_00);
        goto LAB_000d1518;
      }
    }
    if (param_8 == 3) {
      local_58[0] = s_srcp_001a6fa0[0];
      local_58[1] = s_srcp_001a6fa0[1];
      local_58[2] = s_srcp_001a6fa0[2];
      local_58[3] = s_srcp_001a6fa0[3];
      local_58[4] = s_srcp_001a6fa0[4];
    }
    else {
      builtin_strncpy(local_58,"???",4);
    }
  }
LAB_000d1518:
  sVar7 = _strlen(param_1);
  uVar1 = in_stack_0000003e & 0xff80;
  if (((uVar1 == 0x9200) || (uVar1 == 0xdb00)) || (uVar1 == 0xb680)) {
    _strcpy(param_1 + sVar7,(char *)((in_stack_0000003e >> 0xb & 0x1c) + 0x1dc259));
  }
  else {
    FUN_001a32d0(param_1 + sVar7,"%s.%s%s%s",local_58,(in_stack_0000003e >> 0xb & 0x1c) + 0x1dc259,
                 (in_stack_0000003e >> 8 & 0x1c) + 0x1dc259,
                 (in_stack_0000003e >> 5 & 0x1c) + 0x1dc259,(uint)in_stack_0000003e,iVar13);
  }
  sVar7 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar7)[0] = ')';
    (param_1 + sVar7)[1] = '\0';
  }
  return;
}

/* FUN_000d1624 @ 0xd1624 (536 bytes) */
double FUN_000d1624(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,char *param_7,int param_8,double fparam_1)
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  char *pcVar6;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  char local_38 [40];
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    pcVar6 = "neg(";
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
    pcVar6 = param_7;
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
    pcVar6 = "abs(";
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
    pcVar6 = "nab(";
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
    pcVar6 = "???(";
  }
  if (1 < in_stack_00000040 - 0xeU) {
    if (in_stack_0000003c != 3) {
      if (param_8 != 1) {
        if (param_8 == 0) {
          ((double (*)())FUN_000d10dc)(local_38,param_2,param_7,param_4,param_5,param_6,pcVar6,0,fparam_1);
          goto LAB_000d1780;
        }
        param_3 = param_4;
        if (param_8 != 2) goto LAB_000d176c;
      }
      ((double (*)())FUN_000d10dc)(local_38,param_3,param_7,param_4,param_5,param_6,pcVar6,param_8,fparam_1);
      goto LAB_000d1780;
    }
    if (param_8 == 1) {
      ((double (*)())FUN_000d10dc)(local_38,param_6,param_7,param_4,param_5,param_6,pcVar6,1,fparam_1);
      goto LAB_000d1780;
    }
    if (param_8 != 0) {
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_38,param_7,param_7,param_4,param_5,param_6,pcVar6,2,fparam_1);
        goto LAB_000d1780;
      }
LAB_000d176c:
      if (param_8 == 3) {
        pcVar6 = "srcp";
        local_38[0] = s_srcp_001a6fa0[0];
        local_38[1] = s_srcp_001a6fa0[1];
        local_38[2] = s_srcp_001a6fa0[2];
        local_38[3] = s_srcp_001a6fa0[3];
        local_38[4] = s_srcp_001a6fa0[4];
      }
      else {
        builtin_strncpy(local_38,"???",4);
      }
      goto LAB_000d1780;
    }
  }
  ((double (*)())FUN_000d10dc)(local_38,param_5,param_7,param_4,param_5,param_6,pcVar6,param_8,fparam_1);
LAB_000d1780:
  sVar5 = _strlen(param_1);
  if (in_stack_0000003c - 4U < 3) {
    _strcpy(param_1 + sVar5,(char *)(in_stack_0000003c * 4 + 0x1dc259));
  }
  else {
    FUN_001a32d0(param_1 + sVar5,"%s.%s",local_38,in_stack_0000003c * 4 + 0x1dc259,param_5,param_6,
                 pcVar6,param_8);
  }
  sVar5 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar5)[0] = ')';
    (param_1 + sVar5)[1] = '\0';
  }
  return;
}

/* FUN_000d183c @ 0xd183c (13160 bytes) */
int FUN_000d183c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint *param_1;
  uint param_2;
  uint *param_3;
  char *param_4;
  uint param_5;
  uint *param_6;
  char *param_7;
  byte *param_8;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  char cVar9;
  int iVar10;
  size_t sVar11;
  int iVar12;
  uint *puVar13;
  char *pcVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  char *pcVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  char *pcVar22;
  uint uVar23;
  char *pcVar24;
  bool bVar26;
  uint uVar25;
  byte *pbVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  int iVar32;
  uint *puVar33;
  uint uVar34;
  uint *puVar35;
  uint uVar36;
  uint uVar37;
  undefined **ppuVar38;
  bool bVar39;
  uint *puVar40;
  double dVar41;
  uint uStack0000001c;
  uint *puStack00000020;
  undefined4 local_2b8;
  uint local_2b4;
  char local_2b0 [4];
  char local_2ac [2];
  uint local_2aa;
  char local_2a6 [6];
  undefined2 local_2a0;
  undefined1 uStack_29e;
  uint local_296;
  char local_292 [4];
  char local_28e [2];
  uint local_28c;
  char local_288 [4];
  char local_284 [2];
  uint local_282;
  char local_27e [4];
  char local_27a;
  uint auStack_278 [3];
  uint auStack_269 [3];
  undefined1 auStack_25a [15];
  uint auStack_24b [3];
  uint auStack_23c [8];
  uint auStack_21c [8];
  uint auStack_1fc [8];
  uint auStack_1dc [8];
  uint auStack_1bc [8];
  uint auStack_19c [8];
  uint auStack_17c [8];
  uint auStack_15c [25];
  int local_f8;
  int local_f4;
  uint *local_f0;
  uint local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  byte *local_cc;
  uint *local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  byte *local_ac;
  uint local_a8;
  uint *local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  ushort local_6c;
  uint *local_68;
  uint *local_64;
  uint *local_60;
  int local_5c;
  
  uStack0000001c = param_2;
  puStack00000020 = param_3;
  ((int (*)())FUN_000d0b68)(param_1,1,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) {
    local_a0 = param_1[2];
    uVar21 = uStack0000001c;
    puVar13 = puStack00000020;
    ((int (*)())FUN_000d03b4)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",uVar21,puVar13,param_5,param_6,param_7,param_8);
    }
    else {
      iVar32 = 0;
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",uVar21,puVar13,param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Levels:                 %2d\n",(uint)*(ushort *)((int)param_1 + 0x16),
                   puVar13,param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(param_1 + 6),puVar13,
                   param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)param_1 + 0x1a),
                   puVar13,param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(param_1 + 7),puVar13,
                   param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)param_1 + 0x1e),
                   puVar13,param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)param_1 + 0x22),
                   puVar13,param_5,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(param_1 + 9),puVar13,
                   param_5,param_6,param_7,param_8);
      uVar21 = (uint)*(ushort *)((int)param_1 + 0x26);
      ((int (*)())FUN_000d03b4)(0,"     Nominal cycle count:    %2d\n",uVar21,puVar13,param_5,param_6,param_7,
                   param_8);
      ((int (*)())FUN_000d03b4)(0,"     Tex lookup counts:     ",uVar21,puVar13,param_5,param_6,param_7,param_8);
      puVar40 = param_1;
      do {
        uVar21 = (uint)*(byte *)((int)puVar40 + 0x2a);
        ((int (*)())FUN_000d03b4)(0," %2d",uVar21,puVar13,param_5,param_6,param_7,param_8);
        bVar26 = iVar32 != 0xf;
        puVar40 = (uint *)((int)puVar40 + 1);
        iVar32 = iVar32 + 1;
      } while (bVar26);
      ((int (*)())FUN_000d03b4)(0,"\n \n",uVar21,puVar13,param_5,param_6,param_7,param_8);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",uVar21,puVar13,param_5,param_6,param_7,param_8);
    if ((param_1[0x12] == 1) && (local_a0 != 0)) {
      puVar35 = param_1 + 0x24;
      uVar37 = 1;
      puVar40 = puVar35;
      puVar33 = param_1 + 0x12;
      do {
        puVar19 = puVar40;
        uVar21 = uVar37 - 1;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",uVar21,puVar13,param_5,param_6,param_7,param_8);
        if (*(char *)((int)puVar33 + 0xb) == '\0') {
          if (*(char *)((int)puVar33 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",uVar21,puVar13,param_5,param_6,param_7,
                         param_8);
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())FUN_000d03b4)(0,"\n",uVar21,puVar13,param_5,param_6,param_7,param_8);
        }
        else {
          uVar21 = (uint)*(ushort *)((int)puVar33 + 6);
          param_5 = (uint)*(byte *)((int)puVar33 + 10);
          puVar13 = (uint *)((*(byte *)((int)puVar33 + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",uVar21,puVar13,param_5,param_6,param_7,param_8);
          if (*(char *)((int)puVar33 + 0xd) == '\0') {
            if (*(char *)((int)puVar33 + 0xb) == '\x02') {
              ((int (*)())FUN_000d03b4)(0," fbuf  ",uVar21,puVar13,param_5,param_6,param_7,param_8);
            }
            else if (*(char *)((int)puVar33 + 0xb) == '\x03') {
              ((int (*)())FUN_000d03b4)(0," back  ",uVar21,puVar13,param_5,param_6,param_7,param_8);
            }
            else {
              if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())FUN_000d03b4)(0,"       ",uVar21,puVar13,param_5,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0," biased",uVar21,puVar13,param_5,param_6,param_7,param_8);
          }
LAB_000d3b80:
          if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d3be0;
          uVar21 = (uint)*(ushort *)(puVar33 + 1);
          param_5 = (uint)*(byte *)(puVar33 + 2);
          puVar13 = (uint *)((*(byte *)((int)puVar33 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",uVar21,puVar13,param_5,param_6,param_7,param_8);
          if (*(char *)(puVar33 + 3) == '\0') goto LAB_000d3be0;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",uVar21,puVar13,param_5,param_6,param_7,param_8);
        }
        uVar37 = uVar37 + 1;
        if (*puVar35 != 1) break;
        puVar35 = puVar35 + 0x12;
        puVar40 = puVar19 + 0x12;
        puVar33 = puVar19;
      } while (uVar37 <= local_a0);
    }
    else {
      uVar37 = 1;
    }
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",uVar21,puVar13,param_5,param_6,param_7,param_8);
    if (uVar37 <= local_a0) {
      uVar28 = 0;
      puVar40 = param_1 + uVar37 * 0x12;
      local_a8 = 1;
      local_a4 = (uint *)0x0;
      local_e8 = 0;
      uVar21 = 0;
      do {
        uVar34 = *puVar40;
        if (((uVar34 == 2) && ((local_a8 != 0 || (*(char *)(puVar40 + 8) != '\0')))) ||
           (uVar28 == 0)) {
          if (uVar28 < 0x34) {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(byte)((char)(uVar28 / 0x34) + 0x2f) << 8;
          }
          cVar9 = (char)(uVar28 % 0x34);
          if (uVar28 % 0x34 < 0x1a) {
            cVar9 = cVar9 + 'A';
          }
          else {
            cVar9 = cVar9 + 'G';
          }
          (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT12(cVar9,(*(unsigned short *)((unsigned char *)&(local_2b8) + 1)));
          ((int (*)())FUN_000d03b4)(0," \n   Level %s:\n",&local_2b8,puVar13,uVar21,param_6,param_7,param_8);
          uVar28 = uVar28 + 1;
          uVar34 = *puVar40;
        }
        local_a8 = (uint)(uVar34 - 3 < 2);
        if (uVar34 == 2) {
          ((int (*)())FUN_000d03b4)(0,"     tex %02d    :  ",local_e8,puVar13,uVar21,param_6,param_7,param_8);
          uVar23 = (uint)*(ushort *)((int)puVar40 + 0xe);
          uVar34 = (uint)*(ushort *)(puVar40 + 3);
          uVar15 = (uint)*(byte *)((int)puVar40 + 0x19);
          if ((*(byte *)((int)puVar40 + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)puVar40 + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.rgba = ",uVar34,puVar13,uVar21,param_6,param_7,param_8);
          }
          puVar33 = (uint *)(uint)*(byte *)((int)puVar40 + 0x1a);
          puVar13 = (uint *)(*(byte *)((int)puVar40 + 0x1f) & 0xf ^ 0xf);
          if (&MACH_HEADER.cputype < puVar33) {
            ((int (*)())FUN_000d03b4)(0,"???()\n",uVar34,puVar13,uVar21,param_6,puVar33,param_8);
            param_7 = (char *)puVar33;
          }
          else {
            param_7 = (char *)(0);
            switch((int)puVar33) {
            case 0x0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",uVar34,puVar13,uVar21,param_6,param_7,param_8);
              break;
            case 0x1:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup(r%02d.%s, tex%02d)\n",uVar23,puVar13,uVar15,param_6,param_7,
                           param_8);
              break;
            case 0x2:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"kill(r%02d.%s)\n",uVar23,puVar13,uVar21,param_6,param_7,param_8);
              break;
            case 0x3:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(r%02d.%s, tex%02d)\n",uVar23,puVar13,uVar15,param_6,
                           param_7,param_8);
              break;
            case 0x4:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",uVar23,puVar13,uVar15,param_6,
                           param_7,param_8);
            }
          }
          local_e8 = local_e8 + 1;
        }
        else if ((1 < uVar34) && (uVar34 < 5)) {
          local_cc = (byte *)((int)puVar40 + 0x31);
          switch(*(undefined1 *)((int)puVar40 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            uVar34 = 0;
            bVar26 = true;
            uVar21 = 3;
            iVar32 = 1;
            break;
          case 1:
          case 4:
          case 5:
            uVar34 = 0;
            bVar26 = true;
            uVar21 = 1;
            iVar32 = 0;
            break;
          case 2:
            uVar34 = 3;
            bVar26 = true;
            uVar21 = 1;
            iVar32 = 0;
            break;
          default:
            uVar34 = 0;
            bVar26 = false;
            uVar21 = 0;
            iVar32 = 0;
            break;
          case 9:
            uVar34 = 0;
            bVar26 = true;
            uVar21 = 0;
            iVar32 = 0;
          }
          local_c8 = puVar40 + 0x10;
          if (*(byte *)(puVar40 + 0x10) < 0xc) {
            uVar23 = 1 << ((int)(char)*(byte *)(puVar40 + 0x10) & 0x3fU);
            if ((uVar23 & 0x61) == 0) {
              if ((uVar23 & 0xc) == 0) {
                if ((uVar23 & 0xf80) != 0) {
                  uVar34 = uVar34 | 1;
                }
              }
              else {
                uVar34 = 3;
              }
            }
            else {
              uVar34 = 7;
            }
          }
          local_ac = (byte *)(uint)*(byte *)((int)puVar40 + 0x3b);
          uVar36 = (uint)*(ushort *)((int)puVar40 + 0xe);
          puVar33 = (uint *)(uint)*(ushort *)(puVar40 + 4);
          puVar35 = (uint *)(uint)*(ushort *)((int)puVar40 + 0x12);
          puVar19 = (uint *)(uint)*(ushort *)((int)puVar40 + 0x1a);
          param_6 = (uint *)(uint)*(ushort *)(puVar40 + 7);
          param_7 = (char *)(uint)*(ushort *)((int)puVar40 + 0x1e);
          uVar31 = (uint)*(byte *)((int)puVar40 + 0x2a);
          uVar30 = (uint)*(byte *)((int)puVar40 + 0x2b);
          uVar29 = (uint)*(byte *)(puVar40 + 0xb);
          uVar15 = (uint)*(byte *)((int)puVar40 + 0x39);
          uVar23 = (uint)*(byte *)((int)puVar40 + 0x3a);
          local_b0 = (uint)*(byte *)((int)puVar40 + 0x2d);
          local_b4 = (uint)*(byte *)((int)puVar40 + 0x2e);
          local_b8 = (uint)*(byte *)((int)puVar40 + 0x2f);
          local_bc = (uint)*(byte *)(puVar40 + 0xf);
          local_c0 = (uint)*(byte *)((int)puVar40 + 0x3d);
          local_c4 = (uint)*(byte *)((int)puVar40 + 0x3e);
          if (bVar26) {
            uVar25 = (uint)(uVar31 - 0xf < 4);
          }
          else {
            uVar25 = 0;
          }
          bVar26 = bVar26 && uVar31 == 0x13;
          uVar21 = uVar21 & 1;
          if (uVar21 != 0) {
            uVar25 = uVar25 | uVar30 - 0xf < 4;
            bVar26 = bVar26 || uVar30 == 0x13;
          }
          if (iVar32 != 0) {
            uVar21 = -(uVar29 ^ 0x13);
            uVar25 = uVar25 | uVar29 - 0xf < 4;
            bVar26 = (bool)(bVar26 | (uVar29 ^ 0x13) == 0);
          }
          if ((uVar34 & 1) != 0) {
            uVar21 = -(uVar15 ^ 0xf);
            uVar25 = uVar25 | uVar15 - 0xc < 3;
            bVar26 = (bool)(bVar26 | (uVar15 ^ 0xf) == 0);
          }
          if ((uVar34 & 2) != 0) {
            uVar21 = -(uVar23 ^ 0xf);
            uVar25 = uVar25 | uVar23 - 0xc < 3;
            bVar26 = (bool)(bVar26 | (uVar23 ^ 0xf) == 0);
          }
          if ((uVar34 & 4) != 0) {
            uVar21 = -((uint)local_ac ^ 0xf);
            uVar25 = uVar25 | local_ac + -0xc < (byte *)((int)&MACH_HEADER.magic + 3);
            bVar26 = (bool)(bVar26 | ((uint)local_ac ^ 0xf) == 0);
          }
          puVar17 = puVar13;
          if (uVar25 != 0) {
            puVar16 = local_a4;
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.rgb = ",local_a4,puVar13,uVar21,uVar34,uVar25,
                         iVar32);
            cVar9 = *(char *)(puVar40 + 0xc);
            if (cVar9 == '\x01') {
              puVar17 = &local_2aa;
              ((int (*)())FUN_000d0450)(puVar17,uVar36,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d0450)(&local_2a0,puVar33,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2a0,puVar17,uVar21,uVar34,uVar25,iVar32);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar36,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2aa,puVar13,uVar21,uVar34,uVar25,iVar32);
              puVar17 = puVar13;
            }
            else if (cVar9 == '\x02') {
              puVar17 = &local_2aa;
              ((int (*)())FUN_000d0450)(puVar17,uVar36,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d0450)(&local_2a0,puVar33,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2a0,puVar17,uVar21,uVar34,uVar25,iVar32);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar36,puVar16,puVar13,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2aa,puVar13,uVar21,uVar34,uVar25,iVar32);
              puVar17 = puVar13;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",puVar16,puVar13,uVar21,uVar34,uVar25,iVar32);
              puVar17 = puVar13;
            }
          }
          puVar13 = puVar17;
          if (bVar26) {
            puVar16 = local_a4;
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.a   = ",local_a4,puVar17,uVar21,uVar34,uVar25,
                         iVar32);
            cVar9 = *(char *)((int)puVar40 + 0x3f);
            if (cVar9 == '\x01') {
              puVar13 = &local_2aa;
              ((int (*)())FUN_000d0450)(puVar13,puVar19,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d0450)(&local_2a0,param_6,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2a0,puVar13,uVar21,uVar34,uVar25,iVar32);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,puVar19,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2aa,puVar17,uVar21,uVar34,uVar25,iVar32);
              puVar13 = puVar17;
            }
            else if (cVar9 == '\x02') {
              puVar13 = &local_2aa;
              ((int (*)())FUN_000d0450)(puVar13,puVar19,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d0450)(&local_2a0,param_6,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2a0,puVar13,uVar21,uVar34,uVar25,iVar32);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,puVar19,puVar16,puVar17,uVar21,uVar34,uVar25);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2aa,puVar17,uVar21,uVar34,uVar25,iVar32);
              puVar13 = puVar17;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",puVar16,puVar17,uVar21,uVar34,uVar25,iVar32);
              puVar13 = puVar17;
            }
          }
          puVar17 = local_a4;
          ((int (*)())FUN_000d03b4)(0,"     alu %02d rgb:  ",local_a4,puVar13,uVar21,uVar34,uVar25,iVar32);
          uVar20 = (uint)*(byte *)((int)puVar40 + 0x15);
          bVar3 = *(byte *)(puVar40 + 5);
          if (uVar20 == 0) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar17,0,uVar21,uVar34,uVar25,iVar32);
          }
          else {
            puVar17 = (uint *)(uint)*(byte *)((int)puVar40 + 0x16);
            uVar20 = uVar20 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",puVar17,uVar20,uVar21,uVar34,uVar25,iVar32);
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar17,uVar20,uVar21,uVar34,uVar25,iVar32);
          }
          else {
            puVar17 = (uint *)(uint)*(ushort *)(puVar40 + 3);
            uVar20 = (uint)bVar3 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",puVar17,uVar20,uVar21,uVar34,uVar25,iVar32);
          }
          if (*(char *)((int)puVar40 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar17,uVar20,uVar21,uVar34,uVar25,iVar32);
          }
          local_68 = auStack_1fc;
          local_64 = auStack_1dc;
          ((int (*)())FUN_000d0488)(local_68,uVar36,puVar33,puVar35,puVar19,param_6,param_7,uVar31);
          local_60 = auStack_1bc;
          puVar17 = auStack_19c;
          ((int (*)())FUN_000d0488)(local_64,uVar36,puVar33,puVar35,puVar19,param_6,param_7,uVar30);
          ((int (*)())FUN_000d0488)(local_60,uVar36,puVar33,puVar35,puVar19,param_6,param_7,uVar29);
          puVar13 = auStack_17c;
          ((int (*)())FUN_000d0888)(puVar17,uVar36,puVar33,puVar35,puVar19,param_6,param_7,uVar15);
          puVar16 = auStack_23c;
          ((int (*)())FUN_000d0888)(puVar13,uVar36,puVar33,puVar35,puVar19,param_6,param_7,uVar23);
          param_8 = local_ac;
          ((int (*)())FUN_000d0888)(puVar16,uVar36,puVar33,puVar35,puVar19,param_6,param_7,local_ac);
          bVar3 = *local_cc;
          if (bVar3 < 0xb) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              puVar33 = local_68;
              puVar35 = local_64;
              puVar19 = local_60;
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_68,local_64,local_60,param_6,param_7,param_8);
              break;
            case 1:
              puVar33 = local_68;
              puVar35 = local_64;
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",local_68,local_64,puVar19,param_6,param_7,param_8);
              break;
            case 2:
              puVar33 = local_68;
              puVar35 = puVar17;
              puVar19 = local_64;
              param_6 = puVar13;
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",local_68,puVar17,local_64,puVar13,param_7,param_8);
              break;
            case 3:
              puVar33 = local_68;
              puVar35 = local_64;
              puVar19 = local_60;
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",local_68,local_64,local_60,param_6,param_7,param_8);
              break;
            case 4:
              puVar33 = local_68;
              puVar35 = local_64;
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_68,local_64,puVar19,param_6,param_7,param_8);
              break;
            case 5:
              puVar33 = local_68;
              puVar35 = local_64;
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_68,local_64,puVar19,param_6,param_7,param_8);
              break;
            case 6:
              goto switchD_000d4578_caseD_6;
            case 7:
              puVar33 = local_68;
              puVar35 = local_64;
              puVar19 = local_60;
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_68,local_64,local_60,param_6,param_7,param_8);
              break;
            case 8:
              puVar33 = local_68;
              puVar35 = local_64;
              puVar19 = local_60;
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_68,local_64,local_60,param_6,param_7,param_8);
              break;
            case 9:
              puVar33 = local_68;
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_68,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",puVar33,puVar35,puVar19,param_6,param_7,param_8);
            }
          }
          else {
switchD_000d4578_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)((int)puVar40 + 0x32);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          puVar33 = local_a4;
          ((int (*)())FUN_000d03b4)(0,"          alpha:  ",local_a4,puVar35,puVar19,param_6,param_7,param_8);
          cVar9 = *(char *)(puVar40 + 8);
          bVar26 = *(char *)((int)puVar40 + 0x21) != '\0';
          cVar5 = *(char *)((int)puVar40 + 0x23);
          if (bVar26) {
            puVar33 = (uint *)(uint)*(byte *)((int)puVar40 + 0x22);
            ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          bVar2 = cVar5 != '\0';
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          if ((!bVar26) && (!bVar2)) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          if (cVar9 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          else {
            puVar33 = (uint *)(uint)*(ushort *)(puVar40 + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          if (*(char *)((int)puVar40 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar33,puVar35,puVar19,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)local_c8;
          if (bVar3 < 0xc) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",puVar33,puVar35,puVar19,param_6,param_7,param_8);
              puVar17 = puVar33;
              puVar13 = puVar35;
              puVar16 = puVar19;
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",puVar17,puVar13,puVar19,param_6,param_7,param_8);
              puVar16 = puVar19;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",puVar17,puVar13,puVar19,param_6,param_7,param_8);
              puVar16 = puVar19;
              break;
            case 4:
              goto switchD_000d489c_caseD_4;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",puVar17,puVar35,puVar19,param_6,param_7,param_8);
              puVar13 = puVar35;
              puVar16 = puVar19;
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",puVar17,puVar35,puVar19,param_6,param_7,param_8);
              puVar13 = puVar35;
              puVar16 = puVar19;
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",puVar17,puVar35,puVar19,param_6,param_7,param_8);
              puVar13 = puVar35;
              puVar16 = puVar19;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",puVar17,puVar35,puVar19,param_6,param_7,param_8);
              puVar13 = puVar35;
              puVar16 = puVar19;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",puVar17,puVar35,puVar19,param_6,param_7,param_8);
              puVar13 = puVar35;
              puVar16 = puVar19;
            }
          }
          else {
switchD_000d489c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar33,puVar35,puVar19,param_6,param_7,param_8);
            puVar17 = puVar33;
            puVar13 = puVar35;
            puVar16 = puVar19;
          }
          bVar3 = *(byte *)((int)puVar40 + 0x41);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",puVar17,puVar13,puVar16,param_6,param_7,param_8);
          }
          if (*(char *)(puVar40 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d post-NOP\n",local_a4,puVar13,puVar16,param_6,param_7,
                         param_8);
          }
          local_a4 = (uint *)((int)local_a4 + 1);
        }
        uVar37 = uVar37 + 1;
        puVar40 = puVar40 + 0x12;
        param_5 = local_a0;
        uVar21 = local_a0;
      } while (uVar37 <= local_a0);
    }
    uVar28 = 0;
    ((int (*)())FUN_000d03b4)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    uVar37 = param_1[2];
    uVar21 = uStack0000001c;
    puVar13 = puStack00000020;
    ((int (*)())FUN_000d03b4)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    do {
      uVar34 = *param_1;
      if (uVar34 < 5) {
        switch(uVar34) {
        case 0:
          uVar21 = param_1[1];
          puVar13 = (uint *)param_1[2];
          param_5 = (uint)*(byte *)(param_1 + 3);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0xd);
          param_7 = (char *)(uint)*(ushort *)(param_1 + 5);
          param_8 = (byte *)(uint)*(ushort *)((int)param_1 + 0x16);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                       ,uVar21,puVar13,param_5,param_6,param_7,param_8);
          break;
        case 1:
          uVar21 = (uint)*(ushort *)(param_1 + 1);
          puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 6);
          param_5 = (uint)*(byte *)(param_1 + 2);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 9);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 10);
          param_8 = (byte *)(uint)*(byte *)((int)param_1 + 0xb);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,uVar21,puVar13,param_5,param_6,param_7,param_8);
          break;
        case 2:
          uVar21 = (uint)*(ushort *)(param_1 + 3);
          puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 0xe);
          param_5 = (uint)*(byte *)((int)param_1 + 0x19);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0x1a);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 0x1f);
          param_8 = (byte *)(uint)*(byte *)(param_1 + 8);
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",uVar21,puVar13,
                       param_5,param_6,param_7,param_8);
          break;
        default:
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_ALU    : \n",uVar21,puVar13,param_5,param_6,
                       0,param_8);
          ((int (*)())FUN_000d03b4)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                       (uint)*(ushort *)(param_1 + 3),(uint)*(ushort *)((int)param_1 + 0xe),
                       (uint)*(ushort *)(param_1 + 4),(uint)*(ushort *)((int)param_1 + 0x12),
                       (uint)*(byte *)(param_1 + 5),(uint)*(byte *)((int)param_1 + 0x15));
          ((int (*)())FUN_000d03b4)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                       (uint)*(ushort *)(param_1 + 6),(uint)*(ushort *)((int)param_1 + 0x1a),
                       (uint)*(ushort *)(param_1 + 7),(uint)*(ushort *)((int)param_1 + 0x1e),
                       (uint)*(byte *)(param_1 + 8),(uint)*(byte *)((int)param_1 + 0x21));
          ((int (*)())FUN_000d03b4)(0,
                       "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,(uint)*(byte *)((int)param_1 + 0x2a),(uint)*(byte *)((int)param_1 + 0x2d),
                       (uint)*(byte *)((int)param_1 + 0x2b),(uint)*(byte *)((int)param_1 + 0x2e),
                       (uint)*(byte *)(param_1 + 0xb),(uint)*(byte *)((int)param_1 + 0x2f));
          uVar21 = (uint)*(byte *)((int)param_1 + 0x39);
          puVar13 = (uint *)(uint)*(byte *)(param_1 + 0xf);
          param_5 = (uint)*(byte *)((int)param_1 + 0x3a);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0x3d);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 0x3b);
          param_8 = (byte *)(uint)*(byte *)((int)param_1 + 0x3e);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,uVar21,puVar13,param_5,param_6,param_7,param_8);
        }
      }
      uVar28 = uVar28 + 1;
      param_1 = param_1 + 0x12;
    } while (uVar28 <= uVar37);
    ((int (*)())FUN_000d03b4)(0,"+++ END_PSN                         # \"%s\" %d\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
  }
  else {
    uVar21 = param_1[2];
    puVar13 = puStack00000020;
    local_7c = uVar21;
    ((int (*)())FUN_000d03b4)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 puStack00000020,param_4,uVar21,param_6,param_7,param_8);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",puVar13,param_4,uVar21,param_6,param_7,param_8);
    }
    else {
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",puVar13,param_4,uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(param_1 + 6),param_4,
                   uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)param_1 + 0x1a),
                   param_4,uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(param_1 + 7),param_4,
                   uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)param_1 + 0x1e),
                   param_4,uVar21,param_6,param_7,param_8);
      if (*(byte *)((int)param_1 + 0xe) != 0) {
        ((int (*)())FUN_000d03b4)(0,"     UMRT_EN:               %3d\n",(uint)*(byte *)((int)param_1 + 0xe),
                     param_4,uVar21,param_6,param_7,param_8);
      }
      ((int (*)())FUN_000d03b4)(0,"     CF Instructions:       %3d\n",(uint)*(ushort *)(param_1 + 8),param_4,
                   uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)param_1 + 0x22),
                   param_4,uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(param_1 + 9),param_4,
                   uVar21,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Start Addr:            %3d\n",(uint)*(ushort *)(param_1 + 4),param_4,
                   uVar21,param_6,param_7,param_8);
      puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 0x12);
      ((int (*)())FUN_000d03b4)(0,"     End Addr:              %3d\n",puVar13,param_4,uVar21,param_6,param_7,
                   param_8);
      ((int (*)())FUN_000d03b4)(0," \n",puVar13,param_4,uVar21,param_6,param_7,param_8);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",puVar13,param_4,uVar21,param_6,param_7,param_8);
    if ((param_1[0x12] == 1) && (0 < (int)local_7c)) {
      puVar35 = param_1 + 0x24;
      iVar32 = 1;
      puVar40 = puVar35;
      puVar33 = param_1 + 0x12;
      do {
        puVar19 = puVar40;
        puVar13 = (uint *)(iVar32 + -1);
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",puVar13,param_4,uVar21,param_6,param_7,param_8);
        cVar9 = *(char *)((int)puVar33 + 0xb);
        if (cVar9 == '\0') {
          if (*(char *)((int)puVar33 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",puVar13,param_4,uVar21,param_6,param_7,
                         param_8);
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,uVar21,param_6,param_7,param_8);
        }
        else {
          uVar37 = *(byte *)((int)puVar33 + 0xf) & 0xf ^ 0xf;
          if (cVar9 == '\x01') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            uVar21 = (uint)*(byte *)((int)puVar33 + 10);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",puVar13,param_4,uVar21,param_6,param_7,param_8);
            if (*(char *)((int)puVar33 + 0xd) == '\0') {
              cVar9 = *(char *)((int)puVar33 + 0xb);
            }
            else {
              ((int (*)())FUN_000d03b4)(0," biased",puVar13,param_4,uVar21,param_6,param_7,param_8);
              cVar9 = *(char *)((int)puVar33 + 0xb);
            }
          }
          if (cVar9 == '\x02') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = fbuf",puVar13,param_4,uVar21,param_6,param_7,param_8);
          }
          else if (cVar9 == '\x03') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = back",puVar13,param_4,uVar21,param_6,param_7,param_8);
          }
          else {
            if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())FUN_000d03b4)(0,"       ",puVar13,param_4,uVar21,param_6,param_7,param_8);
          }
LAB_000d1afc:
          if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d1b5c;
          puVar13 = (uint *)(uint)*(ushort *)(puVar33 + 1);
          uVar21 = (uint)*(byte *)(puVar33 + 2);
          param_4 = (char *)((*(byte *)((int)puVar33 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",puVar13,param_4,uVar21,param_6,param_7,param_8);
          if (*(char *)(puVar33 + 3) == '\0') goto LAB_000d1b5c;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",puVar13,param_4,uVar21,param_6,param_7,param_8);
        }
        iVar32 = iVar32 + 1;
        if (*puVar35 != 1) break;
        puVar35 = puVar35 + 0x12;
        puVar40 = puVar19 + 0x12;
        puVar33 = puVar19;
      } while (iVar32 <= (int)local_7c);
    }
    else {
      iVar32 = 1;
    }
    local_5c = 0x1a1848;
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",puVar13,param_4,uVar21,param_6,param_7,param_8);
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00,puVar13,param_4,uVar21,param_6,param_7,param_8);
    if (iVar32 <= (int)local_7c) {
      local_78 = 0;
      puVar40 = param_1 + iVar32 * 0x12;
      local_70 = 0;
      local_f0 = (uint *)0x0;
      local_f4 = 0;
      local_f8 = 0;
      local_74 = 0;
      local_ec = 0;
      do {
        if (*(char *)(puVar40 + 7) == '\0') {
          local_282 = local_282 & 0xffffff;
        }
        else {
          param_7 = " ign_unc";
          (*(unsigned char *)((unsigned char *)&(local_282) + 0)) = s_ign_unc_001a734c[0];
          (*(unsigned char *)((unsigned char *)&(local_282) + 1)) = s_ign_unc_001a734c[1];
          (*(unsigned char *)((unsigned char *)&(local_282) + 2)) = s_ign_unc_001a734c[2];
          (*(unsigned char *)((unsigned char *)&(local_282) + 3)) = s_ign_unc_001a734c[3];
          local_27e[0] = s_ign_unc_001a734c[4];
          local_27e[1] = s_ign_unc_001a734c[5];
          local_27e[2] = s_ign_unc_001a734c[6];
          local_27e[3] = s_ign_unc_001a734c[7];
          local_27a = s_ign_unc_001a734c[8];
        }
        if (*(char *)(puVar40 + 1) == '\0') {
          local_2b4 = local_2b4 & 0xffffff;
        }
        else {
          param_7 = " sem_wait";
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 0)) = s_sem_wait_001a7358[0];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 1)) = s_sem_wait_001a7358[1];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 2)) = s_sem_wait_001a7358[2];
          (*(unsigned char *)((unsigned char *)&(local_2b4) + 3)) = s_sem_wait_001a7358[3];
          local_2b0[0] = s_sem_wait_001a7358[4];
          local_2b0[1] = s_sem_wait_001a7358[5];
          local_2b0[2] = s_sem_wait_001a7358[6];
          local_2b0[3] = s_sem_wait_001a7358[7];
          local_2ac[0] = s_sem_wait_001a7358[8];
          local_2ac[1] = s_sem_wait_001a7358[9];
        }
        if (*(char *)((int)puVar40 + 0xb) == '\0') {
          local_28c = local_28c & 0xffffff;
        }
        else {
          param_7 = " alu_wait";
          (*(unsigned char *)((unsigned char *)&(local_28c) + 0)) = s_alu_wait_001a7364[0];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 1)) = s_alu_wait_001a7364[1];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 2)) = s_alu_wait_001a7364[2];
          (*(unsigned char *)((unsigned char *)&(local_28c) + 3)) = s_alu_wait_001a7364[3];
          local_288[0] = s_alu_wait_001a7364[4];
          local_288[1] = s_alu_wait_001a7364[5];
          local_288[2] = s_alu_wait_001a7364[6];
          local_288[3] = s_alu_wait_001a7364[7];
          local_284[0] = s_alu_wait_001a7364[8];
          local_284[1] = s_alu_wait_001a7364[9];
        }
        uVar37 = *puVar40;
        if (uVar37 == 2) {
          ((int (*)())FUN_000d03b4)(0,"  %d tex %02d    :  ",local_70,local_f4,uVar21,param_6,param_7,param_8);
          bVar3 = *(byte *)((int)puVar40 + 0x1d);
          uVar7 = *(ushort *)((int)puVar40 + 0xe);
          puVar13 = (uint *)(uint)uVar7;
          uVar8 = *(ushort *)(puVar40 + 3);
          uVar21 = (*(byte *)((int)puVar40 + 0x1e) & 0x1f) << 3 | (uint)bVar3;
          puVar33 = (uint *)(uint)*(byte *)((int)puVar40 + 0x19);
          bVar26 = (bVar3 & 1) != 0;
          bVar4 = *(byte *)(puVar40 + 5);
          if (bVar26) {
            pcVar14 = (char *)((bVar4 >> 4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar14 = "_";
          }
          bVar2 = (bVar3 & 2) != 0;
          if (bVar2) {
            pcVar18 = (char *)((bVar4 >> 2 & 0xc) + 0x1dc259);
          }
          else {
            pcVar18 = "_";
          }
          bVar39 = (bVar3 & 4) != 0;
          if (bVar39) {
            pcVar22 = (char *)((bVar4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar22 = "_";
          }
          bVar1 = (uVar21 >> 3 & 1) != 0;
          if (bVar1) {
            pcVar24 = (char *)((bVar4 & 3) * 4 + 0x1dc259);
          }
          else {
            pcVar24 = "_";
          }
          FUN_001a32d0(auStack_25a,"%s%s%s%s",pcVar14,pcVar18,pcVar22,pcVar24,uVar21,param_8);
          if ((*(byte *)((int)puVar40 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)puVar40 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",(uint)uVar8,auStack_25a,pcVar22,pcVar24,uVar21,param_8);
          }
          if (*(byte *)((int)puVar40 + 0x1a) == 2) {
            bVar3 = *(byte *)((int)puVar40 + 0x15);
            param_7 = (char *)(uint)bVar3;
            if (bVar26) {
              pcVar18 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
            }
            else {
              pcVar18 = "-";
            }
            if (bVar2) {
              param_4 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
            }
            else {
              param_4 = "-";
            }
            if (bVar39) {
              pcVar14 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar14 = "-";
            }
            if (bVar1) {
              param_6 = (uint *)(((uint)param_7 & 3) * 4 + 0x1dc259);
            }
            else {
              param_6 = (uint *)"-";
            }
          }
          else {
            local_78 = (uint)*(byte *)((int)puVar40 + 0x1f);
            bVar3 = *(byte *)((int)puVar40 + 0x15);
            param_7 = (char *)(uint)bVar3;
            if ((*(byte *)((int)puVar40 + 0x1f) & 1) == 0) {
              param_8 = (byte *)(bVar3 & 0xc);
              param_7 = (char *)(((uint)param_7 & 3) * 4);
              param_6 = (uint *)((int)param_7 + 0x1dc259);
              pcVar18 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              param_4 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar14 = (char *)(param_8 + 0x1dc259);
            }
            else {
              pcVar18 = "-";
              param_4 = pcVar18;
              pcVar14 = pcVar18;
              param_6 = (uint *)pcVar18;
            }
          }
          puVar35 = auStack_24b;
          FUN_001a32d0(puVar35,"%s%s%s%s",pcVar18,param_4,pcVar14,param_6,param_7,param_8);
          if ((uVar7 & 0x4000) == 0) {
            FUN_001a32d0(auStack_278,"r%02d",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          else {
            puVar13 = (uint *)((uint)puVar13 & 0xbfff);
            FUN_001a32d0(auStack_278,"r[AL+%02d]",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          puVar19 = auStack_278;
          if (*(char *)((int)puVar40 + 0x1b) == '\0') {
            local_296 = local_296 & 0xffffff;
          }
          else {
            param_7 = " sem_grab";
            (*(unsigned char *)((unsigned char *)&(local_296) + 0)) = s_sem_grab_001a73ac[0];
            (*(unsigned char *)((unsigned char *)&(local_296) + 1)) = s_sem_grab_001a73ac[1];
            (*(unsigned char *)((unsigned char *)&(local_296) + 2)) = s_sem_grab_001a73ac[2];
            (*(unsigned char *)((unsigned char *)&(local_296) + 3)) = s_sem_grab_001a73ac[3];
            local_292[0] = s_sem_grab_001a73ac[4];
            local_292[1] = s_sem_grab_001a73ac[5];
            local_292[2] = s_sem_grab_001a73ac[6];
            local_292[3] = s_sem_grab_001a73ac[7];
            local_28e[0] = s_sem_grab_001a73ac[8];
            local_28e[1] = s_sem_grab_001a73ac[9];
          }
          bVar3 = *(byte *)((int)puVar40 + 0x1a);
          if (bVar3 < 8) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",puVar13,param_4,pcVar14,param_6,param_7,param_8);
              break;
            case 1:
              param_6 = &local_2b4;
              param_7 = (char *)&local_296;
              ((int (*)())FUN_000d03b4)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",puVar19,puVar35,puVar33,param_6,
                           param_7,&local_28c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              pcVar14 = (char *)puVar33;
              break;
            case 2:
              pcVar14 = (char *)&local_2b4;
              param_6 = &local_296;
              param_7 = (char *)&local_28c;
              ((int (*)())FUN_000d03b4)(0,"kill(%s.%s)%s%s%s",puVar19,puVar35,pcVar14,param_6,param_7,param_8);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              break;
            case 3:
              param_6 = &local_2b4;
              param_7 = (char *)&local_296;
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",puVar19,puVar35,puVar33,param_6,
                           param_7,&local_28c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              pcVar14 = (char *)puVar33;
              break;
            case 4:
              param_6 = &local_2b4;
              param_7 = (char *)&local_296;
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",puVar19,puVar35,puVar33,
                           param_6,param_7,&local_28c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              pcVar14 = (char *)puVar33;
              break;
            case 5:
              param_6 = &local_2b4;
              param_7 = (char *)&local_296;
              ((int (*)())FUN_000d03b4)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",puVar19,puVar35,puVar33,param_6,
                           param_7,&local_28c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              pcVar14 = (char *)puVar33;
              break;
            case 6:
              bVar3 = *(byte *)((int)puVar40 + 0x16);
              uVar21 = (uint)bVar3;
              bVar26 = (local_78 & 1) == 0;
              if (bVar26) {
                param_8 = (byte *)(bVar3 & 0xc);
                uVar21 = (uVar21 & 3) * 4;
                pcVar18 = (char *)(uVar21 + 0x1dc259);
                pcVar22 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
                pcVar14 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
                pbVar27 = param_8 + 0x1dc259;
              }
              else {
                pcVar22 = "-";
                pcVar14 = pcVar22;
                pbVar27 = (byte *)pcVar22;
                pcVar18 = pcVar22;
              }
              param_6 = auStack_269;
              FUN_001a32d0(param_6,"%s%s%s%s",pcVar22,pcVar14,pbVar27,pcVar18,uVar21,param_8);
              bVar3 = *(byte *)((int)puVar40 + 0x16);
              uVar21 = (uint)bVar3;
              pcVar14 = (char *)(uint)*(ushort *)(puVar40 + 4);
              if (bVar26) {
                param_8 = (byte *)(bVar3 & 0xc);
                uVar21 = (uVar21 & 3) * 4;
                pcVar22 = (char *)(uVar21 + 0x1dc259);
                pcVar24 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
                pcVar18 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
                pbVar27 = param_8 + 0x1dc259;
              }
              else {
                pcVar24 = "-";
                pcVar18 = pcVar24;
                pbVar27 = (byte *)pcVar24;
                pcVar22 = pcVar24;
              }
              FUN_001a32d0(auStack_23c,"%s%s%s%s",pcVar24,pcVar18,pbVar27,pcVar22,uVar21,param_8);
              param_7 = (char *)(uint)*(ushort *)((int)puVar40 + 0x12);
              ((int (*)())FUN_000d03b4)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",puVar19,
                           puVar35,pcVar14,param_6,param_7,auStack_23c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              break;
            case 7:
              param_6 = &local_2b4;
              param_7 = (char *)&local_296;
              ((int (*)())FUN_000d03b4)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",puVar19,puVar35,puVar33,
                           param_6,param_7,&local_28c);
              puVar13 = puVar19;
              param_4 = (char *)puVar35;
              pcVar14 = (char *)puVar33;
            }
          }
          else {
            puVar13 = &local_2b4;
            param_4 = (char *)&local_296;
            pcVar14 = (char *)&local_28c;
            param_6 = &local_282;
            ((int (*)())FUN_000d03b4)(0,"UNKNOWN_OP%s%s%s%s",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          pbVar27 = (byte *)((int)puVar40 + 5);
          if (*(char *)((int)puVar40 + 5) != '\0') {
            if (*(char *)((int)puVar40 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(local_2b8) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *pbVar27;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 1:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.rgb",puVar13,param_4,pcVar14,param_6,param_7,pbVar27);
                break;
              case 2:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.rrr",puVar13,param_4,pcVar14,param_6,param_7,pbVar27);
                break;
              case 3:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.ggg",puVar13,param_4,pcVar14,param_6,param_7,pbVar27);
                break;
              case 4:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.bbb",puVar13,param_4,pcVar14,param_6,param_7,pbVar27);
                break;
              case 5:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.aaa",puVar13,param_4,pcVar14,param_6,param_7,pbVar27);
              }
            }
          }
          param_8 = (byte *)((int)puVar40 + 7);
          if (*(char *)((int)puVar40 + 7) != '\0') {
            if (*(char *)(puVar40 + 2) == '\0') {
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(local_2b8) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *param_8;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 0:
                break;
              default:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.a",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 2:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.r",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 3:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.g",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 4:
                puVar13 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.b",puVar13,param_4,pcVar14,param_6,param_7,param_8);
              }
            }
          }
          if (*(char *)((int)puVar40 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0," write_inactive",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          uVar37 = *puVar40;
          local_f4 = local_f4 + 1;
        }
        if ((uVar37 == 3) || (uVar37 == 4)) {
          local_74 = (uint)*(byte *)((int)puVar40 + 0x43);
          local_ec = (uint)*(byte *)(puVar40 + 0x11);
          switch(*(undefined1 *)((int)puVar40 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar26 = true;
            bVar39 = true;
            bVar2 = true;
            local_98 = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            bVar26 = true;
            bVar39 = true;
            bVar2 = false;
            local_98 = 0;
            break;
          case 2:
            bVar26 = true;
            local_98 = 3;
            bVar39 = true;
            bVar2 = false;
            break;
          default:
            bVar26 = false;
            bVar39 = false;
            bVar2 = false;
            local_98 = 0;
            break;
          case 9:
            bVar26 = true;
            bVar39 = false;
            bVar2 = false;
            local_98 = 0;
          }
          if (*(byte *)(puVar40 + 0x10) < 0x10) {
            uVar21 = 1 << ((int)(char)*(byte *)(puVar40 + 0x10) & 0x3fU);
            if ((uVar21 & 0x61) == 0) {
              if ((uVar21 & 0xc00c) == 0) {
                if ((uVar21 & 0x3f80) != 0) {
                  local_98 = local_98 | 1;
                }
              }
              else {
                local_98 = 3;
              }
            }
            else {
              local_98 = 7;
            }
          }
          local_e4 = *(byte *)((int)puVar40 + 0x2a) & 0xffffff7f;
          uVar37 = (uint)*(byte *)(puVar40 + 0xb);
          local_e0 = *(byte *)((int)puVar40 + 0x2b) & 0xffffff7f;
          uVar28 = (uint)*(byte *)((int)puVar40 + 0x3a);
          uVar21 = (uint)*(byte *)((int)puVar40 + 0x3b);
          local_dc = *(byte *)(puVar40 + 0xb) & 0xffffff7f;
          local_d8 = *(byte *)((int)puVar40 + 0x39) & 0xffffff7f;
          local_d4 = *(byte *)((int)puVar40 + 0x3a) & 0xffffff7f;
          local_d0 = *(byte *)((int)puVar40 + 0x3b) & 0xffffff7f;
          local_6c = *(ushort *)(puVar40 + 10);
          uVar34 = (uint)*(ushort *)((int)puVar40 + 0xe);
          puVar13 = (uint *)(uint)*(ushort *)(puVar40 + 4);
          puVar33 = (uint *)(uint)*(ushort *)((int)puVar40 + 0x12);
          puVar35 = (uint *)(uint)*(ushort *)((int)puVar40 + 0x1a);
          param_6 = (uint *)(uint)*(ushort *)(puVar40 + 7);
          param_7 = (char *)(uint)*(ushort *)((int)puVar40 + 0x1e);
          uVar7 = *(ushort *)(puVar40 + 9);
          uVar8 = *(ushort *)((int)puVar40 + 0x26);
          local_9c = (uint)*(byte *)(puVar40 + 0xe);
          cVar9 = *(char *)((int)puVar40 + 0x36);
          cVar5 = *(char *)((int)puVar40 + 0x37);
          local_80 = (uint)*(byte *)((int)puVar40 + 0x2d);
          local_84 = (uint)*(byte *)((int)puVar40 + 0x2e);
          local_88 = (uint)*(byte *)((int)puVar40 + 0x2f);
          local_8c = (uint)*(byte *)(puVar40 + 0xf);
          local_90 = (uint)*(byte *)((int)puVar40 + 0x3d);
          local_94 = (uint)*(byte *)((int)puVar40 + 0x3e);
          if (bVar26) {
            bVar26 = local_e4 != 3;
            if (bVar26) {
LAB_000d2654:
              bVar1 = false;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar7);
              bVar1 = true;
              if (iVar10 != 0) goto LAB_000d2654;
            }
            if (!bVar26) {
              bVar26 = true;
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar7);
              if (iVar10 != 0) goto LAB_000d2674;
            }
            bVar26 = false;
          }
          else {
            bVar26 = false;
            bVar1 = false;
          }
LAB_000d2674:
          if (bVar39) {
            bVar39 = local_e0 != 3;
            if (bVar39) {
LAB_000d269c:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar8);
              bVar3 = 1;
              if (iVar10 != 0) goto LAB_000d269c;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (bVar39) {
LAB_000d26bc:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar8);
              bVar3 = 1;
              if (iVar10 == 0) goto LAB_000d26bc;
            }
            bVar26 = (bool)(bVar26 | bVar3);
          }
          if (bVar2) {
            bVar2 = local_dc != 3;
            if (bVar2) {
LAB_000d26ec:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)local_6c);
              bVar3 = 1;
              if (iVar10 != 0) goto LAB_000d26ec;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (bVar2) {
LAB_000d270c:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)local_6c);
              bVar3 = 1;
              if (iVar10 == 0) goto LAB_000d270c;
            }
            bVar26 = (bool)(bVar26 | bVar3);
          }
          if ((local_98 & 1) != 0) {
            if ((local_d8 != 3) || (bVar3 = 1, cVar9 == '\x03')) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if ((local_d8 != 3) || (bVar3 = 1, cVar9 != '\x03')) {
              bVar3 = 0;
            }
            bVar26 = (bool)(bVar26 | bVar3);
          }
          uVar23 = local_98 & 2;
          if (uVar23 != 0) {
            if ((local_d4 != 3) || (bVar3 = 1, cVar5 == '\x03')) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if ((local_d4 != 3) || (bVar3 = 1, cVar5 != '\x03')) {
              bVar3 = 0;
            }
            bVar26 = (bool)(bVar26 | bVar3);
          }
          if ((local_98 & 4) != 0) {
            if ((local_d0 != 3) || (bVar3 = 1, uVar23 = local_9c, local_9c == 3)) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if ((local_d0 != 3) || (bVar3 = 1, local_9c != 3)) {
              bVar3 = 0;
            }
            bVar26 = (bool)(bVar26 | bVar3);
          }
          if (bVar1) {
            iVar10 = local_70;
            puVar19 = local_f0;
            dVar41 = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.rgb = ",local_70,local_f0,
                                          uVar23,uVar21,uVar37,uVar28);
            cVar9 = *(char *)(puVar40 + 0xc);
            if (cVar9 == '\x01') {
              dVar41 = (double)((double (*)())FUN_000d10dc)(&local_2a0,uVar34,iVar10,puVar19,uVar23,uVar21,uVar37,
                                            uVar28,dVar41);
              ((double (*)())FUN_000d10dc)(&local_2aa,puVar13,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2aa,&local_2a0,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\0') {
              ((double (*)())FUN_000d10dc)(&local_2a0,uVar34,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2a0,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x02') {
              dVar41 = (double)((double (*)())FUN_000d10dc)(&local_2a0,uVar34,iVar10,puVar19,uVar23,uVar21,uVar37,
                                            uVar28,dVar41);
              ((double (*)())FUN_000d10dc)(&local_2aa,puVar13,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2aa,&local_2a0,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x03') {
              ((double (*)())FUN_000d10dc)(&local_2a0,uVar34,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2a0,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",iVar10,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
          }
          if (bVar26) {
            iVar10 = local_70;
            puVar19 = local_f0;
            dVar41 = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.a   = ",local_70,local_f0,
                                          uVar23,uVar21,uVar37,uVar28);
            cVar9 = *(char *)((int)puVar40 + 0x3f);
            if (cVar9 == '\x01') {
              dVar41 = (double)((double (*)())FUN_000d10dc)(&local_2a0,puVar35,iVar10,puVar19,uVar23,uVar21,uVar37,
                                            uVar28,dVar41);
              ((double (*)())FUN_000d10dc)(&local_2aa,param_6,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2aa,&local_2a0,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\0') {
              ((double (*)())FUN_000d10dc)(&local_2a0,puVar35,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2a0,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x02') {
              dVar41 = (double)((double (*)())FUN_000d10dc)(&local_2a0,puVar35,iVar10,puVar19,uVar23,uVar21,uVar37,
                                            uVar28,dVar41);
              ((double (*)())FUN_000d10dc)(&local_2aa,param_6,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2aa,&local_2a0,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x03') {
              ((double (*)())FUN_000d10dc)(&local_2a0,puVar35,iVar10,puVar19,uVar23,uVar21,uVar37,uVar28,dVar41);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2a0,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",iVar10,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
          }
          puVar19 = local_f0;
          ((int (*)())FUN_000d03b4)(0,"  %d alu %02d rgb:  ",local_70,local_f0,uVar23,uVar21,uVar37,uVar28);
          uVar15 = (uint)*(byte *)((int)puVar40 + 0x15);
          bVar3 = *(byte *)(puVar40 + 5);
          if (uVar15 == 0) {
LAB_000d2b24:
            ((int (*)())FUN_000d03b4)(0,"           ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
          }
          else if (*puVar40 == 3) {
            iVar10 = uVar15 * 4;
            uVar15 = (uint)*(byte *)((int)puVar40 + 0x16);
            puVar19 = (uint *)(iVar10 + 0x1dc239);
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
          }
          else {
            if (*puVar40 != 4) goto LAB_000d2b24;
            uVar15 = uVar15 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"pred.%s = ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
            cVar9 = *(char *)((int)puVar40 + 0x16);
            if (cVar9 == '\x01') {
              ((int (*)())FUN_000d03b4)(0,"(<) ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d03b4)(0,"(==) ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x02') {
              ((int (*)())FUN_000d03b4)(0,"(>=) ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d03b4)(0,"(!=) ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
            }
          }
          if (bVar3 == 0) {
            dVar41 = (double)((int (*)())FUN_000d03b4)(0,"          ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28)
            ;
          }
          else {
            uVar15 = (uint)*(ushort *)(puVar40 + 3);
            puVar19 = (uint *)((uint)bVar3 * 4 + 0x1dc239);
            dVar41 = (double)((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28
                                         );
          }
          if (*(char *)((int)puVar40 + 0x33) != '\0') {
            dVar41 = (double)((int (*)())FUN_000d03b4)(0,"clamped ",uVar15,puVar19,uVar23,uVar21,uVar37,uVar28);
          }
          puVar19 = auStack_21c;
          dVar41 = (double)((double (*)())FUN_000d13a4)(puVar19,uVar34,puVar13,puVar33,puVar35,param_6,param_7,
                                        local_e4,dVar41);
          param_4 = (char *)auStack_17c;
          dVar41 = (double)((double (*)())FUN_000d13a4)(param_4,uVar34,puVar13,puVar33,puVar35,param_6,param_7,
                                        local_e0,dVar41);
          puVar17 = auStack_19c;
          dVar41 = (double)((double (*)())FUN_000d13a4)(puVar17,uVar34,puVar13,puVar33,puVar35,param_6,param_7,
                                        local_dc,dVar41);
          local_60 = auStack_1bc;
          dVar41 = (double)((double (*)())FUN_000d1624)(local_60,uVar34,puVar13,puVar33,puVar35,param_6,param_7,
                                        local_d8,dVar41);
          local_64 = auStack_1dc;
          dVar41 = (double)((double (*)())FUN_000d1624)(local_64,uVar34,puVar13,puVar33,puVar35,param_6,param_7,
                                        local_d4,dVar41);
          local_68 = auStack_1fc;
          uVar21 = local_d0;
          ((double (*)())FUN_000d1624)(local_68,uVar34,puVar13,puVar33,puVar35,param_6,param_7,local_d0,dVar41);
          bVar3 = *(byte *)((int)puVar40 + 0x31);
          if (bVar3 < 0xd) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",puVar19,param_4,puVar35,param_6,param_7,uVar21);
              puVar17 = puVar35;
              break;
            case 2:
              puVar13 = local_60;
              puVar17 = (uint *)param_4;
              param_6 = local_64;
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",puVar19,local_60,param_4,local_64,param_7,uVar21);
              param_4 = (char *)puVar13;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",puVar19,param_4,puVar35,param_6,param_7,uVar21);
              puVar17 = puVar35;
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",puVar19,param_4,puVar35,param_6,param_7,uVar21);
              puVar17 = puVar35;
              break;
            case 6:
              goto switchD_000d2d30_caseD_6;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",puVar19,puVar33,puVar35,param_6,param_7,uVar21);
              param_4 = (char *)puVar33;
              puVar17 = puVar35;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",puVar13,puVar33,puVar35,param_6,param_7,uVar21);
              puVar19 = puVar13;
              param_4 = (char *)puVar33;
              puVar17 = puVar35;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",puVar19,param_4,puVar35,param_6,param_7,uVar21);
              puVar17 = puVar35;
              break;
            case 0xc:
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",puVar19,param_4,puVar35,param_6,param_7,uVar21);
              puVar17 = puVar35;
            }
          }
          else {
switchD_000d2d30_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar13,puVar33,puVar35,param_6,param_7,uVar21);
            puVar19 = puVar13;
            param_4 = (char *)puVar33;
            puVar17 = puVar35;
          }
          bVar3 = *(byte *)((int)puVar40 + 0x32);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4",puVar19,param_4,puVar17,param_6,param_7,uVar21);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8",puVar19,param_4,puVar17,param_6,param_7,uVar21);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???",puVar19,param_4,puVar17,param_6,param_7,uVar21);
          }
          if (((*(unsigned char *)((unsigned char *)&(local_2b4) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&(local_28c) + 0)) != '\0')) {
            puVar19 = &local_2b4;
            param_4 = (char *)&local_28c;
            ((int (*)())FUN_000d03b4)(0,"%s%s",puVar19,param_4,puVar17,param_6,param_7,uVar21);
          }
          param_8 = (byte *)((int)puVar40 + 5);
          if (*(char *)((int)puVar40 + 5) != '\0') {
            if (*(char *)((int)puVar40 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(local_2b8) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *param_8;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 1:
                puVar19 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.rgb",puVar19,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 2:
                puVar19 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.rrr",puVar19,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 3:
                puVar19 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.ggg",puVar19,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 4:
                puVar19 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.bbb",puVar19,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 5:
                puVar19 = &local_2b8;
                ((int (*)())FUN_000d03b4)(0," %s.aaa",puVar19,param_4,puVar17,param_6,param_7,param_8);
              }
            }
          }
          ((int (*)())FUN_000d03b4)(0,"\n",puVar19,param_4,puVar17,param_6,param_7,param_8);
          puVar13 = local_f0;
          ((int (*)())FUN_000d03b4)(0,"         alpha:  ",local_f0,param_4,puVar17,param_6,param_7,param_8);
          cVar9 = *(char *)(puVar40 + 8);
          bVar26 = *(char *)((int)puVar40 + 0x21) != '\0';
          cVar5 = *(char *)((int)puVar40 + 0x23);
          if (bVar26) {
            if (*puVar40 == 3) {
              puVar13 = (uint *)(uint)*(byte *)((int)puVar40 + 0x22);
              ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
            }
            else if (*puVar40 == 4) {
              ((int (*)())FUN_000d03b4)(0,"pred.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              cVar6 = *(char *)((int)puVar40 + 0x22);
              if (cVar6 == '\x01') {
                ((int (*)())FUN_000d03b4)(0,"(<) ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              }
              else if (cVar6 == '\0') {
                ((int (*)())FUN_000d03b4)(0,"(==) ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              }
              else if (cVar6 == '\x02') {
                ((int (*)())FUN_000d03b4)(0,"(>=) ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              }
              else if (cVar6 == '\x03') {
                ((int (*)())FUN_000d03b4)(0,"(!=) ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              }
            }
          }
          bVar2 = cVar5 != '\0';
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if ((!bVar26) && (!bVar2)) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (cVar9 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          else {
            puVar13 = (uint *)(uint)*(ushort *)(puVar40 + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)((int)puVar40 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)(puVar40 + 0x10);
          if (bVar3 < 0x10) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              puVar17 = local_68;
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_60,local_64,local_68,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 2:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_60,local_64,puVar17,param_6,param_7,param_8);
              break;
            case 3:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_60,local_64,puVar17,param_6,param_7,param_8);
              break;
            case 4:
              goto switchD_000d324c_caseD_4;
            case 5:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              puVar17 = local_68;
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_60,local_64,local_68,param_6,param_7,param_8);
              break;
            case 6:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              puVar17 = local_68;
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_60,local_64,local_68,param_6,param_7,param_8);
              break;
            case 7:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 8:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 9:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 10:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xb:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xc:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"sin(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xd:
              puVar13 = local_60;
              ((int (*)())FUN_000d03b4)(0,"cos(%s)",local_60,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xe:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",local_60,local_64,puVar17,param_6,param_7,param_8);
              break;
            case 0xf:
              puVar13 = local_60;
              param_4 = (char *)local_64;
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",local_60,local_64,puVar17,param_6,param_7,param_8);
            }
          }
          else {
switchD_000d324c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)((int)puVar40 + 0x41);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0," ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8",puVar13,param_4,puVar17,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)((int)puVar40 + 10) == '\0') {
            param_8 = (byte *)((int)puVar40 + 7);
            if (*(char *)((int)puVar40 + 7) != '\0') {
              if (*(char *)(puVar40 + 2) == '\0') {
                (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(local_2b8) + 2)));
              }
              else {
                param_7 = "!p";
                (*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
              }
              bVar3 = *param_8;
              if (bVar3 < 6) {
                param_7 = (char *)(0);
                switch(bVar3) {
                case 0:
                  break;
                default:
                  puVar13 = &local_2b8;
                  ((int (*)())FUN_000d03b4)(0," %s.a",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 2:
                  puVar13 = &local_2b8;
                  ((int (*)())FUN_000d03b4)(0," %s.r",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 3:
                  puVar13 = &local_2b8;
                  ((int (*)())FUN_000d03b4)(0," %s.g",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 4:
                  puVar13 = &local_2b8;
                  ((int (*)())FUN_000d03b4)(0," %s.b",puVar13,param_4,puVar17,param_6,param_7,param_8);
                }
              }
            }
            if (*(char *)((int)puVar40 + 9) != '\0') {
              ((int (*)())FUN_000d03b4)(0," write_inactive",puVar13,param_4,puVar17,param_6,param_7,param_8);
            }
            ((int (*)())FUN_000d03b4)(0," \n",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          else {
            ((int (*)())FUN_000d03b4)(0," last\n",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)(puVar40 + 0xd) != '\0') {
            puVar13 = local_f0;
            ((int (*)())FUN_000d03b4)(0,"   alu %02d post-NOP\n",local_f0,param_4,puVar17,param_6,param_7,param_8
                        );
          }
          uVar37 = *puVar40;
          local_f0 = (uint *)((int)local_f0 + 1);
        }
        if (uVar37 == 5) {
          if (local_ec == 1) {
            param_7 = "lt";
            local_2a0 = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if (local_ec == 0) {
            param_7 = "eq";
            local_2a0 = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if (local_ec == 2) {
            param_7 = "ge";
            local_2a0 = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if (local_ec == 3) {
            param_7 = "ne";
            local_2a0 = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            local_2a0 = CONCAT21(0x2000,uStack_29e);
          }
          if (local_74 == 0) {
            local_2aa = 0x72656400;
          }
          else if (local_74 == 1) {
            param_7 = "alpha";
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 3)) = s_alpha_001a77e8[3];
            local_2a6[0] = s_alpha_001a77e8[4];
            local_2a6[1] = s_alpha_001a77e8[5];
          }
          else {
            local_2aa = CONCAT22(0x2000,(*(unsigned short *)((unsigned char *)&(local_2aa) + 2)));
          }
          param_4 = (char *)auStack_15c;
          ((int (*)())FUN_000d03b4)(0,"  %d cf  %02d    :  ",local_70,local_f8,local_ec,param_6,param_7,param_8);
          param_8 = (byte *)((uint)*(byte *)((int)puVar40 + 0x15) * 10 + 0x1dc1bc);
          param_7 = (char *)((uint)*(byte *)(puVar40 + 5) * 10 + 0x1dc1bc);
          FUN_001a32d0(param_4,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       (uint)*(byte *)((int)puVar40 + 0x12),(uint)*(byte *)(puVar40 + 4),
                       (uint)*(byte *)((int)puVar40 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)puVar40 + 0x11) * 5 + 0x1dc1da,param_7,param_8);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            iVar10 = 0;
          }
          else {
            ppuVar38 = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            iVar10 = 0;
            pcVar14 = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              sVar11 = _strlen(pcVar14);
              iVar12 = _strncmp(pcVar14,param_4,sVar11);
              if (iVar12 == 0) break;
              pcVar14 = *ppuVar38;
              iVar10 = iVar10 + 2;
              ppuVar38 = ppuVar38 + 2;
            } while (pcVar14 != (char *)0x0);
          }
          puVar13 = (uint *)(PTR_s_IF_b_001dc2cc)[iVar10];
          puVar33 = &local_2b4;
          param_6 = &local_28c;
          ((int (*)())FUN_000d03b4)(0,"%s(%s)%s%s",puVar13,param_4,puVar33,param_6,param_7,param_8);
          cVar9 = *(char *)((int)puVar40 + 0x12);
          if ((cVar9 == -0x10) || (cVar9 == '\x0f')) {
            puVar13 = &local_2aa;
            param_4 = (char *)&local_2a0;
            ((int (*)())FUN_000d03b4)(0,"( prev_alu: %s %s )\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          else if ((cVar9 == -0x56) || (cVar9 == 'U')) {
            puVar13 = (uint *)(uint)*(byte *)((int)puVar40 + 0x17);
            ((int (*)())FUN_000d03b4)(0,"( bool_addr: %d )\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          local_f8 = local_f8 + 1;
        }
        iVar32 = iVar32 + 1;
        puVar40 = puVar40 + 0x12;
        local_70 = local_70 + 1;
        uVar21 = local_7c;
      } while (iVar32 <= (int)local_7c);
    }
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00,puVar13,param_4,uVar21,param_6,param_7,param_8);
    ((int (*)())FUN_000d03b4)(0,"======== End r520 neutral format pixel shader =============\n",puVar13,param_4,
                 uVar21,param_6,param_7,param_8);
  }
  return;
}

/* FUN_000d4de8 @ 0xd4de8 (16 bytes) */
int FUN_000d4de8(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* FUN_000d4df8 @ 0xd4df8 (16 bytes) */
int FUN_000d4df8(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

