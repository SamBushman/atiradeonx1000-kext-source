#include "decls.h"

/* FUN_001b526e @ 0x1b526e (650 bytes) */
int FUN_001b526e(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int local_2c;
  char local_18;
  int local_10;
  
  iVar1 = *(int *)(param_1[4] + 0x24);
  uVar5 = *(uint *)(iVar1 + 4);
  if (uVar5 - 1 < uVar5) {
    piVar4 = (int *)(*(int *)(iVar1 + 8) + (uVar5 - 1) * 4);
  }
  else {
    piVar4 = (int *)0x0;
  }
  iVar2 = *piVar4;
  FUN_001a7f3c(iVar1,uVar5 - 1);
  iVar1 = param_1[0x18];
  cVar3 = FUN_000e1402(param_4,0x4b);
  if (cVar3 == '\0') {
    iVar6 = param_1[0x2a];
  }
  else {
    iVar6 = param_1[0x2a];
    piVar4 = (int *)(iVar6 + (iVar1 + -1) * 0x48);
    if ((((*piVar4 == 5) && (*(char *)((int)piVar4 + 0xe) == '\0')) &&
        ((piVar4[4] & 0xff00ffU) == 1)) && (*(char *)(iVar6 + 0xf + iVar2 * 0x48) == '\0')) {
      local_18 = *(char *)((int)piVar4 + 0x13) + '\x01';
      param_1[0x18] = param_1[0x18] + -1;
      param_1[0x2f] = param_1[0x2f] + 1;
      *(int *)(param_1[4] + 0x1c) = *(int *)(param_1[4] + 0x1c) + 1;
      iVar6 = param_1[0x2a];
      goto LAB_001b5324;
    }
  }
  param_1[0x2f] = 0;
  local_18 = '\x01';
LAB_001b5324:
  *(short *)(iVar6 + 0xc + iVar2 * 0x48) = (short)param_1[0x18] - (short)param_1[0x1d];
  local_2c = param_1[0x2e];
  param_1[local_2c + 0x30] = iVar2;
  iVar1 = param_1[0x2f];
  if (0 < iVar1) {
    iVar6 = param_1[0x2a];
    uVar5 = (uint)*(byte *)(iVar6 + 0x13 + iVar2 * 0x48);
    piVar4 = param_1 + local_2c + 0x30;
    local_10 = 0;
    while( true ) {
      uVar5 = uVar5 + (*(char *)(*piVar4 * 0x48 + 0xf + iVar6) == '\0');
      iVar2 = piVar4[1];
      iVar6 = iVar6 + iVar2 * 0x48;
      if (*(char *)(iVar6 + 0xf) == '\x01') {
        uVar5 = uVar5 + 1;
      }
      *(char *)(iVar6 + 0x13) = (char)uVar5;
      if (uVar5 != 0) {
        *(undefined1 *)(iVar2 * 0x48 + 0x15 + param_1[0x2a]) = 1;
      }
      local_10 = local_10 + 1;
      piVar4 = piVar4 + 1;
      if (local_10 == iVar1) break;
      iVar6 = param_1[0x2a];
    }
    local_2c = param_1[0x2e];
  }
  param_1[0x2e] = local_2c + -1;
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x10 + param_1[0x18] * 0x48) = 1;
  *(undefined1 *)(param_1[0x2a] + 0x14 + param_1[0x18] * 0x48) = 1;
  *(char *)(param_1[0x2a] + 0x13 + param_1[0x18] * 0x48) = local_18;
  (**(code **)(*param_1 + 0x15c))(param_1);
  if (*(char *)(param_2 + 0xdc) != '\0') {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x34))();
  return;
}

/* FUN_001b54f8 @ 0x1b54f8 (167 bytes) */
int FUN_001b54f8(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0xc + *(int *)(param_1 + 0x60) * 0x48) = param_5;
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0xa8);
    iVar4 = FUN_0010b0f4(param_4,0);
    uVar3 = FUN_001a90b8(*(undefined4 *)(iVar4 + 0x10));
    *(undefined1 *)(iVar2 + iVar1 * 0x48 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0xa8) + 0x18 + *(int *)(param_1 + 0x60) * 0x48) = param_5;
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0xa8);
    iVar4 = FUN_0010b0f4(param_4,0);
    *(bool *)(iVar2 + iVar1 * 0x48 + 0x20) = *(char *)(iVar4 + 0x13) == '\0';
  }
  return;
}

/* FUN_001b55a0 @ 0x1b55a0 (488 bytes) */
int FUN_001b55a0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  int local_28;
  undefined1 local_1e;
  
  switch(*(undefined4 *)(param_4 + 300)) {
  default:
    local_28 = 2;
    local_1e = 0;
    break;
  case 1:
    local_28 = 2;
    local_1e = 3;
    break;
  case 2:
    local_28 = 1;
    local_1e = 1;
    break;
  case 3:
    local_28 = 2;
    local_1e = 2;
    break;
  case 4:
    local_28 = 2;
    local_1e = 1;
    break;
  case 5:
    local_28 = 1;
    local_1e = 2;
  }
  bVar4 = FUN_001a90e8(1,0);
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x60) * 0x48) = 4;
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0x60);
    iVar3 = *(int *)(param_1 + 0xa8);
    iVar6 = FUN_0010b0f4(param_4,0);
    uVar5 = FUN_001a90b8(*(undefined4 *)(iVar6 + 0x10));
    *(undefined1 *)(iVar3 + iVar2 * 0x48 + 0x15) = uVar5;
    if (local_28 == 1) {
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x2d + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 ^ bVar4;
    }
    else {
      pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x2e + *(int *)(param_1 + 0x60) * 0x48);
      *pbVar1 = *pbVar1 ^ bVar4;
    }
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x16 + *(int *)(param_1 + 0x60) * 0x48) = local_1e;
  }
  if (param_3 != 0) {
    iVar2 = *(int *)(param_1 + 0x60);
    iVar3 = *(int *)(param_1 + 0xa8);
    iVar6 = FUN_0010b0f4(param_4,0);
    *(bool *)(iVar3 + iVar2 * 0x48 + 0x21) = *(char *)(iVar6 + 0x13) == '\0';
  }
  if (local_28 != 1) {
    pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x3d + *(int *)(param_1 + 0x60) * 0x48);
    *pbVar1 = *pbVar1 ^ bVar4;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x22 + *(int *)(param_1 + 0x60) * 0x48) = local_1e;
    return;
  }
  pbVar1 = (byte *)(*(int *)(param_1 + 0xa8) + 0x3c + *(int *)(param_1 + 0x60) * 0x48);
  *pbVar1 = *pbVar1 ^ bVar4;
  *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x22 + *(int *)(param_1 + 0x60) * 0x48) = local_1e;
  return;
}

/* FUN_001b57a2 @ 0x1b57a2 (416 bytes) */
int FUN_001b57a2(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined1 local_10;
  
  iVar1 = *(int *)(param_4 + 0x98);
  iVar2 = *(int *)(param_4 + 0x94);
  if (iVar1 == 0x2c) {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x15 + *(int *)(param_1 + 0x60) * 0x48) = 7;
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x21 + *(int *)(param_1 + 0x60) * 0x48) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0xac) + 0x9374) = 1;
    bVar6 = -(*(int *)(param_4 + 300) == 0) & 2;
    if ((*(byte *)(param_4 + 0x15) & 0x10) != 0) {
      bVar6 = bVar6 | 1;
    }
    *(byte *)(*(int *)(param_1 + 0xa8) + 0x16 + *(int *)(param_1 + 0x60) * 0x48) = bVar6;
    *(byte *)(*(int *)(param_1 + 0xa8) + 0x22 + *(int *)(param_1 + 0x60) * 0x48) = bVar6;
    return;
  }
  if (iVar1 == 9) {
    iVar5 = iVar2 + 1;
    iVar4 = *(int *)(*(int *)(param_1 + 0xac) + 0x9374);
    if (iVar5 <= iVar4) {
      iVar5 = iVar4;
    }
    *(int *)(*(int *)(param_1 + 0xac) + 0x9374) = iVar5;
  }
  local_10 = (undefined1)iVar2;
  if ((param_2 != '\0') && (iVar1 != 8)) {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x16 + *(int *)(param_1 + 0x60) * 0x48) = local_10;
    iVar2 = *(int *)(param_1 + 0x60);
    iVar4 = *(int *)(param_1 + 0xa8);
    iVar5 = FUN_0010b0f4(param_4,0);
    uVar3 = FUN_001a90b8(*(undefined4 *)(iVar5 + 0x10));
    *(undefined1 *)(iVar4 + iVar2 * 0x48 + 0x15) = uVar3;
  }
  if (param_3 != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x22 + *(int *)(param_1 + 0x60) * 0x48) = local_10;
    if (iVar1 == 8) {
      *(undefined1 *)(*(int *)(param_1 + 0xa8) + 0x23 + *(int *)(param_1 + 0x60) * 0x48) = 1;
      return;
    }
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0xa8);
    iVar4 = FUN_0010b0f4(param_4,0);
    *(bool *)(iVar2 + iVar1 * 0x48 + 0x21) = *(char *)(iVar4 + 0x13) == '\0';
  }
  return;
}

/* FUN_001b5942 @ 0x1b5942 (2480 bytes) */
int FUN_001b5942(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  undefined2 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  undefined4 uVar12;
  byte bVar13;
  undefined4 local_64;
  undefined4 local_60;
  int *local_5c;
  undefined1 local_54;
  int local_50 [5];
  int local_3c [4];
  int local_2c;
  int local_28;
  
  piVar7 = (int *)FUN_0010b180(param_2,1);
  cVar2 = (**(code **)(*piVar7 + 0x60))(piVar7);
  if (cVar2 != '\0') {
    iVar9 = FUN_0010b0f4(piVar7,1);
    uVar12 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(param_2,1);
    local_60 = *(undefined4 *)(iVar9 + 0x10);
    local_64 = FUN_000f5610(uVar12,local_60);
    piVar11 = (int *)FUN_0010b180(piVar7,1);
    FUN_0010ba02(param_2,1,piVar11,0,param_4);
    iVar9 = FUN_0010b0f4(piVar7,1);
    uVar12 = *(undefined4 *)(iVar9 + 0x10);
    iVar9 = FUN_0010b0f4(param_2,1);
    *(undefined4 *)(iVar9 + 0x10) = uVar12;
    local_5c = piVar7;
  }
  else {
    local_5c = (int *)0x0;
    piVar11 = piVar7;
  }
  uVar6 = (**(code **)(*param_1 + 0x158))(param_1,param_2,1,param_4);
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 2;
  *(undefined2 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = uVar6;
  local_50[0] = *(int *)(*(int *)(param_2 + 0x88) + 8);
  iVar9 = *(int *)(param_2 + 0x134);
  if (local_50[0] == 0x77) {
    *(undefined1 *)(param_1[0x2a] + 0x19 + param_1[0x18] * 0x48) = 0;
    *(undefined2 *)(param_1[0x2a] + 0xc + param_1[0x18] * 0x48) = 0;
    *(undefined4 *)(FUN_00009369 + param_1[0x2b] + 7) = 1;
    iVar8 = (**(code **)(*piVar11 + 0x80))(piVar11);
  }
  else {
    local_54 = (undefined1)iVar9;
    *(undefined1 *)(param_1[0x2a] + 0x19 + param_1[0x18] * 0x48) = local_54;
    iVar8 = param_1[0x18];
    iVar1 = param_1[0x2a];
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),param_2);
    *(undefined2 *)(iVar1 + iVar8 * 0x48 + 0xc) = uVar6;
    iVar8 = (**(code **)(*piVar11 + 0x80))(piVar11);
  }
  if (iVar8 == 0) {
    *(undefined4 *)(param_1[0x2b] + 0x9378 + iVar9 * 4) = 1;
  }
  if (*(int *)(PTR_DAT_00213a35 + local_50[0] * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x2a] + 0x1a + param_1[0x18] * 0x48) =
         (char)*(int *)(PTR_DAT_00213a35 + local_50[0] * 0x38 + 0xc);
  }
  iVar9 = *(int *)(*(int *)(*(int *)(param_4 + 0x3f4) + 0x78) + 4 + iVar9 * 0xc);
  if (iVar9 == 2) {
    bVar13 = 0xc;
  }
  else {
    if (iVar9 < 3) {
      if (iVar9 == 1) {
        bVar13 = 0xe;
        iVar9 = *(int *)(param_2 + 0x138);
        goto joined_r0x001b5ab9;
      }
    }
    else if (iVar9 < 5) {
      bVar13 = 8;
      goto LAB_001b5aa5;
    }
    bVar13 = 0;
  }
LAB_001b5aa5:
  iVar9 = *(int *)(param_2 + 0x138);
joined_r0x001b5ab9:
  if (local_50[0] == 0x77) {
    *(undefined1 *)(param_1[0x2a] + 0x1f + param_1[0x18] * 0x48) = 0;
    iVar9 = FUN_0010b0f4(param_2,1);
    uVar12 = FUN_000f5b3c(*(undefined4 *)(iVar9 + 0x10));
    *(undefined4 *)(param_2 + 0x9c) = uVar12;
    iVar9 = FUN_0010b0f4(param_2,1);
    *(undefined4 *)(iVar9 + 0x10) = DAT_001cf324;
  }
  else {
    if ((local_50[0] - 0x75U < 2) || (local_50[0] == 0xae)) {
      *(byte *)(param_1[0x2a] + 0x1f + param_1[0x18] * 0x48) = bVar13 & 7;
      iVar8 = param_1[0x18];
    }
    else {
      *(byte *)(param_1[0x2a] + 0x1f + param_1[0x18] * 0x48) = bVar13;
      iVar8 = param_1[0x18];
    }
    *(bool *)(param_1[0x2a] + 0x18 + iVar8 * 0x48) = iVar9 == 1;
    iVar9 = param_1[0x18];
    iVar8 = param_1[0x2a];
    if (((*(byte *)(param_2 + 0x15) & 0x20) == 0) &&
       (cVar5 = FUN_000e1402(param_4,0x22), cVar5 != '\0')) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined1 *)(iVar8 + iVar9 * 0x48 + 0x1c) = uVar3;
  }
  iVar9 = FUN_0010b0f4(param_2,1);
  uVar10 = FUN_000f5c70(*(undefined4 *)(iVar9 + 0x10));
  *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xfc | (byte)uVar10 & 3;
  *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xf3 | (byte)(uVar10 >> 6) & 0xc;
  *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xcf |
       ((byte)(uVar10 >> 0x10) & 3) << 4;
  *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0x3f | (char)(uVar10 >> 0x18) << 6;
  uVar10 = FUN_000f5c70(*(undefined4 *)(param_2 + 0x140));
  *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) & 0xfc | (byte)uVar10 & 3;
  *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) & 0xf3 | (byte)(uVar10 >> 6) & 0xc;
  *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) & 0xcf |
       ((byte)(uVar10 >> 0x10) & 3) << 4;
  *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) =
       *(byte *)(param_1[0x18] * 0x48 + 0x14 + param_1[0x2a]) & 0x3f | (char)(uVar10 >> 0x18) << 6;
  *(undefined1 *)(param_1[0x2a] + 0x1d + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x1e + param_1[0x18] * 0x48) = 0;
  iVar9 = param_1[0x2a] + param_1[0x18] * 0x48;
  bVar13 = *(byte *)(iVar9 + 0x1d);
  iVar8 = FUN_0010b0f4(param_2,0);
  bVar4 = FUN_001a90b8(*(undefined4 *)(iVar8 + 0x10));
  *(byte *)(iVar9 + 0x1d) = bVar13 | bVar4;
  iVar9 = param_1[0x2a] + param_1[0x18] * 0x48;
  bVar13 = *(byte *)(iVar9 + 0x1e);
  iVar8 = FUN_0010b0f4(param_2,0);
  *(byte *)(iVar9 + 0x1e) = *(char *)(iVar8 + 0x13) == '\0' | bVar13;
  *(undefined2 *)(param_1[0x2a] + 0x10 + param_1[0x18] * 0x48) = 0;
  *(undefined2 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0;
  param_1[0x2c] = param_1[0x18];
  if (local_50[0] == 0x78) {
    iVar9 = FUN_0010b0f4(param_2,2);
    uVar10 = *(uint *)(iVar9 + 0x10);
    *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) & 0xfc | (byte)uVar10 & 3;
    *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) & 0xf3 | (byte)(uVar10 >> 6) & 0xc;
    *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) & 0xcf |
         ((byte)(uVar10 >> 0x10) & 3) << 4;
    *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x16 + param_1[0x2a]) & 0x3f |
         (byte)((uVar10 >> 0x18) << 6);
    iVar9 = param_1[0x18];
    iVar8 = param_1[0x2a];
    uVar12 = FUN_0010b180(param_2,2);
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),uVar12);
    *(undefined2 *)(iVar8 + iVar9 * 0x48 + 0x10) = uVar6;
    iVar9 = FUN_0010b0f4(param_2,3);
    uVar10 = *(uint *)(iVar9 + 0x10);
    *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) & 0xfc | (byte)uVar10 & 3;
    *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) & 0xf3 | (byte)(uVar10 >> 6) & 0xc;
    *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) & 0xcf |
         ((byte)(uVar10 >> 0x10) & 3) << 4;
    *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x17 + param_1[0x2a]) & 0x3f |
         (byte)((uVar10 >> 0x18) << 6);
    iVar9 = param_1[0x18];
    iVar8 = param_1[0x2a];
    uVar12 = FUN_0010b180(param_2,3);
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),uVar12);
    *(undefined2 *)(iVar8 + iVar9 * 0x48 + 0x12) = uVar6;
  }
  if (cVar2 != '\0') {
    iVar9 = 1;
    do {
      local_50[iVar9 + 8] = 0;
      local_50[iVar9] = 0;
      local_50[iVar9 + 4] = 0;
      iVar9 = iVar9 + 1;
    } while (iVar9 != 5);
    (**(code **)(*param_1 + 0xf8))(param_1,1,local_50 + 1,local_50 + 9,0,local_64);
    (**(code **)(*param_1 + 0x108))(param_1,1,local_50 + 9,local_5c,local_60);
    (**(code **)(*param_1 + 0x10c))(param_1,1,local_50 + 5,local_5c,local_60);
    FUN_0010ba02(param_2,1,local_5c,0,param_4);
    iVar9 = FUN_0010b0f4(param_2,1);
    *(undefined4 *)(iVar9 + 0x10) = local_60;
    *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xfc | (byte)local_28 & 3;
    *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xf3 |
         ((byte)(local_28 >> 3) & 3) << 2;
    *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0xcf |
         ((byte)(local_28 >> 6) & 3) << 4;
    *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) =
         *(byte *)(param_1[0x18] * 0x48 + 0x15 + param_1[0x2a]) & 0x3f |
         (char)(local_3c[1] >> 9) << 6;
  }
  return;
}

/* FUN_001b62f2 @ 0x1b62f2 (890 bytes) */
int FUN_001b62f2(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 local_34 [36];
  
  iVar1 = FUN_0010a17a(0x12,param_1[3]);
  iVar3 = param_1[3];
  uVar2 = FUN_0010b180(param_2,1);
  FUN_0010ba02(iVar1,1,uVar2,0,iVar3);
  iVar3 = FUN_0010b0f4(param_2,1);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_0010b0f4(iVar1,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  iVar4 = iVar1 + 0xa4;
  FUN_00109c0e(iVar4,2,*(uint *)(param_2 + 0xb8) >> 1 & 1);
  FUN_00109c0e(iVar4,1,*(byte *)(param_2 + 0xb8) & 1);
  iVar3 = param_1[3];
  uVar2 = FUN_0010b180(param_2,2);
  FUN_0010ba02(iVar1,2,uVar2,0,iVar3);
  iVar3 = FUN_0010b0f4(param_2,2);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = FUN_0010b0f4(iVar1,2);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  iVar5 = iVar1 + 0xbc;
  FUN_00109c0e(iVar5,2,*(uint *)(param_2 + 0xd0) >> 1 & 1);
  FUN_00109c0e(iVar5,1,*(byte *)(param_2 + 0xd0) & 1);
  *(undefined4 *)(iVar1 + 0x9c) = DAT_001cf328;
  iVar3 = FUN_0010b0f4(iVar1,0);
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  switch(*(undefined4 *)(param_2 + 300)) {
  case 0:
    FUN_00109c0e(iVar5,1,*(byte *)(param_2 + 0xd0) & 1 ^ 1);
    uVar6 = 0;
    break;
  case 1:
    FUN_00109c0e(iVar5,1,*(byte *)(param_2 + 0xd0) & 1 ^ 1);
    uVar6 = 3;
    break;
  case 2:
    FUN_00109c0e(iVar4,1,*(byte *)(param_2 + 0xb8) & 1 ^ 1);
    uVar6 = 1;
    break;
  case 3:
    FUN_00109c0e(iVar5,1,*(byte *)(param_2 + 0xd0) & 1 ^ 1);
    uVar6 = 2;
    break;
  case 4:
    FUN_00109c0e(iVar5,1,*(byte *)(param_2 + 0xd0) & 1 ^ 1);
    uVar6 = 1;
    break;
  case 5:
    FUN_00109c0e(iVar4,1,*(byte *)(param_2 + 0xb8) & 1 ^ 1);
  default:
    uVar6 = 2;
  }
  FUN_001a7e06(local_34);
  FUN_001a7cd6(local_34,iVar1);
  (**(code **)(*param_1 + 0x34))(param_1,local_34,param_3);
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -5) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -4) = uVar6;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x34) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x33) = 0;
  *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -3) = 1;
  return;
}

/* FUN_001b668c @ 0x1b668c (246 bytes) */
int FUN_001b668c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 1;
  *(undefined1 *)(param_1[0x2a] + 0x18 + param_1[0x18] * 0x48) = param_2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3c) = (short)param_1[0x18] + -1;
  puVar2 = *(uint **)(param_1[4] + 0x28);
  iVar1 = param_1[0x2a] + -0x48 + param_1[0x18] * 0x48;
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    *(int *)(uVar3 * 4 + puVar2[2]) = iVar1;
    return;
  }
  piVar4 = (int *)FUN_001a7f7c(puVar2,uVar3);
  *piVar4 = iVar1;
  return;
}

/* FUN_001b6782 @ 0x1b6782 (332 bytes) */
int FUN_001b6782(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0xff;
  if (param_3 == '\0') {
    *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 5;
  }
  else {
    *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 6;
  }
  if (param_2 < 1) {
    *(undefined1 *)(param_1[0x2a] + 0x15 + param_1[0x18] * 0x48) = 0;
  }
  else {
    *(undefined1 *)(param_1[0x2a] + 0x15 + param_1[0x18] * 0x48) = 1;
  }
  *(char *)(param_1[0x2a] + 0x13 + param_1[0x18] * 0x48) = (char)param_2;
  (**(code **)(*param_1 + 0x15c))(param_1);
  *(short *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x3c) = (short)param_1[0x18] + -1;
  puVar2 = *(uint **)(param_1[4] + 0x28);
  iVar1 = param_1[0x2a] + -0x48 + param_1[0x18] * 0x48;
  uVar3 = puVar2[1];
  if (*puVar2 <= uVar3) {
    piVar4 = (int *)FUN_001a7f7c(puVar2,uVar3);
    *piVar4 = iVar1;
    return;
  }
  _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
  puVar2[1] = uVar3 + 1;
  *(int *)(uVar3 * 4 + puVar2[2]) = iVar1;
  return;
}

/* FUN_001b68ce @ 0x1b68ce (238 bytes) */
int FUN_001b68ce(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
{
  char cVar1;
  undefined4 uVar2;
  char local_d;
  
  local_d = '\0';
  cVar1 = FUN_001b4dde(param_3,&local_d);
  if (local_d == '\0') {
    uVar2 = FUN_000eac0c(param_6,0);
    ((int (*)())FUN_001b62f2)(param_1,param_3,param_5,uVar2);
    ((int (*)())FUN_001b6782)(param_1,param_2 + -1,param_4);
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x36) = 0xf0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x3d) = 1;
    return;
  }
  if (cVar1 != '\0') {
    ((int (*)())FUN_001b6782)(param_1,param_2 + -1,param_4);
    if (param_5 != '\0') {
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + -0x44) = 1;
      return;
    }
  }
  return;
}

/* FUN_001b69bc @ 0x1b69bc (249 bytes) */
int FUN_001b69bc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_000e9644(param_2);
  (**(code **)(*piVar2 + 0x14))(piVar2);
  FUN_001a7d72(piVar2);
  *(undefined4 *)(param_2 + 0x128) = 0;
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  iVar1 = *(int *)(*(int *)(param_2 + 300) + 0xd0);
  if (*(int *)(iVar1 + 4) == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 8);
  }
  (**(code **)(*param_1 + 0x34))(param_1,*piVar2 + 0x90,*(undefined1 *)(*piVar2 + 0xdc));
  ((int (*)())FUN_001b68ce)();
  return;
}

/* FUN_001b6ab6 @ 0x1b6ab6 (140 bytes) */
int FUN_001b6ab6(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  bool bVar2;
  
  iVar1 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) == '\0') || (iVar1 != param_1[0x18])) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  ((int (*)())FUN_001b6782)(param_1,*(undefined4 *)(param_2 + 0x128),
               *(undefined1 *)(*(int *)(param_2 + 0x124) + 300));
  if (bVar2) {
    *(undefined1 *)(param_1[0x18] * 0x48 + param_1[0x2a] + -0x44) = 1;
  }
  return;
}

/* FUN_001b6b42 @ 0x1b6b42 (282 bytes) */
int FUN_001b6b42(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0xf;
  *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 0;
  *(undefined1 *)(param_1[0x2a] + 0x14 + param_1[0x18] * 0x48) = 2;
  if (param_2 != '\0') {
    *(undefined1 *)(param_1[0x2a] + 0x15 + param_1[0x18] * 0x48) = 2;
  }
  *(undefined1 *)(param_1[0x2a] + 0xb + param_1[0x18] * 0x48) = 1;
  iVar1 = param_1[0x18];
  puVar2 = *(uint **)(param_1[4] + 0x24);
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    *(int *)(uVar3 * 4 + puVar2[2]) = iVar1;
    (**(code **)(*param_1 + 0x15c))(param_1);
    param_1[0x2e] = param_1[0x2e] + 1;
    return;
  }
  piVar4 = (int *)FUN_001a7f7c(puVar2,uVar3);
  *piVar4 = iVar1;
  (**(code **)(*param_1 + 0x15c))(param_1);
  param_1[0x2e] = param_1[0x2e] + 1;
  return;
}

/* FUN_001b6c5c @ 0x1b6c5c (274 bytes) */
int FUN_001b6c5c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar2 = (int *)FUN_000e9644(param_2);
  (**(code **)(*piVar2 + 0x14))(piVar2);
  FUN_001a7d72(piVar2);
  *(undefined4 *)(param_2 + 0x128) = 0;
  iVar1 = param_1[0x18];
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined1 *)(param_2 + 0xdc));
  if ((*(char *)(param_2 + 0xdc) == '\0') || (iVar1 != param_1[0x18])) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  uVar3 = FUN_000eac0c(param_2,0);
  ((int (*)())FUN_001b62f2)(param_1,piVar2,uVar5,uVar3);
  iVar1 = *(int *)(param_2 + 0x130);
  iVar4 = FUN_001a7d8a(iVar1 + 0x90);
  if (iVar4 < 3) {
    FUN_000e97ce(iVar1);
  }
  ((int (*)())FUN_001b6b42)();
  return;
}

/* FUN_001b6d6e @ 0x1b6d6e (517 bytes) */
int FUN_001b6d6e(param_1, param_2)
  int *param_1;
  int *param_2;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = param_2[0x4c];
  iVar3 = FUN_001a7d8a(iVar6 + 0x90);
  if (iVar3 < 3) {
    cVar2 = FUN_000e97ce(iVar6);
    if (cVar2 != '\0') {
      if (*(int *)(*(int *)(iVar6 + 0xd0) + 4) == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = *(int **)(*(int *)(iVar6 + 0xd0) + 8);
      }
      if (*piVar4 == param_2[0x4d]) {
        return;
      }
    }
  }
  *(undefined4 *)(param_1[0x2a] + param_1[0x18] * 0x48) = 5;
  *(undefined1 *)(param_1[0x2a] + 0xe + param_1[0x18] * 0x48) = 0;
  cVar2 = (**(code **)(*param_2 + 0x40))(param_2);
  if (cVar2 == '\0') {
    *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0;
    *(undefined1 *)(param_1[0x2a] + 0x15 + param_1[0x18] * 0x48) = 1;
    *(undefined1 *)(param_1[0x2a] + 0x13 + param_1[0x18] * 0x48) = 1;
    *(undefined1 *)(param_1[0x2a] + 0xf + param_1[0x18] * 0x48) = 1;
    iVar6 = *(int *)(param_1[4] + 0x24);
    uVar7 = *(uint *)(iVar6 + 4);
    uVar5 = uVar7 - 1;
    if (uVar5 < uVar7) goto LAB_001b6f28;
  }
  else {
    *(undefined1 *)(param_1[0x2a] + 0x12 + param_1[0x18] * 0x48) = 0xff;
    iVar6 = *(int *)(param_1[4] + 0x24);
    uVar7 = *(uint *)(iVar6 + 4);
    uVar5 = uVar7 - 1;
    if (uVar5 < uVar7) {
LAB_001b6f28:
      piVar4 = (int *)(*(int *)(iVar6 + 8) + uVar5 * 4);
      goto LAB_001b6e14;
    }
  }
  piVar4 = (int *)0x0;
LAB_001b6e14:
  iVar3 = *piVar4;
  FUN_001a7f3c(iVar6,uVar7 - 1);
  *(short *)(param_1[0x2a] + 0xc + iVar3 * 0x48) = (short)param_1[0x18] - (short)param_1[0x1d];
  iVar6 = param_1[0x18];
  puVar1 = *(uint **)(param_1[4] + 0x24);
  uVar5 = puVar1[1];
  if (uVar5 < *puVar1) {
    _memset((void *)(uVar5 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar5 + 1;
    piVar4 = (int *)(uVar5 * 4 + puVar1[2]);
  }
  else {
    piVar4 = (int *)FUN_001a7f7c(puVar1,uVar5);
  }
  *piVar4 = iVar6;
  if (*(char *)(param_2[0x4d] + 0xdc) != '\0') {
    *(undefined1 *)(param_1[0x2a] + 4 + param_1[0x18] * 0x48) = 1;
  }
                    
                    
  (**(code **)(*param_1 + 0x15c))();
  return;
}

/* __i686_get_pc_thunk_bx @ 0x1bca0c (4 bytes) */
int __i686_get_pc_thunk_bx()
{
  return;
}

/* __i686_get_pc_thunk_cx @ 0x1bca10 (4 bytes) */
int __i686_get_pc_thunk_cx()
{
  return;
}

/* FUN_001bca14 @ 0x1bca14 (51 bytes) */
int FUN_001bca14(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbfc8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bca48 @ 0x1bca48 (5 bytes) */
int FUN_001bca48()
{
  return;
}

/* FUN_001bca4e @ 0x1bca4e (5 bytes) */
int FUN_001bca4e()
{
  return;
}

/* FUN_001bca54 @ 0x1bca54 (5 bytes) */
int FUN_001bca54()
{
  return;
}

/* FUN_001bca5a @ 0x1bca5a (14 bytes) */
int FUN_001bca5a(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x80);
}

/* FUN_001bca68 @ 0x1bca68 (5 bytes) */
int FUN_001bca68()
{
  return;
}

/* FUN_001bca6e @ 0x1bca6e (41 bytes) */
int FUN_001bca6e(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  if (((iVar1 != 6) && (iVar1 != 7)) && (iVar1 != 8)) {
    return 0;
  }
  return 1;
}

/* FUN_001bca98 @ 0x1bca98 (7 bytes) */
int FUN_001bca98()
{
  return 0;
}

/* FUN_001bcaa0 @ 0x1bcaa0 (7 bytes) */
int FUN_001bcaa0()
{
  return 0;
}

/* FUN_001bcaa8 @ 0x1bcaa8 (7 bytes) */
int FUN_001bcaa8()
{
  return 0;
}

/* FUN_001bcab0 @ 0x1bcab0 (7 bytes) */
int FUN_001bcab0()
{
  return 0;
}

/* FUN_001bcab8 @ 0x1bcab8 (7 bytes) */
int FUN_001bcab8()
{
  return 0;
}

/* FUN_001bcac0 @ 0x1bcac0 (24 bytes) */
int FUN_001bcac0(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 4) == 4;
}

/* FUN_001bcad8 @ 0x1bcad8 (7 bytes) */
int FUN_001bcad8()
{
  return 0;
}

/* FUN_001bcae0 @ 0x1bcae0 (7 bytes) */
int FUN_001bcae0()
{
  return 0;
}

/* FUN_001bcae8 @ 0x1bcae8 (7 bytes) */
int FUN_001bcae8()
{
  return 0;
}

/* FUN_001bcaf0 @ 0x1bcaf0 (7 bytes) */
int FUN_001bcaf0()
{
  return 0;
}

/* FUN_001bcaf8 @ 0x1bcaf8 (7 bytes) */
int FUN_001bcaf8()
{
  return 0;
}

/* FUN_001bcb00 @ 0x1bcb00 (7 bytes) */
int FUN_001bcb00()
{
  return 0;
}

/* FUN_001bcb08 @ 0x1bcb08 (7 bytes) */
int FUN_001bcb08()
{
  return 0;
}

/* FUN_001bcb10 @ 0x1bcb10 (7 bytes) */
int FUN_001bcb10()
{
  return 0;
}

/* FUN_001bcb18 @ 0x1bcb18 (7 bytes) */
int FUN_001bcb18()
{
  return 0;
}

/* FUN_001bcb20 @ 0x1bcb20 (7 bytes) */
int FUN_001bcb20()
{
  return 0;
}

/* FUN_001bcb28 @ 0x1bcb28 (7 bytes) */
int FUN_001bcb28()
{
  return 0;
}

/* FUN_001bcb30 @ 0x1bcb30 (7 bytes) */
int FUN_001bcb30()
{
  return 0;
}

/* FUN_001bcb38 @ 0x1bcb38 (7 bytes) */
int FUN_001bcb38()
{
  return 0;
}

/* FUN_001bcb40 @ 0x1bcb40 (7 bytes) */
int FUN_001bcb40()
{
  return 0;
}

/* FUN_001bcb48 @ 0x1bcb48 (7 bytes) */
int FUN_001bcb48()
{
  return 0;
}

/* FUN_001bcb50 @ 0x1bcb50 (7 bytes) */
int FUN_001bcb50()
{
  return 0;
}

/* FUN_001bcb58 @ 0x1bcb58 (17 bytes) */
int FUN_001bcb58(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x11c) = param_2;
  return;
}

/* FUN_001bcb6a @ 0x1bcb6a (10 bytes) */
int FUN_001bcb6a()
{
  return 1;
}

/* FUN_001bcb74 @ 0x1bcb74 (7 bytes) */
int FUN_001bcb74()
{
  return 0;
}

/* FUN_001bcb7c @ 0x1bcb7c (5 bytes) */
int FUN_001bcb7c()
{
  return;
}

/* FUN_001bcb82 @ 0x1bcb82 (16 bytes) */
int FUN_001bcb82()
{
  return "pseudo";
}

/* FUN_001bcb92 @ 0x1bcb92 (29 bytes) */
int FUN_001bcb92(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  *(undefined1 *)(param_2 * 0x18 + param_1 + param_3 + 0x9c) = param_4;
  return;
}

/* FUN_001bcbb0 @ 0x1bcbb0 (21 bytes) */
int FUN_001bcbb0(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbfc8;
  return;
}

/* FUN_001bcbc6 @ 0x1bcbc6 (24 bytes) */
int FUN_001bcbc6(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_001bcbde @ 0x1bcbde (54 bytes) */
int FUN_001bcbde(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213441 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bcc14 @ 0x1bcc14 (46 bytes) */
int FUN_001bcc14(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_001bcc42 @ 0x1bcc42 (76 bytes) */
int FUN_001bcc42(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bcc8e @ 0x1bcc8e (84 bytes) */
int FUN_001bcc8e(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbf08;
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bcce2 @ 0x1bcce2 (54 bytes) */
int FUN_001bcce2(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbcc8;
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

/* FUN_001bcd18 @ 0x1bcd18 (84 bytes) */
int FUN_001bcd18(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbcc8;
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001bcd6c @ 0x1bcd6c (54 bytes) */
int FUN_001bcd6c(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fbd88;
  *param_1 = PTR_DAT_00213449 + 8;
  *param_1 = PTR_DAT_00213445 + 8;
  *param_1 = PTR_DAT_00213441 + 8;
  return;
}

