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
  uint uVar10;
  uint uVar11;
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
  
  puVar3 = (undefined4 *)_calloc(1,0x3c);
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
        uVar10 = *param_3;
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
              uVar11 = uVar10;
              do {
                uVar13 = uVar13 + 1;
                uVar10 = uVar11 + uVar9;
                _bcopy(uVar11,piVar14,uVar9);
                piVar14 = (int *)((int)piVar14 + (uVar9 & 0xfffffffc));
                uVar11 = uVar10;
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
    _free(*(undefined4 *)(param_3 + 0x28));
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
  
  if (_textureBufferBytes == 0) {
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
      if (_textureBufferBytes == 0) goto LAB_00004194;
    }
  }
  uVar4 = param_2 + 0x20U & 0xffffffe0;
  uVar3 = param_3 + 0x20U & 0xffffffe0;
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
  _free(_textureBufferBytes);
  _textureBufferBytes = 0;
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
  if (_textureBufferBytes != 0) {
    _textureBuffer = _textureBufferBytes;
    iVar1 = ((int (*)())__AllocateSurface)(param_1,8,&_textureBuffer,0);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_textureBufferBytes);
      uVar2 = 0;
      _textureBufferBytes = 0;
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
  
  if (_offscreenBufferBytes == 0) goto LAB_000043f0;
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
      if (_offscreenBufferBytes == 0) goto LAB_000043f0;
    }
  }
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
  ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
  _free(_offscreenBufferBytes);
  _offscreenBufferBytes = 0;
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
  if (_offscreenBufferBytes != 0) {
    _offscreenBuffer = _offscreenBufferBytes;
    iVar1 = ((int (*)())__AllocateSurface)(param_1,0,&_offscreenBuffer,0);
    if (iVar1 == 0) {
      uVar2 = 1;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
    }
    else {
      _free(_offscreenBufferBytes);
      uVar2 = 0;
      _offscreenBufferBytes = 0;
    }
  }
  return uVar2;
}

/* __Stop @ 0x4500 (248 bytes) */
int __Stop(param_1)
  int param_1;
{
  int iVar1;
  
  if (_offscreenBufferBytes != 0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,0,&_offscreenBuffer);
    _free(_offscreenBufferBytes);
    _offscreenBufferBytes = 0;
  }
  if (_textureBufferBytes != 0) {
    *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
    ((int (*)())__FreeSurface)(param_1,8,&_textureBuffer);
    _free(_textureBufferBytes);
    _textureBufferBytes = 0;
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
  undefined *puVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  dword *pdVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  dword *pdVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  dword *pdVar16;
  int iVar17;
  int iVar18;
  dword *pdVar19;
  int iVar20;
  float fVar21;
  dword *pdVar22;
  float fVar23;
  dword *pdVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  int iVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  uint uVar41;
  dword *pdVar42;
  int iVar43;
  double dVar44;
  double dVar45;
  double dVar46;
  double dVar47;
  double dVar48;
  double dVar49;
  double dVar50;
  double dVar51;
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
  
  pdVar42 = *(dword **)(param_1 + 0x80);
  iVar39 = *(int *)(param_5 + 0x58);
  uVar41 = *(int *)(*(int *)(param_1 + 0x18) + 0x10) - 7;
  if (pdVar42 != (dword *)0x0) {
    uVar40 = uVar41 - ((int)pdVar42 - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
    if ((0x1000 < *(short *)(param_1 + 0x50)) || (0x1000 < *(short *)(param_1 + 0x52))) {
      return 0xe00002c7;
    }
    iVar6 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,0);
    if (iVar6 != 0) {
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
      if (iVar39 != 0) {
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
          dVar44 = (double)CONCAT44(0x43300000,uStack_194) - 4503601774854144.0;
          dVar48 = (double)(float)dVar44;
          dVar46 = (double)CONCAT44(0x43300000,uStack_18c) - 4503601774854144.0;
          dVar49 = (double)(float)dVar46;
          dVar45 = dVar49 + (double)(float)((double)CONCAT44(0x43300000,uStack_17c) -
                                           4503601774854144.0);
          dVar51 = (double)(float)dVar45;
          dVar47 = dVar48 + (double)(float)((double)CONCAT44(0x43300000,uStack_184) -
                                           4503601774854144.0);
          dVar50 = (double)(float)dVar47;
          if (2147483648.0 <= dVar48) {
            local_170 = (longlong)(int)(dVar48 - 2147483648.0);
            local_dc = (int)(dVar48 - 2147483648.0) + 0x80000000;
          }
          else {
            local_dc = (uint)dVar44;
            local_178 = (longlong)(int)local_dc;
          }
          if (2147483648.0 <= dVar49) {
            local_160 = (longlong)(int)(dVar49 - 2147483648.0);
            local_e0 = (int)(dVar49 - 2147483648.0) + 0x80000000;
          }
          else {
            local_e0 = (uint)dVar46;
            local_168 = (longlong)(int)local_e0;
          }
          if (2147483648.0 <= dVar50) {
            local_150 = (longlong)(int)(dVar50 - 2147483648.0);
            local_e4 = (int)(dVar50 - 2147483648.0) + 0x80000000;
          }
          else {
            local_e4 = (uint)dVar47;
            local_158 = (longlong)(int)local_e4;
          }
          if (2147483648.0 <= dVar51) {
            local_140 = (longlong)(int)(dVar51 - 2147483648.0);
            local_e8 = (int)(dVar51 - 2147483648.0) + 0x80000000;
          }
          else {
            local_e8 = (uint)dVar45;
            local_148 = (longlong)(int)local_e8;
          }
          if (bVar3) {
            if (uVar40 < 0x8a) {
              local_1a8 = *(float *)(param_1 + 0x18);
              local_19c[0] = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar42 = 0x5c8;
                local_19c[0] = 2.8026e-45;
                pdVar42[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar42[(int)local_19c[0]] = 0x1000000;
              puVar5 = *(uint **)(param_1 + 0x7c);
              *puVar5 = ((int)pdVar42 - (int)puVar5 >> 2) + (int)local_19c[0] | *puVar5;
              iVar6 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                          *(undefined4 *)PTR_0000e694,local_b4,local_bc,1);
              if (iVar6 == 0) {
                bVar3 = true;
                *(undefined4 *)((int)local_1a8 + 0x1c) = 0;
                pdVar42 = (dword *)((int)local_1a8 + 0x20);
                *(float *)(param_1 + 0x18) = local_1a8;
                pdVar8 = (dword *)((int)local_1a8 + 0x38);
                pdVar12 = (dword *)((int)local_1a8 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_1a8 + 0x1c;
                pdVar24 = (dword *)((int)local_1a8 + 0x28);
                pdVar16 = (dword *)((int)local_1a8 + 0x2c);
                pdVar19 = (dword *)((int)local_1a8 + 0x30);
                pdVar22 = (dword *)((int)local_1a8 + 0x34);
                uVar40 = uVar41;
              }
              else {
LAB_00004b14:
                bVar3 = true;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar42 = (dword *)0x0;
                pdVar12 = &__mh_bundle_header.cputype;
                pdVar24 = &__mh_bundle_header.cpusubtype;
                pdVar16 = &__mh_bundle_header.filetype;
                pdVar19 = &__mh_bundle_header.ncmds;
                pdVar22 = &__mh_bundle_header.sizeofcmds;
                pdVar8 = &__mh_bundle_header.flags;
                uVar40 = uVar41;
              }
            }
            else {
              pdVar12 = pdVar42 + 1;
              pdVar24 = pdVar42 + 2;
              pdVar16 = pdVar42 + 3;
              pdVar19 = pdVar42 + 4;
              pdVar22 = pdVar42 + 5;
              pdVar8 = pdVar42 + 6;
              bVar3 = true;
            }
          }
          else if (uVar40 < 0x22) {
            local_19c[0] = *(float *)(param_1 + 0x18);
            local_1a8 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar42 = 0x5c8;
              local_1a8 = 2.8026e-45;
              pdVar42[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar42[(int)local_1a8] = 0x1000000;
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = ((int)pdVar42 - (int)puVar5 >> 2) + (int)local_1a8 | *puVar5;
            iVar6 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694
                                        ,local_bc,&local_1a8,1);
            if (iVar6 != 0) goto LAB_00004b14;
            bVar3 = true;
            *(undefined4 *)((int)local_19c[0] + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_19c[0];
            pdVar42 = (dword *)((int)local_19c[0] + 0x20);
            pdVar8 = (dword *)((int)local_19c[0] + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_19c[0] + 0x1c;
            pdVar12 = (dword *)((int)local_19c[0] + 0x24);
            pdVar24 = (dword *)((int)local_19c[0] + 0x28);
            pdVar16 = (dword *)((int)local_19c[0] + 0x2c);
            pdVar19 = (dword *)((int)local_19c[0] + 0x30);
            pdVar22 = (dword *)((int)local_19c[0] + 0x34);
            uVar40 = uVar41;
          }
          else {
            pdVar12 = pdVar42 + 1;
            pdVar24 = pdVar42 + 2;
            pdVar16 = pdVar42 + 3;
            pdVar19 = pdVar42 + 4;
            pdVar22 = pdVar42 + 5;
            pdVar8 = pdVar42 + 6;
            bVar3 = false;
          }
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)pdVar42 - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar42;
          *pdVar42 = 0xe000000;
          *pdVar12 = 0;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)pdVar24 - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar24;
          *pdVar24 = 0x10000000;
          *pdVar16 = *(dword *)*DAT_0000e6e4;
          *pdVar19 = DAT_0000e6e4[7];
          *pdVar22 = 6;
          if (bVar3) {
            iVar7 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar8,param_1 + 0x4c,local_d4,0,0,0,0);
            local_b8 = *(short *)(param_1 + 0x50);
            iVar13 = iVar7 + 1;
            iVar17 = iVar7 + 2;
            iVar10 = iVar7 + 0x16;
            iVar6 = iVar7 << 2;
            iVar43 = iVar7 + 3;
            iVar25 = iVar7 + 4;
            iVar11 = iVar7 + 5;
            iVar14 = iVar7 + 6;
            iVar20 = iVar7 + 7;
            iVar18 = iVar7 + 8;
            iVar26 = iVar7 + 9;
            iVar27 = iVar7 + 10;
            iVar28 = iVar7 + 0xb;
            iVar29 = iVar7 + 0xc;
            iVar30 = iVar7 + 0xd;
            iVar31 = iVar7 + 0xe;
            iVar32 = iVar7 + 0xf;
            iVar33 = iVar7 + 0x10;
            iVar34 = iVar7 + 0x11;
            iVar35 = iVar7 + 0x12;
            iVar37 = iVar7 + 0x13;
            iVar9 = iVar7 + 0x14;
            iVar7 = iVar7 + 0x15;
            local_b6 = *(short *)(param_1 + 0x52);
          }
          else {
            *pdVar8 = 0x1120;
            local_b8 = *(short *)(param_1 + 0x50);
            local_b6 = *(short *)(param_1 + 0x52);
            pdVar8[1] = (int)local_b8 - 1U & 0x7ff | (local_b6 + -1) * 0x800 & 0x3ff800U |
                        0x80000000;
            pdVar8[2] = 0x1130;
            pdVar8[3] = local_c4;
            pdVar8[4] = 0x1140;
            pdVar8[5] = *(int *)(param_1 + 0x5c) - 1U & 0x3fff |
                        ((int)local_b8 - 1U) * 0x10 & 0x8000 | (local_b6 + -1) * 0x20 & 0x10000U;
            iVar6 = 0x18;
            iVar43 = 9;
            iVar13 = 7;
            iVar25 = 10;
            iVar11 = 0xb;
            iVar17 = 8;
            iVar14 = 0xc;
            iVar20 = 0xd;
            iVar18 = 0xe;
            iVar26 = 0xf;
            iVar27 = 0x10;
            iVar28 = 0x11;
            iVar29 = 0x12;
            iVar30 = 0x13;
            iVar31 = 0x14;
            iVar32 = 0x15;
            iVar33 = 0x16;
            iVar34 = 0x17;
            iVar35 = 0x18;
            iVar37 = 0x19;
            iVar9 = 0x1a;
            iVar7 = 0x1b;
            iVar10 = 0x1c;
          }
          *(undefined4 *)((int)pdVar8 + iVar6) = 0x10f8;
          pdVar8[iVar13] = local_dc & 0x1fff | (local_e0 & 0x1fff) << 0xd;
          pdVar8[iVar17] = 0x10f9;
          pdVar8[iVar43] = local_e4 & 0x1fff | (local_e8 & 0x1fff) << 0xd;
          pdVar8[iVar25] = 0xc00c3500;
          pdVar8[iVar11] = 0x4003d;
          uStack_134 = (int)local_b8 ^ 0x80000000;
          uStack_124 = (int)local_b6 ^ 0x80000000;
          local_138 = 0x43300000;
          local_128 = 0x43300000;
          dVar47 = 1.0 / ((double)CONCAT44(0x43300000,uStack_134) - 4503601774854144.0);
          dVar45 = 1.0 / ((double)CONCAT44(0x43300000,uStack_124) - 4503601774854144.0);
          local_1a4 = (float)(dVar50 * dVar47);
          local_19c[0] = (float)(dVar51 * dVar45);
          local_1a0 = (float)(dVar48 * dVar47);
          local_1a8 = (float)(dVar49 * dVar45);
          pdVar8[iVar14] = local_dc | local_e8 << 0x10;
          fVar21 = *local_c0;
          pdVar8[iVar20] = (dword)fVar21;
          fVar15 = *local_bc;
          pdVar8[iVar18] = (dword)fVar15;
          pdVar8[iVar26] = local_dc | local_e0 << 0x10;
          pdVar8[iVar27] = (dword)fVar21;
          fVar21 = *local_b4;
          pdVar8[iVar28] = (dword)fVar21;
          pdVar8[iVar29] = local_e4 | local_e0 << 0x10;
          fVar23 = *local_b0;
          pdVar8[iVar30] = (dword)fVar23;
          pdVar8[iVar31] = (dword)fVar21;
          pdVar8[iVar32] = local_e4 | local_e8 << 0x10;
          pdVar8[iVar33] = (dword)fVar23;
          pdVar8[iVar34] = (dword)fVar15;
          pdVar8[iVar35] = 0x1393;
          pdVar8[iVar37] = 10;
          pdVar8[iVar9] = 0x5c8;
          pdVar8[iVar7] = 0x20000;
          uVar40 = (uVar40 - 6) - iVar10;
          iVar6 = local_ac[5];
          uVar38 = local_ac[2] + *(int *)(param_1 + 0x60);
          iVar7 = local_ac[3] + *(int *)(param_1 + 100);
          uVar36 = uVar38 + local_ac[4];
          pdVar8 = pdVar8 + iVar10;
          if (uVar40 < 0x22) {
            local_1a4 = *(float *)(param_1 + 0x18);
            local_1a0 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar8 = 0x5c8;
              local_1a0 = 2.8026e-45;
              pdVar8[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar8[(int)local_1a0] = 0x1000000;
            puVar4 = PTR_0000e694;
            puVar5 = *(uint **)(param_1 + 0x7c);
            *puVar5 = ((int)pdVar8 - (int)puVar5 >> 2) + (int)local_1a0 | *puVar5;
            iVar9 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar4,
                                        local_b0,local_c0,1);
            uVar40 = uVar41;
            if (iVar9 == 0) {
              bVar3 = true;
              *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_1a4;
              pdVar8 = (dword *)((int)local_1a4 + 0x20);
              pdVar42 = (dword *)((int)local_1a4 + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
              pdVar12 = (dword *)((int)local_1a4 + 0x24);
              pdVar16 = (dword *)((int)local_1a4 + 0x28);
              pdVar19 = (dword *)((int)local_1a4 + 0x2c);
              pdVar24 = (dword *)((int)local_1a4 + 0x30);
              pdVar22 = (dword *)((int)local_1a4 + 0x34);
            }
            else {
              bVar3 = true;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar8 = (dword *)0x0;
              pdVar12 = &__mh_bundle_header.cputype;
              pdVar16 = &__mh_bundle_header.cpusubtype;
              pdVar19 = &__mh_bundle_header.filetype;
              pdVar24 = &__mh_bundle_header.ncmds;
              pdVar22 = &__mh_bundle_header.sizeofcmds;
              pdVar42 = &__mh_bundle_header.flags;
            }
          }
          else {
            pdVar12 = pdVar8 + 1;
            pdVar16 = pdVar8 + 2;
            pdVar19 = pdVar8 + 3;
            pdVar24 = pdVar8 + 4;
            pdVar22 = pdVar8 + 5;
            pdVar42 = pdVar8 + 6;
            bVar3 = false;
          }
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)pdVar8 - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar8;
          *pdVar8 = 0x12000000;
          *pdVar12 = 0;
          *pdVar16 = 0;
          *pdVar19 = 0;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = (int)pdVar24 - (int)puVar5 >> 2 | *puVar5;
          *(dword **)(param_1 + 0x7c) = pdVar24;
          *pdVar24 = 0x4000000;
          *pdVar22 = *(dword *)*DAT_0000e6e4;
          if (bVar3) {
            iVar11 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar42,local_cc,local_d8,0,0,0,0);
            local_ec = iVar11 + 1;
            iVar26 = iVar11 + 9;
            local_f4 = iVar11 + 3;
            local_f8 = iVar11 + 4;
            iVar10 = iVar11 + 10;
            local_f0 = iVar11 + 2;
            iVar14 = iVar11 + 0x16;
            iVar9 = iVar11 << 2;
            iVar17 = iVar11 + 5;
            iVar25 = iVar11 + 6;
            iVar18 = iVar11 + 7;
            iVar20 = iVar11 + 8;
            iVar28 = iVar11 + 0xb;
            iVar29 = iVar11 + 0xc;
            iVar30 = iVar11 + 0xd;
            iVar31 = iVar11 + 0xe;
            iVar32 = iVar11 + 0xf;
            iVar33 = iVar11 + 0x10;
            iVar34 = iVar11 + 0x11;
            iVar35 = iVar11 + 0x12;
            iVar27 = iVar11 + 0x13;
            iVar13 = iVar11 + 0x14;
            iVar11 = iVar11 + 0x15;
          }
          else {
            *pdVar42 = 0x1120;
            sVar1 = *(short *)(local_cc + 1);
            iVar9 = *(short *)((int)local_cc + 6) + -1;
            pdVar42[1] = (int)sVar1 - 1U & 0x7ff | iVar9 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar42[2] = 0x1130;
            pdVar42[3] = local_d8 & 0x1f | 0x53000;
            pdVar42[4] = 0x1140;
            pdVar42[5] = local_cc[4] - 1 & 0x3fff | ((int)sVar1 - 1U) * 0x10 & 0x8000 |
                         iVar9 * 0x20 & 0x10000U;
            local_f8 = 10;
            local_f0 = 8;
            iVar9 = 0x18;
            local_f4 = 9;
            local_ec = 7;
            iVar26 = 0xf;
            iVar17 = 0xb;
            iVar25 = 0xc;
            iVar18 = 0xd;
            iVar10 = 0x10;
            iVar20 = 0xe;
            iVar28 = 0x11;
            iVar29 = 0x12;
            iVar30 = 0x13;
            iVar31 = 0x14;
            iVar32 = 0x15;
            iVar33 = 0x16;
            iVar34 = 0x17;
            iVar35 = 0x18;
            iVar27 = 0x19;
            iVar13 = 0x1a;
            iVar11 = 0x1b;
            iVar14 = 0x1c;
          }
          *(undefined4 *)((int)pdVar42 + iVar9) = 0x10f8;
          pdVar42[local_ec] = uVar38 & 0x1fff | iVar7 * 0x2000 & 0x3ffe000U;
          pdVar42[local_f0] = 0x10f9;
          pdVar42[local_f4] = uVar36 & 0x1fff | (iVar7 + iVar6) * 0x2000 & 0x3ffe000U;
          pdVar42[local_f8] = 0xc00c3500;
          pdVar42[iVar17] = 0x4003d;
          uVar2 = (iVar7 + iVar6) * 0x10000;
          local_118 = 0x43300000;
          uStack_114 = (int)*(short *)(local_cc + 1) ^ 0x80000000;
          local_1a8 = (float)(dVar48 * (1.0 / ((double)CONCAT44(0x43300000,uStack_114) -
                                              4503601774854144.0)));
          local_110 = 0x43300000;
          uStack_10c = (int)*(short *)(local_cc + 1) ^ 0x80000000;
          local_19c[0] = (float)(dVar50 * (1.0 / ((double)CONCAT44(0x43300000,uStack_10c) -
                                                 4503601774854144.0)));
          local_108 = 0x43300000;
          uStack_104 = (int)*(short *)((int)local_cc + 6) ^ 0x80000000;
          local_1a0 = (float)(dVar49 * (1.0 / ((double)CONCAT44(0x43300000,uStack_104) -
                                              4503601774854144.0)));
          local_100 = 0x43300000;
          uStack_fc = (int)*(short *)((int)local_cc + 6) ^ 0x80000000;
          local_1a4 = (float)(dVar51 * (1.0 / ((double)CONCAT44(0x43300000,uStack_fc) -
                                              4503601774854144.0)));
          pdVar42[iVar25] = uVar38 | uVar2;
          fVar21 = *local_b4;
          pdVar42[iVar18] = (dword)fVar21;
          fVar15 = *local_b0;
          pdVar42[iVar20] = (dword)fVar15;
          pdVar42[iVar26] = uVar38 | iVar7 * 0x10000;
          pdVar42[iVar10] = (dword)fVar21;
          fVar21 = *local_c0;
          pdVar42[iVar28] = (dword)fVar21;
          pdVar42[iVar29] = uVar36 | iVar7 * 0x10000;
          fVar23 = *local_bc;
          pdVar42[iVar30] = (dword)fVar23;
          pdVar42[iVar31] = (dword)fVar21;
          pdVar42[iVar32] = uVar36 | uVar2;
          pdVar42[iVar33] = (dword)fVar23;
          pdVar42[iVar34] = (dword)fVar15;
          pdVar42[iVar35] = 0x1393;
          pdVar42[iVar27] = 10;
          pdVar42[iVar13] = 0x5c8;
          pdVar42[iVar11] = 0x20000;
          uVar40 = (uVar40 - 6) - iVar14;
          pdVar42 = pdVar42 + iVar14;
          local_d0 = local_d0 + 1;
          local_ac = local_ac + 6;
          bVar3 = false;
        } while (iVar39 != local_d0);
      }
      *(dword **)(param_1 + 0x80) = pdVar42;
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
  float fVar3;
  float fVar4;
  short sVar5;
  uint uVar6;
  float fVar7;
  bool bVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  int iVar17;
  float fVar18;
  dword *pdVar19;
  int iVar20;
  dword *pdVar21;
  int iVar22;
  dword dVar23;
  int iVar24;
  float fVar25;
  dword *pdVar26;
  float fVar27;
  dword *pdVar28;
  dword dVar29;
  float fVar30;
  float fVar31;
  dword *pdVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  uint uVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  int iVar43;
  uint uVar44;
  int iVar45;
  int iVar46;
  uint uVar47;
  int iVar48;
  int iVar49;
  uint uVar50;
  dword *pdVar51;
  dword *pdVar52;
  int *piVar53;
  uint uVar54;
  int iVar55;
  int iVar56;
  int iVar57;
  double dVar58;
  double dVar59;
  double dVar60;
  double dVar61;
  double dVar62;
  double dVar63;
  double dVar64;
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
  
  uVar54 = param_4 & 0x7ffff000;
  pdVar52 = *(dword **)(param_1 + 0x80);
  iVar55 = *(int *)(param_1 + 0x18);
  piVar53 = *(int **)(param_5 + 0x60);
  iVar10 = *(int *)(iVar55 + 0x10);
  iVar37 = *piVar53;
  uVar38 = iVar10 - 7;
  if (pdVar52 == (dword *)0x0) {
LAB_000081e0:
    iVar10 = -0x1ffffd42;
  }
  else {
    bVar1 = uVar54 == 0x1000;
    if (bVar1) {
      local_fc = *(dword *)(param_1 + 0x84);
      local_d8 = (dword *)(param_1 + 0x1c);
      local_ec = *(int *)(param_1 + 0x30);
      iVar22 = 0x9000000;
      local_f0 = *(int *)(param_1 + 0x34);
LAB_000056ac:
      local_348 = *(short *)(local_d8 + 1);
      if ((0x1000 < local_348) || (0x1000 < *(short *)((int)local_d8 + 6))) {
        return -0x1ffffd39;
      }
      local_140 = iVar22 + 0x1000000;
    }
    else {
      if (uVar54 < 0x1001) {
        if (uVar54 != 0) {
          return -0x1ffffd44;
        }
        local_d8 = (dword *)(param_1 + 0x4c);
        local_ec = 0;
        local_f0 = 0;
        local_fc = 0;
        iVar22 = 0xd000000;
        goto LAB_000056ac;
      }
      if (uVar54 == 0x3000) {
        puVar11 = *(undefined4 **)(param_6 + 0x28);
        local_ec = 0;
        local_f0 = 0;
        local_d8 = puVar11 + 3;
        local_140 = 0x8000000;
        local_fc = *(dword *)*puVar11;
        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + 1;
        local_348 = *(short *)(puVar11 + 4);
      }
      else {
        if (uVar54 != 0x7000) {
          return -0x1ffffd44;
        }
        local_354[1] = 0x800;
        local_368 = 0x30;
        local_354[0] = param_6;
        local_fc = param_6;
        iVar22 = _io_connect_method_scalarI_structureO
                           (*(undefined4 *)(param_1 + 0xc),2,local_354,2,local_354 + 2,&local_368);
        if (iVar22 != 0) {
          return iVar22;
        }
        local_ec = 0;
        local_f0 = 0;
        local_140 = 0xc000000;
        local_d8 = local_354 + 2;
      }
    }
    puVar9 = PTR_0000e694;
    local_d4 = piVar53 + 3;
    if (iVar37 == 0) {
      local_d4 = piVar53 + 1;
      iVar37 = 1;
    }
    local_e8 = *(int *)(param_5 + 0x5c) - (int)*(short *)((int)piVar53 + 6);
    dStack_304 = local_d8[2];
    dVar29 = local_d8[4];
    local_e4 = *(int *)(param_5 + 0x58) - (int)*(short *)(piVar53 + 1);
    dVar23 = local_d8[7];
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
    fVar18 = (float)((double)CONCAT44(0x43300000,uStack_314) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,dStack_304) - 4503599627370496.0);
    fVar25 = (float)((double)CONCAT44(0x43300000,uStack_30c) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,dStack_2fc) - 4503599627370496.0);
    uVar47 = uVar38 - ((int)pdVar52 - (iVar55 + 0x20) >> 2);
    while (((uint)pdVar52 & 0x1f) != 0) {
      if (uVar47 == 0) {
        local_364 = *(float *)(param_1 + 0x18);
        local_360 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *pdVar52 = 0x5c8;
          local_360 = 2.8026e-45;
          pdVar52[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        pdVar52[(int)local_360] = 0x1000000;
        puVar12 = *(uint **)(param_1 + 0x7c);
        *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_360 | *puVar12;
        iVar55 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar9,
                                     &local_364,&local_360,1);
        if (iVar55 == 0) {
          *(undefined4 *)((int)local_364 + 0x1c) = 0;
          *(float *)(param_1 + 0x18) = local_364;
          pdVar52 = (dword *)((int)local_364 + 0x20);
          *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
          uVar47 = uVar38;
        }
        else {
          pdVar52 = (dword *)0x0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          *(undefined4 *)(param_1 + 0x18) = 0;
          uVar47 = uVar38;
        }
      }
      else {
        *pdVar52 = 0x80000000;
        pdVar52 = pdVar52 + 1;
        uVar47 = uVar47 - 1;
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
    iVar55 = (int)*(short *)(local_d8 + 1);
    if (((bVar1) || (uVar54 == 0)) && (*(int *)(param_1 + 0x8c) == 0)) {
      iVar10 = ((int (*)())_createOffscreenBuffer)(param_1,local_d8,0);
      if (iVar10 == 0) goto LAB_000081e0;
      local_dc = DAT_0000e6e4 + 3;
      local_f8 = DAT_0000e6e4[0xc];
      if (local_f8 == 3) {
        local_f8 = 0xb;
      }
      else if (local_f8 == 6) {
        local_f8 = 0xc;
      }
      if (iVar37 != 0) {
        local_ac = &local_358;
        local_b8 = &local_364;
        local_b4 = &local_360;
        local_c8 = 0xc000;
        local_a8 = local_d4;
        local_b0 = &local_35c;
        local_e0 = 0;
        bVar8 = true;
        local_c4 = local_f4 & 0x1f | 0x53000;
        do {
          local_2f8 = 0x43300000;
          uStack_2f4 = local_ec + *(short *)local_a8 ^ 0x80000000;
          local_2f0 = 0x43300000;
          uStack_2ec = local_f0 + (short)*local_a8 ^ 0x80000000;
          dVar58 = (double)CONCAT44(0x43300000,uStack_2f4) - 4503601774854144.0;
          local_2e8 = 0x43300000;
          uStack_2e4 = (int)*(short *)(local_a8 + 1) ^ 0x80000000;
          dVar61 = (double)(float)dVar58;
          local_2e0 = 0x43300000;
          dVar59 = (double)CONCAT44(0x43300000,uStack_2ec) - 4503601774854144.0;
          uStack_2dc = (int)*(short *)((int)local_a8 + 6) ^ 0x80000000;
          dVar62 = (double)(float)dVar59;
          dVar60 = dVar61 + (double)(float)((double)CONCAT44(0x43300000,uStack_2e4) -
                                           4503601774854144.0);
          dVar63 = (double)(float)dVar60;
          dVar2 = dVar62 + (double)(float)((double)CONCAT44(0x43300000,uStack_2dc) -
                                          4503601774854144.0);
          dVar64 = (double)(float)dVar2;
          if (2147483648.0 <= dVar61) {
            local_2d0 = (longlong)(int)(dVar61 - 2147483648.0);
            local_104 = (int)(dVar61 - 2147483648.0) + 0x80000000;
          }
          else {
            local_104 = (uint)dVar58;
            local_2d8 = (longlong)(int)local_104;
          }
          if (2147483648.0 <= dVar62) {
            local_2c0 = (longlong)(int)(dVar62 - 2147483648.0);
            local_108 = (int)(dVar62 - 2147483648.0) + 0x80000000;
          }
          else {
            local_108 = (uint)dVar59;
            local_2c8 = (longlong)(int)local_108;
          }
          if (2147483648.0 <= dVar63) {
            local_2b0 = (longlong)(int)(dVar63 - 2147483648.0);
            local_10c = (int)(dVar63 - 2147483648.0) + 0x80000000;
          }
          else {
            local_10c = (uint)dVar60;
            local_2b8 = (longlong)(int)local_10c;
          }
          if (2147483648.0 <= dVar64) {
            local_2a0 = (longlong)(int)(dVar64 - 2147483648.0);
            local_110 = (int)(dVar64 - 2147483648.0) + 0x80000000;
          }
          else {
            local_110 = (uint)dVar2;
            local_2a8 = (longlong)(int)local_110;
          }
          if (bVar8) {
            if (uVar47 < 0x8a) {
              local_360 = *(float *)(param_1 + 0x18);
              local_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar52 = 0x5c8;
                local_364 = 2.8026e-45;
                pdVar52[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar52[(int)local_364] = 0x1000000;
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_364 | *puVar12;
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,local_b4,local_b8,1);
              if (iVar10 == 0) {
                *(undefined4 *)((int)local_360 + 0x1c) = 0;
                pdVar52 = (dword *)((int)local_360 + 0x20);
                *(float *)(param_1 + 0x18) = local_360;
                pdVar26 = (dword *)((int)local_360 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
              }
              else {
LAB_00005e40:
                pdVar52 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar26 = &__mh_bundle_header.cputype;
              }
LAB_00005e7c:
              bVar8 = true;
              uVar47 = uVar38;
            }
            else {
              pdVar26 = pdVar52 + 1;
              bVar8 = true;
            }
          }
          else {
            if (uVar47 < 0x22) {
              local_364 = *(float *)(param_1 + 0x18);
              local_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar52 = 0x5c8;
                local_360 = 2.8026e-45;
                pdVar52[1] = local_c8;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar52[(int)local_360] = 0x1000000;
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_360 | *puVar12;
              iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,local_b8,local_b4,1);
              if (iVar10 != 0) goto LAB_00005e40;
              *(undefined4 *)((int)local_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_364;
              pdVar52 = (dword *)((int)local_364 + 0x20);
              pdVar26 = (dword *)((int)local_364 + 0x24);
              *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
              goto LAB_00005e7c;
            }
            pdVar26 = pdVar52 + 1;
            bVar8 = false;
          }
          if (bVar1) {
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = 0xa000000;
          }
          else {
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = 0xe000000;
          }
          pdVar52 = pdVar26 + 5;
          *pdVar26 = local_fc;
          puVar12 = *(uint **)(param_1 + 0x7c);
          *puVar12 = (int)(pdVar26 + 1) - (int)puVar12 >> 2 | *puVar12;
          *(dword **)(param_1 + 0x7c) = pdVar26 + 1;
          pdVar26[1] = 0x10000000;
          pdVar26[2] = *(dword *)*DAT_0000e6e4;
          dVar23 = DAT_0000e6e4[7];
          pdVar26[4] = 6;
          pdVar26[3] = dVar23;
          if (bVar8) {
            iVar22 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_d8,local_f4,0,0,0,0);
            iVar55 = iVar22 + 1;
            iVar14 = iVar22 + 0x16;
            iVar10 = iVar22 << 2;
            iVar56 = iVar22 + 2;
            iVar33 = iVar22 + 3;
            iVar34 = iVar22 + 4;
            iVar15 = iVar22 + 5;
            iVar24 = iVar22 + 6;
            iVar17 = iVar22 + 7;
            iVar20 = iVar22 + 8;
            iVar35 = iVar22 + 9;
            iVar36 = iVar22 + 10;
            iVar39 = iVar22 + 0xb;
            iVar40 = iVar22 + 0xc;
            iVar41 = iVar22 + 0xd;
            iVar42 = iVar22 + 0xe;
            iVar43 = iVar22 + 0xf;
            iVar45 = iVar22 + 0x10;
            iVar46 = iVar22 + 0x11;
            iVar48 = iVar22 + 0x12;
            iVar49 = iVar22 + 0x13;
            iVar13 = iVar22 + 0x14;
            iVar22 = iVar22 + 0x15;
          }
          else {
            *pdVar52 = 0x1120;
            sVar5 = *(short *)(local_d8 + 1);
            iVar10 = *(short *)((int)local_d8 + 6) + -1;
            pdVar26[6] = (int)sVar5 - 1U & 0x7ff | iVar10 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar26[7] = 0x1130;
            pdVar26[8] = local_c4;
            pdVar26[9] = 0x1140;
            pdVar26[10] = local_d8[4] - 1 & 0x3fff | ((int)sVar5 - 1U) * 0x10 & 0x8000 |
                          iVar10 * 0x20 & 0x10000U;
            iVar10 = 0x18;
            iVar56 = 8;
            iVar33 = 9;
            iVar55 = 7;
            iVar34 = 10;
            iVar15 = 0xb;
            iVar24 = 0xc;
            iVar17 = 0xd;
            iVar20 = 0xe;
            iVar35 = 0xf;
            iVar36 = 0x10;
            iVar39 = 0x11;
            iVar40 = 0x12;
            iVar41 = 0x13;
            iVar42 = 0x14;
            iVar43 = 0x15;
            iVar45 = 0x16;
            iVar46 = 0x17;
            iVar48 = 0x18;
            iVar49 = 0x19;
            iVar13 = 0x1a;
            iVar22 = 0x1b;
            iVar14 = 0x1c;
          }
          *(undefined4 *)((int)pdVar52 + iVar10) = 0x10f8;
          pdVar52[iVar55] = local_104 & 0x1fff | (local_108 & 0x1fff) << 0xd;
          pdVar52[iVar56] = 0x10f9;
          pdVar52[iVar33] = local_10c & 0x1fff | (local_110 & 0x1fff) << 0xd;
          pdVar52[iVar34] = 0xc00c3500;
          pdVar52[iVar15] = 0x4003d;
          local_298 = 0x43300000;
          uStack_294 = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          local_358 = (float)(dVar61 * (1.0 / ((double)CONCAT44(0x43300000,uStack_294) -
                                              4503601774854144.0)));
          local_290 = 0x43300000;
          uStack_28c = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          local_35c = (float)(dVar63 * (1.0 / ((double)CONCAT44(0x43300000,uStack_28c) -
                                              4503601774854144.0)));
          local_288 = 0x43300000;
          uStack_284 = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
          local_360 = (float)(dVar62 * (1.0 / ((double)CONCAT44(0x43300000,uStack_284) -
                                              4503601774854144.0)));
          local_280 = 0x43300000;
          uStack_27c = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
          local_364 = (float)(dVar64 * (1.0 / ((double)CONCAT44(0x43300000,uStack_27c) -
                                              4503601774854144.0)));
          pdVar52[iVar24] = local_104 | local_110 << 0x10;
          fVar25 = *local_ac;
          pdVar52[iVar17] = (dword)fVar25;
          fVar18 = *local_b8;
          pdVar52[iVar20] = (dword)fVar18;
          pdVar52[iVar35] = local_104 | local_108 << 0x10;
          pdVar52[iVar36] = (dword)fVar25;
          fVar25 = *local_b4;
          pdVar52[iVar39] = (dword)fVar25;
          pdVar52[iVar40] = local_10c | local_108 << 0x10;
          fVar30 = *local_b0;
          pdVar52[iVar41] = (dword)fVar30;
          pdVar52[iVar42] = (dword)fVar25;
          pdVar52[iVar43] = local_10c | local_110 << 0x10;
          pdVar52[iVar45] = (dword)fVar30;
          pdVar52[iVar46] = (dword)fVar18;
          pdVar52[iVar48] = 0x1393;
          pdVar52[iVar49] = 10;
          pdVar52[iVar13] = 0x5c8;
          pdVar52[iVar22] = 0x20000;
          uVar54 = (uVar47 - 6) - iVar14;
          pdVar52 = pdVar52 + iVar14;
          uVar50 = local_e4 + *(short *)local_a8;
          uVar47 = uVar50 + (int)*(short *)(local_a8 + 1);
          iVar55 = local_e8 + (short)*local_a8;
          iVar10 = iVar55 + *(short *)((int)local_a8 + 6);
          if (uVar54 < 0x22) {
            local_35c = *(float *)(param_1 + 0x18);
            local_358 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar52 = 0x5c8;
              local_358 = 2.8026e-45;
              pdVar52[1] = local_c8;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar9 = PTR_0000e694;
            pdVar52[(int)local_358] = 0x1000000;
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_358 | *puVar12;
            iVar22 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar9,
                                         local_b0,local_ac,1);
            if (iVar22 == 0) {
              *(undefined4 *)((int)local_35c + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_35c;
              pdVar52 = (dword *)((int)local_35c + 0x20);
              pdVar26 = (dword *)((int)local_35c + 0x24);
              *(int *)(param_1 + 0x7c) = (int)local_35c + 0x1c;
            }
            else {
              pdVar52 = (dword *)0x0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar26 = &__mh_bundle_header.cputype;
            }
            bVar8 = true;
            uVar54 = uVar38;
          }
          else {
            pdVar26 = pdVar52 + 1;
            bVar8 = false;
          }
          if (bVar1) {
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = 0x11000000;
          }
          else {
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = 0x12000000;
          }
          pdVar26[1] = 0;
          pdVar26[2] = 0;
          pdVar52 = pdVar26 + 5;
          *pdVar26 = local_fc;
          puVar12 = *(uint **)(param_1 + 0x7c);
          *puVar12 = (int)(pdVar26 + 3) - (int)puVar12 >> 2 | *puVar12;
          *(dword **)(param_1 + 0x7c) = pdVar26 + 3;
          pdVar26[3] = 0x4000000;
          pdVar26[4] = *(dword *)*DAT_0000e6e4;
          if (bVar8) {
            iVar13 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar52,local_dc,local_f8,0,0,0,0);
            iVar24 = iVar13 + 4;
            iVar35 = iVar13 + 9;
            local_15c = iVar13 + 3;
            local_154 = iVar13 + 1;
            local_158 = iVar13 + 2;
            iVar15 = iVar13 + 0x16;
            iVar22 = iVar13 << 2;
            iVar17 = iVar13 + 5;
            iVar34 = iVar13 + 6;
            iVar20 = iVar13 + 7;
            iVar33 = iVar13 + 8;
            iVar49 = iVar13 + 10;
            iVar36 = iVar13 + 0xb;
            iVar39 = iVar13 + 0xc;
            iVar40 = iVar13 + 0xd;
            iVar41 = iVar13 + 0xe;
            iVar42 = iVar13 + 0xf;
            iVar43 = iVar13 + 0x10;
            iVar45 = iVar13 + 0x11;
            iVar46 = iVar13 + 0x12;
            iVar48 = iVar13 + 0x13;
            iVar14 = iVar13 + 0x14;
            iVar13 = iVar13 + 0x15;
          }
          else {
            *pdVar52 = 0x1120;
            sVar5 = *(short *)(local_dc + 1);
            iVar22 = *(short *)((int)local_dc + 6) + -1;
            pdVar26[6] = (int)sVar5 - 1U & 0x7ff | iVar22 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar26[7] = 0x1130;
            pdVar26[8] = local_f8 & 0x1f | 0x53000;
            pdVar26[9] = 0x1140;
            pdVar26[10] = local_dc[4] - 1 & 0x3fff | ((int)sVar5 - 1U) * 0x10 & 0x8000 |
                          iVar22 * 0x20 & 0x10000U;
            iVar24 = 10;
            local_15c = 9;
            iVar22 = 0x18;
            iVar35 = 0xf;
            local_154 = 7;
            iVar17 = 0xb;
            local_158 = 8;
            iVar20 = 0xd;
            iVar34 = 0xc;
            iVar33 = 0xe;
            iVar49 = 0x10;
            iVar36 = 0x11;
            iVar39 = 0x12;
            iVar40 = 0x13;
            iVar41 = 0x14;
            iVar42 = 0x15;
            iVar43 = 0x16;
            iVar45 = 0x17;
            iVar46 = 0x18;
            iVar48 = 0x19;
            iVar14 = 0x1a;
            iVar13 = 0x1b;
            iVar15 = 0x1c;
          }
          *(undefined4 *)((int)pdVar52 + iVar22) = 0x10f8;
          pdVar52[local_154] = uVar50 & 0x1fff | iVar55 * 0x2000 & 0x3ffe000U;
          pdVar52[local_158] = 0x10f9;
          pdVar52[local_15c] = uVar47 & 0x1fff | iVar10 * 0x2000 & 0x3ffe000U;
          pdVar52[iVar24] = 0xc00c3500;
          pdVar52[iVar17] = 0x4003d;
          uVar44 = iVar10 * 0x10000;
          local_278 = 0x43300000;
          uStack_274 = (int)*(short *)(local_dc + 1) ^ 0x80000000;
          local_364 = (float)(dVar61 * (1.0 / ((double)CONCAT44(0x43300000,uStack_274) -
                                              4503601774854144.0)));
          local_270 = 0x43300000;
          uStack_26c = (int)*(short *)(local_dc + 1) ^ 0x80000000;
          local_360 = (float)(dVar63 * (1.0 / ((double)CONCAT44(0x43300000,uStack_26c) -
                                              4503601774854144.0)));
          local_268 = 0x43300000;
          uStack_264 = (int)*(short *)((int)local_dc + 6) ^ 0x80000000;
          local_358 = (float)(dVar62 * (1.0 / ((double)CONCAT44(0x43300000,uStack_264) -
                                              4503601774854144.0)));
          local_260 = 0x43300000;
          uStack_25c = (int)*(short *)((int)local_dc + 6) ^ 0x80000000;
          local_35c = (float)(dVar64 * (1.0 / ((double)CONCAT44(0x43300000,uStack_25c) -
                                              4503601774854144.0)));
          pdVar52[iVar34] = uVar50 | uVar44;
          fVar25 = *local_b8;
          pdVar52[iVar20] = (dword)fVar25;
          fVar18 = *local_b0;
          pdVar52[iVar33] = (dword)fVar18;
          pdVar52[iVar35] = uVar50 | iVar55 * 0x10000;
          pdVar52[iVar49] = (dword)fVar25;
          fVar25 = *local_ac;
          pdVar52[iVar36] = (dword)fVar25;
          pdVar52[iVar39] = uVar47 | iVar55 * 0x10000;
          fVar30 = *local_b4;
          pdVar52[iVar40] = (dword)fVar30;
          pdVar52[iVar41] = (dword)fVar25;
          pdVar52[iVar42] = uVar47 | uVar44;
          pdVar52[iVar43] = (dword)fVar30;
          pdVar52[iVar45] = (dword)fVar18;
          pdVar52[iVar46] = 0x1393;
          pdVar52[iVar48] = 10;
          pdVar52[iVar14] = 0x5c8;
          pdVar52[iVar13] = 0x20000;
          uVar47 = (uVar54 - 6) - iVar15;
          pdVar52 = pdVar52 + iVar15;
          local_e0 = local_e0 + 1;
          local_a8 = local_a8 + 2;
          bVar8 = false;
        } while (iVar37 != local_e0);
      }
    }
    else if (iVar55 < 0x1001) {
      if (iVar37 != 0) {
        local_114 = dVar29 * dVar23 * 0x1000;
        local_b0 = &local_35c;
        local_b8 = &local_364;
        local_b4 = &local_360;
        local_ac = &local_358;
        local_170 = 0;
        bVar1 = true;
        piVar53 = local_d4;
        do {
          local_160 = (short *)((int)piVar53 + 2);
          local_164 = (short *)((int)piVar53 + 6);
          local_258 = 0x43300000;
          uStack_254 = local_ec + *(short *)piVar53 ^ 0x80000000;
          uVar50 = local_e4 + *(short *)piVar53;
          local_250 = 0x43300000;
          iVar55 = local_e8 + (short)*piVar53;
          uStack_24c = local_f0 + (short)*piVar53 ^ 0x80000000;
          local_248 = 0x43300000;
          uStack_244 = (int)*(short *)(piVar53 + 1) ^ 0x80000000;
          uVar54 = uVar50 + (int)*(short *)(piVar53 + 1);
          fVar30 = (float)((double)CONCAT44(0x43300000,uStack_254) - 4503601774854144.0);
          local_240 = 0x43300000;
          uStack_23c = (int)*(short *)((int)piVar53 + 6) ^ 0x80000000;
          uVar44 = iVar55 + *(short *)((int)piVar53 + 6);
          fVar3 = (float)((double)CONCAT44(0x43300000,uStack_24c) - 4503601774854144.0);
          iVar10 = (int)*(short *)((int)local_d8 + 6);
          fVar4 = fVar3 + (float)((double)CONCAT44(0x43300000,uStack_23c) - 4503601774854144.0);
          if (iVar10 < 0x1000) {
            local_238 = 0x43300000;
            fVar16 = (float)((double)CONCAT44(0x43300000,iVar10) - 4503599627370496.0);
            iStack_234 = iVar10;
          }
          else {
            fVar16 = 4096.0;
            if (4096.0 <= fVar4) {
              iVar10 = 0x1000;
              uVar44 = local_e8 + 0x1000;
              fVar4 = fVar16;
            }
            else {
              iVar10 = 0x1000;
            }
          }
          local_230 = 0x43300000;
          uStack_22c = (int)*(short *)(local_d8 + 1) ^ 0x80000000;
          fVar16 = fVar25 * (1.0 / fVar16);
          fVar4 = fVar4 * fVar16;
          fVar3 = fVar3 * fVar16;
          fVar16 = fVar18 * (1.0 / (float)((double)CONCAT44(0x43300000,uStack_22c) -
                                          4503601774854144.0));
          fVar7 = (fVar30 + (float)((double)CONCAT44(0x43300000,uStack_244) - 4503601774854144.0)) *
                  fVar16;
          fVar30 = fVar30 * fVar16;
          if (bVar1) {
            if (uVar47 < 0x8a) {
              local_360 = *(float *)(param_1 + 0x18);
              local_364 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar52 = 0x5c8;
                local_364 = 2.8026e-45;
                pdVar52[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar52[(int)local_364] = 0x1000000;
              puVar9 = PTR_0000e694;
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_364 | *puVar12;
              iVar22 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar9,
                                           local_b4,local_b8,1);
              if (iVar22 == 0) {
                *(undefined4 *)((int)local_360 + 0x1c) = 0;
                pdVar52 = (dword *)((int)local_360 + 0x20);
                *(float *)(param_1 + 0x18) = local_360;
                pdVar51 = (dword *)((int)local_360 + 0x38);
                pdVar26 = (dword *)((int)local_360 + 0x24);
                *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
                pdVar19 = (dword *)((int)local_360 + 0x28);
                pdVar21 = (dword *)((int)local_360 + 0x2c);
                pdVar28 = (dword *)((int)local_360 + 0x30);
                pdVar32 = (dword *)((int)local_360 + 0x34);
                uVar47 = uVar38;
              }
              else {
LAB_00006cc0:
                pdVar52 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar26 = &__mh_bundle_header.cputype;
                pdVar19 = &__mh_bundle_header.cpusubtype;
                pdVar21 = &__mh_bundle_header.filetype;
                pdVar28 = &__mh_bundle_header.ncmds;
                pdVar32 = &__mh_bundle_header.sizeofcmds;
                pdVar51 = &__mh_bundle_header.flags;
                uVar47 = uVar38;
              }
            }
            else {
              pdVar26 = pdVar52 + 1;
              pdVar19 = pdVar52 + 2;
              pdVar21 = pdVar52 + 3;
              pdVar28 = pdVar52 + 4;
              pdVar32 = pdVar52 + 5;
              pdVar51 = pdVar52 + 6;
            }
LAB_00006d28:
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = local_140;
            *pdVar26 = local_fc;
            *pdVar19 = local_100;
            *pdVar21 = 0;
            *pdVar28 = 0;
            *pdVar32 = 0;
            uVar47 = uVar47 - 6;
            iVar14 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,0,iVar10);
            local_148 = iVar14 + 0xe;
            local_14c = iVar14 + 0xf;
            iVar17 = iVar14 + 0x16;
            iVar10 = iVar14 << 2;
            local_150 = iVar14 + 0x10;
            iVar13 = iVar14 + 0x11;
            iVar22 = iVar14 + 0x12;
            iVar34 = iVar14 + 1;
            iVar35 = iVar14 + 2;
            iVar33 = iVar14 + 3;
            iVar20 = iVar14 + 4;
            iVar24 = iVar14 + 5;
            iVar39 = iVar14 + 6;
            iVar40 = iVar14 + 7;
            iVar41 = iVar14 + 8;
            iVar42 = iVar14 + 9;
            iVar43 = iVar14 + 10;
            iVar45 = iVar14 + 0xb;
            iVar46 = iVar14 + 0xc;
            iVar15 = iVar14 + 0xd;
            iVar48 = iVar14 + 0x13;
            iVar36 = iVar14 + 0x14;
            iVar14 = iVar14 + 0x15;
            pdVar52 = pdVar51;
          }
          else {
            if (uVar47 < 0x16) {
              local_364 = *(float *)(param_1 + 0x18);
              local_360 = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar52 = 0x5c8;
                local_360 = 2.8026e-45;
                pdVar52[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar52[(int)local_360] = 0x1000000;
              puVar9 = PTR_0000e694;
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_360 | *puVar12;
              iVar22 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar9,
                                           local_b8,local_b4,1);
              if (iVar22 != 0) goto LAB_00006cc0;
              *(undefined4 *)((int)local_364 + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_364;
              pdVar52 = (dword *)((int)local_364 + 0x20);
              pdVar51 = (dword *)((int)local_364 + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
              pdVar26 = (dword *)((int)local_364 + 0x24);
              pdVar19 = (dword *)((int)local_364 + 0x28);
              pdVar21 = (dword *)((int)local_364 + 0x2c);
              pdVar28 = (dword *)((int)local_364 + 0x30);
              pdVar32 = (dword *)((int)local_364 + 0x34);
              uVar47 = uVar38;
              goto LAB_00006d28;
            }
            iVar10 = 0;
            iVar34 = 1;
            local_148 = 0xe;
            local_14c = 0xf;
            iVar13 = 0x11;
            local_150 = 0x10;
            iVar35 = 2;
            iVar33 = 3;
            iVar22 = 0x12;
            iVar20 = 4;
            iVar24 = 5;
            iVar39 = 6;
            iVar40 = 7;
            iVar41 = 8;
            iVar42 = 9;
            iVar43 = 10;
            iVar45 = 0xb;
            iVar46 = 0xc;
            iVar15 = 0xd;
            iVar48 = 0x13;
            iVar36 = 0x14;
            iVar14 = 0x15;
            iVar17 = 0x16;
          }
          *(undefined4 *)((int)pdVar52 + iVar10) = 0x10f8;
          local_cc = uVar50 & 0x1fff;
          pdVar52[iVar34] = local_cc | iVar55 * 0x2000 & 0x3ffe000U;
          pdVar52[iVar35] = 0x10f9;
          local_d0 = uVar54 & 0x1fff;
          pdVar52[iVar33] = local_d0 | (uVar44 & 0x1fff) << 0xd;
          pdVar52[iVar20] = 0xc00c3500;
          pdVar52[iVar24] = 0x4003d;
          pdVar52[iVar39] = uVar50 | uVar44 << 0x10;
          fVar27 = *local_b0;
          pdVar52[iVar40] = (dword)fVar27;
          fVar16 = *local_b8;
          pdVar52[iVar41] = (dword)fVar16;
          pdVar52[iVar42] = uVar50 | iVar55 * 0x10000;
          pdVar52[iVar43] = (dword)fVar27;
          fVar27 = *local_b4;
          pdVar52[iVar45] = (dword)fVar27;
          pdVar52[iVar46] = uVar54 | iVar55 * 0x10000;
          fVar31 = *local_ac;
          pdVar52[iVar15] = (dword)fVar31;
          pdVar52[local_148] = (dword)fVar27;
          pdVar52[local_14c] = uVar54 | uVar44 << 0x10;
          pdVar52[local_150] = (dword)fVar31;
          pdVar52[iVar13] = (dword)fVar16;
          pdVar52[iVar22] = 0x1393;
          pdVar52[iVar48] = 10;
          pdVar52[iVar36] = 0x5c8;
          pdVar52[iVar14] = 0x20000;
          uVar47 = uVar47 - iVar17;
          bVar1 = false;
          pdVar52 = pdVar52 + iVar17;
          iVar10 = (int)*local_160 + (int)*local_164;
          local_364 = fVar4;
          local_360 = fVar3;
          local_35c = fVar30;
          local_358 = fVar7;
          if (0xfff < iVar10) {
            local_228 = 0x43300000;
            iVar22 = local_e8 + 0x1000;
            iVar55 = local_e8 + *local_160 + (int)*local_164;
            uStack_224 = (local_f0 + iVar10) - 0x1000U ^ 0x80000000;
            local_220 = 0x43300000;
            iVar10 = *(short *)((int)local_d8 + 6) + -0x1000;
            fVar16 = fVar25 * (1.0 / (float)((double)CONCAT44(0x43300000,iVar10) -
                                            4503599627370496.0));
            fVar27 = (float)((double)CONCAT44(0x43300000,uStack_224) - 4503601774854144.0) * fVar16;
            fVar16 = fVar16 * 0.0;
            iStack_21c = iVar10;
            if (uVar47 < 0x8a) {
              local_358 = *(float *)(param_1 + 0x18);
              local_35c = 0.0;
              if (*(int *)(param_1 + 0x8c) == 0) {
                *pdVar52 = 0x5c8;
                local_35c = 2.8026e-45;
                pdVar52[1] = 0xc000;
                *(undefined4 *)(param_1 + 0x94) = 0;
              }
              pdVar52[(int)local_35c] = 0x1000000;
              puVar9 = PTR_0000e694;
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_35c | *puVar12;
              iVar13 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar9,
                                           local_ac,local_b0,1);
              if (iVar13 == 0) {
                *(undefined4 *)((int)local_358 + 0x1c) = 0;
                *(float *)(param_1 + 0x18) = local_358;
                pdVar52 = (dword *)((int)local_358 + 0x20);
                pdVar51 = (dword *)((int)local_358 + 0x38);
                *(int *)(param_1 + 0x7c) = (int)local_358 + 0x1c;
                pdVar26 = (dword *)((int)local_358 + 0x24);
                pdVar19 = (dword *)((int)local_358 + 0x28);
                pdVar21 = (dword *)((int)local_358 + 0x2c);
                pdVar28 = (dword *)((int)local_358 + 0x30);
                pdVar32 = (dword *)((int)local_358 + 0x34);
                uVar47 = uVar38;
              }
              else {
                pdVar52 = (dword *)0x0;
                *(undefined4 *)(param_1 + 0x7c) = 0;
                *(undefined4 *)(param_1 + 0x18) = 0;
                pdVar26 = &__mh_bundle_header.cputype;
                pdVar19 = &__mh_bundle_header.cpusubtype;
                pdVar21 = &__mh_bundle_header.filetype;
                pdVar28 = &__mh_bundle_header.ncmds;
                pdVar32 = &__mh_bundle_header.sizeofcmds;
                pdVar51 = &__mh_bundle_header.flags;
                uVar47 = uVar38;
              }
            }
            else {
              pdVar26 = pdVar52 + 1;
              pdVar19 = pdVar52 + 2;
              pdVar21 = pdVar52 + 3;
              pdVar28 = pdVar52 + 4;
              pdVar32 = pdVar52 + 5;
              pdVar51 = pdVar52 + 6;
            }
            puVar12 = *(uint **)(param_1 + 0x7c);
            *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
            *(dword **)(param_1 + 0x7c) = pdVar52;
            *pdVar52 = local_140;
            *pdVar26 = local_fc;
            *pdVar19 = local_100;
            *pdVar21 = local_114;
            *pdVar28 = 0;
            *pdVar32 = 0;
            iVar10 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,0,iVar10);
            pdVar51[iVar10] = 0x10f8;
            pdVar51[iVar10 + 1] = local_cc | iVar22 * 0x2000 & 0x3ffe000U;
            pdVar51[iVar10 + 2] = 0x10f9;
            pdVar51[iVar10 + 3] = local_d0 | iVar55 * 0x2000 & 0x3ffe000U;
            pdVar51[iVar10 + 4] = 0xc00c3500;
            pdVar51[iVar10 + 5] = 0x4003d;
            uVar44 = iVar55 * 0x10000;
            pdVar51[iVar10 + 6] = uVar50 | uVar44;
            pdVar51[iVar10 + 7] = (dword)fVar30;
            pdVar51[iVar10 + 8] = (dword)fVar27;
            uVar6 = iVar22 * 0x10000;
            pdVar51[iVar10 + 9] = uVar50 | uVar6;
            pdVar51[iVar10 + 10] = (dword)fVar30;
            pdVar51[iVar10 + 0xb] = (dword)fVar16;
            pdVar51[iVar10 + 0xc] = uVar54 | uVar6;
            pdVar51[iVar10 + 0xd] = (dword)fVar7;
            pdVar51[iVar10 + 0xe] = (dword)fVar16;
            pdVar51[iVar10 + 0xf] = uVar54 | uVar44;
            pdVar51[iVar10 + 0x10] = (dword)fVar7;
            pdVar51[iVar10 + 0x11] = (dword)fVar27;
            pdVar51[iVar10 + 0x12] = 0x1393;
            pdVar51[iVar10 + 0x13] = 10;
            pdVar51[iVar10 + 0x14] = 0x5c8;
            pdVar51[iVar10 + 0x15] = 0x20000;
            uVar47 = (uVar47 - 6) - (iVar10 + 0x16);
            bVar1 = true;
            pdVar52 = pdVar51 + iVar10 + 0x16;
            local_364 = fVar30;
            local_360 = fVar7;
            local_35c = fVar16;
            local_358 = fVar27;
          }
          piVar53 = piVar53 + 2;
          local_170 = local_170 + 1;
        } while (iVar37 != local_170);
      }
    }
    else {
      local_120 = iVar55 >> 1 & 0xfffffe00;
      local_11c = iVar55 - local_120;
      local_118 = local_120 + 2;
      local_208 = 0x43300000;
      local_218 = 0x43300000;
      local_210 = 0x43300000;
      uStack_214 = (int)*(short *)((int)local_d8 + 6) ^ 0x80000000;
      uStack_204 = local_11c ^ 0x80000000;
      uStack_20c = local_118 ^ 0x80000000;
      fVar30 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_214) - 4503601774854144.0);
      fVar3 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_204) - 4503601774854144.0);
      fVar4 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_20c) - 4503601774854144.0);
      if (iVar37 != 0) {
        bVar1 = true;
        local_174 = 0;
        local_c0 = 0xc000;
        local_168 = local_d4;
        do {
          iVar55 = (int)*(short *)local_168;
          if (local_ec + iVar55 < (int)local_118) {
            uStack_1fc = local_ec + iVar55 ^ 0x80000000;
            local_200 = 0x43300000;
            uVar54 = local_ec + iVar55 + *(short *)(local_168 + 1);
            uStack_1f4 = local_118;
            if ((int)uVar54 < (int)local_118) {
              uStack_1f4 = uVar54;
            }
            uStack_1f4 = uStack_1f4 ^ 0x80000000;
            local_1f8 = 0x43300000;
            local_16c = local_e4 + iVar55;
            uVar54 = local_16c + (int)*(short *)(local_168 + 1);
            iVar55 = (int)(short)*local_168;
            local_1f0 = 0x43300000;
            uStack_1ec = local_f0 + iVar55 ^ 0x80000000;
            local_1e8 = 0x43300000;
            uStack_1e4 = local_f0 + iVar55 + *(short *)((int)local_168 + 6) ^ 0x80000000;
            if ((int)local_118 < (int)uVar54) {
              local_1e0 = 0x43300000;
              uStack_1dc = local_e4 + local_118 ^ 0x80000000;
              uVar54 = uStack_1dc;
            }
            else {
              uStack_1d4 = uVar54 ^ 0x80000000;
              local_1d8 = 0x43300000;
              uVar54 = uStack_1d4;
            }
            dVar60 = (double)CONCAT44(0x43300000,uVar54) - 4503601774854144.0;
            fVar16 = (float)dVar60;
            if (2.1474836e+09 <= fVar16) {
              iVar22 = (int)(fVar16 - 2.1474836e+09);
              local_1c8 = (longlong)iVar22;
              local_124 = iVar22 + 0x80000000;
            }
            else {
              local_124 = (uint)dVar60;
              local_1d0 = (longlong)(int)local_124;
            }
            fVar16 = fVar18 * fVar4 * (float)((double)CONCAT44(0x43300000,uStack_1fc) -
                                             4503601774854144.0);
            fVar7 = fVar18 * fVar4 * (float)((double)CONCAT44(0x43300000,uStack_1f4) -
                                            4503601774854144.0);
            fVar27 = fVar25 * fVar30 * (float)((double)CONCAT44(0x43300000,uStack_1ec) -
                                              4503601774854144.0);
            fVar31 = fVar25 * fVar30 * (float)((double)CONCAT44(0x43300000,uStack_1e4) -
                                              4503601774854144.0);
            local_128 = local_e8 + iVar55;
            local_12c = local_128 + (int)*(short *)((int)local_168 + 6);
            if (bVar1) {
              if (uVar47 < 0x9e) {
                local_360 = *(float *)(param_1 + 0x18);
                local_364 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar52 = 0x5c8;
                  local_364 = 2.8026e-45;
                  pdVar52[1] = local_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar52[(int)local_364] = 0x1000000;
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_364 | *puVar12;
                iVar55 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_360,&local_364,1);
                if (iVar55 == 0) {
                  *(undefined4 *)((int)local_360 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_360;
                  pdVar52 = (dword *)((int)local_360 + 0x20);
                  pdVar51 = (dword *)((int)local_360 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_360 + 0x1c;
                  pdVar26 = (dword *)((int)local_360 + 0x24);
                  pdVar19 = (dword *)((int)local_360 + 0x28);
                  pdVar21 = (dword *)((int)local_360 + 0x2c);
                  pdVar28 = (dword *)((int)local_360 + 0x30);
                  pdVar32 = (dword *)((int)local_360 + 0x34);
                  uVar47 = uVar38;
                }
                else {
                  pdVar52 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar26 = &__mh_bundle_header.cputype;
                  pdVar19 = &__mh_bundle_header.cpusubtype;
                  pdVar21 = &__mh_bundle_header.filetype;
                  pdVar28 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  pdVar51 = &__mh_bundle_header.flags;
                  uVar47 = uVar38;
                }
              }
              else {
                pdVar26 = pdVar52 + 1;
                pdVar19 = pdVar52 + 2;
                pdVar21 = pdVar52 + 3;
                pdVar28 = pdVar52 + 4;
                pdVar32 = pdVar52 + 5;
                pdVar51 = pdVar52 + 6;
              }
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
              *(dword **)(param_1 + 0x7c) = pdVar52;
              *pdVar52 = local_140;
              *pdVar26 = local_fc;
              *pdVar19 = local_100;
              *pdVar21 = 0;
              *pdVar28 = 0;
              *pdVar32 = 0;
              uVar47 = uVar47 - 4;
              iVar55 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,local_118,0)
              ;
LAB_0000789c:
              iVar13 = iVar55 + 9;
              iVar39 = iVar55 + 0x16;
              iVar22 = iVar55 << 2;
              iVar20 = iVar55 + 1;
              iVar24 = iVar55 + 2;
              iVar33 = iVar55 + 3;
              iVar57 = iVar55 + 4;
              iVar34 = iVar55 + 5;
              iVar40 = iVar55 + 6;
              iVar41 = iVar55 + 7;
              iVar17 = iVar55 + 8;
              iVar35 = iVar55 + 10;
              iVar42 = iVar55 + 0xb;
              iVar36 = iVar55 + 0xc;
              iVar43 = iVar55 + 0xd;
              iVar45 = iVar55 + 0xe;
              iVar46 = iVar55 + 0xf;
              iVar48 = iVar55 + 0x10;
              iVar49 = iVar55 + 0x11;
              iVar56 = iVar55 + 0x12;
              iVar14 = iVar55 + 0x13;
              iVar15 = iVar55 + 0x14;
              iVar55 = iVar55 + 0x15;
              pdVar52 = pdVar51;
            }
            else {
              if (uVar47 < 0x2a) {
                local_364 = *(float *)(param_1 + 0x18);
                local_360 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar52 = 0x5c8;
                  local_360 = 2.8026e-45;
                  pdVar52[1] = local_c0;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar52[(int)local_360] = 0x1000000;
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_360 | *puVar12;
                iVar55 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_364,&local_360,1);
                if (iVar55 == 0) {
                  *(undefined4 *)((int)local_364 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_364;
                  pdVar26 = (dword *)((int)local_364 + 0x20);
                  pdVar51 = (dword *)((int)local_364 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_364 + 0x1c;
                  pdVar52 = (dword *)((int)local_364 + 0x24);
                  pdVar19 = (dword *)((int)local_364 + 0x28);
                  pdVar21 = (dword *)((int)local_364 + 0x2c);
                  pdVar28 = (dword *)((int)local_364 + 0x30);
                  pdVar32 = (dword *)((int)local_364 + 0x34);
                }
                else {
                  pdVar26 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar52 = &__mh_bundle_header.cputype;
                  pdVar19 = &__mh_bundle_header.cpusubtype;
                  pdVar21 = &__mh_bundle_header.filetype;
                  pdVar28 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  pdVar51 = &__mh_bundle_header.flags;
                }
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = (int)pdVar26 - (int)puVar12 >> 2 | *puVar12;
                *(dword **)(param_1 + 0x7c) = pdVar26;
                *pdVar26 = local_140;
                *pdVar52 = local_fc;
                *pdVar19 = local_100;
                *pdVar21 = 0;
                *pdVar28 = 0;
                *pdVar32 = 0;
                uVar47 = iVar10 - 0xb;
                iVar55 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,local_118,
                                            0);
                goto LAB_0000789c;
              }
              iVar22 = 0;
              iVar20 = 1;
              iVar24 = 2;
              iVar13 = 9;
              iVar33 = 3;
              iVar57 = 4;
              iVar34 = 5;
              iVar40 = 6;
              iVar41 = 7;
              iVar17 = 8;
              iVar35 = 10;
              iVar42 = 0xb;
              iVar36 = 0xc;
              iVar43 = 0xd;
              iVar45 = 0xe;
              iVar46 = 0xf;
              iVar48 = 0x10;
              iVar49 = 0x11;
              iVar56 = 0x12;
              iVar14 = 0x13;
              iVar15 = 0x14;
              iVar55 = 0x15;
              iVar39 = 0x16;
            }
            *(undefined4 *)((int)pdVar52 + iVar22) = 0x10f8;
            pdVar52[iVar20] = local_16c & 0x1fff | (local_128 & 0x1fff) << 0xd;
            pdVar52[iVar24] = 0x10f9;
            pdVar52[iVar33] = local_124 & 0x1fff | (local_12c & 0x1fff) << 0xd;
            pdVar52[iVar57] = 0xc00c3500;
            pdVar52[iVar34] = 0x4003d;
            pdVar52[iVar40] = local_16c | local_12c << 0x10;
            pdVar52[iVar41] = (dword)fVar16;
            pdVar52[iVar17] = (dword)fVar31;
            pdVar52[iVar13] = local_16c | local_128 << 0x10;
            pdVar52[iVar35] = (dword)fVar16;
            pdVar52[iVar42] = (dword)fVar27;
            pdVar52[iVar36] = local_124 | local_128 << 0x10;
            pdVar52[iVar43] = (dword)fVar7;
            pdVar52[iVar45] = (dword)fVar27;
            pdVar52[iVar46] = local_124 | local_12c << 0x10;
            pdVar52[iVar48] = (dword)fVar7;
            pdVar52[iVar49] = (dword)fVar31;
            pdVar52[iVar56] = 0x1393;
            pdVar52[iVar14] = 10;
            pdVar52[iVar15] = 0x5c8;
            pdVar52[iVar55] = 0x20000;
            uVar47 = uVar47 - iVar39;
            bVar1 = false;
            pdVar52 = pdVar52 + iVar39;
            local_364 = fVar31;
            local_360 = fVar27;
            local_35c = fVar7;
            local_358 = fVar16;
          }
          local_174 = local_174 + 1;
          local_168 = local_168 + 2;
        } while (iVar37 != local_174);
        bVar1 = true;
        local_178 = 0;
        local_bc = 0xc000;
        piVar53 = local_d4;
        do {
          iVar22 = (int)*(short *)piVar53;
          iVar55 = iVar22 + *(short *)(piVar53 + 1) + local_ec;
          if ((int)local_120 < iVar55) {
            uStack_1bc = local_120;
            if ((int)local_120 < iVar22 + local_ec) {
              uStack_1bc = iVar22 + local_ec;
            }
            uStack_1bc = uStack_1bc ^ 0x80000000;
            uStack_1b4 = local_120 ^ 0x80000000;
            uStack_1ac = iVar55 - local_120 ^ 0x80000000;
            local_134 = local_e4 + iVar22;
            local_1c0 = 0x43300000;
            local_1b8 = 0x43300000;
            local_1b0 = 0x43300000;
            iVar55 = (int)(short)*piVar53;
            local_1a8 = 0x43300000;
            uStack_1a4 = iVar55 + local_f0 ^ 0x80000000;
            local_1a0 = 0x43300000;
            uStack_19c = iVar55 + *(short *)((int)piVar53 + 6) + local_ec ^ 0x80000000;
            if ((int)local_120 < (int)local_134) {
              uStack_194 = local_134 ^ 0x80000000;
              local_198 = 0x43300000;
              uVar54 = uStack_194;
            }
            else {
              local_190 = 0x43300000;
              uStack_18c = local_e4 + local_120 ^ 0x80000000;
              uVar54 = uStack_18c;
            }
            dVar60 = (double)CONCAT44(0x43300000,uVar54) - 4503601774854144.0;
            fVar4 = (float)dVar60;
            if (2.1474836e+09 <= fVar4) {
              iVar22 = (int)(fVar4 - 2.1474836e+09);
              local_180 = (longlong)iVar22;
              local_130 = iVar22 + 0x80000000;
            }
            else {
              local_130 = (uint)dVar60;
              local_188 = (longlong)(int)local_130;
            }
            local_134 = local_134 + (int)*(short *)(piVar53 + 1);
            fVar4 = fVar18 * fVar3 * ((float)((double)CONCAT44(0x43300000,uStack_1bc) -
                                             4503601774854144.0) -
                                     (float)((double)CONCAT44(0x43300000,uStack_1b4) -
                                            4503601774854144.0));
            fVar16 = fVar18 * fVar3 * (float)((double)CONCAT44(0x43300000,uStack_1ac) -
                                             4503601774854144.0);
            fVar7 = fVar25 * fVar30 * (float)((double)CONCAT44(0x43300000,uStack_1a4) -
                                             4503601774854144.0);
            fVar27 = fVar25 * fVar30 * (float)((double)CONCAT44(0x43300000,uStack_19c) -
                                              4503601774854144.0);
            local_138 = local_e8 + iVar55;
            local_13c = local_138 + (int)*(short *)((int)piVar53 + 6);
            if (bVar1) {
              if (uVar47 < 0x9e) {
                local_35c = *(float *)(param_1 + 0x18);
                local_358 = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar52 = 0x5c8;
                  local_358 = 2.8026e-45;
                  pdVar52[1] = local_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar52[(int)local_358] = 0x1000000;
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_358 | *puVar12;
                iVar55 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_35c,&local_358,1);
                if (iVar55 == 0) {
                  *(undefined4 *)((int)local_35c + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_35c;
                  pdVar52 = (dword *)((int)local_35c + 0x20);
                  pdVar51 = (dword *)((int)local_35c + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_35c + 0x1c;
                  pdVar26 = (dword *)((int)local_35c + 0x24);
                  pdVar19 = (dword *)((int)local_35c + 0x28);
                  pdVar21 = (dword *)((int)local_35c + 0x2c);
                  pdVar28 = (dword *)((int)local_35c + 0x30);
                  pdVar32 = (dword *)((int)local_35c + 0x34);
                  uVar47 = uVar38;
                }
                else {
                  pdVar52 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar26 = &__mh_bundle_header.cputype;
                  pdVar19 = &__mh_bundle_header.cpusubtype;
                  pdVar21 = &__mh_bundle_header.filetype;
                  pdVar28 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  pdVar51 = &__mh_bundle_header.flags;
                  uVar47 = uVar38;
                }
              }
              else {
                pdVar26 = pdVar52 + 1;
                pdVar19 = pdVar52 + 2;
                pdVar21 = pdVar52 + 3;
                pdVar28 = pdVar52 + 4;
                pdVar32 = pdVar52 + 5;
                pdVar51 = pdVar52 + 6;
              }
              puVar12 = *(uint **)(param_1 + 0x7c);
              *puVar12 = (int)pdVar52 - (int)puVar12 >> 2 | *puVar12;
              *(dword **)(param_1 + 0x7c) = pdVar52;
              *pdVar52 = local_140;
              *pdVar26 = local_fc;
              *pdVar19 = local_100;
              *pdVar21 = 0;
              *pdVar28 = local_d8[0xb];
              *pdVar32 = local_120;
              uVar47 = uVar47 - 4;
              iVar55 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,local_11c,0)
              ;
LAB_00007ff0:
              iVar13 = iVar55 + 9;
              iVar14 = iVar55 + 10;
              iVar39 = iVar55 + 0x16;
              iVar22 = iVar55 << 2;
              iVar24 = iVar55 + 1;
              iVar33 = iVar55 + 2;
              iVar34 = iVar55 + 3;
              iVar40 = iVar55 + 4;
              iVar41 = iVar55 + 5;
              iVar42 = iVar55 + 6;
              iVar43 = iVar55 + 7;
              iVar20 = iVar55 + 8;
              iVar45 = iVar55 + 0xb;
              iVar36 = iVar55 + 0xc;
              iVar46 = iVar55 + 0xd;
              iVar48 = iVar55 + 0xe;
              iVar57 = iVar55 + 0xf;
              iVar35 = iVar55 + 0x10;
              iVar49 = iVar55 + 0x11;
              iVar56 = iVar55 + 0x12;
              iVar15 = iVar55 + 0x13;
              iVar17 = iVar55 + 0x14;
              iVar55 = iVar55 + 0x15;
              pdVar52 = pdVar51;
            }
            else {
              if (uVar47 < 0x2a) {
                local_358 = *(float *)(param_1 + 0x18);
                local_35c = 0.0;
                if (*(int *)(param_1 + 0x8c) == 0) {
                  *pdVar52 = 0x5c8;
                  local_35c = 2.8026e-45;
                  pdVar52[1] = local_bc;
                  *(undefined4 *)(param_1 + 0x94) = 0;
                }
                pdVar52[(int)local_35c] = 0x1000000;
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = ((int)pdVar52 - (int)puVar12 >> 2) + (int)local_35c | *puVar12;
                iVar55 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&local_358,&local_35c,1);
                if (iVar55 == 0) {
                  *(undefined4 *)((int)local_358 + 0x1c) = 0;
                  *(float *)(param_1 + 0x18) = local_358;
                  pdVar26 = (dword *)((int)local_358 + 0x20);
                  pdVar51 = (dword *)((int)local_358 + 0x38);
                  *(int *)(param_1 + 0x7c) = (int)local_358 + 0x1c;
                  pdVar52 = (dword *)((int)local_358 + 0x24);
                  pdVar19 = (dword *)((int)local_358 + 0x28);
                  pdVar21 = (dword *)((int)local_358 + 0x2c);
                  pdVar28 = (dword *)((int)local_358 + 0x30);
                  pdVar32 = (dword *)((int)local_358 + 0x34);
                }
                else {
                  pdVar26 = (dword *)0x0;
                  *(undefined4 *)(param_1 + 0x7c) = 0;
                  *(undefined4 *)(param_1 + 0x18) = 0;
                  pdVar52 = &__mh_bundle_header.cputype;
                  pdVar19 = &__mh_bundle_header.cpusubtype;
                  pdVar21 = &__mh_bundle_header.filetype;
                  pdVar28 = &__mh_bundle_header.ncmds;
                  pdVar32 = &__mh_bundle_header.sizeofcmds;
                  pdVar51 = &__mh_bundle_header.flags;
                }
                puVar12 = *(uint **)(param_1 + 0x7c);
                *puVar12 = (int)pdVar26 - (int)puVar12 >> 2 | *puVar12;
                *(dword **)(param_1 + 0x7c) = pdVar26;
                *pdVar26 = local_140;
                *pdVar52 = local_fc;
                *pdVar19 = local_100;
                *pdVar21 = 0;
                *pdVar28 = local_d8[0xb];
                *pdVar32 = local_120;
                uVar47 = iVar10 - 0xb;
                iVar55 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar51,local_d8,local_f4,local_144,0,local_11c,
                                            0);
                goto LAB_00007ff0;
              }
              iVar22 = 0;
              iVar24 = 1;
              iVar13 = 9;
              iVar33 = 2;
              iVar34 = 3;
              iVar14 = 10;
              iVar40 = 4;
              iVar41 = 5;
              iVar42 = 6;
              iVar43 = 7;
              iVar20 = 8;
              iVar45 = 0xb;
              iVar36 = 0xc;
              iVar46 = 0xd;
              iVar48 = 0xe;
              iVar57 = 0xf;
              iVar35 = 0x10;
              iVar49 = 0x11;
              iVar56 = 0x12;
              iVar15 = 0x13;
              iVar17 = 0x14;
              iVar55 = 0x15;
              iVar39 = 0x16;
            }
            *(undefined4 *)((int)pdVar52 + iVar22) = 0x10f8;
            pdVar52[iVar24] = local_130 & 0x1fff | (local_138 & 0x1fff) << 0xd;
            pdVar52[iVar33] = 0x10f9;
            pdVar52[iVar34] = local_134 & 0x1fff | (local_13c & 0x1fff) << 0xd;
            pdVar52[iVar40] = 0xc00c3500;
            pdVar52[iVar41] = 0x4003d;
            pdVar52[iVar42] = local_130 | local_13c << 0x10;
            pdVar52[iVar43] = (dword)fVar4;
            pdVar52[iVar20] = (dword)fVar27;
            pdVar52[iVar13] = local_130 | local_138 << 0x10;
            pdVar52[iVar14] = (dword)fVar4;
            pdVar52[iVar45] = (dword)fVar7;
            pdVar52[iVar36] = local_134 | local_138 << 0x10;
            pdVar52[iVar46] = (dword)fVar16;
            pdVar52[iVar48] = (dword)fVar7;
            pdVar52[iVar57] = local_134 | local_13c << 0x10;
            pdVar52[iVar35] = (dword)fVar16;
            pdVar52[iVar49] = (dword)fVar27;
            pdVar52[iVar56] = 0x1393;
            pdVar52[iVar15] = 10;
            pdVar52[iVar17] = 0x5c8;
            pdVar52[iVar55] = 0x20000;
            uVar47 = uVar47 - iVar39;
            bVar1 = false;
            pdVar52 = pdVar52 + iVar39;
            local_364 = fVar7;
            local_360 = fVar16;
            local_35c = fVar4;
            local_358 = fVar27;
          }
          piVar53 = piVar53 + 2;
          local_178 = local_178 + 1;
        } while (iVar37 != local_178);
      }
    }
    iVar10 = 0;
    *(dword **)(param_1 + 0x80) = pdVar52;
  }
  return iVar10;
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
  bool bVar4;
  bool bVar5;
  double dVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  float fVar9;
  int iVar10;
  dword dVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  dword *pdVar15;
  float fVar16;
  dword *pdVar17;
  uint uVar18;
  float fVar19;
  dword *pdVar20;
  int *piVar21;
  dword *pdVar22;
  float fVar23;
  int iVar24;
  uint *puVar25;
  int iVar26;
  dword *pdVar27;
  float fVar28;
  float fVar29;
  uint uVar30;
  dword *pdVar31;
  int iVar32;
  uint uVar33;
  uint uVar34;
  int iVar35;
  uint uVar36;
  int iVar37;
  uint uVar38;
  uint uVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  uint uVar43;
  int iVar44;
  dword *pdVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  undefined4 *puVar49;
  int iVar50;
  int iVar51;
  int iVar52;
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
  
  uVar33 = param_4 & 0x7ffff000;
  if ((uVar33 != 0x6000) || ((param_3 & 0xf000) != 0)) {
    pdVar45 = *(dword **)(param_1 + 0x80);
    iVar24 = *(int *)(param_1 + 0x18);
    uVar43 = param_5[5];
    uVar30 = *(int *)(iVar24 + 0x10) - 7;
    if ((pdVar45 != (dword *)0x0) &&
       ((iVar12 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,(uint)(*(int *)(param_1 + 0x70) == 3)),
        iVar12 != 0 &&
        (iVar12 = ((int (*)())_createTextureBuffer)(param_1,0x40,0x40,(uint)(*(int *)(param_1 + 0x70) == 3)),
        iVar12 != 0)))) {
      local_f0 = 0x8284;
      local_108 = DAT_0000e748 + 0xc;
      if (uVar33 != 0x6000) {
        _fillTextureWithPattern(param_6,uVar33,*param_5,param_5[1]);
      }
      else {
        _fillTextureWithPattern(param_6,0x6000,param_6,param_6);
      }
      uVar33 = uVar30 - ((int)pdVar45 - (iVar24 + 0x20) >> 2);
      if (param_5[0x16] != 0) {
        local_bc = uVar43 & 0x7c00;
        local_c4 = (param_3 & 0xc000) >> 0xe & 1;
        local_104 = 0;
        bVar5 = (param_3 & 0xc000) == 0;
        puVar49 = param_5;
        do {
          local_114 = puVar49[0x18] + *(int *)(param_1 + 100);
          local_118 = local_114 + puVar49[0x1a];
          local_10c = puVar49[0x17] + *(int *)(param_1 + 0x60);
          local_110 = local_10c + puVar49[0x19];
          local_120 = local_118;
          if (local_114 + 8 < local_118) {
            local_120 = local_114 + 8;
          }
          iStack_2b4 = (local_10c & 7) + param_5[2];
          iStack_2ac = (local_114 & 7) + param_5[3];
          local_2b8 = 0x43300000;
          local_2b0 = 0x43300000;
          fVar9 = (float)((double)CONCAT44(0x43300000,iStack_2b4) - 4503599627370496.0);
          fVar1 = (float)((double)CONCAT44(0x43300000,iStack_2ac) - 4503599627370496.0);
          if (local_114 < local_118) {
            uVar39 = local_10c + 8;
            uVar34 = local_110;
            if (uVar39 < local_110) {
              uVar34 = uVar39;
            }
            local_290 = 0x43300000;
            bVar4 = true;
            uStack_28c = local_bc >> 10;
            dVar6 = (double)CONCAT44(0x43300000,uStack_28c);
            uVar18 = local_114;
            do {
              local_11c = uVar18;
              if (local_10c < local_110) {
                if (!bVar4) {
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
                  fVar2 = (float)((double)CONCAT44(0x43300000,local_11c) - 4503599627370496.0);
                  fVar3 = (float)((double)CONCAT44(0x43300000,local_120) - 4503599627370496.0);
                  uVar18 = uVar39;
                  uVar38 = local_10c;
                  local_124 = uVar34;
                  goto LAB_00008bec;
                }
                uVar36 = uVar39;
                if (uVar33 < 0xd4) {
                  local_2ec = *(float *)(param_1 + 0x18);
                  local_2e8 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar45 = 0x5c8;
                    local_2e8 = 2.8026e-45;
                    pdVar45[1] = 0xc000;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar45[(int)local_2e8] = 0x1000000;
                  puVar7 = PTR_0000e694;
                  puVar25 = *(uint **)(param_1 + 0x7c);
                  *puVar25 = ((int)pdVar45 - (int)puVar25 >> 2) + (int)local_2e8 | *puVar25;
                  iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar7,&local_2ec,&local_2e8,1);
                  uStack_244 = local_10c;
                  if (iVar24 == 0) {
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
                    pdVar45 = (dword *)((int)local_2ec + 0x20);
                    pdVar22 = (dword *)((int)local_2ec + 0x38);
                    pdVar15 = (dword *)((int)local_2ec + 0x24);
                    local_d8 = &local_2f4;
                    pdVar17 = (dword *)((int)local_2ec + 0x2c);
                    pdVar31 = (dword *)((int)local_2ec + 0x28);
                    local_f4 = local_120 - local_11c;
                    pdVar20 = (dword *)((int)local_2ec + 0x30);
                    pdVar27 = (dword *)((int)local_2ec + 0x34);
                    *(int *)(param_1 + 0x7c) = (int)local_2ec + 0x1c;
                    *(float *)(param_1 + 0x18) = local_2ec;
                    uVar33 = uVar30;
                    local_124 = uVar34;
                  }
                  else {
                    local_d0 = local_2e4;
                    local_e0 = &local_2fc;
                    local_e8 = &local_304;
                    local_ec = &local_308;
                    pdVar45 = (dword *)0x0;
                    local_e4 = &local_300;
                    local_dc = &local_2f8;
                    pdVar15 = &__mh_bundle_header.cputype;
                    local_cc = local_120 << 0x10;
                    local_d4 = &local_2f0;
                    pdVar31 = &__mh_bundle_header.cpusubtype;
                    pdVar17 = &__mh_bundle_header.filetype;
                    pdVar20 = &__mh_bundle_header.ncmds;
                    pdVar27 = &__mh_bundle_header.sizeofcmds;
                    pdVar22 = &__mh_bundle_header.flags;
                    local_c8 = local_11c << 0x10;
                    local_d8 = &local_2f4;
                    local_f4 = local_120 - local_11c;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    uVar33 = uVar30;
                    local_124 = uVar34;
                  }
                }
                else {
                  local_d0 = local_2e4;
                  local_e0 = &local_2fc;
                  local_e8 = &local_304;
                  local_ec = &local_308;
                  pdVar15 = pdVar45 + 1;
                  pdVar31 = pdVar45 + 2;
                  local_e4 = &local_300;
                  pdVar17 = pdVar45 + 3;
                  local_dc = &local_2f8;
                  pdVar20 = pdVar45 + 4;
                  local_cc = local_120 << 0x10;
                  local_d4 = &local_2f0;
                  pdVar27 = pdVar45 + 5;
                  pdVar22 = pdVar45 + 6;
                  local_c8 = local_11c << 0x10;
                  local_d8 = &local_2f4;
                  local_f4 = local_120 - local_11c;
                  uStack_244 = local_10c;
                  local_124 = uVar34;
                }
                do {
                  puVar25 = *(uint **)(param_1 + 0x7c);
                  *puVar25 = (int)pdVar45 - (int)puVar25 >> 2 | *puVar25;
                  *(dword **)(param_1 + 0x7c) = pdVar45;
                  *pdVar45 = 0xa000000;
                  *pdVar15 = *(dword *)(param_1 + 0x84);
                  puVar25 = *(uint **)(param_1 + 0x7c);
                  *puVar25 = (int)pdVar31 - (int)puVar25 >> 2 | *puVar25;
                  *(dword **)(param_1 + 0x7c) = pdVar31;
                  *pdVar31 = 0x10000000;
                  *pdVar17 = *(dword *)*DAT_0000e6e4;
                  *pdVar20 = DAT_0000e6e4[7];
                  if (DAT_0000e6c0 == 0x10) {
                    *pdVar27 = 3;
                  }
                  else {
                    *pdVar27 = 6;
                  }
                  puVar25 = *(uint **)(param_1 + 0x7c);
                  *puVar25 = (int)pdVar22 - (int)puVar25 >> 2 | *puVar25;
                  *(dword **)(param_1 + 0x7c) = pdVar22;
                  *pdVar22 = 0x13000000;
                  pdVar22[1] = *(undefined4 *)**(undefined4 **)(local_f0 + 0x64c4);
                  pdVar22[2] = 0;
                  pdVar45 = pdVar22 + 4;
                  pdVar22[3] = 0;
                  iVar12 = *(int *)(param_1 + 0x70);
                  uVar33 = uVar33 - 10;
                  *pdVar45 = 0x850;
                  pdVar22[5] = 0x100;
                  pdVar22[6] = 0x887;
                  pdVar22[7] = 0x1c000;
                  pdVar22[8] = 0x82c;
                  pdVar22[9] = 0;
                  pdVar22[10] = 0x1002;
                  pdVar22[0xb] = 0;
                  pdVar22[0xc] = 0x824;
                  pdVar22[0xd] = 1;
                  pdVar22[0xe] = 0x825;
                  pdVar22[0xf] = 0x12;
                  pdVar22[0x10] = 0x82d;
                  pdVar22[0x11] = 5;
                  pdVar22[0x12] = 0x854;
                  pdVar22[0x13] = 0x6010006;
                  pdVar22[0x14] = 0x855;
                  pdVar22[0x15] = 0x2701;
                  pdVar22[0x16] = 0x878;
                  pdVar22[0x17] = 0xf688f688;
                  pdVar22[0x18] = 0x879;
                  pdVar22[0x19] = 0xfb24f688;
                  pdVar22[0x1a] = 0x10a2;
                  pdVar22[0x1b] = 0;
                  pdVar22[0x1c] = 0x1381;
                  pdVar22[0x1d] = 0;
                  pdVar22[0x1e] = 0x109e;
                  pdVar22[0x1f] = 5;
                  pdVar22[0x20] = 0x1383;
                  pdVar22[0x21] = 0xf;
                  pdVar22[0x22] = 0x1004;
                  pdVar22[0x23] = 0x66666666;
                  pdVar22[0x24] = 0x1005;
                  pdVar22[0x25] = 0x66666666;
                  pdVar22[0x26] = 0x10ae;
                  pdVar22[0x27] = 0;
                  pdVar22[0x28] = 0x10ea;
                  pdVar22[0x29] = 0x2da49525;
                  pdVar22[0x2a] = 0x10fa;
                  pdVar22[0x2b] = 0xffffff;
                  pdVar22[0x2c] = 0x10f4;
                  pdVar22[0x2d] = 0xffff;
                  pdVar22[0x2e] = 0x10f8;
                  pdVar22[0x2f] = 0;
                  pdVar22[0x30] = 0x10f9;
                  pdVar22[0x31] =
                       *(uint *)(param_1 + 0x54) & 0x1fff |
                       (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
                  pdVar22[0x32] = 0x13c0;
                  pdVar22[0x33] = 0;
                  pdVar22[0x34] = 0x13c1;
                  pdVar22[0x35] = 0;
                  pdVar22[0x36] = 0x10c0;
                  pdVar22[0x37] = 0x40004;
                  pdVar22[0x38] = 0x10c1;
                  pdVar22[0x39] = 1;
                  pdVar22[0x3a] = 0x10c8;
                  pdVar22[0x3b] = 0x10;
                  pdVar22[0x3c] = 0x10c9;
                  pdVar22[0x3d] = 0x31;
                  pdVar22[0x3e] = 0x101d;
                  pdVar22[0x3f] = 0x28ffe040;
                  pdVar22[0x40] = 0x101e;
                  pdVar22[0x41] = 0x28ffe0c2;
                  pdVar22[0x42] = 0x1041;
                  pdVar22[0x43] = 3;
                  pdVar22[0x44] = 0x1040;
                  pdVar22[0x45] = 0;
                  pdVar22[0x46] = 0x1100;
                  pdVar22[0x47] = 0x2a92;
                  pdVar22[0x48] = 0x1101;
                  pdVar22[0x49] = 0x10002a92;
                  pdVar22[0x4a] = 0x1120;
                  local_f8 = *(short *)(param_1 + 0x50);
                  local_f6 = *(short *)(param_1 + 0x52);
                  pdVar22[0x4b] =
                       (int)local_f8 - 1U & 0x7ff | (local_f6 + -1) * 0x800 & 0x3ff800U | 0x80000000
                  ;
                  pdVar22[0x4c] = 0x1121;
                  uVar18 = (int)*(short *)(local_108 + 4) - 1;
                  iVar26 = *(short *)(local_108 + 6) + -1;
                  pdVar22[0x4d] = uVar18 & 0x7ff | iVar26 * 0x800 & 0x3ff800U | 0x80000000;
                  pdVar22[0x4e] = 0x1130;
                  iVar24 = 0x5300c - (uint)(iVar12 == 3);
                  pdVar22[0x4f] = iVar24;
                  pdVar22[0x50] = 0x1131;
                  pdVar22[0x51] = iVar24;
                  pdVar22[0x52] = 0x1140;
                  pdVar22[0x53] =
                       *(int *)(param_1 + 0x5c) - 1U & 0x3fff | ((int)local_f8 - 1U) * 0x10 & 0x8000
                       | (local_f6 + -1) * 0x20 & 0x10000U;
                  pdVar22[0x54] = 0x1141;
                  pdVar22[0x55] =
                       *(int *)(local_108 + 0x10) - 1U & 0x3fff | uVar18 * 0x10 & 0x8000 |
                       iVar26 * 0x20 & 0x10000U;
                  if (bVar5) {
                    iVar32 = 0x52;
                    iVar14 = 0x148;
                    local_164 = 0x56;
                    local_168 = 0x57;
                    local_16c = 0x58;
                    local_170 = 0x59;
                    local_174 = 0x5a;
                    local_178 = 0x5b;
                    local_17c = 0x5c;
                    local_180 = 0x5d;
                    iVar51 = 0x5f;
                    local_184 = 0x5e;
                    iVar35 = 0x53;
                    iVar37 = 0x54;
                    iVar52 = 0x60;
                    iVar40 = 0x55;
                    iVar50 = 0x61;
                    iVar41 = 0x62;
                    iVar42 = 99;
                    iVar44 = 100;
                    iVar46 = 0x65;
                    iVar47 = 0x66;
                    iVar10 = 0x67;
                    iVar48 = 0x68;
                    iVar24 = 0x69;
                    iVar26 = 0x6a;
                    iVar13 = 0x6b;
                    iVar12 = 0x6c;
                  }
                  else {
                    if (iVar12 == 3) {
                      uStack_284 = uVar43 >> 5 & 0x1f;
                      uStack_27c = uVar43 & 0x1f;
                      uStack_294 = uVar43 >> 0xf & 1;
                      local_288 = 0x43300000;
                      local_280 = 0x43300000;
                      local_298 = 0x43300000;
                      local_128 = (float)(dVar6 - 4503599627370496.0) / 31.0;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_284) -
                                         4503599627370496.0) / 31.0;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_27c) -
                                         4503599627370496.0) / 31.0;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_294) -
                                         4503599627370496.0);
                    }
                    else {
                      uStack_274 = uVar43 >> 0x18;
                      uStack_26c = uVar43 >> 0x10 & 0xff;
                      uStack_25c = uVar43 & 0xff;
                      uStack_264 = uVar43 >> 8 & 0xff;
                      local_278 = 0x43300000;
                      local_270 = 0x43300000;
                      local_268 = 0x43300000;
                      local_260 = 0x43300000;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_274) -
                                         4503599627370496.0) / 255.0;
                      local_128 = (float)((double)CONCAT44(0x43300000,uStack_26c) -
                                         4503599627370496.0) / 255.0;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_25c) -
                                         4503599627370496.0) / 255.0;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_264) -
                                         4503599627370496.0) / 255.0;
                    }
                    pdVar22[0x56] = 0x1094;
                    pdVar22[0x57] = 0x10000;
                    pdVar22[0x58] = 0x1095;
                    pdVar22[0x59] = (dword)local_128;
                    pdVar22[0x5a] = 0x1095;
                    pdVar22[0x5b] = (dword)local_12c;
                    pdVar22[0x5c] = 0x1095;
                    pdVar22[0x5d] = (dword)local_130;
                    pdVar22[0x5e] = 0x1095;
                    pdVar22[0x5f] = (dword)local_134;
                    iVar32 = 0x5c;
                    iVar14 = 0x170;
                    local_164 = 0x60;
                    local_168 = 0x61;
                    local_16c = 0x62;
                    local_170 = 99;
                    local_174 = 100;
                    local_178 = 0x65;
                    local_17c = 0x66;
                    local_180 = 0x67;
                    iVar51 = 0x69;
                    local_184 = 0x68;
                    iVar35 = 0x5d;
                    iVar37 = 0x5e;
                    iVar52 = 0x6a;
                    iVar40 = 0x5f;
                    iVar50 = 0x6b;
                    iVar41 = 0x6c;
                    iVar42 = 0x6d;
                    iVar44 = 0x6e;
                    iVar46 = 0x6f;
                    iVar47 = 0x70;
                    iVar10 = 0x71;
                    iVar48 = 0x72;
                    iVar24 = 0x73;
                    iVar26 = 0x74;
                    iVar13 = 0x75;
                    iVar12 = 0x76;
                  }
                  *(undefined4 *)((int)pdVar45 + iVar14) = 0x1094;
                  pdVar45[iVar35] = 0;
                  pdVar45[iVar37] = 0x1095;
                  pdVar45[iVar40] = 0x7803;
                  pdVar45[local_164] = 0x1095;
                  pdVar45[local_168] = 0x2410000;
                  pdVar45[local_16c] = 0x1095;
                  pdVar45[local_170] = 0x3901e401;
                  pdVar45[local_174] = 0x1095;
                  pdVar45[local_178] = 0;
                  pdVar45[local_17c] = 0x1095;
                  pdVar45[local_180] = 0;
                  pdVar45[local_184] = 0x1095;
                  pdVar45[iVar51] = 0;
                  if (bVar5) {
                    pdVar45[iVar52] = 0x1095;
                    pdVar45[iVar50] = 0x78105;
                    pdVar45[iVar41] = 0x1095;
                    pdVar45[iVar42] = 1;
                    pdVar45[iVar44] = 0x1095;
                    pdVar45[iVar46] = 1;
                    pdVar45[iVar47] = 0x1095;
                    pdVar45[iVar10] = 0xdb0220;
                    pdVar45[iVar48] = 0x1095;
                    pdVar45[iVar24] = 0xc0c006;
                    pdVar45[iVar26] = 0x1095;
                    pdVar45[iVar13] = 0x20490000;
                  }
                  else {
                    pdVar45[iVar52] = 0x1095;
                    pdVar45[iVar50] = 0x7807;
                    pdVar45[iVar41] = 0x1095;
                    pdVar45[iVar42] = 0x2400000;
                    pdVar45[iVar44] = 0x1095;
                    pdVar45[iVar46] = 0x3900e400;
                    pdVar45[iVar47] = 0x1095;
                    pdVar45[iVar10] = 0;
                    pdVar45[iVar48] = 0x1095;
                    pdVar45[iVar24] = 0;
                    pdVar45[iVar26] = 0x1095;
                    pdVar45[iVar13] = 0;
                    pdVar45[iVar12] = 0x1095;
                    pdVar45[iVar32 + 0x1b] = 0x7804;
                    pdVar45[iVar32 + 0x1c] = 0x1095;
                    pdVar45[iVar32 + 0x1d] = 0x40040000;
                    pdVar45[iVar32 + 0x1e] = 0x1095;
                    pdVar45[iVar32 + 0x1f] = 0x40040000;
                    pdVar45[iVar32 + 0x20] = 0x1095;
                    pdVar45[iVar32 + 0x21] = 0xdb0490;
                    pdVar45[iVar32 + 0x22] = 0x1095;
                    pdVar45[iVar32 + 0x23] = 0xc10026;
                    pdVar45[iVar32 + 0x24] = 0x1095;
                    pdVar45[iVar32 + 0x25] = 0xdfa23028;
                    pdVar45[iVar32 + 0x26] = 0x1095;
                    pdVar45[iVar32 + 0x27] = 0x7800;
                    pdVar45[iVar32 + 0x28] = 0x1095;
                    pdVar45[iVar32 + 0x29] = 2;
                    pdVar45[iVar32 + 0x2a] = 0x1095;
                    pdVar45[iVar32 + 0x2b] = 2;
                    pdVar45[iVar32 + 0x2c] = 0x1095;
                    pdVar45[iVar32 + 0x2d] = 0xdb0220;
                    pdVar45[iVar32 + 0x2e] = 0x1095;
                    pdVar45[iVar32 + 0x2f] = 0xc0c021;
                    pdVar45[iVar32 + 0x30] = 0x1095;
                    pdVar45[iVar32 + 0x31] = 0x22;
                    pdVar45[iVar32 + 0x32] = 0x1095;
                    pdVar45[iVar32 + 0x33] = 0x78101;
                    pdVar45[iVar32 + 0x34] = 0x1095;
                    uVar18 = (local_c4 ^ 1) << 10 | local_c4 | 0x200000;
                    pdVar45[iVar32 + 0x35] = uVar18;
                    pdVar45[iVar32 + 0x36] = 0x1095;
                    pdVar45[iVar32 + 0x37] = uVar18;
                    pdVar45[iVar32 + 0x38] = 0x1095;
                    pdVar45[iVar32 + 0x39] = 0x440221;
                    pdVar45[iVar32 + 0x3a] = 0x1095;
                    pdVar45[iVar32 + 0x3b] = 0x60d006;
                    pdVar45[iVar32 + 0x3c] = 0x1095;
                    iVar12 = iVar32 + 0x3e;
                    pdVar45[iVar32 + 0x3d] = 0xdda22008;
                  }
                  pdVar45[iVar12] = 0x1189;
                  pdVar45[iVar12 + 1] = 0;
                  pdVar45[iVar12 + 2] = 0x1181;
                  pdVar45[iVar12 + 3] = 5;
                  pdVar45[iVar12 + 4] = 0x118d;
                  if (bVar5) {
                    dVar11 = 0x10000;
                  }
                  else {
                    dVar11 = 0x40000;
                  }
                  pdVar45[iVar12 + 5] = dVar11;
                  pdVar45[iVar12 + 6] = 0x118e;
                  pdVar45[iVar12 + 7] = 0;
                  pdVar45[iVar12 + 8] = 0x118c;
                  if (bVar5) {
                    dVar11 = 0x10000;
                  }
                  else {
                    dVar11 = 0x40000;
                  }
                  pdVar45[iVar12 + 9] = dVar11;
                  pdVar45[iVar12 + 10] = 0x11a9;
                  pdVar45[iVar12 + 0xb] = 0x1b01;
                  pdVar45[iVar12 + 0xc] = 0x11aa;
                  pdVar45[iVar12 + 0xd] = 0xf;
                  pdVar45[iVar12 + 0xe] = 0x11ab;
                  pdVar45[iVar12 + 0xf] = 0xf;
                  pdVar45[iVar12 + 0x10] = 0x11ac;
                  pdVar45[iVar12 + 0x11] = 0xf;
                  pdVar45[iVar12 + 0x12] = 0x12f0;
                  pdVar45[iVar12 + 0x13] = 0;
                  pdVar45[iVar12 + 0x14] = 0x12f5;
                  pdVar45[iVar12 + 0x15] = 0;
                  local_13c = iVar12 + 0x17;
                  local_140 = iVar12 + 0x18;
                  iVar26 = iVar12 + 0x30;
                  local_258 = 0x43300000;
                  local_250 = 0x43300000;
                  iVar14 = iVar12 + 0x1a;
                  iVar37 = iVar12 + 0x19;
                  uStack_254 = local_11c;
                  uStack_24c = local_120;
                  local_14c = iVar12 + 0x1e;
                  local_150 = iVar12 + 0x1f;
                  local_144 = iVar12 + 0x1b;
                  local_15c = iVar12 + 0x22;
                  local_160 = iVar12 + 0x24;
                  local_138 = (iVar12 + 0x16) * 4;
                  local_148 = iVar12 + 0x1d;
                  local_154 = iVar12 + 0x20;
                  iVar13 = iVar12 + 0x1c;
                  local_158 = iVar12 + 0x21;
                  iVar35 = iVar12 + 0x25;
                  iVar24 = iVar12 + 0x26;
                  iVar32 = iVar12 + 0x23;
                  iVar48 = iVar12 + 0x27;
                  iVar40 = iVar12 + 0x28;
                  iVar41 = iVar12 + 0x29;
                  iVar42 = iVar12 + 0x2a;
                  iVar44 = iVar12 + 0x2b;
                  iVar46 = iVar12 + 0x2c;
                  iVar47 = iVar12 + 0x2d;
                  iVar10 = iVar12 + 0x2e;
                  iVar12 = iVar12 + 0x2f;
                  fVar2 = (float)((double)CONCAT44(0x43300000,local_11c) - 4503599627370496.0);
                  fVar3 = (float)((double)CONCAT44(0x43300000,local_120) - 4503599627370496.0);
                  while( true ) {
                    uStack_23c = local_124;
                    local_238 = 0x43300000;
                    local_228 = 0x43300000;
                    local_248 = 0x43300000;
                    local_240 = 0x43300000;
                    uStack_234 = (int)local_f8 ^ 0x80000000;
                    uStack_224 = (int)local_f6 ^ 0x80000000;
                    local_304 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_234) -
                                             4503601774854144.0);
                    local_300 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_224) -
                                             4503601774854144.0);
                    local_308 = local_304 *
                                (float)((double)CONCAT44(0x43300000,uStack_244) - 4503599627370496.0
                                       );
                    local_304 = local_304 *
                                (float)((double)CONCAT44(0x43300000,local_124) - 4503599627370496.0)
                    ;
                    local_2fc = local_300 * fVar3;
                    local_300 = local_300 * fVar2;
                    *(undefined4 *)((int)pdVar45 + local_138) = 0xc0143500;
                    pdVar45[local_13c] = 0x4003d;
                    iVar50 = local_124 - uStack_244;
                    if ((iVar50 == 8) && (local_f4 == 8)) {
                      local_1e8 = 0x43300000;
                      uStack_1e4 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f8 = (fVar9 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1e4) -
                                                4503601774854144.0));
                      local_1e0 = 0x43300000;
                      uStack_1dc = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f4 = (fVar9 + 8.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1dc) -
                                                4503601774854144.0));
                      local_1d8 = 0x43300000;
                      uStack_1d4 = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2f0 = (fVar1 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1d4) -
                                                4503601774854144.0));
                      local_1d0 = 0x43300000;
                      uStack_1cc = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2e4[0] = (fVar1 + 8.0) *
                                     (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1cc) -
                                                   4503601774854144.0));
                    }
                    else {
                      local_218 = 0x43300000;
                      local_210 = 0x43300000;
                      uStack_214 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f8 = (fVar9 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_214) -
                                                4503601774854144.0));
                      local_208 = 0x43300000;
                      uStack_204 = (int)*(short *)(local_108 + 4) ^ 0x80000000;
                      local_2f4 = (fVar9 + (float)((double)CONCAT44(0x43300000,iVar50) -
                                                  4503599627370496.0)) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_204) -
                                                4503601774854144.0));
                      local_200 = 0x43300000;
                      iStack_1f4 = local_f4;
                      local_1f8 = 0x43300000;
                      uStack_1fc = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2f0 = (fVar1 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1fc) -
                                                4503601774854144.0));
                      local_1f0 = 0x43300000;
                      uStack_1ec = (int)*(short *)(local_108 + 6) ^ 0x80000000;
                      local_2e4[0] = (fVar1 + (float)((double)CONCAT44(0x43300000,local_f4) -
                                                     4503599627370496.0)) *
                                     (1.0 / (float)((double)CONCAT44(0x43300000,uStack_1ec) -
                                                   4503601774854144.0));
                      iStack_20c = iVar50;
                    }
                    pdVar45[local_140] = uStack_244 | local_cc;
                    fVar28 = *local_ec;
                    pdVar45[iVar37] = (dword)fVar28;
                    fVar19 = *local_e0;
                    pdVar45[iVar14] = (dword)fVar19;
                    fVar23 = *local_dc;
                    pdVar45[local_144] = (dword)fVar23;
                    fVar16 = *local_d0;
                    pdVar45[iVar13] = (dword)fVar16;
                    pdVar45[local_148] = uStack_244 | local_c8;
                    pdVar45[local_14c] = (dword)fVar28;
                    fVar29 = *local_e4;
                    pdVar45[local_150] = (dword)fVar29;
                    pdVar45[local_154] = (dword)fVar23;
                    fVar28 = *local_d4;
                    pdVar45[local_158] = (dword)fVar28;
                    pdVar45[local_15c] = local_124 | local_c8;
                    fVar23 = *local_e8;
                    pdVar45[iVar32] = (dword)fVar23;
                    pdVar45[local_160] = (dword)fVar29;
                    fVar29 = *local_d8;
                    pdVar45[iVar35] = (dword)fVar29;
                    pdVar45[iVar24] = (dword)fVar28;
                    pdVar45[iVar48] = local_124 | local_cc;
                    pdVar45[iVar40] = (dword)fVar23;
                    pdVar45[iVar41] = (dword)fVar19;
                    pdVar45[iVar42] = (dword)fVar29;
                    pdVar45[iVar44] = (dword)fVar16;
                    pdVar45[iVar46] = 0x1393;
                    pdVar45[iVar47] = 10;
                    pdVar45[iVar10] = 0x5c8;
                    pdVar45[iVar12] = 0x20000;
                    uVar33 = uVar33 - iVar26;
                    pdVar45 = pdVar45 + iVar26;
                    local_124 = local_110;
                    if (uStack_244 + 0x10 < local_110) {
                      local_124 = uStack_244 + 0x10;
                    }
                    bVar4 = false;
                    if (local_110 <= uVar36) goto LAB_0000a09c;
                    uVar18 = uVar36 + 8;
                    uVar38 = uVar36;
LAB_00008bec:
                    if (uVar33 < 0x1a) break;
                    local_f8 = *(short *)(param_1 + 0x50);
                    iVar24 = 0x10;
                    iVar26 = 0x1a;
                    iVar35 = 0xf;
                    iVar12 = 0x19;
                    iVar10 = 0x18;
                    iVar47 = 0x17;
                    iVar46 = 0x16;
                    iVar44 = 0x15;
                    iVar42 = 0x14;
                    iVar41 = 0x13;
                    iVar40 = 0x12;
                    iVar48 = 0x11;
                    iVar32 = 0xd;
                    iVar13 = 6;
                    iVar14 = 4;
                    local_f6 = *(short *)(param_1 + 0x52);
                    local_160 = 0xe;
                    local_15c = 0xc;
                    local_154 = 10;
                    local_150 = 9;
                    local_14c = 8;
                    local_148 = 7;
                    local_158 = 0xb;
                    local_140 = 2;
                    iVar37 = 3;
                    local_144 = 5;
                    local_13c = 1;
                    local_138 = 0;
                    uVar36 = uVar18;
                    uStack_244 = uVar38;
                  }
                  local_2e8 = *(float *)(param_1 + 0x18);
                  local_2ec = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar45 = 0x5c8;
                    local_2ec = 2.8026e-45;
                    pdVar45[1] = 0xc000;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar45[(int)local_2ec] = 0x1000000;
                  puVar7 = PTR_0000e694;
                  puVar25 = *(uint **)(param_1 + 0x7c);
                  *puVar25 = ((int)pdVar45 - (int)puVar25 >> 2) + (int)local_2ec | *puVar25;
                  iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar7,&local_2e8,&local_2ec,1);
                  if (iVar24 == 0) {
                    *(undefined4 *)((int)local_2e8 + 0x1c) = 0;
                    *(float *)(param_1 + 0x18) = local_2e8;
                    pdVar45 = (dword *)((int)local_2e8 + 0x20);
                    pdVar22 = (dword *)((int)local_2e8 + 0x38);
                    *(int *)(param_1 + 0x7c) = (int)local_2e8 + 0x1c;
                    pdVar15 = (dword *)((int)local_2e8 + 0x24);
                    pdVar31 = (dword *)((int)local_2e8 + 0x28);
                    pdVar17 = (dword *)((int)local_2e8 + 0x2c);
                    pdVar20 = (dword *)((int)local_2e8 + 0x30);
                    pdVar27 = (dword *)((int)local_2e8 + 0x34);
                    uVar36 = uVar38 + 8;
                    uStack_244 = uVar38;
                    uVar33 = uVar30;
                  }
                  else {
                    pdVar22 = &__mh_bundle_header.flags;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar27 = &__mh_bundle_header.sizeofcmds;
                    pdVar20 = &__mh_bundle_header.ncmds;
                    pdVar17 = &__mh_bundle_header.filetype;
                    pdVar31 = &__mh_bundle_header.cpusubtype;
                    pdVar15 = &__mh_bundle_header.cputype;
                    pdVar45 = (dword *)0x0;
                    uVar36 = uVar38 + 8;
                    uStack_244 = uVar38;
                    uVar33 = uVar30;
                  }
                } while( true );
              }
LAB_0000a09c:
              local_120 = local_118;
              if (local_11c + 0x10 < local_118) {
                local_120 = local_11c + 0x10;
              }
              uVar18 = local_11c + 8;
            } while (local_11c + 8 < local_118);
          }
          if (uVar33 < 0x86) {
            local_2ec = *(float *)(param_1 + 0x18);
            local_2e8 = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *pdVar45 = 0x5c8;
              local_2e8 = 2.8026e-45;
              pdVar45[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            pdVar45[(int)local_2e8] = 0x1000000;
            puVar25 = *(uint **)(param_1 + 0x7c);
            *puVar25 = ((int)pdVar45 - (int)puVar25 >> 2) + (int)local_2e8 | *puVar25;
            iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&local_2ec,&local_2e8,1);
            if (iVar24 == 0) {
              *(undefined4 *)((int)local_2ec + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_2ec;
              pdVar45 = (dword *)((int)local_2ec + 0x20);
              pdVar31 = (dword *)((int)local_2ec + 0x38);
              *(int *)(param_1 + 0x7c) = (int)local_2ec + 0x1c;
              pdVar15 = (dword *)((int)local_2ec + 0x24);
              pdVar17 = (dword *)((int)local_2ec + 0x28);
              pdVar20 = (dword *)((int)local_2ec + 0x2c);
              pdVar27 = (dword *)((int)local_2ec + 0x30);
              pdVar22 = (dword *)((int)local_2ec + 0x34);
              uVar33 = uVar30;
            }
            else {
              pdVar45 = (dword *)0x0;
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              pdVar15 = &__mh_bundle_header.cputype;
              pdVar17 = &__mh_bundle_header.cpusubtype;
              pdVar20 = &__mh_bundle_header.filetype;
              pdVar27 = &__mh_bundle_header.ncmds;
              pdVar22 = &__mh_bundle_header.sizeofcmds;
              pdVar31 = &__mh_bundle_header.flags;
              uVar33 = uVar30;
            }
          }
          else {
            pdVar15 = pdVar45 + 1;
            pdVar17 = pdVar45 + 2;
            pdVar20 = pdVar45 + 3;
            pdVar27 = pdVar45 + 4;
            pdVar22 = pdVar45 + 5;
            pdVar31 = pdVar45 + 6;
          }
          puVar25 = *(uint **)(param_1 + 0x7c);
          *puVar25 = (int)pdVar45 - (int)puVar25 >> 2 | *puVar25;
          *(dword **)(param_1 + 0x7c) = pdVar45;
          *pdVar45 = 0x11000000;
          *pdVar15 = *(dword *)(param_1 + 0x84);
          *pdVar17 = 0;
          *pdVar20 = 0;
          puVar25 = *(uint **)(param_1 + 0x7c);
          *puVar25 = (int)pdVar27 - (int)puVar25 >> 2 | *puVar25;
          *(dword **)(param_1 + 0x7c) = pdVar27;
          *pdVar27 = 0x4000000;
          *pdVar22 = *(dword *)*DAT_0000e6e4;
          puVar8 = DAT_0000e6e4;
          iVar24 = DAT_0000e6e4[0xc];
          if (iVar24 == 3) {
            iVar24 = 0xb;
          }
          else if (iVar24 == 6) {
            iVar24 = 0xc;
          }
          iVar24 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar31,DAT_0000e6e4 + 3,iVar24,0,0,0,0);
          uStack_1c4 = local_10c;
          uStack_1b4 = local_114;
          uStack_1bc = local_110;
          uStack_1ac = local_118;
          local_1c8 = 0x43300000;
          local_1c0 = 0x43300000;
          local_1b8 = 0x43300000;
          local_1b0 = 0x43300000;
          pdVar31[iVar24] = 0xc00c3500;
          pdVar31[iVar24 + 1] = 0x4003d;
          local_1a8 = 0x43300000;
          uStack_1a4 = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
          local_2fc = (float)((double)(float)((double)CONCAT44(0x43300000,local_10c) -
                                             4503599627370496.0) *
                             (1.0 / ((double)CONCAT44(0x43300000,uStack_1a4) - 4503601774854144.0)))
          ;
          local_1a0 = 0x43300000;
          uStack_19c = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
          local_2e4[0] = (float)((double)(float)((double)CONCAT44(0x43300000,local_110) -
                                                4503599627370496.0) *
                                (1.0 / ((double)CONCAT44(0x43300000,uStack_19c) - 4503601774854144.0
                                       )));
          local_198 = 0x43300000;
          uStack_194 = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
          local_2e8 = (float)((double)(float)((double)CONCAT44(0x43300000,local_114) -
                                             4503599627370496.0) *
                             (1.0 / ((double)CONCAT44(0x43300000,uStack_194) - 4503601774854144.0)))
          ;
          local_190 = 0x43300000;
          uStack_18c = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
          local_2ec = (float)((double)(float)((double)CONCAT44(0x43300000,local_118) -
                                             4503599627370496.0) *
                             (1.0 / ((double)CONCAT44(0x43300000,uStack_18c) - 4503601774854144.0)))
          ;
          pdVar31[iVar24 + 2] = local_10c | local_118 << 0x10;
          pdVar31[iVar24 + 3] = (dword)local_2fc;
          pdVar31[iVar24 + 4] = (dword)local_2ec;
          pdVar31[iVar24 + 5] = local_10c | local_114 << 0x10;
          pdVar31[iVar24 + 6] = (dword)local_2fc;
          pdVar31[iVar24 + 7] = (dword)local_2e8;
          pdVar31[iVar24 + 8] = local_110 | local_114 << 0x10;
          pdVar31[iVar24 + 9] = (dword)local_2e4[0];
          pdVar31[iVar24 + 10] = (dword)local_2e8;
          pdVar31[iVar24 + 0xb] = local_110 | local_118 << 0x10;
          pdVar31[iVar24 + 0xc] = (dword)local_2e4[0];
          pdVar31[iVar24 + 0xd] = (dword)local_2ec;
          pdVar31[iVar24 + 0xe] = 0x1393;
          pdVar31[iVar24 + 0xf] = 10;
          pdVar31[iVar24 + 0x10] = 0x5c8;
          pdVar31[iVar24 + 0x11] = 0x20000;
          uVar33 = (uVar33 - 6) - (iVar24 + 0x12);
          puVar49 = puVar49 + 4;
          pdVar45 = pdVar31 + iVar24 + 0x12;
          local_104 = local_104 + 1;
        } while (local_104 < (uint)param_5[0x16]);
      }
      *(dword **)(param_1 + 0x80) = pdVar45;
      return 0;
    }
  }
  else {
    puVar49 = *(undefined4 **)(param_1 + 0x80);
    iVar24 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
    local_fc = iVar24 - 7;
    if (puVar49 != (undefined4 *)0x0) {
      uVar30 = param_5[0x16];
      uVar33 = local_fc - ((int)puVar49 - (*(int *)(param_1 + 0x18) + 0x20) >> 2);
      local_100 = (iVar24 - 0x75U) / 0xc - 1;
      if (uVar30 != 0) {
        local_c0 = &local_300;
        local_188 = local_100 * 0xc + 0x6e;
        uVar43 = 0;
        do {
          if (uVar33 < local_188) {
            local_2fc = *(float *)(param_1 + 0x18);
            local_2e4[0] = 0.0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              *puVar49 = 0x5c8;
              local_2e4[0] = 2.8026e-45;
              puVar49[1] = 0xc000;
              *(undefined4 *)(param_1 + 0x94) = 0;
            }
            puVar49[(int)local_2e4[0]] = 0x1000000;
            puVar25 = *(uint **)(param_1 + 0x7c);
            *puVar25 = ((int)puVar49 - (int)puVar25 >> 2) + (int)local_2e4[0] | *puVar25;
            iVar24 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&local_2fc,local_2e4,1);
            uVar33 = local_fc;
            if (iVar24 == 0) {
              *(undefined4 *)((int)local_2fc + 0x1c) = 0;
              *(float *)(param_1 + 0x18) = local_2fc;
              puVar49 = (undefined4 *)((int)local_2fc + 0x20);
              *(int *)(param_1 + 0x7c) = (int)local_2fc + 0x1c;
              uVar30 = param_5[0x16];
            }
            else {
              *(undefined4 *)(param_1 + 0x7c) = 0;
              *(undefined4 *)(param_1 + 0x18) = 0;
              puVar49 = (undefined4 *)0x0;
              uVar30 = param_5[0x16];
            }
          }
          uVar34 = uVar43 + local_100;
          if (uVar34 < uVar30) {
            uVar30 = uVar34;
          }
          iVar24 = ((int (*)())_radeon3DFillSetup)(puVar49,0,param_6,param_1);
          iVar26 = uVar30 - uVar43;
          puVar49[iVar24] = iVar26 * 0xc0000 | 0xc0003500;
          iVar12 = iVar24 + 2;
          puVar49[iVar24 + 1] = iVar26 * 0x40000 | 0x3d;
          if (uVar43 < uVar30) {
            iVar24 = iVar12 * 4;
            iVar35 = *(int *)(param_1 + 0x60);
            iVar37 = *(int *)(param_1 + 100);
            iVar40 = iVar24 + 4;
            iVar41 = iVar24 + 0x28;
            iVar42 = iVar24 + 0x24;
            piVar21 = param_5 + uVar43 * 4 + 0x17;
            iVar44 = iVar24 + 0x20;
            iVar46 = iVar24 + 0x1c;
            iVar47 = iVar24 + 0x18;
            iVar32 = iVar24 + 0x14;
            iVar13 = iVar24 + 0x10;
            iVar14 = iVar24 + 0xc;
            iVar24 = iVar24 + 8;
            do {
              local_2d8 = 0x43300000;
              uStack_2d4 = *piVar21 + iVar35 ^ 0x80000000;
              local_2fc = (float)((double)CONCAT44(0x43300000,uStack_2d4) - 4503601774854144.0);
              local_2d0 = 0x43300000;
              uStack_2cc = *piVar21 + iVar35 + piVar21[2] ^ 0x80000000;
              local_300 = (float)((double)CONCAT44(0x43300000,uStack_2cc) - 4503601774854144.0);
              local_2c8 = 0x43300000;
              uStack_2c4 = piVar21[1] + iVar37 ^ 0x80000000;
              local_304 = (float)((double)CONCAT44(0x43300000,uStack_2c4) - 4503601774854144.0);
              local_2c0 = 0x43300000;
              uStack_2bc = piVar21[1] + iVar37 + piVar21[3] ^ 0x80000000;
              local_308 = (float)((double)CONCAT44(0x43300000,uStack_2bc) - 4503601774854144.0);
              puVar49[iVar12] = local_2fc;
              *(float *)((int)puVar49 + iVar40) = local_308;
              *(undefined4 *)((int)puVar49 + iVar24) = 0;
              *(float *)((int)puVar49 + iVar14) = local_2fc;
              *(float *)((int)puVar49 + iVar13) = local_304;
              *(undefined4 *)((int)puVar49 + iVar32) = 0;
              fVar9 = *local_c0;
              *(float *)((int)puVar49 + iVar47) = fVar9;
              *(float *)((int)puVar49 + iVar46) = local_304;
              *(undefined4 *)((int)puVar49 + iVar44) = 0;
              *(float *)((int)puVar49 + iVar42) = fVar9;
              *(float *)((int)puVar49 + iVar41) = local_308;
              iVar10 = iVar12 + 0xb;
              iVar40 = iVar40 + 0x30;
              iVar12 = iVar12 + 0xc;
              iVar24 = iVar24 + 0x30;
              iVar14 = iVar14 + 0x30;
              iVar13 = iVar13 + 0x30;
              iVar32 = iVar32 + 0x30;
              iVar47 = iVar47 + 0x30;
              iVar46 = iVar46 + 0x30;
              iVar44 = iVar44 + 0x30;
              iVar42 = iVar42 + 0x30;
              iVar41 = iVar41 + 0x30;
              puVar49[iVar10] = 0;
              piVar21 = piVar21 + 4;
              iVar26 = iVar26 + -1;
            } while (iVar26 != 0);
          }
          puVar49[iVar12] = 0x1393;
          puVar49[iVar12 + 1] = 10;
          puVar49[iVar12 + 2] = 0x5c8;
          puVar49[iVar12 + 3] = 0x20000;
          uVar30 = param_5[0x16];
          uVar33 = uVar33 - (iVar12 + 4);
          puVar49 = puVar49 + iVar12 + 4;
          uVar43 = uVar34;
        } while (uVar34 < uVar30);
      }
      *(undefined4 **)(param_1 + 0x80) = puVar49;
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
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  dword *pdVar9;
  dword *pdVar10;
  dword *pdVar11;
  dword *pdVar12;
  float fVar13;
  float fVar14;
  uint uVar15;
  dword *pdVar16;
  dword *pdVar17;
  float fVar18;
  float fVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  dword *pdVar30;
  int iVar31;
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
  
  pdVar30 = *(dword **)(param_1 + 0x80);
  iVar31 = *(int *)(param_1 + 0x18);
  local_cc = *(int *)(iVar31 + 0x10) - 7;
  if ((pdVar30 == (dword *)0x0) ||
     (puStack00000028 = param_5, uStack0000002c = param_6,
     iVar6 = ((int (*)())_createOffscreenBuffer)(param_1,param_1 + 0x4c,(uint)(*(int *)(param_1 + 0x70) == 3)),
     iVar6 == 0)) {
    uVar7 = 0xe00002be;
  }
  else {
    uVar21 = *puStack00000028;
    uVar8 = local_cc - ((int)pdVar30 - (iVar31 + 0x20) >> 2);
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
      dVar4 = (double)CONCAT44(0x43300000,uStack_1c4);
      dVar3 = (double)CONCAT44(0x43300000,uStack_1dc);
      puVar22 = puStack00000028;
      do {
        if (uVar8 < 0xda) {
          local_1f8 = *(float *)(param_1 + 0x18);
          local_1fc = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *pdVar30 = 0x5c8;
            local_1fc = 2.8026e-45;
            pdVar30[1] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          pdVar30[(int)local_1fc] = 0x1000000;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = ((int)pdVar30 - (int)puVar5 >> 2) + (int)local_1fc | *puVar5;
          iVar31 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       local_ac,local_b0,1);
          uVar8 = local_cc;
          if (iVar31 == 0) {
            *(undefined4 *)((int)local_1f8 + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_1f8;
            pdVar30 = (dword *)((int)local_1f8 + 0x20);
            pdVar10 = (dword *)((int)local_1f8 + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_1f8 + 0x1c;
            pdVar16 = (dword *)((int)local_1f8 + 0x24);
            pdVar17 = (dword *)((int)local_1f8 + 0x28);
            pdVar11 = (dword *)((int)local_1f8 + 0x2c);
            pdVar12 = (dword *)((int)local_1f8 + 0x30);
            pdVar9 = (dword *)((int)local_1f8 + 0x34);
          }
          else {
            pdVar30 = (dword *)0x0;
            pdVar16 = &__mh_bundle_header.cputype;
            pdVar17 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar11 = &__mh_bundle_header.filetype;
            pdVar12 = &__mh_bundle_header.ncmds;
            pdVar9 = &__mh_bundle_header.sizeofcmds;
            pdVar10 = &__mh_bundle_header.flags;
          }
        }
        else {
          pdVar16 = pdVar30 + 1;
          pdVar17 = pdVar30 + 2;
          pdVar11 = pdVar30 + 3;
          pdVar12 = pdVar30 + 4;
          pdVar9 = pdVar30 + 5;
          pdVar10 = pdVar30 + 6;
        }
        puVar5 = *(uint **)(param_1 + 0x7c);
        *puVar5 = (int)pdVar30 - (int)puVar5 >> 2 | *puVar5;
        *(dword **)(param_1 + 0x7c) = pdVar30;
        *pdVar30 = 0xa000000;
        *pdVar16 = *(dword *)(param_1 + 0x84);
        puVar5 = *(uint **)(param_1 + 0x7c);
        *puVar5 = (int)pdVar17 - (int)puVar5 >> 2 | *puVar5;
        *(dword **)(param_1 + 0x7c) = pdVar17;
        *pdVar17 = 0x10000000;
        *pdVar11 = *(dword *)*DAT_0000e6e4;
        *pdVar12 = DAT_0000e6e4[7];
        if (DAT_0000e6c0 == 0x10) {
          *pdVar9 = 3;
        }
        else {
          *pdVar9 = 6;
        }
        iVar31 = *(int *)(param_1 + 0x70);
        *pdVar10 = 0x850;
        pdVar10[1] = 0x100;
        pdVar10[2] = 0x887;
        pdVar10[3] = 0x1c000;
        pdVar10[4] = 0x82c;
        pdVar10[5] = 0;
        pdVar10[6] = 0x1002;
        pdVar10[7] = 0;
        pdVar10[8] = 0x824;
        pdVar10[9] = 1;
        pdVar10[10] = 0x825;
        pdVar10[0xb] = 2;
        pdVar10[0xc] = 0x82d;
        pdVar10[0xd] = 3;
        pdVar10[0xe] = 0x854;
        pdVar10[0xf] = 0x26010006;
        pdVar10[0x10] = 0x878;
        pdVar10[0x11] = 0xf688f688;
        pdVar10[0x12] = 0x10a2;
        pdVar10[0x13] = 0;
        pdVar10[0x14] = 0x1381;
        pdVar10[0x15] = 0;
        pdVar10[0x16] = 0x109e;
        pdVar10[0x17] = 5;
        pdVar10[0x18] = 0x1383;
        pdVar10[0x19] = 0xf;
        pdVar10[0x1a] = 0x1004;
        pdVar10[0x1b] = 0x66666666;
        pdVar10[0x1c] = 0x1005;
        pdVar10[0x1d] = 0x66666666;
        pdVar10[0x1e] = 0x10ae;
        pdVar10[0x1f] = 0;
        pdVar10[0x20] = 0x10ea;
        pdVar10[0x21] = 0x2da49525;
        pdVar10[0x22] = 0x10fa;
        pdVar10[0x23] = 0xffffff;
        pdVar10[0x24] = 0x10f4;
        pdVar10[0x25] = 0xffff;
        pdVar10[0x26] = 0x10f8;
        pdVar10[0x27] = 0;
        pdVar10[0x28] = 0x10f9;
        pdVar10[0x29] =
             *(uint *)(param_1 + 0x54) & 0x1fff | (*(uint *)(param_1 + 0x58) & 0x1fff) << 0xd;
        pdVar10[0x2a] = 0x13c0;
        pdVar10[0x2b] = 0;
        pdVar10[0x2c] = 0x13c1;
        pdVar10[0x2d] = 0;
        pdVar10[0x2e] = 0x10c0;
        pdVar10[0x2f] = 0x40002;
        pdVar10[0x30] = 0x10c1;
        pdVar10[0x31] = 0;
        pdVar10[0x32] = 0x10c8;
        pdVar10[0x33] = 0x10;
        pdVar10[0x34] = 0x101d;
        pdVar10[0x35] = 0x280c2040;
        pdVar10[0x36] = 0x1041;
        pdVar10[0x37] = 1;
        pdVar10[0x38] = 0x1040;
        pdVar10[0x39] = 0;
        pdVar10[0x3a] = 0x1100;
        pdVar10[0x3b] = 0x2a92;
        pdVar10[0x3c] = 0x1120;
        sVar1 = *(short *)(param_1 + 0x50);
        sVar2 = *(short *)(param_1 + 0x52);
        uVar15 = (int)sVar1 - 1;
        iVar6 = sVar2 + -1;
        pdVar10[0x3d] = uVar15 & 0x7ff | iVar6 * 0x800 & 0x3ff800U | 0x80000000;
        pdVar10[0x3e] = 0x1130;
        pdVar10[0x3f] = 0x5300c - (uint)(iVar31 == 3);
        pdVar10[0x40] = 0x1140;
        pdVar10[0x41] =
             *(int *)(param_1 + 0x5c) - 1U & 0x3fff | uVar15 * 0x10 & 0x8000 |
             iVar6 * 0x20 & 0x10000U;
        if (iVar31 != 3) {
          local_1c0 = 0x43300000;
          fVar14 = (float)(dVar4 - 4503599627370496.0) / 255.0;
          local_1b8 = 0x43300000;
          local_1b0 = 0x43300000;
          uStack_1ac = uStack0000002c & 0xff;
          uStack_1bc = uStack0000002c >> 0x10 & 0xff;
          uStack_1b4 = uStack0000002c >> 8 & 0xff;
          fVar18 = (float)((double)CONCAT44(0x43300000,uStack_1bc) - 4503599627370496.0) / 255.0;
          fVar19 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - 4503599627370496.0) / 255.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_1ac) - 4503599627370496.0) / 255.0;
        }
        else {
          local_1d8 = 0x43300000;
          fVar18 = (float)(dVar3 - 4503599627370496.0) / 31.0;
          local_1d0 = 0x43300000;
          local_1ec[1] = 176.0;
          uStack_1d4 = uStack0000002c >> 5 & 0x1f;
          uStack_1cc = uStack0000002c & 0x1f;
          uStack_1e4 = uStack0000002c >> 0xf & 1;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_1e4) - 4503599627370496.0);
          fVar19 = (float)((double)CONCAT44(0x43300000,uStack_1d4) - 4503599627370496.0) / 31.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_1cc) - 4503599627370496.0) / 31.0;
        }
        pdVar10[0x42] = 0x1094;
        pdVar10[0x43] = 0x10000;
        pdVar10[0x44] = 0x1095;
        pdVar10[0x45] = (dword)fVar18;
        pdVar10[0x46] = 0x1095;
        pdVar10[0x47] = (dword)fVar19;
        pdVar10[0x48] = 0x1095;
        pdVar10[0x49] = (dword)fVar13;
        pdVar10[0x4a] = 0x1095;
        pdVar10[0x4b] = (dword)fVar14;
        if (iVar31 != 3) {
          uStack_184 = uVar21 >> 0x18;
          local_188 = 0x43300000;
          uStack_17c = uVar21 >> 0x10 & 0xff;
          local_180 = 0x43300000;
          local_178 = 0x43300000;
          local_170 = 0x43300000;
          uStack_174 = uVar21 >> 8 & 0xff;
          uStack_16c = uVar21 & 0xff;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_184) - 4503599627370496.0) / 255.0;
          fVar18 = (float)((double)CONCAT44(0x43300000,uStack_17c) - 4503599627370496.0) / 255.0;
          fVar19 = (float)((double)CONCAT44(0x43300000,uStack_174) - 4503599627370496.0) / 255.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_16c) - 4503599627370496.0) / 255.0;
          local_a0 = fVar13;
        }
        else {
          uStack_19c = uVar21 >> 10 & 0x1f;
          local_1a0 = 0x43300000;
          uStack_194 = uVar21 >> 5 & 0x1f;
          local_198 = 0x43300000;
          local_190 = 0x43300000;
          local_1a8 = 0x43300000;
          uStack_18c = uVar21 & 0x1f;
          uStack_1a4 = uVar21 >> 0xf & 1;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_1a4) - 4503599627370496.0);
          fVar18 = (float)((double)CONCAT44(0x43300000,uStack_19c) - 4503599627370496.0) / 31.0;
          fVar19 = (float)((double)CONCAT44(0x43300000,uStack_194) - 4503599627370496.0) / 31.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_18c) - 4503599627370496.0) / 31.0;
          local_a0 = fVar14;
        }
        pdVar10[0x4c] = 0x1095;
        pdVar10[0x4d] = (dword)fVar18;
        pdVar10[0x4e] = 0x1095;
        pdVar10[0x4f] = (dword)fVar19;
        pdVar10[0x50] = 0x1095;
        pdVar10[0x51] = (dword)fVar13;
        pdVar10[0x52] = 0x1095;
        pdVar10[0x53] = (dword)fVar14;
        pdVar10[0x54] = 0x1094;
        pdVar10[0x55] = 0;
        pdVar10[0x56] = 0x1095;
        pdVar10[0x57] = 0x7803;
        pdVar10[0x58] = 0x1095;
        pdVar10[0x59] = 0x2400000;
        pdVar10[0x5a] = 0x1095;
        pdVar10[0x5b] = 0x3900e400;
        pdVar10[0x5c] = 0x1095;
        pdVar10[0x5d] = 0;
        pdVar10[0x5e] = 0x1095;
        pdVar10[0x5f] = 0;
        pdVar10[0x60] = 0x1095;
        pdVar10[0x61] = 0;
        pdVar10[0x62] = 0x1095;
        pdVar10[99] = 0x7804;
        pdVar10[100] = 0x1095;
        pdVar10[0x65] = 0x40040000;
        pdVar10[0x66] = 0x1095;
        pdVar10[0x67] = 0x40040000;
        pdVar10[0x68] = 0x1095;
        pdVar10[0x69] = local_c8;
        pdVar10[0x6a] = 0x1095;
        pdVar10[0x6b] = local_c4;
        pdVar10[0x6c] = 0x1095;
        pdVar10[0x6d] = local_c0;
        pdVar10[0x6e] = 0x1095;
        pdVar10[0x6f] = 0x7800;
        pdVar10[0x70] = 0x1095;
        pdVar10[0x71] = 1;
        pdVar10[0x72] = 0x1095;
        pdVar10[0x73] = 1;
        pdVar10[0x74] = 0x1095;
        pdVar10[0x75] = local_bc;
        pdVar10[0x76] = 0x1095;
        pdVar10[0x77] = local_b8;
        pdVar10[0x78] = 0x1095;
        pdVar10[0x79] = 0x12;
        pdVar10[0x7a] = 0x1095;
        pdVar10[0x7b] = 0x7800;
        pdVar10[0x7c] = 0x1095;
        pdVar10[0x7d] = 0x140400;
        pdVar10[0x7e] = 0x1095;
        pdVar10[0x7f] = 0x140400;
        pdVar10[0x80] = 0x1095;
        pdVar10[0x81] = local_b4;
        pdVar10[0x82] = 0x1095;
        pdVar10[0x83] = 0x60d036;
        pdVar10[0x84] = 0x1095;
        pdVar10[0x85] = 0xdda22038;
        pdVar10[0x86] = 0x1095;
        pdVar10[0x87] = 0x7800;
        pdVar10[0x88] = 0x1095;
        pdVar10[0x89] = 0x40040400;
        pdVar10[0x8a] = 0x1095;
        pdVar10[0x8b] = 0x40040400;
        pdVar10[0x8c] = 0x1095;
        pdVar10[0x8d] = local_c8;
        pdVar10[0x8e] = 0x1095;
        pdVar10[0x8f] = local_c4;
        pdVar10[0x90] = 0x1095;
        pdVar10[0x91] = local_c0;
        pdVar10[0x92] = 0x1095;
        pdVar10[0x93] = 0x7800;
        pdVar10[0x94] = 0x1095;
        pdVar10[0x95] = 1;
        pdVar10[0x96] = 0x1095;
        pdVar10[0x97] = 1;
        pdVar10[0x98] = 0x1095;
        pdVar10[0x99] = local_bc;
        pdVar10[0x9a] = 0x1095;
        pdVar10[0x9b] = local_b8;
        pdVar10[0x9c] = 0x1095;
        pdVar10[0x9d] = 0x12;
        pdVar10[0x9e] = 0x1095;
        pdVar10[0x9f] = 0x78101;
        pdVar10[0xa0] = 0x1095;
        pdVar10[0xa1] = 0x140003;
        pdVar10[0xa2] = 0x1095;
        pdVar10[0xa3] = 0x140003;
        pdVar10[0xa4] = 0x1095;
        pdVar10[0xa5] = local_b4;
        pdVar10[0xa6] = 0x1095;
        pdVar10[0xa7] = 0x60d006;
        pdVar10[0xa8] = 0x1095;
        pdVar10[0xa9] = 0xdda22008;
        pdVar10[0xaa] = 0x1189;
        pdVar10[0xab] = 0;
        pdVar10[0xac] = 0x1181;
        pdVar10[0xad] = 5;
        pdVar10[0xae] = 0x118d;
        pdVar10[0xaf] = 0x60000;
        pdVar10[0xb0] = 0x118e;
        pdVar10[0xb1] = 0;
        pdVar10[0xb2] = 0x118c;
        pdVar10[0xb3] = 0x60000;
        pdVar10[0xb4] = 0x11a9;
        pdVar10[0xb5] = 0x1b01;
        pdVar10[0xb6] = 0x11aa;
        pdVar10[0xb7] = 0xf;
        pdVar10[0xb8] = 0x11ab;
        pdVar10[0xb9] = 0xf;
        pdVar10[0xba] = 0x11ac;
        pdVar10[0xbb] = 0xf;
        pdVar10[0xbc] = 0x12f0;
        pdVar10[0xbd] = 0;
        pdVar10[0xbe] = 0x12f5;
        pdVar10[0xbf] = 0;
        local_148 = 0x43300000;
        local_138 = 0x43300000;
        uStack_144 = (int)sVar1 ^ 0x80000000;
        uStack_134 = (int)sVar2 ^ 0x80000000;
        local_168 = 0x43300000;
        local_160 = 0x43300000;
        local_158 = 0x43300000;
        local_150 = 0x43300000;
        uVar29 = puVar22[0x17] + *(int *)(param_1 + 0x60);
        uVar27 = puVar22[0x18] + *(int *)(param_1 + 100);
        uVar28 = uVar29 + puVar22[0x19];
        uVar15 = uVar27 + puVar22[0x1a];
        uStack_164 = uVar29 ^ 0x80000000;
        uStack_154 = uVar27 ^ 0x80000000;
        uStack_15c = uVar28 ^ 0x80000000;
        uStack_14c = uVar15 ^ 0x80000000;
        local_208 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_144) - 4503601774854144.0);
        local_200 = 1.0 / (float)((double)CONCAT44(0x43300000,uStack_134) - 4503601774854144.0);
        local_1ec[0] = local_208 *
                       (float)((double)CONCAT44(0x43300000,uStack_164) - 4503601774854144.0);
        local_208 = local_208 *
                    (float)((double)CONCAT44(0x43300000,uStack_15c) - 4503601774854144.0);
        local_204 = local_200 *
                    (float)((double)CONCAT44(0x43300000,uStack_154) - 4503601774854144.0);
        local_200 = local_200 *
                    (float)((double)CONCAT44(0x43300000,uStack_14c) - 4503601774854144.0);
        pdVar10[0xc0] = 0xc00c3500;
        pdVar10[0xc1] = 0x4003d;
        uVar26 = uVar29 | uVar15 * 0x10000;
        pdVar10[0xc2] = uVar26;
        fVar18 = *local_d4;
        pdVar10[0xc3] = (dword)fVar18;
        fVar14 = *local_d8;
        pdVar10[0xc4] = (dword)fVar14;
        uVar25 = uVar29 | uVar27 * 0x10000;
        pdVar10[0xc5] = uVar25;
        pdVar10[0xc6] = (dword)fVar18;
        fVar18 = *local_dc;
        pdVar10[199] = (dword)fVar18;
        uVar24 = uVar28 | uVar27 * 0x10000;
        pdVar10[200] = uVar24;
        fVar19 = *local_e0;
        pdVar10[0xc9] = (dword)fVar19;
        pdVar10[0xca] = (dword)fVar18;
        uVar23 = uVar28 | uVar15 * 0x10000;
        pdVar10[0xcb] = uVar23;
        pdVar10[0xcc] = (dword)fVar19;
        pdVar10[0xcd] = (dword)fVar14;
        pdVar10[0xce] = 0x1393;
        pdVar10[0xcf] = 10;
        pdVar10[0xd0] = 0x5c8;
        pdVar10[0xd1] = 0x20000;
        puVar20 = pdVar10 + 0xd2;
        if (uVar8 - 0xd8 < 0x86) {
          local_1fc = *(float *)(param_1 + 0x18);
          local_1f8 = 0.0;
          if (*(int *)(param_1 + 0x8c) == 0) {
            *puVar20 = 0x5c8;
            local_1f8 = 2.8026e-45;
            pdVar10[0xd3] = 0xc000;
            *(undefined4 *)(param_1 + 0x94) = 0;
          }
          puVar20[(int)local_1f8] = 0x1000000;
          puVar5 = *(uint **)(param_1 + 0x7c);
          *puVar5 = ((int)puVar20 - (int)puVar5 >> 2) + (int)local_1f8 | *puVar5;
          iVar31 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       local_b0,local_ac,1);
          uVar8 = local_cc;
          if (iVar31 == 0) {
            *(undefined4 *)((int)local_1fc + 0x1c) = 0;
            *(float *)(param_1 + 0x18) = local_1fc;
            puVar20 = (undefined4 *)((int)local_1fc + 0x20);
            pdVar30 = (dword *)((int)local_1fc + 0x38);
            *(int *)(param_1 + 0x7c) = (int)local_1fc + 0x1c;
            pdVar9 = (dword *)((int)local_1fc + 0x24);
            pdVar11 = (dword *)((int)local_1fc + 0x28);
            pdVar12 = (dword *)((int)local_1fc + 0x2c);
            pdVar16 = (dword *)((int)local_1fc + 0x30);
            pdVar10 = (dword *)((int)local_1fc + 0x34);
          }
          else {
            puVar20 = (undefined4 *)0x0;
            pdVar9 = &__mh_bundle_header.cputype;
            pdVar11 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(param_1 + 0x7c) = 0;
            *(undefined4 *)(param_1 + 0x18) = 0;
            pdVar12 = &__mh_bundle_header.filetype;
            pdVar16 = &__mh_bundle_header.ncmds;
            pdVar10 = &__mh_bundle_header.sizeofcmds;
            pdVar30 = &__mh_bundle_header.flags;
          }
        }
        else {
          pdVar30 = pdVar10 + 0xd8;
          pdVar9 = pdVar10 + 0xd3;
          pdVar11 = pdVar10 + 0xd4;
          pdVar12 = pdVar10 + 0xd5;
          pdVar16 = pdVar10 + 0xd6;
          pdVar10 = pdVar10 + 0xd7;
          uVar8 = uVar8 - 0xd8;
        }
        puVar5 = *(uint **)(param_1 + 0x7c);
        *puVar5 = (int)puVar20 - (int)puVar5 >> 2 | *puVar5;
        *(undefined4 **)(param_1 + 0x7c) = puVar20;
        *puVar20 = 0x11000000;
        *pdVar9 = *(dword *)(param_1 + 0x84);
        *pdVar11 = 0;
        *pdVar12 = 0;
        puVar5 = *(uint **)(param_1 + 0x7c);
        *puVar5 = (int)pdVar16 - (int)puVar5 >> 2 | *puVar5;
        *(dword **)(param_1 + 0x7c) = pdVar16;
        *pdVar16 = 0x4000000;
        *pdVar10 = *(dword *)*DAT_0000e6e4;
        puVar20 = DAT_0000e6e4;
        iVar31 = DAT_0000e6e4[0xc];
        if (iVar31 == 3) {
          iVar31 = 0xb;
        }
        else if (iVar31 == 6) {
          iVar31 = 0xc;
        }
        iVar31 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar30,DAT_0000e6e4 + 3,iVar31,0,0,0,0);
        local_128 = 0x43300000;
        local_120 = 0x43300000;
        local_118 = 0x43300000;
        local_110 = 0x43300000;
        pdVar30[iVar31] = 0xc00c3500;
        pdVar30[iVar31 + 1] = 0x4003d;
        local_108 = 0x43300000;
        uStack_104 = (int)*(short *)(puVar20 + 4) ^ 0x80000000;
        local_1fc = (float)((double)(float)((double)CONCAT44(0x43300000,uVar29) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,uStack_104) - 4503601774854144.0)));
        local_100 = 0x43300000;
        uStack_fc = (int)*(short *)(puVar20 + 4) ^ 0x80000000;
        local_1f0 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar28) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,uStack_fc) - 4503601774854144.0)));
        local_f8 = 0x43300000;
        uStack_f4 = (int)*(short *)((int)puVar20 + 0x12) ^ 0x80000000;
        local_1f4 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar27) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,uStack_f4) - 4503601774854144.0)));
        local_f0 = 0x43300000;
        uStack_ec = (int)*(short *)((int)puVar20 + 0x12) ^ 0x80000000;
        local_1f8 = (float)((double)(float)((double)CONCAT44(0x43300000,uVar15) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,uStack_ec) - 4503601774854144.0)));
        pdVar30[iVar31 + 2] = uVar26;
        fVar18 = *local_b0;
        pdVar30[iVar31 + 3] = (dword)fVar18;
        fVar14 = *local_ac;
        pdVar30[iVar31 + 4] = (dword)fVar14;
        pdVar30[iVar31 + 5] = uVar25;
        pdVar30[iVar31 + 6] = (dword)fVar18;
        fVar18 = *local_e4;
        pdVar30[iVar31 + 7] = (dword)fVar18;
        pdVar30[iVar31 + 8] = uVar24;
        fVar19 = *local_e8;
        pdVar30[iVar31 + 9] = (dword)fVar19;
        pdVar30[iVar31 + 10] = (dword)fVar18;
        pdVar30[iVar31 + 0xb] = uVar23;
        pdVar30[iVar31 + 0xc] = (dword)fVar19;
        pdVar30[iVar31 + 0xd] = (dword)fVar14;
        pdVar30[iVar31 + 0xe] = 0x1393;
        pdVar30[iVar31 + 0xf] = 10;
        pdVar30[iVar31 + 0x10] = 0x5c8;
        pdVar30[iVar31 + 0x11] = 0x20000;
        uVar8 = (uVar8 - 6) - (iVar31 + 0x12);
        puVar22 = puVar22 + 4;
        pdVar30 = pdVar30 + iVar31 + 0x12;
        local_d0 = local_d0 + 1;
        uStack_124 = uVar29;
        uStack_11c = uVar28;
        uStack_114 = uVar27;
        uStack_10c = uVar15;
      } while (local_d0 < puStack00000028[0x16]);
    }
    uVar7 = 0;
    *(dword **)(param_1 + 0x80) = pdVar30;
  }
  return uVar7;
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
  char *pcVar3;
  bool bVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  dword *pdVar12;
  int iVar13;
  dword *pdVar14;
  dword *pdVar15;
  segment_command *psVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  dword *pdVar20;
  int iVar21;
  float fVar22;
  dword *pdVar23;
  uint *puVar24;
  float *pfVar25;
  dword *pdVar26;
  int iVar27;
  float fVar28;
  float fVar29;
  int iVar30;
  dword *pdVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  dword *pdVar38;
  dword *pdVar39;
  undefined4 *puVar40;
  dword *pdVar41;
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
    puVar40 = *(undefined4 **)(param_1 + 0x80);
    fVar29 = *(float *)(param_1 + 0x18);
    if (puVar40 != (undefined4 *)0x0) {
      if ((uint)((*(int *)((int)fVar29 + 0x10) + -7) - ((int)puVar40 - ((int)fVar29 + 0x20) >> 2)) <
          param_5[0x16] * 0xc + 0x6eU) {
        local_1a0 = 0.0;
        if (*(int *)(param_1 + 0x8c) == 0) {
          *puVar40 = 0x5c8;
          local_1a0 = 2.8026e-45;
          puVar40[1] = 0xc000;
          *(undefined4 *)(param_1 + 0x94) = 0;
        }
        puVar40[(int)local_1a0] = 0x1000000;
        puVar5 = PTR_0000e694;
        puVar24 = *(uint **)(param_1 + 0x7c);
        *puVar24 = ((int)puVar40 - (int)puVar24 >> 2) + (int)local_1a0 | *puVar24;
        local_1a4 = fVar29;
        iVar10 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,*(undefined4 *)puVar5,
                                     &local_1a4,&local_1a0,1);
        if (iVar10 == 0) {
          *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
          *(float *)(param_1 + 0x18) = local_1a4;
          puVar40 = (undefined4 *)((int)local_1a4 + 0x20);
          *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
        }
        else {
          puVar40 = (undefined4 *)0x0;
          *(undefined4 *)(param_1 + 0x7c) = 0;
          *(undefined4 *)(param_1 + 0x18) = 0;
        }
      }
      iVar10 = ((int (*)())_radeon3DFillSetup)(puVar40,0,param_6,param_1);
      iVar18 = param_5[0x16];
      puVar24 = puVar40 + iVar10;
      *puVar24 = iVar18 * 0xc0000 | 0xc0003500;
      pfVar11 = (float *)(puVar24 + 2);
      puVar24[1] = iVar18 << 0x12 | 0x3d;
      uVar9 = param_5[0x17] + *(int *)(param_1 + 100);
      fVar29 = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - 4503601774854144.0);
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar9 + param_5[0x18] ^ 0x80000000) -
                     4503601774854144.0);
      if (iVar18 != 0) {
        iVar10 = *(int *)(param_1 + 0x60);
        if (iVar18 == 0) {
          iVar18 = 1;
        }
        do {
          fVar28 = (float)((double)CONCAT44(0x43300000,param_5[0x19] + iVar10 ^ 0x80000000) -
                          4503601774854144.0);
          fVar22 = (float)((double)CONCAT44(0x43300000,param_5[0x1a] + iVar10 ^ 0x80000000) -
                          4503601774854144.0);
          *pfVar11 = fVar28;
          pfVar11[1] = fVar1;
          pfVar11[2] = 0.0;
          pfVar11[3] = fVar28;
          pfVar11[4] = fVar29;
          pfVar11[5] = 0.0;
          pfVar11[6] = fVar22;
          pfVar11[7] = fVar29;
          pfVar11[8] = 0.0;
          pfVar11[9] = fVar22;
          pfVar11[10] = fVar1;
          pfVar25 = pfVar11 + 0xb;
          pfVar11 = pfVar11 + 0xc;
          *pfVar25 = 0.0;
          param_5 = param_5 + 2;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      *pfVar11 = 7.02191e-42;
      pfVar11[1] = 1.4013e-44;
      pfVar11[2] = 2.07392e-42;
      pfVar11[3] = 1.83671e-40;
      *(float **)(param_1 + 0x80) = pfVar11 + 4;
      return 0;
    }
  }
  else {
    pdVar39 = *(dword **)(param_1 + 0x80);
    iVar10 = *(int *)(param_1 + 0x18);
    uVar9 = *(int *)(iVar10 + 0x10) - 7;
    if ((pdVar39 != (dword *)0x0) &&
       (iVar18 = ((int (*)())_createTextureBuffer)(param_1,0x40,0x40,(uint)(*(int *)(param_1 + 0x70) == 3)),
       iVar18 != 0)) {
      local_e8 = 0xbaa4;
      uVar34 = uVar9 - ((int)pdVar39 - (iVar10 + 0x20) >> 2);
      _fillTextureWithPattern(param_6,param_4 & 0x7ffff000,*param_5,param_5[1]);
      iVar10 = *(int *)(((unsigned char *)0x00002ca4) + local_e8);
      local_104 = *(int *)(iVar10 + 0x30);
      if (local_104 == 3) {
        local_104 = 0xb;
      }
      else if (local_104 == 6) {
        local_104 = 0xc;
      }
      uVar19 = param_5[0x16];
      local_178 = 0x43300000;
      uVar32 = param_5[0x17] + *(int *)(param_1 + 100);
      iStack_174 = (uVar32 & 7) + param_5[3];
      uVar35 = uVar32 + param_5[0x18];
      fVar29 = (float)((double)CONCAT44(0x43300000,iStack_174) - 4503599627370496.0);
      if (uVar19 != 0) {
        local_118 = uVar35;
        if (uVar32 + 8 < uVar35) {
          local_118 = uVar32 + 8;
        }
        bVar4 = true;
        local_100 = 0;
        local_10c = param_5;
        do {
          local_170 = 0x43300000;
          uVar36 = *(int *)(param_1 + 0x60) + local_10c[0x19];
          iStack_16c = (uVar36 & 7) + param_5[2];
          uVar37 = *(int *)(param_1 + 0x60) + local_10c[0x1a];
          fVar1 = (float)((double)CONCAT44(0x43300000,iStack_16c) - 4503599627370496.0);
          if (uVar32 < uVar35) {
            local_114 = uVar36 + 8;
            local_108 = uVar37;
            if (local_114 < uVar37) {
              local_108 = local_114;
            }
            local_f4 = uVar36 & 0x1fff;
            local_f0 = uVar37 & 0x1fff;
            local_f8 = 0xc000;
            local_ec = 0x4003d;
            local_fc = 1;
            uVar19 = uVar32;
            uVar6 = local_118;
            do {
              if (uVar36 < uVar37) {
                uVar8 = uVar36;
                uVar33 = local_108;
                if (!bVar4) {
                  local_e4 = uVar6 << 0x10;
                  local_e0 = uVar19 << 0x10;
                  local_dc = uVar6 - uVar19;
                  uVar6 = local_114;
                  goto LAB_0000c1c8;
                }
                if (uVar34 < 0x8e) {
                  local_1a4 = *(float *)(param_1 + 0x18);
                  local_1a0 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar39 = 0x5c8;
                    local_1a0 = 2.8026e-45;
                    pdVar39[1] = local_f8;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar39[(int)local_1a0] = 0x1000000;
                  puVar5 = PTR_0000e694;
                  puVar24 = *(uint **)(param_1 + 0x7c);
                  *puVar24 = ((int)pdVar39 - (int)puVar24 >> 2) + (int)local_1a0 | *puVar24;
                  iVar18 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar5,&local_1a4,&local_1a0,1);
                  uVar33 = local_108;
                  if (iVar18 == 0) {
                    local_e4 = uVar6 << 0x10;
                    local_e0 = uVar19 << 0x10;
                    local_dc = uVar6 - uVar19;
                    *(undefined4 *)((int)local_1a4 + 0x1c) = 0;
                    pdVar39 = (dword *)((int)local_1a4 + 0x20);
                    local_110 = local_114;
                    *(float *)(param_1 + 0x18) = local_1a4;
                    pdVar41 = (dword *)((int)local_1a4 + 0x48);
                    *(int *)(param_1 + 0x7c) = (int)local_1a4 + 0x1c;
                    pdVar38 = (dword *)((int)local_1a4 + 0x24);
                    pdVar31 = (dword *)((int)local_1a4 + 0x28);
                    pdVar12 = (dword *)((int)local_1a4 + 0x2c);
                    pdVar26 = (dword *)((int)local_1a4 + 0x30);
                    pdVar14 = (dword *)((int)local_1a4 + 0x34);
                    pdVar15 = (dword *)((int)local_1a4 + 0x38);
                    psVar16 = (segment_command *)((int)local_1a4 + 0x3c);
                    pdVar20 = (dword *)((int)local_1a4 + 0x40);
                    pdVar23 = (dword *)((int)local_1a4 + 0x44);
                    uVar34 = uVar9;
                  }
                  else {
                    local_e4 = uVar6 << 0x10;
                    local_dc = uVar6 - uVar19;
                    local_e0 = uVar19 << 0x10;
                    local_110 = local_114;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar39 = (dword *)0x0;
                    pdVar38 = &__mh_bundle_header.cputype;
                    pdVar31 = &__mh_bundle_header.cpusubtype;
                    pdVar12 = &__mh_bundle_header.filetype;
                    pdVar26 = &__mh_bundle_header.ncmds;
                    pdVar14 = &__mh_bundle_header.sizeofcmds;
                    pdVar15 = &__mh_bundle_header.flags;
                    psVar16 = &(*(GhidraMachOCommand *)0x0000001c);
                    pdVar20 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    pdVar23 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar41 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    uVar34 = uVar9;
                  }
                }
                else {
                  local_e4 = uVar6 << 0x10;
                  local_e0 = uVar19 << 0x10;
                  local_dc = uVar6 - uVar19;
                  pdVar38 = pdVar39 + 1;
                  pdVar31 = pdVar39 + 2;
                  pdVar12 = pdVar39 + 3;
                  local_110 = local_114;
                  pdVar26 = pdVar39 + 4;
                  pdVar14 = pdVar39 + 5;
                  pdVar15 = pdVar39 + 6;
                  psVar16 = (segment_command *)(pdVar39 + 7);
                  pdVar20 = pdVar39 + 8;
                  pdVar23 = pdVar39 + 9;
                  pdVar41 = pdVar39 + 10;
                }
                do {
                  puVar24 = *(uint **)(param_1 + 0x7c);
                  *puVar24 = (int)pdVar39 - (int)puVar24 >> 2 | *puVar24;
                  *(dword **)(param_1 + 0x7c) = pdVar39;
                  *pdVar39 = 0x11000000;
                  *pdVar38 = *(dword *)(param_1 + 0x84);
                  *pdVar31 = 0;
                  *pdVar12 = 0;
                  puVar24 = *(uint **)(param_1 + 0x7c);
                  *puVar24 = (int)pdVar26 - (int)puVar24 >> 2 | *puVar24;
                  *(dword **)(param_1 + 0x7c) = pdVar26;
                  *pdVar26 = 0x8000000;
                  *pdVar14 = *(dword *)**(undefined4 **)(((unsigned char *)0x00002ca4) + local_e8);
                  *pdVar15 = 0;
                  psVar16->cmd = 0;
                  *pdVar20 = 0;
                  *pdVar23 = 0;
                  uVar34 = uVar34 - 10;
                  iVar13 = ((int (*)())_radeon3DCopySetup)(param_1,pdVar41,iVar10 + 0xc,local_104,0,0,0,0);
                  iVar18 = iVar13 << 2;
                  iVar27 = iVar13 + 1;
                  iVar30 = iVar13 + 2;
                  iVar21 = iVar13 + 3;
                  iVar17 = iVar13 + 4;
                  pdVar39 = pdVar41;
                  while( true ) {
                    if (local_fc != 0) {
                      pcVar3 = (char *)((int)pdVar39 + iVar18);
                      pcVar3[0] = '\0';
                      pcVar3[1] = '\0';
                      pcVar3[2] = '\x10';
                      pcVar3[3] = -8;
                      pdVar39[iVar27] = local_f4 | uVar32 * 0x2000 & 0x3ffe000;
                      pdVar39[iVar30] = 0x10f9;
                      pdVar39[iVar21] = local_f0 | uVar35 * 0x2000 & 0x3ffe000;
                      iVar18 = iVar17 << 2;
                      iVar27 = iVar17 + 1;
                      iVar30 = iVar17 + 2;
                      local_fc = 0;
                      iVar21 = iVar17 + 3;
                      iVar13 = iVar17;
                      iVar17 = iVar17 + 4;
                    }
                    iVar7 = uVar33 - uVar8;
                    if ((iVar7 == 8) && (local_dc == 8)) {
                      pcVar3 = (char *)((int)pdVar39 + iVar18);
                      pcVar3[0] = -0x40;
                      pcVar3[1] = '\f';
                      pcVar3[2] = '5';
                      pcVar3[3] = '\0';
                      pdVar39[iVar27] = local_ec;
                      local_138 = 0x43300000;
                      uStack_134 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar2 = (float)((double)(fVar1 + 0.0) *
                                     (1.0 / ((double)CONCAT44(0x43300000,uStack_134) -
                                            4503601774854144.0)));
                      local_130 = 0x43300000;
                      uStack_12c = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar28 = (float)((double)(fVar1 + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,uStack_12c) -
                                             4503601774854144.0)));
                      local_128 = 0x43300000;
                      uStack_124 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      local_1a4 = (float)((double)(fVar29 + 0.0) *
                                         (1.0 / ((double)CONCAT44(0x43300000,uStack_124) -
                                                4503601774854144.0)));
                      local_120 = 0x43300000;
                      uStack_11c = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      fVar22 = (float)((double)(fVar29 + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,uStack_11c) -
                                             4503601774854144.0)));
                      pdVar39[iVar30] = uVar8 | local_e4;
                      pdVar39[iVar21] = (dword)fVar2;
                      pdVar39[iVar17] = (dword)fVar22;
                      pdVar39[iVar13 + 5] = uVar8 | local_e0;
                      pdVar39[iVar13 + 6] = (dword)fVar2;
                      pdVar39[iVar13 + 7] = (dword)local_1a4;
                      pdVar39[iVar13 + 8] = uVar33 | local_e0;
                      local_1a0 = fVar28;
                      local_19c = fVar22;
                    }
                    else {
                      local_168 = 0x43300000;
                      local_160 = 0x43300000;
                      iStack_15c = local_dc;
                      pcVar3 = (char *)((int)pdVar39 + iVar18);
                      pcVar3[0] = -0x40;
                      pcVar3[1] = '\f';
                      pcVar3[2] = '5';
                      pcVar3[3] = '\0';
                      pdVar39[iVar27] = local_ec;
                      local_158 = 0x43300000;
                      uStack_154 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      local_19c = (float)((double)(fVar1 + 0.0) *
                                         (1.0 / ((double)CONCAT44(0x43300000,uStack_154) -
                                                4503601774854144.0)));
                      local_150 = 0x43300000;
                      uStack_14c = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar28 = (float)((double)(fVar1 + (float)((double)CONCAT44(0x43300000,iVar7) -
                                                               4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,uStack_14c) -
                                             4503601774854144.0)));
                      local_148 = 0x43300000;
                      uStack_144 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      local_1a4 = (float)((double)(fVar29 + 0.0) *
                                         (1.0 / ((double)CONCAT44(0x43300000,uStack_144) -
                                                4503601774854144.0)));
                      local_140 = 0x43300000;
                      uStack_13c = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      fVar22 = (float)((double)(fVar29 + (float)((double)CONCAT44(0x43300000,
                                                                                  local_dc) -
                                                                4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,uStack_13c) -
                                             4503601774854144.0)));
                      pdVar39[iVar30] = local_e4 | uVar8;
                      pdVar39[iVar21] = (dword)local_19c;
                      pdVar39[iVar17] = (dword)fVar22;
                      pdVar39[iVar13 + 5] = local_e0 | uVar8;
                      pdVar39[iVar13 + 6] = (dword)local_19c;
                      pdVar39[iVar13 + 7] = (dword)local_1a4;
                      pdVar39[iVar13 + 8] = local_e0 | uVar33;
                      local_1a0 = fVar22;
                      iStack_164 = iVar7;
                    }
                    pdVar39[iVar13 + 9] = (dword)fVar28;
                    pdVar39[iVar13 + 10] = (dword)local_1a4;
                    pdVar39[iVar13 + 0xb] = uVar33 | local_e4;
                    pdVar39[iVar13 + 0xc] = (dword)fVar28;
                    pdVar39[iVar13 + 0xd] = (dword)fVar22;
                    pdVar39[iVar13 + 0xe] = 0x1393;
                    pdVar39[iVar13 + 0xf] = 10;
                    pdVar39[iVar13 + 0x10] = 0x5c8;
                    pdVar39[iVar13 + 0x11] = 0x20000;
                    uVar34 = uVar34 - (iVar13 + 0x12);
                    pdVar39 = pdVar39 + iVar13 + 0x12;
                    uVar33 = uVar37;
                    if (uVar8 + 0x10 < uVar37) {
                      uVar33 = uVar8 + 0x10;
                    }
                    bVar4 = false;
                    if (uVar37 <= local_110) goto LAB_0000c820;
                    uVar6 = local_110 + 8;
                    uVar8 = local_110;
LAB_0000c1c8:
                    if (uVar34 < 0x16) break;
                    iVar17 = 4;
                    iVar21 = 3;
                    iVar30 = 2;
                    iVar27 = 1;
                    iVar18 = 0;
                    iVar13 = 0;
                    local_110 = uVar6;
                  }
                  local_1a0 = *(float *)(param_1 + 0x18);
                  local_1a4 = 0.0;
                  if (*(int *)(param_1 + 0x8c) == 0) {
                    *pdVar39 = 0x5c8;
                    local_1a4 = 2.8026e-45;
                    pdVar39[1] = local_f8;
                    *(undefined4 *)(param_1 + 0x94) = 0;
                  }
                  pdVar39[(int)local_1a4] = 0x1000000;
                  puVar5 = PTR_0000e694;
                  puVar24 = *(uint **)(param_1 + 0x7c);
                  *puVar24 = ((int)pdVar39 - (int)puVar24 >> 2) + (int)local_1a4 | *puVar24;
                  iVar18 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 0xc),0,
                                               *(undefined4 *)puVar5,&local_1a0,&local_1a4,1);
                  if (iVar18 == 0) {
                    local_110 = uVar8 + 8;
                    local_fc = 1;
                    *(undefined4 *)((int)local_1a0 + 0x1c) = 0;
                    *(float *)(param_1 + 0x18) = local_1a0;
                    pdVar39 = (dword *)((int)local_1a0 + 0x20);
                    pdVar41 = (dword *)((int)local_1a0 + 0x48);
                    *(int *)(param_1 + 0x7c) = (int)local_1a0 + 0x1c;
                    pdVar38 = (dword *)((int)local_1a0 + 0x24);
                    pdVar31 = (dword *)((int)local_1a0 + 0x28);
                    pdVar12 = (dword *)((int)local_1a0 + 0x2c);
                    pdVar26 = (dword *)((int)local_1a0 + 0x30);
                    pdVar14 = (dword *)((int)local_1a0 + 0x34);
                    pdVar15 = (dword *)((int)local_1a0 + 0x38);
                    psVar16 = (segment_command *)((int)local_1a0 + 0x3c);
                    pdVar20 = (dword *)((int)local_1a0 + 0x40);
                    pdVar23 = (dword *)((int)local_1a0 + 0x44);
                    uVar34 = uVar9;
                  }
                  else {
                    local_110 = uVar8 + 8;
                    pdVar41 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    pdVar23 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar20 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    psVar16 = &(*(GhidraMachOCommand *)0x0000001c);
                    local_fc = 1;
                    *(undefined4 *)(param_1 + 0x7c) = 0;
                    *(undefined4 *)(param_1 + 0x18) = 0;
                    pdVar15 = &__mh_bundle_header.flags;
                    pdVar14 = &__mh_bundle_header.sizeofcmds;
                    pdVar26 = &__mh_bundle_header.ncmds;
                    pdVar12 = &__mh_bundle_header.filetype;
                    pdVar31 = &__mh_bundle_header.cpusubtype;
                    pdVar38 = &__mh_bundle_header.cputype;
                    pdVar39 = (dword *)0x0;
                    uVar34 = uVar9;
                  }
                } while( true );
              }
LAB_0000c820:
              uVar8 = uVar19 + 0x10;
              uVar19 = uVar19 + 8;
              uVar6 = uVar35;
              if (uVar8 < uVar35) {
                uVar6 = uVar8;
              }
            } while (uVar19 < uVar35);
            uVar19 = param_5[0x16];
          }
          local_100 = local_100 + 1;
          local_10c = local_10c + 2;
        } while (local_100 < uVar19);
      }
      *(dword **)(param_1 + 0x80) = pdVar39;
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
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char local_58 [4];
  char acStack_54 [4];
  char acStack_50 [64];
  
  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  iVar1 = _strlen(local_58);
  builtin_strncpy(local_58 + iVar1,"$LDB",4);
  acStack_50[iVar1] = '\0';
  builtin_strncpy(acStack_54 + iVar1,"L128",4);
  iVar2 = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (iVar2 == 0) {
    local_58[iVar1] = '\0';
  }
  uVar3 = _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  uVar3 = _NSAddressOfSymbol(uVar3);
  return uVar3;
}

