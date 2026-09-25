#include "decls.h"

/* __AllocateSurface @ 0x2750 (1420 bytes) */
int __AllocateSurface(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint *param_3;
  undefined4 param_4;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  void *pvVar11;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  uint local_78;
  int local_74;
  uint local_70;
  int *local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  
  puVar3 = _calloc(1,0x3c);
  if ((param_2 & 1) == 0) {
    if ((param_2 & 8) == 0) {
      iVar4 = __DecodePixelFormat(param_3[1],puVar3 + 0xc,puVar3 + 0xd,puVar3 + 10,&local_70,
                                  puVar3 + 0xb,0,puVar3 + 0xe);
      if (iVar4 == 0) goto LAB_00002cb0;
      uVar1 = param_3[6];
      uVar12 = puVar3[10];
      iVar4 = 1;
      *(undefined2 *)((int)puVar3 + 0xe) = 0;
      *(undefined2 *)(puVar3 + 3) = 0;
      puVar3[7] = uVar1 / uVar12;
      uVar2 = param_3[4];
      *(short *)(puVar3 + 4) = (short)uVar2;
      uVar1 = param_3[5];
      puVar3[5] = uVar2;
      *(short *)((int)puVar3 + 0x12) = (short)uVar1;
      puVar3[6] = uVar1;
      uVar1 = uVar12 * uVar2 * uVar1 + 3;
      local_60 = (uVar1 & 0xfffffffc) + 0xfff & 0xfffff000;
      for (uVar1 = uVar1 >> 2; 0x3fff < uVar1; uVar1 = uVar1 >> 1) {
        iVar4 = iVar4 << 1;
      }
      local_74 = 2;
      local_64 = ((uVar1 + 0xd) * iVar4 + 0x27) * 4 & 0xffffffe0;
      iVar4 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),9,&local_64,2,&local_6c,&local_74);
      if (iVar4 == 0) {
        *puVar3 = local_68;
        uVar5 = param_3[4];
        uVar2 = param_3[5];
        pvVar10 = (void *)*param_3;
        uVar9 = uVar12 * uVar5;
        uVar1 = uVar12 * uVar5 * uVar2 >> 2;
        uVar12 = uVar2;
        if (uVar1 < 0x4000) {
          iVar4 = 1;
        }
        else {
          iVar4 = 1;
          do {
            uVar1 = uVar1 >> 1;
            uVar2 = uVar2 >> 1;
            uVar12 = uVar12 >> 1;
            iVar4 = iVar4 << 1;
          } while (0x3fff < uVar1);
        }
        uVar6 = 0x20;
        if (0x1f < uVar9) {
          uVar6 = uVar9;
        }
        *local_6c = (uVar1 + 0xd) * iVar4 + 8;
        local_6c[6] = uVar1 + 0xd;
        local_6c[7] = iVar4;
        local_6c[5] = uVar6 * uVar2;
        local_6c[0x20] = 0x1393;
        local_6c[0x21] = 10;
        local_6c[0x22] = 0x5c8;
        piVar14 = local_6c + 0x24;
        local_6c[0x23] = 0x20000;
        iVar7 = 3;
        if (local_70 != 3) {
          iVar7 = 0;
        }
        if (iVar4 != 0) {
          iVar8 = 0;
          do {
            *piVar14 = 0x5cb;
            piVar14[1] = iVar7;
            piVar14[2] = 0x51b;
            piVar14[3] = (local_70 & 0xf) << 8 | 0x53cc30f2;
            piVar14[4] = 0x10501;
            piVar14[5] = 0;
            piVar14[6] = uVar6;
            piVar14[7] = 0x5c0;
            piVar14[8] = 0;
            piVar14[9] = 0x1050e;
            piVar14[10] = 0;
            piVar14[0xb] = uVar5 | uVar2 << 0x10;
            piVar14[0xc] = (uVar1 - 1) * 0x10000 | 0x85f0;
            piVar14 = piVar14 + 0xd;
            if (uVar12 != 0) {
              uVar13 = 0;
              pvVar11 = pvVar10;
              do {
                uVar13 = uVar13 + 1;
                pvVar10 = (void *)((int)pvVar11 + uVar9);
                _bcopy(pvVar11,piVar14,uVar9);
                piVar14 = (int *)((int)piVar14 + (uVar9 & 0xfffffffc));
                pvVar11 = pvVar10;
              } while (uVar13 != uVar12);
            }
            iVar8 = iVar8 + 1;
          } while (iVar4 != iVar8);
        }
        *piVar14 = 0xd0b;
        piVar14[1] = 5;
        piVar14[2] = 0x5c8;
        piVar14[3] = 0x10000;
        iVar4 = 0;
        goto LAB_00002ce0;
      }
    }
    else if (((param_3[6] & 0x3f) == 0) &&
            (iVar4 = __DecodePixelFormat(param_3[1],puVar3 + 0xc,puVar3 + 0xd,puVar3 + 10,0,
                                         puVar3 + 0xb,0,puVar3 + 0xe), iVar4 != 0)) {
      uVar2 = param_3[6];
      *(undefined2 *)((int)puVar3 + 0xe) = 0;
      *(undefined2 *)(puVar3 + 3) = 0;
      puVar3[7] = uVar2 / (uint)puVar3[10];
      uVar1 = param_3[4];
      *(short *)(puVar3 + 4) = (short)uVar1;
      local_5c = param_3[5];
      puVar3[5] = uVar1;
      *(short *)((int)puVar3 + 0x12) = (short)local_5c;
      puVar3[6] = local_5c;
      local_74 = 1;
      local_5c = local_5c * uVar2;
      local_60 = *param_3;
      local_64 = param_2;
      iVar4 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(param_1 + 0xc),8,&local_64,3,puVar3,&local_74);
      if (iVar4 == 0) goto LAB_00002ce0;
    }
    else {
LAB_00002cb0:
      iVar4 = -0x1ffffd39;
    }
  }
  else {
    puVar3[2] = param_4;
    param_3[10] = (uint)puVar3;
    iVar4 = __SetDestination(param_1,1,param_3);
    if (iVar4 == 0) {
      if ((param_2 & 2) != 0) {
        local_60 = param_3[4];
        local_5c = param_3[5];
        local_74 = iVar4;
        local_64 = param_2;
        iVar4 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),4,&local_64,3,0,&local_74);
        if (iVar4 != 0) goto LAB_00002cb8;
      }
      if (((param_2 & 0x10) != 0) &&
         (iVar4 = __DecodePixelFormat(param_3[1],puVar3 + 0xc,puVar3 + 0xd,puVar3 + 10,0,
                                      puVar3 + 0xb,&local_78,puVar3 + 0xe), iVar4 != 0)) {
        uVar1 = param_3[4] * puVar3[10] + 0x7f & 0xffffff80;
        local_60 = (param_3[5] + 1) * uVar1;
        param_3[6] = uVar1;
        local_64 = local_78;
        local_74 = 2;
        iVar4 = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(param_1 + 0xc),10,&local_64,2,&local_6c,&local_74);
        if (iVar4 == 0) {
          iVar4 = 0;
          *puVar3 = local_68;
          uVar1 = param_3[6];
          *(undefined2 *)((int)puVar3 + 0xe) = 0;
          *(undefined2 *)(puVar3 + 3) = 0;
          puVar3[7] = uVar1 / (uint)puVar3[10];
          uVar1 = param_3[4];
          *(short *)(puVar3 + 4) = (short)uVar1;
          uVar2 = param_3[5];
          puVar3[5] = uVar1;
          *(short *)((int)puVar3 + 0x12) = (short)uVar2;
          puVar3[6] = uVar2;
          puVar3[1] = local_6c;
          param_3[9] = 2;
          goto LAB_00002ce0;
        }
      }
      iVar4 = 0;
      goto LAB_00002ce0;
    }
  }
LAB_00002cb8:
  _free(puVar3);
  puVar3 = (undefined4 *)0x0;
LAB_00002ce0:
  param_3[10] = (uint)puVar3;
  return iVar4;
}

/* _radeon3DCopySetup @ 0x2d10 (2048 bytes) */
int _radeon3DCopySetup(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(uint *)(param_3 + 0x2c) == 0) {
    if (param_4 == 6) {
      uVar3 = 0xfffffff9;
      uVar5 = 0xc;
    }
    else if (param_4 == 3) {
      uVar3 = 0xfffffff8;
      uVar5 = 0xb;
    }
    else {
      uVar5 = param_4 & 0x1f;
      uVar3 = param_4 - 0x13;
    }
  }
  else {
    uVar5 = *(uint *)(&DAT_0000e018 + (*(uint *)(param_3 + 0x2c) & 0xff) * 0x1c) >> 0x13 & 0x1f;
    uVar3 = uVar5 - 0x13;
  }
  *(undefined4 *)(param_2 + param_6 * 4) = 0x10ea;
  *(undefined4 *)(param_2 + (param_6 + 1) * 4) = 0x2da49525;
  *(undefined4 *)(param_2 + (param_6 + 2) * 4) = 0x10fa;
  *(undefined4 *)(param_2 + (param_6 + 3) * 4) = 0xffffff;
  *(undefined4 *)(param_2 + (param_6 + 4) * 4) = 0x1004;
  *(undefined4 *)(param_2 + (param_6 + 5) * 4) = 0x66666666;
  *(undefined4 *)(param_2 + (param_6 + 6) * 4) = 0x1005;
  *(undefined4 *)(param_2 + (param_6 + 7) * 4) = 0x6666666;
  *(undefined4 *)(param_2 + (param_6 + 8) * 4) = 0x13c1;
  *(undefined4 *)(param_2 + (param_6 + 9) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 10) * 4) = 0x850;
  *(undefined4 *)(param_2 + (param_6 + 0xb) * 4) = 0x100;
  *(undefined4 *)(param_2 + (param_6 + 0xc) * 4) = 0x887;
  *(undefined4 *)(param_2 + (param_6 + 0xd) * 4) = 0x1c000;
  *(undefined4 *)(param_2 + (param_6 + 0xe) * 4) = 0x82c;
  *(undefined4 *)(param_2 + (param_6 + 0xf) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x10) * 4) = 0x10ae;
  *(undefined4 *)(param_2 + (param_6 + 0x11) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x12) * 4) = 0x1002;
  *(undefined4 *)(param_2 + (param_6 + 0x13) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x14) * 4) = 0x824;
  *(undefined4 *)(param_2 + (param_6 + 0x15) * 4) = 1;
  *(undefined4 *)(param_2 + (param_6 + 0x16) * 4) = 0x825;
  *(undefined4 *)(param_2 + (param_6 + 0x17) * 4) = 2;
  *(undefined4 *)(param_2 + (param_6 + 0x18) * 4) = 0x82d;
  *(undefined4 *)(param_2 + (param_6 + 0x19) * 4) = 3;
  *(undefined4 *)(param_2 + (param_6 + 0x1a) * 4) = 0x854;
  *(undefined4 *)(param_2 + (param_6 + 0x1b) * 4) = 0x26010006;
  *(undefined4 *)(param_2 + (param_6 + 0x1c) * 4) = 0x878;
  *(undefined4 *)(param_2 + (param_6 + 0x1d) * 4) = 0xf688f688;
  *(undefined4 *)(param_2 + (param_6 + 0x1e) * 4) = 0x13c0;
  *(undefined4 *)(param_2 + (param_6 + 0x1f) * 4) = 0;
  *(undefined4 *)((param_6 + 0x20) * 4 + param_2) = 0x13c1;
  *(undefined4 *)((param_6 + 0x21) * 4 + param_2) = 0;
  *(undefined4 *)((param_6 + 0x22) * 4 + param_2) = 0x12f5;
  *(undefined4 *)((param_6 + 0x23) * 4 + param_2) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x24) * 4) = 0x12f0;
  *(undefined4 *)(param_2 + (param_6 + 0x25) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x26) * 4) = 0x10a2;
  *(undefined4 *)(param_2 + (param_6 + 0x27) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x28) * 4) = 0x1381;
  *(undefined4 *)(param_2 + (param_6 + 0x29) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x2a) * 4) = 0x109e;
  *(undefined4 *)(param_2 + (param_6 + 0x2b) * 4) = 5;
  *(undefined4 *)(param_2 + (param_6 + 0x2c) * 4) = 0x1041;
  *(undefined4 *)(param_2 + (param_6 + 0x2d) * 4) = 1;
  *(undefined4 *)(param_2 + (param_6 + 0x2e) * 4) = 0x1094;
  *(undefined4 *)(param_2 + (param_6 + 0x2f) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x30) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x31) * 4) = 0x7803;
  *(undefined4 *)(param_2 + (param_6 + 0x32) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x33) * 4) = 0x2400000;
  *(undefined4 *)(param_2 + (param_6 + 0x34) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x35) * 4) = 0xe400e400;
  *(undefined4 *)(param_2 + (param_6 + 0x36) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x37) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x38) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x39) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x3a) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x3b) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x3c) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x3d) * 4) = 0x78105;
  *(undefined4 *)(param_2 + (param_6 + 0x3e) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x3f) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x40) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x41) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x42) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x43) * 4) = 0xdb0220;
  *(undefined4 *)(param_2 + (param_6 + 0x44) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x45) * 4) = 0xc0c000;
  *(undefined4 *)(param_2 + (param_6 + 0x46) * 4) = 0x1095;
  *(undefined4 *)(param_2 + (param_6 + 0x47) * 4) = 0x20490000;
  *(undefined4 *)(param_2 + (param_6 + 0x48) * 4) = 0x1189;
  *(undefined4 *)(param_2 + (param_6 + 0x49) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x4a) * 4) = 0x1181;
  *(undefined4 *)(param_2 + (param_6 + 0x4b) * 4) = 1;
  *(undefined4 *)(param_2 + (param_6 + 0x4c) * 4) = 0x118d;
  *(undefined4 *)(param_2 + (param_6 + 0x4d) * 4) = 0x10000;
  *(undefined4 *)(param_2 + (param_6 + 0x4e) * 4) = 0x118e;
  *(undefined4 *)(param_2 + (param_6 + 0x4f) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x50) * 4) = 0x118c;
  *(undefined4 *)(param_2 + (param_6 + 0x51) * 4) = 0x10000;
  *(undefined4 *)(param_2 + (param_6 + 0x52) * 4) = 0x11a9;
  if (2 < uVar3) {
    *(undefined4 *)(param_2 + (param_6 + 0x53) * 4) = 0x6c01;
  }
  else {
    *(undefined4 *)(param_2 + (param_6 + 0x53) * 4) = 0x1b01;
  }
  *(undefined4 *)(param_2 + (param_6 + 0x54) * 4) = 0x11aa;
  *(undefined4 *)(param_2 + (param_6 + 0x55) * 4) = 0xf;
  *(undefined4 *)(param_2 + (param_6 + 0x56) * 4) = 0x11ab;
  *(undefined4 *)(param_2 + (param_6 + 0x57) * 4) = 0xf;
  *(undefined4 *)(param_2 + (param_6 + 0x58) * 4) = 0x11ac;
  *(undefined4 *)(param_2 + (param_6 + 0x59) * 4) = 0xf;
  *(undefined4 *)(param_2 + (param_6 + 0x5a) * 4) = 0x10c0;
  *(undefined4 *)(param_2 + (param_6 + 0x5b) * 4) = 0x40002;
  *(undefined4 *)(param_2 + (param_6 + 0x5c) * 4) = 0x10c1;
  *(undefined4 *)(param_2 + (param_6 + 0x5d) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 0x5e) * 4) = 0x10c8;
  *(undefined4 *)(param_2 + (param_6 + 0x5f) * 4) = 0x10;
  *(undefined4 *)(param_2 + (param_6 + 0x60) * 4) = 0x101d;
  *(undefined4 *)(param_2 + (param_6 + 0x61) * 4) = 0x280c2040;
  *(undefined4 *)(param_2 + (param_6 + 0x62) * 4) = 0x1040;
  *(undefined4 *)(param_2 + (param_6 + 99) * 4) = 0;
  *(undefined4 *)(param_2 + (param_6 + 100) * 4) = 0x1100;
  uVar4 = 0x1492;
  if (param_5 == 0) {
    uVar4 = 0xa92;
  }
  *(uint *)(param_2 + (param_6 + 0x65) * 4) = uVar4 | 0x2000;
  *(undefined4 *)(param_2 + (param_6 + 0x66) * 4) = 0x1120;
  iVar1 = param_7;
  if (param_7 == 0) {
    iVar1 = (int)*(short *)(param_3 + 4);
  }
  iVar2 = param_8;
  if (param_8 == 0) {
    iVar2 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (param_6 + 0x67) * 4) =
       iVar1 - 1U & 0x7ff | (iVar2 + -1) * 0x800 & 0x3ff800U | 0x80000000;
  *(undefined4 *)(param_2 + (param_6 + 0x68) * 4) = 0x1130;
  if (2 < uVar3) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0x400000;
  }
  *(uint *)(param_2 + (param_6 + 0x69) * 4) = uVar3 | uVar5 | 0x53000;
  *(undefined4 *)(param_2 + (param_6 + 0x6a) * 4) = 0x1140;
  if (param_7 == 0) {
    param_7 = (int)*(short *)(param_3 + 4);
  }
  if (param_8 == 0) {
    param_8 = (int)*(short *)(param_3 + 6);
  }
  *(uint *)(param_2 + (param_6 + 0x6b) * 4) =
       (param_8 + -1) * 0x20 & 0x10000U |
       (param_7 + -1) * 0x10 & 0x8000U | *(int *)(param_3 + 0x10) - 1U & 0x3fff;
  *(undefined4 *)(param_2 + (param_6 + 0x6c) * 4) = 0x10f4;
  *(undefined4 *)(param_2 + (param_6 + 0x6d) * 4) = 0xffff;
  return param_6 + 0x6e;
}

/* _radeon3DFillSetup @ 0x3540 (2020 bytes) */
int _radeon3DFillSetup(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  *(undefined4 *)(param_1 + param_2 * 4) = 0x850;
  *(undefined4 *)(param_1 + (param_2 + 1) * 4) = 0x100;
  *(undefined4 *)(param_1 + (param_2 + 2) * 4) = 0x887;
  *(undefined4 *)(param_1 + (param_2 + 3) * 4) = 0x1c000;
  *(undefined4 *)(param_1 + (param_2 + 4) * 4) = 0x82c;
  *(undefined4 *)(param_1 + (param_2 + 5) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 6) * 4) = 0x1002;
  *(undefined4 *)(param_1 + (param_2 + 7) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 8) * 4) = 0x824;
  *(undefined4 *)(param_1 + (param_2 + 9) * 4) = 1;
  *(undefined4 *)(param_1 + (param_2 + 10) * 4) = 0x825;
  *(undefined4 *)(param_1 + (param_2 + 0xb) * 4) = 4;
  *(undefined4 *)(param_1 + (param_2 + 0xc) * 4) = 0x82d;
  *(undefined4 *)(param_1 + (param_2 + 0xd) * 4) = 3;
  *(undefined4 *)(param_1 + (param_2 + 0xe) * 4) = 0x854;
  *(undefined4 *)(param_1 + (param_2 + 0xf) * 4) = 0x26000001;
  *(undefined4 *)(param_1 + (param_2 + 0x10) * 4) = 0x878;
  *(undefined4 *)(param_1 + (param_2 + 0x11) * 4) = 0xfb24fb08;
  *(undefined4 *)(param_1 + (param_2 + 0x12) * 4) = 0x10a2;
  *(undefined4 *)(param_1 + (param_2 + 0x13) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x14) * 4) = 0x1381;
  *(undefined4 *)(param_1 + (param_2 + 0x15) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x16) * 4) = 0x109e;
  *(undefined4 *)(param_1 + (param_2 + 0x17) * 4) = 5;
  *(undefined4 *)(param_1 + (param_2 + 0x18) * 4) = 0x1383;
  *(undefined4 *)(param_1 + (param_2 + 0x19) * 4) = 0xf;
  *(undefined4 *)(param_1 + (param_2 + 0x1a) * 4) = 0x1004;
  *(undefined4 *)(param_1 + (param_2 + 0x1b) * 4) = 0x66666666;
  *(undefined4 *)(param_1 + (param_2 + 0x1c) * 4) = 0x1005;
  *(undefined4 *)(param_1 + (param_2 + 0x1d) * 4) = 0x66666666;
  *(undefined4 *)(param_1 + (param_2 + 0x1e) * 4) = 0x10ae;
  *(undefined4 *)(param_1 + (param_2 + 0x1f) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x20) * 4) = 0x10ea;
  *(undefined4 *)(param_1 + (param_2 + 0x21) * 4) = 0x2da49525;
  *(undefined4 *)(param_1 + (param_2 + 0x22) * 4) = 0x10fa;
  *(undefined4 *)(param_1 + (param_2 + 0x23) * 4) = 0xffffff;
  *(undefined4 *)(param_1 + (param_2 + 0x24) * 4) = 0x10f4;
  *(undefined4 *)(param_1 + (param_2 + 0x25) * 4) = 0xffff;
  *(undefined4 *)(param_1 + (param_2 + 0x26) * 4) = 0x10f8;
  *(undefined4 *)(param_1 + (param_2 + 0x27) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x28) * 4) = 0x10f9;
  *(uint *)(param_1 + (param_2 + 0x29) * 4) =
       *(uint *)(param_4 + 0x54) & 0x1fff | (*(uint *)(param_4 + 0x58) & 0x1fff) << 0xd;
  *(undefined4 *)(param_1 + (param_2 + 0x2a) * 4) = 0x13c0;
  *(undefined4 *)(param_1 + (param_2 + 0x2b) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x2c) * 4) = 0x13c1;
  *(undefined4 *)(param_1 + (param_2 + 0x2d) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x2e) * 4) = 0x10c0;
  *(undefined4 *)(param_1 + (param_2 + 0x2f) * 4) = 4;
  *(undefined4 *)(param_1 + (param_2 + 0x30) * 4) = 0x10c1;
  *(undefined4 *)(param_1 + (param_2 + 0x31) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x32) * 4) = 0x10c8;
  *(undefined4 *)(param_1 + (param_2 + 0x33) * 4) = 0x10;
  *(undefined4 *)(param_1 + (param_2 + 0x34) * 4) = 0x101d;
  *(undefined4 *)(param_1 + (param_2 + 0x35) * 4) = 0xc2040;
  *(undefined4 *)(param_1 + (param_2 + 0x36) * 4) = 0x1041;
  *(undefined4 *)(param_1 + (param_2 + 0x37) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x38) * 4) = 0x1040;
  *(undefined4 *)(param_1 + (param_2 + 0x39) * 4) = 0;
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
  *(undefined4 *)(param_1 + (param_2 + 0x3a) * 4) = 0x1094;
  *(undefined4 *)(param_1 + (param_2 + 0x3b) * 4) = 0x10000;
  *(undefined4 *)(param_1 + (param_2 + 0x3c) * 4) = 0x1095;
  *(float *)(param_1 + (param_2 + 0x3d) * 4) = fVar3;
  *(undefined4 *)(param_1 + (param_2 + 0x3e) * 4) = 0x1095;
  *(float *)(param_1 + (param_2 + 0x3f) * 4) = fVar2;
  *(undefined4 *)(param_1 + (param_2 + 0x40) * 4) = 0x1095;
  *(float *)(param_1 + (param_2 + 0x41) * 4) = fVar1;
  *(undefined4 *)(param_1 + (param_2 + 0x42) * 4) = 0x1095;
  *(float *)(param_1 + (param_2 + 0x43) * 4) = fVar4;
  *(undefined4 *)(param_1 + (param_2 + 0x44) * 4) = 0x1094;
  *(undefined4 *)(param_1 + (param_2 + 0x45) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x46) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x47) * 4) = 0x78105;
  *(undefined4 *)(param_1 + (param_2 + 0x48) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x49) * 4) = 0x100;
  *(undefined4 *)(param_1 + (param_2 + 0x4a) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x4b) * 4) = 0x100;
  *(undefined4 *)(param_1 + (param_2 + 0x4c) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x4d) * 4) = 0xdb0220;
  *(undefined4 *)(param_1 + (param_2 + 0x4e) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x4f) * 4) = 0xc0c000;
  *(undefined4 *)(param_1 + (param_2 + 0x50) * 4) = 0x1095;
  *(undefined4 *)(param_1 + (param_2 + 0x51) * 4) = 0x20490000;
  *(undefined4 *)(param_1 + (param_2 + 0x52) * 4) = 0x1189;
  *(undefined4 *)(param_1 + (param_2 + 0x53) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x54) * 4) = 0x1181;
  *(undefined4 *)(param_1 + (param_2 + 0x55) * 4) = 1;
  *(undefined4 *)(param_1 + (param_2 + 0x56) * 4) = 0x118d;
  *(undefined4 *)(param_1 + (param_2 + 0x57) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x58) * 4) = 0x118e;
  *(undefined4 *)(param_1 + (param_2 + 0x59) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x5a) * 4) = 0x118c;
  *(undefined4 *)(param_1 + (param_2 + 0x5b) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x5c) * 4) = 0x11a9;
  *(undefined4 *)(param_1 + (param_2 + 0x5d) * 4) = 0x1b01;
  *(undefined4 *)(param_1 + (param_2 + 0x5e) * 4) = 0x11aa;
  *(undefined4 *)(param_1 + (param_2 + 0x5f) * 4) = 0xf;
  *(undefined4 *)(param_1 + (param_2 + 0x60) * 4) = 0x11ab;
  *(undefined4 *)(param_1 + (param_2 + 0x61) * 4) = 0xf;
  *(undefined4 *)(param_1 + (param_2 + 0x62) * 4) = 0x11ac;
  *(undefined4 *)(param_1 + (param_2 + 99) * 4) = 0xf;
  *(undefined4 *)(param_1 + (param_2 + 100) * 4) = 0x12f0;
  *(undefined4 *)(param_1 + (param_2 + 0x65) * 4) = 0;
  *(undefined4 *)(param_1 + (param_2 + 0x66) * 4) = 0x12f5;
  *(undefined4 *)(param_1 + (param_2 + 0x67) * 4) = 0;
  return param_2 + 0x68;
}

/* __Flush @ 0x3d30 (344 bytes) */
int __Flush(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int local_28;
  int local_24 [6];
  
  puVar4 = *(undefined4 **)(param_1 + 0x80);
  if (puVar4 != (undefined4 *)(*(int *)(param_1 + 0x18) + 0x20)) {
    if ((param_2 & 0x10000) == 0) {
      iVar2 = *(int *)(param_1 + 0x8c);
    }
    else {
      iVar2 = 0;
      if (*(int *)(param_1 + 0x8c) != 0) {
        puVar3 = *(uint **)(param_1 + 0x7c);
        *puVar3 = (int)puVar4 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(param_1 + 0x7c) = puVar4;
        *puVar4 = 0x2000000;
        puVar4 = puVar4 + 1;
        iVar2 = *(int *)(param_1 + 0x8c);
      }
    }
    local_24[0] = *(int *)(param_1 + 0x18);
    local_28 = 0;
    if (iVar2 == 0) {
      *puVar4 = 0x5c8;
      local_28 = 2;
      puVar4[1] = 0xc000;
      *(undefined4 *)(param_1 + 0x94) = 0;
    }
    puVar4[local_28] = 0x1000000;
    puVar1 = PTR_0000e694;
    puVar3 = *(uint **)(param_1 + 0x7c);
    *puVar3 = ((int)puVar4 - (int)puVar3 >> 2) + local_28 | *puVar3;
    iVar2 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar1,local_24,
                                &local_28,1);
    if (iVar2 == 0) {
      *(undefined4 *)(local_24[0] + 0x1c) = 0;
      *(int *)(param_1 + 0x18) = local_24[0];
      iVar2 = local_24[0] + 0x20;
      *(int *)(param_1 + 0x7c) = local_24[0] + 0x1c;
    }
    else {
      iVar2 = 0;
      *(undefined4 *)(param_1 + 0x7c) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    *(int *)(param_1 + 0x80) = iVar2;
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
int __FreeSurface(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_3 + 0x28);
  if (iVar1 == 0) {
    uVar3 = 0xe00002d8;
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
int _createTextureBuffer(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
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
    if ((uVar4 == _textureBufferWidth) &&
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
  if (param_4 == 0) {
    DAT_0000e738 = uVar4 << 2;
    DAT_0000e724 = 0x42475241;
    _textureBufferSize = uVar4 * uVar3 * 4;
  }
  else {
    DAT_0000e738 = uVar4 << 1;
    _textureBufferSize = uVar4 * uVar3 * 2;
    DAT_0000e724 = 0x10;
  }
  _textureBufferHeight = uVar3;
  _textureBufferWidth = uVar4;
  DAT_0000e730 = uVar4;
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
int _createOffscreenBuffer(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  
  if (_offscreenBufferBytes == (void *)0x0) goto LAB_000043f0;
  if (param_3 == 0) {
    if (DAT_0000e6c0 == 0x42475241) goto LAB_0000430c;
  }
  else if (DAT_0000e6c0 == 0x10) {
LAB_0000430c:
    if ((((int)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0) == _offscreenBufferWidth) &&
       (((int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0) == _offscreenBufferHeight)) {
      iVar1 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 0xc),0xc,*DAT_0000e6e4,1,0,0);
      if (iVar1 == 0) {
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
  _offscreenBufferWidth = (int)*(short *)(param_2 + 4) + 0x20U & 0xffffffe0;
  _offscreenBufferHeight = (int)*(short *)(param_2 + 6) + 0x20U & 0xffffffe0;
  if (param_3 == 0) {
    DAT_0000e6d4 = _offscreenBufferWidth << 2;
    DAT_0000e6c0 = 0x42475241;
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 4;
  }
  else {
    DAT_0000e6d4 = _offscreenBufferWidth << 1;
    _offscreenBufferSize = _offscreenBufferWidth * _offscreenBufferHeight * 2;
    DAT_0000e6c0 = 0x10;
  }
  DAT_0000e6cc = _offscreenBufferWidth;
  DAT_0000e6d0 = _offscreenBufferHeight;
  _offscreenBufferBytes = _malloc(_offscreenBufferSize);
  uVar2 = 0;
  if (_offscreenBufferBytes != (void *)0x0) {
    _offscreenBuffer = _offscreenBufferBytes;
    iVar1 = ((int (*)())__AllocateSurface)(param_1,0,&_offscreenBuffer,0);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_offscreenBufferBytes);
      uVar2 = 0;
      _offscreenBufferBytes = (void *)0x0;
    }
  }
  return uVar2;
}

/* __Stop @ 0x4500 (248 bytes) */
int __Stop(param_1)
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
int _radeonCopy(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  short sVar1;
  uint uVar2;
  bool bVar3;
  double dVar4;
  double dVar5;
  undefined *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  dword *pdVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  dword *pdVar14;
  int iVar15;
  int iVar16;
  float fVar17;
  dword *pdVar18;
  int iVar19;
  int iVar20;
  dword *pdVar21;
  int iVar22;
  float fVar23;
  dword *pdVar24;
  float fVar25;
  dword *pdVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  int iVar41;
  uint uVar42;
  uint uVar43;
  dword *pdVar44;
  int iVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
  double dVar52;
  double dVar53;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c [2];
  uint uStack_194;
  undefined4 local_190;
  uint uStack_18c;
  undefined4 local_188;
  uint uStack_184;
  undefined4 local_180;
  uint uStack_17c;
  longlong local_178;
  longlong local_170;
  longlong local_168;
  longlong local_160;
  longlong local_158;
  longlong local_150;
  longlong local_148;
  longlong local_140;
  undefined4 local_138;
  uint uStack_134;
  undefined4 local_128;
  uint uStack_124;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  undefined4 local_108;
  uint uStack_104;
  undefined4 local_100;
  uint uStack_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  int local_d0;
  undefined4 *local_cc;
  undefined4 local_c8;
  uint local_c4;
  float *local_c0;
  float *local_bc;
  short local_b8;
  short local_b6;
  float *local_b4;
  float *local_b0;
  int *local_ac;
  
  pdVar44 = *(dword **)(param_1 + 0x80);
  iVar41 = *(int *)(param_5 + 0x58);
  uVar43 = *(int *)(*(int *)(param_1 + 0x18) + 0x10) - 7;
  if (pdVar44 != (dword *)0x0) {
    uVar42 = uVar43 - ((int)pdVar44 - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
    if ((0x1000 < *(short *)(param_1 + 0x50)) || (0x1000 < *(short *)(param_1 + 0x52))) {
      return 0xe00002c7;
    }
    iVar8 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,0);
    dVar5 = DOUBLE_0000cfe8;
    dVar4 = DOUBLE_0000cfe0;
    if (iVar8 != 0) {
      local_d4 = *(uint *)(param_1 + 0x70);
      local_cc = DAT_0000e6e4 + 3;
      if (local_d4 == 3) {
        local_d4 = 0xb;
      }
      else if (local_d4 == 6) {
        local_d4 = 0xc;
      }
      local_d8 = DAT_0000e6e4[0xc];
      if (local_d8 == 3) {
        local_d8 = 0xb;
      }
      else if (local_d8 == 6) {
        local_d8 = 0xc;
      }
      if (iVar41 != 0) {
        local_c0 = &local_1a0;
        local_bc = local_19c;
        local_b4 = &local_1a8;
        local_d0 = 0;
        local_b0 = &local_1a4;
        local_c8 = 0xc000;
        local_c4 = local_d4 & 0x1f | 0x53000;
        bVar3 = true;
        local_ac = (int *)(param_5 + 0x5c);
        do {
          local_19c[1] = 176.0;
          uStack_194 = *local_ac + *(int *)(param_1 + 0x60) ^ 0x80000000;
          local_190 = 0x43300000;
          local_188 = 0x43300000;
          local_180 = 0x43300000;
          uStack_18c = local_ac[1] + *(int *)(param_1 + 100) ^ 0x80000000;
          uStack_184 = local_ac[4] ^ 0x80000000;
          uStack_17c = local_ac[5] ^ 0x80000000;
          dVar46 = (double)CONCAT44(0x43300000,uStack_194) - dVar4;
          dVar50 = (double)(float)dVar46;
          dVar48 = (double)CONCAT44(0x43300000,uStack_18c) - dVar4;
          dVar51 = (double)(float)dVar48;
          dVar47 = dVar51 + (double)(float)((double)CONCAT44(0x43300000,uStack_17c) - dVar4);
          dVar53 = (double)(float)dVar47;
          dVar49 = dVar50 + (double)(float)((double)CONCAT44(0x43300000,uStack_184) - dVar4);
          dVar52 = (double)(float)dVar49;
          if (DOUBLE_0000cff0 <= dVar50) {
            local_170 = (longlong)(int)(dVar50 - DOUBLE_0000cff0);
            local_dc = (int)(dVar50 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_dc = (uint)dVar46;
            local_178 = (longlong)(int)local_dc;
          }
          if (DOUBLE_0000cff0 <= dVar51) {
            local_160 = (longlong)(int)(dVar51 - DOUBLE_0000cff0);
            local_e0 = (int)(dVar51 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_e0 = (uint)dVar48;
            local_168 = (longlong)(int)local_e0;
          }
          if (DOUBLE_0000cff0 <= dVar52) {
            local_150 = (longlong)(int)(dVar52 - DOUBLE_0000cff0);
            local_e4 = (int)(dVar52 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_e4 = (uint)dVar49;
            local_158 = (longlong)(int)local_e4;
          }
          if (DOUBLE_0000cff0 <= dVar53) {
            local_140 = (longlong)(int)(dVar53 - DOUBLE_0000cff0);
            local_e8 = (int)(dVar53 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_e8 = (uint)dVar47;
            local_148 = (longlong)(int)local_e8;
          }
          if (bVar3) {
            if (uVar42 < 0x8a) {
              local_1a8 = *(float *)(param_1 + 0x18);
              local_19c[0] = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar44 = 0x5c8;
                local_19c[0] = 2.8026e-45;
                pdVar44[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar44[(int)local_19c[0]] = 0x1000000;
              puVar7 = *(uint **)(param_1 + 0x7c);
              *puVar7 = ((int)pdVar44 - (int)puVar7 >> 2) + (int)local_19c[0] | *puVar7;
              iVar8 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                          *(undefined4 *)PTR_0000e694,local_b4,local_bc,1);
              if (iVar8 == 0) {
                bVar3 = true;
                *(undefined4 *)((int)local_1a8 + 0x1c) = 0;
                pdVar44 = (dword *)((int)local_1a8 + 0x20);
                *(float *)(param_1 + 0x18) = local_1a8;
                pdVar10 = (dword *)((int)local_1a8 + 0x38);
                pdVar14 = (dword *)((int)local_1a8 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_1a8 + 0x1c;
                pdVar26 = (dword *)((int)local_1a8 + 0x28);
                pdVar18 = (dword *)((int)local_1a8 + 0x2c);
                pdVar21 = (dword *)((int)local_1a8 + 0x30);
                pdVar24 = (dword *)((int)local_1a8 + 0x34);
                uVar42 = uVar43;
              }
              else {
LAB_00004b14:
                bVar3 = true;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar44 = (dword *)0x0;
                pdVar14 = &__mh_bundle_header.cputype;
                pdVar26 = &__mh_bundle_header.cpusubtype;
                pdVar18 = &__mh_bundle_header.filetype;
                pdVar21 = &__mh_bundle_header.ncmds;
                pdVar24 = &__mh_bundle_header.sizeofcmds;
                pdVar10 = &__mh_bundle_header.flags;
                uVar42 = uVar43;
              }
            }
            else {
              pdVar14 = pdVar44 + 1;
              pdVar26 = pdVar44 + 2;
              pdVar18 = pdVar44 + 3;
              pdVar21 = pdVar44 + 4;
              pdVar24 = pdVar44 + 5;
              pdVar10 = pdVar44 + 6;
              bVar3 = true;
            }
          }
          else if (uVar42 < 0x22) {
            local_19c[0] = *(float *)(param_1 + 0x18);
            local_1a8 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar44 = 0x5c8;
              local_1a8 = 2.8026e-45;
              pdVar44[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar44[(int)local_1a8] = 0x1000000;
            puVar7 = *(uint **)(param_1 + 0x7c);
            *puVar7 = ((int)pdVar44 - (int)puVar7 >> 2) + (int)local_1a8 | *puVar7;
            iVar8 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694
                                        ,local_bc,&local_1a8,1);
            if (iVar8 != 0) goto LAB_00004b14;
            bVar3 = true;
            *(undefined4 *)((int)local_19c[0] + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_19c[0];
            pdVar44 = (dword *)((int)local_19c[0] + 0x20);
            pdVar10 = (dword *)((int)local_19c[0] + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_19c[0] + 0x1c;
            pdVar14 = (dword *)((int)local_19c[0] + 0x24);
            pdVar26 = (dword *)((int)local_19c[0] + 0x28);
            pdVar18 = (dword *)((int)local_19c[0] + 0x2c);
            pdVar21 = (dword *)((int)local_19c[0] + 0x30);
            pdVar24 = (dword *)((int)local_19c[0] + 0x34);
            uVar42 = uVar43;
          }
          else {
            pdVar14 = pdVar44 + 1;
            pdVar26 = pdVar44 + 2;
            pdVar18 = pdVar44 + 3;
            pdVar21 = pdVar44 + 4;
            pdVar24 = pdVar44 + 5;
            pdVar10 = pdVar44 + 6;
            bVar3 = false;
          }
          puVar7 = *(uint **)(param_1 + 0x7c);
          *puVar7 = (int)pdVar44 - (int)puVar7 >> 2 | *puVar7;
          *(dword **)(param_1 + 0x7c) = pdVar44;
          *pdVar44 = 0xe000000;
          *pdVar14 = 0;
          puVar7 = *(uint **)(param_1 + 0x7c);
          *puVar7 = (int)pdVar26 - (int)puVar7 >> 2 | *puVar7;
          *(dword **)(param_1 + 0x7c) = pdVar26;
          *pdVar26 = 0x10000000;
          *pdVar18 = *(dword *)*DAT_0000e6e4;
          *pdVar21 = DAT_0000e6e4[7];
          *pdVar24 = 6;
          if (bVar3) {
            iVar9 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar10,param_1 + 0x4c,local_d4,0,0,0,0);
            local_b8 = *(short *)(param_1 + 0x50);
            iVar15 = iVar9 + 1;
            iVar19 = iVar9 + 2;
            iVar12 = iVar9 + 0x16;
            iVar8 = iVar9 << 2;
            iVar45 = iVar9 + 3;
            iVar27 = iVar9 + 4;
            iVar13 = iVar9 + 5;
            iVar16 = iVar9 + 6;
            iVar22 = iVar9 + 7;
            iVar20 = iVar9 + 8;
            iVar28 = iVar9 + 9;
            iVar29 = iVar9 + 10;
            iVar30 = iVar9 + 0xb;
            iVar31 = iVar9 + 0xc;
            iVar32 = iVar9 + 0xd;
            iVar33 = iVar9 + 0xe;
            iVar34 = iVar9 + 0xf;
            iVar35 = iVar9 + 0x10;
            iVar36 = iVar9 + 0x11;
            iVar37 = iVar9 + 0x12;
            iVar39 = iVar9 + 0x13;
            iVar11 = iVar9 + 0x14;
            iVar9 = iVar9 + 0x15;
            local_b6 = *(short *)(param_1 + 0x52);
          }
          else {
            *pdVar10 = 0x1120;
            local_b8 = *(short *)(param_1 + 0x50);
            local_b6 = *(short *)(param_1 + 0x52);
            pdVar10[1] = (int)local_b8 - 1U & 0x7ff | (local_b6 + -1) * 0x800 & 0x3ff800U |
                         0x80000000;
            pdVar10[2] = 0x1130;
            pdVar10[3] = local_c4;
            pdVar10[4] = 0x1140;
            pdVar10[5] = *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
                         ((int)local_b8 - 1U) * 0x10 & 0x8000 | (local_b6 + -1) * 0x20 & 0x10000U;
            iVar8 = 0x18;
            iVar45 = 9;
            iVar15 = 7;
            iVar27 = 10;
            iVar13 = 0xb;
            iVar19 = 8;
            iVar16 = 0xc;
            iVar22 = 0xd;
            iVar20 = 0xe;
            iVar28 = 0xf;
            iVar29 = 0x10;
            iVar30 = 0x11;
            iVar31 = 0x12;
            iVar32 = 0x13;
            iVar33 = 0x14;
            iVar34 = 0x15;
            iVar35 = 0x16;
            iVar36 = 0x17;
            iVar37 = 0x18;
            iVar39 = 0x19;
            iVar11 = 0x1a;
            iVar9 = 0x1b;
            iVar12 = 0x1c;
          }
          *(undefined4 *)((int)pdVar10 + iVar8) = 0x10f8;
          pdVar10[iVar15] = local_dc & 0x1fff | (local_e0 & 0x1fff) << 0xd;
          pdVar10[iVar19] = 0x10f9;
          pdVar10[iVar45] = local_e4 & 0x1fff | (local_e8 & 0x1fff) << 0xd;
          pdVar10[iVar27] = 0xc00c3500;
          pdVar10[iVar13] = 0x4003d;
          uStack_134 = (int)local_b8 ^ 0x80000000;
          uStack_124 = (int)local_b6 ^ 0x80000000;
          local_138 = 0x43300000;
          local_128 = 0x43300000;
          dVar49 = dVar5 / ((double)CONCAT44(0x43300000,uStack_134) - dVar4);
          dVar47 = dVar5 / ((double)CONCAT44(0x43300000,uStack_124) - dVar4);
          local_1a4 = (float)(dVar52 * dVar49);
          local_19c[0] = (float)(dVar53 * dVar47);
          local_1a0 = (float)(dVar50 * dVar49);
          local_1a8 = (float)(dVar51 * dVar47);
          pdVar10[iVar16] = local_dc | local_e8 << 0x10;
          fVar23 = *local_c0;
          pdVar10[iVar22] = (dword)fVar23;
          fVar17 = *local_bc;
          pdVar10[iVar20] = (dword)fVar17;
          pdVar10[iVar28] = local_dc | local_e0 << 0x10;
          pdVar10[iVar29] = (dword)fVar23;
          fVar23 = *local_b4;
          pdVar10[iVar30] = (dword)fVar23;
          pdVar10[iVar31] = local_e4 | local_e0 << 0x10;
          fVar25 = *local_b0;
          pdVar10[iVar32] = (dword)fVar25;
          pdVar10[iVar33] = (dword)fVar23;
          pdVar10[iVar34] = local_e4 | local_e8 << 0x10;
          pdVar10[iVar35] = (dword)fVar25;
          pdVar10[iVar36] = (dword)fVar17;
          pdVar10[iVar37] = 0x1393;
          pdVar10[iVar39] = 10;
          pdVar10[iVar11] = 0x5c8;
          pdVar10[iVar9] = 0x20000;
          uVar42 = (uVar42 - 6) - iVar12;
          iVar8 = local_ac[5];
          uVar40 = local_ac[2] + *(int *)(param_1 + 0x60);
          iVar9 = local_ac[3] + *(int *)(param_1 + 100);
          uVar38 = uVar40 + local_ac[4];
          pdVar10 = pdVar10 + iVar12;
          if (uVar42 < 0x22) {
            local_1a4 = *(float *)(param_1 + 0x18);
            local_1a0 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar10 = 0x5c8;
              local_1a0 = 2.8026e-45;
              pdVar10[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar10[(int)local_1a0] = 0x1000000;
            puVar6 = PTR_0000e694;
            puVar7 = *(uint **)(param_1 + 0x7c);
            *puVar7 = ((int)pdVar10 - (int)puVar7 >> 2) + (int)local_1a0 | *puVar7;
            iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar6,
                                         local_b0,local_c0,1);
            uVar42 = uVar43;
            if (iVar11 == 0) {
              bVar3 = true;
              *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_1a4;
              pdVar10 = (dword *)((int)local_1a4 + 0x20);
              pdVar44 = (dword *)((int)local_1a4 + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
              pdVar14 = (dword *)((int)local_1a4 + 0x24);
              pdVar18 = (dword *)((int)local_1a4 + 0x28);
              pdVar21 = (dword *)((int)local_1a4 + 0x2c);
              pdVar26 = (dword *)((int)local_1a4 + 0x30);
              pdVar24 = (dword *)((int)local_1a4 + 0x34);
            }
            else {
              bVar3 = true;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar10 = (dword *)0x0;
              pdVar14 = &__mh_bundle_header.cputype;
              pdVar18 = &__mh_bundle_header.cpusubtype;
              pdVar21 = &__mh_bundle_header.filetype;
              pdVar26 = &__mh_bundle_header.ncmds;
              pdVar24 = &__mh_bundle_header.sizeofcmds;
              pdVar44 = &__mh_bundle_header.flags;
            }
          }
          else {
            pdVar14 = pdVar10 + 1;
            pdVar18 = pdVar10 + 2;
            pdVar21 = pdVar10 + 3;
            pdVar26 = pdVar10 + 4;
            pdVar24 = pdVar10 + 5;
            pdVar44 = pdVar10 + 6;
            bVar3 = false;
          }
          puVar7 = *(uint **)(param_1 + 0x7c);
          *puVar7 = (int)pdVar10 - (int)puVar7 >> 2 | *puVar7;
          *(dword **)(param_1 + 0x7c) = pdVar10;
          *pdVar10 = 0x12000000;
          *pdVar14 = 0;
          *pdVar18 = 0;
          *pdVar21 = 0;
          puVar7 = *(uint **)(param_1 + 0x7c);
          *puVar7 = (int)pdVar26 - (int)puVar7 >> 2 | *puVar7;
          *(dword **)(param_1 + 0x7c) = pdVar26;
          *pdVar26 = 0x4000000;
          *pdVar24 = *(dword *)*DAT_0000e6e4;
          if (bVar3) {
            iVar13 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar44,local_cc,local_d8,0,0,0,0);
            local_ec = iVar13 + 1;
            iVar28 = iVar13 + 9;
            local_f4 = iVar13 + 3;
            local_f8 = iVar13 + 4;
            iVar12 = iVar13 + 10;
            local_f0 = iVar13 + 2;
            iVar16 = iVar13 + 0x16;
            iVar11 = iVar13 << 2;
            iVar19 = iVar13 + 5;
            iVar27 = iVar13 + 6;
            iVar20 = iVar13 + 7;
            iVar22 = iVar13 + 8;
            iVar30 = iVar13 + 0xb;
            iVar31 = iVar13 + 0xc;
            iVar32 = iVar13 + 0xd;
            iVar33 = iVar13 + 0xe;
            iVar34 = iVar13 + 0xf;
            iVar35 = iVar13 + 0x10;
            iVar36 = iVar13 + 0x11;
            iVar37 = iVar13 + 0x12;
            iVar29 = iVar13 + 0x13;
            iVar15 = iVar13 + 0x14;
            iVar13 = iVar13 + 0x15;
          }
          else {
            *pdVar44 = 0x1120;
            sVar1 = *(short *)(local_cc + 1);
            iVar11 = *(short *)((int)local_cc + 6) + -1;
            pdVar44[1] = (int)sVar1 - 1U & 0x7ff | iVar11 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar44[2] = 0x1130;
            pdVar44[3] = local_d8 & 0x1f | 0x53000;
            pdVar44[4] = 0x1140;
            pdVar44[5] = local_cc[4] - 1 & 0x3fff | ((int)sVar1 - 1U) * 0x10 & 0x8000 |
                         iVar11 * 0x20 & 0x10000U;
            local_f8 = 10;
            local_f0 = 8;
            iVar11 = 0x18;
            local_f4 = 9;
            local_ec = 7;
            iVar28 = 0xf;
            iVar19 = 0xb;
            iVar27 = 0xc;
            iVar20 = 0xd;
            iVar12 = 0x10;
            iVar22 = 0xe;
            iVar30 = 0x11;
            iVar31 = 0x12;
            iVar32 = 0x13;
            iVar33 = 0x14;
            iVar34 = 0x15;
            iVar35 = 0x16;
            iVar36 = 0x17;
            iVar37 = 0x18;
            iVar29 = 0x19;
            iVar15 = 0x1a;
            iVar13 = 0x1b;
            iVar16 = 0x1c;
          }
          *(undefined4 *)((int)pdVar44 + iVar11) = 0x10f8;
          pdVar44[local_ec] = uVar40 & 0x1fff | iVar9 * 0x2000 & 0x3ffe000U;
          pdVar44[local_f0] = 0x10f9;
          pdVar44[local_f4] = uVar38 & 0x1fff | (iVar9 + iVar8) * 0x2000 & 0x3ffe000U;
          pdVar44[local_f8] = 0xc00c3500;
          pdVar44[iVar19] = 0x4003d;
          uVar2 = (iVar9 + iVar8) * 0x10000;
          local_118 = 0x43300000;
          uStack_114 = (int)*(short *)(local_cc + 1) ^ 0x80000000;
          local_1a8 = (float)(dVar50 * (dVar5 / ((double)CONCAT44(0x43300000,uStack_114) - dVar4)));
          local_110 = 0x43300000;
          uStack_10c = (int)*(short *)(local_cc + 1) ^ 0x80000000;
          local_19c[0] = (float)(dVar52 * (dVar5 / ((double)CONCAT44(0x43300000,uStack_10c) - dVar4)
                                          ));
          local_108 = 0x43300000;
          uStack_104 = (int)*(short *)((int)local_cc + 6) ^ 0x80000000;
          local_1a0 = (float)(dVar51 * (dVar5 / ((double)CONCAT44(0x43300000,uStack_104) - dVar4)));
          local_100 = 0x43300000;
          uStack_fc = (int)*(short *)((int)local_cc + 6) ^ 0x80000000;
          local_1a4 = (float)(dVar53 * (dVar5 / ((double)CONCAT44(0x43300000,uStack_fc) - dVar4)));
          pdVar44[iVar27] = uVar40 | uVar2;
          fVar23 = *local_b4;
          pdVar44[iVar20] = (dword)fVar23;
          fVar17 = *local_b0;
          pdVar44[iVar22] = (dword)fVar17;
          pdVar44[iVar28] = uVar40 | iVar9 * 0x10000;
          pdVar44[iVar12] = (dword)fVar23;
          fVar23 = *local_c0;
          pdVar44[iVar30] = (dword)fVar23;
          pdVar44[iVar31] = uVar38 | iVar9 * 0x10000;
          fVar25 = *local_bc;
          pdVar44[iVar32] = (dword)fVar25;
          pdVar44[iVar33] = (dword)fVar23;
          pdVar44[iVar34] = uVar38 | uVar2;
          pdVar44[iVar35] = (dword)fVar25;
          pdVar44[iVar36] = (dword)fVar17;
          pdVar44[iVar37] = 0x1393;
          pdVar44[iVar29] = 10;
          pdVar44[iVar15] = 0x5c8;
          pdVar44[iVar13] = 0x20000;
          uVar42 = (uVar42 - 6) - iVar16;
          pdVar44 = pdVar44 + iVar16;
          local_d0 = local_d0 + 1;
          local_ac = local_ac + 6;
          bVar3 = false;
        } while (iVar41 != local_d0);
      }
      *(dword **)(param_1 + 0x80) = pdVar44;
      return 0;
    }
  }
  return 0xe00002be;
}

/* FUN_000055a4 @ 0x55a4 (11396 bytes) */
int FUN_000055a4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,dword param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  short sVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  bool bVar9;
  undefined *puVar10;
  int iVar11;
  undefined4 *puVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float fVar17;
  int iVar18;
  float fVar19;
  dword *pdVar20;
  int iVar21;
  dword *pdVar22;
  int iVar23;
  dword dVar24;
  int iVar25;
  float fVar26;
  dword *pdVar27;
  float fVar28;
  dword *pdVar29;
  dword dVar30;
  float fVar31;
  float fVar32;
  dword *pdVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  uint uVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  int iVar44;
  uint uVar45;
  int iVar46;
  int iVar47;
  uint uVar48;
  int iVar49;
  int iVar50;
  uint uVar51;
  dword *pdVar52;
  dword *pdVar53;
  int *piVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  int iVar58;
  double dVar59;
  double dVar60;
  double dVar61;
  double dVar62;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  double dVar63;
  double dVar64;
  double dVar65;
  double dVar66;
  undefined4 local_368;
  float local_364;
  float local_360;
  float local_35c;
  float local_358;
  dword local_354 [3];
  short local_348;
  undefined4 local_318;
  uint uStack_314;
  undefined4 local_310;
  uint uStack_30c;
  undefined4 local_308;
  dword dStack_304;
  undefined4 local_300;
  dword dStack_2fc;
  undefined4 local_2f8;
  uint uStack_2f4;
  undefined4 local_2f0;
  uint uStack_2ec;
  undefined4 local_2e8;
  uint uStack_2e4;
  undefined4 local_2e0;
  uint uStack_2dc;
  longlong local_2d8;
  longlong local_2d0;
  longlong local_2c8;
  longlong local_2c0;
  longlong local_2b8;
  longlong local_2b0;
  longlong local_2a8;
  longlong local_2a0;
  undefined4 local_298;
  uint uStack_294;
  undefined4 local_290;
  uint uStack_28c;
  undefined4 local_288;
  uint uStack_284;
  undefined4 local_280;
  uint uStack_27c;
  undefined4 local_278;
  uint uStack_274;
  undefined4 local_270;
  uint uStack_26c;
  undefined4 local_268;
  uint uStack_264;
  undefined4 local_260;
  uint uStack_25c;
  undefined4 local_258;
  uint uStack_254;
  undefined4 local_250;
  uint uStack_24c;
  undefined4 local_248;
  uint uStack_244;
  undefined4 local_240;
  uint uStack_23c;
  undefined4 local_238;
  int iStack_234;
  undefined4 local_230;
  uint uStack_22c;
  undefined4 local_228;
  uint uStack_224;
  undefined4 local_220;
  int iStack_21c;
  undefined4 local_218;
  uint uStack_214;
  undefined4 local_210;
  uint uStack_20c;
  undefined4 local_208;
  uint uStack_204;
  undefined4 local_200;
  uint uStack_1fc;
  undefined4 local_1f8;
  uint uStack_1f4;
  undefined4 local_1f0;
  uint uStack_1ec;
  undefined4 local_1e8;
  uint uStack_1e4;
  undefined4 local_1e0;
  uint uStack_1dc;
  undefined4 local_1d8;
  uint uStack_1d4;
  longlong local_1d0;
  longlong local_1c8;
  undefined4 local_1c0;
  uint uStack_1bc;
  undefined4 local_1b8;
  uint uStack_1b4;
  undefined4 local_1b0;
  uint uStack_1ac;
  undefined4 local_1a8;
  uint uStack_1a4;
  undefined4 local_1a0;
  uint uStack_19c;
  undefined4 local_198;
  uint uStack_194;
  undefined4 local_190;
  uint uStack_18c;
  longlong local_188;
  longlong local_180;
  int local_178;
  int local_174;
  int local_170;
  uint local_16c;
  int *local_168;
  short *local_164;
  short *local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  dword local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  dword local_114;
  uint local_110;
  uint local_10c;
  uint local_108;
  uint local_104;
  dword local_100;
  dword local_fc;
  uint local_f8;
  dword local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  undefined4 *local_dc;
  dword *local_d8;
  int *local_d4;
  uint local_d0;
  uint local_cc;
  dword local_c8;
  dword local_c4;
  dword local_c0;
  undefined4 local_bc;
  float *local_b8;
  float *local_b4;
  float *local_b0;
  float *local_ac;
  int *local_a8;
  
  uVar55 = param_4 & 0x7ffff000;
  pdVar53 = *(dword **)(param_1 + 0x80);
  iVar56 = *(int *)(param_1 + 0x18);
  piVar54 = *(int **)(param_5 + 0x60);
  iVar11 = *(int *)(iVar56 + 0x10);
  iVar38 = *piVar54;
  uVar39 = iVar11 - 7;
  if (pdVar53 == (dword *)0x0) {
LAB_000081e0:
    iVar11 = -0x1ffffd42;
  }
  else {
    bVar1 = uVar55 == 0x1000;
    if (bVar1) {
      local_fc = *(dword *)(param_1 + 0x84);
      local_d8 = (dword *)(param_1 + 0x1c);
      local_ec = *(int *)(param_1 + 0x30);
      iVar23 = 0x9000000;
      local_f0 = *(int *)(param_1 + 0x34);
LAB_000056ac:
      local_348 = *(short *)(local_d8 + 1);
      if ((0x1000 < local_348) || (0x1000 < *(short *)((int)local_d8 + 6))) {
        return -0x1ffffd39;
      }
      local_140 = iVar23 + 0x1000000;
    }
    else {
      if (uVar55 < 0x1001) {
        if (uVar55 != 0) {
          return -0x1ffffd44;
        }
        local_d8 = (dword *)(param_1 + 0x4c);
        local_ec = 0;
        local_f0 = 0;
        local_fc = 0;
        iVar23 = 0xd000000;
        goto LAB_000056ac;
      }
      if (uVar55 == 0x3000) {
        puVar12 = *(undefined4 **)(param_6 + 0x28);
        local_ec = 0;
        local_f0 = 0;
        local_d8 = puVar12 + 3;
        local_140 = 0x8000000;
        local_fc = *(dword *)*puVar12;
        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
        local_348 = *(short *)(puVar12 + 4);
      }
      else {
        if (uVar55 != 0x7000) {
          return -0x1ffffd44;
        }
        local_354[1] = 0x800;
        local_368 = 0x30;
        local_354[0] = param_6;
        local_fc = param_6;
        iVar23 = _io_connect_method_scalarI_structureO
                           (*(undefined4 *)(param_1 + 0xc),2,local_354,2,local_354 + 2,&local_368);
        if (iVar23 != 0) {
          return iVar23;
        }
        local_ec = 0;
        local_f0 = 0;
        local_140 = 0xc000000;
        fparam_1 = extraout_f1;
        local_d8 = local_354 + 2;
      }
    }
    puVar10 = PTR_0000e694;
    local_d4 = piVar54 + 3;
    if (iVar38 == 0) {
      local_d4 = piVar54 + 1;
      iVar38 = 1;
    }
    local_e8 = *(int *)(param_5 + 0x5c) - (int)*(short *)((int)piVar54 + 6);
    dStack_304 = local_d8[2];
    dVar30 = local_d8[4];
    local_e4 = *(int *)(param_5 + 0x58) - (int)*(short *)(piVar54 + 1);
    dVar24 = local_d8[7];
    local_f4 = local_d8[9];
    dStack_2fc = local_d8[3];
    if ((dStack_304 != (int)local_348) ||
       (local_144 = 0, dStack_2fc != (int)*(short *)((int)local_d8 + 6))) {
      local_144 = 1;
    }
    if (local_f4 == 3) {
      local_f4 = 0xb;
    }
    else if (local_f4 == 6) {
      local_f4 = 0xc;
    }
    uStack_314 = (int)local_348 ^ 0x80000000;
    local_318 = 0x43300000;
    local_300 = 0x43300000;
    local_310 = 0x43300000;
    local_308 = 0x43300000;
    uStack_30c = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
    fVar19 = (float)((double)CONCAT44(0x43300000,uStack_314) - DOUBLE_0000cfe0) /
             (float)((double)CONCAT44(0x43300000,dStack_304) - DOUBLE_0000cfd8);
    fVar26 = (float)((double)CONCAT44(0x43300000,uStack_30c) - DOUBLE_0000cfe0) /
             (float)((double)CONCAT44(0x43300000,dStack_2fc) - DOUBLE_0000cfd8);
    uVar48 = uVar39 - ((int)pdVar53 - (iVar56 + 0x20) >> 2);
    while (((uint)pdVar53 & 0x1f) != 0) {
      if (uVar48 == 0) {
        local_364 = *(float *)(param_1 + 0x18);
        local_360 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *pdVar53 = 0x5c8;
          local_360 = 2.8026e-45;
          pdVar53[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        pdVar53[(int)local_360] = 0x1000000;
        puVar13 = *(uint **)(param_1 + 0x7c);
        *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_360 | *puVar13;
        iVar56 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                     *(undefined4 *)puVar10,&local_364,&local_360,1);
        fparam_1 = extraout_f1_00;
        if (iVar56 == 0) {
          *(undefined4 *)((int)local_364 + 0x1c) = 0;
          *(float *)(param_1 + 0x18) = local_364;
          pdVar53 = (dword *)((int)local_364 + 0x20);
          *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
          uVar48 = uVar39;
        }
        else {
          pdVar53 = (dword *)0x0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          *(undefined4 *)(param_1 + 0x18) = 0;
          uVar48 = uVar39;
        }
      }
      else {
        *pdVar53 = 0x80000000;
        pdVar53 = pdVar53 + 1;
        uVar48 = uVar48 - 1;
      }
    }
    if ((local_144 == 0) && (local_f4 == *(dword *)(param_1 + 0x70))) {
      local_e4 = local_e4 + *(int *)(param_1 + 0x60);
      local_e8 = local_e8 + *(int *)(param_1 + 100);
    }
    local_100 = 1;
    if (local_d8[10] != 1) {
      local_100 = (uint)(local_d8[10] == 2) << 1;
    }
    iVar56 = (int)*(short *)(local_d8 + 1);
    if (((bVar1) || (uVar55 == 0)) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar11 = ((int (*)())_createOffscreenBuffer)(param_1,local_d8,0);
      dVar62 = DOUBLE_0000cfe8;
      dVar61 = DOUBLE_0000cfe0;
      if (iVar11 == 0) goto LAB_000081e0;
      local_dc = DAT_0000e6e4 + 3;
      local_f8 = DAT_0000e6e4[0xc];
      if (local_f8 == 3) {
        local_f8 = 0xb;
      }
      else if (local_f8 == 6) {
        local_f8 = 0xc;
      }
      if (iVar38 != 0) {
        local_ac = &local_358;
        local_b8 = &local_364;
        local_b4 = &local_360;
        local_c8 = 0xc000;
        local_a8 = local_d4;
        local_b0 = &local_35c;
        local_e0 = 0;
        bVar9 = true;
        local_c4 = local_f4 & 0x1f | 0x53000;
        do {
          local_2f8 = 0x43300000;
          uStack_2f4 = local_ec + *(short *)local_a8 ^ 0x80000000;
          local_2f0 = 0x43300000;
          uStack_2ec = local_f0 + (short)*local_a8 ^ 0x80000000;
          dVar59 = (double)CONCAT44(0x43300000,uStack_2f4) - dVar61;
          local_2e8 = 0x43300000;
          uStack_2e4 = (int)*(short *)(local_a8 + 1) ^ 0x80000000;
          dVar63 = (double)(float)dVar59;
          local_2e0 = 0x43300000;
          dVar60 = (double)CONCAT44(0x43300000,uStack_2ec) - dVar61;
          uStack_2dc = (int)*(short *)((int)local_a8 + 6) ^ 0x80000000;
          dVar64 = (double)(float)dVar60;
          dVar2 = dVar63 + (double)(float)((double)CONCAT44(0x43300000,uStack_2e4) - dVar61);
          dVar65 = (double)(float)dVar2;
          dVar3 = dVar64 + (double)(float)((double)CONCAT44(0x43300000,uStack_2dc) - dVar61);
          dVar66 = (double)(float)dVar3;
          if (DOUBLE_0000cff0 <= dVar63) {
            local_2d0 = (longlong)(int)(dVar63 - DOUBLE_0000cff0);
            local_104 = (int)(dVar63 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_104 = (uint)dVar59;
            local_2d8 = (longlong)(int)local_104;
          }
          if (DOUBLE_0000cff0 <= dVar64) {
            local_2c0 = (longlong)(int)(dVar64 - DOUBLE_0000cff0);
            local_108 = (int)(dVar64 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_108 = (uint)dVar60;
            local_2c8 = (longlong)(int)local_108;
          }
          if (DOUBLE_0000cff0 <= dVar65) {
            local_2b0 = (longlong)(int)(dVar65 - DOUBLE_0000cff0);
            local_10c = (int)(dVar65 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_10c = (uint)dVar2;
            local_2b8 = (longlong)(int)local_10c;
          }
          if (DOUBLE_0000cff0 <= dVar66) {
            local_2a0 = (longlong)(int)(dVar66 - DOUBLE_0000cff0);
            local_110 = (int)(dVar66 - DOUBLE_0000cff0) + 0x80000000;
          }
          else {
            local_110 = (uint)dVar3;
            local_2a8 = (longlong)(int)local_110;
          }
          if (bVar9) {
            if (uVar48 < 0x8a) {
              local_360 = *(float *)(param_1 + 0x18);
              local_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar53 = 0x5c8;
                local_364 = 2.8026e-45;
                pdVar53[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar53[(int)local_364] = 0x1000000;
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_364 | *puVar13;
              iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,local_b4,local_b8,1);
              if (iVar11 == 0) {
                *(undefined4 *)((int)local_360 + 0x1c) = 0;
                pdVar53 = (dword *)((int)local_360 + 0x20);
                *(float *)(param_1 + 0x18) = local_360;
                pdVar27 = (dword *)((int)local_360 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
              }
              else {
LAB_00005e40:
                pdVar53 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar27 = &__mh_bundle_header.cputype;
              }
LAB_00005e7c:
              bVar9 = true;
              uVar48 = uVar39;
            }
            else {
              pdVar27 = pdVar53 + 1;
              bVar9 = true;
            }
          }
          else {
            if (uVar48 < 0x22) {
              local_364 = *(float *)(param_1 + 0x18);
              local_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar53 = 0x5c8;
                local_360 = 2.8026e-45;
                pdVar53[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar53[(int)local_360] = 0x1000000;
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_360 | *puVar13;
              iVar11 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,local_b8,local_b4,1);
              if (iVar11 != 0) goto LAB_00005e40;
              *(undefined4 *)((int)local_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_364;
              pdVar53 = (dword *)((int)local_364 + 0x20);
              pdVar27 = (dword *)((int)local_364 + 0x24);
              *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
              goto LAB_00005e7c;
            }
            pdVar27 = pdVar53 + 1;
            bVar9 = false;
          }
          if (bVar1) {
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = 0xa000000;
          }
          else {
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = 0xe000000;
          }
          pdVar53 = pdVar27 + 5;
          *pdVar27 = local_fc;
          puVar13 = *(uint **)(param_1 + 0x7c);
          *puVar13 = (int)(pdVar27 + 1) - (int)puVar13 >> 2 | *puVar13;
          *(dword **)(param_1 + 0x7c) = pdVar27 + 1;
          pdVar27[1] = 0x10000000;
          pdVar27[2] = *(dword *)*DAT_0000e6e4;
          dVar24 = DAT_0000e6e4[7];
          pdVar27[4] = 6;
          pdVar27[3] = dVar24;
          if (bVar9) {
            iVar23 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar53,local_d8,local_f4,0,0,0,0);
            iVar56 = iVar23 + 1;
            iVar15 = iVar23 + 0x16;
            iVar11 = iVar23 << 2;
            iVar57 = iVar23 + 2;
            iVar34 = iVar23 + 3;
            iVar35 = iVar23 + 4;
            iVar16 = iVar23 + 5;
            iVar25 = iVar23 + 6;
            iVar18 = iVar23 + 7;
            iVar21 = iVar23 + 8;
            iVar36 = iVar23 + 9;
            iVar37 = iVar23 + 10;
            iVar40 = iVar23 + 0xb;
            iVar41 = iVar23 + 0xc;
            iVar42 = iVar23 + 0xd;
            iVar43 = iVar23 + 0xe;
            iVar44 = iVar23 + 0xf;
            iVar46 = iVar23 + 0x10;
            iVar47 = iVar23 + 0x11;
            iVar49 = iVar23 + 0x12;
            iVar50 = iVar23 + 0x13;
            iVar14 = iVar23 + 0x14;
            iVar23 = iVar23 + 0x15;
          }
          else {
            *pdVar53 = 0x1120;
            sVar5 = *(short *)(local_d8 + 1);
            iVar11 = *(short *)((int)local_d8 + 6) + -1;
            pdVar27[6] = (int)sVar5 - 1U & 0x7ff | iVar11 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar27[7] = 0x1130;
            pdVar27[8] = local_c4;
            pdVar27[9] = 0x1140;
            pdVar27[10] = local_d8[4] - 1 & 0x3fff | ((int)sVar5 - 1U) * 0x10 & 0x8000 |
                          iVar11 * 0x20 & 0x10000U;
            iVar11 = 0x18;
            iVar57 = 8;
            iVar34 = 9;
            iVar56 = 7;
            iVar35 = 10;
            iVar16 = 0xb;
            iVar25 = 0xc;
            iVar18 = 0xd;
            iVar21 = 0xe;
            iVar36 = 0xf;
            iVar37 = 0x10;
            iVar40 = 0x11;
            iVar41 = 0x12;
            iVar42 = 0x13;
            iVar43 = 0x14;
            iVar44 = 0x15;
            iVar46 = 0x16;
            iVar47 = 0x17;
            iVar49 = 0x18;
            iVar50 = 0x19;
            iVar14 = 0x1a;
            iVar23 = 0x1b;
            iVar15 = 0x1c;
          }
          *(undefined4 *)((int)pdVar53 + iVar11) = 0x10f8;
          pdVar53[iVar56] = local_104 & 0x1fff | (local_108 & 0x1fff) << 0xd;
          pdVar53[iVar57] = 0x10f9;
          pdVar53[iVar34] = local_10c & 0x1fff | (local_110 & 0x1fff) << 0xd;
          pdVar53[iVar35] = 0xc00c3500;
          pdVar53[iVar16] = 0x4003d;
          local_298 = 0x43300000;
          uStack_294 = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          local_358 = (float)(dVar63 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_294) - dVar61))
                             );
          local_290 = 0x43300000;
          uStack_28c = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          local_35c = (float)(dVar65 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_28c) - dVar61))
                             );
          local_288 = 0x43300000;
          uStack_284 = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
          local_360 = (float)(dVar64 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_284) - dVar61))
                             );
          local_280 = 0x43300000;
          uStack_27c = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
          local_364 = (float)(dVar66 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_27c) - dVar61))
                             );
          pdVar53[iVar25] = local_104 | local_110 << 0x10;
          fVar26 = *local_ac;
          pdVar53[iVar18] = (dword)fVar26;
          fVar19 = *local_b8;
          pdVar53[iVar21] = (dword)fVar19;
          pdVar53[iVar36] = local_104 | local_108 << 0x10;
          pdVar53[iVar37] = (dword)fVar26;
          fVar26 = *local_b4;
          pdVar53[iVar40] = (dword)fVar26;
          pdVar53[iVar41] = local_10c | local_108 << 0x10;
          fVar31 = *local_b0;
          pdVar53[iVar42] = (dword)fVar31;
          pdVar53[iVar43] = (dword)fVar26;
          pdVar53[iVar44] = local_10c | local_110 << 0x10;
          pdVar53[iVar46] = (dword)fVar31;
          pdVar53[iVar47] = (dword)fVar19;
          pdVar53[iVar49] = 0x1393;
          pdVar53[iVar50] = 10;
          pdVar53[iVar14] = 0x5c8;
          pdVar53[iVar23] = 0x20000;
          uVar55 = (uVar48 - 6) - iVar15;
          pdVar53 = pdVar53 + iVar15;
          uVar51 = local_e4 + *(short *)local_a8;
          uVar48 = uVar51 + (int)*(short *)(local_a8 + 1);
          iVar56 = local_e8 + (short)*local_a8;
          iVar11 = iVar56 + *(short *)((int)local_a8 + 6);
          if (uVar55 < 0x22) {
            local_35c = *(float *)(param_1 + 0x18);
            local_358 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar53 = 0x5c8;
              local_358 = 2.8026e-45;
              pdVar53[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar10 = PTR_0000e694;
            pdVar53[(int)local_358] = 0x1000000;
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_358 | *puVar13;
            iVar23 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar10,
                                         local_b0,local_ac,1);
            if (iVar23 == 0) {
              *(undefined4 *)((int)local_35c + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_35c;
              pdVar53 = (dword *)((int)local_35c + 0x20);
              pdVar27 = (dword *)((int)local_35c + 0x24);
              *(int *)(param_1 + 0x7c) = (int)local_35c + 0x1c;
            }
            else {
              pdVar53 = (dword *)0x0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar27 = &__mh_bundle_header.cputype;
            }
            bVar9 = true;
            uVar55 = uVar39;
          }
          else {
            pdVar27 = pdVar53 + 1;
            bVar9 = false;
          }
          if (bVar1) {
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = 0x11000000;
          }
          else {
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = 0x12000000;
          }
          pdVar27[1] = 0;
          pdVar27[2] = 0;
          pdVar53 = pdVar27 + 5;
          *pdVar27 = local_fc;
          puVar13 = *(uint **)(param_1 + 0x7c);
          *puVar13 = (int)(pdVar27 + 3) - (int)puVar13 >> 2 | *puVar13;
          *(dword **)(param_1 + 0x7c) = pdVar27 + 3;
          pdVar27[3] = 0x4000000;
          pdVar27[4] = *(dword *)*DAT_0000e6e4;
          if (bVar9) {
            iVar14 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar53,local_dc,local_f8,0,0,0,0);
            iVar25 = iVar14 + 4;
            iVar36 = iVar14 + 9;
            local_15c = iVar14 + 3;
            local_154 = iVar14 + 1;
            local_158 = iVar14 + 2;
            iVar16 = iVar14 + 0x16;
            iVar23 = iVar14 << 2;
            iVar18 = iVar14 + 5;
            iVar35 = iVar14 + 6;
            iVar21 = iVar14 + 7;
            iVar34 = iVar14 + 8;
            iVar50 = iVar14 + 10;
            iVar37 = iVar14 + 0xb;
            iVar40 = iVar14 + 0xc;
            iVar41 = iVar14 + 0xd;
            iVar42 = iVar14 + 0xe;
            iVar43 = iVar14 + 0xf;
            iVar44 = iVar14 + 0x10;
            iVar46 = iVar14 + 0x11;
            iVar47 = iVar14 + 0x12;
            iVar49 = iVar14 + 0x13;
            iVar15 = iVar14 + 0x14;
            iVar14 = iVar14 + 0x15;
          }
          else {
            *pdVar53 = 0x1120;
            sVar5 = *(short *)(local_dc + 1);
            iVar23 = *(short *)((int)local_dc + 6) + -1;
            pdVar27[6] = (int)sVar5 - 1U & 0x7ff | iVar23 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar27[7] = 0x1130;
            pdVar27[8] = local_f8 & 0x1f | 0x53000;
            pdVar27[9] = 0x1140;
            pdVar27[10] = local_dc[4] - 1 & 0x3fff | ((int)sVar5 - 1U) * 0x10 & 0x8000 |
                          iVar23 * 0x20 & 0x10000U;
            iVar25 = 10;
            local_15c = 9;
            iVar23 = 0x18;
            iVar36 = 0xf;
            local_154 = 7;
            iVar18 = 0xb;
            local_158 = 8;
            iVar21 = 0xd;
            iVar35 = 0xc;
            iVar34 = 0xe;
            iVar50 = 0x10;
            iVar37 = 0x11;
            iVar40 = 0x12;
            iVar41 = 0x13;
            iVar42 = 0x14;
            iVar43 = 0x15;
            iVar44 = 0x16;
            iVar46 = 0x17;
            iVar47 = 0x18;
            iVar49 = 0x19;
            iVar15 = 0x1a;
            iVar14 = 0x1b;
            iVar16 = 0x1c;
          }
          *(undefined4 *)((int)pdVar53 + iVar23) = 0x10f8;
          pdVar53[local_154] = uVar51 & 0x1fff | iVar56 * 0x2000 & 0x3ffe000U;
          pdVar53[local_158] = 0x10f9;
          pdVar53[local_15c] = uVar48 & 0x1fff | iVar11 * 0x2000 & 0x3ffe000U;
          pdVar53[iVar25] = 0xc00c3500;
          pdVar53[iVar18] = 0x4003d;
          uVar45 = iVar11 * 0x10000;
          local_278 = 0x43300000;
          uStack_274 = (int)*(short *)(local_dc + 1) ^ 0x80000000;
          local_364 = (float)(dVar63 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_274) - dVar61))
                             );
          local_270 = 0x43300000;
          uStack_26c = (int)*(short *)(local_dc + 1) ^ 0x80000000;
          local_360 = (float)(dVar65 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_26c) - dVar61))
                             );
          local_268 = 0x43300000;
          uStack_264 = (int)*(short *)((int)local_dc + 6) ^ 0x80000000;
          local_358 = (float)(dVar64 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_264) - dVar61))
                             );
          local_260 = 0x43300000;
          uStack_25c = (int)*(short *)((int)local_dc + 6) ^ 0x80000000;
          local_35c = (float)(dVar66 * (dVar62 / ((double)CONCAT44(0x43300000,uStack_25c) - dVar61))
                             );
          pdVar53[iVar35] = uVar51 | uVar45;
          fVar26 = *local_b8;
          pdVar53[iVar21] = (dword)fVar26;
          fVar19 = *local_b0;
          pdVar53[iVar34] = (dword)fVar19;
          pdVar53[iVar36] = uVar51 | iVar56 * 0x10000;
          pdVar53[iVar50] = (dword)fVar26;
          fVar26 = *local_ac;
          pdVar53[iVar37] = (dword)fVar26;
          pdVar53[iVar40] = uVar48 | iVar56 * 0x10000;
          fVar31 = *local_b4;
          pdVar53[iVar41] = (dword)fVar31;
          pdVar53[iVar42] = (dword)fVar26;
          pdVar53[iVar43] = uVar48 | uVar45;
          pdVar53[iVar44] = (dword)fVar31;
          pdVar53[iVar46] = (dword)fVar19;
          pdVar53[iVar47] = 0x1393;
          pdVar53[iVar49] = 10;
          pdVar53[iVar15] = 0x5c8;
          pdVar53[iVar14] = 0x20000;
          uVar48 = (uVar55 - 6) - iVar16;
          pdVar53 = pdVar53 + iVar16;
          local_e0 = local_e0 + 1;
          local_a8 = local_a8 + 2;
          bVar9 = false;
        } while (iVar38 != local_e0);
      }
    }
    else if (iVar56 < 0x1001) {
      if (iVar38 != 0) {
        local_114 = dVar30 * dVar24 * 0x1000;
        local_b0 = &local_35c;
        local_b8 = &local_364;
        local_b4 = &local_360;
        local_ac = &local_358;
        local_170 = 0;
        bVar1 = true;
        piVar54 = local_d4;
        do {
          local_160 = (short *)((int)piVar54 + 2);
          local_164 = (short *)((int)piVar54 + 6);
          local_258 = 0x43300000;
          uStack_254 = local_ec + *(short *)piVar54 ^ 0x80000000;
          uVar51 = local_e4 + *(short *)piVar54;
          local_250 = 0x43300000;
          iVar56 = local_e8 + (short)*piVar54;
          uStack_24c = local_f0 + (short)*piVar54 ^ 0x80000000;
          local_248 = 0x43300000;
          uStack_244 = (int)*(short *)(piVar54 + 1) ^ 0x80000000;
          uVar55 = uVar51 + (int)*(short *)(piVar54 + 1);
          fVar31 = (float)((double)CONCAT44(0x43300000,uStack_254) - DOUBLE_0000cfe0);
          local_240 = 0x43300000;
          uStack_23c = (int)*(short *)((int)piVar54 + 6) ^ 0x80000000;
          uVar45 = iVar56 + *(short *)((int)piVar54 + 6);
          fVar4 = (float)((double)CONCAT44(0x43300000,uStack_24c) - DOUBLE_0000cfe0);
          iVar11 = (int)*(short *)((int)local_d8 + 6);
          fVar8 = fVar4 + (float)((double)CONCAT44(0x43300000,uStack_23c) - DOUBLE_0000cfe0);
          if (iVar11 < 0x1000) {
            local_238 = 0x43300000;
            fVar17 = (float)((double)CONCAT44(0x43300000,iVar11) - DOUBLE_0000cfd8);
            iStack_234 = iVar11;
          }
          else {
            fVar17 = FLOAT_0000d004;
            if (FLOAT_0000d004 <= fVar8) {
              iVar11 = 0x1000;
              uVar45 = local_e8 + 0x1000;
              fVar8 = FLOAT_0000d004;
            }
            else {
              iVar11 = 0x1000;
            }
          }
          local_230 = 0x43300000;
          uStack_22c = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          fVar17 = fVar26 * (FLOAT_0000d000 / fVar17);
          fVar8 = fVar8 * fVar17;
          fVar4 = fVar4 * fVar17;
          fVar17 = fVar19 * (FLOAT_0000d000 /
                            (float)((double)CONCAT44(0x43300000,uStack_22c) - DOUBLE_0000cfe0));
          fVar7 = (fVar31 + (float)((double)CONCAT44(0x43300000,uStack_244) - DOUBLE_0000cfe0)) *
                  fVar17;
          fVar31 = fVar31 * fVar17;
          if (bVar1) {
            if (uVar48 < 0x8a) {
              local_360 = *(float *)(param_1 + 0x18);
              local_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar53 = 0x5c8;
                local_364 = 2.8026e-45;
                pdVar53[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar53[(int)local_364] = 0x1000000;
              puVar10 = PTR_0000e694;
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_364 | *puVar13;
              iVar23 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)puVar10,local_b4,local_b8,1);
              if (iVar23 == 0) {
                *(undefined4 *)((int)local_360 + 0x1c) = 0;
                pdVar53 = (dword *)((int)local_360 + 0x20);
                *(float *)(param_1 + 0x18) = local_360;
                pdVar52 = (dword *)((int)local_360 + 0x38);
                pdVar27 = (dword *)((int)local_360 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
                pdVar20 = (dword *)((int)local_360 + 0x28);
                pdVar22 = (dword *)((int)local_360 + 0x2c);
                pdVar29 = (dword *)((int)local_360 + 0x30);
                pdVar33 = (dword *)((int)local_360 + 0x34);
                uVar48 = uVar39;
              }
              else {
LAB_00006cc0:
                pdVar53 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar27 = &__mh_bundle_header.cputype;
                pdVar20 = &__mh_bundle_header.cpusubtype;
                pdVar22 = &__mh_bundle_header.filetype;
                pdVar29 = &__mh_bundle_header.ncmds;
                pdVar33 = &__mh_bundle_header.sizeofcmds;
                pdVar52 = &__mh_bundle_header.flags;
                uVar48 = uVar39;
              }
            }
            else {
              pdVar27 = pdVar53 + 1;
              pdVar20 = pdVar53 + 2;
              pdVar22 = pdVar53 + 3;
              pdVar29 = pdVar53 + 4;
              pdVar33 = pdVar53 + 5;
              pdVar52 = pdVar53 + 6;
            }
LAB_00006d28:
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = local_140;
            *pdVar27 = local_fc;
            *pdVar20 = local_100;
            *pdVar22 = 0;
            *pdVar29 = 0;
            *pdVar33 = 0;
            uVar48 = uVar48 - 6;
            iVar15 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,0,iVar11);
            local_148 = iVar15 + 0xe;
            local_14c = iVar15 + 0xf;
            iVar18 = iVar15 + 0x16;
            iVar11 = iVar15 << 2;
            local_150 = iVar15 + 0x10;
            iVar14 = iVar15 + 0x11;
            iVar23 = iVar15 + 0x12;
            iVar35 = iVar15 + 1;
            iVar36 = iVar15 + 2;
            iVar34 = iVar15 + 3;
            iVar21 = iVar15 + 4;
            iVar25 = iVar15 + 5;
            iVar40 = iVar15 + 6;
            iVar41 = iVar15 + 7;
            iVar42 = iVar15 + 8;
            iVar43 = iVar15 + 9;
            iVar44 = iVar15 + 10;
            iVar46 = iVar15 + 0xb;
            iVar47 = iVar15 + 0xc;
            iVar16 = iVar15 + 0xd;
            iVar49 = iVar15 + 0x13;
            iVar37 = iVar15 + 0x14;
            iVar15 = iVar15 + 0x15;
            pdVar53 = pdVar52;
            fparam_1 = extraout_f1_01;
          }
          else {
            if (uVar48 < 0x16) {
              local_364 = *(float *)(param_1 + 0x18);
              local_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar53 = 0x5c8;
                local_360 = 2.8026e-45;
                pdVar53[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar53[(int)local_360] = 0x1000000;
              puVar10 = PTR_0000e694;
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_360 | *puVar13;
              iVar23 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)puVar10,local_b8,local_b4,1);
              if (iVar23 != 0) goto LAB_00006cc0;
              *(undefined4 *)((int)local_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_364;
              pdVar53 = (dword *)((int)local_364 + 0x20);
              pdVar52 = (dword *)((int)local_364 + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
              pdVar27 = (dword *)((int)local_364 + 0x24);
              pdVar20 = (dword *)((int)local_364 + 0x28);
              pdVar22 = (dword *)((int)local_364 + 0x2c);
              pdVar29 = (dword *)((int)local_364 + 0x30);
              pdVar33 = (dword *)((int)local_364 + 0x34);
              uVar48 = uVar39;
              goto LAB_00006d28;
            }
            iVar11 = 0;
            iVar35 = 1;
            local_148 = 0xe;
            local_14c = 0xf;
            iVar14 = 0x11;
            local_150 = 0x10;
            iVar36 = 2;
            iVar34 = 3;
            iVar23 = 0x12;
            iVar21 = 4;
            iVar25 = 5;
            iVar40 = 6;
            iVar41 = 7;
            iVar42 = 8;
            iVar43 = 9;
            iVar44 = 10;
            iVar46 = 0xb;
            iVar47 = 0xc;
            iVar16 = 0xd;
            iVar49 = 0x13;
            iVar37 = 0x14;
            iVar15 = 0x15;
            iVar18 = 0x16;
          }
          *(undefined4 *)((int)pdVar53 + iVar11) = 0x10f8;
          local_cc = uVar51 & 0x1fff;
          pdVar53[iVar35] = local_cc | iVar56 * 0x2000 & 0x3ffe000U;
          pdVar53[iVar36] = 0x10f9;
          local_d0 = uVar55 & 0x1fff;
          pdVar53[iVar34] = local_d0 | (uVar45 & 0x1fff) << 0xd;
          pdVar53[iVar21] = 0xc00c3500;
          pdVar53[iVar25] = 0x4003d;
          pdVar53[iVar40] = uVar51 | uVar45 << 0x10;
          fVar28 = *local_b0;
          pdVar53[iVar41] = (dword)fVar28;
          fVar17 = *local_b8;
          pdVar53[iVar42] = (dword)fVar17;
          pdVar53[iVar43] = uVar51 | iVar56 * 0x10000;
          pdVar53[iVar44] = (dword)fVar28;
          fVar28 = *local_b4;
          pdVar53[iVar46] = (dword)fVar28;
          pdVar53[iVar47] = uVar55 | iVar56 * 0x10000;
          fVar32 = *local_ac;
          pdVar53[iVar16] = (dword)fVar32;
          pdVar53[local_148] = (dword)fVar28;
          pdVar53[local_14c] = uVar55 | uVar45 << 0x10;
          pdVar53[local_150] = (dword)fVar32;
          pdVar53[iVar14] = (dword)fVar17;
          pdVar53[iVar23] = 0x1393;
          pdVar53[iVar49] = 10;
          pdVar53[iVar37] = 0x5c8;
          pdVar53[iVar15] = 0x20000;
          uVar48 = uVar48 - iVar18;
          bVar1 = false;
          pdVar53 = pdVar53 + iVar18;
          iVar11 = (int)*local_160 + (int)*local_164;
          local_364 = fVar8;
          local_360 = fVar4;
          local_35c = fVar31;
          local_358 = fVar7;
          if (0xfff < iVar11) {
            local_228 = 0x43300000;
            iVar23 = local_e8 + 0x1000;
            iVar56 = local_e8 + *local_160 + (int)*local_164;
            uStack_224 = (local_f0 + iVar11) - 0x1000U ^ 0x80000000;
            local_220 = 0x43300000;
            iVar11 = *(short *)((int)local_d8 + 6) + -0x1000;
            fVar17 = fVar26 * (FLOAT_0000d000 /
                              (float)((double)CONCAT44(0x43300000,iVar11) - DOUBLE_0000cfd8));
            fVar28 = (float)((double)CONCAT44(0x43300000,uStack_224) - DOUBLE_0000cfe0) * fVar17;
            fVar17 = fVar17 * FLOAT_0000d008;
            iStack_21c = iVar11;
            if (uVar48 < 0x8a) {
              local_358 = *(float *)(param_1 + 0x18);
              local_35c = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar53 = 0x5c8;
                local_35c = 2.8026e-45;
                pdVar53[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar53[(int)local_35c] = 0x1000000;
              puVar10 = PTR_0000e694;
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_35c | *puVar13;
              iVar14 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)puVar10,local_ac,local_b0,1);
              if (iVar14 == 0) {
                *(undefined4 *)((int)local_358 + 0x1c) = 0;
                *(float *)(param_1 + 0x18) = local_358;
                pdVar53 = (dword *)((int)local_358 + 0x20);
                pdVar52 = (dword *)((int)local_358 + 0x38);
                *(int *)(param_1 + 0x7c) = (int)local_358 + 0x1c;
                pdVar27 = (dword *)((int)local_358 + 0x24);
                pdVar20 = (dword *)((int)local_358 + 0x28);
                pdVar22 = (dword *)((int)local_358 + 0x2c);
                pdVar29 = (dword *)((int)local_358 + 0x30);
                pdVar33 = (dword *)((int)local_358 + 0x34);
                uVar48 = uVar39;
              }
              else {
                pdVar53 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar27 = &__mh_bundle_header.cputype;
                pdVar20 = &__mh_bundle_header.cpusubtype;
                pdVar22 = &__mh_bundle_header.filetype;
                pdVar29 = &__mh_bundle_header.ncmds;
                pdVar33 = &__mh_bundle_header.sizeofcmds;
                pdVar52 = &__mh_bundle_header.flags;
                uVar48 = uVar39;
              }
            }
            else {
              pdVar27 = pdVar53 + 1;
              pdVar20 = pdVar53 + 2;
              pdVar22 = pdVar53 + 3;
              pdVar29 = pdVar53 + 4;
              pdVar33 = pdVar53 + 5;
              pdVar52 = pdVar53 + 6;
            }
            puVar13 = *(uint **)(param_1 + 0x7c);
            *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
            *(dword **)(param_1 + 0x7c) = pdVar53;
            *pdVar53 = local_140;
            *pdVar27 = local_fc;
            *pdVar20 = local_100;
            *pdVar22 = local_114;
            *pdVar29 = 0;
            *pdVar33 = 0;
            iVar11 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,0,iVar11);
            pdVar52[iVar11] = 0x10f8;
            pdVar52[iVar11 + 1] = local_cc | iVar23 * 0x2000 & 0x3ffe000U;
            pdVar52[iVar11 + 2] = 0x10f9;
            pdVar52[iVar11 + 3] = local_d0 | iVar56 * 0x2000 & 0x3ffe000U;
            pdVar52[iVar11 + 4] = 0xc00c3500;
            pdVar52[iVar11 + 5] = 0x4003d;
            uVar45 = iVar56 * 0x10000;
            pdVar52[iVar11 + 6] = uVar51 | uVar45;
            pdVar52[iVar11 + 7] = (dword)fVar31;
            pdVar52[iVar11 + 8] = (dword)fVar28;
            uVar6 = iVar23 * 0x10000;
            pdVar52[iVar11 + 9] = uVar51 | uVar6;
            pdVar52[iVar11 + 10] = (dword)fVar31;
            pdVar52[iVar11 + 0xb] = (dword)fVar17;
            pdVar52[iVar11 + 0xc] = uVar55 | uVar6;
            pdVar52[iVar11 + 0xd] = (dword)fVar7;
            pdVar52[iVar11 + 0xe] = (dword)fVar17;
            pdVar52[iVar11 + 0xf] = uVar55 | uVar45;
            pdVar52[iVar11 + 0x10] = (dword)fVar7;
            pdVar52[iVar11 + 0x11] = (dword)fVar28;
            pdVar52[iVar11 + 0x12] = 0x1393;
            pdVar52[iVar11 + 0x13] = 10;
            pdVar52[iVar11 + 0x14] = 0x5c8;
            pdVar52[iVar11 + 0x15] = 0x20000;
            uVar48 = (uVar48 - 6) - (iVar11 + 0x16);
            bVar1 = true;
            pdVar53 = pdVar52 + iVar11 + 0x16;
            fparam_1 = extraout_f1_02;
            local_364 = fVar31;
            local_360 = fVar7;
            local_35c = fVar17;
            local_358 = fVar28;
          }
          piVar54 = piVar54 + 2;
          local_170 = local_170 + 1;
        } while (iVar38 != local_170);
      }
    }
    else {
      local_120 = iVar56 >> 1 & 0xfffffe00;
      local_11c = iVar56 - local_120;
      local_118 = local_120 + 2;
      local_208 = 0x43300000;
      local_218 = 0x43300000;
      local_210 = 0x43300000;
      uStack_214 = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
      uStack_204 = local_11c ^ 0x80000000;
      uStack_20c = local_118 ^ 0x80000000;
      fVar31 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_214) - DOUBLE_0000cfe0);
      fVar4 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_204) - DOUBLE_0000cfe0);
      fVar8 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_20c) - DOUBLE_0000cfe0);
      if (iVar38 != 0) {
        bVar1 = true;
        local_174 = 0;
        local_c0 = 0xc000;
        local_168 = local_d4;
        do {
          iVar56 = (int)*(short *)local_168;
          if (local_ec + iVar56 < (int)local_118) {
            uStack_1fc = local_ec + iVar56 ^ 0x80000000;
            local_200 = 0x43300000;
            uVar55 = local_ec + iVar56 + *(short *)(local_168 + 1);
            uStack_1f4 = local_118;
            if ((int)uVar55 < (int)local_118) {
              uStack_1f4 = uVar55;
            }
            uStack_1f4 = uStack_1f4 ^ 0x80000000;
            local_1f8 = 0x43300000;
            local_16c = local_e4 + iVar56;
            uVar55 = local_16c + (int)*(short *)(local_168 + 1);
            iVar56 = (int)(short)*local_168;
            local_1f0 = 0x43300000;
            uStack_1ec = local_f0 + iVar56 ^ 0x80000000;
            local_1e8 = 0x43300000;
            uStack_1e4 = local_f0 + iVar56 + *(short *)((int)local_168 + 6) ^ 0x80000000;
            if ((int)local_118 < (int)uVar55) {
              local_1e0 = 0x43300000;
              uStack_1dc = local_e4 + local_118 ^ 0x80000000;
              uVar55 = uStack_1dc;
            }
            else {
              uStack_1d4 = uVar55 ^ 0x80000000;
              local_1d8 = 0x43300000;
              uVar55 = uStack_1d4;
            }
            dVar61 = (double)CONCAT44(0x43300000,uVar55) - DOUBLE_0000cfe0;
            dVar62 = (double)(float)dVar61;
            if (DOUBLE_0000cff0 <= dVar62) {
              iVar23 = (int)(dVar62 - DOUBLE_0000cff0);
              local_1c8 = (longlong)iVar23;
              local_124 = iVar23 + 0x80000000;
            }
            else {
              local_124 = (uint)dVar61;
              local_1d0 = (longlong)(int)local_124;
            }
            fVar28 = fVar19 * fVar8 * (float)((double)CONCAT44(0x43300000,uStack_1fc) -
                                             DOUBLE_0000cfe0);
            fVar32 = fVar19 * fVar8 * (float)((double)CONCAT44(0x43300000,uStack_1f4) -
                                             DOUBLE_0000cfe0);
            fVar17 = fVar26 * fVar31 * (float)((double)CONCAT44(0x43300000,uStack_1ec) -
                                              DOUBLE_0000cfe0);
            fVar7 = fVar26 * fVar31 * (float)((double)CONCAT44(0x43300000,uStack_1e4) -
                                             DOUBLE_0000cfe0);
            local_128 = local_e8 + iVar56;
            local_12c = local_128 + (int)*(short *)((int)local_168 + 6);
            if (bVar1) {
              if (uVar48 < 0x9e) {
                local_360 = *(float *)(param_1 + 0x18);
                local_364 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar53 = 0x5c8;
                  local_364 = 2.8026e-45;
                  pdVar53[1] = local_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar53[(int)local_364] = 0x1000000;
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_364 | *puVar13;
                iVar56 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_360,&local_364,1);
                if (iVar56 == 0) {
                  *(undefined4 *)((int)local_360 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_360;
                  pdVar53 = (dword *)((int)local_360 + 0x20);
                  pdVar52 = (dword *)((int)local_360 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
                  pdVar27 = (dword *)((int)local_360 + 0x24);
                  pdVar20 = (dword *)((int)local_360 + 0x28);
                  pdVar22 = (dword *)((int)local_360 + 0x2c);
                  pdVar29 = (dword *)((int)local_360 + 0x30);
                  pdVar33 = (dword *)((int)local_360 + 0x34);
                  uVar48 = uVar39;
                }
                else {
                  pdVar53 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar27 = &__mh_bundle_header.cputype;
                  pdVar20 = &__mh_bundle_header.cpusubtype;
                  pdVar22 = &__mh_bundle_header.filetype;
                  pdVar29 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  pdVar52 = &__mh_bundle_header.flags;
                  uVar48 = uVar39;
                }
              }
              else {
                pdVar27 = pdVar53 + 1;
                pdVar20 = pdVar53 + 2;
                pdVar22 = pdVar53 + 3;
                pdVar29 = pdVar53 + 4;
                pdVar33 = pdVar53 + 5;
                pdVar52 = pdVar53 + 6;
              }
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
              *(dword **)(param_1 + 0x7c) = pdVar53;
              *pdVar53 = local_140;
              *pdVar27 = local_fc;
              *pdVar20 = local_100;
              *pdVar22 = 0;
              *pdVar29 = 0;
              *pdVar33 = 0;
              uVar48 = uVar48 - 4;
              iVar56 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,local_118,0)
              ;
              fparam_1 = extraout_f1_03;
LAB_0000789c:
              iVar14 = iVar56 + 9;
              iVar40 = iVar56 + 0x16;
              iVar23 = iVar56 << 2;
              iVar21 = iVar56 + 1;
              iVar25 = iVar56 + 2;
              iVar34 = iVar56 + 3;
              iVar58 = iVar56 + 4;
              iVar35 = iVar56 + 5;
              iVar41 = iVar56 + 6;
              iVar42 = iVar56 + 7;
              iVar18 = iVar56 + 8;
              iVar36 = iVar56 + 10;
              iVar43 = iVar56 + 0xb;
              iVar37 = iVar56 + 0xc;
              iVar44 = iVar56 + 0xd;
              iVar46 = iVar56 + 0xe;
              iVar47 = iVar56 + 0xf;
              iVar49 = iVar56 + 0x10;
              iVar50 = iVar56 + 0x11;
              iVar57 = iVar56 + 0x12;
              iVar15 = iVar56 + 0x13;
              iVar16 = iVar56 + 0x14;
              iVar56 = iVar56 + 0x15;
              pdVar53 = pdVar52;
            }
            else {
              if (uVar48 < 0x2a) {
                local_364 = *(float *)(param_1 + 0x18);
                local_360 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar53 = 0x5c8;
                  local_360 = 2.8026e-45;
                  pdVar53[1] = local_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar53[(int)local_360] = 0x1000000;
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_360 | *puVar13;
                iVar56 = _IOConnectMapMemory(fparam_1,*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_364,&local_360,1);
                if (iVar56 == 0) {
                  *(undefined4 *)((int)local_364 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_364;
                  pdVar27 = (dword *)((int)local_364 + 0x20);
                  pdVar52 = (dword *)((int)local_364 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
                  pdVar53 = (dword *)((int)local_364 + 0x24);
                  pdVar20 = (dword *)((int)local_364 + 0x28);
                  pdVar22 = (dword *)((int)local_364 + 0x2c);
                  pdVar29 = (dword *)((int)local_364 + 0x30);
                  pdVar33 = (dword *)((int)local_364 + 0x34);
                }
                else {
                  pdVar27 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar53 = &__mh_bundle_header.cputype;
                  pdVar20 = &__mh_bundle_header.cpusubtype;
                  pdVar22 = &__mh_bundle_header.filetype;
                  pdVar29 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  pdVar52 = &__mh_bundle_header.flags;
                }
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = (int)pdVar27 - (int)puVar13 >> 2 | *puVar13;
                *(dword **)(param_1 + 0x7c) = pdVar27;
                *pdVar27 = local_140;
                *pdVar53 = local_fc;
                *pdVar20 = local_100;
                *pdVar22 = 0;
                *pdVar29 = 0;
                *pdVar33 = 0;
                uVar48 = iVar11 - 0xb;
                iVar56 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,local_118,
                                            0);
                fparam_1 = extraout_f1_04;
                goto LAB_0000789c;
              }
              iVar23 = 0;
              iVar21 = 1;
              iVar25 = 2;
              iVar14 = 9;
              iVar34 = 3;
              iVar58 = 4;
              iVar35 = 5;
              iVar41 = 6;
              iVar42 = 7;
              iVar18 = 8;
              iVar36 = 10;
              iVar43 = 0xb;
              iVar37 = 0xc;
              iVar44 = 0xd;
              iVar46 = 0xe;
              iVar47 = 0xf;
              iVar49 = 0x10;
              iVar50 = 0x11;
              iVar57 = 0x12;
              iVar15 = 0x13;
              iVar16 = 0x14;
              iVar56 = 0x15;
              iVar40 = 0x16;
            }
            *(undefined4 *)((int)pdVar53 + iVar23) = 0x10f8;
            pdVar53[iVar21] = local_16c & 0x1fff | (local_128 & 0x1fff) << 0xd;
            pdVar53[iVar25] = 0x10f9;
            pdVar53[iVar34] = local_124 & 0x1fff | (local_12c & 0x1fff) << 0xd;
            pdVar53[iVar58] = 0xc00c3500;
            pdVar53[iVar35] = 0x4003d;
            pdVar53[iVar41] = local_16c | local_12c << 0x10;
            pdVar53[iVar42] = (dword)fVar28;
            pdVar53[iVar18] = (dword)fVar7;
            pdVar53[iVar14] = local_16c | local_128 << 0x10;
            pdVar53[iVar36] = (dword)fVar28;
            pdVar53[iVar43] = (dword)fVar17;
            pdVar53[iVar37] = local_124 | local_128 << 0x10;
            pdVar53[iVar44] = (dword)fVar32;
            pdVar53[iVar46] = (dword)fVar17;
            pdVar53[iVar47] = local_124 | local_12c << 0x10;
            pdVar53[iVar49] = (dword)fVar32;
            pdVar53[iVar50] = (dword)fVar7;
            pdVar53[iVar57] = 0x1393;
            pdVar53[iVar15] = 10;
            pdVar53[iVar16] = 0x5c8;
            pdVar53[iVar56] = 0x20000;
            uVar48 = uVar48 - iVar40;
            bVar1 = false;
            pdVar53 = pdVar53 + iVar40;
            local_364 = fVar7;
            local_360 = fVar17;
            local_35c = fVar32;
            local_358 = fVar28;
          }
          local_174 = local_174 + 1;
          local_168 = local_168 + 2;
        } while (iVar38 != local_174);
        bVar1 = true;
        local_178 = 0;
        local_bc = 0xc000;
        piVar54 = local_d4;
        do {
          iVar23 = (int)*(short *)piVar54;
          iVar56 = iVar23 + *(short *)(piVar54 + 1) + local_ec;
          if ((int)local_120 < iVar56) {
            uStack_1bc = local_120;
            if ((int)local_120 < iVar23 + local_ec) {
              uStack_1bc = iVar23 + local_ec;
            }
            uStack_1bc = uStack_1bc ^ 0x80000000;
            uStack_1b4 = local_120 ^ 0x80000000;
            uStack_1ac = iVar56 - local_120 ^ 0x80000000;
            local_134 = local_e4 + iVar23;
            local_1c0 = 0x43300000;
            local_1b8 = 0x43300000;
            local_1b0 = 0x43300000;
            iVar56 = (int)(short)*piVar54;
            local_1a8 = 0x43300000;
            uStack_1a4 = iVar56 + local_f0 ^ 0x80000000;
            local_1a0 = 0x43300000;
            uStack_19c = iVar56 + *(short *)((int)piVar54 + 6) + local_ec ^ 0x80000000;
            if ((int)local_120 < (int)local_134) {
              uStack_194 = local_134 ^ 0x80000000;
              local_198 = 0x43300000;
              uVar55 = uStack_194;
            }
            else {
              local_190 = 0x43300000;
              uStack_18c = local_e4 + local_120 ^ 0x80000000;
              uVar55 = uStack_18c;
            }
            dVar61 = (double)CONCAT44(0x43300000,uVar55) - DOUBLE_0000cfe0;
            dVar62 = (double)(float)dVar61;
            if (DOUBLE_0000cff0 <= dVar62) {
              iVar23 = (int)(dVar62 - DOUBLE_0000cff0);
              local_180 = (longlong)iVar23;
              local_130 = iVar23 + 0x80000000;
            }
            else {
              local_130 = (uint)dVar61;
              local_188 = (longlong)(int)local_130;
            }
            local_134 = local_134 + (int)*(short *)(piVar54 + 1);
            fVar7 = fVar19 * fVar4 * ((float)((double)CONCAT44(0x43300000,uStack_1bc) -
                                             DOUBLE_0000cfe0) -
                                     (float)((double)CONCAT44(0x43300000,uStack_1b4) -
                                            DOUBLE_0000cfe0));
            fVar28 = fVar19 * fVar4 * (float)((double)CONCAT44(0x43300000,uStack_1ac) -
                                             DOUBLE_0000cfe0);
            fVar8 = fVar26 * fVar31 * (float)((double)CONCAT44(0x43300000,uStack_1a4) -
                                             DOUBLE_0000cfe0);
            fVar17 = fVar26 * fVar31 * (float)((double)CONCAT44(0x43300000,uStack_19c) -
                                              DOUBLE_0000cfe0);
            local_138 = local_e8 + iVar56;
            local_13c = local_138 + (int)*(short *)((int)piVar54 + 6);
            if (bVar1) {
              if (uVar48 < 0x9e) {
                local_35c = *(float *)(param_1 + 0x18);
                local_358 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar53 = 0x5c8;
                  local_358 = 2.8026e-45;
                  pdVar53[1] = local_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar53[(int)local_358] = 0x1000000;
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_358 | *puVar13;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_35c,&local_358,1);
                if (iVar56 == 0) {
                  *(undefined4 *)((int)local_35c + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_35c;
                  pdVar53 = (dword *)((int)local_35c + 0x20);
                  pdVar52 = (dword *)((int)local_35c + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_35c + 0x1c;
                  pdVar27 = (dword *)((int)local_35c + 0x24);
                  pdVar20 = (dword *)((int)local_35c + 0x28);
                  pdVar22 = (dword *)((int)local_35c + 0x2c);
                  pdVar29 = (dword *)((int)local_35c + 0x30);
                  pdVar33 = (dword *)((int)local_35c + 0x34);
                  uVar48 = uVar39;
                }
                else {
                  pdVar53 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar27 = &__mh_bundle_header.cputype;
                  pdVar20 = &__mh_bundle_header.cpusubtype;
                  pdVar22 = &__mh_bundle_header.filetype;
                  pdVar29 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  pdVar52 = &__mh_bundle_header.flags;
                  uVar48 = uVar39;
                }
              }
              else {
                pdVar27 = pdVar53 + 1;
                pdVar20 = pdVar53 + 2;
                pdVar22 = pdVar53 + 3;
                pdVar29 = pdVar53 + 4;
                pdVar33 = pdVar53 + 5;
                pdVar52 = pdVar53 + 6;
              }
              puVar13 = *(uint **)(param_1 + 0x7c);
              *puVar13 = (int)pdVar53 - (int)puVar13 >> 2 | *puVar13;
              *(dword **)(param_1 + 0x7c) = pdVar53;
              *pdVar53 = local_140;
              *pdVar27 = local_fc;
              *pdVar20 = local_100;
              *pdVar22 = 0;
              *pdVar29 = local_d8[0xb];
              *pdVar33 = local_120;
              uVar48 = uVar48 - 4;
              iVar56 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,local_11c,0)
              ;
LAB_00007ff0:
              iVar14 = iVar56 + 9;
              iVar15 = iVar56 + 10;
              iVar40 = iVar56 + 0x16;
              iVar23 = iVar56 << 2;
              iVar25 = iVar56 + 1;
              iVar34 = iVar56 + 2;
              iVar35 = iVar56 + 3;
              iVar41 = iVar56 + 4;
              iVar42 = iVar56 + 5;
              iVar43 = iVar56 + 6;
              iVar44 = iVar56 + 7;
              iVar21 = iVar56 + 8;
              iVar46 = iVar56 + 0xb;
              iVar37 = iVar56 + 0xc;
              iVar47 = iVar56 + 0xd;
              iVar49 = iVar56 + 0xe;
              iVar58 = iVar56 + 0xf;
              iVar36 = iVar56 + 0x10;
              iVar50 = iVar56 + 0x11;
              iVar57 = iVar56 + 0x12;
              iVar16 = iVar56 + 0x13;
              iVar18 = iVar56 + 0x14;
              iVar56 = iVar56 + 0x15;
              pdVar53 = pdVar52;
            }
            else {
              if (uVar48 < 0x2a) {
                local_358 = *(float *)(param_1 + 0x18);
                local_35c = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar53 = 0x5c8;
                  local_35c = 2.8026e-45;
                  pdVar53[1] = local_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar53[(int)local_35c] = 0x1000000;
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = ((int)pdVar53 - (int)puVar13 >> 2) + (int)local_35c | *puVar13;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_358,&local_35c,1);
                if (iVar56 == 0) {
                  *(undefined4 *)((int)local_358 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_358;
                  pdVar27 = (dword *)((int)local_358 + 0x20);
                  pdVar52 = (dword *)((int)local_358 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_358 + 0x1c;
                  pdVar53 = (dword *)((int)local_358 + 0x24);
                  pdVar20 = (dword *)((int)local_358 + 0x28);
                  pdVar22 = (dword *)((int)local_358 + 0x2c);
                  pdVar29 = (dword *)((int)local_358 + 0x30);
                  pdVar33 = (dword *)((int)local_358 + 0x34);
                }
                else {
                  pdVar27 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar53 = &__mh_bundle_header.cputype;
                  pdVar20 = &__mh_bundle_header.cpusubtype;
                  pdVar22 = &__mh_bundle_header.filetype;
                  pdVar29 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  pdVar52 = &__mh_bundle_header.flags;
                }
                puVar13 = *(uint **)(param_1 + 0x7c);
                *puVar13 = (int)pdVar27 - (int)puVar13 >> 2 | *puVar13;
                *(dword **)(param_1 + 0x7c) = pdVar27;
                *pdVar27 = local_140;
                *pdVar53 = local_fc;
                *pdVar20 = local_100;
                *pdVar22 = 0;
                *pdVar29 = local_d8[0xb];
                *pdVar33 = local_120;
                uVar48 = iVar11 - 0xb;
                iVar56 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,local_144,0,local_11c,
                                            0);
                goto LAB_00007ff0;
              }
              iVar23 = 0;
              iVar25 = 1;
              iVar14 = 9;
              iVar34 = 2;
              iVar35 = 3;
              iVar15 = 10;
              iVar41 = 4;
              iVar42 = 5;
              iVar43 = 6;
              iVar44 = 7;
              iVar21 = 8;
              iVar46 = 0xb;
              iVar37 = 0xc;
              iVar47 = 0xd;
              iVar49 = 0xe;
              iVar58 = 0xf;
              iVar36 = 0x10;
              iVar50 = 0x11;
              iVar57 = 0x12;
              iVar16 = 0x13;
              iVar18 = 0x14;
              iVar56 = 0x15;
              iVar40 = 0x16;
            }
            *(undefined4 *)((int)pdVar53 + iVar23) = 0x10f8;
            pdVar53[iVar25] = local_130 & 0x1fff | (local_138 & 0x1fff) << 0xd;
            pdVar53[iVar34] = 0x10f9;
            pdVar53[iVar35] = local_134 & 0x1fff | (local_13c & 0x1fff) << 0xd;
            pdVar53[iVar41] = 0xc00c3500;
            pdVar53[iVar42] = 0x4003d;
            pdVar53[iVar43] = local_130 | local_13c << 0x10;
            pdVar53[iVar44] = (dword)fVar7;
            pdVar53[iVar21] = (dword)fVar17;
            pdVar53[iVar14] = local_130 | local_138 << 0x10;
            pdVar53[iVar15] = (dword)fVar7;
            pdVar53[iVar46] = (dword)fVar8;
            pdVar53[iVar37] = local_134 | local_138 << 0x10;
            pdVar53[iVar47] = (dword)fVar28;
            pdVar53[iVar49] = (dword)fVar8;
            pdVar53[iVar58] = local_134 | local_13c << 0x10;
            pdVar53[iVar36] = (dword)fVar28;
            pdVar53[iVar50] = (dword)fVar17;
            pdVar53[iVar57] = 0x1393;
            pdVar53[iVar16] = 10;
            pdVar53[iVar18] = 0x5c8;
            pdVar53[iVar56] = 0x20000;
            uVar48 = uVar48 - iVar40;
            bVar1 = false;
            pdVar53 = pdVar53 + iVar40;
            local_364 = fVar8;
            local_360 = fVar28;
            local_35c = fVar7;
            local_358 = fVar17;
          }
          piVar54 = piVar54 + 2;
          local_178 = local_178 + 1;
        } while (iVar38 != local_178);
      }
    }
    iVar11 = 0;
    *(dword **)(param_1 + 0x80) = pdVar53;
  }
  return iVar11;
}

/* _radeonFill @ 0x8260 (9000 bytes) */
int _radeonFill(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  bool bVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  float fVar14;
  float fVar15;
  undefined *puVar16;
  undefined4 *puVar17;
  float fVar18;
  int iVar19;
  dword dVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  dword *pdVar24;
  float fVar25;
  dword *pdVar26;
  uint uVar27;
  float fVar28;
  dword *pdVar29;
  int *piVar30;
  dword *pdVar31;
  float fVar32;
  int iVar33;
  uint *puVar34;
  int iVar35;
  dword *pdVar36;
  float fVar37;
  float fVar38;
  uint uVar39;
  dword *pdVar40;
  int iVar41;
  uint uVar42;
  uint uVar43;
  int iVar44;
  uint uVar45;
  int iVar46;
  uint uVar47;
  uint uVar48;
  int iVar49;
  int iVar50;
  int iVar51;
  uint uVar52;
  int iVar53;
  dword *pdVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  undefined4 *puVar58;
  int iVar59;
  int iVar60;
  int iVar61;
  double dVar62;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  float local_2e4 [3];
  undefined4 local_2d8;
  uint uStack_2d4;
  undefined4 local_2d0;
  uint uStack_2cc;
  undefined4 local_2c8;
  uint uStack_2c4;
  undefined4 local_2c0;
  uint uStack_2bc;
  undefined4 local_2b8;
  int iStack_2b4;
  undefined4 local_2b0;
  int iStack_2ac;
  undefined4 local_2a8;
  uint uStack_2a4;
  undefined4 local_2a0;
  uint uStack_29c;
  undefined4 local_298;
  uint uStack_294;
  undefined4 local_290;
  uint uStack_28c;
  undefined4 local_288;
  uint uStack_284;
  undefined4 local_280;
  uint uStack_27c;
  undefined4 local_278;
  uint uStack_274;
  undefined4 local_270;
  uint uStack_26c;
  undefined4 local_268;
  uint uStack_264;
  undefined4 local_260;
  uint uStack_25c;
  undefined4 local_258;
  uint uStack_254;
  undefined4 local_250;
  uint uStack_24c;
  undefined4 local_248;
  uint uStack_244;
  undefined4 local_240;
  uint uStack_23c;
  undefined4 local_238;
  uint uStack_234;
  undefined4 local_228;
  uint uStack_224;
  undefined4 local_218;
  uint uStack_214;
  undefined4 local_210;
  int iStack_20c;
  undefined4 local_208;
  uint uStack_204;
  undefined4 local_200;
  uint uStack_1fc;
  undefined4 local_1f8;
  int iStack_1f4;
  undefined4 local_1f0;
  uint uStack_1ec;
  undefined4 local_1e8;
  uint uStack_1e4;
  undefined4 local_1e0;
  uint uStack_1dc;
  undefined4 local_1d8;
  uint uStack_1d4;
  undefined4 local_1d0;
  uint uStack_1cc;
  undefined4 local_1c8;
  uint uStack_1c4;
  undefined4 local_1c0;
  uint uStack_1bc;
  undefined4 local_1b8;
  uint uStack_1b4;
  undefined4 local_1b0;
  uint uStack_1ac;
  undefined4 local_1a8;
  uint uStack_1a4;
  undefined4 local_1a0;
  uint uStack_19c;
  undefined4 local_198;
  uint uStack_194;
  undefined4 local_190;
  uint uStack_18c;
  uint local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  int local_108;
  uint local_104;
  int local_100;
  uint local_fc;
  short local_f8;
  short local_f6;
  int local_f4;
  int local_f0;
  float *local_ec;
  float *local_e8;
  float *local_e4;
  float *local_e0;
  float *local_dc;
  float *local_d8;
  float *local_d4;
  float *local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  float *local_c0;
  uint local_bc;
  
  uVar42 = param_4 & 0x7ffff000;
  if ((uVar42 != 0x6000) || ((param_3 & 0xf000) != 0)) {
    pdVar54 = *(dword **)(param_1 + 0x80);
    iVar33 = *(int *)(param_1 + 0x18);
    uVar52 = param_5[5];
    uVar39 = *(int *)(iVar33 + 0x10) - 7;
    if ((pdVar54 != (dword *)0x0) &&
       ((iVar21 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,(uint)(*(int *)(param_1 + 0x70) == 3)),
        iVar21 != 0 &&
        (iVar21 = ((int (*)())_createTextureBuffer)(param_1,0x40,0x40,(uint)(*(int *)(param_1 + 0x70) == 3)),
        iVar21 != 0)))) {
      local_f0 = 0x8284;
      local_108 = DAT_0000e748 + 0xc;
      if (uVar42 != 0x6000) {
        _fillTextureWithPattern(param_6,uVar42,*param_5,param_5[1]);
      }
      else {
        _fillTextureWithPattern(param_6,0x6000,param_6,param_6);
      }
      dVar13 = DOUBLE_0000cfe8;
      dVar11 = DOUBLE_0000cfe0;
      dVar9 = DOUBLE_0000cfd8;
      uVar42 = uVar39 - ((int)pdVar54 - (iVar33 + 0x20) >> 2);
      if (param_5[0x16] != 0) {
        local_bc = uVar52 & 0x7c00;
        local_c4 = (param_3 & 0xc000) >> 0xe & 1;
        local_104 = 0;
        bVar8 = (param_3 & 0xc000) == 0;
        puVar58 = param_5;
        do {
          fVar15 = FLOAT_0000d00c;
          fVar14 = FLOAT_0000d008;
          fVar18 = FLOAT_0000d000;
          dVar10 = DOUBLE_0000cfd8;
          local_114 = puVar58[0x18] + *(int *)(param_1 + 100);
          local_118 = local_114 + puVar58[0x1a];
          local_10c = puVar58[0x17] + *(int *)(param_1 + 0x60);
          local_110 = local_10c + puVar58[0x19];
          local_120 = local_118;
          if (local_114 + 8 < local_118) {
            local_120 = local_114 + 8;
          }
          iStack_2b4 = (local_10c & 7) + param_5[2];
          iStack_2ac = (local_114 & 7) + param_5[3];
          local_2b8 = 0x43300000;
          local_2b0 = 0x43300000;
          fVar1 = (float)((double)CONCAT44(0x43300000,iStack_2b4) - dVar9);
          fVar2 = (float)((double)CONCAT44(0x43300000,iStack_2ac) - dVar9);
          if (local_114 < local_118) {
            uVar48 = local_10c + 8;
            uVar43 = local_110;
            if (uVar48 < local_110) {
              uVar43 = uVar48;
            }
            local_290 = 0x43300000;
            bVar7 = true;
            uStack_28c = local_bc >> 10;
            fVar5 = fVar2 + FLOAT_0000d008;
            fVar6 = fVar2 + FLOAT_0000d00c;
            dVar62 = (double)CONCAT44(0x43300000,uStack_28c) - DOUBLE_0000cfd8;
            uVar27 = local_114;
            do {
              local_11c = uVar27;
              if (local_10c < local_110) {
                if (!bVar7) {
                  local_ec = &local_308;
                  local_2a8 = 0x43300000;
                  local_2a0 = 0x43300000;
                  uStack_2a4 = local_11c;
                  uStack_29c = local_120;
                  local_cc = local_120 << 0x10;
                  local_e0 = &local_2fc;
                  local_dc = &local_2f8;
                  local_c8 = local_11c << 0x10;
                  local_e4 = &local_300;
                  local_d4 = &local_2f0;
                  local_d0 = local_2e4;
                  local_d8 = &local_2f4;
                  local_e8 = &local_304;
                  local_f4 = local_120 - local_11c;
                  fVar3 = (float)((double)CONCAT44(0x43300000,local_11c) - dVar10);
                  fVar4 = (float)((double)CONCAT44(0x43300000,local_120) - dVar10);
                  uVar27 = uVar48;
                  uVar47 = local_10c;
                  local_124 = uVar43;
                  goto LAB_00008bec;
                }
                uVar45 = uVar48;
                if (uVar42 < 0xd4) {
                  local_2ec = *(float *)(param_1 + 0x18);
                  local_2e8 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar54 = 0x5c8;
                    local_2e8 = 2.8026e-45;
                    pdVar54[1] = 0xc000;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar54[(int)local_2e8] = 0x1000000;
                  puVar16 = PTR_0000e694;
                  puVar34 = *(uint **)(param_1 + 0x7c);
                  *puVar34 = ((int)pdVar54 - (int)puVar34 >> 2) + (int)local_2e8 | *puVar34;
                  iVar33 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar16,&local_2ec,&local_2e8,1);
                  uStack_244 = local_10c;
                  if (iVar33 == 0) {
                    local_e8 = &local_304;
                    local_e0 = &local_2fc;
                    local_d0 = local_2e4;
                    *(undefined4 *)((int)local_2ec + 0x1c) = 0;
                    local_ec = &local_308;
                    local_e4 = &local_300;
                    local_dc = &local_2f8;
                    local_d4 = &local_2f0;
                    local_c8 = local_11c << 0x10;
                    local_cc = local_120 << 0x10;
                    pdVar54 = (dword *)((int)local_2ec + 0x20);
                    pdVar31 = (dword *)((int)local_2ec + 0x38);
                    pdVar24 = (dword *)((int)local_2ec + 0x24);
                    local_d8 = &local_2f4;
                    pdVar26 = (dword *)((int)local_2ec + 0x2c);
                    pdVar40 = (dword *)((int)local_2ec + 0x28);
                    local_f4 = local_120 - local_11c;
                    pdVar29 = (dword *)((int)local_2ec + 0x30);
                    pdVar36 = (dword *)((int)local_2ec + 0x34);
                    *(int *)(param_1 + 0x7c) = (int)local_2ec + 0x1c;
                    *(float *)(param_1 + 0x18) = local_2ec;
                    uVar42 = uVar39;
                    local_124 = uVar43;
                  }
                  else {
                    local_d0 = local_2e4;
                    local_e0 = &local_2fc;
                    local_e8 = &local_304;
                    local_ec = &local_308;
                    pdVar54 = (dword *)0x0;
                    local_e4 = &local_300;
                    local_dc = &local_2f8;
                    pdVar24 = &__mh_bundle_header.cputype;
                    local_cc = local_120 << 0x10;
                    local_d4 = &local_2f0;
                    pdVar40 = &__mh_bundle_header.cpusubtype;
                    pdVar26 = &__mh_bundle_header.filetype;
                    pdVar29 = &__mh_bundle_header.ncmds;
                    pdVar36 = &__mh_bundle_header.sizeofcmds;
                    pdVar31 = &__mh_bundle_header.flags;
                    local_c8 = local_11c << 0x10;
                    local_d8 = &local_2f4;
                    local_f4 = local_120 - local_11c;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    uVar42 = uVar39;
                    local_124 = uVar43;
                  }
                }
                else {
                  local_d0 = local_2e4;
                  local_e0 = &local_2fc;
                  local_e8 = &local_304;
                  local_ec = &local_308;
                  pdVar24 = pdVar54 + 1;
                  pdVar40 = pdVar54 + 2;
                  local_e4 = &local_300;
                  pdVar26 = pdVar54 + 3;
                  local_dc = &local_2f8;
                  pdVar29 = pdVar54 + 4;
                  local_cc = local_120 << 0x10;
                  local_d4 = &local_2f0;
                  pdVar36 = pdVar54 + 5;
                  pdVar31 = pdVar54 + 6;
                  local_c8 = local_11c << 0x10;
                  local_d8 = &local_2f4;
                  local_f4 = local_120 - local_11c;
                  uStack_244 = local_10c;
                  local_124 = uVar43;
                }
                do {
                  puVar34 = *(uint **)(param_1 + 0x7c);
                  *puVar34 = (int)pdVar54 - (int)puVar34 >> 2 | *puVar34;
                  *(dword **)(param_1 + 0x7c) = pdVar54;
                  *pdVar54 = 0xa000000;
                  *pdVar24 = *(dword *)(param_1 + 0x84);
                  puVar34 = *(uint **)(param_1 + 0x7c);
                  *puVar34 = (int)pdVar40 - (int)puVar34 >> 2 | *puVar34;
                  *(dword **)(param_1 + 0x7c) = pdVar40;
                  *pdVar40 = 0x10000000;
                  *pdVar26 = *(dword *)*DAT_0000e6e4;
                  *pdVar29 = DAT_0000e6e4[7];
                  if (DAT_0000e6c0 == 0x10) {
                    *pdVar36 = 3;
                  }
                  else {
                    *pdVar36 = 6;
                  }
                  puVar34 = *(uint **)(param_1 + 0x7c);
                  *puVar34 = (int)pdVar31 - (int)puVar34 >> 2 | *puVar34;
                  *(dword **)(param_1 + 0x7c) = pdVar31;
                  *pdVar31 = 0x13000000;
                  pdVar31[1] = *(undefined4 *)**(undefined4 **)(local_f0 + 0x64c4);
                  pdVar31[2] = 0;
                  pdVar54 = pdVar31 + 4;
                  pdVar31[3] = 0;
                  iVar21 = *(int *)(param_1 + 0x70);
                  uVar42 = uVar42 - 10;
                  *pdVar54 = 0x850;
                  pdVar31[5] = 0x100;
                  pdVar31[6] = 0x887;
                  pdVar31[7] = 0x1c000;
                  pdVar31[8] = 0x82c;
                  pdVar31[9] = 0;
                  pdVar31[10] = 0x1002;
                  pdVar31[0xb] = 0;
                  pdVar31[0xc] = 0x824;
                  pdVar31[0xd] = 1;
                  pdVar31[0xe] = 0x825;
                  pdVar31[0xf] = 0x12;
                  pdVar31[0x10] = 0x82d;
                  pdVar31[0x11] = 5;
                  pdVar31[0x12] = 0x854;
                  pdVar31[0x13] = 0x6010006;
                  pdVar31[0x14] = 0x855;
                  pdVar31[0x15] = 0x2701;
                  pdVar31[0x16] = 0x878;
                  pdVar31[0x17] = 0xf688f688;
                  pdVar31[0x18] = 0x879;
                  pdVar31[0x19] = 0xfb24f688;
                  pdVar31[0x1a] = 0x10a2;
                  pdVar31[0x1b] = 0;
                  pdVar31[0x1c] = 0x1381;
                  pdVar31[0x1d] = 0;
                  pdVar31[0x1e] = 0x109e;
                  pdVar31[0x1f] = 5;
                  pdVar31[0x20] = 0x1383;
                  pdVar31[0x21] = 0xf;
                  pdVar31[0x22] = 0x1004;
                  pdVar31[0x23] = 0x66666666;
                  pdVar31[0x24] = 0x1005;
                  pdVar31[0x25] = 0x66666666;
                  pdVar31[0x26] = 0x10ae;
                  pdVar31[0x27] = 0;
                  pdVar31[0x28] = 0x10ea;
                  pdVar31[0x29] = 0x2da49525;
                  pdVar31[0x2a] = 0x10fa;
                  pdVar31[0x2b] = 0xffffff;
                  pdVar31[0x2c] = 0x10f4;
                  pdVar31[0x2d] = 0xffff;
                  pdVar31[0x2e] = 0x10f8;
                  pdVar31[0x2f] = 0;
                  pdVar31[0x30] = 0x10f9;
                  pdVar31[0x31] =
                       *(uint *)(param_1 + 0x54) & 0x1fff |
                       (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
                  pdVar31[0x32] = 0x13c0;
                  pdVar31[0x33] = 0;
                  pdVar31[0x34] = 0x13c1;
                  pdVar31[0x35] = 0;
                  pdVar31[0x36] = 0x10c0;
                  pdVar31[0x37] = 0x40004;
                  pdVar31[0x38] = 0x10c1;
                  pdVar31[0x39] = 1;
                  pdVar31[0x3a] = 0x10c8;
                  pdVar31[0x3b] = 0x10;
                  pdVar31[0x3c] = 0x10c9;
                  pdVar31[0x3d] = 0x31;
                  pdVar31[0x3e] = 0x101d;
                  pdVar31[0x3f] = 0x28ffe040;
                  pdVar31[0x40] = 0x101e;
                  pdVar31[0x41] = 0x28ffe0c2;
                  pdVar31[0x42] = 0x1041;
                  pdVar31[0x43] = 3;
                  pdVar31[0x44] = 0x1040;
                  pdVar31[0x45] = 0;
                  pdVar31[0x46] = 0x1100;
                  pdVar31[0x47] = 0x2a92;
                  pdVar31[0x48] = 0x1101;
                  pdVar31[0x49] = 0x10002a92;
                  pdVar31[0x4a] = 0x1120;
                  local_f8 = *(short *)(param_1 + 0x50);
                  local_f6 = *(short *)(param_1 + 0x52);
                  pdVar31[0x4b] =
                       (int)local_f8 - 1U & 0x7ff | (local_f6 + -1) * 0x800 & 0x3ff800U | 0x80000000
                  ;
                  pdVar31[0x4c] = 0x1121;
                  uVar27 = (int)*(short *)(local_108 + 4) - 1;
                  iVar35 = *(short *)(local_108 + 6) + -1;
                  pdVar31[0x4d] = uVar27 & 0x7ff | iVar35 * 0x800 & 0x3ff800U | 0x80000000;
                  pdVar31[0x4e] = 0x1130;
                  iVar33 = 0x5300c - (uint)(iVar21 == 3);
                  pdVar31[0x4f] = iVar33;
                  pdVar31[0x50] = 0x1131;
                  pdVar31[0x51] = iVar33;
                  pdVar31[0x52] = 0x1140;
                  pdVar31[0x53] =
                       *(int *)(param_1 + 0x5c) - 1U & 0x3fff | ((int)local_f8 - 1U) * 0x10 & 0x8000
                       | (local_f6 + -1) * 0x20 & 0x10000U;
                  pdVar31[0x54] = 0x1141;
                  pdVar31[0x55] =
                       *(int *)(local_108 + 0x10) - 1U & 0x3fff | uVar27 * 0x10 & 0x8000 |
                       iVar35 * 0x20 & 0x10000U;
                  if (bVar8) {
                    iVar41 = 0x52;
                    iVar23 = 0x148;
                    local_164 = 0x56;
                    local_168 = 0x57;
                    local_16c = 0x58;
                    local_170 = 0x59;
                    local_174 = 0x5a;
                    local_178 = 0x5b;
                    local_17c = 0x5c;
                    local_180 = 0x5d;
                    iVar60 = 0x5f;
                    local_184 = 0x5e;
                    iVar44 = 0x53;
                    iVar46 = 0x54;
                    iVar61 = 0x60;
                    iVar49 = 0x55;
                    iVar59 = 0x61;
                    iVar50 = 0x62;
                    iVar51 = 99;
                    iVar53 = 100;
                    iVar55 = 0x65;
                    iVar56 = 0x66;
                    iVar19 = 0x67;
                    iVar57 = 0x68;
                    iVar33 = 0x69;
                    iVar35 = 0x6a;
                    iVar22 = 0x6b;
                    iVar21 = 0x6c;
                  }
                  else {
                    if (iVar21 == 3) {
                      uStack_284 = uVar52 >> 5 & 0x1f;
                      uStack_27c = uVar52 & 0x1f;
                      uStack_294 = uVar52 >> 0xf & 1;
                      local_288 = 0x43300000;
                      local_280 = 0x43300000;
                      local_298 = 0x43300000;
                      local_128 = (float)dVar62 / FLOAT_0000cff8;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_284) - dVar10) /
                                  FLOAT_0000cff8;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_27c) - dVar10) /
                                  FLOAT_0000cff8;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_294) - dVar10);
                    }
                    else {
                      uStack_274 = uVar52 >> 0x18;
                      uStack_26c = uVar52 >> 0x10 & 0xff;
                      uStack_25c = uVar52 & 0xff;
                      uStack_264 = uVar52 >> 8 & 0xff;
                      local_278 = 0x43300000;
                      local_270 = 0x43300000;
                      local_268 = 0x43300000;
                      local_260 = 0x43300000;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_274) - dVar10) /
                                  FLOAT_0000cffc;
                      local_128 = (float)((double)CONCAT44(0x43300000,uStack_26c) - dVar10) /
                                  FLOAT_0000cffc;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_25c) - dVar10) /
                                  FLOAT_0000cffc;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_264) - dVar10) /
                                  FLOAT_0000cffc;
                    }
                    pdVar31[0x56] = 0x1094;
                    pdVar31[0x57] = 0x10000;
                    pdVar31[0x58] = 0x1095;
                    pdVar31[0x59] = (dword)local_128;
                    pdVar31[0x5a] = 0x1095;
                    pdVar31[0x5b] = (dword)local_12c;
                    pdVar31[0x5c] = 0x1095;
                    pdVar31[0x5d] = (dword)local_130;
                    pdVar31[0x5e] = 0x1095;
                    pdVar31[0x5f] = (dword)local_134;
                    iVar41 = 0x5c;
                    iVar23 = 0x170;
                    local_164 = 0x60;
                    local_168 = 0x61;
                    local_16c = 0x62;
                    local_170 = 99;
                    local_174 = 100;
                    local_178 = 0x65;
                    local_17c = 0x66;
                    local_180 = 0x67;
                    iVar60 = 0x69;
                    local_184 = 0x68;
                    iVar44 = 0x5d;
                    iVar46 = 0x5e;
                    iVar61 = 0x6a;
                    iVar49 = 0x5f;
                    iVar59 = 0x6b;
                    iVar50 = 0x6c;
                    iVar51 = 0x6d;
                    iVar53 = 0x6e;
                    iVar55 = 0x6f;
                    iVar56 = 0x70;
                    iVar19 = 0x71;
                    iVar57 = 0x72;
                    iVar33 = 0x73;
                    iVar35 = 0x74;
                    iVar22 = 0x75;
                    iVar21 = 0x76;
                  }
                  *(undefined4 *)((int)pdVar54 + iVar23) = 0x1094;
                  pdVar54[iVar44] = 0;
                  pdVar54[iVar46] = 0x1095;
                  pdVar54[iVar49] = 0x7803;
                  pdVar54[local_164] = 0x1095;
                  pdVar54[local_168] = 0x2410000;
                  pdVar54[local_16c] = 0x1095;
                  pdVar54[local_170] = 0x3901e401;
                  pdVar54[local_174] = 0x1095;
                  pdVar54[local_178] = 0;
                  pdVar54[local_17c] = 0x1095;
                  pdVar54[local_180] = 0;
                  pdVar54[local_184] = 0x1095;
                  pdVar54[iVar60] = 0;
                  if (bVar8) {
                    pdVar54[iVar61] = 0x1095;
                    pdVar54[iVar59] = 0x78105;
                    pdVar54[iVar50] = 0x1095;
                    pdVar54[iVar51] = 1;
                    pdVar54[iVar53] = 0x1095;
                    pdVar54[iVar55] = 1;
                    pdVar54[iVar56] = 0x1095;
                    pdVar54[iVar19] = 0xdb0220;
                    pdVar54[iVar57] = 0x1095;
                    pdVar54[iVar33] = 0xc0c006;
                    pdVar54[iVar35] = 0x1095;
                    pdVar54[iVar22] = 0x20490000;
                  }
                  else {
                    pdVar54[iVar61] = 0x1095;
                    pdVar54[iVar59] = 0x7807;
                    pdVar54[iVar50] = 0x1095;
                    pdVar54[iVar51] = 0x2400000;
                    pdVar54[iVar53] = 0x1095;
                    pdVar54[iVar55] = 0x3900e400;
                    pdVar54[iVar56] = 0x1095;
                    pdVar54[iVar19] = 0;
                    pdVar54[iVar57] = 0x1095;
                    pdVar54[iVar33] = 0;
                    pdVar54[iVar35] = 0x1095;
                    pdVar54[iVar22] = 0;
                    pdVar54[iVar21] = 0x1095;
                    pdVar54[iVar41 + 0x1b] = 0x7804;
                    pdVar54[iVar41 + 0x1c] = 0x1095;
                    pdVar54[iVar41 + 0x1d] = 0x40040000;
                    pdVar54[iVar41 + 0x1e] = 0x1095;
                    pdVar54[iVar41 + 0x1f] = 0x40040000;
                    pdVar54[iVar41 + 0x20] = 0x1095;
                    pdVar54[iVar41 + 0x21] = 0xdb0490;
                    pdVar54[iVar41 + 0x22] = 0x1095;
                    pdVar54[iVar41 + 0x23] = 0xc10026;
                    pdVar54[iVar41 + 0x24] = 0x1095;
                    pdVar54[iVar41 + 0x25] = 0xdfa23028;
                    pdVar54[iVar41 + 0x26] = 0x1095;
                    pdVar54[iVar41 + 0x27] = 0x7800;
                    pdVar54[iVar41 + 0x28] = 0x1095;
                    pdVar54[iVar41 + 0x29] = 2;
                    pdVar54[iVar41 + 0x2a] = 0x1095;
                    pdVar54[iVar41 + 0x2b] = 2;
                    pdVar54[iVar41 + 0x2c] = 0x1095;
                    pdVar54[iVar41 + 0x2d] = 0xdb0220;
                    pdVar54[iVar41 + 0x2e] = 0x1095;
                    pdVar54[iVar41 + 0x2f] = 0xc0c021;
                    pdVar54[iVar41 + 0x30] = 0x1095;
                    pdVar54[iVar41 + 0x31] = 0x22;
                    pdVar54[iVar41 + 0x32] = 0x1095;
                    pdVar54[iVar41 + 0x33] = 0x78101;
                    pdVar54[iVar41 + 0x34] = 0x1095;
                    uVar27 = (local_c4 ^ 1) << 10 | local_c4 | 0x200000;
                    pdVar54[iVar41 + 0x35] = uVar27;
                    pdVar54[iVar41 + 0x36] = 0x1095;
                    pdVar54[iVar41 + 0x37] = uVar27;
                    pdVar54[iVar41 + 0x38] = 0x1095;
                    pdVar54[iVar41 + 0x39] = 0x440221;
                    pdVar54[iVar41 + 0x3a] = 0x1095;
                    pdVar54[iVar41 + 0x3b] = 0x60d006;
                    pdVar54[iVar41 + 0x3c] = 0x1095;
                    iVar21 = iVar41 + 0x3e;
                    pdVar54[iVar41 + 0x3d] = 0xdda22008;
                  }
                  pdVar54[iVar21] = 0x1189;
                  pdVar54[iVar21 + 1] = 0;
                  pdVar54[iVar21 + 2] = 0x1181;
                  pdVar54[iVar21 + 3] = 5;
                  pdVar54[iVar21 + 4] = 0x118d;
                  if (bVar8) {
                    dVar20 = 0x10000;
                  }
                  else {
                    dVar20 = 0x40000;
                  }
                  pdVar54[iVar21 + 5] = dVar20;
                  pdVar54[iVar21 + 6] = 0x118e;
                  pdVar54[iVar21 + 7] = 0;
                  pdVar54[iVar21 + 8] = 0x118c;
                  if (bVar8) {
                    dVar20 = 0x10000;
                  }
                  else {
                    dVar20 = 0x40000;
                  }
                  pdVar54[iVar21 + 9] = dVar20;
                  pdVar54[iVar21 + 10] = 0x11a9;
                  pdVar54[iVar21 + 0xb] = 0x1b01;
                  pdVar54[iVar21 + 0xc] = 0x11aa;
                  pdVar54[iVar21 + 0xd] = 0xf;
                  pdVar54[iVar21 + 0xe] = 0x11ab;
                  pdVar54[iVar21 + 0xf] = 0xf;
                  pdVar54[iVar21 + 0x10] = 0x11ac;
                  pdVar54[iVar21 + 0x11] = 0xf;
                  pdVar54[iVar21 + 0x12] = 0x12f0;
                  pdVar54[iVar21 + 0x13] = 0;
                  pdVar54[iVar21 + 0x14] = 0x12f5;
                  pdVar54[iVar21 + 0x15] = 0;
                  local_13c = iVar21 + 0x17;
                  local_140 = iVar21 + 0x18;
                  iVar35 = iVar21 + 0x30;
                  local_258 = 0x43300000;
                  local_250 = 0x43300000;
                  iVar23 = iVar21 + 0x1a;
                  iVar46 = iVar21 + 0x19;
                  uStack_254 = local_11c;
                  uStack_24c = local_120;
                  local_14c = iVar21 + 0x1e;
                  local_150 = iVar21 + 0x1f;
                  local_144 = iVar21 + 0x1b;
                  local_15c = iVar21 + 0x22;
                  local_160 = iVar21 + 0x24;
                  local_138 = (iVar21 + 0x16) * 4;
                  local_148 = iVar21 + 0x1d;
                  local_154 = iVar21 + 0x20;
                  iVar22 = iVar21 + 0x1c;
                  local_158 = iVar21 + 0x21;
                  iVar44 = iVar21 + 0x25;
                  iVar33 = iVar21 + 0x26;
                  iVar41 = iVar21 + 0x23;
                  iVar57 = iVar21 + 0x27;
                  iVar49 = iVar21 + 0x28;
                  iVar50 = iVar21 + 0x29;
                  iVar51 = iVar21 + 0x2a;
                  iVar53 = iVar21 + 0x2b;
                  iVar55 = iVar21 + 0x2c;
                  iVar56 = iVar21 + 0x2d;
                  iVar19 = iVar21 + 0x2e;
                  iVar21 = iVar21 + 0x2f;
                  fVar3 = (float)((double)CONCAT44(0x43300000,local_11c) - dVar10);
                  fVar4 = (float)((double)CONCAT44(0x43300000,local_120) - dVar10);
                  while( true ) {
                    fVar28 = FLOAT_0000d008;
                    fVar25 = FLOAT_0000d000;
                    dVar12 = DOUBLE_0000cfe0;
                    uStack_23c = local_124;
                    local_238 = 0x43300000;
                    local_228 = 0x43300000;
                    local_248 = 0x43300000;
                    local_240 = 0x43300000;
                    uStack_234 = (int)local_f8 ^ 0x80000000;
                    uStack_224 = (int)local_f6 ^ 0x80000000;
                    local_304 = FLOAT_0000d000 /
                                (float)((double)CONCAT44(0x43300000,uStack_234) - DOUBLE_0000cfe0);
                    local_300 = FLOAT_0000d000 /
                                (float)((double)CONCAT44(0x43300000,uStack_224) - DOUBLE_0000cfe0);
                    local_308 = local_304 *
                                (float)((double)CONCAT44(0x43300000,uStack_244) - dVar10);
                    local_304 = local_304 * (float)((double)CONCAT44(0x43300000,local_124) - dVar10)
                    ;
                    local_2fc = local_300 * fVar4;
                    local_300 = local_300 * fVar3;
                    *(undefined4 *)((int)pdVar54 + local_138) = 0xc0143500;
                    pdVar54[local_13c] = 0x4003d;
                    iVar59 = local_124 - uStack_244;
                    if ((iVar59 == 8) && (local_f4 == 8)) {
                      local_1e8 = 0x43300000;
                      uStack_1e4 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f8 = (fVar1 + fVar28) *
                                  (fVar25 / (float)((double)CONCAT44(0x43300000,uStack_1e4) - dVar12
                                                   ));
                      local_1e0 = 0x43300000;
                      uStack_1dc = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f4 = (fVar1 + fVar15) *
                                  (fVar25 / (float)((double)CONCAT44(0x43300000,uStack_1dc) - dVar12
                                                   ));
                      local_1d8 = 0x43300000;
                      uStack_1d4 = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2f0 = (fVar2 + fVar28) *
                                  (fVar25 / (float)((double)CONCAT44(0x43300000,uStack_1d4) - dVar12
                                                   ));
                      local_1d0 = 0x43300000;
                      uStack_1cc = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2e4[0] = fVar6 * (fVar25 / (float)((double)CONCAT44(0x43300000,
                                                                                uStack_1cc) - dVar12
                                                              ));
                    }
                    else {
                      local_218 = 0x43300000;
                      local_210 = 0x43300000;
                      uStack_214 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f8 = (fVar1 + fVar14) *
                                  (fVar18 / (float)((double)CONCAT44(0x43300000,uStack_214) - dVar11
                                                   ));
                      local_208 = 0x43300000;
                      uStack_204 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f4 = (fVar1 + (float)((double)CONCAT44(0x43300000,iVar59) - dVar10)) *
                                  (fVar18 / (float)((double)CONCAT44(0x43300000,uStack_204) - dVar11
                                                   ));
                      local_200 = 0x43300000;
                      iStack_1f4 = local_f4;
                      local_1f8 = 0x43300000;
                      uStack_1fc = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2f0 = fVar5 * (fVar18 / (float)((double)CONCAT44(0x43300000,uStack_1fc)
                                                           - dVar11));
                      local_1f0 = 0x43300000;
                      uStack_1ec = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2e4[0] = (fVar2 + (float)((double)CONCAT44(0x43300000,local_f4) - dVar10
                                                     )) *
                                     (fVar18 / (float)((double)CONCAT44(0x43300000,uStack_1ec) -
                                                      dVar11));
                      iStack_20c = iVar59;
                    }
                    pdVar54[local_140] = uStack_244 | local_cc;
                    fVar37 = *local_ec;
                    pdVar54[iVar46] = (dword)fVar37;
                    fVar28 = *local_e0;
                    pdVar54[iVar23] = (dword)fVar28;
                    fVar32 = *local_dc;
                    pdVar54[local_144] = (dword)fVar32;
                    fVar25 = *local_d0;
                    pdVar54[iVar22] = (dword)fVar25;
                    pdVar54[local_148] = uStack_244 | local_c8;
                    pdVar54[local_14c] = (dword)fVar37;
                    fVar38 = *local_e4;
                    pdVar54[local_150] = (dword)fVar38;
                    pdVar54[local_154] = (dword)fVar32;
                    fVar37 = *local_d4;
                    pdVar54[local_158] = (dword)fVar37;
                    pdVar54[local_15c] = local_124 | local_c8;
                    fVar32 = *local_e8;
                    pdVar54[iVar41] = (dword)fVar32;
                    pdVar54[local_160] = (dword)fVar38;
                    fVar38 = *local_d8;
                    pdVar54[iVar44] = (dword)fVar38;
                    pdVar54[iVar33] = (dword)fVar37;
                    pdVar54[iVar57] = local_124 | local_cc;
                    pdVar54[iVar49] = (dword)fVar32;
                    pdVar54[iVar50] = (dword)fVar28;
                    pdVar54[iVar51] = (dword)fVar38;
                    pdVar54[iVar53] = (dword)fVar25;
                    pdVar54[iVar55] = 0x1393;
                    pdVar54[iVar56] = 10;
                    pdVar54[iVar19] = 0x5c8;
                    pdVar54[iVar21] = 0x20000;
                    uVar42 = uVar42 - iVar35;
                    pdVar54 = pdVar54 + iVar35;
                    local_124 = local_110;
                    if (uStack_244 + 0x10 < local_110) {
                      local_124 = uStack_244 + 0x10;
                    }
                    bVar7 = false;
                    if (local_110 <= uVar45) goto LAB_0000a09c;
                    uVar27 = uVar45 + 8;
                    uVar47 = uVar45;
LAB_00008bec:
                    if (uVar42 < 0x1a) break;
                    local_f8 = *(short *)(param_1 + 0x50);
                    iVar33 = 0x10;
                    iVar35 = 0x1a;
                    iVar44 = 0xf;
                    iVar21 = 0x19;
                    iVar19 = 0x18;
                    iVar56 = 0x17;
                    iVar55 = 0x16;
                    iVar53 = 0x15;
                    iVar51 = 0x14;
                    iVar50 = 0x13;
                    iVar49 = 0x12;
                    iVar57 = 0x11;
                    iVar41 = 0xd;
                    iVar22 = 6;
                    iVar23 = 4;
                    local_f6 = *(short *)(param_1 + 0x52);
                    local_160 = 0xe;
                    local_15c = 0xc;
                    local_154 = 10;
                    local_150 = 9;
                    local_14c = 8;
                    local_148 = 7;
                    local_158 = 0xb;
                    local_140 = 2;
                    iVar46 = 3;
                    local_144 = 5;
                    local_13c = 1;
                    local_138 = 0;
                    uVar45 = uVar27;
                    uStack_244 = uVar47;
                  }
                  local_2e8 = *(float *)(param_1 + 0x18);
                  local_2ec = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar54 = 0x5c8;
                    local_2ec = 2.8026e-45;
                    pdVar54[1] = 0xc000;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar54[(int)local_2ec] = 0x1000000;
                  puVar16 = PTR_0000e694;
                  puVar34 = *(uint **)(param_1 + 0x7c);
                  *puVar34 = ((int)pdVar54 - (int)puVar34 >> 2) + (int)local_2ec | *puVar34;
                  iVar33 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar16,&local_2e8,&local_2ec,1);
                  if (iVar33 == 0) {
                    *(undefined4 *)((int)local_2e8 + 0x1c) = 0;
                    *(float *)(param_1 + 0x18) = local_2e8;
                    pdVar54 = (dword *)((int)local_2e8 + 0x20);
                    pdVar31 = (dword *)((int)local_2e8 + 0x38);
                    *(int *)(param_1 + 0x7c) = (int)local_2e8 + 0x1c;
                    pdVar24 = (dword *)((int)local_2e8 + 0x24);
                    pdVar40 = (dword *)((int)local_2e8 + 0x28);
                    pdVar26 = (dword *)((int)local_2e8 + 0x2c);
                    pdVar29 = (dword *)((int)local_2e8 + 0x30);
                    pdVar36 = (dword *)((int)local_2e8 + 0x34);
                    uVar45 = uVar47 + 8;
                    uStack_244 = uVar47;
                    uVar42 = uVar39;
                  }
                  else {
                    pdVar31 = &__mh_bundle_header.flags;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar36 = &__mh_bundle_header.sizeofcmds;
                    pdVar29 = &__mh_bundle_header.ncmds;
                    pdVar26 = &__mh_bundle_header.filetype;
                    pdVar40 = &__mh_bundle_header.cpusubtype;
                    pdVar24 = &__mh_bundle_header.cputype;
                    pdVar54 = (dword *)0x0;
                    uVar45 = uVar47 + 8;
                    uStack_244 = uVar47;
                    uVar42 = uVar39;
                  }
                } while( true );
              }
LAB_0000a09c:
              local_120 = local_118;
              if (local_11c + 0x10 < local_118) {
                local_120 = local_11c + 0x10;
              }
              uVar27 = local_11c + 8;
            } while (local_11c + 8 < local_118);
          }
          if (uVar42 < 0x86) {
            local_2ec = *(float *)(param_1 + 0x18);
            local_2e8 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar54 = 0x5c8;
              local_2e8 = 2.8026e-45;
              pdVar54[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar54[(int)local_2e8] = 0x1000000;
            puVar34 = *(uint **)(param_1 + 0x7c);
            *puVar34 = ((int)pdVar54 - (int)puVar34 >> 2) + (int)local_2e8 | *puVar34;
            iVar33 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&local_2ec,&local_2e8,1);
            if (iVar33 == 0) {
              *(undefined4 *)((int)local_2ec + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_2ec;
              pdVar54 = (dword *)((int)local_2ec + 0x20);
              pdVar40 = (dword *)((int)local_2ec + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_2ec + 0x1c;
              pdVar24 = (dword *)((int)local_2ec + 0x24);
              pdVar26 = (dword *)((int)local_2ec + 0x28);
              pdVar29 = (dword *)((int)local_2ec + 0x2c);
              pdVar36 = (dword *)((int)local_2ec + 0x30);
              pdVar31 = (dword *)((int)local_2ec + 0x34);
              uVar42 = uVar39;
            }
            else {
              pdVar54 = (dword *)0x0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar24 = &__mh_bundle_header.cputype;
              pdVar26 = &__mh_bundle_header.cpusubtype;
              pdVar29 = &__mh_bundle_header.filetype;
              pdVar36 = &__mh_bundle_header.ncmds;
              pdVar31 = &__mh_bundle_header.sizeofcmds;
              pdVar40 = &__mh_bundle_header.flags;
              uVar42 = uVar39;
            }
          }
          else {
            pdVar24 = pdVar54 + 1;
            pdVar26 = pdVar54 + 2;
            pdVar29 = pdVar54 + 3;
            pdVar36 = pdVar54 + 4;
            pdVar31 = pdVar54 + 5;
            pdVar40 = pdVar54 + 6;
          }
          puVar34 = *(uint **)(param_1 + 0x7c);
          *puVar34 = (int)pdVar54 - (int)puVar34 >> 2 | *puVar34;
          *(dword **)(param_1 + 0x7c) = pdVar54;
          *pdVar54 = 0x11000000;
          *pdVar24 = *(dword *)(param_1 + 0x84);
          *pdVar26 = 0;
          *pdVar29 = 0;
          puVar34 = *(uint **)(param_1 + 0x7c);
          *puVar34 = (int)pdVar36 - (int)puVar34 >> 2 | *puVar34;
          *(dword **)(param_1 + 0x7c) = pdVar36;
          *pdVar36 = 0x4000000;
          *pdVar31 = *(dword *)*DAT_0000e6e4;
          puVar17 = DAT_0000e6e4;
          iVar33 = DAT_0000e6e4[0xc];
          if (iVar33 == 3) {
            iVar33 = 0xb;
          }
          else if (iVar33 == 6) {
            iVar33 = 0xc;
          }
          iVar33 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar40,DAT_0000e6e4 + 3,iVar33,0,0,0,0);
          uStack_1c4 = local_10c;
          uStack_1b4 = local_114;
          uStack_1bc = local_110;
          uStack_1ac = local_118;
          local_1c8 = 0x43300000;
          local_1c0 = 0x43300000;
          local_1b8 = 0x43300000;
          local_1b0 = 0x43300000;
          pdVar40[iVar33] = 0xc00c3500;
          pdVar40[iVar33 + 1] = 0x4003d;
          local_1a8 = 0x43300000;
          uStack_1a4 = (int)*(short *)(puVar17 + 4) ^ 0x80000000;
          local_2fc = (float)((double)(float)((double)CONCAT44(0x43300000,local_10c) - dVar9) *
                             (dVar13 / ((double)CONCAT44(0x43300000,uStack_1a4) - dVar11)));
          local_1a0 = 0x43300000;
          uStack_19c = (int)*(short *)(puVar17 + 4) ^ 0x80000000;
          local_2e4[0] = (float)((double)(float)((double)CONCAT44(0x43300000,local_110) - dVar9) *
                                (dVar13 / ((double)CONCAT44(0x43300000,uStack_19c) - dVar11)));
          local_198 = 0x43300000;
          uStack_194 = (int)*(short *)((int)puVar17 + 0x12) ^ 0x80000000;
          local_2e8 = (float)((double)(float)((double)CONCAT44(0x43300000,local_114) - dVar9) *
                             (dVar13 / ((double)CONCAT44(0x43300000,uStack_194) - dVar11)));
          local_190 = 0x43300000;
          uStack_18c = (int)*(short *)((int)puVar17 + 0x12) ^ 0x80000000;
          local_2ec = (float)((double)(float)((double)CONCAT44(0x43300000,local_118) - dVar9) *
                             (dVar13 / ((double)CONCAT44(0x43300000,uStack_18c) - dVar11)));
          pdVar40[iVar33 + 2] = local_10c | local_118 << 0x10;
          pdVar40[iVar33 + 3] = (dword)local_2fc;
          pdVar40[iVar33 + 4] = (dword)local_2ec;
          pdVar40[iVar33 + 5] = local_10c | local_114 << 0x10;
          pdVar40[iVar33 + 6] = (dword)local_2fc;
          pdVar40[iVar33 + 7] = (dword)local_2e8;
          pdVar40[iVar33 + 8] = local_110 | local_114 << 0x10;
          pdVar40[iVar33 + 9] = (dword)local_2e4[0];
          pdVar40[iVar33 + 10] = (dword)local_2e8;
          pdVar40[iVar33 + 0xb] = local_110 | local_118 << 0x10;
          pdVar40[iVar33 + 0xc] = (dword)local_2e4[0];
          pdVar40[iVar33 + 0xd] = (dword)local_2ec;
          pdVar40[iVar33 + 0xe] = 0x1393;
          pdVar40[iVar33 + 0xf] = 10;
          pdVar40[iVar33 + 0x10] = 0x5c8;
          pdVar40[iVar33 + 0x11] = 0x20000;
          uVar42 = (uVar42 - 6) - (iVar33 + 0x12);
          puVar58 = puVar58 + 4;
          pdVar54 = pdVar40 + iVar33 + 0x12;
          local_104 = local_104 + 1;
        } while (local_104 < (uint)param_5[0x16]);
      }
      *(dword **)(param_1 + 0x80) = pdVar54;
      return 0;
    }
  }
  else {
    puVar58 = *(undefined4 **)(param_1 + 0x80);
    iVar33 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
    local_fc = iVar33 - 7;
    if (puVar58 != (undefined4 *)0x0) {
      uVar39 = param_5[0x16];
      uVar42 = local_fc - ((int)puVar58 - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
      local_100 = (iVar33 - 0x75U) / 0xc - 1;
      if (uVar39 != 0) {
        local_c0 = &local_300;
        local_188 = local_100 * 0xc + 0x6e;
        uVar52 = 0;
        do {
          if (uVar42 < local_188) {
            local_2fc = *(float *)(param_1 + 0x18);
            local_2e4[0] = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *puVar58 = 0x5c8;
              local_2e4[0] = 2.8026e-45;
              puVar58[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar58[(int)local_2e4[0]] = 0x1000000;
            puVar34 = *(uint **)(param_1 + 0x7c);
            *puVar34 = ((int)puVar58 - (int)puVar34 >> 2) + (int)local_2e4[0] | *puVar34;
            iVar33 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&local_2fc,local_2e4,1);
            uVar42 = local_fc;
            if (iVar33 == 0) {
              *(undefined4 *)((int)local_2fc + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_2fc;
              puVar58 = (undefined4 *)((int)local_2fc + 0x20);
              *(int *)(param_1 + 0x7c) = (int)local_2fc + 0x1c;
              uVar39 = param_5[0x16];
            }
            else {
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              puVar58 = (undefined4 *)0x0;
              uVar39 = param_5[0x16];
            }
          }
          uVar43 = uVar52 + local_100;
          if (uVar43 < uVar39) {
            uVar39 = uVar43;
          }
          iVar33 = ((int (*)())_radeon3DFillSetup)(puVar58,0,param_6,param_1);
          iVar35 = uVar39 - uVar52;
          puVar58[iVar33] = iVar35 * 0xc0000 | 0xc0003500;
          iVar21 = iVar33 + 2;
          puVar58[iVar33 + 1] = iVar35 * 0x40000 | 0x3d;
          dVar9 = DOUBLE_0000cfe0;
          if (uVar52 < uVar39) {
            iVar33 = iVar21 * 4;
            iVar44 = *(int *)(param_1 + 0x60);
            iVar46 = *(int *)(param_1 + 100);
            iVar49 = iVar33 + 4;
            iVar50 = iVar33 + 0x28;
            iVar51 = iVar33 + 0x24;
            piVar30 = param_5 + uVar52 * 4 + 0x17;
            iVar53 = iVar33 + 0x20;
            iVar55 = iVar33 + 0x1c;
            iVar56 = iVar33 + 0x18;
            iVar41 = iVar33 + 0x14;
            iVar22 = iVar33 + 0x10;
            iVar23 = iVar33 + 0xc;
            iVar33 = iVar33 + 8;
            do {
              local_2d8 = 0x43300000;
              uStack_2d4 = *piVar30 + iVar44 ^ 0x80000000;
              local_2fc = (float)((double)CONCAT44(0x43300000,uStack_2d4) - dVar9);
              local_2d0 = 0x43300000;
              uStack_2cc = *piVar30 + iVar44 + piVar30[2] ^ 0x80000000;
              local_300 = (float)((double)CONCAT44(0x43300000,uStack_2cc) - dVar9);
              local_2c8 = 0x43300000;
              uStack_2c4 = piVar30[1] + iVar46 ^ 0x80000000;
              local_304 = (float)((double)CONCAT44(0x43300000,uStack_2c4) - dVar9);
              local_2c0 = 0x43300000;
              uStack_2bc = piVar30[1] + iVar46 + piVar30[3] ^ 0x80000000;
              local_308 = (float)((double)CONCAT44(0x43300000,uStack_2bc) - dVar9);
              puVar58[iVar21] = local_2fc;
              *(float *)((int)puVar58 + iVar49) = local_308;
              *(undefined4 *)((int)puVar58 + iVar33) = 0;
              *(float *)((int)puVar58 + iVar23) = local_2fc;
              *(float *)((int)puVar58 + iVar22) = local_304;
              *(undefined4 *)((int)puVar58 + iVar41) = 0;
              fVar18 = *local_c0;
              *(float *)((int)puVar58 + iVar56) = fVar18;
              *(float *)((int)puVar58 + iVar55) = local_304;
              *(undefined4 *)((int)puVar58 + iVar53) = 0;
              *(float *)((int)puVar58 + iVar51) = fVar18;
              *(float *)((int)puVar58 + iVar50) = local_308;
              iVar19 = iVar21 + 0xb;
              iVar49 = iVar49 + 0x30;
              iVar21 = iVar21 + 0xc;
              iVar33 = iVar33 + 0x30;
              iVar23 = iVar23 + 0x30;
              iVar22 = iVar22 + 0x30;
              iVar41 = iVar41 + 0x30;
              iVar56 = iVar56 + 0x30;
              iVar55 = iVar55 + 0x30;
              iVar53 = iVar53 + 0x30;
              iVar51 = iVar51 + 0x30;
              iVar50 = iVar50 + 0x30;
              puVar58[iVar19] = 0;
              piVar30 = piVar30 + 4;
              iVar35 = iVar35 + -1;
            } while (iVar35 != 0);
          }
          puVar58[iVar21] = 0x1393;
          puVar58[iVar21 + 1] = 10;
          puVar58[iVar21 + 2] = 0x5c8;
          puVar58[iVar21 + 3] = 0x20000;
          uVar39 = param_5[0x16];
          uVar42 = uVar42 - (iVar21 + 4);
          puVar58 = puVar58 + iVar21 + 4;
          uVar52 = uVar43;
        } while (uVar43 < uVar39);
      }
      *(undefined4 **)(param_1 + 0x80) = puVar58;
      return 0;
    }
  }
  return 0xe00002be;
}

/* _radeonHighlight @ 0xa5a0 (5300 bytes) */
int _radeonHighlight(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  uint *param_5;
  uint param_6;
{
  short sVar1;
  short sVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  uint *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  dword *pdVar12;
  dword *pdVar13;
  dword *pdVar14;
  dword *pdVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  dword *pdVar19;
  dword *pdVar20;
  float fVar21;
  float fVar22;
  undefined4 *puVar23;
  uint uVar24;
  uint *puVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  dword *pdVar33;
  int iVar34;
  double dVar35;
  double dVar36;
  uint *puStack00000028;
  uint uStack0000002c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec [2];
  uint uStack_1e4;
  undefined4 local_1e0;
  uint uStack_1dc;
  undefined4 local_1d8;
  uint uStack_1d4;
  undefined4 local_1d0;
  uint uStack_1cc;
  undefined4 local_1c8;
  uint uStack_1c4;
  undefined4 local_1c0;
  uint uStack_1bc;
  undefined4 local_1b8;
  uint uStack_1b4;
  undefined4 local_1b0;
  uint uStack_1ac;
  undefined4 local_1a8;
  uint uStack_1a4;
  undefined4 local_1a0;
  uint uStack_19c;
  undefined4 local_198;
  uint uStack_194;
  undefined4 local_190;
  uint uStack_18c;
  undefined4 local_188;
  uint uStack_184;
  undefined4 local_180;
  uint uStack_17c;
  undefined4 local_178;
  uint uStack_174;
  undefined4 local_170;
  uint uStack_16c;
  undefined4 local_168;
  uint uStack_164;
  undefined4 local_160;
  uint uStack_15c;
  undefined4 local_158;
  uint uStack_154;
  undefined4 local_150;
  uint uStack_14c;
  undefined4 local_148;
  uint uStack_144;
  undefined4 local_138;
  uint uStack_134;
  undefined4 local_128;
  uint uStack_124;
  undefined4 local_120;
  uint uStack_11c;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  undefined4 local_108;
  uint uStack_104;
  undefined4 local_100;
  uint uStack_fc;
  undefined4 local_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint uStack_ec;
  float *local_e8;
  float *local_e4;
  float *local_e0;
  float *local_dc;
  float *local_d8;
  float *local_d4;
  uint local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  float *local_b0;
  float *local_ac;
  float local_a0;
  
  pdVar33 = *(dword **)(param_1 + 0x80);
  iVar34 = *(int *)(param_1 + 0x18);
  local_cc = *(int *)(iVar34 + 0x10) - 7;
  if ((pdVar33 == (dword *)0x0) ||
     (puStack00000028 = param_5, uStack0000002c = param_6,
     iVar9 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,(uint)(*(int *)(param_1 + 0x70) == 3)),
     fVar7 = FLOAT_0000cffc, fVar6 = FLOAT_0000cff8, dVar5 = DOUBLE_0000cfe8,
     dVar4 = DOUBLE_0000cfe0, dVar3 = DOUBLE_0000cfd8, iVar9 == 0)) {
    uVar10 = 0xe00002be;
  }
  else {
    uVar24 = *puStack00000028;
    uVar11 = local_cc - ((int)pdVar33 - (iVar34 + 0x20) >> 2);
    if (puStack00000028[0x16] != 0) {
      local_1c8 = 0x43300000;
      local_1e0 = 0x43300000;
      uStack_1c4 = uStack0000002c >> 0x18;
      uStack_1dc = uStack0000002c >> 10 & 0x1f;
      local_c4 = 0xc10016;
      local_c8 = 0xdb0490;
      local_c0 = 0xdfa23018;
      local_bc = 0xdb0220;
      local_d4 = local_1ec;
      local_b4 = 0x440221;
      local_b8 = 0xc0c011;
      local_dc = &local_204;
      local_d8 = &local_200;
      local_e0 = &local_208;
      local_ac = &local_1f8;
      local_b0 = &local_1fc;
      local_e4 = &local_1f4;
      local_e8 = &local_1f0;
      local_d0 = 0;
      dVar36 = (double)CONCAT44(0x43300000,uStack_1c4) - DOUBLE_0000cfd8;
      dVar35 = (double)CONCAT44(0x43300000,uStack_1dc) - DOUBLE_0000cfd8;
      puVar25 = puStack00000028;
      do {
        if (uVar11 < 0xda) {
          local_1f8 = *(float *)(param_1 + 0x18);
          local_1fc = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *pdVar33 = 0x5c8;
            local_1fc = 2.8026e-45;
            pdVar33[1] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          pdVar33[(int)local_1fc] = 0x1000000;
          puVar8 = *(uint **)(param_1 + 0x7c);
          *puVar8 = ((int)pdVar33 - (int)puVar8 >> 2) + (int)local_1fc | *puVar8;
          iVar34 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       local_ac,local_b0,1);
          uVar11 = local_cc;
          if (iVar34 == 0) {
            *(undefined4 *)((int)local_1f8 + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_1f8;
            pdVar33 = (dword *)((int)local_1f8 + 0x20);
            pdVar13 = (dword *)((int)local_1f8 + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_1f8 + 0x1c;
            pdVar19 = (dword *)((int)local_1f8 + 0x24);
            pdVar20 = (dword *)((int)local_1f8 + 0x28);
            pdVar14 = (dword *)((int)local_1f8 + 0x2c);
            pdVar15 = (dword *)((int)local_1f8 + 0x30);
            pdVar12 = (dword *)((int)local_1f8 + 0x34);
          }
          else {
            pdVar33 = (dword *)0x0;
            pdVar19 = &__mh_bundle_header.cputype;
            pdVar20 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar14 = &__mh_bundle_header.filetype;
            pdVar15 = &__mh_bundle_header.ncmds;
            pdVar12 = &__mh_bundle_header.sizeofcmds;
            pdVar13 = &__mh_bundle_header.flags;
          }
        }
        else {
          pdVar19 = pdVar33 + 1;
          pdVar20 = pdVar33 + 2;
          pdVar14 = pdVar33 + 3;
          pdVar15 = pdVar33 + 4;
          pdVar12 = pdVar33 + 5;
          pdVar13 = pdVar33 + 6;
        }
        puVar8 = *(uint **)(param_1 + 0x7c);
        *puVar8 = (int)pdVar33 - (int)puVar8 >> 2 | *puVar8;
        *(dword **)(param_1 + 0x7c) = pdVar33;
        *pdVar33 = 0xa000000;
        *pdVar19 = *(dword *)(param_1 + 0x84);
        puVar8 = *(uint **)(param_1 + 0x7c);
        *puVar8 = (int)pdVar20 - (int)puVar8 >> 2 | *puVar8;
        *(dword **)(param_1 + 0x7c) = pdVar20;
        *pdVar20 = 0x10000000;
        *pdVar14 = *(dword *)*DAT_0000e6e4;
        *pdVar15 = DAT_0000e6e4[7];
        if (DAT_0000e6c0 == 0x10) {
          *pdVar12 = 3;
        }
        else {
          *pdVar12 = 6;
        }
        iVar34 = *(int *)(param_1 + 0x70);
        *pdVar13 = 0x850;
        pdVar13[1] = 0x100;
        pdVar13[2] = 0x887;
        pdVar13[3] = 0x1c000;
        pdVar13[4] = 0x82c;
        pdVar13[5] = 0;
        pdVar13[6] = 0x1002;
        pdVar13[7] = 0;
        pdVar13[8] = 0x824;
        pdVar13[9] = 1;
        pdVar13[10] = 0x825;
        pdVar13[0xb] = 2;
        pdVar13[0xc] = 0x82d;
        pdVar13[0xd] = 3;
        pdVar13[0xe] = 0x854;
        pdVar13[0xf] = 0x26010006;
        pdVar13[0x10] = 0x878;
        pdVar13[0x11] = 0xf688f688;
        pdVar13[0x12] = 0x10a2;
        pdVar13[0x13] = 0;
        pdVar13[0x14] = 0x1381;
        pdVar13[0x15] = 0;
        pdVar13[0x16] = 0x109e;
        pdVar13[0x17] = 5;
        pdVar13[0x18] = 0x1383;
        pdVar13[0x19] = 0xf;
        pdVar13[0x1a] = 0x1004;
        pdVar13[0x1b] = 0x66666666;
        pdVar13[0x1c] = 0x1005;
        pdVar13[0x1d] = 0x66666666;
        pdVar13[0x1e] = 0x10ae;
        pdVar13[0x1f] = 0;
        pdVar13[0x20] = 0x10ea;
        pdVar13[0x21] = 0x2da49525;
        pdVar13[0x22] = 0x10fa;
        pdVar13[0x23] = 0xffffff;
        pdVar13[0x24] = 0x10f4;
        pdVar13[0x25] = 0xffff;
        pdVar13[0x26] = 0x10f8;
        pdVar13[0x27] = 0;
        pdVar13[0x28] = 0x10f9;
        pdVar13[0x29] =
             *(uint *)(param_1 + 0x54) & 0x1fff | (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
        pdVar13[0x2a] = 0x13c0;
        pdVar13[0x2b] = 0;
        pdVar13[0x2c] = 0x13c1;
        pdVar13[0x2d] = 0;
        pdVar13[0x2e] = 0x10c0;
        pdVar13[0x2f] = 0x40002;
        pdVar13[0x30] = 0x10c1;
        pdVar13[0x31] = 0;
        pdVar13[0x32] = 0x10c8;
        pdVar13[0x33] = 0x10;
        pdVar13[0x34] = 0x101d;
        pdVar13[0x35] = 0x280c2040;
        pdVar13[0x36] = 0x1041;
        pdVar13[0x37] = 1;
        pdVar13[0x38] = 0x1040;
        pdVar13[0x39] = 0;
        pdVar13[0x3a] = 0x1100;
        pdVar13[0x3b] = 0x2a92;
        pdVar13[0x3c] = 0x1120;
        sVar1 = *(short *)(param_1 + 0x50);
        sVar2 = *(short *)(param_1 + 0x52);
        uVar18 = (int)sVar1 - 1;
        iVar9 = sVar2 + -1;
        pdVar13[0x3d] = uVar18 & 0x7ff | iVar9 * 0x800 & 0x3ff800U | 0x80000000;
        pdVar13[0x3e] = 0x1130;
        pdVar13[0x3f] = 0x5300c - (uint)(iVar34 == 3);
        pdVar13[0x40] = 0x1140;
        pdVar13[0x41] =
             *(int *)(param_1 + 0x5c) - 1U & 0x3fff | uVar18 * 0x10 & 0x8000 |
             iVar9 * 0x20 & 0x10000U;
        if (iVar34 != 3) {
          local_1c0 = 0x43300000;
          fVar17 = (float)dVar36 / fVar7;
          local_1b8 = 0x43300000;
          local_1b0 = 0x43300000;
          uStack_1ac = uStack0000002c & 0xff;
          uStack_1bc = uStack0000002c >> 0x10 & 0xff;
          uStack_1b4 = uStack0000002c >> 8 & 0xff;
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_1bc) - dVar3) / fVar7;
          fVar22 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - dVar3) / fVar7;
          fVar16 = (float)((double)CONCAT44(0x43300000,uStack_1ac) - dVar3) / fVar7;
        }
        else {
          local_1d8 = 0x43300000;
          fVar21 = (float)dVar35 / fVar6;
          local_1d0 = 0x43300000;
          local_1ec[1] = 176.0;
          uStack_1d4 = uStack0000002c >> 5 & 0x1f;
          uStack_1cc = uStack0000002c & 0x1f;
          uStack_1e4 = uStack0000002c >> 0xf & 1;
          fVar17 = (float)((double)CONCAT44(0x43300000,uStack_1e4) - dVar3);
          fVar22 = (float)((double)CONCAT44(0x43300000,uStack_1d4) - dVar3) / fVar6;
          fVar16 = (float)((double)CONCAT44(0x43300000,uStack_1cc) - dVar3) / fVar6;
        }
        pdVar13[0x42] = 0x1094;
        pdVar13[0x43] = 0x10000;
        pdVar13[0x44] = 0x1095;
        pdVar13[0x45] = (dword)fVar21;
        pdVar13[0x46] = 0x1095;
        pdVar13[0x47] = (dword)fVar22;
        pdVar13[0x48] = 0x1095;
        pdVar13[0x49] = (dword)fVar16;
        pdVar13[0x4a] = 0x1095;
        pdVar13[0x4b] = (dword)fVar17;
        if (iVar34 != 3) {
          uStack_184 = uVar24 >> 0x18;
          local_188 = 0x43300000;
          uStack_17c = uVar24 >> 0x10 & 0xff;
          local_180 = 0x43300000;
          local_178 = 0x43300000;
          local_170 = 0x43300000;
          uStack_174 = uVar24 >> 8 & 0xff;
          uStack_16c = uVar24 & 0xff;
          fVar17 = (float)((double)CONCAT44(0x43300000,uStack_184) - dVar3) / fVar7;
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_17c) - dVar3) / fVar7;
          fVar22 = (float)((double)CONCAT44(0x43300000,uStack_174) - dVar3) / fVar7;
          fVar16 = (float)((double)CONCAT44(0x43300000,uStack_16c) - dVar3) / fVar7;
          local_a0 = fVar16;
        }
        else {
          uStack_19c = uVar24 >> 10 & 0x1f;
          local_1a0 = 0x43300000;
          uStack_194 = uVar24 >> 5 & 0x1f;
          local_198 = 0x43300000;
          local_190 = 0x43300000;
          local_1a8 = 0x43300000;
          uStack_18c = uVar24 & 0x1f;
          uStack_1a4 = uVar24 >> 0xf & 1;
          fVar17 = (float)((double)CONCAT44(0x43300000,uStack_1a4) - dVar3);
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_19c) - dVar3) / fVar6;
          fVar22 = (float)((double)CONCAT44(0x43300000,uStack_194) - dVar3) / fVar6;
          fVar16 = (float)((double)CONCAT44(0x43300000,uStack_18c) - dVar3) / fVar6;
          local_a0 = fVar17;
        }
        pdVar13[0x4c] = 0x1095;
        pdVar13[0x4d] = (dword)fVar21;
        pdVar13[0x4e] = 0x1095;
        pdVar13[0x4f] = (dword)fVar22;
        pdVar13[0x50] = 0x1095;
        pdVar13[0x51] = (dword)fVar16;
        pdVar13[0x52] = 0x1095;
        pdVar13[0x53] = (dword)fVar17;
        pdVar13[0x54] = 0x1094;
        pdVar13[0x55] = 0;
        pdVar13[0x56] = 0x1095;
        pdVar13[0x57] = 0x7803;
        pdVar13[0x58] = 0x1095;
        pdVar13[0x59] = 0x2400000;
        pdVar13[0x5a] = 0x1095;
        pdVar13[0x5b] = 0x3900e400;
        pdVar13[0x5c] = 0x1095;
        pdVar13[0x5d] = 0;
        pdVar13[0x5e] = 0x1095;
        pdVar13[0x5f] = 0;
        pdVar13[0x60] = 0x1095;
        pdVar13[0x61] = 0;
        pdVar13[0x62] = 0x1095;
        pdVar13[99] = 0x7804;
        pdVar13[100] = 0x1095;
        pdVar13[0x65] = 0x40040000;
        pdVar13[0x66] = 0x1095;
        pdVar13[0x67] = 0x40040000;
        pdVar13[0x68] = 0x1095;
        pdVar13[0x69] = local_c8;
        pdVar13[0x6a] = 0x1095;
        pdVar13[0x6b] = local_c4;
        pdVar13[0x6c] = 0x1095;
        pdVar13[0x6d] = local_c0;
        pdVar13[0x6e] = 0x1095;
        pdVar13[0x6f] = 0x7800;
        pdVar13[0x70] = 0x1095;
        pdVar13[0x71] = 1;
        pdVar13[0x72] = 0x1095;
        pdVar13[0x73] = 1;
        pdVar13[0x74] = 0x1095;
        pdVar13[0x75] = local_bc;
        pdVar13[0x76] = 0x1095;
        pdVar13[0x77] = local_b8;
        pdVar13[0x78] = 0x1095;
        pdVar13[0x79] = 0x12;
        pdVar13[0x7a] = 0x1095;
        pdVar13[0x7b] = 0x7800;
        pdVar13[0x7c] = 0x1095;
        pdVar13[0x7d] = 0x140400;
        pdVar13[0x7e] = 0x1095;
        pdVar13[0x7f] = 0x140400;
        pdVar13[0x80] = 0x1095;
        pdVar13[0x81] = local_b4;
        pdVar13[0x82] = 0x1095;
        pdVar13[0x83] = 0x60d036;
        pdVar13[0x84] = 0x1095;
        pdVar13[0x85] = 0xdda22038;
        pdVar13[0x86] = 0x1095;
        pdVar13[0x87] = 0x7800;
        pdVar13[0x88] = 0x1095;
        pdVar13[0x89] = 0x40040400;
        pdVar13[0x8a] = 0x1095;
        pdVar13[0x8b] = 0x40040400;
        pdVar13[0x8c] = 0x1095;
        pdVar13[0x8d] = local_c8;
        pdVar13[0x8e] = 0x1095;
        pdVar13[0x8f] = local_c4;
        pdVar13[0x90] = 0x1095;
        pdVar13[0x91] = local_c0;
        pdVar13[0x92] = 0x1095;
        pdVar13[0x93] = 0x7800;
        pdVar13[0x94] = 0x1095;
        pdVar13[0x95] = 1;
        pdVar13[0x96] = 0x1095;
        pdVar13[0x97] = 1;
        pdVar13[0x98] = 0x1095;
        pdVar13[0x99] = local_bc;
        pdVar13[0x9a] = 0x1095;
        pdVar13[0x9b] = local_b8;
        pdVar13[0x9c] = 0x1095;
        pdVar13[0x9d] = 0x12;
        pdVar13[0x9e] = 0x1095;
        pdVar13[0x9f] = 0x78101;
        pdVar13[0xa0] = 0x1095;
        pdVar13[0xa1] = 0x140003;
        pdVar13[0xa2] = 0x1095;
        pdVar13[0xa3] = 0x140003;
        pdVar13[0xa4] = 0x1095;
        pdVar13[0xa5] = local_b4;
        pdVar13[0xa6] = 0x1095;
        pdVar13[0xa7] = 0x60d006;
        pdVar13[0xa8] = 0x1095;
        pdVar13[0xa9] = 0xdda22008;
        pdVar13[0xaa] = 0x1189;
        pdVar13[0xab] = 0;
        pdVar13[0xac] = 0x1181;
        pdVar13[0xad] = 5;
        pdVar13[0xae] = 0x118d;
        pdVar13[0xaf] = 0x60000;
        pdVar13[0xb0] = 0x118e;
        pdVar13[0xb1] = 0;
        pdVar13[0xb2] = 0x118c;
        pdVar13[0xb3] = 0x60000;
        pdVar13[0xb4] = 0x11a9;
        pdVar13[0xb5] = 0x1b01;
        pdVar13[0xb6] = 0x11aa;
        pdVar13[0xb7] = 0xf;
        pdVar13[0xb8] = 0x11ab;
        pdVar13[0xb9] = 0xf;
        pdVar13[0xba] = 0x11ac;
        pdVar13[0xbb] = 0xf;
        pdVar13[0xbc] = 0x12f0;
        pdVar13[0xbd] = 0;
        pdVar13[0xbe] = 0x12f5;
        pdVar13[0xbf] = 0;
        local_148 = 0x43300000;
        local_138 = 0x43300000;
        uStack_144 = (int)sVar1 ^ 0x80000000;
        uStack_134 = (int)sVar2 ^ 0x80000000;
        local_168 = 0x43300000;
        local_160 = 0x43300000;
        local_158 = 0x43300000;
        local_150 = 0x43300000;
        uVar32 = puVar25[0x17] + *(int *)(param_1 + 0x60);
        uVar30 = puVar25[0x18] + *(int *)(param_1 + 100);
        uVar31 = uVar32 + puVar25[0x19];
        uVar18 = uVar30 + puVar25[0x1a];
        uStack_164 = uVar32 ^ 0x80000000;
        uStack_154 = uVar30 ^ 0x80000000;
        uStack_15c = uVar31 ^ 0x80000000;
        uStack_14c = uVar18 ^ 0x80000000;
        local_208 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_144) - dVar4);
        local_200 = FLOAT_0000d000 / (float)((double)CONCAT44(0x43300000,uStack_134) - dVar4);
        local_1ec[0] = local_208 * (float)((double)CONCAT44(0x43300000,uStack_164) - dVar4);
        local_208 = local_208 * (float)((double)CONCAT44(0x43300000,uStack_15c) - dVar4);
        local_204 = local_200 * (float)((double)CONCAT44(0x43300000,uStack_154) - dVar4);
        local_200 = local_200 * (float)((double)CONCAT44(0x43300000,uStack_14c) - dVar4);
        pdVar13[0xc0] = 0xc00c3500;
        pdVar13[0xc1] = 0x4003d;
        uVar29 = uVar32 | uVar18 * 0x10000;
        pdVar13[0xc2] = uVar29;
        fVar21 = *local_d4;
        pdVar13[0xc3] = (dword)fVar21;
        fVar17 = *local_d8;
        pdVar13[0xc4] = (dword)fVar17;
        uVar28 = uVar32 | uVar30 * 0x10000;
        pdVar13[0xc5] = uVar28;
        pdVar13[0xc6] = (dword)fVar21;
        fVar21 = *local_dc;
        pdVar13[199] = (dword)fVar21;
        uVar27 = uVar31 | uVar30 * 0x10000;
        pdVar13[200] = uVar27;
        fVar22 = *local_e0;
        pdVar13[0xc9] = (dword)fVar22;
        pdVar13[0xca] = (dword)fVar21;
        uVar26 = uVar31 | uVar18 * 0x10000;
        pdVar13[0xcb] = uVar26;
        pdVar13[0xcc] = (dword)fVar22;
        pdVar13[0xcd] = (dword)fVar17;
        pdVar13[0xce] = 0x1393;
        pdVar13[0xcf] = 10;
        pdVar13[0xd0] = 0x5c8;
        pdVar13[0xd1] = 0x20000;
        puVar23 = pdVar13 + 0xd2;
        if (uVar11 - 0xd8 < 0x86) {
          local_1fc = *(float *)(param_1 + 0x18);
          local_1f8 = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *puVar23 = 0x5c8;
            local_1f8 = 2.8026e-45;
            pdVar13[0xd3] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          puVar23[(int)local_1f8] = 0x1000000;
          puVar8 = *(uint **)(param_1 + 0x7c);
          *puVar8 = ((int)puVar23 - (int)puVar8 >> 2) + (int)local_1f8 | *puVar8;
          iVar34 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       local_b0,local_ac,1);
          uVar11 = local_cc;
          if (iVar34 == 0) {
            *(undefined4 *)((int)local_1fc + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_1fc;
            puVar23 = (undefined4 *)((int)local_1fc + 0x20);
            pdVar33 = (dword *)((int)local_1fc + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_1fc + 0x1c;
            pdVar12 = (dword *)((int)local_1fc + 0x24);
            pdVar14 = (dword *)((int)local_1fc + 0x28);
            pdVar15 = (dword *)((int)local_1fc + 0x2c);
            pdVar19 = (dword *)((int)local_1fc + 0x30);
            pdVar13 = (dword *)((int)local_1fc + 0x34);
          }
          else {
            puVar23 = (undefined4 *)0x0;
            pdVar12 = &__mh_bundle_header.cputype;
            pdVar14 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar15 = &__mh_bundle_header.filetype;
            pdVar19 = &__mh_bundle_header.ncmds;
            pdVar13 = &__mh_bundle_header.sizeofcmds;
            pdVar33 = &__mh_bundle_header.flags;
          }
        }
        else {
          pdVar33 = pdVar13 + 0xd8;
          pdVar12 = pdVar13 + 0xd3;
          pdVar14 = pdVar13 + 0xd4;
          pdVar15 = pdVar13 + 0xd5;
          pdVar19 = pdVar13 + 0xd6;
          pdVar13 = pdVar13 + 0xd7;
          uVar11 = uVar11 - 0xd8;
        }
        puVar8 = *(uint **)(param_1 + 0x7c);
        *puVar8 = (int)puVar23 - (int)puVar8 >> 2 | *puVar8;
        *(undefined4 **)(param_1 + 0x7c) = puVar23;
        *puVar23 = 0x11000000;
        *pdVar12 = *(dword *)(param_1 + 0x84);
        *pdVar14 = 0;
        *pdVar15 = 0;
        puVar8 = *(uint **)(param_1 + 0x7c);
        *puVar8 = (int)pdVar19 - (int)puVar8 >> 2 | *puVar8;
        *(dword **)(param_1 + 0x7c) = pdVar19;
        *pdVar19 = 0x4000000;
        *pdVar13 = *(dword *)*DAT_0000e6e4;
        puVar23 = DAT_0000e6e4;
        iVar34 = DAT_0000e6e4[0xc];
        if (iVar34 == 3) {
          iVar34 = 0xb;
        }
        else if (iVar34 == 6) {
          iVar34 = 0xc;
        }
        iVar34 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar33,DAT_0000e6e4 + 3,iVar34,0,0,0,0);
        local_128 = 0x43300000;
        local_120 = 0x43300000;
        local_118 = 0x43300000;
        local_110 = 0x43300000;
        pdVar33[iVar34] = 0xc00c3500;
        pdVar33[iVar34 + 1] = 0x4003d;
        local_108 = 0x43300000;
        uStack_104 = (int)*(short *)(puVar23 + 4) ^ 0x80000000;
        local_1fc = (float)((double)(float)((double)CONCAT44(0x43300000,uVar32) - dVar3) *
                           (dVar5 / ((double)CONCAT44(0x43300000,uStack_104) - dVar4)));
        local_100 = 0x43300000;
        uStack_fc = (int)*(short *)(puVar23 + 4) ^ 0x80000000;
        local_1f0 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar31) - dVar3) *
                           (dVar5 / ((double)CONCAT44(0x43300000,uStack_fc) - dVar4)));
        local_f8 = 0x43300000;
        uStack_f4 = (int)*(short *)((int)puVar23 + 0x12) ^ 0x80000000;
        local_1f4 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar30) - dVar3) *
                           (dVar5 / ((double)CONCAT44(0x43300000,uStack_f4) - dVar4)));
        local_f0 = 0x43300000;
        uStack_ec = (int)*(short *)((int)puVar23 + 0x12) ^ 0x80000000;
        local_1f8 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar18) - dVar3) *
                           (dVar5 / ((double)CONCAT44(0x43300000,uStack_ec) - dVar4)));
        pdVar33[iVar34 + 2] = uVar29;
        fVar21 = *local_b0;
        pdVar33[iVar34 + 3] = (dword)fVar21;
        fVar17 = *local_ac;
        pdVar33[iVar34 + 4] = (dword)fVar17;
        pdVar33[iVar34 + 5] = uVar28;
        pdVar33[iVar34 + 6] = (dword)fVar21;
        fVar21 = *local_e4;
        pdVar33[iVar34 + 7] = (dword)fVar21;
        pdVar33[iVar34 + 8] = uVar27;
        fVar22 = *local_e8;
        pdVar33[iVar34 + 9] = (dword)fVar22;
        pdVar33[iVar34 + 10] = (dword)fVar21;
        pdVar33[iVar34 + 0xb] = uVar26;
        pdVar33[iVar34 + 0xc] = (dword)fVar22;
        pdVar33[iVar34 + 0xd] = (dword)fVar17;
        pdVar33[iVar34 + 0xe] = 0x1393;
        pdVar33[iVar34 + 0xf] = 10;
        pdVar33[iVar34 + 0x10] = 0x5c8;
        pdVar33[iVar34 + 0x11] = 0x20000;
        uVar11 = (uVar11 - 6) - (iVar34 + 0x12);
        puVar25 = puVar25 + 4;
        pdVar33 = pdVar33 + iVar34 + 0x12;
        local_d0 = local_d0 + 1;
        uStack_124 = uVar32;
        uStack_11c = uVar31;
        uStack_114 = uVar30;
        uStack_10c = uVar18;
      } while (local_d0 < puStack00000028[0x16]);
    }
    uVar10 = 0;
    *(dword **)(param_1 + 0x80) = pdVar33;
  }
  return uVar10;
}

/* _radeonSolidScanlines @ 0xba90 (3660 bytes) */
int _radeonSolidScanlines(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 *param_5;
  undefined4 param_6;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char *pcVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  float *pfVar17;
  dword *pdVar18;
  int iVar19;
  dword *pdVar20;
  dword *pdVar21;
  segment_command *psVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  dword *pdVar26;
  int iVar27;
  float fVar28;
  dword *pdVar29;
  uint *puVar30;
  float *pfVar31;
  bool bVar35;
  dword *pdVar32;
  int iVar33;
  float fVar34;
  float fVar36;
  int iVar37;
  dword *pdVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  dword *pdVar45;
  dword *pdVar46;
  undefined4 *puVar47;
  dword *pdVar48;
  float local_1a4;
  float local_1a0;
  float local_19c;
  undefined4 local_178;
  int iStack_174;
  undefined4 local_170;
  int iStack_16c;
  undefined4 local_168;
  int iStack_164;
  undefined4 local_160;
  int iStack_15c;
  undefined4 local_158;
  uint uStack_154;
  undefined4 local_150;
  uint uStack_14c;
  undefined4 local_148;
  uint uStack_144;
  undefined4 local_140;
  uint uStack_13c;
  undefined4 local_138;
  uint uStack_134;
  undefined4 local_130;
  uint uStack_12c;
  undefined4 local_128;
  uint uStack_124;
  undefined4 local_120;
  uint uStack_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  undefined4 *local_10c;
  uint local_108;
  int local_104;
  uint local_100;
  int local_fc;
  undefined4 local_f8;
  uint local_f4;
  uint local_f0;
  dword local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  int local_dc;
  
  if ((param_4 & 0x7ffff000) == 0x6000) {
    puVar47 = *(undefined4 **)(param_1 + 0x80);
    fVar36 = *(float *)(param_1 + 0x18);
    if (puVar47 != (undefined4 *)0x0) {
      if ((uint)((*(int *)((int)fVar36 + 0x10) + -7) - ((int)puVar47 - ((int)fVar36 + 0x20) >> 2)) <
          param_5[0x16] * 0xc + 0x6eU) {
        local_1a0 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *puVar47 = 0x5c8;
          local_1a0 = 2.8026e-45;
          puVar47[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        puVar47[(int)local_1a0] = 0x1000000;
        puVar11 = PTR_0000e694;
        puVar30 = *(uint **)(param_1 + 0x7c);
        *puVar30 = ((int)puVar47 - (int)puVar30 >> 2) + (int)local_1a0 | *puVar30;
        local_1a4 = fVar36;
        iVar16 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar11,
                                     &local_1a4,&local_1a0,1);
        if (iVar16 == 0) {
          *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
          *(float *)(param_1 + 0x18) = local_1a4;
          puVar47 = (undefined4 *)((int)local_1a4 + 0x20);
          *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
        }
        else {
          puVar47 = (undefined4 *)0x0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          *(undefined4 *)(param_1 + 0x18) = 0;
        }
      }
      iVar16 = ((int (*)())_radeon3DFillSetup)(puVar47,0,param_6,param_1);
      iVar24 = param_5[0x16];
      puVar30 = puVar47 + iVar16;
      *puVar30 = iVar24 * 0xc0000 | 0xc0003500;
      pfVar17 = (float *)(puVar30 + 2);
      puVar30[1] = iVar24 << 0x12 | 0x3d;
      dVar8 = DOUBLE_0000cfe0;
      uVar15 = param_5[0x17] + *(int *)(param_1 + 100);
      fVar36 = (float)((double)CONCAT44(0x43300000,uVar15 ^ 0x80000000) - DOUBLE_0000cfe0);
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar15 + param_5[0x18] ^ 0x80000000) -
                     DOUBLE_0000cfe0);
      if (iVar24 != 0) {
        iVar16 = *(int *)(param_1 + 0x60);
        if (iVar24 == 0) {
          iVar24 = 1;
        }
        do {
          fVar2 = (float)((double)CONCAT44(0x43300000,param_5[0x19] + iVar16 ^ 0x80000000) - dVar8);
          fVar3 = (float)((double)CONCAT44(0x43300000,param_5[0x1a] + iVar16 ^ 0x80000000) - dVar8);
          *pfVar17 = fVar2;
          pfVar17[1] = fVar1;
          pfVar17[2] = 0.0;
          pfVar17[3] = fVar2;
          pfVar17[4] = fVar36;
          pfVar17[5] = 0.0;
          pfVar17[6] = fVar3;
          pfVar17[7] = fVar36;
          pfVar17[8] = 0.0;
          pfVar17[9] = fVar3;
          pfVar17[10] = fVar1;
          pfVar31 = pfVar17 + 0xb;
          pfVar17 = pfVar17 + 0xc;
          *pfVar31 = 0.0;
          param_5 = param_5 + 2;
          iVar24 = iVar24 + -1;
        } while (iVar24 != 0);
      }
      *pfVar17 = 7.02191e-42;
      pfVar17[1] = 1.4013e-44;
      pfVar17[2] = 2.07392e-42;
      pfVar17[3] = 1.83671e-40;
      *(float **)(param_1 + 0x80) = pfVar17 + 4;
      return 0;
    }
  }
  else {
    pdVar46 = *(dword **)(param_1 + 0x80);
    iVar16 = *(int *)(param_1 + 0x18);
    uVar15 = *(int *)(iVar16 + 0x10) - 7;
    if ((pdVar46 != (dword *)0x0) &&
       (iVar24 = ((int (*)())_createTextureBuffer)(param_1,0x40,0x40,(uint)(*(int *)(param_1 + 0x70) == 3)),
       iVar24 != 0)) {
      local_e8 = 0xbaa4;
      uVar41 = uVar15 - ((int)pdVar46 - (iVar16 + 0x20) >> 2);
      _fillTextureWithPattern(param_6,param_4 & 0x7ffff000,*param_5,param_5[1]);
      fVar1 = FLOAT_0000d00c;
      fVar36 = FLOAT_0000d008;
      dVar8 = DOUBLE_0000cfd8;
      iVar16 = *(int *)(((unsigned char *)0x00002ca4) + local_e8);
      local_104 = *(int *)(iVar16 + 0x30);
      if (local_104 == 3) {
        local_104 = 0xb;
      }
      else if (local_104 == 6) {
        local_104 = 0xc;
      }
      uVar25 = param_5[0x16];
      local_178 = 0x43300000;
      uVar39 = param_5[0x17] + *(int *)(param_1 + 100);
      iStack_174 = (uVar39 & 7) + param_5[3];
      uVar42 = uVar39 + param_5[0x18];
      fVar2 = (float)((double)CONCAT44(0x43300000,iStack_174) - DOUBLE_0000cfd8);
      if (uVar25 != 0) {
        local_118 = uVar42;
        if (uVar39 + 8 < uVar42) {
          local_118 = uVar39 + 8;
        }
        bVar35 = true;
        local_100 = 0;
        fVar3 = fVar2 + FLOAT_0000d008;
        fVar7 = fVar2 + FLOAT_0000d00c;
        local_10c = param_5;
        do {
          dVar10 = DOUBLE_0000cfe8;
          dVar9 = DOUBLE_0000cfe0;
          local_170 = 0x43300000;
          uVar43 = *(int *)(param_1 + 0x60) + local_10c[0x19];
          iStack_16c = (uVar43 & 7) + param_5[2];
          uVar44 = *(int *)(param_1 + 0x60) + local_10c[0x1a];
          fVar4 = (float)((double)CONCAT44(0x43300000,iStack_16c) - dVar8);
          if (uVar39 < uVar42) {
            local_114 = uVar43 + 8;
            local_108 = uVar44;
            if (local_114 < uVar44) {
              local_108 = local_114;
            }
            local_f4 = uVar43 & 0x1fff;
            local_f0 = uVar44 & 0x1fff;
            local_f8 = 0xc000;
            local_ec = 0x4003d;
            local_fc = 1;
            uVar25 = uVar39;
            uVar12 = local_118;
            do {
              if (uVar43 < uVar44) {
                uVar14 = uVar43;
                uVar40 = local_108;
                if (!bVar35) {
                  local_e4 = uVar12 << 0x10;
                  local_e0 = uVar25 << 0x10;
                  local_dc = uVar12 - uVar25;
                  uVar12 = local_114;
                  goto LAB_0000c1c8;
                }
                if (uVar41 < 0x8e) {
                  local_1a4 = *(float *)(param_1 + 0x18);
                  local_1a0 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar46 = 0x5c8;
                    local_1a0 = 2.8026e-45;
                    pdVar46[1] = local_f8;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar46[(int)local_1a0] = 0x1000000;
                  puVar11 = PTR_0000e694;
                  puVar30 = *(uint **)(param_1 + 0x7c);
                  *puVar30 = ((int)pdVar46 - (int)puVar30 >> 2) + (int)local_1a0 | *puVar30;
                  iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar11,&local_1a4,&local_1a0,1);
                  uVar40 = local_108;
                  if (iVar24 == 0) {
                    local_e4 = uVar12 << 0x10;
                    local_e0 = uVar25 << 0x10;
                    local_dc = uVar12 - uVar25;
                    *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
                    pdVar46 = (dword *)((int)local_1a4 + 0x20);
                    local_110 = local_114;
                    *(float *)(param_1 + 0x18) = local_1a4;
                    pdVar48 = (dword *)((int)local_1a4 + 0x48);
                    *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
                    pdVar45 = (dword *)((int)local_1a4 + 0x24);
                    pdVar38 = (dword *)((int)local_1a4 + 0x28);
                    pdVar18 = (dword *)((int)local_1a4 + 0x2c);
                    pdVar32 = (dword *)((int)local_1a4 + 0x30);
                    pdVar20 = (dword *)((int)local_1a4 + 0x34);
                    pdVar21 = (dword *)((int)local_1a4 + 0x38);
                    psVar22 = (segment_command *)((int)local_1a4 + 0x3c);
                    pdVar26 = (dword *)((int)local_1a4 + 0x40);
                    pdVar29 = (dword *)((int)local_1a4 + 0x44);
                    uVar41 = uVar15;
                  }
                  else {
                    local_e4 = uVar12 << 0x10;
                    local_dc = uVar12 - uVar25;
                    local_e0 = uVar25 << 0x10;
                    local_110 = local_114;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar46 = (dword *)0x0;
                    pdVar45 = &__mh_bundle_header.cputype;
                    pdVar38 = &__mh_bundle_header.cpusubtype;
                    pdVar18 = &__mh_bundle_header.filetype;
                    pdVar32 = &__mh_bundle_header.ncmds;
                    pdVar20 = &__mh_bundle_header.sizeofcmds;
                    pdVar21 = &__mh_bundle_header.flags;
                    psVar22 = &(*(GhidraMachOCommand *)0x0000001c);
                    pdVar26 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    pdVar29 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar48 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    uVar41 = uVar15;
                  }
                }
                else {
                  local_e4 = uVar12 << 0x10;
                  local_e0 = uVar25 << 0x10;
                  local_dc = uVar12 - uVar25;
                  pdVar45 = pdVar46 + 1;
                  pdVar38 = pdVar46 + 2;
                  pdVar18 = pdVar46 + 3;
                  local_110 = local_114;
                  pdVar32 = pdVar46 + 4;
                  pdVar20 = pdVar46 + 5;
                  pdVar21 = pdVar46 + 6;
                  psVar22 = (segment_command *)(pdVar46 + 7);
                  pdVar26 = pdVar46 + 8;
                  pdVar29 = pdVar46 + 9;
                  pdVar48 = pdVar46 + 10;
                }
                do {
                  puVar30 = *(uint **)(param_1 + 0x7c);
                  *puVar30 = (int)pdVar46 - (int)puVar30 >> 2 | *puVar30;
                  *(dword **)(param_1 + 0x7c) = pdVar46;
                  *pdVar46 = 0x11000000;
                  *pdVar45 = *(dword *)(param_1 + 0x84);
                  *pdVar38 = 0;
                  *pdVar18 = 0;
                  puVar30 = *(uint **)(param_1 + 0x7c);
                  *puVar30 = (int)pdVar32 - (int)puVar30 >> 2 | *puVar30;
                  *(dword **)(param_1 + 0x7c) = pdVar32;
                  *pdVar32 = 0x8000000;
                  *pdVar20 = *(dword *)**(undefined4 **)(((unsigned char *)0x00002ca4) + local_e8);
                  *pdVar21 = 0;
                  psVar22->cmd = 0;
                  *pdVar26 = 0;
                  *pdVar29 = 0;
                  uVar41 = uVar41 - 10;
                  iVar19 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar48,iVar16 + 0xc,local_104,0,0,0,0);
                  iVar24 = iVar19 << 2;
                  iVar33 = iVar19 + 1;
                  iVar37 = iVar19 + 2;
                  iVar27 = iVar19 + 3;
                  iVar23 = iVar19 + 4;
                  pdVar46 = pdVar48;
                  while( true ) {
                    if (local_fc != 0) {
                      pcVar6 = (char *)((int)pdVar46 + iVar24);
                      pcVar6[0] = '\0';
                      pcVar6[1] = '\0';
                      pcVar6[2] = '\x10';
                      pcVar6[3] = -8;
                      pdVar46[iVar33] = local_f4 | uVar39 * 0x2000 & 0x3ffe000;
                      pdVar46[iVar37] = 0x10f9;
                      pdVar46[iVar27] = local_f0 | uVar42 * 0x2000 & 0x3ffe000;
                      iVar24 = iVar23 << 2;
                      iVar33 = iVar23 + 1;
                      iVar37 = iVar23 + 2;
                      local_fc = 0;
                      iVar27 = iVar23 + 3;
                      iVar19 = iVar23;
                      iVar23 = iVar23 + 4;
                    }
                    iVar13 = uVar40 - uVar14;
                    if ((iVar13 == 8) && (local_dc == 8)) {
                      pcVar6 = (char *)((int)pdVar46 + iVar24);
                      pcVar6[0] = -0x40;
                      pcVar6[1] = '\f';
                      pcVar6[2] = '5';
                      pcVar6[3] = '\0';
                      pdVar46[iVar33] = local_ec;
                      local_138 = 0x43300000;
                      uStack_134 = (int)*(short *)(iVar16 + 0x10) ^ 0x80000000;
                      fVar5 = (float)((double)(fVar4 + fVar36) *
                                     (dVar10 / ((double)CONCAT44(0x43300000,uStack_134) - dVar9)));
                      local_130 = 0x43300000;
                      uStack_12c = (int)*(short *)(iVar16 + 0x10) ^ 0x80000000;
                      fVar34 = (float)((double)(fVar4 + fVar1) *
                                      (dVar10 / ((double)CONCAT44(0x43300000,uStack_12c) - dVar9)));
                      local_128 = 0x43300000;
                      uStack_124 = (int)*(short *)(iVar16 + 0x12) ^ 0x80000000;
                      local_1a4 = (float)((double)fVar3 *
                                         (dVar10 / ((double)CONCAT44(0x43300000,uStack_124) - dVar9)
                                         ));
                      local_120 = 0x43300000;
                      uStack_11c = (int)*(short *)(iVar16 + 0x12) ^ 0x80000000;
                      fVar28 = (float)((double)fVar7 *
                                      (dVar10 / ((double)CONCAT44(0x43300000,uStack_11c) - dVar9)));
                      pdVar46[iVar37] = uVar14 | local_e4;
                      pdVar46[iVar27] = (dword)fVar5;
                      pdVar46[iVar23] = (dword)fVar28;
                      pdVar46[iVar19 + 5] = uVar14 | local_e0;
                      pdVar46[iVar19 + 6] = (dword)fVar5;
                      pdVar46[iVar19 + 7] = (dword)local_1a4;
                      pdVar46[iVar19 + 8] = uVar40 | local_e0;
                      local_1a0 = fVar34;
                      local_19c = fVar28;
                    }
                    else {
                      local_168 = 0x43300000;
                      local_160 = 0x43300000;
                      iStack_15c = local_dc;
                      pcVar6 = (char *)((int)pdVar46 + iVar24);
                      pcVar6[0] = -0x40;
                      pcVar6[1] = '\f';
                      pcVar6[2] = '5';
                      pcVar6[3] = '\0';
                      pdVar46[iVar33] = local_ec;
                      local_158 = 0x43300000;
                      uStack_154 = (int)*(short *)(iVar16 + 0x10) ^ 0x80000000;
                      local_19c = (float)((double)(fVar4 + fVar36) *
                                         (dVar10 / ((double)CONCAT44(0x43300000,uStack_154) - dVar9)
                                         ));
                      local_150 = 0x43300000;
                      uStack_14c = (int)*(short *)(iVar16 + 0x10) ^ 0x80000000;
                      fVar34 = (float)((double)(fVar4 + (float)((double)CONCAT44(0x43300000,iVar13)
                                                               - dVar8)) *
                                      (dVar10 / ((double)CONCAT44(0x43300000,uStack_14c) - dVar9)));
                      local_148 = 0x43300000;
                      uStack_144 = (int)*(short *)(iVar16 + 0x12) ^ 0x80000000;
                      local_1a4 = (float)((double)fVar3 *
                                         (dVar10 / ((double)CONCAT44(0x43300000,uStack_144) - dVar9)
                                         ));
                      local_140 = 0x43300000;
                      uStack_13c = (int)*(short *)(iVar16 + 0x12) ^ 0x80000000;
                      fVar28 = (float)((double)(fVar2 + (float)((double)CONCAT44(0x43300000,local_dc
                                                                                ) - dVar8)) *
                                      (dVar10 / ((double)CONCAT44(0x43300000,uStack_13c) - dVar9)));
                      pdVar46[iVar37] = local_e4 | uVar14;
                      pdVar46[iVar27] = (dword)local_19c;
                      pdVar46[iVar23] = (dword)fVar28;
                      pdVar46[iVar19 + 5] = local_e0 | uVar14;
                      pdVar46[iVar19 + 6] = (dword)local_19c;
                      pdVar46[iVar19 + 7] = (dword)local_1a4;
                      pdVar46[iVar19 + 8] = local_e0 | uVar40;
                      local_1a0 = fVar28;
                      iStack_164 = iVar13;
                    }
                    pdVar46[iVar19 + 9] = (dword)fVar34;
                    pdVar46[iVar19 + 10] = (dword)local_1a4;
                    pdVar46[iVar19 + 0xb] = uVar40 | local_e4;
                    pdVar46[iVar19 + 0xc] = (dword)fVar34;
                    pdVar46[iVar19 + 0xd] = (dword)fVar28;
                    pdVar46[iVar19 + 0xe] = 0x1393;
                    pdVar46[iVar19 + 0xf] = 10;
                    pdVar46[iVar19 + 0x10] = 0x5c8;
                    pdVar46[iVar19 + 0x11] = 0x20000;
                    uVar41 = uVar41 - (iVar19 + 0x12);
                    pdVar46 = pdVar46 + iVar19 + 0x12;
                    uVar40 = uVar44;
                    if (uVar14 + 0x10 < uVar44) {
                      uVar40 = uVar14 + 0x10;
                    }
                    bVar35 = false;
                    if (uVar44 <= local_110) goto LAB_0000c820;
                    uVar12 = local_110 + 8;
                    uVar14 = local_110;
LAB_0000c1c8:
                    if (uVar41 < 0x16) break;
                    iVar23 = 4;
                    iVar27 = 3;
                    iVar37 = 2;
                    iVar33 = 1;
                    iVar24 = 0;
                    iVar19 = 0;
                    local_110 = uVar12;
                  }
                  local_1a0 = *(float *)(param_1 + 0x18);
                  local_1a4 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar46 = 0x5c8;
                    local_1a4 = 2.8026e-45;
                    pdVar46[1] = local_f8;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar46[(int)local_1a4] = 0x1000000;
                  puVar11 = PTR_0000e694;
                  puVar30 = *(uint **)(param_1 + 0x7c);
                  *puVar30 = ((int)pdVar46 - (int)puVar30 >> 2) + (int)local_1a4 | *puVar30;
                  iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar11,&local_1a0,&local_1a4,1);
                  if (iVar24 == 0) {
                    local_110 = uVar14 + 8;
                    local_fc = 1;
                    *(undefined4 *)((int)local_1a0 + 0x1c) = 0;
                    *(float *)(param_1 + 0x18) = local_1a0;
                    pdVar46 = (dword *)((int)local_1a0 + 0x20);
                    pdVar48 = (dword *)((int)local_1a0 + 0x48);
                    *(int *)(param_1 + 0x7c) = (int)local_1a0 + 0x1c;
                    pdVar45 = (dword *)((int)local_1a0 + 0x24);
                    pdVar38 = (dword *)((int)local_1a0 + 0x28);
                    pdVar18 = (dword *)((int)local_1a0 + 0x2c);
                    pdVar32 = (dword *)((int)local_1a0 + 0x30);
                    pdVar20 = (dword *)((int)local_1a0 + 0x34);
                    pdVar21 = (dword *)((int)local_1a0 + 0x38);
                    psVar22 = (segment_command *)((int)local_1a0 + 0x3c);
                    pdVar26 = (dword *)((int)local_1a0 + 0x40);
                    pdVar29 = (dword *)((int)local_1a0 + 0x44);
                    uVar41 = uVar15;
                  }
                  else {
                    local_110 = uVar14 + 8;
                    pdVar48 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    pdVar29 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar26 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    psVar22 = &(*(GhidraMachOCommand *)0x0000001c);
                    local_fc = 1;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar21 = &__mh_bundle_header.flags;
                    pdVar20 = &__mh_bundle_header.sizeofcmds;
                    pdVar32 = &__mh_bundle_header.ncmds;
                    pdVar18 = &__mh_bundle_header.filetype;
                    pdVar38 = &__mh_bundle_header.cpusubtype;
                    pdVar45 = &__mh_bundle_header.cputype;
                    pdVar46 = (dword *)0x0;
                    uVar41 = uVar15;
                  }
                } while( true );
              }
LAB_0000c820:
              uVar14 = uVar25 + 0x10;
              uVar25 = uVar25 + 8;
              uVar12 = uVar42;
              if (uVar14 < uVar42) {
                uVar12 = uVar14;
              }
            } while (uVar25 < uVar42);
            uVar25 = param_5[0x16];
          }
          local_100 = local_100 + 1;
          local_10c = local_10c + 2;
        } while (local_100 < uVar25);
      }
      *(dword **)(param_1 + 0x80) = pdVar46;
      return 0;
    }
  }
  return 0xe00002be;
}

/* _printf_LDBLStub @ 0xc89c (172 bytes) */
int _printf_LDBLStub(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (_funcptr == (code *)0x0) {
    _funcptr = (code *)((int (*)())___stub_getrealaddr)("printf");
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
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  char local_58 [4];
  char acStack_54 [4];
  char acStack_50 [64];
  
  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  sVar1 = _strlen(local_58);
  *(undefined4 *)(local_58 + sVar1) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 0));
  acStack_50[sVar1] = s__LDBL128_0000cfbc[8];
  *(undefined4 *)(acStack_54 + sVar1) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_0000cfbc) + 4));
  iVar2 = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (iVar2 == 0) {
    local_58[sVar1] = '\0';
  }
  _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  uVar3 = _NSAddressOfSymbol();
  return uVar3;
}

