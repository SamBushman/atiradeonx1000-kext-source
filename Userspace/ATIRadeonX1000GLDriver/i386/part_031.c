#include "decls.h"

/* FUN_0011074c @ 0x11074c (50 bytes) */
int FUN_0011074c(param_1)
  int param_1;
{
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x20:
  case 0x24:
  case 0x27:
    return 0;
  case 0x21:
  case 0x26:
  case 0x28:
    return 2;
  case 0x22:
  case 0x25:
  case 0x29:
    return 3;
  case 0x23:
  case 0x2a:
    return 1;
  default:
    return 8;
  case 0x8b:
  case 0x8c:
  case 0x8d:
    return *(undefined4 *)(param_1 + 300);
  }
}

/* FUN_00110958 @ 0x110958 (77 bytes) */
bool FUN_00110958(undefined4 param_1,float param_2,float param_3)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = ((int (*)())FUN_0011074c)(param_1);
  switch(uVar2) {
  case 0:
    bVar1 = param_2 == param_3;
    break;
  case 1:
    bVar1 = param_2 != param_3;
    break;
  case 2:
    bVar1 = param_3 < param_2;
    break;
  case 3:
    bVar1 = param_3 <= param_2;
    break;
  case 4:
    bVar1 = param_2 < param_3;
    break;
  case 5:
    bVar1 = param_2 <= param_3;
    break;
  default:
    bVar1 = false;
  }
  return bVar1;
}

/* FUN_00110a08 @ 0x110a08 (49 bytes) */
int FUN_00110a08(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (((iVar1 != 0x8c) && (iVar1 != 0x8d)) && (iVar1 != 0x8b)) {
    return;
  }
  *(undefined4 *)(param_1 + 300) = param_2;
  return;
}

/* FUN_00110a3a @ 0x110a3a (86 bytes) */
int FUN_00110a3a(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  byte bVar1;
  
  (**(code **)(**(int **)(param_4 + 0x54) + 0xf0))(*(int **)(param_4 + 0x54),param_3);
  switch(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8)) {
  case 0x12:
    if (param_2 == 1) {
      bVar1 = *(byte *)(param_1 + 0xb8);
joined_r0x00110b5d:
      if ((bVar1 & 1) != 0) {
        return 0;
      }
      return param_3;
    }
    bVar1 = *(byte *)(param_1 + 0xb8);
    break;
  case 0x13:
    if (param_2 != 1) {
      return 0x3f800000;
    }
    return param_3;
  case 0x14:
    if (param_2 == 2) {
      if ((*(byte *)(param_1 + 0xe8) & 1) == 0) {
        return 0;
      }
      return 0x3f800000;
    }
    if (param_2 == 3) {
      bVar1 = *(byte *)(param_1 + 0xe8);
      goto joined_r0x00110b5d;
    }
    if (param_2 != 1) {
      return 0x7ffffffd;
    }
    bVar1 = *(byte *)(param_1 + 0xe8);
    break;
  default:
    return 0x7ffffffd;
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x31:
    return param_3;
  }
  if ((bVar1 & 1) == 0) {
    return 0;
  }
  return param_3;
}

/* FUN_00110b92 @ 0x110b92 (122 bytes) */
int FUN_00110b92(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 8);
  if (iVar1 == 0x13) {
    if ((*(byte *)(param_1 + 0xd0) & 1) == (*(byte *)(param_1 + 0xb8) & 1)) {
      return 1;
    }
  }
  else if (iVar1 == 0x14) {
    if ((*(byte *)(param_1 + 0xd0) & 1) == (*(byte *)(param_1 + 0xb8) & 1)) {
      return 1;
    }
    if ((*(byte *)(param_1 + 0xe8) & 1) != 0) {
      return 1;
    }
  }
  else if ((iVar1 == 0x12) &&
          (((*(byte *)(param_1 + 0xb8) & 1) == 0 || ((*(byte *)(param_1 + 0xd0) & 1) == 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_00110c0c @ 0x110c0c (198 bytes) */
int FUN_00110c0c(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  uVar3 = FUN_00119212(*(undefined4 *)(param_1[0x22] + 8),param_6);
  iVar4 = FUN_00118f66(uVar3);
  param_1[0x22] = iVar4;
  if (param_5 != '\0') {
    iVar4 = FUN_00118f66(0x35);
    param_1[0x22] = iVar4;
    FUN_00109c0e(param_1 + 0x2f,1,*(byte *)(param_1 + 0x34) & 1 ^ 1);
  }
  puVar1 = PTR_DAT_00213485;
  param_1[0x2d] = *(int *)(PTR_DAT_00213485 + param_2 * 4);
  if (1 < iVar2) {
    param_1[0x33] = *(int *)(puVar1 + param_3 * 4);
  }
  if (2 < iVar2) {
    param_1[0x39] = *(int *)(puVar1 + param_4 * 4);
  }
  return;
}

/* FUN_00110cd2 @ 0x110cd2 (196 bytes) */
int FUN_00110cd2(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  bVar4 = *(int *)(param_1[0x22] + 8) == 0x35;
  uVar1 = FUN_00119212(*(undefined4 *)(param_1[0x22] + 8),param_2);
  iVar2 = FUN_00118f66(uVar1);
  param_1[0x22] = iVar2;
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  iVar3 = FUN_000f5c30(param_1[0x2d]);
  param_1[0x2d] = iVar3;
  if (1 < iVar2) {
    iVar3 = FUN_000f5c30(param_1[0x33]);
    param_1[0x33] = iVar3;
  }
  if (2 < iVar2) {
    iVar2 = FUN_000f5c30(param_1[0x39]);
    param_1[0x39] = iVar2;
  }
  if (bVar4) {
    FUN_00109c0e(param_1 + 0x2f,1,*(byte *)(param_1 + 0x34) & 1 ^ 1);
  }
  return bVar4;
}

/* FUN_00110d96 @ 0x110d96 (399 bytes) */
int FUN_00110d96(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  *(int *)(param_1 + 0x84) = param_3;
  FUN_000fa0d2(param_1,*(undefined4 *)(param_4 + 0x3f4),param_3,param_2,param_2,param_2,param_2);
  uVar2 = DAT_001cbea8;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x9c) = DAT_001cbea8;
  }
  else {
    iVar5 = FUN_0010b0f4(param_1,param_3);
    *(undefined4 *)(iVar5 + 0x10) = uVar2;
  }
  if ((*(byte *)(*(int *)(param_4 + 0x3f4) + 0x30) & 8) == 0) {
    iVar5 = *(int *)(param_1 + 0x8c + param_3 * 0x18);
    piVar4 = *(int **)(iVar5 + 0x18);
    if (*piVar4 == 0) {
      piVar4 = (int *)FUN_001a7f7c(piVar4,0);
    }
    else {
      if (piVar4[1] == 0) {
        *(undefined4 *)piVar4[2] = 0;
        piVar4[1] = 1;
      }
      piVar4 = (int *)piVar4[2];
    }
    iVar1 = *piVar4;
    if (*(int *)(*(int *)(iVar5 + 0x2c) + 4) == 0) {
      uVar2 = *(undefined4 *)(param_4 + 0xbc);
      puVar3 = (undefined4 *)FUN_001a7bca(uVar2,0x240);
      *puVar3 = uVar2;
      puVar3 = puVar3 + 1;
      FUN_00183c52(puVar3,iVar1,param_4);
      FUN_00184224(puVar3);
      FUN_00185344(puVar3);
      FUN_00183630(puVar3);
      FUN_0012a7b2(iVar5,*(undefined4 *)(*(int *)(iVar1 + 0x158) + 0xb0),puVar3);
    }
    FUN_0010ba02(param_1,param_3,iVar1,0,param_4);
  }
  return;
}

/* FUN_00110f42 @ 0x110f42 (381 bytes) */
int FUN_00110f42(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                float param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  
  *(int *)(param_4 + 0x228) = *(int *)(param_4 + 0x228) + 1;
  iVar2 = FUN_0010f654(0xa2,param_5);
  *(int *)(iVar2 + 0x84) = param_1;
  *(undefined4 *)(iVar2 + 0x94) = *(undefined4 *)(iVar2 + 0x14c);
  *(undefined4 *)(iVar2 + 0x98) = 0x36;
  *(undefined4 *)(iVar2 + 0x9c) = param_2;
  FUN_0010ba02(iVar2,1,param_3,*(uint *)(param_4 + 0x30) >> 7 & 1,param_5);
  uVar1 = DAT_001cbea8;
  iVar3 = FUN_0010b0f4(iVar2,1);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  FUN_000fa0d2(iVar2,param_4,2,param_6,param_6,param_6,param_6);
  iVar3 = FUN_0010b0f4(iVar2,2);
  *(undefined4 *)(iVar3 + 0x10) = uVar1;
  if (param_1 != 3) {
    *(int *)(iVar2 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
    return iVar2;
  }
  if ((param_6 != 0.0) || (NAN(param_6))) {
    local_20 = 0;
  }
  else {
    local_20 = 0x3f800000;
  }
  FUN_000fa0d2(iVar2,param_4,3,local_20,local_20,local_20,local_20);
  iVar3 = FUN_0010b0f4(iVar2,3);
  *(undefined4 *)(iVar3 + 0x10) = DAT_001cbea8;
  *(int *)(iVar2 + 0x160) = *(int *)(param_4 + 0x46c) + 1;
  return iVar2;
}

/* FUN_001110c0 @ 0x1110c0 (1231 bytes) */
int FUN_001110c0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  bool bVar21;
  int local_b8;
  
  uVar13 = FUN_0010b180(param_1,1);
  uVar2 = param_1[0x2e];
  iVar14 = FUN_0010b0f4(param_1,1);
  uVar3 = *(undefined4 *)(iVar14 + 0x10);
  uVar15 = FUN_0010b180(param_1,2);
  uVar4 = param_1[0x34];
  iVar14 = FUN_0010b0f4(param_1,2);
  uVar5 = *(undefined4 *)(iVar14 + 0x10);
  uVar16 = FUN_0010b180(param_1,3);
  uVar6 = param_1[0x3a];
  iVar14 = FUN_0010b0f4(param_1,3);
  uVar7 = *(undefined4 *)(iVar14 + 0x10);
  iVar14 = param_1[1];
  iVar8 = param_1[0x56];
  iVar9 = param_1[0x26];
  iVar10 = param_1[0x25];
  iVar17 = FUN_0010b0f4(param_1,0);
  iVar17 = *(int *)(iVar17 + 0x10);
  iVar12 = param_1[0x48];
  iVar11 = param_1[0x49];
  iVar18 = FUN_00109e42(param_1,*(undefined4 *)(param_3 + 0x3f4));
  if ((*(byte *)((int)param_1 + 0x15) & 2) == 0) {
    local_b8 = 0;
  }
  else {
    local_b8 = FUN_0010b180(param_1,param_1[0x21]);
  }
  uVar19 = FUN_0010b180(param_1,param_2);
  FUN_001a7d72(param_1);
  iVar20 = *(int *)(param_1[0x22] + 8);
  if (iVar20 == 0x25) {
    iVar20 = (param_2 != 3) + 0xb1;
    bVar21 = param_2 == 2;
  }
  else if (iVar20 == 0x26) {
    iVar20 = (param_2 == 3) + 0xb1;
    bVar21 = param_2 == 2;
  }
  else if (iVar20 == 0x24) {
    if (param_2 == 3) {
      iVar20 = 0xb0;
      bVar21 = false;
    }
    else {
      iVar20 = 0xb3;
      bVar21 = false;
    }
  }
  else {
    iVar20 = 0;
    bVar21 = false;
  }
  FUN_0010d8fc(param_1,iVar20,param_3);
  param_1[0x25] = iVar10;
  param_1[0x26] = iVar9;
  param_1[0x27] = iVar17;
  *(char *)(param_1 + 0x48) = (char)iVar12;
  param_1[0x49] = iVar11;
  param_1[0x58] = iVar18 + *(int *)(*(int *)(param_3 + 0x3f4) + 0x46c);
  FUN_000e9596(iVar8,iVar14,param_1);
  FUN_0010ba02(param_1,1,uVar13,0,param_3);
  piVar1 = param_1 + 0x29;
  FUN_00109c0e(piVar1,1,(byte)uVar2 & 1);
  FUN_00109c0e(piVar1,2,(byte)(uVar2 >> 1) & 1);
  iVar14 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar14 + 0x10) = uVar3;
  if (bVar21) {
    FUN_00109c0e(piVar1,1,*(byte *)(param_1 + 0x2e) & 1 ^ 1);
  }
  if (param_2 == 3) {
    FUN_0010ba02(param_1,2,uVar15,0,param_3);
    FUN_00109c0e(param_1 + 0x2f,1,(byte)uVar4 & 1);
    FUN_00109c0e(param_1 + 0x2f,2,(byte)(uVar4 >> 1) & 1);
    iVar14 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar14 + 0x10) = uVar5;
  }
  else {
    FUN_0010ba02(param_1,2,uVar16,0,param_3);
    FUN_00109c0e(param_1 + 0x2f,1,(byte)uVar6 & 1);
    FUN_00109c0e(param_1 + 0x2f,2,(byte)(uVar6 >> 1) & 1);
    iVar14 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar14 + 0x10) = uVar7;
  }
  if (local_b8 == 0) {
    (**(code **)(*param_1 + 0x94))(param_1,uVar19,param_3);
    return;
  }
  (**(code **)(*param_1 + 0x94))(param_1,local_b8,param_3);
  return;
}

/* FUN_00111598 @ 0x111598 (262 bytes) */
int FUN_00111598(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = *(int *)(param_1 + 0x84);
  if (0 < local_24) {
    local_20 = 1;
    do {
      iVar1 = FUN_0010b0f4(param_1,local_20);
      iVar3 = local_20;
      if (*(int *)(iVar1 + 0x10) == DAT_001cbea8) {
        while( true ) {
          if (iVar3 < local_24) {
            FUN_0010b85e(param_1,iVar3,param_1,iVar3 + 1);
            uVar2 = FUN_0010b180(param_1,iVar3 + 1);
            FUN_0010ba02(param_1,iVar3,uVar2,0,param_2);
          }
          else {
            FUN_0010a83e(param_1,iVar3);
            FUN_0010ba02(param_1,iVar3,0,0,param_2);
          }
          if (local_24 < iVar3 + 1) break;
          iVar3 = iVar3 + 1;
        }
        local_24 = local_24 + -1;
        *(int *)(param_1 + 0x84) = local_24;
      }
      else {
        local_20 = local_20 + 1;
      }
    } while (local_20 <= local_24);
  }
  return;
}

/* FUN_0011169e @ 0x11169e (419 bytes) */
int FUN_0011169e(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte bStack_21;
  undefined4 local_20;
  
  (**(code **)(*param_1 + 0x60))(param_1);
  piVar4 = (int *)FUN_0010b180(param_1,1);
  iVar7 = *(int *)(piVar4[0x22] + 8);
  if (((((iVar7 - 0x16U < 2) || (iVar7 == 0x19)) || (iVar7 == 0x31)) ||
      (((iVar7 == 0x13 || (iVar7 == 0x14)) || (iVar7 == 0x12)))) &&
     (iVar7 = *(int *)(*(int *)(param_2 + 0x3f4) + 0x228),
     iVar5 = (**(code **)(*piVar4 + 0x14))(piVar4), iVar7 + iVar5 < *(int *)(param_2 + 0x398))) {
    if (param_1[0x21] < 2) {
      bVar2 = true;
    }
    else {
      iVar7 = 2;
      bVar2 = true;
      do {
        iVar5 = FUN_0010b180(param_1,iVar7);
        if (*(int *)(iVar5 + 0x98) == 0x33) {
          iVar6 = FUN_0010b0f4(param_1,iVar7);
          local_20 = *(undefined4 *)(iVar6 + 0x10);
          iVar6 = 1;
          do {
            if (((&bStack_21)[iVar6] != 4) &&
               (*(float *)(iVar5 + 0x20 + (uint)(&bStack_21)[iVar6] * 0x18) != 0.0)) {
              bVar2 = false;
              break;
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 != 5);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 <= param_1[0x21]);
    }
    if ((*(byte *)((int)piVar4 + 0x15) & 2) != 0) {
      uVar8 = 0;
      do {
        iVar7 = FUN_0010b0f4(param_1,1);
        bVar1 = *(byte *)(uVar8 + 0x10 + iVar7);
        if (((bVar1 != 4) &&
            (iVar7 = FUN_0010b0f4(piVar4,0), *(char *)(uVar8 + 0x10 + iVar7) == '\x01')) &&
           (bVar1 != uVar8)) {
          return 0;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 != 4);
    }
    if ((bVar2) || (cVar3 = ((int (*)())FUN_00110b92)(piVar4), cVar3 != '\0')) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00111842 @ 0x111842 (1415 bytes) */
int FUN_00111842(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_44;
  int local_38;
  int local_30;
  int local_24;
  undefined4 local_20 [4];
  
  piVar4 = (int *)FUN_0010b180(param_1,1);
  iVar5 = FUN_0010b0f4(param_1,1);
  cVar3 = FUN_0010a2a8(piVar4,param_3,*(undefined4 *)(iVar5 + 0x10));
  if (cVar3 != '\0') {
    iVar5 = FUN_0010b0f4(param_2,1);
    local_20[0] = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = param_2[0x21];
    if (1 < iVar5) {
      iVar9 = 2;
      local_30 = 1;
      do {
        uVar7 = FUN_0010b180(param_2,iVar9);
        FUN_0010ba02(param_2,local_30,uVar7,0,param_3);
        iVar10 = FUN_0010b0f4(param_2,iVar9);
        iVar10 = *(int *)(iVar10 + 0x10);
        if (local_30 == 0) {
          param_2[0x27] = iVar10;
        }
        else {
          iVar8 = FUN_0010b0f4(param_2,local_30);
          *(int *)(iVar8 + 0x10) = iVar10;
        }
        iVar9 = iVar9 + 1;
        local_30 = local_30 + 1;
      } while (iVar9 <= iVar5);
    }
    param_2[0x21] = iVar5 + -1;
    local_38 = 0;
    do {
      bVar1 = *(byte *)((int)local_20 + local_38);
      if ((bVar1 != 4) && (0 < *(int *)(param_1 + 0x84))) {
        iVar5 = 1;
        do {
          iVar9 = FUN_0010b0f4(param_1,iVar5);
          bVar2 = *(byte *)(bVar1 + 0x10 + iVar9);
          if (bVar2 != 4) {
            iVar5 = FUN_0010b180(param_1,iVar5);
            uVar7 = *(undefined4 *)(iVar5 + 0x20 + (uint)bVar2 * 0x18);
            iVar9 = ((int (*)())FUN_00110362)(param_2,uVar7,&local_24);
            iVar5 = local_24;
            if (iVar9 == 0) {
              iVar5 = param_2[0x21];
              ((int (*)())FUN_00110d96)(param_2,uVar7,iVar5 + 1,param_3);
              (**(code **)(*param_2 + 0x88))(param_2,iVar5 + 1,local_38,local_38);
            }
            else if (local_24 != local_38) {
              iVar10 = FUN_0010b0f4(param_2,iVar9);
              (**(code **)(*param_2 + 0x88))
                        (param_2,iVar9,local_38,*(undefined1 *)(iVar5 + 0x10 + iVar10));
            }
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 <= *(int *)(param_1 + 0x84));
      }
      local_38 = local_38 + 1;
      if (local_38 == 4) {
        FUN_0010b3fe(param_1,param_3);
        return;
      }
    } while( true );
  }
  iVar5 = *(int *)(*(int *)(param_3 + 0x3f4) + 0x46c);
  cVar3 = (**(code **)(*piVar4 + 0x5c))(piVar4);
  if (cVar3 == '\0') {
    piVar6 = piVar4;
    if (iVar5 < piVar4[0x58]) {
      piVar4[0x58] = piVar4[0x58] + 1;
    }
    else {
      piVar4[0x58] = iVar5 + 1;
    }
  }
  else {
    piVar6 = (int *)FUN_0010a1c2(piVar4,param_3,0);
    piVar6[0x25] = piVar6[0x53];
    piVar6[0x26] = 0x31;
    FUN_000e9596(piVar4[0x56],piVar4,piVar6);
    iVar10 = iVar5 + 1;
    piVar6[0x58] = iVar10;
    iVar9 = FUN_0010b180(piVar6,1);
    if (iVar5 < *(int *)(iVar9 + 0x160)) {
      *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
    }
    else {
      *(int *)(iVar9 + 0x160) = iVar10;
    }
    if (1 < piVar6[0x21]) {
      iVar9 = FUN_0010b180(piVar6,2);
      if (iVar5 < *(int *)(iVar9 + 0x160)) {
        *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
      }
      else {
        *(int *)(iVar9 + 0x160) = iVar10;
      }
    }
  }
  FUN_0010ba02(param_2,1,piVar6,0,param_3);
  if ((*(byte *)(*(int *)(param_3 + 0x3f4) + 0x30) & 8) == 0) {
    FUN_0010a3c2(param_2,1,*(undefined4 *)(param_1 + 0xa4));
  }
  else {
    FUN_0010b3fe(param_1,param_3);
  }
  local_20[0] = DAT_001cbea8;
  local_44 = 0;
  do {
    iVar5 = FUN_0010b0f4(param_2,1);
    bVar1 = *(byte *)(local_44 + 0x10 + iVar5);
    uVar11 = (uint)bVar1;
    if (bVar1 != 4) {
      iVar5 = FUN_0010b0f4(param_1,1);
      if (*(char *)(uVar11 + 0x10 + iVar5) == '\x04') {
        if (1 < *(int *)(param_1 + 0x84)) {
          iVar5 = 2;
          do {
            iVar9 = FUN_0010b0f4(param_1,iVar5);
            bVar1 = *(byte *)(uVar11 + 0x10 + iVar9);
            if (bVar1 != 4) {
              iVar5 = FUN_0010b180(param_1,iVar5);
              uVar7 = *(undefined4 *)(iVar5 + 0x20 + (uint)bVar1 * 0x18);
              iVar9 = ((int (*)())FUN_00110362)(param_2,uVar7,&local_24);
              iVar5 = local_24;
              if (iVar9 == 0) {
                iVar5 = param_2[0x21];
                ((int (*)())FUN_00110d96)(param_2,uVar7,iVar5 + 1,param_3);
                (**(code **)(*param_2 + 0x88))(param_2,iVar5 + 1,local_44,local_44);
              }
              else if (local_24 != local_44) {
                iVar10 = FUN_0010b0f4(param_2,iVar9);
                (**(code **)(*param_2 + 0x88))
                          (param_2,iVar9,local_44,*(undefined1 *)(iVar5 + 0x10 + iVar10));
              }
              break;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 <= *(int *)(param_1 + 0x84));
        }
      }
      else {
        iVar5 = FUN_0010b0f4(param_1,1);
        *(undefined1 *)((int)local_20 + local_44) = *(undefined1 *)(uVar11 + 0x10 + iVar5);
      }
    }
    uVar7 = local_20[0];
    local_44 = local_44 + 1;
    if (local_44 == 4) {
      iVar5 = FUN_0010b0f4(param_2,1);
      *(undefined4 *)(iVar5 + 0x10) = uVar7;
      return;
    }
  } while( true );
}

/* FUN_00111dca @ 0x111dca (1284 bytes) */
int FUN_00111dca(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  undefined4 *local_7c;
  undefined4 *local_74;
  int local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 local_44 [4];
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20 [4];
  
  piVar3 = (int *)FUN_0010b180(param_1,1);
  iVar4 = *(int *)(*(int *)(param_2 + 0x3f4) + 0x46c);
  if (iVar4 < piVar3[0x58]) {
    piVar3[0x58] = piVar3[0x58] + 1;
  }
  else {
    piVar3[0x58] = iVar4 + 1;
  }
  iVar4 = FUN_0010b0f4(param_1,1);
  local_28 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = FUN_0010b0f4(param_1,0);
  local_20[0] = *(int *)(iVar4 + 0x10);
  iVar4 = FUN_0010b0f4(piVar3,0);
  local_24 = *(undefined4 *)(iVar4 + 0x10);
  if ((*(byte *)((int)piVar3 + 0x15) & 2) != 0) {
    iVar4 = 1;
    do {
      bVar1 = *(byte *)((int)&local_2c + iVar4 + 3);
      if ((bVar1 != 4) && (*(char *)((int)local_20 + (bVar1 - 4)) == '\x01')) {
        *(undefined1 *)((int)local_20 + iVar4 + -1) = 1;
        *(undefined1 *)((int)&local_2c + iVar4 + 3) = 4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 5);
  }
  iVar4 = piVar3[0x56];
  local_60 = 1;
  local_7c = local_44;
  iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3);
  if (0 < iVar5) {
    do {
      piVar6 = (int *)(*(int *)(param_2 + 0x3f4) + 0x228);
      *piVar6 = *piVar6 + 1;
      piVar6 = (int *)FUN_0010f654(0xa2,param_2);
      *local_7c = piVar6;
      piVar6[0x25] = piVar6[0x53];
      piVar6[0x26] = 0x36;
      piVar6[0x21] = 1;
      piVar6[0x4b] = 1;
      uVar7 = FUN_0010b180(piVar3,local_60);
      FUN_0010ba02(piVar6,1,uVar7,0,param_2);
      piVar6[0x27] = local_20[0];
      iVar5 = FUN_0010b0f4(piVar3,local_60);
      local_30 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = 0;
      do {
        if (*(byte *)((int)&local_28 + iVar5) != 4) {
          (**(code **)(*piVar6 + 0x88))
                    (piVar6,1,iVar5,
                     *(undefined1 *)((int)&local_30 + (uint)*(byte *)((int)&local_28 + iVar5)));
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 4);
      FUN_000e956e(iVar4,piVar3,piVar6);
      piVar8 = (int *)FUN_0010b180(piVar6,1);
      cVar2 = (**(code **)(*piVar8 + 0x60))(piVar8);
      if (cVar2 != '\0') {
        uVar7 = FUN_0010b180(piVar6,1);
        ((int (*)())FUN_00111842)(uVar7,piVar6,param_2);
      }
      FUN_0010ba02(piVar3,local_60,piVar6,0,param_2);
      piVar6[0x58] = *(int *)(*(int *)(param_2 + 0x3f4) + 0x46c) + 1;
      local_60 = local_60 + 1;
      local_7c = local_7c + 1;
      iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3);
    } while (local_60 <= iVar5);
  }
  local_5c = 0;
  do {
    if ((*(char *)((int)local_20 + local_5c) != '\x01') &&
       (*(char *)((int)&local_28 + local_5c) == '\x04')) {
      if (1 < *(int *)(param_1 + 0x84)) {
        iVar4 = 2;
        do {
          iVar5 = FUN_0010b0f4(param_1,iVar4);
          bVar1 = *(byte *)(local_5c + 0x10 + iVar5);
          if (bVar1 != 4) {
            iVar4 = FUN_0010b180(param_1,iVar4);
            local_58 = *(undefined4 *)(iVar4 + 0x20 + (uint)bVar1 * 0x18);
            goto LAB_00112156;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= *(int *)(param_1 + 0x84));
      }
      local_58 = 0;
LAB_00112156:
      local_74 = local_44;
      for (local_54 = 1; iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3), local_54 <= iVar4;
          local_54 = local_54 + 1) {
        uVar7 = ((int (*)())FUN_00110a3a)(piVar3,local_54,local_58,param_2);
        piVar6 = (int *)*local_74;
        iVar5 = ((int (*)())FUN_00110362)(piVar6,uVar7,&local_34);
        iVar4 = local_34;
        if (iVar5 == 0) {
          iVar4 = piVar6[0x21];
          ((int (*)())FUN_00110d96)(piVar6,uVar7,iVar4 + 1,param_2);
          (**(code **)(*piVar6 + 0x88))(piVar6,iVar4 + 1,local_5c,local_5c);
        }
        else {
          iVar9 = FUN_0010b0f4(piVar6,iVar5);
          (**(code **)(*piVar6 + 0x88))(piVar6,iVar5,local_5c,*(undefined1 *)(iVar4 + 0x10 + iVar9))
          ;
        }
        local_74 = local_74 + 1;
      }
    }
    local_5c = local_5c + 1;
    if (local_5c == 4) {
      piVar3[0x27] = local_20[0];
      local_2c = DAT_001cbeac;
      iVar4 = 1;
      do {
        if (*(char *)((int)local_20 + iVar4 + -1) == '\x01') {
          *(undefined1 *)((int)&local_30 + iVar4 + 3) = 4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 5);
      iVar5 = 1;
      iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
      if (0 < iVar4) {
        do {
          iVar4 = local_2c;
          if (iVar5 == 0) {
            piVar3[0x27] = local_2c;
          }
          else {
            iVar9 = FUN_0010b0f4(piVar3,iVar5);
            *(int *)(iVar9 + 0x10) = iVar4;
          }
          iVar5 = iVar5 + 1;
          iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
        } while (iVar5 <= iVar4);
      }
      FUN_0010b3fe(param_1,param_2);
      return piVar3;
    }
  } while( true );
}

/* FUN_001122ce @ 0x1122ce (385 bytes) */
int FUN_001122ce(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_10;
  
  piVar3 = (int *)FUN_0010b180(param_1,param_2);
  cVar2 = (**(code **)(*piVar3 + 0x60))(piVar3);
  if (cVar2 == '\0') {
    iVar4 = FUN_0010b0f4(param_1,param_2);
    return *(undefined4 *)(iVar4 + 0x10);
  }
  iVar4 = FUN_0010b0f4(param_1,0);
  iVar4 = FUN_000f5ede(*(undefined4 *)(iVar4 + 0x10));
  iVar5 = FUN_0010b0f4(param_1,param_2);
  bVar1 = *(byte *)(iVar4 + 0x10 + iVar5);
  if (-1 < iVar4) {
    FUN_0010b0f4(piVar3,0);
  }
  local_10 = 1;
  while( true ) {
    iVar4 = (**(code **)(*piVar3 + 0x14))(piVar3);
    if (iVar4 < local_10) {
      iVar4 = FUN_0010b0f4(param_1,param_2);
      return *(undefined4 *)(iVar4 + 0x10);
    }
    iVar4 = FUN_0010b0f4(piVar3,local_10);
    if (*(char *)(bVar1 + 0x10 + iVar4) != '\x04') break;
    local_10 = local_10 + 1;
  }
  uVar7 = *(undefined4 *)(param_3 + 8);
  uVar6 = FUN_0010b180(piVar3,local_10);
  FUN_0010ba02(param_1,param_2,uVar6,1,uVar7);
  cVar2 = FUN_0010a67e(piVar3,param_3);
  if (cVar2 != '\0') {
    (**(code **)(*piVar3 + 0xc))(piVar3,1,*(undefined4 *)(param_3 + 8));
  }
  iVar4 = FUN_0010b0f4(param_1,param_2);
  uVar7 = *(undefined4 *)(iVar4 + 0x10);
  iVar4 = FUN_0010b0f4(piVar3,local_10);
  uVar7 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar7);
  return uVar7;
}

/* FUN_00112450 @ 0x112450 (633 bytes) */
int FUN_00112450(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  undefined4 local_24;
  int local_20;
  undefined4 local_10;
  
  iVar13 = *(int *)(param_4 + 0x3f4);
  iVar1 = param_1[2];
  iVar2 = param_1[0x56];
  iVar3 = param_1[4];
  iVar8 = FUN_00109e42(param_1,iVar13);
  iVar9 = FUN_0010b0f4(param_1,0);
  iVar9 = *(int *)(iVar9 + 0x10);
  iVar7 = param_1[0x48];
  iVar4 = param_1[0x49];
  local_24 = 0;
  local_20 = 0;
  local_10 = 0;
  if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
    FUN_0010a980(param_1,&local_24);
  }
  uVar10 = FUN_0010b180(param_1,param_2);
  uVar5 = param_1[param_2 * 6 + 0x28];
  iVar11 = FUN_0010b0f4(param_1,param_2);
  uVar6 = *(undefined4 *)(iVar11 + 0x10);
  if (param_3 == '\0') {
    iVar14 = 1;
    iVar11 = (**(code **)(*param_1 + 0x14))(param_1);
    if (0 < iVar11) {
      do {
        if (iVar14 != param_2) {
          uVar12 = FUN_0010b180(param_1,iVar14);
          FUN_0010b3fe(uVar12,param_4);
        }
        iVar14 = iVar14 + 1;
        iVar11 = (**(code **)(*param_1 + 0x14))(param_1);
      } while (iVar14 <= iVar11);
    }
    FUN_001a7d72(param_1);
  }
  else {
    (**(code **)(*param_1 + 0xc))(param_1,1,param_4);
  }
  FUN_0010db52(param_1,0x31,*(undefined4 *)(iVar13 + 8));
  param_1[4] = iVar3;
  param_1[0x58] = iVar8 + *(int *)(iVar13 + 0x46c);
  param_1[0x25] = param_1[0x53];
  param_1[0x26] = 0;
  *(char *)(param_1 + 0x48) = (char)iVar7;
  param_1[0x49] = iVar4;
  param_1[0x27] = iVar9;
  FUN_0010ba02(param_1,1,uVar10,0,param_4);
  FUN_00109c0e(param_1 + 0x29,1,(byte)uVar5 & 1);
  FUN_00109c0e(param_1 + 0x29,2,(byte)(uVar5 >> 1) & 1);
  iVar13 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar13 + 0x10) = uVar6;
  if (local_20 != 0) {
    FUN_0010c568(param_1,&local_24,param_3,param_4);
  }
  FUN_000e956e(iVar2,iVar1,param_1);
  return;
}

/* FUN_001126d2 @ 0x1126d2 (412 bytes) */
int FUN_001126d2(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined1 local_4c [4];
  float local_48;
  undefined1 local_34 [4];
  float local_30;
  
  cVar3 = FUN_00118f7a(*(undefined4 *)(*(int *)(param_1 + 0x88) + 8),param_2);
  if (cVar3 == '\0') {
    return;
  }
  iVar5 = FUN_0010b0f4(param_1,0);
  uVar1 = *(undefined4 *)(iVar5 + 0x10);
  cVar3 = FUN_000f7e7e(param_1,1,uVar1,local_34);
  cVar4 = FUN_000f7e7e(param_1,2,uVar1,local_4c);
  if (cVar3 == '\0') {
    iVar5 = FUN_0010b180(param_1,1);
    uVar1 = *(undefined4 *)(iVar5 + 0x98);
    iVar5 = FUN_0010b180(param_1,2);
    uVar2 = *(undefined4 *)(iVar5 + 0x98);
    cVar3 = FUN_0012df9c(uVar1);
    if (cVar3 == '\0') {
      return;
    }
    cVar3 = FUN_0012df9c(uVar2);
    if (cVar3 != '\0') {
      return;
    }
  }
  else if (cVar4 != '\0') {
    if (((local_30 != FLOAT_001c5ba4) && (local_30 != FLOAT_001c5bdc)) &&
       (local_30 != FLOAT_001c5bd0)) {
      if (local_30 != FLOAT_001c5c70) {
        return;
      }
      if (NAN(local_30) || NAN(FLOAT_001c5c70)) {
        return;
      }
    }
    if (local_48 == FLOAT_001c5ba4) {
      return;
    }
    if (local_48 == FLOAT_001c5bdc) {
      return;
    }
    if (local_48 == FLOAT_001c5bd0) {
      return;
    }
    if (local_48 == FLOAT_001c5c70) {
      return;
    }
  }
  FUN_0010fe82(param_1,1,2,param_2);
  return;
}

/* FUN_0011286e @ 0x11286e (811 bytes) */
int FUN_0011286e(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  byte bVar12;
  byte bVar13;
  
  uVar9 = FUN_0010b180(param_1,1);
  bVar12 = (byte)*(uint *)(param_1 + 0xb8) & 1;
  bVar6 = (byte)(*(uint *)(param_1 + 0xb8) >> 1) & 1;
  iVar10 = FUN_0010b0f4(param_1,1);
  uVar1 = *(undefined4 *)(iVar10 + 0x10);
  uVar11 = FUN_0010b180(param_1,2);
  bVar13 = (byte)*(uint *)(param_1 + 0xd0) & 1;
  bVar7 = (byte)(*(uint *)(param_1 + 0xd0) >> 1) & 1;
  iVar10 = FUN_0010b0f4(param_1,2);
  uVar2 = *(undefined4 *)(iVar10 + 0x10);
  uVar3 = *(undefined4 *)(param_1 + 0x14c);
  piVar4 = *(int **)(param_1 + 0x158);
  cVar8 = (**(code **)(*piVar4 + 0x24))(piVar4);
  if (cVar8 != '\0') {
    FUN_000e9644(piVar4);
    piVar4[0x4a] = 0;
  }
  FUN_001a7d72(param_1);
  iVar10 = ((int (*)())FUN_0011074c)(param_1);
  uVar5 = *(undefined4 *)(PTR_DAT_00213569 + iVar10 * 4);
  iVar10 = *(int *)(PTR_DAT_00213565 + iVar10 * 4);
  piVar4 = (int *)(*(int *)(param_2 + 0x3f4) + 0x21c);
  *piVar4 = *piVar4 + 1;
  FUN_0010d8fc(param_1,uVar5,param_2);
  *(undefined4 *)(param_1 + 0x94) = uVar3;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001cbe88;
  if (iVar10 == 0) {
    FUN_0010ba02(param_1,1,uVar9,0,param_2);
    FUN_00109c0e(param_1 + 0xa4,1,bVar12);
    FUN_00109c0e(param_1 + 0xa4,2,bVar6);
    iVar10 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar10 + 0x10) = uVar1;
    FUN_0010ba02(param_1,2,uVar11,0,param_2);
    FUN_00109c0e(param_1 + 0xbc,1,bVar13);
    FUN_00109c0e(param_1 + 0xbc,2,bVar7);
    iVar10 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar10 + 0x10) = uVar2;
    return;
  }
  FUN_0010ba02(param_1,2,uVar9,0,param_2);
  FUN_00109c0e(param_1 + 0xbc,1,bVar12);
  FUN_00109c0e(param_1 + 0xbc,2,bVar6);
  iVar10 = FUN_0010b0f4(param_1,2);
  *(undefined4 *)(iVar10 + 0x10) = uVar1;
  FUN_0010ba02(param_1,1,uVar11,0,param_2);
  FUN_00109c0e(param_1 + 0xa4,1,bVar13);
  FUN_00109c0e(param_1 + 0xa4,2,bVar7);
  iVar10 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar10 + 0x10) = uVar2;
  return;
}

/* FUN_00112ba2 @ 0x112ba2 (1198 bytes) */
int FUN_00112ba2(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  uint param_3;
  int param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  byte bVar16;
  byte bVar17;
  
  uVar9 = FUN_0010b180(param_1,1);
  bVar17 = (byte)*(uint *)(param_1 + 0xb8) & 1;
  bVar6 = (byte)(*(uint *)(param_1 + 0xb8) >> 1) & 1;
  iVar10 = FUN_0010b0f4(param_1,1);
  uVar1 = *(undefined4 *)(iVar10 + 0x10);
  uVar11 = FUN_0010b180(param_1,2);
  bVar16 = (byte)*(uint *)(param_1 + 0xd0) & 1;
  bVar7 = (byte)(*(uint *)(param_1 + 0xd0) >> 1) & 1;
  iVar10 = FUN_0010b0f4(param_1,2);
  uVar2 = *(undefined4 *)(iVar10 + 0x10);
  iVar10 = *(int *)(param_4 + 0x3f4);
  iVar12 = FUN_00109e42(param_1,iVar10);
  uVar3 = *(undefined4 *)(param_1 + 0x98);
  uVar4 = *(undefined4 *)(param_1 + 0x94);
  iVar13 = FUN_0010b0f4(param_1,0);
  uVar5 = *(undefined4 *)(iVar13 + 0x10);
  FUN_001a7d72(param_1);
  cVar8 = (**(code **)(*param_2 + 0x48))(param_2);
  if ((cVar8 == '\0') || (((int)(char)param_2[0x57] >> ((byte)param_3 & 0x1f) & 1U) == 0)) {
    *(int *)(iVar10 + 0x224) = *(int *)(iVar10 + 0x224) + 1;
    FUN_0010da48(param_1,0x24,param_4);
    *(undefined4 *)(param_1 + 0x94) = uVar4;
    *(undefined4 *)(param_1 + 0x98) = uVar3;
    *(undefined4 *)(param_1 + 0x9c) = uVar5;
    *(int *)(param_1 + 0x160) = iVar12 + *(int *)(iVar10 + 0x46c);
    FUN_0010ba02(param_1,1,param_2,0,param_4);
    if (*(int *)(iVar10 + 0x46c) < param_2[0x58]) {
      param_2[0x58] = param_2[0x58] + 1;
    }
    else {
      param_2[0x58] = *(int *)(iVar10 + 0x46c) + 1;
    }
    iVar10 = FUN_0010b0f4(param_1,1);
    *(uint *)(iVar10 + 0x10) = param_3;
    FUN_0010ba02(param_1,3,uVar9,0,param_4);
    FUN_00109c0e(param_1 + 0xd4,1,bVar17);
    FUN_00109c0e(param_1 + 0xd4,2,bVar6);
    iVar10 = FUN_0010b0f4(param_1,3);
    *(undefined4 *)(iVar10 + 0x10) = uVar1;
    FUN_0010ba02(param_1,2,uVar11,0,param_4);
    FUN_00109c0e(param_1 + 0xbc,1,bVar16);
    FUN_00109c0e(param_1 + 0xbc,2,bVar7);
    iVar10 = FUN_0010b0f4(param_1,2);
    *(undefined4 *)(iVar10 + 0x10) = uVar2;
    return;
  }
  uVar14 = FUN_0010b180(param_1,1);
  uVar15 = FUN_0010b180(param_1,2);
  *(int *)(iVar10 + 0x220) = *(int *)(iVar10 + 0x220) + 1;
  FUN_0010db52(param_1,0x31,param_4);
  *(undefined4 *)(param_1 + 0x94) = uVar4;
  *(undefined4 *)(param_1 + 0x98) = uVar3;
  *(undefined4 *)(param_1 + 0x9c) = uVar5;
  *(int *)(param_1 + 0x160) = iVar12 + *(int *)(iVar10 + 0x46c);
  if (((float)param_2[(param_3 & 0xff) * 6 + 8] == 0.0) &&
     (!NAN((float)param_2[(param_3 & 0xff) * 6 + 8]))) {
    FUN_0010ba02(param_1,1,uVar9,0,param_4);
    FUN_00109c0e(param_1 + 0xa4,1,bVar17);
    FUN_00109c0e(param_1 + 0xa4,2,bVar6);
    iVar10 = FUN_0010b0f4(param_1,1);
    *(undefined4 *)(iVar10 + 0x10) = uVar1;
    FUN_0010b3fe(uVar15,param_4);
    return;
  }
  FUN_0010ba02(param_1,1,uVar11,0,param_4);
  FUN_00109c0e(param_1 + 0xa4,1,bVar16);
  FUN_00109c0e(param_1 + 0xa4,2,bVar7);
  iVar10 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar10 + 0x10) = uVar2;
  FUN_0010b3fe(uVar14,param_4);
  return;
}

/* FUN_00113058 @ 0x113058 (103 bytes) */
int FUN_00113058(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x172c) = 0;
  *(undefined4 *)(param_1 + 0x1728) = 0;
  *(undefined4 *)(param_1 + 0x1730) = 0;
  _memset((void *)(param_1 + 0x68),0,0xd00);
  _memset((void *)(param_1 + 0xd68),0,0x9c0);
  return;
}

/* FUN_001130c0 @ 0x1130c0 (168 bytes) */
int FUN_001130c0(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fcca8;
  param_1[2] = 0;
  param_1[4] = 1;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  return;
}

/* FUN_00113168 @ 0x113168 (168 bytes) */
int FUN_00113168(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fcca8;
  param_1[2] = 0;
  param_1[4] = 1;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  return;
}

/* FUN_00113210 @ 0x113210 (35 bytes) */
int FUN_00113210(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 >> 3) + 0x1734 + param_1);
  *pbVar1 = *pbVar1 | (byte)(1 << ((byte)param_2 & 7));
  return;
}

/* FUN_00113234 @ 0x113234 (37 bytes) */
int FUN_00113234(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 >> 3) + 0x1734 + param_1);
  *pbVar1 = *pbVar1 & ~(byte)(1 << ((byte)param_2 & 7));
  return;
}

/* FUN_0011325a @ 0x11325a (90 bytes) */
int FUN_0011325a(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 5;
  iVar1 = param_1;
  do {
    *(undefined1 *)(iVar1 + 0x1734) = 0xff;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 5;
  iVar1 = param_1;
  do {
    *(undefined1 *)(iVar1 + 0x1739) = 0;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar2 != 0xb);
  iVar1 = 0x28;
  do {
    ((int (*)())FUN_00113210)(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x2d);
  return;
}

/* FUN_001132b4 @ 0x1132b4 (32 bytes) */
int FUN_001132b4(param_1, param_2)
  int param_1;
  int param_2;
{
  return (int)(uint)*(byte *)((param_2 >> 3) + 0x1734 + param_1) >> ((byte)param_2 & 7) & 1;
}

/* FUN_001132d4 @ 0x1132d4 (14 bytes) */
int FUN_001132d4(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0;
  return;
}

/* FUN_001132e2 @ 0x1132e2 (39 bytes) */
int FUN_001132e2()
{
  int in_stack_00000024;
  
  if (*(int *)(in_stack_00000024 + 0x3f4) != 0) {
    FUN_000e27ca(in_stack_00000024,0xf);
  }
  return 0;
}

/* FUN_0011330a @ 0x11330a (25 bytes) */
int FUN_0011330a(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  param_1 = *(undefined4 *)(param_2 + 8);
  FUN_000e27ca();
  return;
}

/* FUN_00113324 @ 0x113324 (43 bytes) */
int FUN_00113324(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = FUN_0010ed70(0xa4,param_3);
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xffff7fff;
  *(undefined4 *)(iVar1 + 300) = param_2;
  return;
}

/* FUN_00113350 @ 0x113350 (21 bytes) */
int FUN_00113350()
{
  undefined4 uStack00000004;
  int in_stack_00000010;
  
  uStack00000004 = *(undefined4 *)(in_stack_00000010 + 0xb8);
  FUN_001a7bca();
  return;
}

/* FUN_00113366 @ 0x113366 (127 bytes) */
int FUN_00113366(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar1 + 0xc70) = 4;
  puVar2 = PTR_FUN_00213575;
  *(undefined **)(iVar1 + 0xc74) = PTR_FUN_00213575;
  *(undefined4 *)(iVar1 + 0xc78) = 0;
  *(undefined4 *)(iVar1 + 0xc60) = 0x4c;
  *(undefined4 *)(iVar1 + 0x298) = 4;
  *(undefined **)(iVar1 + 0x29c) = puVar2;
  *(undefined4 *)(iVar1 + 0x2a0) = 0;
  *(undefined4 *)(iVar1 + 0x288) = 0x4d;
  *(undefined **)(iVar1 + 0xd08) = PTR_DAT_00213571;
  puVar2 = PTR_DAT_0021357d;
  *(undefined **)(iVar1 + 0xc9c) = PTR_DAT_0021357d;
  *(undefined **)(*(int *)(param_1 + 0xc) + 0xe28) = puVar2;
  return;
}

/* FUN_001133e6 @ 0x1133e6 (14 bytes) */
int FUN_001133e6(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x60);
}

/* FUN_001133f4 @ 0x1133f4 (14 bytes) */
int FUN_001133f4(param_1)
  int param_1;
{
  return *(undefined4 *)(*(int *)(param_1 + 0x54) + 100);
}

/* FUN_00113402 @ 0x113402 (10 bytes) */
int FUN_00113402()
{
  return 0x10c;
}

/* FUN_0011340c @ 0x11340c (10 bytes) */
int FUN_0011340c()
{
  return 0xb5;
}

/* FUN_00113416 @ 0x113416 (10 bytes) */
int FUN_00113416()
{
  return 0xb5;
}

/* FUN_00113420 @ 0x113420 (39 bytes) */
int FUN_00113420()
{
  int in_stack_0000001c;
  
  if (*(int *)(in_stack_0000001c + 0x3f4) != 0) {
    FUN_000e27ca(in_stack_0000001c,0xf);
  }
  return 0;
}

/* FUN_00113448 @ 0x113448 (39 bytes) */
int FUN_00113448()
{
  int in_stack_00000028;
  
  if (*(int *)(in_stack_00000028 + 0x3f4) != 0) {
    FUN_000e27ca(in_stack_00000028,0xf);
  }
  return 0;
}

/* FUN_00113470 @ 0x113470 (171 bytes) */
int FUN_00113470(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  short *param_4;
{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = *(undefined4 *)(param_2 + 0x3a0);
  uVar2 = *(undefined4 *)(param_2 + 8);
  sVar1 = *param_4;
  uVar3 = FUN_000edadc(param_2,*(byte *)(param_4 + 1) & 0x3f);
  uVar4 = FUN_0012eb84(uVar4,uVar3,(int)sVar1,0);
  iVar5 = FUN_0010ed70(0xa4,uVar2);
  FUN_0010a3c2(iVar5,0,uVar4);
  *(int *)(iVar5 + 300) = (int)sVar1;
  FUN_000fbaca();
  return;
}

/* FUN_0011351c @ 0x11351c (16 bytes) */
int FUN_0011351c()
{
  ((int (*)())FUN_00113470)();
  return;
}

/* FUN_0011352c @ 0x11352c (240 bytes) */
int FUN_0011352c(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    puVar1 = *(undefined4 **)(iVar2 + 0x60);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1);
      (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),puVar1);
      iVar2 = *(int *)(param_1 + 4);
    }
    if (*(int *)(iVar2 + 100) != 0) {
      (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),*(int *)(iVar2 + 100));
      iVar2 = *(int *)(param_1 + 4);
    }
    (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),iVar2);
  }
  iVar2 = *(int *)(param_1 + 8);
  if ((*(int *)(param_1 + 4) != iVar2) && (iVar2 != 0)) {
    puVar1 = *(undefined4 **)(iVar2 + 0x60);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1);
      (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),puVar1);
      iVar2 = *(int *)(param_1 + 8);
    }
    if (*(int *)(iVar2 + 100) != 0) {
      (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),*(int *)(iVar2 + 100));
      iVar2 = *(int *)(param_1 + 8);
    }
    (**(code **)(param_2 + 0x90))(*(undefined4 *)(param_2 + 0x98),iVar2);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* FUN_0011361c @ 0x11361c (163 bytes) */
int FUN_0011361c(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  *param_1 = PTR_DAT_00213581 + 8;
  *param_1 = PTR_DAT_0021356d + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = FUN_000e27f6(param_2,0x1740);
  if (iVar1 != 0) {
    FUN_001319cc(iVar1,param_2,1);
  }
  param_1[1] = iVar1;
  iVar1 = FUN_000e27f6(param_2,0x1744);
  if (iVar1 != 0) {
    FUN_001306b2(iVar1,param_2,1);
  }
  param_1[2] = iVar1;
  return;
}

/* FUN_001136d6 @ 0x1136d6 (163 bytes) */
int FUN_001136d6(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  *param_1 = PTR_DAT_00213581 + 8;
  *param_1 = PTR_DAT_0021356d + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = FUN_000e27f6(param_2,0x1740);
  if (iVar1 != 0) {
    FUN_001319cc(iVar1,param_2,1);
  }
  param_1[1] = iVar1;
  iVar1 = FUN_000e27f6(param_2,0x1744);
  if (iVar1 != 0) {
    FUN_001306b2(iVar1,param_2,1);
  }
  param_1[2] = iVar1;
  return;
}

/* FUN_00113790 @ 0x113790 (174 bytes) */
int FUN_00113790(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  *param_1 = PTR_DAT_00213581 + 8;
  *param_1 = PTR_DAT_0021356d + 8;
  *param_1 = PTR_DAT_00213579 + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = FUN_000e27f6(param_2,0x1740);
  if (iVar1 != 0) {
    FUN_00131ce2(iVar1,param_2,1);
  }
  param_1[1] = iVar1;
  iVar1 = FUN_000e27f6(param_2,0x1944);
  if (iVar1 != 0) {
    FUN_001a58de(iVar1,param_2,1);
  }
  param_1[2] = iVar1;
  return;
}

/* FUN_00113860 @ 0x113860 (174 bytes) */
int FUN_00113860(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  int iVar1;
  
  *param_1 = PTR_DAT_00213581 + 8;
  *param_1 = PTR_DAT_0021356d + 8;
  *param_1 = PTR_DAT_00213579 + 8;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar1 = FUN_000e27f6(param_2,0x1740);
  if (iVar1 != 0) {
    FUN_00131ce2(iVar1,param_2,1);
  }
  param_1[1] = iVar1;
  iVar1 = FUN_000e27f6(param_2,0x1944);
  if (iVar1 != 0) {
    FUN_001a58de(iVar1,param_2,1);
  }
  param_1[2] = iVar1;
  return;
}

/* FUN_00113930 @ 0x113930 (54 bytes) */
int FUN_00113930(param_1)
  int param_1;
{
  int iVar1;
  
  if (param_1 == 0x18) {
    return 3;
  }
  iVar1 = FUN_00109e62(param_1);
  if (iVar1 != 0x15) {
    if (iVar1 != 0x16) {
      return 0;
    }
    return 2;
  }
  return 1;
}

/* FUN_00113966 @ 0x113966 (66 bytes) */
int FUN_00113966(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 < 1) {
    return -1;
  }
  iVar2 = *(int *)(param_1 + 4 + param_2 * 4);
  if (iVar2 == *(int *)(param_1 + 4)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      if (param_2 == iVar3) {
        return -1;
      }
      piVar1 = (int *)(param_1 + 8);
      param_1 = param_1 + 4;
    } while (iVar2 != *piVar1);
  }
  return iVar3;
}

/* FUN_001139a8 @ 0x1139a8 (63 bytes) */
int FUN_001139a8(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 == 0x16) {
    if ((param_2 != 0) && (param_2 == 1)) {
      return 2;
    }
  }
  else if (param_1 == 0x17) {
    if (param_2 != 0) {
      if (param_2 == 1) {
        param_2 = 3;
      }
      return param_2;
    }
    return 1;
  }
  return param_2;
}

/* FUN_001139e8 @ 0x1139e8 (106 bytes) */
int FUN_001139e8(param_1, param_2, param_3)
  int *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((*param_1 != *param_2) && (param_1[5] <= param_2[5])) {
    iVar3 = 1;
    do {
      if (param_1[1] == 0) {
        *(undefined4 *)(param_3 + -4 + iVar3 * 4) = 0xffffffff;
      }
      else {
        iVar1 = 0;
        piVar2 = param_2;
        while (param_1[1] != piVar2[1]) {
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 1;
          if (iVar1 == 4) {
            return 0;
          }
        }
        *(int *)(param_3 + -4 + iVar3 * 4) = iVar1;
      }
      iVar3 = iVar3 + 1;
      param_1 = param_1 + 1;
    } while (iVar3 != 5);
    return 1;
  }
  return 0;
}

/* FUN_00113a52 @ 0x113a52 (45 bytes) */
int FUN_00113a52(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000f60f4(param_1);
  iVar2 = FUN_000f60f4(param_2);
  return iVar1 < iVar2;
}

/* FUN_00113a80 @ 0x113a80 (34 bytes) */
int FUN_00113a80(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 != 6) {
    if (param_1 == 7) {
      param_2 = param_2 * 2 + 1;
    }
    return param_2;
  }
  return param_2 * 2;
}

/* FUN_00113aa2 @ 0x113aa2 (16 bytes) */
int FUN_00113aa2()
{
  undefined4 *in_stack_00000010;
  
  *in_stack_00000010 = 0;
  return 0;
}

/* FUN_00113ab2 @ 0x113ab2 (163 bytes) */
int FUN_00113ab2(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x3c8) == '\0') {
    iVar1 = *(int *)(param_2 + 0x394);
    iVar4 = (**(code **)(*param_1 + 0xe4))(param_1);
    iVar1 = *(int *)(iVar1 + 0x98);
    iVar2 = *(int *)(iVar1 + 8);
    while (iVar2 != 0) {
      if (((*(byte *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) == 0xa4)) {
        cVar3 = FUN_00137bae(param_2,iVar4);
        while (cVar3 == '\0') {
          iVar4 = iVar4 + 1;
          cVar3 = FUN_00137bae(param_2,iVar4);
        }
        FUN_00137b7e(param_2,iVar4);
        *(int *)(iVar1 + 0x94) = iVar4;
        *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x40;
      }
      iVar1 = *(int *)(iVar1 + 8);
      iVar2 = *(int *)(iVar1 + 8);
    }
  }
  return;
}

/* FUN_00113b56 @ 0x113b56 (55 bytes) */
int FUN_00113b56(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((cVar1 != '\0') && (1 < param_1[0x4f] - 6U)) {
    return 1;
  }
  return 0;
}

/* FUN_00113b8e @ 0x113b8e (50 bytes) */
int FUN_00113b8e(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((cVar1 != '\0') && (param_1[0x4f] == 0x18)) {
    return 1;
  }
  return 0;
}

/* FUN_00113bc0 @ 0x113bc0 (55 bytes) */
int FUN_00113bc0(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((cVar1 != '\0') && (param_1[0x4f] - 0x16U < 2)) {
    return 1;
  }
  return 0;
}

/* FUN_00113bf8 @ 0x113bf8 (70 bytes) */
int FUN_00113bf8(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x68))(param_1);
  if ((cVar1 != '\0') &&
     ((0x18 < (uint)param_1[0x4f] || ((1 << ((byte)param_1[0x4f] & 0x1f) & 0x1c000c0U) == 0)))) {
    return 1;
  }
  return 0;
}

/* FUN_00113c3e @ 0x113c3e (74 bytes) */
int FUN_00113c3e(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  *param_1 = param_2;
  param_1[5] = 0;
  iVar1 = ((int (*)())FUN_00113930)(*(undefined4 *)(param_2 + 0x13c));
  param_1[6] = iVar1;
  iVar1 = 4;
  do {
    param_1[1] = 0;
    param_1[7] = 0;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_00113c88 @ 0x113c88 (74 bytes) */
int FUN_00113c88(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  *param_1 = param_2;
  param_1[5] = 0;
  iVar1 = ((int (*)())FUN_00113930)(*(undefined4 *)(param_2 + 0x13c));
  param_1[6] = iVar1;
  iVar1 = 4;
  do {
    param_1[1] = 0;
    param_1[7] = 0;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

