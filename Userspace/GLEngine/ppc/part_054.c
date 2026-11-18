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
  uint remaining;
  
  byteOffset = 0;
  if ((int)(count << 1) < 1) {
    return;
  }
  remaining = count & 0x7fffffff;
  do {
    *(short *)(dst + byteOffset) =
         (short)((int)*(short *)(src + byteOffset) + (int)*(short *)(src + byteOffset + offsetA) >> 1)
    ;
    byteOffset = byteOffset + 2;
    remaining = remaining - 1;
  } while (remaining != 0);
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
  float texelBC;
  float *sourceABC;
  float weight;
  int sourceSample;
  int byteOffset;
  float *sourceBCCursor;
  uint remaining;
  
  weight = FLOAT_00108f4c;
  byteOffset = 0;
  if (0 < (int)(count << 2)) {
    remaining = count & 0x3fffffff;
    sourceBCCursor = (float *)(src + offsetB + offsetC);
    do {
      sourceSample = src + byteOffset;
      texelBC = *sourceBCCursor;
      sourceABC = (float *)((int)sourceBCCursor + offsetA);
      sourceBCCursor = sourceBCCursor + 1;
      *(float *)(dst + byteOffset) =
           (*(float *)(src + byteOffset) + *(float *)(sourceSample + offsetA) + *(float *)(sourceSample + offsetB)
            + *(float *)(sourceSample + offsetA + offsetB) + *(float *)(sourceSample + offsetC) +
            *(float *)(sourceSample + offsetA + offsetC) + texelBC + *sourceABC) * weight;
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
  byte texel0;
  byte texelA;
  
  texel0 = *src;
  texelA = src[offsetA];
  *dst = (byte)((texel0 & 0xe0) + (texelA & 0xe0) >> 1) & 0xe0 |
             (byte)((texel0 & 0x1c) + (texelA & 0x1c) >> 1) & 0x1c |
             (byte)((texel0 & 3) + (texelA & 3) >> 1);
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
  byte texel0;
  byte texelA;
  byte texelB;
  byte texelAB;
  
  texel0 = *src;
  texelA = src[offsetA];
  texelB = src[offsetB];
  texelAB = src[offsetB + offsetA];
  *dst = (byte)((texel0 & 0xe0) + (texelA & 0xe0) + (texelB & 0xe0) + (texelAB & 0xe0) >> 2) & 0xe0 |
             (byte)((texel0 & 0x1c) + (texelA & 0x1c) + (texelB & 0x1c) + (texelAB & 0x1c) >> 2) & 0x1c |
             (byte)((texel0 & 3) + (texelA & 3) + (texelB & 3) + (texelAB & 3) >> 2) & 3;
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
  ushort texel0;
  ushort texelA;
  ushort texelB;
  ushort texelAB;
  
  texel0 = *src;
  texelA = *(ushort *)((int)src + offsetA);
  texelB = *(ushort *)((int)src + offsetB);
  texelAB = *(ushort *)((int)src + offsetB + offsetA);
  *dst = (ushort)((texel0 & 0xf000) + (texelA & 0xf000) + (texelB & 0xf000) + (texelAB & 0xf000) >> 2
                     ) & 0xf000 |
             (ushort)((texel0 & 0xf00) + (texelA & 0xf00) + (texelB & 0xf00) + (texelAB & 0xf00) >> 2) &
             0xf00 | (ushort)((texel0 & 0xf0) + (texelA & 0xf0) + (texelB & 0xf0) + (texelAB & 0xf0) >> 2
                             ) & 0xf0 |
             (ushort)((texel0 & 0xf) + (texelA & 0xf) + (texelB & 0xf) + (texelAB & 0xf) >> 2) & 0xf;
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
  undefined2 texelAB;
  
  texelAB = *(undefined2 *)((int)src + offsetB + offsetA);
  *dst = ((short)(char)((ushort)*src >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetA) >> 8) +
              (short)(char)((ushort)*(undefined2 *)((int)src + offsetB) >> 8) +
             (short)(char)((ushort)texelAB >> 8)) * 0x80 & 0xff00U |
             (ushort)((uint)((int)(char)*src +
                             (int)(char)*(undefined2 *)((int)src + offsetA) +
                             (int)(char)*(undefined2 *)((int)src + offsetB) + (int)(char)texelAB)
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
  int texelAB;
  int texelAC;
  int texelBC;
  int texelABC;
  
  texelAB = *(int *)((int)src + offsetB + offsetA);
  texelAC = *(int *)((int)src + offsetC + offsetA);
  texelBC = *(int *)((int)src + offsetC + offsetB);
  texelABC = *(int *)((int)src + offsetC + offsetB + offsetA);
  *dst = ((*src >> 0x10) + (*(int *)((int)src + offsetA) >> 0x10) +
              (*(int *)((int)src + offsetB) >> 0x10) + (texelAB >> 0x10) +
              (*(int *)((int)src + offsetC) >> 0x10) + (texelAC >> 0x10) + (texelBC >> 0x10) +
             (texelABC >> 0x10)) * 0x8000 & 0xffff0000U |
             (uint)((int)(short)*src + (int)(short)*(int *)((int)src + offsetA) +
                    (int)(short)*(int *)((int)src + offsetB) + (int)(short)texelAB +
                    (int)(short)*(int *)((int)src + offsetC) + (int)(short)texelAC +
                    (int)(short)texelBC + (int)(short)texelABC) >> 1 & 0xffff;
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
  int dstOrSrcCursorOrColumns;
  undefined4 rgbaRowBytes;
  undefined4 compressedBuffer;
  undefined4 compressedRowBytes;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int incomingR8;
  undefined *puVar15;
  int incomingR10;
  int cursorOrColumnsOrSkipBytes;
  int srcCursor3;
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
  int srcCursorLevelImageOrOffset;
  int dstOrSrcCursorOrSkipBytes;
  int dstOrSrcCursor;
  int rowPixelsStrideOrCursor;
  int cursorOrStrideOrCount;
  uint typeBorderDepthOrRowCount;
  int dstOrSrcCursorOrColumns2;
  int dstCursor;
  int dstCursor2;
  byte in_xer_so = 0;
  byte borderCompareCr;
  byte incomingCr1;
  byte dimensionsCompareCr1;
  byte dimensionsCompareCr2;
  byte incomingCr4;
  byte incomingCr5;
  byte incomingCr6;
  byte pixelTypeCompareCr;
  byte savedCrHighByte;
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
  int pixelPairBytesCopy5;
  int pixelPairBytesCopy6;
  int pixelPairBytesCopy7;
  int sliceSkipBytes;
  int firstGeneratedLevel;
  int rowSkipBytes5;
  int pixelPairBytesCopy8;
  int srcPixelAdvance3;
  uint savedCrFields;
  uint savedCrFields2;
  int pixelPairBytes;
  uint savedCrFields3;
  int pixelPairBytesCopy1;
  int pixelPairBytesCopy2;
  int pixelPairBytesCopy3;
  int srcPixelAdvance4;
  int pixelPairBytesCopy4;
  
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
  typeBorderDepthOrRowCount = (uint)pixelType;
  pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8032) << 3 | (0x8032 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8032) << 1 | in_xer_so & 1
  ;
  if (typeBorderDepthOrRowCount == 0x8032) {
    filter1D = (code *)PTR__gle332Filter1_0011156c;
    filter2D = (code *)PTR__gle332Filter2_00111568;
    filter3D = (code *)PTR__gle332Filter3_00111564;
LAB_000faa98:
    bytesPerPixel = 1;
    goto LAB_000facc8;
  }
  if (0x8032 >= typeBorderDepthOrRowCount) {
    pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x1400) << 3 | (0x1400 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x1400) << 1 |
             in_xer_so & 1;
    bytesPerPixel = levelRecordThenComponentCount;
    if (typeBorderDepthOrRowCount == 0x1400) {
      filter1D = (code *)PTR__gleByteFilter1_001115c0;
      filter2D = (code *)PTR__gleByteFilter2_001115bc;
      filter3D = (code *)PTR__gleByteFilter3_001115b8;
      goto LAB_000facc8;
    }
    if (0x1400 >= typeBorderDepthOrRowCount) {
      pixelTypeCompareCr = (typeBorderDepthOrRowCount < 5) << 3 | (5 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 5) << 1 | in_xer_so & 1;
      if (typeBorderDepthOrRowCount == 5) {
        filter1D = (code *)PTR__gle1616Filter1_001114dc;
        filter2D = (code *)PTR__gle1616Filter2_001114d8;
        filter3D = (code *)PTR__gle1616Filter3_001114d4;
      }
      else {
        if (5 >= typeBorderDepthOrRowCount) {
          if (typeBorderDepthOrRowCount == 0) {
            levelRecordThenComponentCount = 4;
            puVar15 = &DAT_0010a634;
            filter1D = (code *)PTR__gle8888Filter1_001115d8;
            originalCompressedData = *(int *)(sourceImage + 0x14);
            decodedData = _malloc((uint)*(ushort *)(sourceImage + 4) * 4 * (uint)*(ushort *)(sourceImage + 6) *
                            (uint)*(ushort *)(sourceImage + 8));
            pixelTypeCompareCr = (decodedData < 0) << 3 | (0 < decodedData) << 2 | (decodedData == 0) << 1 | in_xer_so & 1;
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
            local_18c = typeBorderDepthOrRowCount;
            local_188 = typeBorderDepthOrRowCount;
            _glgProcessPixels(iStack00000018 + 0x31a8,&local_1b0,puVar13,puVar14,lastLevelThenLevelArg,incomingR8,
                              iStack00000018,incomingR10);
            bytesPerPixel = 4;
            goto LAB_000facc8;
          }
          pixelTypeCompareCr = (typeBorderDepthOrRowCount == 0) << 3 | (1 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 1) << 1 | in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 1) {
            return;
          }
          filter1D = (code *)PTR__gles8s8Filter1_001114e8;
          filter2D = (code *)PTR__gles8s8Filter2_001114e4;
          filter3D = (code *)PTR__gles8s8Filter3_001114e0;
          goto LAB_000fac40;
        }
        pixelTypeCompareCr = (typeBorderDepthOrRowCount < 7) << 3 | (7 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 7) << 1 | in_xer_so & 1;
        if (typeBorderDepthOrRowCount == 7) {
          filter1D = (code *)PTR__gle8s8s8s8Filter1_001114c4;
          filter2D = (code *)PTR__gle8s8s8s8Filter2_001114c0;
          filter3D = (code *)PTR__gle8s8s8s8Filter3_001114bc;
        }
        else if (typeBorderDepthOrRowCount < 7) {
          filter1D = (code *)PTR__gles16s16Filter1_001114d0;
          filter2D = (code *)PTR__gles16s16Filter2_001114cc;
          filter3D = (code *)PTR__gles16s16Filter3_001114c8;
        }
        else {
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 8) << 3 | (8 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 8) << 1 | in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 8) {
            return;
          }
          filter1D = (code *)PTR__gles8s8s8s8Filter1_001114b8;
          filter2D = (code *)PTR__gles8s8s8s8Filter2_001114b4;
          filter3D = (code *)PTR__gles8s8s8s8Filter3_001114b0;
        }
      }
      goto LAB_000facc4;
    }
    pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x1404) << 3 | (0x1404 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x1404) << 1 |
             in_xer_so & 1;
    if (typeBorderDepthOrRowCount == 0x1404) {
      filter1D = (code *)PTR__gleIntFilter1_00111590;
      filter2D = (code *)PTR__gleIntFilter2_0011158c;
      filter3D = (code *)PTR__gleIntFilter3_00111588;
    }
    else {
      if (0x1404 >= typeBorderDepthOrRowCount) {
        pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x1402) << 3 | (0x1402 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x1402) << 1 |
                 in_xer_so & 1;
        if (typeBorderDepthOrRowCount == 0x1402) {
          filter1D = (code *)PTR__gleShortFilter1_001115a8;
          filter2D = (code *)PTR__gleShortFilter2_001115a4;
          filter3D = (code *)PTR__gleShortFilter3_001115a0;
        }
        else {
          if (0x1402 >= typeBorderDepthOrRowCount) {
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
      pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x1406) << 3 | (0x1406 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x1406) << 1 |
               in_xer_so & 1;
      if (typeBorderDepthOrRowCount == 0x1406) {
        filter1D = (code *)PTR__gleFloatFilter1_00111584;
        filter2D = (code *)PTR__gleFloatFilter2_00111580;
        filter3D = (code *)PTR__gleFloatFilter3_0011157c;
      }
      else {
        if (typeBorderDepthOrRowCount >= 0x1406) {
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x140b) << 3 | (0x140b < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x140b) << 1 |
                   in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 0x140b) {
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
  pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8365) << 3 | (0x8365 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8365) << 1 | in_xer_so & 1
  ;
  if (typeBorderDepthOrRowCount == 0x8365) {
LAB_000faac0:
    filter1D = (code *)PTR__gle4444Filter1_00111548;
    filter2D = (code *)PTR__gle4444Filter2_00111544;
    filter3D = (code *)PTR__gle4444Filter3_00111540;
LAB_000fac40:
    bytesPerPixel = 2;
  }
  else {
    if (0x8365 < typeBorderDepthOrRowCount) {
      if (typeBorderDepthOrRowCount < 0x85bc) {
        if (0x85b9 < typeBorderDepthOrRowCount) {
          format = *(ushort *)(sourceImage + 0x10);
          pixelTypeCompareCr = (format < 0x85b9) << 3 | (0x85b9 < format) << 2 | (format == 0x85b9) << 1 |
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
        pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8367) << 3 | (0x8367 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8367) << 1 |
                 in_xer_so & 1;
        if (typeBorderDepthOrRowCount == 0x8367) {
LAB_000fab84:
          filter1D = (code *)PTR__gle8888Filter1_001115d8;
        }
        else {
          if (typeBorderDepthOrRowCount < 0x8367) {
            filter1D = (code *)PTR__gle1555RevFilter1_00111530;
            filter2D = (code *)PTR__gle1555RevFilter2_0011152c;
            filter3D = (code *)PTR__gle1555RevFilter3_00111528;
            goto LAB_000fac40;
          }
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8368) << 3 | (0x8368 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8368) << 1 |
                   in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 0x8368) {
            return;
          }
          filter1D = (code *)PTR__gle2101010RevFilter1_0011150c;
          filter2D = (code *)PTR__gle2101010RevFilter2_00111508;
          filter3D = (code *)PTR__gle2101010RevFilter3_00111504;
        }
      }
      else {
        pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x86da) << 3 | (0x86da < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x86da) << 1 |
                 in_xer_so & 1;
        if (typeBorderDepthOrRowCount == 0x86da) {
          filter1D = (code *)PTR__gles8s888Filter1_001114f4;
          filter2D = (code *)PTR__gles8s888Filter2_001114f0;
          filter3D = (code *)PTR__gles8s888Filter3_001114ec;
        }
        else {
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x86db) << 3 | (0x86db < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x86db) << 1 |
                   in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 0x86db) {
            return;
          }
          filter1D = (code *)PTR__gle88s8s8Filter1_00111500;
          filter2D = (code *)PTR__gle88s8s8Filter2_001114fc;
          filter3D = (code *)PTR__gle88s8s8Filter3_001114f8;
        }
      }
    }
    else {
      pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8036) << 3 | (0x8036 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8036) << 1 |
               in_xer_so & 1;
      if (typeBorderDepthOrRowCount != 0x8036) {
        if (0x8036 < typeBorderDepthOrRowCount) {
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8362) << 3 | (0x8362 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8362) << 1 |
                   in_xer_so & 1;
          if (typeBorderDepthOrRowCount == 0x8362) {
            filter1D = (code *)PTR__gle233RevFilter1_00111560;
            filter2D = (code *)PTR__gle233RevFilter2_0011155c;
            filter3D = (code *)PTR__gle233RevFilter3_00111558;
            goto LAB_000faa98;
          }
          if (typeBorderDepthOrRowCount < 0x8362) {
            return;
          }
          filter1D = (code *)PTR__gle565Filter1_00111554;
          filter2D = (code *)PTR__gle565Filter2_00111550;
          filter3D = (code *)PTR__gle565Filter3_0011154c;
        }
        else {
          pixelTypeCompareCr = (typeBorderDepthOrRowCount < 0x8034) << 3 | (0x8034 < typeBorderDepthOrRowCount) << 2 | (typeBorderDepthOrRowCount == 0x8034) << 1 |
                   in_xer_so & 1;
          if (typeBorderDepthOrRowCount != 0x8034) {
            if (0x8034 < typeBorderDepthOrRowCount) goto LAB_000fab84;
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
  typeBorderDepthOrRowCount = (uint)*(byte *)(sourceImage + 10);
  moreThanOneDimension = 1 < dimensions;
  isOneDimensional = dimensions == 1;
  dimensionsCompareCr1 = (dimensions < 1) << 3 | moreThanOneDimension << 2 | isOneDimensional << 1 | in_xer_so & 1;
  twiceBorder = typeBorderDepthOrRowCount * 2;
  srcThenDestInteriorHeight = (uint)*(ushort *)(sourceImage + 6);
  srcThenDestInteriorWidth = (int)((uint)*(ushort *)(sourceImage + 4) + typeBorderDepthOrRowCount * -2) >> (pixelPairShift & 0x3f);
  if (moreThanOneDimension) {
    srcThenDestInteriorHeight = srcThenDestInteriorHeight + typeBorderDepthOrRowCount * -2;
  }
  isThreeDimensional = 2 < dimensions;
  isTwoDimensional = dimensions == 2;
  dimensionsCompareCr2 = (dimensions < 2) << 3 | isThreeDimensional << 2 | isTwoDimensional << 1 | in_xer_so & 1;
  srcThenDestInteriorDepth = (uint)*(ushort *)(sourceImage + 8);
  if (isThreeDimensional) {
    srcThenDestInteriorDepth = srcThenDestInteriorDepth + typeBorderDepthOrRowCount * -2;
  }
  pixelPairBytes = bytesPerPixel << 1;
  nextLevel = sourceLevel + 1;
  borderCompareCr = (typeBorderDepthOrRowCount != 0) << 2 | (typeBorderDepthOrRowCount == 0) << 1 | in_xer_so & 1;
  savedCrFields = (uint)borderCompareCr << 0x1c | (uint)(incomingCr1 & 0xf) << 0x18 | (uint)dimensionsCompareCr1 << 0x14 |
             (uint)dimensionsCompareCr2 << 0x10 | (uint)(incomingCr4 & 0xf) << 0xc | (uint)(incomingCr5 & 0xf) << 8 |
             (uint)(incomingCr6 & 0xf) << 4 | (uint)(pixelTypeCompareCr & 0xf);
  savedCrFields3 = (uint)borderCompareCr << 0x1c | (uint)(incomingCr1 & 0xf) << 0x18 | (uint)dimensionsCompareCr1 << 0x14 |
             (uint)dimensionsCompareCr2 << 0x10 | (uint)(incomingCr4 & 0xf) << 0xc | (uint)(incomingCr5 & 0xf) << 8 |
             (uint)(incomingCr6 & 0xf) << 4 | (uint)(pixelTypeCompareCr & 0xf);
  borderCopy = twiceBorder >> 1;
  srcCursorLevelImageOrOffset = sourceImage;
  firstGeneratedLevel = nextLevel;
  savedCrFields2 = savedCrFields;
  pixelPairBytesCopy1 = pixelPairBytes;
  pixelPairBytesCopy2 = pixelPairBytes;
  pixelPairBytesCopy3 = pixelPairBytes;
  pixelPairBytesCopy4 = pixelPairBytes;
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
          srcCursorLevelImageOrOffset = levelsToRecompress * 0x18 + iStack0000001c + faceOffset + 0xc4;
          levelsToRecompress = iStack00000028 - levelsToRecompress;
          pixelTransferState = iStack00000018 + 0x31a8;
          savedGlContext = iStack00000018;
          do {
            decodedLevelData = *(undefined4 *)(srcCursorLevelImageOrOffset + 0x14);
            compressedBuffer = _malloc(blockBytes * ((int)(*(ushort *)(srcCursorLevelImageOrOffset + 4) + 3) >> 2) *
                             ((int)(*(ushort *)(srcCursorLevelImageOrOffset + 6) + 3) >> 2));
            *(undefined4 *)(srcCursorLevelImageOrOffset + 0x14) = compressedBuffer;
            rgbaRowBytes = _gleRowBytes(0x1908,0x8035,(uint)*(ushort *)(srcCursorLevelImageOrOffset + 4));
            compressedRowBytes = _gleRowBytes((uint)*(ushort *)(srcCursorLevelImageOrOffset + 0x10),0,(uint)*(ushort *)(srcCursorLevelImageOrOffset + 0xc)
                                 );
            _glgConvertType(0x1908,0x8035,auStack_138,auStack_134,lastLevelThenLevelArg,incomingR8,savedGlContext,incomingR10);
            puVar13 = auStack_128;
            puVar14 = auStack_124;
            _glgConvertType((uint)*(ushort *)(srcCursorLevelImageOrOffset + 0x10),0,auStack_128,auStack_124,lastLevelThenLevelArg,incomingR8
                            ,savedGlContext,incomingR10);
            local_11c = 0;
            local_120 = 2;
            local_118 = 0;
            local_114 = (uint)*(ushort *)(srcCursorLevelImageOrOffset + 4);
            local_110 = (uint)*(ushort *)(srcCursorLevelImageOrOffset + 6);
            local_140 = decodedLevelData;
            local_130 = *(undefined4 *)(srcCursorLevelImageOrOffset + 0x14);
            srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + 0x18;
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
    rowPixelsStrideOrCursor = (int)(uint)*(ushort *)(srcCursorLevelImageOrOffset + 0xc) >> (pixelPairShift & 0x3f);
    rowBytes = rowPixelsStrideOrCursor * bytesPerPixel;
    rowPadBytes = (rowPixelsStrideOrCursor - (srcThenDestInteriorWidth + twiceBorder)) * bytesPerPixel;
    rowPixelsStrideOrCursor = 0;
    if (srcThenDestInteriorHeight != 1) {
      rowPixelsStrideOrCursor = rowBytes;
    }
    sliceBytes = (uint)*(ushort *)(srcCursorLevelImageOrOffset + 0xe) * rowBytes;
    cursorOrColumnsOrSkipBytes = ((uint)*(ushort *)(srcCursorLevelImageOrOffset + 0xe) - (srcThenDestInteriorHeight + twiceBorder)) * rowBytes;
    cursorOrStrideOrCount = 0;
    if (srcThenDestInteriorDepth != 1) {
      cursorOrStrideOrCount = sliceBytes;
    }
    srcThenDestInteriorHeight = (uint)*(ushort *)(destLevelRecord + 0xca);
    srcThenDestInteriorWidth = (int)((uint)*(ushort *)(destLevelRecord + 200) - twiceBorder) >> (pixelPairShift & 0x3f);
    if (moreThanOneDimension) {
      srcThenDestInteriorHeight = srcThenDestInteriorHeight - twiceBorder;
    }
    typeBorderDepthOrRowCount = (uint)*(ushort *)(destLevelRecord + 0xcc);
    srcThenDestInteriorDepth = typeBorderDepthOrRowCount;
    if (isThreeDimensional) {
      srcThenDestInteriorDepth = typeBorderDepthOrRowCount - twiceBorder;
    }
    dstOrSrcCursorOrColumns = _malloc((uint)*(ushort *)(destLevelRecord + 0xd0) * (uint)*(ushort *)(destLevelRecord + 0xd2) * typeBorderDepthOrRowCount *
                     (bytesPerPixel >> (pixelPairShift & 0x3f)));
    *(int *)(destLevelRecord + 0xd8) = dstOrSrcCursorOrColumns;
    srcCursorLevelImageOrOffset = *(int *)(srcCursorLevelImageOrOffset + 0x14);
    *(byte *)(destLevelRecord + 0xcf) = *(byte *)(destLevelRecord + 0xcf) | 0x10;
    if (isTwoDimensional) {
      savedCrHighByte = (byte)(savedCrFields2 >> 0x18);
      if (!(bool)(savedCrHighByte >> 5 & 1)) {
        cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
        cursorOrStrideOrCount = srcCursorLevelImageOrOffset + bytesPerPixel;
        (*filter2D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        if (0 < srcThenDestInteriorWidth) {
          srcCursorLevelImageOrOffset = cursorOrStrideOrCount;
          columnsRemaining3 = srcThenDestInteriorWidth;
          dstOrSrcCursorOrColumns = cursorOrColumnsOrSkipBytes;
          do {
            cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
            cursorOrStrideOrCount = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
            (*filter2D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes);
            columnsRemaining3 = columnsRemaining3 + -1;
            srcCursorLevelImageOrOffset = cursorOrStrideOrCount;
            dstOrSrcCursorOrColumns = cursorOrColumnsOrSkipBytes;
          } while (columnsRemaining3 != 0);
        }
        dstOrSrcCursorOrColumns = cursorOrColumnsOrSkipBytes + bytesPerPixel;
        (*filter2D)(cursorOrColumnsOrSkipBytes,cursorOrStrideOrCount - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        srcCursorLevelImageOrOffset = (cursorOrStrideOrCount - bytesPerPixel) + bytesPerPixel * 2 + rowPadBytes;
      }
      cursorOrStrideOrCount = pixelPairBytes;
      if (0 < (int)srcThenDestInteriorHeight) {
        cursorOrColumnsOrSkipBytes = rowPadBytes + rowPixelsStrideOrCursor;
        typeBorderDepthOrRowCount = srcThenDestInteriorHeight;
        do {
          srcCursor3 = srcCursorLevelImageOrOffset;
          dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns;
          if (!(bool)(savedCrHighByte >> 5 & 1)) {
            dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
            srcCursor3 = srcCursorLevelImageOrOffset + bytesPerPixel;
            (*filter2D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor);
          }
          srcCursorLevelImageOrOffset = srcCursor3;
          dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
          dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
          if (0 < srcThenDestInteriorWidth) {
            do {
              dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns2 + bytesPerPixel;
              srcCursor3 = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
              (*filter2D)(dstOrSrcCursorOrColumns2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowPixelsStrideOrCursor);
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
              srcCursorLevelImageOrOffset = srcCursor3;
              dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
            } while (dstOrSrcCursorOrColumns != 0);
          }
          dstOrSrcCursorOrColumns = dstOrSrcCursorOrSkipBytes;
          if (!(bool)(savedCrHighByte >> 5 & 1)) {
            srcCursorLevelImageOrOffset = srcCursor3 - bytesPerPixel;
            dstOrSrcCursorOrColumns = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
            srcCursor3 = srcCursorLevelImageOrOffset + cursorOrStrideOrCount;
            (*filter2D)(dstOrSrcCursorOrSkipBytes,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor);
          }
          typeBorderDepthOrRowCount = typeBorderDepthOrRowCount - 1;
          srcCursorLevelImageOrOffset = srcCursor3 + cursorOrColumnsOrSkipBytes;
        } while (typeBorderDepthOrRowCount != 0);
      }
      if (!(bool)(savedCrHighByte >> 5 & 1)) {
        cursorOrStrideOrCount = dstOrSrcCursorOrColumns + bytesPerPixel;
        rowPixelsStrideOrCursor = (srcCursorLevelImageOrOffset - rowBytes) + bytesPerPixel;
        (*filter2D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
        if (0 < srcThenDestInteriorWidth) {
          srcCursorLevelImageOrOffset = rowPixelsStrideOrCursor;
          cursorOrColumnsOrSkipBytes = srcThenDestInteriorWidth;
          dstCursor3 = cursorOrStrideOrCount;
          do {
            cursorOrStrideOrCount = dstCursor3 + bytesPerPixel;
            rowPixelsStrideOrCursor = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
            (*filter2D)(dstCursor3,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes);
            cursorOrColumnsOrSkipBytes = cursorOrColumnsOrSkipBytes + -1;
            srcCursorLevelImageOrOffset = rowPixelsStrideOrCursor;
            dstCursor3 = cursorOrStrideOrCount;
          } while (cursorOrColumnsOrSkipBytes != 0);
        }
        (*filter2D)(cursorOrStrideOrCount,rowPixelsStrideOrCursor - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes);
      }
      destWidth = *(ushort *)(destLevelRecord + 200);
      incomingR10 = 0;
      typeBorderDepthOrRowCount = 1;
      uVar6 = *(ushort *)(destLevelRecord + 0xca);
LAB_000fb8d8:
      destHeight = (uint)uVar6;
      incomingR8 = borderCopy;
      srcCursorLevelImageOrOffset = borderCopy;
LAB_000fb8dc:
      lastLevelThenLevelArg = nextLevel;
      _gleModifyPluginTextureLevel
                (iStack00000018,iStack0000001c,destLevelRecord + 0xc4,iStack00000020,nextLevel,incomingR8,srcCursorLevelImageOrOffset,
                 incomingR10,(uint)destWidth,destHeight,typeBorderDepthOrRowCount);
    }
    else if (isThreeDimensional) {
      if (dimensions == 3) {
        savedCrHighByte = (byte)(savedCrFields3 >> 0x18);
        if (!(bool)(savedCrHighByte >> 5 & 1)) {
          dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrColumns + bytesPerPixel;
          dstOrSrcCursorOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel;
          (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            srcCursorLevelImageOrOffset = dstOrSrcCursorOrSkipBytes;
            dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
            dstCursor2 = dstOrSrcCursorOrColumns2;
            do {
              dstOrSrcCursorOrColumns2 = dstCursor2 + bytesPerPixel;
              dstOrSrcCursorOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
              (*filter3D)(dstCursor2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
              srcCursorLevelImageOrOffset = dstOrSrcCursorOrSkipBytes;
              dstCursor2 = dstOrSrcCursorOrColumns2;
            } while (dstOrSrcCursorOrColumns != 0);
          }
          pixelPairBytesCopy5 = pixelPairBytesCopy1;
          dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns2 + bytesPerPixel;
          srcCursorLevelImageOrOffset = (dstOrSrcCursorOrSkipBytes - bytesPerPixel) + pixelPairBytesCopy1;
          (*filter3D)(dstOrSrcCursorOrColumns2,dstOrSrcCursorOrSkipBytes - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + rowPadBytes;
          if (0 < (int)srcThenDestInteriorHeight) {
            srcPixelAdvance3 = bytesPerPixel + pixelStep;
            dstOrSrcCursorOrSkipBytes = rowPadBytes + rowPixelsStrideOrCursor;
            typeBorderDepthOrRowCount = srcThenDestInteriorHeight;
            do {
              dstCursor = dstOrSrcCursorOrColumns + bytesPerPixel;
              dstOrSrcCursor = srcCursorLevelImageOrOffset + bytesPerPixel;
              (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,sliceBytes);
              srcCursorLevelImageOrOffset = srcPixelAdvance3;
              dstOrSrcCursorOrColumns = dstOrSrcCursor;
              dstOrSrcCursorOrColumns2 = srcThenDestInteriorWidth;
              dstCursor2 = dstCursor;
              if (0 < srcThenDestInteriorWidth) {
                do {
                  dstCursor = dstCursor2 + bytesPerPixel;
                  dstOrSrcCursor = dstOrSrcCursorOrColumns + srcCursorLevelImageOrOffset;
                  (*filter3D)(dstCursor2,dstOrSrcCursorOrColumns,levelRecordThenComponentCount,pixelStep,rowPixelsStrideOrCursor,sliceBytes);
                  dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrColumns2 + -1;
                  dstOrSrcCursorOrColumns = dstOrSrcCursor;
                  dstCursor2 = dstCursor;
                } while (dstOrSrcCursorOrColumns2 != 0);
              }
              dstOrSrcCursorOrColumns = dstCursor + bytesPerPixel;
              srcCursorLevelImageOrOffset = (dstOrSrcCursor - bytesPerPixel) + pixelPairBytesCopy5;
              (*filter3D)(dstCursor,dstOrSrcCursor - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,sliceBytes);
              typeBorderDepthOrRowCount = typeBorderDepthOrRowCount - 1;
              srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + dstOrSrcCursorOrSkipBytes;
            } while (typeBorderDepthOrRowCount != 0);
          }
          dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrColumns + bytesPerPixel;
          dstOrSrcCursorOrSkipBytes = (srcCursorLevelImageOrOffset - rowBytes) + bytesPerPixel;
          (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            srcCursorLevelImageOrOffset = dstOrSrcCursorOrSkipBytes;
            dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
            dstCursor2 = dstOrSrcCursorOrColumns2;
            do {
              dstOrSrcCursorOrColumns2 = dstCursor2 + bytesPerPixel;
              dstOrSrcCursorOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
              (*filter3D)(dstCursor2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
              srcCursorLevelImageOrOffset = dstOrSrcCursorOrSkipBytes;
              dstCursor2 = dstOrSrcCursorOrColumns2;
            } while (dstOrSrcCursorOrColumns != 0);
          }
          dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns2 + bytesPerPixel;
          srcCursorLevelImageOrOffset = (dstOrSrcCursorOrSkipBytes - bytesPerPixel) + pixelPairBytesCopy5;
          (*filter3D)(dstOrSrcCursorOrColumns2,dstOrSrcCursorOrSkipBytes - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + rowPadBytes + rowBytes + cursorOrColumnsOrSkipBytes;
        }
        if (0 < (int)srcThenDestInteriorDepth) {
          sliceSkipBytes = cursorOrColumnsOrSkipBytes + cursorOrStrideOrCount;
          rowSkipBytes5 = rowPadBytes + rowPixelsStrideOrCursor;
          slicesRemaining = srcThenDestInteriorDepth;
          srcPixelAdvance4 = bytesPerPixel + pixelStep;
          pixelPairBytesCopy6 = pixelPairBytesCopy2;
          pixelPairBytesCopy8 = pixelPairBytesCopy4;
          do {
            if (!(bool)(savedCrHighByte >> 5 & 1)) {
              dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
              cursorOrColumnsOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel;
              (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowBytes,cursorOrStrideOrCount);
              if (0 < srcThenDestInteriorWidth) {
                srcCursorLevelImageOrOffset = cursorOrColumnsOrSkipBytes;
                dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
                dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
                do {
                  dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns2 + bytesPerPixel;
                  cursorOrColumnsOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
                  (*filter3D)(dstOrSrcCursorOrColumns2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes,cursorOrStrideOrCount);
                  dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
                  srcCursorLevelImageOrOffset = cursorOrColumnsOrSkipBytes;
                  dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
                } while (dstOrSrcCursorOrColumns != 0);
              }
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
              srcCursorLevelImageOrOffset = (cursorOrColumnsOrSkipBytes - bytesPerPixel) + pixelPairBytesCopy6 + rowPadBytes;
              (*filter3D)(dstOrSrcCursorOrSkipBytes,cursorOrColumnsOrSkipBytes - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,cursorOrStrideOrCount);
            }
            dstOrSrcCursorOrSkipBytes = srcPixelAdvance4;
            cursorOrColumnsOrSkipBytes = rowSkipBytes5;
            if (0 < (int)srcThenDestInteriorHeight) {
              pixelPairBytesCopy7 = pixelPairBytesCopy8;
              typeBorderDepthOrRowCount = srcThenDestInteriorHeight;
              do {
                dstOrSrcCursorOrColumns2 = srcCursorLevelImageOrOffset;
                dstCursor2 = dstOrSrcCursorOrColumns;
                if (!(bool)(savedCrHighByte >> 5 & 1)) {
                  dstCursor2 = dstOrSrcCursorOrColumns + bytesPerPixel;
                  dstOrSrcCursorOrColumns2 = srcCursorLevelImageOrOffset + bytesPerPixel;
                  (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,cursorOrStrideOrCount);
                }
                srcCursorLevelImageOrOffset = dstOrSrcCursorOrColumns2;
                dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
                dstOrSrcCursor = dstCursor2;
                if (0 < srcThenDestInteriorWidth) {
                  do {
                    dstCursor2 = dstOrSrcCursor + bytesPerPixel;
                    dstOrSrcCursorOrColumns2 = srcCursorLevelImageOrOffset + dstOrSrcCursorOrSkipBytes;
                    (*filter3D)(dstOrSrcCursor,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowPixelsStrideOrCursor,cursorOrStrideOrCount);
                    dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
                    srcCursorLevelImageOrOffset = dstOrSrcCursorOrColumns2;
                    dstOrSrcCursor = dstCursor2;
                  } while (dstOrSrcCursorOrColumns != 0);
                }
                dstOrSrcCursorOrColumns = dstCursor2;
                if (!(bool)(savedCrHighByte >> 5 & 1)) {
                  srcCursorLevelImageOrOffset = dstOrSrcCursorOrColumns2 - bytesPerPixel;
                  dstOrSrcCursorOrColumns = dstCursor2 + bytesPerPixel;
                  dstOrSrcCursorOrColumns2 = srcCursorLevelImageOrOffset + pixelPairBytesCopy7;
                  (*filter3D)(dstCursor2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,cursorOrStrideOrCount);
                }
                typeBorderDepthOrRowCount = typeBorderDepthOrRowCount - 1;
                srcCursorLevelImageOrOffset = dstOrSrcCursorOrColumns2 + cursorOrColumnsOrSkipBytes;
              } while (typeBorderDepthOrRowCount != 0);
            }
            if (!(bool)(savedCrHighByte >> 5 & 1)) {
              dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
              cursorOrColumnsOrSkipBytes = (srcCursorLevelImageOrOffset - rowBytes) + bytesPerPixel;
              (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,cursorOrStrideOrCount);
              if (0 < srcThenDestInteriorWidth) {
                srcCursorLevelImageOrOffset = cursorOrColumnsOrSkipBytes;
                dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
                dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
                do {
                  dstOrSrcCursorOrSkipBytes = dstOrSrcCursorOrColumns2 + bytesPerPixel;
                  cursorOrColumnsOrSkipBytes = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
                  (*filter3D)(dstOrSrcCursorOrColumns2,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes,cursorOrStrideOrCount);
                  dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
                  srcCursorLevelImageOrOffset = cursorOrColumnsOrSkipBytes;
                  dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrSkipBytes;
                } while (dstOrSrcCursorOrColumns != 0);
              }
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
              srcCursorLevelImageOrOffset = (cursorOrColumnsOrSkipBytes - bytesPerPixel) + pixelPairBytesCopy6;
              (*filter3D)(dstOrSrcCursorOrSkipBytes,cursorOrColumnsOrSkipBytes - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,cursorOrStrideOrCount);
              srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + rowPadBytes + rowBytes;
            }
            slicesRemaining = slicesRemaining - 1;
            srcCursorLevelImageOrOffset = srcCursorLevelImageOrOffset + sliceSkipBytes;
          } while (slicesRemaining != 0);
        }
        if (!(bool)(savedCrHighByte >> 5 & 1)) {
          cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrColumns + bytesPerPixel;
          cursorOrStrideOrCount = (srcCursorLevelImageOrOffset - sliceBytes) + bytesPerPixel;
          (*filter3D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset - sliceBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            srcCursorLevelImageOrOffset = cursorOrStrideOrCount;
            dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
            dstOrSrcCursorOrSkipBytes = cursorOrColumnsOrSkipBytes;
            do {
              cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
              cursorOrStrideOrCount = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
              (*filter3D)(dstOrSrcCursorOrSkipBytes,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
              srcCursorLevelImageOrOffset = cursorOrStrideOrCount;
              dstOrSrcCursorOrSkipBytes = cursorOrColumnsOrSkipBytes;
            } while (dstOrSrcCursorOrColumns != 0);
          }
          srcCursorLevelImageOrOffset = pixelPairBytesCopy3;
          dstOrSrcCursorOrSkipBytes = cursorOrColumnsOrSkipBytes + bytesPerPixel;
          dstOrSrcCursorOrColumns = (cursorOrStrideOrCount - bytesPerPixel) + pixelPairBytesCopy3;
          (*filter3D)(cursorOrColumnsOrSkipBytes,cursorOrStrideOrCount - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + rowPadBytes;
          if (0 < (int)srcThenDestInteriorHeight) {
            cursorOrStrideOrCount = rowPadBytes + rowPixelsStrideOrCursor;
            typeBorderDepthOrRowCount = srcThenDestInteriorHeight;
            do {
              dstCursor2 = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
              dstOrSrcCursorOrColumns2 = dstOrSrcCursorOrColumns + bytesPerPixel;
              (*filter3D)(dstOrSrcCursorOrSkipBytes,dstOrSrcCursorOrColumns,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,sliceBytes);
              cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrColumns2;
              dstOrSrcCursorOrColumns = srcThenDestInteriorWidth;
              dstOrSrcCursorOrSkipBytes = dstCursor2;
              if (0 < srcThenDestInteriorWidth) {
                do {
                  dstCursor2 = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
                  dstOrSrcCursorOrColumns2 = cursorOrColumnsOrSkipBytes + bytesPerPixel + pixelStep;
                  (*filter3D)(dstOrSrcCursorOrSkipBytes,cursorOrColumnsOrSkipBytes,levelRecordThenComponentCount,pixelStep,rowPixelsStrideOrCursor,sliceBytes);
                  dstOrSrcCursorOrColumns = dstOrSrcCursorOrColumns + -1;
                  cursorOrColumnsOrSkipBytes = dstOrSrcCursorOrColumns2;
                  dstOrSrcCursorOrSkipBytes = dstCursor2;
                } while (dstOrSrcCursorOrColumns != 0);
              }
              dstOrSrcCursorOrSkipBytes = dstCursor2 + bytesPerPixel;
              dstOrSrcCursorOrColumns = (dstOrSrcCursorOrColumns2 - bytesPerPixel) + srcCursorLevelImageOrOffset + cursorOrStrideOrCount;
              (*filter3D)(dstCursor2,dstOrSrcCursorOrColumns2 - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowPixelsStrideOrCursor,sliceBytes);
              typeBorderDepthOrRowCount = typeBorderDepthOrRowCount - 1;
            } while (typeBorderDepthOrRowCount != 0);
          }
          rowPixelsStrideOrCursor = dstOrSrcCursorOrSkipBytes + bytesPerPixel;
          srcCursorLevelImageOrOffset = (dstOrSrcCursorOrColumns - rowBytes) + bytesPerPixel;
          (*filter3D)(dstOrSrcCursorOrSkipBytes,dstOrSrcCursorOrColumns - rowBytes,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
          if (0 < srcThenDestInteriorWidth) {
            cursorOrStrideOrCount = srcCursorLevelImageOrOffset;
            cursorOrColumnsOrSkipBytes = srcThenDestInteriorWidth;
            dstOrSrcCursorOrColumns = rowPixelsStrideOrCursor;
            do {
              rowPixelsStrideOrCursor = dstOrSrcCursorOrColumns + bytesPerPixel;
              srcCursorLevelImageOrOffset = cursorOrStrideOrCount + bytesPerPixel + pixelStep;
              (*filter3D)(dstOrSrcCursorOrColumns,cursorOrStrideOrCount,levelRecordThenComponentCount,pixelStep,rowBytes,sliceBytes);
              cursorOrColumnsOrSkipBytes = cursorOrColumnsOrSkipBytes + -1;
              cursorOrStrideOrCount = srcCursorLevelImageOrOffset;
              dstOrSrcCursorOrColumns = rowPixelsStrideOrCursor;
            } while (cursorOrColumnsOrSkipBytes != 0);
          }
          (*filter3D)(rowPixelsStrideOrCursor,srcCursorLevelImageOrOffset - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel,rowBytes,sliceBytes);
        }
        destWidth = *(ushort *)(destLevelRecord + 200);
        uVar6 = *(ushort *)(destLevelRecord + 0xca);
        typeBorderDepthOrRowCount = (uint)*(ushort *)(destLevelRecord + 0xcc);
        incomingR10 = borderCopy;
        goto LAB_000fb8d8;
      }
    }
    else if (isOneDimensional) {
      savedCrHighByte = (byte)(savedCrFields >> 0x18);
      rowPixelsStrideOrCursor = srcCursorLevelImageOrOffset;
      dstCursor4 = dstOrSrcCursorOrColumns;
      if (!(bool)(savedCrHighByte >> 5 & 1)) {
        dstCursor4 = dstOrSrcCursorOrColumns + bytesPerPixel;
        rowPixelsStrideOrCursor = srcCursorLevelImageOrOffset + bytesPerPixel;
        (*filter1D)(dstOrSrcCursorOrColumns,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,bytesPerPixel);
      }
      if (0 < srcThenDestInteriorWidth) {
        srcCursorLevelImageOrOffset = rowPixelsStrideOrCursor;
        cursorOrStrideOrCount = srcThenDestInteriorWidth;
        cursorOrColumnsOrSkipBytes = dstCursor4;
        do {
          dstCursor4 = cursorOrColumnsOrSkipBytes + bytesPerPixel;
          rowPixelsStrideOrCursor = srcCursorLevelImageOrOffset + bytesPerPixel + pixelStep;
          (*filter1D)(cursorOrColumnsOrSkipBytes,srcCursorLevelImageOrOffset,levelRecordThenComponentCount,pixelStep);
          cursorOrStrideOrCount = cursorOrStrideOrCount + -1;
          srcCursorLevelImageOrOffset = rowPixelsStrideOrCursor;
          cursorOrColumnsOrSkipBytes = dstCursor4;
        } while (cursorOrStrideOrCount != 0);
      }
      if (!(bool)(savedCrHighByte >> 5 & 1)) {
        (*filter1D)(dstCursor4,rowPixelsStrideOrCursor - bytesPerPixel,levelRecordThenComponentCount,bytesPerPixel);
      }
      destWidth = *(ushort *)(destLevelRecord + 200);
      incomingR10 = 0;
      typeBorderDepthOrRowCount = 1;
      destHeight = 1;
      incomingR8 = twiceBorder >> 1;
      srcCursorLevelImageOrOffset = 0;
      goto LAB_000fb8dc;
    }
    nextLevel = nextLevel + 1;
    srcCursorLevelImageOrOffset = destLevelRecord + 0xc4;
  } while( true );
}

/* _gleGenerateEmptyMipmaps @ 0xfbb00 (868 bytes) */
int _gleGenerateEmptyMipmaps(glContext, textureObject, face, baseLevel, lastLevel, levelData, levelFlagBits)
  undefined4 glContext;
  int textureObject;
  int face;
  int baseLevel;
  int lastLevel;
  undefined4 levelData;
  undefined4 levelFlagBits;
{
  byte levelFlagByte;
  undefined2 previousLevelType;
  ushort targetKind;
  uint border;
  uint depthWithBorder;
  short heightWithBorder;
  short rowWidth;
  int baseOffsetThenPreviousLevel;
  undefined4 componentCount;
  undefined4 returnValue;
  int faceBaseThenNextLevel;
  int newLevel;
  int levelIndex;
  uint levelHeight;
  uint dimensions;
  uint levelDepth;
  uint levelWidth;
  int borderDouble;
  int clearLevel;
  
  targetKind = *(ushort *)(textureObject + 0x24) & 0xf;
  if (targetKind == 1) {
    dimensions = 3;
  }
  else {
    if (targetKind < 2) {
      if ((*(ushort *)(textureObject + 0x24) & 0xf) != 0) {
        return glContext;
      }
    }
    else if (targetKind != 3) {
      if (targetKind != 4) {
        return glContext;
      }
      dimensions = 1;
      goto LAB_000fbb7c;
    }
    dimensions = 2;
  }
LAB_000fbb7c:
  faceBaseThenNextLevel = textureObject + face * 0x168;
  baseOffsetThenPreviousLevel = faceBaseThenNextLevel + baseLevel * 0x18;
  componentCount = _gleComponents((uint)*(ushort *)(baseOffsetThenPreviousLevel + 0xd4));
  border = (uint)*(byte *)(baseOffsetThenPreviousLevel + 0xce);
  borderDouble = border * 2;
  levelHeight = (uint)*(ushort *)(baseOffsetThenPreviousLevel + 0xca);
  levelWidth = (uint)*(ushort *)(baseOffsetThenPreviousLevel + 200) + border * -2;
  if (1 < dimensions) {
    levelHeight = levelHeight + border * -2;
  }
  levelDepth = (uint)*(ushort *)(baseOffsetThenPreviousLevel + 0xcc);
  if (2 < dimensions) {
    levelDepth = levelDepth + border * -2;
  }
  levelIndex = baseLevel + 1;
  returnValue = componentCount;
  faceBaseThenNextLevel = levelIndex * 0x18 + faceBaseThenNextLevel + 0xc4;
  baseOffsetThenPreviousLevel = baseOffsetThenPreviousLevel + 0xc4;
  for (; (((newLevel = faceBaseThenNextLevel, 1 < (int)levelWidth || (1 < (int)levelHeight)) || (1 < (int)levelDepth)) &&
         (levelIndex <= lastLevel)); levelIndex = levelIndex + 1) {
    if ((*(byte *)(newLevel + 0xb) & 0x20) != 0) {
      _gleDeletePluginTextureLevel(glContext,textureObject,newLevel,face,levelIndex);
      if (*(int *)(newLevel + 0x14) != 0) {
        levelFlagByte = *(byte *)(newLevel + 0xb);
        if ((levelFlagByte & 1) == 0) {
          _gleFreeTextureLevel(glContext,textureObject,newLevel);
          levelFlagByte = *(byte *)(newLevel + 0xb);
        }
        else {
          *(undefined4 *)(newLevel + 0x14) = 0;
        }
        *(byte *)(newLevel + 0xb) = levelFlagByte & 0xef;
      }
      *(byte *)(newLevel + 0xb) = *(byte *)(newLevel + 0xb) & 0xdf;
    }
    levelWidth = (int)levelWidth >> 1 | (uint)((int)levelWidth >> 1 == 0);
    levelHeight = (int)levelHeight >> 1 | (uint)((int)levelHeight >> 1 == 0);
    levelDepth = (int)levelDepth >> 1 | (uint)((int)levelDepth >> 1 == 0);
    *(short *)(newLevel + 4) = (short)levelWidth + (short)borderDouble;
    heightWithBorder = (short)levelHeight;
    if (1 < dimensions) {
      heightWithBorder = heightWithBorder + (short)borderDouble;
    }
    *(short *)(newLevel + 6) = heightWithBorder;
    depthWithBorder = levelDepth;
    if (2 < dimensions) {
      depthWithBorder = levelDepth + borderDouble;
    }
    previousLevelType = *(undefined2 *)(baseOffsetThenPreviousLevel + 0x12);
    *(undefined2 *)(newLevel + 0x10) = *(undefined2 *)(baseOffsetThenPreviousLevel + 0x10);
    *(short *)(newLevel + 8) = (short)depthWithBorder;
    *(char *)(newLevel + 10) = (char)(borderDouble >> 1);
    *(undefined2 *)(newLevel + 0x12) = previousLevelType;
    *(byte *)(newLevel + 0xb) = (byte)levelFlagBits | 0x20;
    *(undefined4 *)(newLevel + 0x14) = levelData;
    if ((*(ushort *)(textureObject + 0x24) & 0x100) == 0) {
      if (*(short *)(newLevel + 0x10) == -0x7a47) {
        rowWidth = *(short *)(newLevel + 4);
        if (rowWidth == 1) {
          rowWidth = 2;
        }
      }
      else {
        rowWidth = *(short *)(newLevel + 4);
      }
      *(short *)(newLevel + 0xc) = rowWidth;
      *(undefined2 *)(newLevel + 0xe) = *(undefined2 *)(newLevel + 6);
    }
    else {
      *(undefined2 *)(newLevel + 0xc) = 0;
      *(undefined2 *)(newLevel + 0xe) = 0;
    }
    returnValue = _gleCreatePluginTextureLevel(glContext,textureObject,newLevel,face,levelIndex,componentCount);
    faceBaseThenNextLevel = newLevel + 0x18;
    baseOffsetThenPreviousLevel = newLevel;
  }
  if (0xe < lastLevel) {
    lastLevel = 0xe;
  }
  if (levelIndex <= lastLevel) {
    clearLevel = levelIndex * 0x18 + textureObject + face * 0x168 + 0xc4;
    do {
      levelFlagByte = *(byte *)(clearLevel + 0xb);
      if ((levelFlagByte & 0x20) != 0) {
        returnValue = _gleDeletePluginTextureLevel(glContext,textureObject,clearLevel,face,levelIndex);
        if (*(int *)(clearLevel + 0x14) != 0) {
          levelFlagByte = *(byte *)(clearLevel + 0xb);
          if ((levelFlagByte & 1) == 0) {
            returnValue = _gleFreeTextureLevel(glContext,textureObject,clearLevel);
            levelFlagByte = *(byte *)(clearLevel + 0xb);
          }
          else {
            *(undefined4 *)(clearLevel + 0x14) = 0;
          }
          *(byte *)(clearLevel + 0xb) = levelFlagByte & 0xef;
        }
        *(byte *)(clearLevel + 0xb) = *(byte *)(clearLevel + 0xb) & 0xdf;
        levelFlagByte = *(byte *)(clearLevel + 0xb);
      }
      levelIndex = levelIndex + 1;
      *(byte *)(clearLevel + 0xb) = levelFlagByte & 0xf8;
      *(undefined2 *)(clearLevel + 4) = 0;
      *(undefined2 *)(clearLevel + 6) = 0;
      *(undefined2 *)(clearLevel + 8) = 0;
      *(undefined1 *)(clearLevel + 10) = 0;
      *(undefined2 *)(clearLevel + 0x10) = 0;
      *(undefined2 *)(clearLevel + 0x12) = 0;
      *(undefined2 *)(clearLevel + 0xc) = 0;
      *(undefined2 *)(clearLevel + 0xe) = 0;
      clearLevel = clearLevel + 0x18;
    } while (levelIndex <= lastLevel);
  }
  return returnValue;
}

/* _gleGenMipmapsToLevel @ 0xfbe64 (384 bytes) */
int _gleGenMipmapsToLevel(glContext, textureObject, faceIndex, level, maxLevelLimit, useMaxLevelByte)
  int glContext;
  int textureObject;
  int faceIndex;
  int level;
  undefined4 maxLevelLimit;
  int useMaxLevelByte;
{
  int levelRecord;
  int nextLevel;
  byte *levelFlagsPtr;
  int pluginResult;
  int remaining;
  uint lastLevel;
  int faceOffset;
  
  if ((*(ushort *)(textureObject + 0x24) & 0xf) != 2) {
    faceOffset = faceIndex * 0x168;
    levelRecord = textureObject + faceOffset + level * 0x18;
    ((int (*)())_gleGenerateEmptyMipmaps)(glContext,textureObject,faceIndex,level,maxLevelLimit,0,0);
    if ((*(byte *)(faceOffset + level * 0x18 + textureObject + 0xcf) & 0x20) == 0) {
      return 0;
    }
    pluginResult = (**(code **)(glContext + 0x4714))
                      (*(undefined4 *)(glContext + 0x4688),
                       *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),faceIndex);
    if (pluginResult != 0) {
      *(undefined4 *)(textureObject + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (useMaxLevelByte == 0) {
        lastLevel = (uint)*(short *)(textureObject + 0x62);
      }
      else {
        lastLevel = (uint)*(byte *)(textureObject + 0x87);
      }
      if (0xf < (int)lastLevel) {
        lastLevel = 0xf;
      }
      nextLevel = level + 1;
      if (nextLevel <= (int)lastLevel) {
        remaining = (lastLevel + 1) - nextLevel;
        levelFlagsPtr = (byte *)(nextLevel * 0x18 + faceOffset + textureObject + 0xcf);
        do {
          *levelFlagsPtr = *levelFlagsPtr | 0x40;
          levelFlagsPtr = levelFlagsPtr + 0x18;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
      return 1;
    }
    if ((*(ushort *)(textureObject + 0x24) & 0x100) == 0) {
      if (*(int *)(levelRecord + 0xd8) == 0) {
        _gleAllocateTextureLevel(glContext,textureObject,levelRecord + 0xc4);
      }
      _gleSynchronizePluginTextureLevels(glContext,textureObject);
      ((void (*)())_gleGenerateMipmapData)(glContext,textureObject,faceIndex,level,maxLevelLimit);
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
double _gleHalfFloatToFloat(uint halfBits)
{
  float floatValue;
  uint mantissa;
  uint exponentFieldThenFloatExponentBits;
  uint signBit;
  
  exponentFieldThenFloatExponentBits = halfBits & 0x7c00;
  mantissa = halfBits & 0x3ff;
  signBit = (halfBits & 0x8000) << 0x10;
  if (exponentFieldThenFloatExponentBits == 0x7c00) {
    floatValue = GH_U2F((unsigned int)((signBit | 0x7f800000)));
    if (mantissa != 0) {
      floatValue = GH_U2F((unsigned int)((signBit | 0x7fffffff)));
    }
  }
  else {
    if (exponentFieldThenFloatExponentBits == 0) {
      exponentFieldThenFloatExponentBits = 0;
      if (mantissa != 0) {
        exponentFieldThenFloatExponentBits = 0x38000000;
        while (mantissa = mantissa << 1, (mantissa & 0x400) == 0) {
          exponentFieldThenFloatExponentBits = exponentFieldThenFloatExponentBits - 0x800000;
        }
        mantissa = mantissa & 0x3ff;
      }
    }
    else {
      exponentFieldThenFloatExponentBits = exponentFieldThenFloatExponentBits * 0x2000 + 0x38000000;
    }
    floatValue = GH_U2F((unsigned int)((signBit | exponentFieldThenFloatExponentBits | mantissa << 0xd)));
  }
  return (double)floatValue;
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
  int activeUnitThenTargetObject;
  
  activeUnitThenTargetObject = *(int *)(glContext + 0x53d4);
  if (target == 0x80d2) {
    activeUnitThenTargetObject = *(int *)(glContext + 0x52c4);
    goto LAB_000fc364;
  }
  if (target < 0x80d3) {
    if (target == 0x8064) {
      activeUnitThenTargetObject = *(int *)(glContext + 0x52b4);
    }
    else {
      if (target < 0x8065) {
        if (target != 0xde1) {
          if (target < 0xde2) {
            if (target == 0xde0) {
              activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 0x14 + glContext + 0x5164);
              goto LAB_000fc320;
            }
          }
          else if (target == 0x8063) {
            activeUnitThenTargetObject = *(int *)(glContext + 0x52b8);
            goto LAB_000fc364;
          }
          return 0;
        }
        activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 0x14 + glContext + 0x5160);
        goto LAB_000fc320;
      }
      if (target == 0x8070) {
        activeUnitThenTargetObject = *(int *)(glContext + 0x52ac);
      }
      else {
        if (target < 0x8071) {
          if (target != 0x806f) {
            return 0;
          }
          activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 0x14 + glContext + 0x5158);
          goto LAB_000fc320;
        }
        if (target == 0x80d0) {
          activeUnitThenTargetObject = *(int *)(glContext + 0x52bc);
        }
        else {
          if (target != 0x80d1) {
            return 0;
          }
          activeUnitThenTargetObject = *(int *)(glContext + 0x52c0);
        }
      }
    }
LAB_000fc364:
    return activeUnitThenTargetObject + 0x10;
  }
  if (target != 0x84f5) {
    if (target < 0x84f6) {
      if (target == 0x80d4) {
        activeUnitThenTargetObject = *(int *)(glContext + 0x52cc);
      }
      else if (target < 0x80d4) {
        activeUnitThenTargetObject = *(int *)(glContext + 0x52c8);
      }
      else {
        if (target != 0x80d5) {
          if (target != 0x81fb) {
            return 0;
          }
          activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 4 + glContext + 0x52d4);
          goto LAB_000fc320;
        }
        activeUnitThenTargetObject = *(int *)(glContext + 0x52d0);
      }
      goto LAB_000fc364;
    }
    if (target == 0x8513) {
      activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 0x14 + glContext + 0x5154);
      goto LAB_000fc320;
    }
    if (target < 0x8514) {
      if (target != 0x84f7) {
        return 0;
      }
      activeUnitThenTargetObject = *(int *)(glContext + 0x52b0);
      goto LAB_000fc364;
    }
    if (target == 0x851b) {
      activeUnitThenTargetObject = *(int *)(glContext + 0x52a8);
      goto LAB_000fc364;
    }
    if (target != 0x85b3) {
      return 0;
    }
  }
  activeUnitThenTargetObject = *(int *)(activeUnitThenTargetObject * 0x14 + glContext + 0x515c);
LAB_000fc320:
  return activeUnitThenTargetObject + 0x10;
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
  int *rendererDispatch;
  undefined4 *rendererHandlePtr;
  int sharedState;
  int rendererSlotCursor;
  int defaultTexture;
  undefined4 rendererName;
  int *nextBucket;
  int *rendererDispatch2;
  uint loopIndex;
  uint defaultTexIndex;
  uint loopIndex2;
  int *hashNode;
  int *defaultTexCursor;
  undefined4 *nameCursor;
  int rendererCursor;
  
  sharedState = *(int *)(glContext + 0x5148);
  hashNode = (int *)(sharedState + 0x2008);
  do {
    nextBucket = hashNode + 1;
    for (hashNode = (int *)*hashNode; hashNode != (int *)0x0; hashNode = (int *)*hashNode) {
      if (((hashNode[2] == 1) && ((*(ushort *)(hashNode + 0xd) & 0x3c00) != 0x800)) &&
         (loopIndex = 0, *(char *)(glContext + 0x85a4) != '\0')) {
        nameCursor = hashNode + 4;
        rendererCursor = glContext + 0x10000;
        do {
          rendererDispatch = (int *)(rendererCursor + -0x777c);
          loopIndex = loopIndex + 1;
          rendererName = *nameCursor;
          nameCursor = nameCursor + 1;
          rendererHandlePtr = (undefined4 *)(rendererCursor + -0x7a54);
          rendererCursor = rendererCursor + 0x2e0;
          (**(code **)(*rendererDispatch + 0x170))(*rendererHandlePtr,rendererName);
        } while (loopIndex < *(byte *)(glContext + 0x85a4));
      }
    }
    hashNode = nextBucket;
  } while (nextBucket <= (int *)(sharedState + 0x3004));
  defaultTexIndex = 0;
  defaultTexCursor = (int *)(glContext + 0x5294);
  do {
    defaultTexture = *defaultTexCursor;
    defaultTexCursor = defaultTexCursor + 1;
    if (((defaultTexture != 0) && (*(int *)(defaultTexture + 8) == 1)) &&
       (((*(ushort *)(defaultTexture + 0x34) & 0x3c00) != 0x800 &&
        (loopIndex2 = 0, *(char *)(glContext + 0x85a4) != '\0')))) {
      nameCursor = (undefined4 *)(defaultTexture + 0x10);
      rendererSlotCursor = glContext + 0x10000;
      do {
        rendererDispatch2 = (int *)(rendererSlotCursor + -0x777c);
        loopIndex2 = loopIndex2 + 1;
        rendererName = *nameCursor;
        nameCursor = nameCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch2 + 0x170))(*rendererHandlePtr,rendererName);
      } while (loopIndex2 < *(byte *)(glContext + 0x85a4));
    }
    defaultTexIndex = defaultTexIndex + 1;
  } while (defaultTexIndex < 5);
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

