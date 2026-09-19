#include "decls.h"

/* FUN_0009aa35 @ 0x9aa35 (250 bytes) */
int FUN_0009aa35(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  iVar1 = *(int *)(param_2 + 0x54);
  pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_4 * *(int *)(iVar1 + 0x3cc));
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(iVar1 + 0x3c8);
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar1 + 0x3cc);
  *(void **)(param_3 + 0x18) = pvVar2;
  *(int **)(param_3 + 0x1c) = &local_10;
  *(undefined4 **)(param_3 + 0x28) = &local_14;
  *(undefined4 **)(param_3 + 0x2c) = &local_18;
  *(undefined4 **)(param_3 + 0x30) = &local_1c;
  iVar3 = FUN_00077d43(param_3);
  if (iVar3 == 0) {
    _memcpy(*(void **)(iVar1 + 0x3c8),pvVar2,param_4 * local_10);
    *(int *)(iVar1 + 0x3cc) = local_10;
    *(undefined4 *)(param_2 + 0x34) = local_14;
    *(undefined4 *)(param_2 + 0x38) = local_18;
    *(undefined4 *)(param_2 + 0x44) = local_1c;
    (**(code **)(param_1 + 0x18))(pvVar2);
    return true;
  }
  _memcpy(*(void **)(iVar1 + 0x3c8),pvVar2,param_4 * *(int *)(iVar1 + 0x3cc));
  (**(code **)(param_1 + 0x18))(pvVar2);
  return iVar3 == 0;
}

/* FUN_0009ab2f @ 0x9ab2f (778 bytes) */
int FUN_0009ab2f(param_1)
  int param_1;
{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  bool bVar7;
  float fVar8;
  byte bVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  uint uVar17;
  char cVar18;
  byte bVar19;
  int iVar20;
  ushort *puVar21;
  bool bVar22;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_1c = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(char *)(local_1c + 0x24ad) == '\0') {
    bVar6 = false;
    bVar7 = false;
    bVar22 = false;
    bVar2 = *(byte *)(param_1 + 0x44);
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x44);
    if (((bVar2 & 1) == 0) || (uVar17 = *(uint *)(param_1 + 0x88), uVar17 == 0)) {
      bVar6 = false;
      bVar7 = false;
    }
    else {
      bVar6 = false;
      bVar7 = false;
      iVar20 = local_1c;
      do {
        if ((uVar17 & 1) != 0) {
          bVar6 = (bool)(bVar6 | *(float *)(iVar20 + 0x24fc) != 0.0);
          bVar7 = (bool)(bVar7 | *(float *)(iVar20 + 0x24fc) == 0.0);
        }
        iVar20 = iVar20 + 0x80;
        uVar17 = uVar17 >> 1;
      } while (uVar17 != 0);
    }
    bVar22 = (*(byte *)(param_1 + 0x8c) & 0x30) != 0;
  }
  bVar19 = (*(byte *)(local_1c + 0x2d4d) & 1) * '\x04';
  bVar3 = *(byte *)(param_1 + 0x1874);
  bVar9 = (*(byte *)(param_1 + 300) & 1) << 5;
  *(byte *)(param_1 + 0x1874) = bVar3 & 0xdb | bVar19 | bVar9;
  if (((bVar22) || (bVar6)) || (bVar7)) {
    cVar18 = '\x01';
  }
  else {
    cVar18 = '\0';
  }
  *(byte *)(param_1 + 0x1874) = bVar3 & 0x5b | bVar19 | bVar9 | cVar18 << 7;
  if ((bVar2 & 1) == 0) {
    *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xf;
    *(byte *)(param_1 + 0x1877) =
         *(byte *)(param_1 + 0x1877) & 0xfe | (*(byte *)(param_1 + 0x45) & 0x85) != 0;
    iVar20 = 8;
    do {
      *(undefined2 *)(param_1 + 0x1894) = 0;
      param_1 = param_1 + 2;
      iVar20 = iVar20 + -1;
    } while (iVar20 != 0);
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x1876);
    *(byte *)(param_1 + 0x1876) = bVar2 | 0x10;
    bVar19 = (*(short *)(local_1c + 0x2d48) == -0x7e06) << 5;
    *(byte *)(param_1 + 0x1876) = bVar2 & 0xdf | 0x10 | bVar19;
    *(byte *)(param_1 + 0x1876) =
         bVar2 & 0x1f | 0x10 | bVar19 | (*(byte *)(local_1c + 0x2d4c) & 1) << 6 |
         *(char *)(param_1 + 0x12d) << 7;
    fVar8 = FLOAT_001c5ba4;
    puVar21 = (ushort *)(param_1 + 0x1894);
    local_14 = *(uint *)(param_1 + 0x88);
    local_18 = param_1;
    local_20 = 0;
    do {
      if ((local_14 & 1) == 0) {
        *puVar21 = 0;
      }
      else {
        pbVar1 = (byte *)(param_1 + 0x3a8 + local_20);
        *(byte *)puVar21 = (byte)*puVar21 | 1;
        uVar5 = (ushort)(*pbVar1 & 3) * 2;
        uVar4 = *puVar21;
        *puVar21 = uVar4 & 0xfff9 | uVar5;
        uVar10 = (*pbVar1 >> 2 & 3) << 3;
        *puVar21 = uVar4 & 0xffe1 | uVar5 | uVar10;
        uVar11 = (*pbVar1 >> 4 & 3) << 5;
        *puVar21 = uVar4 & 0xff81 | uVar5 | uVar10 | uVar11;
        uVar12 = (ushort)(*(float *)(local_1c + 0x24fc) != 0.0) << 7;
        *puVar21 = uVar4 & 0xff01 | uVar5 | uVar10 | uVar11 | uVar12;
        uVar13 = (ushort)(fVar8 == *(float *)(local_1c + 0x24fc)) << 8;
        *puVar21 = uVar4 & 0xfe01 | uVar5 | uVar10 | uVar11 | uVar12 | uVar13;
        uVar14 = (*(byte *)(local_18 + 0x150c) & 1) << 9;
        *puVar21 = uVar4 & 0xfc01 | uVar5 | uVar10 | uVar11 | uVar12 | uVar13 | uVar14;
        uVar15 = (ushort)(*(float *)(local_1c + 0x251c) != 0.0) << 10;
        *puVar21 = uVar4 & 0xf801 | uVar5 | uVar10 | uVar11 | uVar12 | uVar13 | uVar14 | uVar15;
        uVar16 = (*pbVar1 >> 6 & 1) << 0xb;
        *puVar21 = uVar4 & 0xf001 | uVar5 | uVar10 | uVar11 | uVar12 | uVar13 | uVar14 | uVar15 |
                   uVar16;
        *puVar21 = uVar4 & 0xe001 | uVar5 | uVar10 | uVar11 | uVar12 | uVar13 | uVar14 | uVar15 |
                   uVar16 | (ushort)(*pbVar1 >> 7) << 0xc;
      }
      local_14 = local_14 >> 1;
      puVar21 = puVar21 + 1;
      local_20 = local_20 + 4;
      local_1c = local_1c + 0x80;
      local_18 = local_18 + 0x6c;
    } while (local_20 != 0x20);
  }
  return;
}

/* FUN_0009ae39 @ 0x9ae39 (224 bytes) */
int FUN_0009ae39(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(param_1 + 0x44) < '\0') && (*(char *)(param_1 + 0x121) == '\0')) {
    sVar1 = *(short *)(iVar2 + 0x2e04);
    if (sVar1 == 0x801) {
      cVar3 = '\x02';
    }
    else if (sVar1 == 0x2601) {
      cVar3 = '\x03';
    }
    else if (sVar1 == 0x800) {
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\0';
    }
    *(byte *)(param_1 + 0x1877) =
         *(byte *)(param_1 + 0x1877) & 0xf1 | cVar3 * '\x02' |
         (*(short *)(iVar2 + 0x2e06) == -0x7baf) << 3;
    sVar1 = *(short *)(iVar2 + 0x2e08);
    if (sVar1 == -0x7aa5) {
      cVar3 = '\x02';
    }
    else if (sVar1 == -0x7aa4) {
      cVar3 = '\0';
    }
    else if (sVar1 == 0x2502) {
      cVar3 = '\x01';
    }
    *(byte *)(param_1 + 0x1879) = *(byte *)(param_1 + 0x1879) & 0xcf | cVar3 << 4;
    return;
  }
  *(byte *)(param_1 + 0x1877) = *(byte *)(param_1 + 0x1877) & 0xf1;
  *(byte *)(param_1 + 0x1879) = *(byte *)(param_1 + 0x1879) & 0xcf;
  return;
}

/* FUN_0009af19 @ 0x9af19 (182 bytes) */
int FUN_0009af19(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(iVar1 + 0x4301) != '\0') && (*(char *)(param_1 + 0x91) != '\0')) {
    *(byte *)(param_1 + 0x1874) = *(byte *)(param_1 + 0x1874) | 0x10;
    *(byte *)(param_1 + 0x1875) =
         *(byte *)(param_1 + 0x1875) & 1 | (*(byte *)(iVar1 + 0x4302) & 1) * '\x02' |
         *(byte *)(param_1 + 0x8d) >> 2 & 4 | (*(char *)(param_1 + 0x90) == '\x02') << 3 |
         (*(byte *)(param_1 + 0x91) & 7) << 4 | *(char *)(param_1 + 0x13a9) << 7;
    *(byte *)(param_1 + 0x1876) =
         *(byte *)(param_1 + 0x1876) & 0xfe | *(byte *)(param_1 + 0x13aa) & 1;
    return;
  }
  *(byte *)(param_1 + 0x1874) = *(byte *)(param_1 + 0x1874) & 0xef;
  *(byte *)(param_1 + 0x1875) = *(byte *)(param_1 + 0x1875) & 1;
  *(byte *)(param_1 + 0x1876) = *(byte *)(param_1 + 0x1876) & 0xfe;
  return;
}

/* FUN_0009afcf @ 0x9afcf (670 bytes) */
int FUN_0009afcf(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int local_18;
  byte local_11;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  *(undefined1 *)(param_1 + 0x129) = 0;
  *(undefined1 *)(param_1 + 0x130) = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  *(undefined1 *)(param_1 + 0x128) = 0;
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
LAB_0009b106:
    bVar3 = false;
    local_11 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x13c) == 1) {
      uVar7 = *(uint *)(param_1 + 0x26c);
      *(uint *)(param_1 + 0x270) = uVar7 & 0xf;
      *(uint *)(param_1 + 0x278) = uVar7 >> 4 & 0xf;
      *(uint *)(param_1 + 0x280) = uVar7 >> 8 & 0xf;
      *(uint *)(param_1 + 0x288) = uVar7 >> 0xc & 0xf;
      *(uint *)(param_1 + 0x274) = uVar7 >> 0x10 & 0xf;
      *(uint *)(param_1 + 0x27c) = uVar7 >> 0x14 & 0xf;
      *(uint *)(param_1 + 0x284) = uVar7 >> 0x18 & 0xf;
      *(uint *)(param_1 + 0x28c) = uVar7 >> 0x1c;
      *(undefined4 *)(param_1 + 0x290) = 2;
      *(undefined4 *)(param_1 + 0x294) = 3;
    }
    else {
      *(undefined4 *)(param_1 + 0x270) = 0;
      *(undefined4 *)(param_1 + 0x278) = 1;
      *(undefined4 *)(param_1 + 0x280) = 2;
      *(undefined4 *)(param_1 + 0x288) = 3;
      *(undefined4 *)(param_1 + 0x274) = 4;
      *(undefined4 *)(param_1 + 0x27c) = 5;
      *(undefined4 *)(param_1 + 0x284) = 6;
      *(undefined4 *)(param_1 + 0x28c) = 7;
      *(undefined4 *)(param_1 + 0x290) = 0;
      *(undefined4 *)(param_1 + 0x294) = 1;
    }
    uVar7 = *(uint *)(param_1 + 0x88);
    if (uVar7 == 0) goto LAB_0009b106;
    bVar3 = false;
    local_11 = 0;
    local_18 = 0;
    iVar9 = iVar2;
    do {
      if ((uVar7 & 1) != 0) {
        if ((((*(byte *)(param_1 + 0x3a8 + local_18 * 4) & 0x30) == 0) ||
            (*(short *)(iVar2 + 0x2d48) != -0x7e06)) || (*(char *)(iVar2 + 0x2d4d) == '\0')) {
          bVar4 = 0;
        }
        else {
          bVar4 = 1;
        }
        *(byte *)(param_1 + 0x130) = bVar4 | *(byte *)(param_1 + 0x130);
        local_11 = local_11 | *(float *)(iVar9 + 0x24fc) != 0.0;
        bVar3 = (bool)(bVar3 | *(float *)(iVar9 + 0x24fc) == 0.0);
      }
      local_18 = local_18 + 1;
      iVar9 = iVar9 + 0x80;
      uVar7 = uVar7 >> 1;
    } while (uVar7 != 0);
  }
  bVar8 = *(byte *)(param_1 + 0x8c) >> 4 & 1;
  bVar4 = *(byte *)(param_1 + 0x8c) >> 5 & 1;
  bVar6 = bVar8 | bVar4;
  if ((bVar4 == 0 && bVar8 == 0) || (*(char *)(iVar2 + 0x2d4d) == '\0')) {
    bVar4 = 0;
  }
  else {
    bVar4 = 1;
  }
  bVar4 = bVar4 | *(byte *)(param_1 + 0x130);
  *(byte *)(param_1 + 0x130) = bVar4;
  *(byte *)(param_1 + 0x129) = bVar4 | local_11;
  if ((bVar6 == 0) && (local_11 == 0)) {
    if (bVar3) {
      cVar1 = *(char *)(iVar2 + 0x24ad);
      goto joined_r0x0009b16a;
    }
  }
  else {
    cVar1 = *(char *)(iVar2 + 0x24ad);
joined_r0x0009b16a:
    if (cVar1 != '\0') {
      uVar5 = 1;
      goto LAB_0009b16e;
    }
  }
  uVar5 = 0;
LAB_0009b16e:
  *(undefined1 *)(param_1 + 0x128) = uVar5;
  if ((*(char *)(param_1 + 0x12f) == '\0') && ((*(byte *)(param_1 + 0x44) & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x12a) = 1;
    return;
  }
  *(byte *)(param_1 + 0x12a) = bVar6;
  return;
}

/* FUN_0009b26d @ 0x9b26d (108 bytes) */
int FUN_0009b26d(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(char *)(param_1 + 0x3d4) == '\0') {
    if (*(char *)(param_1 + 0x124) == '\0') {
      if (((*(byte *)(param_1 + 0x45) & 8) == 0) && (iVar1 = *(int *)(param_1 + 0x14c), iVar1 != 0))
      {
        (**(code **)(param_1 + 0x12d0))(param_1,iVar1);
        (**(code **)(param_1 + 0x12c4))(param_1,iVar1);
      }
    }
    else if (*(int *)(param_1 + 0x14c) != 0) {
      (**(code **)(param_1 + 0x12d0))(param_1,*(int *)(param_1 + 0x14c));
      return;
    }
  }
  return;
}

/* FUN_0009b2d9 @ 0x9b2d9 (64 bytes) */
int FUN_0009b2d9(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return;
  }
  *(undefined1 *)(param_1 + 0x3d4) = 0;
  if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
    if (*(char *)(param_1 + 0x1868) == '\0') {
      FUN_00062d7a();
      return;
    }
                    
                    
    (**(code **)(param_1 + 0x11cc))();
    return;
  }
  ((int (*)())FUN_0009b26d)();
  return;
}

/* FUN_0009b319 @ 0x9b319 (6407 bytes) */
void * FUN_0009b319(int param_1,float param_2,int param_3,int *param_4,int *param_5,int param_6,
                   float param_7)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint uVar8;
  byte bVar9;
  int unaff_EBX;
  int unaff_EBP;
  float unaff_ESI;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int unaff_EDI;
  int iVar13;
  int unaff_retaddr;
  byte local_dd;
  int local_d0;
  float local_c4;
  byte *local_c0;
  int local_b4;
  int local_b0;
  uint local_a8;
  uint local_9c;
  uint local_98;
  int local_90;
  undefined1 local_89;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int *local_74;
  int local_70;
  int *local_6c;
  int local_68;
  int *local_64;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_30 [4];
  float local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_88 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(byte *)(param_1 + 0x1874) & 3) != 1) {
    bVar9 = *(byte *)(param_1 + 0x46);
    goto LAB_0009b351;
  }
  if ((*(byte *)(param_1 + 0x8d) & 1) != 0) {
    bVar9 = *(byte *)(param_1 + 0x46);
    goto LAB_0009c631;
  }
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    bVar9 = *(byte *)(param_1 + 0x46);
LAB_0009b351:
    uVar6 = 0;
  }
  else {
    bVar9 = *(byte *)(param_1 + 0x46);
    if ((bVar9 & 4) != 0) {
      if (*(char *)(param_1 + 0x11d3) != '\0') goto LAB_0009c631;
      goto LAB_0009b351;
    }
    if (*(char *)(param_1 + 0x1135) == '\0') goto LAB_0009b351;
LAB_0009c631:
    if ((*(byte *)((int)&switchdataD_000013c0 + param_1) & 1) == 0)
    goto LAB_0009b351;
    uVar6 = 1;
  }
  if (((bVar9 & 0x20) == 0) ||
     ((*(byte *)((int)&switchdataD_000013c0 + param_1) & 2) == 0)) {
    local_89 = 0;
  }
  else {
    local_89 = 1;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x11d2);
  pvVar7 = (void *)FUN_0008dbba(param_1,param_2,uVar6);
  (**(code **)(param_1 + 0x12c0))(param_1,pvVar7,&local_20,param_3);
  if (*(int *)(param_1 + 0x13c) == 1) {
    _memcpy(pvVar7,(void *)(param_1 + 0x19c),0x68);
  }
  else {
    _memcpy(pvVar7,(void *)(param_1 + 0x204),0x68);
  }
  piVar10 = (int *)((int)pvVar7 + 0xa4);
  iVar13 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset(piVar10,-1,0x324);
  param_5[2] = 0;
  if (*(char *)(iVar13 + 0x4301) == '\0') {
    local_20 = (float)(iVar13 + 0x2460);
    if ((((((local_1c == 0 && local_18 == 0) && local_14 == 0) && local_20 == FLOAT_001c5ba4) &&
         (((unaff_EBX == 0 && unaff_EDI == 0) && unaff_EBP == 0) && FLOAT_001c5ba4 == unaff_ESI)) &&
        (((unaff_retaddr == 0 && param_1 == 0) && param_3 == 0) && FLOAT_001c5ba4 == param_2)) &&
        (((param_4 == (int *)0x0 && param_5 == (int *)0x0) && param_6 == 0) &&
        FLOAT_001c5ba4 == param_7)) {
      local_54 = 0;
    }
    else {
      *(undefined4 *)((int)pvVar7 + 0xa4) = 0;
      *(undefined4 *)(*param_5 + param_5[2] * 4) = 0;
      *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
      param_5[2] = param_5[2] + 1;
      local_54 = 4;
    }
    bVar9 = *(byte *)(param_1 + 0x8d);
    if ((bVar9 & 0x10) == 0) goto LAB_0009bb26;
    *(int *)((int)pvVar7 + 0xb4) = local_54;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 1;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)((int)pvVar7 + 0xc4) = local_54 + 4;
    local_54 = local_54 + 8;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 2;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    if ((*(byte *)(param_1 + 0x8d) & 1) != 0) goto LAB_0009bb2e;
LAB_0009b4ff:
    bVar9 = *(byte *)(param_1 + 0x44);
    local_d0 = local_54;
  }
  else {
    bVar9 = *(byte *)(iVar13 + 0x4300);
    local_50 = 0;
    local_48 = 0;
    local_c4 = (float)(iVar13 + 0x1960);
    local_64 = piVar10;
    do {
      if (((1 << (bVar9 & 0x1f)) - 1U & 1 << ((byte)local_48 & 0x1f)) != 0) {
        local_20 = local_c4;
        if ((((((local_1c != 0 || local_18 != 0) || local_14 != 0) || local_c4 != FLOAT_001c5ba4) ||
             (((unaff_EBX != 0 || unaff_EDI != 0) || unaff_EBP != 0) || FLOAT_001c5ba4 != unaff_ESI)
             ) || (((unaff_retaddr != 0 || param_1 != 0) || param_3 != 0) ||
                  FLOAT_001c5ba4 != param_2)) ||
            (((param_4 != (int *)0x0 || param_5 != (int *)0x0) || param_6 != 0) ||
            FLOAT_001c5ba4 != param_7)) {
          *local_64 = local_50;
          local_50 = local_50 + 4;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0;
          *(int *)(param_5[1] + param_5[2] * 4) = local_48;
          param_5[2] = param_5[2] + 1;
        }
        if ((*(byte *)(param_1 + 0x8d) & 0x10) != 0) {
          local_64[4] = local_50;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 1;
          *(int *)(param_5[1] + param_5[2] * 4) = local_48;
          param_5[2] = param_5[2] + 1;
          local_64[8] = local_50 + 4;
          local_50 = local_50 + 8;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 2;
          *(int *)(param_5[1] + param_5[2] * 4) = local_48;
          param_5[2] = param_5[2] + 1;
        }
      }
      local_48 = local_48 + 1;
      local_c4 = (float)((int)local_c4 + 0x40);
      local_64 = local_64 + 1;
    } while (local_48 != 4);
    *(int *)((int)pvVar7 + 0xd4) = local_50;
    local_54 = local_50 + 4;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 3;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    bVar9 = *(byte *)(param_1 + 0x8d);
LAB_0009bb26:
    if ((bVar9 & 1) == 0) goto LAB_0009b4ff;
LAB_0009bb2e:
    if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
      local_a8 = 0xff;
    }
    else if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      local_a8 = (uint)*(byte *)(param_1 + 0x1135);
    }
    else {
      local_a8 = (uint)*(byte *)(param_1 + 0x11d3);
    }
    local_70 = param_1;
    local_4c = 0;
    local_78 = 0;
    local_68 = 0;
    local_74 = piVar10;
    local_6c = piVar10;
    do {
      if ((local_a8 & 1 << ((byte)local_4c & 0x1f)) != 0) {
        iVar11 = param_1 + 0x450 + local_68;
        uVar12 = *(uint *)(local_70 + 0x48);
        if (((uVar12 & 0x20) != 0) && ((ushort)(*(short *)(iVar11 + 0x3c) + 0xdc00U) < 2)) {
          local_6c[0xa9] = local_54;
          local_54 = local_54 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1a;
          *(int *)(param_5[1] + param_5[2] * 4) = local_78;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar12 & 0x40) != 0) && ((ushort)(*(short *)(iVar11 + 0x60) + 0xdc00U) < 2)) {
          local_6c[0xaa] = local_54;
          local_54 = local_54 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1a;
          *(int *)(param_5[1] + param_5[2] * 4) = local_78 + 1;
          param_5[2] = param_5[2] + 1;
        }
        if (((char)uVar12 < '\0') && ((ushort)(*(short *)(iVar11 + 0x84) + 0xdc00U) < 2)) {
          local_6c[0xab] = local_54;
          local_54 = local_54 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1a;
          *(int *)(param_5[1] + param_5[2] * 4) = local_78 + 2;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar12 & 0x100) != 0) && ((ushort)(*(short *)(iVar11 + 0xa8) + 0xdc00U) < 2)) {
          local_6c[0xac] = local_54;
          local_54 = local_54 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1a;
          *(int *)(param_5[1] + param_5[2] * 4) = local_78 + 3;
          param_5[2] = param_5[2] + 1;
        }
        if (*(int *)(local_70 + 0x150) != 0) {
          local_74[0xd] = local_54;
          local_54 = local_54 + 4;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 4;
          *(int *)(param_5[1] + param_5[2] * 4) = local_4c;
          param_5[2] = param_5[2] + 1;
        }
      }
      local_4c = local_4c + 1;
      local_78 = local_78 + 4;
      local_74 = local_74 + 1;
      local_70 = local_70 + 4;
      local_6c = local_6c + 4;
      local_68 = local_68 + 0xcc;
    } while (local_4c != 8);
    bVar9 = *(byte *)(param_1 + 0x44);
    local_d0 = local_54;
  }
  local_54 = local_d0;
  if ((bVar9 & 1) != 0) {
    local_9c = *(uint *)(param_1 + 0x88);
    if (local_9c == 0) {
      bVar4 = false;
      iVar11 = *(int *)(param_1 + 0x13c);
    }
    else {
      local_7c = param_1;
      local_b0 = 0;
      bVar4 = false;
      local_c0 = (byte *)(param_1 + 0x3a8);
      local_80 = iVar13;
      do {
        if (((local_9c & 1) != 0) && (local_dd = *local_c0, (local_dd & 0x3f) != 0)) {
          if ((local_dd & 3) == 2) {
            piVar10[0x16] = local_d0;
            local_d0 = local_d0 + 1;
            *(undefined4 *)(*param_5 + param_5[2] * 4) = 5;
            *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
            param_5[2] = param_5[2] + 1;
            local_dd = *local_c0;
            if ((local_dd & 0xc) != 8) goto LAB_0009b5b4;
LAB_0009c82e:
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (*(uint *)(param_1 + 0x280) < 8) {
                local_b4 = local_d0;
              }
              else {
                piVar10[0x18] = local_d0;
                local_b4 = local_d0 + 1;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1c;
                *(int *)(param_5[1] + param_5[2] * 4) = local_b0 * 2;
                param_5[2] = param_5[2] + 1;
              }
              if ((*(char *)(iVar13 + 0x2d4c) != '\0') && (7 < *(uint *)(param_1 + 0x284))) {
                piVar10[0x19] = local_b4;
                local_b4 = local_b4 + 1;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1c;
                *(uint *)(param_5[1] + param_5[2] * 4) = local_b0 * 2 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            else {
              local_b4 = local_d0;
            }
            if (piVar10[0x18] == -1) {
LAB_0009c8e4:
              piVar10[0x17] = local_b4;
              local_b4 = local_b4 + 1;
              *(undefined4 *)(*param_5 + param_5[2] * 4) = 6;
              *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
              param_5[2] = param_5[2] + 1;
              local_dd = *local_c0;
            }
            else if (*(char *)(iVar13 + 0x2d4c) == '\0') {
              local_dd = *local_c0;
            }
            else {
              if (piVar10[0x19] == -1) goto LAB_0009c8e4;
              local_dd = *local_c0;
            }
          }
          else {
            bVar5 = true;
            if ((local_dd & 3) != 3) {
              bVar5 = bVar4;
            }
            bVar4 = bVar5;
            if ((local_dd & 0xc) == 8) goto LAB_0009c82e;
LAB_0009b5b4:
            local_b4 = local_d0;
          }
          if ((local_dd & 0x30) == 0x20) {
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (7 < *(uint *)(param_1 + 0x288)) {
                piVar10[0x1b] = local_b4;
                local_b4 = local_b4 + 1;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1d;
                *(int *)(param_5[1] + param_5[2] * 4) = local_b0 * 2;
                param_5[2] = param_5[2] + 1;
              }
              if ((*(char *)(iVar13 + 0x2d4c) != '\0') && (7 < *(uint *)(param_1 + 0x28c))) {
                piVar10[0x1c] = local_b4;
                local_b4 = local_b4 + 1;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1d;
                *(uint *)(param_5[1] + param_5[2] * 4) = local_b0 * 2 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            if ((piVar10[0x1b] == -1) ||
               ((*(char *)(iVar13 + 0x2d4c) != '\0' && (piVar10[0x1c] == -1)))) {
              piVar10[0x1a] = local_b4;
              local_b4 = local_b4 + 1;
              *(undefined4 *)(*param_5 + param_5[2] * 4) = 7;
              *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
              param_5[2] = param_5[2] + 1;
            }
          }
          piVar10[0x1e] = local_b4;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 8;
          *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
          param_5[2] = param_5[2] + 1;
          piVar10[0x1f] = local_b4 + 1;
          local_58 = local_b4 + 2;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 9;
          *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
          param_5[2] = param_5[2] + 1;
          local_d0 = local_58;
          if (*(float *)(local_80 + 0x24fc) != 0.0) {
            if ((*local_c0 & 0x40) == 0) {
              cVar2 = *(char *)(local_7c + 0x150c);
            }
            else {
              if ((char)*local_c0 < '\0') {
                piVar10[0x22] = local_58;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xc;
              }
              else {
                piVar10[0x20] = local_58;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 10;
              }
              local_58 = local_b4 + 3;
              *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
              param_5[2] = param_5[2] + 1;
              cVar2 = *(char *)(local_7c + 0x150c);
            }
            local_d0 = local_58;
            if (cVar2 != '\0') {
              piVar10[0x21] = local_58;
              *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xb;
              *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
              param_5[2] = param_5[2] + 1;
              local_d0 = local_58 + 1;
              if (*(float *)(local_80 + 0x251c) != 0.0) {
                piVar10[0x23] = local_58 + 1;
                *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xd;
                *(int *)(param_5[1] + param_5[2] * 4) = local_b0;
                param_5[2] = param_5[2] + 1;
                local_d0 = local_58 + 2;
              }
            }
          }
        }
        local_b0 = local_b0 + 1;
        local_c0 = local_c0 + 4;
        piVar10 = piVar10 + 0xf;
        local_80 = local_80 + 0x80;
        local_7c = local_7c + 0x6c;
        local_9c = local_9c >> 1;
      } while (local_9c != 0);
      iVar11 = *(int *)(param_1 + 0x13c);
    }
    if (iVar11 == 1) {
      if (7 < *(uint *)(param_1 + 0x270)) {
        *(int *)((int)pvVar7 + 0x2d8) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xe;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x278)) {
        *(int *)((int)pvVar7 + 0x2dc) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xf;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x280)) {
        *(int *)((int)pvVar7 + 0x2e0) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x10;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x288)) {
        *(int *)((int)pvVar7 + 0x2ec) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x11;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if ((7 < *(uint *)(param_1 + 0x270)) || (7 < *(uint *)(param_1 + 0x278))) {
        *(int *)((int)pvVar7 + 0x2f8) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x12;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (1 < *(uint *)(param_1 + 0x290)) {
        *(int *)((int)pvVar7 + 800) = local_d0;
        local_d0 = local_d0 + 1;
        *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x13;
        *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (*(char *)(iVar13 + 0x2d4c) != '\0') {
        if (7 < *(uint *)(param_1 + 0x274)) {
          *(int *)((int)pvVar7 + 0x2fc) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xe;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x27c)) {
          *(int *)((int)pvVar7 + 0x300) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0xf;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x284)) {
          *(int *)((int)pvVar7 + 0x304) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x10;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x28c)) {
          *(int *)((int)pvVar7 + 0x310) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x11;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if ((7 < *(uint *)(param_1 + 0x274)) || (7 < *(uint *)(param_1 + 0x27c))) {
          *(int *)((int)pvVar7 + 0x31c) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x12;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (1 < *(uint *)(param_1 + 0x294)) {
          *(int *)((int)pvVar7 + 0x324) = local_d0;
          local_d0 = local_d0 + 1;
          *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x13;
          *(undefined4 *)(param_5[1] + param_5[2] * 4) = 1;
          param_5[2] = param_5[2] + 1;
        }
      }
    }
    *(int *)((int)pvVar7 + 0x328) = local_d0;
    local_54 = local_d0 + 1;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x14;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    if (bVar4) {
      *(int *)((int)pvVar7 + 0x32c) = local_54;
      local_54 = local_d0 + 2;
      *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x1b;
      *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
      param_5[2] = param_5[2] + 1;
      bVar9 = *(byte *)(param_1 + 0x44);
    }
    else {
      bVar9 = *(byte *)(param_1 + 0x44);
    }
  }
  if (((char)bVar9 < '\0') && (*(char *)(param_1 + 0x121) == '\0')) {
    *(int *)((int)pvVar7 + 0x330) = local_54;
    local_54 = local_54 + 1;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x15;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    bVar9 = *(byte *)(param_1 + 0x1874);
  }
  else {
    bVar9 = *(byte *)(param_1 + 0x1874);
  }
  if ((bVar9 & 3) == 2) {
    *(int *)((int)pvVar7 + 0x334) = local_54;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x16;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)((int)pvVar7 + 0x338) = local_54 + 1;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x17;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)((int)pvVar7 + 0x340) = local_54 + 2;
    local_54 = local_54 + 3;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x18;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
  }
  if (*(char *)(param_1 + 300) != '\0') {
    *(int *)((int)pvVar7 + 0x344) = local_54;
    local_54 = local_54 + 1;
    *(undefined4 *)(*param_5 + param_5[2] * 4) = 0x19;
    *(undefined4 *)(param_5[1] + param_5[2] * 4) = 0;
    param_5[2] = param_5[2] + 1;
  }
  *param_4 = local_54;
  if (*(char *)(local_88 + 0x4301) == '\0') {
    local_20 = (float)(local_88 + 0x1960);
    if ((((((local_1c == 0 && local_18 == 0) && local_14 == 0) && local_20 == FLOAT_001c5ba4) &&
         (((unaff_EBX == 0 && unaff_EDI == 0) && unaff_EBP == 0) && FLOAT_001c5ba4 == unaff_ESI)) &&
        (((unaff_retaddr == 0 && param_1 == 0) && param_3 == 0) && FLOAT_001c5ba4 == param_2)) &&
        (((param_4 == (int *)0x0 && param_5 == (int *)0x0) && param_6 == 0) &&
        FLOAT_001c5ba4 == param_7)) {
      FUN_0008dd2f(pvVar7,local_89,uVar1);
    }
    else {
      FUN_00091fe9(pvVar7,local_89,uVar1);
    }
    if (*(char *)(param_1 + 0x12a) == '\0') goto LAB_0009c104;
    FUN_000929fa(pvVar7);
    if (*(char *)(param_1 + 0x128) == '\0') goto LAB_0009c114;
LAB_0009bdb0:
    FUN_0008ec28(pvVar7);
    cVar2 = *(char *)(param_1 + 0x44);
  }
  else {
    if (*(char *)(param_1 + 0x90) != '\0') {
      uVar12 = 0;
      iVar13 = param_1;
      do {
        local_30[uVar12] = (uint)*(byte *)(iVar13 + 0x13a9);
        uVar12 = uVar12 + 1;
        iVar13 = iVar13 + 1;
      } while (uVar12 < *(byte *)(param_1 + 0x90));
    }
    FUN_00091576(pvVar7,*(undefined1 *)(param_1 + 0x91),*(undefined1 *)(local_88 + 0x4302));
    if (*(char *)(param_1 + 0x129) == '\0') {
      FUN_0008ec41(pvVar7,local_30,*(undefined1 *)(param_1 + 0x91),
                   *(undefined1 *)(local_88 + 0x4302),local_89,uVar1);
      cVar2 = *(char *)(param_1 + 0x12a);
    }
    else {
      FUN_00090148(pvVar7,local_30,*(undefined1 *)(param_1 + 0x91),
                   *(undefined1 *)(local_88 + 0x4302),*(char *)(param_1 + 0x90) == '\x02');
      FUN_000915a1(pvVar7,local_89,uVar1);
      cVar2 = *(char *)(param_1 + 0x12a);
    }
    if (cVar2 != '\0') {
      FUN_0008e52a(pvVar7,local_30,*(undefined1 *)(param_1 + 0x91),
                   *(undefined1 *)(local_88 + 0x4302));
    }
LAB_0009c104:
    if (*(char *)(param_1 + 0x128) != '\0') goto LAB_0009bdb0;
LAB_0009c114:
    if (*(char *)(param_1 + 300) != '\0') {
      FUN_0008ebfe(pvVar7);
    }
    cVar2 = *(char *)(param_1 + 0x44);
  }
  if (((cVar2 < '\0') && (*(char *)(param_1 + 0x121) == '\0')) &&
     ((*(int *)((int)pvVar7 + 0x3d8) == 0 || ((*(byte *)(param_1 + 0x46) & 4) == 0)))) {
    sVar3 = *(short *)(local_88 + 0x2e04);
    if (sVar3 == 0x801) {
      FUN_00092a24(pvVar7);
    }
    else if (sVar3 == 0x2601) {
      FUN_00098f23(pvVar7);
    }
    else if (sVar3 == 0x800) {
      FUN_0009988b(pvVar7);
    }
  }
  if ((*(byte *)(param_1 + 0x45) & 0x40) == 0) {
    if ((*(byte *)(param_1 + 0x8d) & 1) != 0) {
      uVar12 = (uint)*(byte *)(param_1 + 0x13b0);
      if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)*(byte *)(param_1 + 0x13b0)) {
        uVar12 = (uint)*(byte *)(param_1 + 0x2b);
      }
      if (uVar12 != 0) {
        local_84 = param_1;
        uVar8 = 0;
        iVar13 = param_1;
        do {
          if (*(char *)(iVar13 + 0x1438) != '\0') {
            FUN_00092aa0(pvVar7,uVar8,0,uVar8,*(undefined1 *)(local_84 + 0x150),uVar8,
                         *(ushort *)(param_1 + 0x187c + uVar8 * 2) >> 2 & 0xfff);
          }
          uVar8 = uVar8 + 1;
          iVar13 = iVar13 + 1;
          local_84 = local_84 + 4;
        } while (uVar12 != uVar8);
      }
    }
  }
  else {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      bVar9 = *(byte *)(param_1 + 0x1135);
    }
    else {
      bVar9 = *(byte *)(param_1 + 0x11d3);
    }
    local_98 = (uint)bVar9;
    if (*(char *)(param_1 + 0x13b0) != '\0') {
      iVar11 = 0;
      iVar13 = param_1;
      do {
        while ((local_98 & 1 << ((byte)iVar11 & 0x1f)) == 0) {
          iVar11 = iVar11 + 1;
          iVar13 = iVar13 + 4;
          if ((int)(uint)*(byte *)(param_1 + 0x13b0) <= iVar11) goto LAB_0009be83;
        }
        FUN_00092aa0(pvVar7,iVar11,0,iVar11,*(undefined1 *)(iVar13 + 0x150),iVar11,
                     *(ushort *)(param_1 + 0x187c + iVar11 * 2) >> 2 & 0xfff);
        iVar11 = iVar11 + 1;
        iVar13 = iVar13 + 4;
      } while (iVar11 < (int)(uint)*(byte *)(param_1 + 0x13b0));
    }
  }
LAB_0009be83:
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
    FUN_0008de84(pvVar7,3,0,0);
    if ((*(byte *)(param_1 + 0x45) & 0x85) != 0) {
      FUN_0008de84(pvVar7,4,1,0);
      bVar9 = *(byte *)(param_1 + 0x1874);
      goto joined_r0x0009c51c;
    }
  }
  else {
    FUN_00093589(pvVar7);
    uVar12 = *(uint *)(param_1 + 0x88);
    if (uVar12 == 0) {
      local_90 = 0;
    }
    else {
      iVar13 = 0;
      local_44 = 0;
      uVar8 = uVar12;
      do {
        if (((uVar8 & 1) != 0) && ((*(byte *)(param_1 + 0x3a8 + iVar13 * 4) & 0x3f) != 0)) {
          local_44 = iVar13;
        }
        iVar13 = iVar13 + 1;
        uVar8 = uVar8 >> 1;
      } while (uVar8 != 0);
      local_90 = 0;
      iVar13 = 0;
      do {
        if ((uVar12 & 1) != 0) {
          bVar9 = *(byte *)(param_1 + 0x3a8 + iVar13 * 4);
          if ((bVar9 & 0x3f) != 0) {
            if (*(float *)(local_88 + 0x24fc) == 0.0) {
              FUN_00093e6f(pvVar7,iVar13,local_90 == 0,iVar13 == local_44,bVar9 & 3,bVar9 >> 2 & 3,
                           bVar9 >> 4 & 3);
            }
            else {
              FUN_000956af(pvVar7,iVar13,local_90 == 0,iVar13 == local_44,bVar9 >> 6 & 1,bVar9 >> 7,
                           *(byte *)(param_1 + iVar13 * 4 + 0x3a9) & 1,bVar9 & 3,bVar9 >> 2 & 3,
                           bVar9 >> 4 & 3);
            }
            local_90 = local_90 + 1;
          }
        }
        iVar13 = iVar13 + 1;
        local_88 = local_88 + 0x80;
        uVar12 = uVar12 >> 1;
      } while (uVar12 != 0);
    }
    FUN_000994eb(pvVar7,local_90);
  }
  bVar9 = *(byte *)(param_1 + 0x1874);
joined_r0x0009c51c:
  if ((bVar9 & 3) == 2) {
    FUN_00097bb2(pvVar7,2,*(float *)(param_1 + 0x114) == 0.0);
  }
  if ((*(byte *)(param_1 + 0x46) & 0x10) == 0) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      FUN_00099907(pvVar7,*(undefined1 *)(param_1 + 0x120));
    }
  }
  else if (*(int *)((int)pvVar7 + 0x3d8) == 0) {
    FUN_00099907(pvVar7,*(undefined1 *)(param_1 + 0x11d1));
  }
  else {
    FUN_00098504(pvVar7);
  }
  iVar13 = FUN_00098884(pvVar7);
  if (iVar13 == 6) {
    *(undefined1 *)(param_1 + 0x126) = 1;
  }
  return pvVar7;
}

/* FUN_0009cc20 @ 0x9cc20 (479 bytes) */
int FUN_0009cc20(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *local_30;
  undefined *local_18;
  uint local_14;
  uint *local_10;
  
  puVar1 = *(undefined **)(param_1 + 0x111c);
  if (puVar1 != ((unsigned char *)0x0000fb2f)) {
    puVar2 = ((unsigned char *)0x0000fb2f);
    if (puVar1 + param_2 < ((unsigned char *)0x0000fb30)) {
      puVar2 = puVar1 + param_2;
    }
    *(undefined **)(param_1 + 0x111c) = puVar2;
    iVar3 = (**(code **)(param_1 + 0x10))(1,(int)puVar2 << 2);
    if (puVar1 == (undefined *)0x0) {
      iVar4 = *(int *)(param_1 + 0x1118);
    }
    else {
      local_18 = (undefined *)0x0;
      iVar4 = *(int *)(param_1 + 0x1118);
      do {
        puVar10 = *(uint **)(iVar4 + (int)local_18 * 4);
        if (puVar10 != (uint *)0x0) {
          local_14 = *(uint *)(param_1 + 0x111c);
          local_10 = puVar10 + 0xc;
          puVar7 = puVar10 + 0xb;
          puVar8 = puVar10;
          if (local_10 < puVar7) goto LAB_0009cd7e;
LAB_0009ccb5:
          uVar9 = 0;
          puVar5 = puVar10;
          do {
            puVar8 = puVar7;
            uVar9 = uVar9 ^ *puVar5 ^ (puVar5[1] >> 0x1d | puVar5[1] << 3) ^
                    (puVar5[2] >> 0x1a | puVar5[2] << 6) ^ (puVar5[3] >> 0x17 | puVar5[3] << 9) ^
                    (puVar5[4] >> 0x14 | puVar5[4] << 0xc) ^ (puVar5[5] >> 0x11 | puVar5[5] << 0xf)
                    ^ (puVar5[6] >> 0xe | puVar5[6] << 0x12) ^
                    (puVar5[7] >> 0xb | puVar5[7] << 0x15) ^ (puVar5[8] >> 8 | puVar5[8] << 0x18) ^
                    (puVar5[9] >> 5 | puVar5[9] << 0x1b) ^ (puVar5[10] >> 2 | puVar5[10] << 0x1e);
            puVar5 = puVar8;
            puVar7 = puVar8 + 0xb;
          } while (puVar8 + 0xb <= local_10);
          local_30 = puVar8 + 5;
          puVar7 = puVar10;
          if (local_30 <= local_10) goto LAB_0009cd8d;
          do {
            bVar6 = 0;
            local_30 = puVar8;
            while( true ) {
              for (; local_30 < local_10; local_30 = local_30 + 1) {
                uVar9 = uVar9 ^ (*local_30 << (bVar6 & 0x1f) | *local_30 >> 0x20 - (bVar6 & 0x1f));
                bVar6 = bVar6 + 3;
              }
              puVar10 = (uint *)puVar7[0x17];
              puVar8 = (uint *)(iVar3 + (uVar9 % local_14) * 4);
              puVar7[0x17] = *puVar8;
              *puVar8 = (uint)puVar7;
              if (puVar10 == (uint *)0x0) {
                iVar4 = *(int *)(param_1 + 0x1118);
                goto LAB_0009cde4;
              }
              local_14 = *(uint *)(param_1 + 0x111c);
              local_10 = puVar10 + 0xc;
              puVar7 = puVar10 + 0xb;
              puVar8 = puVar10;
              if (puVar7 <= local_10) goto LAB_0009ccb5;
LAB_0009cd7e:
              uVar9 = 0;
              local_30 = puVar8 + 5;
              puVar7 = puVar8;
              if (local_10 < local_30) break;
LAB_0009cd8d:
              uVar9 = uVar9 ^ *puVar8 ^ (puVar8[1] >> 0x1d | puVar8[1] << 3) ^
                      (puVar8[2] >> 0x1a | puVar8[2] << 6) ^ (puVar8[3] >> 0x17 | puVar8[3] << 9) ^
                      (puVar8[4] >> 0x14 | puVar8[4] << 0xc);
              bVar6 = 0xf;
            }
          } while( true );
        }
LAB_0009cde4:
        local_18 = local_18 + 1;
      } while (puVar1 != local_18);
    }
    (**(code **)(param_1 + 0x18))(iVar4);
    *(int *)(param_1 + 0x1118) = iVar3;
  }
  return;
}

/* FUN_0009cdff @ 0x9cdff (639 bytes) */
int FUN_0009cdff(param_1, param_2)
  int param_1;
  uint *param_2;
{
  char cVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  uint *puVar10;
  bool bVar11;
  char *local_30;
  int local_14;
  
  cVar1 = *(char *)(param_1 + 0x1120);
  if (cVar1 == '\0') {
    puVar10 = param_2 + 0xc;
    if (puVar10 < param_2 + 0xb) {
      uVar7 = 0;
      puVar5 = param_2 + 5;
      puVar6 = param_2;
      if (puVar5 <= puVar10) goto LAB_0009cfe6;
LAB_0009ceee:
      bVar3 = 0;
      puVar5 = puVar6;
    }
    else {
      uVar7 = 0;
      puVar5 = param_2;
      puVar2 = param_2 + 0xb;
      do {
        puVar6 = puVar2;
        uVar7 = uVar7 ^ *puVar5 ^ (puVar5[1] >> 0x1d | puVar5[1] << 3) ^
                (puVar5[2] >> 0x1a | puVar5[2] << 6) ^ (puVar5[3] >> 0x17 | puVar5[3] << 9) ^
                (puVar5[4] >> 0x14 | puVar5[4] << 0xc) ^ (puVar5[5] >> 0x11 | puVar5[5] << 0xf) ^
                (puVar5[6] >> 0xe | puVar5[6] << 0x12) ^ (puVar5[7] >> 0xb | puVar5[7] << 0x15) ^
                (puVar5[8] >> 8 | puVar5[8] << 0x18) ^ (puVar5[9] >> 5 | puVar5[9] << 0x1b) ^
                (puVar5[10] >> 2 | puVar5[10] << 0x1e);
        puVar5 = puVar6;
        puVar2 = puVar6 + 0xb;
      } while (puVar6 + 0xb <= puVar10);
      puVar5 = puVar6 + 5;
      if (puVar10 < puVar5) goto LAB_0009ceee;
LAB_0009cfe6:
      uVar7 = uVar7 ^ *puVar6 ^ (puVar6[1] >> 0x1d | puVar6[1] << 3) ^
              (puVar6[2] >> 0x1a | puVar6[2] << 6) ^ (puVar6[3] >> 0x17 | puVar6[3] << 9) ^
              (puVar6[4] >> 0x14 | puVar6[4] << 0xc);
      bVar3 = 0xf;
    }
    for (; puVar5 < puVar10; puVar5 = puVar5 + 1) {
      uVar7 = uVar7 ^ (*puVar5 << (bVar3 & 0x1f) | *puVar5 >> 0x20 - (bVar3 & 0x1f));
      bVar3 = bVar3 + 3;
    }
    local_30 = *(char **)(*(int *)(param_1 + 0x1118) + (uVar7 % *(uint *)(param_1 + 0x111c)) * 4);
    if (*(char *)(param_1 + 0x2f) == '\0') goto LAB_0009ce4b;
LAB_0009cf24:
    if (local_30 == (char *)0x0) {
LAB_0009d012:
      local_14 = 0;
    }
    else {
      local_14 = 0;
      bVar11 = false;
      do {
        iVar4 = 0x18;
        pcVar8 = local_30;
        puVar10 = param_2;
        do {
          pcVar9 = pcVar8;
          puVar5 = puVar10;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          puVar5 = (uint *)((int)puVar10 + 1);
          pcVar9 = pcVar8 + 1;
          bVar11 = *pcVar8 == (char)*puVar10;
          pcVar8 = pcVar9;
          puVar10 = puVar5;
        } while (bVar11);
        iVar4 = 0;
        if (!bVar11) {
          iVar4 = (uint)(byte)pcVar9[-1] - (uint)*(byte *)((int)puVar5 - 1);
        }
        if (iVar4 == 0) {
          return local_30;
        }
        local_30 = *(char **)(local_30 + 0x5c);
        local_14 = local_14 + 1;
        bVar11 = local_30 == (char *)0x0;
      } while (!bVar11);
    }
  }
  else {
    local_30 = *(char **)(*(int *)(param_1 + 0x1118) +
                         ((*param_2 + param_2[2] + param_2[3]) % *(uint *)(param_1 + 0x111c)) * 4);
    if (*(char *)(param_1 + 0x2f) != '\0') goto LAB_0009cf24;
LAB_0009ce4b:
    if (local_30 == (char *)0x0) goto LAB_0009d012;
    local_14 = 0;
    bVar11 = false;
    do {
      iVar4 = 0x30;
      pcVar8 = local_30;
      puVar10 = param_2;
      do {
        pcVar9 = pcVar8;
        puVar5 = puVar10;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        puVar5 = (uint *)((int)puVar10 + 1);
        pcVar9 = pcVar8 + 1;
        bVar11 = *pcVar8 == (char)*puVar10;
        pcVar8 = pcVar9;
        puVar10 = puVar5;
      } while (bVar11);
      iVar4 = 0;
      if (!bVar11) {
        iVar4 = (uint)(byte)pcVar9[-1] - (uint)*(byte *)((int)puVar5 - 1);
      }
      if (iVar4 == 0) {
        return local_30;
      }
      local_30 = *(char **)(local_30 + 0x5c);
      local_14 = local_14 + 1;
      bVar11 = local_30 == (char *)0x0;
    } while (!bVar11);
  }
  if ((cVar1 != '\0') && (4 < local_14)) {
LAB_0009d01e:
    ((int (*)())FUN_0009cc20)();
    *(undefined1 *)(param_1 + 0x1120) = 0;
    return (char *)0x0;
  }
  if ((7 < local_14) && (*(undefined **)(param_1 + 0x111c) <= ((unsigned char *)0x0000fb2e))) {
    if (cVar1 != '\0') goto LAB_0009d01e;
    ((int (*)())FUN_0009cc20)();
  }
  return (char *)0x0;
}

/* FUN_0009d07e @ 0x9d07e (195 bytes) */
int FUN_0009d07e(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int *piVar1;
  uint local_210;
  int local_88;
  
  piVar1 = *(int **)(param_2 + 0x50);
  if (piVar1[2] != 0) {
    local_210 = 0;
    local_88 = 0;
    do {
      if (*(uint *)(*piVar1 + local_88) < 0x1e) {
                    
                    
        (*(code *)(*(int *)(((unsigned char *)0x0009d114) + *(int *)(*piVar1 + local_88) * 4) + 0x9d08f))();
        return;
      }
      local_210 = local_210 + 1;
      local_88 = local_88 + 4;
    } while (local_210 < (uint)piVar1[2]);
  }
  return;
}

/* FUN_0009f1b0 @ 0x9f1b0 (92 bytes) */
int FUN_0009f1b0(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 != 0) {
    bVar1 = false;
    uVar2 = 3;
    iVar3 = 0x48;
    while (uVar2 < *(uint *)(param_2 + 4)) {
      while( true ) {
        if (bVar1) {
          return uVar2;
        }
        if (param_3 == *(int *)(iVar3 + *(int *)(param_2 + 8))) break;
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 0x18;
        if (*(uint *)(param_2 + 4) <= uVar2) goto LAB_0009f1f6;
      }
      bVar1 = true;
    }
LAB_0009f1f6:
    if (bVar1) {
      return uVar2;
    }
  }
  return 0;
}

/* FUN_0009f20c @ 0x9f20c (102 bytes) */
int FUN_0009f20c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  *(undefined4 *)(param_1 + 0x1124) = 0xffffffff;
  **(undefined1 **)(param_1 + 0x1128) = 0;
  if (((0 < param_4) && (param_3 == 0x8875)) && (param_2 == 0x8804)) {
    FUN_00088a7f();
    return;
  }
  return;
}

/* FUN_0009f272 @ 0x9f272 (49 bytes) */
int FUN_0009f272(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  param_2[4] = 0;
  param_2[5] = 0;
  return;
}

/* FUN_0009f2a3 @ 0x9f2a3 (403 bytes) */
int FUN_0009f2a3(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if ((param_2 == 0x8620) || (param_2 == 0x8804)) {
    iVar1 = *(int *)(param_1 + 0x112c);
    iVar3 = ((int (*)())FUN_0009f1b0)();
    if (iVar3 == 0) {
      if (param_3 != 0) {
        uVar4 = *(uint *)(iVar1 + 4);
        if ((uVar4 & 7) == 0) {
          iVar3 = (**(code **)(param_1 + 0xc))(uVar4 * 0x18 + 0xc0);
          if (iVar3 == 0) {
            return;
          }
          (**(code **)(param_1 + 0x1344))
                    (iVar3,*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 4) * 0x18);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 8));
          *(int *)(iVar1 + 8) = iVar3;
          uVar4 = *(uint *)(iVar1 + 4);
        }
        ((int (*)())FUN_0009f272)(param_1,*(int *)(iVar1 + 8) + uVar4 * 0x18);
        *(int *)(*(int *)(iVar1 + 8) + 4 + *(int *)(iVar1 + 4) * 0x18) = param_2;
        *(int *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 4) * 0x18) = param_3;
        if (param_2 == 0x8804) {
          iVar3 = *(int *)(iVar1 + 4);
          iVar2 = *(int *)(iVar1 + 8);
          uVar5 = (**(code **)(param_1 + 0xc))(0x78);
          *(undefined4 *)(iVar2 + iVar3 * 0x18 + 0x14) = uVar5;
          FUN_00088843(param_1,*(undefined4 *)
                                (*(int *)(iVar1 + 8) + 0x14 + *(int *)(iVar1 + 4) * 0x18));
          FUN_000887e9(param_1,*(undefined4 *)(iVar1 + 4));
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
        }
        else {
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
        }
        return;
      }
    }
    else if (param_2 != *(int *)(*(int *)(iVar1 + 8) + 4 + iVar3 * 0x18)) {
      return;
    }
    if (param_2 == 0x8804) {
      FUN_000887e9();
      return;
    }
  }
  return;
}

/* FUN_0009f436 @ 0x9f436 (86 bytes) */
int FUN_0009f436(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_10;
  
  if (0 < param_2) {
    piVar1 = *(int **)(param_1 + 0x112c);
    iVar3 = *piVar1;
    local_10 = 0;
    do {
      while( true ) {
        iVar2 = ((int (*)())FUN_0009f1b0)();
        if (iVar2 == 0) break;
        iVar3 = iVar3 + 1;
      }
      *(int *)(param_3 + local_10 * 4) = iVar3;
      iVar3 = iVar3 + 1;
      local_10 = local_10 + 1;
    } while (param_2 != local_10);
    *piVar1 = iVar3;
  }
  return;
}

/* FUN_0009f48c @ 0x9f48c (230 bytes) */
int FUN_0009f48c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0x8620) {
    iVar1 = *(int *)(param_1 + 0x14a0);
    iVar2 = *(int *)(param_1 + 0x112c);
  }
  else {
    if (param_2 != 0x8804) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x1270);
    iVar2 = *(int *)(param_1 + 0x112c);
  }
  if (param_3 == 0x8627) {
    *param_4 = *(uint *)(*(int *)(iVar2 + 8) + 0xc + iVar1 * 0x18);
    return;
  }
  if (param_3 == 0x8876) {
    *param_4 = *(uint *)(*(int *)(iVar2 + 8) + 8 + iVar1 * 0x18);
    return;
  }
  if (param_3 != 0x8677) {
    if (param_2 == 0x8804) {
      iVar1 = *(int *)(*(int *)(iVar2 + 8) + 0x14 + iVar1 * 0x18);
      switch(param_3) {
      case 0x8805:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x6c);
        return;
      case 0x8806:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x70);
        return;
      case 0x8807:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x74);
        return;
      case 0x8808:
        *param_4 = *(uint *)(iVar1 + 0x54);
        return;
      case 0x8809:
        *param_4 = *(uint *)(iVar1 + 0x58);
        return;
      case 0x880a:
        *param_4 = *(uint *)(iVar1 + 0x5c);
        return;
      case 0x880b:
        *param_4 = *(uint *)(param_1 + 0x1204);
        return;
      case 0x880c:
        *param_4 = *(uint *)(param_1 + 0x1208);
        return;
      case 0x880d:
        *param_4 = *(uint *)(param_1 + 0x120c);
        return;
      case 0x880e:
        *param_4 = *(uint *)(param_1 + 0x1210);
        return;
      case 0x880f:
        *param_4 = *(uint *)(param_1 + 0x1214);
        return;
      case 0x8810:
        *param_4 = *(uint *)(param_1 + 0x1218);
        return;
      case 0x88a0:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x68);
        return;
      case 0x88a1:
        *param_4 = *(uint *)(param_1 + 0x11d4);
        return;
      case 0x88a2:
        *param_4 = *(uint *)(iVar1 + 0x50);
        return;
      case 0x88a3:
        *param_4 = *(uint *)(param_1 + 0x11d8);
        return;
      case 0x88a4:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x88);
        return;
      case 0x88a5:
        *param_4 = *(uint *)(param_1 + 0x11dc);
        return;
      case 0x88a6:
        *param_4 = *(uint *)(iVar1 + 0x68);
        return;
      case 0x88a7:
        *param_4 = *(uint *)(param_1 + 0x11e0);
        return;
      case 0x88a8:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x84);
        return;
      case 0x88a9:
        *param_4 = *(uint *)(param_1 + 0x11e4);
        return;
      case 0x88aa:
        *param_4 = *(uint *)(iVar1 + 100);
        return;
      case 0x88ab:
        *param_4 = *(uint *)(param_1 + 0x11e8);
        return;
      case 0x88ac:
        *param_4 = *(uint *)(*(int *)(iVar1 + 0x74) + 0x7c);
        return;
      case 0x88ad:
        *param_4 = *(uint *)(param_1 + 0x11ec);
        return;
      case 0x88ae:
        *param_4 = *(uint *)(iVar1 + 0x60);
        return;
      case 0x88af:
        *param_4 = *(uint *)(param_1 + 0x11f0);
        return;
      case 0x88b0:
      case 0x88b2:
        *param_4 = 0;
        return;
      case 0x88b1:
        *param_4 = *(uint *)(param_1 + 0x11f4);
        return;
      case 0x88b3:
        *param_4 = *(uint *)(param_1 + 0x11f8);
        return;
      case 0x88b4:
        *param_4 = *(uint *)(param_1 + 0x11fc);
        return;
      case 0x88b5:
        *param_4 = *(uint *)(param_1 + 0x1200);
        return;
      case 0x88b6:
        *param_4 = (uint)*(byte *)(iVar1 + 0x6c);
        return;
      }
    }
    return;
  }
  *param_4 = *(uint *)(*(int *)(iVar2 + 8) + iVar1 * 0x18);
  return;
}

/* FUN_0009fa14 @ 0x9fa14 (114 bytes) */
int FUN_0009fa14(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = param_2[5];
  if (iVar1 != 0) {
    if (param_2[1] == 0x8804) {
      FUN_00088952(param_1,iVar1);
      iVar1 = param_2[5];
    }
    (**(code **)(param_1 + 0x18))(iVar1);
    param_2[5] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(param_1 + 0x18))(param_2[4]);
    param_2[4] = 0;
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  return;
}

/* FUN_0009fa86 @ 0x9fa86 (203 bytes) */
int FUN_0009fa86(param_1)
  int param_1;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint local_10;
  
  FUN_00088834(param_1);
  if (*(int *)(param_1 + 0x1128) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_1 + 0x1128));
    *(undefined4 *)(param_1 + 0x1128) = 0;
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x112c) + 0xc);
  *piVar1 = *piVar1 + -1;
  if (*(int *)(*(int *)(param_1 + 0x112c) + 0xc) == 0) {
    iVar2 = *(int *)(param_1 + 0x112c);
    if (*(int *)(iVar2 + 4) == 0) {
      *(undefined4 *)(iVar2 + 4) = 0;
      iVar3 = *(int *)(iVar2 + 8);
    }
    else {
      local_10 = 0;
      iVar3 = 0;
      do {
        ((int (*)())FUN_0009fa14)(param_1,iVar3 + *(int *)(iVar2 + 8));
        local_10 = local_10 + 1;
        iVar3 = iVar3 + 0x18;
      } while (local_10 < *(uint *)(iVar2 + 4));
      *(undefined4 *)(iVar2 + 4) = 0;
      iVar3 = *(int *)(iVar2 + 8);
    }
    if (iVar3 != 0) {
      (**(code **)(param_1 + 0x18))(iVar3);
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    (**(code **)(param_1 + 0x18))(iVar2);
    *(undefined4 *)(param_1 + 0x112c) = 0;
  }
  return;
}

/* FUN_0009fb51 @ 0x9fb51 (378 bytes) */
int FUN_0009fb51(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int *local_1c;
  int local_18;
  
  if (0 < param_2) {
    iVar1 = *(int *)(param_1 + 0x112c);
    local_18 = 0;
    local_1c = param_3;
    do {
      uVar3 = ((int (*)())FUN_0009f1b0)();
      if (uVar3 != 0) {
        iVar4 = *(int *)(iVar1 + 8);
        iVar2 = uVar3 * 0x18;
        if ((*(int *)(iVar4 + 4 + iVar2) == 0x8804) &&
           (*(int *)(iVar4 + *(int *)(param_1 + 0x1270) * 0x18) == *local_1c)) {
          ((int (*)())FUN_0009f2a3)(param_1,0x8804,0);
          iVar4 = *(int *)(iVar1 + 8);
        }
        ((int (*)())FUN_0009fa14)(param_1,iVar2 + iVar4);
        pvVar5 = (void *)(*(int *)(iVar1 + 8) + iVar2);
        _memmove(pvVar5,(void *)((int)pvVar5 + 0x18),(*(int *)(iVar1 + 4) - uVar3) * 0x18 - 0x18);
        iVar2 = *(int *)(iVar1 + 4) + -1;
        *(int *)(iVar1 + 4) = iVar2;
        *(undefined4 *)(*(int *)(iVar1 + 8) + 8 + iVar2 * 0x18) = 0;
        *(undefined4 *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 4) * 0x18) = 0;
        *(undefined4 *)(*(int *)(iVar1 + 8) + 0xc + *(int *)(iVar1 + 4) * 0x18) = 0xffffffff;
        *(undefined4 *)(*(int *)(iVar1 + 8) + 0x10 + *(int *)(iVar1 + 4) * 0x18) = 0;
        *(undefined4 *)(*(int *)(iVar1 + 8) + 4 + *(int *)(iVar1 + 4) * 0x18) = 0;
        *(undefined4 *)(*(int *)(iVar1 + 8) + 0x14 + *(int *)(iVar1 + 4) * 0x18) = 0;
        if (uVar3 < *(uint *)(param_1 + 0x1270)) {
          *(uint *)(param_1 + 0x1270) = *(uint *)(param_1 + 0x1270) - 1;
        }
      }
      local_18 = local_18 + 1;
      local_1c = local_1c + 1;
    } while (param_2 != local_18);
  }
  return;
}

/* FUN_0009fccb @ 0x9fccb (116 bytes) */
int FUN_0009fccb(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x112c);
  puVar1[1] = 3;
  *puVar1 = 1;
  puVar1[4] = 1;
  puVar1[3] = 1;
  uVar2 = (**(code **)(param_1 + 0xc))(0xc0);
  puVar1[2] = uVar2;
  *(undefined4 *)(param_1 + 0x1124) = 0xffffffff;
  puVar3 = (undefined1 *)(**(code **)(param_1 + 0xc))(1);
  *(undefined1 **)(param_1 + 0x1128) = puVar3;
  *puVar3 = 0;
  *(undefined4 *)(param_1 + 0x1130) = 0;
  FUN_0008a49a();
  return;
}

/* FUN_0009fd3f @ 0x9fd3f (5 bytes) */
int FUN_0009fd3f()
{
  return;
}

/* FUN_0009fd44 @ 0x9fd44 (121 bytes) */
int FUN_0009fd44(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  *(code **)(param_1 + 0x115c) = FUN_0009fd3f;
  *(code **)(param_1 + 0x1160) = FUN_0009fd3f;
  *(undefined **)(param_1 + 0x1164) = PTR_LAB_000b1ae8_4_002132e9;
  ((int (*)())FUN_000a0c5d)(param_1);
  iVar2 = 0;
  uVar1 = *(uint *)(param_1 + 0x27bc);
  iVar3 = param_1;
  do {
    *(undefined4 *)(iVar3 + 0x27c0) = 0xff;
    uVar1 = 1 << ((byte)iVar2 & 0x1f) | uVar1;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 != 0x10);
  *(uint *)(param_1 + 0x27bc) = uVar1;
  return 1;
}

/* FUN_0009fdbd @ 0x9fdbd (9 bytes) */
int FUN_0009fdbd()
{
  ((int (*)())FUN_000a0d59)();
  return;
}

/* FUN_0009fdc6 @ 0x9fdc6 (21 bytes) */
int FUN_0009fdc6(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return (-(uint)(param_2 == '\0') & 0xfffffedd) + 0x125;
}

/* FUN_0009fddb @ 0x9fddb (43 bytes) */
int FUN_0009fddb(param_1)
  int param_1;
{
  if (((param_1 != -0x1134) && (*(int *)(param_1 + 0x1144) != 0)) &&
     (*(char *)(*(int *)(param_1 + 0x1144) + 0x74) != '\0')) {
    return 1;
  }
  return 0;
}

/* FUN_0009fe06 @ 0x9fe06 (204 bytes) */
int FUN_0009fe06(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = param_1;
  iVar1 = 1;
  do {
    iVar4 = iVar1;
    if (*(char *)(param_2 + -1 + iVar4) == '\0') {
      uVar3 = 0;
LAB_0009fe28:
      *(undefined4 *)(iVar2 + 0x48) = uVar3;
    }
    else {
      iVar1 = *(int *)(param_3 + -4 + iVar4 * 4);
      if (iVar1 == 1) {
        uVar3 = 2;
        goto LAB_0009fe28;
      }
      uVar3 = 1;
      if (iVar1 != 2) {
        uVar3 = 8;
      }
      *(undefined4 *)(iVar2 + 0x48) = uVar3;
    }
    iVar2 = iVar2 + 4;
    iVar1 = iVar4 + 1;
    if (iVar4 + 1 == 0x11) {
      iVar2 = *(int *)(param_1 + 0x1154);
      if (*(int *)(iVar2 + 4) != 0) {
        uVar6 = 0;
        uVar5 = iVar4 + 1U & 0xffff0000;
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(iVar2 + 0x88) + 0x70 + uVar5) +
                          *(int *)(param_1 + 0x113c) * 4);
          if (iVar1 != 0) {
            *(undefined4 *)(iVar1 + 0x15d0) = 1;
            iVar2 = *(int *)(param_1 + 0x1154);
          }
          uVar6 = uVar6 + 1;
          uVar5 = uVar5 + 0x78;
        } while (uVar6 < *(uint *)(iVar2 + 4));
      }
      *(undefined4 *)(param_1 + 0x27bc) = 0;
      return;
    }
  } while( true );
}

/* FUN_0009fed2 @ 0x9fed2 (36 bytes) */
int FUN_0009fed2(param_1)
  int param_1;
{
  if (((param_1 != -0x1134) && (*(int *)(param_1 + 0x1144) != 0)) &&
     (*(char *)(*(int *)(param_1 + 0x1144) + 0x74) != '\0')) {
    return *(undefined1 *)(param_1 + 0x1135);
  }
  return 0;
}

/* FUN_0009fef6 @ 0x9fef6 (44 bytes) */
int FUN_0009fef6(param_1)
  int param_1;
{
  int iVar1;
  
  if (((param_1 != -0x1134) && (iVar1 = *(int *)(param_1 + 0x1144), iVar1 != 0)) &&
     (*(char *)(iVar1 + 0x74) != '\0')) {
    return (-(uint)(*(char *)(iVar1 + 0x6c) == '\0') & 0xfffffffe) + 3;
  }
  return 0;
}

/* FUN_0009ff22 @ 0x9ff22 (135 bytes) */
int FUN_0009ff22(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int local_18;
  int local_14;
  
  *(undefined1 *)(param_1 + 0x1135) = 0;
  if (0 < param_3) {
    local_18 = 0;
    uVar3 = (uint)*(ushort *)(param_1 + 0x1148);
    do {
      if (uVar3 != 0) {
        local_14 = 0;
        do {
          pcVar1 = (char *)(*(int *)(param_2 + 0xc) + (local_18 * uVar3 + local_14) * 0xc);
          if ((*pcVar1 != '\0') && (uVar2 = *(int *)(pcVar1 + 8) - 0x84c0, uVar2 < 8)) {
            *(byte *)(param_1 + 0x1135) =
                 *(byte *)(param_1 + 0x1135) | (byte)(1 << ((byte)uVar2 & 0x1f));
          }
          local_14 = local_14 + 1;
        } while (local_14 < (int)uVar3);
      }
      local_18 = local_18 + 1;
    } while (param_3 != local_18);
  }
  return;
}

/* FUN_0009ffa9 @ 0x9ffa9 (47 bytes) */
int FUN_0009ffa9(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_2 != 0) && (*(char *)(param_1 + 0x1134) == '\0')) {
    iVar1 = **(int **)(param_1 + 0x1154);
    **(int **)(param_1 + 0x1154) = param_2 + iVar1;
    return iVar1;
  }
  return 0;
}

/* FUN_0009ffd8 @ 0x9ffd8 (592 bytes) */
int FUN_0009ffd8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  if (*(char *)(param_1 + 0x1134) == '\0') {
    iVar1 = *(int *)(param_1 + 0x1154);
    uVar5 = *(uint *)(iVar1 + 4);
    uVar7 = 0;
    bVar3 = false;
    iVar6 = 0;
    while (uVar7 < uVar5) {
      while( true ) {
        if (bVar3) goto LAB_000a003f;
        if (param_2 == *(int *)(iVar6 + *(int *)(iVar1 + 0x88))) break;
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 0x78;
        if (uVar5 <= uVar7) goto LAB_000a0035;
      }
      bVar3 = true;
    }
LAB_000a0035:
    if (bVar3) {
LAB_000a003f:
      iVar6 = uVar7 * 0x78;
      iVar2 = *(int *)(iVar1 + 0x88);
      if (uVar7 != *(uint *)(param_1 + 0x1140)) {
        *(undefined1 *)(param_1 + 0x1136) = 1;
      }
      *(uint *)(param_1 + 0x1140) = uVar7;
      if (*(char *)(iVar6 + iVar2 + 0x6c) == '\0') {
        *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) & 0xfd;
        if ((*(uint *)(param_1 + 0x44) & 0x4c000) == 0xc000) {
          *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0x7f;
        }
      }
      else {
        *(byte *)(param_1 + 0x46) =
             *(byte *)(param_1 + 0x46) & 0xfd | (*(byte *)(param_1 + 0x46) & 1) * '\x02';
        if ((*(uint *)(param_1 + 0x44) & 0x4c000) == 0x4000) {
          *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) | 0x80;
        }
      }
    }
    else {
      if ((uVar5 & 7) == 0) {
        uVar4 = (**(code **)(param_1 + 0x10))(1,uVar5 * 0x78 + 0x3c0);
        (**(code **)(param_1 + 0x1344))
                  (uVar4,*(undefined4 *)(iVar1 + 0x88),*(int *)(iVar1 + 4) * 0x78);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar1 + 0x88));
        *(undefined4 *)(iVar1 + 0x88) = uVar4;
        uVar5 = *(uint *)(iVar1 + 4);
      }
      ((int (*)())FUN_000a124a)(param_1,uVar5 * 0x78 + *(int *)(iVar1 + 0x88));
      *(int *)(*(int *)(iVar1 + 4) * 0x78 + *(int *)(iVar1 + 0x88)) = param_2;
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
      *(uint *)(param_1 + 0x1140) = uVar7;
      *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) & 0xfd;
      if ((*(uint *)(param_1 + 0x44) & 0x4c000) == 0xc000) {
        *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0x7f;
      }
      *(undefined1 *)(param_1 + 0x1136) = 1;
      iVar6 = uVar7 * 0x78;
    }
    iVar6 = iVar6 + *(int *)(iVar1 + 0x88);
    *(int *)(param_1 + 0x1144) = iVar6;
    ((int (*)())FUN_0009ff22)(param_1,iVar6,*(undefined4 *)(iVar6 + 4));
    if ((*(uint *)(param_1 + 0x44) & 0x44000) == 0x4000) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
    }
  }
  return;
}

/* FUN_000a0228 @ 0xa0228 (299 bytes) */
int FUN_000a0228(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  bool bVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  
  if ((*(char *)(param_1 + 0x1134) == '\0') && (param_2 != 0)) {
    iVar1 = *(int *)(param_1 + 0x1154);
    if (param_2 == **(int **)(param_1 + 0x1144)) {
      ((int (*)())FUN_0009ffd8)(param_1,0);
    }
    uVar5 = 0;
    bVar2 = false;
    iVar3 = 0;
    while (uVar5 < *(uint *)(iVar1 + 4)) {
      while( true ) {
        if (bVar2) goto LAB_000a02a7;
        if (param_2 == *(int *)(iVar3 + *(int *)(iVar1 + 0x88))) break;
        uVar5 = uVar5 + 1;
        iVar3 = iVar3 + 0x78;
        if (*(uint *)(iVar1 + 4) <= uVar5) goto LAB_000a029d;
      }
      bVar2 = true;
    }
LAB_000a029d:
    if (bVar2) {
LAB_000a02a7:
      ((int (*)())FUN_000a143e)(param_1,uVar5 * 0x78 + *(int *)(iVar1 + 0x88));
      pvVar4 = (void *)(*(int *)(iVar1 + 0x88) + uVar5 * 0x78);
      _memmove(pvVar4,(void *)((int)pvVar4 + 0x78),(*(int *)(iVar1 + 4) - uVar5) * 0x78 - 0x78);
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + -1;
      if (uVar5 < *(uint *)(param_1 + 0x1140)) {
        iVar3 = *(uint *)(param_1 + 0x1140) - 1;
        *(int *)(param_1 + 0x1140) = iVar3;
        *(int *)(param_1 + 0x1144) = iVar3 * 0x78 + *(int *)(iVar1 + 0x88);
      }
    }
  }
  return;
}

/* FUN_000a0353 @ 0xa0353 (107 bytes) */
int FUN_000a0353(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    *(undefined1 *)(param_1 + 0x1134) = 1;
    ((int (*)())FUN_000a143e)(param_1,*(undefined4 *)(param_1 + 0x1144));
    ((int (*)())FUN_000a124a)(param_1,*(undefined4 *)(param_1 + 0x1144));
    if ((*(uint *)(param_1 + 0x44) & 0x44000) == 0x4000) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      return;
    }
  }
  return;
}

/* FUN_000a03be @ 0xa03be (657 bytes) */
int FUN_000a03be(param_1)
  int param_1;
{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_34;
  int local_30;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x1144);
  iVar4 = *(byte *)(param_1 + 0x1138) + 1;
  if (iVar4 == 2) {
    bVar2 = false;
    iVar5 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_30 = 0;
    local_34 = 0;
    while ((iVar5 < **(int **)(iVar1 + 0x14) || (local_1c < **(int **)(iVar1 + 0x20)))) {
      if ((local_18 < *(int *)(iVar1 + 0x18)) &&
         ((iVar5 < **(int **)(iVar1 + 0x14) &&
          (iVar7 = local_34 + *(int *)(iVar1 + 0x10), local_10 == *(int *)(iVar7 + 0x44))))) {
        if (((*(int *)(iVar7 + 0x14) == 0x8577) ||
            (((*(int *)(iVar7 + 0x14) == 0x896d || (*(int *)(iVar7 + 0x24) == 0x8577)) ||
             (*(int *)(iVar7 + 0x24) == 0x896d)))) ||
           ((*(int *)(iVar7 + 0x34) == 0x8577 || (*(int *)(iVar7 + 0x34) == 0x896d)))) {
          bVar2 = true;
        }
        local_18 = local_18 + 1;
        local_34 = local_34 + 0x4c;
        local_10 = local_10 + 1;
        iVar5 = iVar5 + 1;
      }
      if (((local_14 < *(int *)(iVar1 + 0x24)) && (local_1c < **(int **)(iVar1 + 0x20))) &&
         (iVar7 = local_30 + *(int *)(iVar1 + 0x1c), local_10 == *(int *)(iVar7 + 0x44))) {
        if (((((*(int *)(iVar7 + 0x14) == 0x8577) || (*(int *)(iVar7 + 0x14) == 0x896d)) ||
             (*(int *)(iVar7 + 0x24) == 0x8577)) ||
            ((*(int *)(iVar7 + 0x24) == 0x896d || (*(int *)(iVar7 + 0x34) == 0x8577)))) ||
           (*(int *)(iVar7 + 0x34) == 0x896d)) {
          bVar2 = true;
        }
        local_14 = local_14 + 1;
        local_30 = local_30 + 0x4c;
        local_10 = local_10 + 1;
        local_1c = local_1c + 1;
      }
    }
    if (bVar2) {
      *(undefined4 *)(iVar1 + 4) = 1;
      ((int (*)())FUN_000a123c)(*(undefined4 *)(param_1 + 0x1144),0);
      goto LAB_000a03fb;
    }
  }
  *(int *)(iVar1 + 4) = iVar4;
LAB_000a03fb:
  ((int (*)())FUN_0009ff22)(param_1,*(int *)(param_1 + 0x1144),*(undefined4 *)(*(int *)(param_1 + 0x1144) + 4));
  *(undefined1 *)(param_1 + 0x1136) = 1;
  *(undefined1 *)(param_1 + 0x1134) = 0;
  cVar3 = (**(code **)(param_1 + 0x1164))(param_1);
  if (cVar3 == '\0') {
    ((int (*)())FUN_000a123c)(*(undefined4 *)(param_1 + 0x1144),0);
    *(undefined1 *)(param_1 + 0x1138) = 0;
    *(undefined1 *)(param_1 + 0x1137) = 0;
    cVar3 = *(char *)(iVar1 + 0x6c);
  }
  else {
    *(undefined1 *)(param_1 + 0x1138) = 0;
    *(undefined1 *)(param_1 + 0x1137) = 0;
    cVar3 = *(char *)(iVar1 + 0x6c);
  }
  if (cVar3 == '\0') {
    *(byte *)(param_1 + 0x46) = *(byte *)(param_1 + 0x46) & 0xfd;
    uVar6 = *(uint *)(param_1 + 0x44);
    if ((uVar6 & 0x4c000) == 0xc000) {
      *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) & 0x7f;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      *(undefined1 *)(param_1 + 0x29) = 1;
      uVar6 = *(uint *)(param_1 + 0x44);
    }
  }
  else {
    *(byte *)(param_1 + 0x46) =
         *(byte *)(param_1 + 0x46) & 0xfd | (*(byte *)(param_1 + 0x46) & 1) * '\x02';
    uVar6 = *(uint *)(param_1 + 0x44);
    if ((uVar6 & 0x4c000) == 0x4000) {
      *(byte *)(param_1 + 0x45) = *(byte *)(param_1 + 0x45) | 0x80;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      *(undefined1 *)(param_1 + 0x29) = 1;
      uVar6 = *(uint *)(param_1 + 0x44);
    }
  }
  if ((uVar6 & 0x44000) == 0x4000) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
  }
  return;
}

/* FUN_000a064f @ 0xa064f (267 bytes) */
int FUN_000a064f(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x1138) + (uint)(*(char *)(param_1 + 0x1137) != '\0');
  if (((uVar1 < *(byte *)(param_1 + 0x1150)) && (param_2 - 0x8921U < 6)) && (param_4 - 0x8976U < 4))
  {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)*(byte *)(param_1 + 0x13b2) < (int)(param_3 - 0x84c0U)) goto LAB_000a0742;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar1 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a0742;
    cVar2 = ((int (*)())FUN_000a1587)(param_1,*(undefined4 *)(param_1 + 0x1144),uVar1,param_2,param_3,0,param_4);
    if (cVar2 != '\0') {
      if (*(char *)(param_1 + 0x1137) == '\0') {
        return;
      }
      *(char *)(param_1 + 0x1138) = *(char *)(param_1 + 0x1138) + '\x01';
      *(undefined1 *)(param_1 + 0x1137) = 0;
      return;
    }
  }
LAB_000a0742:
  ((int (*)())FUN_000a123c)();
  return;
}

/* FUN_000a075a @ 0xa075a (267 bytes) */
int FUN_000a075a(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x1138) + (uint)(*(char *)(param_1 + 0x1137) != '\0');
  if (((uVar1 < *(byte *)(param_1 + 0x1150)) && (param_2 - 0x8921U < 6)) && (param_4 - 0x8976U < 4))
  {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)*(byte *)(param_1 + 0x13b2) < (int)(param_3 - 0x84c0U)) goto LAB_000a084d;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar1 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a084d;
    cVar2 = ((int (*)())FUN_000a1587)(param_1,*(undefined4 *)(param_1 + 0x1144),uVar1,param_2,param_3,1,param_4);
    if (cVar2 != '\0') {
      if (*(char *)(param_1 + 0x1137) == '\0') {
        return;
      }
      *(char *)(param_1 + 0x1138) = *(char *)(param_1 + 0x1138) + '\x01';
      *(undefined1 *)(param_1 + 0x1137) = 0;
      return;
    }
  }
LAB_000a084d:
  ((int (*)())FUN_000a123c)();
  return;
}

/* FUN_000a0865 @ 0xa0865 (152 bytes) */
int FUN_000a0865(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a1678)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,param_8,0,0,0,0,0,0);
  return;
}

/* FUN_000a08fd @ 0xa08fd (149 bytes) */
int FUN_000a08fd(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a1678)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,0,0,0);
  return;
}

/* FUN_000a0992 @ 0xa0992 (146 bytes) */
int FUN_000a0992(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a1678)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
               param_13,param_14);
  return;
}

/* FUN_000a0a24 @ 0xa0a24 (145 bytes) */
int FUN_000a0a24(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a18fa)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,0,0,0,0,0,0);
  return;
}

/* FUN_000a0ab5 @ 0xa0ab5 (142 bytes) */
int FUN_000a0ab5(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a18fa)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,0,0,0);
  return;
}

/* FUN_000a0b43 @ 0xa0b43 (139 bytes) */
int FUN_000a0b43(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
{
  if (*(char *)(param_1 + 0x1134) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x1137) = 1;
  ((int (*)())FUN_000a18fa)(param_1,*(undefined4 *)(param_1 + 0x1144),*(undefined1 *)(param_1 + 0x1138),param_2,
               param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
               param_13);
  return;
}

/* FUN_000a0bce @ 0xa0bce (143 bytes) */
int FUN_000a0bce(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  if (7 < param_2 - 0x8941U) {
    ((int (*)())FUN_000a123c)();
    return;
  }
  ((int (*)())FUN_000a1be0)(param_1,*(undefined4 *)(param_1 + 0x1144),param_2,param_3,
               *(undefined1 *)(param_1 + 0x1134));
  if (((*(uint *)(param_1 + 0x44) & 0x44000) == 0x4000) &&
     ((*(uint *)(param_1 + 0x38) & 0x2000) != 0)) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
    return;
  }
  return;
}

/* FUN_000a0c5d @ 0xa0c5d (68 bytes) */
int FUN_000a0c5d(param_1)
  int param_1;
{
  (**(code **)(param_1 + 0x115c))(param_1);
  *(undefined1 *)(param_1 + 0x1136) = 1;
  *(undefined4 *)(param_1 + 0x1140) = 0;
  *(undefined1 *)(param_1 + 0x1134) = 0;
  *(undefined1 *)(param_1 + 0x1137) = 0;
  *(undefined1 *)(param_1 + 0x1138) = 0;
  *(undefined4 *)(param_1 + 0x1144) = *(undefined4 *)(*(int *)(param_1 + 0x1154) + 0x88);
  return;
}

/* FUN_000a0ca1 @ 0xa0ca1 (184 bytes) */
int FUN_000a0ca1(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_1 + 0x1154);
  ((int (*)())FUN_000a143e)(param_1,iVar1 + 0x10);
  if (*(int *)(iVar1 + 4) != 0) {
    local_10 = 0;
    iVar2 = 0;
    do {
      ((int (*)())FUN_000a143e)(param_1,iVar2 + *(int *)(iVar1 + 0x88));
      local_10 = local_10 + 1;
      iVar2 = iVar2 + 0x78;
    } while (local_10 < *(uint *)(iVar1 + 4));
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  if (*(int *)(iVar1 + 0x88) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar1 + 0x88));
    *(undefined4 *)(iVar1 + 0x88) = 0;
  }
  if (*(int *)(iVar1 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(iVar1 + 0xc));
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  (**(code **)(param_1 + 0x18))(iVar1);
  *(undefined4 *)(param_1 + 0x1154) = 0;
  return;
}

/* FUN_000a0d59 @ 0xa0d59 (57 bytes) */
int FUN_000a0d59(param_1)
  int param_1;
{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x1154) + 8);
  *piVar1 = *piVar1 + -1;
  if (*(int *)(*(int *)(param_1 + 0x1154) + 8) != 0) {
    return;
  }
  (**(code **)(param_1 + 0x1160))(param_1);
  ((int (*)())FUN_000a0ca1)();
  return;
}

/* FUN_000a0d92 @ 0xa0d92 (362 bytes) */
int FUN_000a0d92(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_14;
  undefined4 local_10;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x1154) + 8);
  *piVar1 = *piVar1 + -1;
  if (*(int *)(*(int *)(param_1 + 0x1154) + 8) == 0) {
    ((int (*)())FUN_000a0ca1)();
  }
  iVar2 = *(int *)(param_2 + 0x1154);
  *(undefined4 *)(param_1 + 0x1140) = 0;
  *(undefined1 *)(param_1 + 0x1134) = 0;
  *(undefined1 *)(param_1 + 0x1137) = 0;
  *(undefined1 *)(param_1 + 0x1138) = 0;
  *(int *)(param_1 + 0x1154) = iVar2;
  iVar6 = *(int *)(iVar2 + 0x8c);
  *(int *)(param_1 + 0x113c) = iVar6;
  *(int *)(iVar2 + 0x8c) = iVar6 + 1;
  *(undefined4 *)(param_1 + 0x1144) = *(undefined4 *)(iVar2 + 0x88);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
  pvVar3 = *(void **)(iVar2 + 0x80);
  pvVar4 = (void *)(**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar2 + 0x8c),4);
  *(void **)(iVar2 + 0x80) = pvVar4;
  _memcpy(pvVar4,pvVar3,*(int *)(iVar2 + 0x8c) * 4 - 4);
  (**(code **)(param_1 + 0x18))(pvVar3);
  if (*(int *)(iVar2 + 4) == 0) {
    return;
  }
  local_14 = 0;
  local_10 = 0;
  do {
    iVar6 = local_10 + *(int *)(iVar2 + 0x88);
    pvVar3 = *(void **)(iVar6 + 0x70);
    uVar5 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar2 + 0x8c),4);
    *(undefined4 *)(iVar6 + 0x70) = uVar5;
    _memcpy(*(void **)(local_10 + 0x70 + *(int *)(iVar2 + 0x88)),pvVar3,
            *(int *)(iVar2 + 0x8c) * 4 - 4);
    (**(code **)(param_1 + 0x18))(pvVar3);
    local_14 = local_14 + 1;
    local_10 = local_10 + 0x78;
  } while (local_14 < *(uint *)(iVar2 + 4));
  return;
}

/* FUN_000a0efc @ 0xa0efc (250 bytes) */
int FUN_000a0efc(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  
  *(undefined4 *)(param_1 + 0x113c) = 0;
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x3c0);
  puVar2 = (undefined1 *)(**(code **)(param_1 + 0xc))((uint)*(ushort *)(param_1 + 0x114a) * 0x14);
  if (puVar2 != (undefined1 *)0x0) {
    if (*(short *)(param_1 + 0x114a) != 0) {
      iVar3 = 0;
      puVar4 = puVar2;
      do {
        *puVar4 = 0;
        *(undefined4 *)(puVar4 + 4) = 0x3f800000;
        *(undefined4 *)(puVar4 + 8) = 0x3f800000;
        *(undefined4 *)(puVar4 + 0xc) = 0x3f800000;
        *(undefined4 *)(puVar4 + 0x10) = 0x3f800000;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 0x14;
      } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 0x114a));
    }
    *(undefined4 *)(*(int *)(param_1 + 0x1154) + 8) = 1;
    *(undefined4 **)(*(int *)(param_1 + 0x1154) + 0x88) = puVar1;
    *(undefined1 **)(*(int *)(param_1 + 0x1154) + 0xc) = puVar2;
    **(undefined4 **)(param_1 + 0x1154) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1154) + 4) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1154) + 0x8c) = 1;
    ((int (*)())FUN_000a124a)(param_1,puVar1);
    *puVar1 = 0;
    ((int (*)())FUN_000a124a)(param_1,*(int *)(param_1 + 0x1154) + 0x10);
    *(undefined4 *)(*(int *)(param_1 + 0x1154) + 0x10) = 0;
  }
  return;
}

/* FUN_000a0ff6 @ 0xa0ff6 (298 bytes) */
int FUN_000a0ff6(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  
  if ((((((5 < param_3 - 0x8921) && (7 < param_3 - 0x8941)) && (param_3 != 0)) &&
       ((param_3 != 1 && (param_3 != 0x8577)))) && (param_3 != 0x896d)) ||
     ((((*param_6 = param_3, param_4 != 0 && (param_4 != 0x1903)) &&
       ((param_4 != 0x1904 && ((param_4 != 0x1905 && (param_4 != 0x1906)))))) ||
      (param_6[3] = param_4, (param_5 & 0xfffffff0) != 0)))) {
    return 0;
  }
  param_6[2] = param_5;
  param_6[1] = 0;
  if (1 < param_3) goto joined_r0x000a10ec;
  param_6[3] = 0;
  if (param_3 == 0) {
    if ((param_5 & 2) != 0) {
      param_5 = param_5 & 0xfffffffd;
      param_3 = 1;
    }
  }
  else if ((param_3 == 1) && ((param_5 & 2) != 0)) {
    param_5 = param_5 & 0xfffffffd;
    param_3 = 0;
  }
  if ((param_5 & 8) == 0) {
    if (param_3 == 0) {
      uVar2 = param_5 & 0xfffffffa;
      uVar1 = param_5 & 8;
      param_5 = uVar2;
      if (uVar1 != 0) goto LAB_000a10c7;
      goto LAB_000a10e1;
    }
  }
  else {
LAB_000a10c7:
    if ((param_5 & 1) != 0) {
      uVar2 = param_5 & 0xfffffff6;
      if (param_3 == 0) {
        if ((param_5 & 4) == 0) {
          param_3 = 1;
          param_6[2] = uVar2 | 4;
          *param_6 = 1;
          goto joined_r0x000a10ec;
        }
        uVar2 = param_5 & 0xfffffff2;
        param_3 = 1;
      }
LAB_000a10e1:
      param_6[2] = uVar2;
      *param_6 = param_3;
      goto joined_r0x000a10ec;
    }
  }
  param_6[2] = param_5;
  *param_6 = param_3;
joined_r0x000a10ec:
  if (param_3 == 0x896d) {
    *(undefined1 *)(param_2 + 0x6c) = 1;
  }
  return 1;
}

/* FUN_000a1120 @ 0xa1120 (284 bytes) */
int FUN_000a1120(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_3c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(byte *)(param_1 + 4) != 0xffffffff) {
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_1c = 0;
    do {
      iVar1 = *(int *)(local_1c * 4 + *(int *)(param_2 + 0x14));
      iVar2 = *(int *)(local_1c * 4 + *(int *)(param_2 + 0x20));
      iVar3 = 0;
      local_3c = 0;
      while ((iVar3 < iVar1 || (local_3c < iVar2))) {
        if ((local_18 < *(int *)(param_2 + 0x18)) && (iVar3 < iVar1)) {
          if (local_10 == *(int *)(*(int *)(param_2 + 0x10) + 0x44 + local_18 * 0x4c)) {
            local_18 = local_18 + 1;
            local_10 = local_10 + 1;
            iVar3 = iVar3 + 1;
          }
        }
        if ((local_14 < *(int *)(param_2 + 0x24)) && (local_3c < iVar2)) {
          if (local_10 == *(int *)(*(int *)(param_2 + 0x1c) + 0x44 + local_14 * 0x4c)) {
            local_14 = local_14 + 1;
            local_10 = local_10 + 1;
            local_3c = local_3c + 1;
          }
        }
      }
      local_1c = local_1c + 1;
    } while (*(byte *)(param_1 + 4) + 1 != local_1c);
    *param_3 = iVar3;
    *param_4 = local_3c;
    return;
  }
  *param_3 = 0;
  *param_4 = 0;
  return;
}

/* FUN_000a123c @ 0xa123c (14 bytes) */
int FUN_000a123c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(param_1 + 0x74) = param_2;
  return;
}

/* FUN_000a124a @ 0xa124a (500 bytes) */
int FUN_000a124a(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined4 local_20;
  
  *(undefined4 *)(param_2 + 4) = 1;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined1 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(param_1 + 0x114c) * 0x4c);
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(byte *)(param_1 + 0x1150) << 2);
  *(undefined4 *)(param_2 + 0x14) = uVar1;
  *(undefined4 *)(param_2 + 0x24) = 0;
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(param_1 + 0x114c) * 0x4c);
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(byte *)(param_1 + 0x1150) << 2);
  *(undefined4 *)(param_2 + 0x20) = uVar1;
  bVar4 = 0;
  if (*(char *)(param_1 + 0x1150) != '\0') {
    iVar3 = 0;
    do {
      *(undefined4 *)(*(int *)(param_2 + 0x14) + iVar3 * 4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x20) + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
      bVar4 = *(byte *)(param_1 + 0x1150);
    } while (iVar3 < (int)(uint)bVar4);
  }
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(param_1 + 0x1148) * (uint)bVar4 * 0xc);
  *(undefined4 *)(param_2 + 0xc) = uVar1;
  if (*(char *)(param_1 + 0x1150) != '\0') {
    local_20 = 0;
    uVar5 = (uint)*(ushort *)(param_1 + 0x1148);
    do {
      if (uVar5 != 0) {
        iVar3 = 0;
        do {
          iVar2 = (iVar3 + local_20 * uVar5) * 0xc;
          *(undefined1 *)(*(int *)(param_2 + 0xc) + iVar2) = 0;
          *(undefined1 *)(iVar2 + 1 + *(int *)(param_2 + 0xc)) = 1;
          *(int *)(iVar2 + 8 + *(int *)(param_2 + 0xc)) = iVar3 + 0x84c0;
          iVar3 = iVar3 + 1;
          uVar5 = (uint)*(ushort *)(param_1 + 0x1148);
        } while (iVar3 < (int)uVar5);
      }
      local_20 = local_20 + 1;
    } while (local_20 < (int)(uint)*(byte *)(param_1 + 0x1150));
  }
  uVar1 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(param_1 + 0x114a) * 0x14);
  *(undefined4 *)(param_2 + 0x28) = uVar1;
  if (*(short *)(param_1 + 0x114a) != 0) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      *(undefined1 *)(*(int *)(param_2 + 0x28) + iVar2) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + 4 + iVar2) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + 8 + iVar2) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + 0xc + iVar2) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + 0x10 + iVar2) = 0x3f800000;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x14;
    } while (iVar3 < (int)(uint)*(ushort *)(param_1 + 0x114a));
  }
  uVar1 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(param_1 + 0x1154) + 0x8c),4);
  *(undefined4 *)(param_2 + 0x70) = uVar1;
  ((int (*)())FUN_000a123c)();
  return;
}

/* FUN_000a143e @ 0xa143e (329 bytes) */
int FUN_000a143e(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x10));
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x1c));
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x20));
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  if (*(int *)(param_2 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0xc));
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  if (*(int *)(param_2 + 0x28) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(param_2 + 0x28));
    *(undefined4 *)(param_2 + 0x28) = 0;
  }
  if (*(int *)(param_2 + 0x70) != 0) {
    iVar5 = *(int *)(param_1 + 0x1154);
    if (*(int *)(iVar5 + 0x8c) == 0) {
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0x70));
      *(undefined4 *)(param_2 + 0x70) = 0;
    }
    else {
      uVar4 = 0;
      iVar3 = *(int *)(param_2 + 0x70);
      do {
        piVar1 = (int *)(iVar3 + uVar4 * 4);
        iVar2 = *piVar1;
        if (iVar2 != 0) {
          *piVar1 = 0;
          (**(code **)(param_1 + 0x1158))(param_1,iVar2);
          iVar3 = *(int *)(param_2 + 0x70);
          iVar5 = *(int *)(param_1 + 0x1154);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(iVar5 + 0x8c));
      (**(code **)(param_1 + 0x18))(iVar3);
      *(undefined4 *)(param_2 + 0x70) = 0;
    }
  }
  return;
}

/* FUN_000a1587 @ 0xa1587 (241 bytes) */
int FUN_000a1587(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = *(char **)(param_2 + 0xc);
  iVar2 = (((uint)*(ushort *)(param_1 + 0x1148) * param_3 + param_4) * 3 + -0x19b63) * 4;
  pcVar1 = pcVar5 + iVar2;
  if (*pcVar1 != '\0') {
    return 0;
  }
  iVar4 = (uint)*(ushort *)(param_1 + 0x1148) * (uint)*(byte *)(param_1 + 0x1150);
  if (iVar4 != 0) {
    iVar3 = 0;
    do {
      if ((*pcVar5 != '\0') && (*(int *)(pcVar5 + 8) == param_5)) {
        if ((param_7 == 0x8976) || (param_7 == 0x8978)) {
          if (*(int *)(pcVar5 + 4) == 0x8977) {
            return 0;
          }
          if (*(int *)(pcVar5 + 4) == 0x8979) {
            return 0;
          }
        }
        else {
          if (*(int *)(pcVar5 + 4) == 0x8976) {
            return 0;
          }
          if (*(int *)(pcVar5 + 4) == 0x8978) {
            return 0;
          }
        }
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 0xc;
    } while (iVar4 != iVar3);
  }
  *pcVar1 = '\x01';
  *(undefined1 *)(iVar2 + 1 + *(int *)(param_2 + 0xc)) = param_6;
  *(int *)(iVar2 + 8 + *(int *)(param_2 + 0xc)) = param_5;
  *(int *)(iVar2 + 4 + *(int *)(param_2 + 0xc)) = param_7;
  return 1;
}

/* FUN_000a1678 @ 0xa1678 (642 bytes) */
int FUN_000a1678(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
  int param_12;
  undefined4 param_13;
  int param_14;
  int param_15;
  undefined4 param_16;
{
  int *piVar1;
  char cVar2;
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  int local_1c;
  int local_18;
  undefined1 local_14 [4];
  int local_10;
  
  ((int (*)())FUN_000a1120)(local_14);
  if ((((param_3 < (int)(uint)*(byte *)(param_1 + 0x1150)) &&
       (local_10 < (int)(uint)*(ushort *)(param_1 + 0x114e))) && (param_4 - 0x8961U < 0xc)) &&
     ((1 << ((byte)(param_4 - 0x8961U) & 0x1f) & 0xffdU) != 0)) {
    local_60 = param_4;
    cVar2 = ((int (*)())FUN_000a0ff6)(param_9,param_10,local_4c);
    if ((((((cVar2 != '\0') && (cVar2 = ((int (*)())FUN_000a0ff6)(param_12,param_13,local_3c), cVar2 != '\0')) &&
          ((cVar2 = ((int (*)())FUN_000a0ff6)(param_15,param_16,local_2c), cVar2 != '\0' &&
           (param_5 - 0x8921U < 6)))) &&
         ((((7 < param_8 - 0x8941U || (7 < param_11 - 0x8941U)) ||
           ((7 < param_14 - 0x8941U ||
            (((param_8 == param_11 || (param_8 == param_14)) || (param_11 == param_14)))))) &&
          (((param_7 & 0xffffffbf & (param_7 & 0xffffffbf) - 1) == 0 &&
           ((param_8 != 0x896d || (param_9 != 0x1906)))))))) &&
        (((param_11 != 0x896d || (param_12 != 0x1906)) &&
         ((param_14 != 0x896d || (param_15 != 0x1906)))))) &&
       ((param_4 != 0x8967 ||
        (((param_8 != 0x896d || ((param_9 != 0 && (param_9 != 0x1906)))) &&
         ((param_11 != 0x896d || ((param_12 != 0 && (param_12 != 0x1906)))))))))) {
      if (7 < param_6) {
        return 0;
      }
      local_5c = param_5;
      local_54 = param_7;
      local_58 = param_6;
      local_50 = 0;
      local_1c = *(int *)(param_2 + 8);
      local_18 = param_3;
      *(int *)(param_2 + 8) = local_1c + 1;
      (**(code **)(param_1 + 0x1344))
                (*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18) * 0x4c,&local_60,0x4c);
      piVar1 = (int *)(*(int *)(param_2 + 0x14) + param_3 * 4);
      *piVar1 = *piVar1 + 1;
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
      return 1;
    }
  }
  ((int (*)())FUN_000a123c)(param_2,0);
  return 0;
}

/* FUN_000a18fa @ 0xa18fa (742 bytes) */
int FUN_000a18fa(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
  int param_11;
  undefined4 param_12;
  int param_13;
  int param_14;
  undefined4 param_15;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  int local_60;
  int local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 local_4c [16];
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  int local_1c;
  int local_18;
  int local_14 [2];
  
  ((int (*)())FUN_000a1120)(local_14);
  if ((((param_3 < (int)(uint)*(byte *)(param_1 + 0x1150)) &&
       (local_14[0] < (int)(uint)*(ushort *)(param_1 + 0x114e))) && (param_4 - 0x8961U < 0xc)) &&
     ((1 << ((byte)(param_4 - 0x8961U) & 0x1f) & 0xffdU) != 0)) {
    local_60 = param_4;
    cVar3 = ((int (*)())FUN_000a0ff6)(param_8,param_9,local_4c);
    if (((((cVar3 != '\0') && (cVar3 = ((int (*)())FUN_000a0ff6)(param_11,param_12,local_3c), cVar3 != '\0')) &&
         ((cVar3 = ((int (*)())FUN_000a0ff6)(param_14,param_15,local_2c), cVar3 != '\0' &&
          (param_5 - 0x8921U < 6)))) &&
        (((7 < param_7 - 0x8941U || (7 < param_10 - 0x8941U)) ||
         ((7 < param_13 - 0x8941U ||
          (((param_7 == param_10 || (param_7 == param_13)) || (param_10 == param_13)))))))) &&
       (((param_6 & 0xffffffbf & (param_6 & 0xffffffbf) - 1) == 0 &&
        ((((1 < param_4 - 0x8966U && (param_4 != 0x896c)) ||
          (((0 < *(int *)(param_2 + 0x18) &&
            ((iVar1 = *(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18) * 0x4c,
             *(int *)(iVar1 + -8) == *(int *)(param_2 + 8) + -1 && (param_3 == *(int *)(iVar1 + -4))
             ))) && (param_4 == *(int *)(iVar1 + -0x4c))))) &&
         (((((((param_4 == 0x8967 || (*(int *)(param_2 + 0x18) < 2)) ||
              (iVar1 = *(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18) * 0x4c,
              *(int *)(iVar1 + -8) != *(int *)(param_2 + 8) + -1)) ||
             ((param_3 != *(int *)(iVar1 + -4) || (*(int *)(iVar1 + -0x4c) != 0x8967)))) &&
            ((param_7 != 0x896d || ((param_8 != 0 && (param_8 != 0x1906)))))) &&
           ((param_10 != 0x896d || ((param_11 != 0 && (param_11 != 0x1906)))))) &&
          ((param_13 != 0x896d || ((param_14 != 0 && (param_14 != 0x1906)))))))))))) {
      local_5c = param_5;
      local_54 = param_6;
      local_58 = 0;
      local_50 = 0;
      local_1c = *(int *)(param_2 + 8);
      local_18 = param_3;
      *(int *)(param_2 + 8) = local_1c + 1;
      (**(code **)(param_1 + 0x1344))
                (*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x24) * 0x4c,&local_60,0x4c);
      piVar2 = (int *)(*(int *)(param_2 + 0x20) + param_3 * 4);
      *piVar2 = *piVar2 + 1;
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
      return 1;
    }
  }
  ((int (*)())FUN_000a123c)(param_2,0);
  return 0;
}

/* FUN_000a1be0 @ 0xa1be0 (183 bytes) */
int FUN_000a1be0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
{
  undefined1 *puVar1;
  
  param_3 = param_3 + -0x8941;
  if ((-1 < param_3) && (param_3 < (int)(uint)*(ushort *)(param_1 + 0x114a))) {
    if (param_5 == '\0') {
      puVar1 = (undefined1 *)(*(int *)(*(int *)(param_1 + 0x1154) + 0xc) + param_3 * 0x14);
      *puVar1 = 1;
      *(undefined4 *)(puVar1 + 4) = *param_4;
      *(undefined4 *)(puVar1 + 8) = param_4[1];
      *(undefined4 *)(puVar1 + 0xc) = param_4[2];
      *(undefined4 *)(puVar1 + 0x10) = param_4[3];
      return 1;
    }
    param_3 = param_3 * 0x14;
    *(undefined1 *)(*(int *)(param_2 + 0x28) + param_3) = 1;
    *(undefined4 *)(param_3 + 4 + *(int *)(param_2 + 0x28)) = *param_4;
    *(undefined4 *)(param_3 + 8 + *(int *)(param_2 + 0x28)) = param_4[1];
    *(undefined4 *)(param_3 + 0xc + *(int *)(param_2 + 0x28)) = param_4[2];
    *(undefined4 *)(param_3 + 0x10 + *(int *)(param_2 + 0x28)) = param_4[3];
    return 1;
  }
  return 0;
}

/* FUN_000a1c97 @ 0xa1c97 (68 bytes) */
int FUN_000a1c97(int param_1,float param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x13e0);
  if ((float)iVar1 < param_2) {
    if ((float)*(int *)(param_1 + 0x13e4) <= param_2) {
      return *(int *)(param_1 + 0x13e4);
    }
    iVar1 = (int)(param_2 + FLOAT_001c5bd4);
  }
  return iVar1;
}

/* FUN_000a1cdb @ 0xa1cdb (90 bytes) */
int FUN_000a1cdb(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_10;
  
  bVar1 = *(byte *)(param_1 + 0x13b7);
  uVar2 = 1 << (bVar1 & 0x1f);
  if ((param_2 & uVar2) == 0) {
    local_10 = 0;
    uVar3 = (uint)bVar1;
    do {
      uVar3 = uVar3 - 1;
      if (local_10 == bVar1) {
        uVar2 = 1 << ((byte)uVar3 & 0x1f);
        break;
      }
      uVar2 = 1 << ((byte)uVar3 & 0x1f);
      local_10 = local_10 + 1;
    } while ((param_2 & uVar2) == 0);
  }
  if ((int)uVar2 < (int)param_2) {
    uVar2 = uVar2 * 2;
  }
  return uVar2;
}

