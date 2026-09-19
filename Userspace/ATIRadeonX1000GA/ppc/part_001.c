#include "decls.h"

/* __AllocateSurface @ 0x2750 (1420 bytes) */
longlong __AllocateSurface(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  size_t sVar9;
  int iVar10;
  ulonglong uVar11;
  uint uVar12;
  size_t sVar13;
  void *pvVar14;
  void *pvVar15;
  uint uVar16;
  ushort uVar18;
  int *piVar17;
  uint local_78;
  undefined4 local_74;
  uint local_70;
  int *local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined4 *puVar4;
  
  puVar4 = _calloc(1,0x3c);
  lVar2 = (longlong)(int)puVar4;
  if ((param_2 & 1) == 0) {
    if ((param_2 & 8) == 0) {
      iVar5 = __DecodePixelFormat(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,&local_70,
                                  lVar2 + 0x2c,0,lVar2 + 0x38);
      if (iVar5 == 0) goto LAB_00002cb0;
      uVar1 = param_3[6];
      uVar16 = puVar4[10];
      iVar8 = 1;
      *(undefined2 *)((int)puVar4 + 0xe) = 0;
      *(undefined2 *)(puVar4 + 3) = 0;
      puVar4[7] = uVar1 / uVar16;
      uVar1 = param_3[4];
      *(short *)(puVar4 + 4) = (short)uVar1;
      uVar12 = param_3[5];
      puVar4[5] = uVar1;
      *(short *)((int)puVar4 + 0x12) = (short)uVar12;
      puVar4[6] = uVar12;
      uVar7 = (longlong)(int)uVar16 * (longlong)(int)(uVar1 * uVar12) + 3U & 0xfffffffc;
      uVar6 = uVar7 >> 2;
      iVar5 = (int)uVar6;
      local_60 = (int)uVar7 + 0xfffU & 0xfffff000;
      while (0x3fff < uVar6) {
        uVar6 = uVar6 >> 1;
        iVar5 = (int)uVar6;
        iVar8 = iVar8 << 1;
      }
      local_74 = 2;
      local_64 = ((iVar5 + 0xd) * iVar8 + 0x27U & 0x3ffffff8) << 2;
      lVar3 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),9,&local_64,2,&local_6c,&local_74);
      if (lVar3 == 0) {
        *puVar4 = local_68;
        uVar1 = param_3[4];
        uVar12 = param_3[5];
        uVar7 = (ulonglong)uVar12;
        pvVar14 = (void *)*param_3;
        sVar13 = uVar16 * uVar1;
        uVar6 = ((longlong)(int)uVar16 * (longlong)(int)(uVar1 * uVar12) & 0xffffffffU) >> 2;
        if (uVar6 < 0x4000) {
          iVar5 = 1;
        }
        else {
          iVar5 = 1;
          uVar11 = uVar7;
          do {
            uVar6 = uVar6 >> 1;
            uVar7 = uVar7 >> 1;
            uVar11 = uVar11 >> 1;
            uVar12 = (uint)uVar11;
            iVar5 = iVar5 << 1;
          } while (0x3fff < uVar6);
        }
        iVar8 = (int)uVar6 + 0xd;
        sVar9 = 0x20;
        if (0x1f < sVar13) {
          sVar9 = sVar13;
        }
        *local_6c = iVar8 * iVar5 + 8;
        local_6c[6] = iVar8;
        local_6c[7] = iVar5;
        local_6c[5] = sVar9 * (int)uVar7;
        local_6c[0x20] = 0x1393;
        local_6c[0x21] = 10;
        local_6c[0x22] = 0x5c8;
        piVar17 = local_6c + 0x24;
        local_6c[0x23] = 0x20000;
        iVar8 = 3;
        if (local_70 != 3) {
          iVar8 = 0;
        }
        if (iVar5 != 0) {
          iVar10 = 0;
          do {
            *piVar17 = 0x5cb;
            piVar17[1] = iVar8;
            piVar17[2] = 0x51b;
            piVar17[3] = (local_70 & 0xf) << 8 | 0x53cc30f2;
            piVar17[4] = 0x10501;
            piVar17[5] = 0;
            piVar17[6] = sVar9;
            piVar17[7] = 0x5c0;
            piVar17[8] = 0;
            piVar17[9] = 0x1050e;
            piVar17[10] = 0;
            piVar17[0xb] = uVar1 | (uint)(uVar7 << 0x10);
            piVar17[0xc] = (uint)((uVar6 - 1 & 0xffffffff) << 0x10) | 0x85f0;
            piVar17 = piVar17 + 0xd;
            if (uVar12 != 0) {
              uVar16 = 0;
              pvVar15 = pvVar14;
              do {
                uVar16 = uVar16 + 1;
                pvVar14 = (void *)((int)pvVar15 + sVar13);
                _bcopy(pvVar15,piVar17,sVar13);
                piVar17 = (int *)((int)piVar17 + (sVar13 & 0xfffffffc));
                pvVar15 = pvVar14;
              } while (uVar16 != uVar12);
            }
            iVar10 = iVar10 + 1;
          } while (iVar5 != iVar10);
        }
        *piVar17 = 0xd0b;
        piVar17[1] = 5;
        piVar17[2] = 0x5c8;
        piVar17[3] = 0x10000;
        lVar3 = 0;
        goto LAB_00002ce0;
      }
    }
    else {
      uVar18 = (ushort)param_3[6] & 0x3f;
      if (((param_3[6] & 0x3f) == 0) &&
         (iVar5 = __DecodePixelFormat(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,0,
                                      lVar2 + 0x2c,0,lVar2 + 0x38), iVar5 != 0)) {
        uVar1 = param_3[6];
        *(ushort *)((int)puVar4 + 0xe) = uVar18;
        *(ushort *)(puVar4 + 3) = uVar18;
        puVar4[7] = uVar1 / (uint)puVar4[10];
        uVar16 = param_3[4];
        *(short *)(puVar4 + 4) = (short)uVar16;
        local_5c = param_3[5];
        puVar4[5] = uVar16;
        *(short *)((int)puVar4 + 0x12) = (short)local_5c;
        puVar4[6] = local_5c;
        local_74 = 1;
        local_5c = local_5c * uVar1;
        local_60 = *param_3;
        local_64 = param_2;
        lVar3 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),8,&local_64,3,lVar2,&local_74);
        if (lVar3 == 0) goto LAB_00002ce0;
      }
      else {
LAB_00002cb0:
        lVar3 = -0x1ffffd39;
      }
    }
  }
  else {
    puVar4[2] = param_4;
    param_3[10] = (uint)puVar4;
    lVar3 = __SetDestination(param_1,1,param_3);
    if (lVar3 == 0) {
      if ((param_2 & 2) != 0) {
        local_60 = param_3[4];
        local_5c = param_3[5];
        local_74 = 0;
        local_64 = param_2;
        lVar3 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),4,&local_64,3,0,&local_74);
        if (lVar3 != 0) goto LAB_00002cb8;
      }
      if (((param_2 & 0x10) != 0) &&
         (iVar5 = __DecodePixelFormat(param_3[1],lVar2 + 0x30,lVar2 + 0x34,lVar2 + 0x28,0,
                                      lVar2 + 0x2c,&local_78,lVar2 + 0x38), iVar5 != 0)) {
        uVar1 = param_3[4] * puVar4[10] + 0x7f & 0xffffff80;
        local_60 = (param_3[5] + 1) * uVar1;
        param_3[6] = uVar1;
        local_64 = local_78;
        local_74 = 2;
        iVar5 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),10,&local_64,2,&local_6c,&local_74);
        if (iVar5 == 0) {
          lVar3 = 0;
          *puVar4 = local_68;
          uVar1 = param_3[6];
          *(undefined2 *)((int)puVar4 + 0xe) = 0;
          *(undefined2 *)(puVar4 + 3) = 0;
          puVar4[7] = uVar1 / (uint)puVar4[10];
          uVar1 = param_3[4];
          *(short *)(puVar4 + 4) = (short)uVar1;
          uVar16 = param_3[5];
          puVar4[5] = uVar1;
          *(short *)((int)puVar4 + 0x12) = (short)uVar16;
          puVar4[6] = uVar16;
          puVar4[1] = local_6c;
          param_3[9] = 2;
          goto LAB_00002ce0;
        }
      }
      lVar3 = 0;
      goto LAB_00002ce0;
    }
  }
LAB_00002cb8:
  _free(puVar4);
  puVar4 = (undefined4 *)0x0;
LAB_00002ce0:
  param_3[10] = (uint)puVar4;
  return lVar3;
}

/* _radeon3DCopySetup @ 0x2d10 (2048 bytes) */
longlong _radeon3DCopySetup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  int param_2;
  int param_3;
  longlong param_4;
  int param_5;
  ulonglong param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(uint *)(param_3 + 0x2c) == 0) {
    uVar5 = (uint)param_4;
    if (uVar5 == 6) {
      uVar3 = 0xfffffffffffffff9;
      uVar5 = 0xc;
    }
    else if (uVar5 == 3) {
      uVar3 = 0xfffffffffffffff8;
      uVar5 = 0xb;
    }
    else {
      uVar5 = uVar5 & 0x1f;
      uVar3 = param_4 - 0x13;
    }
  }
  else {
    uVar3 = (ulonglong)
            (*(uint *)(&DAT_0000e018 + (*(uint *)(param_3 + 0x2c) & 0xff) * 0x1c) >> 0x13) & 0x1f;
    uVar5 = (uint)uVar3;
    uVar3 = uVar3 - 0x13;
  }
  *(undefined4 *)(param_2 + (int)((param_6 & 0xffffffff) << 2)) = 0x10ea;
  *(undefined4 *)(param_2 + (int)((param_6 + 1 & 0xffffffff) << 2)) = 0x2da49525;
  *(undefined4 *)(param_2 + (int)((param_6 + 2 & 0xffffffff) << 2)) = 0x10fa;
  *(undefined4 *)(param_2 + (int)((param_6 + 3 & 0xffffffff) << 2)) = 0xffffff;
  *(undefined4 *)(param_2 + (int)((param_6 + 4 & 0xffffffff) << 2)) = 0x1004;
  *(undefined4 *)(param_2 + (int)((param_6 + 5 & 0xffffffff) << 2)) = 0x66666666;
  *(undefined4 *)(param_2 + (int)((param_6 + 6 & 0xffffffff) << 2)) = 0x1005;
  *(undefined4 *)(param_2 + (int)((param_6 + 7 & 0xffffffff) << 2)) = 0x6666666;
  *(undefined4 *)(param_2 + (int)((param_6 + 8 & 0xffffffff) << 2)) = 0x13c1;
  *(undefined4 *)(param_2 + (int)((param_6 + 9 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 10 & 0xffffffff) << 2)) = 0x850;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xb & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xc & 0xffffffff) << 2)) = 0x887;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xd & 0xffffffff) << 2)) = 0x1c000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xe & 0xffffffff) << 2)) = 0x82c;
  *(undefined4 *)(param_2 + (int)((param_6 + 0xf & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x10 & 0xffffffff) << 2)) = 0x10ae;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x11 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x12 & 0xffffffff) << 2)) = 0x1002;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x13 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x14 & 0xffffffff) << 2)) = 0x824;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x15 & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x16 & 0xffffffff) << 2)) = 0x825;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x17 & 0xffffffff) << 2)) = 2;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x18 & 0xffffffff) << 2)) = 0x82d;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x19 & 0xffffffff) << 2)) = 3;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1a & 0xffffffff) << 2)) = 0x854;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1b & 0xffffffff) << 2)) = 0x26010006;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1c & 0xffffffff) << 2)) = 0x878;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1d & 0xffffffff) << 2)) = 0xf688f688;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1e & 0xffffffff) << 2)) = 0x13c0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x1f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)((int)((param_6 + 0x20 & 0xffffffff) << 2) + param_2) = 0x13c1;
  *(undefined4 *)((int)((param_6 + 0x21 & 0xffffffff) << 2) + param_2) = 0;
  *(undefined4 *)((int)((param_6 + 0x22 & 0xffffffff) << 2) + param_2) = 0x12f5;
  *(undefined4 *)((int)((param_6 + 0x23 & 0xffffffff) << 2) + param_2) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x24 & 0xffffffff) << 2)) = 0x12f0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x25 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x26 & 0xffffffff) << 2)) = 0x10a2;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x27 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x28 & 0xffffffff) << 2)) = 0x1381;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x29 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2a & 0xffffffff) << 2)) = 0x109e;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2b & 0xffffffff) << 2)) = 5;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2c & 0xffffffff) << 2)) = 0x1041;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2d & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2e & 0xffffffff) << 2)) = 0x1094;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x2f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x30 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x31 & 0xffffffff) << 2)) = 0x7803;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x32 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x33 & 0xffffffff) << 2)) = 0x2400000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x34 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x35 & 0xffffffff) << 2)) = 0xe400e400;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x36 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x37 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x38 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x39 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3a & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3b & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3c & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3d & 0xffffffff) << 2)) = 0x78105;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3e & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x3f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x40 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x41 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x42 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x43 & 0xffffffff) << 2)) = 0xdb0220;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x44 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x45 & 0xffffffff) << 2)) = 0xc0c000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x46 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x47 & 0xffffffff) << 2)) = 0x20490000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x48 & 0xffffffff) << 2)) = 0x1189;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x49 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4a & 0xffffffff) << 2)) = 0x1181;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4b & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4c & 0xffffffff) << 2)) = 0x118d;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4d & 0xffffffff) << 2)) = 0x10000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4e & 0xffffffff) << 2)) = 0x118e;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x4f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x50 & 0xffffffff) << 2)) = 0x118c;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x51 & 0xffffffff) << 2)) = 0x10000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x52 & 0xffffffff) << 2)) = 0x11a9;
  if (2 < uVar3) {
    *(undefined4 *)(param_2 + (int)((param_6 + 0x53 & 0xffffffff) << 2)) = 0x6c01;
  }
  else {
    *(undefined4 *)(param_2 + (int)((param_6 + 0x53 & 0xffffffff) << 2)) = 0x1b01;
  }
  *(undefined4 *)(param_2 + (int)((param_6 + 0x54 & 0xffffffff) << 2)) = 0x11aa;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x55 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x56 & 0xffffffff) << 2)) = 0x11ab;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x57 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x58 & 0xffffffff) << 2)) = 0x11ac;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x59 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5a & 0xffffffff) << 2)) = 0x10c0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5b & 0xffffffff) << 2)) = 0x40002;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5c & 0xffffffff) << 2)) = 0x10c1;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5d & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5e & 0xffffffff) << 2)) = 0x10c8;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x5f & 0xffffffff) << 2)) = 0x10;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x60 & 0xffffffff) << 2)) = 0x101d;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x61 & 0xffffffff) << 2)) = 0x280c2040;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x62 & 0xffffffff) << 2)) = 0x1040;
  *(undefined4 *)(param_2 + (int)((param_6 + 99 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_2 + (int)((param_6 + 100 & 0xffffffff) << 2)) = 0x1100;
  uVar4 = 0x1492;
  if (param_5 == 0) {
    uVar4 = 0xa92;
  }
  *(uint *)(param_2 + (int)((param_6 + 0x65 & 0xffffffff) << 2)) = uVar4 | 0x2000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x66 & 0xffffffff) << 2)) = 0x1120;
  iVar1 = param_7;
  if (param_7 == 0) {
    iVar1 = (int)*(short *)(param_3 + 4);
  }
  iVar2 = param_8;
  if (param_8 == 0) {
    iVar2 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (int)((param_6 + 0x67 & 0xffffffff) << 2)) =
       iVar1 - 1U & 0x7ff | (iVar2 + -1) * 0x800 & 0x3ff800U | 0x80000000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x68 & 0xffffffff) << 2)) = 0x1130;
  if (2 < uVar3) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x400000;
  }
  *(uint *)(param_2 + (int)((param_6 + 0x69 & 0xffffffff) << 2)) = uVar4 | uVar5 | 0x53000;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x6a & 0xffffffff) << 2)) = 0x1140;
  if (param_7 == 0) {
    param_7 = (int)*(short *)(param_3 + 4);
  }
  if (param_8 == 0) {
    param_8 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (int)((param_6 + 0x6b & 0xffffffff) << 2)) =
       (param_8 + -1) * 0x20 & 0x10000U |
       (param_7 + -1) * 0x10 & 0x8000U | *(int *)(param_3 + 0x10) - 1U & 0x3fff;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x6c & 0xffffffff) << 2)) = 0x10f4;
  *(undefined4 *)(param_2 + (int)((param_6 + 0x6d & 0xffffffff) << 2)) = 0xffff;
  return param_6 + 0x6e;
}

/* _radeon3DFillSetup @ 0x3540 (2020 bytes) */
longlong _radeon3DFillSetup(param_1, param_2, param_3, param_4)
  int param_1;
  ulonglong param_2;
  uint param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  *(undefined4 *)(param_1 + (int)((param_2 & 0xffffffff) << 2)) = 0x850;
  *(undefined4 *)(param_1 + (int)((param_2 + 1 & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_1 + (int)((param_2 + 2 & 0xffffffff) << 2)) = 0x887;
  *(undefined4 *)(param_1 + (int)((param_2 + 3 & 0xffffffff) << 2)) = 0x1c000;
  *(undefined4 *)(param_1 + (int)((param_2 + 4 & 0xffffffff) << 2)) = 0x82c;
  *(undefined4 *)(param_1 + (int)((param_2 + 5 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 6 & 0xffffffff) << 2)) = 0x1002;
  *(undefined4 *)(param_1 + (int)((param_2 + 7 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 8 & 0xffffffff) << 2)) = 0x824;
  *(undefined4 *)(param_1 + (int)((param_2 + 9 & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_1 + (int)((param_2 + 10 & 0xffffffff) << 2)) = 0x825;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xb & 0xffffffff) << 2)) = 4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xc & 0xffffffff) << 2)) = 0x82d;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xd & 0xffffffff) << 2)) = 3;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xe & 0xffffffff) << 2)) = 0x854;
  *(undefined4 *)(param_1 + (int)((param_2 + 0xf & 0xffffffff) << 2)) = 0x26000001;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x10 & 0xffffffff) << 2)) = 0x878;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x11 & 0xffffffff) << 2)) = 0xfb24fb08;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x12 & 0xffffffff) << 2)) = 0x10a2;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x13 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x14 & 0xffffffff) << 2)) = 0x1381;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x15 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x16 & 0xffffffff) << 2)) = 0x109e;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x17 & 0xffffffff) << 2)) = 5;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x18 & 0xffffffff) << 2)) = 0x1383;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x19 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1a & 0xffffffff) << 2)) = 0x1004;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1b & 0xffffffff) << 2)) = 0x66666666;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1c & 0xffffffff) << 2)) = 0x1005;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1d & 0xffffffff) << 2)) = 0x66666666;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1e & 0xffffffff) << 2)) = 0x10ae;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x1f & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x20 & 0xffffffff) << 2)) = 0x10ea;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x21 & 0xffffffff) << 2)) = 0x2da49525;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x22 & 0xffffffff) << 2)) = 0x10fa;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x23 & 0xffffffff) << 2)) = 0xffffff;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x24 & 0xffffffff) << 2)) = 0x10f4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x25 & 0xffffffff) << 2)) = 0xffff;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x26 & 0xffffffff) << 2)) = 0x10f8;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x27 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x28 & 0xffffffff) << 2)) = 0x10f9;
  *(uint *)(param_1 + (int)((param_2 + 0x29 & 0xffffffff) << 2)) =
       *(uint *)(param_4 + 0x54) & 0x1fff | (*(uint *)(param_4 + 0x58) & 0x1fff) << 0xd;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2a & 0xffffffff) << 2)) = 0x13c0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2b & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2c & 0xffffffff) << 2)) = 0x13c1;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2d & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2e & 0xffffffff) << 2)) = 0x10c0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x2f & 0xffffffff) << 2)) = 4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x30 & 0xffffffff) << 2)) = 0x10c1;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x31 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x32 & 0xffffffff) << 2)) = 0x10c8;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x33 & 0xffffffff) << 2)) = 0x10;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x34 & 0xffffffff) << 2)) = 0x101d;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x35 & 0xffffffff) << 2)) = 0xc2040;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x36 & 0xffffffff) << 2)) = 0x1041;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x37 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x38 & 0xffffffff) << 2)) = 0x1040;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x39 & 0xffffffff) << 2)) = 0;
  if (*(int *)(param_4 + 0x70) == 3) {
    fVar1 = (float)((double)CONCAT44(0x43300000,param_3 & 0x1f) - DOUBLE_0000cfd8) / FLOAT_0000cff8;
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3 >> 10 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    fVar2 = (float)((double)CONCAT44(0x43300000,param_3 >> 5 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    fVar4 = (float)((double)CONCAT44(0x43300000,param_3 >> 0xf & 1) - DOUBLE_0000cfd8);
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,param_3 & 0xff) - DOUBLE_0000cfd8) / FLOAT_0000cffc;
    fVar4 = (float)((double)CONCAT44(0x43300000,param_3 >> 0x18) - DOUBLE_0000cfd8) / FLOAT_0000cffc
    ;
    fVar3 = (float)((double)CONCAT44(0x43300000,param_3 >> 0x10 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
    fVar2 = (float)((double)CONCAT44(0x43300000,param_3 >> 8 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
  }
  *(undefined4 *)(param_1 + (int)((param_2 + 0x3a & 0xffffffff) << 2)) = 0x1094;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x3b & 0xffffffff) << 2)) = 0x10000;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x3c & 0xffffffff) << 2)) = 0x1095;
  *(float *)(param_1 + (int)((param_2 + 0x3d & 0xffffffff) << 2)) = fVar3;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x3e & 0xffffffff) << 2)) = 0x1095;
  *(float *)(param_1 + (int)((param_2 + 0x3f & 0xffffffff) << 2)) = fVar2;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x40 & 0xffffffff) << 2)) = 0x1095;
  *(float *)(param_1 + (int)((param_2 + 0x41 & 0xffffffff) << 2)) = fVar1;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x42 & 0xffffffff) << 2)) = 0x1095;
  *(float *)(param_1 + (int)((param_2 + 0x43 & 0xffffffff) << 2)) = fVar4;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x44 & 0xffffffff) << 2)) = 0x1094;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x45 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x46 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x47 & 0xffffffff) << 2)) = 0x78105;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x48 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x49 & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4a & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4b & 0xffffffff) << 2)) = 0x100;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4c & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4d & 0xffffffff) << 2)) = 0xdb0220;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4e & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x4f & 0xffffffff) << 2)) = 0xc0c000;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x50 & 0xffffffff) << 2)) = 0x1095;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x51 & 0xffffffff) << 2)) = 0x20490000;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x52 & 0xffffffff) << 2)) = 0x1189;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x53 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x54 & 0xffffffff) << 2)) = 0x1181;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x55 & 0xffffffff) << 2)) = 1;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x56 & 0xffffffff) << 2)) = 0x118d;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x57 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x58 & 0xffffffff) << 2)) = 0x118e;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x59 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5a & 0xffffffff) << 2)) = 0x118c;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5b & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5c & 0xffffffff) << 2)) = 0x11a9;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5d & 0xffffffff) << 2)) = 0x1b01;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5e & 0xffffffff) << 2)) = 0x11aa;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x5f & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x60 & 0xffffffff) << 2)) = 0x11ab;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x61 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x62 & 0xffffffff) << 2)) = 0x11ac;
  *(undefined4 *)(param_1 + (int)((param_2 + 99 & 0xffffffff) << 2)) = 0xf;
  *(undefined4 *)(param_1 + (int)((param_2 + 100 & 0xffffffff) << 2)) = 0x12f0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x65 & 0xffffffff) << 2)) = 0;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x66 & 0xffffffff) << 2)) = 0x12f5;
  *(undefined4 *)(param_1 + (int)((param_2 + 0x67 & 0xffffffff) << 2)) = 0;
  return param_2 + 0x68;
}

/* __Flush @ 0x3d30 (344 bytes) */
undefined8 __Flush(param_1, param_2)
  int param_1;
  ulonglong param_2;
{
  uint *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_28;
  int local_24 [9];
  
  puVar4 = *(undefined4 **)(param_1 + 0x80);
  if (puVar4 != (undefined4 *)(*(int *)(param_1 + 0x18) + 0x20)) {
    if ((param_2 & 0x10000) == 0) {
      iVar3 = *(int *)(param_1 + 0x8c);
    }
    else {
      iVar3 = 0;
      if (*(int *)(param_1 + 0x8c) != 0) {
        puVar1 = *(uint **)(param_1 + 0x7c);
        *puVar1 = (int)puVar4 - (int)puVar1 >> 2 | *puVar1;
        *(undefined4 **)(param_1 + 0x7c) = puVar4;
        *puVar4 = 0x2000000;
        puVar4 = puVar4 + 1;
        iVar3 = *(int *)(param_1 + 0x8c);
      }
    }
    local_24[0] = *(int *)(param_1 + 0x18);
    local_28 = 0;
    if (iVar3 == 0) {
      *puVar4 = 0x5c8;
      local_28 = 2;
      puVar4[1] = 0xc000;
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    puVar4[local_28] = 0x1000000;
    puVar2 = PTR_0000e694;
    puVar1 = *(uint **)(param_1 + 0x7c);
    *puVar1 = ((int)puVar4 - (int)puVar1 >> 2) + local_28 | *puVar1;
    iVar3 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar2,local_24,
                                &local_28,1);
    if (iVar3 == 0) {
      *(undefined4 *)(local_24[0] + 0x1c) = 0;
      *(int *)(param_1 + 0x18) = local_24[0];
      iVar3 = local_24[0] + 0x20;
      *(int *)(param_1 + 0x7c) = local_24[0] + 0x1c;
    }
    else {
      iVar3 = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *(int *)(param_1 + 0x80) = iVar3;
  }
  return 0;
}

/* __WaitComplete @ 0x3ea0 (140 bytes) */
int __WaitComplete(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uStack0000001c;
  
  uStack0000001c = param_2;
  if (((*(int *)(param_1 + 0x80) != 0) && (*(int *)(param_1 + 0x8c) != 0)) &&
     (*(int *)(param_1 + 0x94) != 0)) {
    *(undefined4 *)(param_1 + 0x94) = 0;
    uStack0000001c = 1;
  }
  ((int (*)())__Flush)(param_1,0);
  _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 0xc),7,&STACKARG(0x1c),1,0,0);
  return;
}

/* __FreeSurface @ 0x3f30 (224 bytes) */
undefined8 __FreeSurface(param_1, param_2, param_3)
  int param_1;
  ulonglong param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_3 + 0x28);
  if (iVar1 == 0) {
    uVar3 = 0xffffffffe00002d8;
  }
  else {
    if (((param_2 & 8) != 0) && (*(int *)(param_1 + 0x94) != 0)) {
      ((int (*)())__WaitComplete)(param_1,0x88);
      iVar1 = *(int *)(param_3 + 0x28);
    }
    uVar3 = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
    if (param_3 == *(int *)(param_1 + 0x8c)) {
      uVar3 = __SetDestination(param_1,0,0);
    }
    piVar2 = *(int **)(param_3 + 0x28);
    if (*piVar2 != 0) {
      uVar3 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xb,*piVar2,1,0,0);
      piVar2 = *(int **)(param_3 + 0x28);
    }
    piVar2[2] = 0;
    _free(*(void **)(param_3 + 0x28));
    *(undefined4 *)(param_3 + 0x28) = 0;
  }
  return uVar3;
}

/* _createTextureBuffer @ 0x4020 (584 bytes) */
undefined8 _createTextureBuffer(param_1, param_2, param_3, param_4)
  int param_1;
  longlong param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (_textureBufferBytes == (void *)0x0) {
    uVar4 = param_2 + 0x20U & 0xffffffe0;
    uVar3 = param_3 + 0x20U & 0xffffffe0;
    goto LAB_00004194;
  }
  if (param_4 == 0) {
    if (DAT_0000e724 == 0x42475241) goto LAB_000040bc;
  }
  else if (DAT_0000e724 == 0x10) {
LAB_000040bc:
    uVar4 = param_2 + 0x20U & 0xffffffe0;
    if (((int)uVar4 == _textureBufferWidth) &&
       (uVar3 = param_3 + 0x20U & 0xffffffe0, uVar3 == _textureBufferHeight)) {
      iVar1 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xc,*DAT_0000e748,1,0,0);
      if (iVar1 == 0) {
        return 1;
      }
      if (_textureBufferBytes == (void *)0x0) goto LAB_00004194;
    }
  }
  uVar4 = param_2 + 0x20U & 0xffffffe0;
  uVar3 = param_3 + 0x20U & 0xffffffe0;
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
  _free(_textureBufferBytes);
  _textureBufferBytes = (void *)0x0;
LAB_00004194:
  _textureBufferWidth = (int)uVar4;
  if (param_4 == 0) {
    DAT_0000e738 = (undefined4)(uVar4 << 2);
    DAT_0000e724 = 0x42475241;
    _textureBufferSize = _textureBufferWidth * uVar3 * 4;
  }
  else {
    DAT_0000e738 = (undefined4)(uVar4 << 1);
    _textureBufferSize = _textureBufferWidth * uVar3 * 2;
    DAT_0000e724 = 0x10;
  }
  _textureBufferHeight = uVar3;
  DAT_0000e730 = _textureBufferWidth;
  DAT_0000e734 = uVar3;
  _textureBufferBytes = _malloc(_textureBufferSize);
  uVar2 = 0;
  if (_textureBufferBytes != (void *)0x0) {
    _textureBuffer = _textureBufferBytes;
    iVar1 = ((int (*)())__AllocateSurface)(param_1,8,&_textureBuffer,0);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_textureBufferBytes);
      uVar2 = 0;
      _textureBufferBytes = (void *)0x0;
    }
  }
  return uVar2;
}

/* _createOffscreenBuffer @ 0x4290 (588 bytes) */
undefined8 _createOffscreenBuffer(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ulonglong uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (_offscreenBufferBytes == (void *)0x0) goto LAB_000043f0;
  if (param_3 == 0) {
    if (DAT_0000e6c0 == 0x42475241) goto LAB_0000430c;
  }
  else if (DAT_0000e6c0 == 0x10) {
LAB_0000430c:
    if ((((int)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0) == _offscreenBufferWidth) &&
       (((int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0) == _offscreenBufferHeight)) {
      iVar2 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xc,*DAT_0000e6e4,1,0,0);
      if (iVar2 == 0) {
        return 1;
      }
      if (_offscreenBufferBytes == (void *)0x0) goto LAB_000043f0;
    }
  }
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
  _free(_offscreenBufferBytes);
  _offscreenBufferBytes = (void *)0x0;
LAB_000043f0:
  uVar1 = (longlong)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0;
  _offscreenBufferWidth = (uint)uVar1;
  _offscreenBufferHeight = (int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0;
  if (param_3 == 0) {
    DAT_0000e6d4 = (undefined4)(uVar1 << 2);
    DAT_0000e6c0 = 0x42475241;
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 4;
  }
  else {
    DAT_0000e6d4 = (undefined4)(uVar1 << 1);
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 2;
    DAT_0000e6c0 = 0x10;
  }
  DAT_0000e6cc = _offscreenBufferWidth;
  DAT_0000e6d0 = _offscreenBufferHeight;
  _offscreenBufferBytes = _malloc(_offscreenBufferSize);
  uVar3 = 0;
  if (_offscreenBufferBytes != (void *)0x0) {
    _offscreenBuffer = _offscreenBufferBytes;
    iVar2 = ((int (*)())__AllocateSurface)(param_1,0,&_offscreenBuffer,0);
    if (iVar2 == 0) {
      uVar3 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_offscreenBufferBytes);
      uVar3 = 0;
      _offscreenBufferBytes = (void *)0x0;
    }
  }
  return uVar3;
}

/* __Stop @ 0x4500 (248 bytes) */
undefined8 __Stop(param_1)
  int param_1;
{
  int iVar1;
  
  if (_offscreenBufferBytes != (void *)0x0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
    _free(_offscreenBufferBytes);
    _offscreenBufferBytes = (void *)0x0;
  }
  if (_textureBufferBytes != (void *)0x0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
    _free(_textureBufferBytes);
    _textureBufferBytes = (void *)0x0;
  }
  ((int (*)())__Flush)(param_1,0);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      _IOServiceClose(*(int *)(param_1 + 0xc));
      iVar1 = *(int *)(param_1 + 0x10);
    }
    _IOObjectRelease(iVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}

/* _radeonCopy @ 0x4600 (3944 bytes) */
undefined8 _radeonCopy(param_1)
  int param_1;
{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 *puVar8;
  bool bVar9;
  uint uVar10;
  undefined *puVar11;
  int iVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  dword *pdVar16;
  int in_r7;
  ulonglong uVar17;
  ulonglong uVar18;
  dword *pdVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  dword *pdVar22;
  ulonglong uVar23;
  dword *pdVar24;
  dword *pdVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  ulonglong uVar28;
  ulonglong uVar29;
  ulonglong uVar30;
  ulonglong uVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  uint uVar37;
  ulonglong uVar38;
  uint uVar39;
  ulonglong uVar40;
  ulonglong uVar41;
  int *piVar44;
  longlong lVar42;
  longlong lVar43;
  ulonglong uVar45;
  ulonglong uVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  double dVar54;
  double dVar55;
  double dVar56;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float afStack_19c [2];
  uint uStack_194;
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_188;
  uint uStack_184;
  undefined4 uStack_180;
  uint uStack_17c;
  longlong lStack_178;
  longlong lStack_170;
  longlong lStack_168;
  longlong lStack_160;
  longlong lStack_158;
  longlong lStack_150;
  longlong lStack_148;
  longlong lStack_140;
  undefined4 uStack_138;
  uint uStack_134;
  undefined4 uStack_128;
  uint uStack_124;
  undefined4 uStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  uint uStack_10c;
  undefined4 uStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  uint uStack_fc;
  int iStack_f8;
  int iStack_f4;
  int iStack_f0;
  int iStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  int iStack_d0;
  undefined4 *puStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  float *pfStack_c0;
  float *pfStack_bc;
  short sStack_b8;
  short sStack_b6;
  float *pfStack_b4;
  float *pfStack_b0;
  int *piStack_ac;
  
  piVar44 = (int *)(in_r7 + 0x5c);
  iVar12 = ((int (*)())FUN_0000c968)();
  uVar2 = *(uint *)(iVar12 + 0x80);
  uVar45 = (ulonglong)uVar2;
  iVar3 = *(int *)(in_r7 + 0x58);
  uVar41 = (ulonglong)*(uint *)(*(int *)(iVar12 + 0x18) + 0x10) - 7;
  if (uVar2 != 0) {
    uVar40 = uVar41 - (longlong)((int)(uVar2 - (*(int *)(iVar12 + 0x18) + 0x20)) >> 2);
    if ((0x1000 < *(short *)(param_1 + 0x50)) || (0x1000 < *(short *)(param_1 + 0x52))) {
      return 0xffffffffe00002c7;
    }
    iVar12 = ((int (*)())_createOffscreenBuffer)(iVar12,param_1 + 0x4c,0);
    if (iVar12 != 0) {
      uStack_d4 = *(uint *)(param_1 + 0x70);
      puStack_cc = DAT_0000e6e4 + 3;
      if (uStack_d4 == 3) {
        uStack_d4 = 0xb;
      }
      else if (uStack_d4 == 6) {
        uStack_d4 = 0xc;
      }
      uStack_d8 = DAT_0000e6e4[0xc];
      if (uStack_d8 == 3) {
        uStack_d8 = 0xb;
      }
      else if (uStack_d8 == 6) {
        uStack_d8 = 0xc;
      }
      if (iVar3 != 0) {
        pfStack_c0 = &fStack_1a0;
        pfStack_bc = afStack_19c;
        pfStack_b4 = &fStack_1a8;
        iStack_d0 = 0;
        pfStack_b0 = &fStack_1a4;
        uStack_c8 = 0xc000;
        uStack_c4 = uStack_d4 & 0x1f | 0x53000;
        bVar9 = true;
        dVar51 = DOUBLE_0000cfe8;
        dVar52 = DOUBLE_0000cfe0;
        piStack_ac = piVar44;
        do {
          afStack_19c[1] = 176.0;
          uStack_194 = *piStack_ac + *(int *)(param_1 + 0x60) ^ 0x80000000;
          uStack_190 = 0x43300000;
          uStack_188 = 0x43300000;
          uStack_180 = 0x43300000;
          uStack_18c = piStack_ac[1] + *(int *)(param_1 + 100) ^ 0x80000000;
          uStack_184 = piStack_ac[4] ^ 0x80000000;
          uStack_17c = piStack_ac[5] ^ 0x80000000;
          dVar47 = (double)CONCAT44(0x43300000,uStack_194) - dVar52;
          dVar53 = (double)(float)dVar47;
          dVar49 = (double)CONCAT44(0x43300000,uStack_18c) - dVar52;
          dVar54 = (double)(float)dVar49;
          dVar48 = dVar54 + (double)(float)((double)CONCAT44(0x43300000,uStack_17c) - dVar52);
          dVar56 = (double)(float)dVar48;
          dVar50 = dVar53 + (double)(float)((double)CONCAT44(0x43300000,uStack_184) - dVar52);
          dVar55 = (double)(float)dVar50;
          if (DOUBLE_0000cff0 <= dVar53) {
            lStack_170 = (longlong)(int)(dVar53 - DOUBLE_0000cff0);
            uStack_dc = (int)(dVar53 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_dc = (uint)dVar47;
            lStack_178 = (longlong)(int)uStack_dc;
          }
          if (DOUBLE_0000cff0 <= dVar54) {
            lStack_160 = (longlong)(int)(dVar54 - DOUBLE_0000cff0);
            uStack_e0 = (int)(dVar54 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_e0 = (uint)dVar49;
            lStack_168 = (longlong)(int)uStack_e0;
          }
          if (DOUBLE_0000cff0 <= dVar55) {
            lStack_150 = (longlong)(int)(dVar55 - DOUBLE_0000cff0);
            uStack_e4 = (int)(dVar55 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_e4 = (uint)dVar50;
            lStack_158 = (longlong)(int)uStack_e4;
          }
          if (DOUBLE_0000cff0 <= dVar56) {
            lStack_140 = (longlong)(int)(dVar56 - DOUBLE_0000cff0);
            uStack_e8 = (int)(dVar56 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_e8 = (uint)dVar48;
            lStack_148 = (longlong)(int)uStack_e8;
          }
          puVar8 = (undefined4 *)uVar45;
          if (bVar9) {
            if ((uVar40 & 0xffffffff) < 0x8a) {
              fStack_1a8 = *(float *)(param_1 + 0x18);
              afStack_19c[0] = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar8 = 0x5c8;
                afStack_19c[0] = 2.8026e-45;
                puVar8[1] = uStack_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar8[(int)afStack_19c[0]] = 0x1000000;
              puVar4 = *(uint **)(param_1 + 0x7c);
              *puVar4 = ((int)puVar8 - (int)puVar4 >> 2) + (int)afStack_19c[0] | *puVar4;
              iVar12 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,pfStack_b4,pfStack_bc,1);
              if (iVar12 == 0) {
                bVar9 = true;
                *(undefined4 *)((int)fStack_1a8 + 0x1c) = 0;
                uVar45 = (ulonglong)(uint)fStack_1a8 + 0x20;
                *(float *)(param_1 + 0x18) = fStack_1a8;
                lVar42 = (ulonglong)(uint)fStack_1a8 + 0x38;
                pdVar16 = (dword *)((int)fStack_1a8 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)fStack_1a8 + 0x1c;
                pdVar25 = (dword *)((int)fStack_1a8 + 0x28);
                pdVar19 = (dword *)((int)fStack_1a8 + 0x2c);
                pdVar22 = (dword *)((int)fStack_1a8 + 0x30);
                pdVar24 = (dword *)((int)fStack_1a8 + 0x34);
                uVar40 = uVar41;
              }
              else {
LAB_00004b14:
                bVar9 = true;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                uVar45 = 0;
                pdVar16 = &__mh_bundle_header.cputype;
                pdVar25 = &__mh_bundle_header.cpusubtype;
                pdVar19 = &__mh_bundle_header.filetype;
                pdVar22 = &__mh_bundle_header.ncmds;
                pdVar24 = &__mh_bundle_header.sizeofcmds;
                lVar42 = 0x18;
                uVar40 = uVar41;
              }
            }
            else {
              pdVar16 = puVar8 + 1;
              pdVar25 = puVar8 + 2;
              pdVar19 = puVar8 + 3;
              pdVar22 = puVar8 + 4;
              pdVar24 = puVar8 + 5;
              lVar42 = uVar45 + 0x18;
              bVar9 = true;
            }
          }
          else if ((uVar40 & 0xffffffff) < 0x22) {
            afStack_19c[0] = *(float *)(param_1 + 0x18);
            fStack_1a8 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *puVar8 = 0x5c8;
              fStack_1a8 = 2.8026e-45;
              puVar8[1] = uStack_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar8[(int)fStack_1a8] = 0x1000000;
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = ((int)puVar8 - (int)puVar4 >> 2) + (int)fStack_1a8 | *puVar4;
            iVar12 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,pfStack_bc,&fStack_1a8,1);
            if (iVar12 != 0) goto LAB_00004b14;
            bVar9 = true;
            *(undefined4 *)((int)afStack_19c[0] + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = afStack_19c[0];
            uVar45 = (ulonglong)(uint)afStack_19c[0] + 0x20;
            lVar42 = (ulonglong)(uint)afStack_19c[0] + 0x38;
            *(int *)(param_1 + 0x7c) = (int)afStack_19c[0] + 0x1c;
            pdVar16 = (dword *)((int)afStack_19c[0] + 0x24);
            pdVar25 = (dword *)((int)afStack_19c[0] + 0x28);
            pdVar19 = (dword *)((int)afStack_19c[0] + 0x2c);
            pdVar22 = (dword *)((int)afStack_19c[0] + 0x30);
            pdVar24 = (dword *)((int)afStack_19c[0] + 0x34);
            uVar40 = uVar41;
          }
          else {
            pdVar16 = puVar8 + 1;
            pdVar25 = puVar8 + 2;
            pdVar19 = puVar8 + 3;
            pdVar22 = puVar8 + 4;
            pdVar24 = puVar8 + 5;
            lVar42 = uVar45 + 0x18;
            bVar9 = false;
          }
          puVar4 = *(uint **)(param_1 + 0x7c);
          puVar8 = (undefined4 *)uVar45;
          *puVar4 = (int)puVar8 - (int)puVar4 >> 2 | *puVar4;
          *(undefined4 **)(param_1 + 0x7c) = puVar8;
          *puVar8 = 0xe000000;
          *pdVar16 = 0;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = (int)pdVar25 - (int)puVar4 >> 2 | *puVar4;
          *(dword **)(param_1 + 0x7c) = pdVar25;
          *pdVar25 = 0x10000000;
          *pdVar19 = *(dword *)*DAT_0000e6e4;
          *pdVar22 = DAT_0000e6e4[7];
          *pdVar24 = 6;
          puVar8 = (undefined4 *)lVar42;
          if (bVar9) {
            uVar45 = ((int (*)())_radeon3DCopySetup)(param_1,lVar42,param_1 + 0x4c,uStack_d4,0,0,0,0);
            sStack_b8 = *(short *)(param_1 + 0x50);
            uVar17 = uVar45 + 1;
            uVar20 = uVar45 + 2;
            uVar14 = uVar45 + 0x16;
            iVar12 = (int)((uVar45 & 0x3fffffff) << 2);
            uVar46 = uVar45 + 3;
            uVar26 = uVar45 + 4;
            uVar15 = uVar45 + 5;
            uVar18 = uVar45 + 6;
            uVar23 = uVar45 + 7;
            uVar21 = uVar45 + 8;
            uVar27 = uVar45 + 9;
            uVar28 = uVar45 + 10;
            uVar29 = uVar45 + 0xb;
            uVar30 = uVar45 + 0xc;
            uVar31 = uVar45 + 0xd;
            uVar32 = uVar45 + 0xe;
            uVar33 = uVar45 + 0xf;
            uVar34 = uVar45 + 0x10;
            uVar35 = uVar45 + 0x11;
            uVar36 = uVar45 + 0x12;
            uVar38 = uVar45 + 0x13;
            uVar13 = uVar45 + 0x14;
            uVar45 = uVar45 + 0x15;
            sStack_b6 = *(short *)(param_1 + 0x52);
          }
          else {
            *puVar8 = 0x1120;
            sStack_b8 = *(short *)(param_1 + 0x50);
            sStack_b6 = *(short *)(param_1 + 0x52);
            puVar8[1] = (int)sStack_b8 - 1U & 0x7ff | (sStack_b6 + -1) * 0x800 & 0x3ff800U |
                        0x80000000;
            puVar8[2] = 0x1130;
            puVar8[3] = uStack_c4;
            puVar8[4] = 0x1140;
            puVar8[5] = *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
                        ((int)sStack_b8 - 1U) * 0x10 & 0x8000 | (sStack_b6 + -1) * 0x20 & 0x10000U;
            iVar12 = 0x18;
            uVar46 = 9;
            uVar17 = 7;
            uVar26 = 10;
            uVar15 = 0xb;
            uVar20 = 8;
            uVar18 = 0xc;
            uVar23 = 0xd;
            uVar21 = 0xe;
            uVar27 = 0xf;
            uVar28 = 0x10;
            uVar29 = 0x11;
            uVar30 = 0x12;
            uVar31 = 0x13;
            uVar32 = 0x14;
            uVar33 = 0x15;
            uVar34 = 0x16;
            uVar35 = 0x17;
            uVar36 = 0x18;
            uVar38 = 0x19;
            uVar13 = 0x1a;
            uVar45 = 0x1b;
            uVar14 = 0x1c;
          }
          *(undefined4 *)((int)puVar8 + iVar12) = 0x10f8;
          *(uint *)((int)puVar8 + (int)((uVar17 & 0xffffffff) << 2)) =
               uStack_dc & 0x1fff | (uStack_e0 & 0x1fff) << 0xd;
          *(undefined4 *)((int)puVar8 + (int)((uVar20 & 0xffffffff) << 2)) = 0x10f9;
          *(uint *)((int)puVar8 + (int)((uVar46 & 0xffffffff) << 2)) =
               uStack_e4 & 0x1fff | (uStack_e8 & 0x1fff) << 0xd;
          *(undefined4 *)((int)puVar8 + (int)((uVar26 & 0xffffffff) << 2)) = 0xc00c3500;
          *(undefined4 *)((int)puVar8 + (int)((uVar15 & 0xffffffff) << 2)) = 0x4003d;
          uStack_134 = (int)sStack_b8 ^ 0x80000000;
          uStack_124 = (int)sStack_b6 ^ 0x80000000;
          uStack_138 = 0x43300000;
          uStack_128 = 0x43300000;
          dVar50 = dVar51 / ((double)CONCAT44(0x43300000,uStack_134) - dVar52);
          dVar48 = dVar51 / ((double)CONCAT44(0x43300000,uStack_124) - dVar52);
          fStack_1a4 = (float)(dVar55 * dVar50);
          afStack_19c[0] = (float)(dVar56 * dVar48);
          fStack_1a0 = (float)(dVar53 * dVar50);
          fStack_1a8 = (float)(dVar54 * dVar48);
          *(uint *)((int)puVar8 + (int)((uVar18 & 0xffffffff) << 2)) = uStack_dc | uStack_e8 << 0x10
          ;
          fVar5 = *pfStack_c0;
          *(float *)((int)puVar8 + (int)((uVar23 & 0xffffffff) << 2)) = fVar5;
          fVar6 = *pfStack_bc;
          *(float *)((int)puVar8 + (int)((uVar21 & 0xffffffff) << 2)) = fVar6;
          *(uint *)((int)puVar8 + (int)((uVar27 & 0xffffffff) << 2)) = uStack_dc | uStack_e0 << 0x10
          ;
          *(float *)((int)puVar8 + (int)((uVar28 & 0xffffffff) << 2)) = fVar5;
          fVar5 = *pfStack_b4;
          *(float *)((int)puVar8 + (int)((uVar29 & 0xffffffff) << 2)) = fVar5;
          *(uint *)((int)puVar8 + (int)((uVar30 & 0xffffffff) << 2)) = uStack_e4 | uStack_e0 << 0x10
          ;
          fVar7 = *pfStack_b0;
          *(float *)((int)puVar8 + (int)((uVar31 & 0xffffffff) << 2)) = fVar7;
          *(float *)((int)puVar8 + (int)((uVar32 & 0xffffffff) << 2)) = fVar5;
          *(uint *)((int)puVar8 + (int)((uVar33 & 0xffffffff) << 2)) = uStack_e4 | uStack_e8 << 0x10
          ;
          *(float *)((int)puVar8 + (int)((uVar34 & 0xffffffff) << 2)) = fVar7;
          *(float *)((int)puVar8 + (int)((uVar35 & 0xffffffff) << 2)) = fVar6;
          *(undefined4 *)((int)puVar8 + (int)((uVar36 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)((int)puVar8 + (int)((uVar38 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)((int)puVar8 + (int)((uVar13 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)((int)puVar8 + (int)((uVar45 & 0xffffffff) << 2)) = 0x20000;
          uVar45 = (uVar40 - 6) - uVar14;
          uVar2 = piStack_ac[5];
          uVar39 = piStack_ac[2] + *(int *)(param_1 + 0x60);
          uVar40 = (ulonglong)(uint)piStack_ac[3] + (ulonglong)*(uint *)(param_1 + 100);
          uVar37 = uVar39 + piStack_ac[4];
          lVar42 = (uVar14 & 0x3fffffff) * 4 + lVar42;
          puVar8 = (undefined4 *)lVar42;
          if ((uVar45 & 0xffffffff) < 0x22) {
            fStack_1a4 = *(float *)(param_1 + 0x18);
            fStack_1a0 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *puVar8 = 0x5c8;
              fStack_1a0 = 2.8026e-45;
              puVar8[1] = uStack_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar8[(int)fStack_1a0] = 0x1000000;
            puVar11 = PTR_0000e694;
            puVar4 = *(uint **)(param_1 + 0x7c);
            *puVar4 = ((int)puVar8 - (int)puVar4 >> 2) + (int)fStack_1a0 | *puVar4;
            iVar12 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                         pfStack_b0,pfStack_c0,1);
            uVar45 = uVar41;
            if (iVar12 == 0) {
              bVar9 = true;
              *(undefined4 *)((int)fStack_1a4 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = fStack_1a4;
              lVar42 = (ulonglong)(uint)fStack_1a4 + 0x20;
              lVar43 = (ulonglong)(uint)fStack_1a4 + 0x38;
              *(int *)(param_1 + 0x7c) = (int)fStack_1a4 + 0x1c;
              pdVar16 = (dword *)((int)fStack_1a4 + 0x24);
              pdVar19 = (dword *)((int)fStack_1a4 + 0x28);
              pdVar22 = (dword *)((int)fStack_1a4 + 0x2c);
              pdVar25 = (dword *)((int)fStack_1a4 + 0x30);
              pdVar24 = (dword *)((int)fStack_1a4 + 0x34);
            }
            else {
              bVar9 = true;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              lVar42 = 0;
              pdVar16 = &__mh_bundle_header.cputype;
              pdVar19 = &__mh_bundle_header.cpusubtype;
              pdVar22 = &__mh_bundle_header.filetype;
              pdVar25 = &__mh_bundle_header.ncmds;
              pdVar24 = &__mh_bundle_header.sizeofcmds;
              lVar43 = 0x18;
            }
          }
          else {
            pdVar16 = puVar8 + 1;
            pdVar19 = puVar8 + 2;
            pdVar22 = puVar8 + 3;
            pdVar25 = puVar8 + 4;
            pdVar24 = puVar8 + 5;
            lVar43 = lVar42 + 0x18;
            bVar9 = false;
          }
          puVar4 = *(uint **)(param_1 + 0x7c);
          puVar8 = (undefined4 *)lVar42;
          *puVar4 = (int)puVar8 - (int)puVar4 >> 2 | *puVar4;
          *(undefined4 **)(param_1 + 0x7c) = puVar8;
          *puVar8 = 0x12000000;
          *pdVar16 = 0;
          *pdVar19 = 0;
          *pdVar22 = 0;
          puVar4 = *(uint **)(param_1 + 0x7c);
          *puVar4 = (int)pdVar25 - (int)puVar4 >> 2 | *puVar4;
          *(dword **)(param_1 + 0x7c) = pdVar25;
          *pdVar25 = 0x4000000;
          *pdVar24 = *(dword *)*DAT_0000e6e4;
          puVar8 = (undefined4 *)lVar43;
          if (bVar9) {
            uVar14 = ((int (*)())_radeon3DCopySetup)(param_1,lVar43,puStack_cc,uStack_d8,0,0,0,0);
            iStack_f0 = (int)uVar14;
            iStack_ec = iStack_f0 + 1;
            uVar26 = uVar14 + 9;
            iStack_f4 = iStack_f0 + 3;
            iStack_f8 = iStack_f0 + 4;
            uVar13 = uVar14 + 10;
            iStack_f0 = iStack_f0 + 2;
            uVar17 = uVar14 + 0x16;
            iVar12 = (int)((uVar14 & 0x3fffffff) << 2);
            uVar18 = uVar14 + 5;
            uVar23 = uVar14 + 6;
            uVar20 = uVar14 + 7;
            uVar21 = uVar14 + 8;
            uVar28 = uVar14 + 0xb;
            uVar29 = uVar14 + 0xc;
            uVar30 = uVar14 + 0xd;
            uVar31 = uVar14 + 0xe;
            uVar32 = uVar14 + 0xf;
            uVar33 = uVar14 + 0x10;
            uVar34 = uVar14 + 0x11;
            uVar35 = uVar14 + 0x12;
            uVar27 = uVar14 + 0x13;
            uVar15 = uVar14 + 0x14;
            uVar14 = uVar14 + 0x15;
          }
          else {
            *puVar8 = 0x1120;
            sVar1 = *(short *)(puStack_cc + 1);
            iVar12 = *(short *)((int)puStack_cc + 6) + -1;
            puVar8[1] = (int)sVar1 - 1U & 0x7ff | iVar12 * 0x800 & 0x3ff800U | 0x80000000;
            puVar8[2] = 0x1130;
            puVar8[3] = uStack_d8 & 0x1f | 0x53000;
            puVar8[4] = 0x1140;
            puVar8[5] = puStack_cc[4] - 1 & 0x3fff | ((int)sVar1 - 1U) * 0x10 & 0x8000 |
                        iVar12 * 0x20 & 0x10000U;
            iStack_f8 = 10;
            iStack_f0 = 8;
            iVar12 = 0x18;
            iStack_f4 = 9;
            iStack_ec = 7;
            uVar26 = 0xf;
            uVar18 = 0xb;
            uVar23 = 0xc;
            uVar20 = 0xd;
            uVar13 = 0x10;
            uVar21 = 0xe;
            uVar28 = 0x11;
            uVar29 = 0x12;
            uVar30 = 0x13;
            uVar31 = 0x14;
            uVar32 = 0x15;
            uVar33 = 0x16;
            uVar34 = 0x17;
            uVar35 = 0x18;
            uVar27 = 0x19;
            uVar15 = 0x1a;
            uVar14 = 0x1b;
            uVar17 = 0x1c;
          }
          *(undefined4 *)((int)puVar8 + iVar12) = 0x10f8;
          puVar8[iStack_ec] = uVar39 & 0x1fff | (uint)((uVar40 & 0xffffffff) << 0xd) & 0x3ffe000;
          puVar8[iStack_f0] = 0x10f9;
          puVar8[iStack_f4] =
               uVar37 & 0x1fff | (uint)((uVar40 + uVar2 & 0xffffffff) << 0xd) & 0x3ffe000;
          puVar8[iStack_f8] = 0xc00c3500;
          *(undefined4 *)((int)puVar8 + (int)((uVar18 & 0xffffffff) << 2)) = 0x4003d;
          uVar2 = (uint)((uVar40 + uVar2 & 0xffffffff) << 0x10);
          uStack_118 = 0x43300000;
          uStack_114 = (int)*(short *)(puStack_cc + 1) ^ 0x80000000;
          fStack_1a8 = (float)(dVar53 * (dVar51 / ((double)CONCAT44(0x43300000,uStack_114) - dVar52)
                                        ));
          uStack_110 = 0x43300000;
          uStack_10c = (int)*(short *)(puStack_cc + 1) ^ 0x80000000;
          afStack_19c[0] =
               (float)(dVar55 * (dVar51 / ((double)CONCAT44(0x43300000,uStack_10c) - dVar52)));
          uStack_108 = 0x43300000;
          uStack_104 = (int)*(short *)((int)puStack_cc + 6) ^ 0x80000000;
          fStack_1a0 = (float)(dVar54 * (dVar51 / ((double)CONCAT44(0x43300000,uStack_104) - dVar52)
                                        ));
          uStack_100 = 0x43300000;
          uStack_fc = (int)*(short *)((int)puStack_cc + 6) ^ 0x80000000;
          fStack_1a4 = (float)(dVar56 * (dVar51 / ((double)CONCAT44(0x43300000,uStack_fc) - dVar52))
                              );
          *(uint *)((int)puVar8 + (int)((uVar23 & 0xffffffff) << 2)) = uVar39 | uVar2;
          fVar5 = *pfStack_b4;
          *(float *)((int)puVar8 + (int)((uVar20 & 0xffffffff) << 2)) = fVar5;
          fVar6 = *pfStack_b0;
          *(float *)((int)puVar8 + (int)((uVar21 & 0xffffffff) << 2)) = fVar6;
          uVar10 = (uint)((uVar40 & 0xffffffff) << 0x10);
          *(uint *)((int)puVar8 + (int)((uVar26 & 0xffffffff) << 2)) = uVar39 | uVar10;
          *(float *)((int)puVar8 + (int)((uVar13 & 0xffffffff) << 2)) = fVar5;
          fVar5 = *pfStack_c0;
          *(float *)((int)puVar8 + (int)((uVar28 & 0xffffffff) << 2)) = fVar5;
          *(uint *)((int)puVar8 + (int)((uVar29 & 0xffffffff) << 2)) = uVar37 | uVar10;
          fVar7 = *pfStack_bc;
          *(float *)((int)puVar8 + (int)((uVar30 & 0xffffffff) << 2)) = fVar7;
          *(float *)((int)puVar8 + (int)((uVar31 & 0xffffffff) << 2)) = fVar5;
          *(uint *)((int)puVar8 + (int)((uVar32 & 0xffffffff) << 2)) = uVar37 | uVar2;
          *(float *)((int)puVar8 + (int)((uVar33 & 0xffffffff) << 2)) = fVar7;
          *(float *)((int)puVar8 + (int)((uVar34 & 0xffffffff) << 2)) = fVar6;
          *(undefined4 *)((int)puVar8 + (int)((uVar35 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)((int)puVar8 + (int)((uVar27 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)((int)puVar8 + (int)((uVar15 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)((int)puVar8 + (int)((uVar14 & 0xffffffff) << 2)) = 0x20000;
          uVar40 = (uVar45 - 6) - uVar17;
          uVar45 = lVar43 + (uVar17 & 0x3fffffff) * 4;
          iStack_d0 = iStack_d0 + 1;
          piStack_ac = piStack_ac + 6;
          bVar9 = false;
        } while (iVar3 != iStack_d0);
      }
      *(int *)(param_1 + 0x80) = (int)uVar45;
      return 0;
    }
  }
  return 0xffffffffe00002be;
}

/* FUN_000055a4 @ 0x55a4 (11396 bytes) */
undefined8 FUN_000055a4(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined8 param_2;
  undefined8 param_3;
  uint param_4;
  int param_5;
  dword param_6;
{
  bool bVar1;
  float fVar2;
  dword dVar3;
  dword dVar4;
  uint *puVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  bool bVar9;
  uint uVar10;
  undefined *puVar11;
  ulonglong uVar12;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar13;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  int *piVar21;
  dword *pdVar22;
  int *piVar23;
  ulonglong uVar24;
  dword *pdVar25;
  ulonglong uVar26;
  dword *pdVar27;
  longlong lVar28;
  ulonglong uVar29;
  longlong lVar30;
  dword *pdVar31;
  dword *pdVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  ulonglong uVar35;
  ulonglong uVar36;
  int iVar37;
  ulonglong uVar38;
  ulonglong uVar39;
  ulonglong uVar40;
  ulonglong uVar41;
  ulonglong uVar42;
  ulonglong uVar43;
  uint uVar44;
  ulonglong uVar45;
  short sVar46;
  ulonglong uVar47;
  uint uVar48;
  ulonglong uVar49;
  ulonglong uVar50;
  ulonglong uVar51;
  uint uVar53;
  ulonglong uVar52;
  ulonglong uVar54;
  undefined4 *puVar55;
  ulonglong uVar56;
  ulonglong uVar57;
  double dVar58;
  double dVar59;
  double dVar60;
  double dVar61;
  double dVar62;
  double dVar63;
  double dVar64;
  double dVar65;
  double dVar66;
  double dVar67;
  undefined4 uStack_368;
  float fStack_364;
  float fStack_360;
  float fStack_35c;
  float fStack_358;
  dword adStack_354 [3];
  short sStack_348;
  undefined4 uStack_318;
  uint uStack_314;
  undefined4 uStack_310;
  uint uStack_30c;
  undefined4 uStack_308;
  dword dStack_304;
  undefined4 uStack_300;
  dword dStack_2fc;
  undefined4 uStack_2f8;
  uint uStack_2f4;
  undefined4 uStack_2f0;
  uint uStack_2ec;
  undefined4 uStack_2e8;
  uint uStack_2e4;
  undefined4 uStack_2e0;
  uint uStack_2dc;
  longlong lStack_2d8;
  longlong lStack_2d0;
  longlong lStack_2c8;
  longlong lStack_2c0;
  longlong lStack_2b8;
  longlong lStack_2b0;
  longlong lStack_2a8;
  longlong lStack_2a0;
  undefined4 uStack_298;
  uint uStack_294;
  undefined4 uStack_290;
  uint uStack_28c;
  undefined4 uStack_288;
  uint uStack_284;
  undefined4 uStack_280;
  uint uStack_27c;
  undefined4 uStack_278;
  uint uStack_274;
  undefined4 uStack_270;
  uint uStack_26c;
  undefined4 uStack_268;
  uint uStack_264;
  undefined4 uStack_260;
  uint uStack_25c;
  undefined4 uStack_258;
  uint uStack_254;
  undefined4 uStack_250;
  uint uStack_24c;
  undefined4 uStack_248;
  uint uStack_244;
  undefined4 uStack_240;
  uint uStack_23c;
  undefined4 uStack_238;
  int iStack_234;
  undefined4 uStack_230;
  uint uStack_22c;
  undefined4 uStack_228;
  uint uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  uint uStack_214;
  undefined4 uStack_210;
  uint uStack_20c;
  undefined4 uStack_208;
  uint uStack_204;
  undefined4 uStack_200;
  uint uStack_1fc;
  undefined4 uStack_1f8;
  uint uStack_1f4;
  undefined4 uStack_1f0;
  uint uStack_1ec;
  undefined4 uStack_1e8;
  uint uStack_1e4;
  undefined4 uStack_1e0;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  uint uStack_1d4;
  longlong lStack_1d0;
  longlong lStack_1c8;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_1a0;
  uint uStack_19c;
  undefined4 uStack_198;
  uint uStack_194;
  undefined4 uStack_190;
  uint uStack_18c;
  longlong lStack_188;
  longlong lStack_180;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  uint uStack_16c;
  int *piStack_168;
  short *psStack_164;
  short *psStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  uint uStack_13c;
  uint uStack_138;
  uint uStack_134;
  uint uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uint uStack_120;
  uint uStack_11c;
  uint uStack_118;
  dword dStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  dword dStack_100;
  dword dStack_fc;
  uint uStack_f8;
  dword dStack_f4;
  int iStack_f0;
  int iStack_ec;
  uint uStack_e8;
  int iStack_e4;
  int iStack_e0;
  undefined4 *puStack_dc;
  dword *pdStack_d8;
  int *piStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  float *pfStack_b8;
  float *pfStack_b4;
  float *pfStack_b0;
  float *pfStack_ac;
  int *piStack_a8;
  
  param_4 = param_4 & 0x7ffff000;
  iVar37 = param_5;
  iVar14 = ((int (*)())FUN_0000c968)();
  uVar48 = *(uint *)(iVar14 + 0x80);
  uVar54 = (ulonglong)uVar48;
  iVar15 = *(int *)(iVar14 + 0x18);
  piVar21 = *(int **)(iVar37 + 0x60);
  uVar12 = (ulonglong)*(uint *)(iVar15 + 0x10);
  iVar37 = *piVar21;
  uVar38 = uVar12 - 7;
  if (uVar48 == 0) {
LAB_000081e0:
    uVar13 = 0xffffffffe00002be;
  }
  else {
    bVar1 = param_4 == 0x1000;
    if (bVar1) {
      dStack_fc = *(dword *)(iVar14 + 0x84);
      pdStack_d8 = (dword *)(iVar14 + 0x1c);
      iStack_ec = *(int *)(iVar14 + 0x30);
      iStack_140 = 0x9000000;
      iStack_f0 = *(int *)(iVar14 + 0x34);
LAB_000056ac:
      sStack_348 = *(short *)(pdStack_d8 + 1);
      if ((0x1000 < sStack_348) || (0x1000 < *(short *)((int)pdStack_d8 + 6))) {
        return 0xffffffffe00002c7;
      }
      iStack_140 = iStack_140 + 0x1000000;
    }
    else {
      if (param_4 < 0x1001) {
        if (param_4 != 0) {
          return 0xffffffffe00002bc;
        }
        pdStack_d8 = (dword *)(iVar14 + 0x4c);
        iStack_ec = 0;
        iStack_f0 = 0;
        dStack_fc = 0;
        iStack_140 = 0xd000000;
        goto LAB_000056ac;
      }
      if (param_4 == 0x3000) {
        puVar55 = *(undefined4 **)(param_6 + 0x28);
        iStack_ec = 0;
        iStack_f0 = 0;
        pdStack_d8 = puVar55 + 3;
        iStack_140 = 0x8000000;
        dStack_fc = *(dword *)*puVar55;
        *(int *)(iVar14 + 0x94) = *(int *)(iVar14 + 0x94) + 1;
        sStack_348 = *(short *)(puVar55 + 4);
      }
      else {
        if (param_4 != 0x7000) {
          return 0xffffffffe00002bc;
        }
        adStack_354[1] = 0x800;
        uStack_368 = 0x30;
        adStack_354[0] = param_6;
        dStack_fc = param_6;
        uVar13 = _io_connect_method_scalarI_structureO
                           (*(undefined4 *)(iVar14 + 0xc),2,adStack_354,2,adStack_354 + 2,
                            &uStack_368);
        if ((int)uVar13 != 0) {
          return uVar13;
        }
        iStack_ec = 0;
        iStack_f0 = 0;
        iStack_140 = 0xc000000;
        pdStack_d8 = adStack_354 + 2;
      }
    }
    puVar11 = PTR_0000e694;
    piStack_d4 = piVar21 + 3;
    if (iVar37 == 0) {
      piStack_d4 = piVar21 + 1;
      iVar37 = 1;
    }
    uStack_e8 = *(int *)(param_5 + 0x5c) - (int)*(short *)((int)piVar21 + 6);
    dStack_304 = pdStack_d8[2];
    dVar3 = pdStack_d8[4];
    iStack_e4 = *(int *)(param_5 + 0x58) - (int)*(short *)(piVar21 + 1);
    dVar4 = pdStack_d8[7];
    dStack_f4 = pdStack_d8[9];
    dStack_2fc = pdStack_d8[3];
    if ((dStack_304 != (int)sStack_348) ||
       (iStack_144 = 0, dStack_2fc != (int)*(short *)((int)pdStack_d8 + 6))) {
      iStack_144 = 1;
    }
    if (dStack_f4 == 3) {
      dStack_f4 = 0xb;
    }
    else if (dStack_f4 == 6) {
      dStack_f4 = 0xc;
    }
    uStack_314 = (int)sStack_348 ^ 0x80000000;
    uStack_318 = 0x43300000;
    uStack_300 = 0x43300000;
    uStack_310 = 0x43300000;
    uStack_308 = 0x43300000;
    uStack_30c = (int)*(short *)((int)pdStack_d8 + 6) ^ 0x80000000;
    dVar63 = (double)((float)((double)CONCAT44(0x43300000,uStack_314) - DOUBLE_0000cfe0) /
                     (float)((double)CONCAT44(0x43300000,dStack_304) - DOUBLE_0000cfd8));
    dVar62 = (double)((float)((double)CONCAT44(0x43300000,uStack_30c) - DOUBLE_0000cfe0) /
                     (float)((double)CONCAT44(0x43300000,dStack_2fc) - DOUBLE_0000cfd8));
    uVar18 = uVar38 - (longlong)((int)(uVar48 - (iVar15 + 0x20)) >> 2);
    while ((uVar54 & 0x1f) != 0) {
      puVar55 = (undefined4 *)uVar54;
      if ((int)uVar18 == 0) {
        fStack_364 = *(float *)(param_1 + 0x18);
        fStack_360 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *puVar55 = 0x5c8;
          fStack_360 = 2.8026e-45;
          puVar55[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        puVar55[(int)fStack_360] = 0x1000000;
        puVar5 = *(uint **)(param_1 + 0x7c);
        *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_360 | *puVar5;
        iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                     &fStack_364,&fStack_360,1);
        if (iVar15 == 0) {
          *(undefined4 *)((int)fStack_364 + 0x1c) = 0;
          *(float *)(param_1 + 0x18) = fStack_364;
          uVar54 = (ulonglong)(uint)fStack_364 + 0x20;
          *(int *)(param_1 + 0x7c) = (int)fStack_364 + 0x1c;
          uVar18 = uVar38;
        }
        else {
          uVar54 = 0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          *(undefined4 *)(param_1 + 0x18) = 0;
          uVar18 = uVar38;
        }
      }
      else {
        *puVar55 = 0x80000000;
        uVar54 = uVar54 + 4;
        uVar18 = uVar18 - 1;
      }
    }
    if ((iStack_144 == 0) && (dStack_f4 == *(dword *)(param_1 + 0x70))) {
      iStack_e4 = iStack_e4 + *(int *)(param_1 + 0x60);
      uStack_e8 = uStack_e8 + *(int *)(param_1 + 100);
    }
    dStack_100 = 1;
    if (pdStack_d8[10] != 1) {
      dStack_100 = (uint)(pdStack_d8[10] == 2) << 1;
    }
    sVar46 = *(short *)(pdStack_d8 + 1);
    if (((bVar1) || (param_4 == 0)) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar15 = ((int (*)())_createOffscreenBuffer)(param_1,pdStack_d8,0);
      if (iVar15 == 0) goto LAB_000081e0;
      puStack_dc = DAT_0000e6e4 + 3;
      uStack_f8 = DAT_0000e6e4[0xc];
      if (uStack_f8 == 3) {
        uStack_f8 = 0xb;
      }
      else if (uStack_f8 == 6) {
        uStack_f8 = 0xc;
      }
      if (iVar37 != 0) {
        pfStack_ac = &fStack_358;
        pfStack_b8 = &fStack_364;
        pfStack_b4 = &fStack_360;
        uStack_c8 = 0xc000;
        piStack_a8 = piStack_d4;
        pfStack_b0 = &fStack_35c;
        iStack_e0 = 0;
        bVar9 = true;
        uStack_c4 = dStack_f4 & 0x1f | 0x53000;
        dVar62 = DOUBLE_0000cfe8;
        dVar63 = DOUBLE_0000cfe0;
        do {
          uStack_2f8 = 0x43300000;
          uStack_2f4 = iStack_ec + *(short *)piStack_a8 ^ 0x80000000;
          uStack_2f0 = 0x43300000;
          uStack_2ec = iStack_f0 + (short)*piStack_a8 ^ 0x80000000;
          dVar58 = (double)CONCAT44(0x43300000,uStack_2f4) - dVar63;
          uStack_2e8 = 0x43300000;
          uStack_2e4 = (int)*(short *)(piStack_a8 + 1) ^ 0x80000000;
          dVar64 = (double)(float)dVar58;
          uStack_2e0 = 0x43300000;
          dVar59 = (double)CONCAT44(0x43300000,uStack_2ec) - dVar63;
          uStack_2dc = (int)*(short *)((int)piStack_a8 + 6) ^ 0x80000000;
          dVar65 = (double)(float)dVar59;
          dVar60 = dVar64 + (double)(float)((double)CONCAT44(0x43300000,uStack_2e4) - dVar63);
          dVar66 = (double)(float)dVar60;
          dVar61 = dVar65 + (double)(float)((double)CONCAT44(0x43300000,uStack_2dc) - dVar63);
          dVar67 = (double)(float)dVar61;
          if (DOUBLE_0000cff0 <= dVar64) {
            lStack_2d0 = (longlong)(int)(dVar64 - DOUBLE_0000cff0);
            uStack_104 = (int)(dVar64 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_104 = (uint)dVar58;
            lStack_2d8 = (longlong)(int)uStack_104;
          }
          if (DOUBLE_0000cff0 <= dVar65) {
            lStack_2c0 = (longlong)(int)(dVar65 - DOUBLE_0000cff0);
            uStack_108 = (int)(dVar65 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_108 = (uint)dVar59;
            lStack_2c8 = (longlong)(int)uStack_108;
          }
          if (DOUBLE_0000cff0 <= dVar66) {
            lStack_2b0 = (longlong)(int)(dVar66 - DOUBLE_0000cff0);
            uStack_10c = (int)(dVar66 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_10c = (uint)dVar60;
            lStack_2b8 = (longlong)(int)uStack_10c;
          }
          if (DOUBLE_0000cff0 <= dVar67) {
            lStack_2a0 = (longlong)(int)(dVar67 - DOUBLE_0000cff0);
            uStack_110 = (int)(dVar67 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            uStack_110 = (uint)dVar61;
            lStack_2a8 = (longlong)(int)uStack_110;
          }
          puVar55 = (undefined4 *)uVar54;
          if (bVar9) {
            if ((uVar18 & 0xffffffff) < 0x8a) {
              fStack_360 = *(float *)(param_1 + 0x18);
              fStack_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar55 = 0x5c8;
                fStack_364 = 2.8026e-45;
                puVar55[1] = uStack_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar55[(int)fStack_364] = 0x1000000;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_364 | *puVar5;
              iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,pfStack_b4,pfStack_b8,1);
              if (iVar15 == 0) {
                *(undefined4 *)((int)fStack_360 + 0x1c) = 0;
                uVar54 = (ulonglong)(uint)fStack_360 + 0x20;
                *(float *)(param_1 + 0x18) = fStack_360;
                lVar28 = (ulonglong)(uint)fStack_360 + 0x24;
                *(int *)(param_1 + 0x7c) = (int)fStack_360 + 0x1c;
              }
              else {
LAB_00005e40:
                uVar54 = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                lVar28 = 4;
              }
LAB_00005e7c:
              bVar9 = true;
              uVar18 = uVar38;
            }
            else {
              lVar28 = uVar54 + 4;
              bVar9 = true;
            }
          }
          else {
            if ((uVar18 & 0xffffffff) < 0x22) {
              fStack_364 = *(float *)(param_1 + 0x18);
              fStack_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar55 = 0x5c8;
                fStack_360 = 2.8026e-45;
                puVar55[1] = uStack_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar55[(int)fStack_360] = 0x1000000;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_360 | *puVar5;
              iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,pfStack_b8,pfStack_b4,1);
              if (iVar15 != 0) goto LAB_00005e40;
              *(undefined4 *)((int)fStack_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = fStack_364;
              uVar54 = (ulonglong)(uint)fStack_364 + 0x20;
              lVar28 = (ulonglong)(uint)fStack_364 + 0x24;
              *(int *)(param_1 + 0x7c) = (int)fStack_364 + 0x1c;
              goto LAB_00005e7c;
            }
            lVar28 = uVar54 + 4;
            bVar9 = false;
          }
          puVar55 = (undefined4 *)uVar54;
          if (bVar1) {
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = (int)puVar55 - (int)puVar5 >> 2 | *puVar5;
            *(undefined4 **)(param_1 + 0x7c) = puVar55;
            *puVar55 = 0xa000000;
          }
          else {
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = (int)puVar55 - (int)puVar5 >> 2 | *puVar5;
            *(undefined4 **)(param_1 + 0x7c) = puVar55;
            *puVar55 = 0xe000000;
          }
          pdVar22 = (dword *)lVar28;
          lVar28 = lVar28 + 0x14;
          *pdVar22 = dStack_fc;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)(pdVar22 + 1) - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar22 + 1;
          pdVar22[1] = 0x10000000;
          pdVar22[2] = *(dword *)*DAT_0000e6e4;
          dVar3 = DAT_0000e6e4[7];
          pdVar22[4] = 6;
          pdVar22[3] = dVar3;
          puVar55 = (undefined4 *)lVar28;
          if (bVar9) {
            uVar12 = ((int (*)())_radeon3DCopySetup)(param_1,lVar28,pdStack_d8,dStack_f4,0,0,0,0);
            uVar54 = uVar12 + 1;
            uVar19 = uVar12 + 0x16;
            iVar15 = (int)((uVar12 & 0x3fffffff) << 2);
            uVar56 = uVar12 + 2;
            uVar33 = uVar12 + 3;
            uVar34 = uVar12 + 4;
            uVar20 = uVar12 + 5;
            uVar29 = uVar12 + 6;
            uVar24 = uVar12 + 7;
            uVar26 = uVar12 + 8;
            uVar35 = uVar12 + 9;
            uVar36 = uVar12 + 10;
            uVar39 = uVar12 + 0xb;
            uVar40 = uVar12 + 0xc;
            uVar41 = uVar12 + 0xd;
            uVar42 = uVar12 + 0xe;
            uVar43 = uVar12 + 0xf;
            uVar45 = uVar12 + 0x10;
            uVar47 = uVar12 + 0x11;
            uVar49 = uVar12 + 0x12;
            uVar51 = uVar12 + 0x13;
            uVar17 = uVar12 + 0x14;
            uVar12 = uVar12 + 0x15;
          }
          else {
            *puVar55 = 0x1120;
            sVar46 = *(short *)(pdStack_d8 + 1);
            iVar15 = *(short *)((int)pdStack_d8 + 6) + -1;
            puVar55[1] = (int)sVar46 - 1U & 0x7ff | iVar15 * 0x800 & 0x3ff800U | 0x80000000;
            puVar55[2] = 0x1130;
            puVar55[3] = uStack_c4;
            puVar55[4] = 0x1140;
            puVar55[5] = pdStack_d8[4] - 1 & 0x3fff | ((int)sVar46 - 1U) * 0x10 & 0x8000 |
                         iVar15 * 0x20 & 0x10000U;
            iVar15 = 0x18;
            uVar56 = 8;
            uVar33 = 9;
            uVar54 = 7;
            uVar34 = 10;
            uVar20 = 0xb;
            uVar29 = 0xc;
            uVar24 = 0xd;
            uVar26 = 0xe;
            uVar35 = 0xf;
            uVar36 = 0x10;
            uVar39 = 0x11;
            uVar40 = 0x12;
            uVar41 = 0x13;
            uVar42 = 0x14;
            uVar43 = 0x15;
            uVar45 = 0x16;
            uVar47 = 0x17;
            uVar49 = 0x18;
            uVar51 = 0x19;
            uVar17 = 0x1a;
            uVar12 = 0x1b;
            uVar19 = 0x1c;
          }
          *(undefined4 *)((int)puVar55 + iVar15) = 0x10f8;
          *(uint *)((int)puVar55 + (int)((uVar54 & 0xffffffff) << 2)) =
               uStack_104 & 0x1fff | (uStack_108 & 0x1fff) << 0xd;
          *(undefined4 *)((int)puVar55 + (int)((uVar56 & 0xffffffff) << 2)) = 0x10f9;
          *(uint *)((int)puVar55 + (int)((uVar33 & 0xffffffff) << 2)) =
               uStack_10c & 0x1fff | (uStack_110 & 0x1fff) << 0xd;
          *(undefined4 *)((int)puVar55 + (int)((uVar34 & 0xffffffff) << 2)) = 0xc00c3500;
          *(undefined4 *)((int)puVar55 + (int)((uVar20 & 0xffffffff) << 2)) = 0x4003d;
          uStack_298 = 0x43300000;
          uStack_294 = (int)*(short *)(pdStack_d8 + 1) ^ 0x80000000;
          fStack_358 = (float)(dVar64 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_294) - dVar63)
                                        ));
          uStack_290 = 0x43300000;
          uStack_28c = (int)*(short *)(pdStack_d8 + 1) ^ 0x80000000;
          fStack_35c = (float)(dVar66 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_28c) - dVar63)
                                        ));
          uStack_288 = 0x43300000;
          uStack_284 = (int)*(short *)((int)pdStack_d8 + 6) ^ 0x80000000;
          fStack_360 = (float)(dVar65 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_284) - dVar63)
                                        ));
          uStack_280 = 0x43300000;
          uStack_27c = (int)*(short *)((int)pdStack_d8 + 6) ^ 0x80000000;
          fStack_364 = (float)(dVar67 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_27c) - dVar63)
                                        ));
          *(uint *)((int)puVar55 + (int)((uVar29 & 0xffffffff) << 2)) =
               uStack_104 | uStack_110 << 0x10;
          fVar6 = *pfStack_ac;
          *(float *)((int)puVar55 + (int)((uVar24 & 0xffffffff) << 2)) = fVar6;
          fVar7 = *pfStack_b8;
          *(float *)((int)puVar55 + (int)((uVar26 & 0xffffffff) << 2)) = fVar7;
          *(uint *)((int)puVar55 + (int)((uVar35 & 0xffffffff) << 2)) =
               uStack_104 | uStack_108 << 0x10;
          *(float *)((int)puVar55 + (int)((uVar36 & 0xffffffff) << 2)) = fVar6;
          fVar6 = *pfStack_b4;
          *(float *)((int)puVar55 + (int)((uVar39 & 0xffffffff) << 2)) = fVar6;
          *(uint *)((int)puVar55 + (int)((uVar40 & 0xffffffff) << 2)) =
               uStack_10c | uStack_108 << 0x10;
          fVar8 = *pfStack_b0;
          *(float *)((int)puVar55 + (int)((uVar41 & 0xffffffff) << 2)) = fVar8;
          *(float *)((int)puVar55 + (int)((uVar42 & 0xffffffff) << 2)) = fVar6;
          *(uint *)((int)puVar55 + (int)((uVar43 & 0xffffffff) << 2)) =
               uStack_10c | uStack_110 << 0x10;
          *(float *)((int)puVar55 + (int)((uVar45 & 0xffffffff) << 2)) = fVar8;
          *(float *)((int)puVar55 + (int)((uVar47 & 0xffffffff) << 2)) = fVar7;
          *(undefined4 *)((int)puVar55 + (int)((uVar49 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)((int)puVar55 + (int)((uVar51 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)((int)puVar55 + (int)((uVar17 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)((int)puVar55 + (int)((uVar12 & 0xffffffff) << 2)) = 0x20000;
          uVar54 = (uVar18 - 6) - uVar19;
          lVar28 = lVar28 + (uVar19 & 0x3fffffff) * 4;
          uVar53 = iStack_e4 + *(short *)piStack_a8;
          uVar48 = uVar53 + (int)*(short *)(piStack_a8 + 1);
          iVar14 = uStack_e8 + (int)(short)*piStack_a8;
          iVar15 = iVar14 + *(short *)((int)piStack_a8 + 6);
          if ((uVar54 & 0xffffffff) < 0x22) {
            fStack_35c = *(float *)(param_1 + 0x18);
            fStack_358 = 0.0;
            puVar55 = (undefined4 *)lVar28;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *puVar55 = 0x5c8;
              fStack_358 = 2.8026e-45;
              puVar55[1] = uStack_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar11 = PTR_0000e694;
            puVar55[(int)fStack_358] = 0x1000000;
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_358 | *puVar5;
            iVar16 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                         pfStack_b0,pfStack_ac,1);
            if (iVar16 == 0) {
              *(undefined4 *)((int)fStack_35c + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = fStack_35c;
              lVar28 = (ulonglong)(uint)fStack_35c + 0x20;
              lVar30 = (ulonglong)(uint)fStack_35c + 0x24;
              *(int *)(param_1 + 0x7c) = (int)fStack_35c + 0x1c;
            }
            else {
              lVar28 = 0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              lVar30 = 4;
            }
            bVar9 = true;
            uVar54 = uVar38;
          }
          else {
            lVar30 = lVar28 + 4;
            bVar9 = false;
          }
          puVar55 = (undefined4 *)lVar28;
          if (bVar1) {
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = (int)puVar55 - (int)puVar5 >> 2 | *puVar5;
            *(undefined4 **)(param_1 + 0x7c) = puVar55;
            *puVar55 = 0x11000000;
          }
          else {
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = (int)puVar55 - (int)puVar5 >> 2 | *puVar5;
            *(undefined4 **)(param_1 + 0x7c) = puVar55;
            *puVar55 = 0x12000000;
          }
          pdVar22 = (dword *)lVar30;
          pdVar22[1] = 0;
          pdVar22[2] = 0;
          lVar30 = lVar30 + 0x14;
          *pdVar22 = dStack_fc;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)(pdVar22 + 3) - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar22 + 3;
          pdVar22[3] = 0x4000000;
          pdVar22[4] = *(dword *)*DAT_0000e6e4;
          puVar55 = (undefined4 *)lVar30;
          if (bVar9) {
            uVar12 = ((int (*)())_radeon3DCopySetup)(param_1,lVar30,puStack_dc,uStack_f8,0,0,0,0);
            uVar24 = uVar12 + 4;
            uVar33 = uVar12 + 9;
            iStack_158 = (int)uVar12;
            iStack_15c = iStack_158 + 3;
            iStack_154 = iStack_158 + 1;
            iStack_158 = iStack_158 + 2;
            uVar17 = uVar12 + 0x16;
            iVar16 = (int)((uVar12 & 0x3fffffff) << 2);
            uVar19 = uVar12 + 5;
            uVar29 = uVar12 + 6;
            uVar20 = uVar12 + 7;
            uVar26 = uVar12 + 8;
            uVar47 = uVar12 + 10;
            uVar34 = uVar12 + 0xb;
            uVar35 = uVar12 + 0xc;
            uVar36 = uVar12 + 0xd;
            uVar39 = uVar12 + 0xe;
            uVar40 = uVar12 + 0xf;
            uVar41 = uVar12 + 0x10;
            uVar42 = uVar12 + 0x11;
            uVar43 = uVar12 + 0x12;
            uVar45 = uVar12 + 0x13;
            uVar18 = uVar12 + 0x14;
            uVar12 = uVar12 + 0x15;
          }
          else {
            *puVar55 = 0x1120;
            sVar46 = *(short *)(puStack_dc + 1);
            iVar16 = *(short *)((int)puStack_dc + 6) + -1;
            puVar55[1] = (int)sVar46 - 1U & 0x7ff | iVar16 * 0x800 & 0x3ff800U | 0x80000000;
            puVar55[2] = 0x1130;
            puVar55[3] = uStack_f8 & 0x1f | 0x53000;
            puVar55[4] = 0x1140;
            puVar55[5] = puStack_dc[4] - 1 & 0x3fff | ((int)sVar46 - 1U) * 0x10 & 0x8000 |
                         iVar16 * 0x20 & 0x10000U;
            uVar24 = 10;
            iStack_15c = 9;
            iVar16 = 0x18;
            uVar33 = 0xf;
            iStack_154 = 7;
            uVar19 = 0xb;
            iStack_158 = 8;
            uVar20 = 0xd;
            uVar29 = 0xc;
            uVar26 = 0xe;
            uVar47 = 0x10;
            uVar34 = 0x11;
            uVar35 = 0x12;
            uVar36 = 0x13;
            uVar39 = 0x14;
            uVar40 = 0x15;
            uVar41 = 0x16;
            uVar42 = 0x17;
            uVar43 = 0x18;
            uVar45 = 0x19;
            uVar18 = 0x1a;
            uVar12 = 0x1b;
            uVar17 = 0x1c;
          }
          *(undefined4 *)((int)puVar55 + iVar16) = 0x10f8;
          puVar55[iStack_154] = uVar53 & 0x1fff | iVar14 * 0x2000 & 0x3ffe000U;
          puVar55[iStack_158] = 0x10f9;
          puVar55[iStack_15c] = uVar48 & 0x1fff | iVar15 * 0x2000 & 0x3ffe000U;
          *(undefined4 *)((int)puVar55 + (int)((uVar24 & 0xffffffff) << 2)) = 0xc00c3500;
          *(undefined4 *)((int)puVar55 + (int)((uVar19 & 0xffffffff) << 2)) = 0x4003d;
          uVar44 = iVar15 * 0x10000;
          uStack_278 = 0x43300000;
          uStack_274 = (int)*(short *)(puStack_dc + 1) ^ 0x80000000;
          fStack_364 = (float)(dVar64 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_274) - dVar63)
                                        ));
          uStack_270 = 0x43300000;
          uStack_26c = (int)*(short *)(puStack_dc + 1) ^ 0x80000000;
          fStack_360 = (float)(dVar66 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_26c) - dVar63)
                                        ));
          uStack_268 = 0x43300000;
          uStack_264 = (int)*(short *)((int)puStack_dc + 6) ^ 0x80000000;
          fStack_358 = (float)(dVar65 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_264) - dVar63)
                                        ));
          uStack_260 = 0x43300000;
          uStack_25c = (int)*(short *)((int)puStack_dc + 6) ^ 0x80000000;
          fStack_35c = (float)(dVar67 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_25c) - dVar63)
                                        ));
          *(uint *)((int)puVar55 + (int)((uVar29 & 0xffffffff) << 2)) = uVar53 | uVar44;
          fVar6 = *pfStack_b8;
          *(float *)((int)puVar55 + (int)((uVar20 & 0xffffffff) << 2)) = fVar6;
          fVar7 = *pfStack_b0;
          *(float *)((int)puVar55 + (int)((uVar26 & 0xffffffff) << 2)) = fVar7;
          *(uint *)((int)puVar55 + (int)((uVar33 & 0xffffffff) << 2)) = uVar53 | iVar14 * 0x10000;
          *(float *)((int)puVar55 + (int)((uVar47 & 0xffffffff) << 2)) = fVar6;
          fVar6 = *pfStack_ac;
          *(float *)((int)puVar55 + (int)((uVar34 & 0xffffffff) << 2)) = fVar6;
          *(uint *)((int)puVar55 + (int)((uVar35 & 0xffffffff) << 2)) = uVar48 | iVar14 * 0x10000;
          fVar8 = *pfStack_b4;
          *(float *)((int)puVar55 + (int)((uVar36 & 0xffffffff) << 2)) = fVar8;
          *(float *)((int)puVar55 + (int)((uVar39 & 0xffffffff) << 2)) = fVar6;
          *(uint *)((int)puVar55 + (int)((uVar40 & 0xffffffff) << 2)) = uVar48 | uVar44;
          *(float *)((int)puVar55 + (int)((uVar41 & 0xffffffff) << 2)) = fVar8;
          *(float *)((int)puVar55 + (int)((uVar42 & 0xffffffff) << 2)) = fVar7;
          *(undefined4 *)((int)puVar55 + (int)((uVar43 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)((int)puVar55 + (int)((uVar45 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)((int)puVar55 + (int)((uVar18 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)((int)puVar55 + (int)((uVar12 & 0xffffffff) << 2)) = 0x20000;
          uVar18 = (uVar54 - 6) - uVar17;
          uVar54 = lVar30 + (uVar17 & 0x3fffffff) * 4;
          iStack_e0 = iStack_e0 + 1;
          piStack_a8 = piStack_a8 + 2;
          bVar9 = false;
        } while (iVar37 != iStack_e0);
      }
    }
    else if (sVar46 < 0x1001) {
      if (iVar37 != 0) {
        dStack_114 = dVar3 * dVar4 * 0x1000;
        pfStack_b0 = &fStack_35c;
        pfStack_b8 = &fStack_364;
        pfStack_b4 = &fStack_360;
        pfStack_ac = &fStack_358;
        iStack_170 = 0;
        bVar1 = true;
        piVar21 = piStack_d4;
        do {
          psStack_160 = (short *)((int)piVar21 + 2);
          psStack_164 = (short *)((int)piVar21 + 6);
          uStack_258 = 0x43300000;
          uStack_254 = iStack_ec + *(short *)piVar21 ^ 0x80000000;
          uVar53 = iStack_e4 + *(short *)piVar21;
          uStack_250 = 0x43300000;
          iVar14 = uStack_e8 + (int)(short)*piVar21;
          uStack_24c = iStack_f0 + (short)*piVar21 ^ 0x80000000;
          uStack_248 = 0x43300000;
          uStack_244 = (int)*(short *)(piVar21 + 1) ^ 0x80000000;
          uVar48 = uVar53 + (int)*(short *)(piVar21 + 1);
          fVar6 = (float)((double)CONCAT44(0x43300000,uStack_254) - DOUBLE_0000cfe0);
          uStack_240 = 0x43300000;
          uStack_23c = (int)*(short *)((int)piVar21 + 6) ^ 0x80000000;
          uVar44 = iVar14 + *(short *)((int)piVar21 + 6);
          fVar7 = (float)((double)CONCAT44(0x43300000,uStack_24c) - DOUBLE_0000cfe0);
          sVar46 = *(short *)((int)pdStack_d8 + 6);
          iVar15 = (int)sVar46;
          fVar8 = fVar7 + (float)((double)CONCAT44(0x43300000,uStack_23c) - DOUBLE_0000cfe0);
          if (iVar15 < 0x1000) {
            uStack_238 = 0x43300000;
            fVar2 = (float)((double)CONCAT44(0x43300000,iVar15) - DOUBLE_0000cfd8);
            iStack_234 = iVar15;
          }
          else {
            fVar2 = FLOAT_0000d004;
            if (FLOAT_0000d004 <= fVar8) {
              sVar46 = 0x1000;
              uVar44 = uStack_e8 + 0x1000;
              fVar8 = FLOAT_0000d004;
            }
            else {
              sVar46 = 0x1000;
            }
          }
          uStack_230 = 0x43300000;
          uStack_22c = (int)*(short *)(pdStack_d8 + 1) ^ 0x80000000;
          fVar2 = (float)(dVar62 * (double)(FLOAT_0000d000 / fVar2));
          dVar58 = (double)(fVar8 * fVar2);
          dVar59 = (double)(fVar7 * fVar2);
          fVar7 = (float)(dVar63 * (double)(FLOAT_0000d000 /
                                           (float)((double)CONCAT44(0x43300000,uStack_22c) -
                                                  DOUBLE_0000cfe0)));
          dVar60 = (double)((fVar6 + (float)((double)CONCAT44(0x43300000,uStack_244) -
                                            DOUBLE_0000cfe0)) * fVar7);
          dVar61 = (double)(fVar6 * fVar7);
          puVar55 = (undefined4 *)uVar54;
          if (bVar1) {
            if ((uVar18 & 0xffffffff) < 0x8a) {
              fStack_360 = *(float *)(param_1 + 0x18);
              fStack_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar55 = 0x5c8;
                fStack_364 = 2.8026e-45;
                puVar55[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar55[(int)fStack_364] = 0x1000000;
              puVar11 = PTR_0000e694;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_364 | *puVar5;
              iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                           pfStack_b4,pfStack_b8,1);
              if (iVar15 == 0) {
                *(undefined4 *)((int)fStack_360 + 0x1c) = 0;
                uVar54 = (ulonglong)(uint)fStack_360 + 0x20;
                *(float *)(param_1 + 0x18) = fStack_360;
                uVar12 = (ulonglong)(uint)fStack_360 + 0x38;
                pdVar22 = (dword *)((int)fStack_360 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)fStack_360 + 0x1c;
                pdVar25 = (dword *)((int)fStack_360 + 0x28);
                pdVar27 = (dword *)((int)fStack_360 + 0x2c);
                pdVar31 = (dword *)((int)fStack_360 + 0x30);
                pdVar32 = (dword *)((int)fStack_360 + 0x34);
                uVar18 = uVar38;
              }
              else {
LAB_00006cc0:
                uVar54 = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar22 = &__mh_bundle_header.cputype;
                pdVar25 = &__mh_bundle_header.cpusubtype;
                pdVar27 = &__mh_bundle_header.filetype;
                pdVar31 = &__mh_bundle_header.ncmds;
                pdVar32 = &__mh_bundle_header.sizeofcmds;
                uVar12 = 0x18;
                uVar18 = uVar38;
              }
            }
            else {
              pdVar22 = puVar55 + 1;
              pdVar25 = puVar55 + 2;
              pdVar27 = puVar55 + 3;
              pdVar31 = puVar55 + 4;
              pdVar32 = puVar55 + 5;
              uVar12 = uVar54 + 0x18;
            }
LAB_00006d28:
            puVar5 = *(uint **)(param_1 + 0x7c);
            piVar23 = (int *)uVar54;
            *puVar5 = (int)piVar23 - (int)puVar5 >> 2 | *puVar5;
            *(int **)(param_1 + 0x7c) = piVar23;
            *piVar23 = iStack_140;
            *pdVar22 = dStack_fc;
            *pdVar25 = dStack_100;
            *pdVar27 = 0;
            *pdVar31 = 0;
            *pdVar32 = 0;
            uVar18 = uVar18 - 6;
            uVar20 = ((int (*)())_radeon3DCopySetup)(param_1,uVar12,pdStack_d8,dStack_f4,iStack_144,0,0,sVar46);
            iStack_150 = (int)uVar20;
            iStack_148 = iStack_150 + 0xe;
            iStack_14c = iStack_150 + 0xf;
            uVar26 = uVar20 + 0x16;
            iVar15 = (int)((uVar20 & 0x3fffffff) << 2);
            iStack_150 = iStack_150 + 0x10;
            uVar19 = uVar20 + 0x11;
            uVar17 = uVar20 + 0x12;
            uVar35 = uVar20 + 1;
            uVar36 = uVar20 + 2;
            uVar34 = uVar20 + 3;
            uVar29 = uVar20 + 4;
            uVar33 = uVar20 + 5;
            uVar40 = uVar20 + 6;
            uVar41 = uVar20 + 7;
            uVar42 = uVar20 + 8;
            uVar43 = uVar20 + 9;
            uVar45 = uVar20 + 10;
            uVar47 = uVar20 + 0xb;
            uVar49 = uVar20 + 0xc;
            uVar24 = uVar20 + 0xd;
            uVar51 = uVar20 + 0x13;
            uVar39 = uVar20 + 0x14;
            uVar20 = uVar20 + 0x15;
            uVar54 = uVar12;
          }
          else {
            if ((uVar18 & 0xffffffff) < 0x16) {
              fStack_364 = *(float *)(param_1 + 0x18);
              fStack_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar55 = 0x5c8;
                fStack_360 = 2.8026e-45;
                puVar55[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar55[(int)fStack_360] = 0x1000000;
              puVar11 = PTR_0000e694;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_360 | *puVar5;
              iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                           pfStack_b8,pfStack_b4,1);
              if (iVar15 != 0) goto LAB_00006cc0;
              *(undefined4 *)((int)fStack_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = fStack_364;
              uVar54 = (ulonglong)(uint)fStack_364 + 0x20;
              uVar12 = (ulonglong)(uint)fStack_364 + 0x38;
              *(int *)(param_1 + 0x7c) = (int)fStack_364 + 0x1c;
              pdVar22 = (dword *)((int)fStack_364 + 0x24);
              pdVar25 = (dword *)((int)fStack_364 + 0x28);
              pdVar27 = (dword *)((int)fStack_364 + 0x2c);
              pdVar31 = (dword *)((int)fStack_364 + 0x30);
              pdVar32 = (dword *)((int)fStack_364 + 0x34);
              uVar18 = uVar38;
              goto LAB_00006d28;
            }
            iVar15 = 0;
            uVar35 = 1;
            iStack_148 = 0xe;
            iStack_14c = 0xf;
            uVar19 = 0x11;
            iStack_150 = 0x10;
            uVar36 = 2;
            uVar34 = 3;
            uVar17 = 0x12;
            uVar29 = 4;
            uVar33 = 5;
            uVar40 = 6;
            uVar41 = 7;
            uVar42 = 8;
            uVar43 = 9;
            uVar45 = 10;
            uVar47 = 0xb;
            uVar49 = 0xc;
            uVar24 = 0xd;
            uVar51 = 0x13;
            uVar39 = 0x14;
            uVar20 = 0x15;
            uVar26 = 0x16;
          }
          iVar16 = (int)uVar54;
          *(undefined4 *)(iVar16 + iVar15) = 0x10f8;
          uStack_cc = uVar53 & 0x1fff;
          *(uint *)(iVar16 + (int)((uVar35 & 0xffffffff) << 2)) =
               uStack_cc | iVar14 * 0x2000 & 0x3ffe000U;
          *(undefined4 *)(iVar16 + (int)((uVar36 & 0xffffffff) << 2)) = 0x10f9;
          uStack_d0 = uVar48 & 0x1fff;
          *(uint *)(iVar16 + (int)((uVar34 & 0xffffffff) << 2)) =
               uStack_d0 | (uVar44 & 0x1fff) << 0xd;
          fStack_360 = (float)dVar59;
          fStack_364 = (float)dVar58;
          fStack_35c = (float)dVar61;
          fStack_358 = (float)dVar60;
          *(undefined4 *)(iVar16 + (int)((uVar29 & 0xffffffff) << 2)) = 0xc00c3500;
          *(undefined4 *)(iVar16 + (int)((uVar33 & 0xffffffff) << 2)) = 0x4003d;
          *(uint *)(iVar16 + (int)((uVar40 & 0xffffffff) << 2)) = uVar53 | uVar44 << 0x10;
          fVar6 = *pfStack_b0;
          *(float *)(iVar16 + (int)((uVar41 & 0xffffffff) << 2)) = fVar6;
          fVar7 = *pfStack_b8;
          *(float *)(iVar16 + (int)((uVar42 & 0xffffffff) << 2)) = fVar7;
          *(uint *)(iVar16 + (int)((uVar43 & 0xffffffff) << 2)) = uVar53 | iVar14 * 0x10000;
          *(float *)(iVar16 + (int)((uVar45 & 0xffffffff) << 2)) = fVar6;
          fVar6 = *pfStack_b4;
          *(float *)(iVar16 + (int)((uVar47 & 0xffffffff) << 2)) = fVar6;
          *(uint *)(iVar16 + (int)((uVar49 & 0xffffffff) << 2)) = uVar48 | iVar14 * 0x10000;
          fVar8 = *pfStack_ac;
          *(float *)(iVar16 + (int)((uVar24 & 0xffffffff) << 2)) = fVar8;
          *(float *)(iVar16 + iStack_148 * 4) = fVar6;
          *(uint *)(iVar16 + iStack_14c * 4) = uVar48 | uVar44 << 0x10;
          *(float *)(iVar16 + iStack_150 * 4) = fVar8;
          *(float *)(iVar16 + (int)((uVar19 & 0xffffffff) << 2)) = fVar7;
          *(undefined4 *)(iVar16 + (int)((uVar17 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)(iVar16 + (int)((uVar51 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)(iVar16 + (int)((uVar39 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)(iVar16 + (int)((uVar20 & 0xffffffff) << 2)) = 0x20000;
          uVar18 = uVar18 - uVar26;
          bVar1 = false;
          uVar54 = uVar54 + (uVar26 & 0x3fffffff) * 4;
          iVar15 = (int)*psStack_160 + (int)*psStack_164;
          if (0xfff < iVar15) {
            uStack_228 = 0x43300000;
            uVar17 = (ulonglong)uStack_e8 + 0x1000;
            uVar12 = (ulonglong)uStack_e8 + (longlong)*psStack_160 + (longlong)*psStack_164;
            uStack_224 = (iStack_f0 + iVar15) - 0x1000U ^ 0x80000000;
            uStack_220 = 0x43300000;
            lVar28 = (longlong)*(short *)((int)pdStack_d8 + 6) + -0x1000;
            uStack_21c = (undefined4)lVar28;
            fVar6 = (float)(dVar62 * (double)(FLOAT_0000d000 /
                                             (float)((double)CONCAT44(0x43300000,uStack_21c) -
                                                    DOUBLE_0000cfd8)));
            dVar58 = (double)((float)((double)CONCAT44(0x43300000,uStack_224) - DOUBLE_0000cfe0) *
                             fVar6);
            dVar59 = (double)(fVar6 * FLOAT_0000d008);
            puVar55 = (undefined4 *)uVar54;
            if ((uVar18 & 0xffffffff) < 0x8a) {
              fStack_358 = *(float *)(param_1 + 0x18);
              fStack_35c = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *puVar55 = 0x5c8;
                fStack_35c = 2.8026e-45;
                puVar55[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              puVar55[(int)fStack_35c] = 0x1000000;
              puVar11 = PTR_0000e694;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_35c | *puVar5;
              iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                           pfStack_ac,pfStack_b0,1);
              if (iVar15 == 0) {
                *(undefined4 *)((int)fStack_358 + 0x1c) = 0;
                *(float *)(param_1 + 0x18) = fStack_358;
                uVar54 = (ulonglong)(uint)fStack_358 + 0x20;
                lVar30 = (ulonglong)(uint)fStack_358 + 0x38;
                *(int *)(param_1 + 0x7c) = (int)fStack_358 + 0x1c;
                pdVar22 = (dword *)((int)fStack_358 + 0x24);
                pdVar25 = (dword *)((int)fStack_358 + 0x28);
                pdVar27 = (dword *)((int)fStack_358 + 0x2c);
                pdVar31 = (dword *)((int)fStack_358 + 0x30);
                pdVar32 = (dword *)((int)fStack_358 + 0x34);
                uVar18 = uVar38;
              }
              else {
                uVar54 = 0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar22 = &__mh_bundle_header.cputype;
                pdVar25 = &__mh_bundle_header.cpusubtype;
                pdVar27 = &__mh_bundle_header.filetype;
                pdVar31 = &__mh_bundle_header.ncmds;
                pdVar32 = &__mh_bundle_header.sizeofcmds;
                lVar30 = 0x18;
                uVar18 = uVar38;
              }
            }
            else {
              pdVar22 = puVar55 + 1;
              pdVar25 = puVar55 + 2;
              pdVar27 = puVar55 + 3;
              pdVar31 = puVar55 + 4;
              pdVar32 = puVar55 + 5;
              lVar30 = uVar54 + 0x18;
            }
            puVar5 = *(uint **)(param_1 + 0x7c);
            piVar23 = (int *)uVar54;
            *puVar5 = (int)piVar23 - (int)puVar5 >> 2 | *puVar5;
            *(int **)(param_1 + 0x7c) = piVar23;
            *piVar23 = iStack_140;
            *pdVar22 = dStack_fc;
            *pdVar25 = dStack_100;
            *pdVar27 = dStack_114;
            *pdVar31 = 0;
            *pdVar32 = 0;
            uVar54 = ((int (*)())_radeon3DCopySetup)(param_1,lVar30,pdStack_d8,dStack_f4,iStack_144,0,0,lVar28);
            iVar15 = (int)lVar30;
            *(undefined4 *)(iVar15 + (int)((uVar54 & 0xffffffff) << 2)) = 0x10f8;
            *(uint *)(iVar15 + (int)((uVar54 + 1 & 0xffffffff) << 2)) =
                 uStack_cc | (uint)((uVar17 & 0xffffffff) << 0xd) & 0x3ffe000;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 2 & 0xffffffff) << 2)) = 0x10f9;
            *(uint *)(iVar15 + (int)((uVar54 + 3 & 0xffffffff) << 2)) =
                 uStack_d0 | (uint)((uVar12 & 0xffffffff) << 0xd) & 0x3ffe000;
            fStack_364 = (float)dVar61;
            fStack_360 = (float)dVar60;
            fStack_35c = (float)dVar59;
            fStack_358 = (float)dVar58;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 4 & 0xffffffff) << 2)) = 0xc00c3500;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 5 & 0xffffffff) << 2)) = 0x4003d;
            uVar44 = (uint)((uVar12 & 0xffffffff) << 0x10);
            *(uint *)(iVar15 + (int)((uVar54 + 6 & 0xffffffff) << 2)) = uVar53 | uVar44;
            *(float *)(iVar15 + (int)((uVar54 + 7 & 0xffffffff) << 2)) = fStack_364;
            *(float *)(iVar15 + (int)((uVar54 + 8 & 0xffffffff) << 2)) = fStack_358;
            uVar10 = (uint)((uVar17 & 0xffffffff) << 0x10);
            *(uint *)(iVar15 + (int)((uVar54 + 9 & 0xffffffff) << 2)) = uVar53 | uVar10;
            *(float *)(iVar15 + (int)((uVar54 + 10 & 0xffffffff) << 2)) = fStack_364;
            *(float *)(iVar15 + (int)((uVar54 + 0xb & 0xffffffff) << 2)) = fStack_35c;
            *(uint *)(iVar15 + (int)((uVar54 + 0xc & 0xffffffff) << 2)) = uVar48 | uVar10;
            *(float *)(iVar15 + (int)((uVar54 + 0xd & 0xffffffff) << 2)) = fStack_360;
            *(float *)(iVar15 + (int)((uVar54 + 0xe & 0xffffffff) << 2)) = fStack_35c;
            *(uint *)(iVar15 + (int)((uVar54 + 0xf & 0xffffffff) << 2)) = uVar48 | uVar44;
            *(float *)(iVar15 + (int)((uVar54 + 0x10 & 0xffffffff) << 2)) = fStack_360;
            *(float *)(iVar15 + (int)((uVar54 + 0x11 & 0xffffffff) << 2)) = fStack_358;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 0x12 & 0xffffffff) << 2)) = 0x1393;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 0x13 & 0xffffffff) << 2)) = 10;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 0x14 & 0xffffffff) << 2)) = 0x5c8;
            *(undefined4 *)(iVar15 + (int)((uVar54 + 0x15 & 0xffffffff) << 2)) = 0x20000;
            uVar18 = (uVar18 - 6) - (uVar54 + 0x16);
            bVar1 = true;
            uVar54 = lVar30 + (uVar54 + 0x16 & 0x3fffffff) * 4;
          }
          piVar21 = piVar21 + 2;
          iStack_170 = iStack_170 + 1;
        } while (iVar37 != iStack_170);
      }
    }
    else {
      uStack_120 = (int)sVar46 >> 1 & 0xfffffe00;
      uStack_11c = (int)sVar46 - uStack_120;
      uStack_118 = uStack_120 + 2;
      uStack_208 = 0x43300000;
      uStack_218 = 0x43300000;
      uStack_210 = 0x43300000;
      uStack_214 = (int)*(short *)((int)pdStack_d8 + 6) ^ 0x80000000;
      uStack_204 = uStack_11c ^ 0x80000000;
      uStack_20c = uStack_118 ^ 0x80000000;
      dVar58 = (double)(FLOAT_0000d000 /
                       (float)((double)CONCAT44(0x43300000,uStack_214) - DOUBLE_0000cfe0));
      dVar60 = (double)(FLOAT_0000d000 /
                       (float)((double)CONCAT44(0x43300000,uStack_204) - DOUBLE_0000cfe0));
      dVar61 = (double)(FLOAT_0000d000 /
                       (float)((double)CONCAT44(0x43300000,uStack_20c) - DOUBLE_0000cfe0));
      if (iVar37 != 0) {
        bVar1 = true;
        iStack_174 = 0;
        uStack_c0 = 0xc000;
        piStack_168 = piStack_d4;
        do {
          iVar15 = (int)*(short *)piStack_168;
          if (iStack_ec + iVar15 < (int)uStack_118) {
            uStack_1fc = iStack_ec + iVar15 ^ 0x80000000;
            uStack_200 = 0x43300000;
            uVar48 = iStack_ec + iVar15 + *(short *)(piStack_168 + 1);
            uStack_1f4 = uStack_118;
            if ((int)uVar48 < (int)uStack_118) {
              uStack_1f4 = uVar48;
            }
            uStack_1f4 = uStack_1f4 ^ 0x80000000;
            uStack_1f8 = 0x43300000;
            uStack_16c = iStack_e4 + iVar15;
            uVar48 = uStack_16c + (int)*(short *)(piStack_168 + 1);
            iVar15 = (int)(short)*piStack_168;
            uStack_1f0 = 0x43300000;
            uStack_1ec = iStack_f0 + iVar15 ^ 0x80000000;
            uStack_1e8 = 0x43300000;
            uStack_1e4 = iStack_f0 + iVar15 + *(short *)((int)piStack_168 + 6) ^ 0x80000000;
            if ((int)uStack_118 < (int)uVar48) {
              uStack_1e0 = 0x43300000;
              uStack_1dc = iStack_e4 + uStack_118 ^ 0x80000000;
              uVar48 = uStack_1dc;
            }
            else {
              uStack_1d4 = uVar48 ^ 0x80000000;
              uStack_1d8 = 0x43300000;
              uVar48 = uStack_1d4;
            }
            dVar59 = (double)CONCAT44(0x43300000,uVar48) - DOUBLE_0000cfe0;
            dVar64 = (double)(float)dVar59;
            if (DOUBLE_0000cff0 <= dVar64) {
              iVar14 = (int)(dVar64 - DOUBLE_0000cff0);
              lStack_1c8 = (longlong)iVar14;
              uStack_124 = iVar14 + 0x80000000;
            }
            else {
              uStack_124 = (uint)dVar59;
              lStack_1d0 = (longlong)(int)uStack_124;
            }
            dVar66 = (double)(float)(dVar63 * (double)(float)(dVar61 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1fc) - DOUBLE_0000cfe0)
                                                  ));
            dVar65 = (double)(float)(dVar63 * (double)(float)(dVar61 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1f4) - DOUBLE_0000cfe0)
                                                  ));
            dVar64 = (double)(float)(dVar62 * (double)(float)(dVar58 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1ec) - DOUBLE_0000cfe0)
                                                  ));
            dVar59 = (double)(float)(dVar62 * (double)(float)(dVar58 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1e4) - DOUBLE_0000cfe0)
                                                  ));
            uStack_128 = uStack_e8 + iVar15;
            uStack_12c = uStack_128 + (int)*(short *)((int)piStack_168 + 6);
            puVar55 = (undefined4 *)uVar54;
            if (bVar1) {
              if ((uVar18 & 0xffffffff) < 0x9e) {
                fStack_360 = *(float *)(param_1 + 0x18);
                fStack_364 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *puVar55 = 0x5c8;
                  fStack_364 = 2.8026e-45;
                  puVar55[1] = uStack_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                puVar55[(int)fStack_364] = 0x1000000;
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_364 | *puVar5;
                iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&fStack_360,&fStack_364,1);
                if (iVar15 == 0) {
                  *(undefined4 *)((int)fStack_360 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = fStack_360;
                  uVar54 = (ulonglong)(uint)fStack_360 + 0x20;
                  uVar17 = (ulonglong)(uint)fStack_360 + 0x38;
                  *(int *)(param_1 + 0x7c) = (int)fStack_360 + 0x1c;
                  pdVar22 = (dword *)((int)fStack_360 + 0x24);
                  pdVar25 = (dword *)((int)fStack_360 + 0x28);
                  pdVar27 = (dword *)((int)fStack_360 + 0x2c);
                  pdVar31 = (dword *)((int)fStack_360 + 0x30);
                  pdVar32 = (dword *)((int)fStack_360 + 0x34);
                  uVar18 = uVar38;
                }
                else {
                  uVar54 = 0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar22 = &__mh_bundle_header.cputype;
                  pdVar25 = &__mh_bundle_header.cpusubtype;
                  pdVar27 = &__mh_bundle_header.filetype;
                  pdVar31 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  uVar17 = 0x18;
                  uVar18 = uVar38;
                }
              }
              else {
                pdVar22 = puVar55 + 1;
                pdVar25 = puVar55 + 2;
                pdVar27 = puVar55 + 3;
                pdVar31 = puVar55 + 4;
                pdVar32 = puVar55 + 5;
                uVar17 = uVar54 + 0x18;
              }
              puVar5 = *(uint **)(param_1 + 0x7c);
              piVar21 = (int *)uVar54;
              *puVar5 = (int)piVar21 - (int)puVar5 >> 2 | *puVar5;
              *(int **)(param_1 + 0x7c) = piVar21;
              *piVar21 = iStack_140;
              *pdVar22 = dStack_fc;
              *pdVar25 = dStack_100;
              *pdVar27 = 0;
              *pdVar31 = 0;
              *pdVar32 = 0;
              uVar18 = uVar18 - 4;
              uVar19 = ((int (*)())_radeon3DCopySetup)(param_1,uVar17,pdStack_d8,dStack_f4,iStack_144,0,
                                          uStack_118,0);
LAB_0000789c:
              uVar20 = uVar19 + 9;
              uVar41 = uVar19 + 0x16;
              iVar15 = (int)((uVar19 & 0x3fffffff) << 2);
              uVar33 = uVar19 + 1;
              uVar34 = uVar19 + 2;
              uVar35 = uVar19 + 3;
              uVar57 = uVar19 + 4;
              uVar36 = uVar19 + 5;
              uVar42 = uVar19 + 6;
              uVar43 = uVar19 + 7;
              uVar29 = uVar19 + 8;
              uVar39 = uVar19 + 10;
              uVar45 = uVar19 + 0xb;
              uVar40 = uVar19 + 0xc;
              uVar47 = uVar19 + 0xd;
              uVar49 = uVar19 + 0xe;
              uVar51 = uVar19 + 0xf;
              uVar56 = uVar19 + 0x10;
              uVar50 = uVar19 + 0x11;
              uVar52 = uVar19 + 0x12;
              uVar24 = uVar19 + 0x13;
              uVar26 = uVar19 + 0x14;
              uVar19 = uVar19 + 0x15;
              uVar54 = uVar17;
            }
            else {
              if ((uVar18 & 0xffffffff) < 0x2a) {
                fStack_364 = *(float *)(param_1 + 0x18);
                fStack_360 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *puVar55 = 0x5c8;
                  fStack_360 = 2.8026e-45;
                  puVar55[1] = uStack_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                puVar55[(int)fStack_360] = 0x1000000;
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_360 | *puVar5;
                iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&fStack_364,&fStack_360,1);
                if (iVar15 == 0) {
                  *(undefined4 *)((int)fStack_364 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = fStack_364;
                  piVar21 = (int *)((int)fStack_364 + 0x20);
                  uVar17 = (ulonglong)(uint)fStack_364 + 0x38;
                  *(uint *)(param_1 + 0x7c) = (int)fStack_364 + 0x1c;
                  pdVar22 = (dword *)((int)fStack_364 + 0x24);
                  pdVar25 = (dword *)((int)fStack_364 + 0x28);
                  pdVar27 = (dword *)((int)fStack_364 + 0x2c);
                  pdVar31 = (dword *)((int)fStack_364 + 0x30);
                  pdVar32 = (dword *)((int)fStack_364 + 0x34);
                }
                else {
                  piVar21 = (int *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar22 = &__mh_bundle_header.cputype;
                  pdVar25 = &__mh_bundle_header.cpusubtype;
                  pdVar27 = &__mh_bundle_header.filetype;
                  pdVar31 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  uVar17 = 0x18;
                }
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = (int)piVar21 - (int)puVar5 >> 2 | *puVar5;
                *(int **)(param_1 + 0x7c) = piVar21;
                *piVar21 = iStack_140;
                *pdVar22 = dStack_fc;
                *pdVar25 = dStack_100;
                *pdVar27 = 0;
                *pdVar31 = 0;
                *pdVar32 = 0;
                uVar18 = uVar12 - 0xb;
                uVar19 = ((int (*)())_radeon3DCopySetup)(param_1,uVar17,pdStack_d8,dStack_f4,iStack_144,0,
                                            uStack_118,0);
                goto LAB_0000789c;
              }
              iVar15 = 0;
              uVar33 = 1;
              uVar34 = 2;
              uVar20 = 9;
              uVar35 = 3;
              uVar57 = 4;
              uVar36 = 5;
              uVar42 = 6;
              uVar43 = 7;
              uVar29 = 8;
              uVar39 = 10;
              uVar45 = 0xb;
              uVar40 = 0xc;
              uVar47 = 0xd;
              uVar49 = 0xe;
              uVar51 = 0xf;
              uVar56 = 0x10;
              uVar50 = 0x11;
              uVar52 = 0x12;
              uVar24 = 0x13;
              uVar26 = 0x14;
              uVar19 = 0x15;
              uVar41 = 0x16;
            }
            iVar14 = (int)uVar54;
            *(undefined4 *)(iVar14 + iVar15) = 0x10f8;
            *(uint *)(iVar14 + (int)((uVar33 & 0xffffffff) << 2)) =
                 uStack_16c & 0x1fff | (uStack_128 & 0x1fff) << 0xd;
            *(undefined4 *)(iVar14 + (int)((uVar34 & 0xffffffff) << 2)) = 0x10f9;
            *(uint *)(iVar14 + (int)((uVar35 & 0xffffffff) << 2)) =
                 uStack_124 & 0x1fff | (uStack_12c & 0x1fff) << 0xd;
            fStack_358 = (float)dVar66;
            fStack_35c = (float)dVar65;
            fStack_360 = (float)dVar64;
            fStack_364 = (float)dVar59;
            *(undefined4 *)(iVar14 + (int)((uVar57 & 0xffffffff) << 2)) = 0xc00c3500;
            *(undefined4 *)(iVar14 + (int)((uVar36 & 0xffffffff) << 2)) = 0x4003d;
            *(uint *)(iVar14 + (int)((uVar42 & 0xffffffff) << 2)) = uStack_16c | uStack_12c << 0x10;
            *(float *)(iVar14 + (int)((uVar43 & 0xffffffff) << 2)) = fStack_358;
            *(float *)(iVar14 + (int)((uVar29 & 0xffffffff) << 2)) = fStack_364;
            *(uint *)(iVar14 + (int)((uVar20 & 0xffffffff) << 2)) = uStack_16c | uStack_128 << 0x10;
            *(float *)(iVar14 + (int)((uVar39 & 0xffffffff) << 2)) = fStack_358;
            *(float *)(iVar14 + (int)((uVar45 & 0xffffffff) << 2)) = fStack_360;
            *(uint *)(iVar14 + (int)((uVar40 & 0xffffffff) << 2)) = uStack_124 | uStack_128 << 0x10;
            *(float *)(iVar14 + (int)((uVar47 & 0xffffffff) << 2)) = fStack_35c;
            *(float *)(iVar14 + (int)((uVar49 & 0xffffffff) << 2)) = fStack_360;
            *(uint *)(iVar14 + (int)((uVar51 & 0xffffffff) << 2)) = uStack_124 | uStack_12c << 0x10;
            *(float *)(iVar14 + (int)((uVar56 & 0xffffffff) << 2)) = fStack_35c;
            *(float *)(iVar14 + (int)((uVar50 & 0xffffffff) << 2)) = fStack_364;
            *(undefined4 *)(iVar14 + (int)((uVar52 & 0xffffffff) << 2)) = 0x1393;
            *(undefined4 *)(iVar14 + (int)((uVar24 & 0xffffffff) << 2)) = 10;
            *(undefined4 *)(iVar14 + (int)((uVar26 & 0xffffffff) << 2)) = 0x5c8;
            *(undefined4 *)(iVar14 + (int)((uVar19 & 0xffffffff) << 2)) = 0x20000;
            uVar18 = uVar18 - uVar41;
            bVar1 = false;
            uVar54 = uVar54 + (uVar41 & 0x3fffffff) * 4;
          }
          iStack_174 = iStack_174 + 1;
          piStack_168 = piStack_168 + 2;
        } while (iVar37 != iStack_174);
        bVar1 = true;
        iStack_178 = 0;
        uStack_bc = 0xc000;
        piVar21 = piStack_d4;
        do {
          iVar14 = (int)*(short *)piVar21;
          iVar15 = iVar14 + *(short *)(piVar21 + 1) + iStack_ec;
          if ((int)uStack_120 < iVar15) {
            uStack_1bc = uStack_120;
            if ((int)uStack_120 < iVar14 + iStack_ec) {
              uStack_1bc = iVar14 + iStack_ec;
            }
            uStack_1bc = uStack_1bc ^ 0x80000000;
            uStack_1b4 = uStack_120 ^ 0x80000000;
            uStack_1ac = iVar15 - uStack_120 ^ 0x80000000;
            uStack_134 = iStack_e4 + iVar14;
            uStack_1c0 = 0x43300000;
            uStack_1b8 = 0x43300000;
            uStack_1b0 = 0x43300000;
            iVar15 = (int)(short)*piVar21;
            uStack_1a8 = 0x43300000;
            uStack_1a4 = iVar15 + iStack_f0 ^ 0x80000000;
            uStack_1a0 = 0x43300000;
            uStack_19c = iVar15 + *(short *)((int)piVar21 + 6) + iStack_ec ^ 0x80000000;
            if ((int)uStack_120 < (int)uStack_134) {
              uStack_194 = uStack_134 ^ 0x80000000;
              uStack_198 = 0x43300000;
              uVar48 = uStack_194;
            }
            else {
              uStack_190 = 0x43300000;
              uStack_18c = iStack_e4 + uStack_120 ^ 0x80000000;
              uVar48 = uStack_18c;
            }
            dVar61 = (double)CONCAT44(0x43300000,uVar48) - DOUBLE_0000cfe0;
            dVar59 = (double)(float)dVar61;
            if (DOUBLE_0000cff0 <= dVar59) {
              iVar14 = (int)(dVar59 - DOUBLE_0000cff0);
              lStack_180 = (longlong)iVar14;
              uStack_130 = iVar14 + 0x80000000;
            }
            else {
              uStack_130 = (uint)dVar61;
              lStack_188 = (longlong)(int)uStack_130;
            }
            uStack_134 = uStack_134 + (int)*(short *)(piVar21 + 1);
            dVar65 = (double)(float)(dVar63 * (double)(float)(dVar60 * (double)((float)((double)
                                                  CONCAT44(0x43300000,uStack_1bc) - DOUBLE_0000cfe0)
                                                  - (float)((double)CONCAT44(0x43300000,uStack_1b4)
                                                           - DOUBLE_0000cfe0))));
            dVar64 = (double)(float)(dVar63 * (double)(float)(dVar60 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1ac) - DOUBLE_0000cfe0)
                                                  ));
            dVar59 = (double)(float)(dVar62 * (double)(float)(dVar58 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_1a4) - DOUBLE_0000cfe0)
                                                  ));
            dVar61 = (double)(float)(dVar62 * (double)(float)(dVar58 * (double)(float)((double)
                                                  CONCAT44(0x43300000,uStack_19c) - DOUBLE_0000cfe0)
                                                  ));
            uStack_138 = uStack_e8 + iVar15;
            uStack_13c = uStack_138 + (int)*(short *)((int)piVar21 + 6);
            puVar55 = (undefined4 *)uVar54;
            if (bVar1) {
              if ((uVar18 & 0xffffffff) < 0x9e) {
                fStack_35c = *(float *)(param_1 + 0x18);
                fStack_358 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *puVar55 = 0x5c8;
                  fStack_358 = 2.8026e-45;
                  puVar55[1] = uStack_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                puVar55[(int)fStack_358] = 0x1000000;
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_358 | *puVar5;
                iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&fStack_35c,&fStack_358,1);
                if (iVar15 == 0) {
                  *(undefined4 *)((int)fStack_35c + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = fStack_35c;
                  uVar54 = (ulonglong)(uint)fStack_35c + 0x20;
                  uVar17 = (ulonglong)(uint)fStack_35c + 0x38;
                  *(int *)(param_1 + 0x7c) = (int)fStack_35c + 0x1c;
                  pdVar22 = (dword *)((int)fStack_35c + 0x24);
                  pdVar25 = (dword *)((int)fStack_35c + 0x28);
                  pdVar27 = (dword *)((int)fStack_35c + 0x2c);
                  pdVar31 = (dword *)((int)fStack_35c + 0x30);
                  pdVar32 = (dword *)((int)fStack_35c + 0x34);
                  uVar18 = uVar38;
                }
                else {
                  uVar54 = 0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar22 = &__mh_bundle_header.cputype;
                  pdVar25 = &__mh_bundle_header.cpusubtype;
                  pdVar27 = &__mh_bundle_header.filetype;
                  pdVar31 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  uVar17 = 0x18;
                  uVar18 = uVar38;
                }
              }
              else {
                pdVar22 = puVar55 + 1;
                pdVar25 = puVar55 + 2;
                pdVar27 = puVar55 + 3;
                pdVar31 = puVar55 + 4;
                pdVar32 = puVar55 + 5;
                uVar17 = uVar54 + 0x18;
              }
              puVar5 = *(uint **)(param_1 + 0x7c);
              piVar23 = (int *)uVar54;
              *puVar5 = (int)piVar23 - (int)puVar5 >> 2 | *puVar5;
              *(int **)(param_1 + 0x7c) = piVar23;
              *piVar23 = iStack_140;
              *pdVar22 = dStack_fc;
              *pdVar25 = dStack_100;
              *pdVar27 = 0;
              *pdVar31 = pdStack_d8[0xb];
              *pdVar32 = uStack_120;
              uVar18 = uVar18 - 4;
              uVar19 = ((int (*)())_radeon3DCopySetup)(param_1,uVar17,pdStack_d8,dStack_f4,iStack_144,0,
                                          uStack_11c,0);
LAB_00007ff0:
              uVar20 = uVar19 + 9;
              uVar24 = uVar19 + 10;
              uVar41 = uVar19 + 0x16;
              iVar15 = (int)((uVar19 & 0x3fffffff) << 2);
              uVar34 = uVar19 + 1;
              uVar35 = uVar19 + 2;
              uVar36 = uVar19 + 3;
              uVar42 = uVar19 + 4;
              uVar43 = uVar19 + 5;
              uVar45 = uVar19 + 6;
              uVar47 = uVar19 + 7;
              uVar33 = uVar19 + 8;
              uVar49 = uVar19 + 0xb;
              uVar40 = uVar19 + 0xc;
              uVar51 = uVar19 + 0xd;
              uVar56 = uVar19 + 0xe;
              uVar57 = uVar19 + 0xf;
              uVar39 = uVar19 + 0x10;
              uVar50 = uVar19 + 0x11;
              uVar52 = uVar19 + 0x12;
              uVar26 = uVar19 + 0x13;
              uVar29 = uVar19 + 0x14;
              uVar19 = uVar19 + 0x15;
              uVar54 = uVar17;
            }
            else {
              if ((uVar18 & 0xffffffff) < 0x2a) {
                fStack_358 = *(float *)(param_1 + 0x18);
                fStack_35c = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *puVar55 = 0x5c8;
                  fStack_35c = 2.8026e-45;
                  puVar55[1] = uStack_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                puVar55[(int)fStack_35c] = 0x1000000;
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = ((int)puVar55 - (int)puVar5 >> 2) + (int)fStack_35c | *puVar5;
                iVar15 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&fStack_358,&fStack_35c,1);
                if (iVar15 == 0) {
                  *(undefined4 *)((int)fStack_358 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = fStack_358;
                  piVar23 = (int *)((int)fStack_358 + 0x20);
                  uVar17 = (ulonglong)(uint)fStack_358 + 0x38;
                  *(uint *)(param_1 + 0x7c) = (int)fStack_358 + 0x1c;
                  pdVar22 = (dword *)((int)fStack_358 + 0x24);
                  pdVar25 = (dword *)((int)fStack_358 + 0x28);
                  pdVar27 = (dword *)((int)fStack_358 + 0x2c);
                  pdVar31 = (dword *)((int)fStack_358 + 0x30);
                  pdVar32 = (dword *)((int)fStack_358 + 0x34);
                }
                else {
                  piVar23 = (int *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar22 = &__mh_bundle_header.cputype;
                  pdVar25 = &__mh_bundle_header.cpusubtype;
                  pdVar27 = &__mh_bundle_header.filetype;
                  pdVar31 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  uVar17 = 0x18;
                }
                puVar5 = *(uint **)(param_1 + 0x7c);
                *puVar5 = (int)piVar23 - (int)puVar5 >> 2 | *puVar5;
                *(int **)(param_1 + 0x7c) = piVar23;
                *piVar23 = iStack_140;
                *pdVar22 = dStack_fc;
                *pdVar25 = dStack_100;
                *pdVar27 = 0;
                *pdVar31 = pdStack_d8[0xb];
                *pdVar32 = uStack_120;
                uVar18 = uVar12 - 0xb;
                uVar19 = ((int (*)())_radeon3DCopySetup)(param_1,uVar17,pdStack_d8,dStack_f4,iStack_144,0,
                                            uStack_11c,0);
                goto LAB_00007ff0;
              }
              iVar15 = 0;
              uVar34 = 1;
              uVar20 = 9;
              uVar35 = 2;
              uVar36 = 3;
              uVar24 = 10;
              uVar42 = 4;
              uVar43 = 5;
              uVar45 = 6;
              uVar47 = 7;
              uVar33 = 8;
              uVar49 = 0xb;
              uVar40 = 0xc;
              uVar51 = 0xd;
              uVar56 = 0xe;
              uVar57 = 0xf;
              uVar39 = 0x10;
              uVar50 = 0x11;
              uVar52 = 0x12;
              uVar26 = 0x13;
              uVar29 = 0x14;
              uVar19 = 0x15;
              uVar41 = 0x16;
            }
            iVar14 = (int)uVar54;
            *(undefined4 *)(iVar14 + iVar15) = 0x10f8;
            *(uint *)(iVar14 + (int)((uVar34 & 0xffffffff) << 2)) =
                 uStack_130 & 0x1fff | (uStack_138 & 0x1fff) << 0xd;
            *(undefined4 *)(iVar14 + (int)((uVar35 & 0xffffffff) << 2)) = 0x10f9;
            *(uint *)(iVar14 + (int)((uVar36 & 0xffffffff) << 2)) =
                 uStack_134 & 0x1fff | (uStack_13c & 0x1fff) << 0xd;
            fStack_35c = (float)dVar65;
            fStack_360 = (float)dVar64;
            fStack_364 = (float)dVar59;
            fStack_358 = (float)dVar61;
            *(undefined4 *)(iVar14 + (int)((uVar42 & 0xffffffff) << 2)) = 0xc00c3500;
            *(undefined4 *)(iVar14 + (int)((uVar43 & 0xffffffff) << 2)) = 0x4003d;
            *(uint *)(iVar14 + (int)((uVar45 & 0xffffffff) << 2)) = uStack_130 | uStack_13c << 0x10;
            *(float *)(iVar14 + (int)((uVar47 & 0xffffffff) << 2)) = fStack_35c;
            *(float *)(iVar14 + (int)((uVar33 & 0xffffffff) << 2)) = fStack_358;
            *(uint *)(iVar14 + (int)((uVar20 & 0xffffffff) << 2)) = uStack_130 | uStack_138 << 0x10;
            *(float *)(iVar14 + (int)((uVar24 & 0xffffffff) << 2)) = fStack_35c;
            *(float *)(iVar14 + (int)((uVar49 & 0xffffffff) << 2)) = fStack_364;
            *(uint *)(iVar14 + (int)((uVar40 & 0xffffffff) << 2)) = uStack_134 | uStack_138 << 0x10;
            *(float *)(iVar14 + (int)((uVar51 & 0xffffffff) << 2)) = fStack_360;
            *(float *)(iVar14 + (int)((uVar56 & 0xffffffff) << 2)) = fStack_364;
            *(uint *)(iVar14 + (int)((uVar57 & 0xffffffff) << 2)) = uStack_134 | uStack_13c << 0x10;
            *(float *)(iVar14 + (int)((uVar39 & 0xffffffff) << 2)) = fStack_360;
            *(float *)(iVar14 + (int)((uVar50 & 0xffffffff) << 2)) = fStack_358;
            *(undefined4 *)(iVar14 + (int)((uVar52 & 0xffffffff) << 2)) = 0x1393;
            *(undefined4 *)(iVar14 + (int)((uVar26 & 0xffffffff) << 2)) = 10;
            *(undefined4 *)(iVar14 + (int)((uVar29 & 0xffffffff) << 2)) = 0x5c8;
            *(undefined4 *)(iVar14 + (int)((uVar19 & 0xffffffff) << 2)) = 0x20000;
            uVar18 = uVar18 - uVar41;
            bVar1 = false;
            uVar54 = uVar54 + (uVar41 & 0x3fffffff) * 4;
          }
          piVar21 = piVar21 + 2;
          iStack_178 = iStack_178 + 1;
        } while (iVar37 != iStack_178);
      }
    }
    uVar13 = 0;
    *(int *)(param_1 + 0x80) = (int)uVar54;
  }
  return uVar13;
}

/* _radeonFill @ 0x8260 (9000 bytes) */
undefined8 _radeonFill(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined8 param_1;
  undefined8 param_2;
  ulonglong param_3;
  uint param_4;
  longlong param_5;
  undefined8 param_6;
{
  uint *puVar1;
  float fVar2;
  uint uVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  undefined *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined4 uVar16;
  int iVar19;
  int iVar20;
  ulonglong uVar17;
  ulonglong uVar18;
  int iVar21;
  longlong lVar22;
  longlong lVar23;
  int iVar24;
  dword *pdVar25;
  dword *pdVar26;
  dword *pdVar27;
  longlong lVar28;
  int *piVar29;
  dword *pdVar30;
  ulonglong uVar31;
  uint uVar32;
  longlong lVar33;
  ulonglong uVar34;
  dword *pdVar35;
  ulonglong uVar36;
  int iVar37;
  longlong lVar38;
  ulonglong uVar39;
  ulonglong uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  longlong lVar44;
  longlong lVar45;
  longlong lVar46;
  longlong lVar47;
  longlong lVar48;
  uint uVar49;
  longlong lVar50;
  longlong lVar51;
  ulonglong uVar52;
  longlong lVar53;
  longlong lVar54;
  int iVar55;
  longlong lVar56;
  double dVar57;
  double dVar58;
  double dVar59;
  double dVar60;
  double dVar61;
  double dVar62;
  double dVar63;
  double dVar64;
  double dVar65;
  double dVar66;
  double dVar67;
  double dVar68;
  double dVar69;
  double dVar70;
  undefined4 uStack_308;
  float fStack_304;
  float fStack_300;
  undefined4 uStack_2fc;
  float fStack_2f8;
  float fStack_2f4;
  float fStack_2f0;
  float fStack_2ec;
  float fStack_2e8;
  float afStack_2e4 [3];
  undefined4 uStack_2d8;
  uint uStack_2d4;
  undefined4 uStack_2d0;
  uint uStack_2cc;
  undefined4 uStack_2c8;
  uint uStack_2c4;
  undefined4 uStack_2c0;
  uint uStack_2bc;
  undefined4 uStack_2b8;
  int iStack_2b4;
  undefined4 uStack_2b0;
  int iStack_2ac;
  undefined4 uStack_2a8;
  uint uStack_2a4;
  undefined4 uStack_2a0;
  uint uStack_29c;
  undefined4 uStack_298;
  uint uStack_294;
  undefined4 uStack_290;
  uint uStack_28c;
  undefined4 uStack_288;
  uint uStack_284;
  undefined4 uStack_280;
  uint uStack_27c;
  undefined4 uStack_278;
  uint uStack_274;
  undefined4 uStack_270;
  uint uStack_26c;
  undefined4 uStack_268;
  uint uStack_264;
  undefined4 uStack_260;
  uint uStack_25c;
  undefined4 uStack_258;
  uint uStack_254;
  undefined4 uStack_250;
  uint uStack_24c;
  undefined4 uStack_248;
  uint uStack_244;
  undefined4 uStack_240;
  uint uStack_23c;
  undefined4 uStack_238;
  uint uStack_234;
  undefined4 uStack_228;
  uint uStack_224;
  undefined4 uStack_218;
  uint uStack_214;
  undefined4 uStack_210;
  int iStack_20c;
  undefined4 uStack_208;
  uint uStack_204;
  undefined4 uStack_200;
  uint uStack_1fc;
  undefined4 uStack_1f8;
  int iStack_1f4;
  undefined4 uStack_1f0;
  uint uStack_1ec;
  undefined4 uStack_1e8;
  uint uStack_1e4;
  undefined4 uStack_1e0;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  uint uStack_1d4;
  undefined4 uStack_1d0;
  uint uStack_1cc;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_1a0;
  uint uStack_19c;
  undefined4 uStack_198;
  uint uStack_194;
  undefined4 uStack_190;
  uint uStack_18c;
  uint uStack_188;
  int iStack_184;
  int iStack_180;
  int iStack_17c;
  int iStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  int iStack_164;
  int iStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  int iStack_150;
  int iStack_14c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  int iStack_13c;
  int iStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  uint uStack_124;
  uint uStack_120;
  uint uStack_11c;
  uint uStack_118;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  int iStack_108;
  uint uStack_104;
  uint uStack_100;
  uint uStack_fc;
  short sStack_f8;
  short sStack_f6;
  int iStack_f4;
  int iStack_f0;
  undefined4 *puStack_ec;
  float *pfStack_e8;
  float *pfStack_e4;
  undefined4 *puStack_e0;
  float *pfStack_dc;
  float *pfStack_d8;
  float *pfStack_d4;
  float *pfStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  float *pfStack_c0;
  uint uStack_bc;
  
  uVar14 = ZEXT48(&STACKARG(0x0));
  param_4 = param_4 & 0x7ffff000;
  iVar19 = ((int (*)())FUN_0000c960)();
  puVar9 = (undefined4 *)param_5;
  if ((param_4 != 0x6000) || ((param_3 & 0xf000) != 0)) {
    uVar49 = *(uint *)(iVar19 + 0x80);
    uVar52 = (ulonglong)uVar49;
    iVar20 = *(int *)(iVar19 + 0x18);
    uVar3 = puVar9[5];
    uVar31 = (ulonglong)*(uint *)(iVar20 + 0x10) - 7;
    if ((uVar49 != 0) &&
       ((iVar21 = ((int (*)())_createOffscreenBuffer)(iVar19,iVar19 + 0x4c,*(int *)(iVar19 + 0x70) == 3),
        iVar21 != 0 &&
        (iVar21 = ((int (*)())_createTextureBuffer)(iVar19,0x40,0x40,*(int *)(iVar19 + 0x70) == 3), iVar21 != 0))
       )) {
      iStack_f0 = 0x8284;
      iStack_108 = DAT_0000e748 + 0xc;
      if (param_4 != 0x6000) {
        _fillTextureWithPattern(param_6,param_4,*puVar9,puVar9[1]);
      }
      else {
        _fillTextureWithPattern(param_6,0x6000,param_6,param_6);
      }
      uVar36 = uVar31 - (longlong)((int)(uVar49 - (iVar20 + 0x20)) >> 2);
      if (puVar9[0x16] != 0) {
        uStack_bc = uVar3 & 0x7c00;
        uStack_c4 = (uint)(param_3 & 0xc000) >> 0xe & 1;
        uStack_104 = 0;
        bVar11 = (param_3 & 0xc000) == 0;
        dVar59 = DOUBLE_0000cfe8;
        dVar64 = DOUBLE_0000cfe0;
        dVar68 = DOUBLE_0000cfd8;
        do {
          iVar20 = (int)param_5;
          uStack_114 = *(int *)(iVar20 + 0x60) + *(int *)(iVar19 + 100);
          uStack_118 = uStack_114 + *(int *)(iVar20 + 0x68);
          uStack_10c = *(int *)(iVar20 + 0x5c) + *(int *)(iVar19 + 0x60);
          uStack_110 = uStack_10c + *(int *)(iVar20 + 100);
          uStack_120 = uStack_118;
          if (uStack_114 + 8 < uStack_118) {
            uStack_120 = uStack_114 + 8;
          }
          iStack_2b4 = (uStack_10c & 7) + puVar9[2];
          iStack_2ac = (uStack_114 & 7) + puVar9[3];
          uStack_2b8 = 0x43300000;
          uStack_2b0 = 0x43300000;
          dVar69 = (double)(float)((double)CONCAT44(0x43300000,iStack_2b4) - dVar68);
          dVar70 = (double)(float)((double)CONCAT44(0x43300000,iStack_2ac) - dVar68);
          if (uStack_114 < uStack_118) {
            uVar43 = uStack_10c + 8;
            uVar49 = uStack_110;
            if (uVar43 < uStack_110) {
              uVar49 = uVar43;
            }
            uStack_290 = 0x43300000;
            dVar65 = (double)FLOAT_0000d008;
            bVar12 = true;
            uStack_28c = uStack_bc >> 10;
            dVar63 = (double)FLOAT_0000d000;
            dVar61 = (double)FLOAT_0000d00c;
            dVar62 = (double)(float)(dVar70 + dVar65);
            dVar60 = (double)(float)(dVar70 + dVar61);
            dVar66 = (double)(float)((double)CONCAT44(0x43300000,uStack_28c) - DOUBLE_0000cfd8);
            dVar67 = DOUBLE_0000cfd8;
            uVar41 = uStack_114;
            do {
              uStack_11c = uVar41;
              if (uStack_10c < uStack_110) {
                uVar41 = uVar43;
                if (!bVar12) {
                  puStack_ec = &uStack_308;
                  uStack_2a8 = 0x43300000;
                  uStack_2a0 = 0x43300000;
                  uStack_2a4 = uStack_11c;
                  uStack_29c = uStack_120;
                  uStack_cc = uStack_120 << 0x10;
                  puStack_e0 = &uStack_2fc;
                  pfStack_dc = &fStack_2f8;
                  uStack_c8 = uStack_11c << 0x10;
                  pfStack_e4 = &fStack_300;
                  pfStack_d4 = &fStack_2f0;
                  pfStack_d0 = afStack_2e4;
                  pfStack_d8 = &fStack_2f4;
                  pfStack_e8 = &fStack_304;
                  iStack_f4 = uStack_120 - uStack_11c;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_11c) - dVar67);
                  uVar42 = uStack_10c;
                  uStack_124 = uVar49;
                  goto LAB_00008bec;
                }
                if ((uVar36 & 0xffffffff) < 0xd4) {
                  fStack_2ec = *(float *)(iVar19 + 0x18);
                  fStack_2e8 = 0.0;
                  puVar10 = (undefined4 *)uVar52;
                  if (*(int *)(iVar19 + 0x8c) == 0) {
                    *puVar10 = 0x5c8;
                    fStack_2e8 = 2.8026e-45;
                    puVar10[1] = 0xc000;
                    *(undefined4 *)(iVar19 + 0x94) = 0;
                  }
                  puVar10[(int)fStack_2e8] = 0x1000000;
                  puVar13 = PTR_0000e694;
                  puVar1 = *(uint **)(iVar19 + 0x7c);
                  *puVar1 = ((int)puVar10 - (int)puVar1 >> 2) + (int)fStack_2e8 | *puVar1;
                  iVar20 = _IOConnectMapMemory(*(undefined4 *)(iVar19 + 0xc),0,
                                               *(undefined4 *)puVar13,uVar14 - 0x2ec,uVar14 - 0x2e8,
                                               1);
                  uVar42 = uStack_10c;
                  if (iVar20 == 0) {
                    pfStack_e8 = &fStack_304;
                    puStack_e0 = &uStack_2fc;
                    pfStack_d0 = afStack_2e4;
                    *(undefined4 *)((int)fStack_2ec + 0x1c) = 0;
                    puStack_ec = &uStack_308;
                    pfStack_e4 = &fStack_300;
                    pfStack_dc = &fStack_2f8;
                    pfStack_d4 = &fStack_2f0;
                    uVar36 = (ulonglong)(uint)fStack_2ec;
                    uStack_c8 = uStack_11c << 0x10;
                    uStack_cc = uStack_120 << 0x10;
                    uVar52 = uVar36 + 0x20;
                    lVar23 = uVar36 + 0x38;
                    lVar33 = uVar36 + 0x24;
                    pfStack_d8 = &fStack_2f4;
                    lVar15 = uVar36 + 0x2c;
                    lVar38 = uVar36 + 0x28;
                    iStack_f4 = uStack_120 - uStack_11c;
                    lVar22 = uVar36 + 0x30;
                    lVar28 = uVar36 + 0x34;
                    *(int *)(iVar19 + 0x7c) = (int)fStack_2ec + 0x1c;
                    *(float *)(iVar19 + 0x18) = fStack_2ec;
                    uVar36 = uVar31;
                    uStack_124 = uVar49;
                  }
                  else {
                    pfStack_d0 = afStack_2e4;
                    puStack_e0 = &uStack_2fc;
                    pfStack_e8 = &fStack_304;
                    puStack_ec = &uStack_308;
                    uVar52 = 0;
                    pfStack_e4 = &fStack_300;
                    pfStack_dc = &fStack_2f8;
                    lVar33 = 4;
                    uStack_cc = uStack_120 << 0x10;
                    pfStack_d4 = &fStack_2f0;
                    lVar38 = 8;
                    lVar15 = 0xc;
                    lVar22 = 0x10;
                    lVar28 = 0x14;
                    lVar23 = 0x18;
                    uStack_c8 = uStack_11c << 0x10;
                    pfStack_d8 = &fStack_2f4;
                    iStack_f4 = uStack_120 - uStack_11c;
                    *(undefined4 *)(iVar19 + 0x7c) = 0;
                    *(undefined4 *)(iVar19 + 0x18) = 0;
                    uVar36 = uVar31;
                    uStack_124 = uVar49;
                  }
                }
                else {
                  pfStack_d0 = afStack_2e4;
                  puStack_e0 = &uStack_2fc;
                  pfStack_e8 = &fStack_304;
                  puStack_ec = &uStack_308;
                  lVar33 = uVar52 + 4;
                  lVar38 = uVar52 + 8;
                  pfStack_e4 = &fStack_300;
                  lVar15 = uVar52 + 0xc;
                  pfStack_dc = &fStack_2f8;
                  lVar22 = uVar52 + 0x10;
                  uStack_cc = uStack_120 << 0x10;
                  pfStack_d4 = &fStack_2f0;
                  lVar28 = uVar52 + 0x14;
                  lVar23 = uVar52 + 0x18;
                  uStack_c8 = uStack_11c << 0x10;
                  pfStack_d8 = &fStack_2f4;
                  iStack_f4 = uStack_120 - uStack_11c;
                  uVar42 = uStack_10c;
                  uStack_124 = uVar49;
                }
                do {
                  puVar1 = *(uint **)(iVar19 + 0x7c);
                  puVar10 = (undefined4 *)uVar52;
                  *puVar1 = (int)puVar10 - (int)puVar1 >> 2 | *puVar1;
                  *(undefined4 **)(iVar19 + 0x7c) = puVar10;
                  *puVar10 = 0xa000000;
                  *(undefined4 *)lVar33 = *(undefined4 *)(iVar19 + 0x84);
                  puVar1 = *(uint **)(iVar19 + 0x7c);
                  puVar10 = (undefined4 *)lVar38;
                  *puVar1 = (int)puVar10 - (int)puVar1 >> 2 | *puVar1;
                  *(undefined4 **)(iVar19 + 0x7c) = puVar10;
                  *puVar10 = 0x10000000;
                  *(undefined4 *)lVar15 = *(undefined4 *)*DAT_0000e6e4;
                  *(undefined4 *)lVar22 = DAT_0000e6e4[7];
                  if (DAT_0000e6c0 == 0x10) {
                    *(undefined4 *)lVar28 = 3;
                  }
                  else {
                    *(undefined4 *)lVar28 = 6;
                  }
                  puVar1 = *(uint **)(iVar19 + 0x7c);
                  puVar10 = (undefined4 *)lVar23;
                  *puVar1 = (int)puVar10 - (int)puVar1 >> 2 | *puVar1;
                  *(undefined4 **)(iVar19 + 0x7c) = puVar10;
                  *puVar10 = 0x13000000;
                  puVar10[1] = *(undefined4 *)**(undefined4 **)(iStack_f0 + 0x64c4);
                  puVar10[2] = 0;
                  uVar52 = lVar23 + 0x10;
                  puVar10[3] = 0;
                  iVar20 = *(int *)(iVar19 + 0x70);
                  uVar36 = uVar36 - 10;
                  puVar10 = (undefined4 *)uVar52;
                  *puVar10 = 0x850;
                  puVar10[1] = 0x100;
                  puVar10[2] = 0x887;
                  puVar10[3] = 0x1c000;
                  puVar10[4] = 0x82c;
                  puVar10[5] = 0;
                  puVar10[6] = 0x1002;
                  puVar10[7] = 0;
                  puVar10[8] = 0x824;
                  puVar10[9] = 1;
                  puVar10[10] = 0x825;
                  puVar10[0xb] = 0x12;
                  puVar10[0xc] = 0x82d;
                  puVar10[0xd] = 5;
                  puVar10[0xe] = 0x854;
                  puVar10[0xf] = 0x6010006;
                  puVar10[0x10] = 0x855;
                  puVar10[0x11] = 0x2701;
                  puVar10[0x12] = 0x878;
                  puVar10[0x13] = 0xf688f688;
                  puVar10[0x14] = 0x879;
                  puVar10[0x15] = 0xfb24f688;
                  puVar10[0x16] = 0x10a2;
                  puVar10[0x17] = 0;
                  puVar10[0x18] = 0x1381;
                  puVar10[0x19] = 0;
                  puVar10[0x1a] = 0x109e;
                  puVar10[0x1b] = 5;
                  puVar10[0x1c] = 0x1383;
                  puVar10[0x1d] = 0xf;
                  puVar10[0x1e] = 0x1004;
                  puVar10[0x1f] = 0x66666666;
                  puVar10[0x20] = 0x1005;
                  puVar10[0x21] = 0x66666666;
                  puVar10[0x22] = 0x10ae;
                  puVar10[0x23] = 0;
                  puVar10[0x24] = 0x10ea;
                  puVar10[0x25] = 0x2da49525;
                  puVar10[0x26] = 0x10fa;
                  puVar10[0x27] = 0xffffff;
                  puVar10[0x28] = 0x10f4;
                  puVar10[0x29] = 0xffff;
                  puVar10[0x2a] = 0x10f8;
                  puVar10[0x2b] = 0;
                  puVar10[0x2c] = 0x10f9;
                  puVar10[0x2d] =
                       *(uint *)(iVar19 + 0x54) & 0x1fff |
                       (*(uint *)(iVar19 + 0x58) & 0x1fff) << 0xd;
                  puVar10[0x2e] = 0x13c0;
                  puVar10[0x2f] = 0;
                  puVar10[0x30] = 0x13c1;
                  puVar10[0x31] = 0;
                  puVar10[0x32] = 0x10c0;
                  puVar10[0x33] = 0x40004;
                  puVar10[0x34] = 0x10c1;
                  puVar10[0x35] = 1;
                  puVar10[0x36] = 0x10c8;
                  puVar10[0x37] = 0x10;
                  puVar10[0x38] = 0x10c9;
                  puVar10[0x39] = 0x31;
                  puVar10[0x3a] = 0x101d;
                  puVar10[0x3b] = 0x28ffe040;
                  puVar10[0x3c] = 0x101e;
                  puVar10[0x3d] = 0x28ffe0c2;
                  puVar10[0x3e] = 0x1041;
                  puVar10[0x3f] = 3;
                  puVar10[0x40] = 0x1040;
                  puVar10[0x41] = 0;
                  puVar10[0x42] = 0x1100;
                  puVar10[0x43] = 0x2a92;
                  puVar10[0x44] = 0x1101;
                  puVar10[0x45] = 0x10002a92;
                  puVar10[0x46] = 0x1120;
                  sStack_f8 = *(short *)(iVar19 + 0x50);
                  sStack_f6 = *(short *)(iVar19 + 0x52);
                  puVar10[0x47] =
                       (int)sStack_f8 - 1U & 0x7ff | (sStack_f6 + -1) * 0x800 & 0x3ff800U |
                       0x80000000;
                  puVar10[0x48] = 0x1121;
                  uVar32 = (int)*(short *)(iStack_108 + 4) - 1;
                  iVar24 = *(short *)(iStack_108 + 6) + -1;
                  puVar10[0x49] = uVar32 & 0x7ff | iVar24 * 0x800 & 0x3ff800U | 0x80000000;
                  puVar10[0x4a] = 0x1130;
                  iVar21 = 0x5300c - (uint)(iVar20 == 3);
                  puVar10[0x4b] = iVar21;
                  puVar10[0x4c] = 0x1131;
                  puVar10[0x4d] = iVar21;
                  puVar10[0x4e] = 0x1140;
                  puVar10[0x4f] =
                       *(int *)(iVar19 + 0x5c) - 1U & 0x3fff | ((int)sStack_f8 - 1U) * 0x10 & 0x8000
                       | (sStack_f6 + -1) * 0x20 & 0x10000U;
                  puVar10[0x50] = 0x1141;
                  puVar10[0x51] =
                       *(int *)(iStack_108 + 0x10) - 1U & 0x3fff | uVar32 * 0x10 & 0x8000 |
                       iVar24 * 0x20 & 0x10000U;
                  if (bVar11) {
                    lVar28 = 0x52;
                    iVar20 = 0x148;
                    iStack_164 = 0x56;
                    iStack_168 = 0x57;
                    iStack_16c = 0x58;
                    iStack_170 = 0x59;
                    iStack_174 = 0x5a;
                    iStack_178 = 0x5b;
                    iStack_17c = 0x5c;
                    iStack_180 = 0x5d;
                    iVar55 = 0x5f;
                    iStack_184 = 0x5e;
                    iVar21 = 0x53;
                    iVar24 = 0x54;
                    lVar56 = 0x60;
                    iVar37 = 0x55;
                    lVar53 = 0x61;
                    lVar38 = 0x62;
                    lVar44 = 99;
                    lVar45 = 100;
                    lVar46 = 0x65;
                    lVar47 = 0x66;
                    lVar48 = 0x67;
                    lVar50 = 0x68;
                    lVar33 = 0x69;
                    lVar22 = 0x6a;
                    lVar23 = 0x6b;
                    lVar15 = 0x6c;
                  }
                  else {
                    if (iVar20 == 3) {
                      uStack_284 = uVar3 >> 5 & 0x1f;
                      uStack_27c = uVar3 & 0x1f;
                      uStack_294 = uVar3 >> 0xf & 1;
                      dVar58 = (double)FLOAT_0000cff8;
                      uStack_288 = 0x43300000;
                      uStack_280 = 0x43300000;
                      uStack_298 = 0x43300000;
                      fStack_128 = (float)(dVar66 / dVar58);
                      fStack_12c = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_284) -
                                                          dVar67) / dVar58);
                      fStack_130 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_27c) -
                                                          dVar67) / dVar58);
                      fStack_134 = (float)((double)CONCAT44(0x43300000,uStack_294) - dVar67);
                    }
                    else {
                      uStack_274 = uVar3 >> 0x18;
                      uStack_26c = uVar3 >> 0x10 & 0xff;
                      uStack_25c = uVar3 & 0xff;
                      uStack_264 = uVar3 >> 8 & 0xff;
                      uStack_278 = 0x43300000;
                      uStack_270 = 0x43300000;
                      uStack_268 = 0x43300000;
                      uStack_260 = 0x43300000;
                      fStack_134 = (float)((double)CONCAT44(0x43300000,uStack_274) - dVar67) /
                                   FLOAT_0000cffc;
                      fStack_128 = (float)((double)CONCAT44(0x43300000,uStack_26c) - dVar67) /
                                   FLOAT_0000cffc;
                      fStack_130 = (float)((double)CONCAT44(0x43300000,uStack_25c) - dVar67) /
                                   FLOAT_0000cffc;
                      fStack_12c = (float)((double)CONCAT44(0x43300000,uStack_264) - dVar67) /
                                   FLOAT_0000cffc;
                    }
                    puVar10[0x52] = 0x1094;
                    puVar10[0x53] = 0x10000;
                    puVar10[0x54] = 0x1095;
                    puVar10[0x55] = fStack_128;
                    puVar10[0x56] = 0x1095;
                    puVar10[0x57] = fStack_12c;
                    puVar10[0x58] = 0x1095;
                    puVar10[0x59] = fStack_130;
                    puVar10[0x5a] = 0x1095;
                    puVar10[0x5b] = fStack_134;
                    lVar28 = 0x5c;
                    iVar20 = 0x170;
                    iStack_164 = 0x60;
                    iStack_168 = 0x61;
                    iStack_16c = 0x62;
                    iStack_170 = 99;
                    iStack_174 = 100;
                    iStack_178 = 0x65;
                    iStack_17c = 0x66;
                    iStack_180 = 0x67;
                    iVar55 = 0x69;
                    iStack_184 = 0x68;
                    iVar21 = 0x5d;
                    iVar24 = 0x5e;
                    lVar56 = 0x6a;
                    iVar37 = 0x5f;
                    lVar53 = 0x6b;
                    lVar38 = 0x6c;
                    lVar44 = 0x6d;
                    lVar45 = 0x6e;
                    lVar46 = 0x6f;
                    lVar47 = 0x70;
                    lVar48 = 0x71;
                    lVar50 = 0x72;
                    lVar33 = 0x73;
                    lVar22 = 0x74;
                    lVar23 = 0x75;
                    lVar15 = 0x76;
                  }
                  *(undefined4 *)((int)puVar10 + iVar20) = 0x1094;
                  puVar10[iVar21] = 0;
                  puVar10[iVar24] = 0x1095;
                  puVar10[iVar37] = 0x7803;
                  puVar10[iStack_164] = 0x1095;
                  puVar10[iStack_168] = 0x2410000;
                  puVar10[iStack_16c] = 0x1095;
                  puVar10[iStack_170] = 0x3901e401;
                  puVar10[iStack_174] = 0x1095;
                  puVar10[iStack_178] = 0;
                  puVar10[iStack_17c] = 0x1095;
                  puVar10[iStack_180] = 0;
                  puVar10[iStack_184] = 0x1095;
                  puVar10[iVar55] = 0;
                  if (bVar11) {
                    *(undefined4 *)((int)puVar10 + (int)(lVar56 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar53 << 2)) = 0x78105;
                    *(undefined4 *)((int)puVar10 + (int)(lVar38 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar44 << 2)) = 1;
                    *(undefined4 *)((int)puVar10 + (int)(lVar45 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar46 << 2)) = 1;
                    *(undefined4 *)((int)puVar10 + (int)(lVar47 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar48 << 2)) = 0xdb0220;
                    *(undefined4 *)((int)puVar10 + (int)(lVar50 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar33 << 2)) = 0xc0c006;
                    *(undefined4 *)((int)puVar10 + (int)(lVar22 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar23 << 2)) = 0x20490000;
                  }
                  else {
                    *(undefined4 *)((int)puVar10 + (int)(lVar56 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar53 << 2)) = 0x7807;
                    *(undefined4 *)((int)puVar10 + (int)(lVar38 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar44 << 2)) = 0x2400000;
                    *(undefined4 *)((int)puVar10 + (int)(lVar45 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar46 << 2)) = 0x3900e400;
                    *(undefined4 *)((int)puVar10 + (int)(lVar47 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar48 << 2)) = 0;
                    *(undefined4 *)((int)puVar10 + (int)(lVar50 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar33 << 2)) = 0;
                    *(undefined4 *)((int)puVar10 + (int)(lVar22 << 2)) = 0x1095;
                    *(undefined4 *)((int)puVar10 + (int)(lVar23 << 2)) = 0;
                    *(undefined4 *)((int)puVar10 + (int)(lVar15 << 2)) = 0x1095;
                    iVar20 = (int)lVar28;
                    puVar10[iVar20 + 0x1b] = 0x7804;
                    puVar10[iVar20 + 0x1c] = 0x1095;
                    puVar10[iVar20 + 0x1d] = 0x40040000;
                    puVar10[iVar20 + 0x1e] = 0x1095;
                    puVar10[iVar20 + 0x1f] = 0x40040000;
                    puVar10[iVar20 + 0x20] = 0x1095;
                    puVar10[iVar20 + 0x21] = 0xdb0490;
                    puVar10[iVar20 + 0x22] = 0x1095;
                    puVar10[iVar20 + 0x23] = 0xc10026;
                    puVar10[iVar20 + 0x24] = 0x1095;
                    puVar10[iVar20 + 0x25] = 0xdfa23028;
                    puVar10[iVar20 + 0x26] = 0x1095;
                    puVar10[iVar20 + 0x27] = 0x7800;
                    puVar10[iVar20 + 0x28] = 0x1095;
                    puVar10[iVar20 + 0x29] = 2;
                    puVar10[iVar20 + 0x2a] = 0x1095;
                    puVar10[iVar20 + 0x2b] = 2;
                    puVar10[iVar20 + 0x2c] = 0x1095;
                    puVar10[iVar20 + 0x2d] = 0xdb0220;
                    puVar10[iVar20 + 0x2e] = 0x1095;
                    puVar10[iVar20 + 0x2f] = 0xc0c021;
                    puVar10[iVar20 + 0x30] = 0x1095;
                    puVar10[iVar20 + 0x31] = 0x22;
                    puVar10[iVar20 + 0x32] = 0x1095;
                    puVar10[iVar20 + 0x33] = 0x78101;
                    puVar10[iVar20 + 0x34] = 0x1095;
                    uVar32 = (uStack_c4 ^ 1) << 10 | uStack_c4 | 0x200000;
                    puVar10[iVar20 + 0x35] = uVar32;
                    puVar10[iVar20 + 0x36] = 0x1095;
                    puVar10[iVar20 + 0x37] = uVar32;
                    puVar10[iVar20 + 0x38] = 0x1095;
                    puVar10[iVar20 + 0x39] = 0x440221;
                    puVar10[iVar20 + 0x3a] = 0x1095;
                    puVar10[iVar20 + 0x3b] = 0x60d006;
                    puVar10[iVar20 + 0x3c] = 0x1095;
                    lVar15 = lVar28 + 0x3e;
                    puVar10[iVar20 + 0x3d] = 0xdda22008;
                  }
                  *(undefined4 *)((int)puVar10 + (int)(lVar15 << 2)) = 0x1189;
                  iStack_158 = (int)lVar15;
                  puVar10[iStack_158 + 1] = 0;
                  puVar10[iStack_158 + 2] = 0x1181;
                  puVar10[iStack_158 + 3] = 5;
                  puVar10[iStack_158 + 4] = 0x118d;
                  if (bVar11) {
                    uVar16 = 0x10000;
                  }
                  else {
                    uVar16 = 0x40000;
                  }
                  puVar10[iStack_158 + 5] = uVar16;
                  puVar10[iStack_158 + 6] = 0x118e;
                  puVar10[iStack_158 + 7] = 0;
                  puVar10[iStack_158 + 8] = 0x118c;
                  if (bVar11) {
                    uVar16 = 0x10000;
                  }
                  else {
                    uVar16 = 0x40000;
                  }
                  puVar10[iStack_158 + 9] = uVar16;
                  puVar10[iStack_158 + 10] = 0x11a9;
                  puVar10[iStack_158 + 0xb] = 0x1b01;
                  puVar10[iStack_158 + 0xc] = 0x11aa;
                  puVar10[iStack_158 + 0xd] = 0xf;
                  puVar10[iStack_158 + 0xe] = 0x11ab;
                  puVar10[iStack_158 + 0xf] = 0xf;
                  puVar10[iStack_158 + 0x10] = 0x11ac;
                  puVar10[iStack_158 + 0x11] = 0xf;
                  puVar10[iStack_158 + 0x12] = 0x12f0;
                  puVar10[iStack_158 + 0x13] = 0;
                  puVar10[iStack_158 + 0x14] = 0x12f5;
                  puVar10[iStack_158 + 0x15] = 0;
                  iStack_13c = iStack_158 + 0x17;
                  iStack_140 = iStack_158 + 0x18;
                  lVar22 = lVar15 + 0x30;
                  uStack_258 = 0x43300000;
                  uStack_250 = 0x43300000;
                  lVar28 = lVar15 + 0x1a;
                  lVar45 = lVar15 + 0x19;
                  uStack_254 = uStack_11c;
                  uStack_24c = uStack_120;
                  iStack_14c = iStack_158 + 0x1e;
                  iStack_150 = iStack_158 + 0x1f;
                  iStack_144 = iStack_158 + 0x1b;
                  iStack_15c = iStack_158 + 0x22;
                  iStack_160 = iStack_158 + 0x24;
                  iStack_138 = (iStack_158 + 0x16) * 4;
                  iStack_148 = iStack_158 + 0x1d;
                  iStack_154 = iStack_158 + 0x20;
                  lVar23 = lVar15 + 0x1c;
                  iStack_158 = iStack_158 + 0x21;
                  lVar44 = lVar15 + 0x25;
                  lVar33 = lVar15 + 0x26;
                  lVar38 = lVar15 + 0x23;
                  lVar54 = lVar15 + 0x27;
                  lVar46 = lVar15 + 0x28;
                  lVar47 = lVar15 + 0x29;
                  lVar48 = lVar15 + 0x2a;
                  lVar50 = lVar15 + 0x2b;
                  lVar53 = lVar15 + 0x2c;
                  lVar56 = lVar15 + 0x2d;
                  lVar51 = lVar15 + 0x2e;
                  lVar15 = lVar15 + 0x2f;
                  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_11c) - dVar67);
                  while( true ) {
                    fVar5 = FLOAT_0000d000;
                    dVar58 = DOUBLE_0000cfe0;
                    uStack_23c = uStack_124;
                    uStack_238 = 0x43300000;
                    uStack_228 = 0x43300000;
                    uStack_248 = 0x43300000;
                    uStack_240 = 0x43300000;
                    uStack_234 = (int)sStack_f8 ^ 0x80000000;
                    uStack_224 = (int)sStack_f6 ^ 0x80000000;
                    dVar57 = (double)FLOAT_0000d008;
                    fStack_304 = (FLOAT_0000d000 /
                                 (float)((double)CONCAT44(0x43300000,uStack_234) - DOUBLE_0000cfe0))
                                 * (float)((double)CONCAT44(0x43300000,uStack_124) - dVar67);
                    fStack_300 = (FLOAT_0000d000 /
                                 (float)((double)CONCAT44(0x43300000,uStack_224) - DOUBLE_0000cfe0))
                                 * fVar2;
                    iVar20 = (int)uVar52;
                    *(undefined4 *)(iVar20 + iStack_138) = 0xc0143500;
                    *(undefined4 *)(iVar20 + iStack_13c * 4) = 0x4003d;
                    iVar21 = uStack_124 - uVar42;
                    if ((iVar21 == 8) && (iStack_f4 == 8)) {
                      uStack_1e8 = 0x43300000;
                      uStack_1e4 = (int)*(short *)(iStack_108 + 4) ^ 0x80000000;
                      fStack_2f8 = (float)(dVar69 + dVar57) *
                                   (fVar5 / (float)((double)CONCAT44(0x43300000,uStack_1e4) - dVar58
                                                   ));
                      uStack_1e0 = 0x43300000;
                      uStack_1dc = (int)*(short *)(iStack_108 + 4) ^ 0x80000000;
                      fStack_2f4 = (float)(dVar69 + dVar61) *
                                   (fVar5 / (float)((double)CONCAT44(0x43300000,uStack_1dc) - dVar58
                                                   ));
                      uStack_1d8 = 0x43300000;
                      uStack_1d4 = (int)*(short *)(iStack_108 + 6) ^ 0x80000000;
                      fStack_2f0 = (float)(dVar70 + dVar57) *
                                   (fVar5 / (float)((double)CONCAT44(0x43300000,uStack_1d4) - dVar58
                                                   ));
                      uStack_1d0 = 0x43300000;
                      uStack_1cc = (int)*(short *)(iStack_108 + 6) ^ 0x80000000;
                      afStack_2e4[0] =
                           (float)(dVar60 * (double)(fVar5 / (float)((double)CONCAT44(0x43300000,
                                                                                      uStack_1cc) -
                                                                    dVar58)));
                    }
                    else {
                      uStack_218 = 0x43300000;
                      uStack_210 = 0x43300000;
                      uStack_214 = (int)*(short *)(iStack_108 + 4) ^ 0x80000000;
                      fStack_2f8 = (float)(dVar69 + dVar65) *
                                   (float)(dVar63 / (double)(float)((double)CONCAT44(0x43300000,
                                                                                     uStack_214) -
                                                                   dVar64));
                      uStack_208 = 0x43300000;
                      uStack_204 = (int)*(short *)(iStack_108 + 4) ^ 0x80000000;
                      fStack_2f4 = (float)(dVar69 + (double)(float)((double)CONCAT44(0x43300000,
                                                                                     iVar21) -
                                                                   dVar67)) *
                                   (float)(dVar63 / (double)(float)((double)CONCAT44(0x43300000,
                                                                                     uStack_204) -
                                                                   dVar64));
                      uStack_200 = 0x43300000;
                      iStack_1f4 = iStack_f4;
                      uStack_1f8 = 0x43300000;
                      uStack_1fc = (int)*(short *)(iStack_108 + 6) ^ 0x80000000;
                      fStack_2f0 = (float)(dVar62 * (double)(float)(dVar63 / (double)(float)((double
                                                  )CONCAT44(0x43300000,uStack_1fc) - dVar64)));
                      uStack_1f0 = 0x43300000;
                      uStack_1ec = (int)*(short *)(iStack_108 + 6) ^ 0x80000000;
                      afStack_2e4[0] =
                           (float)(dVar70 + (double)(float)((double)CONCAT44(0x43300000,iStack_f4) -
                                                           dVar67)) *
                           (float)(dVar63 / (double)(float)((double)CONCAT44(0x43300000,uStack_1ec)
                                                           - dVar64));
                      iStack_20c = iVar21;
                    }
                    *(uint *)(iVar20 + iStack_140 * 4) = uVar42 | uStack_cc;
                    uVar16 = *puStack_ec;
                    *(undefined4 *)(iVar20 + (int)(lVar45 << 2)) = uVar16;
                    uVar4 = *puStack_e0;
                    *(undefined4 *)(iVar20 + (int)(lVar28 << 2)) = uVar4;
                    fVar5 = *pfStack_dc;
                    *(float *)(iVar20 + iStack_144 * 4) = fVar5;
                    fVar6 = *pfStack_d0;
                    *(float *)(iVar20 + (int)(lVar23 << 2)) = fVar6;
                    *(uint *)(iVar20 + iStack_148 * 4) = uVar42 | uStack_c8;
                    *(undefined4 *)(iVar20 + iStack_14c * 4) = uVar16;
                    fVar7 = *pfStack_e4;
                    *(float *)(iVar20 + iStack_150 * 4) = fVar7;
                    *(float *)(iVar20 + iStack_154 * 4) = fVar5;
                    fVar5 = *pfStack_d4;
                    *(float *)(iVar20 + iStack_158 * 4) = fVar5;
                    *(uint *)(iVar20 + iStack_15c * 4) = uStack_124 | uStack_c8;
                    fVar8 = *pfStack_e8;
                    *(float *)(iVar20 + (int)(lVar38 << 2)) = fVar8;
                    *(float *)(iVar20 + iStack_160 * 4) = fVar7;
                    fVar7 = *pfStack_d8;
                    *(float *)(iVar20 + (int)(lVar44 << 2)) = fVar7;
                    *(float *)(iVar20 + (int)(lVar33 << 2)) = fVar5;
                    *(uint *)(iVar20 + (int)(lVar54 << 2)) = uStack_124 | uStack_cc;
                    *(float *)(iVar20 + (int)(lVar46 << 2)) = fVar8;
                    *(undefined4 *)(iVar20 + (int)(lVar47 << 2)) = uVar4;
                    *(float *)(iVar20 + (int)(lVar48 << 2)) = fVar7;
                    *(float *)(iVar20 + (int)(lVar50 << 2)) = fVar6;
                    *(undefined4 *)(iVar20 + (int)(lVar53 << 2)) = 0x1393;
                    *(undefined4 *)(iVar20 + (int)(lVar56 << 2)) = 10;
                    *(undefined4 *)(iVar20 + (int)(lVar51 << 2)) = 0x5c8;
                    *(undefined4 *)(iVar20 + (int)(lVar15 << 2)) = 0x20000;
                    uVar36 = uVar36 - lVar22;
                    uVar52 = uVar52 + lVar22 * 4;
                    uStack_124 = uStack_110;
                    if (uVar42 + 0x10 < uStack_110) {
                      uStack_124 = uVar42 + 0x10;
                    }
                    bVar12 = false;
                    uStack_244 = uVar42;
                    if (uStack_110 <= uVar41) goto LAB_0000a09c;
                    uVar42 = uVar41;
                    uVar41 = uVar41 + 8;
LAB_00008bec:
                    if ((uVar36 & 0xffffffff) < 0x1a) break;
                    sStack_f8 = *(short *)(iVar19 + 0x50);
                    lVar33 = 0x10;
                    lVar22 = 0x1a;
                    lVar44 = 0xf;
                    lVar15 = 0x19;
                    lVar51 = 0x18;
                    lVar56 = 0x17;
                    lVar53 = 0x16;
                    lVar50 = 0x15;
                    lVar48 = 0x14;
                    lVar47 = 0x13;
                    lVar46 = 0x12;
                    lVar54 = 0x11;
                    lVar38 = 0xd;
                    lVar23 = 6;
                    lVar28 = 4;
                    sStack_f6 = *(short *)(iVar19 + 0x52);
                    iStack_160 = 0xe;
                    iStack_15c = 0xc;
                    iStack_154 = 10;
                    iStack_150 = 9;
                    iStack_14c = 8;
                    iStack_148 = 7;
                    iStack_158 = 0xb;
                    iStack_140 = 2;
                    lVar45 = 3;
                    iStack_144 = 5;
                    iStack_13c = 1;
                    iStack_138 = 0;
                  }
                  fStack_2e8 = *(float *)(iVar19 + 0x18);
                  fStack_2ec = 0.0;
                  puVar10 = (undefined4 *)uVar52;
                  if (*(int *)(iVar19 + 0x8c) == 0) {
                    *puVar10 = 0x5c8;
                    fStack_2ec = 2.8026e-45;
                    puVar10[1] = 0xc000;
                    *(undefined4 *)(iVar19 + 0x94) = 0;
                  }
                  puVar10[(int)fStack_2ec] = 0x1000000;
                  puVar13 = PTR_0000e694;
                  puVar1 = *(uint **)(iVar19 + 0x7c);
                  *puVar1 = ((int)puVar10 - (int)puVar1 >> 2) + (int)fStack_2ec | *puVar1;
                  iVar20 = _IOConnectMapMemory(*(undefined4 *)(iVar19 + 0xc),0,
                                               *(undefined4 *)puVar13,uVar14 - 0x2e8,uVar14 - 0x2ec,
                                               1);
                  if (iVar20 == 0) {
                    *(undefined4 *)((int)fStack_2e8 + 0x1c) = 0;
                    uVar36 = (ulonglong)(uint)fStack_2e8;
                    *(float *)(iVar19 + 0x18) = fStack_2e8;
                    uVar52 = uVar36 + 0x20;
                    lVar23 = uVar36 + 0x38;
                    *(int *)(iVar19 + 0x7c) = (int)fStack_2e8 + 0x1c;
                    lVar33 = uVar36 + 0x24;
                    lVar38 = uVar36 + 0x28;
                    lVar15 = uVar36 + 0x2c;
                    lVar22 = uVar36 + 0x30;
                    lVar28 = uVar36 + 0x34;
                    uVar36 = uVar31;
                    uVar41 = uVar42 + 8;
                  }
                  else {
                    lVar23 = 0x18;
                    *(undefined4 *)(iVar19 + 0x7c) = 0;
                    *(undefined4 *)(iVar19 + 0x18) = 0;
                    lVar28 = 0x14;
                    lVar22 = 0x10;
                    lVar15 = 0xc;
                    lVar38 = 8;
                    lVar33 = 4;
                    uVar52 = 0;
                    uVar36 = uVar31;
                    uVar41 = uVar42 + 8;
                  }
                } while( true );
              }
LAB_0000a09c:
              uStack_120 = uStack_118;
              if (uStack_11c + 0x10 < uStack_118) {
                uStack_120 = uStack_11c + 0x10;
              }
              uVar41 = uStack_11c + 8;
            } while (uStack_11c + 8 < uStack_118);
          }
          puVar10 = (undefined4 *)uVar52;
          if ((uVar36 & 0xffffffff) < 0x86) {
            fStack_2ec = *(float *)(iVar19 + 0x18);
            fStack_2e8 = 0.0;
            if (*(int *)(iVar19 + 0x8c) == 0) {
              *puVar10 = 0x5c8;
              fStack_2e8 = 2.8026e-45;
              puVar10[1] = 0xc000;
              *(undefined4 *)(iVar19 + 0x94) = 0;
            }
            puVar10[(int)fStack_2e8] = 0x1000000;
            puVar1 = *(uint **)(iVar19 + 0x7c);
            *puVar1 = ((int)puVar10 - (int)puVar1 >> 2) + (int)fStack_2e8 | *puVar1;
            iVar20 = _IOConnectMapMemory(*(undefined4 *)(iVar19 + 0xc),0,*(undefined4 *)PTR_0000e694
                                         ,uVar14 - 0x2ec,uVar14 - 0x2e8,1);
            if (iVar20 == 0) {
              *(undefined4 *)((int)fStack_2ec + 0x1c) = 0;
              *(float *)(iVar19 + 0x18) = fStack_2ec;
              uVar52 = (ulonglong)(uint)fStack_2ec + 0x20;
              lVar33 = (ulonglong)(uint)fStack_2ec + 0x38;
              *(int *)(iVar19 + 0x7c) = (int)fStack_2ec + 0x1c;
              pdVar25 = (dword *)((int)fStack_2ec + 0x24);
              pdVar26 = (dword *)((int)fStack_2ec + 0x28);
              pdVar27 = (dword *)((int)fStack_2ec + 0x2c);
              pdVar35 = (dword *)((int)fStack_2ec + 0x30);
              pdVar30 = (dword *)((int)fStack_2ec + 0x34);
              uVar36 = uVar31;
            }
            else {
              uVar52 = 0;
              *(undefined4 *)(iVar19 + 0x7c) = 0;
              *(undefined4 *)(iVar19 + 0x18) = 0;
              pdVar25 = &__mh_bundle_header.cputype;
              pdVar26 = &__mh_bundle_header.cpusubtype;
              pdVar27 = &__mh_bundle_header.filetype;
              pdVar35 = &__mh_bundle_header.ncmds;
              pdVar30 = &__mh_bundle_header.sizeofcmds;
              lVar33 = 0x18;
              uVar36 = uVar31;
            }
          }
          else {
            pdVar25 = puVar10 + 1;
            pdVar26 = puVar10 + 2;
            pdVar27 = puVar10 + 3;
            pdVar35 = puVar10 + 4;
            pdVar30 = puVar10 + 5;
            lVar33 = uVar52 + 0x18;
          }
          puVar1 = *(uint **)(iVar19 + 0x7c);
          puVar10 = (undefined4 *)uVar52;
          *puVar1 = (int)puVar10 - (int)puVar1 >> 2 | *puVar1;
          *(undefined4 **)(iVar19 + 0x7c) = puVar10;
          *puVar10 = 0x11000000;
          *pdVar25 = *(dword *)(iVar19 + 0x84);
          *pdVar26 = 0;
          *pdVar27 = 0;
          puVar1 = *(uint **)(iVar19 + 0x7c);
          *puVar1 = (int)pdVar35 - (int)puVar1 >> 2 | *puVar1;
          *(dword **)(iVar19 + 0x7c) = pdVar35;
          *pdVar35 = 0x4000000;
          *pdVar30 = *(dword *)*DAT_0000e6e4;
          puVar10 = DAT_0000e6e4;
          iVar20 = DAT_0000e6e4[0xc];
          if (iVar20 == 3) {
            iVar20 = 0xb;
          }
          else if (iVar20 == 6) {
            iVar20 = 0xc;
          }
          uVar52 = ((int (*)())_radeon3DCopySetup)(iVar19,lVar33,DAT_0000e6e4 + 3,iVar20,0,0,0,0);
          uStack_1c4 = uStack_10c;
          uStack_1b4 = uStack_114;
          uStack_1bc = uStack_110;
          uStack_1ac = uStack_118;
          uStack_1c8 = 0x43300000;
          uStack_1c0 = 0x43300000;
          uStack_1b8 = 0x43300000;
          uStack_1b0 = 0x43300000;
          iVar20 = (int)lVar33;
          *(undefined4 *)(iVar20 + (int)((uVar52 & 0xffffffff) << 2)) = 0xc00c3500;
          *(undefined4 *)(iVar20 + (int)((uVar52 + 1 & 0xffffffff) << 2)) = 0x4003d;
          uStack_1a8 = 0x43300000;
          uStack_1a4 = (int)*(short *)(puVar10 + 4) ^ 0x80000000;
          fVar2 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_10c) - dVar68) *
                         (dVar59 / ((double)CONCAT44(0x43300000,uStack_1a4) - dVar64)));
          uStack_1a0 = 0x43300000;
          uStack_19c = (int)*(short *)(puVar10 + 4) ^ 0x80000000;
          afStack_2e4[0] =
               (float)((double)(float)((double)CONCAT44(0x43300000,uStack_110) - dVar68) *
                      (dVar59 / ((double)CONCAT44(0x43300000,uStack_19c) - dVar64)));
          uStack_198 = 0x43300000;
          uStack_194 = (int)*(short *)((int)puVar10 + 0x12) ^ 0x80000000;
          fStack_2e8 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_114) - dVar68) *
                              (dVar59 / ((double)CONCAT44(0x43300000,uStack_194) - dVar64)));
          uStack_190 = 0x43300000;
          uStack_18c = (int)*(short *)((int)puVar10 + 0x12) ^ 0x80000000;
          fStack_2ec = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_118) - dVar68) *
                              (dVar59 / ((double)CONCAT44(0x43300000,uStack_18c) - dVar64)));
          *(uint *)(iVar20 + (int)((uVar52 + 2 & 0xffffffff) << 2)) =
               uStack_10c | uStack_118 << 0x10;
          *(float *)(iVar20 + (int)((uVar52 + 3 & 0xffffffff) << 2)) = fVar2;
          *(float *)(iVar20 + (int)((uVar52 + 4 & 0xffffffff) << 2)) = fStack_2ec;
          *(uint *)(iVar20 + (int)((uVar52 + 5 & 0xffffffff) << 2)) =
               uStack_10c | uStack_114 << 0x10;
          *(float *)(iVar20 + (int)((uVar52 + 6 & 0xffffffff) << 2)) = fVar2;
          *(float *)(iVar20 + (int)((uVar52 + 7 & 0xffffffff) << 2)) = fStack_2e8;
          *(uint *)(iVar20 + (int)((uVar52 + 8 & 0xffffffff) << 2)) =
               uStack_110 | uStack_114 << 0x10;
          *(float *)(iVar20 + (int)((uVar52 + 9 & 0xffffffff) << 2)) = afStack_2e4[0];
          *(float *)(iVar20 + (int)((uVar52 + 10 & 0xffffffff) << 2)) = fStack_2e8;
          *(uint *)(iVar20 + (int)((uVar52 + 0xb & 0xffffffff) << 2)) =
               uStack_110 | uStack_118 << 0x10;
          *(float *)(iVar20 + (int)((uVar52 + 0xc & 0xffffffff) << 2)) = afStack_2e4[0];
          *(float *)(iVar20 + (int)((uVar52 + 0xd & 0xffffffff) << 2)) = fStack_2ec;
          *(undefined4 *)(iVar20 + (int)((uVar52 + 0xe & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)(iVar20 + (int)((uVar52 + 0xf & 0xffffffff) << 2)) = 10;
          *(undefined4 *)(iVar20 + (int)((uVar52 + 0x10 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)(iVar20 + (int)((uVar52 + 0x11 & 0xffffffff) << 2)) = 0x20000;
          uVar36 = (uVar36 - 6) - (uVar52 + 0x12);
          param_5 = param_5 + 0x10;
          uVar52 = (uVar52 + 0x12 & 0x3fffffff) * 4 + lVar33;
          uStack_104 = uStack_104 + 1;
        } while (uStack_104 < (uint)puVar9[0x16]);
      }
      *(int *)(iVar19 + 0x80) = (int)uVar52;
      return 0;
    }
  }
  else {
    uVar49 = *(uint *)(iVar19 + 0x80);
    uVar52 = (ulonglong)uVar49;
    uVar31 = (ulonglong)*(uint *)(*(int *)(iVar19 + 0x18) + 0x10);
    lVar33 = uVar31 - 7;
    uStack_fc = (uint)lVar33;
    if (uVar49 != 0) {
      uVar36 = (ulonglong)(uint)puVar9[0x16];
      uVar39 = lVar33 - ((int)(uVar49 - (*(int *)(iVar19 + 0x18) + 0x20)) >> 2);
      uStack_100 = (int)((uVar31 - 0x75 & 0xffffffff) / 0xc) - 1;
      if (puVar9[0x16] != 0) {
        pfStack_c0 = &fStack_300;
        uStack_188 = uStack_100 * 0xc + 0x6e;
        lVar33 = uVar14 - 0x304;
        uVar31 = 0;
        do {
          if ((uVar39 & 0xffffffff) < (ulonglong)uStack_188) {
            uVar49 = *(uint *)(iVar19 + 0x18);
            afStack_2e4[0] = 0.0;
            puVar10 = (undefined4 *)uVar52;
            if (*(int *)(iVar19 + 0x8c) == 0) {
              *puVar10 = 0x5c8;
              afStack_2e4[0] = 2.8026e-45;
              puVar10[1] = 0xc000;
              *(undefined4 *)(iVar19 + 0x94) = 0;
            }
            puVar10[(int)afStack_2e4[0]] = 0x1000000;
            puVar1 = *(uint **)(iVar19 + 0x7c);
            *puVar1 = ((int)puVar10 - (int)puVar1 >> 2) + (int)afStack_2e4[0] | *puVar1;
            iVar20 = _IOConnectMapMemory(*(undefined4 *)(iVar19 + 0xc),0,*(undefined4 *)PTR_0000e694
                                         ,uVar14 - 0x2fc,uVar14 - 0x2e4,1);
            if (iVar20 == 0) {
              uVar39 = (ulonglong)uStack_fc;
              *(undefined4 *)(uVar49 + 0x1c) = 0;
              *(uint *)(iVar19 + 0x18) = uVar49;
              uVar52 = (ulonglong)uVar49 + 0x20;
              *(uint *)(iVar19 + 0x7c) = uVar49 + 0x1c;
              uVar36 = (ulonglong)(uint)puVar9[0x16];
            }
            else {
              *(undefined4 *)(iVar19 + 0x7c) = 0;
              *(undefined4 *)(iVar19 + 0x18) = 0;
              uVar52 = 0;
              uVar39 = (ulonglong)uStack_fc;
              uVar36 = (ulonglong)(uint)puVar9[0x16];
            }
          }
          uVar40 = uVar31 + uStack_100;
          if ((uVar40 & 0xffffffff) < uVar36) {
            uVar36 = uVar40;
          }
          uVar17 = ((int (*)())_radeon3DFillSetup)(uVar52,0,param_6,iVar19);
          uVar34 = uVar36 - uVar31;
          iVar20 = (int)uVar52;
          *(uint *)(iVar20 + (int)((uVar17 & 0xffffffff) << 2)) =
               (uint)((uVar34 * 0xc & 0xffffffff) << 0x10) | 0xc0003500;
          uVar18 = uVar17 + 2;
          *(uint *)(iVar20 + (int)((uVar17 + 1 & 0xffffffff) << 2)) =
               (uint)((uVar34 & 0xffffffff) << 0x12) | 0x3d;
          dVar59 = DOUBLE_0000cfe0;
          if ((uVar31 & 0xffffffff) < (uVar36 & 0xffffffff)) {
            lVar15 = (uVar18 & 0x3fffffff) * 4;
            iVar21 = *(int *)(iVar19 + 0x60);
            iVar24 = *(int *)(iVar19 + 100);
            lVar44 = lVar15 + 4;
            lVar45 = lVar15 + 0x28;
            lVar46 = lVar15 + 0x24;
            lVar28 = (uVar31 & 0xfffffff) * 0x10 + param_5 + 0x5c;
            lVar47 = lVar15 + 0x20;
            lVar48 = lVar15 + 0x1c;
            lVar50 = lVar15 + 0x18;
            lVar38 = lVar15 + 0x14;
            lVar22 = lVar15 + 0x10;
            lVar23 = lVar15 + 0xc;
            lVar15 = lVar15 + 8;
            do {
              piVar29 = (int *)lVar28;
              uStack_2d8 = 0x43300000;
              uStack_2d4 = *piVar29 + iVar21 ^ 0x80000000;
              uStack_2d0 = 0x43300000;
              uStack_2cc = *piVar29 + iVar21 + piVar29[2] ^ 0x80000000;
              fStack_300 = (float)((double)CONCAT44(0x43300000,uStack_2cc) - dVar59);
              uStack_2c8 = 0x43300000;
              uStack_2c4 = piVar29[1] + iVar24 ^ 0x80000000;
              fStack_304 = (float)((double)CONCAT44(0x43300000,uStack_2c4) - dVar59);
              uStack_2c0 = 0x43300000;
              uStack_2bc = piVar29[1] + iVar24 + piVar29[3] ^ 0x80000000;
              *(undefined4 *)(iVar20 + (int)((uVar18 & 0xffffffff) << 2)) = uStack_2fc;
              *(undefined4 *)(iVar20 + (int)lVar44) = uStack_308;
              *(undefined4 *)(iVar20 + (int)lVar15) = 0;
              *(undefined4 *)(iVar20 + (int)lVar23) = uStack_2fc;
              uVar16 = *(undefined4 *)lVar33;
              *(undefined4 *)(iVar20 + (int)lVar22) = uVar16;
              *(undefined4 *)(iVar20 + (int)lVar38) = 0;
              fVar2 = *pfStack_c0;
              *(float *)(iVar20 + (int)lVar50) = fVar2;
              *(undefined4 *)(iVar20 + (int)lVar48) = uVar16;
              *(undefined4 *)(iVar20 + (int)lVar47) = 0;
              *(float *)(iVar20 + (int)lVar46) = fVar2;
              *(undefined4 *)(iVar20 + (int)lVar45) = uStack_308;
              uVar31 = uVar18 + 0xb;
              lVar44 = lVar44 + 0x30;
              uVar18 = uVar18 + 0xc;
              lVar15 = lVar15 + 0x30;
              lVar23 = lVar23 + 0x30;
              lVar22 = lVar22 + 0x30;
              lVar38 = lVar38 + 0x30;
              lVar50 = lVar50 + 0x30;
              lVar48 = lVar48 + 0x30;
              lVar47 = lVar47 + 0x30;
              lVar46 = lVar46 + 0x30;
              lVar45 = lVar45 + 0x30;
              *(undefined4 *)(iVar20 + (int)((uVar31 & 0xffffffff) << 2)) = 0;
              lVar28 = lVar28 + 0x10;
              uVar34 = uVar34 - 1;
            } while (uVar34 != 0);
          }
          *(undefined4 *)(iVar20 + (int)((uVar18 & 0xffffffff) << 2)) = 0x1393;
          *(undefined4 *)(iVar20 + (int)((uVar18 + 1 & 0xffffffff) << 2)) = 10;
          *(undefined4 *)(iVar20 + (int)((uVar18 + 2 & 0xffffffff) << 2)) = 0x5c8;
          *(undefined4 *)(iVar20 + (int)((uVar18 + 3 & 0xffffffff) << 2)) = 0x20000;
          uVar36 = (ulonglong)(uint)puVar9[0x16];
          uVar39 = uVar39 - (uVar18 + 4);
          uVar52 = uVar52 + (uVar18 + 4 & 0x3fffffff) * 4;
          uVar31 = uVar40;
        } while ((uVar40 & 0xffffffff) < uVar36);
      }
      *(int *)(iVar19 + 0x80) = (int)uVar52;
      return 0;
    }
  }
  return 0xffffffffe00002be;
}

/* _radeonHighlight @ 0xa5a0 (5300 bytes) */
undefined8 _radeonHighlight(param_1)
  int param_1;
{
  double dVar1;
  double dVar2;
  double dVar3;
  short sVar4;
  short sVar5;
  uint *puVar6;
  float fVar7;
  undefined4 *puVar8;
  int iVar10;
  int iVar11;
  undefined8 uVar9;
  ulonglong uVar12;
  dword *pdVar13;
  longlong lVar14;
  dword *pdVar15;
  dword *pdVar16;
  uint *in_r7;
  float fVar17;
  dword *pdVar18;
  uint in_r8;
  float fVar19;
  dword *pdVar20;
  undefined4 *puVar21;
  ulonglong uVar22;
  uint *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  ulonglong uVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  float fStack_208;
  float fStack_204;
  float fStack_200;
  float fStack_1fc;
  float fStack_1f8;
  float fStack_1f4;
  float fStack_1f0;
  float afStack_1ec [2];
  uint uStack_1e4;
  undefined4 uStack_1e0;
  uint uStack_1dc;
  undefined4 uStack_1d8;
  uint uStack_1d4;
  undefined4 uStack_1d0;
  uint uStack_1cc;
  undefined4 uStack_1c8;
  uint uStack_1c4;
  undefined4 uStack_1c0;
  uint uStack_1bc;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  undefined4 uStack_1b0;
  uint uStack_1ac;
  undefined4 uStack_1a8;
  uint uStack_1a4;
  undefined4 uStack_1a0;
  uint uStack_19c;
  undefined4 uStack_198;
  uint uStack_194;
  undefined4 uStack_190;
  uint uStack_18c;
  undefined4 uStack_188;
  uint uStack_184;
  undefined4 uStack_180;
  uint uStack_17c;
  undefined4 uStack_178;
  uint uStack_174;
  undefined4 uStack_170;
  uint uStack_16c;
  undefined4 uStack_168;
  uint uStack_164;
  undefined4 uStack_160;
  uint uStack_15c;
  undefined4 uStack_158;
  uint uStack_154;
  undefined4 uStack_150;
  uint uStack_14c;
  undefined4 uStack_148;
  uint uStack_144;
  undefined4 uStack_138;
  uint uStack_134;
  undefined4 uStack_128;
  uint uStack_124;
  undefined4 uStack_120;
  uint uStack_11c;
  undefined4 uStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  uint uStack_10c;
  undefined4 uStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  uint uStack_fc;
  undefined4 uStack_f8;
  uint uStack_f4;
  undefined4 uStack_f0;
  uint uStack_ec;
  float *pfStack_e8;
  float *pfStack_e4;
  float *pfStack_e0;
  float *pfStack_dc;
  float *pfStack_d8;
  float *pfStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float *pfStack_b0;
  float *pfStack_ac;
  float fStack_a0;
  
  iVar10 = ((int (*)())FUN_0000c974)();
  uVar24 = *(uint *)(iVar10 + 0x80);
  uVar32 = (ulonglong)uVar24;
  iVar11 = *(int *)(iVar10 + 0x18);
  uStack_cc = *(int *)(iVar11 + 0x10) - 7;
  if ((uVar24 == 0) ||
     (iVar10 = ((int (*)())_createOffscreenBuffer)(iVar10,iVar10 + 0x4c,*(int *)(iVar10 + 0x70) == 3),
     iVar10 == 0)) {
    uVar9 = 0xffffffffe00002be;
  }
  else {
    uVar22 = (ulonglong)*in_r7;
    uVar12 = (ulonglong)uStack_cc - (longlong)((int)(uVar24 - (iVar11 + 0x20)) >> 2);
    if (in_r7[0x16] != 0) {
      uStack_1c8 = 0x43300000;
      uStack_1e0 = 0x43300000;
      uStack_1c4 = in_r8 >> 0x18;
      uStack_1dc = in_r8 >> 10 & 0x1f;
      uStack_c4 = 0xc10016;
      uStack_c8 = 0xdb0490;
      uStack_c0 = 0xdfa23018;
      uStack_bc = 0xdb0220;
      pfStack_d4 = afStack_1ec;
      uStack_b4 = 0x440221;
      uStack_b8 = 0xc0c011;
      pfStack_dc = &fStack_204;
      pfStack_d8 = &fStack_200;
      pfStack_e0 = &fStack_208;
      pfStack_ac = &fStack_1f8;
      pfStack_b0 = &fStack_1fc;
      pfStack_e4 = &fStack_1f4;
      pfStack_e8 = &fStack_1f0;
      uStack_d0 = 0;
      dVar36 = (double)FLOAT_0000cff8;
      dVar37 = (double)FLOAT_0000cffc;
      dVar34 = (double)(float)((double)CONCAT44(0x43300000,uStack_1c4) - DOUBLE_0000cfd8);
      dVar35 = (double)(float)((double)CONCAT44(0x43300000,uStack_1dc) - DOUBLE_0000cfd8);
      dVar38 = DOUBLE_0000cfe8;
      dVar39 = DOUBLE_0000cfe0;
      dVar40 = DOUBLE_0000cfd8;
      puVar23 = in_r7;
      do {
        puVar8 = (undefined4 *)uVar32;
        if ((uVar12 & 0xffffffff) < 0xda) {
          fStack_1f8 = *(float *)(param_1 + 0x18);
          fStack_1fc = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *puVar8 = 0x5c8;
            fStack_1fc = 2.8026e-45;
            puVar8[1] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          puVar8[(int)fStack_1fc] = 0x1000000;
          puVar6 = *(uint **)(param_1 + 0x7c);
          *puVar6 = ((int)puVar8 - (int)puVar6 >> 2) + (int)fStack_1fc | *puVar6;
          iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       pfStack_ac,pfStack_b0,1);
          if (iVar11 == 0) {
            uVar12 = (ulonglong)uStack_cc;
            *(undefined4 *)((int)fStack_1f8 + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = fStack_1f8;
            uVar32 = (ulonglong)(uint)fStack_1f8 + 0x20;
            lVar14 = (ulonglong)(uint)fStack_1f8 + 0x38;
            *(int *)(param_1 + 0x7c) = (int)fStack_1f8 + 0x1c;
            pdVar18 = (dword *)((int)fStack_1f8 + 0x24);
            pdVar20 = (dword *)((int)fStack_1f8 + 0x28);
            pdVar15 = (dword *)((int)fStack_1f8 + 0x2c);
            pdVar16 = (dword *)((int)fStack_1f8 + 0x30);
            pdVar13 = (dword *)((int)fStack_1f8 + 0x34);
          }
          else {
            uVar12 = (ulonglong)uStack_cc;
            uVar32 = 0;
            pdVar18 = &__mh_bundle_header.cputype;
            pdVar20 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar15 = &__mh_bundle_header.filetype;
            pdVar16 = &__mh_bundle_header.ncmds;
            pdVar13 = &__mh_bundle_header.sizeofcmds;
            lVar14 = 0x18;
          }
        }
        else {
          pdVar18 = puVar8 + 1;
          pdVar20 = puVar8 + 2;
          pdVar15 = puVar8 + 3;
          pdVar16 = puVar8 + 4;
          pdVar13 = puVar8 + 5;
          lVar14 = uVar32 + 0x18;
        }
        puVar6 = *(uint **)(param_1 + 0x7c);
        puVar8 = (undefined4 *)uVar32;
        *puVar6 = (int)puVar8 - (int)puVar6 >> 2 | *puVar6;
        *(undefined4 **)(param_1 + 0x7c) = puVar8;
        *puVar8 = 0xa000000;
        *pdVar18 = *(dword *)(param_1 + 0x84);
        puVar6 = *(uint **)(param_1 + 0x7c);
        *puVar6 = (int)pdVar20 - (int)puVar6 >> 2 | *puVar6;
        *(dword **)(param_1 + 0x7c) = pdVar20;
        *pdVar20 = 0x10000000;
        *pdVar15 = *(dword *)*DAT_0000e6e4;
        *pdVar16 = DAT_0000e6e4[7];
        if (DAT_0000e6c0 == 0x10) {
          *pdVar13 = 3;
        }
        else {
          *pdVar13 = 6;
        }
        iVar11 = *(int *)(param_1 + 0x70);
        puVar8 = (undefined4 *)lVar14;
        *puVar8 = 0x850;
        puVar8[1] = 0x100;
        puVar8[2] = 0x887;
        puVar8[3] = 0x1c000;
        puVar8[4] = 0x82c;
        puVar8[5] = 0;
        puVar8[6] = 0x1002;
        puVar8[7] = 0;
        puVar8[8] = 0x824;
        puVar8[9] = 1;
        puVar8[10] = 0x825;
        puVar8[0xb] = 2;
        puVar8[0xc] = 0x82d;
        puVar8[0xd] = 3;
        puVar8[0xe] = 0x854;
        puVar8[0xf] = 0x26010006;
        puVar8[0x10] = 0x878;
        puVar8[0x11] = 0xf688f688;
        puVar8[0x12] = 0x10a2;
        puVar8[0x13] = 0;
        puVar8[0x14] = 0x1381;
        puVar8[0x15] = 0;
        puVar8[0x16] = 0x109e;
        puVar8[0x17] = 5;
        puVar8[0x18] = 0x1383;
        puVar8[0x19] = 0xf;
        puVar8[0x1a] = 0x1004;
        puVar8[0x1b] = 0x66666666;
        puVar8[0x1c] = 0x1005;
        puVar8[0x1d] = 0x66666666;
        puVar8[0x1e] = 0x10ae;
        puVar8[0x1f] = 0;
        puVar8[0x20] = 0x10ea;
        puVar8[0x21] = 0x2da49525;
        puVar8[0x22] = 0x10fa;
        puVar8[0x23] = 0xffffff;
        puVar8[0x24] = 0x10f4;
        puVar8[0x25] = 0xffff;
        puVar8[0x26] = 0x10f8;
        puVar8[0x27] = 0;
        puVar8[0x28] = 0x10f9;
        puVar8[0x29] = *(uint *)(param_1 + 0x54) & 0x1fff |
                       (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
        puVar8[0x2a] = 0x13c0;
        puVar8[0x2b] = 0;
        puVar8[0x2c] = 0x13c1;
        puVar8[0x2d] = 0;
        puVar8[0x2e] = 0x10c0;
        puVar8[0x2f] = 0x40002;
        puVar8[0x30] = 0x10c1;
        puVar8[0x31] = 0;
        puVar8[0x32] = 0x10c8;
        puVar8[0x33] = 0x10;
        puVar8[0x34] = 0x101d;
        puVar8[0x35] = 0x280c2040;
        puVar8[0x36] = 0x1041;
        puVar8[0x37] = 1;
        puVar8[0x38] = 0x1040;
        puVar8[0x39] = 0;
        puVar8[0x3a] = 0x1100;
        puVar8[0x3b] = 0x2a92;
        puVar8[0x3c] = 0x1120;
        sVar4 = *(short *)(param_1 + 0x50);
        sVar5 = *(short *)(param_1 + 0x52);
        uVar24 = (int)sVar4 - 1;
        iVar10 = sVar5 + -1;
        puVar8[0x3d] = uVar24 & 0x7ff | iVar10 * 0x800 & 0x3ff800U | 0x80000000;
        puVar8[0x3e] = 0x1130;
        puVar8[0x3f] = 0x5300c - (uint)(iVar11 == 3);
        puVar8[0x40] = 0x1140;
        puVar8[0x41] = *(int *)(param_1 + 0x5c) - 1U & 0x3fff | uVar24 * 0x10 & 0x8000 |
                       iVar10 * 0x20 & 0x10000U;
        if (iVar11 != 3) {
          uStack_1c0 = 0x43300000;
          dVar33 = dVar34 / dVar37;
          uStack_1b8 = 0x43300000;
          uStack_1b0 = 0x43300000;
          uStack_1ac = in_r8 & 0xff;
          uStack_1bc = in_r8 >> 0x10 & 0xff;
          uStack_1b4 = in_r8 >> 8 & 0xff;
          dVar1 = (double)(float)((double)CONCAT44(0x43300000,uStack_1bc) - dVar40) / dVar37;
          dVar2 = (double)(float)((double)CONCAT44(0x43300000,uStack_1b4) - dVar40) / dVar37;
          dVar3 = (double)(float)((double)CONCAT44(0x43300000,uStack_1ac) - dVar40) / dVar37;
        }
        else {
          uStack_1d8 = 0x43300000;
          dVar1 = dVar35 / dVar36;
          uStack_1d0 = 0x43300000;
          afStack_1ec[1] = 176.0;
          uStack_1d4 = in_r8 >> 5 & 0x1f;
          uStack_1cc = in_r8 & 0x1f;
          uStack_1e4 = in_r8 >> 0xf & 1;
          dVar33 = (double)CONCAT44(0x43300000,uStack_1e4) - dVar40;
          dVar2 = (double)(float)((double)CONCAT44(0x43300000,uStack_1d4) - dVar40) / dVar36;
          dVar3 = (double)(float)((double)CONCAT44(0x43300000,uStack_1cc) - dVar40) / dVar36;
        }
        puVar8[0x42] = 0x1094;
        puVar8[0x43] = 0x10000;
        puVar8[0x44] = 0x1095;
        puVar8[0x45] = (float)dVar1;
        puVar8[0x46] = 0x1095;
        puVar8[0x47] = (float)dVar2;
        puVar8[0x48] = 0x1095;
        puVar8[0x49] = (float)dVar3;
        puVar8[0x4a] = 0x1095;
        puVar8[0x4b] = (float)dVar33;
        uVar24 = (uint)uVar22;
        if (iVar11 != 3) {
          uStack_184 = (uint)(byte)(uVar22 >> 0x18);
          uStack_188 = 0x43300000;
          uStack_17c = (ushort)(uVar22 >> 0x10) & 0xff;
          uStack_180 = 0x43300000;
          uStack_178 = 0x43300000;
          uStack_170 = 0x43300000;
          uStack_174 = uVar24 >> 8 & 0xff;
          uStack_16c = uVar24 & 0xff;
          fVar17 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_184) - dVar40) /
                          dVar37);
          dVar33 = (double)(float)((double)CONCAT44(0x43300000,uStack_17c) - dVar40) / dVar37;
          dVar1 = (double)(float)((double)CONCAT44(0x43300000,uStack_174) - dVar40) / dVar37;
          fVar19 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_16c) - dVar40) /
                          dVar37);
          fStack_a0 = fVar19;
        }
        else {
          uStack_19c = uVar24 >> 10 & 0x1f;
          uStack_1a0 = 0x43300000;
          uStack_194 = uVar24 >> 5 & 0x1f;
          uStack_198 = 0x43300000;
          uStack_190 = 0x43300000;
          uStack_1a8 = 0x43300000;
          uStack_18c = uVar24 & 0x1f;
          uStack_1a4 = uVar24 >> 0xf & 1;
          fVar17 = (float)((double)CONCAT44(0x43300000,uStack_1a4) - dVar40);
          dVar33 = (double)(float)((double)CONCAT44(0x43300000,uStack_19c) - dVar40) / dVar36;
          dVar1 = (double)(float)((double)CONCAT44(0x43300000,uStack_194) - dVar40) / dVar36;
          fVar19 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack_18c) - dVar40) /
                          dVar36);
          fStack_a0 = fVar17;
        }
        puVar8[0x4c] = 0x1095;
        puVar8[0x4d] = (float)dVar33;
        puVar8[0x4e] = 0x1095;
        puVar8[0x4f] = (float)dVar1;
        puVar8[0x50] = 0x1095;
        puVar8[0x51] = fVar19;
        puVar8[0x52] = 0x1095;
        puVar8[0x53] = fVar17;
        puVar8[0x54] = 0x1094;
        puVar8[0x55] = 0;
        puVar8[0x56] = 0x1095;
        puVar8[0x57] = 0x7803;
        puVar8[0x58] = 0x1095;
        puVar8[0x59] = 0x2400000;
        puVar8[0x5a] = 0x1095;
        puVar8[0x5b] = 0x3900e400;
        puVar8[0x5c] = 0x1095;
        puVar8[0x5d] = 0;
        puVar8[0x5e] = 0x1095;
        puVar8[0x5f] = 0;
        puVar8[0x60] = 0x1095;
        puVar8[0x61] = 0;
        puVar8[0x62] = 0x1095;
        puVar8[99] = 0x7804;
        puVar8[100] = 0x1095;
        puVar8[0x65] = 0x40040000;
        puVar8[0x66] = 0x1095;
        puVar8[0x67] = 0x40040000;
        puVar8[0x68] = 0x1095;
        puVar8[0x69] = uStack_c8;
        puVar8[0x6a] = 0x1095;
        puVar8[0x6b] = uStack_c4;
        puVar8[0x6c] = 0x1095;
        puVar8[0x6d] = uStack_c0;
        puVar8[0x6e] = 0x1095;
        puVar8[0x6f] = 0x7800;
        puVar8[0x70] = 0x1095;
        puVar8[0x71] = 1;
        puVar8[0x72] = 0x1095;
        puVar8[0x73] = 1;
        puVar8[0x74] = 0x1095;
        puVar8[0x75] = uStack_bc;
        puVar8[0x76] = 0x1095;
        puVar8[0x77] = uStack_b8;
        puVar8[0x78] = 0x1095;
        puVar8[0x79] = 0x12;
        puVar8[0x7a] = 0x1095;
        puVar8[0x7b] = 0x7800;
        puVar8[0x7c] = 0x1095;
        puVar8[0x7d] = 0x140400;
        puVar8[0x7e] = 0x1095;
        puVar8[0x7f] = 0x140400;
        puVar8[0x80] = 0x1095;
        puVar8[0x81] = uStack_b4;
        puVar8[0x82] = 0x1095;
        puVar8[0x83] = 0x60d036;
        puVar8[0x84] = 0x1095;
        puVar8[0x85] = 0xdda22038;
        puVar8[0x86] = 0x1095;
        puVar8[0x87] = 0x7800;
        puVar8[0x88] = 0x1095;
        puVar8[0x89] = 0x40040400;
        puVar8[0x8a] = 0x1095;
        puVar8[0x8b] = 0x40040400;
        puVar8[0x8c] = 0x1095;
        puVar8[0x8d] = uStack_c8;
        puVar8[0x8e] = 0x1095;
        puVar8[0x8f] = uStack_c4;
        puVar8[0x90] = 0x1095;
        puVar8[0x91] = uStack_c0;
        puVar8[0x92] = 0x1095;
        puVar8[0x93] = 0x7800;
        puVar8[0x94] = 0x1095;
        puVar8[0x95] = 1;
        puVar8[0x96] = 0x1095;
        puVar8[0x97] = 1;
        puVar8[0x98] = 0x1095;
        puVar8[0x99] = uStack_bc;
        puVar8[0x9a] = 0x1095;
        puVar8[0x9b] = uStack_b8;
        puVar8[0x9c] = 0x1095;
        puVar8[0x9d] = 0x12;
        puVar8[0x9e] = 0x1095;
        puVar8[0x9f] = 0x78101;
        puVar8[0xa0] = 0x1095;
        puVar8[0xa1] = 0x140003;
        puVar8[0xa2] = 0x1095;
        puVar8[0xa3] = 0x140003;
        puVar8[0xa4] = 0x1095;
        puVar8[0xa5] = uStack_b4;
        puVar8[0xa6] = 0x1095;
        puVar8[0xa7] = 0x60d006;
        puVar8[0xa8] = 0x1095;
        puVar8[0xa9] = 0xdda22008;
        puVar8[0xaa] = 0x1189;
        puVar8[0xab] = 0;
        puVar8[0xac] = 0x1181;
        puVar8[0xad] = 5;
        puVar8[0xae] = 0x118d;
        puVar8[0xaf] = 0x60000;
        puVar8[0xb0] = 0x118e;
        puVar8[0xb1] = 0;
        puVar8[0xb2] = 0x118c;
        puVar8[0xb3] = 0x60000;
        puVar8[0xb4] = 0x11a9;
        puVar8[0xb5] = 0x1b01;
        puVar8[0xb6] = 0x11aa;
        puVar8[0xb7] = 0xf;
        puVar8[0xb8] = 0x11ab;
        puVar8[0xb9] = 0xf;
        puVar8[0xba] = 0x11ac;
        puVar8[0xbb] = 0xf;
        puVar8[0xbc] = 0x12f0;
        puVar8[0xbd] = 0;
        puVar8[0xbe] = 0x12f5;
        puVar8[0xbf] = 0;
        uStack_148 = 0x43300000;
        uStack_138 = 0x43300000;
        uStack_144 = (int)sVar4 ^ 0x80000000;
        uStack_134 = (int)sVar5 ^ 0x80000000;
        uStack_168 = 0x43300000;
        uStack_160 = 0x43300000;
        uStack_158 = 0x43300000;
        uStack_150 = 0x43300000;
        uVar31 = puVar23[0x17] + *(int *)(param_1 + 0x60);
        uVar29 = puVar23[0x18] + *(int *)(param_1 + 100);
        uVar30 = uVar31 + puVar23[0x19];
        uVar24 = uVar29 + puVar23[0x1a];
        uStack_164 = uVar31 ^ 0x80000000;
        uStack_154 = uVar29 ^ 0x80000000;
        uStack_15c = uVar30 ^ 0x80000000;
        uStack_14c = uVar24 ^ 0x80000000;
        fStack_208 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_144) - dVar39);
        fStack_200 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_134) - dVar39);
        afStack_1ec[0] = fStack_208 * (float)((double)CONCAT44(0x43300000,uStack_164) - dVar39);
        fStack_208 = fStack_208 * (float)((double)CONCAT44(0x43300000,uStack_15c) - dVar39);
        fStack_204 = fStack_200 * (float)((double)CONCAT44(0x43300000,uStack_154) - dVar39);
        fStack_200 = fStack_200 * (float)((double)CONCAT44(0x43300000,uStack_14c) - dVar39);
        puVar8[0xc0] = 0xc00c3500;
        puVar8[0xc1] = 0x4003d;
        uVar28 = uVar31 | uVar24 * 0x10000;
        puVar8[0xc2] = uVar28;
        fVar19 = *pfStack_d4;
        puVar8[0xc3] = fVar19;
        fVar17 = *pfStack_d8;
        puVar8[0xc4] = fVar17;
        uVar27 = uVar31 | uVar29 * 0x10000;
        puVar8[0xc5] = uVar27;
        puVar8[0xc6] = fVar19;
        fVar19 = *pfStack_dc;
        puVar8[199] = fVar19;
        uVar26 = uVar30 | uVar29 * 0x10000;
        puVar8[200] = uVar26;
        fVar7 = *pfStack_e0;
        puVar8[0xc9] = fVar7;
        puVar8[0xca] = fVar19;
        uVar25 = uVar30 | uVar24 * 0x10000;
        puVar8[0xcb] = uVar25;
        puVar8[0xcc] = fVar7;
        puVar8[0xcd] = fVar17;
        puVar8[0xce] = 0x1393;
        puVar8[0xcf] = 10;
        puVar8[0xd0] = 0x5c8;
        puVar8[0xd1] = 0x20000;
        uVar12 = uVar12 - 0xd8;
        puVar21 = puVar8 + 0xd2;
        if ((uVar12 & 0xffffffff) < 0x86) {
          fStack_1fc = *(float *)(param_1 + 0x18);
          fStack_1f8 = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *puVar21 = 0x5c8;
            fStack_1f8 = 2.8026e-45;
            puVar8[0xd3] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          puVar21[(int)fStack_1f8] = 0x1000000;
          puVar6 = *(uint **)(param_1 + 0x7c);
          *puVar6 = ((int)puVar21 - (int)puVar6 >> 2) + (int)fStack_1f8 | *puVar6;
          iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       pfStack_b0,pfStack_ac,1);
          if (iVar11 == 0) {
            uVar12 = (ulonglong)uStack_cc;
            *(undefined4 *)((int)fStack_1fc + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = fStack_1fc;
            puVar21 = (undefined4 *)((int)fStack_1fc + 0x20);
            lVar14 = (ulonglong)(uint)fStack_1fc + 0x38;
            *(int *)(param_1 + 0x7c) = (int)fStack_1fc + 0x1c;
            pdVar13 = (dword *)((int)fStack_1fc + 0x24);
            pdVar16 = (dword *)((int)fStack_1fc + 0x28);
            pdVar18 = (dword *)((int)fStack_1fc + 0x2c);
            pdVar20 = (dword *)((int)fStack_1fc + 0x30);
            pdVar15 = (dword *)((int)fStack_1fc + 0x34);
          }
          else {
            uVar12 = (ulonglong)uStack_cc;
            puVar21 = (undefined4 *)0x0;
            pdVar13 = &__mh_bundle_header.cputype;
            pdVar16 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar18 = &__mh_bundle_header.filetype;
            pdVar20 = &__mh_bundle_header.ncmds;
            pdVar15 = &__mh_bundle_header.sizeofcmds;
            lVar14 = 0x18;
          }
        }
        else {
          lVar14 = lVar14 + 0x360;
          pdVar13 = puVar8 + 0xd3;
          pdVar16 = puVar8 + 0xd4;
          pdVar18 = puVar8 + 0xd5;
          pdVar20 = puVar8 + 0xd6;
          pdVar15 = puVar8 + 0xd7;
        }
        puVar6 = *(uint **)(param_1 + 0x7c);
        *puVar6 = (int)puVar21 - (int)puVar6 >> 2 | *puVar6;
        *(undefined4 **)(param_1 + 0x7c) = puVar21;
        *puVar21 = 0x11000000;
        *pdVar13 = *(dword *)(param_1 + 0x84);
        *pdVar16 = 0;
        *pdVar18 = 0;
        puVar6 = *(uint **)(param_1 + 0x7c);
        *puVar6 = (int)pdVar20 - (int)puVar6 >> 2 | *puVar6;
        *(dword **)(param_1 + 0x7c) = pdVar20;
        *pdVar20 = 0x4000000;
        *pdVar15 = *(dword *)*DAT_0000e6e4;
        puVar8 = DAT_0000e6e4;
        iVar11 = DAT_0000e6e4[0xc];
        if (iVar11 == 3) {
          iVar11 = 0xb;
        }
        else if (iVar11 == 6) {
          iVar11 = 0xc;
        }
        uVar32 = ((int (*)())_radeon3DCopySetup)(param_1,lVar14,DAT_0000e6e4 + 3,iVar11,0,0,0,0);
        uStack_128 = 0x43300000;
        uStack_120 = 0x43300000;
        uStack_118 = 0x43300000;
        uStack_110 = 0x43300000;
        iVar11 = (int)lVar14;
        *(undefined4 *)(iVar11 + (int)((uVar32 & 0xffffffff) << 2)) = 0xc00c3500;
        *(undefined4 *)(iVar11 + (int)((uVar32 + 1 & 0xffffffff) << 2)) = 0x4003d;
        uStack_108 = 0x43300000;
        uStack_104 = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
        fStack_1fc = (float)((double)(float)((double)CONCAT44(0x43300000,uVar31) - dVar40) *
                            (dVar38 / ((double)CONCAT44(0x43300000,uStack_104) - dVar39)));
        uStack_100 = 0x43300000;
        uStack_fc = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
        fStack_1f0 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar30) - dVar40) *
                            (dVar38 / ((double)CONCAT44(0x43300000,uStack_fc) - dVar39)));
        uStack_f8 = 0x43300000;
        uStack_f4 = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
        fStack_1f4 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar29) - dVar40) *
                            (dVar38 / ((double)CONCAT44(0x43300000,uStack_f4) - dVar39)));
        uStack_f0 = 0x43300000;
        uStack_ec = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
        fStack_1f8 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar24) - dVar40) *
                            (dVar38 / ((double)CONCAT44(0x43300000,uStack_ec) - dVar39)));
        *(uint *)(iVar11 + (int)((uVar32 + 2 & 0xffffffff) << 2)) = uVar28;
        fVar19 = *pfStack_b0;
        *(float *)(iVar11 + (int)((uVar32 + 3 & 0xffffffff) << 2)) = fVar19;
        fVar17 = *pfStack_ac;
        *(float *)(iVar11 + (int)((uVar32 + 4 & 0xffffffff) << 2)) = fVar17;
        *(uint *)(iVar11 + (int)((uVar32 + 5 & 0xffffffff) << 2)) = uVar27;
        *(float *)(iVar11 + (int)((uVar32 + 6 & 0xffffffff) << 2)) = fVar19;
        fVar19 = *pfStack_e4;
        *(float *)(iVar11 + (int)((uVar32 + 7 & 0xffffffff) << 2)) = fVar19;
        *(uint *)(iVar11 + (int)((uVar32 + 8 & 0xffffffff) << 2)) = uVar26;
        fVar7 = *pfStack_e8;
        *(float *)(iVar11 + (int)((uVar32 + 9 & 0xffffffff) << 2)) = fVar7;
        *(float *)(iVar11 + (int)((uVar32 + 10 & 0xffffffff) << 2)) = fVar19;
        *(uint *)(iVar11 + (int)((uVar32 + 0xb & 0xffffffff) << 2)) = uVar25;
        *(float *)(iVar11 + (int)((uVar32 + 0xc & 0xffffffff) << 2)) = fVar7;
        *(float *)(iVar11 + (int)((uVar32 + 0xd & 0xffffffff) << 2)) = fVar17;
        *(undefined4 *)(iVar11 + (int)((uVar32 + 0xe & 0xffffffff) << 2)) = 0x1393;
        *(undefined4 *)(iVar11 + (int)((uVar32 + 0xf & 0xffffffff) << 2)) = 10;
        *(undefined4 *)(iVar11 + (int)((uVar32 + 0x10 & 0xffffffff) << 2)) = 0x5c8;
        *(undefined4 *)(iVar11 + (int)((uVar32 + 0x11 & 0xffffffff) << 2)) = 0x20000;
        uVar12 = (uVar12 - 6) - (uVar32 + 0x12);
        puVar23 = puVar23 + 4;
        uVar32 = lVar14 + (uVar32 + 0x12 & 0x3fffffff) * 4;
        uStack_d0 = uStack_d0 + 1;
        uStack_124 = uVar31;
        uStack_11c = uVar30;
        uStack_114 = uVar29;
        uStack_10c = uVar24;
      } while (uStack_d0 < in_r7[0x16]);
    }
    uVar9 = 0;
    *(int *)(param_1 + 0x80) = (int)uVar32;
  }
  return uVar9;
}

/* _radeonSolidScanlines @ 0xba90 (3660 bytes) */
undefined8 _radeonSolidScanlines()
{
  float fVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar6;
  int iVar7;
  ulonglong uVar5;
  int iVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  longlong lVar8;
  ulonglong uVar9;
  longlong lVar14;
  longlong lVar15;
  ulonglong in_r6;
  longlong lVar16;
  ulonglong uVar17;
  undefined4 *in_r7;
  ulonglong uVar18;
  uint uVar21;
  longlong lVar19;
  ulonglong uVar20;
  float fVar22;
  undefined8 in_r8;
  uint *puVar24;
  longlong lVar23;
  float fVar25;
  bool bVar28;
  longlong lVar26;
  ulonglong uVar27;
  ulonglong uVar29;
  longlong lVar30;
  ulonglong uVar31;
  uint uVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  uint uVar35;
  longlong lVar36;
  ulonglong uVar37;
  ulonglong uVar38;
  undefined4 *puVar39;
  double dVar40;
  double dVar41;
  double dVar42;
  double dVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  uint uStack_1a4;
  uint uStack_1a0;
  float fStack_19c;
  undefined4 uStack_178;
  int iStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  undefined4 uStack_168;
  int iStack_164;
  undefined4 uStack_160;
  int iStack_15c;
  undefined4 uStack_158;
  uint uStack_154;
  undefined4 uStack_150;
  uint uStack_14c;
  undefined4 uStack_148;
  uint uStack_144;
  undefined4 uStack_140;
  uint uStack_13c;
  undefined4 uStack_138;
  uint uStack_134;
  undefined4 uStack_130;
  uint uStack_12c;
  undefined4 uStack_128;
  uint uStack_124;
  undefined4 uStack_120;
  uint uStack_11c;
  uint uStack_118;
  uint uStack_114;
  uint uStack_110;
  undefined4 *puStack_10c;
  uint uStack_108;
  int iStack_104;
  uint uStack_100;
  int iStack_fc;
  undefined4 uStack_f8;
  uint uStack_f4;
  uint uStack_f0;
  undefined4 uStack_ec;
  int iStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  int iStack_dc;
  
  uVar21 = uStack_1a0;
  iVar10 = ((int (*)())FUN_0000c954)();
  if ((int)(in_r6 & 0x7ffff000) == 0x6000) {
    puVar39 = *(undefined4 **)(iVar10 + 0x80);
    iVar12 = *(int *)(iVar10 + 0x18);
    if (puVar39 != (undefined4 *)0x0) {
      if ((uint)((*(int *)(iVar12 + 0x10) + -7) - ((int)puVar39 - (iVar12 + 0x20) >> 2)) <
          in_r7[0x16] * 0xc + 0x6eU) {
        uStack_1a0 = 0;
        if (*(int *)(iVar10 + 0x8c) == 0) {
          *puVar39 = 0x5c8;
          uStack_1a0 = 2;
          puVar39[1] = 0xc000;
          *(undefined4 *)(iVar10 + 0x94) = 0;
        }
        puVar39[uStack_1a0] = 0x1000000;
        puVar2 = PTR_0000e694;
        puVar13 = *(uint **)(iVar10 + 0x7c);
        *puVar13 = ((int)puVar39 - (int)puVar13 >> 2) + uStack_1a0 | *puVar13;
        iVar11 = _IOConnectMapMemory(*(undefined4 *)(iVar10 + 0xc),0,*(undefined4 *)puVar2,
                                     &uStack_1a4,&uStack_1a0,1);
        if (iVar11 == 0) {
          *(undefined4 *)(iVar12 + 0x1c) = 0;
          *(int *)(iVar10 + 0x18) = iVar12;
          puVar39 = (undefined4 *)(iVar12 + 0x20);
          *(int *)(iVar10 + 0x7c) = iVar12 + 0x1c;
        }
        else {
          puVar39 = (undefined4 *)0x0;
          *(undefined4 *)(iVar10 + 0x7c) = 0;
          *(undefined4 *)(iVar10 + 0x18) = 0;
        }
      }
      iVar12 = ((int (*)())_radeon3DFillSetup)(puVar39,0,in_r8,iVar10);
      uVar35 = in_r7[0x16];
      uVar18 = (ulonglong)uVar35;
      puVar13 = puVar39 + iVar12;
      *puVar13 = (uint)((uVar18 * 0xc & 0xffffffff) << 0x10) | 0xc0003500;
      puVar24 = puVar13 + 2;
      puVar13[1] = uVar35 << 0x12 | 0x3d;
      uVar6 = in_r7[0x17] + *(int *)(iVar10 + 100);
      fVar25 = (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - DOUBLE_0000cfe0);
      fVar22 = (float)((double)CONCAT44(0x43300000,uVar6 + in_r7[0x18] ^ 0x80000000) -
                      DOUBLE_0000cfe0);
      if (uVar35 != 0) {
        if (uVar18 == 0) {
          uVar18 = 1;
        }
        do {
          *puVar24 = uStack_1a4;
          puVar24[1] = (uint)fVar22;
          puVar24[2] = 0;
          puVar24[3] = uStack_1a4;
          puVar24[4] = (uint)fVar25;
          puVar24[5] = 0;
          puVar24[6] = uVar21;
          puVar24[7] = (uint)fVar25;
          puVar24[8] = 0;
          puVar24[9] = uVar21;
          puVar24[10] = (uint)fVar22;
          puVar13 = puVar24 + 0xb;
          puVar24 = puVar24 + 0xc;
          *puVar13 = 0;
          uVar18 = uVar18 - 1;
        } while (uVar18 != 0);
      }
      *puVar24 = 0x1393;
      puVar24[1] = 10;
      puVar24[2] = 0x5c8;
      puVar24[3] = 0x20000;
      *(uint **)(iVar10 + 0x80) = puVar24 + 4;
      return 0;
    }
  }
  else {
    uVar21 = *(uint *)(iVar10 + 0x80);
    uVar18 = (ulonglong)uVar21;
    iVar12 = *(int *)(iVar10 + 0x18);
    uVar37 = (ulonglong)*(uint *)(iVar12 + 0x10) - 7;
    if ((uVar21 != 0) &&
       (iVar11 = ((int (*)())_createTextureBuffer)(iVar10,0x40,0x40,*(int *)(iVar10 + 0x70) == 3), iVar11 != 0))
    {
      iStack_e8 = 0xbaa4;
      uVar33 = uVar37 - (longlong)((int)(uVar21 - (iVar12 + 0x20)) >> 2);
      _fillTextureWithPattern(in_r8,in_r6 & 0x7ffff000,*in_r7,in_r7[1]);
      iVar12 = *(int *)(((unsigned char *)0x00002ca4) + iStack_e8);
      iStack_104 = *(int *)(iVar12 + 0x30);
      if (iStack_104 == 3) {
        iStack_104 = 0xb;
      }
      else if (iStack_104 == 6) {
        iStack_104 = 0xc;
      }
      uVar21 = in_r7[0x16];
      uStack_178 = 0x43300000;
      uVar31 = (ulonglong)(uint)in_r7[0x17] + (ulonglong)*(uint *)(iVar10 + 100);
      iStack_174 = ((uint)uVar31 & 7) + in_r7[3];
      uVar34 = uVar31 + (uint)in_r7[0x18];
      dVar51 = (double)(float)((double)CONCAT44(0x43300000,iStack_174) - DOUBLE_0000cfd8);
      if (uVar21 != 0) {
        uStack_118 = (uint)uVar34;
        if ((uVar31 + 8 & 0xffffffff) < (uVar34 & 0xffffffff)) {
          uStack_118 = (uint)(uVar31 + 8);
        }
        dVar45 = (double)FLOAT_0000d00c;
        dVar47 = (double)FLOAT_0000d008;
        bVar28 = true;
        uStack_100 = 0;
        dVar42 = (double)(float)(dVar51 + dVar47);
        dVar41 = (double)(float)(dVar51 + dVar45);
        dVar49 = DOUBLE_0000cfd8;
        puStack_10c = in_r7;
        do {
          uStack_170 = 0x43300000;
          uVar35 = *(int *)(iVar10 + 0x60) + puStack_10c[0x19];
          iStack_16c = (uVar35 & 7) + in_r7[2];
          uVar6 = *(int *)(iVar10 + 0x60) + puStack_10c[0x1a];
          dVar50 = (double)(float)((double)CONCAT44(0x43300000,iStack_16c) - dVar49);
          if ((uVar31 & 0xffffffff) < (uVar34 & 0xffffffff)) {
            uStack_114 = uVar35 + 8;
            uStack_108 = uVar6;
            if (uStack_114 < uVar6) {
              uStack_108 = uStack_114;
            }
            dVar48 = (double)(float)(dVar50 + dVar47);
            dVar44 = (double)(float)(dVar50 + dVar45);
            uStack_f4 = uVar35 & 0x1fff;
            uStack_f0 = uVar6 & 0x1fff;
            uVar38 = (ulonglong)uStack_118;
            uStack_f8 = 0xc000;
            uStack_ec = 0x4003d;
            iStack_fc = 1;
            uVar5 = uVar31;
            dVar43 = dVar41;
            dVar46 = dVar42;
            dVar52 = DOUBLE_0000cfe8;
            dVar53 = DOUBLE_0000cfe0;
            do {
              if (uVar35 < uVar6) {
                iVar11 = (int)uVar38;
                iVar7 = (int)uVar5;
                uVar21 = uStack_108;
                uVar32 = uVar35;
                if (!bVar28) {
                  uStack_e4 = (uint)((uVar38 & 0xffffffff) << 0x10);
                  uStack_e0 = (uint)((uVar5 & 0xffffffff) << 0x10);
                  iStack_dc = iVar11 - iVar7;
                  uVar3 = uStack_114;
                  goto LAB_0000c1c8;
                }
                if ((uVar33 & 0xffffffff) < 0x8e) {
                  uVar3 = *(uint *)(iVar10 + 0x18);
                  uStack_1a0 = 0;
                  puVar39 = (undefined4 *)uVar18;
                  if (*(int *)(iVar10 + 0x8c) == 0) {
                    *puVar39 = 0x5c8;
                    uStack_1a0 = 2;
                    puVar39[1] = uStack_f8;
                    *(undefined4 *)(iVar10 + 0x94) = 0;
                  }
                  puVar39[uStack_1a0] = 0x1000000;
                  puVar2 = PTR_0000e694;
                  puVar13 = *(uint **)(iVar10 + 0x7c);
                  *puVar13 = ((int)puVar39 - (int)puVar13 >> 2) + uStack_1a0 | *puVar13;
                  iVar4 = _IOConnectMapMemory(*(undefined4 *)(iVar10 + 0xc),0,*(undefined4 *)puVar2,
                                              &uStack_1a4,&uStack_1a0,1);
                  uVar21 = uStack_108;
                  if (iVar4 == 0) {
                    uStack_e4 = (uint)((uVar38 & 0xffffffff) << 0x10);
                    uStack_e0 = (uint)((uVar5 & 0xffffffff) << 0x10);
                    iStack_dc = iVar11 - iVar7;
                    *(undefined4 *)(uVar3 + 0x1c) = 0;
                    uVar33 = (ulonglong)uVar3;
                    uVar18 = uVar33 + 0x20;
                    uStack_110 = uStack_114;
                    *(uint *)(iVar10 + 0x18) = uVar3;
                    uVar38 = uVar33 + 0x48;
                    *(uint *)(iVar10 + 0x7c) = uVar3 + 0x1c;
                    lVar36 = uVar33 + 0x24;
                    lVar30 = uVar33 + 0x28;
                    lVar8 = uVar33 + 0x2c;
                    lVar26 = uVar33 + 0x30;
                    lVar14 = uVar33 + 0x34;
                    lVar15 = uVar33 + 0x38;
                    lVar16 = uVar33 + 0x3c;
                    lVar19 = uVar33 + 0x40;
                    lVar23 = uVar33 + 0x44;
                    uVar33 = uVar37;
                  }
                  else {
                    uStack_e4 = (uint)((uVar38 & 0xffffffff) << 0x10);
                    iStack_dc = iVar11 - iVar7;
                    uStack_e0 = (uint)((uVar5 & 0xffffffff) << 0x10);
                    uStack_110 = uStack_114;
                    *(undefined4 *)(iVar10 + 0x7c) = 0;
                    *(undefined4 *)(iVar10 + 0x18) = 0;
                    uVar18 = 0;
                    lVar36 = 4;
                    lVar30 = 8;
                    lVar8 = 0xc;
                    lVar26 = 0x10;
                    lVar14 = 0x14;
                    lVar15 = 0x18;
                    lVar16 = 0x1c;
                    lVar19 = 0x20;
                    lVar23 = 0x24;
                    uVar38 = 0x28;
                    uVar33 = uVar37;
                  }
                }
                else {
                  uStack_e4 = (uint)((uVar38 & 0xffffffff) << 0x10);
                  uStack_e0 = (uint)((uVar5 & 0xffffffff) << 0x10);
                  iStack_dc = iVar11 - iVar7;
                  lVar36 = uVar18 + 4;
                  lVar30 = uVar18 + 8;
                  lVar8 = uVar18 + 0xc;
                  uStack_110 = uStack_114;
                  lVar26 = uVar18 + 0x10;
                  lVar14 = uVar18 + 0x14;
                  lVar15 = uVar18 + 0x18;
                  lVar16 = uVar18 + 0x1c;
                  lVar19 = uVar18 + 0x20;
                  lVar23 = uVar18 + 0x24;
                  uVar38 = uVar18 + 0x28;
                }
                do {
                  puVar13 = *(uint **)(iVar10 + 0x7c);
                  puVar39 = (undefined4 *)uVar18;
                  *puVar13 = (int)puVar39 - (int)puVar13 >> 2 | *puVar13;
                  *(undefined4 **)(iVar10 + 0x7c) = puVar39;
                  *puVar39 = 0x11000000;
                  *(undefined4 *)lVar36 = *(undefined4 *)(iVar10 + 0x84);
                  *(undefined4 *)lVar30 = 0;
                  *(undefined4 *)lVar8 = 0;
                  puVar13 = *(uint **)(iVar10 + 0x7c);
                  puVar39 = (undefined4 *)lVar26;
                  *puVar13 = (int)puVar39 - (int)puVar13 >> 2 | *puVar13;
                  *(undefined4 **)(iVar10 + 0x7c) = puVar39;
                  *puVar39 = 0x8000000;
                  *(undefined4 *)lVar14 =
                       *(undefined4 *)**(undefined4 **)(((unsigned char *)0x00002ca4) + iStack_e8);
                  *(undefined4 *)lVar15 = 0;
                  *(undefined4 *)lVar16 = 0;
                  *(undefined4 *)lVar19 = 0;
                  *(undefined4 *)lVar23 = 0;
                  uVar33 = uVar33 - 10;
                  uVar9 = ((int (*)())_radeon3DCopySetup)(iVar10,uVar38,iVar12 + 0xc,iStack_104,0,0,0,0);
                  lVar8 = (uVar9 & 0x3fffffff) << 2;
                  uVar27 = uVar9 + 1;
                  uVar29 = uVar9 + 2;
                  uVar20 = uVar9 + 3;
                  uVar17 = uVar9 + 4;
                  uVar18 = uVar38;
                  while( true ) {
                    iVar7 = (int)lVar8;
                    iVar11 = (int)uVar18;
                    if (iStack_fc != 0) {
                      *(undefined4 *)(iVar11 + iVar7) = 0x10f8;
                      *(uint *)(iVar11 + (int)((uVar27 & 0xffffffff) << 2)) =
                           uStack_f4 | (uint)((uVar31 & 0xffffffff) << 0xd) & 0x3ffe000;
                      *(undefined4 *)(iVar11 + (int)((uVar29 & 0xffffffff) << 2)) = 0x10f9;
                      *(uint *)(iVar11 + (int)((uVar20 & 0xffffffff) << 2)) =
                           uStack_f0 | (uint)((uVar34 & 0xffffffff) << 0xd) & 0x3ffe000;
                      iVar7 = (int)((uVar17 & 0x3fffffff) << 2);
                      uVar27 = uVar17 + 1;
                      uVar29 = uVar17 + 2;
                      iStack_fc = 0;
                      uVar20 = uVar17 + 3;
                      uVar9 = uVar17;
                      uVar17 = uVar17 + 4;
                    }
                    iVar4 = uVar21 - uVar32;
                    if ((iVar4 == 8) && (iStack_dc == 8)) {
                      *(undefined4 *)(iVar11 + iVar7) = 0xc00c3500;
                      *(undefined4 *)(iVar11 + (int)((uVar27 & 0xffffffff) << 2)) = uStack_ec;
                      uStack_138 = 0x43300000;
                      uStack_134 = (int)*(short *)(iVar12 + 0x10) ^ 0x80000000;
                      fVar1 = (float)(dVar48 * (dVar52 / ((double)CONCAT44(0x43300000,uStack_134) -
                                                         dVar53)));
                      uStack_130 = 0x43300000;
                      uStack_12c = (int)*(short *)(iVar12 + 0x10) ^ 0x80000000;
                      dVar40 = dVar44 * (dVar52 / ((double)CONCAT44(0x43300000,uStack_12c) - dVar53)
                                        );
                      uStack_128 = 0x43300000;
                      uStack_124 = (int)*(short *)(iVar12 + 0x12) ^ 0x80000000;
                      fVar25 = (float)(dVar46 * (dVar52 / ((double)CONCAT44(0x43300000,uStack_124) -
                                                          dVar53)));
                      uStack_120 = 0x43300000;
                      uStack_11c = (int)*(short *)(iVar12 + 0x12) ^ 0x80000000;
                      fVar22 = (float)(dVar43 * (dVar52 / ((double)CONCAT44(0x43300000,uStack_11c) -
                                                          dVar53)));
                      *(uint *)(iVar11 + (int)((uVar29 & 0xffffffff) << 2)) = uVar32 | uStack_e4;
                      *(float *)(iVar11 + (int)((uVar20 & 0xffffffff) << 2)) = fVar1;
                      *(float *)(iVar11 + (int)((uVar17 & 0xffffffff) << 2)) = fVar22;
                      *(uint *)(iVar11 + (int)((uVar9 + 5 & 0xffffffff) << 2)) = uVar32 | uStack_e0;
                      *(float *)(iVar11 + (int)((uVar9 + 6 & 0xffffffff) << 2)) = fVar1;
                      *(float *)(iVar11 + (int)((uVar9 + 7 & 0xffffffff) << 2)) = fVar25;
                      *(uint *)(iVar11 + (int)((uVar9 + 8 & 0xffffffff) << 2)) = uVar21 | uStack_e0;
                      fStack_19c = fVar22;
                    }
                    else {
                      uStack_168 = 0x43300000;
                      uStack_160 = 0x43300000;
                      iStack_15c = iStack_dc;
                      *(undefined4 *)(iVar11 + iVar7) = 0xc00c3500;
                      *(undefined4 *)(iVar11 + (int)((uVar27 & 0xffffffff) << 2)) = uStack_ec;
                      uStack_158 = 0x43300000;
                      uStack_154 = (int)*(short *)(iVar12 + 0x10) ^ 0x80000000;
                      fStack_19c = (float)(dVar48 * (dVar52 / ((double)CONCAT44(0x43300000,
                                                                                uStack_154) - dVar53
                                                              )));
                      uStack_150 = 0x43300000;
                      uStack_14c = (int)*(short *)(iVar12 + 0x10) ^ 0x80000000;
                      dVar40 = (double)(float)(dVar50 + (double)(float)((double)CONCAT44(0x43300000,
                                                                                         iVar4) -
                                                                       dVar49)) *
                               (dVar52 / ((double)CONCAT44(0x43300000,uStack_14c) - dVar53));
                      uStack_148 = 0x43300000;
                      uStack_144 = (int)*(short *)(iVar12 + 0x12) ^ 0x80000000;
                      fVar25 = (float)(dVar46 * (dVar52 / ((double)CONCAT44(0x43300000,uStack_144) -
                                                          dVar53)));
                      uStack_140 = 0x43300000;
                      uStack_13c = (int)*(short *)(iVar12 + 0x12) ^ 0x80000000;
                      fVar22 = (float)((double)(float)(dVar51 + (double)(float)((double)CONCAT44(
                                                  0x43300000,iStack_dc) - dVar49)) *
                                      (dVar52 / ((double)CONCAT44(0x43300000,uStack_13c) - dVar53)))
                      ;
                      *(uint *)(iVar11 + (int)((uVar29 & 0xffffffff) << 2)) = uStack_e4 | uVar32;
                      *(float *)(iVar11 + (int)((uVar20 & 0xffffffff) << 2)) = fStack_19c;
                      *(float *)(iVar11 + (int)((uVar17 & 0xffffffff) << 2)) = fVar22;
                      *(uint *)(iVar11 + (int)((uVar9 + 5 & 0xffffffff) << 2)) = uStack_e0 | uVar32;
                      *(float *)(iVar11 + (int)((uVar9 + 6 & 0xffffffff) << 2)) = fStack_19c;
                      *(float *)(iVar11 + (int)((uVar9 + 7 & 0xffffffff) << 2)) = fVar25;
                      *(uint *)(iVar11 + (int)((uVar9 + 8 & 0xffffffff) << 2)) = uStack_e0 | uVar21;
                      iStack_164 = iVar4;
                    }
                    *(float *)(iVar11 + (int)((uVar9 + 9 & 0xffffffff) << 2)) = (float)dVar40;
                    *(float *)(iVar11 + (int)((uVar9 + 10 & 0xffffffff) << 2)) = fVar25;
                    *(uint *)(iVar11 + (int)((uVar9 + 0xb & 0xffffffff) << 2)) = uVar21 | uStack_e4;
                    *(float *)(iVar11 + (int)((uVar9 + 0xc & 0xffffffff) << 2)) = (float)dVar40;
                    *(float *)(iVar11 + (int)((uVar9 + 0xd & 0xffffffff) << 2)) = fVar22;
                    *(undefined4 *)(iVar11 + (int)((uVar9 + 0xe & 0xffffffff) << 2)) = 0x1393;
                    *(undefined4 *)(iVar11 + (int)((uVar9 + 0xf & 0xffffffff) << 2)) = 10;
                    *(undefined4 *)(iVar11 + (int)((uVar9 + 0x10 & 0xffffffff) << 2)) = 0x5c8;
                    *(undefined4 *)(iVar11 + (int)((uVar9 + 0x11 & 0xffffffff) << 2)) = 0x20000;
                    uVar33 = uVar33 - (uVar9 + 0x12);
                    uVar18 = uVar18 + (uVar9 + 0x12 & 0x3fffffff) * 4;
                    uVar21 = uVar6;
                    if (uVar32 + 0x10 < uVar6) {
                      uVar21 = uVar32 + 0x10;
                    }
                    bVar28 = false;
                    if (uVar6 <= uStack_110) goto LAB_0000c820;
                    uVar3 = uStack_110 + 8;
                    uVar32 = uStack_110;
LAB_0000c1c8:
                    if ((uVar33 & 0xffffffff) < 0x16) break;
                    uVar17 = 4;
                    uVar20 = 3;
                    uVar29 = 2;
                    uVar27 = 1;
                    lVar8 = 0;
                    uVar9 = 0;
                    uStack_110 = uVar3;
                  }
                  uVar3 = *(uint *)(iVar10 + 0x18);
                  uStack_1a4 = 0;
                  puVar39 = (undefined4 *)uVar18;
                  if (*(int *)(iVar10 + 0x8c) == 0) {
                    *puVar39 = 0x5c8;
                    uStack_1a4 = 2;
                    puVar39[1] = uStack_f8;
                    *(undefined4 *)(iVar10 + 0x94) = 0;
                  }
                  puVar39[uStack_1a4] = 0x1000000;
                  puVar2 = PTR_0000e694;
                  puVar13 = *(uint **)(iVar10 + 0x7c);
                  *puVar13 = ((int)puVar39 - (int)puVar13 >> 2) + uStack_1a4 | *puVar13;
                  iVar11 = _IOConnectMapMemory(*(undefined4 *)(iVar10 + 0xc),0,*(undefined4 *)puVar2
                                               ,&uStack_1a0,&uStack_1a4,1);
                  if (iVar11 == 0) {
                    uStack_110 = uVar32 + 8;
                    iStack_fc = 1;
                    *(undefined4 *)(uVar3 + 0x1c) = 0;
                    uVar33 = (ulonglong)uVar3;
                    *(uint *)(iVar10 + 0x18) = uVar3;
                    uVar18 = uVar33 + 0x20;
                    uVar38 = uVar33 + 0x48;
                    *(uint *)(iVar10 + 0x7c) = uVar3 + 0x1c;
                    lVar36 = uVar33 + 0x24;
                    lVar30 = uVar33 + 0x28;
                    lVar8 = uVar33 + 0x2c;
                    lVar26 = uVar33 + 0x30;
                    lVar14 = uVar33 + 0x34;
                    lVar15 = uVar33 + 0x38;
                    lVar16 = uVar33 + 0x3c;
                    lVar19 = uVar33 + 0x40;
                    lVar23 = uVar33 + 0x44;
                    uVar33 = uVar37;
                  }
                  else {
                    uStack_110 = uVar32 + 8;
                    uVar38 = 0x28;
                    lVar23 = 0x24;
                    lVar19 = 0x20;
                    lVar16 = 0x1c;
                    iStack_fc = 1;
                    *(undefined4 *)(iVar10 + 0x7c) = 0;
                    *(undefined4 *)(iVar10 + 0x18) = 0;
                    lVar15 = 0x18;
                    lVar14 = 0x14;
                    lVar26 = 0x10;
                    lVar8 = 0xc;
                    lVar30 = 8;
                    lVar36 = 4;
                    uVar18 = 0;
                    uVar33 = uVar37;
                  }
                } while( true );
              }
LAB_0000c820:
              uVar9 = uVar5 + 0x10;
              uVar5 = uVar5 + 8;
              uVar38 = uVar34;
              if ((uVar9 & 0xffffffff) < (uVar34 & 0xffffffff)) {
                uVar38 = uVar9;
              }
            } while ((uVar5 & 0xffffffff) < (uVar34 & 0xffffffff));
            uVar21 = in_r7[0x16];
          }
          uStack_100 = uStack_100 + 1;
          puStack_10c = puStack_10c + 2;
        } while (uStack_100 < uVar21);
      }
      *(int *)(iVar10 + 0x80) = (int)uVar18;
      return 0;
    }
  }
  return 0xffffffffe00002be;
}

/* _printf_LDBLStub @ 0xc89c (172 bytes) */
int _printf_LDBLStub(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  ulonglong param_1;
  ulonglong param_2;
  ulonglong param_3;
  ulonglong param_4;
  ulonglong param_5;
  ulonglong param_6;
  ulonglong param_7;
  ulonglong param_8;
{
  if (_funcptr == (code *)0x0) {
    _funcptr = (code *)((int (*)())___stub_getrealaddr)("printf");
    param_1 = param_1 & 0xffffffff;
    param_8 = param_8 & 0xffffffff;
    param_7 = param_7 & 0xffffffff;
    param_6 = param_6 & 0xffffffff;
    param_5 = param_5 & 0xffffffff;
    param_4 = param_4 & 0xffffffff;
    param_3 = param_3 & 0xffffffff;
    param_2 = param_2 & 0xffffffff;
  }
                    
                    
  (*_funcptr)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_0000c954 @ 0xc954 (12 bytes) */
int FUN_0000c954()
{
  return;
}

/* FUN_0000c960 @ 0xc960 (8 bytes) */
int FUN_0000c960()
{
  return;
}

/* FUN_0000c968 @ 0xc968 (12 bytes) */
int FUN_0000c968()
{
  return;
}

/* FUN_0000c974 @ 0xc974 (36 bytes) */
int FUN_0000c974()
{
  return;
}

/* ___stub_getrealaddr @ 0xc9ec (164 bytes) */
int ___stub_getrealaddr(param_1)
  char *param_1;
{
  undefined4 uVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  char local_58 [4];
  char acStack_54 [4];
  char acStack_50 [80];
  
  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  sVar3 = _strlen(local_58);
  cVar2 = s__LDBL128_0000cfbc[8];
  uVar1 = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 4));
  *(undefined4 *)(local_58 + sVar3) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 0));
  acStack_50[sVar3] = cVar2;
  *(undefined4 *)(acStack_54 + sVar3) = uVar1;
  iVar4 = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (iVar4 == 0) {
    local_58[sVar3] = '\0';
  }
  _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  _NSAddressOfSymbol();
  return;
}

