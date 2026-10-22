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
  uint loopIndex;
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
      loopIndex = 0;
      iVar9 = param_2;
      do {
        loopIndex = loopIndex + 1;
        uVar3 = FUN_000c73a0(param_2);
        *(undefined4 *)(iVar9 + 0x17c) = uVar3;
        iVar9 = iVar9 + 4;
      } while (loopIndex != uVar7);
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
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  int allocation;
  
  allocation = _malloc(0x28);
  iVar1 = *param_1;
  *param_1 = allocation;
  *(int *)(allocation + 0x24) = iVar1;
  return _memcpy(allocation,param_2,0x24);
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
  /* Same undersized-buffer defect as auStack_c148 below (issue #64), same function, a sibling call
   * site: declared 76 bytes but memset to 0xbc=188 (0x2b18-0xbc=0x2a5c, exactly this buffer's own
   * sibling declared right after it - confirming the real size). Enlarged to match. */
  undefined1 auStack_2b18 [0xbc];
  uint *local_2acc;
  int local_2ac8;
  undefined4 local_2ac0 [8];
  undefined4 local_2aa0 [16];
  int local_2a60;
  /* Same undersized-buffer defect as auStack_9d1c below (issue #64), same function, a sibling call
   * site: declared 72 bytes but memset to 0x674=1652. Enlarged to match. */
  undefined1 auStack_2a5c [0x674];
  undefined4 local_2a14;
  undefined4 local_2a10;
  uint local_2a08;
  uint local_2a04;
  int local_29fc;
  int local_29f8;
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
  
  iVar38 = 8;
  iVar11 = 0;
  do {
    *(undefined4 *)((int)local_2b38 + iVar11) = 0xffffffff;
    *(undefined4 *)((int)local_2b58 + iVar11) = 0xffffffff;
    iVar11 = iVar11 + 4;
    iVar38 = iVar38 + -1;
  } while (iVar38 != 0);
  pppppppuVar18 = param_3;
  iVar11 = _malloc(0x400);
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
  iVar38 = param_2[1];
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
  puVar29 = local_2260;
  local_6c = puVar29;
  local_23bc[0] = local_2b58[0];
  do {
    *puVar29 = 0;
    puVar29[0x408] = 0;
    puVar29 = puVar29 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
  puVar16 = local_1b0;
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
  local_2bb4 = puVar29 + 2;
  puVar26 = local_2bb4;
switchD_000c90cc_caseD_18:
  puVar29 = puVar26;
  if (puVar29 < puVar31 + iVar38) goto code_r0x000c90a4;
  if (local_220 != (uint *******)0x0) {
    puVar29 = (uint *)0x0;
    uVar33 = 0;
    goto LAB_000ca6bc;
  }
  iVar36 = (iVar36 + iVar38) * 4;
  local_2398 = local_23e8;
  if (local_239c != 0) {
    iVar36 = iVar36 + 0x48;
  }
  uVar33 = iVar36 + iVar39 * 4;
  bVar4 = local_218 != 0;
  if (bVar4) {
    uVar33 = uVar33 + 0x14;
  }
  uVar32 = uVar33;
  if ((local_1f8[0] != 0) && (uVar32 = uVar33 + 0xc, bVar4)) {
    uVar32 = uVar33 + 0x24;
  }
  uVar33 = uVar32;
  if ((local_1f8[1] != 0) && (uVar33 = uVar32 + 0xc, bVar4)) {
    uVar33 = uVar32 + 0x24;
  }
  uVar32 = uVar33;
  if ((local_1f8[2] != 0) && (uVar32 = uVar33 + 0xc, bVar4)) {
    uVar32 = uVar33 + 0x24;
  }
  uVar22 = uVar32;
  if ((local_1f8[3] != 0) && (uVar22 = uVar32 + 0xc, bVar4)) {
    uVar22 = uVar32 + 0x24;
  }
  if (((local_1dc != 0) && (local_1e4 != 0)) && (local_1b4 == (uint *******)0x0)) {
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
  piVar12 = local_1f8;
  iVar39 = 4;
  do {
    if (*piVar12 != 0) {
      uVar22 = uVar22 + 0x2c;
    }
    piVar12 = piVar12 + 1;
    iVar39 = iVar39 + -1;
  } while (iVar39 != 0);
LAB_000c99d4:
  if (((local_1d0 != 0) || (local_1c8 != 0)) || (uVar33 = uVar22, local_1b4 == (uint *******)0x0)) {
    if ((local_1d4 == 0) && (local_1cc != 0)) {
      uVar22 = uVar22 + 0xc;
    }
    uVar33 = uVar22;
    if ((local_1b4 == (uint *******)0x0) && (uVar33 = uVar22 + 0xc, local_d8 != 0)) {
      uVar33 = uVar22 + 0x18;
    }
  }
  bVar4 = true;
  pppppppuVar20 = local_1b4;
  pppppppuVar25 = local_220;
  puVar29 = (uint *)_malloc(uVar33 + 0x10);
  *puVar29 = *puVar31;
  local_2bb4 = puVar31 + 2;
  puVar29[1] = puVar31[1];
  puVar26 = local_2bb4;
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
    local_2bb4 = puVar29 + 1;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar9 = 0;
LAB_000c9340:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 2);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar9,2,&local_23e8);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 8:
  case 0x32:
    local_2bb4 = puVar29 + 2;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 9:
  case 0x1d:
    local_2bb4 = puVar29 + 3;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 3);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,3,&local_23e8);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0xf:
    local_2bb4 = puVar29 + *(ushort *)((int)puVar29 + 6) + 2;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x14:
    local_2bb4 = puVar29 + 3;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x15:
    goto switchD_000c90cc_caseD_15;
  case 0x16:
    local_2bb4 = puVar29 + 1;
    pppppppuVar18 = &local_23e8;
    uVar33 = puVar29[1];
    puVar6 = (undefined *)(uVar33 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,0,0);
    if (puVar6 == ((unsigned char *)0x00160000U)) {
      local_239c = 1;
    }
    else if (puVar6 == (undefined *)0x110000) {
      local_23e0 = 1 << (uVar33 & 0x3f) | local_23e0;
    }
    else if (puVar6 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar33 & 0x3f);
    }
    else if (puVar6 == (undefined *)0x100000) {
      local_2384 = 1;
    }
    goto LAB_000c9564;
  case 0x18:
    goto switchD_000c90cc_caseD_18;
  case 0x19:
    uVar32 = (uint)pppppppuVar18 >> 0x1b & 3;
    uVar33 = (uint)pppppppuVar18 >> 0x10 & 0xff;
    if ((uVar32 == 2) || ((uVar32 == 0 && (auStack_130[uVar33] == 2)))) {
      local_2270 = 1 << ((uint)pppppppuVar18 >> 0x10 & 0x3f) | local_2270;
    }
    pppppppuVar18 = (uint *******)((uint)pppppppuVar18 >> 0x18 & 7);
    FUN_000c7270(&local_23e8,uVar33,pppppppuVar18);
    local_2bb4 = local_2bb4 + 1;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1a:
    local_2bb4 = puVar29 + 1;
    if ((int)pppppppuVar18 < 0) {
      local_2bb4 = puVar29 + 2;
    }
LAB_000c9564:
    local_2bb4 = local_2bb4 + 1;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x1c:
    local_2bb4 = puVar29 + 1;
    uVar32 = puVar29[1];
    uVar33 = uVar32 >> 0x10 & 0x3f;
    if (uVar33 == 1) {
      pppppppuVar18 = &local_2b68;
      local_2b68 = (uint ******)puVar29[2];
      local_2b64 = puVar29[3];
      local_2b60 = puVar29[4];
      local_2bb4 = puVar29 + 6;
      local_2b5c = puVar29[5];
      FUN_000c7290(&local_23e8,uVar32 & 0xffff,pppppppuVar18);
      puVar26 = local_2bb4;
    }
    else {
      puVar26 = local_2bb4;
      if (uVar33 == 2) {
        pppppppuVar18 = &local_2b68;
        local_2b68 = (uint ******)puVar29[2];
        local_2b64 = puVar29[3];
        local_2b60 = puVar29[4];
        local_2bb4 = puVar29 + 6;
        local_2b5c = puVar29[5];
        FUN_000c72f0(&local_23e8,uVar32 & 0xffff,pppppppuVar18);
        puVar26 = local_2bb4;
      }
    }
    goto switchD_000c90cc_caseD_18;
  case 0x24:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 2);
    iVar36 = iVar36 + 5;
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,1,2,&local_23e8);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x35:
    pppppppuVar18 = &local_23e8;
    local_2bb4 = puVar29 + 2;
    local_2b8c[0] = (uint ******)puVar29[1];
    ((int (*)())FUN_000c87d0)(local_2b8c,auStack_2b80,pppppppuVar18);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x37:
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,0,1,&local_23e8);
    local_1bc = 1;
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x3e:
    uVar9 = 0;
    break;
  case 0x5d:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar33 = puVar29[1];
    uVar32 = *puVar29;
    if ((((uVar32 & 0xc000000) == 0x4000000) ||
        (((uVar32 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar32 = *puVar29;
    }
    if ((int)uVar32 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar32 = *puVar29;
    }
    if ((uVar32 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      unaff_r21 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    pppppppuVar18 = &local_23e8;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,unaff_r21,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2b74 = (uint ******)*local_2bb4;
    puVar29 = local_2bb4 + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2bb0 = (uint ******)local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bb4 = puVar29;
    ((int (*)())FUN_000c87d0)(&local_2b74,&local_2bb0,pppppppuVar18);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  case 0x5e:
    local_2bb4 = puVar29 + 2;
    local_c8 = local_c8 + 1;
    uVar33 = puVar29[1];
    uVar32 = *puVar29;
    if ((((uVar32 & 0xc000000) == 0x4000000) ||
        (((uVar32 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2374) != 0)))) &&
       (local_2378 << (*(byte *)((int)puVar29 + 1) & 0x3f) != 0)) {
      iVar39 = iVar39 + 0x1b;
      local_2374 = 1 << (*(byte *)((int)puVar29 + 1) & 0x3f) | local_2374;
      uVar32 = *puVar29;
    }
    if ((int)uVar32 < 0) {
      local_2bb4 = puVar29 + 3;
      uVar32 = *puVar29;
    }
    if ((uVar32 & 0x40000000) != 0) {
      local_2bb4 = local_2bb4 + 1;
    }
    if ((uVar33 & 0x400000) != 0) {
      unaff_r20 = *local_2bb4;
      local_2bb4 = local_2bb4 + 1;
    }
    pppppppuVar18 = &local_23e8;
    ((int (*)())FUN_000c8600)(uVar33 & 0xffff,uVar33 >> 0x10 & 0x3f,pppppppuVar18,unaff_r20,uVar33 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar29 + 1) & 0x3f) & local_2378) != 0) {
      iVar39 = iVar39 + 4;
    }
    local_2bb0 = (uint ******)*local_2bb4;
    puVar29 = local_2bb4 + 1;
    if (((uint)local_2bb0 & 0x400000) != 0) {
      local_2ba4 = (uint *******)local_2bb4[1];
      puVar29 = local_2bb4 + 2;
    }
    local_2bac[0] = *puVar29;
    local_2bb4 = puVar29 + 1;
    if ((local_2bac[0] & 0x400000) != 0) {
      local_2ba0[0] = puVar29[1];
      local_2bb4 = puVar29 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_2bb0,&local_2ba4,pppppppuVar18);
    ((int (*)())FUN_000c87d0)(local_2bac,local_2ba0,pppppppuVar18);
    puVar26 = local_2bb4;
    goto switchD_000c90cc_caseD_18;
  }
  pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
  local_2bb4 = (uint *)((int (*)())FUN_000c8910)(puVar29,uVar9,1,&local_23e8);
  puVar26 = local_2bb4;
  goto switchD_000c90cc_caseD_18;
switchD_000c9ab8_caseD_18:
  local_2bb8 = pppppppuVar30;
  puVar19 = puVar26;
  pppppppuVar30 = local_2bb8;
  if (puVar31 + iVar38 <= puVar19) {
    uVar33 = uVar33 >> 2;
    local_23e0 = uVar21 | local_23e0;
LAB_000ca6bc:
    if (local_220 != (uint *******)0x0) {
      return local_220;
    }
    param_3[0x1587] = (uint ******)0x0;
    iVar38 = 0;
    param_3[0x1589] = (uint ******)0x0;
    param_3[0x1502] = (uint ******)0x0;
    pppppppuVar18 = param_3 + 0x1000;
    puVar37 = auStack_2248;
    pppppppuVar20 = param_3 + 0x1004;
    puVar31 = local_6c;
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
    local_2ac8 = uVar33 << 2;
    puVar27 = local_23dc;
    puVar16 = local_2ac0;
    iVar39 = 8;
    local_2a60 = iVar38;
    do {
      uVar9 = *puVar27;
      uVar13 = puVar27[8];
      puVar27 = puVar27 + 1;
      *puVar16 = uVar9;
      puVar16[8] = uVar13;
      puVar16 = puVar16 + 1;
      iVar39 = iVar39 + -1;
    } while (iVar39 != 0);
    local_2410 = 0x400;
    local_2acc = puVar29;
    local_240c = (uint *)_malloc(0x40000);
    local_2408 = (int *)_malloc(0x40000);
    local_2a10 = 0x40;
    local_29f8 = _malloc(0x900);
    local_2a14 = 0x40;
    local_29fc = _malloc(0x900);
    cVar24 = '\0';
    pcVar14 = local_2953;
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
    param_3[0x1000] = local_2400;
    if (local_2400 != (uint ******)0x0) {
      puVar31 = local_240c;
      pppppppuVar18 = param_3;
      if (local_2400 == (uint ******)0x0) {
        local_2400 = (uint ******)0x1;
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
        local_2400 = (uint ******)((int)local_2400 - 1);
      } while (local_2400 != (uint ******)0x0);
    }
    ppppppuVar10 = param_3[0x1502];
    if (ppppppuVar10 < local_23ec) {
      param_3[0x1502] = local_23ec;
      param_3[0x1501] = (uint ******)((int)local_23ec + 1);
      ppppppuVar10 = local_23ec;
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
    if (local_2a04 == 0) goto LAB_000caa4c;
    uVar33 = 0;
    iVar39 = 0;
    uVar21 = local_2a04;
    do {
      iVar36 = iVar39 + local_29f8;
      if (*(int *)(iVar36 + 8) == 0x16) {
        uVar32 = *(uint *)(iVar36 + 0x10);
        iVar35 = *(int *)(iVar39 + local_29f8);
        iVar17 = ((int)uVar32 >> 5) + (uint)((int)uVar32 < 0 && (uVar32 & 0x1f) != 0);
        if ((1 << (uVar32 + iVar17 * -0x20 & 0x3f) & local_2260[iVar17]) == 0) goto LAB_000caa2c;
        iVar17 = FUN_000c7240(*(undefined4 *)(iVar36 + 4));
        iVar36 = FUN_000c7240(*(undefined4 *)(iVar36 + 0xc));
        local_78 = (longlong)(int)local_2240[uVar32 * 4 + iVar36];
        aiStack_1220[iVar35 * 4 + iVar17] = (int)local_2240[uVar32 * 4 + iVar36];
      }
      else if (*(int *)(iVar36 + 8) == 0x18) {
LAB_000caa2c:
        ((int (*)())FUN_000c8de0)(param_3 + 0x1589,iVar36);
        uVar21 = local_2a04;
      }
      uVar33 = uVar33 + 1;
      iVar39 = iVar39 + 0x24;
      if (uVar21 <= uVar33) {
LAB_000caa4c:
        if (local_2a08 != 0) {
          uVar33 = 0;
          iVar39 = 0;
          uVar21 = local_2a08;
          do {
            iVar36 = iVar39 + local_29fc;
            if (*(int *)(iVar36 + 8) == 1) {
              ppppppuVar15 = *(uint *******)(iVar39 + local_29fc);
              iVar17 = FUN_000c7240(*(undefined4 *)(iVar36 + 4));
              ppppppuVar10 = *(uint *******)(iVar36 + 0x14);
              *(undefined1 *)(param_3 + (int)(((unsigned char *)0x00001005) + (int)ppppppuVar15 * 5)) = 1;
              param_3[(int)(((unsigned char *)0x00001001) + (int)ppppppuVar15 * 5 + iVar17)] = ppppppuVar10;
              uVar21 = local_2a08;
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
        param_3[0x1503] = local_2958;
        param_3[0x1504] = local_2654;
        param_3[0x1505] = local_23fc;
        param_3[0x1588] = (uint ******)0x0;
        if (local_2654 == (uint ******)0x0) {
          ppppppuVar10 = param_3[0x151d];
        }
        else {
          pcVar14 = local_2650;
          if (local_2654 == (uint ******)0x0) {
            local_2654 = (uint ******)0x1;
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
            local_2654 = (uint ******)((int)local_2654 - 1);
          } while (local_2654 != (uint ******)0x0);
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
          puVar37 = &uStack_2954;
          ppppppuVar15 = ppppppuVar10;
          if (ppppppuVar10 == (uint ******)0x0) {
            ppppppuVar15 = (uint ******)0x1;
          }
          do {
            pbVar2 = puVar37 + 1;
            pbVar5 = puVar37 + (int)(abStack_2950 + -(int)&uStack_2954);
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
        iVar39 = *local_2408;
        param_3[0x1520] = (uint ******)0x0;
        param_3[0x151f] = (uint ******)(uint)(iVar39 != 0);
        if (((uint ******)(uint)(iVar39 != 0) != (uint ******)0x0) &&
           (iVar39 = *local_2408, 0 < iVar39)) {
          pppppppuVar18 = param_3 + 0x1531;
          ppppppuVar10 = (uint ******)0x0;
          do {
            pppppppuVar18[0x20] = (uint ******)0x0;
            *pppppppuVar18 = (uint ******)0x0;
            pppppppuVar18[0x10] = (uint ******)0x0;
            if (local_2408[(int)ppppppuVar10 * 7 + 3] == 0x3e) {
              param_3[0x1520] =
                   (uint ******)(2 << (((uint)ppppppuVar10 & 0x1f) << 1) | (uint)param_3[0x1520]);
              *(char *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5547) =
                   (char)aiStack_1220[local_2408[(int)ppppppuVar10 * 7 + 4] * 4 + 1];
              *(char *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5546) =
                   (char)aiStack_1220[local_2408[(int)ppppppuVar10 * 7 + 4] * 4 + 2];
              *(short *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x54c6) =
                   (short)local_2408[(int)ppppppuVar10 * 7 + 5];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001531) + (int)ppppppuVar10)) =
                   (short)aiStack_1220[local_2408[(int)ppppppuVar10 * 7 + 4] * 4];
              *(short *)((int)param_3 + (int)ppppppuVar10 * 4 + 0x5506) =
                   (short)local_2408[(int)ppppppuVar10 * 7 + 7];
              *(short *)(param_3 + (int)(((unsigned char *)0x00001541) + (int)ppppppuVar10)) =
                   (short)local_2408[(int)ppppppuVar10 * 7 + 5] + 1;
              param_3[(int)(((unsigned char *)0x00001561) + local_2408[(int)ppppppuVar10 * 7 + 4])] = ppppppuVar10;
            }
            ppppppuVar10 = (uint ******)((int)ppppppuVar10 + 1);
            pppppppuVar18 = pppppppuVar18 + 1;
            iVar39 = iVar39 + -1;
          } while (iVar39 != 0);
        }
        if (local_240c != (uint *)0x0) {
          _free(local_240c);
        }
        if (iVar11 != 0) {
          _free(iVar11);
        }
        if (local_2408 != (int *)0x0) {
          _free(local_2408);
        }
        if (puVar29 != (uint *)0x0) {
          _free(puVar29);
        }
        if (iVar38 != 0) {
          _free(iVar38);
        }
        if (local_29f8 != 0) {
          _free(local_29f8);
        }
        if (local_29fc != 0) {
          _free(local_29fc);
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
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,1,&local_23e8);
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8;
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
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,2,&local_23e8);
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8;
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
    *local_2bb8 = ppppppuVar10;
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar18 = (uint *******)0x0;
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,0,2,&local_23e8);
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_2bb8 = ppppppuVar10;
    local_2bb4 = puVar19 + 2;
    local_2bb8[1] = (uint ******)puVar19[1];
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8 + 2;
    goto switchD_000c9ab8_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_2bb8 = ppppppuVar10;
    local_2bb8[1] = (uint ******)puVar19[1];
    local_2bb4 = puVar19 + 3;
    local_2bb8[2] = (uint ******)puVar19[2];
    puVar26 = local_2bb4;
    pppppppuVar25 = local_2bb8 + 3;
    pppppppuVar30 = local_2bb8 + 3;
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
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
    }
    pppppppuVar18 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,1,3,&local_23e8);
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8;
    goto switchD_000c9ab8_caseD_18;
  case 0xf:
    local_2bb4 = puVar19 + 2;
    *local_2bb8 = ppppppuVar10;
    local_2bb8[1] = (uint ******)puVar19[1];
    pppppppuVar30 = local_2bb8 + 2;
    for (uVar32 = (uint)*(ushort *)((int)puVar19 + 6); puVar26 = local_2bb4, uVar32 != 0;
        uVar32 = uVar32 - 1) {
      ppppppuVar10 = (uint ******)*local_2bb4;
      local_2bb4 = local_2bb4 + 1;
      *pppppppuVar30 = ppppppuVar10;
      pppppppuVar30 = pppppppuVar30 + 1;
    }
  case 0x18:
    goto switchD_000c9ab8_caseD_18;
  case 0x19:
    local_2bb4 = puVar19 + 1;
    if (((uint)ppppppuVar10 & 0x18000000) == 0) {
      uVar32 = *(uint *)((int)auStack_130 + ((uint)ppppppuVar10 >> 0xe & 0x3fc));
      if (uVar32 != 2) {
        uVar32 = 1;
      }
      ppppppuVar10 = (uint ******)((uVar32 & 3) << 0x1b | (uint)ppppppuVar10 & 0xe7ffffff);
    }
    *local_2bb8 = ppppppuVar10;
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1a:
    local_2bb4 = puVar19 + 1;
    *local_2bb8 = ppppppuVar10;
    pppppppuVar25 = local_2bb8 + 1;
    if ((int)ppppppuVar10 < 0) {
      ppppppuVar10 = (uint ******)*local_2bb4;
      local_2bb4 = puVar19 + 2;
      local_2bb8[1] = ppppppuVar10;
      pppppppuVar25 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar25;
    ppppppuVar10 = (uint ******)*local_2bb4;
    local_2bb4 = local_2bb4 + 1;
    *local_2bb8 = ppppppuVar10;
    puVar26 = local_2bb4;
    pppppppuVar25 = pppppppuVar30;
    pppppppuVar30 = local_2bb8 + 1;
    goto switchD_000c9ab8_caseD_18;
  case 0x1c:
    local_2bb4 = puVar19 + 1;
    pppppppuVar18 = local_2bb8 + 1;
    *local_2bb8 = ppppppuVar10;
    puVar26 = local_2bb4;
    pppppppuVar30 = pppppppuVar18;
    if ((puVar19[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_2bb8[1] = (uint ******)puVar19[1];
      pppppppuVar20 = local_2bb8 + 6;
      local_2bb8[2] = (uint ******)puVar19[2];
      local_2bb8[3] = (uint ******)puVar19[3];
      local_2bb8[4] = (uint ******)puVar19[4];
      local_2bb4 = puVar19 + 6;
      local_2bb8[5] = (uint ******)puVar19[5];
      puVar26 = local_2bb4;
      pppppppuVar25 = local_2bb8 + 5;
      pppppppuVar30 = pppppppuVar20;
    }
    goto switchD_000c9ab8_caseD_18;
  case 0x28:
    local_2bb4 = puVar19 + 1;
    puVar16 = (undefined4 *)
              ((int (*)())FUN_000c7930)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,local_2bb4,pppppppuVar20,
                           iVar39);
    *puVar16 = ppppppuVar10;
    puVar26 = local_2bb4;
    pppppppuVar30 = (uint *******)(puVar16 + 1);
    goto switchD_000c9ab8_caseD_18;
  case 0x35:
    pppppppuVar18 = &local_23e8;
    *local_2bb8 = ppppppuVar10;
    local_2bb4 = puVar19 + 2;
    local_2b8c[0] = (uint ******)puVar19[1];
    local_2bb8 = local_2bb8 + 1;
    ((int (*)())FUN_000c8760)(local_2b8c,auStack_2b80,pppppppuVar18);
    *local_2bb8 = local_2b8c[0];
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8 + 1;
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
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
      puVar19 = local_2bb4;
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
    local_2ba4 = (uint *******)*puVar26;
    puVar19 = puVar26 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar19 = puVar26 + 2;
      unaff_r15 = (uint ******)puVar26[1];
    }
    local_2b74 = (uint ******)*puVar19;
    local_2bb4 = puVar19 + 1;
    if (((uint)local_2b74 & 0x400000) != 0) {
      local_2b98 = (uint ******)puVar19[1];
      local_2bb4 = puVar19 + 2;
    }
    uVar7 = (uint)ppppppuVar10 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca0e4:
      if (local_2378 << (uVar32 & 0x3f) == 0) {
        local_70 = (uint ******)&local_2b74;
        pppppppuVar30 = (uint *******)0x0;
        uVar34 = 1 << (uVar32 & 0x3f);
        ppppppuVar28 = (uint ******)&local_2b98;
      }
      else {
        local_60 = (uint ******)&local_2b98;
        local_70 = (uint ******)&local_2b74;
        local_2bb8 = (uint *******)((int (*)())FUN_000c7460)(&local_23e8,local_70,local_60,uVar22,local_2bb8);
        ppppppuVar28 = local_60;
        if (((uint)local_2ba4 & 0x400000) == 0) {
          pppppppuVar30 = (uint *******)0x0;
          uVar34 = 1 << (uVar32 & 0x3f);
        }
        else {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          pppppppuVar30 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar34 = 1 << (uVar32 & 0x3f);
          local_2bb0 = unaff_r15;
        }
      }
    }
    else if (uVar7 == 0x8000000) {
      uVar34 = 1 << (uVar32 & 0x3f);
      if ((uVar34 & local_2374) != 0) goto LAB_000ca0e4;
      local_70 = (uint ******)&local_2b74;
      pppppppuVar30 = (uint *******)0x0;
      ppppppuVar28 = (uint ******)&local_2b98;
    }
    else {
      pppppppuVar30 = (uint *******)0x0;
      uVar34 = 1 << (uVar32 & 0x3f);
      local_70 = (uint ******)&local_2b74;
      ppppppuVar28 = (uint ******)&local_2b98;
    }
    pppppppuVar18 = &local_23e8;
    ((int (*)())FUN_000c8760)(local_70,ppppppuVar28,&local_23e8);
    *local_2bb8 = ppppppuVar10;
    pppppppuVar25 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = ppppppuVar15;
      pppppppuVar25 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar25;
    if (bVar1) {
      *local_2bb8 = ppppppuVar23;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = (uint ******)local_2ba4;
    pppppppuVar25 = local_2bb8 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r15;
      pppppppuVar25 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar25;
    *local_2bb8 = local_2b74;
    pppppppuVar25 = (uint *******)((uint)local_2b74 & 0x400000);
    pppppppuVar8 = local_2bb8 + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      local_2bb8[1] = local_2b98;
      pppppppuVar8 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar8;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (local_2378 << (uVar32 & 0x3f) != 0)) {
      pppppppuVar18 = (uint *******)&local_2ba4;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_23e8,local_70,pppppppuVar18,&local_2bb0,uVar22,pppppppuVar30,
                                local_2bb8,pppppppuVar25);
      pppppppuVar20 = pppppppuVar30;
    }
    uVar34 = uVar34 & local_2378;
    ppppppuVar10 = unaff_r15;
    goto joined_r0x000ca538;
  case 0x5e:
    if (bVar4) {
      bVar4 = false;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_2bb8,&local_23e8,pppppppuVar18,puVar19,puVar19,pppppppuVar20,
                                iVar39,pppppppuVar25);
      puVar19 = local_2bb4;
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
    local_2ba4 = (uint *******)*puVar26;
    puVar19 = puVar26 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      puVar19 = puVar26 + 2;
      unaff_r14 = (uint ******)puVar26[1];
    }
    local_2b98 = (uint ******)*puVar19;
    puVar26 = puVar19 + 1;
    if (((uint)local_2b98 & 0x400000) != 0) {
      local_2b74 = (uint ******)puVar19[1];
      puVar26 = puVar19 + 2;
    }
    local_2b94 = (uint ******)*puVar26;
    local_2bb4 = puVar26 + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      local_2b70 = (uint ******)puVar26[1];
      local_2bb4 = puVar26 + 2;
    }
    uVar7 = (uint)ppppppuVar10 & 0xc000000;
    if (uVar7 == 0x4000000) {
LAB_000ca3b8:
      if (local_2378 << (uVar32 & 0x3f) != 0) {
        pppppppuVar18 = &local_2b74;
        local_2bb8 = (uint *******)
                     ((int (*)())FUN_000c7460)(&local_23e8,&local_2b98,pppppppuVar18,uVar22,local_2bb8);
        if (((uint)local_2ba4 & 0x400000) != 0) {
          local_2ba4 = (uint *******)((uint)local_2ba4 & 0xffbfffff);
          pppppppuVar20 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar34 = 1 << (uVar32 & 0x3f);
          local_2bb0 = unaff_r14;
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
      if ((uVar34 & local_2374) != 0) goto LAB_000ca3b8;
    }
LAB_000ca414:
    *local_2bb8 = ppppppuVar10;
    pppppppuVar25 = local_2bb8 + 1;
    if (bVar3) {
      local_2bb8[1] = ppppppuVar15;
      pppppppuVar25 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar25;
    if (bVar1) {
      *local_2bb8 = ppppppuVar23;
      local_2bb8 = local_2bb8 + 1;
    }
    *local_2bb8 = (uint ******)local_2ba4;
    pppppppuVar25 = local_2bb8 + 1;
    if (((uint)local_2ba4 & 0x400000) != 0) {
      local_2bb8[1] = unaff_r14;
      pppppppuVar25 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar25;
    *local_2bb8 = local_2b98;
    pppppppuVar25 = (uint *******)((uint)local_2b98 & 0x400000);
    pppppppuVar30 = local_2bb8 + 1;
    if (pppppppuVar25 != (uint *******)0x0) {
      local_2bb8[1] = local_2b74;
      pppppppuVar30 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar30;
    *local_2bb8 = local_2b94;
    pppppppuVar30 = local_2bb8 + 1;
    if (((uint)local_2b94 & 0x400000) != 0) {
      local_2bb8[1] = local_2b70;
      pppppppuVar30 = local_2bb8 + 2;
    }
    local_2bb8 = pppppppuVar30;
    if (((uVar7 == 0x4000000) || ((uVar7 == 0x8000000 && ((uVar34 & local_2374) != 0)))) &&
       (pppppppuVar25 = (uint *******)(local_2378 << (uVar32 & 0x3f)),
       pppppppuVar25 != (uint *******)0x0)) {
      pppppppuVar18 = (uint *******)&local_2ba4;
      local_2bb8 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_23e8,&local_2b98,pppppppuVar18,&local_2bb0,uVar22,
                                pppppppuVar20,local_2bb8,pppppppuVar25);
    }
    uVar34 = uVar34 & local_2378;
    ppppppuVar10 = unaff_r14;
joined_r0x000ca538:
    puVar26 = local_2bb4;
    pppppppuVar30 = local_2bb8;
    if (uVar34 != 0) {
      pppppppuVar20 = local_2bb8 + 1;
      *local_2bb8 = (uint ******)0x47;
      pppppppuVar25 = local_2ba4;
      if (((uint)local_2ba4 & 0x400000) == 0) {
        pppppppuVar25 = (uint *******)((uint)local_2ba4 | 0x400000);
        ppppppuVar10 = (uint ******)0x55;
      }
      if (aiStack_22f0[uVar22] == 0x1906) {
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
      else if ((aiStack_22f0[uVar22] == 0x1909) && (((uint)ppppppuVar10 & 0xc0) == 0x40)) {
        ppppppuVar10 = (uint ******)((uint)ppppppuVar10 & 0xffffff3f | 0xc0);
      }
      *pppppppuVar20 = (uint ******)pppppppuVar25;
      local_2bb8[2] = ppppppuVar10;
      local_2bb8[3] = (uint ******)((uint)pppppppuVar25 & 0x3fffff);
      pppppppuVar30 = local_2bb8 + 4;
    }
    goto switchD_000c9ab8_caseD_18;
  }
  local_2bb4 = (uint *)((int (*)())FUN_000c8aa0)(&local_2bb8,&local_2bb4,pppppppuVar18,1,&local_23e8);
  puVar26 = local_2bb4;
  pppppppuVar30 = local_2bb8;
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
   * alias (pppppppuVar19/local_88) at every call site in this function - as the base of a large
   * per-context attribute-state array, indexing it at param_3[2] up to param_3[0x88a] (~8.7KB).
   * Declared as a single word, this overflowed onto whatever real stock places after it on the
   * stack. Live-verified on real hardware via a raw memory watchpoint at the real stock address:
   * FUN_000c8600's `param_3[param_1+0x87c] = 1;` (opcode 0x47, param_1==0) is a real, deterministic
   * write stock performs that the rebuild's undersized local_c08c can't - traced back through
   * FUN_000cae90's own size-computation cascade (part_018.c:2758-2820) to the calloc(44) crash this
   * issue's title tracks: the write's real destination is 12 bytes past a stack region our size
   * computation reads back as a "flag" (local_9e9c[0]) to decide the command buffer's malloc size,
   * so leaving it unwritten undersizes that malloc by exactly the corruption this issue chases.
   * Given its own real size, without touching any other local's declaration. */
  unsigned char local_c08c_buf [0x2400];
#define local_c08c (*(uint *******)(local_c08c_buf))
  undefined4 local_c088;
  uint local_c084;
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
  undefined4 local_9cd4;
  uint local_9cc8;
  int local_9cbc;
  uint local_9c84 [27];
  int local_9c18;
  char local_9c14 [1348];
  undefined1 auStack_96d0 [37816];
  int iStack_318;
  uint *******local_88;
  uint ******local_84;
  int *local_80;
  uint ******local_70;
  
  iVar46 = 8;
  iVar13 = 0;
  do {
    *(undefined4 *)((int)local_c168 + iVar13) = 0xffffffff;
    *(undefined4 *)((int)local_c188 + iVar13) = 0;
    iVar13 = iVar13 + 4;
    iVar46 = iVar46 + -1;
  } while (iVar46 != 0);
  bVar3 = param_1 == 0;
  local_c168[0] = local_c168[0] & 0xffff0000;
  pppppppuVar19 = param_3;
  iVar13 = _malloc(0x400);
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
    puVar34 = local_bf94;
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    iVar46 = param_1;
    do {
      iVar26 = *(int *)(((unsigned char *)0x000013f8) + iVar46);
      if ((iVar26 != 0) && (*(short *)(iVar26 + 0x38) == 0x1902)) {
        uVar21 = 1 << ((uint)in_r8 & 0x3f);
        local_c01c = uVar21 | local_c01c;
        *puVar34 = (uint)*(ushort *)(iVar26 + 0x58);
        puVar34[0x10] = (uint)*(ushort *)(iVar26 + 0x5c);
        if (*(short *)(iVar26 + 0x5a) != 0) {
          local_c018 = uVar21 | local_c018;
        }
      }
      in_r8 = (uint *******)((int)in_r8 + 1);
      iVar46 = iVar46 + 4;
      puVar34 = puVar34 + 1;
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
  iVar46 = 0;
  puVar34 = local_9dd4;
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
  local_9e58 = (uint *******)((int)((unsigned char *)0x0) + 1);
  local_9e88 = 0;
  local_9d90 = param_3[0x45];
  if ((bVar3) || (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != -0x7baf)) {
    local_9d80 = 0;
  }
  else {
    local_9d80 = 1;
  }
  puVar40 = (uint *)*param_4;
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
  iVar46 = param_4[1];
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
  puVar34 = local_bf04;
  iVar47 = 8;
  do {
    *puVar34 = 0;
    puVar34[0x408] = 0;
    puVar34 = puVar34 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
  local_80 = local_9e54;
  iVar47 = 0x10;
  piVar18 = local_80;
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
  local_c1f8 = puVar34 + 2;
  puVar23 = local_c1f8;
switchD_000cb23c_caseD_18:
  puVar34 = puVar23;
  if (puVar34 < puVar40 + iVar46) goto code_r0x000cb214;
  if (local_9ec4 != 0) {
    puVar34 = (uint *)0x0;
    uVar35 = 0;
    goto LAB_000cc88c;
  }
  iVar47 = (iVar46 + iVar47) * 4;
  local_c03c = local_c08c;
  if (local_c040 != 0) {
    iVar47 = iVar47 + 0x48;
  }
  uVar35 = iVar47 + iVar26 * 4;
  bVar5 = local_9ebc != 0;
  if (bVar5) {
    uVar35 = uVar35 + 0x14;
  }
  uVar12 = uVar35;
  if ((local_9e9c[0] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar35 = uVar12;
  if ((local_9e9c[1] != 0) && (uVar35 = uVar12 + 0xc, bVar5)) {
    uVar35 = uVar12 + 0x24;
  }
  uVar12 = uVar35;
  if ((local_9e9c[2] != 0) && (uVar12 = uVar35 + 0xc, bVar5)) {
    uVar12 = uVar35 + 0x24;
  }
  uVar27 = uVar12;
  if ((local_9e9c[3] != 0) && (uVar27 = uVar12 + 0xc, bVar5)) {
    uVar27 = uVar12 + 0x24;
  }
  if (((local_9e80 != 0) && (local_9e88 != 0)) && (local_9e58 == (uint *******)0x0)) {
    uVar27 = uVar27 + 0x14;
  }
  if (local_9d90 == (uint ******)0x1) {
    uVar27 = uVar27 + 0x24;
  }
  else if (local_9d90 == (uint ******)0x2) {
    uVar27 = uVar27 + 0x30;
  }
  else if (local_9d90 == (uint ******)0x3) {
    uVar27 = uVar27 + 0x40;
  }
  else if (local_9d90 == (uint ******)0x0) goto LAB_000cbb64;
  uVar27 = uVar27 + 8;
  piVar18 = local_9e9c;
  iVar47 = 4;
  do {
    if (*piVar18 != 0) {
      uVar27 = uVar27 + 0x2c;
    }
    piVar18 = piVar18 + 1;
    iVar47 = iVar47 + -1;
  } while (iVar47 != 0);
LAB_000cbb64:
  if (((local_9e74 != 0) || (local_9e6c != 0)) || (uVar35 = uVar27, local_9e58 == (uint *******)0x0)
     ) {
    if ((local_9e78 == 0) && (local_9e70 != 0)) {
      uVar27 = uVar27 + 0xc;
    }
    uVar35 = uVar27;
    if ((local_9e58 == (uint *******)0x0) && (uVar35 = uVar27 + 0xc, local_9d7c != 0)) {
      uVar35 = uVar27 + 0x18;
    }
  }
  bVar5 = true;
  pppppppuVar28 = local_9e58;
  puVar34 = (uint *)_malloc(uVar35 + 0x10);
  *puVar34 = *puVar40;
  local_c1f8 = puVar40 + 2;
  puVar34[1] = puVar40[1];
  puVar23 = local_c1f8;
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
    local_c1f8 = puVar34 + 1;
    puVar23 = local_c1f8;
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
    local_c1f8 = puVar34 + 1;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    uVar29 = 0;
LAB_000cb4b0:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar34,uVar29,2,&local_c08c);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 8:
  case 0x32:
    local_c1f8 = puVar34 + 2;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 9:
  case 0x1d:
    local_c1f8 = puVar34 + 3;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 10:
  case 0xd:
  case 0x21:
  case 0x2f:
  case 0x3f:
  case 0x40:
  case 100:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 3);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar34,1,3,&local_c08c);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0xf:
    local_c1f8 = puVar34 + *(ushort *)((int)puVar34 + 6) + 2;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x14:
    local_c1f8 = puVar34 + 3;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x15:
    goto switchD_000cb23c_caseD_15;
  case 0x16:
    local_c1f8 = puVar34 + 1;
    pppppppuVar19 = &local_c08c;
    uVar35 = puVar34[1];
    puVar8 = (undefined *)(uVar35 & 0x3f0000);
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,pppppppuVar19,0,0);
    if (puVar8 == ((unsigned char *)0x00160000U)) {
      local_c040 = 1;
    }
    else if (puVar8 == (undefined *)0x110000) {
      local_c084 = 1 << (uVar35 & 0x3f) | local_c084;
    }
    else if (puVar8 == (undefined *)0xf0000) {
      uVar21 = uVar21 | 1 << (uVar35 & 0x3f);
    }
    else if (puVar8 == (undefined *)0x100000) {
      local_c028 = 1;
    }
    goto LAB_000cb6d4;
  case 0x18:
    goto switchD_000cb23c_caseD_18;
  case 0x19:
    uVar12 = (uint)pppppppuVar19 >> 0x1b & 3;
    uVar35 = (uint)pppppppuVar19 >> 0x10 & 0xff;
    if ((uVar12 == 2) || ((uVar12 == 0 && (local_9dd4[uVar35] == 2)))) {
      local_bf14 = 1 << ((uint)pppppppuVar19 >> 0x10 & 0x3f) | local_bf14;
    }
    pppppppuVar19 = (uint *******)((uint)pppppppuVar19 >> 0x18 & 7);
    FUN_000c7270(&local_c08c,uVar35,pppppppuVar19);
    local_c1f8 = local_c1f8 + 1;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1a:
    local_c1f8 = puVar34 + 1;
    if ((int)pppppppuVar19 < 0) {
      local_c1f8 = puVar34 + 2;
    }
LAB_000cb6d4:
    local_c1f8 = local_c1f8 + 1;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x1c:
    local_c1f8 = puVar34 + 1;
    uVar12 = puVar34[1];
    uVar35 = uVar12 >> 0x10 & 0x3f;
    if (uVar35 == 1) {
      pppppppuVar19 = &local_c1a8;
      local_c1a8 = (uint ******)puVar34[2];
      local_c1a4 = puVar34[3];
      local_c1a0 = puVar34[4];
      local_c1f8 = puVar34 + 6;
      local_c19c = puVar34[5];
      FUN_000c7290(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
      puVar23 = local_c1f8;
    }
    else {
      puVar23 = local_c1f8;
      if (uVar35 == 2) {
        pppppppuVar19 = &local_c1a8;
        local_c1a8 = (uint ******)puVar34[2];
        local_c1a4 = puVar34[3];
        local_c1a0 = puVar34[4];
        local_c1f8 = puVar34 + 6;
        local_c19c = puVar34[5];
        FUN_000c72f0(&local_c08c,uVar12 & 0xffff,pppppppuVar19);
        puVar23 = local_c1f8;
      }
    }
    goto switchD_000cb23c_caseD_18;
  case 0x24:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 2);
    iVar47 = iVar47 + 5;
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar34,1,2,&local_c08c);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    local_c1f8 = puVar34 + 2;
    local_c1c0[0] = (uint ******)puVar34[1];
    ((int (*)())FUN_000c87d0)(local_c1c0,auStack_c1b4,pppppppuVar19);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x37:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar34,0,1,&local_c08c);
    local_9e60 = 1;
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x3e:
    uVar29 = 0;
    break;
  case 0x5d:
    local_c1f8 = puVar34 + 2;
    local_9d6c = local_9d6c + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      iVar26 = iVar26 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | local_c018;
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      local_c1f8 = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r20 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,local_88,unaff_r20,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & local_c01c) != 0) {
      iVar26 = iVar26 + 4;
    }
    local_c1e4 = (uint ******)*local_c1f8;
    puVar34 = local_c1f8 + 1;
    if (((uint)local_c1e4 & 0x400000) != 0) {
      local_c1f0 = (uint *******)local_c1f8[1];
      puVar34 = local_c1f8 + 2;
    }
    local_c1f8 = puVar34;
    pppppppuVar19 = local_88;
    ((int (*)())FUN_000c87d0)(&local_c1e4,&local_c1f0,local_88);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  case 0x5e:
    local_c1f8 = puVar34 + 2;
    local_9d6c = local_9d6c + 1;
    uVar35 = puVar34[1];
    uVar12 = *puVar34;
    if ((((uVar12 & 0xc000000) == 0x4000000) ||
        (((uVar12 & 0xc000000) == 0x8000000 &&
         ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & local_c018) != 0)))) &&
       (local_c01c << (*(byte *)((int)puVar34 + 1) & 0x3f) != 0)) {
      iVar26 = iVar26 + 0x1b;
      local_c018 = 1 << (*(byte *)((int)puVar34 + 1) & 0x3f) | local_c018;
      uVar12 = *puVar34;
    }
    if ((int)uVar12 < 0) {
      local_c1f8 = puVar34 + 3;
      uVar12 = *puVar34;
    }
    if ((uVar12 & 0x40000000) != 0) {
      local_c1f8 = local_c1f8 + 1;
    }
    if ((uVar35 & 0x400000) != 0) {
      unaff_r19 = *local_c1f8;
      local_c1f8 = local_c1f8 + 1;
    }
    local_88 = &local_c08c;
    ((int (*)())FUN_000c8600)(uVar35 & 0xffff,uVar35 >> 0x10 & 0x3f,local_88,unaff_r19,uVar35 >> 0x16 & 1);
    if ((1 << (*(byte *)((int)puVar34 + 1) & 0x3f) & local_c01c) != 0) {
      iVar26 = iVar26 + 4;
    }
    local_c1f0 = (uint *******)*local_c1f8;
    puVar34 = local_c1f8 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1e4 = (uint ******)local_c1f8[1];
      puVar34 = local_c1f8 + 2;
    }
    local_c1ec[0] = *puVar34;
    local_c1f8 = puVar34 + 1;
    if ((local_c1ec[0] & 0x400000) != 0) {
      local_c1e0[0] = puVar34[1];
      local_c1f8 = puVar34 + 2;
    }
    ((int (*)())FUN_000c87d0)(&local_c1f0,&local_c1e4,local_88);
    pppppppuVar19 = local_88;
    ((int (*)())FUN_000c87d0)(local_c1ec,local_c1e0,local_88);
    puVar23 = local_c1f8;
    goto switchD_000cb23c_caseD_18;
  }
  pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
  local_c1f8 = (uint *)((int (*)())FUN_000c8910)(puVar34,uVar29,1,&local_c08c);
  puVar23 = local_c1f8;
  goto switchD_000cb23c_caseD_18;
switchD_000cbc48_caseD_18:
  local_c1f4 = pppppppuVar36;
  puVar22 = puVar23;
  pppppppuVar36 = local_c1f4;
  if (puVar40 + iVar46 <= puVar22) {
    uVar35 = uVar35 >> 2;
    local_c084 = uVar21 | local_c084;
LAB_000cc88c:
    if (local_9ec4 != 0) {
      _free(puVar34);
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
    iVar46 = 8;
    uVar21 = 0;
    pppppppuVar28 = param_3 + 0x2c;
    pppppppuVar19 = param_3;
    do {
      if ((1 << (uVar21 & 0x3f) & local_c084) == 0) {
        *(undefined1 *)(pppppppuVar19 + 0x2c) = 0;
      }
      else if ((local_c040 == 0) || (local_c02c != uVar21)) {
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
    *(undefined4 *)(((unsigned char *)0x000010e0) + (int)*param_3) = local_bfd4;
    piVar18 = local_80;
    piVar44 = param_2;
    piVar32 = param_2;
    do {
      uVar12 = 1 << (uVar21 & 0x3f);
      if ((uVar12 & local_bf14) == 0) {
        *(undefined1 *)(piVar32 + 0x582) = 0;
      }
      else {
        *(undefined1 *)(piVar32 + 0x582) = 1;
      }
      if ((uVar12 & local_c01c) == 0) {
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
    local_88 = &local_c08c;
    iVar46 = 0;
    puVar40 = local_aee4;
    puVar38 = auStack_beec;
    puVar37 = auStack_aecc;
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
    *(uint *)(((unsigned char *)0x00003748) + (int)*param_3) = local_aee4[0];
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
    local_c100 = local_c198;
    local_9cd4 = 0x40;
    local_c198[0] = local_c198[0] & 0x403fffff | 0x62000000;
    local_c0fc = puVar34;
    local_9cbc = _malloc(0x900);
    /* issue #64 live-repro (crash #6, past the iVar47-mask fix): local_9cc8 - the record count
     * later used as this loop's bound (`uVar21 = local_9cc8; ... while (uVar35 < uVar21)`,
     * below) - is read in several places but WRITTEN nowhere in this entire function; the only
     * thing ever done with its companion buffer is this _malloc(0x900) (64 records of 0x24
     * bytes each) with no populating writes anywhere in this 4600-line function either. A
     * freshly malloc'd, never-populated record list has zero valid entries, so the natural,
     * safe count is 0 - but nothing sets it, leaving it as raw uninitialized stack garbage.
     * Live-verified on real hardware: local_9cc8 read back as 3221123400 (0xC000FE48), driving
     * the consumption loop far past the (empty) buffer into unrelated memory, reading a garbage
     * piVar18[0] (e.g. 4249536) used as an array index and crashing on the resulting wild
     * write. Initialized to 0 to match the buffer's real (empty) population state.
     *
     * The exact same defect class recurs at local_9c18 just below (used the identical way -
     * `if (local_9c18 != 0) { pcVar31 = local_9c14; do { ... } while (--local_9c18 != 0); }`
     * over its own never-populated buffer local_9c14) - also never written anywhere in this
     * function. Live-verified: it crashed next, reading through pcVar31 at address 0xc0000000.
     * Fixed the same way, for the same reason. */
    local_9cc8 = 0;
    local_9c18 = 0;
    iVar47 = ((int (*)())FUN_000cd1b0)(*param_5,auStack_c148,auStack_9d1c);
    if (iVar47 != 0) {
      return 2;
    }
    iVar47 = 0;
    puVar37 = auStack_96d0;
    do {
      _memcpy((int)param_3[3] + iVar47,puVar37,0x48);
      ppppppuVar15 = param_3[3];
      if ((*(int *)(iVar47 + (int)ppppppuVar15) == 1) &&
         (*(char *)((int)ppppppuVar15 + iVar47 + 8) == '\x0f')) {
        *(char *)((int)ppppppuVar15 + iVar47 + 8) = (char)local_c024;
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
      uVar21 = *(uint *)((int)local_9c84 + iVar47) | *(uint *)((int)local_88 + iVar47 + 0x188);
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
    for (; iStack_318 != 0; iStack_318 = iStack_318 + -1) {
    }
    if (local_9cc8 != 0) {
      uVar35 = 0;
      uVar21 = local_9cc8;
      do {
        piVar18 = (int *)(uVar35 * 0x24 + local_9cbc);
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
          ((int (*)())FUN_000c8de0)(param_3 + 0x48,piVar18);
          uVar21 = local_9cc8;
        }
        uVar35 = uVar35 + 1;
      } while (uVar35 < uVar21);
    }
    if (local_9c18 != 0) {
      iVar47 = 0;
      pcVar31 = local_9c14;
      if (local_9c18 == 0) {
        local_9c18 = 1;
      }
      do {
        cVar6 = *pcVar31;
        pcVar31 = pcVar31 + 0xc;
        if (cVar6 != '\x02') {
          iVar47 = iVar47 + 1;
        }
        if (cVar6 == '\x04') {
          *(undefined1 *)((int)param_2 + 0x1e2e) = 1;
          param_2[0x7a3] = local_c024 + 2;
        }
        local_9c18 = local_9c18 + -1;
      } while (local_9c18 != 0);
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
    _free(local_9cbc);
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
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar19,puVar22,puVar22,in_r8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,1,local_88);
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4;
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
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar19,puVar22,puVar22,in_r8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,2,local_88);
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 6:
  case 0x10:
  case 0x27:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x4b:
  case 0x53:
    local_c1f8 = puVar22 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 7:
  case 0x11:
  case 0x34:
    pppppppuVar19 = (uint *******)0x0;
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,0,2,&local_c08c);
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 8:
  case 0x15:
  case 0x16:
  case 0x32:
    *local_c1f4 = ppppppuVar15;
    local_c1f8 = puVar22 + 2;
    local_c1f4[1] = (uint ******)puVar22[1];
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4 + 2;
    goto switchD_000cbc48_caseD_18;
  case 9:
  case 0x14:
  case 0x1d:
    *local_c1f4 = ppppppuVar15;
    local_c1f4[1] = (uint ******)puVar22[1];
    local_c1f8 = puVar22 + 3;
    local_c1f4[2] = (uint ******)puVar22[2];
    puVar23 = local_c1f8;
    pppppppuVar28 = local_c1f4 + 3;
    pppppppuVar36 = local_c1f4 + 3;
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
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar19,puVar22,puVar22,in_r8,local_88,
                                pppppppuVar28);
    }
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,1,3,local_88);
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4;
    goto switchD_000cbc48_caseD_18;
  case 0xf:
    local_c1f8 = puVar22 + 2;
    *local_c1f4 = ppppppuVar15;
    local_c1f4[1] = (uint ******)puVar22[1];
    pppppppuVar36 = local_c1f4 + 2;
    for (uVar12 = (uint)*(ushort *)((int)puVar22 + 6); puVar23 = local_c1f8, uVar12 != 0;
        uVar12 = uVar12 - 1) {
      ppppppuVar15 = (uint ******)*local_c1f8;
      local_c1f8 = local_c1f8 + 1;
      *pppppppuVar36 = ppppppuVar15;
      pppppppuVar36 = pppppppuVar36 + 1;
    }
  case 0x18:
    goto switchD_000cbc48_caseD_18;
  case 0x19:
    local_c1f8 = puVar22 + 1;
    if (((uint)ppppppuVar15 & 0x18000000) == 0) {
      uVar12 = *(uint *)((int)local_9dd4 + ((uint)ppppppuVar15 >> 0xe & 0x3fc));
      if (uVar12 != 2) {
        uVar12 = 1;
      }
      ppppppuVar15 = (uint ******)((uVar12 & 3) << 0x1b | (uint)ppppppuVar15 & 0xe7ffffff);
    }
    *local_c1f4 = ppppppuVar15;
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1a:
    local_c1f8 = puVar22 + 1;
    *local_c1f4 = ppppppuVar15;
    pppppppuVar28 = local_c1f4 + 1;
    if ((int)ppppppuVar15 < 0) {
      ppppppuVar15 = (uint ******)*local_c1f8;
      local_c1f8 = puVar22 + 2;
      local_c1f4[1] = ppppppuVar15;
      pppppppuVar28 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar28;
    ppppppuVar15 = (uint ******)*local_c1f8;
    local_c1f8 = local_c1f8 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar23 = local_c1f8;
    pppppppuVar28 = pppppppuVar36;
    pppppppuVar36 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x1c:
    local_c1f8 = puVar22 + 1;
    pppppppuVar19 = local_c1f4 + 1;
    *local_c1f4 = ppppppuVar15;
    puVar23 = local_c1f8;
    pppppppuVar36 = pppppppuVar19;
    if ((puVar22[1] >> 0x10 & 0x3f) - 1 < 2) {
      local_c1f4[1] = (uint ******)puVar22[1];
      in_r8 = local_c1f4 + 6;
      local_c1f4[2] = (uint ******)puVar22[2];
      local_c1f4[3] = (uint ******)puVar22[3];
      local_c1f4[4] = (uint ******)puVar22[4];
      local_c1f8 = puVar22 + 6;
      local_c1f4[5] = (uint ******)puVar22[5];
      puVar23 = local_c1f8;
      pppppppuVar28 = local_c1f4 + 5;
      pppppppuVar36 = in_r8;
    }
    goto switchD_000cbc48_caseD_18;
  case 0x28:
    local_c1f8 = puVar22 + 1;
    puVar45 = (undefined4 *)
              ((int (*)())FUN_000c7930)(local_c1f4,&local_c08c,pppppppuVar19,puVar22,local_c1f8,in_r8,uVar12 * 4)
    ;
    *puVar45 = ppppppuVar15;
    puVar23 = local_c1f8;
    pppppppuVar36 = (uint *******)(puVar45 + 1);
    goto switchD_000cbc48_caseD_18;
  case 0x35:
    pppppppuVar19 = &local_c08c;
    *local_c1f4 = ppppppuVar15;
    local_c1f8 = puVar22 + 2;
    local_c1c0[0] = (uint ******)puVar22[1];
    local_c1f4 = local_c1f4 + 1;
    ((int (*)())FUN_000c8760)(local_c1c0,auStack_c1b4,pppppppuVar19);
    *local_c1f4 = local_c1c0[0];
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4 + 1;
    goto switchD_000cbc48_caseD_18;
  case 0x37:
  case 0x3e:
    pppppppuVar19 = (uint *******)0x0;
    break;
  case 0x3b:
    pppppppuVar19 = (uint *******)((int)((unsigned char *)0x0) + 1);
    break;
  case 0x5d:
    local_88 = &local_c08c;
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,local_88,pppppppuVar19,puVar22,puVar22,in_r8,local_88,
                                pppppppuVar28);
      puVar22 = local_c1f8;
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
    local_c1f0 = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      unaff_r15 = (uint ******)puVar23[1];
    }
    local_c1cc = (uint ******)*puVar22;
    local_c1f8 = puVar22 + 1;
    if (((uint)local_c1cc & 0x400000) != 0) {
      local_c1d8 = (uint ******)puVar22[1];
      local_c1f8 = puVar22 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc2a4:
      if (local_c01c << (uVar12 & 0x3f) == 0) {
        local_84 = (uint ******)&local_c1cc;
        pppppppuVar36 = (uint *******)0x0;
        uVar42 = 1 << (uVar12 & 0x3f);
        ppppppuVar14 = (uint ******)&local_c1d8;
      }
      else {
        local_84 = (uint ******)&local_c1cc;
        local_70 = (uint ******)&local_c1d8;
        local_c1f4 = (uint *******)((int (*)())FUN_000c7460)(local_88,local_84,local_70,uVar27,local_c1f4);
        ppppppuVar14 = local_70;
        if (((uint)local_c1f0 & 0x400000) == 0) {
          pppppppuVar36 = (uint *******)0x0;
          uVar42 = 1 << (uVar12 & 0x3f);
        }
        else {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          pppppppuVar36 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          local_c1e4 = unaff_r15;
        }
      }
    }
    else if (uVar9 == 0x8000000) {
      uVar42 = 1 << (uVar12 & 0x3f);
      if ((uVar42 & local_c018) != 0) goto LAB_000cc2a4;
      local_84 = (uint ******)&local_c1cc;
      pppppppuVar36 = (uint *******)0x0;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    else {
      pppppppuVar36 = (uint *******)0x0;
      uVar42 = 1 << (uVar12 & 0x3f);
      local_84 = (uint ******)&local_c1cc;
      ppppppuVar14 = (uint ******)&local_c1d8;
    }
    pppppppuVar19 = local_88;
    ((int (*)())FUN_000c8760)(local_84,ppppppuVar14,local_88);
    *local_c1f4 = ppppppuVar15;
    pppppppuVar28 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = ppppppuVar17;
      pppppppuVar28 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar28;
    if (bVar1) {
      *local_c1f4 = ppppppuVar39;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = (uint ******)local_c1f0;
    pppppppuVar28 = local_c1f4 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r15;
      pppppppuVar28 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar28;
    *local_c1f4 = local_c1cc;
    pppppppuVar28 = (uint *******)((uint)local_c1cc & 0x400000);
    pppppppuVar11 = local_c1f4 + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      local_c1f4[1] = local_c1d8;
      pppppppuVar11 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar11;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & local_c018) != 0)))) &&
       (local_c01c << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&local_c1f0;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c7650)(local_88,local_84,pppppppuVar19,&local_c1e4,uVar27,pppppppuVar36,
                                local_c1f4,pppppppuVar28);
      in_r8 = pppppppuVar36;
    }
    uVar42 = uVar42 & local_c01c;
    ppppppuVar15 = unaff_r15;
    goto joined_r0x000cc708;
  case 0x5e:
    if (bVar5) {
      bVar5 = false;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c8110)(local_c1f4,&local_c08c,pppppppuVar19,puVar22,puVar22,in_r8,
                                uVar12 * 4,pppppppuVar28);
      puVar22 = local_c1f8;
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
    local_c1f0 = (uint *******)*puVar23;
    puVar22 = puVar23 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      puVar22 = puVar23 + 2;
      unaff_r14 = (uint ******)puVar23[1];
    }
    local_c1d8 = (uint ******)*puVar22;
    puVar23 = puVar22 + 1;
    if (((uint)local_c1d8 & 0x400000) != 0) {
      local_c1cc = (uint ******)puVar22[1];
      puVar23 = puVar22 + 2;
    }
    local_c1d4 = (uint ******)*puVar23;
    local_c1f8 = puVar23 + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      local_c1c8 = (uint ******)puVar23[1];
      local_c1f8 = puVar23 + 2;
    }
    uVar9 = (uint)ppppppuVar15 & 0xc000000;
    if (uVar9 == 0x4000000) {
LAB_000cc588:
      if (local_c01c << (uVar12 & 0x3f) != 0) {
        pppppppuVar19 = &local_c1cc;
        local_c1f4 = (uint *******)
                     ((int (*)())FUN_000c7460)(&local_c08c,&local_c1d8,pppppppuVar19,uVar27,local_c1f4);
        if (((uint)local_c1f0 & 0x400000) != 0) {
          local_c1f0 = (uint *******)((uint)local_c1f0 & 0xffbfffff);
          in_r8 = (uint *******)((int)((unsigned char *)0x0) + 1);
          uVar42 = 1 << (uVar12 & 0x3f);
          local_c1e4 = unaff_r14;
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
      if ((uVar42 & local_c018) != 0) goto LAB_000cc588;
    }
LAB_000cc5e4:
    *local_c1f4 = ppppppuVar15;
    pppppppuVar28 = local_c1f4 + 1;
    if (bVar4) {
      local_c1f4[1] = ppppppuVar17;
      pppppppuVar28 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar28;
    if (bVar1) {
      *local_c1f4 = ppppppuVar39;
      local_c1f4 = local_c1f4 + 1;
    }
    *local_c1f4 = (uint ******)local_c1f0;
    pppppppuVar28 = local_c1f4 + 1;
    if (((uint)local_c1f0 & 0x400000) != 0) {
      local_c1f4[1] = unaff_r14;
      pppppppuVar28 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar28;
    *local_c1f4 = local_c1d8;
    pppppppuVar28 = (uint *******)((uint)local_c1d8 & 0x400000);
    pppppppuVar36 = local_c1f4 + 1;
    if (pppppppuVar28 != (uint *******)0x0) {
      local_c1f4[1] = local_c1cc;
      pppppppuVar36 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar36;
    *local_c1f4 = local_c1d4;
    pppppppuVar36 = local_c1f4 + 1;
    if (((uint)local_c1d4 & 0x400000) != 0) {
      local_c1f4[1] = local_c1c8;
      pppppppuVar36 = local_c1f4 + 2;
    }
    local_c1f4 = pppppppuVar36;
    if (((uVar9 == 0x4000000) || ((uVar9 == 0x8000000 && ((uVar42 & local_c018) != 0)))) &&
       (local_c01c << (uVar12 & 0x3f) != 0)) {
      pppppppuVar19 = (uint *******)&local_c1f0;
      local_c1f4 = (uint *******)
                   ((int (*)())FUN_000c7650)(&local_c08c,&local_c1d8,pppppppuVar19,&local_c1e4,uVar27,in_r8,
                                local_c1f4,pppppppuVar28);
    }
    uVar42 = uVar42 & local_c01c;
    ppppppuVar15 = unaff_r14;
joined_r0x000cc708:
    puVar23 = local_c1f8;
    pppppppuVar36 = local_c1f4;
    if (uVar42 != 0) {
      in_r8 = local_c1f4 + 1;
      *local_c1f4 = (uint ******)0x47;
      pppppppuVar28 = local_c1f0;
      if (((uint)local_c1f0 & 0x400000) == 0) {
        pppppppuVar28 = (uint *******)((uint)local_c1f0 | 0x400000);
        ppppppuVar15 = (uint ******)0x55;
      }
      if (local_bf94[uVar27] == 0x1906) {
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
      else if ((local_bf94[uVar27] == 0x1909) && (((uint)ppppppuVar15 & 0xc0) == 0x40)) {
        ppppppuVar15 = (uint ******)((uint)ppppppuVar15 & 0xffffff3f | 0xc0);
      }
      *in_r8 = (uint ******)pppppppuVar28;
      local_c1f4[2] = ppppppuVar15;
      local_c1f4[3] = (uint ******)((uint)pppppppuVar28 & 0x3fffff);
      pppppppuVar36 = local_c1f4 + 4;
    }
    goto switchD_000cbc48_caseD_18;
  }
  local_c1f8 = (uint *)((int (*)())FUN_000c8aa0)(&local_c1f4,&local_c1f8,pppppppuVar19,1,&local_c08c);
  puVar23 = local_c1f8;
  pppppppuVar36 = local_c1f4;
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
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,acStack_238,(double)*(float *)(param_2[0xc] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8,(double)*(float *)(param_2[0xc] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_138,(double)*(float *)(param_2[0xc] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_b8,(double)*(float *)(param_2[0xc] + iVar3 + 0xc));
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
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,acStack_238,(double)*(float *)(param_2[0xd] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8,(double)*(float *)(param_2[0xd] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_138,(double)*(float *)(param_2[0xd] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_b8,(double)*(float *)(param_2[0xd] + iVar3 + 0xc));
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
      iVar3 = uVar2 * 0x10;
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,acStack_238,(double)*(float *)(param_2[0xe] + iVar3));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_1b8,(double)*(float *)(param_2[0xe] + iVar3 + 4));
      uVar1 = ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_138,(double)*(float *)(param_2[0xe] + iVar3 + 8));
      ((char * (*)())FUN_000cdc3c)(uVar1,10,auStack_b8,(double)*(float *)(param_2[0xe] + iVar3 + 0xc));
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
  uint loopIndex;
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
  uint loopIndex2;
  uint uVar12;
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  uint local_98;
  int local_94 [3];
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong local_80;
  longlong local_78;
  undefined4 i2dHi2;
  uint i2dLo2;
  longlong local_68;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  
  local_94[0] = 0;
  local_98 = 0;
  pcVar7 = _ecvt(fparam_1,param_2,(int *)&local_98,local_94);
  bVar1 = local_94[0] != 0;
  if (bVar1) {
    *param_3 = '-';
  }
  uVar13 = (uint)bVar1;
  if (((int)local_98 < 1 - param_2) || (param_2 < (int)local_98)) {
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
    uVar13 = local_98 - 1;
    param_3[iVar8] = 'e';
    iVar4 = iVar8 + 1;
    if ((int)uVar13 < 0) {
      uVar13 = -uVar13;
      param_3[iVar4] = '-';
      iVar4 = iVar8 + 2;
    }
    i2dLo1 = uVar13 ^ 0x80000000;
    i2dHi1 = 0x43300000;
    local_98 = uVar13;
    dVar14 = _log((double)(float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0));
    dVar15 = _log(DOUBLE_001aa238);
    dVar3 = DOUBLE_001aa1e8;
    dVar2 = DOUBLE_001aa1e0;
    dVar14 = dVar14 / dVar15;
    if (DOUBLE_001aa1e8 <= dVar14) {
      local_78 = (longlong)(int)(dVar14 - DOUBLE_001aa1e8);
      uVar10 = (int)(dVar14 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar10 = (uint)(int)dVar14;
      local_80 = (longlong)(int)uVar10;
    }
    loopIndex2 = 0;
    pcVar7 = param_3 + iVar4;
    uVar12 = uVar10;
    do {
      i2dLo2 = uVar12 ^ 0x80000000;
      i2dHi2 = 0x43300000;
      dVar16 = (double)CONCAT44(0x43300000,i2dLo2) - dVar2;
      dVar15 = _pow(DOUBLE_001aa238,dVar16);
      dVar14 = DOUBLE_001aa238;
      if (dVar3 <= dVar15) {
        iVar8 = (int)(dVar15 - dVar3);
        local_60 = (longlong)iVar8;
        uVar5 = iVar8 + 0x80000000;
      }
      else {
        uVar5 = (uint)(int)dVar15;
        local_68 = (longlong)(int)uVar5;
      }
      cVar6 = (char)(uVar13 / uVar5);
      *pcVar7 = cVar6 + '0';
      dVar14 = _pow(dVar14,dVar16);
      if (DOUBLE_001aa1e8 <= dVar14) {
        local_50 = (longlong)(int)(dVar14 - DOUBLE_001aa1e8);
        iVar8 = (int)(dVar14 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar8 = (int)dVar14;
        local_58 = (longlong)iVar8;
      }
      loopIndex2 = loopIndex2 + 1;
      pcVar7 = pcVar7 + 1;
      uVar12 = uVar12 - 1;
      uVar13 = local_98 - cVar6 * iVar8;
      local_98 = uVar13;
    } while (loopIndex2 <= uVar10);
    param_3[loopIndex2 + iVar4] = '\0';
  }
  else {
    uVar10 = uVar13;
    if ((int)local_98 < 1) {
      param_3[bVar1] = '0';
      uVar10 = uVar13 + 2;
      param_3[uVar13 + 1] = '.';
      if ((int)local_98 < 0) {
        iVar8 = -local_98;
        pcVar9 = param_3 + uVar10;
        if (0 < (int)(local_98 + 1)) {
          iVar8 = 1;
        }
        do {
          *pcVar9 = '0';
          uVar10 = uVar10 + 1;
          pcVar9 = pcVar9 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      local_98 = 0xffffffff;
    }
    if (*pcVar7 != '\0') {
      loopIndex = 0;
      pcVar9 = pcVar7;
      do {
        if (loopIndex == local_98) {
          local_98 = 0xffffffff;
          param_3[uVar10] = '.';
          uVar10 = uVar10 + 1;
        }
        loopIndex = loopIndex + 1;
        param_3[uVar10] = *pcVar9;
        uVar10 = uVar10 + 1;
        pcVar9 = pcVar7 + loopIndex;
      } while (pcVar7[loopIndex] != '\0');
    }
    param_3[uVar10] = '\0';
    if (local_98 == 0xffffffff) {
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
  undefined1 auStack_a4 [152];
  
  if (*(int *)(param_1 + 8) != 0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
    FUN_001a34d4(auStack_a4,param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7,param_8);
    pcVar2 = (char *)_strchr(auStack_a4,0x3f);
    if (pcVar2 != (char *)0x0) {
      for (; (((cVar1 = *pcVar2, cVar1 == '?' || (cVar1 == ' ')) || (cVar1 == ',')) ||
             (cVar1 == '\t')); pcVar2 = pcVar2 + -1) {
      }
      pcVar2[1] = '\0';
    }
    FUN_001a32d0(auStack_a4,"%s\n",auStack_a4,param_4,param_5,param_6,param_7,param_8);
    (*(code *)**(undefined4 **)(param_1 + 8))
              (*(undefined4 *)(param_1 + 0xc),"",auStack_a4,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
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
  int length;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 in_r10;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_48 [32];
  
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
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x2d00;
  }
  else {
    uVar7 = -uVar2 >> 0x1f;
  }
  if (uVar3 == 1) {
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x7600;
  }
  else if (uVar3 == 0) {
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x7200;
  }
  else if (uVar3 == 2) {
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x6300;
  }
  else if (uVar3 == 3) {
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x7400;
  }
  else {
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x3f00;
  }
  FUN_001a32d0(auStack_48,"%d",uVar10 & 0xff,in_r6,in_r7,in_r8,uVar6,in_r10);
  if (uVar9 == 0) {
    _strcat(param_3,auStack_48);
  }
  else {
    if (uVar9 == 0x10) {
      length = _strlen(param_3);
      *(undefined4 *)(param_3 + length) = 0x5b613000;
    }
    else {
      length = _strlen(param_3);
      *(undefined4 *)(param_3 + length) = 0x5b693000;
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
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x2b00;
    _strcat(param_3,auStack_48);
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x5d00;
  }
  if ((uVar4 != 0xd10000) || (uVar7 != 0)) {
    uVar8 = 0;
    length = _strlen(param_3);
    *(undefined2 *)(param_3 + length) = 0x2e00;
    uVar10 = 0xd;
    do {
      if (((uVar2 & 0x2000000 << (uVar8 & 0x3f)) != 0) && (uVar7 != 0)) {
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x2d00;
      }
      switch((uVar4 & 7 << (uVar10 & 0x3f)) >> (uVar10 & 0x3f)) {
      case 0:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x7800;
        break;
      case 1:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x7900;
        break;
      case 2:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x7a00;
        break;
      case 3:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x7700;
        break;
      case 4:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x3000;
        break;
      case 5:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x3100;
        break;
      default:
        length = _strlen(param_3);
        *(undefined2 *)(param_3 + length) = 0x3f00;
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
  int loopIndex;
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
    loopIndex = 0;
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
        if ((loopIndex != 0) && ((uint)bVar2 != *(uint *)(pcVar8 + 0xc))) {
          bVar1 = true;
        }
        loopIndex = loopIndex + 1;
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
                       ,loopIndex,pcVar7,pcVar8);
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
  int length;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined1 auStack_38 [28];
  
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
  FUN_001a32d0(auStack_38,"%d",uVar6 >> 0xd & 0x7f,param_4,param_5,param_6,pcVar5,param_8);
  if ((uVar6 & 0x80001000) == 0) {
    _strcat(param_3,auStack_38);
  }
  else {
    if ((uVar6 & 0x80001000) == 0x80000000) {
      length = _strlen(param_3);
      builtin_strncpy(param_3 + length,"[a0",4);
    }
    else {
      length = _strlen(param_3);
      builtin_strncpy(param_3 + length,"[i0",4);
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
    length = _strlen(param_3);
    (param_3 + length)[0] = '+';
    (param_3 + length)[1] = '\0';
    _strcat(param_3,auStack_38);
    length = _strlen(param_3);
    (param_3 + length)[0] = ']';
    (param_3 + length)[1] = '\0';
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
    length = _strlen(param_3);
    (param_3 + length)[0] = '.';
    (param_3 + length)[1] = '\0';
    if ((uVar6 & 0x100000) != 0) {
      length = _strlen(param_3);
      (param_3 + length)[0] = 'x';
      (param_3 + length)[1] = '\0';
    }
    if ((uVar6 & 0x200000) != 0) {
      length = _strlen(param_3);
      (param_3 + length)[0] = 'y';
      (param_3 + length)[1] = '\0';
    }
    if ((uVar6 & 0x400000) != 0) {
      length = _strlen(param_3);
      (param_3 + length)[0] = 'z';
      (param_3 + length)[1] = '\0';
    }
    if ((uVar6 & 0x800000) != 0) {
      length = _strlen(param_3);
      (param_3 + length)[0] = 'w';
      (param_3 + length)[1] = '\0';
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
  int length;
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int length2;
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
  undefined1 auStack_48 [5];
  undefined1 auStack_43 [23];
  
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
  FUN_001a32d0(auStack_48,"%d",uVar12 >> 0x13 & 3,puVar5,puVar6,in_r8,iVar7,in_r10);
  if ((uVar9 & 0x2000000) != 0) {
    _strcat(param_4,"_sat");
  }
  _strcat(param_4,auStack_48);
  length2 = _strlen(param_4);
  *(undefined2 *)(length2 + (int)param_4) = 0x2e00;
  if (uVar10 == 0) {
    length2 = _strlen(param_4);
    *(undefined2 *)(length2 + (int)param_4) = 0x7800;
  }
  else if (uVar10 == 0x8000000) {
    length2 = _strlen(param_4);
    *(undefined2 *)(length2 + (int)param_4) = 0x7900;
  }
  else if (uVar10 == 0x10000000) {
    length2 = _strlen(param_4);
    *(undefined2 *)(length2 + (int)param_4) = 0x7a00;
  }
  else if (uVar10 == 0x18000000) {
    length2 = _strlen(param_4);
    *(undefined2 *)(length2 + (int)param_4) = 0x7700;
  }
  length2 = _strlen(param_4);
  *(undefined2 *)(length2 + (int)param_4) = 0x2c00;
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
  FUN_001a32d0(auStack_43,"%d",uVar12 >> 5 & 0xff,puVar5,puVar6,in_r8,iVar7,in_r10);
  _strcat(param_5,auStack_43);
  uVar10 = uVar12 & 0x6000000;
  if (((uVar12 & 0x7e000) != 0x10000) || (uVar10 != 0)) {
    uVar11 = 0;
    length = _strlen(param_5);
    *(undefined2 *)(length + (int)param_5) = 0x2e00;
    uVar3 = 0xd;
    do {
      if (((uVar10 & 0x2000000 << (uVar11 & 0x3f)) != 0) && (uVar10 != 0)) {
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x2d00;
      }
      switch((uVar12 & 0x7e000 & 7 << (uVar3 & 0x3f)) >> (uVar3 & 0x3f)) {
      case 0:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x7800;
        break;
      case 1:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x7900;
        break;
      case 2:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x7a00;
        break;
      case 3:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x7700;
        break;
      case 4:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x3000;
        break;
      case 5:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x3100;
        break;
      default:
        length = _strlen(param_5);
        *(undefined2 *)(length + (int)param_5) = 0x3f00;
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
  int length;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int loopIndex;
  undefined1 auStack_98 [120];
  
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
    loopIndex = 0;
    while( true ) {
      iVar1 = loopIndex * 0x1c + *(int *)(iVar1 + 0x654);
      piVar5 = (int *)(*(int *)(iVar1 + 0x14) + 1);
      if (piVar5 == piVar3) {
        ((int (*)())FUN_000cfd24)(param_1,iVar1 + 4,piVar3,uVar2,uVar4,param_6,piVar5,param_8);
        piVar3 = (int *)param_1[1];
      }
      loopIndex = loopIndex + 1;
      if (iVar6 == loopIndex) break;
      iVar1 = *param_1;
    }
  }
  FUN_001a32d0(auStack_98,"%3d:",piVar3,uVar2,uVar4,param_6,piVar5,param_8);
  _strcat(param_3,auStack_98);
  param_1[1] = param_1[1] + 1;
  length = _strlen(param_3);
  uVar2 = ((int (*)())FUN_000cf2ec)(param_1,param_2,param_3 + length,param_4,param_5);
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
  int length2;
  int length;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int loopIndex;
  int iVar5;
  int local_d8;
  int local_d4;
  int aiStack_d0 [5];
  undefined1 auStack_ba [22];
  undefined1 auStack_a4 [22];
  undefined2 auStack_8e [11];
  int aiStack_78 [12];
  
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
    loopIndex = 0;
    do {
      param_4 = &local_d8;
      param_5 = &local_d4;
      iVar1 = ((int (*)())FUN_000cff30)(param_1,iVar5,auStack_ba,param_4,&local_d4,param_6,param_7,param_8);
      param_3 = auStack_ba;
      if (iVar1 == 0) {
        if (local_d8 == 0) {
          uVar2 = ((int (*)())FUN_000cea6c)(param_1,iVar5,aiStack_78,param_4,param_5,param_6,param_7,param_8);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,aiStack_d0);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,auStack_8e);
          iVar5 = ((int (*)())FUN_000ce148)(param_1,uVar2,auStack_a4);
          if (local_d4 == 1) {
            length = _strlen(aiStack_78);
            *(undefined2 *)((int)aiStack_78 + length) = 0x2c00;
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
            length = _strlen(aiStack_78);
            *(undefined2 *)((int)aiStack_78 + length) = 0x2c00;
            length = _strlen(aiStack_d0);
            *(undefined2 *)((int)aiStack_d0 + length) = 0x2c00;
            param_4 = aiStack_78;
            param_5 = aiStack_d0;
            param_6 = auStack_8e;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,aiStack_78,aiStack_d0,auStack_8e,
                         param_7,param_8);
          }
          else {
            length = _strlen(aiStack_78);
            *(undefined2 *)((int)aiStack_78 + length) = 0x2c00;
            length = _strlen(aiStack_d0);
            *(undefined2 *)((int)aiStack_d0 + length) = 0x2c00;
            length = _strlen(auStack_8e);
            *(undefined2 *)((int)auStack_8e + length) = 0x2c00;
            param_4 = aiStack_78;
            param_5 = aiStack_d0;
            param_6 = auStack_8e;
            param_7 = auStack_a4;
            ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s%s",auStack_ba,aiStack_78,aiStack_d0,auStack_8e,
                         auStack_a4,param_8);
          }
        }
        else {
          uVar2 = ((int (*)())FUN_000cea6c)(param_1,iVar5,aiStack_78,param_4,param_5,param_6,param_7,param_8);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,aiStack_d0);
          uVar2 = ((int (*)())FUN_000ce148)(param_1,uVar2,auStack_8e);
          length2 = _strlen(aiStack_78);
          *(undefined2 *)((int)aiStack_78 + length2) = 0x2c00;
          length2 = _strlen(aiStack_d0);
          *(undefined2 *)((int)aiStack_d0 + length2) = 0x2c00;
          param_6 = auStack_8e;
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s%-15s",auStack_ba,aiStack_78,aiStack_d0,auStack_8e,
                       param_7,param_8);
          iVar5 = ((int (*)())FUN_000ced58)(param_1,uVar2,auStack_ba,aiStack_78,aiStack_d0);
          param_4 = aiStack_78;
          param_5 = aiStack_d0;
          ((int (*)())FUN_000ce050)(param_1,"%s %-10s%-15s",auStack_ba,aiStack_78,aiStack_d0,param_6,param_7,
                       param_8);
        }
      }
      else {
        iVar5 = iVar5 + 0x10;
        ((int (*)())FUN_000ce050)(param_1,"%s",auStack_ba,param_4,param_5,param_6,param_7,param_8);
      }
      loopIndex = loopIndex + 1;
    } while (iVar3 != loopIndex);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined1 auStack_124 [280];
  
  if (DAT_001fa61c != (undefined4 *)0x0) {
    (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
    (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
    (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
    (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
    (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
    (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
    FUN_001a34d4(auStack_124,param_2,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),param_4,param_5,param_6,param_7,param_8);
    (*(code *)*DAT_001fa61c)(DAT_001fa618,"",auStack_124,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
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
  int length;
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  char local_38 [6];
  undefined1 auStack_32 [22];
  
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
      param_4 = uVar6;
    }
  }
  else {
    builtin_strncpy(local_38,"???",4);
  }
  length = _strlen(param_1);
  pcVar5 = param_1 + length;
  if (param_8 < 0x20) {
    puVar8 = ((unsigned char *)0x000d0730) + *(int *)(((unsigned char *)0x000d0730) + param_8 * 4);
                    
    switch(param_8) {
    default:
      FUN_001a32d0(pcVar5,"%s.rgb",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 1:
    case 5:
    case 9:
    case 0x10:
      FUN_001a32d0(pcVar5,"%s.rrr",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 2:
    case 6:
    case 10:
    case 0x11:
      FUN_001a32d0(pcVar5,"%s.ggg",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 3:
    case 7:
    case 0xb:
    case 0x12:
      FUN_001a32d0(pcVar5,"%s.bbb",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0xc:
    case 0xd:
    case 0xe:
    case 0x13:
      FUN_001a32d0(pcVar5,"%s.aaa",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x14:
    case 0x15:
    case 0x16:
      goto override_jmp_000d072c_case_5;
    case 0x17:
    case 0x18:
    case 0x19:
      FUN_001a32d0(pcVar5,"%s.gbr",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x1a:
    case 0x1b:
    case 0x1c:
      FUN_001a32d0(pcVar5,"%s.brg",local_38,param_4,param_5,param_6,puVar8,uVar9);
      break;
    case 0x1d:
      FUN_001a32d0(pcVar5,"%s.a:%s.bg",local_38,auStack_32,param_5,param_6,puVar8,uVar9);
    }
  }
  else {
override_jmp_000d072c_case_5:
    _strcpy(pcVar5,local_38);
  }
  length = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + length)[0] = ')';
    (param_1 + length)[1] = '\0';
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
  int length;
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  char local_28 [24];
  
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
  length = _strlen(param_1);
  pcVar5 = param_1 + length;
  if (param_8 < 0x10) {
    puVar7 = ((unsigned char *)0x000d0aa4) + *(int *)(((unsigned char *)0x000d0aa4) + param_8 * 4);
                    
    switch(param_8) {
    default:
      FUN_001a32d0(pcVar5,"%s.r",local_28,param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 1:
    case 4:
    case 7:
      FUN_001a32d0(pcVar5,"%s.g",local_28,param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 2:
    case 5:
    case 8:
      FUN_001a32d0(pcVar5,"%s.b",local_28,param_4,param_5,param_6,puVar7,uVar8);
      break;
    case 9:
      FUN_001a32d0(pcVar5,"%s.a",local_28,param_4,param_5,param_6,puVar7,uVar8);
    }
  }
  else {
    _strcpy(pcVar5,local_28);
  }
  length = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + length)[0] = ')';
    (param_1 + length)[1] = '\0';
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
  uint loopIndex2;
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
  uint loopIndex;
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
    loopIndex = 1;
    do {
      loopIndex = loopIndex + 1;
      if (*piVar7 != 1) goto LAB_000d0bfc;
      piVar7 = piVar7 + 0x12;
    } while (loopIndex <= uVar12);
LAB_000d0bd8:
    uVar10 = 0;
    uVar9 = 0;
    bVar3 = true;
  }
  else {
    loopIndex = 1;
LAB_000d0bfc:
    if (uVar12 < loopIndex) goto LAB_000d0bd8;
    uVar10 = 0;
    bVar3 = true;
    puVar17 = (uint *)(param_1 + loopIndex * 0x48);
    uVar16 = 0;
    uVar13 = 0;
    bVar1 = false;
    uVar9 = 0;
    uVar15 = loopIndex;
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
  if (loopIndex <= uVar12) {
    bVar1 = uVar10 != 0;
    puVar17 = (uint *)(param_1 + loopIndex * 0x48);
    puVar14 = (undefined1 *)((int)puVar17 + -3);
    loopIndex2 = 0;
    uVar15 = 100000;
    uVar16 = loopIndex;
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
             (loopIndex2 != *(ushort *)(param_1 + 0x12))) {
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
        if (loopIndex2 == 0) {
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
      loopIndex2 = loopIndex2 + 1;
      puVar17 = puVar17 + 0x12;
      puVar14 = puVar14 + 0x48;
      uVar15 = uVar4;
    } while (uVar16 <= uVar12);
    if (((loopIndex2 != 0) &&
        (iVar6 = (*(ushort *)(param_1 + 0x12) + loopIndex) * 0x48, *(int *)(param_1 + iVar6) == 3)) &&
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
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong local_80;
  undefined4 local_78;
  uint uStack_74;
  undefined4 i2dHi2;
  uint i2dLo2;
  longlong local_68;
  undefined4 i2dHi3;
  uint i2dLo3;
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
          i2dHi1 = 0x43300000;
          i2dLo1 = ((uint)(int)local_50 >> 0x17 & 0xff) - 0x7f ^ 0x80000000;
          dVar10 = _pow(DOUBLE_001aa2a0,(double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0);
          dVar10 = _log(dVar10);
          dVar11 = _log(dVar3);
          dVar10 = _floor(dVar10 / dVar11);
          local_78 = 0x43300000;
          uVar7 = (uint)(int)dVar10;
          local_80 = (longlong)(int)uVar7;
          uStack_74 = uVar7 ^ 0x80000000;
          dVar11 = _pow(dVar3,(double)CONCAT44(0x43300000,uStack_74) - dVar2);
          dVar10 = DOUBLE_001aa298;
          dVar11 = dVar9 / dVar11 + DOUBLE_001aa298;
          if (dVar3 <= dVar11) {
            uVar7 = uVar7 + 1;
            i2dHi2 = 0x43300000;
            i2dLo2 = uVar7 ^ 0x80000000;
            dVar11 = _pow(dVar3,(double)CONCAT44(0x43300000,i2dLo2) - dVar2);
            dVar11 = dVar9 / dVar11 + dVar10;
          }
          dVar9 = _floor(dVar11);
          uVar5 = (uint)(int)dVar9;
          local_68 = (longlong)(int)uVar5;
          local_98[2] = 0x2e;
          iVar6 = 3;
          local_98[1] = (char)uVar5 + '0';
          do {
            i2dLo3 = uVar5 ^ 0x80000000;
            i2dHi3 = 0x43300000;
            dVar11 = (dVar11 - ((double)CONCAT44(0x43300000,i2dLo3) - dVar2)) * dVar3;
            dVar9 = _floor(dVar11);
            bVar1 = iVar6 != 9;
            uVar5 = (uint)(int)dVar9;
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
  int length;
  int length2;
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
  char local_58 [44];
  
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
    ((double (*)())FUN_000d10dc)(local_58,param_2,param_3,uVar10,param_5,param_6,pcVar13,iVar8,in_f1);
  }
  else {
    uVar9 = param_3;
    uVar11 = param_5;
    uVar12 = param_6;
    iVar7 = ((int (*)())FUN_000d10a8)(param_10 & 0xffff);
    if (iVar7 == 0) {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(local_58,param_3,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      param_3 = uVar9;
      param_5 = uVar11;
      param_6 = uVar12;
      in_f1 = fparam_1;
      if (param_8 == 0) goto LAB_000d14bc;
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_58,param_4,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
    }
    else {
      if (param_8 == 1) {
        ((double (*)())FUN_000d10dc)(local_58,param_6,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      if (param_8 == 0) {
        ((double (*)())FUN_000d10dc)(local_58,param_5,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
        goto LAB_000d1518;
      }
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_58,param_7,uVar9,uVar10,uVar11,uVar12,pcVar13,iVar8,fparam_1);
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
  length2 = _strlen(param_1);
  uVar1 = param_10 & 0xffff;
  uVar2 = param_10 & 0xff80;
  if (((uVar2 == 0x9200) || (uVar2 == 0xdb00)) || (uVar2 == 0xb680)) {
    _strcpy(param_1 + length2,(uVar1 >> 0xb & 0x1c) + 0x1dc259);
  }
  else {
    FUN_001a32d0(param_1 + length2,"%s.%s%s%s",local_58,(uVar1 >> 0xb & 0x1c) + 0x1dc259,
                 (uVar1 >> 8 & 0x1c) + 0x1dc259,(uVar1 >> 5 & 0x1c) + 0x1dc259,uVar1,iVar8);
  }
  length = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + length)[0] = ')';
    (param_1 + length)[1] = '\0';
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
  int length;
  char *pcVar6;
  double in_f1;
  char local_38 [40];
  
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
          ((double (*)())FUN_000d10dc)(local_38,param_2,param_7,param_4,param_5,param_6,pcVar6,0,in_f1);
          goto LAB_000d1780;
        }
        param_3 = param_4;
        if (param_8 != 2) goto LAB_000d176c;
      }
      ((double (*)())FUN_000d10dc)(local_38,param_3,param_7,param_4,param_5,param_6,pcVar6,param_8,in_f1);
      goto LAB_000d1780;
    }
    if (param_8 == 1) {
      ((double (*)())FUN_000d10dc)(local_38,param_6,param_7,param_4,param_5,param_6,pcVar6,1,in_f1);
      goto LAB_000d1780;
    }
    if (param_8 != 0) {
      if (param_8 == 2) {
        ((double (*)())FUN_000d10dc)(local_38,param_7,param_7,param_4,param_5,param_6,pcVar6,2,in_f1);
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
  ((double (*)())FUN_000d10dc)(local_38,param_5,param_7,param_4,param_5,param_6,pcVar6,param_8,in_f1);
LAB_000d1780:
  length = _strlen(param_1);
  if (param_10 - 4U < 3) {
    _strcpy(param_1 + length,param_10 * 4 + 0x1dc259);
  }
  else {
    FUN_001a32d0(param_1 + length,"%s.%s",local_38,param_10 * 4 + 0x1dc259,param_5,param_6,pcVar6,
                 param_8);
  }
  length = _strlen(param_1);
  if (param_9 != 0) {
    (param_1 + length)[0] = ')';
    (param_1 + length)[1] = '\0';
  }
  return;
}

/* FUN_000d183c @ 0xd183c (13160 bytes) */
int FUN_000d183c(pixelShader, dumpLabel, dumpId, argR6, argR7, argR8, argR9, argR10)
  uint *pixelShader;
  uint dumpLabel;
  uint *dumpId;
  char *argR6;
  uint argR7;
  uint *argR8;
  char *argR9;
  byte *argR10;
{
  undefined4 cfNameLength;
  uint psnRecordIndex;
  bool rgbSelectBNotSrcp;
  bool rgbOperandBUsed;
  bool rgbSrcpNeededFlag;
  bool depthWriteFlag2;
  bool rgbSelectCNotSrcp;
  bool rgbOperandCUsed;
  bool texEnableG;
  uint rgbOutputWriteMask;
  char cfAddressByte;
  char rsColorSource;
  char rgbPreOpKind;
  int cfOpTableIndex;
  int rgbDestMaskOffset;
  int instructionNumberArg;
  byte *rgbOpcodePtr;
  byte *predicateControlPtr;
  byte *dySwizzleTextZ;
  char *dySwizzleTextX;
  char *dySwizzleTextW;
  char *dxSwizzleTextX;
  char *dySwizzleTextY;
  char *dxSwizzleTextW;
  char *srcSwizzleTextX;
  char *dxSwizzleTextY;
  char *srcSwizzleTextZ;
  int rsRecordNumber2;
  int rgbThirdOperandUsed;
  uint *semWaitTextPtr;
  uint *alphaOpcodePtr;
  uint *alphaOutIndexArg;
  uint psnRecordKind;
  uint alphaOperandUseMask;
  bool alphaOutputEnableFlag2;
  bool alphaSrcpNeededFlag;
  bool rgbSelectANotSrcp;
  bool rgbOperandAUsed;
  bool texSwizzleEnabled;
  bool texEnableR;
  bool alphaOutputEnableFlag;
  bool alphaSrcpNeededFmt1;
  uint rgbSelectCRaw;
  uint recordKind2;
  uint rsColorWriteMask;
  uint psnRecordCount;
  uint *srcSwizzleTextPtr;
  uint *registerTextPtr;
  uint *rsNextRecordCopy2;
  uint *alphaAddrAFmt1;
  byte predicateModeByteAlpha2;
  byte alphaOutputScaleByte2;
  byte alphaOpcodeByte2;
  byte predicateModeByte2;
  byte rgbOutputScaleByte2;
  byte rgbOpcodeByte2;
  byte rgbTempWriteMask2;
  byte srcpNeedBit;
  byte predicateModeByteAlpha;
  byte predicateModeByte;
  byte texDySwizzleByte;
  byte texDxSwizzleByte;
  byte texOpcodeByte;
  byte texSrcSwizzleByte2;
  byte texSrcSwizzleByte;
  byte texEnableBits;
  byte alphaOutputScaleByte;
  byte alphaOpcodeByte;
  byte rgbOutputScaleByte;
  byte rgbOpcodeByte;
  uint *operandText1Ptr;
  uint *alphaUseBitB;
  uint *operandText5PtrFmt1;
  uint *rgbOutIndexArg;
  uint *operandText5Ptr;
  uint *rgbDestMaskTextPtr;
  uint *aluIndexArg;
  uint *operandText0Ptr;
  uint *operandText4Ptr2;
  uint *neutralLineArg0;
  uint *psnLineArg1;
  uint *alphaSrcpTextPtr;
  uint alphaSelectCBaseArg;
  uint rgbOpcodeBit;
  uint dySwizzleWOffset;
  uint dxSwizzleWOffset;
  uint texComponentEnableBits;
  uint neutralRecordCountArg;
  uint psnLineArg0;
  uint rgbOperandUseMask;
  uint usListStaleZero;
  uint nominalCycleCount;
  uint *alphaAddrA;
  uint *texUnit2;
  uint *texOpcode;
  uint *rgbAddrC;
  uint *rgbAddrB;
  uint *instructionRecord2;
  uint *rsNextRecord2;
  uint *instructionRecord;
  uint *rsNextRecord;
  uint *rsRecord2;
  uint *rsRecord;
  uint *rsScanRecord2;
  uint *rsScanRecord;
  ushort rgbAuxB;
  ushort rgbAuxA;
  uint rgbAddrA;
  uint alphaSelectA;
  uint alphaAuxB;
  uint alphaSelectB2;
  uint texSrcReg;
  uint alphaAuxC;
  uint texDestReg;
  uint alphaSelectB;
  uint alphaSelectC;
  char rgbOutIndex;
  char alphaTempEnable;
  char alphaPreOp;
  bool texEnableA;
  bool depthWriteFlag;
  byte rgbTempWriteMask;
  byte texWriteMask;
  char depthWrite;
  char alphaOutIndex;
  ushort texSrcReg2;
  ushort texDestReg2;
  char levelLetter;
  int auxCheckResult;
  undefined4 operandAuxWord;
  int cfNameCompare;
  uint *dumpIdArg;
  char *maskTextX;
  uint rgbSelectCRawFmt1;
  char *maskTextY;
  uint *aluNumberArg;
  uint rgbOutputMaskText;
  uint dumpLabelArg;
  char *maskTextZ;
  uint *srcpTextAPtr;
  char *maskTextW;
  bool statsLoopMore;
  uint rgbSrcpNeeded;
  byte *dxSwizzleTextZ;
  uint levelNumber;
  uint recordKind;
  uint alphaOpcodeBit;
  uint rgbSelectB;
  uint uVar30;
  int statsIndex;
  uint *rgbAddrCFmt1;
  uint *rgbAddrBFmt1;
  uint texUnit;
  uint *rsNextRecordCopy;
  uint rgbAddrA2;
  uint rsRecordNumber;
  undefined **cfOpNameCursor;
  bool texEnableB;
  undefined *cfOpNameEntry;
  uint *statByteCursor;
  double printfResultScratch;
  uint dumpLabelSlot;
  uint *dumpIdSlot;
  undefined2 operandAuxHigh;
  uint *in_stack_fffffd2c;
  undefined4 predicateText;
  uint semWaitText;
  char semWaitText4 [4];
  char semWaitText8 [2];
  uint srcpTextA;
  char local_2a6 [6];
  undefined2 srcpTextB;
  undefined1 uStack_29e;
  uint semGrabText;
  char semGrabText4 [4];
  char semGrabText8 [2];
  uint aluWaitText;
  char aluWaitText4 [4];
  char aluWaitText8 [2];
  uint ignUncText;
  char ignUncText4 [4];
  char ignUncText8;
  uint registerText [3];
  uint dxSwizzleTextA [3];
  undefined1 writeMaskText [15];
  uint srcSwizzleText [3];
  uint operandText0 [8];
  uint operandText1 [8];
  uint operandText2 [8];
  uint operandText3 [8];
  uint operandText4 [8];
  uint operandText5 [8];
  uint operandText6 [8];
  uint cfWordText [25];
  int cfIndex;
  int texIndex;
  uint *aluIndex;
  uint cfCompareCode;
  int texNumber;
  uint rgbSelectABase;
  uint rgbSelectBBase;
  uint rgbSelectCBase;
  uint alphaSelectABase;
  uint alphaSelectBBase;
  uint alphaSelectCBase;
  byte *rgbOpcodePtr2;
  uint *alphaOpcodePtr2;
  uint alphaModC;
  uint alphaModB;
  uint alphaModA;
  uint rgbModC;
  uint rgbModB;
  uint rgbModA;
  byte *alphaSelectC2;
  uint previousIsAlu;
  uint *aluNumber;
  uint recordCount;
  uint *alphaAuxD;
  uint alphaUseMaskNeutral;
  uint alphaModC2;
  uint alphaModB2;
  uint alphaModA2;
  uint rgbModC2;
  uint rgbModB2;
  uint rgbModA2;
  uint recordCount2;
  uint texFlagsByte;
  uint cfPrevAluDest;
  int instructionNumber;
  ushort rgbAuxC;
  uint *operandText2Ptr;
  uint *operandText3Ptr;
  uint *operandText4Ptr;
  int blankLineFormatOffset;
  
  dumpLabelSlot = dumpLabel;
  dumpIdSlot = dumpId;
  ((int (*)())FUN_000d0b68)(pixelShader,1,dumpId,argR6,argR7,argR8,argR9,argR10);
  if ((*(byte *)((int)pixelShader + 0xf) & 0x10) == 0) {
    recordCount = pixelShader[2];
    dumpLabelArg = dumpLabelSlot;
    dumpIdArg = dumpIdSlot;
    ((int (*)())FUN_000d03b4)(0,"======== Begin Loki NSF pixel shader dump: %s: %d ========\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    if (*(short *)(pixelShader + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    }
    else {
      statsIndex = 0;
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Levels:                 %2d\n",(uint)*(ushort *)((int)pixelShader + 0x16),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(pixelShader + 6),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1a),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(pixelShader + 7),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1e),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)pixelShader + 0x22),
                   dumpIdArg,argR7,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(pixelShader + 9),dumpIdArg,
                   argR7,argR8,argR9,argR10);
      nominalCycleCount = (uint)*(ushort *)((int)pixelShader + 0x26);
      ((int (*)())FUN_000d03b4)(0,"     Nominal cycle count:    %2d\n",nominalCycleCount,dumpIdArg,argR7,argR8,argR9,
                   argR10);
      ((int (*)())FUN_000d03b4)(0,"     Tex lookup counts:     ",nominalCycleCount,dumpIdArg,argR7,argR8,argR9,argR10);
      statByteCursor = pixelShader;
      do {
        dumpLabelArg = (uint)*(byte *)((int)statByteCursor + 0x2a);
        ((int (*)())FUN_000d03b4)(0," %2d",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        statsLoopMore = statsIndex != 0xf;
        statByteCursor = (uint *)((int)statByteCursor + 1);
        statsIndex = statsIndex + 1;
      } while (statsLoopMore);
      ((int (*)())FUN_000d03b4)(0,"\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    if ((pixelShader[0x12] == 1) && (recordCount != 0)) {
      rsScanRecord = pixelShader + 0x24;
      rsRecordNumber = 1;
      rsNextRecord = rsScanRecord;
      rsRecord = pixelShader + 0x12;
      do {
        rsNextRecordCopy = rsNextRecord;
        dumpLabelArg = rsRecordNumber - 1;
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        if (*(char *)((int)rsRecord + 0xb) == '\0') {
          if (*(char *)((int)rsRecord + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,
                         argR10);
            goto LAB_000d3b80;
          }
LAB_000d3be0:
          ((int (*)())FUN_000d03b4)(0,"\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        }
        else {
          dumpLabelArg = (uint)*(ushort *)((int)rsRecord + 6);
          argR7 = (uint)*(byte *)((int)rsRecord + 10);
          dumpIdArg = (uint *)((*(byte *)((int)rsRecord + 0xf) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          if (*(char *)((int)rsRecord + 0xd) == '\0') {
            if (*(char *)((int)rsRecord + 0xb) == '\x02') {
              ((int (*)())FUN_000d03b4)(0," fbuf  ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
            else if (*(char *)((int)rsRecord + 0xb) == '\x03') {
              ((int (*)())FUN_000d03b4)(0," back  ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
            else {
              if (*(char *)((int)rsRecord + 9) == '\0') goto LAB_000d3be0;
              ((int (*)())FUN_000d03b4)(0,"       ",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0," biased",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          }
LAB_000d3b80:
          if (*(char *)((int)rsRecord + 9) == '\0') goto LAB_000d3be0;
          dumpLabelArg = (uint)*(ushort *)(rsRecord + 1);
          argR7 = (uint)*(byte *)(rsRecord + 2);
          dumpIdArg = (uint *)((*(byte *)((int)rsRecord + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
          if (*(char *)(rsRecord + 3) == '\0') goto LAB_000d3be0;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
        }
        rsRecordNumber = rsRecordNumber + 1;
        if (*rsScanRecord != 1) break;
        rsScanRecord = rsScanRecord + 0x12;
        rsNextRecord = rsNextRecordCopy + 0x12;
        rsRecord = rsNextRecordCopy;
      } while (rsRecordNumber <= recordCount);
    }
    else {
      rsRecordNumber = 1;
    }
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",dumpLabelArg,dumpIdArg,argR7,argR8,argR9,argR10);
    if (rsRecordNumber <= recordCount) {
      levelNumber = 0;
      instructionRecord = pixelShader + rsRecordNumber * 0x12;
      previousIsAlu = 1;
      aluNumber = (uint *)0x0;
      texNumber = 0;
      usListStaleZero = 0;
      do {
        recordKind = *instructionRecord;
        if (((recordKind == 2) && ((previousIsAlu != 0 || (*(char *)(instructionRecord + 8) != '\0')))) ||
           (levelNumber == 0)) {
          if (levelNumber < 0x34) {
            (*(unsigned short *)((unsigned char *)&(predicateText) + 1)) = (ushort)(*(unsigned int *)((unsigned char *)&(predicateText) + 0)) & 0xff;
          }
          else {
            (*(unsigned short *)((unsigned char *)&(predicateText) + 1)) = (ushort)(byte)((char)(levelNumber / 0x34) + 0x2f) << 8;
          }
          levelLetter = (char)(levelNumber % 0x34);
          if (levelNumber % 0x34 < 0x1a) {
            levelLetter = levelLetter + 'A';
          }
          else {
            levelLetter = levelLetter + 'G';
          }
          (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(levelLetter,(*(unsigned short *)((unsigned char *)&(predicateText) + 1)));
          ((int (*)())FUN_000d03b4)(0," \n   Level %s:\n",&predicateText,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          levelNumber = levelNumber + 1;
          recordKind = *instructionRecord;
        }
        previousIsAlu = (uint)(recordKind - 3 < 2);
        if (recordKind == 2) {
          ((int (*)())FUN_000d03b4)(0,"     tex %02d    :  ",texNumber,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          texSrcReg = (uint)*(ushort *)((int)instructionRecord + 0xe);
          texDestReg = (uint)*(ushort *)(instructionRecord + 3);
          texUnit = (uint)*(byte *)((int)instructionRecord + 0x19);
          if ((*(byte *)((int)instructionRecord + 0x1a) < 5) &&
             ((1 << ((int)(char)*(byte *)((int)instructionRecord + 0x1a) & 0x3fU) & 0x1aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.rgba = ",texDestReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
          }
          texOpcode = (uint *)(uint)*(byte *)((int)instructionRecord + 0x1a);
          dumpIdArg = (uint *)(*(byte *)((int)instructionRecord + 0x1f) & 0xf ^ 0xf);
          if (((unsigned char *)0x4) < texOpcode) {
            ((int (*)())FUN_000d03b4)(0,"???()\n",texDestReg,dumpIdArg,usListStaleZero,argR8,texOpcode,argR10);
            argR9 = (char *)texOpcode;
          }
          else {
            argR9 = (char *)(0);
            switch((int)texOpcode) {
            case 0x0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",texDestReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
              break;
            case 0x1:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,argR9,
                           argR10);
              break;
            case 0x2:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"kill(r%02d.%s)\n",texSrcReg,dumpIdArg,usListStaleZero,argR8,argR9,argR10);
              break;
            case 0x3:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,
                           argR9,argR10);
              break;
            case 0x4:
              dumpIdArg = (uint *)((int)dumpIdArg * 5 + 0x1dc279);
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(r%02d.%s, tex%02d)\n",texSrcReg,dumpIdArg,texUnit,argR8,
                           argR9,argR10);
            }
          }
          texNumber = texNumber + 1;
        }
        else if ((1 < recordKind) && (recordKind < 5)) {
          rgbOpcodePtr2 = (byte *)((int)instructionRecord + 0x31);
          switch(*(undefined1 *)((int)instructionRecord + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 3;
            rgbThirdOperandUsed = 1;
            break;
          case 1:
          case 4:
          case 5:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 1;
            rgbThirdOperandUsed = 0;
            break;
          case 2:
            alphaOperandUseMask = 3;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 1;
            rgbThirdOperandUsed = 0;
            break;
          default:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = false;
            rgbOperandUseMask = 0;
            rgbThirdOperandUsed = 0;
            break;
          case 9:
            alphaOperandUseMask = 0;
            alphaSrcpNeededFmt1 = true;
            rgbOperandUseMask = 0;
            rgbThirdOperandUsed = 0;
          }
          alphaOpcodePtr2 = instructionRecord + 0x10;
          if (*(byte *)(instructionRecord + 0x10) < 0xc) {
            alphaOpcodeBit = 1 << ((int)(char)*(byte *)(instructionRecord + 0x10) & 0x3fU);
            if ((alphaOpcodeBit & 0x61) == 0) {
              if ((alphaOpcodeBit & 0xc) == 0) {
                if ((alphaOpcodeBit & 0xf80) != 0) {
                  alphaOperandUseMask = alphaOperandUseMask | 1;
                }
              }
              else {
                alphaOperandUseMask = 3;
              }
            }
            else {
              alphaOperandUseMask = 7;
            }
          }
          alphaSelectC2 = (byte *)(uint)*(byte *)((int)instructionRecord + 0x3b);
          rgbAddrA2 = (uint)*(ushort *)((int)instructionRecord + 0xe);
          rgbAddrBFmt1 = (uint *)(uint)*(ushort *)(instructionRecord + 4);
          rgbAddrCFmt1 = (uint *)(uint)*(ushort *)((int)instructionRecord + 0x12);
          alphaAddrAFmt1 = (uint *)(uint)*(ushort *)((int)instructionRecord + 0x1a);
          argR8 = (uint *)(uint)*(ushort *)(instructionRecord + 7);
          argR9 = (char *)(uint)*(ushort *)((int)instructionRecord + 0x1e);
          uVar30 = (uint)*(byte *)((int)instructionRecord + 0x2a);
          rgbSelectB = (uint)*(byte *)((int)instructionRecord + 0x2b);
          rgbSelectCRawFmt1 = (uint)*(byte *)(instructionRecord + 0xb);
          alphaSelectA = (uint)*(byte *)((int)instructionRecord + 0x39);
          alphaSelectB2 = (uint)*(byte *)((int)instructionRecord + 0x3a);
          rgbModA = (uint)*(byte *)((int)instructionRecord + 0x2d);
          rgbModB = (uint)*(byte *)((int)instructionRecord + 0x2e);
          rgbModC = (uint)*(byte *)((int)instructionRecord + 0x2f);
          alphaModA = (uint)*(byte *)(instructionRecord + 0xf);
          alphaModB = (uint)*(byte *)((int)instructionRecord + 0x3d);
          alphaModC = (uint)*(byte *)((int)instructionRecord + 0x3e);
          if (alphaSrcpNeededFmt1) {
            rgbSrcpNeeded = (uint)(uVar30 - 0xf < 4);
          }
          else {
            rgbSrcpNeeded = 0;
          }
          alphaSrcpNeededFmt1 = alphaSrcpNeededFmt1 && uVar30 == 0x13;
          rgbOperandUseMask = rgbOperandUseMask & 1;
          if (rgbOperandUseMask != 0) {
            rgbSrcpNeeded = rgbSrcpNeeded | rgbSelectB - 0xf < 4;
            alphaSrcpNeededFmt1 = alphaSrcpNeededFmt1 || rgbSelectB == 0x13;
          }
          if (rgbThirdOperandUsed != 0) {
            rgbOperandUseMask = -(rgbSelectCRawFmt1 ^ 0x13);
            rgbSrcpNeeded = rgbSrcpNeeded | rgbSelectCRawFmt1 - 0xf < 4;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (rgbSelectCRawFmt1 ^ 0x13) == 0);
          }
          if ((alphaOperandUseMask & 1) != 0) {
            rgbOperandUseMask = -(alphaSelectA ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectA - 0xc < 3;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (alphaSelectA ^ 0xf) == 0);
          }
          if ((alphaOperandUseMask & 2) != 0) {
            rgbOperandUseMask = -(alphaSelectB2 ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectB2 - 0xc < 3;
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | (alphaSelectB2 ^ 0xf) == 0);
          }
          if ((alphaOperandUseMask & 4) != 0) {
            rgbOperandUseMask = -((uint)alphaSelectC2 ^ 0xf);
            rgbSrcpNeeded = rgbSrcpNeeded | alphaSelectC2 + -0xc < (byte *)((int)((unsigned char *)0x0) + 3);
            alphaSrcpNeededFmt1 = (bool)(alphaSrcpNeededFmt1 | ((uint)alphaSelectC2 ^ 0xf) == 0);
          }
          srcpTextAPtr = dumpIdArg;
          if (rgbSrcpNeeded != 0) {
            aluNumberArg = aluNumber;
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.rgb = ",aluNumber,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,
                         rgbThirdOperandUsed);
            rgbPreOpKind = *(char *)(instructionRecord + 0xc);
            if (rgbPreOpKind == '\x01') {
              srcpTextAPtr = &srcpTextA;
              ((int (*)())FUN_000d0450)(srcpTextAPtr,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d0450)(&srcpTextB,rgbAddrBFmt1,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&srcpTextB,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (rgbPreOpKind == '\0') {
              ((int (*)())FUN_000d0450)(&srcpTextA,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&srcpTextA,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
            else if (rgbPreOpKind == '\x02') {
              srcpTextAPtr = &srcpTextA;
              ((int (*)())FUN_000d0450)(srcpTextAPtr,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d0450)(&srcpTextB,rgbAddrBFmt1,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&srcpTextB,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (rgbPreOpKind == '\x03') {
              ((int (*)())FUN_000d0450)(&srcpTextA,rgbAddrA2,aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&srcpTextA,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",aluNumberArg,dumpIdArg,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              srcpTextAPtr = dumpIdArg;
            }
          }
          alphaSrcpTextPtr = srcpTextAPtr;
          if (alphaSrcpNeededFmt1) {
            aluNumberArg = aluNumber;
            ((int (*)())FUN_000d03b4)(0,"     alu %02d pre:  srcp.a   = ",aluNumber,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,
                         rgbThirdOperandUsed);
            alphaPreOp = *(char *)((int)instructionRecord + 0x3f);
            if (alphaPreOp == '\x01') {
              alphaSrcpTextPtr = &srcpTextA;
              ((int (*)())FUN_000d0450)(alphaSrcpTextPtr,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d0450)(&srcpTextB,argR8,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&srcpTextB,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (alphaPreOp == '\0') {
              ((int (*)())FUN_000d0450)(&srcpTextA,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&srcpTextA,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
            else if (alphaPreOp == '\x02') {
              alphaSrcpTextPtr = &srcpTextA;
              ((int (*)())FUN_000d0450)(alphaSrcpTextPtr,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d0450)(&srcpTextB,argR8,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&srcpTextB,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
            }
            else if (alphaPreOp == '\x03') {
              ((int (*)())FUN_000d0450)(&srcpTextA,alphaAddrAFmt1,aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&srcpTextA,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",aluNumberArg,srcpTextAPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
              alphaSrcpTextPtr = srcpTextAPtr;
            }
          }
          rgbOutIndexArg = aluNumber;
          ((int (*)())FUN_000d03b4)(0,"     alu %02d rgb:  ",aluNumber,alphaSrcpTextPtr,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          rgbOutputMaskText = (uint)*(byte *)((int)instructionRecord + 0x15);
          rgbTempWriteMask = *(byte *)(instructionRecord + 5);
          if (rgbOutputMaskText == 0) {
            ((int (*)())FUN_000d03b4)(0,"           ",rgbOutIndexArg,0,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          else {
            rgbOutIndexArg = (uint *)(uint)*(byte *)((int)instructionRecord + 0x16);
            rgbOutputMaskText = rgbOutputMaskText * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          if (rgbTempWriteMask == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          else {
            rgbOutIndexArg = (uint *)(uint)*(ushort *)(instructionRecord + 3);
            rgbOutputMaskText = (uint)rgbTempWriteMask * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          if (*(char *)((int)instructionRecord + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",rgbOutIndexArg,rgbOutputMaskText,rgbOperandUseMask,alphaOperandUseMask,rgbSrcpNeeded,rgbThirdOperandUsed);
          }
          operandText2Ptr = operandText2;
          operandText3Ptr = operandText3;
          ((int (*)())FUN_000d0488)(operandText2Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,uVar30,rgbModA);
          operandText4Ptr = operandText4;
          operandText5PtrFmt1 = operandText5;
          ((int (*)())FUN_000d0488)(operandText3Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,rgbSelectB,rgbModB);
          ((int (*)())FUN_000d0488)(operandText4Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,rgbSelectCRawFmt1,rgbModC);
          dumpIdArg = operandText6;
          ((int (*)())FUN_000d0888)(operandText5PtrFmt1,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectA,alphaModA);
          operandText0Ptr = operandText0;
          ((int (*)())FUN_000d0888)(dumpIdArg,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectB2,alphaModB);
          argR10 = alphaSelectC2;
          ((int (*)())FUN_000d0888)(operandText0Ptr,rgbAddrA2,rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,alphaSelectC2,alphaModC);
          rgbOpcodeByte = *rgbOpcodePtr2;
          if (rgbOpcodeByte < 0xb) {
            argR9 = (char *)(0);
            switch(rgbOpcodeByte) {
            case 0:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 1:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 2:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText5PtrFmt1;
              alphaAddrAFmt1 = operandText3Ptr;
              argR8 = dumpIdArg;
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",operandText2Ptr,operandText5PtrFmt1,operandText3Ptr,dumpIdArg,argR9,argR10);
              break;
            case 3:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 4:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 5:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",operandText2Ptr,operandText3Ptr,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 6:
              goto switchD_000d4578_caseD_6;
            case 7:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 8:
              rgbAddrBFmt1 = operandText2Ptr;
              rgbAddrCFmt1 = operandText3Ptr;
              alphaAddrAFmt1 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",operandText2Ptr,operandText3Ptr,operandText4Ptr,argR8,argR9,argR10);
              break;
            case 9:
              rgbAddrBFmt1 = operandText2Ptr;
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",operandText2Ptr,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            }
          }
          else {
switchD_000d4578_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          rgbOutputScaleByte = *(byte *)((int)instructionRecord + 0x32);
          if (rgbOutputScaleByte < 7) {
            argR9 = (char *)(0);
            switch(rgbOutputScaleByte) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",rgbAddrBFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          alphaOutIndexArg = aluNumber;
          ((int (*)())FUN_000d03b4)(0,"          alpha:  ",aluNumber,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          alphaTempEnable = *(char *)(instructionRecord + 8);
          alphaOutputEnableFlag = *(char *)((int)instructionRecord + 0x21) != '\0';
          depthWrite = *(char *)((int)instructionRecord + 0x23);
          if (alphaOutputEnableFlag) {
            alphaOutIndexArg = (uint *)(uint)*(byte *)((int)instructionRecord + 0x22);
            ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          depthWriteFlag = depthWrite != '\0';
          if (depthWriteFlag) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if ((!alphaOutputEnableFlag) && (!depthWriteFlag)) {
            ((int (*)())FUN_000d03b4)(0,"           ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if (alphaTempEnable == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          else {
            alphaOutIndexArg = (uint *)(uint)*(ushort *)(instructionRecord + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
          }
          alphaOpcodeByte = *(byte *)alphaOpcodePtr2;
          if (alphaOpcodeByte < 0xc) {
            argR9 = (char *)(0);
            switch(alphaOpcodeByte) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText5PtrFmt1 = alphaOutIndexArg;
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",operandText5PtrFmt1,dumpIdArg,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",operandText5PtrFmt1,dumpIdArg,alphaAddrAFmt1,argR8,argR9,argR10);
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 4:
              goto switchD_000d489c_caseD_4;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",operandText5PtrFmt1,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
              dumpIdArg = rgbAddrCFmt1;
              operandText0Ptr = alphaAddrAFmt1;
            }
          }
          else {
switchD_000d489c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",alphaOutIndexArg,rgbAddrCFmt1,alphaAddrAFmt1,argR8,argR9,argR10);
            operandText5PtrFmt1 = alphaOutIndexArg;
            dumpIdArg = rgbAddrCFmt1;
            operandText0Ptr = alphaAddrAFmt1;
          }
          alphaOutputScaleByte = *(byte *)((int)instructionRecord + 0x41);
          if (alphaOutputScaleByte < 7) {
            argR9 = (char *)(0);
            switch(alphaOutputScaleByte) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???\n",operandText5PtrFmt1,dumpIdArg,operandText0Ptr,argR8,argR9,argR10);
          }
          if (*(char *)(instructionRecord + 0xd) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"     alu %02d post-NOP\n",aluNumber,dumpIdArg,operandText0Ptr,argR8,argR9,
                         argR10);
          }
          aluNumber = (uint *)((int)aluNumber + 1);
        }
        rsRecordNumber = rsRecordNumber + 1;
        instructionRecord = instructionRecord + 0x12;
        argR7 = recordCount;
        usListStaleZero = recordCount;
      } while (rsRecordNumber <= recordCount);
    }
    psnRecordIndex = 0;
    ((int (*)())FUN_000d03b4)(0,"======== End   Loki NSF pixel shader dump: %s: %d ========\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    psnRecordCount = pixelShader[2];
    psnLineArg0 = dumpLabelSlot;
    psnLineArg1 = dumpIdSlot;
    ((int (*)())FUN_000d03b4)(0,"+++ BEGIN_PSN                       # \"%s\" %d\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
    do {
      psnRecordKind = *pixelShader;
      if (psnRecordKind < 5) {
        switch(psnRecordKind) {
        case 0:
          psnLineArg0 = pixelShader[1];
          psnLineArg1 = (uint *)pixelShader[2];
          argR7 = (uint)*(byte *)(pixelShader + 3);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0xd);
          argR9 = (char *)(uint)*(ushort *)(pixelShader + 5);
          argR10 = (byte *)(uint)*(ushort *)((int)pixelShader + 0x16);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_HEADER : %08x %08x %02x %02x %04x %04x %04x %04x %04x %04x %04x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
          break;
        case 1:
          psnLineArg0 = (uint)*(ushort *)(pixelShader + 1);
          psnLineArg1 = (uint *)(uint)*(ushort *)((int)pixelShader + 6);
          argR7 = (uint)*(byte *)(pixelShader + 2);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 9);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 10);
          argR10 = (byte *)(uint)*(byte *)((int)pixelShader + 0xb);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ R300PSN_INST_RS     : %04x %04x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
          break;
        case 2:
          psnLineArg0 = (uint)*(ushort *)(pixelShader + 3);
          psnLineArg1 = (uint *)(uint)*(ushort *)((int)pixelShader + 0xe);
          argR7 = (uint)*(byte *)((int)pixelShader + 0x19);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0x1a);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 0x1f);
          argR10 = (byte *)(uint)*(byte *)(pixelShader + 8);
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_TEX    : %04x %04x %02x %02x %02x %02x\n",psnLineArg0,psnLineArg1,
                       argR7,argR8,argR9,argR10);
          break;
        default:
          ((int (*)())FUN_000d03b4)(0,"+++ R300PSN_INST_ALU    : \n",psnLineArg0,psnLineArg1,argR7,argR8,
                       0,argR10);
          ((int (*)())FUN_000d03b4)(0,"+++ RGB_ADDR            : %04x %04x %04x %04x %02x %02x %02x\n",
                       (uint)*(ushort *)(pixelShader + 3),(uint)*(ushort *)((int)pixelShader + 0xe),
                       (uint)*(ushort *)(pixelShader + 4),(uint)*(ushort *)((int)pixelShader + 0x12),
                       (uint)*(byte *)(pixelShader + 5),(uint)*(byte *)((int)pixelShader + 0x15));
          ((int (*)())FUN_000d03b4)(0,"+++ ALPHA_ADDR          : %04x %04x %04x %04x %02x %02x %02x %02x\n",
                       (uint)*(ushort *)(pixelShader + 6),(uint)*(ushort *)((int)pixelShader + 0x1a),
                       (uint)*(ushort *)(pixelShader + 7),(uint)*(ushort *)((int)pixelShader + 0x1e),
                       (uint)*(byte *)(pixelShader + 8),(uint)*(byte *)((int)pixelShader + 0x21));
          ((int (*)())FUN_000d03b4)(0,
                       "+++ RGB_INST            : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,(uint)*(byte *)((int)pixelShader + 0x2a),(uint)*(byte *)((int)pixelShader + 0x2d),
                       (uint)*(byte *)((int)pixelShader + 0x2b),(uint)*(byte *)((int)pixelShader + 0x2e),
                       (uint)*(byte *)(pixelShader + 0xb),(uint)*(byte *)((int)pixelShader + 0x2f));
          psnLineArg0 = (uint)*(byte *)((int)pixelShader + 0x39);
          psnLineArg1 = (uint *)(uint)*(byte *)(pixelShader + 0xf);
          argR7 = (uint)*(byte *)((int)pixelShader + 0x3a);
          argR8 = (uint *)(uint)*(byte *)((int)pixelShader + 0x3d);
          argR9 = (char *)(uint)*(byte *)((int)pixelShader + 0x3b);
          argR10 = (byte *)(uint)*(byte *)((int)pixelShader + 0x3e);
          ((int (*)())FUN_000d03b4)(0,
                       "+++ ALPHA_INST          : %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n"
                       ,psnLineArg0,psnLineArg1,argR7,argR8,argR9,argR10);
        }
      }
      psnRecordIndex = psnRecordIndex + 1;
      pixelShader = pixelShader + 0x12;
    } while (psnRecordIndex <= psnRecordCount);
    ((int (*)())FUN_000d03b4)(0,"+++ END_PSN                         # \"%s\" %d\n",dumpLabelSlot,
                 dumpIdSlot,argR7,argR8,argR9,argR10);
  }
  else {
    neutralRecordCountArg = pixelShader[2];
    neutralLineArg0 = dumpIdSlot;
    recordCount2 = neutralRecordCountArg;
    ((int (*)())FUN_000d03b4)(0,"======== Begin r520 neutral format pixel shader: %d =============\n",
                 dumpIdSlot,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if (*(short *)(pixelShader + 5) == 0) {
      ((int (*)())FUN_000d03b4)(0," Shader stats not valid\n \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    }
    else {
      ((int (*)())FUN_000d03b4)(0," Shader stats:\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     RS Instructions:        %2d\n",(uint)*(ushort *)(pixelShader + 6),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     TEX Instructions:      %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1a),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instructions:      %3d\n",(uint)*(ushort *)(pixelShader + 7),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     ALU Instruction slots: %3d\n",(uint)*(ushort *)((int)pixelShader + 0x1e),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      if (*(byte *)((int)pixelShader + 0xe) != 0) {
        ((int (*)())FUN_000d03b4)(0,"     UMRT_EN:               %3d\n",(uint)*(byte *)((int)pixelShader + 0xe),
                     argR6,neutralRecordCountArg,argR8,argR9,argR10);
      }
      ((int (*)())FUN_000d03b4)(0,"     CF Instructions:       %3d\n",(uint)*(ushort *)(pixelShader + 8),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Pix Size:               %2d\n",(uint)*(ushort *)((int)pixelShader + 0x22),
                   argR6,neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Highest Const:          %2d\n",(uint)*(ushort *)(pixelShader + 9),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      ((int (*)())FUN_000d03b4)(0,"     Start Addr:            %3d\n",(uint)*(ushort *)(pixelShader + 4),argR6,
                   neutralRecordCountArg,argR8,argR9,argR10);
      neutralLineArg0 = (uint *)(uint)*(ushort *)((int)pixelShader + 0x12);
      ((int (*)())FUN_000d03b4)(0,"     End Addr:              %3d\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,
                   argR10);
      ((int (*)())FUN_000d03b4)(0," \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    }
    ((int (*)())FUN_000d03b4)(0," RS Instructions:\n \n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if ((pixelShader[0x12] == 1) && (0 < (int)recordCount2)) {
      rsScanRecord2 = pixelShader + 0x24;
      rsRecordNumber2 = 1;
      rsNextRecord2 = rsScanRecord2;
      rsRecord2 = pixelShader + 0x12;
      do {
        rsNextRecordCopy2 = rsNextRecord2;
        neutralLineArg0 = (uint *)(rsRecordNumber2 + -1);
        ((int (*)())FUN_000d03b4)(0,"   rs %02d:",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        rsColorSource = *(char *)((int)rsRecord2 + 0xb);
        if (rsColorSource == '\0') {
          if (*(char *)((int)rsRecord2 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"                         ",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,
                         argR10);
            goto LAB_000d1afc;
          }
LAB_000d1b5c:
          ((int (*)())FUN_000d03b4)(0,"\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        }
        else {
          rsColorWriteMask = *(byte *)((int)rsRecord2 + 0xf) & 0xf ^ 0xf;
          if (rsColorSource == '\x01') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            neutralRecordCountArg = (uint)*(byte *)((int)rsRecord2 + 10);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = col%02ld",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
            if (*(char *)((int)rsRecord2 + 0xd) == '\0') {
              rsColorSource = *(char *)((int)rsRecord2 + 0xb);
            }
            else {
              ((int (*)())FUN_000d03b4)(0," biased",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
              rsColorSource = *(char *)((int)rsRecord2 + 0xb);
            }
          }
          if (rsColorSource == '\x02') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = fbuf",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
          else if (rsColorSource == '\x03') {
            neutralLineArg0 = (uint *)(uint)*(ushort *)((int)rsRecord2 + 6);
            argR6 = (char *)(rsColorWriteMask * 5 + 0x1dc279);
            ((int (*)())FUN_000d03b4)(0,"  r%02d.%s = back",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
          else {
            if (*(char *)((int)rsRecord2 + 9) == '\0') goto LAB_000d1b5c;
            ((int (*)())FUN_000d03b4)(0,"       ",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          }
LAB_000d1afc:
          if (*(char *)((int)rsRecord2 + 9) == '\0') goto LAB_000d1b5c;
          neutralLineArg0 = (uint *)(uint)*(ushort *)(rsRecord2 + 1);
          neutralRecordCountArg = (uint)*(byte *)(rsRecord2 + 2);
          argR6 = (char *)((*(byte *)((int)rsRecord2 + 0xe) & 0xf ^ 0xf) * 5 + 0x1dc279);
          ((int (*)())FUN_000d03b4)(0,"   r%02d.%s = txc%02ld",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
          if (*(char *)(rsRecord2 + 3) == '\0') goto LAB_000d1b5c;
          ((int (*)())FUN_000d03b4)(0," adjusted\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
        }
        rsRecordNumber2 = rsRecordNumber2 + 1;
        if (*rsScanRecord2 != 1) break;
        rsScanRecord2 = rsScanRecord2 + 0x12;
        rsNextRecord2 = rsNextRecordCopy2 + 0x12;
        rsRecord2 = rsNextRecordCopy2;
      } while (rsRecordNumber2 <= (int)recordCount2);
    }
    else {
      rsRecordNumber2 = 1;
    }
    blankLineFormatOffset = 0x1a1848;
    ((int (*)())FUN_000d03b4)(0," \n US Program:\n",neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    ((int (*)())FUN_000d03b4)(0,blankLineFormatOffset + 0x5b00,neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    if (rsRecordNumber2 <= (int)recordCount2) {
      texFlagsByte = 0;
      instructionRecord2 = pixelShader + rsRecordNumber2 * 0x12;
      instructionNumber = 0;
      aluIndex = (uint *)0x0;
      texIndex = 0;
      cfIndex = 0;
      cfPrevAluDest = 0;
      cfCompareCode = 0;
      do {
        if (*(char *)(instructionRecord2 + 7) == '\0') {
          ignUncText = ignUncText & 0xffffff;
        }
        else {
          argR9 = " ign_unc";
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 0)) = s_ign_unc_001a734c[0];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 1)) = s_ign_unc_001a734c[1];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 2)) = s_ign_unc_001a734c[2];
          (*(unsigned char *)((unsigned char *)&(ignUncText) + 3)) = s_ign_unc_001a734c[3];
          ignUncText4[0] = s_ign_unc_001a734c[4];
          ignUncText4[1] = s_ign_unc_001a734c[5];
          ignUncText4[2] = s_ign_unc_001a734c[6];
          ignUncText4[3] = s_ign_unc_001a734c[7];
          ignUncText8 = s_ign_unc_001a734c[8];
        }
        if (*(char *)(instructionRecord2 + 1) == '\0') {
          semWaitText = semWaitText & 0xffffff;
        }
        else {
          argR9 = " sem_wait";
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 0)) = s_sem_wait_001a7358[0];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 1)) = s_sem_wait_001a7358[1];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 2)) = s_sem_wait_001a7358[2];
          (*(unsigned char *)((unsigned char *)&(semWaitText) + 3)) = s_sem_wait_001a7358[3];
          semWaitText4[0] = s_sem_wait_001a7358[4];
          semWaitText4[1] = s_sem_wait_001a7358[5];
          semWaitText4[2] = s_sem_wait_001a7358[6];
          semWaitText4[3] = s_sem_wait_001a7358[7];
          semWaitText8[0] = s_sem_wait_001a7358[8];
          semWaitText8[1] = s_sem_wait_001a7358[9];
        }
        if (*(char *)((int)instructionRecord2 + 0xb) == '\0') {
          aluWaitText = aluWaitText & 0xffffff;
        }
        else {
          argR9 = " alu_wait";
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 0)) = s_alu_wait_001a7364[0];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 1)) = s_alu_wait_001a7364[1];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 2)) = s_alu_wait_001a7364[2];
          (*(unsigned char *)((unsigned char *)&(aluWaitText) + 3)) = s_alu_wait_001a7364[3];
          aluWaitText4[0] = s_alu_wait_001a7364[4];
          aluWaitText4[1] = s_alu_wait_001a7364[5];
          aluWaitText4[2] = s_alu_wait_001a7364[6];
          aluWaitText4[3] = s_alu_wait_001a7364[7];
          aluWaitText8[0] = s_alu_wait_001a7364[8];
          aluWaitText8[1] = s_alu_wait_001a7364[9];
        }
        recordKind2 = *instructionRecord2;
        if (recordKind2 == 2) {
          ((int (*)())FUN_000d03b4)(0,"  %d tex %02d    :  ",instructionNumber,texIndex,neutralRecordCountArg,argR8,argR9,argR10);
          texEnableBits = *(byte *)((int)instructionRecord2 + 0x1d);
          texSrcReg2 = *(ushort *)((int)instructionRecord2 + 0xe);
          neutralLineArg0 = (uint *)(uint)texSrcReg2;
          texDestReg2 = *(ushort *)(instructionRecord2 + 3);
          texComponentEnableBits = (*(byte *)((int)instructionRecord2 + 0x1e) & 0x1f) << 3 | (uint)texEnableBits;
          texUnit2 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x19);
          texEnableR = (texEnableBits & 1) != 0;
          texWriteMask = *(byte *)(instructionRecord2 + 5);
          if (texEnableR) {
            maskTextX = (char *)((texWriteMask >> 4 & 0xc) + 0x1dc259);
          }
          else {
            maskTextX = "_";
          }
          texEnableG = (texEnableBits & 2) != 0;
          if (texEnableG) {
            maskTextY = (char *)((texWriteMask >> 2 & 0xc) + 0x1dc259);
          }
          else {
            maskTextY = "_";
          }
          texEnableB = (texEnableBits & 4) != 0;
          if (texEnableB) {
            maskTextZ = (char *)((texWriteMask & 0xc) + 0x1dc259);
          }
          else {
            maskTextZ = "_";
          }
          texEnableA = (texComponentEnableBits >> 3 & 1) != 0;
          if (texEnableA) {
            maskTextW = (char *)((texWriteMask & 3) * 4 + 0x1dc259);
          }
          else {
            maskTextW = "_";
          }
          FUN_001a32d0(writeMaskText,"%s%s%s%s",maskTextX,maskTextY,maskTextZ,maskTextW,texComponentEnableBits,argR10);
          if ((*(byte *)((int)instructionRecord2 + 0x1a) < 7) &&
             ((1 << ((int)(char)*(byte *)((int)instructionRecord2 + 0x1a) & 0x3fU) & 0x7aU) != 0)) {
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",(uint)texDestReg2,writeMaskText,maskTextZ,maskTextW,texComponentEnableBits,argR10);
          }
          if (*(byte *)((int)instructionRecord2 + 0x1a) == 2) {
            texSrcSwizzleByte = *(byte *)((int)instructionRecord2 + 0x15);
            argR9 = (char *)(uint)texSrcSwizzleByte;
            if (texEnableR) {
              srcSwizzleTextX = (char *)((texSrcSwizzleByte >> 4 & 0xc) + 0x1dc259);
            }
            else {
              srcSwizzleTextX = "-";
            }
            if (texEnableG) {
              argR6 = (char *)((texSrcSwizzleByte >> 2 & 0xc) + 0x1dc259);
            }
            else {
              argR6 = "-";
            }
            if (texEnableB) {
              srcSwizzleTextZ = (char *)((texSrcSwizzleByte & 0xc) + 0x1dc259);
            }
            else {
              srcSwizzleTextZ = "-";
            }
            if (texEnableA) {
              argR8 = (uint *)(((uint)argR9 & 3) * 4 + 0x1dc259);
            }
            else {
              argR8 = (uint *)"-";
            }
          }
          else {
            texFlagsByte = (uint)*(byte *)((int)instructionRecord2 + 0x1f);
            texSrcSwizzleByte2 = *(byte *)((int)instructionRecord2 + 0x15);
            argR9 = (char *)(uint)texSrcSwizzleByte2;
            if ((*(byte *)((int)instructionRecord2 + 0x1f) & 1) == 0) {
              argR10 = (byte *)(texSrcSwizzleByte2 & 0xc);
              argR9 = (char *)(((uint)argR9 & 3) * 4);
              argR8 = (uint *)((int)argR9 + 0x1dc259);
              srcSwizzleTextX = (char *)((texSrcSwizzleByte2 >> 4 & 0xc) + 0x1dc259);
              argR6 = (char *)((texSrcSwizzleByte2 >> 2 & 0xc) + 0x1dc259);
              srcSwizzleTextZ = (char *)(argR10 + 0x1dc259);
            }
            else {
              srcSwizzleTextX = "-";
              argR6 = srcSwizzleTextX;
              srcSwizzleTextZ = srcSwizzleTextX;
              argR8 = (uint *)srcSwizzleTextX;
            }
          }
          srcSwizzleTextPtr = srcSwizzleText;
          FUN_001a32d0(srcSwizzleTextPtr,"%s%s%s%s",srcSwizzleTextX,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          if ((texSrcReg2 & 0x4000) == 0) {
            FUN_001a32d0(registerText,"r%02d",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          else {
            neutralLineArg0 = (uint *)((uint)neutralLineArg0 & 0xbfff);
            FUN_001a32d0(registerText,"r[AL+%02d]",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          registerTextPtr = registerText;
          if (*(char *)((int)instructionRecord2 + 0x1b) == '\0') {
            semGrabText = semGrabText & 0xffffff;
          }
          else {
            argR9 = " sem_grab";
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 0)) = s_sem_grab_001a73ac[0];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 1)) = s_sem_grab_001a73ac[1];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 2)) = s_sem_grab_001a73ac[2];
            (*(unsigned char *)((unsigned char *)&(semGrabText) + 3)) = s_sem_grab_001a73ac[3];
            semGrabText4[0] = s_sem_grab_001a73ac[4];
            semGrabText4[1] = s_sem_grab_001a73ac[5];
            semGrabText4[2] = s_sem_grab_001a73ac[6];
            semGrabText4[3] = s_sem_grab_001a73ac[7];
            semGrabText8[0] = s_sem_grab_001a73ac[8];
            semGrabText8[1] = s_sem_grab_001a73ac[9];
          }
          texOpcodeByte = *(byte *)((int)instructionRecord2 + 0x1a);
          if (texOpcodeByte < 8) {
            argR9 = (char *)(0);
            switch(texOpcodeByte) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"NOP\n",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
              break;
            case 1:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())FUN_000d03b4)(0,"lookup(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 2:
              srcSwizzleTextZ = (char *)&semWaitText;
              argR8 = &semGrabText;
              argR9 = (char *)&aluWaitText;
              ((int (*)())FUN_000d03b4)(0,"kill(%s.%s)%s%s%s",registerTextPtr,srcSwizzleTextPtr,srcSwizzleTextZ,argR8,argR9,argR10);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              break;
            case 3:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())FUN_000d03b4)(0,"lookup_proj(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 4:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())FUN_000d03b4)(0,"lookup_lodbias(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,
                           argR8,argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 5:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())FUN_000d03b4)(0,"lookup_lod(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,argR8,
                           argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
              break;
            case 6:
              texDxSwizzleByte = *(byte *)((int)instructionRecord2 + 0x16);
              dxSwizzleWOffset = (uint)texDxSwizzleByte;
              texSwizzleEnabled = (texFlagsByte & 1) == 0;
              if (texSwizzleEnabled) {
                argR10 = (byte *)(texDxSwizzleByte & 0xc);
                dxSwizzleWOffset = (dxSwizzleWOffset & 3) * 4;
                dxSwizzleTextW = (char *)(dxSwizzleWOffset + 0x1dc259);
                dxSwizzleTextX = (char *)((texDxSwizzleByte >> 4 & 0xc) + 0x1dc259);
                dxSwizzleTextY = (char *)((texDxSwizzleByte >> 2 & 0xc) + 0x1dc259);
                dxSwizzleTextZ = argR10 + 0x1dc259;
              }
              else {
                dxSwizzleTextX = "-";
                dxSwizzleTextY = dxSwizzleTextX;
                dxSwizzleTextZ = (byte *)dxSwizzleTextX;
                dxSwizzleTextW = dxSwizzleTextX;
              }
              argR8 = dxSwizzleTextA;
              FUN_001a32d0(argR8,"%s%s%s%s",dxSwizzleTextX,dxSwizzleTextY,dxSwizzleTextZ,dxSwizzleTextW,dxSwizzleWOffset,argR10);
              texDySwizzleByte = *(byte *)((int)instructionRecord2 + 0x16);
              dySwizzleWOffset = (uint)texDySwizzleByte;
              srcSwizzleTextZ = (char *)(uint)*(ushort *)(instructionRecord2 + 4);
              if (texSwizzleEnabled) {
                argR10 = (byte *)(texDySwizzleByte & 0xc);
                dySwizzleWOffset = (dySwizzleWOffset & 3) * 4;
                dySwizzleTextW = (char *)(dySwizzleWOffset + 0x1dc259);
                dySwizzleTextX = (char *)((texDySwizzleByte >> 4 & 0xc) + 0x1dc259);
                dySwizzleTextY = (char *)((texDySwizzleByte >> 2 & 0xc) + 0x1dc259);
                dySwizzleTextZ = argR10 + 0x1dc259;
              }
              else {
                dySwizzleTextX = "-";
                dySwizzleTextY = dySwizzleTextX;
                dySwizzleTextZ = (byte *)dySwizzleTextX;
                dySwizzleTextW = dySwizzleTextX;
              }
              FUN_001a32d0(operandText0,"%s%s%s%s",dySwizzleTextX,dySwizzleTextY,dySwizzleTextZ,dySwizzleTextW,dySwizzleWOffset,argR10);
              argR9 = (char *)(uint)*(ushort *)((int)instructionRecord2 + 0x12);
              in_stack_fffffd2c = &semWaitText;
              ((int (*)())FUN_000d03b4)(0,"lookup_dxdy(%s.%s, r%02d.%s, r%02d.%s,  tex%02d)%s%s%s%s",registerTextPtr,
                           srcSwizzleTextPtr,srcSwizzleTextZ,argR8,argR9,operandText0);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              break;
            case 7:
              argR8 = &semWaitText;
              argR9 = (char *)&semGrabText;
              ((int (*)())FUN_000d03b4)(0,"lookup_uncached(%s.%s, tex%02d)%s%s%s%s",registerTextPtr,srcSwizzleTextPtr,texUnit2,
                           argR8,argR9,&aluWaitText);
              neutralLineArg0 = registerTextPtr;
              argR6 = (char *)srcSwizzleTextPtr;
              srcSwizzleTextZ = (char *)texUnit2;
            }
          }
          else {
            neutralLineArg0 = &semWaitText;
            argR6 = (char *)&semGrabText;
            srcSwizzleTextZ = (char *)&aluWaitText;
            argR8 = &ignUncText;
            ((int (*)())FUN_000d03b4)(0,"UNKNOWN_OP%s%s%s%s",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          predicateControlPtr = (byte *)((int)instructionRecord2 + 5);
          if (*(char *)((int)instructionRecord2 + 5) != '\0') {
            if (*(char *)((int)instructionRecord2 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByte = *predicateControlPtr;
            if (predicateModeByte < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByte) {
              case 1:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.rgb",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 2:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.rrr",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 3:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.ggg",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 4:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.bbb",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
                break;
              case 5:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.aaa",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,predicateControlPtr);
              }
            }
          }
          argR10 = (byte *)((int)instructionRecord2 + 7);
          if (*(char *)((int)instructionRecord2 + 7) != '\0') {
            if (*(char *)(instructionRecord2 + 2) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByteAlpha = *argR10;
            if (predicateModeByteAlpha < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByteAlpha) {
              case 0:
                break;
              default:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.a",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 2:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.r",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 3:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.g",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
                break;
              case 4:
                neutralLineArg0 = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.b",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
              }
            }
          }
          if (*(char *)((int)instructionRecord2 + 9) != '\0') {
            ((int (*)())FUN_000d03b4)(0," write_inactive",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          }
          ((int (*)())FUN_000d03b4)(0,"\n",neutralLineArg0,argR6,srcSwizzleTextZ,argR8,argR9,argR10);
          recordKind2 = *instructionRecord2;
          texIndex = texIndex + 1;
        }
        operandAuxHigh = (undefined2)((uint)in_stack_fffffd2c >> 0x10);
        if ((recordKind2 == 3) || (recordKind2 == 4)) {
          rgbOpcodePtr = (byte *)((int)instructionRecord2 + 0x31);
          cfPrevAluDest = (uint)*(byte *)((int)instructionRecord2 + 0x43);
          cfCompareCode = (uint)*(byte *)(instructionRecord2 + 0x11);
          switch(*(undefined1 *)((int)instructionRecord2 + 0x31)) {
          case 0:
          case 3:
          case 7:
          case 8:
            rgbOperandAUsed = true;
            rgbOperandBUsed = true;
            rgbOperandCUsed = true;
            alphaUseMaskNeutral = 0;
            break;
          case 1:
          case 4:
          case 5:
          case 0xb:
          case 0xc:
            rgbOperandAUsed = true;
            rgbOperandBUsed = true;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
            break;
          case 2:
            rgbOperandAUsed = true;
            alphaUseMaskNeutral = 3;
            rgbOperandBUsed = true;
            rgbOperandCUsed = false;
            break;
          default:
            rgbOperandAUsed = false;
            rgbOperandBUsed = false;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
            break;
          case 9:
            rgbOperandAUsed = true;
            rgbOperandBUsed = false;
            rgbOperandCUsed = false;
            alphaUseMaskNeutral = 0;
          }
          alphaOpcodePtr = instructionRecord2 + 0x10;
          if (*(byte *)(instructionRecord2 + 0x10) < 0x10) {
            rgbOpcodeBit = 1 << ((int)(char)*(byte *)(instructionRecord2 + 0x10) & 0x3fU);
            if ((rgbOpcodeBit & 0x61) == 0) {
              if ((rgbOpcodeBit & 0xc00c) == 0) {
                if ((rgbOpcodeBit & 0x3f80) != 0) {
                  alphaUseMaskNeutral = alphaUseMaskNeutral | 1;
                }
              }
              else {
                alphaUseMaskNeutral = 3;
              }
            }
            else {
              alphaUseMaskNeutral = 7;
            }
          }
          rgbSelectABase = *(byte *)((int)instructionRecord2 + 0x2a) & 0xffffff7f;
          rgbSelectCRaw = (uint)*(byte *)(instructionRecord2 + 0xb);
          rgbSelectBBase = *(byte *)((int)instructionRecord2 + 0x2b) & 0xffffff7f;
          alphaSelectB = (uint)*(byte *)((int)instructionRecord2 + 0x3a);
          alphaSelectC = (uint)*(byte *)((int)instructionRecord2 + 0x3b);
          rgbSelectCBase = *(byte *)(instructionRecord2 + 0xb) & 0xffffff7f;
          alphaSelectABase = *(byte *)((int)instructionRecord2 + 0x39) & 0xffffff7f;
          alphaSelectBBase = *(byte *)((int)instructionRecord2 + 0x3a) & 0xffffff7f;
          alphaSelectCBase = *(byte *)((int)instructionRecord2 + 0x3b) & 0xffffff7f;
          rgbAuxC = *(ushort *)(instructionRecord2 + 10);
          rgbAddrA = (uint)*(ushort *)((int)instructionRecord2 + 0xe);
          rgbAddrB = (uint *)(uint)*(ushort *)(instructionRecord2 + 4);
          rgbAddrC = (uint *)(uint)*(ushort *)((int)instructionRecord2 + 0x12);
          alphaAddrA = (uint *)(uint)*(ushort *)((int)instructionRecord2 + 0x1a);
          argR8 = (uint *)(uint)*(ushort *)(instructionRecord2 + 7);
          argR9 = (char *)(uint)*(ushort *)((int)instructionRecord2 + 0x1e);
          rgbAuxA = *(ushort *)(instructionRecord2 + 9);
          rgbAuxB = *(ushort *)((int)instructionRecord2 + 0x26);
          alphaAuxD = (uint *)(uint)*(byte *)(instructionRecord2 + 0xe);
          alphaAuxB = (uint)*(byte *)((int)instructionRecord2 + 0x36);
          alphaAuxC = (uint)*(byte *)((int)instructionRecord2 + 0x37);
          rgbModA2 = (uint)*(byte *)((int)instructionRecord2 + 0x2d);
          rgbModB2 = (uint)*(byte *)((int)instructionRecord2 + 0x2e);
          rgbModC2 = (uint)*(byte *)((int)instructionRecord2 + 0x2f);
          alphaModA2 = (uint)*(byte *)(instructionRecord2 + 0xf);
          alphaModB2 = (uint)*(byte *)((int)instructionRecord2 + 0x3d);
          alphaModC2 = (uint)*(byte *)((int)instructionRecord2 + 0x3e);
          if (rgbOperandAUsed) {
            rgbSelectANotSrcp = rgbSelectABase != 3;
            if (rgbSelectANotSrcp) {
LAB_000d2654:
              rgbSrcpNeededFlag = false;
            }
            else {
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxA);
              rgbSrcpNeededFlag = true;
              if (auxCheckResult != 0) goto LAB_000d2654;
            }
            if (!rgbSelectANotSrcp) {
              alphaSrcpNeededFlag = true;
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxA);
              if (auxCheckResult != 0) goto LAB_000d2674;
            }
            alphaSrcpNeededFlag = false;
          }
          else {
            alphaSrcpNeededFlag = false;
            rgbSrcpNeededFlag = false;
          }
LAB_000d2674:
          if (rgbOperandBUsed) {
            rgbSelectBNotSrcp = rgbSelectBBase != 3;
            if (rgbSelectBNotSrcp) {
LAB_000d269c:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxB);
              srcpNeedBit = 1;
              if (auxCheckResult != 0) goto LAB_000d269c;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if (rgbSelectBNotSrcp) {
LAB_000d26bc:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxB);
              srcpNeedBit = 1;
              if (auxCheckResult == 0) goto LAB_000d26bc;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if (rgbOperandCUsed) {
            rgbSelectCNotSrcp = rgbSelectCBase != 3;
            if (rgbSelectCNotSrcp) {
LAB_000d26ec:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxC);
              srcpNeedBit = 1;
              if (auxCheckResult != 0) goto LAB_000d26ec;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if (rgbSelectCNotSrcp) {
LAB_000d270c:
              srcpNeedBit = 0;
            }
            else {
              auxCheckResult = ((int (*)())FUN_000d10a8)((uint)rgbAuxC);
              srcpNeedBit = 1;
              if (auxCheckResult == 0) goto LAB_000d270c;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if ((alphaUseMaskNeutral & 1) != 0) {
            if ((alphaSelectABase != 3) || (srcpNeedBit = 1, alphaAuxB == 3)) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectABase != 3) || (srcpNeedBit = 1, alphaAuxB != 3)) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          alphaUseBitB = (uint *)(alphaUseMaskNeutral & 2);
          if (alphaUseBitB != (uint *)0x0) {
            if ((alphaSelectBBase != 3) || (srcpNeedBit = 1, alphaAuxC == 3)) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectBBase != 3) || (srcpNeedBit = 1, alphaAuxC != 3)) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if ((alphaUseMaskNeutral & 4) != 0) {
            if ((alphaSelectCBase != 3) ||
               (srcpNeedBit = 1, alphaUseBitB = alphaAuxD, alphaAuxD == (uint *)((int)((unsigned char *)0x0) + 3))) {
              srcpNeedBit = 0;
            }
            rgbSrcpNeededFlag = (bool)(rgbSrcpNeededFlag | srcpNeedBit);
            if ((alphaSelectCBase != 3) || (srcpNeedBit = 1, alphaAuxD != (uint *)((int)((unsigned char *)0x0) + 3))) {
              srcpNeedBit = 0;
            }
            alphaSrcpNeededFlag = (bool)(alphaSrcpNeededFlag | srcpNeedBit);
          }
          if (rgbSrcpNeededFlag) {
            instructionNumberArg = instructionNumber;
            aluIndexArg = aluIndex;
            printfResultScratch = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.rgb = ",instructionNumber,aluIndex,
                                          alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            rgbPreOpKind = *(char *)(instructionRecord2 + 0xc);
            if (rgbPreOpKind == '\x01') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,rgbAddrB,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb-%s.rgb\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\0') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.rgb\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\x02') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,rgbAddrB,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"%s.rgb+%s.rgb\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbPreOpKind == '\x03') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,rgbAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.rgb\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          if (alphaSrcpNeededFlag) {
            instructionNumberArg = instructionNumber;
            aluIndexArg = aluIndex;
            printfResultScratch = (double)((int (*)())FUN_000d03b4)(0,"  %d alu %02d pre:  srcp.a   = ",instructionNumber,aluIndex,
                                          alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            alphaPreOp = *(char *)((int)instructionRecord2 + 0x3f);
            if (alphaPreOp == '\x01') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,argR8,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"%s.a-%s.a\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\0') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"1.0-2.0*%s.a\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\x02') {
              printfResultScratch = (double)((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,
                                            alphaSelectB,printfResultScratch);
              ((double (*)())FUN_000d10dc)(&srcpTextA,argR8,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"%s.a+%s.a\n",&srcpTextA,&srcpTextB,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (alphaPreOp == '\x03') {
              ((double (*)())FUN_000d10dc)(&srcpTextB,alphaAddrA,instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB,printfResultScratch);
              ((int (*)())FUN_000d03b4)(0,"1.0-%s.a\n",&srcpTextB,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else {
              ((int (*)())FUN_000d03b4)(0,"???\n",instructionNumberArg,aluIndexArg,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          rgbDestMaskTextPtr = aluIndex;
          ((int (*)())FUN_000d03b4)(0,"  %d alu %02d rgb:  ",instructionNumber,aluIndex,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          rgbOutputWriteMask = (uint)*(byte *)((int)instructionRecord2 + 0x15);
          rgbTempWriteMask2 = *(byte *)(instructionRecord2 + 5);
          if (rgbOutputWriteMask == 0) {
LAB_000d2b24:
            ((int (*)())FUN_000d03b4)(0,"           ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else if (*instructionRecord2 == 3) {
            rgbDestMaskOffset = rgbOutputWriteMask * 4;
            rgbOutputWriteMask = (uint)*(byte *)((int)instructionRecord2 + 0x16);
            rgbDestMaskTextPtr = (uint *)(rgbDestMaskOffset + 0x1dc239);
            ((int (*)())FUN_000d03b4)(0,"out%d.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else {
            if (*instructionRecord2 != 4) goto LAB_000d2b24;
            rgbOutputWriteMask = rgbOutputWriteMask * 4 + 0x1dc239;
            ((int (*)())FUN_000d03b4)(0,"pred.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            rgbOutIndex = *(char *)((int)instructionRecord2 + 0x16);
            if (rgbOutIndex == '\x01') {
              ((int (*)())FUN_000d03b4)(0,"(<) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\0') {
              ((int (*)())FUN_000d03b4)(0,"(==) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\x02') {
              ((int (*)())FUN_000d03b4)(0,"(>=) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
            else if (rgbOutIndex == '\x03') {
              ((int (*)())FUN_000d03b4)(0,"(!=) ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
            }
          }
          if (rgbTempWriteMask2 == 0) {
            ((int (*)())FUN_000d03b4)(0,"          ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          else {
            rgbOutputWriteMask = (uint)*(ushort *)(instructionRecord2 + 3);
            rgbDestMaskTextPtr = (uint *)((uint)rgbTempWriteMask2 * 4 + 0x1dc239);
            ((int (*)())FUN_000d03b4)(0,"r%02d.%s = ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          if (*(char *)((int)instructionRecord2 + 0x33) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",rgbOutputWriteMask,rgbDestMaskTextPtr,alphaUseBitB,alphaSelectC,rgbSelectCRaw,alphaSelectB);
          }
          operandText1Ptr = operandText1;
          operandAuxWord = CONCAT22(operandAuxHigh,rgbAuxA);
          ((int (*)())FUN_000d13a4)(operandText1Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectABase,rgbModA2,
                       operandAuxWord,(uint)*rgbOpcodePtr);
          operandAuxWord = CONCAT22((short)((uint)operandAuxWord >> 0x10),rgbAuxB);
          argR6 = (char *)operandText6;
          ((int (*)())FUN_000d13a4)(argR6,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectBBase,rgbModB2,
                       operandAuxWord,(uint)*rgbOpcodePtr);
          operandText5Ptr = operandText5;
          ((int (*)())FUN_000d13a4)(operandText5Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,rgbSelectCBase,rgbModC2,
                       CONCAT22((short)((uint)operandAuxWord >> 0x10),rgbAuxC),(uint)*rgbOpcodePtr);
          operandText4Ptr = operandText4;
          ((int (*)())FUN_000d1624)(operandText4Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectABase,alphaModA2,
                       alphaAuxB,(uint)*(byte *)alphaOpcodePtr);
          operandText3Ptr = operandText3;
          ((int (*)())FUN_000d1624)(operandText3Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectBBase,alphaModB2,
                       alphaAuxC,(uint)*(byte *)alphaOpcodePtr);
          operandText2Ptr = operandText2;
          alphaSelectCBaseArg = alphaSelectCBase;
          in_stack_fffffd2c = alphaAuxD;
          ((int (*)())FUN_000d1624)(operandText2Ptr,rgbAddrA,rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBase,alphaModC2,
                       alphaAuxD,(uint)*(byte *)alphaOpcodePtr);
          rgbOpcodeByte2 = *rgbOpcodePtr;
          if (rgbOpcodeByte2 < 0xd) {
            argR9 = (char *)(0);
            switch(rgbOpcodeByte2) {
            case 0:
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp3(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 2:
              operandText4Ptr2 = operandText4Ptr;
              operandText5Ptr = (uint *)argR6;
              argR8 = operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"dp4(%s:%s, %s:%s)",operandText1Ptr,operandText4Ptr,argR6,operandText3Ptr,argR9,alphaSelectCBaseArg);
              argR6 = (char *)operandText4Ptr2;
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"d2a(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 6:
              goto switchD_000d2d30_caseD_6;
            case 7:
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 8:
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 9:
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",operandText1Ptr,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              argR6 = (char *)rgbAddrC;
              operandText5Ptr = alphaAddrA;
              break;
            case 10:
              ((int (*)())FUN_000d03b4)(0,"sop()",rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText1Ptr = rgbAddrB;
              argR6 = (char *)rgbAddrC;
              operandText5Ptr = alphaAddrA;
              break;
            case 0xb:
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
              break;
            case 0xc:
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",operandText1Ptr,argR6,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
              operandText5Ptr = alphaAddrA;
            }
          }
          else {
switchD_000d2d30_caseD_6:
            ((int (*)())FUN_000d03b4)(0,"???()",rgbAddrB,rgbAddrC,alphaAddrA,argR8,argR9,alphaSelectCBaseArg);
            operandText1Ptr = rgbAddrB;
            argR6 = (char *)rgbAddrC;
            operandText5Ptr = alphaAddrA;
          }
          rgbOutputScaleByte2 = *(byte *)((int)instructionRecord2 + 0x32);
          if (rgbOutputScaleByte2 < 7) {
            argR9 = (char *)(0);
            switch(rgbOutputScaleByte2) {
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
          }
          if (((*(unsigned char *)((unsigned char *)&(semWaitText) + 0)) != '\0') || ((*(unsigned char *)((unsigned char *)&(aluWaitText) + 0)) != '\0')) {
            operandText1Ptr = &semWaitText;
            argR6 = (char *)&aluWaitText;
            ((int (*)())FUN_000d03b4)(0,"%s%s",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,alphaSelectCBaseArg);
          }
          argR10 = (byte *)((int)instructionRecord2 + 5);
          if (*(char *)((int)instructionRecord2 + 5) != '\0') {
            if (*(char *)((int)instructionRecord2 + 6) == '\0') {
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
            }
            else {
              argR9 = "!p";
              (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
            }
            predicateModeByte2 = *argR10;
            if (predicateModeByte2 < 6) {
              argR9 = (char *)(0);
              switch(predicateModeByte2) {
              case 1:
                operandText1Ptr = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.rgb",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 2:
                operandText1Ptr = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.rrr",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 3:
                operandText1Ptr = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.ggg",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 4:
                operandText1Ptr = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.bbb",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
                break;
              case 5:
                operandText1Ptr = &predicateText;
                ((int (*)())FUN_000d03b4)(0," %s.aaa",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
            }
          }
          ((int (*)())FUN_000d03b4)(0,"\n",operandText1Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
          neutralLineArg0 = aluIndex;
          ((int (*)())FUN_000d03b4)(0,"         alpha:  ",aluIndex,argR6,operandText5Ptr,argR8,argR9,argR10);
          alphaTempEnable = *(char *)(instructionRecord2 + 8);
          alphaOutputEnableFlag2 = *(char *)((int)instructionRecord2 + 0x21) != '\0';
          depthWrite = *(char *)((int)instructionRecord2 + 0x23);
          if (alphaOutputEnableFlag2) {
            if (*instructionRecord2 == 3) {
              neutralLineArg0 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x22);
              ((int (*)())FUN_000d03b4)(0,"out%d.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
            else if (*instructionRecord2 == 4) {
              ((int (*)())FUN_000d03b4)(0,"pred.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              alphaOutIndex = *(char *)((int)instructionRecord2 + 0x22);
              if (alphaOutIndex == '\x01') {
                ((int (*)())FUN_000d03b4)(0,"(<) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\0') {
                ((int (*)())FUN_000d03b4)(0,"(==) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\x02') {
                ((int (*)())FUN_000d03b4)(0,"(>=) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
              else if (alphaOutIndex == '\x03') {
                ((int (*)())FUN_000d03b4)(0,"(!=) ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              }
            }
          }
          depthWriteFlag2 = depthWrite != '\0';
          if (depthWriteFlag2) {
            ((int (*)())FUN_000d03b4)(0,"depth    = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if ((!alphaOutputEnableFlag2) && (!depthWriteFlag2)) {
            ((int (*)())FUN_000d03b4)(0,"           ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (alphaTempEnable == '\0') {
            ((int (*)())FUN_000d03b4)(0,"          ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          else {
            neutralLineArg0 = (uint *)(uint)*(ushort *)(instructionRecord2 + 6);
            ((int (*)())FUN_000d03b4)(0,"r%02d.a   = ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord2 + 0x42) != '\0') {
            ((int (*)())FUN_000d03b4)(0,"clamped ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          alphaOpcodeByte2 = *(byte *)alphaOpcodePtr;
          if (alphaOpcodeByte2 < 0x10) {
            argR9 = (char *)(0);
            switch(alphaOpcodeByte2) {
            case 0:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())FUN_000d03b4)(0,"mad(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"dp()",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 2:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"min(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 3:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"max(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 4:
              goto switchD_000d324c_caseD_4;
            case 5:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())FUN_000d03b4)(0,"cnd(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 6:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              operandText5Ptr = operandText2Ptr;
              ((int (*)())FUN_000d03b4)(0,"cmp(%s, %s, %s)",operandText4Ptr,operandText3Ptr,operandText2Ptr,argR8,argR9,argR10);
              break;
            case 7:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"frc(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 8:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"ex2(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 9:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"ln2(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 10:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"rcp(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xb:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"rsq(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xc:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"sin(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xd:
              neutralLineArg0 = operandText4Ptr;
              ((int (*)())FUN_000d03b4)(0,"cos(%s)",operandText4Ptr,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xe:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"mdh(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 0xf:
              neutralLineArg0 = operandText4Ptr;
              argR6 = (char *)operandText3Ptr;
              ((int (*)())FUN_000d03b4)(0,"mdv(%s, %s)",operandText4Ptr,operandText3Ptr,operandText5Ptr,argR8,argR9,argR10);
            }
          }
          else {
switchD_000d324c_caseD_4:
            ((int (*)())FUN_000d03b4)(0,"???()",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          alphaOutputScaleByte2 = *(byte *)((int)instructionRecord2 + 0x41);
          if (alphaOutputScaleByte2 < 7) {
            argR9 = (char *)(0);
            switch(alphaOutputScaleByte2) {
            case 0:
              ((int (*)())FUN_000d03b4)(0," ",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 1:
              ((int (*)())FUN_000d03b4)(0,"*2",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 2:
              ((int (*)())FUN_000d03b4)(0,"*4",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 3:
              ((int (*)())FUN_000d03b4)(0,"*8",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 4:
              ((int (*)())FUN_000d03b4)(0,"/2",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 5:
              ((int (*)())FUN_000d03b4)(0,"/4",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
              break;
            case 6:
              ((int (*)())FUN_000d03b4)(0,"/8",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"*???",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)((int)instructionRecord2 + 10) == '\0') {
            argR10 = (byte *)((int)instructionRecord2 + 7);
            if (*(char *)((int)instructionRecord2 + 7) != '\0') {
              if (*(char *)(instructionRecord2 + 2) == '\0') {
                (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT21(0x7000,(*(unsigned char *)((unsigned char *)&(predicateText) + 2)));
              }
              else {
                argR9 = "!p";
                (*(unsigned int *)((unsigned char *)&(predicateText) + 0)) = CONCAT12(s__p_001a74dc[0],(*(unsigned short *)((unsigned char *)&(s__p_001a74dc) + 1)));
              }
              predicateModeByteAlpha2 = *argR10;
              if (predicateModeByteAlpha2 < 6) {
                argR9 = (char *)(0);
                switch(predicateModeByteAlpha2) {
                case 0:
                  break;
                default:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())FUN_000d03b4)(0," %s.a",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 2:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())FUN_000d03b4)(0," %s.r",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 3:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())FUN_000d03b4)(0," %s.g",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                  break;
                case 4:
                  neutralLineArg0 = &predicateText;
                  ((int (*)())FUN_000d03b4)(0," %s.b",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
                }
              }
            }
            if (*(char *)((int)instructionRecord2 + 9) != '\0') {
              ((int (*)())FUN_000d03b4)(0," write_inactive",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
            }
            ((int (*)())FUN_000d03b4)(0," \n",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          else {
            ((int (*)())FUN_000d03b4)(0," last\n",neutralLineArg0,argR6,operandText5Ptr,argR8,argR9,argR10);
          }
          if (*(char *)(instructionRecord2 + 0xd) != '\0') {
            neutralLineArg0 = aluIndex;
            ((int (*)())FUN_000d03b4)(0,"   alu %02d post-NOP\n",aluIndex,argR6,operandText5Ptr,argR8,argR9,argR10
                        );
          }
          recordKind2 = *instructionRecord2;
          aluIndex = (uint *)((int)aluIndex + 1);
        }
        if (recordKind2 == 5) {
          if (cfCompareCode == 1) {
            argR9 = "lt";
            srcpTextB = CONCAT12(s_lt_001a77dc[0],(*(unsigned short *)((unsigned char *)&(s_lt_001a77dc) + 1)));
          }
          else if (cfCompareCode == 0) {
            argR9 = "eq";
            srcpTextB = CONCAT12(s_eq_001a77d8[0],(*(unsigned short *)((unsigned char *)&(s_eq_001a77d8) + 1)));
          }
          else if (cfCompareCode == 2) {
            argR9 = "ge";
            srcpTextB = CONCAT12(s_ge_001a77e0[0],(*(unsigned short *)((unsigned char *)&(s_ge_001a77e0) + 1)));
          }
          else if (cfCompareCode == 3) {
            argR9 = "ne";
            srcpTextB = CONCAT12(s_ne_001a77e4[0],(*(unsigned short *)((unsigned char *)&(s_ne_001a77e4) + 1)));
          }
          else {
            srcpTextB = CONCAT21(0x2000,uStack_29e);
          }
          if (cfPrevAluDest == 0) {
            srcpTextA = 0x72656400;
          }
          else if (cfPrevAluDest == 1) {
            argR9 = "alpha";
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 0)) = s_alpha_001a77e8[0];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 1)) = s_alpha_001a77e8[1];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 2)) = s_alpha_001a77e8[2];
            (*(unsigned char *)((unsigned char *)&(srcpTextA) + 3)) = s_alpha_001a77e8[3];
            local_2a6[0] = s_alpha_001a77e8[4];
            local_2a6[1] = s_alpha_001a77e8[5];
          }
          else {
            srcpTextA = CONCAT22(0x2000,(*(unsigned short *)((unsigned char *)&(srcpTextA) + 2)));
          }
          argR6 = (char *)cfWordText;
          ((int (*)())FUN_000d03b4)(0,"  %d cf  %02d    :  ",instructionNumber,cfIndex,cfCompareCode,argR8,argR9,argR10);
          in_stack_fffffd2c = (uint *)0x0;
          argR10 = (byte *)((uint)*(byte *)((int)instructionRecord2 + 0x15) * 10 + 0x1dc1bc);
          argR9 = (char *)((uint)*(byte *)(instructionRecord2 + 5) * 10 + 0x1dc1bc);
          FUN_001a32d0(argR6,"0x%02x %1d %s %s %s %s %1d %1d %d",
                       (uint)*(byte *)((int)instructionRecord2 + 0x12),(uint)*(byte *)(instructionRecord2 + 4),
                       (uint)*(byte *)((int)instructionRecord2 + 0xe) * 10 + 0x1dc1e9,
                       (uint)*(byte *)((int)instructionRecord2 + 0x11) * 5 + 0x1dc1da,argR9,argR10);
          if (PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0 == (undefined *)0x0) {
            cfOpTableIndex = 0;
          }
          else {
            cfOpNameCursor = &PTR_s_0xaa_0_JUMP_NONE_NONE_NONE_001dc2d8;
            cfOpTableIndex = 0;
            cfOpNameEntry = PTR_s_0x55_0_JUMP_NONE_NONE_NONE_001dc2d0;
            do {
              cfNameLength = _strlen(cfOpNameEntry);
              cfNameCompare = _strncmp(cfOpNameEntry,argR6,cfNameLength);
              if (cfNameCompare == 0) break;
              cfOpNameEntry = *cfOpNameCursor;
              cfOpTableIndex = cfOpTableIndex + 2;
              cfOpNameCursor = cfOpNameCursor + 2;
            } while (cfOpNameEntry != (undefined *)0x0);
          }
          neutralLineArg0 = (uint *)(PTR_s_IF_b_001dc2cc)[cfOpTableIndex];
          semWaitTextPtr = &semWaitText;
          argR8 = &aluWaitText;
          ((int (*)())FUN_000d03b4)(0,"%s(%s)%s%s",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          cfAddressByte = *(char *)((int)instructionRecord2 + 0x12);
          if ((cfAddressByte == -0x10) || (cfAddressByte == '\x0f')) {
            neutralLineArg0 = &srcpTextA;
            argR6 = (char *)&srcpTextB;
            ((int (*)())FUN_000d03b4)(0,"( prev_alu: %s %s )\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          else if ((cfAddressByte == -0x56) || (cfAddressByte == 'U')) {
            neutralLineArg0 = (uint *)(uint)*(byte *)((int)instructionRecord2 + 0x17);
            ((int (*)())FUN_000d03b4)(0,"( bool_addr: %d )\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          else {
            ((int (*)())FUN_000d03b4)(0,"\n",neutralLineArg0,argR6,semWaitTextPtr,argR8,argR9,argR10);
          }
          cfIndex = cfIndex + 1;
        }
        rsRecordNumber2 = rsRecordNumber2 + 1;
        instructionRecord2 = instructionRecord2 + 0x12;
        instructionNumber = instructionNumber + 1;
        neutralRecordCountArg = recordCount2;
      } while (rsRecordNumber2 <= (int)recordCount2);
    }
    ((int (*)())FUN_000d03b4)(0,blankLineFormatOffset + 0x5b00,neutralLineArg0,argR6,neutralRecordCountArg,argR8,argR9,argR10);
    ((int (*)())FUN_000d03b4)(0,"======== End r520 neutral format pixel shader =============\n",neutralLineArg0,argR6,
                 neutralRecordCountArg,argR8,argR9,argR10);
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

