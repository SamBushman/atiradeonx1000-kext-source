#include "decls.h"

/* FUN_00083c80 @ 0x83c80 (12 bytes) */
int FUN_00083c80(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  FUN_00083870();
  return;
}

/* FUN_00083c90 @ 0x83c90 (372 bytes) */
int FUN_00083c90(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = 4;
  *(undefined4 *)(((unsigned char *)0x0000148c) + param_1) = 0;
  *(undefined1 *)(param_1 + 0x3d4) = 1;
  uVar2 = *(int *)(((unsigned char *)0x000013f4) + param_1) - 2;
  uVar3 = *(int *)(((unsigned char *)0x000013f4) + param_1) - 1;
  DAT_001dbca8 = uVar3 & 0x3ff | DAT_001dbca8 & 0xfffffc00;
  DAT_001dbcac = (uVar3 & 0x3ff) << 0x14 |
                 (uVar2 & 0x3ff) << 10 | uVar2 & 0x3ff | DAT_001dbcac & 0xc0000000;
  uVar3 = *(uint *)(param_1 + 0x8c);
  if ((uVar3 & 0x8000) != 0) {
    if (*(int *)(param_1 + 0xd8) == 2) {
      bVar4 = 0xc;
      *(uint *)(param_1 + 0x8c) = uVar3 | 0x50000;
    }
    else {
      bVar4 = 4;
      *(uint *)(param_1 + 0x8c) = uVar3 & 0xffff7fff;
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(byte *)(param_1 + 0x2d) = bVar4 | *(byte *)(param_1 + 0x2d);
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  param_2[3] = uVar2;
  param_2[1] = 0;
  *param_2 = 0x8a1;
  param_2[2] = 0x880;
  param_2[4] = 0x78882;
  param_2[5] = DAT_001dbcb0;
  param_2[6] = DAT_001dbcb4;
  param_2[7] = DAT_001dbcb8;
  param_2[8] = DAT_001dbcbc;
  param_2[9] = DAT_001dbcc0;
  param_2[10] = DAT_001dbcc4;
  param_2[0xb] = DAT_001dbcc8;
  uVar1 = DAT_001dbccc;
  param_2[0xd] = ((unsigned char *)0x000208b4);
  param_2[0xc] = uVar1;
  param_2[0xe] = DAT_001dbcac;
  param_2[0xf] = DAT_001fa5e4;
  uVar3 = DAT_001dbca8;
  param_2[0x11] = 0x8b7;
  param_2[0x12] = 0;
  param_2[0x10] = uVar3;
  return param_2 + 0x13;
}

/* FUN_00086710 @ 0x86710 (152 bytes) */
int FUN_00086710(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x880;
  uVar2 = *(undefined4 *)(param_1 + 0x244c);
  puVar1[2] = ((unsigned char *)0x00038882);
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 400);
  puVar1[4] = *(undefined4 *)(param_1 + 0x194);
  puVar1[5] = *(undefined4 *)(param_1 + 0xf0);
  puVar1[6] = *(undefined4 *)(param_1 + 0x198);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_000867b0 @ 0x867b0 (140 bytes) */
int FUN_000867b0(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0x1930);
  uVar4 = 0;
  iVar5 = 6;
  uVar2 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if (((int)(uint)*(ushort *)(param_1 + 0x36) >> (uVar4 & 0x3f) & 1U) != 0) {
      uVar1 = 1 << (uVar4 & 0x3f);
      if ((uVar2 & uVar1) == 0) {
        *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & ~uVar1;
      }
      else {
        uVar3 = uVar3 | 0x1000000;
        *(uint *)(param_1 + 0x1930) = uVar3;
        *(uint *)(param_1 + 0x1b74) = uVar1 | *(uint *)(param_1 + 0x1b74);
      }
    }
    uVar4 = uVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(uint *)(param_1 + 0x1930) = uVar3 | 0x400000;
  *(undefined2 *)(param_1 + 0x36) = 0;
  return;
}

/* FUN_00086840 @ 0x86840 (228 bytes) */
int FUN_00086840(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  puVar7 = (undefined4 *)(param_1 + 0x3d8);
  uVar6 = 0;
  uVar5 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if ((uVar5 & 1 << (uVar6 & 0x3f)) != 0) {
      puVar4 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4;
      *puVar4 = 0x880;
      iVar2 = *(int *)(param_1 + 0x1be0);
      puVar4[2] = ((unsigned char *)0x00038882);
      puVar4[1] = uVar6 + iVar2;
      puVar4[3] = *puVar7;
      puVar4[4] = puVar7[1];
      puVar4[5] = puVar7[2];
      puVar4[6] = puVar7[3];
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x1c;
      (*pcVar3)(param_1);
    }
    bVar1 = uVar6 != 5;
    puVar7 = puVar7 + 4;
    uVar6 = uVar6 + 1;
  } while (bVar1);
  return;
}

/* FUN_00086930 @ 0x86930 (204 bytes) */
int FUN_00086930(double param_1,double param_2,int param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_3 + 0x284c)) - DOUBLE_001aa250)
          * FLOAT_001aa170 + (float)(param_1 + param_2);
  if (fVar1 == FLOAT_001aa0d4) {
    return 0;
  }
  if (fVar1 != FLOAT_001aa174) {
    fVar2 = FLOAT_001aa17c;
    if ((FLOAT_001aa178 <= fVar1) && (fVar2 = FLOAT_001aa184, fVar1 <= FLOAT_001aa180)) {
      fVar2 = fVar1 * FLOAT_001aa0f8;
    }
    return (int)fVar2;
  }
  return -0x10;
}

/* FUN_00086a10 @ 0x86a10 (96 bytes) */
int FUN_00086a10(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  float *param_3;
{
  undefined2 uVar1;
  
  if (param_3 == (float *)0x0) {
    uVar1 = ((int (*)())FUN_00086930)((double)*(float *)(param_2 + 0x20),(double)FLOAT_001aa0d4);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  else {
    uVar1 = ((int (*)())FUN_00086930)((double)*(float *)(param_2 + 0x20),(double)*param_3);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  return;
}

/* FUN_00086a80 @ 0x86a80 (284 bytes) */
int FUN_00086a80(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x1b74);
  param_2[1] = *(undefined4 *)(param_1 + 0x1b84);
  param_2[2] = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
  param_2[3] = *(undefined4 *)(param_1 + 0x1aa0);
  param_2[4] = *(undefined4 *)(param_1 + 0x1ab0);
  param_2[5] = *(undefined4 *)(param_1 + 0x1aa4);
  param_2[6] = *(undefined4 *)(param_1 + 0x1aa8);
  param_2[8] = *(undefined4 *)(param_1 + 0x1ab8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1aec);
  param_2[10] = *(undefined4 *)(param_1 + 0x1a4c);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1a50);
  param_2[0xc] = *(undefined4 *)(param_1 + 0x1a80);
  param_2[0xd] = *(undefined4 *)(param_1 + 0x1af8);
  param_2[0xe] = *(undefined4 *)(param_1 + 0x1b9c);
  param_2[0xf] = *(undefined4 *)(param_1 + 0x1ba0);
  param_2[0x10] = *(undefined4 *)(param_1 + 0x248c);
  param_2[0x11] = **(undefined4 **)(param_1 + 0x2440);
  param_2[0x12] = **(undefined4 **)(param_1 + 0x2444);
  param_2[0x15] = *(undefined4 *)(param_1 + 0x1ae0);
  param_2[0x13] = *(undefined4 *)(param_1 + 7000);
  param_2[0x14] = *(undefined4 *)(param_1 + 0x1b10);
  param_2[0x16] = *(undefined4 *)(param_1 + 0x1b3c);
  param_2[0x17] = *(undefined4 *)(FUN_00001af4 + param_1);
  param_2[0x18] = *(undefined4 *)(param_1 + 0x1b50);
  param_2[0x19] = *(undefined4 *)(param_1 + 0x1f2c);
  param_2[0x1a] = *(undefined4 *)(param_1 + 0x1a60);
  param_2[0x1b] = *(undefined4 *)(param_1 + 0x1a68);
  param_2[0x1c] = *(undefined4 *)(param_1 + 0x1a6c);
  param_2[0x1d] = *(undefined4 *)(param_1 + 0x1b60);
  param_2[0x1e] = *(undefined4 *)(param_1 + 0x23e0);
  param_2[0x1f] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[0x20] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[0x21] = *(undefined4 *)(param_1 + 0x1bc0);
  param_2[0x22] = *(undefined4 *)(param_1 + 0x1bb0);
  return;
}

/* FUN_00086ba0 @ 0x86ba0 (1840 bytes) */
int FUN_00086ba0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  undefined4 param_5;
{
  bool bVar1;
  ushort uVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  code *pcVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 uVar12;
  
  bVar1 = param_3 == 0;
  ((int (*)())FUN_00086a80)(param_1,param_5);
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(uint *)(param_1 + 0x1aa0) = param_4 & 1 | (param_3 & 1) << 1 | (param_3 & 1) << 2;
  *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xffff3fff | 0x1c000;
  *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xffffffc5 | 5;
  if (bVar1) {
    uVar5 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8;
    *(uint *)(param_1 + 0x1aa4) = uVar5;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x1aa4) & 0xfffffff8 | 7;
    *(uint *)(param_1 + 0x1aa4) = uVar5;
  }
  if (param_4 == 0) {
    *(uint *)(param_1 + 0x1aa4) = uVar5 & 0xffffffc7;
  }
  else {
    iVar11 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(uint *)(param_1 + 0x1aa4) = uVar5 & 0xff1c71c7 | 0x438438;
    *(char *)(param_1 + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x00002db4) + iVar11);
    *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar11);
  }
  *(undefined4 *)(param_1 + 0x1a80) = 0x20200000;
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
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff | 0xf0000000;
  dVar4 = DOUBLE_001aa1e0;
  fVar3 = FLOAT_001aa0d4;
  if (*(int *)(param_1 + 8) == 0xc) {
    uVar8 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar5 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         dVar4) * *(float *)(param_1 + 0x2814) + fVar3) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar5 | uVar8 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       dVar4) * *(float *)(param_1 + 0x2818) + fVar3) & 0x1fffU) << 0xd |
         uVar5 | uVar8 & 0xfc000000;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x1b10);
    *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc000000;
    uVar5 = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(param_1 + 4) + 0x15c) ^ 0x80000000) -
                         dVar4) * *(float *)(param_1 + 0x2814) + fVar3) & 0x1fff;
    *(uint *)(param_1 + 0x1b10) = uVar5 | uVar8 & 0xffffe000;
    *(uint *)(param_1 + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(param_1 + 4) + 0x160) ^ 0x80000000) -
                       dVar4) * *(float *)(param_1 + 0x2818) + fVar3) & 0x1fffU) << 0xd |
         uVar5 | uVar8 & 0xfc000000;
  }
  uVar2 = *(ushort *)(param_1 + 0x1b52);
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(((unsigned char *)0x00001b30) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(uint *)(param_1 + 0x1b50) = (uint)uVar2;
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(undefined4 *)(param_1 + 0x1af8) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(FUN_00001af4 + param_1) = 0;
  }
  uVar12 = *(undefined4 *)(param_1 + 0x1930);
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  FUN_0004b480(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  pcVar9 = *(code **)(((unsigned char *)0x00001330) + param_1);
  *(uint *)(param_1 + 0x1f2c) = *(uint *)(param_1 + 0x1f2c) & 0xfffff800 | 0x80;
  (*pcVar9)(param_1,0xc0100000);
  *(undefined4 *)(param_1 + 0x1930) = uVar12;
  if (!bVar1) {
    *(uint *)(param_1 + 0x1ae0) = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffe;
  }
  puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3d);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
  puVar10 = puVar7 + 0x34;
  *puVar7 = 0x887;
  uVar12 = *(undefined4 *)(param_1 + 0x1b74);
  puVar7[2] = 0x82c;
  puVar7[1] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1b84);
  puVar7[4] = ((unsigned char *)0x000010ae);
  puVar7[3] = uVar12;
  uVar12 = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
  puVar7[6] = ((unsigned char *)0x000013c0);
  puVar7[5] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar7[8] = ((unsigned char *)0x000013c1);
  puVar7[7] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar7[10] = ((unsigned char *)0x000013c2);
  puVar7[9] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar7[0xc] = ((unsigned char *)0x000012f0);
  puVar7[0xb] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1aec);
  puVar7[0xe] = ((unsigned char *)0x000012f5);
  puVar7[0xd] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1a4c);
  puVar7[0x10] = ((unsigned char *)0x000012f6);
  puVar7[0xf] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1a50);
  puVar7[0x12] = ((unsigned char *)0x00001381);
  puVar7[0x11] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1a80);
  puVar7[0x14] = ((unsigned char *)0x00001386);
  puVar7[0x13] = uVar12;
  puVar7[0x15] = *(undefined4 *)(param_1 + 0x1af8);
  puVar7[0x16] = 0x824;
  uVar12 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar7[0x18] = 0x825;
  puVar7[0x17] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar7[0x1a] = 0x82d;
  puVar7[0x19] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x248c);
  puVar7[0x1c] = 0x854;
  puVar7[0x1b] = uVar12;
  uVar12 = **(undefined4 **)(param_1 + 0x2440);
  puVar7[0x1e] = 0x878;
  puVar7[0x1d] = uVar12;
  uVar12 = **(undefined4 **)(param_1 + 0x2444);
  puVar7[0x20] = ((unsigned char *)0x000010f8);
  puVar7[0x1f] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 7000);
  puVar7[0x22] = ((unsigned char *)0x000010f9);
  puVar7[0x21] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1b10);
  puVar7[0x24] = ((unsigned char *)0x000010a2);
  puVar7[0x23] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar7[0x26] = ((unsigned char *)0x00001383);
  puVar7[0x25] = uVar12;
  uVar12 = *(undefined4 *)(FUN_00001af4 + param_1);
  puVar7[0x28] = ((unsigned char *)0x00001002);
  puVar7[0x27] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1b50);
  puVar7[0x2a] = ((unsigned char *)0x000010c0);
  puVar7[0x29] = uVar12;
  puVar7[0x2b] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar7[0x2c] = 0x825;
  uVar12 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar7[0x2e] = 0x766;
  puVar7[0x2d] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar7[0x30] = 0x768;
  puVar7[0x2f] = uVar12;
  uVar12 = *(undefined4 *)(param_1 + 0x1c94);
  puVar7[0x32] = ((unsigned char *)0x000010fa);
  puVar7[0x31] = uVar12;
  puVar7[0x33] = *(undefined4 *)(param_1 + 0x1b60);
  if (!bVar1) {
    iVar11 = *(int *)(param_1 + 4);
    puVar6 = *(uint **)(iVar11 + 0x1d8);
    *puVar6 = (int)puVar10 - (int)puVar6 >> 2 | *puVar6;
    *(undefined4 **)(iVar11 + 0x1d8) = puVar10;
    puVar10 = puVar7 + 0x39;
    puVar7[0x34] = 0x2f000000;
    puVar7[0x35] = (*(unsigned char *)0x000010e9);
    uVar12 = *(undefined4 *)(param_1 + 0x1ae0);
    puVar7[0x37] = ((unsigned char *)0x000013c7);
    puVar7[0x36] = uVar12;
    puVar7[0x38] = *(undefined4 *)(param_1 + 0x1ab0);
  }
  *puVar10 = ((unsigned char *)0x00001048);
  uVar12 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar10[2] = ((unsigned char *)0x00001047);
  puVar10[1] = uVar12;
  puVar10[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar10 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar10 + 4);
  return;
}

/* FUN_000872e0 @ 0x872e0 (1296 bytes) */
int FUN_000872e0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  char cVar1;
  undefined *puVar2;
  code *pcVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  puVar8 = *(undefined4 **)(param_1 + 0x2440);
  *(undefined4 *)(param_1 + 0x1b74) = *param_2;
  *(undefined4 *)(param_1 + 0x1b84) = param_2[1];
  *(undefined4 *)(((unsigned char *)0x00001b30) + param_1) = param_2[2];
  *(undefined4 *)(param_1 + 0x1aa0) = param_2[3];
  *(undefined4 *)(param_1 + 0x1ab0) = param_2[4];
  *(undefined4 *)(param_1 + 0x1aa4) = param_2[5];
  *(undefined4 *)(param_1 + 0x1aa8) = param_2[6];
  *(undefined4 *)(param_1 + 0x1ab8) = param_2[8];
  *(undefined4 *)(param_1 + 0x1aec) = param_2[9];
  *(undefined4 *)(param_1 + 0x1a4c) = param_2[10];
  *(undefined4 *)(param_1 + 0x1a50) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x1a80) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x1af8) = param_2[0xd];
  *(undefined4 *)(param_1 + 0x1b9c) = param_2[0xe];
  *(undefined4 *)(param_1 + 0x1ba0) = param_2[0xf];
  *(undefined4 *)(param_1 + 0x248c) = param_2[0x10];
  *puVar8 = param_2[0x11];
  **(undefined4 **)(param_1 + 0x2444) = param_2[0x12];
  *(undefined4 *)(param_1 + 0x1ae0) = param_2[0x15];
  *(undefined4 *)(param_1 + 7000) = param_2[0x13];
  *(undefined4 *)(param_1 + 0x1b10) = param_2[0x14];
  *(undefined4 *)(param_1 + 0x1b3c) = param_2[0x16];
  *(undefined4 *)(FUN_00001af4 + param_1) = param_2[0x17];
  *(undefined4 *)(param_1 + 0x1b50) = param_2[0x18];
  *(undefined4 *)(param_1 + 0x1f2c) = param_2[0x19];
  *(undefined4 *)(param_1 + 0x1a60) = param_2[0x1a];
  *(undefined4 *)(param_1 + 0x1a68) = param_2[0x1b];
  *(undefined4 *)(param_1 + 0x1a6c) = param_2[0x1c];
  *(undefined4 *)(param_1 + 0x1b60) = param_2[0x1d];
  *(undefined4 *)(param_1 + 0x23e0) = param_2[0x1e];
  *(undefined4 *)(param_1 + 0x1c8c) = param_2[0x1f];
  *(undefined4 *)(param_1 + 0x1c94) = param_2[0x20];
  *(undefined4 *)(param_1 + 0x1bc0) = param_2[0x21];
  pcVar3 = *(code **)(((unsigned char *)0x00001334) + param_1);
  *(undefined4 *)(param_1 + 0x1bb0) = param_2[0x22];
  (*pcVar3)(param_1,0);
  if (((*(uint *)(param_1 + 0x44) & 0x20000) != 0) &&
     (puVar8 = *(undefined4 **)(param_1 + 0x1e70), puVar8 != (undefined4 *)0x0)) {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar1 == '\0') goto LAB_00087474;
  }
  puVar8 = *(undefined4 **)(param_1 + 0x1e5c);
LAB_00087474:
  *(undefined1 *)((int)puVar8 + 0x10eb) = 0;
  if (*(int *)(param_1 + 0x23e0) == 0) {
    *puVar8 = 0;
    puVar8[0x4c0] = 0;
  }
  else {
    puVar8[7] = 0;
    puVar8[0x54b] = 0;
  }
  FUN_0004a8f0(param_1);
  (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  puVar8 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x55);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar8;
  *puVar8 = 0x887;
  puVar2 = PTR_DAT_001e88c8;
  uVar6 = *(undefined4 *)(param_1 + 0x1b74);
  puVar8[2] = 0x82c;
  puVar8[1] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b84);
  puVar8[4] = ((unsigned char *)0x000010ae);
  puVar8[3] = uVar6;
  uVar6 = *(undefined4 *)(((unsigned char *)0x00001b30) + param_1);
  puVar8[6] = ((unsigned char *)0x000013c0);
  puVar8[5] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa0);
  puVar8[8] = ((unsigned char *)0x000013c1);
  puVar8[7] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar8[10] = ((unsigned char *)0x000013c2);
  puVar8[9] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1aa8);
  puVar8[0xc] = ((unsigned char *)0x000012f0);
  puVar8[0xb] = uVar6;
  uVar7 = *(uint *)(param_1 + 0x1aec);
  puVar8[0xd] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar8[0xd] = uVar7 & 0xfffffffe;
  }
  puVar8[0xe] = ((unsigned char *)0x000012f5);
  uVar7 = *(uint *)(param_1 + 0x1a4c);
  puVar8[0xf] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar8[0xf] = uVar7 & 0xfffff7ff;
  }
  puVar8[0x10] = ((unsigned char *)0x000012f6);
  uVar6 = *(undefined4 *)(param_1 + 0x1a50);
  puVar8[0x12] = ((unsigned char *)0x00001381);
  puVar8[0x11] = uVar6;
  uVar7 = *(uint *)(param_1 + 0x1a80);
  puVar8[0x13] = uVar7;
  if ((*(uint *)(puVar2 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    puVar8[0x13] = uVar7 & 0xfffffffc;
  }
  puVar8[0x14] = ((unsigned char *)0x00001386);
  puVar5 = puVar8 + 0x34;
  uVar6 = *(undefined4 *)(param_1 + 0x1af8);
  puVar8[0x16] = 0x824;
  puVar8[0x15] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b9c);
  puVar8[0x18] = 0x825;
  puVar8[0x17] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar8[0x1a] = 0x82d;
  puVar8[0x19] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x248c);
  puVar8[0x1c] = 0x854;
  puVar8[0x1b] = uVar6;
  uVar6 = **(undefined4 **)(param_1 + 0x2440);
  puVar8[0x1e] = 0x878;
  puVar8[0x1d] = uVar6;
  uVar6 = **(undefined4 **)(param_1 + 0x2444);
  puVar8[0x20] = ((unsigned char *)0x000010a2);
  puVar8[0x1f] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b3c);
  puVar8[0x22] = ((unsigned char *)0x00001383);
  puVar8[0x21] = uVar6;
  uVar6 = *(undefined4 *)(FUN_00001af4 + param_1);
  puVar8[0x24] = ((unsigned char *)0x00001002);
  puVar8[0x23] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b50);
  puVar8[0x26] = ((unsigned char *)0x000010c0);
  puVar8[0x25] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1f2c);
  puVar8[0x28] = 0x825;
  puVar8[0x27] = uVar6;
  puVar8[0x29] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar8[0x2a] = ((unsigned char *)0x00001008);
  uVar6 = *(undefined4 *)(param_1 + 0x1a60);
  puVar8[0x2c] = ((unsigned char *)0x00001004);
  puVar8[0x2b] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1a68);
  puVar8[0x2e] = ((unsigned char *)0x00001005);
  puVar8[0x2d] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1a6c);
  puVar8[0x30] = ((unsigned char *)0x000010fa);
  puVar8[0x2f] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1b60);
  puVar8[0x32] = ((unsigned char *)0x000013c5);
  puVar8[0x31] = uVar6;
  puVar8[0x33] = *(undefined4 *)(param_1 + 0x1ab8);
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar8[0x34] = ((unsigned char *)0x000013c5);
    puVar5 = puVar8 + 0x36;
    puVar8[0x35] = *(undefined4 *)(param_1 + 0x1ab8);
  }
  puVar8 = (undefined4 *)FUN_0004dd10(param_1,puVar5);
  *puVar8 = 0x766;
  uVar6 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar8[2] = 0x768;
  puVar8[1] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1c94);
  puVar8[4] = ((unsigned char *)0x000010fa);
  puVar8[3] = uVar6;
  puVar8[5] = *(undefined4 *)(param_1 + 0x1b60);
  iVar9 = *(int *)(param_1 + 4);
  puVar4 = *(uint **)(iVar9 + 0x1d8);
  *puVar4 = (int)(puVar8 + 6) - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(iVar9 + 0x1d8) = puVar8 + 6;
  puVar8[6] = 0x2f000000;
  puVar8[7] = (*(unsigned char *)0x000010e9);
  uVar6 = *(undefined4 *)(param_1 + 0x1ae0);
  puVar8[9] = ((unsigned char *)0x000013c7);
  puVar8[8] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1ab0);
  puVar8[0xb] = ((unsigned char *)0x00001048);
  puVar8[10] = uVar6;
  uVar6 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar8[0xd] = ((unsigned char *)0x00001047);
  puVar8[0xc] = uVar6;
  puVar8[0xe] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar8 + 0xf;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar8 + 0xf);
  return;
}

/* FUN_000879f0 @ 0x879f0 (732 bytes) */
int FUN_000879f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
  int param_7;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = 0;
  if (param_1 != 0) {
    iVar8 = *(int *)(param_1 + 0x276c);
  }
  _memset(param_5,0,0x80);
  iVar7 = 0;
  iVar9 = 8;
  uVar2 = 0;
  iVar3 = param_4;
  iVar5 = param_4;
  puVar6 = param_5;
  do {
    *puVar6 = 1;
    *(undefined1 *)((int)puVar6 + 0xb) = 0;
    *(undefined2 *)((int)puVar6 + 6) = 0;
    *(undefined1 *)((int)puVar6 + 0xe) = 0;
    *(undefined1 *)((int)puVar6 + 0xf) = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    *(undefined1 *)((int)puVar6 + 9) = 0;
    if (*(char *)(iVar7 + param_6) != '\0') {
      *(uint *)(iVar5 + 0x88) = *(uint *)(iVar5 + 0x88) & 0xfe001fff | 0xd10000;
      *(uint *)(iVar5 + 200) =
           (uVar2 + 3) * 0x40000 |
           (uVar2 + 2) * 0x1000 | (uVar2 + 1) * 0x40 | uVar2 | *(uint *)(iVar5 + 200) & 0xff000000;
      *(short *)(puVar6 + 1) = (short)iVar7 + 2;
      *(undefined1 *)((int)puVar6 + 9) = 1;
      *(char *)(puVar6 + 2) = (char)iVar7;
      *(undefined1 *)(puVar6 + 3) = 0;
    }
    puVar6 = puVar6 + 0x12;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 4;
    uVar2 = uVar2 + 4 & 0x3f;
    iVar3 = iVar3 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(char *)(param_3 + 0x118) != '\0') {
    *(undefined1 *)((int)param_5 + 0x24f) = 0;
    *(undefined1 *)((int)param_5 + 0x24b) = 0;
    uVar2 = iVar8 * 4;
    *(undefined1 *)((int)param_5 + 0x24a) = 0;
    *(undefined1 *)((int)param_5 + 0x24d) = 0;
    *(undefined1 *)((int)param_5 + 0x24e) = 0;
    *(undefined2 *)((int)param_5 + 0x246) = 0;
    *(undefined1 *)((int)param_5 + 0x249) = 1;
    param_5[0x90] = 1;
    iVar3 = 4;
    *(uint *)(uVar2 + param_4 + 0x88) = *(uint *)(uVar2 + param_4 + 0x88) & 0xfff81fff | 0x10000;
    if (*(int *)(param_4 + 0x210) != 2) {
      iVar3 = 2;
    }
    iVar5 = uVar2 + param_4;
    uVar4 = 0x3e;
    *(uint *)(iVar5 + 0x88) = iVar3 << 0x13 | *(uint *)(iVar5 + 0x88) & 0xfe07ffff | 0x1400000;
    *(uint *)(iVar5 + 200) =
         ((char)uVar2 + 1) * 0x40 & 0xfc0U | uVar2 & 0x3c | *(uint *)(iVar5 + 200) & 0xfffff000;
    if (*(int *)(param_4 + 0x210) != 2) {
      uVar4 = (int)(char)uVar2 + 2U & 0x3e;
    }
    *(uint *)(uVar2 + param_4 + 200) =
         uVar4 << 0xc | *(uint *)(uVar2 + param_4 + 200) & 0xff000fff | 0xfc0000;
    *(char *)(param_5 + 0x92) = (char)iVar8;
    uVar1 = *(undefined4 *)(param_3 + 0x108);
    *(undefined1 *)(param_5 + 0x93) = 0;
    *(short *)(param_5 + 0x91) = (short)uVar1;
  }
  *(undefined1 *)((int)param_5 + 10) = 0;
  *(undefined2 *)((int)param_5 + 6) = 0;
  *(undefined1 *)((int)param_5 + 0xb) = 1;
  *(undefined1 *)((int)param_5 + 0xd) = 0;
  *(uint *)(param_4 + 0x88) = *(uint *)(param_4 + 0x88) & 0xffffe03f;
  *(uint *)(param_4 + 200) = *(uint *)(param_4 + 200) & 0x80ffffff;
  if (param_7 == 0) {
    uVar1 = 1;
    iVar8 = 1;
  }
  else {
    uVar1 = 2;
    *(undefined1 *)((int)param_5 + 0x55) = 0;
    *(undefined1 *)((int)param_5 + 0x53) = 1;
    *(undefined1 *)((int)param_5 + 0x52) = 1;
    *(undefined2 *)((int)param_5 + 0x4e) = 1;
    iVar8 = 2;
    *(uint *)(param_4 + 0x8c) = *(uint *)(param_4 + 0x8c) & 0xffffe03f | 0x40;
    *(uint *)(param_4 + 0xcc) = *(uint *)(param_4 + 0xcc) & 0x80ffffff | 0x1000000;
  }
  *(undefined4 *)(param_4 + 0x20c) = uVar1;
  iVar3 = 0x48;
  *(undefined4 *)(param_4 + 0x214) = 0;
  *(uint *)(param_4 + 0x208) = iVar8 << 7 | *(uint *)(param_4 + 0x208) & 0xfffff87f;
  if (*(char *)(param_3 + 0x118) == '\0') {
    iVar3 = 0;
  }
  return (int)param_5 + iVar3 + 0x240;
}

/* FUN_00087e80 @ 0x87e80 (764 bytes) */
int FUN_00087e80(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar8 = param_3 + 0x124;
  uVar3 = param_1[0x8f8];
  *(undefined4 *)(((unsigned char *)0x000037cc) + param_3) = 0;
  ((unsigned char *)0x000037e8)[param_3] = (char)uVar3;
  if (param_3 == 0) {
    return 0;
  }
  *(int *)(((unsigned char *)0x000037e4) + param_3) = param_3;
  local_38 = 0;
  local_34 = 2;
  local_30 = 0;
  local_40 = 0;
  local_3c = 0;
  uVar3 = param_4[1];
  uVar5 = param_4[2];
  iVar6 = param_1[0x8f8];
  *(undefined4 *)(param_3 + 4) = *param_4;
  *(undefined4 *)(param_3 + 8) = uVar3;
  *(undefined4 *)(param_3 + 0xc) = uVar5;
  local_48 = param_4[2];
  local_44 = *param_4;
  if (param_2 != 0) {
    *(undefined4 *)(((unsigned char *)0x000011fc) + param_3) = 0;
    iVar9 = *(int *)(param_2 + 0x74);
    iVar4 = FUN_000abb60();
    if (iVar4 == 0x801) {
      local_3c = local_3c | 0xc;
    }
    else if (iVar4 == 0x2601) {
      local_3c = local_3c | 4;
    }
    else if (iVar4 == 0x800) {
      local_3c = local_3c | 8;
    }
    if (*(char *)(iVar9 + 5) != '\0') goto LAB_00088008;
  }
  else {
    local_3c = 2;
    _memset(((unsigned char *)0x00003100) + param_3,0,0x100);
    iVar9 = 0x10;
    iVar4 = iVar8;
    do {
      ((unsigned char *)0x00002fdc)[iVar4] = 1;
      iVar4 = iVar4 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(undefined4 *)(((unsigned char *)0x000011fc) + param_3) = 0;
  }
  iVar4 = param_1[0x917];
  if (iVar4 != 0) {
    local_38 = 0;
    do {
      local_38 = local_38 << 1 | 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    local_3c = local_3c | 0x400;
  }
LAB_00088008:
  if (iVar6 != 0) {
    local_3c = local_3c | 0x100;
    *(undefined4 *)(FUN_00001830 + param_3) = param_1[0x9db];
  }
  uVar2 = local_3c | 0x80;
  if (*(char *)(param_3 + 0x120) != '\0') {
    uVar2 = local_3c | 0x280;
  }
  local_3c = uVar2;
  iVar4 = FUN_000b4400(param_1,param_3 + 0x18a8,param_3 + 0x1784,&local_48,iVar8);
  if (iVar4 == 1) {
    return 0xfffffffe;
  }
  if (param_2 != 0) {
    if (iVar6 == 0) {
      iVar6 = *(int *)(((unsigned char *)0x000037cc) + param_3);
      iVar9 = *(int *)(((unsigned char *)0x000037d0) + param_3);
    }
    else {
      iVar6 = *(int *)(((unsigned char *)0x000037d8) + param_3);
      iVar9 = *(int *)(((unsigned char *)0x000037dc) + param_3);
    }
    if (iVar4 == 0) {
      *(undefined1 *)(param_2 + 0x6c) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 0x6c) = 0;
      *param_1 = 1;
    }
    uVar3 = *(undefined4 *)(((unsigned char *)0x00003874) + param_3);
    *(int *)(param_2 + 0x54) = iVar6;
    *(int *)(param_2 + 0x58) = iVar9;
    iVar7 = 0;
    *(undefined4 *)(param_2 + 100) = 0;
    *(undefined4 *)(param_2 + 0x5c) = uVar3;
    do {
      for (uVar2 = *(uint *)(((unsigned char *)0x000010b8) + iVar8); uVar2 != 0; uVar2 = uVar2 >> 1) {
        if ((uVar2 & 1) != 0) {
          *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
        }
      }
      bVar1 = iVar7 != 7;
      iVar8 = iVar8 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    *(int *)(param_2 + 0x68) = *(int *)(((unsigned char *)0x00003870) + param_3) + 1;
    uVar3 = *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x7c);
    *(int *)(param_2 + 0x50) = iVar6 + iVar9;
    *(undefined4 *)(param_2 + 0x60) = uVar3;
    *(undefined *)(param_2 + 2) = ((unsigned char *)0x000036d7)[param_3];
    *(undefined *)(param_2 + 1) = ((unsigned char *)0x000036d6)[param_3];
  }
  if (iVar4 == 0) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00088190 @ 0x88190 (740 bytes) */
int FUN_00088190(param_1, param_2)
  int param_1;
  char *param_2;
{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = param_2 + 0x124;
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      if (*(int *)(param_2 + 0x37cc) == 0) {
        ((int (*)())FUN_00087e80)(param_1,0,*(int *)(param_2 + 0x37e4),*(int *)(param_2 + 0x37e4) + 4);
        *param_2 = '\0';
      }
      pcVar4 = pcVar5;
      if (0 < *(int *)(param_2 + 0x37cc)) {
        *(char **)(param_1 + 0x1e70) = pcVar5;
        *(char **)(param_1 + 0x1e5c) = pcVar5;
        *(char **)(param_2 + 0x37e4) = param_2;
      }
    }
    else {
      if (*(int *)(param_2 + 0x37d8) == 0) {
        ((int (*)())FUN_00087e80)(param_1,0,*(int *)(param_2 + 0x37e4),*(int *)(param_2 + 0x37e4) + 4);
        *param_2 = '\0';
      }
      if (0 < *(int *)(param_2 + 0x37d8)) {
        *(char **)(param_1 + 0x1e70) = pcVar5;
        *(char **)(param_1 + 0x1e5c) = pcVar5;
        *(char **)(param_2 + 0x37e4) = param_2;
      }
      pcVar4 = param_2 + 0x140;
    }
    pcVar1 = *(char **)(((unsigned char *)0x00001488) + param_1);
    if ((pcVar1 != (char *)0x0) && (param_2 != pcVar1)) {
      *pcVar1 = '\0';
    }
    if (*param_2 == '\0') {
      iVar3 = *(int *)(param_1 + 0x2768);
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
      if ((iVar3 == 0) || (*(int *)(param_1 + 0x277c) == -1)) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x277c) * 4 + iVar3 + 0xc0);
      }
      *(undefined4 *)(param_2 + 0x164c) = uVar2;
      *(undefined4 *)(param_2 + 0x1208) = uVar2;
      param_2[0x1420] = '\0';
      param_2[0x1421] = '\0';
      param_2[0x1422] = '\0';
      param_2[0x1423] = '\0';
    }
    if (param_2 == *(char **)(((unsigned char *)0x00001488) + param_1)) {
      if ((param_2[0x36d7] != '\0') &&
         (((*(uint *)(param_1 + 0x38) & 0x400) != 0 || ((*(uint *)(param_1 + 0x3c) & 1) != 0)))) {
        FUN_000b51a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
      if ((param_2[0x3748] != '\0') && ((*(uint *)(param_1 + 0x38) & 0x100) != 0)) {
        FUN_000b5320(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
      if ((*(int *)(param_2 + 0x374c) != 0) &&
         (*(short *)(param_1 + 0x34) != 0 || *(short *)(param_1 + 0x32) != 0)) {
        FUN_000b50a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
        param_2[0x120f] = '\0';
      }
    }
    else {
      if (*(char *)(param_1 + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      }
      *(char **)(((unsigned char *)0x00001488) + param_1) = param_2;
      *param_2 = '\x01';
      pcVar4[0] = '\0';
      pcVar4[1] = '\0';
      pcVar4[2] = '\0';
      pcVar4[3] = '\0';
      param_2[0x1424] = '\0';
      param_2[0x1425] = '\0';
      param_2[0x1426] = '\0';
      param_2[0x1427] = '\0';
      param_2[0x120f] = '\0';
      if (param_2[0x36d7] != '\0') {
        FUN_000b51a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
      if (param_2[0x3748] != '\0') {
        FUN_000b5320(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
      if (*(int *)(param_2 + 0x374c) != 0) {
        FUN_000b50a0(param_1,param_2 + 0x18a8,param_2 + 0x1784);
      }
    }
    (**(code **)(param_1 + 0x294c))(param_1,pcVar5);
    if ((*(uint *)(param_1 + 0x1930) & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1);
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
    }
  }
  return 0;
}

/* FUN_00088480 @ 0x88480 (268 bytes) */
int FUN_00088480(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  pbVar4 = *(byte **)(param_1 + 8);
  iVar8 = 0;
  iVar3 = 0;
  iVar9 = *(int *)(param_1 + 0xc) - (int)pbVar4;
  iVar5 = DAT_001dbcd0 + -1;
  do {
    uVar2 = iVar8 + iVar5;
    iVar6 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
    if (iVar9 < 1) {
      bVar1 = iVar3 == 0;
LAB_000884dc:
      iVar7 = 0;
    }
    else {
      iVar3 = (uint)*pbVar4 - (int)(char)*(PTR_s_1D_001e9158)[iVar6 * 3];
      bVar1 = iVar3 == 0;
      if (!bVar1) goto LAB_000884dc;
      iVar7 = 0;
      iVar10 = iVar9;
      do {
        iVar7 = iVar7 + 1;
        iVar10 = iVar10 + -1;
        if (iVar10 == 0) {
          iVar3 = 0;
          goto LAB_0008855c;
        }
        iVar3 = (uint)pbVar4[iVar7] - (int)(char)(PTR_s_1D_001e9158)[iVar6 * 3][iVar7];
        bVar1 = false;
      } while (iVar3 == 0);
    }
    if (iVar3 < 1) {
      if (bVar1) {
LAB_0008855c:
        if ((PTR_s_1D_001e9158)[iVar6 * 3][iVar7] == '\0') {
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(&UNK_001e915c + iVar6 * 0xc);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(&UNK_001e9160 + iVar6 * 0xc);
          return;
        }
      }
      iVar5 = iVar6 + -1;
    }
    else {
      iVar8 = iVar6 + 1;
    }
    if (iVar5 < iVar8) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      return;
    }
  } while( true );
}

/* FUN_000885b0 @ 0x885b0 (860 bytes) */
int FUN_000885b0(param_1)
  int param_1;
{
  byte bVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  double dVar9;
  double dVar10;
  
  dVar3 = DOUBLE_001aa238;
  dVar9 = DOUBLE_001aa1e0;
  pbVar6 = *(byte **)(param_1 + 0xc);
  bVar1 = *pbVar6;
  dVar10 = DOUBLE_001aa228;
  while ((bVar1 - 0x30 & 0xff) < 10) {
    pbVar6 = pbVar6 + 1;
    *(byte **)(param_1 + 0xc) = pbVar6;
    dVar10 = dVar10 * dVar3 + ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar9);
    bVar1 = *pbVar6;
  }
  if ((bVar1 == 0x2e) && (pbVar7 = pbVar6 + 1, pbVar6[1] != 0x2e)) {
    *(byte **)(param_1 + 0xc) = pbVar7;
    dVar4 = DOUBLE_001aa220;
    dVar3 = DOUBLE_001aa1e0;
    bVar1 = pbVar6[1];
    dVar9 = DOUBLE_001aa220;
    while ((bVar1 - 0x30 & 0xff) < 10) {
      pbVar7 = pbVar7 + 1;
      *(byte **)(param_1 + 0xc) = pbVar7;
      dVar10 = dVar9 * ((double)CONCAT44(0x43300000,bVar1 - 0x30 ^ 0x80000000) - dVar3) + dVar10;
      dVar9 = dVar9 * dVar4;
      bVar1 = *pbVar7;
    }
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  pbVar6 = *(byte **)(param_1 + 0xc);
  if ((*pbVar6 != 0x45) && (*pbVar6 != 0x65)) goto LAB_0008886c;
  *(byte **)(param_1 + 0xc) = pbVar6 + 1;
  if (pbVar6[1] == 0x2d) {
    bVar2 = true;
    *(byte **)(param_1 + 0xc) = pbVar6 + 2;
  }
  else {
    bVar2 = false;
    if (pbVar6[1] == 0x2b) {
      *(byte **)(param_1 + 0xc) = pbVar6 + 2;
    }
  }
  pbVar6 = *(byte **)(param_1 + 0xc);
  uVar8 = (uint)*pbVar6;
  if ((uVar8 - 0x30 & 0xff) < 10) {
LAB_000887c4:
    iVar5 = 0;
    do {
      iVar5 = iVar5 * 10 + uVar8 + -0x30;
      if (1000 < iVar5) {
        iVar5 = 1000;
      }
      pbVar6 = pbVar6 + 1;
      *(byte **)(param_1 + 0xc) = pbVar6;
      uVar8 = (uint)*pbVar6;
    } while ((uVar8 - 0x30 & 0xff) < 10);
    dVar9 = DOUBLE_001aa200;
    if (0 < iVar5) {
      do {
        dVar9 = dVar9 * DOUBLE_001aa238;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      pbVar6 = *(byte **)(param_1 + 0xc);
    }
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"Invalid scientific notation.");
    pbVar6 = *(byte **)(param_1 + 0xc);
    uVar8 = (uint)*pbVar6;
    dVar9 = DOUBLE_001aa200;
    if ((uVar8 - 0x30 & 0xff) < 10) goto LAB_000887c4;
  }
  if (bVar2) {
    dVar9 = DOUBLE_001aa200 / dVar9;
  }
  dVar10 = dVar10 * dVar9;
  bVar2 = false;
LAB_0008886c:
  bVar1 = *pbVar6;
  if ((((byte)(bVar1 + 0xbf) < 0x1a) || ((byte)(bVar1 + 0x9f) < 0x1a)) || (bVar1 == 0x5f)) {
    ((int (*)())FUN_00088e70)(param_1,"invalid suffix on number");
  }
  *(double *)(param_1 + 0x1c) = dVar10;
  *(int *)(param_1 + 0x18) = (int)dVar10;
  if ((bVar2) && (dVar10 == (double)CONCAT44(0x43300000,(int)dVar10) - DOUBLE_001aa250)) {
    *(undefined4 *)(param_1 + 0x14) = 0xf;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x10;
  }
  return;
}

/* FUN_00088920 @ 0x88920 (892 bytes) */
int FUN_00088920(param_1)
  int param_1;
{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  bool bVar5;
  int iVar6;
  undefined1 *puVar7;
  
  puVar7 = *(undefined1 **)(param_1 + 0xc);
  puVar4 = *(undefined1 **)(param_1 + 0x10);
  if (puVar4 != puVar7) {
    bVar3 = false;
    bVar5 = false;
    bVar2 = false;
    iVar6 = (int)puVar4 - (int)puVar7;
    do {
      switch(*puVar7) {
      case 9:
      case 0x20:
        if ((!bVar5) && (!bVar3)) goto LAB_00088ae8;
        bVar3 = false;
        bVar5 = false;
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        break;
      case 10:
        if (bVar3) {
          bVar3 = true;
          bVar2 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        else {
          bVar3 = true;
          bVar2 = false;
        }
        break;
      default:
        if ((bVar5) || (bVar3)) {
          bVar3 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        if (!bVar2) goto LAB_00088afc;
LAB_00088ae8:
        bVar5 = false;
        break;
      case 0xd:
        if ((bVar5) || (bVar3)) {
          bVar3 = false;
          bVar5 = true;
          bVar2 = false;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        else {
          bVar5 = true;
          bVar2 = false;
        }
        break;
      case 0x23:
        if ((bVar5) || (bVar2 = true, bVar3)) {
          bVar3 = false;
          bVar5 = false;
          bVar2 = true;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
      }
      iVar6 = iVar6 + -1;
      puVar7 = puVar7 + 1;
      *(undefined1 **)(param_1 + 0xc) = puVar7;
    } while (iVar6 != 0);
  }
LAB_00088afc:
  if (puVar7 < puVar4) {
    *(undefined1 **)(param_1 + 8) = puVar7;
    switch(*puVar7) {
    case 0x2b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x19;
      break;
    case 0x2c:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x13;
      break;
    case 0x2d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x1a;
      break;
    case 0x2e:
      if (puVar7[1] == '.') {
        *(undefined1 **)(param_1 + 0xc) = puVar7 + 2;
        *(undefined4 *)(param_1 + 0x14) = 0x12;
      }
      else {
        if ((byte)(puVar7[1] - 0x30) < 10) goto switchD_00088b48_caseD_30;
        *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
        *(undefined4 *)(param_1 + 0x14) = 0x11;
      }
      break;
    default:
      ((int (*)())FUN_00088e70)(param_1,"invalid character");
      return;
    case 0x31:
    case 0x32:
    case 0x33:
      if (puVar7[1] == 'D') {
        do {
          do {
            puVar4 = puVar7 + 1;
            *(undefined1 **)(param_1 + 0xc) = puVar4;
            cVar1 = puVar7[1];
            puVar7 = puVar4;
          } while ((byte)(cVar1 + 0xbfU) < 0x1a);
        } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'))
        ;
        goto LAB_00088d48;
      }
    case 0x30:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
switchD_00088b48_caseD_30:
      ((int (*)())FUN_000885b0)();
      return;
    case 0x3b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x14;
      break;
    case 0x3d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x1b;
      break;
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5f:
    case 0x61:
    case 0x62:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
      do {
        do {
          puVar4 = puVar7 + 1;
          *(undefined1 **)(param_1 + 0xc) = puVar4;
          cVar1 = puVar7[1];
          puVar7 = puVar4;
        } while ((byte)(cVar1 + 0xbfU) < 0x1a);
      } while ((((byte)(cVar1 + 0x9fU) < 0x1a) || ((byte)(cVar1 - 0x30U) < 10)) || (cVar1 == '_'));
LAB_00088d48:
      ((int (*)())FUN_00088480)();
      return;
    case 0x5b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x15;
      break;
    case 0x5d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x16;
      break;
    case 0x7b:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x17;
      break;
    case 0x7d:
      *(undefined1 **)(param_1 + 0xc) = puVar7 + 1;
      *(undefined4 *)(param_1 + 0x14) = 0x18;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x1c;
  }
  return;
}

/* FUN_00088e70 @ 0x88e70 (112 bytes) */
int FUN_00088e70(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  if ((int)param_1[10] < 0) {
    param_1[0xc] = param_2;
    param_1[0xb] = param_1[9];
    param_1[10] = param_1[2] - param_1[1];
  }
  param_1[3] = param_1[4];
  ((int (*)())FUN_00088920)();
  *(undefined4 *)*param_1 = 0x502;
  return;
}

/* FUN_00088ee0 @ 0x88ee0 (28 bytes) */
int FUN_00088ee0(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_00088e70)(param_1,"out of memory");
  return;
}

/* FUN_00088f00 @ 0x88f00 (184 bytes) */
int FUN_00088f00(param_1)
  int *param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    ((int (*)())FUN_00088ee0)(param_1);
  }
  else {
    puVar1[5] = puVar1 + 6;
    puVar1[10] = 0;
    puVar1[6] = 4;
    puVar1[2] = 0;
    puVar1[8] = 0x36;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[7] = 0;
    puVar1[9] = 0;
    if (param_1[0x11] == 0) {
      param_1[0x11] = (int)puVar1;
    }
    else {
      *(undefined4 **)param_1[0x12] = puVar1;
    }
    param_1[0x12] = (int)puVar1;
  }
  return puVar1;
}

/* FUN_00088fd0 @ 0x88fd0 (332 bytes) */
int FUN_00088fd0(param_1)
  int param_1;
{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pcVar2 = *(char **)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc) - (int)pcVar2;
  if (*(int *)(param_1 + 0x14) == 0) {
    piVar1 = *(int **)(param_1 + 0x3c);
    if (piVar1 != (int *)0x0) {
      do {
        if (iVar4 == piVar1[2]) {
          if (iVar4 < 1) {
            if (iVar4 == 0) {
              return piVar1;
            }
          }
          else if (*pcVar2 == *(char *)piVar1[1]) {
            iVar3 = 0;
            iVar5 = iVar4;
            do {
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + -1;
              if (iVar5 == 0) {
                return piVar1;
              }
            } while (pcVar2[iVar3] == ((char *)piVar1[1])[iVar3]);
          }
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
    piVar1 = *(int **)(param_1 + 0x4c);
    if (piVar1 != (int *)0x0) {
      do {
        if (iVar4 == piVar1[2]) {
          if (iVar4 < 1) {
            if (iVar4 == 0) {
LAB_00089104:
              return (int *)piVar1[3];
            }
          }
          else if (*pcVar2 == *(char *)piVar1[1]) {
            iVar3 = 0;
            iVar5 = iVar4;
            do {
              iVar3 = iVar3 + 1;
              iVar5 = iVar5 + -1;
              if (iVar5 == 0) goto LAB_00089104;
            } while (pcVar2[iVar3] == ((char *)piVar1[1])[iVar3]);
          }
        }
        piVar1 = (int *)*piVar1;
      } while (piVar1 != (int *)0x0);
    }
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"invalid variable name");
  }
  return (int *)0x0;
}

/* FUN_00089140 @ 0x89140 (28 bytes) */
int FUN_00089140(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_00088e70)(param_1,"internal error");
  return;
}

/* FUN_00089160 @ 0x89160 (44 bytes) */
int FUN_00089160(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(param_1 + 0x14) == param_2) {
    ((int (*)())FUN_00088920)();
    return;
  }
  ((int (*)())FUN_00088e70)(param_1,"unexpected token");
  return;
}

/* FUN_00089190 @ 0x89190 (124 bytes) */
int FUN_00089190(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0x61:
  case 0x77:
    uVar1 = 3;
    break;
  case 0x62:
  case 0x7a:
    uVar1 = 2;
    break;
  default:
    ((int (*)())FUN_00088e70)(param_1,"invalid component");
  case 0x72:
  case 0x78:
    uVar1 = 0;
    break;
  case 0x67:
  case 0x79:
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_00089280 @ 0x89280 (156 bytes) */
int FUN_00089280(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0xc) != 0) {
    uVar2 = *(uint *)(param_2 + 0x10);
    if (uVar2 < *(uint *)(param_2 + 0xc)) {
      *(uint *)(param_2 + 0x10) = uVar2 + 1;
      puVar1 = (undefined4 *)(uVar2 * 0x14 + *(int *)(param_2 + 0x14));
    }
    else {
      ((int (*)())FUN_00088e70)(param_1,"too many array initializers");
      puVar1 = (undefined4 *)(param_2 + 0x18);
    }
  }
  *puVar1 = 4;
  puVar1[4] = 0;
  puVar1[2] = 0x36;
  puVar1[1] = 0;
  puVar1[3] = 0;
  return puVar1;
}

/* FUN_00089320 @ 0x89320 (264 bytes) */
int FUN_00089320(param_1, param_2)
  int *param_1;
  float *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = param_1[0x9116];
  iVar6 = 0;
  if (iVar7 != 0) {
    pfVar4 = (float *)(param_1 + 0x9016);
    iVar5 = 0;
    iVar8 = iVar7;
    do {
      if ((((*pfVar4 == *param_2) && (pfVar4[1] == param_2[1])) && (pfVar4[2] == param_2[2])) &&
         (pfVar4[3] == param_2[3])) {
        return iVar5;
      }
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 4;
      iVar8 = iVar8 + -1;
      iVar6 = iVar7;
    } while (iVar8 != 0);
  }
  if (iVar6 < *(int *)(((unsigned char *)0x000011e4) + *param_1)) {
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    param_1[iVar7 * 4 + 0x9019] = (int)param_2[3];
    param_1[iVar7 * 4 + 0x9016] = (int)fVar1;
    param_1[iVar7 * 4 + 0x9017] = (int)fVar2;
    param_1[iVar7 * 4 + 0x9018] = (int)fVar3;
    param_1[0x9116] = param_1[0x9116] + 1;
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"too many constants");
    iVar7 = 0;
  }
  return iVar7;
}

/* FUN_00089430 @ 0x89430 (348 bytes) */
int FUN_00089430(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1[5] == 0) {
    iVar1 = param_1[6];
    if ((((iVar1 == 0xc) || (iVar1 == 0x1d)) || (iVar1 == 0x20)) ||
       ((iVar1 == 0x27 || (iVar1 == 0x2a)))) {
      puVar2 = (undefined4 *)0x0;
      ((int (*)())FUN_00088e70)(param_1,"reserved variable name");
    }
    else {
      iVar1 = ((int (*)())FUN_00088fd0)();
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)(**(code **)(*param_1 + 0xc))(0x2c);
        if (puVar2 == (undefined4 *)0x0) {
          ((int (*)())FUN_00088ee0)(param_1);
        }
        else {
          puVar2[2] = param_1[3] - param_1[2];
          iVar1 = param_1[2];
          puVar2[5] = puVar2 + 6;
          puVar2[6] = 4;
          puVar2[8] = 0x36;
          puVar2[10] = 0;
          *puVar2 = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          puVar2[1] = iVar1;
          puVar2[7] = 0;
          puVar2[9] = 0;
          if (param_1[0xf] == 0) {
            param_1[0xf] = (int)puVar2;
          }
          else {
            *(undefined4 **)param_1[0x10] = puVar2;
          }
          param_1[0x10] = (int)puVar2;
        }
      }
      else {
        puVar2 = (undefined4 *)0x0;
        ((int (*)())FUN_00088e70)(param_1,"redeclared variable name");
      }
    }
  }
  else {
    ((int (*)())FUN_00089140)();
    puVar2 = (undefined4 *)0x0;
  }
  ((int (*)())FUN_00088920)(param_1);
  return puVar2;
}

/* FUN_000895b0 @ 0x895b0 (364 bytes) */
int FUN_000895b0(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  if ((param_1[5] != 0) || (param_1[6] != 0x20)) {
    ((int (*)())FUN_00088e70)(param_1,"invalid result binding");
  }
  ((int (*)())FUN_00088920)(param_1);
  ((int (*)())FUN_00089160)(param_1,0x11);
  if (param_1[5] == 0) {
    param_2[2] = 0x35;
    *param_2 = 3;
    if (param_1[6] == 4) {
      ((int (*)())FUN_00088920)(param_1);
      param_2[1] = 0;
      if (*(char *)((int)param_1 + 0x3a) == '\0') {
        param_2[3] = 0;
      }
      else {
        iVar1 = 0;
        if (param_1[5] == 0x15) {
          ((int (*)())FUN_00088920)(param_1);
          if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
             (iVar1 < (int)(uint)(byte)((unsigned char *)0x000013b3)[*param_1])) {
            ((int (*)())FUN_00088920)(param_1);
          }
          else {
            iVar1 = 0;
            ((int (*)())FUN_00088e70)(param_1,"invalid output color");
          }
          ((int (*)())FUN_00089160)(param_1,0x16);
        }
        param_2[3] = iVar1;
      }
    }
    else {
      if (param_1[6] != 5) goto LAB_00089638;
      ((int (*)())FUN_00088920)(param_1);
      param_2[1] = 1;
    }
    return;
  }
LAB_00089638:
  ((int (*)())FUN_00088e70)(param_1,"invalid result binding");
  return;
}

/* FUN_00089740 @ 0x89740 (88 bytes) */
int FUN_00089740(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x19) {
    ((int (*)())FUN_00088920)();
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    if (*(int *)(param_1 + 0x14) == 0x1a) {
      ((int (*)())FUN_00088920)();
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

/* FUN_000897b0 @ 0x897b0 (164 bytes) */
double FUN_000897b0(int param_1)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  
  uVar1 = ((int (*)())FUN_00089740)();
  dVar2 = DOUBLE_001aa228;
  dVar3 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_001aa1e0;
  if (*(int *)(param_1 + 0x14) - 0xfU < 2) {
    dVar2 = *(double *)(param_1 + 0x1c);
    ((int (*)())FUN_00088920)(param_1);
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,"invalid constant");
  }
  return dVar2 * dVar3;
}

/* FUN_00089a20 @ 0x89a20 (144 bytes) */
int FUN_00089a20(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(((unsigned char *)0x000011fc) + *param_1))) {
    ((int (*)())FUN_00088920)();
  }
  else {
    iVar1 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid program local parameter number");
  }
  return iVar1;
}

/* FUN_00089ac0 @ 0x89ac0 (144 bytes) */
int FUN_00089ac0(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(((unsigned char *)0x00001200) + *param_1))) {
    ((int (*)())FUN_00088920)();
  }
  else {
    iVar1 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid program environment parameter number");
  }
  return iVar1;
}

/* FUN_00089b60 @ 0x89b60 (168 bytes) */
int FUN_00089b60(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_1[5] == 0x15) {
    ((int (*)())FUN_00088920)();
    if (((param_1[5] != 0xf) || (iVar1 = param_1[6], iVar1 < 0)) ||
       ((int)(uint)(byte)((unsigned char *)0x000013b0)[*param_1] <= iVar1)) {
      ((int (*)())FUN_00088e70)(param_1,"invalid texture coordinate");
      iVar1 = param_1[6];
    }
    ((int (*)())FUN_00088920)(param_1);
    ((int (*)())FUN_00089160)(param_1,0x16);
  }
  return iVar1;
}

/* FUN_00089c10 @ 0x89c10 (128 bytes) */
int FUN_00089c10(param_1)
  int param_1;
{
  uint uVar1;
  
  if (((*(int *)(param_1 + 0x14) == 0xf) && (uVar1 = *(uint *)(param_1 + 0x18), -1 < (int)uVar1)) &&
     (uVar1 < 4)) {
    ((int (*)())FUN_00088920)();
  }
  else {
    uVar1 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid matrix row number");
  }
  return uVar1;
}

/* FUN_00089ca0 @ 0x89ca0 (144 bytes) */
int FUN_00089ca0(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < (int)(uint)(byte)((unsigned char *)0x000013b5)[*param_1])) {
    ((int (*)())FUN_00088920)();
  }
  else {
    iVar1 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid light number");
  }
  return iVar1;
}

/* FUN_0008aa40 @ 0x8aa40 (3780 bytes) */
int FUN_0008aa40(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  double dVar12;
  float local_28;
  float local_24;
  float local_20;
  
  if (0x1a < (uint)param_1[5]) {
LAB_0008aaa0:
    pcVar9 = "invalid parameter binding";
    goto LAB_0008ab20;
  }
  uVar2 = 1 << (param_1[5] & 0x3fU);
  if ((uVar2 & 0x818000) == 0) {
    if ((uVar2 & 1) != 0) {
      if (param_1[6] == 0x1d) {
        ((int (*)())FUN_00088920)();
        ((int (*)())FUN_00089160)(param_1,0x11);
        puVar3 = (undefined4 *)((int (*)())FUN_00089280)(param_1,param_2);
        *puVar3 = 2;
        if (param_1[5] == 0) {
          if (param_1[6] == 9) {
            puVar3[2] = 0x32;
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x15);
            iVar6 = ((int (*)())FUN_00089ac0)(param_1);
            iVar7 = iVar6;
            if ((param_3 == 0) || (param_1[5] != 0x12)) {
LAB_0008abb4:
              ((int (*)())FUN_00089160)(param_1,0x16);
              puVar3[3] = iVar6;
              while (iVar6 = iVar6 + 1, iVar6 <= iVar7) {
                puVar8 = (undefined4 *)((int (*)())FUN_00089280)(param_1,param_2);
                uVar4 = puVar3[1];
                uVar10 = puVar3[2];
                uVar11 = puVar3[3];
                *puVar8 = *puVar3;
                puVar8[1] = uVar4;
                puVar8[3] = uVar11;
                puVar8[2] = uVar10;
                uVar4 = puVar3[4];
                puVar8[3] = iVar6;
                puVar8[4] = uVar4;
                puVar3 = puVar8;
              }
              return;
            }
            ((int (*)())FUN_00088920)(param_1);
            iVar7 = ((int (*)())FUN_00089ac0)(param_1);
            if (iVar6 <= iVar7) goto LAB_0008abb4;
          }
          else {
            if (param_1[6] != 0x14) goto LAB_0008ab0c;
            puVar3[2] = 0x33;
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x15);
            iVar6 = ((int (*)())FUN_00089a20)(param_1);
            iVar7 = iVar6;
            if ((param_3 == 0) || (param_1[5] != 0x12)) goto LAB_0008abb4;
            ((int (*)())FUN_00088920)(param_1);
            iVar7 = ((int (*)())FUN_00089a20)(param_1);
            if (iVar6 <= iVar7) goto LAB_0008abb4;
          }
          pcVar9 = "invalid program parameter range";
        }
        else {
LAB_0008ab0c:
          pcVar9 = "invalid program parameter type";
        }
LAB_0008ab20:
        ((int (*)())FUN_00088e70)(param_1,pcVar9);
        return;
      }
      if (param_1[6] != 0x27) {
        pcVar9 = "invalid parameter binding";
        goto LAB_0008ab20;
      }
      ((int (*)())FUN_00088920)();
      ((int (*)())FUN_00089160)(param_1,0x11);
      if (param_1[5] != 0) {
        ((int (*)())FUN_00088e70)(param_1,"invalid state binding");
      }
      puVar3 = (undefined4 *)((int (*)())FUN_00089280)(param_1,param_2);
      *puVar3 = 2;
      switch(param_1[6]) {
      case 5:
        if (param_1[5] != 0) {
LAB_0008a570:
          ((int (*)())FUN_00089140)(param_1);
          return;
        }
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x11);
        if ((param_1[5] == 0) && (param_1[6] == 0x1f)) {
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x18;
          return;
        }
        pcVar9 = "invalid depth property";
        break;
      default:
        pcVar9 = "invalid state binding";
        break;
      case 10:
        if (param_1[5] != 0) goto LAB_0008a570;
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x11);
        if (param_1[5] == 0) {
          if (param_1[6] == 4) {
            ((int (*)())FUN_00088920)(param_1);
            puVar3[2] = 0x16;
            return;
          }
          if (param_1[6] == 0x1a) {
            ((int (*)())FUN_00088920)(param_1);
            puVar3[2] = 0x17;
            return;
          }
        }
        pcVar9 = "invalid fog property";
        break;
      case 0x11:
        if (param_1[5] != 0) goto LAB_0008a570;
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x15);
        uVar4 = ((int (*)())FUN_00089ca0)(param_1);
        puVar3[3] = uVar4;
        ((int (*)())FUN_00089160)(param_1,0x16);
        ((int (*)())FUN_00089160)(param_1,0x11);
        if (param_1[5] == 0) {
          switch(param_1[6]) {
          default:
            goto switchD_0008a094_caseD_0;
          case 1:
            uVar4 = 10;
            break;
          case 2:
            uVar4 = 0xe;
            break;
          case 6:
            uVar4 = 0xb;
            break;
          case 0xe:
            uVar4 = 0x10;
            break;
          case 0x1b:
            uVar4 = 0xd;
            break;
          case 0x25:
            uVar4 = 0xc;
            break;
          case 0x26:
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x11);
            if ((param_1[5] != 0) || (param_1[6] != 7)) {
              pcVar9 = "invalid spot light property";
              goto LAB_0008a9fc;
            }
            uVar4 = 0xf;
          }
LAB_00089fc4:
          puVar3[2] = uVar4;
          ((int (*)())FUN_00088920)(param_1);
          return;
        }
switchD_0008a094_caseD_0:
        pcVar9 = "invalid light property";
        break;
      case 0x12:
        if (param_1[5] != 0) {
          ((int (*)())FUN_00089140)(param_1);
        }
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x11);
        if (param_1[5] == 0) {
          puVar3[3] = 0;
          iVar6 = param_1[6];
          if (iVar6 == 3) {
            puVar3[3] = 1;
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x11);
          }
          else if (iVar6 == 0xd) {
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x11);
          }
          else if (iVar6 == 1) {
            uVar4 = 0x11;
            goto LAB_00089fc4;
          }
          if ((param_1[5] == 0) && (param_1[6] == 0x22)) {
            uVar4 = 0x12;
            goto LAB_00089fc4;
          }
        }
        pcVar9 = "invalid light model property";
        break;
      case 0x13:
        if (param_1[5] != 0) goto LAB_0008a570;
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x15);
        uVar4 = ((int (*)())FUN_00089ca0)(param_1);
        puVar3[3] = uVar4;
        ((int (*)())FUN_00089160)(param_1,0x16);
        ((int (*)())FUN_00089160)(param_1,0x11);
        puVar3[4] = 0;
        if (param_1[5] == 0) {
          if (param_1[6] == 3) {
            puVar3[4] = 1;
LAB_0008a31c:
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x11);
            if (param_1[5] != 0) goto LAB_0008a38c;
          }
          else if (param_1[6] == 0xd) goto LAB_0008a31c;
          iVar6 = param_1[6];
          if (iVar6 == 6) {
            uVar4 = 0x14;
            goto LAB_00089fc4;
          }
          if (iVar6 == 0x25) {
            uVar4 = 0x15;
            goto LAB_00089fc4;
          }
          if (iVar6 == 1) {
            uVar4 = 0x13;
            goto LAB_00089fc4;
          }
        }
LAB_0008a38c:
        pcVar9 = "invalid light product property";
        break;
      case 0x15:
        if (param_1[5] != 0) goto LAB_0008a570;
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x11);
        puVar3[3] = 0;
        if (param_1[5] == 0) {
          if (param_1[6] == 3) {
            puVar3[3] = 1;
LAB_00089ec0:
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x11);
            if (param_1[5] != 0) goto switchD_00089f14_caseD_0;
          }
          else if (param_1[6] == 0xd) goto LAB_00089ec0;
          switch(param_1[6]) {
          default:
            goto switchD_00089f14_caseD_0;
          case 1:
            uVar4 = 5;
            break;
          case 6:
            uVar4 = 6;
            break;
          case 8:
            uVar4 = 8;
            break;
          case 0x24:
            uVar4 = 9;
            break;
          case 0x25:
            uVar4 = 7;
          }
          goto LAB_00089fc4;
        }
switchD_00089f14_caseD_0:
        pcVar9 = "invalid material property";
        break;
      case 0x16:
        if (param_1[5] != 0) goto LAB_0008a570;
        ((int (*)())FUN_00088920)(param_1);
        ((int (*)())FUN_00089160)(param_1,0x11);
        if (param_1[5] != 0) {
          ((int (*)())FUN_00088e70)(param_1,"invalid matrix property");
        }
        switch(param_1[6]) {
        case 0x17:
          iVar6 = 0;
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x1a;
          if (param_1[5] == 0x15) {
            ((int (*)())FUN_00088920)(param_1);
            if (((param_1[5] == 0xf) && (iVar6 = param_1[6], -1 < iVar6)) &&
               (iVar6 < (int)(uint)(byte)((unsigned char *)0x000013b4)[*param_1])) {
              ((int (*)())FUN_00088920)(param_1);
            }
            else {
              iVar6 = 0;
              ((int (*)())FUN_00088e70)(param_1,"invalid modelview matrix number");
            }
            ((int (*)())FUN_00089160)(param_1,0x16);
          }
          puVar3[3] = iVar6;
          break;
        case 0x18:
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x22;
          break;
        case 0x19:
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x2a;
          ((int (*)())FUN_00089160)(param_1,0x15);
          ((int (*)())FUN_00088e70)(param_1,"invalid palette matrix number");
          puVar3[3] = 0;
          ((int (*)())FUN_00089160)(param_1,0x16);
          break;
        default:
          ((int (*)())FUN_00088e70)(param_1,"invalid matrix property");
          break;
        case 0x1d:
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x2e;
          ((int (*)())FUN_00089160)(param_1,0x15);
          if (((param_1[5] == 0xf) && (iVar6 = param_1[6], -1 < iVar6)) &&
             (iVar6 < *(int *)(((unsigned char *)0x0000149c) + *param_1))) {
            ((int (*)())FUN_00088920)(param_1);
          }
          else {
            iVar6 = 0;
            ((int (*)())FUN_00088e70)(param_1,"invalid program matrix number");
          }
          puVar3[3] = iVar6;
          ((int (*)())FUN_00089160)(param_1,0x16);
          break;
        case 0x1e:
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x1e;
          break;
        case 0x2a:
          ((int (*)())FUN_00088920)(param_1);
          puVar3[2] = 0x26;
          uVar4 = ((int (*)())FUN_00089b60)(param_1);
          puVar3[3] = uVar4;
        }
        if (param_1[5] == 0x11) {
          ((int (*)())FUN_00088920)(param_1);
          if (param_1[5] != 0) {
            pcVar9 = "invalid matrix modifier";
            break;
          }
          iVar6 = param_1[6];
          if (iVar6 == 0x10) {
            ((int (*)())FUN_00088920)(param_1);
            bVar1 = param_1[5] != 0x11;
            if (!bVar1) {
              ((int (*)())FUN_00088920)(param_1);
            }
            puVar3[4] = 3;
LAB_0008a838:
            if (bVar1) goto LAB_0008a960;
          }
          else {
            if (iVar6 == 0x2b) {
              ((int (*)())FUN_00088920)(param_1);
              bVar1 = param_1[5] != 0x11;
              if (!bVar1) {
                ((int (*)())FUN_00088920)(param_1);
              }
              puVar3[4] = 2;
              goto LAB_0008a838;
            }
            if (iVar6 == 0xf) {
              ((int (*)())FUN_00088920)(param_1);
              bVar1 = param_1[5] != 0x11;
              if (!bVar1) {
                ((int (*)())FUN_00088920)(param_1);
              }
              puVar3[4] = 1;
              goto LAB_0008a838;
            }
            puVar3[4] = 0;
          }
          if ((param_1[5] == 0) && (param_1[6] == 0x21)) {
            ((int (*)())FUN_00088920)(param_1);
            ((int (*)())FUN_00089160)(param_1,0x15);
            iVar5 = ((int (*)())FUN_00089c10)(param_1);
            iVar7 = iVar5;
            if ((param_3 != 0) && (param_1[5] == 0x12)) {
              ((int (*)())FUN_00088920)(param_1);
              iVar7 = ((int (*)())FUN_00089c10)(param_1);
              if (iVar7 < iVar5) {
                pcVar9 = "invalid matrix row range";
                break;
              }
            }
            iVar6 = iVar5 + 1;
            ((int (*)())FUN_00089160)(param_1,0x16);
LAB_0008a984:
            puVar3[2] = iVar5 + puVar3[2];
            for (; iVar6 <= iVar7; iVar6 = iVar6 + 1) {
              puVar8 = (undefined4 *)((int (*)())FUN_00089280)(param_1,param_2);
              iVar5 = puVar3[2];
              uVar4 = *puVar3;
              uVar10 = puVar3[1];
              uVar11 = puVar3[3];
              puVar8[2] = iVar5;
              *puVar8 = uVar4;
              puVar8[1] = uVar10;
              puVar8[3] = uVar11;
              uVar4 = puVar3[4];
              puVar8[2] = iVar5 + 1;
              puVar8[4] = uVar4;
              puVar3 = puVar8;
            }
            return;
          }
          pcVar9 = "invalid matrix row selector";
        }
        else {
LAB_0008a960:
          if (param_3 != 0) {
            iVar7 = 3;
            iVar5 = 0;
            iVar6 = 1;
            goto LAB_0008a984;
          }
          pcVar9 = "missing matrix row selector";
        }
        break;
      case 0x29:
        if (param_1[5] != 0) goto LAB_0008a570;
        iVar6 = 0;
        ((int (*)())FUN_00088920)(param_1);
        if (param_1[5] == 0x15) {
          ((int (*)())FUN_00088920)(param_1);
          if (((param_1[5] != 0xf) || (iVar6 = param_1[6], iVar6 < 0)) ||
             ((int)(uint)(byte)((unsigned char *)0x000013b2)[*param_1] <= iVar6)) {
            ((int (*)())FUN_00088e70)(param_1,"invalid legacy texture unit");
            iVar6 = param_1[6];
          }
          ((int (*)())FUN_00088920)(param_1);
          ((int (*)())FUN_00089160)(param_1,0x16);
        }
        puVar3[3] = iVar6;
        ((int (*)())FUN_00089160)(param_1,0x11);
        if ((param_1[5] == 0) && (param_1[6] == 4)) {
          uVar4 = 0x19;
          goto LAB_00089fc4;
        }
        pcVar9 = "invalid texenv property";
      }
LAB_0008a9fc:
      ((int (*)())FUN_00088e70)(param_1,pcVar9);
      return;
    }
    if ((uVar2 & 0x6000000) == 0) goto LAB_0008aaa0;
    if (param_4 == 0) {
      pcVar9 = "consecutive sign operators";
      goto LAB_0008ab20;
    }
  }
  puVar3 = (undefined4 *)((int (*)())FUN_00089280)();
  puVar3[2] = 0x34;
  *puVar3 = 2;
  if (0x1a < (uint)param_1[5]) {
LAB_000898c0:
    ((int (*)())FUN_00088e70)(param_1,"invalid constant");
    return;
  }
  uVar2 = 1 << (param_1[5] & 0x3fU);
  if ((uVar2 & 0x6018000) != 0) {
    dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
    local_28 = (float)dVar12;
    local_24 = local_28;
    local_20 = local_28;
    uVar4 = ((int (*)())FUN_00089320)(param_1,&local_28);
    puVar3[3] = uVar4;
    return;
  }
  if ((uVar2 & 0x800000) == 0) goto LAB_000898c0;
  ((int (*)())FUN_00088920)(param_1);
  local_20 = 0.0;
  local_24 = 0.0;
  dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
  local_28 = (float)dVar12;
  if (param_1[5] == 0x13) {
    ((int (*)())FUN_00088920)(param_1);
    dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
    local_24 = (float)dVar12;
    if (param_1[5] == 0x13) {
      ((int (*)())FUN_00088920)(param_1);
      dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
      local_20 = (float)dVar12;
      if (param_1[5] == 0x13) {
        ((int (*)())FUN_00088920)(param_1);
        ((double (*)())FUN_000897b0)(param_1);
        goto LAB_000899e0;
      }
    }
  }
  if ((param_1[10] < 0) && (param_1[0xb] == -1)) {
    param_1[0xb] = param_1[9];
    param_1[0xc] = (int)
                   "warning: <paramConstVector> rule match where parser is supplying some default component(s)"
    ;
  }
LAB_000899e0:
  ((int (*)())FUN_00089160)(param_1,0x18);
  uVar4 = ((int (*)())FUN_00089320)(param_1,&local_28);
  puVar3[3] = uVar4;
  return;
}

/* FUN_0008ace0 @ 0x8ace0 (464 bytes) */
int FUN_0008ace0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x18) == 0xc)) {
    *(undefined4 *)(param_2 + 0x18) = 1;
    ((int (*)())FUN_00088920)();
    ((int (*)())FUN_00089160)(param_1,0x11);
    if (*(int *)(param_1 + 0x14) != 0) {
      ((int (*)())FUN_00088e70)(param_1,"invalid fragment attribute binding item");
    }
    uVar1 = *(uint *)(param_1 + 0x18);
    if (uVar1 == 0xb) {
      ((int (*)())FUN_00088920)(param_1);
      *(undefined4 *)(param_2 + 0x20) = 3;
      return;
    }
    if (uVar1 < 0xc) {
      if (uVar1 == 4) {
        ((int (*)())FUN_00088920)(param_1);
        *(undefined4 *)(param_2 + 0x20) = 1;
        uVar2 = 0;
        if (*(int *)(param_1 + 0x14) == 0x11) {
          ((int (*)())FUN_00088920)(param_1);
          if (*(int *)(param_1 + 0x14) == 0) {
            if (*(int *)(param_1 + 0x18) == 0x1c) {
              ((int (*)())FUN_00088920)(param_1);
              uVar2 = 0;
            }
            else if (*(int *)(param_1 + 0x18) == 0x23) {
              ((int (*)())FUN_00088920)(param_1);
              uVar2 = 1;
            }
            else {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + -1;
              ((int (*)())FUN_00088920)(param_1);
              uVar2 = 0;
            }
          }
          else {
            ((int (*)())FUN_00088e70)(param_1,"invalid color type");
            uVar2 = 0;
          }
        }
        *(undefined4 *)(param_2 + 0x24) = uVar2;
        return;
      }
    }
    else {
      if (uVar1 == 0x1b) {
        ((int (*)())FUN_00088920)(param_1);
        *(undefined4 *)(param_2 + 0x20) = 4;
        return;
      }
      if (uVar1 == 0x28) {
        ((int (*)())FUN_00088920)(param_1);
        *(undefined4 *)(param_2 + 0x20) = 2;
        uVar2 = ((int (*)())FUN_00089b60)(param_1);
        *(undefined4 *)(param_2 + 0x24) = uVar2;
        return;
      }
    }
    pcVar3 = "invalid fragment attribute binding item";
  }
  else {
    pcVar3 = "invalid fragment attribute binding";
  }
  ((int (*)())FUN_00088e70)(param_1,pcVar3);
  return;
}

/* FUN_0008aec0 @ 0x8aec0 (136 bytes) */
int FUN_0008aec0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) &&
     (*(int *)(param_1 + 0xc) - (int)*(undefined1 **)(param_1 + 8) == 1)) {
    uVar1 = ((int (*)())FUN_00089190)(param_1,**(undefined1 **)(param_1 + 8));
    ((int (*)())FUN_00088920)(param_1);
  }
  else {
    uVar1 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid component");
  }
  return uVar1;
}

/* FUN_0008b160 @ 0x8b160 (864 bytes) */
int FUN_0008b160(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x14);
  if (uVar4 < 0x11) {
    if (0xe < uVar4) goto LAB_0008b1f0;
    if (uVar4 != 0) goto LAB_0008b1a0;
    iVar1 = *(int *)(param_1 + 0x18);
    if ((iVar1 == 0x1d) || (iVar1 == 0x27)) goto LAB_0008b1f0;
    if (iVar1 == 0xc) {
      iVar1 = ((int (*)())FUN_00088f00)();
      if (iVar1 == 0) {
        return;
      }
LAB_0008b270:
      *param_2 = iVar1;
      if (*(int *)(param_1 + 0x14) != 0) {
        ((int (*)())FUN_00089140)();
        return;
      }
      if (*(int *)(param_1 + 0x18) == 0xc) {
        ((int (*)())FUN_0008ace0)();
      }
      else {
        ((int (*)())FUN_00088920)(param_1,iVar1);
      }
      param_2[6] = 0;
      return;
    }
    iVar1 = ((int (*)())FUN_00088fd0)();
    if (iVar1 == 0) {
      pcVar3 = "undefined variable";
      goto LAB_0008b220;
    }
    iVar2 = *(int *)(iVar1 + 0x18);
    if (iVar2 == 1) goto LAB_0008b270;
    if (iVar2 == 0) {
      param_2[6] = 0;
      *param_2 = iVar1;
      ((int (*)())FUN_00088920)(param_1);
      return;
    }
    if (iVar2 != 2) {
      if (iVar2 != 3) {
        ((int (*)())FUN_00089140)(param_1);
        return;
      }
      pcVar3 = "invalid source register type";
      goto LAB_0008b220;
    }
  }
  else {
    if (uVar4 != 0x17) {
LAB_0008b1a0:
      pcVar3 = "invalid source register";
LAB_0008b220:
      ((int (*)())FUN_00088e70)(param_1,pcVar3);
      return;
    }
LAB_0008b1f0:
    iVar1 = ((int (*)())FUN_00088f00)(param_1);
    if (iVar1 == 0) {
      return;
    }
  }
  *param_2 = iVar1;
  uVar4 = *(uint *)(param_1 + 0x14);
  if (uVar4 < 0x11) {
    if (uVar4 < 0xf) {
      if (uVar4 == 0) {
        if ((*(int *)(param_1 + 0x18) != 0x1d) && (*(int *)(param_1 + 0x18) != 0x27)) {
          if (*(int *)(iVar1 + 0xc) == 0) {
            ((int (*)())FUN_00088920)();
            param_2[6] = 0;
            return;
          }
          ((int (*)())FUN_00088920)();
          ((int (*)())FUN_00089160)(param_1,0x15);
          if (*(int *)(param_1 + 0x14) == 0xf) {
            iVar2 = *(int *)(param_1 + 0x18);
            param_2[6] = iVar2;
            if (iVar2 <= *(int *)(iVar1 + 0xc)) {
              ((int (*)())FUN_00088920)(param_1);
              ((int (*)())FUN_00089160)(param_1,0x16);
              return;
            }
            pcVar3 = "invalid array index";
          }
          else {
            pcVar3 = "invalid array addressing";
          }
          ((int (*)())FUN_00088e70)(param_1,pcVar3);
          return;
        }
        ((int (*)())FUN_0008aa40)(param_1,iVar1,0,0);
        param_2[6] = 0;
        return;
      }
LAB_0008afa0:
      ((int (*)())FUN_00089140)(param_1);
      return;
    }
  }
  else if (uVar4 != 0x17) goto LAB_0008afa0;
  ((int (*)())FUN_0008aa40)(param_1,iVar1,0,0);
  param_2[6] = 0;
  return;
}

/* FUN_0008b300 @ 0x8b300 (396 bytes) */
int FUN_0008b300(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar3 = ((int (*)())FUN_00089740)();
  if (*(int *)(param_1 + 0x14) == 0) {
    bVar4 = **(char **)(param_1 + 8) + 0x9f;
    if (bVar4 < 0x1a) {
      iVar5 = 1;
      uVar1 = 1 << ((int)(char)bVar4 & 0x3fU);
      if (((uVar1 & 0x20043) == 0) && (iVar5 = 0, (uVar1 & 0x3c00000) == 0)) goto LAB_0008b3d0;
    }
    else {
LAB_0008b3d0:
      iVar5 = -1;
    }
    uVar6 = ((int (*)())FUN_0008aec0)(param_1);
    iVar2 = *param_2;
    if (*param_2 == -1) {
      *param_2 = iVar5;
      iVar2 = iVar5;
    }
    if (iVar5 == iVar2) goto LAB_0008b41c;
  }
  else if (*(int *)(param_1 + 0x14) == 0xf) {
    if (*(int *)(param_1 + 0x18) == 0) {
      uVar6 = 4;
      ((int (*)())FUN_00088920)(param_1);
      goto LAB_0008b41c;
    }
    if (*(int *)(param_1 + 0x18) == 1) {
      uVar6 = 5;
      ((int (*)())FUN_00088920)(param_1);
      goto LAB_0008b41c;
    }
  }
  uVar6 = 0;
  ((int (*)())FUN_00088e70)(param_1,"invalid extended swizzle selector");
LAB_0008b41c:
  if (iVar3 == -1) {
    switch(uVar6) {
    case 0:
      uVar6 = 6;
      break;
    case 1:
      uVar6 = 7;
      break;
    case 2:
      uVar6 = 8;
      break;
    case 3:
      uVar6 = 9;
      break;
    case 4:
      uVar6 = 4;
      break;
    case 5:
      uVar6 = 10;
      break;
    default:
      ((int (*)())FUN_00089140)(param_1);
    }
  }
  return uVar6;
}

/* FUN_0008b4b0 @ 0x8b4b0 (496 bytes) */
int FUN_0008b4b0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    if (*(int *)(param_1 + 0x18) == 0x20) {
      iVar2 = ((int (*)())FUN_00088f00)();
      if (iVar2 != 0) {
        ((int (*)())FUN_000895b0)(param_1,iVar2 + 0x18);
      }
    }
    else {
      iVar2 = ((int (*)())FUN_00088fd0)();
      if (iVar2 == 0) {
        ((int (*)())FUN_00088e70)(param_1,"undefined variable");
      }
      else {
        uVar6 = *(uint *)(iVar2 + 0x18);
        if (uVar6 < 3) {
          if (uVar6 == 0) {
LAB_0008b558:
            ((int (*)())FUN_00088920)(param_1);
          }
          else {
            iVar2 = 0;
            ((int (*)())FUN_00088e70)(param_1,"invalid destination register type");
          }
        }
        else {
          if (uVar6 == 3) goto LAB_0008b558;
          iVar2 = 0;
          ((int (*)())FUN_00089140)(param_1);
        }
      }
    }
  }
  else {
    iVar2 = 0;
    ((int (*)())FUN_00088e70)(param_1,"invalid destination register");
  }
  *param_2 = iVar2;
  uVar6 = 0xf;
  if (*(int *)(param_1 + 0x14) == 0x11) {
    ((int (*)())FUN_00088920)(param_1);
    if (*(int *)(param_1 + 0x14) == 0) {
      puVar7 = *(undefined1 **)(param_1 + 8);
      if ((int)*(undefined1 **)(param_1 + 0xc) - (int)puVar7 < 5) {
        uVar6 = 0;
        if (puVar7 < *(undefined1 **)(param_1 + 0xc)) {
          cVar4 = '\x02';
          do {
            uVar3 = ((int (*)())FUN_00089190)(param_1,*puVar7);
            uVar3 = 1 << (uVar3 & 0x3f);
            cVar5 = 3 < (byte)(**(char **)(param_1 + 8) + 0x89U);
            if ((cVar4 == '\x02') || (bVar1 = cVar4 == cVar5, cVar5 = cVar4, bVar1)) {
              if (uVar6 < uVar3) {
                uVar6 = uVar6 | uVar3;
              }
              else {
                ((int (*)())FUN_00088e70)(param_1,"invalid writemask order");
              }
            }
            else {
              ((int (*)())FUN_00088e70)(param_1,"invalid writemask components");
            }
            puVar7 = puVar7 + 1;
            cVar4 = cVar5;
          } while (puVar7 < *(undefined1 **)(param_1 + 0xc));
        }
        ((int (*)())FUN_00088920)(param_1);
        goto LAB_0008b6a0;
      }
    }
    uVar6 = 0xf;
    ((int (*)())FUN_00088e70)(param_1,"invalid writemask");
  }
LAB_0008b6a0:
  param_2[1] = uVar6;
  return;
}

/* FUN_0008b6d0 @ 0x8b6d0 (624 bytes) */
int FUN_0008b6d0(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar2 = ((int (*)())FUN_00089740)();
  if (iVar2 == -1) {
    *(undefined1 *)(param_2 + 0x14) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  ((int (*)())FUN_0008b160)(param_1,param_2);
  if (*(int *)(param_1 + 0x14) != 0x11) {
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 0x10) = 3;
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0xc) = 2;
    return;
  }
  ((int (*)())FUN_00088920)(param_1);
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = *(int *)(param_1 + 0xc) - (int)*(undefined1 **)(param_1 + 8);
    if ((iVar2 == 1) || (iVar2 == 4)) {
      uVar3 = ((int (*)())FUN_00089190)(param_1,**(undefined1 **)(param_1 + 8));
      *(undefined4 *)(param_2 + 4) = uVar3;
      if (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) < 2) {
        *(undefined4 *)(param_2 + 0x10) = uVar3;
        *(undefined4 *)(param_2 + 8) = uVar3;
        *(undefined4 *)(param_2 + 0xc) = uVar3;
      }
      else {
        uVar3 = ((int (*)())FUN_00089190)(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 1));
        *(undefined4 *)(param_2 + 8) = uVar3;
        uVar3 = ((int (*)())FUN_00089190)(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 2));
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar3 = ((int (*)())FUN_00089190)(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 3));
        *(undefined4 *)(param_2 + 0x10) = uVar3;
        pcVar4 = *(char **)(param_1 + 8);
        if ((byte)(*pcVar4 + 0x89U) < 4) {
          cVar1 = pcVar4[1];
          if (((((cVar1 != 'r') && (cVar1 != 'g')) && (cVar1 != 'b')) &&
              (((cVar1 != 'a' && (cVar1 = pcVar4[2], cVar1 != 'r')) &&
               (((cVar1 != 'g' && ((cVar1 != 'b' && (cVar1 != 'a')))) &&
                (cVar1 = pcVar4[3], cVar1 != 'r')))))) &&
             (((cVar1 != 'g' && (cVar1 != 'b')) && (cVar1 != 'a')))) goto LAB_0008b93c;
        }
        else if (((((3 < (byte)(pcVar4[1] + 0x89U)) && (cVar1 = pcVar4[2], cVar1 != 'x')) &&
                  (cVar1 != 'y')) &&
                 (((cVar1 != 'z' && (cVar1 != 'w')) &&
                  ((cVar1 = pcVar4[3], cVar1 != 'x' && ((cVar1 != 'y' && (cVar1 != 'z')))))))) &&
                (cVar1 != 'w')) goto LAB_0008b93c;
        ((int (*)())FUN_00088e70)(param_1,"invalid swizzle suffix");
      }
LAB_0008b93c:
      ((int (*)())FUN_00088920)(param_1);
      return;
    }
  }
  ((int (*)())FUN_00088e70)(param_1,"invalid swizzle suffix");
  return;
}

/* FUN_0008b960 @ 0x8b960 (132 bytes) */
int FUN_0008b960(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())FUN_00089740)();
  if (iVar1 == -1) {
    *(undefined1 *)(param_2 + 0x14) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  ((int (*)())FUN_0008b160)(param_1,param_2);
  ((int (*)())FUN_00089160)(param_1,0x11);
  uVar2 = ((int (*)())FUN_0008aec0)(param_1);
  *(undefined4 *)(param_2 + 0x10) = uVar2;
  *(undefined4 *)(param_2 + 4) = uVar2;
  *(undefined4 *)(param_2 + 8) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  return;
}

/* FUN_0008b9f0 @ 0x8b9f0 (2664 bytes) */
int FUN_0008b9f0(param_1)
  int *param_1;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_38 [7];
  
  pcVar4 = (char *)param_1[3];
  cVar1 = *pcVar4;
  pcVar5 = pcVar4 + 1;
  param_1[3] = (int)pcVar5;
  if (cVar1 == '!') {
    cVar1 = pcVar4[1];
    pcVar5 = pcVar4 + 2;
    param_1[3] = (int)pcVar5;
    if (cVar1 == '!') {
      cVar1 = pcVar4[2];
      pcVar5 = pcVar4 + 3;
      param_1[3] = (int)pcVar5;
      if (cVar1 == 'A') {
        cVar1 = pcVar4[3];
        pcVar5 = pcVar4 + 4;
        param_1[3] = (int)pcVar5;
        if (cVar1 == 'R') {
          cVar1 = pcVar4[4];
          pcVar5 = pcVar4 + 5;
          param_1[3] = (int)pcVar5;
          if (cVar1 == 'B') {
            cVar1 = pcVar4[5];
            pcVar5 = pcVar4 + 6;
            param_1[3] = (int)pcVar5;
            if (cVar1 == 'f') {
              cVar1 = pcVar4[6];
              pcVar5 = pcVar4 + 7;
              param_1[3] = (int)pcVar5;
              if (cVar1 == 'p') {
                cVar1 = pcVar4[7];
                pcVar5 = pcVar4 + 8;
                param_1[3] = (int)pcVar5;
                if (cVar1 == '1') {
                  cVar1 = pcVar4[8];
                  pcVar5 = pcVar4 + 9;
                  param_1[3] = (int)pcVar5;
                  if (cVar1 == '.') {
                    cVar1 = pcVar4[9];
                    pcVar5 = pcVar4 + 10;
                    param_1[3] = (int)pcVar5;
                    if (cVar1 == '0') {
                      ((int (*)())FUN_00088920)();
                      uVar7 = param_1[5];
                      while (uVar7 == 8) {
                        ((int (*)())FUN_00088920)(param_1);
                        if (param_1[5] == 1) {
                          *(undefined1 *)((int)param_1 + param_1[6] + 0x34) = 1;
                          ((int (*)())FUN_00088920)(param_1);
                        }
                        else {
                          ((int (*)())FUN_00088e70)(param_1,"invalid option name");
                        }
                        ((int (*)())FUN_00089160)(param_1,0x14);
                        uVar7 = param_1[5];
                      }
LAB_0008bbb0:
                      if ((uVar7 == 6) || (uVar7 == 0x1c)) {
                        ((int (*)())FUN_00089160)(param_1,6);
                        ((int (*)())FUN_00089160)(param_1,0x1c);
                        return (uint)param_1[10] >> 0x1f;
                      }
                      if (uVar7 < 0xe) {
                        uVar2 = 1 << (uVar7 & 0x3f);
                        if ((uVar2 & 0x3618) != 0) {
                          if (param_1[0x9014] < *(int *)(((unsigned char *)0x00001204) + *param_1)) {
                            piVar6 = param_1 + (param_1[0x9014] + param_1[0x9015]) * 0x18 + 0x14;
                            switch(uVar7) {
                            case 3:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 10);
                              piVar6[0x11] = 0;
                              break;
                            case 4:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 3);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 10);
                              piVar6[0x11] = 0;
                              break;
                            default:
                              ((int (*)())FUN_00089140)(param_1);
                              break;
                            case 9:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 3);
                              piVar6[0x11] = 0;
                              piVar6[10] = 0;
                              break;
                            case 10:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b160)(param_1,piVar6 + 3);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              local_38[0] = 0xffffffff;
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[4] = iVar3;
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[5] = iVar3;
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[6] = iVar3;
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[7] = iVar3;
                              piVar6[0x11] = 0;
                              *(undefined1 *)(piVar6 + 8) = 0;
                              piVar6[10] = 0;
                              break;
                            case 0xc:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 10);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 0x11);
                              break;
                            case 0xd:
                              *piVar6 = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              piVar6[0x11] = 0;
                              piVar6[10] = 0;
                            }
                            param_1[0x9014] = param_1[0x9014] + 1;
                            goto LAB_0008bba0;
                          }
                          ((int (*)())FUN_00088e70)(param_1,"too many ALU instructions");
                          uVar7 = param_1[5];
                          goto LAB_0008bbb0;
                        }
                        if ((uVar2 & 0x24) == 0) {
                          if ((uVar2 & 0x880) == 0) goto LAB_0008bb90;
                          if (param_1[0x9015] < *(int *)(((unsigned char *)0x00001208) + *param_1)) {
                            iVar3 = param_1[0x9015] + param_1[0x9014];
                            if (uVar7 == 7) {
                              param_1[iVar3 * 0x18 + 0x14] = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              param_1[iVar3 * 0x18 + 0x15] = 0;
                              ((int (*)())FUN_0008b6d0)(param_1,param_1 + iVar3 * 0x18 + 0x17);
                              param_1[iVar3 * 0x18 + 0x25] = 0;
                              param_1[iVar3 * 0x18 + 0x1e] = 0;
                            }
                            else if (uVar7 == 0xb) {
                              param_1[iVar3 * 0x18 + 0x14] = param_1[6];
                              ((int (*)())FUN_00088920)(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,param_1 + iVar3 * 0x18 + 0x15);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,param_1 + iVar3 * 0x18 + 0x17);
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              if ((param_1[5] != 0) || (param_1[6] != 0x2a)) {
                                ((int (*)())FUN_00088e70)(param_1,"invalid texture image unit");
                              }
                              iVar8 = 0;
                              ((int (*)())FUN_00088920)(param_1);
                              if (param_1[5] == 0x15) {
                                ((int (*)())FUN_00088920)(param_1);
                                if (((param_1[5] != 0xf) || (iVar8 = param_1[6], iVar8 < 0)) ||
                                   ((int)(uint)(byte)((unsigned char *)0x000013b1)[*param_1] <= iVar8)) {
                                  ((int (*)())FUN_00088e70)(param_1,"invalid texture image unit number");
                                  iVar8 = param_1[6];
                                }
                                ((int (*)())FUN_00088920)(param_1);
                                ((int (*)())FUN_00089160)(param_1,0x16);
                              }
                              param_1[iVar3 * 0x18 + 0x24] = iVar8;
                              ((int (*)())FUN_00089160)(param_1,0x13);
                              if (param_1[5] != 0xe) {
                                ((int (*)())FUN_00088e70)(param_1,"invalid texture target");
                              }
                              ((int (*)())FUN_00088920)(param_1);
                              iVar8 = param_1[6];
                              param_1[iVar3 * 0x18 + 0x2b] = iVar8;
                              if ((*(char *)((int)param_1 + 0x39) == '\0') && (iVar8 - 6U < 3)) {
                                ((int (*)())FUN_00088e70)(param_1,"invalid texture target");
                              }
                              param_1[iVar3 * 0x18 + 0x25] = 0;
                              param_1[iVar3 * 0x18 + 0x1e] = 0;
                            }
                            else {
                              ((int (*)())FUN_00089140)(param_1);
                            }
                            param_1[0x9015] = param_1[0x9015] + 1;
                            goto LAB_0008bba0;
                          }
                          ((int (*)())FUN_00088e70)(param_1,"too many texture instructions");
                          uVar7 = param_1[5];
                          goto LAB_0008bbb0;
                        }
                        if ((uVar7 != 2) && (uVar7 != 5)) {
                          ((int (*)())FUN_00089140)(param_1);
                          uVar7 = param_1[5];
                        }
                        if (uVar7 == 2) {
                          ((int (*)())FUN_00088920)(param_1);
                          iVar3 = ((int (*)())FUN_00088fd0)(param_1);
                          if (iVar3 != 0) {
                            ((int (*)())FUN_00088e70)(param_1,"redeclared variable name");
                          }
                          piVar6 = (int *)(**(code **)(*param_1 + 0xc))(0x10);
                          if (piVar6 == (int *)0x0) {
                            ((int (*)())FUN_00088ee0)(param_1);
                          }
                          piVar6[2] = param_1[3] - param_1[2];
                          piVar6[1] = param_1[2];
                          iVar3 = param_1[0x13];
                          piVar6[3] = 0;
                          *piVar6 = iVar3;
                          param_1[0x13] = (int)piVar6;
                          ((int (*)())FUN_00088920)(param_1);
                          ((int (*)())FUN_00089160)(param_1,0x1b);
                          iVar3 = ((int (*)())FUN_00088fd0)(param_1);
                          if (iVar3 == 0) {
                            ((int (*)())FUN_00088e70)(param_1,"undefined variable binding in alias");
                          }
                          else {
                            piVar6[3] = iVar3;
                            ((int (*)())FUN_00088920)(param_1);
                          }
                        }
                        else {
                          iVar3 = param_1[6];
                          if (iVar3 == 1) {
                            ((int (*)())FUN_00088920)(param_1);
                            iVar3 = ((int (*)())FUN_00089430)(param_1);
                            if (iVar3 != 0) {
                              ((int (*)())FUN_00089160)(param_1,0x1b);
                              ((int (*)())FUN_0008ace0)(param_1,iVar3);
                            }
                          }
                          else if (iVar3 == 0) {
                            ((int (*)())FUN_00088920)(param_1);
                            if (param_1[5] != 0x1c) {
                              while (iVar3 = ((int (*)())FUN_00089430)(param_1), iVar3 != 0) {
                                *(undefined4 *)(iVar3 + 0x20) = 0;
                                *(undefined4 *)(iVar3 + 0x18) = 0;
                                if ((param_1[5] != 0x13) ||
                                   (((int (*)())FUN_00088920)(param_1), param_1[5] == 0x1c)) break;
                              }
                            }
                          }
                          else if (iVar3 == 2) {
                            ((int (*)())FUN_00088920)(param_1);
                            iVar3 = ((int (*)())FUN_00089430)(param_1);
                            if (iVar3 != 0) {
                              *(undefined4 *)(iVar3 + 0x18) = 2;
                              if (param_1[5] == 0x15) {
                                ((int (*)())FUN_00088920)(param_1);
                                if (param_1[5] == 0xf) {
                                  iVar8 = param_1[6];
                                  if ((iVar8 == 0) || (*(int *)(((unsigned char *)0x000011e4) + *param_1) < iVar8))
                                  {
                                    ((int (*)())FUN_00088e70)(param_1,"invalid parameter array size");
                                    iVar8 = 1;
                                  }
                                  else {
                                    ((int (*)())FUN_00088920)(param_1);
                                  }
                                }
                                else {
                                  iVar8 = *(int *)(((unsigned char *)0x000011e4) + *param_1) + 1;
                                }
                                *(int *)(iVar3 + 0xc) = iVar8;
                                iVar8 = (**(code **)(*param_1 + 0xc))(iVar8 * 0x14);
                                *(int *)(iVar3 + 0x14) = iVar8;
                                *(undefined4 *)(iVar3 + 0x10) = 0;
                                if (iVar8 == 0) {
                                  ((int (*)())FUN_00088ee0)(param_1);
                                }
                                else {
                                  ((int (*)())FUN_00089160)(param_1,0x16);
                                  ((int (*)())FUN_00089160)(param_1,0x1b);
                                  ((int (*)())FUN_00089160)(param_1,0x17);
                                  iVar8 = param_1[5];
                                  while ((iVar8 != 0x1c &&
                                         (((int (*)())FUN_0008aa40)(param_1,iVar3,1,1), param_1[5] == 0x13))) {
                                    ((int (*)())FUN_00088920)(param_1);
                                    iVar8 = param_1[5];
                                  }
                                  if (*(int *)(((unsigned char *)0x000011e4) + *param_1) < *(int *)(iVar3 + 0xc)) {
                                    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
                                  }
                                  else if (*(int *)(iVar3 + 0xc) != *(int *)(iVar3 + 0x10)) {
                                    ((int (*)())FUN_00088e70)(param_1,"array size and binding count mismatch");
                                  }
                                  ((int (*)())FUN_00089160)(param_1,0x18);
                                }
                              }
                              else {
                                *(undefined4 *)(iVar3 + 0xc) = 0;
                                ((int (*)())FUN_00089160)(param_1,0x1b);
                                ((int (*)())FUN_0008aa40)(param_1,iVar3,0,1);
                              }
                            }
                          }
                          else if (iVar3 == 3) {
                            ((int (*)())FUN_00088920)(param_1);
                            iVar3 = ((int (*)())FUN_00089430)(param_1);
                            if (iVar3 != 0) {
                              ((int (*)())FUN_00089160)(param_1,0x1b);
                              ((int (*)())FUN_000895b0)(param_1,iVar3 + 0x18);
                            }
                          }
                          else {
                            ((int (*)())FUN_00089140)(param_1);
                          }
                        }
                      }
                      else {
LAB_0008bb90:
                        ((int (*)())FUN_00088e70)(param_1,"invalid statement");
                      }
LAB_0008bba0:
                      ((int (*)())FUN_00089160)(param_1,0x14);
                      uVar7 = param_1[5];
                      goto LAB_0008bbb0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  param_1[2] = (int)(pcVar5 + -1);
  ((int (*)())FUN_00088e70)(param_1,"invalid header");
  return 0;
}

/* FUN_0008c490 @ 0x8c490 (248 bytes) */
int FUN_0008c490(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar1 = *param_3;
  if (0 < (int)uVar1) {
    uVar4 = 0;
    iVar2 = param_2;
    uVar6 = uVar1;
    do {
      if (((*(int *)(iVar2 + 8) == param_6[2]) && (*(int *)(iVar2 + 0xc) == param_6[3])) &&
         (*(int *)(iVar2 + 0x10) == param_6[4])) {
        if (-1 < (int)uVar4) {
          param_6[1] = uVar4;
          return uVar4;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x14;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (uVar1 < param_4) {
    uVar5 = param_6[2];
    uVar3 = param_6[3];
    param_6[1] = uVar1;
    iVar2 = uVar1 * 0x14 + param_2;
    *(undefined4 *)(param_2 + uVar1 * 0x14) = *param_6;
    *(undefined4 *)(iVar2 + 8) = uVar5;
    *(undefined4 *)(iVar2 + 0xc) = uVar3;
    *(uint *)(iVar2 + 4) = uVar1;
    *(undefined4 *)(iVar2 + 0x10) = param_6[4];
    *param_3 = *param_3 + 1;
  }
  else {
    ((int (*)())FUN_00088e70)(param_1,param_5);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* FUN_0008c590 @ 0x8c590 (3768 bytes) */
int FUN_0008c590(param_1, param_2, param_3, param_4)
  int param_1;
  undefined1 *param_2;
  size_t param_3;
  void *param_4;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int *piVar5;
  byte bVar9;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar10;
  void *pvVar11;
  size_t sVar12;
  char *pcVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  void *pvVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint *puVar23;
  int iVar24;
  int iVar25;
  int local_d8 [16];
  uint local_98;
  int local_94;
  int local_90;
  uint local_8c;
  undefined *local_88;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int *local_70;
  undefined *local_6c;
  int *local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  
  piVar10 = (int *)(**(code **)(param_1 + 0xc))(((unsigned char *)0x00024a30));
  param_2[0x54] = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  if (*(int *)(param_2 + 0x60) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x78) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 0;
  *(undefined4 *)(param_2 + 0x90) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar15 = 0;
    puVar4 = param_2;
    do {
      *(undefined4 *)(puVar4 + 0x14) = 0;
      iVar15 = iVar15 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar15 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  if (0 < *(int *)(((unsigned char *)0x000011d4) + param_1)) {
    iVar15 = 0;
    do {
      *(undefined1 *)(*(int *)(param_2 + 0x94) + iVar15) = 0;
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int *)(((unsigned char *)0x000011d4) + param_1));
  }
  pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3 + 1);
  if (pvVar11 == (void *)0x0) {
    _free(piVar10);
    return;
  }
  _memcpy(pvVar11,param_4,param_3);
  *(undefined1 *)((int)pvVar11 + param_3) = 0;
  piVar10[3] = (int)pvVar11;
  *piVar10 = param_1;
  piVar10[1] = (int)pvVar11;
  piVar10[2] = (int)pvVar11;
  piVar10[4] = (int)pvVar11 + param_3;
  piVar10[0xb] = -1;
  piVar10[10] = -1;
  piVar10[9] = 1;
  iVar15 = 7;
  piVar10[0xc] = (int)"";
  piVar5 = piVar10;
  do {
    *(undefined1 *)(piVar5 + 0xd) = 0;
    piVar5 = (int *)((int)piVar5 + 1);
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  piVar10[0xf] = 0;
  piVar10[0x928b] = 0;
  piVar10[0x10] = 0;
  piVar10[0x11] = 0;
  piVar10[0x12] = 0;
  piVar10[0x13] = 0;
  piVar10[0x9014] = 0;
  piVar10[0x9015] = 0;
  piVar10[0x9116] = 0;
  piVar10[0x9149] = 0;
  piVar10[0x928a] = 0;
  iVar15 = ((int (*)())FUN_0008b9f0)(piVar10);
  if (iVar15 != 0) {
    iVar15 = *piVar10;
    bVar9 = *(char *)(piVar10 + 0xd) == '\x01';
    if (*(char *)((int)piVar10 + 0x35) == '\x01') {
      bVar9 = bVar9 + 1;
    }
    if (*(char *)((int)piVar10 + 0x36) == '\x01') {
      bVar9 = bVar9 + 1;
    }
    if (bVar9 < 2) {
      local_98 = (uint)(bVar9 == 1);
      bVar9 = *(char *)((int)piVar10 + 0x37) == '\x01';
      if (*(char *)(piVar10 + 0xe) == '\x01') {
        bVar9 = bVar9 + 1;
      }
      if (bVar9 < 2) {
LAB_0008c88c:
        piVar5 = (int *)piVar10[0xf];
        local_94 = 0;
        do {
          if (piVar5 != (int *)0x0) {
            local_68 = piVar10 + 0x914a;
            local_6c = &DAT_001ac5a4;
            bVar1 = local_98 == 0;
            local_8c = local_98;
            local_64 = piVar10 + 0x928a;
            local_88 = &DAT_001ac5a4;
            do {
              iVar2 = piVar5[6];
              if (iVar2 == 1) {
                iVar2 = ((int (*)())FUN_0008c490)(piVar10,piVar10 + 0x9117,piVar10 + 0x9149,
                                     *(int *)(((unsigned char *)0x000011ec) + iVar15) - local_8c,local_88 + -0x6920,
                                     piVar5 + 6);
                if (iVar2 < 0) goto LAB_0008d2d0;
              }
              else if (iVar2 == 0) {
                if ((int)(*(int *)(((unsigned char *)0x000011dc) + iVar15) - local_8c) <= piVar10[0x928b]) {
                  ((int (*)())FUN_00088e70)(piVar10,"too many temporaries");
                  goto LAB_0008d2d0;
                }
                piVar5[7] = piVar10[0x928b];
                piVar10[0x928b] = piVar10[0x928b] + 1;
              }
              else if (iVar2 == 2) {
                iVar2 = piVar5[3];
                local_90 = 1;
                if ((iVar2 == 0) || (local_90 = iVar2, 0 < iVar2)) {
                  iVar2 = 0;
                  iVar16 = 0;
                  do {
                    if (bVar1) {
                      iVar20 = 0;
                    }
                    else {
                      iVar20 = 2;
                    }
                    iVar20 = ((int (*)())FUN_0008c490)(piVar10,local_68,local_64,
                                          *(int *)(((unsigned char *)0x000011e4) + iVar15) - iVar20,
                                          local_6c + -0x693c,iVar16 + piVar5[5]);
                    if (iVar20 < 0) goto LAB_0008d2d0;
                    iVar2 = iVar2 + 1;
                    iVar16 = iVar16 + 0x14;
                  } while (local_90 != iVar2);
                }
              }
              else if (iVar2 != 3) {
                ((int (*)())FUN_00089140)(piVar10);
                goto LAB_0008d2d0;
              }
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
          }
          local_94 = local_94 + 1;
          if (1 < local_94) {
            iVar20 = piVar10[0x9014];
            iVar16 = *(int *)(((unsigned char *)0x000011d4) + iVar15);
            iVar2 = iVar20 + piVar10[0x9015];
            if (iVar2 <= iVar16) {
              bVar1 = local_98 == 0;
              if (!bVar1) {
                if (*(char *)(piVar10 + 0xd) == '\x01') {
                  if (iVar20 <= *(int *)(((unsigned char *)0x00001204) + iVar15) + -3) {
                    if (iVar16 + -3 < iVar2) goto LAB_0008cad4;
                    goto LAB_0008ca70;
                  }
LAB_0008cab4:
                  ((int (*)())FUN_00088e70)(piVar10,"too many ALU instructions");
                  goto LAB_0008d2d0;
                }
LAB_0008ca70:
                if (*(char *)((int)piVar10 + 0x35) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar15) + -4 < iVar20) goto LAB_0008cab4;
                  if (iVar16 + -4 < iVar2) goto LAB_0008cad4;
                }
                if (*(char *)((int)piVar10 + 0x36) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar15) + -2 < iVar20) goto LAB_0008cab4;
                  if (iVar16 + -2 < iVar2) goto LAB_0008cad4;
                }
              }
              uVar3 = (uint)(byte)((unsigned char *)0x000013b1)[iVar15];
              if (uVar3 != 0) {
                piVar5 = local_d8;
                do {
                  *piVar5 = 0;
                  piVar5 = piVar5 + 1;
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (iVar2 < 1) {
                iVar20 = 0;
                iVar24 = 1;
              }
              else {
                local_70 = local_d8;
                uVar19 = 0;
                uVar22 = 0;
                uVar3 = 0;
                uVar21 = 0;
                iVar20 = 0;
                iVar24 = 1;
                iVar25 = 0;
                iVar16 = iVar2;
                do {
                  uVar6 = *(uint *)((int)piVar10 + iVar25 + 0x50);
                  if (uVar6 < 0x20) {
                    if ((0x1c < uVar6) || (uVar6 == 0xb)) goto LAB_0008cb94;
LAB_0008cb70:
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x5c);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar17 = *(uint *)(iVar8 + 0x1c);
                      uVar7 = uVar17 - 0x20;
                      if ((int)uVar7 < 0) {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      else {
                        uVar17 = 0;
                        uVar7 = 1 << (uVar7 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar7;
                      uVar21 = uVar21 | uVar17;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x78);
                    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x18) == 0)) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        uVar17 = 0;
                        uVar7 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar17;
                      uVar21 = uVar21 | uVar7;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x94);
                    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x18) == 0)) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        uVar17 = 0;
                        uVar7 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar17;
                      uVar21 = uVar21 | uVar7;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        local_80 = 0;
                        local_7c = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        local_7c = 0;
                        local_80 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | local_80;
                      uVar21 = uVar21 | local_7c;
                    }
                    if (uVar6 == 0xb) goto LAB_0008ce38;
LAB_0008cddc:
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar6 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar6 < 0) {
                        local_78 = 0;
                        local_74 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        local_78 = 1 << (uVar6 & 0x3f);
                        local_74 = 0;
                      }
                      uVar19 = uVar19 | local_78;
                      uVar22 = uVar22 | local_74;
                    }
                  }
                  else {
                    if (2 < uVar6 - 0x3d) goto LAB_0008cb70;
LAB_0008cb94:
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x5c);
                    uVar17 = *(uint *)(iVar8 + 0x1c);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      if ((int)(uVar17 - 0x20) < 0) {
                        uVar17 = (uVar19 << 1) << (0x1f - uVar17 & 0x3f) | uVar22 >> (uVar17 & 0x3f)
                        ;
                      }
                      else {
                        uVar17 = uVar19 >> (uVar17 - 0x20 & 0x3f);
                      }
                      if ((uVar17 & 1) == 0) goto LAB_0008cbd4;
LAB_0008cc20:
                      iVar24 = iVar24 + 1;
                      if (uVar6 != 0xb) {
                        uVar19 = 0;
                        uVar22 = 0;
                        uVar3 = 0;
                        uVar21 = 0;
LAB_0008cc50:
                        iVar8 = *(int *)((int)piVar10 + iVar25 + 0x90);
                        if (local_70[iVar8] == 0) {
                          local_70[iVar8] = *(int *)((int)piVar10 + iVar25 + 0xac);
                          iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        }
                        else {
                          if (local_70[iVar8] != *(int *)((int)piVar10 + iVar25 + 0xac)) {
                            ((int (*)())FUN_00088e70)(piVar10,"multiple targets on texture context");
                            goto LAB_0008d2d0;
                          }
                          iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        }
                        goto LAB_0008cddc;
                      }
                      uVar19 = 0;
                      uVar22 = 0;
                      iVar20 = 1;
                      uVar3 = 0;
                      uVar21 = 0;
                    }
                    else {
LAB_0008cbd4:
                      if (uVar6 != 0xb) {
                        iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        if (*(int *)(iVar8 + 0x18) == 0) {
                          uVar17 = *(uint *)(iVar8 + 0x1c);
                          if ((int)(uVar17 - 0x20) < 0) {
                            uVar17 = (uVar3 << 1) << (0x1f - uVar17 & 0x3f) |
                                     uVar21 >> (uVar17 & 0x3f);
                          }
                          else {
                            uVar17 = uVar3 >> (uVar17 - 0x20 & 0x3f);
                          }
                          if ((uVar17 & 1) != 0) goto LAB_0008cc20;
                        }
                        goto LAB_0008cc50;
                      }
                      iVar20 = 1;
                    }
                  }
LAB_0008ce38:
                  iVar25 = iVar25 + 0x60;
                  iVar16 = iVar16 + -1;
                } while (iVar16 != 0);
              }
              if (*(int *)((*(unsigned char *)0x0000120c) + iVar15) < iVar24) {
                ((int (*)())FUN_00088e70)(piVar10,"too many indirections");
              }
              else {
                local_60 = iVar20;
                iVar2 = (**(code **)(iVar15 + 0xc))
                                  (iVar2 * 0x70 + (piVar10[0x9149] + piVar10[0x928a]) * 0x14 +
                                   piVar10[0x9116] * 0x10 + 0x70);
                *(int *)(param_2 + 0x60) = iVar2;
                if (iVar2 != 0) {
                  if (local_60 != 0) {
                    param_2[3] = 1;
                  }
                  if (*(char *)((int)piVar10 + 0x3a) == '\x01') {
                    param_2[5] = 1;
                  }
                  if (bVar1) {
                    *(uint *)(param_2 + 8) = local_98;
                  }
                  else {
                    param_2[1] = 1;
                    if (*(char *)(piVar10 + 0xd) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x800;
                    }
                    else if (*(char *)((int)piVar10 + 0x35) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x801;
                    }
                    else if (*(char *)((int)piVar10 + 0x36) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x2601;
                    }
                    else {
                      *(undefined4 *)(param_2 + 8) = 0;
                    }
                  }
                  if (((unsigned char *)0x000013b1)[iVar15] != '\0') {
                    iVar2 = 0;
                    piVar5 = local_d8;
                    puVar4 = param_2;
                    do {
                      iVar16 = *piVar5;
                      iVar2 = iVar2 + 1;
                      piVar5 = piVar5 + 1;
                      *(int *)(puVar4 + 0x14) = iVar16;
                      puVar4 = puVar4 + 4;
                    } while (iVar2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[iVar15]);
                  }
                  *(int *)(param_2 + 100) = *(int *)(param_2 + 0x60);
                  *(int *)(param_2 + 0x68) = piVar10[0x9014] + piVar10[0x9015];
                  *(int *)(param_2 + 0x6c) = piVar10[0x9014];
                  *(int *)(param_2 + 0x70) = piVar10[0x9015];
                  pvVar11 = (void *)((piVar10[0x9014] + piVar10[0x9015]) * 0x70 +
                                     *(int *)(param_2 + 0x60) + 0x70);
                  *(void **)(param_2 + 0x78) = pvVar11;
                  *(int *)(param_2 + 0x7c) = piVar10[0x9149];
                  pvVar18 = (void *)(piVar10[0x9149] * 0x14 + (int)pvVar11);
                  *(void **)(param_2 + 0x80) = pvVar18;
                  *(int *)(param_2 + 0x84) = piVar10[0x928a];
                  *(void **)(param_2 + 0x8c) = (void *)(piVar10[0x928a] * 0x14 + (int)pvVar18);
                  *(int *)(param_2 + 0x90) = piVar10[0x9116];
                  iVar15 = piVar10[0x928b];
                  *(int *)(param_2 + 0x74) = iVar24;
                  iVar2 = 0;
                  *(int *)(param_2 + 0x88) = iVar15;
                  _memcpy(pvVar11,piVar10 + 0x9117,piVar10[0x9149] * 0x14);
                  _memcpy(*(void **)(param_2 + 0x80),piVar10 + 0x914a,piVar10[0x928a] * 0x14);
                  _memcpy(*(void **)(param_2 + 0x8c),piVar10 + 0x9016,piVar10[0x9116] << 4);
                  if (0 < piVar10[0x9014] + piVar10[0x9015]) {
                    iVar2 = 0;
                    local_5c = piVar10 + 0x14;
                    iVar16 = 0;
                    iVar15 = 0;
                    do {
                      iVar25 = *(int *)(param_2 + 100);
                      iVar20 = (int)local_5c + iVar15;
                      puVar23 = (uint *)(iVar16 + iVar25);
                      _memset(puVar23,0,0x70);
                      *(undefined4 *)(iVar16 + iVar25) = *(undefined4 *)((int)local_5c + iVar15);
                      iVar25 = *(int *)(iVar20 + 4);
                      *(undefined1 *)(iVar2 + *(int *)(param_2 + 0x94)) = 0;
                      if (iVar25 != 0) {
                        uVar3 = *(uint *)(iVar25 + 0x1c);
                        puVar23[1] = *(uint *)(iVar25 + 0x18);
                        puVar23[2] = uVar3;
                        if (*(int *)(iVar25 + 0x18) == 3) {
                          if (*(int *)(iVar25 + 0x1c) == 1) {
                            param_2[4] = 1;
                          }
                          else if (*(int *)(iVar25 + 0x1c) == 0) {
                            *(char *)(iVar2 + *(int *)(param_2 + 0x94)) =
                                 (char)*(undefined4 *)(iVar25 + 0x24);
                          }
                        }
                      }
                      iVar25 = 0;
                      puVar23[3] = *(uint *)(iVar20 + 8);
                      puVar14 = puVar23;
                      do {
                        iVar24 = *(int *)(iVar20 + 0xc);
                        if (iVar24 == 0) {
                          uVar3 = *puVar23;
                          if ((0x1c < uVar3) &&
                             (((uVar3 < 0x20 || (uVar3 - 0x3d < 3)) &&
                              (puVar14[0xb] = *(uint *)(iVar20 + 0x24), iVar25 == 1)))) {
                            *(uint *)(param_2 + 0x10) =
                                 1 << (puVar23[0x13] & 0x3f) | *(uint *)(param_2 + 0x10);
                          }
                        }
                        else {
                          if (*(int *)(iVar24 + 0xc) == 0) {
                            uVar3 = *(uint *)(iVar24 + 0x1c);
                            uVar19 = *(uint *)(iVar24 + 0x18);
                            puVar14[0xb] = 0;
                            puVar14[5] = uVar3;
                            puVar14[4] = uVar19;
                          }
                          else {
                            iVar8 = *(int *)(iVar20 + 0x24) * 0x14;
                            uVar3 = *(uint *)(iVar8 + *(int *)(iVar24 + 0x14));
                            uVar19 = *(uint *)(iVar8 + *(int *)(iVar24 + 0x14) + 4);
                            puVar14[0xb] = 0;
                            puVar14[4] = uVar3;
                            puVar14[5] = uVar19;
                          }
                          if (puVar14[4] == 1) {
                            iVar8 = puVar14[5] * 0x14 + *(int *)(param_2 + 0x78);
                            iVar24 = *(int *)(iVar8 + 8);
                            if (iVar24 == 1) {
                              if (*(int *)(iVar8 + 0xc) == 1) {
                                *param_2 = 1;
                              }
                            }
                            else if (iVar24 == 2) {
                              *(uint *)(param_2 + 0xc) =
                                   1 << (*(uint *)(iVar8 + 0xc) & 0x3f) | *(uint *)(param_2 + 0xc);
                            }
                            else if (iVar24 == 3) {
                              param_2[1] = 1;
                            }
                            else if (iVar24 == 4) {
                              param_2[2] = 1;
                            }
                          }
                          uVar3 = *(uint *)(iVar20 + 0x14);
                          uVar19 = *(uint *)(iVar20 + 0x18);
                          uVar21 = *(uint *)(iVar20 + 0x1c);
                          puVar14[6] = *(uint *)(iVar20 + 0x10);
                          puVar14[7] = uVar3;
                          puVar14[8] = uVar19;
                          puVar14[9] = uVar21;
                          *(undefined1 *)(puVar14 + 10) = *(undefined1 *)(iVar20 + 0x20);
                        }
                        bVar1 = iVar25 != 2;
                        iVar20 = iVar20 + 0x1c;
                        puVar14 = puVar14 + 8;
                        iVar25 = iVar25 + 1;
                      } while (bVar1);
                      iVar2 = iVar2 + 1;
                      iVar15 = iVar15 + 0x60;
                      iVar16 = iVar16 + 0x70;
                    } while (iVar2 < piVar10[0x9014] + piVar10[0x9015]);
                  }
                  _memset((void *)(iVar2 * 0x70 + *(int *)(param_2 + 100)),0,0x70);
                  *(undefined4 *)(iVar2 * 0x70 + *(int *)(param_2 + 100)) = 0x41;
                  param_2[0x54] = 1;
                }
              }
              goto LAB_0008d2d0;
            }
LAB_0008cad4:
            ((int (*)())FUN_00088e70)(piVar10,"too many total instructions");
            goto LAB_0008d2d0;
          }
          if (local_94 == 0) goto LAB_0008c88c;
          piVar5 = (int *)piVar10[0x11];
        } while( true );
      }
      ((int (*)())FUN_00088e70)(piVar10,"more than one precision hint option");
    }
    else {
      ((int (*)())FUN_00088e70)(piVar10,"more than one fog option");
    }
  }
LAB_0008d2d0:
  *(int *)(((unsigned char *)0x00001124) + param_1) = piVar10[10];
  if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  sVar12 = _strlen((char *)piVar10[0xc]);
  pcVar13 = (char *)(**(code **)(param_1 + 0xc))(sVar12 + 0xb);
  *(char **)(((unsigned char *)0x00001128) + param_1) = pcVar13;
  if ((undefined *)piVar10[0xb] < ((unsigned char *)0x00002710)) {
    FUN_001a32d0(pcVar13,"line %d: %s",(undefined *)piVar10[0xb],piVar10[0xc]);
  }
  else {
    _strcpy(pcVar13,(char *)piVar10[0xc]);
  }
  if (piVar10[1] != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  piVar5 = (int *)piVar10[0xf];
  while (piVar5 != (int *)0x0) {
    if ((int *)piVar5[5] != piVar5 + 6) {
      (**(code **)(param_1 + 0x18))();
    }
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
  piVar5 = (int *)piVar10[0x11];
  while (piVar5 != (int *)0x0) {
    if ((int *)piVar5[5] != piVar5 + 6) {
      (**(code **)(param_1 + 0x18))();
    }
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
  piVar5 = (int *)piVar10[0x13];
  while (piVar5 != (int *)0x0) {
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
                    
                    
  (**(code **)(param_1 + 0x18))(piVar10);
  return;
}

/* FUN_0008d470 @ 0x8d470 (1744 bytes) */
int FUN_0008d470(param_1)
  int param_1;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  undefined *puVar16;
  int iVar17;
  
  puVar7 = (*(unsigned char *)0x000011d0) + param_1;
  uVar11 = *(uint *)(param_1 + 0x44);
  iVar17 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  ((unsigned char *)0x000011d2)[param_1] = 0;
  ((unsigned char *)0x000011d1)[param_1] = 0;
  pcVar8 = *(char **)(((unsigned char *)0x0000121c) + param_1);
  if (*(char *)(*(int *)(pcVar8 + 0x74) + 0x54) == '\0') {
    ((unsigned char *)0x000011d3)[param_1] = 0;
    *(undefined4 *)(((unsigned char *)0x00001228) + param_1) = 0;
    if (((unsigned char *)0x000013b1)[param_1] != '\0') {
      iVar10 = 0;
      puVar16 = puVar7;
      do {
        *(undefined4 *)(puVar16 + 0x5c) = 0;
        iVar10 = iVar10 + 1;
        puVar16 = puVar16 + 4;
      } while (iVar10 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
    }
    uVar12 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(pcVar8 + 8);
    ((unsigned char *)0x000011d3)[param_1] = (char)uVar3;
    uVar5 = *(uint *)(pcVar8 + 0xc);
    *(uint *)(((unsigned char *)0x00001228) + param_1) = uVar5;
    uVar15 = (uint)(byte)((unsigned char *)0x000013b6)[param_1];
    uVar12 = uVar15 - 1;
    if (-1 < (int)uVar12) {
      do {
        if (((uVar3 & 0xff | uVar5) >> (uVar12 & 0x3f) & 1) != 0) goto LAB_0008d4f8;
        uVar12 = uVar12 - 1;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    uVar12 = 0xffffffff;
LAB_0008d4f8:
    uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
    if (uVar15 != 0) {
      iVar10 = 0;
      pcVar14 = pcVar8;
      puVar16 = puVar7;
      do {
        switch(*(undefined4 *)(pcVar14 + 0x10)) {
        case 0:
          *(undefined4 *)(puVar16 + 0x5c) = 0;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 1:
        case 6:
          *(undefined4 *)(puVar16 + 0x5c) = 0x10;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 2:
        case 7:
          *(undefined4 *)(puVar16 + 0x5c) = 8;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 3:
          *(undefined4 *)(puVar16 + 0x5c) = 2;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 4:
          *(undefined4 *)(puVar16 + 0x5c) = 1;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 5:
        case 8:
          *(undefined4 *)(puVar16 + 0x5c) = 4;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
        }
        iVar10 = iVar10 + 1;
        pcVar14 = pcVar14 + 4;
        puVar16 = puVar16 + 4;
      } while (iVar10 < (int)uVar15);
    }
  }
  bVar2 = (uVar11 >> 0xd & 1) == 0;
  if ((pcVar8[4] == '\0') || (bVar2)) {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x200) != 0) {
      uVar15 = *(uint *)(param_1 + 0x3c);
      uVar11 = uVar11 & 0xfffffdff;
      goto LAB_0008d6a4;
    }
  }
  else {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x200) == 0) {
      uVar15 = *(uint *)(param_1 + 0x3c);
      uVar11 = uVar11 | 0x200;
LAB_0008d6a4:
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = uVar15 | 1;
    }
  }
  if ((*pcVar8 == '\0') || (bVar2)) {
    if ((uVar11 & 0x1000) != 0) {
      uVar11 = uVar11 & 0xffffefff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
    if ((bVar2) && ((uVar11 & 0x4000) != 0)) goto joined_r0x0008d734;
    if ((uVar11 & 0x10000) != 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 & 0xfffeffff;
      goto LAB_0008d760;
    }
  }
  else {
    if ((uVar11 & 0x1000) == 0) {
      uVar11 = uVar11 | 0x1000;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
joined_r0x0008d734:
    if ((uVar11 & 0x10000) == 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 | 0x10000;
LAB_0008d760:
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar15 | 0x20;
    }
  }
  if ((pcVar8[3] == '\0') || (bVar2)) {
    if ((uVar11 & 0x100) != 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 & 0xfffffeff;
      goto LAB_0008d7b0;
    }
  }
  else if ((uVar11 & 0x100) == 0) {
    uVar15 = *(uint *)(param_1 + 0x38);
    uVar11 = uVar11 | 0x100;
LAB_0008d7b0:
    *(uint *)(param_1 + 0x44) = uVar11;
    *(undefined1 *)(param_1 + 0x2a) = 1;
    *(uint *)(param_1 + 0x38) = uVar15 | 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if ((pcVar8[1] == '\0') || (bVar2)) {
    if ((uVar11 & 0x800) != 0) {
      uVar11 = uVar11 & 0xfffff7ff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffdfff;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    if ((uVar11 & 0x800) == 0) {
      uVar11 = uVar11 | 0x800;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x2000;
    }
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  }
  if ((pcVar8[2] == '\0') || (bVar2)) {
    if ((uVar11 & 0x400) != 0) {
      uVar11 = uVar11 & 0xfffffbff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffefff;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    if ((uVar11 & 0x400) == 0) {
      uVar11 = uVar11 | 0x400;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x1000;
    }
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  }
  if ((uVar11 & 0xc00) != 0) {
    bVar9 = ((unsigned char *)0x000013b0)[param_1];
    uVar15 = (uint)bVar9;
    if (uVar15 == 0) {
      uVar5 = 0xffffffff;
      uVar13 = 0xffffffff;
    }
    else {
      uVar6 = 0;
      uVar5 = 0xffffffff;
      uVar3 = 0xffffffff;
      do {
        uVar13 = uVar3;
        if (((((int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar6 & 0x3f) & 1U) == 0) &&
            (uVar13 = uVar6, uVar3 != 0xffffffff)) && (uVar13 = uVar3, uVar5 == 0xffffffff)) {
          uVar5 = uVar6;
        }
        uVar6 = uVar6 + 1;
        uVar15 = uVar15 - 1;
        uVar3 = uVar13;
      } while (uVar15 != 0);
    }
    if ((uVar11 & 0x800) == 0) {
      if ((uVar11 & 0x400) != 0) {
        if (uVar13 != 0xffffffff) {
          bVar9 = (byte)uVar13;
        }
        ((unsigned char *)0x000011d2)[param_1] = bVar9;
        if ((int)uVar13 <= (int)uVar12) goto LAB_0008d98c;
        uVar11 = *(uint *)(param_1 + 0x44);
        uVar12 = uVar13;
      }
    }
    else {
      if (uVar13 != 0xffffffff) {
        bVar9 = (byte)uVar13;
      }
      ((unsigned char *)0x000011d1)[param_1] = bVar9;
      if ((int)uVar12 < (int)uVar13) {
        uVar12 = uVar13;
      }
      uVar11 = *(uint *)(param_1 + 0x44);
      if ((uVar11 & 0x400) != 0) {
        uVar4 = (undefined1)uVar5;
        if (uVar5 == 0xffffffff) {
          uVar4 = ((unsigned char *)0x000013b0)[param_1];
        }
        ((unsigned char *)0x000011d2)[param_1] = uVar4;
        if ((int)uVar12 < (int)uVar5) {
          uVar11 = *(uint *)(param_1 + 0x44);
          uVar12 = uVar5;
        }
        else {
LAB_0008d98c:
          uVar11 = *(uint *)(param_1 + 0x44);
        }
      }
    }
  }
  if ((bVar2) && (((unsigned char *)0x00002e0a)[iVar17] != '\0')) {
    if ((uVar11 & 0x1000000) == 0) {
      *(uint *)(param_1 + 0x44) = uVar11 | 0x1000000;
      uVar12 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar12 | 0x100;
      if ((((int)uVar11 < 0 || (uVar11 & 0x800000) != 0) || (uVar11 & 0x200000) != 0) ||
          (uVar11 & 0x10000) != 0) {
        *(uint *)(param_1 + 0x38) = uVar12 | 0x120;
      }
    }
  }
  else {
    if ((uVar11 & 0x1000000) != 0) {
      uVar15 = uVar11 & 0xfeffffff;
      *(uint *)(param_1 + 0x44) = uVar15;
      uVar3 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfffffffe;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar3 | 0x100;
      if ((((int)uVar11 < 0 || (uVar15 >> 0x17 & 1) != 0) || (uVar15 >> 0x15 & 1) != 0) ||
          (uVar15 >> 0x10 & 1) != 0) {
        *(uint *)(param_1 + 0x38) = uVar3 | 0x120;
      }
    }
    if (!bVar2) {
      uVar11 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
      if (uVar11 != 0) {
        iVar17 = param_1;
        if ((uVar11 == 0) || (uVar11 == 0x80000000)) {
          uVar11 = 1;
        }
        do {
          uVar15 = *(uint *)(iVar17 + 0x48) & 0xffffffe0;
          *(uint *)(iVar17 + 0x48) = uVar15;
          puVar1 = (uint *)(puVar7 + 0x5c);
          puVar7 = puVar7 + 4;
          *(uint *)(iVar17 + 0x48) = uVar15 | *puVar1;
          iVar17 = iVar17 + 4;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      if ((int)(uint)*(byte *)(param_1 + 0x2b) <= (int)uVar12) {
        *(char *)(param_1 + 0x2b) = (char)uVar12 + '\x01';
      }
      bVar9 = ((unsigned char *)0x000013b6)[param_1];
      uVar11 = *(uint *)(param_1 + 0x3c);
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(ushort *)(param_1 + 0x34) = (short)(1 << (bVar9 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      goto LAB_0008da14;
    }
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  uVar11 = *(uint *)(param_1 + 0x3c) | 0x100;
  *(uint *)(param_1 + 0x3c) = uVar11;
LAB_0008da14:
  *(uint *)(param_1 + 0x3c) = uVar11 | 0x40;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_0008dbd0 @ 0x8dbd0 (100 bytes) */
int FUN_0008dbd0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(((unsigned char *)0x00001270) + param_1) != param_2) {
    *(int *)(((unsigned char *)0x00001270) + param_1) = param_2;
    *(undefined4 *)(((unsigned char *)0x0000121c) + param_1) =
         *(undefined4 *)(param_2 * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
    ((int (*)())FUN_0008d470)();
    ((unsigned char *)0x000011d0)[param_1] = 1;
  }
  return;
}

/* FUN_0008dc40 @ 0x8dc40 (12 bytes) */
int FUN_0008dc40(param_1)
  int param_1;
{
                    
                    
  (**(code **)(((unsigned char *)0x00001278) + param_1))();
  return;
}

/* FUN_0008dc50 @ 0x8dc50 (336 bytes) */
int FUN_0008dc50(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  param_2[4] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar4 = 0;
    puVar1 = param_2;
    do {
      *(undefined4 *)(puVar1 + 0x10) = 0;
      iVar4 = iVar4 + 1;
      puVar1 = puVar1 + 4;
    } while (iVar4 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0x10),4)
  ;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x70) = uVar2;
  *(undefined4 *)(param_2 + 0x58) = 0;
  param_2[0x6c] = 1;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  iVar4 = (**(code **)(param_1 + 0xc))(0x98);
  *(int *)(param_2 + 0x74) = iVar4;
  *(undefined1 *)(iVar4 + 0x54) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 0x55) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x58) = 0;
  iVar5 = *(int *)(((unsigned char *)0x000011d4) + param_1);
  iVar3 = (**(code **)(param_1 + 0x10))(iVar5,1);
  *(int *)(iVar4 + 0x94) = iVar3;
  if (0 < iVar5) {
    iVar4 = 0;
    do {
      *(undefined1 *)(iVar3 + iVar4) = 0;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

/* FUN_0008dda0 @ 0x8dda0 (408 bytes) */
int FUN_0008dda0(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  param_2[4] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar3 = 0;
    puVar2 = param_2;
    do {
      *(undefined4 *)(puVar2 + 0x10) = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  iVar3 = *(int *)(param_2 + 0x70);
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  if (iVar3 != 0) {
    iVar1 = *(int *)(iVar4 + 0x10);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(iVar5 * 4 + iVar3) != 0) {
          *(undefined4 *)(iVar5 * 4 + iVar3) = 0;
          (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1);
          iVar3 = *(int *)(param_2 + 0x70);
          iVar1 = *(int *)(iVar4 + 0x10);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x70) = 0;
  }
  iVar3 = *(int *)(param_2 + 0x74);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x60) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x60));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    if (*(int *)(iVar3 + 0x94) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x94));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x94) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    (**(code **)(param_1 + 0x18))(iVar3);
    *(undefined4 *)(param_2 + 0x74) = 0;
  }
  return;
}

/* FUN_0008df50 @ 0x8df50 (880 bytes) */
int FUN_0008df50(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  
  puVar15 = (undefined1 *)param_1[0x487];
  if ((*(int *)(puVar15 + 0x74) != 0) && (iVar4 = (*(code *)param_1[3])(0x78), iVar4 != 0)) {
    ((int (*)())FUN_0008dc50)(param_1,iVar4);
    iVar17 = *(int *)(iVar4 + 0x74);
    if (iVar17 == 0) {
      ((int (*)())FUN_0008dda0)(param_1,iVar4);
      (*(code *)param_1[6])(iVar4);
      *param_1 = 0x505;
    }
    else {
      iVar14 = param_1[1099];
      iVar5 = _strncmp(param_4,"!!ILfs1.0\n",10);
      if (iVar5 == 0) {
        *(undefined1 *)(iVar17 + 0x55) = 1;
        *(char **)(*(int *)(iVar4 + 0x74) + 0x58) = param_4;
        *(undefined4 *)(*(int *)(iVar4 + 0x74) + 0x5c) = param_3;
        *(undefined1 *)(*(int *)(iVar4 + 0x74) + 0x54) = 1;
      }
      else {
        *(undefined1 *)(iVar17 + 0x55) = 0;
        ((int (*)())FUN_0008c590)(param_1,*(undefined4 *)(iVar4 + 0x74),param_3,param_4);
        if (*(char *)(*(int *)(iVar4 + 0x74) + 0x54) == '\0') {
          ((int (*)())FUN_0008dda0)(param_1,iVar4);
          (*(code *)param_1[6])(iVar4);
          *param_1 = 0x502;
          return;
        }
      }
      param_1[0x487] = iVar4;
      *(int *)(param_1[0x49c] * 0x18 + *(int *)(iVar14 + 8) + 0x14) = iVar4;
      iVar17 = *(int *)(puVar15 + 0x74);
      *(undefined1 *)(iVar4 + 2) = *(undefined1 *)(iVar17 + 2);
      *(undefined1 *)(iVar4 + 1) = *(undefined1 *)(iVar17 + 1);
      iVar17 = (*(code *)param_1[0x49f])(param_1,1);
      if (iVar17 == 0) {
        *param_1 = 0x502;
      }
      iVar17 = param_1[0x49c] * 0x18 + *(int *)(param_1[1099] + 8);
      *(undefined4 *)(iVar17 + 8) = param_2;
      *(undefined4 *)(iVar17 + 0xc) = param_3;
      if (*(int *)(iVar17 + 0x10) != 0) {
        (*(code *)param_1[6])();
      }
      uVar6 = (*(code *)param_1[3])(param_3);
      *(undefined4 *)(iVar17 + 0x10) = uVar6;
      (*(code *)param_1[0x4d1])(uVar6,param_4,param_3);
      *(undefined4 *)(*(int *)(iVar4 + 0x74) + 0x58) = *(undefined4 *)(iVar17 + 0x10);
      param_1[0x487] = puVar15;
      *(undefined1 **)(param_1[0x49c] * 0x18 + *(int *)(iVar14 + 8) + 0x14) = puVar15;
      uVar7 = *(undefined4 *)(iVar4 + 0x70);
      uVar2 = *(undefined4 *)(iVar4 + 0x54);
      uVar16 = *(undefined4 *)(puVar15 + 0x70);
      uVar18 = *(undefined4 *)(puVar15 + 0x74);
      uVar6 = *(undefined4 *)(iVar4 + 0x50);
      uVar10 = *(undefined4 *)(iVar4 + 0x58);
      uVar12 = *(undefined4 *)(iVar4 + 0x5c);
      uVar11 = *(undefined4 *)(iVar4 + 0x60);
      uVar9 = *(undefined4 *)(iVar4 + 100);
      uVar8 = *(undefined4 *)(iVar4 + 0x68);
      uVar1 = *(undefined1 *)(iVar4 + 0x6c);
      *(undefined4 *)(puVar15 + 0x74) = *(undefined4 *)(iVar4 + 0x74);
      *(undefined4 *)(puVar15 + 0x70) = uVar7;
      *(undefined4 *)(puVar15 + 0x54) = uVar2;
      *(undefined4 *)(puVar15 + 0x50) = uVar6;
      *(undefined4 *)(puVar15 + 0x58) = uVar10;
      *(undefined4 *)(puVar15 + 0x5c) = uVar12;
      *(undefined4 *)(puVar15 + 0x60) = uVar11;
      *(undefined4 *)(puVar15 + 100) = uVar9;
      *(undefined4 *)(puVar15 + 0x68) = uVar8;
      puVar15[0x6c] = uVar1;
      *(undefined4 *)(iVar4 + 0x70) = uVar16;
      *(undefined4 *)(iVar4 + 0x74) = uVar18;
      ((int (*)())FUN_0008dda0)(param_1,iVar4);
      (*(code *)param_1[6])(iVar4);
      puVar13 = *(undefined1 **)(puVar15 + 0x74);
      puVar15[4] = puVar13[4];
      *puVar15 = *puVar13;
      puVar15[1] = puVar13[1];
      puVar15[2] = puVar13[2];
      puVar15[3] = puVar13[3];
      *(undefined4 *)(puVar15 + 8) = *(undefined4 *)(puVar13 + 0xc);
      *(undefined4 *)(puVar15 + 0xc) = *(undefined4 *)(puVar13 + 0x10);
      if (*(char *)((int)param_1 + 0x13b1) != '\0') {
        puVar3 = (undefined4 *)(puVar13 + 0x14);
        iVar4 = 0;
        do {
          uVar6 = *puVar3;
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 1;
          *(undefined4 *)(puVar15 + 0x10) = uVar6;
          puVar15 = puVar15 + 4;
        } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x13b1));
      }
      ((int (*)())FUN_0008d470)(param_1);
      *(undefined1 *)(param_1 + 0x474) = 1;
    }
  }
  return;
}

/* FUN_0008e2e0 @ 0x8e2e0 (168 bytes) */
int FUN_0008e2e0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  void *param_4;
{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  char *pcVar5;
  
  sVar1 = param_3 * 4;
  pcVar5 = _malloc(sVar1 + 0xd);
  cVar4 = s___ILfs1_0_001a5d2c[0xc];
  uVar3 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 8));
  uVar2 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 4));
  *(undefined4 *)pcVar5 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 0));
  *(undefined4 *)(pcVar5 + 4) = uVar2;
  pcVar5[0xc] = cVar4;
  *(undefined4 *)(pcVar5 + 8) = uVar3;
  _memcpy(pcVar5 + 10,param_4,sVar1);
  pcVar5[sVar1 + 0xc] = '\0';
  ((int (*)())FUN_0008df50)(param_1,0x8875,sVar1 + 0xc,pcVar5);
  _free(pcVar5);
  return;
}

/* FUN_0008ebb0 @ 0x8ebb0 (4284 bytes) */
int FUN_0008ebb0(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  double dVar21;
  double dVar22;
  undefined8 uVar23;
  float local_e8 [4];
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8 [14];
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  
  pfVar7 = param_3;
  uVar23 = FUN_001a3264();
  fVar1 = FLOAT_001aa0e8;
  iVar18 = *(int *)((int)uVar23 + 8);
  iVar13 = *(int *)((int)((ulonglong)uVar23 >> 0x20) + 4);
  iVar9 = *(int *)((int)uVar23 + 0xc);
  iVar16 = *(int *)(iVar13 + 0x10);
  switch(iVar18) {
  case 5:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28c0);
      pfVar7[1] = *(float *)(iVar16 + 0x28c4);
      pfVar7[2] = *(float *)(iVar16 + 0x28c8);
      pfVar7[3] = *(float *)(iVar16 + 0x28cc);
    }
    else {
      *pfVar7 = *(float *)(((unsigned char *)0x00002b00) + iVar16);
      pfVar7[1] = *(float *)(((unsigned char *)0x00002b04) + iVar16);
      pfVar7[2] = *(float *)(((unsigned char *)0x00002b08) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b0c) + iVar16);
    }
    break;
  case 6:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28d0);
      pfVar7[1] = *(float *)(iVar16 + 0x28d4);
      pfVar7[2] = *(float *)(iVar16 + 0x28d8);
      pfVar7[3] = *(float *)(iVar16 + 0x28dc);
    }
    else {
      *pfVar7 = *(float *)(((unsigned char *)0x00002b10) + iVar16);
      pfVar7[1] = *(float *)(((unsigned char *)0x00002b14) + iVar16);
      pfVar7[2] = *(float *)(((unsigned char *)0x00002b18) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b1c) + iVar16);
    }
    break;
  case 7:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28e0);
      pfVar7[1] = *(float *)(iVar16 + 0x28e4);
      pfVar7[2] = *(float *)(iVar16 + 0x28e8);
      pfVar7[3] = *(float *)(iVar16 + 0x28ec);
    }
    else {
      *pfVar7 = *(float *)(((unsigned char *)0x00002b20) + iVar16);
      pfVar7[1] = *(float *)(((unsigned char *)0x00002b24) + iVar16);
      pfVar7[2] = *(float *)(((unsigned char *)0x00002b28) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b2c) + iVar16);
    }
    break;
  case 8:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28f0);
      pfVar7[1] = *(float *)(iVar16 + 0x28f4);
      pfVar7[2] = *(float *)(iVar16 + 0x28f8);
      pfVar7[3] = *(float *)(iVar16 + 0x28fc);
    }
    else {
      *pfVar7 = *(float *)(((unsigned char *)0x00002b30) + iVar16);
      pfVar7[1] = *(float *)(((unsigned char *)0x00002b34) + iVar16);
      pfVar7[2] = *(float *)(((unsigned char *)0x00002b38) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b3c) + iVar16);
    }
    break;
  case 9:
    if (iVar9 == 0) {
      fVar1 = *(float *)(iVar16 + 0x2900);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b40) + iVar16);
    }
    *param_3 = fVar1;
    param_3[3] = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    break;
  case 10:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24c0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24cc);
    break;
  case 0xb:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24d0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24dc);
    break;
  case 0xc:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24e0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24ec);
    break;
  case 0xd:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24f0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24fc);
    break;
  case 0xe:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x2510);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2514);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2518);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x251c);
    break;
  case 0xf:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x2500);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2504);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2508);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x250c);
    break;
  case 0x10:
    fVar2 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24f0);
    *pfVar7 = fVar2;
    fVar3 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f4);
    pfVar7[1] = fVar3;
    fVar5 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f8) + fVar1;
    pfVar7[2] = fVar5;
    dVar21 = (double)_sqrt((double)(fVar5 * fVar5 + fVar2 * fVar2 + fVar3 * fVar3));
    param_3[3] = fVar1;
    fVar1 = fVar1 / (float)dVar21;
    param_3[2] = fVar5 * fVar1;
    *param_3 = fVar1 * fVar2;
    param_3[1] = fVar3 * fVar1;
    break;
  case 0x11:
    *pfVar7 = *(float *)(iVar16 + 0x24b0);
    pfVar7[1] = *(float *)(iVar16 + 0x24b4);
    pfVar7[2] = *(float *)(iVar16 + 0x24b8);
    pfVar7[3] = *(float *)(iVar16 + 0x24bc);
    break;
  case 0x12:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x24b0) * *(float *)(iVar16 + 0x28c0) +
                *(float *)(iVar16 + 0x28f0);
      pfVar7[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(iVar16 + 0x28c4) +
                  *(float *)(iVar16 + 0x28f4);
      pfVar7[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(iVar16 + 0x28c8) +
                  *(float *)(iVar16 + 0x28f8);
      pfVar7[3] = *(float *)(iVar16 + 0x28dc);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x24b0) * *(float *)(((unsigned char *)0x00002b00) + iVar16) +
                *(float *)(((unsigned char *)0x00002b30) + iVar16);
      pfVar7[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(((unsigned char *)0x00002b04) + iVar16) +
                  *(float *)(((unsigned char *)0x00002b34) + iVar16);
      pfVar7[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(((unsigned char *)0x00002b08) + iVar16) +
                  *(float *)(((unsigned char *)0x00002b38) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b1c) + iVar16);
    }
    break;
  case 0x13:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c0);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b00) + iVar16);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24c0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c4);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b04) + iVar16);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c8);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b08) + iVar16);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28cc);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b0c) + iVar16);
    }
    goto LAB_0008f398;
  case 0x14:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d0);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b10) + iVar16);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24d0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d4);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b14) + iVar16);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d8);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b18) + iVar16);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28dc);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b1c) + iVar16);
    }
    goto LAB_0008f398;
  case 0x15:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e0);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b20) + iVar16);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24e0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e4);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b24) + iVar16);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e8);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b28) + iVar16);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28ec);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b2c) + iVar16);
    }
    goto LAB_0008f398;
  case 0x16:
    *pfVar7 = *(float *)(((unsigned char *)0x00002de0) + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x00002de4) + iVar16);
    pfVar7[2] = *(float *)(((unsigned char *)0x00002de8) + iVar16);
    pfVar7[3] = *(float *)(((unsigned char *)0x00002dec) + iVar16);
    break;
  case 0x17:
    *pfVar7 = *(float *)(((unsigned char *)0x00002df0) + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x00002df4) + iVar16);
    pfVar7[2] = *(float *)(((unsigned char *)0x00002df8) + iVar16);
    pfVar7[3] = *(float *)(((unsigned char *)0x00002dfc) + iVar16);
    break;
  case 0x18:
    *pfVar7 = (float)*(double *)(FUN_00001830 + iVar16);
    pfVar7[1] = (float)*(double *)(iVar16 + 0x1838);
    dVar22 = *(double *)(FUN_00001830 + iVar16);
    dVar21 = *(double *)(iVar16 + 0x1838);
    pfVar7[3] = 1.0;
    pfVar7[2] = (float)(dVar21 - dVar22);
    break;
  case 0x19:
    *pfVar7 = *(float *)(((unsigned char *)0x000031c4) + iVar9 * 0x7c + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x000031c8) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10))
    ;
    pfVar7[2] = *(float *)(((unsigned char *)0x000031cc) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10))
    ;
    fVar1 = *(float *)(((unsigned char *)0x000031d0) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10));
LAB_0008f398:
    param_3[3] = fVar1;
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
    iVar18 = iVar18 + -0x1a;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1960;
    goto LAB_0008f444;
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    iVar16 = iVar16 + 0x1920;
    iVar18 = iVar18 + -0x1e;
    goto LAB_0008f444;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
    iVar16 = iVar16 + 0x1860;
    iVar18 = iVar18 + -0x22;
    goto LAB_0008f444;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    iVar18 = iVar18 + -0x26;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1c60;
    goto LAB_0008f444;
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    iVar18 = iVar18 + -0x2e;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1a60;
LAB_0008f444:
    iVar9 = 0;
    iVar13 = 0x10;
    pfVar7 = local_e8;
    do {
      iVar4 = iVar9 * 4;
      iVar9 = iVar9 + 1;
      *pfVar7 = *(float *)(iVar16 + iVar4);
      pfVar7 = pfVar7 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar9 = *(int *)(param_2 + 0x10);
    if ((iVar9 == 1) || (iVar9 == 3)) {
      local_a8[4] = 1.0;
      local_a8[0xd] = 1.0;
      local_a8[1] = local_d8;
      local_a8[2] = local_c8;
      local_68 = local_e8[2];
      local_a8[0] = local_e8[0];
      local_a8[7] = FLOAT_001aa0d4;
      local_a8[6] = FLOAT_001aa0d4;
      local_a8[5] = FLOAT_001aa0d4;
      local_a8[8] = local_e8[1];
      local_6c = FLOAT_001aa0d4;
      local_a8[3] = local_b8;
      local_a8[9] = local_d4;
      local_a8[0xc] = FLOAT_001aa0d4;
      local_a8[10] = local_c4;
      local_a8[0xb] = local_b4;
      local_64 = local_d0;
      local_60 = local_c0;
      local_5c = local_b0;
      local_50 = 0x3f800000;
      local_4c = FLOAT_001aa0d4;
      local_2c = 0x3f800000;
      local_54 = FLOAT_001aa0d4;
      local_58 = FLOAT_001aa0d4;
      local_30 = FLOAT_001aa0d4;
      local_34 = FLOAT_001aa0d4;
      local_38 = FLOAT_001aa0d4;
      local_44 = local_cc;
      local_40 = local_bc;
      local_48 = local_e8[3];
      local_3c = local_ac;
      pfVar7 = &STACKARG(0xffffffb8);
      pfVar17 = &STACKARG(0xffffff98);
      if (ABS(local_e8[3]) <= ABS(local_e8[2])) {
        pfVar7 = &STACKARG(0xffffff98);
        pfVar17 = &STACKARG(0xffffffb8);
      }
      pfVar11 = local_a8 + 8;
      fVar1 = *pfVar7;
      if (ABS(*pfVar7) <= ABS(local_e8[1])) {
        pfVar11 = pfVar7;
        pfVar7 = local_a8 + 8;
        fVar1 = local_e8[1];
      }
      pfVar12 = local_a8;
      if (ABS(local_e8[0]) < ABS(fVar1)) {
        pfVar12 = pfVar7;
        pfVar7 = local_a8;
      }
      fVar1 = *pfVar12;
      if (fVar1 != FLOAT_001aa0d4) {
        fVar2 = pfVar12[1];
        pfVar10 = pfVar12 + 4;
        fVar3 = *pfVar7 / fVar1;
        fVar5 = *pfVar11 / fVar1;
        fVar1 = *pfVar17 / fVar1;
        pfVar7[1] = -(fVar3 * fVar2 - pfVar7[1]);
        pfVar11[1] = -(fVar5 * fVar2 - pfVar11[1]);
        pfVar17[1] = -(fVar1 * fVar2 - pfVar17[1]);
        fVar2 = pfVar12[2];
        pfVar7[2] = -(fVar3 * fVar2 - pfVar7[2]);
        pfVar11[2] = -(fVar5 * fVar2 - pfVar11[2]);
        pfVar17[2] = -(fVar1 * fVar2 - pfVar17[2]);
        fVar2 = pfVar12[3];
        pfVar7[3] = -(fVar3 * fVar2 - pfVar7[3]);
        pfVar11[3] = -(fVar5 * fVar2 - pfVar11[3]);
        pfVar17[3] = -(fVar1 * fVar2 - pfVar17[3]);
        fVar2 = pfVar12[4];
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[4] = -(fVar3 * fVar2 - pfVar7[4]);
          pfVar11[4] = -(fVar5 * fVar2 - pfVar11[4]);
          pfVar17[4] = -(fVar1 * fVar2 - pfVar17[4]);
        }
        fVar2 = pfVar12[5];
        pfVar8 = pfVar12 + 5;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[5] = -(fVar3 * fVar2 - pfVar7[5]);
          pfVar11[5] = -(fVar5 * fVar2 - pfVar11[5]);
          pfVar17[5] = -(fVar1 * fVar2 - pfVar17[5]);
        }
        fVar2 = pfVar12[6];
        pfVar19 = pfVar12 + 6;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[6] = -(fVar3 * fVar2 - pfVar7[6]);
          pfVar11[6] = -(fVar5 * fVar2 - pfVar11[6]);
          pfVar17[6] = -(fVar1 * fVar2 - pfVar17[6]);
        }
        fVar2 = pfVar12[7];
        pfVar20 = pfVar12 + 7;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[7] = -(fVar3 * fVar2 - pfVar7[7]);
          pfVar11[7] = -(fVar5 * fVar2 - pfVar11[7]);
          pfVar17[7] = -(fVar1 * fVar2 - pfVar17[7]);
        }
        pfVar15 = pfVar11;
        if (ABS(pfVar11[1]) < ABS(pfVar17[1])) {
          pfVar15 = pfVar17;
          pfVar17 = pfVar11;
        }
        fVar1 = pfVar15[1];
        fVar2 = pfVar7[1];
        pfVar11 = pfVar7 + 1;
        pfVar14 = pfVar15;
        if (ABS(fVar2) < ABS(fVar1)) {
          pfVar11 = pfVar15 + 1;
          pfVar14 = pfVar7;
          pfVar7 = pfVar15;
          fVar2 = fVar1;
        }
        if (fVar2 != FLOAT_001aa0d4) {
          fVar3 = pfVar14[1] / fVar2;
          fVar2 = pfVar17[1] / fVar2;
          pfVar14[2] = -(fVar3 * pfVar7[2] - pfVar14[2]);
          pfVar17[2] = -(fVar2 * pfVar7[2] - pfVar17[2]);
          pfVar14[3] = -(fVar3 * pfVar7[3] - pfVar14[3]);
          pfVar17[3] = -(fVar2 * pfVar7[3] - pfVar17[3]);
          fVar1 = pfVar7[4];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[4] = -(fVar3 * fVar1 - pfVar14[4]);
            pfVar17[4] = -(fVar2 * fVar1 - pfVar17[4]);
          }
          fVar1 = pfVar7[5];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[5] = -(fVar3 * fVar1 - pfVar14[5]);
            pfVar17[5] = -(fVar2 * fVar1 - pfVar17[5]);
          }
          fVar1 = pfVar7[6];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[6] = -(fVar3 * fVar1 - pfVar14[6]);
            pfVar17[6] = -(fVar2 * fVar1 - pfVar17[6]);
          }
          fVar1 = pfVar7[7];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[7] = -(fVar3 * fVar1 - pfVar14[7]);
            pfVar17[7] = -(fVar2 * fVar1 - pfVar17[7]);
          }
          pfVar15 = pfVar14;
          if (ABS(pfVar14[2]) < ABS(pfVar17[2])) {
            pfVar15 = pfVar17;
            pfVar17 = pfVar14;
          }
          fVar1 = pfVar15[2];
          if (fVar1 != FLOAT_001aa0d4) {
            fVar1 = pfVar17[2] / fVar1;
            fVar2 = -(fVar1 * pfVar15[3] - pfVar17[3]);
            pfVar17[3] = fVar2;
            fVar3 = -(fVar1 * pfVar15[4] - pfVar17[4]);
            pfVar17[4] = fVar3;
            fVar6 = -(fVar1 * pfVar15[5] - pfVar17[5]);
            pfVar17[5] = fVar6;
            fVar5 = -(fVar1 * pfVar15[6] - pfVar17[6]);
            pfVar17[6] = fVar5;
            fVar1 = -(fVar1 * pfVar15[7] - pfVar17[7]);
            pfVar17[7] = fVar1;
            if (fVar2 != FLOAT_001aa0d4) {
              fVar2 = FLOAT_001aa0e8 / fVar2;
              fVar3 = fVar2 * fVar3;
              pfVar17[4] = fVar3;
              pfVar17[7] = fVar2 * fVar1;
              pfVar17[5] = fVar2 * fVar6;
              pfVar17[6] = fVar2 * fVar5;
              fVar1 = pfVar15[3];
              fVar2 = FLOAT_001aa0e8 / pfVar15[2];
              pfVar15[4] = fVar2 * -(fVar1 * fVar3 - pfVar15[4]);
              pfVar15[5] = fVar2 * -(fVar1 * pfVar17[5] - pfVar15[5]);
              pfVar15[6] = fVar2 * -(fVar1 * pfVar17[6] - pfVar15[6]);
              pfVar15[7] = fVar2 * -(fVar1 * pfVar17[7] - pfVar15[7]);
              fVar1 = pfVar7[3];
              pfVar7[4] = -(fVar1 * pfVar17[4] - pfVar7[4]);
              pfVar7[5] = -(fVar1 * pfVar17[5] - pfVar7[5]);
              pfVar7[6] = -(fVar1 * pfVar17[6] - pfVar7[6]);
              pfVar7[7] = -(fVar1 * pfVar17[7] - pfVar7[7]);
              fVar1 = pfVar12[3];
              *pfVar10 = -(fVar1 * pfVar17[4] - *pfVar10);
              *pfVar8 = -(fVar1 * pfVar17[5] - *pfVar8);
              *pfVar19 = -(fVar1 * pfVar17[6] - *pfVar19);
              *pfVar20 = -(fVar1 * pfVar17[7] - *pfVar20);
              fVar1 = pfVar7[2];
              fVar2 = FLOAT_001aa0e8 / *pfVar11;
              pfVar7[4] = fVar2 * -(fVar1 * pfVar15[4] - pfVar7[4]);
              pfVar7[5] = fVar2 * -(fVar1 * pfVar15[5] - pfVar7[5]);
              pfVar7[6] = fVar2 * -(fVar1 * pfVar15[6] - pfVar7[6]);
              pfVar7[7] = fVar2 * -(fVar1 * pfVar15[7] - pfVar7[7]);
              fVar1 = pfVar12[2];
              *pfVar10 = -(fVar1 * pfVar15[4] - *pfVar10);
              *pfVar8 = -(fVar1 * pfVar15[5] - *pfVar8);
              *pfVar19 = -(fVar1 * pfVar15[6] - *pfVar19);
              *pfVar20 = -(fVar1 * pfVar15[7] - *pfVar20);
              fVar1 = pfVar12[1];
              local_b8 = FLOAT_001aa0e8 / *pfVar12;
              *pfVar10 = local_b8 * -(fVar1 * pfVar7[4] - *pfVar10);
              *pfVar8 = local_b8 * -(fVar1 * pfVar7[5] - *pfVar8);
              *pfVar19 = local_b8 * -(fVar1 * pfVar7[6] - *pfVar19);
              local_b8 = local_b8 * -(fVar1 * pfVar7[7] - *pfVar20);
              *pfVar20 = local_b8;
              local_e8[0] = *pfVar10;
              local_d8 = *pfVar8;
              local_c8 = *pfVar19;
              local_e8[1] = pfVar7[4];
              local_d4 = pfVar7[5];
              local_c4 = pfVar7[6];
              local_b4 = pfVar7[7];
              local_e8[2] = pfVar15[4];
              local_d0 = pfVar15[5];
              local_c0 = pfVar15[6];
              iVar9 = *(int *)(param_2 + 0x10);
              local_b0 = pfVar15[7];
              local_e8[3] = pfVar17[4];
              local_cc = pfVar17[5];
              local_bc = pfVar17[6];
              local_ac = pfVar17[7];
              goto LAB_0008eb2c;
            }
          }
        }
        iVar9 = *(int *)(param_2 + 0x10);
      }
    }
LAB_0008eb2c:
    if (-1 < iVar9) {
      if (iVar9 < 2) {
        iVar9 = 0;
        iVar16 = 4;
        pfVar7 = local_e8 + iVar18;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 4;
          *(float *)(iVar9 + (int)param_3) = fVar1;
          iVar9 = iVar9 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      else if (iVar9 < 4) {
        iVar9 = 0;
        pfVar7 = local_e8 + iVar18 * 4;
        iVar16 = 4;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 1;
          *(float *)(iVar9 + (int)param_3) = fVar1;
          iVar9 = iVar9 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
    }
    return;
  case 0x32:
    *(undefined8 *)pfVar7 = *(undefined8 *)(((unsigned char *)0x00001010) + iVar9 * 0x10 + iVar16);
    *(undefined8 *)(pfVar7 + 2) = *(undefined8 *)(((unsigned char *)0x00001010) + iVar9 * 0x10 + iVar16 + 8);
    break;
  case 0x33:
    iVar16 = *(int *)(**(int **)(*(int *)(iVar13 + 0x18) + 400) + 0x18);
    *(undefined8 *)pfVar7 = *(undefined8 *)(iVar9 * 0x10 + iVar16);
    *(undefined8 *)(pfVar7 + 2) = *(undefined8 *)(iVar9 * 0x10 + iVar16 + 8);
  }
  return;
}

/* FUN_0008f520 @ 0x8f520 (456 bytes) */
int FUN_0008f520(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = (*(unsigned char *)0x000011d0) + param_1;
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  *(undefined4 *)(((unsigned char *)0x0000126c) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x00001220) + param_1) = 2;
  (**(code **)(((unsigned char *)0x00001274) + param_1))();
  ((unsigned char *)0x000011d3)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001228) + param_1) = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar2 = 0;
    do {
      *(undefined4 *)(puVar5 + 0x5c) = 0;
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  FUN_000a0350(param_1,*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8)) = 0;
  iVar2 = *(int *)(((unsigned char *)0x0000126c) + param_1);
  iVar3 = *(int *)(iVar4 + 8);
  uVar1 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar2 * 0x18 + iVar3 + 0x14) = uVar1;
  ((int (*)())FUN_0008dc50)(param_1,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 0x14));
  FUN_000a0350(param_1,*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8)) = 0;
  iVar2 = *(int *)(((unsigned char *)0x00001220) + param_1);
  iVar3 = *(int *)(iVar4 + 8);
  uVar1 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar2 * 0x18 + iVar3 + 0x14) = uVar1;
  ((int (*)())FUN_0008dc50)(param_1,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 0x14));
  return;
}

/* FUN_0008f760 @ 0x8f760 (144 bytes) */
int FUN_0008f760(param_1)
  int param_1;
{
  ((unsigned char *)0x000011d0)[param_1] = 1;
  *(int *)(((unsigned char *)0x00001270) + param_1) = *(int *)(((unsigned char *)0x0000126c) + param_1);
  *(undefined4 *)(((unsigned char *)0x0000121c) + param_1) =
       *(undefined4 *)
        (*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8)
        + 0x14);
  ((int (*)())FUN_0008c590)(param_1,*(undefined4 *)
                        (*(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                                  *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14) + 0x74),
               0xf,"!!ARBfp1.0\nEND\n");
  ((int (*)())FUN_0008dbd0)(param_1,*(undefined4 *)(((unsigned char *)0x0000126c) + param_1));
  return;
}

/* FUN_0008f7f0 @ 0x8f7f0 (884 bytes) */
int FUN_0008f7f0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  code *pcVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  undefined1 auStack_f8 [144];
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  longlong local_40;
  longlong local_38;
  
  iVar20 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar16 = (**(code **)(param_1 + 0x2758))(param_1,((unsigned char *)0x00002710));
  pcVar14 = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar16;
  (*pcVar14)(param_1,iVar16);
  iVar19 = *(int *)(param_1 + 4);
  if (((((*(uint *)(iVar19 + 0x154) & 0x700000) == 0) || (*param_4 != 0)) || (param_4[1] != 0)) ||
     ((param_4[2] != *(uint *)(iVar19 + 0x15c) || (param_4[3] != *(uint *)(iVar19 + 0x160))))) {
    bVar11 = false;
    iVar19 = 0;
  }
  else {
    bVar11 = true;
    FUN_000a5c40(param_1,param_2);
    iVar19 = *(int *)(FUN_00002748 + param_1 + 4);
  }
  ((int (*)())FUN_00086ba0)(param_1,1,0,0,auStack_f8);
  uVar18 = 0x25;
  if (*(char *)(param_1 + 0x2802) != '\0') {
    uVar18 = 0x23;
  }
  puVar17 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar18);
  cVar7 = *(char *)(param_1 + 0x2802);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar17;
  if (cVar7 == '\0') {
    puVar17[1] = 0x10000000;
    *puVar17 = 0x5c8;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  uVar18 = (**(code **)(param_1 + 0x2758))(param_1,0x23);
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar18;
  puVar17 = (undefined4 *)((int (*)())FUN_00083c90)(param_1);
  if (bVar11) {
    *(int *)(iVar16 + 8) = (int)puVar17 - iVar16 >> 2;
  }
  local_68 = 0x43300000;
  local_60 = 0x43300000;
  local_58 = 0x43300000;
  local_50 = 0x43300000;
  uStack_4c = param_4[2] ^ 0x80000000;
  uStack_64 = param_4[1] ^ 0x80000000;
  uStack_5c = *param_4 ^ 0x80000000;
  uStack_54 = param_4[3] ^ 0x80000000;
  uStack_44 = *(undefined4 *)(param_1 + 8);
  uVar18 = *(undefined4 *)(((unsigned char *)0x00002dac) + iVar20);
  uVar8 = *(undefined4 *)(((unsigned char *)0x00002da0) + iVar20);
  uVar9 = *(undefined4 *)(((unsigned char *)0x00002da4) + iVar20);
  uVar10 = *(undefined4 *)(((unsigned char *)0x00002da8) + iVar20);
  local_48 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_001aa1e0);
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_54) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_5c) - DOUBLE_001aa1e0);
  fVar12 = (fVar5 + fVar2) * FLOAT_001aa10c;
  fVar13 = (fVar3 + fVar4) * FLOAT_001aa10c;
  fVar6 = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_001aa250);
  uVar1 = (uint)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar3));
  local_40 = (longlong)(int)uVar1;
  iVar20 = (int)(fVar6 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar2 - fVar5));
  local_38 = (longlong)iVar20;
  puVar17[2] = 0x82c;
  *puVar17 = ((unsigned char *)0x00001087);
  puVar17[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  uVar15 = *(undefined4 *)(param_1 + 0x1b84);
  puVar17[5] = 0x10031;
  puVar17[4] = 0xc0083500;
  puVar17[6] = fVar12;
  puVar17[7] = fVar13;
  puVar17[9] = 0x3f800000;
  puVar17[10] = uVar8;
  puVar17[0xb] = uVar9;
  puVar17[3] = uVar15;
  puVar17[0xc] = uVar10;
  puVar17[0xd] = uVar18;
  puVar17[0xe] = ((unsigned char *)0x00001087);
  puVar17[8] = 0;
  puVar17[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar17 + 0x10;
  (**(code **)(param_1 + 0x275c))(param_1,puVar17 + 0x10);
  FUN_0009d3b0(param_1);
  ((int (*)())FUN_000872e0)(param_1,auStack_f8);
  if (bVar11) {
    *(int *)(iVar16 + 4) = *(int *)(FUN_00002748 + param_1 + 4) - iVar19 >> 2;
  }
  return;
}

/* FUN_0008fb70 @ 0x8fb70 (248 bytes) */
int FUN_0008fb70(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != 0) {
    ((int (*)())FUN_00086840)();
  }
  iVar2 = *(int *)(param_1 + 0x1b7c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  if (*(char *)(param_1 + 0x1868) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      FUN_000651e0(param_1);
    }
  }
  else if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    iVar1 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))
              (param_1,iVar1 + 0x13c,*(undefined4 *)(iVar1 + 0x130));
  }
  FUN_0009d2e0(param_1);
  *(char *)(param_1 + 0x23ec) = '\x01' - (iVar2 == *(int *)(param_1 + 0x1b7c));
  return;
}

/* FUN_0008fc70 @ 0x8fc70 (1028 bytes) */
int FUN_0008fc70(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset((void *)(param_1 + 0x19c),-1,0x68);
  FUN_0004fc80(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x19c) = 0;
  if (*(int *)(param_1 + 0x44) < 0) {
    FUN_0004fc80(param_1,1,3,0,1,0,0,0);
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    if ("}J3x})+x|B;x}k"[iVar4 + 3] == '\0') {
      uVar3 = *(uint *)(param_1 + 0x44);
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      FUN_0004fc80(param_1,2,3,0,2,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x1a8) = 2;
    }
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x8c);
    if (((uVar5 >> 0x14 & 1) == 0 && (uVar5 >> 0x1a & 1) == 0) && (uVar5 >> 0x1b & 1) == 0) {
      iVar7 = 1;
      uVar6 = 1;
      uVar5 = 2;
    }
    else {
      iVar7 = 2;
      uVar5 = 3;
      FUN_0004fc80(param_1,1,3,0,1,0,0,0);
      uVar6 = 2;
      *(undefined4 *)(param_1 + 0x1a0) = 1;
    }
    FUN_0004fc80(param_1,uVar6,3,0,uVar6,0,0,0);
    uVar3 = *(uint *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x1a8) = uVar6;
    if ((uVar3 & 0xa10000) != 0) {
      FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x1ac) = uVar5;
      uVar5 = iVar7 + 2;
    }
  }
  if ((uVar3 & 0x20000) == 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    }
    if (uVar2 == 0) goto LAB_0008ff78;
    uVar3 = 0;
    iVar7 = param_1;
    iVar8 = param_1;
    do {
      if ((((unsigned char *)0x00001438)[iVar8] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar7) != 0)) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar3 != uVar2);
  }
  else {
    if ((uVar3 & 0x2000) == 0) {
      bVar1 = ((unsigned char *)0x00001135)[param_1];
    }
    else {
      bVar1 = ((unsigned char *)0x000011d3)[param_1];
    }
    uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar2 == 0) goto LAB_0008ff78;
    uVar3 = 0;
    iVar7 = param_1;
    do {
      if (((uint)bVar1 & 1 << (uVar3 & 0x3f)) != 0) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar7 = iVar7 + 4;
    } while ((int)uVar3 < (int)uVar2);
  }
  uVar3 = *(uint *)(param_1 + 0x44);
LAB_0008ff78:
  if (((uVar3 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar4) == -0x7baf)) {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1ec) = uVar5;
    uVar5 = uVar5 + 1;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  if (((unsigned char *)0x00004301)[iVar4] != '\0') {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1f8) = uVar5;
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 - 1;
  if ((uVar3 & 1) == 0) {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x2000;
  }
  else {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x20000000;
  }
  *(char *)(param_1 + 0x131) = (char)uVar5;
  *(uint *)(param_1 + 0x2430) = uVar5;
  *(uint *)(param_1 + 0x2438) = uVar5;
  *(undefined1 *)(param_1 + 0x2435) = 1;
  *(uint *)(param_1 + 0x243c) = uVar5;
  *(uint *)(param_1 + 0x1ca4) = (uVar5 & 0x1f) << 2 | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
  return;
}

/* FUN_000900a0 @ 0x900a0 (944 bytes) */
int FUN_000900a0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = *(uint *)(param_1 + 0x1b9c);
  iVar11 = *(int *)(param_1 + 0x1ba0);
  iVar10 = *(int *)(param_1 + 0x1ca0);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(param_1 + 0x1868) != '\0') && (*(char *)(param_1 + 0x124) != '\0')) {
    FUN_0004dbe0();
    return;
  }
  uVar8 = *(uint *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  if ((int)uVar8 < 0) {
    *(undefined4 *)(param_1 + 0x1ca0) = 3;
    if ("}J3x})+x|B;x}k"[iVar5 + 3] != '\0') {
      *(undefined4 *)(param_1 + 0x1ca0) = 7;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x8c);
    if (((uVar1 >> 0x14 & 1) != 0 || (uVar1 >> 0x1a & 1) != 0) || (uVar1 >> 0x1b & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = 3;
    }
    uVar1 = *(uint *)(param_1 + 0x1ca0);
    *(uint *)(param_1 + 0x1ca0) = uVar1 | 4;
    if ((uVar8 & 0xa10000) != 0) {
      *(uint *)(param_1 + 0x1ca0) = uVar1 | 0xc;
    }
  }
  if (((uVar8 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar5) == -0x7baf)) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
  }
  if (((unsigned char *)0x00004301)[iVar5] != '\0') {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x80000;
  }
  uVar1 = 3;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((int)uVar4 < 0) {
    if (*(short *)("}J3x})+x|B;x}k" + iVar5) == -0x7e06) {
      *(undefined4 *)(param_1 + 0x1b9c) = 7;
    }
    if ("}J3x})+x|B;x}k"[iVar5 + 4] == '\0') {
      uVar1 = *(uint *)(param_1 + 0x1b9c);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x1b9c) | 0x1c;
      *(uint *)(param_1 + 0x1b9c) = uVar1;
    }
  }
  else if (((uVar4 >> 0x17 & 1) != 0 || (uVar4 >> 0x15 & 1) != 0) || (uVar4 >> 0x10 & 1) != 0) {
    uVar1 = 7;
    *(undefined4 *)(param_1 + 0x1b9c) = 7;
  }
  if ((*(uint *)(param_1 + 0xe8) & 1) != 0) {
    uVar1 = uVar1 | 0x10000;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if (((uVar8 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    uVar1 = uVar1 | 4;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if ((uVar8 & 0x20000) == 0) {
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[param_1]) {
      uVar8 = (uint)*(byte *)(param_1 + 0x2b);
    }
    if (uVar8 != 0) {
      iVar2 = 0;
      uVar4 = 0;
      iVar5 = param_1;
      iVar7 = param_1;
      do {
        if ((((unsigned char *)0x00001438)[iVar7] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar5) != 0)) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar4 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (iVar2 + 10U & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        iVar2 = iVar2 + 1;
        uVar4 = uVar4 + 3;
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 4;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  else {
    if ((uVar8 & 0x2000) == 0) {
      uVar4 = (uint)(byte)((unsigned char *)0x00001135)[param_1];
    }
    else {
      uVar4 = (uint)(byte)((unsigned char *)0x000011d3)[param_1];
      if ((uVar8 & 0x800) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d1)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
      if ((uVar8 & 0x400) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d2)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
    }
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar8 != 0) {
      uVar6 = 0;
      uVar3 = 0;
      if (uVar8 == 0) {
        uVar8 = 1;
      }
      do {
        if ((uVar4 & 1 << (uVar6 & 0x3f)) != 0) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (uVar6 + 10 & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        uVar6 = uVar6 + 1;
        uVar3 = uVar3 + 3;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  if ((((uVar9 != uVar1) || (iVar11 != *(int *)(param_1 + 0x1ba0))) ||
      (iVar10 != *(int *)(param_1 + 0x1ca0))) || (*(char *)(param_1 + 299) != '\0')) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    ((int (*)())FUN_0008fc70)(param_1);
    (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
    *(undefined1 *)(param_1 + 299) = 0;
  }
  return;
}

/* FUN_00090470 @ 0x90470 (952 bytes) */
int FUN_00090470(param_1)
  int param_1;
{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x1868) != '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
      *(code **)(((unsigned char *)0x000012b4) + param_1) = FUN_000900a0;
    }
    else {
      *(undefined **)(((unsigned char *)0x000012b4) + param_1) = PTR_FUN_001e89ec;
    }
  }
  if ((*(uint *)(param_1 + 0x1808) & 0x20000000) != 0) {
    FUN_000a4980(param_1);
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  if (uVar1 != 0) {
    if ((uVar1 & 4) != 0) {
      FUN_0004ea70(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 2) != 0) {
      FUN_0004eba0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 8) != 0) {
      FUN_0004ed90(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x400) != 0) {
      FUN_000520c0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x100) != 0) {
      FUN_0004f2e0(param_1);
      FUN_0009cf10(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x800) != 0) {
      FUN_0009cff0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x4000) != 0) {
      FUN_0004f080(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x2200) != 0) {
      FUN_0004def0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      if ((uVar1 & 0x20000) != 0) {
        ((int (*)())FUN_000867b0)(param_1);
        uVar1 = *(uint *)(param_1 + 0x38);
      }
      if ((uVar1 & 0x20) != 0) {
        FUN_000bd9a0(param_1);
        uVar1 = *(uint *)(param_1 + 0x38);
      }
      if ((uVar1 & 0x1000) != 0) {
        if (*(char *)(param_1 + 0x1868) == '\0') {
          FUN_00064f40(param_1);
        }
        else {
          (**(code **)((int)((unsigned char *)0x000011cc) + param_1))(param_1);
        }
      }
    }
    else if ((uVar1 & 0x20) != 0) {
      FUN_0004d620(param_1);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x3c);
  if (uVar1 != 0) {
    if ((uVar1 & 1) != 0) {
      FUN_0004dac0(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 2) != 0) {
      FUN_0004f550(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 8) != 0) {
      FUN_00051420(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x10) != 0) {
      FUN_0004ff70(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x20) != 0) {
      FUN_00051010(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x40) != 0) {
      FUN_00050140(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x400) != 0) {
      FUN_0004dc30(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_000a5ec0(param_1);
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      if ((((*(uint *)(param_1 + 0x38) & 0x4b928) != 0) || (*(short *)(param_1 + 0x34) != 0)) ||
         (*(char *)(param_1 + 299) != '\0')) {
        ((int (*)())FUN_000900a0)(param_1);
      }
    }
    else {
      FUN_0004dbe0(param_1);
    }
  }
  FUN_0004d100(param_1);
  FUN_00052280(param_1);
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined4 *)(param_1 + 0x1810) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x180c) = 0;
  return;
}

