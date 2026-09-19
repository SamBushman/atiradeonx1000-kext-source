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
      param_1 = iVar3 * 4 + param_1;
      *(uint *)(param_1 + 0xc) = uVar5 & *(uint *)(param_1 + 0xc);
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
int FUN_000c7650(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  uint *param_4;
  uint param_5;
  int param_6;
  uint *param_7;
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
int FUN_000c7930(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint in_r9;
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
        in_r9 = *(uint *)(iVar2 + 0x21e0) & 0xffff | 0x40000;
        param_1[3] = in_r9;
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
      param_1[3] = uVar1 & 0xffff | in_r9 & 0xffc00000 | 0x10000 | 0x400000;
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
      param_1[3] = uVar1 & 0xffff | in_r9 & 0xffc00000 | 0x10000 | 0x400000;
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
int FUN_000c8110(param_1, param_2)
  uint *param_1;
  int param_2;
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
  uVar3 = FUN_000c73a0(param_2);
  *(undefined4 *)(param_2 + 0x2208) = uVar3;
  if (*(int *)(param_2 + 100) != 0) {
    uVar3 = FUN_000c7350(param_2);
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
    uVar3 = ((int (*)())FUN_000c73c0)(param_2);
    *(undefined4 *)(param_2 + 0x5c) = uVar3;
    uVar3 = FUN_000c7350(param_2);
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
  if ((uVar1 & 0x3f0000) == 0x160000) {
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
void FUN_000c8e30(double param_1,double param_2,double param_3,double param_4,int param_5,
                 int param_6)

{
  param_5 = param_6 * 0x10 + param_5;
  *(float *)(param_5 + 0x98) = (float)param_4;
  *(float *)(param_5 + 0x8c) = (float)param_1;
  *(float *)(param_5 + 0x90) = (float)param_2;
  *(float *)(param_5 + 0x94) = (float)param_3;
  return;
}

/* FUN_000c8e50 @ 0xc8e50 (7396 bytes) */
int FUN_000c8e50(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  byte *pbVar5;
  uint uVar6;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  void *pvVar14;
  uint *puVar15;
  void *pvVar16;
  undefined4 *puVar17;
  uint uVar18;
  uint *puVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  undefined4 *puVar23;
  char cVar25;
  undefined4 uVar24;
  undefined4 *puVar26;
  undefined4 *puVar27;
  undefined4 uVar28;
  uint unaff_r14;
  uint unaff_r15;
  uint *puVar29;
  uint unaff_r20;
  uint unaff_r21;
  uint uVar30;
  uint *puVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  undefined1 *puVar38;
  int iVar39;
  uint *local_2bb8;
  uint *local_2bb4;
  uint local_2bb0;
  uint local_2bac [2];
  uint local_2ba4;
  uint local_2ba0 [2];
  uint local_2b98;
  uint local_2b94;
  uint local_2b8c [3];
  undefined1 auStack_2b80 [12];
  uint local_2b74;
  uint local_2b70;
  uint local_2b68;
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
  undefined4 local_2958;
  undefined1 uStack_2954;
  char local_2953 [3];
  byte abStack_2950 [764];
  int local_2654;
  char local_2650 [576];
  undefined4 local_2410;
  undefined4 *local_240c;
  int *local_2408;
  int local_2400;
  undefined4 local_23fc;
  uint local_23ec;
  undefined4 local_23e8;
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
  undefined4 local_2398;
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
  int local_220;
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
  int local_1b4;
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
  uint *local_70;
  uint *local_6c;
  uint *local_60;
  
  iVar39 = 8;
  iVar9 = 0;
  do {
    *(undefined4 *)((int)local_2b38 + iVar9) = 0xffffffff;
    *(undefined4 *)((int)local_2b58 + iVar9) = 0xffffffff;
    iVar9 = iVar9 + 4;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  pvVar14 = _malloc(0x400);
  uVar21 = *(uint *)(param_1 + 0x44);
  local_218 = 0;
  if ((uVar21 & 0x2000) == 0) {
    local_1e4 = uVar21 >> 0x18 & 1;
    local_1d8 = 0xffff;
  }
  else {
    local_1e4 = uVar21 >> 0xb & 1;
    if (local_1e4 == 0) {
      local_1d8 = 0xffff;
    }
    else {
      local_1d8 = (uint)(byte)((unsigned char *)0x000011d1)[param_1];
    }
  }
  puVar31 = (uint *)*param_2;
  local_d8 = uVar21 >> 10 & 1;
  iVar39 = 8;
  local_23e4 = 0xffff;
  local_d4 = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
  local_c4 = (uint)(param_2[6] == 0);
  local_23c0 = local_2b1c;
  iVar9 = param_2[1];
  local_23c4 = local_2b20;
  local_23c8 = local_2b24;
  local_1b4 = 0;
  local_ec = 0;
  local_cc = 0;
  local_7c = 0;
  local_23cc = local_2b28;
  local_23dc[3] = local_2b38[3];
  local_23e8 = 0;
  local_239c = 0;
  local_2384 = 0;
  local_23dc[2] = local_2b38[2];
  local_23dc[1] = local_2b38[1];
  local_23dc[0] = local_2b38[0];
  local_23a0 = local_2b3c;
  local_2270 = 0;
  local_1b8 = 0;
  local_23e0 = 0;
  local_220 = 0;
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
  puVar29 = local_2260;
  local_6c = puVar29;
  local_23bc[0] = local_2b58[0];
  do {
    *puVar29 = 0;
    puVar29[0x408] = 0;
    puVar29 = puVar29 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  puVar13 = local_1b0;
  iVar39 = 0x10;
  do {
    *puVar13 = 0;
    puVar13[0x10] = 0;
    puVar13 = puVar13 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  iVar36 = 0;
  iVar39 = 0;
  uVar21 = 0;
  puVar29 = puVar31;
switchD_000c90cc_caseD_15:
  local_2bb4 = puVar29 + 2;
  puVar15 = local_2bb4;
switchD_000c90cc_caseD_18:
  puVar29 = puVar15;
  if (puVar29 < puVar31 + iVar9) goto code_r0x000c90a4;
  if (local_220 != 0) {
    puVar29 = (uint *)0x0;
    uVar18 = 0;
    goto LAB_000ca6bc;
  }
  iVar36 = (iVar36 + iVar9) * 4;
  local_2398 = local_23e8;
  if (local_239c != 0) {
    iVar36 = iVar36 + 0x48;
  }
  uVar18 = iVar36 + iVar39 * 4;
  bVar4 = local_218 != 0;
  if (bVar4) {
    uVar18 = uVar18 + 0x14;
  }
  uVar33 = uVar18;
  if ((local_1f8[0] != 0) && (uVar33 = uVar18 + 0xc, bVar4)) {
    uVar33 = uVar18 + 0x24;
  }
  uVar18 = uVar33;
  if ((local_1f8[1] != 0) && (uVar18 = uVar33 + 0xc, bVar4)) {
    uVar18 = uVar33 + 0x24;
  }
  uVar33 = uVar18;
  if ((local_1f8[2] != 0) && (uVar33 = uVar18 + 0xc, bVar4)) {
    uVar33 = uVar18 + 0x24;
  }
  uVar22 = uVar33;
  if ((local_1f8[3] != 0) && (uVar22 = uVar33 + 0xc, bVar4)) {
    uVar22 = uVar33 + 0x24;
  }
  if (((local_1dc != 0) && (local_1e4 != 0)) && (local_1b4 == 0)) {
    uVar22 = uVar22 + 0x14;
  }
  if (local_ec == 1) {
    uVar22 = uVar22 + 0x24;
  }
  else if (local_ec == 2) {
    uVar22 = uVar22 + 0x30;
  }
  else if (local_ec == 3) {
    uVar22 = uVar22 + 0x40;
  }
  else if (local_ec == 0) goto LAB_000c99d4;
  uVar22 = uVar22 + 8;
  piVar10 = local_1f8;
  iVar39 = 4;
  do {
    if (*piVar10 != 0) {
      uVar22 = uVar22 + 0x2c;
    }
    piVar10 = piVar10 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
LAB_000c99d4:
  if (((local_1d0 != 0) || (local_1c8 != 0)) || (uVar18 = uVar22, local_1b4 == 0)) {
    if ((local_1d4 == 0) && (local_1cc != 0)) {
      uVar22 = uVar22 + 0xc;
    }
    uVar18 = uVar22;
    if ((local_1b4 == 0) && (uVar18 = uVar22 + 0xc, local_d8 != 0)) {
      uVar18 = uVar22 + 0x18;
    }
  }
  bVar4 = true;
  puVar29 = _malloc(uVar18 + 0x10);
  *puVar29 = *puVar31;
  local_2bb4 = puVar31 + 2;
  puVar29[1] = puVar31[1];
  puVar20 = local_2bb4;
  puVar15 = puVar29 + 2;
  goto switchD_000c9ab8_caseD_18;
code_r0x000c90a4:
  uVar18 = *puVar29;
  puVar15 = puVar29;
  switch(uVar18 & 0xffff) {
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
    uVar8 = 1;
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
    uVar8 = 1;
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
    local_2bb4 = puVar29 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar8 = 0;
LAB_000c9340:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar8,2,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    local_2bb4 = puVar29 + 2;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    local_2bb4 = puVar29 + 3;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,3,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    local_2bb4 = puVar29 + *(ushort *)((int)puVar29 + 6) + 2;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    local_2bb4 = puVar29 + 3;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    local_2bb4 = puVar29 + 1;
    uVar33 = puVar29[1];
    uVar18 = uVar33 & 0x3f0000;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,&local_23e8,0,0);
    if (uVar18 == 0x160000) {
      local_239c = 1;
    }
    else if (uVar18 == 0x110000) {
      local_23e0 = 1 << (uVar33 & 0x3f) | local_23e0;
    }
    else if (uVar18 == 0xf0000) {
      uVar21 = uVar21 | 1 << (uVar33 & 0x3f);
    }
    else if (uVar18 == 0x100000) {
      local_2384 = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    uVar22 = uVar18 >> 0x1b & 3;
    uVar33 = uVar18 >> 0x10 & 0xff;
    if ((uVar22 == 2) || ((uVar22 == 0 && (auStack_130[uVar33] == 2)))) {
      local_2270 = 1 << (uVar18 >> 0x10 & 0x3f) | local_2270;
    }
    FUN_000c7270(&local_23e8,uVar33,uVar18 >> 0x18 & 7);
    local_2bb4 = local_2bb4 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    local_2bb4 = puVar29 + 1;
    if ((int)uVar18 < 0) {
      local_2bb4 = puVar29 + 2;
    }
LAB_000c9564:
    local_2bb4 = local_2bb4 + 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    local_2bb4 = puVar29 + 1;
    uVar33 = puVar29[1];
    uVar18 = uVar33 >> 0x10 & 0x3f;
    if (uVar18 == 1) {
      local_2b68 = puVar29[2];
      local_2b64 = puVar29[3];
      local_2b60 = puVar29[4];
      local_2bb4 = puVar29 + 6;
      local_2b5c = puVar29[5];
      FUN_000c7290(&local_23e8,uVar33 & 0xffff,&local_2b68);
      puVar15 = local_2bb4;
    }
    else {
      puVar15 = local_2bb4;
      if (uVar18 == 2) {
        local_2b68 = puVar29[2];
        local_2b64 = puVar29[3];
        local_2b60 = puVar29[4];
        local_2bb4 = puVar29 + 6;
        local_2b5c = puVar29[5];
        FUN_000c72f0(&local_23e8,uVar33 & 0xffff,&local_2b68);
        puVar15 = local_2bb4;
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    iVar36 = iVar36 + 5;
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,2,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    local_2bb4 = puVar29 + 2;
    local_2b8c[0] = puVar29[1];
    ((int (*)())FUN_000c87d0)(local_2b8c,auStack_2b80,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,0,1,&local_23e8);
    local_1bc = 1;
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    uVar8 = 0;
    break;
  case 0x5d:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar18 = puVar29[1];
    uVar33 = *puVar29;
    if ((((uVar33 & 0xc000000) == 0x4000000) ||
        (((uVar33 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar33 = *puVar29;
    }
    if ((int)uVar33 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar33 = *puVar29;
    }
    if ((uVar33 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar18 & 0x400000) != 0) {
      unaff_r21 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    ((int (*)())FUN_000c8600)(uVar18 & 0xffff,uVar18 >> 0x10 & 0x3f,&local_23e8,unaff_r21,uVar18 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2b74 = *local_2bb4;
    puVar29 = local_2bb4 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2bb0 = local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bb4 = puVar29;
    ((int (*)())FUN_000c87d0)(&local_2b74,&local_2bb0,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar18 = puVar29[1];
    uVar33 = *puVar29;
    if ((((uVar33 & 0xc000000) == 0x4000000) ||
        (((uVar33 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar33 = *puVar29;
    }
    if ((int)uVar33 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar33 = *puVar29;
    }
    if ((uVar33 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar18 & 0x400000) != 0) {
      unaff_r20 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    ((int (*)())FUN_000c8600)(uVar18 & 0xffff,uVar18 >> 0x10 & 0x3f,&local_23e8,unaff_r20,uVar18 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2bb0 = *local_2bb4;
    puVar29 = local_2bb4 + 1;
    if ((local_2bb0 & 0x400000) != 0) {
      local_2ba4 = local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bac[0] = *puVar29;
    local_2bb4 = puVar29 + 1;
    if ((local_2bac[0] & 0x400000) != 0) {
      local_2ba0[0] = puVar29[1];
      local_2bb4 = puVar29 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_2bb0,&local_2ba4,&local_23e8);
    ((int (*)())FUN_000c87d0)(local_2bac,local_2ba0,&local_23e8);
    puVar15 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar8,1,&local_23e8);
  puVar15 = local_2bb4;
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  local_2bb8 = puVar15;
  puVar19 = puVar20;
  if (puVar31 + iVar9 <= puVar19) {
    uVar18 = uVar18 >> 2;
    local_23e0 = uVar21 | local_23e0;
LAB_000ca6bc:
    if (local_220 != 0) {
      return local_220;
    }
    param_3[0x1587] = 0;
    iVar9 = 0;
    param_3[0x1589] = 0;
    param_3[0x1502] = 0;
    puVar13 = param_3 + 0x1000;
    puVar38 = auStack_2248;
    puVar17 = param_3 + 0x1004;
    puVar31 = local_6c;
    do {
      puVar26 = puVar17 + 1;
      puVar27 = (undefined4 *)(puVar38 + 8);
      puVar23 = puVar13 + 1;
      iVar39 = 0x20;
      uVar21 = 0;
      do {
        if ((1 << (uVar21 & 0x3f) & *puVar31) == 0) {
          *(undefined1 *)puVar26 = 0;
        }
        else {
          *puVar23 = *puVar27;
          puVar23[1] = puVar27[1];
          puVar23[2] = puVar27[2];
          uVar8 = puVar27[3];
          *(undefined1 *)(puVar23 + 4) = 1;
          puVar23[3] = uVar8;
          if ((uint)param_3[0x1502] < iVar9 + uVar21) {
            param_3[0x1502] = iVar9 + uVar21;
          }
        }
        uVar21 = uVar21 + 1;
        puVar26 = puVar26 + 5;
        puVar27 = puVar27 + 4;
        puVar23 = puVar23 + 5;
        iVar39 = iVar39 + -1;
      } while (iVar39 != 0);
      bVar4 = iVar9 != 0xe0;
      puVar17 = puVar17 + 0xa0;
      puVar38 = puVar38 + 0x200;
      puVar13 = puVar13 + 0xa0;
      puVar31 = puVar31 + 1;
      iVar9 = iVar9 + 0x20;
    } while (bVar4);
    if ((int)param_3[0x1587] < (int)param_3[0x1502]) {
      param_3[0x1587] = param_3[0x1502];
    }
    _memset(auStack_2b18,0,0xbc);
    _memset(auStack_2a5c,0,0x674);
    pvVar16 = (void *)(**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x1870));
    local_2ac8 = uVar18 << 2;
    puVar17 = local_23dc;
    puVar13 = local_2ac0;
    iVar9 = 8;
    local_2a60 = pvVar16;
    do {
      uVar8 = *puVar17;
      uVar11 = puVar17[8];
      puVar17 = puVar17 + 1;
      *puVar13 = uVar8;
      puVar13[8] = uVar11;
      puVar13 = puVar13 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    local_2410 = 0x400;
    local_2acc = puVar29;
    local_240c = _malloc(0x40000);
    local_2408 = _malloc(0x40000);
    local_2a10 = 0x40;
    local_29f8 = _malloc(0x900);
    local_2a14 = 0x40;
    local_29fc = _malloc(0x900);
    cVar25 = '\0';
    pcVar12 = local_2953;
    iVar9 = 0x40;
    do {
      *pcVar12 = cVar25;
      pcVar12 = pcVar12 + 0xc;
      cVar25 = cVar25 + '\x01';
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar9 = *(int *)(param_1 + 0x186c);
    if (iVar9 == 0) {
      FUN_000c6ff0(param_1,1);
      iVar9 = *(int *)(param_1 + 0x186c);
    }
    iVar9 = ((int (*)())FUN_000cd1b0)(iVar9,auStack_2b18,auStack_2a5c);
    if (iVar9 != 0) {
      return 2;
    }
    param_3[0x1000] = local_2400;
    if (local_2400 != 0) {
      puVar13 = local_240c;
      puVar17 = param_3;
      if (local_2400 == 0) {
        local_2400 = 1;
      }
      do {
        uVar8 = *puVar13;
        uVar11 = puVar13[1];
        uVar24 = puVar13[2];
        uVar28 = puVar13[3];
        puVar13 = puVar13 + 4;
        *puVar17 = uVar8;
        puVar17[1] = uVar11;
        puVar17[2] = uVar24;
        puVar17[3] = uVar28;
        puVar17 = puVar17 + 4;
        local_2400 = local_2400 + -1;
      } while (local_2400 != 0);
    }
    uVar21 = param_3[0x1502];
    if (uVar21 < local_23ec) {
      param_3[0x1502] = local_23ec;
      param_3[0x1501] = local_23ec + 1;
      uVar21 = local_23ec;
    }
    else {
      param_3[0x1501] = uVar21 + 1;
    }
    if (0xff < uVar21) {
      param_3[0x1502] = 0xff;
    }
    if (0x100 < (uint)param_3[0x1501]) {
      param_3[0x1501] = 0x100;
    }
    if (local_2a04 == 0) goto LAB_000caa4c;
    uVar18 = 0;
    iVar9 = 0;
    uVar21 = local_2a04;
    do {
      iVar39 = iVar9 + (int)local_29f8;
      if (*(int *)(iVar39 + 8) == 0x16) {
        uVar33 = *(uint *)(iVar39 + 0x10);
        iVar35 = *(int *)(iVar9 + (int)local_29f8);
        iVar36 = ((int)uVar33 >> 5) + (uint)((int)uVar33 < 0 && (uVar33 & 0x1f) != 0);
        if ((1 << (uVar33 + iVar36 * -0x20 & 0x3f) & local_2260[iVar36]) == 0) goto LAB_000caa2c;
        iVar36 = FUN_000c7240(*(undefined4 *)(iVar39 + 4));
        iVar39 = FUN_000c7240(*(undefined4 *)(iVar39 + 0xc));
        local_78 = (longlong)(int)local_2240[uVar33 * 4 + iVar39];
        aiStack_1220[iVar35 * 4 + iVar36] = (int)local_2240[uVar33 * 4 + iVar39];
      }
      else if (*(int *)(iVar39 + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())FUN_000c8de0)(param_3 + 0x1589,iVar39);
        uVar21 = local_2a04;
      }
      uVar18 = uVar18 + 1;
      iVar9 = iVar9 + 0x24;
      if (uVar21 <= uVar18) {
LAB_000caa4c:
        if (local_2a08 != 0) {
          uVar18 = 0;
          iVar9 = 0;
          uVar21 = local_2a08;
          do {
            pvVar7 = local_29fc;
            if (*(int *)((int)local_29fc + iVar9 + 8) == 1) {
              uVar33 = *(uint *)(iVar9 + (int)local_29fc);
              iVar39 = FUN_000c7240(*(undefined4 *)((int)local_29fc + iVar9 + 4));
              uVar8 = *(undefined4 *)((int)pvVar7 + iVar9 + 0x14);
              *(undefined1 *)(param_3 + (int)(((unsigned char *)0x00001005) + uVar33 * 5)) = 1;
              param_3[(int)(((unsigned char *)0x00001001) + uVar33 * 5 + iVar39)] = uVar8;
              uVar21 = local_2a08;
              if ((uint)param_3[0x1502] < uVar33) {
                param_3[0x1502] = uVar33;
              }
            }
            uVar18 = uVar18 + 1;
            iVar9 = iVar9 + 0x24;
          } while (uVar18 < uVar21);
        }
        uVar21 = 0;
        *(undefined1 *)(param_3 + 0x1507) = 0;
        param_3[0x1506] = 0;
        param_3[0x151d] = 0;
        param_3[0x151e] = 0;
        param_3[0x1503] = local_2958;
        param_3[0x1504] = local_2654;
        param_3[0x1505] = local_23fc;
        param_3[0x1588] = 0;
        if (local_2654 == 0) {
          uVar21 = param_3[0x151d];
        }
        else {
          pcVar12 = local_2650;
          if (local_2654 == 0) {
            local_2654 = 1;
          }
          do {
            cVar25 = *pcVar12;
            if (cVar25 == '\x01') {
              uVar21 = uVar21 | 0x10000;
              param_3[0x151d] = uVar21;
            }
            else if (cVar25 == '\0') {
              uVar21 = uVar21 | 1;
              *(undefined1 *)(param_3 + 0x1507) = 1;
              param_3[0x151d] = uVar21;
            }
            else if (cVar25 == '\x02') {
              cVar25 = pcVar12[1];
              if (cVar25 == '\x01') {
                uVar21 = uVar21 | 4;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\0') {
                uVar21 = uVar21 | 2;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\x02') {
                uVar21 = uVar21 | 8;
                param_3[0x151d] = uVar21;
              }
              else if (cVar25 == '\x03') {
                uVar21 = uVar21 | 0x10;
                param_3[0x151d] = uVar21;
              }
            }
            else if (cVar25 == '\x05') {
              param_3[0x151e] = 4 << ((uint)(byte)pcVar12[1] * 3 & 0x3f) | param_3[0x151e];
              param_3[0x1588] = 4 << ((uint)(byte)pcVar12[1] * 3 & 0x3f) | param_3[0x1588];
            }
            pcVar12 = pcVar12 + 0xc;
            local_2654 = local_2654 + -1;
          } while (local_2654 != 0);
        }
        if ((uVar21 & 0x18) != 0) {
          param_3[0x151d] = uVar21 | 0x1c;
        }
        puVar13 = param_3 + 0x1571;
        iVar9 = 0x16;
        do {
          *puVar13 = 0x16;
          puVar13 = puVar13 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        uVar21 = param_3[0x1503];
        if (uVar21 != 0) {
          puVar38 = &uStack_2954;
          uVar18 = uVar21;
          if (uVar21 == 0) {
            uVar18 = 1;
          }
          do {
            pbVar2 = puVar38 + 1;
            pbVar5 = puVar38 + (int)(abStack_2950 + -(int)&uStack_2954);
            puVar38 = puVar38 + 0xc;
            param_3[(int)(((unsigned char *)0x00001571) + *pbVar2)] = (uint)*pbVar5;
            uVar18 = uVar18 - 1;
          } while (uVar18 != 0);
        }
        if (uVar21 < 2) {
          if (uVar21 == 0) {
            param_3[0x1571] = 0;
            param_3[0x1572] = 1;
          }
          else if (param_3[0x1571] == 0) {
            param_3[0x1572] = 1;
          }
          else {
            param_3[0x1572] = 0;
          }
        }
        iVar9 = *local_2408;
        param_3[0x1520] = 0;
        param_3[0x151f] = (uint)(iVar9 != 0);
        if (((iVar9 != 0) != 0) && (iVar9 = *local_2408, 0 < iVar9)) {
          puVar13 = param_3 + 0x1531;
          uVar21 = 0;
          do {
            puVar13[0x20] = 0;
            *puVar13 = 0;
            puVar13[0x10] = 0;
            if (local_2408[uVar21 * 7 + 3] == 0x3e) {
              param_3[0x1520] = 2 << ((uVar21 & 0x1f) << 1) | param_3[0x1520];
              *(char *)((int)param_3 + uVar21 * 4 + 0x5547) =
                   (char)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4 + 1];
              *(char *)((int)param_3 + uVar21 * 4 + 0x5546) =
                   (char)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4 + 2];
              *(short *)((int)param_3 + uVar21 * 4 + 0x54c6) = (short)local_2408[uVar21 * 7 + 5];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001531) + uVar21)) =
                   (short)aiStack_1220[local_2408[uVar21 * 7 + 4] * 4];
              *(short *)((int)param_3 + uVar21 * 4 + 0x5506) = (short)local_2408[uVar21 * 7 + 7];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001541) + uVar21)) =
                   (short)local_2408[uVar21 * 7 + 5] + 1;
              param_3[(int)(((unsigned char *)0x00001561) + local_2408[uVar21 * 7 + 4])] = uVar21;
            }
            uVar21 = uVar21 + 1;
            puVar13 = puVar13 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
        if (local_240c != (undefined4 *)0x0) {
          _free(local_240c);
        }
        if (pvVar14 != (void *)0x0) {
          _free(pvVar14);
        }
        if (local_2408 != (int *)0x0) {
          _free(local_2408);
        }
        if (puVar29 != (uint *)0x0) {
          _free(puVar29);
        }
        if (pvVar16 != (void *)0x0) {
          _free(pvVar16);
        }
        if (local_29f8 != (void *)0x0) {
          _free(local_29f8);
        }
        if (local_29fc != (void *)0x0) {
          _free(local_29fc);
        }
        return 0;
      }
    } while( true );
  }
  uVar33 = *puVar19;
  puVar20 = puVar19;
  puVar15 = local_2bb8;
  switch(uVar33 & 0xffff) {
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
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,1,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
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
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,2,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,0,2,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_2bb8 = uVar33;
    local_2bb4 = puVar19 + 2;
    local_2bb8[1] = puVar19[1];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_2bb8 = uVar33;
    local_2bb8[1] = puVar19[1];
    local_2bb4 = puVar19 + 3;
    local_2bb8[2] = puVar19[2];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 3;
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
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
    }
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,3,&local_23e8);
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    local_2bb4 = puVar19 + 2;
    *local_2bb8 = uVar33;
    local_2bb8[1] = puVar19[1];
    puVar15 = local_2bb8 + 2;
    for (uVar33 = (uint)*(ushort *)((int)puVar19 + 6); puVar20 = local_2bb4, uVar33 != 0;
        uVar33 = uVar33 - 1) {
      uVar22 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
      *puVar15 = uVar22;
      puVar15 = puVar15 + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    local_2bb4 = puVar19 + 1;
    if ((uVar33 & 0x18000000) == 0) {
      uVar22 = *(uint *)((int)auStack_130 + (uVar33 >> 0xe & 0x3fc));
      if (uVar22 != 2) {
        uVar22 = 1;
      }
      uVar33 = (uVar22 & 3) << 0x1b | uVar33 & 0xe7ffffff;
    }
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar15 = local_2bb8 + 1;
    if ((int)uVar33 < 0) {
      uVar33 = *local_2bb4;
      local_2bb4 = puVar19 + 2;
      local_2bb8[1] = uVar33;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    uVar33 = *local_2bb4;
    local_2bb4 = local_2bb4 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    if ((puVar19[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_2bb8[1] = puVar19[1];
      local_2bb8[2] = puVar19[2];
      local_2bb8[3] = puVar19[3];
      local_2bb8[4] = puVar19[4];
      local_2bb4 = puVar19 + 6;
      local_2bb8[5] = puVar19[5];
      puVar20 = local_2bb4;
      puVar15 = local_2bb8 + 6;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    local_2bb4 = puVar19 + 1;
    puVar15 = (uint *)((int (*)())FUN_000c7930)(local_2bb8,&local_23e8);
    *puVar15 = uVar33;
    puVar20 = local_2bb4;
    puVar15 = puVar15 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    *local_2bb8 = uVar33;
    local_2bb4 = puVar19 + 2;
    local_2b8c[0] = puVar19[1];
    local_2bb8 = local_2bb8 + 1;
    ((int (*)())FUN_000c8760)(local_2b8c,auStack_2b80,&local_23e8);
    *local_2bb8 = local_2b8c[0];
    puVar20 = local_2bb4;
    puVar15 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x37:
  case 0x3e:
    uVar8 = 0;
    break;
  case 0x3b:
    uVar8 = 1;
    break;
  case 0x5d:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
      puVar19 = local_2bb4;
    }
    uVar32 = *puVar19;
    puVar15 = puVar19 + 1;
    uVar33 = uVar32 >> 0x10;
    uVar22 = uVar33 & 0xff;
    bVar3 = (uVar32 & 0x80000000) != 0;
    if (bVar3) {
      puVar15 = puVar19 + 2;
      uVar30 = puVar19[1];
    }
    else {
      uVar30 = 0;
    }
    bVar1 = (uVar32 >> 0x1e & 1) != 0;
    if (bVar1) {
      uVar37 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar37 = 0;
    }
    local_2ba4 = *puVar15;
    puVar20 = puVar15 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      puVar20 = puVar15 + 2;
      unaff_r15 = puVar15[1];
    }
    local_2b74 = *puVar20;
    local_2bb4 = puVar20 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2b98 = puVar20[1];
      local_2bb4 = puVar20 + 2;
    }
    uVar6 = uVar32 & 0xc000000;
    if (uVar6 == 0x4000000) {
LAB_000ca0e4:
      if (local_2378 << (uVar33 & 0x3f) == 0) {
        local_70 = &local_2b74;
        uVar8 = 0;
        uVar34 = 1 << (uVar33 & 0x3f);
        puVar15 = &local_2b98;
      }
      else {
        local_60 = &local_2b98;
        local_70 = &local_2b74;
        local_2bb8 = (uint *)((int (*)())FUN_000c7460)(&local_23e8,local_70,local_60,uVar22,local_2bb8);
        puVar15 = local_60;
        if ((local_2ba4 & 0x400000) == 0) {
          uVar8 = 0;
          uVar34 = 1 << (uVar33 & 0x3f);
        }
        else {
          local_2ba4 = local_2ba4 & 0xffbfffff;
          uVar8 = 1;
          uVar34 = 1 << (uVar33 & 0x3f);
          local_2bb0 = unaff_r15;
        }
      }
    }
    else if (uVar6 == 0x8000000) {
      uVar34 = 1 << (uVar33 & 0x3f);
      if ((uVar34 & local_2374) != 0) goto LAB_000ca0e4;
      local_70 = &local_2b74;
      uVar8 = 0;
      puVar15 = &local_2b98;
    }
    else {
      uVar8 = 0;
      uVar34 = 1 << (uVar33 & 0x3f);
      local_70 = &local_2b74;
      puVar15 = &local_2b98;
    }
    ((int (*)())FUN_000c8760)(local_70,puVar15,&local_23e8);
    *local_2bb8 = uVar32;
    puVar15 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = uVar30;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (bVar1) {
      *local_2bb8 = uVar37;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = local_2ba4;
    puVar15 = local_2bb8 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r15;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b74;
    puVar15 = local_2bb8 + 1;
    if ((local_2b74 & 0x400000) != 0) {
      local_2bb8[1] = local_2b98;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (((uVar6 == 0x4000000) || ((uVar6 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (local_2378 << (uVar33 & 0x3f) != 0)) {
      local_2bb8 = (uint *)((int (*)())FUN_000c7650)(&local_23e8,local_70,&local_2ba4,&local_2bb0,uVar22,uVar8,
                                        local_2bb8);
    }
    uVar34 = uVar34 & local_2378;
    uVar33 = unaff_r15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *)((int (*)())FUN_000c8110)(local_2bb8,&local_23e8);
      puVar19 = local_2bb4;
    }
    uVar32 = *puVar19;
    puVar15 = puVar19 + 1;
    uVar33 = uVar32 >> 0x10;
    uVar22 = uVar33 & 0xff;
    bVar3 = (uVar32 & 0x80000000) != 0;
    if (bVar3) {
      puVar15 = puVar19 + 2;
      uVar30 = puVar19[1];
    }
    else {
      uVar30 = 0;
    }
    bVar1 = (uVar32 & 0x40000000) != 0;
    if (bVar1) {
      uVar37 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar37 = 0;
    }
    local_2ba4 = *puVar15;
    puVar20 = puVar15 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      puVar20 = puVar15 + 2;
      unaff_r14 = puVar15[1];
    }
    local_2b98 = *puVar20;
    puVar15 = puVar20 + 1;
    if ((local_2b98 & 0x400000) != 0) {
      local_2b74 = puVar20[1];
      puVar15 = puVar20 + 2;
    }
    local_2b94 = *puVar15;
    local_2bb4 = puVar15 + 1;
    if ((local_2b94 & 0x400000) != 0) {
      local_2b70 = puVar15[1];
      local_2bb4 = puVar15 + 2;
    }
    uVar6 = uVar32 & 0xc000000;
    if (uVar6 == 0x4000000) {
LAB_000ca3b8:
      if ((local_2378 << (uVar33 & 0x3f) == 0) ||
         (local_2bb8 = (uint *)((int (*)())FUN_000c7460)(&local_23e8,&local_2b98,&local_2b74,uVar22,local_2bb8),
         (local_2ba4 & 0x400000) == 0)) {
LAB_000ca3ec:
        uVar8 = 0;
        uVar34 = 1 << (uVar33 & 0x3f);
      }
      else {
        local_2ba4 = local_2ba4 & 0xffbfffff;
        uVar8 = 1;
        uVar34 = 1 << (uVar33 & 0x3f);
        local_2bb0 = unaff_r14;
      }
    }
    else {
      if (uVar6 != 0x8000000) goto LAB_000ca3ec;
      uVar8 = 0;
      uVar34 = 1 << (uVar33 & 0x3f);
      if ((uVar34 & local_2374) != 0) goto LAB_000ca3b8;
    }
    *local_2bb8 = uVar32;
    puVar15 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = uVar30;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (bVar1) {
      *local_2bb8 = uVar37;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = local_2ba4;
    puVar15 = local_2bb8 + 1;
    if ((local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r14;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b98;
    puVar15 = local_2bb8 + 1;
    if ((local_2b98 & 0x400000) != 0) {
      local_2bb8[1] = local_2b74;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    *local_2bb8 = local_2b94;
    puVar15 = local_2bb8 + 1;
    if ((local_2b94 & 0x400000) != 0) {
      local_2bb8[1] = local_2b70;
      puVar15 = local_2bb8 + 2;
    }
    local_2bb8 = puVar15;
    if (((uVar6 == 0x4000000) || ((uVar6 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (local_2378 << (uVar33 & 0x3f) != 0)) {
      local_2bb8 = (uint *)((int (*)())FUN_000c7650)(&local_23e8,&local_2b98,&local_2ba4,&local_2bb0,uVar22,uVar8
                                        ,local_2bb8);
    }
    uVar34 = uVar34 & local_2378;
    uVar33 = unaff_r14;
joined_r0x000ca538:
    puVar20 = local_2bb4;
    puVar15 = local_2bb8;
    if (uVar34 != 0) {
      *local_2bb8 = 0x47;
      uVar32 = local_2ba4;
      if ((local_2ba4 & 0x400000) == 0) {
        uVar32 = local_2ba4 | 0x400000;
        uVar33 = 0x55;
      }
      if (aiStack_22f0[uVar22] == 0x1906) {
        if ((uVar33 & 3) == 1) {
          uVar33 = uVar33 & 0xfffffffc | 2;
        }
        if ((uVar33 & 0xc) == 4) {
          uVar33 = uVar33 & 0xfffffff3 | 8;
        }
        if ((uVar33 & 0x30) == 0x10) {
          uVar33 = uVar33 & 0xffffffcf | 0x20;
        }
      }
      else if ((aiStack_22f0[uVar22] == 0x1909) && ((uVar33 & 0xc0) == 0x40)) {
        uVar33 = uVar33 & 0xffffff3f | 0xc0;
      }
      local_2bb8[1] = uVar32;
      local_2bb8[2] = uVar33;
      local_2bb8[3] = uVar32 & 0x3fffff;
      puVar15 = local_2bb8 + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,uVar8,1,&local_23e8);
  puVar20 = local_2bb4;
  puVar15 = local_2bb8;
  goto switchD_000c9ab8_caseD_18;
switchD_000c90cc_caseD_0:
                    
  _exit(0);
}

/* FUN_000cae90 @ 0xcae90 (7760 bytes) */
int FUN_000cae90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int *param_3;
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
  uint uVar8;
  float fVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  void *pvVar14;
  uint *puVar15;
  void *pvVar16;
  uint uVar17;
  uint *puVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  byte *pbVar22;
  int iVar23;
  uint uVar24;
  int *piVar25;
  undefined4 uVar26;
  int iVar27;
  char *pcVar28;
  int *piVar29;
  undefined4 uVar30;
  uint unaff_r14;
  uint unaff_r15;
  uint *puVar31;
  uint unaff_r19;
  undefined1 *puVar32;
  uint unaff_r20;
  uint uVar33;
  undefined1 *puVar34;
  uint uVar35;
  uint *puVar36;
  uint uVar37;
  float *pfVar38;
  uint uVar39;
  int iVar40;
  undefined4 *puVar41;
  int iVar42;
  uint *local_c1f8;
  uint *local_c1f4;
  uint local_c1f0;
  uint local_c1ec [2];
  uint local_c1e4;
  uint local_c1e0 [2];
  uint local_c1d8;
  uint local_c1d4;
  uint local_c1cc;
  uint local_c1c8;
  uint local_c1c0 [3];
  undefined1 auStack_c1b4 [12];
  uint local_c1a8;
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
  undefined4 local_c08c;
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
  undefined4 local_c03c;
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
  int local_9eb8;
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
  int local_9e58;
  int local_9e54 [16];
  int local_9e14 [16];
  uint local_9dd4 [17];
  int local_9d90;
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
  undefined4 *local_88;
  uint *local_84;
  int *local_80;
  uint *local_70;
  
  iVar42 = 8;
  iVar11 = 0;
  do {
    *(undefined4 *)((int)local_c168 + iVar11) = 0xffffffff;
    *(undefined4 *)((int)local_c188 + iVar11) = 0;
    iVar11 = iVar11 + 4;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  bVar3 = param_1 == 0;
  local_c168[0] = local_c168[0] & 0xffff0000;
  pvVar14 = _malloc(0x400);
  local_9d20 = 0;
  local_c018 = 0;
  local_9d70 = 0;
  local_9d6c = 0;
  if (bVar3) {
    local_c01c = 0;
  }
  else {
    uVar21 = 0;
    iVar42 = 0x10;
    local_c018 = 0;
    local_c01c = 0;
    puVar31 = local_bf94;
    iVar11 = param_1;
    do {
      iVar23 = *(int *)(((unsigned char *)0x000013f8) + iVar11);
      if ((iVar23 != 0) && (*(short *)(iVar23 + 0x38) == 0x1902)) {
        uVar17 = 1 << (uVar21 & 0x3f);
        local_c01c = uVar17 | local_c01c;
        *puVar31 = (uint)*(ushort *)(iVar23 + 0x58);
        puVar31[0x10] = (uint)*(ushort *)(iVar23 + 0x5c);
        if (*(short *)(iVar23 + 0x5a) != 0) {
          local_c018 = uVar17 | local_c018;
        }
      }
      uVar21 = uVar21 + 1;
      iVar11 = iVar11 + 4;
      puVar31 = puVar31 + 1;
      iVar42 = iVar42 + -1;
    } while (iVar42 != 0);
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
  iVar11 = 0;
  puVar31 = local_9dd4;
  iVar42 = 0x10;
  do {
    *puVar31 = 0;
    if ((!bVar3) && (*(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2) != 0)) {
      *puVar31 = (uint)*(byte *)(*(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2) + 0x30);
    }
    iVar11 = iVar11 + 1;
    puVar31 = puVar31 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  local_9e58 = 1;
  local_9e88 = 0;
  local_9d90 = param_3[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != -0x7baf)) {
    local_9d80 = 0;
  }
  else {
    local_9d80 = 1;
  }
  puVar36 = (uint *)*param_4;
  local_c08c = 0;
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
  iVar11 = param_4[1];
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
  puVar31 = local_bf04;
  iVar42 = 8;
  do {
    *puVar31 = 0;
    puVar31[0x408] = 0;
    puVar31 = puVar31 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  local_80 = local_9e54;
  iVar42 = 0x10;
  piVar12 = local_80;
  do {
    *piVar12 = 0;
    piVar12[0x10] = 0;
    piVar12 = piVar12 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
  iVar42 = 0;
  iVar23 = 0;
  uVar21 = 0;
  puVar31 = puVar36;
switchD_000cb23c_caseD_15:
  local_c1f8 = puVar31 + 2;
  puVar15 = local_c1f8;
switchD_000cb23c_caseD_18:
  puVar31 = puVar15;
  if (puVar31 < puVar36 + iVar11) goto code_r0x000cb214;
  if (local_9ec4 != 0) {
    puVar31 = (uint *)0x0;
    uVar17 = 0;
    goto LAB_000cc88c;
  }
  iVar42 = (iVar11 + iVar42) * 4;
  local_c03c = local_c08c;
  if (local_c040 != 0) {
    iVar42 = iVar42 + 0x48;
  }
  uVar17 = iVar42 + iVar23 * 4;
  bVar5 = local_9ebc != 0;
  if (bVar5) {
    uVar17 = uVar17 + 0x14;
  }
  uVar10 = uVar17;
  if ((local_9e9c[0] != 0) && (uVar10 = uVar17 + 0xc, bVar5)) {
    uVar10 = uVar17 + 0x24;
  }
  uVar17 = uVar10;
  if ((local_9e9c[1] != 0) && (uVar17 = uVar10 + 0xc, bVar5)) {
    uVar17 = uVar10 + 0x24;
  }
  uVar10 = uVar17;
  if ((local_9e9c[2] != 0) && (uVar10 = uVar17 + 0xc, bVar5)) {
    uVar10 = uVar17 + 0x24;
  }
  uVar24 = uVar10;
  if ((local_9e9c[3] != 0) && (uVar24 = uVar10 + 0xc, bVar5)) {
    uVar24 = uVar10 + 0x24;
  }
  if (((local_9e80 != 0) && (local_9e88 != 0)) && (local_9e58 == 0)) {
    uVar24 = uVar24 + 0x14;
  }
  if (local_9d90 == 1) {
    uVar24 = uVar24 + 0x24;
  }
  else if (local_9d90 == 2) {
    uVar24 = uVar24 + 0x30;
  }
  else if (local_9d90 == 3) {
    uVar24 = uVar24 + 0x40;
  }
  else if (local_9d90 == 0) goto LAB_000cbb64;
  uVar24 = uVar24 + 8;
  piVar12 = local_9e9c;
  iVar42 = 4;
  do {
    if (*piVar12 != 0) {
      uVar24 = uVar24 + 0x2c;
    }
    piVar12 = piVar12 + 1;
    iVar42 = iVar42 + -1;
  } while (iVar42 != 0);
LAB_000cbb64:
  if (((local_9e74 != 0) || (local_9e6c != 0)) || (uVar17 = uVar24, local_9e58 == 0)) {
    if ((local_9e78 == 0) && (local_9e70 != 0)) {
      uVar24 = uVar24 + 0xc;
    }
    uVar17 = uVar24;
    if ((local_9e58 == 0) && (uVar17 = uVar24 + 0xc, local_9d7c != 0)) {
      uVar17 = uVar24 + 0x18;
    }
  }
  bVar5 = true;
  puVar31 = _malloc(uVar17 + 0x10);
  *puVar31 = *puVar36;
  local_c1f8 = puVar36 + 2;
  puVar31[1] = puVar36[1];
  puVar19 = local_c1f8;
  puVar15 = puVar31 + 2;
  goto switchD_000cbc48_caseD_18;
code_r0x000cb214:
  uVar17 = *puVar31;
  puVar15 = puVar31;
  switch(uVar17 & 0xffff) {
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
    uVar26 = 1;
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
    uVar26 = 1;
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
    local_c1f8 = puVar31 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar26 = 0;
LAB_000cb4b0:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar26,2,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    local_c1f8 = puVar31 + 2;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    local_c1f8 = puVar31 + 3;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,3,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    local_c1f8 = puVar31 + *(ushort *)((int)puVar31 + 6) + 2;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    local_c1f8 = puVar31 + 3;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    local_c1f8 = puVar31 + 1;
    uVar10 = puVar31[1];
    uVar17 = uVar10 & 0x3f0000;
    ((int (*)())FUN_000c8600)(uVar10 & 0xffff,uVar10 >> 0x10 & 0x3f,&local_c08c,0,0);
    if (uVar17 == 0x160000) {
      local_c040 = 1;
    }
    else if (uVar17 == 0x110000) {
      local_c084 = 1 << (uVar10 & 0x3f) | local_c084;
    }
    else if (uVar17 == 0xf0000) {
      uVar21 = uVar21 | 1 << (uVar10 & 0x3f);
    }
    else if (uVar17 == 0x100000) {
      local_c028 = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar24 = uVar17 >> 0x1b & 3;
    uVar10 = uVar17 >> 0x10 & 0xff;
    if ((uVar24 == 2) || ((uVar24 == 0 && (local_9dd4[uVar10] == 2)))) {
      local_bf14 = 1 << (uVar17 >> 0x10 & 0x3f) | local_bf14;
    }
    FUN_000c7270(&local_c08c,uVar10,uVar17 >> 0x18 & 7);
    local_c1f8 = local_c1f8 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    local_c1f8 = puVar31 + 1;
    if ((int)uVar17 < 0) {
      local_c1f8 = puVar31 + 2;
    }
LAB_000cb6d4:
    local_c1f8 = local_c1f8 + 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    local_c1f8 = puVar31 + 1;
    uVar10 = puVar31[1];
    uVar17 = uVar10 >> 0x10 & 0x3f;
    if (uVar17 == 1) {
      local_c1a8 = puVar31[2];
      local_c1a4 = puVar31[3];
      local_c1a0 = puVar31[4];
      local_c1f8 = puVar31 + 6;
      local_c19c = puVar31[5];
      FUN_000c7290(&local_c08c,uVar10 & 0xffff,&local_c1a8);
      puVar15 = local_c1f8;
    }
    else {
      puVar15 = local_c1f8;
      if (uVar17 == 2) {
        local_c1a8 = puVar31[2];
        local_c1a4 = puVar31[3];
        local_c1a0 = puVar31[4];
        local_c1f8 = puVar31 + 6;
        local_c19c = puVar31[5];
        FUN_000c72f0(&local_c08c,uVar10 & 0xffff,&local_c1a8);
        puVar15 = local_c1f8;
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    iVar42 = iVar42 + 5;
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,1,2,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    local_c1f8 = puVar31 + 2;
    local_c1c0[0] = puVar31[1];
    ((int (*)())FUN_000c87d0)(local_c1c0,auStack_c1b4,&local_c08c);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,0,1,&local_c08c);
    local_9e60 = 1;
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar26 = 0;
    break;
  case 0x5d:
    local_c1f8 = puVar31 + 2;
    local_9d6c = local_9d6c + 1;
    uVar17 = puVar31[1];
    uVar10 = *puVar31;
    if ((((uVar10 & 0xc000000) == 0x4000000) ||
        (((uVar10 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar23 = iVar23 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_c018;
      uVar10 = *puVar31;
    }
    if ((int)uVar10 < 0) {
      local_c1f8 = puVar31 + 3;
      uVar10 = *puVar31;
    }
    if ((uVar10 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar17 & 0x400000) != 0) {
      unaff_r20 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar17 & 0xffff,uVar17 >> 0x10 & 0x3f,local_88,unaff_r20,uVar17 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c01c) != 0) {
      iVar23 = iVar23 + 4;
    }
    local_c1e4 = *local_c1f8;
    puVar31 = local_c1f8 + 1;
    if ((local_c1e4 & 0x400000) != 0) {
      local_c1f0 = local_c1f8[1];
      puVar31 = local_c1f8 + 2;
    }
    local_c1f8 = puVar31;
    ((int (*)())FUN_000c87d0)(&local_c1e4,&local_c1f0,local_88);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    local_c1f8 = puVar31 + 2;
    local_9d6c = local_9d6c + 1;
    uVar17 = puVar31[1];
    uVar10 = *puVar31;
    if ((((uVar10 & 0xc000000) == 0x4000000) ||
        (((uVar10 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar31 + 1) & 0x3f) != 0)) {
      iVar23 = iVar23 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar31 + 1) & 0x3f) | local_c018;
      uVar10 = *puVar31;
    }
    if ((int)uVar10 < 0) {
      local_c1f8 = puVar31 + 3;
      uVar10 = *puVar31;
    }
    if ((uVar10 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar17 & 0x400000) != 0) {
      unaff_r19 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar17 & 0xffff,uVar17 >> 0x10 & 0x3f,local_88,unaff_r19,uVar17 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar31 + 1) & 0x3f) & local_c01c) != 0) {
      iVar23 = iVar23 + 4;
    }
    local_c1f0 = *local_c1f8;
    puVar31 = local_c1f8 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1e4 = local_c1f8[1];
      puVar31 = local_c1f8 + 2;
    }
    local_c1ec[0] = *puVar31;
    local_c1f8 = puVar31 + 1;
    if ((local_c1ec[0] & 0x400000) != 0) {
      local_c1e0[0] = puVar31[1];
      local_c1f8 = puVar31 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_c1f0,&local_c1e4,local_88);
    ((int (*)())FUN_000c87d0)(local_c1ec,local_c1e0,local_88);
    puVar15 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar31,uVar26,1,&local_c08c);
  puVar15 = local_c1f8;
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  local_c1f4 = puVar15;
  puVar18 = puVar19;
  if (puVar36 + iVar11 <= puVar18) {
    uVar17 = uVar17 >> 2;
    local_c084 = uVar21 | local_c084;
LAB_000cc88c:
    if (local_9ec4 != 0) {
      _free(puVar31);
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
      param_3[0x2e] = local_c034 + param_2[0x7c7];
      param_3[0x2f] = local_c030 + param_2[0x7c7];
    }
    if ((local_c028 == 0) || (local_c024 == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      param_2[0x7a3] = local_c024 + 2;
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
    }
    if (local_9d90 == 0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = local_c020;
      param_3[0x38] = local_9d88 + param_2[0x7c7];
      param_3[0x39] = local_9d84 + param_2[0x7c7];
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
    iVar11 = 8;
    uVar21 = 0;
    piVar25 = param_3 + 0x2c;
    piVar12 = param_3;
    do {
      if ((1 << (uVar21 & 0x3f) & local_c084) == 0) {
        *(undefined1 *)(piVar12 + 0x2c) = 0;
      }
      else if ((local_c040 == 0) || (local_c02c != uVar21)) {
        *(undefined1 *)(piVar12 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)piVar25 = 0;
      }
      uVar21 = uVar21 + 1;
      piVar25 = (int *)((int)piVar25 + 1);
      piVar12 = (int *)((int)piVar12 + 1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    param_2[0x7a9] = 0;
    param_3[0x36] = 0;
    uVar21 = 0;
    iVar11 = 0x10;
    *(undefined4 *)(((unsigned char *)0x000010e0) + *param_3) = local_bfd4;
    piVar12 = local_80;
    piVar25 = param_2;
    piVar29 = param_2;
    do {
      uVar10 = 1 << (uVar21 & 0x3f);
      if ((uVar10 & local_bf14) == 0) {
        *(undefined1 *)(piVar29 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar29 + 0x582) = 1;
      }
      if ((uVar10 & local_c01c) == 0) {
        *(undefined1 *)(piVar29 + 0x586) = 0;
      }
      else {
        *(undefined1 *)(piVar29 + 0x586) = 1;
        param_2[0x7a9] = 1;
        piVar25[0x7aa] = piVar12[-0x860] + param_2[0x7c7];
      }
      uVar21 = uVar21 + 1;
      piVar25[0x572] = *piVar12;
      piVar25 = piVar25 + 1;
      piVar2 = piVar12 + 0x10;
      piVar12 = piVar12 + 1;
      *(char *)(piVar29 + 0x56e) = (char)*piVar2;
      fVar9 = FLOAT_001aa0e8;
      piVar29 = (int *)((int)piVar29 + 1);
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar11 = 0;
    piVar12 = param_2;
    piVar25 = param_2;
    do {
      if (((!bVar3) && (*(char *)(piVar25 + 0x586) != '\0')) &&
         (iVar42 = *(int *)(((unsigned char *)0x000013f8) + iVar11 * 4 + *param_2), iVar42 != 0)) {
        ((void (*)())FUN_000c8e30)((double)(fVar9 / *(float *)(iVar42 + 0x44)),
                     (double)(fVar9 / *(float *)(iVar42 + 0x48)),(double)*(float *)(iVar42 + 0x50),
                     (double)FLOAT_001aa0e8,*param_3,
                     (param_3[0x36] - param_2[0x7c7]) + piVar12[0x7aa]);
      }
      bVar5 = iVar11 != 0xf;
      piVar12 = piVar12 + 1;
      piVar25 = (int *)((int)piVar25 + 1);
      iVar11 = iVar11 + 1;
    } while (bVar5);
    local_88 = &local_c08c;
    iVar11 = 0;
    puVar36 = local_aee4;
    puVar34 = auStack_beec;
    puVar32 = auStack_aecc;
    do {
      puVar41 = (undefined4 *)(puVar32 + 8);
      pfVar38 = (float *)(puVar34 + 8);
      uVar21 = 0;
      iVar42 = iVar11 << 2;
      do {
        uVar10 = 1 << (uVar21 & 0x3f);
        if ((uVar10 & puVar36[-0x408]) != 0) {
          ((void (*)())FUN_000c8e30)((double)*pfVar38,(double)pfVar38[1],(double)pfVar38[2],(double)pfVar38[3],
                       *param_3,iVar11 + uVar21);
        }
        if ((uVar10 & *puVar36) != 0) {
          uVar30 = puVar41[1];
          uVar26 = *puVar41;
          iVar23 = iVar42 + *param_3;
          ((unsigned char *)0x000036c9)[iVar23] = (char)puVar41[2];
          ((unsigned char *)0x000036cb)[iVar23] = (char)uVar26;
          ((unsigned char *)0x000036ca)[iVar23] = (char)uVar30;
        }
        bVar3 = uVar21 != 0x1f;
        iVar42 = iVar42 + 4;
        puVar41 = puVar41 + 4;
        pfVar38 = pfVar38 + 4;
        uVar21 = uVar21 + 1;
      } while (bVar3);
      bVar3 = iVar11 != 0xe0;
      puVar32 = puVar32 + 0x200;
      puVar34 = puVar34 + 0x200;
      puVar36 = puVar36 + 1;
      iVar11 = iVar11 + 0x20;
    } while (bVar3);
    *(uint *)(((unsigned char *)0x00003748) + *param_3) = local_aee4[0];
    _memset(auStack_c148,0,0xbc);
    _memset(auStack_9d1c,0,0x9c88);
    pvVar16 = _malloc(param_5[1]);
    if (pvVar16 == (void *)0x0) {
      return -1;
    }
    _memset(pvVar16,0,param_5[1]);
    local_c0f8 = uVar17 << 2;
    puVar15 = local_c080;
    puVar36 = local_c0f0;
    iVar11 = 8;
    local_c090 = pvVar16;
    do {
      uVar21 = *puVar15;
      uVar17 = puVar15[8];
      puVar15 = puVar15 + 1;
      *puVar36 = uVar21;
      puVar36[8] = uVar17;
      puVar36 = puVar36 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    local_c100 = local_c198;
    local_9cd4 = 0x40;
    local_c198[0] = local_c198[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar31;
    local_9cbc = _malloc(0x900);
    iVar11 = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (iVar11 != 0) {
      return 2;
    }
    iVar11 = 0;
    puVar32 = auStack_96d0;
    do {
      _memcpy((void *)(param_3[3] + iVar11),puVar32,0x48);
      iVar42 = iVar11 + param_3[3];
      if ((*(int *)(iVar11 + param_3[3]) == 1) && (*(char *)(iVar42 + 8) == '\x0f')) {
        *(char *)(iVar42 + 8) = (char)local_c024;
      }
      iVar11 = iVar11 + 0x48;
      puVar32 = puVar32 + 0x48;
    } while (iVar11 != 0x9360);
    iVar23 = 0;
    iVar11 = 0;
    iVar42 = 0;
    iVar40 = 0x1a20;
    piVar12 = param_2 + 0x594;
    do {
      uVar21 = *(uint *)((int)local_9c84 + iVar11) | *(uint *)((int)local_88 + iVar11 + 0x188);
      *(uint *)(((unsigned char *)0x000010b8) + iVar23 * 4 + *param_3) = uVar21;
      if (uVar21 != 0) {
        iVar20 = param_2[0x7c7];
        pbVar22 = (byte *)(piVar12 + 2);
        piVar25 = (int *)((int)param_2 + iVar40);
        iVar27 = iVar42;
        do {
          bVar7 = (byte)uVar21;
          uVar21 = uVar21 >> 1;
          iVar13 = iVar27 + iVar20;
          *pbVar22 = bVar7 & 1;
          iVar27 = iVar27 + 1;
          pbVar22 = pbVar22 + 1;
          *piVar25 = iVar13;
          piVar25 = piVar25 + 1;
        } while (uVar21 != 0);
      }
      bVar3 = iVar23 != 7;
      iVar11 = iVar11 + 4;
      iVar42 = iVar42 + 0x20;
      piVar12 = piVar12 + 8;
      iVar40 = iVar40 + 0x80;
      iVar23 = iVar23 + 1;
    } while (bVar3);
    if (*(int *)(((unsigned char *)0x000010b8) + *param_3) == 0) {
      *(undefined4 *)(((unsigned char *)0x000010d8) + *param_3) = 0;
    }
    for (; iStack_318 != 0; iStack_318 = iStack_318 + -1) {
    }
    if (local_9cc8 != 0) {
      uVar17 = 0;
      uVar21 = local_9cc8;
      do {
        piVar12 = (int *)(uVar17 * 0x24 + (int)local_9cbc);
        switch(piVar12[2]) {
        case 1:
          iVar11 = piVar12[1];
          iVar42 = *param_3;
          iVar23 = *piVar12;
          if (iVar11 == 1) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x90);
          }
          else if (iVar11 == 0) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x8c);
          }
          else if (iVar11 == 2) {
            piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x94);
          }
          else {
            piVar25 = (int *)0x0;
            if (iVar11 == 3) {
              piVar25 = (int *)(iVar23 * 0x10 + iVar42 + 0x98);
            }
          }
          *piVar25 = piVar12[5];
          uVar21 = local_9cc8;
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())FUN_000c8de0)(param_3 + 0x48);
          uVar21 = local_9cc8;
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 < uVar21);
    }
    if (local_9c18 != 0) {
      iVar11 = 0;
      pcVar28 = local_9c14;
      if (local_9c18 == 0) {
        local_9c18 = 1;
      }
      do {
        cVar6 = *pcVar28;
        pcVar28 = pcVar28 + 0xc;
        if (cVar6 != '\x02') {
          iVar11 = iVar11 + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_c024 + 2;
        }
        local_9c18 = local_9c18 + -1;
      } while (local_9c18 != 0);
      iVar42 = 1;
      if (8 < iVar11) goto LAB_000ccf90;
    }
    iVar42 = 0;
LAB_000ccf90:
    iVar11 = 0;
    iVar23 = 0x10;
    do {
      iVar40 = iVar11 * 0x10;
      iVar11 = iVar11 + 1;
      *(undefined4 *)(iVar40 + param_3[1] + 0x108) = 0;
      *(undefined4 *)(iVar40 + param_3[1] + 0x10c) = 1;
      *(undefined4 *)(iVar40 + param_3[1] + 0x110) = 2;
      *(undefined4 *)(iVar40 + param_3[1] + 0x114) = 3;
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    _free(local_9cbc);
    _free(pvVar16);
    if (pvVar14 != (void *)0x0) {
      _free(pvVar14);
    }
    if (puVar31 != (uint *)0x0) {
      _free(puVar31);
    }
    return iVar42;
  }
  uVar10 = *puVar18;
  puVar19 = puVar18;
  puVar15 = local_c1f4;
  switch(uVar10 & 0xffff) {
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
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,1,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
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
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,2,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,0,2,&local_c08c);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_c1f4 = uVar10;
    local_c1f8 = puVar18 + 2;
    local_c1f4[1] = puVar18[1];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_c1f4 = uVar10;
    local_c1f4[1] = puVar18[1];
    local_c1f8 = puVar18 + 3;
    local_c1f4[2] = puVar18[2];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 3;
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
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
    }
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,3,local_88);
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    local_c1f8 = puVar18 + 2;
    *local_c1f4 = uVar10;
    local_c1f4[1] = puVar18[1];
    puVar15 = local_c1f4 + 2;
    for (uVar10 = (uint)*(ushort *)((int)puVar18 + 6); puVar19 = local_c1f8, uVar10 != 0;
        uVar10 = uVar10 - 1) {
      uVar24 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
      *puVar15 = uVar24;
      puVar15 = puVar15 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    local_c1f8 = puVar18 + 1;
    if ((uVar10 & 0x18000000) == 0) {
      uVar24 = *(uint *)((int)local_9dd4 + (uVar10 >> 0xe & 0x3fc));
      if (uVar24 != 2) {
        uVar24 = 1;
      }
      uVar10 = (uVar24 & 3) << 0x1b | uVar10 & 0xe7ffffff;
    }
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar15 = local_c1f4 + 1;
    if ((int)uVar10 < 0) {
      uVar10 = *local_c1f8;
      local_c1f8 = puVar18 + 2;
      local_c1f4[1] = uVar10;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    uVar10 = *local_c1f8;
    local_c1f8 = local_c1f8 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    local_c1f8 = puVar18 + 1;
    *local_c1f4 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    if ((puVar18[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_c1f4[1] = puVar18[1];
      local_c1f4[2] = puVar18[2];
      local_c1f4[3] = puVar18[3];
      local_c1f4[4] = puVar18[4];
      local_c1f8 = puVar18 + 6;
      local_c1f4[5] = puVar18[5];
      puVar19 = local_c1f8;
      puVar15 = local_c1f4 + 6;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    local_c1f8 = puVar18 + 1;
    puVar15 = (uint *)((int (*)())FUN_000c7930)(local_c1f4,&local_c08c);
    *puVar15 = uVar10;
    puVar19 = local_c1f8;
    puVar15 = puVar15 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    *local_c1f4 = uVar10;
    local_c1f8 = puVar18 + 2;
    local_c1c0[0] = puVar18[1];
    local_c1f4 = local_c1f4 + 1;
    ((int (*)())FUN_000c8760)(local_c1c0,auStack_c1b4,&local_c08c);
    *local_c1f4 = local_c1c0[0];
    puVar19 = local_c1f8;
    puVar15 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    uVar26 = 0;
    break;
  case 0x3b:
    uVar26 = 1;
    break;
  case 0x5d:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,local_88);
      puVar18 = local_c1f8;
    }
    uVar37 = *puVar18;
    puVar15 = puVar18 + 1;
    uVar10 = uVar37 >> 0x10;
    uVar24 = uVar10 & 0xff;
    bVar4 = (uVar37 & 0x80000000) != 0;
    if (bVar4) {
      puVar15 = puVar18 + 2;
      uVar33 = puVar18[1];
    }
    else {
      uVar33 = 0;
    }
    bVar1 = (uVar37 >> 0x1e & 1) != 0;
    if (bVar1) {
      uVar35 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar35 = 0;
    }
    local_c1f0 = *puVar15;
    puVar19 = puVar15 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      puVar19 = puVar15 + 2;
      unaff_r15 = puVar15[1];
    }
    local_c1cc = *puVar19;
    local_c1f8 = puVar19 + 1;
    if ((local_c1cc & 0x400000) != 0) {
      local_c1d8 = puVar19[1];
      local_c1f8 = puVar19 + 2;
    }
    uVar8 = uVar37 & 0xc000000;
    if (uVar8 == 0x4000000) {
LAB_000cc2a4:
      if (local_c01c << (uVar10 & 0x3f) == 0) {
        local_84 = &local_c1cc;
        uVar26 = 0;
        uVar39 = 1 << (uVar10 & 0x3f);
        puVar15 = &local_c1d8;
      }
      else {
        local_84 = &local_c1cc;
        local_70 = &local_c1d8;
        local_c1f4 = (uint *)((int (*)())FUN_000c7460)(local_88,local_84,local_70,uVar24,local_c1f4);
        puVar15 = local_70;
        if ((local_c1f0 & 0x400000) == 0) {
          uVar26 = 0;
          uVar39 = 1 << (uVar10 & 0x3f);
        }
        else {
          local_c1f0 = local_c1f0 & 0xffbfffff;
          uVar26 = 1;
          uVar39 = 1 << (uVar10 & 0x3f);
          local_c1e4 = unaff_r15;
        }
      }
    }
    else if (uVar8 == 0x8000000) {
      uVar39 = 1 << (uVar10 & 0x3f);
      if ((uVar39 & local_c018) != 0) goto LAB_000cc2a4;
      local_84 = &local_c1cc;
      uVar26 = 0;
      puVar15 = &local_c1d8;
    }
    else {
      uVar26 = 0;
      uVar39 = 1 << (uVar10 & 0x3f);
      local_84 = &local_c1cc;
      puVar15 = &local_c1d8;
    }
    ((int (*)())FUN_000c8760)(local_84,puVar15,local_88);
    *local_c1f4 = uVar37;
    puVar15 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = uVar33;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (bVar1) {
      *local_c1f4 = uVar35;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = local_c1f0;
    puVar15 = local_c1f4 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r15;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1cc;
    puVar15 = local_c1f4 + 1;
    if ((local_c1cc & 0x400000) != 0) {
      local_c1f4[1] = local_c1d8;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (((uVar8 == 0x4000000) || ((uVar8 == 0x8000000 && ((uVar39 & local_c018) != 0)))) &&
       (local_c01c << (uVar10 & 0x3f) != 0)) {
      local_c1f4 = (uint *)((int (*)())FUN_000c7650)(local_88,local_84,&local_c1f0,&local_c1e4,uVar24,uVar26,
                                        local_c1f4);
    }
    uVar39 = uVar39 & local_c01c;
    uVar10 = unaff_r15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *)((int (*)())FUN_000c8110)(local_c1f4,&local_c08c);
      puVar18 = local_c1f8;
    }
    uVar37 = *puVar18;
    puVar15 = puVar18 + 1;
    uVar10 = uVar37 >> 0x10;
    uVar24 = uVar10 & 0xff;
    bVar4 = (uVar37 & 0x80000000) != 0;
    if (bVar4) {
      puVar15 = puVar18 + 2;
      uVar33 = puVar18[1];
    }
    else {
      uVar33 = 0;
    }
    bVar1 = (uVar37 & 0x40000000) != 0;
    if (bVar1) {
      uVar35 = *puVar15;
      puVar15 = puVar15 + 1;
    }
    else {
      uVar35 = 0;
    }
    local_c1f0 = *puVar15;
    puVar19 = puVar15 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      puVar19 = puVar15 + 2;
      unaff_r14 = puVar15[1];
    }
    local_c1d8 = *puVar19;
    puVar15 = puVar19 + 1;
    if ((local_c1d8 & 0x400000) != 0) {
      local_c1cc = puVar19[1];
      puVar15 = puVar19 + 2;
    }
    local_c1d4 = *puVar15;
    local_c1f8 = puVar15 + 1;
    if ((local_c1d4 & 0x400000) != 0) {
      local_c1c8 = puVar15[1];
      local_c1f8 = puVar15 + 2;
    }
    uVar8 = uVar37 & 0xc000000;
    if (uVar8 == 0x4000000) {
LAB_000cc588:
      if ((local_c01c << (uVar10 & 0x3f) == 0) ||
         (local_c1f4 = (uint *)((int (*)())FUN_000c7460)(&local_c08c,&local_c1d8,&local_c1cc,uVar24,local_c1f4),
         (local_c1f0 & 0x400000) == 0)) {
LAB_000cc5bc:
        uVar26 = 0;
        uVar39 = 1 << (uVar10 & 0x3f);
      }
      else {
        local_c1f0 = local_c1f0 & 0xffbfffff;
        uVar26 = 1;
        uVar39 = 1 << (uVar10 & 0x3f);
        local_c1e4 = unaff_r14;
      }
    }
    else {
      if (uVar8 != 0x8000000) goto LAB_000cc5bc;
      uVar26 = 0;
      uVar39 = 1 << (uVar10 & 0x3f);
      if ((uVar39 & local_c018) != 0) goto LAB_000cc588;
    }
    *local_c1f4 = uVar37;
    puVar15 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = uVar33;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (bVar1) {
      *local_c1f4 = uVar35;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = local_c1f0;
    puVar15 = local_c1f4 + 1;
    if ((local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r14;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1d8;
    puVar15 = local_c1f4 + 1;
    if ((local_c1d8 & 0x400000) != 0) {
      local_c1f4[1] = local_c1cc;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    *local_c1f4 = local_c1d4;
    puVar15 = local_c1f4 + 1;
    if ((local_c1d4 & 0x400000) != 0) {
      local_c1f4[1] = local_c1c8;
      puVar15 = local_c1f4 + 2;
    }
    local_c1f4 = puVar15;
    if (((uVar8 == 0x4000000) || ((uVar8 == 0x8000000 && ((uVar39 & local_c018) != 0)))) &&
       (local_c01c << (uVar10 & 0x3f) != 0)) {
      local_c1f4 = (uint *)((int (*)())FUN_000c7650)(&local_c08c,&local_c1d8,&local_c1f0,&local_c1e4,uVar24,
                                        uVar26,local_c1f4);
    }
    uVar39 = uVar39 & local_c01c;
    uVar10 = unaff_r14;
joined_r0x000cc708:
    puVar19 = local_c1f8;
    puVar15 = local_c1f4;
    if (uVar39 != 0) {
      *local_c1f4 = 0x47;
      uVar37 = local_c1f0;
      if ((local_c1f0 & 0x400000) == 0) {
        uVar37 = local_c1f0 | 0x400000;
        uVar10 = 0x55;
      }
      if (local_bf94[uVar24] == 0x1906) {
        if ((uVar10 & 3) == 1) {
          uVar10 = uVar10 & 0xfffffffc | 2;
        }
        if ((uVar10 & 0xc) == 4) {
          uVar10 = uVar10 & 0xfffffff3 | 8;
        }
        if ((uVar10 & 0x30) == 0x10) {
          uVar10 = uVar10 & 0xffffffcf | 0x20;
        }
      }
      else if ((local_bf94[uVar24] == 0x1909) && ((uVar10 & 0xc0) == 0x40)) {
        uVar10 = uVar10 & 0xffffff3f | 0xc0;
      }
      local_c1f4[1] = uVar37;
      local_c1f4[2] = uVar10;
      local_c1f4[3] = uVar37 & 0x3fffff;
      puVar15 = local_c1f4 + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,uVar26,1,&local_c08c);
  puVar19 = local_c1f8;
  puVar15 = local_c1f4;
  goto switchD_000cbc48_caseD_18;
switchD_000cb23c_caseD_0:
                    
  _exit(0);
}

/* FUN_000cd05c @ 0xcd05c (244 bytes) */
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
int FUN_000cd1b0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_000da394();
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
    FUN_000e0ca8();
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
int FUN_000cd1ec()
{
  undefined4 in_r6;
  undefined4 uStack00000024;
  
  uStack00000024 = in_r6;
  ((int (*)())FUN_000cd388)();
  return;
}

/* FUN_000cd214 @ 0xcd214 (40 bytes) */
int FUN_000cd214(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cd404)(param_1,param_2,&STACKARG(0x20));
  return;
}

/* FUN_000cd23c @ 0xcd23c (40 bytes) */
int FUN_000cd23c()
{
  undefined4 in_r7;
  undefined4 uStack00000028;
  
  uStack00000028 = in_r7;
  ((int (*)())FUN_000cdba4)();
  return;
}

/* FUN_000cd264 @ 0xcd264 (40 bytes) */
int FUN_000cd264(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uStack00000020;
  
  uStack00000020 = param_3;
  ((int (*)())FUN_000cdbe4)(param_1,param_2,&STACKARG(0x20));
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
  FUN_000e06d8();
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
int FUN_000cd404(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  int param_3;
{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_238 [128];
  undefined1 auStack_1b8 [128];
  undefined1 auStack_138 [128];
  undefined1 auStack_b8 [144];
  
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_3 == 0) {
    return;
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"; ------------- SC_SRCSHADER Dump ------------------\r\n");
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntVSConst = %d\r\n",param_2[3]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntPSConst = %d\r\n",param_2[4]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumIntGSConst = %d\r\n",param_2[5]);
  if (((param_2[3] != 0) && (*param_2 != 0)) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer VS Constants"), param_2[3] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + *param_2;
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + *param_2),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[3]);
  }
  if ((param_2[4] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer PS Constants"), param_2[4] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + param_2[1];
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + param_2[1]),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[4]);
  }
  if ((param_2[5] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Integer GS Constants"), param_2[5] != 0)
     ) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10 + param_2[2];
      uVar4 = uVar5 + 1;
      ((int (*)())FUN_000cd3a4)(param_1,param_3,
                   "SC_SHADERSTATE: i%d = Count(%d), LoopStart(%d), LoopStep(%d)\r\n",uVar5,
                   *(undefined4 *)(uVar5 * 0x10 + param_2[2]),*(undefined4 *)(iVar3 + 4),
                   *(undefined4 *)(iVar3 + 8));
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[5]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolVSConst = %d\r\n",param_2[9]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolPSConst = %d\r\n",param_2[10]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumBoolGSConst = %d\r\n",param_2[0xb]);
  if (param_2[9] == 0) goto LAB_000cd7d0;
  if (param_2[6] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool VS Constants");
    if (param_2[9] == 0) goto LAB_000cd7d0;
    uVar5 = 0;
    do {
      if (*(int *)(uVar5 * 4 + param_2[6]) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[9]);
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if (param_2[7] != 0) {
    ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool PS Constants");
    if (param_2[10] != 0) {
      uVar5 = 0;
      do {
        if (*(int *)(uVar5 * 4 + param_2[7]) == 0) {
          pcVar2 = "FALSE";
        }
        else {
          pcVar2 = "TRUE";
        }
        ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)param_2[10]);
    }
    if (param_2[9] == 0) goto LAB_000cd7d0;
  }
  if ((param_2[8] != 0) &&
     (((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Bool GS Constants"), param_2[0xb] != 0))
  {
    uVar5 = 0;
    do {
      if (*(int *)(uVar5 * 4 + param_2[8]) == 0) {
        pcVar2 = "FALSE";
      }
      else {
        pcVar2 = "TRUE";
      }
      ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: b%d = %s\r\n",uVar5,pcVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_2[0xb]);
  }
LAB_000cd7d0:
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatVSConst = %d\r\n",param_2[0xf]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatPSConst = %d\r\n",param_2[0x10]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: u32NumFloatGSConst = %d\r\n",param_2[0x11]);
  if (((param_2[0xf] != 0) && (param_2[0xc] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float VS Constants"),
     param_2[0xf] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xc] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0xf]);
  }
  if (((param_2[0x10] != 0) && (param_2[0xd] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float PS Constants"),
     param_2[0x10] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xd] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0x10]);
  }
  if (((param_2[0x11] != 0) && (param_2[0xe] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float GS Constants"),
     param_2[0x11] != 0)) {
    uVar5 = 0;
    do {
      iVar3 = uVar5 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3),uVar1,10,auStack_238);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 4),uVar1,10,auStack_1b8);
      uVar1 = ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 8),uVar1,10,auStack_138);
      ((char * (*)())FUN_000cdc3c)((double)*(float *)(param_2[0xe] + iVar3 + 0xc),uVar1,10,auStack_b8);
      uVar4 = uVar5 + 1;
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar5,
                           auStack_238,auStack_1b8,auStack_138,auStack_b8);
      uVar5 = uVar4;
    } while (uVar4 < (uint)param_2[0x11]);
  }
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"u32Copts = 0x%08X",param_2[0x15]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"fConstantsAvailable = %d",param_2[0x16],param_2[0x17],param_2[0x18],
               param_2[0x19],param_2[0x1a]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"iConstantsAvailable = %d",param_2[0x1e],param_2[0x1f],param_2[0x20],
               param_2[0x21],param_2[0x22]);
  ((int (*)())FUN_000cd3a4)(param_1,param_3,"bConstantsAvailable = %d",param_2[0x26],param_2[0x27],param_2[0x28],
               param_2[0x29],param_2[0x2a]);
  return;
}

/* FUN_000cdba4 @ 0xcdba4 (64 bytes) */
int FUN_000cdba4(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
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
    ((int (*)())FUN_000d035c)();
    return;
  }
  if (*(int *)(param_2 + 0xf8) != 1) {
    return;
  }
  FUN_000d4e8c();
  return;
}

/* FUN_000cdbe4 @ 0xcdbe4 (60 bytes) */
int FUN_000cdbe4(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
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
    ((int (*)())FUN_000d0304)();
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
char * FUN_000cdc3c(double param_1,int param_2,int *param_3,char *param_4)

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
  double dVar12;
  double dVar13;
  double dVar14;
  uint local_98;
  
  pcVar6 = _ecvt(param_1,param_2,param_3,param_3);
  if ((1 - (int)param_3 < 1) && (-1 < (int)param_3)) {
    *param_4 = '0';
    param_4[1] = '.';
    uVar9 = 2;
    if (*pcVar6 != '\0') {
      iVar7 = 0;
      pcVar8 = pcVar6;
      do {
        if (iVar7 == -1) {
          param_4[uVar9] = '.';
          uVar9 = uVar9 + 1;
        }
        iVar7 = iVar7 + 1;
        param_4[uVar9] = *pcVar8;
        uVar9 = uVar9 + 1;
        pcVar8 = pcVar6 + iVar7;
      } while (pcVar6[iVar7] != '\0');
    }
    param_4[uVar9] = '\0';
    cVar5 = *param_4;
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
        cVar5 = param_4[iVar7];
      } while (cVar5 != '\0');
    }
    param_4[uVar11] = '\0';
  }
  else {
    *param_4 = *pcVar6;
    param_4[1] = '.';
    iVar7 = 2;
    cVar5 = pcVar6[1];
    if (cVar5 != '\0') {
      pcVar8 = param_4 + 2;
      iVar3 = 1;
      do {
        *pcVar8 = cVar5;
        iVar3 = iVar3 + 1;
        cVar5 = pcVar6[iVar3];
        iVar7 = iVar7 + 1;
        pcVar8 = pcVar8 + 1;
      } while (cVar5 != '\0');
    }
    param_4[iVar7] = 'e';
    param_4[iVar7 + 1] = '-';
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
    pcVar6 = param_4 + iVar7 + 2;
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
    param_4[uVar10 + iVar7 + 2] = '\0';
  }
  return param_4;
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
    FUN_001a34d4(acStack_a4,param_2,&STACKARG(0x20));
    pcVar2 = _strchr(acStack_a4,0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    FUN_001a32d0(acStack_a4,"%s\n",acStack_a4);
    (*(code *)**(undefined4 **)(param_1 + 8))
              (*(undefined4 *)(param_1 + 0xc),"",acStack_a4,&STACKARG(0x20));
  }
  return;
}

/* FUN_000ce148 @ 0xce148 (836 bytes) */
int FUN_000ce148(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  bool bVar1;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char acStack_48 [32];
  
  uVar4 = *param_2;
  uVar2 = uVar4 & 0x1e000000;
  uVar6 = uVar4 & 0xf;
  *param_3 = '\0';
  if (uVar2 == 0x1e000000) {
    uVar5 = 0;
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '-';
    (param_3 + sVar3)[1] = '\0';
  }
  else {
    uVar5 = -uVar2 >> 0x1f;
  }
  if (uVar6 == 1) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'v';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 0) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'r';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 2) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 'c';
    (param_3 + sVar3)[1] = '\0';
  }
  else if (uVar6 == 3) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = 't';
    (param_3 + sVar3)[1] = '\0';
  }
  else {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '?';
    (param_3 + sVar3)[1] = '\0';
  }
  FUN_001a32d0(acStack_48,"%d",uVar4 >> 5 & 0xff);
  if ((uVar4 & 0x80000010) == 0) {
    _strcat(param_3,acStack_48);
  }
  else {
    if ((uVar4 & 0x80000010) == 0x10) {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[a0",4);
    }
    else {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[i0",4);
    }
    switch(uVar4 >> 0x1d & 3) {
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
    _strcat(param_3,acStack_48);
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = ']';
    (param_3 + sVar3)[1] = '\0';
  }
  if (((uVar4 & 0x1ffe000) != 0xd10000) || (uVar5 != 0)) {
    uVar6 = 0;
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '.';
    (param_3 + sVar3)[1] = '\0';
    uVar7 = 0xd;
    do {
      if (((uVar2 & 0x2000000 << (uVar6 & 0x3f)) != 0) && (uVar5 != 0)) {
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '-';
        (param_3 + sVar3)[1] = '\0';
      }
      switch((uVar4 & 0x1ffe000 & 7 << (uVar7 & 0x3f)) >> (uVar7 & 0x3f)) {
      case 0:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'x';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 1:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'y';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 2:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'z';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 3:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = 'w';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 4:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '0';
        (param_3 + sVar3)[1] = '\0';
        break;
      case 5:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '1';
        (param_3 + sVar3)[1] = '\0';
        break;
      default:
        sVar3 = _strlen(param_3);
        (param_3 + sVar3)[0] = '?';
        (param_3 + sVar3)[1] = '\0';
      }
      bVar1 = uVar6 != 3;
      uVar7 = uVar7 + 3;
      uVar6 = uVar6 + 1;
    } while (bVar1);
  }
  return param_2 + 1;
}

/* FUN_000ce4e4 @ 0xce4e4 (48 bytes) */
int FUN_000ce4e4(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  if ((*param_2 & 1) == 0) {
    return;
  }
  ((int (*)())FUN_000ce050)(param_1,";    v%d = dx v%d",*(undefined1 *)(param_2 + 1),
               *(undefined1 *)((int)param_2 + 1));
  return;
}

/* FUN_000ce514 @ 0xce514 (864 bytes) */
int FUN_000ce514(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  bool bVar1;
  byte bVar2;
  char *acVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
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
  undefined1 auStack_78 [76];
  
  if ((*param_2 & 1) != 0) {
    acVar3 = acStack_1ef;
    switch(*(undefined1 *)param_2) {
    case 0:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pos_001a62cc) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_pos_001a62cc) + 5));
      local_1f4 = s_IL_pos_001a62cc[4];
      break;
    case 1:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 8));
      local_1ec = s_IL_pointsize_001a62d4[0xc];
      break;
    case 2:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 4));
      local_1f0 = s_IL_color_001a62e4[8];
      local_1f0 = CONCAT13(local_1f0,acVar3);
      break;
    case 3:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 4));
      local_1f0 = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 8));
      local_1ec = s_IL_backcolor_001a62f0[0xc];
      break;
    case 4:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_fog_001a6300) + 0));
      (*(unsigned short *)((unsigned char *)&(acStack_1f3) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_fog_001a6300) + 5));
      local_1f4 = s_IL_fog_001a6300[4];
      break;
    case 5:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      local_1f0 = s_IL_generic_001a6308[8];
      break;
    default:
      *(unsigned int *)local_1f8 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
      local_1f4 = (*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 4));
      (*(unsigned short *)((unsigned char *)&(acStack_1ef) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      local_1f0 = s_IL_unknown_001a6314[8];
    }
    FUN_001a32d0(local_218 + 4,"%d",*(undefined1 *)((int)param_2 + 1));
    builtin_strncpy(local_218,"xyzw",4);
    uVar11 = *param_2 >> 4;
    iVar4 = 0;
    bVar1 = false;
    uVar9 = 0;
    pcVar8 = local_218;
    iVar12 = 4;
    puVar6 = param_2;
    do {
      if ((uVar11 & 0xf & 1 << (uVar9 & 0x3f)) != 0) {
        bVar2 = *(byte *)(puVar6 + 1);
        *(uint *)(pcVar8 + 0x10) = (uint)bVar2;
        if ((iVar4 != 0) && ((uint)bVar2 != *(uint *)(pcVar8 + 0xc))) {
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 4;
      }
      uVar9 = uVar9 + 1;
      puVar6 = (uint *)((int)puVar6 + 1);
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    if (bVar1) {
      uVar11 = 0;
      puVar10 = auStack_138;
      puVar6 = param_2;
      do {
        if ((*param_2 >> 4 & 0xf & 1 << (uVar11 & 0x3f)) == 0) {
          auStack_138[uVar11 * 0x40] = 0;
        }
        else {
          FUN_001a32d0(puVar10,"o%d.%c ",*(undefined1 *)(puVar6 + 1),
                       (int)local_218[*(byte *)(puVar6 + 2)]);
        }
        bVar1 = uVar11 != 3;
        puVar10 = puVar10 + 0x40;
        puVar6 = (uint *)((int)puVar6 + 1);
        uVar11 = uVar11 + 1;
      } while (bVar1);
      FUN_001a32d0(auStack_1b8,"%s%s%s%s",auStack_138,auStack_f8,auStack_b8,auStack_78);
    }
    else {
      iVar4 = 0x5f;
      if ((uVar11 & 1) != 0) {
        iVar4 = (int)local_218[*(byte *)(param_2 + 2)];
      }
      iVar12 = 0x5f;
      if ((uVar11 & 2) != 0) {
        iVar12 = (int)local_218[*(byte *)((int)param_2 + 9)];
      }
      iVar5 = 0x5f;
      if ((uVar11 & 4) != 0) {
        iVar5 = (int)local_218[*(byte *)((int)param_2 + 10)];
      }
      iVar7 = 0x5f;
      if ((uVar11 & 8) != 0) {
        iVar7 = (int)local_218[*(byte *)((int)param_2 + 0xb)];
      }
      FUN_001a32d0(auStack_1b8,"o%d.%c%c%c%c",*(undefined1 *)(param_2 + 1),iVar4,iVar12,iVar5,iVar7)
      ;
    }
    ((int (*)())FUN_000ce050)(param_1,";    %s = %s%s",auStack_1b8,local_1f8,local_218 + 4);
  }
  return;
}

/* FUN_000ce88c @ 0xce88c (480 bytes) */
int FUN_000ce88c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  ((int (*)())FUN_000ce050)(param_1,";                 VS Data");
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  ((int (*)())FUN_000ce050)(param_1,"; Input Semantic Mappings");
  if (*(int *)(param_2 + 0x104) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No input mappings");
  }
  else {
    iVar3 = 0;
    iVar2 = param_2 + 0x108;
    do {
      ((int (*)())FUN_000ce4e4)(param_1,iVar2,iVar3);
      bVar1 = iVar3 != 0x3f;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,"; Output Semantic Mappings");
  if (*(int *)(param_2 + 0x408) == 0) {
    ((int (*)())FUN_000ce050)(param_1,";    No output mappings");
  }
  else {
    iVar3 = 0;
    iVar2 = param_2 + 0x40c;
    do {
      ((int (*)())FUN_000ce514)(param_1,iVar2,iVar3);
      bVar1 = iVar3 != 0x2f;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (bVar1);
  }
  ((int (*)())FUN_000ce050)(param_1,"");
  ((int (*)())FUN_000ce050)(param_1,"; Num Insts = %d",*(undefined4 *)(param_2 + 0x65c));
  ((int (*)())FUN_000ce050)(param_1,"; Max Temp = %d",*(int *)(param_2 + 0x660) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Max AltTemp = %d",*(int *)(param_2 + 0x664) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Max Constants = %d",*(int *)(param_2 + 0x670) + -1);
  ((int (*)())FUN_000ce050)(param_1,"; Last Pos Inst = %d",*(undefined4 *)(param_2 + 0x668));
  ((int (*)())FUN_000ce050)(param_1,"; Last Src Inst = %d",*(undefined4 *)(param_2 + 0x66c));
  if (*(int *)(param_2 + 0x658) != 0) {
    ((int (*)())FUN_000ce050)(param_1,"; Shader uses relative addressing");
  }
  return 1;
}

/* FUN_000cea6c @ 0xcea6c (660 bytes) */
int FUN_000cea6c(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
{
  undefined2 uVar1;
  uint uVar2;
  size_t sVar3;
  uint uVar4;
  char acStack_38 [28];
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(s_ox_001a64a8) + 1));
  uVar4 = *param_2;
  switch(uVar4 >> 8 & 0xf) {
  case 0:
    param_3[0] = 'r';
    param_3[1] = '\0';
    break;
  case 1:
    param_3[0] = 'a';
    param_3[1] = '\0';
    break;
  case 2:
    param_3[0] = 'o';
    param_3[1] = '\0';
    break;
  case 3:
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
    break;
  default:
    param_3[0] = '?';
    param_3[1] = '\0';
  }
  FUN_001a32d0(acStack_38,"%d",uVar4 >> 0xd & 0x7f);
  if ((uVar4 & 0x80001000) == 0) {
    _strcat(param_3,acStack_38);
  }
  else {
    if ((uVar4 & 0x80001000) == 0x80000000) {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[a0",4);
    }
    else {
      sVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + sVar3,"[i0",4);
    }
    switch(uVar4 >> 0x1d & 3) {
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
  if ((uVar4 & 0x40) == 0) {
    uVar2 = uVar4 & 0x1000000;
  }
  else {
    uVar2 = uVar4 & 0x2000000;
  }
  if (uVar2 != 0) {
    _strcat(param_3,"_sat");
  }
  if ((uVar4 & 0xf00000) != 0xf00000) {
    sVar3 = _strlen(param_3);
    (param_3 + sVar3)[0] = '.';
    (param_3 + sVar3)[1] = '\0';
    if ((uVar4 & 0x100000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'x';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x200000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'y';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x400000) != 0) {
      sVar3 = _strlen(param_3);
      (param_3 + sVar3)[0] = 'z';
      (param_3 + sVar3)[1] = '\0';
    }
    if ((uVar4 & 0x800000) != 0) {
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
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char acStack_48 [5];
  char acStack_43 [23];
  
  uVar2 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 4));
  uVar7 = *param_2;
  uVar4 = param_2[-3];
  uVar5 = uVar7 & 0x18000000;
  uVar6 = uVar7 & 0xf;
  *(undefined4 *)param_3 = (*(unsigned int *)((unsigned char *)&(s_Du_001a64b4) + 0));
  *(undefined4 *)(param_3 + 4) = uVar2;
  switch(uVar7 >> 0x15 & 0xf | (uVar7 & 4) << 2 | 0x40) {
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
    break;
  default:
    _strcat(param_3,"ERROR     ");
  }
  param_4[0] = 't';
  param_4[1] = '\0';
  FUN_001a32d0(acStack_48,"%d",uVar7 >> 0x13 & 3);
  if ((uVar4 & 0x2000000) != 0) {
    _strcat(param_4,"_sat");
  }
  _strcat(param_4,acStack_48);
  sVar3 = _strlen(param_4);
  (param_4 + sVar3)[0] = '.';
  (param_4 + sVar3)[1] = '\0';
  if (uVar5 == 0) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'x';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x8000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'y';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x10000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'z';
    (param_4 + sVar3)[1] = '\0';
  }
  else if (uVar5 == 0x18000000) {
    sVar3 = _strlen(param_4);
    (param_4 + sVar3)[0] = 'w';
    (param_4 + sVar3)[1] = '\0';
  }
  sVar3 = _strlen(param_4);
  (param_4 + sVar3)[0] = ',';
  (param_4 + sVar3)[1] = '\0';
  if (uVar6 == 1) {
    param_5[0] = 'v';
    param_5[1] = '\0';
  }
  else if (uVar6 == 0) {
    param_5[0] = 'r';
    param_5[1] = '\0';
  }
  else if (uVar6 == 2) {
    param_5[0] = 'c';
    param_5[1] = '\0';
  }
  else if (uVar6 == 3) {
    param_5[0] = 't';
    param_5[1] = '\0';
  }
  else {
    param_5[0] = '?';
    param_5[1] = '\0';
  }
  FUN_001a32d0(acStack_43,"%d",uVar7 >> 5 & 0xff);
  _strcat(param_5,acStack_43);
  uVar5 = uVar7 & 0x6000000;
  if (((uVar7 & 0x7e000) != 0x10000) || (uVar5 != 0)) {
    uVar6 = 0;
    sVar3 = _strlen(param_5);
    (param_5 + sVar3)[0] = '.';
    (param_5 + sVar3)[1] = '\0';
    uVar4 = 0xd;
    do {
      if (((uVar5 & 0x2000000 << (uVar6 & 0x3f)) != 0) && (uVar5 != 0)) {
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '-';
        (param_5 + sVar3)[1] = '\0';
      }
      switch((uVar7 & 0x7e000 & 7 << (uVar4 & 0x3f)) >> (uVar4 & 0x3f)) {
      case 0:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'x';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 1:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'y';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 2:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'z';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 3:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = 'w';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 4:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '0';
        (param_5 + sVar3)[1] = '\0';
        break;
      case 5:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '1';
        (param_5 + sVar3)[1] = '\0';
        break;
      default:
        sVar3 = _strlen(param_5);
        (param_5 + sVar3)[0] = '?';
        (param_5 + sVar3)[1] = '\0';
      }
      bVar1 = uVar6 != 1;
      uVar4 = uVar4 + 3;
      uVar6 = uVar6 + 1;
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
int FUN_000cfd24(param_1, param_2)
  undefined4 param_1;
  int *param_2;
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
    ((int (*)())FUN_000ce050)(param_1,pcVar3,iVar7,pcVar2,pcVar5,iVar6,iVar4);
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
  ((int (*)())FUN_000ce050)(param_1,"\nNot = %d, op=%s(%d), reg =%d",iVar7,uVar1,uVar8,param_2[3]);
  iVar7 = param_2[4];
  ((int (*)())FUN_000ce050)(param_1," ifinst = %d begInst= %d callinst = %d",iVar7,iVar7,iVar7);
  ((int (*)())FUN_000ce050)(param_1," else=%d, labelinst=%d",param_2[5],param_2[5]);
  iVar4 = param_2[6];
  pcVar2 = " endif= %d , endinst = %d, retinst = %d";
  iVar7 = iVar4;
  iVar6 = iVar4;
LAB_000cfe3c:
  ((int (*)())FUN_000ce050)(param_1,pcVar2,iVar4,iVar7,iVar6);
  return;
}

/* FUN_000cff30 @ 0xcff30 (252 bytes) */
int FUN_000cff30(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  char *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char acStack_98 [120];
  
  *param_3 = '\0';
  iVar1 = *param_1;
  if ((*(int **)(iVar1 + 0x654) == (int *)0x0) || (iVar4 = **(int **)(iVar1 + 0x654), iVar4 < 1)) {
    iVar3 = param_1[1];
  }
  else {
    iVar3 = param_1[1];
    iVar5 = 0;
    while( true ) {
      if (*(int *)(iVar5 * 0x1c + *(int *)(iVar1 + 0x654) + 0x14) + 1 == iVar3) {
        ((int (*)())FUN_000cfd24)(param_1);
        iVar3 = param_1[1];
      }
      iVar5 = iVar5 + 1;
      if (iVar4 == iVar5) break;
      iVar1 = *param_1;
    }
  }
  FUN_001a32d0(acStack_98,"%3d:",iVar3);
  _strcat(param_3,acStack_98);
  param_1[1] = param_1[1] + 1;
  sVar2 = _strlen(param_3);
  ((int (*)())FUN_000cf2ec)(param_1,param_2,param_3 + sVar2,param_4,param_5);
  return;
}

/* FUN_000d002c @ 0xd002c (728 bytes) */
int FUN_000d002c(param_1, param_2)
  int *param_1;
  int param_2;
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
  char acStack_d0 [22];
  undefined1 auStack_ba [22];
  undefined1 auStack_a4 [22];
  char acStack_8e [22];
  char acStack_78 [48];
  
  iVar7 = *(int *)(param_2 + 0x650);
  iVar5 = *(int *)(param_2 + 0x65c);
  *param_1 = param_2;
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  ((int (*)())FUN_000ce050)(param_1,";              VS Disassembly             ");
  ((int (*)())FUN_000ce050)(param_1,";*****************************************");
  if (iVar5 != 0) {
    iVar6 = 0;
    do {
      iVar2 = ((int (*)())FUN_000cff30)(param_1,iVar7,auStack_ba,&local_d8,&local_d4);
      if (iVar2 == 0) {
        if (local_d8 == 0) {
          uVar3 = ((int (*)())FUN_000cea6c)(param_1,iVar7,acStack_78);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_d0);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_8e);
          iVar7 = ((int (*)())FUN_000ce148)(param_1,uVar3,auStack_a4);
          if (local_d4 == 1) {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",auStack_ba,acStack_78,acStack_d0);
          }
          else if (local_d4 == 0) {
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s",auStack_ba,acStack_78);
          }
          else if (local_d4 == 2) {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_d0);
            pcVar1 = acStack_d0 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,acStack_78,acStack_d0,acStack_8e);
          }
          else {
            sVar4 = _strlen(acStack_78);
            pcVar1 = acStack_78 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_d0);
            pcVar1 = acStack_d0 + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            sVar4 = _strlen(acStack_8e);
            pcVar1 = acStack_8e + sVar4;
            pcVar1[0] = ',';
            pcVar1[1] = '\0';
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s%s",auStack_ba,acStack_78,acStack_d0,acStack_8e,
                         auStack_a4);
          }
        }
        else {
          uVar3 = ((int (*)())FUN_000cea6c)(param_1,iVar7,acStack_78);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_d0);
          uVar3 = ((int (*)())FUN_000ce148)(param_1,uVar3,acStack_8e);
          sVar4 = _strlen(acStack_78);
          pcVar1 = acStack_78 + sVar4;
          pcVar1[0] = ',';
          pcVar1[1] = '\0';
          sVar4 = _strlen(acStack_d0);
          pcVar1 = acStack_d0 + sVar4;
          pcVar1[0] = ',';
          pcVar1[1] = '\0';
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,acStack_78,acStack_d0,acStack_8e);
          iVar7 = ((int (*)())FUN_000ced58)(param_1,uVar3,auStack_ba,acStack_78,acStack_d0);
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",auStack_ba,acStack_78,acStack_d0);
        }
      }
      else {
        iVar7 = iVar7 + 0x10;
        ((int (*)())FUN_000ce050)(param_1,"%s",auStack_ba);
      }
      iVar6 = iVar6 + 1;
    } while (iVar5 != iVar6);
  }
  ((int (*)())FUN_000ce050)(param_1,"");
  param_1[1] = 0;
  return 1;
}

/* FUN_000d0304 @ 0xd0304 (84 bytes) */
int FUN_000d0304(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  ((int (*)())FUN_000ce038)(auStack_38);
  local_30 = param_3;
  local_2c = param_1;
  ((int (*)())FUN_000ce88c)(auStack_38,param_2);
  return 0;
}

/* FUN_000d035c @ 0xd035c (84 bytes) */
int FUN_000d035c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined1 auStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  
  ((int (*)())FUN_000ce038)(auStack_38);
  local_30 = param_4;
  local_2c = param_1;
  ((int (*)())FUN_000d002c)(auStack_38,param_2);
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
    FUN_001a34d4(auStack_124,param_2,&STACKARG(0x20));
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",auStack_124,&STACKARG(0x20));
  }
  return;
}

/* FUN_000d0450 @ 0xd0450 (56 bytes) */
int FUN_000d0450(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x8000) != 0) {
    FUN_001a32d0(param_1,"c%02u",param_2 & 0xffff7fff);
    return;
  }
  FUN_001a32d0(param_1,"r%02u",param_2);
  return;
}

/* FUN_000d0488 @ 0xd0488 (604 bytes) */
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
  switch(param_8) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0x17:
  case 0x1a:
    ((int (*)())FUN_000d0450)(local_38,param_2);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x18:
  case 0x1b:
    ((int (*)())FUN_000d0450)(local_38,param_3);
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0x19:
  case 0x1c:
    ((int (*)())FUN_000d0450)(local_38,param_4);
    break;
  case 0xc:
    ((int (*)())FUN_000d0450)(local_38,param_5);
    break;
  case 0xd:
    ((int (*)())FUN_000d0450)(local_38,param_6);
    break;
  case 0xe:
    ((int (*)())FUN_000d0450)(local_38,param_7);
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
    ((int (*)())FUN_000d0450)(local_38,param_5);
    ((int (*)())FUN_000d0450)(auStack_32,param_2);
    break;
  case 0x1e:
    ((int (*)())FUN_000d0450)(local_38,param_6);
    ((int (*)())FUN_000d0450)(auStack_32,param_3);
    break;
  case 0x1f:
    ((int (*)())FUN_000d0450)(local_38,param_7);
    ((int (*)())FUN_000d0450)(auStack_32,param_4);
    break;
  default:
    builtin_strncpy(local_38,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (0x1f < param_8) {
    _strcpy(param_1 + sVar5,local_38);
    sVar5 = _strlen(param_1);
    if (in_stack_00000038 != 0) {
      (param_1 + sVar5)[0] = ')';
      (param_1 + sVar5)[1] = '\0';
    }
    return;
  }
                    
                    
  (*(code *)(((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + param_8 * 4)))();
  return;
}

/* FUN_000d0888 @ 0xd0888 (516 bytes) */
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
  switch(param_8) {
  case 0:
  case 1:
  case 2:
    ((int (*)())FUN_000d0450)(local_28,param_2);
    break;
  case 3:
  case 4:
  case 5:
    ((int (*)())FUN_000d0450)(local_28,param_3);
    break;
  case 6:
  case 7:
  case 8:
    ((int (*)())FUN_000d0450)(local_28,param_4);
    break;
  case 9:
    ((int (*)())FUN_000d0450)(local_28,param_5);
    break;
  case 10:
    ((int (*)())FUN_000d0450)(local_28,param_6);
    break;
  case 0xb:
    ((int (*)())FUN_000d0450)(local_28,param_7);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
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
    break;
  default:
    builtin_strncpy(local_28,"???",4);
  }
  sVar5 = _strlen(param_1);
  if (0xf < param_8) {
    _strcpy(param_1 + sVar5,local_28);
    sVar5 = _strlen(param_1);
    if (in_stack_00000038 != 0) {
      (param_1 + sVar5)[0] = ')';
      (param_1 + sVar5)[1] = '\0';
    }
    return;
  }
                    
                    
  (*(code *)(((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + param_8 * 4)))();
  return;
}

/* FUN_000d0b68 @ 0xd0b68 (1344 bytes) */
int FUN_000d0b68(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  char cVar8;
  char cVar9;
  uint uVar5;
  int iVar6;
  int *piVar7;
  char cVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar14 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar14 != 0)) {
    piVar7 = (int *)(param_1 + 0x90);
    uVar13 = 1;
    do {
      uVar13 = uVar13 + 1;
      if (*piVar7 != 1) goto LAB_000d0bfc;
      piVar7 = piVar7 + 0x12;
    } while (uVar13 <= uVar14);
LAB_000d0bd8:
    bVar12 = 0;
    uVar11 = 0;
    bVar3 = true;
  }
  else {
    uVar13 = 1;
LAB_000d0bfc:
    if (uVar14 < uVar13) goto LAB_000d0bd8;
    bVar12 = 0;
    bVar3 = true;
    puVar19 = (uint *)(param_1 + uVar13 * 0x48);
    uVar18 = 0;
    uVar15 = 0;
    bVar1 = false;
    uVar11 = 0;
    uVar17 = uVar13;
    do {
      uVar4 = *puVar19;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if (uVar4 != 2) goto LAB_000d0c50;
          bVar12 = bVar12 | *(byte *)(puVar19 + 1) | *(byte *)((int)puVar19 + 0x1b);
          if (*(char *)((int)puVar19 + 0x1a) != '\0') {
            uVar11 = uVar11 | -(puVar19[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          bVar12 = bVar12 | *(byte *)(puVar19 + 1);
        }
      }
      else if (uVar4 == 5) {
        bVar12 = bVar12 | *(byte *)(puVar19 + 1);
        if (bVar3) {
          if ((*(char *)((int)puVar19 + 0xe) != '\0') || (*(char *)((int)puVar19 + 0x11) != '\0')) {
            bVar1 = true;
          }
          uVar4 = puVar19[4] & 0xff00ff00;
          if ((uVar4 != 0) &&
             ((*(ushort *)(puVar19 + 3) < uVar15 || (*(char *)((int)puVar19 + 0x19) != '\0')))) {
            bVar1 = true;
          }
          cVar8 = *(char *)(puVar19 + 5);
          cVar9 = *(char *)((int)puVar19 + 0x15);
          cVar10 = cVar8;
          if ((uVar4 != 0) && (cVar10 = cVar9, uVar4 == 0x100ff00)) {
            cVar8 = cVar9;
          }
          cVar9 = cVar10;
          if ((cVar8 == '\x01') || (cVar9 = cVar8, cVar8 != '\0')) {
            if (cVar9 == '\x02') goto LAB_000d0d60;
            if (cVar9 == '\x01') {
              uVar18 = uVar18 - *(byte *)((int)puVar19 + 0x13);
            }
          }
          else if (cVar10 == '\x02') {
LAB_000d0d60:
            uVar18 = uVar18 + 1;
          }
          bVar3 = !bVar1;
          if (4 < uVar18) {
            bVar1 = true;
            bVar3 = false;
          }
        }
      }
      else {
LAB_000d0c50:
        ((int (*)())FUN_000d03b4)(0,"Bad Instruction Type!");
      }
      uVar17 = uVar17 + 1;
      uVar15 = uVar15 + 1;
      puVar19 = puVar19 + 0x12;
    } while (uVar17 <= uVar14);
    if (uVar15 != 0) goto LAB_000d0be8;
  }
  uVar15 = 1;
LAB_000d0be8:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)uVar15 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (uVar13 <= uVar14) {
    bVar1 = bVar12 != 0;
    puVar19 = (uint *)(param_1 + uVar13 * 0x48);
    puVar16 = (undefined1 *)((int)puVar19 + -3);
    uVar15 = 0;
    uVar17 = 100000;
    uVar18 = uVar13;
    do {
      uVar5 = *puVar19;
      uVar4 = uVar17;
      if (uVar5 < 5) {
        if (uVar5 < 3) {
          if (uVar5 == 2) {
            if (uVar11 == 0) {
              *(undefined1 *)((int)puVar19 + 0x1e) = 1;
              *(undefined1 *)((int)puVar19 + 0x1d) = 7;
              puVar19[5] = puVar19[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar19 + 0x1f);
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar19[5] = puVar19[5] >> 2 & 0x300000 | puVar19[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar19[5] = puVar19[5] >> 4 & 0xc0000 | puVar19[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar19[5] = puVar19[5] >> 6 & 0x30000 | puVar19[5] & 0xfffcffff;
              }
            }
            uVar4 = uVar18;
            if (((!bVar1) && (*(char *)(puVar19 + 8) != '\0')) && (uVar17 != 100000)) {
              iVar6 = param_1 + uVar17 * 0x48;
              *(undefined1 *)(iVar6 + 4) = 1;
              *(undefined1 *)(iVar6 + 0x1b) = 1;
              *(undefined1 *)(puVar19 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar19 + 0x15) == '\0') && ((puVar19[8] & 0xff00ff) == 0)) &&
             (uVar15 != *(ushort *)(param_1 + 0x12))) {
            *puVar19 = 4;
          }
          if ((bVar1) || (uVar17 == 100000)) {
LAB_000d1004:
            uVar4 = 100000;
          }
          else {
            iVar6 = param_1 + uVar17 * 0x48;
            *(undefined1 *)(iVar6 + 4) = 1;
            *(undefined1 *)(iVar6 + 0x1b) = 1;
            *(undefined1 *)(puVar19 + 1) = 1;
            uVar4 = 100000;
          }
        }
      }
      else if (uVar5 == 5) {
        if ((!bVar1) && (uVar17 != 100000)) {
          iVar6 = param_1 + uVar17 * 0x48;
          *(undefined1 *)(iVar6 + 4) = 1;
          *(undefined1 *)(iVar6 + 0x1b) = 1;
          *(undefined1 *)(puVar19 + 1) = 1;
        }
        if ((byte)(*(byte *)((int)puVar19 + 0x12) & 0xf0) ==
            (byte)(*(byte *)((int)puVar19 + 0x12) << 4)) goto LAB_000d1004;
        if (uVar15 == 0) {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test is first US instruction");
          uVar4 = 100000;
        }
        else if (*(int *)(puVar16 + -0x45) - 3U < 2) {
          *puVar16 = 1;
          uVar4 = 100000;
        }
        else {
          ((int (*)())FUN_000d03b4)(0,"FC ALU result test follows non-ALU instruction");
          uVar4 = 100000;
        }
      }
      uVar18 = uVar18 + 1;
      uVar15 = uVar15 + 1;
      puVar19 = puVar19 + 0x12;
      puVar16 = puVar16 + 0x48;
      uVar17 = uVar4;
    } while (uVar18 <= uVar14);
    if (((uVar15 != 0) &&
        (iVar6 = (*(ushort *)(param_1 + 0x12) + uVar13) * 0x48, *(int *)(param_1 + iVar6) == 3)) &&
       (bVar12 == 0)) {
      *(undefined1 *)(param_1 + iVar6 + 4) = 1;
    }
  }
  if (((uVar11 != 0) || (bVar12 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
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
int FUN_000d10dc(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  bool bVar1;
  char cVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  ulonglong uVar13;
  char local_98 [10];
  undefined1 local_8e;
  undefined1 local_8d;
  char local_8c;
  char local_8b;
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
  
  uVar13 = FUN_001a3260(param_1,param_2,param_2);
  uVar7 = (undefined4)(uVar13 >> 0x20);
  uVar8 = (uint)uVar13;
  if ((uVar13 & 0x8000) == 0) {
    if ((uVar13 & 0x4000) == 0) {
      if ((uVar13 & 0x2000) == 0) {
        FUN_001a32d0(uVar7,"r%02u");
      }
      else {
        dVar10 = (double)((double (*)())FUN_000da78c)(uVar8 & 0xffffdfff);
        dVar4 = DOUBLE_001aa238;
        dVar3 = DOUBLE_001aa1e0;
        if (dVar10 == (double)FLOAT_001aa0d4) {
          local_98[0] = ' ';
          local_98[2] = 0x2e;
          iVar9 = 7;
          local_98[1] = '0';
          iVar5 = 3;
          do {
            local_98[iVar5] = '0';
            iVar5 = iVar5 + 1;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          local_8d = 0x2b;
          local_8b = '0';
          local_8c = '0';
        }
        else {
          if (dVar10 < (double)FLOAT_001aa0d4) {
            dVar10 = -dVar10;
            local_98[0] = '-';
          }
          else {
            local_98[0] = '+';
          }
          local_50 = (float)dVar10;
          local_88 = 0x43300000;
          uStack_84 = ((uint)local_50 >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,uStack_84) - DOUBLE_001aa1e0);
          dVar11 = (double)_log();
          dVar12 = (double)_log(dVar4);
          dVar11 = (double)_floor(dVar11 / dVar12);
          local_78 = 0x43300000;
          uVar8 = (uint)dVar11;
          local_80 = (longlong)(int)uVar8;
          uStack_74 = uVar8 ^ 0x80000000;
          dVar12 = (double)_pow(dVar4,(double)CONCAT44(0x43300000,uStack_74) - dVar3);
          dVar11 = DOUBLE_001aa298;
          dVar12 = dVar10 / dVar12 + DOUBLE_001aa298;
          if (dVar4 <= dVar12) {
            uVar8 = uVar8 + 1;
            local_70 = 0x43300000;
            uStack_6c = uVar8 ^ 0x80000000;
            dVar12 = (double)_pow(dVar4,(double)CONCAT44(0x43300000,uStack_6c) - dVar3);
            dVar12 = dVar10 / dVar12 + dVar11;
          }
          dVar10 = (double)_floor(dVar12);
          uVar6 = (uint)dVar10;
          local_68 = (longlong)(int)uVar6;
          local_98[2] = 0x2e;
          iVar5 = 3;
          local_98[1] = (char)uVar6 + '0';
          do {
            uStack_5c = uVar6 ^ 0x80000000;
            local_60 = 0x43300000;
            dVar12 = (dVar12 - ((double)CONCAT44(0x43300000,uStack_5c) - dVar3)) * dVar4;
            dVar10 = (double)_floor(dVar12);
            bVar1 = iVar5 != 9;
            uVar6 = (uint)dVar10;
            local_58 = (longlong)(int)uVar6;
            local_98[iVar5] = (char)uVar6 + '0';
            iVar5 = iVar5 + 1;
          } while (bVar1);
          if ((int)uVar8 < 0) {
            uVar8 = -uVar8;
            local_8d = 0x2d;
          }
          else {
            local_8d = 0x2b;
          }
          cVar2 = (char)((int)uVar8 / 10);
          local_8c = cVar2 + '0';
          local_8b = (char)uVar8 + cVar2 * -10 + '0';
        }
        local_8e = 0x45;
        local_8a = 0;
        FUN_001a32d0(param_1,"(%s)",local_98);
      }
    }
    else {
      FUN_001a32d0(uVar7,"r[AL+%02u]",uVar8 & 0xffffbfff);
    }
  }
  else {
    FUN_001a32d0(uVar7,"c%02u",uVar8 & 0xffff7fff);
  }
  return;
}

/* FUN_000d13a4 @ 0xd13a4 (640 bytes) */
int FUN_000d13a4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  ushort uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  size_t sVar7;
  int in_stack_00000038;
  ushort in_stack_0000003e;
  int in_stack_00000040;
  char local_58 [44];
  
  cVar5 = s______001a6f98[4];
  cVar4 = s_nab__001a6f90[4];
  cVar3 = s_abs__001a6f88[4];
  cVar2 = s_neg__001a6f80[4];
  if (in_stack_00000038 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar2;
  }
  else if (in_stack_00000038 == 0) {
    *param_1 = '\0';
  }
  else if (in_stack_00000038 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar3;
  }
  else if (in_stack_00000038 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar4;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar5;
  }
  if (in_stack_00000040 - 0xbU < 2) {
LAB_000d14bc:
    ((int (*)())FUN_000d10dc)(local_58,param_2);
  }
  else {
    iVar6 = ((int (*)())FUN_000d10a8)(in_stack_0000003e);
    if (iVar6 == 0) {
      if (param_8 == 1) {
        ((int (*)())FUN_000d10dc)(local_58,param_3);
        goto LAB_000d1518;
      }
      if (param_8 == 0) goto LAB_000d14bc;
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_58,param_4);
        goto LAB_000d1518;
      }
    }
    else {
      if (param_8 == 1) {
        ((int (*)())FUN_000d10dc)(local_58,param_6);
        goto LAB_000d1518;
      }
      if (param_8 == 0) {
        ((int (*)())FUN_000d10dc)(local_58,param_5);
        goto LAB_000d1518;
      }
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_58,param_7);
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
                 (in_stack_0000003e >> 5 & 0x1c) + 0x1dc259);
  }
  sVar7 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar7)[0] = ')';
    (param_1 + sVar7)[1] = '\0';
  }
  return;
}

/* FUN_000d1624 @ 0xd1624 (536 bytes) */
int FUN_000d1624(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  size_t sVar5;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  char local_38 [40];
  
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
  if (1 < in_stack_00000040 - 0xeU) {
    if (in_stack_0000003c != 3) {
      if (param_8 != 1) {
        if (param_8 == 0) {
          ((int (*)())FUN_000d10dc)(local_38,param_2);
          goto LAB_000d1780;
        }
        param_3 = param_4;
        if (param_8 != 2) goto LAB_000d176c;
      }
      ((int (*)())FUN_000d10dc)(local_38,param_3);
      goto LAB_000d1780;
    }
    if (param_8 == 1) {
      ((int (*)())FUN_000d10dc)(local_38,param_6);
      goto LAB_000d1780;
    }
    if (param_8 != 0) {
      if (param_8 == 2) {
        ((int (*)())FUN_000d10dc)(local_38,param_7);
        goto LAB_000d1780;
      }
LAB_000d176c:
      if (param_8 == 3) {
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
  ((int (*)())FUN_000d10dc)(local_38,param_5);
LAB_000d1780:
  sVar5 = _strlen(param_1);
  if (in_stack_0000003c - 4U < 3) {
    _strcpy(param_1 + sVar5,(char *)(in_stack_0000003c * 4 + 0x1dc259));
  }
  else {
    FUN_001a32d0(param_1 + sVar5,"%s.%s",local_38,in_stack_0000003c * 4 + 0x1dc259);
  }
  sVar5 = _strlen(param_1);
  if (in_stack_00000038 != 0) {
    (param_1 + sVar5)[0] = ')';
    (param_1 + sVar5)[1] = '\0';
  }
  return;
}

/* FUN_000d183c @ 0xd183c (13160 bytes) */
int FUN_000d183c(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  bool bVar17;
  int iVar18;
  char cVar20;
  uint uVar19;
  size_t sVar21;
  int iVar22;
  char *pcVar23;
  char *pcVar24;
  char *pcVar25;
  char *pcVar26;
  bool bVar27;
  bool bVar28;
  bool bVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  int *piVar37;
  uint *puVar38;
  undefined **ppuVar39;
  int *piVar40;
  bool bVar42;
  int *piVar41;
  undefined4 *puVar43;
  int *piVar44;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined1 local_2b8 [4];
  uint local_2b4;
  char local_2b0 [4];
  char local_2ac [2];
  undefined4 local_2aa;
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
  undefined1 auStack_278 [15];
  undefined1 auStack_269 [15];
  undefined1 auStack_25a [15];
  undefined1 auStack_24b [15];
  undefined1 auStack_23c [32];
  undefined1 auStack_21c [32];
  undefined1 auStack_1fc [32];
  undefined1 auStack_1dc [32];
  undefined1 auStack_1bc [32];
  undefined1 auStack_19c [32];
  undefined1 auStack_17c [32];
  char acStack_15c [100];
  int local_f8;
  int local_f4;
  int local_f0;
  uint local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  undefined1 *local_cc;
  uint *local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  undefined2 local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  int local_5c;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  ((int (*)())FUN_000d0b68)(param_1,1);
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) {
    local_a0 = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 uStack00000020);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n");
    }
    else {
      iVar34 = 0;
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n");
      ((int (*)())FUN_000d03b4)(0,"     Levels:                 %2d\n",*(undefined2 *)((int)param_1 + 0x16));
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
      ((int (*)())FUN_000d03b4)(0,"     Nominal cycle count:    %2d\n",*(undefined2 *)((int)param_1 + 0x26));
      ((int (*)())FUN_000d03b4)(0,"     Tex lookup counts:     ");
      puVar43 = param_1;
      do {
        ((int (*)())FUN_000d03b4)(0," %2d",*(undefined1 *)((int)puVar43 + 0x2a));
        bVar2 = iVar34 != 0xf;
        puVar43 = (undefined4 *)((int)puVar43 + 1);
        iVar34 = iVar34 + 1;
      } while (bVar2);
      ((int (*)())FUN_000d03b4)(0,"\n \n");
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n");
    if ((param_1[0x12] == 1) && (local_a0 != 0)) {
      piVar41 = param_1 + 0x24;
      uVar36 = 1;
      piVar37 = piVar41;
      piVar44 = param_1 + 0x12;
      do {
        piVar40 = piVar37;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",uVar36 - 1);
        if (*(char *)((int)piVar44 + 0xb) == '\0') {
          if (*(char *)((int)piVar44 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ");
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())FUN_000d03b4)(0,"\n");
        }
        else {
          ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",*(undefined2 *)((int)piVar44 + 6),
                       (*(byte *)((int)piVar44 + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279,
                       *(undefined1 *)((int)piVar44 + 10));
          if (*(char *)((int)piVar44 + 0xd) == '\0') {
            if (*(char *)((int)piVar44 + 0xb) == '\x02') {
              ((int (*)())FUN_000d03b4)(0," fbuf  ");
            }
            else if (*(char *)((int)piVar44 + 0xb) == '\x03') {
              ((int (*)())FUN_000d03b4)(0," back  ");
            }
            else {
              if (*(char *)((int)piVar44 + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())FUN_000d03b4)(0,"       ");
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0," biased");
          }
LAB_000d3b80:
          if ((*(char *)((int)piVar44 + 9) == '\0') ||
             (((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",*(undefined2 *)(piVar44 + 1),
                           (*(byte *)((int)piVar44 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279,
                           *(undefined1 *)(piVar44 + 2)), *(char *)(piVar44 + 3) == '\0'))
          goto LAB_000d3be0;
          ((int (*)())FUN_000d03b4)(0," adjusted\n");
        }
        uVar36 = uVar36 + 1;
        if (*piVar41 != 1) break;
        piVar41 = piVar41 + 0x12;
        piVar37 = piVar40 + 0x12;
        piVar44 = piVar40;
      } while (uVar36 <= local_a0);
    }
    else {
      uVar36 = 1;
    }
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n");
    if (uVar36 <= local_a0) {
      uVar35 = 0;
      puVar38 = param_1 + uVar36 * 0x12;
      local_a8 = 1;
      local_a4 = 0;
      local_e8 = 0;
      do {
        uVar19 = *puVar38;
        if (((uVar19 == 2) && ((local_a8 != 0 || (*(char *)(puVar38 + 8) != '\0')))) ||
           (uVar35 == 0)) {
          if (uVar35 < 0x34) {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&(local_2b8) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&(local_2b8) + 1)) = (ushort)(byte)((char)(uVar35 / 0x34) + 0x2f) << 8;
          }
          local_2b8[0] = (char)(uVar35 % 0x34);
          if (uVar35 % 0x34 < 0x1a) {
            local_2b8[0] = local_2b8[0] + 'A';
          }
          else {
            local_2b8[0] = local_2b8[0] + 'G';
          }
          ((int (*)())FUN_000d03b4)(0," \n   Level %s:\n",local_2b8);
          uVar35 = uVar35 + 1;
          uVar19 = *puVar38;
        }
        local_a8 = (uint)(uVar19 - 3 < 2);
        if (uVar19 == 2) {
          ((int (*)())FUN_000d03b4)(0,"     tex %02d    :  ",local_e8);
          uVar9 = *(undefined2 *)((int)puVar38 + 0xe);
          uVar4 = *(undefined1 *)((int)puVar38 + 0x19);
          if ((*(byte *)((int)puVar38 + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)puVar38 + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.rgba = ",*(undefined2 *)(puVar38 + 3));
          }
          uVar19 = *(byte *)((int)puVar38 + 0x1f) & 0xf ^ 0xf;
          switch(*(undefined1 *)((int)puVar38 + 0x1a)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"NOP\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"lookup(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"kill(r%02d.%s)\n",uVar9,uVar19 * 5 + 0x1dc279);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"lookup_proj(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",uVar9,uVar19 * 5 + 0x1dc279,uVar4);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()\n");
          }
          local_e8 = local_e8 + 1;
        }
        else if ((1 < uVar19) && (uVar19 < 5)) {
          local_cc = (undefined1 *)((int)puVar38 + 0x31);
          switch(*(undefined1 *)((int)puVar38 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = true;
            bVar28 = true;
            break;
          case 1:
          case 4:
          case 5:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = true;
            bVar28 = false;
            break;
          case 2:
            bVar1 = true;
            bVar2 = true;
            bVar42 = true;
            bVar29 = true;
            bVar28 = false;
            break;
          default:
            bVar1 = false;
            bVar2 = false;
            bVar42 = false;
            bVar29 = false;
            bVar28 = false;
            break;
          case 9:
            bVar1 = false;
            bVar2 = false;
            bVar42 = true;
            bVar29 = false;
            bVar28 = false;
          }
          bVar17 = false;
          local_c8 = puVar38 + 0x10;
          if (*(byte *)(puVar38 + 0x10) < 0xc) {
            uVar19 = 1 << ((int)(char)*(byte *)(puVar38 + 0x10) & 0x3fU);
            if ((uVar19 & 0x61) == 0) {
              if ((uVar19 & 0xc) == 0) {
                if ((uVar19 & 0xf80) != 0) {
                  bVar17 = false;
                  bVar2 = true;
                }
              }
              else {
                bVar17 = false;
                bVar1 = true;
                bVar2 = true;
              }
            }
            else {
              bVar17 = true;
              bVar1 = true;
              bVar2 = true;
            }
          }
          local_ac = (uint)*(byte *)((int)puVar38 + 0x3b);
          uVar9 = *(undefined2 *)((int)puVar38 + 0xe);
          uVar10 = *(undefined2 *)(puVar38 + 4);
          uVar11 = *(undefined2 *)((int)puVar38 + 0x12);
          uVar12 = *(undefined2 *)((int)puVar38 + 0x1a);
          uVar13 = *(undefined2 *)(puVar38 + 7);
          uVar14 = *(undefined2 *)((int)puVar38 + 0x1e);
          uVar33 = (uint)*(byte *)((int)puVar38 + 0x2a);
          uVar32 = (uint)*(byte *)((int)puVar38 + 0x2b);
          uVar31 = (uint)*(byte *)(puVar38 + 0xb);
          uVar30 = (uint)*(byte *)((int)puVar38 + 0x39);
          uVar19 = (uint)*(byte *)((int)puVar38 + 0x3a);
          local_b0 = (uint)*(byte *)((int)puVar38 + 0x2d);
          local_b4 = (uint)*(byte *)((int)puVar38 + 0x2e);
          local_b8 = (uint)*(byte *)((int)puVar38 + 0x2f);
          local_bc = (uint)*(byte *)(puVar38 + 0xf);
          local_c0 = (uint)*(byte *)((int)puVar38 + 0x3d);
          local_c4 = (uint)*(byte *)((int)puVar38 + 0x3e);
          bVar27 = bVar42 && uVar33 - 0xf < 4;
          bVar42 = bVar42 && uVar33 == 0x13;
          if (bVar29) {
            bVar27 = bVar27 || uVar32 - 0xf < 4;
            bVar42 = bVar42 || uVar32 == 0x13;
          }
          if (bVar28) {
            bVar27 = (bool)(bVar27 | uVar31 - 0xf < 4);
            bVar42 = (bool)(bVar42 | uVar31 == 0x13);
          }
          if (bVar2) {
            bVar27 = (bool)(bVar27 | uVar30 - 0xc < 3);
            bVar42 = (bool)(bVar42 | uVar30 == 0xf);
          }
          if (bVar1) {
            bVar27 = (bool)(bVar27 | uVar19 - 0xc < 3);
            bVar42 = (bool)(bVar42 | uVar19 == 0xf);
          }
          if (bVar17) {
            bVar27 = (bool)(bVar27 | local_ac - 0xc < 3);
            bVar42 = (bool)(bVar42 | local_ac == 0xf);
          }
          if (bVar27) {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.rgb = ",local_a4);
            cVar20 = *(char *)(puVar38 + 0xc);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2aa);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2aa);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          if (bVar42) {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.a   = ",local_a4);
            cVar20 = *(char *)((int)puVar38 + 0x3f);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2aa);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d0450)(&local_2a0,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2a0,&local_2aa);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d0450)(&local_2aa,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2aa);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          ((int (*)())FUN_000d03b4)(0,"     alu %02d rgb:  ",local_a4);
          bVar3 = *(byte *)(puVar38 + 5);
          if (*(byte *)((int)puVar38 + 0x15) == 0) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",*(undefined1 *)((int)puVar38 + 0x16),
                         (uint)*(byte *)((int)puVar38 + 0x15) * 4 + 0x1dc239);
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",*(undefined2 *)(puVar38 + 3),(uint)bVar3 * 4 + 0x1dc239);
          }
          if (*(char *)((int)puVar38 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          local_68 = auStack_1fc;
          local_64 = auStack_1dc;
          ((int (*)())FUN_000d0488)(local_68,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar33);
          local_60 = auStack_1bc;
          ((int (*)())FUN_000d0488)(local_64,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar32);
          ((int (*)())FUN_000d0488)(local_60,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar31);
          ((int (*)())FUN_000d0888)(auStack_19c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar30);
          ((int (*)())FUN_000d0888)(auStack_17c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,uVar19);
          ((int (*)())FUN_000d0888)(auStack_23c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_ac);
          switch(*local_cc) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",local_68,local_64);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",local_68,auStack_19c,local_64,auStack_17c);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_68,local_64);
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_68,local_64);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_68,local_64,local_60);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_68);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"sop()");
          }
          switch(*(undefined1 *)((int)puVar38 + 0x32)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2\n");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4\n");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8\n");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2\n");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4\n");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8\n");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???\n");
          }
          ((int (*)())FUN_000d03b4)(0,"          alpha:  ",local_a4);
          cVar20 = *(char *)(puVar38 + 8);
          bVar2 = *(char *)((int)puVar38 + 0x21) != '\0';
          cVar6 = *(char *)((int)puVar38 + 0x23);
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",*(undefined1 *)((int)puVar38 + 0x22));
          }
          bVar1 = cVar6 != '\0';
          if (bVar1) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ");
          }
          if ((!bVar2) && (!bVar1)) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          if (cVar20 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",*(undefined2 *)(puVar38 + 6));
          }
          if (*(char *)((int)puVar38 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          switch(*(undefined1 *)local_c8) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp()");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",auStack_19c,auStack_17c);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",auStack_19c,auStack_17c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",auStack_19c,auStack_17c,auStack_23c);
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",auStack_19c);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"ex2(%s)",auStack_19c);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"ln2(%s)",auStack_19c);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"rcp(%s)",auStack_19c);
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"rsq(%s)",auStack_19c);
          }
          switch(*(undefined1 *)((int)puVar38 + 0x41)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"\n");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2\n");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4\n");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8\n");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2\n");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4\n");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8\n");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???\n");
          }
          if (*(char *)(puVar38 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d post-NOP\n",local_a4);
          }
          local_a4 = local_a4 + 1;
        }
        uVar36 = uVar36 + 1;
        puVar38 = puVar38 + 0x12;
      } while (uVar36 <= local_a0);
    }
    uVar35 = 0;
    ((int (*)())FUN_000d03b4)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 uStack00000020);
    uVar36 = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",uStack0000001c,uStack00000020
                );
    do {
      switch(*param_1) {
      case 0:
        ((int (*)())FUN_000d03b4)(0,
                     "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                     ,param_1[1],param_1[2],*(undefined1 *)(param_1 + 3),
                     *(undefined1 *)((int)param_1 + 0xd),*(undefined2 *)(param_1 + 5),
                     *(undefined2 *)((int)param_1 + 0x16));
        break;
      case 1:
        ((int (*)())FUN_000d03b4)(0,
                     "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined2 *)(param_1 + 1),*(undefined2 *)((int)param_1 + 6),
                     *(undefined1 *)(param_1 + 2),*(undefined1 *)((int)param_1 + 9),
                     *(undefined1 *)((int)param_1 + 10),*(undefined1 *)((int)param_1 + 0xb));
        break;
      case 2:
        ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 3),*(undefined2 *)((int)param_1 + 0xe),
                     *(undefined1 *)((int)param_1 + 0x19),*(undefined1 *)((int)param_1 + 0x1a),
                     *(undefined1 *)((int)param_1 + 0x1f),*(undefined1 *)(param_1 + 8));
        break;
      case 3:
      case 4:
        ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_ALU    : \n");
        ((int (*)())FUN_000d03b4)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 3),*(undefined2 *)((int)param_1 + 0xe),
                     *(undefined2 *)(param_1 + 4),*(undefined2 *)((int)param_1 + 0x12),
                     *(undefined1 *)(param_1 + 5),*(undefined1 *)((int)param_1 + 0x15));
        ((int (*)())FUN_000d03b4)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                     *(undefined2 *)(param_1 + 6),*(undefined2 *)((int)param_1 + 0x1a),
                     *(undefined2 *)(param_1 + 7),*(undefined2 *)((int)param_1 + 0x1e),
                     *(undefined1 *)(param_1 + 8),*(undefined1 *)((int)param_1 + 0x21));
        ((int (*)())FUN_000d03b4)(0,
                     "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined1 *)((int)param_1 + 0x2a),*(undefined1 *)((int)param_1 + 0x2d),
                     *(undefined1 *)((int)param_1 + 0x2b),*(undefined1 *)((int)param_1 + 0x2e),
                     *(undefined1 *)(param_1 + 0xb),*(undefined1 *)((int)param_1 + 0x2f));
        ((int (*)())FUN_000d03b4)(0,
                     "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                     ,*(undefined1 *)((int)param_1 + 0x39),*(undefined1 *)(param_1 + 0xf),
                     *(undefined1 *)((int)param_1 + 0x3a),*(undefined1 *)((int)param_1 + 0x3d),
                     *(undefined1 *)((int)param_1 + 0x3b),*(undefined1 *)((int)param_1 + 0x3e));
      }
      uVar35 = uVar35 + 1;
      param_1 = param_1 + 0x12;
    } while (uVar35 <= uVar36);
    ((int (*)())FUN_000d03b4)(0,"+++ END_PSN                         # \"%s\" %d\n",uStack0000001c,uStack00000020
                );
  }
  else {
    local_7c = param_1[2];
    ((int (*)())FUN_000d03b4)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 uStack00000020);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n");
    }
    else {
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n");
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",*(undefined2 *)(param_1 + 6));
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",*(undefined2 *)((int)param_1 + 0x1a));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",*(undefined2 *)(param_1 + 7));
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",*(undefined2 *)((int)param_1 + 0x1e));
      if (*(char *)((int)param_1 + 0xe) != '\0') {
        ((int (*)())FUN_000d03b4)(0,"     UMRT_EN:               %3d\n");
      }
      ((int (*)())FUN_000d03b4)(0,"     CF Instructions:       %3d\n",*(undefined2 *)(param_1 + 8));
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",*(undefined2 *)((int)param_1 + 0x22));
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",*(undefined2 *)(param_1 + 9));
      ((int (*)())FUN_000d03b4)(0,"     Start Addr:            %3d\n",*(undefined2 *)(param_1 + 4));
      ((int (*)())FUN_000d03b4)(0,"     End Addr:              %3d\n",*(undefined2 *)((int)param_1 + 0x12));
      ((int (*)())FUN_000d03b4)(0," \n");
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n");
    if ((param_1[0x12] == 1) && (0 < local_7c)) {
      piVar41 = param_1 + 0x24;
      iVar34 = 1;
      piVar37 = piVar41;
      piVar44 = param_1 + 0x12;
      do {
        piVar40 = piVar37;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",iVar34 + -1);
        cVar20 = *(char *)((int)piVar44 + 0xb);
        if (cVar20 == '\0') {
          if (*(char *)((int)piVar44 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ");
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())FUN_000d03b4)(0,"\n");
        }
        else {
          uVar36 = *(byte *)((int)piVar44 + 0xf) & 0xf ^ 0xf;
          if (cVar20 == '\x01') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279,*(undefined1 *)((int)piVar44 + 10));
            if (*(char *)((int)piVar44 + 0xd) == '\0') {
              cVar20 = *(char *)((int)piVar44 + 0xb);
            }
            else {
              ((int (*)())FUN_000d03b4)(0," biased");
              cVar20 = *(char *)((int)piVar44 + 0xb);
            }
          }
          if (cVar20 == '\x02') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = fbuf",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279);
          }
          else if (cVar20 == '\x03') {
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = back",*(undefined2 *)((int)piVar44 + 6),
                         uVar36 * 5 + 0x1dc279);
          }
          else {
            if (*(char *)((int)piVar44 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())FUN_000d03b4)(0,"       ");
          }
LAB_000d1afc:
          if ((*(char *)((int)piVar44 + 9) == '\0') ||
             (((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",*(undefined2 *)(piVar44 + 1),
                           (*(byte *)((int)piVar44 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279,
                           *(undefined1 *)(piVar44 + 2)), *(char *)(piVar44 + 3) == '\0'))
          goto LAB_000d1b5c;
          ((int (*)())FUN_000d03b4)(0," adjusted\n");
        }
        iVar34 = iVar34 + 1;
        if (*piVar41 != 1) break;
        piVar41 = piVar41 + 0x12;
        piVar37 = piVar40 + 0x12;
        piVar44 = piVar40;
      } while (iVar34 <= local_7c);
    }
    else {
      iVar34 = 1;
    }
    local_5c = 0x1a1848;
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n");
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00);
    if (iVar34 <= local_7c) {
      local_78 = 0;
      piVar37 = param_1 + iVar34 * 0x12;
      local_70 = 0;
      local_f0 = 0;
      local_f4 = 0;
      local_f8 = 0;
      local_74 = 0;
      local_ec = 0;
      do {
        if (*(char *)(piVar37 + 7) == '\0') {
          local_282 = local_282 & 0xffffff;
        }
        else {
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
        if (*(char *)(piVar37 + 1) == '\0') {
          local_2b4 = local_2b4 & 0xffffff;
        }
        else {
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
        if (*(char *)((int)piVar37 + 0xb) == '\0') {
          local_28c = local_28c & 0xffffff;
        }
        else {
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
        iVar18 = *piVar37;
        if (iVar18 == 2) {
          ((int (*)())FUN_000d03b4)(0,"  %d tex %02d    :  ",local_70,local_f4);
          bVar3 = *(byte *)((int)piVar37 + 0x1d);
          uVar8 = *(ushort *)((int)piVar37 + 0xe);
          uVar9 = *(undefined2 *)(piVar37 + 3);
          uVar4 = *(undefined1 *)((int)piVar37 + 0x19);
          bVar2 = (bVar3 & 1) != 0;
          bVar5 = *(byte *)(piVar37 + 5);
          if (bVar2) {
            pcVar23 = (char *)((bVar5 >> 4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar23 = "_";
          }
          bVar1 = (bVar3 & 2) != 0;
          if (bVar1) {
            pcVar24 = (char *)((bVar5 >> 2 & 0xc) + 0x1dc259);
          }
          else {
            pcVar24 = "_";
          }
          bVar42 = (bVar3 & 4) != 0;
          if (bVar42) {
            pcVar25 = (char *)((bVar5 & 0xc) + 0x1dc259);
          }
          else {
            pcVar25 = "_";
          }
          bVar28 = (((*(byte *)((int)piVar37 + 0x1e) & 0x1f) << 3 | (uint)bVar3) >> 3 & 1) != 0;
          if (bVar28) {
            pcVar26 = (char *)((bVar5 & 3) * 4 + 0x1dc259);
          }
          else {
            pcVar26 = "_";
          }
          FUN_001a32d0(auStack_25a,"%s%s%s%s",pcVar23,pcVar24,pcVar25,pcVar26);
          if ((*(byte *)((int)piVar37 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)piVar37 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",uVar9,auStack_25a);
          }
          if (*(char *)((int)piVar37 + 0x1a) == '\x02') {
            bVar3 = *(byte *)((int)piVar37 + 0x15);
            if (bVar2) {
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
            }
            if (bVar1) {
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
            }
            else {
              pcVar23 = "-";
            }
            if (bVar42) {
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar24 = "-";
            }
            if (bVar28) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
            }
            else {
              pcVar25 = "-";
            }
          }
          else {
            local_78 = (uint)*(byte *)((int)piVar37 + 0x1f);
            bVar3 = *(byte *)((int)piVar37 + 0x15);
            if ((*(byte *)((int)piVar37 + 0x1f) & 1) == 0) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
          }
          FUN_001a32d0(auStack_24b,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
          if ((uVar8 & 0x4000) == 0) {
            FUN_001a32d0(auStack_278,"r%02d",uVar8);
          }
          else {
            FUN_001a32d0(auStack_278,"r[AL+%02d]");
          }
          if (*(char *)((int)piVar37 + 0x1b) == '\0') {
            local_296 = local_296 & 0xffffff;
          }
          else {
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
          switch(*(char *)((int)piVar37 + 0x1a)) {
          case '\0':
            ((int (*)())FUN_000d03b4)(0,"NOP\n");
            break;
          case '\x01':
            ((int (*)())FUN_000d03b4)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,&local_2b4
                         ,&local_296,&local_28c);
            break;
          case '\x02':
            ((int (*)())FUN_000d03b4)(0,"kill(%s.%s)%s%s%s",auStack_278,auStack_24b,&local_2b4,&local_296,
                         &local_28c);
            break;
          case '\x03':
            ((int (*)())FUN_000d03b4)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x04':
            ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x05':
            ((int (*)())FUN_000d03b4)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          case '\x06':
            bVar3 = *(byte *)((int)piVar37 + 0x16);
            bVar2 = (local_78 & 1) == 0;
            if (bVar2) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
            FUN_001a32d0(auStack_269,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
            bVar3 = *(byte *)((int)piVar37 + 0x16);
            uVar9 = *(undefined2 *)(piVar37 + 4);
            if (bVar2) {
              pcVar25 = (char *)((bVar3 & 3) * 4 + 0x1dc259);
              pcVar26 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              pcVar23 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar24 = (char *)((bVar3 & 0xc) + 0x1dc259);
            }
            else {
              pcVar26 = "-";
              pcVar23 = pcVar26;
              pcVar24 = pcVar26;
              pcVar25 = pcVar26;
            }
            FUN_001a32d0(auStack_23c,"%s%s%s%s",pcVar26,pcVar23,pcVar24,pcVar25);
            ((int (*)())FUN_000d03b4)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",auStack_278,
                         auStack_24b,uVar9,auStack_269,*(undefined2 *)((int)piVar37 + 0x12),
                         auStack_23c);
            break;
          case '\a':
            ((int (*)())FUN_000d03b4)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",auStack_278,auStack_24b,uVar4,
                         &local_2b4,&local_296,&local_28c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"UNKNOWN_OP%s%s%s%s",&local_2b4,&local_296,&local_28c,&local_282);
          }
          if (*(char *)((int)piVar37 + 5) != '\0') {
            if (*(char *)((int)piVar37 + 6) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 5)) {
            case 1:
              ((int (*)())FUN_000d03b4)(0," %s.rgb",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.rrr",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.ggg",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.bbb",local_2b8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.aaa",local_2b8);
            }
          }
          if (*(char *)((int)piVar37 + 7) != '\0') {
            if (*(char *)(piVar37 + 2) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 7)) {
            case 1:
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.a",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.r",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.g",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.b",local_2b8);
            }
          }
          if (*(char *)((int)piVar37 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0," write_inactive");
          }
          ((int (*)())FUN_000d03b4)(0,"\n");
          iVar18 = *piVar37;
          local_f4 = local_f4 + 1;
        }
        if ((iVar18 == 3) || (iVar18 == 4)) {
          local_74 = (uint)*(byte *)((int)piVar37 + 0x43);
          local_ec = (uint)*(byte *)(piVar37 + 0x11);
          switch(*(undefined1 *)((int)piVar37 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar2 = true;
            bVar42 = true;
            bVar1 = true;
            local_98 = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            bVar2 = true;
            bVar42 = true;
            bVar1 = false;
            local_98 = 0;
            break;
          case 2:
            bVar2 = true;
            local_98 = 3;
            bVar42 = true;
            bVar1 = false;
            break;
          default:
            bVar2 = false;
            bVar42 = false;
            bVar1 = false;
            local_98 = 0;
            break;
          case 9:
            bVar2 = true;
            bVar42 = false;
            bVar1 = false;
            local_98 = 0;
          }
          if (*(byte *)(piVar37 + 0x10) < 0x10) {
            uVar36 = 1 << ((int)(char)*(byte *)(piVar37 + 0x10) & 0x3fU);
            if ((uVar36 & 0x61) == 0) {
              if ((uVar36 & 0xc00c) == 0) {
                if ((uVar36 & 0x3f80) != 0) {
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
          local_e4 = *(byte *)((int)piVar37 + 0x2a) & 0xffffff7f;
          local_e0 = *(byte *)((int)piVar37 + 0x2b) & 0xffffff7f;
          local_dc = *(byte *)(piVar37 + 0xb) & 0xffffff7f;
          local_d8 = *(byte *)((int)piVar37 + 0x39) & 0xffffff7f;
          local_d4 = *(byte *)((int)piVar37 + 0x3a) & 0xffffff7f;
          local_d0 = *(byte *)((int)piVar37 + 0x3b) & 0xffffff7f;
          local_6c = *(undefined2 *)(piVar37 + 10);
          uVar9 = *(undefined2 *)((int)piVar37 + 0xe);
          uVar10 = *(undefined2 *)(piVar37 + 4);
          uVar11 = *(undefined2 *)((int)piVar37 + 0x12);
          uVar12 = *(undefined2 *)((int)piVar37 + 0x1a);
          uVar13 = *(undefined2 *)(piVar37 + 7);
          uVar14 = *(undefined2 *)((int)piVar37 + 0x1e);
          uVar15 = *(undefined2 *)(piVar37 + 9);
          uVar16 = *(undefined2 *)((int)piVar37 + 0x26);
          local_9c = (uint)*(byte *)(piVar37 + 0xe);
          cVar20 = *(char *)((int)piVar37 + 0x36);
          cVar6 = *(char *)((int)piVar37 + 0x37);
          local_80 = (uint)*(byte *)((int)piVar37 + 0x2d);
          local_84 = (uint)*(byte *)((int)piVar37 + 0x2e);
          local_88 = (uint)*(byte *)((int)piVar37 + 0x2f);
          local_8c = (uint)*(byte *)(piVar37 + 0xf);
          local_90 = (uint)*(byte *)((int)piVar37 + 0x3d);
          local_94 = (uint)*(byte *)((int)piVar37 + 0x3e);
          if (bVar2) {
            bVar2 = local_e4 != 3;
            if (bVar2) {
LAB_000d2654:
              bVar28 = false;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar15);
              bVar28 = true;
              if (iVar18 != 0) goto LAB_000d2654;
            }
            if (!bVar2) {
              bVar2 = true;
              iVar18 = ((int (*)())FUN_000d10a8)(uVar15);
              if (iVar18 != 0) goto LAB_000d2674;
            }
            bVar2 = false;
          }
          else {
            bVar2 = false;
            bVar28 = false;
          }
LAB_000d2674:
          if (bVar42) {
            bVar42 = local_e0 != 3;
            if (bVar42) {
LAB_000d269c:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar16);
              bVar3 = 1;
              if (iVar18 != 0) goto LAB_000d269c;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if (bVar42) {
LAB_000d26bc:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(uVar16);
              bVar3 = 1;
              if (iVar18 == 0) goto LAB_000d26bc;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if (bVar1) {
            bVar1 = local_dc != 3;
            if (bVar1) {
LAB_000d26ec:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(local_6c);
              bVar3 = 1;
              if (iVar18 != 0) goto LAB_000d26ec;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if (bVar1) {
LAB_000d270c:
              bVar3 = 0;
            }
            else {
              iVar18 = ((int (*)())FUN_000d10a8)(local_6c);
              bVar3 = 1;
              if (iVar18 == 0) goto LAB_000d270c;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 1) != 0) {
            if ((local_d8 != 3) || (bVar3 = 1, cVar20 == '\x03')) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d8 != 3) || (bVar3 = 1, cVar20 != '\x03')) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 2) != 0) {
            if ((local_d4 != 3) || (bVar3 = 1, cVar6 == '\x03')) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d4 != 3) || (bVar3 = 1, cVar6 != '\x03')) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if ((local_98 & 4) != 0) {
            if ((local_d0 != 3) || (bVar3 = 1, local_9c == 3)) {
              bVar3 = 0;
            }
            bVar28 = (bool)(bVar28 | bVar3);
            if ((local_d0 != 3) || (bVar3 = 1, local_9c != 3)) {
              bVar3 = 0;
            }
            bVar2 = (bool)(bVar2 | bVar3);
          }
          if (bVar28) {
            ((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.rgb = ",local_70,local_f0);
            cVar20 = *(char *)(piVar37 + 0xc);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&local_2a0);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar10);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar9);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&local_2a0);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.a   = ",local_70,local_f0);
            cVar20 = *(char *)((int)piVar37 + 0x3f);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&local_2a0);
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d10dc)(&local_2aa,uVar13);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&local_2aa,&local_2a0);
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d10dc)(&local_2a0,uVar12);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&local_2a0);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n");
            }
          }
          ((int (*)())FUN_000d03b4)(0,"  %d alu %02d rgb:  ",local_70,local_f0);
          uVar36 = (uint)*(byte *)((int)piVar37 + 0x15);
          bVar3 = *(byte *)(piVar37 + 5);
          if (uVar36 == 0) {
LAB_000d2b24:
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          else if (*piVar37 == 3) {
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",*(undefined1 *)((int)piVar37 + 0x16),uVar36 * 4 + 0x1dc239)
            ;
          }
          else {
            if (*piVar37 != 4) goto LAB_000d2b24;
            ((int (*)())FUN_000d03b4)(0,"pred.%s = ",uVar36 * 4 + 0x1dc239);
            cVar20 = *(char *)((int)piVar37 + 0x16);
            if (cVar20 == '\x01') {
              ((int (*)())FUN_000d03b4)(0,"(<) ");
            }
            else if (cVar20 == '\0') {
              ((int (*)())FUN_000d03b4)(0,"(==) ");
            }
            else if (cVar20 == '\x02') {
              ((int (*)())FUN_000d03b4)(0,"(>=) ");
            }
            else if (cVar20 == '\x03') {
              ((int (*)())FUN_000d03b4)(0,"(!=) ");
            }
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",*(undefined2 *)(piVar37 + 3),(uint)bVar3 * 4 + 0x1dc239);
          }
          if (*(char *)((int)piVar37 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          ((int (*)())FUN_000d13a4)(auStack_21c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_e4);
          ((int (*)())FUN_000d13a4)(auStack_17c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_e0);
          ((int (*)())FUN_000d13a4)(auStack_19c,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_dc);
          local_60 = auStack_1bc;
          ((int (*)())FUN_000d1624)(local_60,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d8);
          local_64 = auStack_1dc;
          ((int (*)())FUN_000d1624)(local_64,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d4);
          local_68 = auStack_1fc;
          ((int (*)())FUN_000d1624)(local_68,uVar9,uVar10,uVar11,uVar12,uVar13,uVar14,local_d0);
          switch(*(undefined1 *)((int)piVar37 + 0x31)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",auStack_21c,local_60,auStack_17c,local_64);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",auStack_21c,auStack_17c);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",auStack_21c,auStack_17c,auStack_19c);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",auStack_21c);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"sop()");
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",auStack_21c,auStack_17c);
            break;
          case 0xc:
            ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",auStack_21c,auStack_17c);
          }
          switch(*(undefined1 *)((int)piVar37 + 0x32)) {
          case 0:
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???");
          }
          if (((*(unsigned char *)((unsigned char *)&(local_2b4) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&(local_28c) + 0)) != '\0')) {
            ((int (*)())FUN_000d03b4)(0,"%s%s",&local_2b4,&local_28c);
          }
          if (*(char *)((int)piVar37 + 5) != '\0') {
            if (*(char *)((int)piVar37 + 6) == '\0') {
              (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
            }
            else {
              local_2b8[0] = s__p_001a74dc[0];
              local_2b8[1] = s__p_001a74dc[1];
              local_2b8[2] = s__p_001a74dc[2];
            }
            switch(*(undefined1 *)((int)piVar37 + 5)) {
            case 1:
              ((int (*)())FUN_000d03b4)(0," %s.rgb",local_2b8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0," %s.rrr",local_2b8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0," %s.ggg",local_2b8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0," %s.bbb",local_2b8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0," %s.aaa",local_2b8);
            }
          }
          ((int (*)())FUN_000d03b4)(0,"\n");
          ((int (*)())FUN_000d03b4)(0,"         alpha:  ",local_f0);
          cVar20 = *(char *)(piVar37 + 8);
          bVar2 = *(char *)((int)piVar37 + 0x21) != '\0';
          cVar6 = *(char *)((int)piVar37 + 0x23);
          if (bVar2) {
            if (*piVar37 == 3) {
              ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",*(undefined1 *)((int)piVar37 + 0x22));
            }
            else if (*piVar37 == 4) {
              ((int (*)())FUN_000d03b4)(0,"pred.a   = ");
              cVar7 = *(char *)((int)piVar37 + 0x22);
              if (cVar7 == '\x01') {
                ((int (*)())FUN_000d03b4)(0,"(<) ");
              }
              else if (cVar7 == '\0') {
                ((int (*)())FUN_000d03b4)(0,"(==) ");
              }
              else if (cVar7 == '\x02') {
                ((int (*)())FUN_000d03b4)(0,"(>=) ");
              }
              else if (cVar7 == '\x03') {
                ((int (*)())FUN_000d03b4)(0,"(!=) ");
              }
            }
          }
          bVar1 = cVar6 != '\0';
          if (bVar1) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ");
          }
          if ((!bVar2) && (!bVar1)) {
            ((int (*)())FUN_000d03b4)(0,"           ");
          }
          if (cVar20 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ");
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",*(undefined2 *)(piVar37 + 6));
          }
          if (*(char *)((int)piVar37 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ");
          }
          switch(*(undefined1 *)(piVar37 + 0x10)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"dp()");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",local_60,local_64);
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",local_60,local_64);
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"???()");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",local_60,local_64,local_68);
            break;
          case 7:
            ((int (*)())FUN_000d03b4)(0,"frc(%s)",local_60);
            break;
          case 8:
            ((int (*)())FUN_000d03b4)(0,"ex2(%s)",local_60);
            break;
          case 9:
            ((int (*)())FUN_000d03b4)(0,"ln2(%s)",local_60);
            break;
          case 10:
            ((int (*)())FUN_000d03b4)(0,"rcp(%s)",local_60);
            break;
          case 0xb:
            ((int (*)())FUN_000d03b4)(0,"rsq(%s)",local_60);
            break;
          case 0xc:
            ((int (*)())FUN_000d03b4)(0,"sin(%s)",local_60);
            break;
          case 0xd:
            ((int (*)())FUN_000d03b4)(0,"cos(%s)",local_60);
            break;
          case 0xe:
            ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",local_60,local_64);
            break;
          case 0xf:
            ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",local_60,local_64);
          }
          switch(*(undefined1 *)((int)piVar37 + 0x41)) {
          case 0:
            ((int (*)())FUN_000d03b4)(0," ");
            break;
          case 1:
            ((int (*)())FUN_000d03b4)(0,"*2");
            break;
          case 2:
            ((int (*)())FUN_000d03b4)(0,"*4");
            break;
          case 3:
            ((int (*)())FUN_000d03b4)(0,"*8");
            break;
          case 4:
            ((int (*)())FUN_000d03b4)(0,"/2");
            break;
          case 5:
            ((int (*)())FUN_000d03b4)(0,"/4");
            break;
          case 6:
            ((int (*)())FUN_000d03b4)(0,"/8");
            break;
          default:
            ((int (*)())FUN_000d03b4)(0,"*???");
          }
          if (*(char *)((int)piVar37 + 10) == '\0') {
            if (*(char *)((int)piVar37 + 7) != '\0') {
              if (*(char *)(piVar37 + 2) == '\0') {
                (*(unsigned short *)((unsigned char *)&(local_2b8) + 0)) = 0x7000;
              }
              else {
                local_2b8[0] = s__p_001a74dc[0];
                local_2b8[1] = s__p_001a74dc[1];
                local_2b8[2] = s__p_001a74dc[2];
              }
              switch(*(undefined1 *)((int)piVar37 + 7)) {
              case 1:
              case 5:
                ((int (*)())FUN_000d03b4)(0," %s.a",local_2b8);
                break;
              case 2:
                ((int (*)())FUN_000d03b4)(0," %s.r",local_2b8);
                break;
              case 3:
                ((int (*)())FUN_000d03b4)(0," %s.g",local_2b8);
                break;
              case 4:
                ((int (*)())FUN_000d03b4)(0," %s.b",local_2b8);
              }
            }
            if (*(char *)((int)piVar37 + 9) != '\0') {
              ((int (*)())FUN_000d03b4)(0," write_inactive");
            }
            ((int (*)())FUN_000d03b4)(0," \n");
          }
          else {
            ((int (*)())FUN_000d03b4)(0," last\n");
          }
          if (*(char *)(piVar37 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"   alu %02d post-NOP\n",local_f0);
          }
          iVar18 = *piVar37;
          local_f0 = local_f0 + 1;
        }
        if (iVar18 == 5) {
          if (local_ec == 1) {
            local_2a0 = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if (local_ec == 0) {
            local_2a0 = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if (local_ec == 2) {
            local_2a0 = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if (local_ec == 3) {
            local_2a0 = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            local_2a0 = CONCAT21(0x2000,uStack_29e);
          }
          if (local_74 == 0) {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = 'r';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = 'e';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 2)) = 'd';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 3)) = '\0';
          }
          else if (local_74 == 1) {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 3)) = s_alpha_001a77e8[3];
            local_2a6[0] = s_alpha_001a77e8[4];
            local_2a6[1] = s_alpha_001a77e8[5];
          }
          else {
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 0)) = ' ';
            (*(unsigned char *)((unsigned char *)&(local_2aa) + 1)) = '\0';
          }
          ((int (*)())FUN_000d03b4)(0,"  %d cf  %02d    :  ",local_70,local_f8);
          FUN_001a32d0(acStack_15c,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       *(undefined1 *)((int)piVar37 + 0x12),*(undefined1 *)(piVar37 + 4),
                       (uint)*(byte *)((int)piVar37 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)piVar37 + 0x11) * 5 + 0x1dc1da,
                       (uint)*(byte *)(piVar37 + 5) * 10 + 0x1dc1bc,
                       (uint)*(byte *)((int)piVar37 + 0x15) * 10 + 0x1dc1bc);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            iVar18 = 0;
          }
          else {
            ppuVar39 = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            iVar18 = 0;
            pcVar23 = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              sVar21 = _strlen(pcVar23);
              iVar22 = _strncmp(pcVar23,acStack_15c,sVar21);
              if (iVar22 == 0) break;
              pcVar23 = *ppuVar39;
              iVar18 = iVar18 + 2;
              ppuVar39 = ppuVar39 + 2;
            } while (pcVar23 != (char *)0x0);
          }
          ((int (*)())FUN_000d03b4)(0,"%s(%s)%s%s",(PTR_s_IF_b_001dc2cc)[iVar18],acStack_15c,&local_2b4,
                       &local_28c);
          cVar20 = *(char *)((int)piVar37 + 0x12);
          if ((cVar20 == -0x10) || (cVar20 == '\x0f')) {
            ((int (*)())FUN_000d03b4)(0,"( prev_alu: %s %s )\n",&local_2aa,&local_2a0);
          }
          else if ((cVar20 == -0x56) || (cVar20 == 'U')) {
            ((int (*)())FUN_000d03b4)(0,"( bool_addr: %d )\n",*(undefined1 *)((int)piVar37 + 0x17));
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"\n");
          }
          local_f8 = local_f8 + 1;
        }
        iVar34 = iVar34 + 1;
        piVar37 = piVar37 + 0x12;
        local_70 = local_70 + 1;
      } while (iVar34 <= local_7c);
    }
    ((int (*)())FUN_000d03b4)(0,local_5c + 0x5b00);
    ((int (*)())FUN_000d03b4)(0,"======== End r520 neutral format pixel shader =============\n");
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

