#include "decls.h"

/* __AllocateSurface @ 0x2750 (1420 bytes) */
int __AllocateSurface(accel, flags, surfaceDesc, vramAddress)
  int accel;
  uint flags;
  uint *surfaceDesc;
  undefined4 vramAddress;
{
  uint uVar1;
  uint uVar2;
  undefined4 *record;
  int status;
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
  uint tiledFormatCode;
  int outCount;
  uint formatCode;
  int *scalarOut0;
  undefined4 scalarOut1;
  uint scalarIn0;
  uint scalarIn1;
  uint scalarIn2;
  
  record = (undefined4 *)_calloc(1,0x3c);
  if ((flags & 1) == 0) {
    if ((flags & 8) == 0) {
      status = __DecodePixelFormat(surfaceDesc[1],record + 0xc,record + 0xd,record + 10,&formatCode,
                                  record + 0xb,0,record + 0xe);
      if (status == 0) goto LAB_00002cb0;
      uVar1 = surfaceDesc[6];
      uVar12 = record[10];
      status = 1;
      *(undefined2 *)((int)record + 0xe) = 0;
      *(undefined2 *)(record + 3) = 0;
      record[7] = uVar1 / uVar12;
      uVar2 = surfaceDesc[4];
      *(short *)(record + 4) = (short)uVar2;
      uVar1 = surfaceDesc[5];
      record[5] = uVar2;
      *(short *)((int)record + 0x12) = (short)uVar1;
      record[6] = uVar1;
      uVar1 = uVar12 * uVar2 * uVar1 + 3;
      scalarIn1 = (uVar1 & 0xfffffffc) + 0xfff & 0xfffff000;
      for (uVar1 = uVar1 >> 2; 0x3fff < uVar1; uVar1 = uVar1 >> 1) {
        status = status << 1;
      }
      outCount = 2;
      scalarIn0 = ((uVar1 + 0xd) * status + 0x27) * 4 & 0xffffffe0;
      status = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(accel + 0xc),9,&scalarIn0,2,&scalarOut0,&outCount);
      if (status == 0) {
        *record = scalarOut1;
        uVar5 = surfaceDesc[4];
        uVar2 = surfaceDesc[5];
        uVar10 = *surfaceDesc;
        uVar9 = uVar12 * uVar5;
        uVar1 = uVar12 * uVar5 * uVar2 >> 2;
        uVar12 = uVar2;
        if (uVar1 < 0x4000) {
          status = 1;
        }
        else {
          status = 1;
          do {
            uVar1 = uVar1 >> 1;
            uVar2 = uVar2 >> 1;
            uVar12 = uVar12 >> 1;
            status = status << 1;
          } while (0x3fff < uVar1);
        }
        uVar6 = 0x20;
        if (0x1f < uVar9) {
          uVar6 = uVar9;
        }
        *scalarOut0 = (uVar1 + 0xd) * status + 8;
        scalarOut0[6] = uVar1 + 0xd;
        scalarOut0[7] = status;
        scalarOut0[5] = uVar6 * uVar2;
        scalarOut0[0x20] = 0x1393;
        scalarOut0[0x21] = 10;
        scalarOut0[0x22] = 0x5c8;
        piVar14 = scalarOut0 + 0x24;
        scalarOut0[0x23] = 0x20000;
        iVar7 = 3;
        if (formatCode != 3) {
          iVar7 = 0;
        }
        if (status != 0) {
          iVar8 = 0;
          do {
            *piVar14 = 0x5cb;
            piVar14[1] = iVar7;
            piVar14[2] = 0x51b;
            piVar14[3] = (formatCode & 0xf) << 8 | 0x53cc30f2;
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
          } while (status != iVar8);
        }
        *piVar14 = 0xd0b;
        piVar14[1] = 5;
        piVar14[2] = 0x5c8;
        piVar14[3] = 0x10000;
        status = 0;
        goto LAB_00002ce0;
      }
    }
    else if (((surfaceDesc[6] & 0x3f) == 0) &&
            (status = __DecodePixelFormat(surfaceDesc[1],record + 0xc,record + 0xd,record + 10,0,
                                         record + 0xb,0,record + 0xe), status != 0)) {
      uVar2 = surfaceDesc[6];
      *(undefined2 *)((int)record + 0xe) = 0;
      *(undefined2 *)(record + 3) = 0;
      record[7] = uVar2 / (uint)record[10];
      uVar1 = surfaceDesc[4];
      *(short *)(record + 4) = (short)uVar1;
      scalarIn2 = surfaceDesc[5];
      record[5] = uVar1;
      *(short *)((int)record + 0x12) = (short)scalarIn2;
      record[6] = scalarIn2;
      outCount = 1;
      scalarIn2 = scalarIn2 * uVar2;
      scalarIn1 = *surfaceDesc;
      scalarIn0 = flags;
      status = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(accel + 0xc),8,&scalarIn0,3,record,&outCount);
      if (status == 0) goto LAB_00002ce0;
    }
    else {
LAB_00002cb0:
      status = -0x1ffffd39;
    }
  }
  else {
    record[2] = vramAddress;
    surfaceDesc[10] = (uint)record;
    status = __SetDestination(accel,1,surfaceDesc);
    if (status == 0) {
      if ((flags & 2) != 0) {
        scalarIn1 = surfaceDesc[4];
        scalarIn2 = surfaceDesc[5];
        outCount = status;
        scalarIn0 = flags;
        status = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(accel + 0xc),4,&scalarIn0,3,0,&outCount);
        if (status != 0) goto LAB_00002cb8;
      }
      if (((flags & 0x10) != 0) &&
         (status = __DecodePixelFormat(surfaceDesc[1],record + 0xc,record + 0xd,record + 10,0,
                                      record + 0xb,&tiledFormatCode,record + 0xe), status != 0)) {
        uVar1 = surfaceDesc[4] * record[10] + 0x7f & 0xffffff80;
        scalarIn1 = (surfaceDesc[5] + 1) * uVar1;
        surfaceDesc[6] = uVar1;
        scalarIn0 = tiledFormatCode;
        outCount = 2;
        status = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(accel + 0xc),10,&scalarIn0,2,&scalarOut0,&outCount);
        if (status == 0) {
          status = 0;
          *record = scalarOut1;
          uVar1 = surfaceDesc[6];
          *(undefined2 *)((int)record + 0xe) = 0;
          *(undefined2 *)(record + 3) = 0;
          record[7] = uVar1 / (uint)record[10];
          uVar1 = surfaceDesc[4];
          *(short *)(record + 4) = (short)uVar1;
          uVar2 = surfaceDesc[5];
          record[5] = uVar1;
          *(short *)((int)record + 0x12) = (short)uVar2;
          record[6] = uVar2;
          record[1] = scalarOut0;
          surfaceDesc[9] = 2;
          goto LAB_00002ce0;
        }
      }
      status = 0;
      goto LAB_00002ce0;
    }
  }
LAB_00002cb8:
  _free(record);
  record = (undefined4 *)0x0;
LAB_00002ce0:
  surfaceDesc[10] = (uint)record;
  return status;
}

/* _radeon3DCopySetup @ 0x2d10 (2048 bytes) */
int _radeon3DCopySetup(accel, cmdBuf, dstDesc, dstFormat, useMask, cmdIndex, widthOverride, heightOverride)
  undefined4 accel;
  int cmdBuf;
  int dstDesc;
  uint dstFormat;
  int useMask;
  int cmdIndex;
  int widthOverride;
  int heightOverride;
{
  int width;
  int height;
  uint formatBias;
  uint blendControl;
  uint hwFormat;
  
  if (*(uint *)(dstDesc + 0x2c) == 0) {
    if (dstFormat == 6) {
      formatBias = 0xfffffff9;
      hwFormat = 0xc;
    }
    else if (dstFormat == 3) {
      formatBias = 0xfffffff8;
      hwFormat = 0xb;
    }
    else {
      hwFormat = dstFormat & 0x1f;
      formatBias = dstFormat - 0x13;
    }
  }
  else {
    hwFormat = *(uint *)(&DAT_0000e018 + (*(uint *)(dstDesc + 0x2c) & 0xff) * 0x1c) >> 0x13 & 0x1f;
    formatBias = hwFormat - 0x13;
  }
  *(undefined4 *)(cmdBuf + cmdIndex * 4) = 0x10ea;
  *(undefined4 *)(cmdBuf + (cmdIndex + 1) * 4) = 0x2da49525;
  *(undefined4 *)(cmdBuf + (cmdIndex + 2) * 4) = 0x10fa;
  *(undefined4 *)(cmdBuf + (cmdIndex + 3) * 4) = 0xffffff;
  *(undefined4 *)(cmdBuf + (cmdIndex + 4) * 4) = 0x1004;
  *(undefined4 *)(cmdBuf + (cmdIndex + 5) * 4) = 0x66666666;
  *(undefined4 *)(cmdBuf + (cmdIndex + 6) * 4) = 0x1005;
  *(undefined4 *)(cmdBuf + (cmdIndex + 7) * 4) = 0x6666666;
  *(undefined4 *)(cmdBuf + (cmdIndex + 8) * 4) = 0x13c1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 9) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 10) * 4) = 0x850;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xb) * 4) = 0x100;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xc) * 4) = 0x887;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xd) * 4) = 0x1c000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xe) * 4) = 0x82c;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xf) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x10) * 4) = 0x10ae;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x11) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x12) * 4) = 0x1002;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x13) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x14) * 4) = 0x824;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x15) * 4) = 1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x16) * 4) = 0x825;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x17) * 4) = 2;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x18) * 4) = 0x82d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x19) * 4) = 3;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1a) * 4) = 0x854;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1b) * 4) = 0x26010006;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1c) * 4) = 0x878;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1d) * 4) = 0xf688f688;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1e) * 4) = 0x13c0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1f) * 4) = 0;
  *(undefined4 *)((cmdIndex + 0x20) * 4 + cmdBuf) = 0x13c1;
  *(undefined4 *)((cmdIndex + 0x21) * 4 + cmdBuf) = 0;
  *(undefined4 *)((cmdIndex + 0x22) * 4 + cmdBuf) = 0x12f5;
  *(undefined4 *)((cmdIndex + 0x23) * 4 + cmdBuf) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x24) * 4) = 0x12f0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x25) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x26) * 4) = 0x10a2;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x27) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x28) * 4) = 0x1381;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x29) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2a) * 4) = 0x109e;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2b) * 4) = 5;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2c) * 4) = 0x1041;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2d) * 4) = 1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2e) * 4) = 0x1094;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2f) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x30) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x31) * 4) = 0x7803;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x32) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x33) * 4) = 0x2400000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x34) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x35) * 4) = 0xe400e400;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x36) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x37) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x38) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x39) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3a) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3b) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3c) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3d) * 4) = 0x78105;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3e) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3f) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x40) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x41) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x42) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x43) * 4) = 0xdb0220;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x44) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x45) * 4) = 0xc0c000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x46) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x47) * 4) = 0x20490000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x48) * 4) = 0x1189;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x49) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4a) * 4) = 0x1181;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4b) * 4) = 1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4c) * 4) = 0x118d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4d) * 4) = 0x10000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4e) * 4) = 0x118e;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4f) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x50) * 4) = 0x118c;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x51) * 4) = 0x10000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x52) * 4) = 0x11a9;
  if (2 < formatBias) {
    *(undefined4 *)(cmdBuf + (cmdIndex + 0x53) * 4) = 0x6c01;
  }
  else {
    *(undefined4 *)(cmdBuf + (cmdIndex + 0x53) * 4) = 0x1b01;
  }
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x54) * 4) = 0x11aa;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x55) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x56) * 4) = 0x11ab;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x57) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x58) * 4) = 0x11ac;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x59) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5a) * 4) = 0x10c0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5b) * 4) = 0x40002;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5c) * 4) = 0x10c1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5d) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5e) * 4) = 0x10c8;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5f) * 4) = 0x10;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x60) * 4) = 0x101d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x61) * 4) = 0x280c2040;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x62) * 4) = 0x1040;
  *(undefined4 *)(cmdBuf + (cmdIndex + 99) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 100) * 4) = 0x1100;
  blendControl = 0x1492;
  if (useMask == 0) {
    blendControl = 0xa92;
  }
  *(uint *)(cmdBuf + (cmdIndex + 0x65) * 4) = blendControl | 0x2000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x66) * 4) = 0x1120;
  width = widthOverride;
  if (widthOverride == 0) {
    width = (int)*(short *)(dstDesc + 4);
  }
  height = heightOverride;
  if (heightOverride == 0) {
    height = (int)*(short *)(dstDesc + 6);
  }
  *(uint *)(cmdBuf + (cmdIndex + 0x67) * 4) =
       width - 1U & 0x7ff | (height + -1) * 0x800 & 0x3ff800U | 0x80000000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x68) * 4) = 0x1130;
  if (2 < formatBias) {
    formatBias = 0;
  }
  else {
    formatBias = 0x400000;
  }
  *(uint *)(cmdBuf + (cmdIndex + 0x69) * 4) = formatBias | hwFormat | 0x53000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x6a) * 4) = 0x1140;
  if (widthOverride == 0) {
    widthOverride = (int)*(short *)(dstDesc + 4);
  }
  if (heightOverride == 0) {
    heightOverride = (int)*(short *)(dstDesc + 6);
  }
  *(uint *)(cmdBuf + (cmdIndex + 0x6b) * 4) =
       (heightOverride + -1) * 0x20 & 0x10000U |
       (widthOverride + -1) * 0x10 & 0x8000U | *(int *)(dstDesc + 0x10) - 1U & 0x3fff;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x6c) * 4) = 0x10f4;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x6d) * 4) = 0xffff;
  return cmdIndex + 0x6e;
}

/* _radeon3DFillSetup @ 0x3540 (2020 bytes) */
int _radeon3DFillSetup(cmdBuf, cmdIndex, packedColor, target)
  int cmdBuf;
  int cmdIndex;
  uint packedColor;
  int target;
{
  float blue;
  float green;
  float red;
  float alpha;
  
  *(undefined4 *)(cmdBuf + cmdIndex * 4) = 0x850;
  *(undefined4 *)(cmdBuf + (cmdIndex + 1) * 4) = 0x100;
  *(undefined4 *)(cmdBuf + (cmdIndex + 2) * 4) = 0x887;
  *(undefined4 *)(cmdBuf + (cmdIndex + 3) * 4) = 0x1c000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 4) * 4) = 0x82c;
  *(undefined4 *)(cmdBuf + (cmdIndex + 5) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 6) * 4) = 0x1002;
  *(undefined4 *)(cmdBuf + (cmdIndex + 7) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 8) * 4) = 0x824;
  *(undefined4 *)(cmdBuf + (cmdIndex + 9) * 4) = 1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 10) * 4) = 0x825;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xb) * 4) = 4;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xc) * 4) = 0x82d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xd) * 4) = 3;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xe) * 4) = 0x854;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0xf) * 4) = 0x26000001;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x10) * 4) = 0x878;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x11) * 4) = 0xfb24fb08;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x12) * 4) = 0x10a2;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x13) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x14) * 4) = 0x1381;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x15) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x16) * 4) = 0x109e;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x17) * 4) = 5;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x18) * 4) = 0x1383;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x19) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1a) * 4) = 0x1004;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1b) * 4) = 0x66666666;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1c) * 4) = 0x1005;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1d) * 4) = 0x66666666;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1e) * 4) = 0x10ae;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x1f) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x20) * 4) = 0x10ea;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x21) * 4) = 0x2da49525;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x22) * 4) = 0x10fa;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x23) * 4) = 0xffffff;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x24) * 4) = 0x10f4;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x25) * 4) = 0xffff;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x26) * 4) = 0x10f8;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x27) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x28) * 4) = 0x10f9;
  *(uint *)(cmdBuf + (cmdIndex + 0x29) * 4) =
       *(uint *)(target + 0x54) & 0x1fff | (*(uint *)(target + 0x58) & 0x1fff) << 0xd;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2a) * 4) = 0x13c0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2b) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2c) * 4) = 0x13c1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2d) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2e) * 4) = 0x10c0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x2f) * 4) = 4;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x30) * 4) = 0x10c1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x31) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x32) * 4) = 0x10c8;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x33) * 4) = 0x10;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x34) * 4) = 0x101d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x35) * 4) = 0xc2040;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x36) * 4) = 0x1041;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x37) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x38) * 4) = 0x1040;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x39) * 4) = 0;
  if (*(int *)(target + 0x70) == 3) {
    blue = (float)((double)CONCAT44(0x43300000,packedColor & 0x1f) - DOUBLE_0000cfd8) / FLOAT_0000cff8;
    red = (float)((double)CONCAT44(0x43300000,packedColor >> 10 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    green = (float)((double)CONCAT44(0x43300000,packedColor >> 5 & 0x1f) - DOUBLE_0000cfd8) /
            FLOAT_0000cff8;
    alpha = (float)((double)CONCAT44(0x43300000,packedColor >> 0xf & 1) - DOUBLE_0000cfd8);
  }
  else {
    blue = (float)((double)CONCAT44(0x43300000,packedColor & 0xff) - DOUBLE_0000cfd8) / FLOAT_0000cffc;
    alpha = (float)((double)CONCAT44(0x43300000,packedColor >> 0x18) - DOUBLE_0000cfd8) / FLOAT_0000cffc
    ;
    red = (float)((double)CONCAT44(0x43300000,packedColor >> 0x10 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
    green = (float)((double)CONCAT44(0x43300000,packedColor >> 8 & 0xff) - DOUBLE_0000cfd8) /
            FLOAT_0000cffc;
  }
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3a) * 4) = 0x1094;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3b) * 4) = 0x10000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3c) * 4) = 0x1095;
  *(float *)(cmdBuf + (cmdIndex + 0x3d) * 4) = red;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x3e) * 4) = 0x1095;
  *(float *)(cmdBuf + (cmdIndex + 0x3f) * 4) = green;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x40) * 4) = 0x1095;
  *(float *)(cmdBuf + (cmdIndex + 0x41) * 4) = blue;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x42) * 4) = 0x1095;
  *(float *)(cmdBuf + (cmdIndex + 0x43) * 4) = alpha;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x44) * 4) = 0x1094;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x45) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x46) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x47) * 4) = 0x78105;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x48) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x49) * 4) = 0x100;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4a) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4b) * 4) = 0x100;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4c) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4d) * 4) = 0xdb0220;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4e) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x4f) * 4) = 0xc0c000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x50) * 4) = 0x1095;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x51) * 4) = 0x20490000;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x52) * 4) = 0x1189;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x53) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x54) * 4) = 0x1181;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x55) * 4) = 1;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x56) * 4) = 0x118d;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x57) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x58) * 4) = 0x118e;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x59) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5a) * 4) = 0x118c;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5b) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5c) * 4) = 0x11a9;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5d) * 4) = 0x1b01;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5e) * 4) = 0x11aa;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x5f) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x60) * 4) = 0x11ab;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x61) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x62) * 4) = 0x11ac;
  *(undefined4 *)(cmdBuf + (cmdIndex + 99) * 4) = 0xf;
  *(undefined4 *)(cmdBuf + (cmdIndex + 100) * 4) = 0x12f0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x65) * 4) = 0;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x66) * 4) = 0x12f5;
  *(undefined4 *)(cmdBuf + (cmdIndex + 0x67) * 4) = 0;
  return cmdIndex + 0x68;
}

/* __Flush @ 0x3d30 (344 bytes) */
int __Flush(accel, flushFlags)
  int accel;
  uint flushFlags;
{
  undefined *taskPtr;
  int destOrNewBase;
  uint *lastHeader;
  undefined4 *cmdWrite;
  int padWords;
  int mapAddr [6];
  
  cmdWrite = *(undefined4 **)(accel + 0x80);
  if (cmdWrite != (undefined4 *)(*(int *)(accel + 0x18) + 0x20)) {
    if ((flushFlags & 0x10000) == 0) {
      destOrNewBase = *(int *)(accel + 0x8c);
    }
    else {
      destOrNewBase = 0;
      if (*(int *)(accel + 0x8c) != 0) {
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(accel + 0x7c) = cmdWrite;
        *cmdWrite = 0x2000000;
        cmdWrite = cmdWrite + 1;
        destOrNewBase = *(int *)(accel + 0x8c);
      }
    }
    mapAddr[0] = *(int *)(accel + 0x18);
    padWords = 0;
    if (destOrNewBase == 0) {
      *cmdWrite = 0x5c8;
      padWords = 2;
      cmdWrite[1] = 0xc000;
      *(undefined4 *)(accel + 0x94) = 0;
    }
    cmdWrite[padWords] = 0x1000000;
    taskPtr = PTR_0000e694;
    lastHeader = *(uint **)(accel + 0x7c);
    *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + padWords | *lastHeader;
    destOrNewBase = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,mapAddr,
                                &padWords,1);
    if (destOrNewBase == 0) {
      *(undefined4 *)(mapAddr[0] + 0x1c) = 0;
      *(int *)(accel + 0x18) = mapAddr[0];
      destOrNewBase = mapAddr[0] + 0x20;
      *(int *)(accel + 0x7c) = mapAddr[0] + 0x1c;
    }
    else {
      destOrNewBase = 0;
      *(undefined4 *)(accel + 0x7c) = 0;
      *(undefined4 *)(accel + 0x18) = 0;
    }
    *(int *)(accel + 0x80) = destOrNewBase;
  }
  return 0;
}

/* __WaitComplete @ 0x3ea0 (140 bytes) */
int __WaitComplete(accel, waitArg)
  int accel;
  undefined4 waitArg;
{
  unsigned int ghidra_home[8] = { accel, waitArg, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = waitArg;
  if (((*(int *)(accel + 0x80) != 0) && (*(int *)(accel + 0x8c) != 0)) &&
     (*(int *)(accel + 0x94) != 0)) {
    *(undefined4 *)(accel + 0x94) = 0;
    (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = 1;
  }
  ((int (*)())__Flush)(accel,0);
  return _io_connect_method_scalarI_structureI(*(undefined4 *)(accel + 0xc),7,&(*(unsigned int *)((unsigned char *)ghidra_home + 4)),1,0,0);
}

/* __FreeSurface @ 0x3f30 (224 bytes) */
int __FreeSurface(accel, freeFlags, surfaceDesc)
  int accel;
  uint freeFlags;
  int surfaceDesc;
{
  int record;
  int *recordPtr;
  undefined4 status;
  
  record = *(int *)(surfaceDesc + 0x28);
  if (record == 0) {
    status = 0xe00002d8;
  }
  else {
    if (((freeFlags & 8) != 0) && (*(int *)(accel + 0x94) != 0)) {
      ((int (*)())__WaitComplete)(accel,0x88);
      record = *(int *)(surfaceDesc + 0x28);
    }
    status = 0;
    *(undefined4 *)(record + 8) = 0;
    if (surfaceDesc == *(int *)(accel + 0x8c)) {
      status = __SetDestination(accel,0,0);
    }
    recordPtr = *(int **)(surfaceDesc + 0x28);
    if (*recordPtr != 0) {
      status = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(accel + 0xc),0xb,*recordPtr,1,0,0);
      recordPtr = *(int **)(surfaceDesc + 0x28);
    }
    recordPtr[2] = 0;
    _free(*(undefined4 *)(surfaceDesc + 0x28));
    *(undefined4 *)(surfaceDesc + 0x28) = 0;
  }
  return status;
}

/* _createTextureBuffer @ 0x4020 (584 bytes) */
int _createTextureBuffer(accel, width, height, is16bpp)
  int accel;
  int width;
  int height;
  int is16bpp;
{
  int status;
  undefined4 result;
  uint alignedHeight;
  uint alignedWidth;
  
  if (_textureBufferBytes == 0) {
    alignedWidth = width + 0x20U & 0xffffffe0;
    alignedHeight = height + 0x20U & 0xffffffe0;
    goto LAB_00004194;
  }
  if (is16bpp == 0) {
    if (DAT_0000e724 == 0x42475241) goto LAB_000040bc;
  }
  else if (DAT_0000e724 == 0x10) {
LAB_000040bc:
    alignedWidth = width + 0x20U & 0xffffffe0;
    if ((alignedWidth == _textureBufferWidth) &&
       (alignedHeight = height + 0x20U & 0xffffffe0, alignedHeight == _textureBufferHeight)) {
      status = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(accel + 0xc),0xc,*DAT_0000e748,1,0,0);
      if (status == 0) {
        return 1;
      }
      if (_textureBufferBytes == 0) goto LAB_00004194;
    }
  }
  alignedWidth = width + 0x20U & 0xffffffe0;
  alignedHeight = height + 0x20U & 0xffffffe0;
  *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + -1;
  ((int (*)())__FreeSurface)(accel,8,&_textureBuffer);
  _free(_textureBufferBytes);
  _textureBufferBytes = 0;
LAB_00004194:
  if (is16bpp == 0) {
    DAT_0000e738 = alignedWidth << 2;
    DAT_0000e724 = 0x42475241;
    _textureBufferSize = alignedWidth * alignedHeight * 4;
  }
  else {
    DAT_0000e738 = alignedWidth << 1;
    _textureBufferSize = alignedWidth * alignedHeight * 2;
    DAT_0000e724 = 0x10;
  }
  _textureBufferHeight = alignedHeight;
  _textureBufferWidth = alignedWidth;
  DAT_0000e730 = alignedWidth;
  DAT_0000e734 = alignedHeight;
  _textureBufferBytes = _malloc(_textureBufferSize);
  result = 0;
  if (_textureBufferBytes != 0) {
    _textureBuffer = _textureBufferBytes;
    status = ((int (*)())__AllocateSurface)(accel,8,&_textureBuffer,0);
    if (status == 0) {
      result = 1;
      *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + 1;
    }
    else {
      _free(_textureBufferBytes);
      result = 0;
      _textureBufferBytes = 0;
    }
  }
  return result;
}

/* _createOffscreenBuffer @ 0x4290 (588 bytes) */
int _createOffscreenBuffer(accel, rect, is16bpp)
  int accel;
  int rect;
  int is16bpp;
{
  int status;
  undefined4 result;
  
  if (_offscreenBufferBytes == 0) goto LAB_000043f0;
  if (is16bpp == 0) {
    if (DAT_0000e6c0 == 0x42475241) goto LAB_0000430c;
  }
  else if (DAT_0000e6c0 == 0x10) {
LAB_0000430c:
    if ((((int)*(short *)(rect + 4) + 0x20U & 0xffffffe0) == _offscreenBufferWidth) &&
       (((int)*(short *)(rect + 6) + 0x20U & 0xffffffe0) == _offscreenBufferHeight)) {
      status = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(accel + 0xc),0xc,*DAT_0000e6e4,1,0,0);
      if (status == 0) {
        return 1;
      }
      if (_offscreenBufferBytes == 0) goto LAB_000043f0;
    }
  }
  *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + -1;
  ((int (*)())__FreeSurface)(accel,0,&_offscreenBuffer);
  _free(_offscreenBufferBytes);
  _offscreenBufferBytes = 0;
LAB_000043f0:
  _offscreenBufferWidth = (int)*(short *)(rect + 4) + 0x20U & 0xffffffe0;
  _offscreenBufferHeight = (int)*(short *)(rect + 6) + 0x20U & 0xffffffe0;
  if (is16bpp == 0) {
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
  result = 0;
  if (_offscreenBufferBytes != 0) {
    _offscreenBuffer = _offscreenBufferBytes;
    status = ((int (*)())__AllocateSurface)(accel,0,&_offscreenBuffer,0);
    if (status == 0) {
      result = 1;
      *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + 1;
    }
    else {
      _free(_offscreenBufferBytes);
      result = 0;
      _offscreenBufferBytes = 0;
    }
  }
  return result;
}

/* __Stop @ 0x4500 (248 bytes) */
int __Stop(accel)
  int accel;
{
  int service;
  
  if (_offscreenBufferBytes != 0) {
    *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + -1;
    ((int (*)())__FreeSurface)(accel,0,&_offscreenBuffer);
    _free(_offscreenBufferBytes);
    _offscreenBufferBytes = 0;
  }
  if (_textureBufferBytes != 0) {
    *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + -1;
    ((int (*)())__FreeSurface)(accel,8,&_textureBuffer);
    _free(_textureBufferBytes);
    _textureBufferBytes = 0;
  }
  ((int (*)())__Flush)(accel,0);
  service = *(int *)(accel + 0x10);
  if (service != 0) {
    if (*(int *)(accel + 0xc) != 0) {
      _IOServiceClose(*(int *)(accel + 0xc));
      service = *(int *)(accel + 0x10);
    }
    _IOObjectRelease(service);
    *(undefined4 *)(accel + 0xc) = 0;
    *(undefined4 *)(accel + 0x10) = 0;
  }
  return 0;
}

/* _radeonCopy @ 0x4600 (3944 bytes) */
int _radeonCopy(accel, unusedArg2, unusedArg3, unusedArg4, blitReq)
  int accel;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  int blitReq;
{
  short offscreenWidth;
  uint dstBottomHi;
  bool needsSetup;
  undefined *taskPtr;
  uint *lastHeader;
  int iVar6;
  int iVar7;
  dword *pdVar8;
  int iVar9;
  int idxPlus22Or10Block1;
  int iVar11;
  dword *cmdPtrPlus36Or1Block2;
  int idxPlus1Or20Block1;
  int idxPlus6Or22Block1;
  dword texWord1;
  dword *pdVar16;
  int idxPlus2Or5Block1;
  int idxPlus8Or7Block1;
  dword *pdVar19;
  int idxPlus7Or8Block1;
  dword texWord2;
  dword *pdVar22;
  dword texWord3;
  dword *pdVar24;
  int idxPlus4Or6Block1;
  int idxPlus9Block1;
  int idxPlus10Or19Block1;
  int idxPlus11Block1;
  int idxPlus12Block1;
  int idxPlus13Block1;
  int idxPlus14Block1;
  int idxPlus15Block1;
  int idxPlus16Block1;
  int idxPlus17Block1;
  int idxPlus18Block1;
  uint dstRight;
  int idxPlus19Block3;
  uint dstX;
  int rectCount;
  uint cmdWordsLeft;
  uint cmdCapacity;
  dword *cmdWrite;
  int idxPlus3Block3;
  double srcLeftExact;
  double srcBottomExactOrInvHeight;
  double srcTopExact;
  double srcRightExactOrInvWidth;
  double srcLeftFloat;
  double srcTopFloat;
  double srcRightFloat;
  double srcBottomFloat;
  uint scratchWord0;
  uint scratchWord1;
  uint scratchWord2;
  uint scratchWord3;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  longlong d2iScratch1;
  longlong d2iScratch2;
  longlong d2iScratch3;
  longlong d2iScratch4;
  longlong d2iScratch5;
  longlong d2iScratch6;
  longlong d2iScratch7;
  longlong d2iScratch8;
  undefined4 i2dHi5;
  uint i2dLo5;
  undefined4 i2dHi6;
  uint i2dLo6;
  undefined4 i2dHi7;
  uint i2dLo7;
  undefined4 i2dHi8;
  uint i2dLo8;
  undefined4 i2dHi9;
  uint i2dLo9;
  undefined4 i2dHi10;
  uint i2dLo10;
  int idxPlus4Block4;
  int idxPlus3Block4;
  int idxPlus2Block4;
  int idxPlus1Block4;
  uint srcBottomInt;
  uint srcRightInt;
  uint srcTopInt;
  uint srcLeftInt;
  uint offscreenFormat;
  uint screenFormat;
  int local_d0;
  undefined4 *offscreenDesc;
  undefined4 flushWaitWord;
  uint colorBufferWord;
  dword *scratchWord2Ptr;
  dword *scratchWord3Ptr;
  short screenWidth;
  short screenHeight;
  dword *scratchWord0Ptr;
  dword *scratchWord1Ptr;
  int *rect;
  
  cmdWrite = *(dword **)(accel + 0x80);
  rectCount = *(int *)(blitReq + 0x58);
  cmdCapacity = *(int *)(*(int *)(accel + 0x18) + 0x10) - 7;
  if (cmdWrite != (dword *)0x0) {
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (*(int *)(accel + 0x18) + 0x20) >> 2);
    if ((0x1000 < *(short *)(accel + 0x50)) || (0x1000 < *(short *)(accel + 0x52))) {
      return 0xe00002c7;
    }
    iVar6 = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,0);
    if (iVar6 != 0) {
      screenFormat = *(uint *)(accel + 0x70);
      offscreenDesc = DAT_0000e6e4 + 3;
      if (screenFormat == 3) {
        screenFormat = 0xb;
      }
      else if (screenFormat == 6) {
        screenFormat = 0xc;
      }
      offscreenFormat = DAT_0000e6e4[0xc];
      if (offscreenFormat == 3) {
        offscreenFormat = 0xb;
      }
      else if (offscreenFormat == 6) {
        offscreenFormat = 0xc;
      }
      if (rectCount != 0) {
        scratchWord2Ptr = &scratchWord2;
        scratchWord3Ptr = &scratchWord3;
        scratchWord0Ptr = &scratchWord0;
        local_d0 = 0;
        scratchWord1Ptr = &scratchWord1;
        flushWaitWord = 0xc000;
        colorBufferWord = screenFormat & 0x1f | 0x53000;
        needsSetup = true;
        rect = (int *)(blitReq + 0x5c);
        do {
          i2dHi1 = 0x43300000;
          i2dLo1 = *rect + *(int *)(accel + 0x60) ^ 0x80000000;
          i2dHi2 = 0x43300000;
          i2dHi3 = 0x43300000;
          i2dHi4 = 0x43300000;
          i2dLo2 = rect[1] + *(int *)(accel + 100) ^ 0x80000000;
          i2dLo3 = rect[4] ^ 0x80000000;
          i2dLo4 = rect[5] ^ 0x80000000;
          srcLeftExact = (double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0;
          srcLeftFloat = (double)(float)srcLeftExact;
          srcTopExact = (double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0;
          srcTopFloat = (double)(float)srcTopExact;
          srcBottomExactOrInvHeight = srcTopFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo4) -
                                           4503601774854144.0);
          srcBottomFloat = (double)(float)srcBottomExactOrInvHeight;
          srcRightExactOrInvWidth = srcLeftFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo3) -
                                           4503601774854144.0);
          srcRightFloat = (double)(float)srcRightExactOrInvWidth;
          if (2147483648.0 <= srcLeftFloat) {
            d2iScratch2 = (longlong)(int)(srcLeftFloat - 2147483648.0);
            srcLeftInt = (int)(srcLeftFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcLeftInt = (uint)(int)srcLeftExact;
            d2iScratch1 = (longlong)(int)srcLeftInt;
          }
          if (2147483648.0 <= srcTopFloat) {
            d2iScratch4 = (longlong)(int)(srcTopFloat - 2147483648.0);
            srcTopInt = (int)(srcTopFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcTopInt = (uint)(int)srcTopExact;
            d2iScratch3 = (longlong)(int)srcTopInt;
          }
          if (2147483648.0 <= srcRightFloat) {
            d2iScratch6 = (longlong)(int)(srcRightFloat - 2147483648.0);
            srcRightInt = (int)(srcRightFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcRightInt = (uint)(int)srcRightExactOrInvWidth;
            d2iScratch5 = (longlong)(int)srcRightInt;
          }
          if (2147483648.0 <= srcBottomFloat) {
            d2iScratch8 = (longlong)(int)(srcBottomFloat - 2147483648.0);
            srcBottomInt = (int)(srcBottomFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcBottomInt = (uint)(int)srcBottomExactOrInvHeight;
            d2iScratch7 = (longlong)(int)srcBottomInt;
          }
          if (needsSetup) {
            if (cmdWordsLeft < 0x8a) {
              scratchWord0 = *(uint *)(accel + 0x18);
              scratchWord3 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord3 = 2;
                cmdWrite[1] = flushWaitWord;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord3] = 0x1000000;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord3 | *lastHeader;
              iVar6 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                          *(undefined4 *)PTR_0000e694,scratchWord0Ptr,scratchWord3Ptr,1);
              if (iVar6 == 0) {
                needsSetup = true;
                *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord0 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord0;
                pdVar8 = (dword *)(scratchWord0 + 0x38);
                cmdPtrPlus36Or1Block2 = (dword *)(scratchWord0 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                pdVar24 = (dword *)(scratchWord0 + 0x28);
                pdVar16 = (dword *)(scratchWord0 + 0x2c);
                pdVar19 = (dword *)(scratchWord0 + 0x30);
                pdVar22 = (dword *)(scratchWord0 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
LAB_00004b14:
                needsSetup = true;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                cmdWrite = (dword *)0x0;
                cmdPtrPlus36Or1Block2 = &__mh_bundle_header.cputype;
                pdVar24 = &__mh_bundle_header.cpusubtype;
                pdVar16 = &__mh_bundle_header.filetype;
                pdVar19 = &__mh_bundle_header.ncmds;
                pdVar22 = &__mh_bundle_header.sizeofcmds;
                pdVar8 = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              cmdPtrPlus36Or1Block2 = cmdWrite + 1;
              pdVar24 = cmdWrite + 2;
              pdVar16 = cmdWrite + 3;
              pdVar19 = cmdWrite + 4;
              pdVar22 = cmdWrite + 5;
              pdVar8 = cmdWrite + 6;
              needsSetup = true;
            }
          }
          else if (cmdWordsLeft < 0x22) {
            scratchWord3 = *(uint *)(accel + 0x18);
            scratchWord0 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *cmdWrite = 0x5c8;
              scratchWord0 = 2;
              cmdWrite[1] = flushWaitWord;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            cmdWrite[scratchWord0] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
            iVar6 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694
                                        ,scratchWord3Ptr,&scratchWord0,1);
            if (iVar6 != 0) goto LAB_00004b14;
            needsSetup = true;
            *(undefined4 *)(scratchWord3 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord3;
            cmdWrite = (dword *)(scratchWord3 + 0x20);
            pdVar8 = (dword *)(scratchWord3 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
            cmdPtrPlus36Or1Block2 = (dword *)(scratchWord3 + 0x24);
            pdVar24 = (dword *)(scratchWord3 + 0x28);
            pdVar16 = (dword *)(scratchWord3 + 0x2c);
            pdVar19 = (dword *)(scratchWord3 + 0x30);
            pdVar22 = (dword *)(scratchWord3 + 0x34);
            cmdWordsLeft = cmdCapacity;
          }
          else {
            cmdPtrPlus36Or1Block2 = cmdWrite + 1;
            pdVar24 = cmdWrite + 2;
            pdVar16 = cmdWrite + 3;
            pdVar19 = cmdWrite + 4;
            pdVar22 = cmdWrite + 5;
            pdVar8 = cmdWrite + 6;
            needsSetup = false;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWrite;
          *cmdWrite = 0xe000000;
          *cmdPtrPlus36Or1Block2 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pdVar24 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar24;
          *pdVar24 = 0x10000000;
          *pdVar16 = *(dword *)*DAT_0000e6e4;
          *pdVar19 = DAT_0000e6e4[7];
          *pdVar22 = 6;
          if (needsSetup) {
            iVar7 = ((int (*)())_radeon3DCopySetup)(accel,pdVar8,accel + 0x4c,screenFormat,0,0,0,0);
            screenWidth = *(short *)(accel + 0x50);
            idxPlus1Or20Block1 = iVar7 + 1;
            idxPlus2Or5Block1 = iVar7 + 2;
            idxPlus22Or10Block1 = iVar7 + 0x16;
            iVar6 = iVar7 << 2;
            idxPlus3Block3 = iVar7 + 3;
            idxPlus4Or6Block1 = iVar7 + 4;
            iVar11 = iVar7 + 5;
            idxPlus6Or22Block1 = iVar7 + 6;
            idxPlus7Or8Block1 = iVar7 + 7;
            idxPlus8Or7Block1 = iVar7 + 8;
            idxPlus9Block1 = iVar7 + 9;
            idxPlus10Or19Block1 = iVar7 + 10;
            idxPlus11Block1 = iVar7 + 0xb;
            idxPlus12Block1 = iVar7 + 0xc;
            idxPlus13Block1 = iVar7 + 0xd;
            idxPlus14Block1 = iVar7 + 0xe;
            idxPlus15Block1 = iVar7 + 0xf;
            idxPlus16Block1 = iVar7 + 0x10;
            idxPlus17Block1 = iVar7 + 0x11;
            idxPlus18Block1 = iVar7 + 0x12;
            idxPlus19Block3 = iVar7 + 0x13;
            iVar9 = iVar7 + 0x14;
            iVar7 = iVar7 + 0x15;
            screenHeight = *(short *)(accel + 0x52);
          }
          else {
            *pdVar8 = 0x1120;
            screenWidth = *(short *)(accel + 0x50);
            screenHeight = *(short *)(accel + 0x52);
            pdVar8[1] = (int)screenWidth - 1U & 0x7ff | (screenHeight + -1) * 0x800 & 0x3ff800U |
                        0x80000000;
            pdVar8[2] = 0x1130;
            pdVar8[3] = colorBufferWord;
            pdVar8[4] = 0x1140;
            pdVar8[5] = *(int *)(accel + 0x5c) - 1U & 0x3fff |
                        ((int)screenWidth - 1U) * 0x10 & 0x8000 | (screenHeight + -1) * 0x20 & 0x10000U;
            iVar6 = 0x18;
            idxPlus3Block3 = 9;
            idxPlus1Or20Block1 = 7;
            idxPlus4Or6Block1 = 10;
            iVar11 = 0xb;
            idxPlus2Or5Block1 = 8;
            idxPlus6Or22Block1 = 0xc;
            idxPlus7Or8Block1 = 0xd;
            idxPlus8Or7Block1 = 0xe;
            idxPlus9Block1 = 0xf;
            idxPlus10Or19Block1 = 0x10;
            idxPlus11Block1 = 0x11;
            idxPlus12Block1 = 0x12;
            idxPlus13Block1 = 0x13;
            idxPlus14Block1 = 0x14;
            idxPlus15Block1 = 0x15;
            idxPlus16Block1 = 0x16;
            idxPlus17Block1 = 0x17;
            idxPlus18Block1 = 0x18;
            idxPlus19Block3 = 0x19;
            iVar9 = 0x1a;
            iVar7 = 0x1b;
            idxPlus22Or10Block1 = 0x1c;
          }
          *(undefined4 *)((int)pdVar8 + iVar6) = 0x10f8;
          pdVar8[idxPlus1Or20Block1] = srcLeftInt & 0x1fff | (srcTopInt & 0x1fff) << 0xd;
          pdVar8[idxPlus2Or5Block1] = 0x10f9;
          pdVar8[idxPlus3Block3] = srcRightInt & 0x1fff | (srcBottomInt & 0x1fff) << 0xd;
          pdVar8[idxPlus4Or6Block1] = 0xc00c3500;
          pdVar8[iVar11] = 0x4003d;
          i2dLo5 = (int)screenWidth ^ 0x80000000;
          i2dLo6 = (int)screenHeight ^ 0x80000000;
          i2dHi5 = 0x43300000;
          i2dHi6 = 0x43300000;
          srcRightExactOrInvWidth = 1.0 / ((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0);
          srcBottomExactOrInvHeight = 1.0 / ((double)CONCAT44(0x43300000,i2dLo6) - 4503601774854144.0);
          scratchWord1 = (uint)GH_F2U((float)(srcRightFloat * srcRightExactOrInvWidth));
          scratchWord3 = (uint)GH_F2U((float)(srcBottomFloat * srcBottomExactOrInvHeight));
          scratchWord2 = (uint)GH_F2U((float)(srcLeftFloat * srcRightExactOrInvWidth));
          scratchWord0 = (uint)GH_F2U((float)(srcTopFloat * srcBottomExactOrInvHeight));
          pdVar8[idxPlus6Or22Block1] = srcLeftInt | srcBottomInt << 0x10;
          texWord2 = *scratchWord2Ptr;
          pdVar8[idxPlus7Or8Block1] = texWord2;
          texWord1 = *scratchWord3Ptr;
          pdVar8[idxPlus8Or7Block1] = texWord1;
          pdVar8[idxPlus9Block1] = srcLeftInt | srcTopInt << 0x10;
          pdVar8[idxPlus10Or19Block1] = texWord2;
          texWord2 = *scratchWord0Ptr;
          pdVar8[idxPlus11Block1] = texWord2;
          pdVar8[idxPlus12Block1] = srcRightInt | srcTopInt << 0x10;
          texWord3 = *scratchWord1Ptr;
          pdVar8[idxPlus13Block1] = texWord3;
          pdVar8[idxPlus14Block1] = texWord2;
          pdVar8[idxPlus15Block1] = srcRightInt | srcBottomInt << 0x10;
          pdVar8[idxPlus16Block1] = texWord3;
          pdVar8[idxPlus17Block1] = texWord1;
          pdVar8[idxPlus18Block1] = 0x1393;
          pdVar8[idxPlus19Block3] = 10;
          pdVar8[iVar9] = 0x5c8;
          pdVar8[iVar7] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - idxPlus22Or10Block1;
          iVar6 = rect[5];
          dstX = rect[2] + *(int *)(accel + 0x60);
          iVar7 = rect[3] + *(int *)(accel + 100);
          dstRight = dstX + rect[4];
          pdVar8 = pdVar8 + idxPlus22Or10Block1;
          if (cmdWordsLeft < 0x22) {
            scratchWord1 = *(uint *)(accel + 0x18);
            scratchWord2 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *pdVar8 = 0x5c8;
              scratchWord2 = 2;
              pdVar8[1] = flushWaitWord;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            pdVar8[scratchWord2] = 0x1000000;
            taskPtr = PTR_0000e694;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)pdVar8 - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
            iVar9 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                        scratchWord1Ptr,scratchWord2Ptr,1);
            cmdWordsLeft = cmdCapacity;
            if (iVar9 == 0) {
              needsSetup = true;
              *(undefined4 *)(scratchWord1 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord1;
              pdVar8 = (dword *)(scratchWord1 + 0x20);
              cmdWrite = (dword *)(scratchWord1 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
              cmdPtrPlus36Or1Block2 = (dword *)(scratchWord1 + 0x24);
              pdVar16 = (dword *)(scratchWord1 + 0x28);
              pdVar19 = (dword *)(scratchWord1 + 0x2c);
              pdVar24 = (dword *)(scratchWord1 + 0x30);
              pdVar22 = (dword *)(scratchWord1 + 0x34);
            }
            else {
              needsSetup = true;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              pdVar8 = (dword *)0x0;
              cmdPtrPlus36Or1Block2 = &__mh_bundle_header.cputype;
              pdVar16 = &__mh_bundle_header.cpusubtype;
              pdVar19 = &__mh_bundle_header.filetype;
              pdVar24 = &__mh_bundle_header.ncmds;
              pdVar22 = &__mh_bundle_header.sizeofcmds;
              cmdWrite = &__mh_bundle_header.flags;
            }
          }
          else {
            cmdPtrPlus36Or1Block2 = pdVar8 + 1;
            pdVar16 = pdVar8 + 2;
            pdVar19 = pdVar8 + 3;
            pdVar24 = pdVar8 + 4;
            pdVar22 = pdVar8 + 5;
            cmdWrite = pdVar8 + 6;
            needsSetup = false;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pdVar8 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar8;
          *pdVar8 = 0x12000000;
          *cmdPtrPlus36Or1Block2 = 0;
          *pdVar16 = 0;
          *pdVar19 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pdVar24 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar24;
          *pdVar24 = 0x4000000;
          *pdVar22 = *(dword *)*DAT_0000e6e4;
          if (needsSetup) {
            iVar11 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,offscreenDesc,offscreenFormat,0,0,0,0);
            idxPlus1Block4 = iVar11 + 1;
            idxPlus9Block1 = iVar11 + 9;
            idxPlus3Block4 = iVar11 + 3;
            idxPlus4Block4 = iVar11 + 4;
            idxPlus22Or10Block1 = iVar11 + 10;
            idxPlus2Block4 = iVar11 + 2;
            idxPlus6Or22Block1 = iVar11 + 0x16;
            iVar9 = iVar11 << 2;
            idxPlus2Or5Block1 = iVar11 + 5;
            idxPlus4Or6Block1 = iVar11 + 6;
            idxPlus8Or7Block1 = iVar11 + 7;
            idxPlus7Or8Block1 = iVar11 + 8;
            idxPlus11Block1 = iVar11 + 0xb;
            idxPlus12Block1 = iVar11 + 0xc;
            idxPlus13Block1 = iVar11 + 0xd;
            idxPlus14Block1 = iVar11 + 0xe;
            idxPlus15Block1 = iVar11 + 0xf;
            idxPlus16Block1 = iVar11 + 0x10;
            idxPlus17Block1 = iVar11 + 0x11;
            idxPlus18Block1 = iVar11 + 0x12;
            idxPlus10Or19Block1 = iVar11 + 0x13;
            idxPlus1Or20Block1 = iVar11 + 0x14;
            iVar11 = iVar11 + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            offscreenWidth = *(short *)(offscreenDesc + 1);
            iVar9 = *(short *)((int)offscreenDesc + 6) + -1;
            cmdWrite[1] = (int)offscreenWidth - 1U & 0x7ff | iVar9 * 0x800 & 0x3ff800U | 0x80000000;
            cmdWrite[2] = 0x1130;
            cmdWrite[3] = offscreenFormat & 0x1f | 0x53000;
            cmdWrite[4] = 0x1140;
            cmdWrite[5] = offscreenDesc[4] - 1 & 0x3fff | ((int)offscreenWidth - 1U) * 0x10 & 0x8000 |
                         iVar9 * 0x20 & 0x10000U;
            idxPlus4Block4 = 10;
            idxPlus2Block4 = 8;
            iVar9 = 0x18;
            idxPlus3Block4 = 9;
            idxPlus1Block4 = 7;
            idxPlus9Block1 = 0xf;
            idxPlus2Or5Block1 = 0xb;
            idxPlus4Or6Block1 = 0xc;
            idxPlus8Or7Block1 = 0xd;
            idxPlus22Or10Block1 = 0x10;
            idxPlus7Or8Block1 = 0xe;
            idxPlus11Block1 = 0x11;
            idxPlus12Block1 = 0x12;
            idxPlus13Block1 = 0x13;
            idxPlus14Block1 = 0x14;
            idxPlus15Block1 = 0x15;
            idxPlus16Block1 = 0x16;
            idxPlus17Block1 = 0x17;
            idxPlus18Block1 = 0x18;
            idxPlus10Or19Block1 = 0x19;
            idxPlus1Or20Block1 = 0x1a;
            iVar11 = 0x1b;
            idxPlus6Or22Block1 = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + iVar9) = 0x10f8;
          cmdWrite[idxPlus1Block4] = dstX & 0x1fff | iVar7 * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus2Block4] = 0x10f9;
          cmdWrite[idxPlus3Block4] = dstRight & 0x1fff | (iVar7 + iVar6) * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus4Block4] = 0xc00c3500;
          cmdWrite[idxPlus2Or5Block1] = 0x4003d;
          dstBottomHi = (iVar7 + iVar6) * 0x10000;
          i2dHi7 = 0x43300000;
          i2dLo7 = (int)*(short *)(offscreenDesc + 1) ^ 0x80000000;
          scratchWord0 = (uint)GH_F2U((float)(srcLeftFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                                    4503601774854144.0))));
          i2dHi8 = 0x43300000;
          i2dLo8 = (int)*(short *)(offscreenDesc + 1) ^ 0x80000000;
          scratchWord3 = (uint)GH_F2U((float)(srcRightFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) -
                                                    4503601774854144.0))));
          i2dHi9 = 0x43300000;
          i2dLo9 = (int)*(short *)((int)offscreenDesc + 6) ^ 0x80000000;
          scratchWord2 = (uint)GH_F2U((float)(srcTopFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo9) -
                                                    4503601774854144.0))));
          i2dHi10 = 0x43300000;
          i2dLo10 = (int)*(short *)((int)offscreenDesc + 6) ^ 0x80000000;
          scratchWord1 = (uint)GH_F2U((float)(srcBottomFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo10) -
                                                    4503601774854144.0))));
          cmdWrite[idxPlus4Or6Block1] = dstX | dstBottomHi;
          texWord2 = *scratchWord0Ptr;
          cmdWrite[idxPlus8Or7Block1] = texWord2;
          texWord1 = *scratchWord1Ptr;
          cmdWrite[idxPlus7Or8Block1] = texWord1;
          cmdWrite[idxPlus9Block1] = dstX | iVar7 * 0x10000;
          cmdWrite[idxPlus22Or10Block1] = texWord2;
          texWord2 = *scratchWord2Ptr;
          cmdWrite[idxPlus11Block1] = texWord2;
          cmdWrite[idxPlus12Block1] = dstRight | iVar7 * 0x10000;
          texWord3 = *scratchWord3Ptr;
          cmdWrite[idxPlus13Block1] = texWord3;
          cmdWrite[idxPlus14Block1] = texWord2;
          cmdWrite[idxPlus15Block1] = dstRight | dstBottomHi;
          cmdWrite[idxPlus16Block1] = texWord3;
          cmdWrite[idxPlus17Block1] = texWord1;
          cmdWrite[idxPlus18Block1] = 0x1393;
          cmdWrite[idxPlus10Or19Block1] = 10;
          cmdWrite[idxPlus1Or20Block1] = 0x5c8;
          cmdWrite[iVar11] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - idxPlus6Or22Block1;
          cmdWrite = cmdWrite + idxPlus6Or22Block1;
          local_d0 = local_d0 + 1;
          rect = rect + 6;
          needsSetup = false;
        } while (rectCount != local_d0);
      }
      *(dword **)(accel + 0x80) = cmdWrite;
      return 0;
    }
  }
  return 0xe00002be;
}

/* FUN_000055a4 @ 0x55a4 (11396 bytes) */
int FUN_000055a4(int accel,undefined4 unusedArg2,undefined4 unusedArg3,uint blitFlags,int blitReq,dword srcRef,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8)
{
  bool isScreenCopyOrNeedsSetup;
  double dVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  short sVar7;
  uint uVar8;
  float widthRatio;
  float heightRatio;
  float fVar11;
  float fVar12;
  float fVar13;
  bool needsSetup;
  undefined *taskPtr;
  int iVar16;
  undefined4 *puVar17;
  uint *lastHeader;
  int iVar19;
  int iVar20;
  int idxPlus5Or22Or13Or20Or19Block1;
  int idxPlus7Or5Or22Or8Or20Block1;
  dword *pdVar23;
  int idxPlus8Or7Or4Or1Block1;
  dword *pdVar25;
  int iVar26;
  dword dVar27;
  int idxPlus6Or4Or5Or2Or1Block1;
  dword *pdVar29;
  dword *pdVar30;
  dword dVar31;
  dword dVar32;
  dword *pdVar33;
  int idxPlus3Or8Or2Block1;
  int idxPlus4Or6Or1Or5Or3Block1;
  int idxPlus9Or2Or10Or16Block1;
  int idxPlus10Or11Or20Or12Block1;
  int regionCount;
  uint cmdCapacity;
  int idxPlus11Or12Or6Or22Block1;
  int idxPlus12Or13Or7Or6Or4Block1;
  int idxPlus13Or14Or8Or7Or5Block1;
  int idxPlus14Or15Or9Or11Or6Block1;
  int idxPlus15Or16Or10Or13Or7Block1;
  uint uVar45;
  int idxPlus16Or17Or11Or14Block1;
  int idxPlus17Or18Or12Or15Or13Block1;
  uint cmdWordsLeft;
  int idxPlus18Or19Or16Or14Block1;
  int idxPlus19Or10Or17Block2;
  uint uVar51;
  dword *cmdPtrPlus6Block3;
  dword *cmdWrite;
  int *regionRect;
  uint blitKindOrWordsLeft;
  int iVar56;
  int idxPlus2Or18Block4;
  int idxPlus4Or15Block5;
  double srcLeftExact;
  double srcTopExact;
  double dVar61;
  double srcLeftFloat;
  double srcTopFloat;
  double srcRightFloat;
  double srcBottomFloat;
  undefined4 local_368;
  uint scratchWord0;
  uint scratchWord1;
  uint scratchWord2;
  uint scratchWord3;
  dword local_354 [3];
  short srcWidth;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  dword dStack_304;
  undefined4 i2dHi4;
  dword dStack_2fc;
  undefined4 i2dHi5;
  uint i2dLo3;
  undefined4 i2dHi6;
  uint i2dLo4;
  undefined4 i2dHi7;
  uint i2dLo5;
  undefined4 i2dHi8;
  uint i2dLo6;
  longlong d2iScratch1;
  longlong d2iScratch2;
  longlong d2iScratch3;
  longlong d2iScratch4;
  longlong d2iScratch5;
  longlong d2iScratch6;
  longlong d2iScratch7;
  longlong d2iScratch8;
  undefined4 i2dHi9;
  uint i2dLo7;
  undefined4 i2dHi10;
  uint i2dLo8;
  undefined4 i2dHi11;
  uint i2dLo9;
  undefined4 i2dHi12;
  uint i2dLo10;
  undefined4 i2dHi13;
  uint i2dLo11;
  undefined4 i2dHi14;
  uint i2dLo12;
  undefined4 i2dHi15;
  uint i2dLo13;
  undefined4 i2dHi16;
  uint i2dLo14;
  undefined4 i2dHi17;
  uint i2dLo15;
  undefined4 i2dHi18;
  uint i2dLo16;
  undefined4 i2dHi19;
  uint i2dLo17;
  undefined4 i2dHi20;
  uint i2dLo18;
  undefined4 i2dHi21;
  int iStack_234;
  undefined4 i2dHi22;
  uint i2dLo19;
  undefined4 i2dHi23;
  uint i2dLo20;
  undefined4 i2dHi24;
  int iStack_21c;
  undefined4 i2dHi25;
  uint i2dLo21;
  undefined4 i2dHi26;
  uint i2dLo22;
  undefined4 i2dHi27;
  uint i2dLo23;
  undefined4 i2dHi28;
  uint i2dLo24;
  undefined4 i2dHi29;
  uint uStack_1f4;
  undefined4 i2dHi30;
  uint i2dLo25;
  undefined4 i2dHi31;
  uint i2dLo26;
  undefined4 i2dHi32;
  uint i2dLo27;
  undefined4 i2dHi33;
  uint i2dLo28;
  longlong d2iScratch9;
  longlong d2iScratch10;
  undefined4 i2dHi34;
  uint uStack_1bc;
  undefined4 i2dHi35;
  uint i2dLo29;
  undefined4 i2dHi36;
  uint i2dLo30;
  undefined4 i2dHi37;
  uint i2dLo31;
  undefined4 i2dHi38;
  uint i2dLo32;
  undefined4 i2dHi39;
  uint i2dLo33;
  undefined4 i2dHi40;
  uint i2dLo34;
  longlong d2iScratch11;
  longlong d2iScratch12;
  int local_178;
  int local_174;
  int local_170;
  uint local_16c;
  int *local_168;
  short *local_164;
  short *local_160;
  int idxPlus3Block6;
  int idxPlus2Block6;
  int idxPlus1Block6;
  int idxPlus16Block7;
  int idxPlus15Block7;
  int idxPlus14Block7;
  int sizeMismatch;
  dword blitCommandHeader;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  uint splitRow;
  uint splitRemainder;
  uint splitRowPlus2;
  dword tileHeightWords;
  uint srcBottomInt;
  uint srcRightInt;
  uint srcTopInt;
  uint srcLeftInt;
  dword srcMode;
  dword srcHandle;
  uint offscreenFormat;
  dword srcFormat;
  int srcOriginY;
  int srcOriginX;
  int dstOffsetY;
  int dstOffsetX;
  int local_e0;
  undefined4 *offscreenDesc;
  dword *srcDesc;
  int *regionFirstRect;
  uint local_d0;
  uint local_cc;
  dword local_c8;
  dword local_c4;
  dword local_c0;
  undefined4 local_bc;
  dword *scratchWord0Ptr;
  dword *scratchWord1Ptr;
  dword *scratchWord2Ptr;
  dword *scratchWord3Ptr;
  int *local_a8;
  
  blitKindOrWordsLeft = blitFlags & 0x7ffff000;
  cmdWrite = *(dword **)(accel + 0x80);
  iVar56 = *(int *)(accel + 0x18);
  regionRect = *(int **)(blitReq + 0x60);
  iVar16 = *(int *)(iVar56 + 0x10);
  regionCount = *regionRect;
  cmdCapacity = iVar16 - 7;
  if (cmdWrite == (dword *)0x0) {
LAB_000081e0:
    iVar16 = -0x1ffffd42;
  }
  else {
    isScreenCopyOrNeedsSetup = blitKindOrWordsLeft == 0x1000;
    if (isScreenCopyOrNeedsSetup) {
      srcHandle = *(dword *)(accel + 0x84);
      srcDesc = (dword *)(accel + 0x1c);
      srcOriginX = *(int *)(accel + 0x30);
      iVar26 = 0x9000000;
      srcOriginY = *(int *)(accel + 0x34);
LAB_000056ac:
      srcWidth = *(short *)(srcDesc + 1);
      if ((0x1000 < srcWidth) || (0x1000 < *(short *)((int)srcDesc + 6))) {
        return -0x1ffffd39;
      }
      blitCommandHeader = iVar26 + 0x1000000;
    }
    else {
      if (blitKindOrWordsLeft < 0x1001) {
        if (blitKindOrWordsLeft != 0) {
          return -0x1ffffd44;
        }
        srcDesc = (dword *)(accel + 0x4c);
        srcOriginX = 0;
        srcOriginY = 0;
        srcHandle = 0;
        iVar26 = 0xd000000;
        goto LAB_000056ac;
      }
      if (blitKindOrWordsLeft == 0x3000) {
        puVar17 = *(undefined4 **)(srcRef + 0x28);
        srcOriginX = 0;
        srcOriginY = 0;
        srcDesc = puVar17 + 3;
        blitCommandHeader = 0x8000000;
        srcHandle = *(dword *)*puVar17;
        *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + 1;
        srcWidth = *(short *)(puVar17 + 4);
      }
      else {
        if (blitKindOrWordsLeft != 0x7000) {
          return -0x1ffffd44;
        }
        local_354[1] = 0x800;
        local_368 = 0x30;
        local_354[0] = srcRef;
        srcHandle = srcRef;
        iVar26 = _io_connect_method_scalarI_structureO
                           (*(undefined4 *)(accel + 0xc),2,local_354,2,local_354 + 2,&local_368);
        if (iVar26 != 0) {
          return iVar26;
        }
        srcOriginX = 0;
        srcOriginY = 0;
        blitCommandHeader = 0xc000000;
        srcDesc = local_354 + 2;
      }
    }
    taskPtr = PTR_0000e694;
    regionFirstRect = regionRect + 3;
    if (regionCount == 0) {
      regionFirstRect = regionRect + 1;
      regionCount = 1;
    }
    dstOffsetY = *(int *)(blitReq + 0x5c) - (int)*(short *)((int)regionRect + 6);
    dStack_304 = srcDesc[2];
    dVar31 = srcDesc[4];
    dstOffsetX = *(int *)(blitReq + 0x58) - (int)*(short *)(regionRect + 1);
    dVar27 = srcDesc[7];
    srcFormat = srcDesc[9];
    dStack_2fc = srcDesc[3];
    if ((dStack_304 != (int)srcWidth) ||
       (sizeMismatch = 0, dStack_2fc != (int)*(short *)((int)srcDesc + 6))) {
      sizeMismatch = 1;
    }
    if (srcFormat == 3) {
      srcFormat = 0xb;
    }
    else if (srcFormat == 6) {
      srcFormat = 0xc;
    }
    i2dLo1 = (int)srcWidth ^ 0x80000000;
    i2dHi1 = 0x43300000;
    i2dHi4 = 0x43300000;
    i2dHi2 = 0x43300000;
    i2dHi3 = 0x43300000;
    i2dLo2 = (int)*(short *)((int)srcDesc + 6) ^ 0x80000000;
    widthRatio = (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0) /
            (float)((double)CONCAT44(0x43300000,dStack_304) - 4503599627370496.0);
    heightRatio = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,dStack_2fc) - 4503599627370496.0);
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (iVar56 + 0x20) >> 2);
    while (((uint)cmdWrite & 0x1f) != 0) {
      if (cmdWordsLeft == 0) {
        scratchWord0 = *(uint *)(accel + 0x18);
        scratchWord1 = 0;
        if (*(int *)(accel + 0x8c) == 0) {
          *cmdWrite = 0x5c8;
          scratchWord1 = 2;
          cmdWrite[1] = 0xc000;
          *(undefined4 *)(accel + 0x94) = 0;
        }
        cmdWrite[scratchWord1] = 0x1000000;
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
        iVar56 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                     &scratchWord0,&scratchWord1,1);
        if (iVar56 == 0) {
          *(undefined4 *)(scratchWord0 + 0x1c) = 0;
          *(uint *)(accel + 0x18) = scratchWord0;
          cmdWrite = (dword *)(scratchWord0 + 0x20);
          *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
          cmdWordsLeft = cmdCapacity;
        }
        else {
          cmdWrite = (dword *)0x0;
          *(undefined4 *)(accel + 0x7c) = 0;
          *(undefined4 *)(accel + 0x18) = 0;
          cmdWordsLeft = cmdCapacity;
        }
      }
      else {
        *cmdWrite = 0x80000000;
        cmdWrite = cmdWrite + 1;
        cmdWordsLeft = cmdWordsLeft - 1;
      }
    }
    if ((sizeMismatch == 0) && (srcFormat == *(dword *)(accel + 0x70))) {
      dstOffsetX = dstOffsetX + *(int *)(accel + 0x60);
      dstOffsetY = dstOffsetY + *(int *)(accel + 100);
    }
    srcMode = 1;
    if (srcDesc[10] != 1) {
      srcMode = (uint)(srcDesc[10] == 2) << 1;
    }
    iVar56 = (int)*(short *)(srcDesc + 1);
    if (((isScreenCopyOrNeedsSetup) || (blitKindOrWordsLeft == 0)) && (*(int *)(accel + 0x8c) == 0)) {
      iVar16 = ((int (*)())_createOffscreenBuffer)(accel,srcDesc,0);
      if (iVar16 == 0) goto LAB_000081e0;
      offscreenDesc = DAT_0000e6e4 + 3;
      offscreenFormat = DAT_0000e6e4[0xc];
      if (offscreenFormat == 3) {
        offscreenFormat = 0xb;
      }
      else if (offscreenFormat == 6) {
        offscreenFormat = 0xc;
      }
      if (regionCount != 0) {
        scratchWord3Ptr = &scratchWord3;
        scratchWord0Ptr = &scratchWord0;
        scratchWord1Ptr = &scratchWord1;
        local_c8 = 0xc000;
        local_a8 = regionFirstRect;
        scratchWord2Ptr = &scratchWord2;
        local_e0 = 0;
        needsSetup = true;
        local_c4 = srcFormat & 0x1f | 0x53000;
        do {
          i2dHi5 = 0x43300000;
          i2dLo3 = srcOriginX + *(short *)local_a8 ^ 0x80000000;
          i2dHi6 = 0x43300000;
          i2dLo4 = srcOriginY + (short)*local_a8 ^ 0x80000000;
          srcLeftExact = (double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0;
          i2dHi7 = 0x43300000;
          i2dLo5 = (int)*(short *)(local_a8 + 1) ^ 0x80000000;
          srcLeftFloat = (double)(float)srcLeftExact;
          i2dHi8 = 0x43300000;
          srcTopExact = (double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0;
          i2dLo6 = (int)*(short *)((int)local_a8 + 6) ^ 0x80000000;
          srcTopFloat = (double)(float)srcTopExact;
          dVar61 = srcLeftFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo5) -
                                           4503601774854144.0);
          srcRightFloat = (double)(float)dVar61;
          dVar2 = srcTopFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo6) -
                                          4503601774854144.0);
          srcBottomFloat = (double)(float)dVar2;
          if (2147483648.0 <= srcLeftFloat) {
            d2iScratch2 = (longlong)(int)(srcLeftFloat - 2147483648.0);
            srcLeftInt = (int)(srcLeftFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcLeftInt = (uint)(int)srcLeftExact;
            d2iScratch1 = (longlong)(int)srcLeftInt;
          }
          if (2147483648.0 <= srcTopFloat) {
            d2iScratch4 = (longlong)(int)(srcTopFloat - 2147483648.0);
            srcTopInt = (int)(srcTopFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcTopInt = (uint)(int)srcTopExact;
            d2iScratch3 = (longlong)(int)srcTopInt;
          }
          if (2147483648.0 <= srcRightFloat) {
            d2iScratch6 = (longlong)(int)(srcRightFloat - 2147483648.0);
            srcRightInt = (int)(srcRightFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcRightInt = (uint)(int)dVar61;
            d2iScratch5 = (longlong)(int)srcRightInt;
          }
          if (2147483648.0 <= srcBottomFloat) {
            d2iScratch8 = (longlong)(int)(srcBottomFloat - 2147483648.0);
            srcBottomInt = (int)(srcBottomFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcBottomInt = (uint)(int)dVar2;
            d2iScratch7 = (longlong)(int)srcBottomInt;
          }
          if (needsSetup) {
            if (cmdWordsLeft < 0x8a) {
              scratchWord1 = *(uint *)(accel + 0x18);
              scratchWord0 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord0 = 2;
                cmdWrite[1] = local_c8;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord0] = 0x1000000;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
              iVar16 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,scratchWord1Ptr,scratchWord0Ptr,1);
              if (iVar16 == 0) {
                *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord1 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord1;
                pdVar29 = (dword *)(scratchWord1 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
              }
              else {
LAB_00005e40:
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                pdVar29 = &__mh_bundle_header.cputype;
              }
LAB_00005e7c:
              needsSetup = true;
              cmdWordsLeft = cmdCapacity;
            }
            else {
              pdVar29 = cmdWrite + 1;
              needsSetup = true;
            }
          }
          else {
            if (cmdWordsLeft < 0x22) {
              scratchWord0 = *(uint *)(accel + 0x18);
              scratchWord1 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord1 = 2;
                cmdWrite[1] = local_c8;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord1] = 0x1000000;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
              iVar16 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,scratchWord0Ptr,scratchWord1Ptr,1);
              if (iVar16 != 0) goto LAB_00005e40;
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              pdVar29 = (dword *)(scratchWord0 + 0x24);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              goto LAB_00005e7c;
            }
            pdVar29 = cmdWrite + 1;
            needsSetup = false;
          }
          if (isScreenCopyOrNeedsSetup) {
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = 0xa000000;
          }
          else {
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = 0xe000000;
          }
          cmdWrite = pdVar29 + 5;
          *pdVar29 = srcHandle;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)(pdVar29 + 1) - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar29 + 1;
          pdVar29[1] = 0x10000000;
          pdVar29[2] = *(dword *)*DAT_0000e6e4;
          dVar27 = DAT_0000e6e4[7];
          pdVar29[4] = 6;
          pdVar29[3] = dVar27;
          if (needsSetup) {
            iVar26 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,srcDesc,srcFormat,0,0,0,0);
            iVar56 = iVar26 + 1;
            iVar20 = iVar26 + 0x16;
            iVar16 = iVar26 << 2;
            idxPlus2Or18Block4 = iVar26 + 2;
            idxPlus3Or8Or2Block1 = iVar26 + 3;
            idxPlus4Or6Or1Or5Or3Block1 = iVar26 + 4;
            idxPlus5Or22Or13Or20Or19Block1 = iVar26 + 5;
            idxPlus6Or4Or5Or2Or1Block1 = iVar26 + 6;
            idxPlus7Or5Or22Or8Or20Block1 = iVar26 + 7;
            idxPlus8Or7Or4Or1Block1 = iVar26 + 8;
            idxPlus9Or2Or10Or16Block1 = iVar26 + 9;
            idxPlus10Or11Or20Or12Block1 = iVar26 + 10;
            idxPlus11Or12Or6Or22Block1 = iVar26 + 0xb;
            idxPlus12Or13Or7Or6Or4Block1 = iVar26 + 0xc;
            idxPlus13Or14Or8Or7Or5Block1 = iVar26 + 0xd;
            idxPlus14Or15Or9Or11Or6Block1 = iVar26 + 0xe;
            idxPlus15Or16Or10Or13Or7Block1 = iVar26 + 0xf;
            idxPlus16Or17Or11Or14Block1 = iVar26 + 0x10;
            idxPlus17Or18Or12Or15Or13Block1 = iVar26 + 0x11;
            idxPlus18Or19Or16Or14Block1 = iVar26 + 0x12;
            idxPlus19Or10Or17Block2 = iVar26 + 0x13;
            iVar19 = iVar26 + 0x14;
            iVar26 = iVar26 + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            sVar7 = *(short *)(srcDesc + 1);
            iVar16 = *(short *)((int)srcDesc + 6) + -1;
            pdVar29[6] = (int)sVar7 - 1U & 0x7ff | iVar16 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar29[7] = 0x1130;
            pdVar29[8] = local_c4;
            pdVar29[9] = 0x1140;
            pdVar29[10] = srcDesc[4] - 1 & 0x3fff | ((int)sVar7 - 1U) * 0x10 & 0x8000 |
                          iVar16 * 0x20 & 0x10000U;
            iVar16 = 0x18;
            idxPlus2Or18Block4 = 8;
            idxPlus3Or8Or2Block1 = 9;
            iVar56 = 7;
            idxPlus4Or6Or1Or5Or3Block1 = 10;
            idxPlus5Or22Or13Or20Or19Block1 = 0xb;
            idxPlus6Or4Or5Or2Or1Block1 = 0xc;
            idxPlus7Or5Or22Or8Or20Block1 = 0xd;
            idxPlus8Or7Or4Or1Block1 = 0xe;
            idxPlus9Or2Or10Or16Block1 = 0xf;
            idxPlus10Or11Or20Or12Block1 = 0x10;
            idxPlus11Or12Or6Or22Block1 = 0x11;
            idxPlus12Or13Or7Or6Or4Block1 = 0x12;
            idxPlus13Or14Or8Or7Or5Block1 = 0x13;
            idxPlus14Or15Or9Or11Or6Block1 = 0x14;
            idxPlus15Or16Or10Or13Or7Block1 = 0x15;
            idxPlus16Or17Or11Or14Block1 = 0x16;
            idxPlus17Or18Or12Or15Or13Block1 = 0x17;
            idxPlus18Or19Or16Or14Block1 = 0x18;
            idxPlus19Or10Or17Block2 = 0x19;
            iVar19 = 0x1a;
            iVar26 = 0x1b;
            iVar20 = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + iVar16) = 0x10f8;
          cmdWrite[iVar56] = srcLeftInt & 0x1fff | (srcTopInt & 0x1fff) << 0xd;
          cmdWrite[idxPlus2Or18Block4] = 0x10f9;
          cmdWrite[idxPlus3Or8Or2Block1] = srcRightInt & 0x1fff | (srcBottomInt & 0x1fff) << 0xd;
          cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = 0xc00c3500;
          cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = 0x4003d;
          i2dHi9 = 0x43300000;
          i2dLo7 = (int)*(short *)(srcDesc + 1) ^ 0x80000000;
          scratchWord3 = (uint)GH_F2U((float)(srcLeftFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                                    4503601774854144.0))));
          i2dHi10 = 0x43300000;
          i2dLo8 = (int)*(short *)(srcDesc + 1) ^ 0x80000000;
          scratchWord2 = (uint)GH_F2U((float)(srcRightFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) -
                                                    4503601774854144.0))));
          i2dHi11 = 0x43300000;
          i2dLo9 = (int)*(short *)((int)srcDesc + 6) ^ 0x80000000;
          scratchWord1 = (uint)GH_F2U((float)(srcTopFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo9) -
                                                    4503601774854144.0))));
          i2dHi12 = 0x43300000;
          i2dLo10 = (int)*(short *)((int)srcDesc + 6) ^ 0x80000000;
          scratchWord0 = (uint)GH_F2U((float)(srcBottomFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo10) -
                                                    4503601774854144.0))));
          cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = srcLeftInt | srcBottomInt << 0x10;
          dVar31 = *scratchWord3Ptr;
          cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = dVar31;
          dVar27 = *scratchWord0Ptr;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = dVar27;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = srcLeftInt | srcTopInt << 0x10;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = dVar31;
          dVar31 = *scratchWord1Ptr;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = dVar31;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = srcRightInt | srcTopInt << 0x10;
          dVar32 = *scratchWord2Ptr;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = dVar32;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = dVar31;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = srcRightInt | srcBottomInt << 0x10;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = dVar32;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = dVar27;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 0x1393;
          cmdWrite[idxPlus19Or10Or17Block2] = 10;
          cmdWrite[iVar19] = 0x5c8;
          cmdWrite[iVar26] = 0x20000;
          blitKindOrWordsLeft = (cmdWordsLeft - 6) - iVar20;
          cmdWrite = cmdWrite + iVar20;
          uVar51 = dstOffsetX + *(short *)local_a8;
          cmdWordsLeft = uVar51 + (int)*(short *)(local_a8 + 1);
          iVar56 = dstOffsetY + (short)*local_a8;
          iVar16 = iVar56 + *(short *)((int)local_a8 + 6);
          if (blitKindOrWordsLeft < 0x22) {
            scratchWord2 = *(uint *)(accel + 0x18);
            scratchWord3 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *cmdWrite = 0x5c8;
              scratchWord3 = 2;
              cmdWrite[1] = local_c8;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            taskPtr = PTR_0000e694;
            cmdWrite[scratchWord3] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord3 | *lastHeader;
            iVar26 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                         scratchWord2Ptr,scratchWord3Ptr,1);
            if (iVar26 == 0) {
              *(undefined4 *)(scratchWord2 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord2;
              cmdWrite = (dword *)(scratchWord2 + 0x20);
              pdVar29 = (dword *)(scratchWord2 + 0x24);
              *(uint *)(accel + 0x7c) = scratchWord2 + 0x1c;
            }
            else {
              cmdWrite = (dword *)0x0;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              pdVar29 = &__mh_bundle_header.cputype;
            }
            needsSetup = true;
            blitKindOrWordsLeft = cmdCapacity;
          }
          else {
            pdVar29 = cmdWrite + 1;
            needsSetup = false;
          }
          if (isScreenCopyOrNeedsSetup) {
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = 0x11000000;
          }
          else {
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = 0x12000000;
          }
          pdVar29[1] = 0;
          pdVar29[2] = 0;
          cmdWrite = pdVar29 + 5;
          *pdVar29 = srcHandle;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)(pdVar29 + 3) - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar29 + 3;
          pdVar29[3] = 0x4000000;
          pdVar29[4] = *(dword *)*DAT_0000e6e4;
          if (needsSetup) {
            iVar19 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,offscreenDesc,offscreenFormat,0,0,0,0);
            idxPlus6Or4Or5Or2Or1Block1 = iVar19 + 4;
            idxPlus9Or2Or10Or16Block1 = iVar19 + 9;
            idxPlus3Block6 = iVar19 + 3;
            idxPlus1Block6 = iVar19 + 1;
            idxPlus2Block6 = iVar19 + 2;
            idxPlus5Or22Or13Or20Or19Block1 = iVar19 + 0x16;
            iVar26 = iVar19 << 2;
            idxPlus7Or5Or22Or8Or20Block1 = iVar19 + 5;
            idxPlus4Or6Or1Or5Or3Block1 = iVar19 + 6;
            idxPlus8Or7Or4Or1Block1 = iVar19 + 7;
            idxPlus3Or8Or2Block1 = iVar19 + 8;
            idxPlus19Or10Or17Block2 = iVar19 + 10;
            idxPlus10Or11Or20Or12Block1 = iVar19 + 0xb;
            idxPlus11Or12Or6Or22Block1 = iVar19 + 0xc;
            idxPlus12Or13Or7Or6Or4Block1 = iVar19 + 0xd;
            idxPlus13Or14Or8Or7Or5Block1 = iVar19 + 0xe;
            idxPlus14Or15Or9Or11Or6Block1 = iVar19 + 0xf;
            idxPlus15Or16Or10Or13Or7Block1 = iVar19 + 0x10;
            idxPlus16Or17Or11Or14Block1 = iVar19 + 0x11;
            idxPlus17Or18Or12Or15Or13Block1 = iVar19 + 0x12;
            idxPlus18Or19Or16Or14Block1 = iVar19 + 0x13;
            iVar20 = iVar19 + 0x14;
            iVar19 = iVar19 + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            sVar7 = *(short *)(offscreenDesc + 1);
            iVar26 = *(short *)((int)offscreenDesc + 6) + -1;
            pdVar29[6] = (int)sVar7 - 1U & 0x7ff | iVar26 * 0x800 & 0x3ff800U | 0x80000000;
            pdVar29[7] = 0x1130;
            pdVar29[8] = offscreenFormat & 0x1f | 0x53000;
            pdVar29[9] = 0x1140;
            pdVar29[10] = offscreenDesc[4] - 1 & 0x3fff | ((int)sVar7 - 1U) * 0x10 & 0x8000 |
                          iVar26 * 0x20 & 0x10000U;
            idxPlus6Or4Or5Or2Or1Block1 = 10;
            idxPlus3Block6 = 9;
            iVar26 = 0x18;
            idxPlus9Or2Or10Or16Block1 = 0xf;
            idxPlus1Block6 = 7;
            idxPlus7Or5Or22Or8Or20Block1 = 0xb;
            idxPlus2Block6 = 8;
            idxPlus8Or7Or4Or1Block1 = 0xd;
            idxPlus4Or6Or1Or5Or3Block1 = 0xc;
            idxPlus3Or8Or2Block1 = 0xe;
            idxPlus19Or10Or17Block2 = 0x10;
            idxPlus10Or11Or20Or12Block1 = 0x11;
            idxPlus11Or12Or6Or22Block1 = 0x12;
            idxPlus12Or13Or7Or6Or4Block1 = 0x13;
            idxPlus13Or14Or8Or7Or5Block1 = 0x14;
            idxPlus14Or15Or9Or11Or6Block1 = 0x15;
            idxPlus15Or16Or10Or13Or7Block1 = 0x16;
            idxPlus16Or17Or11Or14Block1 = 0x17;
            idxPlus17Or18Or12Or15Or13Block1 = 0x18;
            idxPlus18Or19Or16Or14Block1 = 0x19;
            iVar20 = 0x1a;
            iVar19 = 0x1b;
            idxPlus5Or22Or13Or20Or19Block1 = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + iVar26) = 0x10f8;
          cmdWrite[idxPlus1Block6] = uVar51 & 0x1fff | iVar56 * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus2Block6] = 0x10f9;
          cmdWrite[idxPlus3Block6] = cmdWordsLeft & 0x1fff | iVar16 * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0xc00c3500;
          cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = 0x4003d;
          uVar45 = iVar16 * 0x10000;
          i2dHi13 = 0x43300000;
          i2dLo11 = (int)*(short *)(offscreenDesc + 1) ^ 0x80000000;
          scratchWord0 = (uint)GH_F2U((float)(srcLeftFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo11) -
                                                    4503601774854144.0))));
          i2dHi14 = 0x43300000;
          i2dLo12 = (int)*(short *)(offscreenDesc + 1) ^ 0x80000000;
          scratchWord1 = (uint)GH_F2U((float)(srcRightFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo12) -
                                                    4503601774854144.0))));
          i2dHi15 = 0x43300000;
          i2dLo13 = (int)*(short *)((int)offscreenDesc + 6) ^ 0x80000000;
          scratchWord3 = (uint)GH_F2U((float)(srcTopFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo13) -
                                                    4503601774854144.0))));
          i2dHi16 = 0x43300000;
          i2dLo14 = (int)*(short *)((int)offscreenDesc + 6) ^ 0x80000000;
          scratchWord2 = (uint)GH_F2U((float)(srcBottomFloat * (1.0 / ((double)CONCAT44(0x43300000,i2dLo14) -
                                                    4503601774854144.0))));
          cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = uVar51 | uVar45;
          dVar31 = *scratchWord0Ptr;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = dVar31;
          dVar27 = *scratchWord2Ptr;
          cmdWrite[idxPlus3Or8Or2Block1] = dVar27;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = uVar51 | iVar56 * 0x10000;
          cmdWrite[idxPlus19Or10Or17Block2] = dVar31;
          dVar31 = *scratchWord3Ptr;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = dVar31;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = cmdWordsLeft | iVar56 * 0x10000;
          dVar32 = *scratchWord1Ptr;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = dVar32;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = dVar31;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = cmdWordsLeft | uVar45;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = dVar32;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = dVar27;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = 0x1393;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 10;
          cmdWrite[iVar20] = 0x5c8;
          cmdWrite[iVar19] = 0x20000;
          cmdWordsLeft = (blitKindOrWordsLeft - 6) - idxPlus5Or22Or13Or20Or19Block1;
          cmdWrite = cmdWrite + idxPlus5Or22Or13Or20Or19Block1;
          local_e0 = local_e0 + 1;
          local_a8 = local_a8 + 2;
          needsSetup = false;
        } while (regionCount != local_e0);
      }
    }
    else if (iVar56 < 0x1001) {
      if (regionCount != 0) {
        tileHeightWords = dVar31 * dVar27 * 0x1000;
        scratchWord2Ptr = &scratchWord2;
        scratchWord0Ptr = &scratchWord0;
        scratchWord1Ptr = &scratchWord1;
        scratchWord3Ptr = &scratchWord3;
        local_170 = 0;
        isScreenCopyOrNeedsSetup = true;
        regionRect = regionFirstRect;
        do {
          local_160 = (short *)((int)regionRect + 2);
          local_164 = (short *)((int)regionRect + 6);
          i2dHi17 = 0x43300000;
          i2dLo15 = srcOriginX + *(short *)regionRect ^ 0x80000000;
          uVar51 = dstOffsetX + *(short *)regionRect;
          i2dHi18 = 0x43300000;
          iVar56 = dstOffsetY + (short)*regionRect;
          i2dLo16 = srcOriginY + (short)*regionRect ^ 0x80000000;
          i2dHi19 = 0x43300000;
          i2dLo17 = (int)*(short *)(regionRect + 1) ^ 0x80000000;
          blitKindOrWordsLeft = uVar51 + (int)*(short *)(regionRect + 1);
          fVar3 = (float)((double)CONCAT44(0x43300000,i2dLo15) - 4503601774854144.0);
          i2dHi20 = 0x43300000;
          i2dLo18 = (int)*(short *)((int)regionRect + 6) ^ 0x80000000;
          uVar45 = iVar56 + *(short *)((int)regionRect + 6);
          fVar4 = (float)((double)CONCAT44(0x43300000,i2dLo16) - 4503601774854144.0);
          iVar16 = (int)*(short *)((int)srcDesc + 6);
          fVar6 = fVar4 + (float)((double)CONCAT44(0x43300000,i2dLo18) - 4503601774854144.0);
          if (iVar16 < 0x1000) {
            i2dHi21 = 0x43300000;
            fVar5 = (float)((double)CONCAT44(0x43300000,iVar16) - 4503599627370496.0);
            iStack_234 = iVar16;
          }
          else {
            fVar5 = 4096.0;
            if (4096.0 <= fVar6) {
              iVar16 = 0x1000;
              uVar45 = dstOffsetY + 0x1000;
              fVar6 = fVar5;
            }
            else {
              iVar16 = 0x1000;
            }
          }
          i2dHi22 = 0x43300000;
          i2dLo19 = (int)*(short *)(srcDesc + 1) ^ 0x80000000;
          fVar5 = heightRatio * (1.0 / fVar5);
          fVar6 = fVar6 * fVar5;
          fVar4 = fVar4 * fVar5;
          fVar5 = widthRatio * (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo19) -
                                        4503601774854144.0));
          fVar11 = (fVar3 + (float)((double)CONCAT44(0x43300000,i2dLo17) - 4503601774854144.0)) *
                   fVar5;
          fVar3 = fVar3 * fVar5;
          if (isScreenCopyOrNeedsSetup) {
            if (cmdWordsLeft < 0x8a) {
              scratchWord1 = *(uint *)(accel + 0x18);
              scratchWord0 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord0 = 2;
                cmdWrite[1] = 0xc000;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord0] = 0x1000000;
              taskPtr = PTR_0000e694;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
              iVar26 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord1Ptr,scratchWord0Ptr,1);
              if (iVar26 == 0) {
                *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord1 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord1;
                cmdPtrPlus6Block3 = (dword *)(scratchWord1 + 0x38);
                pdVar29 = (dword *)(scratchWord1 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                pdVar23 = (dword *)(scratchWord1 + 0x28);
                pdVar25 = (dword *)(scratchWord1 + 0x2c);
                pdVar30 = (dword *)(scratchWord1 + 0x30);
                pdVar33 = (dword *)(scratchWord1 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
LAB_00006cc0:
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                pdVar29 = &__mh_bundle_header.cputype;
                pdVar23 = &__mh_bundle_header.cpusubtype;
                pdVar25 = &__mh_bundle_header.filetype;
                pdVar30 = &__mh_bundle_header.ncmds;
                pdVar33 = &__mh_bundle_header.sizeofcmds;
                cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              pdVar29 = cmdWrite + 1;
              pdVar23 = cmdWrite + 2;
              pdVar25 = cmdWrite + 3;
              pdVar30 = cmdWrite + 4;
              pdVar33 = cmdWrite + 5;
              cmdPtrPlus6Block3 = cmdWrite + 6;
            }
LAB_00006d28:
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = blitCommandHeader;
            *pdVar29 = srcHandle;
            *pdVar23 = srcMode;
            *pdVar25 = 0;
            *pdVar30 = 0;
            *pdVar33 = 0;
            cmdWordsLeft = cmdWordsLeft - 6;
            iVar20 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,0,iVar16);
            idxPlus14Block7 = iVar20 + 0xe;
            idxPlus15Block7 = iVar20 + 0xf;
            idxPlus7Or5Or22Or8Or20Block1 = iVar20 + 0x16;
            iVar16 = iVar20 << 2;
            idxPlus16Block7 = iVar20 + 0x10;
            iVar19 = iVar20 + 0x11;
            iVar26 = iVar20 + 0x12;
            idxPlus4Or6Or1Or5Or3Block1 = iVar20 + 1;
            idxPlus9Or2Or10Or16Block1 = iVar20 + 2;
            idxPlus3Or8Or2Block1 = iVar20 + 3;
            idxPlus8Or7Or4Or1Block1 = iVar20 + 4;
            idxPlus6Or4Or5Or2Or1Block1 = iVar20 + 5;
            idxPlus11Or12Or6Or22Block1 = iVar20 + 6;
            idxPlus12Or13Or7Or6Or4Block1 = iVar20 + 7;
            idxPlus13Or14Or8Or7Or5Block1 = iVar20 + 8;
            idxPlus14Or15Or9Or11Or6Block1 = iVar20 + 9;
            idxPlus15Or16Or10Or13Or7Block1 = iVar20 + 10;
            idxPlus16Or17Or11Or14Block1 = iVar20 + 0xb;
            idxPlus17Or18Or12Or15Or13Block1 = iVar20 + 0xc;
            idxPlus5Or22Or13Or20Or19Block1 = iVar20 + 0xd;
            idxPlus18Or19Or16Or14Block1 = iVar20 + 0x13;
            idxPlus10Or11Or20Or12Block1 = iVar20 + 0x14;
            iVar20 = iVar20 + 0x15;
            cmdWrite = cmdPtrPlus6Block3;
          }
          else {
            if (cmdWordsLeft < 0x16) {
              scratchWord0 = *(uint *)(accel + 0x18);
              scratchWord1 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord1 = 2;
                cmdWrite[1] = 0xc000;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord1] = 0x1000000;
              taskPtr = PTR_0000e694;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
              iVar26 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord0Ptr,scratchWord1Ptr,1);
              if (iVar26 != 0) goto LAB_00006cc0;
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              cmdPtrPlus6Block3 = (dword *)(scratchWord0 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              pdVar29 = (dword *)(scratchWord0 + 0x24);
              pdVar23 = (dword *)(scratchWord0 + 0x28);
              pdVar25 = (dword *)(scratchWord0 + 0x2c);
              pdVar30 = (dword *)(scratchWord0 + 0x30);
              pdVar33 = (dword *)(scratchWord0 + 0x34);
              cmdWordsLeft = cmdCapacity;
              goto LAB_00006d28;
            }
            iVar16 = 0;
            idxPlus4Or6Or1Or5Or3Block1 = 1;
            idxPlus14Block7 = 0xe;
            idxPlus15Block7 = 0xf;
            iVar19 = 0x11;
            idxPlus16Block7 = 0x10;
            idxPlus9Or2Or10Or16Block1 = 2;
            idxPlus3Or8Or2Block1 = 3;
            iVar26 = 0x12;
            idxPlus8Or7Or4Or1Block1 = 4;
            idxPlus6Or4Or5Or2Or1Block1 = 5;
            idxPlus11Or12Or6Or22Block1 = 6;
            idxPlus12Or13Or7Or6Or4Block1 = 7;
            idxPlus13Or14Or8Or7Or5Block1 = 8;
            idxPlus14Or15Or9Or11Or6Block1 = 9;
            idxPlus15Or16Or10Or13Or7Block1 = 10;
            idxPlus16Or17Or11Or14Block1 = 0xb;
            idxPlus17Or18Or12Or15Or13Block1 = 0xc;
            idxPlus5Or22Or13Or20Or19Block1 = 0xd;
            idxPlus18Or19Or16Or14Block1 = 0x13;
            idxPlus10Or11Or20Or12Block1 = 0x14;
            iVar20 = 0x15;
            idxPlus7Or5Or22Or8Or20Block1 = 0x16;
          }
          *(undefined4 *)((int)cmdWrite + iVar16) = 0x10f8;
          local_cc = uVar51 & 0x1fff;
          cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = local_cc | iVar56 * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = 0x10f9;
          local_d0 = blitKindOrWordsLeft & 0x1fff;
          cmdWrite[idxPlus3Or8Or2Block1] = local_d0 | (uVar45 & 0x1fff) << 0xd;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = 0xc00c3500;
          cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0x4003d;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = uVar51 | uVar45 << 0x10;
          dVar31 = *scratchWord2Ptr;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = dVar31;
          dVar27 = *scratchWord0Ptr;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = dVar27;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = uVar51 | iVar56 * 0x10000;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = dVar31;
          dVar31 = *scratchWord1Ptr;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = dVar31;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = blitKindOrWordsLeft | iVar56 * 0x10000;
          dVar32 = *scratchWord3Ptr;
          cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = dVar32;
          cmdWrite[idxPlus14Block7] = dVar31;
          cmdWrite[idxPlus15Block7] = blitKindOrWordsLeft | uVar45 << 0x10;
          cmdWrite[idxPlus16Block7] = dVar32;
          cmdWrite[iVar19] = dVar27;
          cmdWrite[iVar26] = 0x1393;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 10;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = 0x5c8;
          cmdWrite[iVar20] = 0x20000;
          cmdWordsLeft = cmdWordsLeft - idxPlus7Or5Or22Or8Or20Block1;
          isScreenCopyOrNeedsSetup = false;
          cmdWrite = cmdWrite + idxPlus7Or5Or22Or8Or20Block1;
          iVar16 = (int)*local_160 + (int)*local_164;
          scratchWord0 = (uint)GH_F2U((float)(fVar6));
          scratchWord1 = (uint)GH_F2U((float)(fVar4));
          scratchWord2 = (uint)GH_F2U((float)(fVar3));
          scratchWord3 = (uint)GH_F2U((float)(fVar11));
          if (0xfff < iVar16) {
            i2dHi23 = 0x43300000;
            iVar26 = dstOffsetY + 0x1000;
            iVar56 = dstOffsetY + *local_160 + (int)*local_164;
            i2dLo20 = (srcOriginY + iVar16) - 0x1000U ^ 0x80000000;
            i2dHi24 = 0x43300000;
            iVar16 = *(short *)((int)srcDesc + 6) + -0x1000;
            fVar5 = heightRatio * (1.0 / (float)((double)CONCAT44(0x43300000,iVar16) - 4503599627370496.0
                                           ));
            fVar12 = (float)((double)CONCAT44(0x43300000,i2dLo20) - 4503601774854144.0) * fVar5;
            fVar5 = fVar5 * 0.0;
            iStack_21c = iVar16;
            if (cmdWordsLeft < 0x8a) {
              scratchWord3 = *(uint *)(accel + 0x18);
              scratchWord2 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord2 = 2;
                cmdWrite[1] = 0xc000;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord2] = 0x1000000;
              taskPtr = PTR_0000e694;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
              iVar19 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord3Ptr,scratchWord2Ptr,1);
              if (iVar19 == 0) {
                *(undefined4 *)(scratchWord3 + 0x1c) = 0;
                *(uint *)(accel + 0x18) = scratchWord3;
                cmdWrite = (dword *)(scratchWord3 + 0x20);
                cmdPtrPlus6Block3 = (dword *)(scratchWord3 + 0x38);
                *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
                pdVar29 = (dword *)(scratchWord3 + 0x24);
                pdVar23 = (dword *)(scratchWord3 + 0x28);
                pdVar25 = (dword *)(scratchWord3 + 0x2c);
                pdVar30 = (dword *)(scratchWord3 + 0x30);
                pdVar33 = (dword *)(scratchWord3 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                pdVar29 = &__mh_bundle_header.cputype;
                pdVar23 = &__mh_bundle_header.cpusubtype;
                pdVar25 = &__mh_bundle_header.filetype;
                pdVar30 = &__mh_bundle_header.ncmds;
                pdVar33 = &__mh_bundle_header.sizeofcmds;
                cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              pdVar29 = cmdWrite + 1;
              pdVar23 = cmdWrite + 2;
              pdVar25 = cmdWrite + 3;
              pdVar30 = cmdWrite + 4;
              pdVar33 = cmdWrite + 5;
              cmdPtrPlus6Block3 = cmdWrite + 6;
            }
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = blitCommandHeader;
            *pdVar29 = srcHandle;
            *pdVar23 = srcMode;
            *pdVar25 = tileHeightWords;
            *pdVar30 = 0;
            *pdVar33 = 0;
            iVar16 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,0,iVar16);
            cmdPtrPlus6Block3[iVar16] = 0x10f8;
            cmdPtrPlus6Block3[iVar16 + 1] = local_cc | iVar26 * 0x2000 & 0x3ffe000U;
            cmdPtrPlus6Block3[iVar16 + 2] = 0x10f9;
            cmdPtrPlus6Block3[iVar16 + 3] = local_d0 | iVar56 * 0x2000 & 0x3ffe000U;
            cmdPtrPlus6Block3[iVar16 + 4] = 0xc00c3500;
            cmdPtrPlus6Block3[iVar16 + 5] = 0x4003d;
            uVar45 = iVar56 * 0x10000;
            cmdPtrPlus6Block3[iVar16 + 6] = uVar51 | uVar45;
            cmdPtrPlus6Block3[iVar16 + 7] = (dword)GH_F2U((float)(fVar3));
            cmdPtrPlus6Block3[iVar16 + 8] = (dword)GH_F2U((float)(fVar12));
            uVar8 = iVar26 * 0x10000;
            cmdPtrPlus6Block3[iVar16 + 9] = uVar51 | uVar8;
            cmdPtrPlus6Block3[iVar16 + 10] = (dword)GH_F2U((float)(fVar3));
            cmdPtrPlus6Block3[iVar16 + 0xb] = (dword)GH_F2U((float)(fVar5));
            cmdPtrPlus6Block3[iVar16 + 0xc] = blitKindOrWordsLeft | uVar8;
            cmdPtrPlus6Block3[iVar16 + 0xd] = (dword)GH_F2U((float)(fVar11));
            cmdPtrPlus6Block3[iVar16 + 0xe] = (dword)GH_F2U((float)(fVar5));
            cmdPtrPlus6Block3[iVar16 + 0xf] = blitKindOrWordsLeft | uVar45;
            cmdPtrPlus6Block3[iVar16 + 0x10] = (dword)GH_F2U((float)(fVar11));
            cmdPtrPlus6Block3[iVar16 + 0x11] = (dword)GH_F2U((float)(fVar12));
            cmdPtrPlus6Block3[iVar16 + 0x12] = 0x1393;
            cmdPtrPlus6Block3[iVar16 + 0x13] = 10;
            cmdPtrPlus6Block3[iVar16 + 0x14] = 0x5c8;
            cmdPtrPlus6Block3[iVar16 + 0x15] = 0x20000;
            cmdWordsLeft = (cmdWordsLeft - 6) - (iVar16 + 0x16);
            isScreenCopyOrNeedsSetup = true;
            cmdWrite = cmdPtrPlus6Block3 + iVar16 + 0x16;
            scratchWord0 = (uint)GH_F2U((float)(fVar3));
            scratchWord1 = (uint)GH_F2U((float)(fVar11));
            scratchWord2 = (uint)GH_F2U((float)(fVar5));
            scratchWord3 = (uint)GH_F2U((float)(fVar12));
          }
          regionRect = regionRect + 2;
          local_170 = local_170 + 1;
        } while (regionCount != local_170);
      }
    }
    else {
      splitRow = iVar56 >> 1 & 0xfffffe00;
      splitRemainder = iVar56 - splitRow;
      splitRowPlus2 = splitRow + 2;
      i2dHi27 = 0x43300000;
      i2dHi25 = 0x43300000;
      i2dHi26 = 0x43300000;
      i2dLo21 = (int)*(short *)((int)srcDesc + 6) ^ 0x80000000;
      i2dLo23 = splitRemainder ^ 0x80000000;
      i2dLo22 = splitRowPlus2 ^ 0x80000000;
      fVar3 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo21) - 4503601774854144.0);
      fVar4 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo23) - 4503601774854144.0);
      fVar6 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo22) - 4503601774854144.0);
      if (regionCount != 0) {
        isScreenCopyOrNeedsSetup = true;
        local_174 = 0;
        local_c0 = 0xc000;
        local_168 = regionFirstRect;
        do {
          iVar56 = (int)*(short *)local_168;
          if (srcOriginX + iVar56 < (int)splitRowPlus2) {
            i2dLo24 = srcOriginX + iVar56 ^ 0x80000000;
            i2dHi28 = 0x43300000;
            blitKindOrWordsLeft = srcOriginX + iVar56 + *(short *)(local_168 + 1);
            uStack_1f4 = splitRowPlus2;
            if ((int)blitKindOrWordsLeft < (int)splitRowPlus2) {
              uStack_1f4 = blitKindOrWordsLeft;
            }
            uStack_1f4 = uStack_1f4 ^ 0x80000000;
            i2dHi29 = 0x43300000;
            local_16c = dstOffsetX + iVar56;
            blitKindOrWordsLeft = local_16c + (int)*(short *)(local_168 + 1);
            iVar56 = (int)(short)*local_168;
            i2dHi30 = 0x43300000;
            i2dLo25 = srcOriginY + iVar56 ^ 0x80000000;
            i2dHi31 = 0x43300000;
            i2dLo26 = srcOriginY + iVar56 + *(short *)((int)local_168 + 6) ^ 0x80000000;
            if ((int)splitRowPlus2 < (int)blitKindOrWordsLeft) {
              i2dHi32 = 0x43300000;
              i2dLo27 = dstOffsetX + splitRowPlus2 ^ 0x80000000;
              blitKindOrWordsLeft = i2dLo27;
            }
            else {
              i2dLo28 = blitKindOrWordsLeft ^ 0x80000000;
              i2dHi33 = 0x43300000;
              blitKindOrWordsLeft = i2dLo28;
            }
            dVar61 = (double)CONCAT44(0x43300000,blitKindOrWordsLeft) - 4503601774854144.0;
            fVar5 = (float)dVar61;
            if (2.1474836e+09 <= fVar5) {
              iVar26 = (int)(fVar5 - 2.1474836e+09);
              d2iScratch10 = (longlong)iVar26;
              local_124 = iVar26 + 0x80000000;
            }
            else {
              local_124 = (uint)(int)dVar61;
              d2iScratch9 = (longlong)(int)local_124;
            }
            fVar5 = widthRatio * fVar6 * (float)((double)CONCAT44(0x43300000,i2dLo24) -
                                           4503601774854144.0);
            fVar11 = widthRatio * fVar6 * (float)((double)CONCAT44(0x43300000,uStack_1f4) -
                                            4503601774854144.0);
            fVar12 = heightRatio * fVar3 * (float)((double)CONCAT44(0x43300000,i2dLo25) -
                                             4503601774854144.0);
            fVar13 = heightRatio * fVar3 * (float)((double)CONCAT44(0x43300000,i2dLo26) -
                                             4503601774854144.0);
            local_128 = dstOffsetY + iVar56;
            local_12c = local_128 + (int)*(short *)((int)local_168 + 6);
            if (isScreenCopyOrNeedsSetup) {
              if (cmdWordsLeft < 0x9e) {
                scratchWord1 = *(uint *)(accel + 0x18);
                scratchWord0 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord0 = 2;
                  cmdWrite[1] = local_c0;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord0] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord1,&scratchWord0,1);
                if (iVar56 == 0) {
                  *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord1;
                  cmdWrite = (dword *)(scratchWord1 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord1 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                  pdVar29 = (dword *)(scratchWord1 + 0x24);
                  pdVar23 = (dword *)(scratchWord1 + 0x28);
                  pdVar25 = (dword *)(scratchWord1 + 0x2c);
                  pdVar30 = (dword *)(scratchWord1 + 0x30);
                  pdVar33 = (dword *)(scratchWord1 + 0x34);
                  cmdWordsLeft = cmdCapacity;
                }
                else {
                  cmdWrite = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  pdVar29 = &__mh_bundle_header.cputype;
                  pdVar23 = &__mh_bundle_header.cpusubtype;
                  pdVar25 = &__mh_bundle_header.filetype;
                  pdVar30 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                  cmdWordsLeft = cmdCapacity;
                }
              }
              else {
                pdVar29 = cmdWrite + 1;
                pdVar23 = cmdWrite + 2;
                pdVar25 = cmdWrite + 3;
                pdVar30 = cmdWrite + 4;
                pdVar33 = cmdWrite + 5;
                cmdPtrPlus6Block3 = cmdWrite + 6;
              }
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
              *(dword **)(accel + 0x7c) = cmdWrite;
              *cmdWrite = blitCommandHeader;
              *pdVar29 = srcHandle;
              *pdVar23 = srcMode;
              *pdVar25 = 0;
              *pdVar30 = 0;
              *pdVar33 = 0;
              cmdWordsLeft = cmdWordsLeft - 4;
              iVar56 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRowPlus2,0)
              ;
LAB_0000789c:
              iVar19 = iVar56 + 9;
              idxPlus11Or12Or6Or22Block1 = iVar56 + 0x16;
              iVar26 = iVar56 << 2;
              idxPlus8Or7Or4Or1Block1 = iVar56 + 1;
              idxPlus6Or4Or5Or2Or1Block1 = iVar56 + 2;
              idxPlus3Or8Or2Block1 = iVar56 + 3;
              idxPlus4Or15Block5 = iVar56 + 4;
              idxPlus4Or6Or1Or5Or3Block1 = iVar56 + 5;
              idxPlus12Or13Or7Or6Or4Block1 = iVar56 + 6;
              idxPlus13Or14Or8Or7Or5Block1 = iVar56 + 7;
              idxPlus7Or5Or22Or8Or20Block1 = iVar56 + 8;
              idxPlus9Or2Or10Or16Block1 = iVar56 + 10;
              idxPlus14Or15Or9Or11Or6Block1 = iVar56 + 0xb;
              idxPlus10Or11Or20Or12Block1 = iVar56 + 0xc;
              idxPlus15Or16Or10Or13Or7Block1 = iVar56 + 0xd;
              idxPlus16Or17Or11Or14Block1 = iVar56 + 0xe;
              idxPlus17Or18Or12Or15Or13Block1 = iVar56 + 0xf;
              idxPlus18Or19Or16Or14Block1 = iVar56 + 0x10;
              idxPlus19Or10Or17Block2 = iVar56 + 0x11;
              idxPlus2Or18Block4 = iVar56 + 0x12;
              iVar20 = iVar56 + 0x13;
              idxPlus5Or22Or13Or20Or19Block1 = iVar56 + 0x14;
              iVar56 = iVar56 + 0x15;
              cmdWrite = cmdPtrPlus6Block3;
            }
            else {
              if (cmdWordsLeft < 0x2a) {
                scratchWord0 = *(uint *)(accel + 0x18);
                scratchWord1 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord1 = 2;
                  cmdWrite[1] = local_c0;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord1] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord0,&scratchWord1,1);
                if (iVar56 == 0) {
                  *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord0;
                  pdVar29 = (dword *)(scratchWord0 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord0 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                  cmdWrite = (dword *)(scratchWord0 + 0x24);
                  pdVar23 = (dword *)(scratchWord0 + 0x28);
                  pdVar25 = (dword *)(scratchWord0 + 0x2c);
                  pdVar30 = (dword *)(scratchWord0 + 0x30);
                  pdVar33 = (dword *)(scratchWord0 + 0x34);
                }
                else {
                  pdVar29 = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWrite = &__mh_bundle_header.cputype;
                  pdVar23 = &__mh_bundle_header.cpusubtype;
                  pdVar25 = &__mh_bundle_header.filetype;
                  pdVar30 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                }
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = (int)pdVar29 - (int)lastHeader >> 2 | *lastHeader;
                *(dword **)(accel + 0x7c) = pdVar29;
                *pdVar29 = blitCommandHeader;
                *cmdWrite = srcHandle;
                *pdVar23 = srcMode;
                *pdVar25 = 0;
                *pdVar30 = 0;
                *pdVar33 = 0;
                cmdWordsLeft = iVar16 - 0xb;
                iVar56 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRowPlus2,
                                            0);
                goto LAB_0000789c;
              }
              iVar26 = 0;
              idxPlus8Or7Or4Or1Block1 = 1;
              idxPlus6Or4Or5Or2Or1Block1 = 2;
              iVar19 = 9;
              idxPlus3Or8Or2Block1 = 3;
              idxPlus4Or15Block5 = 4;
              idxPlus4Or6Or1Or5Or3Block1 = 5;
              idxPlus12Or13Or7Or6Or4Block1 = 6;
              idxPlus13Or14Or8Or7Or5Block1 = 7;
              idxPlus7Or5Or22Or8Or20Block1 = 8;
              idxPlus9Or2Or10Or16Block1 = 10;
              idxPlus14Or15Or9Or11Or6Block1 = 0xb;
              idxPlus10Or11Or20Or12Block1 = 0xc;
              idxPlus15Or16Or10Or13Or7Block1 = 0xd;
              idxPlus16Or17Or11Or14Block1 = 0xe;
              idxPlus17Or18Or12Or15Or13Block1 = 0xf;
              idxPlus18Or19Or16Or14Block1 = 0x10;
              idxPlus19Or10Or17Block2 = 0x11;
              idxPlus2Or18Block4 = 0x12;
              iVar20 = 0x13;
              idxPlus5Or22Or13Or20Or19Block1 = 0x14;
              iVar56 = 0x15;
              idxPlus11Or12Or6Or22Block1 = 0x16;
            }
            *(undefined4 *)((int)cmdWrite + iVar26) = 0x10f8;
            cmdWrite[idxPlus8Or7Or4Or1Block1] = local_16c & 0x1fff | (local_128 & 0x1fff) << 0xd;
            cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0x10f9;
            cmdWrite[idxPlus3Or8Or2Block1] = local_124 & 0x1fff | (local_12c & 0x1fff) << 0xd;
            cmdWrite[idxPlus4Or15Block5] = 0xc00c3500;
            cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = 0x4003d;
            cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = local_16c | local_12c << 0x10;
            cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = (dword)GH_F2U((float)(fVar5));
            cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = (dword)GH_F2U((float)(fVar13));
            cmdWrite[iVar19] = local_16c | local_128 << 0x10;
            cmdWrite[idxPlus9Or2Or10Or16Block1] = (dword)GH_F2U((float)(fVar5));
            cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = (dword)GH_F2U((float)(fVar12));
            cmdWrite[idxPlus10Or11Or20Or12Block1] = local_124 | local_128 << 0x10;
            cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = (dword)GH_F2U((float)(fVar11));
            cmdWrite[idxPlus16Or17Or11Or14Block1] = (dword)GH_F2U((float)(fVar12));
            cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = local_124 | local_12c << 0x10;
            cmdWrite[idxPlus18Or19Or16Or14Block1] = (dword)GH_F2U((float)(fVar11));
            cmdWrite[idxPlus19Or10Or17Block2] = (dword)GH_F2U((float)(fVar13));
            cmdWrite[idxPlus2Or18Block4] = 0x1393;
            cmdWrite[iVar20] = 10;
            cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = 0x5c8;
            cmdWrite[iVar56] = 0x20000;
            cmdWordsLeft = cmdWordsLeft - idxPlus11Or12Or6Or22Block1;
            isScreenCopyOrNeedsSetup = false;
            cmdWrite = cmdWrite + idxPlus11Or12Or6Or22Block1;
            scratchWord0 = (uint)GH_F2U((float)(fVar13));
            scratchWord1 = (uint)GH_F2U((float)(fVar12));
            scratchWord2 = (uint)GH_F2U((float)(fVar11));
            scratchWord3 = (uint)GH_F2U((float)(fVar5));
          }
          local_174 = local_174 + 1;
          local_168 = local_168 + 2;
        } while (regionCount != local_174);
        isScreenCopyOrNeedsSetup = true;
        local_178 = 0;
        local_bc = 0xc000;
        regionRect = regionFirstRect;
        do {
          iVar26 = (int)*(short *)regionRect;
          iVar56 = iVar26 + *(short *)(regionRect + 1) + srcOriginX;
          if ((int)splitRow < iVar56) {
            uStack_1bc = splitRow;
            if ((int)splitRow < iVar26 + srcOriginX) {
              uStack_1bc = iVar26 + srcOriginX;
            }
            uStack_1bc = uStack_1bc ^ 0x80000000;
            i2dLo29 = splitRow ^ 0x80000000;
            i2dLo30 = iVar56 - splitRow ^ 0x80000000;
            local_134 = dstOffsetX + iVar26;
            i2dHi34 = 0x43300000;
            i2dHi35 = 0x43300000;
            i2dHi36 = 0x43300000;
            iVar56 = (int)(short)*regionRect;
            i2dHi37 = 0x43300000;
            i2dLo31 = iVar56 + srcOriginY ^ 0x80000000;
            i2dHi38 = 0x43300000;
            i2dLo32 = iVar56 + *(short *)((int)regionRect + 6) + srcOriginX ^ 0x80000000;
            if ((int)splitRow < (int)local_134) {
              i2dLo33 = local_134 ^ 0x80000000;
              i2dHi39 = 0x43300000;
              blitKindOrWordsLeft = i2dLo33;
            }
            else {
              i2dHi40 = 0x43300000;
              i2dLo34 = dstOffsetX + splitRow ^ 0x80000000;
              blitKindOrWordsLeft = i2dLo34;
            }
            dVar61 = (double)CONCAT44(0x43300000,blitKindOrWordsLeft) - 4503601774854144.0;
            fVar6 = (float)dVar61;
            if (2.1474836e+09 <= fVar6) {
              iVar26 = (int)(fVar6 - 2.1474836e+09);
              d2iScratch12 = (longlong)iVar26;
              local_130 = iVar26 + 0x80000000;
            }
            else {
              local_130 = (uint)(int)dVar61;
              d2iScratch11 = (longlong)(int)local_130;
            }
            local_134 = local_134 + (int)*(short *)(regionRect + 1);
            fVar6 = widthRatio * fVar4 * ((float)((double)CONCAT44(0x43300000,uStack_1bc) -
                                            4503601774854144.0) -
                                    (float)((double)CONCAT44(0x43300000,i2dLo29) -
                                           4503601774854144.0));
            fVar5 = widthRatio * fVar4 * (float)((double)CONCAT44(0x43300000,i2dLo30) -
                                           4503601774854144.0);
            fVar11 = heightRatio * fVar3 * (float)((double)CONCAT44(0x43300000,i2dLo31) -
                                             4503601774854144.0);
            fVar12 = heightRatio * fVar3 * (float)((double)CONCAT44(0x43300000,i2dLo32) -
                                             4503601774854144.0);
            local_138 = dstOffsetY + iVar56;
            local_13c = local_138 + (int)*(short *)((int)regionRect + 6);
            if (isScreenCopyOrNeedsSetup) {
              if (cmdWordsLeft < 0x9e) {
                scratchWord2 = *(uint *)(accel + 0x18);
                scratchWord3 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord3 = 2;
                  cmdWrite[1] = local_bc;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord3] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord3 | *lastHeader;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord2,&scratchWord3,1);
                if (iVar56 == 0) {
                  *(undefined4 *)(scratchWord2 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord2;
                  cmdWrite = (dword *)(scratchWord2 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord2 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord2 + 0x1c;
                  pdVar29 = (dword *)(scratchWord2 + 0x24);
                  pdVar23 = (dword *)(scratchWord2 + 0x28);
                  pdVar25 = (dword *)(scratchWord2 + 0x2c);
                  pdVar30 = (dword *)(scratchWord2 + 0x30);
                  pdVar33 = (dword *)(scratchWord2 + 0x34);
                  cmdWordsLeft = cmdCapacity;
                }
                else {
                  cmdWrite = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  pdVar29 = &__mh_bundle_header.cputype;
                  pdVar23 = &__mh_bundle_header.cpusubtype;
                  pdVar25 = &__mh_bundle_header.filetype;
                  pdVar30 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                  cmdWordsLeft = cmdCapacity;
                }
              }
              else {
                pdVar29 = cmdWrite + 1;
                pdVar23 = cmdWrite + 2;
                pdVar25 = cmdWrite + 3;
                pdVar30 = cmdWrite + 4;
                pdVar33 = cmdWrite + 5;
                cmdPtrPlus6Block3 = cmdWrite + 6;
              }
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
              *(dword **)(accel + 0x7c) = cmdWrite;
              *cmdWrite = blitCommandHeader;
              *pdVar29 = srcHandle;
              *pdVar23 = srcMode;
              *pdVar25 = 0;
              *pdVar30 = srcDesc[0xb];
              *pdVar33 = splitRow;
              cmdWordsLeft = cmdWordsLeft - 4;
              iVar56 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRemainder,0)
              ;
LAB_00007ff0:
              iVar19 = iVar56 + 9;
              iVar20 = iVar56 + 10;
              idxPlus11Or12Or6Or22Block1 = iVar56 + 0x16;
              iVar26 = iVar56 << 2;
              idxPlus6Or4Or5Or2Or1Block1 = iVar56 + 1;
              idxPlus3Or8Or2Block1 = iVar56 + 2;
              idxPlus4Or6Or1Or5Or3Block1 = iVar56 + 3;
              idxPlus12Or13Or7Or6Or4Block1 = iVar56 + 4;
              idxPlus13Or14Or8Or7Or5Block1 = iVar56 + 5;
              idxPlus14Or15Or9Or11Or6Block1 = iVar56 + 6;
              idxPlus15Or16Or10Or13Or7Block1 = iVar56 + 7;
              idxPlus8Or7Or4Or1Block1 = iVar56 + 8;
              idxPlus16Or17Or11Or14Block1 = iVar56 + 0xb;
              idxPlus10Or11Or20Or12Block1 = iVar56 + 0xc;
              idxPlus17Or18Or12Or15Or13Block1 = iVar56 + 0xd;
              idxPlus18Or19Or16Or14Block1 = iVar56 + 0xe;
              idxPlus4Or15Block5 = iVar56 + 0xf;
              idxPlus9Or2Or10Or16Block1 = iVar56 + 0x10;
              idxPlus19Or10Or17Block2 = iVar56 + 0x11;
              idxPlus2Or18Block4 = iVar56 + 0x12;
              idxPlus5Or22Or13Or20Or19Block1 = iVar56 + 0x13;
              idxPlus7Or5Or22Or8Or20Block1 = iVar56 + 0x14;
              iVar56 = iVar56 + 0x15;
              cmdWrite = cmdPtrPlus6Block3;
            }
            else {
              if (cmdWordsLeft < 0x2a) {
                scratchWord3 = *(uint *)(accel + 0x18);
                scratchWord2 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord2 = 2;
                  cmdWrite[1] = local_bc;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord2] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
                iVar56 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord3,&scratchWord2,1);
                if (iVar56 == 0) {
                  *(undefined4 *)(scratchWord3 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord3;
                  pdVar29 = (dword *)(scratchWord3 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord3 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
                  cmdWrite = (dword *)(scratchWord3 + 0x24);
                  pdVar23 = (dword *)(scratchWord3 + 0x28);
                  pdVar25 = (dword *)(scratchWord3 + 0x2c);
                  pdVar30 = (dword *)(scratchWord3 + 0x30);
                  pdVar33 = (dword *)(scratchWord3 + 0x34);
                }
                else {
                  pdVar29 = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWrite = &__mh_bundle_header.cputype;
                  pdVar23 = &__mh_bundle_header.cpusubtype;
                  pdVar25 = &__mh_bundle_header.filetype;
                  pdVar30 = &__mh_bundle_header.ncmds;
                  pdVar33 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                }
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = (int)pdVar29 - (int)lastHeader >> 2 | *lastHeader;
                *(dword **)(accel + 0x7c) = pdVar29;
                *pdVar29 = blitCommandHeader;
                *cmdWrite = srcHandle;
                *pdVar23 = srcMode;
                *pdVar25 = 0;
                *pdVar30 = srcDesc[0xb];
                *pdVar33 = splitRow;
                cmdWordsLeft = iVar16 - 0xb;
                iVar56 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRemainder,
                                            0);
                goto LAB_00007ff0;
              }
              iVar26 = 0;
              idxPlus6Or4Or5Or2Or1Block1 = 1;
              iVar19 = 9;
              idxPlus3Or8Or2Block1 = 2;
              idxPlus4Or6Or1Or5Or3Block1 = 3;
              iVar20 = 10;
              idxPlus12Or13Or7Or6Or4Block1 = 4;
              idxPlus13Or14Or8Or7Or5Block1 = 5;
              idxPlus14Or15Or9Or11Or6Block1 = 6;
              idxPlus15Or16Or10Or13Or7Block1 = 7;
              idxPlus8Or7Or4Or1Block1 = 8;
              idxPlus16Or17Or11Or14Block1 = 0xb;
              idxPlus10Or11Or20Or12Block1 = 0xc;
              idxPlus17Or18Or12Or15Or13Block1 = 0xd;
              idxPlus18Or19Or16Or14Block1 = 0xe;
              idxPlus4Or15Block5 = 0xf;
              idxPlus9Or2Or10Or16Block1 = 0x10;
              idxPlus19Or10Or17Block2 = 0x11;
              idxPlus2Or18Block4 = 0x12;
              idxPlus5Or22Or13Or20Or19Block1 = 0x13;
              idxPlus7Or5Or22Or8Or20Block1 = 0x14;
              iVar56 = 0x15;
              idxPlus11Or12Or6Or22Block1 = 0x16;
            }
            *(undefined4 *)((int)cmdWrite + iVar26) = 0x10f8;
            cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = local_130 & 0x1fff | (local_138 & 0x1fff) << 0xd;
            cmdWrite[idxPlus3Or8Or2Block1] = 0x10f9;
            cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = local_134 & 0x1fff | (local_13c & 0x1fff) << 0xd;
            cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = 0xc00c3500;
            cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = 0x4003d;
            cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = local_130 | local_13c << 0x10;
            cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = (dword)GH_F2U((float)(fVar6));
            cmdWrite[idxPlus8Or7Or4Or1Block1] = (dword)GH_F2U((float)(fVar12));
            cmdWrite[iVar19] = local_130 | local_138 << 0x10;
            cmdWrite[iVar20] = (dword)GH_F2U((float)(fVar6));
            cmdWrite[idxPlus16Or17Or11Or14Block1] = (dword)GH_F2U((float)(fVar11));
            cmdWrite[idxPlus10Or11Or20Or12Block1] = local_134 | local_138 << 0x10;
            cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = (dword)GH_F2U((float)(fVar5));
            cmdWrite[idxPlus18Or19Or16Or14Block1] = (dword)GH_F2U((float)(fVar11));
            cmdWrite[idxPlus4Or15Block5] = local_134 | local_13c << 0x10;
            cmdWrite[idxPlus9Or2Or10Or16Block1] = (dword)GH_F2U((float)(fVar5));
            cmdWrite[idxPlus19Or10Or17Block2] = (dword)GH_F2U((float)(fVar12));
            cmdWrite[idxPlus2Or18Block4] = 0x1393;
            cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = 10;
            cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = 0x5c8;
            cmdWrite[iVar56] = 0x20000;
            cmdWordsLeft = cmdWordsLeft - idxPlus11Or12Or6Or22Block1;
            isScreenCopyOrNeedsSetup = false;
            cmdWrite = cmdWrite + idxPlus11Or12Or6Or22Block1;
            scratchWord0 = (uint)GH_F2U((float)(fVar11));
            scratchWord1 = (uint)GH_F2U((float)(fVar5));
            scratchWord2 = (uint)GH_F2U((float)(fVar6));
            scratchWord3 = (uint)GH_F2U((float)(fVar12));
          }
          regionRect = regionRect + 2;
          local_178 = local_178 + 1;
        } while (regionCount != local_178);
      }
    }
    iVar16 = 0;
    *(dword **)(accel + 0x80) = cmdWrite;
  }
  return iVar16;
}

/* _radeonFill @ 0x8260 (9000 bytes) */
int _radeonFill(accel, unusedArg2, fillFlags, blitFlags, fillReq, patternBuf)
  int accel;
  undefined4 unusedArg2;
  uint fillFlags;
  uint blitFlags;
  undefined4 *fillReq;
  undefined4 patternBuf;
{
  float fVar1;
  float fVar2;
  float fVar3;
  bool firstTile;
  bool noMaskFlags;
  double dVar6;
  undefined *taskPtr;
  undefined4 *puVar8;
  float fVar9;
  int iVar10;
  dword dVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  dword *pdVar15;
  dword *pdVar16;
  uint uVar17;
  dword dVar18;
  dword *pdVar19;
  int *piVar20;
  dword *pdVar21;
  float fVar22;
  int iVar23;
  uint *lastHeader;
  int iVar25;
  dword *pdVar26;
  float fVar27;
  float fVar28;
  uint cmdCapacity;
  dword *pdVar30;
  int iVar31;
  uint cmdWordsLeft;
  uint uVar33;
  int iVar34;
  uint uVar35;
  int iVar36;
  uint uVar37;
  uint idxPlus8Block1;
  int iVar39;
  int iVar40;
  int iVar41;
  uint fillColor;
  int iVar43;
  dword *cmdWrite;
  int iVar45;
  int iVar46;
  int iVar47;
  undefined4 *rectEntry;
  int iVar49;
  int iVar50;
  int iVar51;
  float local_308;
  float local_304;
  float local_300;
  uint local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  uint scratchWord0;
  uint scratchWord1;
  uint scratchWord2;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  uint i2dLo3;
  undefined4 i2dHi4;
  uint i2dLo4;
  undefined4 i2dHi5;
  int iStack_2b4;
  undefined4 i2dHi6;
  int iStack_2ac;
  undefined4 i2dHi7;
  uint uStack_2a4;
  undefined4 i2dHi8;
  uint uStack_29c;
  undefined4 i2dHi9;
  uint uStack_294;
  undefined4 i2dHi10;
  uint uStack_28c;
  undefined4 i2dHi11;
  uint uStack_284;
  undefined4 i2dHi12;
  uint uStack_27c;
  undefined4 i2dHi13;
  uint uStack_274;
  undefined4 i2dHi14;
  uint uStack_26c;
  undefined4 i2dHi15;
  uint uStack_264;
  undefined4 i2dHi16;
  uint uStack_25c;
  undefined4 i2dHi17;
  uint uStack_254;
  undefined4 i2dHi18;
  uint uStack_24c;
  undefined4 i2dHi19;
  uint uStack_244;
  undefined4 i2dHi20;
  uint uStack_23c;
  undefined4 i2dHi21;
  uint i2dLo5;
  undefined4 i2dHi22;
  uint i2dLo6;
  undefined4 i2dHi23;
  uint i2dLo7;
  undefined4 i2dHi24;
  int iStack_20c;
  undefined4 i2dHi25;
  uint i2dLo8;
  undefined4 i2dHi26;
  uint i2dLo9;
  undefined4 i2dHi27;
  int iStack_1f4;
  undefined4 i2dHi28;
  uint i2dLo10;
  undefined4 i2dHi29;
  uint i2dLo11;
  undefined4 i2dHi30;
  uint i2dLo12;
  undefined4 i2dHi31;
  uint i2dLo13;
  undefined4 i2dHi32;
  uint i2dLo14;
  undefined4 i2dHi33;
  uint uStack_1c4;
  undefined4 i2dHi34;
  uint uStack_1bc;
  undefined4 i2dHi35;
  uint uStack_1b4;
  undefined4 i2dHi36;
  uint uStack_1ac;
  undefined4 i2dHi37;
  uint i2dLo15;
  undefined4 i2dHi38;
  uint i2dLo16;
  undefined4 i2dHi39;
  uint i2dLo17;
  undefined4 i2dHi40;
  uint i2dLo18;
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
  int idxPlus36Block2;
  int idxPlus34Block2;
  int idxPlus33Block2;
  int idxPlus32Block2;
  int idxPlus31Block2;
  int idxPlus30Block2;
  int idxPlus29Block2;
  int idxPlus27Block2;
  int idxPlus24Block2;
  int idxPlus23Block2;
  int local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  uint tileRight;
  uint tileBottom;
  uint tileTop;
  uint dstBottom;
  uint dstTop;
  uint dstRight;
  uint dstLeft;
  int textureDesc;
  uint local_104;
  int local_100;
  uint local_fc;
  short screenWidth;
  short screenHeight;
  int tileHeight;
  int local_f0;
  float *local_ec;
  float *local_e8;
  float *local_e4;
  dword *local_e0;
  float *local_dc;
  float *local_d8;
  float *local_d4;
  dword *local_d0;
  uint tileBottomHi;
  uint tileTopHi;
  uint maskBit;
  float *local_c0;
  uint colorBits;
  
  cmdWordsLeft = blitFlags & 0x7ffff000;
  if ((cmdWordsLeft != 0x6000) || ((fillFlags & 0xf000) != 0)) {
    cmdWrite = *(dword **)(accel + 0x80);
    iVar23 = *(int *)(accel + 0x18);
    fillColor = fillReq[5];
    cmdCapacity = *(int *)(iVar23 + 0x10) - 7;
    if ((cmdWrite != (dword *)0x0) &&
       ((iVar12 = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,(uint)(*(int *)(accel + 0x70) == 3)),
        iVar12 != 0 &&
        (iVar12 = ((int (*)())_createTextureBuffer)(accel,0x40,0x40,(uint)(*(int *)(accel + 0x70) == 3)),
        iVar12 != 0)))) {
      local_f0 = 0x8284;
      textureDesc = DAT_0000e748 + 0xc;
      if (cmdWordsLeft != 0x6000) {
        _fillTextureWithPattern(patternBuf,cmdWordsLeft,*fillReq,fillReq[1]);
      }
      else {
        _fillTextureWithPattern(patternBuf,0x6000,patternBuf,patternBuf);
      }
      cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (iVar23 + 0x20) >> 2);
      if (fillReq[0x16] != 0) {
        colorBits = fillColor & 0x7c00;
        maskBit = (fillFlags & 0xc000) >> 0xe & 1;
        local_104 = 0;
        noMaskFlags = (fillFlags & 0xc000) == 0;
        rectEntry = fillReq;
        do {
          dstTop = rectEntry[0x18] + *(int *)(accel + 100);
          dstBottom = dstTop + rectEntry[0x1a];
          dstLeft = rectEntry[0x17] + *(int *)(accel + 0x60);
          dstRight = dstLeft + rectEntry[0x19];
          tileBottom = dstBottom;
          if (dstTop + 8 < dstBottom) {
            tileBottom = dstTop + 8;
          }
          iStack_2b4 = (dstLeft & 7) + fillReq[2];
          iStack_2ac = (dstTop & 7) + fillReq[3];
          i2dHi5 = 0x43300000;
          i2dHi6 = 0x43300000;
          fVar9 = (float)((double)CONCAT44(0x43300000,iStack_2b4) - 4503599627370496.0);
          fVar1 = (float)((double)CONCAT44(0x43300000,iStack_2ac) - 4503599627370496.0);
          if (dstTop < dstBottom) {
            idxPlus8Block1 = dstLeft + 8;
            uVar33 = dstRight;
            if (idxPlus8Block1 < dstRight) {
              uVar33 = idxPlus8Block1;
            }
            i2dHi10 = 0x43300000;
            firstTile = true;
            uStack_28c = colorBits >> 10;
            dVar6 = (double)CONCAT44(0x43300000,uStack_28c);
            uVar17 = dstTop;
            do {
              tileTop = uVar17;
              if (dstLeft < dstRight) {
                if (!firstTile) {
                  local_ec = &local_308;
                  i2dHi7 = 0x43300000;
                  i2dHi8 = 0x43300000;
                  uStack_2a4 = tileTop;
                  uStack_29c = tileBottom;
                  tileBottomHi = tileBottom << 0x10;
                  local_e0 = &local_2fc;
                  local_dc = &local_2f8;
                  tileTopHi = tileTop << 0x10;
                  local_e4 = &local_300;
                  local_d4 = &local_2f0;
                  local_d0 = &scratchWord2;
                  local_d8 = &local_2f4;
                  local_e8 = &local_304;
                  tileHeight = tileBottom - tileTop;
                  fVar2 = (float)((double)CONCAT44(0x43300000,tileTop) - 4503599627370496.0);
                  fVar3 = (float)((double)CONCAT44(0x43300000,tileBottom) - 4503599627370496.0);
                  uVar17 = idxPlus8Block1;
                  uVar37 = dstLeft;
                  tileRight = uVar33;
                  goto LAB_00008bec;
                }
                uVar35 = idxPlus8Block1;
                if (cmdWordsLeft < 0xd4) {
                  scratchWord0 = *(uint *)(accel + 0x18);
                  scratchWord1 = 0;
                  if (*(int *)(accel + 0x8c) == 0) {
                    *cmdWrite = 0x5c8;
                    scratchWord1 = 2;
                    cmdWrite[1] = 0xc000;
                    *(undefined4 *)(accel + 0x94) = 0;
                  }
                  cmdWrite[scratchWord1] = 0x1000000;
                  taskPtr = PTR_0000e694;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
                  iVar23 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord0,&scratchWord1,1);
                  uStack_244 = dstLeft;
                  if (iVar23 == 0) {
                    local_e8 = &local_304;
                    local_e0 = &local_2fc;
                    local_d0 = &scratchWord2;
                    *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                    local_ec = &local_308;
                    local_e4 = &local_300;
                    local_dc = &local_2f8;
                    local_d4 = &local_2f0;
                    tileTopHi = tileTop << 0x10;
                    tileBottomHi = tileBottom << 0x10;
                    cmdWrite = (dword *)(scratchWord0 + 0x20);
                    pdVar21 = (dword *)(scratchWord0 + 0x38);
                    pdVar15 = (dword *)(scratchWord0 + 0x24);
                    local_d8 = &local_2f4;
                    pdVar16 = (dword *)(scratchWord0 + 0x2c);
                    pdVar30 = (dword *)(scratchWord0 + 0x28);
                    tileHeight = tileBottom - tileTop;
                    pdVar19 = (dword *)(scratchWord0 + 0x30);
                    pdVar26 = (dword *)(scratchWord0 + 0x34);
                    *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                    *(uint *)(accel + 0x18) = scratchWord0;
                    cmdWordsLeft = cmdCapacity;
                    tileRight = uVar33;
                  }
                  else {
                    local_d0 = &scratchWord2;
                    local_e0 = &local_2fc;
                    local_e8 = &local_304;
                    local_ec = &local_308;
                    cmdWrite = (dword *)0x0;
                    local_e4 = &local_300;
                    local_dc = &local_2f8;
                    pdVar15 = &__mh_bundle_header.cputype;
                    tileBottomHi = tileBottom << 0x10;
                    local_d4 = &local_2f0;
                    pdVar30 = &__mh_bundle_header.cpusubtype;
                    pdVar16 = &__mh_bundle_header.filetype;
                    pdVar19 = &__mh_bundle_header.ncmds;
                    pdVar26 = &__mh_bundle_header.sizeofcmds;
                    pdVar21 = &__mh_bundle_header.flags;
                    tileTopHi = tileTop << 0x10;
                    local_d8 = &local_2f4;
                    tileHeight = tileBottom - tileTop;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdWordsLeft = cmdCapacity;
                    tileRight = uVar33;
                  }
                }
                else {
                  local_d0 = &scratchWord2;
                  local_e0 = &local_2fc;
                  local_e8 = &local_304;
                  local_ec = &local_308;
                  pdVar15 = cmdWrite + 1;
                  pdVar30 = cmdWrite + 2;
                  local_e4 = &local_300;
                  pdVar16 = cmdWrite + 3;
                  local_dc = &local_2f8;
                  pdVar19 = cmdWrite + 4;
                  tileBottomHi = tileBottom << 0x10;
                  local_d4 = &local_2f0;
                  pdVar26 = cmdWrite + 5;
                  pdVar21 = cmdWrite + 6;
                  tileTopHi = tileTop << 0x10;
                  local_d8 = &local_2f4;
                  tileHeight = tileBottom - tileTop;
                  uStack_244 = dstLeft;
                  tileRight = uVar33;
                }
                do {
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = cmdWrite;
                  *cmdWrite = 0xa000000;
                  *pdVar15 = *(dword *)(accel + 0x84);
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)pdVar30 - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = pdVar30;
                  *pdVar30 = 0x10000000;
                  *pdVar16 = *(dword *)*DAT_0000e6e4;
                  *pdVar19 = DAT_0000e6e4[7];
                  if (DAT_0000e6c0 == 0x10) {
                    *pdVar26 = 3;
                  }
                  else {
                    *pdVar26 = 6;
                  }
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)pdVar21 - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = pdVar21;
                  *pdVar21 = 0x13000000;
                  pdVar21[1] = *(undefined4 *)**(undefined4 **)(local_f0 + 0x64c4);
                  pdVar21[2] = 0;
                  cmdWrite = pdVar21 + 4;
                  pdVar21[3] = 0;
                  iVar12 = *(int *)(accel + 0x70);
                  cmdWordsLeft = cmdWordsLeft - 10;
                  *cmdWrite = 0x850;
                  pdVar21[5] = 0x100;
                  pdVar21[6] = 0x887;
                  pdVar21[7] = 0x1c000;
                  pdVar21[8] = 0x82c;
                  pdVar21[9] = 0;
                  pdVar21[10] = 0x1002;
                  pdVar21[0xb] = 0;
                  pdVar21[0xc] = 0x824;
                  pdVar21[0xd] = 1;
                  pdVar21[0xe] = 0x825;
                  pdVar21[0xf] = 0x12;
                  pdVar21[0x10] = 0x82d;
                  pdVar21[0x11] = 5;
                  pdVar21[0x12] = 0x854;
                  pdVar21[0x13] = 0x6010006;
                  pdVar21[0x14] = 0x855;
                  pdVar21[0x15] = 0x2701;
                  pdVar21[0x16] = 0x878;
                  pdVar21[0x17] = 0xf688f688;
                  pdVar21[0x18] = 0x879;
                  pdVar21[0x19] = 0xfb24f688;
                  pdVar21[0x1a] = 0x10a2;
                  pdVar21[0x1b] = 0;
                  pdVar21[0x1c] = 0x1381;
                  pdVar21[0x1d] = 0;
                  pdVar21[0x1e] = 0x109e;
                  pdVar21[0x1f] = 5;
                  pdVar21[0x20] = 0x1383;
                  pdVar21[0x21] = 0xf;
                  pdVar21[0x22] = 0x1004;
                  pdVar21[0x23] = 0x66666666;
                  pdVar21[0x24] = 0x1005;
                  pdVar21[0x25] = 0x66666666;
                  pdVar21[0x26] = 0x10ae;
                  pdVar21[0x27] = 0;
                  pdVar21[0x28] = 0x10ea;
                  pdVar21[0x29] = 0x2da49525;
                  pdVar21[0x2a] = 0x10fa;
                  pdVar21[0x2b] = 0xffffff;
                  pdVar21[0x2c] = 0x10f4;
                  pdVar21[0x2d] = 0xffff;
                  pdVar21[0x2e] = 0x10f8;
                  pdVar21[0x2f] = 0;
                  pdVar21[0x30] = 0x10f9;
                  pdVar21[0x31] =
                       *(uint *)(accel + 0x54) & 0x1fff |
                       (*(uint *)(accel + 0x58) & 0x1fff) << 0xd;
                  pdVar21[0x32] = 0x13c0;
                  pdVar21[0x33] = 0;
                  pdVar21[0x34] = 0x13c1;
                  pdVar21[0x35] = 0;
                  pdVar21[0x36] = 0x10c0;
                  pdVar21[0x37] = 0x40004;
                  pdVar21[0x38] = 0x10c1;
                  pdVar21[0x39] = 1;
                  pdVar21[0x3a] = 0x10c8;
                  pdVar21[0x3b] = 0x10;
                  pdVar21[0x3c] = 0x10c9;
                  pdVar21[0x3d] = 0x31;
                  pdVar21[0x3e] = 0x101d;
                  pdVar21[0x3f] = 0x28ffe040;
                  pdVar21[0x40] = 0x101e;
                  pdVar21[0x41] = 0x28ffe0c2;
                  pdVar21[0x42] = 0x1041;
                  pdVar21[0x43] = 3;
                  pdVar21[0x44] = 0x1040;
                  pdVar21[0x45] = 0;
                  pdVar21[0x46] = 0x1100;
                  pdVar21[0x47] = 0x2a92;
                  pdVar21[0x48] = 0x1101;
                  pdVar21[0x49] = 0x10002a92;
                  pdVar21[0x4a] = 0x1120;
                  screenWidth = *(short *)(accel + 0x50);
                  screenHeight = *(short *)(accel + 0x52);
                  pdVar21[0x4b] =
                       (int)screenWidth - 1U & 0x7ff | (screenHeight + -1) * 0x800 & 0x3ff800U | 0x80000000
                  ;
                  pdVar21[0x4c] = 0x1121;
                  uVar17 = (int)*(short *)(textureDesc + 4) - 1;
                  iVar25 = *(short *)(textureDesc + 6) + -1;
                  pdVar21[0x4d] = uVar17 & 0x7ff | iVar25 * 0x800 & 0x3ff800U | 0x80000000;
                  pdVar21[0x4e] = 0x1130;
                  iVar23 = 0x5300c - (uint)(iVar12 == 3);
                  pdVar21[0x4f] = iVar23;
                  pdVar21[0x50] = 0x1131;
                  pdVar21[0x51] = iVar23;
                  pdVar21[0x52] = 0x1140;
                  pdVar21[0x53] =
                       *(int *)(accel + 0x5c) - 1U & 0x3fff | ((int)screenWidth - 1U) * 0x10 & 0x8000
                       | (screenHeight + -1) * 0x20 & 0x10000U;
                  pdVar21[0x54] = 0x1141;
                  pdVar21[0x55] =
                       *(int *)(textureDesc + 0x10) - 1U & 0x3fff | uVar17 * 0x10 & 0x8000 |
                       iVar25 * 0x20 & 0x10000U;
                  if (noMaskFlags) {
                    iVar31 = 0x52;
                    iVar14 = 0x148;
                    local_164 = 0x56;
                    local_168 = 0x57;
                    local_16c = 0x58;
                    local_170 = 0x59;
                    local_174 = 0x5a;
                    local_178 = 0x5b;
                    local_17c = 0x5c;
                    local_180 = 0x5d;
                    iVar50 = 0x5f;
                    local_184 = 0x5e;
                    iVar34 = 0x53;
                    iVar36 = 0x54;
                    iVar51 = 0x60;
                    iVar39 = 0x55;
                    iVar49 = 0x61;
                    iVar40 = 0x62;
                    iVar41 = 99;
                    iVar43 = 100;
                    iVar45 = 0x65;
                    iVar46 = 0x66;
                    iVar10 = 0x67;
                    iVar47 = 0x68;
                    iVar23 = 0x69;
                    iVar25 = 0x6a;
                    iVar13 = 0x6b;
                    iVar12 = 0x6c;
                  }
                  else {
                    if (iVar12 == 3) {
                      uStack_284 = fillColor >> 5 & 0x1f;
                      uStack_27c = fillColor & 0x1f;
                      uStack_294 = fillColor >> 0xf & 1;
                      i2dHi11 = 0x43300000;
                      i2dHi12 = 0x43300000;
                      i2dHi9 = 0x43300000;
                      local_128 = (float)(dVar6 - 4503599627370496.0) / 31.0;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_284) -
                                         4503599627370496.0) / 31.0;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_27c) -
                                         4503599627370496.0) / 31.0;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_294) -
                                         4503599627370496.0);
                    }
                    else {
                      uStack_274 = fillColor >> 0x18;
                      uStack_26c = fillColor >> 0x10 & 0xff;
                      uStack_25c = fillColor & 0xff;
                      uStack_264 = fillColor >> 8 & 0xff;
                      i2dHi13 = 0x43300000;
                      i2dHi14 = 0x43300000;
                      i2dHi15 = 0x43300000;
                      i2dHi16 = 0x43300000;
                      local_134 = (float)((double)CONCAT44(0x43300000,uStack_274) -
                                         4503599627370496.0) / 255.0;
                      local_128 = (float)((double)CONCAT44(0x43300000,uStack_26c) -
                                         4503599627370496.0) / 255.0;
                      local_130 = (float)((double)CONCAT44(0x43300000,uStack_25c) -
                                         4503599627370496.0) / 255.0;
                      local_12c = (float)((double)CONCAT44(0x43300000,uStack_264) -
                                         4503599627370496.0) / 255.0;
                    }
                    pdVar21[0x56] = 0x1094;
                    pdVar21[0x57] = 0x10000;
                    pdVar21[0x58] = 0x1095;
                    pdVar21[0x59] = (dword)GH_F2U(local_128);
                    pdVar21[0x5a] = 0x1095;
                    pdVar21[0x5b] = (dword)GH_F2U(local_12c);
                    pdVar21[0x5c] = 0x1095;
                    pdVar21[0x5d] = (dword)GH_F2U(local_130);
                    pdVar21[0x5e] = 0x1095;
                    pdVar21[0x5f] = (dword)GH_F2U(local_134);
                    iVar31 = 0x5c;
                    iVar14 = 0x170;
                    local_164 = 0x60;
                    local_168 = 0x61;
                    local_16c = 0x62;
                    local_170 = 99;
                    local_174 = 100;
                    local_178 = 0x65;
                    local_17c = 0x66;
                    local_180 = 0x67;
                    iVar50 = 0x69;
                    local_184 = 0x68;
                    iVar34 = 0x5d;
                    iVar36 = 0x5e;
                    iVar51 = 0x6a;
                    iVar39 = 0x5f;
                    iVar49 = 0x6b;
                    iVar40 = 0x6c;
                    iVar41 = 0x6d;
                    iVar43 = 0x6e;
                    iVar45 = 0x6f;
                    iVar46 = 0x70;
                    iVar10 = 0x71;
                    iVar47 = 0x72;
                    iVar23 = 0x73;
                    iVar25 = 0x74;
                    iVar13 = 0x75;
                    iVar12 = 0x76;
                  }
                  *(undefined4 *)((int)cmdWrite + iVar14) = 0x1094;
                  cmdWrite[iVar34] = 0;
                  cmdWrite[iVar36] = 0x1095;
                  cmdWrite[iVar39] = 0x7803;
                  cmdWrite[local_164] = 0x1095;
                  cmdWrite[local_168] = 0x2410000;
                  cmdWrite[local_16c] = 0x1095;
                  cmdWrite[local_170] = 0x3901e401;
                  cmdWrite[local_174] = 0x1095;
                  cmdWrite[local_178] = 0;
                  cmdWrite[local_17c] = 0x1095;
                  cmdWrite[local_180] = 0;
                  cmdWrite[local_184] = 0x1095;
                  cmdWrite[iVar50] = 0;
                  if (noMaskFlags) {
                    cmdWrite[iVar51] = 0x1095;
                    cmdWrite[iVar49] = 0x78105;
                    cmdWrite[iVar40] = 0x1095;
                    cmdWrite[iVar41] = 1;
                    cmdWrite[iVar43] = 0x1095;
                    cmdWrite[iVar45] = 1;
                    cmdWrite[iVar46] = 0x1095;
                    cmdWrite[iVar10] = 0xdb0220;
                    cmdWrite[iVar47] = 0x1095;
                    cmdWrite[iVar23] = 0xc0c006;
                    cmdWrite[iVar25] = 0x1095;
                    cmdWrite[iVar13] = 0x20490000;
                  }
                  else {
                    cmdWrite[iVar51] = 0x1095;
                    cmdWrite[iVar49] = 0x7807;
                    cmdWrite[iVar40] = 0x1095;
                    cmdWrite[iVar41] = 0x2400000;
                    cmdWrite[iVar43] = 0x1095;
                    cmdWrite[iVar45] = 0x3900e400;
                    cmdWrite[iVar46] = 0x1095;
                    cmdWrite[iVar10] = 0;
                    cmdWrite[iVar47] = 0x1095;
                    cmdWrite[iVar23] = 0;
                    cmdWrite[iVar25] = 0x1095;
                    cmdWrite[iVar13] = 0;
                    cmdWrite[iVar12] = 0x1095;
                    cmdWrite[iVar31 + 0x1b] = 0x7804;
                    cmdWrite[iVar31 + 0x1c] = 0x1095;
                    cmdWrite[iVar31 + 0x1d] = 0x40040000;
                    cmdWrite[iVar31 + 0x1e] = 0x1095;
                    cmdWrite[iVar31 + 0x1f] = 0x40040000;
                    cmdWrite[iVar31 + 0x20] = 0x1095;
                    cmdWrite[iVar31 + 0x21] = 0xdb0490;
                    cmdWrite[iVar31 + 0x22] = 0x1095;
                    cmdWrite[iVar31 + 0x23] = 0xc10026;
                    cmdWrite[iVar31 + 0x24] = 0x1095;
                    cmdWrite[iVar31 + 0x25] = 0xdfa23028;
                    cmdWrite[iVar31 + 0x26] = 0x1095;
                    cmdWrite[iVar31 + 0x27] = 0x7800;
                    cmdWrite[iVar31 + 0x28] = 0x1095;
                    cmdWrite[iVar31 + 0x29] = 2;
                    cmdWrite[iVar31 + 0x2a] = 0x1095;
                    cmdWrite[iVar31 + 0x2b] = 2;
                    cmdWrite[iVar31 + 0x2c] = 0x1095;
                    cmdWrite[iVar31 + 0x2d] = 0xdb0220;
                    cmdWrite[iVar31 + 0x2e] = 0x1095;
                    cmdWrite[iVar31 + 0x2f] = 0xc0c021;
                    cmdWrite[iVar31 + 0x30] = 0x1095;
                    cmdWrite[iVar31 + 0x31] = 0x22;
                    cmdWrite[iVar31 + 0x32] = 0x1095;
                    cmdWrite[iVar31 + 0x33] = 0x78101;
                    cmdWrite[iVar31 + 0x34] = 0x1095;
                    uVar17 = (maskBit ^ 1) << 10 | maskBit | 0x200000;
                    cmdWrite[iVar31 + 0x35] = uVar17;
                    cmdWrite[iVar31 + 0x36] = 0x1095;
                    cmdWrite[iVar31 + 0x37] = uVar17;
                    cmdWrite[iVar31 + 0x38] = 0x1095;
                    cmdWrite[iVar31 + 0x39] = 0x440221;
                    cmdWrite[iVar31 + 0x3a] = 0x1095;
                    cmdWrite[iVar31 + 0x3b] = 0x60d006;
                    cmdWrite[iVar31 + 0x3c] = 0x1095;
                    iVar12 = iVar31 + 0x3e;
                    cmdWrite[iVar31 + 0x3d] = 0xdda22008;
                  }
                  cmdWrite[iVar12] = 0x1189;
                  cmdWrite[iVar12 + 1] = 0;
                  cmdWrite[iVar12 + 2] = 0x1181;
                  cmdWrite[iVar12 + 3] = 5;
                  cmdWrite[iVar12 + 4] = 0x118d;
                  if (noMaskFlags) {
                    dVar11 = 0x10000;
                  }
                  else {
                    dVar11 = 0x40000;
                  }
                  cmdWrite[iVar12 + 5] = dVar11;
                  cmdWrite[iVar12 + 6] = 0x118e;
                  cmdWrite[iVar12 + 7] = 0;
                  cmdWrite[iVar12 + 8] = 0x118c;
                  if (noMaskFlags) {
                    dVar11 = 0x10000;
                  }
                  else {
                    dVar11 = 0x40000;
                  }
                  cmdWrite[iVar12 + 9] = dVar11;
                  cmdWrite[iVar12 + 10] = 0x11a9;
                  cmdWrite[iVar12 + 0xb] = 0x1b01;
                  cmdWrite[iVar12 + 0xc] = 0x11aa;
                  cmdWrite[iVar12 + 0xd] = 0xf;
                  cmdWrite[iVar12 + 0xe] = 0x11ab;
                  cmdWrite[iVar12 + 0xf] = 0xf;
                  cmdWrite[iVar12 + 0x10] = 0x11ac;
                  cmdWrite[iVar12 + 0x11] = 0xf;
                  cmdWrite[iVar12 + 0x12] = 0x12f0;
                  cmdWrite[iVar12 + 0x13] = 0;
                  cmdWrite[iVar12 + 0x14] = 0x12f5;
                  cmdWrite[iVar12 + 0x15] = 0;
                  idxPlus23Block2 = iVar12 + 0x17;
                  idxPlus24Block2 = iVar12 + 0x18;
                  iVar25 = iVar12 + 0x30;
                  i2dHi17 = 0x43300000;
                  i2dHi18 = 0x43300000;
                  iVar14 = iVar12 + 0x1a;
                  iVar36 = iVar12 + 0x19;
                  uStack_254 = tileTop;
                  uStack_24c = tileBottom;
                  idxPlus30Block2 = iVar12 + 0x1e;
                  idxPlus31Block2 = iVar12 + 0x1f;
                  idxPlus27Block2 = iVar12 + 0x1b;
                  idxPlus34Block2 = iVar12 + 0x22;
                  idxPlus36Block2 = iVar12 + 0x24;
                  local_138 = (iVar12 + 0x16) * 4;
                  idxPlus29Block2 = iVar12 + 0x1d;
                  idxPlus32Block2 = iVar12 + 0x20;
                  iVar13 = iVar12 + 0x1c;
                  idxPlus33Block2 = iVar12 + 0x21;
                  iVar34 = iVar12 + 0x25;
                  iVar23 = iVar12 + 0x26;
                  iVar31 = iVar12 + 0x23;
                  iVar47 = iVar12 + 0x27;
                  iVar39 = iVar12 + 0x28;
                  iVar40 = iVar12 + 0x29;
                  iVar41 = iVar12 + 0x2a;
                  iVar43 = iVar12 + 0x2b;
                  iVar45 = iVar12 + 0x2c;
                  iVar46 = iVar12 + 0x2d;
                  iVar10 = iVar12 + 0x2e;
                  iVar12 = iVar12 + 0x2f;
                  fVar2 = (float)((double)CONCAT44(0x43300000,tileTop) - 4503599627370496.0);
                  fVar3 = (float)((double)CONCAT44(0x43300000,tileBottom) - 4503599627370496.0);
                  while( true ) {
                    uStack_23c = tileRight;
                    i2dHi21 = 0x43300000;
                    i2dHi22 = 0x43300000;
                    i2dHi19 = 0x43300000;
                    i2dHi20 = 0x43300000;
                    i2dLo5 = (int)screenWidth ^ 0x80000000;
                    i2dLo6 = (int)screenHeight ^ 0x80000000;
                    local_304 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo5) -
                                             4503601774854144.0);
                    local_300 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo6) -
                                             4503601774854144.0);
                    local_308 = local_304 *
                                (float)((double)CONCAT44(0x43300000,uStack_244) - 4503599627370496.0
                                       );
                    local_304 = local_304 *
                                (float)((double)CONCAT44(0x43300000,tileRight) - 4503599627370496.0)
                    ;
                    local_2fc = (uint)GH_F2U((float)((local_300 * fVar3)));
                    local_300 = local_300 * fVar2;
                    *(undefined4 *)((int)cmdWrite + local_138) = 0xc0143500;
                    cmdWrite[idxPlus23Block2] = 0x4003d;
                    iVar49 = tileRight - uStack_244;
                    if ((iVar49 == 8) && (tileHeight == 8)) {
                      i2dHi29 = 0x43300000;
                      i2dLo11 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      local_2f8 = (fVar9 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo11) -
                                                4503601774854144.0));
                      i2dHi30 = 0x43300000;
                      i2dLo12 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      local_2f4 = (fVar9 + 8.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo12) -
                                                4503601774854144.0));
                      i2dHi31 = 0x43300000;
                      i2dLo13 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      local_2f0 = (fVar1 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo13) -
                                                4503601774854144.0));
                      i2dHi32 = 0x43300000;
                      i2dLo14 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      scratchWord2 = (uint)GH_F2U((float)(((fVar1 + 8.0) *
                                        (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo14) -
                                                      4503601774854144.0)))));
                    }
                    else {
                      i2dHi23 = 0x43300000;
                      i2dHi24 = 0x43300000;
                      i2dLo7 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      local_2f8 = (fVar9 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo7) -
                                                4503601774854144.0));
                      i2dHi25 = 0x43300000;
                      i2dLo8 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      local_2f4 = (fVar9 + (float)((double)CONCAT44(0x43300000,iVar49) -
                                                  4503599627370496.0)) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo8) -
                                                4503601774854144.0));
                      i2dHi26 = 0x43300000;
                      iStack_1f4 = tileHeight;
                      i2dHi27 = 0x43300000;
                      i2dLo9 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      local_2f0 = (fVar1 + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo9) -
                                                4503601774854144.0));
                      i2dHi28 = 0x43300000;
                      i2dLo10 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      scratchWord2 = (uint)GH_F2U((float)(((fVar1 + (float)((double)CONCAT44(0x43300000,tileHeight) -
                                                         4503599627370496.0)) *
                                        (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo10) -
                                                      4503601774854144.0)))));
                      iStack_20c = iVar49;
                    }
                    cmdWrite[idxPlus24Block2] = uStack_244 | tileBottomHi;
                    fVar27 = *local_ec;
                    cmdWrite[iVar36] = (dword)GH_F2U(fVar27);
                    dVar18 = *local_e0;
                    cmdWrite[iVar14] = dVar18;
                    fVar22 = *local_dc;
                    cmdWrite[idxPlus27Block2] = (dword)GH_F2U(fVar22);
                    dVar11 = *local_d0;
                    cmdWrite[iVar13] = dVar11;
                    cmdWrite[idxPlus29Block2] = uStack_244 | tileTopHi;
                    cmdWrite[idxPlus30Block2] = (dword)GH_F2U(fVar27);
                    fVar28 = *local_e4;
                    cmdWrite[idxPlus31Block2] = (dword)GH_F2U(fVar28);
                    cmdWrite[idxPlus32Block2] = (dword)GH_F2U(fVar22);
                    fVar27 = *local_d4;
                    cmdWrite[idxPlus33Block2] = (dword)GH_F2U(fVar27);
                    cmdWrite[idxPlus34Block2] = tileRight | tileTopHi;
                    fVar22 = *local_e8;
                    cmdWrite[iVar31] = (dword)GH_F2U(fVar22);
                    cmdWrite[idxPlus36Block2] = (dword)GH_F2U(fVar28);
                    fVar28 = *local_d8;
                    cmdWrite[iVar34] = (dword)GH_F2U(fVar28);
                    cmdWrite[iVar23] = (dword)GH_F2U(fVar27);
                    cmdWrite[iVar47] = tileRight | tileBottomHi;
                    cmdWrite[iVar39] = (dword)GH_F2U(fVar22);
                    cmdWrite[iVar40] = dVar18;
                    cmdWrite[iVar41] = (dword)GH_F2U(fVar28);
                    cmdWrite[iVar43] = dVar11;
                    cmdWrite[iVar45] = 0x1393;
                    cmdWrite[iVar46] = 10;
                    cmdWrite[iVar10] = 0x5c8;
                    cmdWrite[iVar12] = 0x20000;
                    cmdWordsLeft = cmdWordsLeft - iVar25;
                    cmdWrite = cmdWrite + iVar25;
                    tileRight = dstRight;
                    if (uStack_244 + 0x10 < dstRight) {
                      tileRight = uStack_244 + 0x10;
                    }
                    firstTile = false;
                    if (dstRight <= uVar35) goto LAB_0000a09c;
                    uVar17 = uVar35 + 8;
                    uVar37 = uVar35;
LAB_00008bec:
                    if (cmdWordsLeft < 0x1a) break;
                    screenWidth = *(short *)(accel + 0x50);
                    iVar23 = 0x10;
                    iVar25 = 0x1a;
                    iVar34 = 0xf;
                    iVar12 = 0x19;
                    iVar10 = 0x18;
                    iVar46 = 0x17;
                    iVar45 = 0x16;
                    iVar43 = 0x15;
                    iVar41 = 0x14;
                    iVar40 = 0x13;
                    iVar39 = 0x12;
                    iVar47 = 0x11;
                    iVar31 = 0xd;
                    iVar13 = 6;
                    iVar14 = 4;
                    screenHeight = *(short *)(accel + 0x52);
                    idxPlus36Block2 = 0xe;
                    idxPlus34Block2 = 0xc;
                    idxPlus32Block2 = 10;
                    idxPlus31Block2 = 9;
                    idxPlus30Block2 = 8;
                    idxPlus29Block2 = 7;
                    idxPlus33Block2 = 0xb;
                    idxPlus24Block2 = 2;
                    iVar36 = 3;
                    idxPlus27Block2 = 5;
                    idxPlus23Block2 = 1;
                    local_138 = 0;
                    uVar35 = uVar17;
                    uStack_244 = uVar37;
                  }
                  scratchWord1 = *(uint *)(accel + 0x18);
                  scratchWord0 = 0;
                  if (*(int *)(accel + 0x8c) == 0) {
                    *cmdWrite = 0x5c8;
                    scratchWord0 = 2;
                    cmdWrite[1] = 0xc000;
                    *(undefined4 *)(accel + 0x94) = 0;
                  }
                  cmdWrite[scratchWord0] = 0x1000000;
                  taskPtr = PTR_0000e694;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
                  iVar23 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord1,&scratchWord0,1);
                  if (iVar23 == 0) {
                    *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                    *(uint *)(accel + 0x18) = scratchWord1;
                    cmdWrite = (dword *)(scratchWord1 + 0x20);
                    pdVar21 = (dword *)(scratchWord1 + 0x38);
                    *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                    pdVar15 = (dword *)(scratchWord1 + 0x24);
                    pdVar30 = (dword *)(scratchWord1 + 0x28);
                    pdVar16 = (dword *)(scratchWord1 + 0x2c);
                    pdVar19 = (dword *)(scratchWord1 + 0x30);
                    pdVar26 = (dword *)(scratchWord1 + 0x34);
                    uVar35 = uVar37 + 8;
                    uStack_244 = uVar37;
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    pdVar21 = &__mh_bundle_header.flags;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    pdVar26 = &__mh_bundle_header.sizeofcmds;
                    pdVar19 = &__mh_bundle_header.ncmds;
                    pdVar16 = &__mh_bundle_header.filetype;
                    pdVar30 = &__mh_bundle_header.cpusubtype;
                    pdVar15 = &__mh_bundle_header.cputype;
                    cmdWrite = (dword *)0x0;
                    uVar35 = uVar37 + 8;
                    uStack_244 = uVar37;
                    cmdWordsLeft = cmdCapacity;
                  }
                } while( true );
              }
LAB_0000a09c:
              tileBottom = dstBottom;
              if (tileTop + 0x10 < dstBottom) {
                tileBottom = tileTop + 0x10;
              }
              uVar17 = tileTop + 8;
            } while (tileTop + 8 < dstBottom);
          }
          if (cmdWordsLeft < 0x86) {
            scratchWord0 = *(uint *)(accel + 0x18);
            scratchWord1 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *cmdWrite = 0x5c8;
              scratchWord1 = 2;
              cmdWrite[1] = 0xc000;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            cmdWrite[scratchWord1] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
            iVar23 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&scratchWord0,&scratchWord1,1);
            if (iVar23 == 0) {
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              pdVar30 = (dword *)(scratchWord0 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              pdVar15 = (dword *)(scratchWord0 + 0x24);
              pdVar16 = (dword *)(scratchWord0 + 0x28);
              pdVar19 = (dword *)(scratchWord0 + 0x2c);
              pdVar26 = (dword *)(scratchWord0 + 0x30);
              pdVar21 = (dword *)(scratchWord0 + 0x34);
              cmdWordsLeft = cmdCapacity;
            }
            else {
              cmdWrite = (dword *)0x0;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              pdVar15 = &__mh_bundle_header.cputype;
              pdVar16 = &__mh_bundle_header.cpusubtype;
              pdVar19 = &__mh_bundle_header.filetype;
              pdVar26 = &__mh_bundle_header.ncmds;
              pdVar21 = &__mh_bundle_header.sizeofcmds;
              pdVar30 = &__mh_bundle_header.flags;
              cmdWordsLeft = cmdCapacity;
            }
          }
          else {
            pdVar15 = cmdWrite + 1;
            pdVar16 = cmdWrite + 2;
            pdVar19 = cmdWrite + 3;
            pdVar26 = cmdWrite + 4;
            pdVar21 = cmdWrite + 5;
            pdVar30 = cmdWrite + 6;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWrite;
          *cmdWrite = 0x11000000;
          *pdVar15 = *(dword *)(accel + 0x84);
          *pdVar16 = 0;
          *pdVar19 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pdVar26 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pdVar26;
          *pdVar26 = 0x4000000;
          *pdVar21 = *(dword *)*DAT_0000e6e4;
          puVar8 = DAT_0000e6e4;
          iVar23 = DAT_0000e6e4[0xc];
          if (iVar23 == 3) {
            iVar23 = 0xb;
          }
          else if (iVar23 == 6) {
            iVar23 = 0xc;
          }
          iVar23 = ((int (*)())_radeon3DCopySetup)(accel,pdVar30,DAT_0000e6e4 + 3,iVar23,0,0,0,0);
          uStack_1c4 = dstLeft;
          uStack_1b4 = dstTop;
          uStack_1bc = dstRight;
          uStack_1ac = dstBottom;
          i2dHi33 = 0x43300000;
          i2dHi34 = 0x43300000;
          i2dHi35 = 0x43300000;
          i2dHi36 = 0x43300000;
          pdVar30[iVar23] = 0xc00c3500;
          pdVar30[iVar23 + 1] = 0x4003d;
          i2dHi37 = 0x43300000;
          i2dLo15 = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
          local_2fc = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstLeft) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo15) -
                                          4503601774854144.0))));
          i2dHi38 = 0x43300000;
          i2dLo16 = (int)*(short *)(puVar8 + 4) ^ 0x80000000;
          scratchWord2 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstRight) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo16) -
                                          4503601774854144.0))));
          i2dHi39 = 0x43300000;
          i2dLo17 = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
          scratchWord1 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstTop) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo17) -
                                          4503601774854144.0))));
          i2dHi40 = 0x43300000;
          i2dLo18 = (int)*(short *)((int)puVar8 + 0x12) ^ 0x80000000;
          scratchWord0 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstBottom) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo18) -
                                          4503601774854144.0))));
          pdVar30[iVar23 + 2] = dstLeft | dstBottom << 0x10;
          pdVar30[iVar23 + 3] = local_2fc;
          pdVar30[iVar23 + 4] = scratchWord0;
          pdVar30[iVar23 + 5] = dstLeft | dstTop << 0x10;
          pdVar30[iVar23 + 6] = local_2fc;
          pdVar30[iVar23 + 7] = scratchWord1;
          pdVar30[iVar23 + 8] = dstRight | dstTop << 0x10;
          pdVar30[iVar23 + 9] = scratchWord2;
          pdVar30[iVar23 + 10] = scratchWord1;
          pdVar30[iVar23 + 0xb] = dstRight | dstBottom << 0x10;
          pdVar30[iVar23 + 0xc] = scratchWord2;
          pdVar30[iVar23 + 0xd] = scratchWord0;
          pdVar30[iVar23 + 0xe] = 0x1393;
          pdVar30[iVar23 + 0xf] = 10;
          pdVar30[iVar23 + 0x10] = 0x5c8;
          pdVar30[iVar23 + 0x11] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - (iVar23 + 0x12);
          rectEntry = rectEntry + 4;
          cmdWrite = pdVar30 + iVar23 + 0x12;
          local_104 = local_104 + 1;
        } while (local_104 < (uint)fillReq[0x16]);
      }
      *(dword **)(accel + 0x80) = cmdWrite;
      return 0;
    }
  }
  else {
    rectEntry = *(undefined4 **)(accel + 0x80);
    iVar23 = *(int *)(*(int *)(accel + 0x18) + 0x10);
    local_fc = iVar23 - 7;
    if (rectEntry != (undefined4 *)0x0) {
      cmdCapacity = fillReq[0x16];
      cmdWordsLeft = local_fc - ((int)rectEntry - (*(int *)(accel + 0x18) + 0x20) >> 2);
      local_100 = (iVar23 - 0x75U) / 0xc - 1;
      if (cmdCapacity != 0) {
        local_c0 = &local_300;
        local_188 = local_100 * 0xc + 0x6e;
        fillColor = 0;
        do {
          if (cmdWordsLeft < local_188) {
            local_2fc = *(uint *)(accel + 0x18);
            scratchWord2 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *rectEntry = 0x5c8;
              scratchWord2 = 2;
              rectEntry[1] = 0xc000;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            rectEntry[scratchWord2] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)rectEntry - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
            iVar23 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&local_2fc,&scratchWord2,1);
            cmdWordsLeft = local_fc;
            if (iVar23 == 0) {
              *(undefined4 *)(local_2fc + 0x1c) = 0;
              *(uint *)(accel + 0x18) = local_2fc;
              rectEntry = (undefined4 *)(local_2fc + 0x20);
              *(uint *)(accel + 0x7c) = local_2fc + 0x1c;
              cmdCapacity = fillReq[0x16];
            }
            else {
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              rectEntry = (undefined4 *)0x0;
              cmdCapacity = fillReq[0x16];
            }
          }
          uVar33 = fillColor + local_100;
          if (uVar33 < cmdCapacity) {
            cmdCapacity = uVar33;
          }
          iVar23 = ((int (*)())_radeon3DFillSetup)(rectEntry,0,patternBuf,accel);
          iVar25 = cmdCapacity - fillColor;
          rectEntry[iVar23] = iVar25 * 0xc0000 | 0xc0003500;
          iVar12 = iVar23 + 2;
          rectEntry[iVar23 + 1] = iVar25 * 0x40000 | 0x3d;
          if (fillColor < cmdCapacity) {
            iVar23 = iVar12 * 4;
            iVar34 = *(int *)(accel + 0x60);
            iVar36 = *(int *)(accel + 100);
            iVar39 = iVar23 + 4;
            iVar40 = iVar23 + 0x28;
            iVar41 = iVar23 + 0x24;
            piVar20 = fillReq + fillColor * 4 + 0x17;
            iVar43 = iVar23 + 0x20;
            iVar45 = iVar23 + 0x1c;
            iVar46 = iVar23 + 0x18;
            iVar31 = iVar23 + 0x14;
            iVar13 = iVar23 + 0x10;
            iVar14 = iVar23 + 0xc;
            iVar23 = iVar23 + 8;
            do {
              i2dHi1 = 0x43300000;
              i2dLo1 = *piVar20 + iVar34 ^ 0x80000000;
              local_2fc = (uint)GH_F2U((float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0
                                       ));
              i2dHi2 = 0x43300000;
              i2dLo2 = *piVar20 + iVar34 + piVar20[2] ^ 0x80000000;
              local_300 = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
              i2dHi3 = 0x43300000;
              i2dLo3 = piVar20[1] + iVar36 ^ 0x80000000;
              local_304 = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
              i2dHi4 = 0x43300000;
              i2dLo4 = piVar20[1] + iVar36 + piVar20[3] ^ 0x80000000;
              local_308 = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
              rectEntry[iVar12] = local_2fc;
              *(float *)((int)rectEntry + iVar39) = local_308;
              *(undefined4 *)((int)rectEntry + iVar23) = 0;
              *(uint *)((int)rectEntry + iVar14) = local_2fc;
              *(float *)((int)rectEntry + iVar13) = local_304;
              *(undefined4 *)((int)rectEntry + iVar31) = 0;
              fVar9 = *local_c0;
              *(float *)((int)rectEntry + iVar46) = fVar9;
              *(float *)((int)rectEntry + iVar45) = local_304;
              *(undefined4 *)((int)rectEntry + iVar43) = 0;
              *(float *)((int)rectEntry + iVar41) = fVar9;
              *(float *)((int)rectEntry + iVar40) = local_308;
              iVar10 = iVar12 + 0xb;
              iVar39 = iVar39 + 0x30;
              iVar12 = iVar12 + 0xc;
              iVar23 = iVar23 + 0x30;
              iVar14 = iVar14 + 0x30;
              iVar13 = iVar13 + 0x30;
              iVar31 = iVar31 + 0x30;
              iVar46 = iVar46 + 0x30;
              iVar45 = iVar45 + 0x30;
              iVar43 = iVar43 + 0x30;
              iVar41 = iVar41 + 0x30;
              iVar40 = iVar40 + 0x30;
              rectEntry[iVar10] = 0;
              piVar20 = piVar20 + 4;
              iVar25 = iVar25 + -1;
            } while (iVar25 != 0);
          }
          rectEntry[iVar12] = 0x1393;
          rectEntry[iVar12 + 1] = 10;
          rectEntry[iVar12 + 2] = 0x5c8;
          rectEntry[iVar12 + 3] = 0x20000;
          cmdCapacity = fillReq[0x16];
          cmdWordsLeft = cmdWordsLeft - (iVar12 + 4);
          rectEntry = rectEntry + iVar12 + 4;
          fillColor = uVar33;
        } while (uVar33 < cmdCapacity);
      }
      *(undefined4 **)(accel + 0x80) = rectEntry;
      return 0;
    }
  }
  return 0xe00002be;
}

/* _radeonHighlight @ 0xa5a0 (5300 bytes) */
int _radeonHighlight(accel, unusedArg2, unusedArg3, unusedArg4, fillReq, highlightColor)
  int accel;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  uint *fillReq;
  uint highlightColor;
{
  short screenWidth;
  short screenHeight;
  double dVar3;
  double dVar4;
  uint *lastHeader;
  int iVar6;
  undefined4 uVar7;
  uint cmdWordsLeft;
  dword *pdVar9;
  dword *pdVar10;
  dword *pdVar11;
  dword *pdVar12;
  float fVar13;
  float fVar14;
  dword dVar15;
  uint uVar16;
  dword *pdVar17;
  dword dVar18;
  dword *pdVar19;
  float fVar20;
  float fVar21;
  undefined4 *puVar22;
  uint uVar23;
  uint *rectEntry;
  uint bottomRightPacked;
  uint topRightPacked;
  uint topLeftPacked;
  uint bottomLeftPacked;
  uint dstTop;
  uint dstRight;
  uint dstLeft;
  dword *cmdWrite;
  int iVar33;
  uint *puStack00000028;
  uint uStack0000002c;
  float local_208;
  float local_204;
  float local_200;
  uint scratchWord1;
  uint scratchWord0;
  float local_1f4;
  float local_1f0;
  float local_1ec [2];
  uint uStack_1e4;
  undefined4 i2dHi1;
  uint uStack_1dc;
  undefined4 i2dHi2;
  uint uStack_1d4;
  undefined4 i2dHi3;
  uint uStack_1cc;
  undefined4 i2dHi4;
  uint uStack_1c4;
  undefined4 i2dHi5;
  uint uStack_1bc;
  undefined4 i2dHi6;
  uint uStack_1b4;
  undefined4 i2dHi7;
  uint uStack_1ac;
  undefined4 i2dHi8;
  uint uStack_1a4;
  undefined4 i2dHi9;
  uint uStack_19c;
  undefined4 i2dHi10;
  uint uStack_194;
  undefined4 i2dHi11;
  uint uStack_18c;
  undefined4 i2dHi12;
  uint uStack_184;
  undefined4 i2dHi13;
  uint uStack_17c;
  undefined4 i2dHi14;
  uint uStack_174;
  undefined4 i2dHi15;
  uint uStack_16c;
  undefined4 i2dHi16;
  uint i2dLo1;
  undefined4 i2dHi17;
  uint i2dLo2;
  undefined4 i2dHi18;
  uint i2dLo3;
  undefined4 i2dHi19;
  uint i2dLo4;
  undefined4 i2dHi20;
  uint i2dLo5;
  undefined4 i2dHi21;
  uint i2dLo6;
  undefined4 i2dHi22;
  uint uStack_124;
  undefined4 i2dHi23;
  uint uStack_11c;
  undefined4 i2dHi24;
  uint uStack_114;
  undefined4 i2dHi25;
  uint uStack_10c;
  undefined4 i2dHi26;
  uint i2dLo7;
  undefined4 i2dHi27;
  uint i2dLo8;
  undefined4 i2dHi28;
  uint i2dLo9;
  undefined4 i2dHi29;
  uint i2dLo10;
  float *local_e8;
  float *local_e4;
  float *local_e0;
  float *local_dc;
  float *local_d8;
  float *local_d4;
  uint local_d0;
  uint cmdCapacity;
  undefined4 shaderWord0;
  undefined4 shaderWord1;
  undefined4 shaderWord2;
  undefined4 shaderWord3;
  undefined4 shaderWord4;
  undefined4 shaderWord5;
  dword *scratchWord1Ptr;
  dword *scratchWord0Ptr;
  float local_a0;
  
  cmdWrite = *(dword **)(accel + 0x80);
  iVar33 = *(int *)(accel + 0x18);
  cmdCapacity = *(int *)(iVar33 + 0x10) - 7;
  if ((cmdWrite == (dword *)0x0) ||
     (puStack00000028 = fillReq, uStack0000002c = highlightColor,
     iVar6 = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,(uint)(*(int *)(accel + 0x70) == 3)),
     iVar6 == 0)) {
    uVar7 = 0xe00002be;
  }
  else {
    uVar23 = *puStack00000028;
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (iVar33 + 0x20) >> 2);
    if (puStack00000028[0x16] != 0) {
      i2dHi4 = 0x43300000;
      i2dHi1 = 0x43300000;
      uStack_1c4 = uStack0000002c >> 0x18;
      uStack_1dc = uStack0000002c >> 10 & 0x1f;
      shaderWord1 = 0xc10016;
      shaderWord0 = 0xdb0490;
      shaderWord2 = 0xdfa23018;
      shaderWord3 = 0xdb0220;
      local_d4 = local_1ec;
      shaderWord5 = 0x440221;
      shaderWord4 = 0xc0c011;
      local_dc = &local_204;
      local_d8 = &local_200;
      local_e0 = &local_208;
      scratchWord0Ptr = &scratchWord0;
      scratchWord1Ptr = &scratchWord1;
      local_e4 = &local_1f4;
      local_e8 = &local_1f0;
      local_d0 = 0;
      dVar4 = (double)CONCAT44(0x43300000,uStack_1c4);
      dVar3 = (double)CONCAT44(0x43300000,uStack_1dc);
      rectEntry = puStack00000028;
      do {
        if (cmdWordsLeft < 0xda) {
          scratchWord0 = *(uint *)(accel + 0x18);
          scratchWord1 = 0;
          if (*(int *)(accel + 0x8c) == 0) {
            *cmdWrite = 0x5c8;
            scratchWord1 = 2;
            cmdWrite[1] = 0xc000;
            *(undefined4 *)(accel + 0x94) = 0;
          }
          cmdWrite[scratchWord1] = 0x1000000;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
          iVar33 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       scratchWord0Ptr,scratchWord1Ptr,1);
          cmdWordsLeft = cmdCapacity;
          if (iVar33 == 0) {
            *(undefined4 *)(scratchWord0 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord0;
            cmdWrite = (dword *)(scratchWord0 + 0x20);
            pdVar10 = (dword *)(scratchWord0 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
            pdVar17 = (dword *)(scratchWord0 + 0x24);
            pdVar19 = (dword *)(scratchWord0 + 0x28);
            pdVar11 = (dword *)(scratchWord0 + 0x2c);
            pdVar12 = (dword *)(scratchWord0 + 0x30);
            pdVar9 = (dword *)(scratchWord0 + 0x34);
          }
          else {
            cmdWrite = (dword *)0x0;
            pdVar17 = &__mh_bundle_header.cputype;
            pdVar19 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(accel + 0x7c) = 0;
            *(undefined4 *)(accel + 0x18) = 0;
            pdVar11 = &__mh_bundle_header.filetype;
            pdVar12 = &__mh_bundle_header.ncmds;
            pdVar9 = &__mh_bundle_header.sizeofcmds;
            pdVar10 = &__mh_bundle_header.flags;
          }
        }
        else {
          pdVar17 = cmdWrite + 1;
          pdVar19 = cmdWrite + 2;
          pdVar11 = cmdWrite + 3;
          pdVar12 = cmdWrite + 4;
          pdVar9 = cmdWrite + 5;
          pdVar10 = cmdWrite + 6;
        }
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = cmdWrite;
        *cmdWrite = 0xa000000;
        *pdVar17 = *(dword *)(accel + 0x84);
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)pdVar19 - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = pdVar19;
        *pdVar19 = 0x10000000;
        *pdVar11 = *(dword *)*DAT_0000e6e4;
        *pdVar12 = DAT_0000e6e4[7];
        if (DAT_0000e6c0 == 0x10) {
          *pdVar9 = 3;
        }
        else {
          *pdVar9 = 6;
        }
        iVar33 = *(int *)(accel + 0x70);
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
             *(uint *)(accel + 0x54) & 0x1fff | (*(uint *)(accel + 0x58) & 0x1fff) << 0xd;
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
        screenWidth = *(short *)(accel + 0x50);
        screenHeight = *(short *)(accel + 0x52);
        uVar16 = (int)screenWidth - 1;
        iVar6 = screenHeight + -1;
        pdVar10[0x3d] = uVar16 & 0x7ff | iVar6 * 0x800 & 0x3ff800U | 0x80000000;
        pdVar10[0x3e] = 0x1130;
        pdVar10[0x3f] = 0x5300c - (uint)(iVar33 == 3);
        pdVar10[0x40] = 0x1140;
        pdVar10[0x41] =
             *(int *)(accel + 0x5c) - 1U & 0x3fff | uVar16 * 0x10 & 0x8000 |
             iVar6 * 0x20 & 0x10000U;
        if (iVar33 != 3) {
          i2dHi5 = 0x43300000;
          fVar14 = (float)(dVar4 - 4503599627370496.0) / 255.0;
          i2dHi6 = 0x43300000;
          i2dHi7 = 0x43300000;
          uStack_1ac = uStack0000002c & 0xff;
          uStack_1bc = uStack0000002c >> 0x10 & 0xff;
          uStack_1b4 = uStack0000002c >> 8 & 0xff;
          fVar20 = (float)((double)CONCAT44(0x43300000,uStack_1bc) - 4503599627370496.0) / 255.0;
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_1b4) - 4503599627370496.0) / 255.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_1ac) - 4503599627370496.0) / 255.0;
        }
        else {
          i2dHi2 = 0x43300000;
          fVar20 = (float)(dVar3 - 4503599627370496.0) / 31.0;
          i2dHi3 = 0x43300000;
          local_1ec[1] = 176.0;
          uStack_1d4 = uStack0000002c >> 5 & 0x1f;
          uStack_1cc = uStack0000002c & 0x1f;
          uStack_1e4 = uStack0000002c >> 0xf & 1;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_1e4) - 4503599627370496.0);
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_1d4) - 4503599627370496.0) / 31.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_1cc) - 4503599627370496.0) / 31.0;
        }
        pdVar10[0x42] = 0x1094;
        pdVar10[0x43] = 0x10000;
        pdVar10[0x44] = 0x1095;
        pdVar10[0x45] = (dword)GH_F2U(fVar20);
        pdVar10[0x46] = 0x1095;
        pdVar10[0x47] = (dword)GH_F2U(fVar21);
        pdVar10[0x48] = 0x1095;
        pdVar10[0x49] = (dword)GH_F2U(fVar13);
        pdVar10[0x4a] = 0x1095;
        pdVar10[0x4b] = (dword)GH_F2U(fVar14);
        if (iVar33 != 3) {
          uStack_184 = uVar23 >> 0x18;
          i2dHi12 = 0x43300000;
          uStack_17c = uVar23 >> 0x10 & 0xff;
          i2dHi13 = 0x43300000;
          i2dHi14 = 0x43300000;
          i2dHi15 = 0x43300000;
          uStack_174 = uVar23 >> 8 & 0xff;
          uStack_16c = uVar23 & 0xff;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_184) - 4503599627370496.0) / 255.0;
          fVar20 = (float)((double)CONCAT44(0x43300000,uStack_17c) - 4503599627370496.0) / 255.0;
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_174) - 4503599627370496.0) / 255.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_16c) - 4503599627370496.0) / 255.0;
          local_a0 = fVar13;
        }
        else {
          uStack_19c = uVar23 >> 10 & 0x1f;
          i2dHi9 = 0x43300000;
          uStack_194 = uVar23 >> 5 & 0x1f;
          i2dHi10 = 0x43300000;
          i2dHi11 = 0x43300000;
          i2dHi8 = 0x43300000;
          uStack_18c = uVar23 & 0x1f;
          uStack_1a4 = uVar23 >> 0xf & 1;
          fVar14 = (float)((double)CONCAT44(0x43300000,uStack_1a4) - 4503599627370496.0);
          fVar20 = (float)((double)CONCAT44(0x43300000,uStack_19c) - 4503599627370496.0) / 31.0;
          fVar21 = (float)((double)CONCAT44(0x43300000,uStack_194) - 4503599627370496.0) / 31.0;
          fVar13 = (float)((double)CONCAT44(0x43300000,uStack_18c) - 4503599627370496.0) / 31.0;
          local_a0 = fVar14;
        }
        pdVar10[0x4c] = 0x1095;
        pdVar10[0x4d] = (dword)GH_F2U(fVar20);
        pdVar10[0x4e] = 0x1095;
        pdVar10[0x4f] = (dword)GH_F2U(fVar21);
        pdVar10[0x50] = 0x1095;
        pdVar10[0x51] = (dword)GH_F2U(fVar13);
        pdVar10[0x52] = 0x1095;
        pdVar10[0x53] = (dword)GH_F2U(fVar14);
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
        pdVar10[0x69] = shaderWord0;
        pdVar10[0x6a] = 0x1095;
        pdVar10[0x6b] = shaderWord1;
        pdVar10[0x6c] = 0x1095;
        pdVar10[0x6d] = shaderWord2;
        pdVar10[0x6e] = 0x1095;
        pdVar10[0x6f] = 0x7800;
        pdVar10[0x70] = 0x1095;
        pdVar10[0x71] = 1;
        pdVar10[0x72] = 0x1095;
        pdVar10[0x73] = 1;
        pdVar10[0x74] = 0x1095;
        pdVar10[0x75] = shaderWord3;
        pdVar10[0x76] = 0x1095;
        pdVar10[0x77] = shaderWord4;
        pdVar10[0x78] = 0x1095;
        pdVar10[0x79] = 0x12;
        pdVar10[0x7a] = 0x1095;
        pdVar10[0x7b] = 0x7800;
        pdVar10[0x7c] = 0x1095;
        pdVar10[0x7d] = 0x140400;
        pdVar10[0x7e] = 0x1095;
        pdVar10[0x7f] = 0x140400;
        pdVar10[0x80] = 0x1095;
        pdVar10[0x81] = shaderWord5;
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
        pdVar10[0x8d] = shaderWord0;
        pdVar10[0x8e] = 0x1095;
        pdVar10[0x8f] = shaderWord1;
        pdVar10[0x90] = 0x1095;
        pdVar10[0x91] = shaderWord2;
        pdVar10[0x92] = 0x1095;
        pdVar10[0x93] = 0x7800;
        pdVar10[0x94] = 0x1095;
        pdVar10[0x95] = 1;
        pdVar10[0x96] = 0x1095;
        pdVar10[0x97] = 1;
        pdVar10[0x98] = 0x1095;
        pdVar10[0x99] = shaderWord3;
        pdVar10[0x9a] = 0x1095;
        pdVar10[0x9b] = shaderWord4;
        pdVar10[0x9c] = 0x1095;
        pdVar10[0x9d] = 0x12;
        pdVar10[0x9e] = 0x1095;
        pdVar10[0x9f] = 0x78101;
        pdVar10[0xa0] = 0x1095;
        pdVar10[0xa1] = 0x140003;
        pdVar10[0xa2] = 0x1095;
        pdVar10[0xa3] = 0x140003;
        pdVar10[0xa4] = 0x1095;
        pdVar10[0xa5] = shaderWord5;
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
        i2dHi20 = 0x43300000;
        i2dHi21 = 0x43300000;
        i2dLo5 = (int)screenWidth ^ 0x80000000;
        i2dLo6 = (int)screenHeight ^ 0x80000000;
        i2dHi16 = 0x43300000;
        i2dHi17 = 0x43300000;
        i2dHi18 = 0x43300000;
        i2dHi19 = 0x43300000;
        dstLeft = rectEntry[0x17] + *(int *)(accel + 0x60);
        dstTop = rectEntry[0x18] + *(int *)(accel + 100);
        dstRight = dstLeft + rectEntry[0x19];
        uVar16 = dstTop + rectEntry[0x1a];
        i2dLo1 = dstLeft ^ 0x80000000;
        i2dLo3 = dstTop ^ 0x80000000;
        i2dLo2 = dstRight ^ 0x80000000;
        i2dLo4 = uVar16 ^ 0x80000000;
        local_208 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0);
        local_200 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo6) - 4503601774854144.0);
        local_1ec[0] = local_208 *
                       (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
        local_208 = local_208 *
                    (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
        local_204 = local_200 *
                    (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
        local_200 = local_200 *
                    (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
        pdVar10[0xc0] = 0xc00c3500;
        pdVar10[0xc1] = 0x4003d;
        bottomLeftPacked = dstLeft | uVar16 * 0x10000;
        pdVar10[0xc2] = bottomLeftPacked;
        fVar20 = *local_d4;
        pdVar10[0xc3] = (dword)GH_F2U(fVar20);
        fVar14 = *local_d8;
        pdVar10[0xc4] = (dword)GH_F2U(fVar14);
        topLeftPacked = dstLeft | dstTop * 0x10000;
        pdVar10[0xc5] = topLeftPacked;
        pdVar10[0xc6] = (dword)GH_F2U(fVar20);
        fVar20 = *local_dc;
        pdVar10[199] = (dword)GH_F2U(fVar20);
        topRightPacked = dstRight | dstTop * 0x10000;
        pdVar10[200] = topRightPacked;
        fVar21 = *local_e0;
        pdVar10[0xc9] = (dword)GH_F2U(fVar21);
        pdVar10[0xca] = (dword)GH_F2U(fVar20);
        bottomRightPacked = dstRight | uVar16 * 0x10000;
        pdVar10[0xcb] = bottomRightPacked;
        pdVar10[0xcc] = (dword)GH_F2U(fVar21);
        pdVar10[0xcd] = (dword)GH_F2U(fVar14);
        pdVar10[0xce] = 0x1393;
        pdVar10[0xcf] = 10;
        pdVar10[0xd0] = 0x5c8;
        pdVar10[0xd1] = 0x20000;
        puVar22 = pdVar10 + 0xd2;
        if (cmdWordsLeft - 0xd8 < 0x86) {
          scratchWord1 = *(uint *)(accel + 0x18);
          scratchWord0 = 0;
          if (*(int *)(accel + 0x8c) == 0) {
            *puVar22 = 0x5c8;
            scratchWord0 = 2;
            pdVar10[0xd3] = 0xc000;
            *(undefined4 *)(accel + 0x94) = 0;
          }
          puVar22[scratchWord0] = 0x1000000;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = ((int)puVar22 - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
          iVar33 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       scratchWord1Ptr,scratchWord0Ptr,1);
          cmdWordsLeft = cmdCapacity;
          if (iVar33 == 0) {
            *(undefined4 *)(scratchWord1 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord1;
            puVar22 = (undefined4 *)(scratchWord1 + 0x20);
            cmdWrite = (dword *)(scratchWord1 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
            pdVar9 = (dword *)(scratchWord1 + 0x24);
            pdVar11 = (dword *)(scratchWord1 + 0x28);
            pdVar12 = (dword *)(scratchWord1 + 0x2c);
            pdVar17 = (dword *)(scratchWord1 + 0x30);
            pdVar10 = (dword *)(scratchWord1 + 0x34);
          }
          else {
            puVar22 = (undefined4 *)0x0;
            pdVar9 = &__mh_bundle_header.cputype;
            pdVar11 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(accel + 0x7c) = 0;
            *(undefined4 *)(accel + 0x18) = 0;
            pdVar12 = &__mh_bundle_header.filetype;
            pdVar17 = &__mh_bundle_header.ncmds;
            pdVar10 = &__mh_bundle_header.sizeofcmds;
            cmdWrite = &__mh_bundle_header.flags;
          }
        }
        else {
          cmdWrite = pdVar10 + 0xd8;
          pdVar9 = pdVar10 + 0xd3;
          pdVar11 = pdVar10 + 0xd4;
          pdVar12 = pdVar10 + 0xd5;
          pdVar17 = pdVar10 + 0xd6;
          pdVar10 = pdVar10 + 0xd7;
          cmdWordsLeft = cmdWordsLeft - 0xd8;
        }
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)puVar22 - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(accel + 0x7c) = puVar22;
        *puVar22 = 0x11000000;
        *pdVar9 = *(dword *)(accel + 0x84);
        *pdVar11 = 0;
        *pdVar12 = 0;
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)pdVar17 - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = pdVar17;
        *pdVar17 = 0x4000000;
        *pdVar10 = *(dword *)*DAT_0000e6e4;
        puVar22 = DAT_0000e6e4;
        iVar33 = DAT_0000e6e4[0xc];
        if (iVar33 == 3) {
          iVar33 = 0xb;
        }
        else if (iVar33 == 6) {
          iVar33 = 0xc;
        }
        iVar33 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,DAT_0000e6e4 + 3,iVar33,0,0,0,0);
        i2dHi22 = 0x43300000;
        i2dHi23 = 0x43300000;
        i2dHi24 = 0x43300000;
        i2dHi25 = 0x43300000;
        cmdWrite[iVar33] = 0xc00c3500;
        cmdWrite[iVar33 + 1] = 0x4003d;
        i2dHi26 = 0x43300000;
        i2dLo7 = (int)*(short *)(puVar22 + 4) ^ 0x80000000;
        scratchWord1 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstLeft) -
                                                 4503599627370496.0) *
                                 (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                        4503601774854144.0))));
        i2dHi27 = 0x43300000;
        i2dLo8 = (int)*(short *)(puVar22 + 4) ^ 0x80000000;
        local_1f0 = (float)((double)(float)((double)CONCAT44(0x43300000,dstRight) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) - 4503601774854144.0)));
        i2dHi28 = 0x43300000;
        i2dLo9 = (int)*(short *)((int)puVar22 + 0x12) ^ 0x80000000;
        local_1f4 = (float)((double)(float)((double)CONCAT44(0x43300000,dstTop) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,i2dLo9) - 4503601774854144.0)));
        i2dHi29 = 0x43300000;
        i2dLo10 = (int)*(short *)((int)puVar22 + 0x12) ^ 0x80000000;
        scratchWord0 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,uVar16) -
                                                 4503599627370496.0) *
                                 (1.0 / ((double)CONCAT44(0x43300000,i2dLo10) - 4503601774854144.0
                                        ))));
        cmdWrite[iVar33 + 2] = bottomLeftPacked;
        dVar18 = *scratchWord1Ptr;
        cmdWrite[iVar33 + 3] = dVar18;
        dVar15 = *scratchWord0Ptr;
        cmdWrite[iVar33 + 4] = dVar15;
        cmdWrite[iVar33 + 5] = topLeftPacked;
        cmdWrite[iVar33 + 6] = dVar18;
        fVar14 = *local_e4;
        cmdWrite[iVar33 + 7] = (dword)GH_F2U(fVar14);
        cmdWrite[iVar33 + 8] = topRightPacked;
        fVar20 = *local_e8;
        cmdWrite[iVar33 + 9] = (dword)GH_F2U(fVar20);
        cmdWrite[iVar33 + 10] = (dword)GH_F2U(fVar14);
        cmdWrite[iVar33 + 0xb] = bottomRightPacked;
        cmdWrite[iVar33 + 0xc] = (dword)GH_F2U(fVar20);
        cmdWrite[iVar33 + 0xd] = dVar15;
        cmdWrite[iVar33 + 0xe] = 0x1393;
        cmdWrite[iVar33 + 0xf] = 10;
        cmdWrite[iVar33 + 0x10] = 0x5c8;
        cmdWrite[iVar33 + 0x11] = 0x20000;
        cmdWordsLeft = (cmdWordsLeft - 6) - (iVar33 + 0x12);
        rectEntry = rectEntry + 4;
        cmdWrite = cmdWrite + iVar33 + 0x12;
        local_d0 = local_d0 + 1;
        uStack_124 = dstLeft;
        uStack_11c = dstRight;
        uStack_114 = dstTop;
        uStack_10c = uVar16;
      } while (local_d0 < puStack00000028[0x16]);
    }
    uVar7 = 0;
    *(dword **)(accel + 0x80) = cmdWrite;
  }
  return uVar7;
}

/* _radeonSolidScanlines @ 0xba90 (3660 bytes) */
int _radeonSolidScanlines(accel, unusedArg2, unusedArg3, blitFlags, scanReq, packedColor)
  int accel;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  uint blitFlags;
  undefined4 *scanReq;
  undefined4 packedColor;
{
  float fVar1;
  float fVar2;
  float fVar3;
  char *pcVar4;
  bool bVar5;
  undefined *taskPtr;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  float *pfVar11;
  dword *cmdPtrPlus44Or3Block1;
  int iVar13;
  dword *pdVar14;
  dword *cmdPtrPlus6Block2;
  segment_command *psVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  dword *pdVar20;
  int idxPlus3Block3;
  float fVar22;
  dword *pdVar23;
  uint *lastHeader;
  float *pfVar25;
  dword *pdVar26;
  int idxPlus1Block3;
  float fVar28;
  uint cmdCapacity;
  int idxPlus2Block3;
  dword *cmdPtrPlus40Or2Block1;
  uint dstTop;
  uint uVar33;
  uint cmdWordsLeft;
  uint dstBottom;
  uint dstLeft;
  uint dstRight;
  dword *pdVar38;
  dword *cmdWrite;
  undefined4 *puVar40;
  dword *pdVar41;
  uint scratchWord0;
  uint scratchWord1;
  float local_19c;
  undefined4 i2dHi1;
  int iStack_174;
  undefined4 i2dHi2;
  int iStack_16c;
  undefined4 i2dHi3;
  int iStack_164;
  undefined4 i2dHi4;
  int iStack_15c;
  undefined4 i2dHi5;
  uint i2dLo1;
  undefined4 i2dHi6;
  uint i2dLo2;
  undefined4 i2dHi7;
  uint i2dLo3;
  undefined4 i2dHi8;
  uint i2dLo4;
  undefined4 i2dHi9;
  uint i2dLo5;
  undefined4 i2dHi10;
  uint i2dLo6;
  undefined4 i2dHi11;
  uint i2dLo7;
  undefined4 i2dHi12;
  uint i2dLo8;
  uint local_118;
  uint idxPlus8Block4;
  uint local_110;
  undefined4 *scanEntry;
  uint local_108;
  int local_104;
  uint local_100;
  int local_fc;
  undefined4 flushWaitWord;
  uint dstLeftMasked;
  uint dstRightMasked;
  dword local_ec;
  int local_e8;
  uint local_e4;
  uint local_e0;
  int local_dc;
  
  if ((blitFlags & 0x7ffff000) == 0x6000) {
    puVar40 = *(undefined4 **)(accel + 0x80);
    cmdCapacity = *(uint *)(accel + 0x18);
    if (puVar40 != (undefined4 *)0x0) {
      if ((uint)((*(int *)(cmdCapacity + 0x10) + -7) - ((int)((int)puVar40 - (cmdCapacity + 0x20)) >> 2)) <
          scanReq[0x16] * 0xc + 0x6eU) {
        scratchWord1 = 0;
        if (*(int *)(accel + 0x8c) == 0) {
          *puVar40 = 0x5c8;
          scratchWord1 = 2;
          puVar40[1] = 0xc000;
          *(undefined4 *)(accel + 0x94) = 0;
        }
        puVar40[scratchWord1] = 0x1000000;
        taskPtr = PTR_0000e694;
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = ((int)puVar40 - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
        scratchWord0 = cmdCapacity;
        iVar10 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                     &scratchWord0,&scratchWord1,1);
        if (iVar10 == 0) {
          *(undefined4 *)(scratchWord0 + 0x1c) = 0;
          *(uint *)(accel + 0x18) = scratchWord0;
          puVar40 = (undefined4 *)(scratchWord0 + 0x20);
          *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
        }
        else {
          puVar40 = (undefined4 *)0x0;
          *(undefined4 *)(accel + 0x7c) = 0;
          *(undefined4 *)(accel + 0x18) = 0;
        }
      }
      iVar10 = ((int (*)())_radeon3DFillSetup)(puVar40,0,packedColor,accel);
      iVar18 = scanReq[0x16];
      lastHeader = puVar40 + iVar10;
      *lastHeader = iVar18 * 0xc0000 | 0xc0003500;
      pfVar11 = (float *)(lastHeader + 2);
      lastHeader[1] = iVar18 << 0x12 | 0x3d;
      cmdCapacity = scanReq[0x17] + *(int *)(accel + 100);
      fVar1 = (float)((double)CONCAT44(0x43300000,cmdCapacity ^ 0x80000000) - 4503601774854144.0);
      fVar2 = (float)((double)CONCAT44(0x43300000,cmdCapacity + scanReq[0x18] ^ 0x80000000) -
                     4503601774854144.0);
      if (iVar18 != 0) {
        iVar10 = *(int *)(accel + 0x60);
        if (iVar18 == 0) {
          iVar18 = 1;
        }
        do {
          fVar28 = (float)((double)CONCAT44(0x43300000,scanReq[0x19] + iVar10 ^ 0x80000000) -
                          4503601774854144.0);
          fVar22 = (float)((double)CONCAT44(0x43300000,scanReq[0x1a] + iVar10 ^ 0x80000000) -
                          4503601774854144.0);
          *pfVar11 = fVar28;
          pfVar11[1] = fVar2;
          pfVar11[2] = 0.0;
          pfVar11[3] = fVar28;
          pfVar11[4] = fVar1;
          pfVar11[5] = 0.0;
          pfVar11[6] = fVar22;
          pfVar11[7] = fVar1;
          pfVar11[8] = 0.0;
          pfVar11[9] = fVar22;
          pfVar11[10] = fVar2;
          pfVar25 = pfVar11 + 0xb;
          pfVar11 = pfVar11 + 0xc;
          *pfVar25 = 0.0;
          scanReq = scanReq + 2;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
      }
      *pfVar11 = 7.02191e-42;
      pfVar11[1] = 1.4013e-44;
      pfVar11[2] = 2.07392e-42;
      pfVar11[3] = 1.83671e-40;
      *(float **)(accel + 0x80) = pfVar11 + 4;
      return 0;
    }
  }
  else {
    cmdWrite = *(dword **)(accel + 0x80);
    iVar10 = *(int *)(accel + 0x18);
    cmdCapacity = *(int *)(iVar10 + 0x10) - 7;
    if ((cmdWrite != (dword *)0x0) &&
       (iVar18 = ((int (*)())_createTextureBuffer)(accel,0x40,0x40,(uint)(*(int *)(accel + 0x70) == 3)),
       iVar18 != 0)) {
      local_e8 = 0xbaa4;
      cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (iVar10 + 0x20) >> 2);
      _fillTextureWithPattern(packedColor,blitFlags & 0x7ffff000,*scanReq,scanReq[1]);
      iVar10 = *(int *)(((unsigned char *)0x00002ca4) + local_e8);
      local_104 = *(int *)(iVar10 + 0x30);
      if (local_104 == 3) {
        local_104 = 0xb;
      }
      else if (local_104 == 6) {
        local_104 = 0xc;
      }
      uVar19 = scanReq[0x16];
      i2dHi1 = 0x43300000;
      dstTop = scanReq[0x17] + *(int *)(accel + 100);
      iStack_174 = (dstTop & 7) + scanReq[3];
      dstBottom = dstTop + scanReq[0x18];
      fVar1 = (float)((double)CONCAT44(0x43300000,iStack_174) - 4503599627370496.0);
      if (uVar19 != 0) {
        local_118 = dstBottom;
        if (dstTop + 8 < dstBottom) {
          local_118 = dstTop + 8;
        }
        bVar5 = true;
        local_100 = 0;
        scanEntry = scanReq;
        do {
          i2dHi2 = 0x43300000;
          dstLeft = *(int *)(accel + 0x60) + scanEntry[0x19];
          iStack_16c = (dstLeft & 7) + scanReq[2];
          dstRight = *(int *)(accel + 0x60) + scanEntry[0x1a];
          fVar2 = (float)((double)CONCAT44(0x43300000,iStack_16c) - 4503599627370496.0);
          if (dstTop < dstBottom) {
            idxPlus8Block4 = dstLeft + 8;
            local_108 = dstRight;
            if (idxPlus8Block4 < dstRight) {
              local_108 = idxPlus8Block4;
            }
            dstLeftMasked = dstLeft & 0x1fff;
            dstRightMasked = dstRight & 0x1fff;
            flushWaitWord = 0xc000;
            local_ec = 0x4003d;
            local_fc = 1;
            uVar19 = dstTop;
            uVar7 = local_118;
            do {
              if (dstLeft < dstRight) {
                uVar9 = dstLeft;
                uVar33 = local_108;
                if (!bVar5) {
                  local_e4 = uVar7 << 0x10;
                  local_e0 = uVar19 << 0x10;
                  local_dc = uVar7 - uVar19;
                  uVar7 = idxPlus8Block4;
                  goto LAB_0000c1c8;
                }
                if (cmdWordsLeft < 0x8e) {
                  scratchWord0 = *(uint *)(accel + 0x18);
                  scratchWord1 = 0;
                  if (*(int *)(accel + 0x8c) == 0) {
                    *cmdWrite = 0x5c8;
                    scratchWord1 = 2;
                    cmdWrite[1] = flushWaitWord;
                    *(undefined4 *)(accel + 0x94) = 0;
                  }
                  cmdWrite[scratchWord1] = 0x1000000;
                  taskPtr = PTR_0000e694;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
                  iVar18 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord0,&scratchWord1,1);
                  uVar33 = local_108;
                  if (iVar18 == 0) {
                    local_e4 = uVar7 << 0x10;
                    local_e0 = uVar19 << 0x10;
                    local_dc = uVar7 - uVar19;
                    *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                    cmdWrite = (dword *)(scratchWord0 + 0x20);
                    local_110 = idxPlus8Block4;
                    *(uint *)(accel + 0x18) = scratchWord0;
                    pdVar41 = (dword *)(scratchWord0 + 0x48);
                    *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                    pdVar38 = (dword *)(scratchWord0 + 0x24);
                    cmdPtrPlus40Or2Block1 = (dword *)(scratchWord0 + 0x28);
                    cmdPtrPlus44Or3Block1 = (dword *)(scratchWord0 + 0x2c);
                    pdVar26 = (dword *)(scratchWord0 + 0x30);
                    pdVar14 = (dword *)(scratchWord0 + 0x34);
                    cmdPtrPlus6Block2 = (dword *)(scratchWord0 + 0x38);
                    psVar16 = (segment_command *)(scratchWord0 + 0x3c);
                    pdVar20 = (dword *)(scratchWord0 + 0x40);
                    pdVar23 = (dword *)(scratchWord0 + 0x44);
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    local_e4 = uVar7 << 0x10;
                    local_dc = uVar7 - uVar19;
                    local_e0 = uVar19 << 0x10;
                    local_110 = idxPlus8Block4;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdWrite = (dword *)0x0;
                    pdVar38 = &__mh_bundle_header.cputype;
                    cmdPtrPlus40Or2Block1 = &__mh_bundle_header.cpusubtype;
                    cmdPtrPlus44Or3Block1 = &__mh_bundle_header.filetype;
                    pdVar26 = &__mh_bundle_header.ncmds;
                    pdVar14 = &__mh_bundle_header.sizeofcmds;
                    cmdPtrPlus6Block2 = &__mh_bundle_header.flags;
                    psVar16 = &(*(GhidraMachOCommand *)0x0000001c);
                    pdVar20 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    pdVar23 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar41 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    cmdWordsLeft = cmdCapacity;
                  }
                }
                else {
                  local_e4 = uVar7 << 0x10;
                  local_e0 = uVar19 << 0x10;
                  local_dc = uVar7 - uVar19;
                  pdVar38 = cmdWrite + 1;
                  cmdPtrPlus40Or2Block1 = cmdWrite + 2;
                  cmdPtrPlus44Or3Block1 = cmdWrite + 3;
                  local_110 = idxPlus8Block4;
                  pdVar26 = cmdWrite + 4;
                  pdVar14 = cmdWrite + 5;
                  cmdPtrPlus6Block2 = cmdWrite + 6;
                  psVar16 = (segment_command *)(cmdWrite + 7);
                  pdVar20 = cmdWrite + 8;
                  pdVar23 = cmdWrite + 9;
                  pdVar41 = cmdWrite + 10;
                }
                do {
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = cmdWrite;
                  *cmdWrite = 0x11000000;
                  *pdVar38 = *(dword *)(accel + 0x84);
                  *cmdPtrPlus40Or2Block1 = 0;
                  *cmdPtrPlus44Or3Block1 = 0;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)pdVar26 - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = pdVar26;
                  *pdVar26 = 0x8000000;
                  *pdVar14 = *(dword *)**(undefined4 **)(((unsigned char *)0x00002ca4) + local_e8);
                  *cmdPtrPlus6Block2 = 0;
                  psVar16->cmd = 0;
                  *pdVar20 = 0;
                  *pdVar23 = 0;
                  cmdWordsLeft = cmdWordsLeft - 10;
                  iVar13 = ((int (*)())_radeon3DCopySetup)(accel,pdVar41,iVar10 + 0xc,local_104,0,0,0,0);
                  iVar18 = iVar13 << 2;
                  idxPlus1Block3 = iVar13 + 1;
                  idxPlus2Block3 = iVar13 + 2;
                  idxPlus3Block3 = iVar13 + 3;
                  iVar17 = iVar13 + 4;
                  cmdWrite = pdVar41;
                  while( true ) {
                    if (local_fc != 0) {
                      pcVar4 = (char *)((int)cmdWrite + iVar18);
                      pcVar4[0] = '\0';
                      pcVar4[1] = '\0';
                      pcVar4[2] = '\x10';
                      pcVar4[3] = -8;
                      cmdWrite[idxPlus1Block3] = dstLeftMasked | dstTop * 0x2000 & 0x3ffe000;
                      cmdWrite[idxPlus2Block3] = 0x10f9;
                      cmdWrite[idxPlus3Block3] = dstRightMasked | dstBottom * 0x2000 & 0x3ffe000;
                      iVar18 = iVar17 << 2;
                      idxPlus1Block3 = iVar17 + 1;
                      idxPlus2Block3 = iVar17 + 2;
                      local_fc = 0;
                      idxPlus3Block3 = iVar17 + 3;
                      iVar13 = iVar17;
                      iVar17 = iVar17 + 4;
                    }
                    iVar8 = uVar33 - uVar9;
                    if ((iVar8 == 8) && (local_dc == 8)) {
                      pcVar4 = (char *)((int)cmdWrite + iVar18);
                      pcVar4[0] = -0x40;
                      pcVar4[1] = '\f';
                      pcVar4[2] = '5';
                      pcVar4[3] = '\0';
                      cmdWrite[idxPlus1Block3] = local_ec;
                      i2dHi9 = 0x43300000;
                      i2dLo5 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar3 = (float)((double)(fVar2 + 0.0) *
                                     (1.0 / ((double)CONCAT44(0x43300000,i2dLo5) -
                                            4503601774854144.0)));
                      i2dHi10 = 0x43300000;
                      i2dLo6 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar28 = (float)((double)(fVar2 + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo6) -
                                             4503601774854144.0)));
                      i2dHi11 = 0x43300000;
                      i2dLo7 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      scratchWord0 = (uint)GH_F2U((float)((double)(fVar1 + 0.0) *
                                               (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                                      4503601774854144.0))));
                      i2dHi12 = 0x43300000;
                      i2dLo8 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      fVar22 = (float)((double)(fVar1 + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) -
                                             4503601774854144.0)));
                      cmdWrite[idxPlus2Block3] = uVar9 | local_e4;
                      cmdWrite[idxPlus3Block3] = (dword)GH_F2U(fVar3);
                      cmdWrite[iVar17] = (dword)GH_F2U(fVar22);
                      cmdWrite[iVar13 + 5] = uVar9 | local_e0;
                      cmdWrite[iVar13 + 6] = (dword)GH_F2U(fVar3);
                      cmdWrite[iVar13 + 7] = scratchWord0;
                      cmdWrite[iVar13 + 8] = uVar33 | local_e0;
                      scratchWord1 = (uint)GH_F2U(fVar28);
                      local_19c = fVar22;
                    }
                    else {
                      i2dHi3 = 0x43300000;
                      i2dHi4 = 0x43300000;
                      iStack_15c = local_dc;
                      pcVar4 = (char *)((int)cmdWrite + iVar18);
                      pcVar4[0] = -0x40;
                      pcVar4[1] = '\f';
                      pcVar4[2] = '5';
                      pcVar4[3] = '\0';
                      cmdWrite[idxPlus1Block3] = local_ec;
                      i2dHi5 = 0x43300000;
                      i2dLo1 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      local_19c = (float)((double)(fVar2 + 0.0) *
                                         (1.0 / ((double)CONCAT44(0x43300000,i2dLo1) -
                                                4503601774854144.0)));
                      i2dHi6 = 0x43300000;
                      i2dLo2 = (int)*(short *)(iVar10 + 0x10) ^ 0x80000000;
                      fVar28 = (float)((double)(fVar2 + (float)((double)CONCAT44(0x43300000,iVar8) -
                                                               4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo2) -
                                             4503601774854144.0)));
                      i2dHi7 = 0x43300000;
                      i2dLo3 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      scratchWord0 = (uint)GH_F2U((float)((double)(fVar1 + 0.0) *
                                               (1.0 / ((double)CONCAT44(0x43300000,i2dLo3) -
                                                      4503601774854144.0))));
                      i2dHi8 = 0x43300000;
                      i2dLo4 = (int)*(short *)(iVar10 + 0x12) ^ 0x80000000;
                      fVar22 = (float)((double)(fVar1 + (float)((double)CONCAT44(0x43300000,local_dc
                                                                                ) -
                                                               4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo4) -
                                             4503601774854144.0)));
                      cmdWrite[idxPlus2Block3] = local_e4 | uVar9;
                      cmdWrite[idxPlus3Block3] = (dword)GH_F2U(local_19c);
                      cmdWrite[iVar17] = (dword)GH_F2U(fVar22);
                      cmdWrite[iVar13 + 5] = local_e0 | uVar9;
                      cmdWrite[iVar13 + 6] = (dword)GH_F2U(local_19c);
                      cmdWrite[iVar13 + 7] = scratchWord0;
                      cmdWrite[iVar13 + 8] = local_e0 | uVar33;
                      scratchWord1 = (uint)GH_F2U(fVar22);
                      iStack_164 = iVar8;
                    }
                    cmdWrite[iVar13 + 9] = (dword)GH_F2U(fVar28);
                    cmdWrite[iVar13 + 10] = scratchWord0;
                    cmdWrite[iVar13 + 0xb] = uVar33 | local_e4;
                    cmdWrite[iVar13 + 0xc] = (dword)GH_F2U(fVar28);
                    cmdWrite[iVar13 + 0xd] = (dword)GH_F2U(fVar22);
                    cmdWrite[iVar13 + 0xe] = 0x1393;
                    cmdWrite[iVar13 + 0xf] = 10;
                    cmdWrite[iVar13 + 0x10] = 0x5c8;
                    cmdWrite[iVar13 + 0x11] = 0x20000;
                    cmdWordsLeft = cmdWordsLeft - (iVar13 + 0x12);
                    cmdWrite = cmdWrite + iVar13 + 0x12;
                    uVar33 = dstRight;
                    if (uVar9 + 0x10 < dstRight) {
                      uVar33 = uVar9 + 0x10;
                    }
                    bVar5 = false;
                    if (dstRight <= local_110) goto LAB_0000c820;
                    uVar7 = local_110 + 8;
                    uVar9 = local_110;
LAB_0000c1c8:
                    if (cmdWordsLeft < 0x16) break;
                    iVar17 = 4;
                    idxPlus3Block3 = 3;
                    idxPlus2Block3 = 2;
                    idxPlus1Block3 = 1;
                    iVar18 = 0;
                    iVar13 = 0;
                    local_110 = uVar7;
                  }
                  scratchWord1 = *(uint *)(accel + 0x18);
                  scratchWord0 = 0;
                  if (*(int *)(accel + 0x8c) == 0) {
                    *cmdWrite = 0x5c8;
                    scratchWord0 = 2;
                    cmdWrite[1] = flushWaitWord;
                    *(undefined4 *)(accel + 0x94) = 0;
                  }
                  cmdWrite[scratchWord0] = 0x1000000;
                  taskPtr = PTR_0000e694;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
                  iVar18 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord1,&scratchWord0,1);
                  if (iVar18 == 0) {
                    local_110 = uVar9 + 8;
                    local_fc = 1;
                    *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                    *(uint *)(accel + 0x18) = scratchWord1;
                    cmdWrite = (dword *)(scratchWord1 + 0x20);
                    pdVar41 = (dword *)(scratchWord1 + 0x48);
                    *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                    pdVar38 = (dword *)(scratchWord1 + 0x24);
                    cmdPtrPlus40Or2Block1 = (dword *)(scratchWord1 + 0x28);
                    cmdPtrPlus44Or3Block1 = (dword *)(scratchWord1 + 0x2c);
                    pdVar26 = (dword *)(scratchWord1 + 0x30);
                    pdVar14 = (dword *)(scratchWord1 + 0x34);
                    cmdPtrPlus6Block2 = (dword *)(scratchWord1 + 0x38);
                    psVar16 = (segment_command *)(scratchWord1 + 0x3c);
                    pdVar20 = (dword *)(scratchWord1 + 0x40);
                    pdVar23 = (dword *)(scratchWord1 + 0x44);
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    local_110 = uVar9 + 8;
                    pdVar41 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    pdVar23 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    pdVar20 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    psVar16 = &(*(GhidraMachOCommand *)0x0000001c);
                    local_fc = 1;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdPtrPlus6Block2 = &__mh_bundle_header.flags;
                    pdVar14 = &__mh_bundle_header.sizeofcmds;
                    pdVar26 = &__mh_bundle_header.ncmds;
                    cmdPtrPlus44Or3Block1 = &__mh_bundle_header.filetype;
                    cmdPtrPlus40Or2Block1 = &__mh_bundle_header.cpusubtype;
                    pdVar38 = &__mh_bundle_header.cputype;
                    cmdWrite = (dword *)0x0;
                    cmdWordsLeft = cmdCapacity;
                  }
                } while( true );
              }
LAB_0000c820:
              uVar9 = uVar19 + 0x10;
              uVar19 = uVar19 + 8;
              uVar7 = dstBottom;
              if (uVar9 < dstBottom) {
                uVar7 = uVar9;
              }
            } while (uVar19 < dstBottom);
            uVar19 = scanReq[0x16];
          }
          local_100 = local_100 + 1;
          scanEntry = scanEntry + 2;
        } while (local_100 < uVar19);
      }
      *(dword **)(accel + 0x80) = cmdWrite;
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

