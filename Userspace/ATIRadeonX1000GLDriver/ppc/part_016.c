#include "decls.h"

/* gld_buildActiveUnitList @ 0xa7d10 (344 bytes) */
int gld_buildActiveUnitList(glContext)
  int glContext;
{
  int listByteOffsetMasked;
  uint enabledUnitBits;
  uint unitsLeft;
  byte unitCount;
  int listByteOffset;
  int activeUnitCount;
  uint unitsLeftMasked;
  int baseCost;
  uint ctx44Word;
  int loopIndex;
  int unitShadowCursor;
  uint loopIndex2;
  
  ctx44Word = *(uint *)(glContext + 0x44);
  if ((((int)ctx44Word < 0) &&
      (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(glContext + 4) + 0x10)) == -0x7e06)) ||
     (baseCost = 0, (ctx44Word & 0xa10000) != 0)) {
    baseCost = 1;
  }
  if ((ctx44Word & 0x1000000) != 0) {
    baseCost = 5;
  }
  if ((ctx44Word & 0x20000) == 0) {
    unitCount = *(byte *)(glContext + 0x2b);
    if (unitCount != 0) {
      unitsLeft = (uint)unitCount;
      activeUnitCount = 0;
      loopIndex = 0;
      unitShadowCursor = glContext;
      if ((unitCount == 0) || (unitsLeft == 0x80000000)) {
        unitsLeft = 1;
      }
      do {
        if (*(int *)(((unsigned char *)0x000013f8) + unitShadowCursor) != 0) {
          listByteOffset = activeUnitCount * 4;
          activeUnitCount = activeUnitCount + 1;
          *(int *)(listByteOffset + glContext + 0x1824) = loopIndex;
        }
        loopIndex = loopIndex + 1;
        unitShadowCursor = unitShadowCursor + 4;
        unitsLeft = unitsLeft - 1;
      } while (unitsLeft != 0);
LAB_000a7de8:
      activeUnitCount = activeUnitCount << 4;
      goto LAB_000a7df4;
    }
  }
  else {
    unitsLeftMasked = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
    if (unitsLeftMasked != 0) {
      activeUnitCount = 0;
      loopIndex2 = 0;
      if ((unitsLeftMasked == 0) || (unitsLeftMasked == 0x80000000)) {
        unitsLeftMasked = 1;
      }
      while( true ) {
        if ((ctx44Word & 0x2000) == 0) {
          enabledUnitBits = (int)(uint)(byte)((unsigned char *)0x00001135)[glContext] >> (loopIndex2 & 0x3f);
        }
        else {
          enabledUnitBits = (int)(uint)(byte)((unsigned char *)0x000011d3)[glContext] >> (loopIndex2 & 0x3f);
        }
        if ((enabledUnitBits & 1) != 0) {
          listByteOffsetMasked = activeUnitCount * 4;
          activeUnitCount = activeUnitCount + 1;
          *(uint *)(listByteOffsetMasked + glContext + 0x1824) = loopIndex2;
        }
        loopIndex2 = loopIndex2 + 1;
        unitsLeftMasked = unitsLeftMasked - 1;
        if (unitsLeftMasked == 0) break;
        ctx44Word = *(uint *)(glContext + 0x44);
      }
      goto LAB_000a7de8;
    }
  }
  activeUnitCount = 0;
LAB_000a7df4:
  *(int *)(glContext + 0x1804) = baseCost + activeUnitCount;
  return;
}

/* FUN_000a7e80 @ 0xa7e80 (24 bytes) */
int FUN_000a7e80(glContext)
  int glContext;
{
  *(undefined1 *)(glContext + 0x29) = 1;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x10;
  return;
}

/* FUN_000a7ea0 @ 0xa7ea0 (48 bytes) */
int FUN_000a7ea0(glContext)
  int glContext;
{
  *(undefined1 *)(glContext + 0x29) = 1;
  *(uint *)(glContext + 0x44) = *(uint *)(glContext + 0x44) & 0xefffffff;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x400;
  *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1018;
  return;
}

/* noop_a7ed0 @ 0xa7ed0 (4 bytes) */
int noop_a7ed0()
{
  return;
}

/* gld_updateTextureUnitState @ 0xa7ee0 (980 bytes) */
int gld_updateTextureUnitState(ctx, unitMask)
  int ctx;
  uint unitMask;
{
  int unitHalfOffsetBound;
  int oldTexShadow;
  int unitHalfOffset;
  int unitRegBase8Final;
  int unitRegBase12;
  int unitRegBase8Bound;
  int unitRegBase8;
  uint ctxWord278;
  int ctxPtr10;
  byte texField6b;
  byte texField6a;
  byte texField69;
  byte texField68;
  byte unitBit8;
  int unitWordOffset;
  uint samplerModeBits;
  uint newUnitWord48;
  uint oldUnitWord48;
  int boundTexture;
  int unitBit;
  ushort unitBit16;
  int ctxUnitCursor;
  uint loopIndex;
  int streamBase;
  
  if (unitMask != 0) {
    loopIndex = 0;
    streamBase = ctx + 0x240;
    ctxUnitCursor = ctx;
    do {
      if ((unitMask & 1) != 0) {
        unitWordOffset = loopIndex * 4;
        ctxWord278 = *(uint *)(ctx + 0x278);
        unitBit = 1 << (loopIndex & 0x3f);
        oldUnitWord48 = *(uint *)(unitWordOffset + streamBase + 0x48);
        unitBit16 = (ushort)unitBit;
        newUnitWord48 = oldUnitWord48 & 0xffffffe0 |
                *(uint *)(((unsigned char *)0x000031d4) + loopIndex * 0x7c + *(int *)(ctx + 0x10)) & 0x1f;
        *(ushort *)(ctx + 0x272) = unitBit16 | *(ushort *)(ctx + 0x272);
        *(uint *)(ctx + 0x278) = ctxWord278 | 0x200;
        if (oldUnitWord48 != newUnitWord48) {
          *(undefined1 *)(ctx + 0x269) = 1;
          *(ushort *)(ctx + 0x274) = unitBit16 | *(ushort *)(ctx + 0x274);
          ctxPtr10 = *(int *)(ctx + 0x10);
          if (((((unsigned char *)0x00002d48)[ctxPtr10 + 2] != '\0') && (*(int *)(ctxUnitCursor + 0x18c) != 0)) &&
             ((**(ushort **)(*(int *)(ctxUnitCursor + 0x18c) + 0x30) & 0xf) == 0)) {
            *(uint *)(ctx + 0x278) = ctxWord278 | 0x220;
            ctxPtr10 = *(int *)(ctx + 0x10);
          }
          if (((unsigned char *)0x00002e0a)[ctxPtr10] != '\0') {
            *(uint *)(ctx + 0x278) = *(uint *)(ctx + 0x278) | 0x100;
          }
          *(uint *)(unitWordOffset + streamBase + 0x48) = newUnitWord48;
          *(undefined1 *)(ctx + 0x26b5) = 1;
        }
        boundTexture = *(int *)(ctxUnitCursor + 0x18c);
        unitBit8 = (byte)unitBit;
        if (boundTexture == 0) {
          if (((unsigned char *)0x00001438)[loopIndex + streamBase] != '\0') {
            *(undefined1 *)(ctx + 0x269) = 1;
            *(ushort *)(ctx + 0x274) = unitBit16 | *(ushort *)(ctx + 0x274);
          }
          ((unsigned char *)0x00001438)[loopIndex + streamBase] = 0;
          *(undefined4 *)(((unsigned char *)0x000013f8) + unitWordOffset + streamBase) = 0;
          unitRegBase8 = loopIndex * 8 + streamBase;
          unitHalfOffset = loopIndex * 2 + streamBase;
          *(uint *)(unitRegBase8 + 0x18ac) = *(uint *)(unitRegBase8 + 0x18ac) & 0xfffffffe;
          *(ushort *)(unitHalfOffset + 0x187c) = *(ushort *)(unitHalfOffset + 0x187c) & 0x7fff;
          *(byte *)(ctx + 0x260) = *(byte *)(ctx + 0x260) & ~unitBit8;
        }
        else {
          oldTexShadow = *(int *)(((unsigned char *)0x000013f8) + unitWordOffset + streamBase);
          texField6b = *(byte *)(boundTexture + 0x6b);
          texField6a = *(byte *)(boundTexture + 0x6a);
          texField69 = *(byte *)(boundTexture + 0x69);
          samplerModeBits = *(uint *)(boundTexture + 200) >> 0x16 & 3;
          texField68 = *(byte *)(boundTexture + 0x68);
          if ((boundTexture + 0x3c != oldTexShadow) && (*(undefined1 *)(ctx + 0x269) = 1, oldTexShadow == 0)) {
            *(ushort *)(ctx + 0x274) = unitBit16 | *(ushort *)(ctx + 0x274);
          }
          ((unsigned char *)0x00001438)[loopIndex + streamBase] = 1;
          *(int *)(((unsigned char *)0x000013f8) + unitWordOffset + streamBase) = boundTexture + 0x3c;
          unitRegBase8Bound = loopIndex * 8 + streamBase;
          unitHalfOffsetBound = loopIndex * 2 + streamBase;
          *(uint *)(unitRegBase8Bound + 0x18ac) = *(uint *)(unitRegBase8Bound + 0x18ac) | 1;
          *(uint *)(unitRegBase8Bound + 0x18a8) =
               (uint)*(byte *)(boundTexture + 0x6c) << 0x1d | *(uint *)(unitRegBase8Bound + 0x18a8) & 0x1fffffff;
          *(ushort *)(unitHalfOffsetBound + 0x187c) = *(ushort *)(unitHalfOffsetBound + 0x187c) | 0x8000;
          if (*(byte *)(ctx + 0x26b) <= loopIndex) {
            *(undefined1 *)(ctx + 0x26b5) = 1;
            *(char *)(ctx + 0x26b) = (char)loopIndex + '\x01';
            *(undefined1 *)(ctx + 0x269) = 1;
            *(uint *)(ctx + 0x27c) = *(uint *)(ctx + 0x27c) | 0x400;
          }
          gld_applyAnisotropyOverride(ctx,loopIndex);
          *(undefined4 *)(boundTexture + 0x88) = *(undefined4 *)(*(int *)(boundTexture + 0x30) + 0x38);
          *(uint *)(unitRegBase8Bound + 0x18ac) =
               (texField68 & 1) << 0x14 |
               (texField69 & 7) << 0x15 |
               (texField6a & 1) << 0x13 | (texField6b & 7) << 4 | *(uint *)(unitRegBase8Bound + 0x18ac) & 0xff07ff8f;
          if (*(short *)(boundTexture + 0x74) == 0x1902) {
            *(uint *)(ctx + 0x1a48) = *(uint *)(ctx + 0x1a48) | 0x80000000;
          }
          if ((**(ushort **)(boundTexture + 0x30) & 0xf) == 2) {
            *(uint *)(ctx + 0x1a48) = *(uint *)(ctx + 0x1a48) | 0x40000000;
          }
          if (*(float *)(boundTexture + 0x88) != FLOAT_001aa0d4) {
            *(uint *)(ctx + 0x1a48) = *(uint *)(ctx + 0x1a48) | 0x10000000;
          }
          if ((loopIndex < 8) && (samplerModeBits != 0)) {
            if ((*(uint *)(ctx + 0x284) & 0x20000) != 0) goto LAB_000a81e0;
            if (((int)(uint)*(byte *)(ctx + 0x260) >> (loopIndex & 0x3f) & 1U) == 0) {
              *(undefined1 *)(ctx + 0x269) = 1;
              *(byte *)(ctx + 0x260) = *(byte *)(ctx + 0x260) | unitBit8;
              *(ushort *)(ctx + 0x274) = unitBit16 | *(ushort *)(ctx + 0x274);
            }
            *(char *)(loopIndex + streamBase + 0x21) = (char)samplerModeBits;
            unitRegBase12 = loopIndex * 0xc + streamBase;
            *(uint *)(unitRegBase12 + 0x2854) = (uint)*(ushort *)(boundTexture + 0xd0);
            *(uint *)(unitRegBase12 + 0x2858) = (uint)*(ushort *)(boundTexture + 0xd4);
            *(uint *)(unitRegBase12 + 0x285c) = (uint)*(ushort *)(boundTexture + 0xd2);
          }
          else {
LAB_000a81e0:
            if (((int)(uint)*(byte *)(ctx + 0x260) >> (loopIndex & 0x3f) & 1U) != 0) {
              *(undefined1 *)(ctx + 0x269) = 1;
              *(byte *)(ctx + 0x260) = *(byte *)(ctx + 0x260) & ~unitBit8;
              *(ushort *)(ctx + 0x274) = unitBit16 | *(ushort *)(ctx + 0x274);
            }
          }
          unitRegBase8Final = loopIndex * 8 + streamBase;
          *(uint *)(unitRegBase8Final + 0x18a8) = samplerModeBits << 2 | *(uint *)(unitRegBase8Final + 0x18a8) & 0xfffffff3;
        }
      }
      loopIndex = loopIndex + 1;
      unitMask = unitMask >> 1;
      ctxUnitCursor = ctxUnitCursor + 4;
    } while (unitMask != 0);
  }
  return;
}

/* FUN_000a82c0 @ 0xa82c0 (96 bytes) */
int FUN_000a82c0(ctx, unit)
  int ctx;
  int unit;
{
  int *piVar1;
  int remaining;
  
  if (*(int *)(((unsigned char *)0x000013f8) + unit * 4 + ctx + 0x240) == 0) {
    return;
  }
  remaining = 5;
  piVar1 = (int *)(unit * 0x14 + *(int *)(ctx + 0x18));
  while ((*piVar1 == 0 ||
         (*(int *)(((unsigned char *)0x000013f8) + unit * 4 + ctx + 0x240) != *piVar1 + 0x3c))) {
    piVar1 = piVar1 + 1;
    remaining = remaining + -1;
    if (remaining == 0) {
      *(undefined4 *)(((unsigned char *)0x000013f8) + unit * 4 + ctx + 0x240) = 0;
      return;
    }
  }
  return;
}

/* FUN_000a8320 @ 0xa8320 (20 bytes) */
int FUN_000a8320(ctx, packetIndex)
  int ctx;
  int packetIndex;
{
  *(undefined4 *)(((unsigned char *)0x00001638) + packetIndex * 4 + ctx) = 0;
  return;
}

/* gld_copyTexCombinerSources @ 0xa8340 (720 bytes) */
int gld_copyTexCombinerSources(glContextPtr4, dirtyBitsWord4)
  int glContextPtr4;
  uint dirtyBitsWord4;
{
  uint stateWord278;
  int unitWordOffset;
  short *unitEnvSource;
  uint pendingUnitBits;
  int loopIndex2;
  uint loopIndex3;
  int unitFlagWords;
  uint unitFlags;
  uint *unitFlagWord;
  int unitEnvBlock;
  int loopIndex;
  
  pendingUnitBits = dirtyBitsWord4 >> 0x10 & 0xff;
  if (pendingUnitBits != 0) {
    loopIndex3 = 0;
    unitFlagWords = glContextPtr4 + 0x288;
    loopIndex = 0;
    loopIndex2 = 0;
    do {
      if ((pendingUnitBits & 1) != 0) {
        unitWordOffset = loopIndex3 * 4;
        unitEnvBlock = loopIndex + glContextPtr4 + 0x690;
        unitFlagWord = (uint *)(unitFlagWords + unitWordOffset);
        unitEnvSource = (short *)(((unsigned char *)0x00003988) + loopIndex2 + *(int *)(glContextPtr4 + 0x10));
        if (*(char *)(unitEnvSource + 0x48) == '\0') {
          *(uint *)(unitFlagWords + unitWordOffset) = *(uint *)(unitFlagWords + unitWordOffset) & 0xffffffdf;
        }
        else {
          *(uint *)(unitFlagWords + unitWordOffset) = *(uint *)(unitFlagWords + unitWordOffset) | 0x20;
        }
        if (*(char *)((int)unitEnvSource + 0x91) == '\0') {
          unitFlags = *unitFlagWord & 0xffffffbf;
          *unitFlagWord = unitFlags;
        }
        else {
          unitFlags = *unitFlagWord | 0x40;
          *unitFlagWord = unitFlags;
        }
        if (*(char *)(unitEnvSource + 0x49) == '\0') {
          unitFlags = unitFlags & 0xffffff7f;
          *unitFlagWord = unitFlags;
        }
        else {
          unitFlags = unitFlags | 0x80;
          *unitFlagWord = unitFlags;
        }
        if (*(char *)((int)unitEnvSource + 0x93) == '\0') {
          unitFlags = unitFlags & 0xfffffeff;
          *unitFlagWord = unitFlags;
        }
        else {
          unitFlags = unitFlags | 0x100;
          *unitFlagWord = unitFlags;
        }
        if ((unitFlags & 0x1e0) != 0) {
          if ((unitFlags & 0x20) != 0) {
            if (*(short *)(unitEnvBlock + 0x3c) != *unitEnvSource) {
              *(short *)(unitEnvBlock + 0x3c) = *unitEnvSource;
            }
            *(undefined4 *)(unitEnvBlock + 0x50) = *(undefined4 *)(unitEnvSource + 10);
            *(undefined4 *)(unitEnvBlock + 0x54) = *(undefined4 *)(unitEnvSource + 0xc);
            *(undefined4 *)(unitEnvBlock + 0x58) = *(undefined4 *)(unitEnvSource + 0xe);
            *(undefined4 *)(unitEnvBlock + 0x5c) = *(undefined4 *)(unitEnvSource + 0x10);
            *(undefined4 *)(unitEnvBlock + 0x40) = *(undefined4 *)(unitEnvSource + 2);
            *(undefined4 *)(unitEnvBlock + 0x44) = *(undefined4 *)(unitEnvSource + 4);
            *(undefined4 *)(unitEnvBlock + 0x48) = *(undefined4 *)(unitEnvSource + 6);
            *(undefined4 *)(unitEnvBlock + 0x4c) = *(undefined4 *)(unitEnvSource + 8);
            unitFlags = *unitFlagWord;
          }
          if ((unitFlags & 0x40) != 0) {
            if (*(short *)(unitEnvBlock + 0x60) != unitEnvSource[0x12]) {
              *(short *)(unitEnvBlock + 0x60) = unitEnvSource[0x12];
            }
            *(undefined4 *)(unitEnvBlock + 0x74) = *(undefined4 *)(unitEnvSource + 0x1c);
            *(undefined4 *)(unitEnvBlock + 0x78) = *(undefined4 *)(unitEnvSource + 0x1e);
            *(undefined4 *)(unitEnvBlock + 0x7c) = *(undefined4 *)(unitEnvSource + 0x20);
            *(undefined4 *)(unitEnvBlock + 0x80) = *(undefined4 *)(unitEnvSource + 0x22);
            *(undefined4 *)(unitEnvBlock + 100) = *(undefined4 *)(unitEnvSource + 0x14);
            *(undefined4 *)(unitEnvBlock + 0x68) = *(undefined4 *)(unitEnvSource + 0x16);
            *(undefined4 *)(unitEnvBlock + 0x6c) = *(undefined4 *)(unitEnvSource + 0x18);
            *(undefined4 *)(unitEnvBlock + 0x70) = *(undefined4 *)(unitEnvSource + 0x1a);
            unitFlags = *unitFlagWord;
          }
          if ((unitFlags & 0x80) != 0) {
            if (*(short *)(unitEnvBlock + 0x84) != unitEnvSource[0x24]) {
              *(short *)(unitEnvBlock + 0x84) = unitEnvSource[0x24];
            }
            *(undefined4 *)(unitEnvBlock + 0x98) = *(undefined4 *)(unitEnvSource + 0x2e);
            *(undefined4 *)(unitEnvBlock + 0x9c) = *(undefined4 *)(unitEnvSource + 0x30);
            *(undefined4 *)(unitEnvBlock + 0xa0) = *(undefined4 *)(unitEnvSource + 0x32);
            *(undefined4 *)(unitEnvBlock + 0xa4) = *(undefined4 *)(unitEnvSource + 0x34);
            *(undefined4 *)(unitEnvBlock + 0x88) = *(undefined4 *)(unitEnvSource + 0x26);
            *(undefined4 *)(unitEnvBlock + 0x8c) = *(undefined4 *)(unitEnvSource + 0x28);
            *(undefined4 *)(unitEnvBlock + 0x90) = *(undefined4 *)(unitEnvSource + 0x2a);
            *(undefined4 *)(unitEnvBlock + 0x94) = *(undefined4 *)(unitEnvSource + 0x2c);
            unitFlags = *unitFlagWord;
          }
          if ((unitFlags & 0x100) != 0) {
            if (*(short *)(unitEnvBlock + 0xa8) != unitEnvSource[0x36]) {
              *(short *)(unitEnvBlock + 0xa8) = unitEnvSource[0x36];
            }
            *(undefined4 *)(unitEnvBlock + 0xbc) = *(undefined4 *)(unitEnvSource + 0x40);
            *(undefined4 *)(unitEnvBlock + 0xc0) = *(undefined4 *)(unitEnvSource + 0x42);
            *(undefined4 *)(unitEnvBlock + 0xc4) = *(undefined4 *)(unitEnvSource + 0x44);
            *(undefined4 *)(unitEnvBlock + 200) = *(undefined4 *)(unitEnvSource + 0x46);
            *(undefined4 *)(unitEnvBlock + 0xac) = *(undefined4 *)(unitEnvSource + 0x38);
            *(undefined4 *)(unitEnvBlock + 0xb0) = *(undefined4 *)(unitEnvSource + 0x3a);
            *(undefined4 *)(unitEnvBlock + 0xb4) = *(undefined4 *)(unitEnvSource + 0x3c);
            *(undefined4 *)(unitEnvBlock + 0xb8) = *(undefined4 *)(unitEnvSource + 0x3e);
          }
        }
        *(undefined1 *)(glContextPtr4 + 0x269) = 1;
        stateWord278 = *(uint *)(glContextPtr4 + 0x278);
        *(byte *)(glContextPtr4 + 0x26c) = (byte)(1 << (loopIndex3 & 0x3f)) | *(byte *)(glContextPtr4 + 0x26c);
        *(uint *)(glContextPtr4 + 0x278) = stateWord278 | 0x8000;
        if (((unsigned char *)0x00002d48)[*(int *)(glContextPtr4 + 0x10) + 2] != '\0') {
          *(uint *)(glContextPtr4 + 0x278) = stateWord278 | 0x8020;
        }
      }
      pendingUnitBits = pendingUnitBits >> 1;
      loopIndex3 = loopIndex3 + 1;
      loopIndex2 = loopIndex2 + 0x94;
      loopIndex = loopIndex + 0xcc;
    } while (pendingUnitBits != 0);
  }
  *(undefined1 *)(glContextPtr4 + 0x26b5) = 1;
  return;
}

/* FUN_000a8630 @ 0xa8630 (968 bytes) */
double FUN_000a8630(int glContext,int engineState,uint dirtyBitsWord8,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12,double fpPassThrough13)
{
  uint loopIndex;
  uint glContextWord40;
  uint glContextWord38;
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  undefined1 uVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  
  if ((dirtyBitsWord8 & 8) != 0) {
    *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x80;
    *(uint *)(glContext + 0x40) = *(uint *)(glContext + 0x40) | 0x20000;
    *(undefined1 *)(glContext + 0x29) = 1;
  }
  if (((dirtyBitsWord8 & 0x3f000008) != 0) && (*(int *)(((unsigned char *)0x00003e28) + engineState) != 0)) {
    fVar11 = *(float *)(engineState + 0x1920);
    dVar34 = (double)*(float *)(engineState + 0x192c);
    dVar36 = (double)*(float *)(engineState + 0x1958);
    dVar35 = (double)*(float *)(engineState + 0x195c);
    dVar38 = (double)*(float *)(engineState + 0x1928);
    dVar37 = (double)*(float *)(engineState + 0x1938);
    dVar39 = (double)*(float *)(engineState + 0x1948);
    dVar29 = (double)*(float *)(engineState + 0x193c);
    fVar12 = *(float *)(engineState + 0x1934);
    fVar2 = (float)(dVar38 * dVar35 - (double)(float)(dVar34 * dVar36));
    fVar3 = (float)(dVar38 * dVar29 - (double)(float)(dVar34 * dVar37));
    fVar4 = (float)(dVar37 * dVar35 - (double)(float)(dVar29 * dVar36));
    fVar13 = *(float *)(engineState + 0x1924);
    fVar14 = *(float *)(engineState + 0x1944);
    dVar30 = (double)*(float *)(engineState + 0x194c);
    fVar15 = *(float *)(engineState + 0x1954);
    fVar16 = *(float *)(engineState + 0x1940);
    fVar5 = (float)(dVar38 * dVar30 - (double)(float)(dVar34 * dVar39));
    fVar20 = fVar15 * fVar3 + (fVar13 * fVar4 - fVar12 * fVar2);
    fVar6 = (float)(dVar37 * dVar30 - (double)(float)(dVar29 * dVar39));
    fVar7 = (float)(dVar39 * dVar35 - (double)(float)(dVar30 * dVar36));
    dVar28 = (double)(fVar11 * fVar14 - fVar13 * fVar16);
    fVar22 = -(fVar13 * fVar6 - (fVar12 * fVar5 - fVar14 * fVar3));
    fVar21 = -(fVar13 * fVar7 - (fVar14 * fVar2 - fVar15 * fVar5));
    fVar17 = *(float *)(engineState + 0x1950);
    fVar18 = *(float *)(engineState + 0x1930);
    fVar19 = fVar15 * fVar6 + (fVar12 * fVar7 - fVar14 * fVar4);
    dVar33 = (double)(fVar11 * fVar15 - fVar13 * fVar17);
    fpPassThrough8 = (double)(fVar18 * fVar15 - fVar12 * fVar17);
    dVar31 = (double)(fVar11 * fVar12 - fVar13 * fVar18);
    fpPassThrough3 = (double)(fVar18 * fVar14 - fVar12 * fVar16);
    fpPassThrough6 = (double)(float)(dVar33 * dVar30 - (double)(float)(dVar28 * dVar35));
    fVar12 = fVar11 * fVar19 + fVar18 * fVar21 + fVar17 * fVar22 + fVar16 * fVar20;
    dVar32 = (double)(fVar16 * fVar15 - fVar14 * fVar17);
    dVar1 = fpPassThrough8 * dVar34;
    dVar9 = fpPassThrough8 * dVar38;
    fpPassThrough7 = (double)(float)(dVar31 * dVar39 +
                              (double)(float)(fpPassThrough3 * dVar38 - (double)(float)(dVar28 * dVar37)))
    ;
    fpPassThrough4 = -(double)(float)(dVar32 * dVar37 -
                               (double)(float)(fpPassThrough8 * dVar39 -
                                              (double)(float)(fpPassThrough3 * dVar36)));
    fpPassThrough5 = (double)(float)(fpPassThrough3 * dVar35 +
                              (double)(float)(dVar32 * dVar29 - (double)(float)(fpPassThrough8 * dVar30)))
    ;
    dVar10 = fpPassThrough3 * dVar34;
    fpPassThrough1 = (double)(float)(dVar28 * dVar36 +
                              (double)(float)(dVar32 * dVar38 - (double)(float)(dVar33 * dVar39)));
    fpPassThrough2 = -(double)(float)(dVar32 * dVar34 - fpPassThrough6);
    if ((fVar12 < FLOAT_001aa198) || (uVar26 = 0, FLOAT_001aa19c < fVar12)) {
      uVar26 = 1;
      dVar27 = (double)(FLOAT_001aa0e8 / fVar12);
      dVar32 = fpPassThrough7 * dVar27;
      dVar34 = fpPassThrough5 * dVar27;
      fpPassThrough6 = (double)(float)dVar34;
      fVar12 = (float)((double)fVar20 * dVar27);
      fpPassThrough5 = (double)fVar12;
      dVar38 = fpPassThrough4 * dVar27;
      fpPassThrough4 = (double)(float)dVar38;
      dVar39 = fpPassThrough2 * dVar27;
      fpPassThrough2 = (double)(float)dVar39;
      dVar8 = fpPassThrough1 * dVar27;
      fpPassThrough1 = (double)(float)dVar8;
      fVar13 = (float)((double)fVar19 * dVar27);
      fpPassThrough8 = (double)fVar13;
      fVar14 = (float)((double)fVar21 * dVar27);
      fpPassThrough7 = (double)fVar14;
      *(float *)(((unsigned char *)0x000013a4) + glContext) = (float)dVar32;
      *(float *)(((unsigned char *)0x0000136c) + glContext) =
           (float)(dVar27 * -(double)(fVar18 * fVar7 - (fVar16 * fVar4 - fVar17 * fVar6)));
      *(float *)(((unsigned char *)0x00001370) + glContext) = (float)dVar34;
      *(float *)(((unsigned char *)0x00001388) + glContext) = fVar12;
      *(float *)(((unsigned char *)0x00001374) + glContext) = (float)dVar38;
      *(float *)(((unsigned char *)0x0000137c) + glContext) =
           (float)(dVar27 * (double)(fVar17 * fVar5 + (fVar11 * fVar7 - fVar16 * fVar2)));
      *(float *)(((unsigned char *)0x00001380) + glContext) = (float)dVar39;
      *(float *)(((unsigned char *)0x0000138c) + glContext) =
           (float)(dVar27 * -(double)(fVar11 * fVar4 - (fVar18 * fVar2 - fVar17 * fVar3)));
      *(float *)(((unsigned char *)0x00001384) + glContext) = (float)dVar8;
      *(float *)(((unsigned char *)0x0000139c) + glContext) =
           (float)(dVar27 * (double)(fVar16 * fVar3 + (fVar11 * fVar6 - fVar18 * fVar5)));
      *(float *)(((unsigned char *)0x00001390U) + glContext) =
           (float)((double)(float)(dVar31 * dVar35 +
                                  (double)(float)(dVar1 - (double)(float)(dVar33 * dVar29))) *
                  dVar27);
      *(float *)(((unsigned char *)0x00001368) + glContext) = fVar13;
      *(float *)(((unsigned char *)0x00001378) + glContext) = fVar14;
      *(float *)(((unsigned char *)0x00001394) + glContext) =
           (float)(-(double)(float)(dVar9 - (double)(float)(dVar33 * dVar37 -
                                                           (double)(float)(dVar31 * dVar36))) *
                  dVar27);
      fVar2 = (float)((double)fVar22 * dVar27);
      fpPassThrough3 = (double)fVar2;
      *(float *)(((unsigned char *)0x00001398) + glContext) = fVar2;
      *(float *)(((unsigned char *)0x000013a0) + glContext) =
           (float)(-(double)(float)(dVar10 - (double)(float)(dVar28 * dVar29 -
                                                            (double)(float)(dVar31 * dVar30))) *
                  dVar27);
    }
    glContextWord38 = *(uint *)(glContext + 0x38);
    glContextWord40 = *(uint *)(glContext + 0x40);
    ((unsigned char *)0x000013a8)[glContext] = uVar26;
    *(uint *)(glContext + 0x40) = glContextWord40 | 0x20000;
    *(uint *)(glContext + 0x38) = glContextWord38 | 0x20080;
    *(undefined1 *)(glContext + 0x29) = 1;
    *(undefined2 *)(glContext + 0x36) = 0x3f;
  }
  if ((dirtyBitsWord8 & 0xf8) != 0) {
    if ((dirtyBitsWord8 & 0x10) == 0) {
      uVar23 = *(uint *)(glContext + 0x40);
    }
    else {
      uVar23 = *(uint *)(glContext + 0x40) | 0x10000;
      *(uint *)(glContext + 0x40) = uVar23;
    }
    if (((unsigned char *)0x00004301)[engineState] != '\0') {
      uVar24 = (uint)(byte)((unsigned char *)0x00004300)[engineState];
      if ((uint)(byte)((unsigned char *)0x000013b4)[glContext] < (uint)(byte)((unsigned char *)0x00004300)[engineState]) {
        uVar24 = (uint)(byte)((unsigned char *)0x000013b4)[glContext];
      }
      if (1 < uVar24) {
        if ((dirtyBitsWord8 & 0x20) == 0) {
          iVar25 = uVar24 - 1;
          loopIndex = 1;
          do {
            loopIndex = loopIndex + 1;
            iVar25 = iVar25 + -1;
            if (iVar25 == 0) goto LAB_000a89c0;
          } while ((dirtyBitsWord8 & 0x10 << (loopIndex & 0x3f)) == 0);
        }
        uVar23 = uVar23 | 0x10000;
        *(uint *)(glContext + 0x40) = uVar23;
      }
    }
LAB_000a89c0:
    *(uint *)(glContext + 0x40) = uVar23 | 0x30000;
    *(undefined1 *)(glContext + 0x29) = 1;
    *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x80;
  }
  _restf14(fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,fpPassThrough7,fpPassThrough8);
  return;
}

/* gld_transformClipPlanes @ 0xa8a00 (488 bytes) */
int gld_transformClipPlanes(glContextPtr4, dirtyBitsWord8)
  int glContextPtr4;
  uint dirtyBitsWord8;
{
  float planeW;
  float planeX;
  float planeY;
  float planeZ;
  int planeByteOffset;
  float oneF;
  int transformedPlanes;
  int engineCaps;
  uint planeBit;
  int transformedPlane;
  undefined *planeCursor;
  uint loopIndex;
  int remaining;
  
  oneF = FLOAT_001aa0e8;
  loopIndex = 0;
  remaining = 6;
  engineCaps = *(int *)(glContextPtr4 + 0x10);
  transformedPlanes = glContextPtr4 + 0x618;
  planeCursor = ((unsigned char *)0x00003e20) + engineCaps;
  do {
    if (((0x1000000 << (loopIndex & 0x3f) | 8U) & dirtyBitsWord8) != 0) {
      planeBit = 1 << (loopIndex & 0x3f);
      if ((planeBit & *(uint *)(((unsigned char *)0x00003e28) + engineCaps)) != 0) {
        planeW = *(float *)(planeCursor + 0x18);
        planeByteOffset = loopIndex * 0x10;
        planeX = *(float *)(planeCursor + 0xc);
        planeY = *(float *)(planeCursor + 0x10);
        planeZ = *(float *)(planeCursor + 0x14);
        transformedPlane = planeByteOffset + transformedPlanes;
        if (planeW == oneF) {
          *(float *)(transformedPlanes + planeByteOffset) =
               planeZ * *(float *)(((unsigned char *)0x000015c8) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015a8) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015b8) + glContextPtr4) + *(float *)(((unsigned char *)0x000015d8) + glContextPtr4);
          *(float *)(transformedPlane + 4) =
               planeZ * *(float *)(((unsigned char *)0x000015cc) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015ac) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015bc) + glContextPtr4) + *(float *)(((unsigned char *)0x000015dc) + glContextPtr4);
          *(float *)(transformedPlane + 8) =
               planeZ * *(float *)(((unsigned char *)0x000015d0) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015b0) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015c0) + glContextPtr4) + *(float *)(((unsigned char *)0x000015e0) + glContextPtr4);
          *(float *)(transformedPlane + 0xc) =
               planeZ * *(float *)((int)((unsigned char *)0x000015d4) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015b4) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015c4) + glContextPtr4) + *(float *)(((unsigned char *)0x000015e4) + glContextPtr4);
        }
        else {
          *(float *)(transformedPlanes + planeByteOffset) =
               planeW * *(float *)(((unsigned char *)0x000015d8) + glContextPtr4) +
               planeZ * *(float *)(((unsigned char *)0x000015c8) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015a8) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015b8) + glContextPtr4);
          *(float *)(transformedPlane + 4) =
               planeW * *(float *)(((unsigned char *)0x000015dc) + glContextPtr4) +
               planeZ * *(float *)(((unsigned char *)0x000015cc) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015ac) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015bc) + glContextPtr4);
          *(float *)(transformedPlane + 8) =
               planeW * *(float *)(((unsigned char *)0x000015e0) + glContextPtr4) +
               planeZ * *(float *)(((unsigned char *)0x000015d0) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015b0) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015c0) + glContextPtr4);
          *(float *)(transformedPlane + 0xc) =
               planeW * *(float *)(((unsigned char *)0x000015e4) + glContextPtr4) +
               planeZ * *(float *)((int)((unsigned char *)0x000015d4) + glContextPtr4) +
               planeX * *(float *)(((unsigned char *)0x000015b4) + glContextPtr4) +
               planeY * *(float *)(((unsigned char *)0x000015c4) + glContextPtr4);
        }
      }
      *(ushort *)(glContextPtr4 + 0x276) = (ushort)planeBit | *(ushort *)(glContextPtr4 + 0x276);
    }
    loopIndex = loopIndex + 1;
    planeCursor = planeCursor + 0x10;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined1 *)(glContextPtr4 + 0x269) = 1;
  *(uint *)(glContextPtr4 + 0x278) = *(uint *)(glContextPtr4 + 0x278) | 0x20000;
  return;
}

/* gld_updateProgramFlags @ 0xa8c00 (356 bytes) */
int gld_updateProgramFlags(glContext, engineCaps, dirtyBitsArg, scratchR6, dirtyWord3, dirtyWord1, staleArgR9)
  int glContext;
  int engineCaps;
  undefined4 dirtyBitsArg;
  undefined4 scratchR6;
  undefined4 dirtyWord3;
  undefined4 dirtyWord1;
  undefined4 staleArgR9;
{
  uint flagChange;
  uint glContextWord1928;
  int glContextPtr4;
  uint programFlag;
  uint sampleFlag;
  
  if (((unsigned char *)0x00002e2d)[engineCaps] != '\0') {
    *(undefined1 *)(glContext + 0x2f) = 0;
    *(undefined1 *)(glContext + 0x2940) = 1;
    *(uint *)(glContext + 0x1808) = *(uint *)(glContext + 0x1808) | 0x20000000;
  }
  if (((unsigned char *)0x00002e2c)[engineCaps] != '\0') {
    *(undefined1 *)(glContext + 0x2f) = 0;
    *(undefined1 *)(glContext + 0x2940) = 1;
    *(uint *)(glContext + 0x1808) = *(uint *)(glContext + 0x1808) | 0x20000000;
  }
  glContextPtr4 = *(int *)(glContext + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4 + 0x10)] != '\0') &&
     ((*(uint *)(glContext + 0x44) & 0x20000) == 0)) {
    glContextPtr4 = FUN_0001a010(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),dirtyBitsArg,scratchR6,dirtyWord3,dirtyWord1,
                         staleArgR9);
    if (glContextPtr4 == 0) {
      glContextPtr4 = *(int *)(glContext + 4);
      programFlag = 1;
      goto LAB_000a8cb4;
    }
    glContextPtr4 = *(int *)(glContext + 4);
  }
  programFlag = 0;
LAB_000a8cb4:
  glContextWord1928 = *(uint *)(glContext + 0x1928);
  flagChange = glContextWord1928 >> 4 & 1 ^ programFlag;
  *(uint *)(glContext + 0x1928) = glContextWord1928 & 0xffffffef | flagChange | programFlag << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
      ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (sampleFlag = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(glContextPtr4 + 0x10)) == -1)) {
    sampleFlag = 0;
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 6;
  *(uint *)(glContext + 0x1928) =
       glContextWord1928 & 0xffffffe7 | flagChange | programFlag << 4 | (glContextWord1928 & 8) >> 3 ^ sampleFlag | sampleFlag << 3;
  return;
}

/* FUN_000a8d70 @ 0xa8d70 (168 bytes) */
int FUN_000a8d70(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00003178)[param_2] != '\0') {
    *(undefined1 *)(glContext + 0x2f) = 0;
    *(undefined1 *)(glContext + 0x2940) = 1;
    *(uint *)(glContext + 0x1808) = *(uint *)(glContext + 0x1808) | 0x20000000;
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 4;
  iVar1 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((((unsigned char *)0x00003178)[iVar1] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     ((*(short *)(((unsigned char *)0x00003170) + iVar1) != 0x1b02 && (*(short *)(((unsigned char *)0x00003172) + iVar1) != 0x1b02))
     )) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  *(uint *)(glContext + 0x1928) =
       *(uint *)(glContext + 0x1928) & 0xfffffffb | *(uint *)(glContext + 0x1928) >> 2 & 1 ^ uVar2 |
       uVar2 << 2;
  return;
}

/* gld_updateLightingFlags @ 0xa8e20 (544 bytes) */
int gld_updateLightingFlags(glContext, engineCaps, dirtyMask)
  int glContext;
  int engineCaps;
  uint dirtyMask;
{
  uint bit24Value;
  uint chipVariantBit;
  uint glContextWord38_3;
  uint glContextWord38_2;
  uint glContextWord18a4;
  uint glContextWord38;
  uint capsFlag2e0b;
  uint glContextWord44;
  uint ctx44Word;
  
  if ((dirtyMask & 0x1000) == 0) {
    ctx44Word = *(uint *)(glContext + 0x44);
    capsFlag2e0b = (uint)(byte)((unsigned char *)0x00002e0b)[engineCaps];
    goto LAB_000a8ee8;
  }
  if (((unsigned char *)0x00002e0a)[engineCaps] == '\0') {
    glContextWord44 = *(uint *)(glContext + 0x44);
LAB_000a8e54:
    bit24Value = 0;
  }
  else {
    glContextWord44 = *(uint *)(glContext + 0x44);
    bit24Value = 1;
    if ((glContextWord44 & 0x2000) != 0) goto LAB_000a8e54;
  }
  glContextWord38 = *(uint *)(glContext + 0x38);
  ctx44Word = bit24Value << 0x18 | glContextWord44 & 0xfeffffff;
  *(uint *)(glContext + 0x44) = ctx44Word;
  *(uint *)(glContext + 0x38) = glContextWord38 | 0x100;
  *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x40;
  *(uint *)(glContext + 0x18a4) = bit24Value | *(uint *)(glContext + 0x18a4) & 0xfffffffe;
  *(undefined1 *)(glContext + 0x29) = 1;
  capsFlag2e0b = (uint)(byte)((unsigned char *)0x00002e0b)[engineCaps];
  if (((((unsigned char *)0x00002d48)[engineCaps + 2] != '\0' || ((unsigned char *)0x00002e0b)[engineCaps] != 0) ||
      (glContextWord44 & 0x200000) != 0) || (glContextWord44 & 0x10000) != 0) {
    *(uint *)(glContext + 0x38) = glContextWord38 | 0x120;
    capsFlag2e0b = (uint)(byte)((unsigned char *)0x00002e0b)[engineCaps];
  }
LAB_000a8ee8:
  if ((ctx44Word >> 0x17 & 1) != capsFlag2e0b) {
    glContextWord38_2 = *(uint *)(glContext + 0x38);
    *(uint *)(glContext + 0x44) = (capsFlag2e0b & 1) << 0x17 | ctx44Word & 0xff7fffff;
    *(undefined1 *)(glContext + 0x29) = 1;
    *(uint *)(glContext + 0x38) = glContextWord38_2 | 0x120;
    if (*(int *)(glContext + -0x70) != 0) {
      *(uint *)(glContext + 0x38) = glContextWord38_2 | 0x2320;
      *(byte *)(glContext + 0x2e) = *(byte *)(glContext + 0x2e) | 2;
    }
    if (((unsigned char *)0x00004304)[engineCaps] == '\0') {
      if ((int)*(uint *)(glContext + 0x44) < 0) {
        glContextWord18a4 = *(uint *)(glContext + 0x18a4);
        chipVariantBit = (uint)(*(short *)(((unsigned char *)0x00002d48) + engineCaps) == -0x7e06) << 2;
        *(uint *)(glContext + 0x18a4) = chipVariantBit | glContextWord18a4 & 0xfffffffb;
        *(uint *)(glContext + 0x18a4) =
             ((byte)((unsigned char *)0x00002d48)[engineCaps + 4] & 1) << 1 | chipVariantBit | glContextWord18a4 & 0xfffffff9;
      }
      else {
        *(uint *)(glContext + 0x18a4) =
             *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
      }
    }
    else {
      *(uint *)(glContext + 0x18a4) =
           (uint)((undefined *)(*(uint *)(glContext + 0x44) & 0x80040) == ((unsigned char *)0x00080040U)) << 1 |
           *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
    }
  }
  if ((dirtyMask & 0x800) != 0) {
    glContextWord38_3 = *(uint *)(glContext + 0x38);
    *(undefined1 *)(glContext + 0x29) = 1;
    *(uint *)(glContext + 0x38) = glContextWord38_3 | 0x100;
    if (((unsigned char *)0x00002d48)[engineCaps + 2] != '\0') {
      *(uint *)(glContext + 0x38) = glContextWord38_3 | 0x120;
    }
    if (*(int *)(glContext + -0x70) == 0) {
      if (*(int *)(glContext + -0x74) != 0) {
        *(undefined1 *)(glContext + 0x29) = 1;
        *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
        *(byte *)(glContext + 0x2d) = *(byte *)(glContext + 0x2d) | 3;
        return;
      }
      return;
    }
    *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x2200;
    *(byte *)(glContext + 0x2e) = *(byte *)(glContext + 0x2e) | 2;
    return;
  }
  return;
}

/* FUN_000a9070 @ 0xa9070 (1476 bytes) */
int FUN_000a9070(glContextPtr4, dirtyBitsWord10)
  int glContextPtr4;
  uint dirtyBitsWord10;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint loopIndex;
  int loopIndex2;
  undefined4 *puVar18;
  undefined2 *puVar19;
  
  uVar9 = dirtyBitsWord10 | dirtyBitsWord10 >> 0x10;
  uVar9 = (uVar9 | uVar9 >> 8) & 0xff;
  *(ushort *)(glContextPtr4 + 0x272) = (ushort)uVar9 | *(ushort *)(glContextPtr4 + 0x272);
  if (uVar9 != 0) {
    loopIndex = 0;
    loopIndex2 = 0;
    iVar15 = glContextPtr4 + 0x240;
    do {
      if ((uVar9 & 1) != 0) {
        puVar18 = (undefined4 *)(((unsigned char *)0x000031c4) + loopIndex * 0x7c + *(int *)(glContextPtr4 + 0x10));
        puVar19 = (undefined2 *)(glContextPtr4 + 0x690 + loopIndex * 0xcc);
        if ((loopIndex == *(uint *)(glContextPtr4 + 0x29ac)) && (*(int *)(glContextPtr4 + 0x29a8) != 0)) {
          iVar10 = *(int *)(*(int *)(glContextPtr4 + 0x29a8) + 0xbc);
          uVar13 = 1 << (loopIndex & 0x3f);
        }
        else {
          iVar10 = *(int *)(((unsigned char *)0x000013f8) + iVar15);
          uVar13 = 1 << (loopIndex & 0x3f);
          if (iVar10 == 0) {
            *(uint *)(glContextPtr4 + 0x29f4) = ~uVar13 & *(uint *)(glContextPtr4 + 0x29f4);
            *(uint *)(glContextPtr4 + 0x29f0) = ~uVar13 & *(uint *)(glContextPtr4 + 0x29f0);
          }
        }
        if ((dirtyBitsWord10 & uVar13) != 0) {
          iVar14 = loopIndex2 + glContextPtr4 + 0x1ae4;
          *puVar19 = *(undefined2 *)(puVar18 + 5);
          uVar5 = *(ushort *)(puVar18 + 5);
          *(uint *)(iVar14 + 8) =
               (((uint)uVar5 * 0x3b >> 0xd & 1 | (uint)uVar5 * 0x107 >> 10 & 2 | uVar5 >> 3 & 4) ^ 1
               ) << 1 | *(uint *)(iVar14 + 8) & 0xfffffff1;
        }
        if ((dirtyBitsWord10 & 0x10000 << (loopIndex & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x10) = puVar18[0xf];
          if (iVar10 != 0) {
            iVar10 = iVar10 + 0x4c;
          }
          FUN_00086a10(glContextPtr4 + 0x240,puVar19,iVar10);
        }
        if ((dirtyBitsWord10 & 0x100 << (loopIndex & 0x3f)) != 0) {
          *(undefined4 *)(puVar19 + 0x16) = *puVar18;
          *(undefined4 *)(puVar19 + 0x18) = puVar18[1];
          *(undefined4 *)(puVar19 + 0x1a) = puVar18[2];
          *(undefined4 *)(puVar19 + 0x1c) = puVar18[3];
          *(undefined1 *)(glContextPtr4 + 0x269) = 1;
          *(uint *)(glContextPtr4 + 0x27c) = *(uint *)(glContextPtr4 + 0x27c) | 0x400;
        }
        if ((dirtyBitsWord10 & 0x1000000 << (loopIndex & 0x3f)) != 0) {
          uVar13 = (uint)*(ushort *)(puVar18 + 6);
          iVar10 = glContextPtr4 + 0x1ae8;
          uVar5 = *(ushort *)((int)puVar18 + 0x1a);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[1];
          puVar11 = (uint *)(iVar10 + loopIndex2);
          if (uVar13 != (ushort)puVar19[2]) {
            puVar19[2] = *(ushort *)(puVar18 + 6);
            puVar11[1] = ((uVar13 * 0xb5 >> 7 & 1 | uVar13 * 0x177 >> 8 & 2 |
                           uVar13 * 0x19f >> 6 & 4 | uVar13 * 0x1bb >> 5 & 8) ^ 0xf) << 7 |
                         puVar11[1] & 0xfffff87f;
          }
          uVar7 = puVar19[3];
          uVar8 = *(ushort *)(puVar18 + 7);
          uVar13 = (uint)uVar8;
          if (uVar12 != uVar6) {
            puVar19[1] = uVar5;
            puVar11[1] = ((uVar12 * 0xc3 >> 8 & 1 | uVar12 * 0x165 >> 9 & 2 | uVar12 * 0xb >> 8 & 4
                          | uVar12 * 0xcb >> 6 & 8) ^ 10) << 0xd | puVar11[1] & 0xfffe1fff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x22);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[6];
          if (uVar13 != uVar7) {
            puVar19[3] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x18 | puVar11[1] & 0xf0ffffff;
          }
          uVar7 = *(ushort *)(puVar18 + 10);
          uVar8 = puVar19[9];
          if (uVar12 != uVar6) {
            puVar19[6] = uVar5;
            *(uint *)(iVar10 + loopIndex2) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 8 | *(uint *)(iVar10 + loopIndex2) & 0xfffff0ff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x2e);
          uVar6 = puVar19[0xc];
          if ((uint)uVar7 != (uint)uVar8) {
            puVar19[9] = uVar7;
            *(uint *)(iVar10 + loopIndex2) =
                 (uVar7 & 3) << 0x14 | *(uint *)(iVar10 + loopIndex2) & 0xffcfffff;
          }
          uVar7 = puVar19[4];
          uVar8 = *(ushort *)((int)puVar18 + 0x1e);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xc] = uVar5;
            *(uint *)(iVar10 + loopIndex2) =
                 (uVar5 & 1) << 0x1a | *(uint *)(iVar10 + loopIndex2) & 0xfbffffff;
          }
          uVar5 = *(ushort *)(puVar18 + 9);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[7];
          if (uVar13 != uVar7) {
            puVar19[4] = uVar8;
            puVar11[1] = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4
                          | uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 0x1c | puVar11[1] & 0xfffffff;
          }
          uVar7 = puVar19[10];
          uVar8 = *(ushort *)((int)puVar18 + 0x2a);
          if (uVar12 != uVar6) {
            puVar19[7] = uVar5;
            *(uint *)(iVar10 + loopIndex2) =
                 ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                  uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0xc | *(uint *)(iVar10 + loopIndex2) & 0xffff0fff;
          }
          uVar5 = *(ushort *)(puVar18 + 0xc);
          uVar6 = puVar19[0xd];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[10] = uVar8;
            *(uint *)(iVar10 + loopIndex2) =
                 (uVar8 & 3) << 0x16 | *(uint *)(iVar10 + loopIndex2) & 0xff3fffff;
          }
          uVar7 = puVar19[5];
          uVar8 = *(ushort *)(puVar18 + 8);
          uVar13 = (uint)uVar8;
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xd] = uVar5;
            *(uint *)(iVar10 + loopIndex2) =
                 (uVar5 & 1) << 0x1b | *(uint *)(iVar10 + loopIndex2) & 0xf7ffffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x26);
          uVar12 = (uint)uVar5;
          uVar6 = puVar19[8];
          if (uVar13 != uVar7) {
            puVar19[5] = uVar8;
            *puVar11 = ((uVar13 * 0x11 >> 4 & 1 | uVar13 * 0x37 >> 6 & 2 | uVar13 * 0x51 >> 7 & 4 |
                        uVar13 * 0x15 >> 6 & 8) ^ 0xc) << 4 | *puVar11 & 0xffffff0f;
          }
          uVar7 = puVar19[0xb];
          uVar8 = *(ushort *)(puVar18 + 0xb);
          if (uVar12 != uVar6) {
            puVar19[8] = uVar5;
            *puVar11 = ((uVar12 * 0x11 >> 4 & 1 | uVar12 * 0x37 >> 6 & 2 | uVar12 * 0x51 >> 7 & 4 |
                        uVar12 * 0x15 >> 6 & 8) ^ 0xc) << 0x10 | *puVar11 & 0xfff0ffff;
          }
          uVar5 = *(ushort *)((int)puVar18 + 0x32);
          uVar6 = puVar19[0xe];
          if ((uint)uVar8 != (uint)uVar7) {
            puVar19[0xb] = uVar8;
            *puVar11 = (uVar8 & 3) << 0x18 | *puVar11 & 0xfcffffff;
          }
          fVar1 = GH_U2F((unsigned int)(puVar18[0xd]));
          fVar2 = *(float *)(puVar19 + 0x12);
          if ((uint)uVar5 != (uint)uVar6) {
            puVar19[0xe] = uVar5;
            *puVar11 = (uVar5 & 1) << 0x1c | *puVar11 & 0xefffffff;
          }
          fVar3 = GH_U2F((unsigned int)(puVar18[0xe]));
          fVar4 = *(float *)(puVar19 + 0x14);
          if (fVar1 != fVar2) {
            *(float *)(puVar19 + 0x12) = fVar1;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar1) {
              uVar13 = 3 - (fVar1 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0xb | puVar11[1] & 0xffffe7ff;
          }
          if (fVar3 != fVar4) {
            *(float *)(puVar19 + 0x14) = fVar3;
            uVar13 = 1;
            if (FLOAT_001aa128 < fVar3) {
              uVar13 = 3 - (fVar3 <= FLOAT_001aa158);
            }
            puVar11[1] = (uVar13 & 3) << 0x11 | puVar11[1] & 0xfff9ffff;
          }
        }
      }
      uVar9 = uVar9 >> 1;
      loopIndex = loopIndex + 1;
      loopIndex2 = loopIndex2 + 8;
      iVar15 = iVar15 + 4;
    } while (uVar9 != 0);
  }
  *(uint *)(glContextPtr4 + 0x278) = *(uint *)(glContextPtr4 + 0x278) | 0x200;
  return;
}

/* gld_updatePointState @ 0xa9640 (1116 bytes) */
double gld_updatePointState(int glContext,int pointState,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12)
{
  double scaleLength;
  uint pointStateWord;
  float quantizedPointSizeInt;
  float pointSizeStateInt;
  float pointSizeState;
  float maxSizeClamped;
  float hwMaxSize;
  float scaledWidth;
  float pointSizeMaxState;
  undefined4 needsDerivedScale;
  undefined4 attenuationQuadratic;
  undefined4 glContextWord13d4;
  float glContextFloat13c4;
  float glContextFloat13cc;
  byte pointSmoothFlag;
  byte pointSpriteFlag;
  float pointSizeMinState;
  float scaledHeight;
  float minSizeClampTemp;
  float minSizeClamped;
  float quantizedPointSize;
  bool needsScaleRecompute;
  float oneF;
  uint glContextWord44;
  undefined4 hwMinSizeInt;
  uint pointModeBits;
  double intToDoubleBias;
  
  pointSmoothFlag = ((unsigned char *)0x000030dc)[pointState];
  glContextWord44 = *(uint *)(glContext + 0x44);
  pointModeBits = (pointSmoothFlag & 1) << 0x1e;
  *(uint *)(glContext + 0x44) = pointModeBits | glContextWord44 & 0xbfffffff;
  pointSpriteFlag = ((unsigned char *)0x000030dd)[pointState];
  *(uint *)(glContext + 0x44) = (pointSpriteFlag & 1) << 0x1d | pointModeBits | glContextWord44 & 0x9fffffff;
  if ((pointSpriteFlag & 1) != 0 || (pointSmoothFlag & 1) != 0) {
    *(undefined1 *)(glContext + 0x2f) = 0;
    *(undefined1 *)(glContext + 0x2940) = 1;
    *(uint *)(glContext + 0x1808) = *(uint *)(glContext + 0x1808) | 0x20000000;
  }
  hwMinSizeInt = *(undefined4 *)(((unsigned char *)0x000013d0U) + glContext);
  *(undefined4 *)(glContext + 0xec) = *(undefined4 *)(((unsigned char *)0x000030e4) + pointState);
  intToDoubleBias = DOUBLE_001aa250;
  pointSizeMinState = *(float *)(((unsigned char *)0x000030c0) + pointState);
  glContextFloat13c4 = *(float *)(((unsigned char *)0x000013c4) + glContext);
  *(float *)(glContext + 0xf4) = pointSizeMinState;
  minSizeClampTemp = pointSizeMinState;
  if (pointSizeMinState - glContextFloat13c4 < 0.0) {
    minSizeClampTemp = glContextFloat13c4;
  }
  minSizeClamped = glContextFloat13c4;
  if (-(pointSizeMinState - glContextFloat13c4) < 0.0) {
    minSizeClamped = minSizeClampTemp;
  }
  *(float *)(glContext + 0x100) = minSizeClamped;
  if (pointSizeMinState <= (float)((double)CONCAT44(0x43300000,hwMinSizeInt) - intToDoubleBias)) {
    *(undefined4 *)(glContext + 0x108) = hwMinSizeInt;
  }
  else {
    *(int *)(glContext + 0x108) = (int)pointSizeMinState;
  }
  glContextWord13d4 = *(undefined4 *)(((unsigned char *)0x000013d4) + glContext);
  pointSizeMaxState = *(float *)(((unsigned char *)0x000030c4) + pointState);
  *(float *)(glContext + 0xf8) = pointSizeMaxState;
  hwMaxSize = *(float *)(((unsigned char *)0x000013c8U) + glContext);
  maxSizeClamped = hwMaxSize;
  if (pointSizeMaxState - hwMaxSize < 0.0) {
    maxSizeClamped = pointSizeMaxState;
  }
  if (-(pointSizeMaxState - hwMaxSize) < 0.0) {
    maxSizeClamped = hwMaxSize;
  }
  *(float *)(glContext + 0x104) = maxSizeClamped;
  if ((float)((double)CONCAT44(0x43300000,glContextWord13d4) - DOUBLE_001aa250) <= pointSizeMaxState) {
    *(undefined4 *)(glContext + 0x10c) = glContextWord13d4;
  }
  else {
    *(int *)(glContext + 0x10c) = (int)pointSizeMaxState;
  }
  glContextFloat13cc = *(float *)(((unsigned char *)0x000013cc) + glContext);
  *(undefined4 *)(glContext + 0xf0) = *(undefined4 *)(((unsigned char *)0x000030bc) + pointState);
  pointSizeState = *(float *)(((unsigned char *)0x000030bc) + pointState);
  quantizedPointSize = glContextFloat13c4;
  if ((glContextFloat13c4 < pointSizeState) && (quantizedPointSize = hwMaxSize, pointSizeState < hwMaxSize)) {
    quantizedPointSize = glContextFloat13cc * (float)((double)CONCAT44(0x43300000,
                                             (int)((pointSizeState - glContextFloat13c4) / glContextFloat13cc + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + glContextFloat13c4;
  }
  *(float *)(glContext + 0xe0) = quantizedPointSize;
  oneF = FLOAT_001aa0e8;
  pointSizeStateInt = *(float *)(((unsigned char *)0x000030bc) + pointState);
  quantizedPointSizeInt = glContextFloat13c4;
  if ((glContextFloat13c4 < pointSizeStateInt) && (quantizedPointSizeInt = hwMaxSize, pointSizeStateInt < hwMaxSize)) {
    quantizedPointSizeInt = glContextFloat13cc * (float)((double)CONCAT44(0x43300000,
                                             (int)((pointSizeStateInt - glContextFloat13c4) / glContextFloat13cc + FLOAT_001aa10c) ^
                                             0x80000000) - DOUBLE_001aa1e0) + glContextFloat13c4;
  }
  *(int *)(glContext + 0xe4) = (int)quantizedPointSizeInt;
  *(undefined4 *)(glContext + 0xfc) = *(undefined4 *)(((unsigned char *)0x000030c8) + pointState);
  *(undefined4 *)(glContext + 0x110) = *(undefined4 *)(((unsigned char *)0x000030cc) + pointState);
  *(undefined4 *)(glContext + 0x114) = *(undefined4 *)(((unsigned char *)0x000030d0) + pointState);
  attenuationQuadratic = *(undefined4 *)(((unsigned char *)0x000030d4) + pointState);
  *(float *)(glContext + 0x11c) = oneF;
  *(undefined4 *)(glContext + 0x118) = attenuationQuadratic;
  if (((*(float *)(((unsigned char *)0x000030cc) + pointState) == oneF) &&
      (*(float *)(((unsigned char *)0x000030d0) + pointState) == FLOAT_001aa0d4)) &&
     (*(float *)(((unsigned char *)0x000030d4) + pointState) == FLOAT_001aa0d4)) {
    pointStateWord = *(uint *)(glContext + 0xe8) & 0xfffffffe;
    *(uint *)(glContext + 0xe8) = pointStateWord;
    *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xff7fffff;
    *(uint *)(glContext + 0x1928) =
         *(uint *)(glContext + 0x1928) & 0xfffffffd | *(uint *)(glContext + 0x1928) >> 1 & 1;
  }
  else {
    pointStateWord = *(uint *)(glContext + 0xe8) | 1;
    *(uint *)(glContext + 0xe8) = pointStateWord;
    *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) | 0x800000;
    if (*(int *)(*(int *)(glContext + 4) + 0x1cc) == 0) {
      *(uint *)(glContext + 0x1928) =
           *(uint *)(glContext + 0x1928) & 0xfffffffd | (*(uint *)(glContext + 0x1928) ^ 2) >> 1 & 1 | 2
      ;
    }
  }
  if (*(short *)(((unsigned char *)0x000030e2) + pointState) == 0x60b4) {
    pointStateWord = pointStateWord & 0xfffffff7;
    *(uint *)(glContext + 0xe8) = pointStateWord;
  }
  else {
    pointStateWord = pointStateWord | 8;
    *(uint *)(glContext + 0xe8) = pointStateWord;
  }
  if ((*(int *)(glContext + 0xe4) < 2) && ((pointStateWord & 1) == 0)) {
    needsScaleRecompute = false;
    needsDerivedScale = 0;
    if (*(int *)(glContext + 0xec) == 0) goto LAB_000a99e8;
  }
  needsScaleRecompute = true;
  needsDerivedScale = 1;
LAB_000a99e8:
  *(undefined4 *)(glContext + 0x1940) = needsDerivedScale;
  if (needsScaleRecompute) {
    scaledWidth = *(float *)(*(int *)(glContext + 4) + 0x2a54);
    scaledHeight = *(float *)(*(int *)(glContext + 4) + 0x2a58);
    scaledWidth = (scaledWidth + scaledWidth) * *(float *)(pointState + 0x1810);
    scaledHeight = (scaledHeight + scaledHeight) * *(float *)(pointState + 0x1814);
    if (scaledWidth == FLOAT_001aa0d4) {
      *(float *)(glContext + 400) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(glContext + 400) = FLOAT_001aa0e8 / scaledWidth;
    }
    if (scaledHeight == FLOAT_001aa0d4) {
      *(float *)(glContext + 0x194) = FLOAT_001aa0d4;
    }
    else {
      *(float *)(glContext + 0x194) = FLOAT_001aa0e8 / scaledHeight;
    }
    scaleLength = _sqrt((double)(*(float *)(glContext + 400) * *(float *)(glContext + 400) +
                           *(float *)(glContext + 0x194) * *(float *)(glContext + 0x194)));
    fpPassThrough1 = (double)(float)scaleLength;
    *(float *)(glContext + 0x198) = (float)scaleLength;
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0xc;
  return fpPassThrough1;
}

/* gld_validateDirtyState @ 0xa9ac0 (7656 bytes) */
void gld_validateDirtyState(char *glContext,uint *dirtyBits,char *dirtyBitsArg,undefined *scratchR6,uint dirtyWord3,char *dirtyWord1,undefined4 unusedArgR9,uint dirtyWord4,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9,double fpPassThrough10,double fpPassThrough11,double fpPassThrough12,double fpPassThrough13)
{
  uint dirtyScissorBits;
  uint zeroFlagC;
  uint dirtyBits4Word;
  uint flagChangeB;
  uint stateWord1874B;
  uint ctx44Bit13B;
  char *dirtyKeepSelected;
  char *dirtyKeepMaskedB;
  uint dirtyBits0x8000000;
  uint dirtyWord4Lights;
  uint zeroFlagB;
  uint feedbackFlag;
  uint chipVariantBitC;
  uint capsFlag2d4a;
  uint zeroFlagA;
  uint dirtyBits0x4400000;
  uint engineWord3e28;
  byte sampleCountBB;
  byte texFlag6cB;
  byte reg181cByte;
  byte sampleCountB;
  bool ctx44SignClear;
  byte sampleCountAB;
  byte stateByte2eNewB;
  byte reg1814Byte;
  byte sampleCountA;
  int engineCapsG;
  uint ctx44WordB;
  uint modeBitsCheckB;
  uint chipVariantBitB;
  uint sampleCountFlag;
  uint oneFlag;
  uint ctx44Word;
  uint ctx44Bit15B;
  uint dirtyWord38SetB;
  uint stateBit23B;
  uint dirtyKeepMaskHi;
  uint zeroFlag;
  uint stateWord1874;
  uint ctx44Bit13;
  uint modeBitsCheck;
  int drawableHeightCopy;
  int engineCapsF;
  int noVertexProgramMask;
  int engineCapsE;
  int engineCapsD;
  int engineCapsC;
  int drawableWidth;
  int engineCapsB;
  int engineCapsA;
  int scissorXCopy;
  uint stateWord278;
  uint dirtyKeepAny;
  uint dirtyKeepMaskLo;
  uint chipVariantBit2;
  uint dirtyLightMask;
  uint flagChange;
  uint dirtyBits0x7000000;
  uint dirtyWord38Set;
  float newtonTermB;
  float spotDirY;
  float spotDirX;
  float spotDirLengthSq;
  int engineStateWord3188;
  int engineStateWord318c;
  float newtonTerm;
  float rsqrtGuess;
  float lengthSq;
  uint loopIndex3;
  uint dirtyBitsWord0;
  int loopIndex2;
  int remaining;
  int loopIndex;
  uint dirtyBitsWord10;
  uint glContextWord18a4_3;
  uint glContextWord1928_2;
  uint glContextWord1928;
  uint dirtyBitsWord4;
  uint glContextWord18a4;
  char *dirtyBitsWord8;
  int glContextWordNeg74;
  int glContextPtr4_2;
  int glContextPtr1144;
  int glContextPtr4;
  byte glContextByte13b6;
  bool dirtyNegative;
  byte texFlag6c;
  float lightDirLengthSq;
  float lightDirX;
  int drawableHeight;
  uint chipVariantBit;
  float newtonTermA;
  float rsqrtGuessB;
  int scissorRight;
  uint drawBufferFlagA;
  code *glContextPtr12b0;
  uint ctx44Bit15;
  char enabledBitCount;
  int lightDirPtr;
  uint glContextWord18a4_2;
  uint *r4AfterCall;
  uint *r4AfterCall2;
  uint *r4AfterCall3;
  uint *r4AfterCall4;
  uint *r4AfterCall5;
  uint *r4AfterCall6;
  uint *staleR4Chain;
  uint *r4AfterCall7;
  uint *r4AfterCall8;
  uint *r4AfterCall9;
  uint *r4AfterCall10;
  uint *r4AfterCall11;
  uint *r4AfterCall12;
  uint *r4AfterCall13;
  uint *r4AfterCall14;
  uint *r4AfterCall15;
  uint *r4AfterCall16;
  uint *r4AfterCall17;
  char *ctx44Snapshot;
  char *stateWord44Copy;
  int adjustedCount;
  uint stateBit23;
  char pointSpriteFlag;
  undefined *dirtyHighMask;
  uint calleeSavedR20;
  uint calleeSavedR21;
  uint engineState;
  uint dirtyBitsWord3;
  char *dirtyKeepMasked;
  int drawableWidthCopy;
  uint stateWord2cc;
  byte stateByte2eNew;
  int scissorX;
  double vecXYSq;
  double f1AfterCall;
  double f1AfterCall2;
  double f1AfterCall3;
  double vecX;
  double vecY;
  double vecZ;
  double invLength;
  double staleStackArg_ffffff68;
  double staleStackArg_ffffff70;
  double staleStackArg_ffffff78;
  double staleStackArg_ffffff80;
  double staleStackArg_ffffff88;
  int stackWord64;
  int stackWord60;
  int stackWord5c;
  uint stackWord58;
  uint stackWord54;
  uint stackWord50;
  uint stackWord4c;
  int stackWord48;
  int stackWord44;
  float stackFloat40;
  int stackWord3c;
  uint stackWord38;
  uint stackWord34;
  
  dirtyBitsWord0 = *dirtyBits;
  glContextPtr4_2 = *(int *)(glContext + 4);
  dirtyBitsWord8 = (char *)dirtyBits[2];
  if ((((dirtyBitsWord0 & 0x20000180) != 0) || (*(int *)(glContextPtr4_2 + 0x2a48) != *(int *)(glContextPtr4_2 + 0x15c))) ||
     (staleR4Chain = dirtyBits, *(int *)(glContextPtr4_2 + 0x2a4c) != *(int *)(glContextPtr4_2 + 0x160))) {
    fpPassThrough1 = (double)gld_updateSampleConfig(glContextPtr4_2);
    staleR4Chain = r4AfterCall;
  }
  if (*(char *)(glContextPtr4_2 + 0x2a43) != '\0') {
    dirtyBitsWord8 = (char *)((uint)dirtyBitsWord8 | 1);
    dirtyWord4 = *(uint *)(glContext + 0x38) | 0x400;
    *(uint *)(glContext + 0x38) = dirtyWord4;
    *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1002;
    glContext[0x29] = '\x01';
  }
  if (((unsigned char *)0x00002b7d)[glContextPtr4_2] != '\0') {
    glContextPtr4 = *(int *)(glContext + 4);
    drawBufferFlagA = *(uint *)(glContextPtr4 + 0x154) >> 6 & 1;
    ((unsigned char *)0x00001490)[(int)glContext] = (char)drawBufferFlagA;
    ((unsigned char *)0x00001491)[(int)glContext] = (byte)(*(uint *)(glContextPtr4 + 0x154) >> 7) & 1;
    if (drawBufferFlagA != 0) {
      dirtyBitsWord0 = dirtyBitsWord0 | 0x200;
    }
    dirtyBitsWord8 = (char *)((uint)dirtyBitsWord8 | 1);
    glContext[0x29] = '\x01';
    dirtyBitsWord0 = dirtyBitsWord0 | 0x4000001;
    dirtyWord4 = *(uint *)(glContext + 0x38) | 0x4000;
    *(uint *)(glContext + 0x38) = dirtyWord4;
  }
  engineState = *(uint *)(glContextPtr4_2 + 0x10);
  dirtyBitsWord3 = dirtyBits[3];
  engineWord3e28 = *(uint *)(((unsigned char *)0x00003e28) + engineState);
  if (*(int *)(glContextPtr4_2 + 0x1cc) == 0) {
    *(undefined4 *)(glContextPtr4_2 + 0x26c4) = 0;
    *(undefined4 *)(glContextPtr4_2 + 0x26c0) = 0;
    if (dirtyBitsWord8 == (char *)0x0 && dirtyBitsWord3 == 0) goto LAB_000aaa50;
    dirtyBits0x4400000 = dirtyBitsWord3 & 0x4400000;
    if (dirtyBits0x4400000 != 0) {
      glContextWordNeg74 = *(int *)(glContext + -0x74);
      dirtyWord1 = *(char **)(glContext + 0x44);
      dirtyWord4 = glContextWordNeg74 - 1;
      adjustedCount = dirtyWord4 + (glContextWordNeg74 == 0);
      if (glContextWordNeg74 - adjustedCount == ((uint)dirtyWord1 >> 0x14 & 1)) {
        if (((glContextWordNeg74 != adjustedCount) ||
            ((uint)dirtyWord1 >> 0x1f == (uint)(byte)((unsigned char *)0x00002d48)[engineState + 2])) ||
           (((unsigned char *)0x00004304)[engineState] != '\0')) goto LAB_000a9de4;
LAB_000a9c74:
        stateBit23 = *(uint *)(glContext + 0x1874) >> 0x17 & 1;
        *(uint *)(glContext + 0x1928) =
             *(uint *)(glContext + 0x1928) & 0xfffffffd |
             *(uint *)(glContext + 0x1928) >> 1 & 1 ^ stateBit23 | stateBit23 << 1;
        if (((unsigned char *)0x00004304)[engineState] == '\0') {
          glContext[0x2475] = '\x01';
          dirtyWord1 = (char *)((uint)(byte)((unsigned char *)0x00002d48)[engineState + 2] << 0x1f |
                            (uint)dirtyWord1 & 0x7fffffff);
          *(char **)(glContext + 0x44) = dirtyWord1;
        }
        else if ((int)dirtyWord1 < 0) {
          dirtyWord1 = (char *)((uint)dirtyWord1 & 0x7fffffff);
          *(char **)(glContext + 0x44) = dirtyWord1;
          *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
        }
        glContextPtr12b0 = *(code **)(((unsigned char *)0x000012b0) + (int)glContext);
        dirtyWord1 = (char *)((uint)dirtyWord1 & 0xffe7ffff);
        *(char **)(glContext + 0x44) = dirtyWord1;
        glContext[299] = '\x01';
        (*glContextPtr12b0)(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyBits0x4400000,dirtyWord1);
        glContextByte13b6 = ((unsigned char *)0x000013b6)[(int)glContext];
        glContext[0x29] = '\x01';
        dirtyWord38Set = *(uint *)(glContext + 0x38) | 0x58a60;
        *(uint *)(glContext + 0x38) = dirtyWord38Set;
        *(ushort *)(glContext + 0x34) =
             (short)(1 << (glContextByte13b6 & 0x3f)) - 1U | *(ushort *)(glContext + 0x34);
        staleR4Chain = r4AfterCall2;
        fpPassThrough1 = f1AfterCall;
      }
      else {
        if (glContextWordNeg74 == adjustedCount) goto LAB_000a9c74;
        dirtyWord38Set = *(uint *)(glContext + 0x38);
        dirtyWord1 = (char *)((uint)dirtyWord1 | 0x180000);
        *(char **)(glContext + 0x44) = dirtyWord1;
        glContext[299] = '\x01';
        *(uint *)(glContext + 0x1928) =
             *(uint *)(glContext + 0x1928) & 0xfffffffd | *(uint *)(glContext + 0x1928) >> 1 & 1;
      }
      if (((unsigned char *)0x00004304)[engineState] == '\0') {
        if ((int)*(uint *)(glContext + 0x44) < 0) {
          glContextWord18a4 = *(uint *)(glContext + 0x18a4);
          dirtyWord1 = (char *)-(*(ushort *)(((unsigned char *)0x00002d48) + engineState) ^ 0x81fa);
          chipVariantBit = (uint)((*(ushort *)(((unsigned char *)0x00002d48) + engineState) ^ 0x81fa) == 0) << 2;
          *(uint *)(glContext + 0x18a4) = chipVariantBit | glContextWord18a4 & 0xfffffffb;
          *(uint *)(glContext + 0x18a4) =
               ((byte)((unsigned char *)0x00002d48)[engineState + 4] & 1) << 1 | chipVariantBit | glContextWord18a4 & 0xfffffff9;
        }
        else {
          *(uint *)(glContext + 0x18a4) =
               *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        modeBitsCheck = *(uint *)(glContext + 0x44) & 0x80040 ^ 0x80040;
        dirtyBits0x4400000 = -modeBitsCheck;
        *(uint *)(glContext + 0x18a4) =
             (uint)(modeBitsCheck == 0) << 1 |
             *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
      }
      dirtyWord4 = dirtyWord38Set | 0x1000;
      *(uint *)(glContext + 0x38) = dirtyWord4;
      glContext[0x29] = '\x01';
      glContext[0x2d] = glContext[0x2d] | 0xf;
    }
LAB_000a9de4:
    dirtyBits0x7000000 = dirtyBitsWord3 & 0x7000000;
    if (dirtyBits0x7000000 != 0) {
      glContext[0x29] = '\x01';
      stateByte2eNew = glContext[0x2e] | 2;
      if ((dirtyBitsWord3 & 0x5000000) != 0) {
        ctx44Snapshot = *(char **)(glContext + 0x44);
        stateByte2eNew = glContext[0x2e] | 3;
        dirtyBits0x7000000 = (uint)(byte)glContext[0x279c];
        ctx44Bit15 = (uint)ctx44Snapshot >> 0xf & 1;
        ctx44Bit13 = (uint)ctx44Snapshot >> 0xd & 1;
        dirtyWord1 = ctx44Snapshot;
        if (*(int *)(glContext + -0x70) == 0) {
          if (ctx44Bit13 == 0) {
            if (ctx44Bit15 != 0) {
              *(char **)(glContext + 0x44) = (char *)((uint)ctx44Snapshot & 0xfffd7fff);
              *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
              dirtyWord1 = (char *)((uint)ctx44Snapshot & 0xfffd7fff);
              if (((uint)ctx44Snapshot & 0x4000) != 0) {
                glContext[0x29] = '\x01';
                *(char **)(glContext + 0x44) = (char *)((uint)ctx44Snapshot & 0xfffc3fff);
                *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
                dirtyWord1 = (char *)((uint)ctx44Snapshot & 0xfffc3fff);
              }
            }
          }
          else {
            dirtyWord1 = (char *)((uint)ctx44Snapshot & 0xfffddfff);
            *(char **)(glContext + 0x44) = dirtyWord1;
            *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
            fpPassThrough1 = (double)arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyBits0x4400000,dirtyWord1,dirtyBits0x7000000,
                                            ctx44Snapshot);
            staleR4Chain = r4AfterCall3;
          }
        }
        else if (dirtyBits0x7000000 == 0) {
          if (ctx44Bit15 == 0) {
            if (ctx44Bit13 != 0) {
              *(uint *)(glContext + 0x44) = (uint)ctx44Snapshot & 0xfffddfff;
              *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
              arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyBits0x4400000,(uint)ctx44Snapshot & 0xfffddfff,0,
                           ctx44Snapshot);
              ctx44Snapshot = *(char **)(glContext + 0x44);
            }
            glContextPtr1144 = *(int *)(((unsigned char *)0x00001144) + (int)glContext);
            *(uint *)(glContext + 0x44) = (uint)ctx44Snapshot | 0x28000;
            *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) | 0x4000;
            texFlag6c = *(byte *)(glContextPtr1144 + 0x6c);
            ctx44Snapshot = (char *)((texFlag6c & 1) << 0xe | (uint)ctx44Snapshot & 0xffffbfff | 0x28000);
            *(char **)(glContext + 0x44) = ctx44Snapshot;
            if ((texFlag6c & 1) != 0) {
              ctx44Snapshot = (char *)((uint)ctx44Snapshot | 0x10000);
              glContext[0x29] = '\x01';
              *(char **)(glContext + 0x44) = ctx44Snapshot;
              *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
            }
          }
          dirtyBitsArg = (char *)0x0;
          fpPassThrough1 = (double)FUN_0003e320(glContext + -0x240,dirtyBits,0);
          staleR4Chain = r4AfterCall4;
          dirtyWord1 = ctx44Snapshot;
        }
        else if (ctx44Bit13 == 0) {
          if (ctx44Bit15 == 0) {
            stateWord1874 = *(uint *)(glContext + 0x1874);
            stateWord44Copy = ctx44Snapshot;
          }
          else {
            stateWord1874 = *(uint *)(glContext + 0x1874) & 0xffffbfff;
            *(char **)(glContext + 0x44) = (char *)((uint)ctx44Snapshot & 0xfffd7fff);
            *(uint *)(glContext + 0x1874) = stateWord1874;
            stateWord44Copy = (char *)((uint)ctx44Snapshot & 0xfffd7fff);
            if (((uint)ctx44Snapshot & 0x4000) != 0) {
              stateWord44Copy = (char *)((uint)ctx44Snapshot & 0xfffc3fff);
              glContext[0x29] = '\x01';
              *(char **)(glContext + 0x44) = stateWord44Copy;
              ctx44Snapshot = (char *)(*(uint *)(glContext + 0x38) | 0x20);
              *(char **)(glContext + 0x38) = ctx44Snapshot;
            }
          }
          dirtyWord1 = (char *)((uint)stateWord44Copy | 0x22000);
          *(uint *)(glContext + 0x1874) = stateWord1874 | 0x4000;
          *(char **)(glContext + 0x44) = dirtyWord1;
          *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x80000000;
          fpPassThrough1 = (double)arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyBits0x4400000,dirtyWord1,dirtyBits0x7000000,
                                          ctx44Snapshot);
          staleR4Chain = r4AfterCall5;
        }
        glContext[0x2475] = '\x01';
      }
      glContextPtr4 = *(int *)(glContext + 4);
      if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
         ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) {
LAB_000a9ffc:
        zeroFlagA = 0;
      }
      else {
        glContextPtr4 = FUN_0001a010(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),dirtyBitsArg,scratchR6,dirtyBits0x4400000,dirtyWord1
                              ,dirtyBits0x7000000);
        staleR4Chain = r4AfterCall6;
        fpPassThrough1 = f1AfterCall2;
        if (glContextPtr4 != 0) {
          glContextPtr4 = *(int *)(glContext + 4);
          goto LAB_000a9ffc;
        }
        glContextPtr4 = *(int *)(glContext + 4);
        zeroFlagA = 1;
      }
      glContextWord1928_2 = *(uint *)(glContext + 0x1928);
      flagChange = glContextWord1928_2 >> 4 & 1 ^ zeroFlagA;
      *(uint *)(glContext + 0x1928) = glContextWord1928_2 & 0xffffffef | flagChange | zeroFlagA << 4;
      if (((((unsigned char *)0x00002e2c)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
          ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
         (sampleCountFlag = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(glContextPtr4 + 0x10)) == -1)) {
        sampleCountFlag = 0;
      }
      glContext[0x2e] = stateByte2eNew;
      dirtyWord4 = *(uint *)(glContext + 0x38) | 0x2000;
      *(uint *)(glContext + 0x38) = dirtyWord4;
      *(uint *)(glContext + 0x1928) =
           glContextWord1928_2 & 0xffffffe7 | flagChange | zeroFlagA << 4 | (glContextWord1928_2 & 8) >> 3 ^ sampleCountFlag | sampleCountFlag << 3;
    }
    dirtyWord3 = (uint)dirtyBitsWord8 & 1;
    if (dirtyWord3 != 0) {
      sampleCountA = *(byte *)(glContextPtr4_2 + 0x2a5c);
      dirtyWord1 = "ir_undefined";
      engineCapsA = *(int *)(glContextPtr4_2 + 0x10);
      sampleCountB = *(byte *)(glContextPtr4_2 + 0x2a5d);
      dirtyWord4 = (uint)sampleCountB;
      *(ushort *)(((unsigned char *)0x000015fc) + glContextPtr4_2) = (ushort)sampleCountA * (short)*(undefined4 *)(glContextPtr4_2 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + glContextPtr4_2) = (ushort)sampleCountB * (short)*(undefined4 *)(glContextPtr4_2 + 0x160);
      if ((*(double *)(0x00001830 + engineCapsA) == 1.0) && (*(double *)(engineCapsA + 0x1838) == 1.0)) {
        *(uint *)(glContextPtr4_2 + 0x2cc) = *(uint *)(glContextPtr4_2 + 0x2cc) | 0x400000;
      }
      if ((sampleCountA < 2) || (dirtyWord4 < 2)) {
        *(undefined1 *)(glContextPtr4_2 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(glContextPtr4_2 + 0x2690) = 1;
      }
      *(uint *)(glContextPtr4_2 + 0x278) = *(uint *)(glContextPtr4_2 + 0x278) | 0x400;
      *(uint *)(glContextPtr4_2 + 0x27c) = *(uint *)(glContextPtr4_2 + 0x27c) | 3;
      *(undefined1 *)(glContextPtr4_2 + 0x269) = 1;
    }
    engineWord3e28 = 0;
    if ((dirtyBitsWord3 & 0x200000) != 0) {
      if (((unsigned char *)0x00004301)[engineState] != '\0') {
        dirtyBitsWord8 = (char *)((uint)dirtyBitsWord8 | 0xf0);
      }
      engineCapsB = *(int *)(glContextPtr4_2 + 0x10);
      if ((((unsigned char *)0x00004301)[engineCapsB] == '\0') ||
         (engineWord3e28 = (uint)(byte)((unsigned char *)0x000015f4)[glContextPtr4_2], engineWord3e28 == 0)) {
        dirtyWord1 = (char *)0x0;
        enabledBitCount = '\0';
      }
      else {
        dirtyWord1 = (char *)0x0;
        loopIndex3 = 0;
        dirtyWord4 = 1;
        if (engineWord3e28 == 0) {
          engineWord3e28 = 1;
        }
        do {
          dirtyWord3 = (1 << ((byte)((unsigned char *)0x00004300)[engineCapsB] & 0x3f)) - 1U & 1 << (loopIndex3 & 0x3f);
          if (dirtyWord3 != 0) {
            dirtyWord1 = dirtyWord1 + 1;
          }
          loopIndex3 = loopIndex3 + 1;
          engineWord3e28 = engineWord3e28 - 1;
        } while (engineWord3e28 != 0);
        enabledBitCount = (char)dirtyWord1;
      }
      *(char *)(glContextPtr4_2 + 0x2d0) = enabledBitCount;
      if ((dirtyWord1 == (char *)0x0) || (pointSpriteFlag = '\x01', ((unsigned char *)0x00004302)[engineCapsB] == '\0')) {
        pointSpriteFlag = '\0';
      }
      engineWord3e28 = *(uint *)(glContextPtr4_2 + 0x278);
      *(char *)(glContextPtr4_2 + 0x2d1) = enabledBitCount - pointSpriteFlag;
      *(undefined1 *)(glContextPtr4_2 + 0x269) = 1;
      *(uint *)(glContextPtr4_2 + 0x278) = engineWord3e28 | 0x800;
      if (((unsigned char *)0x00002d48)[*(int *)(glContextPtr4_2 + 0x10) + 2] != '\0') {
        *(uint *)(glContextPtr4_2 + 0x278) = engineWord3e28 | 0x820;
      }
    }
    dirtyNegative = (int)dirtyBitsWord8 < 0;
    if (dirtyBitsWord8 != (char *)0x0) {
      dirtyWord1 = (char *)((uint)dirtyBitsWord8 & 0xff0000);
      if (dirtyWord1 != (char *)0x0) {
        dirtyLightMask = (uint)dirtyBitsWord8 >> 0x10 & 0xff;
        if (dirtyLightMask != 0) {
          staleR4Chain = (uint *)0x0;
          do {
            engineWord3e28 = 0;
            if ((dirtyLightMask & 1) != 0) {
              scratchR6 = (undefined *)(*(int *)(glContextPtr4_2 + 0x10) + (int)staleR4Chain * 0x40 + 0x1c60);
              dirtyWord1 = (char *)(stackWord58 | stackWord50 | stackWord4c | stackWord54 ^ (uint)0x3f800000U);
              engineWord3e28 = stackWord38 | stackWord34 | calleeSavedR20 | calleeSavedR21 ^ (uint)0x3f800000U;
              if (((((((stackWord64 == 0 && stackWord60 == 0) && stackWord5c == 0) &&
                     scratchR6 == (undefined *)0x3f800000U) && dirtyWord1 == (char *)0x0) &&
                   (((stackWord48 == 0 && stackWord44 == 0) && stackWord3c == 0) && stackFloat40 == 1.0)) &&
                   engineWord3e28 == 0) &&
                 (*(char *)((int)staleR4Chain + *(int *)(glContextPtr4_2 + 0x25c) + 0x2784) != '\0')) {
                dirtyWord4 = ~(0x10000 << ((uint)staleR4Chain & 0x3f));
              }
              else {
                *(bool *)((int)staleR4Chain + *(int *)(glContextPtr4_2 + 0x25c) + 0x2784) =
                     (((((stackWord64 == 0 && stackWord60 == 0) && stackWord5c == 0) &&
                       scratchR6 == (undefined *)0x3f800000U) && dirtyWord1 == (char *)0x0) &&
                     (((stackWord48 == 0 && stackWord44 == 0) && stackWord3c == 0) && stackFloat40 == 1.0)) &&
                     engineWord3e28 == 0;
                engineWord3e28 = 1 << ((uint)staleR4Chain & 0x3f);
                *(undefined1 *)(glContextPtr4_2 + 0x269) = 1;
                dirtyWord4 = 0xffffffff;
                *(ushort *)(glContextPtr4_2 + 0x272) = (ushort)engineWord3e28 | *(ushort *)(glContextPtr4_2 + 0x272);
                engineWord3e28 = engineWord3e28 | *(uint *)(glContextPtr4_2 + 0x280);
                *(uint *)(glContextPtr4_2 + 0x278) = *(uint *)(glContextPtr4_2 + 0x278) | 0x80;
                *(uint *)(glContextPtr4_2 + 0x280) = engineWord3e28;
              }
              dirtyBitsWord8 = (char *)((uint)dirtyBitsWord8 & dirtyWord4);
            }
            dirtyLightMask = dirtyLightMask >> 1;
            staleR4Chain = (uint *)((int)staleR4Chain + 1);
          } while (dirtyLightMask != 0);
          dirtyNegative = (int)dirtyBitsWord8 < 0;
          dirtyBitsArg = (char *)0x0;
          if (dirtyBitsWord8 == (char *)0x0) goto LAB_000aa35c;
        }
        dirtyBitsArg = (char *)0x0;
        *(undefined1 *)(glContextPtr4_2 + 0x26b5) = 1;
      }
LAB_000aa35c:
      if ((((uint)dirtyBitsWord8 & 0x40000000) != 0) && (((unsigned char *)0x00002d48)[engineState + 2] != '\0')) {
        glContext[0x29] = '\x01';
        dirtyWord4 = *(uint *)(glContext + 0x38) | 0x20;
        *(uint *)(glContext + 0x38) = dirtyWord4;
      }
      if (((uint)dirtyBitsWord8 & 0x3f0000f8) != 0) {
        dirtyBitsArg = dirtyBitsWord8;
        fpPassThrough1 = (double)((double (*)())FUN_000a8630)(glContext,engineState,dirtyBitsWord8,fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,
                                        fpPassThrough5,fpPassThrough6,fpPassThrough7,fpPassThrough8,staleStackArg_ffffff68,
                                        staleStackArg_ffffff70,staleStackArg_ffffff78,staleStackArg_ffffff80,
                                        staleStackArg_ffffff88);
        staleR4Chain = r4AfterCall7;
      }
      if ((((uint)dirtyBitsWord8 & 0x800000f0) != 0) &&
         (((*(char *)(engineState + 0x24ae) != '\0' || (dirtyNegative)) && (((unsigned char *)0x00002d48)[engineState + 2] != '\0')
          ))) {
        glContext[0x29] = '\x01';
        dirtyWord4 = *(uint *)(glContext + 0x38) | 0x20;
        *(uint *)(glContext + 0x38) = dirtyWord4;
      }
      dirtyWord3 = (uint)dirtyBitsWord8 & 0x3f000008;
      if (dirtyWord3 != 0) {
        fpPassThrough1 = (double)((int (*)())gld_transformClipPlanes)(glContextPtr4_2,dirtyBitsWord8);
        staleR4Chain = r4AfterCall8;
      }
    }
    if ((dirtyBitsWord3 & 0x1007ffff) != 0) {
      dirtyWord3 = 0;
      if ((dirtyBitsWord3 & 0x7ffff) != 0) {
        if ((((unsigned char *)0x00004304)[engineState] == '\0') || (*(int *)(glContext + -0x74) != 0)) {
          capsFlag2d4a = (uint)(byte)((unsigned char *)0x00002d48)[engineState + 2] << 0x1f |
                   *(uint *)(glContext + 0x44) & 0x7fffffff;
          *(uint *)(glContext + 0x44) = capsFlag2d4a;
        }
        else {
          capsFlag2d4a = *(uint *)(glContext + 0x44) & 0x7fffffff;
          *(uint *)(glContext + 0x44) = capsFlag2d4a;
        }
        if (((unsigned char *)0x00004304)[engineState] == '\0') {
          if ((int)capsFlag2d4a < 0) {
            glContextWord18a4_3 = *(uint *)(glContext + 0x18a4);
            chipVariantBit2 = (uint)(*(short *)(((unsigned char *)0x00002d48) + engineState) == -0x7e06) << 2;
            *(uint *)(glContext + 0x18a4) = chipVariantBit2 | glContextWord18a4_3 & 0xfffffffb;
            chipVariantBit2 = ((byte)((unsigned char *)0x00002d48)[engineState + 4] & 1) << 1 | chipVariantBit2 | glContextWord18a4_3 & 0xfffffff9;
            *(uint *)(glContext + 0x18a4) = chipVariantBit2;
          }
          else {
            chipVariantBit2 = capsFlag2d4a >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
            *(uint *)(glContext + 0x18a4) = chipVariantBit2;
          }
        }
        else {
          chipVariantBit2 = (uint)((undefined *)(capsFlag2d4a & 0x80040) == ((unsigned char *)0x00080040U)) << 1 |
                   capsFlag2d4a >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
          *(uint *)(glContext + 0x18a4) = chipVariantBit2;
        }
        ctx44SignClear = (capsFlag2d4a & 0x80000000) == 0;
        if (!ctx44SignClear) {
          glContext[0x2f] = '\0';
        }
        if ((dirtyBitsWord3 & 1) != 0) {
          glContext[0x1810] = '\0';
          glContext[0x1811] = '\0';
          glContext[0x1812] = '\0';
          glContext[0x1813] = '\x1f';
          *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x10000;
          *(uint *)(glContext + 0x180c) = *(uint *)(glContext + 0x180c) | 7;
          glContext[0x29] = '\x01';
          if (((unsigned char *)0x00004304)[engineState] == '\0') {
            if (ctx44SignClear) {
              *(uint *)(glContext + 0x18a4) = capsFlag2d4a >> 0x15 & 4 | chipVariantBit2 & 0xfffffff9;
            }
            else {
              chipVariantBitC = (uint)(*(short *)(((unsigned char *)0x00002d48) + engineState) == -0x7e06) << 2;
              *(uint *)(glContext + 0x18a4) = chipVariantBitC | chipVariantBit2 & 0xfffffffb;
              *(uint *)(glContext + 0x18a4) =
                   ((byte)((unsigned char *)0x00002d48)[engineState + 4] & 1) << 1 | chipVariantBitC | chipVariantBit2 & 0xfffffff9;
            }
          }
          else {
            *(uint *)(glContext + 0x18a4) =
                 (uint)((undefined *)(*(uint *)(glContext + 0x44) & 0x80040) == ((unsigned char *)0x00080040U)) << 1 |
                 capsFlag2d4a >> 0x15 & 4 | chipVariantBit2 & 0xfffffff9;
          }
        }
        glContext[0x88] = '\0';
        glContext[0x89] = '\0';
        glContext[0x8a] = '\0';
        glContext[0x8b] = '\0';
        fpPassThrough7 = 1.0;
        fpPassThrough5 = 0.0625;
        fpPassThrough4 = 12.0;
        fpPassThrough3 = -1.0;
        fpPassThrough6 = 3.0;
        remaining = 8;
        staleR4Chain = (uint *)0x0;
        loopIndex = 0x2500;
        scratchR6 = ((unsigned char *)0x000014b0) + (int)glContext;
        loopIndex2 = 0;
        dirtyBitsArg = glContext;
        dirtyWord3 = engineState;
        dirtyWord1 = glContext;
        do {
          engineWord3e28 = *(uint *)(glContext + 0x88);
          *(uint *)(glContext + 0x88) =
               1 << ((uint)staleR4Chain & 0x3f) & *(uint *)(((unsigned char *)0x00002d40) + engineState) | engineWord3e28;
          if ((dirtyBitsWord3 & (0xc << (((uint)staleR4Chain & 0x1f) << 1) | 1U)) != 0) {
            lightDirPtr = engineState + loopIndex;
            *(undefined4 *)(((unsigned char *)0x000014a4) + (int)dirtyWord1) = *(undefined4 *)(dirtyWord3 + 0x24f0);
            *(undefined4 *)(((unsigned char *)0x000014a8) + (int)dirtyWord1) = *(undefined4 *)(dirtyWord3 + 0x24f4);
            *(undefined4 *)(((unsigned char *)0x000014ac) + (int)dirtyWord1) = *(undefined4 *)(dirtyWord3 + 0x24f8);
            *(undefined4 *)(((unsigned char *)0x000014b0) + (int)dirtyWord1) = *(undefined4 *)(dirtyWord3 + 0x24fc);
            lightDirX = *(float *)(engineState + loopIndex);
            lightDirLengthSq = *(float *)(lightDirPtr + 8) * *(float *)(lightDirPtr + 8) +
                    lightDirX * lightDirX + *(float *)(lightDirPtr + 4) * *(float *)(lightDirPtr + 4);
            if (0.0 < lightDirLengthSq) {
              if (lightDirLengthSq == 1.0) {
                *(float *)(scratchR6 + 4) = lightDirX;
                *(undefined4 *)(scratchR6 + 8) = *(undefined4 *)(lightDirPtr + 4);
                *(undefined4 *)(scratchR6 + 0xc) = *(undefined4 *)(lightDirPtr + 8);
              }
              else {
                rsqrtGuessB = (float)(0x5f375a00 - ((uint)GH_F2U(lightDirLengthSq) >> 1));
                lightDirLengthSq = rsqrtGuessB * lightDirLengthSq * rsqrtGuessB;
                newtonTermA = 3.0 - lightDirLengthSq;
                lightDirLengthSq = newtonTermA * rsqrtGuessB * 0.0625 * -(newtonTermA * lightDirLengthSq * newtonTermA - 12.0);
                *(float *)(scratchR6 + 4) = lightDirX * lightDirLengthSq;
                *(float *)(scratchR6 + 8) = lightDirLengthSq * *(float *)(lightDirPtr + 4);
                *(float *)(scratchR6 + 0xc) = lightDirLengthSq * *(float *)(lightDirPtr + 8);
              }
            }
            else {
              *(float *)(scratchR6 + 0xc) = 0.0;
              *(float *)(scratchR6 + 4) = 0.0;
              *(float *)(scratchR6 + 8) = 0.0;
            }
            invLength = 0.0;
            ((unsigned char *)0x0000150c)[(int)dirtyWord1] = *(float *)(dirtyWord3 + 0x250c) != -1.0;
            *(undefined4 *)(((unsigned char *)0x00001504) + (int)dirtyWord1) = *(undefined4 *)(dirtyWord3 + 0x250c);
            if (*(float *)(dirtyWord3 + 0x2510) != 0.0) {
              *(float *)(((unsigned char *)0x00001508) + (int)dirtyWord1) = 1.0 / *(float *)(dirtyWord3 + 0x2510);
            }
            if ((((unsigned char *)0x00002d48)[engineState + 5] == '\0') && (((unsigned char *)0x0000150c)[(int)dirtyWord1] == '\0')) {
              if (*(float *)(((unsigned char *)0x000014b0) + (int)dirtyWord1) == 0.0) {
                vecX = (double)*(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 4));
                vecY = (double)*(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 8));
                vecZ = (double)*(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 0xc));
                vecXYSq = (double)(float)(vecX * vecX + (double)(float)(vecY * vecY));
                lengthSq = (float)(vecZ * vecZ + vecXYSq);
                if (0.0 < lengthSq) {
                  if (lengthSq == 1.0) {
                    fpPassThrough8 = (double)(float)(vecZ + 1.0);
                  }
                  else {
                    rsqrtGuess = (float)(0x5f375a00 - ((uint)GH_F2U(lengthSq) >> 1));
                    lengthSq = rsqrtGuess * lengthSq * rsqrtGuess;
                    newtonTerm = 3.0 - lengthSq;
                    invLength = (double)(newtonTerm * rsqrtGuess * 0.0625 * -(newtonTerm * lengthSq * newtonTerm - 12.0));
                    vecY = (double)(float)(vecY * invLength);
                    vecZ = (double)(float)(vecZ * invLength);
                    vecX = (double)(float)(vecX * invLength);
                    fpPassThrough8 = (double)(float)(vecZ + 1.0);
                    vecXYSq = (double)(float)(vecX * vecX + (double)(float)(vecY * vecY));
                  }
                }
                else {
                  fpPassThrough8 = 1.0;
                  vecXYSq = invLength;
                  vecX = invLength;
                  vecY = invLength;
                  vecZ = invLength;
                }
                lengthSq = (float)(fpPassThrough8 * fpPassThrough8 + vecXYSq);
                *(float *)(((unsigned char *)0x000014fc) + (int)dirtyWord1) = (float)vecZ;
                *(float *)(((unsigned char *)0x000014f4) + (int)dirtyWord1) = (float)vecX;
                *(float *)(((unsigned char *)0x000014f8) + (int)dirtyWord1) = (float)vecY;
                if (0.0 < lengthSq) {
                  if (lengthSq == 1.0) {
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 4)) = (float)vecX;
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 0xc)) = (float)fpPassThrough8;
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 8)) = (float)vecY;
                  }
                  else {
                    rsqrtGuess = (float)(0x5f375a00 - ((uint)GH_F2U(lengthSq) >> 1));
                    lengthSq = rsqrtGuess * lengthSq * rsqrtGuess;
                    newtonTerm = 3.0 - lengthSq;
                    invLength = (double)(newtonTerm * rsqrtGuess * 0.0625 * -(newtonTerm * lengthSq * newtonTerm - 12.0));
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 4)) =
                         (float)(invLength * vecX);
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 0xc)) =
                         (float)(fpPassThrough8 * invLength);
                    *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 8)) =
                         (float)(invLength * vecY);
                  }
                }
                else {
                  *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 4)) = 0.0;
                  *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 0xc)) = 0.0;
                  *(float *)(((unsigned char *)0x000014e0) + (int)(glContext + loopIndex2 + 8)) = 0.0;
                }
              }
            }
            else if (*(float *)(((unsigned char *)0x000014b0) + (int)dirtyWord1) == 0.0) {
              spotDirX = *(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 4));
              spotDirLengthSq = *(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 0xc));
              spotDirY = *(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 8));
              spotDirLengthSq = spotDirLengthSq * spotDirLengthSq + spotDirX * spotDirX + spotDirY * spotDirY;
              if (0.0 < spotDirLengthSq) {
                if (spotDirLengthSq == 1.0) {
                  *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 4)) = spotDirX;
                  *(undefined4 *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 8)) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 8));
                  *(undefined4 *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 0xc)) =
                       *(undefined4 *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 0xc));
                }
                else {
                  rsqrtGuessB = (float)(0x5f375a00 - ((uint)GH_F2U(spotDirLengthSq) >> 1));
                  spotDirLengthSq = rsqrtGuessB * spotDirLengthSq * rsqrtGuessB;
                  newtonTermB = 3.0 - spotDirLengthSq;
                  spotDirLengthSq = newtonTermB * rsqrtGuessB * 0.0625 * -(newtonTermB * spotDirLengthSq * newtonTermB - 12.0);
                  *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 4)) = spotDirX * spotDirLengthSq;
                  *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 8)) =
                       spotDirLengthSq * *(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 8));
                  *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 0xc)) =
                       spotDirLengthSq * *(float *)(((unsigned char *)0x000014a0) + (int)(glContext + loopIndex2 + 0xc));
                }
              }
              else {
                *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 4)) = 0.0;
                *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 0xc)) = 0.0;
                *(float *)(((unsigned char *)0x000014f0) + (int)(glContext + loopIndex2 + 8)) = 0.0;
              }
            }
            reg1814Byte = dirtyBitsArg[0x1814];
            reg181cByte = dirtyBitsArg[0x181c];
            glContext[0x29] = '\x01';
            engineWord3e28 = reg181cByte | 3;
            *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
            dirtyBitsArg[0x1814] = reg1814Byte | 0x3f;
            dirtyBitsArg[0x181c] = (char)engineWord3e28;
          }
          staleR4Chain = (uint *)((int)staleR4Chain + 1);
          loopIndex2 = loopIndex2 + 0x6c;
          scratchR6 = scratchR6 + 0x6c;
          loopIndex = loopIndex + 0x80;
          dirtyBitsArg = dirtyBitsArg + 1;
          dirtyWord1 = dirtyWord1 + 0x6c;
          dirtyWord3 = dirtyWord3 + 0x80;
          remaining = remaining + -1;
        } while (remaining != 0);
        glContext[0x29] = '\x01';
        dirtyWord4 = *(uint *)(glContext + 0x38) | 0x20;
        *(uint *)(glContext + 0x38) = dirtyWord4;
      }
      if ((dirtyBitsWord3 & 0x10000000) != 0) {
        glContext[0x29] = '\x01';
      }
    }
LAB_000aaa50:
    dirtyBitsWord4 = dirtyBits[1];
    dirtyBitsWord10 = dirtyBits[4];
    if (dirtyBitsWord10 != 0 || (dirtyBitsWord4 & 0xff0000) != 0) {
      if ((dirtyBitsWord4 & 0xff0000) != 0) {
        fpPassThrough1 = (double)((int (*)())gld_copyTexCombinerSources)(glContextPtr4_2,dirtyBitsWord4);
        staleR4Chain = r4AfterCall9;
      }
      if (dirtyBitsWord10 != 0) {
        fpPassThrough1 = (double)((int (*)())FUN_000a9070)(glContextPtr4_2,dirtyBitsWord10);
        staleR4Chain = r4AfterCall10;
      }
    }
    if (dirtyBitsWord0 != 0) {
      if ((dirtyBitsWord0 & 1) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1010;
      }
      if ((dirtyBitsWord0 & 6) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1018;
      }
      dirtyWord3 = dirtyBitsWord0 & 0x200;
      if (dirtyWord3 != 0) {
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 1;
      }
      if ((dirtyBitsWord0 & 0x10000000) != 0) {
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x20;
      }
      engineWord3e28 = dirtyBitsWord0 & 0x8000000;
      if (engineWord3e28 != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x40;
      }
      dirtyWord4 = 0;
      if ((dirtyBitsWord0 & 0x4000000) != 0) {
        scissorX = *(int *)(((unsigned char *)0x00003180) + engineState);
        engineWord3e28 = *(uint *)(((unsigned char *)0x00003184) + engineState);
        dirtyWord3 = *(uint *)(((unsigned char *)0x00003188) + engineState);
        engineStateWord318c = *(int *)(((unsigned char *)0x0000318c) + engineState);
        drawableHeight = *(int *)(glContext + -0xe0);
        drawableWidth = *(int *)(glContext + -0xe4);
        *(int *)(glContext + 0x440) = scissorX;
        *(uint *)(glContext + 0x444) = engineWord3e28;
        *(uint *)(glContext + 0x448) = dirtyWord3;
        *(int *)(glContext + 0x44c) = engineStateWord318c;
        if (((unsigned char *)0x00003190)[engineState] == '\0') {
          *(undefined4 *)(((unsigned char *)0x0000135c) + (int)glContext) = 0;
          *(int *)(((unsigned char *)0x00001360) + (int)glContext) = drawableWidth;
          *(int *)(((unsigned char *)0x00001364) + (int)glContext) = drawableHeight;
          *(undefined4 *)(((unsigned char *)0x00001358) + (int)glContext) = 0;
        }
        else {
          if (glContext[0x293c] != '\0') {
            engineWord3e28 = drawableHeight - (engineWord3e28 + engineStateWord318c);
          }
          scissorRight = scissorX + dirtyWord3;
          engineStateWord318c = engineWord3e28 + engineStateWord318c;
          if (scissorX < 0) {
            scissorX = 0;
          }
          if ((int)engineWord3e28 < 0) {
            engineWord3e28 = 0;
          }
          if (scissorRight <= drawableWidth) {
            drawableWidth = scissorRight;
          }
          if (engineStateWord318c <= drawableHeight) {
            drawableHeight = engineStateWord318c;
          }
          *(int *)(((unsigned char *)0x00001358) + (int)glContext) = scissorX;
          *(uint *)(((unsigned char *)0x0000135c) + (int)glContext) = engineWord3e28;
          *(int *)(((unsigned char *)0x00001360) + (int)glContext) = drawableWidth;
          *(int *)(((unsigned char *)0x00001364) + (int)glContext) = drawableHeight;
        }
        dirtyWord4 = *(uint *)(glContext + 0x38) | 2;
        *(uint *)(glContext + 0x38) = dirtyWord4;
      }
      if ((dirtyBitsWord0 & 0x800000) != 0) {
        engineCapsC = *(int *)(*(int *)(glContext + 4) + 0x10);
        if (((((unsigned char *)0x00003178)[engineCapsC] == '\0') ||
            (dirtyWord3 = *(uint *)(glContext + 0x44) & 0x20000, dirtyWord3 != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + engineCapsC) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + engineCapsC) != 0x1b02)))) {
          zeroFlag = 0;
        }
        else {
          zeroFlag = 1;
        }
        engineWord3e28 = *(uint *)(glContext + 0x38);
        dirtyWord4 = engineWord3e28 | 0x4004;
        *(uint *)(glContext + 0x38) = dirtyWord4;
        *(uint *)(glContext + 0x1928) =
             *(uint *)(glContext + 0x1928) & 0xfffffffb | *(uint *)(glContext + 0x1928) >> 2 & 1 ^ zeroFlag
             | zeroFlag << 2;
      }
      dirtyWord1 = (char *)(dirtyBitsWord0 & 0x1c0080);
      if (dirtyWord1 != (char *)0x0) {
        engineWord3e28 = dirtyBitsWord0 & 0x40080;
        if (engineWord3e28 != 0) {
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x40;
        }
        dirtyWord4 = dirtyBitsWord0 & 0x80000;
        if (dirtyWord4 != 0) {
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 1;
        }
        if ((dirtyBitsWord0 & 0x100000) != 0) {
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x20;
        }
      }
      dirtyKeepMaskedB = (char *)(dirtyBitsWord0 & 0xe363fd78);
      if (dirtyKeepMaskedB != (char *)0x0) {
        if ((dirtyBitsWord0 & 0x1800) != 0) {
          dirtyBitsArg = dirtyKeepMaskedB;
          fpPassThrough1 = (double)((int (*)())gld_updateLightingFlags)(glContext,engineState,dirtyKeepMaskedB);
          staleR4Chain = r4AfterCall11;
        }
        if ((dirtyBitsWord0 & 0x3000000) != 0) {
          fpPassThrough1 = (double)((int (*)())FUN_000a8d70)(glContext,engineState);
          staleR4Chain = r4AfterCall12;
          dirtyBitsArg = dirtyKeepMaskedB;
        }
        if ((dirtyBitsWord0 & 0x38) != 0) {
          glContext[0x29] = '\x01';
        }
        if ((dirtyBitsWord0 & 0x100) != 0) {
          fpPassThrough1 = (double)((int (*)())FUN_000a7e80)(glContext);
          staleR4Chain = r4AfterCall13;
        }
        if ((dirtyBitsWord0 & 0x400) != 0) {
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 8;
        }
        if ((dirtyBitsWord0 & 0x2000) != 0) {
          glContext[0x29] = '\x01';
        }
        dirtyWord3 = dirtyBitsWord0 & 0x1c000;
        if (dirtyWord3 != 0) {
          fpPassThrough1 = (double)((int (*)())gld_updateProgramFlags)(glContext,engineState,dirtyBitsArg,scratchR6,dirtyWord3,dirtyWord1,engineWord3e28);
          staleR4Chain = r4AfterCall14;
        }
        if ((dirtyBitsWord0 & 0x20000) != 0) {
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 8;
        }
        if ((dirtyBitsWord0 & 0x400000) != 0) {
          ((double (*)())gld_updatePointState)(glContext,engineState,fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,fpPassThrough7
                       ,fpPassThrough8,staleStackArg_ffffff68,staleStackArg_ffffff70,staleStackArg_ffffff78,
                       staleStackArg_ffffff80);
          staleR4Chain = r4AfterCall15;
        }
        if ((dirtyBitsWord0 & 0x20000000) != 0) {
          ((int (*)())FUN_000a7ea0)(glContext);
          staleR4Chain = r4AfterCall16;
        }
      }
    }
    if (*(char *)(glContextPtr4_2 + 0x26b5) != '\0') {
      gld_updateTexCombinerState(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyWord3,dirtyWord1,engineWord3e28,dirtyWord4);
      *(undefined1 *)(glContextPtr4_2 + 0x26b5) = 0;
    }
    if ((((dirtyBitsWord0 & 0x401800) == 0 && (dirtyBitsWord4 & 0xffffff) == 0) && ((uint)dirtyBitsWord8 & 0x3fff0008) == 0
        ) && (dirtyBitsWord3 & 0x5400002) == 0) {
      return;
    }
    stateWord2cc = *(uint *)(glContextPtr4_2 + 0x2cc);
    engineCapsD = *(int *)(glContextPtr4_2 + 0x10);
    if (((*(uint *)(glContextPtr4_2 + 0x284) & 0x80000800) != 0) ||
       (((((*(uint *)(glContextPtr4_2 + 0x284) & 0x1000000) != 0 &&
          (*(short *)(((unsigned char *)0x00002e06) + engineCapsD) == -0x7bae)) || ((*(uint *)(glContextPtr4_2 + 0x328) & 1) != 0)
         ) || ((*(int *)(((unsigned char *)0x00003e28) + engineCapsD) != 0 || (feedbackFlag = 0, (stateWord2cc & 0xe000000) != 0)))))
       ) {
      feedbackFlag = 1;
    }
    *(uint *)(glContextPtr4_2 + 0x2cc) = feedbackFlag << 0x13 | stateWord2cc & 0xfff7ffff;
    if ((stateWord2cc >> 0x13 & 1) == feedbackFlag) {
      return;
    }
    if (((unsigned char *)0x00004301)[engineCapsD] == '\0') {
      return;
    }
    stateWord278 = *(uint *)(glContextPtr4_2 + 0x278);
    *(undefined1 *)(glContextPtr4_2 + 0x269) = 1;
    *(uint *)(glContextPtr4_2 + 0x278) = stateWord278 | 0x800;
    if (((unsigned char *)0x00002d48)[engineCapsD + 2] == '\0') {
      return;
    }
    *(uint *)(glContextPtr4_2 + 0x278) = stateWord278 | 0x820;
    return;
  }
  engineWord3e28 = engineWord3e28 | (uint)dirtyBitsWord8 & 0x3f000000;
  *(uint *)(glContextPtr4_2 + 0x26c4) = dirtyBitsWord3 & 0x1027ffff;
  if (engineWord3e28 == 0) {
    dirtyKeepMaskHi = 0xc0ff00f8;
    dirtyKeepMaskLo = 0x3f00ff07;
  }
  else {
    dirtyKeepMaskHi = 0xc0ff00f0;
    dirtyKeepMaskLo = 0x3f00ff0f;
  }
  dirtyKeepSelected = (char *)((uint)dirtyBitsWord8 & dirtyKeepMaskLo);
  dirtyHighMask = (undefined *)(dirtyBitsWord3 & 0x4c00000);
  *(uint *)(glContextPtr4_2 + 0x26c0) = (uint)dirtyBitsWord8 & dirtyKeepMaskHi;
  dirtyKeepAny = (uint)dirtyKeepSelected & 0xff00 | (uint)dirtyHighMask;
  if (dirtyKeepAny != 0) {
    engineWord3e28 = 0;
    if ((dirtyBitsWord3 & 0x800000) != 0) {
      engineCapsE = *(int *)(glContextPtr4_2 + 0x10);
      engineWord3e28 = *(uint *)(glContext + 0x44);
      if ((uint)(byte)((unsigned char *)0x00004305)[engineCapsE] != (engineWord3e28 >> 7 & 1)) {
        engineWord3e28 = ((byte)((unsigned char *)0x00004305)[engineCapsE] & 1) << 7 | engineWord3e28 & 0xffffff7f;
        *(uint *)(glContext + 0x44) = engineWord3e28;
        *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1008;
        engineCapsE = *(int *)(glContextPtr4_2 + 0x10);
      }
      if ((uint)(byte)((unsigned char *)0x00004306)[engineCapsE] != (engineWord3e28 >> 6 & 1)) {
        engineWord3e28 = ((byte)((unsigned char *)0x00004306)[engineCapsE] & 1) << 6 | engineWord3e28 & 0xffffffbf;
        *(uint *)(glContext + 0x44) = engineWord3e28;
        *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
      }
    }
    dirtyHighMask = (undefined *)(dirtyBitsWord3 & 0x4400000);
    if (dirtyHighMask != (undefined *)0x0) {
      engineWord3e28 = *(uint *)(glContext + 0x44);
      noVertexProgramMask = -(uint)(*(int *)(glContext + -0x74) == 0);
      if (noVertexProgramMask + 1U == (engineWord3e28 >> 0x14 & 1)) {
        if (((noVertexProgramMask != -1) || (engineWord3e28 >> 0x1f == (uint)(byte)((unsigned char *)0x00002d48)[engineState + 2])) ||
           (((unsigned char *)0x00004304)[engineState] != '\0')) goto LAB_000ab18c;
LAB_000ab014:
        stateBit23B = *(uint *)(glContext + 0x1874) >> 0x17 & 1;
        *(uint *)(glContext + 0x1928) =
             *(uint *)(glContext + 0x1928) & 0xfffffffd | *(uint *)(glContext + 0x1928) >> 1 & 1 ^ stateBit23B
             | stateBit23B << 1;
        if (((unsigned char *)0x00004304)[engineState] == '\0') {
          glContext[0x2475] = '\x01';
          engineWord3e28 = (uint)(byte)((unsigned char *)0x00002d48)[engineState + 2] << 0x1f | engineWord3e28 & 0x7fffffff;
          *(uint *)(glContext + 0x44) = engineWord3e28;
        }
        else if ((int)engineWord3e28 < 0) {
          engineWord3e28 = engineWord3e28 & 0x7fffffff;
          *(uint *)(glContext + 0x44) = engineWord3e28;
          *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
        }
        glContextPtr12b0 = *(code **)(((unsigned char *)0x000012b0) + (int)glContext);
        engineWord3e28 = engineWord3e28 & 0xffe7ffff;
        *(uint *)(glContext + 0x44) = engineWord3e28;
        glContext[299] = '\x01';
        (*glContextPtr12b0)(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyKeepAny,engineWord3e28);
        glContextByte13b6 = ((unsigned char *)0x000013b6)[(int)glContext];
        dirtyHighMask = *(undefined **)(glContext + 0x38);
        glContext[0x29] = '\x01';
        dirtyWord38SetB = (uint)dirtyHighMask | 0x58a60;
        *(uint *)(glContext + 0x38) = dirtyWord38SetB;
        *(ushort *)(glContext + 0x34) =
             (short)(1 << (glContextByte13b6 & 0x3f)) - 1U | *(ushort *)(glContext + 0x34);
      }
      else {
        if (noVertexProgramMask == -1) goto LAB_000ab014;
        dirtyWord38SetB = *(uint *)(glContext + 0x38);
        engineWord3e28 = engineWord3e28 | 0x180000;
        *(uint *)(glContext + 0x44) = engineWord3e28;
        glContext[299] = '\x01';
        dirtyHighMask = (undefined *)(*(uint *)(glContext + 0x1928) >> 1 & 1);
        *(uint *)(glContext + 0x1928) = *(uint *)(glContext + 0x1928) & 0xfffffffd | (uint)dirtyHighMask;
      }
      if (((unsigned char *)0x00004304)[engineState] == '\0') {
        if ((int)*(uint *)(glContext + 0x44) < 0) {
          glContextWord18a4_2 = *(uint *)(glContext + 0x18a4);
          engineWord3e28 = -(*(ushort *)(((unsigned char *)0x00002d48) + engineState) ^ 0x81fa);
          chipVariantBitB = (uint)((*(ushort *)(((unsigned char *)0x00002d48) + engineState) ^ 0x81fa) == 0) << 2;
          *(uint *)(glContext + 0x18a4) = chipVariantBitB | glContextWord18a4_2 & 0xfffffffb;
          *(uint *)(glContext + 0x18a4) =
               ((byte)((unsigned char *)0x00002d48)[engineState + 4] & 1) << 1 | chipVariantBitB | glContextWord18a4_2 & 0xfffffff9;
        }
        else {
          *(uint *)(glContext + 0x18a4) =
               *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
        }
      }
      else {
        dirtyHighMask = ((unsigned char *)0x00080040U);
        modeBitsCheckB = *(uint *)(glContext + 0x44) & 0x80040 ^ 0x80040;
        dirtyKeepAny = -modeBitsCheckB;
        *(uint *)(glContext + 0x18a4) =
             (uint)(modeBitsCheckB == 0) << 1 |
             *(uint *)(glContext + 0x44) >> 0x15 & 4 | *(uint *)(glContext + 0x18a4) & 0xfffffff9;
      }
      *(uint *)(glContext + 0x38) = dirtyWord38SetB | 0x1000;
      glContext[0x29] = '\x01';
      glContext[0x2d] = glContext[0x2d] | 0xf;
    }
LAB_000ab18c:
    dirtyBitsArg = (char *)0x0;
    fpPassThrough1 = (double)FUN_0003b160(glContextPtr4_2,dirtyBits,0);
    staleR4Chain = r4AfterCall17;
  }
  if ((dirtyBitsWord3 & 0x7000000) == 0) goto LAB_000ab460;
  glContext[0x29] = '\x01';
  stateByte2eNewB = glContext[0x2e] | 2;
  if ((dirtyBitsWord3 & 0x5000000) != 0) {
    ctx44WordB = *(uint *)(glContext + 0x44);
    stateByte2eNewB = glContext[0x2e] | 3;
    dirtyHighMask = (undefined *)(uint)(byte)glContext[0x279c];
    ctx44Bit15B = ctx44WordB >> 0xf & 1;
    ctx44Bit13B = ctx44WordB >> 0xd & 1;
    engineWord3e28 = ctx44WordB;
    if (*(int *)(glContext + -0x70) == 0) {
      if (ctx44Bit13B == 0) {
        if (ctx44Bit15B != 0) {
          *(uint *)(glContext + 0x44) = ctx44WordB & 0xfffd7fff;
          *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
          engineWord3e28 = ctx44WordB & 0xfffd7fff;
          if ((ctx44WordB & 0x4000) != 0) {
            glContext[0x29] = '\x01';
            *(uint *)(glContext + 0x44) = ctx44WordB & 0xfffc3fff;
            *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
            engineWord3e28 = ctx44WordB & 0xfffc3fff;
          }
        }
      }
      else {
        engineWord3e28 = ctx44WordB & 0xfffddfff;
        *(uint *)(glContext + 0x44) = engineWord3e28;
        *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
        fpPassThrough1 = (double)arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyKeepAny,engineWord3e28,dirtyHighMask,ctx44WordB
                                       );
      }
    }
    else if (dirtyHighMask == (undefined *)0x0) {
      if (ctx44Bit15B == 0) {
        if (ctx44Bit13B != 0) {
          *(uint *)(glContext + 0x44) = ctx44WordB & 0xfffddfff;
          *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xffffbfff;
          arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyKeepAny,ctx44WordB & 0xfffddfff,0,ctx44WordB);
          ctx44WordB = *(uint *)(glContext + 0x44);
        }
        glContextPtr1144 = *(int *)(((unsigned char *)0x00001144) + (int)glContext);
        *(uint *)(glContext + 0x44) = ctx44WordB | 0x28000;
        *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) | 0x4000;
        texFlag6cB = *(byte *)(glContextPtr1144 + 0x6c);
        ctx44WordB = (texFlag6cB & 1) << 0xe | ctx44WordB & 0xffffbfff | 0x28000;
        *(uint *)(glContext + 0x44) = ctx44WordB;
        if ((texFlag6cB & 1) != 0) {
          ctx44WordB = ctx44WordB | 0x10000;
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x44) = ctx44WordB;
          *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x20;
        }
      }
      dirtyBitsArg = (char *)0x0;
      fpPassThrough1 = (double)FUN_0003e320(glContext + -0x240,dirtyBits,0);
      engineWord3e28 = ctx44WordB;
    }
    else if (ctx44Bit13B == 0) {
      if (ctx44Bit15B == 0) {
        stateWord1874B = *(uint *)(glContext + 0x1874);
        ctx44Word = ctx44WordB;
      }
      else {
        stateWord1874B = *(uint *)(glContext + 0x1874) & 0xffffbfff;
        *(uint *)(glContext + 0x44) = ctx44WordB & 0xfffd7fff;
        *(uint *)(glContext + 0x1874) = stateWord1874B;
        ctx44Word = ctx44WordB & 0xfffd7fff;
        if ((ctx44WordB & 0x4000) != 0) {
          ctx44Word = ctx44WordB & 0xfffc3fff;
          glContext[0x29] = '\x01';
          *(uint *)(glContext + 0x44) = ctx44Word;
          ctx44WordB = *(uint *)(glContext + 0x38) | 0x20;
          *(uint *)(glContext + 0x38) = ctx44WordB;
        }
      }
      engineWord3e28 = ctx44Word | 0x20000;
      dirtyHighMask = (undefined *)(ctx44Word | 0x22000);
      *(uint *)(glContext + 0x1874) = stateWord1874B | 0x4000;
      *(undefined **)(glContext + 0x44) = dirtyHighMask;
      *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x80000000;
      fpPassThrough1 = (double)arbfpUpdateStateForProgram(glContext,staleR4Chain,dirtyBitsArg,scratchR6,dirtyKeepAny,engineWord3e28,dirtyHighMask,ctx44WordB);
    }
    glContext[0x2475] = '\x01';
  }
  glContextPtr4 = *(int *)(glContext + 4);
  if ((((unsigned char *)0x00002e2d)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
     ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) {
LAB_000ab3d0:
    zeroFlagB = 0;
  }
  else {
    glContextPtr4 = FUN_0001a010(glContextPtr4,*(undefined4 *)(glContextPtr4 + 0x26a0),dirtyBitsArg,scratchR6,dirtyKeepAny,engineWord3e28,
                          dirtyHighMask);
    fpPassThrough1 = f1AfterCall3;
    if (glContextPtr4 != 0) {
      glContextPtr4 = *(int *)(glContext + 4);
      goto LAB_000ab3d0;
    }
    glContextPtr4 = *(int *)(glContext + 4);
    zeroFlagB = 1;
  }
  glContextWord1928 = *(uint *)(glContext + 0x1928);
  flagChangeB = glContextWord1928 >> 4 & 1 ^ zeroFlagB;
  *(uint *)(glContext + 0x1928) = glContextWord1928 & 0xffffffef | flagChangeB | zeroFlagB << 4;
  if (((((unsigned char *)0x00002e2c)[*(int *)(glContextPtr4 + 0x10)] == '\0') ||
      ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
     (oneFlag = 1, *(short *)(((unsigned char *)0x00002e28) + *(int *)(glContextPtr4 + 0x10)) == -1)) {
    oneFlag = 0;
  }
  glContext[0x2e] = stateByte2eNewB;
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x2000;
  *(uint *)(glContext + 0x1928) =
       glContextWord1928 & 0xffffffe7 | flagChangeB | zeroFlagB << 4 | (glContextWord1928 & 8) >> 3 ^ oneFlag | oneFlag << 3;
LAB_000ab460:
  if (dirtyKeepSelected != (char *)0x0) {
    if (((uint)dirtyKeepSelected & 1) != 0) {
      sampleCountAB = *(byte *)(glContextPtr4_2 + 0x2a5c);
      engineCapsF = *(int *)(glContextPtr4_2 + 0x10);
      sampleCountBB = *(byte *)(glContextPtr4_2 + 0x2a5d);
      *(ushort *)(((unsigned char *)0x000015fc) + glContextPtr4_2) = (ushort)sampleCountAB * (short)*(undefined4 *)(glContextPtr4_2 + 0x15c);
      *(ushort *)(((unsigned char *)0x000015fa) + glContextPtr4_2) = (ushort)sampleCountBB * (short)*(undefined4 *)(glContextPtr4_2 + 0x160);
      if ((*(double *)(0x00001830 + engineCapsF) == 1.0) && (*(double *)(engineCapsF + 0x1838) == 1.0)) {
        *(uint *)(glContextPtr4_2 + 0x2cc) = *(uint *)(glContextPtr4_2 + 0x2cc) | 0x400000;
      }
      if ((sampleCountAB < 2) || (sampleCountBB < 2)) {
        *(undefined1 *)(glContextPtr4_2 + 0x2690) = 0;
      }
      else {
        *(undefined1 *)(glContextPtr4_2 + 0x2690) = 1;
      }
      *(undefined1 *)(glContextPtr4_2 + 0x269) = 1;
      *(uint *)(glContextPtr4_2 + 0x278) = *(uint *)(glContextPtr4_2 + 0x278) | 0x400;
      *(uint *)(glContextPtr4_2 + 0x27c) = *(uint *)(glContextPtr4_2 + 0x27c) | 3;
    }
    if (((uint)dirtyKeepSelected & 0x3f000008) != 0) {
      dirtyBitsArg = dirtyKeepSelected;
      ((double (*)())FUN_000a8630)(glContext,engineState,dirtyKeepSelected,fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,
                   fpPassThrough7,fpPassThrough8,staleStackArg_ffffff68,staleStackArg_ffffff70,staleStackArg_ffffff78,
                   staleStackArg_ffffff80,staleStackArg_ffffff88);
      fpPassThrough1 = (double)((int (*)())gld_transformClipPlanes)(glContextPtr4_2,dirtyKeepSelected);
    }
  }
  dirtyBits4Word = dirtyBits[4];
  dirtyWord4Lights = dirtyBits[1] & 0xff0000;
  if (dirtyBits4Word != 0 || dirtyWord4Lights != 0) {
    if (dirtyWord4Lights != 0) {
      fpPassThrough1 = (double)((int (*)())gld_copyTexCombinerSources)(glContextPtr4_2,dirtyBits[1]);
    }
    if (dirtyBits4Word != 0) {
      fpPassThrough1 = (double)((int (*)())FUN_000a9070)(glContextPtr4_2,dirtyBits4Word);
    }
  }
  if (dirtyBitsWord0 != 0) {
    if ((dirtyBitsWord0 & 1) != 0) {
      glContext[0x29] = '\x01';
      *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1010;
    }
    if ((dirtyBitsWord0 & 6) != 0) {
      glContext[0x29] = '\x01';
      *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x1018;
    }
    if ((dirtyBitsWord0 & 0x200) != 0) {
      *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 1;
    }
    if ((dirtyBitsWord0 & 0x10000000) != 0) {
      *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x20;
    }
    dirtyBits0x8000000 = dirtyBitsWord0 & 0x8000000;
    if (dirtyBits0x8000000 != 0) {
      glContext[0x29] = '\x01';
      *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x40;
    }
    if ((dirtyBitsWord0 & 0x4000000) != 0) {
      scissorXCopy = *(int *)(((unsigned char *)0x00003180) + engineState);
      dirtyBits0x8000000 = *(uint *)(((unsigned char *)0x00003184) + engineState);
      engineStateWord3188 = *(int *)(((unsigned char *)0x00003188) + engineState);
      engineStateWord318c = *(int *)(((unsigned char *)0x0000318c) + engineState);
      drawableHeightCopy = *(int *)(glContext + -0xe0);
      drawableWidthCopy = *(int *)(glContext + -0xe4);
      *(int *)(glContext + 0x440) = scissorXCopy;
      *(uint *)(glContext + 0x444) = dirtyBits0x8000000;
      *(int *)(glContext + 0x448) = engineStateWord3188;
      *(int *)(glContext + 0x44c) = engineStateWord318c;
      if (((unsigned char *)0x00003190)[engineState] == '\0') {
        *(undefined4 *)(((unsigned char *)0x0000135c) + (int)glContext) = 0;
        *(int *)(((unsigned char *)0x00001360) + (int)glContext) = drawableWidthCopy;
        *(int *)(((unsigned char *)0x00001364) + (int)glContext) = drawableHeightCopy;
        *(undefined4 *)(((unsigned char *)0x00001358) + (int)glContext) = 0;
      }
      else {
        if (glContext[0x293c] != '\0') {
          dirtyBits0x8000000 = drawableHeightCopy - (dirtyBits0x8000000 + engineStateWord318c);
        }
        engineStateWord3188 = scissorXCopy + engineStateWord3188;
        engineStateWord318c = dirtyBits0x8000000 + engineStateWord318c;
        if (scissorXCopy < 0) {
          scissorXCopy = 0;
        }
        if ((int)dirtyBits0x8000000 < 0) {
          dirtyBits0x8000000 = 0;
        }
        if (engineStateWord3188 <= drawableWidthCopy) {
          drawableWidthCopy = engineStateWord3188;
        }
        if (engineStateWord318c <= drawableHeightCopy) {
          drawableHeightCopy = engineStateWord318c;
        }
        *(int *)(((unsigned char *)0x00001358) + (int)glContext) = scissorXCopy;
        *(uint *)(((unsigned char *)0x0000135c) + (int)glContext) = dirtyBits0x8000000;
        *(int *)(((unsigned char *)0x00001360) + (int)glContext) = drawableWidthCopy;
        *(int *)(((unsigned char *)0x00001364) + (int)glContext) = drawableHeightCopy;
      }
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 2;
    }
    if ((dirtyBitsWord0 & 0x800000) != 0) {
      engineCapsG = *(int *)(*(int *)(glContext + 4) + 0x10);
      if (((((unsigned char *)0x00003178)[engineCapsG] == '\0') || ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
         ((*(short *)(((unsigned char *)0x00003170) + engineCapsG) != 0x1b02 &&
          (*(short *)(((unsigned char *)0x00003172) + engineCapsG) != 0x1b02)))) {
        zeroFlagC = 0;
      }
      else {
        zeroFlagC = 1;
      }
      dirtyBits0x8000000 = *(uint *)(glContext + 0x38) | 0x4004;
      *(uint *)(glContext + 0x38) = dirtyBits0x8000000;
      *(uint *)(glContext + 0x1928) =
           *(uint *)(glContext + 0x1928) & 0xfffffffb | *(uint *)(glContext + 0x1928) >> 2 & 1 ^ zeroFlagC
           | zeroFlagC << 2;
    }
    dirtyScissorBits = dirtyBitsWord0 & 0x1c0080;
    if (dirtyScissorBits != 0) {
      dirtyBits0x8000000 = dirtyBitsWord0 & 0x40080;
      if (dirtyBits0x8000000 != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x40;
      }
      if ((dirtyBitsWord0 & 0x80000) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 1;
      }
      if ((dirtyBitsWord0 & 0x100000) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 0x20;
      }
    }
    dirtyKeepMasked = (char *)(dirtyBitsWord0 & 0xe363fd78);
    if (dirtyKeepMasked != (char *)0x0) {
      if ((dirtyBitsWord0 & 0x1800) != 0) {
        dirtyBitsArg = dirtyKeepMasked;
        fpPassThrough1 = (double)((int (*)())gld_updateLightingFlags)(glContext,engineState,dirtyKeepMasked);
      }
      if ((dirtyBitsWord0 & 0x3000000) != 0) {
        fpPassThrough1 = (double)((int (*)())FUN_000a8d70)(glContext,engineState);
        dirtyBitsArg = dirtyKeepMasked;
      }
      if ((dirtyBitsWord0 & 0x38) != 0) {
        glContext[0x29] = '\x01';
      }
      if ((dirtyBitsWord0 & 0x100) != 0) {
        fpPassThrough1 = (double)((int (*)())FUN_000a7e80)(glContext);
      }
      if ((dirtyBitsWord0 & 0x400) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 8;
      }
      if ((dirtyBitsWord0 & 0x2000) != 0) {
        glContext[0x29] = '\x01';
      }
      if ((dirtyBitsWord0 & 0x1c000) != 0) {
        fpPassThrough1 = (double)((int (*)())gld_updateProgramFlags)(glContext,engineState,dirtyBitsArg,scratchR6,dirtyBitsWord0 & 0x1c000,dirtyScissorBits,
                                        dirtyBits0x8000000);
      }
      if ((dirtyBitsWord0 & 0x20000) != 0) {
        glContext[0x29] = '\x01';
        *(uint *)(glContext + 0x3c) = *(uint *)(glContext + 0x3c) | 8;
      }
      if ((dirtyBitsWord0 & 0x400000) != 0) {
        ((double (*)())gld_updatePointState)(glContext,engineState,fpPassThrough1,fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,fpPassThrough7,
                     fpPassThrough8,staleStackArg_ffffff68,staleStackArg_ffffff70,staleStackArg_ffffff78,
                     staleStackArg_ffffff80);
      }
      if ((dirtyBitsWord0 & 0x20000000) != 0) {
        ((int (*)())FUN_000a7ea0)(glContext);
      }
    }
  }
  return;
}

/* FUN_000ab900 @ 0xab900 (60 bytes) */
int FUN_000ab900(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x1868) != '\0') {
    *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b40;
    return;
  }
  *(undefined **)((int)((unsigned char *)0x000011cc) + param_1) = PTR_FUN_001e8b3c;
  return;
}

/* FUN_000ab940 @ 0xab940 (96 bytes) */
int FUN_000ab940(srcKind, srcValue, unusedArgR5, outOperand, outIsSpecial, altSrcValue)
  int srcKind;
  int srcValue;
  undefined4 unusedArgR5;
  int *outOperand;
  undefined1 *outIsSpecial;
  int altSrcValue;
{
  if (srcKind == 3) {
    if (srcValue == 1) {
      outOperand[1] = 0x18;
      *outOperand = 0;
    }
    else {
      *outOperand = altSrcValue;
      outOperand[1] = 0x17;
    }
    *outIsSpecial = 1;
    return;
  }
  *outOperand = srcValue;
  outOperand[1] = 4;
  *outIsSpecial = 0;
  return;
}

/* gld_classifyOperand @ 0xab9b0 (240 bytes) */
int gld_classifyOperand(operandSpace, operandIndex, unusedArgR5, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9, unusedArgR10, operandTable, outOperand)
  int operandSpace;
  int operandIndex;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
  undefined4 unusedArgR10;
  int operandTable;
  int *outOperand;
{
  int entryValue;
  int entryKind;
  int entryAddr;
  
  if (operandSpace == 1) {
    entryAddr = operandIndex * 0x14 + operandTable;
    entryKind = *(int *)(entryAddr + 8);
    entryValue = *(int *)(entryAddr + 0xc);
    if (entryKind == 1) {
      if (entryValue == 0) {
        *outOperand = 0;
        outOperand[1] = 0x12;
        return;
      }
      outOperand[1] = 0x13;
      *outOperand = 0;
      return;
    }
    if (entryKind == 3) {
      outOperand[1] = 0x10;
      *outOperand = 0;
      return;
    }
    if (entryKind == 4) {
      outOperand[1] = 0x16;
      *outOperand = 0;
      return;
    }
    *outOperand = entryValue;
    outOperand[1] = 0x11;
    return;
  }
  if (operandSpace == 0) {
    *outOperand = operandIndex;
    outOperand[1] = 4;
    return;
  }
  if (operandSpace != 2) {
    return;
  }
  *outOperand = operandIndex;
  outOperand[1] = 1;
  return;
}

/* FUN_000abab0 @ 0xabab0 (164 bytes) */
void FUN_000abab0(int glContext,int a1,undefined4 a2,double fpPassThrough1)
{
  int iVar1;
  undefined1 auStack_70 [16];
  undefined1 auStack_30 [20];
  
  iVar1 = *(int *)(*(int *)(a1 + 0x74) + 0x84) * -0x10;
  *(unsigned char **)(auStack_70 + iVar1) = ((unsigned int)__builtin_frame_address(0));
  ((double (*)())FUN_00024fe0)(*(undefined4 *)(glContext + 4),*(undefined4 *)(*(int *)(a1 + 0x74) + 0x84),
               auStack_30 + iVar1,fpPassThrough1);
  (**(code **)(((unsigned char *)0x00001280) + glContext))
            (glContext,a2,0,0,auStack_30 + iVar1,*(undefined4 *)(*(int *)(a1 + 0x74) + 0x84)
             ,1);
  return;
}

/* FUN_000abb60 @ 0xabb60 (96 bytes) */
int FUN_000abb60(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(((unsigned char *)0x0000121c) + param_1) != 0) {
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x74);
    if (*(char *)(iVar1 + 0x54) == '\0') {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                       *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 + 0x74);
    }
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 8);
    }
  }
  return 0;
}

/* gld_scanOperandRegisterCount @ 0xabbd0 (312 bytes) */
int gld_scanOperandRegisterCount(packet, hasHeaderWord, operandCount, a12)
  int packet;
  int hasHeaderWord;
  int operandCount;
  int a12;
{
  int registerCount;
  uint *nextWordCursor;
  uint *operandCursor;
  uint operandWord;
  
  operandCursor = (uint *)(packet + 4);
  if (hasHeaderWord != 0) {
    operandWord = *(uint *)(packet + 4);
    operandCursor = (uint *)(packet + 8);
    if ((operandWord & 0x3f0000) == 0x180000) {
      *(undefined1 *)(*(int *)(a12 + 0x74) + 4) = 1;
    }
    if ((operandWord & 0x400000) != 0) {
      operandCursor = (uint *)(packet + 0xc);
    }
  }
  nextWordCursor = operandCursor;
  if (0 < operandCount) {
    operandWord = *operandCursor;
    nextWordCursor = operandCursor + 1;
    if ((operandWord & 0x400000) != 0) {
      nextWordCursor = operandCursor + 2;
    }
    if ((operandWord >> 0x10 & 0x3f) - 1 < 2) {
      registerCount = (operandWord & 0xffff) + 1;
      if (*(int *)(*(int *)(a12 + 0x74) + 0x84) < registerCount) {
        *(int *)(*(int *)(a12 + 0x74) + 0x84) = registerCount;
      }
    }
  }
  operandCursor = nextWordCursor;
  if (1 < operandCount) {
    operandWord = *nextWordCursor;
    operandCursor = nextWordCursor + 1;
    if ((operandWord & 0x400000) != 0) {
      operandCursor = nextWordCursor + 2;
    }
    if ((operandWord >> 0x10 & 0x3f) - 1 < 2) {
      registerCount = (operandWord & 0xffff) + 1;
      if (*(int *)(*(int *)(a12 + 0x74) + 0x84) < registerCount) {
        *(int *)(*(int *)(a12 + 0x74) + 0x84) = registerCount;
      }
    }
  }
  if (operandCount < 3) {
    return operandCursor;
  }
  operandWord = *operandCursor;
  nextWordCursor = operandCursor + 2;
  if ((operandWord & 0x400000) == 0) {
    nextWordCursor = operandCursor + 1;
  }
  if (1 < (operandWord >> 0x10 & 0x3f) - 1) {
    return nextWordCursor;
  }
  registerCount = (operandWord & 0xffff) + 1;
  if (registerCount <= *(int *)(*(int *)(a12 + 0x74) + 0x84)) {
    return nextWordCursor;
  }
  *(int *)(*(int *)(a12 + 0x74) + 0x84) = registerCount;
  return nextWordCursor;
}

/* gld_scanProgramTokens @ 0xabd10 (1640 bytes) */
int gld_scanProgramTokens(glContext, a12, tokenInfo)
  int glContext;
  int a12;
  uint *tokenInfo;
{
  int operandRegCountB;
  int operandRegCount;
  int constRegCount;
  float *afterOperandCursor;
  float *afterConstCursor;
  uint constKind;
  uint inputIndex;
  uint outputKind;
  float constToken;
  float cursor2Word0;
  float cursorWord0;
  uint allocation;
  float *cursor2;
  float *cursor;
  int a12Ptr74_2;
  undefined4 samplerKindCode;
  uint tokenCount;
  uint tokenBase;
  float *outputOperandPtr;
  int a12Ptr74;
  float tokenWord;
  float *secondOperandPtr;
  undefined4 slotRecord;
  int inputByteOffset;
  int tokenBytes;
  float *tokenCursor;
  float operandScratch0;
  float operandScratch1;
  float operandScratch2;
  float operandScratch3;
  undefined4 i2dHi0;
  float negConstLo0;
  undefined4 i2dHi1;
  float negConstLo1;
  undefined4 i2dHi2;
  float negConstLo2;
  undefined4 i2dHi3;
  float negConstLo3;
  
  a12Ptr74_2 = *(int *)(a12 + 0x74);
  tokenBytes = *(int *)(a12Ptr74_2 + 0x5c) + -10;
  allocation = (**(code **)(glContext + 0xc))(*(int *)(a12Ptr74_2 + 0x5c) + -6,a12,tokenInfo);
  tokenInfo[2] = allocation;
  _memcpy(allocation,*(int *)(a12Ptr74_2 + 0x58) + 10,tokenBytes);
  tokenBase = tokenInfo[2];
  tokenCursor = (float *)(tokenBase + 8);
  tokenCount = *(int *)(a12Ptr74_2 + 0x5c) - 10U >> 2;
  *tokenInfo = tokenCount;
  tokenInfo[1] = tokenCount + 1;
  slotRecord = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + *(int *)(a12 + 0x70));
  *(undefined1 *)(*(int *)(a12 + 0x74) + 4) = 0;
  *(undefined1 *)(*(int *)(a12 + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(a12 + 0x74) + 5) = 0;
  *(undefined4 *)(*(int *)(a12 + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(a12 + 0x74) + 0x10) = 0;
  **(undefined1 **)(a12 + 0x74) = 0;
  *(undefined1 *)(*(int *)(a12 + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(a12 + 0x74) + 2) = 0;
  *(undefined1 *)(a12 + 0x6c) = 1;
  while (tokenCursor < (float *)(tokenBase + tokenBytes)) {
    tokenWord = *tokenCursor;
    switch((uint)GH_F2U(tokenWord) & 0xffff) {
    default:
      goto switchD_000abe1c_caseD_0;
    case 1:
    case 2:
    case 4:
    case 5:
    case 0xb:
    case 0xe:
    case 0x12:
    case 0x1e:
    case 0x25:
    case 0x26:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x30:
    case 0x31:
    case 0x33:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3c:
    case 0x3d:
    case 0x47:
    case 0x48:
    case 0x4a:
    case 0x4c:
    case 0x4d:
    case 0x50:
    case 0x51:
    case 0x54:
    case 0x55:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5c:
    case 0x62:
    case 99:
      tokenCursor = (float *)((int (*)())gld_scanOperandRegisterCount)(tokenCursor,1,1,a12);
      break;
    case 3:
    case 0xc:
    case 0x13:
    case 0x1f:
    case 0x20:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x41:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x49:
    case 0x4e:
    case 0x52:
    case 0x56:
    case 0x5b:
      tokenCursor = (float *)((int (*)())gld_scanOperandRegisterCount)(tokenCursor,1,2,a12);
      break;
    case 10:
    case 0xd:
    case 0x21:
    case 0x2f:
    case 0x3f:
    case 0x40:
    case 100:
      tokenCursor = (float *)((int (*)())gld_scanOperandRegisterCount)(tokenCursor,1,3,a12);
      break;
    case 0xf:
      tokenCursor = tokenCursor + *(ushort *)((int)tokenCursor + 6) + 2;
      break;
    case 0x14:
      tokenCursor = tokenCursor + 3;
      break;
    case 0x16:
      outputOperandPtr = tokenCursor + 1;
      tokenCursor = tokenCursor + 2;
      outputKind = (uint)GH_F2U(*outputOperandPtr) >> 0x10 & 0x3f;
      if (outputKind == 0x11) {
        *(uint *)(*(int *)(a12 + 0x74) + 0xc) =
             1 << ((uint)GH_F2U(*outputOperandPtr) & 0x3f) | *(uint *)(*(int *)(a12 + 0x74) + 0xc);
      }
      else if (outputKind < 0x12) {
        if (outputKind == 0x10) {
          *(undefined1 *)(*(int *)(a12 + 0x74) + 1) = 1;
        }
      }
      else if (outputKind == 0x13) {
        **(undefined1 **)(a12 + 0x74) = 1;
      }
      else if (outputKind == 0x16) {
        *(undefined1 *)(*(int *)(a12 + 0x74) + 2) = 1;
      }
      break;
    case 0x18:
      break;
    case 0x19:
      inputIndex = (uint)GH_F2U(tokenWord) >> 0x10 & 0xff;
      tokenCursor = tokenCursor + 1;
      *(uint *)(*(int *)(a12 + 0x74) + 0x10) =
           1 << ((uint)GH_F2U(tokenWord) >> 0x10 & 0x3f) | *(uint *)(*(int *)(a12 + 0x74) + 0x10);
      switch((uint)GH_F2U(tokenWord) >> 0x18 & 7) {
      case 0:
        inputByteOffset = inputIndex * 4;
        if (*(int *)(((unsigned char *)0x000013f8) + inputByteOffset + glContext) == 0) {
switchD_000ac280_caseD_4:
          *(undefined4 *)(inputByteOffset + *(int *)(a12 + 0x74) + 0x14) = 1;
        }
        else {
          switch(*(undefined1 *)(*(int *)(((unsigned char *)0x000013f8) + inputByteOffset + glContext) + 0x30)) {
          case 0:
            *(undefined4 *)(inputByteOffset + *(int *)(a12 + 0x74) + 0x14) = 4;
            break;
          case 1:
            *(undefined4 *)(inputByteOffset + *(int *)(a12 + 0x74) + 0x14) = 3;
            break;
          case 2:
            *(undefined4 *)(inputByteOffset + *(int *)(a12 + 0x74) + 0x14) = 5;
            break;
          case 3:
            *(undefined4 *)(inputByteOffset + *(int *)(a12 + 0x74) + 0x14) = 2;
            break;
          case 4:
            goto switchD_000ac280_caseD_4;
          }
        }
        break;
      case 1:
        *(undefined4 *)(inputIndex * 4 + *(int *)(a12 + 0x74) + 0x14) = 1;
        break;
      case 2:
        samplerKindCode = 5;
        if (((uint)GH_F2U(tokenWord) & 0x18000000) != 0x10000000) {
          samplerKindCode = 2;
        }
        *(undefined4 *)(inputIndex * 4 + *(int *)(a12 + 0x74) + 0x14) = samplerKindCode;
        break;
      case 3:
        *(undefined4 *)(inputIndex * 4 + *(int *)(a12 + 0x74) + 0x14) = 3;
        break;
      case 4:
        *(undefined4 *)(inputIndex * 4 + *(int *)(a12 + 0x74) + 0x14) = 4;
      }
      break;
    case 0x1c:
      constToken = tokenCursor[1];
      constKind = (uint)GH_F2U(constToken) >> 0x10 & 0x3f;
      if (constKind == 1) {
        (**(code **)(((unsigned char *)0x00001280) + glContext))
                  (glContext,slotRecord,(uint)GH_F2U(constToken) & 0xffff,(uint)GH_F2U(constToken) & 0xffff,tokenCursor + 2,1,0);
        afterConstCursor = tokenCursor + 6;
      }
      else {
        afterConstCursor = tokenCursor + 1;
        if (constKind == 2) {
          i2dHi0 = 0x43300000;
          negConstLo0 = -tokenCursor[2];
          operandScratch0 = (float)((double)CONCAT44(0x43300000,negConstLo0) - 4503601774854144.0);
          i2dHi1 = 0x43300000;
          negConstLo1 = -tokenCursor[3];
          operandScratch1 = (float)((double)CONCAT44(0x43300000,negConstLo1) - 4503601774854144.0);
          i2dHi2 = 0x43300000;
          negConstLo2 = -tokenCursor[4];
          operandScratch2 = (float)((double)CONCAT44(0x43300000,negConstLo2) - 4503601774854144.0);
          i2dHi3 = 0x43300000;
          negConstLo3 = -tokenCursor[5];
          operandScratch3 = (float)((double)CONCAT44(0x43300000,negConstLo3) - 4503601774854144.0);
          (**(code **)(((unsigned char *)0x00001280) + glContext))
                    (glContext,slotRecord,(uint)GH_F2U(constToken) & 0xffff,(uint)GH_F2U(constToken) & 0xffff,&operandScratch0,1,0,
                     *(code **)(((unsigned char *)0x00001280) + glContext));
          afterConstCursor = tokenCursor + 6;
        }
      }
      tokenCursor = afterConstCursor;
      constRegCount = ((uint)GH_F2U(constToken) & 0xffff) + 1;
      if (*(int *)(*(int *)(a12 + 0x74) + 0x84) < constRegCount) {
        *(int *)(*(int *)(a12 + 0x74) + 0x84) = constRegCount;
      }
      break;
    case 0x37:
      tokenCursor = (float *)((int (*)())gld_scanOperandRegisterCount)(tokenCursor,0,1,a12);
      *(undefined1 *)(*(int *)(a12 + 0x74) + 3) = 1;
      break;
    case 0x4b:
      tokenCursor = tokenCursor + 1;
      break;
    case 0x5d:
      cursor = tokenCursor + 1;
      if ((int)GH_F2U(tokenWord) < 0) {
        cursor = tokenCursor + 2;
      }
      if (((uint)GH_F2U(tokenWord) & 0x40000000) != 0) {
        cursor = cursor + 1;
      }
      cursorWord0 = *cursor;
      secondOperandPtr = cursor + 1;
      if (((uint)GH_F2U(cursorWord0) & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(a12 + 0x74) + 4) = 1;
      }
      if (((uint)GH_F2U(cursorWord0) & 0x400000) != 0) {
        secondOperandPtr = cursor + 2;
      }
      operandScratch0 = *secondOperandPtr;
      tokenCursor = secondOperandPtr + 1;
      if (((uint)GH_F2U(operandScratch0) & 0x400000) != 0) {
        tokenCursor = secondOperandPtr + 2;
      }
      if (((uint)GH_F2U(operandScratch0) >> 0x10 & 0x3f) - 1 < 2) {
        a12Ptr74 = *(int *)(a12 + 0x74);
        operandRegCount = ((uint)GH_F2U(operandScratch0) & 0xffff) + 1;
        if (*(int *)(a12Ptr74 + 0x84) < operandRegCount) {
LAB_000ac4f8:
          *(int *)(a12Ptr74 + 0x84) = operandRegCount;
        }
      }
      break;
    case 0x5e:
      cursor2 = tokenCursor + 1;
      if ((int)GH_F2U(tokenWord) < 0) {
        cursor2 = tokenCursor + 2;
      }
      if (((uint)GH_F2U(tokenWord) & 0x40000000) != 0) {
        cursor2 = cursor2 + 1;
      }
      cursor2Word0 = *cursor2;
      tokenCursor = cursor2 + 1;
      if (((uint)GH_F2U(cursor2Word0) & 0x3f0000) == 0x180000) {
        *(undefined1 *)(*(int *)(a12 + 0x74) + 4) = 1;
      }
      if (((uint)GH_F2U(cursor2Word0) & 0x400000) != 0) {
        tokenCursor = cursor2 + 2;
      }
      operandScratch0 = *tokenCursor;
      afterOperandCursor = tokenCursor + 1;
      if (((uint)GH_F2U(operandScratch0) & 0x400000) != 0) {
        afterOperandCursor = tokenCursor + 2;
      }
      if (((uint)GH_F2U(operandScratch0) >> 0x10 & 0x3f) - 1 < 2) {
        operandRegCountB = ((uint)GH_F2U(operandScratch0) & 0xffff) + 1;
        if (*(int *)(*(int *)(a12 + 0x74) + 0x84) < operandRegCountB) {
          *(int *)(*(int *)(a12 + 0x74) + 0x84) = operandRegCountB;
        }
      }
      operandScratch1 = *afterOperandCursor;
      tokenCursor = afterOperandCursor + 1;
      if (((uint)GH_F2U(operandScratch1) & 0x400000) != 0) {
        tokenCursor = afterOperandCursor + 2;
      }
      if (((uint)GH_F2U(operandScratch1) >> 0x10 & 0x3f) - 1 < 2) {
        a12Ptr74 = *(int *)(a12 + 0x74);
        operandRegCount = ((uint)GH_F2U(operandScratch1) & 0xffff) + 1;
        if (*(int *)(a12Ptr74 + 0x84) < operandRegCount) goto LAB_000ac4f8;
      }
    }
  }
switchD_000abe1c_caseD_0:
  return 1;
}

/* FUN_000ac540 @ 0xac540 (476 bytes) */
int FUN_000ac540(glContext, wordVector, param_3, param_4)
  int glContext;
  uint *wordVector;
  uint param_3;
  uint param_4;
{
  uint wordVectorWord0;
  uint allocation3;
  uint allocation2;
  uint allocation;
  uint uVar1;
  
  wordVectorWord0 = *wordVector;
  if (wordVector[1] <= wordVectorWord0) {
    allocation = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation;
    wordVectorWord0 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(undefined4 *)(wordVectorWord0 * 4 + wordVector[2]) = 0xe;
  uVar1 = *wordVector + 1;
  *wordVector = uVar1;
  if (wordVector[1] <= uVar1) {
    allocation2 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation2,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation2;
    uVar1 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(uint *)(uVar1 * 4 + wordVector[2]) = param_4 & 0xffff | 0x170000;
  uVar1 = *wordVector + 1;
  *wordVector = uVar1;
  if (wordVector[1] <= uVar1) {
    allocation3 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation3,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation3;
    uVar1 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(uint *)(uVar1 * 4 + wordVector[2]) = param_3 & 0xffff | 0x40000;
  *wordVector = *wordVector + 1;
  return;
}

/* FUN_000ac720 @ 0xac720 (7944 bytes) */
int FUN_000ac720(glContext, a1Ptr74, wordVector, formatCode, formatDesc, flagBits, param_7, param_8, formatDesc2, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22, param_23, param_24, param_25)
  int glContext;
  int a1Ptr74;
  uint *wordVector;
  int formatCode;
  uint *formatDesc;
  uint flagBits;
  uint *param_7;
  uint *param_8;
  uint *formatDesc2;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  undefined4 param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  undefined4 param_22;
  undefined4 param_23;
  undefined4 param_24;
  undefined4 param_25;
{
  uint wordVectorWord0_3;
  uint wordVectorWord0_2;
  uint wordVectorWord0;
  uint allocation20;
  uint allocation19;
  uint allocation18;
  uint allocation17;
  uint allocation16;
  uint allocation15;
  uint allocation14;
  uint allocation13;
  uint allocation12;
  uint allocation11;
  uint allocation10;
  uint allocation9;
  uint allocation8;
  uint allocation7;
  uint allocation6;
  uint allocation5;
  uint allocation4;
  uint allocation3;
  uint allocation2;
  uint allocation;
  int loopIndex8;
  int loopIndex7;
  int loopIndex6;
  int loopIndex4;
  int loopIndex3;
  int remaining4;
  int remaining3;
  int loopIndex2;
  int remaining2;
  int remaining;
  int loopIndex;
  int glContextWord11e0;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint *cursor;
  uint uVar18;
  uint uVar19;
  int loopIndex5;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  uint local_7c [9];
  int local_58;
  undefined4 local_54;
  
  uVar18 = 0;
  uVar13 = 0;
  local_58 = a1Ptr74;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c[0] = 0;
  local_7c[1] = 0;
  local_7c[2] = 0;
  local_54 = param_25;
  if ((formatCode - 0x21U < 0x20) && ((1 << (formatCode - 0x21U & 0x3f) & 0x8fffffffU) != 0)) {
    uVar18 = 0x100;
  }
  if (formatDesc[1] == 0x18) {
    uVar18 = 0x100;
  }
  uVar12 = flagBits >> 2 & 1;
  uVar2 = (flagBits >> 1 & 1) << 2;
  uVar3 = uVar12 << 4;
  uVar16 = (formatDesc[1] & 0x3f) << 0x10 | *formatDesc & 0xffff | 0x400000;
  uVar4 = (flagBits >> 3 & 1) << 6;
  uVar19 = uVar4 | uVar3 | uVar2 | flagBits & 1 | uVar18;
  switch(formatCode) {
  case 0:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xc:
  case 0x12:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x19:
  case 0x1c:
  case 0x21:
  case 0x24:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x32:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
  case 0x3c:
    loopIndex = 1;
    goto LAB_000ad33c;
  case 1:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x10:
  case 0x11:
  case 0x13:
  case 0x14:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x20:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x30:
  case 0x31:
  case 0x33:
  case 0x34:
  case 0x38:
  case 0x3a:
  case 0x3b:
  case 0x40:
    loopIndex = 1;
    goto LAB_000ace5c;
  case 2:
  case 0xe:
  case 0xf:
  case 0x23:
  case 0x2e:
  case 0x2f:
    local_7c[6] = param_24;
    local_7c[5] = param_23;
    local_7c[4] = param_22;
    local_7c[3] = param_21;
    local_80 = *formatDesc2 & 0xffff;
    local_80 = (formatDesc2[1] & 0x3f) << 0x10 | local_80 | 0x400000;
    if (formatDesc2[1] == 0x10) {
      loopIndex2 = 0;
      remaining = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + loopIndex2 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        remaining = remaining + -1;
        *(undefined4 *)((int)local_7c + loopIndex2 + 0xc) = uVar5;
        loopIndex2 = loopIndex2 + 4;
      } while (remaining != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[2] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[2] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[2] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[2] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[2] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[2] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[2] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[2] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[2] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[2] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[2] = 5;
    }
    if (bVar1) {
      local_7c[2] = local_7c[2] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    local_7c[2] = iVar14 << 4 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    local_7c[2] = iVar14 << 8 | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    local_7c[2] = iVar14 << 0xc | local_7c[2];
    if (bVar1) {
      local_7c[2] = local_7c[2] | 0x8000;
    }
    loopIndex = 2;
    if ((char)param_12 != '\0') {
      local_7c[2] = (local_7c[2] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[2] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[2] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[2] ^ 8) & 8 | local_7c[2] & 0xffff7777;
    }
LAB_000ace5c:
    local_7c[6] = param_20;
    local_7c[5] = param_19;
    local_7c[4] = param_18;
    local_7c[3] = param_17;
    local_84 = (param_8[1] & 0x3f) << 0x10 | *param_8 & 0xffff | 0x400000;
    if (param_8[1] == 0x10) {
      loopIndex5 = 0;
      remaining3 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + loopIndex5 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        remaining3 = remaining3 + -1;
        *(undefined4 *)((int)local_7c + loopIndex5 + 0xc) = uVar5;
        loopIndex5 = loopIndex5 + 4;
      } while (remaining3 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[1] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[1] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[1] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[1] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[1] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[1] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[1] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[1] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[1] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[1] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[1] = 5;
    }
    if (bVar1) {
      local_7c[1] = local_7c[1] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[1] = iVar15 << 4 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[1] = iVar15 << 8 | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[1] = iVar15 << 0xc | local_7c[1];
    if (bVar1) {
      local_7c[1] = local_7c[1] | 0x8000;
    }
    loopIndex = loopIndex + 1;
    if ((char)param_11 != '\0') {
      local_7c[1] = (local_7c[1] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[1] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[1] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[1] ^ 8) & 8 | local_7c[1] & 0xffff7777;
    }
LAB_000ad33c:
    local_7c[6] = param_16;
    local_7c[5] = param_15;
    local_7c[4] = param_14;
    local_7c[3] = param_13;
    local_88 = (param_7[1] & 0x3f) << 0x10 | *param_7 & 0xffff | 0x400000;
    if (param_7[1] == 0x10) {
      loopIndex6 = 0;
      remaining4 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + loopIndex6 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        remaining4 = remaining4 + -1;
        *(undefined4 *)((int)local_7c + loopIndex6 + 0xc) = uVar5;
        loopIndex6 = loopIndex6 + 4;
      } while (remaining4 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      local_7c[0] = 0;
      break;
    case 1:
      bVar1 = false;
      local_7c[0] = 1;
      break;
    case 2:
      bVar1 = false;
      local_7c[0] = 2;
      break;
    case 3:
      bVar1 = false;
      local_7c[0] = 3;
      break;
    case 4:
      bVar1 = false;
      local_7c[0] = 4;
      break;
    case 5:
      bVar1 = false;
      local_7c[0] = 5;
      break;
    case 6:
      bVar1 = true;
      local_7c[0] = 0;
      break;
    case 7:
      bVar1 = true;
      local_7c[0] = 1;
      break;
    case 8:
      bVar1 = true;
      local_7c[0] = 2;
      break;
    case 9:
      bVar1 = true;
      local_7c[0] = 3;
      break;
    case 10:
      bVar1 = true;
      local_7c[0] = 5;
    }
    if (bVar1) {
      local_7c[0] = local_7c[0] | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[0] = iVar15 << 4 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[0] = iVar15 << 8 | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar15 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar15 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar15 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar15 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar15 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar15 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar15 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar15 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar15 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar15 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar15 = 5;
    }
    local_7c[0] = iVar15 << 0xc | local_7c[0];
    if (bVar1) {
      local_7c[0] = local_7c[0] | 0x8000;
    }
    if ((char)param_10 != '\0') {
      local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                    (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                    (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                    (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
    }
    break;
  default:
    loopIndex = 0;
    break;
  case 0xd:
  case 0x2d:
    uVar6 = *param_7;
    uVar9 = param_7[1];
    local_7c[6] = param_16;
    local_7c[5] = param_15;
    local_7c[4] = param_14;
    local_7c[3] = param_13;
    uVar8 = *(int *)(a1Ptr74 + 0x88) + 2;
    uVar11 = uVar8 & 0xffff;
    if (uVar9 == 0x10) {
      loopIndex3 = 0;
      remaining2 = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + loopIndex3 + 0xc)) {
        default:
          uVar5 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar5 = 4;
          break;
        case 3:
        case 5:
          uVar5 = 5;
          break;
        case 6:
          uVar5 = 6;
          break;
        case 9:
        case 10:
          uVar5 = 10;
        }
        remaining2 = remaining2 + -1;
        *(undefined4 *)((int)local_7c + loopIndex3 + 0xc) = uVar5;
        loopIndex3 = loopIndex3 + 4;
      } while (remaining2 != 0);
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      uVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar7 = 5;
    }
    if (bVar1) {
      uVar7 = uVar7 | 8;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    uVar7 = iVar14 << 4 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x80;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    uVar7 = iVar14 << 8 | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x800;
    }
    switch(local_7c[6]) {
    default:
      bVar1 = false;
      iVar14 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar14 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar14 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar14 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar14 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar14 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar14 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar14 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar14 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar14 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar14 = 5;
    }
    uVar7 = iVar14 << 0xc | uVar7;
    if (bVar1) {
      uVar7 = uVar7 | 0x8000;
    }
    if ((char)param_10 != '\0') {
      uVar7 = (uVar7 & 0xfffff777 ^ 0x8000) & 0x8000 |
              (uVar7 & 0xffffff77 ^ 0x800) & 0x800 |
              (uVar7 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar7 ^ 8) & 8 | uVar7 & 0xffff7777;
    }
    wordVectorWord0 = *wordVector;
    if (wordVector[1] <= wordVectorWord0) {
      allocation = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation;
      wordVectorWord0 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(undefined4 *)(wordVectorWord0 * 4 + wordVector[2]) = 0x47;
    uVar10 = *wordVector + 1;
    *wordVector = uVar10;
    if (wordVector[1] <= uVar10) {
      allocation2 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation2,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation2;
      uVar10 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar10 * 4 + wordVector[2]) = uVar11 | 0x40000;
    uVar10 = *wordVector + 1;
    *wordVector = uVar10;
    if (wordVector[1] <= uVar10) {
      allocation3 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation3,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation3;
      uVar10 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar10 * 4 + wordVector[2]) = (uVar9 & 0x3f) << 0x10 | uVar6 & 0xffff | 0x400000;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation14 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation14,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation14;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + wordVector[2]) = uVar7;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation15 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation15,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation15;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + wordVector[2]) = 0x2000d;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation16 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation16,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation16;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + wordVector[2]) = uVar11 | 0x440000;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation17 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation17,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation17;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(undefined4 *)(uVar6 * 4 + wordVector[2]) = 4;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation18 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation18,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation18;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + wordVector[2]) = uVar11 | 0x40000;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation19 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation19,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation19;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + wordVector[2]) = uVar11 | 0x40000;
    uVar6 = *wordVector + 1;
    *wordVector = uVar6;
    if (wordVector[1] <= uVar6) {
      allocation20 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation20,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation20;
      uVar6 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar6 * 4 + wordVector[2]) = uVar11 | 0x440000;
    uVar11 = *wordVector + 1;
    *wordVector = uVar11;
    if (wordVector[1] <= uVar11) {
      allocation4 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation4,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation4;
      uVar11 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    loopIndex = 1;
    *(undefined **)(uVar11 * 4 + wordVector[2]) = ((unsigned char *)0x00004444);
    local_88 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88) + 0)),(short)uVar8);
    *wordVector = *wordVector + 1;
    local_88 = local_88 & 0xff80ffff | 0x40000;
  }
  switch(formatCode) {
  case 0:
  case 0x21:
    uVar13 = 1;
    break;
  case 1:
  case 0x22:
    uVar13 = 3;
    break;
  case 2:
  case 0x23:
    uVar13 = 0x5000d;
    break;
  case 3:
  case 0x24:
    uVar13 = 0x12;
    goto LAB_000ae47c;
  case 4:
  case 0x25:
    uVar13 = 0x22;
    break;
  case 5:
  case 0x26:
    uVar13 = 0x23;
    break;
  case 6:
  case 0x27:
    uVar13 = 0x23;
    local_7c[0] = local_7c[0] & 0xffff0fff | 0x5000;
    break;
  case 7:
  case 0x28:
    uVar13 = 0x24;
    break;
  case 8:
  case 0x29:
    uVar13 = 0x2d;
    break;
  case 9:
  case 0x2a:
    uVar13 = 0x30;
    break;
  case 10:
  case 0x2b:
    uVar13 = 0x31;
    break;
  case 0xc:
  case 0x2c:
    uVar13 = 0x3c;
    break;
  case 0xd:
  case 0x2d:
    uVar13 = 0x39;
    break;
  case 0xe:
  case 0x2e:
    uVar13 = 0x3f;
    break;
  case 0xf:
  case 0x2f:
    uVar13 = 0x40;
    break;
  case 0x10:
  case 0x30:
    uVar13 = 0x41;
    break;
  case 0x11:
  case 0x31:
    uVar13 = 0x44;
    break;
  case 0x12:
  case 0x1c:
  case 0x32:
  case 0x3c:
    uVar13 = 0x47;
    break;
  case 0x13:
  case 0x33:
    uVar13 = 0x49;
    break;
  case 0x14:
  case 0x34:
    uVar13 = 0x4e;
    break;
  case 0x15:
  case 0x35:
    uVar13 = 0x51;
    break;
  case 0x16:
  case 0x36:
    uVar13 = 0x55;
    local_7c[0] = local_7c[0] & 0xffff7777 | 0x100000;
    break;
  case 0x17:
  case 0x37:
    uVar13 = 0x59;
    break;
  case 0x18:
  case 0x38:
    uVar13 = 0x20056;
    break;
  case 0x19:
  case 0x39:
    uVar13 = 0x58;
LAB_000ae47c:
    wordVectorWord0_2 = *wordVector;
    if (wordVector[1] <= wordVectorWord0_2) {
      allocation5 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation5,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation5;
      wordVectorWord0_2 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(undefined4 *)(wordVectorWord0_2 * 4 + wordVector[2]) = 0x4d;
    uVar11 = *wordVector + 1;
    *wordVector = uVar11;
    glContextWord11e0 = *(int *)(((unsigned char *)0x000011e0) + glContext);
    if (wordVector[1] <= uVar11) {
      allocation6 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation6,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation6;
      uVar11 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    uVar6 = local_88;
    *(uint *)(uVar11 * 4 + wordVector[2]) = glContextWord11e0 + 1U & 0xffff | 0x40000;
    uVar11 = *wordVector + 1;
    *wordVector = uVar11;
    if (wordVector[1] <= uVar11) {
      allocation7 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation7,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation7;
      uVar11 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    uVar8 = local_7c[0];
    *(uint *)(uVar11 * 4 + wordVector[2]) = uVar6;
    uVar11 = *wordVector + 1;
    *wordVector = uVar11;
    if ((local_88 & 0x400000) != 0) {
      if (wordVector[1] <= uVar11) {
        allocation8 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
        if (wordVector[2] != 0) {
          _memcpy(allocation8,wordVector[2],*wordVector << 2);
          (**(code **)(glContext + 0x18))(wordVector[2]);
        }
        wordVector[2] = allocation8;
        uVar11 = *wordVector;
        wordVector[1] = wordVector[1] + 0x80;
      }
      *(uint *)(uVar11 * 4 + wordVector[2]) = uVar8;
      *wordVector = *wordVector + 1;
    }
    local_88 = CONCAT22((short)(local_88 >> 0x10),
                        (short)*(undefined4 *)(((unsigned char *)0x000011e0) + glContext) + 1) & 0xffc0ffff | 0x40000;
    break;
  case 0x1a:
  case 0x3a:
    uVar13 = 0x50056;
    break;
  case 0x1b:
  case 0x3b:
    uVar13 = 0x5b;
    break;
  case 0x20:
  case 0x40:
    uVar13 = 0x13;
  }
  if (formatDesc[1] == 0x18) {
    if (loopIndex != 0) {
      loopIndex7 = 0;
      iVar15 = loopIndex;
      do {
        if (((&local_88)[loopIndex7] & 0x400000) != 0) {
          uVar19 = local_7c[loopIndex7];
          local_7c[loopIndex7] = uVar19 >> 8 & 7 | uVar19 >> 8 & 8 | uVar19 & 0xfffffff0;
        }
        loopIndex7 = loopIndex7 + 1;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
    }
    uVar19 = uVar12 | uVar4 | uVar3 | uVar2 | uVar18;
    bVar1 = false;
  }
  else if (formatDesc[1] == 0x17) {
    bVar1 = true;
    uVar16 = *(uint *)(local_58 + 0x88) & 0xffff | 0x440000;
  }
  else {
    bVar1 = false;
  }
  wordVectorWord0_3 = *wordVector;
  if (wordVector[1] <= wordVectorWord0_3) {
    allocation9 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation9,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation9;
    wordVectorWord0_3 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(undefined4 *)(wordVectorWord0_3 * 4 + wordVector[2]) = uVar13;
  uVar18 = *wordVector + 1;
  *wordVector = uVar18;
  if (wordVector[1] <= uVar18) {
    allocation10 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation10,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation10;
    uVar18 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(uint *)(uVar18 * 4 + wordVector[2]) = uVar16;
  uVar18 = *wordVector + 1;
  *wordVector = uVar18;
  if ((uVar16 & 0x400000) != 0) {
    if (wordVector[1] <= uVar18) {
      allocation11 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation11,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation11;
      uVar18 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar18 * 4 + wordVector[2]) = uVar19;
    uVar18 = *wordVector + 1;
    *wordVector = uVar18;
  }
  if (loopIndex != 0) {
    loopIndex4 = 0;
    loopIndex8 = 0;
    cursor = &local_88;
    do {
      uVar13 = *(undefined4 *)(loopIndex8 + (int)&local_88);
      if (wordVector[1] <= uVar18) {
        allocation12 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
        if (wordVector[2] != 0) {
          _memcpy(allocation12,wordVector[2],*wordVector << 2);
          (**(code **)(glContext + 0x18))(wordVector[2]);
        }
        wordVector[2] = allocation12;
        uVar18 = *wordVector;
        wordVector[1] = wordVector[1] + 0x80;
      }
      *(undefined4 *)(uVar18 * 4 + wordVector[2]) = uVar13;
      uVar18 = *wordVector + 1;
      *wordVector = uVar18;
      if ((*cursor & 0x400000) != 0) {
        uVar13 = *(undefined4 *)((int)local_7c + loopIndex8);
        if (wordVector[1] <= uVar18) {
          allocation13 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
          if (wordVector[2] != 0) {
            _memcpy(allocation13,wordVector[2],*wordVector << 2);
            (**(code **)(glContext + 0x18))(wordVector[2]);
          }
          wordVector[2] = allocation13;
          uVar18 = *wordVector;
          wordVector[1] = wordVector[1] + 0x80;
        }
        *(undefined4 *)(uVar18 * 4 + wordVector[2]) = uVar13;
        uVar18 = *wordVector + 1;
        *wordVector = uVar18;
      }
      loopIndex4 = loopIndex4 + 1;
      cursor = cursor + 1;
      loopIndex8 = loopIndex8 + 4;
    } while (loopIndex != loopIndex4);
  }
  if (bVar1) {
    ((int (*)())FUN_000ac540)(glContext,wordVector,*(undefined4 *)(local_58 + 0x88),local_54);
    return;
  }
  return;
}

/* FUN_000aec40 @ 0xaec40 (3872 bytes) */
int FUN_000aec40(glContext, a1Ptr74, wordVector, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14)
  int glContext;
  int a1Ptr74;
  uint *wordVector;
  int param_4;
  uint *param_5;
  uint param_6;
  uint *param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
  uint param_13;
  int param_14;
{
  uint wordVectorWord0;
  uint allocation9;
  uint allocation8;
  uint allocation7;
  uint allocation6;
  uint allocation5;
  uint allocation4;
  uint allocation3;
  uint allocation2;
  uint allocation;
  int remaining2;
  int remaining;
  int loopIndex3;
  int loopIndex2;
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int loopIndex;
  uint uVar11;
  uint uVar12;
  int loopIndex4;
  uint *cursor;
  undefined4 uStack00000034;
  uint local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c [14];
  
  uVar12 = 0;
  uVar9 = param_5[1];
  local_88 = 0;
  local_84 = 0;
  local_7c[0] = 0;
  local_80 = 0;
  local_7c[1] = 0;
  if (uVar9 != 0x17) {
    uVar11 = (uVar9 & 0x3f) << 0x10 | *param_5 & 0xffff;
  }
  else {
    uVar11 = *(uint *)(a1Ptr74 + 0x88) & 0xffff | 0x40000;
  }
  if (param_4 - 0x3dU < 3) {
    uVar12 = 0x100;
  }
  if (uVar9 == 0x18) {
    uVar12 = 0x100;
  }
  uStack00000034 = param_8;
  if ((param_4 == 0x1f) && ((char)param_12 != '\0')) {
    uVar2 = *param_7;
    uVar6 = param_7[1];
    local_7c[5] = param_11;
    local_7c[4] = param_10;
    local_7c[3] = param_9;
    local_7c[2] = param_8;
    uVar5 = *(int *)(a1Ptr74 + 0x88) + 1;
    if (uVar6 == 0x10) {
      loopIndex = 0;
      remaining = 4;
      do {
        switch(*(undefined4 *)((int)local_7c + loopIndex + 8)) {
        default:
          uVar3 = 0;
          break;
        case 1:
        case 2:
        case 4:
        case 7:
        case 8:
          uVar3 = 4;
          break;
        case 3:
        case 5:
          uVar3 = 5;
          break;
        case 6:
          uVar3 = 6;
          break;
        case 9:
        case 10:
          uVar3 = 10;
        }
        remaining = remaining + -1;
        *(undefined4 *)((int)local_7c + loopIndex + 8) = uVar3;
        loopIndex = loopIndex + 4;
      } while (remaining != 0);
    }
    switch(local_7c[2]) {
    default:
      bVar1 = false;
      uVar4 = 0;
      break;
    case 1:
      bVar1 = false;
      uVar4 = 1;
      break;
    case 2:
      bVar1 = false;
      uVar4 = 2;
      break;
    case 3:
      bVar1 = false;
      uVar4 = 3;
      break;
    case 4:
      bVar1 = false;
      uVar4 = 4;
      break;
    case 5:
      bVar1 = false;
      uVar4 = 5;
      break;
    case 6:
      bVar1 = true;
      uVar4 = 0;
      break;
    case 7:
      bVar1 = true;
      uVar4 = 1;
      break;
    case 8:
      bVar1 = true;
      uVar4 = 2;
      break;
    case 9:
      bVar1 = true;
      uVar4 = 3;
      break;
    case 10:
      bVar1 = true;
      uVar4 = 5;
    }
    if (bVar1) {
      uVar4 = uVar4 | 8;
    }
    switch(local_7c[3]) {
    default:
      bVar1 = false;
      iVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar7 = 5;
    }
    uVar4 = iVar7 << 4 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x80;
    }
    switch(local_7c[4]) {
    default:
      bVar1 = false;
      iVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar7 = 5;
    }
    uVar4 = iVar7 << 8 | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x800;
    }
    switch(local_7c[5]) {
    default:
      bVar1 = false;
      iVar7 = 0;
      break;
    case 1:
      bVar1 = false;
      iVar7 = 1;
      break;
    case 2:
      bVar1 = false;
      iVar7 = 2;
      break;
    case 3:
      bVar1 = false;
      iVar7 = 3;
      break;
    case 4:
      bVar1 = false;
      iVar7 = 4;
      break;
    case 5:
      bVar1 = false;
      iVar7 = 5;
      break;
    case 6:
      bVar1 = true;
      iVar7 = 0;
      break;
    case 7:
      bVar1 = true;
      iVar7 = 1;
      break;
    case 8:
      bVar1 = true;
      iVar7 = 2;
      break;
    case 9:
      bVar1 = true;
      iVar7 = 3;
      break;
    case 10:
      bVar1 = true;
      iVar7 = 5;
    }
    uVar4 = iVar7 << 0xc | uVar4;
    if (bVar1) {
      uVar4 = uVar4 | 0x8000;
    }
    wordVectorWord0 = *wordVector;
    if (wordVector[1] <= wordVectorWord0) {
      allocation7 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation7,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation7;
      wordVectorWord0 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(undefined4 *)(wordVectorWord0 * 4 + wordVector[2]) = 0x47;
    uVar8 = *wordVector + 1;
    *wordVector = uVar8;
    if (wordVector[1] <= uVar8) {
      allocation8 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation8,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation8;
      uVar8 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar8 * 4 + wordVector[2]) = uVar5 & 0xffff | 0x40000;
    uVar8 = *wordVector + 1;
    *wordVector = uVar8;
    if (wordVector[1] <= uVar8) {
      allocation9 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation9,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation9;
      uVar8 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar8 * 4 + wordVector[2]) = (uVar6 & 0x3f) << 0x10 | uVar2 & 0xffff | 0x400000;
    uVar2 = *wordVector + 1;
    *wordVector = uVar2;
    if (wordVector[1] <= uVar2) {
      allocation4 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation4,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation4;
      uVar2 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + wordVector[2]) =
         (uVar4 & 0xfffff777 ^ 0x8000) & 0x8000 |
         (uVar4 & 0xffffff77 ^ 0x800) & 0x800 |
         (uVar4 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar4 ^ 8) & 8 | uVar4 & 0xffff7777;
    local_84 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_84) + 0)),(short)uVar5);
    local_7c[0] = local_7c[0] & 0xffff8888 | 0x3210;
    uVar2 = *wordVector + 1;
    *wordVector = uVar2;
    local_84 = local_84 & 0xffc0ffff | 0x40000;
LAB_000af474:
    iVar7 = 1;
    local_88 = 0x5d;
    local_84 = local_84 | 0x400000;
    local_7c[0] = local_7c[0] & 0xff1fffff | 0x600000;
    goto LAB_000afabc;
  }
  local_7c[5] = param_11;
  local_7c[4] = param_10;
  local_7c[3] = param_9;
  local_7c[2] = param_8;
  local_84 = *param_7 & 0xffff;
  local_84 = (param_7[1] & 0x3f) << 0x10 | local_84 | 0x400000;
  if (param_7[1] == 0x10) {
    loopIndex2 = 0;
    remaining2 = 4;
    do {
      switch(*(undefined4 *)((int)local_7c + loopIndex2 + 8)) {
      default:
        uVar3 = 0;
        break;
      case 1:
      case 2:
      case 4:
      case 7:
      case 8:
        uVar3 = 4;
        break;
      case 3:
      case 5:
        uVar3 = 5;
        break;
      case 6:
        uVar3 = 6;
        break;
      case 9:
      case 10:
        uVar3 = 10;
      }
      remaining2 = remaining2 + -1;
      *(undefined4 *)((int)local_7c + loopIndex2 + 8) = uVar3;
      loopIndex2 = loopIndex2 + 4;
    } while (remaining2 != 0);
  }
  switch(local_7c[2]) {
  default:
    bVar1 = false;
    local_7c[0] = 0;
    break;
  case 1:
    bVar1 = false;
    local_7c[0] = 1;
    break;
  case 2:
    bVar1 = false;
    local_7c[0] = 2;
    break;
  case 3:
    bVar1 = false;
    local_7c[0] = 3;
    break;
  case 4:
    bVar1 = false;
    local_7c[0] = 4;
    break;
  case 5:
    bVar1 = false;
    local_7c[0] = 5;
    break;
  case 6:
    bVar1 = true;
    local_7c[0] = 0;
    break;
  case 7:
    bVar1 = true;
    local_7c[0] = 1;
    break;
  case 8:
    bVar1 = true;
    local_7c[0] = 2;
    break;
  case 9:
    bVar1 = true;
    local_7c[0] = 3;
    break;
  case 10:
    bVar1 = true;
    local_7c[0] = 5;
  }
  if (bVar1) {
    local_7c[0] = local_7c[0] | 8;
  }
  switch(local_7c[3]) {
  default:
    bVar1 = false;
    iVar7 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar7 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar7 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar7 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar7 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar7 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar7 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar7 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar7 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar7 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar7 = 5;
  }
  local_7c[0] = iVar7 << 4 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x80;
  }
  switch(local_7c[4]) {
  default:
    bVar1 = false;
    iVar7 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar7 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar7 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar7 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar7 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar7 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar7 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar7 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar7 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar7 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar7 = 5;
  }
  local_7c[0] = iVar7 << 8 | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x800;
  }
  switch(local_7c[5]) {
  default:
    bVar1 = false;
    iVar7 = 0;
    break;
  case 1:
    bVar1 = false;
    iVar7 = 1;
    break;
  case 2:
    bVar1 = false;
    iVar7 = 2;
    break;
  case 3:
    bVar1 = false;
    iVar7 = 3;
    break;
  case 4:
    bVar1 = false;
    iVar7 = 4;
    break;
  case 5:
    bVar1 = false;
    iVar7 = 5;
    break;
  case 6:
    bVar1 = true;
    iVar7 = 0;
    break;
  case 7:
    bVar1 = true;
    iVar7 = 1;
    break;
  case 8:
    bVar1 = true;
    iVar7 = 2;
    break;
  case 9:
    bVar1 = true;
    iVar7 = 3;
    break;
  case 10:
    bVar1 = true;
    iVar7 = 5;
  }
  local_7c[0] = iVar7 << 0xc | local_7c[0];
  if (bVar1) {
    local_7c[0] = local_7c[0] | 0x8000;
  }
  if ((char)param_12 != '\0') {
    local_7c[0] = (local_7c[0] & 0xfffff777 ^ 0x8000) & 0x8000 |
                  (local_7c[0] & 0xffffff77 ^ 0x800) & 0x800 |
                  (local_7c[0] & 0xfffffff7 ^ 0x80) & 0x80 |
                  (local_7c[0] ^ 8) & 8 | local_7c[0] & 0xffff7777;
  }
  switch(param_4) {
  case 0xb:
    uVar2 = *wordVector;
    iVar7 = 1;
    local_88 = 0x37;
    goto LAB_000afb10;
  default:
    uVar2 = *wordVector;
    iVar7 = 0;
    goto LAB_000afb10;
  case 0x1d:
  case 0x3d:
    uVar2 = *wordVector;
    iVar7 = 1;
    local_88 = 0x5d;
    break;
  case 0x1e:
  case 0x3e:
    iVar7 = 2;
    local_88 = 0x5e;
    uVar2 = *wordVector;
    local_80 = local_84;
    local_7c[1] = local_7c[0];
    break;
  case 0x1f:
  case 0x3f:
    uVar2 = *wordVector;
    goto LAB_000af474;
  }
LAB_000afabc:
  local_88 = (uint)(param_14 - 6U < 3) << 0x1a | (param_13 & 0x33ff) << 0x10 | local_88;
LAB_000afb10:
  if (wordVector[1] <= uVar2) {
    allocation5 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
    if (wordVector[2] != 0) {
      _memcpy(allocation5,wordVector[2],*wordVector << 2);
      (**(code **)(glContext + 0x18))(wordVector[2]);
    }
    wordVector[2] = allocation5;
    uVar2 = *wordVector;
    wordVector[1] = wordVector[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + wordVector[2]) = local_88;
  uVar2 = *wordVector + 1;
  *wordVector = uVar2;
  if (param_4 != 0xb) {
    if (wordVector[1] <= uVar2) {
      allocation6 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation6,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation6;
      uVar2 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar2 * 4 + wordVector[2]) = uVar11 | 0x400000;
    uVar11 = *wordVector + 1;
    *wordVector = uVar11;
    if (wordVector[1] <= uVar11) {
      allocation = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
      if (wordVector[2] != 0) {
        _memcpy(allocation,wordVector[2],*wordVector << 2);
        (**(code **)(glContext + 0x18))(wordVector[2]);
      }
      wordVector[2] = allocation;
      uVar11 = *wordVector;
      wordVector[1] = wordVector[1] + 0x80;
    }
    *(uint *)(uVar11 * 4 + wordVector[2]) =
         (param_6 >> 3 & 1) << 6 |
         (param_6 >> 2 & 1) << 4 | (param_6 >> 1 & 1) << 2 | param_6 & 1 | uVar12;
    uVar2 = *wordVector + 1;
    *wordVector = uVar2;
  }
  if (iVar7 != 0) {
    cursor = &local_84;
    loopIndex3 = 0;
    loopIndex4 = 0;
    do {
      uVar3 = *(undefined4 *)((int)&local_84 + loopIndex4);
      if (wordVector[1] <= uVar2) {
        allocation2 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
        if (wordVector[2] != 0) {
          _memcpy(allocation2,wordVector[2],*wordVector << 2);
          (**(code **)(glContext + 0x18))(wordVector[2]);
        }
        wordVector[2] = allocation2;
        uVar2 = *wordVector;
        wordVector[1] = wordVector[1] + 0x80;
      }
      *(undefined4 *)(uVar2 * 4 + wordVector[2]) = uVar3;
      uVar2 = *wordVector + 1;
      *wordVector = uVar2;
      if ((*cursor & 0x400000) != 0) {
        uVar3 = *(undefined4 *)((int)local_7c + loopIndex4);
        if (wordVector[1] <= uVar2) {
          allocation3 = (**(code **)(glContext + 0xc))(wordVector[1] * 4 + 0x200);
          if (wordVector[2] != 0) {
            _memcpy(allocation3,wordVector[2],*wordVector << 2);
            (**(code **)(glContext + 0x18))(wordVector[2]);
          }
          wordVector[2] = allocation3;
          uVar2 = *wordVector;
          wordVector[1] = wordVector[1] + 0x80;
        }
        *(undefined4 *)(uVar2 * 4 + wordVector[2]) = uVar3;
        uVar2 = *wordVector + 1;
        *wordVector = uVar2;
      }
      loopIndex3 = loopIndex3 + 1;
      cursor = cursor + 1;
      loopIndex4 = loopIndex4 + 4;
    } while (iVar7 != loopIndex3);
  }
  if (uVar9 == 0x17) {
    ((int (*)())FUN_000ac540)(glContext,wordVector,*(undefined4 *)(a1Ptr74 + 0x88),*param_5);
  }
  return;
}

/* FUN_000afe40 @ 0xafe40 (5932 bytes) */
undefined4 FUN_000afe40(int glContext,int param_2,undefined4 unusedArgR5,uint *unused,double fpPassThrough1)
{
  undefined4 allocation26;
  undefined4 allocation25;
  int allocation24;
  int allocation23;
  int allocation22;
  int allocation21;
  int allocation20;
  int allocation19;
  int allocation18;
  int allocation17;
  int allocation16;
  int allocation15;
  int allocation14;
  int allocation13;
  int allocation12;
  int allocation11;
  int allocation10;
  int allocation9;
  int allocation8;
  int allocation7;
  int allocation6;
  int allocation5;
  int allocation4;
  int allocation3;
  int allocation2;
  int allocation;
  uint loopIndex6;
  int loopIndex5;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  int a1Ptr74;
  int glContextWord1130_2;
  int a1Word70;
  int glContextWord1130;
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined1 *staleArgR7;
  undefined4 staleArgR8;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char *a2;
  int a1;
  uint uVar8;
  char *cursor;
  undefined4 uVar10;
  int iVar11;
  code *glContextPtr10;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  char *a1Ptr74_2;
  int loopIndex4;
  double f1AfterCall;
  double f1AfterCall2;
  char local_208 [4];
  undefined1 auStack_204 [8];
  undefined1 auStack_1fc [8];
  undefined1 auStack_1f4 [8];
  uint wordCount;
  uint wordCapacity;
  int wordData;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  uint auStack_170 [66];
  int local_68;
  undefined1 *local_64;
  uint *local_60;
  uint *local_5c;
  
  a1 = *(int *)(((unsigned char *)0x0000121c) + glContext);
  a1Ptr74_2 = *(char **)(a1 + 0x74);
  if (a1Ptr74_2[0x54] == '\0') {
    a1 = *(int *)(*(int *)(((unsigned char *)0x00001220) + glContext) * 0x18 +
                  *(int *)(*(int *)(((unsigned char *)0x0000112c) + glContext) + 8) + 0x14);
    a1Ptr74_2 = *(char **)(a1 + 0x74);
  }
  uVar8 = *(uint *)(a1 + 0x70);
  iVar11 = *(int *)(((unsigned char *)0x00001130) + glContext) * 4;
  a2 = *(char **)(iVar11 + uVar8);
  if (a2 == (char *)0x0) {
    glContextPtr10 = *(code **)(glContext + 0x10);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + glContext))(glContext);
    uVar4 = (*glContextPtr10)(1,uVar4);
    *(undefined4 *)(iVar11 + uVar8) = uVar4;
  }
  else {
    if ((param_2 != 1) && (a2[0x119] == '\0')) goto LAB_000b0028;
    *(undefined4 *)(iVar11 + uVar8) = 0;
    (**(code **)(((unsigned char *)0x00001224) + glContext))(glContext,a2);
    glContextPtr10 = *(code **)(glContext + 0x10);
    glContextWord1130 = *(int *)(((unsigned char *)0x00001130) + glContext);
    uVar8 = *(uint *)(a1 + 0x70);
    uVar4 = (**(code **)(((unsigned char *)0x00001284) + glContext))(glContext);
    uVar4 = (*glContextPtr10)(1,uVar4);
    *(undefined4 *)(glContextWord1130 * 4 + uVar8) = uVar4;
  }
  a2 = *(char **)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + *(int *)(a1 + 0x70));
  *a2 = '\0';
  if (a1Ptr74_2[0x55] == '\0') {
    wordData = 0;
    wordCount = 0;
    wordCapacity = 0;
    allocation = (**(code **)(glContext + 0xc))(0x200);
    if (wordData != 0) {
      _memcpy(allocation,wordData,wordCount << 2);
      (**(code **)(glContext + 0x18))(wordData);
    }
    wordCapacity = wordCapacity + 0x80;
    *(undefined4 *)(allocation + wordCount * 4) = 1;
    wordCount = wordCount + 1;
    wordData = allocation;
    if (wordCapacity <= wordCount) {
      allocation2 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
      if (wordData != 0) {
        _memcpy(allocation2,wordData,wordCount << 2);
        (**(code **)(glContext + 0x18))(wordData);
      }
      wordCapacity = wordCapacity + 0x80;
      wordData = allocation2;
    }
    *(undefined4 *)(wordCount * 4 + wordData) = 0x10200;
    wordCount = wordCount + 1;
    if (wordCapacity <= wordCount) {
      allocation3 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
      if (wordData != 0) {
        _memcpy(allocation3,wordData,wordCount << 2);
        (**(code **)(glContext + 0x18))(wordData);
      }
      wordCapacity = wordCapacity + 0x80;
      wordData = allocation3;
    }
    *(undefined4 *)(wordCount * 4 + wordData) = 0x1ff0016;
    wordCount = wordCount + 1;
    if (wordCapacity <= wordCount) {
      allocation4 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
      if (wordData != 0) {
        _memcpy(allocation4,wordData,wordCount << 2);
        (**(code **)(glContext + 0x18))(wordData);
      }
      wordCapacity = wordCapacity + 0x80;
      wordData = allocation4;
    }
    *(undefined4 *)(wordCount * 4 + wordData) = 0x120000;
    wordCount = wordCount + 1;
    if (*a1Ptr74_2 != '\0') {
      if (wordCapacity <= wordCount) {
        allocation5 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation5,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation5;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x1ff0016;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation6 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation6,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation6;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x130000;
      wordCount = wordCount + 1;
    }
    if (a1Ptr74_2[1] != '\0') {
      if (wordCapacity <= wordCount) {
        allocation7 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation7,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation7;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x1ff0016;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation8 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation8,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation8;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x100000;
      wordCount = wordCount + 1;
    }
    if (a1Ptr74_2[2] != '\0') {
      uVar8 = 0x3ff0016;
      if (wordCapacity <= wordCount) {
        allocation9 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation9,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation9;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x3ff0016;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation10 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation10,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation10;
      }
      *(undefined **)(wordCount * 4 + wordData) = ((unsigned char *)0x00160000);
      wordCount = wordCount + 1;
    }
    uVar5 = wordCount;
    if (((unsigned char *)0x000013b1)[glContext] != '\0') {
      loopIndex6 = 0;
      cursor = a1Ptr74_2;
      do {
        uVar13 = 1 << (loopIndex6 & 0x3f);
        if ((uVar13 & *(uint *)(a1Ptr74_2 + 0x10)) != 0) {
          switch(*(undefined4 *)(cursor + 0x14)) {
          case 0:
            uVar8 = loopIndex6 << 0x10 | 0x8000019;
            break;
          case 1:
          case 6:
            uVar8 = loopIndex6 << 0x10 | 0x9000019;
            break;
          case 2:
          case 7:
            uVar8 = loopIndex6 << 0x10 | 0xa000019;
            break;
          case 3:
            uVar8 = loopIndex6 << 0x10 | 0xb000019;
            break;
          case 4:
            uVar8 = loopIndex6 << 0x10 | 0xc000019;
            break;
          case 5:
          case 8:
            uVar8 = loopIndex6 << 0x10 | 0x12000019;
          }
          if (wordCapacity <= uVar5) {
            allocation11 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation11,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            uVar5 = wordCount;
            wordData = allocation11;
          }
          *(uint *)(uVar5 * 4 + wordData) = uVar8;
          uVar5 = wordCount + 1;
          wordCount = uVar5;
        }
        if (((int)loopIndex6 < (int)(uint)(byte)((unsigned char *)0x000013b0)[glContext]) &&
           ((uVar13 & *(uint *)(a1Ptr74_2 + 0xc)) != 0)) {
          if (wordCapacity <= uVar5) {
            allocation12 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation12,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            uVar5 = wordCount;
            wordData = allocation12;
          }
          *(undefined4 *)(uVar5 * 4 + wordData) = 0x1ff0016;
          wordCount = wordCount + 1;
          if (wordCapacity <= wordCount) {
            allocation13 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation13,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation13;
          }
          *(uint *)(wordCount * 4 + wordData) = loopIndex6 & 0xffff | 0x110000;
          uVar5 = wordCount + 1;
          wordCount = uVar5;
        }
        loopIndex6 = loopIndex6 + 1;
        cursor = cursor + 4;
      } while ((int)loopIndex6 < (int)(uint)(byte)((unsigned char *)0x000013b1)[glContext]);
    }
    iVar11 = *(int *)(a1Ptr74_2 + 0x84);
    uVar8 = 0x10000;
    if (0 < iVar11) {
      loopIndex3 = 0;
      loopIndex4 = 0;
      do {
        iVar17 = loopIndex4 + *(int *)(a1Ptr74_2 + 0x80);
        if (*(int *)(iVar17 + 8) == 0x34) {
          uVar8 = *(uint *)(iVar17 + 4) & 0xffff | uVar8 & 0xffff0000;
          if (wordCapacity <= uVar5) {
            allocation14 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation14,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            uVar5 = wordCount;
            wordData = allocation14;
          }
          *(undefined4 *)(uVar5 * 4 + wordData) = 0x1c;
          wordCount = wordCount + 1;
          if (wordCapacity <= wordCount) {
            allocation15 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation15,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation15;
          }
          *(uint *)(wordCount * 4 + wordData) = uVar8;
          wordCount = wordCount + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar17 + 0xc) * 0x10 + *(int *)(a1Ptr74_2 + 0x8c));
          if (wordCapacity <= wordCount) {
            allocation16 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation16,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation16;
          }
          *(undefined4 *)(wordCount * 4 + wordData) = uVar4;
          wordCount = wordCount + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar17 + 0xc) * 0x10 + *(int *)(a1Ptr74_2 + 0x8c) + 4);
          if (wordCapacity <= wordCount) {
            allocation17 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation17,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation17;
          }
          *(undefined4 *)(wordCount * 4 + wordData) = uVar4;
          wordCount = wordCount + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar17 + 0xc) * 0x10 + *(int *)(a1Ptr74_2 + 0x8c) + 8);
          if (wordCapacity <= wordCount) {
            allocation18 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation18,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation18;
          }
          *(undefined4 *)(wordCount * 4 + wordData) = uVar4;
          wordCount = wordCount + 1;
          uVar4 = *(undefined4 *)(*(int *)(iVar17 + 0xc) * 0x10 + *(int *)(a1Ptr74_2 + 0x8c) + 0xc);
          if (wordCapacity <= wordCount) {
            allocation19 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
            if (wordData != 0) {
              _memcpy(allocation19,wordData,wordCount << 2);
              (**(code **)(glContext + 0x18))(wordData);
            }
            wordCapacity = wordCapacity + 0x80;
            wordData = allocation19;
          }
          *(undefined4 *)(wordCount * 4 + wordData) = uVar4;
          uVar5 = wordCount + 1;
          iVar11 = *(int *)(a1Ptr74_2 + 0x84);
          wordCount = uVar5;
        }
        loopIndex3 = loopIndex3 + 1;
        loopIndex4 = loopIndex4 + 0x14;
      } while (loopIndex3 < iVar11);
    }
    if (**(int **)(a1Ptr74_2 + 100) == 0x41) {
      local_5c = &wordCount;
LAB_000b10a0:
      if (wordCapacity <= uVar5) {
        allocation20 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation20,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        uVar5 = wordCount;
        wordData = allocation20;
      }
      *(undefined4 *)(uVar5 * 4 + wordData) = 0x47;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation21 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation21,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation21;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x570000;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation22 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation22,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation22;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0;
      wordCount = wordCount + 1;
      if (wordCapacity <= wordCount) {
        allocation23 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
        if (wordData != 0) {
          _memcpy(allocation23,wordData,wordCount << 2);
          (**(code **)(glContext + 0x18))(wordData);
        }
        wordCapacity = wordCapacity + 0x80;
        wordData = allocation23;
      }
      *(undefined4 *)(wordCount * 4 + wordData) = 0x40000;
      wordCount = wordCount + 1;
    }
    else {
      local_5c = &wordCount;
      loopIndex = 0;
      local_68 = 0;
      local_64 = auStack_1f4;
      local_60 = auStack_170;
      loopIndex5 = 0;
      do {
        local_208[0] = '\0';
        iVar15 = loopIndex5 + *(int *)(a1Ptr74_2 + 100);
        uVar13 = *(uint *)(loopIndex5 + *(int *)(a1Ptr74_2 + 100));
        local_1e0 = *(undefined4 *)(iVar15 + 4);
        local_1dc = *(undefined4 *)(iVar15 + 8);
        staleArgR8 = *(undefined4 *)(iVar15 + 0xc);
        local_190 = *(undefined4 *)(iVar15 + 0x10);
        local_18c = *(undefined4 *)(iVar15 + 0x14);
        local_188 = *(undefined4 *)(iVar15 + 0x18);
        local_184 = *(undefined4 *)(iVar15 + 0x1c);
        local_180 = *(undefined4 *)(iVar15 + 0x20);
        local_17c = *(undefined4 *)(iVar15 + 0x24);
        uVar6 = *(undefined4 *)(iVar15 + 0x28);
        local_174 = *(undefined4 *)(iVar15 + 0x2c);
        local_1b0 = *(undefined4 *)(iVar15 + 0x30);
        local_1ac = *(undefined4 *)(iVar15 + 0x34);
        local_1a8 = *(undefined4 *)(iVar15 + 0x38);
        local_1a4 = *(undefined4 *)(iVar15 + 0x3c);
        (*(unsigned char *)((unsigned char *)&(local_178) + 0)) = (byte)((uint)uVar6 >> 0x18);
        bVar3 = (*(unsigned char *)((unsigned char *)&(local_178) + 0));
        uVar16 = (uint)(*(unsigned char *)((unsigned char *)&(local_178) + 0));
        local_1a0 = *(undefined4 *)(iVar15 + 0x40);
        local_19c = *(undefined4 *)(iVar15 + 0x44);
        uVar7 = *(undefined4 *)(iVar15 + 0x48);
        uVar14 = *(undefined4 *)(iVar15 + 0x4c);
        local_1d0 = *(undefined4 *)(iVar15 + 0x50);
        local_1cc = *(undefined4 *)(iVar15 + 0x54);
        local_1c8 = *(undefined4 *)(iVar15 + 0x58);
        local_1c4 = *(undefined4 *)(iVar15 + 0x5c);
        (*(unsigned char *)((unsigned char *)&(local_198) + 0)) = (byte)((uint)uVar7 >> 0x18);
        bVar2 = (*(unsigned char *)((unsigned char *)&(local_198) + 0));
        uVar8 = (uint)(*(unsigned char *)((unsigned char *)&(local_198) + 0));
        uVar4 = *(undefined4 *)(iVar15 + 0x68);
        uVar10 = *(undefined4 *)(iVar15 + 0x6c);
        local_1c0 = *(undefined4 *)(iVar15 + 0x60);
        local_1bc = *(undefined4 *)(iVar15 + 100);
        (*(unsigned char *)((unsigned char *)&(local_1b8) + 0)) = (byte)((uint)uVar4 >> 0x18);
        bVar1 = (*(unsigned char *)((unsigned char *)&(local_1b8) + 0));
        uVar5 = (uint)(*(unsigned char *)((unsigned char *)&(local_1b8) + 0));
        local_1d8 = staleArgR8;
        local_1b8 = uVar4;
        local_1b4 = uVar10;
        local_198 = uVar7;
        local_194 = uVar14;
        local_178 = uVar6;
        if (uVar13 < 0x20) {
          if ((0x1c < uVar13) || (uVar13 == 0xb)) goto LAB_000b0fbc;
LAB_000b0e20:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,staleArgR8,auStack_204,local_208,
                       (uint)*(byte *)(*(int *)(a1Ptr74_2 + 0x94) + loopIndex));
          local_178 = CONCAT13(bVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())gld_classifyOperand)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174,*(undefined4 *)(a1Ptr74_2 + 0x78),local_64);
          local_198 = CONCAT13(bVar2,(*(unsigned int *)((unsigned char *)&(local_198) + 1)));
          local_194 = uVar14;
          ((int (*)())gld_classifyOperand)(local_1b0,local_1ac,local_1a8,local_1a4,local_1a0,local_19c,local_198,uVar14,
                       *(undefined4 *)(a1Ptr74_2 + 0x78),auStack_1fc);
          local_1b8 = CONCAT13(bVar1,(*(unsigned int *)((unsigned char *)&(local_1b8) + 1)));
          local_1b4 = uVar10;
          ((int (*)())gld_classifyOperand)(local_1d0,local_1cc,local_1c8,local_1c4,local_1c0,local_1bc,local_1b8,uVar10,
                       *(undefined4 *)(a1Ptr74_2 + 0x78),local_60);
          staleArgR7 = auStack_204;
          ((int (*)())FUN_000ac720)(glContext,a1Ptr74_2,local_5c,uVar13,auStack_204,staleArgR8,local_64,auStack_1fc,
                       local_60,uVar16,uVar8,uVar5,local_188,local_184,local_180,local_17c,local_1a8
                       ,local_1a4,local_1a0,local_19c,local_1c8,local_1c4,local_1c0,local_1bc,
                       (uint)*(byte *)(loopIndex + *(int *)(a1Ptr74_2 + 0x94)));
        }
        else {
          if (2 < uVar13 - 0x3d) goto LAB_000b0e20;
LAB_000b0fbc:
          ((int (*)())FUN_000ab940)(local_1e0,local_1dc,staleArgR8,auStack_1fc,local_208,0);
          local_178 = CONCAT13(bVar3,(*(unsigned int *)((unsigned char *)&(local_178) + 1)));
          ((int (*)())gld_classifyOperand)(local_190,local_18c,local_188,local_184,local_180,local_17c,local_178,
                       local_174,*(undefined4 *)(a1Ptr74_2 + 0x78),auStack_204);
          staleArgR7 = auStack_1fc;
          ((int (*)())FUN_000aec40)(glContext,a1Ptr74_2,local_5c,uVar13,auStack_1fc,staleArgR8,auStack_204,local_188,
                       local_184,local_180,local_17c,uVar16,uVar14,uVar10);
        }
        if (local_208[0] != '\0') {
          local_68 = 1;
        }
        loopIndex5 = loopIndex5 + 0x70;
        loopIndex = loopIndex + 1;
      } while (*(int *)(*(int *)(a1Ptr74_2 + 100) + loopIndex5) != 0x41);
      uVar5 = wordCount;
      if (local_68 == 0) goto LAB_000b10a0;
    }
    if (wordCapacity <= wordCount) {
      allocation24 = (**(code **)(glContext + 0xc))(wordCapacity * 4 + 0x200);
      if (wordData != 0) {
        _memcpy(allocation24,wordData,wordCount << 2);
        (**(code **)(glContext + 0x18))(wordData);
      }
      wordCapacity = wordCapacity + 0x80;
      wordData = allocation24;
    }
    iVar11 = wordCount * 4;
    *(undefined4 *)(iVar11 + wordData) = 0x28;
    wordCount = wordCount + 1;
    unused = local_5c;
    iVar11 = (**(code **)(((unsigned char *)0x00001288) + glContext))(glContext,a1,a2,local_5c,staleArgR7,staleArgR8,iVar11);
    fpPassThrough1 = f1AfterCall2;
    if (iVar11 < 0) {
      glContextWord1130_2 = *(int *)(((unsigned char *)0x00001130) + glContext);
      a1Word70 = *(int *)(a1 + 0x70);
      uVar4 = *(undefined4 *)(glContextWord1130_2 * 4 + a1Word70);
      if (iVar11 == -1) {
        printf_LDBLStub_1a32d0(auStack_170,
                     "Fragment program exceeded native resources:\n  Temporaries          - %d\n  Parameters           - %d\n  Attributes           - %d\n  ALU instructions     - %d\n  Texture instructions - %d\n  Texture indirections - %d\n"
                     ,*(undefined4 *)(a1 + 0x68),*(undefined4 *)(a1 + 100),
                     *(undefined4 *)(a1 + 0x60),*(undefined4 *)(a1 + 0x54),
                     *(undefined4 *)(a1 + 0x58),*(undefined4 *)(a1 + 0x5c));
        if (*(int *)(((unsigned char *)0x00001128) + glContext) != 0) {
          (**(code **)(glContext + 0x18))(*(int *)(((unsigned char *)0x00001128) + glContext));
        }
        iVar11 = _strlen(auStack_170);
        allocation26 = (**(code **)(glContext + 0xc))(iVar11 + 1);
        *(undefined4 *)(((unsigned char *)0x00001128) + glContext) = allocation26;
        _strcpy(allocation26,auStack_170);
        glContextWord1130_2 = *(int *)(((unsigned char *)0x00001130) + glContext);
        a1Word70 = *(int *)(a1 + 0x70);
      }
      *(undefined4 *)(glContextWord1130_2 * 4 + a1Word70) = 0;
LAB_000b1448:
      (**(code **)(((unsigned char *)0x00001224) + glContext))(glContext,uVar4);
      return 0;
    }
  }
  else {
    unused = auStack_170;
    iVar11 = ((int (*)())gld_scanProgramTokens)(glContext,a1,unused);
    if (iVar11 == 0) {
      if (*(int *)(((unsigned char *)0x00001128) + glContext) != 0) {
        (**(code **)(glContext + 0x18))(*(int *)(((unsigned char *)0x00001128) + glContext));
      }
      allocation25 = (**(code **)(glContext + 0xc))(0x22);
      *(undefined4 *)(((unsigned char *)0x00001128) + glContext) = allocation25;
      _memcpy(allocation25,"program had bad or unsupported IL",0x22);
      return 0;
    }
    iVar11 = (**(code **)(((unsigned char *)0x00001288) + glContext))(glContext,a1,a2,unused);
    fpPassThrough1 = f1AfterCall;
    if (iVar11 == -1) {
      *(undefined1 *)(a1 + 0x6c) = 0;
    }
    else {
      if (iVar11 == -2) {
        uVar4 = *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + *(int *)(a1 + 0x70));
        *(undefined4 *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + *(int *)(a1 + 0x70)) = 0;
        goto LAB_000b1448;
      }
      *(undefined1 *)(a1 + 0x6c) = 1;
    }
  }
  a2[0x119] = '\0';
LAB_000b0028:
  ((unsigned char *)0x000011d0)[glContext] = 0;
  if (a1Ptr74_2[0x55] == '\0') {
    a1Ptr74 = *(int *)(a1 + 0x74);
    loopIndex2 = 0;
    if (0 < *(int *)(a1Ptr74 + 0x84)) {
      do {
        iVar15 = loopIndex2 * 0x14 + *(int *)(a1Ptr74 + 0x80);
        if (*(int *)(iVar15 + 8) == 0x34) {
          if (*a2 == '\0') {
            unused = *(uint **)(iVar15 + 4);
            (**(code **)(((unsigned char *)0x00001280) + glContext))
                      (glContext,a2,loopIndex2,unused,
                       *(int *)(iVar15 + 0xc) * 0x10 + *(int *)(a1Ptr74 + 0x8c),1,1);
            a1Ptr74 = *(int *)(a1 + 0x74);
          }
        }
        else {
          arbfpFetchParameterValue(glContext,iVar15,&local_1e0,unused);
          unused = *(uint **)(iVar15 + 4);
          (**(code **)(((unsigned char *)0x00001280) + glContext))(glContext,a2,loopIndex2,unused,&local_1e0,1,1);
          a1Ptr74 = *(int *)(a1 + 0x74);
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 < *(int *)(a1Ptr74 + 0x84));
    }
  }
  else {
    ((void (*)())FUN_000abab0)(glContext,a1,a2,fpPassThrough1);
  }
  if (((*(uint *)(glContext + 0x44) & 0x2000) != 0) && (*(char *)(a1 + 0x6c) != '\0')) {
    (**(code **)(((unsigned char *)0x00001290) + glContext))(glContext,a2);
  }
  return 1;
}

/* ilTokenBufPush @ 0xb15d0 (180 bytes) */
int ilTokenBufPush(ctx, tokenBuf, token)
  int ctx;
  uint *tokenBuf;
  undefined4 token;
{
  uint newTokenData;
  uint tokenIndex;
  
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = token;
  *tokenBuf = *tokenBuf + 1;
  return;
}

/* atifsEmitFinalColorClamp @ 0xb1690 (476 bytes) */
int atifsEmitFinalColorClamp(ctx, tokenBuf)
  int ctx;
  uint *tokenBuf;
{
  uint newTokenData;
  uint tokenIndex;
  
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0xe;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x170000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x40000;
  *tokenBuf = *tokenBuf + 1;
  return;
}

/* atifsEmitAddSecondaryColor @ 0xb1870 (800 bytes) */
int atifsEmitAddSecondaryColor(ctx, tokenBuf)
  int ctx;
  uint *tokenBuf;
{
  uint newTokenData;
  uint tokenIndex;
  
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 3;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x40000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x40000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x530000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined **)(tokenIndex * 4 + tokenBuf[2]) = ((unsigned char *)0x00004210);
  *tokenBuf = *tokenBuf + 1;
  return;
}

/* atifsEmitMoveWithWriteMask @ 0xb1b90 (748 bytes) */
int atifsEmitMoveWithWriteMask(ctx, tokenBuf, dstRegEnum, srcTempIndex, writeMask)
  int ctx;
  uint *tokenBuf;
  int dstRegEnum;
  uint srcTempIndex;
  uint writeMask;
{
  uint newTokenData;
  uint tokenIndex;
  uint ilWriteMask;
  
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x47;
  ilWriteMask = 0;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if ((writeMask & 7) == 0) {
    ilWriteMask = 0x15;
  }
  if ((writeMask & 1) != 0) {
    ilWriteMask = ilWriteMask & 0xfffffffc | 1;
  }
  if ((writeMask & 2) != 0) {
    ilWriteMask = ilWriteMask & 0xfffffff3 | 4;
  }
  if ((writeMask & 4) != 0) {
    ilWriteMask = ilWriteMask & 0xffffffcf | 0x10;
  }
  if ((writeMask & 8) != 0) {
    ilWriteMask = ilWriteMask | 0x40;
  }
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + tokenBuf[2]) = dstRegEnum + 0x76dfU & 0xffff | 0x440000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + tokenBuf[2]) = ilWriteMask;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + tokenBuf[2]) = srcTempIndex & 0xffff | 0x40000;
  *tokenBuf = *tokenBuf + 1;
  return;
}

/* atifsEmitSourceOperand @ 0xb1e80 (932 bytes) */
int atifsEmitSourceOperand(ctx, tokenBuf, srcArg, reserved0, isColorOp, regWritten)
  int ctx;
  uint *tokenBuf;
  uint *srcArg;
  undefined4 reserved0;
  undefined4 isColorOp;
  int regWritten;
{
  uint swizzleNewTokenData;
  uint newTokenData;
  uint tokenIndex;
  uint argRep;
  uint argMod;
  uint argReg;
  uint srcToken;
  undefined *swizzleWord;
  
  srcToken = 0;
  swizzleWord = (undefined *)0x0;
  argReg = *srcArg;
  if ((argReg - 0x8921 < 6) && (*(char *)(argReg + regWritten + -0x8921) == '\0')) {
    argReg = 0;
    *srcArg = 0;
LAB_000b1f80:
    srcToken = 0x410000;
    swizzleWord = ((unsigned char *)0x00004444);
  }
  else if (argReg < 0x8927) {
    if (argReg < 0x8921) {
      if (argReg == 1) {
        srcToken = 0x410000;
        swizzleWord = ((unsigned char *)0x00005555);
      }
      else {
        if (argReg == 0) goto LAB_000b1f80;
        if (argReg == 0x8577) {
          srcToken = 0x120000;
        }
      }
    }
    else {
      srcToken = argReg + 0x76df & 0xffff | 0x40000;
    }
  }
  else if (0x8940 < argReg) {
    if (argReg < 0x8949) {
      srcToken = argReg + 0x76bf & 0xffff | 0x10000;
    }
    else if (argReg == 0x896d) {
      srcToken = 0x130000;
    }
  }
  argRep = srcArg[3];
  if (argRep == 0) {
    argMod = srcArg[2];
    if (argMod == 0) goto LAB_000b2028;
  }
  else {
    argMod = srcArg[2];
  }
  srcToken = srcToken | 0x400000;
LAB_000b2028:
  if ((argMod & 1) != 0) {
    swizzleWord = (undefined *)((uint)swizzleWord | 0x40000);
  }
  if ((argMod & 2) != 0) {
    swizzleWord = (undefined *)((uint)swizzleWord | 0x10000);
  }
  if ((argMod & 4) != 0) {
    swizzleWord = (undefined *)((uint)swizzleWord | 0x8888);
  }
  if ((argMod & 8) != 0) {
    swizzleWord = (undefined *)((uint)swizzleWord | 0x20000);
  }
  if (1 < argReg) {
    if (argRep == 0x1904) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8888 | 0x1111);
    }
    else if (argRep < 0x1905) {
      if (argRep == 0) {
        swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8888 | 0x3210);
      }
      else if (argRep == 0x1903) {
        swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8888);
      }
    }
    else if (argRep == 0x1905) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8888 | 0x2222);
    }
    else if (argRep == 0x1906) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8888 | 0x3333);
    }
  }
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + tokenBuf[2]) = srcToken;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if ((srcToken & 0x400000) != 0) {
    if (tokenBuf[1] <= tokenIndex) {
      swizzleNewTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
      if (tokenBuf[2] != 0) {
        _memcpy(swizzleNewTokenData,tokenBuf[2],*tokenBuf << 2);
        (**(code **)(ctx + 0x18))(tokenBuf[2]);
      }
      tokenBuf[2] = swizzleNewTokenData;
      tokenIndex = *tokenBuf;
      tokenBuf[1] = tokenBuf[1] + 0x80;
    }
    *(undefined **)(tokenIndex * 4 + tokenBuf[2]) = swizzleWord;
    *tokenBuf = *tokenBuf + 1;
  }
  return 1;
}

/* atifsEmitDestinationOperand @ 0xb2260 (692 bytes) */
int atifsEmitDestinationOperand(ctx, tokenBuf, dstArg, reserved0, hasWriteMask, regWritten)
  int ctx;
  uint *tokenBuf;
  uint *dstArg;
  undefined4 reserved0;
  int hasWriteMask;
  int regWritten;
{
  uint newTokenData;
  uint tokenIndex;
  uint dstModBits;
  uint dstRegEnum;
  uint dstMask;
  uint ilDstWord;
  uint dstToken;
  
  ilDstWord = 0;
  dstRegEnum = *dstArg;
  if (dstRegEnum - 0x8921 < 6) {
    *(undefined1 *)(dstRegEnum + regWritten + -0x8921) = 1;
    dstRegEnum = dstRegEnum + 0x76df;
  }
  dstToken = dstRegEnum & 0xffff | 0x40000;
  if (hasWriteMask != 0) {
    dstMask = dstArg[1];
    ilDstWord = 0;
    if ((dstMask & 7) == 0) {
      dstToken = dstRegEnum & 0xffff | 0x440000;
      ilDstWord = 0x15;
    }
    if ((dstMask & 1) != 0) {
      dstToken = dstToken | 0x400000;
      ilDstWord = ilDstWord & 0xfffffffc | 1;
    }
    if ((dstMask & 2) != 0) {
      dstToken = dstToken | 0x400000;
      ilDstWord = ilDstWord & 0xfffffff3 | 4;
    }
    if ((dstMask & 4) != 0) {
      dstToken = dstToken | 0x400000;
      ilDstWord = ilDstWord & 0xffffffcf | 0x10;
    }
    if ((dstMask & 8) == 0) goto LAB_000b2364;
  }
  dstToken = dstToken | 0x400000;
  ilDstWord = ilDstWord | 0x40;
LAB_000b2364:
  dstModBits = dstArg[2];
  if (dstModBits != 0) {
    dstToken = dstToken | 0x400000;
    if ((dstModBits & 0x40) != 0) {
      ilDstWord = ilDstWord | 0x100;
    }
    switch(dstModBits & 0x3f) {
    case 1:
      ilDstWord = ilDstWord | 0x200;
      break;
    case 2:
      ilDstWord = ilDstWord | 0x400;
      break;
    case 4:
      ilDstWord = ilDstWord | 0x600;
      break;
    case 8:
      ilDstWord = ilDstWord | 0x800;
      break;
    case 0x10:
      ilDstWord = ilDstWord | 0xa00;
      break;
    case 0x20:
      ilDstWord = ilDstWord | 0xc00;
    }
  }
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + tokenBuf[2]) = dstToken;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if ((dstToken & 0x400000) != 0) {
    if (tokenBuf[1] <= tokenIndex) {
      newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
      if (tokenBuf[2] != 0) {
        _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
        (**(code **)(ctx + 0x18))(tokenBuf[2]);
      }
      tokenBuf[2] = newTokenData;
      tokenIndex = *tokenBuf;
      tokenBuf[1] = tokenBuf[1] + 0x80;
    }
    *(uint *)(tokenIndex * 4 + tokenBuf[2]) = ilDstWord;
    *tokenBuf = *tokenBuf + 1;
  }
  return 1;
}

/* atifsEmitTextureOps @ 0xb25a0 (2216 bytes) */
int atifsEmitTextureOps(ctx, tokenBuf, fsState, pass, passCount, regWritten)
  int ctx;
  uint *tokenBuf;
  int fsState;
  int pass;
  undefined4 passCount;
  int regWritten;
{
  int textureOp2;
  int entryOffset;
  int coordSource;
  uint coordSourceToken;
  uint newTokenData;
  uint tokenIndex;
  uint coordNewTokenData;
  int textureOp;
  uint coordTokenIndex;
  uint regsPerPass;
  int shaderDef;
  uint loopIndex;
  uint swizzleMode;
  undefined *swizzleWord;
  int recordOffset;
  
  regsPerPass = (uint)*(ushort *)(fsState + 0x14);
  shaderDef = *(int *)(fsState + 0x10);
  if (*(ushort *)(fsState + 0x14) != 0) {
    loopIndex = 0;
    do {
      recordOffset = (loopIndex + regsPerPass * pass) * 0xc;
      textureOp = recordOffset + *(int *)(shaderDef + 0xc);
      if (*(char *)(recordOffset + *(int *)(shaderDef + 0xc)) != '\0') {
        swizzleMode = *(uint *)(textureOp + 4);
        swizzleWord = (undefined *)0x0;
        if (*(char *)(textureOp + 1) == '\0') {
          if ((swizzleMode == 0x8976) && (loopIndex == *(int *)(textureOp + 8) - 0x8921U)) goto LAB_000b2c0c;
          tokenIndex = *tokenBuf;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x47;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(tokenIndex * 4 + tokenBuf[2]) = loopIndex + 6 & 0xffff | 0x40000;
          *tokenBuf = *tokenBuf + 1;
          *(undefined1 *)(regWritten + loopIndex) = 1;
          coordSource = *(int *)(recordOffset + *(int *)(shaderDef + 0xc) + 8);
          if (coordSource - 0x84c0U < 6) {
            coordSourceToken = coordSource + 0x7b40U & 0xffff | 0x110000;
          }
          else {
            coordSourceToken = coordSource + 0x76dfU & 0xffff | 0x40000;
          }
          coordTokenIndex = *tokenBuf;
          if (tokenBuf[1] <= coordTokenIndex) {
            coordNewTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(coordNewTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = coordNewTokenData;
            coordTokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(coordTokenIndex * 4 + tokenBuf[2]) = coordSourceToken | 0x400000;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
        }
        else {
          tokenIndex = *tokenBuf;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(tokenIndex * 4 + tokenBuf[2]) = (loopIndex & 0x3fff) << 0x10 | 0x5d;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(tokenIndex * 4 + tokenBuf[2]) = loopIndex + 6 & 0xffff | 0x40000;
          *tokenBuf = *tokenBuf + 1;
          coordSource = *(int *)(recordOffset + *(int *)(shaderDef + 0xc) + 8);
          if (coordSource - 0x84c0U < 6) {
            coordSourceToken = coordSource + 0x7b40U & 0xffff | 0x110000;
          }
          else if (*(char *)(regWritten + coordSource + -0x8921) == '\0') {
            swizzleMode = 0;
            coordSourceToken = coordSource + 0x76dfU & 0xffff | 0x10000;
          }
          else {
            coordSourceToken = coordSource + 0x76dfU & 0xffff | 0x40000;
          }
          *(undefined1 *)(loopIndex + regWritten) = 1;
          coordTokenIndex = *tokenBuf;
          if (tokenBuf[1] <= coordTokenIndex) {
            coordNewTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(coordNewTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = coordNewTokenData;
            coordTokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(coordTokenIndex * 4 + tokenBuf[2]) = coordSourceToken | 0x400000;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
        }
        if (swizzleMode == 0x8977) {
          swizzleWord = ((unsigned char *)0x00003310);
        }
        else if (swizzleMode < 0x8978) {
          if (swizzleMode == 0) {
            swizzleWord = ((unsigned char *)0x00004444);
          }
          else if (swizzleMode == 0x8976) {
            swizzleWord = ((unsigned char *)0x00003210);
          }
        }
        else if (swizzleMode == 0x8978) {
          swizzleWord = (undefined *)0x602510;
        }
        else if (swizzleMode == 0x8979) {
          swizzleWord = (undefined *)0x603510;
        }
        if (tokenBuf[1] <= tokenIndex) {
          newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
          if (tokenBuf[2] != 0) {
            _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
            (**(code **)(ctx + 0x18))(tokenBuf[2]);
          }
          tokenBuf[2] = newTokenData;
          tokenIndex = *tokenBuf;
          tokenBuf[1] = tokenBuf[1] + 0x80;
        }
        *(undefined **)(tokenIndex * 4 + tokenBuf[2]) = swizzleWord;
        *tokenBuf = *tokenBuf + 1;
        regsPerPass = (uint)*(ushort *)(fsState + 0x14);
      }
LAB_000b2c0c:
      loopIndex = loopIndex + 1;
    } while ((int)loopIndex < (int)regsPerPass);
    if (regsPerPass != 0) {
      loopIndex = 0;
      do {
        entryOffset = (loopIndex + regsPerPass * pass) * 0xc;
        textureOp2 = entryOffset + *(int *)(shaderDef + 0xc);
        if ((*(char *)(entryOffset + *(int *)(shaderDef + 0xc)) != '\0') &&
           (((*(char *)(textureOp2 + 1) != '\0' || (*(int *)(textureOp2 + 4) != 0x8976)) ||
            (loopIndex != *(int *)(textureOp2 + 8) - 0x8921U)))) {
          tokenIndex = *tokenBuf;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x47;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(tokenIndex * 4 + tokenBuf[2]) = loopIndex & 0xffff | 0x40000;
          tokenIndex = *tokenBuf + 1;
          *tokenBuf = tokenIndex;
          if (tokenBuf[1] <= tokenIndex) {
            newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
            if (tokenBuf[2] != 0) {
              _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
              (**(code **)(ctx + 0x18))(tokenBuf[2]);
            }
            tokenBuf[2] = newTokenData;
            tokenIndex = *tokenBuf;
            tokenBuf[1] = tokenBuf[1] + 0x80;
          }
          *(uint *)(tokenIndex * 4 + tokenBuf[2]) = (loopIndex & 0xffff) + 6 & 0xffff | 0x40000;
          *tokenBuf = *tokenBuf + 1;
          regsPerPass = (uint)*(ushort *)(fsState + 0x14);
        }
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)regsPerPass);
    }
  }
  return;
}

/* atifsEmitClearTemp0 @ 0xb2e60 (636 bytes) */
int atifsEmitClearTemp0(ctx, tokenBuf)
  int ctx;
  uint *tokenBuf;
{
  uint newTokenData;
  uint tokenIndex;
  
  tokenIndex = *tokenBuf;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x47;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x40000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + tokenBuf[2]) = 0x410000;
  tokenIndex = *tokenBuf + 1;
  *tokenBuf = tokenIndex;
  if (tokenBuf[1] <= tokenIndex) {
    newTokenData = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(newTokenData,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = newTokenData;
    tokenIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined **)(tokenIndex * 4 + tokenBuf[2]) = ((unsigned char *)0x00004444);
  *tokenBuf = *tokenBuf + 1;
  return;
}

/* atifsEmitInputDeclarations @ 0xb30e0 (1352 bytes) */
int atifsEmitInputDeclarations(ctx, tokenBuf, fsState, shaderDef)
  int ctx;
  uint *tokenBuf;
  int fsState;
  int shaderDef;
{
  uint textureUnitCount;
  int secondPassOffset;
  int sampleOps;
  uint pushIndex;
  int rendererRec;
  uint loopIndex;
  int loopIndex2;
  
  pushIndex = *tokenBuf;
  rendererRec = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (tokenBuf[1] <= pushIndex) {
    pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = pushIndex;
    pushIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(pushIndex * 4 + tokenBuf[2]) = 0x1ff0016;
  pushIndex = *tokenBuf + 1;
  *tokenBuf = pushIndex;
  if (tokenBuf[1] <= pushIndex) {
    pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = pushIndex;
    pushIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(pushIndex * 4 + tokenBuf[2]) = 0x120000;
  pushIndex = *tokenBuf + 1;
  *tokenBuf = pushIndex;
  if (*(char *)(shaderDef + 0x6c) == '\0') {
    if ((*(uint *)(ctx + 0x44) & 0x80100000) == 0x80000000) {
      if (*(short *)(((unsigned char *)0x00002d48) + rendererRec) != -0x7e06) goto LAB_000b3398;
    }
    else if ((*(uint *)(ctx + 0x44) & 0x800000) == 0) goto LAB_000b3398;
  }
  if (tokenBuf[1] <= pushIndex) {
    pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = pushIndex;
    pushIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(pushIndex * 4 + tokenBuf[2]) = 0x1ff0016;
  pushIndex = *tokenBuf + 1;
  *tokenBuf = pushIndex;
  if (tokenBuf[1] <= pushIndex) {
    pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
    if (tokenBuf[2] != 0) {
      _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
      (**(code **)(ctx + 0x18))(tokenBuf[2]);
    }
    tokenBuf[2] = pushIndex;
    pushIndex = *tokenBuf;
    tokenBuf[1] = tokenBuf[1] + 0x80;
  }
  *(undefined4 *)(pushIndex * 4 + tokenBuf[2]) = 0x130000;
  pushIndex = *tokenBuf + 1;
  *tokenBuf = pushIndex;
LAB_000b3398:
  textureUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
  if (textureUnitCount != 0) {
    loopIndex = 0;
    do {
      if (((int)(uint)*(byte *)(fsState + 1) >> (loopIndex & 0x3f) & 1U) != 0) {
        if (tokenBuf[1] <= pushIndex) {
          pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
          if (tokenBuf[2] != 0) {
            _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
            (**(code **)(ctx + 0x18))(tokenBuf[2]);
          }
          tokenBuf[2] = pushIndex;
          pushIndex = *tokenBuf;
          tokenBuf[1] = tokenBuf[1] + 0x80;
        }
        *(undefined4 *)(pushIndex * 4 + tokenBuf[2]) = 0x1ff0016;
        pushIndex = *tokenBuf + 1;
        *tokenBuf = pushIndex;
        if (tokenBuf[1] <= pushIndex) {
          pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
          if (tokenBuf[2] != 0) {
            _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
            (**(code **)(ctx + 0x18))(tokenBuf[2]);
          }
          tokenBuf[2] = pushIndex;
          pushIndex = *tokenBuf;
          tokenBuf[1] = tokenBuf[1] + 0x80;
        }
        *(uint *)(pushIndex * 4 + tokenBuf[2]) = loopIndex & 0xffff | 0x110000;
        pushIndex = *tokenBuf + 1;
        *tokenBuf = pushIndex;
        textureUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
      }
      loopIndex = loopIndex + 1;
    } while ((int)loopIndex < (int)textureUnitCount);
  }
  textureUnitCount = (uint)*(ushort *)(fsState + 0x14);
  if (*(ushort *)(fsState + 0x14) != 0) {
    loopIndex2 = 0;
    rendererRec = 0;
    do {
      sampleOps = *(int *)(shaderDef + 0xc);
      if (((*(char *)(sampleOps + rendererRec) != '\0') && (*(char *)(sampleOps + rendererRec + 1) != '\0')) ||
         ((secondPassOffset = (loopIndex2 + textureUnitCount) * 0xc, *(char *)(sampleOps + secondPassOffset) != '\0' &&
          (*(char *)(sampleOps + secondPassOffset + 1) != '\0')))) {
        if (tokenBuf[1] <= pushIndex) {
          pushIndex = (**(code **)(ctx + 0xc))(tokenBuf[1] * 4 + 0x200);
          if (tokenBuf[2] != 0) {
            _memcpy(pushIndex,tokenBuf[2],*tokenBuf << 2);
            (**(code **)(ctx + 0x18))(tokenBuf[2]);
          }
          tokenBuf[2] = pushIndex;
          pushIndex = *tokenBuf;
          tokenBuf[1] = tokenBuf[1] + 0x80;
        }
        *(uint *)(pushIndex * 4 + tokenBuf[2]) = loopIndex2 << 0x10 | 0x19;
        pushIndex = *tokenBuf + 1;
        *tokenBuf = pushIndex;
        textureUnitCount = (uint)*(ushort *)(fsState + 0x14);
      }
      loopIndex2 = loopIndex2 + 1;
      rendererRec = rendererRec + 0xc;
    } while (loopIndex2 < (int)textureUnitCount);
  }
  return;
}

/* atifsCompileCurrentShader @ 0xb3630 (3316 bytes) */
int atifsCompileCurrentShader(ctx)
  int ctx;
{
  uint constantIndex;
  uint constantCount;
  uint ilCndOpcodeBase;
  uint alphaSourceCount;
  undefined4 programBytes;
  int ilCndModeBit;
  int savedColorDst;
  int constantOffset2;
  int passIndex;
  int programTable;
  code *setConstantFn;
  int instructionNumber;
  int contextSlot;
  int constantOffset;
  bool isLastConstant;
  bool redirectedToScratch;
  bool haveAlphaOp;
  ushort ilOpcode;
  code *programSizeFn;
  char wantSecondaryAdd;
  int regIndex;
  int colorOpsInPass;
  undefined4 staleProgram;
  undefined4 ilHeaderWord;
  undefined4 deadArg4;
  undefined4 deadArg5;
  undefined1 *constantFloats;
  undefined4 deadArg6;
  uint constantBit;
  uint ctxFlags;
  int alphaOpsInPass;
  int colorOpsDoneInPass;
  int alphaOpsDoneInPass;
  int nextColorOp;
  int nextAlphaOp;
  int opsDoneInPass;
  undefined1 *compiledProgram;
  code *callocFn;
  int *colorOp;
  undefined1 *programConstantPtr;
  int *alphaOp;
  int shaderDef;
  int regCount;
  uint ilOpcodeWord;
  undefined1 regWritten [8];
  undefined4 tokenCount;
  undefined4 tokenCapacity;
  undefined4 tokenData;
  int passCount;
  int rendererRec;
  
  rendererRec = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (((unsigned char *)0x00001134)[ctx] == '\0') {
    shaderDef = *(int *)(((unsigned char *)0x00001144) + ctx);
  }
  else {
    shaderDef = *(int *)(((unsigned char *)0x00001154) + ctx) + 0x10;
  }
  compiledProgram = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + ctx) * 4 + *(int *)(shaderDef + 0x70));
  if (compiledProgram != (undefined1 *)0x0) {
    ctxFlags = *(uint *)(ctx + 0x44);
    if ((ctxFlags & 0x100000) == 0) {
      if ((((int)ctxFlags < 0) && (*(short *)(((unsigned char *)0x00002d48) + rendererRec) == -0x7e06)) ||
         (wantSecondaryAdd = '\0', (ctxFlags & 0x80800000) == 0x800000)) {
        wantSecondaryAdd = '\x01';
      }
    }
    else if (((ctxFlags & 0x800000) == 0) ||
            (wantSecondaryAdd = '\x01', *(char *)(*(int *)(((unsigned char *)0x00001168) + ctx) + 0x6e) == '\0')) {
      wantSecondaryAdd = '\0';
    }
    if (compiledProgram[0x118] == wantSecondaryAdd) {
      if (((unsigned char *)0x00001136)[ctx] != '\0') {
        *compiledProgram = 0;
      }
    }
    else {
      compiledProgram[0x119] = 1;
    }
    if (compiledProgram[0x119] == '\0') goto LAB_000b42ec;
  }
  tokenData = 0;
  tokenCount = 0;
  tokenCapacity = 0;
  ((int (*)())ilTokenBufPush)(ctx,&tokenCount,1);
  ilHeaderWord = 0x10200;
  ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x10200);
  regIndex = 0;
  regCount = 8;
  do {
    regWritten[regIndex] = 0;
    regIndex = regIndex + 1;
    regCount = regCount + -1;
  } while (regCount != 0);
  if (compiledProgram != (undefined1 *)0x0) {
    programTable = *(int *)(shaderDef + 0x70);
    staleProgram = *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + ctx) * 4 + programTable);
    *(undefined4 *)(*(int *)(((unsigned char *)0x0000113c) + ctx) * 4 + programTable) = 0;
    (**(code **)(((unsigned char *)0x00001158) + ctx))(ctx,staleProgram,ilHeaderWord,deadArg4,deadArg5,deadArg6,programTable);
    programSizeFn = *(code **)(((unsigned char *)0x00001284) + ctx);
    contextSlot = *(int *)(((unsigned char *)0x0000113c) + ctx);
    callocFn = *(code **)(ctx + 0x10);
    programTable = *(int *)(shaderDef + 0x70);
  }
  else {
    programSizeFn = *(code **)(((unsigned char *)0x00001284) + ctx);
    contextSlot = *(int *)(((unsigned char *)0x0000113c) + ctx);
    callocFn = *(code **)(ctx + 0x10);
    programTable = *(int *)(shaderDef + 0x70);
  }
  programBytes = (*programSizeFn)(ctx);
  programBytes = (*callocFn)(1,programBytes);
  *(undefined4 *)(contextSlot * 4 + programTable) = programBytes;
  compiledProgram = *(undefined1 **)(*(int *)(((unsigned char *)0x0000113c) + ctx) * 4 + *(int *)(shaderDef + 0x70));
  *compiledProgram = 0;
  passCount = *(int *)(shaderDef + 4);
  ((int (*)())atifsEmitInputDeclarations)(ctx,&tokenCount,((unsigned char *)0x00001134U) + ctx,shaderDef);
  ((int (*)())atifsEmitClearTemp0)(ctx,&tokenCount);
  if (0 < passCount) {
    nextColorOp = 0;
    nextAlphaOp = 0;
    instructionNumber = 0;
    passIndex = 0;
    do {
      colorOpsDoneInPass = 0;
      alphaOpsDoneInPass = 0;
      opsDoneInPass = 0;
      ((int (*)())atifsEmitTextureOps)(ctx,&tokenCount,((unsigned char *)0x00001134U) + ctx,passIndex,passCount,regWritten);
      while( true ) {
        colorOpsInPass = *(int *)(*(int *)(shaderDef + 0x14) + passIndex * 4);
        alphaOpsInPass = *(int *)(*(int *)(shaderDef + 0x20) + passIndex * 4);
        if (colorOpsInPass + alphaOpsInPass <= opsDoneInPass) break;
        if (((nextColorOp < *(int *)(shaderDef + 0x18)) && (colorOpsDoneInPass < colorOpsInPass)) &&
           (colorOp = (int *)(nextColorOp * 0x4c + *(int *)(shaderDef + 0x10)), instructionNumber == colorOp[0x11])) {
          nextColorOp = nextColorOp + 1;
          colorOpsDoneInPass = colorOpsDoneInPass + 1;
          opsDoneInPass = opsDoneInPass + 1;
          instructionNumber = instructionNumber + 1;
        }
        else {
          colorOp = (int *)0x0;
        }
        if (((nextAlphaOp < *(int *)(shaderDef + 0x24)) && (alphaOpsDoneInPass < alphaOpsInPass)) &&
           (alphaOp = (int *)(nextAlphaOp * 0x4c + *(int *)(shaderDef + 0x1c)), instructionNumber == alphaOp[0x11])) {
          alphaOpsDoneInPass = alphaOpsDoneInPass + 1;
          opsDoneInPass = opsDoneInPass + 1;
          nextAlphaOp = nextAlphaOp + 1;
          instructionNumber = instructionNumber + 1;
        }
        else {
          alphaOp = (int *)0x0;
        }
        if ((colorOp == (int *)0x0) || (alphaOp == (int *)0x0)) goto LAB_000b3a90;
        switch(*alphaOp) {
        case 0x8961:
          alphaSourceCount = 1;
          break;
        default:
          alphaSourceCount = 0;
          break;
        case 0x8966:
        case 0x8967:
          if (*alphaOp == *colorOp) goto LAB_000b3a90;
        case 0x8963:
        case 0x8964:
        case 0x8965:
          alphaSourceCount = 2;
          break;
        case 0x896c:
          if (*colorOp == 0x896c) goto LAB_000b3a90;
        case 0x8968:
        case 0x8969:
        case 0x896a:
        case 0x896b:
          alphaSourceCount = 3;
        }
        savedColorDst = colorOp[1];
        if (((savedColorDst != alphaOp[5]) && ((savedColorDst != alphaOp[9] || (alphaSourceCount < 2)))) &&
           ((savedColorDst != alphaOp[0xd] || (alphaSourceCount < 3)))) {
LAB_000b3a90:
          if (colorOp != (int *)0x0) {
            redirectedToScratch = false;
            savedColorDst = 0;
            goto LAB_000b3aa8;
          }
          redirectedToScratch = false;
          savedColorDst = 0;
          goto switchD_000b3adc_caseD_8962;
        }
        savedColorDst = colorOp[1];
        redirectedToScratch = true;
        colorOp[1] = 6;
LAB_000b3aa8:
        haveAlphaOp = alphaOp != (int *)0x0;
        switch(*colorOp) {
        case 0x8961:
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x47);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,colorOp + 1,0,1,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 5,0,1,regWritten);
        default:
          goto switchD_000b3adc_caseD_8962;
        case 0x8963:
          ilOpcode = 3;
          break;
        case 0x8964:
          ilOpcode = 0x49;
          break;
        case 0x8965:
          ilOpcode = 0x5b;
          break;
        case 0x8966:
          if ((haveAlphaOp) && (*alphaOp == 0x8966)) {
            colorOp[2] = colorOp[2] | 8;
          }
          ilOpcode = 0x22;
          break;
        case 0x8967:
          if ((haveAlphaOp) && (*alphaOp == 0x8967)) {
            colorOp[2] = colorOp[2] | 8;
          }
          ilOpcode = 0x23;
          break;
        case 0x8968:
          ilOpcode = 0x40;
          goto LAB_000b3c70;
        case 0x8969:
          ilOpcode = 0x3f;
LAB_000b3c70:
          ilOpcodeWord = (uint)ilOpcode;
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,ilOpcodeWord);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,colorOp + 1,0,1,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 5,0,1,regWritten);
LAB_000b3e14:
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 9,0,1,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 0xd,0,1,regWritten);
          goto switchD_000b3adc_caseD_8962;
        case 0x896a:
          ilCndOpcodeBase = 0x3000d;
          ilCndModeBit = 1;
          goto LAB_000b3d3c;
        case 0x896b:
          ilCndOpcodeBase = 0x2000d;
          ilCndModeBit = 0;
LAB_000b3d3c:
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,ilCndModeBit << 0x16 | ilCndOpcodeBase);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,colorOp + 1,0,1,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 0xd,0,1,regWritten);
          goto LAB_000b3bb4;
        case 0x896c:
          if ((haveAlphaOp) && (*alphaOp == 0x896c)) {
            colorOp[2] = colorOp[2] | 8;
          }
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x21);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,colorOp + 1,0,1,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 5,0,1,regWritten);
          goto LAB_000b3e14;
        }
        ilOpcodeWord = (uint)ilOpcode;
        ((int (*)())ilTokenBufPush)(ctx,&tokenCount,ilOpcodeWord);
        ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,colorOp + 1,0,1,regWritten);
LAB_000b3bb4:
        ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 5,0,1,regWritten);
        ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,colorOp + 9,0,1,regWritten);
switchD_000b3adc_caseD_8962:
        if (alphaOp == (int *)0x0) goto switchD_000b3e78_caseD_8962;
        switch(*alphaOp) {
        case 0x8961:
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x47);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,alphaOp + 1,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 5,0,0,regWritten);
          break;
        case 0x8963:
          ilOpcode = 3;
          goto LAB_000b3f1c;
        case 0x8964:
          ilOpcode = 0x49;
          goto LAB_000b3f1c;
        case 0x8965:
          ilOpcode = 0x5b;
LAB_000b3f1c:
          ilOpcodeWord = (uint)ilOpcode;
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,ilOpcodeWord);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,alphaOp + 1,0,0,regWritten);
LAB_000b4120:
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 5,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 9,0,0,regWritten);
          break;
        case 0x8968:
          ilOpcode = 0x40;
          goto LAB_000b3f68;
        case 0x8969:
          ilOpcode = 0x3f;
LAB_000b3f68:
          ilOpcodeWord = (uint)ilOpcode;
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,ilOpcodeWord);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,alphaOp + 1,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 5,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 9,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 0xd,0,0,regWritten);
          break;
        case 0x896a:
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x43000d);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,alphaOp + 1,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 0xd,0,0,regWritten);
          goto LAB_000b4120;
        case 0x896b:
          ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x2000d);
          ((int (*)())atifsEmitDestinationOperand)(ctx,&tokenCount,alphaOp + 1,0,0,regWritten);
          ((int (*)())atifsEmitSourceOperand)(ctx,&tokenCount,alphaOp + 0xd,0,0,regWritten);
          goto LAB_000b4120;
        }
switchD_000b3e78_caseD_8962:
        if (redirectedToScratch) {
          ((int (*)())atifsEmitMoveWithWriteMask)(ctx,&tokenCount,savedColorDst,colorOp[1],colorOp[2]);
          colorOp[1] = savedColorDst;
        }
      }
      passIndex = passIndex + 1;
    } while (passCount != passIndex);
  }
  if ((*(uint *)(ctx + 0x44) & 0x80100000) == 0x80000000) {
    if (*(short *)(((unsigned char *)0x00002d48) + rendererRec) == -0x7e06) goto LAB_000b420c;
LAB_000b41b8:
    compiledProgram[0x118] = 0;
  }
  else {
    if ((*(uint *)(ctx + 0x44) & 0x800000) == 0) goto LAB_000b41b8;
LAB_000b420c:
    ((int (*)())atifsEmitAddSecondaryColor)(ctx,&tokenCount);
    compiledProgram[0x118] = 1;
  }
  ((int (*)())atifsEmitFinalColorClamp)(ctx,&tokenCount);
  ((int (*)())ilTokenBufPush)(ctx,&tokenCount,0x28);
  *(undefined4 *)(compiledProgram + 0x11c) = 0;
  constantCount = (uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx);
  if (constantCount != 0) {
    constantBit = 0;
    constantOffset2 = 0;
    programConstantPtr = compiledProgram;
    do {
      if (*(char *)(*(int *)(shaderDef + 0x28) + constantOffset2) != '\0') {
        *(uint *)(compiledProgram + 0x11c) = 1 << (constantBit & 0x3f) | *(uint *)(compiledProgram + 0x11c);
        *(undefined4 *)(programConstantPtr + 0x98) = *(undefined4 *)(*(int *)(shaderDef + 0x28) + constantOffset2 + 4);
        *(undefined4 *)(programConstantPtr + 0x9c) = *(undefined4 *)(*(int *)(shaderDef + 0x28) + constantOffset2 + 8);
        *(undefined4 *)(programConstantPtr + 0xa0) = *(undefined4 *)(*(int *)(shaderDef + 0x28) + constantOffset2 + 0xc);
        *(undefined4 *)(programConstantPtr + 0xa4) = *(undefined4 *)(*(int *)(shaderDef + 0x28) + constantOffset2 + 0x10);
        constantCount = (uint)*(ushort *)(((unsigned char *)0x0000114a) + ctx);
      }
      constantBit = constantBit + 1;
      constantOffset2 = constantOffset2 + 0x14;
      programConstantPtr = programConstantPtr + 0x10;
    } while ((int)constantBit < (int)constantCount);
  }
  compiledProgram[0x120] = 1;
  (**(code **)(((unsigned char *)0x00001288) + ctx))(ctx,0,compiledProgram,&tokenCount);
  compiledProgram[0x119] = 0;
LAB_000b42ec:
  constantIndex = 0;
  constantOffset = 0;
  ((unsigned char *)0x00001136)[ctx] = 0;
  programConstantPtr = compiledProgram + 0x98;
  do {
    if ((1 << (constantIndex & 0x3f) & *(uint *)(compiledProgram + 0x11c)) == 0) {
      if (*(char *)(constantOffset + *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0xc)) != '\0') {
        setConstantFn = *(code **)(((unsigned char *)0x00001280) + ctx);
        constantFloats = (undefined1 *)(constantOffset + *(int *)(*(int *)(((unsigned char *)0x00001154) + ctx) + 0xc) + 4);
        goto LAB_000b4370;
      }
    }
    else {
      setConstantFn = *(code **)(((unsigned char *)0x00001280) + ctx);
      constantFloats = programConstantPtr;
LAB_000b4370:
      (*setConstantFn)(ctx,compiledProgram,constantIndex,constantIndex,constantFloats,1,0);
    }
    isLastConstant = constantIndex == 7;
    programConstantPtr = programConstantPtr + 0x10;
    constantOffset = constantOffset + 0x14;
    constantIndex = constantIndex + 1;
    if (isLastConstant) {
      if ((*(uint *)(ctx + 0x44) & 0x22000) == 0x20000) {
        (**(code **)(((unsigned char *)0x00001290) + ctx))(ctx,compiledProgram);
      }
      return 1;
    }
  } while( true );
}

/* noop_b43f0 @ 0xb43f0 (4 bytes) */
int noop_b43f0()
{
  return;
}

/* FUN_000b4400 @ 0xb4400 (2136 bytes) */
int FUN_000b4400(glContext, compileOutput, compileRecord, ilSource, glContextWord1e5c)
  int glContext;
  int *compileOutput;
  int *compileRecord;
  int *ilSource;
  int glContextWord1e5c;
{
  int compileRecordPtrc;
  int loopIndex;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined1 local_38 [28];
  
  if ((((compileOutput == (int *)0x0) || (compileRecord == (int *)0x0)) || (ilSource == (int *)0x0)) ||
     (glContextWord1e5c == 0)) {
    return 1;
  }
  *compileOutput = glContext;
  compileOutput[0xe] = 0;
  compileOutput[1] = 0;
  iVar8 = 0;
  compileOutput[2] = 0;
  *(undefined1 *)(compileOutput + 3) = 0;
  *(undefined1 *)((int)compileOutput + 0xd) = 0;
  *(undefined1 *)((int)compileOutput + 0xe) = 0;
  compileOutput[4] = 0;
  compileOutput[5] = 0;
  compileOutput[7] = 0;
  compileOutput[9] = 0;
  compileOutput[10] = 0;
  compileOutput[0xb] = 0;
  compileOutput[0xc] = 0;
  *(undefined1 *)(compileOutput + 0xd) = 0;
  compileOutput[8] = 0;
  compileOutput[6] = 0x21;
  piVar4 = compileOutput;
  piVar7 = compileOutput;
  piVar9 = compileOutput;
  do {
    bVar1 = iVar8 != 2;
    piVar4[0xf] = 0x21;
    piVar4[0x12] = 0;
    piVar9[0x15] = 0;
    piVar9[0x16] = 1;
    piVar9[0x17] = 2;
    piVar9[0x18] = 3;
    *(undefined1 *)(piVar4 + 0x21) = 0;
    *(undefined1 *)((int)piVar4 + 0x85) = 0;
    *(undefined1 *)((int)piVar4 + 0x86) = 0;
    *(undefined1 *)((int)piVar4 + 0x87) = 0;
    *(undefined1 *)(piVar7 + 0x24) = 0;
    *(undefined1 *)((int)piVar7 + 0x93) = 0;
    *(undefined1 *)((int)piVar7 + 0x96) = 0;
    *(undefined1 *)((int)piVar7 + 0x99) = 0;
    *(undefined1 *)(piVar7 + 0x27) = 0;
    piVar4[0x28] = 0;
    piVar9 = piVar9 + 4;
    piVar4 = piVar4 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    iVar8 = iVar8 + 1;
  } while (bVar1);
  compileOutput[0x2d] = 0;
  *(undefined1 *)(compileOutput + 0x2b) = 0;
  compileOutput[0x2c] = 0;
  iVar8 = 0x10;
  piVar4 = compileOutput;
  piVar7 = compileOutput;
  do {
    *(undefined1 *)(piVar4 + 0x56e) = 0;
    piVar7[0x572] = 0;
    *(undefined1 *)(piVar4 + 0x582) = 0;
    *(undefined1 *)(piVar4 + 0x586) = 0;
    piVar7[0x7aa] = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    piVar7 = piVar7 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0x30;
  piVar4 = compileOutput;
  piVar7 = compileOutput;
  do {
    *(undefined1 *)(piVar7 + 0x58a) = 0;
    piVar4[0x658] = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  compileOutput[0x788] = 0;
  compileOutput[0x656] = 0;
  compileOutput[0x78a] = 0x100;
  loopIndex = 0;
  piVar4 = compileOutput;
  piVar7 = compileOutput;
  piVar9 = compileOutput;
  do {
    *(undefined1 *)(piVar7 + 0x596) = 0;
    *(undefined1 *)(piVar7 + 0x5d6) = 0;
    loopIndex = loopIndex + 1;
    piVar9[0x688] = 0;
    piVar4[0x6e] = 0;
    piVar4[0x6f] = 0;
    piVar4[0x70] = 0;
    piVar4[0x71] = 0;
    *(undefined1 *)(piVar7 + 0x2e) = 0;
    piVar9 = piVar9 + 1;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4 = piVar4 + 5;
  } while (loopIndex < compileOutput[0x78a]);
  compileOutput[0x7a5] = 0;
  compileOutput[0x657] = 0;
  compileOutput[0x789] = 0;
  *(undefined1 *)(compileOutput + 0x78b) = 0;
  iVar8 = 8;
  *(undefined1 *)((int)compileOutput + 0x1e2d) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e2e) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e2f) = 0;
  *(undefined1 *)(compileOutput + 0x78c) = 0;
  compileOutput[0x7a3] = 0;
  compileOutput[0x7a4] = 0;
  piVar4 = compileOutput;
  piVar7 = compileOutput;
  do {
    *(undefined1 *)((int)piVar7 + 0x1e31) = 0;
    *(undefined1 *)((int)piVar7 + 0x1e39) = 0;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar4[0x793] = 0;
    piVar4[0x79b] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  compileOutput[0x7a9] = 0;
  compileOutput[0x791] = 0;
  compileOutput[0x792] = 0;
  *(undefined1 *)(compileOutput + 0x7a6) = 0;
  iVar8 = 4;
  *(undefined1 *)((int)compileOutput + 0x1e99) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e9a) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e9b) = 0;
  *(undefined1 *)(compileOutput + 0x7a7) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e9d) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e9e) = 0;
  *(undefined1 *)((int)compileOutput + 0x1e9f) = 0;
  *(undefined1 *)(compileOutput + 0x7a8) = 0;
  *(undefined1 *)((int)compileOutput + 0x1ea1) = 0;
  *(undefined1 *)(compileOutput + 0x7ba) = 0;
  compileOutput[0x7bb] = 0;
  compileOutput[0x7bc] = 0;
  compileOutput[0x7bd] = 0;
  piVar4 = compileOutput;
  do {
    *(undefined1 *)(piVar4 + 0x7be) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(compileOutput + 0x7c1) = 0;
  *(undefined1 *)(compileOutput + 0x7bf) = 0;
  *(undefined1 *)((int)compileOutput + 0x1efd) = 0;
  compileOutput[0x7c5] = 0;
  compileOutput[0x7c3] = 0;
  compileOutput[0x7c2] = 1;
  compileOutput[0x7c6] = 0;
  compileOutput[0x7c4] = 0;
  compileOutput[0x7c7] = 0x8000;
  *compileRecord = glContextWord1e5c;
  compileRecord[1] = (int)(((unsigned char *)0x000010ec) + glContextWord1e5c);
  *(undefined4 *)(((unsigned char *)0x000012fc) + glContextWord1e5c) = 0;
  iVar10 = 0x10;
  *(undefined4 *)(((unsigned char *)0x000010e4) + *compileRecord) = 0xffffffff;
  iVar8 = glContextWord1e5c;
  do {
    *(undefined4 *)(((unsigned char *)0x000015d0) + iVar8) = 0;
    ((unsigned char *)0x00001610)[glContextWord1e5c] = 0;
    glContextWord1e5c = glContextWord1e5c + 1;
    *(undefined4 *)(((unsigned char *)0x00001620) + iVar8) = 0;
    iVar8 = iVar8 + 4;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  *(undefined4 *)(((unsigned char *)0x000010e0) + *compileRecord) = 0;
  *(undefined4 *)(((unsigned char *)0x000015cc) + *compileRecord) = 0;
  ((unsigned char *)0x000010e9)[*compileRecord] = 0;
  ((unsigned char *)0x000010ea)[*compileRecord] = 0;
  compileRecord[0x12] = 1;
  compileRecord[0x1a] = 0;
  compileRecord[0x18] = 0;
  compileRecord[0x17] = 0;
  compileRecord[0x19] = 0;
  compileRecord[0x15] = 0;
  compileRecord[0x16] = 0;
  compileRecord[0x13] = 0;
  compileRecord[0x14] = 0;
  piVar4 = compileRecord;
  do {
    piVar4[0x1b] = 0;
    piVar4[0x23] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  iVar10 = 4;
  do {
    iVar2 = iVar8 * 4;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(((unsigned char *)0x000010a8) + iVar2 + *compileRecord) = 0;
    *(undefined4 *)(((unsigned char *)0x00001098) + iVar2 + *compileRecord) = 0;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = 8;
  piVar4 = compileRecord;
  do {
    *(undefined1 *)(piVar4 + 0x2c) = 0;
    piVar4 = (int *)((int)piVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 4;
  compileRecord[0x36] = 0;
  compileRecord[0x3a] = 0;
  compileRecord[0x37] = 0x8000;
  compileRecord[0x2e] = 0x8000;
  compileRecord[0x2f] = 0x8000;
  compileRecord[0x30] = 0x8000;
  compileRecord[0x31] = 0x8000;
  compileRecord[0x32] = 0x8000;
  compileRecord[0x33] = 0x8000;
  compileRecord[0x34] = 0x8000;
  compileRecord[0x35] = 0x8000;
  compileRecord[0x3b] = 0;
  compileRecord[0x3c] = 0;
  compileRecord[0x3d] = 0;
  compileRecord[0x42] = 0;
  piVar4 = compileRecord;
  do {
    piVar4[0x3e] = 0;
    piVar4 = piVar4 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined1 *)(compileRecord + 0x44) = 0;
  *(undefined1 *)(compileRecord + 0x43) = 0;
  *(undefined1 *)((int)compileRecord + 0x10d) = 0;
  *(undefined1 *)((int)compileRecord + 0x10e) = 0;
  *(undefined1 *)((int)compileRecord + 0x10f) = 0;
  compileOutput[2] = *ilSource;
  *(byte *)((int)compileOutput + 0x1f05) = (byte)ilSource[3] & 1;
  *(byte *)((int)compileOutput + 0x1f06) = (byte)ilSource[3] & 2;
  uVar3 = (uint)ilSource[3] >> 2 & 3;
  compileRecord[0x45] = uVar3;
  if (uVar3 != 0) {
    *(undefined1 *)(compileOutput + 0x7a8) = 1;
  }
  if ((ilSource[3] & 0x100U) == 0) {
    *(undefined1 *)(compileRecord + 0x46) = 0;
    compileRecord[1] = (int)(((unsigned char *)0x000010ec) + *compileRecord);
  }
  else {
    *(undefined1 *)(compileRecord + 0x46) = 1;
    compileRecord[1] = (int)(((unsigned char *)0x00001318) + *compileRecord);
  }
  if ((ilSource[3] & 0x400U) == 0) {
    compileRecord[0x47] = 0;
  }
  else {
    compileRecord[0x47] = ilSource[4];
  }
  if ((ilSource[3] & 0x200U) == 0) {
    *(undefined1 *)((int)compileRecord + 0x119) = 0;
  }
  else {
    *(undefined1 *)((int)compileRecord + 0x119) = 1;
  }
  iVar8 = 0;
  iVar10 = 8;
  do {
    local_38[iVar8] = 0;
    iVar8 = iVar8 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar5 = (undefined4 *)FUN_000a6f70(0x48000);
  compileRecord[3] = (int)puVar5;
  _memset(puVar5,0,0x48);
  *(undefined1 *)(puVar5 + 3) = 0;
  *(undefined1 *)((int)puVar5 + 0xd) = 0;
  *(undefined2 *)(puVar5 + 5) = 0;
  *(undefined2 *)((int)puVar5 + 0x22) = 0;
  puVar5[1] = 0x1000;
  *puVar5 = 0;
  puVar5[2] = 0;
  compileRecord[2] = (int)(puVar5 + 0x12);
  iVar8 = FUN_000879f0(glContext,compileOutput,compileRecord,compileRecord[1],puVar5 + 0x12,local_38,0);
  iVar10 = 0;
  compileRecord[2] = iVar8;
  *(undefined1 *)(compileOutput + 0x7c8) = 1;
  iVar8 = 0x10;
  do {
    iVar2 = iVar10 * 0x10;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(iVar2 + compileRecord[1] + 0x108) = 0;
    *(undefined4 *)(iVar2 + compileRecord[1] + 0x10c) = 1;
    *(undefined4 *)(iVar2 + compileRecord[1] + 0x110) = 2;
    *(undefined4 *)(iVar2 + compileRecord[1] + 0x114) = 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (glContext == 0) {
    iVar8 = ilSource[6];
  }
  else {
    if (*(int *)(glContext + 0x186c) == 0) {
      scCreateForContext(glContext,*(undefined4 *)(glContext + 0x2454));
    }
    iVar8 = glContext + 0x186c;
  }
  iVar8 = ilRewriteForTextureState(glContext,compileOutput,compileRecord,ilSource,iVar8);
  if (iVar8 != 0) {
    return 2;
  }
  FUN_000c5e60(compileRecord[3]);
  compileRecordPtrc = compileRecord[3];
  FUN_000c5e60(compileRecordPtrc);
  if ((ilSource[3] & 0x100U) == 0) {
    iVar10 = *compileRecord + 4;
  }
  else {
    iVar10 = *compileRecord + 0x20;
  }
  uVar6 = FUN_000a6f70(((uint)*(ushort *)(compileRecordPtrc + 0x1c) + (uint)*(ushort *)(compileRecordPtrc + 0x1a) +
                       (uint)*(ushort *)(compileRecordPtrc + 0x20)) * 0x18);
  *(undefined4 *)(iVar10 + 0x10) = uVar6;
  iVar8 = FUN_000bfed0(compileRecord[3],compileRecord[1] + 0x44,iVar10);
  if ((ilSource[3] & 0x100U) == 0) {
    *(uint *)(((unsigned char *)0x000036a8) + *compileRecord) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036b0) + *compileRecord) = (*(uint *)(compileRecord[1] + 0x44) & 0xf) + 1;
  }
  else {
    *(uint *)(((unsigned char *)0x000036b4) + *compileRecord) =
         ((*(uint *)(iVar10 + 8) >> 0x10 & 0x1ff) - (*(uint *)(iVar10 + 8) & 0x1ff)) + 1;
    *(uint *)(((unsigned char *)0x000036bc) + *compileRecord) = (*(uint *)(compileRecord[1] + 0x44) & 0xf) + 1;
  }
  ((unsigned char *)0x000036c5)[*compileRecord] = 1;
  _free(compileRecord[3]);
  if (8 < (uint)(((compileOutput[0x791] + compileOutput[0x792]) -
                 ((int)-(uint)*(byte *)((int)compileOutput + 0x1e2e) >> 0x1f)) -
                ((int)-(uint)*(byte *)((int)compileOutput + 0x1e2f) >> 0x1f))) {
    compileOutput[1] = 6;
    return 6;
  }
  if (iVar8 == 0) {
switchD_000b4be8_caseD_80000007:
    uVar6 = 0;
  }
  else {
    switch(iVar8) {
    case -0x7fffffff:
    case -0x7ffffff0:
      uVar6 = 3;
      break;
    case -0x7ffffffe:
    case -0x7fffffee:
      uVar6 = 4;
      break;
    case -0x7ffffffd:
    case -0x7fffffec:
      uVar6 = 6;
      break;
    case -0x7ffffffc:
    case -0x7fffffea:
      uVar6 = 9;
      break;
    case -0x7ffffffb:
    case -0x7fffffeb:
      uVar6 = 10;
      break;
    case -0x7ffffffa:
    case -0x7fffffef:
      uVar6 = 8;
      break;
    default:
      goto switchD_000b4be8_caseD_80000007;
    case -0x7fffffed:
      uVar6 = 5;
      break;
    case -0x7fffffe9:
      uVar6 = 0xb;
      break;
    case -0x7fffffe8:
      uVar6 = 0xc;
    }
  }
  return uVar6;
}

/* gld_decodeProgramInterface @ 0xb4cd0 (608 bytes) */
int gld_decodeProgramInterface(glContext, programObj)
  int glContext;
  int programObj;
{
  undefined4 resultCode;
  uint loopIndex2;
  char *cursor2;
  int remaining2;
  int remaining;
  char outputEnabled;
  int decodeStatus;
  undefined4 inputKindCode;
  uint *cursor3;
  uint cursor3Word0;
  uint loopIndex;
  char *cursor;
  int rangeStart;
  int rangeWords;
  undefined4 rangeReserved0;
  undefined4 rangeReserved1;
  undefined1 decodeInfo [176];
  char outputEnableFlags [116];
  undefined1 decodeBuffer [5560];
  char inputEnableFlags [16];
  uint inputKinds [16];
  char decodeBufferTail [2085];
  undefined1 resultByte0;
  undefined1 resultByte1;
  undefined1 resultByte2;
  undefined1 resultByte4;
  undefined1 resultByte3;
  
  rangeStart = *(int *)(*(int *)(programObj + 0x74) + 0x58) + 10;
  rangeReserved0 = 0;
  rangeReserved1 = 0;
  rangeWords = *(int *)(*(int *)(programObj + 0x74) + 0x5c) + -10 >> 2;
  decodeStatus = ((int (*)())FUN_000b4400)(glContext,decodeBuffer,decodeInfo,&rangeStart,
                       *(undefined4 *)
                        (*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + *(int *)(programObj + 0x70)));
  *(undefined4 *)(*(int *)(programObj + 0x74) + 0xc) = 0;
  *(undefined4 *)(*(int *)(programObj + 0x74) + 0x10) = 0;
  *(undefined1 *)(*(int *)(programObj + 0x74) + 4) = 0;
  **(undefined1 **)(programObj + 0x74) = 0;
  *(undefined1 *)(*(int *)(programObj + 0x74) + 1) = 0;
  *(undefined1 *)(*(int *)(programObj + 0x74) + 2) = 0;
  *(undefined1 *)(*(int *)(programObj + 0x74) + 3) = 0;
  *(undefined1 *)(*(int *)(programObj + 0x74) + 5) = 0;
  *(undefined4 *)(programObj + 0x54) = 0;
  *(undefined4 *)(programObj + 0x58) = 0;
  *(undefined4 *)(programObj + 0x50) = 0;
  *(undefined4 *)(programObj + 0x5c) = 0;
  *(undefined4 *)(programObj + 0x60) = 0;
  *(undefined4 *)(programObj + 100) = 0;
  *(undefined4 *)(programObj + 0x68) = 0;
  if (decodeStatus == 0) {
    loopIndex = 0;
    cursor = outputEnableFlags;
    *(undefined1 *)(*(int *)(programObj + 0x74) + 4) = resultByte4;
    remaining = 8;
    **(undefined1 **)(programObj + 0x74) = resultByte0;
    *(undefined1 *)(*(int *)(programObj + 0x74) + 1) = resultByte1;
    *(undefined1 *)(*(int *)(programObj + 0x74) + 2) = resultByte2;
    *(undefined1 *)(*(int *)(programObj + 0x74) + 3) = resultByte3;
    *(undefined1 *)(*(int *)(programObj + 0x74) + 5) = 0;
    do {
      outputEnabled = *cursor;
      cursor = cursor + 1;
      if (outputEnabled != '\0') {
        *(uint *)(*(int *)(programObj + 0x74) + 0xc) =
             1 << (loopIndex & 0x3f) | *(uint *)(*(int *)(programObj + 0x74) + 0xc);
      }
      loopIndex = loopIndex + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    loopIndex2 = 0;
    cursor2 = inputEnableFlags;
    cursor3 = inputKinds;
    remaining2 = 0x10;
    do {
      if (*cursor2 != '\0') {
        *(uint *)(*(int *)(programObj + 0x74) + 0x10) =
             1 << (loopIndex2 & 0x3f) | *(uint *)(*(int *)(programObj + 0x74) + 0x10);
        cursor3Word0 = *cursor3;
        if (cursor3Word0 == 2) {
          inputKindCode = 5;
          if (cursor2[0x50] == '\0') {
            inputKindCode = 2;
          }
          *(undefined4 *)(loopIndex2 * 4 + *(int *)(programObj + 0x74) + 0x14) = inputKindCode;
        }
        else if (cursor3Word0 < 3) {
          if (cursor3Word0 == 1) {
LAB_000b4ee0:
            *(uint *)(loopIndex2 * 4 + *(int *)(programObj + 0x74) + 0x14) = cursor3Word0;
          }
        }
        else if ((cursor3Word0 == 3) || (cursor3Word0 == 4)) goto LAB_000b4ee0;
      }
      loopIndex2 = loopIndex2 + 1;
      cursor2 = cursor2 + 1;
      cursor3 = cursor3 + 1;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
    resultCode = 1;
    *(undefined1 *)(programObj + 0x6c) = 1;
  }
  else if (decodeStatus == 1) {
    *(undefined1 *)(programObj + 0x6c) = 0;
    resultCode = 0;
  }
  else {
    resultCode = 1;
    *(undefined1 *)(programObj + 0x6c) = 0;
  }
  return resultCode;
}

/* FUN_000b4f50 @ 0xb4f50 (180 bytes) */
void FUN_000b4f50(int param_1,int param_2,undefined4 unusedArgR5,undefined4 unusedArgR6,undefined4 unusedArgR7,undefined4 unusedArgR8,int param_7,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4)
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_7 == 0) {
    uVar2 = ((uint (*)())floatToFp24)(fpPassThrough1);
    iVar1 = param_2 * 0x10 + param_1;
    *(undefined4 *)(iVar1 + 0x8c) = uVar2;
    uVar2 = ((uint (*)())floatToFp24)(fpPassThrough2);
    *(undefined4 *)(iVar1 + 0x90) = uVar2;
    uVar2 = ((uint (*)())floatToFp24)(fpPassThrough3);
    *(undefined4 *)(iVar1 + 0x94) = uVar2;
    uVar2 = ((uint (*)())floatToFp24)(fpPassThrough4);
    *(undefined4 *)(iVar1 + 0x98) = uVar2;
  }
  else {
    iVar1 = param_2 * 0x10 + param_1;
    *(float *)(iVar1 + 0x98) = (float)fpPassThrough4;
    *(float *)(iVar1 + 0x8c) = (float)fpPassThrough1;
    *(float *)(iVar1 + 0x90) = (float)fpPassThrough2;
    *(float *)(iVar1 + 0x94) = (float)fpPassThrough3;
  }
  return;
}

/* FUN_000b5010 @ 0xb5010 (132 bytes) */
void FUN_000b5010(int glContext,int engineState,int *slotRecord,int param_4,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4)
{
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  
  if ((param_4 < 0x100) && (((unsigned char *)0x00001658)[param_4 + engineState] != '\0')) {
    if (*(char *)(param_4 + engineState + 0x1758) == '\0') {
      ((void (*)())FUN_000b4f50)(*slotRecord,*(int *)(param_4 * 4 + engineState + 0x1a20) - *(int *)(engineState + 0x1f1c),
                   slotRecord,param_4,staleArgR7,staleArgR8,*(undefined4 *)(glContext + 0x2454),fpPassThrough1,fpPassThrough2,
                   fpPassThrough3,fpPassThrough4);
      *(undefined4 *)(glContext + 0x1e64) = 0;
      ((unsigned char *)0x000010eb)[*slotRecord] = 0;
    }
  }
  return;
}

/* gld_emitTextureUnitScaleParams @ 0xb50a0 (228 bytes) */
int gld_emitTextureUnitScaleParams(glContext, engineState, slotRecord)
  int glContext;
  int engineState;
  int *slotRecord;
{
  float oneF;
  int *slotRecordCopy;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int boundTexture;
  int loopIndex;
  int unitShadowCursor;
  int unitSlotCursor;
  int unitFlagCursor;
  
  oneF = FLOAT_001aa0e8;
  if (((unsigned char *)0x000013b1)[glContext] != '\0') {
    loopIndex = 0;
    slotRecordCopy = slotRecord;
    unitShadowCursor = glContext;
    unitSlotCursor = engineState;
    unitFlagCursor = engineState;
    do {
      if (((unsigned char *)0x00001618)[unitFlagCursor] != '\0') {
        boundTexture = *(int *)(((unsigned char *)0x000013f8) + unitShadowCursor);
        if (boundTexture != 0) {
          ((void (*)())FUN_000b4f50)(*slotRecord,(*(int *)(unitSlotCursor + 0x1ea8) - *(int *)(engineState + 0x1f1c)) +
                                slotRecord[0x36],slotRecordCopy,staleArgR6,staleArgR7,staleArgR8,
                       *(undefined4 *)(glContext + 0x2454),(double)(oneF / *(float *)(boundTexture + 0x44)),
                       (double)(oneF / *(float *)(boundTexture + 0x48)),(double)*(float *)(boundTexture + 0x50),
                       (double)*(float *)(((unsigned char *)0x00001620) + loopIndex * 4 + *slotRecord));
        }
      }
      loopIndex = loopIndex + 1;
      unitFlagCursor = unitFlagCursor + 1;
      unitShadowCursor = unitShadowCursor + 4;
      unitSlotCursor = unitSlotCursor + 4;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b1)[glContext]);
  }
  return;
}

/* noop_b5190 @ 0xb5190 (4 bytes) */
int noop_b5190()
{
  return;
}

/* gld_emitSlotViewportTransforms @ 0xb51a0 (376 bytes) */
int gld_emitSlotViewportTransforms(glContext, engineState, slotRecord)
  int glContext;
  int engineState;
  undefined4 *slotRecord;
{
  float viewportScaleY;
  float viewportScaleX;
  uint rectWidth;
  uint rectHeight;
  int engine;
  undefined4 *slotRecordCopy;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int engineCaps;
  double fpPassThrough2;
  double fpPassThrough1;
  
  engine = *(int *)(glContext + 4);
  engineCaps = *(int *)(engine + 0x10);
  if (*(char *)(engineState + 0x1e2f) != '\0') {
    rectWidth = *(uint *)(engineCaps + 0x1840);
    viewportScaleY = *(float *)(engine + 0x2a58);
    viewportScaleX = *(float *)(engine + 0x2a54);
    rectHeight = *(uint *)(engineCaps + 0x1844);
    fpPassThrough1 = (double)(viewportScaleX * (float)((double)CONCAT44(0x43300000,
                                                         *(uint *)(engineCaps + 0x1848) ^ 0x80000000) -
                                       4503601774854144.0) * 0.5);
    fpPassThrough2 = (double)(viewportScaleY * (float)((double)CONCAT44(0x43300000,
                                                         *(uint *)(engineCaps + 0x184c) ^ 0x80000000) -
                                       4503601774854144.0) * 0.5);
    slotRecordCopy = slotRecord;
    ((void (*)())FUN_000b4f50)(*slotRecord,slotRecord[0x2e] - *(int *)(engineState + 0x1f1c),slotRecord,staleArgR6,staleArgR7,staleArgR8,
                 *(undefined4 *)(glContext + 0x2454),fpPassThrough1,fpPassThrough2,
                 (double)(float)((*(double *)(engineCaps + 0x1838) - *(double *)(0x00001830 + engineCaps)) *
                                0.5),0.0);
    ((void (*)())FUN_000b4f50)(*slotRecord,slotRecord[0x2f] - *(int *)(engineState + 0x1f1c),slotRecordCopy,staleArgR6,staleArgR7,staleArgR8,
                 *(undefined4 *)(glContext + 0x2454),
                 (double)(float)((double)(viewportScaleX * (float)((double)CONCAT44(0x43300000,
                                                                           rectWidth ^ 0x80000000) -
                                                         4503601774854144.0)) + fpPassThrough1),
                 (double)(float)((double)(viewportScaleY * (float)((double)CONCAT44(0x43300000,
                                                                           rectHeight ^ 0x80000000) -
                                                         4503601774854144.0)) + fpPassThrough2),
                 (double)(float)((*(double *)(engineCaps + 0x1838) + *(double *)(0x00001830 + engineCaps)) *
                                0.5),0.0);
    *(undefined4 *)(glContext + 0x1e64) = 0;
  }
  return;
}

/* gld_emitSlotTransformParams @ 0xb5320 (204 bytes) */
int gld_emitSlotTransformParams(glContext, engineState, slotRecord)
  int glContext;
  int engineState;
  undefined4 *slotRecord;
{
  undefined4 *slotRecordCopy;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int engineCaps;
  
  engineCaps = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (*(char *)(engineState + 0x1ea0) != '\0') {
    slotRecordCopy = slotRecord;
    ((void (*)())FUN_000b4f50)(*slotRecord,slotRecord[0x38] - *(int *)(engineState + 0x1f1c),slotRecord,staleArgR6,staleArgR7,staleArgR8,
                 *(undefined4 *)(glContext + 0x2454),-(double)*(float *)(((unsigned char *)0x00002dfc) + engineCaps),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002dfc) + engineCaps) *
                                (double)*(float *)(((unsigned char *)0x00002df8) + engineCaps)),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + engineCaps) / DOUBLE_001aa268),
                 (double)(float)((double)*(float *)(((unsigned char *)0x00002df0) + engineCaps) / DOUBLE_001aa270));
    ((void (*)())FUN_000b4f50)(*slotRecord,slotRecord[0x39] - *(int *)(engineState + 0x1f1c),slotRecordCopy,staleArgR6,staleArgR7,staleArgR8,
                 *(undefined4 *)(glContext + 0x2454),(double)*(float *)(((unsigned char *)0x00002de0) + engineCaps),
                 (double)*(float *)(((unsigned char *)0x00002de4) + engineCaps),(double)*(float *)(((unsigned char *)0x00002de8) + engineCaps)
                 ,(double)FLOAT_001aa0d4);
    *(undefined4 *)(glContext + 0x1e64) = 0;
  }
  return;
}

/* noop_b53f0 @ 0xb53f0 (4 bytes) */
int noop_b53f0()
{
  return;
}

/* gld_emitProgramStatePackets @ 0xb5400 (928 bytes) */
int gld_emitProgramStatePackets(glContext, programObj)
  int glContext;
  int programObj;
{
  int tableByteOffset;
  int ctxWordCursor;
  int packetStart3;
  int packetStart2;
  uint copyRemaining;
  uint registerHeader;
  int packetEndFixed;
  int packetEnd;
  undefined4 glContextWord1ba0;
  undefined4 glContextWord1b9c;
  undefined4 glContextWord1ca0;
  undefined4 glContextWord1ca4;
  int remaining;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  undefined4 *srcWordPtr;
  uint pairCount;
  uint constStartIndex;
  int packetStart;
  undefined4 *packet;
  uint *pairPacket;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 glContextWord1b94;
  uint *cursor;
  int programState;
  int constCount;
  int constWords;
  uint pairRemaining;
  
  programState = *(int *)(programObj + 0x14);
  constCount = *(int *)(((unsigned char *)0x00004024) + programState);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  constWords = constCount * 4;
  packet[1] = 0;
  *packet = 0x8a1;
  packetStart = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = packetStart + 8;
  (*UNRECOVERED_JUMPTABLE)(glContext,packetStart + 8,staleArgR5,staleArgR6,staleArgR7,staleArgR8,UNRECOVERED_JUMPTABLE);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,6);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = 0x208b4;
  packet[1] = *(undefined4 *)(glContext + 0x1b90);
  packet[2] = *(undefined4 *)(glContext + 0x1b8c);
  glContextWord1b94 = *(undefined4 *)(glContext + 0x1b94);
  packet[4] = 0x820;
  packet[3] = glContextWord1b94;
  packet[5] = *(undefined4 *)(glContext + 0x1b7c);
  packetStart2 = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = packetStart2 + 0x18;
  (*UNRECOVERED_JUMPTABLE)(glContext,packetStart2 + 0x18,staleArgR5,staleArgR6,staleArgR7,staleArgR8,UNRECOVERED_JUMPTABLE);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = 0x8b7;
  packet[1] = *(undefined4 *)(glContext + 0x1b98);
  packetStart3 = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = packetStart3 + 8;
  (*UNRECOVERED_JUMPTABLE)(glContext,packetStart3 + 8,staleArgR5,staleArgR6,staleArgR7,staleArgR8,UNRECOVERED_JUMPTABLE);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,constWords + 3);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = 0x880;
  constStartIndex = *(uint *)(((unsigned char *)0x0000548c) + programState);
  packet[2] = (constWords + -1) * 0x10000 | 0x8882;
  packet[1] = constStartIndex & 0x3ff;
  _memcpy(packet + 3,programState + 0x24,*(int *)(((unsigned char *)0x00004024) + programState) << 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  packetEnd = constCount * 0x10 + *(int *)(0x00002748 + glContext + 4) + 0xc;
  *(int *)(0x00002748 + glContext + 4) = packetEnd;
  (*UNRECOVERED_JUMPTABLE)(glContext,packetEnd);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x15);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = 0x82d;
  remaining = 8;
  glContextWord1ca4 = *(undefined4 *)(glContext + 0x1ca4);
  packet[2] = 0x861;
  packet[1] = glContextWord1ca4;
  glContextWord1ca0 = *(undefined4 *)(glContext + 0x1ca0);
  packet[4] = 0x824;
  packet[3] = glContextWord1ca0;
  glContextWord1b9c = *(undefined4 *)(glContext + 0x1b9c);
  packet[6] = 0x825;
  packet[5] = glContextWord1b9c;
  glContextWord1ba0 = *(undefined4 *)(glContext + 0x1ba0);
  packet[8] = ((unsigned char *)0x000010c0U);
  packet[7] = glContextWord1ba0;
  packet[9] = *(undefined4 *)(glContext + 0x1f2c);
  packet[10] = *(uint *)(glContext + 0x1f28) | 0x70000;
  loopIndex = 0;
  ctxWordCursor = glContext;
  do {
    srcWordPtr = (undefined4 *)(ctxWordCursor + 0x1ee8);
    ctxWordCursor = ctxWordCursor + 4;
    *(undefined4 *)((int)packet + loopIndex + 0x2c) = *srcWordPtr;
    remaining = remaining + -1;
    loopIndex = loopIndex + 4;
  } while (remaining != 0);
  packet[0x13] = ((unsigned char *)0x00001047U);
  packet[0x14] = *(undefined4 *)(glContext + 0x1bb0);
  packetEndFixed = *(int *)(0x00002748 + glContext + 4);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = packetEndFixed + 0x54;
  (*UNRECOVERED_JUMPTABLE)(glContext,packetEndFixed + 0x54);
  if (*(int *)(glContext + 0x243c) != 0) {
    pairCount = *(int *)(glContext + 0x243c) + 1U >> 1;
    pairPacket = (uint *)(**(code **)(glContext + 0x2758))(glContext,pairCount * 2 + 2);
    *(uint **)(0x00002748 + glContext + 4) = pairPacket;
    cursor = pairPacket + 1;
    registerHeader = (pairCount - 1) * 0x10000;
    *pairPacket = registerHeader | 0x854;
    if (pairCount != 0) {
      loopIndex2 = 0;
      pairRemaining = pairCount;
      do {
        tableByteOffset = loopIndex2 * 4;
        loopIndex2 = loopIndex2 + 1;
        *cursor = *(uint *)(tableByteOffset + *(int *)(glContext + 0x2440));
        cursor = cursor + 1;
        pairRemaining = pairRemaining - 1;
      } while (pairRemaining != 0);
    }
    *cursor = registerHeader | 0x878;
    if (pairCount != 0) {
      loopIndex3 = 0;
      copyRemaining = pairCount;
      do {
        *(undefined4 *)((int)cursor + loopIndex3 + 4) =
             *(undefined4 *)(loopIndex3 + *(int *)(glContext + 0x2444));
        loopIndex3 = loopIndex3 + 4;
        copyRemaining = copyRemaining - 1;
      } while (copyRemaining != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    *(uint *)(0x00002748 + glContext + 4) = pairCount * 8 + *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
    return;
  }
  return;
}

/* gld_compileFragmentProgramImage @ 0xb57a0 (688 bytes) */
int gld_compileFragmentProgramImage(ctx, param_2)
  int ctx;
  int param_2;
{
  int allocationPtr4024;
  int allocationWord542c;
  undefined4 *cursor;
  int loopIndex;
  uint ctxWord44;
  uint packedLimitWord;
  int oldMaxConstIndex;
  uint lastTexInstIndex;
  undefined4 *allocation;
  int status;
  uint lastDependentInstIndex;
  undefined4 *instructionCursor;
  int scanIndex;
  int constSlotCursor;
  char *slotFlagCursor;
  
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(param_2 + 0x14));
  }
  allocation = (undefined4 *)(**(code **)(ctx + 0xc))(0x569c);
  *(undefined4 **)(param_2 + 0x14) = allocation;
  allocation[2] = 0;
  status = 0xe;
  *allocation = *(undefined4 *)(param_2 + 0xc);
  allocation[1] = *(undefined4 *)(param_2 + 4);
  allocation[3] = *(undefined4 *)(ctx + 0x2454);
  allocation[4] = *(undefined4 *)(ctx + 0x2454);
  ctxWord44 = *(uint *)(ctx + 0x44);
  allocation[8] = 1;
  allocation[7] = 1;
  allocation[6] = ctxWord44 >> 7 & 1;
  if (*(char *)(ctx + 0x1869) != '\0') {
    instructionCursor = allocation + 9;
    status = ilAssembleProgram(ctx,allocation,instructionCursor);
    if (status == 0) {
      allocationWord542c = allocation[0x150b];
      *(undefined1 *)((int)allocation + 0x5497) = 0;
      allocationPtr4024 = allocation[0x1009];
      *(char *)((int)allocation + 0x5495) = (char)allocationWord542c;
      packedLimitWord = (allocationPtr4024 + -1) * 0x100000 & 0x3ff00000U | allocation[0x1523] & 0xc00ffc00;
      allocation[0x1523] = packedLimitWord;
      if (*(int *)(((unsigned char *)0x00001240) + param_2) < (int)allocation[0x1590]) {
        *(undefined4 *)(((unsigned char *)0x00001240) + param_2) = allocation[0x1590];
        packedLimitWord = allocation[0x1523];
        allocationPtr4024 = allocation[0x1009];
        allocationWord542c = allocation[0x150b];
      }
      lastTexInstIndex = 0;
      scanIndex = allocationPtr4024;
      if (allocationPtr4024 != 0) {
        do {
          lastTexInstIndex = instructionCursor[scanIndex * 4 + -4] & 0xf00;
          if (((lastTexInstIndex == 0x200) || (lastTexInstIndex == 0x300)) && ((instructionCursor[scanIndex * 4 + -4] & 0xfe000) == 0)) {
            lastTexInstIndex = scanIndex - 1;
          }
          else {
            lastTexInstIndex = 0;
          }
        } while ((scanIndex + -1 != 0) && (scanIndex = scanIndex + -1, lastTexInstIndex == 0));
        lastTexInstIndex = lastTexInstIndex & 0xffff;
      }
      lastDependentInstIndex = 0;
      allocation[0x1523] = (lastTexInstIndex & 0x3ff) << 10 | packedLimitWord & 0xfff003ff;
      if (allocationPtr4024 != 0) {
        instructionCursor = instructionCursor + allocationPtr4024 * 4;
        do {
          if ((((instructionCursor[-3] & 7) == 1) || ((instructionCursor[-2] & 7) == 1)) || ((instructionCursor[-1] & 7) == 1)) {
            lastDependentInstIndex = allocationPtr4024 - 1;
          }
          else {
            lastDependentInstIndex = 0;
          }
          allocationPtr4024 = allocationPtr4024 + -1;
        } while ((allocationPtr4024 != 0) && (instructionCursor = instructionCursor + -4, lastDependentInstIndex == 0));
      }
      *(int *)(((unsigned char *)0x00001038) + param_2) = allocationWord542c;
      if (0 < allocationWord542c) {
        slotFlagCursor = (char *)(allocation + 0x100e);
        cursor = allocation + 0x100a;
        loopIndex = 0;
        constSlotCursor = param_2;
        do {
          if (*slotFlagCursor != '\0') {
            oldMaxConstIndex = *(int *)(((unsigned char *)0x00001240) + param_2);
            *(undefined4 *)(constSlotCursor + 0x18) = *cursor;
            *(undefined4 *)(constSlotCursor + 0x1c) = cursor[1];
            *(undefined4 *)(constSlotCursor + 0x20) = cursor[2];
            *(undefined4 *)(constSlotCursor + 0x24) = cursor[3];
            if (oldMaxConstIndex < loopIndex) {
              *(int *)(((unsigned char *)0x00001240) + param_2) = loopIndex;
            }
          }
          loopIndex = loopIndex + 1;
          slotFlagCursor = slotFlagCursor + 0x14;
          cursor = cursor + 5;
          constSlotCursor = constSlotCursor + 0x10;
          allocationWord542c = allocationWord542c + -1;
        } while (allocationWord542c != 0);
      }
      status = 0;
      allocation[0x1524] = lastDependentInstIndex & 0x3ff | allocation[0x1524] & 0xfffffc00;
      *(undefined1 *)(param_2 + 1) = 1;
    }
  }
  return status;
}

/* gld_emitProgramConstants @ 0xb5a60 (244 bytes) */
int gld_emitProgramConstants(glContext, programObj)
  int glContext;
  int programObj;
{
  byte constBaseByte;
  int payloadWords;
  code *glContextPtr275c;
  undefined4 *packet;
  int glContextWord2448;
  int programState;
  int constCount;
  
  programState = *(int *)(programObj + 0x14);
  constCount = *(int *)(((unsigned char *)0x00005428) + programState);
  if (*(int *)(((unsigned char *)0x00001240) + programObj) + 1 < *(int *)(((unsigned char *)0x00005428) + programState)) {
    constCount = *(int *)(((unsigned char *)0x00001240) + programObj) + 1;
  }
  payloadWords = constCount * 4;
  if (payloadWords != 0) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,payloadWords + 5);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x8a1;
    packet[1] = 0;
    packet[2] = 0x880;
    constBaseByte = ((unsigned char *)0x00005497)[programState];
    glContextWord2448 = *(int *)(glContext + 0x2448);
    packet[4] = (payloadWords + -1) * 0x10000 | 0x8882;
    packet[3] = (uint)constBaseByte + glContextWord2448;
    _memcpy(packet + 5,programObj + 0x18,constCount * 0x10);
    glContextPtr275c = *(code **)(glContext + 0x275c);
    constCount = constCount * 0x10 + *(int *)(0x00002748 + glContext + 4) + 0x14;
    *(int *)(0x00002748 + glContext + 4) = constCount;
    (*glContextPtr275c)(glContext,constCount);
  }
  ((unsigned char *)0x00005495)[programState] = (char)*(undefined4 *)(((unsigned char *)0x00001038) + programObj);
  return;
}

/* FUN_000b5b60 @ 0xb5b60 (64 bytes) */
int FUN_000b5b60(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())gld_emitProgramStatePackets)(param_1,param_2);
  ((int (*)())gld_emitProgramConstants)(param_1,param_2);
  return 0;
}

/* FUN_000b5ba0 @ 0xb5ba0 (36 bytes) */
int FUN_000b5ba0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())gld_emitProgramStatePackets)(param_1,param_2);
  return 0;
}

/* FUN_000b5bd0 @ 0xb5bd0 (36 bytes) */
int FUN_000b5bd0(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())gld_emitProgramConstants)(param_1,param_2);
  return 0;
}

/* gld_bindProgramStateAndEmit @ 0xb5c00 (828 bytes) */
int gld_bindProgramStateAndEmit(glContext, programObj, updateArg)
  int glContext;
  uint *programObj;
  undefined4 updateArg;
{
  undefined4 copiedWord;
  uint unitsToScanMasked;
  int unitEnabledCursor;
  int loopIndex;
  int remaining;
  uint glContextWord44;
  uint glContextWord1ca0;
  uint glContextWord8c;
  char glContextByte124;
  byte unitEnableMask;
  uint loopIndex3;
  undefined4 result;
  undefined4 *stateWordCursor;
  uint unitUseBits;
  int engineCaps;
  uint unitsToScan;
  int loopIndex2;
  uint programState;
  int unitShadowCursor;
  
  result = 0;
  if (*(char *)(glContext + 0x3d4) == '\0') {
    glContextByte124 = *(char *)(glContext + 0x124);
    *(uint **)(((unsigned char *)0x0000148c) + glContext) = programObj;
    if ((glContextByte124 == '\0') || ((*(uint *)(glContext + 0x44) & 0x100000) == 0)) {
      *(uint **)(((unsigned char *)0x0000148c) + glContext) = programObj;
    }
    result = 1;
    if (programObj[1] != 0) {
      if ((*programObj & 0xffff00) == 0) {
        ((int (*)())gld_compileFragmentProgramImage)(glContext,programObj);
        if (*(char *)((int)programObj + 1) == '\0') {
          *(undefined1 *)((int)programObj + 2) = 1;
        }
        else {
          *(undefined1 *)((int)programObj + 2) = 0;
        }
      }
      programState = programObj[5];
      loopIndex = 0;
      remaining = 0x16;
      stateWordCursor = (undefined4 *)(((unsigned char *)0x000055e8) + programState);
      do {
        copiedWord = *stateWordCursor;
        stateWordCursor = stateWordCursor + 1;
        *(undefined4 *)(*(int *)(glContext + 0x1864) + loopIndex) = copiedWord;
        loopIndex = loopIndex + 4;
        remaining = remaining + -1;
      } while (remaining != 0);
      *(undefined4 *)(glContext + 0x1b90) = *(undefined4 *)(((unsigned char *)0x0000548c) + programState);
      *(undefined4 *)(glContext + 0x1b94) = *(undefined4 *)(((unsigned char *)0x00005490) + programState);
      *(undefined4 *)(glContext + 0x1b8c) = *(undefined4 *)(((unsigned char *)0x00005494) + programState);
      *(undefined4 *)(glContext + 0x1b98) = *(undefined4 *)(((unsigned char *)0x000054a4) + programState);
      FUN_00050ef0(glContext,updateArg,*(undefined4 *)(((unsigned char *)0x00005434) + programState),
                   *(undefined4 *)(((unsigned char *)0x00005438) + programState));
      glContextWord44 = *(uint *)(glContext + 0x44);
      *(undefined4 *)(glContext + 0x1b9c) = *(undefined4 *)(((unsigned char *)0x00005498) + programState);
      *(undefined4 *)(glContext + 0x1ba0) = *(undefined4 *)(((unsigned char *)0x0000549c) + programState);
      if ((glContextWord44 & 0x100000) == 0) {
        engineCaps = *(int *)(*(int *)(glContext + 4) + 0x10);
        *(undefined4 *)(glContext + 0x1ca0) = 1;
        if ((int)glContextWord44 < 0) {
          unitUseBits = 3;
          *(undefined4 *)(glContext + 0x1ca0) = 3;
          if (((unsigned char *)0x00002d48)[engineCaps + 3] != '\0') {
            unitUseBits = 7;
            *(undefined4 *)(glContext + 0x1ca0) = 7;
          }
        }
        else {
          glContextWord8c = *(uint *)(glContext + 0x8c);
          if (((glContextWord8c >> 0x14 & 1) != 0 || (glContextWord8c >> 0x1a & 1) != 0) || (glContextWord8c >> 0x1b & 1) != 0) {
            *(undefined4 *)(glContext + 0x1ca0) = 3;
          }
          glContextWord1ca0 = *(uint *)(glContext + 0x1ca0);
          unitUseBits = glContextWord1ca0 | 4;
          *(uint *)(glContext + 0x1ca0) = unitUseBits;
          if ((glContextWord44 & 0xa10000) != 0) {
            unitUseBits = glContextWord1ca0 | 0xc;
            *(uint *)(glContext + 0x1ca0) = unitUseBits;
          }
        }
        if (((glContextWord44 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + engineCaps) == -0x7baf)) {
          unitUseBits = unitUseBits | 0x40000;
          *(uint *)(glContext + 0x1ca0) = unitUseBits;
        }
        if (((unsigned char *)0x00004301)[engineCaps] != '\0') {
          unitUseBits = unitUseBits | 0x80000;
          *(uint *)(glContext + 0x1ca0) = unitUseBits;
        }
        if ((glContextWord44 & 0x20000) == 0) {
          unitsToScan = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
          if ((uint)*(byte *)(glContext + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[glContext]) {
            unitsToScan = (uint)*(byte *)(glContext + 0x2b);
          }
          if (unitsToScan != 0) {
            loopIndex2 = 0;
            unitEnabledCursor = glContext;
            unitShadowCursor = glContext;
            do {
              if ((((unsigned char *)0x00001438)[unitEnabledCursor] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + unitShadowCursor) != 0)) {
                unitUseBits = 1 << (loopIndex2 + 10U & 0x3f) | unitUseBits;
                *(uint *)(glContext + 0x1ca0) = unitUseBits;
              }
              loopIndex2 = loopIndex2 + 1;
              unitEnabledCursor = unitEnabledCursor + 1;
              unitShadowCursor = unitShadowCursor + 4;
              unitsToScan = unitsToScan - 1;
            } while (unitsToScan != 0);
          }
        }
        else {
          if ((glContextWord44 & 0x2000) == 0) {
            unitEnableMask = ((unsigned char *)0x00001135)[glContext];
          }
          else {
            unitEnableMask = ((unsigned char *)0x000011d3)[glContext];
          }
          unitsToScanMasked = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
          if (unitsToScanMasked != 0) {
            loopIndex3 = 0;
            if (unitsToScanMasked == 0) {
              unitsToScanMasked = 1;
            }
            do {
              if (((uint)unitEnableMask & 1 << (loopIndex3 & 0x3f)) != 0) {
                unitUseBits = 1 << (loopIndex3 + 10 & 0x3f) | unitUseBits;
                *(uint *)(glContext + 0x1ca0) = unitUseBits;
              }
              loopIndex3 = loopIndex3 + 1;
              unitsToScanMasked = unitsToScanMasked - 1;
            } while (unitsToScanMasked != 0);
          }
        }
        *(uint *)(((unsigned char *)0x00005444) + programState) = unitUseBits;
      }
      (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
      *(undefined4 *)(programState + 0x5650) = *(undefined4 *)(glContext + 0x1ba4);
      *(undefined4 *)(programState + 0x5658) = *(undefined4 *)(glContext + 0x1b50);
      if ((*(char *)(glContext + 0x124) == '\0') && ((*(uint *)(glContext + 0x44) & 0x100000) == 0)) {
        (**(code **)(((unsigned char *)0x00001340) + glContext))(glContext);
        ffvpAssignOutputSlots(glContext);
      }
      ((int (*)())gld_emitProgramStatePackets)(glContext,programObj);
      ((int (*)())gld_emitProgramConstants)(glContext,programObj);
      result = 0;
    }
  }
  return result;
}

/* FUN_000b5f40 @ 0xb5f40 (100 bytes) */
int FUN_000b5f40(unusedArgR3, param_2)
  undefined4 unusedArgR3;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x5648) != 0) {
      ilFreeRecordList(*(int *)(iVar1 + 0x5648));
      iVar1 = *(int *)(param_2 + 0x14);
    }
    _free(iVar1);
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  return 0;
}

/* FUN_000b5fb0 @ 0xb5fb0 (100 bytes) */
int FUN_000b5fb0(glContext)
  int glContext;
{
  code *glContextPtr1224;
  int iVar2;
  int iVar3;

  iVar2 = glContext;
  do {
    /* issue #79: the stock loads the slot's object into r4 (`lwz r4,0x1448(r30)`) BEFORE the
     * `beq` that skips an empty slot, so the `bctrl` at 0xb5ff0 sits in a different basic block
     * from the load of its second argument and the indirect-call argument count (1) missed it.
     * The destroy callback (FUN_00087cd0) is (ctx, obj): the rebuilt code destroyed whatever
     * garbage was in r4 - the bad free(0x24) here and #74's 0x84c1 / 0x110001. */
    iVar3 = *(int *)(((unsigned char *)0x00001448) + iVar2);
    if (iVar3 != 0) {
      glContextPtr1224 = *(code **)(((unsigned char *)0x00001224) + glContext);
      *(undefined4 *)(((unsigned char *)0x00001448) + iVar2) = 0;
      ((int (*)())glContextPtr1224)(glContext,iVar3);
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 != glContext + 0x10);
  return;
}

/* gld_buildUnitSetupCmdList @ 0xb6020 (1360 bytes) */
int gld_buildUnitSetupCmdList(glContext, variant, unitMask)
  int glContext;
  int variant;
  uint unitMask;
{
  undefined4 unitOpcodeWord;
  undefined4 allocation8;
  undefined4 allocation7;
  undefined4 allocation5;
  undefined4 allocation4;
  undefined4 allocation3;
  undefined4 allocation2;
  int allocation;
  bool notLastUnit;
  uint cmdCount;
  undefined4 cmdListOwnerArg;
  int cmdList;
  undefined4 allocation6;
  uint unitSelectWord;
  int cmdListSlotBase;
  code *glContextPtr10;
  uint *cmdCountPtr;
  uint loopIndex;
  
  cmdListSlotBase = unitMask * 4 + glContext;
  if (*(int *)(((unsigned char *)0x00001448) + cmdListSlotBase) == 0) {
    glContextPtr10 = *(code **)(glContext + 0x10);
    cmdListOwnerArg = (**(code **)(((unsigned char *)0x00001284) + glContext))(glContext);
    cmdList = (*glContextPtr10)(1,cmdListOwnerArg);
    cmdCountPtr = (uint *)(cmdList + 4);
    *(int *)(((unsigned char *)0x00001448) + cmdListSlotBase) = cmdList;
    *(undefined4 *)(cmdList + 4) = 0;
    *(undefined4 *)(cmdList + 0xc) = 0;
    *(undefined4 *)(cmdList + 8) = 0;
    allocation = (**(code **)(glContext + 0xc))(0x200);
    if (*(int *)(cmdList + 0xc) != 0) {
      _memcpy(allocation,*(int *)(cmdList + 0xc),*(int *)(cmdList + 4) << 2);
      (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
    }
    *(int *)(cmdList + 0xc) = allocation;
    *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
    *(undefined4 *)(*(int *)(cmdList + 4) * 4 + allocation) = 1;
    cmdCount = *(int *)(cmdList + 4) + 1;
    *(uint *)(cmdList + 4) = cmdCount;
    if (*(uint *)(cmdList + 8) <= cmdCount) {
      allocation2 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
      if (*(int *)(cmdList + 0xc) != 0) {
        _memcpy(allocation2,*(int *)(cmdList + 0xc),*(int *)(cmdList + 4) << 2);
        (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
      }
      *(undefined4 *)(cmdList + 0xc) = allocation2;
      *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
    }
    *(undefined4 *)(*cmdCountPtr * 4 + *(int *)(cmdList + 0xc)) = 0x10200;
    cmdCount = *cmdCountPtr + 1;
    *cmdCountPtr = cmdCount;
    if (*(uint *)(cmdList + 8) <= cmdCount) {
      allocation3 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
      if (*(int *)(cmdList + 0xc) != 0) {
        _memcpy(allocation3,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
        (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
      }
      *(undefined4 *)(cmdList + 0xc) = allocation3;
      cmdCount = *cmdCountPtr;
      *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
    }
    *(undefined4 *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = 0x1ff0016;
    cmdCount = *cmdCountPtr + 1;
    *cmdCountPtr = cmdCount;
    if (*(uint *)(cmdList + 8) <= cmdCount) {
      allocation4 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
      if (*(int *)(cmdList + 0xc) != 0) {
        _memcpy(allocation4,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
        (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
      }
      *(undefined4 *)(cmdList + 0xc) = allocation4;
      cmdCount = *cmdCountPtr;
      *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
    }
    *(undefined4 *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = 0x120000;
    cmdCount = *cmdCountPtr + 1;
    *cmdCountPtr = cmdCount;
    if (variant == 0) {
      unitOpcodeWord = 0x47;
    }
    else {
      unitOpcodeWord = 0xe;
    }
    loopIndex = 0;
    unitSelectWord = 0x170000;
    do {
      if ((unitMask & 1 << (loopIndex & 0x3f)) != 0) {
        unitSelectWord = loopIndex & 0xffff | unitSelectWord & 0xffff0000;
        if (*(uint *)(cmdList + 8) <= cmdCount) {
          allocation6 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
          if (*(int *)(cmdList + 0xc) != 0) {
            _memcpy(allocation6,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
          }
          *(undefined4 *)(cmdList + 0xc) = allocation6;
          cmdCount = *cmdCountPtr;
          *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
        }
        *(undefined4 *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = unitOpcodeWord;
        cmdCount = *cmdCountPtr + 1;
        *cmdCountPtr = cmdCount;
        if (*(uint *)(cmdList + 8) <= cmdCount) {
          allocation7 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
          if (*(int *)(cmdList + 0xc) != 0) {
            _memcpy(allocation7,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
          }
          *(undefined4 *)(cmdList + 0xc) = allocation7;
          cmdCount = *cmdCountPtr;
          *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
        }
        *(uint *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = unitSelectWord;
        cmdCount = *cmdCountPtr + 1;
        *cmdCountPtr = cmdCount;
        if (*(uint *)(cmdList + 8) <= cmdCount) {
          allocation8 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
          if (*(int *)(cmdList + 0xc) != 0) {
            _memcpy(allocation8,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
          }
          *(undefined4 *)(cmdList + 0xc) = allocation8;
          cmdCount = *cmdCountPtr;
          *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
        }
        *(undefined4 *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = 0x120000;
        cmdCount = *cmdCountPtr + 1;
        *cmdCountPtr = cmdCount;
      }
      notLastUnit = loopIndex != 3;
      loopIndex = loopIndex + 1;
    } while (notLastUnit);
    if (*(uint *)(cmdList + 8) <= cmdCount) {
      allocation5 = (**(code **)(glContext + 0xc))(*(uint *)(cmdList + 8) * 4 + 0x200);
      if (*(int *)(cmdList + 0xc) != 0) {
        _memcpy(allocation5,*(int *)(cmdList + 0xc),*cmdCountPtr << 2);
        (**(code **)(glContext + 0x18))(*(undefined4 *)(cmdList + 0xc));
      }
      *(undefined4 *)(cmdList + 0xc) = allocation5;
      cmdCount = *cmdCountPtr;
      *(int *)(cmdList + 8) = *(int *)(cmdList + 8) + 0x80;
    }
    *(undefined4 *)(cmdCount * 4 + *(int *)(cmdList + 0xc)) = 0x28;
    *cmdCountPtr = *cmdCountPtr + 1;
                    
                    
    (**(code **)(((unsigned char *)0x00001288) + glContext))(glContext,0,cmdList,cmdCountPtr);
    return;
  }
  return;
}

/* FUN_000b6580 @ 0xb6580 (2448 bytes) */
int FUN_000b6580(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined4 allocation6;
  undefined4 allocation5;
  undefined4 allocation4;
  undefined4 allocation3;
  undefined4 allocation2;
  int allocation;
  int remaining2;
  int remaining;
  int loopIndex3;
  int loopIndex2;
  uint glContextWord44;
  uint glContextWord18a4;
  int glContextWord1e5c_4;
  int glContextWord1e5c_3;
  int glContextPtr1e5c_3;
  int glContextPtr1e5c_2;
  int glContextWord1e5c_2;
  int glContextPtr1e5c;
  int glContextWord1e5c;
  int glContextWord245c;
  uint loopIndex;
  bool bVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int r4AfterCall;
  undefined4 r4AfterCall2;
  undefined4 r4AfterCall3;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  int iVar10;
  undefined4 staleArgR8;
  int iVar11;
  uint uVar12;
  short *psVar13;
  uint *puVar14;
  uint loopIndex4;
  undefined8 uVar16;
  /* local_68/local_64/local_60/local_5c/local_58/local_54/local_50 are one contiguous 7-word
   * array - &local_68 is passed to FUN_000b4400, which internally indexes it param_4[0]..param_4[6],
   * and that same pointer flows straight through into ilRewriteForTextureState as its own param_4, where
   * param_4[0] is a buffer pointer and param_4[1] seeds a command-stream token-count loop bound
   * (confirmed live: ilRewriteForTextureState read local_64's slot as heap-garbage, not the value this function
   * just stored, because the two locals landed non-adjacent at -O0). This is the exact same defect,
   * same call chain (X -> FUN_000b4400 -> ilRewriteForTextureState's param_4[0]/param_4[1]), already fixed once
   * for FUN_00087e80's own local_48 (part_012.c, issue #64) - declared as 7 separate scalars, they
   * are not guaranteed contiguous by the compiler, only by the caller's own struct convention.
   * Merged into a real array, aliased back to the original names so the rest of this function's
   * logic is unchanged (issue #64). */
  undefined4 local_68_arr[7];
#define local_68 local_68_arr[0]
#define local_64 local_68_arr[1]
#define local_60 local_68_arr[2]
#define local_5c local_68_arr[3]
#define local_58 local_68_arr[4]
#define local_54 local_68_arr[5]
#define local_50 local_68_arr[6]
  
  bVar1 = param_2 == 0;
  iVar11 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (bVar1) {
    uVar16 = FUN_0004bbf0(glContext);
    param_2 = (int)uVar16;
    if ((int)((ulonglong)uVar16 >> 0x20) == 0) goto LAB_000b66b8;
    glContextWord1e5c_2 = *(int *)(glContext + 0x1e5c);
    if ((*(int *)(((unsigned char *)0x000036c0) + glContextWord1e5c_2) == 0) ||
       (*(int *)(((unsigned char *)0x00001488) + glContext) != *(int *)(((unsigned char *)0x000036c0) + glContextWord1e5c_2))) {
      if (*(char *)(glContext + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,0);
      }
      FUN_0004ac90(glContext);
      glContextPtr1e5c_2 = *(int *)(glContext + 0x1e5c);
      if (*(int *)(((unsigned char *)0x000036c0) + glContextPtr1e5c_2) == 0) {
        *(undefined4 *)(((unsigned char *)0x00001488) + glContext) = 0;
      }
      else {
        *(int *)(((unsigned char *)0x00001488) + glContext) = *(int *)(((unsigned char *)0x000036c0) + glContextPtr1e5c_2);
      }
      ((unsigned char *)0x000010eb)[glContextPtr1e5c_2] = 0;
      *(undefined4 *)(((unsigned char *)0x00001300) + *(int *)(glContext + 0x1e5c)) = 0;
      **(undefined4 **)(glContext + 0x1e5c) = 0;
      glContextWord1e5c_2 = *(int *)(glContext + 0x1e5c);
      param_2 = r4AfterCall;
    }
    *(undefined4 *)(((unsigned char *)0x000010e4) + glContextWord1e5c_2) = 0xffffffff;
    if (*(int *)(glContext + 0x23e0) == 0) {
      return;
    }
    glContextPtr1e5c_3 = *(int *)(glContext + 0x1e5c);
    if (((unsigned char *)0x000036c4)[glContextPtr1e5c_3] != '\0') {
      ((unsigned char *)0x000010eb)[glContextPtr1e5c_3] = 0;
      *(undefined4 *)(((unsigned char *)0x0000152c) + *(int *)(glContext + 0x1e5c)) = 0;
      *(undefined4 *)(*(int *)(glContext + 0x1e5c) + 0x1c) = 0;
      return;
    }
    bVar1 = false;
  }
  else {
    glContextPtr1e5c_3 = *(int *)(glContext + 0x1e5c);
  }
  ((unsigned char *)0x000036c4)[glContextPtr1e5c_3] = 1;
  *(undefined4 *)(*(int *)(glContext + 0x1e5c) + 0x1c) = 0;
LAB_000b66b8:
  glContextWord1e5c_3 = *(int *)(glContext + 0x1e5c);
  *(undefined4 *)(((unsigned char *)0x000010e4) + glContextWord1e5c_3) = 0xffffffff;
  puVar7 = (undefined1 *)
           (**(code **)(glContext + 0xc))(((unsigned char *)0x00003880U),param_2,staleArgR5,staleArgR6,staleArgR7,staleArgR8,glContextWord1e5c_3);
  glContextWord1e5c_4 = *(int *)(glContext + 0x1e5c);
  uVar9 = r4AfterCall2;
  if (*(int *)(((unsigned char *)0x000036c0) + glContextWord1e5c_4) != 0) {
    iVar8 = *(int *)(*(int *)(((unsigned char *)0x000036c0) + glContextWord1e5c_4) + 0xc);
    if (iVar8 != 0) {
      _free(iVar8);
      *(undefined4 *)(*(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c)) + 0xc) = 0;
      glContextWord1e5c_4 = *(int *)(glContext + 0x1e5c);
    }
    _free(*(undefined4 *)(((unsigned char *)0x000036c0) + glContextWord1e5c_4));
    glContextWord1e5c_4 = *(int *)(glContext + 0x1e5c);
    uVar9 = r4AfterCall3;
  }
  *(undefined1 **)(((unsigned char *)0x000036c0) + glContextWord1e5c_4) = puVar7;
  puVar14 = (uint *)(puVar7 + 4);
  **(undefined4 **)(glContext + 0x1e5c) = 0;
  *puVar7 = 0;
  glContextWord18a4 = *(uint *)(glContext + 0x18a4);
  *(undefined4 *)(puVar7 + 4) = 0;
  *(uint *)(puVar7 + 0x1668) = glContextWord18a4 & 0x3fffc0 | *(uint *)(puVar7 + 0x1668) & 0xffc0003f;
  *(undefined4 *)(puVar7 + 0xc) = 0;
  *(undefined4 *)(puVar7 + 8) = 0;
  allocation = (**(code **)(glContext + 0xc))(0x200,uVar9,staleArgR5,staleArgR6,staleArgR7,staleArgR8,0);
  if (*(int *)(puVar7 + 0xc) != 0) {
    _memcpy(allocation,*(int *)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
    (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
  }
  *(int *)(puVar7 + 0xc) = allocation;
  *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  *(undefined4 *)(*(int *)(puVar7 + 4) * 4 + allocation) = 1;
  iVar4 = *(int *)(puVar7 + 4);
  *(uint *)(puVar7 + 4) = iVar4 + 1U;
  if (*(uint *)(puVar7 + 8) <= iVar4 + 1U) {
    allocation2 = (**(code **)(glContext + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(int *)(puVar7 + 0xc) != 0) {
      _memcpy(allocation2,*(int *)(puVar7 + 0xc),*(int *)(puVar7 + 4) << 2);
      (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(undefined4 *)(puVar7 + 0xc) = allocation2;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  loopIndex2 = 0;
  *(undefined4 *)(*puVar14 * 4 + *(int *)(puVar7 + 0xc)) = 0x10200;
  remaining = 0x14;
  *puVar14 = *puVar14 + 1;
  do {
    iVar6 = loopIndex2 + *(int *)(glContext + 0x1e5c);
    loopIndex2 = loopIndex2 + 1;
    ((unsigned char *)0x00002ddc)[iVar6] = 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  uVar5 = (uint)*(byte *)(glContext + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[glContext] < (uint)*(byte *)(glContext + 0x2b)) {
    uVar5 = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  }
  ffpsEmitDeclarations(glContext,puVar7);
  FUN_000d8450(glContext,puVar7,0);
  iVar4 = *(int *)(puVar7 + 4);
  if (uVar5 == 0) {
    uVar9 = 1;
    uVar12 = 0;
  }
  else {
    loopIndex = 0;
    uVar9 = 1;
    uVar12 = 0;
    psVar13 = (short *)(glContext + 0x454);
    iVar8 = glContext;
    iVar6 = glContext;
    do {
      iVar10 = *(int *)(((unsigned char *)0x000013f8) + iVar6);
      if (iVar10 != 0) {
        if (*(ushort *)(iVar8 + 0x450) == 0x8570) {
          if (*psVar13 != -0x7885) {
            ffpsEmitTexEnvCombine(glContext,puVar7,(uint)*(ushort *)(iVar10 + 0x38),loopIndex,iVar10,uVar9,uVar12)
            ;
            uVar9 = 0;
            uVar12 = loopIndex;
          }
        }
        else {
          ffpsEmitTexEnvLegacy(glContext,puVar7,(uint)*(ushort *)(iVar10 + 0x38),
                       (uint)*(ushort *)(iVar8 + 0x450),loopIndex,iVar10,uVar9,uVar12);
          uVar9 = 0;
          uVar12 = loopIndex;
        }
      }
      loopIndex = loopIndex + 1;
      psVar13 = psVar13 + 0x66;
      iVar6 = iVar6 + 4;
      iVar8 = iVar8 + 0xcc;
    } while (uVar5 != loopIndex);
  }
  glContextWord44 = *(uint *)(glContext + 0x44);
  if ((glContextWord44 & 0x100000) == 0) {
    if ((((int)glContextWord44 < 0) &&
        (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(glContext + 4) + 0x10)) == -0x7e06)) ||
       (bVar2 = false, (glContextWord44 & 0x80800000) == 0x800000)) {
      bVar2 = true;
    }
  }
  else if (((glContextWord44 & 0x800000) == 0) ||
          (bVar2 = true, *(char *)(*(int *)(((unsigned char *)0x00001168) + glContext) + 0x6e) == '\0')) {
    bVar2 = false;
  }
  if ((bVar2) || ((glContextWord44 & 0x200000) != 0)) {
    FUN_000d55c0(glContext,puVar14,uVar9,uVar12);
  }
  if (iVar4 == *(int *)(puVar7 + 4)) {
    uVar5 = *puVar14;
    uVar12 = 0x170000;
    loopIndex4 = 0;
    do {
      if (((int)(*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff) >> (loopIndex4 & 0x3f) & 1U) != 0) {
        uVar12 = loopIndex4 & 0xffff | uVar12 & 0xffff0000;
        if (*(uint *)(puVar7 + 8) <= uVar5) {
          allocation3 = (**(code **)(glContext + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(int *)(puVar7 + 0xc) != 0) {
            _memcpy(allocation3,*(int *)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(undefined4 *)(puVar7 + 0xc) = allocation3;
          uVar5 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar5 * 4 + *(int *)(puVar7 + 0xc)) = 0x47;
        uVar5 = *puVar14 + 1;
        *puVar14 = uVar5;
        if (*(uint *)(puVar7 + 8) <= uVar5) {
          allocation4 = (**(code **)(glContext + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(int *)(puVar7 + 0xc) != 0) {
            _memcpy(allocation4,*(int *)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(undefined4 *)(puVar7 + 0xc) = allocation4;
          uVar5 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(puVar7 + 0xc)) = uVar12;
        uVar5 = *puVar14 + 1;
        *puVar14 = uVar5;
        if (*(uint *)(puVar7 + 8) <= uVar5) {
          allocation5 = (**(code **)(glContext + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
          if (*(int *)(puVar7 + 0xc) != 0) {
            _memcpy(allocation5,*(int *)(puVar7 + 0xc),*puVar14 << 2);
            (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
          }
          *(undefined4 *)(puVar7 + 0xc) = allocation5;
          uVar5 = *puVar14;
          *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
        }
        *(undefined4 *)(uVar5 * 4 + *(int *)(puVar7 + 0xc)) = 0x120000;
        uVar5 = *puVar14 + 1;
        *puVar14 = uVar5;
      }
      bVar2 = loopIndex4 != 3;
      loopIndex4 = loopIndex4 + 1;
    } while (bVar2);
  }
  else {
    FUN_000d5390(glContext,puVar14,0,uVar12,*(uint *)(puVar7 + 0x1668) >> 6 & 0xffff);
    uVar5 = *puVar14;
  }
  if (*(uint *)(puVar7 + 8) <= uVar5) {
    allocation6 = (**(code **)(glContext + 0xc))(*(uint *)(puVar7 + 8) * 4 + 0x200);
    if (*(int *)(puVar7 + 0xc) != 0) {
      _memcpy(allocation6,*(int *)(puVar7 + 0xc),*puVar14 << 2);
      (**(code **)(glContext + 0x18))(*(undefined4 *)(puVar7 + 0xc));
    }
    *(undefined4 *)(puVar7 + 0xc) = allocation6;
    uVar5 = *puVar14;
    *(int *)(puVar7 + 8) = *(int *)(puVar7 + 8) + 0x80;
  }
  *(undefined4 *)(uVar5 * 4 + *(int *)(puVar7 + 0xc)) = 0x28;
  *puVar14 = *puVar14 + 1;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = *(undefined4 *)(puVar7 + 0xc);
  local_64 = *(undefined4 *)(puVar7 + 4);
  local_5c = 0x83;
  local_54 = 2;
  _memset(((unsigned char *)0x00002fdcU) + *(int *)(glContext + 0x1e5c),0,0x100);
  loopIndex3 = 0;
  remaining2 = 0x14;
  do {
    iVar6 = loopIndex3 + *(int *)(glContext + 0x1e5c);
    loopIndex3 = loopIndex3 + 1;
    ((unsigned char *)0x00002fdc)[iVar6] = 1;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  *(undefined4 *)(*(int *)(glContext + 0x1e5c) + 0x1780) = 0;
  if (!bVar1) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(glContext + 0x1e5c)) = *(undefined4 *)(glContext + 0x276c);
    local_5c = local_5c | 0x100;
  }
  if (*(char *)(glContext + 0x121) != '\0') {
    sVar3 = *(short *)(((unsigned char *)0x00002e04) + iVar11);
    if (sVar3 == 0x801) {
      local_5c = local_5c | 0xc;
    }
    else if (sVar3 == 0x2601) {
      local_5c = local_5c | 4;
    }
    else if (sVar3 == 0x800) {
      local_5c = local_5c | 8;
    }
  }
  glContextWord245c = *(int *)(glContext + 0x245c);
  if (glContextWord245c != 0) {
    local_58 = 0;
    do {
      local_58 = local_58 << 1 | 1;
      glContextWord245c = glContextWord245c + -1;
    } while (glContextWord245c != 0);
    local_5c = local_5c | 0x400;
  }
  *(undefined4 *)(((unsigned char *)0x000010d8) + *(int *)(glContext + 0x1e5c)) = 0xff;
  glContextWord1e5c = *(int *)(glContext + 0x1e5c);
  ((int (*)())FUN_000b4400)(glContext,glContextWord1e5c + 0x1784,((unsigned char *)0x00001660) + glContextWord1e5c,&local_68,glContextWord1e5c);
  (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,0);
  if ((bVar1) && (*(int *)(glContext + 0x23e0) != 0)) {
    *(undefined4 *)(((unsigned char *)0x0000170c) + *(int *)(glContext + 0x1e5c)) = *(undefined4 *)(glContext + 0x276c);
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    local_5c = local_5c | 0x100;
    ((int (*)())FUN_000b4400)(glContext,glContextWord1e5c + 0x1784,((unsigned char *)0x00001660) + glContextWord1e5c,&local_68,glContextWord1e5c);
    if (*(char *)(glContext + 0x1868) == '\0') {
      (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,0);
    }
  }
  if (*(char *)(glContext + 0x121) != '\0') {
    glContextPtr1e5c = *(int *)(glContext + 0x1e5c);
    *(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + glContextPtr1e5c)) =
         *(int *)(glContextPtr1e5c + 0x1744) - *(int *)(((unsigned char *)0x000036a0) + glContextPtr1e5c);
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    *(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + glContextWord1e5c)) =
         *(int *)(0x00001740 + glContextWord1e5c) - *(int *)(((unsigned char *)0x000036a0) + glContextWord1e5c);
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))) +
     *(int *)(glContext + 0x1e5c)] = 1;
    ((unsigned char *)0x00002ddc)[*(int *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))) +
     *(int *)(glContext + 0x1e5c)] = 1;
  }
  ((int (*)())noop_b5190)(glContext,*(int *)(glContext + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(glContext + 0x1e5c));
  *(undefined1 **)(((unsigned char *)0x00001488) + glContext) = puVar7;
  FUN_0004ac90(glContext);
  return;
}
#undef local_68
#undef local_64
#undef local_60
#undef local_5c
#undef local_58
#undef local_54
#undef local_50

/* gld_updateUnitBiasRegisters @ 0xb6f20 (928 bytes) */
double gld_updateUnitBiasRegisters(int glContext,int texObject,int loopIndex,int updateMode,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double fpPassThrough9)
{
  double scaledBiasField17;
  double scaledBiasD;
  int unitRegAddrFinal;
  uint field23Bits;
  uint field17Bits;
  uint field15Bits;
  float scaledBias;
  float extentDiff;
  float texObjectBias;
  float unitBias;
  int unitWordOffset;
  double unsignedConvLimit;
  uint modeBits13;
  uint field21Count;
  uint unitWord1cdc;
  int unitRegAddr;
  int glContextPtr4;
  double biasBase;
  double intConvBias;
  double combinedBias;
  double ratioA;
  
  intConvBias = DOUBLE_001aa1e0;
  if (updateMode == 0) {
    return;
  }
  unitWordOffset = loopIndex * 4;
  texObjectBias = *(float *)(texObject + 0x4c);
  unitRegAddr = unitWordOffset + glContext;
  unitWord1cdc = *(uint *)(unitRegAddr + 0x1cdc);
  glContextPtr4 = *(int *)(glContext + 4);
  unitBias = *(float *)(loopIndex * 0xcc + glContext + 0x470);
  biasBase = (double)FLOAT_001aa0d4;
  *(uint *)(unitRegAddr + 0x1d1c) = *(uint *)(unitRegAddr + 0x1d1c) & 0xa0705fff | 0x20100000;
  unsignedConvLimit = DOUBLE_001aa1e8;
  modeBits13 = unitWord1cdc >> 0xd & 3;
  field21Count = 1 << (unitWord1cdc >> 0x15 & 7);
  combinedBias = (double)(float)((double)(texObjectBias + unitBias) + biasBase);
  ratioA = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(glContextPtr4 + 0x15c) ^ 0x80000000) -
                           intConvBias) / FLOAT_001aa1b4);
  intConvBias = (double)((float)((double)CONCAT44(0x43300000,*(uint *)(glContextPtr4 + 0x160) ^ 0x80000000) -
                           intConvBias) / FLOAT_001aa1b8);
  extentDiff = (float)(ratioA - intConvBias);
  if (extentDiff < 0.0) {
    intConvBias = ratioA;
  }
  if (-extentDiff < 0.0) {
    ratioA = intConvBias;
  }
  scaledBias = (float)((double)(float)(ratioA * combinedBias) * (double)FLOAT_001aa1a8 + ratioA);
  if (modeBits13 == 2) {
    biasBase = (double)(scaledBias * FLOAT_001aa1ac);
  }
  if (updateMode != 1) {
    return;
  }
  if ((unitWord1cdc >> 0xb & 3) == 3) {
    if (3 < field21Count) {
      field15Bits = 3;
      scaledBiasD = (double)(float)(biasBase * (double)FLOAT_001aa128);
      if ((scaledBiasD <= (double)FLOAT_001aa158) && (field15Bits = 0, (double)FLOAT_001aa0d4 <= scaledBiasD)) {
        if (DOUBLE_001aa1e8 <= scaledBiasD) {
          field15Bits = (int)(scaledBiasD - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          field15Bits = (uint)(int)(biasBase * (double)FLOAT_001aa128);
        }
      }
      if (((modeBits13 == 0) && ((unitWord1cdc >> 9 & 3) == 2)) &&
         (scaledBiasD = (double)FLOAT_001aa0d4, combinedBias == scaledBiasD)) {
        field17Bits = 0;
      }
      else {
        scaledBiasField17 = (double)(scaledBias * FLOAT_001aa1bc);
        scaledBiasD = (double)(scaledBias * FLOAT_001aa1b0 * FLOAT_001aa0f8);
        if (DOUBLE_001aa1e8 <= scaledBiasField17) {
          field17Bits = (int)(scaledBiasField17 - DOUBLE_001aa1e8) + 0x80000000;
        }
        else {
          field17Bits = (uint)(int)(scaledBias * FLOAT_001aa1bc);
        }
      }
      goto LAB_000b7220;
    }
    if (DOUBLE_001aa1e8 <= biasBase) {
      field15Bits = (int)(biasBase - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      field15Bits = (uint)(int)biasBase;
    }
  }
  else if (DOUBLE_001aa1e8 <= biasBase) {
    field15Bits = (int)(biasBase - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    field15Bits = (uint)(int)biasBase;
  }
  field17Bits = 0;
  scaledBiasD = (double)FLOAT_001aa0d4;
LAB_000b7220:
  unitRegAddrFinal = unitWordOffset + glContext;
  *(uint *)(unitRegAddrFinal + 0x1cdc) =
       (*(uint *)(&DAT_001dbf2c + field21Count * 4) & 7) << 0x15 | *(uint *)(unitRegAddrFinal + 0x1cdc) & 0xff1fffff;
  *(uint *)(unitRegAddrFinal + 0x1d1c) = (field15Bits & 3) << 0xf | *(uint *)(unitRegAddrFinal + 0x1d1c) & 0xfffe7fff;
  if (unsignedConvLimit <= scaledBiasD) {
    field23Bits = (int)(scaledBiasD - unsignedConvLimit) + 0x80000000;
  }
  else {
    field23Bits = (uint)(int)scaledBiasD;
  }
  *(uint *)(unitRegAddrFinal + 0x1d1c) = (field23Bits & 0x3f) << 0x17 | *(uint *)(unitRegAddrFinal + 0x1d1c) & 0xe07fffff;
  *(uint *)(unitWordOffset + glContext + 0x1d1c) =
       (field17Bits & 7) << 0x11 | *(uint *)(unitWordOffset + glContext + 0x1d1c) & 0xfff1ffff;
  return;
}

/* extvsInstReadsTempComponents @ 0xb72d0 (11108 bytes) */
int extvsInstReadsTempComponents(symbolTable, inst, tempIndex, outReadsX, outReadsY, outReadsZ, outReadsW)
  undefined4 symbolTable;
  undefined4 *inst;
  int tempIndex;
  undefined1 *outReadsX;
  undefined1 *outReadsY;
  undefined1 *outReadsZ;
  undefined1 *outReadsW;
{
  int swizzleSelect;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char destEnableX;
  char destEnableY;
  char destEnableZ;
  char destEnableW;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  undefined1 readFlag;
  int operandDataType;
  
  destEnableX = *(char *)((int)inst + 0xf);
  destEnableY = *(char *)((int)inst + 0x13);
  destEnableZ = *(char *)((int)inst + 0x17);
  destEnableW = *(char *)((int)inst + 0x1b);
  switch(*inst) {
  case 0x8782:
  case 0x8791:
  case 0x8792:
  case 0x8793:
  case 0x8794:
  case 0x8795:
switchD_000b7340_caseD_8782:
    *outReadsX = 1;
    *outReadsY = 1;
    *outReadsZ = 1;
    *outReadsW = 1;
    return;
  case 0x8783:
  case 0x8789:
  case 0x878f:
  case 0x8790:
  case 0x8799:
  case 0x879c:
    operandDataType = extvsOperandDataType(symbolTable,inst + 8);
    if (operandDataType != 0x87bf) goto switchD_000b7340_caseD_8782;
  case 0x879a:
  case 0x879b:
    bVar3 = destEnableX == '\0';
    if ((((bVar3) || ((inst[10] != 0x87d5 && (inst[10] != 0x87d9)))) &&
        (((destEnableY == '\0' || ((inst[0xb] != 0x87d5 && (inst[0xb] != 0x87d9)))) &&
         ((destEnableZ == '\0' || ((inst[0xc] != 0x87d5 && (inst[0xc] != 0x87d9)))))))) &&
       ((destEnableW == '\0' || ((inst[0xd] != 0x87d5 && (inst[0xd] != 0x87d9)))))) {
      readFlag = 0;
    }
    else {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if (((((bVar3) || ((inst[10] != 0x87d6 && (inst[10] != 0x87da)))) &&
         ((destEnableY == '\0' || ((inst[0xb] != 0x87d6 && (inst[0xb] != 0x87da)))))) &&
        ((destEnableZ == '\0' || ((inst[0xc] != 0x87d6 && (inst[0xc] != 0x87da)))))) &&
       ((destEnableW == '\0' || ((inst[0xd] != 0x87d6 && (inst[0xd] != 0x87da)))))) {
      readFlag = 0;
    }
    else {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((((bVar3) || ((inst[10] != 0x87d7 && (inst[10] != 0x87db)))) &&
        ((destEnableY == '\0' || ((inst[0xb] != 0x87d7 && (inst[0xb] != 0x87db)))))) &&
       (((destEnableZ == '\0' || ((inst[0xc] != 0x87d7 && (inst[0xc] != 0x87db)))) &&
        ((destEnableW == '\0' || ((inst[0xd] != 0x87d7 && (inst[0xd] != 0x87db)))))))) {
      readFlag = 0;
    }
    else {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if ((((bVar3) || ((inst[10] != 0x87d8 && (inst[10] != 0x87dc)))) &&
        ((destEnableY == '\0' || ((inst[0xb] != 0x87d8 && (inst[0xb] != 0x87dc)))))) &&
       ((destEnableZ == '\0' || ((inst[0xc] != 0x87d8 && (inst[0xc] != 0x87dc)))))) {
      if (destEnableW == '\0') {
LAB_000b9970:
        readFlag = 0;
        goto LAB_000b9ef0;
      }
LAB_000b99c0:
      swizzleSelect = inst[0xd];
      if (swizzleSelect != 0x87d8) {
LAB_000b9960:
        if (swizzleSelect != 0x87dc) goto LAB_000b9970;
      }
    }
    break;
  case 0x8784:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      swizzleSelect = inst[10];
      if ((((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) || (inst[0xb] == 0x87d5)) ||
         (((inst[0xb] == 0x87d9 || (inst[0xc] == 0x87d5)) ||
          (bVar3 = false, inst[0xc] == 0x87d9)))) {
        bVar3 = true;
      }
      if (((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) ||
         ((inst[0xb] == 0x87d6 ||
          (((inst[0xb] == 0x87da || (inst[0xc] == 0x87d6)) ||
           (bVar9 = false, inst[0xc] == 0x87da)))))) {
        bVar9 = true;
      }
      if (((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) ||
         (((inst[0xb] == 0x87d7 || ((inst[0xb] == 0x87db || (inst[0xc] == 0x87d7)))) ||
          (bVar11 = false, inst[0xc] == 0x87db)))) {
        bVar11 = true;
      }
      if (((((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) || (inst[0xb] == 0x87d8)) ||
          ((inst[0xb] == 0x87dc || (inst[0xc] == 0x87d8)))) ||
         (bVar1 = false, inst[0xc] == 0x87dc)) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((inst[0xf] == 2) && (tempIndex == inst[0x10])) {
      swizzleSelect = inst[0x11];
      if ((((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) || (inst[0x12] == 0x87d5)) ||
         (((inst[0x12] == 0x87d9 || (inst[0x13] == 0x87d5)) ||
          (bVar8 = false, inst[0x13] == 0x87d9)))) {
        bVar8 = true;
      }
      if (((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) ||
         ((inst[0x12] == 0x87d6 ||
          (((inst[0x12] == 0x87da || (inst[0x13] == 0x87d6)) ||
           (bVar10 = false, inst[0x13] == 0x87da)))))) {
        bVar10 = true;
      }
      if (((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) ||
         (((inst[0x12] == 0x87d7 || ((inst[0x12] == 0x87db || (inst[0x13] == 0x87d7)))) ||
          (bVar12 = false, inst[0x13] == 0x87db)))) {
        bVar12 = true;
      }
      if (((((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) || (inst[0x12] == 0x87d8)) ||
          ((inst[0x12] == 0x87dc || (inst[0x13] == 0x87d8)))) ||
         (bVar2 = false, inst[0x13] == 0x87dc)) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (readFlag = 0, bVar8)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if ((bVar9) || (readFlag = 0, bVar10)) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((bVar11) || (readFlag = 0, bVar12)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if (bVar1) break;
    goto LAB_000b9dfc;
  case 0x8785:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      swizzleSelect = inst[10];
      if ((((((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) || (inst[0xb] == 0x87d5)) ||
           ((inst[0xb] == 0x87d9 || (inst[0xc] == 0x87d5)))) || (inst[0xc] == 0x87d9)) ||
         ((inst[0xd] == 0x87d5 || (bVar3 = false, inst[0xd] == 0x87d9)))) {
        bVar3 = true;
      }
      if ((((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) || (inst[0xb] == 0x87d6)) ||
         (((inst[0xb] == 0x87da || (inst[0xc] == 0x87d6)) ||
          ((inst[0xc] == 0x87da ||
           ((inst[0xd] == 0x87d6 || (bVar9 = false, inst[0xd] == 0x87da)))))))) {
        bVar9 = true;
      }
      if ((((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) || (inst[0xb] == 0x87d7)) ||
         (((inst[0xb] == 0x87db || (inst[0xc] == 0x87d7)) ||
          ((inst[0xc] == 0x87db ||
           ((inst[0xd] == 0x87d7 || (bVar11 = false, inst[0xd] == 0x87db)))))))) {
        bVar11 = true;
      }
      if (((((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) || (inst[0xb] == 0x87d8)) ||
          ((inst[0xb] == 0x87dc || (inst[0xc] == 0x87d8)))) ||
         ((inst[0xc] == 0x87dc ||
          ((inst[0xd] == 0x87d8 || (bVar1 = false, inst[0xd] == 0x87dc)))))) {
        bVar1 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
    }
    if ((inst[0xf] == 2) && (tempIndex == inst[0x10])) {
      swizzleSelect = inst[0x11];
      if ((((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) || (inst[0x12] == 0x87d5)) ||
         (((inst[0x12] == 0x87d9 || (inst[0x13] == 0x87d5)) ||
          ((inst[0x13] == 0x87d9 ||
           ((inst[0x14] == 0x87d5 || (bVar8 = false, inst[0x14] == 0x87d9)))))))) {
        bVar8 = true;
      }
      if ((((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) || (inst[0x12] == 0x87d6)) ||
         (((inst[0x12] == 0x87da || (inst[0x13] == 0x87d6)) ||
          ((inst[0x13] == 0x87da ||
           ((inst[0x14] == 0x87d6 || (bVar10 = false, inst[0x14] == 0x87da)))))))) {
        bVar10 = true;
      }
      if (((((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) || (inst[0x12] == 0x87d7)) ||
          ((inst[0x12] == 0x87db || (inst[0x13] == 0x87d7)))) ||
         ((inst[0x13] == 0x87db ||
          ((inst[0x14] == 0x87d7 || (bVar12 = false, inst[0x14] == 0x87db)))))) {
        bVar12 = true;
      }
      if ((((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) || (inst[0x12] == 0x87d8)) ||
         (((inst[0x12] == 0x87dc || (inst[0x13] == 0x87d8)) ||
          ((inst[0x13] == 0x87dc ||
           ((inst[0x14] == 0x87d8 || (bVar2 = false, inst[0x14] == 0x87dc)))))))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar3) || (readFlag = 0, bVar8)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if (bVar9) goto LAB_000b92a0;
LAB_000b9294:
    readFlag = 0;
    if (bVar10) goto LAB_000b92a0;
    goto LAB_000b92a4;
  case 0x8786:
  case 0x8787:
  case 0x878a:
  case 0x878b:
  case 0x878c:
  case 0x878d:
  case 0x8796:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      operandDataType = extvsOperandDataType(symbolTable,inst + 8);
      if (operandDataType == 0x87bf) {
        bVar3 = destEnableX == '\0';
        if (((((bVar3) || ((inst[10] != 0x87d5 && (inst[10] != 0x87d9)))) &&
             ((destEnableY == '\0' || ((inst[0xb] != 0x87d5 && (inst[0xb] != 0x87d9)))))) &&
            ((destEnableZ == '\0' || ((inst[0xc] != 0x87d5 && (inst[0xc] != 0x87d9)))))) &&
           ((destEnableW == '\0' || ((inst[0xd] != 0x87d5 && (inst[0xd] != 0x87d9)))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar3) || ((inst[10] != 0x87d6 && (inst[10] != 0x87da)))) &&
            ((destEnableY == '\0' || ((inst[0xb] != 0x87d6 && (inst[0xb] != 0x87da)))))) &&
           (((destEnableZ == '\0' || ((inst[0xc] != 0x87d6 && (inst[0xc] != 0x87da)))) &&
            ((destEnableW == '\0' || ((inst[0xd] != 0x87d6 && (inst[0xd] != 0x87da)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if ((((bVar3) || ((inst[10] != 0x87d7 && (inst[10] != 0x87db)))) &&
            ((destEnableY == '\0' || ((inst[0xb] != 0x87d7 && (inst[0xb] != 0x87db)))))) &&
           (((destEnableZ == '\0' || ((inst[0xc] != 0x87d7 && (inst[0xc] != 0x87db)))) &&
            ((destEnableW == '\0' || ((inst[0xd] != 0x87d7 && (inst[0xd] != 0x87db)))))))) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (((((bVar3) || ((inst[10] != 0x87d8 && (inst[10] != 0x87dc)))) &&
             ((destEnableY == '\0' || ((inst[0xb] != 0x87d8 && (inst[0xb] != 0x87dc)))))) &&
            ((destEnableZ == '\0' || ((inst[0xc] != 0x87d8 && (inst[0xc] != 0x87dc)))))) &&
           ((destEnableW == '\0' || ((inst[0xd] != 0x87d8 && (inst[0xd] != 0x87dc))))))
        goto LAB_000b7dec;
        bVar3 = true;
      }
      else {
        bVar9 = true;
        bVar11 = true;
        bVar1 = true;
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
LAB_000b7dec:
      bVar3 = false;
    }
    if ((inst[0xf] == 2) && (tempIndex == inst[0x10])) {
      operandDataType = extvsOperandDataType(symbolTable,inst + 0xf);
      if (operandDataType == 0x87bf) {
        bVar2 = destEnableX == '\0';
        if ((((bVar2) || ((inst[0x11] != 0x87d5 && (inst[0x11] != 0x87d9)))) &&
            ((destEnableY == '\0' || ((inst[0x12] != 0x87d5 && (inst[0x12] != 0x87d9)))))) &&
           (((destEnableZ == '\0' || ((inst[0x13] != 0x87d5 && (inst[0x13] != 0x87d9)))) &&
            ((destEnableW == '\0' || ((inst[0x14] != 0x87d5 && (inst[0x14] != 0x87d9)))))))) {
          bVar8 = false;
        }
        else {
          bVar8 = true;
        }
        if ((((bVar2) || ((inst[0x11] != 0x87d6 && (inst[0x11] != 0x87da)))) &&
            ((destEnableY == '\0' || ((inst[0x12] != 0x87d6 && (inst[0x12] != 0x87da)))))) &&
           (((destEnableZ == '\0' || ((inst[0x13] != 0x87d6 && (inst[0x13] != 0x87da)))) &&
            ((destEnableW == '\0' || ((inst[0x14] != 0x87d6 && (inst[0x14] != 0x87da)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar2) || ((inst[0x11] != 0x87d7 && (inst[0x11] != 0x87db)))) &&
             ((destEnableY == '\0' || ((inst[0x12] != 0x87d7 && (inst[0x12] != 0x87db)))))) &&
            ((destEnableZ == '\0' || ((inst[0x13] != 0x87d7 && (inst[0x13] != 0x87db)))))) &&
           ((destEnableW == '\0' || ((inst[0x14] != 0x87d7 && (inst[0x14] != 0x87db)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if ((((bVar2) || ((inst[0x11] != 0x87d8 && (inst[0x11] != 0x87dc)))) &&
            ((destEnableY == '\0' || ((inst[0x12] != 0x87d8 && (inst[0x12] != 0x87dc)))))) &&
           (((destEnableZ == '\0' || ((inst[0x13] != 0x87d8 && (inst[0x13] != 0x87dc)))) &&
            ((destEnableW == '\0' || ((inst[0x14] != 0x87d8 && (inst[0x14] != 0x87dc))))))))
        goto LAB_000b812c;
        bVar2 = true;
      }
      else {
        bVar8 = true;
        bVar10 = true;
        bVar12 = true;
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b812c:
      bVar2 = false;
    }
    if ((bVar9) || (readFlag = 0, bVar8)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if ((bVar11) || (readFlag = 0, bVar10)) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((bVar1) || (readFlag = 0, bVar12)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    goto joined_r0x000b9df8;
  case 0x8788:
  case 0x878e:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      operandDataType = extvsOperandDataType(symbolTable,inst + 8);
      if (operandDataType == 0x87bf) {
        bVar1 = destEnableX == '\0';
        if (((((bVar1) || ((inst[10] != 0x87d5 && (inst[10] != 0x87d9)))) &&
             ((destEnableY == '\0' || ((inst[0xb] != 0x87d5 && (inst[0xb] != 0x87d9)))))) &&
            ((destEnableZ == '\0' || ((inst[0xc] != 0x87d5 && (inst[0xc] != 0x87d9)))))) &&
           ((destEnableW == '\0' || ((inst[0xd] != 0x87d5 && (inst[0xd] != 0x87d9)))))) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if ((((bVar1) || ((inst[10] != 0x87d6 && (inst[10] != 0x87da)))) &&
            ((destEnableY == '\0' || ((inst[0xb] != 0x87d6 && (inst[0xb] != 0x87da)))))) &&
           (((destEnableZ == '\0' || ((inst[0xc] != 0x87d6 && (inst[0xc] != 0x87da)))) &&
            ((destEnableW == '\0' || ((inst[0xd] != 0x87d6 && (inst[0xd] != 0x87da)))))))) {
          bVar9 = false;
        }
        else {
          bVar9 = true;
        }
        if ((((bVar1) || ((inst[10] != 0x87d7 && (inst[10] != 0x87db)))) &&
            ((destEnableY == '\0' || ((inst[0xb] != 0x87d7 && (inst[0xb] != 0x87db)))))) &&
           (((destEnableZ == '\0' || ((inst[0xc] != 0x87d7 && (inst[0xc] != 0x87db)))) &&
            ((destEnableW == '\0' || ((inst[0xd] != 0x87d7 && (inst[0xd] != 0x87db)))))))) {
          bVar11 = false;
        }
        else {
          bVar11 = true;
        }
        if (((((bVar1) || ((inst[10] != 0x87d8 && (inst[10] != 0x87dc)))) &&
             ((destEnableY == '\0' || ((inst[0xb] != 0x87d8 && (inst[0xb] != 0x87dc)))))) &&
            ((destEnableZ == '\0' || ((inst[0xc] != 0x87d8 && (inst[0xc] != 0x87dc)))))) &&
           ((destEnableW == '\0' || ((inst[0xd] != 0x87d8 && (inst[0xd] != 0x87dc))))))
        goto LAB_000b84cc;
        bVar8 = true;
      }
      else {
        bVar3 = true;
        bVar9 = true;
        bVar11 = true;
        bVar8 = true;
      }
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b84cc:
      bVar8 = false;
    }
    if ((inst[0xf] == 2) && (tempIndex == inst[0x10])) {
      operandDataType = extvsOperandDataType(symbolTable,inst + 0xf);
      if (operandDataType == 0x87bf) {
        bVar1 = destEnableX == '\0';
        if ((((bVar1) || ((inst[0x11] != 0x87d5 && (inst[0x11] != 0x87d9)))) &&
            ((destEnableY == '\0' || ((inst[0x12] != 0x87d5 && (inst[0x12] != 0x87d9)))))) &&
           (((destEnableZ == '\0' || ((inst[0x13] != 0x87d5 && (inst[0x13] != 0x87d9)))) &&
            ((destEnableW == '\0' || ((inst[0x14] != 0x87d5 && (inst[0x14] != 0x87d9)))))))) {
          bVar10 = false;
        }
        else {
          bVar10 = true;
        }
        if (((((bVar1) || ((inst[0x11] != 0x87d6 && (inst[0x11] != 0x87da)))) &&
             ((destEnableY == '\0' || ((inst[0x12] != 0x87d6 && (inst[0x12] != 0x87da)))))) &&
            ((destEnableZ == '\0' || ((inst[0x13] != 0x87d6 && (inst[0x13] != 0x87da)))))) &&
           ((destEnableW == '\0' || ((inst[0x14] != 0x87d6 && (inst[0x14] != 0x87da)))))) {
          bVar12 = false;
        }
        else {
          bVar12 = true;
        }
        if (((((bVar1) || ((inst[0x11] != 0x87d7 && (inst[0x11] != 0x87db)))) &&
             ((destEnableY == '\0' || ((inst[0x12] != 0x87d7 && (inst[0x12] != 0x87db)))))) &&
            ((destEnableZ == '\0' || ((inst[0x13] != 0x87d7 && (inst[0x13] != 0x87db)))))) &&
           ((destEnableW == '\0' || ((inst[0x14] != 0x87d7 && (inst[0x14] != 0x87db)))))) {
          bVar16 = false;
        }
        else {
          bVar16 = true;
        }
        if ((((bVar1) || ((inst[0x11] != 0x87d8 && (inst[0x11] != 0x87dc)))) &&
            ((destEnableY == '\0' || ((inst[0x12] != 0x87d8 && (inst[0x12] != 0x87dc)))))) &&
           (((destEnableZ == '\0' || ((inst[0x13] != 0x87d8 && (inst[0x13] != 0x87dc)))) &&
            ((destEnableW == '\0' || ((inst[0x14] != 0x87d8 && (inst[0x14] != 0x87dc))))))))
        goto LAB_000b880c;
        bVar1 = true;
      }
      else {
        bVar10 = true;
        bVar12 = true;
        bVar16 = true;
        bVar1 = true;
      }
    }
    else {
      bVar10 = false;
      bVar12 = false;
      bVar16 = false;
LAB_000b880c:
      bVar1 = false;
    }
    if ((inst[0x16] == 2) && (tempIndex == inst[0x17])) {
      operandDataType = extvsOperandDataType(symbolTable,inst + 0x16);
      if (operandDataType == 0x87bf) {
        bVar2 = destEnableX == '\0';
        if ((((bVar2) || ((inst[0x18] != 0x87d5 && (inst[0x18] != 0x87d9)))) &&
            ((destEnableY == '\0' || ((inst[0x19] != 0x87d5 && (inst[0x19] != 0x87d9)))))) &&
           (((destEnableZ == '\0' || ((inst[0x1a] != 0x87d5 && (inst[0x1a] != 0x87d9)))) &&
            ((destEnableW == '\0' || ((inst[0x1b] != 0x87d5 && (inst[0x1b] != 0x87d9)))))))) {
          bVar13 = false;
        }
        else {
          bVar13 = true;
        }
        if (((((bVar2) || ((inst[0x18] != 0x87d6 && (inst[0x18] != 0x87da)))) &&
             ((destEnableY == '\0' || ((inst[0x19] != 0x87d6 && (inst[0x19] != 0x87da)))))) &&
            ((destEnableZ == '\0' || ((inst[0x1a] != 0x87d6 && (inst[0x1a] != 0x87da)))))) &&
           ((destEnableW == '\0' || ((inst[0x1b] != 0x87d6 && (inst[0x1b] != 0x87da)))))) {
          bVar14 = false;
        }
        else {
          bVar14 = true;
        }
        if ((((bVar2) || ((inst[0x18] != 0x87d7 && (inst[0x18] != 0x87db)))) &&
            ((destEnableY == '\0' || ((inst[0x19] != 0x87d7 && (inst[0x19] != 0x87db)))))) &&
           (((destEnableZ == '\0' || ((inst[0x1a] != 0x87d7 && (inst[0x1a] != 0x87db)))) &&
            ((destEnableW == '\0' || ((inst[0x1b] != 0x87d7 && (inst[0x1b] != 0x87db)))))))) {
          bVar15 = false;
        }
        else {
          bVar15 = true;
        }
        if ((((bVar2) || ((inst[0x18] != 0x87d8 && (inst[0x18] != 0x87dc)))) &&
            ((destEnableY == '\0' || ((inst[0x19] != 0x87d8 && (inst[0x19] != 0x87dc)))))) &&
           (((destEnableZ == '\0' || ((inst[0x1a] != 0x87d8 && (inst[0x1a] != 0x87dc)))) &&
            ((destEnableW == '\0' || ((inst[0x1b] != 0x87d8 && (inst[0x1b] != 0x87dc))))))))
        goto LAB_000b8b4c;
        bVar2 = true;
      }
      else {
        bVar13 = true;
        bVar14 = true;
        bVar15 = true;
        bVar2 = true;
      }
    }
    else {
      bVar13 = false;
      bVar14 = false;
      bVar15 = false;
LAB_000b8b4c:
      bVar2 = false;
    }
    if (((bVar3) || (bVar10)) || (readFlag = 0, bVar13)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if (((bVar9) || (bVar12)) || (readFlag = 0, bVar14)) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if (((bVar11) || (bVar16)) || (readFlag = 0, bVar15)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if (bVar8) break;
    goto joined_r0x000b8bc8;
  case 0x8797:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      bVar1 = destEnableX == '\0';
      if ((((bVar1) ||
           ((((inst[0xb] != 0x87d5 && (inst[0xb] != 0x87d9)) && (inst[0xc] != 0x87d5)) &&
            (inst[0xc] != 0x87d9)))) &&
          ((destEnableY == '\0' ||
           (((inst[10] != 0x87d5 && (inst[10] != 0x87d9)) &&
            ((inst[0xc] != 0x87d5 && (inst[0xc] != 0x87d9)))))))) &&
         ((destEnableZ == '\0' ||
          (((inst[10] != 0x87d5 && (inst[10] != 0x87d9)) &&
           ((inst[0xb] != 0x87d5 && (inst[0xb] != 0x87d9)))))))) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (((bVar1) ||
          ((((inst[0xb] != 0x87d6 && (inst[0xb] != 0x87da)) && (inst[0xc] != 0x87d6)) &&
           (inst[0xc] != 0x87da)))) &&
         (((destEnableY == '\0' ||
           (((inst[10] != 0x87d6 && (inst[10] != 0x87da)) &&
            ((inst[0xc] != 0x87d6 && (inst[0xc] != 0x87da)))))) &&
          ((destEnableZ == '\0' ||
           (((inst[10] != 0x87d6 && (inst[10] != 0x87da)) &&
            ((inst[0xb] != 0x87d6 && (inst[0xb] != 0x87da)))))))))) {
        bVar9 = false;
      }
      else {
        bVar9 = true;
      }
      if ((((bVar1) ||
           ((((inst[0xb] != 0x87d7 && (inst[0xb] != 0x87db)) && (inst[0xc] != 0x87d7)) &&
            (inst[0xc] != 0x87db)))) &&
          ((destEnableY == '\0' ||
           (((inst[10] != 0x87d7 && (inst[10] != 0x87db)) &&
            ((inst[0xc] != 0x87d7 && (inst[0xc] != 0x87db)))))))) &&
         ((destEnableZ == '\0' ||
          (((inst[10] != 0x87d7 && (inst[10] != 0x87db)) &&
           ((inst[0xb] != 0x87d7 && (inst[0xb] != 0x87db)))))))) {
        bVar11 = false;
      }
      else {
        bVar11 = true;
      }
      if (((bVar1) ||
          ((((inst[0xb] != 0x87d8 && (inst[0xb] != 0x87dc)) && (inst[0xc] != 0x87d8)) &&
           (inst[0xc] != 0x87dc)))) &&
         (((destEnableY == '\0' ||
           (((inst[10] != 0x87d8 && (inst[10] != 0x87dc)) &&
            ((inst[0xc] != 0x87d8 && (inst[0xc] != 0x87dc)))))) &&
          ((destEnableZ == '\0' ||
           (((inst[10] != 0x87d8 && (inst[10] != 0x87dc)) &&
            ((inst[0xb] != 0x87d8 && (inst[0xb] != 0x87dc)))))))))) goto LAB_000b8f1c;
      bVar1 = true;
    }
    else {
      bVar3 = false;
      bVar9 = false;
      bVar11 = false;
LAB_000b8f1c:
      bVar1 = false;
    }
    if ((inst[0xf] == 2) && (tempIndex == inst[0x10])) {
      bVar2 = destEnableX == '\0';
      if ((((bVar2) ||
           ((((inst[0x12] != 0x87d5 && (inst[0x12] != 0x87d9)) && (inst[0x13] != 0x87d5))
            && (inst[0x13] != 0x87d9)))) &&
          ((destEnableY == '\0' ||
           (((inst[0x11] != 0x87d5 && (inst[0x11] != 0x87d9)) &&
            ((inst[0x13] != 0x87d5 && (inst[0x13] != 0x87d9)))))))) &&
         ((destEnableZ == '\0' ||
          (((inst[0x11] != 0x87d5 && (inst[0x11] != 0x87d9)) &&
           ((inst[0x12] != 0x87d5 && (inst[0x12] != 0x87d9)))))))) {
        bVar8 = false;
      }
      else {
        bVar8 = true;
      }
      if ((((bVar2) ||
           ((((inst[0x12] != 0x87d6 && (inst[0x12] != 0x87da)) && (inst[0x13] != 0x87d6))
            && (inst[0x13] != 0x87da)))) &&
          ((destEnableY == '\0' ||
           (((inst[0x11] != 0x87d6 && (inst[0x11] != 0x87da)) &&
            ((inst[0x13] != 0x87d6 && (inst[0x13] != 0x87da)))))))) &&
         ((destEnableZ == '\0' ||
          (((inst[0x11] != 0x87d6 && (inst[0x11] != 0x87da)) &&
           ((inst[0x12] != 0x87d6 && (inst[0x12] != 0x87da)))))))) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      if (((bVar2) ||
          ((((inst[0x12] != 0x87d7 && (inst[0x12] != 0x87db)) && (inst[0x13] != 0x87d7)) &&
           (inst[0x13] != 0x87db)))) &&
         (((destEnableY == '\0' ||
           (((inst[0x11] != 0x87d7 && (inst[0x11] != 0x87db)) &&
            ((inst[0x13] != 0x87d7 && (inst[0x13] != 0x87db)))))) &&
          ((destEnableZ == '\0' ||
           (((inst[0x11] != 0x87d7 && (inst[0x11] != 0x87db)) &&
            ((inst[0x12] != 0x87d7 && (inst[0x12] != 0x87db)))))))))) {
        bVar12 = false;
      }
      else {
        bVar12 = true;
      }
      if ((((bVar2) ||
           ((((inst[0x12] != 0x87d8 && (inst[0x12] != 0x87dc)) && (inst[0x13] != 0x87d8))
            && (inst[0x13] != 0x87dc)))) &&
          ((destEnableY == '\0' ||
           (((inst[0x11] != 0x87d8 && (inst[0x11] != 0x87dc)) &&
            ((inst[0x13] != 0x87d8 && (inst[0x13] != 0x87dc)))))))) &&
         ((destEnableZ == '\0' ||
          (((inst[0x11] != 0x87d8 && (inst[0x11] != 0x87dc)) &&
           ((inst[0x12] != 0x87d8 && (inst[0x12] != 0x87dc)))))))) goto LAB_000b926c;
      bVar2 = true;
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
LAB_000b926c:
      bVar2 = false;
    }
    if ((bVar3) || (readFlag = 0, bVar8)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if (!bVar9) goto LAB_000b9294;
LAB_000b92a0:
    readFlag = 1;
LAB_000b92a4:
    *outReadsY = readFlag;
    if ((bVar11) || (readFlag = 0, bVar12)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
joined_r0x000b8bc8:
    if (!bVar1) {
LAB_000b9dfc:
      readFlag = 0;
      if (!bVar2) goto LAB_000b9ef0;
    }
    break;
  case 0x8798:
    if ((((((inst[0x11] == 0x87d5) || (inst[0x11] == 0x87d9)) || (inst[0x12] == 0x87d5)) ||
         ((inst[0x12] == 0x87d9 || (inst[0x13] == 0x87d5)))) || (inst[0x13] == 0x87d9)) ||
       ((inst[0x14] == 0x87d5 || (readFlag = 0, inst[0x14] == 0x87d9)))) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if ((((inst[0x11] == 0x87d6) || (inst[0x11] == 0x87da)) || (inst[0x12] == 0x87d6)) ||
       (((inst[0x12] == 0x87da || (inst[0x13] == 0x87d6)) ||
        ((inst[0x13] == 0x87da ||
         ((inst[0x14] == 0x87d6 || (readFlag = 0, inst[0x14] == 0x87da)))))))) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((((inst[0x11] == 0x87d7) || (inst[0x11] == 0x87db)) || (inst[0x12] == 0x87d7)) ||
       (((inst[0x12] == 0x87db || (inst[0x13] == 0x87d7)) ||
        ((inst[0x13] == 0x87db ||
         ((inst[0x14] == 0x87d7 || (readFlag = 0, inst[0x14] == 0x87db)))))))) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if (((((inst[0x11] != 0x87d8) && (inst[0x11] != 0x87dc)) && (inst[0x12] != 0x87d8)) &&
        ((inst[0x12] != 0x87dc && (inst[0x13] != 0x87d8)))) && (inst[0x13] != 0x87dc)) {
      swizzleSelect = inst[0x14];
joined_r0x000b9b40:
      if ((swizzleSelect != 0x87d8) && (readFlag = 0, swizzleSelect != 0x87dc)) goto LAB_000b9ef0;
    }
    break;
  case 0x879d:
    operandDataType = extvsOperandDataType(symbolTable,inst + 8);
    if (operandDataType != 0x87bf) goto switchD_000b7340_caseD_8782;
    swizzleSelect = inst[0x10];
    if (swizzleSelect == 0) {
      swizzleSelect = inst[10];
joined_r0x000b97e0:
      if ((swizzleSelect != 0x87d5) && (swizzleSelect != 0x87d9)) goto LAB_000b9790;
      readFlag = 1;
    }
    else {
      if (swizzleSelect == 1) {
        swizzleSelect = inst[0xb];
        goto joined_r0x000b97e0;
      }
      if (swizzleSelect == 2) {
        swizzleSelect = inst[0xc];
        goto joined_r0x000b97e0;
      }
      if (swizzleSelect == 3) {
        swizzleSelect = inst[0xd];
        goto joined_r0x000b97e0;
      }
LAB_000b9790:
      readFlag = 0;
    }
    *outReadsX = readFlag;
    swizzleSelect = inst[0x10];
    if (swizzleSelect == 0) {
      swizzleSelect = inst[10];
joined_r0x000b9880:
      if ((swizzleSelect != 0x87d6) && (swizzleSelect != 0x87da)) goto LAB_000b9830;
      readFlag = 1;
    }
    else {
      if (swizzleSelect == 1) {
        swizzleSelect = inst[0xb];
        goto joined_r0x000b9880;
      }
      if (swizzleSelect == 2) {
        swizzleSelect = inst[0xc];
        goto joined_r0x000b9880;
      }
      if (swizzleSelect == 3) {
        swizzleSelect = inst[0xd];
        goto joined_r0x000b9880;
      }
LAB_000b9830:
      readFlag = 0;
    }
    *outReadsY = readFlag;
    swizzleSelect = inst[0x10];
    if (swizzleSelect == 0) {
      swizzleSelect = inst[10];
joined_r0x000b9920:
      if ((swizzleSelect != 0x87d7) && (swizzleSelect != 0x87db)) goto LAB_000b98d0;
      readFlag = 1;
    }
    else {
      if (swizzleSelect == 1) {
        swizzleSelect = inst[0xb];
        goto joined_r0x000b9920;
      }
      if (swizzleSelect == 2) {
        swizzleSelect = inst[0xc];
        goto joined_r0x000b9920;
      }
      if (swizzleSelect == 3) {
        swizzleSelect = inst[0xd];
        goto joined_r0x000b9920;
      }
LAB_000b98d0:
      readFlag = 0;
    }
    *outReadsZ = readFlag;
    swizzleSelect = inst[0x10];
    if (swizzleSelect == 0) {
      swizzleSelect = inst[10];
joined_r0x000b9990:
      if (swizzleSelect == 0x87d8) break;
      goto LAB_000b9960;
    }
    if (swizzleSelect == 1) {
      swizzleSelect = inst[0xb];
      goto joined_r0x000b9990;
    }
    if (swizzleSelect == 2) {
      swizzleSelect = inst[0xc];
      goto joined_r0x000b9990;
    }
    if (swizzleSelect == 3) goto LAB_000b99c0;
    goto LAB_000b9970;
  case 0x879e:
    if (((((inst[10] == 0x87d5) || (inst[10] == 0x87d9)) || (inst[0xb] == 0x87d5)) ||
        ((inst[0xb] == 0x87d9 || (inst[0xd] == 0x87d5)))) ||
       (readFlag = 0, inst[0xd] == 0x87d9)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if (((inst[10] == 0x87d6) || (inst[10] == 0x87da)) ||
       ((inst[0xb] == 0x87d6 ||
        (((inst[0xb] == 0x87da || (inst[0xd] == 0x87d6)) ||
         (readFlag = 0, inst[0xd] == 0x87da)))))) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if (((inst[10] == 0x87d7) || (inst[10] == 0x87db)) ||
       (((inst[0xb] == 0x87d7 || ((inst[0xb] == 0x87db || (inst[0xd] == 0x87d7)))) ||
        (readFlag = 0, inst[0xd] == 0x87db)))) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if ((((inst[10] != 0x87d8) && (inst[10] != 0x87dc)) && (inst[0xb] != 0x87d8)) &&
       (inst[0xb] != 0x87dc)) {
      swizzleSelect = inst[0xd];
      goto joined_r0x000b9b40;
    }
    break;
  case 0x879f:
    if ((inst[8] == 2) && (tempIndex == inst[9])) {
      swizzleSelect = inst[0xb];
      if ((((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) || (inst[0xc] == 0x87d5)) ||
         (bVar9 = false, inst[0xc] == 0x87d9)) {
        bVar9 = true;
      }
      if (((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) ||
         ((inst[0xc] == 0x87d6 || (bVar11 = false, inst[0xc] == 0x87da)))) {
        bVar11 = true;
      }
      if (((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) ||
         ((inst[0xc] == 0x87d7 || (bVar1 = false, inst[0xc] == 0x87db)))) {
        bVar1 = true;
      }
      if ((((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) || (inst[0xc] == 0x87d8)) ||
         (bVar3 = false, inst[0xc] == 0x87dc)) {
        bVar3 = true;
      }
    }
    else {
      bVar9 = false;
      bVar11 = false;
      bVar1 = false;
      bVar3 = false;
    }
    if ((inst[0xf] == 2) && (inst[0x10] == tempIndex)) {
      swizzleSelect = inst[0x12];
      if (((swizzleSelect == 0x87d5) || (swizzleSelect == 0x87d9)) ||
         ((inst[0x14] == 0x87d5 || (bVar8 = false, inst[0x14] == 0x87d9)))) {
        bVar8 = true;
      }
      if ((((swizzleSelect == 0x87d6) || (swizzleSelect == 0x87da)) || (inst[0x14] == 0x87d6)) ||
         (bVar10 = false, inst[0x14] == 0x87da)) {
        bVar10 = true;
      }
      if (((swizzleSelect == 0x87d7) || (swizzleSelect == 0x87db)) ||
         ((inst[0x14] == 0x87d7 || (bVar12 = false, inst[0x14] == 0x87db)))) {
        bVar12 = true;
      }
      if (((swizzleSelect == 0x87d8) || (swizzleSelect == 0x87dc)) ||
         ((inst[0x14] == 0x87d8 || (bVar2 = false, inst[0x14] == 0x87dc)))) {
        bVar2 = true;
      }
    }
    else {
      bVar8 = false;
      bVar10 = false;
      bVar12 = false;
      bVar2 = false;
    }
    if ((bVar9) || (readFlag = 0, bVar8)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if ((bVar11) || (readFlag = 0, bVar10)) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((bVar1) || (readFlag = 0, bVar12)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
joined_r0x000b9df8:
    if (bVar3) break;
    goto LAB_000b9dfc;
  case 0x87a0:
  case 0x87a1:
  case 0x87a2:
    if ((inst[10] == 0x87d5) || (readFlag = 0, inst[10] == 0x87d9)) {
      readFlag = 1;
    }
    *outReadsX = readFlag;
    if ((inst[10] == 0x87d6) || (readFlag = 0, inst[10] == 0x87da)) {
      readFlag = 1;
    }
    *outReadsY = readFlag;
    if ((inst[10] == 0x87d7) || (readFlag = 0, inst[10] == 0x87db)) {
      readFlag = 1;
    }
    *outReadsZ = readFlag;
    if ((inst[10] == 0x87d8) || (readFlag = 0, inst[10] == 0x87dc)) {
      readFlag = 1;
    }
    *outReadsW = readFlag;
    return;
  default:
    readFlag = 0;
    *outReadsX = 0;
    *outReadsY = 0;
    *outReadsZ = 0;
    goto LAB_000b9ef0;
  }
  readFlag = 1;
LAB_000b9ef0:
  *outReadsW = readFlag;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_000afe40");
asm(".set FUN_000afe40, _FUN_000afe40");
asm(".globl atifsCompileCurrentShader");
asm(".set atifsCompileCurrentShader, _atifsCompileCurrentShader");
asm(".globl FUN_000b57a0");
asm(".set FUN_000b57a0, _gld_compileFragmentProgramImage");
asm(".globl FUN_000b5b60");
asm(".set FUN_000b5b60, _FUN_000b5b60");
asm(".globl FUN_000b5ba0");
asm(".set FUN_000b5ba0, _FUN_000b5ba0");
asm(".globl FUN_000b5bd0");
asm(".set FUN_000b5bd0, _FUN_000b5bd0");
asm(".globl FUN_000b5c00");
asm(".set FUN_000b5c00, _gld_bindProgramStateAndEmit");
asm(".globl FUN_000b5f40");
asm(".set FUN_000b5f40, _FUN_000b5f40");
