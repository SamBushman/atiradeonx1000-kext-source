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
  /* issue #64 live-repro (3rd crash, past the earlier two fixes): puVar3 - the value this function
   * actually returns (part_018.c:386) - was only ever assigned as a side effect of this
   * OR-condition's third clause, via the comma operator. C's short-circuit evaluation means that
   * side effect never runs when either of the first two clauses is already true, leaving puVar3
   * uninitialized in that case (it has no earlier assignment anywhere in the function). Live-
   * verified on real hardware via a raw memory watchpoint: with *(param_2+0x22fc)==3 (this
   * function's own case), the returned puVar3 was garbage, corrupting a since-freed heap block's
   * `free_list_t.previous` field the moment the caller wrote through it (FUN_000cae90
   * part_018.c:3651, `*puVar45 = ppppppuVar15;`) - confirmed via Apple's real scalable_malloc.c
   * checksum formula against the live-read corrupted bytes. puVar3 is meant to track the current
   * write pointer (== param_1) at this checkpoint regardless of which clause is true; made the
   * assignment unconditional so the case that skipped it can no longer leave it unset. */
  puVar3 = param_1;
  if (((*(int *)(param_2 + 0x2218) != 0) || (*(int *)(param_2 + 0x2220) != 0)) ||
     (*(int *)(param_2 + 0x2234) == 0)) {
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
  if ((undefined *)(uVar1 & 0x3f0000) == ((unsigned char *)0x00160000U)) {
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
    *(undefined4 *)(0x0000222c + param_3 + 4) = 1;
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
  unsigned int frame_[20] __attribute__((aligned(16)));
  
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
    (*(uint *)((char *)frame_ + 8)) = *puVar4;
    puVar2 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 8)) & 0x400000) != 0) {
      (*(uint *)((char *)frame_ + 20)) = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if (((*(uint *)((char *)frame_ + 8)) & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&(*(uint *)((char *)frame_ + 8)),&(*(uint *)((char *)frame_ + 20)),param_4);
  }
  if (1 < param_3) {
    (*(uint *)((char *)frame_ + 12)) = *puVar4;
    puVar2 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 12)) & 0x400000) != 0) {
      (*(uint *)((char *)frame_ + 24)) = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    puVar4 = puVar2;
    if (((*(uint *)((char *)frame_ + 12)) & 0x1800000) != 0) {
      puVar4 = puVar4 + 1;
    }
    ((int (*)())FUN_000c87d0)(&(*(uint *)((char *)frame_ + 12)),&(*(uint *)((char *)frame_ + 24)),param_4);
  }
  puVar2 = puVar4;
  if (2 < param_3) {
    (*(uint *)((char *)frame_ + 16)) = *puVar4;
    puVar2 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 16)) & 0x400000) != 0) {
      ((uint *)((char *)frame_ + 28))[0] = puVar4[1];
      puVar2 = puVar4 + 2;
    }
    if (((*(uint *)((char *)frame_ + 16)) & 0x1800000) != 0) {
      puVar2 = puVar2 + 1;
    }
    ((int (*)())FUN_000c87d0)(&(*(uint *)((char *)frame_ + 16)),((uint *)((char *)frame_ + 28)),param_4);
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
  unsigned int frame_[24] __attribute__((aligned(16)));
  
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
    (*(uint *)((char *)frame_ + 8)) = *puVar7;
    puVar1 = puVar7 + 1;
    if (((*(uint *)((char *)frame_ + 8)) & 0x400000) != 0) {
      (*(uint *)((char *)frame_ + 20)) = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&(*(uint *)((char *)frame_ + 8)),&(*(uint *)((char *)frame_ + 20)),param_5);
    *puVar4 = (*(uint *)((char *)frame_ + 8));
    puVar1 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 8)) & 0x400000) != 0) {
      puVar4[1] = (*(uint *)((char *)frame_ + 20));
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if (((*(uint *)((char *)frame_ + 8)) & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (1 < param_4) {
    (*(uint *)((char *)frame_ + 12)) = *puVar7;
    puVar1 = puVar7 + 1;
    if (((*(uint *)((char *)frame_ + 12)) & 0x400000) != 0) {
      (*(uint *)((char *)frame_ + 24)) = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&(*(uint *)((char *)frame_ + 12)),&(*(uint *)((char *)frame_ + 24)),param_5);
    *puVar4 = (*(uint *)((char *)frame_ + 12));
    puVar1 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 12)) & 0x400000) != 0) {
      puVar4[1] = (*(uint *)((char *)frame_ + 24));
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if (((*(uint *)((char *)frame_ + 12)) & 0x1800000) != 0) {
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      *puVar4 = uVar2;
      puVar4 = puVar4 + 1;
    }
  }
  if (2 < param_4) {
    (*(uint *)((char *)frame_ + 16)) = *puVar7;
    puVar1 = puVar7 + 1;
    if (((*(uint *)((char *)frame_ + 16)) & 0x400000) != 0) {
      ((uint *)((char *)frame_ + 28))[0] = puVar7[1];
      puVar1 = puVar7 + 2;
    }
    puVar7 = puVar1;
    ((int (*)())FUN_000c8760)(&(*(uint *)((char *)frame_ + 16)),((uint *)((char *)frame_ + 28)),param_5);
    *puVar4 = (*(uint *)((char *)frame_ + 16));
    puVar1 = puVar4 + 1;
    if (((*(uint *)((char *)frame_ + 16)) & 0x400000) != 0) {
      puVar4[1] = ((uint *)((char *)frame_ + 28))[0];
      puVar1 = puVar4 + 2;
    }
    puVar4 = puVar1;
    if (((*(uint *)((char *)frame_ + 16)) & 0x1800000) != 0) {
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
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = _malloc(0x28);
  iVar1 = *param_1;
  *param_1 = iVar2;
  *(int *)(iVar2 + 0x24) = iVar1;
  return _memcpy(iVar2,param_2,0x24);
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
  uint *******pppppppuVar8;
  undefined4 uVar9;
  uint ******ppppppuVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  char *pcVar14;
  uint ******ppppppuVar15;
  undefined4 *puVar16;
  int iVar17;
  uint *******pppppppuVar18;
  uint *puVar19;
  uint *******pppppppuVar20;
  uint uVar21;
  uint uVar22;
  char cVar24;
  uint ******ppppppuVar23;
  uint *******pppppppuVar25;
  uint *puVar26;
  undefined4 *puVar27;
  uint ******ppppppuVar28;
  uint ******unaff_r14;
  uint ******unaff_r15;
  uint *puVar29;
  uint unaff_r20;
  uint *******pppppppuVar30;
  uint unaff_r21;
  uint *puVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  int iVar36;
  undefined1 *puVar37;
  int iVar38;
  int iVar39;
  /* Same undersized-buffer defect as auStack_c148 below (issue #64), same function, a sibling call
   * site: declared 76 bytes but memset to 0xbc=188 (0x2b18-0xbc=0x2a5c, exactly this buffer's own
   * sibling declared right after it - confirming the real size). Enlarged to match. */
  undefined1 auStack_2b18 [0xbc];
  /* Same undersized-buffer defect as auStack_9d1c below (issue #64), same function, a sibling call
   * site: declared 72 bytes but memset to 0x674=1652. Enlarged to match. */
  undefined1 auStack_2a5c [0x674];
  unsigned int frame_[2800] __attribute__((aligned(16)));
  
  iVar38 = 8;
  iVar11 = 0;
  do {
    *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 136)) + iVar11) = 0xffffffff;
    *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 104)) + iVar11) = 0xffffffff;
    iVar11 = iVar11 + 4;
    iVar38 = iVar38 + -1;
  } while (iVar38 != 0);
  pppppppuVar18 = param_3;
  iVar11 = _malloc(0x400);
  uVar21 = *(uint *)(param_1 + 0x44);
  (*(int *)((char *)frame_ + 10664)) = 0;
  if ((uVar21 & 0x2000) == 0) {
    (*(uint *)((char *)frame_ + 10716)) = uVar21 >> 0x18 & 1;
    (*(uint *)((char *)frame_ + 10728)) = 0xffff;
  }
  else {
    (*(uint *)((char *)frame_ + 10716)) = uVar21 >> 0xb & 1;
    if ((*(uint *)((char *)frame_ + 10716)) == 0) {
      (*(uint *)((char *)frame_ + 10728)) = 0xffff;
    }
    else {
      (*(uint *)((char *)frame_ + 10728)) = (uint)(byte)((unsigned char *)0x000011d1)[param_1];
    }
  }
  puVar31 = (uint *)*param_2;
  (*(uint *)((char *)frame_ + 10984)) = uVar21 >> 10 & 1;
  iVar39 = 8;
  (*(undefined4 *)((char *)frame_ + 2012)) = 0xffff;
  (*(uint *)((char *)frame_ + 10988)) = (uint)(byte)((unsigned char *)0x000011d2)[param_1];
  (*(uint *)((char *)frame_ + 11004)) = (uint)(param_2[6] == 0);
  (*(undefined4 *)((char *)frame_ + 2048)) = (*(undefined4 *)((char *)frame_ + 164));
  iVar38 = param_2[1];
  (*(undefined4 *)((char *)frame_ + 2044)) = (*(undefined4 *)((char *)frame_ + 160));
  (*(undefined4 *)((char *)frame_ + 2040)) = (*(undefined4 *)((char *)frame_ + 156));
  (*(uint ******* *)((char *)frame_ + 10764)) = (uint *******)0x0;
  (*(int *)((char *)frame_ + 10964)) = 0;
  (*(undefined4 *)((char *)frame_ + 10996)) = 0;
  (*(undefined4 *)((char *)frame_ + 11076)) = 0;
  (*(undefined4 *)((char *)frame_ + 2036)) = (*(undefined4 *)((char *)frame_ + 152));
  ((undefined4 *)((char *)frame_ + 2020))[3] = ((undefined4 *)((char *)frame_ + 136))[3];
  (*(uint ****** *)((char *)frame_ + 2008)) = (uint ******)0x0;
  (*(int *)((char *)frame_ + 2084)) = 0;
  (*(undefined4 *)((char *)frame_ + 2108)) = 0;
  ((undefined4 *)((char *)frame_ + 2020))[2] = ((undefined4 *)((char *)frame_ + 136))[2];
  ((undefined4 *)((char *)frame_ + 2020))[1] = ((undefined4 *)((char *)frame_ + 136))[1];
  ((undefined4 *)((char *)frame_ + 2020))[0] = ((undefined4 *)((char *)frame_ + 136))[0];
  (*(undefined4 *)((char *)frame_ + 2080)) = (*(undefined4 *)((char *)frame_ + 132));
  (*(uint *)((char *)frame_ + 2384)) = 0;
  (*(undefined4 *)((char *)frame_ + 10760)) = 0;
  (*(uint *)((char *)frame_ + 2016)) = 0;
  (*(uint ******* *)((char *)frame_ + 10656)) = (uint *******)0x0;
  ((int *)((char *)frame_ + 10696))[0] = 0;
  (*(undefined4 *)((char *)frame_ + 2072)) = (*(undefined4 *)((char *)frame_ + 124));
  (*(undefined4 *)((char *)frame_ + 2076)) = (*(undefined4 *)((char *)frame_ + 128));
  ((int *)((char *)frame_ + 10696))[1] = 0;
  ((int *)((char *)frame_ + 10696))[2] = 0;
  ((int *)((char *)frame_ + 10696))[3] = 0;
  (*(int *)((char *)frame_ + 10732)) = 0;
  ((undefined4 *)((char *)frame_ + 2052))[3] = ((undefined4 *)((char *)frame_ + 104))[3];
  (*(undefined4 *)((char *)frame_ + 2068)) = (*(undefined4 *)((char *)frame_ + 120));
  (*(int *)((char *)frame_ + 10736)) = 0;
  (*(int *)((char *)frame_ + 10740)) = 0;
  (*(int *)((char *)frame_ + 10744)) = 0;
  (*(int *)((char *)frame_ + 10724)) = 0;
  ((undefined4 *)((char *)frame_ + 2052))[1] = ((undefined4 *)((char *)frame_ + 104))[1];
  (*(undefined4 *)((char *)frame_ + 10748)) = 0;
  (*(undefined4 *)((char *)frame_ + 10752)) = 0;
  (*(undefined4 *)((char *)frame_ + 10756)) = 0;
  ((undefined4 *)((char *)frame_ + 2052))[2] = ((undefined4 *)((char *)frame_ + 104))[2];
  puVar29 = ((uint *)((char *)frame_ + 2400));
  (*(uint * *)((char *)frame_ + 11092)) = puVar29;
  ((undefined4 *)((char *)frame_ + 2052))[0] = ((undefined4 *)((char *)frame_ + 104))[0];
  do {
    *puVar29 = 0;
    puVar29[0x408] = 0;
    puVar29 = puVar29 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  puVar16 = ((undefined4 *)((char *)frame_ + 10768));
  iVar39 = 0x10;
  do {
    *puVar16 = 0;
    puVar16[0x10] = 0;
    puVar16 = puVar16 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  iVar36 = 0;
  iVar39 = 0;
  uVar21 = 0;
  puVar29 = puVar31;
switchD_000c90cc_caseD_15:
  (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
  puVar26 = (*(uint * *)((char *)frame_ + 12));
switchD_000c90cc_caseD_18:
  puVar29 = puVar26;
  if (puVar29 < puVar31 + iVar38) goto code_r0x000c90a4;
  if ((*(uint ******* *)((char *)frame_ + 10656)) != (uint *******)0x0) {
    puVar29 = (uint *)0x0;
    uVar33 = 0;
    goto LAB_000ca6bc;
  }
  iVar36 = (iVar36 + iVar38) * 4;
  (*(uint ****** *)((char *)frame_ + 2088)) = (*(uint ****** *)((char *)frame_ + 2008));
  if ((*(int *)((char *)frame_ + 2084)) != 0) {
    iVar36 = iVar36 + 0x48;
  }
  uVar33 = iVar36 + iVar39 * 4;
  bVar4 = (*(int *)((char *)frame_ + 10664)) != 0;
  if (bVar4) {
    uVar33 = uVar33 + 0x14;
  }
  uVar32 = uVar33;
  if ((((int *)((char *)frame_ + 10696))[0] != 0) && (uVar32 = uVar33 + 0xc, bVar4)) {
    uVar32 = uVar33 + 0x24;
  }
  uVar33 = uVar32;
  if ((((int *)((char *)frame_ + 10696))[1] != 0) && (uVar33 = uVar32 + 0xc, bVar4)) {
    uVar33 = uVar32 + 0x24;
  }
  uVar32 = uVar33;
  if ((((int *)((char *)frame_ + 10696))[2] != 0) && (uVar32 = uVar33 + 0xc, bVar4)) {
    uVar32 = uVar33 + 0x24;
  }
  uVar22 = uVar32;
  if ((((int *)((char *)frame_ + 10696))[3] != 0) && (uVar22 = uVar32 + 0xc, bVar4)) {
    uVar22 = uVar32 + 0x24;
  }
  if ((((*(int *)((char *)frame_ + 10724)) != 0) && ((*(uint *)((char *)frame_ + 10716)) != 0)) && ((*(uint ******* *)((char *)frame_ + 10764)) == (uint *******)0x0)) {
    uVar22 = uVar22 + 0x14;
  }
  if ((*(int *)((char *)frame_ + 10964)) == 1) {
    uVar22 = uVar22 + 0x24;
  }
  else if ((*(int *)((char *)frame_ + 10964)) == 2) {
    uVar22 = uVar22 + 0x30;
  }
  else if ((*(int *)((char *)frame_ + 10964)) == 3) {
    uVar22 = uVar22 + 0x40;
  }
  else if ((*(int *)((char *)frame_ + 10964)) == 0) goto LAB_000c99d4;
  uVar22 = uVar22 + 8;
  piVar12 = ((int *)((char *)frame_ + 10696));
  iVar39 = 4;
  do {
    if (*piVar12 != 0) {
      uVar22 = uVar22 + 0x2c;
    }
    piVar12 = piVar12 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
LAB_000c99d4:
  if ((((*(int *)((char *)frame_ + 10736)) != 0) || ((*(int *)((char *)frame_ + 10744)) != 0)) || (uVar33 = uVar22, (*(uint ******* *)((char *)frame_ + 10764)) == (uint *******)0x0)) {
    if (((*(int *)((char *)frame_ + 10732)) == 0) && ((*(int *)((char *)frame_ + 10740)) != 0)) {
      uVar22 = uVar22 + 0xc;
    }
    uVar33 = uVar22;
    if (((*(uint ******* *)((char *)frame_ + 10764)) == (uint *******)0x0) && (uVar33 = uVar22 + 0xc, (*(uint *)((char *)frame_ + 10984)) != 0)) {
      uVar33 = uVar22 + 0x18;
    }
  }
  bVar4 = true;
  pppppppuVar20 = (*(uint ******* *)((char *)frame_ + 10764));
  pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 10656));
  puVar29 = (uint *)_malloc(uVar33 + 0x10);
  *puVar29 = *puVar31;
  (*(uint * *)((char *)frame_ + 12)) = puVar31 + 2;
  puVar29[1] = puVar31[1];
  puVar26 = (*(uint * *)((char *)frame_ + 12));
  pppppppuVar30 = (uint *******)(puVar29 + 2);
  goto switchD_000c9ab8_caseD_18;
code_r0x000c90a4:
  pppppppuVar18 = (uint *******)*puVar29;
  puVar26 = puVar29;
  switch((uint)pppppppuVar18 & 0xffff) {
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
    uVar9 = 1;
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
    uVar9 = 1;
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
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 1;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar9 = 0;
LAB_000c9340:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 2);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar9,2,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 3;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 3);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8910)(puVar29,1,3,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + *(ushort *)((int)puVar29 + 6) + 2;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 3;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 1;
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    uVar33 = puVar29[1];
    puVar6 = (undefined *)(uVar33 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,0,0);
    if (puVar6 == ((unsigned char *)0x00160000U)) {
      (*(int *)((char *)frame_ + 2084)) = 1;
    }
    else if (puVar6 == (undefined *)0x110000) {
      (*(uint *)((char *)frame_ + 2016)) = 1 << (uVar33 & 0x3f) | (*(uint *)((char *)frame_ + 2016));
    }
    else if (puVar6 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar33 & 0x3f);
    }
    else if (puVar6 == (undefined *)0x100000) {
      (*(undefined4 *)((char *)frame_ + 2108)) = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    uVar32 = (uint)pppppppuVar18 >> 0x1b & 3;
    uVar33 = (uint)pppppppuVar18 >> 0x10 & 0xff;
    if ((uVar32 == 2) || ((uVar32 == 0 && (((uint *)((char *)frame_ + 10896))[uVar33] == 2)))) {
      (*(uint *)((char *)frame_ + 2384)) = 1 << ((uint)pppppppuVar18 >> 0x10 & 0x3f) | (*(uint *)((char *)frame_ + 2384));
    }
    pppppppuVar18 = (uint *******)((uint)pppppppuVar18 >> 0x18 & 7);
    FUN_000c7270(&(*(uint ****** *)((char *)frame_ + 2008)),uVar33,pppppppuVar18);
    (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 1;
    if ((int)pppppppuVar18 < 0) {
      (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    }
LAB_000c9564:
    (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 1;
    uVar32 = puVar29[1];
    uVar33 = uVar32 >> 0x10 & 0x3f;
    if (uVar33 == 1) {
      pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 88));
      (*(uint ****** *)((char *)frame_ + 88)) = (uint ******)puVar29[2];
      (*(uint *)((char *)frame_ + 92)) = puVar29[3];
      (*(uint *)((char *)frame_ + 96)) = puVar29[4];
      (*(uint * *)((char *)frame_ + 12)) = puVar29 + 6;
      (*(uint *)((char *)frame_ + 100)) = puVar29[5];
      FUN_000c7290(&(*(uint ****** *)((char *)frame_ + 2008)),uVar32 & 0xffff,pppppppuVar18);
      puVar26 = (*(uint * *)((char *)frame_ + 12));
    }
    else {
      puVar26 = (*(uint * *)((char *)frame_ + 12));
      if (uVar33 == 2) {
        pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 88));
        (*(uint ****** *)((char *)frame_ + 88)) = (uint ******)puVar29[2];
        (*(uint *)((char *)frame_ + 92)) = puVar29[3];
        (*(uint *)((char *)frame_ + 96)) = puVar29[4];
        (*(uint * *)((char *)frame_ + 12)) = puVar29 + 6;
        (*(uint *)((char *)frame_ + 100)) = puVar29[5];
        FUN_000c72f0(&(*(uint ****** *)((char *)frame_ + 2008)),uVar32 & 0xffff,pppppppuVar18);
        puVar26 = (*(uint * *)((char *)frame_ + 12));
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 2);
    iVar36 = iVar36 + 5;
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8910)(puVar29,1,2,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    ((uint ****** *)((char *)frame_ + 52))[0] = (uint ******)puVar29[1];
    ((int (*)())FUN_000c87d0)(((uint ****** *)((char *)frame_ + 52)),((undefined1 *)((char *)frame_ + 64)),pppppppuVar18);
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8910)(puVar29,0,1,&(*(uint ****** *)((char *)frame_ + 2008)));
    (*(undefined4 *)((char *)frame_ + 10756)) = 1;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    uVar9 = 0;
    break;
  case 0x5d:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    (*(int *)((char *)frame_ + 11000)) = (*(int *)((char *)frame_ + 11000)) + 1;
    uVar33 = puVar29[1];
    uVar32 = *puVar29;
    if ((((uVar32 & 0xc000000) == 0x4000000) ||
        (((uVar32 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 2124))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 2120)) << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      (*(uint *)((char *)frame_ + 2124)) = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | (*(uint *)((char *)frame_ + 2124));
      uVar32 = *puVar29;
    }
    if ((int)uVar32 < 0) {
      (*(uint * *)((char *)frame_ + 12)) = puVar29 + 3;
      uVar32 = *puVar29;
    }
    if ((uVar32 & 0x40000000) != 0) {
      (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      unaff_r21 = *(*(uint * *)((char *)frame_ + 12));
      (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    }
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,unaff_r21,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 2120))) != 0) {
      iVar39 = iVar39 + 4;
    }
    (*(uint ****** *)((char *)frame_ + 76)) = (uint ******)*(*(uint * *)((char *)frame_ + 12));
    puVar29 = (*(uint * *)((char *)frame_ + 12)) + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 76)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 16)) = (uint ******)(*(uint * *)((char *)frame_ + 12))[1];
      puVar29 = (*(uint * *)((char *)frame_ + 12)) + 2;
    }
    (*(uint * *)((char *)frame_ + 12)) = puVar29;
    ((int (*)())FUN_000c87d0)(&(*(uint ****** *)((char *)frame_ + 76)),&(*(uint ****** *)((char *)frame_ + 16)),pppppppuVar18);
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    (*(int *)((char *)frame_ + 11000)) = (*(int *)((char *)frame_ + 11000)) + 1;
    uVar33 = puVar29[1];
    uVar32 = *puVar29;
    if ((((uVar32 & 0xc000000) == 0x4000000) ||
        (((uVar32 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 2124))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 2120)) << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      (*(uint *)((char *)frame_ + 2124)) = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | (*(uint *)((char *)frame_ + 2124));
      uVar32 = *puVar29;
    }
    if ((int)uVar32 < 0) {
      (*(uint * *)((char *)frame_ + 12)) = puVar29 + 3;
      uVar32 = *puVar29;
    }
    if ((uVar32 & 0x40000000) != 0) {
      (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      unaff_r20 = *(*(uint * *)((char *)frame_ + 12));
      (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    }
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,unaff_r20,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 2120))) != 0) {
      iVar39 = iVar39 + 4;
    }
    (*(uint ****** *)((char *)frame_ + 16)) = (uint ******)*(*(uint * *)((char *)frame_ + 12));
    puVar29 = (*(uint * *)((char *)frame_ + 12)) + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 16)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 28)) = (uint *******)(*(uint * *)((char *)frame_ + 12))[1];
      puVar29 = (*(uint * *)((char *)frame_ + 12)) + 2;
    }
    ((uint *)((char *)frame_ + 20))[0] = *puVar29;
    (*(uint * *)((char *)frame_ + 12)) = puVar29 + 1;
    if ((((uint *)((char *)frame_ + 20))[0] & 0x400000) != 0) {
      ((uint *)((char *)frame_ + 32))[0] = puVar29[1];
      (*(uint * *)((char *)frame_ + 12)) = puVar29 + 2;
    }
    ((int (*)())FUN_000c87d0)(&(*(uint ****** *)((char *)frame_ + 16)),&(*(uint ******* *)((char *)frame_ + 28)),pppppppuVar18);
    ((int (*)())FUN_000c87d0)(((uint *)((char *)frame_ + 20)),((uint *)((char *)frame_ + 32)),pppppppuVar18);
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    goto switchD_000c90cc_caseD_18;
  }
  pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
  (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar9,1,&(*(uint ****** *)((char *)frame_ + 2008)));
  puVar26 = (*(uint * *)((char *)frame_ + 12));
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar30;
  puVar19 = puVar26;
  pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
  if (puVar31 + iVar38 <= puVar19) {
    uVar33 = uVar33 >> 2;
    (*(uint *)((char *)frame_ + 2016)) = uVar21 | (*(uint *)((char *)frame_ + 2016));
LAB_000ca6bc:
    if ((*(uint ******* *)((char *)frame_ + 10656)) != (uint *******)0x0) {
      return (*(uint ******* *)((char *)frame_ + 10656));
    }
    param_3[0x1587] = (uint ******)0x0;
    iVar38 = 0;
    param_3[0x1589] = (uint ******)0x0;
    param_3[0x1502] = (uint ******)0x0;
    pppppppuVar18 = param_3 + 0x1000;
    puVar37 = ((undefined1 *)((char *)frame_ + 2424));
    pppppppuVar20 = param_3 + 0x1004;
    puVar31 = (*(uint * *)((char *)frame_ + 11092));
    do {
      pppppppuVar30 = pppppppuVar20 + 1;
      puVar26 = (uint *)(puVar37 + 8);
      pppppppuVar25 = pppppppuVar18 + 1;
      iVar39 = 0x20;
      uVar21 = 0;
      do {
        if ((1 << (uVar21 & 0x3f) & *puVar31) == 0) {
          *(undefined1 *)pppppppuVar30 = 0;
        }
        else {
          *pppppppuVar25 = (uint ******)*puVar26;
          pppppppuVar25[1] = (uint ******)puVar26[1];
          pppppppuVar25[2] = (uint ******)puVar26[2];
          ppppppuVar10 = (uint ******)puVar26[3];
          *(undefined1 *)(pppppppuVar25 + 4) = 1;
          pppppppuVar25[3] = ppppppuVar10;
          if (param_3[0x1502] < (uint ******)(iVar38 + uVar21)) {
            param_3[0x1502] = (uint ******)(iVar38 + uVar21);
          }
        }
        uVar21 = uVar21 + 1;
        pppppppuVar30 = pppppppuVar30 + 5;
        puVar26 = puVar26 + 4;
        pppppppuVar25 = pppppppuVar25 + 5;
        iVar39 = iVar39 + -1;
      } while (iVar39 != 0);
      bVar4 = iVar38 != 0xe0;
      pppppppuVar20 = pppppppuVar20 + 0xa0;
      puVar37 = puVar37 + 0x200;
      pppppppuVar18 = pppppppuVar18 + 0xa0;
      puVar31 = puVar31 + 1;
      iVar38 = iVar38 + 0x20;
    } while (bVar4);
    if ((int)param_3[0x1587] < (int)param_3[0x1502]) {
      param_3[0x1587] = param_3[0x1502];
    }
    _memset(auStack_2b18,0,0xbc);
    _memset(auStack_2a5c,0,0x674);
    iVar38 = (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x1870));
    (*(int *)((char *)frame_ + 248)) = uVar33 << 2;
    puVar27 = ((undefined4 *)((char *)frame_ + 2020));
    puVar16 = ((undefined4 *)((char *)frame_ + 256));
    iVar39 = 8;
    (*(int *)((char *)frame_ + 352)) = iVar38;
    do {
      uVar9 = *puVar27;
      uVar13 = puVar27[8];
      puVar27 = puVar27 + 1;
      *puVar16 = uVar9;
      puVar16[8] = uVar13;
      puVar16 = puVar16 + 1;
      iVar39 = iVar39 + -1;
    } while (iVar39 != 0);
    (*(undefined4 *)((char *)frame_ + 1968)) = 0x400;
    (*(uint * *)((char *)frame_ + 244)) = puVar29;
    (*(uint * *)((char *)frame_ + 1972)) = (uint *)_malloc(0x40000);
    (*(int * *)((char *)frame_ + 1976)) = (int *)_malloc(0x40000);
    (*(undefined4 *)((char *)frame_ + 432)) = 0x40;
    (*(int *)((char *)frame_ + 456)) = _malloc(0x900);
    (*(undefined4 *)((char *)frame_ + 428)) = 0x40;
    (*(int *)((char *)frame_ + 452)) = _malloc(0x900);
    cVar24 = '\0';
    pcVar14 = ((char *)((char *)frame_ + 621));
    iVar39 = 0x40;
    do {
      *pcVar14 = cVar24;
      pcVar14 = pcVar14 + 0xc;
      cVar24 = cVar24 + '\x01';
      iVar39 = iVar39 + -1;
    } while (iVar39 != 0);
    iVar39 = *(int *)(param_1 + 0x186c);
    if (iVar39 == 0) {
      FUN_000c6ff0(param_1,1);
      iVar39 = *(int *)(param_1 + 0x186c);
    }
    iVar39 = ((int (*)())FUN_000cd1b0)(iVar39,auStack_2b18,auStack_2a5c);
    if (iVar39 != 0) {
      return (uint *******)((int)((unsigned char *)0x0) + 2);
    }
    param_3[0x1000] = (*(uint ****** *)((char *)frame_ + 1984));
    if ((*(uint ****** *)((char *)frame_ + 1984)) != (uint ******)0x0) {
      puVar31 = (*(uint * *)((char *)frame_ + 1972));
      pppppppuVar18 = param_3;
      if ((*(uint ****** *)((char *)frame_ + 1984)) == (uint ******)0x0) {
        (*(uint ****** *)((char *)frame_ + 1984)) = (uint ******)0x1;
      }
      do {
        ppppppuVar10 = (uint ******)*puVar31;
        ppppppuVar15 = (uint ******)puVar31[1];
        ppppppuVar23 = (uint ******)puVar31[2];
        ppppppuVar28 = (uint ******)puVar31[3];
        puVar31 = puVar31 + 4;
        *pppppppuVar18 = ppppppuVar10;
        pppppppuVar18[1] = ppppppuVar15;
        pppppppuVar18[2] = ppppppuVar23;
        pppppppuVar18[3] = ppppppuVar28;
        pppppppuVar18 = pppppppuVar18 + 4;
        (*(uint ****** *)((char *)frame_ + 1984)) = (uint ******)((int)(*(uint ****** *)((char *)frame_ + 1984)) - 1);
      } while ((*(uint ****** *)((char *)frame_ + 1984)) != (uint ******)0x0);
    }
    ppppppuVar10 = param_3[0x1502];
    if (ppppppuVar10 < (*(uint ****** *)((char *)frame_ + 2004))) {
      param_3[0x1502] = (*(uint ****** *)((char *)frame_ + 2004));
      param_3[0x1501] = (uint ******)((int)(*(uint ****** *)((char *)frame_ + 2004)) + 1);
      ppppppuVar10 = (*(uint ****** *)((char *)frame_ + 2004));
    }
    else {
      param_3[0x1501] = (uint ******)((int)ppppppuVar10 + 1);
    }
    if ((uint ******)0xff < ppppppuVar10) {
      param_3[0x1502] = (uint ******)0xff;
    }
    if ((uint ******)0x100 < param_3[0x1501]) {
      param_3[0x1501] = (uint ******)0x100;
    }
    if ((*(uint *)((char *)frame_ + 444)) == 0) goto LAB_000caa4c;
    uVar33 = 0;
    iVar39 = 0;
    uVar21 = (*(uint *)((char *)frame_ + 444));
    do {
      iVar36 = iVar39 + (*(int *)((char *)frame_ + 456));
      if (*(int *)(iVar36 + 8) == 0x16) {
        uVar32 = *(uint *)(iVar36 + 0x10);
        iVar35 = *(int *)(iVar39 + (*(int *)((char *)frame_ + 456)));
        iVar17 = ((int)uVar32 >> 5) + (uint)((int)uVar32 < 0 && (uVar32 & 0x1f) != 0);
        if ((1 << (uVar32 + iVar17 * -0x20 & 0x3f) & ((uint *)((char *)frame_ + 2400))[iVar17]) == 0) goto LAB_000caa2c;
        iVar17 = FUN_000c7240(*(undefined4 *)(iVar36 + 4));
        iVar36 = FUN_000c7240(*(undefined4 *)(iVar36 + 0xc));
        (*(longlong *)((char *)frame_ + 11080)) = (longlong)(int)((float *)((char *)frame_ + 2432))[uVar32 * 4 + iVar36];
        ((int *)((char *)frame_ + 6560))[iVar35 * 4 + iVar17] = (int)((float *)((char *)frame_ + 2432))[uVar32 * 4 + iVar36];
      }
      else if (*(int *)(iVar36 + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())FUN_000c8de0)(param_3 + 0x1589,iVar36);
        uVar21 = (*(uint *)((char *)frame_ + 444));
      }
      uVar33 = uVar33 + 1;
      iVar39 = iVar39 + 0x24;
      if (uVar21 <= uVar33) {
LAB_000caa4c:
        if ((*(uint *)((char *)frame_ + 440)) != 0) {
          uVar33 = 0;
          iVar39 = 0;
          uVar21 = (*(uint *)((char *)frame_ + 440));
          do {
            iVar36 = iVar39 + (*(int *)((char *)frame_ + 452));
            if (*(int *)(iVar36 + 8) == 1) {
              ppppppuVar15 = *(uint *******)(iVar39 + (*(int *)((char *)frame_ + 452)));
              iVar17 = FUN_000c7240(*(undefined4 *)(iVar36 + 4));
              ppppppuVar10 = *(uint *******)(iVar36 + 0x14);
              *(undefined1 *)(param_3 + (int)(((unsigned char *)0x00001005) + (int)ppppppuVar15 * 5)) = 1;
              param_3[(int)(((unsigned char *)0x00001001) + (int)ppppppuVar15 * 5 + iVar17)] = ppppppuVar10;
              uVar21 = (*(uint *)((char *)frame_ + 440));
              if (param_3[0x1502] < ppppppuVar15) {
                param_3[0x1502] = ppppppuVar15;
              }
            }
            uVar33 = uVar33 + 1;
            iVar39 = iVar39 + 0x24;
          } while (uVar33 < uVar21);
        }
        ppppppuVar10 = (uint ******)0x0;
        *(undefined1 *)(param_3 + 0x1507) = 0;
        param_3[0x1506] = (uint ******)0x0;
        param_3[0x151d] = (uint ******)0x0;
        param_3[0x151e] = (uint ******)0x0;
        param_3[0x1503] = (*(uint ****** *)((char *)frame_ + 616));
        param_3[0x1504] = (*(uint ****** *)((char *)frame_ + 1388));
        param_3[0x1505] = (*(uint ****** *)((char *)frame_ + 1988));
        param_3[0x1588] = (uint ******)0x0;
        if ((*(uint ****** *)((char *)frame_ + 1388)) == (uint ******)0x0) {
          ppppppuVar10 = param_3[0x151d];
        }
        else {
          pcVar14 = ((char *)((char *)frame_ + 1392));
          if ((*(uint ****** *)((char *)frame_ + 1388)) == (uint ******)0x0) {
            (*(uint ****** *)((char *)frame_ + 1388)) = (uint ******)0x1;
          }
          do {
            cVar24 = *pcVar14;
            if (cVar24 == '\x01') {
              ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 0x10000);
              param_3[0x151d] = ppppppuVar10;
            }
            else if (cVar24 == '\0') {
              ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 1);
              *(undefined1 *)(param_3 + 0x1507) = 1;
              param_3[0x151d] = ppppppuVar10;
            }
            else if (cVar24 == '\x02') {
              cVar24 = pcVar14[1];
              if (cVar24 == '\x01') {
                ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 4);
                param_3[0x151d] = ppppppuVar10;
              }
              else if (cVar24 == '\0') {
                ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 2);
                param_3[0x151d] = ppppppuVar10;
              }
              else if (cVar24 == '\x02') {
                ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 8);
                param_3[0x151d] = ppppppuVar10;
              }
              else if (cVar24 == '\x03') {
                ppppppuVar10 = (uint ******)((uint)ppppppuVar10 | 0x10);
                param_3[0x151d] = ppppppuVar10;
              }
            }
            else if (cVar24 == '\x05') {
              param_3[0x151e] =
                   (uint ******)(4 << ((uint)(byte)pcVar14[1] * 3 & 0x3f) | (uint)param_3[0x151e]);
              param_3[0x1588] =
                   (uint ******)(4 << ((uint)(byte)pcVar14[1] * 3 & 0x3f) | (uint)param_3[0x1588]);
            }
            pcVar14 = pcVar14 + 0xc;
            (*(uint ****** *)((char *)frame_ + 1388)) = (uint ******)((int)(*(uint ****** *)((char *)frame_ + 1388)) - 1);
          } while ((*(uint ****** *)((char *)frame_ + 1388)) != (uint ******)0x0);
        }
        if (((uint)ppppppuVar10 & 0x18) != 0) {
          param_3[0x151d] = (uint ******)((uint)ppppppuVar10 | 0x1c);
        }
        pppppppuVar18 = param_3 + 0x1571;
        iVar39 = 0x16;
        do {
          *pppppppuVar18 = (uint ******)0x16;
          pppppppuVar18 = pppppppuVar18 + 1;
          iVar39 = iVar39 + -1;
        } while (iVar39 != 0);
        ppppppuVar10 = param_3[0x1503];
        if (ppppppuVar10 != (uint ******)0x0) {
          puVar37 = &(*(undefined1 *)((char *)frame_ + 620));
          ppppppuVar15 = ppppppuVar10;
          if (ppppppuVar10 == (uint ******)0x0) {
            ppppppuVar15 = (uint ******)0x1;
          }
          do {
            pbVar2 = puVar37 + 1;
            pbVar5 = puVar37 + (int)(((byte *)((char *)frame_ + 624)) + -(int)&(*(undefined1 *)((char *)frame_ + 620)));
            puVar37 = puVar37 + 0xc;
            param_3[(int)(((unsigned char *)0x00001571) + *pbVar2)] = (uint ******)(uint)*pbVar5;
            ppppppuVar15 = (uint ******)((int)ppppppuVar15 + -1);
          } while (ppppppuVar15 != (uint ******)0x0);
        }
        if (ppppppuVar10 < (uint ******)0x2) {
          if (ppppppuVar10 == (uint ******)0x0) {
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
        iVar39 = *(*(int * *)((char *)frame_ + 1976));
        param_3[0x1520] = (uint ******)0x0;
        param_3[0x151f] = (uint ******)(uint)(iVar39 != 0);
        if (((uint ******)(uint)(iVar39 != 0) != (uint ******)0x0) &&
           (iVar39 = *(*(int * *)((char *)frame_ + 1976)), 0 < iVar39)) {
          pppppppuVar18 = param_3 + 0x1531;
          ppppppuVar10 = (uint ******)0x0;
          do {
            pppppppuVar18[0x20] = (uint ******)0x0;
            *pppppppuVar18 = (uint ******)0x0;
            pppppppuVar18[0x10] = (uint ******)0x0;
            if ((*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 3] == 0x3e) {
              param_3[0x1520] =
                   (uint ******)(2 << (((uint)ppppppuVar10 & 0x1f) << 1) | (uint)param_3[0x1520]);
              *(char *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5547) =
                   (char)((int *)((char *)frame_ + 6560))[(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 4] * 4 + 1];
              *(char *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5546) =
                   (char)((int *)((char *)frame_ + 6560))[(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 4] * 4 + 2];
              *(short *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x54c6) =
                   (short)(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 5];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001531) + (int)ppppppuVar10)) =
                   (short)((int *)((char *)frame_ + 6560))[(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 4] * 4];
              *(short *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5506) =
                   (short)(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 7];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001541) + (int)ppppppuVar10)) =
                   (short)(*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 5] + 1;
              param_3[(int)(((unsigned char *)0x00001561) + (*(int * *)((char *)frame_ + 1976))[(int)ppppppuVar10 * 7 + 4])] = ppppppuVar10;
            }
            ppppppuVar10 = (uint ******)((int)ppppppuVar10 + 1);
            pppppppuVar18 = pppppppuVar18 + 1;
            iVar39 = iVar39 + -1;
          } while (iVar39 != 0);
        }
        if ((*(uint * *)((char *)frame_ + 1972)) != (uint *)0x0) {
          _free((*(uint * *)((char *)frame_ + 1972)));
        }
        if (iVar11 != 0) {
          _free(iVar11);
        }
        if ((*(int * *)((char *)frame_ + 1976)) != (int *)0x0) {
          _free((*(int * *)((char *)frame_ + 1976)));
        }
        if (puVar29 != (uint *)0x0) {
          _free(puVar29);
        }
        if (iVar38 != 0) {
          _free(iVar38);
        }
        if ((*(int *)((char *)frame_ + 456)) != 0) {
          _free((*(int *)((char *)frame_ + 456)));
        }
        if ((*(int *)((char *)frame_ + 452)) != 0) {
          _free((*(int *)((char *)frame_ + 452)));
        }
        return (uint *******)0x0;
      }
    } while( true );
  }
  ppppppuVar10 = (uint ******)*puVar19;
  uVar32 = (uint)ppppppuVar10 & 0xffff;
  if (100 < uVar32) {
switchD_000c90cc_caseD_0:
                    
    _exit(0);
  }
  iVar39 = uVar32 * 4;
  puVar26 = puVar19;
  switch(uVar32) {
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
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 8)),&(*(uint * *)((char *)frame_ + 12)),1,1,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
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
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 8)),&(*(uint * *)((char *)frame_ + 12)),1,2,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
    goto switchD_000c9ab8_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar18 = (uint *******)0x0;
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 8)),&(*(uint * *)((char *)frame_ + 12)),0,2,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 2;
    (*(uint ******* *)((char *)frame_ + 8))[1] = (uint ******)puVar19[1];
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    (*(uint ******* *)((char *)frame_ + 8))[1] = (uint ******)puVar19[1];
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 3;
    (*(uint ******* *)((char *)frame_ + 8))[2] = (uint ******)puVar19[2];
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 3;
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 3;
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
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 8)),&(*(uint * *)((char *)frame_ + 12)),1,3,&(*(uint ****** *)((char *)frame_ + 2008)));
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 2;
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    (*(uint ******* *)((char *)frame_ + 8))[1] = (uint ******)puVar19[1];
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    for (uVar32 = (uint)*(ushort *)((int)puVar19 + 6); puVar26 = (*(uint * *)((char *)frame_ + 12)), uVar32 != 0;
        uVar32 = uVar32 - 1) {
      ppppppuVar10 = (uint ******)*(*(uint * *)((char *)frame_ + 12));
      (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
      *pppppppuVar30 = ppppppuVar10;
      pppppppuVar30 = pppppppuVar30 + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    if (((uint)ppppppuVar10 & 0x18000000) == 0) {
      uVar32 = *(uint *)((int)((uint *)((char *)frame_ + 10896)) + ((uint)ppppppuVar10 >> 0xe & 0x3fc));
      if (uVar32 != 2) {
        uVar32 = 1;
      }
      ppppppuVar10 = (uint ******)((uVar32 & 3) << 0x1b | (uint)ppppppuVar10 & 0xe7ffffff);
    }
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if ((int)ppppppuVar10 < 0) {
      ppppppuVar10 = (uint ******)*(*(uint * *)((char *)frame_ + 12));
      (*(uint * *)((char *)frame_ + 12)) = puVar19 + 2;
      (*(uint ******* *)((char *)frame_ + 8))[1] = ppppppuVar10;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar25;
    ppppppuVar10 = (uint ******)*(*(uint * *)((char *)frame_ + 12));
    (*(uint * *)((char *)frame_ + 12)) = (*(uint * *)((char *)frame_ + 12)) + 1;
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar25 = pppppppuVar30;
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    pppppppuVar18 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = pppppppuVar18;
    if ((puVar19[1] >> 0x10 & 0x3f) - 1 < 2) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = (uint ******)puVar19[1];
      pppppppuVar20 = (*(uint ******* *)((char *)frame_ + 8)) + 6;
      (*(uint ******* *)((char *)frame_ + 8))[2] = (uint ******)puVar19[2];
      (*(uint ******* *)((char *)frame_ + 8))[3] = (uint ******)puVar19[3];
      (*(uint ******* *)((char *)frame_ + 8))[4] = (uint ******)puVar19[4];
      (*(uint * *)((char *)frame_ + 12)) = puVar19 + 6;
      (*(uint ******* *)((char *)frame_ + 8))[5] = (uint ******)puVar19[5];
      puVar26 = (*(uint * *)((char *)frame_ + 12));
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 5;
      pppppppuVar30 = pppppppuVar20;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    puVar16 = (undefined4 *)
              ((int (*)())FUN_000c7930)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,(*(uint * *)((char *)frame_ + 12)),pppppppuVar20,
                           iVar39);
    *puVar16 = ppppppuVar10;
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (uint *******)(puVar16 + 1);
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 2;
    ((uint ****** *)((char *)frame_ + 52))[0] = (uint ******)puVar19[1];
    (*(uint ******* *)((char *)frame_ + 8)) = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    ((int (*)())FUN_000c8760)(((uint ****** *)((char *)frame_ + 52)),((undefined1 *)((char *)frame_ + 64)),pppppppuVar18);
    *(*(uint ******* *)((char *)frame_ + 8)) = ((uint ****** *)((char *)frame_ + 52))[0];
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar18 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    break;
  case 0x5d:
    if (bVar4) {
      bVar4 = false;
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
      puVar19 = (*(uint * *)((char *)frame_ + 12));
    }
    ppppppuVar10 = (uint ******)*puVar19;
    puVar26 = puVar19 + 1;
    uVar32 = (uint)ppppppuVar10 >> 0x10;
    uVar22 = uVar32 & 0xff;
    bVar3 = ((uint)ppppppuVar10 & 0x80000000) != 0;
    if (bVar3) {
      puVar26 = puVar19 + 2;
      ppppppuVar15 = (uint ******)puVar19[1];
    }
    else {
      ppppppuVar15 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar10 >> 0x1e & 1) != 0;
    if (bVar1) {
      ppppppuVar23 = (uint ******)*puVar26;
      puVar26 = puVar26 + 1;
    }
    else {
      ppppppuVar23 = (uint ******)0x0;
    }
    (*(uint ******* *)((char *)frame_ + 28)) = (uint *******)*puVar26;
    puVar19 = puVar26 + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) != 0) {
      puVar19 = puVar26 + 2;
      unaff_r15 = (uint ******)puVar26[1];
    }
    (*(uint ****** *)((char *)frame_ + 76)) = (uint ******)*puVar19;
    (*(uint * *)((char *)frame_ + 12)) = puVar19 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 76)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 40)) = (uint ******)puVar19[1];
      (*(uint * *)((char *)frame_ + 12)) = puVar19 + 2;
    }
    uVar7 = (uint)ppppppuVar10 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca0e4:
      if ((*(uint *)((char *)frame_ + 2120)) << (uVar32 & 0x3f) == 0) {
        (*(uint ****** *)((char *)frame_ + 11088)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 76));
        pppppppuVar30 = (uint *******)0x0;
        uVar34 = 1 << (uVar32 & 0x3f);
        ppppppuVar28 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
      }
      else {
        (*(uint ****** *)((char *)frame_ + 11104)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
        (*(uint ****** *)((char *)frame_ + 11088)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 76));
        (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)((int (*)())FUN_000c7460)(&(*(uint ****** *)((char *)frame_ + 2008)),(*(uint ****** *)((char *)frame_ + 11088)),(*(uint ****** *)((char *)frame_ + 11104)),uVar22,(*(uint ******* *)((char *)frame_ + 8)));
        ppppppuVar28 = (*(uint ****** *)((char *)frame_ + 11104));
        if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) == 0) {
          pppppppuVar30 = (uint *******)0x0;
          uVar34 = 1 << (uVar32 & 0x3f);
        }
        else {
          (*(uint ******* *)((char *)frame_ + 28)) = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0xffbfffff);
          pppppppuVar30 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar34 = 1 << (uVar32 & 0x3f);
          (*(uint ****** *)((char *)frame_ + 16)) = unaff_r15;
        }
      }
    }
    else if (uVar7 == 0x8000000) {
      uVar34 = 1 << (uVar32 & 0x3f);
      if ((uVar34 & (*(uint *)((char *)frame_ + 2124))) != 0) goto LAB_000ca0e4;
      (*(uint ****** *)((char *)frame_ + 11088)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 76));
      pppppppuVar30 = (uint *******)0x0;
      ppppppuVar28 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
    }
    else {
      pppppppuVar30 = (uint *******)0x0;
      uVar34 = 1 << (uVar32 & 0x3f);
      (*(uint ****** *)((char *)frame_ + 11088)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 76));
      ppppppuVar28 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
    }
    pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 2008));
    ((int (*)())FUN_000c8760)((*(uint ****** *)((char *)frame_ + 11088)),ppppppuVar28,&(*(uint ****** *)((char *)frame_ + 2008)));
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (bVar3) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = ppppppuVar15;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar25;
    if (bVar1) {
      *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar23;
      (*(uint ******* *)((char *)frame_ + 8)) = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    }
    *(*(uint ******* *)((char *)frame_ + 8)) = (uint ******)(*(uint ******* *)((char *)frame_ + 28));
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = unaff_r15;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar25;
    *(*(uint ******* *)((char *)frame_ + 8)) = (*(uint ****** *)((char *)frame_ + 76));
    pppppppuVar25 = (uint *******)((uint)(*(uint ****** *)((char *)frame_ + 76)) & 0x400000);
    pppppppuVar8 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = (*(uint ****** *)((char *)frame_ + 40));
      pppppppuVar8 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar8;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar34 & (*(uint *)((char *)frame_ + 2124))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 2120)) << (uVar32 & 0x3f) != 0)) {
      pppppppuVar18 = (uint *******)&(*(uint ******* *)((char *)frame_ + 28));
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c7650)(&(*(uint ****** *)((char *)frame_ + 2008)),(*(uint ****** *)((char *)frame_ + 11088)),pppppppuVar18,&(*(uint ****** *)((char *)frame_ + 16)),uVar22,pppppppuVar30,
                                (*(uint ******* *)((char *)frame_ + 8)),pppppppuVar25);
      pppppppuVar20 = pppppppuVar30;
    }
    uVar34 = uVar34 & (*(uint *)((char *)frame_ + 2120));
    ppppppuVar10 = unaff_r15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (bVar4) {
      bVar4 = false;
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 8)),&(*(uint ****** *)((char *)frame_ + 2008)),pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
      puVar19 = (*(uint * *)((char *)frame_ + 12));
    }
    ppppppuVar10 = (uint ******)*puVar19;
    puVar26 = puVar19 + 1;
    uVar32 = (uint)ppppppuVar10 >> 0x10;
    uVar22 = uVar32 & 0xff;
    bVar3 = ((uint)ppppppuVar10 & 0x80000000) != 0;
    if (bVar3) {
      puVar26 = puVar19 + 2;
      ppppppuVar15 = (uint ******)puVar19[1];
    }
    else {
      ppppppuVar15 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar10 & 0x40000000) != 0;
    if (bVar1) {
      ppppppuVar23 = (uint ******)*puVar26;
      puVar26 = puVar26 + 1;
    }
    else {
      ppppppuVar23 = (uint ******)0x0;
    }
    (*(uint ******* *)((char *)frame_ + 28)) = (uint *******)*puVar26;
    puVar19 = puVar26 + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) != 0) {
      puVar19 = puVar26 + 2;
      unaff_r14 = (uint ******)puVar26[1];
    }
    (*(uint ****** *)((char *)frame_ + 40)) = (uint ******)*puVar19;
    puVar26 = puVar19 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 40)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 76)) = (uint ******)puVar19[1];
      puVar26 = puVar19 + 2;
    }
    (*(uint ****** *)((char *)frame_ + 44)) = (uint ******)*puVar26;
    (*(uint * *)((char *)frame_ + 12)) = puVar26 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 44)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 80)) = (uint ******)puVar26[1];
      (*(uint * *)((char *)frame_ + 12)) = puVar26 + 2;
    }
    uVar7 = (uint)ppppppuVar10 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca3b8:
      if ((*(uint *)((char *)frame_ + 2120)) << (uVar32 & 0x3f) != 0) {
        pppppppuVar18 = &(*(uint ****** *)((char *)frame_ + 76));
        (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                     ((int (*)())FUN_000c7460)(&(*(uint ****** *)((char *)frame_ + 2008)),&(*(uint ****** *)((char *)frame_ + 40)),pppppppuVar18,uVar22,(*(uint ******* *)((char *)frame_ + 8)));
        if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) != 0) {
          (*(uint ******* *)((char *)frame_ + 28)) = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0xffbfffff);
          pppppppuVar20 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar34 = 1 << (uVar32 & 0x3f);
          (*(uint ****** *)((char *)frame_ + 16)) = unaff_r14;
          goto LAB_000ca414;
        }
      }
LAB_000ca3ec:
      pppppppuVar20 = (uint *******)0x0;
      uVar34 = 1 << (uVar32 & 0x3f);
    }
    else {
      if (uVar7 != 0x8000000) goto LAB_000ca3ec;
      pppppppuVar20 = (uint *******)0x0;
      uVar34 = 1 << (uVar32 & 0x3f);
      if ((uVar34 & (*(uint *)((char *)frame_ + 2124))) != 0) goto LAB_000ca3b8;
    }
LAB_000ca414:
    *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar10;
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (bVar3) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = ppppppuVar15;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar25;
    if (bVar1) {
      *(*(uint ******* *)((char *)frame_ + 8)) = ppppppuVar23;
      (*(uint ******* *)((char *)frame_ + 8)) = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    }
    *(*(uint ******* *)((char *)frame_ + 8)) = (uint ******)(*(uint ******* *)((char *)frame_ + 28));
    pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = unaff_r14;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar25;
    *(*(uint ******* *)((char *)frame_ + 8)) = (*(uint ****** *)((char *)frame_ + 40));
    pppppppuVar25 = (uint *******)((uint)(*(uint ****** *)((char *)frame_ + 40)) & 0x400000);
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = (*(uint ****** *)((char *)frame_ + 76));
      pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar30;
    *(*(uint ******* *)((char *)frame_ + 8)) = (*(uint ****** *)((char *)frame_ + 44));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 44)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 8))[1] = (*(uint ****** *)((char *)frame_ + 80));
      pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 8)) = pppppppuVar30;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar34 & (*(uint *)((char *)frame_ + 2124))) != 0)))) &&
       (pppppppuVar25 = (uint *******)((*(uint *)((char *)frame_ + 2120)) << (uVar32 & 0x3f)),
       pppppppuVar25 != (uint *******)0x0)) {
      pppppppuVar18 = (uint *******)&(*(uint ******* *)((char *)frame_ + 28));
      (*(uint ******* *)((char *)frame_ + 8)) = (uint *******)
                   ((int (*)())FUN_000c7650)(&(*(uint ****** *)((char *)frame_ + 2008)),&(*(uint ****** *)((char *)frame_ + 40)),pppppppuVar18,&(*(uint ****** *)((char *)frame_ + 16)),uVar22,
                                pppppppuVar20,(*(uint ******* *)((char *)frame_ + 8)),pppppppuVar25);
    }
    uVar34 = uVar34 & (*(uint *)((char *)frame_ + 2120));
    ppppppuVar10 = unaff_r14;
joined_r0x000ca538:
    puVar26 = (*(uint * *)((char *)frame_ + 12));
    pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
    if (uVar34 != 0) {
      pppppppuVar20 = (*(uint ******* *)((char *)frame_ + 8)) + 1;
      *(*(uint ******* *)((char *)frame_ + 8)) = (uint ******)0x47;
      pppppppuVar25 = (*(uint ******* *)((char *)frame_ + 28));
      if (((uint)(*(uint ******* *)((char *)frame_ + 28)) & 0x400000) == 0) {
        pppppppuVar25 = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 28)) | 0x400000);
        ppppppuVar10 = (uint ******)0x55;
      }
      if (((int *)((char *)frame_ + 2256))[uVar22] == 0x1906) {
        if (((uint)ppppppuVar10 & 3) == 1) {
          ppppppuVar10 = (uint ******)((uint)ppppppuVar10 & 0xfffffffc | 2);
        }
        if (((uint)ppppppuVar10 & 0xc) == 4) {
          ppppppuVar10 = (uint ******)((uint)ppppppuVar10 & 0xfffffff3 | 8);
        }
        if (((uint)ppppppuVar10 & 0x30) == 0x10) {
          ppppppuVar10 = (uint ******)((uint)ppppppuVar10 & 0xffffffcf | 0x20);
        }
      }
      else if ((((int *)((char *)frame_ + 2256))[uVar22] == 0x1909) && (((uint)ppppppuVar10 & 0xc0) == 0x40)) {
        ppppppuVar10 = (uint ******)((uint)ppppppuVar10 & 0xffffff3f | 0xc0);
      }
      *pppppppuVar20 = (uint ******)pppppppuVar25;
      (*(uint ******* *)((char *)frame_ + 8))[2] = ppppppuVar10;
      (*(uint ******* *)((char *)frame_ + 8))[3] = (uint ******)((uint)pppppppuVar25 & 0x3fffff);
      pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8)) + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  (*(uint * *)((char *)frame_ + 12)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 8)),&(*(uint * *)((char *)frame_ + 12)),pppppppuVar18,1,&(*(uint ****** *)((char *)frame_ + 2008)));
  puVar26 = (*(uint * *)((char *)frame_ + 12));
  pppppppuVar30 = (*(uint ******* *)((char *)frame_ + 8));
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
  int *piVar18;
  uint *******pppppppuVar19;
  int iVar20;
  uint uVar21;
  uint *puVar22;
  uint *puVar23;
  int iVar24;
  uint *******in_r8;
  byte *pbVar25;
  int iVar26;
  uint uVar27;
  uint *******pppppppuVar28;
  undefined4 uVar29;
  int iVar30;
  char *pcVar31;
  int *piVar32;
  undefined4 uVar33;
  uint ******unaff_r14;
  uint ******unaff_r15;
  uint *puVar34;
  uint uVar35;
  uint unaff_r19;
  uint *******pppppppuVar36;
  undefined1 *puVar37;
  uint unaff_r20;
  undefined1 *puVar38;
  uint ******ppppppuVar39;
  uint *puVar40;
  float *pfVar41;
  uint uVar42;
  int iVar43;
  int *piVar44;
  undefined4 *puVar45;
  int iVar46;
  int iVar47;
  /* Follow-up to the previous fix's own bug (issue #64 live-repro): enlarging auStack_c148 was
   * correct, but leaving local_c100/local_c0fc/local_c0f8/local_c0f0/local_c0d0/local_c090 as
   * separate, non-overlapping locals was NOT harmless - confirmed live on real hardware. Stock's
   * real code does do pointer arithmetic from this buffer into them: FUN_000cd1b0 (called with
   * auStack_c148) tail-calls into FUN_000da394/FUN_000e2524, which read *(auStack_c148+0x4c)
   * expecting local_c0fc's value; a loop just below also writes local_c0f0[8..15], expecting
   * those words to land in local_c0d0. With the locals declared separately, the compiler placed
   * them elsewhere on the stack, so auStack_c148+0x4c stayed at its memset'd 0 instead of the
   * real pointer - a null deref several calls downstream, in FUN_00193c00's live differential
   * GLDriver test harness. Root-caused via a live watchpoint comparing stock vs. rebuilt (stock:
   * r3=0x40d470 at the same call; rebuilt: 0). Properly merged this time into one byte-accurate
   * 0xbc-byte buffer; each offset below is confirmed directly from its own name's hex value
   * (0xc148-0xc0fc=0x4c, 0xc148-0xc090=0xb8, etc), and the whole run is contiguous and exactly
   * 0xbc bytes (0xb8+4), matching the buffer's own real, memset'd size. */
  undefined1 auStack_c148 [0xbc];
#define local_c100 (*(uint **)(auStack_c148 + 0x48))
#define local_c0fc (*(uint **)(auStack_c148 + 0x4c))
#define local_c0f8 (*(int *)(auStack_c148 + 0x50))
#define local_c0f0 ((uint *)(auStack_c148 + 0x58))
#define local_c0d0 ((uint *)(auStack_c148 + 0x78))
#define local_c090 (*(int *)(auStack_c148 + 0xb8))
  /* issue #64 live-repro: FUN_000c8910/FUN_000c8600 (reached via the command-stream token-1/0x47
   * opcode handlers below) treat their 3rd/4th argument - &local_c08c, passed directly or via an
   * alias (pppppppuVar19/(*(uint ******* *)((char *)frame_ + 49528))) at every call site in this function - as the base of a large
   * per-context attribute-state array, indexing it at param_3[2] up to param_3[0x88a] (~8.7KB).
   * Declared as a single word, this overflowed onto whatever real stock places after it on the
   * stack. Live-verified on real hardware via a raw memory watchpoint at the real stock address:
   * FUN_000c8600's `param_3[param_1+0x87c] = 1;` (opcode 0x47, param_1==0) is a real, deterministic
   * write stock performs that the rebuild's undersized local_c08c can't - traced back through
   * FUN_000cae90's own size-computation cascade (part_018.c:2758-2820) to the calloc(44) crash this
   * issue's title tracks: the write's real destination is 12 bytes past a stack region our size
   * computation reads back as a "flag" (((int *)((char *)frame_ + 9060))[0]) to decide the command buffer's malloc size,
   * so leaving it unwritten undersizes that malloc by exactly the corruption this issue chases.
   * Given its own real size, without touching any other local's declaration. */
  unsigned char local_c08c_buf [0x2400];
#define local_c08c (*(uint *******)(local_c08c_buf))
  /* issue #64 live-repro: the command-stream interpreter's source-side copy loop further down
   * ("puVar23 = local_c080; ... do{uVar21=*puVar23; uVar35=puVar23[8]; puVar23=puVar23+1; ...}
   * while(iVar47!=0)" with iVar47 starting at 8) reads puVar23[0] and puVar23[8] across 8
   * iterations, reaching as far as local_c080+0x3c - 16 contiguous words (0x40 bytes), not just
   * local_c080's own declared 4. local_c070/c06c/c068/c064/c060/c050/c04c/c048/c044 are exactly
   * those remaining words by their own hex offsets. This is the read-side counterpart of the
   * auStack_c148/local_c0fc fix from earlier this session (the write side, local_c0f0/local_c0d0,
   * was already sized correctly there). Left separate, the rebuild copied whatever real stack
   * words happened to follow local_c080's own 4 into the destination command buffer instead of
   * the real header/argument words - live-verified: the command-stream interpreter three calls
   * later reads a garbage opcode (>100) from the corrupted buffer and hits its own documented
   * out-of-range safety net (_exit(0), confirmed present in stock too). Merged into one 0x40-byte
   * buffer. */
  unsigned char local_c080_buf [0x40];
#define local_c080 ((uint *)(local_c080_buf + 0x00))
#define local_c070 (*(undefined4 *)(local_c080_buf + 0x10))
#define local_c06c (*(undefined4 *)(local_c080_buf + 0x14))
#define local_c068 (*(undefined4 *)(local_c080_buf + 0x18))
#define local_c064 (*(undefined4 *)(local_c080_buf + 0x1c))
#define local_c060 ((uint *)(local_c080_buf + 0x20))
#define local_c050 (*(undefined4 *)(local_c080_buf + 0x30))
#define local_c04c (*(undefined4 *)(local_c080_buf + 0x34))
#define local_c048 (*(undefined4 *)(local_c080_buf + 0x38))
#define local_c044 (*(undefined4 *)(local_c080_buf + 0x3c))
  /* Declared too small (72 bytes) vs. its own memset (0x9c88 = 40072 bytes) - this is the real
   * root cause of the shader/GLSL token-stream parser crash tracked on issue #64: this buffer is
   * the token stream's own backing storage (its address eventually becomes the base FUN_000e4a38
   * walks via param_1+0x74), and at 72 declared bytes the memset was overflowing ~40KB into
   * whatever the compiler placed after it on the stack - onto this same giant function's own many
   * other locals, corrupting them, AND leaving the "real" 40KB buffer's tail entirely unzeroed
   * (reading uninitialized stack garbage there once the token stream's real content ran out,
   * instead of the clean zero/terminator byte stock's properly-sized buffer provides). Enlarged to
   * the real size. */
  undefined1 auStack_9d1c [0x9c88];
  unsigned int frame_[12416] __attribute__((aligned(16)));
  
  iVar46 = 8;
  iVar13 = 0;
  do {
    *(undefined4 *)((int)((uint *)((char *)frame_ + 152)) + iVar13) = 0xffffffff;
    *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 120)) + iVar13) = 0;
    iVar13 = iVar13 + 4;
    iVar46 = iVar46 + -1;
  } while (iVar46 != 0);
  bVar3 = param_1 == 0;
  ((uint *)((char *)frame_ + 152))[0] = ((uint *)((char *)frame_ + 152))[0] & 0xffff0000;
  pppppppuVar19 = param_3;
  iVar13 = _malloc(0x400);
  (*(undefined4 *)((char *)frame_ + 9440)) = 0;
  (*(uint *)((char *)frame_ + 488)) = 0;
  (*(undefined4 *)((char *)frame_ + 9360)) = 0;
  (*(int *)((char *)frame_ + 9364)) = 0;
  if (bVar3) {
    (*(uint *)((char *)frame_ + 484)) = 0;
  }
  else {
    in_r8 = (uint *******)0x0;
    iVar47 = 0x10;
    (*(uint *)((char *)frame_ + 488)) = 0;
    (*(uint *)((char *)frame_ + 484)) = 0;
    puVar34 = ((uint *)((char *)frame_ + 620));
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    iVar46 = param_1;
    do {
      iVar26 = *(int *)(((unsigned char *)0x000013f8) + iVar46);
      if ((iVar26 != 0) && (*(short *)(iVar26 + 0x38) == 0x1902)) {
        uVar21 = 1 << ((uint)in_r8 & 0x3f);
        (*(uint *)((char *)frame_ + 484)) = uVar21 | (*(uint *)((char *)frame_ + 484));
        *puVar34 = (uint)*(ushort *)(iVar26 + 0x58);
        puVar34[0x10] = (uint)*(ushort *)(iVar26 + 0x5c);
        if (*(short *)(iVar26 + 0x5a) != 0) {
          (*(uint *)((char *)frame_ + 488)) = uVar21 | (*(uint *)((char *)frame_ + 488));
        }
      }
      in_r8 = (uint *******)((int)in_r8 + 1);
      iVar46 = iVar46 + 4;
      puVar34 = puVar34 + 1;
      iVar47 = iVar47 + -1;
    } while (iVar47 != 0);
  }
  if (*(char *)(param_3 + 0x46) == '\0') {
    (*(int *)((char *)frame_ + 9028)) = 0;
  }
  else {
    (*(uint ****** *)((char *)frame_ + 9032)) = param_3[0x2b];
    (*(int *)((char *)frame_ + 9028)) = 1;
    if (bVar3) {
      (*(undefined4 *)((char *)frame_ + 9036)) = 0;
    }
    else {
      (*(undefined4 *)((char *)frame_ + 9036)) = *(undefined4 *)(param_1 + 0x276c);
    }
  }
  iVar46 = 0;
  puVar34 = ((uint *)((char *)frame_ + 9260));
  iVar47 = 0x10;
  do {
    *puVar34 = 0;
    if ((!bVar3) && (*(int *)(((unsigned char *)0x000013f8) + iVar46 * 4 + *param_2) != 0)) {
      *puVar34 = (uint)*(byte *)(*(int *)(((unsigned char *)0x000013f8) + iVar46 * 4 + *param_2) + 0x30);
    }
    iVar46 = iVar46 + 1;
    puVar34 = puVar34 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  (*(uint ******* *)((char *)frame_ + 9128)) = (uint *******)((int)((unsigned char *)0x0) + 1);
  (*(int *)((char *)frame_ + 9080)) = 0;
  (*(uint ****** *)((char *)frame_ + 9328)) = param_3[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != -0x7baf)) {
    (*(undefined4 *)((char *)frame_ + 9344)) = 0;
  }
  else {
    (*(undefined4 *)((char *)frame_ + 9344)) = 1;
  }
  puVar40 = (uint *)*param_4;
  local_c08c = (uint ******)0x0;
  (*(int *)((char *)frame_ + 472)) = 0;
  (*(undefined4 *)((char *)frame_ + 376)) = 0xffff;
  local_c064 = (*(undefined4 *)((char *)frame_ + 180));
  local_c068 = (*(undefined4 *)((char *)frame_ + 176));
  local_c06c = (*(undefined4 *)((char *)frame_ + 172));
  local_c070 = (*(undefined4 *)((char *)frame_ + 168));
  local_c080[3] = ((uint *)((char *)frame_ + 152))[3];
  local_c080[2] = ((uint *)((char *)frame_ + 152))[2];
  local_c080[1] = ((uint *)((char *)frame_ + 152))[1];
  local_c080[0] = ((uint *)((char *)frame_ + 152))[0];
  local_c044 = (*(undefined4 *)((char *)frame_ + 148));
  local_c048 = (*(undefined4 *)((char *)frame_ + 144));
  iVar46 = param_4[1];
  local_c04c = (*(undefined4 *)((char *)frame_ + 140));
  local_c050 = (*(undefined4 *)((char *)frame_ + 136));
  (*(int *)((char *)frame_ + 448)) = 0;
  local_c060[3] = ((undefined4 *)((char *)frame_ + 120))[3];
  local_c060[2] = ((undefined4 *)((char *)frame_ + 120))[2];
  (*(uint *)((char *)frame_ + 380)) = 0;
  (*(undefined4 *)((char *)frame_ + 9124)) = 0;
  (*(uint *)((char *)frame_ + 748)) = 0;
  (*(int *)((char *)frame_ + 9020)) = 0;
  ((int *)((char *)frame_ + 9060))[0] = 0;
  ((int *)((char *)frame_ + 9060))[1] = 0;
  ((int *)((char *)frame_ + 9060))[2] = 0;
  ((int *)((char *)frame_ + 9060))[3] = 0;
  (*(int *)((char *)frame_ + 9096)) = 0;
  (*(int *)((char *)frame_ + 9100)) = 0;
  (*(int *)((char *)frame_ + 9104)) = 0;
  (*(int *)((char *)frame_ + 9108)) = 0;
  (*(int *)((char *)frame_ + 9088)) = 0;
  (*(undefined4 *)((char *)frame_ + 9112)) = 0;
  (*(int *)((char *)frame_ + 9116)) = 0;
  (*(int *)((char *)frame_ + 9120)) = 0;
  local_c060[1] = ((undefined4 *)((char *)frame_ + 120))[1];
  local_c060[0] = ((undefined4 *)((char *)frame_ + 120))[0];
  puVar34 = ((uint *)((char *)frame_ + 764));
  iVar47 = 8;
  do {
    *puVar34 = 0;
    puVar34[0x408] = 0;
    puVar34 = puVar34 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  (*(int * *)((char *)frame_ + 49536)) = ((int *)((char *)frame_ + 9132));
  iVar47 = 0x10;
  piVar18 = (*(int * *)((char *)frame_ + 49536));
  do {
    *piVar18 = 0;
    piVar18[0x10] = 0;
    piVar18 = piVar18 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  iVar47 = 0;
  iVar26 = 0;
  uVar21 = 0;
  puVar34 = puVar40;
switchD_000cb23c_caseD_15:
  (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
  puVar23 = (*(uint * *)((char *)frame_ + 8));
switchD_000cb23c_caseD_18:
  puVar34 = puVar23;
  if (puVar34 < puVar40 + iVar46) goto code_r0x000cb214;
  if ((*(int *)((char *)frame_ + 9020)) != 0) {
    puVar34 = (uint *)0x0;
    uVar35 = 0;
    goto LAB_000cc88c;
  }
  iVar47 = (iVar46 + iVar47) * 4;
  (*(uint ****** *)((char *)frame_ + 452)) = local_c08c;
  if ((*(int *)((char *)frame_ + 448)) != 0) {
    iVar47 = iVar47 + 0x48;
  }
  uVar35 = iVar47 + iVar26 * 4;
  bVar5 = (*(int *)((char *)frame_ + 9028)) != 0;
  if (bVar5) {
    uVar35 = uVar35 + 0x14;
  }
  uVar12 = uVar35;
  if ((((int *)((char *)frame_ + 9060))[0] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar35 = uVar12;
  if ((((int *)((char *)frame_ + 9060))[1] != 0) && (uVar35 = uVar12 + 0xc, bVar5)) {
    uVar35 = uVar12 + 0x24;
  }
  uVar12 = uVar35;
  if ((((int *)((char *)frame_ + 9060))[2] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar27 = uVar12;
  if ((((int *)((char *)frame_ + 9060))[3] != 0) && (uVar27 = uVar12 + 0xc, bVar5)) {
    uVar27 = uVar12 + 0x24;
  }
  if ((((*(int *)((char *)frame_ + 9088)) != 0) && ((*(int *)((char *)frame_ + 9080)) != 0)) && ((*(uint ******* *)((char *)frame_ + 9128)) == (uint *******)0x0)) {
    uVar27 = uVar27 + 0x14;
  }
  if ((*(uint ****** *)((char *)frame_ + 9328)) == (uint ******)0x1) {
    uVar27 = uVar27 + 0x24;
  }
  else if ((*(uint ****** *)((char *)frame_ + 9328)) == (uint ******)0x2) {
    uVar27 = uVar27 + 0x30;
  }
  else if ((*(uint ****** *)((char *)frame_ + 9328)) == (uint ******)0x3) {
    uVar27 = uVar27 + 0x40;
  }
  else if ((*(uint ****** *)((char *)frame_ + 9328)) == (uint ******)0x0) goto LAB_000cbb64;
  uVar27 = uVar27 + 8;
  piVar18 = ((int *)((char *)frame_ + 9060));
  iVar47 = 4;
  do {
    if (*piVar18 != 0) {
      uVar27 = uVar27 + 0x2c;
    }
    piVar18 = piVar18 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
LAB_000cbb64:
  if ((((*(int *)((char *)frame_ + 9100)) != 0) || ((*(int *)((char *)frame_ + 9108)) != 0)) || (uVar35 = uVar27, (*(uint ******* *)((char *)frame_ + 9128)) == (uint *******)0x0)
     ) {
    if (((*(int *)((char *)frame_ + 9096)) == 0) && ((*(int *)((char *)frame_ + 9104)) != 0)) {
      uVar27 = uVar27 + 0xc;
    }
    uVar35 = uVar27;
    if (((*(uint ******* *)((char *)frame_ + 9128)) == (uint *******)0x0) && (uVar35 = uVar27 + 0xc, (*(int *)((char *)frame_ + 9348)) != 0)) {
      uVar35 = uVar27 + 0x18;
    }
  }
  bVar5 = true;
  pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 9128));
  puVar34 = (uint *)_malloc(uVar35 + 0x10);
  *puVar34 = *puVar40;
  (*(uint * *)((char *)frame_ + 8)) = puVar40 + 2;
  puVar34[1] = puVar40[1];
  puVar23 = (*(uint * *)((char *)frame_ + 8));
  pppppppuVar36 = (uint *******)(puVar34 + 2);
  goto switchD_000cbc48_caseD_18;
code_r0x000cb214:
  pppppppuVar19 = (uint *******)*puVar34;
  puVar23 = puVar34;
  switch((uint)pppppppuVar19 & 0xffff) {
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
    uVar29 = 1;
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
    uVar29 = 1;
    goto LAB_000cb4b0;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  /* issue #64 live-repro (crash #3, use-after-free): opcode 0x28 was lumped in with the
   * trivial single-word opcodes above in THIS sizing pass, contributing nothing extra to
   * iVar47 (the buffer's extra-output-words budget). But the WRITE pass's real case 0x28
   * (below, `puVar45 = FUN_000c7930(...); *puVar45 = ppppppuVar15;`) calls FUN_000c7930,
   * which - depending on live per-context state read from local_c08c/param_2 - can emit far
   * more than one output word: tallying every conditional block in FUN_000c7930 (part_018.c),
   * its worst case is 110 words (60 from the first *(param_2+0x22fc)!=0 block's three
   * sub-loops, 24 from the *(param_2+0x21d0)!=0 loop, 12 from the unconditional third loop,
   * 5 from the 0x220c/0x2204/0x2234 block, 9 from the final 0x2218/0x2220/0x2234 block),
   * plus the caller's own extra `*puVar45 = ppppppuVar15` word already covered by this
   * opcode's baseline 1-word allowance. Live-verified on real hardware: with a watchpoint on
   * the corrupted freed heap block, `info locals` inside FUN_000cae90 at the exact fault
   * showed puVar45 (the write's destination pointer, i.e. FUN_000c7930's real return value)
   * equal to the corrupted address, and ppppppuVar15 (the value written) equal to 0x28 - the
   * opcode number itself, confirming this exact call site. Splitting 0x28 out and adding its
   * real worst-case bonus here (matching the existing iVar47/iVar26 bonus pattern used by
   * cases 0x24/0x5d/0x5e above) so the command buffer is sized for what this opcode can
   * actually emit. */
  case 0x28:
    iVar47 = iVar47 + 110;
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar29 = 0;
LAB_000cb4b0:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8910)(puVar34,uVar29,2,&local_c08c);
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 3;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 3);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8910)(puVar34,1,3,&local_c08c);
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + *(ushort *)((int)puVar34 + 6) + 2;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 3;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    pppppppuVar19 = &local_c08c;
    uVar35 = puVar34[1];
    puVar8 = (undefined *)(uVar35 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar19,0,0);
    if (puVar8 == ((unsigned char *)0x00160000U)) {
      (*(int *)((char *)frame_ + 448)) = 1;
    }
    else if (puVar8 == (undefined *)0x110000) {
      (*(uint *)((char *)frame_ + 380)) = 1 << (uVar35 & 0x3f) | (*(uint *)((char *)frame_ + 380));
    }
    else if (puVar8 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar35 & 0x3f);
    }
    else if (puVar8 == (undefined *)0x100000) {
      (*(int *)((char *)frame_ + 472)) = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar12 = (uint)pppppppuVar19 >> 0x1b & 3;
    uVar35 = (uint)pppppppuVar19 >> 0x10 & 0xff;
    if ((uVar12 == 2) || ((uVar12 == 0 && (((uint *)((char *)frame_ + 9260))[uVar35] == 2)))) {
      (*(uint *)((char *)frame_ + 748)) = 1 << ((uint)pppppppuVar19 >> 0x10 & 0x3f) | (*(uint *)((char *)frame_ + 748));
    }
    pppppppuVar19 = (uint *******)((uint)pppppppuVar19 >> 0x18 & 7);
    FUN_000c7270(&local_c08c,uVar35,pppppppuVar19);
    (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    if ((int)pppppppuVar19 < 0) {
      (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    }
LAB_000cb6d4:
    (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    uVar12 = puVar34[1];
    uVar35 = uVar12 >> 0x10 & 0x3f;
    if (uVar35 == 1) {
      pppppppuVar19 = &(*(uint ****** *)((char *)frame_ + 88));
      (*(uint ****** *)((char *)frame_ + 88)) = (uint ******)puVar34[2];
      (*(uint *)((char *)frame_ + 92)) = puVar34[3];
      (*(uint *)((char *)frame_ + 96)) = puVar34[4];
      (*(uint * *)((char *)frame_ + 8)) = puVar34 + 6;
      (*(uint *)((char *)frame_ + 100)) = puVar34[5];
      FUN_000c7290(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
      puVar23 = (*(uint * *)((char *)frame_ + 8));
    }
    else {
      puVar23 = (*(uint * *)((char *)frame_ + 8));
      if (uVar35 == 2) {
        pppppppuVar19 = &(*(uint ****** *)((char *)frame_ + 88));
        (*(uint ****** *)((char *)frame_ + 88)) = (uint ******)puVar34[2];
        (*(uint *)((char *)frame_ + 92)) = puVar34[3];
        (*(uint *)((char *)frame_ + 96)) = puVar34[4];
        (*(uint * *)((char *)frame_ + 8)) = puVar34 + 6;
        (*(uint *)((char *)frame_ + 100)) = puVar34[5];
        FUN_000c72f0(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
        puVar23 = (*(uint * *)((char *)frame_ + 8));
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    iVar47 = iVar47 + 5;
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8910)(puVar34,1,2,&local_c08c);
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    ((uint ****** *)((char *)frame_ + 64))[0] = (uint ******)puVar34[1];
    ((int (*)())FUN_000c87d0)(((uint ****** *)((char *)frame_ + 64)),((undefined1 *)((char *)frame_ + 76)),pppppppuVar19);
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8910)(puVar34,0,1,&local_c08c);
    (*(int *)((char *)frame_ + 9120)) = 1;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar29 = 0;
    break;
  case 0x5d:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    (*(int *)((char *)frame_ + 9364)) = (*(int *)((char *)frame_ + 9364)) + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 488))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 484)) << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      iVar26 = iVar26 + 0x1b;
      (*(uint *)((char *)frame_ + 488)) = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | (*(uint *)((char *)frame_ + 488));
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      (*(uint * *)((char *)frame_ + 8)) = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r20 = *(*(uint * *)((char *)frame_ + 8));
      (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    }
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,(*(uint ******* *)((char *)frame_ + 49528)),unaff_r20,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 484))) != 0) {
      iVar26 = iVar26 + 4;
    }
    (*(uint ****** *)((char *)frame_ + 28)) = (uint ******)*(*(uint * *)((char *)frame_ + 8));
    puVar34 = (*(uint * *)((char *)frame_ + 8)) + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 28)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)(*(uint * *)((char *)frame_ + 8))[1];
      puVar34 = (*(uint * *)((char *)frame_ + 8)) + 2;
    }
    (*(uint * *)((char *)frame_ + 8)) = puVar34;
    pppppppuVar19 = (*(uint ******* *)((char *)frame_ + 49528));
    ((int (*)())FUN_000c87d0)(&(*(uint ****** *)((char *)frame_ + 28)),&(*(uint ******* *)((char *)frame_ + 16)),(*(uint ******* *)((char *)frame_ + 49528)));
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    (*(int *)((char *)frame_ + 9364)) = (*(int *)((char *)frame_ + 9364)) + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 488))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 484)) << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      iVar26 = iVar26 + 0x1b;
      (*(uint *)((char *)frame_ + 488)) = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | (*(uint *)((char *)frame_ + 488));
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      (*(uint * *)((char *)frame_ + 8)) = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r19 = *(*(uint * *)((char *)frame_ + 8));
      (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    }
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,(*(uint ******* *)((char *)frame_ + 49528)),unaff_r19,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & (*(uint *)((char *)frame_ + 484))) != 0) {
      iVar26 = iVar26 + 4;
    }
    (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)*(*(uint * *)((char *)frame_ + 8));
    puVar34 = (*(uint * *)((char *)frame_ + 8)) + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 28)) = (uint ******)(*(uint * *)((char *)frame_ + 8))[1];
      puVar34 = (*(uint * *)((char *)frame_ + 8)) + 2;
    }
    ((uint *)((char *)frame_ + 20))[0] = *puVar34;
    (*(uint * *)((char *)frame_ + 8)) = puVar34 + 1;
    if ((((uint *)((char *)frame_ + 20))[0] & 0x400000) != 0) {
      ((uint *)((char *)frame_ + 32))[0] = puVar34[1];
      (*(uint * *)((char *)frame_ + 8)) = puVar34 + 2;
    }
    ((int (*)())FUN_000c87d0)(&(*(uint ******* *)((char *)frame_ + 16)),&(*(uint ****** *)((char *)frame_ + 28)),(*(uint ******* *)((char *)frame_ + 49528)));
    pppppppuVar19 = (*(uint ******* *)((char *)frame_ + 49528));
    ((int (*)())FUN_000c87d0)(((uint *)((char *)frame_ + 20)),((uint *)((char *)frame_ + 32)),(*(uint ******* *)((char *)frame_ + 49528)));
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    goto switchD_000cb23c_caseD_18;
  }
  pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
  (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8910)(puVar34,uVar29,1,&local_c08c);
  puVar23 = (*(uint * *)((char *)frame_ + 8));
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar36;
  puVar22 = puVar23;
  pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
  if (puVar40 + iVar46 <= puVar22) {
    uVar35 = uVar35 >> 2;
    (*(uint *)((char *)frame_ + 380)) = uVar21 | (*(uint *)((char *)frame_ + 380));
LAB_000cc88c:
    if ((*(int *)((char *)frame_ + 9020)) != 0) {
      _free(puVar34);
      return (*(int *)((char *)frame_ + 9020));
    }
    if (((*(int *)((char *)frame_ + 448)) == 0) || ((*(uint *)((char *)frame_ + 468)) == 0x11)) {
      *(undefined1 *)(param_2 + 0x7a6) = 0;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7a6) = 1;
      *(undefined1 *)((int)param_2 + 0x1e2f) = 1;
      param_2[0x7a4] = (*(uint *)((char *)frame_ + 468)) + 2;
      param_3[0x2e] = (uint ******)((*(int *)((char *)frame_ + 460)) + param_2[0x7c7]);
      param_3[0x2f] = (uint ******)((*(int *)((char *)frame_ + 464)) + param_2[0x7c7]);
    }
    if (((*(int *)((char *)frame_ + 472)) == 0) || ((*(int *)((char *)frame_ + 476)) == 0x11)) {
      *(undefined1 *)((int)param_2 + 0x1e2e) = 0;
    }
    else {
      param_2[0x7a3] = (*(int *)((char *)frame_ + 476)) + 2;
      *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
    }
    if ((*(uint ****** *)((char *)frame_ + 9328)) == (uint ******)0x0) {
      *(undefined1 *)(param_2 + 0x7a8) = 0;
    }
    else {
      param_2[0x7a3] = (*(int *)((char *)frame_ + 480));
      param_3[0x38] = (uint ******)((*(int *)((char *)frame_ + 9336)) + param_2[0x7c7]);
      param_3[0x39] = (uint ******)((*(int *)((char *)frame_ + 9340)) + param_2[0x7c7]);
      *(undefined1 *)(param_2 + 0x7a8) = 1;
    }
    if ((*(int *)((char *)frame_ + 9116)) == 0) {
      *(undefined1 *)((int)param_2 + 0x1efd) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x1efd) = 1;
    }
    if ((*(int *)((char *)frame_ + 9120)) == 0) {
      *(undefined1 *)(param_2 + 0x7c1) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x7c1) = 1;
    }
    iVar46 = 8;
    uVar21 = 0;
    pppppppuVar28 = param_3 + 0x2c;
    pppppppuVar19 = param_3;
    do {
      if ((1 << (uVar21 & 0x3f) & (*(uint *)((char *)frame_ + 380))) == 0) {
        *(undefined1 *)(pppppppuVar19 + 0x2c) = 0;
      }
      else if (((*(int *)((char *)frame_ + 448)) == 0) || ((*(uint *)((char *)frame_ + 468)) != uVar21)) {
        *(undefined1 *)(pppppppuVar19 + 0x2c) = 1;
      }
      else {
        *(undefined1 *)pppppppuVar28 = 0;
      }
      uVar21 = uVar21 + 1;
      pppppppuVar28 = (uint *******)((int)pppppppuVar28 + 1);
      pppppppuVar19 = (uint *******)((int)pppppppuVar19 + 1);
      iVar46 = iVar46 + -1;
    } while (iVar46 != 0);
    param_2[0x7a9] = 0;
    param_3[0x36] = (uint ******)0x0;
    uVar21 = 0;
    iVar46 = 0x10;
    *(undefined4 *)(((unsigned char *)0x000010e0) + (int)*param_3) = (*(undefined4 *)((char *)frame_ + 556));
    piVar18 = (*(int * *)((char *)frame_ + 49536));
    piVar44 = param_2;
    piVar32 = param_2;
    do {
      uVar12 = 1 << (uVar21 & 0x3f);
      if ((uVar12 & (*(uint *)((char *)frame_ + 748))) == 0) {
        *(undefined1 *)(piVar32 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar32 + 0x582) = 1;
      }
      if ((uVar12 & (*(uint *)((char *)frame_ + 484))) == 0) {
        *(undefined1 *)(piVar32 + 0x586) = 0;
      }
      else {
        *(undefined1 *)(piVar32 + 0x586) = 1;
        param_2[0x7a9] = 1;
        piVar44[0x7aa] = piVar18[-0x860] + param_2[0x7c7];
      }
      uVar21 = uVar21 + 1;
      piVar44[0x572] = *piVar18;
      piVar44 = piVar44 + 1;
      piVar2 = piVar18 + 0x10;
      piVar18 = piVar18 + 1;
      *(char *)(piVar32 + 0x56e) = (char)*piVar2;
      fVar10 = FLOAT_001aa0e8;
      piVar32 = (int *)((int)piVar32 + 1);
      iVar46 = iVar46 + -1;
    } while (iVar46 != 0);
    iVar46 = 0;
    piVar18 = param_2;
    piVar44 = param_2;
    do {
      if (((!bVar3) && (*(char *)(piVar44 + 0x586) != '\0')) &&
         (iVar47 = *(int *)(((unsigned char *)0x000013f8) + iVar46 * 4 + *param_2), iVar47 != 0)) {
        ((void (*)())FUN_000c8e30)(*param_3,(int)param_3[0x36] + (piVar18[0x7aa] - param_2[0x7c7]),
                     (double)(fVar10 / *(float *)(iVar47 + 0x44)),
                     (double)(fVar10 / *(float *)(iVar47 + 0x48)),(double)*(float *)(iVar47 + 0x50),
                     (double)FLOAT_001aa0e8);
      }
      bVar5 = iVar46 != 0xf;
      piVar18 = piVar18 + 1;
      piVar44 = (int *)((int)piVar44 + 1);
      iVar46 = iVar46 + 1;
    } while (bVar5);
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    iVar46 = 0;
    puVar40 = ((uint *)((char *)frame_ + 4892));
    puVar38 = ((undefined1 *)((char *)frame_ + 788));
    puVar37 = ((undefined1 *)((char *)frame_ + 4916));
    do {
      puVar45 = (undefined4 *)(puVar37 + 8);
      pfVar41 = (float *)(puVar38 + 8);
      uVar21 = 0;
      iVar47 = iVar46 << 2;
      do {
        uVar12 = 1 << (uVar21 & 0x3f);
        if ((uVar12 & puVar40[-0x408]) != 0) {
          ((void (*)())FUN_000c8e30)(*param_3,iVar46 + uVar21,(double)*pfVar41,(double)pfVar41[1],
                       (double)pfVar41[2],(double)pfVar41[3]);
        }
        if ((uVar12 & *puVar40) != 0) {
          uVar33 = puVar45[1];
          uVar29 = *puVar45;
          iVar26 = iVar47 + (int)*param_3;
          ((unsigned char *)0x000036c9)[iVar26] = (char)puVar45[2];
          ((unsigned char *)0x000036cb)[iVar26] = (char)uVar29;
          ((unsigned char *)0x000036ca)[iVar26] = (char)uVar33;
        }
        bVar3 = uVar21 != 0x1f;
        iVar47 = iVar47 + 4;
        puVar45 = puVar45 + 4;
        pfVar41 = pfVar41 + 4;
        uVar21 = uVar21 + 1;
      } while (bVar3);
      bVar3 = iVar46 != 0xe0;
      puVar37 = puVar37 + 0x200;
      puVar38 = puVar38 + 0x200;
      puVar40 = puVar40 + 1;
      iVar46 = iVar46 + 0x20;
    } while (bVar3);
    *(uint *)(((unsigned char *)0x00003748) + (int)*param_3) = ((uint *)((char *)frame_ + 4892))[0];
    _memset(auStack_c148,0,0xbc);
    _memset(auStack_9d1c,0,0x9c88);
    iVar46 = _malloc(param_5[1]);
    if (iVar46 == 0) {
      return -1;
    }
    _memset(iVar46,0,param_5[1]);
    local_c0f8 = uVar35 << 2;
    puVar23 = local_c080;
    puVar40 = local_c0f0;
    iVar47 = 8;
    local_c090 = iVar46;
    do {
      uVar21 = *puVar23;
      uVar35 = puVar23[8];
      puVar23 = puVar23 + 1;
      *puVar40 = uVar21;
      puVar40[8] = uVar35;
      puVar40 = puVar40 + 1;
      iVar47 = iVar47 + -1;
    } while (iVar47 != 0);
    local_c100 = ((uint *)((char *)frame_ + 104));
    (*(undefined4 *)((char *)frame_ + 9516)) = 0x40;
    ((uint *)((char *)frame_ + 104))[0] = ((uint *)((char *)frame_ + 104))[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar34;
    (*(int *)((char *)frame_ + 9540)) = _malloc(0x900);
    /* issue #64 live-repro (crash #6, past the iVar47-mask fix): (*(uint *)((char *)frame_ + 9528)) - the record count
     * later used as this loop's bound (`uVar21 = (*(uint *)((char *)frame_ + 9528)); ... while (uVar35 < uVar21)`,
     * below) - is read in several places but WRITTEN nowhere in this entire function; the only
     * thing ever done with its companion buffer is this _malloc(0x900) (64 records of 0x24
     * bytes each) with no populating writes anywhere in this 4600-line function either. A
     * freshly malloc'd, never-populated record list has zero valid entries, so the natural,
     * safe count is 0 - but nothing sets it, leaving it as raw uninitialized stack garbage.
     * Live-verified on real hardware: (*(uint *)((char *)frame_ + 9528)) read back as 3221123400 (0xC000FE48), driving
     * the consumption loop far past the (empty) buffer into unrelated memory, reading a garbage
     * piVar18[0] (e.g. 4249536) used as an array index and crashing on the resulting wild
     * write. Initialized to 0 to match the buffer's real (empty) population state.
     *
     * The exact same defect class recurs at (*(int *)((char *)frame_ + 9704)) just below (used the identical way -
     * `if ((*(int *)((char *)frame_ + 9704)) != 0) { pcVar31 = ((char *)((char *)frame_ + 9708)); do { ... } while (--(*(int *)((char *)frame_ + 9704)) != 0); }`
     * over its own never-populated buffer ((char *)((char *)frame_ + 9708))) - also never written anywhere in this
     * function. Live-verified: it crashed next, reading through pcVar31 at address 0xc0000000.
     * Fixed the same way, for the same reason. */
    (*(uint *)((char *)frame_ + 9528)) = 0;
    (*(int *)((char *)frame_ + 9704)) = 0;
    iVar47 = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (iVar47 != 0) {
      return 2;
    }
    iVar47 = 0;
    puVar37 = ((undefined1 *)((char *)frame_ + 11056));
    do {
      _memcpy((int)param_3[3] + iVar47,puVar37,0x48);
      ppppppuVar15 = param_3[3];
      if ((*(int *)(iVar47 + (int)ppppppuVar15) == 1) &&
         (*(char *)((int)ppppppuVar15 + iVar47 + 8) == '\x0f')) {
        *(char *)((int)ppppppuVar15 + iVar47 + 8) = (char)(*(int *)((char *)frame_ + 476));
      }
      iVar47 = iVar47 + 0x48;
      puVar37 = puVar37 + 0x48;
    } while (iVar47 != 0x9360);
    iVar20 = 0;
    iVar47 = 0;
    iVar26 = 0;
    iVar43 = 0x1a20;
    piVar18 = param_2 + 0x594;
    do {
      uVar21 = *(uint *)((int)((uint *)((char *)frame_ + 9596)) + iVar47) | *(uint *)((int)(*(uint ******* *)((char *)frame_ + 49528)) + iVar47 + 0x188);
      *(uint *)(((unsigned char *)0x000010b8) + (int)(*param_3 + iVar20)) = uVar21;
      if (uVar21 != 0) {
        iVar24 = param_2[0x7c7];
        pbVar25 = (byte *)(piVar18 + 2);
        piVar44 = (int *)((int)param_2 + iVar43);
        iVar30 = iVar26;
        do {
          bVar7 = (byte)uVar21;
          uVar21 = uVar21 >> 1;
          iVar16 = iVar30 + iVar24;
          *pbVar25 = bVar7 & 1;
          iVar30 = iVar30 + 1;
          pbVar25 = pbVar25 + 1;
          *piVar44 = iVar16;
          piVar44 = piVar44 + 1;
        } while (uVar21 != 0);
      }
      bVar3 = iVar20 != 7;
      iVar47 = iVar47 + 4;
      iVar26 = iVar26 + 0x20;
      piVar18 = piVar18 + 8;
      iVar43 = iVar43 + 0x80;
      iVar20 = iVar20 + 1;
    } while (bVar3);
    if (*(int *)(((unsigned char *)0x000010b8) + (int)*param_3) == 0) {
      *(undefined4 *)(((unsigned char *)0x000010d8) + (int)*param_3) = 0;
    }
    for (; (*(int *)((char *)frame_ + 48872)) != 0; (*(int *)((char *)frame_ + 48872)) = (*(int *)((char *)frame_ + 48872)) + -1) {
    }
    if ((*(uint *)((char *)frame_ + 9528)) != 0) {
      uVar35 = 0;
      uVar21 = (*(uint *)((char *)frame_ + 9528));
      do {
        piVar18 = (int *)(uVar35 * 0x24 + (*(int *)((char *)frame_ + 9540)));
        switch(piVar18[2]) {
        case 1:
          iVar47 = piVar18[1];
          ppppppuVar15 = *param_3;
          iVar26 = *piVar18;
          /* issue #64 live-repro (crash #5, past the local_2c-cluster fix): this if-chain
           * checks iVar47 (piVar18[1]) against exactly {1,0,2,3}, each mapping to one of 4
           * consecutive byte offsets (0x24,0x23,0x25,0x26 respectively - i.e. really just
           * `0x23 + iVar47` for iVar47 in that 2-bit range), but leaves ppppppuVar17 NULL for
           * any other value - a classic decompiled-masked-switch defect (Ghidra shows the
           * post-mask compares but drops the `& 3` itself; this project already carries
           * Tools/userspace/switch_ranges.py for the general form of this class). Live-verified
           * on real hardware: piVar18[1] held 128 (0x80) in a real run - not garbage, since
           * piVar18[2]==1 correctly selected this case and piVar18[0]==3 was a sane iVar26 -
           * and its low 2 bits (128 & 3 == 0) are exactly the "iVar47==0" case per the pattern
           * above, so the field is genuinely wider than 2 bits and this chain must mask it
           * before comparing. Rewritten to mask first; behavior for the four originally-
           * handled raw values (0-3, already within the mask's range) is unchanged. */
          iVar47 = iVar47 & 3;
          if (iVar47 == 1) {
            ppppppuVar17 = ppppppuVar15 + iVar26 * 4 + 0x24;
          }
          else if (iVar47 == 0) {
            ppppppuVar17 = ppppppuVar15 + iVar26 * 4 + 0x23;
          }
          else if (iVar47 == 2) {
            ppppppuVar17 = ppppppuVar15 + iVar26 * 4 + 0x25;
          }
          else {
            ppppppuVar17 = ppppppuVar15 + iVar26 * 4 + 0x26;
          }
          *ppppppuVar17 = (uint *****)piVar18[5];
          uVar21 = (*(uint *)((char *)frame_ + 9528));
          break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
          ((int (*)())FUN_000c8de0)(param_3 + 0x48,piVar18);
          uVar21 = (*(uint *)((char *)frame_ + 9528));
        }
        uVar35 = uVar35 + 1;
      } while (uVar35 < uVar21);
    }
    if ((*(int *)((char *)frame_ + 9704)) != 0) {
      iVar47 = 0;
      pcVar31 = ((char *)((char *)frame_ + 9708));
      if ((*(int *)((char *)frame_ + 9704)) == 0) {
        (*(int *)((char *)frame_ + 9704)) = 1;
      }
      do {
        cVar6 = *pcVar31;
        pcVar31 = pcVar31 + 0xc;
        if (cVar6 != '\x02') {
          iVar47 = iVar47 + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = (*(int *)((char *)frame_ + 476)) + 2;
        }
        (*(int *)((char *)frame_ + 9704)) = (*(int *)((char *)frame_ + 9704)) + -1;
      } while ((*(int *)((char *)frame_ + 9704)) != 0);
      iVar26 = 1;
      if (8 < iVar47) goto LAB_000ccf90;
    }
    iVar26 = 0;
LAB_000ccf90:
    iVar20 = 0x10;
    iVar47 = 0;
    do {
      param_3[1][iVar47 * 4 + 0x42] = (uint *****)0x0;
      param_3[1][iVar47 * 4 + 0x43] = (uint *****)0x1;
      param_3[1][iVar47 * 4 + 0x44] = (uint *****)0x2;
      param_3[1][iVar47 * 4 + 0x45] = (uint *****)0x3;
      iVar20 = iVar20 + -1;
      iVar47 = iVar47 + 1;
    } while (iVar20 != 0);
    _free((*(int *)((char *)frame_ + 9540)));
    _free(iVar46);
    if (iVar13 != 0) {
      _free(iVar13);
    }
    if (puVar34 != (uint *)0x0) {
      _free(puVar34);
    }
    return iVar26;
  }
  ppppppuVar15 = (uint ******)*puVar22;
  uVar12 = (uint)ppppppuVar15 & 0xffff;
  if (100 < uVar12) {
switchD_000cb23c_caseD_0:
                    
    _exit(0);
  }
  puVar23 = puVar22;
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
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 12)),(*(uint ******* *)((char *)frame_ + 49528)),pppppppuVar19,puVar22,puVar22,in_r8,(*(uint ******* *)((char *)frame_ + 49528)),
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 12)),&(*(uint * *)((char *)frame_ + 8)),1,1,(*(uint ******* *)((char *)frame_ + 49528)));
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
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
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 12)),(*(uint ******* *)((char *)frame_ + 49528)),pppppppuVar19,puVar22,puVar22,in_r8,(*(uint ******* *)((char *)frame_ + 49528)),
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 12)),&(*(uint * *)((char *)frame_ + 8)),1,2,(*(uint ******* *)((char *)frame_ + 49528)));
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar19 = (uint *******)0x0;
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 12)),&(*(uint * *)((char *)frame_ + 8)),0,2,&local_c08c);
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 2;
    (*(uint ******* *)((char *)frame_ + 12))[1] = (uint ******)puVar22[1];
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    (*(uint ******* *)((char *)frame_ + 12))[1] = (uint ******)puVar22[1];
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 3;
    (*(uint ******* *)((char *)frame_ + 12))[2] = (uint ******)puVar22[2];
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 3;
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 3;
    goto switchD_000cbc48_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 12)),(*(uint ******* *)((char *)frame_ + 49528)),pppppppuVar19,puVar22,puVar22,in_r8,(*(uint ******* *)((char *)frame_ + 49528)),
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 12)),&(*(uint * *)((char *)frame_ + 8)),1,3,(*(uint ******* *)((char *)frame_ + 49528)));
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 2;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    (*(uint ******* *)((char *)frame_ + 12))[1] = (uint ******)puVar22[1];
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    for (uVar12 = (uint)*(ushort *)((int)puVar22 + 6); puVar23 = (*(uint * *)((char *)frame_ + 8)), uVar12 != 0;
        uVar12 = uVar12 - 1) {
      ppppppuVar15 = (uint ******)*(*(uint * *)((char *)frame_ + 8));
      (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
      *pppppppuVar36 = ppppppuVar15;
      pppppppuVar36 = pppppppuVar36 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    if (((uint)ppppppuVar15 & 0x18000000) == 0) {
      uVar12 = *(uint *)((int)((uint *)((char *)frame_ + 9260)) + ((uint)ppppppuVar15 >> 0xe & 0x3fc));
      if (uVar12 != 2) {
        uVar12 = 1;
      }
      ppppppuVar15 = (uint ******)((uVar12 & 3) << 0x1b | (uint)ppppppuVar15 & 0xe7ffffff);
    }
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if ((int)ppppppuVar15 < 0) {
      ppppppuVar15 = (uint ******)*(*(uint * *)((char *)frame_ + 8));
      (*(uint * *)((char *)frame_ + 8)) = puVar22 + 2;
      (*(uint ******* *)((char *)frame_ + 12))[1] = ppppppuVar15;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar28;
    ppppppuVar15 = (uint ******)*(*(uint * *)((char *)frame_ + 8));
    (*(uint * *)((char *)frame_ + 8)) = (*(uint * *)((char *)frame_ + 8)) + 1;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar28 = pppppppuVar36;
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    pppppppuVar19 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = pppppppuVar19;
    if ((puVar22[1] >> 0x10 & 0x3f) - 1 < 2) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = (uint ******)puVar22[1];
      in_r8 = (*(uint ******* *)((char *)frame_ + 12)) + 6;
      (*(uint ******* *)((char *)frame_ + 12))[2] = (uint ******)puVar22[2];
      (*(uint ******* *)((char *)frame_ + 12))[3] = (uint ******)puVar22[3];
      (*(uint ******* *)((char *)frame_ + 12))[4] = (uint ******)puVar22[4];
      (*(uint * *)((char *)frame_ + 8)) = puVar22 + 6;
      (*(uint ******* *)((char *)frame_ + 12))[5] = (uint ******)puVar22[5];
      puVar23 = (*(uint * *)((char *)frame_ + 8));
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 5;
      pppppppuVar36 = in_r8;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    puVar45 = (undefined4 *)
              ((int (*)())FUN_000c7930)((*(uint ******* *)((char *)frame_ + 12)),&local_c08c,pppppppuVar19,puVar22,(*(uint * *)((char *)frame_ + 8)),in_r8,uVar12 * 4)
    ;
    *puVar45 = ppppppuVar15;
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (uint *******)(puVar45 + 1);
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 2;
    ((uint ****** *)((char *)frame_ + 64))[0] = (uint ******)puVar22[1];
    (*(uint ******* *)((char *)frame_ + 12)) = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    ((int (*)())FUN_000c8760)(((uint ****** *)((char *)frame_ + 64)),((undefined1 *)((char *)frame_ + 76)),pppppppuVar19);
    *(*(uint ******* *)((char *)frame_ + 12)) = ((uint ****** *)((char *)frame_ + 64))[0];
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar19 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    break;
  case 0x5d:
    (*(uint ******* *)((char *)frame_ + 49528)) = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 12)),(*(uint ******* *)((char *)frame_ + 49528)),pppppppuVar19,puVar22,puVar22,in_r8,(*(uint ******* *)((char *)frame_ + 49528)),
                                pppppppuVar28);
      puVar22 = (*(uint * *)((char *)frame_ + 8));
    }
    ppppppuVar15 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar27 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar23 = puVar22 + 2;
      ppppppuVar17 = (uint ******)puVar22[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 >> 0x1e & 1) != 0;
    if (bVar1) {
      ppppppuVar39 = (uint ******)*puVar23;
      puVar23 = puVar23 + 1;
    }
    else {
      ppppppuVar39 = (uint ******)0x0;
    }
    (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      unaff_r15 = (uint ******)puVar23[1];
    }
    (*(uint ****** *)((char *)frame_ + 52)) = (uint ******)*puVar22;
    (*(uint * *)((char *)frame_ + 8)) = puVar22 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 52)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 40)) = (uint ******)puVar22[1];
      (*(uint * *)((char *)frame_ + 8)) = puVar22 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc2a4:
      if ((*(uint *)((char *)frame_ + 484)) << (uVar12 & 0x3f) == 0) {
        (*(uint ****** *)((char *)frame_ + 49532)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 52));
        pppppppuVar36 = (uint *******)0x0;
        uVar42 = 1 << (uVar12 & 0x3f);
        ppppppuVar14 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
      }
      else {
        (*(uint ****** *)((char *)frame_ + 49532)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 52));
        (*(uint ****** *)((char *)frame_ + 49552)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
        (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)((int (*)())FUN_000c7460)((*(uint ******* *)((char *)frame_ + 49528)),(*(uint ****** *)((char *)frame_ + 49532)),(*(uint ****** *)((char *)frame_ + 49552)),uVar27,(*(uint ******* *)((char *)frame_ + 12)));
        ppppppuVar14 = (*(uint ****** *)((char *)frame_ + 49552));
        if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) == 0) {
          pppppppuVar36 = (uint *******)0x0;
          uVar42 = 1 << (uVar12 & 0x3f);
        }
        else {
          (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0xffbfffff);
          pppppppuVar36 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          (*(uint ****** *)((char *)frame_ + 28)) = unaff_r15;
        }
      }
    }
    else if (uVar9 == 0x8000000) {
      uVar42 = 1 << (uVar12 & 0x3f);
      if ((uVar42 & (*(uint *)((char *)frame_ + 488))) != 0) goto LAB_000cc2a4;
      (*(uint ****** *)((char *)frame_ + 49532)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 52));
      pppppppuVar36 = (uint *******)0x0;
      ppppppuVar14 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
    }
    else {
      pppppppuVar36 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
      (*(uint ****** *)((char *)frame_ + 49532)) = (uint ******)&(*(uint ****** *)((char *)frame_ + 52));
      ppppppuVar14 = (uint ******)&(*(uint ****** *)((char *)frame_ + 40));
    }
    pppppppuVar19 = (*(uint ******* *)((char *)frame_ + 49528));
    ((int (*)())FUN_000c8760)((*(uint ****** *)((char *)frame_ + 49532)),ppppppuVar14,(*(uint ******* *)((char *)frame_ + 49528)));
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (bVar4) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = ppppppuVar17;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar28;
    if (bVar1) {
      *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar39;
      (*(uint ******* *)((char *)frame_ + 12)) = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    }
    *(*(uint ******* *)((char *)frame_ + 12)) = (uint ******)(*(uint ******* *)((char *)frame_ + 16));
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = unaff_r15;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar28;
    *(*(uint ******* *)((char *)frame_ + 12)) = (*(uint ****** *)((char *)frame_ + 52));
    pppppppuVar28 = (uint *******)((uint)(*(uint ****** *)((char *)frame_ + 52)) & 0x400000);
    pppppppuVar11 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = (*(uint ****** *)((char *)frame_ + 40));
      pppppppuVar11 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar11;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & (*(uint *)((char *)frame_ + 488))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 484)) << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&(*(uint ******* *)((char *)frame_ + 16));
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c7650)((*(uint ******* *)((char *)frame_ + 49528)),(*(uint ****** *)((char *)frame_ + 49532)),pppppppuVar19,&(*(uint ****** *)((char *)frame_ + 28)),uVar27,pppppppuVar36,
                                (*(uint ******* *)((char *)frame_ + 12)),pppppppuVar28);
      in_r8 = pppppppuVar36;
    }
    uVar42 = uVar42 & (*(uint *)((char *)frame_ + 484));
    ppppppuVar15 = unaff_r15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c8110)((*(uint ******* *)((char *)frame_ + 12)),&local_c08c,pppppppuVar19,puVar22,puVar22,in_r8,
                                uVar12 * 4,pppppppuVar28);
      puVar22 = (*(uint * *)((char *)frame_ + 8));
    }
    ppppppuVar15 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    uVar12 = (uint)ppppppuVar15 >> 0x10;
    uVar27 = uVar12 & 0xff;
    bVar4 = ((uint)ppppppuVar15 & 0x80000000) != 0;
    if (bVar4) {
      puVar23 = puVar22 + 2;
      ppppppuVar17 = (uint ******)puVar22[1];
    }
    else {
      ppppppuVar17 = (uint ******)0x0;
    }
    bVar1 = ((uint)ppppppuVar15 & 0x40000000) != 0;
    if (bVar1) {
      ppppppuVar39 = (uint ******)*puVar23;
      puVar23 = puVar23 + 1;
    }
    else {
      ppppppuVar39 = (uint ******)0x0;
    }
    (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      unaff_r14 = (uint ******)puVar23[1];
    }
    (*(uint ****** *)((char *)frame_ + 40)) = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 40)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 52)) = (uint ******)puVar22[1];
      puVar23 = puVar22 + 2;
    }
    (*(uint ****** *)((char *)frame_ + 44)) = (uint ******)*puVar23;
    (*(uint * *)((char *)frame_ + 8)) = puVar23 + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 44)) & 0x400000) != 0) {
      (*(uint ****** *)((char *)frame_ + 56)) = (uint ******)puVar23[1];
      (*(uint * *)((char *)frame_ + 8)) = puVar23 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc588:
      if ((*(uint *)((char *)frame_ + 484)) << (uVar12 & 0x3f) != 0) {
        pppppppuVar19 = &(*(uint ****** *)((char *)frame_ + 52));
        (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                     ((int (*)())FUN_000c7460)(&local_c08c,&(*(uint ****** *)((char *)frame_ + 40)),pppppppuVar19,uVar27,(*(uint ******* *)((char *)frame_ + 12)));
        if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
          (*(uint ******* *)((char *)frame_ + 16)) = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0xffbfffff);
          in_r8 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          (*(uint ****** *)((char *)frame_ + 28)) = unaff_r14;
          goto LAB_000cc5e4;
        }
      }
LAB_000cc5bc:
      in_r8 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
    }
    else {
      if (uVar9 != 0x8000000) goto LAB_000cc5bc;
      in_r8 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
      if ((uVar42 & (*(uint *)((char *)frame_ + 488))) != 0) goto LAB_000cc588;
    }
LAB_000cc5e4:
    *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar15;
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (bVar4) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = ppppppuVar17;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar28;
    if (bVar1) {
      *(*(uint ******* *)((char *)frame_ + 12)) = ppppppuVar39;
      (*(uint ******* *)((char *)frame_ + 12)) = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    }
    *(*(uint ******* *)((char *)frame_ + 12)) = (uint ******)(*(uint ******* *)((char *)frame_ + 16));
    pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = unaff_r14;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar28;
    *(*(uint ******* *)((char *)frame_ + 12)) = (*(uint ****** *)((char *)frame_ + 40));
    pppppppuVar28 = (uint *******)((uint)(*(uint ****** *)((char *)frame_ + 40)) & 0x400000);
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = (*(uint ****** *)((char *)frame_ + 52));
      pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar36;
    *(*(uint ******* *)((char *)frame_ + 12)) = (*(uint ****** *)((char *)frame_ + 44));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
    if (((uint)(*(uint ****** *)((char *)frame_ + 44)) & 0x400000) != 0) {
      (*(uint ******* *)((char *)frame_ + 12))[1] = (*(uint ****** *)((char *)frame_ + 56));
      pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 2;
    }
    (*(uint ******* *)((char *)frame_ + 12)) = pppppppuVar36;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & (*(uint *)((char *)frame_ + 488))) != 0)))) &&
       ((*(uint *)((char *)frame_ + 484)) << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&(*(uint ******* *)((char *)frame_ + 16));
      (*(uint ******* *)((char *)frame_ + 12)) = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_c08c,&(*(uint ****** *)((char *)frame_ + 40)),pppppppuVar19,&(*(uint ****** *)((char *)frame_ + 28)),uVar27,in_r8,
                                (*(uint ******* *)((char *)frame_ + 12)),pppppppuVar28);
    }
    uVar42 = uVar42 & (*(uint *)((char *)frame_ + 484));
    ppppppuVar15 = unaff_r14;
joined_r0x000cc708:
    puVar23 = (*(uint * *)((char *)frame_ + 8));
    pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
    if (uVar42 != 0) {
      in_r8 = (*(uint ******* *)((char *)frame_ + 12)) + 1;
      *(*(uint ******* *)((char *)frame_ + 12)) = (uint ******)0x47;
      pppppppuVar28 = (*(uint ******* *)((char *)frame_ + 16));
      if (((uint)(*(uint ******* *)((char *)frame_ + 16)) & 0x400000) == 0) {
        pppppppuVar28 = (uint *******)((uint)(*(uint ******* *)((char *)frame_ + 16)) | 0x400000);
        ppppppuVar15 = (uint ******)0x55;
      }
      if (((uint *)((char *)frame_ + 620))[uVar27] == 0x1906) {
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
      else if ((((uint *)((char *)frame_ + 620))[uVar27] == 0x1909) && (((uint)ppppppuVar15 & 0xc0) == 0x40)) {
        ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffff3f | 0xc0);
      }
      *in_r8 = (uint ******)pppppppuVar28;
      (*(uint ******* *)((char *)frame_ + 12))[2] = ppppppuVar15;
      (*(uint ******* *)((char *)frame_ + 12))[3] = (uint ******)((uint)pppppppuVar28 & 0x3fffff);
      pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12)) + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  (*(uint * *)((char *)frame_ + 8)) = (uint *)((int (*)())FUN_000c8aa0)(&(*(uint ******* *)((char *)frame_ + 12)),&(*(uint * *)((char *)frame_ + 8)),pppppppuVar19,1,&local_c08c);
  puVar23 = (*(uint * *)((char *)frame_ + 8));
  pppppppuVar36 = (*(uint ******* *)((char *)frame_ + 12));
  goto switchD_000cbc48_caseD_18;
}
#undef local_c08c
#undef local_c080
#undef local_c070
#undef local_c06c
#undef local_c068
#undef local_c064
#undef local_c060
#undef local_c050
#undef local_c04c
#undef local_c048
#undef local_c044

/* FUN_000cd05c @ 0xcd05c (176 bytes) */
int FUN_000cd05c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  int a1;
  int iVar1;
  
  if ((((((param_1 == 0) || (*(code **)(param_1 + 0x30) == (code *)0x0)) ||
        (*(int *)(param_1 + 0x34) == 0)) ||
       ((*(int *)(param_1 + 0x38) == 0 || (*(int *)(param_1 + 0x40) == 0)))) ||
      ((*(int *)(param_1 + 0x44) == 0 ||
       ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x4c) == 0)))))) ||
     ((param_2 == 0 ||
      (a1 = (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x2c),0x44,param_3), a1 == 0))))
  {
    a1 = 0;
  }
  else {
    FUN_000da0c0(a1,param_1);
    iVar1 = FUN_000da420(a1);
    if (iVar1 != 0) {
      FUN_000da458(a1,1);
      (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0x2c),a1,param_3);
      a1 = 0;
    }
  }
  return a1;
}

/* FUN_000cd154 @ 0xcd154 (92 bytes) */
int FUN_000cd154(param_1)
  undefined4 *param_1;
{
  undefined4 uVar1;
  code *pcVar2;
  
  uVar1 = 3;
  if (param_1 != (undefined4 *)0x0) {
    pcVar2 = (code *)*param_1;
    uVar1 = param_1[1];
    FUN_000da458(param_1,1);
    (*pcVar2)(uVar1,param_1);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  return ((int (*)())FUN_000cd388)(param_1,param_2,param_3,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  return ((int (*)())FUN_000cd404)(param_1,param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7,param_8);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  return ((int (*)())FUN_000cdba4)(param_1,param_2,param_3,param_4,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)),param_6,param_7);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  return ((int (*)())FUN_000cdbe4)(param_1,param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7);
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
  return FUN_000e06d8(param_1,param_2,param_3,param_4);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  return (*(code *)*param_2)(param_1,"",param_3,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)),param_5,param_6,param_7,param_8);
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
  unsigned int frame_[144] __attribute__((aligned(16)));
  
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
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((char *)((char *)frame_ + 8)),(double)*(float *)(param_2[0xc] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 136)),(double)*(float *)(param_2[0xc] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 264)),(double)*(float *)(param_2[0xc] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 392)),(double)*(float *)(param_2[0xc] + iVar3 + 0xc));
      param_5 = ((char *)((char *)frame_ + 8));
      uVar4 = uVar2 + 1;
      param_6 = ((undefined1 *)((char *)frame_ + 136));
      param_7 = ((undefined1 *)((char *)frame_ + 264));
      param_8 = ((undefined1 *)((char *)frame_ + 392));
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           ((undefined1 *)((char *)frame_ + 136)),((undefined1 *)((char *)frame_ + 264)),((undefined1 *)((char *)frame_ + 392)));
    } while (uVar4 < (uint)param_2[0xf]);
  }
  if (((param_2[0x10] != 0) && (param_2[0xd] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float PS Constants",uVar2,
                           param_5,param_6,param_7,param_8), param_2[0x10] != 0)) {
    uVar4 = 0;
    do {
      uVar2 = uVar4;
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((char *)((char *)frame_ + 8)),(double)*(float *)(param_2[0xd] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 136)),(double)*(float *)(param_2[0xd] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 264)),(double)*(float *)(param_2[0xd] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 392)),(double)*(float *)(param_2[0xd] + iVar3 + 0xc));
      param_5 = ((char *)((char *)frame_ + 8));
      uVar4 = uVar2 + 1;
      param_6 = ((undefined1 *)((char *)frame_ + 136));
      param_7 = ((undefined1 *)((char *)frame_ + 264));
      param_8 = ((undefined1 *)((char *)frame_ + 392));
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           ((undefined1 *)((char *)frame_ + 136)),((undefined1 *)((char *)frame_ + 264)),((undefined1 *)((char *)frame_ + 392)));
    } while (uVar4 < (uint)param_2[0x10]);
  }
  if (((param_2[0x11] != 0) && (param_2[0xe] != 0)) &&
     (uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"\r\nSC_SHADERSTATE: *** Float GS Constants",uVar2,
                           param_5,param_6,param_7,param_8), param_2[0x11] != 0)) {
    uVar2 = 0;
    do {
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((char *)((char *)frame_ + 8)),(double)*(float *)(param_2[0xe] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 136)),(double)*(float *)(param_2[0xe] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 264)),(double)*(float *)(param_2[0xe] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,((undefined1 *)((char *)frame_ + 392)),(double)*(float *)(param_2[0xe] + iVar3 + 0xc));
      param_5 = ((char *)((char *)frame_ + 8));
      uVar4 = uVar2 + 1;
      param_6 = ((undefined1 *)((char *)frame_ + 136));
      param_7 = ((undefined1 *)((char *)frame_ + 264));
      param_8 = ((undefined1 *)((char *)frame_ + 392));
      uVar1 = ((int (*)())FUN_000cd3a4)(param_1,param_3,"SC_SHADERSTATE: c%d = (%s,%s,%s,%s)\r\n",uVar2,param_5,
                           ((undefined1 *)((char *)frame_ + 136)),((undefined1 *)((char *)frame_ + 264)),((undefined1 *)((char *)frame_ + 392)));
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
  return FUN_000d4e8c(param_1,param_2,param_3,param_5,param_5,param_6,param_2);
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
  return FUN_000d4e64();
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
char * FUN_000cdc3c(undefined4 param_1,int param_2,char *param_3,double fparam_1)
{
  bool bVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  ((int *)((char *)frame_ + 12))[0] = 0;
  (*(uint *)((char *)frame_ + 8)) = 0;
  pcVar7 = _ecvt(fparam_1,param_2,(int *)&(*(uint *)((char *)frame_ + 8)),((int *)((char *)frame_ + 12)));
  bVar1 = ((int *)((char *)frame_ + 12))[0] != 0;
  if (bVar1) {
    *param_3 = '-';
  }
  uVar13 = (uint)bVar1;
  if (((int)(*(uint *)((char *)frame_ + 8)) < 1 - param_2) || (param_2 < (int)(*(uint *)((char *)frame_ + 8)))) {
    param_3[bVar1] = *pcVar7;
    param_3[uVar13 + 1] = '.';
    iVar8 = uVar13 + 2;
    cVar6 = pcVar7[1];
    if (cVar6 != '\0') {
      pcVar9 = param_3 + iVar8;
      iVar4 = 1;
      do {
        *pcVar9 = cVar6;
        iVar4 = iVar4 + 1;
        cVar6 = pcVar7[iVar4];
        iVar8 = iVar8 + 1;
        pcVar9 = pcVar9 + 1;
      } while (cVar6 != '\0');
    }
    uVar13 = (*(uint *)((char *)frame_ + 8)) - 1;
    param_3[iVar8] = 'e';
    iVar4 = iVar8 + 1;
    if ((int)uVar13 < 0) {
      uVar13 = -uVar13;
      param_3[iVar4] = '-';
      iVar4 = iVar8 + 2;
    }
    (*(uint *)((char *)frame_ + 28)) = uVar13 ^ 0x80000000;
    (*(undefined4 *)((char *)frame_ + 24)) = 0x43300000;
    (*(uint *)((char *)frame_ + 8)) = uVar13;
    dVar14 = _log((double)(float)((double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 28))) - DOUBLE_001aa1e0));
    dVar15 = _log(DOUBLE_001aa238);
    dVar3 = DOUBLE_001aa1e8;
    dVar2 = DOUBLE_001aa1e0;
    dVar14 = dVar14 / dVar15;
    if (DOUBLE_001aa1e8 <= dVar14) {
      (*(longlong *)((char *)frame_ + 40)) = (longlong)(int)(dVar14 - DOUBLE_001aa1e8);
      uVar10 = (int)(dVar14 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar10 = (uint)(int)dVar14;
      (*(longlong *)((char *)frame_ + 32)) = (longlong)(int)uVar10;
    }
    uVar11 = 0;
    pcVar7 = param_3 + iVar4;
    uVar12 = uVar10;
    do {
      (*(uint *)((char *)frame_ + 52)) = uVar12 ^ 0x80000000;
      (*(undefined4 *)((char *)frame_ + 48)) = 0x43300000;
      dVar16 = (double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 52))) - dVar2;
      dVar15 = _pow(DOUBLE_001aa238,dVar16);
      dVar14 = DOUBLE_001aa238;
      if (dVar3 <= dVar15) {
        iVar8 = (int)(dVar15 - dVar3);
        (*(longlong *)((char *)frame_ + 64)) = (longlong)iVar8;
        uVar5 = iVar8 + 0x80000000;
      }
      else {
        uVar5 = (uint)(int)dVar15;
        (*(longlong *)((char *)frame_ + 56)) = (longlong)(int)uVar5;
      }
      cVar6 = (char)(uVar13 / uVar5);
      *pcVar7 = cVar6 + '0';
      dVar14 = _pow(dVar14,dVar16);
      if (DOUBLE_001aa1e8 <= dVar14) {
        (*(longlong *)((char *)frame_ + 80)) = (longlong)(int)(dVar14 - DOUBLE_001aa1e8);
        iVar8 = (int)(dVar14 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar8 = (int)dVar14;
        (*(longlong *)((char *)frame_ + 72)) = (longlong)iVar8;
      }
      uVar11 = uVar11 + 1;
      pcVar7 = pcVar7 + 1;
      uVar12 = uVar12 - 1;
      uVar13 = (*(uint *)((char *)frame_ + 8)) - cVar6 * iVar8;
      (*(uint *)((char *)frame_ + 8)) = uVar13;
    } while (uVar11 <= uVar10);
    param_3[uVar11 + iVar4] = '\0';
  }
  else {
    uVar10 = uVar13;
    if ((int)(*(uint *)((char *)frame_ + 8)) < 1) {
      param_3[bVar1] = '0';
      uVar10 = uVar13 + 2;
      param_3[uVar13 + 1] = '.';
      if ((int)(*(uint *)((char *)frame_ + 8)) < 0) {
        iVar8 = -(*(uint *)((char *)frame_ + 8));
        pcVar9 = param_3 + uVar10;
        if (0 < (int)((*(uint *)((char *)frame_ + 8)) + 1)) {
          iVar8 = 1;
        }
        do {
          *pcVar9 = '0';
          uVar10 = uVar10 + 1;
          pcVar9 = pcVar9 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      (*(uint *)((char *)frame_ + 8)) = 0xffffffff;
    }
    if (*pcVar7 != '\0') {
      uVar13 = 0;
      pcVar9 = pcVar7;
      do {
        if (uVar13 == (*(uint *)((char *)frame_ + 8))) {
          (*(uint *)((char *)frame_ + 8)) = 0xffffffff;
          param_3[uVar10] = '.';
          uVar10 = uVar10 + 1;
        }
        uVar13 = uVar13 + 1;
        param_3[uVar10] = *pcVar9;
        uVar10 = uVar10 + 1;
        pcVar9 = pcVar7 + uVar13;
      } while (pcVar7[uVar13] != '\0');
    }
    param_3[uVar10] = '\0';
    if ((*(uint *)((char *)frame_ + 8)) == 0xffffffff) {
      cVar6 = *param_3;
      uVar13 = uVar10;
      if (cVar6 != '\0') {
        iVar8 = 0;
        do {
          if (cVar6 != '0') {
            if (cVar6 == '.') {
              uVar13 = uVar10;
              if (iVar8 + 2U < uVar10) {
                uVar13 = iVar8 + 2U;
              }
            }
            else {
              uVar13 = iVar8 + 1;
            }
          }
          iVar8 = iVar8 + 1;
          cVar6 = param_3[iVar8];
        } while (cVar6 != '\0');
      }
      param_3[uVar13] = '\0';
    }
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char cVar1;
  char *pcVar2;
  unsigned int frame_[44] __attribute__((aligned(16)));
  
  if (*(int *)(param_1 + 8) != 0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
    FUN_001a34d4(((undefined1 *)((char *)frame_ + 12)),param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7,param_8);
    pcVar2 = (char *)_strchr(((undefined1 *)((char *)frame_ + 12)),0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    FUN_001a32d0(((undefined1 *)((char *)frame_ + 12)),"%s\n",((undefined1 *)((char *)frame_ + 12)),param_4,param_5,param_6,param_7,param_8);
    (*(code *)**(undefined4 **)(param_1 + 8))
              (*(undefined4 *)(param_1 + 0xc),"",((undefined1 *)((char *)frame_ + 12)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
  }
  return;
}

/* FUN_000ce148 @ 0xce148 (464 bytes) */
int FUN_000ce148(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  undefined1 *param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 in_r10;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  unsigned int frame_[20] __attribute__((aligned(16)));
  
  uVar6 = *param_2;
  uVar2 = uVar6 & 0x1e000000;
  uVar9 = uVar6 & 0x80000010;
  uVar3 = uVar6 & 0xf;
  uVar4 = uVar6 & 0x1ffe000;
  *param_3 = 0;
  uVar8 = uVar6 >> 0x1d;
  uVar10 = uVar6 >> 5;
  if (uVar2 == 0x1e000000) {
    uVar7 = 0;
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x2d00;
  }
  else {
    uVar7 = -uVar2 >> 0x1f;
  }
  if (uVar3 == 1) {
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x7600;
  }
  else if (uVar3 == 0) {
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x7200;
  }
  else if (uVar3 == 2) {
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x6300;
  }
  else if (uVar3 == 3) {
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x7400;
  }
  else {
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x3f00;
  }
  FUN_001a32d0(((undefined1 *)((char *)frame_ + 8)),"%d",uVar10 & 0xff,in_r6,in_r7,in_r8,uVar6,in_r10);
  if (uVar9 == 0) {
    _strcat(param_3,((undefined1 *)((char *)frame_ + 8)));
  }
  else {
    if (uVar9 == 0x10) {
      iVar5 = _strlen(param_3);
      *(undefined4 *)(param_3 + iVar5) = 0x5b613000;
    }
    else {
      iVar5 = _strlen(param_3);
      *(undefined4 *)(param_3 + iVar5) = 0x5b693000;
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
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x2b00;
    _strcat(param_3,((undefined1 *)((char *)frame_ + 8)));
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x5d00;
  }
  if ((uVar4 != 0xd10000) || (uVar7 != 0)) {
    uVar8 = 0;
    iVar5 = _strlen(param_3);
    *(undefined2 *)(param_3 + iVar5) = 0x2e00;
    uVar10 = 0xd;
    do {
      if (((uVar2 & 0x2000000 << (uVar8 & 0x3f)) != 0) && (uVar7 != 0)) {
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x2d00;
      }
      switch((uVar4 & 7 << (uVar10 & 0x3f)) >> (uVar10 & 0x3f)) {
      case 0:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x7800;
        break;
      case 1:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x7900;
        break;
      case 2:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x7a00;
        break;
      case 3:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x7700;
        break;
      case 4:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x3000;
        break;
      case 5:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x3100;
        break;
      default:
        iVar5 = _strlen(param_3);
        *(undefined2 *)(param_3 + iVar5) = 0x3f00;
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
  return ((int (*)())FUN_000ce050)(param_1,";    v%d = dx v%d",(uint)*(byte *)(param_2 + 1),
               (uint)*(byte *)((int)param_2 + 1),param_5,param_6,param_7,0xce4ec);
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
  unsigned int frame_[136] __attribute__((aligned(16)));
  
  if ((*(uint *)param_2 & 1) != 0) {
    acVar3 = ((char *)((char *)frame_ + 49));
    switch(*param_2) {
    case '\0':
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pos_001a62cc) + 0));
      (*(unsigned short *)((unsigned char *)((char *)((char *)frame_ + 45)) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_pos_001a62cc) + 5));
      (*(char *)((char *)frame_ + 44)) = s_IL_pos_001a62cc[4];
      pcVar7 = "IL_pos";
      break;
    case '\x01':
      param_8 = (uint)(byte)s_IL_pointsize_001a62d4[0xc];
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      (*(char *)((char *)frame_ + 44)) = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 4));
      (*(char *)((char *)frame_ + 48)) = (*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 8));
      (*(char *)((char *)frame_ + 52)) = s_IL_pointsize_001a62d4[0xc];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_pointsize_001a62d4) + 0));
      break;
    case '\x02':
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 0));
      (*(char *)((char *)frame_ + 44)) = (*(unsigned int *)((unsigned char *)&(s_IL_color_001a62e4) + 4));
      (*(char *)((char *)frame_ + 48)) = s_IL_color_001a62e4[8];
      (*(char *)((char *)frame_ + 48)) = CONCAT13((*(char *)((char *)frame_ + 48)),acVar3);
      pcVar7 = "IL_color";
      break;
    case '\x03':
      param_8 = (uint)(byte)s_IL_backcolor_001a62f0[0xc];
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      (*(char *)((char *)frame_ + 44)) = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 4));
      (*(char *)((char *)frame_ + 48)) = (*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 8));
      (*(char *)((char *)frame_ + 52)) = s_IL_backcolor_001a62f0[0xc];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_backcolor_001a62f0) + 0));
      break;
    case '\x04':
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_fog_001a6300) + 0));
      (*(unsigned short *)((unsigned char *)((char *)((char *)frame_ + 45)) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_fog_001a6300) + 5));
      (*(char *)((char *)frame_ + 44)) = s_IL_fog_001a6300[4];
      pcVar7 = "IL_fog";
      break;
    case '\x05':
      param_8 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      (*(char *)((char *)frame_ + 44)) = (*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 4));
      (*(unsigned short *)((unsigned char *)((char *)((char *)frame_ + 49)) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_generic_001a6308) + 9));
      (*(char *)((char *)frame_ + 48)) = s_IL_generic_001a6308[8];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_generic_001a6308) + 0));
      break;
    default:
      param_8 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      *(unsigned int *)((char *)((char *)frame_ + 40)) = (unsigned int)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
      (*(char *)((char *)frame_ + 44)) = (*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 4));
      (*(unsigned short *)((unsigned char *)((char *)((char *)frame_ + 49)) + 0)) = (*(unsigned short *)((unsigned char *)&(s_IL_unknown_001a6314) + 9));
      (*(char *)((char *)frame_ + 48)) = s_IL_unknown_001a6314[8];
      pcVar7 = (char *)(*(unsigned int *)((unsigned char *)&(s_IL_unknown_001a6314) + 0));
    }
    FUN_001a32d0(((char *)((char *)frame_ + 8)) + 4,"%d",(uint)(byte)param_2[1],param_4,param_5,param_6,pcVar7,param_8);
    builtin_strncpy(((char *)((char *)frame_ + 8)),"xyzw",4);
    uVar11 = *(uint *)param_2 >> 4;
    iVar5 = 0;
    bVar1 = false;
    uVar9 = 0;
    uVar4 = 1;
    pcVar8 = ((char *)((char *)frame_ + 8));
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
      puVar10 = ((undefined1 *)((char *)frame_ + 232));
      pcVar6 = param_2;
      do {
        if ((*(uint *)param_2 >> 4 & 0xf & 1 << (uVar11 & 0x3f)) == 0) {
          ((undefined1 *)((char *)frame_ + 232))[uVar11 * 0x40] = 0;
        }
        else {
          FUN_001a32d0(puVar10,"o%d.%c ",(uint)(byte)pcVar6[4],(int)((char *)((char *)frame_ + 8))[(byte)pcVar6[8]],uVar4
                       ,iVar5,pcVar7,pcVar8);
        }
        bVar1 = uVar11 != 3;
        puVar10 = puVar10 + 0x40;
        pcVar6 = pcVar6 + 1;
        uVar11 = uVar11 + 1;
      } while (bVar1);
      pcVar6 = ((char *)((char *)frame_ + 424));
      FUN_001a32d0(((undefined1 *)((char *)frame_ + 104)),"%s%s%s%s",((undefined1 *)((char *)frame_ + 232)),((undefined1 *)((char *)frame_ + 296)),((undefined1 *)((char *)frame_ + 360)),pcVar6,pcVar7,pcVar8);
    }
    else {
      iVar5 = 0x5f;
      if ((uVar11 & 1) != 0) {
        iVar5 = (int)((char *)((char *)frame_ + 8))[(byte)param_2[8]];
      }
      iVar12 = 0x5f;
      if ((uVar11 & 2) != 0) {
        iVar12 = (int)((char *)((char *)frame_ + 8))[(byte)param_2[9]];
      }
      pcVar6 = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((uVar11 & 4) != 0) {
        pcVar6 = (char *)(int)((char *)((char *)frame_ + 8))[(byte)param_2[10]];
      }
      pcVar7 = (*(GhidraMachOSection *)0x00000054).sectname + 0xb;
      if ((uVar11 & 8) != 0) {
        pcVar7 = (char *)(int)((char *)((char *)frame_ + 8))[(byte)param_2[0xb]];
      }
      FUN_001a32d0(((undefined1 *)((char *)frame_ + 104)),"o%d.%c%c%c%c",(uint)(byte)param_2[4],iVar5,iVar12,pcVar6,pcVar7,
                   pcVar8);
    }
    ((int (*)())FUN_000ce050)(param_1,";    %s = %s%s",((undefined1 *)((char *)frame_ + 104)),((char *)((char *)frame_ + 40)),((char *)((char *)frame_ + 8)) + 4,pcVar6,pcVar7,pcVar8);
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
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(s_ox_001a64a8) + 1));
  uVar6 = *param_2;
  pcVar4 = (char *)(uVar6 >> 8 & 0xf);
  if ((uint)pcVar4 < 6) {
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
  FUN_001a32d0(((undefined1 *)((char *)frame_ + 8)),"%d",uVar6 >> 0xd & 0x7f,param_4,param_5,param_6,pcVar5,param_8);
  if ((uVar6 & 0x80001000) == 0) {
    _strcat(param_3,((undefined1 *)((char *)frame_ + 8)));
  }
  else {
    if ((uVar6 & 0x80001000) == 0x80000000) {
      iVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + iVar3,"[a0",4);
    }
    else {
      iVar3 = _strlen(param_3);
      builtin_strncpy(param_3 + iVar3,"[i0",4);
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
    iVar3 = _strlen(param_3);
    (param_3 + iVar3)[0] = '+';
    (param_3 + iVar3)[1] = '\0';
    _strcat(param_3,((undefined1 *)((char *)frame_ + 8)));
    iVar3 = _strlen(param_3);
    (param_3 + iVar3)[0] = ']';
    (param_3 + iVar3)[1] = '\0';
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
    iVar3 = _strlen(param_3);
    (param_3 + iVar3)[0] = '.';
    (param_3 + iVar3)[1] = '\0';
    if ((uVar6 & 0x100000) != 0) {
      iVar3 = _strlen(param_3);
      (param_3 + iVar3)[0] = 'x';
      (param_3 + iVar3)[1] = '\0';
    }
    if ((uVar6 & 0x200000) != 0) {
      iVar3 = _strlen(param_3);
      (param_3 + iVar3)[0] = 'y';
      (param_3 + iVar3)[1] = '\0';
    }
    if ((uVar6 & 0x400000) != 0) {
      iVar3 = _strlen(param_3);
      (param_3 + iVar3)[0] = 'z';
      (param_3 + iVar3)[1] = '\0';
    }
    if ((uVar6 & 0x800000) != 0) {
      iVar3 = _strlen(param_3);
      (param_3 + iVar3)[0] = 'w';
      (param_3 + iVar3)[1] = '\0';
    }
  }
  return param_2 + 1;
}

/* FUN_000ced58 @ 0xced58 (1288 bytes) */
int FUN_000ced58(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  char *param_3;
  undefined2 *param_4;
  undefined2 *param_5;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined4 in_r8;
  int iVar7;
  undefined4 in_r10;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  unsigned int frame_[20] __attribute__((aligned(16)));
  
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
  puVar5 = param_4;
  puVar6 = param_5;
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
  *param_4 = 0x7400;
  FUN_001a32d0(((undefined1 *)((char *)frame_ + 8)),"%d",uVar12 >> 0x13 & 3,puVar5,puVar6,in_r8,iVar7,in_r10);
  if ((uVar9 & 0x2000000) != 0) {
    _strcat(param_4,"_sat");
  }
  _strcat(param_4,((undefined1 *)((char *)frame_ + 8)));
  iVar4 = _strlen(param_4);
  *(undefined2 *)(iVar4 + (int)param_4) = 0x2e00;
  if (uVar10 == 0) {
    iVar4 = _strlen(param_4);
    *(undefined2 *)(iVar4 + (int)param_4) = 0x7800;
  }
  else if (uVar10 == 0x8000000) {
    iVar4 = _strlen(param_4);
    *(undefined2 *)(iVar4 + (int)param_4) = 0x7900;
  }
  else if (uVar10 == 0x10000000) {
    iVar4 = _strlen(param_4);
    *(undefined2 *)(iVar4 + (int)param_4) = 0x7a00;
  }
  else if (uVar10 == 0x18000000) {
    iVar4 = _strlen(param_4);
    *(undefined2 *)(iVar4 + (int)param_4) = 0x7700;
  }
  iVar4 = _strlen(param_4);
  *(undefined2 *)(iVar4 + (int)param_4) = 0x2c00;
  if (uVar11 == 1) {
    *param_5 = 0x7600;
  }
  else if (uVar11 == 0) {
    *param_5 = 0x7200;
  }
  else if (uVar11 == 2) {
    *param_5 = 0x6300;
  }
  else if (uVar11 == 3) {
    *param_5 = 0x7400;
  }
  else {
    *param_5 = 0x3f00;
  }
  FUN_001a32d0(((undefined1 *)((char *)frame_ + 13)),"%d",uVar12 >> 5 & 0xff,puVar5,puVar6,in_r8,iVar7,in_r10);
  _strcat(param_5,((undefined1 *)((char *)frame_ + 13)));
  uVar10 = uVar12 & 0x6000000;
  if (((uVar12 & 0x7e000) != 0x10000) || (uVar10 != 0)) {
    uVar11 = 0;
    iVar7 = _strlen(param_5);
    *(undefined2 *)(iVar7 + (int)param_5) = 0x2e00;
    uVar3 = 0xd;
    do {
      if (((uVar10 & 0x2000000 << (uVar11 & 0x3f)) != 0) && (uVar10 != 0)) {
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x2d00;
      }
      switch((uVar12 & 0x7e000 & 7 << (uVar3 & 0x3f)) >> (uVar3 & 0x3f)) {
      case 0:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x7800;
        break;
      case 1:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x7900;
        break;
      case 2:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x7a00;
        break;
      case 3:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x7700;
        break;
      case 4:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x3000;
        break;
      case 5:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x3100;
        break;
      default:
        iVar7 = _strlen(param_5);
        *(undefined2 *)(iVar7 + (int)param_5) = 0x3f00;
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
  undefined4 *param_3;
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
    *param_3 = 0x20202000;
  }
  else if ((uVar1 & 0x8000000) == 0) {
    *param_3 = 0x21702000;
  }
  else {
    *param_3 = 0x20702000;
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
  undefined1 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  *param_3 = 0;
  iVar1 = *param_1;
  piVar5 = *(int **)(iVar1 + 0x654);
  uVar2 = param_4;
  uVar4 = param_5;
  if ((piVar5 == (int *)0x0) || (iVar6 = *piVar5, iVar6 < 1)) {
    piVar3 = (int *)param_1[1];
  }
  else {
    piVar3 = (int *)param_1[1];
    iVar7 = 0;
    while( true ) {
      iVar1 = iVar7 * 0x1c + *(int *)(iVar1 + 0x654);
      piVar5 = (int *)(*(int *)(iVar1 + 0x14) + 1);
      if (piVar5 == piVar3) {
        ((int (*)())FUN_000cfd24)(param_1,iVar1 + 4,piVar3,uVar2,uVar4,param_6,piVar5,param_8);
        piVar3 = (int *)param_1[1];
      }
      iVar7 = iVar7 + 1;
      if (iVar6 == iVar7) break;
      iVar1 = *param_1;
    }
  }
  FUN_001a32d0(((undefined1 *)((char *)frame_ + 8)),"%3d:",piVar3,uVar2,uVar4,param_6,piVar5,param_8);
  _strcat(param_3,((undefined1 *)((char *)frame_ + 8)));
  param_1[1] = param_1[1] + 1;
  iVar1 = _strlen(param_3);
  uVar2 = ((int (*)())FUN_000cf2ec)(param_1,param_2,param_3 + iVar1,param_4,param_5);
  return uVar2;
}

/* FUN_000d002c @ 0xd002c (728 bytes) */
int FUN_000d002c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined1 *param_3;
  int *param_4;
  int *param_5;
  undefined2 *param_6;
  undefined1 *param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  unsigned int frame_[56] __attribute__((aligned(16)));
  
  iVar5 = *(int *)(param_2 + 0x650);
  iVar3 = *(int *)(param_2 + 0x65c);
  *param_1 = param_2;
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";              VS Disassembly             ",param_3,param_4,param_5,param_6,
               param_7,param_8);
  ((int (*)())FUN_000ce050)(param_1,";*****************************************",param_3,param_4,param_5,param_6,
               param_7,param_8);
  if (iVar3 != 0) {
    iVar4 = 0;
    do {
      param_4 = &(*(int *)((char *)frame_ + 8));
      param_5 = &(*(int *)((char *)frame_ + 12));
      iVar1 = ((int (*)())FUN_000cff30)(param_1,iVar5,((undefined1 *)((char *)frame_ + 38)),param_4,&(*(int *)((char *)frame_ + 12)),param_6,param_7,param_8);
      param_3 = ((undefined1 *)((char *)frame_ + 38));
      if (iVar1 == 0) {
        if ((*(int *)((char *)frame_ + 8)) == 0) {
          uVar2 = ((int (*)())FUN_000cea6c)(param_1,iVar5,((int *)((char *)frame_ + 104)),param_4,param_5,param_6,param_7,param_8);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,((int *)((char *)frame_ + 16)));
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,((undefined2 *)((char *)frame_ + 82)));
          iVar5 = ((int (*)())FUN_000ce148)(param_1,uVar2,((undefined1 *)((char *)frame_ + 60)));
          if ((*(int *)((char *)frame_ + 12)) == 1) {
            iVar1 = _strlen(((int *)((char *)frame_ + 104)));
            *(undefined2 *)((int)((int *)((char *)frame_ + 104)) + iVar1) = 0x2c00;
            param_4 = ((int *)((char *)frame_ + 104));
            param_5 = ((int *)((char *)frame_ + 16));
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)),param_6,param_7,
                         param_8);
          }
          else if ((*(int *)((char *)frame_ + 12)) == 0) {
            param_4 = ((int *)((char *)frame_ + 104));
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),param_5,param_6,param_7,param_8);
          }
          else if ((*(int *)((char *)frame_ + 12)) == 2) {
            iVar1 = _strlen(((int *)((char *)frame_ + 104)));
            *(undefined2 *)((int)((int *)((char *)frame_ + 104)) + iVar1) = 0x2c00;
            iVar1 = _strlen(((int *)((char *)frame_ + 16)));
            *(undefined2 *)((int)((int *)((char *)frame_ + 16)) + iVar1) = 0x2c00;
            param_4 = ((int *)((char *)frame_ + 104));
            param_5 = ((int *)((char *)frame_ + 16));
            param_6 = ((undefined2 *)((char *)frame_ + 82));
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)),((undefined2 *)((char *)frame_ + 82)),
                         param_7,param_8);
          }
          else {
            iVar1 = _strlen(((int *)((char *)frame_ + 104)));
            *(undefined2 *)((int)((int *)((char *)frame_ + 104)) + iVar1) = 0x2c00;
            iVar1 = _strlen(((int *)((char *)frame_ + 16)));
            *(undefined2 *)((int)((int *)((char *)frame_ + 16)) + iVar1) = 0x2c00;
            iVar1 = _strlen(((undefined2 *)((char *)frame_ + 82)));
            *(undefined2 *)((int)((undefined2 *)((char *)frame_ + 82)) + iVar1) = 0x2c00;
            param_4 = ((int *)((char *)frame_ + 104));
            param_5 = ((int *)((char *)frame_ + 16));
            param_6 = ((undefined2 *)((char *)frame_ + 82));
            param_7 = ((undefined1 *)((char *)frame_ + 60));
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s%s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)),((undefined2 *)((char *)frame_ + 82)),
                         ((undefined1 *)((char *)frame_ + 60)),param_8);
          }
        }
        else {
          uVar2 = ((int (*)())FUN_000cea6c)(param_1,iVar5,((int *)((char *)frame_ + 104)),param_4,param_5,param_6,param_7,param_8);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,((int *)((char *)frame_ + 16)));
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,((undefined2 *)((char *)frame_ + 82)));
          iVar5 = _strlen(((int *)((char *)frame_ + 104)));
          *(undefined2 *)((int)((int *)((char *)frame_ + 104)) + iVar5) = 0x2c00;
          iVar5 = _strlen(((int *)((char *)frame_ + 16)));
          *(undefined2 *)((int)((int *)((char *)frame_ + 16)) + iVar5) = 0x2c00;
          param_6 = ((undefined2 *)((char *)frame_ + 82));
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)),((undefined2 *)((char *)frame_ + 82)),
                       param_7,param_8);
          iVar5 = ((int (*)())FUN_000ced58)(param_1,uVar2,((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)));
          param_4 = ((int *)((char *)frame_ + 104));
          param_5 = ((int *)((char *)frame_ + 16));
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",((undefined1 *)((char *)frame_ + 38)),((int *)((char *)frame_ + 104)),((int *)((char *)frame_ + 16)),param_6,param_7,
                       param_8);
        }
      }
      else {
        iVar5 = iVar5 + 0x10;
        ((int (*)())FUN_000ce050)(param_1,"%s",((undefined1 *)((char *)frame_ + 38)),param_4,param_5,param_6,param_7,param_8);
      }
      iVar4 = iVar4 + 1;
    } while (iVar3 != iVar4);
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
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  uVar1 = param_3;
  ((int (*)())FUN_000ce038)(((undefined1 *)((char *)frame_ + 8)));
  (*(undefined4 *)((char *)frame_ + 16)) = param_3;
  (*(undefined4 *)((char *)frame_ + 20)) = param_1;
  ((int (*)())FUN_000ce88c)(((undefined1 *)((char *)frame_ + 8)),param_2,uVar1,param_4,param_5,param_6,param_7,in_r10);
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
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  uVar1 = param_4;
  ((int (*)())FUN_000ce038)(((undefined1 *)((char *)frame_ + 8)));
  (*(undefined4 *)((char *)frame_ + 16)) = param_4;
  (*(undefined4 *)((char *)frame_ + 20)) = param_1;
  ((int (*)())FUN_000d002c)(((undefined1 *)((char *)frame_ + 8)),param_2,param_3,uVar1,param_5,param_6,param_7,in_r10);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  unsigned int frame_[76] __attribute__((aligned(16)));
  
  if (DAT_001fa61c != (undefined4 *)0x0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
    FUN_001a34d4(((undefined1 *)((char *)frame_ + 12)),param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7,param_8);
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",((undefined1 *)((char *)frame_ + 12)),&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
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
  return FUN_001a32d0(param_1,"r%02u",param_2,param_4,param_5,param_6,param_7,0xd0458);
}

/* FUN_000d0488 @ 0xd0488 (552 bytes) */
int FUN_000d0488(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
  int param_9;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (param_9 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (param_9 == 0) {
    *param_1 = '\0';
  }
  else if (param_9 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (param_9 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  uVar9 = param_8;
  if (param_8 < 0x20) {
    iVar7 = 0;
    switch(param_8) {
    default:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_2,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 0x18:
    case 0x1b:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_3,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0x19:
    case 0x1c:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_4,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xc:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_5,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xd:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_6,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xe:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_7,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      ((char *)((char *)frame_ + 8))[0] = s_srcp_001a6fa0[0];
      ((char *)((char *)frame_ + 8))[1] = s_srcp_001a6fa0[1];
      ((char *)((char *)frame_ + 8))[2] = s_srcp_001a6fa0[2];
      ((char *)((char *)frame_ + 8))[3] = s_srcp_001a6fa0[3];
      ((char *)((char *)frame_ + 8))[4] = s_srcp_001a6fa0[4];
      break;
    case 0x14:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"0.0",4);
      break;
    case 0x15:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"1.0",4);
      break;
    case 0x16:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"0.5",4);
      break;
    case 0x1d:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_5,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(((undefined1 *)((char *)frame_ + 14)),param_2,param_3,param_4,param_5,param_6,iVar7);
      break;
    case 0x1e:
      uVar6 = param_3;
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_6,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(((undefined1 *)((char *)frame_ + 14)),param_3,uVar6,param_4,param_5,param_6,iVar7);
      break;
    case 0x1f:
      uVar6 = param_4;
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_7,param_3,param_4,param_5,param_6,iVar7);
      ((int (*)())FUN_000d0450)(((undefined1 *)((char *)frame_ + 14)),param_4,param_3,uVar6,param_5,param_6,iVar7);
      param_4 = uVar6;
    }
  }
  else {
    builtin_strncpy(((char *)((char *)frame_ + 8)),"???",4);
  }
  iVar7 = _strlen(param_1);
  pcVar5 = param_1 + iVar7;
  if (param_8 < 0x20) {
    puVar8 = ((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + param_8 * 4);
                    
    switch(param_8) {
    default:
      FUN_001a32d0(pcVar5,"%s.rgb",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 1:
    case 5:
    case 9:
    case 0x10:
      FUN_001a32d0(pcVar5,"%s.rrr",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 2:
    case 6:
    case 10:
    case 0x11:
      FUN_001a32d0(pcVar5,"%s.ggg",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 3:
    case 7:
    case 0xb:
    case 0x12:
      FUN_001a32d0(pcVar5,"%s.bbb",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
      FUN_001a32d0(pcVar5,"%s.aaa",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x14:
    case 0x15:
    case 0x16:
      goto override_jmp_000d072c_case_5;
    case 0x17:
    case 0x18:
    case 0x19:
      FUN_001a32d0(pcVar5,"%s.gbr",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
      FUN_001a32d0(pcVar5,"%s.brg",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x1d:
      FUN_001a32d0(pcVar5,"%s.a:%s.bg",((char *)((char *)frame_ + 8)),((undefined1 *)((char *)frame_ + 14)),param_5,param_6,puVar8,uVar9);
    }
  }
  else {
override_jmp_000d072c_case_5:
    _strcpy(pcVar5,((char *)((char *)frame_ + 8)));
  }
  iVar7 = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + iVar7)[0] = ')';
    (param_1 + iVar7)[1] = '\0';
  }
  return;
}

/* FUN_000d0888 @ 0xd0888 (464 bytes) */
int FUN_000d0888(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
  int param_9;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  unsigned int frame_[12] __attribute__((aligned(16)));
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (param_9 == 1) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (param_9 == 0) {
    *param_1 = '\0';
  }
  else if (param_9 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
  }
  else if (param_9 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
  }
  uVar8 = param_8;
  if (param_8 < 0x13) {
    iVar6 = 0;
    switch(param_8) {
    case 0:
    case 1:
    case 2:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_2,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 3:
    case 4:
    case 5:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_3,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 6:
    case 7:
    case 8:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_4,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 9:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_5,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 10:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_6,param_3,param_4,param_5,param_6,iVar6);
      break;
    case 0xb:
      ((int (*)())FUN_000d0450)(((char *)((char *)frame_ + 8)),param_7,param_3,param_4,param_5,param_6,iVar6);
      break;
    default:
      ((char *)((char *)frame_ + 8))[0] = s_srcp_001a6fa0[0];
      ((char *)((char *)frame_ + 8))[1] = s_srcp_001a6fa0[1];
      ((char *)((char *)frame_ + 8))[2] = s_srcp_001a6fa0[2];
      ((char *)((char *)frame_ + 8))[3] = s_srcp_001a6fa0[3];
      ((char *)((char *)frame_ + 8))[4] = s_srcp_001a6fa0[4];
      break;
    case 0x10:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"0.0",4);
      break;
    case 0x11:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"1.0",4);
      break;
    case 0x12:
      builtin_strncpy(((char *)((char *)frame_ + 8)),"0.5",4);
    }
  }
  else {
    builtin_strncpy(((char *)((char *)frame_ + 8)),"???",4);
  }
  iVar6 = _strlen(param_1);
  pcVar5 = param_1 + iVar6;
  if (param_8 < 0x10) {
    puVar7 = ((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + param_8 * 4);
                    
    switch(param_8) {
    default:
      FUN_001a32d0(pcVar5,"%s.r",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 1:
    case 4:
    case 7:
      FUN_001a32d0(pcVar5,"%s.g",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 2:
    case 5:
    case 8:
      FUN_001a32d0(pcVar5,"%s.b",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 9:
      FUN_001a32d0(pcVar5,"%s.a",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,puVar7,uVar8);
    }
  }
  else {
    _strcpy(pcVar5,((char *)((char *)frame_ + 8)));
  }
  iVar6 = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + iVar6)[0] = ')';
    (param_1 + iVar6)[1] = '\0';
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
            uVar9 = uVar9 | -(uint)(puVar17[7] & 0xffff00) >> 0x1f;
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
  unsigned int frame_[40] __attribute__((aligned(16)));
  
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
          ((char *)((char *)frame_ + 8))[0] = ' ';
          ((char *)((char *)frame_ + 8))[2] = 0x2e;
          iVar8 = 7;
          ((char *)((char *)frame_ + 8))[1] = '0';
          iVar4 = 3;
          iVar6 = 0x30;
          do {
            ((char *)((char *)frame_ + 8))[iVar4] = '0';
            iVar4 = iVar4 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
          (*(undefined1 *)((char *)frame_ + 19)) = 0x2b;
          (*(undefined1 *)((char *)frame_ + 21)) = 0x30;
          (*(char *)((char *)frame_ + 20)) = '0';
        }
        else {
          if (dVar9 < (double)FLOAT_001aa0d4) {
            dVar9 = -dVar9;
            ((char *)((char *)frame_ + 8))[0] = '-';
          }
          else {
            ((char *)((char *)frame_ + 8))[0] = '+';
          }
          (*(float *)((char *)frame_ + 80)) = (float)dVar9;
          (*(undefined4 *)((char *)frame_ + 24)) = 0x43300000;
          (*(uint *)((char *)frame_ + 28)) = ((uint)(int)(*(float *)((char *)frame_ + 80)) >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          dVar10 = _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 28))) - DOUBLE_001aa1e0);
          dVar10 = _log(dVar10);
          dVar11 = _log(dVar3);
          dVar10 = _floor(dVar10 / dVar11);
          (*(undefined4 *)((char *)frame_ + 40)) = 0x43300000;
          uVar7 = (uint)(int)dVar10;
          (*(longlong *)((char *)frame_ + 32)) = (longlong)(int)uVar7;
          (*(uint *)((char *)frame_ + 44)) = uVar7 ^ 0x80000000;
          dVar11 = _pow(dVar3,(double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 44))) - dVar2);
          dVar10 = DOUBLE_001aa298;
          dVar11 = dVar9 / dVar11 + DOUBLE_001aa298;
          if (dVar3 <= dVar11) {
            uVar7 = uVar7 + 1;
            (*(undefined4 *)((char *)frame_ + 48)) = 0x43300000;
            (*(uint *)((char *)frame_ + 52)) = uVar7 ^ 0x80000000;
            dVar11 = _pow(dVar3,(double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 52))) - dVar2);
            dVar11 = dVar9 / dVar11 + dVar10;
          }
          dVar9 = _floor(dVar11);
          uVar5 = (uint)(int)dVar9;
          (*(longlong *)((char *)frame_ + 56)) = (longlong)(int)uVar5;
          ((char *)((char *)frame_ + 8))[2] = 0x2e;
          iVar6 = 3;
          ((char *)((char *)frame_ + 8))[1] = (char)uVar5 + '0';
          do {
            (*(uint *)((char *)frame_ + 68)) = uVar5 ^ 0x80000000;
            (*(undefined4 *)((char *)frame_ + 64)) = 0x43300000;
            dVar11 = (dVar11 - ((double)CONCAT44(0x43300000,(*(uint *)((char *)frame_ + 68))) - dVar2)) * dVar3;
            dVar9 = _floor(dVar11);
            bVar1 = iVar6 != 9;
            uVar5 = (uint)(int)dVar9;
            (*(longlong *)((char *)frame_ + 72)) = (longlong)(int)uVar5;
            ((char *)((char *)frame_ + 8))[iVar6] = (char)uVar5 + '0';
            iVar6 = iVar6 + 1;
          } while (bVar1);
          if ((int)uVar7 < 0) {
            uVar7 = -uVar7;
            (*(undefined1 *)((char *)frame_ + 19)) = 0x2d;
          }
          else {
            (*(undefined1 *)((char *)frame_ + 19)) = 0x2b;
          }
          (*(char *)((char *)frame_ + 20)) = (char)((int)uVar7 / 10) + '0';
          iVar6 = (int)uVar7 % 10 + 0x30;
          (*(undefined1 *)((char *)frame_ + 21)) = (undefined1)iVar6;
        }
        (*(undefined1 *)((char *)frame_ + 18)) = 0x45;
        (*(undefined1 *)((char *)frame_ + 22)) = 0;
        FUN_001a32d0(param_1,"(%s)",((char *)((char *)frame_ + 8)),param_4,param_5,param_6,iVar6,param_8);
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
int FUN_000d13a4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  char *param_7;
  int param_8;
  int param_9;
  uint param_10;
  int param_11;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char *pcVar13;
  double in_f1;
  double fparam_1;
  unsigned int frame_[24] __attribute__((aligned(16)));
  
  cVar6 = s______001a6f98[4];
  cVar5 = s_nab__001a6f90[4];
  cVar4 = s_abs__001a6f88[4];
  cVar3 = s_neg__001a6f80[4];
  if (param_9 == 1) {
    pcVar13 = "neg(";
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar3;
  }
  else if (param_9 == 0) {
    *param_1 = '\0';
    pcVar13 = param_7;
  }
  else if (param_9 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar4;
    pcVar13 = "abs(";
  }
  else if (param_9 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar5;
    pcVar13 = "nab(";
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar6;
    pcVar13 = "???(";
  }
  uVar10 = param_4;
  iVar8 = param_8;
  if (param_11 - 0xbU < 2) {
LAB_000d14bc:
    ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_2,param_3,uVar10,param_5,param_6,pcVar13,iVar8,in_f1);
  }
  else {
    uVar9 = param_3;
    uVar11 = param_5;
    uVar12 = param_6;
    iVar7 = ((int (*)())FUN_000d10a8)(param_10 & 0xffff);
    if (iVar7 == 0) {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_3,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      param_3 = uVar9;
      param_5 = uVar11;
      param_6 = uVar12;
      in_f1 = fparam_1;
      if (param_8 == 0) goto LAB_000d14bc;
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_4,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
    }
    else {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_6,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      if (param_8 == 0) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_5,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_7,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
    }
    if (param_8 == 3) {
      ((char *)((char *)frame_ + 8))[0] = s_srcp_001a6fa0[0];
      ((char *)((char *)frame_ + 8))[1] = s_srcp_001a6fa0[1];
      ((char *)((char *)frame_ + 8))[2] = s_srcp_001a6fa0[2];
      ((char *)((char *)frame_ + 8))[3] = s_srcp_001a6fa0[3];
      ((char *)((char *)frame_ + 8))[4] = s_srcp_001a6fa0[4];
    }
    else {
      builtin_strncpy(((char *)((char *)frame_ + 8)),"???",4);
    }
  }
LAB_000d1518:
  iVar7 = _strlen(param_1);
  uVar1 = param_10 & 0xffff;
  uVar2 = param_10 & 0xff80;
  if (((uVar2 == 0x9200) || (uVar2 == 0xdb00)) || (uVar2 == 0xb680)) {
    _strcpy(param_1 + iVar7,(uVar1 >> 0xb & 0x1c) + 0x1dc259);
  }
  else {
    FUN_001a32d0(param_1 + iVar7,"%s.%s%s%s",((char *)((char *)frame_ + 8)),(uVar1 >> 0xb & 0x1c) + 0x1dc259,
                 (uVar1 >> 8 & 0x1c) + 0x1dc259,(uVar1 >> 5 & 0x1c) + 0x1dc259,uVar1,iVar8);
  }
  iVar8 = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + iVar8)[0] = ')';
    (param_1 + iVar8)[1] = '\0';
  }
  return;
}

/* FUN_000d1624 @ 0xd1624 (536 bytes) */
int FUN_000d1624(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  char *param_7;
  int param_8;
  int param_9;
  int param_10;
  int param_11;
{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  char *pcVar6;
  double in_f1;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  cVar4 = s______001a6f98[4];
  cVar3 = s_nab__001a6f90[4];
  cVar2 = s_abs__001a6f88[4];
  cVar1 = s_neg__001a6f80[4];
  if (param_9 == 1) {
    pcVar6 = "neg(";
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_neg__001a6f80) + 0));
    param_1[4] = cVar1;
  }
  else if (param_9 == 0) {
    *param_1 = '\0';
    pcVar6 = param_7;
  }
  else if (param_9 == 2) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_abs__001a6f88) + 0));
    param_1[4] = cVar2;
    pcVar6 = "abs(";
  }
  else if (param_9 == 3) {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s_nab__001a6f90) + 0));
    param_1[4] = cVar3;
    pcVar6 = "nab(";
  }
  else {
    *(undefined4 *)param_1 = (*(unsigned int *)((unsigned char *)&(s______001a6f98) + 0));
    param_1[4] = cVar4;
    pcVar6 = "???(";
  }
  if (1 < param_11 - 0xeU) {
    if (param_10 != 3) {
      if (param_8 != 1) {
        if (param_8 == 0) {
          ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_2,param_7,param_4,param_5,param_6,pcVar6,0,in_f1);
          goto LAB_000d1780;
        }
        param_3 = param_4;
        if (param_8 != 2) goto LAB_000d176c;
      }
      ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_3,param_7,param_4,param_5,param_6,pcVar6,param_8,in_f1);
      goto LAB_000d1780;
    }
    if (param_8 == 1) {
      ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_6,param_7,param_4,param_5,param_6,pcVar6,1,in_f1);
      goto LAB_000d1780;
    }
    if (param_8 != 0) {
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_7,param_7,param_4,param_5,param_6,pcVar6,2,in_f1);
        goto LAB_000d1780;
      }
LAB_000d176c:
      if (param_8 == 3) {
        pcVar6 = "srcp";
        ((char *)((char *)frame_ + 8))[0] = s_srcp_001a6fa0[0];
        ((char *)((char *)frame_ + 8))[1] = s_srcp_001a6fa0[1];
        ((char *)((char *)frame_ + 8))[2] = s_srcp_001a6fa0[2];
        ((char *)((char *)frame_ + 8))[3] = s_srcp_001a6fa0[3];
        ((char *)((char *)frame_ + 8))[4] = s_srcp_001a6fa0[4];
      }
      else {
        builtin_strncpy(((char *)((char *)frame_ + 8)),"???",4);
      }
      goto LAB_000d1780;
    }
  }
  ((double (*)())FUN_000d10dc)(((char *)((char *)frame_ + 8)),param_5,param_7,param_4,param_5,param_6,pcVar6,param_8,in_f1);
LAB_000d1780:
  iVar5 = _strlen(param_1);
  if (param_10 - 4U < 3) {
    _strcpy(param_1 + iVar5,param_10 * 4 + 0x1dc259);
  }
  else {
    FUN_001a32d0(param_1 + iVar5,"%s.%s",((char *)((char *)frame_ + 8)),param_10 * 4 + 0x1dc259,param_5,param_6,pcVar6,
                 param_8);
  }
  iVar5 = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + iVar5)[0] = ')';
    (param_1 + iVar5)[1] = '\0';
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
  undefined4 uVar11;
  int iVar12;
  uint *puVar13;
  char *pcVar14;
  uint uVar15;
  char *pcVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  uint *puVar21;
  char *pcVar22;
  bool bVar24;
  uint uVar23;
  byte *pbVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  uint *puVar32;
  uint *puVar33;
  uint uVar34;
  uint *puVar35;
  uint uVar36;
  uint uVar37;
  undefined **ppuVar38;
  bool bVar40;
  undefined *puVar39;
  uint *puVar41;
  double dVar42;
  uint uStack0000001c;
  uint *puStack00000020;
  undefined2 uVar43;
  uint *in_stack_fffffd2c;
  unsigned int frame_[176] __attribute__((aligned(16)));
  
  uStack0000001c = param_2;
  puStack00000020 = param_3;
  ((int (*)())FUN_000d0b68)(param_1,1,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((*(byte *)((int)param_1 + 0xf) & 0x10) == 0) {
    (*(uint *)((char *)frame_ + 544)) = param_1[2];
    uVar19 = uStack0000001c;
    puVar13 = puStack00000020;
    ((int (*)())FUN_000d03b4)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",uVar19,puVar13,param_5,param_6,param_7,param_8);
    }
    else {
      iVar31 = 0;
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",uVar19,puVar13,param_5,param_6,param_7,param_8);
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
      uVar19 = (uint)*(ushort *)((int)param_1 + 0x26);
      ((int (*)())FUN_000d03b4)(0,"     Nominal cycle count:    %2d\n",uVar19,puVar13,param_5,param_6,param_7,
                   param_8);
      ((int (*)())FUN_000d03b4)(0,"     Tex lookup counts:     ",uVar19,puVar13,param_5,param_6,param_7,param_8);
      puVar41 = param_1;
      do {
        uVar19 = (uint)*(byte *)((int)puVar41 + 0x2a);
        ((int (*)())FUN_000d03b4)(0," %2d",uVar19,puVar13,param_5,param_6,param_7,param_8);
        bVar24 = iVar31 != 0xf;
        puVar41 = (uint *)((int)puVar41 + 1);
        iVar31 = iVar31 + 1;
      } while (bVar24);
      ((int (*)())FUN_000d03b4)(0,"\n \n",uVar19,puVar13,param_5,param_6,param_7,param_8);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",uVar19,puVar13,param_5,param_6,param_7,param_8);
    if ((param_1[0x12] == 1) && ((*(uint *)((char *)frame_ + 544)) != 0)) {
      puVar32 = param_1 + 0x24;
      uVar37 = 1;
      puVar41 = puVar32;
      puVar33 = param_1 + 0x12;
      do {
        puVar35 = puVar41;
        uVar19 = uVar37 - 1;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",uVar19,puVar13,param_5,param_6,param_7,param_8);
        if (*(char *)((int)puVar33 + 0xb) == '\0') {
          if (*(char *)((int)puVar33 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",uVar19,puVar13,param_5,param_6,param_7,
                         param_8);
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())FUN_000d03b4)(0,"\n",uVar19,puVar13,param_5,param_6,param_7,param_8);
        }
        else {
          uVar19 = (uint)*(ushort *)((int)puVar33 + 6);
          param_5 = (uint)*(byte *)((int)puVar33 + 10);
          puVar13 = (uint *)((*(byte *)((int)puVar33 + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",uVar19,puVar13,param_5,param_6,param_7,param_8);
          if (*(char *)((int)puVar33 + 0xd) == '\0') {
            if (*(char *)((int)puVar33 + 0xb) == '\x02') {
              ((int (*)())FUN_000d03b4)(0," fbuf  ",uVar19,puVar13,param_5,param_6,param_7,param_8);
            }
            else if (*(char *)((int)puVar33 + 0xb) == '\x03') {
              ((int (*)())FUN_000d03b4)(0," back  ",uVar19,puVar13,param_5,param_6,param_7,param_8);
            }
            else {
              if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())FUN_000d03b4)(0,"       ",uVar19,puVar13,param_5,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0," biased",uVar19,puVar13,param_5,param_6,param_7,param_8);
          }
LAB_000d3b80:
          if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d3be0;
          uVar19 = (uint)*(ushort *)(puVar33 + 1);
          param_5 = (uint)*(byte *)(puVar33 + 2);
          puVar13 = (uint *)((*(byte *)((int)puVar33 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",uVar19,puVar13,param_5,param_6,param_7,param_8);
          if (*(char *)(puVar33 + 3) == '\0') goto LAB_000d3be0;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",uVar19,puVar13,param_5,param_6,param_7,param_8);
        }
        uVar37 = uVar37 + 1;
        if (*puVar32 != 1) break;
        puVar32 = puVar32 + 0x12;
        puVar41 = puVar35 + 0x12;
        puVar33 = puVar35;
      } while (uVar37 <= (*(uint *)((char *)frame_ + 544)));
    }
    else {
      uVar37 = 1;
    }
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",uVar19,puVar13,param_5,param_6,param_7,param_8);
    if (uVar37 <= (*(uint *)((char *)frame_ + 544))) {
      uVar26 = 0;
      puVar41 = param_1 + uVar37 * 0x12;
      (*(uint *)((char *)frame_ + 536)) = 1;
      (*(uint * *)((char *)frame_ + 540)) = (uint *)0x0;
      (*(int *)((char *)frame_ + 472)) = 0;
      uVar19 = 0;
      do {
        uVar27 = *puVar41;
        if (((uVar27 == 2) && (((*(uint *)((char *)frame_ + 536)) != 0 || (*(char *)(puVar41 + 8) != '\0')))) ||
           (uVar26 == 0)) {
          if (uVar26 < 0x34) {
            (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 1)) = (ushort)(byte)((char)(uVar26 / 0x34) + 0x2f) << 8;
          }
          cVar9 = (char)(uVar26 % 0x34);
          if (uVar26 % 0x34 < 0x1a) {
            cVar9 = cVar9 + 'A';
          }
          else {
            cVar9 = cVar9 + 'G';
          }
          (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT12(cVar9,(*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 1)));
          ((int (*)())FUN_000d03b4)(0," \n   Level %s:\n",&(*(undefined4 *)((char *)frame_ + 8)),puVar13,uVar19,param_6,param_7,param_8);
          uVar26 = uVar26 + 1;
          uVar27 = *puVar41;
        }
        (*(uint *)((char *)frame_ + 536)) = (uint)(uVar27 - 3 < 2);
        if (uVar27 == 2) {
          ((int (*)())FUN_000d03b4)(0,"     tex %02d    :  ",(*(int *)((char *)frame_ + 472)),puVar13,uVar19,param_6,param_7,param_8);
          uVar28 = (uint)*(ushort *)((int)puVar41 + 0xe);
          uVar27 = (uint)*(ushort *)(puVar41 + 3);
          uVar34 = (uint)*(byte *)((int)puVar41 + 0x19);
          if ((*(byte *)((int)puVar41 + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)puVar41 + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.rgba = ",uVar27,puVar13,uVar19,param_6,param_7,param_8);
          }
          puVar33 = (uint *)(uint)*(byte *)((int)puVar41 + 0x1a);
          puVar13 = (uint *)(*(byte *)((int)puVar41 + 0x1f) & 0xf ^ 0xf);
          if (((unsigned char *)0x4) < puVar33) {
            ((int (*)())FUN_000d03b4)(0,"???()\n",uVar27,puVar13,uVar19,param_6,puVar33,param_8);
            param_7 = (char *)puVar33;
          }
          else {
            param_7 = (char *)(0);
            switch((int)puVar33) {
            case 0x0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",uVar27,puVar13,uVar19,param_6,param_7,param_8);
              break;
            case 0x1:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup(r%02d.%s, tex%02d)\n",uVar28,puVar13,uVar34,param_6,param_7,
                           param_8);
              break;
            case 0x2:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"kill(r%02d.%s)\n",uVar28,puVar13,uVar19,param_6,param_7,param_8);
              break;
            case 0x3:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(r%02d.%s, tex%02d)\n",uVar28,puVar13,uVar34,param_6,
                           param_7,param_8);
              break;
            case 0x4:
              puVar13 = (uint *)((int)puVar13 * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",uVar28,puVar13,uVar34,param_6,
                           param_7,param_8);
            }
          }
          (*(int *)((char *)frame_ + 472)) = (*(int *)((char *)frame_ + 472)) + 1;
        }
        else if ((1 < uVar27) && (uVar27 < 5)) {
          (*(byte * *)((char *)frame_ + 500)) = (byte *)((int)puVar41 + 0x31);
          switch(*(undefined1 *)((int)puVar41 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            uVar27 = 0;
            bVar24 = true;
            uVar19 = 3;
            iVar31 = 1;
            break;
          case 1:
          case 4:
          case 5:
            uVar27 = 0;
            bVar24 = true;
            uVar19 = 1;
            iVar31 = 0;
            break;
          case 2:
            uVar27 = 3;
            bVar24 = true;
            uVar19 = 1;
            iVar31 = 0;
            break;
          default:
            uVar27 = 0;
            bVar24 = false;
            uVar19 = 0;
            iVar31 = 0;
            break;
          case 9:
            uVar27 = 0;
            bVar24 = true;
            uVar19 = 0;
            iVar31 = 0;
          }
          (*(uint * *)((char *)frame_ + 504)) = puVar41 + 0x10;
          if (*(byte *)(puVar41 + 0x10) < 0xc) {
            uVar28 = 1 << ((int)(char)*(byte *)(puVar41 + 0x10) & 0x3fU);
            if ((uVar28 & 0x61) == 0) {
              if ((uVar28 & 0xc) == 0) {
                if ((uVar28 & 0xf80) != 0) {
                  uVar27 = uVar27 | 1;
                }
              }
              else {
                uVar27 = 3;
              }
            }
            else {
              uVar27 = 7;
            }
          }
          (*(byte * *)((char *)frame_ + 532)) = (byte *)(uint)*(byte *)((int)puVar41 + 0x3b);
          uVar36 = (uint)*(ushort *)((int)puVar41 + 0xe);
          puVar33 = (uint *)(uint)*(ushort *)(puVar41 + 4);
          puVar32 = (uint *)(uint)*(ushort *)((int)puVar41 + 0x12);
          puVar35 = (uint *)(uint)*(ushort *)((int)puVar41 + 0x1a);
          param_6 = (uint *)(uint)*(ushort *)(puVar41 + 7);
          param_7 = (char *)(uint)*(ushort *)((int)puVar41 + 0x1e);
          uVar30 = (uint)*(byte *)((int)puVar41 + 0x2a);
          uVar29 = (uint)*(byte *)((int)puVar41 + 0x2b);
          uVar15 = (uint)*(byte *)(puVar41 + 0xb);
          uVar34 = (uint)*(byte *)((int)puVar41 + 0x39);
          uVar28 = (uint)*(byte *)((int)puVar41 + 0x3a);
          (*(uint *)((char *)frame_ + 528)) = (uint)*(byte *)((int)puVar41 + 0x2d);
          (*(uint *)((char *)frame_ + 524)) = (uint)*(byte *)((int)puVar41 + 0x2e);
          (*(uint *)((char *)frame_ + 520)) = (uint)*(byte *)((int)puVar41 + 0x2f);
          (*(uint *)((char *)frame_ + 516)) = (uint)*(byte *)(puVar41 + 0xf);
          (*(uint *)((char *)frame_ + 512)) = (uint)*(byte *)((int)puVar41 + 0x3d);
          (*(uint *)((char *)frame_ + 508)) = (uint)*(byte *)((int)puVar41 + 0x3e);
          if (bVar24) {
            uVar23 = (uint)(uVar30 - 0xf < 4);
          }
          else {
            uVar23 = 0;
          }
          bVar24 = bVar24 && uVar30 == 0x13;
          uVar19 = uVar19 & 1;
          if (uVar19 != 0) {
            uVar23 = uVar23 | uVar29 - 0xf < 4;
            bVar24 = bVar24 || uVar29 == 0x13;
          }
          if (iVar31 != 0) {
            uVar19 = -(uVar15 ^ 0x13);
            uVar23 = uVar23 | uVar15 - 0xf < 4;
            bVar24 = (bool)(bVar24 | (uVar15 ^ 0x13) == 0);
          }
          if ((uVar27 & 1) != 0) {
            uVar19 = -(uVar34 ^ 0xf);
            uVar23 = uVar23 | uVar34 - 0xc < 3;
            bVar24 = (bool)(bVar24 | (uVar34 ^ 0xf) == 0);
          }
          if ((uVar27 & 2) != 0) {
            uVar19 = -(uVar28 ^ 0xf);
            uVar23 = uVar23 | uVar28 - 0xc < 3;
            bVar24 = (bool)(bVar24 | (uVar28 ^ 0xf) == 0);
          }
          if ((uVar27 & 4) != 0) {
            uVar19 = -((uint)(*(byte * *)((char *)frame_ + 532)) ^ 0xf);
            uVar23 = uVar23 | (*(byte * *)((char *)frame_ + 532)) + -0xc < (byte *)((int)((unsigned char *)0x0) + 3);
            bVar24 = (bool)(bVar24 | ((uint)(*(byte * *)((char *)frame_ + 532)) ^ 0xf) == 0);
          }
          puVar21 = puVar13;
          if (uVar23 != 0) {
            puVar17 = (*(uint * *)((char *)frame_ + 540));
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.rgb = ",(*(uint * *)((char *)frame_ + 540)),puVar13,uVar19,uVar27,uVar23,
                         iVar31);
            cVar9 = *(char *)(puVar41 + 0xc);
            if (cVar9 == '\x01') {
              puVar21 = &(*(uint *)((char *)frame_ + 22));
              ((int (*)())FUN_000d0450)(puVar21,uVar36,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d0450)(&(*(undefined2 *)((char *)frame_ + 32)),puVar33,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar27,uVar23,iVar31);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d0450)(&(*(uint *)((char *)frame_ + 22)),uVar36,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&(*(uint *)((char *)frame_ + 22)),puVar13,uVar19,uVar27,uVar23,iVar31);
              puVar21 = puVar13;
            }
            else if (cVar9 == '\x02') {
              puVar21 = &(*(uint *)((char *)frame_ + 22));
              ((int (*)())FUN_000d0450)(puVar21,uVar36,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d0450)(&(*(undefined2 *)((char *)frame_ + 32)),puVar33,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar27,uVar23,iVar31);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d0450)(&(*(uint *)((char *)frame_ + 22)),uVar36,puVar17,puVar13,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&(*(uint *)((char *)frame_ + 22)),puVar13,uVar19,uVar27,uVar23,iVar31);
              puVar21 = puVar13;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",puVar17,puVar13,uVar19,uVar27,uVar23,iVar31);
              puVar21 = puVar13;
            }
          }
          puVar13 = puVar21;
          if (bVar24) {
            puVar17 = (*(uint * *)((char *)frame_ + 540));
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.a   = ",(*(uint * *)((char *)frame_ + 540)),puVar21,uVar19,uVar27,uVar23,
                         iVar31);
            cVar9 = *(char *)((int)puVar41 + 0x3f);
            if (cVar9 == '\x01') {
              puVar13 = &(*(uint *)((char *)frame_ + 22));
              ((int (*)())FUN_000d0450)(puVar13,puVar35,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d0450)(&(*(undefined2 *)((char *)frame_ + 32)),param_6,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar13,uVar19,uVar27,uVar23,iVar31);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d0450)(&(*(uint *)((char *)frame_ + 22)),puVar35,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&(*(uint *)((char *)frame_ + 22)),puVar21,uVar19,uVar27,uVar23,iVar31);
              puVar13 = puVar21;
            }
            else if (cVar9 == '\x02') {
              puVar13 = &(*(uint *)((char *)frame_ + 22));
              ((int (*)())FUN_000d0450)(puVar13,puVar35,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d0450)(&(*(undefined2 *)((char *)frame_ + 32)),param_6,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar13,uVar19,uVar27,uVar23,iVar31);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d0450)(&(*(uint *)((char *)frame_ + 22)),puVar35,puVar17,puVar21,uVar19,uVar27,uVar23);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&(*(uint *)((char *)frame_ + 22)),puVar21,uVar19,uVar27,uVar23,iVar31);
              puVar13 = puVar21;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",puVar17,puVar21,uVar19,uVar27,uVar23,iVar31);
              puVar13 = puVar21;
            }
          }
          puVar21 = (*(uint * *)((char *)frame_ + 540));
          ((int (*)())FUN_000d03b4)(0,"     alu %02d rgb:  ",(*(uint * *)((char *)frame_ + 540)),puVar13,uVar19,uVar27,uVar23,iVar31);
          uVar18 = (uint)*(byte *)((int)puVar41 + 0x15);
          bVar3 = *(byte *)(puVar41 + 5);
          if (uVar18 == 0) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar21,0,uVar19,uVar27,uVar23,iVar31);
          }
          else {
            puVar21 = (uint *)(uint)*(byte *)((int)puVar41 + 0x16);
            uVar18 = uVar18 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",puVar21,uVar18,uVar19,uVar27,uVar23,iVar31);
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar21,uVar18,uVar19,uVar27,uVar23,iVar31);
          }
          else {
            puVar21 = (uint *)(uint)*(ushort *)(puVar41 + 3);
            uVar18 = (uint)bVar3 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",puVar21,uVar18,uVar19,uVar27,uVar23,iVar31);
          }
          if (*(char *)((int)puVar41 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar21,uVar18,uVar19,uVar27,uVar23,iVar31);
          }
          (*(uint * *)((char *)frame_ + 600)) = ((uint *)((char *)frame_ + 196));
          (*(uint * *)((char *)frame_ + 604)) = ((uint *)((char *)frame_ + 228));
          ((int (*)())FUN_000d0488)((*(uint * *)((char *)frame_ + 600)),uVar36,puVar33,puVar32,puVar35,param_6,param_7,uVar30,(*(uint *)((char *)frame_ + 528)));
          (*(uint * *)((char *)frame_ + 608)) = ((uint *)((char *)frame_ + 260));
          puVar21 = ((uint *)((char *)frame_ + 292));
          ((int (*)())FUN_000d0488)((*(uint * *)((char *)frame_ + 604)),uVar36,puVar33,puVar32,puVar35,param_6,param_7,uVar29,(*(uint *)((char *)frame_ + 524)));
          ((int (*)())FUN_000d0488)((*(uint * *)((char *)frame_ + 608)),uVar36,puVar33,puVar32,puVar35,param_6,param_7,uVar15,(*(uint *)((char *)frame_ + 520)));
          puVar13 = ((uint *)((char *)frame_ + 324));
          ((int (*)())FUN_000d0888)(puVar21,uVar36,puVar33,puVar32,puVar35,param_6,param_7,uVar34,(*(uint *)((char *)frame_ + 516)));
          puVar17 = ((uint *)((char *)frame_ + 132));
          ((int (*)())FUN_000d0888)(puVar13,uVar36,puVar33,puVar32,puVar35,param_6,param_7,uVar28,(*(uint *)((char *)frame_ + 512)));
          param_8 = (*(byte * *)((char *)frame_ + 532));
          ((int (*)())FUN_000d0888)(puVar17,uVar36,puVar33,puVar32,puVar35,param_6,param_7,(*(byte * *)((char *)frame_ + 532)),(*(uint *)((char *)frame_ + 508)));
          bVar3 = *(*(byte * *)((char *)frame_ + 500));
          if (bVar3 < 0xb) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              puVar35 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 608)),param_6,param_7,param_8);
              break;
            case 1:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),puVar35,param_6,param_7,param_8);
              break;
            case 2:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = puVar21;
              puVar35 = (*(uint * *)((char *)frame_ + 604));
              param_6 = puVar13;
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",(*(uint * *)((char *)frame_ + 600)),puVar21,(*(uint * *)((char *)frame_ + 604)),puVar13,param_7,param_8);
              break;
            case 3:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              puVar35 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 608)),param_6,param_7,param_8);
              break;
            case 4:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),puVar35,param_6,param_7,param_8);
              break;
            case 5:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),puVar35,param_6,param_7,param_8);
              break;
            case 6:
              goto switchD_000d4578_caseD_6;
            case 7:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              puVar35 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 608)),param_6,param_7,param_8);
              break;
            case 8:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              puVar32 = (*(uint * *)((char *)frame_ + 604));
              puVar35 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",(*(uint * *)((char *)frame_ + 600)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 608)),param_6,param_7,param_8);
              break;
            case 9:
              puVar33 = (*(uint * *)((char *)frame_ + 600));
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",(*(uint * *)((char *)frame_ + 600)),puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",puVar33,puVar32,puVar35,param_6,param_7,param_8);
            }
          }
          else {
switchD_000d4578_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)((int)puVar41 + 0x32);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          puVar33 = (*(uint * *)((char *)frame_ + 540));
          ((int (*)())FUN_000d03b4)(0,"          alpha:  ",(*(uint * *)((char *)frame_ + 540)),puVar32,puVar35,param_6,param_7,param_8);
          cVar9 = *(char *)(puVar41 + 8);
          bVar24 = *(char *)((int)puVar41 + 0x21) != '\0';
          cVar5 = *(char *)((int)puVar41 + 0x23);
          if (bVar24) {
            puVar33 = (uint *)(uint)*(byte *)((int)puVar41 + 0x22);
            ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          bVar2 = cVar5 != '\0';
          if (bVar2) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          if ((!bVar24) && (!bVar2)) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          if (cVar9 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          else {
            puVar33 = (uint *)(uint)*(ushort *)(puVar41 + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          if (*(char *)((int)puVar41 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar33,puVar32,puVar35,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)(*(uint * *)((char *)frame_ + 504));
          if (bVar3 < 0xc) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",puVar33,puVar32,puVar35,param_6,param_7,param_8);
              puVar21 = puVar33;
              puVar13 = puVar32;
              puVar17 = puVar35;
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",puVar21,puVar13,puVar35,param_6,param_7,param_8);
              puVar17 = puVar35;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",puVar21,puVar13,puVar35,param_6,param_7,param_8);
              puVar17 = puVar35;
              break;
            case 4:
              goto switchD_000d489c_caseD_4;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",puVar21,puVar32,puVar35,param_6,param_7,param_8);
              puVar13 = puVar32;
              puVar17 = puVar35;
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",puVar21,puVar32,puVar35,param_6,param_7,param_8);
              puVar13 = puVar32;
              puVar17 = puVar35;
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",puVar21,puVar32,puVar35,param_6,param_7,param_8);
              puVar13 = puVar32;
              puVar17 = puVar35;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",puVar21,puVar32,puVar35,param_6,param_7,param_8);
              puVar13 = puVar32;
              puVar17 = puVar35;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",puVar21,puVar32,puVar35,param_6,param_7,param_8);
              puVar13 = puVar32;
              puVar17 = puVar35;
            }
          }
          else {
switchD_000d489c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar33,puVar32,puVar35,param_6,param_7,param_8);
            puVar21 = puVar33;
            puVar13 = puVar32;
            puVar17 = puVar35;
          }
          bVar3 = *(byte *)((int)puVar41 + 0x41);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",puVar21,puVar13,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)(puVar41 + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d post-NOP\n",(*(uint * *)((char *)frame_ + 540)),puVar13,puVar17,param_6,param_7,
                         param_8);
          }
          (*(uint * *)((char *)frame_ + 540)) = (uint *)((int)(*(uint * *)((char *)frame_ + 540)) + 1);
        }
        uVar37 = uVar37 + 1;
        puVar41 = puVar41 + 0x12;
        param_5 = (*(uint *)((char *)frame_ + 544));
        uVar19 = (*(uint *)((char *)frame_ + 544));
      } while (uVar37 <= (*(uint *)((char *)frame_ + 544)));
    }
    uVar26 = 0;
    ((int (*)())FUN_000d03b4)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    uVar37 = param_1[2];
    uVar19 = uStack0000001c;
    puVar13 = puStack00000020;
    ((int (*)())FUN_000d03b4)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
    do {
      uVar27 = *param_1;
      if (uVar27 < 5) {
        switch(uVar27) {
        case 0:
          uVar19 = param_1[1];
          puVar13 = (uint *)param_1[2];
          param_5 = (uint)*(byte *)(param_1 + 3);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0xd);
          param_7 = (char *)(uint)*(ushort *)(param_1 + 5);
          param_8 = (byte *)(uint)*(ushort *)((int)param_1 + 0x16);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                       ,uVar19,puVar13,param_5,param_6,param_7,param_8);
          break;
        case 1:
          uVar19 = (uint)*(ushort *)(param_1 + 1);
          puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 6);
          param_5 = (uint)*(byte *)(param_1 + 2);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 9);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 10);
          param_8 = (byte *)(uint)*(byte *)((int)param_1 + 0xb);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,uVar19,puVar13,param_5,param_6,param_7,param_8);
          break;
        case 2:
          uVar19 = (uint)*(ushort *)(param_1 + 3);
          puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 0xe);
          param_5 = (uint)*(byte *)((int)param_1 + 0x19);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0x1a);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 0x1f);
          param_8 = (byte *)(uint)*(byte *)(param_1 + 8);
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",uVar19,puVar13,
                       param_5,param_6,param_7,param_8);
          break;
        default:
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_ALU    : \n",uVar19,puVar13,param_5,param_6,
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
          uVar19 = (uint)*(byte *)((int)param_1 + 0x39);
          puVar13 = (uint *)(uint)*(byte *)(param_1 + 0xf);
          param_5 = (uint)*(byte *)((int)param_1 + 0x3a);
          param_6 = (uint *)(uint)*(byte *)((int)param_1 + 0x3d);
          param_7 = (char *)(uint)*(byte *)((int)param_1 + 0x3b);
          param_8 = (byte *)(uint)*(byte *)((int)param_1 + 0x3e);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,uVar19,puVar13,param_5,param_6,param_7,param_8);
        }
      }
      uVar26 = uVar26 + 1;
      param_1 = param_1 + 0x12;
    } while (uVar26 <= uVar37);
    ((int (*)())FUN_000d03b4)(0,"+++ END_PSN                         # \"%s\" %d\n",uStack0000001c,
                 puStack00000020,param_5,param_6,param_7,param_8);
  }
  else {
    uVar19 = param_1[2];
    puVar13 = puStack00000020;
    (*(uint *)((char *)frame_ + 580)) = uVar19;
    ((int (*)())FUN_000d03b4)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 puStack00000020,param_4,uVar19,param_6,param_7,param_8);
    if (*(short *)(param_1 + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",puVar13,param_4,uVar19,param_6,param_7,param_8);
    }
    else {
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",puVar13,param_4,uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(param_1 + 6),param_4,
                   uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)param_1 + 0x1a),
                   param_4,uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(param_1 + 7),param_4,
                   uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)param_1 + 0x1e),
                   param_4,uVar19,param_6,param_7,param_8);
      if (*(byte *)((int)param_1 + 0xe) != 0) {
        ((int (*)())FUN_000d03b4)(0,"     UMRT_EN:               %3d\n",(uint)*(byte *)((int)param_1 + 0xe),
                     param_4,uVar19,param_6,param_7,param_8);
      }
      ((int (*)())FUN_000d03b4)(0,"     CF Instructions:       %3d\n",(uint)*(ushort *)(param_1 + 8),param_4,
                   uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)param_1 + 0x22),
                   param_4,uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(param_1 + 9),param_4,
                   uVar19,param_6,param_7,param_8);
      ((int (*)())FUN_000d03b4)(0,"     Start Addr:            %3d\n",(uint)*(ushort *)(param_1 + 4),param_4,
                   uVar19,param_6,param_7,param_8);
      puVar13 = (uint *)(uint)*(ushort *)((int)param_1 + 0x12);
      ((int (*)())FUN_000d03b4)(0,"     End Addr:              %3d\n",puVar13,param_4,uVar19,param_6,param_7,
                   param_8);
      ((int (*)())FUN_000d03b4)(0," \n",puVar13,param_4,uVar19,param_6,param_7,param_8);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",puVar13,param_4,uVar19,param_6,param_7,param_8);
    if ((param_1[0x12] == 1) && (0 < (int)(*(uint *)((char *)frame_ + 580)))) {
      puVar32 = param_1 + 0x24;
      iVar31 = 1;
      puVar41 = puVar32;
      puVar33 = param_1 + 0x12;
      do {
        puVar35 = puVar41;
        puVar13 = (uint *)(iVar31 + -1);
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",puVar13,param_4,uVar19,param_6,param_7,param_8);
        cVar9 = *(char *)((int)puVar33 + 0xb);
        if (cVar9 == '\0') {
          if (*(char *)((int)puVar33 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",puVar13,param_4,uVar19,param_6,param_7,
                         param_8);
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,uVar19,param_6,param_7,param_8);
        }
        else {
          uVar37 = *(byte *)((int)puVar33 + 0xf) & 0xf ^ 0xf;
          if (cVar9 == '\x01') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            uVar19 = (uint)*(byte *)((int)puVar33 + 10);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",puVar13,param_4,uVar19,param_6,param_7,param_8);
            if (*(char *)((int)puVar33 + 0xd) == '\0') {
              cVar9 = *(char *)((int)puVar33 + 0xb);
            }
            else {
              ((int (*)())FUN_000d03b4)(0," biased",puVar13,param_4,uVar19,param_6,param_7,param_8);
              cVar9 = *(char *)((int)puVar33 + 0xb);
            }
          }
          if (cVar9 == '\x02') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = fbuf",puVar13,param_4,uVar19,param_6,param_7,param_8);
          }
          else if (cVar9 == '\x03') {
            puVar13 = (uint *)(uint)*(ushort *)((int)puVar33 + 6);
            param_4 = (char *)(uVar37 * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = back",puVar13,param_4,uVar19,param_6,param_7,param_8);
          }
          else {
            if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())FUN_000d03b4)(0,"       ",puVar13,param_4,uVar19,param_6,param_7,param_8);
          }
LAB_000d1afc:
          if (*(char *)((int)puVar33 + 9) == '\0') goto LAB_000d1b5c;
          puVar13 = (uint *)(uint)*(ushort *)(puVar33 + 1);
          uVar19 = (uint)*(byte *)(puVar33 + 2);
          param_4 = (char *)((*(byte *)((int)puVar33 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",puVar13,param_4,uVar19,param_6,param_7,param_8);
          if (*(char *)(puVar33 + 3) == '\0') goto LAB_000d1b5c;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",puVar13,param_4,uVar19,param_6,param_7,param_8);
        }
        iVar31 = iVar31 + 1;
        if (*puVar32 != 1) break;
        puVar32 = puVar32 + 0x12;
        puVar41 = puVar35 + 0x12;
        puVar33 = puVar35;
      } while (iVar31 <= (int)(*(uint *)((char *)frame_ + 580)));
    }
    else {
      iVar31 = 1;
    }
    (*(int *)((char *)frame_ + 612)) = 0x1a1848;
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",puVar13,param_4,uVar19,param_6,param_7,param_8);
    ((int (*)())FUN_000d03b4)(0,(*(int *)((char *)frame_ + 612)) + 0x5b00,puVar13,param_4,uVar19,param_6,param_7,param_8);
    if (iVar31 <= (int)(*(uint *)((char *)frame_ + 580))) {
      (*(uint *)((char *)frame_ + 584)) = 0;
      puVar41 = param_1 + iVar31 * 0x12;
      (*(int *)((char *)frame_ + 592)) = 0;
      (*(uint * *)((char *)frame_ + 464)) = (uint *)0x0;
      (*(int *)((char *)frame_ + 460)) = 0;
      (*(int *)((char *)frame_ + 456)) = 0;
      (*(uint *)((char *)frame_ + 588)) = 0;
      (*(uint *)((char *)frame_ + 468)) = 0;
      do {
        if (*(char *)(puVar41 + 7) == '\0') {
          (*(uint *)((char *)frame_ + 62)) = (*(uint *)((char *)frame_ + 62)) & 0xffffff;
        }
        else {
          param_7 = " ign_unc";
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 62))) + 0)) = s_ign_unc_001a734c[0];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 62))) + 1)) = s_ign_unc_001a734c[1];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 62))) + 2)) = s_ign_unc_001a734c[2];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 62))) + 3)) = s_ign_unc_001a734c[3];
          ((char *)((char *)frame_ + 66))[0] = s_ign_unc_001a734c[4];
          ((char *)((char *)frame_ + 66))[1] = s_ign_unc_001a734c[5];
          ((char *)((char *)frame_ + 66))[2] = s_ign_unc_001a734c[6];
          ((char *)((char *)frame_ + 66))[3] = s_ign_unc_001a734c[7];
          (*(char *)((char *)frame_ + 70)) = s_ign_unc_001a734c[8];
        }
        if (*(char *)(puVar41 + 1) == '\0') {
          (*(uint *)((char *)frame_ + 12)) = (*(uint *)((char *)frame_ + 12)) & 0xffffff;
        }
        else {
          param_7 = " sem_wait";
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 12))) + 0)) = s_sem_wait_001a7358[0];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 12))) + 1)) = s_sem_wait_001a7358[1];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 12))) + 2)) = s_sem_wait_001a7358[2];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 12))) + 3)) = s_sem_wait_001a7358[3];
          ((char *)((char *)frame_ + 16))[0] = s_sem_wait_001a7358[4];
          ((char *)((char *)frame_ + 16))[1] = s_sem_wait_001a7358[5];
          ((char *)((char *)frame_ + 16))[2] = s_sem_wait_001a7358[6];
          ((char *)((char *)frame_ + 16))[3] = s_sem_wait_001a7358[7];
          ((char *)((char *)frame_ + 20))[0] = s_sem_wait_001a7358[8];
          ((char *)((char *)frame_ + 20))[1] = s_sem_wait_001a7358[9];
        }
        if (*(char *)((int)puVar41 + 0xb) == '\0') {
          (*(uint *)((char *)frame_ + 52)) = (*(uint *)((char *)frame_ + 52)) & 0xffffff;
        }
        else {
          param_7 = " alu_wait";
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 52))) + 0)) = s_alu_wait_001a7364[0];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 52))) + 1)) = s_alu_wait_001a7364[1];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 52))) + 2)) = s_alu_wait_001a7364[2];
          (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 52))) + 3)) = s_alu_wait_001a7364[3];
          ((char *)((char *)frame_ + 56))[0] = s_alu_wait_001a7364[4];
          ((char *)((char *)frame_ + 56))[1] = s_alu_wait_001a7364[5];
          ((char *)((char *)frame_ + 56))[2] = s_alu_wait_001a7364[6];
          ((char *)((char *)frame_ + 56))[3] = s_alu_wait_001a7364[7];
          ((char *)((char *)frame_ + 60))[0] = s_alu_wait_001a7364[8];
          ((char *)((char *)frame_ + 60))[1] = s_alu_wait_001a7364[9];
        }
        uVar37 = *puVar41;
        if (uVar37 == 2) {
          ((int (*)())FUN_000d03b4)(0,"  %d tex %02d    :  ",(*(int *)((char *)frame_ + 592)),(*(int *)((char *)frame_ + 460)),uVar19,param_6,param_7,param_8);
          bVar3 = *(byte *)((int)puVar41 + 0x1d);
          uVar7 = *(ushort *)((int)puVar41 + 0xe);
          puVar13 = (uint *)(uint)uVar7;
          uVar8 = *(ushort *)(puVar41 + 3);
          uVar19 = (*(byte *)((int)puVar41 + 0x1e) & 0x1f) << 3 | (uint)bVar3;
          puVar33 = (uint *)(uint)*(byte *)((int)puVar41 + 0x19);
          bVar24 = (bVar3 & 1) != 0;
          bVar4 = *(byte *)(puVar41 + 5);
          if (bVar24) {
            pcVar14 = (char *)((bVar4 >> 4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar14 = "_";
          }
          bVar2 = (bVar3 & 2) != 0;
          if (bVar2) {
            pcVar16 = (char *)((bVar4 >> 2 & 0xc) + 0x1dc259);
          }
          else {
            pcVar16 = "_";
          }
          bVar40 = (bVar3 & 4) != 0;
          if (bVar40) {
            pcVar20 = (char *)((bVar4 & 0xc) + 0x1dc259);
          }
          else {
            pcVar20 = "_";
          }
          bVar1 = (uVar19 >> 3 & 1) != 0;
          if (bVar1) {
            pcVar22 = (char *)((bVar4 & 3) * 4 + 0x1dc259);
          }
          else {
            pcVar22 = "_";
          }
          FUN_001a32d0(((undefined1 *)((char *)frame_ + 102)),"%s%s%s%s",pcVar14,pcVar16,pcVar20,pcVar22,uVar19,param_8);
          if ((*(byte *)((int)puVar41 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)puVar41 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",(uint)uVar8,((undefined1 *)((char *)frame_ + 102)),pcVar20,pcVar22,uVar19,param_8);
          }
          if (*(byte *)((int)puVar41 + 0x1a) == 2) {
            bVar3 = *(byte *)((int)puVar41 + 0x15);
            param_7 = (char *)(uint)bVar3;
            if (bVar24) {
              pcVar16 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
            }
            else {
              pcVar16 = "-";
            }
            if (bVar2) {
              param_4 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
            }
            else {
              param_4 = "-";
            }
            if (bVar40) {
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
            (*(uint *)((char *)frame_ + 584)) = (uint)*(byte *)((int)puVar41 + 0x1f);
            bVar3 = *(byte *)((int)puVar41 + 0x15);
            param_7 = (char *)(uint)bVar3;
            if ((*(byte *)((int)puVar41 + 0x1f) & 1) == 0) {
              param_8 = (byte *)(bVar3 & 0xc);
              param_7 = (char *)(((uint)param_7 & 3) * 4);
              param_6 = (uint *)((int)param_7 + 0x1dc259);
              pcVar16 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
              param_4 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
              pcVar14 = (char *)(param_8 + 0x1dc259);
            }
            else {
              pcVar16 = "-";
              param_4 = pcVar16;
              pcVar14 = pcVar16;
              param_6 = (uint *)pcVar16;
            }
          }
          puVar32 = ((uint *)((char *)frame_ + 117));
          FUN_001a32d0(puVar32,"%s%s%s%s",pcVar16,param_4,pcVar14,param_6,param_7,param_8);
          if ((uVar7 & 0x4000) == 0) {
            FUN_001a32d0(((uint *)((char *)frame_ + 72)),"r%02d",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          else {
            puVar13 = (uint *)((uint)puVar13 & 0xbfff);
            FUN_001a32d0(((uint *)((char *)frame_ + 72)),"r[AL+%02d]",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          puVar35 = ((uint *)((char *)frame_ + 72));
          if (*(char *)((int)puVar41 + 0x1b) == '\0') {
            (*(uint *)((char *)frame_ + 42)) = (*(uint *)((char *)frame_ + 42)) & 0xffffff;
          }
          else {
            param_7 = " sem_grab";
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 42))) + 0)) = s_sem_grab_001a73ac[0];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 42))) + 1)) = s_sem_grab_001a73ac[1];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 42))) + 2)) = s_sem_grab_001a73ac[2];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 42))) + 3)) = s_sem_grab_001a73ac[3];
            ((char *)((char *)frame_ + 46))[0] = s_sem_grab_001a73ac[4];
            ((char *)((char *)frame_ + 46))[1] = s_sem_grab_001a73ac[5];
            ((char *)((char *)frame_ + 46))[2] = s_sem_grab_001a73ac[6];
            ((char *)((char *)frame_ + 46))[3] = s_sem_grab_001a73ac[7];
            ((char *)((char *)frame_ + 50))[0] = s_sem_grab_001a73ac[8];
            ((char *)((char *)frame_ + 50))[1] = s_sem_grab_001a73ac[9];
          }
          bVar3 = *(byte *)((int)puVar41 + 0x1a);
          if (bVar3 < 8) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",puVar13,param_4,pcVar14,param_6,param_7,param_8);
              break;
            case 1:
              param_6 = &(*(uint *)((char *)frame_ + 12));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 42));
              ((int (*)())FUN_000d03b4)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",puVar35,puVar32,puVar33,param_6,
                           param_7,&(*(uint *)((char *)frame_ + 52)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              pcVar14 = (char *)puVar33;
              break;
            case 2:
              pcVar14 = (char *)&(*(uint *)((char *)frame_ + 12));
              param_6 = &(*(uint *)((char *)frame_ + 42));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 52));
              ((int (*)())FUN_000d03b4)(0,"kill(%s.%s)%s%s%s",puVar35,puVar32,pcVar14,param_6,param_7,param_8);
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              break;
            case 3:
              param_6 = &(*(uint *)((char *)frame_ + 12));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 42));
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",puVar35,puVar32,puVar33,param_6,
                           param_7,&(*(uint *)((char *)frame_ + 52)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              pcVar14 = (char *)puVar33;
              break;
            case 4:
              param_6 = &(*(uint *)((char *)frame_ + 12));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 42));
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",puVar35,puVar32,puVar33,
                           param_6,param_7,&(*(uint *)((char *)frame_ + 52)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              pcVar14 = (char *)puVar33;
              break;
            case 5:
              param_6 = &(*(uint *)((char *)frame_ + 12));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 42));
              ((int (*)())FUN_000d03b4)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",puVar35,puVar32,puVar33,param_6,
                           param_7,&(*(uint *)((char *)frame_ + 52)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              pcVar14 = (char *)puVar33;
              break;
            case 6:
              bVar3 = *(byte *)((int)puVar41 + 0x16);
              uVar19 = (uint)bVar3;
              bVar24 = ((*(uint *)((char *)frame_ + 584)) & 1) == 0;
              if (bVar24) {
                param_8 = (byte *)(bVar3 & 0xc);
                uVar19 = (uVar19 & 3) * 4;
                pcVar16 = (char *)(uVar19 + 0x1dc259);
                pcVar20 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
                pcVar14 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
                pbVar25 = param_8 + 0x1dc259;
              }
              else {
                pcVar20 = "-";
                pcVar14 = pcVar20;
                pbVar25 = (byte *)pcVar20;
                pcVar16 = pcVar20;
              }
              param_6 = ((uint *)((char *)frame_ + 87));
              FUN_001a32d0(param_6,"%s%s%s%s",pcVar20,pcVar14,pbVar25,pcVar16,uVar19,param_8);
              bVar3 = *(byte *)((int)puVar41 + 0x16);
              uVar19 = (uint)bVar3;
              pcVar14 = (char *)(uint)*(ushort *)(puVar41 + 4);
              if (bVar24) {
                param_8 = (byte *)(bVar3 & 0xc);
                uVar19 = (uVar19 & 3) * 4;
                pcVar20 = (char *)(uVar19 + 0x1dc259);
                pcVar22 = (char *)((bVar3 >> 4 & 0xc) + 0x1dc259);
                pcVar16 = (char *)((bVar3 >> 2 & 0xc) + 0x1dc259);
                pbVar25 = param_8 + 0x1dc259;
              }
              else {
                pcVar22 = "-";
                pcVar16 = pcVar22;
                pbVar25 = (byte *)pcVar22;
                pcVar20 = pcVar22;
              }
              FUN_001a32d0(((uint *)((char *)frame_ + 132)),"%s%s%s%s",pcVar22,pcVar16,pbVar25,pcVar20,uVar19,param_8);
              param_7 = (char *)(uint)*(ushort *)((int)puVar41 + 0x12);
              in_stack_fffffd2c = &(*(uint *)((char *)frame_ + 12));
              ((int (*)())FUN_000d03b4)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",puVar35,
                           puVar32,pcVar14,param_6,param_7,((uint *)((char *)frame_ + 132)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              break;
            case 7:
              param_6 = &(*(uint *)((char *)frame_ + 12));
              param_7 = (char *)&(*(uint *)((char *)frame_ + 42));
              ((int (*)())FUN_000d03b4)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",puVar35,puVar32,puVar33,
                           param_6,param_7,&(*(uint *)((char *)frame_ + 52)));
              puVar13 = puVar35;
              param_4 = (char *)puVar32;
              pcVar14 = (char *)puVar33;
            }
          }
          else {
            puVar13 = &(*(uint *)((char *)frame_ + 12));
            param_4 = (char *)&(*(uint *)((char *)frame_ + 42));
            pcVar14 = (char *)&(*(uint *)((char *)frame_ + 52));
            param_6 = &(*(uint *)((char *)frame_ + 62));
            ((int (*)())FUN_000d03b4)(0,"UNKNOWN_OP%s%s%s%s",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          pbVar25 = (byte *)((int)puVar41 + 5);
          if (*(char *)((int)puVar41 + 5) != '\0') {
            if (*(char *)((int)puVar41 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *pbVar25;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 1:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.rgb",puVar13,param_4,pcVar14,param_6,param_7,pbVar25);
                break;
              case 2:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.rrr",puVar13,param_4,pcVar14,param_6,param_7,pbVar25);
                break;
              case 3:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.ggg",puVar13,param_4,pcVar14,param_6,param_7,pbVar25);
                break;
              case 4:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.bbb",puVar13,param_4,pcVar14,param_6,param_7,pbVar25);
                break;
              case 5:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.aaa",puVar13,param_4,pcVar14,param_6,param_7,pbVar25);
              }
            }
          }
          param_8 = (byte *)((int)puVar41 + 7);
          if (*(char *)((int)puVar41 + 7) != '\0') {
            if (*(char *)(puVar41 + 2) == '\0') {
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *param_8;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 0:
                break;
              default:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.a",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 2:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.r",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 3:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.g",puVar13,param_4,pcVar14,param_6,param_7,param_8);
                break;
              case 4:
                puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.b",puVar13,param_4,pcVar14,param_6,param_7,param_8);
              }
            }
          }
          if (*(char *)((int)puVar41 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0," write_inactive",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          }
          ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,pcVar14,param_6,param_7,param_8);
          uVar37 = *puVar41;
          (*(int *)((char *)frame_ + 460)) = (*(int *)((char *)frame_ + 460)) + 1;
        }
        uVar43 = (undefined2)((uint)in_stack_fffffd2c >> 0x10);
        if ((uVar37 == 3) || (uVar37 == 4)) {
          pbVar25 = (byte *)((int)puVar41 + 0x31);
          (*(uint *)((char *)frame_ + 588)) = (uint)*(byte *)((int)puVar41 + 0x43);
          (*(uint *)((char *)frame_ + 468)) = (uint)*(byte *)(puVar41 + 0x11);
          switch(*(undefined1 *)((int)puVar41 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            bVar24 = true;
            bVar40 = true;
            bVar2 = true;
            (*(uint *)((char *)frame_ + 552)) = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            bVar24 = true;
            bVar40 = true;
            bVar2 = false;
            (*(uint *)((char *)frame_ + 552)) = 0;
            break;
          case 2:
            bVar24 = true;
            (*(uint *)((char *)frame_ + 552)) = 3;
            bVar40 = true;
            bVar2 = false;
            break;
          default:
            bVar24 = false;
            bVar40 = false;
            bVar2 = false;
            (*(uint *)((char *)frame_ + 552)) = 0;
            break;
          case 9:
            bVar24 = true;
            bVar40 = false;
            bVar2 = false;
            (*(uint *)((char *)frame_ + 552)) = 0;
          }
          puVar33 = puVar41 + 0x10;
          if (*(byte *)(puVar41 + 0x10) < 0x10) {
            uVar19 = 1 << ((int)(char)*(byte *)(puVar41 + 0x10) & 0x3fU);
            if ((uVar19 & 0x61) == 0) {
              if ((uVar19 & 0xc00c) == 0) {
                if ((uVar19 & 0x3f80) != 0) {
                  (*(uint *)((char *)frame_ + 552)) = (*(uint *)((char *)frame_ + 552)) | 1;
                }
              }
              else {
                (*(uint *)((char *)frame_ + 552)) = 3;
              }
            }
            else {
              (*(uint *)((char *)frame_ + 552)) = 7;
            }
          }
          (*(uint *)((char *)frame_ + 476)) = *(byte *)((int)puVar41 + 0x2a) & 0xffffff7f;
          uVar37 = (uint)*(byte *)(puVar41 + 0xb);
          (*(uint *)((char *)frame_ + 480)) = *(byte *)((int)puVar41 + 0x2b) & 0xffffff7f;
          uVar26 = (uint)*(byte *)((int)puVar41 + 0x3a);
          uVar19 = (uint)*(byte *)((int)puVar41 + 0x3b);
          (*(uint *)((char *)frame_ + 484)) = *(byte *)(puVar41 + 0xb) & 0xffffff7f;
          (*(uint *)((char *)frame_ + 488)) = *(byte *)((int)puVar41 + 0x39) & 0xffffff7f;
          (*(uint *)((char *)frame_ + 492)) = *(byte *)((int)puVar41 + 0x3a) & 0xffffff7f;
          (*(uint *)((char *)frame_ + 496)) = *(byte *)((int)puVar41 + 0x3b) & 0xffffff7f;
          (*(ushort *)((char *)frame_ + 596)) = *(ushort *)(puVar41 + 10);
          uVar34 = (uint)*(ushort *)((int)puVar41 + 0xe);
          puVar13 = (uint *)(uint)*(ushort *)(puVar41 + 4);
          puVar32 = (uint *)(uint)*(ushort *)((int)puVar41 + 0x12);
          puVar35 = (uint *)(uint)*(ushort *)((int)puVar41 + 0x1a);
          param_6 = (uint *)(uint)*(ushort *)(puVar41 + 7);
          param_7 = (char *)(uint)*(ushort *)((int)puVar41 + 0x1e);
          uVar7 = *(ushort *)(puVar41 + 9);
          uVar8 = *(ushort *)((int)puVar41 + 0x26);
          (*(uint * *)((char *)frame_ + 548)) = (uint *)(uint)*(byte *)(puVar41 + 0xe);
          uVar28 = (uint)*(byte *)((int)puVar41 + 0x36);
          uVar27 = (uint)*(byte *)((int)puVar41 + 0x37);
          (*(uint *)((char *)frame_ + 576)) = (uint)*(byte *)((int)puVar41 + 0x2d);
          (*(uint *)((char *)frame_ + 572)) = (uint)*(byte *)((int)puVar41 + 0x2e);
          (*(uint *)((char *)frame_ + 568)) = (uint)*(byte *)((int)puVar41 + 0x2f);
          (*(uint *)((char *)frame_ + 564)) = (uint)*(byte *)(puVar41 + 0xf);
          (*(uint *)((char *)frame_ + 560)) = (uint)*(byte *)((int)puVar41 + 0x3d);
          (*(uint *)((char *)frame_ + 556)) = (uint)*(byte *)((int)puVar41 + 0x3e);
          if (bVar24) {
            bVar24 = (*(uint *)((char *)frame_ + 476)) != 3;
            if (bVar24) {
LAB_000d2654:
              bVar1 = false;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar7);
              bVar1 = true;
              if (iVar10 != 0) goto LAB_000d2654;
            }
            if (!bVar24) {
              bVar24 = true;
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar7);
              if (iVar10 != 0) goto LAB_000d2674;
            }
            bVar24 = false;
          }
          else {
            bVar24 = false;
            bVar1 = false;
          }
LAB_000d2674:
          if (bVar40) {
            bVar40 = (*(uint *)((char *)frame_ + 480)) != 3;
            if (bVar40) {
LAB_000d269c:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar8);
              bVar3 = 1;
              if (iVar10 != 0) goto LAB_000d269c;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (bVar40) {
LAB_000d26bc:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)uVar8);
              bVar3 = 1;
              if (iVar10 == 0) goto LAB_000d26bc;
            }
            bVar24 = (bool)(bVar24 | bVar3);
          }
          if (bVar2) {
            bVar2 = (*(uint *)((char *)frame_ + 484)) != 3;
            if (bVar2) {
LAB_000d26ec:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)(*(ushort *)((char *)frame_ + 596)));
              bVar3 = 1;
              if (iVar10 != 0) goto LAB_000d26ec;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (bVar2) {
LAB_000d270c:
              bVar3 = 0;
            }
            else {
              iVar10 = ((int (*)())FUN_000d10a8)((uint)(*(ushort *)((char *)frame_ + 596)));
              bVar3 = 1;
              if (iVar10 == 0) goto LAB_000d270c;
            }
            bVar24 = (bool)(bVar24 | bVar3);
          }
          if (((*(uint *)((char *)frame_ + 552)) & 1) != 0) {
            if (((*(uint *)((char *)frame_ + 488)) != 3) || (bVar3 = 1, uVar28 == 3)) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (((*(uint *)((char *)frame_ + 488)) != 3) || (bVar3 = 1, uVar28 != 3)) {
              bVar3 = 0;
            }
            bVar24 = (bool)(bVar24 | bVar3);
          }
          puVar21 = (uint *)((*(uint *)((char *)frame_ + 552)) & 2);
          if (puVar21 != (uint *)0x0) {
            if (((*(uint *)((char *)frame_ + 492)) != 3) || (bVar3 = 1, uVar27 == 3)) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (((*(uint *)((char *)frame_ + 492)) != 3) || (bVar3 = 1, uVar27 != 3)) {
              bVar3 = 0;
            }
            bVar24 = (bool)(bVar24 | bVar3);
          }
          if (((*(uint *)((char *)frame_ + 552)) & 4) != 0) {
            if (((*(uint *)((char *)frame_ + 496)) != 3) ||
               (bVar3 = 1, puVar21 = (*(uint * *)((char *)frame_ + 548)), (*(uint * *)((char *)frame_ + 548)) == (uint *)((int)((unsigned char *)0x0) + 3))) {
              bVar3 = 0;
            }
            bVar1 = (bool)(bVar1 | bVar3);
            if (((*(uint *)((char *)frame_ + 496)) != 3) || (bVar3 = 1, (*(uint * *)((char *)frame_ + 548)) != (uint *)((int)((unsigned char *)0x0) + 3))) {
              bVar3 = 0;
            }
            bVar24 = (bool)(bVar24 | bVar3);
          }
          if (bVar1) {
            iVar10 = (*(int *)((char *)frame_ + 592));
            puVar17 = (*(uint * *)((char *)frame_ + 464));
            dVar42 = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.rgb = ",(*(int *)((char *)frame_ + 592)),(*(uint * *)((char *)frame_ + 464)),
                                          puVar21,uVar19,uVar37,uVar26);
            cVar9 = *(char *)(puVar41 + 0xc);
            if (cVar9 == '\x01') {
              dVar42 = (double)((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),uVar34,iVar10,puVar17,puVar21,uVar19,uVar37,
                                            uVar26,dVar42);
              ((double (*)())FUN_000d10dc)(&(*(uint *)((char *)frame_ + 22)),puVar13,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&(*(uint *)((char *)frame_ + 22)),&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\0') {
              ((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),uVar34,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x02') {
              dVar42 = (double)((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),uVar34,iVar10,puVar17,puVar21,uVar19,uVar37,
                                            uVar26,dVar42);
              ((double (*)())FUN_000d10dc)(&(*(uint *)((char *)frame_ + 22)),puVar13,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&(*(uint *)((char *)frame_ + 22)),&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x03') {
              ((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),uVar34,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",iVar10,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
          }
          if (bVar24) {
            iVar10 = (*(int *)((char *)frame_ + 592));
            puVar17 = (*(uint * *)((char *)frame_ + 464));
            dVar42 = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.a   = ",(*(int *)((char *)frame_ + 592)),(*(uint * *)((char *)frame_ + 464)),
                                          puVar21,uVar19,uVar37,uVar26);
            cVar9 = *(char *)((int)puVar41 + 0x3f);
            if (cVar9 == '\x01') {
              dVar42 = (double)((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),puVar35,iVar10,puVar17,puVar21,uVar19,uVar37,
                                            uVar26,dVar42);
              ((double (*)())FUN_000d10dc)(&(*(uint *)((char *)frame_ + 22)),param_6,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&(*(uint *)((char *)frame_ + 22)),&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\0') {
              ((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),puVar35,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x02') {
              dVar42 = (double)((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),puVar35,iVar10,puVar17,puVar21,uVar19,uVar37,
                                            uVar26,dVar42);
              ((double (*)())FUN_000d10dc)(&(*(uint *)((char *)frame_ + 22)),param_6,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&(*(uint *)((char *)frame_ + 22)),&(*(undefined2 *)((char *)frame_ + 32)),puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x03') {
              ((double (*)())FUN_000d10dc)(&(*(undefined2 *)((char *)frame_ + 32)),puVar35,iVar10,puVar17,puVar21,uVar19,uVar37,uVar26,dVar42);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&(*(undefined2 *)((char *)frame_ + 32)),puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",iVar10,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
          }
          puVar17 = (*(uint * *)((char *)frame_ + 464));
          ((int (*)())FUN_000d03b4)(0,"  %d alu %02d rgb:  ",(*(int *)((char *)frame_ + 592)),(*(uint * *)((char *)frame_ + 464)),puVar21,uVar19,uVar37,uVar26);
          uVar15 = (uint)*(byte *)((int)puVar41 + 0x15);
          bVar3 = *(byte *)(puVar41 + 5);
          if (uVar15 == 0) {
LAB_000d2b24:
            ((int (*)())FUN_000d03b4)(0,"           ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
          }
          else if (*puVar41 == 3) {
            iVar10 = uVar15 * 4;
            uVar15 = (uint)*(byte *)((int)puVar41 + 0x16);
            puVar17 = (uint *)(iVar10 + 0x1dc239);
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
          }
          else {
            if (*puVar41 != 4) goto LAB_000d2b24;
            uVar15 = uVar15 * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"pred.%s = ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
            cVar9 = *(char *)((int)puVar41 + 0x16);
            if (cVar9 == '\x01') {
              ((int (*)())FUN_000d03b4)(0,"(<) ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\0') {
              ((int (*)())FUN_000d03b4)(0,"(==) ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x02') {
              ((int (*)())FUN_000d03b4)(0,"(>=) ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
            else if (cVar9 == '\x03') {
              ((int (*)())FUN_000d03b4)(0,"(!=) ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
            }
          }
          if (bVar3 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
          }
          else {
            uVar15 = (uint)*(ushort *)(puVar41 + 3);
            puVar17 = (uint *)((uint)bVar3 * 4 + 0x1dc239);
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
          }
          if (*(char *)((int)puVar41 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",uVar15,puVar17,puVar21,uVar19,uVar37,uVar26);
          }
          puVar21 = ((uint *)((char *)frame_ + 164));
          uVar11 = CONCAT22(uVar43,uVar7);
          ((int (*)())FUN_000d13a4)(puVar21,uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 476)),(*(uint *)((char *)frame_ + 576)),
                       uVar11,(uint)*pbVar25);
          uVar11 = CONCAT22((short)((uint)uVar11 >> 0x10),uVar8);
          param_4 = (char *)((uint *)((char *)frame_ + 324));
          ((int (*)())FUN_000d13a4)(param_4,uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 480)),(*(uint *)((char *)frame_ + 572)),
                       uVar11,(uint)*pbVar25);
          puVar17 = ((uint *)((char *)frame_ + 292));
          ((int (*)())FUN_000d13a4)(puVar17,uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 484)),(*(uint *)((char *)frame_ + 568)),
                       CONCAT22((short)((uint)uVar11 >> 0x10),(*(ushort *)((char *)frame_ + 596))),(uint)*pbVar25);
          (*(uint * *)((char *)frame_ + 608)) = ((uint *)((char *)frame_ + 260));
          ((int (*)())FUN_000d1624)((*(uint * *)((char *)frame_ + 608)),uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 488)),(*(uint *)((char *)frame_ + 564)),
                       uVar28,(uint)*(byte *)puVar33);
          (*(uint * *)((char *)frame_ + 604)) = ((uint *)((char *)frame_ + 228));
          ((int (*)())FUN_000d1624)((*(uint * *)((char *)frame_ + 604)),uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 492)),(*(uint *)((char *)frame_ + 560)),
                       uVar27,(uint)*(byte *)puVar33);
          (*(uint * *)((char *)frame_ + 600)) = ((uint *)((char *)frame_ + 196));
          uVar19 = (*(uint *)((char *)frame_ + 496));
          in_stack_fffffd2c = (*(uint * *)((char *)frame_ + 548));
          ((int (*)())FUN_000d1624)((*(uint * *)((char *)frame_ + 600)),uVar34,puVar13,puVar32,puVar35,param_6,param_7,(*(uint *)((char *)frame_ + 496)),(*(uint *)((char *)frame_ + 556)),
                       (*(uint * *)((char *)frame_ + 548)),(uint)*(byte *)puVar33);
          bVar3 = *pbVar25;
          if (bVar3 < 0xd) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",puVar21,param_4,puVar35,param_6,param_7,uVar19);
              puVar17 = puVar35;
              break;
            case 2:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              puVar17 = (uint *)param_4;
              param_6 = (*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",puVar21,(*(uint * *)((char *)frame_ + 608)),param_4,(*(uint * *)((char *)frame_ + 604)),param_7,uVar19);
              param_4 = (char *)puVar13;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",puVar21,param_4,puVar35,param_6,param_7,uVar19);
              puVar17 = puVar35;
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",puVar21,param_4,puVar35,param_6,param_7,uVar19);
              puVar17 = puVar35;
              break;
            case 6:
              goto switchD_000d2d30_caseD_6;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",puVar21,puVar32,puVar35,param_6,param_7,uVar19);
              param_4 = (char *)puVar32;
              puVar17 = puVar35;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",puVar13,puVar32,puVar35,param_6,param_7,uVar19);
              puVar21 = puVar13;
              param_4 = (char *)puVar32;
              puVar17 = puVar35;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",puVar21,param_4,puVar35,param_6,param_7,uVar19);
              puVar17 = puVar35;
              break;
            case 0xc:
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",puVar21,param_4,puVar35,param_6,param_7,uVar19);
              puVar17 = puVar35;
            }
          }
          else {
switchD_000d2d30_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar13,puVar32,puVar35,param_6,param_7,uVar19);
            puVar21 = puVar13;
            param_4 = (char *)puVar32;
            puVar17 = puVar35;
          }
          bVar3 = *(byte *)((int)puVar41 + 0x32);
          if (bVar3 < 7) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4",puVar21,param_4,puVar17,param_6,param_7,uVar19);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8",puVar21,param_4,puVar17,param_6,param_7,uVar19);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???",puVar21,param_4,puVar17,param_6,param_7,uVar19);
          }
          if (((*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 12))) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 52))) + 0)) != '\0')) {
            puVar21 = &(*(uint *)((char *)frame_ + 12));
            param_4 = (char *)&(*(uint *)((char *)frame_ + 52));
            ((int (*)())FUN_000d03b4)(0,"%s%s",puVar21,param_4,puVar17,param_6,param_7,uVar19);
          }
          param_8 = (byte *)((int)puVar41 + 5);
          if (*(char *)((int)puVar41 + 5) != '\0') {
            if (*(char *)((int)puVar41 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 2)));
            }
            else {
              param_7 = "!p";
              (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            bVar3 = *param_8;
            if (bVar3 < 6) {
              param_7 = (char *)(0);
              switch(bVar3) {
              case 1:
                puVar21 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.rgb",puVar21,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 2:
                puVar21 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.rrr",puVar21,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 3:
                puVar21 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.ggg",puVar21,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 4:
                puVar21 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.bbb",puVar21,param_4,puVar17,param_6,param_7,param_8);
                break;
              case 5:
                puVar21 = &(*(undefined4 *)((char *)frame_ + 8));
                ((int (*)())FUN_000d03b4)(0," %s.aaa",puVar21,param_4,puVar17,param_6,param_7,param_8);
              }
            }
          }
          ((int (*)())FUN_000d03b4)(0,"\n",puVar21,param_4,puVar17,param_6,param_7,param_8);
          puVar13 = (*(uint * *)((char *)frame_ + 464));
          ((int (*)())FUN_000d03b4)(0,"         alpha:  ",(*(uint * *)((char *)frame_ + 464)),param_4,puVar17,param_6,param_7,param_8);
          cVar9 = *(char *)(puVar41 + 8);
          bVar24 = *(char *)((int)puVar41 + 0x21) != '\0';
          cVar5 = *(char *)((int)puVar41 + 0x23);
          if (bVar24) {
            if (*puVar41 == 3) {
              puVar13 = (uint *)(uint)*(byte *)((int)puVar41 + 0x22);
              ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
            }
            else if (*puVar41 == 4) {
              ((int (*)())FUN_000d03b4)(0,"pred.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
              cVar6 = *(char *)((int)puVar41 + 0x22);
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
          if ((!bVar24) && (!bVar2)) {
            ((int (*)())FUN_000d03b4)(0,"           ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (cVar9 == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          else {
            puVar13 = (uint *)(uint)*(ushort *)(puVar41 + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)((int)puVar41 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)puVar33;
          if (bVar3 < 0x10) {
            param_7 = (char *)(0);
            switch(bVar3) {
            case 0:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              puVar17 = (*(uint * *)((char *)frame_ + 600));
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 600)),param_6,param_7,param_8);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",puVar13,param_4,puVar17,param_6,param_7,param_8);
              break;
            case 2:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),puVar17,param_6,param_7,param_8);
              break;
            case 3:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),puVar17,param_6,param_7,param_8);
              break;
            case 4:
              goto switchD_000d324c_caseD_4;
            case 5:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              puVar17 = (*(uint * *)((char *)frame_ + 600));
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 600)),param_6,param_7,param_8);
              break;
            case 6:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              puVar17 = (*(uint * *)((char *)frame_ + 600));
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),(*(uint * *)((char *)frame_ + 600)),param_6,param_7,param_8);
              break;
            case 7:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 8:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 9:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 10:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xb:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xc:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"sin(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xd:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              ((int (*)())FUN_000d03b4)(0,"cos(%s)",(*(uint * *)((char *)frame_ + 608)),param_4,puVar17,param_6,param_7,param_8);
              break;
            case 0xe:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),puVar17,param_6,param_7,param_8);
              break;
            case 0xf:
              puVar13 = (*(uint * *)((char *)frame_ + 608));
              param_4 = (char *)(*(uint * *)((char *)frame_ + 604));
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",(*(uint * *)((char *)frame_ + 608)),(*(uint * *)((char *)frame_ + 604)),puVar17,param_6,param_7,param_8);
            }
          }
          else {
switchD_000d324c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          bVar3 = *(byte *)((int)puVar41 + 0x41);
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
          if (*(char *)((int)puVar41 + 10) == '\0') {
            param_8 = (byte *)((int)puVar41 + 7);
            if (*(char *)((int)puVar41 + 7) != '\0') {
              if (*(char *)(puVar41 + 2) == '\0') {
                (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 2)));
              }
              else {
                param_7 = "!p";
                (*(unsigned int *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 8))) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
              }
              bVar3 = *param_8;
              if (bVar3 < 6) {
                param_7 = (char *)(0);
                switch(bVar3) {
                case 0:
                  break;
                default:
                  puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                  ((int (*)())FUN_000d03b4)(0," %s.a",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 2:
                  puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                  ((int (*)())FUN_000d03b4)(0," %s.r",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 3:
                  puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                  ((int (*)())FUN_000d03b4)(0," %s.g",puVar13,param_4,puVar17,param_6,param_7,param_8);
                  break;
                case 4:
                  puVar13 = &(*(undefined4 *)((char *)frame_ + 8));
                  ((int (*)())FUN_000d03b4)(0," %s.b",puVar13,param_4,puVar17,param_6,param_7,param_8);
                }
              }
            }
            if (*(char *)((int)puVar41 + 9) != '\0') {
              ((int (*)())FUN_000d03b4)(0," write_inactive",puVar13,param_4,puVar17,param_6,param_7,param_8);
            }
            ((int (*)())FUN_000d03b4)(0," \n",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          else {
            ((int (*)())FUN_000d03b4)(0," last\n",puVar13,param_4,puVar17,param_6,param_7,param_8);
          }
          if (*(char *)(puVar41 + 0xd) != '\0') {
            puVar13 = (*(uint * *)((char *)frame_ + 464));
            ((int (*)())FUN_000d03b4)(0,"   alu %02d post-NOP\n",(*(uint * *)((char *)frame_ + 464)),param_4,puVar17,param_6,param_7,param_8
                        );
          }
          uVar37 = *puVar41;
          (*(uint * *)((char *)frame_ + 464)) = (uint *)((int)(*(uint * *)((char *)frame_ + 464)) + 1);
        }
        if (uVar37 == 5) {
          if ((*(uint *)((char *)frame_ + 468)) == 1) {
            param_7 = "lt";
            (*(undefined2 *)((char *)frame_ + 32)) = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if ((*(uint *)((char *)frame_ + 468)) == 0) {
            param_7 = "eq";
            (*(undefined2 *)((char *)frame_ + 32)) = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if ((*(uint *)((char *)frame_ + 468)) == 2) {
            param_7 = "ge";
            (*(undefined2 *)((char *)frame_ + 32)) = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if ((*(uint *)((char *)frame_ + 468)) == 3) {
            param_7 = "ne";
            (*(undefined2 *)((char *)frame_ + 32)) = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            (*(undefined2 *)((char *)frame_ + 32)) = CONCAT21(0x2000,(*(undefined1 *)((char *)frame_ + 34)));
          }
          if ((*(uint *)((char *)frame_ + 588)) == 0) {
            (*(uint *)((char *)frame_ + 22)) = 0x72656400;
          }
          else if ((*(uint *)((char *)frame_ + 588)) == 1) {
            param_7 = "alpha";
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 22))) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 22))) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 22))) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&((*(uint *)((char *)frame_ + 22))) + 3)) = s_alpha_001a77e8[3];
            ((char *)((char *)frame_ + 26))[0] = s_alpha_001a77e8[4];
            ((char *)((char *)frame_ + 26))[1] = s_alpha_001a77e8[5];
          }
          else {
            (*(uint *)((char *)frame_ + 22)) = CONCAT22(0x2000,(*(unsigned short *)((unsigned char *)&((*(uint *)((char *)frame_ + 22))) + 2)));
          }
          param_4 = (char *)((uint *)((char *)frame_ + 356));
          ((int (*)())FUN_000d03b4)(0,"  %d cf  %02d    :  ",(*(int *)((char *)frame_ + 592)),(*(int *)((char *)frame_ + 456)),(*(uint *)((char *)frame_ + 468)),param_6,param_7,param_8);
          in_stack_fffffd2c = (uint *)0x0;
          param_8 = (byte *)((uint)*(byte *)((int)puVar41 + 0x15) * 10 + 0x1dc1bc);
          param_7 = (char *)((uint)*(byte *)(puVar41 + 5) * 10 + 0x1dc1bc);
          FUN_001a32d0(param_4,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       (uint)*(byte *)((int)puVar41 + 0x12),(uint)*(byte *)(puVar41 + 4),
                       (uint)*(byte *)((int)puVar41 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)puVar41 + 0x11) * 5 + 0x1dc1da,param_7,param_8);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            iVar10 = 0;
          }
          else {
            ppuVar38 = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            iVar10 = 0;
            puVar39 = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              uVar11 = _strlen(puVar39);
              iVar12 = _strncmp(puVar39,param_4,uVar11);
              if (iVar12 == 0) break;
              puVar39 = *ppuVar38;
              iVar10 = iVar10 + 2;
              ppuVar38 = ppuVar38 + 2;
            } while (puVar39 != (undefined *)0x0);
          }
          puVar13 = (uint *)(PTR_s_IF_b_001dc2cc)[iVar10];
          puVar33 = &(*(uint *)((char *)frame_ + 12));
          param_6 = &(*(uint *)((char *)frame_ + 52));
          ((int (*)())FUN_000d03b4)(0,"%s(%s)%s%s",puVar13,param_4,puVar33,param_6,param_7,param_8);
          cVar9 = *(char *)((int)puVar41 + 0x12);
          if ((cVar9 == -0x10) || (cVar9 == '\x0f')) {
            puVar13 = &(*(uint *)((char *)frame_ + 22));
            param_4 = (char *)&(*(undefined2 *)((char *)frame_ + 32));
            ((int (*)())FUN_000d03b4)(0,"( prev_alu: %s %s )\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          else if ((cVar9 == -0x56) || (cVar9 == 'U')) {
            puVar13 = (uint *)(uint)*(byte *)((int)puVar41 + 0x17);
            ((int (*)())FUN_000d03b4)(0,"( bool_addr: %d )\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"\n",puVar13,param_4,puVar33,param_6,param_7,param_8);
          }
          (*(int *)((char *)frame_ + 456)) = (*(int *)((char *)frame_ + 456)) + 1;
        }
        iVar31 = iVar31 + 1;
        puVar41 = puVar41 + 0x12;
        (*(int *)((char *)frame_ + 592)) = (*(int *)((char *)frame_ + 592)) + 1;
        uVar19 = (*(uint *)((char *)frame_ + 580));
      } while (iVar31 <= (int)(*(uint *)((char *)frame_ + 580)));
    }
    ((int (*)())FUN_000d03b4)(0,(*(int *)((char *)frame_ + 612)) + 0x5b00,puVar13,param_4,uVar19,param_6,param_7,param_8);
    ((int (*)())FUN_000d03b4)(0,"======== End r520 neutral format pixel shader =============\n",puVar13,param_4,
                 uVar19,param_6,param_7,param_8);
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

