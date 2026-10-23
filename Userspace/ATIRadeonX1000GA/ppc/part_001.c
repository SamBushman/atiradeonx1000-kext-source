#include "decls.h"

/* __AllocateSurface @ 0x2750 (1420 bytes) */
int __AllocateSurface(accel, flags, surfaceDesc, vramAddress)
  int accel;
  uint flags;
  uint *surfaceDesc;
  undefined4 vramAddress;
{
  int repeatCount;
  uint tiledHeight;
  uint tiledWidth;
  uint tiledPitch;
  uint descWidthPx;
  uint descPitch;
  uint repeatRows;
  uint repeatHeight;
  uint dataDwords;
  uint descHeight;
  uint srcPitch;
  uint descWidth;
  undefined4 *record;
  int status;
  uint width;
  uint paddedRowBytes;
  int hwTileMode;
  int repeatIndex;
  uint rowBytes;
  uint srcNext;
  uint srcRow;
  uint bytesPerPixel;
  uint rowIndex;
  int *cmdCursor;
  uint tiledFormatCode;
  int outCount;
  uint formatCode;
  int *scalarOut0;
  undefined4 scalarOut1;
  uint scalarIn0;
  uint scalarIn1;
  uint scalarIn2;
  uint alignedPitch;
  
  record = (undefined4 *)_calloc(1,0x3c);
  if ((flags & 1) == 0) {
    if ((flags & 8) == 0) {
      status = __DecodePixelFormat(surfaceDesc[1],record + 0xc,record + 0xd,record + 10,&formatCode,
                                  record + 0xb,0,record + 0xe);
      if (status == 0) goto LAB_00002cb0;
      srcPitch = surfaceDesc[6];
      bytesPerPixel = record[10];
      repeatCount = 1;
      *(undefined2 *)((int)record + 0xe) = 0;
      *(undefined2 *)(record + 3) = 0;
      record[7] = srcPitch / bytesPerPixel;
      descWidth = surfaceDesc[4];
      *(short *)(record + 4) = (short)descWidth;
      descHeight = surfaceDesc[5];
      record[5] = descWidth;
      *(short *)((int)record + 0x12) = (short)descHeight;
      record[6] = descHeight;
      dataDwords = bytesPerPixel * descWidth * descHeight + 3;
      scalarIn1 = (dataDwords & 0xfffffffc) + 0xfff & 0xfffff000;
      for (dataDwords = dataDwords >> 2; 0x3fff < dataDwords; dataDwords = dataDwords >> 1) {
        repeatCount = repeatCount << 1;
      }
      outCount = 2;
      scalarIn0 = ((dataDwords + 0xd) * repeatCount + 0x27) * 4 & 0xffffffe0;
      status = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(accel + 0xc),9,&scalarIn0,2,&scalarOut0,&outCount);
      if (status == 0) {
        *record = scalarOut1;
        width = surfaceDesc[4];
        repeatHeight = surfaceDesc[5];
        srcNext = *surfaceDesc;
        rowBytes = bytesPerPixel * width;
        dataDwords = bytesPerPixel * width * repeatHeight >> 2;
        repeatRows = repeatHeight;
        if (dataDwords < 0x4000) {
          repeatCount = 1;
        }
        else {
          repeatCount = 1;
          do {
            dataDwords = dataDwords >> 1;
            repeatHeight = repeatHeight >> 1;
            repeatRows = repeatRows >> 1;
            repeatCount = repeatCount << 1;
          } while (0x3fff < dataDwords);
        }
        paddedRowBytes = 0x20;
        if (0x1f < rowBytes) {
          paddedRowBytes = rowBytes;
        }
        *scalarOut0 = (dataDwords + 0xd) * repeatCount + 8;
        scalarOut0[6] = dataDwords + 0xd;
        scalarOut0[7] = repeatCount;
        scalarOut0[5] = paddedRowBytes * repeatHeight;
        scalarOut0[0x20] = 0x1393;
        scalarOut0[0x21] = 10;
        scalarOut0[0x22] = 0x5c8;
        cmdCursor = scalarOut0 + 0x24;
        scalarOut0[0x23] = 0x20000;
        hwTileMode = 3;
        if (formatCode != 3) {
          hwTileMode = 0;
        }
        if (repeatCount != 0) {
          repeatIndex = 0;
          do {
            *cmdCursor = 0x5cb;
            cmdCursor[1] = hwTileMode;
            cmdCursor[2] = 0x51b;
            cmdCursor[3] = (formatCode & 0xf) << 8 | 0x53cc30f2;
            cmdCursor[4] = 0x10501;
            cmdCursor[5] = 0;
            cmdCursor[6] = paddedRowBytes;
            cmdCursor[7] = 0x5c0;
            cmdCursor[8] = 0;
            cmdCursor[9] = 0x1050e;
            cmdCursor[10] = 0;
            cmdCursor[0xb] = width | repeatHeight << 0x10;
            cmdCursor[0xc] = (dataDwords - 1) * 0x10000 | 0x85f0;
            cmdCursor = cmdCursor + 0xd;
            if (repeatRows != 0) {
              rowIndex = 0;
              srcRow = srcNext;
              do {
                rowIndex = rowIndex + 1;
                srcNext = srcRow + rowBytes;
                _bcopy(srcRow,cmdCursor,rowBytes);
                cmdCursor = (int *)((int)cmdCursor + (rowBytes & 0xfffffffc));
                srcRow = srcNext;
              } while (rowIndex != repeatRows);
            }
            repeatIndex = repeatIndex + 1;
          } while (repeatCount != repeatIndex);
        }
        *cmdCursor = 0xd0b;
        cmdCursor[1] = 5;
        cmdCursor[2] = 0x5c8;
        cmdCursor[3] = 0x10000;
        status = 0;
        goto LAB_00002ce0;
      }
    }
    else if (((surfaceDesc[6] & 0x3f) == 0) &&
            (status = __DecodePixelFormat(surfaceDesc[1],record + 0xc,record + 0xd,record + 10,0,
                                         record + 0xb,0,record + 0xe), status != 0)) {
      descPitch = surfaceDesc[6];
      *(undefined2 *)((int)record + 0xe) = 0;
      *(undefined2 *)(record + 3) = 0;
      record[7] = descPitch / (uint)record[10];
      descWidthPx = surfaceDesc[4];
      *(short *)(record + 4) = (short)descWidthPx;
      scalarIn2 = surfaceDesc[5];
      record[5] = descWidthPx;
      *(short *)((int)record + 0x12) = (short)scalarIn2;
      record[6] = scalarIn2;
      outCount = 1;
      scalarIn2 = scalarIn2 * descPitch;
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
        alignedPitch = surfaceDesc[4] * record[10] + 0x7f & 0xffffff80;
        scalarIn1 = (surfaceDesc[5] + 1) * alignedPitch;
        surfaceDesc[6] = alignedPitch;
        scalarIn0 = tiledFormatCode;
        outCount = 2;
        status = _io_connect_method_scalarI_scalarO
                          (*(undefined4 *)(accel + 0xc),10,&scalarIn0,2,&scalarOut0,&outCount);
        if (status == 0) {
          status = 0;
          *record = scalarOut1;
          tiledPitch = surfaceDesc[6];
          *(undefined2 *)((int)record + 0xe) = 0;
          *(undefined2 *)(record + 3) = 0;
          record[7] = tiledPitch / (uint)record[10];
          tiledWidth = surfaceDesc[4];
          *(short *)(record + 4) = (short)tiledWidth;
          tiledHeight = surfaceDesc[5];
          record[5] = tiledWidth;
          *(short *)((int)record + 0x12) = (short)tiledHeight;
          record[6] = tiledHeight;
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
  int padWordsOrMapSize;
  int newCmdWriteAddr;
  int mapResult;
  undefined *taskPtr;
  int accel8cState;
  uint *lastHeader;
  undefined4 *cmdWrite;
  int mapAddr [6];
  
  cmdWrite = *(undefined4 **)(accel + 0x80);
  if (cmdWrite != (undefined4 *)(*(int *)(accel + 0x18) + 0x20)) {
    if ((flushFlags & 0x10000) == 0) {
      accel8cState = *(int *)(accel + 0x8c);
    }
    else {
      accel8cState = 0;
      if (*(int *)(accel + 0x8c) != 0) {
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(accel + 0x7c) = cmdWrite;
        *cmdWrite = 0x2000000;
        cmdWrite = cmdWrite + 1;
        accel8cState = *(int *)(accel + 0x8c);
      }
    }
    mapAddr[0] = *(int *)(accel + 0x18);
    padWordsOrMapSize = 0;
    if (accel8cState == 0) {
      *cmdWrite = 0x5c8;
      padWordsOrMapSize = 2;
      cmdWrite[1] = 0xc000;
      *(undefined4 *)(accel + 0x94) = 0;
    }
    cmdWrite[padWordsOrMapSize] = 0x1000000;
    taskPtr = PTR_0000e694;
    lastHeader = *(uint **)(accel + 0x7c);
    *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + padWordsOrMapSize | *lastHeader;
    mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,mapAddr,
                                &padWordsOrMapSize,1);
    if (mapResult == 0) {
      *(undefined4 *)(mapAddr[0] + 0x1c) = 0;
      *(int *)(accel + 0x18) = mapAddr[0];
      newCmdWriteAddr = mapAddr[0] + 0x20;
      *(int *)(accel + 0x7c) = mapAddr[0] + 0x1c;
    }
    else {
      newCmdWriteAddr = 0;
      *(undefined4 *)(accel + 0x7c) = 0;
      *(undefined4 *)(accel + 0x18) = 0;
    }
    *(int *)(accel + 0x80) = newCmdWriteAddr;
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
  int pass2QuadFlushRegIdx;
  int pass2QuadDrawRegValueIdx;
  int pass2QuadDrawRegIdx;
  int pass2QuadVtx3VIdx;
  int pass2QuadVtx3UIdx;
  int pass2QuadVtx3PosIdx;
  int pass2QuadVtx2VIdx;
  int pass2QuadVtx2UIdx;
  int pass2QuadVtx2PosIdx;
  int pass2QuadVtx1VIdx;
  int pass2QuadVtx0VIdx;
  int pass2QuadVtx0UIdx;
  int pass2QuadVtx0PosIdx;
  int pass2QuadVertexFormatIdx;
  int pass2QuadPacketWordsIdx;
  int pass2QuadVtx1UIdx;
  int pass2QuadVtx1PosIdx;
  double invSrcHeight;
  double invSrcWidth;
  short offscreenWidth;
  uint dstBottomHi;
  bool needsSetup;
  undefined *taskPtr;
  uint *lastHeader;
  int pass1QuadPacketWordsIdx;
  dword *cmdPtrPlus36Or1Block2;
  int pass1QuadRectTLIdx;
  int pass1QuadVtx0PosIdx;
  dword texWord1;
  int pass1QuadRectBRRegIdx;
  int pass1QuadVtx0VIdx;
  int pass1QuadVtx0UIdx;
  dword texWord2;
  dword texWord3;
  int pass1QuadDrawHeaderIdx;
  int pass1QuadVtx1PosIdx;
  int pass1QuadVtx1UIdx;
  int pass1QuadVtx1VIdx;
  int pass1QuadVtx2PosIdx;
  int pass1QuadVtx2UIdx;
  int pass1QuadVtx2VIdx;
  int pass1QuadVtx3PosIdx;
  int pass1QuadVtx3UIdx;
  int pass1QuadVtx3VIdx;
  int pass1QuadDrawRegIdx;
  uint dstRight;
  int pass1QuadDrawRegValueIdx;
  uint dstX;
  int rectCount;
  uint cmdWordsLeft;
  uint cmdCapacity;
  dword *cmdWrite;
  int pass1QuadRectBRIdx;
  double srcLeftExact;
  double srcBottomExact;
  double srcTopExact;
  double srcRightExact;
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
  int pass2QuadDrawHeaderIdx;
  int pass2QuadRectBRIdx;
  int pass2QuadRectBRRegIdx;
  int pass2QuadRectTLIdx;
  uint srcBottomInt;
  uint srcRightInt;
  uint srcTopInt;
  uint srcLeftInt;
  uint offscreenFormat;
  uint screenFormat;
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
  int createResult;
  int mapResult;
  int pass1RegByteOffset;
  int rectHeight;
  int pass1SetupWords;
  int dstY;
  int pass1Idx20;
  int mapResultPass2;
  int pass2RegByteOffset;
  int offscreenHeightM1;
  int pass1Idx5;
  int pass2SetupWords;
  dword *streamCursor;
  dword *pass1Word2;
  dword *pass1Word3;
  dword *pass1Word4;
  dword *pass1Word5;
  dword *pass2Word2;
  dword *pass2Word3;
  dword *pass2Word4;
  dword *pass2Word5;
  int rectIndex;
  
  cmdWrite = *(dword **)(accel + 0x80);
  rectCount = *(int *)(blitReq + 0x58);
  cmdCapacity = *(int *)(*(int *)(accel + 0x18) + 0x10) - 7;
  if (cmdWrite != (dword *)0x0) {
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (*(int *)(accel + 0x18) + 0x20) >> 2);
    if ((0x1000 < *(short *)(accel + 0x50)) || (0x1000 < *(short *)(accel + 0x52))) {
      return 0xe00002c7;
    }
    createResult = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,0);
    if (createResult != 0) {
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
        rectIndex = 0;
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
          srcBottomExact = srcTopFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo4) -
                                           4503601774854144.0);
          srcBottomFloat = (double)(float)srcBottomExact;
          srcRightExact = srcLeftFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo3) -
                                           4503601774854144.0);
          srcRightFloat = (double)(float)srcRightExact;
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
            srcRightInt = (uint)(int)srcRightExact;
            d2iScratch5 = (longlong)(int)srcRightInt;
          }
          if (2147483648.0 <= srcBottomFloat) {
            d2iScratch8 = (longlong)(int)(srcBottomFloat - 2147483648.0);
            srcBottomInt = (int)(srcBottomFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcBottomInt = (uint)(int)srcBottomExact;
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
              mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                          *(undefined4 *)PTR_0000e694,scratchWord0Ptr,scratchWord3Ptr,1);
              if (mapResult == 0) {
                needsSetup = true;
                *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord0 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord0;
                streamCursor = (dword *)(scratchWord0 + 0x38);
                cmdPtrPlus36Or1Block2 = (dword *)(scratchWord0 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                pass1Word2 = (dword *)(scratchWord0 + 0x28);
                pass1Word3 = (dword *)(scratchWord0 + 0x2c);
                pass1Word4 = (dword *)(scratchWord0 + 0x30);
                pass1Word5 = (dword *)(scratchWord0 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
LAB_00004b14:
                needsSetup = true;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                cmdWrite = (dword *)0x0;
                cmdPtrPlus36Or1Block2 = &__mh_bundle_header.cputype;
                pass1Word2 = &__mh_bundle_header.cpusubtype;
                pass1Word3 = &__mh_bundle_header.filetype;
                pass1Word4 = &__mh_bundle_header.ncmds;
                pass1Word5 = &__mh_bundle_header.sizeofcmds;
                streamCursor = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              cmdPtrPlus36Or1Block2 = cmdWrite + 1;
              pass1Word2 = cmdWrite + 2;
              pass1Word3 = cmdWrite + 3;
              pass1Word4 = cmdWrite + 4;
              pass1Word5 = cmdWrite + 5;
              streamCursor = cmdWrite + 6;
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
            mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694
                                        ,scratchWord3Ptr,&scratchWord0,1);
            if (mapResult != 0) goto LAB_00004b14;
            needsSetup = true;
            *(undefined4 *)(scratchWord3 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord3;
            cmdWrite = (dword *)(scratchWord3 + 0x20);
            streamCursor = (dword *)(scratchWord3 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
            cmdPtrPlus36Or1Block2 = (dword *)(scratchWord3 + 0x24);
            pass1Word2 = (dword *)(scratchWord3 + 0x28);
            pass1Word3 = (dword *)(scratchWord3 + 0x2c);
            pass1Word4 = (dword *)(scratchWord3 + 0x30);
            pass1Word5 = (dword *)(scratchWord3 + 0x34);
            cmdWordsLeft = cmdCapacity;
          }
          else {
            cmdPtrPlus36Or1Block2 = cmdWrite + 1;
            pass1Word2 = cmdWrite + 2;
            pass1Word3 = cmdWrite + 3;
            pass1Word4 = cmdWrite + 4;
            pass1Word5 = cmdWrite + 5;
            streamCursor = cmdWrite + 6;
            needsSetup = false;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWrite;
          *cmdWrite = 0xe000000;
          *cmdPtrPlus36Or1Block2 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pass1Word2 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pass1Word2;
          *pass1Word2 = 0x10000000;
          *pass1Word3 = *(dword *)*DAT_0000e6e4;
          *pass1Word4 = DAT_0000e6e4[7];
          *pass1Word5 = 6;
          if (needsSetup) {
            pass1SetupWords = ((int (*)())_radeon3DCopySetup)(accel,streamCursor,accel + 0x4c,screenFormat,0,0,0,0);
            screenWidth = *(short *)(accel + 0x50);
            pass1QuadRectTLIdx = pass1SetupWords + 1;
            pass1QuadRectBRRegIdx = pass1SetupWords + 2;
            pass1QuadPacketWordsIdx = pass1SetupWords + 0x16;
            pass1RegByteOffset = pass1SetupWords << 2;
            pass1QuadRectBRIdx = pass1SetupWords + 3;
            pass1QuadDrawHeaderIdx = pass1SetupWords + 4;
            pass1Idx5 = pass1SetupWords + 5;
            pass1QuadVtx0PosIdx = pass1SetupWords + 6;
            pass1QuadVtx0UIdx = pass1SetupWords + 7;
            pass1QuadVtx0VIdx = pass1SetupWords + 8;
            pass1QuadVtx1PosIdx = pass1SetupWords + 9;
            pass1QuadVtx1UIdx = pass1SetupWords + 10;
            pass1QuadVtx1VIdx = pass1SetupWords + 0xb;
            pass1QuadVtx2PosIdx = pass1SetupWords + 0xc;
            pass1QuadVtx2UIdx = pass1SetupWords + 0xd;
            pass1QuadVtx2VIdx = pass1SetupWords + 0xe;
            pass1QuadVtx3PosIdx = pass1SetupWords + 0xf;
            pass1QuadVtx3UIdx = pass1SetupWords + 0x10;
            pass1QuadVtx3VIdx = pass1SetupWords + 0x11;
            pass1QuadDrawRegIdx = pass1SetupWords + 0x12;
            pass1QuadDrawRegValueIdx = pass1SetupWords + 0x13;
            pass1Idx20 = pass1SetupWords + 0x14;
            pass1SetupWords = pass1SetupWords + 0x15;
            screenHeight = *(short *)(accel + 0x52);
          }
          else {
            *streamCursor = 0x1120;
            screenWidth = *(short *)(accel + 0x50);
            screenHeight = *(short *)(accel + 0x52);
            streamCursor[1] = (int)screenWidth - 1U & 0x7ff | (screenHeight + -1) * 0x800 & 0x3ff800U |
                        0x80000000;
            streamCursor[2] = 0x1130;
            streamCursor[3] = colorBufferWord;
            streamCursor[4] = 0x1140;
            streamCursor[5] = *(int *)(accel + 0x5c) - 1U & 0x3fff |
                        ((int)screenWidth - 1U) * 0x10 & 0x8000 | (screenHeight + -1) * 0x20 & 0x10000U;
            pass1RegByteOffset = 0x18;
            pass1QuadRectBRIdx = 9;
            pass1QuadRectTLIdx = 7;
            pass1QuadDrawHeaderIdx = 10;
            pass1Idx5 = 0xb;
            pass1QuadRectBRRegIdx = 8;
            pass1QuadVtx0PosIdx = 0xc;
            pass1QuadVtx0UIdx = 0xd;
            pass1QuadVtx0VIdx = 0xe;
            pass1QuadVtx1PosIdx = 0xf;
            pass1QuadVtx1UIdx = 0x10;
            pass1QuadVtx1VIdx = 0x11;
            pass1QuadVtx2PosIdx = 0x12;
            pass1QuadVtx2UIdx = 0x13;
            pass1QuadVtx2VIdx = 0x14;
            pass1QuadVtx3PosIdx = 0x15;
            pass1QuadVtx3UIdx = 0x16;
            pass1QuadVtx3VIdx = 0x17;
            pass1QuadDrawRegIdx = 0x18;
            pass1QuadDrawRegValueIdx = 0x19;
            pass1Idx20 = 0x1a;
            pass1SetupWords = 0x1b;
            pass1QuadPacketWordsIdx = 0x1c;
          }
          *(undefined4 *)((int)streamCursor + pass1RegByteOffset) = 0x10f8;
          streamCursor[pass1QuadRectTLIdx] = srcLeftInt & 0x1fff | (srcTopInt & 0x1fff) << 0xd;
          streamCursor[pass1QuadRectBRRegIdx] = 0x10f9;
          streamCursor[pass1QuadRectBRIdx] = srcRightInt & 0x1fff | (srcBottomInt & 0x1fff) << 0xd;
          streamCursor[pass1QuadDrawHeaderIdx] = 0xc00c3500;
          streamCursor[pass1Idx5] = 0x4003d;
          i2dLo5 = (int)screenWidth ^ 0x80000000;
          i2dLo6 = (int)screenHeight ^ 0x80000000;
          i2dHi5 = 0x43300000;
          i2dHi6 = 0x43300000;
          invSrcWidth = 1.0 / ((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0);
          invSrcHeight = 1.0 / ((double)CONCAT44(0x43300000,i2dLo6) - 4503601774854144.0);
          scratchWord1 = (uint)GH_F2U((float)(srcRightFloat * invSrcWidth));
          scratchWord3 = (uint)GH_F2U((float)(srcBottomFloat * invSrcHeight));
          scratchWord2 = (uint)GH_F2U((float)(srcLeftFloat * invSrcWidth));
          scratchWord0 = (uint)GH_F2U((float)(srcTopFloat * invSrcHeight));
          streamCursor[pass1QuadVtx0PosIdx] = srcLeftInt | srcBottomInt << 0x10;
          texWord2 = *scratchWord2Ptr;
          streamCursor[pass1QuadVtx0UIdx] = texWord2;
          texWord1 = *scratchWord3Ptr;
          streamCursor[pass1QuadVtx0VIdx] = texWord1;
          streamCursor[pass1QuadVtx1PosIdx] = srcLeftInt | srcTopInt << 0x10;
          streamCursor[pass1QuadVtx1UIdx] = texWord2;
          texWord2 = *scratchWord0Ptr;
          streamCursor[pass1QuadVtx1VIdx] = texWord2;
          streamCursor[pass1QuadVtx2PosIdx] = srcRightInt | srcTopInt << 0x10;
          texWord3 = *scratchWord1Ptr;
          streamCursor[pass1QuadVtx2UIdx] = texWord3;
          streamCursor[pass1QuadVtx2VIdx] = texWord2;
          streamCursor[pass1QuadVtx3PosIdx] = srcRightInt | srcBottomInt << 0x10;
          streamCursor[pass1QuadVtx3UIdx] = texWord3;
          streamCursor[pass1QuadVtx3VIdx] = texWord1;
          streamCursor[pass1QuadDrawRegIdx] = 0x1393;
          streamCursor[pass1QuadDrawRegValueIdx] = 10;
          streamCursor[pass1Idx20] = 0x5c8;
          streamCursor[pass1SetupWords] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - pass1QuadPacketWordsIdx;
          rectHeight = rect[5];
          dstX = rect[2] + *(int *)(accel + 0x60);
          dstY = rect[3] + *(int *)(accel + 100);
          dstRight = dstX + rect[4];
          streamCursor = streamCursor + pass1QuadPacketWordsIdx;
          if (cmdWordsLeft < 0x22) {
            scratchWord1 = *(uint *)(accel + 0x18);
            scratchWord2 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *streamCursor = 0x5c8;
              scratchWord2 = 2;
              streamCursor[1] = flushWaitWord;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            streamCursor[scratchWord2] = 0x1000000;
            taskPtr = PTR_0000e694;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)streamCursor - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
            mapResultPass2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                        scratchWord1Ptr,scratchWord2Ptr,1);
            cmdWordsLeft = cmdCapacity;
            if (mapResultPass2 == 0) {
              needsSetup = true;
              *(undefined4 *)(scratchWord1 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord1;
              streamCursor = (dword *)(scratchWord1 + 0x20);
              cmdWrite = (dword *)(scratchWord1 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
              cmdPtrPlus36Or1Block2 = (dword *)(scratchWord1 + 0x24);
              pass2Word2 = (dword *)(scratchWord1 + 0x28);
              pass2Word3 = (dword *)(scratchWord1 + 0x2c);
              pass2Word4 = (dword *)(scratchWord1 + 0x30);
              pass2Word5 = (dword *)(scratchWord1 + 0x34);
            }
            else {
              needsSetup = true;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              streamCursor = (dword *)0x0;
              cmdPtrPlus36Or1Block2 = &__mh_bundle_header.cputype;
              pass2Word2 = &__mh_bundle_header.cpusubtype;
              pass2Word3 = &__mh_bundle_header.filetype;
              pass2Word4 = &__mh_bundle_header.ncmds;
              pass2Word5 = &__mh_bundle_header.sizeofcmds;
              cmdWrite = &__mh_bundle_header.flags;
            }
          }
          else {
            cmdPtrPlus36Or1Block2 = streamCursor + 1;
            pass2Word2 = streamCursor + 2;
            pass2Word3 = streamCursor + 3;
            pass2Word4 = streamCursor + 4;
            pass2Word5 = streamCursor + 5;
            cmdWrite = streamCursor + 6;
            needsSetup = false;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)streamCursor - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = streamCursor;
          *streamCursor = 0x12000000;
          *cmdPtrPlus36Or1Block2 = 0;
          *pass2Word2 = 0;
          *pass2Word3 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)pass2Word4 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = pass2Word4;
          *pass2Word4 = 0x4000000;
          *pass2Word5 = *(dword *)*DAT_0000e6e4;
          if (needsSetup) {
            pass2SetupWords = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,offscreenDesc,offscreenFormat,0,0,0,0);
            pass2QuadRectTLIdx = pass2SetupWords + 1;
            pass2QuadVtx1PosIdx = pass2SetupWords + 9;
            pass2QuadRectBRIdx = pass2SetupWords + 3;
            pass2QuadDrawHeaderIdx = pass2SetupWords + 4;
            pass2QuadVtx1UIdx = pass2SetupWords + 10;
            pass2QuadRectBRRegIdx = pass2SetupWords + 2;
            pass2QuadPacketWordsIdx = pass2SetupWords + 0x16;
            pass2RegByteOffset = pass2SetupWords << 2;
            pass2QuadVertexFormatIdx = pass2SetupWords + 5;
            pass2QuadVtx0PosIdx = pass2SetupWords + 6;
            pass2QuadVtx0UIdx = pass2SetupWords + 7;
            pass2QuadVtx0VIdx = pass2SetupWords + 8;
            pass2QuadVtx1VIdx = pass2SetupWords + 0xb;
            pass2QuadVtx2PosIdx = pass2SetupWords + 0xc;
            pass2QuadVtx2UIdx = pass2SetupWords + 0xd;
            pass2QuadVtx2VIdx = pass2SetupWords + 0xe;
            pass2QuadVtx3PosIdx = pass2SetupWords + 0xf;
            pass2QuadVtx3UIdx = pass2SetupWords + 0x10;
            pass2QuadVtx3VIdx = pass2SetupWords + 0x11;
            pass2QuadDrawRegIdx = pass2SetupWords + 0x12;
            pass2QuadDrawRegValueIdx = pass2SetupWords + 0x13;
            pass2QuadFlushRegIdx = pass2SetupWords + 0x14;
            pass2SetupWords = pass2SetupWords + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            offscreenWidth = *(short *)(offscreenDesc + 1);
            offscreenHeightM1 = *(short *)((int)offscreenDesc + 6) + -1;
            cmdWrite[1] = (int)offscreenWidth - 1U & 0x7ff | offscreenHeightM1 * 0x800 & 0x3ff800U | 0x80000000;
            cmdWrite[2] = 0x1130;
            cmdWrite[3] = offscreenFormat & 0x1f | 0x53000;
            cmdWrite[4] = 0x1140;
            cmdWrite[5] = offscreenDesc[4] - 1 & 0x3fff | ((int)offscreenWidth - 1U) * 0x10 & 0x8000 |
                         offscreenHeightM1 * 0x20 & 0x10000U;
            pass2QuadDrawHeaderIdx = 10;
            pass2QuadRectBRRegIdx = 8;
            pass2RegByteOffset = 0x18;
            pass2QuadRectBRIdx = 9;
            pass2QuadRectTLIdx = 7;
            pass2QuadVtx1PosIdx = 0xf;
            pass2QuadVertexFormatIdx = 0xb;
            pass2QuadVtx0PosIdx = 0xc;
            pass2QuadVtx0UIdx = 0xd;
            pass2QuadVtx1UIdx = 0x10;
            pass2QuadVtx0VIdx = 0xe;
            pass2QuadVtx1VIdx = 0x11;
            pass2QuadVtx2PosIdx = 0x12;
            pass2QuadVtx2UIdx = 0x13;
            pass2QuadVtx2VIdx = 0x14;
            pass2QuadVtx3PosIdx = 0x15;
            pass2QuadVtx3UIdx = 0x16;
            pass2QuadVtx3VIdx = 0x17;
            pass2QuadDrawRegIdx = 0x18;
            pass2QuadDrawRegValueIdx = 0x19;
            pass2QuadFlushRegIdx = 0x1a;
            pass2SetupWords = 0x1b;
            pass2QuadPacketWordsIdx = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + pass2RegByteOffset) = 0x10f8;
          cmdWrite[pass2QuadRectTLIdx] = dstX & 0x1fff | dstY * 0x2000 & 0x3ffe000U;
          cmdWrite[pass2QuadRectBRRegIdx] = 0x10f9;
          cmdWrite[pass2QuadRectBRIdx] = dstRight & 0x1fff | (dstY + rectHeight) * 0x2000 & 0x3ffe000U;
          cmdWrite[pass2QuadDrawHeaderIdx] = 0xc00c3500;
          cmdWrite[pass2QuadVertexFormatIdx] = 0x4003d;
          dstBottomHi = (dstY + rectHeight) * 0x10000;
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
          cmdWrite[pass2QuadVtx0PosIdx] = dstX | dstBottomHi;
          texWord2 = *scratchWord0Ptr;
          cmdWrite[pass2QuadVtx0UIdx] = texWord2;
          texWord1 = *scratchWord1Ptr;
          cmdWrite[pass2QuadVtx0VIdx] = texWord1;
          cmdWrite[pass2QuadVtx1PosIdx] = dstX | dstY * 0x10000;
          cmdWrite[pass2QuadVtx1UIdx] = texWord2;
          texWord2 = *scratchWord2Ptr;
          cmdWrite[pass2QuadVtx1VIdx] = texWord2;
          cmdWrite[pass2QuadVtx2PosIdx] = dstRight | dstY * 0x10000;
          texWord3 = *scratchWord3Ptr;
          cmdWrite[pass2QuadVtx2UIdx] = texWord3;
          cmdWrite[pass2QuadVtx2VIdx] = texWord2;
          cmdWrite[pass2QuadVtx3PosIdx] = dstRight | dstBottomHi;
          cmdWrite[pass2QuadVtx3UIdx] = texWord3;
          cmdWrite[pass2QuadVtx3VIdx] = texWord1;
          cmdWrite[pass2QuadDrawRegIdx] = 0x1393;
          cmdWrite[pass2QuadDrawRegValueIdx] = 10;
          cmdWrite[pass2QuadFlushRegIdx] = 0x5c8;
          cmdWrite[pass2SetupWords] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - pass2QuadPacketWordsIdx;
          cmdWrite = cmdWrite + pass2QuadPacketWordsIdx;
          rectIndex = rectIndex + 1;
          rect = rect + 6;
          needsSetup = false;
        } while (rectCount != rectIndex);
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
  bool needsSetupBlock;
  uint rightTileLeftBiased;
  uint leftTileRightBiased;
  uint leftTileDstRightUnclamped;
  uint srcRightUnclamped;
  uint dstRegionRight;
  uint wordsLeftAfterSetup;
  uint dstRectRight;
  uint rightTileDstRight;
  float rightTileV0;
  float rightTileU1;
  float leftTileU1;
  float leftTileU0;
  float leftTileRightEdgeF;
  float rightTileU0;
  float rightTileLeftEdgeF;
  float invLeftTileWidth;
  float invRightTileWidth;
  float invSrcHeight;
  float zeroTexCoord;
  float overflowVScale;
  float uScale;
  float vScale;
  float texBottomV;
  float texTopV;
  float texLeftU;
  uint dstRectBottomClamped;
  int overflowSetupWords;
  int overflowHeight;
  int rectBottomY;
  int srcHeightClamped;
  int srcRightEdge;
  int regionY;
  int regionX;
  int dstRectBottomUnclamped;
  int dstRectTop;
  int dstLeftIntLow;
  int rectX;
  int srcRightIntLow;
  int overflowBoundaryY;
  int topLeftCornerIdx;
  int lastTexWordIdx;
  dword scratchWord3Saved;
  dword scratchWord2Copy;
  dword scratchWord1Saved;
  dword scratchWord2Cached;
  dword scratchWord0Copy;
  dword scratchWord1Copy;
  dword scratchWord3Copy;
  dword scratchWord0Cached;
  dword offscreenField7;
  bool isScreenCopy;
  double srcBottomExact;
  float srcLeftPx;
  float srcTopPx;
  float srcHeightPx;
  float srcBottomPx;
  uint yPacked16;
  float widthRatio;
  float heightRatio;
  float texRightU;
  float texV0;
  float texV1;
  bool needsSetup;
  undefined *taskPtr;
  int dstRectBottom;
  undefined4 *srcSurface;
  uint *lastHeader;
  int flushRegIdx;
  int blockEndIdx;
  int idxPlus5Or22Or13Or20Or19Block1;
  int idxPlus7Or5Or22Or8Or20Block1;
  dword *cmdWord2;
  int idxPlus8Or7Or4Or1Block1;
  dword *cmdWord3;
  int drawRegIdx;
  dword srcDescField7;
  int idxPlus6Or4Or5Or2Or1Block1;
  dword *cmdWord4;
  dword srcDescField4;
  dword scratchWord2Saved;
  dword *cmdWord5;
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
  uint dstBottomHigh16;
  int idxPlus16Or17Or11Or14Block1;
  int idxPlus17Or18Or12Or15Or13Block1;
  uint cmdWordsLeft;
  int idxPlus18Or19Or16Or14Block1;
  int idxPlus19Or10Or17Block2;
  uint dstRectLeft;
  dword *cmdPtrPlus6Block3;
  dword *cmdWrite;
  int *regionRect;
  uint blitKind;
  int srcRectWordIdx;
  int idxPlus2Or18Block4;
  int idxPlus4Or15Block5;
  double srcLeftExact;
  double srcTopExact;
  double srcRightExact;
  double srcLeftFloat;
  double srcTopFloat;
  double srcRightFloat;
  double srcBottomFloat;
  undefined4 srcQueryOutSize;
  uint scratchWord0;
  uint scratchWord1;
  uint scratchWord2;
  uint scratchWord3;
  dword srcQueryBlock [3];
  short srcWidth;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 i2dHi3;
  dword srcDescWidth;
  undefined4 i2dHi4;
  dword srcDescHeight;
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
  int srcHeightI2dLo;
  undefined4 i2dHi22;
  uint i2dLo19;
  undefined4 i2dHi23;
  uint i2dLo20;
  undefined4 i2dHi24;
  int overflowHeightI2dLo;
  undefined4 i2dHi25;
  uint i2dLo21;
  undefined4 i2dHi26;
  uint i2dLo22;
  undefined4 i2dHi27;
  uint i2dLo23;
  undefined4 i2dHi28;
  uint i2dLo24;
  undefined4 i2dHi29;
  uint leftTileSrcRightI2dLo;
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
  uint rightTileSrcLeftI2dLo;
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
  int regionIndex3;
  int regionIndex2;
  int regionIndex;
  uint leftTileDstLeft;
  int *srcDescCopy2;
  short *rectHeightPtr;
  short *rectYPtr;
  int idxPlus3Block6;
  int idxPlus2Block6;
  int idxPlus1Block6;
  int idxPlus16Block7;
  int idxPlus15Block7;
  int idxPlus14Block7;
  int sizeMismatch;
  dword blitCommandHeader;
  uint rightTileDstBottom;
  uint rightTileDstTop;
  uint regionDstLeft;
  uint rightTileDstLeft;
  uint leftTileDstBottom;
  uint leftTileDstTop;
  uint leftTileDstRight;
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
  int offscreenRegionIndex;
  undefined4 *offscreenDesc;
  dword *srcDesc;
  int *regionFirstRect;
  uint topMasked;
  uint leftMasked;
  dword flushWaitWord3;
  dword surfaceFormatWord;
  dword flushWaitWord2;
  undefined4 flushWaitWord;
  dword *scratchWord0Ptr;
  dword *scratchWord1Ptr;
  dword *scratchWord2Ptr;
  dword *scratchWord3Ptr;
  int *srcDescCopy1;
  int cmdBufferSize;
  int errorCode;
  int offscreenResult;
  int mapResult;
  int regByteOffset;
  int offscreenHeightM1;
  int setupWords2;
  int mapResult3;
  int setupWords3;
  int cmdHeaderBase;
  int ioResult;
  int setupWords1;
  int mapResult2;
  int regByteOffset2;
  int srcHeightM1;
  int cmdBuffer;
  int mapResult4;
  int offscreenWidth;
  int setupWords4;
  dword *cmdWord1;
  dword *cmdWord0;
  short offscreenWidth16;
  short srcWidth16;
  
  blitKind = blitFlags & 0x7ffff000;
  cmdWrite = *(dword **)(accel + 0x80);
  cmdBuffer = *(int *)(accel + 0x18);
  regionRect = *(int **)(blitReq + 0x60);
  cmdBufferSize = *(int *)(cmdBuffer + 0x10);
  regionCount = *regionRect;
  cmdCapacity = cmdBufferSize - 7;
  if (cmdWrite == (dword *)0x0) {
LAB_000081e0:
    errorCode = -0x1ffffd42;
  }
  else {
    isScreenCopy = blitKind == 0x1000;
    if (isScreenCopy) {
      srcHandle = *(dword *)(accel + 0x84);
      srcDesc = (dword *)(accel + 0x1c);
      srcOriginX = *(int *)(accel + 0x30);
      cmdHeaderBase = 0x9000000;
      srcOriginY = *(int *)(accel + 0x34);
LAB_000056ac:
      srcWidth = *(short *)(srcDesc + 1);
      if ((0x1000 < srcWidth) || (0x1000 < *(short *)((int)srcDesc + 6))) {
        return -0x1ffffd39;
      }
      blitCommandHeader = cmdHeaderBase + 0x1000000;
    }
    else {
      if (blitKind < 0x1001) {
        if (blitKind != 0) {
          return -0x1ffffd44;
        }
        srcDesc = (dword *)(accel + 0x4c);
        srcOriginX = 0;
        srcOriginY = 0;
        srcHandle = 0;
        cmdHeaderBase = 0xd000000;
        goto LAB_000056ac;
      }
      if (blitKind == 0x3000) {
        srcSurface = *(undefined4 **)(srcRef + 0x28);
        srcOriginX = 0;
        srcOriginY = 0;
        srcDesc = srcSurface + 3;
        blitCommandHeader = 0x8000000;
        srcHandle = *(dword *)*srcSurface;
        *(int *)(accel + 0x94) = *(int *)(accel + 0x94) + 1;
        srcWidth = *(short *)(srcSurface + 4);
      }
      else {
        if (blitKind != 0x7000) {
          return -0x1ffffd44;
        }
        srcQueryBlock[1] = 0x800;
        srcQueryOutSize = 0x30;
        srcQueryBlock[0] = srcRef;
        srcHandle = srcRef;
        ioResult = _io_connect_method_scalarI_structureO
                           (*(undefined4 *)(accel + 0xc),2,srcQueryBlock,2,srcQueryBlock + 2,&srcQueryOutSize);
        if (ioResult != 0) {
          return ioResult;
        }
        srcOriginX = 0;
        srcOriginY = 0;
        blitCommandHeader = 0xc000000;
        srcDesc = srcQueryBlock + 2;
      }
    }
    taskPtr = PTR_0000e694;
    regionFirstRect = regionRect + 3;
    if (regionCount == 0) {
      regionFirstRect = regionRect + 1;
      regionCount = 1;
    }
    dstOffsetY = *(int *)(blitReq + 0x5c) - (int)*(short *)((int)regionRect + 6);
    srcDescWidth = srcDesc[2];
    srcDescField4 = srcDesc[4];
    dstOffsetX = *(int *)(blitReq + 0x58) - (int)*(short *)(regionRect + 1);
    srcDescField7 = srcDesc[7];
    srcFormat = srcDesc[9];
    srcDescHeight = srcDesc[3];
    if ((srcDescWidth != (int)srcWidth) ||
       (sizeMismatch = 0, srcDescHeight != (int)*(short *)((int)srcDesc + 6))) {
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
            (float)((double)CONCAT44(0x43300000,srcDescWidth) - 4503599627370496.0);
    heightRatio = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0) /
             (float)((double)CONCAT44(0x43300000,srcDescHeight) - 4503599627370496.0);
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (cmdBuffer + 0x20) >> 2);
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
        mapResult4 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                     &scratchWord0,&scratchWord1,1);
        if (mapResult4 == 0) {
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
    offscreenWidth = (int)*(short *)(srcDesc + 1);
    if (((isScreenCopy) || (blitKind == 0)) && (*(int *)(accel + 0x8c) == 0)) {
      offscreenResult = ((int (*)())_createOffscreenBuffer)(accel,srcDesc,0);
      if (offscreenResult == 0) goto LAB_000081e0;
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
        flushWaitWord3 = 0xc000;
        srcDescCopy1 = regionFirstRect;
        scratchWord2Ptr = &scratchWord2;
        offscreenRegionIndex = 0;
        needsSetup = true;
        surfaceFormatWord = srcFormat & 0x1f | 0x53000;
        do {
          i2dHi5 = 0x43300000;
          i2dLo3 = srcOriginX + *(short *)srcDescCopy1 ^ 0x80000000;
          i2dHi6 = 0x43300000;
          i2dLo4 = srcOriginY + (short)*srcDescCopy1 ^ 0x80000000;
          srcLeftExact = (double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0;
          i2dHi7 = 0x43300000;
          i2dLo5 = (int)*(short *)(srcDescCopy1 + 1) ^ 0x80000000;
          srcLeftFloat = (double)(float)srcLeftExact;
          i2dHi8 = 0x43300000;
          srcTopExact = (double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0;
          i2dLo6 = (int)*(short *)((int)srcDescCopy1 + 6) ^ 0x80000000;
          srcTopFloat = (double)(float)srcTopExact;
          srcRightExact = srcLeftFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo5) -
                                           4503601774854144.0);
          srcRightFloat = (double)(float)srcRightExact;
          srcBottomExact = srcTopFloat + (double)(float)((double)CONCAT44(0x43300000,i2dLo6) -
                                          4503601774854144.0);
          srcBottomFloat = (double)(float)srcBottomExact;
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
            srcRightInt = (uint)(int)srcRightExact;
            d2iScratch5 = (longlong)(int)srcRightInt;
          }
          if (2147483648.0 <= srcBottomFloat) {
            d2iScratch8 = (longlong)(int)(srcBottomFloat - 2147483648.0);
            srcBottomInt = (int)(srcBottomFloat - 2147483648.0) + 0x80000000;
          }
          else {
            srcBottomInt = (uint)(int)srcBottomExact;
            d2iScratch7 = (longlong)(int)srcBottomInt;
          }
          if (needsSetup) {
            if (cmdWordsLeft < 0x8a) {
              scratchWord1 = *(uint *)(accel + 0x18);
              scratchWord0 = 0;
              if (*(int *)(accel + 0x8c) == 0) {
                *cmdWrite = 0x5c8;
                scratchWord0 = 2;
                cmdWrite[1] = flushWaitWord3;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord0] = 0x1000000;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
              mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,scratchWord1Ptr,scratchWord0Ptr,1);
              if (mapResult == 0) {
                *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord1 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord1;
                cmdWord1 = (dword *)(scratchWord1 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
              }
              else {
LAB_00005e40:
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                cmdWord1 = &__mh_bundle_header.cputype;
              }
LAB_00005e7c:
              needsSetup = true;
              cmdWordsLeft = cmdCapacity;
            }
            else {
              cmdWord1 = cmdWrite + 1;
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
                cmdWrite[1] = flushWaitWord3;
                *(undefined4 *)(accel + 0x94) = 0;
              }
              cmdWrite[scratchWord1] = 0x1000000;
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
              mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                           *(undefined4 *)PTR_0000e694,scratchWord0Ptr,scratchWord1Ptr,1);
              if (mapResult != 0) goto LAB_00005e40;
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              cmdWord1 = (dword *)(scratchWord0 + 0x24);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              goto LAB_00005e7c;
            }
            cmdWord1 = cmdWrite + 1;
            needsSetup = false;
          }
          if (isScreenCopy) {
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
          cmdWrite = cmdWord1 + 5;
          *cmdWord1 = srcHandle;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)(cmdWord1 + 1) - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWord1 + 1;
          cmdWord1[1] = 0x10000000;
          cmdWord1[2] = *(dword *)*DAT_0000e6e4;
          offscreenField7 = DAT_0000e6e4[7];
          cmdWord1[4] = 6;
          cmdWord1[3] = offscreenField7;
          if (needsSetup) {
            setupWords1 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,srcDesc,srcFormat,0,0,0,0);
            srcRectWordIdx = setupWords1 + 1;
            blockEndIdx = setupWords1 + 0x16;
            regByteOffset = setupWords1 << 2;
            idxPlus2Or18Block4 = setupWords1 + 2;
            idxPlus3Or8Or2Block1 = setupWords1 + 3;
            idxPlus4Or6Or1Or5Or3Block1 = setupWords1 + 4;
            idxPlus5Or22Or13Or20Or19Block1 = setupWords1 + 5;
            idxPlus6Or4Or5Or2Or1Block1 = setupWords1 + 6;
            idxPlus7Or5Or22Or8Or20Block1 = setupWords1 + 7;
            idxPlus8Or7Or4Or1Block1 = setupWords1 + 8;
            idxPlus9Or2Or10Or16Block1 = setupWords1 + 9;
            idxPlus10Or11Or20Or12Block1 = setupWords1 + 10;
            idxPlus11Or12Or6Or22Block1 = setupWords1 + 0xb;
            idxPlus12Or13Or7Or6Or4Block1 = setupWords1 + 0xc;
            idxPlus13Or14Or8Or7Or5Block1 = setupWords1 + 0xd;
            idxPlus14Or15Or9Or11Or6Block1 = setupWords1 + 0xe;
            idxPlus15Or16Or10Or13Or7Block1 = setupWords1 + 0xf;
            idxPlus16Or17Or11Or14Block1 = setupWords1 + 0x10;
            idxPlus17Or18Or12Or15Or13Block1 = setupWords1 + 0x11;
            idxPlus18Or19Or16Or14Block1 = setupWords1 + 0x12;
            idxPlus19Or10Or17Block2 = setupWords1 + 0x13;
            flushRegIdx = setupWords1 + 0x14;
            setupWords1 = setupWords1 + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            offscreenWidth16 = *(short *)(srcDesc + 1);
            offscreenHeightM1 = *(short *)((int)srcDesc + 6) + -1;
            cmdWord1[6] = (int)offscreenWidth16 - 1U & 0x7ff | offscreenHeightM1 * 0x800 & 0x3ff800U | 0x80000000;
            cmdWord1[7] = 0x1130;
            cmdWord1[8] = surfaceFormatWord;
            cmdWord1[9] = 0x1140;
            cmdWord1[10] = srcDesc[4] - 1 & 0x3fff | ((int)offscreenWidth16 - 1U) * 0x10 & 0x8000 |
                          offscreenHeightM1 * 0x20 & 0x10000U;
            regByteOffset = 0x18;
            idxPlus2Or18Block4 = 8;
            idxPlus3Or8Or2Block1 = 9;
            srcRectWordIdx = 7;
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
            flushRegIdx = 0x1a;
            setupWords1 = 0x1b;
            blockEndIdx = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + regByteOffset) = 0x10f8;
          cmdWrite[srcRectWordIdx] = srcLeftInt & 0x1fff | (srcTopInt & 0x1fff) << 0xd;
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
          scratchWord3Copy = *scratchWord3Ptr;
          cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = scratchWord3Copy;
          scratchWord0Cached = *scratchWord0Ptr;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = scratchWord0Cached;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = srcLeftInt | srcTopInt << 0x10;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = scratchWord3Copy;
          scratchWord1Copy = *scratchWord1Ptr;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = scratchWord1Copy;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = srcRightInt | srcTopInt << 0x10;
          scratchWord2Saved = *scratchWord2Ptr;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = scratchWord2Saved;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = scratchWord1Copy;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = srcRightInt | srcBottomInt << 0x10;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = scratchWord2Saved;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = scratchWord0Cached;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 0x1393;
          cmdWrite[idxPlus19Or10Or17Block2] = 10;
          cmdWrite[flushRegIdx] = 0x5c8;
          cmdWrite[setupWords1] = 0x20000;
          wordsLeftAfterSetup = (cmdWordsLeft - 6) - blockEndIdx;
          cmdWrite = cmdWrite + blockEndIdx;
          dstRectLeft = dstOffsetX + *(short *)srcDescCopy1;
          dstRectRight = dstRectLeft + (int)*(short *)(srcDescCopy1 + 1);
          dstRectTop = dstOffsetY + (short)*srcDescCopy1;
          dstRectBottom = dstRectTop + *(short *)((int)srcDescCopy1 + 6);
          if (wordsLeftAfterSetup < 0x22) {
            scratchWord2 = *(uint *)(accel + 0x18);
            scratchWord3 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *cmdWrite = 0x5c8;
              scratchWord3 = 2;
              cmdWrite[1] = flushWaitWord3;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            taskPtr = PTR_0000e694;
            cmdWrite[scratchWord3] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord3 | *lastHeader;
            mapResult2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                         scratchWord2Ptr,scratchWord3Ptr,1);
            if (mapResult2 == 0) {
              *(undefined4 *)(scratchWord2 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord2;
              cmdWrite = (dword *)(scratchWord2 + 0x20);
              cmdWord1 = (dword *)(scratchWord2 + 0x24);
              *(uint *)(accel + 0x7c) = scratchWord2 + 0x1c;
            }
            else {
              cmdWrite = (dword *)0x0;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              cmdWord1 = &__mh_bundle_header.cputype;
            }
            needsSetup = true;
            wordsLeftAfterSetup = cmdCapacity;
          }
          else {
            cmdWord1 = cmdWrite + 1;
            needsSetup = false;
          }
          if (isScreenCopy) {
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
          cmdWord1[1] = 0;
          cmdWord1[2] = 0;
          cmdWrite = cmdWord1 + 5;
          *cmdWord1 = srcHandle;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)(cmdWord1 + 3) - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWord1 + 3;
          cmdWord1[3] = 0x4000000;
          cmdWord1[4] = *(dword *)*DAT_0000e6e4;
          if (needsSetup) {
            setupWords2 = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,offscreenDesc,offscreenFormat,0,0,0,0);
            idxPlus6Or4Or5Or2Or1Block1 = setupWords2 + 4;
            idxPlus9Or2Or10Or16Block1 = setupWords2 + 9;
            idxPlus3Block6 = setupWords2 + 3;
            idxPlus1Block6 = setupWords2 + 1;
            idxPlus2Block6 = setupWords2 + 2;
            idxPlus5Or22Or13Or20Or19Block1 = setupWords2 + 0x16;
            regByteOffset2 = setupWords2 << 2;
            idxPlus7Or5Or22Or8Or20Block1 = setupWords2 + 5;
            idxPlus4Or6Or1Or5Or3Block1 = setupWords2 + 6;
            idxPlus8Or7Or4Or1Block1 = setupWords2 + 7;
            idxPlus3Or8Or2Block1 = setupWords2 + 8;
            idxPlus19Or10Or17Block2 = setupWords2 + 10;
            idxPlus10Or11Or20Or12Block1 = setupWords2 + 0xb;
            idxPlus11Or12Or6Or22Block1 = setupWords2 + 0xc;
            idxPlus12Or13Or7Or6Or4Block1 = setupWords2 + 0xd;
            idxPlus13Or14Or8Or7Or5Block1 = setupWords2 + 0xe;
            idxPlus14Or15Or9Or11Or6Block1 = setupWords2 + 0xf;
            idxPlus15Or16Or10Or13Or7Block1 = setupWords2 + 0x10;
            idxPlus16Or17Or11Or14Block1 = setupWords2 + 0x11;
            idxPlus17Or18Or12Or15Or13Block1 = setupWords2 + 0x12;
            idxPlus18Or19Or16Or14Block1 = setupWords2 + 0x13;
            blockEndIdx = setupWords2 + 0x14;
            setupWords2 = setupWords2 + 0x15;
          }
          else {
            *cmdWrite = 0x1120;
            srcWidth16 = *(short *)(offscreenDesc + 1);
            srcHeightM1 = *(short *)((int)offscreenDesc + 6) + -1;
            cmdWord1[6] = (int)srcWidth16 - 1U & 0x7ff | srcHeightM1 * 0x800 & 0x3ff800U | 0x80000000;
            cmdWord1[7] = 0x1130;
            cmdWord1[8] = offscreenFormat & 0x1f | 0x53000;
            cmdWord1[9] = 0x1140;
            cmdWord1[10] = offscreenDesc[4] - 1 & 0x3fff | ((int)srcWidth16 - 1U) * 0x10 & 0x8000 |
                          srcHeightM1 * 0x20 & 0x10000U;
            idxPlus6Or4Or5Or2Or1Block1 = 10;
            idxPlus3Block6 = 9;
            regByteOffset2 = 0x18;
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
            blockEndIdx = 0x1a;
            setupWords2 = 0x1b;
            idxPlus5Or22Or13Or20Or19Block1 = 0x1c;
          }
          *(undefined4 *)((int)cmdWrite + regByteOffset2) = 0x10f8;
          cmdWrite[idxPlus1Block6] = dstRectLeft & 0x1fff | dstRectTop * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus2Block6] = 0x10f9;
          cmdWrite[idxPlus3Block6] = dstRectRight & 0x1fff | dstRectBottom * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0xc00c3500;
          cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = 0x4003d;
          dstBottomHigh16 = dstRectBottom * 0x10000;
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
          cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = dstRectLeft | dstBottomHigh16;
          scratchWord0Copy = *scratchWord0Ptr;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = scratchWord0Copy;
          scratchWord2Cached = *scratchWord2Ptr;
          cmdWrite[idxPlus3Or8Or2Block1] = scratchWord2Cached;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = dstRectLeft | dstRectTop * 0x10000;
          cmdWrite[idxPlus19Or10Or17Block2] = scratchWord0Copy;
          scratchWord3Copy = *scratchWord3Ptr;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = scratchWord3Copy;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = dstRectRight | dstRectTop * 0x10000;
          scratchWord1Saved = *scratchWord1Ptr;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = scratchWord1Saved;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = scratchWord3Copy;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = dstRectRight | dstBottomHigh16;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = scratchWord1Saved;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = scratchWord2Cached;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = 0x1393;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 10;
          cmdWrite[blockEndIdx] = 0x5c8;
          cmdWrite[setupWords2] = 0x20000;
          cmdWordsLeft = (wordsLeftAfterSetup - 6) - idxPlus5Or22Or13Or20Or19Block1;
          cmdWrite = cmdWrite + idxPlus5Or22Or13Or20Or19Block1;
          offscreenRegionIndex = offscreenRegionIndex + 1;
          srcDescCopy1 = srcDescCopy1 + 2;
          needsSetup = false;
        } while (regionCount != offscreenRegionIndex);
      }
    }
    else if (offscreenWidth < 0x1001) {
      if (regionCount != 0) {
        tileHeightWords = srcDescField4 * srcDescField7 * 0x1000;
        scratchWord2Ptr = &scratchWord2;
        scratchWord0Ptr = &scratchWord0;
        scratchWord1Ptr = &scratchWord1;
        scratchWord3Ptr = &scratchWord3;
        regionIndex = 0;
        needsSetupBlock = true;
        regionRect = regionFirstRect;
        do {
          rectYPtr = (short *)((int)regionRect + 2);
          rectHeightPtr = (short *)((int)regionRect + 6);
          i2dHi17 = 0x43300000;
          i2dLo15 = srcOriginX + *(short *)regionRect ^ 0x80000000;
          dstRectLeft = dstOffsetX + *(short *)regionRect;
          i2dHi18 = 0x43300000;
          dstRectTop = dstOffsetY + (short)*regionRect;
          i2dLo16 = srcOriginY + (short)*regionRect ^ 0x80000000;
          i2dHi19 = 0x43300000;
          i2dLo17 = (int)*(short *)(regionRect + 1) ^ 0x80000000;
          dstRegionRight = dstRectLeft + (int)*(short *)(regionRect + 1);
          srcLeftPx = (float)((double)CONCAT44(0x43300000,i2dLo15) - 4503601774854144.0);
          i2dHi20 = 0x43300000;
          i2dLo18 = (int)*(short *)((int)regionRect + 6) ^ 0x80000000;
          dstRectBottomClamped = dstRectTop + *(short *)((int)regionRect + 6);
          srcTopPx = (float)((double)CONCAT44(0x43300000,i2dLo16) - 4503601774854144.0);
          srcHeightClamped = (int)*(short *)((int)srcDesc + 6);
          srcBottomPx = srcTopPx + (float)((double)CONCAT44(0x43300000,i2dLo18) - 4503601774854144.0);
          if (srcHeightClamped < 0x1000) {
            i2dHi21 = 0x43300000;
            srcHeightPx = (float)((double)CONCAT44(0x43300000,srcHeightClamped) - 4503599627370496.0);
            srcHeightI2dLo = srcHeightClamped;
          }
          else {
            srcHeightPx = 4096.0;
            if (4096.0 <= srcBottomPx) {
              srcHeightClamped = 0x1000;
              dstRectBottomClamped = dstOffsetY + 0x1000;
              srcBottomPx = srcHeightPx;
            }
            else {
              srcHeightClamped = 0x1000;
            }
          }
          i2dHi22 = 0x43300000;
          i2dLo19 = (int)*(short *)(srcDesc + 1) ^ 0x80000000;
          vScale = heightRatio * (1.0 / srcHeightPx);
          texBottomV = srcBottomPx * vScale;
          texTopV = srcTopPx * vScale;
          uScale = widthRatio * (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo19) -
                                        4503601774854144.0));
          texRightU = (srcLeftPx + (float)((double)CONCAT44(0x43300000,i2dLo17) - 4503601774854144.0)) *
                   uScale;
          texLeftU = srcLeftPx * uScale;
          if (needsSetupBlock) {
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
              mapResult2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord1Ptr,scratchWord0Ptr,1);
              if (mapResult2 == 0) {
                *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                cmdWrite = (dword *)(scratchWord1 + 0x20);
                *(uint *)(accel + 0x18) = scratchWord1;
                cmdPtrPlus6Block3 = (dword *)(scratchWord1 + 0x38);
                cmdWord1 = (dword *)(scratchWord1 + 0x24);
                *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                cmdWord2 = (dword *)(scratchWord1 + 0x28);
                cmdWord3 = (dword *)(scratchWord1 + 0x2c);
                cmdWord4 = (dword *)(scratchWord1 + 0x30);
                cmdWord5 = (dword *)(scratchWord1 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
LAB_00006cc0:
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                cmdWord1 = &__mh_bundle_header.cputype;
                cmdWord2 = &__mh_bundle_header.cpusubtype;
                cmdWord3 = &__mh_bundle_header.filetype;
                cmdWord4 = &__mh_bundle_header.ncmds;
                cmdWord5 = &__mh_bundle_header.sizeofcmds;
                cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              cmdWord1 = cmdWrite + 1;
              cmdWord2 = cmdWrite + 2;
              cmdWord3 = cmdWrite + 3;
              cmdWord4 = cmdWrite + 4;
              cmdWord5 = cmdWrite + 5;
              cmdPtrPlus6Block3 = cmdWrite + 6;
            }
LAB_00006d28:
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = blitCommandHeader;
            *cmdWord1 = srcHandle;
            *cmdWord2 = srcMode;
            *cmdWord3 = 0;
            *cmdWord4 = 0;
            *cmdWord5 = 0;
            cmdWordsLeft = cmdWordsLeft - 6;
            setupWords3 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,0,srcHeightClamped);
            idxPlus14Block7 = setupWords3 + 0xe;
            idxPlus15Block7 = setupWords3 + 0xf;
            idxPlus7Or5Or22Or8Or20Block1 = setupWords3 + 0x16;
            regByteOffset = setupWords3 << 2;
            idxPlus16Block7 = setupWords3 + 0x10;
            lastTexWordIdx = setupWords3 + 0x11;
            drawRegIdx = setupWords3 + 0x12;
            idxPlus4Or6Or1Or5Or3Block1 = setupWords3 + 1;
            idxPlus9Or2Or10Or16Block1 = setupWords3 + 2;
            idxPlus3Or8Or2Block1 = setupWords3 + 3;
            idxPlus8Or7Or4Or1Block1 = setupWords3 + 4;
            idxPlus6Or4Or5Or2Or1Block1 = setupWords3 + 5;
            idxPlus11Or12Or6Or22Block1 = setupWords3 + 6;
            idxPlus12Or13Or7Or6Or4Block1 = setupWords3 + 7;
            idxPlus13Or14Or8Or7Or5Block1 = setupWords3 + 8;
            idxPlus14Or15Or9Or11Or6Block1 = setupWords3 + 9;
            idxPlus15Or16Or10Or13Or7Block1 = setupWords3 + 10;
            idxPlus16Or17Or11Or14Block1 = setupWords3 + 0xb;
            idxPlus17Or18Or12Or15Or13Block1 = setupWords3 + 0xc;
            idxPlus5Or22Or13Or20Or19Block1 = setupWords3 + 0xd;
            idxPlus18Or19Or16Or14Block1 = setupWords3 + 0x13;
            idxPlus10Or11Or20Or12Block1 = setupWords3 + 0x14;
            setupWords3 = setupWords3 + 0x15;
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
              mapResult2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord0Ptr,scratchWord1Ptr,1);
              if (mapResult2 != 0) goto LAB_00006cc0;
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              cmdPtrPlus6Block3 = (dword *)(scratchWord0 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              cmdWord1 = (dword *)(scratchWord0 + 0x24);
              cmdWord2 = (dword *)(scratchWord0 + 0x28);
              cmdWord3 = (dword *)(scratchWord0 + 0x2c);
              cmdWord4 = (dword *)(scratchWord0 + 0x30);
              cmdWord5 = (dword *)(scratchWord0 + 0x34);
              cmdWordsLeft = cmdCapacity;
              goto LAB_00006d28;
            }
            regByteOffset = 0;
            idxPlus4Or6Or1Or5Or3Block1 = 1;
            idxPlus14Block7 = 0xe;
            idxPlus15Block7 = 0xf;
            lastTexWordIdx = 0x11;
            idxPlus16Block7 = 0x10;
            idxPlus9Or2Or10Or16Block1 = 2;
            idxPlus3Or8Or2Block1 = 3;
            drawRegIdx = 0x12;
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
            setupWords3 = 0x15;
            idxPlus7Or5Or22Or8Or20Block1 = 0x16;
          }
          *(undefined4 *)((int)cmdWrite + regByteOffset) = 0x10f8;
          leftMasked = dstRectLeft & 0x1fff;
          cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = leftMasked | dstRectTop * 0x2000 & 0x3ffe000U;
          cmdWrite[idxPlus9Or2Or10Or16Block1] = 0x10f9;
          topMasked = dstRegionRight & 0x1fff;
          cmdWrite[idxPlus3Or8Or2Block1] = topMasked | (dstRectBottomClamped & 0x1fff) << 0xd;
          cmdWrite[idxPlus8Or7Or4Or1Block1] = 0xc00c3500;
          cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0x4003d;
          cmdWrite[idxPlus11Or12Or6Or22Block1] = dstRectLeft | dstRectBottomClamped << 0x10;
          scratchWord2Copy = *scratchWord2Ptr;
          cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = scratchWord2Copy;
          scratchWord0Cached = *scratchWord0Ptr;
          cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = scratchWord0Cached;
          cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = dstRectLeft | dstRectTop * 0x10000;
          cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = scratchWord2Copy;
          scratchWord1Copy = *scratchWord1Ptr;
          cmdWrite[idxPlus16Or17Or11Or14Block1] = scratchWord1Copy;
          cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = dstRegionRight | dstRectTop * 0x10000;
          scratchWord3Saved = *scratchWord3Ptr;
          cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = scratchWord3Saved;
          cmdWrite[idxPlus14Block7] = scratchWord1Copy;
          cmdWrite[idxPlus15Block7] = dstRegionRight | dstRectBottomClamped << 0x10;
          cmdWrite[idxPlus16Block7] = scratchWord3Saved;
          cmdWrite[lastTexWordIdx] = scratchWord0Cached;
          cmdWrite[drawRegIdx] = 0x1393;
          cmdWrite[idxPlus18Or19Or16Or14Block1] = 10;
          cmdWrite[idxPlus10Or11Or20Or12Block1] = 0x5c8;
          cmdWrite[setupWords3] = 0x20000;
          cmdWordsLeft = cmdWordsLeft - idxPlus7Or5Or22Or8Or20Block1;
          needsSetupBlock = false;
          cmdWrite = cmdWrite + idxPlus7Or5Or22Or8Or20Block1;
          rectBottomY = (int)*rectYPtr + (int)*rectHeightPtr;
          scratchWord0 = (uint)GH_F2U((float)(texBottomV));
          scratchWord1 = (uint)GH_F2U((float)(texTopV));
          scratchWord2 = (uint)GH_F2U((float)(texLeftU));
          scratchWord3 = (uint)GH_F2U((float)(texRightU));
          if (0xfff < rectBottomY) {
            i2dHi23 = 0x43300000;
            overflowBoundaryY = dstOffsetY + 0x1000;
            dstRectBottomUnclamped = dstOffsetY + *rectYPtr + (int)*rectHeightPtr;
            i2dLo20 = (srcOriginY + rectBottomY) - 0x1000U ^ 0x80000000;
            i2dHi24 = 0x43300000;
            overflowHeight = *(short *)((int)srcDesc + 6) + -0x1000;
            overflowVScale = heightRatio * (1.0 / (float)((double)CONCAT44(0x43300000,overflowHeight) - 4503599627370496.0
                                           ));
            texV0 = (float)((double)CONCAT44(0x43300000,i2dLo20) - 4503601774854144.0) * overflowVScale;
            zeroTexCoord = overflowVScale * 0.0;
            overflowHeightI2dLo = overflowHeight;
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
              mapResult3 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                           scratchWord3Ptr,scratchWord2Ptr,1);
              if (mapResult3 == 0) {
                *(undefined4 *)(scratchWord3 + 0x1c) = 0;
                *(uint *)(accel + 0x18) = scratchWord3;
                cmdWrite = (dword *)(scratchWord3 + 0x20);
                cmdPtrPlus6Block3 = (dword *)(scratchWord3 + 0x38);
                *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
                cmdWord1 = (dword *)(scratchWord3 + 0x24);
                cmdWord2 = (dword *)(scratchWord3 + 0x28);
                cmdWord3 = (dword *)(scratchWord3 + 0x2c);
                cmdWord4 = (dword *)(scratchWord3 + 0x30);
                cmdWord5 = (dword *)(scratchWord3 + 0x34);
                cmdWordsLeft = cmdCapacity;
              }
              else {
                cmdWrite = (dword *)0x0;
                *(undefined4 *)(accel + 0x7c) = 0;
                *(undefined4 *)(accel + 0x18) = 0;
                cmdWord1 = &__mh_bundle_header.cputype;
                cmdWord2 = &__mh_bundle_header.cpusubtype;
                cmdWord3 = &__mh_bundle_header.filetype;
                cmdWord4 = &__mh_bundle_header.ncmds;
                cmdWord5 = &__mh_bundle_header.sizeofcmds;
                cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                cmdWordsLeft = cmdCapacity;
              }
            }
            else {
              cmdWord1 = cmdWrite + 1;
              cmdWord2 = cmdWrite + 2;
              cmdWord3 = cmdWrite + 3;
              cmdWord4 = cmdWrite + 4;
              cmdWord5 = cmdWrite + 5;
              cmdPtrPlus6Block3 = cmdWrite + 6;
            }
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
            *(dword **)(accel + 0x7c) = cmdWrite;
            *cmdWrite = blitCommandHeader;
            *cmdWord1 = srcHandle;
            *cmdWord2 = srcMode;
            *cmdWord3 = tileHeightWords;
            *cmdWord4 = 0;
            *cmdWord5 = 0;
            overflowSetupWords = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,0,overflowHeight);
            cmdPtrPlus6Block3[overflowSetupWords] = 0x10f8;
            cmdPtrPlus6Block3[overflowSetupWords + 1] = leftMasked | overflowBoundaryY * 0x2000 & 0x3ffe000U;
            cmdPtrPlus6Block3[overflowSetupWords + 2] = 0x10f9;
            cmdPtrPlus6Block3[overflowSetupWords + 3] = topMasked | dstRectBottomUnclamped * 0x2000 & 0x3ffe000U;
            cmdPtrPlus6Block3[overflowSetupWords + 4] = 0xc00c3500;
            cmdPtrPlus6Block3[overflowSetupWords + 5] = 0x4003d;
            dstBottomHigh16 = dstRectBottomUnclamped * 0x10000;
            cmdPtrPlus6Block3[overflowSetupWords + 6] = dstRectLeft | dstBottomHigh16;
            cmdPtrPlus6Block3[overflowSetupWords + 7] = (dword)GH_F2U((float)(texLeftU));
            cmdPtrPlus6Block3[overflowSetupWords + 8] = (dword)GH_F2U((float)(texV0));
            yPacked16 = overflowBoundaryY * 0x10000;
            cmdPtrPlus6Block3[overflowSetupWords + 9] = dstRectLeft | yPacked16;
            cmdPtrPlus6Block3[overflowSetupWords + 10] = (dword)GH_F2U((float)(texLeftU));
            cmdPtrPlus6Block3[overflowSetupWords + 0xb] = (dword)GH_F2U((float)(zeroTexCoord));
            cmdPtrPlus6Block3[overflowSetupWords + 0xc] = dstRegionRight | yPacked16;
            cmdPtrPlus6Block3[overflowSetupWords + 0xd] = (dword)GH_F2U((float)(texRightU));
            cmdPtrPlus6Block3[overflowSetupWords + 0xe] = (dword)GH_F2U((float)(zeroTexCoord));
            cmdPtrPlus6Block3[overflowSetupWords + 0xf] = dstRegionRight | dstBottomHigh16;
            cmdPtrPlus6Block3[overflowSetupWords + 0x10] = (dword)GH_F2U((float)(texRightU));
            cmdPtrPlus6Block3[overflowSetupWords + 0x11] = (dword)GH_F2U((float)(texV0));
            cmdPtrPlus6Block3[overflowSetupWords + 0x12] = 0x1393;
            cmdPtrPlus6Block3[overflowSetupWords + 0x13] = 10;
            cmdPtrPlus6Block3[overflowSetupWords + 0x14] = 0x5c8;
            cmdPtrPlus6Block3[overflowSetupWords + 0x15] = 0x20000;
            cmdWordsLeft = (cmdWordsLeft - 6) - (overflowSetupWords + 0x16);
            needsSetupBlock = true;
            cmdWrite = cmdPtrPlus6Block3 + overflowSetupWords + 0x16;
            scratchWord0 = (uint)GH_F2U((float)(texLeftU));
            scratchWord1 = (uint)GH_F2U((float)(texRightU));
            scratchWord2 = (uint)GH_F2U((float)(zeroTexCoord));
            scratchWord3 = (uint)GH_F2U((float)(texV0));
          }
          regionRect = regionRect + 2;
          regionIndex = regionIndex + 1;
        } while (regionCount != regionIndex);
      }
    }
    else {
      splitRow = offscreenWidth >> 1 & 0xfffffe00;
      splitRemainder = offscreenWidth - splitRow;
      splitRowPlus2 = splitRow + 2;
      i2dHi27 = 0x43300000;
      i2dHi25 = 0x43300000;
      i2dHi26 = 0x43300000;
      i2dLo21 = (int)*(short *)((int)srcDesc + 6) ^ 0x80000000;
      i2dLo23 = splitRemainder ^ 0x80000000;
      i2dLo22 = splitRowPlus2 ^ 0x80000000;
      invSrcHeight = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo21) - 4503601774854144.0);
      invRightTileWidth = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo23) - 4503601774854144.0);
      invLeftTileWidth = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo22) - 4503601774854144.0);
      if (regionCount != 0) {
        needsSetupBlock = true;
        regionIndex2 = 0;
        flushWaitWord2 = 0xc000;
        srcDescCopy2 = regionFirstRect;
        do {
          regionX = (int)*(short *)srcDescCopy2;
          if (srcOriginX + regionX < (int)splitRowPlus2) {
            i2dLo24 = srcOriginX + regionX ^ 0x80000000;
            i2dHi28 = 0x43300000;
            srcRightUnclamped = srcOriginX + regionX + *(short *)(srcDescCopy2 + 1);
            leftTileSrcRightI2dLo = splitRowPlus2;
            if ((int)srcRightUnclamped < (int)splitRowPlus2) {
              leftTileSrcRightI2dLo = srcRightUnclamped;
            }
            leftTileSrcRightI2dLo = leftTileSrcRightI2dLo ^ 0x80000000;
            i2dHi29 = 0x43300000;
            leftTileDstLeft = dstOffsetX + regionX;
            leftTileDstRightUnclamped = leftTileDstLeft + (int)*(short *)(srcDescCopy2 + 1);
            regionY = (int)(short)*srcDescCopy2;
            i2dHi30 = 0x43300000;
            i2dLo25 = srcOriginY + regionY ^ 0x80000000;
            i2dHi31 = 0x43300000;
            i2dLo26 = srcOriginY + regionY + *(short *)((int)srcDescCopy2 + 6) ^ 0x80000000;
            if ((int)splitRowPlus2 < (int)leftTileDstRightUnclamped) {
              i2dHi32 = 0x43300000;
              i2dLo27 = dstOffsetX + splitRowPlus2 ^ 0x80000000;
              leftTileRightBiased = i2dLo27;
            }
            else {
              i2dLo28 = leftTileDstRightUnclamped ^ 0x80000000;
              i2dHi33 = 0x43300000;
              leftTileRightBiased = i2dLo28;
            }
            srcRightExact = (double)CONCAT44(0x43300000,leftTileRightBiased) - 4503601774854144.0;
            leftTileRightEdgeF = (float)srcRightExact;
            if (2.1474836e+09 <= leftTileRightEdgeF) {
              srcRightIntLow = (int)(leftTileRightEdgeF - 2.1474836e+09);
              d2iScratch10 = (longlong)srcRightIntLow;
              leftTileDstRight = srcRightIntLow + 0x80000000;
            }
            else {
              leftTileDstRight = (uint)(int)srcRightExact;
              d2iScratch9 = (longlong)(int)leftTileDstRight;
            }
            leftTileU0 = widthRatio * invLeftTileWidth * (float)((double)CONCAT44(0x43300000,i2dLo24) -
                                           4503601774854144.0);
            leftTileU1 = widthRatio * invLeftTileWidth * (float)((double)CONCAT44(0x43300000,leftTileSrcRightI2dLo) -
                                            4503601774854144.0);
            texV0 = heightRatio * invSrcHeight * (float)((double)CONCAT44(0x43300000,i2dLo25) -
                                             4503601774854144.0);
            texV1 = heightRatio * invSrcHeight * (float)((double)CONCAT44(0x43300000,i2dLo26) -
                                             4503601774854144.0);
            leftTileDstTop = dstOffsetY + regionY;
            leftTileDstBottom = leftTileDstTop + (int)*(short *)((int)srcDescCopy2 + 6);
            if (needsSetupBlock) {
              if (cmdWordsLeft < 0x9e) {
                scratchWord1 = *(uint *)(accel + 0x18);
                scratchWord0 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord0 = 2;
                  cmdWrite[1] = flushWaitWord2;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord0] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
                mapResult4 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord1,&scratchWord0,1);
                if (mapResult4 == 0) {
                  *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord1;
                  cmdWrite = (dword *)(scratchWord1 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord1 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                  cmdWord1 = (dword *)(scratchWord1 + 0x24);
                  cmdWord2 = (dword *)(scratchWord1 + 0x28);
                  cmdWord3 = (dword *)(scratchWord1 + 0x2c);
                  cmdWord4 = (dword *)(scratchWord1 + 0x30);
                  cmdWord5 = (dword *)(scratchWord1 + 0x34);
                  cmdWordsLeft = cmdCapacity;
                }
                else {
                  cmdWrite = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWord1 = &__mh_bundle_header.cputype;
                  cmdWord2 = &__mh_bundle_header.cpusubtype;
                  cmdWord3 = &__mh_bundle_header.filetype;
                  cmdWord4 = &__mh_bundle_header.ncmds;
                  cmdWord5 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                  cmdWordsLeft = cmdCapacity;
                }
              }
              else {
                cmdWord1 = cmdWrite + 1;
                cmdWord2 = cmdWrite + 2;
                cmdWord3 = cmdWrite + 3;
                cmdWord4 = cmdWrite + 4;
                cmdWord5 = cmdWrite + 5;
                cmdPtrPlus6Block3 = cmdWrite + 6;
              }
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
              *(dword **)(accel + 0x7c) = cmdWrite;
              *cmdWrite = blitCommandHeader;
              *cmdWord1 = srcHandle;
              *cmdWord2 = srcMode;
              *cmdWord3 = 0;
              *cmdWord4 = 0;
              *cmdWord5 = 0;
              cmdWordsLeft = cmdWordsLeft - 4;
              setupWords4 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRowPlus2,0)
              ;
LAB_0000789c:
              topLeftCornerIdx = setupWords4 + 9;
              idxPlus11Or12Or6Or22Block1 = setupWords4 + 0x16;
              regByteOffset2 = setupWords4 << 2;
              idxPlus8Or7Or4Or1Block1 = setupWords4 + 1;
              idxPlus6Or4Or5Or2Or1Block1 = setupWords4 + 2;
              idxPlus3Or8Or2Block1 = setupWords4 + 3;
              idxPlus4Or15Block5 = setupWords4 + 4;
              idxPlus4Or6Or1Or5Or3Block1 = setupWords4 + 5;
              idxPlus12Or13Or7Or6Or4Block1 = setupWords4 + 6;
              idxPlus13Or14Or8Or7Or5Block1 = setupWords4 + 7;
              idxPlus7Or5Or22Or8Or20Block1 = setupWords4 + 8;
              idxPlus9Or2Or10Or16Block1 = setupWords4 + 10;
              idxPlus14Or15Or9Or11Or6Block1 = setupWords4 + 0xb;
              idxPlus10Or11Or20Or12Block1 = setupWords4 + 0xc;
              idxPlus15Or16Or10Or13Or7Block1 = setupWords4 + 0xd;
              idxPlus16Or17Or11Or14Block1 = setupWords4 + 0xe;
              idxPlus17Or18Or12Or15Or13Block1 = setupWords4 + 0xf;
              idxPlus18Or19Or16Or14Block1 = setupWords4 + 0x10;
              idxPlus19Or10Or17Block2 = setupWords4 + 0x11;
              idxPlus2Or18Block4 = setupWords4 + 0x12;
              blockEndIdx = setupWords4 + 0x13;
              idxPlus5Or22Or13Or20Or19Block1 = setupWords4 + 0x14;
              setupWords4 = setupWords4 + 0x15;
              cmdWrite = cmdPtrPlus6Block3;
            }
            else {
              if (cmdWordsLeft < 0x2a) {
                scratchWord0 = *(uint *)(accel + 0x18);
                scratchWord1 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord1 = 2;
                  cmdWrite[1] = flushWaitWord2;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord1] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
                mapResult4 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord0,&scratchWord1,1);
                if (mapResult4 == 0) {
                  *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord0;
                  cmdWord0 = (dword *)(scratchWord0 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord0 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                  cmdWrite = (dword *)(scratchWord0 + 0x24);
                  cmdWord2 = (dword *)(scratchWord0 + 0x28);
                  cmdWord3 = (dword *)(scratchWord0 + 0x2c);
                  cmdWord4 = (dword *)(scratchWord0 + 0x30);
                  cmdWord5 = (dword *)(scratchWord0 + 0x34);
                }
                else {
                  cmdWord0 = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWrite = &__mh_bundle_header.cputype;
                  cmdWord2 = &__mh_bundle_header.cpusubtype;
                  cmdWord3 = &__mh_bundle_header.filetype;
                  cmdWord4 = &__mh_bundle_header.ncmds;
                  cmdWord5 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                }
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = (int)cmdWord0 - (int)lastHeader >> 2 | *lastHeader;
                *(dword **)(accel + 0x7c) = cmdWord0;
                *cmdWord0 = blitCommandHeader;
                *cmdWrite = srcHandle;
                *cmdWord2 = srcMode;
                *cmdWord3 = 0;
                *cmdWord4 = 0;
                *cmdWord5 = 0;
                cmdWordsLeft = cmdBufferSize - 0xb;
                setupWords4 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRowPlus2,
                                            0);
                goto LAB_0000789c;
              }
              regByteOffset2 = 0;
              idxPlus8Or7Or4Or1Block1 = 1;
              idxPlus6Or4Or5Or2Or1Block1 = 2;
              topLeftCornerIdx = 9;
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
              blockEndIdx = 0x13;
              idxPlus5Or22Or13Or20Or19Block1 = 0x14;
              setupWords4 = 0x15;
              idxPlus11Or12Or6Or22Block1 = 0x16;
            }
            *(undefined4 *)((int)cmdWrite + regByteOffset2) = 0x10f8;
            cmdWrite[idxPlus8Or7Or4Or1Block1] = leftTileDstLeft & 0x1fff | (leftTileDstTop & 0x1fff) << 0xd;
            cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = 0x10f9;
            cmdWrite[idxPlus3Or8Or2Block1] = leftTileDstRight & 0x1fff | (leftTileDstBottom & 0x1fff) << 0xd;
            cmdWrite[idxPlus4Or15Block5] = 0xc00c3500;
            cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = 0x4003d;
            cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = leftTileDstLeft | leftTileDstBottom << 0x10;
            cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = (dword)GH_F2U((float)(leftTileU0));
            cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = (dword)GH_F2U((float)(texV1));
            cmdWrite[topLeftCornerIdx] = leftTileDstLeft | leftTileDstTop << 0x10;
            cmdWrite[idxPlus9Or2Or10Or16Block1] = (dword)GH_F2U((float)(leftTileU0));
            cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = (dword)GH_F2U((float)(texV0));
            cmdWrite[idxPlus10Or11Or20Or12Block1] = leftTileDstRight | leftTileDstTop << 0x10;
            cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = (dword)GH_F2U((float)(leftTileU1));
            cmdWrite[idxPlus16Or17Or11Or14Block1] = (dword)GH_F2U((float)(texV0));
            cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = leftTileDstRight | leftTileDstBottom << 0x10;
            cmdWrite[idxPlus18Or19Or16Or14Block1] = (dword)GH_F2U((float)(leftTileU1));
            cmdWrite[idxPlus19Or10Or17Block2] = (dword)GH_F2U((float)(texV1));
            cmdWrite[idxPlus2Or18Block4] = 0x1393;
            cmdWrite[blockEndIdx] = 10;
            cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = 0x5c8;
            cmdWrite[setupWords4] = 0x20000;
            cmdWordsLeft = cmdWordsLeft - idxPlus11Or12Or6Or22Block1;
            needsSetupBlock = false;
            cmdWrite = cmdWrite + idxPlus11Or12Or6Or22Block1;
            scratchWord0 = (uint)GH_F2U((float)(texV1));
            scratchWord1 = (uint)GH_F2U((float)(texV0));
            scratchWord2 = (uint)GH_F2U((float)(leftTileU1));
            scratchWord3 = (uint)GH_F2U((float)(leftTileU0));
          }
          regionIndex2 = regionIndex2 + 1;
          srcDescCopy2 = srcDescCopy2 + 2;
        } while (regionCount != regionIndex2);
        needsSetupBlock = true;
        regionIndex3 = 0;
        flushWaitWord = 0xc000;
        regionRect = regionFirstRect;
        do {
          rectX = (int)*(short *)regionRect;
          srcRightEdge = rectX + *(short *)(regionRect + 1) + srcOriginX;
          if ((int)splitRow < srcRightEdge) {
            rightTileSrcLeftI2dLo = splitRow;
            if ((int)splitRow < rectX + srcOriginX) {
              rightTileSrcLeftI2dLo = rectX + srcOriginX;
            }
            rightTileSrcLeftI2dLo = rightTileSrcLeftI2dLo ^ 0x80000000;
            i2dLo29 = splitRow ^ 0x80000000;
            i2dLo30 = srcRightEdge - splitRow ^ 0x80000000;
            regionDstLeft = dstOffsetX + rectX;
            i2dHi34 = 0x43300000;
            i2dHi35 = 0x43300000;
            i2dHi36 = 0x43300000;
            regionY = (int)(short)*regionRect;
            i2dHi37 = 0x43300000;
            i2dLo31 = regionY + srcOriginY ^ 0x80000000;
            i2dHi38 = 0x43300000;
            i2dLo32 = regionY + *(short *)((int)regionRect + 6) + srcOriginX ^ 0x80000000;
            if ((int)splitRow < (int)regionDstLeft) {
              i2dLo33 = regionDstLeft ^ 0x80000000;
              i2dHi39 = 0x43300000;
              rightTileLeftBiased = i2dLo33;
            }
            else {
              i2dHi40 = 0x43300000;
              i2dLo34 = dstOffsetX + splitRow ^ 0x80000000;
              rightTileLeftBiased = i2dLo34;
            }
            srcRightExact = (double)CONCAT44(0x43300000,rightTileLeftBiased) - 4503601774854144.0;
            rightTileLeftEdgeF = (float)srcRightExact;
            if (2.1474836e+09 <= rightTileLeftEdgeF) {
              dstLeftIntLow = (int)(rightTileLeftEdgeF - 2.1474836e+09);
              d2iScratch12 = (longlong)dstLeftIntLow;
              rightTileDstLeft = dstLeftIntLow + 0x80000000;
            }
            else {
              rightTileDstLeft = (uint)(int)srcRightExact;
              d2iScratch11 = (longlong)(int)rightTileDstLeft;
            }
            rightTileDstRight = regionDstLeft + (int)*(short *)(regionRect + 1);
            rightTileU0 = widthRatio * invRightTileWidth * ((float)((double)CONCAT44(0x43300000,rightTileSrcLeftI2dLo) -
                                            4503601774854144.0) -
                                    (float)((double)CONCAT44(0x43300000,i2dLo29) -
                                           4503601774854144.0));
            rightTileU1 = widthRatio * invRightTileWidth * (float)((double)CONCAT44(0x43300000,i2dLo30) -
                                           4503601774854144.0);
            rightTileV0 = heightRatio * invSrcHeight * (float)((double)CONCAT44(0x43300000,i2dLo31) -
                                             4503601774854144.0);
            texV0 = heightRatio * invSrcHeight * (float)((double)CONCAT44(0x43300000,i2dLo32) -
                                             4503601774854144.0);
            rightTileDstTop = dstOffsetY + regionY;
            rightTileDstBottom = rightTileDstTop + (int)*(short *)((int)regionRect + 6);
            if (needsSetupBlock) {
              if (cmdWordsLeft < 0x9e) {
                scratchWord2 = *(uint *)(accel + 0x18);
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
                mapResult4 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord2,&scratchWord3,1);
                if (mapResult4 == 0) {
                  *(undefined4 *)(scratchWord2 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord2;
                  cmdWrite = (dword *)(scratchWord2 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord2 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord2 + 0x1c;
                  cmdWord1 = (dword *)(scratchWord2 + 0x24);
                  cmdWord2 = (dword *)(scratchWord2 + 0x28);
                  cmdWord3 = (dword *)(scratchWord2 + 0x2c);
                  cmdWord4 = (dword *)(scratchWord2 + 0x30);
                  cmdWord5 = (dword *)(scratchWord2 + 0x34);
                  cmdWordsLeft = cmdCapacity;
                }
                else {
                  cmdWrite = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWord1 = &__mh_bundle_header.cputype;
                  cmdWord2 = &__mh_bundle_header.cpusubtype;
                  cmdWord3 = &__mh_bundle_header.filetype;
                  cmdWord4 = &__mh_bundle_header.ncmds;
                  cmdWord5 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                  cmdWordsLeft = cmdCapacity;
                }
              }
              else {
                cmdWord1 = cmdWrite + 1;
                cmdWord2 = cmdWrite + 2;
                cmdWord3 = cmdWrite + 3;
                cmdWord4 = cmdWrite + 4;
                cmdWord5 = cmdWrite + 5;
                cmdPtrPlus6Block3 = cmdWrite + 6;
              }
              lastHeader = *(uint **)(accel + 0x7c);
              *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
              *(dword **)(accel + 0x7c) = cmdWrite;
              *cmdWrite = blitCommandHeader;
              *cmdWord1 = srcHandle;
              *cmdWord2 = srcMode;
              *cmdWord3 = 0;
              *cmdWord4 = srcDesc[0xb];
              *cmdWord5 = splitRow;
              cmdWordsLeft = cmdWordsLeft - 4;
              setupWords4 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRemainder,0)
              ;
LAB_00007ff0:
              topLeftCornerIdx = setupWords4 + 9;
              blockEndIdx = setupWords4 + 10;
              idxPlus11Or12Or6Or22Block1 = setupWords4 + 0x16;
              regByteOffset2 = setupWords4 << 2;
              idxPlus6Or4Or5Or2Or1Block1 = setupWords4 + 1;
              idxPlus3Or8Or2Block1 = setupWords4 + 2;
              idxPlus4Or6Or1Or5Or3Block1 = setupWords4 + 3;
              idxPlus12Or13Or7Or6Or4Block1 = setupWords4 + 4;
              idxPlus13Or14Or8Or7Or5Block1 = setupWords4 + 5;
              idxPlus14Or15Or9Or11Or6Block1 = setupWords4 + 6;
              idxPlus15Or16Or10Or13Or7Block1 = setupWords4 + 7;
              idxPlus8Or7Or4Or1Block1 = setupWords4 + 8;
              idxPlus16Or17Or11Or14Block1 = setupWords4 + 0xb;
              idxPlus10Or11Or20Or12Block1 = setupWords4 + 0xc;
              idxPlus17Or18Or12Or15Or13Block1 = setupWords4 + 0xd;
              idxPlus18Or19Or16Or14Block1 = setupWords4 + 0xe;
              idxPlus4Or15Block5 = setupWords4 + 0xf;
              idxPlus9Or2Or10Or16Block1 = setupWords4 + 0x10;
              idxPlus19Or10Or17Block2 = setupWords4 + 0x11;
              idxPlus2Or18Block4 = setupWords4 + 0x12;
              idxPlus5Or22Or13Or20Or19Block1 = setupWords4 + 0x13;
              idxPlus7Or5Or22Or8Or20Block1 = setupWords4 + 0x14;
              setupWords4 = setupWords4 + 0x15;
              cmdWrite = cmdPtrPlus6Block3;
            }
            else {
              if (cmdWordsLeft < 0x2a) {
                scratchWord3 = *(uint *)(accel + 0x18);
                scratchWord2 = 0;
                if (*(int *)(accel + 0x8c) == 0) {
                  *cmdWrite = 0x5c8;
                  scratchWord2 = 2;
                  cmdWrite[1] = flushWaitWord;
                  *(undefined4 *)(accel + 0x94) = 0;
                }
                cmdWrite[scratchWord2] = 0x1000000;
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = ((int)cmdWrite - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
                mapResult4 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                             *(undefined4 *)PTR_0000e694,&scratchWord3,&scratchWord2,1);
                if (mapResult4 == 0) {
                  *(undefined4 *)(scratchWord3 + 0x1c) = 0;
                  *(uint *)(accel + 0x18) = scratchWord3;
                  cmdWord0 = (dword *)(scratchWord3 + 0x20);
                  cmdPtrPlus6Block3 = (dword *)(scratchWord3 + 0x38);
                  *(uint *)(accel + 0x7c) = scratchWord3 + 0x1c;
                  cmdWrite = (dword *)(scratchWord3 + 0x24);
                  cmdWord2 = (dword *)(scratchWord3 + 0x28);
                  cmdWord3 = (dword *)(scratchWord3 + 0x2c);
                  cmdWord4 = (dword *)(scratchWord3 + 0x30);
                  cmdWord5 = (dword *)(scratchWord3 + 0x34);
                }
                else {
                  cmdWord0 = (dword *)0x0;
                  *(undefined4 *)(accel + 0x7c) = 0;
                  *(undefined4 *)(accel + 0x18) = 0;
                  cmdWrite = &__mh_bundle_header.cputype;
                  cmdWord2 = &__mh_bundle_header.cpusubtype;
                  cmdWord3 = &__mh_bundle_header.filetype;
                  cmdWord4 = &__mh_bundle_header.ncmds;
                  cmdWord5 = &__mh_bundle_header.sizeofcmds;
                  cmdPtrPlus6Block3 = &__mh_bundle_header.flags;
                }
                lastHeader = *(uint **)(accel + 0x7c);
                *lastHeader = (int)cmdWord0 - (int)lastHeader >> 2 | *lastHeader;
                *(dword **)(accel + 0x7c) = cmdWord0;
                *cmdWord0 = blitCommandHeader;
                *cmdWrite = srcHandle;
                *cmdWord2 = srcMode;
                *cmdWord3 = 0;
                *cmdWord4 = srcDesc[0xb];
                *cmdWord5 = splitRow;
                cmdWordsLeft = cmdBufferSize - 0xb;
                setupWords4 = ((int (*)())_radeon3DCopySetup)(accel,cmdPtrPlus6Block3,srcDesc,srcFormat,sizeMismatch,0,splitRemainder,
                                            0);
                goto LAB_00007ff0;
              }
              regByteOffset2 = 0;
              idxPlus6Or4Or5Or2Or1Block1 = 1;
              topLeftCornerIdx = 9;
              idxPlus3Or8Or2Block1 = 2;
              idxPlus4Or6Or1Or5Or3Block1 = 3;
              blockEndIdx = 10;
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
              setupWords4 = 0x15;
              idxPlus11Or12Or6Or22Block1 = 0x16;
            }
            *(undefined4 *)((int)cmdWrite + regByteOffset2) = 0x10f8;
            cmdWrite[idxPlus6Or4Or5Or2Or1Block1] = rightTileDstLeft & 0x1fff | (rightTileDstTop & 0x1fff) << 0xd;
            cmdWrite[idxPlus3Or8Or2Block1] = 0x10f9;
            cmdWrite[idxPlus4Or6Or1Or5Or3Block1] = rightTileDstRight & 0x1fff | (rightTileDstBottom & 0x1fff) << 0xd;
            cmdWrite[idxPlus12Or13Or7Or6Or4Block1] = 0xc00c3500;
            cmdWrite[idxPlus13Or14Or8Or7Or5Block1] = 0x4003d;
            cmdWrite[idxPlus14Or15Or9Or11Or6Block1] = rightTileDstLeft | rightTileDstBottom << 0x10;
            cmdWrite[idxPlus15Or16Or10Or13Or7Block1] = (dword)GH_F2U((float)(rightTileU0));
            cmdWrite[idxPlus8Or7Or4Or1Block1] = (dword)GH_F2U((float)(texV0));
            cmdWrite[topLeftCornerIdx] = rightTileDstLeft | rightTileDstTop << 0x10;
            cmdWrite[blockEndIdx] = (dword)GH_F2U((float)(rightTileU0));
            cmdWrite[idxPlus16Or17Or11Or14Block1] = (dword)GH_F2U((float)(rightTileV0));
            cmdWrite[idxPlus10Or11Or20Or12Block1] = rightTileDstRight | rightTileDstTop << 0x10;
            cmdWrite[idxPlus17Or18Or12Or15Or13Block1] = (dword)GH_F2U((float)(rightTileU1));
            cmdWrite[idxPlus18Or19Or16Or14Block1] = (dword)GH_F2U((float)(rightTileV0));
            cmdWrite[idxPlus4Or15Block5] = rightTileDstRight | rightTileDstBottom << 0x10;
            cmdWrite[idxPlus9Or2Or10Or16Block1] = (dword)GH_F2U((float)(rightTileU1));
            cmdWrite[idxPlus19Or10Or17Block2] = (dword)GH_F2U((float)(texV0));
            cmdWrite[idxPlus2Or18Block4] = 0x1393;
            cmdWrite[idxPlus5Or22Or13Or20Or19Block1] = 10;
            cmdWrite[idxPlus7Or5Or22Or8Or20Block1] = 0x5c8;
            cmdWrite[setupWords4] = 0x20000;
            cmdWordsLeft = cmdWordsLeft - idxPlus11Or12Or6Or22Block1;
            needsSetupBlock = false;
            cmdWrite = cmdWrite + idxPlus11Or12Or6Or22Block1;
            scratchWord0 = (uint)GH_F2U((float)(rightTileV0));
            scratchWord1 = (uint)GH_F2U((float)(rightTileU1));
            scratchWord2 = (uint)GH_F2U((float)(rightTileU0));
            scratchWord3 = (uint)GH_F2U((float)(texV0));
          }
          regionRect = regionRect + 2;
          regionIndex3 = regionIndex3 + 1;
        } while (regionCount != regionIndex3);
      }
    }
    errorCode = 0;
    *(dword **)(accel + 0x80) = cmdWrite;
  }
  return errorCode;
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
  undefined4 *fastCmdWrite;
  uint batchLimit;
  uint batchStart;
  int pass2SetupWords;
  uint cmdWordsLeft;
  bool firstTile;
  bool noMaskFlags;
  undefined *taskPtr;
  undefined4 *patternDesc;
  int *rectPtr;
  uint *lastHeader;
  uint cmdCapacity;
  uint fillKind;
  uint nextTileLeft;
  uint tileLeft;
  uint firstTileRightUnclamped;
  uint fillColor;
  dword *cmdWrite;
  undefined4 *rectEntry;
  int progIdx95;
  int progIdx96;
  float quadSlot0;
  float quadSlot1;
  float quadSlot2;
  uint quadSlot3;
  float quadSlot4;
  float quadSlot5;
  float quadSlot6;
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
  int texOriginUInt;
  undefined4 i2dHi6;
  int texOriginVInt;
  undefined4 i2dHi7;
  uint tileTopSpill2;
  undefined4 i2dHi8;
  uint tileBottomSpill2;
  undefined4 i2dHi9;
  uint fillAlpha1;
  undefined4 i2dHi10;
  uint fillRed5;
  undefined4 i2dHi11;
  uint fillGreen5;
  undefined4 i2dHi12;
  uint fillBlue5;
  undefined4 i2dHi13;
  uint fillAlpha8;
  undefined4 i2dHi14;
  uint fillRed8;
  undefined4 i2dHi15;
  uint fillGreen8;
  undefined4 i2dHi16;
  uint fillBlue8;
  undefined4 i2dHi17;
  uint tileTopSpill;
  undefined4 i2dHi18;
  uint tileBottomSpill;
  undefined4 i2dHi19;
  uint curTileLeft;
  undefined4 i2dHi20;
  uint tileRightSpill;
  undefined4 i2dHi21;
  uint i2dLo5;
  undefined4 i2dHi22;
  uint i2dLo6;
  undefined4 i2dHi23;
  uint i2dLo7;
  undefined4 i2dHi24;
  int tileWidthSpill;
  undefined4 i2dHi25;
  uint i2dLo8;
  undefined4 i2dHi26;
  uint i2dLo9;
  undefined4 i2dHi27;
  int tileHeightSpill;
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
  uint dstLeftSpill;
  undefined4 i2dHi34;
  uint dstRightSpill;
  undefined4 i2dHi35;
  uint dstTopSpill;
  undefined4 i2dHi36;
  uint dstBottomSpill;
  undefined4 i2dHi37;
  uint i2dLo15;
  undefined4 i2dHi38;
  uint i2dLo16;
  undefined4 i2dHi39;
  uint i2dLo17;
  undefined4 i2dHi40;
  uint i2dLo18;
  uint batchWords;
  int progIdx94;
  int progIdx93;
  int progIdx92;
  int progIdx91;
  int progIdx90;
  int progIdx89;
  int progIdx88;
  int progIdx87;
  int progIdx86;
  int fillQuadVtx2ScrVIdx;
  int fillQuadVtx2PosIdx;
  int fillQuadVtx1TexVIdx;
  int fillQuadVtx1TexUIdx;
  int fillQuadVtx1ScrVIdx;
  int fillQuadVtx1ScrUIdx;
  int fillQuadVtx1PosIdx;
  int fillQuadVtx0TexUIdx;
  int fillQuadVtx0PosIdx;
  int fillQuadFormatIdx;
  int tileHdrByteOff;
  float fillAlphaF;
  float fillBlueF;
  float fillGreenF;
  float fillRedF;
  uint tileRight;
  uint tileBottom;
  uint tileTop;
  uint dstBottom;
  uint dstTop;
  uint dstRight;
  uint dstLeft;
  int textureDesc;
  uint rectIndex;
  int rectsPerBatch;
  uint cmdCapacityFast;
  short screenWidth;
  short screenHeight;
  int tileHeight;
  int picOffset;
  float *quadSlot0Ptr;
  float *quadSlot1Ptr;
  float *quadSlot2Ptr;
  dword *quadSlot3Ptr;
  float *quadSlot4Ptr;
  float *quadSlot5Ptr;
  float *quadSlot6Ptr;
  dword *scratchWord2Ref;
  uint tileBottomHi;
  uint tileTopHi;
  uint maskBit;
  float *quadSlot2PtrB;
  uint colorBits;
  dword maskWord;
  dword texV1Bits;
  dword scrV1Bits;
  double fillRed5D;
  float texOriginV;
  float tileTopF;
  float tileBottomF;
  float texOriginU;
  float quadRightF;
  float texU0;
  float scrU1;
  float scrU0;
  float texV0;
  float scrV0;
  float texU1;
  int progIdx103;
  int tileIdx24;
  int vtxIdxZ3;
  int offscreenResult;
  int screenFormat;
  int streamIdxBase;
  int vtxIdxX0;
  int progIdx107;
  int tileIdx6;
  int vtxByteOffY1;
  int progByteOff82;
  int tileIdx4;
  int vtxByteOffX1;
  int cmdBuffer;
  int mapResult;
  int surfaceFormatWord;
  int progIdx105;
  int tileIdx16;
  int pass2Format;
  int cmdBufferSize;
  int fillSetupWords;
  int vtxByteOffZ0;
  int textureHeightM1;
  int progIdx106;
  int tileIdx26;
  int batchRemaining;
  int progIdx82;
  int tileIdx13;
  int vtxByteOffZ1;
  int progIdx83;
  int tileIdx15;
  int originX;
  int progIdx84;
  int tileIdx3;
  int originY;
  int progIdx85;
  int tileIdx18;
  int vtxByteOffY0;
  int progIdx98;
  int tileIdx19;
  int vtxByteOffY3;
  int progIdx99;
  int tileIdx20;
  int vtxByteOffX3;
  int progIdx100;
  int tileIdx21;
  int vtxByteOffZ2;
  int progIdx101;
  int tileIdx22;
  int vtxByteOffY2;
  int progIdx102;
  int tileIdx23;
  int vtxByteOffX2;
  int progIdx104;
  int tileIdx17;
  int progIdx97;
  int tileWidth;
  dword *tileWord1;
  dword *finalWord1;
  dword *tileWord3;
  dword *finalWord2;
  dword *tileWord4;
  dword *finalWord3;
  dword *tileWord5;
  dword *finalWord4;
  dword *tileWord2;
  dword *finalCursor;
  dword *streamCursor;
  dword *finalWord5;
  uint tileRowTop;
  uint tileRowTopNext;
  uint textureWidthM1;
  uint maskCtlWord;
  uint tileRightLimit;
  uint batchEnd;
  
  fillKind = blitFlags & 0x7ffff000;
  if ((fillKind != 0x6000) || ((fillFlags & 0xf000) != 0)) {
    cmdWrite = *(dword **)(accel + 0x80);
    cmdBuffer = *(int *)(accel + 0x18);
    fillColor = fillReq[5];
    cmdCapacity = *(int *)(cmdBuffer + 0x10) - 7;
    if ((cmdWrite != (dword *)0x0) &&
       ((offscreenResult = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,(uint)(*(int *)(accel + 0x70) == 3)),
        offscreenResult != 0 &&
        (offscreenResult = ((int (*)())_createTextureBuffer)(accel,0x40,0x40,(uint)(*(int *)(accel + 0x70) == 3)),
        offscreenResult != 0)))) {
      picOffset = 0x8284;
      textureDesc = DAT_0000e748 + 0xc;
      if (fillKind != 0x6000) {
        _fillTextureWithPattern(patternBuf,fillKind,*fillReq,fillReq[1]);
      }
      else {
        _fillTextureWithPattern(patternBuf,0x6000,patternBuf,patternBuf);
      }
      cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (cmdBuffer + 0x20) >> 2);
      if (fillReq[0x16] != 0) {
        colorBits = fillColor & 0x7c00;
        maskBit = (fillFlags & 0xc000) >> 0xe & 1;
        rectIndex = 0;
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
          texOriginUInt = (dstLeft & 7) + fillReq[2];
          texOriginVInt = (dstTop & 7) + fillReq[3];
          i2dHi5 = 0x43300000;
          i2dHi6 = 0x43300000;
          texOriginU = (float)((double)CONCAT44(0x43300000,texOriginUInt) - 4503599627370496.0);
          texOriginV = (float)((double)CONCAT44(0x43300000,texOriginVInt) - 4503599627370496.0);
          if (dstTop < dstBottom) {
            firstTileRightUnclamped = dstLeft + 8;
            tileRightLimit = dstRight;
            if (firstTileRightUnclamped < dstRight) {
              tileRightLimit = firstTileRightUnclamped;
            }
            i2dHi10 = 0x43300000;
            firstTile = true;
            fillRed5 = colorBits >> 10;
            fillRed5D = (double)CONCAT44(0x43300000,fillRed5);
            tileRowTop = dstTop;
            do {
              tileTop = tileRowTop;
              if (dstLeft < dstRight) {
                if (!firstTile) {
                  quadSlot0Ptr = &quadSlot0;
                  i2dHi7 = 0x43300000;
                  i2dHi8 = 0x43300000;
                  tileTopSpill2 = tileTop;
                  tileBottomSpill2 = tileBottom;
                  tileBottomHi = tileBottom << 0x10;
                  quadSlot3Ptr = &quadSlot3;
                  quadSlot4Ptr = &quadSlot4;
                  tileTopHi = tileTop << 0x10;
                  quadSlot2Ptr = &quadSlot2;
                  quadSlot6Ptr = &quadSlot6;
                  scratchWord2Ref = &scratchWord2;
                  quadSlot5Ptr = &quadSlot5;
                  quadSlot1Ptr = &quadSlot1;
                  tileHeight = tileBottom - tileTop;
                  tileTopF = (float)((double)CONCAT44(0x43300000,tileTop) - 4503599627370496.0);
                  tileBottomF = (float)((double)CONCAT44(0x43300000,tileBottom) - 4503599627370496.0);
                  tileRowTopNext = firstTileRightUnclamped;
                  tileLeft = dstLeft;
                  tileRight = tileRightLimit;
                  goto LAB_00008bec;
                }
                nextTileLeft = firstTileRightUnclamped;
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
                  mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord0,&scratchWord1,1);
                  curTileLeft = dstLeft;
                  if (mapResult == 0) {
                    quadSlot1Ptr = &quadSlot1;
                    quadSlot3Ptr = &quadSlot3;
                    scratchWord2Ref = &scratchWord2;
                    *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                    quadSlot0Ptr = &quadSlot0;
                    quadSlot2Ptr = &quadSlot2;
                    quadSlot4Ptr = &quadSlot4;
                    quadSlot6Ptr = &quadSlot6;
                    tileTopHi = tileTop << 0x10;
                    tileBottomHi = tileBottom << 0x10;
                    cmdWrite = (dword *)(scratchWord0 + 0x20);
                    streamCursor = (dword *)(scratchWord0 + 0x38);
                    tileWord1 = (dword *)(scratchWord0 + 0x24);
                    quadSlot5Ptr = &quadSlot5;
                    tileWord3 = (dword *)(scratchWord0 + 0x2c);
                    tileWord2 = (dword *)(scratchWord0 + 0x28);
                    tileHeight = tileBottom - tileTop;
                    tileWord4 = (dword *)(scratchWord0 + 0x30);
                    tileWord5 = (dword *)(scratchWord0 + 0x34);
                    *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                    *(uint *)(accel + 0x18) = scratchWord0;
                    cmdWordsLeft = cmdCapacity;
                    tileRight = tileRightLimit;
                  }
                  else {
                    scratchWord2Ref = &scratchWord2;
                    quadSlot3Ptr = &quadSlot3;
                    quadSlot1Ptr = &quadSlot1;
                    quadSlot0Ptr = &quadSlot0;
                    cmdWrite = (dword *)0x0;
                    quadSlot2Ptr = &quadSlot2;
                    quadSlot4Ptr = &quadSlot4;
                    tileWord1 = &__mh_bundle_header.cputype;
                    tileBottomHi = tileBottom << 0x10;
                    quadSlot6Ptr = &quadSlot6;
                    tileWord2 = &__mh_bundle_header.cpusubtype;
                    tileWord3 = &__mh_bundle_header.filetype;
                    tileWord4 = &__mh_bundle_header.ncmds;
                    tileWord5 = &__mh_bundle_header.sizeofcmds;
                    streamCursor = &__mh_bundle_header.flags;
                    tileTopHi = tileTop << 0x10;
                    quadSlot5Ptr = &quadSlot5;
                    tileHeight = tileBottom - tileTop;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdWordsLeft = cmdCapacity;
                    tileRight = tileRightLimit;
                  }
                }
                else {
                  scratchWord2Ref = &scratchWord2;
                  quadSlot3Ptr = &quadSlot3;
                  quadSlot1Ptr = &quadSlot1;
                  quadSlot0Ptr = &quadSlot0;
                  tileWord1 = cmdWrite + 1;
                  tileWord2 = cmdWrite + 2;
                  quadSlot2Ptr = &quadSlot2;
                  tileWord3 = cmdWrite + 3;
                  quadSlot4Ptr = &quadSlot4;
                  tileWord4 = cmdWrite + 4;
                  tileBottomHi = tileBottom << 0x10;
                  quadSlot6Ptr = &quadSlot6;
                  tileWord5 = cmdWrite + 5;
                  streamCursor = cmdWrite + 6;
                  tileTopHi = tileTop << 0x10;
                  quadSlot5Ptr = &quadSlot5;
                  tileHeight = tileBottom - tileTop;
                  curTileLeft = dstLeft;
                  tileRight = tileRightLimit;
                }
                do {
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = cmdWrite;
                  *cmdWrite = 0xa000000;
                  *tileWord1 = *(dword *)(accel + 0x84);
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)tileWord2 - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = tileWord2;
                  *tileWord2 = 0x10000000;
                  *tileWord3 = *(dword *)*DAT_0000e6e4;
                  *tileWord4 = DAT_0000e6e4[7];
                  if (DAT_0000e6c0 == 0x10) {
                    *tileWord5 = 3;
                  }
                  else {
                    *tileWord5 = 6;
                  }
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)streamCursor - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = streamCursor;
                  *streamCursor = 0x13000000;
                  streamCursor[1] = *(undefined4 *)**(undefined4 **)(picOffset + 0x64c4);
                  streamCursor[2] = 0;
                  cmdWrite = streamCursor + 4;
                  streamCursor[3] = 0;
                  screenFormat = *(int *)(accel + 0x70);
                  cmdWordsLeft = cmdWordsLeft - 10;
                  *cmdWrite = 0x850;
                  streamCursor[5] = 0x100;
                  streamCursor[6] = 0x887;
                  streamCursor[7] = 0x1c000;
                  streamCursor[8] = 0x82c;
                  streamCursor[9] = 0;
                  streamCursor[10] = 0x1002;
                  streamCursor[0xb] = 0;
                  streamCursor[0xc] = 0x824;
                  streamCursor[0xd] = 1;
                  streamCursor[0xe] = 0x825;
                  streamCursor[0xf] = 0x12;
                  streamCursor[0x10] = 0x82d;
                  streamCursor[0x11] = 5;
                  streamCursor[0x12] = 0x854;
                  streamCursor[0x13] = 0x6010006;
                  streamCursor[0x14] = 0x855;
                  streamCursor[0x15] = 0x2701;
                  streamCursor[0x16] = 0x878;
                  streamCursor[0x17] = 0xf688f688;
                  streamCursor[0x18] = 0x879;
                  streamCursor[0x19] = 0xfb24f688;
                  streamCursor[0x1a] = 0x10a2;
                  streamCursor[0x1b] = 0;
                  streamCursor[0x1c] = 0x1381;
                  streamCursor[0x1d] = 0;
                  streamCursor[0x1e] = 0x109e;
                  streamCursor[0x1f] = 5;
                  streamCursor[0x20] = 0x1383;
                  streamCursor[0x21] = 0xf;
                  streamCursor[0x22] = 0x1004;
                  streamCursor[0x23] = 0x66666666;
                  streamCursor[0x24] = 0x1005;
                  streamCursor[0x25] = 0x66666666;
                  streamCursor[0x26] = 0x10ae;
                  streamCursor[0x27] = 0;
                  streamCursor[0x28] = 0x10ea;
                  streamCursor[0x29] = 0x2da49525;
                  streamCursor[0x2a] = 0x10fa;
                  streamCursor[0x2b] = 0xffffff;
                  streamCursor[0x2c] = 0x10f4;
                  streamCursor[0x2d] = 0xffff;
                  streamCursor[0x2e] = 0x10f8;
                  streamCursor[0x2f] = 0;
                  streamCursor[0x30] = 0x10f9;
                  streamCursor[0x31] =
                       *(uint *)(accel + 0x54) & 0x1fff |
                       (*(uint *)(accel + 0x58) & 0x1fff) << 0xd;
                  streamCursor[0x32] = 0x13c0;
                  streamCursor[0x33] = 0;
                  streamCursor[0x34] = 0x13c1;
                  streamCursor[0x35] = 0;
                  streamCursor[0x36] = 0x10c0;
                  streamCursor[0x37] = 0x40004;
                  streamCursor[0x38] = 0x10c1;
                  streamCursor[0x39] = 1;
                  streamCursor[0x3a] = 0x10c8;
                  streamCursor[0x3b] = 0x10;
                  streamCursor[0x3c] = 0x10c9;
                  streamCursor[0x3d] = 0x31;
                  streamCursor[0x3e] = 0x101d;
                  streamCursor[0x3f] = 0x28ffe040;
                  streamCursor[0x40] = 0x101e;
                  streamCursor[0x41] = 0x28ffe0c2;
                  streamCursor[0x42] = 0x1041;
                  streamCursor[0x43] = 3;
                  streamCursor[0x44] = 0x1040;
                  streamCursor[0x45] = 0;
                  streamCursor[0x46] = 0x1100;
                  streamCursor[0x47] = 0x2a92;
                  streamCursor[0x48] = 0x1101;
                  streamCursor[0x49] = 0x10002a92;
                  streamCursor[0x4a] = 0x1120;
                  screenWidth = *(short *)(accel + 0x50);
                  screenHeight = *(short *)(accel + 0x52);
                  streamCursor[0x4b] =
                       (int)screenWidth - 1U & 0x7ff | (screenHeight + -1) * 0x800 & 0x3ff800U | 0x80000000
                  ;
                  streamCursor[0x4c] = 0x1121;
                  textureWidthM1 = (int)*(short *)(textureDesc + 4) - 1;
                  textureHeightM1 = *(short *)(textureDesc + 6) + -1;
                  streamCursor[0x4d] = textureWidthM1 & 0x7ff | textureHeightM1 * 0x800 & 0x3ff800U | 0x80000000;
                  streamCursor[0x4e] = 0x1130;
                  surfaceFormatWord = 0x5300c - (uint)(screenFormat == 3);
                  streamCursor[0x4f] = surfaceFormatWord;
                  streamCursor[0x50] = 0x1131;
                  streamCursor[0x51] = surfaceFormatWord;
                  streamCursor[0x52] = 0x1140;
                  streamCursor[0x53] =
                       *(int *)(accel + 0x5c) - 1U & 0x3fff | ((int)screenWidth - 1U) * 0x10 & 0x8000
                       | (screenHeight + -1) * 0x20 & 0x10000U;
                  streamCursor[0x54] = 0x1141;
                  streamCursor[0x55] =
                       *(int *)(textureDesc + 0x10) - 1U & 0x3fff | textureWidthM1 * 0x10 & 0x8000 |
                       textureHeightM1 * 0x20 & 0x10000U;
                  if (noMaskFlags) {
                    progIdx82 = 0x52;
                    progByteOff82 = 0x148;
                    progIdx86 = 0x56;
                    progIdx87 = 0x57;
                    progIdx88 = 0x58;
                    progIdx89 = 0x59;
                    progIdx90 = 0x5a;
                    progIdx91 = 0x5b;
                    progIdx92 = 0x5c;
                    progIdx93 = 0x5d;
                    progIdx95 = 0x5f;
                    progIdx94 = 0x5e;
                    progIdx83 = 0x53;
                    progIdx84 = 0x54;
                    progIdx96 = 0x60;
                    progIdx85 = 0x55;
                    progIdx97 = 0x61;
                    progIdx98 = 0x62;
                    progIdx99 = 99;
                    progIdx100 = 100;
                    progIdx101 = 0x65;
                    progIdx102 = 0x66;
                    progIdx103 = 0x67;
                    progIdx104 = 0x68;
                    progIdx105 = 0x69;
                    progIdx106 = 0x6a;
                    progIdx107 = 0x6b;
                    streamIdxBase = 0x6c;
                  }
                  else {
                    if (screenFormat == 3) {
                      fillGreen5 = fillColor >> 5 & 0x1f;
                      fillBlue5 = fillColor & 0x1f;
                      fillAlpha1 = fillColor >> 0xf & 1;
                      i2dHi11 = 0x43300000;
                      i2dHi12 = 0x43300000;
                      i2dHi9 = 0x43300000;
                      fillRedF = (float)(fillRed5D - 4503599627370496.0) / 31.0;
                      fillGreenF = (float)((double)CONCAT44(0x43300000,fillGreen5) -
                                         4503599627370496.0) / 31.0;
                      fillBlueF = (float)((double)CONCAT44(0x43300000,fillBlue5) -
                                         4503599627370496.0) / 31.0;
                      fillAlphaF = (float)((double)CONCAT44(0x43300000,fillAlpha1) -
                                         4503599627370496.0);
                    }
                    else {
                      fillAlpha8 = fillColor >> 0x18;
                      fillRed8 = fillColor >> 0x10 & 0xff;
                      fillBlue8 = fillColor & 0xff;
                      fillGreen8 = fillColor >> 8 & 0xff;
                      i2dHi13 = 0x43300000;
                      i2dHi14 = 0x43300000;
                      i2dHi15 = 0x43300000;
                      i2dHi16 = 0x43300000;
                      fillAlphaF = (float)((double)CONCAT44(0x43300000,fillAlpha8) -
                                         4503599627370496.0) / 255.0;
                      fillRedF = (float)((double)CONCAT44(0x43300000,fillRed8) -
                                         4503599627370496.0) / 255.0;
                      fillBlueF = (float)((double)CONCAT44(0x43300000,fillBlue8) -
                                         4503599627370496.0) / 255.0;
                      fillGreenF = (float)((double)CONCAT44(0x43300000,fillGreen8) -
                                         4503599627370496.0) / 255.0;
                    }
                    streamCursor[0x56] = 0x1094;
                    streamCursor[0x57] = 0x10000;
                    streamCursor[0x58] = 0x1095;
                    streamCursor[0x59] = (dword)GH_F2U(fillRedF);
                    streamCursor[0x5a] = 0x1095;
                    streamCursor[0x5b] = (dword)GH_F2U(fillGreenF);
                    streamCursor[0x5c] = 0x1095;
                    streamCursor[0x5d] = (dword)GH_F2U(fillBlueF);
                    streamCursor[0x5e] = 0x1095;
                    streamCursor[0x5f] = (dword)GH_F2U(fillAlphaF);
                    progIdx82 = 0x5c;
                    progByteOff82 = 0x170;
                    progIdx86 = 0x60;
                    progIdx87 = 0x61;
                    progIdx88 = 0x62;
                    progIdx89 = 99;
                    progIdx90 = 100;
                    progIdx91 = 0x65;
                    progIdx92 = 0x66;
                    progIdx93 = 0x67;
                    progIdx95 = 0x69;
                    progIdx94 = 0x68;
                    progIdx83 = 0x5d;
                    progIdx84 = 0x5e;
                    progIdx96 = 0x6a;
                    progIdx85 = 0x5f;
                    progIdx97 = 0x6b;
                    progIdx98 = 0x6c;
                    progIdx99 = 0x6d;
                    progIdx100 = 0x6e;
                    progIdx101 = 0x6f;
                    progIdx102 = 0x70;
                    progIdx103 = 0x71;
                    progIdx104 = 0x72;
                    progIdx105 = 0x73;
                    progIdx106 = 0x74;
                    progIdx107 = 0x75;
                    streamIdxBase = 0x76;
                  }
                  *(undefined4 *)((int)cmdWrite + progByteOff82) = 0x1094;
                  cmdWrite[progIdx83] = 0;
                  cmdWrite[progIdx84] = 0x1095;
                  cmdWrite[progIdx85] = 0x7803;
                  cmdWrite[progIdx86] = 0x1095;
                  cmdWrite[progIdx87] = 0x2410000;
                  cmdWrite[progIdx88] = 0x1095;
                  cmdWrite[progIdx89] = 0x3901e401;
                  cmdWrite[progIdx90] = 0x1095;
                  cmdWrite[progIdx91] = 0;
                  cmdWrite[progIdx92] = 0x1095;
                  cmdWrite[progIdx93] = 0;
                  cmdWrite[progIdx94] = 0x1095;
                  cmdWrite[progIdx95] = 0;
                  if (noMaskFlags) {
                    cmdWrite[progIdx96] = 0x1095;
                    cmdWrite[progIdx97] = 0x78105;
                    cmdWrite[progIdx98] = 0x1095;
                    cmdWrite[progIdx99] = 1;
                    cmdWrite[progIdx100] = 0x1095;
                    cmdWrite[progIdx101] = 1;
                    cmdWrite[progIdx102] = 0x1095;
                    cmdWrite[progIdx103] = 0xdb0220;
                    cmdWrite[progIdx104] = 0x1095;
                    cmdWrite[progIdx105] = 0xc0c006;
                    cmdWrite[progIdx106] = 0x1095;
                    cmdWrite[progIdx107] = 0x20490000;
                  }
                  else {
                    cmdWrite[progIdx96] = 0x1095;
                    cmdWrite[progIdx97] = 0x7807;
                    cmdWrite[progIdx98] = 0x1095;
                    cmdWrite[progIdx99] = 0x2400000;
                    cmdWrite[progIdx100] = 0x1095;
                    cmdWrite[progIdx101] = 0x3900e400;
                    cmdWrite[progIdx102] = 0x1095;
                    cmdWrite[progIdx103] = 0;
                    cmdWrite[progIdx104] = 0x1095;
                    cmdWrite[progIdx105] = 0;
                    cmdWrite[progIdx106] = 0x1095;
                    cmdWrite[progIdx107] = 0;
                    cmdWrite[streamIdxBase] = 0x1095;
                    cmdWrite[progIdx82 + 0x1b] = 0x7804;
                    cmdWrite[progIdx82 + 0x1c] = 0x1095;
                    cmdWrite[progIdx82 + 0x1d] = 0x40040000;
                    cmdWrite[progIdx82 + 0x1e] = 0x1095;
                    cmdWrite[progIdx82 + 0x1f] = 0x40040000;
                    cmdWrite[progIdx82 + 0x20] = 0x1095;
                    cmdWrite[progIdx82 + 0x21] = 0xdb0490;
                    cmdWrite[progIdx82 + 0x22] = 0x1095;
                    cmdWrite[progIdx82 + 0x23] = 0xc10026;
                    cmdWrite[progIdx82 + 0x24] = 0x1095;
                    cmdWrite[progIdx82 + 0x25] = 0xdfa23028;
                    cmdWrite[progIdx82 + 0x26] = 0x1095;
                    cmdWrite[progIdx82 + 0x27] = 0x7800;
                    cmdWrite[progIdx82 + 0x28] = 0x1095;
                    cmdWrite[progIdx82 + 0x29] = 2;
                    cmdWrite[progIdx82 + 0x2a] = 0x1095;
                    cmdWrite[progIdx82 + 0x2b] = 2;
                    cmdWrite[progIdx82 + 0x2c] = 0x1095;
                    cmdWrite[progIdx82 + 0x2d] = 0xdb0220;
                    cmdWrite[progIdx82 + 0x2e] = 0x1095;
                    cmdWrite[progIdx82 + 0x2f] = 0xc0c021;
                    cmdWrite[progIdx82 + 0x30] = 0x1095;
                    cmdWrite[progIdx82 + 0x31] = 0x22;
                    cmdWrite[progIdx82 + 0x32] = 0x1095;
                    cmdWrite[progIdx82 + 0x33] = 0x78101;
                    cmdWrite[progIdx82 + 0x34] = 0x1095;
                    maskCtlWord = (maskBit ^ 1) << 10 | maskBit | 0x200000;
                    cmdWrite[progIdx82 + 0x35] = maskCtlWord;
                    cmdWrite[progIdx82 + 0x36] = 0x1095;
                    cmdWrite[progIdx82 + 0x37] = maskCtlWord;
                    cmdWrite[progIdx82 + 0x38] = 0x1095;
                    cmdWrite[progIdx82 + 0x39] = 0x440221;
                    cmdWrite[progIdx82 + 0x3a] = 0x1095;
                    cmdWrite[progIdx82 + 0x3b] = 0x60d006;
                    cmdWrite[progIdx82 + 0x3c] = 0x1095;
                    streamIdxBase = progIdx82 + 0x3e;
                    cmdWrite[progIdx82 + 0x3d] = 0xdda22008;
                  }
                  cmdWrite[streamIdxBase] = 0x1189;
                  cmdWrite[streamIdxBase + 1] = 0;
                  cmdWrite[streamIdxBase + 2] = 0x1181;
                  cmdWrite[streamIdxBase + 3] = 5;
                  cmdWrite[streamIdxBase + 4] = 0x118d;
                  if (noMaskFlags) {
                    maskWord = 0x10000;
                  }
                  else {
                    maskWord = 0x40000;
                  }
                  cmdWrite[streamIdxBase + 5] = maskWord;
                  cmdWrite[streamIdxBase + 6] = 0x118e;
                  cmdWrite[streamIdxBase + 7] = 0;
                  cmdWrite[streamIdxBase + 8] = 0x118c;
                  if (noMaskFlags) {
                    maskWord = 0x10000;
                  }
                  else {
                    maskWord = 0x40000;
                  }
                  cmdWrite[streamIdxBase + 9] = maskWord;
                  cmdWrite[streamIdxBase + 10] = 0x11a9;
                  cmdWrite[streamIdxBase + 0xb] = 0x1b01;
                  cmdWrite[streamIdxBase + 0xc] = 0x11aa;
                  cmdWrite[streamIdxBase + 0xd] = 0xf;
                  cmdWrite[streamIdxBase + 0xe] = 0x11ab;
                  cmdWrite[streamIdxBase + 0xf] = 0xf;
                  cmdWrite[streamIdxBase + 0x10] = 0x11ac;
                  cmdWrite[streamIdxBase + 0x11] = 0xf;
                  cmdWrite[streamIdxBase + 0x12] = 0x12f0;
                  cmdWrite[streamIdxBase + 0x13] = 0;
                  cmdWrite[streamIdxBase + 0x14] = 0x12f5;
                  cmdWrite[streamIdxBase + 0x15] = 0;
                  fillQuadFormatIdx = streamIdxBase + 0x17;
                  fillQuadVtx0PosIdx = streamIdxBase + 0x18;
                  tileIdx26 = streamIdxBase + 0x30;
                  i2dHi17 = 0x43300000;
                  i2dHi18 = 0x43300000;
                  tileIdx4 = streamIdxBase + 0x1a;
                  tileIdx3 = streamIdxBase + 0x19;
                  tileTopSpill = tileTop;
                  tileBottomSpill = tileBottom;
                  fillQuadVtx1ScrUIdx = streamIdxBase + 0x1e;
                  fillQuadVtx1ScrVIdx = streamIdxBase + 0x1f;
                  fillQuadVtx0TexUIdx = streamIdxBase + 0x1b;
                  fillQuadVtx2PosIdx = streamIdxBase + 0x22;
                  fillQuadVtx2ScrVIdx = streamIdxBase + 0x24;
                  tileHdrByteOff = (streamIdxBase + 0x16) * 4;
                  fillQuadVtx1PosIdx = streamIdxBase + 0x1d;
                  fillQuadVtx1TexUIdx = streamIdxBase + 0x20;
                  tileIdx6 = streamIdxBase + 0x1c;
                  fillQuadVtx1TexVIdx = streamIdxBase + 0x21;
                  tileIdx15 = streamIdxBase + 0x25;
                  tileIdx16 = streamIdxBase + 0x26;
                  tileIdx13 = streamIdxBase + 0x23;
                  tileIdx17 = streamIdxBase + 0x27;
                  tileIdx18 = streamIdxBase + 0x28;
                  tileIdx19 = streamIdxBase + 0x29;
                  tileIdx20 = streamIdxBase + 0x2a;
                  tileIdx21 = streamIdxBase + 0x2b;
                  tileIdx22 = streamIdxBase + 0x2c;
                  tileIdx23 = streamIdxBase + 0x2d;
                  tileIdx24 = streamIdxBase + 0x2e;
                  streamIdxBase = streamIdxBase + 0x2f;
                  tileTopF = (float)((double)CONCAT44(0x43300000,tileTop) - 4503599627370496.0);
                  tileBottomF = (float)((double)CONCAT44(0x43300000,tileBottom) - 4503599627370496.0);
                  while( true ) {
                    tileRightSpill = tileRight;
                    i2dHi21 = 0x43300000;
                    i2dHi22 = 0x43300000;
                    i2dHi19 = 0x43300000;
                    i2dHi20 = 0x43300000;
                    i2dLo5 = (int)screenWidth ^ 0x80000000;
                    i2dLo6 = (int)screenHeight ^ 0x80000000;
                    quadSlot1 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo5) -
                                             4503601774854144.0);
                    quadSlot2 = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo6) -
                                             4503601774854144.0);
                    quadSlot0 = quadSlot1 *
                                (float)((double)CONCAT44(0x43300000,curTileLeft) - 4503599627370496.0
                                       );
                    quadSlot1 = quadSlot1 *
                                (float)((double)CONCAT44(0x43300000,tileRight) - 4503599627370496.0)
                    ;
                    quadSlot3 = (uint)GH_F2U((float)((quadSlot2 * tileBottomF)));
                    quadSlot2 = quadSlot2 * tileTopF;
                    *(undefined4 *)((int)cmdWrite + tileHdrByteOff) = 0xc0143500;
                    cmdWrite[fillQuadFormatIdx] = 0x4003d;
                    tileWidth = tileRight - curTileLeft;
                    if ((tileWidth == 8) && (tileHeight == 8)) {
                      i2dHi29 = 0x43300000;
                      i2dLo11 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      quadSlot4 = (texOriginU + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo11) -
                                                4503601774854144.0));
                      i2dHi30 = 0x43300000;
                      i2dLo12 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      quadSlot5 = (texOriginU + 8.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo12) -
                                                4503601774854144.0));
                      i2dHi31 = 0x43300000;
                      i2dLo13 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      quadSlot6 = (texOriginV + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo13) -
                                                4503601774854144.0));
                      i2dHi32 = 0x43300000;
                      i2dLo14 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      scratchWord2 = (uint)GH_F2U((float)(((texOriginV + 8.0) *
                                        (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo14) -
                                                      4503601774854144.0)))));
                    }
                    else {
                      i2dHi23 = 0x43300000;
                      i2dHi24 = 0x43300000;
                      i2dLo7 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      quadSlot4 = (texOriginU + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo7) -
                                                4503601774854144.0));
                      i2dHi25 = 0x43300000;
                      i2dLo8 = (int)*(short *)(textureDesc + 4) ^ 0x80000000;
                      quadSlot5 = (texOriginU + (float)((double)CONCAT44(0x43300000,tileWidth) -
                                                  4503599627370496.0)) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo8) -
                                                4503601774854144.0));
                      i2dHi26 = 0x43300000;
                      tileHeightSpill = tileHeight;
                      i2dHi27 = 0x43300000;
                      i2dLo9 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      quadSlot6 = (texOriginV + 0.0) *
                                  (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo9) -
                                                4503601774854144.0));
                      i2dHi28 = 0x43300000;
                      i2dLo10 = (int)*(short *)(textureDesc + 6) ^ 0x80000000;
                      scratchWord2 = (uint)GH_F2U((float)(((texOriginV + (float)((double)CONCAT44(0x43300000,tileHeight) -
                                                         4503599627370496.0)) *
                                        (1.0 / (float)((double)CONCAT44(0x43300000,i2dLo10) -
                                                      4503601774854144.0)))));
                      tileWidthSpill = tileWidth;
                    }
                    cmdWrite[fillQuadVtx0PosIdx] = curTileLeft | tileBottomHi;
                    scrU0 = *quadSlot0Ptr;
                    cmdWrite[tileIdx3] = (dword)GH_F2U(scrU0);
                    scrV1Bits = *quadSlot3Ptr;
                    cmdWrite[tileIdx4] = scrV1Bits;
                    texU0 = *quadSlot4Ptr;
                    cmdWrite[fillQuadVtx0TexUIdx] = (dword)GH_F2U(texU0);
                    texV1Bits = *scratchWord2Ref;
                    cmdWrite[tileIdx6] = texV1Bits;
                    cmdWrite[fillQuadVtx1PosIdx] = curTileLeft | tileTopHi;
                    cmdWrite[fillQuadVtx1ScrUIdx] = (dword)GH_F2U(scrU0);
                    scrV0 = *quadSlot2Ptr;
                    cmdWrite[fillQuadVtx1ScrVIdx] = (dword)GH_F2U(scrV0);
                    cmdWrite[fillQuadVtx1TexUIdx] = (dword)GH_F2U(texU0);
                    texV0 = *quadSlot6Ptr;
                    cmdWrite[fillQuadVtx1TexVIdx] = (dword)GH_F2U(texV0);
                    cmdWrite[fillQuadVtx2PosIdx] = tileRight | tileTopHi;
                    scrU1 = *quadSlot1Ptr;
                    cmdWrite[tileIdx13] = (dword)GH_F2U(scrU1);
                    cmdWrite[fillQuadVtx2ScrVIdx] = (dword)GH_F2U(scrV0);
                    texU1 = *quadSlot5Ptr;
                    cmdWrite[tileIdx15] = (dword)GH_F2U(texU1);
                    cmdWrite[tileIdx16] = (dword)GH_F2U(texV0);
                    cmdWrite[tileIdx17] = tileRight | tileBottomHi;
                    cmdWrite[tileIdx18] = (dword)GH_F2U(scrU1);
                    cmdWrite[tileIdx19] = scrV1Bits;
                    cmdWrite[tileIdx20] = (dword)GH_F2U(texU1);
                    cmdWrite[tileIdx21] = texV1Bits;
                    cmdWrite[tileIdx22] = 0x1393;
                    cmdWrite[tileIdx23] = 10;
                    cmdWrite[tileIdx24] = 0x5c8;
                    cmdWrite[streamIdxBase] = 0x20000;
                    cmdWordsLeft = cmdWordsLeft - tileIdx26;
                    cmdWrite = cmdWrite + tileIdx26;
                    tileRight = dstRight;
                    if (curTileLeft + 0x10 < dstRight) {
                      tileRight = curTileLeft + 0x10;
                    }
                    firstTile = false;
                    if (dstRight <= nextTileLeft) goto LAB_0000a09c;
                    tileRowTopNext = nextTileLeft + 8;
                    tileLeft = nextTileLeft;
LAB_00008bec:
                    if (cmdWordsLeft < 0x1a) break;
                    screenWidth = *(short *)(accel + 0x50);
                    tileIdx16 = 0x10;
                    tileIdx26 = 0x1a;
                    tileIdx15 = 0xf;
                    streamIdxBase = 0x19;
                    tileIdx24 = 0x18;
                    tileIdx23 = 0x17;
                    tileIdx22 = 0x16;
                    tileIdx21 = 0x15;
                    tileIdx20 = 0x14;
                    tileIdx19 = 0x13;
                    tileIdx18 = 0x12;
                    tileIdx17 = 0x11;
                    tileIdx13 = 0xd;
                    tileIdx6 = 6;
                    tileIdx4 = 4;
                    screenHeight = *(short *)(accel + 0x52);
                    fillQuadVtx2ScrVIdx = 0xe;
                    fillQuadVtx2PosIdx = 0xc;
                    fillQuadVtx1TexUIdx = 10;
                    fillQuadVtx1ScrVIdx = 9;
                    fillQuadVtx1ScrUIdx = 8;
                    fillQuadVtx1PosIdx = 7;
                    fillQuadVtx1TexVIdx = 0xb;
                    fillQuadVtx0PosIdx = 2;
                    tileIdx3 = 3;
                    fillQuadVtx0TexUIdx = 5;
                    fillQuadFormatIdx = 1;
                    tileHdrByteOff = 0;
                    nextTileLeft = tileRowTopNext;
                    curTileLeft = tileLeft;
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
                  mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord1,&scratchWord0,1);
                  if (mapResult == 0) {
                    *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                    *(uint *)(accel + 0x18) = scratchWord1;
                    cmdWrite = (dword *)(scratchWord1 + 0x20);
                    streamCursor = (dword *)(scratchWord1 + 0x38);
                    *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                    tileWord1 = (dword *)(scratchWord1 + 0x24);
                    tileWord2 = (dword *)(scratchWord1 + 0x28);
                    tileWord3 = (dword *)(scratchWord1 + 0x2c);
                    tileWord4 = (dword *)(scratchWord1 + 0x30);
                    tileWord5 = (dword *)(scratchWord1 + 0x34);
                    nextTileLeft = tileLeft + 8;
                    curTileLeft = tileLeft;
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    streamCursor = &__mh_bundle_header.flags;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    tileWord5 = &__mh_bundle_header.sizeofcmds;
                    tileWord4 = &__mh_bundle_header.ncmds;
                    tileWord3 = &__mh_bundle_header.filetype;
                    tileWord2 = &__mh_bundle_header.cpusubtype;
                    tileWord1 = &__mh_bundle_header.cputype;
                    cmdWrite = (dword *)0x0;
                    nextTileLeft = tileLeft + 8;
                    curTileLeft = tileLeft;
                    cmdWordsLeft = cmdCapacity;
                  }
                } while( true );
              }
LAB_0000a09c:
              tileBottom = dstBottom;
              if (tileTop + 0x10 < dstBottom) {
                tileBottom = tileTop + 0x10;
              }
              tileRowTop = tileTop + 8;
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
            mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&scratchWord0,&scratchWord1,1);
            if (mapResult == 0) {
              *(undefined4 *)(scratchWord0 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = scratchWord0;
              cmdWrite = (dword *)(scratchWord0 + 0x20);
              finalCursor = (dword *)(scratchWord0 + 0x38);
              *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
              finalWord1 = (dword *)(scratchWord0 + 0x24);
              finalWord2 = (dword *)(scratchWord0 + 0x28);
              finalWord3 = (dword *)(scratchWord0 + 0x2c);
              finalWord4 = (dword *)(scratchWord0 + 0x30);
              finalWord5 = (dword *)(scratchWord0 + 0x34);
              cmdWordsLeft = cmdCapacity;
            }
            else {
              cmdWrite = (dword *)0x0;
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              finalWord1 = &__mh_bundle_header.cputype;
              finalWord2 = &__mh_bundle_header.cpusubtype;
              finalWord3 = &__mh_bundle_header.filetype;
              finalWord4 = &__mh_bundle_header.ncmds;
              finalWord5 = &__mh_bundle_header.sizeofcmds;
              finalCursor = &__mh_bundle_header.flags;
              cmdWordsLeft = cmdCapacity;
            }
          }
          else {
            finalWord1 = cmdWrite + 1;
            finalWord2 = cmdWrite + 2;
            finalWord3 = cmdWrite + 3;
            finalWord4 = cmdWrite + 4;
            finalWord5 = cmdWrite + 5;
            finalCursor = cmdWrite + 6;
          }
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = cmdWrite;
          *cmdWrite = 0x11000000;
          *finalWord1 = *(dword *)(accel + 0x84);
          *finalWord2 = 0;
          *finalWord3 = 0;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = (int)finalWord4 - (int)lastHeader >> 2 | *lastHeader;
          *(dword **)(accel + 0x7c) = finalWord4;
          *finalWord4 = 0x4000000;
          *finalWord5 = *(dword *)*DAT_0000e6e4;
          patternDesc = DAT_0000e6e4;
          pass2Format = DAT_0000e6e4[0xc];
          if (pass2Format == 3) {
            pass2Format = 0xb;
          }
          else if (pass2Format == 6) {
            pass2Format = 0xc;
          }
          pass2SetupWords = ((int (*)())_radeon3DCopySetup)(accel,finalCursor,DAT_0000e6e4 + 3,pass2Format,0,0,0,0);
          dstLeftSpill = dstLeft;
          dstTopSpill = dstTop;
          dstRightSpill = dstRight;
          dstBottomSpill = dstBottom;
          i2dHi33 = 0x43300000;
          i2dHi34 = 0x43300000;
          i2dHi35 = 0x43300000;
          i2dHi36 = 0x43300000;
          finalCursor[pass2SetupWords] = 0xc00c3500;
          finalCursor[pass2SetupWords + 1] = 0x4003d;
          i2dHi37 = 0x43300000;
          i2dLo15 = (int)*(short *)(patternDesc + 4) ^ 0x80000000;
          quadSlot3 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstLeft) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo15) -
                                          4503601774854144.0))));
          i2dHi38 = 0x43300000;
          i2dLo16 = (int)*(short *)(patternDesc + 4) ^ 0x80000000;
          scratchWord2 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstRight) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo16) -
                                          4503601774854144.0))));
          i2dHi39 = 0x43300000;
          i2dLo17 = (int)*(short *)((int)patternDesc + 0x12) ^ 0x80000000;
          scratchWord1 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstTop) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo17) -
                                          4503601774854144.0))));
          i2dHi40 = 0x43300000;
          i2dLo18 = (int)*(short *)((int)patternDesc + 0x12) ^ 0x80000000;
          scratchWord0 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstBottom) -
                                                   4503599627370496.0) *
                                   (1.0 / ((double)CONCAT44(0x43300000,i2dLo18) -
                                          4503601774854144.0))));
          finalCursor[pass2SetupWords + 2] = dstLeft | dstBottom << 0x10;
          finalCursor[pass2SetupWords + 3] = quadSlot3;
          finalCursor[pass2SetupWords + 4] = scratchWord0;
          finalCursor[pass2SetupWords + 5] = dstLeft | dstTop << 0x10;
          finalCursor[pass2SetupWords + 6] = quadSlot3;
          finalCursor[pass2SetupWords + 7] = scratchWord1;
          finalCursor[pass2SetupWords + 8] = dstRight | dstTop << 0x10;
          finalCursor[pass2SetupWords + 9] = scratchWord2;
          finalCursor[pass2SetupWords + 10] = scratchWord1;
          finalCursor[pass2SetupWords + 0xb] = dstRight | dstBottom << 0x10;
          finalCursor[pass2SetupWords + 0xc] = scratchWord2;
          finalCursor[pass2SetupWords + 0xd] = scratchWord0;
          finalCursor[pass2SetupWords + 0xe] = 0x1393;
          finalCursor[pass2SetupWords + 0xf] = 10;
          finalCursor[pass2SetupWords + 0x10] = 0x5c8;
          finalCursor[pass2SetupWords + 0x11] = 0x20000;
          cmdWordsLeft = (cmdWordsLeft - 6) - (pass2SetupWords + 0x12);
          rectEntry = rectEntry + 4;
          cmdWrite = finalCursor + pass2SetupWords + 0x12;
          rectIndex = rectIndex + 1;
        } while (rectIndex < (uint)fillReq[0x16]);
      }
      *(dword **)(accel + 0x80) = cmdWrite;
      return 0;
    }
  }
  else {
    fastCmdWrite = *(undefined4 **)(accel + 0x80);
    cmdBufferSize = *(int *)(*(int *)(accel + 0x18) + 0x10);
    cmdCapacityFast = cmdBufferSize - 7;
    if (fastCmdWrite != (undefined4 *)0x0) {
      batchLimit = fillReq[0x16];
      cmdWordsLeft = cmdCapacityFast - ((int)fastCmdWrite - (*(int *)(accel + 0x18) + 0x20) >> 2);
      rectsPerBatch = (cmdBufferSize - 0x75U) / 0xc - 1;
      if (batchLimit != 0) {
        quadSlot2PtrB = &quadSlot2;
        batchWords = rectsPerBatch * 0xc + 0x6e;
        batchStart = 0;
        do {
          if (cmdWordsLeft < batchWords) {
            quadSlot3 = *(uint *)(accel + 0x18);
            scratchWord2 = 0;
            if (*(int *)(accel + 0x8c) == 0) {
              *fastCmdWrite = 0x5c8;
              scratchWord2 = 2;
              fastCmdWrite[1] = 0xc000;
              *(undefined4 *)(accel + 0x94) = 0;
            }
            fastCmdWrite[scratchWord2] = 0x1000000;
            lastHeader = *(uint **)(accel + 0x7c);
            *lastHeader = ((int)fastCmdWrite - (int)lastHeader >> 2) + scratchWord2 | *lastHeader;
            mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                         *(undefined4 *)PTR_0000e694,&quadSlot3,&scratchWord2,1);
            cmdWordsLeft = cmdCapacityFast;
            if (mapResult == 0) {
              *(undefined4 *)(quadSlot3 + 0x1c) = 0;
              *(uint *)(accel + 0x18) = quadSlot3;
              fastCmdWrite = (undefined4 *)(quadSlot3 + 0x20);
              *(uint *)(accel + 0x7c) = quadSlot3 + 0x1c;
              batchLimit = fillReq[0x16];
            }
            else {
              *(undefined4 *)(accel + 0x7c) = 0;
              *(undefined4 *)(accel + 0x18) = 0;
              fastCmdWrite = (undefined4 *)0x0;
              batchLimit = fillReq[0x16];
            }
          }
          batchEnd = batchStart + rectsPerBatch;
          if (batchEnd < batchLimit) {
            batchLimit = batchEnd;
          }
          fillSetupWords = ((int (*)())_radeon3DFillSetup)(fastCmdWrite,0,patternBuf,accel);
          batchRemaining = batchLimit - batchStart;
          fastCmdWrite[fillSetupWords] = batchRemaining * 0xc0000 | 0xc0003500;
          vtxIdxX0 = fillSetupWords + 2;
          fastCmdWrite[fillSetupWords + 1] = batchRemaining * 0x40000 | 0x3d;
          if (batchStart < batchLimit) {
            vtxByteOffZ0 = vtxIdxX0 * 4;
            originX = *(int *)(accel + 0x60);
            originY = *(int *)(accel + 100);
            vtxByteOffY0 = vtxByteOffZ0 + 4;
            vtxByteOffY3 = vtxByteOffZ0 + 0x28;
            vtxByteOffX3 = vtxByteOffZ0 + 0x24;
            rectPtr = fillReq + batchStart * 4 + 0x17;
            vtxByteOffZ2 = vtxByteOffZ0 + 0x20;
            vtxByteOffY2 = vtxByteOffZ0 + 0x1c;
            vtxByteOffX2 = vtxByteOffZ0 + 0x18;
            vtxByteOffZ1 = vtxByteOffZ0 + 0x14;
            vtxByteOffY1 = vtxByteOffZ0 + 0x10;
            vtxByteOffX1 = vtxByteOffZ0 + 0xc;
            vtxByteOffZ0 = vtxByteOffZ0 + 8;
            do {
              i2dHi1 = 0x43300000;
              i2dLo1 = *rectPtr + originX ^ 0x80000000;
              quadSlot3 = (uint)GH_F2U((float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0
                                       ));
              i2dHi2 = 0x43300000;
              i2dLo2 = *rectPtr + originX + rectPtr[2] ^ 0x80000000;
              quadSlot2 = (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
              i2dHi3 = 0x43300000;
              i2dLo3 = rectPtr[1] + originY ^ 0x80000000;
              quadSlot1 = (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
              i2dHi4 = 0x43300000;
              i2dLo4 = rectPtr[1] + originY + rectPtr[3] ^ 0x80000000;
              quadSlot0 = (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
              fastCmdWrite[vtxIdxX0] = quadSlot3;
              *(float *)((int)fastCmdWrite + vtxByteOffY0) = quadSlot0;
              *(undefined4 *)((int)fastCmdWrite + vtxByteOffZ0) = 0;
              *(uint *)((int)fastCmdWrite + vtxByteOffX1) = quadSlot3;
              *(float *)((int)fastCmdWrite + vtxByteOffY1) = quadSlot1;
              *(undefined4 *)((int)fastCmdWrite + vtxByteOffZ1) = 0;
              quadRightF = *quadSlot2PtrB;
              *(float *)((int)fastCmdWrite + vtxByteOffX2) = quadRightF;
              *(float *)((int)fastCmdWrite + vtxByteOffY2) = quadSlot1;
              *(undefined4 *)((int)fastCmdWrite + vtxByteOffZ2) = 0;
              *(float *)((int)fastCmdWrite + vtxByteOffX3) = quadRightF;
              *(float *)((int)fastCmdWrite + vtxByteOffY3) = quadSlot0;
              vtxIdxZ3 = vtxIdxX0 + 0xb;
              vtxByteOffY0 = vtxByteOffY0 + 0x30;
              vtxIdxX0 = vtxIdxX0 + 0xc;
              vtxByteOffZ0 = vtxByteOffZ0 + 0x30;
              vtxByteOffX1 = vtxByteOffX1 + 0x30;
              vtxByteOffY1 = vtxByteOffY1 + 0x30;
              vtxByteOffZ1 = vtxByteOffZ1 + 0x30;
              vtxByteOffX2 = vtxByteOffX2 + 0x30;
              vtxByteOffY2 = vtxByteOffY2 + 0x30;
              vtxByteOffZ2 = vtxByteOffZ2 + 0x30;
              vtxByteOffX3 = vtxByteOffX3 + 0x30;
              vtxByteOffY3 = vtxByteOffY3 + 0x30;
              fastCmdWrite[vtxIdxZ3] = 0;
              rectPtr = rectPtr + 4;
              batchRemaining = batchRemaining + -1;
            } while (batchRemaining != 0);
          }
          fastCmdWrite[vtxIdxX0] = 0x1393;
          fastCmdWrite[vtxIdxX0 + 1] = 10;
          fastCmdWrite[vtxIdxX0 + 2] = 0x5c8;
          fastCmdWrite[vtxIdxX0 + 3] = 0x20000;
          batchLimit = fillReq[0x16];
          cmdWordsLeft = cmdWordsLeft - (vtxIdxX0 + 4);
          fastCmdWrite = fastCmdWrite + vtxIdxX0 + 4;
          batchStart = batchEnd;
        } while (batchEnd < batchLimit);
      }
      *(undefined4 **)(accel + 0x80) = fastCmdWrite;
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
  int pass2SetupWords;
  short screenWidth;
  short screenHeight;
  uint *lastHeader;
  undefined4 result;
  uint cmdWordsLeft;
  dword *streamCursor;
  uint fillColor;
  uint *rectEntry;
  uint bottomRightPacked;
  uint topRightPacked;
  uint topLeftPacked;
  uint bottomLeftPacked;
  uint dstTop;
  uint dstRight;
  uint dstLeft;
  dword *cmdWrite;
  uint *puStack00000028;
  uint highlightColorHome;
  float scrU1Slot;
  float scrV0Slot;
  float scrV1Slot;
  uint scratchWord1;
  uint scratchWord0;
  float texV0Slot;
  float texU1Slot;
  float scrU0Pair [2];
  uint color1Alpha1;
  undefined4 i2dHi1;
  uint color1Red5;
  undefined4 i2dHi2;
  uint color1Green5;
  undefined4 i2dHi3;
  uint color1Blue5;
  undefined4 i2dHi4;
  uint color1Alpha8;
  undefined4 i2dHi5;
  uint color1Red8;
  undefined4 i2dHi6;
  uint color1Green8;
  undefined4 i2dHi7;
  uint color1Blue8;
  undefined4 i2dHi8;
  uint color2Alpha1;
  undefined4 i2dHi9;
  uint color2Red5;
  undefined4 i2dHi10;
  uint color2Green5;
  undefined4 i2dHi11;
  uint color2Blue5;
  undefined4 i2dHi12;
  uint color2Alpha8;
  undefined4 i2dHi13;
  uint color2Red8;
  undefined4 i2dHi14;
  uint color2Green8;
  undefined4 i2dHi15;
  uint color2Blue8;
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
  uint dstLeftSpill;
  undefined4 i2dHi23;
  uint dstRightSpill;
  undefined4 i2dHi24;
  uint dstTopSpill;
  undefined4 i2dHi25;
  uint dstBottomSpill;
  undefined4 i2dHi26;
  uint i2dLo7;
  undefined4 i2dHi27;
  uint i2dLo8;
  undefined4 i2dHi28;
  uint i2dLo9;
  undefined4 i2dHi29;
  uint i2dLo10;
  float *texU1Ptr;
  float *texV0Ptr;
  float *scrU1Ptr;
  float *scrV0Ptr;
  float *scrV1Ptr;
  float *scrU0Ptr;
  uint cmdCapacity;
  undefined4 shaderWord0;
  undefined4 shaderWord1;
  undefined4 shaderWord2;
  undefined4 shaderWord3;
  undefined4 shaderWord4;
  undefined4 shaderWord5;
  dword *scratchWord1Ptr;
  dword *scratchWord0Ptr;
  dword v1Bits;
  dword u0Bits;
  double color1Red5D;
  double color1AlphaD;
  float color1BlueF;
  float color2BlueF;
  float color1AlphaF;
  float color2AlphaF;
  float scrV1;
  float texV0;
  float color1RedF;
  float color2RedF;
  float scrU0;
  float scrV0;
  float texU1;
  float color1GreenF;
  float color2GreenF;
  float scrU1;
  int cmdBuffer;
  int mapResult;
  int screenFormat;
  int pass2Format;
  int offscreenResult;
  int heightM1;
  float colourSpill;
  uint rectIndex;
  dword *pass1Word3;
  dword *pass2Word2;
  dword *pass1Word4;
  dword *pass2Word3;
  dword *pass1Word1;
  dword *pass2Word4;
  dword *pass1Word2;
  dword *pass1Word5;
  dword *pass2Word1;
  undefined4 *pass2Start;
  undefined4 *patternDesc;
  uint screenWidthM1;
  uint dstBottom;
  
  cmdWrite = *(dword **)(accel + 0x80);
  cmdBuffer = *(int *)(accel + 0x18);
  cmdCapacity = *(int *)(cmdBuffer + 0x10) - 7;
  if ((cmdWrite == (dword *)0x0) ||
     (puStack00000028 = fillReq, highlightColorHome = highlightColor,
     offscreenResult = ((int (*)())_createOffscreenBuffer)(accel,accel + 0x4c,(uint)(*(int *)(accel + 0x70) == 3)),
     offscreenResult == 0)) {
    result = 0xe00002be;
  }
  else {
    fillColor = *puStack00000028;
    cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (cmdBuffer + 0x20) >> 2);
    if (puStack00000028[0x16] != 0) {
      i2dHi4 = 0x43300000;
      i2dHi1 = 0x43300000;
      color1Alpha8 = highlightColorHome >> 0x18;
      color1Red5 = highlightColorHome >> 10 & 0x1f;
      shaderWord1 = 0xc10016;
      shaderWord0 = 0xdb0490;
      shaderWord2 = 0xdfa23018;
      shaderWord3 = 0xdb0220;
      scrU0Ptr = scrU0Pair;
      shaderWord5 = 0x440221;
      shaderWord4 = 0xc0c011;
      scrV0Ptr = &scrV0Slot;
      scrV1Ptr = &scrV1Slot;
      scrU1Ptr = &scrU1Slot;
      scratchWord0Ptr = &scratchWord0;
      scratchWord1Ptr = &scratchWord1;
      texV0Ptr = &texV0Slot;
      texU1Ptr = &texU1Slot;
      rectIndex = 0;
      color1AlphaD = (double)CONCAT44(0x43300000,color1Alpha8);
      color1Red5D = (double)CONCAT44(0x43300000,color1Red5);
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
          mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       scratchWord0Ptr,scratchWord1Ptr,1);
          cmdWordsLeft = cmdCapacity;
          if (mapResult == 0) {
            *(undefined4 *)(scratchWord0 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord0;
            cmdWrite = (dword *)(scratchWord0 + 0x20);
            streamCursor = (dword *)(scratchWord0 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
            pass1Word1 = (dword *)(scratchWord0 + 0x24);
            pass1Word2 = (dword *)(scratchWord0 + 0x28);
            pass1Word3 = (dword *)(scratchWord0 + 0x2c);
            pass1Word4 = (dword *)(scratchWord0 + 0x30);
            pass1Word5 = (dword *)(scratchWord0 + 0x34);
          }
          else {
            cmdWrite = (dword *)0x0;
            pass1Word1 = &__mh_bundle_header.cputype;
            pass1Word2 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(accel + 0x7c) = 0;
            *(undefined4 *)(accel + 0x18) = 0;
            pass1Word3 = &__mh_bundle_header.filetype;
            pass1Word4 = &__mh_bundle_header.ncmds;
            pass1Word5 = &__mh_bundle_header.sizeofcmds;
            streamCursor = &__mh_bundle_header.flags;
          }
        }
        else {
          pass1Word1 = cmdWrite + 1;
          pass1Word2 = cmdWrite + 2;
          pass1Word3 = cmdWrite + 3;
          pass1Word4 = cmdWrite + 4;
          pass1Word5 = cmdWrite + 5;
          streamCursor = cmdWrite + 6;
        }
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = cmdWrite;
        *cmdWrite = 0xa000000;
        *pass1Word1 = *(dword *)(accel + 0x84);
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)pass1Word2 - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = pass1Word2;
        *pass1Word2 = 0x10000000;
        *pass1Word3 = *(dword *)*DAT_0000e6e4;
        *pass1Word4 = DAT_0000e6e4[7];
        if (DAT_0000e6c0 == 0x10) {
          *pass1Word5 = 3;
        }
        else {
          *pass1Word5 = 6;
        }
        screenFormat = *(int *)(accel + 0x70);
        *streamCursor = 0x850;
        streamCursor[1] = 0x100;
        streamCursor[2] = 0x887;
        streamCursor[3] = 0x1c000;
        streamCursor[4] = 0x82c;
        streamCursor[5] = 0;
        streamCursor[6] = 0x1002;
        streamCursor[7] = 0;
        streamCursor[8] = 0x824;
        streamCursor[9] = 1;
        streamCursor[10] = 0x825;
        streamCursor[0xb] = 2;
        streamCursor[0xc] = 0x82d;
        streamCursor[0xd] = 3;
        streamCursor[0xe] = 0x854;
        streamCursor[0xf] = 0x26010006;
        streamCursor[0x10] = 0x878;
        streamCursor[0x11] = 0xf688f688;
        streamCursor[0x12] = 0x10a2;
        streamCursor[0x13] = 0;
        streamCursor[0x14] = 0x1381;
        streamCursor[0x15] = 0;
        streamCursor[0x16] = 0x109e;
        streamCursor[0x17] = 5;
        streamCursor[0x18] = 0x1383;
        streamCursor[0x19] = 0xf;
        streamCursor[0x1a] = 0x1004;
        streamCursor[0x1b] = 0x66666666;
        streamCursor[0x1c] = 0x1005;
        streamCursor[0x1d] = 0x66666666;
        streamCursor[0x1e] = 0x10ae;
        streamCursor[0x1f] = 0;
        streamCursor[0x20] = 0x10ea;
        streamCursor[0x21] = 0x2da49525;
        streamCursor[0x22] = 0x10fa;
        streamCursor[0x23] = 0xffffff;
        streamCursor[0x24] = 0x10f4;
        streamCursor[0x25] = 0xffff;
        streamCursor[0x26] = 0x10f8;
        streamCursor[0x27] = 0;
        streamCursor[0x28] = 0x10f9;
        streamCursor[0x29] =
             *(uint *)(accel + 0x54) & 0x1fff | (*(uint *)(accel + 0x58) & 0x1fff) << 0xd;
        streamCursor[0x2a] = 0x13c0;
        streamCursor[0x2b] = 0;
        streamCursor[0x2c] = 0x13c1;
        streamCursor[0x2d] = 0;
        streamCursor[0x2e] = 0x10c0;
        streamCursor[0x2f] = 0x40002;
        streamCursor[0x30] = 0x10c1;
        streamCursor[0x31] = 0;
        streamCursor[0x32] = 0x10c8;
        streamCursor[0x33] = 0x10;
        streamCursor[0x34] = 0x101d;
        streamCursor[0x35] = 0x280c2040;
        streamCursor[0x36] = 0x1041;
        streamCursor[0x37] = 1;
        streamCursor[0x38] = 0x1040;
        streamCursor[0x39] = 0;
        streamCursor[0x3a] = 0x1100;
        streamCursor[0x3b] = 0x2a92;
        streamCursor[0x3c] = 0x1120;
        screenWidth = *(short *)(accel + 0x50);
        screenHeight = *(short *)(accel + 0x52);
        screenWidthM1 = (int)screenWidth - 1;
        heightM1 = screenHeight + -1;
        streamCursor[0x3d] = screenWidthM1 & 0x7ff | heightM1 * 0x800 & 0x3ff800U | 0x80000000;
        streamCursor[0x3e] = 0x1130;
        streamCursor[0x3f] = 0x5300c - (uint)(screenFormat == 3);
        streamCursor[0x40] = 0x1140;
        streamCursor[0x41] =
             *(int *)(accel + 0x5c) - 1U & 0x3fff | screenWidthM1 * 0x10 & 0x8000 |
             heightM1 * 0x20 & 0x10000U;
        if (screenFormat != 3) {
          i2dHi5 = 0x43300000;
          color1AlphaF = (float)(color1AlphaD - 4503599627370496.0) / 255.0;
          i2dHi6 = 0x43300000;
          i2dHi7 = 0x43300000;
          color1Blue8 = highlightColorHome & 0xff;
          color1Red8 = highlightColorHome >> 0x10 & 0xff;
          color1Green8 = highlightColorHome >> 8 & 0xff;
          color1RedF = (float)((double)CONCAT44(0x43300000,color1Red8) - 4503599627370496.0) / 255.0;
          color1GreenF = (float)((double)CONCAT44(0x43300000,color1Green8) - 4503599627370496.0) / 255.0;
          color1BlueF = (float)((double)CONCAT44(0x43300000,color1Blue8) - 4503599627370496.0) / 255.0;
        }
        else {
          i2dHi2 = 0x43300000;
          color1RedF = (float)(color1Red5D - 4503599627370496.0) / 31.0;
          i2dHi3 = 0x43300000;
          scrU0Pair[1] = 176.0;
          color1Green5 = highlightColorHome >> 5 & 0x1f;
          color1Blue5 = highlightColorHome & 0x1f;
          color1Alpha1 = highlightColorHome >> 0xf & 1;
          color1AlphaF = (float)((double)CONCAT44(0x43300000,color1Alpha1) - 4503599627370496.0);
          color1GreenF = (float)((double)CONCAT44(0x43300000,color1Green5) - 4503599627370496.0) / 31.0;
          color1BlueF = (float)((double)CONCAT44(0x43300000,color1Blue5) - 4503599627370496.0) / 31.0;
        }
        streamCursor[0x42] = 0x1094;
        streamCursor[0x43] = 0x10000;
        streamCursor[0x44] = 0x1095;
        streamCursor[0x45] = (dword)GH_F2U(color1RedF);
        streamCursor[0x46] = 0x1095;
        streamCursor[0x47] = (dword)GH_F2U(color1GreenF);
        streamCursor[0x48] = 0x1095;
        streamCursor[0x49] = (dword)GH_F2U(color1BlueF);
        streamCursor[0x4a] = 0x1095;
        streamCursor[0x4b] = (dword)GH_F2U(color1AlphaF);
        if (screenFormat != 3) {
          color2Alpha8 = fillColor >> 0x18;
          i2dHi12 = 0x43300000;
          color2Red8 = fillColor >> 0x10 & 0xff;
          i2dHi13 = 0x43300000;
          i2dHi14 = 0x43300000;
          i2dHi15 = 0x43300000;
          color2Green8 = fillColor >> 8 & 0xff;
          color2Blue8 = fillColor & 0xff;
          color2AlphaF = (float)((double)CONCAT44(0x43300000,color2Alpha8) - 4503599627370496.0) / 255.0;
          color2RedF = (float)((double)CONCAT44(0x43300000,color2Red8) - 4503599627370496.0) / 255.0;
          color2GreenF = (float)((double)CONCAT44(0x43300000,color2Green8) - 4503599627370496.0) / 255.0;
          color2BlueF = (float)((double)CONCAT44(0x43300000,color2Blue8) - 4503599627370496.0) / 255.0;
          colourSpill = color2BlueF;
        }
        else {
          color2Red5 = fillColor >> 10 & 0x1f;
          i2dHi9 = 0x43300000;
          color2Green5 = fillColor >> 5 & 0x1f;
          i2dHi10 = 0x43300000;
          i2dHi11 = 0x43300000;
          i2dHi8 = 0x43300000;
          color2Blue5 = fillColor & 0x1f;
          color2Alpha1 = fillColor >> 0xf & 1;
          color2AlphaF = (float)((double)CONCAT44(0x43300000,color2Alpha1) - 4503599627370496.0);
          color2RedF = (float)((double)CONCAT44(0x43300000,color2Red5) - 4503599627370496.0) / 31.0;
          color2GreenF = (float)((double)CONCAT44(0x43300000,color2Green5) - 4503599627370496.0) / 31.0;
          color2BlueF = (float)((double)CONCAT44(0x43300000,color2Blue5) - 4503599627370496.0) / 31.0;
          colourSpill = color2AlphaF;
        }
        streamCursor[0x4c] = 0x1095;
        streamCursor[0x4d] = (dword)GH_F2U(color2RedF);
        streamCursor[0x4e] = 0x1095;
        streamCursor[0x4f] = (dword)GH_F2U(color2GreenF);
        streamCursor[0x50] = 0x1095;
        streamCursor[0x51] = (dword)GH_F2U(color2BlueF);
        streamCursor[0x52] = 0x1095;
        streamCursor[0x53] = (dword)GH_F2U(color2AlphaF);
        streamCursor[0x54] = 0x1094;
        streamCursor[0x55] = 0;
        streamCursor[0x56] = 0x1095;
        streamCursor[0x57] = 0x7803;
        streamCursor[0x58] = 0x1095;
        streamCursor[0x59] = 0x2400000;
        streamCursor[0x5a] = 0x1095;
        streamCursor[0x5b] = 0x3900e400;
        streamCursor[0x5c] = 0x1095;
        streamCursor[0x5d] = 0;
        streamCursor[0x5e] = 0x1095;
        streamCursor[0x5f] = 0;
        streamCursor[0x60] = 0x1095;
        streamCursor[0x61] = 0;
        streamCursor[0x62] = 0x1095;
        streamCursor[99] = 0x7804;
        streamCursor[100] = 0x1095;
        streamCursor[0x65] = 0x40040000;
        streamCursor[0x66] = 0x1095;
        streamCursor[0x67] = 0x40040000;
        streamCursor[0x68] = 0x1095;
        streamCursor[0x69] = shaderWord0;
        streamCursor[0x6a] = 0x1095;
        streamCursor[0x6b] = shaderWord1;
        streamCursor[0x6c] = 0x1095;
        streamCursor[0x6d] = shaderWord2;
        streamCursor[0x6e] = 0x1095;
        streamCursor[0x6f] = 0x7800;
        streamCursor[0x70] = 0x1095;
        streamCursor[0x71] = 1;
        streamCursor[0x72] = 0x1095;
        streamCursor[0x73] = 1;
        streamCursor[0x74] = 0x1095;
        streamCursor[0x75] = shaderWord3;
        streamCursor[0x76] = 0x1095;
        streamCursor[0x77] = shaderWord4;
        streamCursor[0x78] = 0x1095;
        streamCursor[0x79] = 0x12;
        streamCursor[0x7a] = 0x1095;
        streamCursor[0x7b] = 0x7800;
        streamCursor[0x7c] = 0x1095;
        streamCursor[0x7d] = 0x140400;
        streamCursor[0x7e] = 0x1095;
        streamCursor[0x7f] = 0x140400;
        streamCursor[0x80] = 0x1095;
        streamCursor[0x81] = shaderWord5;
        streamCursor[0x82] = 0x1095;
        streamCursor[0x83] = 0x60d036;
        streamCursor[0x84] = 0x1095;
        streamCursor[0x85] = 0xdda22038;
        streamCursor[0x86] = 0x1095;
        streamCursor[0x87] = 0x7800;
        streamCursor[0x88] = 0x1095;
        streamCursor[0x89] = 0x40040400;
        streamCursor[0x8a] = 0x1095;
        streamCursor[0x8b] = 0x40040400;
        streamCursor[0x8c] = 0x1095;
        streamCursor[0x8d] = shaderWord0;
        streamCursor[0x8e] = 0x1095;
        streamCursor[0x8f] = shaderWord1;
        streamCursor[0x90] = 0x1095;
        streamCursor[0x91] = shaderWord2;
        streamCursor[0x92] = 0x1095;
        streamCursor[0x93] = 0x7800;
        streamCursor[0x94] = 0x1095;
        streamCursor[0x95] = 1;
        streamCursor[0x96] = 0x1095;
        streamCursor[0x97] = 1;
        streamCursor[0x98] = 0x1095;
        streamCursor[0x99] = shaderWord3;
        streamCursor[0x9a] = 0x1095;
        streamCursor[0x9b] = shaderWord4;
        streamCursor[0x9c] = 0x1095;
        streamCursor[0x9d] = 0x12;
        streamCursor[0x9e] = 0x1095;
        streamCursor[0x9f] = 0x78101;
        streamCursor[0xa0] = 0x1095;
        streamCursor[0xa1] = 0x140003;
        streamCursor[0xa2] = 0x1095;
        streamCursor[0xa3] = 0x140003;
        streamCursor[0xa4] = 0x1095;
        streamCursor[0xa5] = shaderWord5;
        streamCursor[0xa6] = 0x1095;
        streamCursor[0xa7] = 0x60d006;
        streamCursor[0xa8] = 0x1095;
        streamCursor[0xa9] = 0xdda22008;
        streamCursor[0xaa] = 0x1189;
        streamCursor[0xab] = 0;
        streamCursor[0xac] = 0x1181;
        streamCursor[0xad] = 5;
        streamCursor[0xae] = 0x118d;
        streamCursor[0xaf] = 0x60000;
        streamCursor[0xb0] = 0x118e;
        streamCursor[0xb1] = 0;
        streamCursor[0xb2] = 0x118c;
        streamCursor[0xb3] = 0x60000;
        streamCursor[0xb4] = 0x11a9;
        streamCursor[0xb5] = 0x1b01;
        streamCursor[0xb6] = 0x11aa;
        streamCursor[0xb7] = 0xf;
        streamCursor[0xb8] = 0x11ab;
        streamCursor[0xb9] = 0xf;
        streamCursor[0xba] = 0x11ac;
        streamCursor[0xbb] = 0xf;
        streamCursor[0xbc] = 0x12f0;
        streamCursor[0xbd] = 0;
        streamCursor[0xbe] = 0x12f5;
        streamCursor[0xbf] = 0;
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
        dstBottom = dstTop + rectEntry[0x1a];
        i2dLo1 = dstLeft ^ 0x80000000;
        i2dLo3 = dstTop ^ 0x80000000;
        i2dLo2 = dstRight ^ 0x80000000;
        i2dLo4 = dstBottom ^ 0x80000000;
        scrU1Slot = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo5) - 4503601774854144.0);
        scrV1Slot = 1.0 / (float)((double)CONCAT44(0x43300000,i2dLo6) - 4503601774854144.0);
        scrU0Pair[0] = scrU1Slot *
                       (float)((double)CONCAT44(0x43300000,i2dLo1) - 4503601774854144.0);
        scrU1Slot = scrU1Slot *
                    (float)((double)CONCAT44(0x43300000,i2dLo2) - 4503601774854144.0);
        scrV0Slot = scrV1Slot *
                    (float)((double)CONCAT44(0x43300000,i2dLo3) - 4503601774854144.0);
        scrV1Slot = scrV1Slot *
                    (float)((double)CONCAT44(0x43300000,i2dLo4) - 4503601774854144.0);
        streamCursor[0xc0] = 0xc00c3500;
        streamCursor[0xc1] = 0x4003d;
        bottomLeftPacked = dstLeft | dstBottom * 0x10000;
        streamCursor[0xc2] = bottomLeftPacked;
        scrU0 = *scrU0Ptr;
        streamCursor[0xc3] = (dword)GH_F2U(scrU0);
        scrV1 = *scrV1Ptr;
        streamCursor[0xc4] = (dword)GH_F2U(scrV1);
        topLeftPacked = dstLeft | dstTop * 0x10000;
        streamCursor[0xc5] = topLeftPacked;
        streamCursor[0xc6] = (dword)GH_F2U(scrU0);
        scrV0 = *scrV0Ptr;
        streamCursor[199] = (dword)GH_F2U(scrV0);
        topRightPacked = dstRight | dstTop * 0x10000;
        streamCursor[200] = topRightPacked;
        scrU1 = *scrU1Ptr;
        streamCursor[0xc9] = (dword)GH_F2U(scrU1);
        streamCursor[0xca] = (dword)GH_F2U(scrV0);
        bottomRightPacked = dstRight | dstBottom * 0x10000;
        streamCursor[0xcb] = bottomRightPacked;
        streamCursor[0xcc] = (dword)GH_F2U(scrU1);
        streamCursor[0xcd] = (dword)GH_F2U(scrV1);
        streamCursor[0xce] = 0x1393;
        streamCursor[0xcf] = 10;
        streamCursor[0xd0] = 0x5c8;
        streamCursor[0xd1] = 0x20000;
        pass2Start = streamCursor + 0xd2;
        if (cmdWordsLeft - 0xd8 < 0x86) {
          scratchWord1 = *(uint *)(accel + 0x18);
          scratchWord0 = 0;
          if (*(int *)(accel + 0x8c) == 0) {
            *pass2Start = 0x5c8;
            scratchWord0 = 2;
            streamCursor[0xd3] = 0xc000;
            *(undefined4 *)(accel + 0x94) = 0;
          }
          pass2Start[scratchWord0] = 0x1000000;
          lastHeader = *(uint **)(accel + 0x7c);
          *lastHeader = ((int)pass2Start - (int)lastHeader >> 2) + scratchWord0 | *lastHeader;
          mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)PTR_0000e694,
                                       scratchWord1Ptr,scratchWord0Ptr,1);
          cmdWordsLeft = cmdCapacity;
          if (mapResult == 0) {
            *(undefined4 *)(scratchWord1 + 0x1c) = 0;
            *(uint *)(accel + 0x18) = scratchWord1;
            pass2Start = (undefined4 *)(scratchWord1 + 0x20);
            cmdWrite = (dword *)(scratchWord1 + 0x38);
            *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
            pass2Word1 = (dword *)(scratchWord1 + 0x24);
            pass2Word2 = (dword *)(scratchWord1 + 0x28);
            pass2Word3 = (dword *)(scratchWord1 + 0x2c);
            pass2Word4 = (dword *)(scratchWord1 + 0x30);
            streamCursor = (dword *)(scratchWord1 + 0x34);
          }
          else {
            pass2Start = (undefined4 *)0x0;
            pass2Word1 = &__mh_bundle_header.cputype;
            pass2Word2 = &__mh_bundle_header.cpusubtype;
            *(undefined4 *)(accel + 0x7c) = 0;
            *(undefined4 *)(accel + 0x18) = 0;
            pass2Word3 = &__mh_bundle_header.filetype;
            pass2Word4 = &__mh_bundle_header.ncmds;
            streamCursor = &__mh_bundle_header.sizeofcmds;
            cmdWrite = &__mh_bundle_header.flags;
          }
        }
        else {
          cmdWrite = streamCursor + 0xd8;
          pass2Word1 = streamCursor + 0xd3;
          pass2Word2 = streamCursor + 0xd4;
          pass2Word3 = streamCursor + 0xd5;
          pass2Word4 = streamCursor + 0xd6;
          streamCursor = streamCursor + 0xd7;
          cmdWordsLeft = cmdWordsLeft - 0xd8;
        }
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)pass2Start - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(accel + 0x7c) = pass2Start;
        *pass2Start = 0x11000000;
        *pass2Word1 = *(dword *)(accel + 0x84);
        *pass2Word2 = 0;
        *pass2Word3 = 0;
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = (int)pass2Word4 - (int)lastHeader >> 2 | *lastHeader;
        *(dword **)(accel + 0x7c) = pass2Word4;
        *pass2Word4 = 0x4000000;
        *streamCursor = *(dword *)*DAT_0000e6e4;
        patternDesc = DAT_0000e6e4;
        pass2Format = DAT_0000e6e4[0xc];
        if (pass2Format == 3) {
          pass2Format = 0xb;
        }
        else if (pass2Format == 6) {
          pass2Format = 0xc;
        }
        pass2SetupWords = ((int (*)())_radeon3DCopySetup)(accel,cmdWrite,DAT_0000e6e4 + 3,pass2Format,0,0,0,0);
        i2dHi22 = 0x43300000;
        i2dHi23 = 0x43300000;
        i2dHi24 = 0x43300000;
        i2dHi25 = 0x43300000;
        cmdWrite[pass2SetupWords] = 0xc00c3500;
        cmdWrite[pass2SetupWords + 1] = 0x4003d;
        i2dHi26 = 0x43300000;
        i2dLo7 = (int)*(short *)(patternDesc + 4) ^ 0x80000000;
        scratchWord1 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstLeft) -
                                                 4503599627370496.0) *
                                 (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                        4503601774854144.0))));
        i2dHi27 = 0x43300000;
        i2dLo8 = (int)*(short *)(patternDesc + 4) ^ 0x80000000;
        texU1Slot = (float)((double)(float)((double)CONCAT44(0x43300000,dstRight) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) - 4503601774854144.0)));
        i2dHi28 = 0x43300000;
        i2dLo9 = (int)*(short *)((int)patternDesc + 0x12) ^ 0x80000000;
        texV0Slot = (float)((double)(float)((double)CONCAT44(0x43300000,dstTop) - 4503599627370496.0
                                           ) *
                           (1.0 / ((double)CONCAT44(0x43300000,i2dLo9) - 4503601774854144.0)));
        i2dHi29 = 0x43300000;
        i2dLo10 = (int)*(short *)((int)patternDesc + 0x12) ^ 0x80000000;
        scratchWord0 = (uint)GH_F2U((float)((double)(float)((double)CONCAT44(0x43300000,dstBottom) -
                                                 4503599627370496.0) *
                                 (1.0 / ((double)CONCAT44(0x43300000,i2dLo10) - 4503601774854144.0
                                        ))));
        cmdWrite[pass2SetupWords + 2] = bottomLeftPacked;
        u0Bits = *scratchWord1Ptr;
        cmdWrite[pass2SetupWords + 3] = u0Bits;
        v1Bits = *scratchWord0Ptr;
        cmdWrite[pass2SetupWords + 4] = v1Bits;
        cmdWrite[pass2SetupWords + 5] = topLeftPacked;
        cmdWrite[pass2SetupWords + 6] = u0Bits;
        texV0 = *texV0Ptr;
        cmdWrite[pass2SetupWords + 7] = (dword)GH_F2U(texV0);
        cmdWrite[pass2SetupWords + 8] = topRightPacked;
        texU1 = *texU1Ptr;
        cmdWrite[pass2SetupWords + 9] = (dword)GH_F2U(texU1);
        cmdWrite[pass2SetupWords + 10] = (dword)GH_F2U(texV0);
        cmdWrite[pass2SetupWords + 0xb] = bottomRightPacked;
        cmdWrite[pass2SetupWords + 0xc] = (dword)GH_F2U(texU1);
        cmdWrite[pass2SetupWords + 0xd] = v1Bits;
        cmdWrite[pass2SetupWords + 0xe] = 0x1393;
        cmdWrite[pass2SetupWords + 0xf] = 10;
        cmdWrite[pass2SetupWords + 0x10] = 0x5c8;
        cmdWrite[pass2SetupWords + 0x11] = 0x20000;
        cmdWordsLeft = (cmdWordsLeft - 6) - (pass2SetupWords + 0x12);
        rectEntry = rectEntry + 4;
        cmdWrite = cmdWrite + pass2SetupWords + 0x12;
        rectIndex = rectIndex + 1;
        dstLeftSpill = dstLeft;
        dstRightSpill = dstRight;
        dstTopSpill = dstTop;
        dstBottomSpill = dstBottom;
      } while (rectIndex < puStack00000028[0x16]);
    }
    result = 0;
    *(dword **)(accel + 0x80) = cmdWrite;
  }
  return result;
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
  uint *drawPacketHeader;
  uint cmdCapacity;
  uint scanDstTop;
  undefined *taskPtr;
  dword *cmdPtrPlus44Or3Block1;
  dword *cmdPtrPlus6Block2;
  int scanPacketWord3Idx;
  uint *lastHeader;
  int scanPacketWord1Idx;
  uint cmdBufferBase;
  int scanPacketWord2Idx;
  dword *cmdPtrPlus40Or2Block1;
  uint dstTop;
  uint cmdWordsLeft;
  uint dstBottom;
  uint dstLeft;
  uint dstRight;
  dword *cmdWrite;
  uint scratchWord0;
  uint scratchWord1;
  undefined4 i2dHi1;
  undefined4 i2dHi2;
  undefined4 i2dHi3;
  undefined4 i2dHi4;
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
  uint firstTileRightUnclamped;
  undefined4 *scanEntry;
  undefined4 flushWaitWord;
  uint dstLeftMasked;
  uint dstRightMasked;
  bool needsSetup;
  float dstTopF;
  float texOriginV;
  float dstBottomF;
  float texOriginU;
  float dstRightF;
  float v1Norm;
  float dstLeftF;
  float u1Norm;
  float u0Norm;
  int tileHeightCopy;
  int tileWidthCopy;
  int texOriginUInt;
  int texOriginVInt;
  int mapResult;
  int fillSetupWords;
  int originX;
  int cmdBuffer;
  int patternDesc;
  int setupWords;
  int regIdxNext;
  int scanCount;
  int textureBuffer;
  int mapResult2;
  int regByteOffset;
  int tileWidth;
  uint rangeIndex;
  int patternFormat;
  uint tileRightLimit;
  uint nextTileLeft;
  uint tileBottomLimit;
  float v1NormSpill;
  float u0NormAlt;
  int tileHeight;
  uint tileTopHi;
  uint tileBottomHi;
  int picOffset;
  dword drawCountWord;
  int needsRegSetup;
  char *headerBytes;
  dword *cmdWord5;
  dword *cmdWord8;
  dword *cmdWord9;
  dword *cmdWord4;
  dword *cmdWord1;
  dword *cmdWord10;
  segment_command *cmdWord7;
  float *vtxPtr;
  float *vtxLast;
  undefined4 *cmdPtr;
  uint rangeCount;
  uint tileTop;
  uint tileRight;
  uint tileBottom;
  uint tileBottomNext;
  uint tileLeft;
  uint nextTileBottom;
  
  if ((blitFlags & 0x7ffff000) == 0x6000) {
    cmdPtr = *(undefined4 **)(accel + 0x80);
    cmdBufferBase = *(uint *)(accel + 0x18);
    if (cmdPtr != (undefined4 *)0x0) {
      if ((uint)((*(int *)(cmdBufferBase + 0x10) + -7) - ((int)((int)cmdPtr - (cmdBufferBase + 0x20)) >> 2)) <
          scanReq[0x16] * 0xc + 0x6eU) {
        scratchWord1 = 0;
        if (*(int *)(accel + 0x8c) == 0) {
          *cmdPtr = 0x5c8;
          scratchWord1 = 2;
          cmdPtr[1] = 0xc000;
          *(undefined4 *)(accel + 0x94) = 0;
        }
        cmdPtr[scratchWord1] = 0x1000000;
        taskPtr = PTR_0000e694;
        lastHeader = *(uint **)(accel + 0x7c);
        *lastHeader = ((int)cmdPtr - (int)lastHeader >> 2) + scratchWord1 | *lastHeader;
        scratchWord0 = cmdBufferBase;
        mapResult = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,*(undefined4 *)taskPtr,
                                     &scratchWord0,&scratchWord1,1);
        if (mapResult == 0) {
          *(undefined4 *)(scratchWord0 + 0x1c) = 0;
          *(uint *)(accel + 0x18) = scratchWord0;
          cmdPtr = (undefined4 *)(scratchWord0 + 0x20);
          *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
        }
        else {
          cmdPtr = (undefined4 *)0x0;
          *(undefined4 *)(accel + 0x7c) = 0;
          *(undefined4 *)(accel + 0x18) = 0;
        }
      }
      fillSetupWords = ((int (*)())_radeon3DFillSetup)(cmdPtr,0,packedColor,accel);
      scanCount = scanReq[0x16];
      drawPacketHeader = cmdPtr + fillSetupWords;
      *drawPacketHeader = scanCount * 0xc0000 | 0xc0003500;
      vtxPtr = (float *)(drawPacketHeader + 2);
      drawPacketHeader[1] = scanCount << 0x12 | 0x3d;
      scanDstTop = scanReq[0x17] + *(int *)(accel + 100);
      dstTopF = (float)((double)CONCAT44(0x43300000,scanDstTop ^ 0x80000000) - 4503601774854144.0);
      dstBottomF = (float)((double)CONCAT44(0x43300000,scanDstTop + scanReq[0x18] ^ 0x80000000) -
                     4503601774854144.0);
      if (scanCount != 0) {
        originX = *(int *)(accel + 0x60);
        if (scanCount == 0) {
          scanCount = 1;
        }
        do {
          dstLeftF = (float)((double)CONCAT44(0x43300000,scanReq[0x19] + originX ^ 0x80000000) -
                          4503601774854144.0);
          dstRightF = (float)((double)CONCAT44(0x43300000,scanReq[0x1a] + originX ^ 0x80000000) -
                          4503601774854144.0);
          *vtxPtr = dstLeftF;
          vtxPtr[1] = dstBottomF;
          vtxPtr[2] = 0.0;
          vtxPtr[3] = dstLeftF;
          vtxPtr[4] = dstTopF;
          vtxPtr[5] = 0.0;
          vtxPtr[6] = dstRightF;
          vtxPtr[7] = dstTopF;
          vtxPtr[8] = 0.0;
          vtxPtr[9] = dstRightF;
          vtxPtr[10] = dstBottomF;
          vtxLast = vtxPtr + 0xb;
          vtxPtr = vtxPtr + 0xc;
          *vtxLast = 0.0;
          scanReq = scanReq + 2;
          scanCount = scanCount + -1;
        } while (scanCount != 0);
      }
      *vtxPtr = 7.02191e-42;
      vtxPtr[1] = 1.4013e-44;
      vtxPtr[2] = 2.07392e-42;
      vtxPtr[3] = 1.83671e-40;
      *(float **)(accel + 0x80) = vtxPtr + 4;
      return 0;
    }
  }
  else {
    cmdWrite = *(dword **)(accel + 0x80);
    cmdBuffer = *(int *)(accel + 0x18);
    cmdCapacity = *(int *)(cmdBuffer + 0x10) - 7;
    if ((cmdWrite != (dword *)0x0) &&
       (textureBuffer = ((int (*)())_createTextureBuffer)(accel,0x40,0x40,(uint)(*(int *)(accel + 0x70) == 3)),
       textureBuffer != 0)) {
      picOffset = 0xbaa4;
      cmdWordsLeft = cmdCapacity - ((int)cmdWrite - (cmdBuffer + 0x20) >> 2);
      _fillTextureWithPattern(packedColor,blitFlags & 0x7ffff000,*scanReq,scanReq[1]);
      patternDesc = *(int *)(((unsigned char *)0x00002ca4) + picOffset);
      patternFormat = *(int *)(patternDesc + 0x30);
      if (patternFormat == 3) {
        patternFormat = 0xb;
      }
      else if (patternFormat == 6) {
        patternFormat = 0xc;
      }
      rangeCount = scanReq[0x16];
      i2dHi1 = 0x43300000;
      dstTop = scanReq[0x17] + *(int *)(accel + 100);
      texOriginVInt = (dstTop & 7) + scanReq[3];
      dstBottom = dstTop + scanReq[0x18];
      texOriginV = (float)((double)CONCAT44(0x43300000,texOriginVInt) - 4503599627370496.0);
      if (rangeCount != 0) {
        tileBottomLimit = dstBottom;
        if (dstTop + 8 < dstBottom) {
          tileBottomLimit = dstTop + 8;
        }
        needsSetup = true;
        rangeIndex = 0;
        scanEntry = scanReq;
        do {
          i2dHi2 = 0x43300000;
          dstLeft = *(int *)(accel + 0x60) + scanEntry[0x19];
          texOriginUInt = (dstLeft & 7) + scanReq[2];
          dstRight = *(int *)(accel + 0x60) + scanEntry[0x1a];
          texOriginU = (float)((double)CONCAT44(0x43300000,texOriginUInt) - 4503599627370496.0);
          if (dstTop < dstBottom) {
            firstTileRightUnclamped = dstLeft + 8;
            tileRightLimit = dstRight;
            if (firstTileRightUnclamped < dstRight) {
              tileRightLimit = firstTileRightUnclamped;
            }
            dstLeftMasked = dstLeft & 0x1fff;
            dstRightMasked = dstRight & 0x1fff;
            flushWaitWord = 0xc000;
            drawCountWord = 0x4003d;
            needsRegSetup = 1;
            tileTop = dstTop;
            tileBottom = tileBottomLimit;
            do {
              if (dstLeft < dstRight) {
                tileLeft = dstLeft;
                tileRight = tileRightLimit;
                if (!needsSetup) {
                  tileBottomHi = tileBottom << 0x10;
                  tileTopHi = tileTop << 0x10;
                  tileHeight = tileBottom - tileTop;
                  tileBottomNext = firstTileRightUnclamped;
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
                  mapResult2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord0,&scratchWord1,1);
                  tileRight = tileRightLimit;
                  if (mapResult2 == 0) {
                    tileBottomHi = tileBottom << 0x10;
                    tileTopHi = tileTop << 0x10;
                    tileHeight = tileBottom - tileTop;
                    *(undefined4 *)(scratchWord0 + 0x1c) = 0;
                    cmdWrite = (dword *)(scratchWord0 + 0x20);
                    nextTileLeft = firstTileRightUnclamped;
                    *(uint *)(accel + 0x18) = scratchWord0;
                    cmdWord10 = (dword *)(scratchWord0 + 0x48);
                    *(uint *)(accel + 0x7c) = scratchWord0 + 0x1c;
                    cmdWord1 = (dword *)(scratchWord0 + 0x24);
                    cmdPtrPlus40Or2Block1 = (dword *)(scratchWord0 + 0x28);
                    cmdPtrPlus44Or3Block1 = (dword *)(scratchWord0 + 0x2c);
                    cmdWord4 = (dword *)(scratchWord0 + 0x30);
                    cmdWord5 = (dword *)(scratchWord0 + 0x34);
                    cmdPtrPlus6Block2 = (dword *)(scratchWord0 + 0x38);
                    cmdWord7 = (segment_command *)(scratchWord0 + 0x3c);
                    cmdWord8 = (dword *)(scratchWord0 + 0x40);
                    cmdWord9 = (dword *)(scratchWord0 + 0x44);
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    tileBottomHi = tileBottom << 0x10;
                    tileHeight = tileBottom - tileTop;
                    tileTopHi = tileTop << 0x10;
                    nextTileLeft = firstTileRightUnclamped;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdWrite = (dword *)0x0;
                    cmdWord1 = &__mh_bundle_header.cputype;
                    cmdPtrPlus40Or2Block1 = &__mh_bundle_header.cpusubtype;
                    cmdPtrPlus44Or3Block1 = &__mh_bundle_header.filetype;
                    cmdWord4 = &__mh_bundle_header.ncmds;
                    cmdWord5 = &__mh_bundle_header.sizeofcmds;
                    cmdPtrPlus6Block2 = &__mh_bundle_header.flags;
                    cmdWord7 = &(*(GhidraMachOCommand *)0x0000001c);
                    cmdWord8 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    cmdWord9 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    cmdWord10 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    cmdWordsLeft = cmdCapacity;
                  }
                }
                else {
                  tileBottomHi = tileBottom << 0x10;
                  tileTopHi = tileTop << 0x10;
                  tileHeight = tileBottom - tileTop;
                  cmdWord1 = cmdWrite + 1;
                  cmdPtrPlus40Or2Block1 = cmdWrite + 2;
                  cmdPtrPlus44Or3Block1 = cmdWrite + 3;
                  nextTileLeft = firstTileRightUnclamped;
                  cmdWord4 = cmdWrite + 4;
                  cmdWord5 = cmdWrite + 5;
                  cmdPtrPlus6Block2 = cmdWrite + 6;
                  cmdWord7 = (segment_command *)(cmdWrite + 7);
                  cmdWord8 = cmdWrite + 8;
                  cmdWord9 = cmdWrite + 9;
                  cmdWord10 = cmdWrite + 10;
                }
                do {
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)cmdWrite - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = cmdWrite;
                  *cmdWrite = 0x11000000;
                  *cmdWord1 = *(dword *)(accel + 0x84);
                  *cmdPtrPlus40Or2Block1 = 0;
                  *cmdPtrPlus44Or3Block1 = 0;
                  lastHeader = *(uint **)(accel + 0x7c);
                  *lastHeader = (int)cmdWord4 - (int)lastHeader >> 2 | *lastHeader;
                  *(dword **)(accel + 0x7c) = cmdWord4;
                  *cmdWord4 = 0x8000000;
                  *cmdWord5 = *(dword *)**(undefined4 **)(((unsigned char *)0x00002ca4) + picOffset);
                  *cmdPtrPlus6Block2 = 0;
                  cmdWord7->cmd = 0;
                  *cmdWord8 = 0;
                  *cmdWord9 = 0;
                  cmdWordsLeft = cmdWordsLeft - 10;
                  setupWords = ((int (*)())_radeon3DCopySetup)(accel,cmdWord10,patternDesc + 0xc,patternFormat,0,0,0,0);
                  regByteOffset = setupWords << 2;
                  scanPacketWord1Idx = setupWords + 1;
                  scanPacketWord2Idx = setupWords + 2;
                  scanPacketWord3Idx = setupWords + 3;
                  regIdxNext = setupWords + 4;
                  cmdWrite = cmdWord10;
                  while( true ) {
                    if (needsRegSetup != 0) {
                      headerBytes = (char *)((int)cmdWrite + regByteOffset);
                      headerBytes[0] = '\0';
                      headerBytes[1] = '\0';
                      headerBytes[2] = '\x10';
                      headerBytes[3] = -8;
                      cmdWrite[scanPacketWord1Idx] = dstLeftMasked | dstTop * 0x2000 & 0x3ffe000;
                      cmdWrite[scanPacketWord2Idx] = 0x10f9;
                      cmdWrite[scanPacketWord3Idx] = dstRightMasked | dstBottom * 0x2000 & 0x3ffe000;
                      regByteOffset = regIdxNext << 2;
                      scanPacketWord1Idx = regIdxNext + 1;
                      scanPacketWord2Idx = regIdxNext + 2;
                      needsRegSetup = 0;
                      scanPacketWord3Idx = regIdxNext + 3;
                      setupWords = regIdxNext;
                      regIdxNext = regIdxNext + 4;
                    }
                    tileWidth = tileRight - tileLeft;
                    if ((tileWidth == 8) && (tileHeight == 8)) {
                      headerBytes = (char *)((int)cmdWrite + regByteOffset);
                      headerBytes[0] = -0x40;
                      headerBytes[1] = '\f';
                      headerBytes[2] = '5';
                      headerBytes[3] = '\0';
                      cmdWrite[scanPacketWord1Idx] = drawCountWord;
                      i2dHi9 = 0x43300000;
                      i2dLo5 = (int)*(short *)(patternDesc + 0x10) ^ 0x80000000;
                      u0Norm = (float)((double)(texOriginU + 0.0) *
                                     (1.0 / ((double)CONCAT44(0x43300000,i2dLo5) -
                                            4503601774854144.0)));
                      i2dHi10 = 0x43300000;
                      i2dLo6 = (int)*(short *)(patternDesc + 0x10) ^ 0x80000000;
                      u1Norm = (float)((double)(texOriginU + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo6) -
                                             4503601774854144.0)));
                      i2dHi11 = 0x43300000;
                      i2dLo7 = (int)*(short *)(patternDesc + 0x12) ^ 0x80000000;
                      scratchWord0 = (uint)GH_F2U((float)((double)(texOriginV + 0.0) *
                                               (1.0 / ((double)CONCAT44(0x43300000,i2dLo7) -
                                                      4503601774854144.0))));
                      i2dHi12 = 0x43300000;
                      i2dLo8 = (int)*(short *)(patternDesc + 0x12) ^ 0x80000000;
                      v1Norm = (float)((double)(texOriginV + 8.0) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo8) -
                                             4503601774854144.0)));
                      cmdWrite[scanPacketWord2Idx] = tileLeft | tileBottomHi;
                      cmdWrite[scanPacketWord3Idx] = (dword)GH_F2U(u0Norm);
                      cmdWrite[regIdxNext] = (dword)GH_F2U(v1Norm);
                      cmdWrite[setupWords + 5] = tileLeft | tileTopHi;
                      cmdWrite[setupWords + 6] = (dword)GH_F2U(u0Norm);
                      cmdWrite[setupWords + 7] = scratchWord0;
                      cmdWrite[setupWords + 8] = tileRight | tileTopHi;
                      scratchWord1 = (uint)GH_F2U(u1Norm);
                      v1NormSpill = v1Norm;
                    }
                    else {
                      i2dHi3 = 0x43300000;
                      i2dHi4 = 0x43300000;
                      tileHeightCopy = tileHeight;
                      headerBytes = (char *)((int)cmdWrite + regByteOffset);
                      headerBytes[0] = -0x40;
                      headerBytes[1] = '\f';
                      headerBytes[2] = '5';
                      headerBytes[3] = '\0';
                      cmdWrite[scanPacketWord1Idx] = drawCountWord;
                      i2dHi5 = 0x43300000;
                      i2dLo1 = (int)*(short *)(patternDesc + 0x10) ^ 0x80000000;
                      u0NormAlt = (float)((double)(texOriginU + 0.0) *
                                         (1.0 / ((double)CONCAT44(0x43300000,i2dLo1) -
                                                4503601774854144.0)));
                      i2dHi6 = 0x43300000;
                      i2dLo2 = (int)*(short *)(patternDesc + 0x10) ^ 0x80000000;
                      u1Norm = (float)((double)(texOriginU + (float)((double)CONCAT44(0x43300000,tileWidth) -
                                                               4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo2) -
                                             4503601774854144.0)));
                      i2dHi7 = 0x43300000;
                      i2dLo3 = (int)*(short *)(patternDesc + 0x12) ^ 0x80000000;
                      scratchWord0 = (uint)GH_F2U((float)((double)(texOriginV + 0.0) *
                                               (1.0 / ((double)CONCAT44(0x43300000,i2dLo3) -
                                                      4503601774854144.0))));
                      i2dHi8 = 0x43300000;
                      i2dLo4 = (int)*(short *)(patternDesc + 0x12) ^ 0x80000000;
                      v1Norm = (float)((double)(texOriginV + (float)((double)CONCAT44(0x43300000,tileHeight
                                                                                ) -
                                                               4503599627370496.0)) *
                                      (1.0 / ((double)CONCAT44(0x43300000,i2dLo4) -
                                             4503601774854144.0)));
                      cmdWrite[scanPacketWord2Idx] = tileBottomHi | tileLeft;
                      cmdWrite[scanPacketWord3Idx] = (dword)GH_F2U(u0NormAlt);
                      cmdWrite[regIdxNext] = (dword)GH_F2U(v1Norm);
                      cmdWrite[setupWords + 5] = tileTopHi | tileLeft;
                      cmdWrite[setupWords + 6] = (dword)GH_F2U(u0NormAlt);
                      cmdWrite[setupWords + 7] = scratchWord0;
                      cmdWrite[setupWords + 8] = tileTopHi | tileRight;
                      scratchWord1 = (uint)GH_F2U(v1Norm);
                      tileWidthCopy = tileWidth;
                    }
                    cmdWrite[setupWords + 9] = (dword)GH_F2U(u1Norm);
                    cmdWrite[setupWords + 10] = scratchWord0;
                    cmdWrite[setupWords + 0xb] = tileRight | tileBottomHi;
                    cmdWrite[setupWords + 0xc] = (dword)GH_F2U(u1Norm);
                    cmdWrite[setupWords + 0xd] = (dword)GH_F2U(v1Norm);
                    cmdWrite[setupWords + 0xe] = 0x1393;
                    cmdWrite[setupWords + 0xf] = 10;
                    cmdWrite[setupWords + 0x10] = 0x5c8;
                    cmdWrite[setupWords + 0x11] = 0x20000;
                    cmdWordsLeft = cmdWordsLeft - (setupWords + 0x12);
                    cmdWrite = cmdWrite + setupWords + 0x12;
                    tileRight = dstRight;
                    if (tileLeft + 0x10 < dstRight) {
                      tileRight = tileLeft + 0x10;
                    }
                    needsSetup = false;
                    if (dstRight <= nextTileLeft) goto LAB_0000c820;
                    tileBottomNext = nextTileLeft + 8;
                    tileLeft = nextTileLeft;
LAB_0000c1c8:
                    if (cmdWordsLeft < 0x16) break;
                    regIdxNext = 4;
                    scanPacketWord3Idx = 3;
                    scanPacketWord2Idx = 2;
                    scanPacketWord1Idx = 1;
                    regByteOffset = 0;
                    setupWords = 0;
                    nextTileLeft = tileBottomNext;
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
                  mapResult2 = _IOConnectMapMemory(*(undefined4 *)(accel + 0xc),0,
                                               *(undefined4 *)taskPtr,&scratchWord1,&scratchWord0,1);
                  if (mapResult2 == 0) {
                    nextTileLeft = tileLeft + 8;
                    needsRegSetup = 1;
                    *(undefined4 *)(scratchWord1 + 0x1c) = 0;
                    *(uint *)(accel + 0x18) = scratchWord1;
                    cmdWrite = (dword *)(scratchWord1 + 0x20);
                    cmdWord10 = (dword *)(scratchWord1 + 0x48);
                    *(uint *)(accel + 0x7c) = scratchWord1 + 0x1c;
                    cmdWord1 = (dword *)(scratchWord1 + 0x24);
                    cmdPtrPlus40Or2Block1 = (dword *)(scratchWord1 + 0x28);
                    cmdPtrPlus44Or3Block1 = (dword *)(scratchWord1 + 0x2c);
                    cmdWord4 = (dword *)(scratchWord1 + 0x30);
                    cmdWord5 = (dword *)(scratchWord1 + 0x34);
                    cmdPtrPlus6Block2 = (dword *)(scratchWord1 + 0x38);
                    cmdWord7 = (segment_command *)(scratchWord1 + 0x3c);
                    cmdWord8 = (dword *)(scratchWord1 + 0x40);
                    cmdWord9 = (dword *)(scratchWord1 + 0x44);
                    cmdWordsLeft = cmdCapacity;
                  }
                  else {
                    nextTileLeft = tileLeft + 8;
                    cmdWord10 = (dword *)((*(GhidraMachOCommand *)0x0000001c).segname + 4);
                    cmdWord9 = (dword *)(*(GhidraMachOCommand *)0x0000001c).segname;
                    cmdWord8 = &(*(GhidraMachOCommand *)0x0000001c).cmdsize;
                    cmdWord7 = &(*(GhidraMachOCommand *)0x0000001c);
                    needsRegSetup = 1;
                    *(undefined4 *)(accel + 0x7c) = 0;
                    *(undefined4 *)(accel + 0x18) = 0;
                    cmdPtrPlus6Block2 = &__mh_bundle_header.flags;
                    cmdWord5 = &__mh_bundle_header.sizeofcmds;
                    cmdWord4 = &__mh_bundle_header.ncmds;
                    cmdPtrPlus44Or3Block1 = &__mh_bundle_header.filetype;
                    cmdPtrPlus40Or2Block1 = &__mh_bundle_header.cpusubtype;
                    cmdWord1 = &__mh_bundle_header.cputype;
                    cmdWrite = (dword *)0x0;
                    cmdWordsLeft = cmdCapacity;
                  }
                } while( true );
              }
LAB_0000c820:
              nextTileBottom = tileTop + 0x10;
              tileTop = tileTop + 8;
              tileBottom = dstBottom;
              if (nextTileBottom < dstBottom) {
                tileBottom = nextTileBottom;
              }
            } while (tileTop < dstBottom);
            rangeCount = scanReq[0x16];
          }
          rangeIndex = rangeIndex + 1;
          scanEntry = scanEntry + 2;
        } while (rangeIndex < rangeCount);
      }
      *(dword **)(accel + 0x80) = cmdWrite;
      return 0;
    }
  }
  return 0xe00002be;
}

/* _printf_LDBLStub @ 0xc89c (172 bytes) */
int _printf_LDBLStub(printfArg1, printfArg2, printfArg3, printfArg4, printfArg5, printfArg6, printfArg7, printfArg8)
  undefined4 printfArg1;
  undefined4 printfArg2;
  undefined4 printfArg3;
  undefined4 printfArg4;
  undefined4 printfArg5;
  undefined4 printfArg6;
  undefined4 printfArg7;
  undefined4 printfArg8;
{
  if (_funcptr == (code *)0x0) {
    _funcptr = (code *)((int (*)())___stub_getrealaddr)("printf");
  }
                    
                    
  (*_funcptr)(printfArg1,printfArg2,printfArg3,printfArg4,printfArg5,printfArg6,printfArg7,printfArg8);
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
int ___stub_getrealaddr(symbolName)
  undefined4 symbolName;
{
  int nameLength;
  int isDefined;
  undefined4 nsSymbolOrAddress;
  char nameBuffer [4];
  char nameBufferTail [4];
  char nameBufferEnd [64];
  
  nameBuffer[0] = '_';
  _strcpy(nameBuffer + 1,symbolName);
  nameLength = _strlen(nameBuffer);
  builtin_strncpy(nameBuffer + nameLength,"$LDB",4);
  nameBufferEnd[nameLength] = '\0';
  builtin_strncpy(nameBufferTail + nameLength,"L128",4);
  isDefined = _NSIsSymbolNameDefinedWithHint(nameBuffer,"libSystem.");
  if (isDefined == 0) {
    nameBuffer[nameLength] = '\0';
  }
  nsSymbolOrAddress = _NSLookupAndBindSymbolWithHint(nameBuffer,"libSystem.");
  nsSymbolOrAddress = _NSAddressOfSymbol(nsSymbolOrAddress);
  return nsSymbolOrAddress;
}

