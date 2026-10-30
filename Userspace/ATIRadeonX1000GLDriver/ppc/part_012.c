#include "decls.h"

/* noop_83100 @ 0x83100 (4 bytes) */
int noop_83100()
{
  return;
}

/* ffvpSetupVertexOutputRouting @ 0x83110 (856 bytes) */
int ffvpSetupVertexOutputRouting(ctx)
  int ctx;
{
  uint lastSlot;
  uint routeBits;
  int ctxCursor;
  int routeRegPtr;
  int nextSlot;
  code *commitFn;
  uint outputMask;
  uint loopIndex;
  int secondarySlot;
  int slotCursor;
  int colorSlot;
  uint texRouteWord;
  
  *(undefined4 *)(ctx + 0x1ca0) = 1;
  *(undefined4 *)(ctx + 0x1ca4) = 4;
  outputMask = *(uint *)(ctx + 0x1804);
  FUN_0004fc80(ctx,0,3,0,0,0,0,0);
  *(undefined4 *)(ctx + 0x1b9c) = 1;
  *(undefined4 *)(ctx + 0x1bb0) = 0;
  *(undefined4 *)(ctx + 0x1ba0) = 0;
  if ((outputMask & 2) == 0) {
    colorSlot = 1;
    secondarySlot = 2;
  }
  else {
    colorSlot = 2;
    secondarySlot = 3;
    *(uint *)(ctx + 0x1ca0) = *(uint *)(ctx + 0x1ca0) | 0x40000;
    *(uint *)(ctx + 0x1ca4) =
         (*(uint *)(ctx + 0x1ca4) & 0x7f) + 1 & 0x7f | *(uint *)(ctx + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(ctx,1,0,0,1,0,0,0);
    *(uint *)(ctx + 0x1b9c) = *(uint *)(ctx + 0x1b9c) | 0x10000;
  }
  *(uint *)(ctx + 0x1ca0) = *(uint *)(ctx + 0x1ca0) | 4;
  *(uint *)(ctx + 0x1ca4) =
       (*(uint *)(ctx + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(ctx + 0x1ca4) & 0xffffff80;
  FUN_0004fc80(ctx,colorSlot,3,0,colorSlot,0,0,0);
  *(uint *)(ctx + 0x1b9c) = *(uint *)(ctx + 0x1b9c) | 2;
  slotCursor = secondarySlot;
  if ((outputMask & 1) != 0) {
    slotCursor = colorSlot + 2;
    *(uint *)(ctx + 0x1ca0) = *(uint *)(ctx + 0x1ca0) | 8;
    *(uint *)(ctx + 0x1ca4) =
         (*(uint *)(ctx + 0x1ca4) & 0x7f) + 4 & 0x7f | *(uint *)(ctx + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(ctx,secondarySlot,3,0,secondarySlot,0,0,0);
    *(uint *)(ctx + 0x1b9c) = *(uint *)(ctx + 0x1b9c) | 4;
  }
  if ((outputMask & 8) != 0) {
    *(uint *)(ctx + 0x1ca0) = *(uint *)(ctx + 0x1ca0) | 0x30;
    *(uint *)(ctx + 0x1ca4) =
         (*(uint *)(ctx + 0x1ca4) & 0x7f) + 7 & 0x7f | *(uint *)(ctx + 0x1ca4) & 0xffffff80;
    FUN_0004fc80(ctx,slotCursor,3,0,slotCursor,0,0,0);
    nextSlot = slotCursor + 1;
    slotCursor = slotCursor + 2;
    FUN_0004fc80(ctx,nextSlot,2,0,nextSlot,0,0,0);
    *(uint *)(ctx + 0x1b9c) = *(uint *)(ctx + 0x1b9c) | 0x18;
  }
  if (outputMask >> 4 != 0) {
    loopIndex = 0;
    nextSlot = slotCursor;
    ctxCursor = ctx;
    do {
      texRouteWord = *(uint *)(ctxCursor + 0x1824);
      loopIndex = loopIndex + 1;
      slotCursor = nextSlot + 1;
      ctxCursor = ctxCursor + 4;
      *(uint *)(ctx + 0x1ca0) = 0x400 << (texRouteWord & 0x3f) | *(uint *)(ctx + 0x1ca0);
      texRouteWord = 4 << (texRouteWord * 3 & 0x3f);
      *(uint *)(ctx + 0x1ca4) =
           (*(uint *)(ctx + 0x1ca4) & 0x7f) + 4 & 0x7f |
           *(uint *)(ctx + 0x1ca4) & 0xffffff80;
      FUN_0004fc80(ctx,nextSlot,3,0,nextSlot,0,0,0);
      *(uint *)(ctx + 0x1bb0) = texRouteWord | *(uint *)(ctx + 0x1bb0);
      *(uint *)(ctx + 0x1ba0) = texRouteWord | *(uint *)(ctx + 0x1ba0);
      nextSlot = slotCursor;
    } while (outputMask >> 4 != loopIndex);
  }
  if ((*(uint *)(ctx + 0x44) & 0x400) != 0) {
    routeBits = 4 << ((uint)(byte)((unsigned char *)0x000011d2)[ctx] * 3 & 0x3f);
    *(uint *)(ctx + 0x1bb0) = routeBits | *(uint *)(ctx + 0x1bb0);
    *(uint *)(ctx + 0x1ba0) = routeBits | *(uint *)(ctx + 0x1ba0);
  }
  lastSlot = slotCursor - 1;
  if ((lastSlot & 1) == 0) {
    routeRegPtr = (lastSlot * 2 & 0xfffffffc) + ctx;
    *(uint *)(routeRegPtr + 0x1be4) = *(uint *)(routeRegPtr + 0x1be4) | 0x2000;
  }
  else {
    routeRegPtr = (lastSlot * 2 & 0xfffffffc) + ctx;
    *(uint *)(routeRegPtr + 0x1be4) = *(uint *)(routeRegPtr + 0x1be4) | 0x20000000;
  }
  commitFn = *(code **)(((unsigned char *)0x00001334) + ctx);
  *(int *)(ctx + 0x243c) = slotCursor;
  *(int *)(ctx + 0x2438) = slotCursor;
  (*commitFn)(ctx,1);
                    
                    
  (**(code **)(((unsigned char *)0x00001330) + ctx))(ctx,0xc0100000);
  return;
}

/* ffvpBuildPassThroughProgram @ 0x83470 (828 bytes) */
int ffvpBuildPassThroughProgram(ctx)
  int ctx;
{
  int texUnitIndex;
  int clipCopyOutSlot;
  int ctxCursor;
  int colorOutSlot;
  int nextOutputSlot;
  uint loopIndex;
  uint hasBackColors;
  code *hookFn;
  int iVar3;
  int variant;
  undefined4 *builder;
  undefined4 colorInputIndex;
  undefined4 sideFlag;
  undefined4 in_r7;
  undefined4 in_r8;
  uint extraSlotCount;
  uint ctxFlags44;
  int nextTexOutSlot;
  uint outputMask;
  int currentVariant;
  uint hasPointSize;
  int colorOutSlotB;
  uint variantKey [2];
  undefined4 local_60;
  uint local_5c;
  
  if (*(char *)(ctx + 0x1868) == '\0') {
    _memset(variantKey,0,0x30);
    ctxFlags44 = *(uint *)(ctx + 0x44);
    local_60 = *(undefined4 *)(ctx + 0x1804);
    variantKey[0] = variantKey[0] | 8;
    if ((ctxFlags44 & 0xc00) != 0) {
      extraSlotCount = ctxFlags44 >> 9 & 2;
      local_5c = ctxFlags44 >> 0xb & 1 | extraSlotCount | (uint)(byte)((unsigned char *)0x000011d3)[ctx] << 2;
    }
    currentVariant = *(int *)(ctx + 0x14c);
    if ((currentVariant == 0) || (iVar3 = _memcmp(currentVariant,variantKey,0x30), variant = currentVariant, iVar3 != 0)) {
      variant = fpVariantCacheLookup(ctx,variantKey);
      if (variant == 0) {
        outputMask = *(uint *)(ctx + 0x1804);
        builder = (undefined4 *)ffvpCreateBuilder(ctx,0,0);
        builder[0x1a] = 0;
        *builder = 0;
        ctxFlags44 = *(uint *)(ctx + 0x44);
        if ((ctxFlags44 & 0x400) == 0) {
          hasBackColors = outputMask >> 3 & 1;
          hasPointSize = outputMask >> 1 & 1;
          clipCopyOutSlot = 0;
        }
        else {
          hasBackColors = outputMask >> 3 & 1;
          hasPointSize = outputMask >> 1 & 1;
          extraSlotCount = hasBackColors * 2 + (outputMask & 1) + hasPointSize + (uint)(byte)((unsigned char *)0x000011d2)[ctx];
          clipCopyOutSlot = extraSlotCount + 2;
          builder[(byte)((unsigned char *)0x000011d2)[ctx] + 0x21] = clipCopyOutSlot;
          ctxFlags44 = *(uint *)(ctx + 0x44);
        }
        ffvpEmitPositionPassThrough(builder,ctxFlags44 >> 10 & 1,(uint)(byte)((unsigned char *)0x000011d2)[ctx]);
        if (hasPointSize == 0) {
          colorOutSlot = 1;
          colorOutSlotB = 1;
          nextOutputSlot = 2;
          nextTexOutSlot = 2;
        }
        else {
          colorOutSlotB = 2;
          colorOutSlot = 2;
          builder[0x1b] = 1;
          builder[0x13] = 1;
          nextOutputSlot = 3;
          nextTexOutSlot = 3;
          ffvpEmitPointSizePassThrough(builder);
        }
        builder[3] = colorOutSlot;
        builder[0x1d] = colorOutSlotB;
        colorInputIndex = 0;
        sideFlag = 0;
        ffvpEmitColorPassThrough(builder,3,0,0);
        if ((outputMask & 1) != 0) {
          builder[4] = nextOutputSlot;
          builder[0x1f] = nextTexOutSlot;
          colorInputIndex = 1;
          sideFlag = 0;
          ffvpEmitColorPassThrough(builder,4,1,0);
          if ((outputMask & 4) != 0) {
            builder[0x14] = nextOutputSlot;
            builder[0x1c] = nextTexOutSlot;
            builder[0x15] = 3;
            ffvpEmitFogPassThrough(builder);
          }
          nextOutputSlot = colorOutSlot + 2;
          nextTexOutSlot = colorOutSlotB + 2;
        }
        if (hasBackColors != 0) {
          builder[5] = nextOutputSlot;
          builder[0x1e] = nextTexOutSlot;
          ffvpEmitColorPassThrough(builder,3,2,1);
          builder[6] = nextOutputSlot + 1;
          builder[0x20] = nextTexOutSlot + 1;
          colorInputIndex = 3;
          sideFlag = 1;
          nextOutputSlot = nextOutputSlot + 2;
          nextTexOutSlot = nextTexOutSlot + 2;
          ffvpEmitColorPassThrough(builder,4,3,1);
        }
        if (outputMask >> 4 != 0) {
          loopIndex = 0;
          ctxCursor = ctx;
          do {
            texUnitIndex = *(int *)(ctxCursor + 0x1824);
            builder[texUnitIndex + 0xb] = nextOutputSlot;
            nextOutputSlot = nextOutputSlot + 1;
            if (clipCopyOutSlot == nextTexOutSlot) {
              nextTexOutSlot = nextTexOutSlot + 1;
            }
            builder[texUnitIndex + 0x21] = nextTexOutSlot;
            loopIndex = loopIndex + 1;
            ctxCursor = ctxCursor + 4;
            nextTexOutSlot = nextTexOutSlot + 1;
            ffvpEmitTexCoordPassThrough(builder,texUnitIndex,colorInputIndex,sideFlag,in_r7,in_r8,extraSlotCount);
          } while (outputMask >> 4 != loopIndex);
        }
        ffvpFinishProgram(builder);
        if (clipCopyOutSlot == nextTexOutSlot) {
          nextTexOutSlot = nextTexOutSlot + 1;
        }
        variant = fpVariantCacheInsert(ctx,variantKey,builder,nextOutputSlot,nextTexOutSlot,0,0,1);
        *(undefined4 *)(variant + 0x34) = 0;
        *(int *)(variant + 0x38) = *(int *)(*(int *)(variant + 0x54) + 0x3cc) + -1;
        currentVariant = *(int *)(ctx + 0x14c);
      }
      else {
        currentVariant = *(int *)(ctx + 0x14c);
      }
    }
    if (variant != currentVariant) {
      hookFn = *(code **)(((unsigned char *)0x000012d0) + ctx);
      *(int *)(ctx + 0x14c) = variant;
      *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) | 0x40000;
      (*hookFn)(ctx,variant);
    }
  }
  else {
    ffvpSelectPassThroughVariant(ctx);
  }
  return;
}

/* gldEmitVertexRoutingPackets @ 0x837b0 (188 bytes) */
int gldEmitVertexRoutingPackets(param_1)
  int param_1;
{
  undefined4 *a6;
  int iVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar2;
  code *pcVar3;
  
  ((int (*)())ffvpBuildPassThroughProgram)(param_1);
  ((int (*)())ffvpSetupVertexOutputRouting)(param_1);
  a6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(0x00002748 + param_1 + 4) = a6;
  *a6 = 0x861;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
  a6[2] = 0x10824;
  a6[1] = uVar2;
  a6[3] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
  a6[5] = 0x82d;
  a6[4] = uVar2;
  uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
  a6[7] = ((unsigned char *)0x00001047U);
  a6[6] = uVar2;
  a6[8] = *(undefined4 *)(param_1 + 0x1bb0);
  iVar1 = *(int *)(0x00002748 + param_1 + 4);
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = iVar1 + 0x24;
  (*pcVar3)(param_1,iVar1 + 0x24,in_r5,in_r6,in_r7,in_r8,a6);
  return FUN_0004e880(param_1);
}

/* ffvpValidateProgram @ 0x83870 (1012 bytes) */
void ffvpValidateProgram(int ctx,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double fparam_9)
{
  int program;
  int recordCountdown;
  int variant;
  char dirtyFlag;
  uint recordWord0;
  int prevProgramKind;
  int recordCursor;
  uint *record;
  uint src0Reg;
  code *hookFn;
  undefined4 paramList;
  undefined4 *depRecord;
  int dependencyStatus;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 *depRecordCopy;
  undefined4 depElemSize;
  uint src1Reg;
  uint loopIndex;
  int programKind;
  undefined4 in_r10;
  uint src2Reg;
  double validateResult;
  undefined8 lookupResult;
  double unusedStackArg;
  undefined4 builtConstBytes;
  undefined4 constRegCount [5];
  
  *(undefined1 *)(ctx + 0x126) = 0;
  *(undefined4 *)(ctx + 0x1b98) = 0;
  dirtyFlag = *(char *)(ctx + 0x29);
  ((void (*)())gldValidateState)(ctx,unusedArg2,unusedArg3,unusedArg4,unusedArg5,unusedArg6,unusedArg7,unusedFloatArg1,unusedFloatArg2,unusedFloatArg3,
               unusedFloatArg4,unusedFloatArg5,unusedFloatArg6,unusedFloatArg7,unusedFloatArg8,unusedStackArg);
  if (dirtyFlag == '\0') {
    programKind = *(int *)(ctx + 0x13c);
    if (programKind == *(int *)(ctx + 0x140)) {
      prevProgramKind = *(int *)(ctx + 0x148);
      if (prevProgramKind == *(int *)(ctx + 0x144)) {
        return;
      }
    }
    else {
      prevProgramKind = *(int *)(ctx + 0x148);
    }
  }
  else {
    programKind = *(int *)(ctx + 0x13c);
    prevProgramKind = *(int *)(ctx + 0x148);
  }
  *(int *)(ctx + 0x140) = programKind;
  *(int *)(ctx + 0x144) = prevProgramKind;
  if (*(char *)(ctx + 0x124) == '\0') {
    if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
      return;
    }
    lookupResult = fpVariantCacheLookup(ctx,ctx + 0x1874);
    variant = (int)((ulonglong)lookupResult >> 0x20);
    if (variant == 0) {
      ffvpUpdateLightModelFlags(ctx,(int)lookupResult,unusedArg3,unusedArg4,unusedArg5,unusedArg6);
      paramList = paramListCreate(ctx);
      programKind = ffvpBuildProgram(ctx,0,&builtConstBytes,constRegCount,paramList,unusedArg6,programKind,in_r10);
      variant = fpVariantCacheInsert(ctx,ctx + 0x1874,programKind,(uint)*(byte *)(ctx + 0x131),builtConstBytes
                           ,constRegCount[0],paramList,(uint)*(byte *)(ctx + 0x126));
      depRecord = (undefined4 *)
               FUN_000774c0(*(undefined4 *)(ctx + 0xc),*(undefined4 *)(ctx + 0x18));
      depRecord[8] = 0;
      depRecord[9] = 0;
      *depRecord = 0x460;
      depRecord[3] = 0x20;
      depElemSize = 0x10;
      depRecordCopy = depRecord;
      dependencyStatus = fpVariantEntryRecomputeDependencies(ctx,variant,depRecord,0x10);
      FUN_0007a110(depRecord);
      if (*(uint *)(programKind + 0x3cc) <= *(uint *)(programKind + 0x3e4)) {
        *(undefined1 *)(variant + 0x59) = 0;
        *(undefined1 *)(ctx + 0x126) = 0;
      }
      if (*(char *)(ctx + 0x126) == '\0') {
        if (dependencyStatus == 0) {
          program = *(int *)(variant + 0x54);
          recordCountdown = *(int *)(program + 0x3cc);
          *(undefined4 *)(variant + 0x38) = 0;
          if (recordCountdown != 0) {
            recordCursor = recordCountdown * 0x10 + *(int *)(program + 0x3c8);
            do {
              if ((((*(uint *)(recordCursor + -0xc) & 7) == 1) || ((*(uint *)(recordCursor + -8) & 7) == 1)) ||
                 ((*(uint *)(recordCursor + -4) & 7) == 1)) {
                *(int *)(variant + 0x38) = recordCountdown + -1;
              }
              recordCountdown = recordCountdown + -1;
            } while ((recordCountdown != 0) && (recordCursor = recordCursor + -0x10, *(int *)(variant + 0x38) == 0));
          }
        }
        else {
          program = *(int *)(variant + 0x54);
        }
        record = *(uint **)(program + 0x3c8);
        if (*(int *)(program + 0x3cc) != 0) {
          loopIndex = 0;
          do {
            recordWord0 = *record;
            if ((recordWord0 & 0x3f) == 4) {
              if ((((record[1] & 7) == 0) && ((record[2] & 7) == 0)) && ((record[3] & 7) == 0)) {
                src0Reg = record[1] >> 5 & 0xff;
                src1Reg = record[2] >> 5 & 0xff;
                if (((src0Reg != src1Reg) && (src2Reg = record[3] >> 5 & 0xff, src0Reg != src2Reg)) &&
                   (src1Reg != src2Reg)) {
                  *record = recordWord0 & 0xffffffc0 | 0x80;
                  program = *(int *)(variant + 0x54);
                }
              }
            }
            else if ((((recordWord0 & 0x3f) == 0xb) && ((record[1] & 7) == 0)) &&
                    (((record[2] & 7) == 0 && ((record[3] & 7) == 0)))) {
              src0Reg = record[1] >> 5 & 0xff;
              src1Reg = record[2] >> 5 & 0xff;
              if (((src0Reg != src1Reg) && (src2Reg = record[3] >> 5 & 0xff, src0Reg != src2Reg)) &&
                 (src1Reg != src2Reg)) {
                *record = recordWord0 & 0xffffffc0 | 0x81;
                program = *(int *)(variant + 0x54);
              }
            }
            loopIndex = loopIndex + 1;
            record = record + 4;
          } while (loopIndex < *(uint *)(program + 0x3cc));
        }
LAB_00083c10:
        if (variant != *(int *)(ctx + 0x14c)) {
          *(int *)(ctx + 0x14c) = variant;
          hookFn = *(code **)(((unsigned char *)0x000012d0) + ctx);
          *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) | 0x40000;
          (*hookFn)(ctx,variant);
        }
        (**(code **)(((unsigned char *)0x000012c4) + ctx))(ctx,variant);
        return;
      }
      *(undefined1 *)(ctx + 0x2435) = 1;
      *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) | 0x40000000;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1020;
      validateResult = (double)FUN_000a7d10(ctx);
      *(undefined1 *)(ctx + 0x29) = 1;
      ((void (*)())gldValidateState)(ctx,extraout_r4,depRecordCopy,depElemSize,builtConstBytes,constRegCount[0],paramList,validateResult,unusedFloatArg2,
                   unusedFloatArg3,unusedFloatArg4,unusedFloatArg5,unusedFloatArg6,unusedFloatArg7,unusedFloatArg8,unusedStackArg);
    }
    else {
      if (*(char *)(variant + 0x59) == '\0') goto LAB_00083c10;
      *(undefined1 *)(ctx + 0x2435) = 1;
      *(uint *)(ctx + 0x8c) = *(uint *)(ctx + 0x8c) | 0x40000000;
      *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1020;
      validateResult = (double)FUN_000a7d10(ctx);
      *(undefined1 *)(ctx + 0x126) = 1;
      *(undefined1 *)(ctx + 0x29) = 1;
      ((void (*)())gldValidateState)(ctx,extraout_r4_00,unusedArg3,unusedArg4,unusedArg5,unusedArg6,programKind,validateResult,unusedFloatArg2,
                   unusedFloatArg3,unusedFloatArg4,unusedFloatArg5,unusedFloatArg6,unusedFloatArg7,unusedFloatArg8,unusedStackArg);
    }
  }
  ((int (*)())gldEmitVertexRoutingPackets)(ctx);
  return;
}

/* ffvpValidateProgramForced @ 0x83c80 (12 bytes) */
void ffvpValidateProgramForced(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  ((void (*)())ffvpValidateProgram)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,fparam_9);
  return;
}

/* FUN_00083c90 @ 0x83c90 (372 bytes) */
int FUN_00083c90(ctx, packet)
  int ctx;
  undefined4 *packet;
{
  uint packedValue;
  uint ctxFlags8c;
  undefined4 regWord;
  uint heightMinus2;
  uint heightMinus1;
  byte clipMode;
  
  clipMode = 4;
  *(undefined4 *)(((unsigned char *)0x0000148c) + ctx) = 0;
  *(undefined1 *)(ctx + 0x3d4) = 1;
  heightMinus2 = *(int *)(((unsigned char *)0x000013f4) + ctx) - 2;
  heightMinus1 = *(int *)(((unsigned char *)0x000013f4) + ctx) - 1;
  DAT_001dbca8 = heightMinus1 & 0x3ff | DAT_001dbca8 & 0xfffffc00;
  DAT_001dbcac = (heightMinus1 & 0x3ff) << 0x14 |
                 (heightMinus2 & 0x3ff) << 10 | heightMinus2 & 0x3ff | DAT_001dbcac & 0xc0000000;
  ctxFlags8c = *(uint *)(ctx + 0x8c);
  if ((ctxFlags8c & 0x8000) != 0) {
    if (*(int *)(ctx + 0xd8) == 2) {
      clipMode = 0xc;
      *(uint *)(ctx + 0x8c) = ctxFlags8c | 0x50000;
    }
    else {
      clipMode = 4;
      *(uint *)(ctx + 0x8c) = ctxFlags8c & 0xffff7fff;
    }
  }
  if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
    *(uint *)(ctx + 0x38) = *(uint *)(ctx + 0x38) | 0x1000;
    *(byte *)(ctx + 0x2d) = clipMode | *(byte *)(ctx + 0x2d);
    *(undefined1 *)(ctx + 0x29) = 1;
  }
  packet[3] = heightMinus2;
  packet[1] = 0;
  *packet = 0x8a1;
  packet[2] = 0x880;
  packet[4] = 0x78882;
  packet[5] = DAT_001dbcb0;
  packet[6] = DAT_001dbcb4;
  packet[7] = DAT_001dbcb8;
  packet[8] = DAT_001dbcbc;
  packet[9] = DAT_001dbcc0;
  packet[10] = DAT_001dbcc4;
  packet[0xb] = DAT_001dbcc8;
  regWord = DAT_001dbccc;
  packet[0xd] = 0x208b4;
  packet[0xc] = regWord;
  packet[0xe] = DAT_001dbcac;
  packet[0xf] = DAT_001fa5e4;
  packedValue = DAT_001dbca8;
  packet[0x11] = 0x8b7;
  packet[0x12] = 0;
  packet[0x10] = packedValue;
  return packet + 0x13;
}

/* arbEmitRecord3Src_op44 @ 0x83e10 (692 bytes) */
int arbEmitRecord3Src_op44(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint src2NegateXBits;
  uint src1SelectWBits;
  uint src0SelectWBits;
  uint src1NegateW;
  uint src0NegateW;
  uint src2FileField;
  uint src1NegateZBits;
  uint src2NegateZBits;
  uint src1NegateYBits;
  uint src2NegateYBits;
  uint src1NegateXBits;
  uint src2SelectWBits;
  uint src1SelectZBits;
  uint src0SelectZBits;
  uint src2SelectZBits;
  uint src1SelectYBits;
  uint src0SelectYBits;
  uint src2IndexBits;
  uint src0SelectXBits;
  uint src2SelectYBits;
  uint src1IndexBits;
  uint src2SelectXBits;
  uint src1SelectXBits;
  uint src0IndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instrCount;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x44;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  src2FileField = src2File & 0xf;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src2IndexBits = (src2Index & 0xff) << 5;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1NegateW = src1Negate[3];
  *(uint *)(instr + 0xc) = src2IndexBits | src2FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (src1NegateW & 1) << 0x1c |
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  src2SelectXBits = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffff0000;
  src2SelectYBits = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfff80000;
  src2SelectZBits = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffc00000;
  src2SelectWBits = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfe000000;
  src2NegateXBits = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfc000000;
  src2NegateYBits = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf8000000;
  src2NegateZBits = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op01 @ 0x840d0 (548 bytes) */
int arbEmitRecord2Src_op01(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 1;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op02 @ 0x84300 (472 bytes) */
int arbEmitRecord1Src_op02(param_1, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate)
  int param_1;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
{
  uint src0NegateYBits;
  uint src0NegateXBits;
  uint src0SelectWBits;
  uint src0SelectZBits;
  uint src0SelectYBits;
  uint src0SelectXBits;
  int instr;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateZBits;
  int iVar7;
  uint src0FileField;
  uint src0IndexBits;
  uint src0IndexBitsB;
  uint oldWord0;
  uint oldWord1;
  undefined4 allocation;
  int iVar14;
  int iVar15;
  
  iVar14 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar14 + 1U) {
    iVar14 = *(uint *)(param_1 + 0x3e0) * 0x10;
    allocation = _calloc(iVar14 + 0x200,1);
    if (iVar14 != 0) {
      _memcpy(allocation,*(undefined4 *)(param_1 + 0x3c8),iVar14);
      _free(*(undefined4 *)(param_1 + 0x3c8));
    }
    *(undefined4 *)(param_1 + 0x3c8) = allocation;
    iVar14 = *(int *)(param_1 + 0x3cc);
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
  }
  iVar15 = *(int *)(param_1 + 0x3c8);
  iVar7 = iVar14 * 0x10;
  src0FileField = src0File & 0xf;
  *(int *)(param_1 + 0x3cc) = iVar14 + 1;
  instr = iVar7 + iVar15;
  *(int *)(param_1 + 0x3dc) = instr;
  *(undefined4 *)(iVar7 + iVar15) = 0;
  *(undefined1 *)(instr + 3) = 2;
  oldWord0 = *(uint *)(iVar7 + iVar15);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(iVar7 + iVar15) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(iVar7 + iVar15) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(iVar7 + iVar15) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(iVar7 + iVar15) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(iVar7 + iVar15) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  src0IndexBitsB = (src0Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBitsB | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  src0IndexBits = (src0Index & 0xff) << 5 | src0FileField | 0x16da000;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField | oldWord1 & 0xf0000000
  ;
  *(uint *)(instr + 4) =
       (src0Negate[3] & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBitsB | src0FileField;
  *(uint *)(instr + 8) = src0IndexBits;
  *(uint *)(instr + 0xc) = src0IndexBits;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* arbEmitRecord2Src_op02 @ 0x844e0 (548 bytes) */
int arbEmitRecord2Src_op02(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 2;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op03 @ 0x84710 (548 bytes) */
int arbEmitRecord2Src_op03(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 3;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord3Src_op04 @ 0x84940 (692 bytes) */
int arbEmitRecord3Src_op04(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint src2NegateXBits;
  uint src1SelectWBits;
  uint src0SelectWBits;
  uint src1NegateW;
  uint src0NegateW;
  uint src2FileField;
  uint src1NegateZBits;
  uint src2NegateZBits;
  uint src1NegateYBits;
  uint src2NegateYBits;
  uint src1NegateXBits;
  uint src2SelectWBits;
  uint src1SelectZBits;
  uint src0SelectZBits;
  uint src2SelectZBits;
  uint src1SelectYBits;
  uint src0SelectYBits;
  uint src2IndexBits;
  uint src0SelectXBits;
  uint src2SelectYBits;
  uint src1IndexBits;
  uint src2SelectXBits;
  uint src1SelectXBits;
  uint src0IndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instrCount;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 4;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  src2FileField = src2File & 0xf;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src2IndexBits = (src2Index & 0xff) << 5;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1NegateW = src1Negate[3];
  *(uint *)(instr + 0xc) = src2IndexBits | src2FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (src1NegateW & 1) << 0x1c |
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  src2SelectXBits = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffff0000;
  src2SelectYBits = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfff80000;
  src2SelectZBits = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffc00000;
  src2SelectWBits = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfe000000;
  src2NegateXBits = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfc000000;
  src2NegateYBits = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf8000000;
  src2NegateZBits = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord3Src_op0b @ 0x84c00 (692 bytes) */
int arbEmitRecord3Src_op0b(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint src2NegateXBits;
  uint src1SelectWBits;
  uint src0SelectWBits;
  uint src1NegateW;
  uint src0NegateW;
  uint src2FileField;
  uint src1NegateZBits;
  uint src2NegateZBits;
  uint src1NegateYBits;
  uint src2NegateYBits;
  uint src1NegateXBits;
  uint src2SelectWBits;
  uint src1SelectZBits;
  uint src0SelectZBits;
  uint src2SelectZBits;
  uint src1SelectYBits;
  uint src0SelectYBits;
  uint src2IndexBits;
  uint src0SelectXBits;
  uint src2SelectYBits;
  uint src1IndexBits;
  uint src2SelectXBits;
  uint src1SelectXBits;
  uint src0IndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instrCount;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xb;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  src2FileField = src2File & 0xf;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src2IndexBits = (src2Index & 0xff) << 5;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1NegateW = src1Negate[3];
  *(uint *)(instr + 0xc) = src2IndexBits | src2FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (src1NegateW & 1) << 0x1c |
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  src2SelectXBits = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffff0000;
  src2SelectYBits = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfff80000;
  src2SelectZBits = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffc00000;
  src2SelectWBits = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfe000000;
  src2NegateXBits = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfc000000;
  src2NegateYBits = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf8000000;
  src2NegateZBits = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord3Src_op0c @ 0x84ec0 (692 bytes) */
int arbEmitRecord3Src_op0c(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate, src2File, src2Index, src2Select, src2Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
  uint src2File;
  uint src2Index;
  uint *src2Select;
  uint *src2Negate;
{
  uint src2NegateXBits;
  uint src1SelectWBits;
  uint src0SelectWBits;
  uint src1NegateW;
  uint src0NegateW;
  uint src2FileField;
  uint src1NegateZBits;
  uint src2NegateZBits;
  uint src1NegateYBits;
  uint src2NegateYBits;
  uint src1NegateXBits;
  uint src2SelectWBits;
  uint src1SelectZBits;
  uint src0SelectZBits;
  uint src2SelectZBits;
  uint src1SelectYBits;
  uint src0SelectYBits;
  uint src2IndexBits;
  uint src0SelectXBits;
  uint src2SelectYBits;
  uint src1IndexBits;
  uint src2SelectXBits;
  uint src1SelectXBits;
  uint src0IndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrArray;
  uint oldWord2;
  uint oldWord3;
  int instrCount;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xc;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  oldWord3 = *(uint *)(instr + 0xc);
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  src2FileField = src2File & 0xf;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src2IndexBits = (src2Index & 0xff) << 5;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1NegateW = src1Negate[3];
  *(uint *)(instr + 0xc) = src2IndexBits | src2FileField | oldWord3 & 0xffffe000;
  *(uint *)(instr + 8) =
       (src1NegateW & 1) << 0x1c |
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  src2SelectXBits = (*src2Select & 7) << 0xd;
  *(uint *)(instr + 0xc) = src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffff0000;
  src2SelectYBits = (src2Select[1] & 7) << 0x10;
  *(uint *)(instr + 0xc) = src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfff80000;
  src2SelectZBits = (src2Select[2] & 7) << 0x13;
  *(uint *)(instr + 0xc) = src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xffc00000;
  src2SelectWBits = (src2Select[3] & 7) << 0x16;
  *(uint *)(instr + 0xc) = src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfe000000;
  src2NegateXBits = (*src2Negate & 1) << 0x19;
  *(uint *)(instr + 0xc) =
       src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xfc000000;
  src2NegateYBits = (src2Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 0xc) =
       src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf8000000;
  src2NegateZBits = (src2Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 0xc) =
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField | oldWord3 & 0xf0000000
  ;
  *(uint *)(instr + 0xc) =
       (src2Negate[3] & 1) << 0x1c |
       src2NegateZBits | src2NegateYBits | src2NegateXBits | src2SelectWBits | src2SelectZBits | src2SelectYBits | src2SelectXBits | src2IndexBits | src2FileField;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op08 @ 0x85180 (548 bytes) */
int arbEmitRecord2Src_op08(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 8;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op07 @ 0x853b0 (548 bytes) */
int arbEmitRecord2Src_op07(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 7;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op0a @ 0x855e0 (548 bytes) */
int arbEmitRecord2Src_op0a(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 10;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op09 @ 0x85810 (548 bytes) */
int arbEmitRecord2Src_op09(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 9;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op0e @ 0x85a40 (424 bytes) */
int arbEmitRecord1Src_op0e(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint srcNegateXBits;
  uint srcSelectWBits;
  uint srcSelectZBits;
  uint srcSelectYBits;
  uint srcSelectXBits;
  uint srcWord;
  uint srcIndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint srcNegateYBits;
  uint srcNegateZBits;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0xe;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  srcIndexBits = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = srcIndexBits | srcFileField | oldWord1 & 0xffffe000;
  srcSelectXBits = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffff0000;
  srcSelectYBits = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfff80000;
  srcSelectZBits = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffc00000;
  srcSelectWBits = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfe000000;
  srcNegateXBits = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfc000000;
  srcNegateYBits = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf8000000;
  srcNegateZBits = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf0000000;
  srcWord = (srcNegate[3] & 1) << 0x1c |
          srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField;
  *(uint *)(instr + 4) = srcWord;
  *(uint *)(instr + 8) = srcWord;
  *(uint *)(instr + 0xc) = srcWord;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op47 @ 0x85bf0 (424 bytes) */
int arbEmitRecord1Src_op47(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint srcNegateXBits;
  uint srcSelectWBits;
  uint srcSelectZBits;
  uint srcSelectYBits;
  uint srcSelectXBits;
  uint srcWord;
  uint srcIndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint srcNegateYBits;
  uint srcNegateZBits;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x47;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  srcIndexBits = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = srcIndexBits | srcFileField | oldWord1 & 0xffffe000;
  srcSelectXBits = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffff0000;
  srcSelectYBits = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfff80000;
  srcSelectZBits = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffc00000;
  srcSelectWBits = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfe000000;
  srcNegateXBits = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfc000000;
  srcNegateYBits = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf8000000;
  srcNegateZBits = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf0000000;
  srcWord = (srcNegate[3] & 1) << 0x1c |
          srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField;
  *(uint *)(instr + 4) = srcWord;
  *(uint *)(instr + 8) = srcWord;
  *(uint *)(instr + 0xc) = srcWord;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op49 @ 0x85da0 (424 bytes) */
int arbEmitRecord1Src_op49(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint srcNegateXBits;
  uint srcSelectWBits;
  uint srcSelectZBits;
  uint srcSelectYBits;
  uint srcSelectXBits;
  uint srcWord;
  uint srcIndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint srcNegateYBits;
  uint srcNegateZBits;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x49;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  srcIndexBits = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = srcIndexBits | srcFileField | oldWord1 & 0xffffe000;
  srcSelectXBits = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffff0000;
  srcSelectYBits = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfff80000;
  srcSelectZBits = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffc00000;
  srcSelectWBits = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfe000000;
  srcNegateXBits = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfc000000;
  srcNegateYBits = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf8000000;
  srcNegateZBits = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf0000000;
  srcWord = (srcNegate[3] & 1) << 0x1c |
          srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField;
  *(uint *)(instr + 4) = srcWord;
  *(uint *)(instr + 8) = srcWord;
  *(uint *)(instr + 0xc) = srcWord;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op4b @ 0x85f50 (424 bytes) */
int arbEmitRecord1Src_op4b(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint srcNegateXBits;
  uint srcSelectWBits;
  uint srcSelectZBits;
  uint srcSelectYBits;
  uint srcSelectXBits;
  uint srcWord;
  uint srcIndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint srcNegateYBits;
  uint srcNegateZBits;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x4b;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  srcIndexBits = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = srcIndexBits | srcFileField | oldWord1 & 0xffffe000;
  srcSelectXBits = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffff0000;
  srcSelectYBits = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfff80000;
  srcSelectZBits = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffc00000;
  srcSelectWBits = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfe000000;
  srcNegateXBits = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfc000000;
  srcNegateYBits = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf8000000;
  srcNegateZBits = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf0000000;
  srcWord = (srcNegate[3] & 1) << 0x1c |
          srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField;
  *(uint *)(instr + 4) = srcWord;
  *(uint *)(instr + 8) = srcWord;
  *(uint *)(instr + 0xc) = srcWord;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord1Src_op43 @ 0x86100 (424 bytes) */
int arbEmitRecord1Src_op43(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint srcNegateXBits;
  uint srcSelectWBits;
  uint srcSelectZBits;
  uint srcSelectYBits;
  uint srcSelectXBits;
  uint srcWord;
  uint srcIndexBits;
  int instr;
  int oldArrayBytes;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint srcNegateYBits;
  uint srcNegateZBits;
  int instrOffset;
  uint srcFileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x43;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  srcFileField = srcFile & 0xf;
  srcIndexBits = (srcIndex & 0xff) << 5;
  *(uint *)(instr + 4) = srcIndexBits | srcFileField | oldWord1 & 0xffffe000;
  srcSelectXBits = (*srcSelect & 7) << 0xd;
  *(uint *)(instr + 4) = srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffff0000;
  srcSelectYBits = (srcSelect[1] & 7) << 0x10;
  *(uint *)(instr + 4) = srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfff80000;
  srcSelectZBits = (srcSelect[2] & 7) << 0x13;
  *(uint *)(instr + 4) = srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xffc00000;
  srcSelectWBits = (srcSelect[3] & 7) << 0x16;
  *(uint *)(instr + 4) = srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfe000000;
  srcNegateXBits = (*srcNegate & 1) << 0x19;
  *(uint *)(instr + 4) =
       srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xfc000000;
  srcNegateYBits = (srcNegate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf8000000;
  srcNegateZBits = (srcNegate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField | oldWord1 & 0xf0000000;
  srcWord = (srcNegate[3] & 1) << 0x1c |
          srcNegateZBits | srcNegateYBits | srcNegateXBits | srcSelectWBits | srcSelectZBits | srcSelectYBits | srcSelectXBits | srcIndexBits | srcFileField;
  *(uint *)(instr + 4) = srcWord;
  *(uint *)(instr + 8) = srcWord;
  *(uint *)(instr + 0xc) = srcWord;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op45 @ 0x862b0 (548 bytes) */
int arbEmitRecord2Src_op45(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x45;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* arbEmitRecord2Src_op4f @ 0x864e0 (548 bytes) */
int arbEmitRecord2Src_op4f(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  uint *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  int instr;
  int oldArrayBytes;
  uint src1NegateXBits;
  uint src0SelectWBits;
  uint src0NegateW;
  uint src1NegateZBits;
  uint src1NegateYBits;
  uint src1SelectWBits;
  uint src0SelectZBits;
  uint src1SelectZBits;
  uint src0SelectYBits;
  uint src1SelectYBits;
  uint src0SelectXBits;
  uint src1IndexBits;
  uint src1Word;
  uint src1SelectXBits;
  uint src0IndexBits;
  uint dstFileBits;
  uint dstIndexBits;
  uint dstMaskXBits;
  uint dstMaskYBits;
  uint dstMaskZBits;
  uint src0NegateXBits;
  uint src0NegateYBits;
  uint src0NegateZBits;
  int instrOffset;
  uint src0FileField;
  uint src1FileField;
  uint oldWord1;
  uint oldWord0;
  undefined4 newStorage;
  int instrCount;
  int instrArray;
  uint oldWord2;
  
  instrCount = *(int *)(ctx + ARB_instrCount);
  if (*(uint *)(ctx + ARB_instrCapacity) < instrCount + 1U) {
    oldArrayBytes = *(uint *)(ctx + ARB_instrCapacity) * 0x10;
    newStorage = _calloc(oldArrayBytes + 0x200,1);
    if (oldArrayBytes != 0) {
      _memcpy(newStorage,*(undefined4 *)(ctx + ARB_instrArray),oldArrayBytes);
      _free(*(undefined4 *)(ctx + ARB_instrArray));
    }
    *(undefined4 *)(ctx + ARB_instrArray) = newStorage;
    instrCount = *(int *)(ctx + ARB_instrCount);
    *(int *)(ctx + ARB_instrCapacity) = *(int *)(ctx + ARB_instrCapacity) + 0x20;
  }
  instrArray = *(int *)(ctx + ARB_instrArray);
  instrOffset = instrCount * 0x10;
  *(int *)(ctx + ARB_instrCount) = instrCount + 1;
  instr = instrOffset + instrArray;
  *(int *)(ctx + ARB_currentInstr) = instr;
  *(undefined4 *)(instrOffset + instrArray) = 0;
  *(undefined1 *)(instr + 3) = 0x4f;
  oldWord0 = *(uint *)(instrOffset + instrArray);
  dstFileBits = (dstFile & 0xf) << 8;
  dstIndexBits = (dstIndex & 0x7f) << 0xd;
  *(uint *)(instrOffset + instrArray) = dstIndexBits | dstFileBits | oldWord0 & 0xfff010ff;
  dstMaskXBits = (*dstMask & 1) << 0x14;
  *(uint *)(instrOffset + instrArray) = dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffe010ff;
  dstMaskYBits = (dstMask[1] & 1) << 0x15;
  *(uint *)(instrOffset + instrArray) = dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xffc010ff;
  dstMaskZBits = (dstMask[2] & 1) << 0x16;
  *(uint *)(instrOffset + instrArray) = dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff8010ff;
  *(uint *)(instrOffset + instrArray) =
       (dstMask[3] & 1) << 0x17 | dstMaskZBits | dstMaskYBits | dstMaskXBits | dstIndexBits | dstFileBits | oldWord0 & 0xff0010ff;
  oldWord1 = *(uint *)(instr + 4);
  oldWord2 = *(uint *)(instr + 8);
  src0FileField = src0File & 0xf;
  src1FileField = src1File & 0xf;
  src0IndexBits = (src0Index & 0xff) << 5;
  src1IndexBits = (src1Index & 0xff) << 5;
  *(uint *)(instr + 4) = src0IndexBits | src0FileField | oldWord1 & 0xffffe000;
  src0SelectXBits = (*src0Select & 7) << 0xd;
  *(uint *)(instr + 4) = src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffff0000;
  src0SelectYBits = (src0Select[1] & 7) << 0x10;
  *(uint *)(instr + 4) = src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfff80000;
  src0SelectZBits = (src0Select[2] & 7) << 0x13;
  *(uint *)(instr + 4) = src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xffc00000;
  src0SelectWBits = (src0Select[3] & 7) << 0x16;
  *(uint *)(instr + 4) = src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfe000000;
  src0NegateXBits = (*src0Negate & 1) << 0x19;
  *(uint *)(instr + 4) =
       src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xfc000000;
  src0NegateYBits = (src0Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 4) =
       src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf8000000;
  src0NegateZBits = (src0Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 4) =
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField | oldWord1 & 0xf0000000
  ;
  src0NegateW = src0Negate[3];
  *(uint *)(instr + 8) = src1IndexBits | src1FileField | oldWord2 & 0xffffe000;
  *(uint *)(instr + 4) =
       (src0NegateW & 1) << 0x1c |
       src0NegateZBits | src0NegateYBits | src0NegateXBits | src0SelectWBits | src0SelectZBits | src0SelectYBits | src0SelectXBits | src0IndexBits | src0FileField;
  src1SelectXBits = (*src1Select & 7) << 0xd;
  *(uint *)(instr + 8) = src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffff0000;
  src1SelectYBits = (src1Select[1] & 7) << 0x10;
  *(uint *)(instr + 8) = src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfff80000;
  src1SelectZBits = (src1Select[2] & 7) << 0x13;
  *(uint *)(instr + 8) = src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xffc00000;
  src1SelectWBits = (src1Select[3] & 7) << 0x16;
  *(uint *)(instr + 8) = src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfe000000;
  src1NegateXBits = (*src1Negate & 1) << 0x19;
  *(uint *)(instr + 8) =
       src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xfc000000;
  src1NegateYBits = (src1Negate[1] & 1) << 0x1a;
  *(uint *)(instr + 8) =
       src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf8000000;
  src1NegateZBits = (src1Negate[2] & 1) << 0x1b;
  *(uint *)(instr + 8) =
       src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField | oldWord2 & 0xf0000000
  ;
  src1Word = (src1Negate[3] & 1) << 0x1c |
          src1NegateZBits | src1NegateYBits | src1NegateXBits | src1SelectWBits | src1SelectZBits | src1SelectYBits | src1SelectXBits | src1IndexBits | src1FileField;
  *(uint *)(instr + 0xc) = src1Word;
  *(uint *)(instr + 8) = src1Word;
  *(int *)(ctx + ARB_currentInstr) = *(int *)(ctx + ARB_currentInstr) + 0x10;
  return;
}

/* FUN_00086710 @ 0x86710 (152 bytes) */
int FUN_00086710(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
  *puVar1 = 0x880;
  uVar2 = *(undefined4 *)(param_1 + 0x244c);
  puVar1[2] = 0x38882;
  puVar1[1] = uVar2;
  puVar1[3] = *(undefined4 *)(param_1 + 400);
  puVar1[4] = *(undefined4 *)(param_1 + 0x194);
  puVar1[5] = *(undefined4 *)(param_1 + 0xf0);
  puVar1[6] = *(undefined4 *)(param_1 + 0x198);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 0x1c;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,*(int *)(0x00002748 + param_1 + 4));
  return;
}

/* FUN_000867b0 @ 0x867b0 (140 bytes) */
int FUN_000867b0(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint loopCounter;
  int remaining;
  
  uVar3 = *(uint *)(param_1 + 0x1930);
  loopCounter = 0;
  remaining = 6;
  uVar2 = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  do {
    if (((int)(uint)*(ushort *)(param_1 + 0x36) >> (loopCounter & 0x3f) & 1U) != 0) {
      uVar1 = 1 << (loopCounter & 0x3f);
      if ((uVar2 & uVar1) == 0) {
        *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & ~uVar1;
      }
      else {
        uVar3 = uVar3 | 0x1000000;
        *(uint *)(param_1 + 0x1930) = uVar3;
        *(uint *)(param_1 + 0x1b74) = uVar1 | *(uint *)(param_1 + 0x1b74);
      }
    }
    loopCounter = loopCounter + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(uint *)(param_1 + 0x1930) = uVar3 | 0x400000;
  *(undefined2 *)(param_1 + 0x36) = 0;
  return;
}

/* gldUploadClipPlanes @ 0x86840 (228 bytes) */
int gldUploadClipPlanes(ctx)
  int ctx;
{
  int cmdPos;
  bool morePlanes;
  int regBase;
  code *streamSetCurrent;
  undefined4 *a6;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint clipPlaneMask;
  uint loopCounter;
  undefined4 *planeEquation;
  
  planeEquation = (undefined4 *)(ctx + 0x3d8);
  loopCounter = 0;
  clipPlaneMask = *(uint *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(ctx + 4) + 0x10));
  do {
    if ((clipPlaneMask & 1 << (loopCounter & 0x3f)) != 0) {
      a6 = (undefined4 *)(**(code **)(ctx + 0x2758))(ctx,7);
      *(undefined4 **)(0x00002748 + ctx + 4) = a6;
      *a6 = 0x880;
      regBase = *(int *)(ctx + 0x1be0);
      a6[2] = 0x38882;
      a6[1] = loopCounter + regBase;
      a6[3] = *planeEquation;
      a6[4] = planeEquation[1];
      a6[5] = planeEquation[2];
      a6[6] = planeEquation[3];
      cmdPos = *(int *)(0x00002748 + ctx + 4);
      streamSetCurrent = *(code **)(ctx + 0x275c);
      *(int *)(0x00002748 + ctx + 4) = cmdPos + 0x1c;
      (*streamSetCurrent)(ctx,cmdPos + 0x1c,in_r5,in_r6,in_r7,in_r8,a6);
    }
    morePlanes = loopCounter != 5;
    planeEquation = planeEquation + 4;
    loopCounter = loopCounter + 1;
  } while (morePlanes);
  return;
}

/* FUN_00086930 @ 0x86930 (204 bytes) */
int FUN_00086930(int param_1,double fparam_1,double fparam_2)
{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 0x284c)) - DOUBLE_001aa250)
          * FLOAT_001aa170 + (float)(fparam_1 + fparam_2);
  if (fVar1 == FLOAT_001aa0d4) {
    return 0;
  }
  if (fVar1 != FLOAT_001aa174) {
    fVar2 = FLOAT_001aa17c;
    if ((FLOAT_001aa178 <= fVar1) && (fVar2 = FLOAT_001aa184, fVar1 <= FLOAT_001aa180)) {
      fVar2 = fVar1 * FLOAT_001aa0f8;
    }
    return (int)fVar2;
  }
  return -0x10;
}

/* FUN_00086a10 @ 0x86a10 (96 bytes) */
int FUN_00086a10(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  float *param_3;
{
  undefined2 uVar1;
  
  if (param_3 == (float *)0x0) {
    uVar1 = ((int (*)())FUN_00086930)(param_1,(double)*(float *)(param_2 + 0x20),(double)FLOAT_001aa0d4);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  else {
    uVar1 = ((int (*)())FUN_00086930)(param_1,(double)*(float *)(param_2 + 0x20),(double)*param_3);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
  }
  return;
}

/* gldSaveRasterState @ 0x86a80 (284 bytes) */
int gldSaveRasterState(glContext, snapshot)
  int glContext;
  undefined4 *snapshot;
{
  *snapshot = *(undefined4 *)(glContext + 0x1b74);
  snapshot[1] = *(undefined4 *)(glContext + 0x1b84);
  snapshot[2] = *(undefined4 *)(glContext + 0x1b30);
  snapshot[3] = *(undefined4 *)(glContext + 0x1aa0);
  snapshot[4] = *(undefined4 *)(glContext + 0x1ab0);
  snapshot[5] = *(undefined4 *)(glContext + 0x1aa4);
  snapshot[6] = *(undefined4 *)(glContext + 0x1aa8);
  snapshot[8] = *(undefined4 *)(glContext + 0x1ab8);
  snapshot[9] = *(undefined4 *)(glContext + 0x1aec);
  snapshot[10] = *(undefined4 *)(glContext + 0x1a4c);
  snapshot[0xb] = *(undefined4 *)(glContext + 0x1a50);
  snapshot[0xc] = *(undefined4 *)(glContext + 0x1a80);
  snapshot[0xd] = *(undefined4 *)(glContext + 0x1af8);
  snapshot[0xe] = *(undefined4 *)(glContext + 0x1b9c);
  snapshot[0xf] = *(undefined4 *)(glContext + 0x1ba0);
  snapshot[0x10] = *(undefined4 *)(glContext + 0x248c);
  snapshot[0x11] = **(undefined4 **)(glContext + 0x2440);
  snapshot[0x12] = **(undefined4 **)(glContext + 0x2444);
  snapshot[0x15] = *(undefined4 *)(glContext + 0x1ae0);
  snapshot[0x13] = *(undefined4 *)(glContext + 7000);
  snapshot[0x14] = *(undefined4 *)(glContext + 0x1b10);
  snapshot[0x16] = *(undefined4 *)(glContext + 0x1b3c);
  snapshot[0x17] = *(undefined4 *)(0x00001af4 + glContext);
  snapshot[0x18] = *(undefined4 *)(glContext + 0x1b50);
  snapshot[0x19] = *(undefined4 *)(glContext + 0x1f2c);
  snapshot[0x1a] = *(undefined4 *)(glContext + 0x1a60);
  snapshot[0x1b] = *(undefined4 *)(glContext + 0x1a68);
  snapshot[0x1c] = *(undefined4 *)(glContext + 0x1a6c);
  snapshot[0x1d] = *(undefined4 *)(glContext + 0x1b60);
  snapshot[0x1e] = *(undefined4 *)(glContext + 0x23e0);
  snapshot[0x1f] = *(undefined4 *)(glContext + 0x1c8c);
  snapshot[0x20] = *(undefined4 *)(glContext + 0x1c94);
  snapshot[0x21] = *(undefined4 *)(glContext + 0x1bc0);
  snapshot[0x22] = *(undefined4 *)(glContext + 0x1bb0);
  return;
}

/* gldEnterInternalDrawState @ 0x86ba0 (1840 bytes) */
int gldEnterInternalDrawState(glContext, resetReg1af4, modeBitsB, modeBitsA, savedState)
  int glContext;
  int resetReg1af4;
  uint modeBitsB;
  uint modeBitsA;
  undefined4 savedState;
{
  uint scaledXField;
  bool modeBitsBIsZero;
  uint reg1aa4Value;
  uint *ringFlagPtr;
  undefined4 *packet;
  uint a2;
  undefined4 regValue;
  undefined4 a4;
  undefined4 a5;
  uint oldReg1b10;
  code *a6;
  undefined4 *packetTail;
  int stateBlock;
  undefined4 savedWord1930;
  
  modeBitsBIsZero = modeBitsB == 0;
  a2 = modeBitsB;
  ((int (*)())gldSaveRasterState)(glContext,savedState);
  *(undefined4 *)(glContext + 0x1c8c) = *(undefined4 *)(glContext + 0x2814);
  *(undefined4 *)(glContext + 0x1c94) = *(undefined4 *)(glContext + 0x2818);
  *(undefined4 *)(glContext + 0x23e0) = 0;
  *(uint *)(glContext + 0x1aa0) = modeBitsA & 1 | (modeBitsB & 1) << 1 | (modeBitsB & 1) << 2;
  *(uint *)(glContext + 0x1b74) = *(uint *)(glContext + 0x1b74) & 0xffff3fff | 0x1c000;
  *(uint *)(glContext + 0x1b84) = *(uint *)(glContext + 0x1b84) & 0xffffffc5 | 5;
  if (modeBitsBIsZero) {
    reg1aa4Value = *(uint *)(glContext + 0x1aa4) & 0xfffffff8;
    *(uint *)(glContext + 0x1aa4) = reg1aa4Value;
  }
  else {
    reg1aa4Value = *(uint *)(glContext + 0x1aa4) & 0xfffffff8 | 7;
    *(uint *)(glContext + 0x1aa4) = reg1aa4Value;
  }
  if (modeBitsA == 0) {
    *(uint *)(glContext + 0x1aa4) = reg1aa4Value & 0xffffffc7;
  }
  else {
    stateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
    *(uint *)(glContext + 0x1aa4) = reg1aa4Value & 0xff1c71c7 | 0x438438;
    *(char *)(glContext + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x00002db4) + stateBlock);
    *(char *)(glContext + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + stateBlock);
  }
  regValue = 0;
  a5 = 2;
  a4 = 0xf;
  *(undefined4 *)(glContext + 0x1a80) = 0x20200000;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xffffff0f;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xffffe0ff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xffffdfff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xffffbfff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xffff7fff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xff0fffff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xe0ffffff | 0x1000000;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) | 0x20000000;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0xbfffffff;
  **(uint **)(glContext + 0x2440) = **(uint **)(glContext + 0x2440) & 0x7fffffff;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfffffff8;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xffff0fff | 0xf000;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfff8ffff;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(glContext + 0x2444) = **(uint **)(glContext + 0x2444) & 0xfffffff | 0xf0000000;
  if (*(int *)(glContext + 8) == 0xc) {
    oldReg1b10 = *(uint *)(glContext + 0x1b10);
    *(uint *)(glContext + 7000) = *(uint *)(glContext + 7000) & 0xfc000000;
    scaledXField = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(glContext + 4) + 0x15c) ^ 0x80000000) -
                         4503601774854144.0) * *(float *)(glContext + 0x2814) + 0.0) & 0x1fff;
    *(uint *)(glContext + 0x1b10) = scaledXField | oldReg1b10 & 0xffffe000;
    *(uint *)(glContext + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(glContext + 4) + 0x160) ^ 0x80000000) -
                       4503601774854144.0) * *(float *)(glContext + 0x2818) + 0.0) & 0x1fffU) << 0xd |
         scaledXField | oldReg1b10 & 0xfc000000;
  }
  else {
    oldReg1b10 = *(uint *)(glContext + 0x1b10);
    *(uint *)(glContext + 7000) = *(uint *)(glContext + 7000) & 0xfc000000;
    scaledXField = (int)((float)((double)CONCAT44(0x43300000,
                                           *(uint *)(*(int *)(glContext + 4) + 0x15c) ^ 0x80000000) -
                         4503601774854144.0) * *(float *)(glContext + 0x2814) + 0.0) & 0x1fff;
    *(uint *)(glContext + 0x1b10) = scaledXField | oldReg1b10 & 0xffffe000;
    *(uint *)(glContext + 0x1b10) =
         ((int)((float)((double)CONCAT44(0x43300000,
                                         *(uint *)(*(int *)(glContext + 4) + 0x160) ^ 0x80000000) -
                       4503601774854144.0) * *(float *)(glContext + 0x2818) + 0.0) & 0x1fffU) << 0xd |
         scaledXField | oldReg1b10 & 0xfc000000;
  }
  *(undefined4 *)(glContext + 0x1b9c) = 3;
  *(undefined4 *)(glContext + 0x1b30) = 0;
  *(undefined4 *)(glContext + 0x248c) = 8;
  *(undefined4 *)(glContext + 0x1b60) = 0xffffff;
  *(uint *)(glContext + 0x1b50) = (uint)*(ushort *)(glContext + 0x1b52);
  *(undefined4 *)(glContext + 0x1aec) = 0;
  *(undefined4 *)(glContext + 0x1a4c) = 0;
  *(undefined4 *)(glContext + 0x1a50) = 0;
  *(undefined4 *)(glContext + 0x1af8) = 0;
  *(undefined4 *)(glContext + 0x1ba0) = 0;
  *(undefined4 *)(glContext + 0x1bb0) = 0;
  *(undefined4 *)(glContext + 0x1bc0) = 0;
  if (resetReg1af4 == 0) {
    *(undefined4 *)(0x00001af4 + glContext) = 0;
  }
  savedWord1930 = *(undefined4 *)(glContext + 0x1930);
  *(undefined4 *)(glContext + 0x1b3c) = 0;
  FUN_0004b480(glContext,*(uint *)(glContext + 0x18a4) >> 6 & 0xffff);
  a6 = *(code **)(((unsigned char *)0x00001330) + glContext);
  *(uint *)(glContext + 0x1f2c) = *(uint *)(glContext + 0x1f2c) & 0xfffff800 | 0x80;
  (*a6)(glContext,0xc0100000,a2,regValue,a4,a5,a6);
  *(undefined4 *)(glContext + 0x1930) = savedWord1930;
  if (!modeBitsBIsZero) {
    *(uint *)(glContext + 0x1ae0) = *(uint *)(glContext + 0x1ae0) & 0xfffffffe;
    *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) & 0xfffffffe;
  }
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x3d);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  packetTail = packet + 0x34;
  *packet = 0x887;
  regValue = *(undefined4 *)(glContext + 0x1b74);
  packet[2] = 0x82c;
  packet[1] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b84);
  packet[4] = ((unsigned char *)0x000010aeU);
  packet[3] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b30);
  packet[6] = ((unsigned char *)0x000013c0U);
  packet[5] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa0);
  packet[8] = ((unsigned char *)0x000013c1U);
  packet[7] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa4);
  packet[10] = ((unsigned char *)0x000013c2U);
  packet[9] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa8);
  packet[0xc] = ((unsigned char *)0x000012f0U);
  packet[0xb] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aec);
  packet[0xe] = ((unsigned char *)0x000012f5U);
  packet[0xd] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1a4c);
  packet[0x10] = ((unsigned char *)0x000012f6U);
  packet[0xf] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1a50);
  packet[0x12] = ((unsigned char *)0x00001381U);
  packet[0x11] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1a80);
  packet[0x14] = ((unsigned char *)0x00001386U);
  packet[0x13] = regValue;
  packet[0x15] = *(undefined4 *)(glContext + 0x1af8);
  packet[0x16] = 0x824;
  regValue = *(undefined4 *)(glContext + 0x1b9c);
  packet[0x18] = 0x825;
  packet[0x17] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x1a] = 0x82d;
  packet[0x19] = regValue;
  regValue = *(undefined4 *)(glContext + 0x248c);
  packet[0x1c] = 0x854;
  packet[0x1b] = regValue;
  regValue = **(undefined4 **)(glContext + 0x2440);
  packet[0x1e] = 0x878;
  packet[0x1d] = regValue;
  regValue = **(undefined4 **)(glContext + 0x2444);
  packet[0x20] = ((unsigned char *)0x000010f8U);
  packet[0x1f] = regValue;
  regValue = *(undefined4 *)(glContext + 7000);
  packet[0x22] = ((unsigned char *)0x000010f9U);
  packet[0x21] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b10);
  packet[0x24] = ((unsigned char *)0x000010a2U);
  packet[0x23] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b3c);
  packet[0x26] = ((unsigned char *)0x00001383U);
  packet[0x25] = regValue;
  regValue = *(undefined4 *)(0x00001af4 + glContext);
  packet[0x28] = ((unsigned char *)0x00001002U);
  packet[0x27] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b50);
  packet[0x2a] = ((unsigned char *)0x000010c0U);
  packet[0x29] = regValue;
  packet[0x2b] = *(undefined4 *)(glContext + 0x1f2c);
  packet[0x2c] = 0x825;
  regValue = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x2e] = 0x766;
  packet[0x2d] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1c8c);
  packet[0x30] = 0x768;
  packet[0x2f] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1c94);
  packet[0x32] = ((unsigned char *)0x000010faU);
  packet[0x31] = regValue;
  packet[0x33] = *(undefined4 *)(glContext + 0x1b60);
  if (!modeBitsBIsZero) {
    stateBlock = *(int *)(glContext + 4);
    ringFlagPtr = *(uint **)(stateBlock + 0x1d8);
    *ringFlagPtr = (int)packetTail - (int)ringFlagPtr >> 2 | *ringFlagPtr;
    *(undefined4 **)(stateBlock + 0x1d8) = packetTail;
    packetTail = packet + 0x39;
    packet[0x34] = 0x2f000000;
    packet[0x35] = ((unsigned char *)0x000010e9U);
    regValue = *(undefined4 *)(glContext + 0x1ae0);
    packet[0x37] = ((unsigned char *)0x000013c7U);
    packet[0x36] = regValue;
    packet[0x38] = *(undefined4 *)(glContext + 0x1ab0);
  }
  *packetTail = ((unsigned char *)0x00001048U);
  regValue = *(undefined4 *)(glContext + 0x1bc0);
  packetTail[2] = ((unsigned char *)0x00001047U);
  packetTail[1] = regValue;
  packetTail[3] = *(undefined4 *)(glContext + 0x1bb0);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetTail + 4;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,packetTail + 4);
  return;
}

/* gldLeaveInternalDrawState @ 0x872e0 (1296 bytes) */
int gldLeaveInternalDrawState(glContext, savedState)
  int glContext;
  undefined4 *savedState;
{
  undefined4 *packet;
  char enableFlagByte;
  undefined *flagTable;
  code *hookFn;
  uint *ringFlagPtr;
  undefined4 extraout_r4;
  undefined4 *packetTail;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 regValue;
  uint regValueMasked;
  undefined4 *drawStateWords;
  int stateObject;
  double fparam_1;
  
  drawStateWords = *(undefined4 **)(glContext + 0x2440);
  *(undefined4 *)(glContext + 0x1b74) = *savedState;
  *(undefined4 *)(glContext + 0x1b84) = savedState[1];
  *(undefined4 *)(glContext + 0x1b30) = savedState[2];
  *(undefined4 *)(glContext + 0x1aa0) = savedState[3];
  *(undefined4 *)(glContext + 0x1ab0) = savedState[4];
  *(undefined4 *)(glContext + 0x1aa4) = savedState[5];
  *(undefined4 *)(glContext + 0x1aa8) = savedState[6];
  *(undefined4 *)(glContext + 0x1ab8) = savedState[8];
  *(undefined4 *)(glContext + 0x1aec) = savedState[9];
  *(undefined4 *)(glContext + 0x1a4c) = savedState[10];
  *(undefined4 *)(glContext + 0x1a50) = savedState[0xb];
  *(undefined4 *)(glContext + 0x1a80) = savedState[0xc];
  *(undefined4 *)(glContext + 0x1af8) = savedState[0xd];
  *(undefined4 *)(glContext + 0x1b9c) = savedState[0xe];
  *(undefined4 *)(glContext + 0x1ba0) = savedState[0xf];
  *(undefined4 *)(glContext + 0x248c) = savedState[0x10];
  *drawStateWords = savedState[0x11];
  **(undefined4 **)(glContext + 0x2444) = savedState[0x12];
  *(undefined4 *)(glContext + 0x1ae0) = savedState[0x15];
  *(undefined4 *)(glContext + 7000) = savedState[0x13];
  *(undefined4 *)(glContext + 0x1b10) = savedState[0x14];
  *(undefined4 *)(glContext + 0x1b3c) = savedState[0x16];
  *(undefined4 *)(0x00001af4 + glContext) = savedState[0x17];
  *(undefined4 *)(glContext + 0x1b50) = savedState[0x18];
  *(undefined4 *)(glContext + 0x1f2c) = savedState[0x19];
  *(undefined4 *)(glContext + 0x1a60) = savedState[0x1a];
  *(undefined4 *)(glContext + 0x1a68) = savedState[0x1b];
  *(undefined4 *)(glContext + 0x1a6c) = savedState[0x1c];
  *(undefined4 *)(glContext + 0x1b60) = savedState[0x1d];
  *(undefined4 *)(glContext + 0x23e0) = savedState[0x1e];
  *(undefined4 *)(glContext + 0x1c8c) = savedState[0x1f];
  *(undefined4 *)(glContext + 0x1c94) = savedState[0x20];
  *(undefined4 *)(glContext + 0x1bc0) = savedState[0x21];
  hookFn = *(code **)(((unsigned char *)0x00001334) + glContext);
  regValue = savedState[0x22];
  *(undefined4 *)(glContext + 0x1bb0) = regValue;
  (*hookFn)(glContext,0,in_r5,in_r6,in_r7,in_r8,regValue,drawStateWords);
  if (((*(uint *)(glContext + 0x44) & 0x20000) != 0) &&
     (drawStateWords = *(undefined4 **)(glContext + 0x1e70), drawStateWords != (undefined4 *)0x0)) {
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      enableFlagByte = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      enableFlagByte = ((unsigned char *)0x000011d0)[glContext];
    }
    if (enableFlagByte == '\0') goto LAB_00087474;
  }
  drawStateWords = *(undefined4 **)(glContext + 0x1e5c);
LAB_00087474:
  *(undefined1 *)((int)drawStateWords + 0x10eb) = 0;
  if (*(int *)(glContext + 0x23e0) == 0) {
    *drawStateWords = 0;
    drawStateWords[0x4c0] = 0;
  }
  else {
    drawStateWords[7] = 0;
    drawStateWords[0x54b] = 0;
  }
  ((void (*)())FUN_0004a8f0)(glContext,extraout_r4,in_r5,in_r6,fparam_1);
  (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) & 0x3fefffff;
  packet = (undefined4 *)
           (**(code **)(glContext + 0x2758))
                     (glContext,0x55,in_r5,in_r6,in_r7,in_r8,*(code **)(glContext + 0x2758));
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = 0x887;
  flagTable = PTR_DAT_001e88c8;
  regValue = *(undefined4 *)(glContext + 0x1b74);
  packet[2] = 0x82c;
  packet[1] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b84);
  packet[4] = ((unsigned char *)0x000010aeU);
  packet[3] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b30);
  packet[6] = ((unsigned char *)0x000013c0U);
  packet[5] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa0);
  packet[8] = ((unsigned char *)0x000013c1U);
  packet[7] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa4);
  packet[10] = ((unsigned char *)0x000013c2U);
  packet[9] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1aa8);
  packet[0xc] = ((unsigned char *)0x000012f0U);
  packet[0xb] = regValue;
  regValueMasked = *(uint *)(glContext + 0x1aec);
  packet[0xd] = regValueMasked;
  if ((*(uint *)(flagTable + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0xd] = regValueMasked & 0xfffffffe;
  }
  packet[0xe] = ((unsigned char *)0x000012f5U);
  regValueMasked = *(uint *)(glContext + 0x1a4c);
  packet[0xf] = regValueMasked;
  if ((*(uint *)(flagTable + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0xf] = regValueMasked & 0xfffff7ff;
  }
  packet[0x10] = ((unsigned char *)0x000012f6U);
  regValue = *(undefined4 *)(glContext + 0x1a50);
  packet[0x12] = ((unsigned char *)0x00001381U);
  packet[0x11] = regValue;
  regValueMasked = *(uint *)(glContext + 0x1a80);
  packet[0x13] = regValueMasked;
  if ((*(uint *)(flagTable + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    packet[0x13] = regValueMasked & 0xfffffffc;
  }
  packet[0x14] = ((unsigned char *)0x00001386U);
  packetTail = packet + 0x34;
  regValue = *(undefined4 *)(glContext + 0x1af8);
  packet[0x16] = 0x824;
  packet[0x15] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b9c);
  packet[0x18] = 0x825;
  packet[0x17] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x1a] = 0x82d;
  packet[0x19] = regValue;
  regValue = *(undefined4 *)(glContext + 0x248c);
  packet[0x1c] = 0x854;
  packet[0x1b] = regValue;
  regValue = **(undefined4 **)(glContext + 0x2440);
  packet[0x1e] = 0x878;
  packet[0x1d] = regValue;
  regValue = **(undefined4 **)(glContext + 0x2444);
  packet[0x20] = ((unsigned char *)0x000010a2U);
  packet[0x1f] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b3c);
  packet[0x22] = ((unsigned char *)0x00001383U);
  packet[0x21] = regValue;
  regValue = *(undefined4 *)(0x00001af4 + glContext);
  packet[0x24] = ((unsigned char *)0x00001002U);
  packet[0x23] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b50);
  packet[0x26] = ((unsigned char *)0x000010c0U);
  packet[0x25] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1f2c);
  packet[0x28] = 0x825;
  packet[0x27] = regValue;
  packet[0x29] = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x2a] = ((unsigned char *)0x00001008U);
  regValue = *(undefined4 *)(glContext + 0x1a60);
  packet[0x2c] = ((unsigned char *)0x00001004U);
  packet[0x2b] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1a68);
  packet[0x2e] = ((unsigned char *)0x00001005U);
  packet[0x2d] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1a6c);
  packet[0x30] = ((unsigned char *)0x000010faU);
  packet[0x2f] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1b60);
  packet[0x32] = ((unsigned char *)0x000013c5U);
  packet[0x31] = regValue;
  packet[0x33] = *(undefined4 *)(glContext + 0x1ab8);
  if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
    packet[0x34] = ((unsigned char *)0x000013c5U);
    packetTail = packet + 0x36;
    packet[0x35] = *(undefined4 *)(glContext + 0x1ab8);
  }
  packet = (undefined4 *)gldEmitScissorRegs(glContext,packetTail);
  *packet = 0x766;
  regValue = *(undefined4 *)(glContext + 0x1c8c);
  packet[2] = 0x768;
  packet[1] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1c94);
  packet[4] = ((unsigned char *)0x000010faU);
  packet[3] = regValue;
  packet[5] = *(undefined4 *)(glContext + 0x1b60);
  stateObject = *(int *)(glContext + 4);
  ringFlagPtr = *(uint **)(stateObject + 0x1d8);
  *ringFlagPtr = (int)(packet + 6) - (int)ringFlagPtr >> 2 | *ringFlagPtr;
  *(undefined4 **)(stateObject + 0x1d8) = packet + 6;
  packet[6] = 0x2f000000;
  packet[7] = ((unsigned char *)0x000010e9U);
  regValue = *(undefined4 *)(glContext + 0x1ae0);
  packet[9] = ((unsigned char *)0x000013c7U);
  packet[8] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1ab0);
  packet[0xb] = ((unsigned char *)0x00001048U);
  packet[10] = regValue;
  regValue = *(undefined4 *)(glContext + 0x1bc0);
  packet[0xd] = ((unsigned char *)0x00001047U);
  packet[0xc] = regValue;
  packet[0xe] = *(undefined4 *)(glContext + 0x1bb0);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 0xf;
                    
                    
  (**(code **)(glContext + 0x275c))(glContext,packet + 0xf);
  return;
}

/* arbfpUpdateConstantsFp24 @ 0x87800 (344 bytes) */
int arbfpUpdateConstantsFp24(context, fpProgram, unusedArg3, unusedArg4)
  int context;
  int fpProgram;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
{
  int constRegOffset;
  int slotPtr;
  int fp24X;
  int fp24Y;
  int fp24Z;
  int fp24W;
  int fpInfo;
  int loopIndex;
  int entryOffset;
  int hwConstants;
  int paramEntry;
  float paramX;
  float paramY;
  float paramZ;
  float paramW;
  
  fpInfo = *(int *)(fpProgram + 0x74);
  hwConstants = *(int *)(*(int *)(((unsigned char *)0x00001130) + context) * 4 + *(int *)(fpProgram + 0x70));
  if (0 < *(int *)(fpInfo + 0x84)) {
    loopIndex = 0;
    entryOffset = 0;
    do {
      paramEntry = entryOffset + *(int *)(fpInfo + 0x80);
      if (*(int *)(paramEntry + 8) != 0x34) {
        arbfpFetchParameterValue(context,paramEntry,&paramX,unusedArg4);
        fp24X = ((uint (*)())floatToFp24)((double)paramX);
        fp24Y = ((uint (*)())floatToFp24)((double)paramY);
        fp24Z = ((uint (*)())floatToFp24)((double)paramZ);
        fp24W = ((uint (*)())floatToFp24)((double)paramW);
        constRegOffset = *(int *)(paramEntry + 4) * 0x10;
        slotPtr = constRegOffset + hwConstants;
        if ((((fp24X == *(int *)(slotPtr + 0x8c)) && (fp24Y == *(int *)(slotPtr + 0x90))) &&
            (fp24Z == *(int *)(slotPtr + 0x94))) && (fp24W == *(int *)(slotPtr + 0x98))) {
          fpInfo = *(int *)(fpProgram + 0x74);
        }
        else {
          *(int *)(constRegOffset + hwConstants + 0x8c) = fp24X;
          *(int *)(*(int *)(paramEntry + 4) * 0x10 + hwConstants + 0x90) = fp24Y;
          *(int *)(*(int *)(paramEntry + 4) * 0x10 + hwConstants + 0x94) = fp24Z;
          *(int *)(*(int *)(paramEntry + 4) * 0x10 + hwConstants + 0x98) = fp24W;
          *(undefined4 *)(context + 0x1e64) = 0;
          fpInfo = *(int *)(fpProgram + 0x74);
        }
      }
      loopIndex = loopIndex + 1;
      entryOffset = entryOffset + 0x14;
    } while (loopIndex < *(int *)(fpInfo + 0x84));
  }
  return;
}

/* arbfpInitResourceLimits @ 0x87960 (120 bytes) */
int arbfpInitResourceLimits(param_1)
  int param_1;
{
  *(undefined4 *)(((unsigned char *)0x0000120cU) + param_1) = 0x1ff;
  *(undefined4 *)(((unsigned char *)0x00001200) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011e0) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x00001204) + param_1) = 0x400;
  *(undefined4 *)(((unsigned char *)0x00001214) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x000011f0) + param_1) = 10;
  *(undefined4 *)(((unsigned char *)0x000011d8) + param_1) = 0x400;
  *(undefined4 *)(((unsigned char *)0x000011e4) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011e8) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x000011ec) + param_1) = 10;
  *(undefined4 *)(((unsigned char *)0x000011fc) + param_1) = 0x40;
  *(undefined4 *)(((unsigned char *)0x00001210) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x00001208) + param_1) = 0x200;
  *(undefined4 *)(((unsigned char *)0x000011f8) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x000011dc) + param_1) = 0x8000;
  *(undefined4 *)(((unsigned char *)0x00001218) + param_1) = 4;
  *(undefined4 *)(((unsigned char *)0x000011d4) + param_1) = 0x600;
  *(undefined4 *)(((unsigned char *)0x000011f4) + param_1) = 0;
  return;
}

/* noop_879e0 @ 0x879e0 (4 bytes) */
int noop_879e0()
{
  return;
}

/* FUN_000879f0 @ 0x879f0 (732 bytes) */
int FUN_000879f0(ctx, param_2, compileInfo, hwState, unitState, unitEnabled, hasFogOrSecondary)
  int ctx;
  undefined4 param_2;
  int compileInfo;
  int hwState;
  undefined4 *unitState;
  int unitEnabled;
  int hasFogOrSecondary;
{
  undefined4 uVar1;
  uint regBase;
  int hwCursorA;
  uint uVar4;
  int hwCursorB;
  undefined4 *unitCursor;
  int loopCounter;
  int iVar8;
  int remaining;
  
  iVar8 = 0;
  if (ctx != 0) {
    iVar8 = *(int *)(ctx + 0x276c);
  }
  _memset(unitState,0,0x80);
  loopCounter = 0;
  remaining = 8;
  regBase = 0;
  hwCursorA = hwState;
  hwCursorB = hwState;
  unitCursor = unitState;
  do {
    *unitCursor = 1;
    *(undefined1 *)((int)unitCursor + 0xb) = 0;
    *(undefined2 *)((int)unitCursor + 6) = 0;
    *(undefined1 *)((int)unitCursor + 0xe) = 0;
    *(undefined1 *)((int)unitCursor + 0xf) = 0;
    *(undefined4 *)(hwCursorA + 200) = 0;
    *(undefined1 *)((int)unitCursor + 9) = 0;
    if (*(char *)(loopCounter + unitEnabled) != '\0') {
      *(uint *)(hwCursorB + 0x88) = *(uint *)(hwCursorB + 0x88) & 0xfe001fff | 0xd10000;
      *(uint *)(hwCursorB + 200) =
           (regBase + 3) * 0x40000 |
           (regBase + 2) * 0x1000 | (regBase + 1) * 0x40 | regBase | *(uint *)(hwCursorB + 200) & 0xff000000;
      *(short *)(unitCursor + 1) = (short)loopCounter + 2;
      *(undefined1 *)((int)unitCursor + 9) = 1;
      *(char *)(unitCursor + 2) = (char)loopCounter;
      *(undefined1 *)(unitCursor + 3) = 0;
    }
    unitCursor = unitCursor + 0x12;
    loopCounter = loopCounter + 1;
    hwCursorB = hwCursorB + 4;
    regBase = regBase + 4 & 0x3f;
    hwCursorA = hwCursorA + 4;
    remaining = remaining + -1;
  } while (remaining != 0);
  if (*(char *)(compileInfo + 0x118) != '\0') {
    *(undefined1 *)((int)unitState + 0x24f) = 0;
    *(undefined1 *)((int)unitState + 0x24b) = 0;
    regBase = iVar8 * 4;
    *(undefined1 *)((int)unitState + 0x24a) = 0;
    *(undefined1 *)((int)unitState + 0x24d) = 0;
    *(undefined1 *)((int)unitState + 0x24e) = 0;
    *(undefined2 *)((int)unitState + 0x246) = 0;
    *(undefined1 *)((int)unitState + 0x249) = 1;
    unitState[0x90] = 1;
    hwCursorA = 4;
    *(uint *)(regBase + hwState + 0x88) = *(uint *)(regBase + hwState + 0x88) & 0xfff81fff | 0x10000;
    if (*(int *)(hwState + 0x210) != 2) {
      hwCursorA = 2;
    }
    hwCursorB = regBase + hwState;
    uVar4 = 0x3e;
    *(uint *)(hwCursorB + 0x88) = hwCursorA << 0x13 | *(uint *)(hwCursorB + 0x88) & 0xfe07ffff | 0x1400000;
    *(uint *)(hwCursorB + 200) =
         ((char)regBase + 1) * 0x40 & 0xfc0U | regBase & 0x3c | *(uint *)(hwCursorB + 200) & 0xfffff000;
    if (*(int *)(hwState + 0x210) != 2) {
      uVar4 = (int)(char)regBase + 2U & 0x3e;
    }
    *(uint *)(regBase + hwState + 200) =
         uVar4 << 0xc | *(uint *)(regBase + hwState + 200) & 0xff000fff | 0xfc0000;
    *(char *)(unitState + 0x92) = (char)iVar8;
    uVar1 = *(undefined4 *)(compileInfo + 0x108);
    *(undefined1 *)(unitState + 0x93) = 0;
    *(short *)(unitState + 0x91) = (short)uVar1;
  }
  *(undefined1 *)((int)unitState + 10) = 0;
  *(undefined2 *)((int)unitState + 6) = 0;
  *(undefined1 *)((int)unitState + 0xb) = 1;
  *(undefined1 *)((int)unitState + 0xd) = 0;
  *(uint *)(hwState + 0x88) = *(uint *)(hwState + 0x88) & 0xffffe03f;
  *(uint *)(hwState + 200) = *(uint *)(hwState + 200) & 0x80ffffff;
  if (hasFogOrSecondary == 0) {
    uVar1 = 1;
    iVar8 = 1;
  }
  else {
    uVar1 = 2;
    *(undefined1 *)((int)unitState + 0x55) = 0;
    *(undefined1 *)((int)unitState + 0x53) = 1;
    *(undefined1 *)((int)unitState + 0x52) = 1;
    *(undefined2 *)((int)unitState + 0x4e) = 1;
    iVar8 = 2;
    *(uint *)(hwState + 0x8c) = *(uint *)(hwState + 0x8c) & 0xffffe03f | 0x40;
    *(uint *)(hwState + 0xcc) = *(uint *)(hwState + 0xcc) & 0x80ffffff | 0x1000000;
  }
  *(undefined4 *)(hwState + 0x20c) = uVar1;
  hwCursorA = 0x48;
  *(undefined4 *)(hwState + 0x214) = 0;
  *(uint *)(hwState + 0x208) = iVar8 << 7 | *(uint *)(hwState + 0x208) & 0xfffff87f;
  if (*(char *)(compileInfo + 0x118) == '\0') {
    hwCursorA = 0;
  }
  return (int)unitState + hwCursorA + 0x240;
}

/* FUN_00087cd0 @ 0x87cd0 (188 bytes) */
int FUN_00087cd0(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x124;
  if (param_2 != 0) {
    if (iVar1 == *(int *)(glContext + 0x1e70)) {
      *(undefined4 *)(glContext + 0x1e70) = 0;
    }
    FUN_0004b5d0(glContext,iVar1);
    if (iVar1 == *(int *)(glContext + 0x1e64)) {
      *(undefined4 *)(glContext + 0x1e64) = 0;
    }
    if (*(int *)(((unsigned char *)0x00001488) + glContext) == param_2) {
      *(undefined4 *)(((unsigned char *)0x00001488) + glContext) = 0;
    }
    if (iVar1 == *(int *)(glContext + 0x1e5c)) {
      FUN_0004b480(glContext,1);
      return;
    }
  }
  return;
}

/* FUN_00087da0 @ 0x87da0 (172 bytes) */
int FUN_00087da0(glContext, param_2)
  int glContext;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 + 0x124;
  if (iVar1 == *(int *)(glContext + 0x1e70)) {
    *(undefined4 *)(glContext + 0x1e70) = 0;
  }
  FUN_0004b5d0(glContext,iVar1);
  if (iVar1 == *(int *)(glContext + 0x1e64)) {
    *(undefined4 *)(glContext + 0x1e64) = 0;
  }
  if (*(int *)(((unsigned char *)0x00001488) + glContext) == param_2) {
    *(undefined4 *)(((unsigned char *)0x00001488) + glContext) = 0;
  }
  if (iVar1 == *(int *)(glContext + 0x1e5c)) {
    FUN_0004b480(glContext,1);
    return;
  }
  return;
}

/* FUN_00087e60 @ 0x87e60 (8 bytes) */
int FUN_00087e60()
{
  return ((unsigned char *)0x00003880U);
}

/* FUN_00087e70 @ 0x87e70 (8 bytes) */
int FUN_00087e70()
{
  return ((unsigned char *)0x00003880U);
}

/* arbfpCompileFragmentProgram @ 0x87e80 (764 bytes) */
int arbfpCompileFragmentProgram(ctx, fpRecord, workArea, keyWords)
  undefined4 *ctx;
  int fpRecord;
  int workArea;
  undefined4 *keyWords;
{
  uint bits;
  undefined4 shaderField7c;
  undefined4 statWord;
  undefined4 keyWord1;
  int buildStatus;
  int bitCount;
  int fillPtr;
  int partCountA;
  int partCountB;
  int remaining;
  bool moreRounds;
  uint flags;
  undefined4 modeByte;
  int texEnumValue;
  undefined4 keyWord2;
  int altMode;
  int loopCounter;
  int workAreaState;
  int shaderInfo;
  /* local_48/local_44/local_40/local_3c/local_38/local_34/local_30 are one contiguous 7-word array
   * (&local_48 passed to FUN_000b4400, which internally indexes it keyWords[0]..keyWords[6] - and that
   * value flows straight through into ilRewriteForTextureState as its own keyWords, where keyWords[1] seeds a loop
   * counter). Declared as 7 separate scalars, they landed non-adjacent at -O0 (confirmed live: the
   * value ilRewriteForTextureState read via keyWords[1] was heap-garbage-sized, not the small local_44 value),
   * corrupting a command-stream interpreter loop's iteration count downstream and eventually walking
   * off the end into zeroed memory, hitting the interpreter's own out-of-range-opcode safety net
   * (_exit(0), confirmed present in stock too - not itself a bug). Merged into a real array, aliased
   * back to the original names so the rest of this function's logic is unchanged (issue #64). */
  undefined4 local_48_arr[7];
#define local_48 local_48_arr[0]
#define local_44 local_48_arr[1]
#define local_40 local_48_arr[2]
#define local_3c local_48_arr[3]
#define local_38 local_48_arr[4]
#define local_34 local_48_arr[5]
#define local_30 local_48_arr[6]

  workAreaState = workArea + 0x124;
  modeByte = ctx[0x8f8];
  *(undefined4 *)(((unsigned char *)0x000037cc) + workArea) = 0;
  ((unsigned char *)0x000037e8)[workArea] = (char)modeByte;
  if (workArea == 0) {
    return 0;
  }
  *(int *)(((unsigned char *)0x000037e4) + workArea) = workArea;
  local_38 = 0;
  local_34 = 2;
  local_30 = 0;
  local_40 = 0;
  local_3c = 0;
  keyWord1 = keyWords[1];
  keyWord2 = keyWords[2];
  altMode = ctx[0x8f8];
  *(undefined4 *)(workArea + 4) = *keyWords;
  *(undefined4 *)(workArea + 8) = keyWord1;
  *(undefined4 *)(workArea + 0xc) = keyWord2;
  local_48 = keyWords[2];
  local_44 = *keyWords;
  if (fpRecord != 0) {
    *(undefined4 *)(((unsigned char *)0x000011fc) + workArea) = 0;
    shaderInfo = *(int *)(fpRecord + 0x74);
    texEnumValue = FUN_000abb60(ctx);
    if (texEnumValue == 0x801) {
      local_3c = local_3c | 0xc;
    }
    else if (texEnumValue == 0x2601) {
      local_3c = local_3c | 4;
    }
    else if (texEnumValue == 0x800) {
      local_3c = local_3c | 8;
    }
    if (*(char *)(shaderInfo + 5) != '\0') goto LAB_00088008;
  }
  else {
    local_3c = 2;
    _memset(((unsigned char *)0x00003100) + workArea,0,0x100);
    remaining = 0x10;
    fillPtr = workAreaState;
    do {
      ((unsigned char *)0x00002fdc)[fillPtr] = 1;
      fillPtr = fillPtr + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined4 *)(((unsigned char *)0x000011fc) + workArea) = 0;
  }
  bitCount = ctx[0x917];
  if (bitCount != 0) {
    local_38 = 0;
    do {
      local_38 = local_38 << 1 | 1;
      bitCount = bitCount + -1;
    } while (bitCount != 0);
    local_3c = local_3c | 0x400;
  }
LAB_00088008:
  if (altMode != 0) {
    local_3c = local_3c | 0x100;
    *(undefined4 *)(0x00001830 + workArea) = ctx[0x9db];
  }
  flags = local_3c | 0x80;
  if (*(char *)(workArea + 0x120) != '\0') {
    flags = local_3c | 0x280;
  }
  local_3c = flags;
  buildStatus = FUN_000b4400(ctx,workArea + 0x18a8,workArea + 0x1784,&local_48,workAreaState);
#undef local_48
#undef local_44
#undef local_40
#undef local_3c
#undef local_38
#undef local_34
#undef local_30
  if (buildStatus == 1) {
    return 0xfffffffe;
  }
  if (fpRecord != 0) {
    if (altMode == 0) {
      partCountA = *(int *)(((unsigned char *)0x000037cc) + workArea);
      partCountB = *(int *)(((unsigned char *)0x000037d0) + workArea);
    }
    else {
      partCountA = *(int *)(((unsigned char *)0x000037d8) + workArea);
      partCountB = *(int *)(((unsigned char *)0x000037dc) + workArea);
    }
    if (buildStatus == 0) {
      *(undefined1 *)(fpRecord + 0x6c) = 1;
    }
    else {
      *(undefined1 *)(fpRecord + 0x6c) = 0;
      *ctx = 1;
    }
    statWord = *(undefined4 *)(((unsigned char *)0x00003874) + workArea);
    *(int *)(fpRecord + 0x54) = partCountA;
    *(int *)(fpRecord + 0x58) = partCountB;
    loopCounter = 0;
    *(undefined4 *)(fpRecord + 100) = 0;
    *(undefined4 *)(fpRecord + 0x5c) = statWord;
    do {
      for (bits = *(uint *)(((unsigned char *)0x000010b8) + workAreaState); bits != 0; bits = bits >> 1) {
        if ((bits & 1) != 0) {
          *(int *)(fpRecord + 100) = *(int *)(fpRecord + 100) + 1;
        }
      }
      moreRounds = loopCounter != 7;
      workAreaState = workAreaState + 4;
      loopCounter = loopCounter + 1;
    } while (moreRounds);
    *(int *)(fpRecord + 0x68) = *(int *)(((unsigned char *)0x00003870) + workArea) + 1;
    shaderField7c = *(undefined4 *)(*(int *)(fpRecord + 0x74) + 0x7c);
    *(int *)(fpRecord + 0x50) = partCountA + partCountB;
    *(undefined4 *)(fpRecord + 0x60) = shaderField7c;
    *(undefined *)(fpRecord + 2) = ((unsigned char *)0x000036d7)[workArea];
    *(undefined *)(fpRecord + 1) = ((unsigned char *)0x000036d6)[workArea];
  }
  if (buildStatus == 0) {
    return 0;
  }
  return 0xffffffff;
}

/* FUN_00088190 @ 0x88190 (740 bytes) */
int FUN_00088190(ctx, fpState)
  int ctx;
  char *fpState;
{
  char *currentFpState;
  undefined4 currentProgramHandle;
  int programTable;
  char *activeStateBlock;
  char *workAreaState;
  
  workAreaState = fpState + 0x124;
  if (fpState != (char *)0x0) {
    if (*(int *)(ctx + 0x23e0) == 0) {
      if (*(int *)(fpState + 0x37cc) == 0) {
        ((int (*)())arbfpCompileFragmentProgram)(ctx,0,*(int *)(fpState + 0x37e4),*(int *)(fpState + 0x37e4) + 4);
        *fpState = '\0';
      }
      activeStateBlock = workAreaState;
      if (0 < *(int *)(fpState + 0x37cc)) {
        *(char **)(ctx + 0x1e70) = workAreaState;
        *(char **)(ctx + 0x1e5c) = workAreaState;
        *(char **)(fpState + 0x37e4) = fpState;
      }
    }
    else {
      if (*(int *)(fpState + 0x37d8) == 0) {
        ((int (*)())arbfpCompileFragmentProgram)(ctx,0,*(int *)(fpState + 0x37e4),*(int *)(fpState + 0x37e4) + 4);
        *fpState = '\0';
      }
      if (0 < *(int *)(fpState + 0x37d8)) {
        *(char **)(ctx + 0x1e70) = workAreaState;
        *(char **)(ctx + 0x1e5c) = workAreaState;
        *(char **)(fpState + 0x37e4) = fpState;
      }
      activeStateBlock = fpState + 0x140;
    }
    currentFpState = *(char **)(((unsigned char *)0x00001488) + ctx);
    if ((currentFpState != (char *)0x0) && (fpState != currentFpState)) {
      *currentFpState = '\0';
    }
    if (*fpState == '\0') {
      programTable = *(int *)(ctx + 0x2768);
      *(undefined4 *)(((unsigned char *)0x00001488) + ctx) = 0;
      if ((programTable == 0) || (*(int *)(ctx + 0x277c) == -1)) {
        currentProgramHandle = 0;
      }
      else {
        currentProgramHandle = *(undefined4 *)(*(int *)(ctx + 0x277c) * 4 + programTable + 0xc0);
      }
      *(undefined4 *)(fpState + 0x164c) = currentProgramHandle;
      *(undefined4 *)(fpState + 0x1208) = currentProgramHandle;
      fpState[0x1420] = '\0';
      fpState[0x1421] = '\0';
      fpState[0x1422] = '\0';
      fpState[0x1423] = '\0';
    }
    if (fpState == *(char **)(((unsigned char *)0x00001488) + ctx)) {
      if ((fpState[0x36d7] != '\0') &&
         (((*(uint *)(ctx + 0x38) & 0x400) != 0 || ((*(uint *)(ctx + 0x3c) & 1) != 0)))) {
        FUN_000b51a0(ctx,fpState + 0x18a8,fpState + 0x1784);
        fpState[0x120f] = '\0';
      }
      if ((fpState[0x3748] != '\0') && ((*(uint *)(ctx + 0x38) & 0x100) != 0)) {
        FUN_000b5320(ctx,fpState + 0x18a8,fpState + 0x1784);
        fpState[0x120f] = '\0';
      }
      if ((*(int *)(fpState + 0x374c) != 0) &&
         (*(short *)(ctx + 0x34) != 0 || *(short *)(ctx + 0x32) != 0)) {
        FUN_000b50a0(ctx,fpState + 0x18a8,fpState + 0x1784);
        fpState[0x120f] = '\0';
      }
    }
    else {
      if (*(char *)(ctx + 0x1868) == '\0') {
        (**(code **)(((unsigned char *)0x00001334) + ctx))(ctx,0);
      }
      *(char **)(((unsigned char *)0x00001488) + ctx) = fpState;
      *fpState = '\x01';
      activeStateBlock[0] = '\0';
      activeStateBlock[1] = '\0';
      activeStateBlock[2] = '\0';
      activeStateBlock[3] = '\0';
      fpState[0x1424] = '\0';
      fpState[0x1425] = '\0';
      fpState[0x1426] = '\0';
      fpState[0x1427] = '\0';
      fpState[0x120f] = '\0';
      if (fpState[0x36d7] != '\0') {
        FUN_000b51a0(ctx,fpState + 0x18a8,fpState + 0x1784);
      }
      if (fpState[0x3748] != '\0') {
        FUN_000b5320(ctx,fpState + 0x18a8,fpState + 0x1784);
      }
      if (*(int *)(fpState + 0x374c) != 0) {
        FUN_000b50a0(ctx,fpState + 0x18a8,fpState + 0x1784);
      }
    }
    (**(code **)(ctx + 0x294c))(ctx,workAreaState);
    if ((*(uint *)(ctx + 0x1930) & 0xc0100000) != 0) {
      /* issue #79 class: the stock's r4 here is the flags word itself (`lwz r4,0x1930(r29)`, tested by
       * `andis. r0,r4,0xc010`, then the `bctrl` at 0x88444); the siblings pass the literal 0xc0100000 */
      (**(code **)(((unsigned char *)0x00001330) + ctx))(ctx,*(undefined4 *)(ctx + 0x1930));
      *(uint *)(ctx + 0x1930) = *(uint *)(ctx + 0x1930) & 0x3fefffff;
    }
  }
  return 0;
}

/* arbfpLookupKeyword @ 0x88480 (268 bytes) */
int arbfpLookupKeyword(parser)
  int parser;
{
  bool isEqual;
  uint sum;
  int compareResult;
  byte *tokenText;
  int high;
  int mid;
  int matchIndex;
  int low;
  int tokenLength;
  int remaining;
  
  tokenText = *(byte **)(parser + 8);
  low = 0;
  compareResult = 0;
  tokenLength = *(int *)(parser + 0xc) - (int)tokenText;
  high = DAT_001dbcd0 + -1;
  do {
    sum = low + high;
    mid = ((int)sum >> 1) + (uint)((int)sum < 0 && (sum & 1) != 0);
    if (tokenLength < 1) {
      isEqual = compareResult == 0;
LAB_000884dc:
      matchIndex = 0;
    }
    else {
      compareResult = (uint)*tokenText - (int)(char)*(PTR_s_1D_001e9158)[mid * 3];
      isEqual = compareResult == 0;
      if (!isEqual) goto LAB_000884dc;
      matchIndex = 0;
      remaining = tokenLength;
      do {
        matchIndex = matchIndex + 1;
        remaining = remaining + -1;
        if (remaining == 0) {
          compareResult = 0;
          goto LAB_0008855c;
        }
        compareResult = (uint)tokenText[matchIndex] - (int)(char)(PTR_s_1D_001e9158)[mid * 3][matchIndex];
        isEqual = false;
      } while (compareResult == 0);
    }
    if (compareResult < 1) {
      if (isEqual) {
LAB_0008855c:
        if ((PTR_s_1D_001e9158)[mid * 3][matchIndex] == '\0') {
          *(undefined4 *)(parser + 0x14) = *(undefined4 *)(&UNK_001e915c + mid * 0xc);
          *(undefined4 *)(parser + 0x18) = *(undefined4 *)(&UNK_001e9160 + mid * 0xc);
          return;
        }
      }
      high = mid + -1;
    }
    else {
      low = mid + 1;
    }
    if (high < low) {
      *(undefined4 *)(parser + 0x18) = 0;
      *(undefined4 *)(parser + 0x14) = 0;
      return;
    }
  } while( true );
}

/* arbLexNumber @ 0x885b0 (860 bytes) */
int arbLexNumber(parser)
  int parser;
{
  double exponentScale;
  double fracScale;
  double intBias;
  byte suffixChar;
  byte curChar;
  bool bVar2;
  double ten;
  double tenth;
  int exponent;
  byte *cursor;
  byte *fracCursor;
  uint expDigit;
  double intBias2;
  double value;
  
  ten = DOUBLE_001aa238;
  intBias2 = DOUBLE_001aa1e0;
  cursor = *(byte **)(parser + 0xc);
  curChar = *cursor;
  value = DOUBLE_001aa228;
  while ((curChar - 0x30 & 0xff) < 10) {
    cursor = cursor + 1;
    *(byte **)(parser + 0xc) = cursor;
    value = value * ten + ((double)CONCAT44(0x43300000,curChar - 0x30 ^ 0x80000000) - intBias2);
    curChar = *cursor;
  }
  if ((curChar == 0x2e) && (fracCursor = cursor + 1, cursor[1] != 0x2e)) {
    *(byte **)(parser + 0xc) = fracCursor;
    tenth = DOUBLE_001aa220;
    intBias = DOUBLE_001aa1e0;
    curChar = cursor[1];
    fracScale = DOUBLE_001aa220;
    while ((curChar - 0x30 & 0xff) < 10) {
      fracCursor = fracCursor + 1;
      *(byte **)(parser + 0xc) = fracCursor;
      value = fracScale * ((double)CONCAT44(0x43300000,curChar - 0x30 ^ 0x80000000) - intBias) + value;
      fracScale = fracScale * tenth;
      curChar = *fracCursor;
    }
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  cursor = *(byte **)(parser + 0xc);
  if ((*cursor != 0x45) && (*cursor != 0x65)) goto LAB_0008886c;
  *(byte **)(parser + 0xc) = cursor + 1;
  if (cursor[1] == 0x2d) {
    bVar2 = true;
    *(byte **)(parser + 0xc) = cursor + 2;
  }
  else {
    bVar2 = false;
    if (cursor[1] == 0x2b) {
      *(byte **)(parser + 0xc) = cursor + 2;
    }
  }
  cursor = *(byte **)(parser + 0xc);
  expDigit = (uint)*cursor;
  if ((expDigit - 0x30 & 0xff) < 10) {
LAB_000887c4:
    exponent = 0;
    do {
      exponent = exponent * 10 + expDigit + -0x30;
      if (1000 < exponent) {
        exponent = 1000;
      }
      cursor = cursor + 1;
      *(byte **)(parser + 0xc) = cursor;
      expDigit = (uint)*cursor;
    } while ((expDigit - 0x30 & 0xff) < 10);
    exponentScale = DOUBLE_001aa200;
    if (0 < exponent) {
      do {
        exponentScale = exponentScale * DOUBLE_001aa238;
        exponent = exponent + -1;
      } while (exponent != 0);
      cursor = *(byte **)(parser + 0xc);
    }
  }
  else {
    ((int (*)())arbSetError)(parser,"Invalid scientific notation.");
    cursor = *(byte **)(parser + 0xc);
    expDigit = (uint)*cursor;
    exponentScale = DOUBLE_001aa200;
    if ((expDigit - 0x30 & 0xff) < 10) goto LAB_000887c4;
  }
  if (bVar2) {
    exponentScale = DOUBLE_001aa200 / exponentScale;
  }
  value = value * exponentScale;
  bVar2 = false;
LAB_0008886c:
  suffixChar = *cursor;
  if ((((byte)(suffixChar + 0xbf) < 0x1a) || ((byte)(suffixChar + 0x9f) < 0x1a)) || (suffixChar == 0x5f)) {
    ((int (*)())arbSetError)(parser,"invalid suffix on number");
  }
  *(double *)(parser + 0x1c) = value;
  *(int *)(parser + 0x18) = (int)GH_F2U((float)(value));
  if ((bVar2) && (value == (double)CONCAT44(0x43300000,(int)value) - DOUBLE_001aa250)) {
    *(undefined4 *)(parser + 0x14) = 0xf;
  }
  else {
    *(undefined4 *)(parser + 0x14) = 0x10;
  }
  return;
}

/* arbNextToken @ 0x88920 (892 bytes) */
int arbNextToken(parser)
  int parser;
{
  char ch;
  bool sawCarriageReturn;
  bool sawNewline;
  bool inComment;
  undefined1 *sourceEnd;
  int remaining;
  undefined1 *cursor;
  
  cursor = *(undefined1 **)(parser + 0xc);
  sourceEnd = *(undefined1 **)(parser + 0x10);
  if (sourceEnd != cursor) {
    sawNewline = false;
    sawCarriageReturn = false;
    inComment = false;
    remaining = (int)sourceEnd - (int)cursor;
    do {
      switch(*cursor) {
      case 9:
      case 0x20:
        if ((!sawCarriageReturn) && (!sawNewline)) goto LAB_00088ae8;
        sawNewline = false;
        sawCarriageReturn = false;
        *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        break;
      case 10:
        if (sawNewline) {
          sawNewline = true;
          inComment = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        else {
          sawNewline = true;
          inComment = false;
        }
        break;
      default:
        if ((sawCarriageReturn) || (sawNewline)) {
          sawNewline = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        if (!inComment) goto LAB_00088afc;
LAB_00088ae8:
        sawCarriageReturn = false;
        break;
      case 0xd:
        if ((sawCarriageReturn) || (sawNewline)) {
          sawNewline = false;
          sawCarriageReturn = true;
          inComment = false;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
        else {
          sawCarriageReturn = true;
          inComment = false;
        }
        break;
      case 0x23:
        if ((sawCarriageReturn) || (inComment = true, sawNewline)) {
          sawNewline = false;
          sawCarriageReturn = false;
          inComment = true;
          *(int *)(parser + 0x24) = *(int *)(parser + 0x24) + 1;
        }
      }
      remaining = remaining + -1;
      cursor = cursor + 1;
      *(undefined1 **)(parser + 0xc) = cursor;
    } while (remaining != 0);
  }
LAB_00088afc:
  if (cursor < sourceEnd) {
    *(undefined1 **)(parser + 8) = cursor;
    switch(*cursor) {
    case 0x2b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x19;
      break;
    case 0x2c:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x13;
      break;
    case 0x2d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x1a;
      break;
    case 0x2e:
      if (cursor[1] == '.') {
        *(undefined1 **)(parser + 0xc) = cursor + 2;
        *(undefined4 *)(parser + 0x14) = 0x12;
      }
      else {
        if ((byte)(cursor[1] - 0x30) < 10) goto switchD_00088b48_caseD_30;
        *(undefined1 **)(parser + 0xc) = cursor + 1;
        *(undefined4 *)(parser + 0x14) = 0x11;
      }
      break;
    default:
      ((int (*)())arbSetError)(parser,"invalid character");
      return;
    case 0x31:
    case 0x32:
    case 0x33:
      if (cursor[1] == 'D') {
        do {
          do {
            sourceEnd = cursor + 1;
            *(undefined1 **)(parser + 0xc) = sourceEnd;
            ch = cursor[1];
            cursor = sourceEnd;
          } while ((byte)(ch + 0xbfU) < 0x1a);
        } while ((((byte)(ch + 0x9fU) < 0x1a) || ((byte)(ch - 0x30U) < 10)) || (ch == '_'))
        ;
        goto LAB_00088d48;
      }
    case 0x30:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
switchD_00088b48_caseD_30:
      ((int (*)())arbLexNumber)(parser);
      return;
    case 0x3b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x14;
      break;
    case 0x3d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x1b;
      break;
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5f:
    case 0x61:
    case 0x62:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
      do {
        do {
          sourceEnd = cursor + 1;
          *(undefined1 **)(parser + 0xc) = sourceEnd;
          ch = cursor[1];
          cursor = sourceEnd;
        } while ((byte)(ch + 0xbfU) < 0x1a);
      } while ((((byte)(ch + 0x9fU) < 0x1a) || ((byte)(ch - 0x30U) < 10)) || (ch == '_'));
LAB_00088d48:
      ((int (*)())arbfpLookupKeyword)(parser);
      return;
    case 0x5b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x15;
      break;
    case 0x5d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x16;
      break;
    case 0x7b:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x17;
      break;
    case 0x7d:
      *(undefined1 **)(parser + 0xc) = cursor + 1;
      *(undefined4 *)(parser + 0x14) = 0x18;
    }
  }
  else {
    *(undefined4 *)(parser + 0x14) = 0x1c;
  }
  return;
}

/* arbSetError @ 0x88e70 (112 bytes) */
int arbSetError(parser, message)
  undefined4 *parser;
  undefined4 message;
{
  if ((int)parser[10] < 0) {
    parser[0xc] = message;
    parser[0xb] = parser[9];
    parser[10] = parser[2] - parser[1];
  }
  parser[3] = parser[4];
  ((int (*)())arbNextToken)(parser);
  *(undefined4 *)*parser = 0x502;
  return;
}

/* arbErrorOutOfMemory @ 0x88ee0 (28 bytes) */
int arbErrorOutOfMemory(parser)
  undefined4 parser;
{
  return ((int (*)())arbSetError)(parser,"out of memory");
}

/* arbAllocVariable @ 0x88f00 (184 bytes) */
int arbAllocVariable(parser)
  int *parser;
{
  undefined4 *variable;
  
  variable = (undefined4 *)(**(code **)(*parser + 0xc))(0x2c);
  if (variable == (undefined4 *)0x0) {
    ((int (*)())arbErrorOutOfMemory)(parser);
  }
  else {
    variable[5] = variable + 6;
    variable[10] = 0;
    variable[6] = 4;
    variable[2] = 0;
    variable[8] = 0x36;
    variable[1] = 0;
    *variable = 0;
    variable[3] = 0;
    variable[4] = 0;
    variable[7] = 0;
    variable[9] = 0;
    if (parser[0x11] == 0) {
      parser[0x11] = (int)variable;
    }
    else {
      *(undefined4 **)parser[0x12] = variable;
    }
    parser[0x12] = (int)variable;
  }
  return variable;
}

/* arbParseVariableName @ 0x88fd0 (332 bytes) */
int arbParseVariableName(parser)
  int parser;
{
  int *entry;
  char *tokenText;
  int charIndex;
  int tokenLength;
  int remaining;
  
  tokenText = *(char **)(parser + 8);
  tokenLength = *(int *)(parser + 0xc) - (int)tokenText;
  if (*(int *)(parser + 0x14) == 0) {
    entry = *(int **)(parser + 0x3c);
    if (entry != (int *)0x0) {
      do {
        if (tokenLength == entry[2]) {
          if (tokenLength < 1) {
            if (tokenLength == 0) {
              return entry;
            }
          }
          else if (*tokenText == *(char *)entry[1]) {
            charIndex = 0;
            remaining = tokenLength;
            do {
              charIndex = charIndex + 1;
              remaining = remaining + -1;
              if (remaining == 0) {
                return entry;
              }
            } while (tokenText[charIndex] == ((char *)entry[1])[charIndex]);
          }
        }
        entry = (int *)*entry;
      } while (entry != (int *)0x0);
    }
    entry = *(int **)(parser + 0x4c);
    if (entry != (int *)0x0) {
      do {
        if (tokenLength == entry[2]) {
          if (tokenLength < 1) {
            if (tokenLength == 0) {
LAB_00089104:
              return (int *)entry[3];
            }
          }
          else if (*tokenText == *(char *)entry[1]) {
            charIndex = 0;
            remaining = tokenLength;
            do {
              charIndex = charIndex + 1;
              remaining = remaining + -1;
              if (remaining == 0) goto LAB_00089104;
            } while (tokenText[charIndex] == ((char *)entry[1])[charIndex]);
          }
        }
        entry = (int *)*entry;
      } while (entry != (int *)0x0);
    }
  }
  else {
    ((int (*)())arbSetError)(parser,"invalid variable name");
  }
  return (int *)0x0;
}

/* arbErrorInternal @ 0x89140 (28 bytes) */
int arbErrorInternal(parser)
  undefined4 parser;
{
  return ((int (*)())arbSetError)(parser,"internal error");
}

/* arbExpectToken @ 0x89160 (44 bytes) */
int arbExpectToken(parser, expectedToken)
  int parser;
  int expectedToken;
{
  if (*(int *)(parser + 0x14) == expectedToken) {
    ((int (*)())arbNextToken)(parser);
    return;
  }
  return ((int (*)())arbSetError)(parser,"unexpected token");
}

/* arbComponentLetterToIndex @ 0x89190 (124 bytes) */
int arbComponentLetterToIndex(parser, letter)
  undefined4 parser;
  undefined4 letter;
{
  undefined4 componentIndex;
  
  switch(letter) {
  case 0x61:
  case 0x77:
    componentIndex = 3;
    break;
  case 0x62:
  case 0x7a:
    componentIndex = 2;
    break;
  default:
    ((int (*)())arbSetError)(parser,"invalid component");
  case 0x72:
  case 0x78:
    componentIndex = 0;
    break;
  case 0x67:
  case 0x79:
    componentIndex = 1;
  }
  return componentIndex;
}

/* arbAllocBindingEntry @ 0x89280 (156 bytes) */
int arbAllocBindingEntry(parser, variable)
  undefined4 parser;
  int variable;
{
  undefined4 *element;
  uint used;
  
  element = (undefined4 *)(variable + 0x18);
  if (*(uint *)(variable + 0xc) != 0) {
    used = *(uint *)(variable + 0x10);
    if (used < *(uint *)(variable + 0xc)) {
      *(uint *)(variable + 0x10) = used + 1;
      element = (undefined4 *)(used * 0x14 + *(int *)(variable + 0x14));
    }
    else {
      ((int (*)())arbSetError)(parser,"too many array initializers");
      element = (undefined4 *)(variable + 0x18);
    }
  }
  *element = 4;
  element[4] = 0;
  element[2] = 0x36;
  element[1] = 0;
  element[3] = 0;
  return element;
}

/* arbInternConstant @ 0x89320 (264 bytes) */
int arbInternConstant(parser, constant)
  int *parser;
  float *constant;
{
  float valueX;
  float valueY;
  float valueZ;
  float *entry;
  int constantIndex;
  int foundCount;
  int constantCount;
  int remaining;
  
  constantCount = parser[0x9116];
  foundCount = 0;
  if (constantCount != 0) {
    entry = (float *)(parser + 0x9016);
    constantIndex = 0;
    remaining = constantCount;
    do {
      if ((((*entry == *constant) && (entry[1] == constant[1])) && (entry[2] == constant[2])) &&
         (entry[3] == constant[3])) {
        return constantIndex;
      }
      constantIndex = constantIndex + 1;
      entry = entry + 4;
      remaining = remaining + -1;
      foundCount = constantCount;
    } while (remaining != 0);
  }
  if (foundCount < *(int *)(((unsigned char *)0x000011e4) + *parser)) {
    valueX = *constant;
    valueY = constant[1];
    valueZ = constant[2];
    parser[constantCount * 4 + 0x9019] = (int)GH_F2U((float)(constant[3]));
    parser[constantCount * 4 + 0x9016] = (int)GH_F2U(valueX);
    parser[constantCount * 4 + 0x9017] = (int)GH_F2U(valueY);
    parser[constantCount * 4 + 0x9018] = (int)GH_F2U(valueZ);
    parser[0x9116] = parser[0x9116] + 1;
  }
  else {
    ((int (*)())arbSetError)(parser,"too many constants");
    constantCount = 0;
  }
  return constantCount;
}

/* arbDeclareVariable @ 0x89430 (348 bytes) */
int arbDeclareVariable(parser)
  int *parser;
{
  int keywordOrFound;
  undefined4 *variable;
  
  if (parser[5] == 0) {
    keywordOrFound = parser[6];
    if ((((keywordOrFound == 0xc) || (keywordOrFound == 0x1d)) || (keywordOrFound == 0x20)) ||
       ((keywordOrFound == 0x27 || (keywordOrFound == 0x2a)))) {
      variable = (undefined4 *)0x0;
      ((int (*)())arbSetError)(parser,"reserved variable name");
    }
    else {
      keywordOrFound = ((int (*)())arbParseVariableName)(parser);
      if (keywordOrFound == 0) {
        variable = (undefined4 *)(**(code **)(*parser + 0xc))(0x2c);
        if (variable == (undefined4 *)0x0) {
          ((int (*)())arbErrorOutOfMemory)(parser);
        }
        else {
          variable[2] = parser[3] - parser[2];
          keywordOrFound = parser[2];
          variable[5] = variable + 6;
          variable[6] = 4;
          variable[8] = 0x36;
          variable[10] = 0;
          *variable = 0;
          variable[3] = 0;
          variable[4] = 0;
          variable[1] = keywordOrFound;
          variable[7] = 0;
          variable[9] = 0;
          if (parser[0xf] == 0) {
            parser[0xf] = (int)variable;
          }
          else {
            *(undefined4 **)parser[0x10] = variable;
          }
          parser[0x10] = (int)variable;
        }
      }
      else {
        variable = (undefined4 *)0x0;
        ((int (*)())arbSetError)(parser,"redeclared variable name");
      }
    }
  }
  else {
    ((int (*)())arbErrorInternal)(parser);
    variable = (undefined4 *)0x0;
  }
  ((int (*)())arbNextToken)(parser);
  return variable;
}

/* arbParseResultBinding @ 0x895b0 (364 bytes) */
int arbParseResultBinding(parser, binding)
  int *parser;
  undefined4 *binding;
{
  int colorIndex;
  
  if ((parser[5] != 0) || (parser[6] != 0x20)) {
    ((int (*)())arbSetError)(parser,"invalid result binding");
  }
  ((int (*)())arbNextToken)(parser);
  ((int (*)())arbExpectToken)(parser,0x11);
  if (parser[5] == 0) {
    binding[2] = 0x35;
    *binding = 3;
    if (parser[6] == 4) {
      ((int (*)())arbNextToken)(parser);
      binding[1] = 0;
      if (*(char *)((int)parser + 0x3a) == '\0') {
        binding[3] = 0;
      }
      else {
        colorIndex = 0;
        if (parser[5] == 0x15) {
          ((int (*)())arbNextToken)(parser);
          if (((parser[5] == 0xf) && (colorIndex = parser[6], -1 < colorIndex)) &&
             (colorIndex < (int)(uint)(byte)((unsigned char *)0x000013b3)[*parser])) {
            ((int (*)())arbNextToken)(parser);
          }
          else {
            colorIndex = 0;
            ((int (*)())arbSetError)(parser,"invalid output color");
          }
          ((int (*)())arbExpectToken)(parser,0x16);
        }
        binding[3] = colorIndex;
      }
    }
    else {
      if (parser[6] != 5) goto LAB_00089638;
      ((int (*)())arbNextToken)(parser);
      binding[1] = 1;
    }
    return;
  }
LAB_00089638:
  ((int (*)())arbSetError)(parser,"invalid result binding");
  return;
}

/* arbParseOptionalSign @ 0x89740 (88 bytes) */
int arbParseOptionalSign(parser)
  int parser;
{
  undefined4 sign;
  
  if (*(int *)(parser + 0x14) == 0x19) {
    ((int (*)())arbNextToken)(parser);
    sign = 1;
  }
  else {
    sign = 1;
    if (*(int *)(parser + 0x14) == 0x1a) {
      ((int (*)())arbNextToken)(parser);
      sign = 0xffffffff;
    }
  }
  return sign;
}

/* arbParseFloatConstant @ 0x897b0 (164 bytes) */
double arbParseFloatConstant(int parser)
{
  uint sign;
  double value;
  double signAsDouble;
  
  sign = ((int (*)())arbParseOptionalSign)(parser);
  value = DOUBLE_001aa228;
  signAsDouble = (double)CONCAT44(0x43300000,sign ^ 0x80000000) - DOUBLE_001aa1e0;
  if (*(int *)(parser + 0x14) - 0xfU < 2) {
    value = *(double *)(parser + 0x1c);
    ((int (*)())arbNextToken)(parser);
  }
  else {
    ((int (*)())arbSetError)(parser,"invalid constant");
  }
  return value * signAsDouble;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl gldEmitVertexRoutingPackets");
asm(".set gldEmitVertexRoutingPackets, _gldEmitVertexRoutingPackets");
asm(".globl ffvpValidateProgram");
asm(".set ffvpValidateProgram, _ffvpValidateProgram");
asm(".globl arbEmitRecord3Src_op44");
asm(".set arbEmitRecord3Src_op44, _arbEmitRecord3Src_op44");
asm(".globl arbEmitRecord2Src_op01");
asm(".set arbEmitRecord2Src_op01, _arbEmitRecord2Src_op01");
asm(".globl arbEmitRecord1Src_op02");
asm(".set arbEmitRecord1Src_op02, _arbEmitRecord1Src_op02");
asm(".globl arbEmitRecord2Src_op02");
asm(".set arbEmitRecord2Src_op02, _arbEmitRecord2Src_op02");
asm(".globl arbEmitRecord2Src_op03");
asm(".set arbEmitRecord2Src_op03, _arbEmitRecord2Src_op03");
asm(".globl arbEmitRecord3Src_op04");
asm(".set arbEmitRecord3Src_op04, _arbEmitRecord3Src_op04");
asm(".globl arbEmitRecord3Src_op0b");
asm(".set arbEmitRecord3Src_op0b, _arbEmitRecord3Src_op0b");
asm(".globl arbEmitRecord3Src_op0c");
asm(".set arbEmitRecord3Src_op0c, _arbEmitRecord3Src_op0c");
asm(".globl arbEmitRecord2Src_op08");
asm(".set arbEmitRecord2Src_op08, _arbEmitRecord2Src_op08");
asm(".globl arbEmitRecord2Src_op07");
asm(".set arbEmitRecord2Src_op07, _arbEmitRecord2Src_op07");
asm(".globl arbEmitRecord2Src_op0a");
asm(".set arbEmitRecord2Src_op0a, _arbEmitRecord2Src_op0a");
asm(".globl arbEmitRecord2Src_op09");
asm(".set arbEmitRecord2Src_op09, _arbEmitRecord2Src_op09");
asm(".globl arbEmitRecord1Src_op0e");
asm(".set arbEmitRecord1Src_op0e, _arbEmitRecord1Src_op0e");
asm(".globl arbEmitRecord1Src_op47");
asm(".set arbEmitRecord1Src_op47, _arbEmitRecord1Src_op47");
asm(".globl arbEmitRecord1Src_op49");
asm(".set arbEmitRecord1Src_op49, _arbEmitRecord1Src_op49");
asm(".globl arbEmitRecord1Src_op4b");
asm(".set arbEmitRecord1Src_op4b, _arbEmitRecord1Src_op4b");
asm(".globl arbEmitRecord1Src_op43");
asm(".set arbEmitRecord1Src_op43, _arbEmitRecord1Src_op43");
asm(".globl arbEmitRecord2Src_op45");
asm(".set arbEmitRecord2Src_op45, _arbEmitRecord2Src_op45");
asm(".globl arbEmitRecord2Src_op4f");
asm(".set arbEmitRecord2Src_op4f, _arbEmitRecord2Src_op4f");
asm(".globl arbfpInitResourceLimits");
asm(".set arbfpInitResourceLimits, _arbfpInitResourceLimits");
asm(".globl noop_879e0");
asm(".set noop_879e0, _noop_879e0");
asm(".globl FUN_00087cd0");
asm(".set FUN_00087cd0, _FUN_00087cd0");
asm(".globl FUN_00087da0");
asm(".set FUN_00087da0, _FUN_00087da0");
asm(".globl FUN_00087e60");
asm(".set FUN_00087e60, _FUN_00087e60");
asm(".globl FUN_00087e80");
asm(".set FUN_00087e80, _arbfpCompileFragmentProgram");
asm(".globl FUN_00088190");
asm(".set FUN_00088190, _FUN_00088190");
