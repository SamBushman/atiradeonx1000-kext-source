#include "decls.h"

/* FUN_00019c50 @ 0x19c50 (308 bytes) */
int FUN_00019c50(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x2a50);
    fVar1 = *(float *)(param_1 + 0x2a54);
    fVar2 = *(float *)(param_1 + 0x2a58);
    uVar3 = *(uint *)(param_1 + 0x154) & 0x700000;
    if (uVar3 == 0) {
      uVar3 = *(uint *)(param_1 + 0x154) & 0xc0000;
      if (uVar3 == 0x40000) {
        FUN_00019ad0(param_1,2);
      }
      else if (uVar3 == 0x80000) {
        FUN_00019ad0(param_1,4);
      }
      else {
        FUN_00019ad0(param_1,1);
      }
    }
    else if (uVar3 == 0x200000) {
      FUN_000199f0(param_1,4);
    }
    else if (uVar3 == 0x400000) {
      FUN_000199f0(param_1,6);
    }
    else if (uVar3 == 0x100000) {
      FUN_000199f0(param_1,2);
    }
    else {
      FUN_000199f0(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x2a48) = *(undefined4 *)(param_1 + 0x15c);
    *(undefined4 *)(param_1 + 0x2a4c) = *(undefined4 *)(param_1 + 0x160);
    if (((iVar4 != *(int *)(param_1 + 0x2a50)) || (fVar1 != *(float *)(param_1 + 0x2a54))) ||
       (fVar2 != *(float *)(param_1 + 0x2a58))) {
      *(undefined1 *)(param_1 + 0x2a43) = 1;
    }
  }
  return;
}

/* FUN_00019db0 @ 0x19db0 (544 bytes) */
int FUN_00019db0(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[0x3e] == 0) {
    return 0;
  }
  if (param_1[0x79] + 0x28U < (uint)param_1[0x77]) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  if ((param_1[0x55] & 0xfU) == 3) {
    bVar1 = true;
LAB_00019e50:
    FUN_00019ad0(param_1,param_2);
  }
  else {
    bVar1 = param_3 == 0;
    if (bVar1) goto LAB_00019e50;
    FUN_000199f0(param_1,param_2);
  }
  local_24 = param_1[0xf] & 0xff83efff;
  param_1[0xf] = local_24;
  if (bVar1) {
    if (GH_U2F((unsigned int)(param_1[0xa95])) <= FLOAT_001aa128) {
      if (FLOAT_001aa128 < GH_U2F((unsigned int)(param_1[0xa96]))) {
        local_24 = local_24 | 0x41000;
        param_1[0xf] = local_24;
        goto LAB_00019f40;
      }
    }
    else if (FLOAT_001aa128 < GH_U2F((unsigned int)(param_1[0xa96]))) {
      local_24 = local_24 | 0x81000;
      param_1[0xf] = local_24;
      goto LAB_00019f40;
    }
    param_1[0xf] = local_24;
  }
  else {
    iVar2 = param_1[0xa94];
    if (iVar2 == 6) {
      local_24 = local_24 | 0x401000;
      param_1[0xf] = local_24;
    }
    else if (iVar2 == 4) {
      local_24 = local_24 | 0x201000;
      param_1[0xf] = local_24;
    }
    else if (iVar2 == 2) {
      local_24 = local_24 | 0x101000;
      param_1[0xf] = local_24;
    }
  }
LAB_00019f40:
  if (param_1[0x54] == 0) {
    param_1[0x55] = local_24;
  }
  if ((local_24 & 0x20) == 0) {
    local_28 = ~(uint)*(byte *)(*(int *)(PTR_DAT_001e88ac + 0xc) + *param_1);
  }
  else {
    local_28 = *(uint *)(param_1[0x3e] + 8);
  }
  local_24 = local_24 & 0xffff3fc0;
  local_20 = param_1[0x3f];
  local_1c = param_1[0x40];
  _io_connect_method_scalarI_structureI(param_1[1],0,&local_28,4,0,0);
  ((int (*)())FUN_00019c50)(param_1);
  ((int (*)())FUN_00022eb0)(param_1,0);
  *(undefined1 *)(param_1 + 0xa91) = 1;
  return 0;
}

/* FUN_0001a010 @ 0x1a010 (176 bytes) */
int FUN_0001a010(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x154);
  if ((((uVar2 & 0x700000) == 0) &&
      (((uVar2 & 0xc0000) == 0 ||
       ((*(float *)(param_1 + 0x2a54) < FLOAT_001aa128 &&
        (*(float *)(param_1 + 0x2a58) < FLOAT_001aa128)))))) ||
     (bVar1 = true, (uVar2 & 0x70000000) != 0)) {
    bVar1 = false;
  }
  if (param_2 == 1) {
    if ((uVar2 & 0x400) != 0) {
      return 0;
    }
  }
  else if (param_2 == 0) {
    if ((uVar2 & 0x400) == 0) {
      return 0;
    }
  }
  else if (1 < param_2 - 4U) {
    return 0;
  }
  if (!bVar1) {
    return 0;
  }
  return 1;
}

/* FUN_0001a0d0 @ 0x1a0d0 (32 bytes) */
int FUN_0001a0d0(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x238);
  if ((int)(param_2 -
           ((uint)pbVar1[3] << 0x18 | (uint)pbVar1[2] << 0x10 | (uint)pbVar1[1] << 8 | (uint)*pbVar1
           )) < 1) {
    return 1;
  }
  return 0;
}

/* FUN_0001a0f0 @ 0x1a0f0 (388 bytes) */
int FUN_0001a0f0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  cVar1 = ((unsigned char *)0x00002b7e)[param_1];
  *puVar4 = ((unsigned char *)0x00001393U);
  puVar4[1] = 0;
  puVar4[2] = 0x5c8;
  puVar4[3] = 0x20000;
  puVar4 = puVar4 + 4;
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)FUN_0002b7f0(param_1,puVar4);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(int *)(*(int *)(param_1 + 0x1e4) + 0x10) =
       (*(int *)(param_1 + 0x1e0) - (int)puVar4 >> 2) +
       (*(int *)(param_1 + 0x1f0) - *(int *)(param_1 + 0x1ec) >> 2) + 0x25;
  puVar2 = PTR_001e88b4;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *puVar4 = param_2;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),1,*(undefined4 *)puVar2,param_1 + 0x1e4,
                      param_1 + 0x1e8,1);
  iVar3 = *(int *)(param_1 + 0x1e4);
  puVar4 = (undefined4 *)(iVar3 + 0x20);
  *(undefined4 **)(param_1 + 0x1e0) = puVar4 + *(int *)(iVar3 + 0x10) + -0x25;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x2838) = 0;
  *(undefined4 *)(param_1 + 0x204) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x2834) = 0;
  *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  if (cVar1 != '\0') {
    *puVar4 = ((unsigned char *)0x000013d6U);
    *(undefined4 *)(iVar3 + 0x24) = 0;
    puVar4 = (undefined4 *)(iVar3 + 0x28);
  }
  *(int *)(param_1 + 0x1d8) = iVar3 + 0x1c;
  *(undefined4 **)(param_1 + 0x1dc) = puVar4;
  *(undefined4 **)(param_1 + 0x2994) = puVar4 + 0x6000;
  FUN_0002c6c0(param_1);
  return;
}

/* FUN_0001a280 @ 0x1a280 (588 bytes) */
int FUN_0001a280(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint local_28;
  uint local_24;
  
  iVar2 = ((int (*)())FUN_0001a010)(param_1,0,param_3,param_4,param_5,param_6,param_7);
  if (iVar2 != 0) {
    ((int (*)())FUN_000230d0)(param_1,0,0,1,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x2000000);
  if ((*(uint *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],0,0,-(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],param_1 + 0x124,*(undefined4 *)(param_1 + 0x108),
                 -(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    cVar1 = *(char *)(param_1 + 0x2a6c);
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    if (*(char *)(param_1 + 0x2a80) != cVar1) {
      *(char *)(param_1 + 0x2a80) = cVar1;
      if (cVar1 == '\x01') {
        local_24 = 0;
        local_28 = 0;
      }
      else if (cVar1 == '\x02') {
        local_24 = 1;
        local_28 = 1;
      }
      else {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
    }
    iVar2 = *(int *)(param_1 + 0x2a70);
    if (*(int *)(param_1 + 0x2a84) == iVar2) {
      uVar3 = *(uint *)(param_1 + 0x2a74);
      if (*(uint *)(param_1 + 0x2a88) == uVar3) {
        return;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2a74);
    }
    *(uint *)(param_1 + 0x2a88) = uVar3;
    *(int *)(param_1 + 0x2a84) = iVar2;
    ((int (*)())FUN_00019db0)(param_1,iVar2,(uint)(uVar3 < 2));
  }
  return;
}

/* FUN_0001a4e0 @ 0x1a4e0 (212 bytes) */
int FUN_0001a4e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  undefined4 extraout_r4;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (((*(uint *)(param_1 + 0x154) & 0x800) != 0) && (*(int *)(param_1 + 0x26a0) != 1)) {
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    }
    uStack_24 = *(uint *)(param_1 + 0x3c);
    uVar1 = uStack_24 & 0xfffff7ff;
    *(uint *)(param_1 + 0x3c) = uVar1;
    if (*(int *)(param_1 + 0x150) == 0) {
      *(uint *)(param_1 + 0x154) = uVar1;
    }
    uStack_20 = *(undefined4 *)(param_1 + 0xfc);
    uStack_1c = *(undefined4 *)(param_1 + 0x100);
    param_3 = &uStack_28;
    param_4 = 4;
    param_5 = 0;
    param_7 = *(undefined4 *)(*(int *)(param_1 + 0xf8) + 8);
    uStack_24 = uStack_24 & 0xffff37c0;
    param_6 = 0;
    uStack_28 = param_7;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0,param_3,4,0,0);
    param_2 = extraout_r4;
  }
  ((int (*)())FUN_0001a280)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _gldFlush @ 0x1a5c0 (28 bytes) */
int _gldFlush(param_1)
  int param_1;
{
  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) {
    return;
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  return;
}

/* _gldFinish @ 0x1a5e0 (136 bytes) */
int _gldFinish(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  do {
    iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),8,0,0,0,0);
  } while (iVar1 == -0x1ffffd2a);
  return;
}

/* FUN_0001a670 @ 0x1a670 (216 bytes) */
int FUN_0001a670(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar2 + 6) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar2 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar2 + 6;
  *puVar2 = ((unsigned char *)0x00001393U);
  puVar2[1] = 0;
  puVar2[2] = 0x5c8;
  puVar2[3] = 0x20000;
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *puVar1 = (int)(puVar2 + 4) - (int)puVar1 >> 2 | *puVar1;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2 + 4;
  puVar2[4] = 0x34000000;
  puVar2[5] = *param_2;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined4 *)(*param_2 * 8 + *(int *)(param_1 + 0x218) + 4) = 1;
  return;
}

/* FUN_0001a750 @ 0x1a750 (636 bytes) */
int FUN_0001a750(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uStack_28;
  uint uStack_24;
  
  iVar2 = ((int (*)())FUN_0001a010)(param_1,1,param_3,param_4,param_5,param_6,param_7);
  if (iVar2 != 0) {
    ((int (*)())FUN_000230d0)(param_1,0,1,0,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x3000000);
  if ((*(uint *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],0,0,-(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],param_1 + 0x124,*(undefined4 *)(param_1 + 0x108),
                 -(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  do {
    iVar2 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),8,0,0,0,0);
  } while (iVar2 == -0x1ffffd2a);
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    cVar1 = *(char *)(param_1 + 0x2a6c);
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    if (*(char *)(param_1 + 0x2a80) != cVar1) {
      *(char *)(param_1 + 0x2a80) = cVar1;
      if (cVar1 == '\x01') {
        uStack_24 = 0;
        uStack_28 = 0;
      }
      else if (cVar1 == '\x02') {
        uStack_24 = 1;
        uStack_28 = 1;
      }
      else {
        uStack_28 = (uint)*(byte *)(param_1 + 0x142);
        uStack_24 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&uStack_28,2,0,0);
    }
    iVar2 = *(int *)(param_1 + 0x2a70);
    if (*(int *)(param_1 + 0x2a84) == iVar2) {
      uVar3 = *(uint *)(param_1 + 0x2a74);
      if (*(uint *)(param_1 + 0x2a88) == uVar3) {
        return;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2a74);
    }
    *(uint *)(param_1 + 0x2a88) = uVar3;
    *(int *)(param_1 + 0x2a84) = iVar2;
    ((int (*)())FUN_00019db0)(param_1,iVar2,(uint)(uVar3 < 2));
  }
  return;
}

/* FUN_0001a9d0 @ 0x1a9d0 (588 bytes) */
int FUN_0001a9d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint local_28;
  uint local_24;
  
  iVar2 = ((int (*)())FUN_0001a010)(param_1,1,param_3,param_4,param_5,param_6,param_7);
  if (iVar2 != 0) {
    ((int (*)())FUN_000230d0)(param_1,0,1,0,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x3000000);
  if ((*(uint *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],0,0,-(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],param_1 + 0x124,*(undefined4 *)(param_1 + 0x108),
                 -(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    cVar1 = *(char *)(param_1 + 0x2a6c);
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    if (*(char *)(param_1 + 0x2a80) != cVar1) {
      *(char *)(param_1 + 0x2a80) = cVar1;
      if (cVar1 == '\x01') {
        local_24 = 0;
        local_28 = 0;
      }
      else if (cVar1 == '\x02') {
        local_24 = 1;
        local_28 = 1;
      }
      else {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
    }
    iVar2 = *(int *)(param_1 + 0x2a70);
    if (*(int *)(param_1 + 0x2a84) == iVar2) {
      uVar3 = *(uint *)(param_1 + 0x2a74);
      if (*(uint *)(param_1 + 0x2a88) == uVar3) {
        return;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2a74);
    }
    *(uint *)(param_1 + 0x2a88) = uVar3;
    *(int *)(param_1 + 0x2a84) = iVar2;
    ((int (*)())FUN_00019db0)(param_1,iVar2,(uint)(uVar3 < 2));
  }
  return;
}

/* FUN_0001ac30 @ 0x1ac30 (464 bytes) */
int FUN_0001ac30(param_1)
  int param_1;
{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    return 0x271e;
  }
  uVar5 = *(uint *)(param_1 + 0x30);
  if ((uVar5 == 0) || ((uVar5 & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
    return 0x2716;
  }
  uVar6 = *(uint *)(param_1 + 8);
  bVar1 = (uVar6 >> 1 & 1) != 0;
  if (bVar1) {
    for (; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1) {
    }
    if (uVar5 != 1) {
      return 0x2716;
    }
  }
  if ((((((*(uint *)(param_1 + 4) & 0xff00) == 0x1900) && (*(short *)(param_1 + 0x20) == 0)) &&
       (((*(uint *)(param_1 + 0xc) & 2) == 0 || (bVar1)))) && (*(ushort *)(param_1 + 0x22) < 3)) &&
     ((((uVar6 & 0x2000) == 0 || (*(int *)(param_1 + 0x24) == 0)) &&
      (uVar2 = *(ushort *)(param_1 + 0x24), uVar2 < 2)))) {
    if (uVar2 != 0) {
      if (((uVar2 == 1) && (sVar3 = *(short *)(param_1 + 0x26), sVar3 != 6)) &&
         ((sVar3 != 4 && (sVar3 != 2)))) {
        return 0x2712;
      }
    }
    else if (*(short *)(param_1 + 0x26) != 0) {
      return 0x2712;
    }
    if (((((uVar6 & 0xffffd064) == 0) &&
         (((uVar6 & 8) == 0 || ((*(uint *)(param_1 + 0xc) & 8) != 0)))) &&
        ((*(uint *)(param_1 + 0x10) & 0xf57f7bff) == 0)) &&
       (((*(uint *)(param_1 + 0x10) & 0xa800000) == 0 || ((uVar2 == 0 && ((uVar6 & 0x400) == 0))))))
    {
      iVar4 = *(int *)(param_1 + 0x1c);
      if (iVar4 != 1) {
        if (iVar4 != 0x80) {
          return 0x2712;
        }
        uVar5 = 0xfffff7ff;
      }
      else {
        uVar5 = 0xffffe3fe;
      }
      if (((*(uint *)(param_1 + 0x18) & uVar5) == 0) &&
         ((((*(uint *)(param_1 + 0x18) != 1 || (iVar4 != 1)) || ((uVar6 & 0x800) == 0)) &&
          ((uVar5 = *(uint *)(param_1 + 0x14), (uVar5 & 0xff7f7fff) == 0 &&
           ((uVar5 & uVar5 - 1) == 0)))))) {
        return 0;
      }
    }
  }
  return 0x2712;
}

/* FUN_0001ae20 @ 0x1ae20 (768 bytes) */
int FUN_0001ae20(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0x80;
    if (param_2 == 0) {
LAB_0001aee0:
      *(undefined4 *)(param_1 + 0x18) = 0x800;
    }
    else {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0x800;
    }
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x1c) = 1;
    *(uint *)(param_1 + 0x18) = uVar3 & 0x1c01;
    if ((param_2 == 0) || ((uVar3 & 0x1c01) != 0)) {
      if (param_3 == 0) {
        if ((uVar3 & 1) != 0) goto LAB_0001ae88;
        if ((uVar3 & 0x400) == 0) {
          if ((uVar3 & 0x800) != 0) goto LAB_0001aee0;
          goto LAB_0001aeb0;
        }
        *(undefined4 *)(param_1 + 0x18) = 0x400;
      }
      else if ((uVar3 & 1) == 0) {
LAB_0001aeb0:
        *(undefined4 *)(param_1 + 0x18) = 0x1000;
      }
      else {
LAB_0001ae88:
        *(undefined4 *)(param_1 + 0x18) = 1;
      }
    }
  }
  uVar3 = *(uint *)(param_1 + 0x14);
  if ((int)uVar3 < 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else if ((uVar3 & 0x8000) == 0) {
    if ((uVar3 & 0x800000) == 0) {
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    }
    else {
      *(undefined4 *)(param_1 + 0x14) = 0x800000;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x8000;
  }
  if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
    uVar3 = *(uint *)(param_1 + 8) & 0xfffffff7;
    *(uint *)(param_1 + 8) = uVar3;
  }
  else {
    uVar3 = *(uint *)(param_1 + 8);
  }
  if ((uVar3 & 0x2000) != 0) {
    *(undefined2 *)(param_1 + 0x24) = 0;
    *(undefined2 *)(param_1 + 0x26) = 0;
  }
  uVar1 = 0;
  if (*(short *)(param_1 + 0x24) != 0) {
    if (*(short *)(param_1 + 0x24) != 1) {
      *(undefined2 *)(param_1 + 0x24) = 1;
    }
    if (4 < *(short *)(param_1 + 0x26)) {
      *(undefined2 *)(param_1 + 0x26) = 6;
      goto LAB_0001aff4;
    }
    if (2 < *(short *)(param_1 + 0x26)) {
      *(undefined2 *)(param_1 + 0x26) = 4;
      goto LAB_0001aff4;
    }
    uVar1 = 2;
  }
  *(undefined2 *)(param_1 + 0x26) = uVar1;
LAB_0001aff4:
  uVar3 = *(uint *)(param_1 + 0x10);
  iVar4 = 2;
  _memcpy(param_1 + 0x34,param_1,0x34);
  *(undefined4 *)(param_1 + 0x10) = 0x400;
  *(undefined4 *)(param_1 + 0x44) = 0x8000;
  if ((uVar3 & 0x800000) != 0) {
    iVar4 = 3;
    _memcpy(param_1 + 0x68,param_1,0x34);
    *(undefined2 *)(param_1 + 0x8e) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0x800000;
    *(undefined2 *)(param_1 + 0x8c) = 0;
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & 0xfffffbff;
  }
  if ((uVar3 & 0x2000000) != 0) {
    iVar5 = iVar4 * 0x34;
    iVar4 = iVar4 + 1;
    iVar5 = param_1 + iVar5;
    _memcpy(iVar5,param_1,0x34);
    *(undefined2 *)(iVar5 + 0x26) = 0;
    *(undefined4 *)(iVar5 + 0x10) = 0x2000000;
    *(undefined2 *)(iVar5 + 0x24) = 0;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xfffffbff;
  }
  if ((uVar3 & 0x8000000) != 0) {
    iVar5 = iVar4 * 0x34;
    iVar4 = iVar4 + 1;
    iVar5 = param_1 + iVar5;
    _memcpy(iVar5,param_1,0x34);
    *(undefined2 *)(iVar5 + 0x26) = 0;
    *(undefined4 *)(iVar5 + 0x10) = 0x8000000;
    *(undefined2 *)(iVar5 + 0x24) = 0;
    *(uint *)(iVar5 + 8) = *(uint *)(iVar5 + 8) & 0xfffffbff;
  }
  if (iVar4 != 0) {
    iVar5 = 0;
    do {
      iVar2 = ((int (*)())FUN_0001ac30)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = iVar5 + 1;
      param_1 = param_1 + 0x34;
    } while (iVar4 != iVar5);
  }
  return iVar4;
}

/* FUN_0001b150 @ 0x1b150 (88 bytes) */
int FUN_0001b150(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined2 *)(param_1 + 0x26) = 1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0xa800000;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x5000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
  *(undefined2 *)(param_1 + 0x24) = 2;
  *(undefined4 *)(param_1 + 0x2c) = 3;
  *(undefined2 *)(param_1 + 0x28) = 6;
  return;
}

/* _gldFreeVertexBuffer @ 0x1b1b0 (20 bytes) */
int _gldFreeVertexBuffer(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  *(undefined4 *)(param_2 + -0x6c) = 1;
  return;
}

/* _gldCompleteVertexBuffer @ 0x1b1d0 (4 bytes) */
int _gldCompleteVertexBuffer()
{
  return;
}

/* _gldAllocVertexBuffer @ 0x1b1e0 (676 bytes) */
int _gldAllocVertexBuffer(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  iVar4 = *param_3;
  local_48 = 8;
  *param_3 = 0;
  if (0x800 < iVar4) {
    return 0;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    return 0;
  }
  switch(param_2 & 0x7fff) {
  default:
    goto LAB_0001b494;
  case 1:
    uVar7 = 9;
    break;
  case 2:
    uVar7 = 10;
    break;
  case 3:
    uVar7 = 0xb;
    break;
  case 4:
    uVar7 = 0xc;
    break;
  case 5:
    uVar7 = 0xd;
    break;
  case 6:
    uVar7 = 0xe;
  }
  if (*(int *)(param_1 + 0x210) == 0) {
    local_3c = 2;
    local_38 = 0x16000;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,&local_3c,0x14,&local_44,&local_48);
    if (iVar4 != 0) {
      return 0;
    }
    piVar1 = (int *)(local_40 + 0x10);
    *(int *)(local_44 + 0x1c) = local_40;
    do {
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar1 + 0x10000,0,piVar1);
        *piVar1 = iVar4;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_40 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x214) = 1;
    *(int *)(local_44 + 0x10) = local_44;
    goto LAB_0001b468;
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x210) + 0x10);
  iVar4 = *(int *)(iVar8 + 0x1c);
  if (*(int *)(iVar8 + 0x14) == 0) {
    if (0x7f < *(uint *)(param_1 + 0x214)) {
      return 0;
    }
LAB_0001b3e4:
    local_3c = 2;
    local_38 = 0x16000;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,&local_3c,0x14,&local_44,&local_48);
    if (iVar4 != 0) {
LAB_0001b494:
      return 0;
    }
    piVar1 = (int *)(local_40 + 0x10);
    *(int *)(local_44 + 0x1c) = local_40;
    do {
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar1 + 0x10000,0,piVar1);
        *piVar1 = iVar4;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_40 + 0x14) = 1;
    *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 1;
    *(undefined4 *)(local_44 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x210) + 0x10);
    *(int *)(*(int *)(param_1 + 0x210) + 0x10) = local_44;
  }
  else {
    if (*(int *)(iVar8 + 0x18) == *(int *)(param_1 + 0x23c)) {
      if (*(uint *)(param_1 + 0x214) < 0x80) goto LAB_0001b3e4;
      ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
      pbVar6 = *(byte **)(param_1 + 0x238);
      iVar2 = 0xf4241;
      do {
        if ((int)(*(int *)(iVar4 + 8) -
                 ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
                 (uint)*pbVar6)) < 1) break;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      uVar5 = *(uint *)(iVar4 + 8);
      pbVar6 = *(byte **)(param_1 + 0x238);
      uVar3 = (uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
              (uint)*pbVar6;
      in_cr0 = (uVar5 == uVar3) << 1;
      if (0 < (int)(uVar5 - uVar3)) {
        if (*(uint *)(param_1 + 0x214) < 0x80) goto LAB_0001b3e4;
        iVar4 = 0xf4241;
        do {
          if ((int)(uVar5 - ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 |
                             (uint)pbVar6[1] << 8 | (uint)*pbVar6)) < 1) break;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    *(undefined4 *)(iVar8 + 0x14) = 0;
    local_44 = iVar8;
  }
LAB_0001b468:
  iVar4 = *(int *)(param_1 + 0x23c);
  *(int *)(param_1 + 0x210) = local_44;
  *(undefined4 *)(local_44 + 0xc) = uVar7;
  *(int *)(local_44 + 0x18) = iVar4 + -1;
  *param_3 = 0x800;
  return local_44 + 0x80;
}

/* FUN_0001b4b0 @ 0x1b4b0 (44 bytes) */
int FUN_0001b4b0(param_1)
  int param_1;
{
  if ((*(uint *)(param_1 + 0x154) & 0x70000000) == 0) {
    ((unsigned char *)0x00002b7c)[param_1] = 1;
  }
  else {
    ((unsigned char *)0x00002b7c)[param_1] = 0;
  }
  ((unsigned char *)0x00002b7d)[param_1] = 1;
  return;
}

/* FUN_0001b4f0 @ 0x1b4f0 (4 bytes) */
int FUN_0001b4f0()
{
  return;
}

/* FUN_0001b500 @ 0x1b500 (8 bytes) */
int FUN_0001b500()
{
  return 1;
}

/* FUN_0001b510 @ 0x1b510 (1304 bytes) */
int FUN_0001b510(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  *(undefined4 *)(param_2[1] + 0x18) = 0;
  iVar17 = 6;
  piVar14 = param_2;
  do {
    piVar14[0x13] = 0;
    piVar14 = piVar14 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  *(undefined1 *)((int)param_2 + 0x11) = 0;
  *(undefined1 *)((int)param_2 + 0x12) = 0;
  param_2[0x12] = 0;
  param_2[5] = 0;
  *(undefined1 *)(param_2 + 4) = 1;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  piVar14 = (int *)param_2[1];
  if ((piVar14[4] != 0) && (piVar14[5] != 0)) goto LAB_0001b730;
  if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) < (int)(uint)*(ushort *)(*param_2 + 0x9a)) ||
     (*(int *)(*(int *)(param_1 + 0x14) + 0x10) < (int)(uint)*(ushort *)(*param_2 + 0x9c)))
  goto LAB_0001b730;
  iVar17 = 0;
  iVar16 = 0;
  do {
    iVar10 = piVar14[iVar16];
    if (iVar10 != 0) {
      if (iVar16 < 4) {
        iVar17 = iVar10;
      }
      iVar10 = FUN_00032100(param_1,iVar10,param_3,param_4,param_5,param_6);
      if (iVar10 == 0) {
        piVar14 = (int *)param_2[1];
        goto LAB_0001b730;
      }
      piVar14 = (int *)param_2[1];
    }
    puVar4 = PTR_DAT_001e88c8;
    bVar1 = iVar16 != 5;
    iVar16 = iVar16 + 1;
  } while (bVar1);
  if (iVar17 == 0) {
    param_2[9] = 0;
    *(undefined1 *)((int)param_2 + 0x13) = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
  }
  else {
    bVar2 = *(byte *)(iVar17 + 0x38);
    param_2[6] = *(ushort *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) & 0x3f;
    param_2[7] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 10 & 0x3f;
    param_2[8] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 4 & 0x3f;
    uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10);
    if ((((uVar5 & 0x3f0000) == 0) || ((uVar5 & 0xfc00) == 0)) || ((uVar5 & 0x3f0) == 0)) {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
LAB_0001b6ac:
      param_2[9] = uVar5 >> 0x1a;
    }
    else {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
      if ((uVar5 >> 0x1a == 0) || (*(short *)(*(int *)(iVar17 + 0x30) + 2) != 0x1907))
      goto LAB_0001b6ac;
      param_2[9] = 0;
    }
    *(byte *)((int)param_2 + 0x13) =
         (byte)(*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x20) >> 0x17) & 1;
    if ((*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x18) & 0x10000) == 0) goto LAB_0001b730;
  }
  iVar17 = piVar14[4];
  if (iVar17 == 0) {
    param_2[10] = 0;
  }
  else {
    param_2[10] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar17 + 0x38) * 0x24 + 0x14) >> 8 &
                  0x3f;
    if ((*(char *)(iVar17 + 0x38) != '\x10') && (*(char *)(iVar17 + 0x38) != ')'))
    goto LAB_0001b730;
  }
  iVar16 = piVar14[5];
  if (iVar16 == 0) {
    param_2[0xb] = 0;
  }
  else {
    param_2[0xb] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar16 + 0x38) * 0x24 + 0x14) >> 4 &
                   0xf;
    if ((*(char *)(iVar16 + 0x38) != ')') || ((iVar17 != 0 && (iVar17 != iVar16)))) {
LAB_0001b730:
      piVar14[7] = 1;
      return 0;
    }
  }
  iVar17 = 6;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    iVar16 = *piVar7;
    piVar7 = piVar7 + 1;
    if (iVar16 != 0) {
      piVar12[0x13] = *(int *)(iVar16 + 0x34);
    }
    puVar4 = PTR_DAT_001e88c8;
    piVar12 = piVar12 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iVar17 = 4;
  piVar7 = piVar14;
  do {
    if (*piVar7 != 0) {
      switch(*(undefined1 *)(*piVar7 + 0x38)) {
      case 5:
        uVar15 = 0x4000;
        uVar5 = 5;
        break;
      case 6:
      case 7:
        uVar15 = 0x4000;
        uVar5 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0x23:
      case 0x24:
        uVar15 = 0x4000;
        uVar5 = 4;
        break;
      default:
        uVar15 = 0x4000;
        uVar5 = 0;
        break;
      case 0x11:
      case 0x12:
        uVar15 = 0x4000;
        uVar5 = 0xd;
        break;
      case 0x17:
      case 0x18:
        uVar15 = 0x4000;
        uVar5 = 0xb;
        break;
      case 0x1d:
      case 0x1e:
        uVar15 = 0x4000;
        uVar5 = 0xc;
      }
      goto LAB_0001b8f4;
    }
    piVar7 = piVar7 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  uVar15 = 0;
  uVar5 = 0;
LAB_0001b8f4:
  uVar8 = uVar5;
  if (piVar14[4] != 0) {
    cVar3 = *(char *)(piVar14[4] + 0x38);
    uVar15 = uVar15 | 0x100;
    uVar8 = uVar5 | 0x40;
    if (cVar3 == '\x10') {
      uVar8 = uVar5 | 0x10040;
    }
    else if (cVar3 == ')') {
      uVar8 = uVar5 | 0x20040;
    }
  }
  uVar5 = uVar8;
  if (piVar14[5] != 0) {
    uVar15 = uVar15 | 0x400;
    uVar5 = uVar8 | 0x80;
    if (*(char *)(piVar14[5] + 0x38) == ')') {
      uVar5 = uVar8 | 0x30080;
    }
  }
  iVar16 = 0;
  iVar17 = 0;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    piVar13 = (int *)*piVar7;
    piVar7 = piVar7 + 1;
    if (piVar13 == (int *)0x0) {
      piVar12[0x25] = 0;
      piVar12[0x2b] = -1;
      piVar12[0x19] = 0;
      piVar12[0x1f] = 0;
    }
    else {
      iVar11 = *param_2;
      iVar9 = iVar17 + iVar11;
      iVar10 = *(int *)(iVar9 + 8);
      if (*(char *)(piVar13[0xd] + 0x16) == '\x06') {
        uVar8 = (uint)*(ushort *)((int)piVar13 + 0x3e) <<
                (*(uint *)(puVar4 + (uint)*(byte *)(piVar13 + 0xe) * 0x24 + 0x14) & 7);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = 0;
      }
      else {
        iVar6 = *(int *)(iVar9 + 4) * 0xd + iVar10;
        uVar8 = *(uint *)(*piVar13 + 0xc);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = *(int *)(iVar9 + 0xc) * uVar8 * (uint)*(ushort *)(iVar11 + 0x9c) +
                 *(int *)(*piVar13 + iVar6 * 0x20 + 0x48);
      }
      iVar9 = *(int *)piVar13[0xd];
      piVar12[0x19] = iVar10;
      piVar12[0x1f] = uVar8;
      piVar12[0x2b] = iVar9;
      piVar12[0x25] = (uint)*(ushort *)(iVar11 + 0x9a);
    }
    bVar1 = iVar16 != 5;
    iVar17 = iVar17 + 0x18;
    piVar12 = piVar12 + 1;
    iVar16 = iVar16 + 1;
  } while (bVar1);
  param_2[3] = uVar5;
  param_2[2] = uVar15;
  piVar14[7] = 0;
  *(undefined1 *)((int)param_2 + 0xc6) = 0;
  *(undefined1 *)((int)param_2 + 0xc5) = 1;
  *(undefined1 *)(param_2 + 0x31) = 0;
  return 1;
}

/* FUN_0001bac0 @ 0x1bac0 (904 bytes) */
int FUN_0001bac0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  int iVar9;
  
  ((unsigned char *)0x00002b7c)[param_1] = 0;
  puVar4 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x83);
  iVar5 = 0;
  *(uint **)(param_1 + 0x298c) = puVar4;
  puVar2 = (undefined4 *)((uint)(puVar4 + 0xb) & 0xffffffe0);
  *puVar4 = (((int)puVar2 - (int)puVar4) + -8) * 0x4000 | 0xc0001000;
  puVar2[-1] = (int)puVar2 - (int)puVar4;
  iVar9 = 4;
  puVar4 = *(uint **)(param_1 + 0x1d8);
  *puVar4 = (int)puVar2 - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2;
  *puVar2 = 0x41000000;
  puVar2[1] = 4;
  puVar2[2] = (uint)*(ushort *)(*param_2 + 0x9a);
  puVar2[3] = (uint)*(ushort *)(*param_2 + 0x9c);
  puVar2[4] = *(undefined4 *)(param_1 + 0x1d20);
  puVar2[5] = *(undefined4 *)(param_1 + 0x1cf0);
  piVar3 = puVar2 + 6;
  do {
    piVar6 = piVar3;
    uVar7 = (uint)*(ushort *)(iVar5 * 2 + *param_2 + 0x90);
    if (uVar7 == 0) {
      piVar6[5] = 0;
      *piVar6 = -1;
      piVar6[1] = 0;
      piVar6[2] = 0;
      piVar6[3] = 0;
      piVar6[4] = 0;
    }
    else {
      iVar1 = (uVar7 - 0x8ce0) * 4;
      *piVar6 = param_2[uVar7 - 0x8cb5];
      piVar6[1] = param_2[uVar7 - 0x8cc7];
      piVar6[2] = param_2[uVar7 - 0x8cc1];
      piVar6[3] = param_2[uVar7 - 0x8cbb];
      iVar8 = (uVar7 - 0x8ce0) * 0x18 + *param_2;
      piVar6[4] = *(int *)(iVar8 + 4) << 0x10 | *(uint *)(iVar8 + 8);
      piVar6[5] = (uint)*(byte *)(*(int *)(iVar1 + param_2[1]) + 0x38);
      *(undefined1 *)(*(int *)(iVar1 + param_2[1]) + 200) = 0;
      piVar3 = (int *)(*(int *)(*(int *)(iVar1 + param_2[1]) + 0x34) + 0x10);
      do {
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    piVar3 = piVar6 + 6;
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(int *)(param_2[1] + 0x10) == 0) {
    piVar6[0xb] = 0;
    piVar6[7] = 0;
    piVar6[8] = 0;
    piVar6[9] = 0;
    *piVar3 = -1;
    piVar6[10] = 0;
  }
  else {
    *piVar3 = param_2[0x2f];
    piVar6[7] = param_2[0x1d];
    piVar6[8] = param_2[0x23];
    piVar6[9] = param_2[0x29];
    piVar6[10] = *(int *)(*param_2 + 100) << 0x10 | *(uint *)(*param_2 + 0x68);
    piVar6[0xb] = (uint)*(byte *)(*(int *)(param_2[1] + 0x10) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x10) + 200) = 0;
    piVar3 = (int *)(*(int *)(*(int *)(param_2[1] + 0x10) + 0x34) + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  if (*(int *)(param_2[1] + 0x14) == 0) {
    piVar6[0x11] = 0;
    piVar6[0xd] = 0;
    piVar6[0xe] = 0;
    piVar6[0xf] = 0;
    piVar6[0xc] = -1;
    piVar6[0x10] = 0;
  }
  else {
    piVar6[0xc] = param_2[0x30];
    piVar6[0xd] = param_2[0x1e];
    piVar6[0xe] = param_2[0x24];
    piVar6[0xf] = param_2[0x2a];
    piVar6[0x10] = *(int *)(*param_2 + 0x7c) << 0x10 | *(uint *)(*param_2 + 0x80);
    piVar6[0x11] = (uint)*(byte *)(*(int *)(param_2[1] + 0x14) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x14) + 200) = 0;
    piVar3 = (int *)(*(int *)(*(int *)(param_2[1] + 0x14) + 0x34) + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  *(int **)(param_1 + 0x298c) = piVar6 + 0x4b;
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240,piVar6 + 0x4b);
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  ((unsigned char *)0x00002b7d)[param_1] = 1;
  return;
}

/* FUN_0001be50 @ 0x1be50 (868 bytes) */
int FUN_0001be50(param_1, param_2)
  int param_1;
  byte *param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte local_78 [4];
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  int local_70 [4];
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  
  iVar10 = 0x10;
  uVar8 = 0xff;
  uVar9 = 0;
  iVar3 = param_1;
  do {
    uVar2 = (uint)*(byte *)(iVar3 + 3);
    iVar3 = iVar3 + 4;
    if (uVar2 < uVar8) {
      uVar8 = uVar2;
    }
    if (uVar9 < uVar2) {
      uVar9 = uVar2;
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (uVar8 == 0) {
    if (uVar9 != 0xff) {
LAB_0001bfec:
      local_78[0] = (byte)uVar8;
      local_78[1] = (byte)uVar9;
      local_78[3] = (char)((uVar8 * 3 + uVar9 * 2) / 5);
      local_74 = (char)((uVar8 * 2 + uVar9 * 3) / 5);
      local_78[2] = (char)((uVar9 + uVar8 * 4) / 5);
      local_73 = (char)((uVar8 + uVar9 * 4) / 5);
      local_72 = 0;
      local_71 = 0xff;
      goto LAB_0001bf84;
    }
  }
  else if (uVar9 == 0xff) goto LAB_0001bfec;
  local_78[0] = (byte)uVar9;
  local_78[1] = (byte)uVar8;
  local_78[2] = (char)((uVar8 + uVar9 * 6) / 7);
  local_78[3] = (char)((uVar9 * 5 + uVar8 * 2) / 7);
  local_74 = (char)((uVar9 * 4 + uVar8 * 3) / 7);
  local_73 = (char)((uVar9 * 3 + uVar8 * 4) / 7);
  local_72 = (char)((uVar9 * 2 + uVar8 * 5) / 7);
  local_71 = (char)((uVar9 + uVar8 * 6) / 7);
LAB_0001bf84:
  iVar3 = 0;
  do {
    iVar10 = 0;
    piVar6 = local_70 + iVar3 * 4;
    pbVar7 = (byte *)(param_1 + iVar3 * 0x10 + 3);
    do {
      uVar8 = 0xff;
      iVar5 = 0;
      iVar4 = 0;
      iVar11 = 8;
      do {
        if ((uint)local_78[iVar4] - (uint)*pbVar7 < uVar8) {
          iVar5 = iVar4;
          uVar8 = (uint)local_78[iVar4] - (uint)*pbVar7;
        }
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      bVar1 = iVar10 != 3;
      *piVar6 = iVar5;
      pbVar7 = pbVar7 + 4;
      piVar6 = piVar6 + 1;
      iVar10 = iVar10 + 1;
    } while (bVar1);
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  param_2[1] = local_78[1];
  param_2[2] = (byte)(local_70[2] << 6) | (byte)(local_70[1] << 3) | (byte)local_70[0];
  param_2[3] = (byte)(local_5c << 7) | (byte)(local_60 << 4) | (byte)(local_70[3] << 1) |
               (byte)((uint)local_70[2] >> 2) & 1;
  param_2[5] = (byte)(local_48 << 6) | (byte)(local_4c << 3) | (byte)local_50;
  param_2[4] = (byte)(local_54 << 5) | (byte)(local_58 << 2) | (byte)(local_5c >> 1) & 3;
  param_2[6] = (byte)(local_3c << 7) | (byte)(local_40 << 4) | (byte)(local_44 << 1) |
               (byte)(local_48 >> 2) & 1;
  param_2[7] = (byte)(local_34 << 5) | (byte)(local_38 << 2) | (byte)(local_3c >> 1) & 3;
  *param_2 = local_78[0];
  return param_2 + 8;
}

/* FUN_0001c1c0 @ 0x1c1c0 (416 bytes) */
int FUN_0001c1c0(param_1, param_2, param_3, param_4)
  uint param_1;
  uint param_2;
  uint param_3;
  undefined1 *param_4;
{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_28 [32];
  
  if (param_2 < param_1) {
    iVar4 = (param_1 & 0x1f) * 8;
    uVar6 = param_1 >> 8 & 0xf8;
    uVar5 = param_1 >> 3 & 0xfc;
    iVar9 = (param_2 & 0x1f) * 8;
    uVar2 = param_2 >> 8 & 0xf8;
    auStack_28[2] = (char)iVar4;
    uVar3 = param_2 >> 3 & 0xfc;
    auStack_28[0] = (char)uVar6;
    auStack_28[1] = (char)uVar5;
    auStack_28[3] = (char)uVar2;
    auStack_28[5] = (char)iVar9;
    auStack_28[4] = (char)uVar3;
    if (param_3 == 2) {
      iVar8 = uVar6 * 2 + uVar2;
      iVar7 = uVar5 * 2 + uVar3;
      iVar4 = (param_1 & 0x1f) * 0x10 + iVar9;
    }
    else {
      if (param_3 < 2) goto LAB_0001c300;
      if (param_3 != 3) {
        return;
      }
      iVar8 = uVar6 + uVar2 * 2;
      iVar7 = uVar5 + uVar3 * 2;
      iVar4 = iVar4 + (param_2 & 0x1f) * 0x10;
    }
    param_4[3] = 0xff;
    param_4[2] = (char)((ulonglong)((longlong)iVar4 * 0x55555556) >> 0x20);
    *param_4 = (char)((ulonglong)((longlong)iVar8 * 0x55555556) >> 0x20);
    param_4[1] = (char)((ulonglong)((longlong)iVar7 * 0x55555556) >> 0x20);
  }
  else {
    if (param_3 == 3) {
      param_4[3] = 0;
      *param_4 = 0;
      param_4[1] = 0;
      param_4[2] = 0;
      return;
    }
    iVar4 = (param_1 & 0x1f) * 8;
    uVar2 = param_1 >> 8 & 0xf8;
    uVar6 = param_1 >> 3 & 0xfc;
    iVar9 = (param_2 & 0x1f) * 8;
    uVar3 = param_2 >> 8 & 0xf8;
    auStack_28[2] = (char)iVar4;
    uVar5 = param_2 >> 3 & 0xfc;
    auStack_28[0] = (char)uVar2;
    auStack_28[1] = (char)uVar6;
    auStack_28[3] = (char)uVar3;
    auStack_28[5] = (char)iVar9;
    auStack_28[4] = (char)uVar5;
    if (1 < param_3) {
      if (param_3 != 2) {
        return;
      }
      param_4[3] = 0xff;
      *param_4 = (char)((int)(uVar2 + uVar3) >> 1);
      param_4[1] = (char)((int)(uVar6 + uVar5) >> 1);
      param_4[2] = (char)(iVar4 + iVar9 >> 1);
      return;
    }
LAB_0001c300:
    iVar4 = param_3 * 3;
    *param_4 = auStack_28[iVar4];
    param_4[1] = auStack_28[iVar4 + 1];
    uVar1 = auStack_28[iVar4 + 2];
    param_4[3] = 0xff;
    param_4[2] = uVar1;
  }
  return;
}

/* FUN_0001c380 @ 0x1c380 (3664 bytes) */
int FUN_0001c380(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined1 *param_5;
  byte *param_6;
{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  byte bVar24;
  byte *pbVar23;
  int iVar25;
  uint uVar26;
  byte bVar27;
  undefined1 *puVar28;
  uint *puVar29;
  byte bVar30;
  byte bVar31;
  int iVar32;
  byte *pbVar33;
  uint uVar34;
  ushort *puVar35;
  byte bVar36;
  int iVar37;
  int *piVar38;
  byte *pbVar39;
  uint uVar40;
  byte *pbVar41;
  int iVar42;
  byte *pbVar43;
  byte bVar45;
  uint uVar44;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  byte *pbVar51;
  byte in_xer_so;
  int iVar52;
  int iStack00000024;
  byte local_508 [4];
  byte local_504;
  byte local_503;
  byte local_502;
  byte local_501;
  byte local_500;
  byte local_4ff;
  byte local_4fe;
  byte local_4fd;
  byte local_4fc;
  byte local_4fb;
  byte local_4fa;
  byte local_4f9;
  byte local_4f8;
  byte local_4f7;
  undefined1 local_4f6;
  undefined1 local_4f5;
  undefined1 local_4f4;
  undefined1 local_4f3;
  undefined1 local_4f2;
  undefined1 local_4f1;
  int local_4f0 [4];
  byte local_4e0 [16];
  ushort local_4d0 [12];
  byte local_4b8 [7];
  byte local_4b1;
  byte local_4ad;
  byte local_4a9;
  byte local_4a5;
  byte local_4a1;
  byte local_49d;
  byte local_499;
  byte local_495;
  byte local_491;
  byte local_48d;
  byte local_489;
  byte local_485;
  byte local_481;
  byte local_47d;
  byte local_479;
  uint auStack_478 [256];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  byte *local_68;
  uint *local_64;
  int local_60;
  undefined1 *local_5c;
  uint *local_58;
  ushort *local_54;
  
  if (param_3 == 0x80e0) {
    iVar46 = 2;
    iVar47 = 3;
  }
  else if (param_3 == 0x80e1) {
    iVar46 = 2;
    iVar47 = 4;
  }
  else if (param_3 == 0x1907) {
    iVar46 = 0;
    iVar47 = 3;
  }
  else {
    iVar46 = 0;
    iVar47 = 4;
  }
  if ((param_1 + 3U < 7) || (param_2 + 3U < 7)) {
    iVar48 = param_1;
    if (param_1 < 4) {
      iVar48 = 4;
    }
    local_70 = param_2;
    if (param_2 < 4) {
      local_70 = 4;
    }
    else if (param_2 < 1) {
      return;
    }
    bVar3 = 0 < iVar48;
    iVar50 = 0;
    iVar49 = 0;
    do {
      if (bVar3) {
        iVar25 = 0;
        puVar28 = &DAT_001f65e7 + iVar49 * 4;
        iVar52 = iVar48;
        do {
          iVar42 = iVar47 * (iVar25 + iVar49);
          iVar32 = param_1 * (iVar50 - (iVar50 / param_2) * param_2) +
                   (iVar25 - (iVar25 / param_1) * param_1);
          iVar16 = iVar47 * iVar32;
          (DAT_001f65e4)[iVar42] = param_5[iVar16];
          (DAT_001f65e5)[iVar42] = param_5[iVar16 + 1];
          (DAT_001f65e6)[iVar42] = param_5[iVar16 + 2];
          if (iVar47 == 4) {
            *puVar28 = param_5[iVar32 * 4 + 3];
          }
          iVar25 = iVar25 + 1;
          puVar28 = puVar28 + 4;
          iVar52 = iVar52 + -1;
        } while (iVar52 != 0);
      }
      iVar50 = iVar50 + 1;
      iVar49 = iVar49 + iVar48;
    } while (local_70 != iVar50);
    param_5 = DAT_001f65e4;
    param_1 = iVar48;
  }
  else {
    if (param_2 < 1) {
      return;
    }
    local_70 = param_2;
    bVar3 = 0 < param_1;
  }
  bVar4 = iVar47 != 4;
  local_68 = &local_500;
  local_5c = param_5 + iVar46;
  local_58 = auStack_478;
  local_54 = local_4d0;
  local_60 = (uint)(byte)((param_4 < 0xc) << 3 | (0xc < param_4) << 2 | (param_4 == 0xc) << 1 |
                         in_xer_so & 1) << 0x1c;
  local_78 = 0;
  iStack00000024 = param_4;
  do {
    param_6 = (byte *)((uint)(param_6 + 0x1f) & 0xffffffe0);
    if (bVar3) {
      local_74 = 0;
      local_64 = auStack_478;
      local_6c = 0x55555556;
      do {
        if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
          if (bVar4) {
LAB_0001c6fc:
            iVar48 = 0;
            do {
              iVar50 = 0;
              iVar52 = 4;
              pbVar33 = local_4b8 + iVar48 * 0x10;
              iVar49 = local_74 + param_1 * (iVar48 + local_78);
              do {
                iVar25 = iVar50 + iVar49;
                iVar50 = iVar50 + 1;
                iVar25 = iVar47 * iVar25;
                *pbVar33 = local_5c[iVar25];
                pbVar33[1] = param_5[iVar25 + 1];
                pbVar33[2] = param_5[(iVar25 - iVar46) + 2];
                pbVar33[3] = 0xff;
                pbVar33 = pbVar33 + 4;
                iVar52 = iVar52 + -1;
              } while (iVar52 != 0);
              bVar6 = iVar48 != 3;
              iVar48 = iVar48 + 1;
            } while (bVar6);
            goto LAB_0001c78c;
          }
          bVar6 = false;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              *pbVar43 = *pbVar33;
              pbVar43[1] = puVar28[1];
              pbVar43[2] = *pbVar39;
              bVar7 = puVar28[3];
              pbVar43[3] = bVar7;
              if (bVar7 < 0x7f) {
                bVar6 = true;
              }
              pbVar33 = pbVar33 + 4;
              pbVar43 = pbVar43 + 4;
              puVar28 = puVar28 + 4;
              pbVar39 = pbVar39 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar5 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar5);
        }
        else {
          if (bVar4) goto LAB_0001c6fc;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              bVar7 = *pbVar33;
              pbVar33 = pbVar33 + 4;
              *pbVar43 = bVar7;
              pbVar43[1] = puVar28[1];
              bVar7 = *pbVar39;
              pbVar39 = pbVar39 + 4;
              pbVar43[2] = bVar7;
              pbVar51 = puVar28 + 3;
              puVar28 = puVar28 + 4;
              pbVar43[3] = *pbVar51;
              pbVar43 = pbVar43 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar6 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar6);
LAB_0001c78c:
          bVar6 = false;
        }
        iVar48 = 0;
        while (iVar49 = iVar48 + 1, iVar48 != 0xf) {
          iVar50 = iVar48 * 4;
          puVar29 = local_58 + iVar48 * 0x10 + iVar49;
          iVar52 = 0x10 - iVar49;
          bVar7 = local_4b8[iVar50 + 2];
          bVar22 = local_4b8[iVar50];
          bVar24 = local_4b8[iVar50 + 1];
          iVar50 = iVar49;
          if (0x10 < iVar48 + 2) {
            iVar52 = 1;
          }
          do {
            iVar48 = iVar50 * 4;
            iVar50 = iVar50 + 1;
            uVar8 = (ushort)((int)((uint)local_4b8[iVar48] - (uint)bVar22) >> 0x1f);
            uVar9 = (ushort)((int)((uint)local_4b8[iVar48 + 1] - (uint)bVar24) >> 0x1f);
            uVar10 = (ushort)((int)((uint)local_4b8[iVar48 + 2] - (uint)bVar7) >> 0x1f);
            *puVar29 = (int)(short)((uVar8 ^ (ushort)((uint)local_4b8[iVar48] - (uint)bVar22)) -
                                   uVar8) +
                       (int)(short)((uVar9 ^ (ushort)((uint)local_4b8[iVar48 + 1] - (uint)bVar24)) -
                                   uVar9) +
                       (int)(short)((uVar10 ^ (ushort)((uint)local_4b8[iVar48 + 2] - (uint)bVar7)) -
                                   uVar10);
            puVar29 = puVar29 + 1;
            iVar52 = iVar52 + -1;
            iVar48 = iVar49;
          } while (iVar52 != 0);
        }
        bVar5 = !bVar6;
        uVar26 = 0;
        do {
          iVar48 = 0;
          iVar49 = 0x10;
          do {
            local_4e0[iVar48] = (byte)iVar48;
            iVar48 = iVar48 + 1;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar48 = 0x10;
          uVar34 = 0;
          do {
            bVar7 = local_4e0[uVar34];
            uVar40 = uVar34 + 1;
            if ((bVar7 == uVar34) && ((int)uVar40 < 0x10)) {
              iVar49 = 0x10 - uVar40;
              pbVar33 = local_4e0 + uVar34 + 1;
              puVar29 = local_64 + uVar34 * 0x10 + uVar40;
              uVar34 = uVar40;
              do {
                if (*puVar29 < uVar26) {
                  if (uVar34 == *pbVar33) {
                    iVar48 = iVar48 + -1;
                    *pbVar33 = bVar7;
                  }
                  else if (*puVar29 < auStack_478[(uint)*pbVar33 * 0x10 + uVar34]) {
                    *pbVar33 = bVar7;
                  }
                }
                uVar34 = uVar34 + 1;
                puVar29 = puVar29 + 1;
                pbVar33 = pbVar33 + 1;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
            uVar34 = uVar40;
          } while (uVar40 != 0x10);
          uVar26 = uVar26 + 4;
        } while ((int)(bVar5 + 3) < iVar48);
        if (iVar48 < 1) {
          iVar25 = 0;
          iVar49 = 0;
        }
        else {
          iVar50 = 0;
          puVar17 = local_54;
          iVar49 = iVar48;
          do {
            *puVar17 = 0;
            local_508[iVar50] = 0;
            iVar50 = iVar50 + 1;
            puVar17[1] = 0;
            puVar17[2] = 0;
            puVar17 = puVar17 + 3;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar49 = 0;
          uVar26 = 0xffffffff;
          puVar17 = local_54;
          do {
            iVar50 = 0;
            pbVar33 = local_4e0;
            iVar52 = 0x10;
            do {
              if ((int)uVar26 < (int)(uint)local_4e0[iVar50]) {
                uVar26 = (uint)*pbVar33;
                break;
              }
              iVar50 = iVar50 + 1;
              pbVar33 = pbVar33 + 1;
              iVar52 = iVar52 + -1;
            } while (iVar52 != 0);
            if ((int)uVar26 < 0x10) {
              iVar50 = 0x10 - uVar26;
              pbVar33 = local_4e0 + uVar26;
              uVar34 = uVar26;
              do {
                if (uVar26 == *pbVar33) {
                  iVar52 = uVar34 * 4;
                  uVar8 = *puVar17;
                  bVar27 = local_508[iVar49];
                  *pbVar33 = (byte)iVar49;
                  bVar7 = local_4b8[iVar52];
                  bVar22 = local_4b8[iVar52 + 1];
                  bVar24 = local_4b8[iVar52 + 2];
                  local_508[iVar49] = bVar27 + 1;
                  *puVar17 = bVar7 + uVar8;
                  puVar17[1] = (ushort)bVar22 + puVar17[1];
                  puVar17[2] = (ushort)bVar24 + puVar17[2];
                }
                uVar34 = uVar34 + 1;
                pbVar33 = pbVar33 + 1;
                iVar50 = iVar50 + -1;
              } while (iVar50 != 0);
            }
            bVar7 = local_508[iVar49];
            iVar49 = iVar49 + 1;
            *puVar17 = *puVar17 / (ushort)bVar7;
            puVar17[1] = puVar17[1] / (ushort)bVar7;
            puVar17[2] = puVar17[2] / (ushort)bVar7;
            puVar17 = puVar17 + 3;
          } while (iVar48 != iVar49);
          iVar50 = 0;
          iVar49 = 0;
          iVar25 = 0;
          puVar17 = local_54;
          iVar52 = 0;
          do {
            iVar16 = iVar52 + 1;
            if (iVar16 < iVar48) {
              iVar42 = iVar48 - iVar16;
              puVar35 = local_54 + iVar16 * 3;
              iVar32 = iVar16;
              do {
                uVar8 = (short)(*puVar17 - *puVar35) >> 0xf;
                uVar9 = (short)(puVar17[1] - puVar35[1]) >> 0xf;
                uVar10 = (short)(puVar17[2] - puVar35[2]) >> 0xf;
                iVar37 = (int)(short)((uVar8 ^ *puVar17 - *puVar35) - uVar8) +
                         (int)(short)((uVar9 ^ puVar17[1] - puVar35[1]) - uVar9) +
                         (int)(short)((uVar10 ^ puVar17[2] - puVar35[2]) - uVar10);
                if (iVar50 < iVar37) {
                  iVar49 = iVar52;
                  iVar50 = iVar37;
                  iVar25 = iVar32;
                }
                iVar32 = iVar32 + 1;
                puVar35 = puVar35 + 3;
                iVar42 = iVar42 + -1;
              } while (iVar42 != 0);
            }
            puVar17 = puVar17 + 3;
            iVar52 = iVar16;
          } while (iVar48 != iVar16);
        }
        uVar8 = local_4d0[iVar49 * 3];
        uVar9 = local_4d0[iVar25 * 3];
        uVar10 = local_4d0[iVar49 * 3 + 2];
        uVar11 = local_4d0[iVar49 * 3 + 1];
        uVar12 = local_4d0[iVar25 * 3 + 2];
        uVar13 = local_4d0[iVar25 * 3 + 1];
        uVar40 = uVar8 & 0xf8;
        uVar26 = uVar10 & 0xf8;
        uVar34 = uVar11 & 0xfc;
        uVar20 = uVar9 & 0xf8;
        if ((uVar40 == (uVar9 & 0xf8)) && (uVar20 = uVar40, uVar8 != uVar9)) {
          if (uVar9 < uVar8) {
            if (uVar40 < 0xf8) {
              uVar40 = uVar40 + 8 & 0xf8;
            }
          }
          else if (uVar40 < 0xf8) {
            uVar20 = uVar40 + 8 & 0xff;
          }
        }
        uVar44 = uVar13 & 0xfc;
        if ((uVar34 == (uVar13 & 0xfc)) && (uVar44 = uVar34, uVar11 != uVar13)) {
          if (uVar13 < uVar11) {
            if (uVar34 < 0xfc) {
              uVar34 = uVar34 + 4 & 0xff;
            }
          }
          else if (uVar34 < 0xfc) {
            uVar44 = uVar34 + 4 & 0xff;
          }
        }
        uVar21 = uVar12 & 0xf8;
        if ((uVar26 == (uVar12 & 0xf8)) && (uVar21 = uVar26, uVar10 != uVar12)) {
          if (uVar12 < uVar10) {
            if (uVar26 < 0xf8) {
              uVar26 = uVar26 + 8 & 0xff;
            }
          }
          else if (uVar26 < 0xf8) {
            uVar21 = uVar26 + 8 & 0xff;
          }
        }
        uVar18 = uVar40 << 8 | uVar34 << 3;
        uVar15 = uVar20 << 8 | uVar44 << 3;
        uVar19 = uVar18 | uVar26 >> 3;
        uVar14 = uVar15 | uVar21 >> 3;
        bVar30 = (byte)uVar40;
        bVar27 = (byte)uVar34;
        bVar24 = (byte)uVar26;
        bVar36 = (byte)uVar20;
        bVar31 = (byte)uVar44;
        bVar22 = (byte)uVar21;
        bVar45 = (byte)uVar19;
        local_502 = (byte)uVar14;
        bVar7 = (byte)(uVar18 >> 8);
        local_501 = (byte)(uVar15 >> 8);
        if (bVar5) {
          if (uVar14 < uVar19) {
            local_4fc = bVar30;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_4f9 = bVar36;
            local_503 = bVar7;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_504 = bVar45;
          }
          else {
            local_4f9 = bVar30;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_4fc = bVar36;
            local_503 = local_501;
            local_501 = bVar7;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_504 = local_502;
            local_502 = bVar45;
          }
          local_4f6 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc * 2 + (uint)local_4f9) *
                             (longlong)local_6c) >> 0x20);
          local_4f5 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb * 2 + (uint)local_4f8) *
                             (longlong)local_6c) >> 0x20);
          local_4f4 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa * 2 + (uint)local_4f7) *
                             (longlong)local_6c) >> 0x20);
          local_4f3 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc + (uint)local_4f9 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f2 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb + (uint)local_4f8 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f1 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa + (uint)local_4f7 * 2) *
                             (longlong)local_6c) >> 0x20);
        }
        else {
          if (uVar14 < uVar19) {
            local_4fc = bVar36;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_4f9 = bVar30;
            local_503 = local_501;
            local_501 = bVar7;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_504 = local_502;
            local_502 = bVar45;
          }
          else {
            local_4f9 = bVar36;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_4fc = bVar30;
            local_503 = bVar7;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_504 = bVar45;
          }
          local_4f6 = (char)((int)((uint)local_4fc + (uint)local_4f9) >> 1);
          local_4f5 = (char)((int)((uint)local_4fb + (uint)local_4f8) >> 1);
          local_4f4 = (char)((int)((uint)local_4fa + (uint)local_4f7) >> 1);
        }
        local_4fd = 0;
        local_500 = 0;
        local_4ff = 0;
        local_4fe = 0;
        if (bVar5) {
          uVar26 = 4;
        }
        else {
          uVar26 = 3;
        }
        iVar48 = 0;
        pbVar43 = local_4b8 + 2;
        pbVar39 = local_4b8 + 1;
        pbVar51 = local_4b8 + 3;
        pbVar33 = local_68;
        do {
          uVar34 = (uint)*pbVar33;
          uVar40 = 0;
          pbVar23 = local_4b8 + iVar48 * 0x10 + 3;
          do {
            if ((!bVar6) || (uVar20 = 3, 0x7e < *pbVar23)) {
              if (uVar26 != 0) {
                bVar7 = pbVar23[(int)(local_4b8 + (iVar48 * 0x10 - (int)pbVar51))];
                bVar22 = pbVar23[(int)pbVar39 - (int)pbVar51];
                bVar24 = pbVar23[(int)pbVar43 - (int)pbVar51];
                pbVar41 = &local_4fc;
                iVar49 = 0;
                uVar20 = uVar26;
                do {
                  pbVar1 = pbVar41 + 1;
                  bVar27 = *pbVar41;
                  pbVar2 = pbVar41 + 2;
                  pbVar41 = pbVar41 + 3;
                  local_4f0[iVar49] =
                       ((uint)bVar7 - (uint)bVar27) * ((uint)bVar7 - (uint)bVar27) +
                       ((uint)bVar22 - (uint)*pbVar1) * ((uint)bVar22 - (uint)*pbVar1) * 4 +
                       ((uint)bVar24 - (uint)*pbVar2) * ((uint)bVar24 - (uint)*pbVar2);
                  uVar20 = uVar20 - 1;
                  iVar49 = iVar49 + 1;
                } while (uVar20 != 0);
              }
              if (uVar26 < 2) {
                uVar20 = 0;
              }
              else {
                iVar50 = uVar26 - 1;
                uVar44 = 1;
                piVar38 = local_4f0;
                uVar20 = 0;
                iVar49 = local_4f0[0];
                do {
                  piVar38 = piVar38 + 1;
                  if (*piVar38 < iVar49) {
                    uVar20 = uVar44;
                    iVar49 = *piVar38;
                  }
                  uVar44 = uVar44 + 1;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
                uVar20 = uVar20 & 3;
              }
            }
            bVar5 = uVar40 != 6;
            uVar44 = uVar40 & 0x3f;
            pbVar23 = pbVar23 + 4;
            uVar40 = uVar40 + 2;
            uVar34 = uVar20 << uVar44 | uVar34;
            *pbVar33 = (byte)uVar34;
          } while (bVar5);
          bVar5 = iVar48 != 3;
          pbVar51 = pbVar51 + 0x10;
          pbVar39 = pbVar39 + 0x10;
          pbVar43 = pbVar43 + 0x10;
          pbVar33 = pbVar33 + 1;
          iVar48 = iVar48 + 1;
        } while (bVar5);
        if (param_4 == 0xd) {
          if (bVar4) {
            param_6[7] = 0xff;
            *param_6 = 0xff;
            param_6[1] = 0xff;
            param_6[2] = 0xff;
            param_6[3] = 0xff;
            param_6[4] = 0xff;
            param_6[5] = 0xff;
            param_6[6] = 0xff;
            param_6 = param_6 + 8;
          }
          else {
            *param_6 = local_4b1 & 0xf0 | local_4b8[3] >> 4;
            param_6[1] = local_4a9 & 0xf0 | local_4ad >> 4;
            param_6[2] = local_4a1 & 0xf0 | local_4a5 >> 4;
            param_6[3] = local_499 & 0xf0 | local_49d >> 4;
            param_6[4] = local_491 & 0xf0 | local_495 >> 4;
            param_6[5] = local_489 & 0xf0 | local_48d >> 4;
            param_6[6] = local_481 & 0xf0 | local_485 >> 4;
            param_6[7] = local_479 & 0xf0 | local_47d >> 4;
            param_6 = param_6 + 8;
          }
        }
        else if (iStack00000024 == 0xe) {
          param_6 = (byte *)((int (*)())FUN_0001be50)(local_4b8,param_6);
        }
        local_74 = local_74 + 4;
        *param_6 = local_504;
        param_6[1] = local_503;
        param_6[2] = local_502;
        param_6[3] = local_501;
        param_6[4] = local_500;
        param_6[5] = local_4ff;
        param_6[6] = local_4fe;
        param_6[7] = local_4fd;
        param_6 = param_6 + 8;
      } while (local_74 < param_1);
    }
    local_78 = local_78 + 4;
    if (local_70 <= local_78) {
      return;
    }
  } while( true );
}

/* FUN_0001d1e0 @ 0x1d1e0 (808 bytes) */
int FUN_0001d1e0(param_1, param_2, param_3, param_4, param_5, param_6)
  uint param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  if (param_4 == 0xd) {
    if (param_3 != 0) {
      iVar10 = ((int)param_1 >> 2) + (uint)((int)param_1 < 0 && (param_1 & 3) != 0);
      uVar9 = 0;
      do {
        if (param_2 != 0) {
          uVar13 = 0;
          do {
            if (param_1 != 0) {
              iVar8 = ((int)uVar13 >> 2) + (uint)((int)uVar13 < 0 && (uVar13 & 3) != 0);
              uVar14 = 0;
              iVar11 = uVar13 + iVar8 * -4;
              do {
                iVar2 = iVar10;
                if (iVar10 == 0) {
                  iVar2 = 1;
                }
                iVar1 = ((int)uVar14 >> 2) + (uint)((int)uVar14 < 0 && (uVar14 & 3) != 0);
                iVar6 = iVar1 + iVar2 * iVar8;
                uVar5 = uVar14 + iVar1 * -4;
                iVar2 = iVar6 * 0x10;
                iVar1 = param_5 + iVar2;
                ((int (*)())FUN_0001c1c0)((uint)CONCAT11(*(undefined1 *)(iVar1 + 9),*(undefined1 *)(iVar1 + 8)),
                             (uint)CONCAT11(*(undefined1 *)(iVar1 + 0xb),*(undefined1 *)(iVar1 + 10)
                                           ),
                             (int)(uint)*(byte *)(iVar2 + iVar11 + param_5 + 0xc) >>
                             (uVar5 * 2 & 0x3e) & 3,param_6);
                bVar3 = *(byte *)((iVar6 * 8 + iVar11) * 2 + param_5 + ((int)uVar5 >> 1));
                if ((uVar5 & 1) == 0) {
                  bVar3 = bVar3 << 4;
                }
                uVar14 = uVar14 + 1;
                *(byte *)(param_6 + 3) = bVar3 & 0xf0;
                param_6 = param_6 + 4;
              } while (uVar14 < param_1);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < param_2);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < param_3);
    }
  }
  else if (param_4 == 0xe) {
    if (param_3 != 0) {
      iVar10 = ((int)param_1 >> 1) + (uint)((int)param_1 < 0 && (param_1 & 1) != 0);
      uVar9 = 0;
      do {
        if (param_2 != 0) {
          uVar13 = 0;
          do {
            if (param_1 != 0) {
              iVar8 = ((int)uVar13 >> 2) + (uint)((int)uVar13 < 0 && (uVar13 & 3) != 0);
              uVar14 = 0;
              iVar11 = uVar13 + iVar8 * -4;
              do {
                iVar2 = iVar10;
                if (iVar10 == 0) {
                  iVar2 = 1;
                }
                iVar6 = ((int)uVar14 >> 2) + (uint)((int)uVar14 < 0 && (uVar14 & 3) != 0);
                iVar1 = uVar14 + iVar6 * -4;
                iVar2 = (iVar6 + iVar2 * iVar8) * 0x10;
                uVar12 = iVar1 + iVar11 * 4;
                iVar6 = param_5 + iVar2;
                ((int (*)())FUN_0001c1c0)((uint)CONCAT11(*(undefined1 *)(iVar6 + 9),*(undefined1 *)(iVar6 + 8)),
                             (uint)CONCAT11(*(undefined1 *)(iVar6 + 0xb),*(undefined1 *)(iVar6 + 10)
                                           ),
                             (int)(uint)*(byte *)(iVar2 + iVar11 + param_5 + 0xc) >>
                             (iVar1 * 2 & 0x3eU) & 3,param_6);
                bVar3 = *(byte *)(param_5 + iVar2);
                uVar5 = (uint)bVar3;
                uVar7 = (uint)*(byte *)(iVar6 + 1);
                if (iVar11 < 2) {
                  uVar4 = (uint)*(byte *)(iVar6 + 4) << 0x10 | (uint)*(byte *)(iVar6 + 3) << 8 |
                          (uint)*(byte *)(iVar6 + 2);
                }
                else {
                  uVar4 = (uint)*(byte *)(iVar6 + 7) << 0x10 | (uint)*(byte *)(iVar6 + 6) << 8 |
                          (uint)*(byte *)(iVar6 + 5);
                }
                uVar12 = uVar4 >> ((uVar12 + (((int)uVar12 >> 3) +
                                             (uint)((int)uVar12 < 0 && (uVar12 & 7) != 0)) * -8) * 3
                                  & 0x3f) & 7;
                if (uVar5 <= uVar7) {
                  switch(uVar12) {
                  case 0:
                    goto code_r0x0001d62c;
                  case 1:
                    goto code_r0x0001d634;
                  case 2:
                    bVar3 = (byte)(uint)((ulonglong)
                                         ((longlong)(int)(uVar5 * 4 + uVar7) * 0x92492493) >> 0x22);
                    break;
                  case 3:
                    iVar1 = uVar5 * 3;
                    iVar2 = uVar7 << 1;
                    goto code_r0x0001d594;
                  case 4:
                    iVar1 = uVar7 * 3;
                    iVar2 = uVar5 << 1;
                    goto code_r0x0001d670;
                  case 5:
                    bVar3 = (byte)(uint)((ulonglong)
                                         ((longlong)(int)(uVar5 + uVar7 * 4) * 0x92492493) >> 0x22);
                    break;
                  default:
                    goto LAB_0001d6b0;
                  case 7:
                    bVar3 = 0xff;
                  }
                  goto code_r0x0001d6b4;
                }
                switch(uVar12) {
                case 0:
code_r0x0001d62c:
                  break;
                case 1:
code_r0x0001d634:
                  bVar3 = *(byte *)(iVar6 + 1);
                  break;
                case 2:
                  bVar3 = (byte)(uint)((ulonglong)((longlong)(int)(uVar5 * 6 + uVar7) * 0x92492493)
                                      >> 0x22);
                  break;
                case 3:
                  iVar1 = uVar5 * 5;
                  iVar2 = uVar7 << 1;
                  goto code_r0x0001d594;
                case 4:
                  iVar1 = uVar7 * 3;
                  iVar2 = uVar5 << 2;
                  goto code_r0x0001d670;
                case 5:
                  iVar1 = uVar5 * 3;
                  iVar2 = uVar7 << 2;
code_r0x0001d594:
                  bVar3 = (byte)(uint)((ulonglong)((longlong)(iVar1 + iVar2) * 0x92492493) >> 0x22);
                  break;
                case 6:
                  iVar1 = uVar7 * 5;
                  iVar2 = uVar5 << 1;
code_r0x0001d670:
                  bVar3 = (byte)(uint)((ulonglong)((longlong)(iVar2 + iVar1) * 0x92492493) >> 0x22);
                  break;
                case 7:
                  bVar3 = (byte)(uint)((ulonglong)((longlong)(int)(uVar5 + uVar7 * 6) * 0x92492493)
                                      >> 0x22);
                  break;
                default:
LAB_0001d6b0:
                  bVar3 = 0;
                }
code_r0x0001d6b4:
                uVar14 = uVar14 + 1;
                *(byte *)(param_6 + 3) = bVar3;
                param_6 = param_6 + 4;
              } while (uVar14 < param_1);
            }
            uVar13 = uVar13 + 1;
          } while (uVar13 < param_2);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < param_3);
    }
  }
  else if ((param_4 == 0xc) && (param_3 != 0)) {
    iVar10 = ((int)param_1 >> 2) + (uint)((int)param_1 < 0 && (param_1 & 3) != 0);
    uVar9 = 0;
    do {
      if (param_2 != 0) {
        uVar13 = 0;
        do {
          if (param_1 != 0) {
            iVar11 = ((int)uVar13 >> 2) + (uint)((int)uVar13 < 0 && (uVar13 & 3) != 0);
            uVar14 = 0;
            iVar8 = param_6;
            do {
              iVar2 = iVar10;
              if (iVar10 == 0) {
                iVar2 = 1;
              }
              iVar1 = ((int)uVar14 >> 2) + (uint)((int)uVar14 < 0 && (uVar14 & 3) != 0);
              param_6 = iVar8 + 4;
              iVar6 = uVar14 + iVar1 * -4;
              uVar14 = uVar14 + 1;
              iVar2 = (iVar1 + iVar2 * iVar11) * 8;
              iVar1 = param_5 + iVar2;
              ((int (*)())FUN_0001c1c0)((uint)CONCAT11(*(undefined1 *)(iVar1 + 1),
                                          *(undefined1 *)(param_5 + iVar2)),
                           (uint)CONCAT11(*(undefined1 *)(iVar1 + 3),*(undefined1 *)(iVar1 + 2)),
                           (int)(uint)*(byte *)(uVar13 + iVar11 * -4 + iVar2 + param_5 + 4) >>
                           (iVar6 * 2 & 0x3eU) & 3,iVar8);
              iVar8 = param_6;
            } while (uVar14 < param_1);
          }
          uVar13 = uVar13 + 1;
        } while (uVar13 < param_2);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_3);
  }
  return;
}

/* FUN_0001d7c0 @ 0x1d7c0 (148 bytes) */
uint FUN_0001d7c0(double fparam_1)
{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  fVar1 = (float)fparam_1;
  uVar3 = (uint)GH_F2U(fVar1) >> 0x17 & 0xff;
  iVar2 = uVar3 - 0x7f;
  if (iVar2 < 0x11) {
    if (iVar2 < -0xe) {
      if (iVar2 < -0x25) {
        iVar4 = 0;
        uVar3 = 0;
      }
      else {
        iVar4 = 0;
        uVar3 = (((uint)GH_F2U(fVar1) & 0x7fffff | 0x800000) >> (-iVar2 - 0xeU & 0x3f)) >> 0xd;
      }
    }
    else {
      iVar4 = uVar3 - 0x70;
      uVar3 = ((uint)GH_F2U(fVar1) & 0x7fffff) >> 0xd;
    }
  }
  else {
    iVar4 = 0x1f;
    uVar3 = 0x3ff;
  }
  return ((uint)GH_F2U(fVar1) >> 0x1f) << 0xf | iVar4 << 10 | uVar3;
}

/* FUN_0001d880 @ 0x1d880 (704 bytes) */
int FUN_0001d880(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  bVar1 = param_2 == 0;
  iVar19 = *param_1;
  if (bVar1) {
    uVar17 = *(uint *)(iVar19 + 0x314);
  }
  else {
    uVar17 = 0;
  }
  iVar16 = *(int *)(iVar19 + 0x318);
  if (((*(uint *)(param_1[1] + 0x88) & 1) == 0) || (!bVar1)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar1) {
    if ((uVar17 == 0) || (uVar15 = 1, iVar16 == 0)) {
      uVar15 = 0;
    }
    if ((uVar17 & 3) != 0) {
      uVar15 = 0;
    }
  }
  else {
    uVar15 = 1;
  }
  uVar7 = *(uint *)(iVar19 + 0x304) & 0xffff0000;
  if (!bVar4) {
    uVar14 = *(uint *)(param_1[1] + 0x88) & 0xff7f0000;
  }
  else {
    uVar14 = 0xff7f0000;
  }
  bVar2 = uVar14 == 0;
  iVar20 = 0;
  iVar18 = 0;
LAB_0001dae4:
  do {
    while (bVar2) {
      uVar7 = *(uint *)(iVar19 + 0x300);
      if (!bVar4) {
        uVar14 = *(uint *)(param_1[1] + 0x84) & 0xffff;
      }
      else {
        uVar14 = 0xffff;
      }
      iVar18 = iVar18 + 1;
      if (1 < iVar18) {
        iVar19 = param_1[1];
        *(undefined4 *)(iVar19 + 0x84) = 0;
        *(uint *)(iVar19 + 0x88) = *(uint *)(iVar19 + 0x88) & 0xfffb;
        return uVar15;
      }
      bVar2 = uVar14 == 0;
      iVar20 = 0x10;
    }
    uVar5 = *(uint *)(&DAT_001d91f0 + iVar20 * 4);
    if ((uVar14 & uVar5) != 0) {
      uVar14 = uVar14 & ~uVar5;
      puVar9 = (undefined1 *)((int)param_1 + iVar20 + 8);
      bVar2 = uVar14 == 0;
      *(undefined1 *)((int)param_1 + iVar20 + 8) = 1;
      if ((uVar7 & uVar5) != 0) {
        iVar10 = iVar20 * 0x18;
        iVar6 = iVar10 + iVar19;
        uVar13 = *(uint *)(iVar10 + iVar19);
        uVar5 = (uint)*(short *)(iVar6 + 10);
        uVar8 = *(uint *)(iVar6 + 4);
        iVar12 = uVar5 - 1;
        uVar11 = (*(ushort *)(iVar6 + 8) & 0xffff7fff) - 0x1400;
        if (((!bVar1) || (((uVar17 <= uVar13 && (uVar13 < iVar16 + uVar17)) && ((uVar13 & 3) == 0)))
            ) && ((uVar5 < 5 && (uVar8 < 0x200)))) {
          if ((uVar8 & 3) == 0) {
            if ((uVar11 < 0xb) && (iVar6 = uVar11 * 4, *(int *)(&DAT_001d96f4 + iVar6) == 1)) {
              if (uVar8 != 0) {
                uVar5 = uVar8 >> 2;
              }
              bVar2 = uVar14 == 0;
              iVar12 = (iVar6 + iVar12) * 4;
              param_1[iVar20 + 10] =
                   *(uint *)(&DAT_001d9644 + iVar12) & 0x7f |
                   (uVar5 & 0x7f) << 8 | param_1[iVar20 + 10] & 0xffff8080U;
              param_1[iVar20 + 0x2a] = uVar13 - uVar17;
              uVar8 = *(uint *)(&DAT_001d9568 + iVar6);
              uVar5 = *(uint *)(&DAT_001d9594 + iVar12);
              sVar3 = *(short *)(iVar10 + iVar19 + 8);
              param_1[iVar20 + 0x6a] =
                   (*(uint *)(&DAT_001d92a8 + iVar12) & 7) << 9 |
                   (*(uint *)(&DAT_001d9358 + iVar12) & 7) << 6 |
                   (*(uint *)(&DAT_001d9408 + iVar12) & 7) << 3 |
                   *(uint *)(&DAT_001d94b8 + iVar12) & 7 | param_1[iVar20 + 0x6a] & 0xfffff000U;
              param_1[iVar20 + 0x4a] =
                   (uint)(int)sVar3 >> 0x10 & 0x8000 |
                   (uVar8 & 1) << 0xe | uVar5 & 0xf | param_1[iVar20 + 0x4a] & 0xffff3ff0U;
              goto LAB_0001dae0;
            }
            bVar2 = uVar14 == 0;
            *puVar9 = 0;
            goto LAB_0001dae4;
          }
        }
        bVar2 = uVar14 == 0;
        *puVar9 = 0;
        goto LAB_0001dae4;
      }
    }
LAB_0001dae0:
    iVar20 = iVar20 + 1;
  } while( true );
}

/* FUN_0001db50 @ 0x1db50 (180 bytes) */
int FUN_0001db50(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint *param_3;
  uint *param_4;
  uint *param_5;
  int *param_6;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0x7fe0;
  if (*(uint *)(param_1 + 0x29d8) < 0x7ffd) {
    uVar1 = *(uint *)(param_1 + 0x29d8) & 0xffffffe0;
  }
  *param_3 = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_6 = 0;
  if (param_2 < uVar1) {
    *param_3 = param_2;
    if ((param_2 & 0x1f) != 0) {
      *param_3 = param_2 + 0x1f & 0xffffffe0;
    }
    uVar1 = 0;
    *param_5 = 1;
    uVar2 = *param_3;
  }
  else {
    *param_3 = uVar1;
    *param_5 = param_2 / uVar1;
    uVar2 = *param_3;
    uVar1 = (param_2 - (param_2 / uVar2) * uVar2) + 3 & 0xfffffffc;
  }
  *param_4 = uVar2 >> 2;
  if (0x1fff < *param_5) {
    return 0;
  }
  *param_6 = 2 - (uint)(uVar1 == 0);
  return 1;
}

/* FUN_0001dc10 @ 0x1dc10 (976 bytes) */
int FUN_0001dc10(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c [3];
  
  iVar5 = param_2[1];
  iVar7 = *param_2;
  if (*(int *)(iVar5 + 0x84) != 0 || (*(uint *)(iVar5 + 0x88) & 0xfffffff5) != 0) {
    iVar5 = ((int (*)())FUN_0001d880)(param_2,0);
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = param_2[1];
  }
  uVar4 = *(uint *)(iVar5 + 0x88);
  if (*(int *)(iVar5 + 0x84) == 0 && uVar4 == 0) {
    return 1;
  }
  if ((param_2[0x8a] != 0) && (((uVar4 ^ 1) & 1) != 0)) {
    if (*(short *)(iVar7 + 0x312) == -0x7a42) {
      if (param_2[0x8c] == 7) {
        if ((uVar4 & 2) != 0) {
          *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
          *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
          *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
          iVar5 = param_2[1];
        }
        goto LAB_0001dcf8;
      }
    }
    else if (param_2[0x8c] == 6) {
LAB_0001dcf8:
      *(undefined4 *)(iVar5 + 0x84) = 0;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      return 1;
    }
  }
  local_2c[0] = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar5 = ((int (*)())FUN_0001db50)(param_1,*(undefined4 *)(iVar7 + 0x318),local_2c,&local_30,&local_34,&local_38
                      );
  if (iVar5 != 0) {
    if (local_38 < 2) {
      uVar3 = *(uint *)(iVar7 + 0x318);
      uVar4 = 0;
    }
    else {
      uVar3 = *(uint *)(iVar7 + 0x318);
      uVar4 = (uVar3 - (uVar3 / local_2c[0]) * local_2c[0]) + 3 & 0xfffffffc;
    }
    if ((*(short *)(iVar7 + 0x312) == -0x7a42) && (local_38 < 0x4f)) {
      iVar5 = FUN_0000bd60(param_1,param_2,(local_38 * 0x12 + 0xc) * 4,
                           uVar4 + local_2c[0] * local_34,*(undefined4 *)(iVar7 + 0x314),uVar3);
      if (iVar5 != 0) goto LAB_0001ddc0;
      uVar3 = *(uint *)(iVar7 + 0x318);
    }
    iVar5 = FUN_0000bc60(param_1,param_2,*(undefined4 *)(iVar7 + 0x314),
                         *(undefined4 *)(iVar7 + 0x314),uVar3);
    if (iVar5 != 0) {
LAB_0001ddc0:
      if (param_2[0x8c] == 7) {
        uVar3 = *(uint *)(iVar7 + 0x314);
        *(undefined1 *)(param_2[0x8a] + 0x15) = 0;
        uVar3 = (uVar3 & 0xfff) - (uVar3 & 0xfe0) >> 2;
        *(undefined1 *)(param_2[0x8a] + 0x17) = 0;
        *(undefined1 *)(param_2[0x8a] + 0x34) = 1;
        *(undefined1 *)(param_2[0x8a] + 0x35) = 1;
        piVar6 = (int *)param_2[0x8b];
        piVar6[0x280] = (int)((unsigned char *)0x00001393U);
        piVar6[8] = piVar6[8] & 0xafffffffU | 0xa0000000;
        piVar6[0x281] = 10;
        piVar6[0x287] = 2;
        piVar6[0x285] = 2;
        piVar6[0x283] = 0x20000;
        piVar6[0x284] = 0x575;
        piVar6[0x282] = 0x5c8;
        piVar6[0x286] = 0x574;
        *(short *)(piVar6 + 0x10) = (short)((int)(piVar6 + 0x288) - (int)(piVar6 + 0x280) >> 2);
        uVar1 = *(uint *)(iVar7 + 0x314);
        piVar6[0x12] = 0;
        piVar6[0x11] = uVar1 & 0xfe0;
        piVar6[0x13] = local_2c[0] * local_34;
        piVar6[0x14] = local_2c[0] * local_34;
        piVar6[0x15] = 0;
        *(short *)((int)piVar6 + 0x42) = (short)local_38;
        piVar6[0x17] = 0;
        puVar2 = (undefined4 *)
                 FUN_00030a60(piVar6 + 0x288,6,local_2c[0],local_2c[0],0,uVar3,
                              local_34 << 0x10 | local_30);
        if (uVar4 != 0) {
          puVar2 = (undefined4 *)
                   FUN_00030a60(puVar2,6,local_2c[0],local_2c[0],0,uVar3,uVar4 >> 2 | 0x10000);
        }
        *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
        *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
        *puVar2 = 0xd0b;
        puVar2[2] = 0x5c8;
        puVar2[1] = 5;
        puVar2[3] = 0x10000;
        *piVar6 = (int)puVar2 + (0x10 - (int)(piVar6 + 0x280)) >> 2;
      }
      *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
      iVar5 = param_2[1];
      *(undefined4 *)(iVar5 + 0x84) = 0;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_0001dff0 @ 0x1dff0 (140 bytes) */
int FUN_0001dff0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(param_1 + 0x2998))(param_1 + 0x240,1);
  *(int *)(param_1 + 0x298c) = iVar2;
  puVar3 = *(uint **)(param_1 + 0x1d8);
  *puVar3 = iVar2 - (int)puVar3 >> 2 | *puVar3;
  puVar1 = *(undefined4 **)(param_1 + 0x298c);
  *(undefined4 **)(param_1 + 0x1d8) = puVar1;
  *puVar1 = 0x3a000000;
  *(undefined4 **)(param_1 + 0x298c) = puVar1 + 1;
                    
                    
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
  return;
}

/* _gldPageoffBuffer @ 0x1e080 (480 bytes) */
int _gldPageoffBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  
  if (*(int *)(param_2 + 8) != 0) {
    _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
    puVar3 = (undefined4 *)**(undefined4 **)(param_2 + 8);
    cVar1 = (*(unsigned char *)((unsigned char *)&(MACH_HEADER.sizeofcmds) + 2));
    if ((puVar3 == (undefined4 *)0x0) ||
       (cVar1 = *(char *)((int)puVar3 + 0x16), *(char *)((int)puVar3 + 0x16) != '\a')) {
      if (cVar1 == '\x06') {
        if ((0x1ffff < (int)puVar3[4]) &&
           (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
          ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
        }
        if ((*(ushort *)(puVar3 + 10) & ~*(ushort *)(puVar3 + 7) & 1) != 0) {
          iVar4 = ((int (*)())FUN_0001a0d0)(param_1,puVar3[3]);
          if (iVar4 == 0) {
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar3 + 3,1,0,0);
          }
          *(ushort *)(puVar3 + 7) = *(ushort *)(puVar3 + 7) | *(ushort *)(puVar3 + 10);
        }
      }
    }
    else {
      if ((0x1ffff < (int)puVar3[4]) &&
         (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
        ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
      }
      if ((*(ushort *)(puVar3 + 10) & ~*(ushort *)(puVar3 + 7) & 1) != 0) {
        local_28 = *puVar3;
        local_24 = 0;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_28,2,0,0);
      }
      iVar4 = *(int *)(*(int *)(param_2 + 8) + 4);
      if ((*(uint *)(iVar4 + 0x20) & 0x10000000) != 0) {
        iVar2 = ((int (*)())FUN_0001a0d0)(param_1,*(undefined4 *)(iVar4 + 0x1c));
        if (iVar2 == 0) {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar4 + 0x1c,1,0,0);
        }
        *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xefffffff;
      }
    }
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}

/* FUN_0001e270 @ 0x1e270 (8 bytes) */
int FUN_0001e270()
{
  return 0;
}

/* FUN_0001e280 @ 0x1e280 (1184 bytes) */
int FUN_0001e280(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_r6;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *in_r10;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  uint *puVar12;
  uint local_48;
  int local_44;
  uint local_40;
  uint local_3c [6];
  
  bVar1 = param_3 == 0;
  if (bVar1) {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  puVar12 = (uint *)*param_2;
  if (*puVar12 == 0) {
    return 0;
  }
  if (((int *)param_2[2] == (int *)0x0) || (iVar4 = *(int *)param_2[2], iVar4 == 0)) {
LAB_0001e3b0:
    local_3c[0] = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    iVar4 = ((int (*)())FUN_0001db50)(param_1,puVar12[1],local_3c,&local_40,&local_44,&local_48);
    if (iVar4 == 0) {
      return 0;
    }
    if (local_48 < 2) {
      uVar7 = puVar12[1];
      uVar10 = 0;
    }
    else {
      uVar7 = puVar12[1];
      uVar10 = (uVar7 - (uVar7 / local_3c[0]) * local_3c[0]) + 3 & 0xfffffffc;
    }
    uVar5 = uVar7;
    if ((*(short *)(puVar12 + 3) == -0x771c) && (local_48 < 0x4f)) {
      if (bVar1) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0x49;
      }
      uVar5 = *puVar12;
      uVar3 = uVar10 + local_3c[0] * local_44;
      iVar4 = FUN_000065b0(param_1,param_2,iVar4 + (local_48 * 0x12 + 0xc) * 4,uVar3,uVar5,uVar7);
      if (iVar4 == 0) {
        uVar5 = puVar12[1];
        goto LAB_0001e440;
      }
    }
    else {
LAB_0001e440:
      uVar3 = *puVar12;
      iVar4 = FUN_00006470(param_1,param_2,uVar3,uVar3,uVar5);
      if (iVar4 == 0) {
        return 0;
      }
    }
    if (param_2[4] == 7) {
      uVar7 = *puVar12;
      uVar5 = 0;
      *(undefined1 *)(*(int *)param_2[2] + 0x15) = 0;
      uVar7 = (uVar7 & 0xfff) - (uVar7 & 0xfe0) >> 2;
      *(undefined1 *)(*(int *)param_2[2] + 0x17) = 0;
      *(undefined1 *)(*(int *)param_2[2] + 0x34) = 1;
      *(undefined1 *)(*(int *)param_2[2] + 0x35) = 1;
      piVar11 = *(int **)(param_2[2] + 4);
      piVar11[0x280] = (int)((unsigned char *)0x00001393U);
      piVar11[8] = piVar11[8] & 0xbfffffffU | 0xa0000000;
      piVar11[0x281] = 10;
      piVar11[0x283] = 0x20000;
      piVar11[0x287] = 2;
      piVar11[0x285] = 2;
      piVar11[0x284] = 0x575;
      piVar11[0x282] = 0x5c8;
      piVar11[0x286] = 0x574;
      *(short *)(piVar11 + 0x10) = (short)((int)(piVar11 + 0x288) - (int)(piVar11 + 0x280) >> 2);
      uVar3 = *puVar12;
      piVar11[0x12] = 0;
      piVar11[0x11] = uVar3 & 0xfe0;
      piVar11[0x13] = local_3c[0] * local_44;
      piVar11[0x14] = local_3c[0] * local_44;
      piVar11[0x17] = 0;
      piVar11[0x15] = 0;
      *(short *)((int)piVar11 + 0x42) = (short)local_48;
      uVar3 = local_3c[0];
      in_r10 = (undefined4 *)
               FUN_00030a60(piVar11 + 0x288,6,local_3c[0],local_3c[0],0,uVar7,
                            local_44 << 0x10 | local_40);
      if (uVar10 != 0) {
        uVar5 = 0;
        uVar3 = local_3c[0];
        in_r10 = (undefined4 *)
                 FUN_00030a60(in_r10,6,local_3c[0],local_3c[0],0,uVar7,uVar10 >> 2 | 0x10000);
      }
      puVar9 = in_r10 + 4;
      *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
      *(ushort *)(*(int *)param_2[2] + 0x28) = *(ushort *)(*(int *)param_2[2] + 0x28) & 0xfffe;
      *in_r10 = 0xd0b;
      in_r10[2] = 0x5c8;
      in_r10[1] = 5;
      in_r10[3] = 0x10000;
      if (!bVar1) {
        uVar2 = *(undefined4 *)(param_1 + 0x1d74);
        puVar9 = in_r10 + 5;
        in_r10[4] = 0x4790b1;
        iVar4 = 0x48;
        do {
          *puVar9 = uVar2;
          puVar9 = puVar9 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *piVar11 = (int)puVar9 - (int)(piVar11 + 0x280) >> 2;
    }
    iVar4 = *(int *)param_2[2];
    *(undefined1 *)(iVar4 + 0x14) = 1;
    puVar6 = (uint *)param_2[1];
    if (((*puVar6 & 2) == 0) || ((*(uint *)(param_1 + 0x24) & 2) == 0)) goto LAB_0001e6e0;
    FUN_0000b620(param_1,*puVar12,puVar12[2],uVar3,uVar5,puVar6,iVar4,in_r10);
  }
  else {
    puVar6 = (uint *)param_2[1];
    uVar10 = *puVar6;
    in_r10 = (undefined4 *)(uVar10 ^ 1);
    if (((uint)in_r10 & 1) == 0) goto LAB_0001e3b0;
    if (*(short *)(puVar12 + 3) != -0x771c) {
      if (param_2[4] == 6) {
        if (((uVar10 & 2) != 0) && ((*(uint *)(param_1 + 0x24) & 2) != 0)) {
          FUN_0000b620(param_1,*puVar12,puVar12[2],in_r6,iVar4,puVar6,0,uVar10 & 2);
          puVar6 = (uint *)param_2[1];
        }
        goto LAB_0001e6e0;
      }
      goto LAB_0001e3b0;
    }
    if (param_2[4] != 7) goto LAB_0001e3b0;
    if ((uVar10 & 2) == 0) goto LAB_0001e6e0;
    *(undefined1 *)(iVar4 + 0x14) = 1;
    *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
    iVar8 = *(int *)param_2[2];
    *(ushort *)(iVar8 + 0x28) = *(ushort *)(iVar8 + 0x28) & 0xfffe;
    if ((*(uint *)(param_1 + 0x24) & 2) != 0) {
      FUN_0000b620(param_1,*puVar12,puVar12[2],in_r6,iVar4,puVar6,iVar8,uVar10 & 2);
      puVar6 = (uint *)param_2[1];
      goto LAB_0001e6e0;
    }
  }
  puVar6 = (uint *)param_2[1];
LAB_0001e6e0:
  *puVar6 = 0;
  return 1;
}

/* FUN_0001e730 @ 0x1e730 (332 bytes) */
int FUN_0001e730(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar7 = *param_2;
  iVar6 = param_2[1];
  uVar5 = *(uint *)(iVar7 + 0x304);
  if ((*(uint *)(iVar7 + 0x300) & ~*(uint *)(iVar7 + 0x308)) == 0 &&
      (uVar5 & ~*(uint *)(iVar7 + 0x30c)) == 0) {
    if (*(int *)(iVar6 + 0x84) != 0 || (*(uint *)(iVar6 + 0x88) & 0xfffffff5) != 0) {
      iVar3 = ((int (*)())FUN_0001d880)(param_2,1);
      if (iVar3 == 0) goto LAB_0001e86c;
      uVar5 = *(uint *)(iVar7 + 0x304);
    }
    uVar5 = uVar5 & 0xffff0000;
    iVar8 = 0;
    iVar3 = 0;
    bVar1 = uVar5 == 0;
    while( true ) {
      while (!bVar1) {
        uVar9 = *(uint *)(&DAT_001d91f0 + iVar8 * 4);
        if ((uVar5 & uVar9) != 0) {
          iVar4 = *(int *)(iVar8 * 4 + iVar6);
          if ((iVar4 == 0) || (iVar4 = ((int (*)())FUN_0001e280)(param_1,iVar4,0), iVar4 == 0))
          goto LAB_0001e86c;
          uVar5 = uVar5 & ~uVar9;
          bVar1 = uVar5 == 0;
        }
        iVar8 = iVar8 + 1;
      }
      iVar3 = iVar3 + 1;
      uVar5 = *(uint *)(iVar7 + 0x300) & 0xffff;
      if (1 < iVar3) break;
      bVar1 = uVar5 == 0;
      iVar8 = 0x10;
    }
    if (*(int *)(iVar6 + 0x80) != 0) {
      ((int (*)())FUN_0001e280)(param_1,*(int *)(iVar6 + 0x80),1);
    }
    iVar6 = param_2[1];
    uVar2 = 1;
    *(undefined4 *)(iVar6 + 0x84) = 0;
    *(undefined4 *)(iVar6 + 0x88) = 0;
  }
  else {
LAB_0001e86c:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0001e890 @ 0x1e890 (16 bytes) */
int FUN_0001e890(param_1, param_2, param_3)
  uint *param_1;
  uint *param_2;
  uint param_3;
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  vec16 auVar4;
  vec16 auVar5;
  vec16 auVar6;
  vec16 auVar7;
  vec16 auVar8;
  vec16 auVar9;
  
  puVar3 = (uint *)((int)param_1 + (param_3 & 0x7ffffffe) * 2);
  for (; ((uint)param_1 & 0x1f) != 0; param_1 = param_1 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1 << 0x10 | uVar1 >> 0x10;
  }
  auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
  auVar7 = *(vec16 *)
            (((uint)param_2 & 0xf) * 0x10 + *(int *)PTR_DAT_001e88cc & 0xfffffff0);
  for (puVar2 = param_2; puVar2 < param_2 + 0x38; puVar2 = puVar2 + 8) {
    dataCacheBlockTouch(puVar2);
  }
  for (; param_1 < puVar3 + -0x40; param_1 = param_1 + 0x10) {
    dataCacheBlockTouch(param_2 + 0x38);
    auVar4 = *(vec16 *)((uint)(param_2 + 0xc) & 0xfffffff0);
    auVar9 = *(vec16 *)((uint)(param_2 + 8) & 0xfffffff0);
    auVar8 = vectorPermute(auVar6,*(vec16 *)((uint)(param_2 + 4) & 0xfffffff0),auVar7);
    dataCacheBlockTouch(param_2 + 0x40);
    auVar6 = *(vec16 *)((uint)(param_2 + 0x10) & 0xfffffff0);
    auVar5 = vectorPermute(*(vec16 *)((uint)(param_2 + 4) & 0xfffffff0),auVar9,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar8;
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar5;
    auVar5 = vectorPermute(auVar9,auVar4,auVar7);
    auVar4 = vectorPermute(auVar4,auVar6,auVar7);
    dataCacheBlockAllocate(param_1 + 8);
    *(vec16 *)((uint)(param_1 + 8) & 0xfffffff0) = auVar5;
    *(vec16 *)((uint)(param_1 + 0xc) & 0xfffffff0) = auVar4;
    param_2 = param_2 + 0x10;
  }
  for (; param_1 < puVar3 + -0x10; param_1 = param_1 + 0x10) {
    puVar2 = param_2 + 4;
    auVar9 = *(vec16 *)((uint)(param_2 + 8) & 0xfffffff0);
    auVar5 = *(vec16 *)((uint)(param_2 + 0xc) & 0xfffffff0);
    param_2 = param_2 + 0x10;
    auVar8 = vectorPermute(auVar6,*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar7);
    auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
    auVar4 = vectorPermute(*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar9,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar8;
    auVar8 = vectorPermute(auVar9,auVar5,auVar7);
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar4;
    auVar4 = vectorPermute(auVar5,auVar6,auVar7);
    dataCacheBlockAllocate(param_1 + 8);
    *(vec16 *)((uint)(param_1 + 8) & 0xfffffff0) = auVar8;
    *(vec16 *)((uint)(param_1 + 0xc) & 0xfffffff0) = auVar4;
  }
  if (param_1 + 8 < puVar3) {
    auVar4 = *(vec16 *)((uint)(param_2 + 4) & 0xfffffff0);
    auVar6 = vectorPermute(auVar6,auVar4,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar6;
    param_2 = param_2 + 8;
    auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
    auVar4 = vectorPermute(auVar4,auVar6,auVar7);
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar4;
    param_1 = param_1 + 8;
  }
  if (param_1 + 4 < puVar3) {
    puVar2 = param_2 + 4;
    param_2 = param_2 + 4;
    auVar6 = vectorPermute(auVar6,*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar7);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar6;
    param_1 = param_1 + 4;
  }
  else if (puVar3 <= param_1) goto LAB_0001eabc;
  do {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1 << 0x10 | uVar1 >> 0x10;
    param_1 = param_1 + 1;
  } while (param_1 < puVar3);
LAB_0001eabc:
  if ((param_3 & 1) != 0) {
    *param_1 = (uint)*(ushort *)param_2;
  }
  return;
}

/* FUN_0001e8a0 @ 0x1e8a0 (564 bytes) */
int FUN_0001e8a0(param_1, param_2, param_3)
  uint *param_1;
  uint *param_2;
  uint param_3;
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  vec16 auVar4;
  vec16 auVar5;
  vec16 auVar6;
  vec16 auVar7;
  vec16 auVar8;
  vec16 auVar9;
  
  puVar3 = (uint *)((int)param_1 + (param_3 & 0x7ffffffe) * 2);
  for (; ((uint)param_1 & 0x1f) != 0; param_1 = param_1 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1 << 0x10 | uVar1 >> 0x10;
  }
  auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
  auVar7 = *(vec16 *)
            (((uint)param_2 & 0xf) * 0x10 + *(int *)PTR_DAT_001e88cc & 0xfffffff0);
  for (puVar2 = param_2; puVar2 < param_2 + 0x38; puVar2 = puVar2 + 8) {
    dataCacheBlockTouch(puVar2);
  }
  for (; param_1 < puVar3 + -0x40; param_1 = param_1 + 0x10) {
    dataCacheBlockTouch(param_2 + 0x38);
    auVar4 = *(vec16 *)((uint)(param_2 + 0xc) & 0xfffffff0);
    auVar9 = *(vec16 *)((uint)(param_2 + 8) & 0xfffffff0);
    auVar8 = vectorPermute(auVar6,*(vec16 *)((uint)(param_2 + 4) & 0xfffffff0),auVar7);
    dataCacheBlockTouch(param_2 + 0x40);
    auVar6 = *(vec16 *)((uint)(param_2 + 0x10) & 0xfffffff0);
    auVar5 = vectorPermute(*(vec16 *)((uint)(param_2 + 4) & 0xfffffff0),auVar9,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar8;
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar5;
    auVar5 = vectorPermute(auVar9,auVar4,auVar7);
    auVar4 = vectorPermute(auVar4,auVar6,auVar7);
    dataCacheBlockAllocate(param_1 + 8);
    *(vec16 *)((uint)(param_1 + 8) & 0xfffffff0) = auVar5;
    *(vec16 *)((uint)(param_1 + 0xc) & 0xfffffff0) = auVar4;
    param_2 = param_2 + 0x10;
  }
  for (; param_1 < puVar3 + -0x10; param_1 = param_1 + 0x10) {
    puVar2 = param_2 + 4;
    auVar9 = *(vec16 *)((uint)(param_2 + 8) & 0xfffffff0);
    auVar5 = *(vec16 *)((uint)(param_2 + 0xc) & 0xfffffff0);
    param_2 = param_2 + 0x10;
    auVar8 = vectorPermute(auVar6,*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar7);
    auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
    auVar4 = vectorPermute(*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar9,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar8;
    auVar8 = vectorPermute(auVar9,auVar5,auVar7);
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar4;
    auVar4 = vectorPermute(auVar5,auVar6,auVar7);
    dataCacheBlockAllocate(param_1 + 8);
    *(vec16 *)((uint)(param_1 + 8) & 0xfffffff0) = auVar8;
    *(vec16 *)((uint)(param_1 + 0xc) & 0xfffffff0) = auVar4;
  }
  if (param_1 + 8 < puVar3) {
    auVar4 = *(vec16 *)((uint)(param_2 + 4) & 0xfffffff0);
    auVar6 = vectorPermute(auVar6,auVar4,auVar7);
    dataCacheBlockAllocate(param_1);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar6;
    param_2 = param_2 + 8;
    auVar6 = *(vec16 *)((uint)param_2 & 0xfffffff0);
    auVar4 = vectorPermute(auVar4,auVar6,auVar7);
    *(vec16 *)((uint)(param_1 + 4) & 0xfffffff0) = auVar4;
    param_1 = param_1 + 8;
  }
  if (param_1 + 4 < puVar3) {
    puVar2 = param_2 + 4;
    param_2 = param_2 + 4;
    auVar6 = vectorPermute(auVar6,*(vec16 *)((uint)puVar2 & 0xfffffff0),auVar7);
    *(vec16 *)((uint)param_1 & 0xfffffff0) = auVar6;
    param_1 = param_1 + 4;
  }
  else if (puVar3 <= param_1) goto LAB_0001eabc;
  do {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1 << 0x10 | uVar1 >> 0x10;
    param_1 = param_1 + 1;
  } while (param_1 < puVar3);
LAB_0001eabc:
  if ((param_3 & 1) != 0) {
    *param_1 = (uint)*(ushort *)param_2;
  }
  return;
}

/* FUN_0001eae0 @ 0x1eae0 (16 bytes) */
int FUN_0001eae0(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  vec16 auVar8;
  vec16 auVar9;
  vec16 auVar10;
  vec16 auVar11;
  vec16 auVar12;
  vec16 auVar13;
  
  puVar7 = (uint *)(param_1 + (param_3 & 0x7ffffffe) * 2);
  for (uVar5 = param_1 + 0x7f & 0xffffff80; uVar5 < ((uint)puVar7 & 0xffffff80);
      uVar5 = uVar5 + 0x80) {
    dataCacheBlockClearToZero(uVar5);
  }
  uVar5 = param_1 & 0xf;
  puVar4 = (uint *)(param_1 - uVar5);
  puVar6 = (uint *)(param_2 - uVar5);
  auVar11 = *(vec16 *)
             (*(int *)PTR_DAT_001e88cc + ((int)puVar6 * 0x10 & 0xf0U) & 0xfffffff0);
  auVar9 = *(vec16 *)(param_2 & 0xfffffff0);
  if (uVar5 != 0) {
    auVar9 = *(vec16 *)((uint)(puVar6 + 4) & 0xfffffff0);
    puVar6 = puVar6 + 4;
    auVar8 = vectorPermute(*(vec16 *)(param_2 & 0xfffffff0),auVar9,auVar11);
    auVar8 = vectorConditionalSelect
                       (*(vec16 *)((uint)puVar4 & 0xfffffff0),auVar8,
                        *(vec16 *)
                         (*(int *)PTR_DAT_001e88cc + uVar5 * 0x10 + 0x100 & 0xfffffff0));
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar8;
    puVar4 = puVar4 + 4;
  }
  for (; puVar4 < puVar7 + -0x10; puVar4 = puVar4 + 0x10) {
    puVar1 = puVar6 + 4;
    puVar2 = puVar6 + 8;
    puVar3 = puVar6 + 0xc;
    puVar6 = puVar6 + 0x10;
    auVar13 = vectorPermute(auVar9,*(vec16 *)((uint)puVar1 & 0xfffffff0),auVar11);
    auVar9 = *(vec16 *)((uint)puVar6 & 0xfffffff0);
    auVar12 = vectorPermute(*(vec16 *)((uint)puVar1 & 0xfffffff0),
                            *(vec16 *)((uint)puVar2 & 0xfffffff0),auVar11);
    auVar10 = vectorPermute(*(vec16 *)((uint)puVar2 & 0xfffffff0),
                            *(vec16 *)((uint)puVar3 & 0xfffffff0),auVar11);
    auVar8 = vectorPermute(*(vec16 *)((uint)puVar3 & 0xfffffff0),auVar9,auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar13;
    *(vec16 *)((uint)(puVar4 + 4) & 0xfffffff0) = auVar12;
    *(vec16 *)((uint)(puVar4 + 8) & 0xfffffff0) = auVar10;
    *(vec16 *)((uint)(puVar4 + 0xc) & 0xfffffff0) = auVar8;
  }
  if (puVar4 + 8 < puVar7) {
    auVar8 = *(vec16 *)((uint)(puVar6 + 4) & 0xfffffff0);
    puVar6 = puVar6 + 8;
    auVar9 = vectorPermute(auVar9,auVar8,auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar9;
    auVar9 = *(vec16 *)((uint)puVar6 & 0xfffffff0);
    auVar8 = vectorPermute(auVar8,auVar9,auVar11);
    *(vec16 *)((uint)(puVar4 + 4) & 0xfffffff0) = auVar8;
    puVar4 = puVar4 + 8;
  }
  if (puVar4 + 4 < puVar7) {
    puVar1 = puVar6 + 4;
    puVar6 = puVar6 + 4;
    auVar9 = vectorPermute(auVar9,*(vec16 *)((uint)puVar1 & 0xfffffff0),auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar9;
    puVar4 = puVar4 + 4;
  }
  else if (puVar7 <= puVar4) goto LAB_0001ecac;
  do {
    uVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar4 = uVar5 << 0x10 | uVar5 >> 0x10;
    puVar4 = puVar4 + 1;
  } while (puVar4 < puVar7);
LAB_0001ecac:
  if ((param_3 & 1) != 0) {
    *puVar4 = (uint)*(ushort *)puVar6;
  }
  return;
}

/* FUN_0001eaf0 @ 0x1eaf0 (468 bytes) */
int FUN_0001eaf0(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  vec16 auVar8;
  vec16 auVar9;
  vec16 auVar10;
  vec16 auVar11;
  vec16 auVar12;
  vec16 auVar13;
  
  puVar7 = (uint *)(param_1 + (param_3 & 0x7ffffffe) * 2);
  for (uVar5 = param_1 + 0x7f & 0xffffff80; uVar5 < ((uint)puVar7 & 0xffffff80);
      uVar5 = uVar5 + 0x80) {
    dataCacheBlockClearToZero(uVar5);
  }
  uVar5 = param_1 & 0xf;
  puVar4 = (uint *)(param_1 - uVar5);
  puVar6 = (uint *)(param_2 - uVar5);
  auVar11 = *(vec16 *)
             (*(int *)PTR_DAT_001e88cc + ((int)puVar6 * 0x10 & 0xf0U) & 0xfffffff0);
  auVar9 = *(vec16 *)(param_2 & 0xfffffff0);
  if (uVar5 != 0) {
    auVar9 = *(vec16 *)((uint)(puVar6 + 4) & 0xfffffff0);
    puVar6 = puVar6 + 4;
    auVar8 = vectorPermute(*(vec16 *)(param_2 & 0xfffffff0),auVar9,auVar11);
    auVar8 = vectorConditionalSelect
                       (*(vec16 *)((uint)puVar4 & 0xfffffff0),auVar8,
                        *(vec16 *)
                         (*(int *)PTR_DAT_001e88cc + uVar5 * 0x10 + 0x100 & 0xfffffff0));
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar8;
    puVar4 = puVar4 + 4;
  }
  for (; puVar4 < puVar7 + -0x10; puVar4 = puVar4 + 0x10) {
    puVar1 = puVar6 + 4;
    puVar2 = puVar6 + 8;
    puVar3 = puVar6 + 0xc;
    puVar6 = puVar6 + 0x10;
    auVar13 = vectorPermute(auVar9,*(vec16 *)((uint)puVar1 & 0xfffffff0),auVar11);
    auVar9 = *(vec16 *)((uint)puVar6 & 0xfffffff0);
    auVar12 = vectorPermute(*(vec16 *)((uint)puVar1 & 0xfffffff0),
                            *(vec16 *)((uint)puVar2 & 0xfffffff0),auVar11);
    auVar10 = vectorPermute(*(vec16 *)((uint)puVar2 & 0xfffffff0),
                            *(vec16 *)((uint)puVar3 & 0xfffffff0),auVar11);
    auVar8 = vectorPermute(*(vec16 *)((uint)puVar3 & 0xfffffff0),auVar9,auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar13;
    *(vec16 *)((uint)(puVar4 + 4) & 0xfffffff0) = auVar12;
    *(vec16 *)((uint)(puVar4 + 8) & 0xfffffff0) = auVar10;
    *(vec16 *)((uint)(puVar4 + 0xc) & 0xfffffff0) = auVar8;
  }
  if (puVar4 + 8 < puVar7) {
    auVar8 = *(vec16 *)((uint)(puVar6 + 4) & 0xfffffff0);
    puVar6 = puVar6 + 8;
    auVar9 = vectorPermute(auVar9,auVar8,auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar9;
    auVar9 = *(vec16 *)((uint)puVar6 & 0xfffffff0);
    auVar8 = vectorPermute(auVar8,auVar9,auVar11);
    *(vec16 *)((uint)(puVar4 + 4) & 0xfffffff0) = auVar8;
    puVar4 = puVar4 + 8;
  }
  if (puVar4 + 4 < puVar7) {
    puVar1 = puVar6 + 4;
    puVar6 = puVar6 + 4;
    auVar9 = vectorPermute(auVar9,*(vec16 *)((uint)puVar1 & 0xfffffff0),auVar11);
    *(vec16 *)((uint)puVar4 & 0xfffffff0) = auVar9;
    puVar4 = puVar4 + 4;
  }
  else if (puVar7 <= puVar4) goto LAB_0001ecac;
  do {
    uVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar4 = uVar5 << 0x10 | uVar5 >> 0x10;
    puVar4 = puVar4 + 1;
  } while (puVar4 < puVar7);
LAB_0001ecac:
  if ((param_3 & 1) != 0) {
    *puVar4 = (uint)*(ushort *)puVar6;
  }
  return;
}

/* FUN_0001ecd0 @ 0x1ecd0 (696 bytes) */
int FUN_0001ecd0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined *param_6;
  uint param_7;
  int param_8;
{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar14;
  undefined4 *puVar10;
  undefined *puVar11;
  int iVar12;
  uint uVar13;
  uint *puVar15;
  uint *puVar16;
  undefined4 uVar17;
  void *pvVar18;
  undefined *puVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  byte *pbVar25;
  int iVar26;
  code *pcVar27;
  int *piVar28;
  uint uVar29;
  undefined4 *puVar30;
  int iVar31;
  undefined *puVar32;
  uint *puVar33;
  int iVar34;
  char in_RESERVE;
  uint uVar35;
  int iVar36;
  double in_f1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  uint uStack00000030;
  double in_stack_ffffff68;
  int iStack_60;
  
  iVar34 = param_1 + 0x240;
  piVar28 = *(int **)(param_1 + 0x1d4);
  if ((piVar28 == (int *)0x0) || (*(char *)(param_1 + 0x2724) == '\0')) goto LAB_0001f7f0;
  iVar31 = *piVar28;
  uVar8 = *(uint *)(((unsigned char *)0x000027c8) + param_1) & 0x1f;
  uVar6 = (uint)(*(int *)(iVar31 + 0x308) != 0 || *(int *)(iVar31 + 0x30c) != 0);
  if ((*(uint *)(iVar31 + 0x304) & 0x400000) == 0) {
    if (((*(int *)(((unsigned char *)0x00003170) + *(int *)(param_1 + 0x10)) == 0x1b011b01) &&
        (*(char *)(param_8 + 0x7c) == '\0')) && (param_3 - 4U < 6)) {
      return 1;
    }
  }
  else if (((*(short *)(((unsigned char *)0x00003170) + *(int *)(param_1 + 0x10)) == 0x1b02) ||
           (*(short *)(((unsigned char *)0x00003172) + *(int *)(param_1 + 0x10)) == 0x1b02)) && (param_3 - 4U < 6))
  goto LAB_0001f7f0;
  iVar26 = *piVar28;
  iVar20 = *(int *)(piVar28[1] + 0x80);
  puVar19 = param_6;
  if (param_5 < 0x20) {
LAB_0001ef10:
    iVar26 = 0;
LAB_0001ef14:
    if (param_6 == ((unsigned char *)0x000014ff)) {
LAB_0001ef40:
      puVar32 = (undefined *)0xffff;
    }
    else {
      puVar32 = (undefined *)0x7ffa;
      if (param_6 == ((unsigned char *)0x00001405)) goto LAB_0001ef30;
    }
  }
  else {
    puVar19 = (undefined *)(*(uint *)(iVar26 + 0x308) | *(uint *)(iVar26 + 0x30c));
    if (((puVar19 != (undefined *)0x0) && (iVar20 != 0)) &&
       ((*(int **)(iVar20 + 8) != (int *)0x0 && (**(int **)(iVar20 + 8) != 0)))) {
      if (param_6 == ((unsigned char *)0x00001403)) {
        if ((*(int *)(iVar20 + 0x10) != 7) || (iVar26 = 1, *(char *)(iVar20 + 0xc) != '\0'))
        goto LAB_0001ee2c;
      }
      else if (param_6 == ((unsigned char *)0x00001405)) {
        iVar26 = 1;
        *(undefined1 *)(iVar20 + 0xc) = 1;
      }
      else {
LAB_0001ee2c:
        iVar26 = 0;
      }
      if ((param_7 & 1) != 0) goto LAB_0001ef10;
      if (iVar26 == 0) goto LAB_0001ef14;
      goto LAB_0001ef40;
    }
    puVar19 = (undefined *)(*(uint *)(iVar26 + 0x308) | *(uint *)(iVar26 + 0x30c));
    if ((((puVar19 != (undefined *)0x0) || ((*(uint *)(iVar26 + 0x304) & 0x800000) == 0)) ||
        (param_2 != 2)) || (param_6 != ((unsigned char *)0x00001405))) goto LAB_0001ef10;
    if ((param_7 & 1) == 0) {
      if ((*(uint *)(iVar26 + 0x314) <= *(uint *)(iVar26 + 0xa8)) &&
         (*(uint *)(iVar26 + 0xa8) < *(uint *)(iVar26 + 0x314) + *(int *)(iVar26 + 0x318))) {
        iVar26 = 1;
        puVar32 = (undefined *)0xffff;
        goto LAB_0001ef50;
      }
    }
    iVar26 = 0;
LAB_0001ef30:
    puVar32 = ((unsigned char *)0x00003ffdU);
  }
LAB_0001ef50:
  uStack00000030 = param_7;
  puVar19 = (undefined *)
            ((uint (*)())FUN_0002cc30)(param_1,1,param_3,param_5,param_5,puVar19,in_f1,in_f2,in_f3,in_f4,in_f5,
                         in_f6,in_f7,in_f8,in_stack_ffffff68);
  bVar2 = 0 < (int)puVar19;
  bVar3 = puVar19 != (undefined *)0x0;
  bVar14 = bVar3;
  switch(param_3) {
  case 1:
  case 8:
    puVar32 = (undefined *)((uint)puVar32 & 0xfffffffe);
  case 0:
LAB_0001f000:
    bVar14 = bVar3;
    break;
  default:
    bVar14 = false;
    if (puVar19 <= puVar32) goto LAB_0001f000;
    break;
  case 4:
    puVar32 = (undefined *)(((uint)puVar32 / 3) * 3);
    break;
  case 7:
    puVar32 = (undefined *)((uint)puVar32 & 0xfffffffc);
  }
  if (puVar19 < puVar32) {
    puVar32 = puVar19;
  }
  if (bVar14) {
    bVar3 = param_6 == ((unsigned char *)0x000014ff);
    if (((bVar3) || (*(int *)(param_1 + 0x2720) != 0)) || (iVar26 != 0)) {
      bVar14 = true;
      bVar9 = true;
    }
    else if (*(int *)(param_1 + 0x26d4) == param_1 + 0x2768) {
      bVar14 = false;
      bVar9 = false;
    }
    else {
      bVar14 = true;
      bVar9 = false;
    }
    uVar21 = -(uint)*(byte *)(param_1 + 0x2a42) >> 0x1e & 2;
    if (*(int *)(param_1 + 0x2680) != param_1 + 0x2630) {
      uVar21 = uVar21 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    if (bVar14) {
      piVar28 = *(int **)(param_1 + 0x1d4);
      iVar20 = uVar21 + 0x14;
      if (*(int *)(*piVar28 + 0x308) != 0 || *(int *)(*piVar28 + 0x30c) != 0) {
        iVar20 = uVar8 + uVar21 + 0x13;
      }
      if (iVar26 != 0) {
        iVar20 = iVar20 + 1;
      }
      uVar21 = iVar20 + (uVar8 + 1 >> 1) * 3 + 3;
      if (*(int *)(param_1 + 0x2720) != 0) {
        uVar21 = uVar21 + *(int *)(param_1 + 0x2720) + 1;
      }
    }
    else {
      piVar28 = *(int **)(param_1 + 0x1d4);
    }
    iStack_60 = 0;
    puVar10 = *(undefined4 **)(piVar28[1] + 0x80);
    if (uVar6 == 0) {
      iStack_60 = *(int *)(iVar31 + 0x314);
    }
    uVar7 = uVar8 + 1 >> 1;
    piVar28 = (int *)0x0;
    puVar30 = (undefined4 *)0x0;
    iVar31 = 0;
    while (bVar2) {
      iVar20 = param_4 + iVar31 * (int)puVar32;
      if (puVar19 < puVar32) {
        puVar32 = puVar19;
      }
      bVar2 = param_6 == ((unsigned char *)0x00001403);
      if (bVar2) {
code_r0x0001f1c0:
        if (iVar26 == 0) {
          puVar11 = (undefined *)(((uint)(puVar32 + 1) >> 1) + 4);
        }
        else {
code_r0x0001f1f0:
          puVar11 = (undefined *)0x8;
        }
      }
      else if (((unsigned char *)0x00001403) < param_6) {
        if (param_6 == ((unsigned char *)0x00001405)) {
          puVar11 = puVar32 + 4;
          if (iVar26 != 0) goto code_r0x0001f1f0;
        }
        else {
          if (!bVar3) goto code_r0x0001f1ac;
          puVar11 = (undefined *)0x4;
        }
      }
      else {
        if (param_6 == ((unsigned char *)0x00001401)) goto code_r0x0001f1c0;
code_r0x0001f1ac:
        puVar11 = (undefined *)0x0;
      }
      puVar15 = (uint *)(**(code **)(param_1 + 0x2998))(iVar34,puVar11 + uVar21 + 2);
      *(uint **)(param_1 + 0x298c) = puVar15;
      puVar16 = puVar15;
      if (*(char *)(param_1 + 0x2a42) != '\0') {
        puVar16 = puVar15 + 2;
        *puVar15 = 0x5c8;
        puVar15[1] = 0x10000000;
        *(undefined1 *)(param_1 + 0x2a42) = 0;
      }
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2630) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x2630;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2650;
        puVar16 = (uint *)FUN_0002c0c0(param_1,puVar16);
      }
      if (bVar14) {
        uVar17 = *(undefined4 *)(((unsigned char *)0x000027c8) + param_1);
        puVar30 = (undefined4 *)((uint)(puVar16 + 0xb) & 0xffffffe0);
        *(int *)(param_1 + 0x26d4) = param_1 + 0x2768;
        *(int *)(param_1 + 0x26d8) = param_1 + 0x2788;
        *(undefined4 *)(param_1 + 0x26d0) = uVar17;
        *puVar16 = (((int)puVar30 - (int)puVar16) + -8) * 0x4000 | 0xc0001000;
        puVar30[-1] = (int)puVar30 - (int)puVar16;
        puVar16 = *(uint **)(param_1 + 0x1d8);
        *puVar16 = *puVar16 | (int)puVar30 - (int)puVar16 >> 2;
        *(undefined4 **)(param_1 + 0x1d8) = puVar30;
        *puVar30 = 0x39000000;
        puVar30[1] = uVar8;
        puVar30[2] = uVar6;
        puVar30[3] = iVar26;
        if (bVar2) {
          uVar17 = 2;
        }
        else {
          uVar17 = 4;
        }
        puVar30[4] = uVar17;
        puVar16 = puVar30 + 8;
        iVar12 = **(int **)(param_1 + 0x1d4);
        if (*(int *)(iVar12 + 0x308) == 0 && *(int *)(iVar12 + 0x30c) == 0) {
          puVar16 = puVar30 + 9;
          puVar30[8] = *(undefined4 *)(*(int **)(param_1 + 0x1d4))[0x8a];
          piVar28 = (int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x228) + 0x10);
          if (in_RESERVE != '\0') {
            iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
            *piVar28 = iVar12;
          }
          if (iVar26 != 0) {
            puVar16 = puVar30 + 10;
            puVar30[9] = **(undefined4 **)(*(int *)(param_1 + 0x1d4) + 0x228);
            piVar28 = (int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 0x228) + 0x10);
            if (in_RESERVE != '\0') {
              iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
              *piVar28 = iVar12;
            }
          }
        }
        else {
          bVar14 = false;
          if (uVar8 != 0) {
            pcVar27 = 0x00002728 + param_1;
            uVar35 = uVar8;
            if (uVar8 == 0) {
              uVar35 = 1;
            }
            do {
              puVar15 = *(uint **)pcVar27;
              pcVar27 = pcVar27 + 4;
              puVar33 = puVar15 + 4;
              *puVar16 = *puVar15;
              puVar16 = puVar16 + 1;
              do {
                if (in_RESERVE != '\0') {
                  uVar24 = storeWordConditionalIndexed(*puVar33 + 0x10000,0,puVar33);
                  *puVar33 = uVar24;
                  bVar14 = true;
                }
              } while (!bVar14);
              uVar35 = uVar35 - 1;
            } while (uVar35 != 0);
          }
          if (iVar26 != 0) {
            *puVar16 = *(uint *)**(undefined4 **)
                                  (*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 4) + 0x80) + 8);
            puVar16 = puVar16 + 1;
            piVar28 = (int *)(**(int **)(*(int *)(*(int *)(*(int *)(param_1 + 0x1d4) + 4) + 0x80) +
                                        8) + 0x10);
            do {
              if (in_RESERVE != '\0') {
                iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
                *piVar28 = iVar12;
                bVar14 = true;
              }
            } while (!bVar14);
          }
        }
        puVar30[5] = ((int)puVar16 - (int)puVar30 >> 2) + 2;
        if (bVar3) {
          puVar15 = puVar16 + 1;
          *puVar16 = (uVar7 * 3 + -1) * 0x10000 | 0x831;
          if (uVar7 != 0) {
            piVar28 = (int *)(param_1 + 0x278c);
            iVar12 = iVar34;
            uVar35 = uVar7;
            do {
              *puVar15 = *(uint *)(iVar12 + 0x2528);
              if (piVar28[-1] == -1) {
                puVar15[1] = 0xffffffff;
              }
              else {
                puVar15[1] = piVar28[-1] + param_4 * (*(uint *)(iVar12 + 0x2528) >> 8 & 0x7f) * 4;
              }
              if (*piVar28 == -1) {
                puVar15[2] = 0xffffffff;
              }
              else {
                puVar15[2] = *piVar28 + param_4 * (*(byte *)(iVar12 + 0x2528) & 0x7f) * 4;
              }
              puVar15 = puVar15 + 3;
              iVar12 = iVar12 + 4;
              piVar28 = piVar28 + 2;
              uVar35 = uVar35 - 1;
            } while (uVar35 != 0);
          }
          puVar16 = puVar15 + 2;
          *puVar15 = 0x830;
          puVar15[1] = *(uint *)(((unsigned char *)0x000027c8) + param_1);
          *(undefined4 *)(param_1 + 0x26d4) = 0;
        }
        else {
          puVar16 = (uint *)FUN_0002c180(param_1,puVar16);
        }
        piVar28 = puVar30 + 7;
        puVar30[6] = (int)puVar16 + (4 - (int)puVar30) >> 2;
        uVar35 = *(uint *)(param_1 + 0x271c);
        bVar4 = uVar35 == 0;
        bVar14 = bVar9;
        if (!bVar4) {
          puVar15 = puVar16 + 1;
          *puVar16 = (*(int *)(param_1 + 0x2720) + -1) * 0x10000 | 0xc0001000;
          if (*(int *)(*(int *)(param_1 + 0x14) + 0x11c) == 0) {
            iVar12 = *(int *)(param_1 + 0x1cc);
            if (iVar12 == 0) {
              if ((uVar35 & 2) != 0) {
                puVar16[1] = *(uint *)(param_8 + 0x40);
                puVar16[2] = *(uint *)(param_8 + 0x44);
                puVar15 = puVar16 + 5;
                uVar24 = *(uint *)(param_8 + 0x48);
                puVar16[4] = 0x3f800000;
                puVar16[3] = uVar24;
              }
              if ((uVar35 & 4) != 0) {
                *puVar15 = *(uint *)(param_8 + 0x30);
                puVar15[1] = *(uint *)(param_8 + 0x34);
                puVar15[2] = *(uint *)(param_8 + 0x38);
                puVar15[3] = *(uint *)(param_8 + 0x3c);
                puVar15 = puVar15 + 4;
              }
              if ((uVar35 & 8) != 0) {
                *puVar15 = *(uint *)(param_8 + 0x50);
                puVar15[1] = *(uint *)(param_8 + 0x54);
                uVar24 = *(uint *)(param_8 + 0x58);
                puVar15[3] = 0x3f800000;
                puVar15[2] = uVar24;
                puVar15 = puVar15 + 4;
              }
              uVar24 = 0;
              iVar36 = 8;
              iVar12 = param_8;
              do {
                if ((uVar35 & 0x400 << (uVar24 & 0x3f)) != 0) {
                  *puVar15 = *(uint *)(iVar12 + 0x80);
                  puVar15[1] = *(uint *)(iVar12 + 0x84);
                  puVar15[2] = *(uint *)(iVar12 + 0x88);
                  puVar15[3] = *(uint *)(iVar12 + 0x8c);
                  puVar15 = puVar15 + 4;
                }
                uVar24 = uVar24 + 1;
                iVar12 = iVar12 + 0x10;
                iVar36 = iVar36 + -1;
              } while (iVar36 != 0);
              if ((uVar35 & 0x40000) != 0) {
                uVar24 = *(uint *)(param_8 + 0x5c);
                puVar15[3] = 0x3f800000;
                puVar15[1] = 0x3f800000;
                puVar15[2] = 0x3f800000;
                *puVar15 = uVar24;
                puVar15 = puVar15 + 4;
              }
              puVar16 = puVar15;
              if ((uVar35 & 0x80000) != 0) {
                *puVar15 = *(uint *)(param_8 + 0x60);
                puVar15[1] = *(uint *)(param_8 + 100);
                puVar15[2] = *(uint *)(param_8 + 0x68);
                puVar15[3] = *(uint *)(param_8 + 0x6c);
                puVar16 = puVar15 + 4;
              }
              goto code_r0x0001f7c0;
            }
          }
          else {
            iVar12 = *(int *)(param_1 + 0x1cc);
          }
          iVar22 = *(int *)(*(int *)(param_1 + 0x14) + 0x11c);
          iVar36 = 0x16;
          puVar16 = puVar15;
          if ((iVar12 == 0) || (iVar36 = *(int *)(*(int *)(param_1 + 0x29e8) + 0x28), iVar36 != 0))
          {
            uVar24 = 0;
            puVar15 = (uint *)(param_1 + 0x27dc);
            do {
              uVar13 = 1 << (uVar24 & 0x3f);
              if ((uVar35 & uVar13) != 0) {
                uVar23 = uVar24;
                if (iVar22 != 0) {
                  uVar23 = *puVar15;
                }
                uVar35 = uVar35 & ~uVar13;
                iVar12 = param_8 + uVar23 * 0x10;
                bVar4 = uVar35 == 0;
                *puVar16 = *(uint *)(param_8 + uVar23 * 0x10);
                puVar16[1] = *(uint *)(iVar12 + 4);
                puVar16[2] = *(uint *)(iVar12 + 8);
                puVar16[3] = *(uint *)(iVar12 + 0xc);
                puVar16 = puVar16 + 4;
              }
              if (bVar4) break;
              uVar24 = uVar24 + 1;
              puVar15 = puVar15 + 1;
              iVar36 = iVar36 + -1;
            } while (iVar36 != 0);
          }
        }
      }
code_r0x0001f7c0:
      dataCacheBlockTouch(0x1d91c8);
      if (bVar2) {
        puVar15 = (uint *)(iVar20 * 2 + uStack00000030);
        dataCacheBlockTouch(puVar15);
        dataCacheBlockTouch((int)puVar15 + (uint)*(byte *)(param_1 + 8));
        uVar35 = (int)puVar32 << 0x10 | *(uint *)(param_3 * 4 + 0x1d91c8) & 0xf | 0x10;
        if (iVar26 == 0) {
          *puVar16 = 0x82c;
          puVar33 = puVar16 + 4;
          uVar24 = *(uint *)(0x00001dc4 + param_1);
          puVar16[2] = ((uint)(puVar32 + 1) >> 1) << 0x10 | 0xc0003600;
          puVar16[3] = uVar35;
          puVar16[1] = uVar24;
          if (puVar32 < (undefined *)0x201) {
            uVar35 = (uint)puVar32 >> 3;
            puVar16 = puVar15;
            if (uVar35 != 0) {
              if (uVar35 == 0) {
                uVar35 = 1;
              }
              do {
                uVar24 = *puVar16;
                uVar13 = puVar16[1];
                uVar23 = puVar16[2];
                uVar29 = puVar16[3];
                puVar16 = puVar16 + 4;
                *puVar33 = uVar24 << 0x10 | uVar24 >> 0x10;
                puVar33[1] = uVar13 << 0x10 | uVar13 >> 0x10;
                puVar33[2] = uVar23 << 0x10 | uVar23 >> 0x10;
                puVar33[3] = uVar29 << 0x10 | uVar29 >> 0x10;
                puVar33 = puVar33 + 4;
                uVar35 = uVar35 - 1;
              } while (uVar35 != 0);
            }
            uVar35 = (uint)puVar32 >> 1 & 3;
            if (uVar35 != 0) {
              if (uVar35 == 0) {
                uVar35 = 1;
              }
              do {
                uVar24 = *puVar16;
                puVar16 = puVar16 + 1;
                *puVar33 = uVar24 << 0x10 | uVar24 >> 0x10;
                puVar33 = puVar33 + 1;
                uVar35 = uVar35 - 1;
              } while (uVar35 != 0);
            }
            if (((uint)puVar32 & 1) != 0) {
              *puVar33 = (uint)*(ushort *)((int)puVar15 + (int)puVar32 * 2 + -2);
              puVar33 = puVar33 + 1;
            }
          }
          else {
            if (*(char *)(param_1 + 8) == -0x80) {
              ((int (*)())FUN_0001eae0)(puVar33,puVar15,puVar32);
            }
            else {
              ((int (*)())FUN_0001e890)(puVar33,puVar15,puVar32);
            }
            puVar33 = puVar33 + ((uint)(puVar32 + 1) >> 1);
          }
        }
        else {
          *puVar16 = 0x82c;
          uVar24 = *(uint *)(0x00001dc4 + param_1);
          puVar16[2] = 0xc0003600;
          puVar16[3] = uVar35;
          puVar16[1] = uVar24;
          *piVar28 = (int)puVar16 + (0x10 - (int)puVar30) >> 2;
          piVar28 = piVar28 + 1;
          puVar16[4] = 0xc0023300;
          puVar16[5] = 0x80000810;
          if (puVar10 == (undefined4 *)0x0) {
            puVar16[6] = (int)puVar15 - iStack_60;
          }
          else {
            puVar16[6] = (int)puVar15 - *(int *)*puVar10;
          }
          puVar33 = puVar16 + 8;
          puVar16[7] = (uint)(puVar32 + 1) >> 1;
        }
      }
      else if (((unsigned char *)0x00001403) < param_6) {
        if (param_6 == ((unsigned char *)0x00001405)) {
          pvVar18 = (void *)(iVar20 * 4 + uStack00000030);
          uVar35 = (int)puVar32 << 0x10 | *(uint *)(param_3 * 4 + 0x1d91c8) & 0xf | 0x810;
          if (iVar26 == 0) {
            *puVar16 = 0x82c;
            puVar33 = puVar16 + 4 + (int)puVar32;
            uVar24 = *(uint *)(0x00001dc4 + param_1);
            puVar16[2] = (int)puVar32 << 0x10 | 0xc0003600;
            puVar16[3] = uVar35;
            puVar16[1] = uVar24;
            _memcpy(puVar16 + 4,pvVar18,(int)puVar32 * 4);
          }
          else {
            *puVar16 = 0x82c;
            uVar24 = *(uint *)(0x00001dc4 + param_1);
            puVar16[2] = 0xc0003600;
            puVar16[3] = uVar35;
            puVar16[1] = uVar24;
            *piVar28 = (int)puVar16 + (0x10 - (int)puVar30) >> 2;
            puVar16[4] = 0xc0023300;
            puVar16[5] = 0x80000810;
            piVar28 = piVar28 + 1;
            if (puVar10 == (undefined4 *)0x0) {
              puVar16[6] = (int)pvVar18 - iStack_60;
            }
            else {
              puVar16[6] = (int)pvVar18 - *(int *)*puVar10;
            }
            puVar33 = puVar16 + 8;
            puVar16[7] = (uint)puVar32;
          }
        }
        else {
          if (!bVar3) goto LAB_0001f7f0;
          puVar33 = puVar16 + 4;
          uVar24 = *(uint *)(param_3 * 4 + 0x1d91c8);
          *puVar16 = 0x82c;
          param_4 = param_4 + (int)puVar32;
          uVar35 = *(uint *)(0x00001dc4 + param_1);
          puVar16[2] = 0xc0003400;
          puVar16[1] = uVar35;
          puVar16[3] = (int)puVar32 << 0x10 | uVar24 & 0xf | 0x820;
        }
      }
      else {
        if (param_6 != ((unsigned char *)0x00001401)) goto LAB_0001f7f0;
        uVar24 = *(uint *)(param_3 * 4 + 0x1d91c8);
        *puVar16 = 0x82c;
        puVar33 = puVar16 + 4;
        uVar35 = *(uint *)(0x00001dc4 + param_1);
        puVar16[2] = (int)(puVar32 + 1) * 0x8000 & 0xffff0000U | 0xc0003600;
        puVar16[1] = uVar35;
        puVar16[3] = (int)puVar32 << 0x10 | uVar24 & 0xf | 0x10;
        if (((uint)puVar32 & 0xfffffffe) != 0) {
          uVar35 = 0;
          pbVar25 = (byte *)(iVar20 + uStack00000030);
          do {
            pbVar1 = pbVar25 + 1;
            uVar35 = uVar35 + 2;
            bVar5 = *pbVar25;
            pbVar25 = pbVar25 + 2;
            *puVar33 = (uint)*pbVar1 << 0x10 | (uint)bVar5;
            puVar33 = puVar33 + 1;
          } while (uVar35 < ((uint)puVar32 & 0xfffffffe));
        }
        if (((uint)puVar32 & 1) != 0) {
          *puVar33 = (uint)((byte *)(iVar20 + uStack00000030))[(int)(puVar32 + -1)];
          puVar33 = puVar33 + 1;
        }
      }
      puVar19 = puVar19 + -(int)puVar32;
      *puVar33 = (uint)((unsigned char *)0x00001393U);
      puVar33[1] = 0;
      puVar33 = puVar33 + 2;
      iVar31 = iVar31 + 1;
      *(uint **)(param_1 + 0x298c) = puVar33;
      (**(code **)(param_1 + 0x299c))(iVar34,puVar33);
      bVar2 = 0 < (int)puVar19;
      if (*(uint **)(param_1 + 0x2994) <= puVar33) {
        pbVar25 = *(byte **)(param_1 + 0x238);
        if (((uint)pbVar25[3] << 0x18 | (uint)pbVar25[2] << 0x10 | (uint)pbVar25[1] << 8 |
            (uint)*pbVar25) == *(uint *)(pbVar25 + 0x20)) {
          ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
          bVar2 = 0 < (int)puVar19;
        }
        else {
          bVar2 = 0 < (int)puVar19;
          *(uint **)(param_1 + 0x2994) = *(uint **)(param_1 + 0x2994) + 0x1000;
        }
      }
    }
    uVar17 = 1;
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    ((unsigned char *)0x000027d0)[param_1 + 5] = 1;
  }
  else {
LAB_0001f7f0:
    uVar17 = 0;
  }
  return uVar17;
}

/* FUN_0001fd00 @ 0x1fd00 (1208 bytes) */
int FUN_0001fd00(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  bool bVar16;
  uint uVar15;
  int *piVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar8 = *(int *)(param_1 + 4);
  piVar13 = *(int **)(iVar8 + 0x1d4);
  if (piVar13 == (int *)0x0) {
    return;
  }
  iVar6 = *piVar13;
  iVar18 = piVar13[1];
  uVar24 = *(uint *)(param_1 + 0x243c);
  bVar1 = *(uint *)(iVar6 + 0x308) == 0;
  bVar2 = *(uint *)(iVar6 + 0x30c) == 0;
  if (*(int *)(iVar8 + 0x1cc) == 0) {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((uVar7 & 0x10000) == 0) goto LAB_0001fdc0;
  }
  else {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((*(uint *)(iVar6 + 0x300) & 1) == 0 && (uVar7 & 0x10000) == 0) {
LAB_0001fdc0:
      bVar16 = true;
      goto LAB_0001fd8c;
    }
  }
  bVar16 = false;
LAB_0001fd8c:
  if (((((*(char *)(iVar8 + 0x20) == '\0') || (0x10 < uVar24)) || (uVar24 < 2)) ||
      ((!bVar1 || !bVar2 &&
       ((*(uint *)(iVar6 + 0x300) & ~*(uint *)(iVar6 + 0x308)) != 0 ||
        (uVar7 & ~*(uint *)(iVar6 + 0x30c)) != 0)))) || (bVar16)) {
switchD_0001ffbc_default:
    *(undefined1 *)(param_1 + 0x24e4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x24dc) = 0;
    *(undefined4 *)(param_1 + 0x24e0) = 0;
    *(undefined1 *)(param_1 + 0x24e4) = 1;
    if (*(int **)(iVar8 + 0x1cc) == (int *)0x0) {
      iVar21 = 0;
      piVar17 = (int *)0x0;
      iVar20 = 0;
      iVar8 = 0;
    }
    else {
      iVar20 = *(int *)(**(int **)(iVar8 + 0x1cc) + 4);
      iVar21 = *(int *)(iVar8 + 0x29e8) + 0x14;
      piVar17 = *(int **)(*(int *)(iVar8 + 0x29e8) + 0x34);
      iVar8 = *(int *)(iVar20 + 0x24);
    }
    puVar19 = (uint *)0x0;
    uVar15 = 0;
    uVar23 = 0;
    uVar7 = 0;
    iVar22 = 0;
    *(uint *)(param_1 + 0x2588) = uVar24 & 0x1f | 0x20;
    iVar25 = 0x16;
    do {
      bVar16 = *(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0;
      if (bVar16) {
        if ((1 << (uVar23 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_0001ff00;
      }
      else if ((*(int *)(iVar22 + *(int *)(iVar21 + 0x20)) != 0x80) ||
              (*(uint *)(iVar21 + 0x1c) <= uVar23)) {
LAB_0001ff00:
        if (iVar20 != 0) {
          if (uVar23 < *(uint *)(iVar21 + 0x1c)) {
            puVar19 = (uint *)(iVar20 + (iVar8 + *(int *)((int)piVar17 + iVar22)) * 8);
          }
          else {
            puVar19 = (uint *)(iVar20 + (iVar8 + *piVar17) * 8);
          }
        }
        if (bVar16) {
          uVar11 = *(uint *)(iVar22 + 0x1d9720);
        }
        else {
          uVar14 = *puVar19;
          uVar11 = *(uint *)(&DAT_001d9778 + (uVar14 >> 0xe & 0x3c));
          if (uVar11 == 8) {
            uVar11 = (uVar14 & 0x1f) + 8;
          }
          else if (uVar11 == 0x10) {
            uVar11 = (uVar14 & 0x1f) + 0x10;
          }
          else if (uVar11 == 0x2f) {
            switch(uVar14 >> 0xc & 0xf) {
            case 0:
              uVar11 = (uVar14 & 1) + 0x20;
              break;
            case 1:
              uVar11 = (uVar14 & 1) + 0x22;
              break;
            case 2:
              uVar11 = (uVar14 & 1) + 0x24;
              break;
            case 3:
              uVar11 = (uVar14 & 1) + 0x26;
              break;
            case 4:
              uVar11 = (uVar14 & 1) + 0x28;
              break;
            default:
              goto switchD_0001ffbc_default;
            }
          }
        }
        if (uVar11 == 0x30) goto switchD_0001ffbc_default;
        if (uVar11 < 0x10) {
          uVar14 = *(uint *)(iVar6 + 0x304);
        }
        else {
          uVar14 = *(uint *)(iVar6 + 0x300);
        }
        if ((uVar14 & *(uint *)(&DAT_001d91f0 + uVar11 * 4)) == 0) {
          *(int *)(param_1 + 0x24e0) = *(int *)(param_1 + 0x24e0) + 4;
          *(uint *)(param_1 + 0x24dc) = 1 << (uVar23 & 0x3f) | *(uint *)(param_1 + 0x24dc);
          if (bVar1 && bVar2) {
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            iVar10 = uVar15 << 2;
          }
          else {
            iVar10 = uVar15 * 4;
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *(undefined4 *)(iVar10 + param_1 + 0x24e4);
          }
        }
        else {
          if (*(char *)((int)piVar13 + uVar11 + 8) == '\0') {
            *(undefined1 *)(param_1 + 0x24e4) = 0;
            return;
          }
          iVar9 = piVar13[uVar11 + 10];
          iVar5 = piVar13[uVar11 + 0x2a];
          uVar14 = piVar13[uVar11 + 0x4a];
          uVar12 = piVar13[uVar11 + 0x6a];
          if (bVar1 && bVar2) {
            iVar10 = uVar15 << 2;
          }
          else {
            iVar10 = uVar15 * 4;
            puVar3 = *(undefined4 **)(*(int *)(iVar18 + uVar11 * 4) + 8);
            if (puVar3 != (undefined4 *)0x0) {
              *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *puVar3;
            }
          }
        }
        if ((uVar15 & 1) == 0) {
          iVar4 = uVar7 * 4 + param_1;
          *(int *)(iVar4 + 0x2528) = iVar9;
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) = uVar12 | *(uint *)(iVar4 + 0x1c04) & 0xf000;
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 | *(uint *)(iVar4 + 0x1be4) & 0x1f00 | *(uint *)(iVar4 + 0x1be4) & 0x2000;
        }
        else {
          iVar4 = uVar7 * 4 + param_1;
          *(uint *)(iVar4 + 0x2528) = iVar9 << 0x10 | *(uint *)(iVar4 + 0x2528);
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) =
               uVar12 << 0x10 | *(uint *)(iVar4 + 0x1c04) & 0xf0000000 | *(uint *)(iVar4 + 0x2410);
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 << 0x10 | *(uint *)(iVar4 + 0x1be4) & 0x1f000000 |
               *(uint *)(iVar4 + 0x1be4) & 0x20000000 | *(uint *)(iVar4 + 0x23f0);
        }
        uVar15 = uVar15 + 1;
        uVar7 = uVar15 >> 1;
      }
      if (uVar15 == uVar24) {
        return;
      }
      uVar23 = uVar23 + 1;
      iVar22 = iVar22 + 4;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  return;
}

/* FUN_00020210 @ 0x20210 (280 bytes) */
int FUN_00020210(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar3 = *(int *)(param_1 + 0x10);
  if (((unsigned char *)0x00003190)[iVar3] == '\0') {
    local_20 = *(int *)(param_1 + 0x15c);
    local_1c = *(int *)(param_1 + 0x160);
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = *(int *)(((unsigned char *)0x00003180) + iVar3);
    if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
      local_24 = *(int *)(((unsigned char *)0x00003184) + iVar3);
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      iVar2 = *(int *)(param_1 + 0x160);
    }
    else {
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      iVar2 = *(int *)(param_1 + 0x160);
      local_24 = iVar2 - (*(int *)(((unsigned char *)0x00003184) + iVar3) + iVar1);
    }
    iVar3 = *(int *)(((unsigned char *)0x00003188) + iVar3);
    if (local_28 < 0) {
      iVar3 = iVar3 + local_28;
      local_28 = 0;
    }
    if (local_24 < 0) {
      iVar1 = iVar1 + local_24;
      local_24 = 0;
    }
    local_20 = *(int *)(param_1 + 0x15c) - local_28;
    if (iVar3 <= local_20) {
      local_20 = iVar3;
    }
    local_1c = iVar2 - local_24;
    if (iVar1 <= iVar2 - local_24) {
      local_1c = iVar1;
    }
    if (local_20 < 1) {
      return;
    }
    if (local_1c < 1) {
      return;
    }
  }
  local_20 = local_28 + local_20;
  local_1c = local_24 + local_1c;
  FUN_0008f7f0(param_1 + 0x240,0,0,&local_28,0);
  return;
}

/* FUN_00020330 @ 0x20330 (216 bytes) */
int FUN_00020330(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar2 = param_2 & *(uint *)(param_1 + 0x158);
  if (((((unsigned char *)0x00002e43)[iVar1] == '\0' && ((unsigned char *)0x00002e40)[iVar1] == '\0') &&
      ((unsigned char *)0x00002e41)[iVar1] == '\0') && ((unsigned char *)0x00002e42)[iVar1] == '\0') {
    uVar2 = uVar2 & 0xffffbfff;
  }
  if (((unsigned char *)0x00002e44)[iVar1] == '\0') {
    uVar2 = uVar2 & 0xfffffeff;
  }
  if ((uVar2 & 0x200) != 0) {
    FUN_000027d0(param_1,iVar1);
  }
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = uVar2 & 0xffffbfff;
    ((int (*)())FUN_00020210)(param_1);
  }
  if ((uVar2 & 0x500) != 0) {
    FUN_000a6cb0(param_1 + 0x240,uVar2);
    return;
  }
  return;
}

/* FUN_00020420 @ 0x20420 (1716 bytes) */
int FUN_00020420(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iStack_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int aiStack_4c [3];
  
  iStack_68 = 0;
  aiStack_4c[0] = 0;
  uStack_64 = 0;
  iStack_60 = 0;
  iStack_5c = 0;
  iStack_58 = 0;
  iStack_54 = 0;
  iStack_50 = 0;
  if (param_5 != 0) {
    iVar12 = param_5;
    iVar1 = _CFStringCreateWithCString(0,"pid",0x600);
    iVar2 = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
    iVar3 = _CFStringCreateWithCString(0,"log_notifications",0x600);
    iVar4 = _CFStringCreateWithCString(0,"fsaa_samples",0x600);
    iVar5 = _CFStringCreateWithCString(0,"fsaa_mode",0x600);
    iVar6 = _CFStringCreateWithCString(0,"aniso_level",0x600);
    iVar7 = _CFStringCreateWithCString(0,"vsync_mode",0x600);
    iVar8 = _CFStringCreateWithCString(0,"performance_level",0x600);
    if (iVar1 != 0) {
      if (((((iVar2 != 0) && (iVar3 != 0)) && (iVar4 != 0)) && ((iVar6 != 0 && (iVar7 != 0)))) &&
         (iVar8 != 0)) {
        iVar9 = _CFDictionaryGetValue(param_5,iVar3);
        if (((iVar9 != 0) && (iVar9 = _CFNumberGetValue(iVar9,3,&iStack_60), iVar9 != 0)) &&
           (iStack_60 != 0)) {
          _puts("\nATI R300 GL Driver Notification Callback");
          FUN_00017ee0(param_2);
        }
        iVar9 = _CFDictionaryGetValue(param_5,iVar1);
        iVar10 = _CFDictionaryGetValue(param_5,iVar2);
        if ((iVar9 == 0) || (iVar10 == 0)) {
          if (iStack_60 != 0) {
            if (iVar9 == 0) {
              _puts("  failed to extract process id from CFDictionary | expected \"pid\"");
            }
            if (iVar10 == 0) {
              _puts(
                   "  failed to extract gl display mask from CFDictionary | expected \"gldisplaymask\""
                   );
            }
          }
        }
        else {
          iVar9 = _CFNumberGetValue(iVar9,3,aiStack_4c);
          if ((iVar9 != 0) && (iVar9 = _CFNumberGetValue(iVar10,3,&uStack_64), iVar9 != 0)) {
            iVar9 = *(int *)(param_2 + 0x2a60);
            if ((iVar9 != aiStack_4c[0]) ||
               (param_7 = uStack_64, (*(uint *)(param_2 + 0x2a64) & uStack_64) == 0)) {
              if (iStack_60 != 0) {
                if (iVar9 != aiStack_4c[0]) {
                  FUN_001a337c("  process id does not match | expected %i | received %i\n",iVar9,
                               aiStack_4c[0],param_4,iVar12,param_6,param_7,param_8);
                }
                if ((*(uint *)(param_2 + 0x2a64) & uStack_64) == 0) {
                  FUN_001a337c("  gl display mask does not match | expected 0x%x | received 0x%x\n",
                               *(uint *)(param_2 + 0x2a64),uStack_64,param_4,iVar12,param_6,param_7,
                               param_8);
                }
              }
            }
            else {
              *(undefined1 *)(param_2 + 0x2a68) = 1;
              uVar13 = uStack_64;
              if (iStack_60 != 0) {
                FUN_001a337c("  process id [%i] and gl display mask [0x%x] match\n",aiStack_4c[0],
                             uStack_64,param_4,iVar12,param_6,uStack_64,param_8);
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar5);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts("  failed to extract fsaa mode from CFDictionary | expected \"fsaa_mode\"");
                }
              }
              else {
                iVar9 = _CFNumberGetValue(iVar9,3,&iStack_58);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a74) = iStack_58, iStack_60 != 0)) {
                  if (iStack_58 == 1) {
                    _puts("  fsaa mode | multisampling");
                  }
                  else if (iStack_58 == 0) {
                    _puts("  fsaa mode | app value");
                  }
                  else if (iStack_58 == 2) {
                    _puts("  fsaa mode | supersampling");
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar4);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract fsaa samples from CFDictionary | expected \"fsaa_samples\""
                       );
                }
              }
              else {
                piVar11 = &iStack_5c;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a70) = iStack_5c, iStack_60 != 0)) {
                  if (iStack_5c == 0) {
                    _puts("  fsaa samples | app value");
                  }
                  else {
                    FUN_001a337c("  fsaa samples | %i\n",iStack_5c,piVar11,param_4,iVar12,param_6,
                                 uVar13,param_8);
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar6);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract anisotropic filtering samples from CFDictionary | expected \"aniso_level\""
                       );
                }
              }
              else {
                piVar11 = &iStack_54;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a7c) = iStack_54, iStack_60 != 0)) {
                  if (iStack_54 == 0) {
                    _puts("  anisotropic filtering samples | app value");
                  }
                  else {
                    FUN_001a337c("  anisotropic filtering samples | %i\n",iStack_54,piVar11,param_4,
                                 iVar12,param_6,uVar13,param_8);
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar7);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract vertical sync mode from CFDictionary | expected \"vsync_mode\""
                       );
                }
              }
              else {
                iVar9 = _CFNumberGetValue(iVar9,3,&iStack_50);
                if ((iVar9 != 0) && (*(char *)(param_2 + 0x2a6c) = (char)iStack_50, iStack_60 != 0))
                {
                  if (iStack_50 == 1) {
                    _puts("  vsync mode | forced off");
                  }
                  else if (iStack_50 == 0) {
                    _puts("  vsync mode | app value");
                  }
                  else if (iStack_50 == 2) {
                    _puts("  vsync mode | forced on");
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar8);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract performance level from CFDictionary | expected \"performance_level\""
                       );
                }
              }
              else {
                piVar11 = &iStack_68;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a78) = iStack_68, iStack_60 != 0)) {
                  if (iStack_68 == 0) {
                    _puts("  performance cheats | off");
                  }
                  else {
                    FUN_001a337c("  performance cheats level | %d\n",iStack_68,piVar11,param_4,
                                 iVar12,param_6,uVar13,param_8);
                  }
                }
              }
            }
          }
        }
      }
      _CFRelease(iVar1);
    }
    if (iVar2 != 0) {
      _CFRelease(iVar2);
    }
    if (iVar3 != 0) {
      _CFRelease(iVar3);
    }
    if (iVar4 != 0) {
      _CFRelease(iVar4);
    }
    if (iVar5 != 0) {
      _CFRelease(iVar5);
    }
    if (iVar6 != 0) {
      _CFRelease(iVar6);
    }
    if (iVar7 != 0) {
      _CFRelease(iVar7);
    }
    if (iVar8 != 0) {
      _CFRelease(iVar8);
    }
  }
  return;
}

/* FUN_00020b00 @ 0x20b00 (40 bytes) */
int FUN_00020b00(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x2a7c) = 0;
  *(undefined4 *)(param_1 + 0x2a70) = 0;
  *(undefined1 *)(param_1 + 0x2a6c) = 0;
  *(undefined1 *)(param_1 + 0x2a6a) = 0;
  *(undefined4 *)(param_1 + 0x2a74) = 0;
  *(undefined4 *)(param_1 + 0x2a78) = 0;
  return;
}

/* FUN_00020b30 @ 0x20b30 (620 bytes) */
int FUN_00020b30(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  int param_6;
  uint param_7;
  undefined4 param_8;
  uint param_9;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = 3;
  if ((*(uint *)(param_1 + 0x154) & 0xf) != 3) {
    iVar8 = 6;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar3 + 0x10) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar3 + 0x10;
  uVar1 = 0;
  *puVar3 = 0xd07;
  iVar4 = *(int *)(param_1 + 0x10);
  if (*(short *)(((unsigned char *)0x00002dba) + iVar4) != 0) {
    if ((*(uint *)(param_1 + 0x154) & 0xf) == 3) {
      uVar6 = 0x7c00;
      if (((unsigned char *)0x00002e40)[iVar4] == '\0') {
        uVar6 = 0;
      }
      uVar7 = 0x3e0;
      if (((unsigned char *)0x00002e41)[iVar4] == '\0') {
        uVar7 = 0;
      }
      uVar1 = 0x1f;
      if (((unsigned char *)0x00002e42)[iVar4] == '\0') {
        uVar1 = 0;
      }
      uVar1 = uVar1 | uVar7 | -(uint)(byte)((unsigned char *)0x00002e43)[iVar4] >> 0x10 & 0x8000 | uVar6;
      uVar1 = uVar1 | uVar1 << 0x10;
    }
    else {
      uVar6 = 0xff000000;
      if (((unsigned char *)0x00002e43)[iVar4] == '\0') {
        uVar6 = 0;
      }
      uVar7 = 0xff0000;
      if (((unsigned char *)0x00002e40)[iVar4] == '\0') {
        uVar7 = 0;
      }
      uVar2 = 0xff00;
      if (((unsigned char *)0x00002e41)[iVar4] == '\0') {
        uVar2 = 0;
      }
      uVar1 = 0xff;
      if (((unsigned char *)0x00002e42)[iVar4] == '\0') {
        uVar1 = 0;
      }
      uVar1 = uVar1 | uVar2 | uVar6 | uVar7;
    }
  }
  puVar3[1] = uVar1;
  puVar3[2] = 0xc0089b00;
  puVar3[3] = iVar8 << 8 | (param_9 & 0xff) << 0x10 | 0x20030ff;
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = (int)(puVar3 + 4) - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar3 + 4;
  puVar3[5] = param_8;
  puVar3[6] = 0;
  puVar3[4] = 0x2a000000;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = param_2 << 0x10 | param_3 & 0xffff;
  puVar3[10] = param_6 << 0x10 | param_7 & 0xffff;
  puVar3[0xb] = param_4 << 0x10 | param_5 & 0xffff;
  puVar3[0xc] = 0xd0b;
  puVar3[0xd] = 5;
  puVar3[0xe] = 0x5c8;
  puVar3[0xf] = 0x10000;
  return;
}

/* FUN_00021c70 @ 0x21c70 (1540 bytes) */
int FUN_00021c70(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  undefined *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  uint uVar6;
  undefined4 *puVar7;
  int a0;
  
  a0 = param_1 + 0x240;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  uVar3 = param_3;
  a3 = param_4;
  a4 = param_5;
  a5 = param_6;
  puVar4 = (undefined4 *)
           (**(code **)(param_1 + 0x2998))(a0,0x406,param_3,param_4,param_5,param_6,param_7,param_8)
  ;
  *(undefined4 **)(param_1 + 0x298c) = puVar4;
  puVar7 = puVar4;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    puVar7 = puVar4 + 2;
    *puVar4 = 0x5c8;
    puVar4[1] = 0x10000000;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  puVar2 = *(uint **)(param_1 + 0x1d8);
  uVar6 = *puVar2;
  *puVar2 = (int)puVar7 - (int)puVar2 >> 2 | uVar6;
  *(undefined4 **)(param_1 + 0x1d8) = puVar7;
  puVar7[2] = param_9;
  puVar7[1] = 0x404;
  *puVar7 = 0x2d000000;
  puVar7[3] = param_2;
  puVar7[4] = param_3;
  puVar7[5] = param_4;
  puVar7[6] = param_5;
  puVar7[7] = param_6;
  puVar7[8] = param_7;
  *(undefined4 **)(param_1 + 0x298c) = puVar7 + 0x404;
  (**(code **)(param_1 + 0x299c))(a0,puVar7 + 0x404,uVar3,a3,a4,a5,uVar6);
  iVar5 = (**(code **)(param_1 + 0x2998))(a0,0xbf);
  *(int *)(param_1 + 0x298c) = iVar5;
  puVar2 = *(uint **)(param_1 + 0x1d8);
  *puVar2 = iVar5 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x298c);
  puVar7 = *(undefined4 **)(param_1 + 0x298c);
  *puVar7 = 0x33000000;
  puVar7[1] = 0;
  *(undefined4 **)(param_1 + 0x298c) = puVar7 + 2;
  puVar7[2] = ((unsigned char *)0x00001393U);
  puVar7[3] = 10;
  puVar7[4] = ((unsigned char *)0x000013c6U);
  puVar7[5] = 3;
  puVar7[6] = 0x5c8;
  puVar7[7] = 0x20000;
  puVar7[8] = (*(unsigned char *)0x000010ea);
  uVar3 = *(undefined4 *)(param_1 + 0x1cfc);
  puVar7[10] = ((unsigned char *)0x000010faU);
  puVar7[9] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1da0);
  puVar7[0xc] = 0xc0001000;
  puVar7[0xe] = 0x11004;
  puVar7[0xb] = uVar3;
  puVar7[0xf] = *(undefined4 *)(param_1 + 0x1ca8);
  uVar3 = *(undefined4 *)(param_1 + 0x1cac);
  puVar7[0x11] = ((unsigned char *)0x00001008U);
  puVar7[0x10] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar7[0x13] = (*(unsigned char *)0x000010e9);
  puVar7[0x12] = uVar3;
  puVar7[0x14] = *(undefined4 *)(param_1 + 0x1d20);
  puVar7[0x15] = ((unsigned char *)0x000013c7U);
  uVar3 = *(undefined4 *)(param_1 + 0x1cf0);
  puVar7[0x17] = ((unsigned char *)0x000013c1U);
  puVar7[0x16] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1ce4);
  puVar7[0x19] = 0x850;
  puVar7[0x18] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1dc0);
  puVar7[0x1b] = 0x887;
  puVar7[0x1a] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1db4);
  puVar7[0xbd] = 0x82c;
  puVar7[0x1c] = uVar3;
  uVar3 = *(undefined4 *)(0x00001dc4 + param_1);
  puVar7[0x1d] = ((unsigned char *)0x000010aeU);
  puVar7[0xbe] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1d70);
  puVar7[0x1f] = ((unsigned char *)0x00001394U);
  puVar7[0x1e] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1d30);
  puVar7[0x21] = ((unsigned char *)0x00001380U);
  puVar7[0x23] = ((unsigned char *)0x00001002U);
  puVar7[0x22] = 0;
  puVar7[0x20] = uVar3;
  puVar7[0x24] = *(undefined4 *)(param_1 + 0x1d90);
  uVar3 = *(undefined4 *)(param_1 + 0x1d90);
  puVar7[0x25] = 0x824;
  puVar7[0x24] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1ddc);
  puVar7[0x27] = 0x825;
  puVar7[0x26] = uVar3;
  puVar7[0x28] = *(undefined4 *)(param_1 + 0x1de0);
  puVar7[0x29] = 0x82d;
  puVar1 = PTR_DAT_001e88c8;
  uVar3 = *(undefined4 *)(0x000026c8 + param_1 + 4);
  puVar7[0x2b] = 0x854;
  puVar7[0x2a] = uVar3;
  uVar3 = **(undefined4 **)(param_1 + 0x2680);
  puVar7[0x2d] = 0x878;
  puVar7[0x2c] = uVar3;
  uVar3 = **(undefined4 **)(param_1 + 0x2684);
  puVar7[0x2f] = ((unsigned char *)0x000013c0U);
  puVar7[0x2e] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1ce0);
  puVar7[0x31] = ((unsigned char *)0x000012f0U);
  puVar7[0x30] = uVar3;
  uVar6 = *(uint *)(param_1 + 0x1d2c);
  puVar7[0x32] = uVar6;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar7[0x32] = uVar6 & 0xfffffffe;
  }
  puVar7[0x33] = ((unsigned char *)0x000012f5U);
  uVar6 = *(uint *)(param_1 + 0x1c8c);
  puVar7[0x34] = uVar6;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar7[0x34] = uVar6 & 0xfffff7ff;
  }
  puVar7[0x35] = ((unsigned char *)0x000010a2U);
  uVar3 = *(undefined4 *)(param_1 + 0x1d7c);
  puVar7[0x37] = ((unsigned char *)0x00001381U);
  puVar7[0x36] = uVar3;
  uVar6 = *(uint *)(param_1 + 0x1cc0);
  puVar7[0x38] = uVar6;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
    puVar7[0x38] = uVar6 & 0xfffffffc;
  }
  puVar7[0x39] = ((unsigned char *)0x0000109eU);
  uVar3 = *(undefined4 *)(param_1 + 0x1d6c);
  puVar7[0x3b] = ((unsigned char *)0x00001096U);
  puVar7[0x3a] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1df8);
  puVar7[0x3d] = ((unsigned char *)0x00001041U);
  puVar7[0x3a] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x29f0);
  puVar7[0x3f] = ((unsigned char *)0x00001046U);
  puVar7[0x3e] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1dfc);
  puVar7[0x41] = ((unsigned char *)0x00001094U);
  puVar7[0x59] = ((unsigned char *)0x00001095U);
  puVar7[0x42] = 0;
  puVar7[0x7f] = ((unsigned char *)0x00001180U);
  puVar7[0x43] = ((unsigned char *)0x00001095U);
  puVar7[0x45] = ((unsigned char *)0x00001095U);
  puVar7[0x47] = ((unsigned char *)0x00001095U);
  puVar7[0x40] = uVar3;
  puVar7[0x49] = ((unsigned char *)0x00001095U);
  puVar7[0x4b] = ((unsigned char *)0x00001095U);
  puVar7[0x4d] = ((unsigned char *)0x00001095U);
  puVar7[0x4f] = ((unsigned char *)0x00001095U);
  puVar7[0x51] = ((unsigned char *)0x00001095U);
  puVar7[0x53] = ((unsigned char *)0x00001095U);
  puVar7[0x55] = ((unsigned char *)0x00001095U);
  puVar7[0x57] = ((unsigned char *)0x00001095U);
  puVar7[0x5b] = 0xc0221000;
  puVar7[0x80] = 2;
  puVar7[0x81] = ((unsigned char *)0x00001189U);
  puVar7[0x83] = ((unsigned char *)0x00001181U);
  puVar7[0x85] = ((unsigned char *)0x0000118dU);
  puVar7[0x87] = ((unsigned char *)0x0000118eU);
  puVar7[0x89] = ((unsigned char *)0x0000118cU);
  puVar7[0x8b] = ((unsigned char *)0x000011a9U);
  uVar3 = *(undefined4 *)(param_1 + 0x257c);
  puVar7[0x8d] = ((unsigned char *)0x000011aaU);
  puVar7[0x8c] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x2580);
  puVar7[0x8f] = ((unsigned char *)0x000011abU);
  puVar7[0x8e] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x2584);
  puVar7[0x91] = ((unsigned char *)0x000011acU);
  puVar7[0x90] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x2588);
  puVar7[0x93] = ((unsigned char *)0x000010c0U);
  puVar7[0x92] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x216c);
  puVar7[0x95] = ((unsigned char *)0x000010c1U);
  puVar7[0x97] = ((unsigned char *)0x000010c8U);
  puVar7[0x99] = ((unsigned char *)0x0000101dU);
  puVar7[0x94] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x2128);
  puVar7[0x9b] = ((unsigned char *)0x0000138aU);
  puVar7[0xa2] = 0;
  puVar7[0x9c] = 0;
  puVar7[0x9f] = ((unsigned char *)0x00001040U);
  puVar7[0x9e] = 0;
  puVar7[0xa0] = 0;
  puVar7[0x9d] = ((unsigned char *)0x0000138eU);
  puVar7[0x9a] = uVar3;
  puVar7[0xa1] = (*(unsigned char *)0x00001150);
  puVar7[0xa3] = ((unsigned char *)0x00001100U);
  uVar3 = *(undefined4 *)(param_1 + 0x1f1c);
  puVar7[0xa5] = ((unsigned char *)0x00001110U);
  puVar7[0xa4] = uVar3;
  puVar7[0xa6] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar7[0xa7] = (*(unsigned char *)0x00001120);
  uVar3 = *(undefined4 *)(param_1 + 0x1f9c);
  puVar7[0xa9] = ((unsigned char *)0x00001130U);
  puVar7[0xa8] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1fdc);
  puVar7[0xab] = ((unsigned char *)0x00001140U);
  puVar7[0xaa] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x201c);
  puVar7[0xad] = ((unsigned char *)0x000010f4U);
  puVar7[0xae] = 0xaaaa;
  puVar7[0xaf] = ((unsigned char *)0x00001383U);
  puVar7[0xac] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1d34);
  puVar7[0xb1] = ((unsigned char *)0x00001386U);
  puVar7[0xb0] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1d38);
  puVar7[0xb3] = 0x110f8;
  puVar7[0xb2] = uVar3;
  puVar7[0xb4] = *(undefined4 *)(param_1 + 0x1d98);
  uVar3 = *(undefined4 *)(param_1 + 0x1d50);
  puVar7[0xb6] = ((unsigned char *)0x00001087U);
  puVar7[0xb5] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1f0c);
  puVar7[0xb8] = 0x31080;
  puVar7[0xb7] = uVar3;
  puVar7[0xb9] = *(undefined4 *)(param_1 + 0x1efc);
  puVar7[0xba] = *(undefined4 *)(param_1 + 0x1f04);
  puVar7[0xbb] = *(undefined4 *)(param_1 + 0x1f00);
  puVar7[0xbc] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004c100(puVar7 + 2,a0);
  *(undefined4 **)(param_1 + 0x298c) = puVar7 + 0xbf;
                    
                    
  (**(code **)(param_1 + 0x299c))(a0);
  return;
}

/* FUN_00022280 @ 0x22280 (4 bytes) */
int FUN_00022280()
{
  return;
}

/* _gldUpdateDispatch @ 0x22290 (2632 bytes) */
uint _gldUpdateDispatch(int param_1,int param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *extraout_r4;
  int *extraout_r4_00;
  int *extraout_r4_01;
  int *extraout_r4_02;
  int *extraout_r4_03;
  int *extraout_r4_04;
  uint *puVar11;
  undefined4 *puVar12;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  char cVar18;
  uint *puVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  uint *puVar25;
  bool bVar27;
  uint uVar26;
  int iVar28;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  
  if (*(char *)(param_1 + 0x2a69) == '\0') {
    if (*(char *)(param_1 + 0x2a44) != '\0') {
      param_3[2] = param_3[2] | 0xfffffffd;
      *param_3 = 0xffffffff;
      param_3[1] = param_3[1] | 0x3ffffff;
      param_3[3] = param_3[3] | 0x7ffffff;
      param_3[4] = 0xffffffff;
      *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
      *(undefined1 *)(param_1 + 0x2a44) = 0;
      *(undefined1 *)(param_1 + 0x2a43) = 1;
      *(undefined1 *)(param_1 + 0x26bd) = 1;
      *(uint *)(0x000026c8 + param_1) = *(uint *)(0x000026c8 + param_1) | 7;
    }
  }
  else {
    param_3[2] = param_3[2] | 0xfffffffd;
    *param_3 = 0xffffffff;
    param_3[1] = param_3[1] | 0x3ffffff;
    param_3[3] = param_3[3] | 0x7ffffff;
    param_3[4] = 0xffffffff;
    *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x2a43) = 1;
    *(undefined1 *)(param_1 + 0x2a44) = 0;
    *(undefined1 *)(param_1 + 0x26bd) = 1;
    *(undefined1 *)(param_1 + 0x2a69) = 0;
    *(uint *)(0x000026c8 + param_1) = *(uint *)(0x000026c8 + param_1) | 7;
  }
  puVar11 = param_3;
  if ((int)*param_3 < 0) {
    fparam_1 = (double)FUN_00007d50(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  piVar10 = *(int **)(param_1 + 0x150);
  if (((piVar10 == (int *)0x0) || (*(ushort *)(*piVar10 + 0x90) == 0)) ||
     (iVar8 = *(int *)((uint)*(ushort *)(*piVar10 + 0x90) * 4 + piVar10[1] + -0x23380), iVar8 == 0))
  {
LAB_00022438:
    uVar17 = 4;
    if ((*param_3 & 0x180) != 0) {
      if (piVar10 != (int *)0x0) {
        ((int (*)())FUN_0001bac0)(param_1,piVar10);
      }
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) ||
         (uVar17 = 0xc, *(int *)(param_1 + 0x150) != 0)) {
        uVar17 = 4;
      }
      fparam_1 = (double)FUN_00017260(param_1);
      piVar10 = extraout_r4;
    }
    puVar19 = param_3 + 1;
    uVar20 = (uint)*(ushort *)((int)param_3 + 6);
    puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x19c);
    if (puVar12 == (undefined4 *)0x0) {
      cVar18 = '\0';
      if ((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] != '\0') &&
         ((psVar13 = (short *)**(undefined4 **)(*(int *)(param_1 + 0x18) + 400),
          *(int *)(psVar13 + 2) == 0 || (cVar18 = '\x01', *psVar13 == -0x7e00)))) goto LAB_00022540;
    }
    else if ((*(int *)((short *)*puVar12 + 2) == 0) || (*(short *)*puVar12 == -0x7e00)) {
LAB_00022540:
      cVar18 = '\0';
    }
    else {
      cVar18 = '\x01';
      if (((puVar12[0xe] != 0) && (uVar9 = *(uint *)(puVar12[0xe] + 0x20), (uVar9 & 0x1000000) != 0)
          ) && ((uVar9 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) {
        param_3[3] = param_3[3] | 0x1000000;
      }
    }
    if ((*(char *)(param_1 + 0x29dc) == cVar18) && (uVar9 = param_3[3], (uVar9 & 0x5000000) == 0)) {
      bVar3 = false;
      if (uVar20 != 0) goto LAB_00022580;
    }
    else {
      *(char *)(param_1 + 0x29dc) = cVar18;
      uVar20 = 0xffff;
      *puVar19 = *puVar19 | 0xffff;
LAB_00022580:
      _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
      piVar10 = *(int **)(*(int *)(param_1 + 0x18) + 0x19c);
      if (piVar10 == (int *)0x0) {
        if (((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] != '\0') &&
            (puVar12 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 400),
            puVar12 != (undefined4 *)0x0)) && (psVar13 = (short *)*puVar12, *psVar13 != -0x7e00)) {
          uVar9 = *(uint *)(psVar13 + 4);
          uVar22 = *(uint *)(psVar13 + 6);
          goto LAB_000225e8;
        }
        uVar22 = 0;
        iVar21 = 0;
        iVar23 = 0;
        iVar8 = param_1;
        uVar9 = uVar20;
        do {
          if ((uVar9 & 1) != 0) {
            uVar14 = 0;
            iVar28 = 5;
            do {
              if ((*(uint *)(((unsigned char *)0x000031d4) + iVar21 + *(int *)(param_1 + 0x10)) &
                  1 << (uVar14 & 0x3f)) != 0) {
                uVar14 = *(uint *)(iVar23 + *(int *)(param_1 + 0x18) + uVar14 * 4);
                if ((*(byte *)(uVar14 + 0x39) & 0x87) == 0) {
                  uVar24 = uVar14 & -(uint)*(byte *)(uVar14 + 0x3d);
                }
                else {
                  iVar28 = FUN_00032100(param_1,uVar14,puVar11,param_4,param_5,param_6);
                  if ((iVar28 == 0) || (uVar24 = uVar14, *(char *)(uVar14 + 0x3d) == '\0')) {
                    uVar24 = 0;
                  }
                }
                uVar15 = *(uint *)(param_1 + 0x26b8) & ~(1 << (uVar22 & 0x3f));
                *(uint *)(param_1 + 0x26b8) = uVar15;
                *(uint *)(param_1 + 0x26b8) =
                     uVar15 | (uint)*(byte *)(uVar14 + 0x44) << (uVar22 & 0x3f);
                goto LAB_00022740;
              }
              uVar14 = uVar14 + 1;
              iVar28 = iVar28 + -1;
            } while (iVar28 != 0);
            uVar24 = 0;
            *(uint *)(param_1 + 0x26b8) = *(uint *)(param_1 + 0x26b8) & ~(1 << (uVar22 & 0x3f));
LAB_00022740:
            *(uint *)(iVar8 + 0x18c) = uVar24;
          }
          uVar9 = uVar9 >> 1;
          uVar22 = uVar22 + 1;
          iVar23 = iVar23 + 0x14;
          iVar21 = iVar21 + 0x7c;
          iVar8 = iVar8 + 4;
        } while (uVar9 != 0);
      }
      else {
        iVar8 = *piVar10;
        uVar9 = *(uint *)(iVar8 + 8);
        uVar22 = *(uint *)(iVar8 + 0xc);
LAB_000225e8:
        uVar24 = 0;
        iVar21 = 0;
        iVar8 = param_1;
        uVar14 = uVar20;
        do {
          if ((uVar14 & 1) != 0) {
            if ((uVar22 & 0xf) < 5) {
              uVar16 = *(uint *)(iVar21 + *(int *)(param_1 + 0x18) + (uVar22 & 0xf) * 4);
              if ((*(byte *)(uVar16 + 0x39) & 0x87) == 0) {
                uVar15 = uVar16 & -(uint)*(byte *)(uVar16 + 0x3d);
              }
              else {
                iVar23 = FUN_00032100(param_1,uVar16,puVar11,param_4,param_5,param_6);
                if ((iVar23 == 0) || (uVar15 = uVar16, *(char *)(uVar16 + 0x3d) == '\0')) {
                  uVar15 = 0;
                }
              }
              uVar26 = *(uint *)(param_1 + 0x26b8) & ~(1 << (uVar24 & 0x3f));
              *(uint *)(param_1 + 0x26b8) = uVar26;
              *(uint *)(param_1 + 0x26b8) =
                   uVar26 | (uint)*(byte *)(uVar16 + 0x44) << (uVar24 & 0x3f);
            }
            else {
              uVar15 = 0;
              *(uint *)(param_1 + 0x26b8) = *(uint *)(param_1 + 0x26b8) & ~(1 << (uVar24 & 0x3f));
            }
            *(uint *)(iVar8 + 0x18c) = uVar15;
          }
          uVar14 = uVar14 >> 1;
          uVar15 = uVar9 << 0x1c;
          uVar9 = uVar9 >> 4;
          uVar24 = uVar24 + 1;
          uVar22 = uVar15 | uVar22 >> 4;
          iVar21 = iVar21 + 0x14;
          iVar8 = iVar8 + 4;
        } while (uVar14 != 0);
      }
      fparam_1 = (double)FUN_000a7ee0(param_1,uVar20);
      uVar20 = *(uint *)(param_1 + 0x26b8);
      if (uVar20 != 0) {
        iVar8 = 0;
        do {
          iVar21 = 0;
          iVar23 = 5;
          do {
            if ((uVar20 & 1) != 0) {
              *(undefined1 *)(*(int *)(iVar8 + iVar21 + *(int *)(param_1 + 0x18)) + 0x44) = 0;
              uVar20 = *(uint *)(param_1 + 0x26b8);
            }
            iVar21 = iVar21 + 4;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
          uVar20 = uVar20 >> 1;
          iVar8 = iVar8 + 0x14;
          *(uint *)(param_1 + 0x26b8) = uVar20;
        } while (uVar20 != 0);
        goto LAB_00022cbc;
      }
      uVar9 = param_3[3];
      bVar3 = true;
      piVar10 = extraout_r4_00;
    }
    puVar25 = param_3 + 3;
    bVar1 = !bVar3;
    if ((uVar9 & 0x5400000) != 0) {
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x198) != 0) ||
         (bVar27 = false, *(int *)(*(int *)(param_1 + 0x18) + 0x18c) != 0)) {
        bVar27 = true;
      }
      bVar1 = bVar3;
      if (!bVar1) {
        _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
      }
      bVar1 = bVar1 && !bVar3;
      fparam_1 = (double)FUN_000095e0(param_1);
      iVar8 = *(int *)(param_1 + 0x1cc);
      if (bVar27 != (iVar8 != 0)) {
        *(undefined1 *)(param_1 + 0x26bd) = 1;
        iVar8 = *(int *)(param_1 + 0x1cc);
      }
      if (iVar8 == 0) {
        *(undefined4 *)(param_1 + 0x29e8) = 0;
      }
      piVar10 = extraout_r4_01;
      if ((*(int *)(param_1 + 0x1d0) == 0) &&
         (*(undefined4 *)(param_1 + 0x29ec) = 0, cVar18 != '\0')) {
        uVar17 = 0;
        *(undefined1 *)(param_1 + 0x2a69) = 1;
        *puVar25 = *puVar25 | 0x10000000;
        *(undefined4 *)(param_1 + 0x29e8) = 0;
        *(undefined4 *)(param_1 + 0x1cc) = 0;
      }
    }
    uVar20 = *puVar25;
    if ((uVar20 & 0x4500000) != 0) {
      if (bVar1) {
        _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
        bVar1 = false;
      }
      fparam_1 = (double)FUN_0000b750(param_1);
      uVar20 = *puVar25;
      piVar10 = extraout_r4_02;
    }
    uVar14 = *puVar19;
    uVar22 = *param_3;
    uVar24 = *(uint *)(param_1 + 0x26c4);
    uVar15 = param_3[4];
    uVar16 = param_3[2] | *(uint *)(param_1 + 0x26c0);
    uVar26 = uVar20 | uVar24;
    uVar9 = uVar14;
    if (((uVar16 != 0 || (uVar22 != 0 || uVar14 != 0)) || uVar15 != 0) || (uVar26 & 0xffefffff) != 0
       ) {
      param_3[2] = uVar16;
      *puVar25 = uVar26;
      ((void (*)())FUN_000a9ac0)(param_1 + 0x240,param_3,puVar11,param_4,uVar20,uVar14,uVar24,uVar15,fparam_1,
                   fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff78,
                   in_stack_ffffff80,in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
      piVar10 = extraout_r4_03;
    }
    if ((uVar26 & 0x10000000) != *(uint *)(param_1 + 0x29c0) ||
        (uVar26 != 0 || ((uVar16 != 0 || (uVar22 != 0 || uVar14 != 0)) || uVar15 != 0))) {
      FUN_0002c230(param_1 + 0x240,param_3);
      piVar10 = extraout_r4_04;
    }
    puVar7 = PTR_FUN_001e8980;
    puVar6 = PTR__gldFlush_001e897c;
    puVar5 = PTR__gldFinish_001e8978;
    puVar4 = PTR_FUN_001e8938;
    if ((*(uint *)(0x000026c8 + param_1) & 2) != 0) {
      uVar17 = uVar17 | 2;
    }
    if ((*param_3 & 0x80) != 0) {
      if (*(int *)(param_1 + 0x150) == 0) {
        uVar22 = *(uint *)(param_1 + 0x154);
        if ((uVar22 & 0x20) == 0) {
          if ((uVar22 & 0x400) == 0) {
            *(code **)(param_2 + 0x60) = FUN_00022280;
          }
          else {
            *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8934;
          }
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar4;
        }
        else if ((uVar22 & 0x400) == 0) {
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8938;
          *(undefined **)(param_2 + 0x58) = puVar7;
          *(undefined **)(param_2 + 0x5c) = puVar4;
        }
        else if ((uVar22 & 0x800) == 0) {
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar6;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8934;
        }
        else if (*(int *)(param_1 + 0x26a0) == 0) {
          ((int (*)())FUN_0001a9d0)(param_1,piVar10,puVar11,param_4,uVar20,uVar9,uVar22 & 0x800);
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar4;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8948;
        }
        else {
          *(undefined **)(param_2 + 0x58) = PTR_FUN_001e8980;
          *(undefined **)(param_2 + 0x5c) = puVar4;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8948;
        }
      }
      else {
        *(code **)(param_2 + 0x60) = FUN_00022280;
        *(undefined **)(param_2 + 0x58) = puVar5;
        *(undefined **)(param_2 + 0x5c) = PTR__gldFlush_001e897c;
      }
    }
    puVar5 = PTR_FUN_001e8910;
    puVar4 = PTR_FUN_001e88ec;
    if ((*(char *)(param_1 + 0x20) == '\0') || (*(int *)(param_1 + 0x1cc) == 0)) {
      *(undefined **)(param_2 + 0x18) = PTR_FUN_001e8944;
      *(undefined **)(param_2 + 0x1c) = puVar5;
      puVar4 = PTR_FUN_001e88d4;
      *(undefined **)(param_2 + 0x24) = PTR_FUN_001e891c;
      *(undefined **)(param_2 + 0x20) = puVar4;
      puVar4 = PTR_FUN_001e88e0;
      *(undefined **)(param_2 + 0x2c) = PTR_FUN_001e8940;
      *(undefined **)(param_2 + 0x34) = puVar4;
      puVar4 = PTR_FUN_001e88e4;
      *(undefined **)(param_2 + 0x30) = PTR_FUN_001e894c;
      *(undefined **)(param_2 + 0x38) = puVar4;
      puVar4 = PTR_FUN_001e8914;
      *(undefined **)(param_2 + 0x3c) = PTR_FUN_001e893c;
      *(undefined **)(param_2 + 0x28) = puVar4;
      puVar4 = PTR_FUN_001e8990;
      if (*(char *)(param_1 + 0x20) == '\0') {
        *(undefined **)(param_2 + 0x40) = PTR_FUN_001e88f8;
        *(undefined **)(param_2 + 0x44) = puVar4;
        *(undefined **)(param_2 + 0x48) = PTR_FUN_001e895c;
      }
      else {
        *(code **)(param_2 + 0x48) = FUN_00022280;
        *(code **)(param_2 + 0x40) = FUN_00022280;
        *(code **)(param_2 + 0x44) = FUN_00022280;
      }
    }
    else {
      *(undefined **)(param_2 + 0x18) = PTR_FUN_001e8918;
      *(undefined **)(param_2 + 0x1c) = puVar4;
      puVar4 = PTR_FUN_001e8954;
      *(undefined **)(param_2 + 0x24) = PTR_FUN_001e8908;
      *(undefined **)(param_2 + 0x28) = puVar4;
      puVar4 = PTR_FUN_001e88f4;
      *(undefined **)(param_2 + 0x20) = PTR_FUN_001e8930;
      *(undefined **)(param_2 + 0x2c) = puVar4;
      puVar4 = PTR_FUN_001e8924;
      *(undefined **)(param_2 + 0x34) = PTR_FUN_001e8960;
      *(undefined **)(param_2 + 0x30) = puVar4;
      puVar4 = PTR_FUN_001e8968;
      *(undefined **)(param_2 + 0x38) = PTR_FUN_001e892c;
      *(undefined **)(param_2 + 0x3c) = puVar4;
    }
    uVar20 = *(uint *)(0x000026c8 + param_1);
    *(uint *)(param_1 + 0x29c0) = uVar26 & 0x10000000;
    ((unsigned char *)0x00002b7d)[param_1] = 0;
    *(undefined1 *)(param_1 + 0x26bd) = 0;
    *(undefined1 *)(param_1 + 0x2a43) = 0;
    *(undefined1 *)(param_1 + 0x2675) = 0;
    *(uint *)(0x000026c8 + param_1) = uVar20 & 0xfffffff9;
    if ((*(int *)(param_1 + 0x150) != 0) &&
       (iVar8 = *(int *)(*(int *)(*(int *)(param_1 + 0x150) + 4) + 0x10), iVar8 != 0)) {
      *(undefined1 *)(iVar8 + 200) = 1;
    }
    if (!bVar1) {
      _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    }
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar17 = uVar17 | 1;
    }
  }
  else {
    bVar2 = *(byte *)(iVar8 + 0x38);
    if (((((unsigned char *)0x00002d84)[*(int *)(param_1 + 0x10)] == '\0') ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x18) & 0x4000) != 0)) &&
       ((((unsigned char *)0x00002e0a)[*(int *)(param_1 + 0x10)] == '\0' ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x18) & 0x8000) != 0))))
    goto LAB_00022438;
LAB_00022cbc:
    uVar17 = 0;
  }
  return uVar17;
}

/* _gldInitDispatch @ 0x22ce0 (456 bytes) */
int _gldInitDispatch(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar7 = 0;
  uVar5 = *(undefined4 *)(param_1 + 0x108);
  uVar4 = *(undefined4 *)(param_1 + 0x104);
  uVar6 = *(undefined4 *)(param_1 + 0x110);
  param_3[2] = *(undefined4 *)(param_1 + 0x10c);
  param_3[1] = uVar5;
  *param_3 = uVar4;
  param_3[3] = uVar6;
  uVar4 = DAT_001aa4c0;
  local_38 = DAT_001aa4b0;
  local_34 = DAT_001aa4b4;
  local_30 = DAT_001aa4b8;
  uVar5 = *(undefined4 *)(param_1 + 0x118);
  local_2c = DAT_001aa4bc;
  local_28 = DAT_001aa4c0;
  param_3[4] = *(undefined4 *)(param_1 + 0x114);
  param_3[5] = uVar5;
  *(undefined4 **)(param_1 + 0x1c) = param_2;
  do {
    fparam_1 = (double)FUN_000a82c0(param_1,iVar7);
    puVar2 = PTR_FUN_001e8950;
    bVar1 = iVar7 != 0xf;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  param_2[5] = PTR_FUN_001e88dc;
  *param_2 = puVar2;
  puVar2 = PTR_FUN_001e898c;
  param_2[4] = PTR_FUN_001e8988;
  param_2[2] = puVar2;
  puVar2 = PTR_FUN_001e8958;
  param_2[3] = PTR_FUN_001e8900;
  param_2[1] = puVar2;
  puVar2 = PTR_FUN_001e890c;
  param_2[0x19] = PTR_FUN_001e8964;
  param_2[0x1d] = puVar2;
  puVar2 = PTR_FUN_001e88f0;
  param_2[0x1e] = PTR_FUN_001e88fc;
  param_2[0x1f] = puVar2;
  puVar3 = PTR_FUN_001e8970;
  puVar2 = PTR_FUN_001e8920;
  if (((unsigned char *)0x00002b82)[param_1] == '\0') {
    param_2[0x14] = PTR_FUN_001e88e8;
    param_2[0x15] = puVar2;
  }
  else {
    param_2[0x14] = PTR_FUN_001e8974;
    param_2[0x15] = puVar3;
  }
  puVar2 = PTR_FUN_001e8928;
  param_2[0x1c] = PTR_FUN_001e8984;
  param_2[0x13] = puVar2;
  puVar2 = PTR_LAB_001e8904;
  param_2[0x1a] = PTR_FUN_001e896c;
  param_2[0x1b] = puVar2;
  param_2[0x20] = PTR_FUN_001e88d8;
  ((uint (*)())_gldUpdateDispatch)(param_1,param_2,&local_38,param_4,param_5,uVar4,fparam_1,in_f2,in_f3,in_f4,
                     in_f5,in_f6,in_f7,in_f8,in_stack_ffffff98,in_stack_ffffffa0,in_stack_ffffffa8,
                     in_stack_ffffffb0,in_stack_ffffffb8);
  return;
}

/* FUN_00022eb0 @ 0x22eb0 (536 bytes) */
int FUN_00022eb0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x240;
  FUN_000a5ec0(iVar4);
  bVar1 = param_2 == (undefined4 *)0x0;
  if (bVar1) {
    param_2 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar4,0x23);
    *(undefined4 **)(param_1 + 0x298c) = param_2;
  }
  uVar2 = *(uint *)(param_1 + 0x1b70);
  if ((uVar2 & 0x100) != 0) {
    *param_2 = ((unsigned char *)0x00001393U);
    param_2[1] = 10;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x2000000) != 0) {
    *param_2 = ((unsigned char *)0x000013c6U);
    param_2[1] = 3;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x200) != 0) {
    *param_2 = ((unsigned char *)0x000012f5U);
    param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x80000) != 0) {
    *param_2 = ((unsigned char *)0x00001008U);
    uVar3 = *(undefined4 *)(param_1 + 0x1ca0);
    param_2[2] = ((unsigned char *)0x00001004U);
    param_2[1] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1ca8);
    param_2[4] = ((unsigned char *)0x00001005U);
    param_2[3] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1cac);
    param_2[6] = ((unsigned char *)0x000010faU);
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(param_1 + 0x1da0);
    param_2 = param_2 + 8;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x10000000) != 0) {
    *param_2 = 0x413de;
    param_2[1] = *(undefined4 *)(param_1 + 0x25a0);
    param_2[2] = *(undefined4 *)(param_1 + 0x25a4);
    param_2[3] = *(undefined4 *)(param_1 + 0x25a8);
    param_2[4] = *(undefined4 *)(param_1 + 0x25ac);
    uVar3 = *(undefined4 *)(param_1 + 0x25b0);
    param_2[6] = 0x313e9;
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(param_1 + 0x25b4);
    param_2[8] = *(undefined4 *)(param_1 + 0x25b8);
    param_2[9] = *(undefined4 *)(param_1 + 0x25bc);
    param_2[10] = *(undefined4 *)(param_1 + 0x25c0);
    param_2 = param_2 + 0xb;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x20000000) != 0) {
    *param_2 = ((unsigned char *)0x000813adU);
    param_2[1] = *(undefined4 *)(param_1 + 0x25c4);
    param_2[2] = *(undefined4 *)(param_1 + 0x25c8);
    param_2[3] = *(undefined4 *)(param_1 + 0x25cc);
    param_2[4] = *(undefined4 *)(param_1 + 0x25d0);
    param_2[5] = *(undefined4 *)(param_1 + 0x25d4);
    param_2[6] = *(undefined4 *)(param_1 + 0x25d8);
    param_2[7] = *(undefined4 *)(param_1 + 0x25dc);
    param_2[8] = *(undefined4 *)(param_1 + 0x25e0);
    param_2[9] = *(undefined4 *)(param_1 + 0x25e4);
    param_2 = param_2 + 10;
  }
  if (bVar1) {
    *(undefined4 **)(param_1 + 0x298c) = param_2;
    (**(code **)(param_1 + 0x299c))(iVar4,param_2);
  }
  return param_2;
}

/* FUN_000230d0 @ 0x230d0 (1544 bytes) */
int FUN_000230d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1 + 0x240;
  if (*(char *)(param_1 + 0x2a5e) != '\0') {
    if ((*(int *)(param_1 + 0x154) < 0) || (param_4 == 0)) {
      param_4 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x2a5e) = 0;
    }
    bVar1 = param_2 == (undefined4 *)0x0;
    puVar5 = param_2;
    if (bVar1) {
      puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar7,500);
      *(undefined4 **)(param_1 + 0x298c) = puVar5;
    }
    puVar3 = *(uint **)(param_1 + 0x1d8);
    *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar5;
    puVar5[2] = param_3;
    *puVar5 = 0x30000000;
    puVar5[1] = 0xfa;
    puVar5[3] = param_4;
    puVar5[4] = param_5;
    if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
      param_6 = (*(int *)(param_1 + 0x160) - param_8) - param_6;
    }
    puVar5[5] = param_6;
    puVar5[6] = param_7;
    puVar5[7] = param_8;
    puVar3 = *(uint **)(param_1 + 0x1d8);
    *puVar3 = (int)(puVar5 + 0xfa) - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar5 + 0xfa;
    puVar5[0xfb] = 0;
    puVar5[0xfa] = 0x33000000;
    puVar5[0xfc] = ((unsigned char *)0x00001393U);
    puVar5[0xfd] = 10;
    puVar5[0xfe] = ((unsigned char *)0x000013c6U);
    puVar5[0xff] = 3;
    puVar5[0x100] = 0x5c8;
    puVar5[0x101] = 0x20000;
    puVar5[0x102] = (*(unsigned char *)0x000010ea);
    uVar4 = *(undefined4 *)(param_1 + 0x1cfc);
    puVar5[0x104] = ((unsigned char *)0x000010faU);
    puVar5[0x103] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1da0);
    puVar5[0x106] = 0xc0001000;
    puVar5[0x108] = 0x11004;
    puVar5[0x105] = uVar4;
    puVar5[0x109] = *(undefined4 *)(param_1 + 0x1ca8);
    uVar4 = *(undefined4 *)(param_1 + 0x1cac);
    puVar5[0x10b] = ((unsigned char *)0x00001008U);
    puVar5[0x10a] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ca0);
    puVar5[0x10d] = (*(unsigned char *)0x000010e9);
    puVar5[0x10c] = uVar4;
    puVar5[0x10e] = *(undefined4 *)(param_1 + 0x1d20);
    puVar5[0x10f] = ((unsigned char *)0x000013c7U);
    uVar4 = *(undefined4 *)(param_1 + 0x1cf0);
    puVar5[0x111] = ((unsigned char *)0x000013c1U);
    puVar5[0x110] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ce4);
    puVar5[0x113] = 0x850;
    puVar5[0x112] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1dc0);
    puVar5[0x115] = 0x887;
    puVar5[0x114] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1db4);
    puVar5[0x1b7] = 0x82c;
    puVar5[0x116] = uVar4;
    uVar4 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar5[0x117] = ((unsigned char *)0x000010aeU);
    puVar5[0x1b8] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d70);
    puVar5[0x119] = ((unsigned char *)0x00001394U);
    puVar5[0x118] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d30);
    puVar5[0x11b] = ((unsigned char *)0x00001380U);
    puVar5[0x11d] = ((unsigned char *)0x00001002U);
    puVar5[0x11c] = 0;
    puVar5[0x11a] = uVar4;
    puVar5[0x11e] = *(undefined4 *)(param_1 + 0x1d90);
    uVar4 = *(undefined4 *)(param_1 + 0x1d90);
    puVar5[0x11f] = 0x824;
    puVar5[0x11e] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ddc);
    puVar5[0x121] = 0x825;
    puVar5[0x120] = uVar4;
    puVar5[0x122] = *(undefined4 *)(param_1 + 0x1de0);
    puVar5[0x123] = 0x82d;
    puVar2 = PTR_DAT_001e88c8;
    uVar4 = *(undefined4 *)(0x000026c8 + param_1 + 4);
    puVar5[0x125] = 0x854;
    puVar5[0x124] = uVar4;
    uVar4 = **(undefined4 **)(param_1 + 0x2680);
    puVar5[0x127] = 0x878;
    puVar5[0x126] = uVar4;
    uVar4 = **(undefined4 **)(param_1 + 0x2684);
    puVar5[0x129] = ((unsigned char *)0x000013c0U);
    puVar5[0x128] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ce0);
    puVar5[299] = ((unsigned char *)0x000012f0U);
    puVar5[0x12a] = uVar4;
    uVar6 = *(uint *)(param_1 + 0x1d2c);
    puVar5[300] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[300] = uVar6 & 0xfffffffe;
    }
    puVar5[0x12d] = ((unsigned char *)0x000012f5U);
    uVar6 = *(uint *)(param_1 + 0x1c8c);
    puVar5[0x12e] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[0x12e] = uVar6 & 0xfffff7ff;
    }
    puVar5[0x12f] = ((unsigned char *)0x000010a2U);
    uVar4 = *(undefined4 *)(param_1 + 0x1d7c);
    puVar5[0x131] = ((unsigned char *)0x00001381U);
    puVar5[0x130] = uVar4;
    uVar6 = *(uint *)(param_1 + 0x1cc0);
    puVar5[0x132] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
      puVar5[0x132] = uVar6 & 0xfffffffc;
    }
    puVar5[0x133] = ((unsigned char *)0x0000109eU);
    param_2 = puVar5 + 0x1b9;
    uVar4 = *(undefined4 *)(param_1 + 0x1d6c);
    puVar5[0x135] = ((unsigned char *)0x00001096U);
    puVar5[0x134] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1df8);
    puVar5[0x137] = ((unsigned char *)0x00001041U);
    puVar5[0x134] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x29f0);
    puVar5[0x139] = ((unsigned char *)0x00001046U);
    puVar5[0x138] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1dfc);
    puVar5[0x13b] = ((unsigned char *)0x00001094U);
    puVar5[0x153] = ((unsigned char *)0x00001095U);
    puVar5[0x13d] = ((unsigned char *)0x00001095U);
    puVar5[0x179] = ((unsigned char *)0x00001180U);
    puVar5[0x13f] = ((unsigned char *)0x00001095U);
    puVar5[0x141] = ((unsigned char *)0x00001095U);
    puVar5[0x143] = ((unsigned char *)0x00001095U);
    puVar5[0x13a] = uVar4;
    puVar5[0x145] = ((unsigned char *)0x00001095U);
    puVar5[0x147] = ((unsigned char *)0x00001095U);
    puVar5[0x149] = ((unsigned char *)0x00001095U);
    puVar5[0x14b] = ((unsigned char *)0x00001095U);
    puVar5[0x14d] = ((unsigned char *)0x00001095U);
    puVar5[0x14f] = ((unsigned char *)0x00001095U);
    puVar5[0x151] = ((unsigned char *)0x00001095U);
    puVar5[0x155] = 0xc0221000;
    puVar5[0x13c] = 0;
    puVar5[0x17a] = 2;
    puVar5[0x17b] = ((unsigned char *)0x00001189U);
    puVar5[0x17d] = ((unsigned char *)0x00001181U);
    puVar5[0x17f] = ((unsigned char *)0x0000118dU);
    puVar5[0x181] = ((unsigned char *)0x0000118eU);
    puVar5[0x183] = ((unsigned char *)0x0000118cU);
    puVar5[0x185] = ((unsigned char *)0x000011a9U);
    uVar4 = *(undefined4 *)(param_1 + 0x257c);
    puVar5[0x187] = ((unsigned char *)0x000011aaU);
    puVar5[0x186] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2580);
    puVar5[0x189] = ((unsigned char *)0x000011abU);
    puVar5[0x188] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2584);
    puVar5[0x18b] = ((unsigned char *)0x000011acU);
    puVar5[0x18a] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2588);
    puVar5[0x18d] = ((unsigned char *)0x000010c0U);
    puVar5[0x18c] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x216c);
    puVar5[399] = ((unsigned char *)0x000010c1U);
    puVar5[0x191] = ((unsigned char *)0x000010c8U);
    puVar5[0x193] = ((unsigned char *)0x0000101dU);
    puVar5[0x18e] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2128);
    puVar5[0x195] = ((unsigned char *)0x0000138aU);
    puVar5[0x197] = ((unsigned char *)0x0000138eU);
    puVar5[0x19c] = 0;
    puVar5[0x199] = ((unsigned char *)0x00001040U);
    puVar5[0x196] = 0;
    puVar5[0x198] = 0;
    puVar5[0x19a] = 0;
    puVar5[0x194] = uVar4;
    puVar5[0x19b] = (*(unsigned char *)0x00001150);
    puVar5[0x19d] = ((unsigned char *)0x00001100U);
    uVar4 = *(undefined4 *)(param_1 + 0x1f1c);
    puVar5[0x19f] = ((unsigned char *)0x00001110U);
    puVar5[0x19e] = uVar4;
    puVar5[0x1a0] = *(undefined4 *)(param_1 + 0x1f5c);
    puVar5[0x1a1] = (*(unsigned char *)0x00001120);
    uVar4 = *(undefined4 *)(param_1 + 0x1f9c);
    puVar5[0x1a3] = ((unsigned char *)0x00001130U);
    puVar5[0x1a2] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1fdc);
    puVar5[0x1a5] = ((unsigned char *)0x00001140U);
    puVar5[0x1a4] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x201c);
    puVar5[0x1a7] = ((unsigned char *)0x000010f4U);
    puVar5[0x1a8] = 0xaaaa;
    puVar5[0x1a9] = ((unsigned char *)0x00001383U);
    puVar5[0x1a6] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d34);
    puVar5[0x1ab] = ((unsigned char *)0x00001386U);
    puVar5[0x1aa] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d38);
    puVar5[0x1ad] = 0x110f8;
    puVar5[0x1ac] = uVar4;
    puVar5[0x1ae] = *(undefined4 *)(param_1 + 0x1d98);
    uVar4 = *(undefined4 *)(param_1 + 0x1d50);
    puVar5[0x1b0] = ((unsigned char *)0x00001087U);
    puVar5[0x1af] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1f0c);
    puVar5[0x1b2] = 0x31080;
    puVar5[0x1b1] = uVar4;
    puVar5[0x1b3] = *(undefined4 *)(param_1 + 0x1efc);
    puVar5[0x1b4] = *(undefined4 *)(param_1 + 0x1f04);
    puVar5[0x1b5] = *(undefined4 *)(param_1 + 0x1f00);
    puVar5[0x1b6] = *(undefined4 *)(param_1 + 0x1f08);
    FUN_0004c100(puVar5 + 0xfc,iVar7);
    if (bVar1) {
      *(undefined4 **)(param_1 + 0x298c) = param_2;
      (**(code **)(param_1 + 0x299c))(iVar7,param_2);
    }
  }
  return param_2;
}

/* FUN_000236f0 @ 0x236f0 (8 bytes) */
int FUN_000236f0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* FUN_00023700 @ 0x23700 (360 bytes) */
int FUN_00023700(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = param_3 + 5;
  *param_3 = 0x308c8;
  param_3[1] = param_2[0xc];
  param_3[2] = param_2[0xd];
  param_3[3] = param_2[0xe];
  param_3[4] = param_2[0xf];
  if ((*(uint *)(param_1 + 0x1ca0) & 8) != 0) {
    if (((unsigned char *)0x00002e0a)[*(int *)(*(int *)(param_1 + 4) + 0x10)] == '\0') {
      puVar5 = param_3 + 9;
      param_3[5] = 0x208cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
    }
    else {
      puVar5 = param_3 + 10;
      param_3[5] = 0x308cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
      param_3[9] = param_2[0x13];
    }
  }
  uVar4 = 10;
  uVar2 = 0x8e8;
  iVar6 = 8;
  puVar3 = param_2;
  do {
    if ((1 << (uVar4 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) {
      *puVar5 = uVar2 | 0x30000;
      puVar5[1] = puVar3[0x20];
      puVar5[2] = puVar3[0x21];
      puVar5[3] = puVar3[0x22];
      puVar5[4] = puVar3[0x23];
      puVar5 = puVar5 + 5;
    }
    uVar4 = uVar4 + 1;
    uVar2 = uVar2 + 4;
    puVar3 = puVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *puVar5 = 0x917;
  bVar1 = *(byte *)(param_2 + 0x1f);
  puVar5[2] = (uint)0x000308c0;
  puVar5[1] = -(uint)bVar1 >> 0x1f;
  puVar5[3] = *param_2;
  puVar5[4] = param_2[1];
  puVar5[5] = param_2[2];
  puVar5[6] = param_2[3];
  return puVar5 + 7;
}

/* FUN_00023870 @ 0x23870 (420 bytes) */
int FUN_00023870(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  uint *param_4;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_2 & 2) != 0) {
    *param_4 = 0x208c4;
    param_4[1] = *(uint *)(param_3 + 0x40);
    param_4[2] = *(uint *)(param_3 + 0x44);
    param_4[3] = *(uint *)(param_3 + 0x48);
    param_4 = param_4 + 4;
  }
  if ((param_2 & 4) != 0) {
    *param_4 = 0x308c8;
    param_4[1] = *(uint *)(param_3 + 0x30);
    param_4[2] = *(uint *)(param_3 + 0x34);
    param_4[3] = *(uint *)(param_3 + 0x38);
    param_4[4] = *(uint *)(param_3 + 0x3c);
    param_4 = param_4 + 5;
  }
  if ((param_2 & 8) != 0) {
    *param_4 = 0x208cc;
    param_4[1] = *(uint *)(param_3 + 0x50);
    param_4[2] = *(uint *)(param_3 + 0x54);
    param_4[3] = *(uint *)(param_3 + 0x58);
    param_4 = param_4 + 4;
  }
  uVar5 = 0;
  uVar4 = 0x8e8;
  iVar6 = 8;
  iVar3 = param_3;
  do {
    uVar2 = 0x400 << (uVar5 & 0x3f);
    if ((uVar2 & param_2) != 0) {
      param_2 = param_2 & ~uVar2;
      *param_4 = uVar4 | 0x30000;
      param_4[1] = *(uint *)(iVar3 + 0x80);
      param_4[2] = *(uint *)(iVar3 + 0x84);
      param_4[3] = *(uint *)(iVar3 + 0x88);
      param_4[4] = *(uint *)(iVar3 + 0x8c);
      param_4 = param_4 + 5;
    }
    if ((param_2 & 0x3fc00) == 0) break;
    uVar5 = uVar5 + 1;
    uVar4 = uVar4 + 4;
    iVar3 = iVar3 + 0x10;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if ((param_2 & 0x40000) != 0) {
    *param_4 = 0x908;
    param_4[1] = *(uint *)(param_3 + 0x5c);
    param_4 = param_4 + 2;
  }
  if ((param_2 & 0x80000) != 0) {
    *param_4 = 0x3090c;
    param_4[1] = *(uint *)(param_3 + 0x60);
    param_4[2] = *(uint *)(param_3 + 100);
    param_4[3] = *(uint *)(param_3 + 0x68);
    param_4[4] = *(uint *)(param_3 + 0x6c);
    param_4 = param_4 + 5;
  }
  *param_4 = 0x917;
  bVar1 = *(byte *)(param_3 + 0x7c);
  param_4[2] = (uint)0x000308c0;
  param_4[1] = -(uint)bVar1 >> 0x1f;
  param_4[3] = *(uint *)(param_3 + 0x20);
  param_4[4] = *(uint *)(param_3 + 0x24);
  param_4[5] = *(uint *)(param_3 + 0x28);
  param_4[6] = *(uint *)(param_3 + 0x2c);
  return param_4 + 7;
}

/* FUN_00023a24 @ 0x23a24 (1860 bytes) */
int FUN_00023a24(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 in_r8;
  undefined4 uVar5;
  undefined4 uVar6;
  
  bVar1 = param_2 == 5;
  uVar5 = *(undefined4 *)(param_1 + 4);
  uVar6 = *(undefined4 *)(param_1 + 0x1ca0);
  iVar2 = param_5;
  if (bVar1) {
    iVar2 = param_5 + 1;
  }
  puVar3 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(*(int *)(param_1 + 0x243c) + 1U & 0xfffffffe) +
                              iVar2 * *(int *)(param_1 + 0x243c) * 5 + iVar2 * 2 + 0x16,param_3,
                      param_4,param_5,in_r8,iVar2 * 2);
  iVar2 = *(int *)(param_1 + 0x2440);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
  if (iVar2 != param_1 + 0x1be4) {
    *(int *)(param_1 + 0x2440) = param_1 + 0x1be4;
    *(int *)(param_1 + 0x2444) = param_1 + 0x1c04;
    *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x1ca4);
    puVar3 = (undefined4 *)FUN_0002c0c0(uVar5,puVar3);
  }
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar3 = 0x5c8;
    puVar3[1] = 0x10000000;
    puVar3 = puVar3 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  puVar4 = puVar3 + 4;
  *puVar3 = 0x82c;
  uVar5 = *(undefined4 *)(param_1 + 0x1b84);
  puVar3[2] = 0x821;
  puVar3[3] = param_2;
  puVar3[1] = uVar5;
  if (*(char *)(*(int *)(param_1 + 4) + 0x20) == '\0') {
    if (bVar1) {
      puVar4 = (undefined4 *)((int (*)())FUN_00023700)(param_1,param_3,puVar4);
    }
    if (param_5 == 0x24) {
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4,puVar4);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x100,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x200,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x300,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x400,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x500,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x600,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x700,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x800,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x900,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xa00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xb00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xc00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xd00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xe00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0xf00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1000,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001100) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001200) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001300) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001400) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001500) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001600) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,((unsigned char *)0x00001700) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1800,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1900,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1a00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1b00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1c00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1d00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1e00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x1f00,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x2000,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x2100,uVar5);
      uVar5 = ((int (*)())FUN_00023700)(param_1,param_4 + 0x2200,uVar5);
      puVar4 = (undefined4 *)((int (*)())FUN_00023700)(param_1,param_4 + 0x2300,uVar5);
    }
    else if (0 < param_5) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        puVar4 = (undefined4 *)((int (*)())FUN_00023700)(param_1,param_4,puVar4);
        param_4 = param_4 + 0x100;
      } while (param_5 != iVar2);
    }
  }
  else {
    if (bVar1) {
      puVar4 = (undefined4 *)((int (*)())FUN_00023870)(param_1,uVar6,param_3,puVar4);
    }
    if (param_5 == 0x24) {
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4,puVar4);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x200,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x300,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x400,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x500,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x600,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x700,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xa00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xb00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xc00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xd00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xe00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0xf00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001100) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001200) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001300) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001400) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001500) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001600) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,((unsigned char *)0x00001700) + param_4,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1a00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1b00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1c00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1d00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1e00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x1f00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x2000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x2100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x2200,uVar5);
      puVar4 = (undefined4 *)((int (*)())FUN_00023870)(param_1,uVar6,param_4 + 0x2300,uVar5);
    }
    else if (0 < param_5) {
      iVar2 = 0;
      do {
        iVar2 = iVar2 + 1;
        puVar4 = (undefined4 *)((int (*)())FUN_00023870)(param_1,uVar6,param_4,puVar4);
        param_4 = param_4 + 0x100;
      } while (param_5 != iVar2);
    }
  }
  *puVar4 = 0x92b;
  puVar4[3] = 0;
  puVar4[2] = ((unsigned char *)0x00001393U);
  puVar4[1] = 0;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1);
  return;
}

/* FUN_00024190 @ 0x24190 (344 bytes) */
int FUN_00024190(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  uint param_4;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(*(int *)(param_1 + 0x243c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x243c) * param_4 * 5 + param_4 * 2 + 0x16,param_3,
                      param_4,in_r7,in_r8,*(code **)(param_1 + 0x2758));
  iVar1 = *(int *)(param_1 + 0x2440);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
  if (iVar1 != param_1 + 0x1be4) {
    *(int *)(param_1 + 0x2440) = param_1 + 0x1be4;
    *(int *)(param_1 + 0x2444) = param_1 + 0x1c04;
    *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x1ca4);
    puVar2 = (undefined4 *)FUN_0002c0c0(uVar5,puVar2);
  }
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar2 = 0x5c8;
    puVar2[1] = 0x10000000;
    puVar2 = puVar2 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  puVar3 = puVar2 + 4;
  *puVar2 = 0x82c;
  uVar5 = *(undefined4 *)(param_1 + 0x1b84);
  puVar2[2] = 0x821;
  puVar2[3] = param_2;
  puVar2[1] = uVar5;
  if (param_4 != 0) {
    uVar4 = 0;
    do {
      uVar5 = *param_3;
      uVar4 = uVar4 + 1;
      param_3 = param_3 + 1;
      puVar3 = (undefined4 *)((int (*)())FUN_00023700)(param_1,uVar5,puVar3);
    } while (uVar4 < param_4);
  }
  *puVar3 = 0x92b;
  puVar3[3] = 0;
  puVar3[2] = ((unsigned char *)0x00001393U);
  puVar3[1] = 0;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1);
  return;
}

/* FUN_000242f0 @ 0x242f0 (116 bytes) */
void FUN_000242f0(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7,double param_8,int param_9,int param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_9,0,4,param_11,param_13,param_14,param_1,param_2,param_3,param_4,
                       param_5,param_6,param_7,param_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_9 + 0x240;
    uVar5 = *(undefined4 *)(param_9 + 0x244);
    uVar6 = *(undefined4 *)(param_9 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_9 + 0x2998))
                       (iVar4,(*(int *)(param_9 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_9 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_9 + 0x298c) = puVar1;
    if (*(code **)(param_9 + 0x2680) != 0x00001e24 + param_9) {
      *(code **)(param_9 + 0x2680) = 0x00001e24 + param_9;
      *(int *)(param_9 + 0x2684) = param_9 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_9 + 4) = *(undefined4 *)(param_9 + 0x1ee4);
      puVar1 = (undefined4 *)FUN_0002c0c0(uVar5,puVar1);
    }
    if (*(char *)(param_9 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_9 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_9);
    puVar1[2] = 0x821;
    puVar1[3] = 4;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_9 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10,puVar2);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x100,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x200,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x300,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x400,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x500,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x600,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x700,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x800,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x900,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xa00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xb00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xc00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xd00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xe00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0xf00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1000,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001100) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001200) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001300) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001400) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001500) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001600) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001700) + param_10,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1800,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1900,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1a00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1b00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1c00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1d00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1e00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x1f00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x2000,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x2100,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_10 + 0x2200,uVar5);
        puVar2 = (undefined4 *)((int (*)())FUN_00023700)(iVar4,param_10 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)((int (*)())FUN_00023700)(iVar4,param_10,puVar2);
          param_10 = param_10 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10,puVar2);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x200,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x300,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x400,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x500,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x600,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x700,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xa00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xb00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xc00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xd00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xe00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0xf00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001100) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001200) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001300) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001400) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001500) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001600) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001700) + param_10,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1a00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1b00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1c00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1d00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1e00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x1f00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x2000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x2100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x2200,uVar5);
      puVar2 = (undefined4 *)((int (*)())FUN_00023870)(iVar4,uVar6,param_10 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)((int (*)())FUN_00023870)(iVar4,uVar6,param_10,puVar2);
        param_10 = param_10 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_9 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_9 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024370 @ 0x24370 (112 bytes) */
void FUN_00024370(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,5,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)FUN_0002c0c0(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 6;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2,puVar2);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x100,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x200,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x300,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x400,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x500,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x600,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x700,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x800,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x900,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = ((int (*)())FUN_00023700)(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)((int (*)())FUN_00023700)(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)((int (*)())FUN_00023700)(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2,puVar2);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = ((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)((int (*)())FUN_00023870)(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)((int (*)())FUN_00023870)(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

