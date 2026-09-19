#include "decls.h"

/* FUN_000fdd90 @ 0xfdd90 (649 bytes) */
int FUN_000fdd90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int local_14;
  int local_10;
  
  uVar1 = FUN_000edadc(param_1,param_2);
  iVar2 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar1,param_3,0);
  piVar3 = *(int **)(iVar2 + 0x18);
  if (*piVar3 == 0) {
    piVar3 = (int *)FUN_001a7f7c(piVar3,0);
    local_14 = *piVar3;
    local_10 = *(int *)(param_1 + 0x3a0);
    puVar7 = *(uint **)(local_10 + 0x20);
    uVar6 = puVar7[1];
    if (uVar6 < *puVar7) goto LAB_000fde02;
  }
  else {
    if (piVar3[1] == 0) {
      *(undefined4 *)piVar3[2] = 0;
      piVar3[1] = 1;
    }
    local_14 = *(int *)piVar3[2];
    local_10 = *(int *)(param_1 + 0x3a0);
    puVar7 = *(uint **)(local_10 + 0x20);
    uVar6 = puVar7[1];
    if (uVar6 < *puVar7) {
LAB_000fde02:
      _memset((void *)(uVar6 * 4 + puVar7[2]),0,4);
      puVar7[1] = uVar6 + 1;
      *(int *)(uVar6 * 4 + puVar7[2]) = local_14;
      *(int *)(local_10 + 0x1c) = *(int *)(local_10 + 0x1c) + 1;
      goto joined_r0x000fdec9;
    }
  }
  piVar3 = (int *)FUN_001a7f7c(puVar7,uVar6);
  *piVar3 = local_14;
  *(int *)(local_10 + 0x1c) = *(int *)(local_10 + 0x1c) + 1;
joined_r0x000fdec9:
  if (param_2 == 1) {
    if (0 < param_4) {
      iVar5 = 0;
      iVar2 = local_14;
      do {
        *(undefined4 *)(iVar2 + 0x20) = param_5[iVar5];
        *(undefined4 *)(iVar2 + 0x1c) = 2;
        *(byte *)(local_14 + 0x15c) =
             *(byte *)(local_14 + 0x15c) | (byte)(1 << ((byte)iVar5 & 0x1f));
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x18;
      } while (param_4 != iVar5);
      return;
    }
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_4 < 1) {
        bVar4 = *(byte *)(local_14 + 0x15c);
      }
      else {
        iVar5 = 0;
        iVar2 = local_14;
        do {
          *(undefined4 *)(iVar2 + 0x20) = *param_5;
          *(undefined4 *)(iVar2 + 0x1c) = 4;
          bVar4 = *(byte *)(local_14 + 0x15c) | (byte)(1 << ((byte)iVar5 & 0x1f));
          *(byte *)(local_14 + 0x15c) = bVar4;
          iVar5 = iVar5 + 1;
          iVar2 = iVar2 + 0x18;
        } while (param_4 != iVar5);
      }
      uVar1 = *(undefined4 *)(local_14 + 0x20);
      *(undefined4 *)(local_14 + 0x38) = uVar1;
      *(undefined4 *)(local_14 + 0x50) = uVar1;
      *(undefined4 *)(local_14 + 0x68) = uVar1;
      *(undefined4 *)(local_14 + 0x34) = 4;
      *(undefined4 *)(local_14 + 0x4c) = 4;
      *(undefined4 *)(local_14 + 100) = 4;
      *(byte *)(local_14 + 0x15c) = bVar4 | 0xe;
    }
  }
  else if (param_2 == 2) {
    if (0 < param_4) {
      iVar5 = 0;
      iVar2 = local_14;
      do {
        *(undefined4 *)(iVar2 + 0x20) = param_5[iVar5];
        *(undefined4 *)(iVar2 + 0x1c) = 3;
        *(byte *)(local_14 + 0x15c) =
             *(byte *)(local_14 + 0x15c) | (byte)(1 << ((byte)iVar5 & 0x1f));
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x18;
      } while (param_4 != iVar5);
      return;
    }
  }
  else if ((param_2 == 0x1d) && (0 < param_4)) {
    iVar5 = 0;
    iVar2 = local_14;
    do {
      *(undefined4 *)(iVar2 + 0x20) = param_5[iVar5];
      *(undefined4 *)(iVar2 + 0x1c) = 3;
      *(byte *)(local_14 + 0x15c) = *(byte *)(local_14 + 0x15c) | (byte)(1 << ((byte)iVar5 & 0x1f));
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 0x18;
    } while (param_4 != iVar5);
  }
  return;
}

/* FUN_000fe01a @ 0xfe01a (619 bytes) */
int FUN_000fe01a(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar3 = (*(uint *)(param_1 + 0x30) >> 0xe | *(uint *)(param_1 + 0x30)) & 1;
  iVar1 = FUN_000d927c(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3);
  if (iVar1 < 1) {
    iVar1 = FUN_000d9260(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3);
  }
  else {
    iVar2 = 0;
    do {
      FUN_000d9352(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3,iVar2,1,&local_1c);
      FUN_000e5d76(param_2,iVar2,local_1c != 0);
      ((int (*)())FUN_000fdd90)(param_1,0,iVar2,1,&local_1c);
      iVar2 = iVar2 + 1;
    } while (iVar1 != iVar2);
    iVar1 = FUN_000d9260(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3);
  }
  if (iVar1 < 1) {
    iVar1 = FUN_000d9244(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3);
  }
  else {
    iVar2 = 0;
    do {
      FUN_000d92f6(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3,iVar2,4,&local_1c);
      FUN_000e5afc(param_2,iVar2,local_1c,local_18,local_14,local_10);
      ((int (*)())FUN_000fdd90)(param_1,2,iVar2,4,&local_1c);
      iVar2 = iVar2 + 1;
    } while (iVar1 != iVar2);
    iVar1 = FUN_000d9244(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3);
  }
  if (iVar1 < 1) {
    return;
  }
  iVar2 = 0;
  do {
    FUN_000d9298(*(undefined4 *)(*(int *)(param_1 + 8) + 0xdc),uVar3,iVar2,4,&local_2c);
    FUN_000e5dbe(param_2,iVar2,local_2c,local_28,local_24,local_20);
    ((int (*)())FUN_000fdd90)(param_1,1,iVar2,4,&local_2c);
    iVar2 = iVar2 + 1;
  } while (iVar1 != iVar2);
  return;
}

/* FUN_000fe286 @ 0xfe286 (11842 bytes) */
int FUN_000fe286(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  ushort *param_3;
  uint *param_4;
  int param_5;
  uint *param_6;
  int param_7;
{
  undefined2 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  char cVar8;
  short sVar9;
  ushort uVar10;
  uint *puVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  int *piVar24;
  int *piVar25;
  byte bVar26;
  uint *puVar27;
  byte bVar28;
  uint uVar29;
  undefined4 in_XMM0_Da;
  undefined4 local_12c;
  undefined4 local_128;
  uint local_110;
  uint local_10c;
  uint local_104;
  undefined4 *local_f8;
  int local_dc;
  undefined4 local_d8;
  uint *local_b4;
  uint *local_b0;
  uint *local_ac;
  uint *local_a8;
  int local_a4;
  int local_a0;
  uint local_88;
  int local_54;
  undefined4 local_30 [3];
  undefined4 local_24;
  undefined4 local_20 [4];
  uint uVar11;
  
  bVar28 = *(byte *)((int)param_4 + 2);
  bVar26 = bVar28 >> 6 & 1;
  iVar14 = *(int *)(param_1 + 8);
  if ((((bVar28 & 0x3f) == 0x10) && (iVar14 != 0)) &&
     (*(char *)(*(int *)(iVar14 + 0x54) + 8) < '\0')) {
    sVar9 = 0xf;
  }
  else {
    sVar9 = (short)*param_4;
  }
  uVar11 = (uint)sVar9;
  local_10c = *(byte *)((int)param_4 + 2) & 0x3f;
  local_110 = uVar11;
  if ((*param_4 & 0x1800000) == 0x800000) {
    puVar1 = (undefined2 *)((-(uint)(bVar26 == 0) & 0xfffffffc) + 8 + (int)param_4);
    bVar28 = *(byte *)(puVar1 + 1);
    uVar2 = *puVar1;
    if ((bVar28 & 1) == 0) {
      local_110 = *(int *)(iVar14 + 0xf8) + 1;
      *(uint *)(iVar14 + 0xf8) = local_110;
      iVar14 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x26,local_110,0);
      *(uint *)(iVar14 + 0x30) = uVar11;
      uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar23 = (undefined4 *)FUN_001a7bca(uVar16,0x168);
      *puVar23 = uVar16;
      puVar20 = puVar23 + 1;
      FUN_0010f2b4(puVar20,0x84,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_0010a3c2)(puVar20,0,iVar14);
      iVar14 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x25,uVar2,0);
      ((int (*)())FUN_0010a3c2)(puVar20,1,iVar14);
      uVar16 = *(undefined4 *)(PTR_DAT_00213485 + (bVar28 >> 1 & 7) * 4);
      iVar15 = FUN_0010b0f4(puVar20,1);
      *(undefined4 *)(iVar15 + 0x10) = uVar16;
      *(undefined1 *)(puVar23 + 0x4c) = *(undefined1 *)(iVar14 + 0x30);
      FUN_001a7cd6(param_2,puVar20);
      local_10c = 0x22;
    }
    else {
      uVar29 = *(int *)(param_5 + 4) - 1;
      if (uVar29 < *(uint *)(param_5 + 4)) {
        piVar25 = (int *)(*(int *)(param_5 + 8) + uVar29 * 4);
      }
      else {
        piVar25 = (int *)0x0;
      }
      iVar14 = *piVar25;
      *(undefined1 *)(iVar14 + 0x135) = 1;
      uVar16 = FUN_000e9a1c(iVar14);
      uVar16 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x27,uVar16,0);
      if (local_10c == 1) {
        local_110 = *(int *)(*(int *)(param_1 + 8) + 0xfc) + 1;
        *(uint *)(*(int *)(param_1 + 8) + 0xfc) = local_110;
        iVar15 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x28,local_110,0);
        *(uint *)(iVar15 + 0x30) = uVar11;
        uVar17 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar23 = (undefined4 *)FUN_001a7bca(uVar17,0x168);
        *puVar23 = uVar17;
        puVar23 = puVar23 + 1;
        FUN_0010ac30(puVar23,0x82,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(puVar23,0,iVar15);
        ((int (*)())FUN_0010a3c2)(puVar23,1,uVar16);
        FUN_000e9512(iVar14,puVar23);
        FUN_0012a42e(iVar15,puVar23);
        FUN_0012a9e6(uVar16,1,puVar23);
        local_10c = 0x23;
      }
      else {
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_1 + 0x30) & 0x2000) != 0) {
            if (*(char *)(param_1 + 0x3d8) == '\0') {
              *(undefined1 *)(param_1 + 0x3d8) = 1;
              uVar17 = FUN_000edadc(param_1,local_10c);
              *(undefined4 *)(param_1 + 1000) = uVar17;
            }
            else {
              FUN_000edadc(param_1,local_10c);
            }
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x3c8) = 1;
        }
        local_110 = *(int *)(*(int *)(param_1 + 8) + 0x100) + 1;
        *(uint *)(*(int *)(param_1 + 8) + 0x100) = local_110;
        uVar17 = FUN_000edadc(param_1,0x24);
        iVar15 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar17,local_110,0);
        *(uint *)(iVar15 + 0x30) = uVar11;
        uVar17 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar23 = (undefined4 *)FUN_001a7bca(uVar17,0x168);
        *puVar23 = uVar17;
        puVar23 = puVar23 + 1;
        FUN_0010ac30(puVar23,0x82,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(puVar23,0,iVar15);
        ((int (*)())FUN_0010a3c2)(puVar23,1,uVar16);
        FUN_000e9512(iVar14,puVar23);
        FUN_0012a42e(iVar15,puVar23);
        FUN_0012a9e6(uVar16,1,puVar23);
        local_10c = 0x24;
      }
    }
    *param_4 = *param_4 & 0xfe7fffff;
    bVar28 = *(byte *)((int)param_4 + 2);
  }
  if (((bVar28 & 0x3f) == 0x1c) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) & 8) == 0)) {
    *param_4 = *param_4 & 0xffc0ffff | 0x10000;
    bVar28 = *(byte *)((int)param_4 + 2);
    puVar12 = param_4 + 1;
    if ((bVar28 & 0x40) == 0) {
      puVar12 = param_4;
    }
    *(short *)param_4 = (short)puVar12[1];
    *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) & 0xfb;
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  if ((local_10c == 0x20) && ((*param_4 & 0x1800000) == 0x1000000)) {
    bVar5 = true;
LAB_000fe90e:
    local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
    *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    bVar28 = *(byte *)((int)param_4 + 2) & 0x3f;
    if (bVar5) {
      local_dc = 0x10b;
    }
    else {
      local_dc = (uint)(bVar28 == 0x1c) * 3 + 0xfb;
    }
    if (*(char *)((int)param_4 + 3) < '\0') {
      uVar11 = param_4[1] << 0x10 | local_110;
      iVar14 = 2;
    }
    else {
      iVar14 = 1;
      uVar11 = local_110;
    }
    iVar14 = (iVar14 + 1) - (uint)((*param_4 & 0x400000) == 0);
    uVar10 = *(ushort *)((int)param_4 + 2) & 0x180;
    if (uVar10 == 0x100) {
      puVar12 = param_4 + iVar14;
      if (bVar5) {
        local_f8 = (undefined4 *)((int (*)())FUN_0010a17a)(local_dc,*(undefined4 *)(param_1 + 8));
        local_f8[0x27] = DAT_001c66f4;
        local_f8[0x50] = DAT_001c66c0;
        local_f8[0x21] = 2;
        uVar16 = FUN_000edadc(param_1,bVar28);
        iVar15 = FUN_0010b0f4(local_f8,2);
        *(undefined4 *)(iVar15 + 8) = 0xffffffff;
        *(undefined4 *)(iVar15 + 0xc) = uVar16;
        local_d8 = 1;
      }
      else {
        uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        local_f8 = (undefined4 *)FUN_001a7bca(uVar16,0x168);
        *local_f8 = uVar16;
        local_f8 = local_f8 + 1;
        FUN_0010d240(local_f8,local_dc,*(undefined4 *)(param_1 + 8));
        uVar16 = FUN_000edadc(param_1,bVar28);
        iVar15 = FUN_0010b0f4(local_f8,1);
        *(uint *)(iVar15 + 8) = uVar11;
        *(undefined4 *)(iVar15 + 0xc) = uVar16;
        local_d8 = 2;
      }
      uVar16 = FUN_000edadc(param_1,4);
      iVar15 = FUN_0010b0f4(local_f8,0);
      *(uint *)(iVar15 + 8) = local_104;
      *(undefined4 *)(iVar15 + 0xc) = uVar16;
      if ((*param_4 & 0x4000000) == 0) {
        uVar16 = FUN_000edadc(param_1,*(byte *)((int)puVar12 + 2) & 0x3f);
        uVar11 = *puVar12;
        iVar14 = FUN_0010b0f4(local_f8,local_d8);
        *(uint *)(iVar14 + 8) = (uint)(ushort)uVar11;
        *(undefined4 *)(iVar14 + 0xc) = uVar16;
      }
      else {
        uVar11 = param_4[iVar14 + 2];
        uVar16 = ((int (*)())FUN_0010a17a)(0xc6,*(undefined4 *)(param_1 + 8));
        uVar17 = FUN_000edadc(param_1,4);
        iVar14 = FUN_0010b0f4(uVar16,0);
        *(uint *)(iVar14 + 8) = local_104;
        *(undefined4 *)(iVar14 + 0xc) = uVar17;
        uVar17 = FUN_000edadc(param_1,*(byte *)((int)puVar12 + 2) & 0x3f);
        uVar29 = *puVar12;
        iVar14 = FUN_0010b0f4(uVar16,1);
        *(uint *)(iVar14 + 8) = (uint)(ushort)uVar29;
        *(undefined4 *)(iVar14 + 0xc) = uVar17;
        FUN_000f9ef4(uVar16,param_1,2,uVar11,uVar11,uVar11,uVar11);
        FUN_001a7cd6(param_2,uVar16);
        uVar16 = FUN_000edadc(param_1,4);
        iVar14 = FUN_0010b0f4(local_f8,local_d8);
        *(uint *)(iVar14 + 8) = local_104;
        *(undefined4 *)(iVar14 + 0xc) = uVar16;
      }
      local_20[0] = DAT_001c66c0;
      FUN_000fb2d4(param_1,local_20,puVar12,local_d8,local_f8);
    }
    else if (uVar10 == 0) {
      uVar29 = param_4[iVar14];
      uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      local_f8 = (undefined4 *)FUN_001a7bca(uVar16,0x168);
      *local_f8 = uVar16;
      local_f8 = local_f8 + 1;
      FUN_0010d240(local_f8,local_dc,*(undefined4 *)(param_1 + 8));
      uVar16 = FUN_000edadc(param_1,4);
      iVar14 = FUN_0010b0f4(local_f8,0);
      *(uint *)(iVar14 + 8) = local_104;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      uVar16 = FUN_000edadc(param_1,bVar28);
      iVar14 = FUN_0010b0f4(local_f8,1);
      *(uint *)(iVar14 + 8) = uVar11;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      FUN_000f9ef4(local_f8,param_1,2,uVar29,uVar29,uVar29,uVar29);
      local_d8 = 1;
    }
    else {
      local_f8 = (undefined4 *)0x0;
      local_d8 = 1;
    }
    iVar14 = FUN_0010b0f4(local_f8,local_d8);
    local_24 = *(undefined4 *)(iVar14 + 0x10);
    piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar8 = (**(code **)(*piVar25 + 0x104))(piVar25,local_f8,local_d8,&local_24,0);
    if (cVar8 == '\0') {
      iVar15 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar15;
      uVar21 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      uVar16 = local_f8[0x32];
      uVar17 = local_f8[0x31];
      iVar14 = FUN_0010b0f4(uVar21,1);
      *(undefined4 *)(iVar14 + 8) = uVar17;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      uVar16 = FUN_000edadc(param_1,4);
      iVar14 = FUN_0010b0f4(uVar21,0);
      *(int *)(iVar14 + 8) = iVar15;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      iVar14 = FUN_0010b0f4(local_f8,2);
      uVar16 = *(undefined4 *)(iVar14 + 0x10);
      iVar14 = FUN_0010b0f4(uVar21,1);
      *(undefined4 *)(iVar14 + 0x10) = uVar16;
      FUN_001a7cd6(param_2,uVar21);
      uVar16 = FUN_000edadc(param_1,4);
      iVar14 = FUN_0010b0f4(local_f8,2);
      *(int *)(iVar14 + 8) = iVar15;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      iVar14 = FUN_0010b0f4(local_f8,2);
      *(undefined4 *)(iVar14 + 0x10) = DAT_001c66e4;
    }
    FUN_001a7cd6(param_2,local_f8);
LAB_000fe8ce:
    *param_4 = *param_4 & 0xffc0ffff | 0x40000;
    *(short *)param_4 = (short)local_104;
    bVar5 = false;
  }
  else {
    if ((byte)((bVar28 & 0x3f) - 0x1b) < 2) {
      bVar5 = false;
      goto LAB_000fe90e;
    }
    if ((*param_4 & 0x2000000) != 0) {
      local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
      *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
      if ((*param_4 & 0x400000) == 0) {
        iVar18 = 1;
        iVar14 = 1;
        iVar15 = 2;
        if ((*param_4 & 0x1800000) == 0x1000000) goto LAB_000fec71;
LAB_000fe3fc:
        local_b4 = (uint *)0x0;
        local_b0 = (uint *)0x0;
      }
      else {
        iVar18 = 2;
        iVar14 = 2;
        iVar15 = 3;
        if ((*param_4 & 0x1800000) != 0x1000000) goto LAB_000fe3fc;
LAB_000fec71:
        local_b4 = param_4 + iVar14;
        local_b0 = param_4 + iVar15;
        iVar14 = iVar18 + 2;
        if ((*param_4 & 0x4000000) == 0) {
          iVar15 = iVar18 + 3;
          iVar18 = iVar14;
        }
        else {
          iVar14 = iVar18 + 3;
          iVar15 = iVar18 + 4;
          iVar18 = iVar14;
        }
      }
      puVar12 = param_4 + iVar14;
      if ((*puVar12 & 0x1800000) == 0x1000000) {
        local_ac = param_4 + iVar15;
        puVar27 = param_4 + iVar18 + 2;
        if ((*puVar12 & 0x4000000) == 0) {
          local_a8 = (uint *)0x0;
        }
        else {
          local_a8 = param_4 + iVar18 + 3;
        }
      }
      else {
        local_ac = (uint *)0x0;
        puVar27 = (uint *)0x0;
        local_a8 = (uint *)0x0;
      }
      if (local_b4 == (uint *)0x0) {
        if (local_ac != (uint *)0x0) {
          if ((local_b0 != (uint *)0x0) || (puVar27 == (uint *)0x0)) goto LAB_000fe466;
          uVar16 = ((int (*)())FUN_0010a17a)(0xe6,*(undefined4 *)(param_1 + 8));
          piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          uVar11 = *param_4;
          uVar17 = (**(code **)(*piVar25 + 0x9c))(piVar25,(short)uVar11,*(int *)(param_1 + 8));
          piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          uVar21 = (**(code **)(*piVar25 + 0xa0))(piVar25,(short)uVar11,*(int *)(param_1 + 8));
          uVar22 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(uVar16,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar22;
          FUN_000f9ef4(uVar16,param_1,1,4,4,4,4);
          uVar22 = FUN_000edadc(param_1,*(byte *)((int)local_ac + 2) & 0x3f);
          uVar11 = *local_ac;
          iVar14 = FUN_0010b0f4(uVar16,2);
          *(uint *)(iVar14 + 8) = (uint)(ushort)uVar11;
          *(undefined4 *)(iVar14 + 0xc) = uVar22;
          local_20[0] = DAT_001c66c0;
          FUN_000fb2d4(param_1,local_20,local_ac,2,uVar16);
          FUN_001a7cd6(param_2,uVar16);
          if ((local_a8 != (uint *)0x0) && (*local_a8 != 0)) {
            uVar16 = ((int (*)())FUN_0010a17a)(0xc6,*(undefined4 *)(param_1 + 8));
            uVar22 = FUN_000edadc(param_1,4);
            iVar14 = FUN_0010b0f4(uVar16,0);
            *(uint *)(iVar14 + 8) = local_104;
            *(undefined4 *)(iVar14 + 0xc) = uVar22;
            uVar22 = FUN_000edadc(param_1,4);
            iVar14 = FUN_0010b0f4(uVar16,1);
            *(uint *)(iVar14 + 8) = local_104;
            *(undefined4 *)(iVar14 + 0xc) = uVar22;
            iVar14 = *local_a8 << 2;
            FUN_000f9ef4(uVar16,param_1,2,iVar14,iVar14,iVar14,iVar14);
            iVar14 = FUN_0010b0f4(uVar16,2);
            *(undefined4 *)(iVar14 + 0x10) = uVar21;
            FUN_001a7cd6(param_2,uVar16);
          }
          uVar16 = ((int (*)())FUN_0010a17a)(0xc6,*(undefined4 *)(param_1 + 8));
          uVar22 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(uVar16,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar22;
          uVar22 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(uVar16,1);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar22;
          iVar14 = FUN_0010b0f4(uVar16,2);
          *(undefined4 *)(iVar14 + 8) = uVar17;
          *(undefined4 *)(iVar14 + 0xc) = 0x1f;
          iVar14 = FUN_0010b0f4(uVar16,2);
          *(undefined4 *)(iVar14 + 0x10) = uVar21;
          FUN_001a7cd6(param_2,uVar16);
          local_a4 = ((int (*)())FUN_0010a17a)(0x68,*(undefined4 *)(param_1 + 8));
          uVar16 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar16;
          *(undefined4 *)(local_a4 + 0x130) = 0;
          *(undefined4 *)(local_a4 + 0x140) = DAT_001c66c0;
          uVar16 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar16;
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(undefined4 *)(iVar14 + 0x10) = DAT_001c66e4;
          local_a0 = 0;
          goto LAB_000fe89d;
        }
        uVar11 = (uint)(ushort)*param_4;
        uVar29 = (uint)(ushort)*puVar12;
        if ((*(byte *)(param_1 + 0x32) & 4) == 0) {
          local_a4 = ((int (*)())FUN_0010a17a)(0x68,*(undefined4 *)(param_1 + 8));
          uVar16 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar16;
          *(uint *)(local_a4 + 0x130) = uVar29;
          *(undefined4 *)(local_a4 + 0x140) = DAT_001c66c0;
          piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          uVar16 = (**(code **)(*piVar25 + 0x9c))(piVar25,uVar11,*(int *)(param_1 + 8));
          piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          uVar17 = (**(code **)(*piVar25 + 0xa0))(piVar25,uVar11,*(int *)(param_1 + 8));
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(undefined4 *)(iVar14 + 8) = uVar16;
          *(undefined4 *)(iVar14 + 0xc) = 0x1f;
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(undefined4 *)(iVar14 + 0x10) = uVar17;
          if (uVar29 == *param_6) {
            piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
            uVar17 = (**(code **)(*piVar25 + 0xa8))(piVar25,local_20,*(int *)(param_1 + 8));
            local_a0 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
            uVar16 = FUN_000edadc(param_1,4);
            iVar14 = FUN_0010b0f4(local_a0,0);
            *(uint *)(iVar14 + 8) = local_104;
            *(undefined4 *)(iVar14 + 0xc) = uVar16;
            *(uint *)(local_a0 + 0x9c) = param_6[1];
            iVar14 = FUN_0010b0f4(local_a0,1);
            uVar16 = local_20[0];
            *(undefined4 *)(iVar14 + 8) = uVar17;
            *(undefined4 *)(iVar14 + 0xc) = 0x1f;
            iVar14 = FUN_0010b0f4(local_a0,1);
            *(undefined4 *)(iVar14 + 0x10) = uVar16;
            goto LAB_000fe89d;
          }
          goto LAB_000fe893;
        }
        piVar25 = (int *)(param_7 + uVar11 * 4);
        if (*piVar25 == 0) {
          uVar16 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
          puVar23 = (undefined4 *)FUN_001a7bca(uVar16,0x14);
          *puVar23 = uVar16;
          puVar23[4] = uVar16;
          puVar23[2] = 0;
          puVar23[1] = 2;
          uVar16 = FUN_001a7bca(uVar16,8);
          puVar23[3] = uVar16;
          *piVar25 = (int)(puVar23 + 1);
        }
        puVar12 = (uint *)*piVar25;
        if (uVar29 < *puVar12) {
          uVar3 = puVar12[1];
          if (uVar3 <= uVar29) {
            _memset((void *)(puVar12[2] + uVar3 * 4),0,(uVar29 - uVar3) * 4 + 4);
            puVar12[1] = uVar29 + 1;
          }
          piVar24 = (int *)(puVar12[2] + uVar29 * 4);
        }
        else {
          piVar24 = (int *)FUN_001a7f7c(puVar12,uVar29);
        }
        if (*piVar24 == 0) {
          iVar14 = FUN_0010ed70(0xa4,*(undefined4 *)(param_1 + 8));
          *(uint *)(iVar14 + 0x14) = *(uint *)(iVar14 + 0x14) & 0xffff7fff;
          iVar18 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar18;
          iVar15 = FUN_0010b0f4(iVar14,0);
          *(int *)(iVar15 + 8) = iVar18;
          *(undefined4 *)(iVar15 + 0xc) = 0;
          *(uint *)(iVar14 + 300) = uVar29;
          *(uint *)(iVar14 + 0x130) = uVar11;
          FUN_000fbaca(param_1,iVar14,*(undefined4 *)(param_1 + 0x394));
          puVar12 = (uint *)*piVar25;
          if (uVar29 < *puVar12) {
            uVar11 = puVar12[1];
            if (uVar11 <= uVar29) {
              _memset((void *)(puVar12[2] + uVar11 * 4),0,(uVar29 - uVar11) * 4 + 4);
              puVar12[1] = uVar29 + 1;
            }
            piVar24 = (int *)(puVar12[2] + uVar29 * 4);
          }
          else {
            piVar24 = (int *)FUN_001a7f7c(puVar12,uVar29);
          }
          *piVar24 = iVar14;
        }
        puVar12 = (uint *)*piVar25;
        if (uVar29 < *puVar12) {
          uVar11 = puVar12[1];
          if (uVar11 <= uVar29) {
            _memset((void *)(puVar12[2] + uVar11 * 4),0,(uVar29 - uVar11) * 4 + 4);
            puVar12[1] = uVar29 + 1;
          }
          piVar25 = (int *)(puVar12[2] + uVar29 * 4);
        }
        else {
          piVar25 = (int *)FUN_001a7f7c(puVar12,uVar29);
        }
        local_104 = *(uint *)(*piVar25 + 0x94);
      }
      else {
        if (((local_b0 == (uint *)0x0) || (local_ac != (uint *)0x0)) || (puVar27 != (uint *)0x0)) {
LAB_000fe466:
          FUN_000fbd02(param_1,param_2,local_b4,local_b0,local_104,4,
                       *(undefined4 *)(param_1 + 0x3f4));
          uVar29 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
          *(uint *)(*(int *)(param_1 + 8) + 0xf0) = uVar29;
          uVar11 = *local_ac;
          local_88 = (uint)(ushort)uVar11;
          if (local_a8 != (uint *)0x0) {
            iVar14 = ((int (*)())FUN_0010a17a)(0xc6,*(undefined4 *)(param_1 + 8));
            uVar16 = FUN_000edadc(param_1,4);
            iVar15 = FUN_0010b0f4(iVar14,0);
            *(uint *)(iVar15 + 8) = uVar29;
            *(undefined4 *)(iVar15 + 0xc) = uVar16;
            *(undefined4 *)(iVar14 + 0x9c) = DAT_001c66e8;
            uVar3 = *local_a8;
            FUN_000f9ef4(iVar14,param_1,1,uVar3,uVar3,uVar3,uVar3);
            uVar16 = FUN_000edadc(param_1,*(byte *)((int)local_ac + 2) & 0x3f);
            iVar15 = FUN_0010b0f4(iVar14,2);
            *(uint *)(iVar15 + 8) = (uint)(ushort)uVar11;
            *(undefined4 *)(iVar15 + 0xc) = uVar16;
            local_24 = DAT_001c66c0;
            FUN_000fb2d4(param_1,&local_24,local_ac,2,iVar14);
            FUN_001a7cd6(param_2,iVar14);
            *local_ac = *local_ac & 0xffc0ffff | 0x40000;
            local_88 = uVar29;
          }
          iVar14 = ((int (*)())FUN_0010a17a)(0xe6,*(undefined4 *)(param_1 + 8));
          uVar16 = FUN_000edadc(param_1,4);
          iVar15 = FUN_0010b0f4(iVar14,0);
          *(uint *)(iVar15 + 8) = uVar29;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          *(undefined4 *)(iVar14 + 0x9c) = DAT_001c66e8;
          FUN_000f9ef4(iVar14,param_1,1,4,4,4,4);
          uVar16 = FUN_000edadc(param_1,*(byte *)((int)local_ac + 2) & 0x3f);
          iVar15 = FUN_0010b0f4(iVar14,2);
          *(uint *)(iVar15 + 8) = local_88;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          local_20[0] = DAT_001c66c0;
          if (local_a8 == (uint *)0x0) {
            FUN_000fb2d4(param_1,local_20,local_ac,2,iVar14);
          }
          else {
            iVar15 = FUN_0010b0f4(iVar14,2);
            *(undefined4 *)(iVar15 + 0x10) = DAT_001c66e4;
          }
          FUN_001a7cd6(param_2,iVar14);
          iVar14 = ((int (*)())FUN_0010a17a)(0xc6,*(undefined4 *)(param_1 + 8));
          *(undefined4 *)(iVar14 + 0x9c) = DAT_001c66e8;
          uVar16 = FUN_000edadc(param_1,4);
          iVar15 = FUN_0010b0f4(iVar14,0);
          *(uint *)(iVar15 + 8) = local_104;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          uVar16 = FUN_000edadc(param_1,4);
          iVar15 = FUN_0010b0f4(iVar14,1);
          *(uint *)(iVar15 + 8) = local_104;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          uVar16 = FUN_000edadc(param_1,4);
          iVar15 = FUN_0010b0f4(iVar14,2);
          *(uint *)(iVar15 + 8) = uVar29;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          uVar16 = DAT_001c66e4;
          iVar15 = FUN_0010b0f4(iVar14,1);
          *(undefined4 *)(iVar15 + 0x10) = uVar16;
          iVar15 = FUN_0010b0f4(iVar14,2);
          *(undefined4 *)(iVar15 + 0x10) = uVar16;
          FUN_001a7cd6(param_2,iVar14);
          local_a4 = ((int (*)())FUN_0010a17a)(0x68,*(undefined4 *)(param_1 + 8));
          uVar17 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar17;
          *(undefined4 *)(local_a4 + 0x130) = 0;
          *(undefined4 *)(local_a4 + 0x140) = DAT_001c66c0;
          uVar17 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar17;
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(undefined4 *)(iVar14 + 0x10) = uVar16;
LAB_000fe893:
          local_a0 = 0;
        }
        else {
          FUN_000fbd02(param_1,param_2,local_b4,local_b0,local_104,4,
                       *(undefined4 *)(param_1 + 0x3f4));
          uVar11 = *puVar12;
          local_a4 = ((int (*)())FUN_0010a17a)(0x68,*(undefined4 *)(param_1 + 8));
          uVar16 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,0);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar16;
          *(uint *)(local_a4 + 0x130) = (uint)(ushort)uVar11;
          *(undefined4 *)(local_a4 + 0x140) = DAT_001c66c0;
          uVar16 = FUN_000edadc(param_1,4);
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(uint *)(iVar14 + 8) = local_104;
          *(undefined4 *)(iVar14 + 0xc) = uVar16;
          iVar14 = FUN_0010b0f4(local_a4,1);
          *(undefined4 *)(iVar14 + 0x10) = DAT_001c66e4;
          local_a0 = 0;
        }
LAB_000fe89d:
        FUN_001a7cd6(param_2,local_a4);
        if (local_a0 != 0) {
          FUN_001a7cd6(param_2,local_a0);
        }
      }
      goto LAB_000fe8ce;
    }
    local_104 = 0;
  }
  if (bVar26 == 0) goto LAB_000fe37a;
  bVar28 = *(byte *)((int)param_4 + 2);
  if (((bVar28 & 0x40) == 0) || ((param_4[1] & 0x4444) == 0)) {
    bVar6 = false;
  }
  else {
    FUN_001b2b8c(param_4,0);
    FUN_001b2b8c(param_4,1);
    FUN_001b2b8c(param_4,2);
    FUN_001b2b8c(param_4,3);
    local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
    *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    uVar13 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
    iVar14 = FUN_0010b0f4(uVar13,0);
    *(uint *)(iVar14 + 8) = local_104;
    *(undefined4 *)(iVar14 + 0xc) = 0;
    uVar16 = FUN_000edadc(param_1,local_10c);
    iVar14 = FUN_0010b0f4(uVar13,1);
    *(uint *)(iVar14 + 8) = local_110;
    *(undefined4 *)(iVar14 + 0xc) = uVar16;
    local_24 = DAT_001c66c0;
    FUN_000fb286(&local_24);
    uVar17 = in_XMM0_Da;
    FUN_000fb286(&local_24);
    uVar21 = uVar17;
    FUN_000fb286(&local_24);
    uVar22 = uVar21;
    FUN_000fb286(&local_24);
    uVar16 = local_24;
    iVar14 = FUN_0010b0f4(uVar13,1);
    *(undefined4 *)(iVar14 + 0x10) = uVar16;
    FUN_001a7cd6(param_2,uVar13);
    iVar14 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
    iVar15 = FUN_0010b0f4(iVar14,0);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    FUN_000fa0d2(iVar14,param_1,1,in_XMM0_Da,uVar17,uVar21,uVar22);
    *(undefined4 *)(iVar14 + 0x9c) = local_20[0];
    FUN_001a7cd6(param_2,iVar14);
    bVar28 = *(byte *)((int)param_4 + 2);
    local_110 = local_104;
    if ((bVar28 & 0x40) == 0) {
      local_10c = 4;
      bVar6 = true;
    }
    else {
      param_4[1] = param_4[1] & 0xffff8888 | 0x3210;
      local_10c = 4;
      bVar6 = true;
    }
  }
  if ((bVar28 & 0x40) == 0) goto LAB_000fe37a;
  puVar12 = param_4 + 1;
  if ((param_4[1] & 0xffff8888) == 0) goto LAB_000fe37a;
  if ((*param_3 - 0x8e < 0x10) && ((param_4[1] & 0x8888) != 0)) {
    *(byte *)(param_4 + 1) = (byte)param_4[1] & 0x77;
    *(byte *)((int)param_4 + 5) = *(byte *)((int)param_4 + 5) & 0x77;
    if (!bVar6) {
      local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
      *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    }
    uVar16 = ((int (*)())FUN_0010a17a)(0xcb,*(undefined4 *)(param_1 + 8));
    iVar14 = FUN_0010b0f4(uVar16,0);
    *(uint *)(iVar14 + 8) = local_104;
    *(undefined4 *)(iVar14 + 0xc) = 0;
    FUN_000fa0d2(uVar16,param_1,2,0,0,0,0);
    uVar17 = FUN_000edadc(param_1,local_10c);
    iVar14 = FUN_0010b0f4(uVar16,1);
    *(uint *)(iVar14 + 8) = local_110;
    *(undefined4 *)(iVar14 + 0xc) = uVar17;
    FUN_001a7cd6(param_2,uVar16);
    local_110 = local_104;
    local_10c = 4;
    bVar6 = true;
    bVar28 = *(byte *)((int)param_4 + 2);
  }
  if (((bVar28 & 0x40) != 0) && ((*(byte *)((int)param_4 + 6) & 1) != 0)) {
    if (!bVar6) {
      local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
      *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    }
    iVar14 = ((int (*)())FUN_0010a17a)(0x12,*(undefined4 *)(param_1 + 8));
    iVar15 = FUN_0010b0f4(iVar14,0);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    uVar16 = FUN_000edadc(param_1,local_10c);
    iVar15 = FUN_0010b0f4(iVar14,1);
    *(uint *)(iVar15 + 8) = local_110;
    *(undefined4 *)(iVar15 + 0xc) = uVar16;
    ((int (*)())FUN_00109c0e)(iVar14 + 0xa4,1,1);
    if (!bVar6) {
      FUN_000fb79c();
    }
    FUN_000fa0d2(iVar14,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    FUN_001a7cd6(param_2,iVar14);
    local_110 = local_104;
    local_10c = 4;
    bVar6 = true;
    bVar28 = *(byte *)((int)param_4 + 2);
  }
  if ((((bVar28 & 0x40) == 0) || ((*(byte *)((int)param_4 + 6) & 2) == 0)) ||
     ((*(byte *)((int)param_4 + 6) & 4) == 0)) {
    if (((bVar28 & 0x40) != 0) && ((*(byte *)((int)param_4 + 6) & 2) != 0)) {
      if (!bVar6) {
        local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
      }
      iVar14 = ((int (*)())FUN_0010a17a)(0x12,*(undefined4 *)(param_1 + 8));
      iVar15 = FUN_0010b0f4(iVar14,0);
      *(uint *)(iVar15 + 8) = local_104;
      *(undefined4 *)(iVar15 + 0xc) = 0;
      uVar16 = FUN_000edadc(param_1,local_10c);
      iVar15 = FUN_0010b0f4(iVar14,1);
      *(uint *)(iVar15 + 8) = local_110;
      *(undefined4 *)(iVar15 + 0xc) = uVar16;
      if (!bVar6) {
        FUN_000fb79c();
      }
      FUN_000fa0d2(iVar14,param_1,2,0x3f000000,0x3f000000,0x3f000000,0x3f000000);
      ((int (*)())FUN_00109c0e)(iVar14 + 0xbc,1,1);
      goto LAB_000ff125;
    }
    if (((bVar28 & 0x40) != 0) && ((*(byte *)((int)param_4 + 6) & 4) != 0)) {
      if (!bVar6) {
        local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
      }
      iVar14 = ((int (*)())FUN_0010a17a)(0x13,*(undefined4 *)(param_1 + 8));
      iVar15 = FUN_0010b0f4(iVar14,0);
      *(uint *)(iVar15 + 8) = local_104;
      *(undefined4 *)(iVar15 + 0xc) = 0;
      uVar16 = FUN_000edadc(param_1,local_10c);
      iVar15 = FUN_0010b0f4(iVar14,1);
      *(uint *)(iVar15 + 8) = local_110;
      *(undefined4 *)(iVar15 + 0xc) = uVar16;
      if (!bVar6) {
        FUN_000fb79c();
      }
      FUN_000fa0d2(iVar14,param_1,2,0x40000000,0x40000000,0x40000000,0x40000000);
      goto LAB_000ff125;
    }
  }
  else {
    if (!bVar6) {
      local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
      *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    }
    iVar14 = ((int (*)())FUN_0010a17a)(0x14,*(undefined4 *)(param_1 + 8));
    iVar15 = FUN_0010b0f4(iVar14,0);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    uVar16 = FUN_000edadc(param_1,local_10c);
    iVar15 = FUN_0010b0f4(iVar14,1);
    *(uint *)(iVar15 + 8) = local_110;
    *(undefined4 *)(iVar15 + 0xc) = uVar16;
    if (!bVar6) {
      FUN_000fb79c();
    }
    FUN_000fa0d2(iVar14,param_1,2,0x40000000,0x40000000,0x40000000,0x40000000);
    FUN_000fa0d2(iVar14,param_1,3,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    ((int (*)())FUN_00109c0e)(iVar14 + 0xd4,1,1);
LAB_000ff125:
    FUN_001a7cd6(param_2,iVar14);
    local_110 = local_104;
    local_10c = 4;
    bVar6 = true;
    bVar28 = *(byte *)((int)param_4 + 2);
  }
  if (((bVar28 & 0x40) != 0) && ((*(byte *)((int)param_4 + 6) & 8) != 0)) {
    local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
    *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
    uVar16 = ((int (*)())FUN_0010a17a)(0x26,*(undefined4 *)(param_1 + 8));
    iVar14 = FUN_0010b0f4(uVar16,0);
    *(uint *)(iVar14 + 8) = local_104;
    *(undefined4 *)(iVar14 + 0xc) = 0;
    uVar17 = FUN_000edadc(param_1,local_10c);
    iVar14 = FUN_0010b0f4(uVar16,1);
    *(uint *)(iVar14 + 8) = local_110;
    *(undefined4 *)(iVar14 + 0xc) = uVar17;
    FUN_000fa0d2(uVar16,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    uVar17 = FUN_000edadc(param_1,local_10c);
    iVar14 = FUN_0010b0f4(uVar16,3);
    *(uint *)(iVar14 + 8) = local_110;
    *(undefined4 *)(iVar14 + 0xc) = uVar17;
    if (!bVar6) {
      FUN_000fb79c();
      iVar14 = FUN_0010b0f4(uVar16,1);
      uVar17 = *(undefined4 *)(iVar14 + 0x10);
      iVar14 = FUN_0010b0f4(uVar16,3);
      *(undefined4 *)(iVar14 + 0x10) = uVar17;
    }
    FUN_001a7cd6(param_2,uVar16);
    iVar14 = ((int (*)())FUN_0010a17a)(0x25,*(undefined4 *)(param_1 + 8));
    iVar15 = FUN_0010b0f4(iVar14,0);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    iVar15 = FUN_0010b0f4(iVar14,1);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    iVar15 = FUN_0010b0f4(iVar14,2);
    *(uint *)(iVar15 + 8) = local_104;
    *(undefined4 *)(iVar15 + 0xc) = 0;
    FUN_000fa0d2(iVar14,param_1,3,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
    ((int (*)())FUN_00109c0e)(iVar14 + 0xd4,1,1);
    FUN_001a7cd6(param_2,iVar14);
    local_10c = 4;
    bVar6 = true;
    bVar28 = *(byte *)((int)param_4 + 2);
    local_110 = local_104;
  }
  if (((bVar28 & 0x40) != 0) && (bVar26 = *(byte *)((int)param_4 + 6) >> 5, bVar26 != 0)) {
    piVar25 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar8 = (**(code **)(*piVar25 + 0xb4))(piVar25);
    if ((cVar8 == '\0') || ((0xbe < *param_3 || (*param_3 != 0x5d)))) {
      if (bVar26 == 4) {
        bVar28 = *(byte *)((int)param_4 + 2);
      }
      else {
        if (bVar26 == 1) {
          local_128 = DAT_001c66e8;
          local_12c = DAT_001c6740;
          local_54 = 1;
LAB_000ff3f8:
          iVar14 = ((int (*)())FUN_0010a17a)(0x40,*(undefined4 *)(param_1 + 8));
          local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
          *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
          iVar15 = FUN_0010b0f4(iVar14,0);
          *(uint *)(iVar15 + 8) = local_104;
          *(undefined4 *)(iVar15 + 0xc) = 0;
          *(undefined4 *)(iVar14 + 0x9c) = DAT_001c66d4;
          uVar16 = FUN_000edadc(param_1,local_10c);
          iVar15 = FUN_0010b0f4(iVar14,1);
          *(uint *)(iVar15 + 8) = local_110;
          *(undefined4 *)(iVar15 + 0xc) = uVar16;
          iVar15 = ((int (*)())FUN_0010a17a)(0x13,*(undefined4 *)(param_1 + 8));
          iVar18 = FUN_0010b0f4(iVar15,0);
          *(uint *)(iVar18 + 8) = local_104;
          *(undefined4 *)(iVar18 + 0xc) = 0;
          uVar16 = FUN_000edadc(param_1,local_10c);
          iVar18 = FUN_0010b0f4(iVar15,1);
          *(uint *)(iVar18 + 8) = local_110;
          *(undefined4 *)(iVar18 + 0xc) = uVar16;
          iVar18 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          iVar19 = FUN_0010b0f4(iVar18,0);
          *(uint *)(iVar19 + 8) = local_104;
          *(undefined4 *)(iVar19 + 0xc) = 0;
          uVar16 = FUN_000edadc(param_1,local_10c);
          iVar19 = FUN_0010b0f4(iVar18,1);
          *(uint *)(iVar19 + 8) = local_110;
          *(undefined4 *)(iVar19 + 0xc) = uVar16;
          if (!bVar6) {
            FUN_000fb79c();
            iVar19 = FUN_0010b0f4(iVar15,1);
            uVar16 = *(undefined4 *)(iVar19 + 0x10);
            iVar19 = FUN_0010b0f4(iVar18,1);
            *(undefined4 *)(iVar19 + 0x10) = uVar16;
          }
          iVar19 = FUN_0010b0f4(iVar15,2);
          *(uint *)(iVar19 + 8) = local_104;
          *(undefined4 *)(iVar19 + 0xc) = 0;
          puVar7 = PTR_DAT_00213485;
          uVar16 = *(undefined4 *)(PTR_DAT_00213485 + 0xc);
          iVar19 = FUN_0010b0f4(iVar15,2);
          *(undefined4 *)(iVar19 + 0x10) = uVar16;
          iVar19 = FUN_0010b0f4(iVar15,1);
          local_30[0] = *(undefined4 *)(iVar19 + 0x10);
          uVar16 = *(undefined4 *)(puVar7 + (uint)*(byte *)((int)local_30 + local_54) * 4);
          iVar19 = FUN_0010b0f4(iVar14,1);
          *(undefined4 *)(iVar19 + 0x10) = uVar16;
          *(undefined4 *)(iVar15 + 0x9c) = local_128;
          *(undefined4 *)(iVar18 + 0x9c) = local_12c;
          FUN_001a7cd6(param_2,iVar14);
          FUN_001a7cd6(param_2,iVar15);
          FUN_001a7cd6(param_2,iVar18);
          local_10c = 4;
          bVar6 = true;
          local_110 = local_104;
        }
        else {
          if (bVar26 == 2) {
            local_128 = DAT_001c673c;
            local_12c = DAT_001c6738;
            local_54 = 2;
            goto LAB_000ff3f8;
          }
          if (bVar26 == 3) {
            local_128 = DAT_001c6734;
            local_12c = DAT_001c6730;
            local_54 = 3;
            goto LAB_000ff3f8;
          }
        }
        bVar28 = *(byte *)((int)param_4 + 2);
      }
    }
    else if (bVar26 == 3) {
      *(undefined1 *)(param_1 + 0x470) = 1;
      bVar28 = *(byte *)((int)param_4 + 2);
    }
    else if (bVar26 == 2) {
      *(undefined1 *)(param_1 + 0x470) = 1;
      local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
      *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
      piVar25 = (int *)((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      iVar14 = FUN_0010b0f4(piVar25,0);
      *(uint *)(iVar14 + 8) = local_104;
      *(undefined4 *)(iVar14 + 0xc) = 0;
      uVar16 = FUN_000edadc(param_1,local_10c);
      iVar14 = FUN_0010b0f4(piVar25,1);
      *(uint *)(iVar14 + 8) = local_110;
      *(undefined4 *)(iVar14 + 0xc) = uVar16;
      FUN_000fb79c();
      pcVar4 = *(code **)(*piVar25 + 0x88);
      iVar14 = FUN_0010b0f4(piVar25,1);
      (*pcVar4)(piVar25,1,3,*(undefined1 *)(iVar14 + 0x12));
      FUN_001a7cd6(param_2,piVar25);
      local_10c = 4;
      bVar6 = true;
      bVar28 = *(byte *)((int)param_4 + 2);
      local_110 = local_104;
    }
    else {
      bVar28 = *(byte *)((int)param_4 + 2);
    }
  }
  if (((bVar28 & 0x40) != 0) && ((*puVar12 & 0x8888) != 0)) {
    uVar11 = FUN_001b2c12(param_4);
    if ((uVar11 != 0) && (uVar11 != 0x8888)) {
      if (!bVar6) {
        local_104 = *(int *)(*(int *)(param_1 + 8) + 0xf0) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0xf0) = local_104;
      }
      iVar14 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      iVar15 = FUN_0010b0f4(iVar14,0);
      *(uint *)(iVar15 + 8) = local_104;
      *(undefined4 *)(iVar15 + 0xc) = 0;
      uVar16 = FUN_000edadc(param_1,local_10c);
      iVar15 = FUN_0010b0f4(iVar14,1);
      *(uint *)(iVar15 + 8) = local_110;
      *(undefined4 *)(iVar15 + 0xc) = uVar16;
      if (!bVar6) {
        FUN_000fb79c();
      }
      if (((*param_4 & 0x400000) != 0) && ((*(byte *)((int)param_4 + 6) & 0x10) != 0)) {
        ((int (*)())FUN_00109c0e)(iVar14 + 0xa4,2,1);
      }
      FUN_001a7cd6(param_2,iVar14);
      iVar14 = FUN_0010b0f4(iVar14,1);
      uVar16 = *(undefined4 *)(iVar14 + 0x10);
      iVar14 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      iVar15 = FUN_0010b0f4(iVar14,0);
      *(uint *)(iVar15 + 8) = local_104;
      *(undefined4 *)(iVar15 + 0xc) = 0;
      uVar17 = FUN_000edadc(param_1,local_10c);
      iVar15 = FUN_0010b0f4(iVar14,1);
      *(uint *)(iVar15 + 8) = local_110;
      *(undefined4 *)(iVar15 + 0xc) = uVar17;
      if (!bVar6) {
        iVar15 = FUN_0010b0f4(iVar14,1);
        *(undefined4 *)(iVar15 + 0x10) = uVar16;
      }
      ((int (*)())FUN_00109c0e)(iVar14 + 0xa4,1,1);
      if (((*param_4 & 0x400000) != 0) && ((*(byte *)((int)param_4 + 6) & 0x10) != 0)) {
        ((int (*)())FUN_00109c0e)(iVar14 + 0xa4,2,1);
        if ((*param_4 & 0x400000) != 0) {
          *(byte *)((int)param_4 + 6) = *(byte *)((int)param_4 + 6) & 0xef;
        }
      }
      *(uint *)(iVar14 + 0x9c) =
           (uint)((CONCAT11((char)(uVar11 >> 7),(char)(uVar11 >> 3)) & 0xff01 ^ 1) & 0x1ff ^ 0x100)
           | (~(uVar11 >> 0xb) & 1) << 0x10 | (~(uVar11 >> 0xf) & 1) << 0x18;
      FUN_001a7cd6(param_2,iVar14);
      if ((*param_4 & 0x400000) == 0) {
        local_110 = local_104;
        local_10c = 4;
      }
      else {
        *(byte *)puVar12 = (byte)*puVar12 & 0x77;
        *(byte *)((int)param_4 + 5) = *(byte *)((int)param_4 + 5) & 0x77;
        local_110 = local_104;
        local_10c = 4;
      }
    }
  }
LAB_000fe37a:
  if (bVar5) {
    *(short *)param_4 = (short)local_110;
    *param_4 = *param_4 & 0xffc0ffff | local_10c << 0x10;
  }
  return;
}

/* FUN_00101182 @ 0x101182 (193 bytes) */
int FUN_00101182(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint *param_6;
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x10);
  *puVar3 = uVar1;
  puVar3[1] = param_2;
  puVar3[2] = *param_3;
  puVar3[3] = param_4;
  uVar2 = param_6[1];
  if (uVar2 < *param_6) {
    _memset((void *)(uVar2 * 4 + param_6[2]),0,4);
    param_6[1] = uVar2 + 1;
    *(undefined4 **)(uVar2 * 4 + param_6[2]) = puVar3 + 1;
    *param_3 = 0xffffffff;
    return param_5;
  }
  piVar4 = (int *)FUN_001a7f7c(param_6,uVar2);
  *piVar4 = (int)(puVar3 + 1);
  *param_3 = 0xffffffff;
  return param_5;
}

/* FUN_00101244 @ 0x101244 (1571 bytes) */
int FUN_00101244(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  short *psVar4;
  short *psVar5;
  ushort *puVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  undefined1 uVar11;
  char cVar12;
  byte bVar13;
  byte bVar14;
  short sVar15;
  undefined2 uVar16;
  ushort uVar17;
  short sVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined4 uVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  undefined4 *puVar32;
  undefined4 *puVar33;
  byte *pbVar34;
  undefined4 *puVar35;
  undefined4 *puVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  int *piVar39;
  int *piVar40;
  undefined *puVar41;
  int *piVar42;
  undefined4 *puVar43;
  undefined4 uVar44;
  ushort uVar45;
  uint uVar46;
  uint uVar47;
  int iVar48;
  ushort *puVar49;
  int iVar50;
  uint *puVar51;
  byte bVar52;
  int iVar53;
  undefined *puVar54;
  int local_374;
  undefined *puStack_358;
  undefined4 uStack_33c;
  undefined4 uStack_338;
  undefined4 uStack_334;
  undefined4 uStack_330;
  undefined4 uStack_31c;
  undefined4 uStack_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  int local_2fc;
  undefined1 uStack_2e2;
  uint uStack_2b4;
  ushort *puStack_27c;
  int iStack_22c;
  int iStack_21c;
  int iStack_1fc;
  int *piStack_1f8;
  int iStack_1f0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  uint uStack_1b8;
  int iStack_1b4;
  uint uStack_1b0;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_148;
  int *piStack_138;
  int iStack_134;
  short sStack_100;
  short sStack_fe;
  undefined4 *puStack_fc;
  undefined4 *puStack_f8;
  int iStack_f0;
  int iStack_ec;
  uint local_e8;
  int local_e4;
  int iStack_d4;
  int iStack_d0;
  int aiStack_c4 [8];
  bool bStack_a1;
  undefined4 uStack_a0;
  int iStack_98;
  undefined *puStack_94;
  uint *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [8];
  int iStack_60;
  undefined1 local_50 [8];
  int iStack_48;
  uint local_38;
  undefined *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  undefined4 uStack_24;
  int local_20 [4];
  
  puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8);
  *puVar1 = *puVar1 & 0xffffffdf;
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  iVar25 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x50);
  uVar46 = iVar25 + 0x1fU >> 5;
  puVar19 = (undefined4 *)FUN_001a7bca(uVar21,uVar46 * 4 + 0xc);
  *puVar19 = uVar21;
  puVar19[2] = iVar25;
  puVar19[1] = uVar46;
  if (uVar46 != 0) {
    uVar47 = 0;
    puVar20 = puVar19 + 1;
    do {
      puVar20[2] = 0;
      uVar47 = uVar47 + 1;
      puVar20 = puVar20 + 1;
    } while (uVar47 < uVar46);
  }
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar20 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
  *puVar20 = uVar21;
  puVar1 = puVar20 + 1;
  puVar20[4] = uVar21;
  puVar20[2] = 0;
  puVar20[1] = 2;
  uVar21 = FUN_001a7bca(uVar21,8);
  puVar20[3] = uVar21;
  local_20[0] = 0;
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar22 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
  *puVar22 = uVar21;
  puVar2 = puVar22 + 1;
  puVar22[4] = uVar21;
  puVar22[2] = 0;
  puVar22[1] = 2;
  uVar21 = FUN_001a7bca(uVar21,8);
  puVar22[3] = uVar21;
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar23 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
  *puVar23 = uVar21;
  puVar3 = puVar23 + 1;
  puVar23[4] = uVar21;
  puVar23[2] = 0;
  puVar23[1] = 2;
  uVar21 = FUN_001a7bca(uVar21,8);
  puVar23[3] = uVar21;
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
  *puVar24 = uVar21;
  puVar24[4] = uVar21;
  puVar24[2] = 0;
  puVar24[1] = 2;
  uVar21 = FUN_001a7bca(uVar21,8);
  puVar24[3] = uVar21;
  *(undefined4 **)(param_1 + 0x408) = puVar24 + 1;
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
  *puVar24 = uVar21;
  puVar24[4] = uVar21;
  puVar24[2] = 0;
  puVar24[1] = 2;
  uVar21 = FUN_001a7bca(uVar21,8);
  puVar24[3] = uVar21;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_34 = DAT_001c66f8;
  local_38 = 0xffffffff;
  local_28 = *(int **)(param_1 + 0x394);
  uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  local_80 = puVar24 + 1;
  puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
  *puVar24 = uVar21;
  piVar42 = puVar24 + 1;
  FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
  local_2c = piVar42;
  FUN_000edc32(param_1,local_28,piVar42);
  FUN_000ea91c(local_28,local_2c);
  local_28 = local_2c;
  FUN_001a7e06(local_50);
  FUN_001a7e06(local_68);
  *(undefined1 *)(param_1 + 0x3d8) = 0;
  *(undefined1 *)(param_1 + 0x3c8) = 0;
  ((int (*)())FUN_000fe01a)(param_1,param_2);
  local_2fc = 0;
  bVar8 = false;
LAB_0010153e:
  cVar12 = FUN_000e7782(param_2);
  if (cVar12 == '\0') {
LAB_00106b40:
    FUN_000edf42(param_1);
    FUN_000ea91c(local_2c,*(undefined4 *)(param_1 + 0x39c));
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
    FUN_0013455c(param_1,*(undefined4 *)(param_1 + 0x394),*(undefined4 *)(param_1 + 0x39c));
    if (puVar2 != (uint *)0x0) {
      FUN_001a7aba(puVar22[4],puVar22[3]);
      FUN_001a7aba(*puVar22,puVar22);
    }
    if (puVar1 != (uint *)0x0) {
      FUN_001a7aba(puVar20[4],puVar20[3]);
      FUN_001a7aba(*puVar20,puVar20);
    }
    if (puVar19 + 1 != (undefined4 *)0x0) {
      FUN_001a7aba(*puVar19,puVar19);
    }
    FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),*(undefined4 *)(param_1 + 0x78));
    FUN_0012534c(param_1);
    return;
  }
  cVar12 = FUN_000e5aa0(param_2);
  if (cVar12 != '\0') {
    local_30 = (int *)0x0;
    local_e8 = 1;
    local_e4 = 0;
    iVar25 = *(int *)(param_1 + 0x3b8);
    if (*(int *)(iVar25 + 4) != 0) {
      do {
        local_30 = *(int **)(local_e4 + *(int *)(iVar25 + 8));
        if ((*(byte *)(local_30 + 5) & 1) != 0) {
          (**(code **)(*local_30 + 0x68))(local_30);
          piVar42 = local_30;
          uVar21 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar21,1,local_30[0x29]);
          puVar51 = local_80;
          uVar46 = piVar42[0x50];
          if (uVar46 < *local_80) {
            uVar47 = local_80[1];
            if (uVar47 <= uVar46) {
              _memset((void *)(local_80[2] + uVar47 * 4),0,(uVar46 - uVar47) * 4 + 4);
              puVar51[1] = uVar46 + 1;
            }
            puVar24 = (undefined4 *)(puVar51[2] + uVar46 * 4);
          }
          else {
            puVar24 = (undefined4 *)FUN_001a7f7c(local_80,uVar46);
          }
          *puVar24 = uVar21;
          iVar25 = *(int *)(param_1 + 0x3b8);
        }
        local_e8 = local_e8 + 1;
        local_e4 = local_e4 + 4;
      } while (local_e8 <= *(uint *)(iVar25 + 4));
    }
    piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar42 + 0x17c))(piVar42,param_1,*(int *)(param_1 + 8));
    FUN_000e7782(param_2);
  }
  *(undefined1 *)(param_1 + 0x470) = 0;
  iVar48 = param_2 + 0x8c;
  iVar25 = FUN_000e5ac0(param_2);
  if (iVar25 == 0x52) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100;
  }
  else if (((iVar25 == 0x84) && ((*(uint *)(param_1 + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(param_1 + 0x30) & 0x200000) == 0)) goto LAB_00106b40;
  local_374 = *(int *)(param_1 + 8);
  piVar42 = *(int **)(local_374 + 0x54);
  iVar26 = piVar42[3];
  uVar21 = FUN_000fb216(iVar25,iVar26);
  puVar41 = DAT_001c66f8;
  switch(uVar21) {
  case 0:
  case 1:
    switch(iVar25) {
    case 0x14:
      if ((*(byte *)(param_1 + 0x31) & 0x40) == 0) {
        psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
        iVar48 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
        iVar25 = *(int *)(param_1 + 8);
        if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (iVar25 != 0)) &&
           (*(char *)(*(int *)(iVar25 + 0x54) + 8) < '\0')) {
          sVar15 = 0xf;
        }
        else {
          sVar15 = *psVar4;
        }
        iVar26 = (int)sVar15;
        psVar4 = *(short **)(*(int *)(param_2 + 0x6c) + 4);
        if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (iVar25 != 0)) &&
           (*(char *)(*(int *)(iVar25 + 0x54) + 8) < '\0')) {
          sVar15 = 0xf;
        }
        else {
          sVar15 = *psVar4;
        }
        if (iVar48 == 0x15) {
code_r0x00107664:
          if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
            *(int *)(param_1 + 0x3dc) = iVar26;
            iVar25 = sVar15 + 1;
            *(int *)(param_1 + 0x3e0) = iVar25;
            *(int *)(param_1 + 1000) = iVar48;
            *(undefined1 *)(param_1 + 0x3d8) = 1;
            if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar26 < iVar25)) {
              do {
                FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),iVar48,iVar26,0);
                iVar26 = iVar26 + 1;
              } while (iVar26 < *(int *)(param_1 + 0x3e0));
            }
          }
          break;
        }
        if (iVar48 < 0x16) {
          if (iVar48 != 0x14) break;
        }
        else if (iVar48 != 0x1a) {
          if (iVar48 == 0x24) goto code_r0x00107664;
          break;
        }
        *(int *)(param_1 + 0x3dc) = iVar26;
        iVar25 = sVar15 + 1;
        *(int *)(param_1 + 0x3e0) = iVar25;
        *(int *)(param_1 + 1000) = iVar48;
        *(undefined1 *)(param_1 + 0x3d8) = 1;
        if (((*(byte *)(param_1 + 0x30) & 1) != 0) && (iVar26 < iVar25)) {
          do {
            FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),iVar48,iVar26,0);
            iVar26 = iVar26 + 1;
          } while (iVar26 < *(int *)(param_1 + 0x3e0));
        }
        break;
      }
      break;
    case 0x16:
    case 0x18:
      psVar4 = (short *)**(undefined4 **)(param_2 + 100);
      if ((*(byte *)(*(int *)(local_374 + 0x3f4) + 0x31) & 0x20) != 0) {
        bVar13 = *(byte *)(psVar4 + 1);
        if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (local_374 != 0)) &&
           (*(char *)(*(int *)(local_374 + 0x54) + 8) < '\0')) {
          sVar15 = 0xf;
        }
        else {
          sVar15 = *psVar4;
        }
        iVar48 = (int)sVar15;
        uVar21 = FUN_000edadc(param_1,bVar13 & 0x3f);
        uVar37 = FUN_000edb48(param_1,bVar13 & 0x3f);
        iVar25 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar21,iVar48,0);
        iVar25 = *(int *)(iVar25 + 0x38);
        ((int (*)())FUN_00109fa4)(iVar25,0,*(byte *)(param_2 + 0x8e) & 3,uVar37,iVar48);
        ((int (*)())FUN_00109fa4)(iVar25,1,*(byte *)(param_2 + 0x8e) >> 2 & 3,uVar37,iVar48);
        ((int (*)())FUN_00109fa4)(iVar25,2,*(byte *)(param_2 + 0x8e) >> 4 & 3,uVar37,iVar48);
        ((int (*)())FUN_00109fa4)(iVar25,3,*(byte *)(param_2 + 0x8e) >> 6,uVar37,iVar48);
        if ((*(byte *)(param_2 + 0x8f) & 1) != 0) {
          *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 1;
        }
        *(uint *)(iVar25 + 0x140) = *(byte *)(param_2 + 0x8f) >> 1 & 1;
        *(undefined4 *)(iVar25 + 0x144) = uVar21;
        *(int *)(iVar25 + 0x148) = iVar48;
      }
      break;
    case 0x17:
      uVar21 = FUN_000edb32(param_1,*(byte *)(param_2 + 0x8e) & 0x1f);
      uVar17 = *(ushort *)(param_2 + 0x8e);
      if (*(char *)(param_2 + 0x8f) < '\0') {
        bVar13 = *(byte *)(param_2 + 0x90);
        uStack_a0 = (undefined *)
                    (CONCAT13(bVar13 >> 6,
                              CONCAT12(bVar13 >> 4,
                                       CONCAT11(bVar13 >> 2,*(undefined1 *)(param_2 + 0x90)))) &
                    0xff030303);
        bVar52 = *(byte *)(param_2 + 0x91) & 1;
        bVar13 = *(byte *)(param_2 + 0x91) >> 2 & 1;
        bVar14 = *(byte *)(param_2 + 0x91) >> 1 & 1;
      }
      else {
        uStack_a0 = (undefined *)0x3030303;
        bVar52 = 0;
        bVar13 = 0;
        bVar14 = 0;
      }
      iVar48 = (int)*(short *)**(undefined4 **)(param_2 + 100);
      uVar37 = FUN_000edadc(param_1,*(byte *)((short *)**(undefined4 **)(param_2 + 100) + 1) & 0x3f)
      ;
      iVar25 = *(int *)(param_1 + 0x3dc);
      if (iVar48 <= *(int *)(param_1 + 0x3dc)) {
        iVar25 = iVar48;
      }
      *(int *)(param_1 + 0x3dc) = iVar25;
      iVar25 = *(int *)(param_1 + 0x3e0);
      if (*(int *)(param_1 + 0x3e0) <= iVar48) {
        iVar25 = iVar48 + 1;
      }
      *(int *)(param_1 + 0x3e0) = iVar25;
      *(undefined4 *)(param_1 + 1000) = 0x24;
      iVar25 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar37,iVar48,0);
      iVar25 = *(int *)(iVar25 + 0x38);
      if (bVar52 == 0) {
        *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 1;
      }
      if (bVar13 != 0) {
        *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 4;
      }
      if (bVar14 != 0) {
        *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 2;
      }
      iVar48 = 0;
      do {
        if (*(char *)((int)&uStack_a0 + iVar48) != '\0') {
          ((int (*)())FUN_00109fa4)(iVar25,iVar48,*(char *)((int)&uStack_a0 + iVar48),uVar21,(char)(uVar17 >> 5))
          ;
        }
        iVar48 = iVar48 + 1;
      } while (iVar48 != 4);
      break;
    case 0x19:
      bVar13 = *(byte *)(param_2 + 0x8f);
      bVar14 = *(byte *)(param_2 + 0x8e);
      iVar25 = (uint)bVar14 * 0xc;
      *(uint *)(*(int *)(param_1 + 0x78) + iVar25) = *(byte *)(param_2 + 0x8f) >> 3 & 3;
      if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x50) < (int)(uint)bVar14) {
        FUN_000e27ca(*(int *)(param_1 + 8),7);
      }
      puVar19[(bVar14 >> 5) + 3] = puVar19[(bVar14 >> 5) + 3] | 1 << (bVar14 & 0x1f);
      *(uint *)(iVar25 + 8 + *(int *)(param_1 + 0x78)) = *(byte *)(param_2 + 0x8f) >> 5 & 1;
      piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      iVar48 = (**(code **)(*piVar42 + 0x48))(piVar42,param_1,bVar13 & 7);
      if (iVar48 != 0) {
        *(int *)(iVar25 + 4 + *(int *)(param_1 + 0x78)) = iVar48;
      }
      break;
    case 0x1a:
      FUN_001a7e06(&uStack_a0);
      puVar41 = DAT_001c66f8;
      bVar13 = *(byte *)(param_2 + 0x8e);
      if (*(char *)(param_2 + 0x8f) < '\0') {
        bVar14 = *(byte *)(param_2 + 0x90);
        cVar12 = (bVar14 & 3) != 0;
        puVar54 = DAT_001c66f8;
        if ((bool)cVar12) {
          puVar54 = (undefined *)0x4;
        }
        if ((bVar14 & 0xc) != 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff);
          cVar12 = cVar12 + '\x01';
        }
        if ((bVar14 & 0x30) != 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff00ffff);
          cVar12 = cVar12 + '\x01';
        }
        if ((bVar14 & 0xc0) != 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xffffff);
          cVar12 = cVar12 + '\x01';
        }
      }
      else {
        cVar12 = '\0';
        puVar54 = _UNK_001c66e0;
      }
      psVar4 = (short *)**(undefined4 **)(param_2 + 100);
      if ((*(byte *)(psVar4 + 1) & 0x40) != 0) {
        iVar25 = FUN_001b2b34(psVar4,0);
        puVar54 = puVar41;
        if (*(int *)(PTR_DAT_002134c1 + iVar25 * 4) == 0) {
          puVar54 = (undefined *)(uint)(byte)(cVar12 + 4);
        }
        iVar25 = FUN_001b2b34(psVar4,1);
        if (*(int *)(PTR_DAT_002134c1 + iVar25 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff);
        }
        iVar25 = FUN_001b2b34(psVar4,2);
        if (*(int *)(PTR_DAT_002134c1 + iVar25 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff00ffff);
        }
        iVar25 = FUN_001b2b34(psVar4,3);
        if (*(int *)(PTR_DAT_002134c1 + iVar25 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xffffff);
        }
      }
      iVar48 = (int)*psVar4;
      iVar25 = *(int *)(param_1 + 0x3cc);
      if (iVar48 <= *(int *)(param_1 + 0x3cc)) {
        iVar25 = iVar48;
      }
      *(int *)(param_1 + 0x3cc) = iVar25;
      iVar25 = *(int *)(param_1 + 0x3d0);
      if (*(int *)(param_1 + 0x3d0) <= iVar48) {
        iVar25 = iVar48 + 1;
      }
      *(int *)(param_1 + 0x3d0) = iVar25;
      piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
      (**(code **)(*piVar42 + 0x4c))
                (piVar42,param_1,bVar13 & 0x3f,psVar4,puVar54,*(undefined4 *)(param_1 + 0x394),1,0,5
                );
      iVar48 = *(int *)(iStack_98 + 8);
      iVar25 = iStack_98;
      while (iVar26 = iVar48, iVar26 != 0) {
        FUN_001a7d72(iVar25);
        FUN_000fbaca(param_1,iVar25,local_2c);
        iVar25 = iVar26;
        iVar48 = *(int *)(iVar26 + 8);
      }
      puStack_94 = PTR_DAT_00213441 + 8;
      uStack_a0 = PTR_DAT_00213441 + 8;
      break;
    case 0x1b:
      iVar25 = FUN_000edb32(param_1,*(byte *)(param_2 + 0x8e) & 0x1f);
      uVar17 = *(ushort *)(param_2 + 0x8e);
      uStack_a0 = DAT_001c66f4;
      if (*(char *)(param_2 + 0x8f) < '\0') {
        bVar13 = *(byte *)(param_2 + 0x90);
        (*(unsigned short *)((unsigned char *)&(uStack_a0) + 0)) = CONCAT11((bVar13 & 0xc) == 0,(bVar13 & 3) == 0);
        (*(unsigned int *)((unsigned char *)&(uStack_a0) + 0)) = CONCAT12((bVar13 & 0x30) == 0,(undefined2)uStack_a0);
        uStack_a0 = (undefined *)CONCAT13((bVar13 & 0xc0) == 0,(undefined3)uStack_a0);
      }
      iVar48 = (int)*(short *)**(undefined4 **)(param_2 + 100);
      uVar21 = FUN_000edadc(param_1,*(byte *)((short *)**(undefined4 **)(param_2 + 100) + 1) & 0x3f)
      ;
      if (iVar25 == 0) {
        *(int *)(*(int *)(param_1 + 0x3a0) + 0x44) = iVar48;
      }
      else if (iVar25 == 1) {
        *(int *)(*(int *)(param_1 + 0x3a0) + 0x48) = iVar48;
      }
      iVar26 = *(int *)(param_1 + 0x3dc);
      if (iVar48 <= *(int *)(param_1 + 0x3dc)) {
        iVar26 = iVar48;
      }
      *(int *)(param_1 + 0x3dc) = iVar26;
      iVar26 = *(int *)(param_1 + 0x3e0);
      if (*(int *)(param_1 + 0x3e0) <= iVar48) {
        iVar26 = iVar48 + 1;
      }
      *(int *)(param_1 + 0x3e0) = iVar26;
      *(undefined4 *)(param_1 + 1000) = 0x24;
      piVar42 = (int *)FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar21,iVar48,0);
      uVar21 = (**(code **)(*piVar42 + 0x2c))(piVar42);
      iVar48 = 0;
      do {
        if (*(char *)((int)&uStack_a0 + iVar48) == '\0') {
          ((int (*)())FUN_00109ed6)(uVar21,iVar48,iVar25,(char)(uVar17 >> 5));
        }
        iVar48 = iVar48 + 1;
      } while (iVar48 != 4);
      break;
    case 0x1c:
    case 0x1d:
    case 0x79:
      sVar15 = *(short *)**(undefined4 **)(param_2 + 100);
      bVar13 = *(byte *)((short *)**(undefined4 **)(param_2 + 100) + 1);
      iVar25 = *(int *)(param_2 + 0x5c);
      if (iVar25 < 1) {
        iVar25 = 0;
      }
      else {
        iVar26 = 0;
        iVar48 = *(int *)(param_2 + 0x58);
        do {
          (&uStack_a0)[iVar26] = *(undefined4 *)(param_2 + 0x8c + (iVar26 + iVar48) * 4);
          iVar26 = iVar26 + 1;
        } while (iVar26 != iVar25);
      }
      ((int (*)())FUN_000fdd90)(param_1,bVar13 & 0x3f,(int)sVar15,iVar25,&uStack_a0);
      break;
    case 0x42:
      uVar21 = *(undefined4 *)(local_374 + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
      *puVar24 = uVar21;
      piVar42 = puVar24 + 1;
      FUN_0010ac30(piVar42,0x94,*(undefined4 *)(param_1 + 8));
      uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x2f,0,0);
      ((int (*)())FUN_0010a3c2)(piVar42,0,uVar21);
      puVar24[0x4c] = 0;
      FUN_000fbaca(param_1,piVar42,local_2c);
      if (bVar8) {
        (**(code **)(*piVar42 + 0x90))(piVar42,uVar21);
      }
      (*(unsigned short *)((unsigned char *)&(uStack_33c) + 2)) = *(byte *)(param_2 + 0x8e) & 0x3f;
      uVar47 = *(ushort *)(param_2 + 0x8e) >> 7 & 0x3f;
      uVar46 = 0;
      if (uVar47 < 5) {
        uVar46 = uVar47;
      }
      psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
      sVar15 = *psVar4;
      uVar37 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
      psVar5 = *(short **)(*(int *)(param_2 + 0x6c) + 4);
      if ((((*(byte *)(psVar5 + 1) & 0x3f) == 0x10) && (*(int *)(param_1 + 8) != 0)) &&
         (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) < '\0')) {
        sVar18 = 0xf;
      }
      else {
        sVar18 = *psVar5;
      }
      uVar38 = FUN_000edadc(param_1,*(byte *)(psVar5 + 1) & 0x3f);
      uVar44 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x2b,0,0);
      piVar42 = (int *)((int (*)())FUN_0010a17a)(0x14,*(undefined4 *)(param_1 + 8));
      iVar25 = FUN_0010b0f4(piVar42,1);
      *(int *)(iVar25 + 8) = (int)sVar15;
      *(undefined4 *)(iVar25 + 0xc) = uVar37;
      uStack_a0 = DAT_001c66c0;
      FUN_000fb2d4(param_1,&uStack_a0,psVar4,1,piVar42);
      iVar25 = FUN_0010b0f4(piVar42,1);
      *(undefined4 *)(iVar25 + 0x10) = DAT_001c66e4;
      FUN_000fa0d2(piVar42,param_1,2,0,0x3f800000,0,0);
      uStack_33c = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_33c) + 2)),0xf);
      uStack_338 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_33c) + 2)),0x10);
      uStack_334 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_33c) + 2)),0x11);
      uStack_330 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_33c) + 2)),0x12);
      FUN_000f9d16(piVar42,param_1,3,uStack_330,uStack_334,uStack_338,uStack_33c);
      iVar25 = FUN_0010b0f4(piVar42,0);
      *(undefined4 *)(iVar25 + 8) = 0;
      *(undefined4 *)(iVar25 + 0xc) = 0x2b;
      FUN_000fbaca(param_1,piVar42,local_2c);
      (**(code **)(*piVar42 + 0x90))(piVar42,uVar21);
      if (bVar8) {
        (**(code **)(*piVar42 + 0x90))(piVar42,uVar44);
      }
      ((int (*)())FUN_0010a38c)(piVar42,param_1,0x2b,0);
      piVar42[0x20] = 1;
      piVar42 = (int *)FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 8));
      iVar25 = FUN_0010b0f4(piVar42,0);
      *(uint *)(iVar25 + 8) = uVar46;
      *(undefined4 *)(iVar25 + 0xc) = 0x2c;
      iVar25 = FUN_0010b0f4(piVar42,1);
      *(int *)(iVar25 + 8) = (int)sVar18;
      *(undefined4 *)(iVar25 + 0xc) = uVar38;
      (**(code **)(*piVar42 + 0x90))(piVar42,uVar44);
      FUN_000fbaca(param_1,piVar42,local_2c);
      ((int (*)())FUN_0010a38c)(piVar42,param_1,0x2c,uVar46);
      bVar8 = true;
      break;
    case 0x43:
      bVar13 = *(byte *)(param_2 + 0x8e);
      iVar25 = **(int **)(param_2 + 100);
      puVar54 = _UNK_001c66e0;
      if ((*(byte *)(iVar25 + 2) & 0x40) != 0) {
        iVar48 = FUN_001b2b34(iVar25,0);
        puVar54 = puVar41;
        if (*(int *)(PTR_DAT_002134c1 + iVar48 * 4) == 0) {
          puVar54 = (undefined *)0x4;
        }
        iVar48 = FUN_001b2b34(iVar25,1);
        if (*(int *)(PTR_DAT_002134c1 + iVar48 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff);
        }
        iVar48 = FUN_001b2b34(iVar25,2);
        if (*(int *)(PTR_DAT_002134c1 + iVar48 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xff00ffff);
        }
        iVar48 = FUN_001b2b34(iVar25,3);
        if (*(int *)(PTR_DAT_002134c1 + iVar48 * 4) == 0) {
          puVar54 = (undefined *)((uint)puVar54 & 0xffffff);
          local_374 = *(int *)(param_1 + 8);
        }
        else {
          local_374 = *(int *)(param_1 + 8);
        }
      }
      (**(code **)(**(int **)(local_374 + 0x54) + 0x4c))
                (*(int **)(local_374 + 0x54),param_1,bVar13 & 0x3f,iVar25,puVar54,local_2c,0,
                 **(undefined4 **)(param_2 + 0x6c),5);
      break;
    case 0x6e:
      uVar21 = *(undefined4 *)(param_2 + 0x8c + *(int *)(param_2 + 0x58) * 4);
      uVar37 = *(undefined4 *)(local_374 + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar37,300);
      *puVar24 = uVar37;
      piVar42 = puVar24 + 1;
      FUN_000ebb06(piVar42,*(undefined4 *)(param_1 + 8));
      puVar24[1] = PTR_DAT_002134c9 + 8;
      puVar24[0x4a] = uVar21;
      local_2c = piVar42;
      FUN_000edc32(param_1,local_28,piVar42);
      FUN_000ea91c(local_28,local_2c);
      local_28 = local_2c;
      uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
      *puVar24 = uVar21;
      piVar42 = puVar24 + 1;
      FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
      local_2c = piVar42;
      FUN_000edc32(param_1,local_28,piVar42);
      FUN_000ea91c(local_28,local_2c);
      local_28 = local_2c;
      break;
    case 0x72:
      piVar42 = (int *)FUN_001a7bca(*(undefined4 *)(local_374 + 0xbc),0xc);
      piVar42[1] = 0;
      piVar42[2] = 0;
      uVar21 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      iVar26 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar26;
      *piVar42 = iVar26;
      iVar25 = FUN_0010b0f4(uVar21,0);
      *(int *)(iVar25 + 8) = iVar26;
      *(undefined4 *)(iVar25 + 0xc) = 0;
      uStack_a0 = DAT_001c66c0;
      ((int (*)())FUN_000fe286)(param_1,local_68,iVar48,**(undefined4 **)(param_2 + 0x6c),puVar1,&local_38,
                   &local_80);
      psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
      if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (*(int *)(param_1 + 8) != 0)) &&
         (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) < '\0')) {
        sVar15 = 0xf;
      }
      else {
        sVar15 = *psVar4;
      }
      uVar37 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
      iVar25 = FUN_0010b0f4(uVar21,1);
      *(int *)(iVar25 + 8) = (int)sVar15;
      *(undefined4 *)(iVar25 + 0xc) = uVar37;
      FUN_000fb2d4(param_1,&uStack_a0,**(undefined4 **)(param_2 + 0x6c),1,uVar21);
      iVar48 = *(int *)(iStack_60 + 8);
      iVar25 = iStack_60;
      while (iVar26 = iVar48, iVar26 != 0) {
        FUN_001a7d72(iVar25);
        FUN_000fbaca(param_1,iVar25,local_2c);
        iVar25 = iVar26;
        iVar48 = *(int *)(iVar26 + 8);
      }
      FUN_000fbaca(param_1,uVar21,local_2c);
      uVar46 = puVar23[2];
      if (uVar46 < *puVar3) {
        _memset((void *)(uVar46 * 4 + puVar23[3]),0,4);
        puVar23[2] = uVar46 + 1;
        piVar39 = (int *)(uVar46 * 4 + puVar23[3]);
      }
      else {
        piVar39 = (int *)FUN_001a7f7c(puVar3,uVar46);
      }
      *piVar39 = (int)piVar42;
      break;
    case 0x73:
      uVar21 = *(undefined4 *)(local_374 + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
      *puVar24 = uVar21;
      puVar32 = puVar24 + 1;
      FUN_0010ac30(puVar32,0xf8,*(undefined4 *)(param_1 + 8));
      puVar24[0x4c] = *(undefined4 *)(param_2 + 0x8c + *(int *)(param_2 + 0x58) * 4);
      FUN_000fbaca(param_1,puVar32,local_2c);
      puVar51 = *(uint **)(param_1 + 0x408);
      uVar46 = puVar51[1];
      if (uVar46 < *puVar51) {
        _memset((void *)(uVar46 * 4 + puVar51[2]),0,4);
        puVar51[1] = uVar46 + 1;
        puVar24 = (undefined4 *)(uVar46 * 4 + puVar51[2]);
      }
      else {
        puVar24 = (undefined4 *)FUN_001a7f7c(puVar51,uVar46);
      }
      *puVar24 = puVar32;
      break;
    case 0x76:
    case 0x77:
      if ((iVar25 == 0x76) && (*(char *)(param_2 + 0x8f) < '\0')) {
        iVar25 = *(int *)(param_2 + 0x8c + *(int *)(param_2 + 0x58) * 4);
        iVar48 = *(int *)(param_2 + 0x28);
        uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x43,0xffffffff,0);
        iVar26 = FUN_0010f060(0x10a,*(undefined4 *)(param_1 + 8));
        *(int *)(param_1 + 0x354) = iVar26;
        ((int (*)())FUN_0010a3c2)(iVar26,0,uVar21);
        *(int *)(iVar26 + 300) = iVar48 + iVar25 * 4;
        FUN_000e9512(*(undefined4 *)(param_1 + 0x394),iVar26);
      }
      else {
        puVar6 = (ushort *)**(undefined4 **)(param_2 + 0x6c);
        bVar13 = (byte)puVar6[1] & 0x3f;
        uStack_2b4 = (uint)*puVar6;
        if (*(char *)((int)puVar6 + 3) < '\0') {
          uStack_2b4 = uStack_2b4 | *(int *)(puVar6 + 2) << 0x10;
          iVar25 = 2;
        }
        else {
          iVar25 = 1;
        }
        uVar21 = *(undefined4 *)(puVar6 + iVar25 * 2);
        if (bVar13 == 0x1c) {
          if (*(int *)(param_1 + 0x90) == 0) {
            uVar37 = *(undefined4 *)(local_374 + 0xb8);
            puVar24 = (undefined4 *)FUN_001a7bca(uVar37,0x14);
            *puVar24 = uVar37;
            puVar24[4] = uVar37;
            puVar24[2] = 0;
            puVar24[1] = 2;
            uVar37 = FUN_001a7bca(uVar37,8);
            puVar24[3] = uVar37;
            *(undefined4 **)(param_1 + 0x90) = puVar24 + 1;
          }
          puVar51 = *(uint **)(param_1 + 0x90);
          if (*puVar51 <= uStack_2b4) goto code_r0x001083b2;
code_r0x0010826f:
          uVar46 = puVar51[1];
          if (uVar46 <= uStack_2b4) {
            _memset((void *)(puVar51[2] + uVar46 * 4),0,(uStack_2b4 - uVar46) * 4 + 4);
            puVar51[1] = uStack_2b4 + 1;
          }
          puVar24 = (undefined4 *)(puVar51[2] + uStack_2b4 * 4);
        }
        else {
          if (*(int *)(param_1 + 0x8c) == 0) {
            uVar37 = *(undefined4 *)(local_374 + 0xb8);
            puVar24 = (undefined4 *)FUN_001a7bca(uVar37,0x14);
            *puVar24 = uVar37;
            puVar24[4] = uVar37;
            puVar24[2] = 0;
            puVar24[1] = 2;
            uVar37 = FUN_001a7bca(uVar37,8);
            puVar24[3] = uVar37;
            *(undefined4 **)(param_1 + 0x8c) = puVar24 + 1;
          }
          puVar51 = *(uint **)(param_1 + 0x8c);
          if (uStack_2b4 < *puVar51) goto code_r0x0010826f;
code_r0x001083b2:
          puVar24 = (undefined4 *)FUN_001a7f7c(puVar51,uStack_2b4);
        }
        *puVar24 = uVar21;
        puVar51 = (uint *)(*(int *)(param_1 + 0x428) + 8 + (uStack_2b4 >> 5) * 4);
        *puVar51 = *puVar51 | 1 << ((byte)uStack_2b4 & 0x1f);
        if ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) & 8) != 0) {
          uVar37 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar32 = (undefined4 *)FUN_001a7bca(uVar37,0x168);
          *puVar32 = uVar37;
          puVar24 = puVar32 + 1;
          FUN_0010ef86(puVar24,0xfa,*(undefined4 *)(param_1 + 8));
          uVar37 = FUN_000edadc(param_1,bVar13);
          iVar25 = FUN_0010b0f4(puVar24,0);
          *(uint *)(iVar25 + 8) = uStack_2b4;
          *(undefined4 *)(iVar25 + 0xc) = uVar37;
          puVar32[0x4c] = uVar21;
          FUN_000fbaca(param_1,puVar24,*(undefined4 *)(param_1 + 0x394));
        }
      }
      break;
    case 0x78:
      *(uint *)(param_1 + 0x3f4) = *(ushort *)(param_2 + 0x8e) & 0x3fff;
      break;
    case 0x7a:
      *(uint *)(param_1 + 0x3ec) = *(ushort *)(param_2 + 0x8e) & 0x3fff;
      break;
    case 0x7c:
      *(uint *)(param_1 + 0x3f0) = *(ushort *)(param_2 + 0x8e) & 0x3fff;
      break;
    case 0x7d:
      psVar4 = (short *)**(undefined4 **)(param_2 + 100);
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
          uStack_a0 = DAT_001c66f4;
          iVar48 = (int)*psVar4;
          uVar21 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
          iVar25 = FUN_000edb32(param_1,*(ushort *)(param_2 + 0x8e) & 0x3fff);
          if (iVar25 == 0) {
            *(int *)(*(int *)(param_1 + 0x3a0) + 0x44) = iVar48;
          }
          else if (iVar25 == 1) {
            *(int *)(*(int *)(param_1 + 0x3a0) + 0x48) = iVar48;
          }
          iVar26 = *(int *)(param_1 + 0x3dc);
          if (iVar48 <= *(int *)(param_1 + 0x3dc)) {
            iVar26 = iVar48;
          }
          *(int *)(param_1 + 0x3dc) = iVar26;
          iVar26 = *(int *)(param_1 + 0x3e0);
          if (*(int *)(param_1 + 0x3e0) <= iVar48) {
            iVar26 = iVar48 + 1;
          }
          *(int *)(param_1 + 0x3e0) = iVar26;
          *(undefined4 *)(param_1 + 1000) = 0x24;
          if (iVar25 == 0xd) {
            iVar26 = *(int *)(param_1 + 0x3a0);
            if (*(int *)(iVar26 + 0x4c) == -1) {
              *(int *)(iVar26 + 0x4c) = iVar48;
            }
            else {
              *(int *)(iVar26 + 0x54) = iVar48;
            }
          }
          else if (iVar25 == 0xe) {
            iVar26 = *(int *)(param_1 + 0x3a0);
            if (*(int *)(iVar26 + 0x50) == -1) {
              *(int *)(iVar26 + 0x50) = iVar48;
            }
            else {
              *(int *)(iVar26 + 0x58) = iVar48;
            }
          }
          else if (iVar25 == 0xb) {
            *(int *)(*(int *)(param_1 + 0x3a0) + 0x5c) = iVar48;
          }
          else if (iVar25 == 0xc) {
            *(int *)(*(int *)(param_1 + 0x3a0) + 0x60) = iVar48;
          }
          else if (iVar25 == 0xf) {
            *(int *)(*(int *)(param_1 + 0x3a0) + 100) = iVar48;
          }
          piVar42 = (int *)FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar21,iVar48,0);
          iVar26 = (**(code **)(*piVar42 + 0x2c))(piVar42);
          *(int *)(iVar26 + 0x140) = iVar48;
          iVar27 = 0;
          do {
            if (*(char *)((int)&uStack_a0 + iVar27) == '\0') {
              ((int (*)())FUN_00109ed6)(iVar26,iVar27,iVar25,iVar48);
            }
            iVar27 = iVar27 + 1;
          } while (iVar27 != 4);
        }
      }
      else {
        if ((*(byte *)(psVar4 + 1) & 0x40) == 0) {
          bVar13 = 0xf;
        }
        else {
          bVar13 = *(byte *)(psVar4 + 2);
          bVar13 = ((bVar13 & 0xc0) == 0x40) * '\b' |
                   ((bVar13 & 0x30) == 0x10) << 2 |
                   ((bVar13 & 0xc) == 4) * '\x02' | (bVar13 & 3) == 1;
        }
        sVar15 = *psVar4;
        (**(code **)(*piVar42 + 0x54))
                  (piVar42,sVar15,*(ushort *)(param_2 + 0x8e) & 0x3fff,sVar15,DAT_001c66c0,0,0,0,
                   bVar13,sVar15,DAT_001c66c0,param_1);
      }
      break;
    case 0x7e:
      bVar13 = *(byte *)(param_2 + 0x8e) & 0x1f;
      uVar21 = FUN_000edb32(param_1,bVar13);
      bVar14 = *(byte *)(param_2 + 0x8e) >> 5;
      if (bVar14 == 3) {
        bVar7 = true;
        bVar9 = false;
        bVar10 = false;
      }
      else if (bVar14 < 4) {
        if (bVar14 == 1) {
          bVar7 = false;
          bVar9 = false;
          bVar10 = true;
        }
        else {
code_r0x00108b81:
          bVar7 = false;
          bVar9 = false;
          bVar10 = false;
        }
      }
      else if (bVar14 == 4) {
        bVar7 = false;
        bVar9 = true;
        bVar10 = false;
      }
      else {
        if (bVar14 != 5) goto code_r0x00108b81;
        bVar7 = true;
        bVar9 = true;
        bVar10 = false;
      }
      puVar6 = (ushort *)**(undefined4 **)(param_2 + 100);
      if ((puVar6[1] & 0x40) == 0) {
        if ((*(byte *)((int)puVar6 + 3) & 2) == 0) {
          puStack_27c = (ushort *)0x0;
          puVar49 = (ushort *)0x0;
        }
        else {
          puStack_27c = puVar6 + 2;
          puVar49 = (ushort *)0x0;
        }
      }
      else {
        puVar49 = puVar6 + 2;
        if ((*(byte *)((int)puVar6 + 3) & 2) == 0) {
          puStack_27c = (ushort *)0x0;
        }
        else {
          puStack_27c = puVar6 + 4;
        }
      }
      if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) == 0)) {
        if (bVar13 == 10) {
          local_38 = (uint)*puStack_27c;
          uStack_a0 = (undefined *)DAT_001c66e8;
          if ((*puVar49 & 3) == 1) {
            piVar42 = &DAT_001c66e8;
          }
          else {
            piVar42 = &uStack_a0;
          }
          uStack_a0 = (undefined *)*piVar42;
          if ((*puVar49 & 0xc) == 4) {
            piVar42 = (int *)&UNK_001c66dc;
          }
          else {
            piVar42 = &uStack_a0;
          }
          uStack_a0 = (undefined *)*piVar42;
          if ((*puVar49 & 0x30) == 0x10) {
            piVar42 = (int *)&UNK_001c66d8;
          }
          else {
            piVar42 = &uStack_a0;
          }
          uStack_a0 = (undefined *)*piVar42;
          if ((*puVar49 & 0xc0) == 0x40) {
            piVar42 = &DAT_001c66d4;
          }
          else {
            piVar42 = &uStack_a0;
          }
          uStack_a0 = (undefined *)*piVar42;
          local_34 = uStack_a0;
        }
      }
      else {
        bVar14 = (byte)puVar6[1] & 0x3f;
        uVar47 = (uint)*puVar6;
        uVar37 = FUN_000edadc(param_1,bVar14);
        puVar51 = local_80;
        uVar46 = *(uint *)(param_1 + 0x3dc);
        if ((int)uVar47 <= (int)*(uint *)(param_1 + 0x3dc)) {
          uVar46 = uVar47;
        }
        *(uint *)(param_1 + 0x3dc) = uVar46;
        iVar25 = *(int *)(param_1 + 0x3e0);
        if (*(int *)(param_1 + 0x3e0) <= (int)uVar47) {
          iVar25 = uVar47 + 1;
        }
        *(int *)(param_1 + 0x3e0) = iVar25;
        *(undefined4 *)(param_1 + 1000) = 0x24;
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          iVar25 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar37,uVar47,0);
          iVar25 = *(int *)(iVar25 + 0x38);
          if (!bVar7) {
            *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 1;
          }
          if (bVar9) {
            *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 4;
          }
          if (bVar10) {
            *(uint *)(iVar25 + 0x13c) = *(uint *)(iVar25 + 0x13c) | 2;
          }
          iVar48 = 0;
          do {
            ((int (*)())FUN_00109fa4)(iVar25,iVar48,1,uVar21,uVar47);
            iVar48 = iVar48 + 1;
          } while (iVar48 != 4);
        }
        else if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          (**(code **)(*piVar42 + 0x4c))
                    (piVar42,param_1,uVar47,puVar6,_UNK_001c66e0,*(undefined4 *)(param_1 + 0x394),1,
                     0,bVar13);
        }
        else if (bVar14 != 9) {
          uVar46 = (uint)*puStack_27c;
          if (uVar46 < *local_80) {
            uVar47 = local_80[1];
            if (uVar47 <= uVar46) {
              _memset((void *)(local_80[2] + uVar47 * 4),0,(uVar46 - uVar47) * 4 + 4);
              puVar51[1] = uVar46 + 1;
            }
            puVar24 = (undefined4 *)(puVar51[2] + uVar46 * 4);
          }
          else {
            puVar24 = (undefined4 *)FUN_001a7f7c(local_80,uVar46);
          }
          uVar21 = *puVar24;
          iVar25 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar25;
          uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar25,0);
          ((int (*)())FUN_0010a3c2)(uVar21,0,uVar37);
          FUN_000fbaca(param_1,uVar21,local_2c);
        }
      }
      break;
    case 0x80:
      bVar13 = *(byte *)(param_2 + 0x8f);
      bVar14 = *(byte *)(param_2 + 0x8e);
      if (piVar42[0x14] < (int)(uint)bVar14) {
        FUN_000e27ca(local_374,7);
      }
      puVar19[(bVar14 >> 5) + 3] = puVar19[(bVar14 >> 5) + 3] | 1 << (bVar14 & 0x1f);
      iVar25 = (uint)bVar14 * 0xc;
      *(undefined4 *)(*(int *)(param_1 + 0x78) + iVar25) = 1;
      if ((bVar13 & 0xf) != 0) {
        *(uint *)(iVar25 + 4 + *(int *)(param_1 + 0x78)) = bVar13 & 0xf;
      }
      break;
    case 0x81:
    case 0x84:
    case 0x85:
      local_2fc = local_2fc + 1;
      if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
        if (puVar20[2] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x180000;
        }
        if (puVar22[2] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80000;
        }
        iVar25 = ((int (*)())FUN_0010a17a)(*(undefined4 *)
                               (*(int *)(*(int *)(local_374 + 0x54) + 0xc) + iVar25 * 0x24),
                              local_374);
        iVar48 = FUN_0010b0f4(iVar25,0);
        *(undefined4 *)(iVar48 + 8) = 0;
        *(undefined4 *)(iVar48 + 0xc) = 0x2c;
        *(int *)(iVar25 + 0x9c) = DAT_001c66e8;
        iVar48 = FUN_0010b0f4(iVar25,1);
        *(undefined4 *)(iVar48 + 8) = 0;
        *(undefined4 *)(iVar48 + 0xc) = 0x2c;
        iVar48 = FUN_0010b0f4(iVar25,1);
        *(undefined4 *)(iVar48 + 0x10) = DAT_001c66e4;
        FUN_000fbaca(param_1,iVar25,local_2c);
      }
      break;
    case 0x87:
      bVar13 = *(byte *)(param_2 + 0x8e);
      uVar46 = (uint)bVar13;
      bVar14 = *(byte *)(param_2 + 0x8f);
      if (*(int *)(param_1 + 0x7c) < (int)uVar46) {
        *(uint *)(param_1 + 0x7c) = uVar46;
      }
      *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1 << (bVar13 & 0x1f);
      uStack_a0 = DAT_001c66c0;
      iVar25 = *(int *)(local_374 + 0xf0) + -1;
      *(int *)(local_374 + 0xf0) = iVar25;
      uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar25,0);
      iVar25 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar25;
      uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar25,0);
      uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_0010a3c2)(uVar38,0,uVar37);
      FUN_000fd68a(param_1,5,1,param_2,uVar38,1,DAT_001c66f4,&uStack_a0,puVar1,1,local_2c);
      FUN_000fbaca(param_1,uVar38,local_2c);
      iVar25 = ((int (*)())FUN_0010a17a)(0x109,*(undefined4 *)(param_1 + 8));
      *(uint *)(iVar25 + 0x134) = uVar46;
      ((int (*)())FUN_0010a3c2)(iVar25,0,uVar21);
      ((int (*)())FUN_0010a3c2)(iVar25,1,uVar37);
      FUN_000fbaca(param_1,iVar25,local_2c);
      uStack_a0 = DAT_001c66c0;
      if ((bVar14 & 0x1f) != 1) {
        puStack_fc = (undefined4 *)PTR_DAT_0021345d;
        puStack_f8 = (undefined4 *)PTR_DAT_00213485;
        puVar24 = (undefined4 *)(PTR_DAT_0021345d + 0x10);
        do {
          iVar25 = ((int (*)())FUN_0010a17a)(0xe1,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(iVar25,0,uVar21);
          ((int (*)())FUN_0010a3c2)(iVar25,1,uVar21);
          *(undefined4 *)(iVar25 + 0x9c) = *puStack_fc;
          uVar37 = *puStack_f8;
          iVar48 = FUN_0010b0f4(iVar25,1);
          *(undefined4 *)(iVar48 + 0x10) = uVar37;
          FUN_000fbaca(param_1,iVar25,local_2c);
          puStack_fc = puStack_fc + 1;
          puStack_f8 = puStack_f8 + 1;
        } while (puVar24 != puStack_fc);
      }
      uVar37 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
      FUN_000fd68a(param_1,0,0,param_2,uVar37,1,DAT_001c66f4,&uStack_a0,puVar1,1,local_2c);
      ((int (*)())FUN_0010a3c2)(uVar37,1,uVar21);
      FUN_000fbaca(param_1,uVar37,local_2c);
      break;
    case 0xbe:
      uVar21 = *(undefined4 *)(local_374 + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
      *puVar24 = uVar21;
      puVar32 = puVar24 + 1;
      FUN_0010ac30(puVar32,0xb4,*(undefined4 *)(param_1 + 8));
      if ((*(ushort *)(param_2 + 0x8e) & 0x3fff) != 0) {
        puVar24[0x4c] = 1;
      }
      ((int (*)())FUN_000fe286)(param_1,local_68,iVar48,**(undefined4 **)(param_2 + 0x6c),puVar1,&local_38,
                   &local_80);
      psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
      if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (*(int *)(param_1 + 8) != 0)) &&
         (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) < '\0')) {
        sVar15 = 0xf;
      }
      else {
        sVar15 = *psVar4;
      }
      iVar25 = (int)sVar15;
      bVar13 = *(byte *)(psVar4 + 1) & 0x3f;
      iVar48 = FUN_0012ead6(*(undefined4 *)(param_1 + 0x3a0),0x2c,0,0);
      if (iVar48 == 0) {
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar33 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
        *puVar33 = uVar21;
        puVar24 = puVar33 + 1;
        FUN_0010dfac(puVar24,*(undefined4 *)(param_1 + 8));
        puVar33[6] = puVar33[6] | 0x10000;
        *(undefined4 **)(param_1 + 0x350) = puVar24;
        puVar33[0x28] = DAT_001c66f4;
        iVar48 = FUN_0012eb2a(*(undefined4 *)(param_1 + 0x3a0),0x2c,0,0);
        ((int (*)())FUN_0010a3c2)(puVar24,0,iVar48);
        ((int (*)())FUN_0010a3c2)(puVar24,1,iVar48);
        iVar26 = FUN_0010b0f4(puVar24,1);
        *(undefined **)(iVar26 + 0x10) = DAT_001c66c0;
        FUN_000e9512(*(undefined4 *)(param_1 + 0x39c),puVar24);
        FUN_0012a42e(iVar48,puVar24);
        FUN_0012a9e6(iVar48,1,puVar24);
      }
      ((int (*)())FUN_0010a3c2)(puVar32,0,iVar48);
      uVar21 = FUN_000edadc(param_1,bVar13);
      iVar48 = FUN_0010b0f4(puVar32,1);
      *(int *)(iVar48 + 8) = iVar25;
      *(undefined4 *)(iVar48 + 0xc) = uVar21;
      uVar21 = FUN_000edadc(param_1,bVar13);
      iVar48 = FUN_0010b0f4(puVar32,2);
      *(int *)(iVar48 + 8) = iVar25;
      *(undefined4 *)(iVar48 + 0xc) = uVar21;
      uVar21 = FUN_000edadc(param_1,bVar13);
      iVar48 = FUN_0010b0f4(puVar32,3);
      *(int *)(iVar48 + 8) = iVar25;
      *(undefined4 *)(iVar48 + 0xc) = uVar21;
      (*(unsigned char *)((unsigned char *)&(uStack_a0) + 1)) = (undefined1)((uint)DAT_001c66c0 >> 8);
      uVar11 = (*(unsigned char *)((unsigned char *)&(uStack_a0) + 1));
      (*(unsigned short *)((unsigned char *)&(uStack_a0) + 0)) = SUB42(DAT_001c66c0,0);
      (*(unsigned int *)((unsigned char *)&(uStack_a0) + 0)) = CONCAT12(uVar11,(undefined2)uStack_a0);
      uStack_a0 = (undefined *)CONCAT13(uVar11,(undefined3)uStack_a0);
      FUN_000fb2d4(param_1,&uStack_a0,**(undefined4 **)(param_2 + 0x6c),1,puVar32);
      uStack_a0 = (undefined *)_UNK_001c66f0;
      FUN_000fb2d4(param_1,&uStack_a0,**(undefined4 **)(param_2 + 0x6c),2,puVar32);
      uStack_a0 = _UNK_001c66ec;
      FUN_000fb2d4(param_1,&uStack_a0,**(undefined4 **)(param_2 + 0x6c),3,puVar32);
      iVar48 = *(int *)(iStack_60 + 8);
      iVar25 = iStack_60;
      while (iVar26 = iVar48, iVar26 != 0) {
        FUN_001a7d72(iVar25);
        FUN_000fbaca(param_1,iVar25,local_2c);
        iVar25 = iVar26;
        iVar48 = *(int *)(iVar26 + 8);
      }
      FUN_000fbaca(param_1,puVar32,local_2c);
      break;
    case 0xe3:
      uVar21 = *(undefined4 *)(local_374 + 0xb8);
      puVar24 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
      *puVar24 = uVar21;
      puVar24 = puVar24 + 1;
      FUN_0010ac30(puVar24,0x106,*(undefined4 *)(param_1 + 8));
      FUN_000fbaca(param_1,puVar24,local_2c);
      puVar51 = *(uint **)(param_1 + 0x408);
      uVar46 = puVar51[1];
      if (uVar46 < *puVar51) {
        _memset((void *)(uVar46 * 4 + puVar51[2]),0,4);
        puVar51[1] = uVar46 + 1;
        puVar32 = (undefined4 *)(uVar46 * 4 + puVar51[2]);
      }
      else {
        puVar32 = (undefined4 *)FUN_001a7f7c(puVar51,uVar46);
      }
      *puVar32 = puVar24;
    }
  default:
    goto LAB_0010153e;
  case 4:
    bVar7 = false;
    break;
  case 5:
    iStack_1fc = *(int *)(iVar26 + 0x18 + iVar25 * 0x24);
    puStack_358 = DAT_001c66f4;
    uStack_a0 = DAT_001c66c0;
    uVar21 = *(undefined4 *)(local_374 + 0xbc);
    puVar32 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
    *puVar32 = uVar21;
    puVar51 = puVar32 + 1;
    puVar32[4] = uVar21;
    puVar32[2] = 0;
    puVar32[1] = 2;
    uVar21 = FUN_001a7bca(uVar21,8);
    puVar32[3] = uVar21;
    uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar33 = (undefined4 *)FUN_001a7bca(uVar21,0x14);
    *puVar33 = uVar21;
    puVar24 = puVar33 + 1;
    puVar33[4] = uVar21;
    puVar33[2] = 0;
    puVar33[1] = 2;
    uVar21 = FUN_001a7bca(uVar21,8);
    puVar33[3] = uVar21;
    local_30 = (int *)0x0;
    piVar42 = aiStack_c4;
    for (iVar26 = 9; iVar26 != 0; iVar26 = iVar26 + -1) {
      *piVar42 = 0;
      piVar42 = piVar42 + 1;
    }
    local_374 = *(int *)(param_1 + 8);
    uVar21 = *(undefined4 *)(*(int *)(local_374 + 0x54) + 0xc);
    iVar26 = FUN_000fb1c8(iVar25,uVar21);
    iVar27 = FUN_000fb1da(iVar25,uVar21);
    if (0 < iVar26) {
      iStack_d4 = 0;
      do {
        iVar53 = iStack_d4 << 2;
        for (iVar28 = 0;
            iVar29 = FUN_000fb1ec(iVar25,iStack_d4,*(undefined4 *)(*(int *)(local_374 + 0x54) + 0xc)
                                 ), iVar28 <= iVar29; iVar28 = iVar28 + 1) {
          FUN_000fc3f6(param_1,local_50,*(undefined4 *)(*(int *)(param_2 + 100) + iVar53),puVar1,
                       local_2fc);
          iVar53 = iVar53 + 0x14;
          local_374 = *(int *)(param_1 + 8);
        }
        iStack_d4 = iStack_d4 + 1;
      } while (iVar26 != iStack_d4);
    }
    if (0 < iVar27) {
      iStack_d0 = 0;
      do {
        iVar53 = iStack_d0 << 2;
        for (iVar28 = 0;
            iVar29 = FUN_000fb1ec(iVar25,iVar26 + iStack_d0,
                                  *(undefined4 *)(*(int *)(local_374 + 0x54) + 0xc)),
            iVar28 <= iVar29; iVar28 = iVar28 + 1) {
          ((int (*)())FUN_000fe286)(param_1,local_68,iVar48,*(undefined4 *)(*(int *)(param_2 + 0x6c) + iVar53),
                       puVar1,&local_38,&local_80);
          iVar53 = iVar53 + 0x14;
          local_374 = *(int *)(param_1 + 8);
        }
        iStack_d0 = iStack_d0 + 1;
      } while (iVar27 != iStack_d0);
    }
    iVar27 = *(int *)(iStack_60 + 8);
    iVar48 = iStack_60;
    while (iVar28 = iVar27, iVar28 != 0) {
      FUN_001a7d72(iVar48);
      FUN_000fbaca(param_1,iVar48,local_2c);
      iVar48 = iVar28;
      iVar27 = *(int *)(iVar28 + 8);
    }
    uStack_2e2 = 0;
    piStack_1f8 = (int *)0x0;
    iStack_1f0 = 0;
    do {
      iVar48 = *(int *)(iStack_1fc + (int)local_30 * 4);
      switch(iVar48) {
      default:
code_r0x00102548:
        bVar7 = true;
        break;
      case 1:
      case 0x13:
      case 0x33:
      case 0x39:
      case 0x3b:
      case 0x3c:
      case 0x3e:
      case 0x40:
      case 0x4c:
      case 0x5e:
        goto code_r0x00102bcc;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
        iVar48 = FUN_000fd68a(param_1,iVar48 + -2,iStack_1f0,param_2,piStack_1f8,iVar26,puStack_358,
                              &uStack_a0,puVar1,uStack_2e2,local_2c);
        if (iVar48 != 0) {
          FUN_001a7d0c(local_50,iVar48);
        }
        goto code_r0x00102c5b;
      case 0x12:
        ((int (*)())FUN_00109c0e)(piStack_1f8 + iStack_1f0 * 6 + 0x23,2,1);
        bVar7 = false;
        break;
      case 0x14:
      case 0x15:
      case 0x16:
        uVar46 = *(ushort *)(param_2 + 0x8e) & 0x3fff;
        if (iVar48 == 0x14) {
          puVar41 = (PTR_DAT_001ef530)[uVar46];
        }
        else if (iVar48 == 0x15) {
          puVar41 = (PTR_DAT_001ef520)[uVar46];
        }
        else {
          puVar41 = (PTR_DAT_001ef510)[uVar46];
        }
        goto code_r0x00102ce2;
      case 0x17:
        iVar48 = FUN_000e5e14(param_2);
        if ((iVar48 == 0x3e) || (iVar48 = FUN_000e5e14(param_2), iVar48 == 0x71)) {
          if (puVar20[2] != 0) {
            if (puVar20[2] - 1 < (uint)puVar20[2]) {
              piVar42 = (int *)(puVar20[3] + (puVar20[2] - 1) * 4);
            }
            else {
              piVar42 = (int *)0x0;
            }
            iVar48 = *piVar42;
            puVar41 = PTR_DAT_002134b5;
            if (puVar22[2] != 0) {
              if (puVar22[2] - 1 < (uint)puVar22[2]) {
                iVar27 = *(int *)(*(int *)(puVar22[3] + (puVar22[2] - 1) * 4) + 0xb8);
              }
              else {
                iVar27 = *(int *)(MACH_HEADER.magic + 0xb8);
              }
              if (local_20[0] <= iVar27) {
                uVar21 = *(undefined4 *)(iVar48 + 0x144);
                uVar37 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
                puVar43 = (undefined4 *)FUN_001a7bca(uVar37,0x130);
                *puVar43 = uVar37;
                piVar42 = puVar43 + 1;
                FUN_000ed9bc(piVar42,iVar48,*(undefined4 *)(iVar48 + 0x124),
                             *(undefined4 *)(param_1 + 8));
                puVar43[0x2f] = local_20[0];
                FUN_000edc32(param_1,local_28,piVar42);
                FUN_000ea91c(local_28,piVar42);
                FUN_000ea91c(piVar42,uVar21);
                local_28 = piVar42;
                *(int *)(iVar48 + 0x130) = *(int *)(iVar48 + 0x130) + 1;
                bVar7 = false;
                break;
              }
            }
            goto code_r0x00102da5;
          }
        }
        else {
          iVar48 = FUN_000e5e14(param_2);
          if (iVar48 == 0x72) {
            if (puVar23[2] - 1 < (uint)puVar23[2]) {
              piVar42 = (int *)(puVar23[3] + (puVar23[2] - 1) * 4);
            }
            else {
              piVar42 = (int *)0x0;
            }
            *(int *)(*piVar42 + 4) = *(int *)(*piVar42 + 4) + 1;
            iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,0,PTR_DAT_002134ad,puVar24);
            goto code_r0x00102d09;
          }
        }
        goto code_r0x00102bcc;
      case 0x1f:
        local_30 = (int *)((int)local_30 + 1);
        uStack_a0 = *(undefined **)(iStack_1fc + (int)local_30 * 4);
        bVar7 = false;
        break;
      case 0x20:
        local_30 = (int *)((int)local_30 + 1);
        puStack_358 = *(undefined **)(iStack_1fc + (int)local_30 * 4);
        bVar7 = false;
        break;
      case 0x21:
        switch(*(byte *)(param_2 + 0x8e) & 7) {
        case 0:
          puVar41 = PTR_DAT_00213479;
          break;
        case 1:
          puVar41 = PTR_DAT_002134a5;
          break;
        case 2:
          puVar41 = PTR_DAT_002134a1;
          break;
        case 3:
          puVar41 = PTR_DAT_002134c5;
          break;
        case 4:
          puVar41 = PTR_DAT_0021348d;
          break;
        case 5:
          puVar41 = PTR_DAT_0021346d;
          break;
        default:
code_r0x001055bb:
          puVar41 = (undefined *)0x0;
        }
        goto code_r0x001047eb;
      case 0x22:
        uVar17 = *(ushort *)(param_2 + 0x8e) >> 6;
        uVar45 = uVar17 & 7;
        if ((uVar17 & 7) == 0) goto code_r0x00102bcc;
        iVar48 = ((int (*)())FUN_0010a17a)(0x12,*(undefined4 *)(param_1 + 8));
        if (aiStack_c4[1] == 0) {
          aiStack_c4[1] = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = aiStack_c4[1];
        }
        iVar27 = aiStack_c4[1];
        iVar28 = FUN_0010b0f4(iVar48,0);
        *(int *)(iVar28 + 8) = iVar27;
        *(undefined4 *)(iVar28 + 0xc) = 0;
        psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
        if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (*(int *)(param_1 + 8) != 0)) &&
           (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) < '\0')) {
          sVar15 = 0xf;
        }
        else {
          sVar15 = *psVar4;
        }
        uVar21 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
        iVar28 = FUN_0010b0f4(iVar48,1);
        *(int *)(iVar28 + 8) = (int)sVar15;
        *(undefined4 *)(iVar28 + 0xc) = uVar21;
        FUN_000fb2d4(param_1,&uStack_a0,**(undefined4 **)(param_2 + 0x6c),iStack_1f0,iVar48);
        if (uVar45 == 2) {
          FUN_000fa0d2(iVar48,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
code_r0x00106add:
          ((int (*)())FUN_00109c0e)(iVar48 + 0xbc,1,1);
        }
        else if (uVar45 < 3) {
          if (uVar45 == 1) {
            FUN_000fa0d2(iVar48,param_1,2,0x3f000000,0x3f000000,0x3f000000,0x3f000000);
            goto code_r0x00106add;
          }
        }
        else if (uVar45 == 3) {
          FUN_000fa0d2(iVar48,param_1,2,0x3f000000,0x3f000000,0x3f000000,0x3f000000);
        }
        else if (uVar45 == 4) {
          FUN_000fa0d2(iVar48,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
        }
        FUN_000fbaca(param_1,iVar48,local_2c);
        iVar48 = FUN_0010b0f4(piStack_1f8,iStack_1f0);
        *(int *)(iVar48 + 8) = iVar27;
        *(undefined4 *)(iVar48 + 0xc) = 0;
        iStack_1f0 = iStack_1f0 + 1;
        local_30 = (int *)((int)local_30 + 1);
        bVar7 = false;
        break;
      case 0x23:
        switch(*(byte *)(param_2 + 0x8e) & 7) {
        case 0:
          puVar41 = PTR_DAT_002134b9;
          break;
        case 1:
          puVar41 = PTR_DAT_00213475;
          break;
        case 2:
          puVar41 = PTR_DAT_0021349d;
          break;
        case 3:
          puVar41 = PTR_DAT_00213489;
          break;
        case 4:
          puVar41 = PTR_DAT_002134bd;
          break;
        case 5:
          puVar41 = PTR_DAT_00213499;
          break;
        default:
          goto code_r0x001055bb;
        }
        goto code_r0x001047eb;
      case 0x24:
        if (puVar20[2] != 0) {
          puVar41 = PTR_DAT_00213471;
          if (puVar22[2] != 0) {
            if (puVar22[2] - 1 < (uint)puVar22[2]) {
              piVar42 = (int *)(puVar22[3] + (puVar22[2] - 1) * 4);
            }
            else {
              piVar42 = (int *)0x0;
            }
            if (local_20[0] <= *(int *)(*piVar42 + 0xb8)) {
              if (puVar20[2] - 1 < (uint)puVar20[2]) {
                piVar42 = (int *)(puVar20[3] + (puVar20[2] - 1) * 4);
              }
              else {
                piVar42 = (int *)0x0;
              }
              iVar48 = *piVar42;
              uVar21 = *(undefined4 *)(iVar48 + 0x140);
              uVar37 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
              puVar43 = (undefined4 *)FUN_001a7bca(uVar37,0x130);
              *puVar43 = uVar37;
              piVar42 = puVar43 + 1;
              FUN_000eda3c(piVar42,iVar48,*(undefined4 *)(iVar48 + 0x124),
                           *(undefined4 *)(param_1 + 8));
              puVar43[0x2f] = local_20[0];
              FUN_000edc32(param_1,local_28,piVar42);
              FUN_000ea91c(local_28,piVar42);
              FUN_000ea91c(piVar42,uVar21);
              local_28 = piVar42;
              *(undefined1 *)(iVar48 + 0x134) = 1;
              bVar7 = false;
              break;
            }
          }
code_r0x00102da5:
          iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,0,puVar41,puVar24);
          goto code_r0x00102d09;
        }
        goto code_r0x00102bcc;
      case 0x26:
        if (puVar32[2] - 1 < (uint)puVar32[2]) {
          puVar43 = (undefined4 *)(puVar32[3] + (puVar32[2] - 1) * 4);
        }
        else {
          puVar43 = (undefined4 *)0x0;
        }
        piVar42 = local_30;
        if (*(char *)*puVar43 == '\0') goto code_r0x00102bcc;
        do {
          while (local_30 = piVar42, *(int *)(iStack_1fc + (int)local_30 * 4) == 0x37) {
            piVar42 = (int *)((int)local_30 + 2);
            local_30 = (int *)((int)local_30 + 1);
            if (*(int *)(iStack_1fc + (int)piVar42 * 4) == 0x28) goto code_r0x0010368c;
          }
          piVar42 = (int *)((int)local_30 + 1);
        } while (*(int *)(iStack_1fc + ((int)local_30 + 1) * 4) != 0x28);
code_r0x0010368c:
        bVar7 = false;
        break;
      case 0x27:
        if (puVar22[2] - 1 < (uint)puVar22[2]) {
          piVar42 = (int *)(puVar22[3] + (puVar22[2] - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        iVar48 = *piVar42;
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
        *puVar43 = uVar21;
        piVar42 = puVar43 + 1;
        FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
        puVar43[0x2f] = local_20[0];
        *(int **)(iVar48 + 0x130) = piVar42;
        local_2c = piVar42;
        FUN_000ea91c(iVar48,piVar42);
        FUN_000edc32(param_1,local_28,local_2c);
        goto code_r0x00103730;
      case 0x28:
        uVar46 = puVar32[2];
        if (uVar46 - 1 < uVar46) {
          piVar42 = (int *)(puVar32[3] + (uVar46 - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        iVar48 = *piVar42;
        FUN_001a7f3c(puVar51,uVar46 - 1);
        if (iVar48 == 0) goto code_r0x00102bcc;
        FUN_001a7aba(*(undefined4 *)(iVar48 + -4),iVar48 + -4);
        bVar7 = false;
        break;
      case 0x29:
        if (puVar22[2] - 1 < (uint)puVar22[2]) {
          piVar42 = (int *)(puVar22[3] + (puVar22[2] - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        piVar42 = (int *)*piVar42;
        iVar48 = piVar42[0x4d];
        *(int *)(iVar48 + 0xb8) = local_20[0];
        FUN_000edc32(param_1,local_28,iVar48);
        piVar39 = (int *)FUN_000e98fc(piVar42);
        piVar39[0x2e] = local_20[0];
        cVar12 = (**(code **)(*piVar39 + 0x38))(piVar39);
        if ((cVar12 == '\0') && (cVar12 = (**(code **)(*piVar39 + 0x3c))(piVar39), cVar12 == '\0'))
        {
          FUN_000ea91c(piVar39,iVar48);
        }
        piVar40 = (int *)FUN_000e986a(piVar42);
        piVar40[0x2e] = local_20[0];
        piVar39 = piVar40;
        if (piVar40 == piVar42) {
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
          *puVar43 = uVar21;
          piVar39 = puVar43 + 1;
          FUN_000eb992(piVar39,*(undefined4 *)(param_1 + 8));
          puVar43[0x2f] = local_20[0];
          piVar40[0x4c] = (int)piVar39;
          FUN_000ea91c(piVar40,piVar39);
          FUN_000edc32(param_1,local_28,piVar39);
        }
        cVar12 = (**(code **)(*piVar39 + 0x38))(piVar39);
        if ((cVar12 == '\0') && (cVar12 = (**(code **)(*piVar39 + 0x3c))(piVar39), cVar12 == '\0'))
        {
          FUN_000ea91c(piVar39,iVar48);
        }
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
        *puVar43 = uVar21;
        piVar42 = puVar43 + 1;
        FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
        puVar43[0x2f] = local_20[0];
        local_2c = piVar42;
        FUN_000edc32(param_1,iVar48,piVar42);
        FUN_000ea91c(iVar48,local_2c);
        local_28 = local_2c;
        FUN_001a7f3c(puVar2,puVar22[2] + -1);
        if (puVar20[2] == 0) goto code_r0x00102bcc;
        if (puVar20[2] - 1 < (uint)puVar20[2]) {
          piVar42 = (int *)(puVar20[3] + (puVar20[2] - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        *(int *)(*piVar42 + 0x124) = *(int *)(*piVar42 + 0x124) + -1;
        bVar7 = false;
        break;
      case 0x2a:
        if (puVar33[2] == 0) goto code_r0x00102548;
        uVar46 = puVar33[2];
        if (uVar46 - 1 < uVar46) {
          piVar42 = (int *)(puVar33[3] + (uVar46 - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        piVar42 = (int *)*piVar42;
        FUN_001a7f3c(puVar24,uVar46 - 1);
        piVar39 = (int *)piVar42[2];
        if ((int *)piVar42[2] == (int *)0x0) {
          piVar39 = local_2c;
        }
        local_2c = piVar39;
        iStack_1fc = *piVar42;
        local_30 = (int *)piVar42[1];
        if (piVar42 == (int *)0x0) goto code_r0x00102bcc;
        FUN_001a7aba(piVar42[-1],piVar42 + -1);
        bVar7 = false;
        break;
      case 0x2c:
        piVar42 = (int *)0x1ef400;
        if (((*(int *)0x001ef400) == 0) || (iVar25 == (*(int *)0x001ef400))) {
code_r0x00102593:
          iStack_1b4 = 0;
          uStack_1b0 = (*(unsigned int *)0x001ef404);
          if (-1 < (char)(*(unsigned int *)0x001ef404)) goto code_r0x00103945;
code_r0x001025be:
          uStack_1b8 = (uint)*(byte *)(param_2 + 0x8e);
          uVar46 = *(byte *)(param_2 + 0x8f) & 0x1f;
        }
        else {
          iStack_1b4 = 0;
          do {
            piVar42 = piVar42 + 3;
            iStack_1b4 = iStack_1b4 + 1;
            if (*piVar42 == 0) goto code_r0x00102593;
          } while (iVar25 != *piVar42);
          uStack_1b0 = *(uint *)(iStack_1b4 * 0xc + 0x1ef404);
          if ((char)uStack_1b0 < '\0') goto code_r0x001025be;
code_r0x00103945:
          uVar46 = (uint)*(byte *)(param_2 + 0x8e);
          uStack_1b8 = uVar46;
        }
        if (*(int *)(param_1 + 0x7c) < (int)uStack_1b8) {
          *(uint *)(param_1 + 0x7c) = uStack_1b8;
        }
        *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1 << ((byte)uStack_1b8 & 0x1f);
        puVar35 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),0x24);
        puVar43 = puVar35;
        for (iVar48 = 9; iVar48 != 0; iVar48 = iVar48 + -1) {
          *puVar43 = 0;
          puVar43 = puVar43 + 1;
        }
        *(undefined2 *)puVar35 = 3;
        *(undefined2 *)((int)puVar35 + 2) = 3;
        *(undefined2 *)(puVar35 + 1) = 3;
        *(undefined2 *)((int)puVar35 + 6) = 7;
        *(undefined2 *)(puVar35 + 2) = 7;
        *(undefined2 *)((int)puVar35 + 10) = 3;
        *(undefined2 *)(puVar35 + 3) = 3;
        *(undefined2 *)((int)puVar35 + 0xe) = 1;
        *(undefined2 *)(puVar35 + 4) = 0;
        *(undefined2 *)((int)puVar35 + 0x12) = 1;
        *(undefined2 *)((int)puVar35 + 0x16) = 0;
        *(undefined2 *)(puVar35 + 6) = 0;
        *(undefined2 *)((int)puVar35 + 0x1a) = 0;
        *(undefined2 *)(puVar35 + 7) = 0;
        *(undefined2 *)(puVar35 + 5) = 0;
        puVar35[8] = uVar46;
        if ((*(char *)(param_2 + 0x8f) < '\0') && (param_2 != -0x94)) {
          uVar16 = FUN_000fb268(*(byte *)(param_2 + 0x94) & 7);
          *(undefined2 *)puVar35 = uVar16;
          uVar16 = FUN_000fb268(*(byte *)(param_2 + 0x94) >> 3 & 7);
          *(undefined2 *)((int)puVar35 + 2) = uVar16;
          uVar16 = FUN_000fb268(*(byte *)(param_2 + 0x95) >> 4 & 7);
          *(undefined2 *)(puVar35 + 1) = uVar16;
          uVar16 = FUN_000fb268(*(ushort *)(param_2 + 0x94) >> 6 & 7);
          *(undefined2 *)((int)puVar35 + 10) = uVar16;
          uVar16 = FUN_000fb268(*(byte *)(param_2 + 0x95) >> 1 & 7);
          *(undefined2 *)(puVar35 + 3) = uVar16;
          uVar16 = FUN_000fb268(*(uint *)(param_2 + 0x94) >> 0xf & 7);
          *(undefined2 *)((int)puVar35 + 6) = uVar16;
          *(ushort *)((int)puVar35 + 0x16) = *(ushort *)(param_2 + 0x96) >> 2 & 0x7f;
          if ((uStack_1b0 & 4) != 0) {
            *(ushort *)(puVar35 + 4) = (*(byte *)(param_2 + 0x97) >> 1 & 1) + 1;
          }
        }
        if (*(char *)(param_2 + 0x60) != '\0') {
          uVar21 = *(undefined4 *)(param_2 + 0x90);
          *(ushort *)(puVar35 + 6) = (ushort)uVar21 & 0xff;
          *(ushort *)((int)puVar35 + 0x1a) = (ushort)((uint)uVar21 >> 8) & 0xff;
          *(ushort *)(puVar35 + 7) = (ushort)((uint)uVar21 >> 0x10) & 0xff;
        }
        bVar13 = *(byte *)(param_2 + 0x8f) & 1;
        *(ushort *)((int)puVar35 + 0x12) = (ushort)(bVar13 == 0);
        bVar14 = *(byte *)(param_2 + 0x8f) >> 1;
        *(ushort *)((int)puVar35 + 0xe) = (ushort)((bVar14 & 1) == 0);
        if ((uStack_1b0 & 1) != 0) {
          *(ushort *)(puVar35 + 4) = (ushort)(iVar25 != 0x5f);
        }
        iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
        uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
        puVar41 = DAT_001c66f4;
        uStack_a0 = DAT_001c66c0;
        iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
        uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
        uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(uVar38,0,uVar37);
        FUN_000fd68a(param_1,5,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
        FUN_000fbaca(param_1,uVar38,local_2c);
        if ((uStack_1b0 & 1) == 0) {
          uStack_1a0 = 0;
        }
        else {
          iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
          uStack_1a0 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
          uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar38,0,uStack_1a0);
          FUN_000fd68a(param_1,10,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
          FUN_000fbaca(param_1,uVar38,local_2c);
        }
        uVar46 = uStack_1b0 >> 3;
        if ((uVar46 & 1) == 0) {
          uStack_19c = 0;
        }
        else {
          iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
          uStack_19c = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
          uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar38,0,uStack_19c);
          FUN_000fd68a(param_1,0xe,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
          FUN_000fbaca(param_1,uVar38,local_2c);
        }
        if ((uStack_1b0 & 0x40) != 0) {
          iVar48 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(iVar48,0,uVar37);
          ((int (*)())FUN_0010a3c2)(iVar48,1,uStack_1a0);
          iVar27 = FUN_0010b0f4(iVar48,1);
          *(undefined4 *)(iVar27 + 0x10) = DAT_001c66e4;
          *(int *)(iVar48 + 0x9c) = DAT_001c66d4;
          FUN_000fbaca(param_1,iVar48,local_2c);
        }
        iVar27 = uStack_1b8 * 0xc;
        iVar48 = *(int *)(*(int *)(param_1 + 0x78) + 4 + iVar27);
        if ((iVar48 == 4) || (iVar48 == 0xb)) {
          iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
          uStack_1a4 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
          uVar38 = ((int (*)())FUN_0010a17a)(0x1b,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar38,0,uStack_1a4);
          ((int (*)())FUN_0010a3c2)(uVar38,1,uVar37);
          uStack_a0 = (undefined *)0x1000202;
          iVar48 = FUN_0010b0f4(uVar38,1);
          *(undefined4 *)(iVar48 + 0x10) = 0x1000202;
          ((int (*)())FUN_0010a3c2)(uVar38,2,uVar37);
          uStack_a0 = (undefined *)0x2020001;
          iVar48 = FUN_0010b0f4(uVar38,2);
          *(undefined4 *)(iVar48 + 0x10) = 0x2020001;
          FUN_000fbaca(param_1,uVar38,local_2c);
          iVar28 = ((int (*)())FUN_0010a17a)(0x40,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(iVar28,0,uStack_1a4);
          *(undefined4 *)(iVar28 + 0x9c) = _UNK_001c66cc;
          ((int (*)())FUN_0010a3c2)(iVar28,1,uStack_1a4);
          ((int (*)())FUN_00109c0e)(iVar28 + 0xa4,2,1);
          iVar48 = _UNK_001c66f0;
          iVar53 = FUN_0010b0f4(iVar28,1);
          *(int *)(iVar53 + 0x10) = iVar48;
          FUN_000fbaca(param_1,iVar28,local_2c);
          iVar28 = ((int (*)())FUN_0010a17a)(0x14,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(iVar28,0,uStack_1a4);
          *(undefined1 *)(iVar28 + 0x9c) = 0;
          *(undefined1 *)(iVar28 + 0x9d) = 0;
          *(undefined1 *)(iVar28 + 0x9e) = 1;
          *(undefined1 *)(iVar28 + 0x9f) = 1;
          ((int (*)())FUN_0010a3c2)(iVar28,1,uStack_1a4);
          ((int (*)())FUN_0010a3c2)(iVar28,2,uStack_1a4);
          iVar53 = FUN_0010b0f4(iVar28,2);
          *(int *)(iVar53 + 0x10) = iVar48;
          FUN_000fa0d2(iVar28,param_1,3,0x3fc00000,0x3fc00000,0x3fc00000,0x3fc00000);
          FUN_000fbaca(param_1,iVar28,local_2c);
          piVar42 = (int *)((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(piVar42,0,uStack_1a4);
          ((int (*)())FUN_0010a3c2)(piVar42,1,uStack_1a4);
          (**(code **)(*piVar42 + 0x88))(piVar42,1,0,1);
          (**(code **)(*piVar42 + 0x88))(piVar42,1,1,0);
          (**(code **)(*piVar42 + 0x88))(piVar42,1,2,3);
          (**(code **)(*piVar42 + 0x88))(piVar42,1,3,0);
          FUN_000fbaca(param_1,piVar42,local_2c);
          if (iVar25 == 0x8b) {
            iVar48 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
            ((int (*)())FUN_0010a3c2)(iVar48,0,uStack_1a4);
            *(undefined1 *)(iVar48 + 0x9c) = 1;
            *(undefined1 *)(iVar48 + 0x9d) = 1;
            *(undefined1 *)(iVar48 + 0x9e) = 1;
            *(undefined1 *)(iVar48 + 0x9f) = 0;
            ((int (*)())FUN_0010a3c2)(iVar48,1,uVar37);
            FUN_000fbaca(param_1,iVar48,local_2c);
          }
          piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          (**(code **)(*piVar42 + 0x5c))(piVar42,uStack_1b8,*(int *)(param_1 + 8));
          if ((uVar46 & 1) != 0) goto code_r0x00105de8;
code_r0x001029d5:
          uStack_198 = 0;
        }
        else {
          uStack_1a4 = uVar37;
          if ((uVar46 & 1) == 0) goto code_r0x001029d5;
code_r0x00105de8:
          uVar37 = ((int (*)())FUN_0010a17a)(0x73,*(undefined4 *)(param_1 + 8));
          piVar42 = (int *)((int (*)())FUN_0010a17a)(0x72,*(undefined4 *)(param_1 + 8));
          uStack_198 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0x1e,0,0);
          ((int (*)())FUN_0010a3c2)(uVar37,0,uStack_198);
          ((int (*)())FUN_0010a3c2)(uVar37,1,uStack_1a0);
          ((int (*)())FUN_0010a3c2)(piVar42,0,uStack_198);
          ((int (*)())FUN_0010a3c2)(piVar42,1,uStack_19c);
          (**(code **)(*piVar42 + 0x90))(piVar42,uStack_198);
          FUN_000fbaca(param_1,uVar37,local_2c);
          FUN_000fbaca(param_1,piVar42,local_2c);
        }
        if ((uStack_1b0 & 1) == 0) {
          uVar47 = uStack_1b0 >> 2 & 1;
        }
        else {
          uVar47 = uStack_1b0 >> 2 & 1;
          if (uVar47 != 0) {
            iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
            *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
            uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
            iVar48 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
            ((int (*)())FUN_0010a3c2)(iVar48,0,uVar37);
            *(undefined4 *)(iVar48 + 0x9c) = _UNK_001c66d0;
            ((int (*)())FUN_0010a3c2)(iVar48,1,uStack_1a4);
            FUN_000fbaca(param_1,iVar48,local_2c);
            iVar48 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
            ((int (*)())FUN_0010a3c2)(iVar48,0,uVar37);
            *(int *)(iVar48 + 0x9c) = DAT_001c66d4;
            ((int (*)())FUN_0010a3c2)(iVar48,1,uStack_1a0);
            FUN_000fbaca(param_1,iVar48,local_2c);
            uStack_1a4 = uVar37;
          }
        }
        iVar48 = *(int *)(iStack_1b4 * 0xc + 0x1ef408);
        if ((uVar47 == 0) || ((bVar14 & 1) == 0)) {
          if ((iVar48 != 0xff) || (*(int *)(iVar27 + 4 + *(int *)(param_1 + 0x78)) != 7))
          goto code_r0x00102a26;
          iVar48 = ((int (*)())FUN_0010a17a)(0x104,*(undefined4 *)(param_1 + 8));
          *(undefined **)(iVar48 + 0x140) = DAT_001c66c0;
          *(uint *)(iVar48 + 0x130) = uStack_1b8;
          ((int (*)())FUN_0010a3c2)(iVar48,0,uVar21);
          ((int (*)())FUN_0010a3c2)(iVar48,1,uStack_1a4);
          FUN_000fbaca(param_1,iVar48,local_2c);
        }
        else {
          iVar48 = 0xae;
code_r0x00102a26:
          piVar42 = (int *)((int (*)())FUN_0010a17a)(iVar48,*(undefined4 *)(param_1 + 8));
          piVar42[0x4f] = (int)puVar35;
          piVar42[0x4d] = uStack_1b8;
          ((int (*)())FUN_0010a3c2)(piVar42,0,uVar21);
          ((int (*)())FUN_0010a3c2)(piVar42,1,uStack_1a4);
          if ((uVar46 & 1) == 0) {
            iVar48 = *(int *)(param_1 + 0x78);
            if (*(int *)(iVar27 + 4 + iVar48) != 8) goto code_r0x00102aaa;
code_r0x0010640f:
            (**(code **)(*piVar42 + 0x88))(piVar42,1,2,1);
            iVar53 = ((int (*)())FUN_0010a17a)(0xbe,*(undefined4 *)(param_1 + 8));
            iVar48 = piVar42[0x2c];
            iVar28 = piVar42[0x2b];
            iVar29 = FUN_0010b0f4(iVar53,0);
            *(int *)(iVar29 + 8) = iVar28;
            *(int *)(iVar29 + 0xc) = iVar48;
            iVar48 = piVar42[0x2c];
            iVar28 = piVar42[0x2b];
            iVar29 = FUN_0010b0f4(iVar53,1);
            *(int *)(iVar29 + 8) = iVar28;
            *(int *)(iVar29 + 0xc) = iVar48;
            iVar48 = FUN_0010b0f4(iVar53,1);
            *(undefined4 *)(iVar48 + 0x10) = DAT_001c66c8;
            *(undefined4 *)(iVar53 + 0x9c) = _UNK_001c66c4;
            FUN_000fbaca(param_1,iVar53,local_2c);
            iVar48 = *(int *)(param_1 + 0x78);
            iVar28 = *(int *)(iVar27 + 4 + iVar48);
          }
          else {
            (**(code **)(*piVar42 + 0x90))(piVar42,uStack_198);
            iVar48 = *(int *)(param_1 + 0x78);
            if (*(int *)(iVar27 + 4 + iVar48) == 8) goto code_r0x0010640f;
code_r0x00102aaa:
            iVar28 = *(int *)(iVar27 + 4 + iVar48);
          }
          if (iVar28 == 9) {
            iVar53 = ((int (*)())FUN_0010a17a)(0xbe,*(undefined4 *)(param_1 + 8));
            iVar48 = piVar42[0x2c];
            iVar28 = piVar42[0x2b];
            iVar29 = FUN_0010b0f4(iVar53,0);
            *(int *)(iVar29 + 8) = iVar28;
            *(int *)(iVar29 + 0xc) = iVar48;
            iVar48 = piVar42[0x2c];
            iVar28 = piVar42[0x2b];
            iVar29 = FUN_0010b0f4(iVar53,1);
            *(int *)(iVar29 + 8) = iVar28;
            *(int *)(iVar29 + 0xc) = iVar48;
            iVar48 = FUN_0010b0f4(iVar53,1);
            *(int *)(iVar48 + 0x10) = _UNK_001c66f0;
            *(undefined4 *)(iVar53 + 0x9c) = _UNK_001c66cc;
            FUN_000fbaca(param_1,iVar53,local_2c);
            iVar48 = *(int *)(param_1 + 0x78);
          }
          iVar48 = FUN_000fb24a(*(undefined4 *)(iVar27 + iVar48));
          piVar42[0x4e] = iVar48;
          *(ushort *)(piVar42[0x4f] + 0x12) = (ushort)bVar13;
          FUN_000fbaca(param_1,piVar42,local_2c);
          if (*(int *)(iVar27 + 8 + *(int *)(param_1 + 0x78)) != 0) {
            uVar37 = ((int (*)())FUN_0010a17a)(0x13,*(undefined4 *)(param_1 + 8));
            iVar48 = piVar42[0x26];
            iVar27 = piVar42[0x25];
            iVar28 = FUN_0010b0f4(uVar37,0);
            *(int *)(iVar28 + 8) = iVar27;
            *(int *)(iVar28 + 0xc) = iVar48;
            iVar48 = piVar42[0x26];
            iVar27 = piVar42[0x25];
            iVar28 = FUN_0010b0f4(uVar37,1);
            *(int *)(iVar28 + 8) = iVar27;
            *(int *)(iVar28 + 0xc) = iVar48;
            (*(unsigned short *)((unsigned char *)&(uStack_31c) + 2)) = (undefined2)uStack_1b8;
            uStack_31c = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_31c) + 2)),0x13);
            uStack_318 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_31c) + 2)),0x13);
            uStack_314 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_31c) + 2)),0x13);
            uStack_310 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_31c) + 2)),0x13);
            FUN_000f9d16(uVar37,param_1,2,uStack_310,uStack_314,uStack_318,uStack_31c);
            FUN_000fbaca(param_1,uVar37,local_2c);
          }
        }
        puVar41 = DAT_001c66f4;
        uStack_a0 = DAT_001c66c0;
        puStack_358 = DAT_001c66f4;
        piStack_1f8 = (int *)((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_000fd68a(param_1,0,0,param_2,piStack_1f8,1,puVar41,&uStack_a0,puVar1,1,local_2c);
        ((int (*)())FUN_0010a3c2)(piStack_1f8,1,uVar21);
        FUN_000fbaca(param_1,piStack_1f8,local_2c);
code_r0x00102bcc:
        bVar7 = false;
        break;
      case 0x2d:
      case 0x2e:
        bVar13 = *(byte *)(param_2 + 0x8e);
        uVar46 = (uint)bVar13;
        puVar35 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),0x24);
        puVar43 = puVar35;
        for (iVar27 = 9; iVar27 != 0; iVar27 = iVar27 + -1) {
          *puVar43 = 0;
          puVar43 = puVar43 + 1;
        }
        *(undefined2 *)puVar35 = 3;
        *(undefined2 *)((int)puVar35 + 2) = 3;
        *(undefined2 *)(puVar35 + 1) = 3;
        *(undefined2 *)((int)puVar35 + 6) = 7;
        *(undefined2 *)(puVar35 + 2) = 7;
        *(undefined2 *)((int)puVar35 + 10) = 3;
        *(undefined2 *)(puVar35 + 3) = 3;
        *(undefined2 *)((int)puVar35 + 0xe) = 1;
        *(undefined2 *)(puVar35 + 4) = 0;
        *(undefined2 *)((int)puVar35 + 0x12) = 1;
        *(undefined2 *)((int)puVar35 + 0x16) = 0;
        *(undefined2 *)(puVar35 + 6) = 0;
        *(undefined2 *)((int)puVar35 + 0x1a) = 0;
        *(undefined2 *)(puVar35 + 7) = 0;
        *(undefined2 *)(puVar35 + 5) = 0;
        *(ushort *)((int)puVar35 + 0x12) = (ushort)((*(byte *)(param_2 + 0x8f) & 1) == 0);
        bVar14 = *(byte *)(param_2 + 0x8f) >> 1;
        *(ushort *)((int)puVar35 + 0xe) = (ushort)((bVar14 & 1) == 0);
        iVar27 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar27;
        uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar27,0);
        uVar21 = _UNK_001c66d0;
        uStack_a0 = DAT_001c66c0;
        iVar27 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(iVar27,0,uVar37);
        *(undefined4 *)(iVar27 + 0x9c) = uVar21;
        FUN_000fd68a(param_1,5,1,param_2,iVar27,1,uVar21,&uStack_a0,puVar1,1,local_2c);
        FUN_000fbaca(param_1,iVar27,local_2c);
        iVar27 = DAT_001c66d4;
        uStack_a0 = DAT_001c66c0;
        piStack_1f8 = (int *)((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(piStack_1f8,0,uVar37);
        piStack_1f8[0x27] = iVar27;
        FUN_000fd68a(param_1,10,1,param_2,piStack_1f8,1,iVar27,&uStack_a0,puVar1,1,local_2c);
        FUN_000fbaca(param_1,piStack_1f8,local_2c);
        if ((bVar14 & 1) == 0) {
          uVar21 = 0x76;
        }
        else {
          if (iVar48 == 0x2d) {
            FUN_000e27ca(*(undefined4 *)(param_1 + 8),0xf);
          }
          uVar21 = 0xae;
        }
        puVar41 = DAT_001c66f4;
        puStack_358 = DAT_001c66f4;
        uStack_a0 = DAT_001c66c0;
        iVar48 = ((int (*)())FUN_0010a17a)(uVar21,*(undefined4 *)(param_1 + 8));
        *(undefined4 **)(iVar48 + 0x13c) = puVar35;
        *(uint *)(iVar48 + 0x134) = uVar46;
        if (*(int *)(param_1 + 0x7c) < (int)uVar46) {
          *(uint *)(param_1 + 0x7c) = uVar46;
        }
        *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1 << (bVar13 & 0x1f);
        uVar21 = FUN_000fb24a(*(undefined4 *)(*(int *)(param_1 + 0x78) + uVar46 * 0xc));
        *(undefined4 *)(iVar48 + 0x138) = uVar21;
        *(uint *)(iVar48 + 0x130) = uVar46;
        iVar27 = FUN_000fd68a(param_1,4,0,param_2,iVar48,1,puVar41,&uStack_a0,puVar1,1,local_2c);
        if (iVar27 != 0) {
          FUN_001a7d0c(local_50,iVar27);
        }
        ((int (*)())FUN_0010a3c2)(iVar48,1,uVar37);
        iVar27 = FUN_0010b0f4(iVar48,1);
        *(undefined **)(iVar27 + 0x10) = DAT_001c66c0;
        uVar21 = FUN_000fb24a(*(undefined4 *)(uVar46 * 0xc + *(int *)(param_1 + 0x78)));
        *(undefined4 *)(iVar48 + 0x138) = uVar21;
        FUN_000fbaca(param_1,iVar48,local_2c);
        bVar7 = false;
        break;
      case 0x2f:
        bVar13 = *(byte *)(param_2 + 0x8e);
        uVar46 = (uint)bVar13;
        puVar35 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(*(int *)(param_1 + 8) + 0xb8),0x24);
        puVar43 = puVar35;
        for (iVar48 = 9; iVar48 != 0; iVar48 = iVar48 + -1) {
          *puVar43 = 0;
          puVar43 = puVar43 + 1;
        }
        *(undefined2 *)puVar35 = 3;
        *(undefined2 *)((int)puVar35 + 2) = 3;
        *(undefined2 *)(puVar35 + 1) = 3;
        *(undefined2 *)((int)puVar35 + 6) = 7;
        *(undefined2 *)(puVar35 + 2) = 7;
        *(undefined2 *)((int)puVar35 + 10) = 3;
        *(undefined2 *)(puVar35 + 3) = 3;
        *(undefined2 *)((int)puVar35 + 0xe) = 1;
        *(undefined2 *)(puVar35 + 4) = 0;
        *(undefined2 *)((int)puVar35 + 0x12) = 1;
        *(undefined2 *)((int)puVar35 + 0x16) = 0;
        *(undefined2 *)(puVar35 + 6) = 0;
        *(undefined2 *)((int)puVar35 + 0x1a) = 0;
        *(undefined2 *)(puVar35 + 7) = 0;
        *(undefined2 *)(puVar35 + 5) = 0;
        bVar14 = *(byte *)(param_2 + 0x8f) & 1;
        *(ushort *)((int)puVar35 + 0x12) = (ushort)(bVar14 == 0);
        *(ushort *)((int)puVar35 + 0xe) = (ushort)((*(byte *)(param_2 + 0x8f) & 2) == 0);
        iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
        uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
        puVar41 = DAT_001c66f4;
        uStack_a0 = DAT_001c66c0;
        iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
        uVar37 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
        uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(uVar38,0,uVar37);
        FUN_000fd68a(param_1,5,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
        FUN_000fbaca(param_1,uVar38,local_2c);
        if (((uint)(iVar25 == 0x5f) * 9 & 1) == 0) {
          uStack_1cc = 0;
        }
        else {
          iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
          uStack_1cc = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
          uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar38,0,uStack_1cc);
          FUN_000fd68a(param_1,10,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
          FUN_000fbaca(param_1,uVar38,local_2c);
        }
        uVar47 = (iVar25 == 0x5f) / 1;
        if (uVar47 == 0) {
          uStack_1c8 = 0;
        }
        else {
          iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
          uStack_1c8 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
          uVar38 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
          ((int (*)())FUN_0010a3c2)(uVar38,0,uStack_1c8);
          FUN_000fd68a(param_1,0xe,1,param_2,uVar38,1,puVar41,&uStack_a0,puVar1,1,local_2c);
          FUN_000fbaca(param_1,uVar38,local_2c);
        }
        iVar48 = ((int (*)())FUN_0010a17a)(0x78,*(undefined4 *)(param_1 + 8));
        *(undefined4 **)(iVar48 + 0x13c) = puVar35;
        ((int (*)())FUN_0010a3c2)(iVar48,0,uVar21);
        ((int (*)())FUN_0010a3c2)(iVar48,1,uVar37);
        if (uVar47 != 0) {
          ((int (*)())FUN_0010a3c2)(iVar48,2,uStack_1cc);
          ((int (*)())FUN_0010a3c2)(iVar48,3,uStack_1c8);
        }
        *(uint *)(iVar48 + 0x134) = uVar46;
        if (*(int *)(param_1 + 0x7c) < (int)uVar46) {
          *(uint *)(param_1 + 0x7c) = uVar46;
        }
        *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1 << (bVar13 & 0x1f);
        uVar37 = FUN_000fb24a(*(undefined4 *)(*(int *)(param_1 + 0x78) + uVar46 * 0xc));
        *(undefined4 *)(iVar48 + 0x138) = uVar37;
        *(uint *)(iVar48 + 0x130) = uVar46;
        *(ushort *)(*(int *)(iVar48 + 0x13c) + 0x12) = (ushort)bVar14;
        FUN_000fbaca(param_1,iVar48,local_2c);
        puVar41 = DAT_001c66f4;
        uStack_a0 = DAT_001c66c0;
        puStack_358 = DAT_001c66f4;
        piStack_1f8 = (int *)((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        FUN_000fd68a(param_1,0,0,param_2,piStack_1f8,1,puVar41,&uStack_a0,puVar1,1,local_2c);
        ((int (*)())FUN_0010a3c2)(piStack_1f8,1,uVar21);
        FUN_000fbaca(param_1,piStack_1f8,local_2c);
        bVar7 = false;
        break;
      case 0x30:
        iVar48 = (int)local_30 * 4 + iStack_1fc;
        FUN_000fa0d2(piStack_1f8,param_1,iStack_1f0,*(undefined4 *)(iVar48 + 4),
                     *(undefined4 *)(iVar48 + 8),*(undefined4 *)(iVar48 + 0xc),
                     *(undefined4 *)(iVar48 + 0x10));
        puVar41 = uStack_a0;
        iVar48 = FUN_0010b0f4(piStack_1f8,iStack_1f0);
        uVar21 = FUN_000f5610(*(undefined4 *)(iVar48 + 0x10),puVar41);
        iVar48 = FUN_0010b0f4(piStack_1f8,iStack_1f0);
        *(undefined4 *)(iVar48 + 0x10) = uVar21;
        iStack_1f0 = iStack_1f0 + 1;
        local_30 = local_30 + 1;
        bVar7 = false;
        break;
      case 0x31:
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
        puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x10);
        *puVar43 = uVar21;
        pbVar34 = (byte *)(puVar43 + 1);
        local_30 = (int *)((int)local_30 + 1);
        switch(*(undefined4 *)(iStack_1fc + (int)local_30 * 4)) {
        case 0x3f:
          *pbVar34 = (*(byte *)(param_2 + 0x8e) & 4) != 0;
          break;
        default:
          *pbVar34 = 0;
          break;
        case 0x5f:
          *pbVar34 = *(byte *)(param_2 + 0x8f) & 1;
          break;
        case 0x67:
          *pbVar34 = 1;
          break;
        case 0x68:
          *pbVar34 = 0;
          break;
        case 0x69:
          *pbVar34 = 0;
          uVar46 = puVar32[2];
          if (*puVar51 <= uVar46) goto code_r0x00104ba2;
          goto code_r0x00104ae9;
        }
        uVar46 = puVar32[2];
        if (uVar46 < *puVar51) {
code_r0x00104ae9:
          _memset((void *)(uVar46 * 4 + puVar32[3]),0,4);
          puVar32[2] = uVar46 + 1;
          puVar43 = (undefined4 *)(uVar46 * 4 + puVar32[3]);
        }
        else {
code_r0x00104ba2:
          puVar43 = (undefined4 *)FUN_001a7f7c(puVar51,uVar46);
        }
        *puVar43 = pbVar34;
        bVar7 = false;
        break;
      case 0x32:
        if (puVar22[2] == 0) {
          iStack_134 = 0;
        }
        else {
          if (puVar22[2] - 1 < (uint)puVar22[2]) {
            piVar42 = (int *)(puVar22[3] + (puVar22[2] - 1) * 4);
          }
          else {
            piVar42 = (int *)0x0;
          }
          iStack_134 = *piVar42;
          *(undefined1 *)(iStack_134 + 0x13c) = 0;
        }
        local_30 = (int *)((int)local_30 + 1);
        switch(*(undefined4 *)(iStack_1fc + (int)local_30 * 4)) {
        case 0x62:
          iVar48 = ((int (*)())FUN_0010a17a)(0x8b,*(undefined4 *)(param_1 + 8));
          FUN_000fa0d2(iVar48,param_1,1,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
          FUN_000fa0d2(iVar48,param_1,2,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
          *(undefined4 *)(iVar48 + 300) = 0;
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x150);
          *puVar43 = uVar21;
          piStack_138 = puVar43 + 1;
          FUN_000ec126(piStack_138,iVar48,iStack_134,0,*(undefined4 *)(param_1 + 8));
          FUN_000e96a6(piStack_138,local_20[0]);
          FUN_000f0144(param_1,iVar48);
          if (puVar22[2] != 0) {
            *(undefined1 *)((int)puVar43 + 0x141) = 0;
          }
          uVar46 = puVar22[2];
          if (uVar46 < *puVar2) goto code_r0x00104e14;
          goto code_r0x00104fa7;
        case 99:
          iVar48 = *(int *)(param_1 + 8);
          psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
          if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (iVar48 != 0)) &&
             (*(char *)(*(int *)(iVar48 + 0x54) + 8) < '\0')) {
            sVar15 = 0xf;
          }
          else {
            sVar15 = *psVar4;
          }
          bVar13 = *(byte *)(psVar4 + 1);
          iVar48 = ((int (*)())FUN_0010a17a)(0x8d,iVar48);
          uVar21 = FUN_000edadc(param_1,bVar13 & 0x3f);
          iVar27 = FUN_0010b0f4(iVar48,1);
          *(int *)(iVar27 + 8) = (int)sVar15;
          *(undefined4 *)(iVar27 + 0xc) = uVar21;
          *(undefined4 *)(iVar48 + 300) = *(undefined4 *)PTR_DAT_0021347d;
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x150);
          *puVar43 = uVar21;
          piStack_138 = puVar43 + 1;
          FUN_000ed3cc(piStack_138,iVar48,iStack_134,*(undefined4 *)(param_1 + 8));
          FUN_000e96a6(piStack_138,local_20[0]);
          FUN_000f0144(param_1,iVar48);
          if (puVar22[2] != 0) {
            *(undefined1 *)((int)puVar43 + 0x141) = 0;
          }
          uVar46 = puVar22[2];
          if (uVar46 < *puVar2) {
            _memset((void *)(uVar46 * 4 + puVar22[3]),0,4);
            puVar22[2] = uVar46 + 1;
            puVar43 = (undefined4 *)(uVar46 * 4 + puVar22[3]);
          }
          else {
            puVar43 = (undefined4 *)FUN_001a7f7c(puVar2,uVar46);
          }
          *puVar43 = piStack_138;
          if (puVar20[2] == 0) break;
          uVar46 = puVar20[2] - 1;
          if (uVar46 < (uint)puVar20[2]) goto code_r0x00105137;
          goto code_r0x00104e68;
        case 100:
          iVar48 = *(int *)(param_1 + 8);
          psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
          if ((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) {
            piVar42 = (int *)(*(unsigned int *)((unsigned char *)&(section_00000054.sectname) + 0));
            if ((iVar48 == 0) || (piVar42 = *(int **)(iVar48 + 0x54), -1 < (char)piVar42[2]))
            goto code_r0x0010528a;
            sVar15 = 0xf;
          }
          else {
            piVar42 = *(int **)(iVar48 + 0x54);
code_r0x0010528a:
            sVar15 = *psVar4;
          }
          psVar5 = (short *)(*(undefined4 **)(param_2 + 0x6c))[1];
          if ((((*(byte *)(psVar5 + 1) & 0x3f) == 0x10) && (iVar48 != 0)) &&
             ((char)piVar42[2] < '\0')) {
            sStack_fe = 0xf;
          }
          else {
            sStack_fe = *psVar5;
          }
          uVar37 = (**(code **)(*piVar42 + 0x24))
                             (piVar42,*(byte *)(param_2 + 0x8e) & 7,(int)sVar15,
                              *(byte *)(psVar4 + 1) & 0x3f,(int)sStack_fe,
                              *(byte *)(psVar5 + 1) & 0x3f,uStack_a0,param_2,local_2c,iVar48);
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x150);
          *puVar43 = uVar21;
          piStack_138 = puVar43 + 1;
          FUN_000ec126(piStack_138,uVar37,iStack_134,0,*(undefined4 *)(param_1 + 8));
          goto code_r0x00104f58;
        case 0x65:
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
          *puVar43 = uVar21;
          FUN_0010ac30(puVar43 + 1,0x8c,*(undefined4 *)(param_1 + 8));
          puVar43[0x4c] = 6;
          piStack_138 = (int *)FUN_000fdbb4(param_1,puVar43 + 1,local_20[0],iStack_134,puVar2,puVar1
                                            ,param_2);
          break;
        case 0x66:
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x168);
          *puVar43 = uVar21;
          FUN_0010ac30(puVar43 + 1,0x8c,*(undefined4 *)(param_1 + 8));
          puVar43[0x4c] = 7;
          piStack_138 = (int *)FUN_000fdbb4(param_1,puVar43 + 1,local_20[0],iStack_134,puVar2,puVar1
                                            ,param_2);
          break;
        default:
          piStack_138 = (int *)0x0;
          break;
        case 0x6f:
          if (puVar23[2] - 1 < (uint)puVar23[2]) {
            puVar43 = (undefined4 *)(puVar23[3] + (puVar23[2] - 1) * 4);
          }
          else {
            puVar43 = (undefined4 *)0x0;
          }
          piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
          uVar37 = (**(code **)(*piVar42 + 0x28))
                             (piVar42,1,*(undefined4 *)*puVar43,4,
                              *(undefined4 *)(param_2 + 0x8c + *(int *)(param_2 + 0x58) * 4),
                              uStack_a0,param_2,local_2c,*(int *)(param_1 + 8));
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x150);
          *puVar43 = uVar21;
          piStack_138 = puVar43 + 1;
          FUN_000ec126(piStack_138,uVar37,iStack_134,0,*(undefined4 *)(param_1 + 8));
          if (puVar23[2] - 1 < (uint)puVar23[2]) {
            piVar42 = (int *)(puVar23[3] + (puVar23[2] - 1) * 4);
          }
          else {
            piVar42 = (int *)0x0;
          }
          iVar48 = *piVar42;
          FUN_000e962c(piStack_138,*(undefined4 *)(iVar48 + 8));
          *(int **)(iVar48 + 8) = piStack_138;
          FUN_000e96a6(piStack_138,local_20[0]);
          FUN_000f0144(param_1,uVar37);
          if (puVar22[2] != 0) {
            *(undefined1 *)((int)puVar43 + 0x141) = 0;
          }
          uVar46 = puVar22[2];
          if (*puVar2 <= uVar46) goto code_r0x00104fa7;
          goto code_r0x00104e14;
        case 0x72:
          iVar48 = *(int *)(param_1 + 8);
          psVar4 = (short *)**(undefined4 **)(param_2 + 0x6c);
          if ((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) {
            piVar42 = (int *)(*(unsigned int *)((unsigned char *)&(section_00000054.sectname) + 0));
            if ((iVar48 == 0) || (piVar42 = *(int **)(iVar48 + 0x54), -1 < (char)piVar42[2]))
            goto code_r0x00104ea9;
            sStack_100 = 0xf;
          }
          else {
            piVar42 = *(int **)(iVar48 + 0x54);
code_r0x00104ea9:
            sStack_100 = *psVar4;
          }
          uVar37 = (**(code **)(*piVar42 + 0x28))
                             (piVar42,iVar25 == 0x6f,(int)sStack_100,*(byte *)(psVar4 + 1) & 0x3f,0,
                              uStack_a0,param_2,local_2c,iVar48);
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x150);
          *puVar43 = uVar21;
          piStack_138 = puVar43 + 1;
          FUN_000ec126(piStack_138,uVar37,iStack_134,0,*(undefined4 *)(param_1 + 8));
code_r0x00104f58:
          FUN_000e96a6(piStack_138,local_20[0]);
          FUN_000f0144(param_1,uVar37);
          if (puVar22[2] != 0) {
            *(undefined1 *)((int)piStack_138 + 0x13d) = 0;
          }
          uVar46 = puVar22[2];
          if (uVar46 < *puVar2) {
code_r0x00104e14:
            _memset((void *)(uVar46 * 4 + puVar22[3]),0,4);
            puVar22[2] = uVar46 + 1;
            puVar43 = (undefined4 *)(uVar46 * 4 + puVar22[3]);
          }
          else {
code_r0x00104fa7:
            puVar43 = (undefined4 *)FUN_001a7f7c(puVar2,uVar46);
          }
          *puVar43 = piStack_138;
          if (puVar20[2] != 0) {
            uVar46 = puVar20[2] - 1;
            if (uVar46 < (uint)puVar20[2]) {
code_r0x00105137:
              piVar42 = (int *)(puVar20[3] + uVar46 * 4);
            }
            else {
code_r0x00104e68:
              piVar42 = (int *)0x0;
            }
            *(int *)(*piVar42 + 0x124) = *(int *)(*piVar42 + 0x124) + 1;
          }
        }
        FUN_000edc32(param_1,local_28,piStack_138);
        FUN_000ea91c(local_28,piStack_138);
        local_28 = piStack_138;
        local_2c = (int *)piStack_138[0x4b];
        FUN_000edc32(param_1,piStack_138,local_2c);
code_r0x00103730:
        local_28 = local_2c;
        bVar7 = false;
        break;
      case 0x34:
        iVar48 = FUN_0010b0f4(piStack_1f8,iStack_1f0);
        *(undefined4 *)(iVar48 + 8) = 0;
        *(undefined4 *)(iVar48 + 0xc) = 0x21;
        iStack_1f0 = iStack_1f0 + 1;
        bVar7 = false;
        break;
      case 0x35:
        if (puVar20[2] - 1 < (uint)puVar20[2]) {
          piVar42 = (int *)(puVar20[3] + (puVar20[2] - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        iVar48 = *piVar42;
        cVar12 = FUN_000e1402(*(undefined4 *)(param_1 + 8),3);
        if ((cVar12 == '\0') || (cVar12 = FUN_00133434(param_1,iVar48), cVar12 == '\0')) {
          cVar12 = FUN_00136740(param_1,puVar1,iVar48,&local_28,&local_2c,local_20);
          if (cVar12 != '\0') goto code_r0x00102bcc;
          if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0x4c) < local_20[0]) {
            FUN_000e27ca(*(int *)(param_1 + 8),8);
          }
          iVar27 = *(int *)(iVar48 + 0x140);
          FUN_000edc32(param_1,local_28,iVar27);
          cVar12 = (**(code **)(*local_28 + 0x38))(local_28);
          if ((cVar12 == '\0') &&
             (cVar12 = (**(code **)(*local_28 + 0x3c))(local_28), cVar12 == '\0')) {
            FUN_000ea91c(local_28,iVar27);
          }
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
          *puVar43 = uVar21;
          puVar35 = puVar43 + 1;
          FUN_000eb992(puVar35,*(undefined4 *)(param_1 + 8));
          FUN_000ea91c(iVar48,puVar35);
          FUN_000edc32(param_1,iVar27,puVar35);
          iVar48 = *(int *)(iVar48 + 0x144);
          FUN_000ea91c(puVar35,iVar48);
          FUN_000edc32(param_1,puVar35,iVar48);
          uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar35 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
          *puVar35 = uVar21;
          piVar42 = puVar35 + 1;
          FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
          local_2c = piVar42;
          FUN_000edc32(param_1,iVar48,piVar42);
          FUN_000ea91c(iVar48,local_2c);
          local_28 = local_2c;
          FUN_001a7f3c(puVar1,puVar20[2] + -1);
          *(int *)(iVar27 + 0xb8) = local_20[0];
          local_20[0] = local_20[0] + -1;
          *(int *)(iVar48 + 0xb8) = local_20[0];
          puVar43[0x2f] = local_20[0];
          local_2c[0x2e] = local_20[0];
          bVar7 = false;
        }
        else {
          local_28 = (int *)FUN_000e9b0e(iVar48);
          piVar42 = *(int **)(iVar48 + 0x140);
          if (piVar42 != (int *)0x0) {
            (**(code **)(*piVar42 + 4))(piVar42);
          }
          piVar42 = *(int **)(iVar48 + 0x144);
          if (piVar42 != (int *)0x0) {
            (**(code **)(*piVar42 + 4))(piVar42);
          }
          FUN_001a805e(local_28[0x34],iVar48);
          do {
            piVar42 = (int *)local_28[2];
            iVar48 = piVar42[0x26];
            iVar27 = *(int *)(iVar48 + 8);
            while (iVar27 != 0) {
              if ((*(uint *)(iVar48 + 0x14) & 1) != 0) {
                *(uint *)(iVar48 + 0x14) = *(uint *)(iVar48 + 0x14) & 0xfffffffe;
              }
              iVar48 = *(int *)(iVar48 + 8);
              iVar27 = *(int *)(iVar48 + 8);
            }
            FUN_001a7d22(piVar42 + 0x24);
            FUN_001a7d72(piVar42);
            if (piVar42 != (int *)0x0) {
              (**(code **)(*piVar42 + 4))(piVar42);
            }
          } while (piVar42 != local_2c);
          local_2c = local_28;
          local_20[0] = local_20[0] + -1;
          bVar7 = false;
        }
        break;
      case 0x36:
        if (puVar20[2] == 0) {
          uStack_148 = 0;
        }
        else {
          if (puVar20[2] - 1 < (uint)puVar20[2]) {
            puVar43 = (undefined4 *)(puVar20[3] + (puVar20[2] - 1) * 4);
          }
          else {
            puVar43 = (undefined4 *)0x0;
          }
          uStack_148 = *puVar43;
        }
        if (iVar25 == 0x71) {
          uVar16 = 0;
        }
        else {
          uVar16 = *(undefined2 *)**(undefined4 **)(param_2 + 0x6c);
        }
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar43 = (undefined4 *)FUN_001a7bca(uVar21,0x14c);
        *puVar43 = uVar21;
        puVar35 = puVar43 + 1;
        FUN_000ec2a0(puVar35,uVar16,uStack_148,iVar25 == 0x71,*(undefined4 *)(param_1 + 8));
        puVar43[0x2f] = local_20[0];
        if ((*(byte *)(param_2 + 0x8e) & 1) != 0) {
          *(undefined1 *)(puVar43 + 0x4c) = 1;
        }
        FUN_000f0144(param_1,puVar43[0x4f]);
        uVar46 = puVar20[2];
        if (uVar46 < *puVar1) {
          _memset((void *)(uVar46 * 4 + puVar20[3]),0,4);
          puVar20[2] = uVar46 + 1;
          puVar36 = (undefined4 *)(uVar46 * 4 + puVar20[3]);
        }
        else {
          puVar36 = (undefined4 *)FUN_001a7f7c(puVar1,uVar46);
        }
        *puVar36 = puVar35;
        local_20[0] = local_20[0] + 1;
        FUN_000edc32(param_1,local_28,puVar35);
        FUN_000ea91c(local_28,puVar35);
        uVar21 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
        puVar36 = (undefined4 *)FUN_001a7bca(uVar21,0x128);
        *puVar36 = uVar21;
        piVar42 = puVar36 + 1;
        FUN_000eb992(piVar42,*(undefined4 *)(param_1 + 8));
        puVar36[0x2f] = local_20[0];
        local_2c = piVar42;
        FUN_000edc32(param_1,puVar35,piVar42);
        FUN_000ea91c(puVar35,local_2c);
        local_28 = local_2c;
        puVar43[0x4b] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x68);
        bVar7 = false;
        break;
      case 0x37:
        local_30 = (int *)((int)local_30 + 1);
        uVar21 = *(undefined4 *)(iStack_1fc + (int)local_30 * 4);
        if (*(char *)(param_1 + 0x470) != '\0') {
          uVar21 = 0x75;
        }
        piStack_1f8 = (int *)((int (*)())FUN_0010a17a)(uVar21,*(undefined4 *)(param_1 + 8));
        bVar7 = false;
        break;
      case 0x38:
        uStack_2e2 = 1;
        bVar7 = false;
        break;
      case 0x3a:
        *(undefined1 *)(piStack_1f8 + 0x48) = 1;
        bVar7 = false;
        goto code_r0x00102559;
      case 0x3d:
        ((int (*)())FUN_00109c0e)(piStack_1f8 + iStack_1f0 * 6 + 0x23,1,
                     *(byte *)(piStack_1f8 + iStack_1f0 * 6 + 0x28) & 1 ^ 1);
        bVar7 = false;
        break;
      case 0x42:
        local_30 = (int *)((int)local_30 + 1);
        uVar21 = *(undefined4 *)(iStack_1fc + (int)local_30 * 4);
        FUN_000fa0d2(piStack_1f8,param_1,iStack_1f0,uVar21,uVar21,uVar21,uVar21);
        goto code_r0x00102c5b;
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
      case 0x48:
      case 0x49:
        puVar41 = (PTR_s_ENDIF_001ef070)[(*(ushort *)(param_2 + 0x8e) & 0x3fff) + iVar48 * 4];
code_r0x00102ce2:
        iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,local_2c,puVar41,puVar24);
        goto code_r0x00102d09;
      case 0x4a:
        puVar41 = (PTR_DAT_001ef500)[*(byte *)(param_2 + 0x8e) & 3];
        goto code_r0x001047eb;
      case 0x4b:
        puVar41 = PTR_DAT_00213491;
        if (((*(byte *)(param_2 + 0x8e) & 1) != 0) &&
           ((*(byte *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) & 0x40) == 0)) {
          puVar41 = PTR_DAT_00213495;
        }
code_r0x001047eb:
        iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,local_2c,puVar41,puVar24);
code_r0x00102d09:
        bVar7 = false;
        break;
      case 0x4d:
        *(ushort *)(piStack_1f8[0x4f] + 0x12) = *(byte *)(param_2 + 0x8f) & 1;
        bVar7 = false;
        break;
      case 0x4e:
        uVar21 = 0;
        goto code_r0x00104430;
      case 0x4f:
        local_30 = (int *)((int)local_30 + 1);
        ((int (*)())FUN_0010a58c)(piStack_1f8,*(undefined4 *)(iStack_1fc + (int)local_30 * 4));
        bVar7 = false;
        break;
      case 0x50:
        local_30 = (int *)((int)local_30 + 1);
        ((int (*)())FUN_0010a5c2)(piStack_1f8,*(undefined4 *)(iStack_1fc + (int)local_30 * 4));
        bVar7 = false;
        break;
      case 0x51:
        bVar13 = *(byte *)(param_2 + 0x8e);
        uVar46 = (uint)bVar13;
        if (((uint)puVar19[(bVar13 >> 5) + 3] >> (bVar13 & 0x1f) & 1) == 0) {
          FUN_000e1c3e(*(undefined4 *)(param_1 + 8),"TextureStage %d misses DCLPT\n",uVar46);
        }
        uVar47 = *(uint *)(param_1 + 0x7c);
        if ((int)*(uint *)(param_1 + 0x7c) < (int)uVar46) {
          uVar47 = uVar46;
        }
        *(uint *)(param_1 + 0x7c) = uVar47;
        *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1 << (bVar13 & 0x1f);
        piStack_1f8[0x4d] = uVar46;
        piStack_1f8[0x4c] = uVar46;
        iVar48 = FUN_000fb24a(*(undefined4 *)(*(int *)(param_1 + 0x78) + uVar46 * 0xc));
        piStack_1f8[0x4e] = iVar48;
        bVar7 = false;
        break;
      case 0x52:
        piStack_1f8[0x4d] = (uint)*(byte *)(param_2 + 0x8e);
        piStack_1f8[0x4c] = (uint)*(byte *)(param_2 + 0x8e);
        bVar7 = false;
        break;
      case 0x53:
        uVar21 = 1;
code_r0x00104430:
        puVar41 = (undefined *)
                  FUN_000fb4ec(*(byte *)(param_2 + 0x8e) & 7,*(undefined4 *)(param_1 + 8),uVar21);
        if (puVar41 != (undefined *)0x0) goto code_r0x00102ce2;
        bVar7 = false;
        break;
      case 0x54:
        uVar17 = *(ushort *)(param_2 + 0x8e);
        sVar15 = *(short *)**(undefined4 **)(param_2 + 100);
        bVar13 = *(byte *)((short *)**(undefined4 **)(param_2 + 100) + 1) & 0x3f;
        FUN_000edadc(param_1,bVar13);
        uVar21 = FUN_000edadc(param_1,bVar13);
        iVar48 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),uVar21,(int)sVar15,0);
        if ((uVar17 & 0x3fff) == 0) goto code_r0x00102bcc;
        *(undefined1 *)(iVar48 + 0x30) = 1;
        bVar7 = false;
        break;
      case 0x55:
      case 0x56:
      case 0x57:
      case 0x58:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x5c:
      case 0x5d:
        iVar48 = iVar48 + -0x55;
        if (aiStack_c4[iVar48] == 0) {
          iVar27 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar27;
          aiStack_c4[iVar48] = iVar27;
        }
        iVar48 = aiStack_c4[iVar48];
        iVar27 = FUN_0010b0f4(piStack_1f8,iStack_1f0);
        *(int *)(iVar27 + 8) = iVar48;
        *(undefined4 *)(iVar27 + 0xc) = 0;
        if (iStack_1f0 == 0) {
          FUN_000fb546(param_1,puVar1,puStack_358,0,0,piStack_1f8,0);
        }
        else {
          FUN_000fb2d4(param_1,&uStack_a0,0,iStack_1f0,piStack_1f8);
        }
        goto code_r0x00102c5b;
      case 0x60:
        if (puVar32[2] - 1 < (uint)puVar32[2]) {
          puVar43 = (undefined4 *)(puVar32[3] + (puVar32[2] - 1) * 4);
        }
        else {
          puVar43 = (undefined4 *)0x0;
        }
        piVar42 = local_30;
        if (*(char *)*puVar43 != '\0') goto code_r0x00102bcc;
        do {
          while (local_30 = piVar42, *(int *)(iStack_1fc + (int)local_30 * 4) == 0x37) {
            piVar42 = (int *)((int)local_30 + 2);
            local_30 = (int *)((int)local_30 + 1);
            if (*(int *)(iStack_1fc + (int)piVar42 * 4) == 0x26) goto code_r0x001037f3;
          }
          piVar42 = (int *)((int)local_30 + 1);
        } while (*(int *)(iStack_1fc + ((int)local_30 + 1) * 4) != 0x26);
code_r0x001037f3:
        bVar7 = false;
        break;
      case 0x6a:
        FUN_000e27ca(*(undefined4 *)(param_1 + 8),0xf);
        bVar7 = false;
        break;
      case 0x6b:
        cVar12 = FUN_000e1402(*(undefined4 *)(param_1 + 8),4);
        puVar41 = PTR_DAT_002134d1;
        if (cVar12 != '\0') {
          puVar41 = PTR_DAT_002134a9;
        }
        iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,local_2c,puVar41,puVar24);
        goto code_r0x00102d09;
      case 0x6c:
        (**(code **)(*piStack_1f8 + 0x24))(piStack_1f8);
        *(undefined1 *)(piStack_1f8 + 0x4b) = 1;
        bVar7 = false;
        goto code_r0x00102559;
      case 0x6d:
        iVar48 = FUN_0010b0f4(piStack_1f8,1);
        puVar41 = *(undefined **)(iVar48 + 0x10);
        if (puVar41 == DAT_001c66c0) goto code_r0x00102bcc;
        iVar48 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar48;
        uVar21 = FUN_0012eb84(*(undefined4 *)(param_1 + 0x3a0),0,iVar48,0);
        iVar28 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
        ((int (*)())FUN_0010a3c2)(iVar28,1,uVar21);
        iVar48 = piStack_1f8[0x26];
        iVar27 = piStack_1f8[0x25];
        iVar53 = FUN_0010b0f4(iVar28,0);
        *(int *)(iVar53 + 8) = iVar27;
        *(int *)(iVar53 + 0xc) = iVar48;
        iVar48 = FUN_0010b0f4(iVar28,1);
        *(undefined **)(iVar48 + 0x10) = puVar41;
        iVar48 = FUN_0010b0f4(piStack_1f8,0);
        *(undefined4 *)(iVar28 + 0x9c) = *(undefined4 *)(iVar48 + 0x10);
        ((int (*)())FUN_0010a3c2)(piStack_1f8,0,uVar21);
        iVar48 = FUN_000f5b3c(puVar41);
        piStack_1f8[0x27] = iVar48;
        iVar48 = FUN_0010b0f4(piStack_1f8,1);
        *(undefined **)(iVar48 + 0x10) = DAT_001c66c0;
        FUN_001a7d0c(local_50,iVar28);
        bVar7 = false;
        break;
      case 0x6e:
        local_30 = (int *)((int)local_30 + 1);
        uVar21 = *(undefined4 *)(iStack_1fc + (int)local_30 * 4);
        FUN_000f9ef4(piStack_1f8,param_1,iStack_1f0,uVar21,uVar21,uVar21,uVar21);
code_r0x00102c5b:
        iStack_1f0 = iStack_1f0 + 1;
        bVar7 = false;
        break;
      case 0x70:
        uVar46 = puVar23[2];
        if (uVar46 - 1 < uVar46) {
          piVar42 = (int *)(puVar23[3] + (uVar46 - 1) * 4);
        }
        else {
          piVar42 = (int *)0x0;
        }
        if (*(int *)(*piVar42 + 4) == 0) {
          if (uVar46 - 1 < (uint)puVar23[2]) {
            puVar43 = (undefined4 *)(puVar23[3] + (uVar46 - 1) * 4);
          }
          else {
            puVar43 = (undefined4 *)0x0;
          }
          uVar21 = *puVar43;
          FUN_001a7f3c(puVar3,uVar46 - 1);
          FUN_001a7aba(*(undefined4 *)(*(int *)(param_1 + 8) + 0xbc),uVar21);
          bVar7 = false;
        }
        else {
          if (uVar46 - 1 < (uint)puVar23[2]) {
            piVar42 = (int *)(puVar23[3] + (uVar46 - 1) * 4);
          }
          else {
            piVar42 = (int *)0x0;
          }
          *(int *)(*piVar42 + 4) = *(int *)(*piVar42 + 4) + -1;
          local_30 = (int *)((int)local_30 + -1);
          iStack_1fc = ((int (*)())FUN_00101182)(param_1,iStack_1fc,&local_30,0,PTR_DAT_002134cd,puVar24);
          bVar7 = false;
        }
        break;
      case 0x71:
        local_30 = (int *)((int)local_30 + 1);
        piStack_1f8[0x50] = *(int *)(iStack_1fc + (int)local_30 * 4);
        bVar7 = false;
      }
      if (piStack_1f8 != (int *)0x0) {
code_r0x00102559:
        iVar48 = (**(code **)(*piStack_1f8 + 0x14))(piStack_1f8);
        if (iVar48 + 1 == iStack_1f0) {
          FUN_000fbaca(param_1,piStack_1f8,local_2c);
          uStack_a0 = DAT_001c66c0;
          piStack_1f8 = (int *)0x0;
          iStack_1f0 = 0;
          puStack_358 = DAT_001c66f4;
        }
      }
      if (bVar7) goto code_r0x00105507;
      local_30 = (int *)((int)local_30 + 1);
    } while( true );
  case 7:
    bVar7 = true;
  }
  iVar26 = FUN_000fb930(param_1,iVar25,*(ushort *)(param_2 + 0x8e) & 0x3fff);
  FUN_000fc3f6(param_1,local_50,**(undefined4 **)(param_2 + 100),puVar1,local_2fc);
  sVar15 = *(short *)**(undefined4 **)(param_2 + 100);
  uVar21 = FUN_000edadc(param_1,*(byte *)((short *)**(undefined4 **)(param_2 + 100) + 1) & 0x3f);
  iVar27 = FUN_0010b0f4(iVar26,0);
  *(int *)(iVar27 + 8) = (int)sVar15;
  *(undefined4 *)(iVar27 + 0xc) = uVar21;
  FUN_000fb546(param_1,puVar1,DAT_001c66f4,**(undefined4 **)(param_2 + 100),0,iVar26,0);
  iVar27 = FUN_000fb1da(iVar25,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 0xc));
  iVar27 = iVar27 + 1;
  if (1 < iVar27) {
    iStack_21c = 1;
    iStack_ec = 0;
    do {
      uStack_a0 = DAT_001c66c0;
      ((int (*)())FUN_000fe286)(param_1,local_68,iVar48,*(undefined4 *)(iStack_ec + *(int *)(param_2 + 0x6c)),
                   puVar1,&local_38,&local_80);
      psVar4 = *(short **)(iStack_ec + *(int *)(param_2 + 0x6c));
      if ((((*(byte *)(psVar4 + 1) & 0x3f) == 0x10) && (*(int *)(param_1 + 8) != 0)) &&
         (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x54) + 8) < '\0')) {
        sVar15 = 0xf;
      }
      else {
        sVar15 = *psVar4;
      }
      uVar21 = FUN_000edadc(param_1,*(byte *)(psVar4 + 1) & 0x3f);
      iVar28 = FUN_0010b0f4(iVar26,iStack_21c);
      *(int *)(iVar28 + 8) = (int)sVar15;
      *(undefined4 *)(iVar28 + 0xc) = uVar21;
      if ((!bVar7) && (cVar12 = FUN_001192da(*(undefined4 *)(param_1 + 8),iVar26), cVar12 != '\0'))
      {
        if (iStack_21c == 1) {
          piVar42 = (int *)&UNK_001c66ec;
        }
        else {
          piVar42 = &DAT_001c66e4;
        }
        uStack_a0 = (undefined *)*piVar42;
      }
      FUN_000fb2d4(param_1,&uStack_a0,*(undefined4 *)(iStack_ec + *(int *)(param_2 + 0x6c)),
                   iStack_21c,iVar26);
      iStack_21c = iStack_21c + 1;
      iStack_ec = iStack_ec + 4;
    } while (iVar27 != iStack_21c);
  }
  iVar48 = FUN_000f60f4(iVar26);
  if (bVar7) {
    iVar53 = *(int *)(*(int *)(param_1 + 8) + 0xf0) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0xf0) = iVar53;
    uVar21 = *(undefined4 *)(iVar26 + 0x94);
    uVar37 = *(undefined4 *)(iVar26 + 0x98);
    iVar28 = FUN_0010b0f4(iVar26,0);
    *(int *)(iVar28 + 8) = iVar53;
    *(undefined4 *)(iVar28 + 0xc) = 0;
    cVar12 = FUN_001192da(*(undefined4 *)(param_1 + 8),iVar26);
    iVar28 = FUN_0010b0f4(iVar26,0);
    puVar41 = *(undefined **)(iVar28 + 0x10);
    uStack_a0 = puVar41;
    if (1 < iVar48) {
      iStack_f0 = 0;
      do {
        iVar28 = FUN_000f5950(uStack_a0);
        iVar29 = FUN_000fb930(param_1,iVar25,*(ushort *)(param_2 + 0x8e) & 0x3fff);
        if (0 < iVar27) {
          iVar50 = 0;
          do {
            while (FUN_0010b85e(iVar29,iVar50,iVar26,iVar50), cVar12 == '\0') {
              iVar50 = iVar50 + 1;
              if (iVar27 == iVar50) goto code_r0x00101e35;
            }
            iVar30 = FUN_0010b0f4(iVar29,iVar50);
            iVar30 = *(int *)(iVar30 + 0x10);
            uStack_24 = iVar30;
            if (iVar50 == 1) {
              (*(unsigned int *)((unsigned char *)&(uStack_24) + 0)) = (undefined3)iVar30;
              uStack_24 = CONCAT13(*(undefined1 *)((int)local_20 + iVar28 + -4),
                                   (undefined3)uStack_24);
            }
            else if (iVar50 == 2) {
              (*(unsigned int *)((unsigned char *)&(uStack_24) + 1)) = (undefined3)((uint)iVar30 >> 8);
              uStack_24 = CONCAT31((*(unsigned int *)((unsigned char *)&(uStack_24) + 1)),*(undefined1 *)((int)local_20 + iVar28 + -4));
            }
            else if (iVar50 == 3) {
              (*(unsigned char *)((unsigned char *)&(uStack_24) + 3)) = (undefined1)((uint)iVar30 >> 0x18);
              (*(unsigned short *)((unsigned char *)&(uStack_24) + 0)) = (undefined2)iVar30;
              (*(unsigned int *)((unsigned char *)&(uStack_24) + 0)) =
                   CONCAT12(*(undefined1 *)((int)local_20 + iVar28 + -4),(undefined2)uStack_24);
            }
            iVar30 = uStack_24;
            iVar31 = FUN_0010b0f4(iVar29,iVar50);
            *(int *)(iVar31 + 0x10) = iVar30;
            iVar50 = iVar50 + 1;
          } while (iVar27 != iVar50);
        }
code_r0x00101e35:
        *(undefined4 *)(iVar29 + 0x9c) = *(undefined4 *)(PTR_DAT_0021345d + iVar28 * 4);
        *(undefined1 *)((int)&uStack_a0 + iVar28) = 1;
        *(undefined1 *)(iVar29 + 0x120) = *(undefined1 *)(iVar26 + 0x120);
        FUN_001a7cd6(local_68,iVar29);
        iStack_f0 = iStack_f0 + 1;
      } while (iVar48 + -1 != iStack_f0);
    }
    *(undefined **)(iVar26 + 0x9c) = uStack_a0;
    if ((cVar12 != '\0') && (iVar25 = FUN_000f5950(uStack_a0), 1 < iVar27)) {
      iVar48 = 1;
      do {
        iVar28 = FUN_0010b0f4(iVar26,iVar48);
        iVar28 = *(int *)(iVar28 + 0x10);
        uStack_24 = iVar28;
        if (iVar48 == 1) {
          (*(unsigned int *)((unsigned char *)&(uStack_24) + 0)) = (undefined3)iVar28;
          uStack_24 = CONCAT13(*(undefined1 *)((int)local_20 + iVar25 + -4),(undefined3)uStack_24);
        }
        else if (iVar48 == 2) {
          (*(unsigned int *)((unsigned char *)&(uStack_24) + 1)) = (undefined3)((uint)iVar28 >> 8);
          uStack_24 = CONCAT31((*(unsigned int *)((unsigned char *)&(uStack_24) + 1)),*(undefined1 *)((int)local_20 + iVar25 + -4));
        }
        else if (iVar48 == 3) {
          (*(unsigned char *)((unsigned char *)&(uStack_24) + 3)) = (undefined1)((uint)iVar28 >> 0x18);
          (*(unsigned short *)((unsigned char *)&(uStack_24) + 0)) = (undefined2)iVar28;
          (*(unsigned int *)((unsigned char *)&(uStack_24) + 0)) =
               CONCAT12(*(undefined1 *)((int)local_20 + iVar25 + -4),(undefined2)uStack_24);
        }
        iVar28 = uStack_24;
        iVar29 = FUN_0010b0f4(iVar26,iVar48);
        *(int *)(iVar29 + 0x10) = iVar28;
        iVar48 = iVar48 + 1;
      } while (iVar27 != iVar48);
    }
    iVar25 = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
    iVar48 = FUN_0010b0f4(iVar25,0);
    *(undefined4 *)(iVar48 + 8) = uVar21;
    *(undefined4 *)(iVar48 + 0xc) = uVar37;
    *(undefined **)(iVar25 + 0x9c) = puVar41;
    iVar48 = FUN_0010b0f4(iVar25,1);
    *(int *)(iVar48 + 8) = iVar53;
    *(undefined4 *)(iVar48 + 0xc) = 0;
    FUN_001a7d0c(local_50,iVar25);
  }
  piVar42 = *(int **)(*(int *)(param_1 + 8) + 0x54);
  cVar12 = (**(code **)(*piVar42 + 0x34))(piVar42,iVar26);
  if (cVar12 == '\0') {
code_r0x00101f6a:
    iStack_22c = 0;
  }
  else {
    iVar25 = FUN_0010b0f4(iVar26,0);
    uStack_24 = *(int *)(iVar25 + 0x10);
    aiStack_c4[0] = *(int *)(iVar25 + 0x10);
    iVar27 = 0;
    iVar48 = 0;
    iVar25 = -1;
    do {
      iVar28 = iVar25;
      if (*(char *)((int)local_20 + iVar48 + -4) == '\0') {
        iVar28 = iVar48;
        if ((iVar27 != 0) && (iVar28 = iVar25, 0 < iVar27)) {
          *(undefined1 *)((int)aiStack_c4 + iVar48) = 1;
        }
        iVar27 = iVar27 + 1;
      }
      iVar48 = iVar48 + 1;
      iVar25 = iVar28;
    } while (iVar48 != 4);
    if (iVar27 < 2) goto code_r0x00101f6a;
    *(int *)(iVar26 + 0x9c) = aiStack_c4[0];
    iVar25 = 1;
    do {
      (&bStack_a1)[iVar25] = SUB41(iVar28,0);
      iVar25 = iVar25 + 1;
    } while (iVar25 != 5);
    iStack_22c = ((int (*)())FUN_0010a17a)(0x31,*(undefined4 *)(param_1 + 8));
    uVar21 = *(undefined4 *)(iVar26 + 0x98);
    uVar37 = *(undefined4 *)(iVar26 + 0x94);
    iVar25 = FUN_0010b0f4(iStack_22c,0);
    *(undefined4 *)(iVar25 + 8) = uVar37;
    *(undefined4 *)(iVar25 + 0xc) = uVar21;
    *(int *)(iStack_22c + 0x9c) = uStack_24;
    uVar21 = *(undefined4 *)(iVar26 + 0x98);
    uVar37 = *(undefined4 *)(iVar26 + 0x94);
    iVar25 = FUN_0010b0f4(iStack_22c,1);
    puVar41 = uStack_a0;
    *(undefined4 *)(iVar25 + 8) = uVar37;
    *(undefined4 *)(iVar25 + 0xc) = uVar21;
    iVar25 = FUN_0010b0f4(iStack_22c,1);
    *(undefined **)(iVar25 + 0x10) = puVar41;
  }
  iVar48 = *(int *)(iStack_60 + 8);
  iVar25 = iStack_60;
  while (iVar27 = iVar48, iVar27 != 0) {
    FUN_001a7d72(iVar25);
    FUN_000fbaca(param_1,iVar25,local_2c);
    iVar25 = iVar27;
    iVar48 = *(int *)(iVar27 + 8);
  }
  FUN_000fbaca(param_1,iVar26,local_2c);
  if (iStack_22c != 0) {
    FUN_000fbaca(param_1,iStack_22c,local_2c);
  }
  iVar48 = *(int *)(iStack_48 + 8);
  iVar25 = iStack_48;
  while (iVar26 = iVar48, iVar26 != 0) {
    FUN_001a7d72(iVar25);
    FUN_000fbaca(param_1,iVar25,local_2c);
    iVar25 = iVar26;
    iVar48 = *(int *)(iVar26 + 8);
  }
  goto LAB_0010153e;
code_r0x00105507:
  iVar48 = *(int *)(iStack_48 + 8);
  iVar25 = iStack_48;
  while (iVar26 = iVar48, iVar26 != 0) {
    FUN_001a7d72(iVar25);
    FUN_000fbaca(param_1,iVar25,local_2c);
    iVar25 = iVar26;
    iVar48 = *(int *)(iVar26 + 8);
  }
  if (puVar51 != (uint *)0x0) {
    FUN_001a7aba(puVar32[4],puVar32[3]);
    FUN_001a7aba(*puVar32,puVar32);
  }
  if (puVar24 != (undefined4 *)0x0) {
    FUN_001a7aba(puVar33[4],puVar33[3]);
    FUN_001a7aba(*puVar33,puVar33);
  }
  goto LAB_0010153e;
}

/* FUN_00109c0e @ 0x109c0e (27 bytes) */
int FUN_00109c0e(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  if (param_3 != '\0') {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | param_2;
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & ~param_2;
  return;
}

/* FUN_00109c2a @ 0x109c2a (102 bytes) */
int FUN_00109c2a(float param_1,char param_2,byte param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = 1 << (param_2 - 1U & 0x1f);
  fVar3 = (float)iVar1 + FLOAT_001c5bdc / (float)(1 << (param_3 - 1 & 0x1f));
  fVar2 = (float)-iVar1;
  if (param_1 <= fVar3) {
    fVar3 = param_1;
  }
  if (fVar2 <= fVar3) {
    fVar2 = fVar3;
  }
  return (int)(fVar2 * (float)(1 << (param_3 & 0x1f)));
}

/* FUN_00109c90 @ 0x109c90 (7 bytes) */
int FUN_00109c90()
{
  return (longdouble)0;
}

/* FUN_00109c98 @ 0x109c98 (14 bytes) */
int FUN_00109c98(param_1)
  uint param_1;
{
  return param_1 < 2;
}

/* FUN_00109ca6 @ 0x109ca6 (5 bytes) */
int FUN_00109ca6()
{
  return;
}

/* FUN_00109cac @ 0x109cac (40 bytes) */
int FUN_00109cac(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = DAT_001cbe6c;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = DAT_001cbe68;
  return;
}

/* FUN_00109cd4 @ 0x109cd4 (71 bytes) */
int FUN_00109cd4(param_1, param_2, param_3, param_4)
  void *param_1;
  void *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  _memcpy(param_2,param_1,0x164);
  if (param_4 == '\0') {
    iVar1 = *(int *)(param_3 + 0x68);
    *(int *)((int)param_2 + 0x14c) = iVar1;
    *(int *)(param_3 + 0x68) = iVar1 + 1;
  }
  return param_2;
}

/* FUN_00109d1c @ 0x109d1c (43 bytes) */
int FUN_00109d1c(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  uint param_3;
{
  *param_2 = param_3;
  if ((param_3 & 1) != 0) {
    param_2[1] = *(uint *)(param_1 + 0x160);
  }
  if ((*param_2 & 2) != 0) {
    param_2[2] = *(uint *)(param_1 + 0x14c);
  }
  return;
}

/* FUN_00109d48 @ 0x109d48 (61 bytes) */
int FUN_00109d48(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if ((uVar1 & 1) != 0) {
    *(uint *)(param_1 + 0x160) = param_2[1];
    param_2[1] = 0;
    uVar1 = *param_2;
  }
  if ((uVar1 & 2) != 0) {
    *(uint *)(param_1 + 0x14c) = param_2[2];
  }
  param_2[2] = 0;
  *param_2 = 0;
  return;
}

/* FUN_00109d86 @ 0x109d86 (97 bytes) */
int FUN_00109d86(param_1, param_2)
  void *param_1;
  void *param_2;
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  ((int (*)())FUN_00109d1c)(param_1,&local_18,0xffffffff);
  _memcpy(param_1,param_2,0x164);
  ((int (*)())FUN_00109d48)(param_1,&local_18);
  return;
}

/* FUN_00109de8 @ 0x109de8 (61 bytes) */
int FUN_00109de8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  param_2 = param_3 * 0x18 + param_2;
  if ((*(int *)(param_1 + 0x94) == *(int *)(param_2 + 0x94)) &&
     (*(int *)(param_1 + 0x98) == *(int *)(param_2 + 0x98))) {
    return 1;
  }
  return 0;
}

/* FUN_00109e26 @ 0x109e26 (28 bytes) */
int FUN_00109e26(param_1)
  int param_1;
{
  FUN_001a7d72(param_1);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  return;
}

/* FUN_00109e42 @ 0x109e42 (31 bytes) */
int FUN_00109e42(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}

/* FUN_00109e62 @ 0x109e62 (54 bytes) */
int FUN_00109e62(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_00213559 + param_1 * 0x10 + 4) & 0x400) == 0) {
    if ((*(uint *)(PTR_PTR_00213559 + param_1 * 0x10 + 4) & 0x800) != 0) {
      param_1 = 0x15;
    }
    return param_1;
  }
  return 0x16;
}

/* FUN_00109e98 @ 0x109e98 (62 bytes) */
int FUN_00109e98(param_1)
  int param_1;
{
  if ((*(uint *)(PTR_PTR_00213559 + param_1 * 0x10 + 4) & 0x400) != 0) {
    return '\x04';
  }
  if ((*(uint *)(PTR_PTR_00213559 + param_1 * 0x10 + 4) & 0x800) == 0) {
    return (param_1 == 7) + '\x01';
  }
  return '\x03';
}

/* FUN_00109ed6 @ 0x109ed6 (125 bytes) */
int FUN_00109ed6(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = (uint)CONCAT12(param_3,param_4);
    return;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(uint *)(param_1 + 300) = (uint)CONCAT12(param_3,param_4);
      return;
    }
  }
  else {
    if (param_2 == 2) {
      *(uint *)(param_1 + 0x134) = (uint)CONCAT12(param_3,param_4);
      return;
    }
    if (param_2 == 3) {
      *(uint *)(param_1 + 0x138) = (uint)CONCAT12(param_3,param_4);
      return;
    }
  }
  return;
}

/* FUN_00109f54 @ 0x109f54 (79 bytes) */
int FUN_00109f54(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x130);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 300);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x134);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x138);
    }
  }
  return 0;
}

/* FUN_00109fa4 @ 0x109fa4 (148 bytes) */
int FUN_00109fa4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x130) = param_3 << 0x18 | (uint)param_4 << 0x10 | (uint)param_5;
    return;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(uint *)(param_1 + 300) = param_3 << 0x18 | (uint)param_4 << 0x10 | (uint)param_5;
      return;
    }
  }
  else {
    if (param_2 == 2) {
      *(uint *)(param_1 + 0x134) = param_3 << 0x18 | (uint)param_4 << 0x10 | (uint)param_5;
      return;
    }
    if (param_2 == 3) {
      *(uint *)(param_1 + 0x138) = param_3 << 0x18 | (uint)param_4 << 0x10 | (uint)param_5;
      return;
    }
  }
  return;
}

/* FUN_0010a038 @ 0x10a038 (79 bytes) */
int FUN_0010a038(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined2 *)(param_1 + 0x130);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined2 *)(param_1 + 300);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined2 *)(param_1 + 0x134);
    }
    if (param_2 == 3) {
      return *(undefined2 *)(param_1 + 0x138);
    }
  }
  return 0;
}

/* FUN_0010a088 @ 0x10a088 (73 bytes) */
int FUN_0010a088(param_1, param_2)
  int *param_1;
  int param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_1 + param_2 + 0x9c;
  iVar4 = 1;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < iVar4) {
      return -1;
    }
    pcVar1 = (char *)(iVar3 + 0x18);
    iVar3 = iVar3 + 0x18;
    if (*pcVar1 != '\x04') break;
    iVar4 = iVar4 + 1;
  }
  return iVar4;
}

/* FUN_0010a0d2 @ 0x10a0d2 (55 bytes) */
int FUN_0010a0d2(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0x1f;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0x9c) = DAT_001cbe6c;
  return;
}

/* FUN_0010a10a @ 0x10a10a (32 bytes) */
int FUN_0010a10a(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 4;
  return;
}

/* FUN_0010a12a @ 0x10a12a (35 bytes) */
int FUN_0010a12a(param_1, param_2)
  int param_1;
  int param_2;
{
  if (((*(byte *)(param_2 + 0x31) & 0x40) != 0) && (*(int *)(param_1 + 0x98) == 0x24)) {
    return 1;
  }
  return 0;
}

/* FUN_0010a14e @ 0x10a14e (43 bytes) */
int FUN_0010a14e()
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((DAT_001fcbe4)[iVar1 * 2] != iVar1) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x15);
  return 1;
}

/* FUN_0010a17a @ 0x10a17a (72 bytes) */
int FUN_0010a17a(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00119244(param_1,param_2);
  iVar1 = (**(code **)(&DAT_001fcbe0 + iVar1 * 8))(param_1,param_2);
  uVar2 = FUN_00118f66(param_1);
  *(undefined4 *)(iVar1 + 0x88) = uVar2;
  return iVar1;
}

/* FUN_0010a1c2 @ 0x10a1c2 (131 bytes) */
int FUN_0010a1c2(param_1, param_2, param_3)
  void *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_001a7bca(*(undefined4 *)(param_2 + 0xb8),0x168);
  *puVar2 = *(undefined4 *)(param_2 + 0xb8);
  _memcpy(puVar2 + 1,param_1,0x164);
  if (param_3 == '\0') {
    iVar1 = *(int *)(param_2 + 0x68);
    puVar2[0x54] = iVar1;
    *(int *)(param_2 + 0x68) = iVar1 + 1;
  }
  puVar2[3] = 0;
  puVar2[2] = 0;
  puVar2[0x57] = 0;
  return puVar2 + 1;
}

/* FUN_0010a246 @ 0x10a246 (52 bytes) */
int FUN_0010a246(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  FUN_001a7aba(*(undefined4 *)(param_3 + 0xb8),*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = param_2;
  return;
}

/* FUN_0010a27a @ 0x10a27a (45 bytes) */
int FUN_0010a27a(param_1, param_2)
  int *param_1;
  int param_2;
{
  (**(code **)(*param_1 + 0xc))
            (param_1,*(uint *)(*(int *)(param_2 + 0x3f4) + 0x30) >> 7 & 1,param_2);
  return;
}

/* FUN_0010a2a8 @ 0x10a2a8 (119 bytes) */
int FUN_0010a2a8(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  
  if (*(int *)(param_1 + 0x98) != 0x33) {
    return 0;
  }
  pbVar3 = &STACKARG(0xc);
  do {
    bVar1 = *pbVar3;
    if (bVar1 != 4) {
      if (((int)*(char *)(param_1 + 0x15c) >> (bVar1 & 0x1f) & 1U) == 0) {
        return 0;
      }
      cVar2 = (**(code **)(**(int **)(param_2 + 0x54) + 0xf0))
                        (*(int **)(param_2 + 0x54),
                         *(undefined4 *)(param_1 + 0x20 + (uint)bVar1 * 0x18));
      if (cVar2 == '\0') {
        return 0;
      }
    }
    pbVar3 = pbVar3 + 1;
    if (pbVar3 == &STACKARG(0x10)) {
      return 1;
    }
  } while( true );
}

/* FUN_0010a320 @ 0x10a320 (57 bytes) */
int FUN_0010a320(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  if ((cVar1 != '\0') && ((param_1[0x26] == 0x26 || (param_1[0x26] == 0x3a)))) {
    return 1;
  }
  return 0;
}

/* FUN_0010a35a @ 0x10a35a (50 bytes) */
int FUN_0010a35a(param_1)
  int *param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  if ((cVar1 != '\0') && (param_1[0x26] == 0x44)) {
    return 1;
  }
  return 0;
}

/* FUN_0010a38c @ 0x10a38c (53 bytes) */
int FUN_0010a38c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  *(undefined4 *)(param_1 + 0x94) = param_4;
  *(undefined4 *)(param_1 + 0x98) = param_3;
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x42;
  *(undefined4 *)(param_1 + 0x80) = 0;
  FUN_000f0b74();
  return;
}

/* FUN_0010a3c2 @ 0x10a3c2 (72 bytes) */
int FUN_0010a3c2(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 + param_2 * 0x18;
  *(int *)(iVar1 + 0x98) = param_3[1];
  *(int *)(iVar1 + 0x94) = param_3[2];
  *(int **)(iVar1 + 0x8c) = param_3;
  if (param_2 == 0) {
    uVar2 = (**(code **)(*param_3 + 0x24))(param_3);
    *(undefined4 *)(param_1 + 0x128) = uVar2;
  }
  return;
}

/* FUN_0010a40a @ 0x10a40a (106 bytes) */
int FUN_0010a40a(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  ((int (*)())FUN_00109c0e)(param_1,1,*(byte *)(param_2 + 5) & 1);
  ((int (*)())FUN_00109c0e)(param_1,2,(uint)param_2[5] >> 1 & 1);
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  return;
}

/* FUN_0010a474 @ 0x10a474 (84 bytes) */
int FUN_0010a474(param_1, param_2)
  int param_1;
  int param_2;
{
  ((int (*)())FUN_00109c0e)(param_1,1,*(byte *)(param_2 + 0x14) & 1);
  ((int (*)())FUN_00109c0e)(param_1,2,*(uint *)(param_2 + 0x14) >> 1 & 1);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
  return;
}

/* FUN_0010a4c8 @ 0x10a4c8 (91 bytes) */
int FUN_0010a4c8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar2;
  
  if (*(int *)(param_1 + 0x158) != *(int *)(param_2 + 0x158)) {
    uVar2 = FUN_000e96e8(*(int *)(param_1 + 0x158),*(int *)(param_2 + 0x158));
    return uVar2;
  }
  if (param_1 != param_2) {
    iVar1 = *(int *)(param_2 + 4);
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      if (param_1 == iVar1) break;
      iVar1 = *(int *)(iVar1 + 4);
    }
  }
  return 1;
}

/* FUN_0010a524 @ 0x10a524 (104 bytes) */
int FUN_0010a524(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  cVar1 = ((int (*)())FUN_0010a4c8)(param_1,param_2);
  if (cVar1 != '\0') {
    return param_1;
  }
  cVar1 = ((int (*)())FUN_0010a4c8)(param_2,param_1);
  if (cVar1 != '\0') {
    return param_2;
  }
  FUN_000e9710(*(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_2 + 0x158));
  iVar2 = FUN_000e9984();
  return iVar2;
}

/* FUN_0010a58c @ 0x10a58c (53 bytes) */
int FUN_0010a58c(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  uVar2 = ((int (*)())FUN_00109c2a)(param_2,3,4);
  *(undefined2 *)(iVar1 + 0x18) = uVar2;
  return;
}

/* FUN_0010a5c2 @ 0x10a5c2 (53 bytes) */
int FUN_0010a5c2(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  uVar2 = ((int (*)())FUN_00109c2a)(param_2,3,4);
  *(undefined2 *)(iVar1 + 0x18) = uVar2;
  return;
}

/* FUN_0010a5f8 @ 0x10a5f8 (53 bytes) */
int FUN_0010a5f8(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x13c);
  uVar2 = ((int (*)())FUN_00109c2a)(param_2,3,4);
  *(undefined2 *)(iVar1 + 0x18) = uVar2;
  return;
}

/* FUN_0010a62e @ 0x10a62e (40 bytes) */
int FUN_0010a62e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 1;
}

/* FUN_0010a656 @ 0x10a656 (40 bytes) */
int FUN_0010a656(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 2;
}

/* FUN_0010a67e @ 0x10a67e (39 bytes) */
int FUN_0010a67e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x160) - *(int *)(param_2 + 0x46c);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1 == 0;
}

/* FUN_0010a6a6 @ 0x10a6a6 (136 bytes) */
int FUN_0010a6a6(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[0x21];
  ((int (*)())FUN_0010a3c2)(param_1,iVar1 + 1,param_2);
  iVar2 = param_1[0x21];
  param_1[0x21] = iVar2 + 1;
  if ((0 < param_1[0x20]) && (param_2 == param_1[0x23])) {
    iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar3 < iVar2 + 1) {
      param_1[5] = param_1[5] | 0x200;
      param_1[(iVar1 + 1) * 6 + 0x27] = DAT_001cbe68;
      return;
    }
  }
  return;
}

/* FUN_0010a72e @ 0x10a72e (79 bytes) */
int FUN_0010a72e(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x133);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12f);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x137);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x13b);
    }
  }
  return 0;
}

/* FUN_0010a77e @ 0x10a77e (72 bytes) */
int FUN_0010a77e(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar2 = 0;
  do {
    iVar1 = ((int (*)())FUN_0010a72e)(param_1,iVar2);
    if (iVar1 == 1) {
      *(undefined1 *)((int)&local_10 + iVar2) = 5;
    }
    else if (iVar1 == 2) {
      *(undefined1 *)((int)&local_10 + iVar2) = 6;
    }
    else {
      *(undefined1 *)((int)&local_10 + iVar2) = 4;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  return local_10;
}

/* FUN_0010a7c6 @ 0x10a7c6 (79 bytes) */
int FUN_0010a7c6(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_0010a816 @ 0x10a816 (39 bytes) */
int FUN_0010a816(param_1)
  undefined4 *param_1;
{
  param_1[5] = param_1[5] & 0xfffffffc;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[3] = 0x46;
  return;
}

/* FUN_0010a83e @ 0x10a83e (31 bytes) */
int FUN_0010a83e()
{
  ((int (*)())FUN_0010a816)();
  return;
}

/* FUN_0010a85e @ 0x10a85e (289 bytes) */
int FUN_0010a85e(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int local_24;
  
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  ((int (*)())FUN_0010a83e)(param_1,0);
  *(undefined4 *)(param_1 + 0x9c) = DAT_001cbe6c;
  uVar1 = DAT_001cbe68;
  *(undefined4 *)(param_1 + 0x154) = DAT_001cbe68;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_24 = 1;
  iVar5 = param_1;
  do {
    ((int (*)())FUN_0010a83e)(param_1,local_24);
    *(undefined4 *)(iVar5 + 0xb4) = uVar1;
    cVar2 = FUN_001192da(param_2,param_1);
    if (cVar2 != '\0') {
      if (local_24 == 1) {
        puVar3 = &DAT_001cbe7c;
      }
      else {
        puVar3 = &DAT_001cbe78;
      }
      *(undefined4 *)(iVar5 + 0xb4) = *puVar3;
    }
    local_24 = local_24 + 1;
    iVar5 = iVar5 + 0x18;
  } while (local_24 != 5);
  *(undefined1 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  iVar4 = 0;
  iVar5 = param_1;
  do {
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    *(undefined4 *)(iVar5 + 0x20) = 0;
    *(byte *)(param_1 + 0x15c) = *(byte *)(param_1 + 0x15c) & ~(byte)(1 << ((byte)iVar4 & 0x1f));
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x18;
  } while (iVar4 != 4);
  puVar3 = (undefined4 *)(param_1 + 300);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  return;
}

/* FUN_0010a980 @ 0x10a980 (49 bytes) */
int FUN_0010a980(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x90 + *(int *)(param_1 + 0x84) * 0x18);
  *(undefined4 *)(param_2 + 0x10) =
       *(undefined4 *)(param_1 + 0x9c + *(int *)(param_1 + 0x84) * 0x18);
  return;
}

/* FUN_0010a9b2 @ 0x10a9b2 (143 bytes) */
int FUN_0010a9b2(param_1, param_2)
  int *param_1;
  char *param_2;
{
  int iVar1;
  int iVar2;
  int local_14;
  char *local_10;
  
  local_10 = param_2;
  local_14 = 0;
  do {
    while (*local_10 != '\0') {
      *(undefined1 *)(local_14 + 0x9c + (int)param_1) = 0;
      local_14 = local_14 + 1;
      local_10 = local_10 + 1;
      if (local_14 == 4) {
        return;
      }
    }
    *(undefined1 *)(local_14 + 0x9c + (int)param_1) = 1;
    for (iVar2 = 1; iVar1 = (**(code **)(*param_1 + 0x14))(param_1), iVar2 <= iVar1;
        iVar2 = iVar2 + 1) {
      (**(code **)(*param_1 + 0x88))(param_1,iVar2,local_14,4);
    }
    local_14 = local_14 + 1;
    local_10 = local_10 + 1;
  } while (local_14 != 4);
  return;
}

/* FUN_0010aa42 @ 0x10aa42 (174 bytes) */
int FUN_0010aa42(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x98) == 0xc) {
    FUN_000f70c0(*(undefined4 *)(*(int *)(param_3 + 0x3f4) + 0x3a0),param_1);
  }
  if ((*(int *)(param_1 + 0x98) == 2) || (*(int *)(param_1 + 0x98) == 0x33)) {
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(*(int *)(param_3 + 0x3f4) + 0x394);
  if (param_1 == *(int *)(iVar2 + 0x124)) {
    *(int *)(iVar2 + 0x124) = iVar1;
  }
  if ((((*(uint *)(param_1 + 0x14) & 4) == 0) && (iVar1 != 0)) &&
     ((*(uint *)(iVar1 + 0x14) & 4) != 0)) {
    *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffffffb;
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
    FUN_001a7d72();
    return;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  FUN_001a7d72();
  return;
}

/* FUN_0010aaf0 @ 0x10aaf0 (79 bytes) */
int FUN_0010aaf0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 1) {
    return *(undefined1 *)(param_1 + 0x132);
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      return *(undefined1 *)(param_1 + 0x12e);
    }
  }
  else {
    if (param_2 == 2) {
      return *(undefined1 *)(param_1 + 0x136);
    }
    if (param_2 == 3) {
      return *(undefined1 *)(param_1 + 0x13a);
    }
  }
  return 0;
}

/* FUN_0010ab40 @ 0x10ab40 (149 bytes) */
int FUN_0010ab40(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x2b) {
      uVar1 = FUN_00118f66(0xa6);
      *(undefined4 *)(param_1 + 0x88) = uVar1;
    }
    else if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 99) {
      uVar1 = FUN_00118f66(100);
      *(undefined4 *)(param_1 + 0x88) = uVar1;
      return;
    }
  }
  else if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0xa6) {
    uVar1 = FUN_00118f66(0x2b);
    *(undefined4 *)(param_1 + 0x88) = uVar1;
  }
  else if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 100) {
    uVar1 = FUN_00118f66(99);
    *(undefined4 *)(param_1 + 0x88) = uVar1;
    return;
  }
  return;
}

