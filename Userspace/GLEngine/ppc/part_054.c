#include "decls.h"

/* _gleMultiVtxTextureCoordGenNormalSTR @ 0xf73b4 (88 bytes) */
void _gleMultiVtxTextureCoordGenNormalSTR(param_1, vertexCursor, vertexCount, param_4)
  int param_1;
  uint vertexCursor;
  int vertexCount;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  int texCoordSlot;
  
  uVar2 = vertexCursor + vertexCount * 0x100;
  if (vertexCursor < uVar2) {
    uVar2 = (uVar2 - vertexCursor) + 0xff >> 8;
    do {
      texCoordSlot = param_4 * 0x10 + vertexCursor;
      *(undefined4 *)(texCoordSlot + 0x80) = *(undefined4 *)(vertexCursor + 0x40);
      *(undefined4 *)(texCoordSlot + 0x84) = *(undefined4 *)(vertexCursor + 0x44);
      puVar1 = (undefined4 *)(vertexCursor + 0x48);
      vertexCursor = vertexCursor + 0x100;
      *(undefined4 *)(texCoordSlot + 0x88) = *puVar1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
  return;
}

/* _gleTextureImageCopy @ 0xf7410 (260 bytes) */
void _gleTextureImageCopy(glContext, param_2, unusedArg3, param_4, y, width, height)
  int glContext;
  int param_2;
  undefined4 unusedArg3;
  undefined4 param_4;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar5 = *(undefined4 *)(glContext + 0x31b0);
  *(uint *)(glContext + 0x31b0) = (uint)*(ushort *)(param_2 + 0xc);
  uVar4 = *(undefined4 *)(glContext + 0x31c8);
  uVar3 = *(undefined4 *)(glContext + 0x31c0);
  uVar6 = *(undefined4 *)(0x31b4 + glContext);
  uVar7 = *(undefined4 *)(glContext + 0x31b8);
  *(uint *)(0x31b4 + glContext) = (uint)*(ushort *)(param_2 + 0xe);
  uVar2 = *(undefined4 *)(glContext + 0x31bc);
  uVar1 = *(undefined4 *)(glContext + 0x31c4);
  *(undefined1 *)(glContext + 0x31c8) = 0;
  *(undefined1 *)(glContext + 0x31c9) = 0;
  *(undefined4 *)(glContext + 0x31b8) = 0;
  *(undefined4 *)(glContext + 0x31bc) = 0;
  *(undefined4 *)(glContext + 0x31c0) = 0;
  *(undefined4 *)(glContext + 0x31c4) = 1;
  (**(code **)(glContext + 0x46a0))
            (*(undefined4 *)(glContext + 0x4688),param_4,y,width,height,
             *(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x12),
             *(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(glContext + 0x31b0) = uVar5;
  *(undefined4 *)(glContext + 0x31c8) = uVar4;
  *(undefined4 *)(0x31b4 + glContext) = uVar6;
  *(undefined4 *)(glContext + 0x31b8) = uVar7;
  *(undefined4 *)(glContext + 0x31bc) = uVar2;
  *(undefined4 *)(glContext + 0x31c0) = uVar3;
  *(undefined4 *)(glContext + 0x31c4) = uVar1;
  return;
}

/* _gleTextureSubImageCopy @ 0xf7514 (348 bytes) */
void _gleTextureSubImageCopy(glContext, param_2, param_3, yoffset, zoffset, param_6, y, width, height)
  int glContext;
  int param_2;
  int param_3;
  int yoffset;
  int zoffset;
  undefined4 param_6;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar7 = *(undefined4 *)(glContext + 0x31b0);
  *(uint *)(glContext + 0x31b0) = (uint)*(ushort *)(param_2 + 0xc);
  uVar8 = *(undefined4 *)(0x31b4 + glContext);
  *(uint *)(0x31b4 + glContext) = (uint)*(ushort *)(param_2 + 0xe);
  uVar4 = *(undefined4 *)(glContext + 0x31b8);
  uVar5 = *(undefined4 *)(glContext + 0x31c8);
  uVar2 = *(undefined4 *)(glContext + 0x31bc);
  uVar3 = *(undefined4 *)(glContext + 0x31c0);
  uVar6 = *(undefined4 *)(glContext + 0x31c4);
  if ((*(ushort *)(param_2 + 8) < 2) && (zoffset == 0)) {
    *(undefined4 *)(glContext + 0x31c0) = 0;
  }
  else {
    *(uint *)(glContext + 0x31c0) = zoffset + (uint)*(byte *)(param_2 + 10);
  }
  if ((*(ushort *)(param_2 + 6) < 2) && (yoffset == 0)) {
    *(undefined4 *)(glContext + 0x31b8) = 0;
  }
  else {
    *(uint *)(glContext + 0x31b8) = yoffset + (uint)*(byte *)(param_2 + 10);
  }
  bVar1 = *(byte *)(param_2 + 10);
  *(undefined4 *)(glContext + 0x31c4) = 1;
  *(undefined1 *)(glContext + 0x31c9) = 0;
  *(uint *)(glContext + 0x31bc) = param_3 + (uint)bVar1;
  *(undefined1 *)(glContext + 0x31c8) = 0;
  (**(code **)(glContext + 0x46a0))
            (*(undefined4 *)(glContext + 0x4688),param_6,y,width,height,
             *(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x12),
             *(undefined4 *)(param_2 + 0x14));
  *(undefined4 *)(glContext + 0x31b0) = uVar7;
  *(undefined4 *)(glContext + 0x31c8) = uVar5;
  *(undefined4 *)(0x31b4 + glContext) = uVar8;
  *(undefined4 *)(glContext + 0x31b8) = uVar4;
  *(undefined4 *)(glContext + 0x31bc) = uVar2;
  *(undefined4 *)(glContext + 0x31c0) = uVar3;
  *(undefined4 *)(glContext + 0x31c4) = uVar6;
  return;
}

/* _gleNoopFilter1 @ 0xf7670 (4 bytes) */
void _gleNoopFilter1()
{
  return;
}

/* _gleNoopFilter2 @ 0xf7674 (4 bytes) */
void _gleNoopFilter2()
{
  return;
}

/* _gleNoopFilter3 @ 0xf7678 (4 bytes) */
void _gleNoopFilter3()
{
  return;
}

/* _gleByteFilter1 @ 0xf767c (60 bytes) */
void _gleByteFilter1(dst, src, count, offsetA)
  int dst;
  char *src;
  int count;
  int offsetA;
{
  char cVar1;
  char *pcVar2;
  int byteOffset;
  
  byteOffset = 0;
  if (0 < count) {
    do {
      cVar1 = *src;
      pcVar2 = src + offsetA;
      src = src + 1;
      *(char *)(dst + byteOffset) = (char)((int)cVar1 + (int)*pcVar2 >> 1);
      byteOffset = byteOffset + 1;
      count = count + -1;
    } while (count != 0);
    return;
  }
  return;
}

/* _gleByteFilter2 @ 0xf76b8 (96 bytes) */
void _gleByteFilter2(dst, src, count, offsetA, offsetB)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
{
  char cVar1;
  int byteOffset;
  char *pcVar3;
  
  byteOffset = 0;
  if (count < 1) {
    return;
  }
  pcVar3 = (char *)(src + offsetA + offsetB);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *(char *)(dst + byteOffset) =
         (char)((int)*(char *)(src + byteOffset) + (int)*(char *)(src + byteOffset + offsetA) +
                (int)*(char *)(src + byteOffset + offsetB) + (int)cVar1 >> 2);
    byteOffset = byteOffset + 1;
    count = count + -1;
  } while (count != 0);
  return;
}

/* _gleByteFilter3 @ 0xf7718 (176 bytes) */
void _gleByteFilter3(dst, src, count, offsetA, offsetB, offsetC)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
  int offsetC;
{
  char cVar1;
  char *pcVar2;
  int byteOffset;
  int iVar4;
  char *pcVar5;
  
  byteOffset = 0;
  if (0 < count) {
    pcVar5 = (char *)(src + offsetB + offsetC);
    do {
      iVar4 = src + byteOffset;
      cVar1 = *pcVar5;
      pcVar2 = pcVar5 + offsetA;
      pcVar5 = pcVar5 + 1;
      *(char *)(dst + byteOffset) =
           (char)((int)*(char *)(src + byteOffset) + (int)*(char *)(iVar4 + offsetA) +
                  (int)*(char *)(iVar4 + offsetB) + (int)*(char *)(iVar4 + offsetA + offsetB) +
                  (int)*(char *)(iVar4 + offsetC) + (int)*(char *)(iVar4 + offsetA + offsetC) +
                  (int)cVar1 + (int)*pcVar2 >> 3);
      byteOffset = byteOffset + 1;
      count = count + -1;
    } while (count != 0);
  }
  return;
}

/* _gleUbyteFilter1 @ 0xf77c8 (52 bytes) */
void _gleUbyteFilter1(dst, src, count, offsetA)
  int dst;
  byte *src;
  int count;
  int offsetA;
{
  byte bVar1;
  byte *pbVar2;
  int byteOffset;
  
  byteOffset = 0;
  if (0 < count) {
    do {
      bVar1 = *src;
      pbVar2 = src + offsetA;
      src = src + 1;
      *(char *)(dst + byteOffset) = (char)((int)((uint)bVar1 + (uint)*pbVar2) >> 1);
      byteOffset = byteOffset + 1;
      count = count + -1;
    } while (count != 0);
    return;
  }
  return;
}

/* _gleUbyteFilter2 @ 0xf77fc (80 bytes) */
void _gleUbyteFilter2(dst, src, count, offsetA, offsetB)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
{
  byte bVar1;
  int byteOffset;
  byte *pbVar3;
  
  byteOffset = 0;
  if (count < 1) {
    return;
  }
  pbVar3 = (byte *)(src + offsetA + offsetB);
  do {
    bVar1 = *pbVar3;
    pbVar3 = pbVar3 + 1;
    *(char *)(dst + byteOffset) =
         (char)((int)((uint)*(byte *)(src + byteOffset) + (uint)*(byte *)(src + byteOffset + offsetA)
                      + (uint)*(byte *)(src + byteOffset + offsetB) + (uint)bVar1) >> 2);
    byteOffset = byteOffset + 1;
    count = count + -1;
  } while (count != 0);
  return;
}

/* _gleUbyteFilter3 @ 0xf784c (144 bytes) */
void _gleUbyteFilter3(dst, src, count, offsetA, offsetB, offsetC)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
  int offsetC;
{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int byteOffset;
  byte *pbVar5;
  
  byteOffset = 0;
  if (0 < count) {
    pbVar5 = (byte *)(src + offsetB + offsetC);
    do {
      iVar3 = src + byteOffset;
      bVar1 = *pbVar5;
      pbVar2 = pbVar5 + offsetA;
      pbVar5 = pbVar5 + 1;
      *(char *)(dst + byteOffset) =
           (char)((int)((uint)*(byte *)(src + byteOffset) + (uint)*(byte *)(iVar3 + offsetA) +
                        (uint)*(byte *)(iVar3 + offsetB) +
                        (uint)*(byte *)(iVar3 + offsetA + offsetB) +
                        (uint)*(byte *)(iVar3 + offsetC) +
                        (uint)*(byte *)(iVar3 + offsetA + offsetC) + (uint)bVar1 + (uint)*pbVar2) >>
                 3);
      byteOffset = byteOffset + 1;
      count = count + -1;
    } while (count != 0);
  }
  return;
}

/* _gleShortFilter1 @ 0xf78dc (60 bytes) */
void _gleShortFilter1(dst, src, count, offsetA)
  int dst;
  int src;
  uint count;
  int offsetA;
{
  int byteOffset;
  uint uVar2;
  
  byteOffset = 0;
  if ((int)(count << 1) < 1) {
    return;
  }
  uVar2 = count & 0x7fffffff;
  do {
    *(short *)(dst + byteOffset) =
         (short)((int)*(short *)(src + byteOffset) + (int)*(short *)(src + byteOffset + offsetA) >> 1)
    ;
    byteOffset = byteOffset + 2;
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  return;
}

/* _gleShortFilter2 @ 0xf7918 (80 bytes) */
void _gleShortFilter2(dst, src, count, offsetA, offsetB)
  int dst;
  int src;
  uint count;
  int offsetA;
  int offsetB;
{
  int iVar1;
  int byteOffset;
  uint uVar3;
  
  byteOffset = 0;
  if ((int)(count << 1) < 1) {
    return;
  }
  uVar3 = count & 0x7fffffff;
  do {
    iVar1 = src + byteOffset;
    *(short *)(dst + byteOffset) =
         (short)((int)*(short *)(src + byteOffset) + (int)*(short *)(iVar1 + offsetA) +
                 (int)*(short *)(iVar1 + offsetB) + (int)*(short *)(iVar1 + offsetA + offsetB) >> 2)
    ;
    byteOffset = byteOffset + 2;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}

/* _gleShortFilter3 @ 0xf7968 (148 bytes) */
void _gleShortFilter3(dst, src, count, offsetA, offsetB, offsetC)
  int dst;
  int src;
  uint count;
  int offsetA;
  int offsetB;
  int offsetC;
{
  short sVar1;
  short *psVar2;
  int iVar3;
  int byteOffset;
  short *psVar5;
  uint uVar6;
  
  byteOffset = 0;
  if (0 < (int)(count << 1)) {
    uVar6 = count & 0x7fffffff;
    psVar5 = (short *)(src + offsetB + offsetC);
    do {
      iVar3 = src + byteOffset;
      sVar1 = *psVar5;
      psVar2 = (short *)((int)psVar5 + offsetA);
      psVar5 = psVar5 + 1;
      *(short *)(dst + byteOffset) =
           (short)((int)*(short *)(src + byteOffset) + (int)*(short *)(iVar3 + offsetA) +
                   (int)*(short *)(iVar3 + offsetB) + (int)*(short *)(iVar3 + offsetA + offsetB) +
                   (int)*(short *)(iVar3 + offsetC) + (int)*(short *)(iVar3 + offsetA + offsetC) +
                   (int)sVar1 + (int)*psVar2 >> 3);
      byteOffset = byteOffset + 2;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}

/* _gleFloatFilter1 @ 0xf7db4 (84 bytes) */
void _gleFloatFilter1(dst, src, count, offsetA, unusedArg5, unusedArg6, unusedArg7)
  int dst;
  int src;
  uint count;
  int offsetA;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  float weight;
  int byteOffset;
  uint remaining;
  
  weight = FLOAT_00108e90;
  byteOffset = 0;
  if ((int)(count << 2) < 1) {
    return;
  }
  remaining = count & 0x3fffffff;
  do {
    *(float *)(dst + byteOffset) =
         (*(float *)(src + byteOffset) + *(float *)(src + byteOffset + offsetA)) * weight;
    byteOffset = byteOffset + 4;
    remaining = remaining - 1;
  } while (remaining != 0);
  return;
}

/* _gleFloatFilter2 @ 0xf7e08 (104 bytes) */
void _gleFloatFilter2(dst, src, count, offsetA, offsetB, unusedArg6, unusedArg7)
  int dst;
  int src;
  uint count;
  int offsetA;
  int offsetB;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  float weight;
  int iVar2;
  int byteOffset;
  uint remaining;
  
  weight = FLOAT_00108f88;
  byteOffset = 0;
  if ((int)(count << 2) < 1) {
    return;
  }
  remaining = count & 0x3fffffff;
  do {
    iVar2 = src + byteOffset;
    *(float *)(dst + byteOffset) =
         (*(float *)(src + byteOffset) + *(float *)(iVar2 + offsetA) + *(float *)(iVar2 + offsetB) +
         *(float *)(iVar2 + offsetA + offsetB)) * weight;
    byteOffset = byteOffset + 4;
    remaining = remaining - 1;
  } while (remaining != 0);
  return;
}

/* _gleFloatFilter3 @ 0xf7e70 (156 bytes) */
void _gleFloatFilter3(dst, src, count, offsetA, offsetB, offsetC, unusedArg7, unusedArg8)
  int dst;
  int src;
  uint count;
  int offsetA;
  int offsetB;
  int offsetC;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  float fVar1;
  float *pfVar2;
  float weight;
  int iVar4;
  int byteOffset;
  float *pfVar6;
  uint remaining;
  
  weight = FLOAT_00108f4c;
  byteOffset = 0;
  if (0 < (int)(count << 2)) {
    remaining = count & 0x3fffffff;
    pfVar6 = (float *)(src + offsetB + offsetC);
    do {
      iVar4 = src + byteOffset;
      fVar1 = *pfVar6;
      pfVar2 = (float *)((int)pfVar6 + offsetA);
      pfVar6 = pfVar6 + 1;
      *(float *)(dst + byteOffset) =
           (*(float *)(src + byteOffset) + *(float *)(iVar4 + offsetA) + *(float *)(iVar4 + offsetB)
            + *(float *)(iVar4 + offsetA + offsetB) + *(float *)(iVar4 + offsetC) +
            *(float *)(iVar4 + offsetA + offsetC) + fVar1 + *pfVar2) * weight;
      byteOffset = byteOffset + 4;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  return;
}

/* _gleHalfFloatFilter1 @ 0xf7f0c (284 bytes) */
void _gleHalfFloatFilter1(dst, src, count, offsetA)
  int dst;
  int src;
  int count;
  int offsetA;
{
  float fVar1;
  uint uVar2;
  float weight;
  ushort uVar4;
  int byteOffset;
  double dVar6;
  double dVar7;
  
  weight = FLOAT_00108e90;
  byteOffset = 0;
  if (0 < count << 1) {
    do {
      dVar6 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(src + byteOffset));
      dVar7 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(src + byteOffset + offsetA));
      fVar1 = (float)(dVar6 + dVar7) * weight;
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
      *(ushort *)(dst + byteOffset) = uVar4;
      byteOffset = byteOffset + 2;
    } while (byteOffset < count << 1);
  }
  return;
}

/* _gleHalfFloatFilter2 @ 0xf8028 (316 bytes) */
void _gleHalfFloatFilter2(dst, src, count, offsetA, offsetB)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
{
  float fVar1;
  uint uVar2;
  float weight;
  ushort uVar4;
  int iVar5;
  int byteOffset;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  
  weight = FLOAT_00108f88;
  byteOffset = 0;
  if (0 < count << 1) {
    do {
      iVar5 = src + byteOffset;
      dVar7 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(src + byteOffset));
      dVar8 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + offsetA));
      dVar9 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + offsetB));
      dVar10 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar5 + offsetA + offsetB));
      fVar1 = (float)((double)(float)((double)(float)(dVar7 + dVar8) + dVar9) + dVar10) * weight;
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
      *(ushort *)(dst + byteOffset) = uVar4;
      byteOffset = byteOffset + 2;
    } while (byteOffset < count << 1);
  }
  return;
}

/* _gleHalfFloatFilter3 @ 0xf8164 (380 bytes) */
void _gleHalfFloatFilter3(dst, src, count, offsetA, offsetB, offsetC)
  int dst;
  int src;
  int count;
  int offsetA;
  int offsetB;
  int offsetC;
{
  float fVar1;
  uint uVar2;
  float weight;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  int byteOffset;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  
  weight = FLOAT_00108f4c;
  byteOffset = 0;
  if (0 < count << 1) {
    puVar5 = (ushort *)(src + offsetB + offsetC);
    do {
      iVar6 = src + byteOffset;
      dVar8 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(src + byteOffset));
      dVar9 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + offsetA));
      dVar10 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + offsetB));
      dVar11 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + offsetA + offsetB));
      dVar12 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + offsetC));
      dVar13 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)(iVar6 + offsetA + offsetC));
      dVar14 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*puVar5);
      dVar15 = (double)((double (*)())_gleHalfFloatToFloat)((uint)*(ushort *)((int)puVar5 + offsetA));
      fVar1 = (float)((double)(float)((double)(float)((double)(float)((double)(float)((double)(float
                                                  )((double)(float)(dVar8 + dVar9) + dVar10) +
                                                  dVar11) + dVar12) + dVar13) + dVar14) + dVar15) *
              weight;
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
      *(ushort *)(dst + byteOffset) = uVar4;
      byteOffset = byteOffset + 2;
      puVar5 = puVar5 + 1;
    } while (byteOffset < count << 1);
  }
  return;
}

/* _gle332Filter1 @ 0xf82e0 (72 bytes) */
void _gle332Filter1(dst, src, unusedArg3, offsetA)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  *dst = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) >> 1) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) >> 1) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) >> 1);
  return;
}

/* _gle332Filter2 @ 0xf8328 (140 bytes) */
void _gle332Filter2(dst, src, unusedArg3, offsetA, offsetB)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  bVar3 = src[offsetB];
  bVar4 = src[offsetB + offsetA];
  *dst = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) + (bVar3 & 0xe0) + (bVar4 & 0xe0) >> 2) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) + (bVar3 & 0x1c) + (bVar4 & 0x1c) >> 2) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) + (bVar3 & 3) + (bVar4 & 3) >> 2) & 3;
  return;
}

/* _gle332Filter3 @ 0xf83b4 (260 bytes) */
void _gle332Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  bVar3 = src[offsetB];
  bVar4 = src[offsetB + offsetA];
  bVar5 = src[offsetC];
  bVar6 = src[offsetC + offsetA];
  bVar7 = src[offsetC + offsetB];
  bVar8 = src[offsetC + offsetB + offsetA];
  *dst = (byte)((bVar1 & 0xe0) + (bVar2 & 0xe0) + (bVar3 & 0xe0) + (bVar4 & 0xe0) +
                    (bVar5 & 0xe0) + (bVar6 & 0xe0) + (bVar7 & 0xe0) + (bVar8 & 0xe0) >> 3) & 0xe0 |
             (byte)((bVar1 & 0x1c) + (bVar2 & 0x1c) + (bVar3 & 0x1c) + (bVar4 & 0x1c) +
                    (bVar5 & 0x1c) + (bVar6 & 0x1c) + (bVar7 & 0x1c) + (bVar8 & 0x1c) >> 3) & 0x1c |
             (byte)((bVar1 & 3) + (bVar2 & 3) + (bVar3 & 3) + (bVar4 & 3) + (bVar5 & 3) +
                    (bVar6 & 3) + (bVar7 & 3) + (bVar8 & 3) >> 3) & 3;
  return;
}

/* _gle233RevFilter1 @ 0xf84b8 (72 bytes) */
void _gle233RevFilter1(dst, src, unusedArg3, offsetA)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  *dst = (byte)((bVar1 & 7) + (bVar2 & 7) >> 1) |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) >> 1) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) >> 1) & 0xc0;
  return;
}

/* _gle233RevFilter2 @ 0xf8500 (140 bytes) */
void _gle233RevFilter2(dst, src, unusedArg3, offsetA, offsetB)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  bVar3 = src[offsetB];
  bVar4 = src[offsetB + offsetA];
  *dst = (byte)((bVar1 & 7) + (bVar2 & 7) + (bVar3 & 7) + (bVar4 & 7) >> 2) & 7 |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) + (bVar3 & 0x38) + (bVar4 & 0x38) >> 2) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) + (bVar3 & 0xc0) + (bVar4 & 0xc0) >> 2) & 0xc0;
  return;
}

/* _gle233RevFilter3 @ 0xf858c (260 bytes) */
void _gle233RevFilter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  byte *dst;
  byte *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  
  bVar1 = *src;
  bVar2 = src[offsetA];
  bVar3 = src[offsetB];
  bVar4 = src[offsetB + offsetA];
  bVar5 = src[offsetC];
  bVar6 = src[offsetC + offsetA];
  bVar7 = src[offsetC + offsetB];
  bVar8 = src[offsetC + offsetB + offsetA];
  *dst = (byte)((bVar1 & 7) + (bVar2 & 7) + (bVar3 & 7) + (bVar4 & 7) + (bVar5 & 7) +
                    (bVar6 & 7) + (bVar7 & 7) + (bVar8 & 7) >> 3) & 7 |
             (byte)((bVar1 & 0x38) + (bVar2 & 0x38) + (bVar3 & 0x38) + (bVar4 & 0x38) +
                    (bVar5 & 0x38) + (bVar6 & 0x38) + (bVar7 & 0x38) + (bVar8 & 0x38) >> 3) & 0x38 |
             (byte)((bVar1 & 0xc0) + (bVar2 & 0xc0) + (bVar3 & 0xc0) + (bVar4 & 0xc0) +
                    (bVar5 & 0xc0) + (bVar6 & 0xc0) + (bVar7 & 0xc0) + (bVar8 & 0xc0) >> 3) & 0xc0;
  return;
}

/* _gle565Filter1 @ 0xf8690 (72 bytes) */
void _gle565Filter1(dst, src, unusedArg3, offsetA)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  *dst = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) >> 1) & 0xf800 |
             (ushort)((uVar1 & 0x7e0) + (uVar2 & 0x7e0) >> 1) & 0x7e0 |
             (ushort)((uVar1 & 0x1f) + (uVar2 & 0x1f) >> 1);
  return;
}

/* _gle565Filter2 @ 0xf86d8 (140 bytes) */
void _gle565Filter2(dst, src, unusedArg3, offsetA, offsetB)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  uVar3 = *(ushort *)((int)src + offsetB);
  uVar4 = *(ushort *)((int)src + offsetB + offsetA);
  *dst = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) + (uVar3 & 0xf800) + (uVar4 & 0xf800) >> 2
                     ) & 0xf800 |
             (ushort)((uVar1 & 0x7e0) + (uVar2 & 0x7e0) + (uVar3 & 0x7e0) + (uVar4 & 0x7e0) >> 2) &
             0x7e0 | (ushort)((uVar1 & 0x1f) + (uVar2 & 0x1f) + (uVar3 & 0x1f) + (uVar4 & 0x1f) >> 2
                             ) & 0x1f;
  return;
}

/* _gle565Filter3 @ 0xf8764 (260 bytes) */
void _gle565Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  uVar3 = *(ushort *)((int)src + offsetB);
  uVar4 = *(ushort *)((int)src + offsetB + offsetA);
  uVar5 = *(ushort *)((int)src + offsetC);
  uVar6 = *(ushort *)((int)src + offsetC + offsetA);
  uVar7 = *(ushort *)((int)src + offsetC + offsetB);
  uVar8 = *(ushort *)((int)src + offsetC + offsetB + offsetA);
  *dst = (ushort)((uVar1 & 0xf800) + (uVar2 & 0xf800) + (uVar3 & 0xf800) + (uVar4 & 0xf800) +
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
void _gle4444Filter1(dst, src, unusedArg3, offsetA)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  *dst = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) >> 1) & 0xf000 |
             (ushort)((uVar1 & 0xf00) + (uVar2 & 0xf00) >> 1) & 0xf00 |
             (ushort)((uVar1 & 0xf0) + (uVar2 & 0xf0) >> 1) & 0xf0 |
             (ushort)((uVar1 & 0xf) + (uVar2 & 0xf) >> 1);
  return;
}

/* _gle4444Filter2 @ 0xf88c4 (176 bytes) */
void _gle4444Filter2(dst, src, unusedArg3, offsetA, offsetB)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  uVar3 = *(ushort *)((int)src + offsetB);
  uVar4 = *(ushort *)((int)src + offsetB + offsetA);
  *dst = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) + (uVar3 & 0xf000) + (uVar4 & 0xf000) >> 2
                     ) & 0xf000 |
             (ushort)((uVar1 & 0xf00) + (uVar2 & 0xf00) + (uVar3 & 0xf00) + (uVar4 & 0xf00) >> 2) &
             0xf00 | (ushort)((uVar1 & 0xf0) + (uVar2 & 0xf0) + (uVar3 & 0xf0) + (uVar4 & 0xf0) >> 2
                             ) & 0xf0 |
             (ushort)((uVar1 & 0xf) + (uVar2 & 0xf) + (uVar3 & 0xf) + (uVar4 & 0xf) >> 2) & 0xf;
  return;
}

/* _gle4444Filter3 @ 0xf8974 (328 bytes) */
void _gle4444Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  ushort *dst;
  ushort *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar1 = *src;
  uVar2 = *(ushort *)((int)src + offsetA);
  uVar3 = *(ushort *)((int)src + offsetB);
  uVar4 = *(ushort *)((int)src + offsetB + offsetA);
  uVar5 = *(ushort *)((int)src + offsetC);
  uVar6 = *(ushort *)((int)src + offsetC + offsetA);
  uVar7 = *(ushort *)((int)src + offsetC + offsetB);
  uVar8 = *(ushort *)((int)src + offsetC + offsetB + offsetA);
  *dst = (ushort)((uVar1 & 0xf000) + (uVar2 & 0xf000) + (uVar3 & 0xf000) + (uVar4 & 0xf000) +
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
void _gles8s8Filter1(dst, src, unusedArg3, offsetA)
  ushort *dst;
  undefined2 *src;
  undefined4 unusedArg3;
  int offsetA;
{
  *dst = ((short)(char)((ushort)*src >> 8) +
             (short)(char)((ushort)*(undefined2 *)((int)src + offsetA) >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*src +
                            (int)(char)*(undefined2 *)((int)src + offsetA)) >> 1) & 0xff;
  return;
}

/* _gles8s8Filter2 @ 0xfa224 (112 bytes) */
void _gles8s8Filter2(dst, src, unusedArg3, offsetA, offsetB)
  ushort *dst;
  undefined2 *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)((int)src + offsetB + offsetA);
  *dst = ((short)(char)((ushort)*src >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetA) >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetB) >> 8) +
             (short)(char)((ushort)uVar1 >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*src +
                             (int)(char)*(undefined2 *)((int)src + offsetA) +
                             (int)(char)*(undefined2 *)((int)src + offsetB) + (int)(char)uVar1)
                     >> 1) & 0xff;
  return;
}

/* _gles8s8Filter3 @ 0xfa294 (224 bytes) */
void _gles8s8Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  ushort *dst;
  undefined2 *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar1 = *(undefined2 *)((int)src + offsetB + offsetA);
  uVar2 = *(undefined2 *)((int)src + offsetC + offsetA);
  uVar3 = *(undefined2 *)((int)src + offsetC + offsetB);
  uVar4 = *(undefined2 *)((int)src + offsetC + offsetB + offsetA);
  *dst = ((short)(char)((ushort)*src >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetA) >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetB) >> 8) +
              (short)(char)((ushort)uVar1 >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetC) >> 8) +
              (short)(char)((ushort)uVar2 >> 8) + (short)(char)((ushort)uVar3 >> 8) +
             (short)(char)((ushort)uVar4 >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*src +
                             (int)(char)*(undefined2 *)((int)src + offsetA) +
                             (int)(char)*(undefined2 *)((int)src + offsetB) + (int)(char)uVar1 +
                             (int)(char)*(undefined2 *)((int)src + offsetC) + (int)(char)uVar2 +
                             (int)(char)uVar3 + (int)(char)uVar4) >> 1) & 0xff;
  return;
}

/* _gles16s16Filter1 @ 0xfa374 (52 bytes) */
void _gles16s16Filter1(dst, src, unusedArg3, offsetA)
  uint *dst;
  int *src;
  undefined4 unusedArg3;
  int offsetA;
{
  *dst = ((*src >> 0x10) + (*(int *)((int)src + offsetA) >> 0x10)) * 0x8000 &
             0xffff0000U |
             (uint)((int)(short)*src + (int)(short)*(int *)((int)src + offsetA)) >> 1 &
             0xffff;
  return;
}

/* _gles16s16Filter2 @ 0xfa3a8 (96 bytes) */
void _gles16s16Filter2(dst, src, unusedArg3, offsetA, offsetB)
  uint *dst;
  int *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  int iVar1;
  
  iVar1 = *(int *)((int)src + offsetB + offsetA);
  *dst = ((*src >> 0x10) + (*(int *)((int)src + offsetA) >> 0x10) +
              (*(int *)((int)src + offsetB) >> 0x10) + (iVar1 >> 0x10)) * 0x8000 & 0xffff0000U |
             (uint)((int)(short)*src + (int)(short)*(int *)((int)src + offsetA) +
                    (int)(short)*(int *)((int)src + offsetB) + (int)(short)iVar1) >> 1 & 0xffff;
  return;
}

/* _gles16s16Filter3 @ 0xfa408 (192 bytes) */
void _gles16s16Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  uint *dst;
  int *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)((int)src + offsetB + offsetA);
  iVar2 = *(int *)((int)src + offsetC + offsetA);
  iVar3 = *(int *)((int)src + offsetC + offsetB);
  iVar4 = *(int *)((int)src + offsetC + offsetB + offsetA);
  *dst = ((*src >> 0x10) + (*(int *)((int)src + offsetA) >> 0x10) +
              (*(int *)((int)src + offsetB) >> 0x10) + (iVar1 >> 0x10) +
              (*(int *)((int)src + offsetC) >> 0x10) + (iVar2 >> 0x10) + (iVar3 >> 0x10) +
             (iVar4 >> 0x10)) * 0x8000 & 0xffff0000U |
             (uint)((int)(short)*src + (int)(short)*(int *)((int)src + offsetA) +
                    (int)(short)*(int *)((int)src + offsetB) + (int)(short)iVar1 +
                    (int)(short)*(int *)((int)src + offsetC) + (int)(short)iVar2 +
                    (int)(short)iVar3 + (int)(short)iVar4) >> 1 & 0xffff;
  return;
}

/* _gle1616Filter1 @ 0xfa4c8 (52 bytes) */
void _gle1616Filter1(dst, src, unusedArg3, offsetA)
  uint *dst;
  uint *src;
  undefined4 unusedArg3;
  int offsetA;
{
  *dst = ((*src >> 0x10) + (*(uint *)((int)src + offsetA) >> 0x10)) * 0x8000 &
             0xffff0000 | (*src & 0xffff) + (*(uint *)((int)src + offsetA) & 0xffff) >> 1;
  return;
}

/* _gle1616Filter2 @ 0xfa4fc (96 bytes) */
void _gle1616Filter2(dst, src, unusedArg3, offsetA, offsetB)
  uint *dst;
  uint *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
{
  uint uVar1;
  
  uVar1 = *(uint *)((int)src + offsetB + offsetA);
  *dst = ((*src >> 0x10) + (*(uint *)((int)src + offsetA) >> 0x10) +
              (*(uint *)((int)src + offsetB) >> 0x10) + (uVar1 >> 0x10)) * 0x8000 & 0xffff0000 |
             (*src & 0xffff) + (*(uint *)((int)src + offsetA) & 0xffff) +
             (*(uint *)((int)src + offsetB) & 0xffff) + (uVar1 & 0xffff) >> 1 & 0xffff;
  return;
}

/* _gle1616Filter3 @ 0xfa55c (192 bytes) */
void _gle1616Filter3(dst, src, unusedArg3, offsetA, offsetB, offsetC)
  uint *dst;
  uint *src;
  undefined4 unusedArg3;
  int offsetA;
  int offsetB;
  int offsetC;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *(uint *)((int)src + offsetB + offsetA);
  uVar2 = *(uint *)((int)src + offsetC + offsetA);
  uVar3 = *(uint *)((int)src + offsetC + offsetB);
  uVar4 = *(uint *)((int)src + offsetC + offsetB + offsetA);
  *dst = ((*src >> 0x10) + (*(uint *)((int)src + offsetA) >> 0x10) +
              (*(uint *)((int)src + offsetB) >> 0x10) + (uVar1 >> 0x10) +
              (*(uint *)((int)src + offsetC) >> 0x10) + (uVar2 >> 0x10) + (uVar3 >> 0x10) +
             (uVar4 >> 0x10)) * 0x8000 & 0xffff0000 |
             (*src & 0xffff) + (*(uint *)((int)src + offsetA) & 0xffff) +
             (*(uint *)((int)src + offsetB) & 0xffff) + (uVar1 & 0xffff) +
             (*(uint *)((int)src + offsetC) & 0xffff) + (uVar2 & 0xffff) + (uVar3 & 0xffff) +
             (uVar4 & 0xffff) >> 1 & 0xffff;
  return;
}

/* _gleGenerateMipmapData @ 0xfa61c (5348 bytes) */
void _gleGenerateMipmapData(glContext, texture, face, sourceLevel, lastLevelThenLevelArg)
  int glContext;
  int texture;
  int face;
  int sourceLevel;
  int lastLevelThenLevelArg;
{
  bool moreThanOneDimension;
  bool isThreeDimensional;
  bool isOneDimensional;
  bool isTwoDimensional;
  ushort destWidth;
  ushort uVar6;
  ushort format;
  ushort pixelType;
  ushort dimensionCode;
  int levelRecordThenComponentCount;
  int blockBytes;
  int destLevelRecord;
  int bytesPerPixel;
  int savedGlContext;
  int decodedData;
  int iVar10;
  undefined4 rgbaRowBytes;
  undefined4 compressedBuffer;
  undefined4 compressedRowBytes;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int incomingR8;
  undefined *puVar15;
  int incomingR10;
  int iVar16;
  int iVar17;
  int dstCursor3;
  int columnsRemaining3;
  int sliceBytes;
  code *filter2D;
  code *filter3D;
  int srcThenDestInteriorWidth;
  int pixelTransferState;
  int rowBytes;
  int dstCursor4;
  int pixelStep;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  int iVar31;
  byte in_xer_so = 0;
  byte bVar32;
  byte in_cr1;
  byte bVar33;
  byte bVar34;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte bVar35;
  int iStack00000018;
  int iStack0000001c;
  int iStack00000020;
  int iStack00000028;
  uint destHeight;
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
  int sourceImage;
  int nextLevel;
  int levelsToRecompress;
  uint srcThenDestInteriorHeight;
  uint srcThenDestInteriorDepth;
  int twiceBorder;
  int dimensions;
  uint pixelPairShift;
  int originalCompressedData;
  int decodedLevelData;
  code *filter1D;
  int faceOffset;
  int rowPadBytes;
  uint slicesRemaining;
  int borderCopy;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int firstGeneratedLevel;
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
  
  dimensionCode = *(ushort *)(texture + 0x24) & 0xf;
  pixelPairShift = 0;
  originalCompressedData = 0;
  if (dimensionCode == 1) {
    dimensions = 3;
  }
  else {
    if (dimensionCode < 2) {
      if ((*(ushort *)(texture + 0x24) & 0xf) != 0) {
        return;
      }
    }
    else if (dimensionCode != 3) {
      if (dimensionCode != 4) {
        return;
      }
      dimensions = 1;
      goto LAB_000fa6b0;
    }
    dimensions = 2;
  }
LAB_000fa6b0:
  faceOffset = face * 0x168;
  levelRecordThenComponentCount = texture + faceOffset + sourceLevel * 0x18;
  sourceImage = levelRecordThenComponentCount + 0xc4;
  iStack00000018 = glContext;
  iStack0000001c = texture;
  iStack00000020 = face;
  iStack00000028 = lastLevelThenLevelArg;
  levelRecordThenComponentCount = _gleComponents((uint)*(ushort *)(levelRecordThenComponentCount + 0xd4));
  filter2D = (code *)PTR__gle8888Filter2_001115d4;
  filter3D = (code *)PTR__gle8888Filter3_001115d0;
  pixelType = *(ushort *)(sourceImage + 0x12);
  uVar28 = (uint)pixelType;
  bVar35 = (uVar28 < 0x8032) << 3 | (0x8032 < uVar28) << 2 | (uVar28 == 0x8032) << 1 | in_xer_so & 1
  ;
  if (uVar28 == 0x8032) {
    filter1D = (code *)PTR__gle332Filter1_0011156c;
    filter2D = (code *)PTR__gle332Filter2_00111568;
    filter3D = (code *)PTR__gle332Filter3_00111564;
LAB_000faa98:
    bytesPerPixel = 1;
    goto LAB_000facc8;
  }
  if (0x8032 >= uVar28) {
    bVar35 = (uVar28 < 0x1400) << 3 | (0x1400 < uVar28) << 2 | (uVar28 == 0x1400) << 1 |
             in_xer_so & 1;
    bytesPerPixel = levelRecordThenComponentCount;
    if (uVar28 == 0x1400) {
      filter1D = (code *)PTR__gleByteFilter1_001115c0;
      filter2D = (code *)PTR__gleByteFilter2_001115bc;
      filter3D = (code *)PTR__gleByteFilter3_001115b8;
      goto LAB_000facc8;
    }
    if (0x1400 >= uVar28) {
      bVar35 = (uVar28 < 5) << 3 | (5 < uVar28) << 2 | (uVar28 == 5) << 1 | in_xer_so & 1;
      if (uVar28 == 5) {
        filter1D = (code *)PTR__gle1616Filter1_001114dc;
        filter2D = (code *)PTR__gle1616Filter2_001114d8;
        filter3D = (code *)PTR__gle1616Filter3_001114d4;
      }
      else {
        if (5 >= uVar28) {
          if (uVar28 == 0) {
            levelRecordThenComponentCount = 4;
            puVar15 = &DAT_0010a634;
            filter1D = (code *)PTR__gle8888Filter1_001115d8;
            originalCompressedData = *(int *)(sourceImage + 0x14);
            decodedData = _malloc((uint)*(ushort *)(sourceImage + 4) * 4 * (uint)*(ushort *)(sourceImage + 6) *
                            (uint)*(ushort *)(sourceImage + 8));
            bVar35 = (decodedData < 0) << 3 | (0 < decodedData) << 2 | (decodedData == 0) << 1 | in_xer_so & 1;
            *(int *)(sourceImage + 0x14) = decodedData;
            if (decodedData == 0) {
              return;
            }
            rgbaRowBytes = _gleRowBytes(0x1908,0x8035,(uint)*(ushort *)(sourceImage + 4));
            compressedRowBytes = _gleRowBytes((uint)*(ushort *)(sourceImage + 0x10),0,
                                  (uint)*(ushort *)(sourceImage + 0xc));
            _glgConvertType((uint)*(ushort *)(sourceImage + 0x10),0,auStack_1a8,auStack_1a4,lastLevelThenLevelArg,
                            incomingR8,puVar15,incomingR10);
            puVar13 = auStack_198;
            puVar14 = auStack_194;
            _glgConvertType(0x1908,0x8035,puVar13,puVar14,lastLevelThenLevelArg,incomingR8,puVar15,incomingR10);
            local_190 = 2;
            local_184 = (uint)*(ushort *)(sourceImage + 4);
            local_180 = (uint)*(ushort *)(sourceImage + 6);
            local_1b0 = originalCompressedData;
            local_1a0 = *(undefined4 *)(sourceImage + 0x14);
            local_144 = (undefined1)pixelType;
            local_1ac = compressedRowBytes;
            local_19c = rgbaRowBytes;
            local_18c = uVar28;
            local_188 = uVar28;
            _glgProcessPixels(iStack00000018 + 0x31a8,&local_1b0,puVar13,puVar14,lastLevelThenLevelArg,incomingR8,
                              iStack00000018,incomingR10);
            bytesPerPixel = 4;
            goto LAB_000facc8;
          }
          bVar35 = (uVar28 == 0) << 3 | (1 < uVar28) << 2 | (uVar28 == 1) << 1 | in_xer_so & 1;
          if (uVar28 != 1) {
            return;
          }
          filter1D = (code *)PTR__gles8s8Filter1_001114e8;
          filter2D = (code *)PTR__gles8s8Filter2_001114e4;
          filter3D = (code *)PTR__gles8s8Filter3_001114e0;
          goto LAB_000fac40;
        }
        bVar35 = (uVar28 < 7) << 3 | (7 < uVar28) << 2 | (uVar28 == 7) << 1 | in_xer_so & 1;
        if (uVar28 == 7) {
          filter1D = (code *)PTR__gle8s8s8s8Filter1_001114c4;
          filter2D = (code *)PTR__gle8s8s8s8Filter2_001114c0;
          filter3D = (code *)PTR__gle8s8s8s8Filter3_001114bc;
        }
        else if (uVar28 < 7) {
          filter1D = (code *)PTR__gles16s16Filter1_001114d0;
          filter2D = (code *)PTR__gles16s16Filter2_001114cc;
          filter3D = (code *)PTR__gles16s16Filter3_001114c8;
        }
        else {
          bVar35 = (uVar28 < 8) << 3 | (8 < uVar28) << 2 | (uVar28 == 8) << 1 | in_xer_so & 1;
          if (uVar28 != 8) {
            return;
          }
          filter1D = (code *)PTR__gles8s8s8s8Filter1_001114b8;
          filter2D = (code *)PTR__gles8s8s8s8Filter2_001114b4;
          filter3D = (code *)PTR__gles8s8s8s8Filter3_001114b0;
        }
      }
      goto LAB_000facc4;
    }
    bVar35 = (uVar28 < 0x1404) << 3 | (0x1404 < uVar28) << 2 | (uVar28 == 0x1404) << 1 |
             in_xer_so & 1;
    if (uVar28 == 0x1404) {
      filter1D = (code *)PTR__gleIntFilter1_00111590;
      filter2D = (code *)PTR__gleIntFilter2_0011158c;
      filter3D = (code *)PTR__gleIntFilter3_00111588;
    }
    else {
      if (0x1404 >= uVar28) {
        bVar35 = (uVar28 < 0x1402) << 3 | (0x1402 < uVar28) << 2 | (uVar28 == 0x1402) << 1 |
                 in_xer_so & 1;
        if (uVar28 == 0x1402) {
          filter1D = (code *)PTR__gleShortFilter1_001115a8;
          filter2D = (code *)PTR__gleShortFilter2_001115a4;
          filter3D = (code *)PTR__gleShortFilter3_001115a0;
        }
        else {
          if (0x1402 >= uVar28) {
            filter1D = (code *)PTR__gleUbyteFilter1_001115cc;
            filter2D = (code *)PTR__gleUbyteFilter2_001115c8;
            filter3D = (code *)PTR__gleUbyteFilter3_001115c4;
            goto LAB_000facc8;
          }
          filter1D = (code *)PTR__gleUshortFilter1_001115b4;
          filter2D = (code *)PTR__gleUshortFilter2_001115b0;
          filter3D = (code *)PTR__gleUshortFilter3_001115ac;
        }
LAB_000faa54:
        bytesPerPixel = levelRecordThenComponentCount << 1;
        goto LAB_000facc8;
      }
      bVar35 = (uVar28 < 0x1406) << 3 | (0x1406 < uVar28) << 2 | (uVar28 == 0x1406) << 1 |
               in_xer_so & 1;
      if (uVar28 == 0x1406) {
        filter1D = (code *)PTR__gleFloatFilter1_00111584;
        filter2D = (code *)PTR__gleFloatFilter2_00111580;
        filter3D = (code *)PTR__gleFloatFilter3_0011157c;
      }
      else {
        if (uVar28 >= 0x1406) {
          bVar35 = (uVar28 < 0x140b) << 3 | (0x140b < uVar28) << 2 | (uVar28 == 0x140b) << 1 |
                   in_xer_so & 1;
          if (uVar28 != 0x140b) {
            return;
          }
          filter1D = (code *)PTR__gleHalfFloatFilter1_00111578;
          filter2D = (code *)PTR__gleHalfFloatFilter2_00111574;
          filter3D = (code *)PTR__gleHalfFloatFilter3_00111570;
          goto LAB_000faa54;
        }
        filter1D = (code *)PTR__gleUintFilter1_0011159c;
        filter2D = (code *)PTR__gleUintFilter2_00111598;
        filter3D = (code *)PTR__gleUintFilter3_00111594;
      }
    }
    bytesPerPixel = levelRecordThenComponentCount << 2;
    goto LAB_000facc8;
  }
  bVar35 = (uVar28 < 0x8365) << 3 | (0x8365 < uVar28) << 2 | (uVar28 == 0x8365) << 1 | in_xer_so & 1
  ;
  if (uVar28 == 0x8365) {
LAB_000faac0:
    filter1D = (code *)PTR__gle4444Filter1_00111548;
    filter2D = (code *)PTR__gle4444Filter2_00111544;
    filter3D = (code *)PTR__gle4444Filter3_00111540;
LAB_000fac40:
    bytesPerPixel = 2;
  }
  else {
    if (0x8365 < uVar28) {
      if (uVar28 < 0x85bc) {
        if (0x85b9 < uVar28) {
          format = *(ushort *)(sourceImage + 0x10);
          bVar35 = (format < 0x85b9) << 3 | (0x85b9 < format) << 2 | (format == 0x85b9) << 1 |
                   in_xer_so & 1;
          if (format == 0x85b9) {
            pixelPairShift = 1;
            filter1D = (code *)PTR__gle8888Filter1_001115d8;
            bytesPerPixel = 4;
            goto LAB_000facc8;
          }
          filter1D = (code *)PTR__gle88Filter1_00111524;
          filter2D = (code *)PTR__gle88Filter2_00111520;
          filter3D = (code *)PTR__gle88Filter3_0011151c;
          goto LAB_000fac40;
        }
        bVar35 = (uVar28 < 0x8367) << 3 | (0x8367 < uVar28) << 2 | (uVar28 == 0x8367) << 1 |
                 in_xer_so & 1;
        if (uVar28 == 0x8367) {
LAB_000fab84:
          filter1D = (code *)PTR__gle8888Filter1_001115d8;
        }
        else {
          if (uVar28 < 0x8367) {
            filter1D = (code *)PTR__gle1555RevFilter1_00111530;
            filter2D = (code *)PTR__gle1555RevFilter2_0011152c;
            filter3D = (code *)PTR__gle1555RevFilter3_00111528;
            goto LAB_000fac40;
          }
          bVar35 = (uVar28 < 0x8368) << 3 | (0x8368 < uVar28) << 2 | (uVar28 == 0x8368) << 1 |
                   in_xer_so & 1;
          if (uVar28 != 0x8368) {
            return;
          }
          filter1D = (code *)PTR__gle2101010RevFilter1_0011150c;
          filter2D = (code *)PTR__gle2101010RevFilter2_00111508;
          filter3D = (code *)PTR__gle2101010RevFilter3_00111504;
        }
      }
      else {
        bVar35 = (uVar28 < 0x86da) << 3 | (0x86da < uVar28) << 2 | (uVar28 == 0x86da) << 1 |
                 in_xer_so & 1;
        if (uVar28 == 0x86da) {
          filter1D = (code *)PTR__gles8s888Filter1_001114f4;
          filter2D = (code *)PTR__gles8s888Filter2_001114f0;
          filter3D = (code *)PTR__gles8s888Filter3_001114ec;
        }
        else {
          bVar35 = (uVar28 < 0x86db) << 3 | (0x86db < uVar28) << 2 | (uVar28 == 0x86db) << 1 |
                   in_xer_so & 1;
          if (uVar28 != 0x86db) {
            return;
          }
          filter1D = (code *)PTR__gle88s8s8Filter1_00111500;
          filter2D = (code *)PTR__gle88s8s8Filter2_001114fc;
          filter3D = (code *)PTR__gle88s8s8Filter3_001114f8;
        }
      }
    }
    else {
      bVar35 = (uVar28 < 0x8036) << 3 | (0x8036 < uVar28) << 2 | (uVar28 == 0x8036) << 1 |
               in_xer_so & 1;
      if (uVar28 != 0x8036) {
        if (0x8036 < uVar28) {
          bVar35 = (uVar28 < 0x8362) << 3 | (0x8362 < uVar28) << 2 | (uVar28 == 0x8362) << 1 |
                   in_xer_so & 1;
          if (uVar28 == 0x8362) {
            filter1D = (code *)PTR__gle233RevFilter1_00111560;
            filter2D = (code *)PTR__gle233RevFilter2_0011155c;
            filter3D = (code *)PTR__gle233RevFilter3_00111558;
            goto LAB_000faa98;
          }
          if (uVar28 < 0x8362) {
            return;
          }
          filter1D = (code *)PTR__gle565Filter1_00111554;
          filter2D = (code *)PTR__gle565Filter2_00111550;
          filter3D = (code *)PTR__gle565Filter3_0011154c;
        }
        else {
          bVar35 = (uVar28 < 0x8034) << 3 | (0x8034 < uVar28) << 2 | (uVar28 == 0x8034) << 1 |
                   in_xer_so & 1;
          if (uVar28 != 0x8034) {
            if (0x8034 < uVar28) goto LAB_000fab84;
            goto LAB_000faac0;
          }
          filter1D = (code *)PTR__gle5551Filter1_0011153c;
          filter2D = (code *)PTR__gle5551Filter2_00111538;
          filter3D = (code *)PTR__gle5551Filter3_00111534;
        }
        goto LAB_000fac40;
      }
      filter1D = (code *)PTR__gle1010102Filter1_00111518;
      filter2D = (code *)PTR__gle1010102Filter2_00111514;
      filter3D = (code *)PTR__gle1010102Filter3_00111510;
    }
LAB_000facc4:
    bytesPerPixel = 4;
  }
LAB_000facc8:
  uVar28 = (uint)*(byte *)(sourceImage + 10);
  moreThanOneDimension = 1 < dimensions;
  isOneDimensional = dimensions == 1;
  bVar33 = (dimensions < 1) << 3 | moreThanOneDimension << 2 | isOneDimensional << 1 | in_xer_so & 1;
  twiceBorder = uVar28 * 2;
  srcThenDestInteriorHeight = (uint)*(ushort *)(sourceImage + 6);
  srcThenDestInteriorWidth = (int)((uint)*(ushort *)(sourceImage + 4) + uVar28 * -2) >> (pixelPairShift & 0x3f);
  if (moreThanOneDimension) {
    srcThenDestInteriorHeight = srcThenDestInteriorHeight + uVar28 * -2;
  }
  isThreeDimensional = 2 < dimensions;
  isTwoDimensional = dimensions == 2;
  bVar34 = (dimensions < 2) << 3 | isThreeDimensional << 2 | isTwoDimensional << 1 | in_xer_so & 1;
  srcThenDestInteriorDepth = (uint)*(ushort *)(sourceImage + 8);
  if (isThreeDimensional) {
    srcThenDestInteriorDepth = srcThenDestInteriorDepth + uVar28 * -2;
  }
  local_74 = bytesPerPixel << 1;
  nextLevel = sourceLevel + 1;
  bVar32 = (uVar28 != 0) << 2 | (uVar28 == 0) << 1 | in_xer_so & 1;
  local_7c = (uint)bVar32 << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar33 << 0x14 |
             (uint)bVar34 << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
             (uint)(in_cr6 & 0xf) << 4 | (uint)(bVar35 & 0xf);
  local_70 = (uint)bVar32 << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar33 << 0x14 |
             (uint)bVar34 << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
             (uint)(in_cr6 & 0xf) << 4 | (uint)(bVar35 & 0xf);
  borderCopy = twiceBorder >> 1;
  iVar23 = sourceImage;
  firstGeneratedLevel = nextLevel;
  local_78 = local_7c;
  local_6c = local_74;
  local_68 = local_74;
  local_64 = local_74;
  local_5c = local_74;
  do {
    if ((((srcThenDestInteriorWidth < 2) && ((int)srcThenDestInteriorHeight < 2)) && ((int)srcThenDestInteriorDepth < 2)) ||
       (iStack00000028 < nextLevel)) {
      if (originalCompressedData != 0) {
        format = *(ushort *)(sourceImage + 0x10);
        iStack00000028 = nextLevel;
        if (((0x83f3 < format) || (0x83f1 < format)) || (blockBytes = 8, format < 0x83f0)) {
          blockBytes = 0x10;
        }
        levelsToRecompress = firstGeneratedLevel;
        _free(*(undefined4 *)(sourceImage + 0x14));
        *(int *)(sourceImage + 0x14) = originalCompressedData;
        if (levelsToRecompress < iStack00000028) {
          iVar23 = levelsToRecompress * 0x18 + iStack0000001c + faceOffset + 0xc4;
          levelsToRecompress = iStack00000028 - levelsToRecompress;
          pixelTransferState = iStack00000018 + 0x31a8;
          savedGlContext = iStack00000018;
          do {
            decodedLevelData = *(undefined4 *)(iVar23 + 0x14);
            compressedBuffer = _malloc(blockBytes * ((int)(*(ushort *)(iVar23 + 4) + 3) >> 2) *
                             ((int)(*(ushort *)(iVar23 + 6) + 3) >> 2));
            *(undefined4 *)(iVar23 + 0x14) = compressedBuffer;
            rgbaRowBytes = _gleRowBytes(0x1908,0x8035,(uint)*(ushort *)(iVar23 + 4));
            compressedRowBytes = _gleRowBytes((uint)*(ushort *)(iVar23 + 0x10),0,(uint)*(ushort *)(iVar23 + 0xc)
                                 );
            _glgConvertType(0x1908,0x8035,auStack_138,auStack_134,lastLevelThenLevelArg,incomingR8,savedGlContext,incomingR10);
            puVar13 = auStack_128;
            puVar14 = auStack_124;
            _glgConvertType((uint)*(ushort *)(iVar23 + 0x10),0,auStack_128,auStack_124,lastLevelThenLevelArg,incomingR8
                            ,savedGlContext,incomingR10);
            local_11c = 0;
            local_120 = 2;
            local_118 = 0;
            local_114 = (uint)*(ushort *)(iVar23 + 4);
            local_110 = (uint)*(ushort *)(iVar23 + 6);
            local_140 = decodedLevelData;
            local_130 = *(undefined4 *)(iVar23 + 0x14);
            iVar23 = iVar23 + 0x18;
            local_d4 = 0;
            local_13c = rgbaRowBytes;
            local_12c = compressedRowBytes;
            _glgProcessPixels(pixelTransferState,&local_140,puVar13,puVar14,lastLevelThenLevelArg,incomingR8,savedGlContext,incomingR10);
            _free(decodedLevelData);
            levelsToRecompress = levelsToRecompress + -1;
          } while (levelsToRecompress != 0);
        }
      }
      return;
    }
    destLevelRecord = iStack0000001c + faceOffset + nextLevel * 0x18;
    pixelStep = bytesPerPixel;
    if (srcThenDestInteriorWidth == 1) {
      pixelStep = 0;
    }
    iVar26 = (int)(uint)*(ushort *)(iVar23 + 0xc) >> (pixelPairShift & 0x3f);
    rowBytes = iVar26 * bytesPerPixel;
    rowPadBytes = (iVar26 - (srcThenDestInteriorWidth + twiceBorder)) * bytesPerPixel;
    iVar26 = 0;
    if (srcThenDestInteriorHeight != 1) {
      iVar26 = rowBytes;
    }
    sliceBytes = (uint)*(ushort *)(iVar23 + 0xe) * rowBytes;
    iVar16 = ((uint)*(ushort *)(iVar23 + 0xe) - (srcThenDestInteriorHeight + twiceBorder)) * rowBytes;
    iVar27 = 0;
    if (srcThenDestInteriorDepth != 1) {
      iVar27 = sliceBytes;
    }
    srcThenDestInteriorHeight = (uint)*(ushort *)(destLevelRecord + 0xca);
    srcThenDestInteriorWidth = (int)((uint)*(ushort *)(destLevelRecord + 200) - twiceBorder) >> (pixelPairShift & 0x3f);
    if (moreThanOneDimension) {
      srcThenDestInteriorHeight = srcThenDestInteriorHeight - twiceBorder;
    }
    uVar28 = (uint)*(ushort *)(destLevelRecord + 0xcc);
    srcThenDestInteriorDepth = uVar28;
    if (isThreeDimensional) {
      srcThenDestInteriorDepth = uVar28 - twiceBorder;
    }
    iVar10 = _malloc((uint)*(ushort *)(destLevelRecord + 0xd0) * (uint)*(ushort *)(destLevelRecord + 0xd2) * uVar28 *
                     (bytesPerPixel >> (pixelPairShift & 0x3f)));
    *(int *)(destLevelRecord + 0xd8) = iVar10;
    iVar23 = *(int *)(iVar23 + 0x14);
    *(byte *)(destLevelRecord + 0xcf) = *(byte *)(destLevelRecord + 0xcf) | 0x10;
    if (isTwoDimensional) {
      bVar35 = (byte)(local_78 >> 0x18);
      if (!(bool)(bVar35 >> 5 & 1)) {
        iVar16 = iVar10 + bytesPerPixel;
        iVar27 = iVar23 + bytesPerPixel;
        (*filter2D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        if (0 < srcThenDestInteriorWidth) {
          iVar23 = iVar27;
          columnsRemaining3 = srcThenDestInteriorWidth;
          iVar10 = iVar16;
          do {
            iVar16 = iVar10 + bytesPerPixel;
            iVar27 = iVar23 + bytesPerPixel + pixelStep;
            (*filter2D)(iVar10,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes);
            columnsRemaining3 = columnsRemaining3 + -1;
            iVar23 = iVar27;
            iVar10 = iVar16;
          } while (columnsRemaining3 != 0);
        }
        iVar10 = iVar16 + bytesPerPixel;
        (*filter2D)(iVar16,iVar27 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        iVar23 = (iVar27 - bytesPerPixel) + bytesPerPixel * 2 + rowPadBytes;
      }
      iVar27 = local_74;
      if (0 < (int)srcThenDestInteriorHeight) {
        iVar16 = rowPadBytes + iVar26;
        uVar28 = srcThenDestInteriorHeight;
        do {
          iVar17 = iVar23;
          iVar24 = iVar10;
          if (!(bool)(bVar35 >> 5 & 1)) {
            iVar24 = iVar10 + bytesPerPixel;
            iVar17 = iVar23 + bytesPerPixel;
            (*filter2D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,iVar26);
          }
          iVar23 = iVar17;
          iVar10 = srcThenDestInteriorWidth;
          iVar29 = iVar24;
          if (0 < srcThenDestInteriorWidth) {
            do {
              iVar24 = iVar29 + bytesPerPixel;
              iVar17 = iVar23 + bytesPerPixel + pixelStep;
              (*filter2D)(iVar29,iVar23,levelRecordThenComponentCount,pixelStep,iVar26);
              iVar10 = iVar10 + -1;
              iVar23 = iVar17;
              iVar29 = iVar24;
            } while (iVar10 != 0);
          }
          iVar10 = iVar24;
          if (!(bool)(bVar35 >> 5 & 1)) {
            iVar23 = iVar17 - bytesPerPixel;
            iVar10 = iVar24 + bytesPerPixel;
            iVar17 = iVar23 + iVar27;
            (*filter2D)(iVar24,iVar23,levelRecordThenComponentCount,bytesPerPixel,iVar26);
          }
          uVar28 = uVar28 - 1;
          iVar23 = iVar17 + iVar16;
        } while (uVar28 != 0);
      }
      if (!(bool)(bVar35 >> 5 & 1)) {
        iVar27 = iVar10 + bytesPerPixel;
        iVar26 = (iVar23 - rowBytes) + bytesPerPixel;
        (*filter2D)(iVar10,iVar23 - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        if (0 < srcThenDestInteriorWidth) {
          iVar23 = iVar26;
          iVar16 = srcThenDestInteriorWidth;
          dstCursor3 = iVar27;
          do {
            iVar27 = dstCursor3 + bytesPerPixel;
            iVar26 = iVar23 + bytesPerPixel + pixelStep;
            (*filter2D)(dstCursor3,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes);
            iVar16 = iVar16 + -1;
            iVar23 = iVar26;
            dstCursor3 = iVar27;
          } while (iVar16 != 0);
        }
        (*filter2D)(iVar27,iVar26 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
      }
      destWidth = *(ushort *)(destLevelRecord + 200);
      incomingR10 = 0;
      uVar28 = 1;
      uVar6 = *(ushort *)(destLevelRecord + 0xca);
LAB_000fb8d8:
      destHeight = (uint)uVar6;
      incomingR8 = borderCopy;
      iVar23 = borderCopy;
LAB_000fb8dc:
      lastLevelThenLevelArg = nextLevel;
      _gleModifyPluginTextureLevel
                (iStack00000018,iStack0000001c,destLevelRecord + 0xc4,iStack00000020,nextLevel,incomingR8,iVar23,
                 incomingR10,(uint)destWidth,destHeight,uVar28);
    }
    else if (isThreeDimensional) {
      if (dimensions == 3) {
        bVar35 = (byte)(local_70 >> 0x18);
        if (!(bool)(bVar35 >> 5 & 1)) {
          iVar29 = iVar10 + bytesPerPixel;
          iVar24 = iVar23 + bytesPerPixel;
          (*filter3D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            iVar23 = iVar24;
            iVar10 = srcThenDestInteriorWidth;
            iVar31 = iVar29;
            do {
              iVar29 = iVar31 + bytesPerPixel;
              iVar24 = iVar23 + bytesPerPixel + pixelStep;
              (*filter3D)(iVar31,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              iVar10 = iVar10 + -1;
              iVar23 = iVar24;
              iVar31 = iVar29;
            } while (iVar10 != 0);
          }
          local_9c = local_6c;
          iVar10 = iVar29 + bytesPerPixel;
          iVar23 = (iVar24 - bytesPerPixel) + local_6c;
          (*filter3D)(iVar29,iVar24 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          iVar23 = iVar23 + rowPadBytes;
          if (0 < (int)srcThenDestInteriorHeight) {
            local_80 = bytesPerPixel + pixelStep;
            iVar24 = rowPadBytes + iVar26;
            uVar28 = srcThenDestInteriorHeight;
            do {
              iVar30 = iVar10 + bytesPerPixel;
              iVar25 = iVar23 + bytesPerPixel;
              (*filter3D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,iVar26,sliceBytes);
              iVar23 = local_80;
              iVar10 = iVar25;
              iVar29 = srcThenDestInteriorWidth;
              iVar31 = iVar30;
              if (0 < srcThenDestInteriorWidth) {
                do {
                  iVar30 = iVar31 + bytesPerPixel;
                  iVar25 = iVar10 + iVar23;
                  (*filter3D)(iVar31,iVar10,levelRecordThenComponentCount,pixelStep,iVar26,sliceBytes);
                  iVar29 = iVar29 + -1;
                  iVar10 = iVar25;
                  iVar31 = iVar30;
                } while (iVar29 != 0);
              }
              iVar10 = iVar30 + bytesPerPixel;
              iVar23 = (iVar25 - bytesPerPixel) + local_9c;
              (*filter3D)(iVar30,iVar25 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,iVar26,sliceBytes);
              uVar28 = uVar28 - 1;
              iVar23 = iVar23 + iVar24;
            } while (uVar28 != 0);
          }
          iVar29 = iVar10 + bytesPerPixel;
          iVar24 = (iVar23 - rowBytes) + bytesPerPixel;
          (*filter3D)(iVar10,iVar23 - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            iVar23 = iVar24;
            iVar10 = srcThenDestInteriorWidth;
            iVar31 = iVar29;
            do {
              iVar29 = iVar31 + bytesPerPixel;
              iVar24 = iVar23 + bytesPerPixel + pixelStep;
              (*filter3D)(iVar31,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              iVar10 = iVar10 + -1;
              iVar23 = iVar24;
              iVar31 = iVar29;
            } while (iVar10 != 0);
          }
          iVar10 = iVar29 + bytesPerPixel;
          iVar23 = (iVar24 - bytesPerPixel) + local_9c;
          (*filter3D)(iVar29,iVar24 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          iVar23 = iVar23 + rowPadBytes + rowBytes + iVar16;
        }
        if (0 < (int)srcThenDestInteriorDepth) {
          local_90 = iVar16 + iVar27;
          local_88 = rowPadBytes + iVar26;
          slicesRemaining = srcThenDestInteriorDepth;
          local_60 = bytesPerPixel + pixelStep;
          local_98 = local_68;
          local_84 = local_5c;
          do {
            if (!(bool)(bVar35 >> 5 & 1)) {
              iVar24 = iVar10 + bytesPerPixel;
              iVar16 = iVar23 + bytesPerPixel;
              (*filter3D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,rowBytes,iVar27);
              if (0 < srcThenDestInteriorWidth) {
                iVar23 = iVar16;
                iVar10 = srcThenDestInteriorWidth;
                iVar29 = iVar24;
                do {
                  iVar24 = iVar29 + bytesPerPixel;
                  iVar16 = iVar23 + bytesPerPixel + pixelStep;
                  (*filter3D)(iVar29,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes,iVar27);
                  iVar10 = iVar10 + -1;
                  iVar23 = iVar16;
                  iVar29 = iVar24;
                } while (iVar10 != 0);
              }
              iVar10 = iVar24 + bytesPerPixel;
              iVar23 = (iVar16 - bytesPerPixel) + local_98 + rowPadBytes;
              (*filter3D)(iVar24,iVar16 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,iVar27);
            }
            iVar24 = local_60;
            iVar16 = local_88;
            if (0 < (int)srcThenDestInteriorHeight) {
              local_94 = local_84;
              uVar28 = srcThenDestInteriorHeight;
              do {
                iVar29 = iVar23;
                iVar31 = iVar10;
                if (!(bool)(bVar35 >> 5 & 1)) {
                  iVar31 = iVar10 + bytesPerPixel;
                  iVar29 = iVar23 + bytesPerPixel;
                  (*filter3D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel,iVar26,iVar27);
                }
                iVar23 = iVar29;
                iVar10 = srcThenDestInteriorWidth;
                iVar25 = iVar31;
                if (0 < srcThenDestInteriorWidth) {
                  do {
                    iVar31 = iVar25 + bytesPerPixel;
                    iVar29 = iVar23 + iVar24;
                    (*filter3D)(iVar25,iVar23,levelRecordThenComponentCount,pixelStep,iVar26,iVar27);
                    iVar10 = iVar10 + -1;
                    iVar23 = iVar29;
                    iVar25 = iVar31;
                  } while (iVar10 != 0);
                }
                iVar10 = iVar31;
                if (!(bool)(bVar35 >> 5 & 1)) {
                  iVar23 = iVar29 - bytesPerPixel;
                  iVar10 = iVar31 + bytesPerPixel;
                  iVar29 = iVar23 + local_94;
                  (*filter3D)(iVar31,iVar23,levelRecordThenComponentCount,bytesPerPixel,iVar26,iVar27);
                }
                uVar28 = uVar28 - 1;
                iVar23 = iVar29 + iVar16;
              } while (uVar28 != 0);
            }
            if (!(bool)(bVar35 >> 5 & 1)) {
              iVar24 = iVar10 + bytesPerPixel;
              iVar16 = (iVar23 - rowBytes) + bytesPerPixel;
              (*filter3D)(iVar10,iVar23 - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,iVar27);
              if (0 < srcThenDestInteriorWidth) {
                iVar23 = iVar16;
                iVar10 = srcThenDestInteriorWidth;
                iVar29 = iVar24;
                do {
                  iVar24 = iVar29 + bytesPerPixel;
                  iVar16 = iVar23 + bytesPerPixel + pixelStep;
                  (*filter3D)(iVar29,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes,iVar27);
                  iVar10 = iVar10 + -1;
                  iVar23 = iVar16;
                  iVar29 = iVar24;
                } while (iVar10 != 0);
              }
              iVar10 = iVar24 + bytesPerPixel;
              iVar23 = (iVar16 - bytesPerPixel) + local_98;
              (*filter3D)(iVar24,iVar16 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,iVar27);
              iVar23 = iVar23 + rowPadBytes + rowBytes;
            }
            slicesRemaining = slicesRemaining - 1;
            iVar23 = iVar23 + local_90;
          } while (slicesRemaining != 0);
        }
        if (!(bool)(bVar35 >> 5 & 1)) {
          iVar16 = iVar10 + bytesPerPixel;
          iVar27 = (iVar23 - sliceBytes) + bytesPerPixel;
          (*filter3D)(iVar10,iVar23 - sliceBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            iVar23 = iVar27;
            iVar10 = srcThenDestInteriorWidth;
            iVar24 = iVar16;
            do {
              iVar16 = iVar24 + bytesPerPixel;
              iVar27 = iVar23 + bytesPerPixel + pixelStep;
              (*filter3D)(iVar24,iVar23,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              iVar10 = iVar10 + -1;
              iVar23 = iVar27;
              iVar24 = iVar16;
            } while (iVar10 != 0);
          }
          iVar23 = local_64;
          iVar24 = iVar16 + bytesPerPixel;
          iVar10 = (iVar27 - bytesPerPixel) + local_64;
          (*filter3D)(iVar16,iVar27 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          iVar10 = iVar10 + rowPadBytes;
          if (0 < (int)srcThenDestInteriorHeight) {
            iVar27 = rowPadBytes + iVar26;
            uVar28 = srcThenDestInteriorHeight;
            do {
              iVar31 = iVar24 + bytesPerPixel;
              iVar29 = iVar10 + bytesPerPixel;
              (*filter3D)(iVar24,iVar10,levelRecordThenComponentCount,bytesPerPixel,iVar26,sliceBytes);
              iVar16 = iVar29;
              iVar10 = srcThenDestInteriorWidth;
              iVar24 = iVar31;
              if (0 < srcThenDestInteriorWidth) {
                do {
                  iVar31 = iVar24 + bytesPerPixel;
                  iVar29 = iVar16 + bytesPerPixel + pixelStep;
                  (*filter3D)(iVar24,iVar16,levelRecordThenComponentCount,pixelStep,iVar26,sliceBytes);
                  iVar10 = iVar10 + -1;
                  iVar16 = iVar29;
                  iVar24 = iVar31;
                } while (iVar10 != 0);
              }
              iVar24 = iVar31 + bytesPerPixel;
              iVar10 = (iVar29 - bytesPerPixel) + iVar23 + iVar27;
              (*filter3D)(iVar31,iVar29 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,iVar26,sliceBytes);
              uVar28 = uVar28 - 1;
            } while (uVar28 != 0);
          }
          iVar26 = iVar24 + bytesPerPixel;
          iVar23 = (iVar10 - rowBytes) + bytesPerPixel;
          (*filter3D)(iVar24,iVar10 - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            iVar27 = iVar23;
            iVar16 = srcThenDestInteriorWidth;
            iVar10 = iVar26;
            do {
              iVar26 = iVar10 + bytesPerPixel;
              iVar23 = iVar27 + bytesPerPixel + pixelStep;
              (*filter3D)(iVar10,iVar27,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              iVar16 = iVar16 + -1;
              iVar27 = iVar23;
              iVar10 = iVar26;
            } while (iVar16 != 0);
          }
          (*filter3D)(iVar26,iVar23 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
        }
        destWidth = *(ushort *)(destLevelRecord + 200);
        uVar6 = *(ushort *)(destLevelRecord + 0xca);
        uVar28 = (uint)*(ushort *)(destLevelRecord + 0xcc);
        incomingR10 = borderCopy;
        goto LAB_000fb8d8;
      }
    }
    else if (isOneDimensional) {
      bVar35 = (byte)(local_7c >> 0x18);
      iVar26 = iVar23;
      dstCursor4 = iVar10;
      if (!(bool)(bVar35 >> 5 & 1)) {
        dstCursor4 = iVar10 + bytesPerPixel;
        iVar26 = iVar23 + bytesPerPixel;
        (*filter1D)(iVar10,iVar23,levelRecordThenComponentCount,bytesPerPixel);
      }
      if (0 < srcThenDestInteriorWidth) {
        iVar23 = iVar26;
        iVar27 = srcThenDestInteriorWidth;
        iVar16 = dstCursor4;
        do {
          dstCursor4 = iVar16 + bytesPerPixel;
          iVar26 = iVar23 + bytesPerPixel + pixelStep;
          (*filter1D)(iVar16,iVar23,levelRecordThenComponentCount,pixelStep);
          iVar27 = iVar27 + -1;
          iVar23 = iVar26;
          iVar16 = dstCursor4;
        } while (iVar27 != 0);
      }
      if (!(bool)(bVar35 >> 5 & 1)) {
        (*filter1D)(dstCursor4,iVar26 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel);
      }
      destWidth = *(ushort *)(destLevelRecord + 200);
      incomingR10 = 0;
      uVar28 = 1;
      destHeight = 1;
      incomingR8 = twiceBorder >> 1;
      iVar23 = 0;
      goto LAB_000fb8dc;
    }
    nextLevel = nextLevel + 1;
    iVar23 = destLevelRecord + 0xc4;
  } while( true );
}

/* _gleGenerateEmptyMipmaps @ 0xfbb00 (868 bytes) */
int _gleGenerateEmptyMipmaps(glContext, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 glContext;
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
        return glContext;
      }
    }
    else if (uVar4 != 3) {
      if (uVar4 != 4) {
        return glContext;
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
      _gleDeletePluginTextureLevel(glContext,param_2,iVar10,param_3,iVar11);
      if (*(int *)(iVar10 + 0x14) != 0) {
        bVar1 = *(byte *)(iVar10 + 0xb);
        if ((bVar1 & 1) == 0) {
          _gleFreeTextureLevel(glContext,param_2,iVar10);
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
    uVar8 = _gleCreatePluginTextureLevel(glContext,param_2,iVar10,param_3,iVar11,uVar7);
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
        uVar8 = _gleDeletePluginTextureLevel(glContext,param_2,iVar16,param_3,iVar11);
        if (*(int *)(iVar16 + 0x14) != 0) {
          bVar1 = *(byte *)(iVar16 + 0xb);
          if ((bVar1 & 1) == 0) {
            uVar8 = _gleFreeTextureLevel(glContext,param_2,iVar16);
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
int _gleGenMipmapsToLevel(glContext, param_2, param_3, level, param_5, param_6)
  int glContext;
  int param_2;
  int param_3;
  int level;
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
    iVar1 = param_2 + iVar5 + level * 0x18;
    ((int (*)())_gleGenerateEmptyMipmaps)(glContext,param_2,param_3,level,param_5,0,0);
    if ((*(byte *)(iVar5 + level * 0x18 + param_2 + 0xcf) & 0x20) == 0) {
      return 0;
    }
    iVar3 = (**(code **)(glContext + 0x4714))
                      (*(undefined4 *)(glContext + 0x4688),
                       *(undefined4 *)(param_2 + (uint)*(byte *)(glContext + 0x85a8) * 4),param_3);
    if (iVar3 != 0) {
      *(undefined4 *)(param_2 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (param_6 == 0) {
        uVar4 = (uint)*(short *)(param_2 + 0x62);
      }
      else {
        uVar4 = (uint)*(byte *)(param_2 + 0x87);
      }
      if (0xf < (int)uVar4) {
        uVar4 = 0xf;
      }
      iVar1 = level + 1;
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
        _gleAllocateTextureLevel(glContext,param_2,iVar1 + 0xc4);
      }
      _gleSynchronizePluginTextureLevels(glContext,param_2);
      ((void (*)())_gleGenerateMipmapData)(glContext,param_2,param_3,level,param_5);
    }
  }
  return 0;
}

/* _gleGenSurfaceMipmaps @ 0xfbfe4 (160 bytes) */
int _gleGenSurfaceMipmaps(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(ushort *)(param_2 + 0x24) & 0xf) != 2) {
    ((int (*)())_gleGenerateEmptyMipmaps)(glContext,param_2,param_3,0,param_4,0,0x12);
    uVar1 = 0;
    if (*(int *)(param_2 + 0x2c) != 0) {
      if (param_5 != 0) {
        (**(code **)(glContext + 0x4714))
                  (*(undefined4 *)(glContext + 0x4688),
                   *(undefined4 *)(param_2 + (uint)*(byte *)(glContext + 0x85a8) * 4),param_3);
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
int _gleLookUpTexture1D(glContext, target)
  int glContext;
  int target;
{
  if (target == 0xde0) {
    return *(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5164) + 0x10;
  }
  if (target != 0x8063) {
    return 0;
  }
  return *(int *)(glContext + 0x52b8) + 0x10;
}

/* _gleLookUpNonProxyTexture1D @ 0xfc154 (40 bytes) */
int _gleLookUpNonProxyTexture1D(glContext, target)
  int glContext;
  int target;
{
  if (target != 0xde0) {
    return 0;
  }
  return *(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5164) + 0x10;
}

/* _gleLookUpNonProxyTexture3D @ 0xfc17c (48 bytes) */
int _gleLookUpNonProxyTexture3D(glContext, target)
  int glContext;
  int target;
{
  if (target != 0x806f) {
    return 0;
  }
  return *(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5158) + 0x10;
}

/* _gleLookUpColorTable @ 0xfc1ac (544 bytes) */
int _gleLookUpColorTable(glContext, target)
  int glContext;
  uint target;
{
  int iVar1;
  
  iVar1 = *(int *)(glContext + 0x53d4);
  if (target == 0x80d2) {
    iVar1 = *(int *)(glContext + 0x52c4);
    goto LAB_000fc364;
  }
  if (target < 0x80d3) {
    if (target == 0x8064) {
      iVar1 = *(int *)(glContext + 0x52b4);
    }
    else {
      if (target < 0x8065) {
        if (target != 0xde1) {
          if (target < 0xde2) {
            if (target == 0xde0) {
              iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5164);
              goto LAB_000fc320;
            }
          }
          else if (target == 0x8063) {
            iVar1 = *(int *)(glContext + 0x52b8);
            goto LAB_000fc364;
          }
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5160);
        goto LAB_000fc320;
      }
      if (target == 0x8070) {
        iVar1 = *(int *)(glContext + 0x52ac);
      }
      else {
        if (target < 0x8071) {
          if (target != 0x806f) {
            return 0;
          }
          iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5158);
          goto LAB_000fc320;
        }
        if (target == 0x80d0) {
          iVar1 = *(int *)(glContext + 0x52bc);
        }
        else {
          if (target != 0x80d1) {
            return 0;
          }
          iVar1 = *(int *)(glContext + 0x52c0);
        }
      }
    }
LAB_000fc364:
    return iVar1 + 0x10;
  }
  if (target != 0x84f5) {
    if (target < 0x84f6) {
      if (target == 0x80d4) {
        iVar1 = *(int *)(glContext + 0x52cc);
      }
      else if (target < 0x80d4) {
        iVar1 = *(int *)(glContext + 0x52c8);
      }
      else {
        if (target != 0x80d5) {
          if (target != 0x81fb) {
            return 0;
          }
          iVar1 = *(int *)(iVar1 * 4 + glContext + 0x52d4);
          goto LAB_000fc320;
        }
        iVar1 = *(int *)(glContext + 0x52d0);
      }
      goto LAB_000fc364;
    }
    if (target == 0x8513) {
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5154);
      goto LAB_000fc320;
    }
    if (target < 0x8514) {
      if (target != 0x84f7) {
        return 0;
      }
      iVar1 = *(int *)(glContext + 0x52b0);
      goto LAB_000fc364;
    }
    if (target == 0x851b) {
      iVar1 = *(int *)(glContext + 0x52a8);
      goto LAB_000fc364;
    }
    if (target != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x515c);
LAB_000fc320:
  return iVar1 + 0x10;
}

/* _gleLookUpNonProxyColorTable @ 0xfc3cc (324 bytes) */
int _gleLookUpNonProxyColorTable(glContext, target)
  int glContext;
  uint target;
{
  int iVar1;
  
  iVar1 = *(int *)(glContext + 0x53d4);
  if (target == 0x80d1) {
    iVar1 = *(int *)(glContext + 0x52c0);
LAB_000fc4f8:
    return iVar1 + 0x10;
  }
  if (target < 0x80d2) {
    if (target == 0xde1) {
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5160);
    }
    else if (target < 0xde2) {
      if (target != 0xde0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5164);
    }
    else {
      if (target != 0x806f) {
        if (target != 0x80d0) {
          return 0;
        }
        iVar1 = *(int *)(glContext + 0x52bc);
        goto LAB_000fc4f8;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5158);
    }
    goto LAB_000fc4a4;
  }
  if (target != 0x84f5) {
    if (target < 0x84f6) {
      if (target == 0x80d2) {
        iVar1 = *(int *)(glContext + 0x52c4);
        goto LAB_000fc4f8;
      }
      if (target != 0x81fb) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 4 + glContext + 0x52d4);
      goto LAB_000fc4a4;
    }
    if (target == 0x8513) {
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5154);
      goto LAB_000fc4a4;
    }
    if (target != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x515c);
LAB_000fc4a4:
  return iVar1 + 0x10;
}

/* _gleReclaimTextureObjectResources @ 0xfc510 (344 bytes) */
void _gleReclaimTextureObjectResources(glContext)
  int glContext;
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
  
  iVar3 = *(int *)(glContext + 0x5148);
  piVar8 = (int *)(iVar3 + 0x2008);
  do {
    piVar5 = piVar8 + 1;
    for (piVar8 = (int *)*piVar8; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
      if (((piVar8[2] == 1) && ((*(ushort *)(piVar8 + 0xd) & 0x3c00) != 0x800)) &&
         (uVar6 = 0, *(char *)(glContext + 0x85a4) != '\0')) {
        puVar9 = piVar8 + 4;
        iVar10 = glContext + 0x10000;
        do {
          piVar1 = (int *)(iVar10 + -0x777c);
          uVar6 = uVar6 + 1;
          uVar4 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar2 = (undefined4 *)(iVar10 + -0x7a54);
          iVar10 = iVar10 + 0x2e0;
          (**(code **)(*piVar1 + 0x170))(*puVar2,uVar4);
        } while (uVar6 < *(byte *)(glContext + 0x85a4));
      }
    }
    piVar8 = piVar5;
  } while (piVar5 <= (int *)(iVar3 + 0x3004));
  uVar6 = 0;
  piVar8 = (int *)(glContext + 0x5294);
  do {
    iVar3 = *piVar8;
    piVar8 = piVar8 + 1;
    if (((iVar3 != 0) && (*(int *)(iVar3 + 8) == 1)) &&
       (((*(ushort *)(iVar3 + 0x34) & 0x3c00) != 0x800 &&
        (uVar7 = 0, *(char *)(glContext + 0x85a4) != '\0')))) {
      puVar9 = (undefined4 *)(iVar3 + 0x10);
      iVar3 = glContext + 0x10000;
      do {
        piVar5 = (int *)(iVar3 + -0x777c);
        uVar7 = uVar7 + 1;
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar2 = (undefined4 *)(iVar3 + -0x7a54);
        iVar3 = iVar3 + 0x2e0;
        (**(code **)(*piVar5 + 0x170))(*puVar2,uVar4);
      } while (uVar7 < *(byte *)(glContext + 0x85a4));
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 5);
  return;
}

/* _gleCompressedTextureImagePut @ 0xfc668 (252 bytes) */
int _gleCompressedTextureImagePut(unusedArg1, param_2, param_3, param_4, unusedArg5, width, height, param_8, internalformat, unusedArg10, data)
  undefined4 unusedArg1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 unusedArg5;
  int width;
  int height;
  int param_8;
  uint internalformat;
  undefined4 unusedArg10;
  int data;
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
  
  if (((0x83f3 < internalformat) || (0x83f1 < internalformat)) || (iVar8 = 3, internalformat < 0x83f0)) {
    iVar8 = 4;
  }
  iVar7 = 0;
  uVar1 = *(ushort *)(param_2 + 4);
  uVar2 = *(ushort *)(param_2 + 6);
  iVar4 = param_4 >> 2;
  if (0 < param_8) {
    iVar6 = height + 3 >> 2;
    iVar5 = (width + 3 >> 2) << iVar8;
    do {
      iVar10 = 0;
      iVar9 = data;
      if (0 < iVar6) {
        do {
          iVar3 = iVar4 + iVar10;
          iVar10 = iVar10 + 1;
          data = iVar9 + iVar5;
          _memcpy(*(int *)(param_2 + 0x14) +
                  (iVar3 * ((int)(uVar1 + 3) >> 2) + (param_3 >> 2) << iVar8),iVar9,iVar5);
          iVar9 = data;
        } while (iVar10 < iVar6);
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + ((int)(uVar2 + 3) >> 2);
    } while (iVar7 < param_8);
  }
  return;
}

/* _gleTextureImagePut_FastByte @ 0xfc764 (6052 bytes) */
int _gleTextureImagePut_FastByte(unusedArg1, width, height, src, dst, srcRowStride, unusedArg7, dstRowSkip, dstRowStride, dstFormat, srcFormat)
  undefined4 unusedArg1;
  int width;
  int height;
  byte *src;
  byte *dst;
  int srcRowStride;
  undefined4 unusedArg7;
  int dstRowSkip;
  int dstRowStride;
  undefined4 dstFormat;
  int srcFormat;
{
  byte *srcComponent;
  byte srcValue;
  int dstComponentCount;
  int remaining;
  byte *srcCursor;
  byte *dstRowEnd;
  uint pixelsLeft;
  
  dstComponentCount = _gleComponents(dstFormat);
  dstRowEnd = dst + width * dstComponentCount;
  switch(dstFormat) {
  case 0x1900:
    if (srcFormat != 0x1900) {
      return 0;
    }
    if (0 < height) {
      do {
        if (dst < dstRowEnd) {
          remaining = (int)dstRowEnd - (int)dst;
          srcCursor = src;
          do {
            srcValue = *srcCursor;
            srcCursor = srcCursor + 1;
            *dst = srcValue << 1 | srcValue >> 6 & 1;
            dst = dst + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        height = height + -1;
        src = src + srcRowStride;
        dst = dst + dstRowSkip;
        dstRowEnd = dstRowEnd + dstRowStride;
      } while (height != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src + 3;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1907) {
        if (srcFormat < 0x1903) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src + 1;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 2;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src + 3;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1907:
    if (srcFormat == 0x1908) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = *src << 1 | *src >> 6 & 1;
            dst[1] = src[1] << 1 | src[1] >> 6 & 1;
            srcComponent = src + 2;
            src = src + 4;
            dst[2] = *srcComponent << 1 | *srcComponent >> 6 & 1;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              srcValue = *src;
              src = src + 1;
              dst[2] = srcValue << 1 | srcValue >> 6 & 1;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                srcValue = *src;
                src = src + 1;
                dst[1] = 0;
                dst[2] = 0;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
              }
              height = height + -1;
              src = srcCursor + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                *dst = 0;
                srcValue = *src;
                src = src + 1;
                dst[2] = 0;
                dst[1] = srcValue << 1 | srcValue >> 6 & 1;
              }
              height = height + -1;
              src = srcCursor + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              dst[2] = 0;
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = *src << 1 | *src >> 6 & 1;
              dst[1] = src[1] << 1 | src[1] >> 6 & 1;
              srcComponent = src + 2;
              src = src + 3;
              dst[2] = *srcComponent << 1 | *srcComponent >> 6 & 1;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            srcCursor = src + 1;
            do {
              *dst = srcCursor[2] << 1 | srcCursor[2] >> 6 & 1;
              dst[1] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[2] = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 3;
            } while (dst < dstRowEnd);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 1;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 2;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = src[2] << 1 | src[2] >> 6 & 1;
            dst[1] = src[1] << 1 | src[1] >> 6 & 1;
            srcValue = *src;
            src = src + 3;
            dst[2] = srcValue << 1 | srcValue >> 6 & 1;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = src[2] << 1 | src[2] >> 6 & 1;
            dst[1] = src[1] << 1 | src[1] >> 6 & 1;
            srcValue = *src;
            src = src + 4;
            dst[2] = srcValue << 1 | srcValue >> 6 & 1;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    break;
  case 0x1908:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = *srcCursor << 1 | *srcCursor >> 6 & 1;
              dst[1] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
              dst[2] = srcCursor[2] << 1 | srcCursor[2] >> 6 & 1;
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = *srcComponent << 1 | *srcComponent >> 6 & 1;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                dst[2] = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0;
                  dst[2] = 0;
                  *dst = srcValue << 1 | srcValue >> 6 & 1;
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  *dst = 0;
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[2] = 0;
                  dst[3] = 0xff;
                  dst[1] = srcValue << 1 | srcValue >> 6 & 1;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                dst[2] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = *srcCursor << 1 | *srcCursor >> 6 & 1;
                dst[1] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
                srcValue = srcCursor[2];
                srcCursor = srcCursor + 3;
                dst[3] = 0xff;
                dst[2] = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[3] << 1 | srcCursor[3] >> 6 & 1;
              dst[1] = srcCursor[2] << 1 | srcCursor[2] >> 6 & 1;
              dst[2] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[3] = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst[2] = *dst;
                dst[1] = *dst;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = *srcCursor << 1 | *srcCursor >> 6 & 1;
                dst[2] = *dst;
                dst[1] = *dst;
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[3] = *srcComponent << 1 | *srcComponent >> 6 & 1;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[2] << 1 | srcCursor[2] >> 6 & 1;
              dst[1] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              dst[3] = 0xff;
              dst[2] = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[2] << 1 | srcCursor[2] >> 6 & 1;
              dst[1] = srcCursor[1] << 1 | srcCursor[1] >> 6 & 1;
              dst[2] = *srcCursor << 1 | *srcCursor >> 6 & 1;
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = *srcComponent << 1 | *srcComponent >> 6 & 1;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1909:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1907) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                remaining = (int)dstRowEnd - (int)dst;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  *dst = srcValue << 1 | srcValue >> 6 & 1;
                  dst = dst + 1;
                  remaining = remaining + -1;
                } while (remaining != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src + 3;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 2;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src + 2;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src + 2;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x190a:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = *srcCursor << 1 | *srcCursor >> 6 & 1;
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = *srcComponent << 1 | *srcComponent >> 6 & 1;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1906) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0xff;
                  *dst = srcValue << 1 | srcValue >> 6 & 1;
                  dst = dst + 2;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              do {
                *dst = 0;
                dst[1] = 0xff;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 3;
                dst[1] = 0xff;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = srcCursor[3] << 1 | srcCursor[3] >> 6 & 1;
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[1] = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = 0xff;
                *dst = srcValue << 1 | srcValue >> 6 & 1;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = *srcCursor << 1 | *srcCursor >> 6 & 1;
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[1] = *srcComponent << 1 | *srcComponent >> 6 & 1;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            srcCursor = src + 2;
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              dst[1] = 0xff;
              *dst = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            srcCursor = src + 3;
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            do {
              *dst = srcCursor[-1] << 1 | srcCursor[-1] >> 6 & 1;
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[1] = srcValue << 1 | srcValue >> 6 & 1;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastShort @ 0xfdf34 (5476 bytes) */
int _gleTextureImagePut_FastShort(unusedArg1, width, height, src, dst, srcRowStride, unusedArg7, dstRowSkip, dstRowStride, dstFormat, srcFormat)
  undefined4 unusedArg1;
  int width;
  int height;
  ushort *src;
  undefined1 *dst;
  int srcRowStride;
  undefined4 unusedArg7;
  int dstRowSkip;
  int dstRowStride;
  undefined4 dstFormat;
  int srcFormat;
{
  ushort *srcComponent;
  ushort srcValue;
  ushort *srcCursor;
  int dstComponentCount;
  int remaining;
  undefined1 *dstRowEnd;
  uint pixelsLeft;
  
  dstComponentCount = _gleComponents(dstFormat);
  dstRowEnd = dst + width * dstComponentCount;
  switch(dstFormat) {
  case 0x1900:
    if (srcFormat != 0x1900) {
      return 0;
    }
    if (0 < height) {
      do {
        if (dst < dstRowEnd) {
          remaining = (int)dstRowEnd - (int)dst;
          srcCursor = src;
          do {
            srcValue = *srcCursor;
            srcCursor = srcCursor + 1;
            *dst = (char)(srcValue >> 7);
            dst = dst + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        height = height + -1;
        src = (ushort *)((int)src + srcRowStride);
        dst = dst + dstRowSkip;
        dstRowEnd = dstRowEnd + dstRowStride;
      } while (height != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)(srcValue >> 7);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1907) {
        if (srcFormat < 0x1903) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)(srcValue >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                *dst = (char)(*srcComponent >> 7);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1907:
    if (srcFormat == 0x1908) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(*src >> 7);
            dst[1] = (char)(src[1] >> 7);
            srcComponent = src + 2;
            src = src + 4;
            dst[2] = (char)(*srcComponent >> 7);
          }
          height = height + -1;
          src = (ushort *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              srcValue = *src;
              src = src + 1;
              dst[2] = (char)(srcValue >> 7);
            }
            height = height + -1;
            src = (ushort *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                srcValue = *src;
                src = src + 1;
                dst[1] = 0;
                dst[2] = 0;
                *dst = (char)(srcValue >> 7);
              }
              height = height + -1;
              src = (ushort *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                *dst = 0;
                srcValue = *src;
                src = src + 1;
                dst[2] = 0;
                dst[1] = (char)(srcValue >> 7);
              }
              height = height + -1;
              src = (ushort *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              dst[2] = 0;
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = (char)(*src >> 7);
              dst[1] = (char)(src[1] >> 7);
              srcComponent = src + 2;
              src = src + 3;
              dst[2] = (char)(*srcComponent >> 7);
            }
            height = height + -1;
            src = (ushort *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[3] >> 7);
            dst[1] = (char)(src[2] >> 7);
            srcComponent = src + 1;
            src = src + 4;
            dst[2] = (char)(*srcComponent >> 7);
          }
          height = height + -1;
          src = (ushort *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 1;
              *dst = (char)(srcValue >> 7);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (ushort *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 2;
              *dst = (char)(srcValue >> 7);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (ushort *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[2] >> 7);
            dst[1] = (char)(src[1] >> 7);
            srcValue = *src;
            src = src + 3;
            dst[2] = (char)(srcValue >> 7);
          }
          height = height + -1;
          src = (ushort *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[2] >> 7);
            dst[1] = (char)(src[1] >> 7);
            srcValue = *src;
            src = src + 4;
            dst[2] = (char)(srcValue >> 7);
          }
          height = height + -1;
          src = (ushort *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    break;
  case 0x1908:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(*srcCursor >> 7);
              dst[1] = (char)(srcCursor[1] >> 7);
              dst[2] = (char)(srcCursor[2] >> 7);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(*srcComponent >> 7);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                dst[2] = (char)(srcValue >> 7);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0;
                  dst[2] = 0;
                  *dst = (char)(srcValue >> 7);
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (ushort *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  *dst = 0;
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[2] = 0;
                  dst[3] = 0xff;
                  dst[1] = (char)(srcValue >> 7);
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (ushort *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                dst[2] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = (char)(srcValue >> 7);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 7);
                dst[1] = (char)(srcCursor[1] >> 7);
                srcValue = srcCursor[2];
                srcCursor = srcCursor + 3;
                dst[3] = 0xff;
                dst[2] = (char)(srcValue >> 7);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[3] >> 7);
              dst[1] = (char)(srcCursor[2] >> 7);
              dst[2] = (char)(srcCursor[1] >> 7);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(srcValue >> 7);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                *dst = (char)(srcValue >> 7);
                dst[2] = *dst;
                dst[1] = *dst;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 7);
                dst[2] = *dst;
                dst[1] = *dst;
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[3] = (char)(*srcComponent >> 7);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 7);
              dst[1] = (char)(srcCursor[1] >> 7);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              dst[3] = 0xff;
              dst[2] = (char)(srcValue >> 7);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 7);
              dst[1] = (char)(srcCursor[1] >> 7);
              dst[2] = (char)(*srcCursor >> 7);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(*srcComponent >> 7);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1909:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)(srcValue >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1907) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                remaining = (int)dstRowEnd - (int)dst;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  *dst = (char)(srcValue >> 7);
                  dst = dst + 1;
                  remaining = remaining + -1;
                } while (remaining != 0);
              }
              height = height + -1;
              src = (ushort *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              *dst = (char)(srcValue >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)(srcValue >> 7);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 2;
                *dst = (char)(srcValue >> 7);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 3;
              *dst = (char)(*srcComponent >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 7);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x190a:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(*srcCursor >> 7);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(*srcComponent >> 7);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1906) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0xff;
                  *dst = (char)(srcValue >> 7);
                  dst = dst + 2;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (ushort *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              do {
                *dst = 0;
                dst[1] = 0xff;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = (char)(srcValue >> 7);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 3;
                dst[1] = 0xff;
                *dst = (char)(srcValue >> 7);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[3] >> 7);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(srcValue >> 7);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = 0xff;
                *dst = (char)(srcValue >> 7);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 7);
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[1] = (char)(*srcComponent >> 7);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (ushort *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              srcValue = srcCursor[2];
              srcCursor = srcCursor + 3;
              dst[1] = 0xff;
              *dst = (char)(srcValue >> 7);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 7);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(*srcComponent >> 7);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (ushort *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastUshort @ 0xff4c4 (5476 bytes) */
int _gleTextureImagePut_FastUshort(unusedArg1, width, height, src, dst, srcRowStride, unusedArg7, dstRowSkip, dstRowStride, dstFormat, srcFormat)
  undefined4 unusedArg1;
  int width;
  int height;
  undefined2 *src;
  undefined1 *dst;
  int srcRowStride;
  undefined4 unusedArg7;
  int dstRowSkip;
  int dstRowStride;
  undefined4 dstFormat;
  int srcFormat;
{
  undefined2 *srcComponent;
  undefined2 srcValue;
  undefined2 *srcCursor;
  int dstComponentCount;
  int remaining;
  undefined1 *dstRowEnd;
  uint pixelsLeft;
  
  dstComponentCount = _gleComponents(dstFormat);
  dstRowEnd = dst + width * dstComponentCount;
  switch(dstFormat) {
  case 0x1900:
    if (srcFormat != 0x1900) {
      return 0;
    }
    if (0 < height) {
      do {
        if (dst < dstRowEnd) {
          remaining = (int)dstRowEnd - (int)dst;
          srcCursor = src;
          do {
            srcValue = *srcCursor;
            srcCursor = srcCursor + 1;
            *dst = (char)((ushort)srcValue >> 8);
            dst = dst + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        height = height + -1;
        src = (undefined2 *)((int)src + srcRowStride);
        dst = dst + dstRowSkip;
        dstRowEnd = dstRowEnd + dstRowStride;
      } while (height != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)*srcComponent >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)((ushort)srcValue >> 8);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1907) {
        if (srcFormat < 0x1903) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)srcValue >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                *dst = (char)((ushort)*srcComponent >> 8);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)*srcComponent >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1907:
    if (srcFormat == 0x1908) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)((ushort)*src >> 8);
            dst[1] = (char)((ushort)src[1] >> 8);
            srcComponent = src + 2;
            src = src + 4;
            dst[2] = (char)((ushort)*srcComponent >> 8);
          }
          height = height + -1;
          src = (undefined2 *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              srcValue = *src;
              src = src + 1;
              dst[2] = (char)((ushort)srcValue >> 8);
            }
            height = height + -1;
            src = (undefined2 *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                srcValue = *src;
                src = src + 1;
                dst[1] = 0;
                dst[2] = 0;
                *dst = (char)((ushort)srcValue >> 8);
              }
              height = height + -1;
              src = (undefined2 *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                *dst = 0;
                srcValue = *src;
                src = src + 1;
                dst[2] = 0;
                dst[1] = (char)((ushort)srcValue >> 8);
              }
              height = height + -1;
              src = (undefined2 *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              dst[2] = 0;
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = (char)((ushort)*src >> 8);
              dst[1] = (char)((ushort)src[1] >> 8);
              srcComponent = src + 2;
              src = src + 3;
              dst[2] = (char)((ushort)*srcComponent >> 8);
            }
            height = height + -1;
            src = (undefined2 *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)((ushort)src[3] >> 8);
            dst[1] = (char)((ushort)src[2] >> 8);
            srcComponent = src + 1;
            src = src + 4;
            dst[2] = (char)((ushort)*srcComponent >> 8);
          }
          height = height + -1;
          src = (undefined2 *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 1;
              *dst = (char)((ushort)srcValue >> 8);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (undefined2 *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 2;
              *dst = (char)((ushort)srcValue >> 8);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (undefined2 *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)((ushort)src[2] >> 8);
            dst[1] = (char)((ushort)src[1] >> 8);
            srcValue = *src;
            src = src + 3;
            dst[2] = (char)((ushort)srcValue >> 8);
          }
          height = height + -1;
          src = (undefined2 *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)((ushort)src[2] >> 8);
            dst[1] = (char)((ushort)src[1] >> 8);
            srcValue = *src;
            src = src + 4;
            dst[2] = (char)((ushort)srcValue >> 8);
          }
          height = height + -1;
          src = (undefined2 *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    break;
  case 0x1908:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)((ushort)*srcCursor >> 8);
              dst[1] = (char)((ushort)srcCursor[1] >> 8);
              dst[2] = (char)((ushort)srcCursor[2] >> 8);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)((ushort)*srcComponent >> 8);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                dst[2] = (char)((ushort)srcValue >> 8);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0;
                  dst[2] = 0;
                  *dst = (char)((ushort)srcValue >> 8);
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (undefined2 *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  *dst = 0;
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[2] = 0;
                  dst[3] = 0xff;
                  dst[1] = (char)((ushort)srcValue >> 8);
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (undefined2 *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                dst[2] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = (char)((ushort)srcValue >> 8);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)((ushort)*srcCursor >> 8);
                dst[1] = (char)((ushort)srcCursor[1] >> 8);
                srcValue = srcCursor[2];
                srcCursor = srcCursor + 3;
                dst[3] = 0xff;
                dst[2] = (char)((ushort)srcValue >> 8);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)((ushort)srcCursor[3] >> 8);
              dst[1] = (char)((ushort)srcCursor[2] >> 8);
              dst[2] = (char)((ushort)srcCursor[1] >> 8);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[3] = (char)((ushort)srcValue >> 8);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                *dst = (char)((ushort)srcValue >> 8);
                dst[2] = *dst;
                dst[1] = *dst;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)((ushort)*srcCursor >> 8);
                dst[2] = *dst;
                dst[1] = *dst;
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[3] = (char)((ushort)*srcComponent >> 8);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)((ushort)srcCursor[2] >> 8);
              dst[1] = (char)((ushort)srcCursor[1] >> 8);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              dst[3] = 0xff;
              dst[2] = (char)((ushort)srcValue >> 8);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)((ushort)srcCursor[2] >> 8);
              dst[1] = (char)((ushort)srcCursor[1] >> 8);
              dst[2] = (char)((ushort)*srcCursor >> 8);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)((ushort)*srcComponent >> 8);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1909:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)srcValue >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1907) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                remaining = (int)dstRowEnd - (int)dst;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  *dst = (char)((ushort)srcValue >> 8);
                  dst = dst + 1;
                  remaining = remaining + -1;
                } while (remaining != 0);
              }
              height = height + -1;
              src = (undefined2 *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              *dst = (char)((ushort)srcValue >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)*srcComponent >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)((ushort)srcValue >> 8);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 2;
                *dst = (char)((ushort)srcValue >> 8);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 3;
              *dst = (char)((ushort)*srcComponent >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 4;
              *dst = (char)((ushort)*srcComponent >> 8);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x190a:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)((ushort)*srcCursor >> 8);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)((ushort)*srcComponent >> 8);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1906) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0xff;
                  *dst = (char)((ushort)srcValue >> 8);
                  dst = dst + 2;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (undefined2 *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              do {
                *dst = 0;
                dst[1] = 0xff;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = (char)((ushort)srcValue >> 8);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 3;
                dst[1] = 0xff;
                *dst = (char)((ushort)srcValue >> 8);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)((ushort)srcCursor[3] >> 8);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[1] = (char)((ushort)srcValue >> 8);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = 0xff;
                *dst = (char)((ushort)srcValue >> 8);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = (char)((ushort)*srcCursor >> 8);
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[1] = (char)((ushort)*srcComponent >> 8);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (undefined2 *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              srcValue = srcCursor[2];
              srcCursor = srcCursor + 3;
              dst[1] = 0xff;
              *dst = (char)((ushort)srcValue >> 8);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)((ushort)srcCursor[2] >> 8);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)((ushort)*srcComponent >> 8);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (undefined2 *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastInt @ 0x100a54 (5476 bytes) */
int _gleTextureImagePut_FastInt(unusedArg1, width, height, src, dst, srcRowStride, unusedArg7, dstRowSkip, dstRowStride, dstFormat, srcFormat)
  undefined4 unusedArg1;
  int width;
  int height;
  uint *src;
  undefined1 *dst;
  int srcRowStride;
  undefined4 unusedArg7;
  int dstRowSkip;
  int dstRowStride;
  undefined4 dstFormat;
  int srcFormat;
{
  uint *srcComponent;
  uint srcValue;
  uint *srcCursor;
  int dstComponentCount;
  int remaining;
  undefined1 *dstRowEnd;
  uint srcValue2;
  uint pixelsLeft;
  
  dstComponentCount = _gleComponents(dstFormat);
  dstRowEnd = dst + width * dstComponentCount;
  switch(dstFormat) {
  case 0x1900:
    if (srcFormat != 0x1900) {
      return 0;
    }
    if (0 < height) {
      do {
        if (dst < dstRowEnd) {
          remaining = (int)dstRowEnd - (int)dst;
          srcCursor = src;
          do {
            srcValue2 = *srcCursor;
            srcCursor = srcCursor + 1;
            *dst = (char)(srcValue2 >> 0x17);
            dst = dst + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        height = height + -1;
        src = (uint *)((int)src + srcRowStride);
        dst = dst + dstRowSkip;
        dstRowEnd = dstRowEnd + dstRowStride;
      } while (height != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue2 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)(srcValue2 >> 0x17);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1907) {
        if (srcFormat < 0x1903) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue2 = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)(srcValue2 >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                *dst = (char)(*srcComponent >> 0x17);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1907:
    if (srcFormat == 0x1908) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(*src >> 0x17);
            dst[1] = (char)(src[1] >> 0x17);
            srcComponent = src + 2;
            src = src + 4;
            dst[2] = (char)(*srcComponent >> 0x17);
          }
          height = height + -1;
          src = (uint *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              srcValue2 = *src;
              src = src + 1;
              dst[2] = (char)(srcValue2 >> 0x17);
            }
            height = height + -1;
            src = (uint *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                srcValue2 = *src;
                src = src + 1;
                dst[1] = 0;
                dst[2] = 0;
                *dst = (char)(srcValue2 >> 0x17);
              }
              height = height + -1;
              src = (uint *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                *dst = 0;
                srcValue2 = *src;
                src = src + 1;
                dst[2] = 0;
                dst[1] = (char)(srcValue2 >> 0x17);
              }
              height = height + -1;
              src = (uint *)((int)srcCursor + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              dst[2] = 0;
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = (char)(*src >> 0x17);
              dst[1] = (char)(src[1] >> 0x17);
              srcComponent = src + 2;
              src = src + 3;
              dst[2] = (char)(*srcComponent >> 0x17);
            }
            height = height + -1;
            src = (uint *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[3] >> 0x17);
            dst[1] = (char)(src[2] >> 0x17);
            srcComponent = src + 1;
            src = src + 4;
            dst[2] = (char)(*srcComponent >> 0x17);
          }
          height = height + -1;
          src = (uint *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue2 = *src;
              src = src + 1;
              *dst = (char)(srcValue2 >> 0x17);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (uint *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue2 = *src;
              src = src + 2;
              *dst = (char)(srcValue2 >> 0x17);
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = (uint *)((int)srcCursor + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[2] >> 0x17);
            dst[1] = (char)(src[1] >> 0x17);
            srcValue2 = *src;
            src = src + 3;
            dst[2] = (char)(srcValue2 >> 0x17);
          }
          height = height + -1;
          src = (uint *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = (char)(src[2] >> 0x17);
            dst[1] = (char)(src[1] >> 0x17);
            srcValue2 = *src;
            src = src + 4;
            dst[2] = (char)(srcValue2 >> 0x17);
          }
          height = height + -1;
          src = (uint *)((int)srcCursor + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    break;
  case 0x1908:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(*srcCursor >> 0x17);
              dst[1] = (char)(srcCursor[1] >> 0x17);
              dst[2] = (char)(srcCursor[2] >> 0x17);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(*srcComponent >> 0x17);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                dst[2] = (char)(srcValue >> 0x17);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0;
                  dst[2] = 0;
                  *dst = (char)(srcValue >> 0x17);
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (uint *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  *dst = 0;
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[2] = 0;
                  dst[3] = 0xff;
                  dst[1] = (char)(srcValue >> 0x17);
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (uint *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                dst[2] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = (char)(srcValue >> 0x17);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 0x17);
                dst[1] = (char)(srcCursor[1] >> 0x17);
                srcValue = srcCursor[2];
                srcCursor = srcCursor + 3;
                dst[3] = 0xff;
                dst[2] = (char)(srcValue >> 0x17);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[3] >> 0x17);
              dst[1] = (char)(srcCursor[2] >> 0x17);
              dst[2] = (char)(srcCursor[1] >> 0x17);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(srcValue >> 0x17);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[3] = 0xff;
                *dst = (char)(srcValue >> 0x17);
                dst[2] = *dst;
                dst[1] = *dst;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 0x17);
                dst[2] = *dst;
                dst[1] = *dst;
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[3] = (char)(*srcComponent >> 0x17);
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 0x17);
              dst[1] = (char)(srcCursor[1] >> 0x17);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 3;
              dst[3] = 0xff;
              dst[2] = (char)(srcValue >> 0x17);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 0x17);
              dst[1] = (char)(srcCursor[1] >> 0x17);
              dst[2] = (char)(*srcCursor >> 0x17);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[3] = (char)(*srcComponent >> 0x17);
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1909:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue2 = *srcCursor;
              srcCursor = srcCursor + 4;
              *dst = (char)(srcValue2 >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1907) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                remaining = (int)dstRowEnd - (int)dst;
                srcCursor = src;
                do {
                  srcValue2 = *srcCursor;
                  srcCursor = srcCursor + 1;
                  *dst = (char)(srcValue2 >> 0x17);
                  dst = dst + 1;
                  remaining = remaining + -1;
                } while (remaining != 0);
              }
              height = height + -1;
              src = (uint *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue2 = *srcCursor;
              srcCursor = srcCursor + 3;
              *dst = (char)(srcValue2 >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue2 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dst = (char)(srcValue2 >> 0x17);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue2 = *srcCursor;
                srcCursor = srcCursor + 2;
                *dst = (char)(srcValue2 >> 0x17);
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 3;
              *dst = (char)(*srcComponent >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 2;
              srcCursor = srcCursor + 4;
              *dst = (char)(*srcComponent >> 0x17);
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x190a:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(*srcCursor >> 0x17);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(*srcComponent >> 0x17);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1906) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 1;
                  dst[1] = 0xff;
                  *dst = (char)(srcValue >> 0x17);
                  dst = dst + 2;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = (uint *)((int)src + srcRowStride);
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              do {
                *dst = 0;
                dst[1] = 0xff;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = (char)(srcValue >> 0x17);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 3;
                dst[1] = 0xff;
                *dst = (char)(srcValue >> 0x17);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[3] >> 0x17);
              srcValue = *srcCursor;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(srcValue >> 0x17);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 1;
                dst[1] = 0xff;
                *dst = (char)(srcValue >> 0x17);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = (char)(*srcCursor >> 0x17);
                srcComponent = srcCursor + 1;
                srcCursor = srcCursor + 2;
                dst[1] = (char)(*srcComponent >> 0x17);
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = (uint *)((int)src + srcRowStride);
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              srcValue = srcCursor[2];
              srcCursor = srcCursor + 3;
              dst[1] = 0xff;
              *dst = (char)(srcValue >> 0x17);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = (char)(srcCursor[2] >> 0x17);
              srcComponent = srcCursor + 3;
              srcCursor = srcCursor + 4;
              dst[1] = (char)(*srcComponent >> 0x17);
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = (uint *)((int)src + srcRowStride);
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
  }
  return 1;
}

/* _gleTextureImagePut_FastUint @ 0x101fe4 (5188 bytes) */
int _gleTextureImagePut_FastUint(unusedArg1, width, height, src, dst, srcRowStride, unusedArg7, dstRowSkip, dstRowStride, dstFormat, srcFormat)
  undefined4 unusedArg1;
  int width;
  int height;
  undefined1 *src;
  undefined1 *dst;
  int srcRowStride;
  undefined4 unusedArg7;
  int dstRowSkip;
  int dstRowStride;
  undefined4 dstFormat;
  int srcFormat;
{
  undefined1 *srcComponent;
  undefined1 srcValue;
  int dstComponentCount;
  int remaining;
  undefined1 *srcCursor;
  undefined1 *dstRowEnd;
  uint pixelsLeft;
  
  dstComponentCount = _gleComponents(dstFormat);
  dstRowEnd = dst + width * dstComponentCount;
  switch(dstFormat) {
  case 0x1900:
    if (srcFormat != 0x1900) {
      return 0;
    }
    if (0 < height) {
      do {
        if (dst < dstRowEnd) {
          remaining = (int)dstRowEnd - (int)dst;
          srcCursor = src;
          do {
            srcValue = *srcCursor;
            srcCursor = srcCursor + 4;
            *dst = srcValue;
            dst = dst + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
        height = height + -1;
        src = src + srcRowStride;
        dst = dst + dstRowSkip;
        dstRowEnd = dstRowEnd + dstRowStride;
      } while (height != 0);
    }
    break;
  default:
    return 0;
  case 0x1906:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              *dst = *srcComponent;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                *dst = srcValue;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1907) {
        if (srcFormat < 0x1903) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0x10;
              *dst = srcValue;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0xff;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcComponent = srcCursor + 4;
                srcCursor = srcCursor + 8;
                *dst = *srcComponent;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            do {
              *dst = 0xff;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              *dst = *srcComponent;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1907:
    if (srcFormat == 0x1908) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = *src;
            dst[1] = src[4];
            srcComponent = src + 8;
            src = src + 0x10;
            dst[2] = *srcComponent;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              srcValue = *src;
              src = src + 4;
              dst[2] = srcValue;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                srcValue = *src;
                src = src + 4;
                dst[1] = 0;
                *dst = srcValue;
                dst[2] = 0;
              }
              height = height + -1;
              src = srcCursor + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          srcCursor = src;
          if (0 < height) {
            do {
              for (; dst < dstRowEnd; dst = dst + 3) {
                *dst = 0;
                srcValue = *src;
                src = src + 4;
                dst[2] = 0;
                dst[1] = srcValue;
              }
              height = height + -1;
              src = srcCursor + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
              srcCursor = src;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = 0;
              dst[1] = 0;
              dst[2] = 0;
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              *dst = *src;
              dst[1] = src[4];
              srcComponent = src + 8;
              src = src + 0xc;
              dst[2] = *srcComponent;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = src[0xc];
            dst[1] = src[8];
            srcComponent = src + 4;
            src = src + 0x10;
            dst[2] = *srcComponent;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 4;
              *dst = srcValue;
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        srcCursor = src;
        if (0 < height) {
          do {
            for (; dst < dstRowEnd; dst = dst + 3) {
              srcValue = *src;
              src = src + 8;
              *dst = srcValue;
              dst[2] = *dst;
              dst[1] = *dst;
            }
            height = height + -1;
            src = srcCursor + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
            srcCursor = src;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = src[8];
            dst[1] = src[4];
            srcValue = *src;
            src = src + 0xc;
            dst[2] = srcValue;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      srcCursor = src;
      if (0 < height) {
        do {
          for (; dst < dstRowEnd; dst = dst + 3) {
            *dst = src[8];
            dst[1] = src[4];
            srcValue = *src;
            src = src + 0x10;
            dst[2] = srcValue;
          }
          height = height + -1;
          src = srcCursor + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
          srcCursor = src;
        } while (height != 0);
      }
    }
    break;
  case 0x1908:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = *srcCursor;
              dst[1] = srcCursor[4];
              dst[2] = srcCursor[8];
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              dst[3] = *srcComponent;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat == 0x1905) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                dst[3] = 0xff;
                dst[2] = srcValue;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat < 0x1906) {
        if (srcFormat == 0x1903) {
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 4;
                  dst[1] = 0;
                  *dst = srcValue;
                  dst[2] = 0;
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else {
          if (srcFormat != 0x1904) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
                srcCursor = src;
                do {
                  *dst = 0;
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 4;
                  dst[2] = 0;
                  dst[1] = srcValue;
                  dst[3] = 0xff;
                  dst = dst + 4;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = 0;
                dst[1] = 0;
                dst[2] = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                dst[3] = srcValue;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = *srcCursor;
                dst[1] = srcCursor[4];
                srcValue = srcCursor[8];
                srcCursor = srcCursor + 0xc;
                dst[3] = 0xff;
                dst[2] = srcValue;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[0xc];
              dst[1] = srcCursor[8];
              dst[2] = srcCursor[4];
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0x10;
              dst[3] = srcValue;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                dst[3] = 0xff;
                *dst = srcValue;
                dst[2] = *dst;
                dst[1] = *dst;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
              srcCursor = src;
              do {
                *dst = *srcCursor;
                dst[2] = *dst;
                dst[1] = *dst;
                srcComponent = srcCursor + 4;
                srcCursor = srcCursor + 8;
                dst[3] = *srcComponent;
                dst = dst + 4;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[8];
              dst[1] = srcCursor[4];
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0xc;
              dst[3] = 0xff;
              dst[2] = srcValue;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (3 - (int)dst)) >> 2;
            srcCursor = src;
            do {
              *dst = srcCursor[8];
              dst[1] = srcCursor[4];
              dst[2] = *srcCursor;
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              dst[3] = *srcComponent;
              dst = dst + 4;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x1909:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0x10;
              *dst = srcValue;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1907) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                remaining = (int)dstRowEnd - (int)dst;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 4;
                  *dst = srcValue;
                  dst = dst + 1;
                  remaining = remaining + -1;
                } while (remaining != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              do {
                *dst = 0;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0xc;
              *dst = srcValue;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              *dst = *srcComponent;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                *dst = srcValue;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              remaining = (int)dstRowEnd - (int)dst;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 8;
                *dst = srcValue;
                dst = dst + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 8;
              srcCursor = srcCursor + 0xc;
              *dst = *srcComponent;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            remaining = (int)dstRowEnd - (int)dst;
            srcCursor = src;
            do {
              srcComponent = srcCursor + 8;
              srcCursor = srcCursor + 0x10;
              *dst = *srcComponent;
              dst = dst + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    break;
  case 0x190a:
    if (srcFormat == 0x1908) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = *srcCursor;
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              dst[1] = *srcComponent;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x1909) {
      if (srcFormat < 0x1906) {
        if (srcFormat < 0x1904) {
          if (srcFormat != 0x1903) {
            return 0;
          }
          if (0 < height) {
            do {
              if (dst < dstRowEnd) {
                pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
                srcCursor = src;
                do {
                  srcValue = *srcCursor;
                  srcCursor = srcCursor + 4;
                  dst[1] = 0xff;
                  *dst = srcValue;
                  dst = dst + 2;
                  pixelsLeft = pixelsLeft - 1;
                } while (pixelsLeft != 0);
              }
              height = height + -1;
              src = src + srcRowStride;
              dst = dst + dstRowSkip;
              dstRowEnd = dstRowEnd + dstRowStride;
            } while (height != 0);
          }
        }
        else if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              do {
                *dst = 0;
                dst[1] = 0xff;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else if (srcFormat == 0x1906) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = 0;
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                dst[1] = srcValue;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x1907) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 0xc;
                dst[1] = 0xff;
                *dst = srcValue;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x8000) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = srcCursor[0xc];
              srcValue = *srcCursor;
              srcCursor = srcCursor + 0x10;
              dst[1] = srcValue;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else if (srcFormat < 0x8001) {
      if (srcFormat == 0x1909) {
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                srcValue = *srcCursor;
                srcCursor = srcCursor + 4;
                dst[1] = 0xff;
                *dst = srcValue;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
      else {
        if (srcFormat != 0x190a) {
          return 0;
        }
        if (0 < height) {
          do {
            if (dst < dstRowEnd) {
              pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
              srcCursor = src;
              do {
                *dst = *srcCursor;
                srcComponent = srcCursor + 4;
                srcCursor = srcCursor + 8;
                dst[1] = *srcComponent;
                dst = dst + 2;
                pixelsLeft = pixelsLeft - 1;
              } while (pixelsLeft != 0);
            }
            height = height + -1;
            src = src + srcRowStride;
            dst = dst + dstRowSkip;
            dstRowEnd = dstRowEnd + dstRowStride;
          } while (height != 0);
        }
      }
    }
    else if (srcFormat == 0x80e0) {
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              srcValue = srcCursor[8];
              srcCursor = srcCursor + 0xc;
              dst[1] = 0xff;
              *dst = srcValue;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
    else {
      if (srcFormat != 0x80e1) {
        return 0;
      }
      if (0 < height) {
        do {
          if (dst < dstRowEnd) {
            pixelsLeft = (uint)(dstRowEnd + (1 - (int)dst)) >> 1;
            srcCursor = src;
            do {
              *dst = srcCursor[8];
              srcComponent = srcCursor + 0xc;
              srcCursor = srcCursor + 0x10;
              dst[1] = *srcComponent;
              dst = dst + 2;
              pixelsLeft = pixelsLeft - 1;
            } while (pixelsLeft != 0);
          }
          height = height + -1;
          src = src + srcRowStride;
          dst = dst + dstRowSkip;
          dstRowEnd = dstRowEnd + dstRowStride;
        } while (height != 0);
      }
    }
  }
  return 1;
}

/* _gleCreateColorTableLevel @ 0x103454 (224 bytes) */
int _gleCreateColorTableLevel(glContext, param_2, param_3, internalformat, width, unusedArg6, unusedArg7, param_8)
  undefined4 glContext;
  undefined4 param_2;
  int param_3;
  undefined4 internalformat;
  int width;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  int param_8;
{
  undefined2 uVar2;
  int iVar1;
  
  *(undefined1 *)(param_3 + 10) = 0;
  *(undefined4 *)(param_3 + 0x14) = 0;
  if (width != 0) {
    *(undefined1 *)(param_3 + 0xb) = 0x20;
    *(short *)(param_3 + 4) = (short)width;
    *(undefined2 *)(param_3 + 6) = 1;
    *(undefined2 *)(param_3 + 8) = 1;
    uVar2 = _gleImagingTexFormatToInternal(internalformat);
    *(undefined2 *)(param_3 + 0x10) = uVar2;
    *(undefined2 *)(param_3 + 0x12) = 0x1406;
    *(short *)(param_3 + 0xc) = (short)width;
    *(undefined2 *)(param_3 + 0xe) = 1;
    if (param_8 == 0) {
      return 1;
    }
    iVar1 = _gleAllocateTextureLevel(glContext,param_2,param_3);
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

