#include "decls.h"

/* FUN_0000bf70 @ 0xbf70 (80 bytes) */
int FUN_0000bf70(param_1, param_2, param_3)
  int param_1;
  ulonglong param_2;
  longlong param_3;
{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)*(uint *)(param_1 + 0x144);
  lVar1 = 0;
  lVar2 = ((param_2 & uVar3 - 1) + param_3) - uVar3;
  if (0 < lVar2) {
    do {
      dataCacheBlockFlush((-uVar3 & param_2) + lVar1);
      lVar1 = lVar1 + uVar3;
    } while ((int)lVar1 < (int)lVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + lVar1);
  sync(0);
  instructionSynchronize();
  return;
}

/* FUN_0000bfc0 @ 0xbfc0 (400 bytes) */
int FUN_0000bfc0(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  puVar3 = PTR_0000f1a0;
  puVar4 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar4 + 0x10) {
    puVar1 = *(uint **)(param_1 + 0x30);
    *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar2 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar2 + 0x20;
    *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    puVar4 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar1 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar4 + 0x10;
  *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = puVar4;
  *puVar4 = 0x15000000;
  puVar4[1] = 0x20202020;
  puVar3 = PTR_0000f1a0;
  puVar1 = *(uint **)(param_1 + 0x30);
  *puVar1 = *(int *)(param_1 + 0x34) - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_0000c160 @ 0xc160 (848 bytes) */
int FUN_0000c160(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  longlong lVar9;
  float local_44;
  float local_3c;
  
  if (param_4 == 1) {
    uVar1 = *(uint *)(param_1 + 0x588);
    uVar2 = *(uint *)(param_1 + 0x578);
    uVar3 = *(uint *)(param_1 + 0x57c) >> 1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x588);
    uVar2 = *(uint *)(param_1 + 0x578);
    uVar3 = *(uint *)(param_1 + 0x57c) >> 2;
  }
  uVar2 = uVar2 >> 2;
  lVar9 = 0x18;
  puVar6 = param_2;
  do {
    *puVar6 = 0x80000000;
    puVar6 = puVar6 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  param_2[0x18] = 0x1120;
  uVar8 = uVar2 - 1 | (uVar3 - 1) * 0x800 | 0x80000000;
  param_2[0x19] = uVar8;
  param_2[0x1a] = 0x1140;
  iVar7 = (uVar1 >> 1 & 0x7ffffffe) - 1;
  param_2[0x1b] = iVar7;
  param_2[0x1c] = 0x1121;
  param_2[0x1d] = uVar8;
  param_2[0x1e] = 0x1141;
  param_2[0x1f] = iVar7;
  param_2[0x20] = 0x1122;
  param_2[0x21] = uVar8;
  param_2[0x22] = 0x1142;
  param_2[0x23] = iVar7;
  param_2[0x24] = 0x1123;
  param_2[0x25] = uVar8;
  param_2[0x26] = 0x1143;
  param_2[0x27] = iVar7;
  param_2[0x28] = 0x1124;
  param_2[0x29] = uVar8;
  param_2[0x2a] = 0x1144;
  param_2[0x2b] = iVar7;
  param_2[0x2c] = 0x82d;
  param_2[0x2d] = 4;
  param_2[0x2e] = 0xc0103500;
  param_2[0x2f] = 0x4003d;
  fVar5 = FLOAT_0000d43c;
  fVar4 = FLOAT_0000d430;
  if (param_5 == 1) {
    if (*(int *)(param_3 + 8) == 0) {
LAB_0000c3c0:
      local_44 = FLOAT_0000d43c / (float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_0000d418);
      goto LAB_0000c3e4;
    }
  }
  else if (*(int *)(param_3 + 8) != 0) goto LAB_0000c3c0;
  local_44 = FLOAT_0000d438 / (float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_0000d418);
LAB_0000c3e4:
  local_3c = local_44 + FLOAT_0000d43c;
  local_44 = local_44 + FLOAT_0000d430;
  param_2[0x30] = 0;
  param_2[0x31] = 0;
  param_2[0x32] = fVar4;
  param_2[0x33] = local_44;
  param_2[0x34] = uVar3 << 0x10;
  param_2[0x35] = 0x10000;
  param_2[0x36] = fVar4;
  param_2[0x37] = local_3c;
  param_2[0x38] = uVar2 | uVar3 << 0x10;
  param_2[0x39] = &DAT_00010001;
  param_2[0x3a] = fVar5;
  param_2[0x3b] = local_3c;
  param_2[0x3c] = uVar2;
  param_2[0x3d] = 1;
  param_2[0x3e] = fVar5;
  param_2[0x3f] = local_44;
  param_2[0x40] = 0x1393;
  param_2[0x41] = 10;
  return param_2 + 0x42;
}

/* FUN_0000c4b0 @ 0xc4b0 (1508 bytes) */
int FUN_0000c4b0(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  bool bVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar4;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  puVar3 = PTR_0000f1a0;
  puVar9 = *(undefined4 **)(param_1 + 0x34);
  if (*(undefined4 **)(param_1 + 0x38) <= puVar9 + 0x188) {
    puVar2 = *(uint **)(param_1 + 0x30);
    *puVar2 = (int)puVar9 - (int)puVar2 >> 2 | *puVar2;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar7 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar7 + 0x20;
    *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    puVar9 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar2 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar9 + 0x188;
  *puVar2 = (int)puVar9 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = puVar9;
  *puVar9 = 0x3d000000;
  puVar9[1] = (int)*param_2;
  puVar9[2] = (int)param_2[1];
  puVar9[3] = *(undefined4 *)(param_2 + 8);
  puVar9[4] = (int)param_4;
  puVar9[5] = -0x80000000;
  puVar9[6] = -0x80000000;
  puVar9[7] = 0x80000000;
  puVar9[8] = 0x80000000;
  puVar9[9] = 0x80000000;
  puVar5 = (undefined4 *)FUN_000096a0(puVar9 + 10);
  *puVar5 = 0x850;
  puVar5[1] = 0x102;
  puVar5[2] = 0x854;
  puVar5[3] = 0x6060006;
  puVar5[4] = 0x855;
  puVar5[5] = ((unsigned char *)0x00002701);
  puVar5[6] = 0x878;
  puVar5[7] = 0xf688f688;
  puVar5[8] = 0x879;
  puVar5[9] = 0xf688f688;
  puVar5[10] = 0x824;
  puVar5[0xb] = 1;
  puVar5[0xc] = 0x825;
  puVar5[0xd] = 0x12;
  puVar5[0xe] = ((unsigned char *)0x000010c0);
  puVar5[0xf] = 0x40004;
  puVar5[0x10] = ((unsigned char *)0x000010c1);
  puVar5[0x11] = 1;
  uVar8 = 0;
  iVar7 = 1;
  puVar5 = puVar5 + 0x12;
  do {
    puVar6 = puVar5;
    *puVar6 = ((unsigned char *)0x0000101d) + uVar8;
    puVar6[1] = uVar8 << 1 | iVar7 << 6 | 0x28ffe000;
    puVar6[2] = ((unsigned char *)0x000010c8) + uVar8;
    puVar6[3] = uVar8 | uVar8 << 5 | 0x10;
    bVar1 = uVar8 != 1;
    iVar7 = iVar7 + 2;
    uVar8 = uVar8 + 1;
    puVar5 = puVar6 + 4;
  } while (bVar1);
  puVar6[4] = 0x1100;
  puVar6[5] = 0xa92;
  puVar6[6] = 0x1110;
  puVar6[7] = 0;
  puVar6[8] = 0x1130;
  puVar6[9] = 0x4000a60c;
  puVar6[10] = 0x1101;
  puVar6[0xb] = &DAT_10000a92;
  puVar6[0xc] = 0x1111;
  puVar6[0xd] = 0;
  puVar6[0xe] = 0x1131;
  puVar6[0xf] = 0x4800a60c;
  puVar6[0x10] = 0x1102;
  puVar6[0x11] = 0x20000a92;
  puVar6[0x12] = 0x1112;
  puVar6[0x13] = 0;
  puVar6[0x14] = 0x1132;
  puVar6[0x15] = 0x2800a60c;
  puVar6[0x16] = 0x1103;
  puVar6[0x17] = 0x30000a92;
  puVar6[0x18] = 0x1113;
  puVar6[0x19] = 0;
  puVar6[0x1a] = 0x1133;
  puVar6[0x1b] = 0x3000a60c;
  puVar6[0x1c] = 0x1104;
  puVar6[0x1d] = 0x40000a92;
  puVar6[0x1e] = 0x1114;
  puVar6[0x1f] = 0;
  puVar6[0x20] = 0x1134;
  puVar6[0x21] = 0x3800a60c;
  puVar6[0x22] = ((unsigned char *)0x00001041);
  puVar6[0x23] = 0x1f;
  DAT_0000f054 = FLOAT_0000d468;
  DAT_0000f060 = FLOAT_0000d468;
  DAT_0000f070 = FLOAT_0000d46c;
  DAT_0000f090 = FLOAT_0000d470;
  DAT_0000f058 = FLOAT_0000d468;
  DAT_0000f05c = FLOAT_0000d468;
  DAT_0000f064 = FLOAT_0000d46c;
  DAT_0000f068 = FLOAT_0000d46c;
  DAT_0000f06c = FLOAT_0000d46c;
  DAT_0000f074 = FLOAT_0000d470;
  DAT_0000f078 = FLOAT_0000d470;
  DAT_0000f07c = FLOAT_0000d470;
  DAT_0000f080 = FLOAT_0000d470;
  DAT_0000f084 = FLOAT_0000d470;
  DAT_0000f088 = FLOAT_0000d470;
  DAT_0000f08c = FLOAT_0000d470;
  puVar5 = (undefined4 *)FUN_000099b0(puVar6 + 0x24,&DAT_0000ece4,0x16,&DAT_0000f054,6,9);
  *puVar5 = 0x11a9;
  puVar5[1] = ((unsigned char *)0x00001b00);
  puVar5[2] = 0x11aa;
  puVar5[3] = ((unsigned char *)0x00001b00);
  puVar5[4] = 0x11ab;
  puVar5[5] = ((unsigned char *)0x00001b00);
  puVar5[6] = 0x11ac;
  puVar5[7] = 0xf;
  puVar9[5] = (int)(puVar5 + 8) - (int)puVar9 >> 2;
  uVar4 = ((int (*)())FUN_0000c160)(param_1,puVar5 + 8,param_2,1,param_4);
  puVar9[6] = (int)uVar4 - (int)puVar9 >> 2;
  ((int (*)())FUN_0000c160)(param_1,uVar4,param_2,2,param_4);
  puVar3 = PTR_0000f1a0;
  puVar2 = *(uint **)(param_1 + 0x30);
  *puVar2 = *(int *)(param_1 + 0x34) - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar3,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar7 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar7 + 0x20;
  *(int *)(param_1 + 0x30) = iVar7 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar7 + 0x20 + *(int *)(iVar7 + 0x10) * 4;
  *(undefined4 *)(iVar7 + 0x1c) = 0;
  return;
}

/* FUN_0000caa0 @ 0xcaa0 (92 bytes) */
int FUN_0000caa0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x120) == 4) {
    ((int (*)())FUN_0000c4b0)();
  }
  *(undefined4 *)(*(int *)(param_1 + 0xac4) * 8 + param_1 + 0xacc) =
       *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x18);
  return;
}

/* FUN_0000cb00 @ 0xcb00 (1136 bytes) */
int FUN_0000cb00(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  short sStack0000001c;
  short sStack0000001e;
  short sStack00000020;
  short sStack00000022;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  uint uStack_44;
  undefined4 local_40;
  uint uStack_3c;
  undefined4 local_38;
  uint uStack_34;
  
  puVar6 = PTR_0000f1a0;
  local_40 = 0x43300000;
  local_50 = 0x43300000;
  local_58 = 0x43300000;
  local_48 = 0x43300000;
  sStack00000022 = (short)param_3;
  sStack0000001e = (short)param_2;
  sStack00000020 = (short)((uint)param_3 >> 0x10);
  sStack0000001c = (short)((uint)param_2 >> 0x10);
  puVar8 = *(undefined4 **)(param_1 + 0x34);
  uStack_4c = (int)sStack0000001e ^ 0x80000000;
  uStack_3c = (int)sStack00000022 ^ 0x80000000;
  uStack_54 = (int)sStack0000001c ^ 0x80000000;
  uStack_44 = (int)sStack00000020 ^ 0x80000000;
  uVar1 = *(uint *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 100);
  uVar5 = uVar1 >> 1;
  local_70 = (float)((double)CONCAT44(0x43300000,uStack_54) - DOUBLE_0000d420);
  local_6c = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_0000d420);
  local_78 = (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_0000d420) * FLOAT_0000d464;
  local_74 = (float)((double)CONCAT44(0x43300000,uStack_3c) - DOUBLE_0000d420) * FLOAT_0000d464;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x1c)) = param_2;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)) = param_3;
  local_68 = local_78;
  local_64 = local_74;
  local_60 = local_70;
  local_5c = local_6c;
  if (*(undefined4 **)(param_1 + 0x38) <= puVar8 + 0xa8) {
    puVar3 = *(uint **)(param_1 + 0x30);
    *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
    **(undefined4 **)(param_1 + 0x34) = 0x1000000;
    _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                        param_1 + 0x44,1);
    iVar4 = *(int *)(param_1 + 0x40);
    *(int *)(param_1 + 0x34) = iVar4 + 0x20;
    *(int *)(param_1 + 0x30) = iVar4 + 0x1c;
    *(int *)(param_1 + 0x38) = iVar4 + 0x20 + *(int *)(iVar4 + 0x10) * 4;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    puVar8 = *(undefined4 **)(param_1 + 0x34);
  }
  puVar3 = *(uint **)(param_1 + 0x30);
  *(undefined4 **)(param_1 + 0x34) = puVar8 + 0xa8;
  *puVar3 = (int)puVar8 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = puVar8;
  *puVar8 = 0x18000000;
  puVar8[1] = param_4;
  puVar8[2] = 3;
  puVar8[3] = param_5;
  puVar8 = puVar8 + 4;
  lVar9 = 8;
  do {
    *puVar8 = 0x80000000;
    puVar8 = puVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  uVar7 = FUN_000096a0();
  puVar8 = (undefined4 *)FUN_00009700(uVar7,1);
  *puVar8 = 0x1100;
  puVar8[1] = 0xa92;
  puVar8[2] = 0x1110;
  puVar8[3] = 0;
  puVar8[4] = 0x1120;
  puVar8[5] = (iVar2 + -1) * 0x800 | (uVar1 >> 2) - 1 | 0x80000000;
  puVar8[6] = 0x1130;
  puVar8[7] = 0x10108802;
  puVar8[8] = 0x1140;
  puVar8[9] = 0xbf;
  puVar8[10] = 0x1101;
  puVar8[0xb] = &DAT_10000a92;
  puVar8[0xc] = 0x1111;
  puVar8[0xd] = 0;
  puVar8[0xe] = 0x1121;
  puVar8[0xf] = 0x8000000f;
  puVar8[0x10] = 0x1131;
  puVar8[0x11] = 0x1800a60e;
  puVar8[0x12] = 0x1141;
  puVar8[0x13] = 0xf;
  puVar8[0x14] = ((unsigned char *)0x00001041);
  puVar8[0x15] = 3;
  local_38 = 0x43300000;
  DAT_0000f0b4 = (float)((double)CONCAT44(0x43300000,uVar5) - DOUBLE_0000d418);
  DAT_0000f0b8 = DAT_0000f0b4;
  DAT_0000f0bc = DAT_0000f0b4;
  DAT_0000f0c0 = DAT_0000f0b4;
  uStack_34 = uVar5;
  puVar8 = (undefined4 *)FUN_000099b0(puVar8 + 0x16,&DAT_0000eef4,9,&DAT_0000f0b4,1,4);
  *puVar8 = 0x11a9;
  puVar8[1] = 0x1b05;
  puVar8[2] = 0x11aa;
  puVar8[3] = 0xf;
  puVar8[4] = 0x11ab;
  puVar8[5] = 0xf;
  puVar8[6] = 0x11ac;
  puVar8[7] = 0xf;
  FUN_00009ac0(puVar8 + 8,&local_78,&local_68,uVar5,iVar2);
  puVar6 = PTR_0000f1a0;
  puVar3 = *(uint **)(param_1 + 0x30);
  *puVar3 = *(int *)(param_1 + 0x34) - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x30) = *(undefined4 **)(param_1 + 0x34);
  **(undefined4 **)(param_1 + 0x34) = 0x1000000;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 0x14),1,*(undefined4 *)puVar6,param_1 + 0x40,
                      param_1 + 0x44,1);
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x34) = iVar2 + 0x20;
  *(int *)(param_1 + 0x30) = iVar2 + 0x1c;
  *(int *)(param_1 + 0x38) = iVar2 + 0x20 + *(int *)(iVar2 + 0x10) * 4;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  return;
}

/* FUN_0000cf98 @ 0xcf98 (12 bytes) */
int FUN_0000cf98()
{
  return;
}

/* FUN_0000cfa4 @ 0xcfa4 (4 bytes) */
int FUN_0000cfa4()
{
  return;
}

/* FUN_0000cfa8 @ 0xcfa8 (24 bytes) */
int FUN_0000cfa8()
{
  return;
}

/* FUN_0000cfe8 @ 0xcfe8 (44 bytes) */
int FUN_0000cfe8()
{
  return;
}

