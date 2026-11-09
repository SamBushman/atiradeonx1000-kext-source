#include "decls.h"

/* _gleMultiVtxTextureCoordGenNormalSTR @ 0xf73b4 (88 bytes) */
int _gleMultiVtxTextureCoordGenNormalSTR(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_2 + param_3 * 0x100;
  if (param_2 < uVar2) {
    uVar2 = (uVar2 - param_2) + 0xff >> 8;
    do {
      iVar3 = param_4 * 0x10 + param_2;
      *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(param_2 + 0x40);
      *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(param_2 + 0x44);
      puVar1 = (undefined4 *)(param_2 + 0x48);
      param_2 = param_2 + 0x100;
      *(undefined4 *)(iVar3 + 0x88) = *puVar1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleTextureImageCopy @ 0xf7410 (260 bytes) */
int _gleTextureImageCopy(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar5 = *(undefined4 *)(param_1 + 0x31b0);
  *(uint *)(param_1 + 0x31b0) = (uint)*(ushort *)(param_2 + 0xc);
  uVar4 = *(undefined4 *)(param_1 + 0x31c8);
  uVar3 = *(undefined4 *)(param_1 + 0x31c0);
  uVar6 = *(undefined4 *)(0x31b4 + param_1);
  uVar7 = *(undefined4 *)(param_1 + 0x31b8);
  *(uint *)(0x31b4 + param_1) = (uint)*(ushort *)(param_2 + 0xe);
  uVar2 = *(undefined4 *)(param_1 + 0x31bc);
  uVar1 = *(undefined4 *)(param_1 + 0x31c4);
  *(undefined1 *)(param_1 + 0x31c8) = 0;
  *(undefined1 *)(param_1 + 0x31c9) = 0;
  *(undefined4 *)(param_1 + 0x31b8) = 0;
  *(undefined4 *)(param_1 + 0x31bc) = 0;
  *(undefined4 *)(param_1 + 0x31c0) = 0;
  *(undefined4 *)(param_1 + 0x31c4) = 1;
  (**(code **)(param_1 + 0x46a0))
            (*(undefined4 *)(param_1 + 0x4688),param_4,param_5,param_6,param_7,
             *(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x12),
             *(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x31b0) = uVar5;
  *(undefined4 *)(param_1 + 0x31c8) = uVar4;
  *(undefined4 *)(0x31b4 + param_1) = uVar6;
  *(undefined4 *)(param_1 + 0x31b8) = uVar7;
  *(undefined4 *)(param_1 + 0x31bc) = uVar2;
  *(undefined4 *)(param_1 + 0x31c0) = uVar3;
  *(undefined4 *)(param_1 + 0x31c4) = uVar1;
  return;
}

/* _gleTextureSubImageCopy @ 0xf7514 (348 bytes) */
int _gleTextureSubImageCopy(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar7 = *(undefined4 *)(param_1 + 0x31b0);
  *(uint *)(param_1 + 0x31b0) = (uint)*(ushort *)(param_2 + 0xc);
  uVar8 = *(undefined4 *)(0x31b4 + param_1);
  *(uint *)(0x31b4 + param_1) = (uint)*(ushort *)(param_2 + 0xe);
  uVar4 = *(undefined4 *)(param_1 + 0x31b8);
  uVar5 = *(undefined4 *)(param_1 + 0x31c8);
  uVar2 = *(undefined4 *)(param_1 + 0x31bc);
  uVar3 = *(undefined4 *)(param_1 + 0x31c0);
  uVar6 = *(undefined4 *)(param_1 + 0x31c4);
  if ((*(ushort *)(param_2 + 8) < 2) && (param_5 == 0)) {
    *(undefined4 *)(param_1 + 0x31c0) = 0;
  }
  else {
    *(uint *)(param_1 + 0x31c0) = param_5 + (uint)*(byte *)(param_2 + 10);
  }
  if ((*(ushort *)(param_2 + 6) < 2) && (param_4 == 0)) {
    *(undefined4 *)(param_1 + 0x31b8) = 0;
  }
  else {
    *(uint *)(param_1 + 0x31b8) = param_4 + (uint)*(byte *)(param_2 + 10);
  }
  bVar1 = *(byte *)(param_2 + 10);
  *(undefined4 *)(param_1 + 0x31c4) = 1;
  *(undefined1 *)(param_1 + 0x31c9) = 0;
  *(uint *)(param_1 + 0x31bc) = param_3 + (uint)bVar1;
  *(undefined1 *)(param_1 + 0x31c8) = 0;
  (**(code **)(param_1 + 0x46a0))
            (*(undefined4 *)(param_1 + 0x4688),param_6,param_7,param_8,param_9,
             *(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x12),
             *(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(param_1 + 0x31b0) = uVar7;
  *(undefined4 *)(param_1 + 0x31c8) = uVar5;
  *(undefined4 *)(0x31b4 + param_1) = uVar8;
  *(undefined4 *)(param_1 + 0x31b8) = uVar4;
  *(undefined4 *)(param_1 + 0x31bc) = uVar2;
  *(undefined4 *)(param_1 + 0x31c0) = uVar3;
  *(undefined4 *)(param_1 + 0x31c4) = uVar6;
  return;
}

/* _gleNoopFilter1 @ 0xf7670 (4 bytes) */
int _gleNoopFilter1()
{
  return;
}

/* _gleNoopFilter2 @ 0xf7674 (4 bytes) */
int _gleNoopFilter2()
{
  return;
}

/* _gleNoopFilter3 @ 0xf7678 (4 bytes) */
int _gleNoopFilter3()
{
  return;
}

/* _gleByteFilter1 @ 0xf767c (60 bytes) */
int _gleByteFilter1(param_1, param_2, param_3, param_4)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      cVar1 = *param_2;
      pcVar2 = param_2 + param_4;
      param_2 = param_2 + 1;
      *(char *)(param_1 + iVar3) = (char)((int)cVar1 + (int)*pcVar2 >> 1);
      iVar3 = iVar3 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return;
  }
  return;
}

/* _gleByteFilter2 @ 0xf76b8 (96 bytes) */
int _gleByteFilter2(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = 0;
  if (param_3 < 1) {
    return;
  }
  pcVar3 = (char *)(param_2 + param_4 + param_5);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *(char *)(param_1 + iVar2) =
         (char)((int)*(char *)(param_2 + iVar2) + (int)*(char *)(param_2 + iVar2 + param_4) +
                (int)*(char *)(param_2 + iVar2 + param_5) + (int)cVar1 >> 2);
    iVar2 = iVar2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

/* _gleByteFilter3 @ 0xf7718 (176 bytes) */
int _gleByteFilter3(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar3 = 0;
  if (0 < param_3) {
    pcVar5 = (char *)(param_2 + param_5 + param_6);
    do {
      iVar4 = param_2 + iVar3;
      cVar1 = *pcVar5;
      pcVar2 = pcVar5 + param_4;
      pcVar5 = pcVar5 + 1;
      *(char *)(param_1 + iVar3) =
           (char)((int)*(char *)(param_2 + iVar3) + (int)*(char *)(iVar4 + param_4) +
                  (int)*(char *)(iVar4 + param_5) + (int)*(char *)(iVar4 + param_4 + param_5) +
                  (int)*(char *)(iVar4 + param_6) + (int)*(char *)(iVar4 + param_4 + param_6) +
                  (int)cVar1 + (int)*pcVar2 >> 3);
      iVar3 = iVar3 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* _gleUbyteFilter1 @ 0xf77c8 (52 bytes) */
int _gleUbyteFilter1(param_1, param_2, param_3, param_4)
  int param_1;
  byte *param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      bVar1 = *param_2;
      pbVar2 = param_2 + param_4;
      param_2 = param_2 + 1;
      *(char *)(param_1 + iVar3) = (char)((int)((uint)bVar1 + (uint)*pbVar2) >> 1);
      iVar3 = iVar3 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    return;
  }
  return;
}

/* _gleUbyteFilter2 @ 0xf77fc (80 bytes) */
int _gleUbyteFilter2(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = 0;
  if (param_3 < 1) {
    return;
  }
  pbVar3 = (byte *)(param_2 + param_4 + param_5);
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    *(char *)(param_1 + iVar2) =
         (char)((int)((uint)*(byte *)(param_2 + iVar2) + (uint)*(byte *)(param_2 + iVar2 + param_4)
                      + (uint)*(byte *)(param_2 + iVar2 + param_5) + (uint)bVar1) >> 2);
    iVar2 = iVar2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return;
}

/* _gleUbyteFilter3 @ 0xf784c (144 bytes) */
int _gleUbyteFilter3(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = 0;
  if (0 < param_3) {
    pbVar5 = (byte *)(param_2 + param_5 + param_6);
    do {
      iVar3 = param_2 + iVar4;
      bVar1 = *pbVar5;
      pbVar2 = pbVar5 + param_4;
      pbVar5 = pbVar5 + 1;
      *(char *)(param_1 + iVar4) =
           (char)((int)((uint)*(byte *)(param_2 + iVar4) + (uint)*(byte *)(iVar3 + param_4) +
                        (uint)*(byte *)(iVar3 + param_5) +
                        (uint)*(byte *)(iVar3 + param_4 + param_5) +
                        (uint)*(byte *)(iVar3 + param_6) +
                        (uint)*(byte *)(iVar3 + param_4 + param_6) + (uint)bVar1 + (uint)*pbVar2) >>
                 3);
      iVar4 = iVar4 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

/* _gleShortFilter1 @ 0xf78dc (60 bytes) */
int _gleShortFilter1(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if ((int)(param_3 << 1) < 1) {
    return;
  }
  uVar2 = param_3 & 0x7fffffff;
  do {
    *(short *)(param_1 + iVar1) =
         (short)((int)*(short *)(param_2 + iVar1) + (int)*(short *)(param_2 + iVar1 + param_4) >> 1)
    ;
    iVar1 = iVar1 + 2;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

/* _gleShortFilter2 @ 0xf7918 (80 bytes) */
int _gleShortFilter2(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if ((int)(param_3 << 1) < 1) {
    return;
  }
  uVar3 = param_3 & 0x7fffffff;
  do {
    iVar1 = param_2 + iVar2;
    *(short *)(param_1 + iVar2) =
         (short)((int)*(short *)(param_2 + iVar2) + (int)*(short *)(iVar1 + param_4) +
                 (int)*(short *)(iVar1 + param_5) + (int)*(short *)(iVar1 + param_4 + param_5) >> 2)
    ;
    iVar2 = iVar2 + 2;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}

/* _gleShortFilter3 @ 0xf7968 (148 bytes) */
int _gleShortFilter3(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  
  iVar4 = 0;
  if (0 < (int)(param_3 << 1)) {
    uVar6 = param_3 & 0x7fffffff;
    psVar5 = (short *)(param_2 + param_5 + param_6);
    do {
      iVar3 = param_2 + iVar4;
      sVar1 = *psVar5;
      psVar2 = (short *)((int)psVar5 + param_4);
      psVar5 = psVar5 + 1;
      *(short *)(param_1 + iVar4) =
           (short)((int)*(short *)(param_2 + iVar4) + (int)*(short *)(iVar3 + param_4) +
                   (int)*(short *)(iVar3 + param_5) + (int)*(short *)(iVar3 + param_4 + param_5) +
                   (int)*(short *)(iVar3 + param_6) + (int)*(short *)(iVar3 + param_4 + param_6) +
                   (int)sVar1 + (int)*psVar2 >> 3);
      iVar4 = iVar4 + 2;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}

/* _gleFloatFilter1 @ 0xf7db4 (84 bytes) */
int _gleFloatFilter1(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  int iVar2;
  uint uVar3;
  
  fVar1 = FLOAT_00108e90;
  iVar2 = 0;
  if ((int)(param_3 << 2) < 1) {
    return;
  }
  uVar3 = param_3 & 0x3fffffff;
  do {
    *(float *)(param_1 + iVar2) =
         (*(float *)(param_2 + iVar2) + *(float *)(param_2 + iVar2 + param_4)) * fVar1;
    iVar2 = iVar2 + 4;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}

/* _gleFloatFilter2 @ 0xf7e08 (104 bytes) */
int _gleFloatFilter2(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  fVar1 = FLOAT_00108f88;
  iVar3 = 0;
  if ((int)(param_3 << 2) < 1) {
    return;
  }
  uVar4 = param_3 & 0x3fffffff;
  do {
    iVar2 = param_2 + iVar3;
    *(float *)(param_1 + iVar3) =
         (*(float *)(param_2 + iVar3) + *(float *)(iVar2 + param_4) + *(float *)(iVar2 + param_5) +
         *(float *)(iVar2 + param_4 + param_5)) * fVar1;
    iVar3 = iVar3 + 4;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  return;
}

/* _gleFloatFilter3 @ 0xf7e70 (156 bytes) */
int _gleFloatFilter3(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  float fVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  
  fVar3 = FLOAT_00108f4c;
  iVar5 = 0;
  if (0 < (int)(param_3 << 2)) {
    uVar7 = param_3 & 0x3fffffff;
    pfVar6 = (float *)(param_2 + param_5 + param_6);
    do {
      iVar4 = param_2 + iVar5;
      fVar1 = *pfVar6;
      pfVar2 = (float *)((int)pfVar6 + param_4);
      pfVar6 = pfVar6 + 1;
      *(float *)(param_1 + iVar5) =
           (*(float *)(param_2 + iVar5) + *(float *)(iVar4 + param_4) + *(float *)(iVar4 + param_5)
            + *(float *)(iVar4 + param_4 + param_5) + *(float *)(iVar4 + param_6) +
            *(float *)(iVar4 + param_4 + param_6) + fVar1 + *pfVar2) * fVar3;
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}

/* _gleHalfFloatFilter1 @ 0xf7f0c (284 bytes) */
int _gleHalfFloatFilter1(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  
  fVar3 = FLOAT_00108e90;
  iVar5 = 0;
  if (0 < param_3 << 1) {
    do {
      dVar6 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(param_2 + iVar5));
      dVar7 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(param_2 + iVar5 + param_4));
      fVar1 = (float)(dVar6 + dVar7) * fVar3;
      uVar2 = (uint)GH_F2U(fVar1) & 0x7f800000;
      uVar4 = (ushort)((uint)GH_F2U(fVar1) >> 0x10) & 0x8000;
      if (uVar2 < 0x47800000) {
        if (uVar2 < 0x38000001) {
          uVar4 = uVar4 | (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff | 0x800000) >>
                                  ((0x38000000 - uVar2 >> 0x17) + 0xe & 0x3f));
        }
        else {
          uVar4 = uVar4 | (ushort)(uVar2 + 0xc8000000 >> 0xd) |
                  (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff) >> 0xd);
        }
      }
      else if ((uVar2 == 0x7f800000) && (((uint)GH_F2U(fVar1) & 1) != 0)) {
        uVar4 = uVar4 | 0x7fff;
      }
      else {
        uVar4 = uVar4 | 0x7c00;
      }
      *(ushort *)(param_1 + iVar5) = uVar4;
      iVar5 = iVar5 + 2;
    } while (iVar5 < param_3 << 1);
  }
  return;
}

/* _gleHalfFloatFilter2 @ 0xf8028 (316 bytes) */
int _gleHalfFloatFilter2(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  fVar3 = FLOAT_00108f88;
  iVar6 = 0;
  if (0 < param_3 << 1) {
    do {
      iVar5 = param_2 + iVar6;
      dVar7 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(param_2 + iVar6));
      dVar8 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + param_4));
      dVar9 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + param_5));
      dVar10 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + param_4 + param_5));
      fVar1 = (float)((double)(float)((double)(float)(dVar7 + dVar8) + dVar9) + dVar10) * fVar3;
      uVar2 = (uint)GH_F2U(fVar1) & 0x7f800000;
      uVar4 = (ushort)((uint)GH_F2U(fVar1) >> 0x10) & 0x8000;
      if (uVar2 < 0x47800000) {
        if (uVar2 < 0x38000001) {
          uVar4 = uVar4 | (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff | 0x800000) >>
                                  ((0x38000000 - uVar2 >> 0x17) + 0xe & 0x3f));
        }
        else {
          uVar4 = uVar4 | (ushort)(uVar2 + 0xc8000000 >> 0xd) |
                  (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff) >> 0xd);
        }
      }
      else if ((uVar2 == 0x7f800000) && (((uint)GH_F2U(fVar1) & 1) != 0)) {
        uVar4 = uVar4 | 0x7fff;
      }
      else {
        uVar4 = uVar4 | 0x7c00;
      }
      *(ushort *)(param_1 + iVar6) = uVar4;
      iVar6 = iVar6 + 2;
    } while (iVar6 < param_3 << 1);
  }
  return;
}

/* _gleHalfFloatFilter3 @ 0xf8164 (380 bytes) */
int _gleHalfFloatFilter3(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  float fVar1;
  uint uVar2;
  float fVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  
  fVar3 = FLOAT_00108f4c;
  iVar7 = 0;
  if (0 < param_3 << 1) {
    puVar5 = (ushort *)(param_2 + param_5 + param_6);
    do {
      iVar6 = param_2 + iVar7;
      dVar8 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(param_2 + iVar7));
      dVar9 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + param_4));
      dVar10 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + param_5));
      dVar11 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + param_4 + param_5));
      dVar12 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + param_6));
      dVar13 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + param_4 + param_6));
      dVar14 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*puVar5);
      dVar15 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)((int)puVar5 + param_4));
      fVar1 = (float)((double)(float)((double)(float)((double)(float)((double)(float)((double)(float
                                                  )((double)(float)(dVar8 + dVar9) + dVar10) +
                                                  dVar11) + dVar12) + dVar13) + dVar14) + dVar15) *
              fVar3;
      uVar2 = (uint)GH_F2U(fVar1) & 0x7f800000;
      uVar4 = (ushort)((uint)GH_F2U(fVar1) >> 0x10) & 0x8000;
      if (uVar2 < 0x47800000) {
        if (uVar2 < 0x38000001) {
          uVar4 = uVar4 | (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff | 0x800000) >>
                                  ((0x38000000 - uVar2 >> 0x17) + 0xe & 0x3f));
        }
        else {
          uVar4 = uVar4 | (ushort)(uVar2 + 0xc8000000 >> 0xd) |
                  (ushort)(((uint)GH_F2U(fVar1) & 0x7fffff) >> 0xd);
        }
      }
      else if ((uVar2 == 0x7f800000) && (((uint)GH_F2U(fVar1) & 1) != 0)) {
        uVar4 = uVar4 | 0x7fff;
      }
      else {
        uVar4 = uVar4 | 0x7c00;
      }
      *(ushort *)(param_1 + iVar7) = uVar4;
      iVar7 = iVar7 + 2;
      puVar5 = puVar5 + 1;
    } while (iVar7 < param_3 << 1);
  }
  return;
}

/* _gle332Filter1 @ 0xf82e0 (72 bytes) */
int _gle332Filter1(param_1, param_2, param_3, param_4)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  *param_1 = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) >> 1) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) >> 1) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) >> 1);
  return;
}

/* _gle332Filter2 @ 0xf8328 (140 bytes) */
int _gle332Filter2(param_1, param_2, param_3, param_4, param_5)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  bVar3 = param_2[param_5];
  bVar4 = param_2[param_5 + param_4];
  *param_1 = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) + (bVar3 & 0xe0) + (bVar4 & 0xe0) >> 2) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) + (bVar3 & 0x1c) + (bVar4 & 0x1c) >> 2) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) + (bVar3 & 3) + (bVar4 & 3) >> 2) & 3;
  return;
}

/* _gle332Filter3 @ 0xf83b4 (260 bytes) */
int _gle332Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  bVar3 = param_2[param_5];
  bVar4 = param_2[param_5 + param_4];
  bVar5 = param_2[param_6];
  bVar6 = param_2[param_6 + param_4];
  bVar7 = param_2[param_6 + param_5];
  bVar8 = param_2[param_6 + param_5 + param_4];
  *param_1 = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) + (bVar3 & 0xe0) + (bVar4 & 0xe0) +
                    (bVar5 & 0xe0) + (bVar6 & 0xe0) + (bVar7 & 0xe0) + (bVar8 & 0xe0) >> 3) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) + (bVar3 & 0x1c) + (bVar4 & 0x1c) +
                    (bVar5 & 0x1c) + (bVar6 & 0x1c) + (bVar7 & 0x1c) + (bVar8 & 0x1c) >> 3) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) + (bVar3 & 3) + (bVar4 & 3) + (bVar5 & 3) +
                    (bVar6 & 3) + (bVar7 & 3) + (bVar8 & 3) >> 3) & 3;
  return;
}

/* _gle233RevFilter1 @ 0xf84b8 (72 bytes) */
int _gle233RevFilter1(param_1, param_2, param_3, param_4)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  *param_1 = (byte)((bVar1 & 7) + (bVar2 & 7) >> 1) |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) >> 1) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) >> 1) & 0xc0;
  return;
}

/* _gle233RevFilter2 @ 0xf8500 (140 bytes) */
int _gle233RevFilter2(param_1, param_2, param_3, param_4, param_5)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  bVar3 = param_2[param_5];
  bVar4 = param_2[param_5 + param_4];
  *param_1 = (byte)((bVar1 & 7) + (bVar2 & 7) + (bVar3 & 7) + (bVar4 & 7) >> 2) & 7 |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) + (bVar3 & 0x38) + (bVar4 & 0x38) >> 2) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) + (bVar3 & 0xc0) + (bVar4 & 0xc0) >> 2) & 0xc0;
  return;
}

/* _gle233RevFilter3 @ 0xf858c (260 bytes) */
int _gle233RevFilter3(param_1, param_2, param_3, param_4, param_5, param_6)
  byte *param_1;
  byte *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar1 = *param_2;
  bVar2 = param_2[param_4];
  bVar3 = param_2[param_5];
  bVar4 = param_2[param_5 + param_4];
  bVar5 = param_2[param_6];
  bVar6 = param_2[param_6 + param_4];
  bVar7 = param_2[param_6 + param_5];
  bVar8 = param_2[param_6 + param_5 + param_4];
  *param_1 = (byte)((bVar1 & 7) + (bVar2 & 7) + (bVar3 & 7) + (bVar4 & 7) + (bVar5 & 7) +
                    (bVar6 & 7) + (bVar7 & 7) + (bVar8 & 7) >> 3) & 7 |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) + (bVar3 & 0x38) + (bVar4 & 0x38) +
                    (bVar5 & 0x38) + (bVar6 & 0x38) + (bVar7 & 0x38) + (bVar8 & 0x38) >> 3) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) + (bVar3 & 0xc0) + (bVar4 & 0xc0) +
                    (bVar5 & 0xc0) + (bVar6 & 0xc0) + (bVar7 & 0xc0) + (bVar8 & 0xc0) >> 3) & 0xc0;
  return;
}

/* _gle565Filter1 @ 0xf8690 (72 bytes) */
int _gle565Filter1(param_1, param_2, param_3, param_4)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) >> 1) & 0xf800 |
             (ushort)((uVar1 & 0x7e0) + (uVar2 & 0x7e0) >> 1) & 0x7e0 |
             (ushort)((uVar1 & 0x1f) + (uVar2 & 0x1f) >> 1);
  return;
}

/* _gle565Filter2 @ 0xf86d8 (140 bytes) */
int _gle565Filter2(param_1, param_2, param_3, param_4, param_5)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  uVar3 = *(ushort *)((int)param_2 + param_5);
  uVar4 = *(ushort *)((int)param_2 + param_5 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) + (uVar3 & 0xf800) + (uVar4 & 0xf800) >> 2
                     ) & 0xf800 |
             (ushort)((uVar1 & 0x7e0) + (uVar2 & 0x7e0) + (uVar3 & 0x7e0) + (uVar4 & 0x7e0) >> 2) &
             0x7e0 | (ushort)((uVar1 & 0x1f) + (uVar2 & 0x1f) + (uVar3 & 0x1f) + (uVar4 & 0x1f) >> 2
                             ) & 0x1f;
  return;
}

/* _gle565Filter3 @ 0xf8764 (260 bytes) */
int _gle565Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  uVar3 = *(ushort *)((int)param_2 + param_5);
  uVar4 = *(ushort *)((int)param_2 + param_5 + param_4);
  uVar5 = *(ushort *)((int)param_2 + param_6);
  uVar6 = *(ushort *)((int)param_2 + param_6 + param_4);
  uVar7 = *(ushort *)((int)param_2 + param_6 + param_5);
  uVar8 = *(ushort *)((int)param_2 + param_6 + param_5 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) + (uVar3 & 0xf800) + (uVar4 & 0xf800) +
                      (uVar5 & 0xf800) + (uVar6 & 0xf800) + (uVar7 & 0xf800) + (uVar8 & 0xf800) >> 3
                     ) & 0xf800 |
             (ushort)((uVar1 & 0x7e0) + (uVar2 & 0x7e0) + (uVar3 & 0x7e0) + (uVar4 & 0x7e0) +
                      (uVar5 & 0x7e0) + (uVar6 & 0x7e0) + (uVar7 & 0x7e0) + (uVar8 & 0x7e0) >> 3) &
             0x7e0 | (ushort)((uVar1 & 0x1f) + (uVar2 & 0x1f) + (uVar3 & 0x1f) + (uVar4 & 0x1f) +
                              (uVar5 & 0x1f) + (uVar6 & 0x1f) + (uVar7 & 0x1f) + (uVar8 & 0x1f) >> 3
                             ) & 0x1f;
  return;
}

/* _gle4444Filter1 @ 0xf8868 (92 bytes) */
int _gle4444Filter1(param_1, param_2, param_3, param_4)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) >> 1) & 0xf000 |
             (ushort)((uVar1 & 0xf00) + (uVar2 & 0xf00) >> 1) & 0xf00 |
             (ushort)((uVar1 & 0xf0) + (uVar2 & 0xf0) >> 1) & 0xf0 |
             (ushort)((uVar1 & 0xf) + (uVar2 & 0xf) >> 1);
  return;
}

/* _gle4444Filter2 @ 0xf88c4 (176 bytes) */
int _gle4444Filter2(param_1, param_2, param_3, param_4, param_5)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  uVar3 = *(ushort *)((int)param_2 + param_5);
  uVar4 = *(ushort *)((int)param_2 + param_5 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) + (uVar3 & 0xf000) + (uVar4 & 0xf000) >> 2
                     ) & 0xf000 |
             (ushort)((uVar1 & 0xf00) + (uVar2 & 0xf00) + (uVar3 & 0xf00) + (uVar4 & 0xf00) >> 2) &
             0xf00 | (ushort)((uVar1 & 0xf0) + (uVar2 & 0xf0) + (uVar3 & 0xf0) + (uVar4 & 0xf0) >> 2
                             ) & 0xf0 |
             (ushort)((uVar1 & 0xf) + (uVar2 & 0xf) + (uVar3 & 0xf) + (uVar4 & 0xf) >> 2) & 0xf;
  return;
}

/* _gle4444Filter3 @ 0xf8974 (328 bytes) */
int _gle4444Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  ushort *param_1;
  ushort *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar1 = *param_2;
  uVar2 = *(ushort *)((int)param_2 + param_4);
  uVar3 = *(ushort *)((int)param_2 + param_5);
  uVar4 = *(ushort *)((int)param_2 + param_5 + param_4);
  uVar5 = *(ushort *)((int)param_2 + param_6);
  uVar6 = *(ushort *)((int)param_2 + param_6 + param_4);
  uVar7 = *(ushort *)((int)param_2 + param_6 + param_5);
  uVar8 = *(ushort *)((int)param_2 + param_6 + param_5 + param_4);
  *param_1 = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) + (uVar3 & 0xf000) + (uVar4 & 0xf000) +
                      (uVar5 & 0xf000) + (uVar6 & 0xf000) + (uVar7 & 0xf000) + (uVar8 & 0xf000) >> 3
                     ) & 0xf000 |
             (ushort)((uVar1 & 0xf00) + (uVar2 & 0xf00) + (uVar3 & 0xf00) + (uVar4 & 0xf00) +
                      (uVar5 & 0xf00) + (uVar6 & 0xf00) + (uVar7 & 0xf00) + (uVar8 & 0xf00) >> 3) &
             0xf00 | (ushort)((uVar1 & 0xf0) + (uVar2 & 0xf0) + (uVar3 & 0xf0) + (uVar4 & 0xf0) +
                              (uVar5 & 0xf0) + (uVar6 & 0xf0) + (uVar7 & 0xf0) + (uVar8 & 0xf0) >> 3
                             ) & 0xf0 |
             (ushort)((uVar1 & 0xf) + (uVar2 & 0xf) + (uVar3 & 0xf) + (uVar4 & 0xf) + (uVar5 & 0xf)
                      + (uVar6 & 0xf) + (uVar7 & 0xf) + (uVar8 & 0xf) >> 3) & 0xf;
  return;
}

/* _gles8s8Filter1 @ 0xfa1e8 (60 bytes) */
int _gles8s8Filter1(param_1, param_2, param_3, param_4)
  ushort *param_1;
  undefined2 *param_2;
  undefined4 param_3;
  int param_4;
{
  *param_1 = ((short)(char)((ushort)*param_2 >> 8) +
             (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_4) >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*param_2 +
                            (int)(char)*(undefined2 *)((int)param_2 + param_4)) >> 1) & 0xff;
  return;
}

/* _gles8s8Filter2 @ 0xfa224 (112 bytes) */
int _gles8s8Filter2(param_1, param_2, param_3, param_4, param_5)
  ushort *param_1;
  undefined2 *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)((int)param_2 + param_5 + param_4);
  *param_1 = ((short)(char)((ushort)*param_2 >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_4) >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_5) >> 8) +
             (short)(char)((ushort)uVar1 >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*param_2 +
                             (int)(char)*(undefined2 *)((int)param_2 + param_4) +
                             (int)(char)*(undefined2 *)((int)param_2 + param_5) + (int)(char)uVar1)
                     >> 1) & 0xff;
  return;
}

/* _gles8s8Filter3 @ 0xfa294 (224 bytes) */
int _gles8s8Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  ushort *param_1;
  undefined2 *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar1 = *(undefined2 *)((int)param_2 + param_5 + param_4);
  uVar2 = *(undefined2 *)((int)param_2 + param_6 + param_4);
  uVar3 = *(undefined2 *)((int)param_2 + param_6 + param_5);
  uVar4 = *(undefined2 *)((int)param_2 + param_6 + param_5 + param_4);
  *param_1 = ((short)(char)((ushort)*param_2 >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_4) >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_5) >> 8) +
              (short)(char)((ushort)uVar1 >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)param_2 + param_6) >> 8) +
              (short)(char)((ushort)uVar2 >> 8) + (short)(char)((ushort)uVar3 >> 8) +
             (short)(char)((ushort)uVar4 >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*param_2 +
                             (int)(char)*(undefined2 *)((int)param_2 + param_4) +
                             (int)(char)*(undefined2 *)((int)param_2 + param_5) + (int)(char)uVar1 +
                             (int)(char)*(undefined2 *)((int)param_2 + param_6) + (int)(char)uVar2 +
                             (int)(char)uVar3 + (int)(char)uVar4) >> 1) & 0xff;
  return;
}

/* _gles16s16Filter1 @ 0xfa374 (52 bytes) */
int _gles16s16Filter1(param_1, param_2, param_3, param_4)
  uint *param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  *param_1 = ((*param_2 >> 0x10) + (*(int *)((int)param_2 + param_4) >> 0x10)) * 0x8000 &
             0xffff0000U |
             (uint)((int)(short)*param_2 + (int)(short)*(int *)((int)param_2 + param_4)) >> 1 &
             0xffff;
  return;
}

/* _gles16s16Filter2 @ 0xfa3a8 (96 bytes) */
int _gles16s16Filter2(param_1, param_2, param_3, param_4, param_5)
  uint *param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  
  iVar1 = *(int *)((int)param_2 + param_5 + param_4);
  *param_1 = ((*param_2 >> 0x10) + (*(int *)((int)param_2 + param_4) >> 0x10) +
              (*(int *)((int)param_2 + param_5) >> 0x10) + (iVar1 >> 0x10)) * 0x8000 & 0xffff0000U |
             (uint)((int)(short)*param_2 + (int)(short)*(int *)((int)param_2 + param_4) +
                    (int)(short)*(int *)((int)param_2 + param_5) + (int)(short)iVar1) >> 1 & 0xffff;
  return;
}

/* _gles16s16Filter3 @ 0xfa408 (192 bytes) */
int _gles16s16Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  uint *param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)((int)param_2 + param_5 + param_4);
  iVar2 = *(int *)((int)param_2 + param_6 + param_4);
  iVar3 = *(int *)((int)param_2 + param_6 + param_5);
  iVar4 = *(int *)((int)param_2 + param_6 + param_5 + param_4);
  *param_1 = ((*param_2 >> 0x10) + (*(int *)((int)param_2 + param_4) >> 0x10) +
              (*(int *)((int)param_2 + param_5) >> 0x10) + (iVar1 >> 0x10) +
              (*(int *)((int)param_2 + param_6) >> 0x10) + (iVar2 >> 0x10) + (iVar3 >> 0x10) +
             (iVar4 >> 0x10)) * 0x8000 & 0xffff0000U |
             (uint)((int)(short)*param_2 + (int)(short)*(int *)((int)param_2 + param_4) +
                    (int)(short)*(int *)((int)param_2 + param_5) + (int)(short)iVar1 +
                    (int)(short)*(int *)((int)param_2 + param_6) + (int)(short)iVar2 +
                    (int)(short)iVar3 + (int)(short)iVar4) >> 1 & 0xffff;
  return;
}

/* _gle1616Filter1 @ 0xfa4c8 (52 bytes) */
int _gle1616Filter1(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint *param_2;
  undefined4 param_3;
  int param_4;
{
  *param_1 = ((*param_2 >> 0x10) + (*(uint *)((int)param_2 + param_4) >> 0x10)) * 0x8000 &
             0xffff0000 | (*param_2 & 0xffff) + (*(uint *)((int)param_2 + param_4) & 0xffff) >> 1;
  return;
}

/* _gle1616Filter2 @ 0xfa4fc (96 bytes) */
int _gle1616Filter2(param_1, param_2, param_3, param_4, param_5)
  uint *param_1;
  uint *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)param_2 + param_5 + param_4);
  *param_1 = ((*param_2 >> 0x10) + (*(uint *)((int)param_2 + param_4) >> 0x10) +
              (*(uint *)((int)param_2 + param_5) >> 0x10) + (uVar1 >> 0x10)) * 0x8000 & 0xffff0000 |
             (*param_2 & 0xffff) + (*(uint *)((int)param_2 + param_4) & 0xffff) +
             (*(uint *)((int)param_2 + param_5) & 0xffff) + (uVar1 & 0xffff) >> 1 & 0xffff;
  return;
}

/* _gle1616Filter3 @ 0xfa55c (192 bytes) */
int _gle1616Filter3(param_1, param_2, param_3, param_4, param_5, param_6)
  uint *param_1;
  uint *param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)((int)param_2 + param_5 + param_4);
  uVar2 = *(uint *)((int)param_2 + param_6 + param_4);
  uVar3 = *(uint *)((int)param_2 + param_6 + param_5);
  uVar4 = *(uint *)((int)param_2 + param_6 + param_5 + param_4);
  *param_1 = ((*param_2 >> 0x10) + (*(uint *)((int)param_2 + param_4) >> 0x10) +
              (*(uint *)((int)param_2 + param_5) >> 0x10) + (uVar1 >> 0x10) +
              (*(uint *)((int)param_2 + param_6) >> 0x10) + (uVar2 >> 0x10) + (uVar3 >> 0x10) +
             (uVar4 >> 0x10)) * 0x8000 & 0xffff0000 |
             (*param_2 & 0xffff) + (*(uint *)((int)param_2 + param_4) & 0xffff) +
             (*(uint *)((int)param_2 + param_5) & 0xffff) + (uVar1 & 0xffff) +
             (*(uint *)((int)param_2 + param_6) & 0xffff) + (uVar2 & 0xffff) + (uVar3 & 0xffff) +
             (uVar4 & 0xffff) >> 1 & 0xffff;
  return;
}

/* _gleGenerateMipmapData @ 0xfa61c (5348 bytes) */
int _gleGenerateMipmapData(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int in_r8;
  undefined *puVar14;
  int in_r10;
  int iVar15;
  int iVar16;
  code *pcVar17;
  code *pcVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  byte in_xer_so = 0;
  byte bVar31;
  byte in_cr1;
  byte bVar32;
  byte bVar33;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte bVar34;
  int iStack00000018;
  int iStack0000001c;
  int iStack00000020;
  int iStack00000028;
  int local_1b0;
  undefined4 local_1ac;
  undefined1 auStack_1a8 [4];
  undefined1 auStack_1a4 [4];
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined1 auStack_198 [4];
  undefined1 auStack_194 [4];
  undefined4 local_190;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  undefined1 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined1 auStack_138 [4];
  undefined1 auStack_134 [4];
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  uint local_114;
  uint local_110;
  undefined1 local_d4;
  int local_d0;
  int local_cc;
  uint local_c8;
  uint local_c4;
  int local_c0;
  int local_bc;
  uint local_b8;
  int local_b4;
  code *local_b0;
  int local_ac;
  int local_a8;
  uint local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  
  uVar5 = *(ushort *)(param_2 + 0x24) & 0xf;
  local_b8 = 0;
  local_b4 = 0;
  if (uVar5 == 1) {
    local_bc = 3;
  }
  else {
    if (uVar5 < 2) {
      if ((*(ushort *)(param_2 + 0x24) & 0xf) != 0) {
        return;
      }
    }
    else if (uVar5 != 3) {
      if (uVar5 != 4) {
        return;
      }
      local_bc = 1;
      goto LAB_000fa6b0;
    }
    local_bc = 2;
  }
LAB_000fa6b0:
  local_ac = param_3 * 0x168;
  iVar6 = param_2 + local_ac + param_4 * 0x18;
  local_d0 = iVar6 + 0xc4;
  iStack00000018 = param_1;
  iStack0000001c = param_2;
  iStack00000020 = param_3;
  iStack00000028 = param_5;
  iVar6 = _gleComponents((uint)*(ushort *)(iVar6 + 0xd4));
  pcVar17 = (code *)PTR__gle8888Filter2_001115d4;
  pcVar18 = (code *)PTR__gle8888Filter3_001115d0;
  uVar5 = *(ushort *)(local_d0 + 0x12);
  uVar27 = (uint)uVar5;
  bVar34 = (uVar27 < 0x8032) << 3 | (0x8032 < uVar27) << 2 | (uVar27 == 0x8032) << 1 | in_xer_so & 1
  ;
  if (uVar27 == 0x8032) {
    local_b0 = (code *)PTR__gle332Filter1_0011156c;
    pcVar17 = (code *)PTR__gle332Filter2_00111568;
    pcVar18 = (code *)PTR__gle332Filter3_00111564;
LAB_000faa98:
    iVar8 = 1;
    goto LAB_000facc8;
  }
  if (0x8032 >= uVar27) {
    bVar34 = (uVar27 < 0x1400) << 3 | (0x1400 < uVar27) << 2 | (uVar27 == 0x1400) << 1 |
             in_xer_so & 1;
    iVar8 = iVar6;
    if (uVar27 == 0x1400) {
      local_b0 = (code *)PTR__gleByteFilter1_001115c0;
      pcVar17 = (code *)PTR__gleByteFilter2_001115bc;
      pcVar18 = (code *)PTR__gleByteFilter3_001115b8;
      goto LAB_000facc8;
    }
    if (0x1400 >= uVar27) {
      bVar34 = (uVar27 < 5) << 3 | (5 < uVar27) << 2 | (uVar27 == 5) << 1 | in_xer_so & 1;
      if (uVar27 == 5) {
        local_b0 = (code *)PTR__gle1616Filter1_001114dc;
        pcVar17 = (code *)PTR__gle1616Filter2_001114d8;
        pcVar18 = (code *)PTR__gle1616Filter3_001114d4;
      }
      else {
        if (5 >= uVar27) {
          if (uVar27 == 0) {
            iVar6 = 4;
            puVar14 = &DAT_0010a634;
            local_b0 = (code *)PTR__gle8888Filter1_001115d8;
            local_b4 = *(int *)(local_d0 + 0x14);
            iVar8 = _malloc((uint)*(ushort *)(local_d0 + 4) * 4 * (uint)*(ushort *)(local_d0 + 6) *
                            (uint)*(ushort *)(local_d0 + 8));
            bVar34 = (iVar8 < 0) << 3 | (0 < iVar8) << 2 | (iVar8 == 0) << 1 | in_xer_so & 1;
            *(int *)(local_d0 + 0x14) = iVar8;
            if (iVar8 == 0) {
              return;
            }
            uVar10 = _gleRowBytes(0x1908,0x8035,(uint)*(ushort *)(local_d0 + 4));
            uVar11 = _gleRowBytes((uint)*(ushort *)(local_d0 + 0x10),0,
                                  (uint)*(ushort *)(local_d0 + 0xc));
            _glgConvertType((uint)*(ushort *)(local_d0 + 0x10),0,auStack_1a8,auStack_1a4,param_5,
                            in_r8,puVar14,in_r10);
            puVar12 = auStack_198;
            puVar13 = auStack_194;
            _glgConvertType(0x1908,0x8035,puVar12,puVar13,param_5,in_r8,puVar14,in_r10);
            local_190 = 2;
            local_184 = (uint)*(ushort *)(local_d0 + 4);
            local_180 = (uint)*(ushort *)(local_d0 + 6);
            local_1b0 = local_b4;
            local_1a0 = *(undefined4 *)(local_d0 + 0x14);
            local_144 = (undefined1)uVar5;
            local_1ac = uVar11;
            local_19c = uVar10;
            local_18c = uVar27;
            local_188 = uVar27;
            _glgProcessPixels(iStack00000018 + 0x31a8,&local_1b0,puVar12,puVar13,param_5,in_r8,
                              iStack00000018,in_r10);
            iVar8 = 4;
            goto LAB_000facc8;
          }
          bVar34 = (uVar27 == 0) << 3 | (1 < uVar27) << 2 | (uVar27 == 1) << 1 | in_xer_so & 1;
          if (uVar27 != 1) {
            return;
          }
          local_b0 = (code *)PTR__gles8s8Filter1_001114e8;
          pcVar17 = (code *)PTR__gles8s8Filter2_001114e4;
          pcVar18 = (code *)PTR__gles8s8Filter3_001114e0;
          goto LAB_000fac40;
        }
        bVar34 = (uVar27 < 7) << 3 | (7 < uVar27) << 2 | (uVar27 == 7) << 1 | in_xer_so & 1;
        if (uVar27 == 7) {
          local_b0 = (code *)PTR__gle8s8s8s8Filter1_001114c4;
          pcVar17 = (code *)PTR__gle8s8s8s8Filter2_001114c0;
          pcVar18 = (code *)PTR__gle8s8s8s8Filter3_001114bc;
        }
        else if (uVar27 < 7) {
          local_b0 = (code *)PTR__gles16s16Filter1_001114d0;
          pcVar17 = (code *)PTR__gles16s16Filter2_001114cc;
          pcVar18 = (code *)PTR__gles16s16Filter3_001114c8;
        }
        else {
          bVar34 = (uVar27 < 8) << 3 | (8 < uVar27) << 2 | (uVar27 == 8) << 1 | in_xer_so & 1;
          if (uVar27 != 8) {
            return;
          }
          local_b0 = (code *)PTR__gles8s8s8s8Filter1_001114b8;
          pcVar17 = (code *)PTR__gles8s8s8s8Filter2_001114b4;
          pcVar18 = (code *)PTR__gles8s8s8s8Filter3_001114b0;
        }
      }
      goto LAB_000facc4;
    }
    bVar34 = (uVar27 < 0x1404) << 3 | (0x1404 < uVar27) << 2 | (uVar27 == 0x1404) << 1 |
             in_xer_so & 1;
    if (uVar27 == 0x1404) {
      local_b0 = (code *)PTR__gleIntFilter1_00111590;
      pcVar17 = (code *)PTR__gleIntFilter2_0011158c;
      pcVar18 = (code *)PTR__gleIntFilter3_00111588;
    }
    else {
      if (0x1404 >= uVar27) {
        bVar34 = (uVar27 < 0x1402) << 3 | (0x1402 < uVar27) << 2 | (uVar27 == 0x1402) << 1 |
                 in_xer_so & 1;
        if (uVar27 == 0x1402) {
          local_b0 = (code *)PTR__gleShortFilter1_001115a8;
          pcVar17 = (code *)PTR__gleShortFilter2_001115a4;
          pcVar18 = (code *)PTR__gleShortFilter3_001115a0;
        }
        else {
          if (0x1402 >= uVar27) {
            local_b0 = (code *)PTR__gleUbyteFilter1_001115cc;
            pcVar17 = (code *)PTR__gleUbyteFilter2_001115c8;
            pcVar18 = (code *)PTR__gleUbyteFilter3_001115c4;
            goto LAB_000facc8;
          }
          local_b0 = (code *)PTR__gleUshortFilter1_001115b4;
          pcVar17 = (code *)PTR__gleUshortFilter2_001115b0;
          pcVar18 = (code *)PTR__gleUshortFilter3_001115ac;
        }
LAB_000faa54:
        iVar8 = iVar6 << 1;
        goto LAB_000facc8;
      }
      bVar34 = (uVar27 < 0x1406) << 3 | (0x1406 < uVar27) << 2 | (uVar27 == 0x1406) << 1 |
               in_xer_so & 1;
      if (uVar27 == 0x1406) {
        local_b0 = (code *)PTR__gleFloatFilter1_00111584;
        pcVar17 = (code *)PTR__gleFloatFilter2_00111580;
        pcVar18 = (code *)PTR__gleFloatFilter3_0011157c;
      }
      else {
        if (uVar27 >= 0x1406) {
          bVar34 = (uVar27 < 0x140b) << 3 | (0x140b < uVar27) << 2 | (uVar27 == 0x140b) << 1 |
                   in_xer_so & 1;
          if (uVar27 != 0x140b) {
            return;
          }
          local_b0 = (code *)PTR__gleHalfFloatFilter1_00111578;
          pcVar17 = (code *)PTR__gleHalfFloatFilter2_00111574;
          pcVar18 = (code *)PTR__gleHalfFloatFilter3_00111570;
          goto LAB_000faa54;
        }
        local_b0 = (code *)PTR__gleUintFilter1_0011159c;
        pcVar17 = (code *)PTR__gleUintFilter2_00111598;
        pcVar18 = (code *)PTR__gleUintFilter3_00111594;
      }
    }
    iVar8 = iVar6 << 2;
    goto LAB_000facc8;
  }
  bVar34 = (uVar27 < 0x8365) << 3 | (0x8365 < uVar27) << 2 | (uVar27 == 0x8365) << 1 | in_xer_so & 1
  ;
  if (uVar27 == 0x8365) {
LAB_000faac0:
    local_b0 = (code *)PTR__gle4444Filter1_00111548;
    pcVar17 = (code *)PTR__gle4444Filter2_00111544;
    pcVar18 = (code *)PTR__gle4444Filter3_00111540;
LAB_000fac40:
    iVar8 = 2;
  }
  else {
    if (0x8365 < uVar27) {
      if (uVar27 < 0x85bc) {
        if (0x85b9 < uVar27) {
          uVar5 = *(ushort *)(local_d0 + 0x10);
          bVar34 = (uVar5 < 0x85b9) << 3 | (0x85b9 < uVar5) << 2 | (uVar5 == 0x85b9) << 1 |
                   in_xer_so & 1;
          if (uVar5 == 0x85b9) {
            local_b8 = 1;
            local_b0 = (code *)PTR__gle8888Filter1_001115d8;
            iVar8 = 4;
            goto LAB_000facc8;
          }
          local_b0 = (code *)PTR__gle88Filter1_00111524;
          pcVar17 = (code *)PTR__gle88Filter2_00111520;
          pcVar18 = (code *)PTR__gle88Filter3_0011151c;
          goto LAB_000fac40;
        }
        bVar34 = (uVar27 < 0x8367) << 3 | (0x8367 < uVar27) << 2 | (uVar27 == 0x8367) << 1 |
                 in_xer_so & 1;
        if (uVar27 == 0x8367) {
LAB_000fab84:
          local_b0 = (code *)PTR__gle8888Filter1_001115d8;
        }
        else {
          if (uVar27 < 0x8367) {
            local_b0 = (code *)PTR__gle1555RevFilter1_00111530;
            pcVar17 = (code *)PTR__gle1555RevFilter2_0011152c;
            pcVar18 = (code *)PTR__gle1555RevFilter3_00111528;
            goto LAB_000fac40;
          }
          bVar34 = (uVar27 < 0x8368) << 3 | (0x8368 < uVar27) << 2 | (uVar27 == 0x8368) << 1 |
                   in_xer_so & 1;
          if (uVar27 != 0x8368) {
            return;
          }
          local_b0 = (code *)PTR__gle2101010RevFilter1_0011150c;
          pcVar17 = (code *)PTR__gle2101010RevFilter2_00111508;
          pcVar18 = (code *)PTR__gle2101010RevFilter3_00111504;
        }
      }
      else {
        bVar34 = (uVar27 < 0x86da) << 3 | (0x86da < uVar27) << 2 | (uVar27 == 0x86da) << 1 |
                 in_xer_so & 1;
        if (uVar27 == 0x86da) {
          local_b0 = (code *)PTR__gles8s888Filter1_001114f4;
          pcVar17 = (code *)PTR__gles8s888Filter2_001114f0;
          pcVar18 = (code *)PTR__gles8s888Filter3_001114ec;
        }
        else {
          bVar34 = (uVar27 < 0x86db) << 3 | (0x86db < uVar27) << 2 | (uVar27 == 0x86db) << 1 |
                   in_xer_so & 1;
          if (uVar27 != 0x86db) {
            return;
          }
          local_b0 = (code *)PTR__gle88s8s8Filter1_00111500;
          pcVar17 = (code *)PTR__gle88s8s8Filter2_001114fc;
          pcVar18 = (code *)PTR__gle88s8s8Filter3_001114f8;
        }
      }
    }
    else {
      bVar34 = (uVar27 < 0x8036) << 3 | (0x8036 < uVar27) << 2 | (uVar27 == 0x8036) << 1 |
               in_xer_so & 1;
      if (uVar27 != 0x8036) {
        if (0x8036 < uVar27) {
          bVar34 = (uVar27 < 0x8362) << 3 | (0x8362 < uVar27) << 2 | (uVar27 == 0x8362) << 1 |
                   in_xer_so & 1;
          if (uVar27 == 0x8362) {
            local_b0 = (code *)PTR__gle233RevFilter1_00111560;
            pcVar17 = (code *)PTR__gle233RevFilter2_0011155c;
            pcVar18 = (code *)PTR__gle233RevFilter3_00111558;
            goto LAB_000faa98;
          }
          if (uVar27 < 0x8362) {
            return;
          }
          local_b0 = (code *)PTR__gle565Filter1_00111554;
          pcVar17 = (code *)PTR__gle565Filter2_00111550;
          pcVar18 = (code *)PTR__gle565Filter3_0011154c;
        }
        else {
          bVar34 = (uVar27 < 0x8034) << 3 | (0x8034 < uVar27) << 2 | (uVar27 == 0x8034) << 1 |
                   in_xer_so & 1;
          if (uVar27 != 0x8034) {
            if (0x8034 < uVar27) goto LAB_000fab84;
            goto LAB_000faac0;
          }
          local_b0 = (code *)PTR__gle5551Filter1_0011153c;
          pcVar17 = (code *)PTR__gle5551Filter2_00111538;
          pcVar18 = (code *)PTR__gle5551Filter3_00111534;
        }
        goto LAB_000fac40;
      }
      local_b0 = (code *)PTR__gle1010102Filter1_00111518;
      pcVar17 = (code *)PTR__gle1010102Filter2_00111514;
      pcVar18 = (code *)PTR__gle1010102Filter3_00111510;
    }
LAB_000facc4:
    iVar8 = 4;
  }
LAB_000facc8:
  uVar27 = (uint)*(byte *)(local_d0 + 10);
  bVar1 = 1 < local_bc;
  bVar3 = local_bc == 1;
  bVar32 = (local_bc < 1) << 3 | bVar1 << 2 | bVar3 << 1 | in_xer_so & 1;
  local_c0 = uVar27 * 2;
  local_c8 = (uint)*(ushort *)(local_d0 + 6);
  iVar19 = (int)((uint)*(ushort *)(local_d0 + 4) + uVar27 * -2) >> (local_b8 & 0x3f);
  if (bVar1) {
    local_c8 = local_c8 + uVar27 * -2;
  }
  bVar2 = 2 < local_bc;
  bVar4 = local_bc == 2;
  bVar33 = (local_bc < 2) << 3 | bVar2 << 2 | bVar4 << 1 | in_xer_so & 1;
  local_c4 = (uint)*(ushort *)(local_d0 + 8);
  if (bVar2) {
    local_c4 = local_c4 + uVar27 * -2;
  }
  local_74 = iVar8 << 1;
  local_cc = param_4 + 1;
  bVar31 = (uVar27 != 0) << 2 | (uVar27 == 0) << 1 | in_xer_so & 1;
  local_7c = (uint)bVar31 << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar32 << 0x14 |
             (uint)bVar33 << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
             (uint)(in_cr6 & 0xf) << 4 | (uint)(bVar34 & 0xf);
  local_70 = (uint)bVar31 << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar32 << 0x14 |
             (uint)bVar33 << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
             (uint)(in_cr6 & 0xf) << 4 | (uint)(bVar34 & 0xf);
  local_a0 = local_c0 >> 1;
  iVar22 = local_d0;
  local_8c = local_cc;
  local_78 = local_7c;
  local_6c = local_74;
  local_68 = local_74;
  local_64 = local_74;
  local_5c = local_74;
  do {
    if ((((iVar19 < 2) && ((int)local_c8 < 2)) && ((int)local_c4 < 2)) ||
       (iStack00000028 < local_cc)) {
      if (local_b4 != 0) {
        uVar5 = *(ushort *)(local_d0 + 0x10);
        iStack00000028 = local_cc;
        if (((0x83f3 < uVar5) || (0x83f1 < uVar5)) || (iVar6 = 8, uVar5 < 0x83f0)) {
          iVar6 = 0x10;
        }
        local_cc = local_8c;
        _free(*(undefined4 *)(local_d0 + 0x14));
        *(int *)(local_d0 + 0x14) = local_b4;
        if (local_cc < iStack00000028) {
          iVar22 = local_cc * 0x18 + iStack0000001c + local_ac + 0xc4;
          local_cc = iStack00000028 - local_cc;
          iVar19 = iStack00000018 + 0x31a8;
          iVar8 = iStack00000018;
          do {
            local_b4 = *(undefined4 *)(iVar22 + 0x14);
            uVar10 = _malloc(iVar6 * ((int)(*(ushort *)(iVar22 + 4) + 3) >> 2) *
                             ((int)(*(ushort *)(iVar22 + 6) + 3) >> 2));
            *(undefined4 *)(iVar22 + 0x14) = uVar10;
            uVar10 = _gleRowBytes(0x1908,0x8035,(uint)*(ushort *)(iVar22 + 4));
            uVar11 = _gleRowBytes((uint)*(ushort *)(iVar22 + 0x10),0,(uint)*(ushort *)(iVar22 + 0xc)
                                 );
            _glgConvertType(0x1908,0x8035,auStack_138,auStack_134,param_5,in_r8,iVar8,in_r10);
            puVar12 = auStack_128;
            puVar13 = auStack_124;
            _glgConvertType((uint)*(ushort *)(iVar22 + 0x10),0,auStack_128,auStack_124,param_5,in_r8
                            ,iVar8,in_r10);
            local_11c = 0;
            local_120 = 2;
            local_118 = 0;
            local_114 = (uint)*(ushort *)(iVar22 + 4);
            local_110 = (uint)*(ushort *)(iVar22 + 6);
            local_140 = local_b4;
            local_130 = *(undefined4 *)(iVar22 + 0x14);
            iVar22 = iVar22 + 0x18;
            local_d4 = 0;
            local_13c = uVar10;
            local_12c = uVar11;
            _glgProcessPixels(iVar19,&local_140,puVar12,puVar13,param_5,in_r8,iVar8,in_r10);
            _free(local_b4);
            local_cc = local_cc + -1;
          } while (local_cc != 0);
        }
      }
      return;
    }
    iVar7 = iStack0000001c + local_ac + local_cc * 0x18;
    iVar21 = iVar8;
    if (iVar19 == 1) {
      iVar21 = 0;
    }
    iVar25 = (int)(uint)*(ushort *)(iVar22 + 0xc) >> (local_b8 & 0x3f);
    iVar20 = iVar25 * iVar8;
    local_a8 = (iVar25 - (iVar19 + local_c0)) * iVar8;
    iVar25 = 0;
    if (local_c8 != 1) {
      iVar25 = iVar20;
    }
    iVar16 = (uint)*(ushort *)(iVar22 + 0xe) * iVar20;
    iVar15 = ((uint)*(ushort *)(iVar22 + 0xe) - (local_c8 + local_c0)) * iVar20;
    iVar26 = 0;
    if (local_c4 != 1) {
      iVar26 = iVar16;
    }
    local_c8 = (uint)*(ushort *)(iVar7 + 0xca);
    iVar19 = (int)((uint)*(ushort *)(iVar7 + 200) - local_c0) >> (local_b8 & 0x3f);
    if (bVar1) {
      local_c8 = local_c8 - local_c0;
    }
    uVar27 = (uint)*(ushort *)(iVar7 + 0xcc);
    local_c4 = uVar27;
    if (bVar2) {
      local_c4 = uVar27 - local_c0;
    }
    iVar9 = _malloc((uint)*(ushort *)(iVar7 + 0xd0) * (uint)*(ushort *)(iVar7 + 0xd2) * uVar27 *
                    (iVar8 >> (local_b8 & 0x3f)));
    *(int *)(iVar7 + 0xd8) = iVar9;
    iVar22 = *(int *)(iVar22 + 0x14);
    *(byte *)(iVar7 + 0xcf) = *(byte *)(iVar7 + 0xcf) | 0x10;
    if (bVar4) {
      bVar34 = (byte)(local_78 >> 0x18);
      if (!(bool)(bVar34 >> 5 & 1)) {
        iVar15 = iVar9 + iVar8;
        iVar26 = iVar22 + iVar8;
        (*pcVar17)(iVar9,iVar22,iVar6,iVar8,iVar20);
        if (0 < iVar19) {
          iVar22 = iVar26;
          iVar16 = iVar19;
          iVar9 = iVar15;
          do {
            iVar15 = iVar9 + iVar8;
            iVar26 = iVar22 + iVar8 + iVar21;
            (*pcVar17)(iVar9,iVar22,iVar6,iVar21,iVar20);
            iVar16 = iVar16 + -1;
            iVar22 = iVar26;
            iVar9 = iVar15;
          } while (iVar16 != 0);
        }
        iVar9 = iVar15 + iVar8;
        (*pcVar17)(iVar15,iVar26 - iVar8,iVar6,iVar8,iVar20);
        iVar22 = (iVar26 - iVar8) + iVar8 * 2 + local_a8;
      }
      iVar26 = local_74;
      if (0 < (int)local_c8) {
        iVar15 = local_a8 + iVar25;
        uVar27 = local_c8;
        do {
          iVar16 = iVar22;
          iVar23 = iVar9;
          if (!(bool)(bVar34 >> 5 & 1)) {
            iVar23 = iVar9 + iVar8;
            iVar16 = iVar22 + iVar8;
            (*pcVar17)(iVar9,iVar22,iVar6,iVar8,iVar25);
          }
          iVar22 = iVar16;
          iVar9 = iVar19;
          iVar28 = iVar23;
          if (0 < iVar19) {
            do {
              iVar23 = iVar28 + iVar8;
              iVar16 = iVar22 + iVar8 + iVar21;
              (*pcVar17)(iVar28,iVar22,iVar6,iVar21,iVar25);
              iVar9 = iVar9 + -1;
              iVar22 = iVar16;
              iVar28 = iVar23;
            } while (iVar9 != 0);
          }
          iVar9 = iVar23;
          if (!(bool)(bVar34 >> 5 & 1)) {
            iVar22 = iVar16 - iVar8;
            iVar9 = iVar23 + iVar8;
            iVar16 = iVar22 + iVar26;
            (*pcVar17)(iVar23,iVar22,iVar6,iVar8,iVar25);
          }
          uVar27 = uVar27 - 1;
          iVar22 = iVar16 + iVar15;
        } while (uVar27 != 0);
      }
      if (!(bool)(bVar34 >> 5 & 1)) {
        iVar26 = iVar9 + iVar8;
        iVar25 = (iVar22 - iVar20) + iVar8;
        (*pcVar17)(iVar9,iVar22 - iVar20,iVar6,iVar8,iVar20);
        if (0 < iVar19) {
          iVar22 = iVar25;
          iVar15 = iVar19;
          iVar16 = iVar26;
          do {
            iVar26 = iVar16 + iVar8;
            iVar25 = iVar22 + iVar8 + iVar21;
            (*pcVar17)(iVar16,iVar22,iVar6,iVar21,iVar20);
            iVar15 = iVar15 + -1;
            iVar22 = iVar25;
            iVar16 = iVar26;
          } while (iVar15 != 0);
        }
        (*pcVar17)(iVar26,iVar25 - iVar8,iVar6,iVar8,iVar20);
      }
      uVar5 = *(ushort *)(iVar7 + 200);
      in_r10 = 0;
      in_r8 = local_a0;
      iVar22 = local_a0;
LAB_000fb8dc:
      param_5 = local_cc;
      _gleModifyPluginTextureLevel
                (iStack00000018,iStack0000001c,iVar7 + 0xc4,iStack00000020,local_cc,in_r8,iVar22,
                 in_r10,(uint)uVar5);
    }
    else if (bVar2) {
      if (local_bc == 3) {
        bVar34 = (byte)(local_70 >> 0x18);
        if (!(bool)(bVar34 >> 5 & 1)) {
          iVar28 = iVar9 + iVar8;
          iVar23 = iVar22 + iVar8;
          (*pcVar18)(iVar9,iVar22,iVar6,iVar8,iVar20,iVar16);
          if (0 < iVar19) {
            iVar22 = iVar23;
            iVar9 = iVar19;
            iVar30 = iVar28;
            do {
              iVar28 = iVar30 + iVar8;
              iVar23 = iVar22 + iVar8 + iVar21;
              (*pcVar18)(iVar30,iVar22,iVar6,iVar21,iVar20,iVar16);
              iVar9 = iVar9 + -1;
              iVar22 = iVar23;
              iVar30 = iVar28;
            } while (iVar9 != 0);
          }
          local_9c = local_6c;
          iVar9 = iVar28 + iVar8;
          iVar22 = (iVar23 - iVar8) + local_6c;
          (*pcVar18)(iVar28,iVar23 - iVar8,iVar6,iVar8,iVar20,iVar16);
          iVar22 = iVar22 + local_a8;
          if (0 < (int)local_c8) {
            local_80 = iVar8 + iVar21;
            iVar23 = local_a8 + iVar25;
            uVar27 = local_c8;
            do {
              iVar29 = iVar9 + iVar8;
              iVar24 = iVar22 + iVar8;
              (*pcVar18)(iVar9,iVar22,iVar6,iVar8,iVar25,iVar16);
              iVar22 = local_80;
              iVar9 = iVar24;
              iVar28 = iVar19;
              iVar30 = iVar29;
              if (0 < iVar19) {
                do {
                  iVar29 = iVar30 + iVar8;
                  iVar24 = iVar9 + iVar22;
                  (*pcVar18)(iVar30,iVar9,iVar6,iVar21,iVar25,iVar16);
                  iVar28 = iVar28 + -1;
                  iVar9 = iVar24;
                  iVar30 = iVar29;
                } while (iVar28 != 0);
              }
              iVar9 = iVar29 + iVar8;
              iVar22 = (iVar24 - iVar8) + local_9c;
              (*pcVar18)(iVar29,iVar24 - iVar8,iVar6,iVar8,iVar25,iVar16);
              uVar27 = uVar27 - 1;
              iVar22 = iVar22 + iVar23;
            } while (uVar27 != 0);
          }
          iVar28 = iVar9 + iVar8;
          iVar23 = (iVar22 - iVar20) + iVar8;
          (*pcVar18)(iVar9,iVar22 - iVar20,iVar6,iVar8,iVar20,iVar16);
          if (0 < iVar19) {
            iVar22 = iVar23;
            iVar9 = iVar19;
            iVar30 = iVar28;
            do {
              iVar28 = iVar30 + iVar8;
              iVar23 = iVar22 + iVar8 + iVar21;
              (*pcVar18)(iVar30,iVar22,iVar6,iVar21,iVar20,iVar16);
              iVar9 = iVar9 + -1;
              iVar22 = iVar23;
              iVar30 = iVar28;
            } while (iVar9 != 0);
          }
          iVar9 = iVar28 + iVar8;
          iVar22 = (iVar23 - iVar8) + local_9c;
          (*pcVar18)(iVar28,iVar23 - iVar8,iVar6,iVar8,iVar20,iVar16);
          iVar22 = iVar22 + local_a8 + iVar20 + iVar15;
        }
        if (0 < (int)local_c4) {
          local_90 = iVar15 + iVar26;
          local_88 = local_a8 + iVar25;
          local_a4 = local_c4;
          local_60 = iVar8 + iVar21;
          local_98 = local_68;
          local_84 = local_5c;
          do {
            if (!(bool)(bVar34 >> 5 & 1)) {
              iVar23 = iVar9 + iVar8;
              iVar15 = iVar22 + iVar8;
              (*pcVar18)(iVar9,iVar22,iVar6,iVar8,iVar20,iVar26);
              if (0 < iVar19) {
                iVar22 = iVar15;
                iVar9 = iVar19;
                iVar28 = iVar23;
                do {
                  iVar23 = iVar28 + iVar8;
                  iVar15 = iVar22 + iVar8 + iVar21;
                  (*pcVar18)(iVar28,iVar22,iVar6,iVar21,iVar20,iVar26);
                  iVar9 = iVar9 + -1;
                  iVar22 = iVar15;
                  iVar28 = iVar23;
                } while (iVar9 != 0);
              }
              iVar9 = iVar23 + iVar8;
              iVar22 = (iVar15 - iVar8) + local_98 + local_a8;
              (*pcVar18)(iVar23,iVar15 - iVar8,iVar6,iVar8,iVar20,iVar26);
            }
            iVar23 = local_60;
            iVar15 = local_88;
            if (0 < (int)local_c8) {
              local_94 = local_84;
              uVar27 = local_c8;
              do {
                iVar28 = iVar22;
                iVar30 = iVar9;
                if (!(bool)(bVar34 >> 5 & 1)) {
                  iVar30 = iVar9 + iVar8;
                  iVar28 = iVar22 + iVar8;
                  (*pcVar18)(iVar9,iVar22,iVar6,iVar8,iVar25,iVar26);
                }
                iVar22 = iVar28;
                iVar9 = iVar19;
                iVar24 = iVar30;
                if (0 < iVar19) {
                  do {
                    iVar30 = iVar24 + iVar8;
                    iVar28 = iVar22 + iVar23;
                    (*pcVar18)(iVar24,iVar22,iVar6,iVar21,iVar25,iVar26);
                    iVar9 = iVar9 + -1;
                    iVar22 = iVar28;
                    iVar24 = iVar30;
                  } while (iVar9 != 0);
                }
                iVar9 = iVar30;
                if (!(bool)(bVar34 >> 5 & 1)) {
                  iVar22 = iVar28 - iVar8;
                  iVar9 = iVar30 + iVar8;
                  iVar28 = iVar22 + local_94;
                  (*pcVar18)(iVar30,iVar22,iVar6,iVar8,iVar25,iVar26);
                }
                uVar27 = uVar27 - 1;
                iVar22 = iVar28 + iVar15;
              } while (uVar27 != 0);
            }
            if (!(bool)(bVar34 >> 5 & 1)) {
              iVar23 = iVar9 + iVar8;
              iVar15 = (iVar22 - iVar20) + iVar8;
              (*pcVar18)(iVar9,iVar22 - iVar20,iVar6,iVar8,iVar20,iVar26);
              if (0 < iVar19) {
                iVar22 = iVar15;
                iVar9 = iVar19;
                iVar28 = iVar23;
                do {
                  iVar23 = iVar28 + iVar8;
                  iVar15 = iVar22 + iVar8 + iVar21;
                  (*pcVar18)(iVar28,iVar22,iVar6,iVar21,iVar20,iVar26);
                  iVar9 = iVar9 + -1;
                  iVar22 = iVar15;
                  iVar28 = iVar23;
                } while (iVar9 != 0);
              }
              iVar9 = iVar23 + iVar8;
              iVar22 = (iVar15 - iVar8) + local_98;
              (*pcVar18)(iVar23,iVar15 - iVar8,iVar6,iVar8,iVar20,iVar26);
              iVar22 = iVar22 + local_a8 + iVar20;
            }
            local_a4 = local_a4 - 1;
            iVar22 = iVar22 + local_90;
          } while (local_a4 != 0);
        }
        if (!(bool)(bVar34 >> 5 & 1)) {
          iVar15 = iVar9 + iVar8;
          iVar26 = (iVar22 - iVar16) + iVar8;
          (*pcVar18)(iVar9,iVar22 - iVar16,iVar6,iVar8,iVar20,iVar16);
          if (0 < iVar19) {
            iVar22 = iVar26;
            iVar9 = iVar19;
            iVar23 = iVar15;
            do {
              iVar15 = iVar23 + iVar8;
              iVar26 = iVar22 + iVar8 + iVar21;
              (*pcVar18)(iVar23,iVar22,iVar6,iVar21,iVar20,iVar16);
              iVar9 = iVar9 + -1;
              iVar22 = iVar26;
              iVar23 = iVar15;
            } while (iVar9 != 0);
          }
          iVar22 = local_64;
          iVar23 = iVar15 + iVar8;
          iVar9 = (iVar26 - iVar8) + local_64;
          (*pcVar18)(iVar15,iVar26 - iVar8,iVar6,iVar8,iVar20,iVar16);
          iVar9 = iVar9 + local_a8;
          if (0 < (int)local_c8) {
            iVar26 = local_a8 + iVar25;
            uVar27 = local_c8;
            do {
              iVar30 = iVar23 + iVar8;
              iVar28 = iVar9 + iVar8;
              (*pcVar18)(iVar23,iVar9,iVar6,iVar8,iVar25,iVar16);
              iVar15 = iVar28;
              iVar9 = iVar19;
              iVar23 = iVar30;
              if (0 < iVar19) {
                do {
                  iVar30 = iVar23 + iVar8;
                  iVar28 = iVar15 + iVar8 + iVar21;
                  (*pcVar18)(iVar23,iVar15,iVar6,iVar21,iVar25,iVar16);
                  iVar9 = iVar9 + -1;
                  iVar15 = iVar28;
                  iVar23 = iVar30;
                } while (iVar9 != 0);
              }
              iVar23 = iVar30 + iVar8;
              iVar9 = (iVar28 - iVar8) + iVar22 + iVar26;
              (*pcVar18)(iVar30,iVar28 - iVar8,iVar6,iVar8,iVar25,iVar16);
              uVar27 = uVar27 - 1;
            } while (uVar27 != 0);
          }
          iVar25 = iVar23 + iVar8;
          iVar22 = (iVar9 - iVar20) + iVar8;
          (*pcVar18)(iVar23,iVar9 - iVar20,iVar6,iVar8,iVar20,iVar16);
          if (0 < iVar19) {
            iVar26 = iVar22;
            iVar15 = iVar19;
            iVar9 = iVar25;
            do {
              iVar25 = iVar9 + iVar8;
              iVar22 = iVar26 + iVar8 + iVar21;
              (*pcVar18)(iVar9,iVar26,iVar6,iVar21,iVar20,iVar16);
              iVar15 = iVar15 + -1;
              iVar26 = iVar22;
              iVar9 = iVar25;
            } while (iVar15 != 0);
          }
          (*pcVar18)(iVar25,iVar22 - iVar8,iVar6,iVar8,iVar20,iVar16);
        }
        uVar5 = *(ushort *)(iVar7 + 200);
        in_r8 = local_a0;
        iVar22 = local_a0;
        in_r10 = local_a0;
        goto LAB_000fb8dc;
      }
    }
    else if (bVar3) {
      bVar34 = (byte)(local_7c >> 0x18);
      iVar25 = iVar22;
      iVar20 = iVar9;
      if (!(bool)(bVar34 >> 5 & 1)) {
        iVar20 = iVar9 + iVar8;
        iVar25 = iVar22 + iVar8;
        (*local_b0)(iVar9,iVar22,iVar6,iVar8);
      }
      if (0 < iVar19) {
        iVar22 = iVar25;
        iVar26 = iVar19;
        iVar15 = iVar20;
        do {
          iVar20 = iVar15 + iVar8;
          iVar25 = iVar22 + iVar8 + iVar21;
          (*local_b0)(iVar15,iVar22,iVar6,iVar21);
          iVar26 = iVar26 + -1;
          iVar22 = iVar25;
          iVar15 = iVar20;
        } while (iVar26 != 0);
      }
      if (!(bool)(bVar34 >> 5 & 1)) {
        (*local_b0)(iVar20,iVar25 - iVar8,iVar6,iVar8);
      }
      uVar5 = *(ushort *)(iVar7 + 200);
      in_r8 = local_c0 >> 1;
      iVar22 = 0;
      in_r10 = 0;
      goto LAB_000fb8dc;
    }
    local_cc = local_cc + 1;
    iVar22 = iVar7 + 0xc4;
  } while( true );
}

/* _gleGenerateEmptyMipmaps @ 0xfbb00 (868 bytes) */
int _gleGenerateEmptyMipmaps(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  byte bVar1;
  undefined2 uVar2;
  ushort uVar4;
  uint uVar3;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  
  uVar4 = *(ushort *)(param_2 + 0x24) & 0xf;
  if (uVar4 == 1) {
    uVar13 = 3;
  }
  else {
    if (uVar4 < 2) {
      if ((*(ushort *)(param_2 + 0x24) & 0xf) != 0) {
        return param_1;
      }
    }
    else if (uVar4 != 3) {
      if (uVar4 != 4) {
        return param_1;
      }
      uVar13 = 1;
      goto LAB_000fbb7c;
    }
    uVar13 = 2;
  }
LAB_000fbb7c:
  iVar9 = param_2 + param_3 * 0x168;
  iVar6 = iVar9 + param_4 * 0x18;
  uVar7 = _gleComponents((uint)*(ushort *)(iVar6 + 0xd4));
  uVar3 = (uint)*(byte *)(iVar6 + 0xce);
  iVar16 = uVar3 * 2;
  uVar12 = (uint)*(ushort *)(iVar6 + 0xca);
  uVar15 = (uint)*(ushort *)(iVar6 + 200) + uVar3 * -2;
  if (1 < uVar13) {
    uVar12 = uVar12 + uVar3 * -2;
  }
  uVar14 = (uint)*(ushort *)(iVar6 + 0xcc);
  if (2 < uVar13) {
    uVar14 = uVar14 + uVar3 * -2;
  }
  iVar11 = param_4 + 1;
  uVar8 = uVar7;
  iVar9 = iVar11 * 0x18 + iVar9 + 0xc4;
  iVar6 = iVar6 + 0xc4;
  for (; (((iVar10 = iVar9, 1 < (int)uVar15 || (1 < (int)uVar12)) || (1 < (int)uVar14)) &&
         (iVar11 <= param_5)); iVar11 = iVar11 + 1) {
    if ((*(byte *)(iVar10 + 0xb) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(param_1,param_2,iVar10,param_3,iVar11);
      if (*(int *)(iVar10 + 0x14) != 0) {
        bVar1 = *(byte *)(iVar10 + 0xb);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(param_1,param_2,iVar10);
          bVar1 = *(byte *)(iVar10 + 0xb);
        }
        else {
          *(undefined4 *)(iVar10 + 0x14) = 0;
        }
        *(byte *)(iVar10 + 0xb) = bVar1 & 0xef;
      }
      *(byte *)(iVar10 + 0xb) = *(byte *)(iVar10 + 0xb) & 0xdf;
    }
    uVar15 = (int)uVar15 >> 1 | (uint)((int)uVar15 >> 1 == 0);
    uVar12 = (int)uVar12 >> 1 | (uint)((int)uVar12 >> 1 == 0);
    uVar14 = (int)uVar14 >> 1 | (uint)((int)uVar14 >> 1 == 0);
    *(short *)(iVar10 + 4) = (short)uVar15 + (short)iVar16;
    sVar5 = (short)uVar12;
    if (1 < uVar13) {
      sVar5 = sVar5 + (short)iVar16;
    }
    *(short *)(iVar10 + 6) = sVar5;
    uVar3 = uVar14;
    if (2 < uVar13) {
      uVar3 = uVar14 + iVar16;
    }
    uVar2 = *(undefined2 *)(iVar6 + 0x12);
    *(undefined2 *)(iVar10 + 0x10) = *(undefined2 *)(iVar6 + 0x10);
    *(short *)(iVar10 + 8) = (short)uVar3;
    *(char *)(iVar10 + 10) = (char)(iVar16 >> 1);
    *(undefined2 *)(iVar10 + 0x12) = uVar2;
    *(byte *)(iVar10 + 0xb) = (byte)param_7 | 0x20;
    *(undefined4 *)(iVar10 + 0x14) = param_6;
    if ((*(ushort *)(param_2 + 0x24) & 0x100) == 0) {
      if (*(short *)(iVar10 + 0x10) == -0x7a47) {
        sVar5 = *(short *)(iVar10 + 4);
        if (sVar5 == 1) {
          sVar5 = 2;
        }
      }
      else {
        sVar5 = *(short *)(iVar10 + 4);
      }
      *(short *)(iVar10 + 0xc) = sVar5;
      *(undefined2 *)(iVar10 + 0xe) = *(undefined2 *)(iVar10 + 6);
    }
    else {
      *(undefined2 *)(iVar10 + 0xc) = 0;
      *(undefined2 *)(iVar10 + 0xe) = 0;
    }
    uVar8 = _gleCreatePluginTextureLevel(param_1,param_2,iVar10,param_3,iVar11,uVar7);
    iVar9 = iVar10 + 0x18;
    iVar6 = iVar10;
  }
  if (0xe < param_5) {
    param_5 = 0xe;
  }
  if (iVar11 <= param_5) {
    iVar16 = iVar11 * 0x18 + param_2 + param_3 * 0x168 + 0xc4;
    do {
      bVar1 = *(byte *)(iVar16 + 0xb);
      if ((bVar1 & 0x20) != 0) {
        uVar8 = _gleDeletePluginTextureLevel(param_1,param_2,iVar16,param_3,iVar11);
        if (*(int *)(iVar16 + 0x14) != 0) {
          bVar1 = *(byte *)(iVar16 + 0xb);
          if ((bVar1 & 1) == 0) {
            uVar8 = _gleFreeTextureLevel(param_1,param_2,iVar16);
            bVar1 = *(byte *)(iVar16 + 0xb);
          }
          else {
            *(undefined4 *)(iVar16 + 0x14) = 0;
          }
          *(byte *)(iVar16 + 0xb) = bVar1 & 0xef;
        }
        *(byte *)(iVar16 + 0xb) = *(byte *)(iVar16 + 0xb) & 0xdf;
        bVar1 = *(byte *)(iVar16 + 0xb);
      }
      iVar11 = iVar11 + 1;
      *(byte *)(iVar16 + 0xb) = bVar1 & 0xf8;
      *(undefined2 *)(iVar16 + 4) = 0;
      *(undefined2 *)(iVar16 + 6) = 0;
      *(undefined2 *)(iVar16 + 8) = 0;
      *(undefined1 *)(iVar16 + 10) = 0;
      *(undefined2 *)(iVar16 + 0x10) = 0;
      *(undefined2 *)(iVar16 + 0x12) = 0;
      *(undefined2 *)(iVar16 + 0xc) = 0;
      *(undefined2 *)(iVar16 + 0xe) = 0;
      iVar16 = iVar16 + 0x18;
    } while (iVar11 <= param_5);
  }
  return uVar8;
}

/* _gleGenMipmapsToLevel @ 0xfbe64 (384 bytes) */
int _gleGenMipmapsToLevel(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((*(ushort *)(param_2 + 0x24) & 0xf) != 2) {
    iVar5 = param_3 * 0x168;
    iVar1 = param_2 + iVar5 + param_4 * 0x18;
    ((int (*)())_gleGenerateEmptyMipmaps)(param_1,param_2,param_3,param_4,param_5,0,0);
    if ((*(byte *)(iVar5 + param_4 * 0x18 + param_2 + 0xcf) & 0x20) == 0) {
      return 0;
    }
    iVar3 = (**(code **)(param_1 + 0x4714))
                      (*(undefined4 *)(param_1 + 0x4688),
                       *(undefined4 *)(param_2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),param_3);
    if (iVar3 != 0) {
      *(undefined4 *)(param_2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
      if (param_6 == 0) {
        uVar4 = (uint)*(short *)(param_2 + 0x62);
      }
      else {
        uVar4 = (uint)*(byte *)(param_2 + 0x87);
      }
      if (0xf < (int)uVar4) {
        uVar4 = 0xf;
      }
      iVar1 = param_4 + 1;
      if (iVar1 <= (int)uVar4) {
        iVar3 = (uVar4 + 1) - iVar1;
        pbVar2 = (byte *)(iVar1 * 0x18 + iVar5 + param_2 + 0xcf);
        do {
          *pbVar2 = *pbVar2 | 0x40;
          pbVar2 = pbVar2 + 0x18;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      return 1;
    }
    if ((*(ushort *)(param_2 + 0x24) & 0x100) == 0) {
      if (*(int *)(iVar1 + 0xd8) == 0) {
        _gleAllocateTextureLevel(param_1,param_2,iVar1 + 0xc4);
      }
      _gleSynchronizePluginTextureLevels(param_1,param_2);
      ((int (*)())_gleGenerateMipmapData)(param_1,param_2,param_3,param_4,param_5);
    }
  }
  return 0;
}

/* _gleGenSurfaceMipmaps @ 0xfbfe4 (160 bytes) */
int _gleGenSurfaceMipmaps(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(ushort *)(param_2 + 0x24) & 0xf) != 2) {
    ((int (*)())_gleGenerateEmptyMipmaps)(param_1,param_2,param_3,0,param_4,0,0x12);
    uVar1 = 0;
    if (*(int *)(param_2 + 0x2c) != 0) {
      if (param_5 != 0) {
        (**(code **)(param_1 + 0x4714))
                  (*(undefined4 *)(param_1 + 0x4688),
                   *(undefined4 *)(param_2 + (uint)*(byte *)(param_1 + 0x85a8) * 4),param_3);
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}

/* _gleHalfFloatToFloat @ 0xfc084 (136 bytes) */
double _gleHalfFloatToFloat(uint param_1)
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 & 0x7c00;
  uVar2 = param_1 & 0x3ff;
  uVar4 = (param_1 & 0x8000) << 0x10;
  if (uVar3 == 0x7c00) {
    fVar1 = GH_U2F((unsigned int)((uVar4 | 0x7f800000)));
    if (uVar2 != 0) {
      fVar1 = GH_U2F((unsigned int)((uVar4 | 0x7fffffff)));
    }
  }
  else {
    if (uVar3 == 0) {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = 0x38000000;
        while (uVar2 = uVar2 << 1, (uVar2 & 0x400) == 0) {
          uVar3 = uVar3 - 0x800000;
        }
        uVar2 = uVar2 & 0x3ff;
      }
    }
    else {
      uVar3 = uVar3 * 0x2000 + 0x38000000;
    }
    fVar1 = GH_U2F((unsigned int)((uVar4 | uVar3 | uVar2 << 0xd)));
  }
  return (double)fVar1;
}

/* _gleLookUpTexture1D @ 0xfc10c (72 bytes) */
int _gleLookUpTexture1D(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0xde0) {
    return *(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5164) + 0x10;
  }
  if (param_2 != 0x8063) {
    return 0;
  }
  return *(int *)(param_1 + 0x52b8) + 0x10;
}

/* _gleLookUpNonProxyTexture1D @ 0xfc154 (40 bytes) */
int _gleLookUpNonProxyTexture1D(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0xde0) {
    return 0;
  }
  return *(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5164) + 0x10;
}

/* _gleLookUpNonProxyTexture3D @ 0xfc17c (48 bytes) */
int _gleLookUpNonProxyTexture3D(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0x806f) {
    return 0;
  }
  return *(int *)(*(int *)(param_1 + 0x53d4) * 0x14 + param_1 + 0x5158) + 0x10;
}

/* _gleLookUpColorTable @ 0xfc1ac (544 bytes) */
int _gleLookUpColorTable(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x53d4);
  if (param_2 == 0x80d2) {
    iVar1 = *(int *)(param_1 + 0x52c4);
    goto LAB_000fc364;
  }
  if (param_2 < 0x80d3) {
    if (param_2 == 0x8064) {
      iVar1 = *(int *)(param_1 + 0x52b4);
    }
    else {
      if (param_2 < 0x8065) {
        if (param_2 != 0xde1) {
          if (param_2 < 0xde2) {
            if (param_2 == 0xde0) {
              iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5164);
              goto LAB_000fc320;
            }
          }
          else if (param_2 == 0x8063) {
            iVar1 = *(int *)(param_1 + 0x52b8);
            goto LAB_000fc364;
          }
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5160);
        goto LAB_000fc320;
      }
      if (param_2 == 0x8070) {
        iVar1 = *(int *)(param_1 + 0x52ac);
      }
      else {
        if (param_2 < 0x8071) {
          if (param_2 != 0x806f) {
            return 0;
          }
          iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5158);
          goto LAB_000fc320;
        }
        if (param_2 == 0x80d0) {
          iVar1 = *(int *)(param_1 + 0x52bc);
        }
        else {
          if (param_2 != 0x80d1) {
            return 0;
          }
          iVar1 = *(int *)(param_1 + 0x52c0);
        }
      }
    }
LAB_000fc364:
    return iVar1 + 0x10;
  }
  if (param_2 != 0x84f5) {
    if (param_2 < 0x84f6) {
      if (param_2 == 0x80d4) {
        iVar1 = *(int *)(param_1 + 0x52cc);
      }
      else if (param_2 < 0x80d4) {
        iVar1 = *(int *)(param_1 + 0x52c8);
      }
      else {
        if (param_2 != 0x80d5) {
          if (param_2 != 0x81fb) {
            return 0;
          }
          iVar1 = *(int *)(iVar1 * 4 + param_1 + 0x52d4);
          goto LAB_000fc320;
        }
        iVar1 = *(int *)(param_1 + 0x52d0);
      }
      goto LAB_000fc364;
    }
    if (param_2 == 0x8513) {
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5154);
      goto LAB_000fc320;
    }
    if (param_2 < 0x8514) {
      if (param_2 != 0x84f7) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x52b0);
      goto LAB_000fc364;
    }
    if (param_2 == 0x851b) {
      iVar1 = *(int *)(param_1 + 0x52a8);
      goto LAB_000fc364;
    }
    if (param_2 != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x515c);
LAB_000fc320:
  return iVar1 + 0x10;
}

/* _gleLookUpNonProxyColorTable @ 0xfc3cc (324 bytes) */
int _gleLookUpNonProxyColorTable(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x53d4);
  if (param_2 == 0x80d1) {
    iVar1 = *(int *)(param_1 + 0x52c0);
LAB_000fc4f8:
    return iVar1 + 0x10;
  }
  if (param_2 < 0x80d2) {
    if (param_2 == 0xde1) {
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5160);
    }
    else if (param_2 < 0xde2) {
      if (param_2 != 0xde0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5164);
    }
    else {
      if (param_2 != 0x806f) {
        if (param_2 != 0x80d0) {
          return 0;
        }
        iVar1 = *(int *)(param_1 + 0x52bc);
        goto LAB_000fc4f8;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5158);
    }
    goto LAB_000fc4a4;
  }
  if (param_2 != 0x84f5) {
    if (param_2 < 0x84f6) {
      if (param_2 == 0x80d2) {
        iVar1 = *(int *)(param_1 + 0x52c4);
        goto LAB_000fc4f8;
      }
      if (param_2 != 0x81fb) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 4 + param_1 + 0x52d4);
      goto LAB_000fc4a4;
    }
    if (param_2 == 0x8513) {
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5154);
      goto LAB_000fc4a4;
    }
    if (param_2 != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x515c);
LAB_000fc4a4:
  return iVar1 + 0x10;
}

/* _gleReclaimTextureObjectResources @ 0xfc510 (344 bytes) */
int _gleReclaimTextureObjectResources(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  
  iVar3 = *(int *)(param_1 + 0x5148);
  piVar8 = (int *)(iVar3 + 0x2008);
  do {
    piVar5 = piVar8 + 1;
    for (piVar8 = (int *)*piVar8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (((piVar8[2] == 1) && ((*(ushort *)(piVar8 + 0xd) & 0x3c00) != 0x800)) &&
         (uVar6 = 0, *(char *)(param_1 + 0x85a4) != '\0')) {
        puVar9 = piVar8 + 4;
        iVar10 = param_1 + 0x10000;
        do {
          piVar1 = (int *)(iVar10 + -0x777c);
          uVar6 = uVar6 + 1;
          uVar4 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar2 = (undefined4 *)(iVar10 + -0x7a54);
          iVar10 = iVar10 + 0x2e0;
          (**(code **)(*piVar1 + 0x170))(*puVar2,uVar4);
        } while (uVar6 < *(byte *)(param_1 + 0x85a4));
      }
    }
    piVar8 = piVar5;
  } while (piVar5 <= (int *)(iVar3 + 0x3004));
  uVar6 = 0;
  piVar8 = (int *)(param_1 + 0x5294);
  do {
    iVar3 = *piVar8;
    piVar8 = piVar8 + 1;
    if (((iVar3 != 0) && (*(int *)(iVar3 + 8) == 1)) &&
       (((*(ushort *)(iVar3 + 0x34) & 0x3c00) != 0x800 &&
        (uVar7 = 0, *(char *)(param_1 + 0x85a4) != '\0')))) {
      puVar9 = (undefined4 *)(iVar3 + 0x10);
      iVar3 = param_1 + 0x10000;
      do {
        piVar5 = (int *)(iVar3 + -0x777c);
        uVar7 = uVar7 + 1;
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar2 = (undefined4 *)(iVar3 + -0x7a54);
        iVar3 = iVar3 + 0x2e0;
        (**(code **)(*piVar5 + 0x170))(*puVar2,uVar4);
      } while (uVar7 < *(byte *)(param_1 + 0x85a4));
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 5);
  return;
}

/* _gleCompressedTextureImagePut @ 0xfc668 (252 bytes) */
int _gleCompressedTextureImagePut(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  int param_8;
  uint param_9;
  undefined4 param_10;
  int param_11;
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (((0x83f3 < param_9) || (0x83f1 < param_9)) || (iVar8 = 3, param_9 < 0x83f0)) {
    iVar8 = 4;
  }
  iVar7 = 0;
  uVar1 = *(ushort *)(param_2 + 4);
  uVar2 = *(ushort *)(param_2 + 6);
  iVar4 = param_4 >> 2;
  if (0 < param_8) {
    iVar6 = param_7 + 3 >> 2;
    iVar5 = (param_6 + 3 >> 2) << iVar8;
    do {
      iVar10 = 0;
      iVar9 = param_11;
      if (0 < iVar6) {
        do {
          iVar3 = iVar4 + iVar10;
          iVar10 = iVar10 + 1;
          param_11 = iVar9 + iVar5;
          _memcpy(*(int *)(param_2 + 0x14) +
                  (iVar3 * ((int)(uVar1 + 3) >> 2) + (param_3 >> 2) << iVar8),iVar9,iVar5);
          iVar9 = param_11;
        } while (iVar10 < iVar6);
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + ((int)(uVar2 + 3) >> 2);
    } while (iVar7 < param_8);
  }
  return;
}

/* _gleTextureImagePut_FastByte @ 0xfc764 (6052 bytes) */
int _gleTextureImagePut_FastByte(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  byte *param_4;
  byte *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  
  iVar3 = _gleComponents(param_10);
  pbVar5 = param_5 + param_2 * iVar3;
  switch(param_10) {
  case 0x1900:
    if (param_11 != 0x1900) {
      return 0;
    }
    if (0 < param_3) {
      do {
        if (param_5 < pbVar5) {
          iVar3 = (int)pbVar5 - (int)param_5;
          pbVar4 = param_4;
          do {
            bVar2 = *pbVar4;
            pbVar4 = pbVar4 + 1;
            *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
            param_5 = param_5 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        pbVar5 = pbVar5 + param_9;
      } while (param_3 != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4 + 3;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1907) {
        if (param_11 < 0x1903) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              pbVar4 = param_4 + 1;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 2;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4 + 3;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      pbVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < pbVar5; param_5 = param_5 + 3) {
            *param_5 = *param_4 << 1 | *param_4 >> 6 & 1;
            param_5[1] = param_4[1] << 1 | param_4[1] >> 6 & 1;
            pbVar1 = param_4 + 2;
            param_4 = param_4 + 4;
            param_5[2] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
          }
          param_3 = param_3 + -1;
          param_4 = pbVar4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
          pbVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        pbVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < pbVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              bVar2 = *param_4;
              param_4 = param_4 + 1;
              param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
            }
            param_3 = param_3 + -1;
            param_4 = pbVar4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
            pbVar4 = param_4;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          pbVar4 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < pbVar5; param_5 = param_5 + 3) {
                bVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[1] = 0;
                param_5[2] = 0;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              }
              param_3 = param_3 + -1;
              param_4 = pbVar4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
              pbVar4 = param_4;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          pbVar4 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < pbVar5; param_5 = param_5 + 3) {
                *param_5 = 0;
                bVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[2] = 0;
                param_5[1] = bVar2 << 1 | bVar2 >> 6 & 1;
              }
              param_3 = param_3 + -1;
              param_4 = pbVar4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
              pbVar4 = param_4;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            for (; param_5 < pbVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              param_5[2] = 0;
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        pbVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < pbVar5; param_5 = param_5 + 3) {
              *param_5 = *param_4 << 1 | *param_4 >> 6 & 1;
              param_5[1] = param_4[1] << 1 | param_4[1] >> 6 & 1;
              pbVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              param_5[2] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
            }
            param_3 = param_3 + -1;
            param_4 = pbVar4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
            pbVar4 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            pbVar4 = param_4 + 1;
            do {
              *param_5 = pbVar4[2] << 1 | pbVar4[2] >> 6 & 1;
              param_5[1] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 3;
            } while (param_5 < pbVar5);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        pbVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < pbVar5; param_5 = param_5 + 3) {
              bVar2 = *param_4;
              param_4 = param_4 + 1;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = pbVar4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
            pbVar4 = param_4;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        pbVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < pbVar5; param_5 = param_5 + 3) {
              bVar2 = *param_4;
              param_4 = param_4 + 2;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = pbVar4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
            pbVar4 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      pbVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < pbVar5; param_5 = param_5 + 3) {
            *param_5 = param_4[2] << 1 | param_4[2] >> 6 & 1;
            param_5[1] = param_4[1] << 1 | param_4[1] >> 6 & 1;
            bVar2 = *param_4;
            param_4 = param_4 + 3;
            param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
          }
          param_3 = param_3 + -1;
          param_4 = pbVar4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
          pbVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      pbVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < pbVar5; param_5 = param_5 + 3) {
            *param_5 = param_4[2] << 1 | param_4[2] >> 6 & 1;
            param_5[1] = param_4[1] << 1 | param_4[1] >> 6 & 1;
            bVar2 = *param_4;
            param_4 = param_4 + 4;
            param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
          }
          param_3 = param_3 + -1;
          param_4 = pbVar4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
          pbVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1908:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
            pbVar4 = param_4;
            do {
              *param_5 = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
              param_5[1] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
              param_5[2] = pbVar4[2] << 1 | pbVar4[2] >> 6 & 1;
              pbVar1 = pbVar4 + 3;
              pbVar4 = pbVar4 + 4;
              param_5[3] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
              pbVar4 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                param_5[3] = 0xff;
                param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          if (0 < param_3) {
            do {
              if (param_5 < pbVar5) {
                uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
                pbVar4 = param_4;
                do {
                  bVar2 = *pbVar4;
                  pbVar4 = pbVar4 + 1;
                  param_5[1] = 0;
                  param_5[2] = 0;
                  *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < pbVar5) {
                uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
                pbVar4 = param_4;
                do {
                  *param_5 = 0;
                  bVar2 = *pbVar4;
                  pbVar4 = pbVar4 + 1;
                  param_5[2] = 0;
                  param_5[3] = 0xff;
                  param_5[1] = bVar2 << 1 | bVar2 >> 6 & 1;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
              pbVar4 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                param_5[3] = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
              pbVar4 = param_4;
              do {
                *param_5 = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
                param_5[1] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
                bVar2 = pbVar4[2];
                pbVar4 = pbVar4 + 3;
                param_5[3] = 0xff;
                param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
            pbVar4 = param_4;
            do {
              *param_5 = pbVar4[3] << 1 | pbVar4[3] >> 6 & 1;
              param_5[1] = pbVar4[2] << 1 | pbVar4[2] >> 6 & 1;
              param_5[2] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              param_5[3] = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                param_5[3] = 0xff;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
              pbVar4 = param_4;
              do {
                *param_5 = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                pbVar1 = pbVar4 + 1;
                pbVar4 = pbVar4 + 2;
                param_5[3] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
            pbVar4 = param_4;
            do {
              *param_5 = pbVar4[2] << 1 | pbVar4[2] >> 6 & 1;
              param_5[1] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 3;
              param_5[3] = 0xff;
              param_5[2] = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (3 - (int)param_5)) >> 2;
            pbVar4 = param_4;
            do {
              *param_5 = pbVar4[2] << 1 | pbVar4[2] >> 6 & 1;
              param_5[1] = pbVar4[1] << 1 | pbVar4[1] >> 6 & 1;
              param_5[2] = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
              pbVar1 = pbVar4 + 3;
              pbVar4 = pbVar4 + 4;
              param_5[3] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1907) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < pbVar5) {
                iVar3 = (int)pbVar5 - (int)param_5;
                pbVar4 = param_4;
                do {
                  bVar2 = *pbVar4;
                  pbVar4 = pbVar4 + 1;
                  *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                  param_5 = param_5 + 1;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              do {
                *param_5 = 0;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 3;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4 + 3;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              iVar3 = (int)pbVar5 - (int)param_5;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 2;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4 + 2;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 3;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            iVar3 = (int)pbVar5 - (int)param_5;
            pbVar4 = param_4 + 2;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
            pbVar4 = param_4;
            do {
              *param_5 = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
              pbVar1 = pbVar4 + 3;
              pbVar4 = pbVar4 + 4;
              param_5[1] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1906) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < pbVar5) {
                uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
                pbVar4 = param_4;
                do {
                  bVar2 = *pbVar4;
                  pbVar4 = pbVar4 + 1;
                  param_5[1] = 0xff;
                  *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                  param_5 = param_5 + 2;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              pbVar5 = pbVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
              do {
                *param_5 = 0;
                param_5[1] = 0xff;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
              pbVar4 = param_4;
              do {
                *param_5 = 0;
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                param_5[1] = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 3;
                param_5[1] = 0xff;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
            pbVar4 = param_4;
            do {
              *param_5 = pbVar4[3] << 1 | pbVar4[3] >> 6 & 1;
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              param_5[1] = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
              pbVar4 = param_4;
              do {
                bVar2 = *pbVar4;
                pbVar4 = pbVar4 + 1;
                param_5[1] = 0xff;
                *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < pbVar5) {
              uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
              pbVar4 = param_4;
              do {
                *param_5 = *pbVar4 << 1 | *pbVar4 >> 6 & 1;
                pbVar1 = pbVar4 + 1;
                pbVar4 = pbVar4 + 2;
                param_5[1] = *pbVar1 << 1 | *pbVar1 >> 6 & 1;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            pbVar5 = pbVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            pbVar4 = param_4 + 2;
            uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
            do {
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 3;
              param_5[1] = 0xff;
              *param_5 = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < pbVar5) {
            pbVar4 = param_4 + 3;
            uVar6 = (uint)(pbVar5 + (1 - (int)param_5)) >> 1;
            do {
              *param_5 = pbVar4[-1] << 1 | pbVar4[-1] >> 6 & 1;
              bVar2 = *pbVar4;
              pbVar4 = pbVar4 + 4;
              param_5[1] = bVar2 << 1 | bVar2 >> 6 & 1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          pbVar5 = pbVar5 + param_9;
        } while (param_3 != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastShort @ 0xfdf34 (5476 bytes) */
int _gleTextureImagePut_FastShort(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  ushort *param_4;
  undefined1 *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  ushort *puVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  iVar4 = _gleComponents(param_10);
  puVar5 = param_5 + param_2 * iVar4;
  switch(param_10) {
  case 0x1900:
    if (param_11 != 0x1900) {
      return 0;
    }
    if (0 < param_3) {
      do {
        if (param_5 < puVar5) {
          iVar4 = (int)puVar5 - (int)param_5;
          puVar3 = param_4;
          do {
            uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            *param_5 = (char)(uVar2 >> 7);
            param_5 = param_5 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = (ushort *)((int)param_4 + param_6);
        param_5 = param_5 + param_8;
        puVar5 = puVar5 + param_9;
      } while (param_3 != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)(uVar2 >> 7);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1907) {
        if (param_11 < 0x1903) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(uVar2 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                *param_5 = (char)(*puVar1 >> 7);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(*param_4 >> 7);
            param_5[1] = (char)(param_4[1] >> 7);
            puVar1 = param_4 + 2;
            param_4 = param_4 + 4;
            param_5[2] = (char)(*puVar1 >> 7);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              uVar2 = *param_4;
              param_4 = param_4 + 1;
              param_5[2] = (char)(uVar2 >> 7);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                uVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[1] = 0;
                param_5[2] = 0;
                *param_5 = (char)(uVar2 >> 7);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                *param_5 = 0;
                uVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[2] = 0;
                param_5[1] = (char)(uVar2 >> 7);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              param_5[2] = 0;
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = (char)(*param_4 >> 7);
              param_5[1] = (char)(param_4[1] >> 7);
              puVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              param_5[2] = (char)(*puVar1 >> 7);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[3] >> 7);
            param_5[1] = (char)(param_4[2] >> 7);
            puVar1 = param_4 + 1;
            param_4 = param_4 + 4;
            param_5[2] = (char)(*puVar1 >> 7);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 1;
              *param_5 = (char)(uVar2 >> 7);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 2;
              *param_5 = (char)(uVar2 >> 7);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[2] >> 7);
            param_5[1] = (char)(param_4[1] >> 7);
            uVar2 = *param_4;
            param_4 = param_4 + 3;
            param_5[2] = (char)(uVar2 >> 7);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[2] >> 7);
            param_5[1] = (char)(param_4[1] >> 7);
            uVar2 = *param_4;
            param_4 = param_4 + 4;
            param_5[2] = (char)(uVar2 >> 7);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1908:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(*puVar3 >> 7);
              param_5[1] = (char)(puVar3[1] >> 7);
              param_5[2] = (char)(puVar3[2] >> 7);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(*puVar1 >> 7);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                param_5[2] = (char)(uVar2 >> 7);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0;
                  param_5[2] = 0;
                  *param_5 = (char)(uVar2 >> 7);
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  *param_5 = 0;
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[2] = 0;
                  param_5[3] = 0xff;
                  param_5[1] = (char)(uVar2 >> 7);
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = (char)(uVar2 >> 7);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 7);
                param_5[1] = (char)(puVar3[1] >> 7);
                uVar2 = puVar3[2];
                puVar3 = puVar3 + 3;
                param_5[3] = 0xff;
                param_5[2] = (char)(uVar2 >> 7);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[3] >> 7);
              param_5[1] = (char)(puVar3[2] >> 7);
              param_5[2] = (char)(puVar3[1] >> 7);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(uVar2 >> 7);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                *param_5 = (char)(uVar2 >> 7);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 7);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[3] = (char)(*puVar1 >> 7);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 7);
              param_5[1] = (char)(puVar3[1] >> 7);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 3;
              param_5[3] = 0xff;
              param_5[2] = (char)(uVar2 >> 7);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 7);
              param_5[1] = (char)(puVar3[1] >> 7);
              param_5[2] = (char)(*puVar3 >> 7);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(*puVar1 >> 7);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(uVar2 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1907) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                iVar4 = (int)puVar5 - (int)param_5;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  *param_5 = (char)(uVar2 >> 7);
                  param_5 = param_5 + 1;
                  iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 3;
              *param_5 = (char)(uVar2 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)(uVar2 >> 7);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 2;
                *param_5 = (char)(uVar2 >> 7);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 3;
              *param_5 = (char)(*puVar1 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 7);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(*puVar3 >> 7);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(*puVar1 >> 7);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1906) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0xff;
                  *param_5 = (char)(uVar2 >> 7);
                  param_5 = param_5 + 2;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (ushort *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              do {
                *param_5 = 0;
                param_5[1] = 0xff;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = (char)(uVar2 >> 7);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 3;
                param_5[1] = 0xff;
                *param_5 = (char)(uVar2 >> 7);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[3] >> 7);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(uVar2 >> 7);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = 0xff;
                *param_5 = (char)(uVar2 >> 7);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 7);
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[1] = (char)(*puVar1 >> 7);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (ushort *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              uVar2 = puVar3[2];
              puVar3 = puVar3 + 3;
              param_5[1] = 0xff;
              *param_5 = (char)(uVar2 >> 7);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 7);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(*puVar1 >> 7);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (ushort *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastUshort @ 0xff4c4 (5476 bytes) */
int _gleTextureImagePut_FastUshort(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined2 *param_4;
  undefined1 *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  iVar4 = _gleComponents(param_10);
  puVar5 = param_5 + param_2 * iVar4;
  switch(param_10) {
  case 0x1900:
    if (param_11 != 0x1900) {
      return 0;
    }
    if (0 < param_3) {
      do {
        if (param_5 < puVar5) {
          iVar4 = (int)puVar5 - (int)param_5;
          puVar3 = param_4;
          do {
            uVar2 = *puVar3;
            puVar3 = puVar3 + 1;
            *param_5 = (char)((ushort)uVar2 >> 8);
            param_5 = param_5 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = (undefined2 *)((int)param_4 + param_6);
        param_5 = param_5 + param_8;
        puVar5 = puVar5 + param_9;
      } while (param_3 != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1907) {
        if (param_11 < 0x1903) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                *param_5 = (char)((ushort)*puVar1 >> 8);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)((ushort)*param_4 >> 8);
            param_5[1] = (char)((ushort)param_4[1] >> 8);
            puVar1 = param_4 + 2;
            param_4 = param_4 + 4;
            param_5[2] = (char)((ushort)*puVar1 >> 8);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              uVar2 = *param_4;
              param_4 = param_4 + 1;
              param_5[2] = (char)((ushort)uVar2 >> 8);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                uVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[1] = 0;
                param_5[2] = 0;
                *param_5 = (char)((ushort)uVar2 >> 8);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                *param_5 = 0;
                uVar2 = *param_4;
                param_4 = param_4 + 1;
                param_5[2] = 0;
                param_5[1] = (char)((ushort)uVar2 >> 8);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              param_5[2] = 0;
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = (char)((ushort)*param_4 >> 8);
              param_5[1] = (char)((ushort)param_4[1] >> 8);
              puVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              param_5[2] = (char)((ushort)*puVar1 >> 8);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)((ushort)param_4[3] >> 8);
            param_5[1] = (char)((ushort)param_4[2] >> 8);
            puVar1 = param_4 + 1;
            param_4 = param_4 + 4;
            param_5[2] = (char)((ushort)*puVar1 >> 8);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 1;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 2;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)((ushort)param_4[2] >> 8);
            param_5[1] = (char)((ushort)param_4[1] >> 8);
            uVar2 = *param_4;
            param_4 = param_4 + 3;
            param_5[2] = (char)((ushort)uVar2 >> 8);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)((ushort)param_4[2] >> 8);
            param_5[1] = (char)((ushort)param_4[1] >> 8);
            uVar2 = *param_4;
            param_4 = param_4 + 4;
            param_5[2] = (char)((ushort)uVar2 >> 8);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1908:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)*puVar3 >> 8);
              param_5[1] = (char)((ushort)puVar3[1] >> 8);
              param_5[2] = (char)((ushort)puVar3[2] >> 8);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                param_5[2] = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0;
                  param_5[2] = 0;
                  *param_5 = (char)((ushort)uVar2 >> 8);
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  *param_5 = 0;
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[2] = 0;
                  param_5[3] = 0xff;
                  param_5[1] = (char)((ushort)uVar2 >> 8);
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)((ushort)*puVar3 >> 8);
                param_5[1] = (char)((ushort)puVar3[1] >> 8);
                uVar2 = puVar3[2];
                puVar3 = puVar3 + 3;
                param_5[3] = 0xff;
                param_5[2] = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)puVar3[3] >> 8);
              param_5[1] = (char)((ushort)puVar3[2] >> 8);
              param_5[2] = (char)((ushort)puVar3[1] >> 8);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)((ushort)*puVar3 >> 8);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[3] = (char)((ushort)*puVar1 >> 8);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)puVar3[2] >> 8);
              param_5[1] = (char)((ushort)puVar3[1] >> 8);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 3;
              param_5[3] = 0xff;
              param_5[2] = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)puVar3[2] >> 8);
              param_5[1] = (char)((ushort)puVar3[1] >> 8);
              param_5[2] = (char)((ushort)*puVar3 >> 8);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1907) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                iVar4 = (int)puVar5 - (int)param_5;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  *param_5 = (char)((ushort)uVar2 >> 8);
                  param_5 = param_5 + 1;
                  iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar2 = *puVar3;
              puVar3 = puVar3 + 3;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 2;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 3;
              *param_5 = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 4;
              *param_5 = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)*puVar3 >> 8);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1906) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0xff;
                  *param_5 = (char)((ushort)uVar2 >> 8);
                  param_5 = param_5 + 2;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (undefined2 *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              do {
                *param_5 = 0;
                param_5[1] = 0xff;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 3;
                param_5[1] = 0xff;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)puVar3[3] >> 8);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = 0xff;
                *param_5 = (char)((ushort)uVar2 >> 8);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = (char)((ushort)*puVar3 >> 8);
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[1] = (char)((ushort)*puVar1 >> 8);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (undefined2 *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              uVar2 = puVar3[2];
              puVar3 = puVar3 + 3;
              param_5[1] = 0xff;
              *param_5 = (char)((ushort)uVar2 >> 8);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)((ushort)puVar3[2] >> 8);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)((ushort)*puVar1 >> 8);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (undefined2 *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastInt @ 0x100a54 (5476 bytes) */
int _gleTextureImagePut_FastInt(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint *param_4;
  undefined1 *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  iVar4 = _gleComponents(param_10);
  puVar5 = param_5 + param_2 * iVar4;
  switch(param_10) {
  case 0x1900:
    if (param_11 != 0x1900) {
      return 0;
    }
    if (0 < param_3) {
      do {
        if (param_5 < puVar5) {
          iVar4 = (int)puVar5 - (int)param_5;
          puVar3 = param_4;
          do {
            uVar6 = *puVar3;
            puVar3 = puVar3 + 1;
            *param_5 = (char)(uVar6 >> 0x17);
            param_5 = param_5 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = (uint *)((int)param_4 + param_6);
        param_5 = param_5 + param_8;
        puVar5 = puVar5 + param_9;
      } while (param_3 != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar6 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)(uVar6 >> 0x17);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1907) {
        if (param_11 < 0x1903) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar6 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(uVar6 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                *param_5 = (char)(*puVar1 >> 0x17);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(*param_4 >> 0x17);
            param_5[1] = (char)(param_4[1] >> 0x17);
            puVar1 = param_4 + 2;
            param_4 = param_4 + 4;
            param_5[2] = (char)(*puVar1 >> 0x17);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              uVar6 = *param_4;
              param_4 = param_4 + 1;
              param_5[2] = (char)(uVar6 >> 0x17);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                uVar6 = *param_4;
                param_4 = param_4 + 1;
                param_5[1] = 0;
                param_5[2] = 0;
                *param_5 = (char)(uVar6 >> 0x17);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          puVar3 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                *param_5 = 0;
                uVar6 = *param_4;
                param_4 = param_4 + 1;
                param_5[2] = 0;
                param_5[1] = (char)(uVar6 >> 0x17);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)puVar3 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar3 = param_4;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              param_5[2] = 0;
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = (char)(*param_4 >> 0x17);
              param_5[1] = (char)(param_4[1] >> 0x17);
              puVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              param_5[2] = (char)(*puVar1 >> 0x17);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[3] >> 0x17);
            param_5[1] = (char)(param_4[2] >> 0x17);
            puVar1 = param_4 + 1;
            param_4 = param_4 + 4;
            param_5[2] = (char)(*puVar1 >> 0x17);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar6 = *param_4;
              param_4 = param_4 + 1;
              *param_5 = (char)(uVar6 >> 0x17);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        puVar3 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar6 = *param_4;
              param_4 = param_4 + 2;
              *param_5 = (char)(uVar6 >> 0x17);
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)puVar3 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar3 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[2] >> 0x17);
            param_5[1] = (char)(param_4[1] >> 0x17);
            uVar6 = *param_4;
            param_4 = param_4 + 3;
            param_5[2] = (char)(uVar6 >> 0x17);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      puVar3 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = (char)(param_4[2] >> 0x17);
            param_5[1] = (char)(param_4[1] >> 0x17);
            uVar6 = *param_4;
            param_4 = param_4 + 4;
            param_5[2] = (char)(uVar6 >> 0x17);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)puVar3 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar3 = param_4;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1908:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(*puVar3 >> 0x17);
              param_5[1] = (char)(puVar3[1] >> 0x17);
              param_5[2] = (char)(puVar3[2] >> 0x17);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                param_5[2] = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0;
                  param_5[2] = 0;
                  *param_5 = (char)(uVar2 >> 0x17);
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar3 = param_4;
                do {
                  *param_5 = 0;
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[2] = 0;
                  param_5[3] = 0xff;
                  param_5[1] = (char)(uVar2 >> 0x17);
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 0x17);
                param_5[1] = (char)(puVar3[1] >> 0x17);
                uVar2 = puVar3[2];
                puVar3 = puVar3 + 3;
                param_5[3] = 0xff;
                param_5[2] = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[3] >> 0x17);
              param_5[1] = (char)(puVar3[2] >> 0x17);
              param_5[2] = (char)(puVar3[1] >> 0x17);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(uVar2 >> 0x17);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[3] = 0xff;
                *param_5 = (char)(uVar2 >> 0x17);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 0x17);
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[3] = (char)(*puVar1 >> 0x17);
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 0x17);
              param_5[1] = (char)(puVar3[1] >> 0x17);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 3;
              param_5[3] = 0xff;
              param_5[2] = (char)(uVar2 >> 0x17);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 0x17);
              param_5[1] = (char)(puVar3[1] >> 0x17);
              param_5[2] = (char)(*puVar3 >> 0x17);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[3] = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar6 = *puVar3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(uVar6 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1907) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                iVar4 = (int)puVar5 - (int)param_5;
                puVar3 = param_4;
                do {
                  uVar6 = *puVar3;
                  puVar3 = puVar3 + 1;
                  *param_5 = (char)(uVar6 >> 0x17);
                  param_5 = param_5 + 1;
                  iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0;
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              uVar6 = *puVar3;
              puVar3 = puVar3 + 3;
              *param_5 = (char)(uVar6 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar6 = *puVar3;
                puVar3 = puVar3 + 1;
                *param_5 = (char)(uVar6 >> 0x17);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar4 = (int)puVar5 - (int)param_5;
              puVar3 = param_4;
              do {
                uVar6 = *puVar3;
                puVar3 = puVar3 + 2;
                *param_5 = (char)(uVar6 >> 0x17);
                param_5 = param_5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 3;
              *param_5 = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar4 = (int)puVar5 - (int)param_5;
            puVar3 = param_4;
            do {
              puVar1 = puVar3 + 2;
              puVar3 = puVar3 + 4;
              *param_5 = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(*puVar3 >> 0x17);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1906) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
                puVar3 = param_4;
                do {
                  uVar2 = *puVar3;
                  puVar3 = puVar3 + 1;
                  param_5[1] = 0xff;
                  *param_5 = (char)(uVar2 >> 0x17);
                  param_5 = param_5 + 2;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = (uint *)((int)param_4 + param_6);
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              do {
                *param_5 = 0;
                param_5[1] = 0xff;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = 0;
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 3;
                param_5[1] = 0xff;
                *param_5 = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[3] >> 0x17);
              uVar2 = *puVar3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(uVar2 >> 0x17);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                uVar2 = *puVar3;
                puVar3 = puVar3 + 1;
                param_5[1] = 0xff;
                *param_5 = (char)(uVar2 >> 0x17);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar3 = param_4;
              do {
                *param_5 = (char)(*puVar3 >> 0x17);
                puVar1 = puVar3 + 1;
                puVar3 = puVar3 + 2;
                param_5[1] = (char)(*puVar1 >> 0x17);
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = (uint *)((int)param_4 + param_6);
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              uVar2 = puVar3[2];
              puVar3 = puVar3 + 3;
              param_5[1] = 0xff;
              *param_5 = (char)(uVar2 >> 0x17);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar3 = param_4;
            do {
              *param_5 = (char)(puVar3[2] >> 0x17);
              puVar1 = puVar3 + 3;
              puVar3 = puVar3 + 4;
              param_5[1] = (char)(*puVar1 >> 0x17);
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = (uint *)((int)param_4 + param_6);
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastUint @ 0x101fe4 (5188 bytes) */
int _gleTextureImagePut_FastUint(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined1 *param_4;
  undefined1 *param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  iVar3 = _gleComponents(param_10);
  puVar5 = param_5 + param_2 * iVar3;
  switch(param_10) {
  case 0x1900:
    if (param_11 != 0x1900) {
      return 0;
    }
    if (0 < param_3) {
      do {
        if (param_5 < puVar5) {
          iVar3 = (int)puVar5 - (int)param_5;
          puVar4 = param_4;
          do {
            uVar2 = *puVar4;
            puVar4 = puVar4 + 4;
            *param_5 = uVar2;
            param_5 = param_5 + 1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + param_6;
        param_5 = param_5 + param_8;
        puVar5 = puVar5 + param_9;
      } while (param_3 != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              *param_5 = *puVar1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                *param_5 = uVar2;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1907) {
        if (param_11 < 0x1903) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0x10;
              *param_5 = uVar2;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0xff;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              puVar4 = param_4;
              do {
                puVar1 = puVar4 + 4;
                puVar4 = puVar4 + 8;
                *param_5 = *puVar1;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            do {
              *param_5 = 0xff;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              *param_5 = *puVar1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1907:
    if (param_11 == 0x1908) {
      puVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = *param_4;
            param_5[1] = param_4[4];
            puVar1 = param_4 + 8;
            param_4 = param_4 + 0x10;
            param_5[2] = *puVar1;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        puVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              uVar2 = *param_4;
              param_4 = param_4 + 4;
              param_5[2] = uVar2;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          puVar4 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                uVar2 = *param_4;
                param_4 = param_4 + 4;
                param_5[1] = 0;
                *param_5 = uVar2;
                param_5[2] = 0;
              }
              param_3 = param_3 + -1;
              param_4 = puVar4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar4 = param_4;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          puVar4 = param_4;
          if (0 < param_3) {
            do {
              for (; param_5 < puVar5; param_5 = param_5 + 3) {
                *param_5 = 0;
                uVar2 = *param_4;
                param_4 = param_4 + 4;
                param_5[2] = 0;
                param_5[1] = uVar2;
              }
              param_3 = param_3 + -1;
              param_4 = puVar4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
              puVar4 = param_4;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = 0;
              param_5[1] = 0;
              param_5[2] = 0;
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        puVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              *param_5 = *param_4;
              param_5[1] = param_4[4];
              puVar1 = param_4 + 8;
              param_4 = param_4 + 0xc;
              param_5[2] = *puVar1;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      puVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = param_4[0xc];
            param_5[1] = param_4[8];
            puVar1 = param_4 + 4;
            param_4 = param_4 + 0x10;
            param_5[2] = *puVar1;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        puVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 4;
              *param_5 = uVar2;
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        puVar4 = param_4;
        if (0 < param_3) {
          do {
            for (; param_5 < puVar5; param_5 = param_5 + 3) {
              uVar2 = *param_4;
              param_4 = param_4 + 8;
              *param_5 = uVar2;
              param_5[2] = *param_5;
              param_5[1] = *param_5;
            }
            param_3 = param_3 + -1;
            param_4 = puVar4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
            puVar4 = param_4;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      puVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = param_4[8];
            param_5[1] = param_4[4];
            uVar2 = *param_4;
            param_4 = param_4 + 0xc;
            param_5[2] = uVar2;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      puVar4 = param_4;
      if (0 < param_3) {
        do {
          for (; param_5 < puVar5; param_5 = param_5 + 3) {
            *param_5 = param_4[8];
            param_5[1] = param_4[4];
            uVar2 = *param_4;
            param_4 = param_4 + 0x10;
            param_5[2] = uVar2;
          }
          param_3 = param_3 + -1;
          param_4 = puVar4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
          puVar4 = param_4;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1908:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = *puVar4;
              param_5[1] = puVar4[4];
              param_5[2] = puVar4[8];
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              param_5[3] = *puVar1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 == 0x1905) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[3] = 0xff;
                param_5[2] = uVar2;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 < 0x1906) {
        if (param_11 == 0x1903) {
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar4 = param_4;
                do {
                  uVar2 = *puVar4;
                  puVar4 = puVar4 + 4;
                  param_5[1] = 0;
                  *param_5 = uVar2;
                  param_5[2] = 0;
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else {
          if (param_11 != 0x1904) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
                puVar4 = param_4;
                do {
                  *param_5 = 0;
                  uVar2 = *puVar4;
                  puVar4 = puVar4 + 4;
                  param_5[2] = 0;
                  param_5[1] = uVar2;
                  param_5[3] = 0xff;
                  param_5 = param_5 + 4;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = 0;
                param_5[1] = 0;
                param_5[2] = 0;
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[3] = uVar2;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = *puVar4;
                param_5[1] = puVar4[4];
                uVar2 = puVar4[8];
                puVar4 = puVar4 + 0xc;
                param_5[3] = 0xff;
                param_5[2] = uVar2;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = puVar4[0xc];
              param_5[1] = puVar4[8];
              param_5[2] = puVar4[4];
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0x10;
              param_5[3] = uVar2;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[3] = 0xff;
                *param_5 = uVar2;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
              puVar4 = param_4;
              do {
                *param_5 = *puVar4;
                param_5[2] = *param_5;
                param_5[1] = *param_5;
                puVar1 = puVar4 + 4;
                puVar4 = puVar4 + 8;
                param_5[3] = *puVar1;
                param_5 = param_5 + 4;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = puVar4[8];
              param_5[1] = puVar4[4];
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0xc;
              param_5[3] = 0xff;
              param_5[2] = uVar2;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (3 - (int)param_5)) >> 2;
            puVar4 = param_4;
            do {
              *param_5 = puVar4[8];
              param_5[1] = puVar4[4];
              param_5[2] = *puVar4;
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              param_5[3] = *puVar1;
              param_5 = param_5 + 4;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x1909:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0x10;
              *param_5 = uVar2;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1907) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                iVar3 = (int)puVar5 - (int)param_5;
                puVar4 = param_4;
                do {
                  uVar2 = *puVar4;
                  puVar4 = puVar4 + 4;
                  *param_5 = uVar2;
                  param_5 = param_5 + 1;
                  iVar3 = iVar3 + -1;
                } while (iVar3 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              do {
                *param_5 = 0;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0xc;
              *param_5 = uVar2;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              *param_5 = *puVar1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                *param_5 = uVar2;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              iVar3 = (int)puVar5 - (int)param_5;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 8;
                *param_5 = uVar2;
                param_5 = param_5 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              puVar1 = puVar4 + 8;
              puVar4 = puVar4 + 0xc;
              *param_5 = *puVar1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            iVar3 = (int)puVar5 - (int)param_5;
            puVar4 = param_4;
            do {
              puVar1 = puVar4 + 8;
              puVar4 = puVar4 + 0x10;
              *param_5 = *puVar1;
              param_5 = param_5 + 1;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    break;
  case 0x190a:
    if (param_11 == 0x1908) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar4 = param_4;
            do {
              *param_5 = *puVar4;
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              param_5[1] = *puVar1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x1909) {
      if (param_11 < 0x1906) {
        if (param_11 < 0x1904) {
          if (param_11 != 0x1903) {
            return 0;
          }
          if (0 < param_3) {
            do {
              if (param_5 < puVar5) {
                uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
                puVar4 = param_4;
                do {
                  uVar2 = *puVar4;
                  puVar4 = puVar4 + 4;
                  param_5[1] = 0xff;
                  *param_5 = uVar2;
                  param_5 = param_5 + 2;
                  uVar6 = uVar6 - 1;
                } while (uVar6 != 0);
              }
              param_3 = param_3 + -1;
              param_4 = param_4 + param_6;
              param_5 = param_5 + param_8;
              puVar5 = puVar5 + param_9;
            } while (param_3 != 0);
          }
        }
        else if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              do {
                *param_5 = 0;
                param_5[1] = 0xff;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else if (param_11 == 0x1906) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                *param_5 = 0;
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[1] = uVar2;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x1907) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 0xc;
                param_5[1] = 0xff;
                *param_5 = uVar2;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x8000) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar4 = param_4;
            do {
              *param_5 = puVar4[0xc];
              uVar2 = *puVar4;
              puVar4 = puVar4 + 0x10;
              param_5[1] = uVar2;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else if (param_11 < 0x8001) {
      if (param_11 == 0x1909) {
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                uVar2 = *puVar4;
                puVar4 = puVar4 + 4;
                param_5[1] = 0xff;
                *param_5 = uVar2;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
      else {
        if (param_11 != 0x190a) {
          return 0;
        }
        if (0 < param_3) {
          do {
            if (param_5 < puVar5) {
              uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
              puVar4 = param_4;
              do {
                *param_5 = *puVar4;
                puVar1 = puVar4 + 4;
                puVar4 = puVar4 + 8;
                param_5[1] = *puVar1;
                param_5 = param_5 + 2;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            param_3 = param_3 + -1;
            param_4 = param_4 + param_6;
            param_5 = param_5 + param_8;
            puVar5 = puVar5 + param_9;
          } while (param_3 != 0);
        }
      }
    }
    else if (param_11 == 0x80e0) {
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar4 = param_4;
            do {
              uVar2 = puVar4[8];
              puVar4 = puVar4 + 0xc;
              param_5[1] = 0xff;
              *param_5 = uVar2;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
    else {
      if (param_11 != 0x80e1) {
        return 0;
      }
      if (0 < param_3) {
        do {
          if (param_5 < puVar5) {
            uVar6 = (uint)(puVar5 + (1 - (int)param_5)) >> 1;
            puVar4 = param_4;
            do {
              *param_5 = puVar4[8];
              puVar1 = puVar4 + 0xc;
              puVar4 = puVar4 + 0x10;
              param_5[1] = *puVar1;
              param_5 = param_5 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          param_3 = param_3 + -1;
          param_4 = param_4 + param_6;
          param_5 = param_5 + param_8;
          puVar5 = puVar5 + param_9;
        } while (param_3 != 0);
      }
    }
  }
  return 1;
}

/* _gleCreateColorTableLevel @ 0x103454 (224 bytes) */
int _gleCreateColorTableLevel(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
{
  undefined2 uVar2;
  int iVar1;
  
  *(undefined1 *)(param_3 + 10) = 0;
  *(undefined4 *)(param_3 + 0x14) = 0;
  if (param_5 != 0) {
    *(undefined1 *)(param_3 + 0xb) = 0x20;
    *(short *)(param_3 + 4) = (short)param_5;
    *(undefined2 *)(param_3 + 6) = 1;
    *(undefined2 *)(param_3 + 8) = 1;
    uVar2 = _gleImagingTexFormatToInternal(param_4);
    *(undefined2 *)(param_3 + 0x10) = uVar2;
    *(undefined2 *)(param_3 + 0x12) = 0x1406;
    *(short *)(param_3 + 0xc) = (short)param_5;
    *(undefined2 *)(param_3 + 0xe) = 1;
    if (param_8 == 0) {
      return 1;
    }
    iVar1 = _gleAllocateTextureLevel(param_1,param_2,param_3);
    if (iVar1 != 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      return 1;
    }
  }
  *(undefined2 *)(param_3 + 0xe) = 0;
  *(undefined2 *)(param_3 + 4) = 0;
  *(undefined2 *)(param_3 + 6) = 0;
  *(undefined2 *)(param_3 + 8) = 0;
  *(undefined1 *)(param_3 + 0xb) = 0;
  *(undefined2 *)(param_3 + 0x10) = 0;
  *(undefined2 *)(param_3 + 0x12) = 0;
  *(undefined2 *)(param_3 + 0xc) = 0;
  return 0;
}

