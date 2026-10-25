#include "decls.h"

/* gld_updateSampleConfig @ 0x19c50 (308 bytes) */
int gld_updateSampleConfig(ctx)
  int ctx;
{
  uint legacySampleBits;
  float savedRasterScaleX;
  float savedRasterScaleY;
  uint sampleModeBits;
  int savedSampleCount;
  
  if (ctx != 0) {
    savedSampleCount = *(int *)(ctx + 0x2a50);
    savedRasterScaleX = *(float *)(ctx + 0x2a54);
    savedRasterScaleY = *(float *)(ctx + 0x2a58);
    sampleModeBits = *(uint *)(ctx + 0x154) & 0x700000;
    if (sampleModeBits == 0) {
      legacySampleBits = *(uint *)(ctx + 0x154) & 0xc0000;
      if (legacySampleBits == 0x40000) {
        FUN_00019ad0(ctx,2);
      }
      else if (legacySampleBits == 0x80000) {
        FUN_00019ad0(ctx,4);
      }
      else {
        FUN_00019ad0(ctx,1);
      }
    }
    else if (sampleModeBits == 0x200000) {
      FUN_000199f0(ctx,4);
    }
    else if (sampleModeBits == 0x400000) {
      FUN_000199f0(ctx,6);
    }
    else if (sampleModeBits == 0x100000) {
      FUN_000199f0(ctx,2);
    }
    else {
      FUN_000199f0(ctx,1);
    }
    *(undefined4 *)(ctx + 0x2a48) = *(undefined4 *)(ctx + 0x15c);
    *(undefined4 *)(ctx + 0x2a4c) = *(undefined4 *)(ctx + 0x160);
    if (((savedSampleCount != *(int *)(ctx + 0x2a50)) || (savedRasterScaleX != *(float *)(ctx + 0x2a54))) ||
       (savedRasterScaleY != *(float *)(ctx + 0x2a58))) {
      *(undefined1 *)(ctx + 0x2a43) = 1;
    }
  }
  return;
}

/* FUN_00019db0 @ 0x19db0 (544 bytes) */
int FUN_00019db0(ctx, sampleCount, sampleModeSelector)
  int *ctx;
  undefined4 sampleCount;
  int sampleModeSelector;
{
  uint scalarIn1;
  bool usesPrimaryConfig;
  int pendingSampleCount;
  uint scalarIn0;
  uint newDrawableFlags;
  int scalarIn2;
  int scalarIn3;
  
  if (ctx == (int *)0x0) {
    return 0;
  }
  if (ctx[0x3e] == 0) {
    return 0;
  }
  if (ctx[0x79] + 0x28U < (uint)ctx[0x77]) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
  }
  if ((ctx[0x55] & 0xfU) == 3) {
    usesPrimaryConfig = true;
LAB_00019e50:
    FUN_00019ad0(ctx,sampleCount);
  }
  else {
    usesPrimaryConfig = sampleModeSelector == 0;
    if (usesPrimaryConfig) goto LAB_00019e50;
    FUN_000199f0(ctx,sampleCount);
  }
  newDrawableFlags = ctx[0xf] & 0xff83efff;
  ctx[0xf] = newDrawableFlags;
  if (usesPrimaryConfig) {
    if (GH_U2F((unsigned int)(ctx[0xa95])) <= FLOAT_001aa128) {
      if (FLOAT_001aa128 < GH_U2F((unsigned int)(ctx[0xa96]))) {
        newDrawableFlags = newDrawableFlags | 0x41000;
        ctx[0xf] = newDrawableFlags;
        goto LAB_00019f40;
      }
    }
    else if (FLOAT_001aa128 < GH_U2F((unsigned int)(ctx[0xa96]))) {
      newDrawableFlags = newDrawableFlags | 0x81000;
      ctx[0xf] = newDrawableFlags;
      goto LAB_00019f40;
    }
    ctx[0xf] = newDrawableFlags;
  }
  else {
    pendingSampleCount = ctx[0xa94];
    if (pendingSampleCount == 6) {
      newDrawableFlags = newDrawableFlags | 0x401000;
      ctx[0xf] = newDrawableFlags;
    }
    else if (pendingSampleCount == 4) {
      newDrawableFlags = newDrawableFlags | 0x201000;
      ctx[0xf] = newDrawableFlags;
    }
    else if (pendingSampleCount == 2) {
      newDrawableFlags = newDrawableFlags | 0x101000;
      ctx[0xf] = newDrawableFlags;
    }
  }
LAB_00019f40:
  if (ctx[0x54] == 0) {
    ctx[0x55] = newDrawableFlags;
  }
  if ((newDrawableFlags & 0x20) == 0) {
    scalarIn0 = ~(uint)*(byte *)(*(int *)(PTR_DAT_001e88ac + 0xc) + *ctx);
  }
  else {
    scalarIn0 = *(uint *)(ctx[0x3e] + 8);
  }
  scalarIn1 = newDrawableFlags & 0xffff3fc0;
  scalarIn2 = ctx[0x3f];
  scalarIn3 = ctx[0x40];
  _io_connect_method_scalarI_structureI(ctx[1],0,&scalarIn0,4,0,0);
  ((int (*)())gld_updateSampleConfig)(ctx);
  ((int (*)())FUN_00022eb0)(ctx,0);
  *(undefined1 *)(ctx + 0xa91) = 1;
  return 0;
}

/* FUN_0001a010 @ 0x1a010 (176 bytes) */
int FUN_0001a010(ctx, readSurfaceCode, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int ctx;
  int readSurfaceCode;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  bool needsResolve;
  uint renderFlags;
  
  renderFlags = *(uint *)(ctx + 0x154);
  if ((((renderFlags & 0x700000) == 0) &&
      (((renderFlags & 0xc0000) == 0 ||
       ((*(float *)(ctx + 0x2a54) < FLOAT_001aa128 &&
        (*(float *)(ctx + 0x2a58) < FLOAT_001aa128)))))) ||
     (needsResolve = true, (renderFlags & 0x70000000) != 0)) {
    needsResolve = false;
  }
  if (readSurfaceCode == 1) {
    if ((renderFlags & 0x400) != 0) {
      return 0;
    }
  }
  else if (readSurfaceCode == 0) {
    if ((renderFlags & 0x400) == 0) {
      return 0;
    }
  }
  else if (1 < readSurfaceCode - 4U) {
    return 0;
  }
  if (!needsResolve) {
    return 0;
  }
  return 1;
}

/* gld_isStampRetired @ 0x1a0d0 (32 bytes) */
int gld_isStampRetired(ctx, stamp)
  int ctx;
  int stamp;
{
  byte *retireCounter;
  
  retireCounter = *(byte **)(ctx + GLD_retireCounter);
  if ((int)(stamp -
           ((uint)retireCounter[3] << 0x18 | (uint)retireCounter[2] << 0x10 | (uint)retireCounter[1] << 8 | (uint)*retireCounter
           )) < 1) {
    return 1;
  }
  return 0;
}

/* gld_submitRing @ 0x1a0f0 (388 bytes) */
int gld_submitRing(ctx, terminatorWord)
  int ctx;
  undefined4 terminatorWord;
{
  char hasPreamble;
  undefined *taskPtr;
  int mappedBuffer;
  undefined4 *writeCursor;
  uint *headerWord;
  
  writeCursor = *(undefined4 **)(ctx + GLD_writeCursor);
  hasPreamble = ((unsigned char *)GLD_hasPreamble)[ctx];
  *writeCursor = ((unsigned char *)0x00001393U);
  writeCursor[1] = 0;
  writeCursor[2] = 0x5c8;
  writeCursor[3] = 0x20000;
  writeCursor = writeCursor + 4;
  if (hasPreamble != '\0') {
    writeCursor = (undefined4 *)FUN_0002b7f0(ctx,writeCursor);
  }
  headerWord = *(uint **)(ctx + GLD_lastHeader);
  *(int *)(*(int *)(ctx + GLD_ringMap) + 0x10) =
       (*(int *)(ctx + GLD_ringLimit) - (int)writeCursor >> 2) +
       (*(int *)(ctx + GLD_reserveEnd) - *(int *)(ctx + GLD_reserveStart) >> 2) + 0x25;
  taskPtr = PTR_001e88b4;
  *headerWord = (int)writeCursor - (int)headerWord >> 2 | *headerWord;
  *writeCursor = terminatorWord;
  _IOConnectMapMemory(*(undefined4 *)(ctx + GLD_connect),1,*(undefined4 *)taskPtr,ctx + GLD_ringMap,
                      ctx + GLD_ringMapSize,1);
  mappedBuffer = *(int *)(ctx + GLD_ringMap);
  writeCursor = (undefined4 *)(mappedBuffer + 0x20);
  *(undefined4 **)(ctx + GLD_ringLimit) = writeCursor + *(int *)(mappedBuffer + 0x10) + -0x25;
  *(undefined4 *)(mappedBuffer + 0x1c) = 0;
  *(undefined4 *)(ctx + 0x2838) = 0;
  *(undefined4 *)(ctx + GLD_dataRefillCount) = 1;
  *(undefined4 *)(ctx + GLD_reserveStart) = 0;
  *(undefined4 *)(ctx + GLD_reserveEnd) = 0;
  *(undefined4 *)(ctx + 0x2834) = 0;
  *(int *)(ctx + GLD_submitEpoch) = *(int *)(ctx + GLD_submitEpoch) + 1;
  if (hasPreamble != '\0') {
    *writeCursor = ((unsigned char *)0x000013d6U);
    *(undefined4 *)(mappedBuffer + 0x24) = 0;
    writeCursor = (undefined4 *)(mappedBuffer + 0x28);
  }
  *(int *)(ctx + GLD_lastHeader) = mappedBuffer + 0x1c;
  *(undefined4 **)(ctx + GLD_writeCursor) = writeCursor;
  *(undefined4 **)(ctx + GLD_streamSoftLimit) = writeCursor + 0x6000;
  return FUN_0002c6c0(ctx);
}

/* glFlush_impl @ 0x1a280 (588 bytes) */
int glFlush_impl(ctx, staleArgR4, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int ctx;
  undefined4 staleArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  undefined4 *writeCursor;
  int pendingSampleCount;
  char pendingSwapIntervalMode;
  int needsResolve;
  uint pendingSampleFlag;
  undefined4 *drawable;
  uint *lastHeader;
  uint scalarIn0;
  uint scalarIn1;
  
  needsResolve = ((int (*)())FUN_0001a010)(ctx,0,staleArgR5,staleArgR6,staleArgR7,staleArgR8,staleArgR9);
  if (needsResolve != 0) {
    ((int (*)())FUN_000230d0)(ctx,0,0,1,0,0,*(undefined4 *)(ctx + 0x15c),*(undefined4 *)(ctx + 0x160)
                );
  }
  ((int (*)())gld_submitRing)(ctx,0x2000000);
  if ((*(uint *)(*(int *)(ctx + 0x1e4) + 0x14) & 2) != 0) {
    drawable = *(undefined4 **)(ctx + 0xf8);
    if (*(char *)(ctx + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],0,0,-(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],ctx + 0x124,*(undefined4 *)(ctx + 0x108),
                 -(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
  }
  writeCursor = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= writeCursor + 5) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
    writeCursor = *(undefined4 **)(ctx + 0x1dc);
  }
  lastHeader = *(uint **)(ctx + 0x1d8);
  *(undefined4 **)(ctx + 0x1dc) = writeCursor + 5;
  *lastHeader = (int)writeCursor - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = writeCursor;
  *writeCursor = 0x28000000;
  if (*(char *)(ctx + 0x2a68) != '\0') {
    pendingSwapIntervalMode = *(char *)(ctx + 0x2a6c);
    *(undefined1 *)(ctx + 0x2a68) = 0;
    *(undefined4 *)(ctx + 0x2a8c) = *(undefined4 *)(ctx + 0x2a78);
    *(undefined4 *)(ctx + 0x2a90) = *(undefined4 *)(ctx + 0x2a7c);
    *(undefined1 *)(ctx + 0x2a69) = 1;
    if (*(char *)(ctx + 0x2a80) != pendingSwapIntervalMode) {
      *(char *)(ctx + 0x2a80) = pendingSwapIntervalMode;
      if (pendingSwapIntervalMode == '\x01') {
        scalarIn1 = 0;
        scalarIn0 = 0;
      }
      else if (pendingSwapIntervalMode == '\x02') {
        scalarIn1 = 1;
        scalarIn0 = 1;
      }
      else {
        scalarIn0 = (uint)*(byte *)(ctx + 0x142);
        scalarIn1 = (uint)*(byte *)(ctx + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),2,&scalarIn0,2,0,0);
    }
    pendingSampleCount = *(int *)(ctx + 0x2a70);
    if (*(int *)(ctx + 0x2a84) == pendingSampleCount) {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
      if (*(uint *)(ctx + 0x2a88) == pendingSampleFlag) {
        return;
      }
    }
    else {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
    }
    *(uint *)(ctx + 0x2a88) = pendingSampleFlag;
    *(int *)(ctx + 0x2a84) = pendingSampleCount;
    ((int (*)())FUN_00019db0)(ctx,pendingSampleCount,(uint)(pendingSampleFlag < 2));
  }
  return;
}

/* glFlush_impl_withSurfaceUpdate @ 0x1a4e0 (212 bytes) */
int glFlush_impl_withSurfaceUpdate(ctx, param_2, param_3, param_4, param_5, param_6, param_7)
  int ctx;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint clearedFlags;
  undefined4 r4AfterIoCall;
  undefined4 scalarIn0;
  uint uStack_24;
  undefined4 scalarIn2;
  undefined4 scalarIn3;
  
  if (((*(uint *)(ctx + 0x154) & 0x800) != 0) && (*(int *)(ctx + 0x26a0) != 1)) {
    if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
      ((int (*)())gld_submitRing)(ctx,0x1000000);
    }
    uStack_24 = *(uint *)(ctx + 0x3c);
    clearedFlags = uStack_24 & 0xfffff7ff;
    *(uint *)(ctx + 0x3c) = clearedFlags;
    if (*(int *)(ctx + 0x150) == 0) {
      *(uint *)(ctx + 0x154) = clearedFlags;
    }
    scalarIn2 = *(undefined4 *)(ctx + 0xfc);
    scalarIn3 = *(undefined4 *)(ctx + 0x100);
    param_3 = &scalarIn0;
    param_4 = 4;
    param_5 = 0;
    param_7 = *(undefined4 *)(*(int *)(ctx + 0xf8) + 8);
    uStack_24 = uStack_24 & 0xffff37c0;
    param_6 = 0;
    scalarIn0 = param_7;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0,param_3,4,0,0);
    param_2 = r4AfterIoCall;
  }
  return ((int (*)())glFlush_impl)(ctx,param_2,param_3,param_4,param_5,param_6,param_7);
}

/* _gldFlush @ 0x1a5c0 (28 bytes) */
int _gldFlush(ctx)
  int ctx;
{
  if (*(uint *)(ctx + GLD_writeCursor) <= *(int *)(ctx + GLD_ringMap) + 0x28U) {
    return;
  }
  return ((int (*)())gld_submitRing)(ctx,0x1000000);
}

/* _gldFinish @ 0x1a5e0 (136 bytes) */
int _gldFinish(ctx)
  int ctx;
{
  int status;
  
  if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
  }
  do {
    status = _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),8,0,0,0,0);
  } while (status == -0x1ffffd2a);
  return;
}

/* gld_signalFence @ 0x1a670 (216 bytes) */
int gld_signalFence(ctx, fence)
  int ctx;
  int *fence;
{
  uint *lastHeader;
  undefined4 *packet;
  
  packet = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= packet + 6) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
    packet = *(undefined4 **)(ctx + 0x1dc);
  }
  *(undefined4 **)(ctx + 0x1dc) = packet + 6;
  *packet = ((unsigned char *)0x00001393U);
  packet[1] = 0;
  packet[2] = 0x5c8;
  packet[3] = 0x20000;
  lastHeader = *(uint **)(ctx + 0x1d8);
  *lastHeader = (int)(packet + 4) - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = packet + 4;
  packet[4] = 0x34000000;
  packet[5] = *fence;
  *(undefined1 *)(fence + 1) = 0;
  *(undefined4 *)(*fence * 8 + *(int *)(ctx + 0x218) + 4) = 1;
  return;
}

/* glFinish_impl @ 0x1a750 (636 bytes) */
int glFinish_impl(ctx, staleArgR4, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  int ctx;
  undefined4 staleArgR4;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  undefined4 *writeCursor;
  int pendingSampleCount;
  int finishStatus;
  char pendingSwapIntervalMode;
  int needsResolve;
  uint pendingSampleFlag;
  undefined4 *drawable;
  uint *lastHeader;
  uint scalarIn0;
  uint scalarIn1;
  
  needsResolve = ((int (*)())FUN_0001a010)(ctx,1,staleArgR5,staleArgR6,staleArgR7,staleArgR8,staleArgR9);
  if (needsResolve != 0) {
    ((int (*)())FUN_000230d0)(ctx,0,1,0,0,0,*(undefined4 *)(ctx + 0x15c),*(undefined4 *)(ctx + 0x160)
                );
  }
  ((int (*)())gld_submitRing)(ctx,0x3000000);
  if ((*(uint *)(*(int *)(ctx + 0x1e4) + 0x14) & 2) != 0) {
    drawable = *(undefined4 **)(ctx + 0xf8);
    if (*(char *)(ctx + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],0,0,-(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],ctx + 0x124,*(undefined4 *)(ctx + 0x108),
                 -(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
  }
  writeCursor = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= writeCursor + 5) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
    writeCursor = *(undefined4 **)(ctx + 0x1dc);
  }
  lastHeader = *(uint **)(ctx + 0x1d8);
  *(undefined4 **)(ctx + 0x1dc) = writeCursor + 5;
  *lastHeader = (int)writeCursor - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = writeCursor;
  *writeCursor = 0x28000000;
  do {
    finishStatus = _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),8,0,0,0,0);
  } while (finishStatus == -0x1ffffd2a);
  if (*(char *)(ctx + 0x2a68) != '\0') {
    pendingSwapIntervalMode = *(char *)(ctx + 0x2a6c);
    *(undefined1 *)(ctx + 0x2a68) = 0;
    *(undefined4 *)(ctx + 0x2a8c) = *(undefined4 *)(ctx + 0x2a78);
    *(undefined4 *)(ctx + 0x2a90) = *(undefined4 *)(ctx + 0x2a7c);
    *(undefined1 *)(ctx + 0x2a69) = 1;
    if (*(char *)(ctx + 0x2a80) != pendingSwapIntervalMode) {
      *(char *)(ctx + 0x2a80) = pendingSwapIntervalMode;
      if (pendingSwapIntervalMode == '\x01') {
        scalarIn1 = 0;
        scalarIn0 = 0;
      }
      else if (pendingSwapIntervalMode == '\x02') {
        scalarIn1 = 1;
        scalarIn0 = 1;
      }
      else {
        scalarIn0 = (uint)*(byte *)(ctx + 0x142);
        scalarIn1 = (uint)*(byte *)(ctx + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),2,&scalarIn0,2,0,0);
    }
    pendingSampleCount = *(int *)(ctx + 0x2a70);
    if (*(int *)(ctx + 0x2a84) == pendingSampleCount) {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
      if (*(uint *)(ctx + 0x2a88) == pendingSampleFlag) {
        return;
      }
    }
    else {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
    }
    *(uint *)(ctx + 0x2a88) = pendingSampleFlag;
    *(int *)(ctx + 0x2a84) = pendingSampleCount;
    ((int (*)())FUN_00019db0)(ctx,pendingSampleCount,(uint)(pendingSampleFlag < 2));
  }
  return;
}

/* FUN_0001a9d0 @ 0x1a9d0 (588 bytes) */
int FUN_0001a9d0(ctx, framebufferObj, dirtyBitsArg, scratchR6, dirtyWord3, staleArgR8, staleArgR9)
  int ctx;
  undefined4 framebufferObj;
  undefined4 dirtyBitsArg;
  undefined4 scratchR6;
  undefined4 dirtyWord3;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  undefined4 *writeCursor;
  int pendingSampleCount;
  char pendingSwapIntervalMode;
  int needsResolve;
  uint pendingSampleFlag;
  undefined4 *drawable;
  uint *lastHeader;
  uint scalarIn0;
  uint scalarIn1;
  
  needsResolve = ((int (*)())FUN_0001a010)(ctx,1,dirtyBitsArg,scratchR6,dirtyWord3,staleArgR8,staleArgR9);
  if (needsResolve != 0) {
    ((int (*)())FUN_000230d0)(ctx,0,1,0,0,0,*(undefined4 *)(ctx + 0x15c),*(undefined4 *)(ctx + 0x160)
                );
  }
  ((int (*)())gld_submitRing)(ctx,0x3000000);
  if ((*(uint *)(*(int *)(ctx + 0x1e4) + 0x14) & 2) != 0) {
    drawable = *(undefined4 **)(ctx + 0xf8);
    if (*(char *)(ctx + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],0,0,-(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*drawable,drawable[1],drawable[2],ctx + 0x124,*(undefined4 *)(ctx + 0x108),
                 -(uint)*(byte *)(ctx + 0x142) >> 0x1f);
    }
  }
  writeCursor = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= writeCursor + 5) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
    writeCursor = *(undefined4 **)(ctx + 0x1dc);
  }
  lastHeader = *(uint **)(ctx + 0x1d8);
  *(undefined4 **)(ctx + 0x1dc) = writeCursor + 5;
  *lastHeader = (int)writeCursor - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = writeCursor;
  *writeCursor = 0x28000000;
  if (*(char *)(ctx + 0x2a68) != '\0') {
    pendingSwapIntervalMode = *(char *)(ctx + 0x2a6c);
    *(undefined1 *)(ctx + 0x2a68) = 0;
    *(undefined4 *)(ctx + 0x2a8c) = *(undefined4 *)(ctx + 0x2a78);
    *(undefined4 *)(ctx + 0x2a90) = *(undefined4 *)(ctx + 0x2a7c);
    *(undefined1 *)(ctx + 0x2a69) = 1;
    if (*(char *)(ctx + 0x2a80) != pendingSwapIntervalMode) {
      *(char *)(ctx + 0x2a80) = pendingSwapIntervalMode;
      if (pendingSwapIntervalMode == '\x01') {
        scalarIn1 = 0;
        scalarIn0 = 0;
      }
      else if (pendingSwapIntervalMode == '\x02') {
        scalarIn1 = 1;
        scalarIn0 = 1;
      }
      else {
        scalarIn0 = (uint)*(byte *)(ctx + 0x142);
        scalarIn1 = (uint)*(byte *)(ctx + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),2,&scalarIn0,2,0,0);
    }
    pendingSampleCount = *(int *)(ctx + 0x2a70);
    if (*(int *)(ctx + 0x2a84) == pendingSampleCount) {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
      if (*(uint *)(ctx + 0x2a88) == pendingSampleFlag) {
        return;
      }
    }
    else {
      pendingSampleFlag = *(uint *)(ctx + 0x2a74);
    }
    *(uint *)(ctx + 0x2a88) = pendingSampleFlag;
    *(int *)(ctx + 0x2a84) = pendingSampleCount;
    ((int (*)())FUN_00019db0)(ctx,pendingSampleCount,(uint)(pendingSampleFlag < 2));
  }
  return;
}

/* gld_validatePixelFormat @ 0x1ac30 (464 bytes) */
int gld_validatePixelFormat(pixelFormat)
  int pixelFormat;
{
  bool singleRenderer;
  ushort sampleBuffers;
  short samples;
  int stencilMask;
  uint displayMask;
  uint surfaceFlags;
  
  if (pixelFormat == 0) {
    return 0x271e;
  }
  displayMask = *(uint *)(pixelFormat + 0x30);
  if ((displayMask == 0) || ((displayMask & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
    return 0x2716;
  }
  surfaceFlags = *(uint *)(pixelFormat + 8);
  singleRenderer = (surfaceFlags >> 1 & 1) != 0;
  if (singleRenderer) {
    for (; (displayMask & 1) == 0; displayMask = displayMask >> 1) {
    }
    if (displayMask != 1) {
      return 0x2716;
    }
  }
  if ((((((*(uint *)(pixelFormat + 4) & 0xff00) == 0x1900) && (*(short *)(pixelFormat + 0x20) == 0)) &&
       (((*(uint *)(pixelFormat + 0xc) & 2) == 0 || (singleRenderer)))) && (*(ushort *)(pixelFormat + 0x22) < 3)) &&
     ((((surfaceFlags & 0x2000) == 0 || (*(int *)(pixelFormat + 0x24) == 0)) &&
      (sampleBuffers = *(ushort *)(pixelFormat + 0x24), sampleBuffers < 2)))) {
    if (sampleBuffers != 0) {
      if (((sampleBuffers == 1) && (samples = *(short *)(pixelFormat + 0x26), samples != 6)) &&
         ((samples != 4 && (samples != 2)))) {
        return 0x2712;
      }
    }
    else if (*(short *)(pixelFormat + 0x26) != 0) {
      return 0x2712;
    }
    if (((((surfaceFlags & 0xffffd064) == 0) &&
         (((surfaceFlags & 8) == 0 || ((*(uint *)(pixelFormat + 0xc) & 8) != 0)))) &&
        ((*(uint *)(pixelFormat + 0x10) & 0xf57f7bff) == 0)) &&
       (((*(uint *)(pixelFormat + 0x10) & 0xa800000) == 0 || ((sampleBuffers == 0 && ((surfaceFlags & 0x400) == 0))))))
    {
      stencilMask = *(int *)(pixelFormat + 0x1c);
      if (stencilMask != 1) {
        if (stencilMask != 0x80) {
          return 0x2712;
        }
        displayMask = 0xfffff7ff;
      }
      else {
        displayMask = 0xffffe3fe;
      }
      if (((*(uint *)(pixelFormat + 0x18) & displayMask) == 0) &&
         ((((*(uint *)(pixelFormat + 0x18) != 1 || (stencilMask != 1)) || ((surfaceFlags & 0x800) == 0)) &&
          ((displayMask = *(uint *)(pixelFormat + 0x14), (displayMask & 0xff7f7fff) == 0 &&
           ((displayMask & displayMask - 1) == 0)))))) {
        return 0;
      }
    }
  }
  return 0x2712;
}

/* gld_expandPixelFormatVariants @ 0x1ae20 (768 bytes) */
int gld_expandPixelFormatVariants(candidateRow, minimumPolicy, maximumPolicy)
  int candidateRow;
  int minimumPolicy;
  int maximumPolicy;
{
  uint bufferMask;
  uint surfaceFlags;
  uint colorBitsWord;
  uint depthStencilPolicyBits;
  int loopIndex;
  undefined2 sampleCountCode;
  int validateResult;
  int variantCount;
  int variantPtr;
  
  if ((*(uint *)(candidateRow + 0x1c) & 1) == 0) {
    *(uint *)(candidateRow + 0x1c) = *(uint *)(candidateRow + 0x1c) & 0x80;
    if (minimumPolicy == 0) {
LAB_0001aee0:
      *(undefined4 *)(candidateRow + 0x18) = 0x800;
    }
    else {
      *(uint *)(candidateRow + 0x18) = *(uint *)(candidateRow + 0x18) & 0x800;
    }
  }
  else {
    depthStencilPolicyBits = *(uint *)(candidateRow + 0x18);
    *(undefined4 *)(candidateRow + 0x1c) = 1;
    *(uint *)(candidateRow + 0x18) = depthStencilPolicyBits & 0x1c01;
    if ((minimumPolicy == 0) || ((depthStencilPolicyBits & 0x1c01) != 0)) {
      if (maximumPolicy == 0) {
        if ((depthStencilPolicyBits & 1) != 0) goto LAB_0001ae88;
        if ((depthStencilPolicyBits & 0x400) == 0) {
          if ((depthStencilPolicyBits & 0x800) != 0) goto LAB_0001aee0;
          goto LAB_0001aeb0;
        }
        *(undefined4 *)(candidateRow + 0x18) = 0x400;
      }
      else if ((depthStencilPolicyBits & 1) == 0) {
LAB_0001aeb0:
        *(undefined4 *)(candidateRow + 0x18) = 0x1000;
      }
      else {
LAB_0001ae88:
        *(undefined4 *)(candidateRow + 0x18) = 1;
      }
    }
  }
  colorBitsWord = *(uint *)(candidateRow + 0x14);
  if ((int)colorBitsWord < 0) {
    *(undefined4 *)(candidateRow + 0x14) = 0;
  }
  else if ((colorBitsWord & 0x8000) == 0) {
    if ((colorBitsWord & 0x800000) == 0) {
      *(undefined4 *)(candidateRow + 0x14) = 0xffffffff;
    }
    else {
      *(undefined4 *)(candidateRow + 0x14) = 0x800000;
    }
  }
  else {
    *(undefined4 *)(candidateRow + 0x14) = 0x8000;
  }
  if ((*(uint *)(candidateRow + 0xc) & 8) == 0) {
    surfaceFlags = *(uint *)(candidateRow + 8) & 0xfffffff7;
    *(uint *)(candidateRow + 8) = surfaceFlags;
  }
  else {
    surfaceFlags = *(uint *)(candidateRow + 8);
  }
  if ((surfaceFlags & 0x2000) != 0) {
    *(undefined2 *)(candidateRow + 0x24) = 0;
    *(undefined2 *)(candidateRow + 0x26) = 0;
  }
  sampleCountCode = 0;
  if (*(short *)(candidateRow + 0x24) != 0) {
    if (*(short *)(candidateRow + 0x24) != 1) {
      *(undefined2 *)(candidateRow + 0x24) = 1;
    }
    if (4 < *(short *)(candidateRow + 0x26)) {
      *(undefined2 *)(candidateRow + 0x26) = 6;
      goto LAB_0001aff4;
    }
    if (2 < *(short *)(candidateRow + 0x26)) {
      *(undefined2 *)(candidateRow + 0x26) = 4;
      goto LAB_0001aff4;
    }
    sampleCountCode = 2;
  }
  *(undefined2 *)(candidateRow + 0x26) = sampleCountCode;
LAB_0001aff4:
  bufferMask = *(uint *)(candidateRow + 0x10);
  variantCount = 2;
  _memcpy(candidateRow + 0x34,candidateRow,0x34);
  *(undefined4 *)(candidateRow + 0x10) = 0x400;
  *(undefined4 *)(candidateRow + 0x44) = 0x8000;
  if ((bufferMask & 0x800000) != 0) {
    variantCount = 3;
    _memcpy(candidateRow + 0x68,candidateRow,0x34);
    *(undefined2 *)(candidateRow + 0x8e) = 0;
    *(undefined4 *)(candidateRow + 0x78) = 0x800000;
    *(undefined2 *)(candidateRow + 0x8c) = 0;
    *(uint *)(candidateRow + 0x70) = *(uint *)(candidateRow + 0x70) & 0xfffffbff;
  }
  if ((bufferMask & 0x2000000) != 0) {
    variantPtr = variantCount * 0x34;
    variantCount = variantCount + 1;
    variantPtr = candidateRow + variantPtr;
    _memcpy(variantPtr,candidateRow,0x34);
    *(undefined2 *)(variantPtr + 0x26) = 0;
    *(undefined4 *)(variantPtr + 0x10) = 0x2000000;
    *(undefined2 *)(variantPtr + 0x24) = 0;
    *(uint *)(variantPtr + 8) = *(uint *)(variantPtr + 8) & 0xfffffbff;
  }
  if ((bufferMask & 0x8000000) != 0) {
    variantPtr = variantCount * 0x34;
    variantCount = variantCount + 1;
    variantPtr = candidateRow + variantPtr;
    _memcpy(variantPtr,candidateRow,0x34);
    *(undefined2 *)(variantPtr + 0x26) = 0;
    *(undefined4 *)(variantPtr + 0x10) = 0x8000000;
    *(undefined2 *)(variantPtr + 0x24) = 0;
    *(uint *)(variantPtr + 8) = *(uint *)(variantPtr + 8) & 0xfffffbff;
  }
  if (variantCount != 0) {
    loopIndex = 0;
    do {
      validateResult = ((int (*)())gld_validatePixelFormat)(candidateRow);
      if (validateResult != 0) {
        return 0;
      }
      loopIndex = loopIndex + 1;
      candidateRow = candidateRow + 0x34;
    } while (variantCount != loopIndex);
  }
  return variantCount;
}

/* gld_fillMaxPixelFormat @ 0x1b150 (88 bytes) */
int gld_fillMaxPixelFormat(pixelFormat)
  int pixelFormat;
{
  *(undefined1 *)(pixelFormat + 0x2a) = 1;
  *(undefined2 *)(pixelFormat + 0x26) = 1;
  *(uint *)(pixelFormat + 0x10) = *(uint *)(pixelFormat + 0x10) | 0xa800000;
  *(uint *)(pixelFormat + 0x1c) = *(uint *)(pixelFormat + 0x1c) | 1;
  *(uint *)(pixelFormat + 8) = *(uint *)(pixelFormat + 8) | 0x5000;
  *(uint *)(pixelFormat + 0xc) = *(uint *)(pixelFormat + 0xc) | 2;
  *(undefined2 *)(pixelFormat + 0x24) = 2;
  *(undefined4 *)(pixelFormat + 0x2c) = 3;
  *(undefined2 *)(pixelFormat + 0x28) = 6;
  return;
}

/* _gldFreeVertexBuffer @ 0x1b1b0 (20 bytes) */
int _gldFreeVertexBuffer(ctx, vertexBuffer)
  undefined4 ctx;
  int vertexBuffer;
{
  if (vertexBuffer == 0) {
    return;
  }
  *(undefined4 *)(vertexBuffer + -0x6c) = 1;
  return;
}

/* _gldCompleteVertexBuffer @ 0x1b1d0 (4 bytes) */
int _gldCompleteVertexBuffer()
{
  return;
}

/* _gldAllocVertexBuffer @ 0x1b1e0 (676 bytes) */
int _gldAllocVertexBuffer(ctx, bufferKind, sizeInOut)
  int ctx;
  uint bufferKind;
  int *sizeInOut;
{
  int *refCountSlot;
  int spinCount;
  uint retiredStamp;
  int requestedSize;
  uint chunkStamp;
  byte *retireCounter;
  undefined4 kernelKind;
  int currentChunk;
  char reservation;
  byte crBits;
  undefined4 structOutSize;
  int chunk;
  int chunkMemory;
  undefined4 structIn0;
  undefined4 structIn1;
  
  requestedSize = *sizeInOut;
  structOutSize = 8;
  *sizeInOut = 0;
  if (0x800 < requestedSize) {
    return 0;
  }
  if (*(char *)(ctx + 0x20) == '\0') {
    return 0;
  }
  switch(bufferKind & 0x7fff) {
  default:
    goto LAB_0001b494;
  case 1:
    kernelKind = 9;
    break;
  case 2:
    kernelKind = 10;
    break;
  case 3:
    kernelKind = 0xb;
    break;
  case 4:
    kernelKind = 0xc;
    break;
  case 5:
    kernelKind = 0xd;
    break;
  case 6:
    kernelKind = 0xe;
  }
  if (*(int *)(ctx + GLD_vertexChunkList) == 0) {
    structIn0 = 2;
    structIn1 = 0x16000;
    requestedSize = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(ctx + GLD_connect),10,&structIn0,0x14,&chunk,&structOutSize);
    if (requestedSize != 0) {
      return 0;
    }
    refCountSlot = (int *)(chunkMemory + 0x10);
    *(int *)(chunk + 0x1c) = chunkMemory;
    do {
      if (reservation != '\0') {
        requestedSize = storeWordConditionalIndexed(*refCountSlot + 0x10000,0,refCountSlot);
        *refCountSlot = requestedSize;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    *(undefined1 *)(chunkMemory + 0x14) = 1;
    *(undefined4 *)(ctx + GLD_vertexChunkCount) = 1;
    *(int *)(chunk + 0x10) = chunk;
    goto LAB_0001b468;
  }
  currentChunk = *(int *)(*(int *)(ctx + GLD_vertexChunkList) + 0x10);
  requestedSize = *(int *)(currentChunk + 0x1c);
  if (*(int *)(currentChunk + 0x14) == 0) {
    if (0x7f < *(uint *)(ctx + GLD_vertexChunkCount)) {
      return 0;
    }
LAB_0001b3e4:
    structIn0 = 2;
    structIn1 = 0x16000;
    requestedSize = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(ctx + GLD_connect),10,&structIn0,0x14,&chunk,&structOutSize);
    if (requestedSize != 0) {
LAB_0001b494:
      return 0;
    }
    refCountSlot = (int *)(chunkMemory + 0x10);
    *(int *)(chunk + 0x1c) = chunkMemory;
    do {
      if (reservation != '\0') {
        requestedSize = storeWordConditionalIndexed(*refCountSlot + 0x10000,0,refCountSlot);
        *refCountSlot = requestedSize;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    *(undefined1 *)(chunkMemory + 0x14) = 1;
    *(int *)(ctx + GLD_vertexChunkCount) = *(int *)(ctx + GLD_vertexChunkCount) + 1;
    *(undefined4 *)(chunk + 0x10) = *(undefined4 *)(*(int *)(ctx + GLD_vertexChunkList) + 0x10);
    *(int *)(*(int *)(ctx + GLD_vertexChunkList) + 0x10) = chunk;
  }
  else {
    if (*(int *)(currentChunk + 0x18) == *(int *)(ctx + GLD_submitEpoch)) {
      if (*(uint *)(ctx + GLD_vertexChunkCount) < 0x80) goto LAB_0001b3e4;
      ((int (*)())gld_submitRing)(ctx,0x1000000);
      retireCounter = *(byte **)(ctx + GLD_retireCounter);
      spinCount = 0xf4241;
      do {
        if ((int)(*(int *)(requestedSize + 8) -
                 ((uint)retireCounter[3] << 0x18 | (uint)retireCounter[2] << 0x10 | (uint)retireCounter[1] << 8 |
                 (uint)*retireCounter)) < 1) break;
        spinCount = spinCount + -1;
      } while (spinCount != 0);
    }
    else {
      chunkStamp = *(uint *)(requestedSize + 8);
      retireCounter = *(byte **)(ctx + GLD_retireCounter);
      retiredStamp = (uint)retireCounter[3] << 0x18 | (uint)retireCounter[2] << 0x10 | (uint)retireCounter[1] << 8 |
              (uint)*retireCounter;
      crBits = (chunkStamp == retiredStamp) << 1;
      if (0 < (int)(chunkStamp - retiredStamp)) {
        if (*(uint *)(ctx + GLD_vertexChunkCount) < 0x80) goto LAB_0001b3e4;
        requestedSize = 0xf4241;
        do {
          if ((int)(chunkStamp - ((uint)retireCounter[3] << 0x18 | (uint)retireCounter[2] << 0x10 |
                             (uint)retireCounter[1] << 8 | (uint)*retireCounter)) < 1) break;
          requestedSize = requestedSize + -1;
        } while (requestedSize != 0);
      }
    }
    *(undefined4 *)(currentChunk + 0x14) = 0;
    chunk = currentChunk;
  }
LAB_0001b468:
  requestedSize = *(int *)(ctx + GLD_submitEpoch);
  *(int *)(ctx + GLD_vertexChunkList) = chunk;
  *(undefined4 *)(chunk + 0xc) = kernelKind;
  *(int *)(chunk + 0x18) = requestedSize + -1;
  *sizeInOut = 0x800;
  return chunk + 0x80;
}

/* gld_updateYInvertedFlag @ 0x1b4b0 (44 bytes) */
int gld_updateYInvertedFlag(ctx)
  int ctx;
{
  if ((*(uint *)(ctx + GLD_renderFlags) & 0x70000000) == 0) {
    ((unsigned char *)GLD_yInverted)[ctx] = 1;
  }
  else {
    ((unsigned char *)GLD_yInverted)[ctx] = 0;
  }
  ((unsigned char *)0x00002b7d)[ctx] = 1;
  return;
}

/* noop_1b4f0 @ 0x1b4f0 (4 bytes) */
int noop_1b4f0()
{
  return;
}

/* returnOne_1b500 @ 0x1b500 (8 bytes) */
int returnOne_1b500()
{
  return 1;
}

/* FUN_0001b510 @ 0x1b510 (1304 bytes) */
int FUN_0001b510(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int gldTextureMakeResidentResult;
  int loopIndex;
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  *(undefined4 *)(param_2[1] + 0x18) = 0;
  iVar17 = 6;
  piVar14 = param_2;
  do {
    piVar14[0x13] = 0;
    piVar14 = piVar14 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  *(undefined1 *)((int)param_2 + 0x11) = 0;
  *(undefined1 *)((int)param_2 + 0x12) = 0;
  param_2[0x12] = 0;
  param_2[5] = 0;
  *(undefined1 *)(param_2 + 4) = 1;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  piVar14 = (int *)param_2[1];
  if ((piVar14[4] != 0) && (piVar14[5] != 0)) goto LAB_0001b730;
  if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) < (int)(uint)*(ushort *)(*param_2 + 0x9a)) ||
     (*(int *)(*(int *)(param_1 + 0x14) + 0x10) < (int)(uint)*(ushort *)(*param_2 + 0x9c)))
  goto LAB_0001b730;
  iVar17 = 0;
  loopIndex = 0;
  do {
    iVar10 = piVar14[loopIndex];
    if (iVar10 != 0) {
      if (loopIndex < 4) {
        iVar17 = iVar10;
      }
      gldTextureMakeResidentResult = gldTextureMakeResident(param_1,iVar10,param_3,param_4,param_5,param_6);
      if (gldTextureMakeResidentResult == 0) {
        piVar14 = (int *)param_2[1];
        goto LAB_0001b730;
      }
      piVar14 = (int *)param_2[1];
    }
    puVar4 = PTR_DAT_001e88c8;
    bVar1 = loopIndex != 5;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  if (iVar17 == 0) {
    param_2[9] = 0;
    *(undefined1 *)((int)param_2 + 0x13) = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
  }
  else {
    bVar2 = *(byte *)(iVar17 + 0x38);
    param_2[6] = *(ushort *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) & 0x3f;
    param_2[7] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 10 & 0x3f;
    param_2[8] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 4 & 0x3f;
    uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10);
    if ((((uVar5 & 0x3f0000) == 0) || ((uVar5 & 0xfc00) == 0)) || ((uVar5 & 0x3f0) == 0)) {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
LAB_0001b6ac:
      param_2[9] = uVar5 >> 0x1a;
    }
    else {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
      if ((uVar5 >> 0x1a == 0) || (*(short *)(*(int *)(iVar17 + 0x30) + 2) != 0x1907))
      goto LAB_0001b6ac;
      param_2[9] = 0;
    }
    *(byte *)((int)param_2 + 0x13) =
         (byte)(*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x20) >> 0x17) & 1;
    if ((*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x18) & 0x10000) == 0) goto LAB_0001b730;
  }
  iVar17 = piVar14[4];
  if (iVar17 == 0) {
    param_2[10] = 0;
  }
  else {
    param_2[10] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar17 + 0x38) * 0x24 + 0x14) >> 8 &
                  0x3f;
    if ((*(char *)(iVar17 + 0x38) != '\x10') && (*(char *)(iVar17 + 0x38) != ')'))
    goto LAB_0001b730;
  }
  iVar16 = piVar14[5];
  if (iVar16 == 0) {
    param_2[0xb] = 0;
  }
  else {
    param_2[0xb] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar16 + 0x38) * 0x24 + 0x14) >> 4 &
                   0xf;
    if ((*(char *)(iVar16 + 0x38) != ')') || ((iVar17 != 0 && (iVar17 != iVar16)))) {
LAB_0001b730:
      piVar14[7] = 1;
      return 0;
    }
  }
  iVar17 = 6;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    iVar16 = *piVar7;
    piVar7 = piVar7 + 1;
    if (iVar16 != 0) {
      piVar12[0x13] = *(int *)(iVar16 + 0x34);
    }
    puVar4 = PTR_DAT_001e88c8;
    piVar12 = piVar12 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iVar17 = 4;
  piVar7 = piVar14;
  do {
    if (*piVar7 != 0) {
      switch(*(undefined1 *)(*piVar7 + 0x38)) {
      case 5:
        uVar15 = 0x4000;
        uVar5 = 5;
        break;
      case 6:
      case 7:
        uVar15 = 0x4000;
        uVar5 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0x23:
      case 0x24:
        uVar15 = 0x4000;
        uVar5 = 4;
        break;
      default:
        uVar15 = 0x4000;
        uVar5 = 0;
        break;
      case 0x11:
      case 0x12:
        uVar15 = 0x4000;
        uVar5 = 0xd;
        break;
      case 0x17:
      case 0x18:
        uVar15 = 0x4000;
        uVar5 = 0xb;
        break;
      case 0x1d:
      case 0x1e:
        uVar15 = 0x4000;
        uVar5 = 0xc;
      }
      goto LAB_0001b8f4;
    }
    piVar7 = piVar7 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  uVar15 = 0;
  uVar5 = 0;
LAB_0001b8f4:
  uVar8 = uVar5;
  if (piVar14[4] != 0) {
    cVar3 = *(char *)(piVar14[4] + 0x38);
    uVar15 = uVar15 | 0x100;
    uVar8 = uVar5 | 0x40;
    if (cVar3 == '\x10') {
      uVar8 = uVar5 | 0x10040;
    }
    else if (cVar3 == ')') {
      uVar8 = uVar5 | 0x20040;
    }
  }
  uVar5 = uVar8;
  if (piVar14[5] != 0) {
    uVar15 = uVar15 | 0x400;
    uVar5 = uVar8 | 0x80;
    if (*(char *)(piVar14[5] + 0x38) == ')') {
      uVar5 = uVar8 | 0x30080;
    }
  }
  iVar16 = 0;
  iVar17 = 0;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    piVar13 = (int *)*piVar7;
    piVar7 = piVar7 + 1;
    if (piVar13 == (int *)0x0) {
      piVar12[0x25] = 0;
      piVar12[0x2b] = -1;
      piVar12[0x19] = 0;
      piVar12[0x1f] = 0;
    }
    else {
      iVar11 = *param_2;
      iVar9 = iVar17 + iVar11;
      iVar10 = *(int *)(iVar9 + 8);
      if (*(char *)(piVar13[0xd] + 0x16) == '\x06') {
        uVar8 = (uint)*(ushort *)((int)piVar13 + 0x3e) <<
                (*(uint *)(puVar4 + (uint)*(byte *)(piVar13 + 0xe) * 0x24 + 0x14) & 7);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = 0;
      }
      else {
        iVar6 = *(int *)(iVar9 + 4) * 0xd + iVar10;
        uVar8 = *(uint *)(*piVar13 + 0xc);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = *(int *)(iVar9 + 0xc) * uVar8 * (uint)*(ushort *)(iVar11 + 0x9c) +
                 *(int *)(*piVar13 + iVar6 * 0x20 + 0x48);
      }
      iVar9 = *(int *)piVar13[0xd];
      piVar12[0x19] = iVar10;
      piVar12[0x1f] = uVar8;
      piVar12[0x2b] = iVar9;
      piVar12[0x25] = (uint)*(ushort *)(iVar11 + 0x9a);
    }
    bVar1 = iVar16 != 5;
    iVar17 = iVar17 + 0x18;
    piVar12 = piVar12 + 1;
    iVar16 = iVar16 + 1;
  } while (bVar1);
  param_2[3] = uVar5;
  param_2[2] = uVar15;
  piVar14[7] = 0;
  *(undefined1 *)((int)param_2 + 0xc6) = 0;
  *(undefined1 *)((int)param_2 + 0xc5) = 1;
  *(undefined1 *)(param_2 + 0x31) = 0;
  return 1;
}

/* gld_emitFramebufferState @ 0x1bac0 (904 bytes) */
int gld_emitFramebufferState(ctx, framebufferObj)
  int ctx;
  int *framebufferObj;
{
  int *refCountWord;
  int *nextEntry;
  int releaseStatus;
  int releaseResult;
  uint *lastHeader;
  int attachmentSlotOffset;
  undefined4 *packetBody;
  uint *packetStart;
  int attachmentIndex;
  int *entry;
  uint attachmentEnum;
  int attachmentDesc;
  char reservation;
  byte crBits;
  int attachmentsLeft;
  
  ((unsigned char *)0x00002b7c)[ctx] = 0;
  packetStart = (uint *)(**(code **)(ctx + 0x2998))(ctx + 0x240,0x83);
  attachmentIndex = 0;
  *(uint **)(ctx + 0x298c) = packetStart;
  packetBody = (undefined4 *)((uint)(packetStart + 0xb) & 0xffffffe0);
  *packetStart = (((int)packetBody - (int)packetStart) + -8) * 0x4000 | 0xc0001000;
  packetBody[-1] = (int)packetBody - (int)packetStart;
  attachmentsLeft = 4;
  lastHeader = *(uint **)(ctx + 0x1d8);
  *lastHeader = (int)packetBody - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = packetBody;
  *packetBody = 0x41000000;
  packetBody[1] = 4;
  packetBody[2] = (uint)*(ushort *)(*framebufferObj + 0x9a);
  packetBody[3] = (uint)*(ushort *)(*framebufferObj + 0x9c);
  packetBody[4] = *(undefined4 *)(ctx + 0x1d20);
  packetBody[5] = *(undefined4 *)(ctx + 0x1cf0);
  nextEntry = packetBody + 6;
  do {
    entry = nextEntry;
    attachmentEnum = (uint)*(ushort *)(attachmentIndex * 2 + *framebufferObj + 0x90);
    if (attachmentEnum == 0) {
      entry[5] = 0;
      *entry = -1;
      entry[1] = 0;
      entry[2] = 0;
      entry[3] = 0;
      entry[4] = 0;
    }
    else {
      attachmentSlotOffset = (attachmentEnum - 0x8ce0) * 4;
      *entry = framebufferObj[attachmentEnum - 0x8cb5];
      entry[1] = framebufferObj[attachmentEnum - 0x8cc7];
      entry[2] = framebufferObj[attachmentEnum - 0x8cc1];
      entry[3] = framebufferObj[attachmentEnum - 0x8cbb];
      attachmentDesc = (attachmentEnum - 0x8ce0) * 0x18 + *framebufferObj;
      entry[4] = *(int *)(attachmentDesc + 4) << 0x10 | *(uint *)(attachmentDesc + 8);
      entry[5] = (uint)*(byte *)(*(int *)(attachmentSlotOffset + framebufferObj[1]) + 0x38);
      *(undefined1 *)(*(int *)(attachmentSlotOffset + framebufferObj[1]) + 200) = 0;
      refCountWord = (int *)(*(int *)(*(int *)(attachmentSlotOffset + framebufferObj[1]) + 0x34) + 0x10);
      do {
        if (reservation != '\0') {
          releaseStatus = storeWordConditionalIndexed(*refCountWord + 0x10000,0,refCountWord);
          *refCountWord = releaseStatus;
          crBits = 2;
        }
      } while (!(bool)(crBits >> 1 & 1));
    }
    nextEntry = entry + 6;
    attachmentIndex = attachmentIndex + 1;
    attachmentsLeft = attachmentsLeft + -1;
  } while (attachmentsLeft != 0);
  if (*(int *)(framebufferObj[1] + 0x10) == 0) {
    entry[0xb] = 0;
    entry[7] = 0;
    entry[8] = 0;
    entry[9] = 0;
    *nextEntry = -1;
    entry[10] = 0;
  }
  else {
    *nextEntry = framebufferObj[0x2f];
    entry[7] = framebufferObj[0x1d];
    entry[8] = framebufferObj[0x23];
    entry[9] = framebufferObj[0x29];
    entry[10] = *(int *)(*framebufferObj + 100) << 0x10 | *(uint *)(*framebufferObj + 0x68);
    entry[0xb] = (uint)*(byte *)(*(int *)(framebufferObj[1] + 0x10) + 0x38);
    *(undefined1 *)(*(int *)(framebufferObj[1] + 0x10) + 200) = 0;
    refCountWord = (int *)(*(int *)(*(int *)(framebufferObj[1] + 0x10) + 0x34) + 0x10);
    do {
      if (reservation != '\0') {
        releaseResult = storeWordConditionalIndexed(*refCountWord + 0x10000,0,refCountWord);
        *refCountWord = releaseResult;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
  }
  if (*(int *)(framebufferObj[1] + 0x14) == 0) {
    entry[0x11] = 0;
    entry[0xd] = 0;
    entry[0xe] = 0;
    entry[0xf] = 0;
    entry[0xc] = -1;
    entry[0x10] = 0;
  }
  else {
    entry[0xc] = framebufferObj[0x30];
    entry[0xd] = framebufferObj[0x1e];
    entry[0xe] = framebufferObj[0x24];
    entry[0xf] = framebufferObj[0x2a];
    entry[0x10] = *(int *)(*framebufferObj + 0x7c) << 0x10 | *(uint *)(*framebufferObj + 0x80);
    entry[0x11] = (uint)*(byte *)(*(int *)(framebufferObj[1] + 0x14) + 0x38);
    *(undefined1 *)(*(int *)(framebufferObj[1] + 0x14) + 200) = 0;
    refCountWord = (int *)(*(int *)(*(int *)(framebufferObj[1] + 0x14) + 0x34) + 0x10);
    do {
      if (reservation != '\0') {
        releaseResult = storeWordConditionalIndexed(*refCountWord + 0x10000,0,refCountWord);
        *refCountWord = releaseResult;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
  }
  *(int **)(ctx + 0x298c) = entry + 0x4b;
  (**(code **)(ctx + 0x299c))(ctx + 0x240,entry + 0x4b);
  if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
  }
  ((unsigned char *)0x00002b7d)[ctx] = 1;
  return;
}

/* dxt5EncodeAlphaBlock @ 0x1be50 (868 bytes) */
int dxt5EncodeAlphaBlock(rgbaBlock, dstBlock)
  int rgbaBlock;
  byte *dstBlock;
{
  bool moreRows;
  uint bestDelta;
  int blockColumn;
  int blockRow;
  bool moreColumns;
  uint alpha;
  int pixelCursor;
  int paletteIndex;
  int bestIndex;
  int *indexCursor;
  byte *alphaCursor;
  uint minAlpha;
  uint maxAlpha;
  int pixelsLeft;
  int paletteLeft;
  byte alphaPalette [4];
  undefined1 alphaPalette4;
  undefined1 alphaPalette5;
  undefined1 alphaPalette6;
  undefined1 alphaPalette7;
  int alphaIndices [4];
  int alphaIndex4;
  uint alphaIndex5;
  int alphaIndex6;
  int alphaIndex7;
  undefined4 alphaIndex8;
  int alphaIndex9;
  uint alphaIndex10;
  int alphaIndex11;
  int alphaIndex12;
  uint alphaIndex13;
  int alphaIndex14;
  int alphaIndex15;
  
  pixelsLeft = 0x10;
  minAlpha = 0xff;
  maxAlpha = 0;
  pixelCursor = rgbaBlock;
  do {
    alpha = (uint)*(byte *)(pixelCursor + 3);
    pixelCursor = pixelCursor + 4;
    if (alpha < minAlpha) {
      minAlpha = alpha;
    }
    if (maxAlpha < alpha) {
      maxAlpha = alpha;
    }
    pixelsLeft = pixelsLeft + -1;
  } while (pixelsLeft != 0);
  if (minAlpha == 0) {
    if (maxAlpha != 0xff) {
LAB_0001bfec:
      alphaPalette[0] = (byte)minAlpha;
      alphaPalette[1] = (byte)maxAlpha;
      alphaPalette[3] = (char)((minAlpha * 3 + maxAlpha * 2) / 5);
      alphaPalette4 = (char)((minAlpha * 2 + maxAlpha * 3) / 5);
      alphaPalette[2] = (char)((maxAlpha + minAlpha * 4) / 5);
      alphaPalette5 = (char)((minAlpha + maxAlpha * 4) / 5);
      alphaPalette6 = 0;
      alphaPalette7 = 0xff;
      goto LAB_0001bf84;
    }
  }
  else if (maxAlpha == 0xff) goto LAB_0001bfec;
  alphaPalette[0] = (byte)maxAlpha;
  alphaPalette[1] = (byte)minAlpha;
  alphaPalette[2] = (char)((minAlpha + maxAlpha * 6) / 7);
  alphaPalette[3] = (char)((maxAlpha * 5 + minAlpha * 2) / 7);
  alphaPalette4 = (char)((maxAlpha * 4 + minAlpha * 3) / 7);
  alphaPalette5 = (char)((maxAlpha * 3 + minAlpha * 4) / 7);
  alphaPalette6 = (char)((maxAlpha * 2 + minAlpha * 5) / 7);
  alphaPalette7 = (char)((maxAlpha + minAlpha * 6) / 7);
LAB_0001bf84:
  blockRow = 0;
  do {
    blockColumn = 0;
    indexCursor = alphaIndices + blockRow * 4;
    alphaCursor = (byte *)(rgbaBlock + blockRow * 0x10 + 3);
    do {
      bestDelta = 0xff;
      bestIndex = 0;
      paletteIndex = 0;
      paletteLeft = 8;
      do {
        if ((uint)alphaPalette[paletteIndex] - (uint)*alphaCursor < bestDelta) {
          bestIndex = paletteIndex;
          bestDelta = (uint)alphaPalette[paletteIndex] - (uint)*alphaCursor;
        }
        paletteIndex = paletteIndex + 1;
        paletteLeft = paletteLeft + -1;
      } while (paletteLeft != 0);
      moreColumns = blockColumn != 3;
      *indexCursor = bestIndex;
      alphaCursor = alphaCursor + 4;
      indexCursor = indexCursor + 1;
      blockColumn = blockColumn + 1;
    } while (moreColumns);
    moreRows = blockRow != 3;
    blockRow = blockRow + 1;
  } while (moreRows);
  dstBlock[1] = alphaPalette[1];
  dstBlock[2] = (byte)(alphaIndices[2] << 6) | (byte)(alphaIndices[1] << 3) | (byte)alphaIndices[0];
  dstBlock[3] = (byte)(alphaIndex5 << 7) | (byte)(alphaIndex4 << 4) | (byte)(alphaIndices[3] << 1) |
               (byte)((uint)alphaIndices[2] >> 2) & 1;
  dstBlock[5] = (byte)(alphaIndex10 << 6) | (byte)(alphaIndex9 << 3) | (byte)alphaIndex8;
  dstBlock[4] = (byte)(alphaIndex7 << 5) | (byte)(alphaIndex6 << 2) | (byte)(alphaIndex5 >> 1) & 3;
  dstBlock[6] = (byte)(alphaIndex13 << 7) | (byte)(alphaIndex12 << 4) | (byte)(alphaIndex11 << 1) |
               (byte)(alphaIndex10 >> 2) & 1;
  dstBlock[7] = (byte)(alphaIndex15 << 5) | (byte)(alphaIndex14 << 2) | (byte)(alphaIndex13 >> 1) & 3;
  *dstBlock = alphaPalette[0];
  return dstBlock + 8;
}

/* dxt1DecodeColorIndex @ 0x1c1c0 (416 bytes) */
int dxt1DecodeColorIndex(color0, color1, texelIndex, rgbaOut)
  uint color0;
  uint color1;
  uint texelIndex;
  undefined1 *rgbaOut;
{
  undefined1 texelBlue;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int greenSum;
  int redSum;
  int blue1;
  undefined1 endpointRgb [32];
  
  if (color1 < color0) {
    iVar4 = (color0 & 0x1f) * 8;
    uVar6 = color0 >> 8 & 0xf8;
    uVar5 = color0 >> 3 & 0xfc;
    blue1 = (color1 & 0x1f) * 8;
    uVar2 = color1 >> 8 & 0xf8;
    endpointRgb[2] = (char)iVar4;
    uVar3 = color1 >> 3 & 0xfc;
    endpointRgb[0] = (char)uVar6;
    endpointRgb[1] = (char)uVar5;
    endpointRgb[3] = (char)uVar2;
    endpointRgb[5] = (char)blue1;
    endpointRgb[4] = (char)uVar3;
    if (texelIndex == 2) {
      redSum = uVar6 * 2 + uVar2;
      greenSum = uVar5 * 2 + uVar3;
      iVar4 = (color0 & 0x1f) * 0x10 + blue1;
    }
    else {
      if (texelIndex < 2) goto LAB_0001c300;
      if (texelIndex != 3) {
        return;
      }
      redSum = uVar6 + uVar2 * 2;
      greenSum = uVar5 + uVar3 * 2;
      iVar4 = iVar4 + (color1 & 0x1f) * 0x10;
    }
    rgbaOut[3] = 0xff;
    rgbaOut[2] = (char)((ulonglong)((longlong)iVar4 * 0x55555556) >> 0x20);
    *rgbaOut = (char)((ulonglong)((longlong)redSum * 0x55555556) >> 0x20);
    rgbaOut[1] = (char)((ulonglong)((longlong)greenSum * 0x55555556) >> 0x20);
  }
  else {
    if (texelIndex == 3) {
      rgbaOut[3] = 0;
      *rgbaOut = 0;
      rgbaOut[1] = 0;
      rgbaOut[2] = 0;
      return;
    }
    iVar4 = (color0 & 0x1f) * 8;
    uVar2 = color0 >> 8 & 0xf8;
    uVar6 = color0 >> 3 & 0xfc;
    blue1 = (color1 & 0x1f) * 8;
    uVar3 = color1 >> 8 & 0xf8;
    endpointRgb[2] = (char)iVar4;
    uVar5 = color1 >> 3 & 0xfc;
    endpointRgb[0] = (char)uVar2;
    endpointRgb[1] = (char)uVar6;
    endpointRgb[3] = (char)uVar3;
    endpointRgb[5] = (char)blue1;
    endpointRgb[4] = (char)uVar5;
    if (1 < texelIndex) {
      if (texelIndex != 2) {
        return;
      }
      rgbaOut[3] = 0xff;
      *rgbaOut = (char)((int)(uVar2 + uVar3) >> 1);
      rgbaOut[1] = (char)((int)(uVar6 + uVar5) >> 1);
      rgbaOut[2] = (char)(iVar4 + blue1 >> 1);
      return;
    }
LAB_0001c300:
    iVar4 = texelIndex * 3;
    *rgbaOut = endpointRgb[iVar4];
    rgbaOut[1] = endpointRgb[iVar4 + 1];
    texelBlue = endpointRgb[iVar4 + 2];
    rgbaOut[3] = 0xff;
    rgbaOut[2] = texelBlue;
  }
  return;
}

/* FUN_0001c380 @ 0x1c380 (3664 bytes) */
int FUN_0001c380(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined1 *param_5;
  byte *param_6;
{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  byte bVar24;
  byte *pbVar23;
  int iVar25;
  uint uVar26;
  byte bVar27;
  undefined1 *puVar28;
  uint *puVar29;
  byte bVar30;
  byte bVar31;
  int iVar32;
  byte *pbVar33;
  uint uVar34;
  ushort *puVar35;
  byte bVar36;
  int iVar37;
  int *piVar38;
  byte *pbVar39;
  uint uVar40;
  byte *pbVar41;
  int iVar42;
  byte *pbVar43;
  byte bVar45;
  uint uVar44;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  byte *pbVar51;
  byte xerSummaryOverflow = 0;
  int iVar52;
  int iStack00000024;
  byte local_508 [4];
  byte local_504;
  byte local_503;
  byte local_502;
  byte local_501;
  byte local_500;
  byte local_4ff;
  byte local_4fe;
  byte local_4fd;
  byte local_4fc;
  byte local_4fb;
  byte local_4fa;
  byte local_4f9;
  byte local_4f8;
  byte local_4f7;
  undefined1 local_4f6;
  undefined1 local_4f5;
  undefined1 local_4f4;
  undefined1 local_4f3;
  undefined1 local_4f2;
  undefined1 local_4f1;
  int local_4f0 [4];
  byte local_4e0 [16];
  ushort local_4d0 [12];
  byte local_4b8 [7];
  byte local_4b1;
  byte local_4ad;
  byte local_4a9;
  byte local_4a5;
  byte local_4a1;
  byte local_49d;
  byte local_499;
  byte local_495;
  byte local_491;
  byte local_48d;
  byte local_489;
  byte local_485;
  byte local_481;
  byte local_47d;
  byte local_479;
  uint auStack_478 [256];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  byte *local_68;
  uint *local_64;
  int local_60;
  undefined1 *local_5c;
  uint *local_58;
  ushort *local_54;
  
  if (param_3 == 0x80e0) {
    iVar46 = 2;
    iVar47 = 3;
  }
  else if (param_3 == 0x80e1) {
    iVar46 = 2;
    iVar47 = 4;
  }
  else if (param_3 == 0x1907) {
    iVar46 = 0;
    iVar47 = 3;
  }
  else {
    iVar46 = 0;
    iVar47 = 4;
  }
  if ((param_1 + 3U < 7) || (param_2 + 3U < 7)) {
    iVar48 = param_1;
    if (param_1 < 4) {
      iVar48 = 4;
    }
    local_70 = param_2;
    if (param_2 < 4) {
      local_70 = 4;
    }
    else if (param_2 < 1) {
      return;
    }
    bVar3 = 0 < iVar48;
    iVar50 = 0;
    iVar49 = 0;
    do {
      if (bVar3) {
        iVar25 = 0;
        puVar28 = &DAT_001f65e7 + iVar49 * 4;
        iVar52 = iVar48;
        do {
          iVar42 = iVar47 * (iVar25 + iVar49);
          iVar32 = param_1 * (iVar50 - (iVar50 / param_2) * param_2) +
                   (iVar25 - (iVar25 / param_1) * param_1);
          iVar16 = iVar47 * iVar32;
          (DAT_001f65e4)[iVar42] = param_5[iVar16];
          (DAT_001f65e5)[iVar42] = param_5[iVar16 + 1];
          (DAT_001f65e6)[iVar42] = param_5[iVar16 + 2];
          if (iVar47 == 4) {
            *puVar28 = param_5[iVar32 * 4 + 3];
          }
          iVar25 = iVar25 + 1;
          puVar28 = puVar28 + 4;
          iVar52 = iVar52 + -1;
        } while (iVar52 != 0);
      }
      iVar50 = iVar50 + 1;
      iVar49 = iVar49 + iVar48;
    } while (local_70 != iVar50);
    param_5 = DAT_001f65e4;
    param_1 = iVar48;
  }
  else {
    if (param_2 < 1) {
      return;
    }
    local_70 = param_2;
    bVar3 = 0 < param_1;
  }
  bVar4 = iVar47 != 4;
  local_68 = &local_500;
  local_5c = param_5 + iVar46;
  local_58 = auStack_478;
  local_54 = local_4d0;
  local_60 = (uint)(byte)((param_4 < 0xc) << 3 | (0xc < param_4) << 2 | (param_4 == 0xc) << 1 |
                         xerSummaryOverflow & 1) << 0x1c;
  local_78 = 0;
  iStack00000024 = param_4;
  do {
    param_6 = (byte *)((uint)(param_6 + 0x1f) & 0xffffffe0);
    if (bVar3) {
      local_74 = 0;
      local_64 = auStack_478;
      local_6c = 0x55555556;
      do {
        if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
          if (bVar4) {
LAB_0001c6fc:
            iVar48 = 0;
            do {
              iVar50 = 0;
              iVar52 = 4;
              pbVar33 = local_4b8 + iVar48 * 0x10;
              iVar49 = local_74 + param_1 * (iVar48 + local_78);
              do {
                iVar25 = iVar50 + iVar49;
                iVar50 = iVar50 + 1;
                iVar25 = iVar47 * iVar25;
                *pbVar33 = local_5c[iVar25];
                pbVar33[1] = param_5[iVar25 + 1];
                pbVar33[2] = param_5[(iVar25 - iVar46) + 2];
                pbVar33[3] = 0xff;
                pbVar33 = pbVar33 + 4;
                iVar52 = iVar52 + -1;
              } while (iVar52 != 0);
              bVar6 = iVar48 != 3;
              iVar48 = iVar48 + 1;
            } while (bVar6);
            goto LAB_0001c78c;
          }
          bVar6 = false;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              *pbVar43 = *pbVar33;
              pbVar43[1] = puVar28[1];
              pbVar43[2] = *pbVar39;
              bVar7 = puVar28[3];
              pbVar43[3] = bVar7;
              if (bVar7 < 0x7f) {
                bVar6 = true;
              }
              pbVar33 = pbVar33 + 4;
              pbVar43 = pbVar43 + 4;
              puVar28 = puVar28 + 4;
              pbVar39 = pbVar39 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar5 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar5);
        }
        else {
          if (bVar4) goto LAB_0001c6fc;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              bVar7 = *pbVar33;
              pbVar33 = pbVar33 + 4;
              *pbVar43 = bVar7;
              pbVar43[1] = puVar28[1];
              bVar7 = *pbVar39;
              pbVar39 = pbVar39 + 4;
              pbVar43[2] = bVar7;
              pbVar51 = puVar28 + 3;
              puVar28 = puVar28 + 4;
              pbVar43[3] = *pbVar51;
              pbVar43 = pbVar43 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar6 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar6);
LAB_0001c78c:
          bVar6 = false;
        }
        iVar48 = 0;
        while (iVar49 = iVar48 + 1, iVar48 != 0xf) {
          iVar50 = iVar48 * 4;
          puVar29 = local_58 + iVar48 * 0x10 + iVar49;
          iVar52 = 0x10 - iVar49;
          bVar7 = local_4b8[iVar50 + 2];
          bVar22 = local_4b8[iVar50];
          bVar24 = local_4b8[iVar50 + 1];
          iVar50 = iVar49;
          if (0x10 < iVar48 + 2) {
            iVar52 = 1;
          }
          do {
            iVar48 = iVar50 * 4;
            iVar50 = iVar50 + 1;
            uVar8 = (ushort)((int)((uint)local_4b8[iVar48] - (uint)bVar22) >> 0x1f);
            uVar9 = (ushort)((int)((uint)local_4b8[iVar48 + 1] - (uint)bVar24) >> 0x1f);
            uVar10 = (ushort)((int)((uint)local_4b8[iVar48 + 2] - (uint)bVar7) >> 0x1f);
            *puVar29 = (int)(short)((uVar8 ^ (ushort)((uint)local_4b8[iVar48] - (uint)bVar22)) -
                                   uVar8) +
                       (int)(short)((uVar9 ^ (ushort)((uint)local_4b8[iVar48 + 1] - (uint)bVar24)) -
                                   uVar9) +
                       (int)(short)((uVar10 ^ (ushort)((uint)local_4b8[iVar48 + 2] - (uint)bVar7)) -
                                   uVar10);
            puVar29 = puVar29 + 1;
            iVar52 = iVar52 + -1;
            iVar48 = iVar49;
          } while (iVar52 != 0);
        }
        bVar5 = !bVar6;
        uVar26 = 0;
        do {
          iVar48 = 0;
          iVar49 = 0x10;
          do {
            local_4e0[iVar48] = (byte)iVar48;
            iVar48 = iVar48 + 1;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar48 = 0x10;
          uVar34 = 0;
          do {
            bVar7 = local_4e0[uVar34];
            uVar40 = uVar34 + 1;
            if ((bVar7 == uVar34) && ((int)uVar40 < 0x10)) {
              iVar49 = 0x10 - uVar40;
              pbVar33 = local_4e0 + uVar34 + 1;
              puVar29 = local_64 + uVar34 * 0x10 + uVar40;
              uVar34 = uVar40;
              do {
                if (*puVar29 < uVar26) {
                  if (uVar34 == *pbVar33) {
                    iVar48 = iVar48 + -1;
                    *pbVar33 = bVar7;
                  }
                  else if (*puVar29 < auStack_478[(uint)*pbVar33 * 0x10 + uVar34]) {
                    *pbVar33 = bVar7;
                  }
                }
                uVar34 = uVar34 + 1;
                puVar29 = puVar29 + 1;
                pbVar33 = pbVar33 + 1;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
            uVar34 = uVar40;
          } while (uVar40 != 0x10);
          uVar26 = uVar26 + 4;
        } while ((int)(bVar5 + 3) < iVar48);
        if (iVar48 < 1) {
          iVar25 = 0;
          iVar49 = 0;
        }
        else {
          iVar50 = 0;
          puVar17 = local_54;
          iVar49 = iVar48;
          do {
            *puVar17 = 0;
            local_508[iVar50] = 0;
            iVar50 = iVar50 + 1;
            puVar17[1] = 0;
            puVar17[2] = 0;
            puVar17 = puVar17 + 3;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar49 = 0;
          uVar26 = 0xffffffff;
          puVar17 = local_54;
          do {
            iVar50 = 0;
            pbVar33 = local_4e0;
            iVar52 = 0x10;
            do {
              if ((int)uVar26 < (int)(uint)local_4e0[iVar50]) {
                uVar26 = (uint)*pbVar33;
                break;
              }
              iVar50 = iVar50 + 1;
              pbVar33 = pbVar33 + 1;
              iVar52 = iVar52 + -1;
            } while (iVar52 != 0);
            if ((int)uVar26 < 0x10) {
              iVar50 = 0x10 - uVar26;
              pbVar33 = local_4e0 + uVar26;
              uVar34 = uVar26;
              do {
                if (uVar26 == *pbVar33) {
                  iVar52 = uVar34 * 4;
                  uVar8 = *puVar17;
                  bVar27 = local_508[iVar49];
                  *pbVar33 = (byte)iVar49;
                  bVar7 = local_4b8[iVar52];
                  bVar22 = local_4b8[iVar52 + 1];
                  bVar24 = local_4b8[iVar52 + 2];
                  local_508[iVar49] = bVar27 + 1;
                  *puVar17 = bVar7 + uVar8;
                  puVar17[1] = (ushort)bVar22 + puVar17[1];
                  puVar17[2] = (ushort)bVar24 + puVar17[2];
                }
                uVar34 = uVar34 + 1;
                pbVar33 = pbVar33 + 1;
                iVar50 = iVar50 + -1;
              } while (iVar50 != 0);
            }
            bVar7 = local_508[iVar49];
            iVar49 = iVar49 + 1;
            *puVar17 = *puVar17 / (ushort)bVar7;
            puVar17[1] = puVar17[1] / (ushort)bVar7;
            puVar17[2] = puVar17[2] / (ushort)bVar7;
            puVar17 = puVar17 + 3;
          } while (iVar48 != iVar49);
          iVar50 = 0;
          iVar49 = 0;
          iVar25 = 0;
          puVar17 = local_54;
          iVar52 = 0;
          do {
            iVar16 = iVar52 + 1;
            if (iVar16 < iVar48) {
              iVar42 = iVar48 - iVar16;
              puVar35 = local_54 + iVar16 * 3;
              iVar32 = iVar16;
              do {
                uVar8 = (short)(*puVar17 - *puVar35) >> 0xf;
                uVar9 = (short)(puVar17[1] - puVar35[1]) >> 0xf;
                uVar10 = (short)(puVar17[2] - puVar35[2]) >> 0xf;
                iVar37 = (int)(short)((uVar8 ^ *puVar17 - *puVar35) - uVar8) +
                         (int)(short)((uVar9 ^ puVar17[1] - puVar35[1]) - uVar9) +
                         (int)(short)((uVar10 ^ puVar17[2] - puVar35[2]) - uVar10);
                if (iVar50 < iVar37) {
                  iVar49 = iVar52;
                  iVar50 = iVar37;
                  iVar25 = iVar32;
                }
                iVar32 = iVar32 + 1;
                puVar35 = puVar35 + 3;
                iVar42 = iVar42 + -1;
              } while (iVar42 != 0);
            }
            puVar17 = puVar17 + 3;
            iVar52 = iVar16;
          } while (iVar48 != iVar16);
        }
        uVar8 = local_4d0[iVar49 * 3];
        uVar9 = local_4d0[iVar25 * 3];
        uVar10 = local_4d0[iVar49 * 3 + 2];
        uVar11 = local_4d0[iVar49 * 3 + 1];
        uVar12 = local_4d0[iVar25 * 3 + 2];
        uVar13 = local_4d0[iVar25 * 3 + 1];
        uVar40 = uVar8 & 0xf8;
        uVar26 = uVar10 & 0xf8;
        uVar34 = uVar11 & 0xfc;
        uVar20 = uVar9 & 0xf8;
        if ((uVar40 == (uVar9 & 0xf8)) && (uVar20 = uVar40, uVar8 != uVar9)) {
          if (uVar9 < uVar8) {
            if (uVar40 < 0xf8) {
              uVar40 = uVar40 + 8 & 0xf8;
            }
          }
          else if (uVar40 < 0xf8) {
            uVar20 = uVar40 + 8 & 0xff;
          }
        }
        uVar44 = uVar13 & 0xfc;
        if ((uVar34 == (uVar13 & 0xfc)) && (uVar44 = uVar34, uVar11 != uVar13)) {
          if (uVar13 < uVar11) {
            if (uVar34 < 0xfc) {
              uVar34 = uVar34 + 4 & 0xff;
            }
          }
          else if (uVar34 < 0xfc) {
            uVar44 = uVar34 + 4 & 0xff;
          }
        }
        uVar21 = uVar12 & 0xf8;
        if ((uVar26 == (uVar12 & 0xf8)) && (uVar21 = uVar26, uVar10 != uVar12)) {
          if (uVar12 < uVar10) {
            if (uVar26 < 0xf8) {
              uVar26 = uVar26 + 8 & 0xff;
            }
          }
          else if (uVar26 < 0xf8) {
            uVar21 = uVar26 + 8 & 0xff;
          }
        }
        uVar18 = uVar40 << 8 | uVar34 << 3;
        uVar15 = uVar20 << 8 | uVar44 << 3;
        uVar19 = uVar18 | uVar26 >> 3;
        uVar14 = uVar15 | uVar21 >> 3;
        bVar30 = (byte)uVar40;
        bVar27 = (byte)uVar34;
        bVar24 = (byte)uVar26;
        bVar36 = (byte)uVar20;
        bVar31 = (byte)uVar44;
        bVar22 = (byte)uVar21;
        bVar45 = (byte)uVar19;
        local_502 = (byte)uVar14;
        bVar7 = (byte)(uVar18 >> 8);
        local_501 = (byte)(uVar15 >> 8);
        if (bVar5) {
          if (uVar14 < uVar19) {
            local_4fc = bVar30;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_4f9 = bVar36;
            local_503 = bVar7;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_504 = bVar45;
          }
          else {
            local_4f9 = bVar30;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_4fc = bVar36;
            local_503 = local_501;
            local_501 = bVar7;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_504 = local_502;
            local_502 = bVar45;
          }
          local_4f6 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc * 2 + (uint)local_4f9) *
                             (longlong)local_6c) >> 0x20);
          local_4f5 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb * 2 + (uint)local_4f8) *
                             (longlong)local_6c) >> 0x20);
          local_4f4 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa * 2 + (uint)local_4f7) *
                             (longlong)local_6c) >> 0x20);
          local_4f3 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc + (uint)local_4f9 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f2 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb + (uint)local_4f8 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f1 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa + (uint)local_4f7 * 2) *
                             (longlong)local_6c) >> 0x20);
        }
        else {
          if (uVar14 < uVar19) {
            local_4fc = bVar36;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_4f9 = bVar30;
            local_503 = local_501;
            local_501 = bVar7;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_504 = local_502;
            local_502 = bVar45;
          }
          else {
            local_4f9 = bVar36;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_4fc = bVar30;
            local_503 = bVar7;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_504 = bVar45;
          }
          local_4f6 = (char)((int)((uint)local_4fc + (uint)local_4f9) >> 1);
          local_4f5 = (char)((int)((uint)local_4fb + (uint)local_4f8) >> 1);
          local_4f4 = (char)((int)((uint)local_4fa + (uint)local_4f7) >> 1);
        }
        local_4fd = 0;
        local_500 = 0;
        local_4ff = 0;
        local_4fe = 0;
        if (bVar5) {
          uVar26 = 4;
        }
        else {
          uVar26 = 3;
        }
        iVar48 = 0;
        pbVar43 = local_4b8 + 2;
        pbVar39 = local_4b8 + 1;
        pbVar51 = local_4b8 + 3;
        pbVar33 = local_68;
        do {
          uVar34 = (uint)*pbVar33;
          uVar40 = 0;
          pbVar23 = local_4b8 + iVar48 * 0x10 + 3;
          do {
            if ((!bVar6) || (uVar20 = 3, 0x7e < *pbVar23)) {
              if (uVar26 != 0) {
                bVar7 = pbVar23[(int)(local_4b8 + (iVar48 * 0x10 - (int)pbVar51))];
                bVar22 = pbVar23[(int)pbVar39 - (int)pbVar51];
                bVar24 = pbVar23[(int)pbVar43 - (int)pbVar51];
                pbVar41 = &local_4fc;
                iVar49 = 0;
                uVar20 = uVar26;
                do {
                  pbVar1 = pbVar41 + 1;
                  bVar27 = *pbVar41;
                  pbVar2 = pbVar41 + 2;
                  pbVar41 = pbVar41 + 3;
                  local_4f0[iVar49] =
                       ((uint)bVar7 - (uint)bVar27) * ((uint)bVar7 - (uint)bVar27) +
                       ((uint)bVar22 - (uint)*pbVar1) * ((uint)bVar22 - (uint)*pbVar1) * 4 +
                       ((uint)bVar24 - (uint)*pbVar2) * ((uint)bVar24 - (uint)*pbVar2);
                  uVar20 = uVar20 - 1;
                  iVar49 = iVar49 + 1;
                } while (uVar20 != 0);
              }
              if (uVar26 < 2) {
                uVar20 = 0;
              }
              else {
                iVar50 = uVar26 - 1;
                uVar44 = 1;
                piVar38 = local_4f0;
                uVar20 = 0;
                iVar49 = local_4f0[0];
                do {
                  piVar38 = piVar38 + 1;
                  if (*piVar38 < iVar49) {
                    uVar20 = uVar44;
                    iVar49 = *piVar38;
                  }
                  uVar44 = uVar44 + 1;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
                uVar20 = uVar20 & 3;
              }
            }
            bVar5 = uVar40 != 6;
            uVar44 = uVar40 & 0x3f;
            pbVar23 = pbVar23 + 4;
            uVar40 = uVar40 + 2;
            uVar34 = uVar20 << uVar44 | uVar34;
            *pbVar33 = (byte)uVar34;
          } while (bVar5);
          bVar5 = iVar48 != 3;
          pbVar51 = pbVar51 + 0x10;
          pbVar39 = pbVar39 + 0x10;
          pbVar43 = pbVar43 + 0x10;
          pbVar33 = pbVar33 + 1;
          iVar48 = iVar48 + 1;
        } while (bVar5);
        if (param_4 == 0xd) {
          if (bVar4) {
            param_6[7] = 0xff;
            *param_6 = 0xff;
            param_6[1] = 0xff;
            param_6[2] = 0xff;
            param_6[3] = 0xff;
            param_6[4] = 0xff;
            param_6[5] = 0xff;
            param_6[6] = 0xff;
            param_6 = param_6 + 8;
          }
          else {
            *param_6 = local_4b1 & 0xf0 | local_4b8[3] >> 4;
            param_6[1] = local_4a9 & 0xf0 | local_4ad >> 4;
            param_6[2] = local_4a1 & 0xf0 | local_4a5 >> 4;
            param_6[3] = local_499 & 0xf0 | local_49d >> 4;
            param_6[4] = local_491 & 0xf0 | local_495 >> 4;
            param_6[5] = local_489 & 0xf0 | local_48d >> 4;
            param_6[6] = local_481 & 0xf0 | local_485 >> 4;
            param_6[7] = local_479 & 0xf0 | local_47d >> 4;
            param_6 = param_6 + 8;
          }
        }
        else if (iStack00000024 == 0xe) {
          param_6 = (byte *)((int (*)())dxt5EncodeAlphaBlock)(local_4b8,param_6);
        }
        local_74 = local_74 + 4;
        *param_6 = local_504;
        param_6[1] = local_503;
        param_6[2] = local_502;
        param_6[3] = local_501;
        param_6[4] = local_500;
        param_6[5] = local_4ff;
        param_6[6] = local_4fe;
        param_6[7] = local_4fd;
        param_6 = param_6 + 8;
      } while (local_74 < param_1);
    }
    local_78 = local_78 + 4;
    if (local_70 <= local_78) {
      return;
    }
  } while( true );
}

/* dxtDecompressImage @ 0x1d1e0 (808 bytes) */
int dxtDecompressImage(width, height, depth, format, blocks, dstCursor)
  uint width;
  uint height;
  uint depth;
  int format;
  int blocks;
  int dstCursor;
{
  uint alphaIndex;
  int blockOffset;
  int blocksPerRowSafe;
  byte alphaPair;
  uint alpha0;
  int columnInBlockDxt1;
  int blockPtrDxt5;
  int blockColumnDxt5;
  int alphaWeightA;
  int columnInBlockDxt5;
  int blockPtr;
  int blockRowDxt1;
  int dstPixel;
  int blockColumn;
  int alphaWeightB;
  byte alphaByte;
  uint alphaIndexBits;
  uint columnInBlockDxt3;
  int blockIndex;
  uint alpha1;
  int blockRow;
  uint sliceIndex;
  int blocksPerRow;
  int rowInBlock;
  uint pixelInBlock;
  uint rowIndex;
  uint columnIndex;
  
  if (format == 0xd) {
    if (depth != 0) {
      blocksPerRow = ((int)width >> 2) + (uint)((int)width < 0 && (width & 3) != 0);
      sliceIndex = 0;
      do {
        if (height != 0) {
          rowIndex = 0;
          do {
            if (width != 0) {
              blockRow = ((int)rowIndex >> 2) + (uint)((int)rowIndex < 0 && (rowIndex & 3) != 0);
              columnIndex = 0;
              rowInBlock = rowIndex + blockRow * -4;
              do {
                blocksPerRowSafe = blocksPerRow;
                if (blocksPerRow == 0) {
                  blocksPerRowSafe = 1;
                }
                blockColumn = ((int)columnIndex >> 2) + (uint)((int)columnIndex < 0 && (columnIndex & 3) != 0);
                blockIndex = blockColumn + blocksPerRowSafe * blockRow;
                columnInBlockDxt3 = columnIndex + blockColumn * -4;
                blockOffset = blockIndex * 0x10;
                blockPtr = blocks + blockOffset;
                ((int (*)())dxt1DecodeColorIndex)((uint)CONCAT11(*(undefined1 *)(blockPtr + 9),*(undefined1 *)(blockPtr + 8)),
                             (uint)CONCAT11(*(undefined1 *)(blockPtr + 0xb),*(undefined1 *)(blockPtr + 10)
                                           ),
                             (int)(uint)*(byte *)(blockOffset + rowInBlock + blocks + 0xc) >>
                             (columnInBlockDxt3 * 2 & 0x3e) & 3,dstCursor);
                alphaPair = *(byte *)((blockIndex * 8 + rowInBlock) * 2 + blocks + ((int)columnInBlockDxt3 >> 1));
                if ((columnInBlockDxt3 & 1) == 0) {
                  alphaPair = alphaPair << 4;
                }
                columnIndex = columnIndex + 1;
                *(byte *)(dstCursor + 3) = alphaPair & 0xf0;
                dstCursor = dstCursor + 4;
              } while (columnIndex < width);
            }
            rowIndex = rowIndex + 1;
          } while (rowIndex < height);
        }
        sliceIndex = sliceIndex + 1;
      } while (sliceIndex < depth);
    }
  }
  else if (format == 0xe) {
    if (depth != 0) {
      blocksPerRow = ((int)width >> 1) + (uint)((int)width < 0 && (width & 1) != 0);
      sliceIndex = 0;
      do {
        if (height != 0) {
          rowIndex = 0;
          do {
            if (width != 0) {
              blockRow = ((int)rowIndex >> 2) + (uint)((int)rowIndex < 0 && (rowIndex & 3) != 0);
              columnIndex = 0;
              rowInBlock = rowIndex + blockRow * -4;
              do {
                blocksPerRowSafe = blocksPerRow;
                if (blocksPerRow == 0) {
                  blocksPerRowSafe = 1;
                }
                blockColumnDxt5 = ((int)columnIndex >> 2) + (uint)((int)columnIndex < 0 && (columnIndex & 3) != 0);
                columnInBlockDxt5 = columnIndex + blockColumnDxt5 * -4;
                blockOffset = (blockColumnDxt5 + blocksPerRowSafe * blockRow) * 0x10;
                pixelInBlock = columnInBlockDxt5 + rowInBlock * 4;
                blockPtrDxt5 = blocks + blockOffset;
                ((int (*)())dxt1DecodeColorIndex)((uint)CONCAT11(*(undefined1 *)(blockPtrDxt5 + 9),*(undefined1 *)(blockPtrDxt5 + 8)),
                             (uint)CONCAT11(*(undefined1 *)(blockPtrDxt5 + 0xb),*(undefined1 *)(blockPtrDxt5 + 10)
                                           ),
                             (int)(uint)*(byte *)(blockOffset + rowInBlock + blocks + 0xc) >>
                             (columnInBlockDxt5 * 2 & 0x3eU) & 3,dstCursor);
                alphaByte = *(byte *)(blocks + blockOffset);
                alpha0 = (uint)alphaByte;
                alpha1 = (uint)*(byte *)(blockPtrDxt5 + 1);
                if (rowInBlock < 2) {
                  alphaIndexBits = (uint)*(byte *)(blockPtrDxt5 + 4) << 0x10 | (uint)*(byte *)(blockPtrDxt5 + 3) << 8 |
                          (uint)*(byte *)(blockPtrDxt5 + 2);
                }
                else {
                  alphaIndexBits = (uint)*(byte *)(blockPtrDxt5 + 7) << 0x10 | (uint)*(byte *)(blockPtrDxt5 + 6) << 8 |
                          (uint)*(byte *)(blockPtrDxt5 + 5);
                }
                alphaIndex = alphaIndexBits >> ((pixelInBlock + (((int)pixelInBlock >> 3) +
                                             (uint)((int)pixelInBlock < 0 && (pixelInBlock & 7) != 0)) * -8) * 3
                                  & 0x3f) & 7;
                if (alpha0 <= alpha1) {
                  switch(alphaIndex) {
                  case 0:
                    goto code_r0x0001d62c;
                  case 1:
                    goto code_r0x0001d634;
                  case 2:
                    alphaByte = (byte)(uint)((ulonglong)
                                         ((longlong)(int)(alpha0 * 4 + alpha1) * 0x92492493) >> 0x22);
                    break;
                  case 3:
                    alphaWeightA = alpha0 * 3;
                    alphaWeightB = alpha1 << 1;
                    goto code_r0x0001d594;
                  case 4:
                    alphaWeightA = alpha1 * 3;
                    alphaWeightB = alpha0 << 1;
                    goto code_r0x0001d670;
                  case 5:
                    alphaByte = (byte)(uint)((ulonglong)
                                         ((longlong)(int)(alpha0 + alpha1 * 4) * 0x92492493) >> 0x22);
                    break;
                  default:
                    goto LAB_0001d6b0;
                  case 7:
                    alphaByte = 0xff;
                  }
                  goto code_r0x0001d6b4;
                }
                switch(alphaIndex) {
                case 0:
code_r0x0001d62c:
                  break;
                case 1:
code_r0x0001d634:
                  alphaByte = *(byte *)(blockPtrDxt5 + 1);
                  break;
                case 2:
                  alphaByte = (byte)(uint)((ulonglong)((longlong)(int)(alpha0 * 6 + alpha1) * 0x92492493)
                                      >> 0x22);
                  break;
                case 3:
                  alphaWeightA = alpha0 * 5;
                  alphaWeightB = alpha1 << 1;
                  goto code_r0x0001d594;
                case 4:
                  alphaWeightA = alpha1 * 3;
                  alphaWeightB = alpha0 << 2;
                  goto code_r0x0001d670;
                case 5:
                  alphaWeightA = alpha0 * 3;
                  alphaWeightB = alpha1 << 2;
code_r0x0001d594:
                  alphaByte = (byte)(uint)((ulonglong)((longlong)(alphaWeightA + alphaWeightB) * 0x92492493) >> 0x22);
                  break;
                case 6:
                  alphaWeightA = alpha1 * 5;
                  alphaWeightB = alpha0 << 1;
code_r0x0001d670:
                  alphaByte = (byte)(uint)((ulonglong)((longlong)(alphaWeightB + alphaWeightA) * 0x92492493) >> 0x22);
                  break;
                case 7:
                  alphaByte = (byte)(uint)((ulonglong)((longlong)(int)(alpha0 + alpha1 * 6) * 0x92492493)
                                      >> 0x22);
                  break;
                default:
LAB_0001d6b0:
                  alphaByte = 0;
                }
code_r0x0001d6b4:
                columnIndex = columnIndex + 1;
                *(byte *)(dstCursor + 3) = alphaByte;
                dstCursor = dstCursor + 4;
              } while (columnIndex < width);
            }
            rowIndex = rowIndex + 1;
          } while (rowIndex < height);
        }
        sliceIndex = sliceIndex + 1;
      } while (sliceIndex < depth);
    }
  }
  else if ((format == 0xc) && (depth != 0)) {
    blocksPerRow = ((int)width >> 2) + (uint)((int)width < 0 && (width & 3) != 0);
    sliceIndex = 0;
    do {
      if (height != 0) {
        rowIndex = 0;
        do {
          if (width != 0) {
            blockRowDxt1 = ((int)rowIndex >> 2) + (uint)((int)rowIndex < 0 && (rowIndex & 3) != 0);
            columnIndex = 0;
            dstPixel = dstCursor;
            do {
              blocksPerRowSafe = blocksPerRow;
              if (blocksPerRow == 0) {
                blocksPerRowSafe = 1;
              }
              blockColumn = ((int)columnIndex >> 2) + (uint)((int)columnIndex < 0 && (columnIndex & 3) != 0);
              dstCursor = dstPixel + 4;
              columnInBlockDxt1 = columnIndex + blockColumn * -4;
              columnIndex = columnIndex + 1;
              blockOffset = (blockColumn + blocksPerRowSafe * blockRowDxt1) * 8;
              blockPtr = blocks + blockOffset;
              ((int (*)())dxt1DecodeColorIndex)((uint)CONCAT11(*(undefined1 *)(blockPtr + 1),
                                          *(undefined1 *)(blocks + blockOffset)),
                           (uint)CONCAT11(*(undefined1 *)(blockPtr + 3),*(undefined1 *)(blockPtr + 2)),
                           (int)(uint)*(byte *)(rowIndex + blockRowDxt1 * -4 + blockOffset + blocks + 4) >>
                           (columnInBlockDxt1 * 2 & 0x3eU) & 3,dstPixel);
              dstPixel = dstCursor;
            } while (columnIndex < width);
          }
          rowIndex = rowIndex + 1;
        } while (rowIndex < height);
      }
      sliceIndex = sliceIndex + 1;
    } while (sliceIndex < depth);
  }
  return;
}

/* floatToHalfBits @ 0x1d7c0 (148 bytes) */
uint floatToHalfBits(double value)
{
  uint halfMantissa;
  float floatValue;
  int unbiasedExponent;
  uint biasedExponent;
  int halfExponent;
  
  floatValue = (float)value;
  biasedExponent = (uint)GH_F2U(floatValue) >> 0x17 & 0xff;
  unbiasedExponent = biasedExponent - 0x7f;
  if (unbiasedExponent < 0x11) {
    if (unbiasedExponent < -0xe) {
      if (unbiasedExponent < -0x25) {
        halfExponent = 0;
        halfMantissa = 0;
      }
      else {
        halfExponent = 0;
        halfMantissa = (((uint)GH_F2U(floatValue) & 0x7fffff | 0x800000) >> (-unbiasedExponent - 0xeU & 0x3f)) >> 0xd;
      }
    }
    else {
      halfExponent = biasedExponent - 0x70;
      halfMantissa = ((uint)GH_F2U(floatValue) & 0x7fffff) >> 0xd;
    }
  }
  else {
    halfExponent = 0x1f;
    halfMantissa = 0x3ff;
  }
  return ((uint)GH_F2U(floatValue) >> 0x1f) << 0xf | halfExponent << 10 | halfMantissa;
}

/* gld_validateVertexArrayStreams @ 0x1d880 (704 bytes) */
int gld_validateVertexArrayStreams(vertexArray, updateMode)
  int *vertexArray;
  int updateMode;
{
  int typeSizeOffset;
  int typeOffset;
  uint signedFlag;
  uint typeFlags;
  uint fetchElementCount;
  int dirtyState;
  int arrayDesc;
  bool isBaseMode;
  bool nothingPending;
  short rawTypeWord;
  bool allDirty;
  uint attrBit;
  int attrEntry;
  uint availableMask;
  uint attrStride;
  undefined1 *attrEnabledFlag;
  int entryOffset;
  uint typeIndex;
  int componentsMinusOne;
  uint attrAddress;
  uint pendingMask;
  undefined4 isValid;
  int dataSize;
  uint dataBase;
  int loopIndex;
  int attrIndex;
  
  isBaseMode = updateMode == 0;
  arrayDesc = *vertexArray;
  if (isBaseMode) {
    dataBase = *(uint *)(arrayDesc + 0x314);
  }
  else {
    dataBase = 0;
  }
  dataSize = *(int *)(arrayDesc + 0x318);
  if (((*(uint *)(vertexArray[1] + 0x88) & 1) == 0) || (!isBaseMode)) {
    allDirty = false;
  }
  else {
    allDirty = true;
  }
  if (isBaseMode) {
    if ((dataBase == 0) || (isValid = 1, dataSize == 0)) {
      isValid = 0;
    }
    if ((dataBase & 3) != 0) {
      isValid = 0;
    }
  }
  else {
    isValid = 1;
  }
  availableMask = *(uint *)(arrayDesc + 0x304) & 0xffff0000;
  if (!allDirty) {
    pendingMask = *(uint *)(vertexArray[1] + 0x88) & 0xff7f0000;
  }
  else {
    pendingMask = 0xff7f0000;
  }
  nothingPending = pendingMask == 0;
  attrIndex = 0;
  loopIndex = 0;
LAB_0001dae4:
  do {
    while (nothingPending) {
      availableMask = *(uint *)(arrayDesc + 0x300);
      if (!allDirty) {
        pendingMask = *(uint *)(vertexArray[1] + 0x84) & 0xffff;
      }
      else {
        pendingMask = 0xffff;
      }
      loopIndex = loopIndex + 1;
      if (1 < loopIndex) {
        dirtyState = vertexArray[1];
        *(undefined4 *)(dirtyState + 0x84) = 0;
        *(uint *)(dirtyState + 0x88) = *(uint *)(dirtyState + 0x88) & 0xfffb;
        return isValid;
      }
      nothingPending = pendingMask == 0;
      attrIndex = 0x10;
    }
    attrBit = *(uint *)(&DAT_001d91f0 + attrIndex * 4);
    if ((pendingMask & attrBit) != 0) {
      pendingMask = pendingMask & ~attrBit;
      attrEnabledFlag = (undefined1 *)((int)vertexArray + attrIndex + 8);
      nothingPending = pendingMask == 0;
      *(undefined1 *)((int)vertexArray + attrIndex + 8) = 1;
      if ((availableMask & attrBit) != 0) {
        entryOffset = attrIndex * 0x18;
        attrEntry = entryOffset + arrayDesc;
        attrAddress = *(uint *)(entryOffset + arrayDesc);
        fetchElementCount = (uint)*(short *)(attrEntry + 10);
        attrStride = *(uint *)(attrEntry + 4);
        componentsMinusOne = fetchElementCount - 1;
        typeIndex = (*(ushort *)(attrEntry + 8) & 0xffff7fff) - 0x1400;
        if (((!isBaseMode) || (((dataBase <= attrAddress && (attrAddress < dataSize + dataBase)) && ((attrAddress & 3) == 0)))
            ) && ((fetchElementCount < 5 && (attrStride < 0x200)))) {
          if ((attrStride & 3) == 0) {
            if ((typeIndex < 0xb) && (typeOffset = typeIndex * 4, *(int *)(&DAT_001d96f4 + typeOffset) == 1)) {
              if (attrStride != 0) {
                fetchElementCount = attrStride >> 2;
              }
              nothingPending = pendingMask == 0;
              typeSizeOffset = (typeOffset + componentsMinusOne) * 4;
              vertexArray[attrIndex + 10] =
                   *(uint *)(&DAT_001d9644 + typeSizeOffset) & 0x7f |
                   (fetchElementCount & 0x7f) << 8 | vertexArray[attrIndex + 10] & 0xffff8080U;
              vertexArray[attrIndex + 0x2a] = attrAddress - dataBase;
              signedFlag = *(uint *)(&DAT_001d9568 + typeOffset);
              typeFlags = *(uint *)(&DAT_001d9594 + typeSizeOffset);
              rawTypeWord = *(short *)(entryOffset + arrayDesc + 8);
              vertexArray[attrIndex + 0x6a] =
                   (*(uint *)(&DAT_001d92a8 + typeSizeOffset) & 7) << 9 |
                   (*(uint *)(&DAT_001d9358 + typeSizeOffset) & 7) << 6 |
                   (*(uint *)(&DAT_001d9408 + typeSizeOffset) & 7) << 3 |
                   *(uint *)(&DAT_001d94b8 + typeSizeOffset) & 7 | vertexArray[attrIndex + 0x6a] & 0xfffff000U;
              vertexArray[attrIndex + 0x4a] =
                   (uint)(int)rawTypeWord >> 0x10 & 0x8000 |
                   (signedFlag & 1) << 0xe | typeFlags & 0xf | vertexArray[attrIndex + 0x4a] & 0xffff3ff0U;
              goto LAB_0001dae0;
            }
            nothingPending = pendingMask == 0;
            *attrEnabledFlag = 0;
            goto LAB_0001dae4;
          }
        }
        nothingPending = pendingMask == 0;
        *attrEnabledFlag = 0;
        goto LAB_0001dae4;
      }
    }
LAB_0001dae0:
    attrIndex = attrIndex + 1;
  } while( true );
}

/* gldComputeVertexChunking @ 0x1db50 (180 bytes) */
int gldComputeVertexChunking(ctx, count, chunkVerts, chunkDwords, chunkCount, tailMode)
  int ctx;
  uint count;
  uint *chunkVerts;
  uint *chunkDwords;
  uint *chunkCount;
  int *tailMode;
{
  uint tailBytes;
  uint maxChunkVerts;
  uint chunkSize;
  
  maxChunkVerts = 0x7fe0;
  if (*(uint *)(ctx + 0x29d8) < 0x7ffd) {
    maxChunkVerts = *(uint *)(ctx + 0x29d8) & 0xffffffe0;
  }
  *chunkVerts = 0;
  *chunkCount = 0;
  *chunkDwords = 0;
  *tailMode = 0;
  if (count < maxChunkVerts) {
    *chunkVerts = count;
    if ((count & 0x1f) != 0) {
      *chunkVerts = count + 0x1f & 0xffffffe0;
    }
    tailBytes = 0;
    *chunkCount = 1;
    chunkSize = *chunkVerts;
  }
  else {
    *chunkVerts = maxChunkVerts;
    *chunkCount = count / maxChunkVerts;
    chunkSize = *chunkVerts;
    tailBytes = (count - (count / chunkSize) * chunkSize) + 3 & 0xfffffffc;
  }
  *chunkDwords = chunkSize >> 2;
  if (0x1fff < *chunkCount) {
    return 0;
  }
  *tailMode = 2 - (uint)(tailBytes == 0);
  return 1;
}

/* gld_prepareVertexArrayBacking @ 0x1dc10 (976 bytes) */
int gld_prepareVertexArrayBacking(ctx, vertexArray)
  undefined4 ctx;
  int *vertexArray;
{
  int chunkingResult;
  int validateResult;
  uint tailBytes;
  uint lineWordOffset;
  uint vertexCount;
  int gld_setVertexArrayAgpRefBackingResult;
  int gld_setVertexArrayNewTextureBackingResult;
  uint dataAddress;
  undefined4 *packetEnd;
  uint dirtyBits;
  int dirtyState;
  int *commandBuffer;
  int arrayDesc;
  uint tailMode;
  int chunkCount;
  uint chunkDwords;
  uint chunkVerts [3];
  
  dirtyState = vertexArray[1];
  arrayDesc = *vertexArray;
  if (*(int *)(dirtyState + 0x84) != 0 || (*(uint *)(dirtyState + 0x88) & 0xfffffff5) != 0) {
    validateResult = ((int (*)())gld_validateVertexArrayStreams)(vertexArray,0);
    if (validateResult == 0) {
      return 0;
    }
    dirtyState = vertexArray[1];
  }
  dirtyBits = *(uint *)(dirtyState + 0x88);
  if (*(int *)(dirtyState + 0x84) == 0 && dirtyBits == 0) {
    return 1;
  }
  if ((vertexArray[0x8a] != 0) && (((dirtyBits ^ 1) & 1) != 0)) {
    if (*(short *)(arrayDesc + 0x312) == -0x7a42) {
      if (vertexArray[0x8c] == 7) {
        if ((dirtyBits & 2) != 0) {
          *(undefined1 *)(vertexArray[0x8a] + 0x14) = 1;
          *(ushort *)(vertexArray[0x8a] + 0x1c) = *(ushort *)(vertexArray[0x8a] + 0x1c) | 1;
          *(ushort *)(vertexArray[0x8a] + 0x28) = *(ushort *)(vertexArray[0x8a] + 0x28) & 0xfffe;
          dirtyState = vertexArray[1];
        }
        goto LAB_0001dcf8;
      }
    }
    else if (vertexArray[0x8c] == 6) {
LAB_0001dcf8:
      *(undefined4 *)(dirtyState + 0x84) = 0;
      *(undefined4 *)(dirtyState + 0x88) = 0;
      return 1;
    }
  }
  chunkVerts[0] = 0;
  tailMode = 0;
  chunkCount = 0;
  chunkDwords = 0;
  chunkingResult = ((int (*)())gldComputeVertexChunking)(ctx,*(undefined4 *)(arrayDesc + 0x318),chunkVerts,&chunkDwords,&chunkCount,&tailMode
                      );
  if (chunkingResult != 0) {
    if (tailMode < 2) {
      vertexCount = *(uint *)(arrayDesc + 0x318);
      tailBytes = 0;
    }
    else {
      vertexCount = *(uint *)(arrayDesc + 0x318);
      tailBytes = (vertexCount - (vertexCount / chunkVerts[0]) * chunkVerts[0]) + 3 & 0xfffffffc;
    }
    if ((*(short *)(arrayDesc + 0x312) == -0x7a42) && (tailMode < 0x4f)) {
      gld_setVertexArrayNewTextureBackingResult = gld_setVertexArrayNewTextureBacking(ctx,vertexArray,(tailMode * 0x12 + 0xc) * 4,
                           tailBytes + chunkVerts[0] * chunkCount,*(undefined4 *)(arrayDesc + 0x314),vertexCount);
      if (gld_setVertexArrayNewTextureBackingResult != 0) goto LAB_0001ddc0;
      vertexCount = *(uint *)(arrayDesc + 0x318);
    }
    gld_setVertexArrayAgpRefBackingResult = gld_setVertexArrayAgpRefBacking(ctx,vertexArray,*(undefined4 *)(arrayDesc + 0x314),
                         *(undefined4 *)(arrayDesc + 0x314),vertexCount);
    if (gld_setVertexArrayAgpRefBackingResult != 0) {
LAB_0001ddc0:
      if (vertexArray[0x8c] == 7) {
        lineWordOffset = *(uint *)(arrayDesc + 0x314);
        *(undefined1 *)(vertexArray[0x8a] + 0x15) = 0;
        lineWordOffset = (lineWordOffset & 0xfff) - (lineWordOffset & 0xfe0) >> 2;
        *(undefined1 *)(vertexArray[0x8a] + 0x17) = 0;
        *(undefined1 *)(vertexArray[0x8a] + 0x34) = 1;
        *(undefined1 *)(vertexArray[0x8a] + 0x35) = 1;
        commandBuffer = (int *)vertexArray[0x8b];
        commandBuffer[0x280] = (int)((unsigned char *)0x00001393U);
        commandBuffer[8] = commandBuffer[8] & 0xafffffffU | 0xa0000000;
        commandBuffer[0x281] = 10;
        commandBuffer[0x287] = 2;
        commandBuffer[0x285] = 2;
        commandBuffer[0x283] = 0x20000;
        commandBuffer[0x284] = 0x575;
        commandBuffer[0x282] = 0x5c8;
        commandBuffer[0x286] = 0x574;
        *(short *)(commandBuffer + 0x10) = (short)((int)(commandBuffer + 0x288) - (int)(commandBuffer + 0x280) >> 2);
        dataAddress = *(uint *)(arrayDesc + 0x314);
        commandBuffer[0x12] = 0;
        commandBuffer[0x11] = dataAddress & 0xfe0;
        commandBuffer[0x13] = chunkVerts[0] * chunkCount;
        commandBuffer[0x14] = chunkVerts[0] * chunkCount;
        commandBuffer[0x15] = 0;
        *(short *)((int)commandBuffer + 0x42) = (short)tailMode;
        commandBuffer[0x17] = 0;
        packetEnd = (undefined4 *)
                 FUN_00030a60(commandBuffer + 0x288,6,chunkVerts[0],chunkVerts[0],0,lineWordOffset,
                              chunkCount << 0x10 | chunkDwords);
        if (tailBytes != 0) {
          packetEnd = (undefined4 *)
                   FUN_00030a60(packetEnd,6,chunkVerts[0],chunkVerts[0],0,lineWordOffset,tailBytes >> 2 | 0x10000);
        }
        *(ushort *)(vertexArray[0x8a] + 0x1c) = *(ushort *)(vertexArray[0x8a] + 0x1c) | 1;
        *(ushort *)(vertexArray[0x8a] + 0x28) = *(ushort *)(vertexArray[0x8a] + 0x28) & 0xfffe;
        *packetEnd = 0xd0b;
        packetEnd[2] = 0x5c8;
        packetEnd[1] = 5;
        packetEnd[3] = 0x10000;
        *commandBuffer = (int)packetEnd + (0x10 - (int)(commandBuffer + 0x280)) >> 2;
      }
      *(undefined1 *)(vertexArray[0x8a] + 0x14) = 1;
      dirtyState = vertexArray[1];
      *(undefined4 *)(dirtyState + 0x84) = 0;
      *(undefined4 *)(dirtyState + 0x88) = 0;
      return 1;
    }
  }
  return 0;
}

/* gld_startPacket @ 0x1dff0 (140 bytes) */
int gld_startPacket(ctx)
  int ctx;
{
  undefined4 *packet;
  int ringPtr;
  uint *headerWord;
  
  ringPtr = (**(code **)(ctx + GLD_streamAllocate))(ctx + GLD_commandStream,1);
  *(int *)(ctx + GLD_streamCurrent) = ringPtr;
  headerWord = *(uint **)(ctx + GLD_lastHeader);
  *headerWord = ringPtr - (int)headerWord >> 2 | *headerWord;
  packet = *(undefined4 **)(ctx + GLD_streamCurrent);
  *(undefined4 **)(ctx + GLD_lastHeader) = packet;
  *packet = 0x3a000000;
  *(undefined4 **)(ctx + GLD_streamCurrent) = packet + 1;
  /* Ghidra dropped this tail-call's 2nd arg (bctr preserves whatever's in r4 - confirmed via stock
   * disassembly 0x1e050-0x1e078: r4 is explicitly loaded as r2+4 (== packet+1, the just-advanced
   * write pointer) right before the tail jump through the vtable slot at +0x299c, which is
   * FUN_0002be60, the ring-buffer "set current pointer" setter (ctx, new_ptr). Without this arg,
   * whatever garbage was left in r4 (observed live: leftover "1" from this function's own earlier
   * call) got installed as the ring buffer's current write pointer, corrupting it for every
   * subsequent allocation through this object - root cause of the post-gldCreateContext GLDriver
   * crash tracked in issue #64. */
  (**(code **)(ctx + GLD_streamSetCurrent))(ctx + GLD_commandStream,packet + 1);
  return;
}

/* _gldPageoffBuffer @ 0x1e080 (480 bytes) */
int _gldPageoffBuffer(ctx, buffer)
  int ctx;
  int buffer;
{
  char kind;
  int waitStatus;
  undefined4 *pluginRecord;
  int handleOwner;
  undefined4 scalarIn0;
  undefined4 scalarIn1;
  
  if (*(int *)(buffer + 8) != 0) {
    _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
    pluginRecord = (undefined4 *)**(undefined4 **)(buffer + 8);
    kind = (*(unsigned char *)((unsigned char *)&(MACH_HEADER.sizeofcmds) + 2));
    if ((pluginRecord == (undefined4 *)0x0) ||
       (kind = *(char *)((int)pluginRecord + 0x16), *(char *)((int)pluginRecord + 0x16) != '\a')) {
      if (kind == '\x06') {
        if ((0x1ffff < (int)pluginRecord[4]) &&
           (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor))) {
          ((int (*)())gld_submitRing)(ctx,0x1000000);
        }
        if ((*(ushort *)(pluginRecord + 10) & ~*(ushort *)(pluginRecord + 7) & 1) != 0) {
          handleOwner = ((int (*)())gld_isStampRetired)(ctx,pluginRecord[3]);
          if (handleOwner == 0) {
            _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),9,pluginRecord + 3,1,0,0);
          }
          *(ushort *)(pluginRecord + 7) = *(ushort *)(pluginRecord + 7) | *(ushort *)(pluginRecord + 10);
        }
      }
    }
    else {
      if ((0x1ffff < (int)pluginRecord[4]) &&
         (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor))) {
        ((int (*)())gld_submitRing)(ctx,0x1000000);
      }
      if ((*(ushort *)(pluginRecord + 10) & ~*(ushort *)(pluginRecord + 7) & 1) != 0) {
        scalarIn0 = *pluginRecord;
        scalarIn1 = 0;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xd,&scalarIn0,2,0,0);
      }
      handleOwner = *(int *)(*(int *)(buffer + 8) + 4);
      if ((*(uint *)(handleOwner + 0x20) & 0x10000000) != 0) {
        waitStatus = ((int (*)())gld_isStampRetired)(ctx,*(undefined4 *)(handleOwner + 0x1c));
        if (waitStatus == 0) {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),9,handleOwner + 0x1c,1,0,0);
        }
        *(uint *)(handleOwner + 0x20) = *(uint *)(handleOwner + 0x20) & 0xefffffff;
      }
    }
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  }
  return;
}

/* returnZero_1e270 @ 0x1e270 (8 bytes) */
int returnZero_1e270()
{
  return 0;
}

/* gld_prepareBufferBacking @ 0x1e280 (1184 bytes) */
int gld_prepareBufferBacking(ctx, bufferObject, mode)
  int ctx;
  undefined4 *bufferObject;
  int mode;
{
  int gld_setBufferAgpRefBackingResult;
  int gld_setBufferNewTextureBackingResult;
  bool isDefaultMode;
  undefined4 uVar2;
  uint uVar3;
  undefined4 staleArgR6;
  int iVar4;
  uint uVar5;
  uint *dirtyState;
  uint uVar7;
  int iVar8;
  undefined4 *packetEnd;
  undefined4 *packetCursor;
  uint tailBytes;
  int *commandBuffer;
  uint *bufferDesc;
  uint tailMode;
  int chunkCount;
  uint chunkDwords;
  uint chunkVerts [6];
  
  isDefaultMode = mode == 0;
  if (isDefaultMode) {
    *(undefined1 *)(bufferObject + 3) = 1;
  }
  bufferDesc = (uint *)*bufferObject;
  if (*bufferDesc == 0) {
    return 0;
  }
  if (((int *)bufferObject[2] == (int *)0x0) || (iVar4 = *(int *)bufferObject[2], iVar4 == 0)) {
LAB_0001e3b0:
    chunkVerts[0] = 0;
    tailMode = 0;
    chunkCount = 0;
    chunkDwords = 0;
    iVar4 = ((int (*)())gldComputeVertexChunking)(ctx,bufferDesc[1],chunkVerts,&chunkDwords,&chunkCount,&tailMode);
    if (iVar4 == 0) {
      return 0;
    }
    if (tailMode < 2) {
      uVar7 = bufferDesc[1];
      tailBytes = 0;
    }
    else {
      uVar7 = bufferDesc[1];
      tailBytes = (uVar7 - (uVar7 / chunkVerts[0]) * chunkVerts[0]) + 3 & 0xfffffffc;
    }
    uVar5 = uVar7;
    if ((*(short *)(bufferDesc + 3) == -0x771c) && (tailMode < 0x4f)) {
      if (isDefaultMode) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0x49;
      }
      uVar5 = *bufferDesc;
      uVar3 = tailBytes + chunkVerts[0] * chunkCount;
      gld_setBufferNewTextureBackingResult = gld_setBufferNewTextureBacking(ctx,bufferObject,iVar4 + (tailMode * 0x12 + 0xc) * 4,uVar3,uVar5,uVar7);
      if (gld_setBufferNewTextureBackingResult == 0) {
        uVar5 = bufferDesc[1];
        goto LAB_0001e440;
      }
    }
    else {
LAB_0001e440:
      uVar3 = *bufferDesc;
      gld_setBufferAgpRefBackingResult = gld_setBufferAgpRefBacking(ctx,bufferObject,uVar3,uVar3,uVar5);
      if (gld_setBufferAgpRefBackingResult == 0) {
        return 0;
      }
    }
    if (bufferObject[4] == 7) {
      uVar7 = *bufferDesc;
      uVar5 = 0;
      *(undefined1 *)(*(int *)bufferObject[2] + 0x15) = 0;
      uVar7 = (uVar7 & 0xfff) - (uVar7 & 0xfe0) >> 2;
      *(undefined1 *)(*(int *)bufferObject[2] + 0x17) = 0;
      *(undefined1 *)(*(int *)bufferObject[2] + 0x34) = 1;
      *(undefined1 *)(*(int *)bufferObject[2] + 0x35) = 1;
      commandBuffer = *(int **)(bufferObject[2] + 4);
      commandBuffer[0x280] = (int)((unsigned char *)0x00001393U);
      commandBuffer[8] = commandBuffer[8] & 0xbfffffffU | 0xa0000000;
      commandBuffer[0x281] = 10;
      commandBuffer[0x283] = 0x20000;
      commandBuffer[0x287] = 2;
      commandBuffer[0x285] = 2;
      commandBuffer[0x284] = 0x575;
      commandBuffer[0x282] = 0x5c8;
      commandBuffer[0x286] = 0x574;
      *(short *)(commandBuffer + 0x10) = (short)((int)(commandBuffer + 0x288) - (int)(commandBuffer + 0x280) >> 2);
      uVar3 = *bufferDesc;
      commandBuffer[0x12] = 0;
      commandBuffer[0x11] = uVar3 & 0xfe0;
      commandBuffer[0x13] = chunkVerts[0] * chunkCount;
      commandBuffer[0x14] = chunkVerts[0] * chunkCount;
      commandBuffer[0x17] = 0;
      commandBuffer[0x15] = 0;
      *(short *)((int)commandBuffer + 0x42) = (short)tailMode;
      uVar3 = chunkVerts[0];
      packetEnd = (undefined4 *)
               FUN_00030a60(commandBuffer + 0x288,6,chunkVerts[0],chunkVerts[0],0,uVar7,
                            chunkCount << 0x10 | chunkDwords);
      if (tailBytes != 0) {
        uVar5 = 0;
        uVar3 = chunkVerts[0];
        packetEnd = (undefined4 *)
                 FUN_00030a60(packetEnd,6,chunkVerts[0],chunkVerts[0],0,uVar7,tailBytes >> 2 | 0x10000);
      }
      packetCursor = packetEnd + 4;
      *(ushort *)(*(int *)bufferObject[2] + 0x1c) = *(ushort *)(*(int *)bufferObject[2] + 0x1c) | 1;
      *(ushort *)(*(int *)bufferObject[2] + 0x28) = *(ushort *)(*(int *)bufferObject[2] + 0x28) & 0xfffe;
      *packetEnd = 0xd0b;
      packetEnd[2] = 0x5c8;
      packetEnd[1] = 5;
      packetEnd[3] = 0x10000;
      if (!isDefaultMode) {
        uVar2 = *(undefined4 *)(ctx + 0x1d74);
        packetCursor = packetEnd + 5;
        packetEnd[4] = 0x4790b1;
        iVar4 = 0x48;
        do {
          *packetCursor = uVar2;
          packetCursor = packetCursor + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      *commandBuffer = (int)packetCursor - (int)(commandBuffer + 0x280) >> 2;
    }
    iVar4 = *(int *)bufferObject[2];
    *(undefined1 *)(iVar4 + 0x14) = 1;
    dirtyState = (uint *)bufferObject[1];
    if (((*dirtyState & 2) == 0) || ((*(uint *)(ctx + 0x24) & 2) == 0)) goto LAB_0001e6e0;
    gldFlushDataCacheRange(ctx,*bufferDesc,bufferDesc[2],uVar3,uVar5,dirtyState,iVar4,packetEnd);
  }
  else {
    dirtyState = (uint *)bufferObject[1];
    tailBytes = *dirtyState;
    packetEnd = (undefined4 *)(tailBytes ^ 1);
    if (((uint)packetEnd & 1) == 0) goto LAB_0001e3b0;
    if (*(short *)(bufferDesc + 3) != -0x771c) {
      if (bufferObject[4] == 6) {
        if (((tailBytes & 2) != 0) && ((*(uint *)(ctx + 0x24) & 2) != 0)) {
          gldFlushDataCacheRange(ctx,*bufferDesc,bufferDesc[2],staleArgR6,iVar4,dirtyState,0,tailBytes & 2);
          dirtyState = (uint *)bufferObject[1];
        }
        goto LAB_0001e6e0;
      }
      goto LAB_0001e3b0;
    }
    if (bufferObject[4] != 7) goto LAB_0001e3b0;
    if ((tailBytes & 2) == 0) goto LAB_0001e6e0;
    *(undefined1 *)(iVar4 + 0x14) = 1;
    *(ushort *)(*(int *)bufferObject[2] + 0x1c) = *(ushort *)(*(int *)bufferObject[2] + 0x1c) | 1;
    iVar8 = *(int *)bufferObject[2];
    *(ushort *)(iVar8 + 0x28) = *(ushort *)(iVar8 + 0x28) & 0xfffe;
    if ((*(uint *)(ctx + 0x24) & 2) != 0) {
      gldFlushDataCacheRange(ctx,*bufferDesc,bufferDesc[2],staleArgR6,iVar4,dirtyState,iVar8,tailBytes & 2);
      dirtyState = (uint *)bufferObject[1];
      goto LAB_0001e6e0;
    }
  }
  dirtyState = (uint *)bufferObject[1];
LAB_0001e6e0:
  *dirtyState = 0;
  return 1;
}

/* gld_prepareVertexArrayBuffers @ 0x1e730 (332 bytes) */
int gld_prepareVertexArrayBuffers(ctx, vertexArray)
  undefined4 ctx;
  int *vertexArray;
{
  int loopIndex;
  bool nonePending;
  undefined4 isReady;
  int validateResult;
  int iVar4;
  uint pendingMask;
  int dirtyState;
  int arrayDesc;
  int attrIndex;
  uint attrBit;
  
  arrayDesc = *vertexArray;
  dirtyState = vertexArray[1];
  pendingMask = *(uint *)(arrayDesc + 0x304);
  if ((*(uint *)(arrayDesc + 0x300) & ~*(uint *)(arrayDesc + 0x308)) == 0 &&
      (pendingMask & ~*(uint *)(arrayDesc + 0x30c)) == 0) {
    if (*(int *)(dirtyState + 0x84) != 0 || (*(uint *)(dirtyState + 0x88) & 0xfffffff5) != 0) {
      validateResult = ((int (*)())gld_validateVertexArrayStreams)(vertexArray,1);
      if (validateResult == 0) goto LAB_0001e86c;
      pendingMask = *(uint *)(arrayDesc + 0x304);
    }
    pendingMask = pendingMask & 0xffff0000;
    attrIndex = 0;
    loopIndex = 0;
    nonePending = pendingMask == 0;
    while( true ) {
      while (!nonePending) {
        attrBit = *(uint *)(&DAT_001d91f0 + attrIndex * 4);
        if ((pendingMask & attrBit) != 0) {
          iVar4 = *(int *)(attrIndex * 4 + dirtyState);
          if ((iVar4 == 0) || (iVar4 = ((int (*)())gld_prepareBufferBacking)(ctx,iVar4,0), iVar4 == 0))
          goto LAB_0001e86c;
          pendingMask = pendingMask & ~attrBit;
          nonePending = pendingMask == 0;
        }
        attrIndex = attrIndex + 1;
      }
      loopIndex = loopIndex + 1;
      pendingMask = *(uint *)(arrayDesc + 0x300) & 0xffff;
      if (1 < loopIndex) break;
      nonePending = pendingMask == 0;
      attrIndex = 0x10;
    }
    if (*(int *)(dirtyState + 0x80) != 0) {
      ((int (*)())gld_prepareBufferBacking)(ctx,*(int *)(dirtyState + 0x80),1);
    }
    dirtyState = vertexArray[1];
    isReady = 1;
    *(undefined4 *)(dirtyState + 0x84) = 0;
    *(undefined4 *)(dirtyState + 0x88) = 0;
  }
  else {
LAB_0001e86c:
    isReady = 0;
  }
  return isReady;
}

/* copyIndices16Swapped_prefetch_entry @ 0x1e890 (16 bytes) */
int copyIndices16Swapped_prefetch_entry(dst, src, count)
  uint *dst;
  uint *src;
  uint count;
{
  vec16 loadedVecB;
  vec16 permutedVecA;
  uint *nextVecPtr;
  uint swapWord;
  uint *prefetchCursor;
  uint *dstEnd;
  vec16 loadedVecA;
  vec16 permutedVecB;
  vec16 carryVec;
  vec16 alignPermute;
  vec16 permutedVecD;
  vec16 loadedVecE;
  
  dstEnd = (uint *)((int)dst + (count & 0x7ffffffe) * 2);
  for (; ((uint)dst & 0x1f) != 0; dst = dst + 1) {
    swapWord = *src;
    src = src + 1;
    *dst = swapWord << 0x10 | swapWord >> 0x10;
  }
  carryVec = *(vec16 *)((uint)src & 0xfffffff0);
  alignPermute = *(vec16 *)
            (((uint)src & 0xf) * 0x10 + *(int *)PTR_DAT_001e88cc & 0xfffffff0);
  for (prefetchCursor = src; prefetchCursor < src + 0x38; prefetchCursor = prefetchCursor + 8) {
    dataCacheBlockTouch(prefetchCursor);
  }
  for (; dst < dstEnd + -0x40; dst = dst + 0x10) {
    dataCacheBlockTouch(src + 0x38);
    loadedVecA = *(vec16 *)((uint)(src + 0xc) & 0xfffffff0);
    loadedVecE = *(vec16 *)((uint)(src + 8) & 0xfffffff0);
    permutedVecD = vectorPermute(carryVec,*(vec16 *)((uint)(src + 4) & 0xfffffff0),alignPermute);
    dataCacheBlockTouch(src + 0x40);
    carryVec = *(vec16 *)((uint)(src + 0x10) & 0xfffffff0);
    permutedVecB = vectorPermute(*(vec16 *)((uint)(src + 4) & 0xfffffff0),loadedVecE,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = permutedVecD;
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = permutedVecB;
    permutedVecB = vectorPermute(loadedVecE,loadedVecA,alignPermute);
    loadedVecA = vectorPermute(loadedVecA,carryVec,alignPermute);
    dataCacheBlockAllocate(dst + 8);
    *(vec16 *)((uint)(dst + 8) & 0xfffffff0) = permutedVecB;
    *(vec16 *)((uint)(dst + 0xc) & 0xfffffff0) = loadedVecA;
    src = src + 0x10;
  }
  for (; dst < dstEnd + -0x10; dst = dst + 0x10) {
    nextVecPtr = src + 4;
    loadedVecE = *(vec16 *)((uint)(src + 8) & 0xfffffff0);
    loadedVecB = *(vec16 *)((uint)(src + 0xc) & 0xfffffff0);
    src = src + 0x10;
    permutedVecD = vectorPermute(carryVec,*(vec16 *)((uint)nextVecPtr & 0xfffffff0),alignPermute);
    carryVec = *(vec16 *)((uint)src & 0xfffffff0);
    permutedVecA = vectorPermute(*(vec16 *)((uint)nextVecPtr & 0xfffffff0),loadedVecE,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = permutedVecD;
    permutedVecD = vectorPermute(loadedVecE,loadedVecB,alignPermute);
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = permutedVecA;
    permutedVecA = vectorPermute(loadedVecB,carryVec,alignPermute);
    dataCacheBlockAllocate(dst + 8);
    *(vec16 *)((uint)(dst + 8) & 0xfffffff0) = permutedVecD;
    *(vec16 *)((uint)(dst + 0xc) & 0xfffffff0) = permutedVecA;
  }
  if (dst + 8 < dstEnd) {
    loadedVecA = *(vec16 *)((uint)(src + 4) & 0xfffffff0);
    carryVec = vectorPermute(carryVec,loadedVecA,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = carryVec;
    src = src + 8;
    carryVec = *(vec16 *)((uint)src & 0xfffffff0);
    loadedVecA = vectorPermute(loadedVecA,carryVec,alignPermute);
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = loadedVecA;
    dst = dst + 8;
  }
  if (dst + 4 < dstEnd) {
    nextVecPtr = src + 4;
    src = src + 4;
    carryVec = vectorPermute(carryVec,*(vec16 *)((uint)nextVecPtr & 0xfffffff0),alignPermute);
    *(vec16 *)((uint)dst & 0xfffffff0) = carryVec;
    dst = dst + 4;
  }
  else if (dstEnd <= dst) goto LAB_0001eabc;
  do {
    swapWord = *src;
    src = src + 1;
    *dst = swapWord << 0x10 | swapWord >> 0x10;
    dst = dst + 1;
  } while (dst < dstEnd);
LAB_0001eabc:
  if ((count & 1) != 0) {
    *dst = (uint)*(ushort *)src;
  }
  return;
}

/* copyIndices16Swapped_prefetch @ 0x1e8a0 (564 bytes) */
int copyIndices16Swapped_prefetch(dst, src, count)
  uint *dst;
  uint *src;
  uint count;
{
  vec16 loadedVecB;
  vec16 permutedVecA;
  uint *nextVecPtr;
  uint swapWord;
  uint *prefetchCursor;
  uint *dstEnd;
  vec16 loadedVecA;
  vec16 permutedVecB;
  vec16 carryVec;
  vec16 alignPermute;
  vec16 permutedVecD;
  vec16 loadedVecE;
  
  dstEnd = (uint *)((int)dst + (count & 0x7ffffffe) * 2);
  for (; ((uint)dst & 0x1f) != 0; dst = dst + 1) {
    swapWord = *src;
    src = src + 1;
    *dst = swapWord << 0x10 | swapWord >> 0x10;
  }
  carryVec = *(vec16 *)((uint)src & 0xfffffff0);
  alignPermute = *(vec16 *)
            (((uint)src & 0xf) * 0x10 + *(int *)PTR_DAT_001e88cc & 0xfffffff0);
  for (prefetchCursor = src; prefetchCursor < src + 0x38; prefetchCursor = prefetchCursor + 8) {
    dataCacheBlockTouch(prefetchCursor);
  }
  for (; dst < dstEnd + -0x40; dst = dst + 0x10) {
    dataCacheBlockTouch(src + 0x38);
    loadedVecA = *(vec16 *)((uint)(src + 0xc) & 0xfffffff0);
    loadedVecE = *(vec16 *)((uint)(src + 8) & 0xfffffff0);
    permutedVecD = vectorPermute(carryVec,*(vec16 *)((uint)(src + 4) & 0xfffffff0),alignPermute);
    dataCacheBlockTouch(src + 0x40);
    carryVec = *(vec16 *)((uint)(src + 0x10) & 0xfffffff0);
    permutedVecB = vectorPermute(*(vec16 *)((uint)(src + 4) & 0xfffffff0),loadedVecE,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = permutedVecD;
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = permutedVecB;
    permutedVecB = vectorPermute(loadedVecE,loadedVecA,alignPermute);
    loadedVecA = vectorPermute(loadedVecA,carryVec,alignPermute);
    dataCacheBlockAllocate(dst + 8);
    *(vec16 *)((uint)(dst + 8) & 0xfffffff0) = permutedVecB;
    *(vec16 *)((uint)(dst + 0xc) & 0xfffffff0) = loadedVecA;
    src = src + 0x10;
  }
  for (; dst < dstEnd + -0x10; dst = dst + 0x10) {
    nextVecPtr = src + 4;
    loadedVecE = *(vec16 *)((uint)(src + 8) & 0xfffffff0);
    loadedVecB = *(vec16 *)((uint)(src + 0xc) & 0xfffffff0);
    src = src + 0x10;
    permutedVecD = vectorPermute(carryVec,*(vec16 *)((uint)nextVecPtr & 0xfffffff0),alignPermute);
    carryVec = *(vec16 *)((uint)src & 0xfffffff0);
    permutedVecA = vectorPermute(*(vec16 *)((uint)nextVecPtr & 0xfffffff0),loadedVecE,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = permutedVecD;
    permutedVecD = vectorPermute(loadedVecE,loadedVecB,alignPermute);
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = permutedVecA;
    permutedVecA = vectorPermute(loadedVecB,carryVec,alignPermute);
    dataCacheBlockAllocate(dst + 8);
    *(vec16 *)((uint)(dst + 8) & 0xfffffff0) = permutedVecD;
    *(vec16 *)((uint)(dst + 0xc) & 0xfffffff0) = permutedVecA;
  }
  if (dst + 8 < dstEnd) {
    loadedVecA = *(vec16 *)((uint)(src + 4) & 0xfffffff0);
    carryVec = vectorPermute(carryVec,loadedVecA,alignPermute);
    dataCacheBlockAllocate(dst);
    *(vec16 *)((uint)dst & 0xfffffff0) = carryVec;
    src = src + 8;
    carryVec = *(vec16 *)((uint)src & 0xfffffff0);
    loadedVecA = vectorPermute(loadedVecA,carryVec,alignPermute);
    *(vec16 *)((uint)(dst + 4) & 0xfffffff0) = loadedVecA;
    dst = dst + 8;
  }
  if (dst + 4 < dstEnd) {
    nextVecPtr = src + 4;
    src = src + 4;
    carryVec = vectorPermute(carryVec,*(vec16 *)((uint)nextVecPtr & 0xfffffff0),alignPermute);
    *(vec16 *)((uint)dst & 0xfffffff0) = carryVec;
    dst = dst + 4;
  }
  else if (dstEnd <= dst) goto LAB_0001eabc;
  do {
    swapWord = *src;
    src = src + 1;
    *dst = swapWord << 0x10 | swapWord >> 0x10;
    dst = dst + 1;
  } while (dst < dstEnd);
LAB_0001eabc:
  if ((count & 1) != 0) {
    *dst = (uint)*(ushort *)src;
  }
  return;
}

/* copyIndices16Swapped_dcbz_entry @ 0x1eae0 (16 bytes) */
int copyIndices16Swapped_dcbz_entry(dst, src, count)
  uint dst;
  uint src;
  uint count;
{
  vec16 tempVec;
  uint swapWord;
  uint dstMisalign;
  uint *vecPtr1;
  uint *vecPtr2;
  uint *vecPtr3;
  uint *dstCursor;
  uint dcbzAddress;
  uint *srcCursor;
  uint *dstEnd;
  vec16 carryVec;
  vec16 outVec2;
  vec16 alignPermute;
  vec16 outVec1;
  vec16 outVec0;
  
  dstEnd = (uint *)(dst + (count & 0x7ffffffe) * 2);
  for (dcbzAddress = dst + 0x7f & 0xffffff80; dcbzAddress < ((uint)dstEnd & 0xffffff80);
      dcbzAddress = dcbzAddress + 0x80) {
    dataCacheBlockClearToZero(dcbzAddress);
  }
  dstMisalign = dst & 0xf;
  dstCursor = (uint *)(dst - dstMisalign);
  srcCursor = (uint *)(src - dstMisalign);
  alignPermute = *(vec16 *)
             (*(int *)PTR_DAT_001e88cc + ((int)srcCursor * 0x10 & 0xf0U) & 0xfffffff0);
  carryVec = *(vec16 *)(src & 0xfffffff0);
  if (dstMisalign != 0) {
    carryVec = *(vec16 *)((uint)(srcCursor + 4) & 0xfffffff0);
    srcCursor = srcCursor + 4;
    tempVec = vectorPermute(*(vec16 *)(src & 0xfffffff0),carryVec,alignPermute);
    tempVec = vectorConditionalSelect
                       (*(vec16 *)((uint)dstCursor & 0xfffffff0),tempVec,
                        *(vec16 *)
                         (*(int *)PTR_DAT_001e88cc + dstMisalign * 0x10 + 0x100 & 0xfffffff0));
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = tempVec;
    dstCursor = dstCursor + 4;
  }
  for (; dstCursor < dstEnd + -0x10; dstCursor = dstCursor + 0x10) {
    vecPtr1 = srcCursor + 4;
    vecPtr2 = srcCursor + 8;
    vecPtr3 = srcCursor + 0xc;
    srcCursor = srcCursor + 0x10;
    outVec0 = vectorPermute(carryVec,*(vec16 *)((uint)vecPtr1 & 0xfffffff0),alignPermute);
    carryVec = *(vec16 *)((uint)srcCursor & 0xfffffff0);
    outVec1 = vectorPermute(*(vec16 *)((uint)vecPtr1 & 0xfffffff0),
                            *(vec16 *)((uint)vecPtr2 & 0xfffffff0),alignPermute);
    outVec2 = vectorPermute(*(vec16 *)((uint)vecPtr2 & 0xfffffff0),
                            *(vec16 *)((uint)vecPtr3 & 0xfffffff0),alignPermute);
    tempVec = vectorPermute(*(vec16 *)((uint)vecPtr3 & 0xfffffff0),carryVec,alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = outVec0;
    *(vec16 *)((uint)(dstCursor + 4) & 0xfffffff0) = outVec1;
    *(vec16 *)((uint)(dstCursor + 8) & 0xfffffff0) = outVec2;
    *(vec16 *)((uint)(dstCursor + 0xc) & 0xfffffff0) = tempVec;
  }
  if (dstCursor + 8 < dstEnd) {
    tempVec = *(vec16 *)((uint)(srcCursor + 4) & 0xfffffff0);
    srcCursor = srcCursor + 8;
    carryVec = vectorPermute(carryVec,tempVec,alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = carryVec;
    carryVec = *(vec16 *)((uint)srcCursor & 0xfffffff0);
    tempVec = vectorPermute(tempVec,carryVec,alignPermute);
    *(vec16 *)((uint)(dstCursor + 4) & 0xfffffff0) = tempVec;
    dstCursor = dstCursor + 8;
  }
  if (dstCursor + 4 < dstEnd) {
    vecPtr1 = srcCursor + 4;
    srcCursor = srcCursor + 4;
    carryVec = vectorPermute(carryVec,*(vec16 *)((uint)vecPtr1 & 0xfffffff0),alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = carryVec;
    dstCursor = dstCursor + 4;
  }
  else if (dstEnd <= dstCursor) goto LAB_0001ecac;
  do {
    swapWord = *srcCursor;
    srcCursor = srcCursor + 1;
    *dstCursor = swapWord << 0x10 | swapWord >> 0x10;
    dstCursor = dstCursor + 1;
  } while (dstCursor < dstEnd);
LAB_0001ecac:
  if ((count & 1) != 0) {
    *dstCursor = (uint)*(ushort *)srcCursor;
  }
  return;
}

/* copyIndices16Swapped_dcbz @ 0x1eaf0 (468 bytes) */
int copyIndices16Swapped_dcbz(dst, src, count)
  uint dst;
  uint src;
  uint count;
{
  vec16 tempVec;
  uint swapWord;
  uint dstMisalign;
  uint *vecPtr1;
  uint *vecPtr2;
  uint *vecPtr3;
  uint *dstCursor;
  uint dcbzAddress;
  uint *srcCursor;
  uint *dstEnd;
  vec16 carryVec;
  vec16 outVec2;
  vec16 alignPermute;
  vec16 outVec1;
  vec16 outVec0;
  
  dstEnd = (uint *)(dst + (count & 0x7ffffffe) * 2);
  for (dcbzAddress = dst + 0x7f & 0xffffff80; dcbzAddress < ((uint)dstEnd & 0xffffff80);
      dcbzAddress = dcbzAddress + 0x80) {
    dataCacheBlockClearToZero(dcbzAddress);
  }
  dstMisalign = dst & 0xf;
  dstCursor = (uint *)(dst - dstMisalign);
  srcCursor = (uint *)(src - dstMisalign);
  alignPermute = *(vec16 *)
             (*(int *)PTR_DAT_001e88cc + ((int)srcCursor * 0x10 & 0xf0U) & 0xfffffff0);
  carryVec = *(vec16 *)(src & 0xfffffff0);
  if (dstMisalign != 0) {
    carryVec = *(vec16 *)((uint)(srcCursor + 4) & 0xfffffff0);
    srcCursor = srcCursor + 4;
    tempVec = vectorPermute(*(vec16 *)(src & 0xfffffff0),carryVec,alignPermute);
    tempVec = vectorConditionalSelect
                       (*(vec16 *)((uint)dstCursor & 0xfffffff0),tempVec,
                        *(vec16 *)
                         (*(int *)PTR_DAT_001e88cc + dstMisalign * 0x10 + 0x100 & 0xfffffff0));
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = tempVec;
    dstCursor = dstCursor + 4;
  }
  for (; dstCursor < dstEnd + -0x10; dstCursor = dstCursor + 0x10) {
    vecPtr1 = srcCursor + 4;
    vecPtr2 = srcCursor + 8;
    vecPtr3 = srcCursor + 0xc;
    srcCursor = srcCursor + 0x10;
    outVec0 = vectorPermute(carryVec,*(vec16 *)((uint)vecPtr1 & 0xfffffff0),alignPermute);
    carryVec = *(vec16 *)((uint)srcCursor & 0xfffffff0);
    outVec1 = vectorPermute(*(vec16 *)((uint)vecPtr1 & 0xfffffff0),
                            *(vec16 *)((uint)vecPtr2 & 0xfffffff0),alignPermute);
    outVec2 = vectorPermute(*(vec16 *)((uint)vecPtr2 & 0xfffffff0),
                            *(vec16 *)((uint)vecPtr3 & 0xfffffff0),alignPermute);
    tempVec = vectorPermute(*(vec16 *)((uint)vecPtr3 & 0xfffffff0),carryVec,alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = outVec0;
    *(vec16 *)((uint)(dstCursor + 4) & 0xfffffff0) = outVec1;
    *(vec16 *)((uint)(dstCursor + 8) & 0xfffffff0) = outVec2;
    *(vec16 *)((uint)(dstCursor + 0xc) & 0xfffffff0) = tempVec;
  }
  if (dstCursor + 8 < dstEnd) {
    tempVec = *(vec16 *)((uint)(srcCursor + 4) & 0xfffffff0);
    srcCursor = srcCursor + 8;
    carryVec = vectorPermute(carryVec,tempVec,alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = carryVec;
    carryVec = *(vec16 *)((uint)srcCursor & 0xfffffff0);
    tempVec = vectorPermute(tempVec,carryVec,alignPermute);
    *(vec16 *)((uint)(dstCursor + 4) & 0xfffffff0) = tempVec;
    dstCursor = dstCursor + 8;
  }
  if (dstCursor + 4 < dstEnd) {
    vecPtr1 = srcCursor + 4;
    srcCursor = srcCursor + 4;
    carryVec = vectorPermute(carryVec,*(vec16 *)((uint)vecPtr1 & 0xfffffff0),alignPermute);
    *(vec16 *)((uint)dstCursor & 0xfffffff0) = carryVec;
    dstCursor = dstCursor + 4;
  }
  else if (dstEnd <= dstCursor) goto LAB_0001ecac;
  do {
    swapWord = *srcCursor;
    srcCursor = srcCursor + 1;
    *dstCursor = swapWord << 0x10 | swapWord >> 0x10;
    dstCursor = dstCursor + 1;
  } while (dstCursor < dstEnd);
LAB_0001ecac:
  if ((count & 1) != 0) {
    *dstCursor = (uint)*(ushort *)srcCursor;
  }
  return;
}

/* gld_drawVertexArray @ 0x1ecd0 (696 bytes) */
int gld_drawVertexArray(ctx, param_2, primitiveMode, first, count, indexType, drawFlags, currentAttribs)
  int ctx;
  int param_2;
  int primitiveMode;
  int first;
  int count;
  undefined *indexType;
  uint drawFlags;
  int currentAttribs;
{
  bool notIndexed;
  bool indexIsShort;
  int *ringHeaderZero;
  int chunkFirst;
  int packetWords;
  int elementsInBuffer;
  int chunkIndex;
  uint *headerWord;
  byte *retireCounter;
  int currentProgram;
  int currentVertexArray;
  byte *pbVar1;
  bool bVar2;
  bool hasElements;
  bool bVar4;
  byte bVar5;
  uint usesBuffers;
  uint arrayPairs;
  uint enabledArrays;
  bool keepStateCache;
  bool needStatePacket;
  undefined4 *puVar10;
  undefined *indexWords;
  int iVar12;
  uint uVar13;
  uint *puVar15;
  uint *packetPtr;
  undefined4 uVar17;
  void *pvVar18;
  undefined *puVar19;
  int elementBinding;
  uint packetStateWords;
  int iVar22;
  uint uVar23;
  uint uVar24;
  byte *indexBytes;
  int arrayStateB;
  code *pcVar27;
  int *piVar28;
  uint uVar29;
  undefined4 *drawPacket;
  int arrayState;
  undefined *chunkCount;
  uint *puVar33;
  int ring;
  char reservation;
  uint uVar35;
  int iVar36;
  double staleFpr1;
  double staleFpr2;
  double staleFpr3;
  double staleFpr4;
  double staleFpr5;
  double staleFpr6;
  double staleFpr7;
  double staleFpr8;
  uint uStack00000030;
  double staleStackArg_ffffff68;
  int iStack_60;
  
  ring = ctx + GLD_commandStream;
  piVar28 = *(int **)(ctx + GLD_currentVertexArray);
  if ((piVar28 == (int *)0x0) || (*(char *)(ctx + 0x2724) == '\0')) goto LAB_0001f7f0;
  arrayState = *piVar28;
  enabledArrays = *(uint *)(((unsigned char *)0x000027c8) + ctx) & 0x1f;
  usesBuffers = (uint)(*(int *)(arrayState + 0x308) != 0 || *(int *)(arrayState + 0x30c) != 0);
  if ((*(uint *)(arrayState + 0x304) & 0x400000) == 0) {
    if (((*(int *)(((unsigned char *)0x00003170) + *(int *)(ctx + GLD_engineState)) == 0x1b011b01) &&
        (*(char *)(currentAttribs + 0x7c) == '\0')) && (primitiveMode - 4U < 6)) {
      return 1;
    }
  }
  else if (((*(short *)(((unsigned char *)0x00003170) + *(int *)(ctx + GLD_engineState)) == 0x1b02) ||
           (*(short *)(((unsigned char *)0x00003172) + *(int *)(ctx + GLD_engineState)) == 0x1b02)) && (primitiveMode - 4U < 6))
  goto LAB_0001f7f0;
  arrayStateB = *piVar28;
  elementBinding = *(int *)(piVar28[1] + 0x80);
  puVar19 = indexType;
  if (count < 0x20) {
LAB_0001ef10:
    elementsInBuffer = 0;
LAB_0001ef14:
    if (indexType == ((unsigned char *)0x000014ff)) {
LAB_0001ef40:
      chunkCount = (undefined *)0xffff;
    }
    else {
      chunkCount = (undefined *)0x7ffa;
      if (indexType == ((unsigned char *)0x00001405)) goto LAB_0001ef30;
    }
  }
  else {
    puVar19 = (undefined *)(*(uint *)(arrayStateB + 0x308) | *(uint *)(arrayStateB + 0x30c));
    if (((puVar19 != (undefined *)0x0) && (elementBinding != 0)) &&
       ((*(int **)(elementBinding + 8) != (int *)0x0 && (**(int **)(elementBinding + 8) != 0)))) {
      if (indexType == ((unsigned char *)0x00001403)) {
        if ((*(int *)(elementBinding + 0x10) != 7) || (elementsInBuffer = 1, *(char *)(elementBinding + 0xc) != '\0'))
        goto LAB_0001ee2c;
      }
      else if (indexType == ((unsigned char *)0x00001405)) {
        elementsInBuffer = 1;
        *(undefined1 *)(elementBinding + 0xc) = 1;
      }
      else {
LAB_0001ee2c:
        elementsInBuffer = 0;
      }
      if ((drawFlags & 1) != 0) goto LAB_0001ef10;
      if (elementsInBuffer == 0) goto LAB_0001ef14;
      goto LAB_0001ef40;
    }
    puVar19 = (undefined *)(*(uint *)(arrayStateB + 0x308) | *(uint *)(arrayStateB + 0x30c));
    if ((((puVar19 != (undefined *)0x0) || ((*(uint *)(arrayStateB + 0x304) & 0x800000) == 0)) ||
        (param_2 != 2)) || (indexType != ((unsigned char *)0x00001405))) goto LAB_0001ef10;
    if ((drawFlags & 1) == 0) {
      if ((*(uint *)(arrayStateB + 0x314) <= *(uint *)(arrayStateB + 0xa8)) &&
         (*(uint *)(arrayStateB + 0xa8) < *(uint *)(arrayStateB + 0x314) + *(int *)(arrayStateB + 0x318))) {
        elementsInBuffer = 1;
        chunkCount = (undefined *)0xffff;
        goto LAB_0001ef50;
      }
    }
    elementsInBuffer = 0;
LAB_0001ef30:
    chunkCount = ((unsigned char *)0x00003ffdU);
  }
LAB_0001ef50:
  uStack00000030 = drawFlags;
  /* hidden-argument defect (found auditing #70/FUN_0002cc30): this is the one real caller (of
   * 25) that supplies a genuine 7th argument - verified via real stock disassembly
   * (`lwz r9,0xa8(r10)`, matching this stack store just above). */
  puVar19 = (undefined *)
            ((uint (*)())FUN_0002cc30)(ctx,1,primitiveMode,count,count,puVar19,drawFlags,staleFpr1,staleFpr2,staleFpr3,staleFpr4,staleFpr5,
                         staleFpr6,staleFpr7,staleFpr8,staleStackArg_ffffff68);
  bVar2 = 0 < (int)puVar19;
  hasElements = puVar19 != (undefined *)0x0;
  needStatePacket = hasElements;
  switch(primitiveMode) {
  case 1:
  case 8:
    chunkCount = (undefined *)((uint)chunkCount & 0xfffffffe);
  case 0:
LAB_0001f000:
    needStatePacket = hasElements;
    break;
  default:
    needStatePacket = false;
    if (puVar19 <= chunkCount) goto LAB_0001f000;
    break;
  case 4:
    chunkCount = (undefined *)(((uint)chunkCount / 3) * 3);
    break;
  case 7:
    chunkCount = (undefined *)((uint)chunkCount & 0xfffffffc);
  }
  if (puVar19 < chunkCount) {
    chunkCount = puVar19;
  }
  if (needStatePacket) {
    notIndexed = indexType == ((unsigned char *)0x000014ff);
    if (((notIndexed) || (*(int *)(ctx + 0x2720) != 0)) || (elementsInBuffer != 0)) {
      needStatePacket = true;
      keepStateCache = true;
    }
    else if (*(int *)(ctx + 0x26d4) == ctx + 0x2768) {
      needStatePacket = false;
      keepStateCache = false;
    }
    else {
      needStatePacket = true;
      keepStateCache = false;
    }
    packetStateWords = -(uint)*(byte *)(ctx + GLD_needsWaitIdle) >> 0x1e & 2;
    if (*(int *)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != ctx + 0x2630) {
      packetStateWords = packetStateWords + (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    if (needStatePacket) {
      piVar28 = *(int **)(ctx + GLD_currentVertexArray);
      packetWords = packetStateWords + 0x14;
      if (*(int *)(*piVar28 + 0x308) != 0 || *(int *)(*piVar28 + 0x30c) != 0) {
        packetWords = enabledArrays + packetStateWords + 0x13;
      }
      if (elementsInBuffer != 0) {
        packetWords = packetWords + 1;
      }
      packetStateWords = packetWords + (enabledArrays + 1 >> 1) * 3 + 3;
      if (*(int *)(ctx + 0x2720) != 0) {
        packetStateWords = packetStateWords + *(int *)(ctx + 0x2720) + 1;
      }
    }
    else {
      piVar28 = *(int **)(ctx + GLD_currentVertexArray);
    }
    iStack_60 = 0;
    puVar10 = *(undefined4 **)(piVar28[1] + 0x80);
    if (usesBuffers == 0) {
      iStack_60 = *(int *)(arrayState + 0x314);
    }
    arrayPairs = enabledArrays + 1 >> 1;
    ringHeaderZero = (int *)0x0;
    drawPacket = (undefined4 *)0x0;
    chunkIndex = 0;
    while (bVar2) {
      chunkFirst = first + chunkIndex * (int)chunkCount;
      if (puVar19 < chunkCount) {
        chunkCount = puVar19;
      }
      indexIsShort = indexType == ((unsigned char *)0x00001403);
      if (indexIsShort) {
code_r0x0001f1c0:
        if (elementsInBuffer == 0) {
          indexWords = (undefined *)(((uint)(chunkCount + 1) >> 1) + 4);
        }
        else {
code_r0x0001f1f0:
          indexWords = (undefined *)0x8;
        }
      }
      else if (((unsigned char *)0x00001403) < indexType) {
        if (indexType == ((unsigned char *)0x00001405)) {
          indexWords = chunkCount + 4;
          if (elementsInBuffer != 0) goto code_r0x0001f1f0;
        }
        else {
          if (!notIndexed) goto code_r0x0001f1ac;
          indexWords = (undefined *)0x4;
        }
      }
      else {
        if (indexType == ((unsigned char *)0x00001401)) goto code_r0x0001f1c0;
code_r0x0001f1ac:
        indexWords = (undefined *)0x0;
      }
      puVar15 = (uint *)(**(code **)(ctx + GLD_streamAllocate))(ring,indexWords + packetStateWords + 2);
      *(uint **)(ctx + GLD_streamCurrent) = puVar15;
      packetPtr = puVar15;
      if (*(char *)(ctx + GLD_needsWaitIdle) != '\0') {
        packetPtr = puVar15 + 2;
        *puVar15 = 0x5c8;
        puVar15[1] = 0x10000000;
        *(undefined1 *)(ctx + GLD_needsWaitIdle) = 0;
      }
      if (*(int *)(ctx + GLD_vap_prog_stream_cntl_0_ptr) != ctx + 0x2630) {
        *(int *)(ctx + GLD_vap_prog_stream_cntl_0_ptr) = ctx + 0x2630;
        *(int *)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr) = ctx + 0x2650;
        packetPtr = (uint *)FUN_0002c0c0(ctx,packetPtr);
      }
      if (needStatePacket) {
        uVar17 = *(undefined4 *)(((unsigned char *)0x000027c8) + ctx);
        drawPacket = (undefined4 *)((uint)(packetPtr + 0xb) & 0xffffffe0);
        *(int *)(ctx + 0x26d4) = ctx + 0x2768;
        *(int *)(ctx + 0x26d8) = ctx + 0x2788;
        *(undefined4 *)(ctx + 0x26d0) = uVar17;
        *packetPtr = (((int)drawPacket - (int)packetPtr) + -8) * 0x4000 | 0xc0001000;
        drawPacket[-1] = (int)drawPacket - (int)packetPtr;
        headerWord = *(uint **)(ctx + GLD_lastHeader);
        *headerWord = *headerWord | (int)drawPacket - (int)headerWord >> 2;
        *(undefined4 **)(ctx + GLD_lastHeader) = drawPacket;
        *drawPacket = 0x39000000;
        drawPacket[1] = enabledArrays;
        drawPacket[2] = usesBuffers;
        drawPacket[3] = elementsInBuffer;
        if (indexIsShort) {
          uVar17 = 2;
        }
        else {
          uVar17 = 4;
        }
        drawPacket[4] = uVar17;
        packetPtr = drawPacket + 8;
        currentVertexArray = **(int **)(ctx + GLD_currentVertexArray);
        if (*(int *)(currentVertexArray + 0x308) == 0 && *(int *)(currentVertexArray + 0x30c) == 0) {
          packetPtr = drawPacket + 9;
          drawPacket[8] = *(undefined4 *)(*(int **)(ctx + GLD_currentVertexArray))[0x8a];
          piVar28 = (int *)(*(int *)(*(int *)(ctx + GLD_currentVertexArray) + 0x228) + 0x10);
          if (reservation != '\0') {
            iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
            *piVar28 = iVar12;
          }
          if (elementsInBuffer != 0) {
            packetPtr = drawPacket + 10;
            drawPacket[9] = **(undefined4 **)(*(int *)(ctx + GLD_currentVertexArray) + 0x228);
            piVar28 = (int *)(*(int *)(*(int *)(ctx + GLD_currentVertexArray) + 0x228) + 0x10);
            if (reservation != '\0') {
              iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
              *piVar28 = iVar12;
            }
          }
        }
        else {
          needStatePacket = false;
          if (enabledArrays != 0) {
            pcVar27 = 0x00002728 + ctx;
            uVar35 = enabledArrays;
            if (enabledArrays == 0) {
              uVar35 = 1;
            }
            do {
              puVar15 = *(uint **)pcVar27;
              pcVar27 = pcVar27 + 4;
              puVar33 = puVar15 + 4;
              *packetPtr = *puVar15;
              packetPtr = packetPtr + 1;
              do {
                if (reservation != '\0') {
                  uVar24 = storeWordConditionalIndexed(*puVar33 + 0x10000,0,puVar33);
                  *puVar33 = uVar24;
                  needStatePacket = true;
                }
              } while (!needStatePacket);
              uVar35 = uVar35 - 1;
            } while (uVar35 != 0);
          }
          if (elementsInBuffer != 0) {
            *packetPtr = *(uint *)**(undefined4 **)
                                  (*(int *)(*(int *)(*(int *)(ctx + GLD_currentVertexArray) + 4) + 0x80) + 8);
            packetPtr = packetPtr + 1;
            piVar28 = (int *)(**(int **)(*(int *)(*(int *)(*(int *)(ctx + GLD_currentVertexArray) + 4) + 0x80) +
                                        8) + 0x10);
            do {
              if (reservation != '\0') {
                iVar12 = storeWordConditionalIndexed(*piVar28 + 0x10000,0,piVar28);
                *piVar28 = iVar12;
                needStatePacket = true;
              }
            } while (!needStatePacket);
          }
        }
        drawPacket[5] = ((int)packetPtr - (int)drawPacket >> 2) + 2;
        if (notIndexed) {
          puVar15 = packetPtr + 1;
          *packetPtr = (arrayPairs * 3 + -1) * 0x10000 | 0x831;
          if (arrayPairs != 0) {
            piVar28 = (int *)(ctx + 0x278c);
            iVar12 = ring;
            uVar35 = arrayPairs;
            do {
              *puVar15 = *(uint *)(iVar12 + 0x2528);
              if (piVar28[-1] == -1) {
                puVar15[1] = 0xffffffff;
              }
              else {
                puVar15[1] = piVar28[-1] + first * (*(uint *)(iVar12 + 0x2528) >> 8 & 0x7f) * 4;
              }
              if (*piVar28 == -1) {
                puVar15[2] = 0xffffffff;
              }
              else {
                puVar15[2] = *piVar28 + first * (*(byte *)(iVar12 + 0x2528) & 0x7f) * 4;
              }
              puVar15 = puVar15 + 3;
              iVar12 = iVar12 + 4;
              piVar28 = piVar28 + 2;
              uVar35 = uVar35 - 1;
            } while (uVar35 != 0);
          }
          packetPtr = puVar15 + 2;
          *puVar15 = 0x830;
          puVar15[1] = *(uint *)(((unsigned char *)0x000027c8) + ctx);
          *(undefined4 *)(ctx + 0x26d4) = 0;
        }
        else {
          packetPtr = (uint *)FUN_0002c180(ctx,packetPtr);
        }
        ringHeaderZero = drawPacket + 7;
        drawPacket[6] = (int)packetPtr + (4 - (int)drawPacket) >> 2;
        uVar35 = *(uint *)(ctx + 0x271c);
        bVar4 = uVar35 == 0;
        needStatePacket = keepStateCache;
        if (!bVar4) {
          puVar15 = packetPtr + 1;
          *packetPtr = (*(int *)(ctx + 0x2720) + -1) * 0x10000 | 0xc0001000;
          if (*(int *)(*(int *)(ctx + GLD_capsBlock) + 0x11c) == 0) {
            currentProgram = *(int *)(ctx + GLD_currentProgram);
            if (currentProgram == 0) {
              if ((uVar35 & 2) != 0) {
                packetPtr[1] = *(uint *)(currentAttribs + 0x40);
                packetPtr[2] = *(uint *)(currentAttribs + 0x44);
                puVar15 = packetPtr + 5;
                uVar24 = *(uint *)(currentAttribs + 0x48);
                packetPtr[4] = 0x3f800000;
                packetPtr[3] = uVar24;
              }
              if ((uVar35 & 4) != 0) {
                *puVar15 = *(uint *)(currentAttribs + 0x30);
                puVar15[1] = *(uint *)(currentAttribs + 0x34);
                puVar15[2] = *(uint *)(currentAttribs + 0x38);
                puVar15[3] = *(uint *)(currentAttribs + 0x3c);
                puVar15 = puVar15 + 4;
              }
              if ((uVar35 & 8) != 0) {
                *puVar15 = *(uint *)(currentAttribs + 0x50);
                puVar15[1] = *(uint *)(currentAttribs + 0x54);
                uVar24 = *(uint *)(currentAttribs + 0x58);
                puVar15[3] = 0x3f800000;
                puVar15[2] = uVar24;
                puVar15 = puVar15 + 4;
              }
              uVar24 = 0;
              iVar36 = 8;
              iVar12 = currentAttribs;
              do {
                if ((uVar35 & 0x400 << (uVar24 & 0x3f)) != 0) {
                  *puVar15 = *(uint *)(iVar12 + 0x80);
                  puVar15[1] = *(uint *)(iVar12 + 0x84);
                  puVar15[2] = *(uint *)(iVar12 + 0x88);
                  puVar15[3] = *(uint *)(iVar12 + 0x8c);
                  puVar15 = puVar15 + 4;
                }
                uVar24 = uVar24 + 1;
                iVar12 = iVar12 + 0x10;
                iVar36 = iVar36 + -1;
              } while (iVar36 != 0);
              if ((uVar35 & 0x40000) != 0) {
                uVar24 = *(uint *)(currentAttribs + 0x5c);
                puVar15[3] = 0x3f800000;
                puVar15[1] = 0x3f800000;
                puVar15[2] = 0x3f800000;
                *puVar15 = uVar24;
                puVar15 = puVar15 + 4;
              }
              packetPtr = puVar15;
              if ((uVar35 & 0x80000) != 0) {
                *puVar15 = *(uint *)(currentAttribs + 0x60);
                puVar15[1] = *(uint *)(currentAttribs + 100);
                puVar15[2] = *(uint *)(currentAttribs + 0x68);
                puVar15[3] = *(uint *)(currentAttribs + 0x6c);
                packetPtr = puVar15 + 4;
              }
              goto code_r0x0001f7c0;
            }
          }
          else {
            currentProgram = *(int *)(ctx + GLD_currentProgram);
          }
          iVar22 = *(int *)(*(int *)(ctx + GLD_capsBlock) + 0x11c);
          iVar36 = 0x16;
          packetPtr = puVar15;
          if ((currentProgram == 0) || (iVar36 = *(int *)(*(int *)(ctx + 0x29e8) + 0x28), iVar36 != 0))
          {
            uVar24 = 0;
            puVar15 = (uint *)(ctx + 0x27dc);
            do {
              uVar13 = 1 << (uVar24 & 0x3f);
              if ((uVar35 & uVar13) != 0) {
                uVar23 = uVar24;
                if (iVar22 != 0) {
                  uVar23 = *puVar15;
                }
                uVar35 = uVar35 & ~uVar13;
                iVar12 = currentAttribs + uVar23 * 0x10;
                bVar4 = uVar35 == 0;
                *packetPtr = *(uint *)(currentAttribs + uVar23 * 0x10);
                packetPtr[1] = *(uint *)(iVar12 + 4);
                packetPtr[2] = *(uint *)(iVar12 + 8);
                packetPtr[3] = *(uint *)(iVar12 + 0xc);
                packetPtr = packetPtr + 4;
              }
              if (bVar4) break;
              uVar24 = uVar24 + 1;
              puVar15 = puVar15 + 1;
              iVar36 = iVar36 + -1;
            } while (iVar36 != 0);
          }
        }
      }
code_r0x0001f7c0:
      dataCacheBlockTouch(0x1d91c8);
      if (indexIsShort) {
        puVar15 = (uint *)(chunkFirst * 2 + uStack00000030);
        dataCacheBlockTouch(puVar15);
        dataCacheBlockTouch((int)puVar15 + (uint)*(byte *)(ctx + GLD_cacheLineSize));
        uVar35 = (int)chunkCount << 0x10 | *(uint *)(primitiveMode * 4 + 0x1d91c8) & 0xf | 0x10;
        if (elementsInBuffer == 0) {
          *packetPtr = 0x82c;
          puVar33 = packetPtr + 4;
          uVar24 = *(uint *)(GLD_vap_vte_cntl + ctx);
          packetPtr[2] = ((uint)(chunkCount + 1) >> 1) << 0x10 | 0xc0003600;
          packetPtr[3] = uVar35;
          packetPtr[1] = uVar24;
          if (chunkCount < (undefined *)0x201) {
            uVar35 = (uint)chunkCount >> 3;
            packetPtr = puVar15;
            if (uVar35 != 0) {
              if (uVar35 == 0) {
                uVar35 = 1;
              }
              do {
                uVar24 = *packetPtr;
                uVar13 = packetPtr[1];
                uVar23 = packetPtr[2];
                uVar29 = packetPtr[3];
                packetPtr = packetPtr + 4;
                *puVar33 = uVar24 << 0x10 | uVar24 >> 0x10;
                puVar33[1] = uVar13 << 0x10 | uVar13 >> 0x10;
                puVar33[2] = uVar23 << 0x10 | uVar23 >> 0x10;
                puVar33[3] = uVar29 << 0x10 | uVar29 >> 0x10;
                puVar33 = puVar33 + 4;
                uVar35 = uVar35 - 1;
              } while (uVar35 != 0);
            }
            uVar35 = (uint)chunkCount >> 1 & 3;
            if (uVar35 != 0) {
              if (uVar35 == 0) {
                uVar35 = 1;
              }
              do {
                uVar24 = *packetPtr;
                packetPtr = packetPtr + 1;
                *puVar33 = uVar24 << 0x10 | uVar24 >> 0x10;
                puVar33 = puVar33 + 1;
                uVar35 = uVar35 - 1;
              } while (uVar35 != 0);
            }
            if (((uint)chunkCount & 1) != 0) {
              *puVar33 = (uint)*(ushort *)((int)puVar15 + (int)chunkCount * 2 + -2);
              puVar33 = puVar33 + 1;
            }
          }
          else {
            if (*(char *)(ctx + GLD_cacheLineSize) == -0x80) {
              ((int (*)())copyIndices16Swapped_dcbz_entry)(puVar33,puVar15,chunkCount);
            }
            else {
              ((int (*)())copyIndices16Swapped_prefetch_entry)(puVar33,puVar15,chunkCount);
            }
            puVar33 = puVar33 + ((uint)(chunkCount + 1) >> 1);
          }
        }
        else {
          *packetPtr = 0x82c;
          uVar24 = *(uint *)(GLD_vap_vte_cntl + ctx);
          packetPtr[2] = 0xc0003600;
          packetPtr[3] = uVar35;
          packetPtr[1] = uVar24;
          *ringHeaderZero = (int)packetPtr + (0x10 - (int)drawPacket) >> 2;
          ringHeaderZero = ringHeaderZero + 1;
          packetPtr[4] = 0xc0023300;
          packetPtr[5] = 0x80000810;
          if (puVar10 == (undefined4 *)0x0) {
            packetPtr[6] = (int)puVar15 - iStack_60;
          }
          else {
            packetPtr[6] = (int)puVar15 - *(int *)*puVar10;
          }
          puVar33 = packetPtr + 8;
          packetPtr[7] = (uint)(chunkCount + 1) >> 1;
        }
      }
      else if (((unsigned char *)0x00001403) < indexType) {
        if (indexType == ((unsigned char *)0x00001405)) {
          pvVar18 = (void *)(chunkFirst * 4 + uStack00000030);
          uVar35 = (int)chunkCount << 0x10 | *(uint *)(primitiveMode * 4 + 0x1d91c8) & 0xf | 0x810;
          if (elementsInBuffer == 0) {
            *packetPtr = 0x82c;
            puVar33 = packetPtr + 4 + (int)chunkCount;
            uVar24 = *(uint *)(GLD_vap_vte_cntl + ctx);
            packetPtr[2] = (int)chunkCount << 0x10 | 0xc0003600;
            packetPtr[3] = uVar35;
            packetPtr[1] = uVar24;
            _memcpy(packetPtr + 4,pvVar18,(int)chunkCount * 4);
          }
          else {
            *packetPtr = 0x82c;
            uVar24 = *(uint *)(GLD_vap_vte_cntl + ctx);
            packetPtr[2] = 0xc0003600;
            packetPtr[3] = uVar35;
            packetPtr[1] = uVar24;
            *ringHeaderZero = (int)packetPtr + (0x10 - (int)drawPacket) >> 2;
            packetPtr[4] = 0xc0023300;
            packetPtr[5] = 0x80000810;
            ringHeaderZero = ringHeaderZero + 1;
            if (puVar10 == (undefined4 *)0x0) {
              packetPtr[6] = (int)pvVar18 - iStack_60;
            }
            else {
              packetPtr[6] = (int)pvVar18 - *(int *)*puVar10;
            }
            puVar33 = packetPtr + 8;
            packetPtr[7] = (uint)chunkCount;
          }
        }
        else {
          if (!notIndexed) goto LAB_0001f7f0;
          puVar33 = packetPtr + 4;
          uVar24 = *(uint *)(primitiveMode * 4 + 0x1d91c8);
          *packetPtr = 0x82c;
          first = first + (int)chunkCount;
          uVar35 = *(uint *)(GLD_vap_vte_cntl + ctx);
          packetPtr[2] = 0xc0003400;
          packetPtr[1] = uVar35;
          packetPtr[3] = (int)chunkCount << 0x10 | uVar24 & 0xf | 0x820;
        }
      }
      else {
        if (indexType != ((unsigned char *)0x00001401)) goto LAB_0001f7f0;
        uVar24 = *(uint *)(primitiveMode * 4 + 0x1d91c8);
        *packetPtr = 0x82c;
        puVar33 = packetPtr + 4;
        uVar35 = *(uint *)(GLD_vap_vte_cntl + ctx);
        packetPtr[2] = (int)(chunkCount + 1) * 0x8000 & 0xffff0000U | 0xc0003600;
        packetPtr[1] = uVar35;
        packetPtr[3] = (int)chunkCount << 0x10 | uVar24 & 0xf | 0x10;
        if (((uint)chunkCount & 0xfffffffe) != 0) {
          uVar35 = 0;
          indexBytes = (byte *)(chunkFirst + uStack00000030);
          do {
            pbVar1 = indexBytes + 1;
            uVar35 = uVar35 + 2;
            bVar5 = *indexBytes;
            indexBytes = indexBytes + 2;
            *puVar33 = (uint)*pbVar1 << 0x10 | (uint)bVar5;
            puVar33 = puVar33 + 1;
          } while (uVar35 < ((uint)chunkCount & 0xfffffffe));
        }
        if (((uint)chunkCount & 1) != 0) {
          *puVar33 = (uint)((byte *)(chunkFirst + uStack00000030))[(int)(chunkCount + -1)];
          puVar33 = puVar33 + 1;
        }
      }
      puVar19 = puVar19 + -(int)chunkCount;
      *puVar33 = (uint)((unsigned char *)0x00001393U);
      puVar33[1] = 0;
      puVar33 = puVar33 + 2;
      chunkIndex = chunkIndex + 1;
      *(uint **)(ctx + GLD_streamCurrent) = puVar33;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,puVar33);
      bVar2 = 0 < (int)puVar19;
      if (*(uint **)(ctx + GLD_streamSoftLimit) <= puVar33) {
        retireCounter = *(byte **)(ctx + GLD_retireCounter);
        if (((uint)retireCounter[3] << 0x18 | (uint)retireCounter[2] << 0x10 | (uint)retireCounter[1] << 8 |
            (uint)*retireCounter) == *(uint *)(retireCounter + 0x20)) {
          ((int (*)())gld_submitRing)(ctx,0x1000000);
          bVar2 = 0 < (int)puVar19;
        }
        else {
          bVar2 = 0 < (int)puVar19;
          *(uint **)(ctx + GLD_streamSoftLimit) = *(uint **)(ctx + GLD_streamSoftLimit) + 0x1000;
        }
      }
    }
    uVar17 = 1;
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    ((unsigned char *)0x000027d0)[ctx + 5] = 1;
  }
  else {
LAB_0001f7f0:
    uVar17 = 0;
  }
  return uVar17;
}

/* FUN_0001fd00 @ 0x1fd00 (1208 bytes) */
int FUN_0001fd00(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  bool bVar16;
  uint loopIndex;
  int *piVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint loopIndex2;
  uint uVar24;
  int iVar25;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar8 = *(int *)(param_1 + 4);
  piVar13 = *(int **)(iVar8 + 0x1d4);
  if (piVar13 == (int *)0x0) {
    return;
  }
  iVar6 = *piVar13;
  iVar18 = piVar13[1];
  uVar24 = *(uint *)(param_1 + 0x243c);
  bVar1 = *(uint *)(iVar6 + 0x308) == 0;
  bVar2 = *(uint *)(iVar6 + 0x30c) == 0;
  if (*(int *)(iVar8 + 0x1cc) == 0) {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((uVar7 & 0x10000) == 0) goto LAB_0001fdc0;
  }
  else {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((*(uint *)(iVar6 + 0x300) & 1) == 0 && (uVar7 & 0x10000) == 0) {
LAB_0001fdc0:
      bVar16 = true;
      goto LAB_0001fd8c;
    }
  }
  bVar16 = false;
LAB_0001fd8c:
  if (((((*(char *)(iVar8 + 0x20) == '\0') || (0x10 < uVar24)) || (uVar24 < 2)) ||
      ((!bVar1 || !bVar2 &&
       ((*(uint *)(iVar6 + 0x300) & ~*(uint *)(iVar6 + 0x308)) != 0 ||
        (uVar7 & ~*(uint *)(iVar6 + 0x30c)) != 0)))) || (bVar16)) {
switchD_0001ffbc_default:
    *(undefined1 *)(param_1 + 0x24e4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x24dc) = 0;
    *(undefined4 *)(param_1 + 0x24e0) = 0;
    *(undefined1 *)(param_1 + 0x24e4) = 1;
    if (*(int **)(iVar8 + 0x1cc) == (int *)0x0) {
      iVar21 = 0;
      piVar17 = (int *)0x0;
      iVar20 = 0;
      iVar8 = 0;
    }
    else {
      iVar20 = *(int *)(**(int **)(iVar8 + 0x1cc) + 4);
      iVar21 = *(int *)(iVar8 + 0x29e8) + 0x14;
      piVar17 = *(int **)(*(int *)(iVar8 + 0x29e8) + 0x34);
      iVar8 = *(int *)(iVar20 + 0x24);
    }
    puVar19 = (uint *)0x0;
    loopIndex = 0;
    loopIndex2 = 0;
    uVar7 = 0;
    iVar22 = 0;
    *(uint *)(param_1 + 0x2588) = uVar24 & 0x1f | 0x20;
    iVar25 = 0x16;
    do {
      bVar16 = *(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0;
      if (bVar16) {
        if ((1 << (loopIndex2 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_0001ff00;
      }
      else if ((*(int *)(iVar22 + *(int *)(iVar21 + 0x20)) != 0x80) ||
              (*(uint *)(iVar21 + 0x1c) <= loopIndex2)) {
LAB_0001ff00:
        if (iVar20 != 0) {
          if (loopIndex2 < *(uint *)(iVar21 + 0x1c)) {
            puVar19 = (uint *)(iVar20 + (iVar8 + *(int *)((int)piVar17 + iVar22)) * 8);
          }
          else {
            puVar19 = (uint *)(iVar20 + (iVar8 + *piVar17) * 8);
          }
        }
        if (bVar16) {
          uVar11 = *(uint *)(iVar22 + 0x1d9720);
        }
        else {
          uVar14 = *puVar19;
          uVar11 = *(uint *)(&DAT_001d9778 + (uVar14 >> 0xe & 0x3c));
          if (uVar11 == 8) {
            uVar11 = (uVar14 & 0x1f) + 8;
          }
          else if (uVar11 == 0x10) {
            uVar11 = (uVar14 & 0x1f) + 0x10;
          }
          else if (uVar11 == 0x2f) {
            switch(uVar14 >> 0xc & 0xf) {
            case 0:
              uVar11 = (uVar14 & 1) + 0x20;
              break;
            case 1:
              uVar11 = (uVar14 & 1) + 0x22;
              break;
            case 2:
              uVar11 = (uVar14 & 1) + 0x24;
              break;
            case 3:
              uVar11 = (uVar14 & 1) + 0x26;
              break;
            case 4:
              uVar11 = (uVar14 & 1) + 0x28;
              break;
            default:
              goto switchD_0001ffbc_default;
            }
          }
        }
        if (uVar11 == 0x30) goto switchD_0001ffbc_default;
        if (uVar11 < 0x10) {
          uVar14 = *(uint *)(iVar6 + 0x304);
        }
        else {
          uVar14 = *(uint *)(iVar6 + 0x300);
        }
        if ((uVar14 & *(uint *)(&DAT_001d91f0 + uVar11 * 4)) == 0) {
          *(int *)(param_1 + 0x24e0) = *(int *)(param_1 + 0x24e0) + 4;
          *(uint *)(param_1 + 0x24dc) = 1 << (loopIndex2 & 0x3f) | *(uint *)(param_1 + 0x24dc);
          if (bVar1 && bVar2) {
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            iVar10 = loopIndex << 2;
          }
          else {
            iVar10 = loopIndex * 4;
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *(undefined4 *)(iVar10 + param_1 + 0x24e4);
          }
        }
        else {
          if (*(char *)((int)piVar13 + uVar11 + 8) == '\0') {
            *(undefined1 *)(param_1 + 0x24e4) = 0;
            return;
          }
          iVar9 = piVar13[uVar11 + 10];
          iVar5 = piVar13[uVar11 + 0x2a];
          uVar14 = piVar13[uVar11 + 0x4a];
          uVar12 = piVar13[uVar11 + 0x6a];
          if (bVar1 && bVar2) {
            iVar10 = loopIndex << 2;
          }
          else {
            iVar10 = loopIndex * 4;
            puVar3 = *(undefined4 **)(*(int *)(iVar18 + uVar11 * 4) + 8);
            if (puVar3 != (undefined4 *)0x0) {
              *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *puVar3;
            }
          }
        }
        if ((loopIndex & 1) == 0) {
          iVar4 = uVar7 * 4 + param_1;
          *(int *)(iVar4 + 0x2528) = iVar9;
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) = uVar12 | *(uint *)(iVar4 + 0x1c04) & 0xf000;
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 | *(uint *)(iVar4 + 0x1be4) & 0x1f00 | *(uint *)(iVar4 + 0x1be4) & 0x2000;
        }
        else {
          iVar4 = uVar7 * 4 + param_1;
          *(uint *)(iVar4 + 0x2528) = iVar9 << 0x10 | *(uint *)(iVar4 + 0x2528);
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) =
               uVar12 << 0x10 | *(uint *)(iVar4 + 0x1c04) & 0xf0000000 | *(uint *)(iVar4 + 0x2410);
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 << 0x10 | *(uint *)(iVar4 + 0x1be4) & 0x1f000000 |
               *(uint *)(iVar4 + 0x1be4) & 0x20000000 | *(uint *)(iVar4 + 0x23f0);
        }
        loopIndex = loopIndex + 1;
        uVar7 = loopIndex >> 1;
      }
      if (loopIndex == uVar24) {
        return;
      }
      loopIndex2 = loopIndex2 + 1;
      iVar22 = iVar22 + 4;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  return;
}

/* FUN_00020210 @ 0x20210 (280 bytes) */
int FUN_00020210(ctx)
  int ctx;
{
  int iVar1;
  int renderHeight;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  iVar3 = *(int *)(ctx + 0x10);
  if (((unsigned char *)0x00003190)[iVar3] == '\0') {
    local_20 = *(int *)(ctx + 0x15c);
    local_1c = *(int *)(ctx + 0x160);
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = *(int *)(((unsigned char *)0x00003180) + iVar3);
    if (((unsigned char *)0x00002b7c)[ctx] == '\0') {
      local_24 = *(int *)(((unsigned char *)0x00003184) + iVar3);
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      renderHeight = *(int *)(ctx + 0x160);
    }
    else {
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      renderHeight = *(int *)(ctx + 0x160);
      local_24 = renderHeight - (*(int *)(((unsigned char *)0x00003184) + iVar3) + iVar1);
    }
    iVar3 = *(int *)(((unsigned char *)0x00003188) + iVar3);
    if (local_28 < 0) {
      iVar3 = iVar3 + local_28;
      local_28 = 0;
    }
    if (local_24 < 0) {
      iVar1 = iVar1 + local_24;
      local_24 = 0;
    }
    local_20 = *(int *)(ctx + 0x15c) - local_28;
    if (iVar3 <= local_20) {
      local_20 = iVar3;
    }
    local_1c = renderHeight - local_24;
    if (iVar1 <= renderHeight - local_24) {
      local_1c = iVar1;
    }
    if (local_20 < 1) {
      return;
    }
    if (local_1c < 1) {
      return;
    }
  }
  local_20 = local_28 + local_20;
  local_1c = local_24 + local_1c;
  FUN_0008f7f0(ctx + 0x240,0,0,&local_28,0);
  return;
}

/* FUN_00020330 @ 0x20330 (216 bytes) */
int FUN_00020330(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar2 = param_2 & *(uint *)(param_1 + 0x158);
  if (((((unsigned char *)0x00002e43)[iVar1] == '\0' && ((unsigned char *)0x00002e40)[iVar1] == '\0') &&
      ((unsigned char *)0x00002e41)[iVar1] == '\0') && ((unsigned char *)0x00002e42)[iVar1] == '\0') {
    uVar2 = uVar2 & 0xffffbfff;
  }
  if (((unsigned char *)0x00002e44)[iVar1] == '\0') {
    uVar2 = uVar2 & 0xfffffeff;
  }
  if ((uVar2 & 0x200) != 0) {
    gld_clearSoftwareColorBuffer(param_1,iVar1);
  }
  if ((uVar2 & 0x4000) != 0) {
    uVar2 = uVar2 & 0xffffbfff;
    ((int (*)())FUN_00020210)(param_1);
  }
  if ((uVar2 & 0x500) != 0) {
    FUN_000a6cb0(param_1 + 0x240,uVar2);
    return;
  }
  return;
}

/* gldDisplayNotificationCallback @ 0x20420 (1716 bytes) */
int gldDisplayNotificationCallback(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  uint param_7;
  undefined4 param_8;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int value2;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iStack_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int aiStack_4c [3];
  
  iStack_68 = 0;
  aiStack_4c[0] = 0;
  uStack_64 = 0;
  iStack_60 = 0;
  iStack_5c = 0;
  iStack_58 = 0;
  iStack_54 = 0;
  iStack_50 = 0;
  if (param_5 != 0) {
    iVar12 = param_5;
    iVar1 = _CFStringCreateWithCString(0,"pid",0x600);
    iVar2 = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
    iVar3 = _CFStringCreateWithCString(0,"log_notifications",0x600);
    iVar4 = _CFStringCreateWithCString(0,"fsaa_samples",0x600);
    iVar5 = _CFStringCreateWithCString(0,"fsaa_mode",0x600);
    iVar6 = _CFStringCreateWithCString(0,"aniso_level",0x600);
    iVar7 = _CFStringCreateWithCString(0,"vsync_mode",0x600);
    iVar8 = _CFStringCreateWithCString(0,"performance_level",0x600);
    if (iVar1 != 0) {
      if (((((iVar2 != 0) && (iVar3 != 0)) && (iVar4 != 0)) && ((iVar6 != 0 && (iVar7 != 0)))) &&
         (iVar8 != 0)) {
        iVar9 = _CFDictionaryGetValue(param_5,iVar3);
        if (((iVar9 != 0) && (iVar9 = _CFNumberGetValue(iVar9,3,&iStack_60), iVar9 != 0)) &&
           (iStack_60 != 0)) {
          _puts("\nATI R300 GL Driver Notification Callback");
          gld_printApplicationPath(param_2);
        }
        iVar9 = _CFDictionaryGetValue(param_5,iVar1);
        value2 = _CFDictionaryGetValue(param_5,iVar2);
        if ((iVar9 == 0) || (value2 == 0)) {
          if (iStack_60 != 0) {
            if (iVar9 == 0) {
              _puts("  failed to extract process id from CFDictionary | expected \"pid\"");
            }
            if (value2 == 0) {
              _puts(
                   "  failed to extract gl display mask from CFDictionary | expected \"gldisplaymask\""
                   );
            }
          }
        }
        else {
          iVar9 = _CFNumberGetValue(iVar9,3,aiStack_4c);
          if ((iVar9 != 0) && (iVar9 = _CFNumberGetValue(value2,3,&uStack_64), iVar9 != 0)) {
            iVar9 = *(int *)(param_2 + 0x2a60);
            if ((iVar9 != aiStack_4c[0]) ||
               (param_7 = uStack_64, (*(uint *)(param_2 + 0x2a64) & uStack_64) == 0)) {
              if (iStack_60 != 0) {
                if (iVar9 != aiStack_4c[0]) {
                  printf_LDBLStub_1a337c("  process id does not match | expected %i | received %i\n",iVar9,
                               aiStack_4c[0],param_4,iVar12,param_6,param_7,param_8);
                }
                if ((*(uint *)(param_2 + 0x2a64) & uStack_64) == 0) {
                  printf_LDBLStub_1a337c("  gl display mask does not match | expected 0x%x | received 0x%x\n",
                               *(uint *)(param_2 + 0x2a64),uStack_64,param_4,iVar12,param_6,param_7,
                               param_8);
                }
              }
            }
            else {
              *(undefined1 *)(param_2 + 0x2a68) = 1;
              uVar13 = uStack_64;
              if (iStack_60 != 0) {
                printf_LDBLStub_1a337c("  process id [%i] and gl display mask [0x%x] match\n",aiStack_4c[0],
                             uStack_64,param_4,iVar12,param_6,uStack_64,param_8);
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar5);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts("  failed to extract fsaa mode from CFDictionary | expected \"fsaa_mode\"");
                }
              }
              else {
                iVar9 = _CFNumberGetValue(iVar9,3,&iStack_58);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a74) = iStack_58, iStack_60 != 0)) {
                  if (iStack_58 == 1) {
                    _puts("  fsaa mode | multisampling");
                  }
                  else if (iStack_58 == 0) {
                    _puts("  fsaa mode | app value");
                  }
                  else if (iStack_58 == 2) {
                    _puts("  fsaa mode | supersampling");
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar4);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract fsaa samples from CFDictionary | expected \"fsaa_samples\""
                       );
                }
              }
              else {
                piVar11 = &iStack_5c;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a70) = iStack_5c, iStack_60 != 0)) {
                  if (iStack_5c == 0) {
                    _puts("  fsaa samples | app value");
                  }
                  else {
                    printf_LDBLStub_1a337c("  fsaa samples | %i\n",iStack_5c,piVar11,param_4,iVar12,param_6,
                                 uVar13,param_8);
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar6);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract anisotropic filtering samples from CFDictionary | expected \"aniso_level\""
                       );
                }
              }
              else {
                piVar11 = &iStack_54;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a7c) = iStack_54, iStack_60 != 0)) {
                  if (iStack_54 == 0) {
                    _puts("  anisotropic filtering samples | app value");
                  }
                  else {
                    printf_LDBLStub_1a337c("  anisotropic filtering samples | %i\n",iStack_54,piVar11,param_4,
                                 iVar12,param_6,uVar13,param_8);
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar7);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract vertical sync mode from CFDictionary | expected \"vsync_mode\""
                       );
                }
              }
              else {
                iVar9 = _CFNumberGetValue(iVar9,3,&iStack_50);
                if ((iVar9 != 0) && (*(char *)(param_2 + 0x2a6c) = (char)iStack_50, iStack_60 != 0))
                {
                  if (iStack_50 == 1) {
                    _puts("  vsync mode | forced off");
                  }
                  else if (iStack_50 == 0) {
                    _puts("  vsync mode | app value");
                  }
                  else if (iStack_50 == 2) {
                    _puts("  vsync mode | forced on");
                  }
                }
              }
              iVar9 = _CFDictionaryGetValue(param_5,iVar8);
              if (iVar9 == 0) {
                if (iStack_60 != 0) {
                  _puts(
                       "  failed to extract performance level from CFDictionary | expected \"performance_level\""
                       );
                }
              }
              else {
                piVar11 = &iStack_68;
                iVar9 = _CFNumberGetValue(iVar9,3,piVar11);
                if ((iVar9 != 0) && (*(int *)(param_2 + 0x2a78) = iStack_68, iStack_60 != 0)) {
                  if (iStack_68 == 0) {
                    _puts("  performance cheats | off");
                  }
                  else {
                    printf_LDBLStub_1a337c("  performance cheats level | %d\n",iStack_68,piVar11,param_4,
                                 iVar12,param_6,uVar13,param_8);
                  }
                }
              }
            }
          }
        }
      }
      _CFRelease(iVar1);
    }
    if (iVar2 != 0) {
      _CFRelease(iVar2);
    }
    if (iVar3 != 0) {
      _CFRelease(iVar3);
    }
    if (iVar4 != 0) {
      _CFRelease(iVar4);
    }
    if (iVar5 != 0) {
      _CFRelease(iVar5);
    }
    if (iVar6 != 0) {
      _CFRelease(iVar6);
    }
    if (iVar7 != 0) {
      _CFRelease(iVar7);
    }
    if (iVar8 != 0) {
      _CFRelease(iVar8);
    }
  }
  return;
}

/* FUN_00020b00 @ 0x20b00 (40 bytes) */
int FUN_00020b00(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x2a7c) = 0;
  *(undefined4 *)(param_1 + 0x2a70) = 0;
  *(undefined1 *)(param_1 + 0x2a6c) = 0;
  *(undefined1 *)(param_1 + 0x2a6a) = 0;
  *(undefined4 *)(param_1 + 0x2a74) = 0;
  *(undefined4 *)(param_1 + 0x2a78) = 0;
  return;
}

/* FUN_00020b30 @ 0x20b30 (620 bytes) */
int FUN_00020b30(ctx, srcX, srcY, width, height, param_6, param_7, param_8, param_9)
  int ctx;
  int srcX;
  uint srcY;
  int width;
  uint height;
  int param_6;
  uint param_7;
  undefined4 param_8;
  uint param_9;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int engineState;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = 3;
  if ((*(uint *)(ctx + 0x154) & 0xf) != 3) {
    iVar8 = 6;
  }
  puVar3 = *(undefined4 **)(ctx + 0x1dc);
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  if (*(undefined4 **)(ctx + 0x1e0) <= puVar3 + 0x10) {
    ((int (*)())gld_submitRing)(ctx,0x1000000);
    puVar3 = *(undefined4 **)(ctx + 0x1dc);
  }
  *(undefined4 **)(ctx + 0x1dc) = puVar3 + 0x10;
  uVar1 = 0;
  *puVar3 = 0xd07;
  engineState = *(int *)(ctx + 0x10);
  if (*(short *)(((unsigned char *)0x00002dba) + engineState) != 0) {
    if ((*(uint *)(ctx + 0x154) & 0xf) == 3) {
      uVar6 = 0x7c00;
      if (((unsigned char *)0x00002e40)[engineState] == '\0') {
        uVar6 = 0;
      }
      uVar7 = 0x3e0;
      if (((unsigned char *)0x00002e41)[engineState] == '\0') {
        uVar7 = 0;
      }
      uVar1 = 0x1f;
      if (((unsigned char *)0x00002e42)[engineState] == '\0') {
        uVar1 = 0;
      }
      uVar1 = uVar1 | uVar7 | -(uint)(byte)((unsigned char *)0x00002e43)[engineState] >> 0x10 & 0x8000 | uVar6;
      uVar1 = uVar1 | uVar1 << 0x10;
    }
    else {
      uVar6 = 0xff000000;
      if (((unsigned char *)0x00002e43)[engineState] == '\0') {
        uVar6 = 0;
      }
      uVar7 = 0xff0000;
      if (((unsigned char *)0x00002e40)[engineState] == '\0') {
        uVar7 = 0;
      }
      uVar2 = 0xff00;
      if (((unsigned char *)0x00002e41)[engineState] == '\0') {
        uVar2 = 0;
      }
      uVar1 = 0xff;
      if (((unsigned char *)0x00002e42)[engineState] == '\0') {
        uVar1 = 0;
      }
      uVar1 = uVar1 | uVar2 | uVar6 | uVar7;
    }
  }
  puVar3[1] = uVar1;
  puVar3[2] = 0xc0089b00;
  puVar3[3] = iVar8 << 8 | (param_9 & 0xff) << 0x10 | 0x20030ff;
  puVar5 = *(uint **)(ctx + 0x1d8);
  *puVar5 = (int)(puVar3 + 4) - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(ctx + 0x1d8) = puVar3 + 4;
  puVar3[5] = param_8;
  puVar3[6] = 0;
  puVar3[4] = 0x2a000000;
  puVar3[7] = 0;
  puVar3[8] = 0;
  puVar3[9] = srcX << 0x10 | srcY & 0xffff;
  puVar3[10] = param_6 << 0x10 | param_7 & 0xffff;
  puVar3[0xb] = width << 0x10 | height & 0xffff;
  puVar3[0xc] = 0xd0b;
  puVar3[0xd] = 5;
  puVar3[0xe] = 0x5c8;
  puVar3[0xf] = 0x10000;
  return;
}

/* FUN_00021c70 @ 0x21c70 (1540 bytes) */
int FUN_00021c70(ctx, srcX, srcY, width, height, param_6, param_7, param_8, param_9)
  int ctx;
  undefined4 srcX;
  undefined4 srcY;
  undefined4 width;
  undefined4 height;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  uint rb3d_blendcntl;
  uint fg_alpha_func;
  uint fg_fog_blend;
  undefined4 ga_point_size;
  undefined4 sc_scissor1;
  undefined4 rb3d_ropcntl;
  undefined4 rb3d_color_channel_mask;
  undefined4 tx_format2;
  undefined4 tx_format1;
  undefined4 tx_format0;
  undefined4 tx_filter0;
  undefined4 rs_ip_0;
  undefined4 rs_count;
  undefined4 us_out_fmt_3;
  undefined4 us_out_fmt_2;
  undefined4 us_out_fmt_1;
  undefined4 us_out_fmt_0;
  undefined4 gb_ps3_enable;
  undefined4 tx_enable;
  undefined4 ga_color_control;
  undefined4 ga_poly_mode;
  undefined4 zb_cntl;
  undefined4 vap_out_vtx_fmt_0;
  undefined4 gb_enable;
  undefined4 rb3d_dither_ctl;
  undefined4 su_cull_mode;
  undefined4 vap_vte_cntl;
  undefined4 vap_clip_cntl;
  undefined4 vap_cntl_status;
  undefined4 zb_zstencilcntl;
  undefined4 zb_bw_cntl;
  undefined4 gb_aa_config;
  undefined4 gb_mspos1;
  undefined4 sc_screendoor;
  undefined4 sc_edgerule;
  undefined *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 a3;
  undefined4 a4;
  undefined4 a5;
  uint uVar6;
  undefined4 *puVar7;
  int a0;
  
  a0 = ctx + 0x240;
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  uVar3 = srcY;
  a3 = width;
  a4 = height;
  a5 = param_6;
  puVar4 = (undefined4 *)
           (**(code **)(ctx + 0x2998))(a0,0x406,srcY,width,height,param_6,param_7,param_8)
  ;
  *(undefined4 **)(ctx + 0x298c) = puVar4;
  puVar7 = puVar4;
  if (*(char *)(ctx + 0x2a42) == '\0') {
    puVar7 = puVar4 + 2;
    *puVar4 = 0x5c8;
    puVar4[1] = 0x10000000;
    *(undefined1 *)(ctx + 0x2a42) = 1;
  }
  puVar2 = *(uint **)(ctx + 0x1d8);
  uVar6 = *puVar2;
  *puVar2 = (int)puVar7 - (int)puVar2 >> 2 | uVar6;
  *(undefined4 **)(ctx + 0x1d8) = puVar7;
  puVar7[2] = param_9;
  puVar7[1] = 0x404;
  *puVar7 = 0x2d000000;
  puVar7[3] = srcX;
  puVar7[4] = srcY;
  puVar7[5] = width;
  puVar7[6] = height;
  puVar7[7] = param_6;
  puVar7[8] = param_7;
  *(undefined4 **)(ctx + 0x298c) = puVar7 + 0x404;
  (**(code **)(ctx + 0x299c))(a0,puVar7 + 0x404,uVar3,a3,a4,a5,uVar6);
  iVar5 = (**(code **)(ctx + 0x2998))(a0,0xbf);
  *(int *)(ctx + 0x298c) = iVar5;
  puVar2 = *(uint **)(ctx + 0x1d8);
  *puVar2 = iVar5 - (int)puVar2 >> 2 | *puVar2;
  *(undefined4 *)(ctx + 0x1d8) = *(undefined4 *)(ctx + 0x298c);
  puVar7 = *(undefined4 **)(ctx + 0x298c);
  *puVar7 = 0x33000000;
  puVar7[1] = 0;
  *(undefined4 **)(ctx + 0x298c) = puVar7 + 2;
  puVar7[2] = ((unsigned char *)0x00001393U);
  puVar7[3] = 10;
  puVar7[4] = ((unsigned char *)0x000013c6U);
  puVar7[5] = 3;
  puVar7[6] = 0x5c8;
  puVar7[7] = 0x20000;
  puVar7[8] = ((unsigned char *)0x000010eaU);
  sc_edgerule = *(undefined4 *)(ctx + 0x1cfc);
  puVar7[10] = ((unsigned char *)0x000010faU);
  puVar7[9] = sc_edgerule;
  sc_screendoor = *(undefined4 *)(ctx + 0x1da0);
  puVar7[0xc] = 0xc0001000;
  puVar7[0xe] = 0x11004;
  puVar7[0xb] = sc_screendoor;
  puVar7[0xf] = *(undefined4 *)(ctx + 0x1ca8);
  gb_mspos1 = *(undefined4 *)(ctx + 0x1cac);
  puVar7[0x11] = ((unsigned char *)0x00001008U);
  puVar7[0x10] = gb_mspos1;
  gb_aa_config = *(undefined4 *)(ctx + 0x1ca0);
  puVar7[0x13] = ((unsigned char *)0x000010e9U);
  puVar7[0x12] = gb_aa_config;
  puVar7[0x14] = *(undefined4 *)(ctx + 0x1d20);
  puVar7[0x15] = ((unsigned char *)0x000013c7U);
  zb_bw_cntl = *(undefined4 *)(ctx + 0x1cf0);
  puVar7[0x17] = ((unsigned char *)0x000013c1U);
  puVar7[0x16] = zb_bw_cntl;
  zb_zstencilcntl = *(undefined4 *)(ctx + 0x1ce4);
  puVar7[0x19] = 0x850;
  puVar7[0x18] = zb_zstencilcntl;
  vap_cntl_status = *(undefined4 *)(ctx + 0x1dc0);
  puVar7[0x1b] = 0x887;
  puVar7[0x1a] = vap_cntl_status;
  vap_clip_cntl = *(undefined4 *)(ctx + 0x1db4);
  puVar7[0xbd] = 0x82c;
  puVar7[0x1c] = vap_clip_cntl;
  vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
  puVar7[0x1d] = ((unsigned char *)0x000010aeU);
  puVar7[0xbe] = vap_vte_cntl;
  su_cull_mode = *(undefined4 *)(ctx + 0x1d70);
  puVar7[0x1f] = ((unsigned char *)0x00001394U);
  puVar7[0x1e] = su_cull_mode;
  rb3d_dither_ctl = *(undefined4 *)(ctx + 0x1d30);
  puVar7[0x21] = ((unsigned char *)0x00001380U);
  puVar7[0x23] = ((unsigned char *)0x00001002U);
  puVar7[0x22] = 0;
  puVar7[0x20] = rb3d_dither_ctl;
  puVar7[0x24] = *(undefined4 *)(ctx + 0x1d90);
  gb_enable = *(undefined4 *)(ctx + 0x1d90);
  puVar7[0x25] = 0x824;
  puVar7[0x24] = gb_enable;
  vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + 0x1ddc);
  puVar7[0x27] = 0x825;
  puVar7[0x26] = vap_out_vtx_fmt_0;
  puVar7[0x28] = *(undefined4 *)(ctx + 0x1de0);
  puVar7[0x29] = 0x82d;
  puVar1 = PTR_DAT_001e88c8;
  uVar3 = *(undefined4 *)(0x000026c8 + ctx + 4);
  puVar7[0x2b] = 0x854;
  puVar7[0x2a] = uVar3;
  uVar3 = **(undefined4 **)(ctx + 0x2680);
  puVar7[0x2d] = 0x878;
  puVar7[0x2c] = uVar3;
  uVar3 = **(undefined4 **)(ctx + 0x2684);
  puVar7[0x2f] = ((unsigned char *)0x000013c0U);
  puVar7[0x2e] = uVar3;
  zb_cntl = *(undefined4 *)(ctx + 0x1ce0);
  puVar7[0x31] = ((unsigned char *)0x000012f0U);
  puVar7[0x30] = zb_cntl;
  fg_fog_blend = *(uint *)(ctx + 0x1d2c);
  puVar7[0x32] = fg_fog_blend;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar7[0x32] = fg_fog_blend & 0xfffffffe;
  }
  puVar7[0x33] = ((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + 0x1c8c);
  puVar7[0x34] = fg_alpha_func;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar7[0x34] = fg_alpha_func & 0xfffff7ff;
  }
  puVar7[0x35] = ((unsigned char *)0x000010a2U);
  ga_poly_mode = *(undefined4 *)(ctx + 0x1d7c);
  puVar7[0x37] = ((unsigned char *)0x00001381U);
  puVar7[0x36] = ga_poly_mode;
  rb3d_blendcntl = *(uint *)(ctx + 0x1cc0);
  puVar7[0x38] = rb3d_blendcntl;
  if ((*(uint *)(puVar1 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x4000) == 0) {
    puVar7[0x38] = rb3d_blendcntl & 0xfffffffc;
  }
  puVar7[0x39] = ((unsigned char *)0x0000109eU);
  uVar3 = *(undefined4 *)(ctx + 0x1d6c);
  puVar7[0x3b] = ((unsigned char *)0x00001096U);
  puVar7[0x3a] = uVar3;
  ga_color_control = *(undefined4 *)(ctx + 0x1df8);
  puVar7[0x3d] = ((unsigned char *)0x00001041U);
  puVar7[0x3a] = ga_color_control;
  tx_enable = *(undefined4 *)(ctx + 0x29f0);
  puVar7[0x3f] = ((unsigned char *)0x00001046U);
  puVar7[0x3e] = tx_enable;
  gb_ps3_enable = *(undefined4 *)(ctx + 0x1dfc);
  puVar7[0x41] = ((unsigned char *)0x00001094U);
  puVar7[0x59] = ((unsigned char *)0x00001095U);
  puVar7[0x42] = 0;
  puVar7[0x7f] = ((unsigned char *)0x00001180U);
  puVar7[0x43] = ((unsigned char *)0x00001095U);
  puVar7[0x45] = ((unsigned char *)0x00001095U);
  puVar7[0x47] = ((unsigned char *)0x00001095U);
  puVar7[0x40] = gb_ps3_enable;
  puVar7[0x49] = ((unsigned char *)0x00001095U);
  puVar7[0x4b] = ((unsigned char *)0x00001095U);
  puVar7[0x4d] = ((unsigned char *)0x00001095U);
  puVar7[0x4f] = ((unsigned char *)0x00001095U);
  puVar7[0x51] = ((unsigned char *)0x00001095U);
  puVar7[0x53] = ((unsigned char *)0x00001095U);
  puVar7[0x55] = ((unsigned char *)0x00001095U);
  puVar7[0x57] = ((unsigned char *)0x00001095U);
  puVar7[0x5b] = 0xc0221000;
  puVar7[0x80] = 2;
  puVar7[0x81] = ((unsigned char *)0x00001189U);
  puVar7[0x83] = ((unsigned char *)0x00001181U);
  puVar7[0x85] = ((unsigned char *)0x0000118dU);
  puVar7[0x87] = ((unsigned char *)0x0000118eU);
  puVar7[0x89] = ((unsigned char *)0x0000118cU);
  puVar7[0x8b] = ((unsigned char *)0x000011a9U);
  us_out_fmt_0 = *(undefined4 *)(ctx + 0x257c);
  puVar7[0x8d] = ((unsigned char *)0x000011aaU);
  puVar7[0x8c] = us_out_fmt_0;
  us_out_fmt_1 = *(undefined4 *)(ctx + 0x2580);
  puVar7[0x8f] = ((unsigned char *)0x000011abU);
  puVar7[0x8e] = us_out_fmt_1;
  us_out_fmt_2 = *(undefined4 *)(ctx + 0x2584);
  puVar7[0x91] = ((unsigned char *)0x000011acU);
  puVar7[0x90] = us_out_fmt_2;
  us_out_fmt_3 = *(undefined4 *)(ctx + 0x2588);
  puVar7[0x93] = ((unsigned char *)0x000010c0U);
  puVar7[0x92] = us_out_fmt_3;
  rs_count = *(undefined4 *)(ctx + 0x216c);
  puVar7[0x95] = ((unsigned char *)0x000010c1U);
  puVar7[0x97] = ((unsigned char *)0x000010c8U);
  puVar7[0x99] = ((unsigned char *)0x0000101dU);
  puVar7[0x94] = rs_count;
  rs_ip_0 = *(undefined4 *)(ctx + 0x2128);
  puVar7[0x9b] = ((unsigned char *)0x0000138aU);
  puVar7[0xa2] = 0;
  puVar7[0x9c] = 0;
  puVar7[0x9f] = ((unsigned char *)0x00001040U);
  puVar7[0x9e] = 0;
  puVar7[0xa0] = 0;
  puVar7[0x9d] = ((unsigned char *)0x0000138eU);
  puVar7[0x9a] = rs_ip_0;
  puVar7[0xa1] = ((unsigned char *)0x00001150U);
  puVar7[0xa3] = ((unsigned char *)0x00001100U);
  tx_filter0 = *(undefined4 *)(ctx + 0x1f1c);
  puVar7[0xa5] = ((unsigned char *)0x00001110U);
  puVar7[0xa4] = tx_filter0;
  puVar7[0xa6] = *(undefined4 *)(ctx + 0x1f5c);
  puVar7[0xa7] = ((unsigned char *)0x00001120U);
  tx_format0 = *(undefined4 *)(ctx + 0x1f9c);
  puVar7[0xa9] = ((unsigned char *)0x00001130U);
  puVar7[0xa8] = tx_format0;
  tx_format1 = *(undefined4 *)(ctx + 0x1fdc);
  puVar7[0xab] = ((unsigned char *)0x00001140U);
  puVar7[0xaa] = tx_format1;
  tx_format2 = *(undefined4 *)(ctx + 0x201c);
  puVar7[0xad] = ((unsigned char *)0x000010f4U);
  puVar7[0xae] = 0xaaaa;
  puVar7[0xaf] = ((unsigned char *)0x00001383U);
  puVar7[0xac] = tx_format2;
  rb3d_color_channel_mask = *(undefined4 *)(ctx + 0x1d34);
  puVar7[0xb1] = ((unsigned char *)0x00001386U);
  puVar7[0xb0] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(undefined4 *)(ctx + 0x1d38);
  puVar7[0xb3] = 0x110f8;
  puVar7[0xb2] = rb3d_ropcntl;
  puVar7[0xb4] = *(undefined4 *)(ctx + 0x1d98);
  sc_scissor1 = *(undefined4 *)(ctx + 0x1d50);
  puVar7[0xb6] = ((unsigned char *)0x00001087U);
  puVar7[0xb5] = sc_scissor1;
  ga_point_size = *(undefined4 *)(ctx + 0x1f0c);
  puVar7[0xb8] = 0x31080;
  puVar7[0xb7] = ga_point_size;
  puVar7[0xb9] = *(undefined4 *)(ctx + 0x1efc);
  puVar7[0xba] = *(undefined4 *)(ctx + 0x1f04);
  puVar7[0xbb] = *(undefined4 *)(ctx + 0x1f00);
  puVar7[0xbc] = *(undefined4 *)(ctx + 0x1f08);
  FUN_0004c100(puVar7 + 2,a0);
  *(undefined4 **)(ctx + 0x298c) = puVar7 + 0xbf;
                    
                    
  (**(code **)(ctx + 0x299c))(a0,puVar7 + 0xbf);
  return;
}

/* noop_22280 @ 0x22280 (4 bytes) */
int noop_22280()
{
  return;
}

/* _gldUpdateDispatch @ 0x22290 (2632 bytes) */
uint _gldUpdateDispatch(int ctx,int dispatch,uint *dirtyBits,undefined4 scratchR6,undefined4 scratchR7,undefined4 scratchR8,double fpPassThrough1,double fpPassThrough2,double fpPassThrough3,double fpPassThrough4,double fpPassThrough5,double fpPassThrough6,double fpPassThrough7,double fpPassThrough8,double staleFprArg9,double staleFprArg10,double staleFprArg11,double staleFprArg12,double staleFprArg13)
{
  int *programObject;
  uint dirtyWord2;
  uint dirtyWord4;
  uint unitObjectValue;
  uint pendingMaskCleared;
  uint dirtyWord1;
  uint unitBitsLeft;
  int textureComplete2;
  int targetsLeft;
  int textureComplete;
  int targetOffset;
  int unitRowOffset;
  uint dirtyWord0;
  uint unitIndex;
  uint dirtyWord3;
  uint pendingTextureMask;
  uint unitMask;
  uint renderFlags;
  bool mutexHeld;
  byte attachFormat;
  bool noUnitUpdate;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  int *framebufferObj;
  int *r4Out0;
  int *r4Out1;
  int *r4Out2;
  int *r4Out3;
  int *r4Out4;
  int *r4Out5;
  uint *dirtyBitsArg;
  undefined4 *currentProgram;
  short *psVar13;
  uint target;
  uint uVar15;
  uint boundTexture;
  uint result;
  char programActive;
  uint *dirtyWord1Ptr;
  uint uVar20;
  int stateOffset;
  uint uVar22;
  int unitRowOffset2;
  uint uVar24;
  uint *dirtyWord3Ptr;
  bool bVar27;
  uint uVar26;
  int targetsLeft2;
  double staleStackArg_ffffff78;
  double staleStackArg_ffffff80;
  double staleStackArg_ffffff88;
  double staleStackArg_ffffff90;
  double staleStackArg_ffffff98;
  
  if (*(char *)(ctx + 0x2a69) == '\0') {
    if (*(char *)(ctx + 0x2a44) != '\0') {
      dirtyBits[2] = dirtyBits[2] | 0xfffffffd;
      *dirtyBits = 0xffffffff;
      dirtyBits[1] = dirtyBits[1] | 0x3ffffff;
      dirtyBits[3] = dirtyBits[3] | 0x7ffffff;
      dirtyBits[4] = 0xffffffff;
      *(undefined4 *)(ctx + 0x29fc) = 0xffffffff;
      *(undefined1 *)(ctx + 0x2a44) = 0;
      *(undefined1 *)(ctx + 0x2a43) = 1;
      *(undefined1 *)(ctx + 0x26bd) = 1;
      *(uint *)(GLD_updateFlags + ctx) = *(uint *)(GLD_updateFlags + ctx) | 7;
    }
  }
  else {
    dirtyBits[2] = dirtyBits[2] | 0xfffffffd;
    *dirtyBits = 0xffffffff;
    dirtyBits[1] = dirtyBits[1] | 0x3ffffff;
    dirtyBits[3] = dirtyBits[3] | 0x7ffffff;
    dirtyBits[4] = 0xffffffff;
    *(undefined4 *)(ctx + 0x29fc) = 0xffffffff;
    *(undefined1 *)(ctx + 0x2a43) = 1;
    *(undefined1 *)(ctx + 0x2a44) = 0;
    *(undefined1 *)(ctx + 0x26bd) = 1;
    *(undefined1 *)(ctx + 0x2a69) = 0;
    *(uint *)(GLD_updateFlags + ctx) = *(uint *)(GLD_updateFlags + ctx) | 7;
  }
  dirtyBitsArg = dirtyBits;
  if ((int)*dirtyBits < 0) {
    fpPassThrough1 = (double)FUN_00007d50(ctx,dispatch,dirtyBits,scratchR6,scratchR7,scratchR8);
  }
  framebufferObj = *(int **)(ctx + GLD_boundFramebuffer);
  if (((framebufferObj == (int *)0x0) || (*(ushort *)(*framebufferObj + 0x90) == 0)) ||
     (iVar8 = *(int *)((uint)*(ushort *)(*framebufferObj + 0x90) * 4 + framebufferObj[1] + -0x23380), iVar8 == 0))
  {
LAB_00022438:
    result = 4;
    if ((*dirtyBits & 0x180) != 0) {
      if (framebufferObj != (int *)0x0) {
        ((int (*)())gld_emitFramebufferState)(ctx,framebufferObj);
      }
      if ((*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x1a0) == 0) ||
         (result = 0xc, *(int *)(ctx + GLD_boundFramebuffer) != 0)) {
        result = 4;
      }
      fpPassThrough1 = (double)FUN_00017260(ctx);
      framebufferObj = r4Out0;
    }
    dirtyWord1Ptr = dirtyBits + 1;
    unitMask = (uint)*(ushort *)((int)dirtyBits + 6);
    currentProgram = *(undefined4 **)(*(int *)(ctx + GLD_engineObjects) + 0x19c);
    if (currentProgram == (undefined4 *)0x0) {
      programActive = '\0';
      if ((((unsigned char *)0x0000430c)[*(int *)(ctx + GLD_engineState)] != '\0') &&
         ((psVar13 = (short *)**(undefined4 **)(*(int *)(ctx + GLD_engineObjects) + 400),
          *(int *)(psVar13 + 2) == 0 || (programActive = '\x01', *psVar13 == -0x7e00)))) goto LAB_00022540;
    }
    else if ((*(int *)((short *)*currentProgram + 2) == 0) || (*(short *)*currentProgram == -0x7e00)) {
LAB_00022540:
      programActive = '\0';
    }
    else {
      programActive = '\x01';
      if (((currentProgram[0xe] != 0) && (uVar9 = *(uint *)(currentProgram[0xe] + 0x20), (uVar9 & 0x1000000) != 0)
          ) && ((uVar9 >> 0x17 & 1) != (uint)(byte)((unsigned char *)GLD_yInverted)[ctx])) {
        dirtyBits[3] = dirtyBits[3] | 0x1000000;
      }
    }
    if ((*(char *)(ctx + GLD_programActive) == programActive) && (uVar9 = dirtyBits[3], (uVar9 & 0x5000000) == 0)) {
      noUnitUpdate = false;
      if (unitMask != 0) goto LAB_00022580;
    }
    else {
      *(char *)(ctx + GLD_programActive) = programActive;
      unitMask = 0xffff;
      *dirtyWord1Ptr = *dirtyWord1Ptr | 0xffff;
LAB_00022580:
      _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
      programObject = *(int **)(*(int *)(ctx + GLD_engineObjects) + 0x19c);
      if (programObject == (int *)0x0) {
        if (((((unsigned char *)0x0000430c)[*(int *)(ctx + GLD_engineState)] != '\0') &&
            (currentProgram = *(undefined4 **)(*(int *)(ctx + GLD_engineObjects) + 400),
            currentProgram != (undefined4 *)0x0)) && (psVar13 = (short *)*currentProgram, *psVar13 != -0x7e00)) {
          uVar9 = *(uint *)(psVar13 + 4);
          uVar22 = *(uint *)(psVar13 + 6);
          goto LAB_000225e8;
        }
        unitIndex = 0;
        stateOffset = 0;
        unitRowOffset2 = 0;
        iVar8 = ctx;
        uVar9 = unitMask;
        do {
          if ((uVar9 & 1) != 0) {
            target = 0;
            targetsLeft2 = 5;
            do {
              if ((*(uint *)(((unsigned char *)0x000031d4) + stateOffset + *(int *)(ctx + GLD_engineState)) &
                  1 << (target & 0x3f)) != 0) {
                target = *(uint *)(unitRowOffset2 + *(int *)(ctx + GLD_engineObjects) + target * 4);
                if ((*(byte *)(target + 0x39) & 0x87) == 0) {
                  uVar24 = target & -(uint)*(byte *)(target + 0x3d);
                }
                else {
                  textureComplete2 = gldTextureMakeResident(ctx,target,dirtyBitsArg,scratchR6,scratchR7,scratchR8);
                  if ((textureComplete2 == 0) || (uVar24 = target, *(char *)(target + 0x3d) == '\0')) {
                    uVar24 = 0;
                  }
                }
                pendingMaskCleared = *(uint *)(ctx + GLD_pendingTextureMask) & ~(1 << (unitIndex & 0x3f));
                *(uint *)(ctx + GLD_pendingTextureMask) = pendingMaskCleared;
                *(uint *)(ctx + GLD_pendingTextureMask) =
                     pendingMaskCleared | (uint)*(byte *)(target + 0x44) << (unitIndex & 0x3f);
                goto LAB_00022740;
              }
              target = target + 1;
              targetsLeft2 = targetsLeft2 + -1;
            } while (targetsLeft2 != 0);
            uVar24 = 0;
            *(uint *)(ctx + GLD_pendingTextureMask) = *(uint *)(ctx + GLD_pendingTextureMask) & ~(1 << (unitIndex & 0x3f));
LAB_00022740:
            *(uint *)(iVar8 + 0x18c) = uVar24;
          }
          uVar9 = uVar9 >> 1;
          unitIndex = unitIndex + 1;
          unitRowOffset2 = unitRowOffset2 + 0x14;
          stateOffset = stateOffset + 0x7c;
          iVar8 = iVar8 + 4;
        } while (uVar9 != 0);
      }
      else {
        iVar8 = *programObject;
        uVar9 = *(uint *)(iVar8 + 8);
        uVar22 = *(uint *)(iVar8 + 0xc);
LAB_000225e8:
        uVar24 = 0;
        unitRowOffset = 0;
        iVar8 = ctx;
        unitBitsLeft = unitMask;
        do {
          if ((unitBitsLeft & 1) != 0) {
            if ((uVar22 & 0xf) < 5) {
              boundTexture = *(uint *)(unitRowOffset + *(int *)(ctx + GLD_engineObjects) + (uVar22 & 0xf) * 4);
              if ((*(byte *)(boundTexture + 0x39) & 0x87) == 0) {
                unitObjectValue = boundTexture & -(uint)*(byte *)(boundTexture + 0x3d);
              }
              else {
                textureComplete = gldTextureMakeResident(ctx,boundTexture,dirtyBitsArg,scratchR6,scratchR7,scratchR8);
                if ((textureComplete == 0) || (unitObjectValue = boundTexture, *(char *)(boundTexture + 0x3d) == '\0')) {
                  unitObjectValue = 0;
                }
              }
              uVar26 = *(uint *)(ctx + GLD_pendingTextureMask) & ~(1 << (uVar24 & 0x3f));
              *(uint *)(ctx + GLD_pendingTextureMask) = uVar26;
              *(uint *)(ctx + GLD_pendingTextureMask) =
                   uVar26 | (uint)*(byte *)(boundTexture + 0x44) << (uVar24 & 0x3f);
            }
            else {
              unitObjectValue = 0;
              *(uint *)(ctx + GLD_pendingTextureMask) = *(uint *)(ctx + GLD_pendingTextureMask) & ~(1 << (uVar24 & 0x3f));
            }
            *(uint *)(iVar8 + 0x18c) = unitObjectValue;
          }
          unitBitsLeft = unitBitsLeft >> 1;
          uVar15 = uVar9 << 0x1c;
          uVar9 = uVar9 >> 4;
          uVar24 = uVar24 + 1;
          uVar22 = uVar15 | uVar22 >> 4;
          unitRowOffset = unitRowOffset + 0x14;
          iVar8 = iVar8 + 4;
        } while (unitBitsLeft != 0);
      }
      fpPassThrough1 = (double)FUN_000a7ee0(ctx,unitMask);
      pendingTextureMask = *(uint *)(ctx + GLD_pendingTextureMask);
      if (pendingTextureMask != 0) {
        iVar8 = 0;
        do {
          targetOffset = 0;
          targetsLeft = 5;
          do {
            if ((pendingTextureMask & 1) != 0) {
              *(undefined1 *)(*(int *)(iVar8 + targetOffset + *(int *)(ctx + GLD_engineObjects)) + 0x44) = 0;
              pendingTextureMask = *(uint *)(ctx + GLD_pendingTextureMask);
            }
            targetOffset = targetOffset + 4;
            targetsLeft = targetsLeft + -1;
          } while (targetsLeft != 0);
          pendingTextureMask = pendingTextureMask >> 1;
          iVar8 = iVar8 + 0x14;
          *(uint *)(ctx + GLD_pendingTextureMask) = pendingTextureMask;
        } while (pendingTextureMask != 0);
        goto LAB_00022cbc;
      }
      uVar9 = dirtyBits[3];
      noUnitUpdate = true;
      framebufferObj = r4Out1;
    }
    dirtyWord3Ptr = dirtyBits + 3;
    mutexHeld = !noUnitUpdate;
    if ((uVar9 & 0x5400000) != 0) {
      if ((*(int *)(*(int *)(ctx + GLD_engineObjects) + 0x198) != 0) ||
         (bVar27 = false, *(int *)(*(int *)(ctx + GLD_engineObjects) + 0x18c) != 0)) {
        bVar27 = true;
      }
      mutexHeld = noUnitUpdate;
      if (!mutexHeld) {
        _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
      }
      mutexHeld = mutexHeld && !noUnitUpdate;
      fpPassThrough1 = (double)FUN_000095e0(ctx);
      iVar8 = *(int *)(ctx + GLD_currentProgram);
      if (bVar27 != (iVar8 != 0)) {
        *(undefined1 *)(ctx + 0x26bd) = 1;
        iVar8 = *(int *)(ctx + GLD_currentProgram);
      }
      if (iVar8 == 0) {
        *(undefined4 *)(ctx + 0x29e8) = 0;
      }
      framebufferObj = r4Out2;
      if ((*(int *)(ctx + 0x1d0) == 0) &&
         (*(undefined4 *)(ctx + 0x29ec) = 0, programActive != '\0')) {
        result = 0;
        *(undefined1 *)(ctx + 0x2a69) = 1;
        *dirtyWord3Ptr = *dirtyWord3Ptr | 0x10000000;
        *(undefined4 *)(ctx + 0x29e8) = 0;
        *(undefined4 *)(ctx + GLD_currentProgram) = 0;
      }
    }
    dirtyWord3 = *dirtyWord3Ptr;
    if ((dirtyWord3 & 0x4500000) != 0) {
      if (mutexHeld) {
        _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
        mutexHeld = false;
      }
      fpPassThrough1 = (double)FUN_0000b750(ctx);
      dirtyWord3 = *dirtyWord3Ptr;
      framebufferObj = r4Out3;
    }
    dirtyWord1 = *dirtyWord1Ptr;
    dirtyWord0 = *dirtyBits;
    uVar24 = *(uint *)(ctx + GLD_pendingDirty3);
    dirtyWord4 = dirtyBits[4];
    dirtyWord2 = dirtyBits[2] | *(uint *)(ctx + GLD_pendingDirty2);
    uVar26 = dirtyWord3 | uVar24;
    uVar9 = dirtyWord1;
    if (((dirtyWord2 != 0 || (dirtyWord0 != 0 || dirtyWord1 != 0)) || dirtyWord4 != 0) || (uVar26 & 0xffefffff) != 0
       ) {
      dirtyBits[2] = dirtyWord2;
      *dirtyWord3Ptr = uVar26;
      ((void (*)())FUN_000a9ac0)(ctx + GLD_commandStream,dirtyBits,dirtyBitsArg,scratchR6,dirtyWord3,dirtyWord1,uVar24,dirtyWord4,fpPassThrough1,
                   fpPassThrough2,fpPassThrough3,fpPassThrough4,fpPassThrough5,fpPassThrough6,fpPassThrough7,fpPassThrough8,staleStackArg_ffffff78,
                   staleStackArg_ffffff80,staleStackArg_ffffff88,staleStackArg_ffffff90,staleStackArg_ffffff98);
      framebufferObj = r4Out4;
    }
    if ((uVar26 & 0x10000000) != *(uint *)(ctx + GLD_lastDirtyBit28) ||
        (uVar26 != 0 || ((dirtyWord2 != 0 || (dirtyWord0 != 0 || dirtyWord1 != 0)) || dirtyWord4 != 0))) {
      FUN_0002c230(ctx + GLD_commandStream,dirtyBits);
      framebufferObj = r4Out5;
    }
    puVar7 = PTR_FUN_001e8980;
    puVar6 = PTR__gldFlush_001e897c;
    puVar5 = PTR__gldFinish_001e8978;
    puVar4 = PTR_FUN_001e8938;
    if ((*(uint *)(GLD_updateFlags + ctx) & 2) != 0) {
      result = result | 2;
    }
    if ((*dirtyBits & 0x80) != 0) {
      if (*(int *)(ctx + GLD_boundFramebuffer) == 0) {
        renderFlags = *(uint *)(ctx + GLD_renderFlags);
        if ((renderFlags & 0x20) == 0) {
          if ((renderFlags & 0x400) == 0) {
            *(code **)(dispatch + 0x60) = noop_22280;
          }
          else {
            *(undefined **)(dispatch + 0x60) = PTR_FUN_001e8934;
          }
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(dispatch + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(dispatch + 0x5c) = puVar4;
        }
        else if ((renderFlags & 0x400) == 0) {
          *(undefined **)(dispatch + 0x60) = PTR_FUN_001e8938;
          *(undefined **)(dispatch + 0x58) = puVar7;
          *(undefined **)(dispatch + 0x5c) = puVar4;
        }
        else if ((renderFlags & 0x800) == 0) {
          *(undefined **)(dispatch + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(dispatch + 0x5c) = puVar6;
          *(undefined **)(dispatch + 0x60) = PTR_FUN_001e8934;
        }
        else if (*(int *)(ctx + 0x26a0) == 0) {
          ((int (*)())FUN_0001a9d0)(ctx,framebufferObj,dirtyBitsArg,scratchR6,dirtyWord3,uVar9,renderFlags & 0x800);
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(dispatch + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(dispatch + 0x5c) = puVar4;
          *(undefined **)(dispatch + 0x60) = PTR_FUN_001e8948;
        }
        else {
          *(undefined **)(dispatch + 0x58) = PTR_FUN_001e8980;
          *(undefined **)(dispatch + 0x5c) = puVar4;
          *(undefined **)(dispatch + 0x60) = PTR_FUN_001e8948;
        }
      }
      else {
        *(code **)(dispatch + 0x60) = noop_22280;
        *(undefined **)(dispatch + 0x58) = puVar5;
        *(undefined **)(dispatch + 0x5c) = PTR__gldFlush_001e897c;
      }
    }
    puVar5 = PTR_FUN_001e8910;
    puVar4 = PTR_FUN_001e88ec;
    if ((*(char *)(ctx + 0x20) == '\0') || (*(int *)(ctx + GLD_currentProgram) == 0)) {
      *(undefined **)(dispatch + 0x18) = PTR_FUN_001e8944;
      *(undefined **)(dispatch + 0x1c) = puVar5;
      puVar4 = PTR_FUN_001e88d4;
      *(undefined **)(dispatch + 0x24) = PTR_FUN_001e891c;
      *(undefined **)(dispatch + 0x20) = puVar4;
      puVar4 = PTR_FUN_001e88e0;
      *(undefined **)(dispatch + 0x2c) = PTR_FUN_001e8940;
      *(undefined **)(dispatch + 0x34) = puVar4;
      puVar4 = PTR_FUN_001e88e4;
      *(undefined **)(dispatch + 0x30) = PTR_FUN_001e894c;
      *(undefined **)(dispatch + 0x38) = puVar4;
      puVar4 = PTR_FUN_001e8914;
      *(undefined **)(dispatch + 0x3c) = PTR_FUN_001e893c;
      *(undefined **)(dispatch + 0x28) = puVar4;
      puVar4 = PTR_FUN_001e8990;
      if (*(char *)(ctx + 0x20) == '\0') {
        *(undefined **)(dispatch + 0x40) = PTR_FUN_001e88f8;
        *(undefined **)(dispatch + 0x44) = puVar4;
        *(undefined **)(dispatch + 0x48) = PTR_FUN_001e895c;
      }
      else {
        *(code **)(dispatch + 0x48) = noop_22280;
        *(code **)(dispatch + 0x40) = noop_22280;
        *(code **)(dispatch + 0x44) = noop_22280;
      }
    }
    else {
      *(undefined **)(dispatch + 0x18) = PTR_FUN_001e8918;
      *(undefined **)(dispatch + 0x1c) = puVar4;
      puVar4 = PTR_FUN_001e8954;
      *(undefined **)(dispatch + 0x24) = PTR_FUN_001e8908;
      *(undefined **)(dispatch + 0x28) = puVar4;
      puVar4 = PTR_FUN_001e88f4;
      *(undefined **)(dispatch + 0x20) = PTR_FUN_001e8930;
      *(undefined **)(dispatch + 0x2c) = puVar4;
      puVar4 = PTR_FUN_001e8924;
      *(undefined **)(dispatch + 0x34) = PTR_FUN_001e8960;
      *(undefined **)(dispatch + 0x30) = puVar4;
      puVar4 = PTR_FUN_001e8968;
      *(undefined **)(dispatch + 0x38) = PTR_FUN_001e892c;
      *(undefined **)(dispatch + 0x3c) = puVar4;
    }
    uVar20 = *(uint *)(GLD_updateFlags + ctx);
    *(uint *)(ctx + GLD_lastDirtyBit28) = uVar26 & 0x10000000;
    ((unsigned char *)0x00002b7d)[ctx] = 0;
    *(undefined1 *)(ctx + 0x26bd) = 0;
    *(undefined1 *)(ctx + 0x2a43) = 0;
    *(undefined1 *)(ctx + 0x2675) = 0;
    *(uint *)(GLD_updateFlags + ctx) = uVar20 & 0xfffffff9;
    if ((*(int *)(ctx + GLD_boundFramebuffer) != 0) &&
       (iVar8 = *(int *)(*(int *)(*(int *)(ctx + GLD_boundFramebuffer) + 4) + 0x10), iVar8 != 0)) {
      *(undefined1 *)(iVar8 + 200) = 1;
    }
    if (!mutexHeld) {
      _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    }
    if (*(char *)(ctx + 0x20) != '\0') {
      result = result | 1;
    }
  }
  else {
    attachFormat = *(byte *)(iVar8 + 0x38);
    if (((((unsigned char *)0x00002d84)[*(int *)(ctx + GLD_engineState)] == '\0') ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)attachFormat * 0x24 + 0x18) & 0x4000) != 0)) &&
       ((((unsigned char *)0x00002e0a)[*(int *)(ctx + GLD_engineState)] == '\0' ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)attachFormat * 0x24 + 0x18) & 0x8000) != 0))))
    goto LAB_00022438;
LAB_00022cbc:
    result = 0;
  }
  return result;
}

/* _gldInitDispatch @ 0x22ce0 (456 bytes) */
int _gldInitDispatch(ctx, dispatch, savedState, updateArg3, updateArg4)
  int ctx;
  undefined4 *dispatch;
  undefined4 *savedState;
  undefined4 updateArg3;
  undefined4 updateArg4;
{
  bool moreUnits;
  undefined *entry;
  undefined *altEntry;
  undefined4 word0;
  undefined4 word1;
  undefined4 word2;
  int unit;
  double staleFprArg1;
  double staleFpr2;
  double staleFpr3;
  double staleFpr4;
  double staleFpr5;
  double staleFpr6;
  double staleFpr7;
  double staleFpr8;
  double staleStackArg_ffffff98;
  double staleStackArg_ffffffa0;
  double staleStackArg_ffffffa8;
  double staleStackArg_ffffffb0;
  double staleStackArg_ffffffb8;
  undefined4 defaultState0;
  undefined4 defaultState1;
  undefined4 defaultState2;
  undefined4 defaultState3;
  undefined4 defaultState4;
  
  unit = 0;
  word1 = *(undefined4 *)(ctx + GLD_drawableHeight);
  word0 = *(undefined4 *)(ctx + GLD_drawableWidth);
  word2 = *(undefined4 *)(ctx + 0x110);
  savedState[2] = *(undefined4 *)(ctx + 0x10c);
  savedState[1] = word1;
  *savedState = word0;
  savedState[3] = word2;
  word0 = DAT_001aa4c0;
  defaultState0 = DAT_001aa4b0;
  defaultState1 = DAT_001aa4b4;
  defaultState2 = DAT_001aa4b8;
  word1 = *(undefined4 *)(ctx + 0x118);
  defaultState3 = DAT_001aa4bc;
  defaultState4 = DAT_001aa4c0;
  savedState[4] = *(undefined4 *)(ctx + 0x114);
  savedState[5] = word1;
  *(undefined4 **)(ctx + GLD_dispatchTable) = dispatch;
  do {
    staleFprArg1 = (double)FUN_000a82c0(ctx,unit);
    entry = PTR_FUN_001e8950;
    moreUnits = unit != 0xf;
    unit = unit + 1;
  } while (moreUnits);
  dispatch[5] = PTR_FUN_001e88dc;
  *dispatch = entry;
  entry = PTR_FUN_001e898c;
  dispatch[4] = PTR_FUN_001e8988;
  dispatch[2] = entry;
  entry = PTR_FUN_001e8958;
  dispatch[3] = PTR_FUN_001e8900;
  dispatch[1] = entry;
  entry = PTR_FUN_001e890c;
  dispatch[0x19] = PTR_FUN_001e8964;
  dispatch[0x1d] = entry;
  entry = PTR_FUN_001e88f0;
  dispatch[0x1e] = PTR_FUN_001e88fc;
  dispatch[0x1f] = entry;
  altEntry = PTR_FUN_001e8970;
  entry = PTR_FUN_001e8920;
  if (((unsigned char *)0x00002b82)[ctx] == '\0') {
    dispatch[0x14] = PTR_FUN_001e88e8;
    dispatch[0x15] = entry;
  }
  else {
    dispatch[0x14] = PTR_FUN_001e8974;
    dispatch[0x15] = altEntry;
  }
  entry = PTR_FUN_001e8928;
  dispatch[0x1c] = PTR_FUN_001e8984;
  dispatch[0x13] = entry;
  entry = PTR_LAB_001e8904;
  dispatch[0x1a] = PTR_FUN_001e896c;
  dispatch[0x1b] = entry;
  dispatch[0x20] = PTR_FUN_001e88d8;
  return ((uint (*)())_gldUpdateDispatch)(ctx,dispatch,&defaultState0,updateArg3,updateArg4,word0,staleFprArg1,staleFpr2,staleFpr3,staleFpr4,
                     staleFpr5,staleFpr6,staleFpr7,staleFpr8,staleStackArg_ffffff98,staleStackArg_ffffffa0,staleStackArg_ffffffa8,
                     staleStackArg_ffffffb0,staleStackArg_ffffffb8);
}

/* FUN_00022eb0 @ 0x22eb0 (536 bytes) */
int FUN_00022eb0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x240;
  FUN_000a5ec0(iVar4);
  bVar1 = param_2 == (undefined4 *)0x0;
  if (bVar1) {
    param_2 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar4,0x23);
    *(undefined4 **)(param_1 + 0x298c) = param_2;
  }
  uVar2 = *(uint *)(param_1 + 0x1b70);
  if ((uVar2 & 0x100) != 0) {
    *param_2 = ((unsigned char *)0x00001393U);
    param_2[1] = 10;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x2000000) != 0) {
    *param_2 = ((unsigned char *)0x000013c6U);
    param_2[1] = 3;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x200) != 0) {
    *param_2 = ((unsigned char *)0x000012f5U);
    param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x80000) != 0) {
    *param_2 = ((unsigned char *)0x00001008U);
    uVar3 = *(undefined4 *)(param_1 + 0x1ca0);
    param_2[2] = ((unsigned char *)0x00001004U);
    param_2[1] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1ca8);
    param_2[4] = ((unsigned char *)0x00001005U);
    param_2[3] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1cac);
    param_2[6] = ((unsigned char *)0x000010faU);
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(param_1 + 0x1da0);
    param_2 = param_2 + 8;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x10000000) != 0) {
    *param_2 = 0x413de;
    param_2[1] = *(undefined4 *)(param_1 + 0x25a0);
    param_2[2] = *(undefined4 *)(param_1 + 0x25a4);
    param_2[3] = *(undefined4 *)(param_1 + 0x25a8);
    param_2[4] = *(undefined4 *)(param_1 + 0x25ac);
    uVar3 = *(undefined4 *)(param_1 + 0x25b0);
    param_2[6] = 0x313e9;
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(param_1 + 0x25b4);
    param_2[8] = *(undefined4 *)(param_1 + 0x25b8);
    param_2[9] = *(undefined4 *)(param_1 + 0x25bc);
    param_2[10] = *(undefined4 *)(param_1 + 0x25c0);
    param_2 = param_2 + 0xb;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x20000000) != 0) {
    *param_2 = ((unsigned char *)0x000813adU);
    param_2[1] = *(undefined4 *)(param_1 + 0x25c4);
    param_2[2] = *(undefined4 *)(param_1 + 0x25c8);
    param_2[3] = *(undefined4 *)(param_1 + 0x25cc);
    param_2[4] = *(undefined4 *)(param_1 + 0x25d0);
    param_2[5] = *(undefined4 *)(param_1 + 0x25d4);
    param_2[6] = *(undefined4 *)(param_1 + 0x25d8);
    param_2[7] = *(undefined4 *)(param_1 + 0x25dc);
    param_2[8] = *(undefined4 *)(param_1 + 0x25e0);
    param_2[9] = *(undefined4 *)(param_1 + 0x25e4);
    param_2 = param_2 + 10;
  }
  if (bVar1) {
    *(undefined4 **)(param_1 + 0x298c) = param_2;
    (**(code **)(param_1 + 0x299c))(iVar4,param_2);
  }
  return param_2;
}

/* FUN_000230d0 @ 0x230d0 (1544 bytes) */
int FUN_000230d0(ctx, param_2, readSurfaceCode, param_4, param_5, param_6, param_7, param_8)
  int ctx;
  undefined4 *param_2;
  undefined4 readSurfaceCode;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  uint rb3d_blendcntl;
  uint fg_alpha_func;
  undefined4 ga_point_size;
  undefined4 sc_scissor1;
  undefined4 rb3d_ropcntl;
  undefined4 rb3d_color_channel_mask;
  undefined4 tx_format2;
  undefined4 tx_format1;
  undefined4 tx_format0;
  undefined4 tx_filter0;
  undefined4 rs_ip_0;
  undefined4 rs_count;
  undefined4 us_out_fmt_3;
  undefined4 us_out_fmt_2;
  undefined4 us_out_fmt_1;
  undefined4 us_out_fmt_0;
  undefined4 gb_ps3_enable;
  undefined4 tx_enable;
  undefined4 ga_color_control;
  undefined4 ga_poly_mode;
  undefined4 zb_cntl;
  undefined4 vap_out_vtx_fmt_0;
  undefined4 gb_enable;
  undefined4 rb3d_dither_ctl;
  undefined4 su_cull_mode;
  undefined4 vap_vte_cntl;
  undefined4 vap_clip_cntl;
  undefined4 vap_cntl_status;
  undefined4 zb_zstencilcntl;
  undefined4 zb_bw_cntl;
  undefined4 gb_aa_config;
  undefined4 gb_mspos1;
  undefined4 sc_screendoor;
  undefined4 sc_edgerule;
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint fg_fog_blend;
  int iVar7;
  
  iVar7 = ctx + 0x240;
  if (*(char *)(ctx + 0x2a5e) != '\0') {
    if ((*(int *)(ctx + 0x154) < 0) || (param_4 == 0)) {
      param_4 = 0;
    }
    else {
      *(undefined1 *)(ctx + 0x2a5e) = 0;
    }
    bVar1 = param_2 == (undefined4 *)0x0;
    puVar5 = param_2;
    if (bVar1) {
      puVar5 = (undefined4 *)(**(code **)(ctx + 0x2998))(iVar7,500);
      *(undefined4 **)(ctx + 0x298c) = puVar5;
    }
    puVar3 = *(uint **)(ctx + 0x1d8);
    *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(ctx + 0x1d8) = puVar5;
    puVar5[2] = readSurfaceCode;
    *puVar5 = 0x30000000;
    puVar5[1] = 0xfa;
    puVar5[3] = param_4;
    puVar5[4] = param_5;
    if (((unsigned char *)0x00002b7c)[ctx] != '\0') {
      param_6 = (*(int *)(ctx + 0x160) - param_8) - param_6;
    }
    puVar5[5] = param_6;
    puVar5[6] = param_7;
    puVar5[7] = param_8;
    puVar3 = *(uint **)(ctx + 0x1d8);
    *puVar3 = (int)(puVar5 + 0xfa) - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(ctx + 0x1d8) = puVar5 + 0xfa;
    puVar5[0xfb] = 0;
    puVar5[0xfa] = 0x33000000;
    puVar5[0xfc] = ((unsigned char *)0x00001393U);
    puVar5[0xfd] = 10;
    puVar5[0xfe] = ((unsigned char *)0x000013c6U);
    puVar5[0xff] = 3;
    puVar5[0x100] = 0x5c8;
    puVar5[0x101] = 0x20000;
    puVar5[0x102] = ((unsigned char *)0x000010eaU);
    sc_edgerule = *(undefined4 *)(ctx + 0x1cfc);
    puVar5[0x104] = ((unsigned char *)0x000010faU);
    puVar5[0x103] = sc_edgerule;
    sc_screendoor = *(undefined4 *)(ctx + 0x1da0);
    puVar5[0x106] = 0xc0001000;
    puVar5[0x108] = 0x11004;
    puVar5[0x105] = sc_screendoor;
    puVar5[0x109] = *(undefined4 *)(ctx + 0x1ca8);
    gb_mspos1 = *(undefined4 *)(ctx + 0x1cac);
    puVar5[0x10b] = ((unsigned char *)0x00001008U);
    puVar5[0x10a] = gb_mspos1;
    gb_aa_config = *(undefined4 *)(ctx + 0x1ca0);
    puVar5[0x10d] = ((unsigned char *)0x000010e9U);
    puVar5[0x10c] = gb_aa_config;
    puVar5[0x10e] = *(undefined4 *)(ctx + 0x1d20);
    puVar5[0x10f] = ((unsigned char *)0x000013c7U);
    zb_bw_cntl = *(undefined4 *)(ctx + 0x1cf0);
    puVar5[0x111] = ((unsigned char *)0x000013c1U);
    puVar5[0x110] = zb_bw_cntl;
    zb_zstencilcntl = *(undefined4 *)(ctx + 0x1ce4);
    puVar5[0x113] = 0x850;
    puVar5[0x112] = zb_zstencilcntl;
    vap_cntl_status = *(undefined4 *)(ctx + 0x1dc0);
    puVar5[0x115] = 0x887;
    puVar5[0x114] = vap_cntl_status;
    vap_clip_cntl = *(undefined4 *)(ctx + 0x1db4);
    puVar5[0x1b7] = 0x82c;
    puVar5[0x116] = vap_clip_cntl;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    puVar5[0x117] = ((unsigned char *)0x000010aeU);
    puVar5[0x1b8] = vap_vte_cntl;
    su_cull_mode = *(undefined4 *)(ctx + 0x1d70);
    puVar5[0x119] = ((unsigned char *)0x00001394U);
    puVar5[0x118] = su_cull_mode;
    rb3d_dither_ctl = *(undefined4 *)(ctx + 0x1d30);
    puVar5[0x11b] = ((unsigned char *)0x00001380U);
    puVar5[0x11d] = ((unsigned char *)0x00001002U);
    puVar5[0x11c] = 0;
    puVar5[0x11a] = rb3d_dither_ctl;
    puVar5[0x11e] = *(undefined4 *)(ctx + 0x1d90);
    gb_enable = *(undefined4 *)(ctx + 0x1d90);
    puVar5[0x11f] = 0x824;
    puVar5[0x11e] = gb_enable;
    vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + 0x1ddc);
    puVar5[0x121] = 0x825;
    puVar5[0x120] = vap_out_vtx_fmt_0;
    puVar5[0x122] = *(undefined4 *)(ctx + 0x1de0);
    puVar5[0x123] = 0x82d;
    puVar2 = PTR_DAT_001e88c8;
    uVar4 = *(undefined4 *)(0x000026c8 + ctx + 4);
    puVar5[0x125] = 0x854;
    puVar5[0x124] = uVar4;
    uVar4 = **(undefined4 **)(ctx + 0x2680);
    puVar5[0x127] = 0x878;
    puVar5[0x126] = uVar4;
    uVar4 = **(undefined4 **)(ctx + 0x2684);
    puVar5[0x129] = ((unsigned char *)0x000013c0U);
    puVar5[0x128] = uVar4;
    zb_cntl = *(undefined4 *)(ctx + 0x1ce0);
    puVar5[299] = ((unsigned char *)0x000012f0U);
    puVar5[0x12a] = zb_cntl;
    fg_fog_blend = *(uint *)(ctx + 0x1d2c);
    puVar5[300] = fg_fog_blend;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[300] = fg_fog_blend & 0xfffffffe;
    }
    puVar5[0x12d] = ((unsigned char *)0x000012f5U);
    fg_alpha_func = *(uint *)(ctx + 0x1c8c);
    puVar5[0x12e] = fg_alpha_func;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[0x12e] = fg_alpha_func & 0xfffff7ff;
    }
    puVar5[0x12f] = ((unsigned char *)0x000010a2U);
    ga_poly_mode = *(undefined4 *)(ctx + 0x1d7c);
    puVar5[0x131] = ((unsigned char *)0x00001381U);
    puVar5[0x130] = ga_poly_mode;
    rb3d_blendcntl = *(uint *)(ctx + 0x1cc0);
    puVar5[0x132] = rb3d_blendcntl;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x4000) == 0) {
      puVar5[0x132] = rb3d_blendcntl & 0xfffffffc;
    }
    puVar5[0x133] = ((unsigned char *)0x0000109eU);
    param_2 = puVar5 + 0x1b9;
    uVar4 = *(undefined4 *)(ctx + 0x1d6c);
    puVar5[0x135] = ((unsigned char *)0x00001096U);
    puVar5[0x134] = uVar4;
    ga_color_control = *(undefined4 *)(ctx + 0x1df8);
    puVar5[0x137] = ((unsigned char *)0x00001041U);
    puVar5[0x134] = ga_color_control;
    tx_enable = *(undefined4 *)(ctx + 0x29f0);
    puVar5[0x139] = ((unsigned char *)0x00001046U);
    puVar5[0x138] = tx_enable;
    gb_ps3_enable = *(undefined4 *)(ctx + 0x1dfc);
    puVar5[0x13b] = ((unsigned char *)0x00001094U);
    puVar5[0x153] = ((unsigned char *)0x00001095U);
    puVar5[0x13d] = ((unsigned char *)0x00001095U);
    puVar5[0x179] = ((unsigned char *)0x00001180U);
    puVar5[0x13f] = ((unsigned char *)0x00001095U);
    puVar5[0x141] = ((unsigned char *)0x00001095U);
    puVar5[0x143] = ((unsigned char *)0x00001095U);
    puVar5[0x13a] = gb_ps3_enable;
    puVar5[0x145] = ((unsigned char *)0x00001095U);
    puVar5[0x147] = ((unsigned char *)0x00001095U);
    puVar5[0x149] = ((unsigned char *)0x00001095U);
    puVar5[0x14b] = ((unsigned char *)0x00001095U);
    puVar5[0x14d] = ((unsigned char *)0x00001095U);
    puVar5[0x14f] = ((unsigned char *)0x00001095U);
    puVar5[0x151] = ((unsigned char *)0x00001095U);
    puVar5[0x155] = 0xc0221000;
    puVar5[0x13c] = 0;
    puVar5[0x17a] = 2;
    puVar5[0x17b] = ((unsigned char *)0x00001189U);
    puVar5[0x17d] = ((unsigned char *)0x00001181U);
    puVar5[0x17f] = ((unsigned char *)0x0000118dU);
    puVar5[0x181] = ((unsigned char *)0x0000118eU);
    puVar5[0x183] = ((unsigned char *)0x0000118cU);
    puVar5[0x185] = ((unsigned char *)0x000011a9U);
    us_out_fmt_0 = *(undefined4 *)(ctx + 0x257c);
    puVar5[0x187] = ((unsigned char *)0x000011aaU);
    puVar5[0x186] = us_out_fmt_0;
    us_out_fmt_1 = *(undefined4 *)(ctx + 0x2580);
    puVar5[0x189] = ((unsigned char *)0x000011abU);
    puVar5[0x188] = us_out_fmt_1;
    us_out_fmt_2 = *(undefined4 *)(ctx + 0x2584);
    puVar5[0x18b] = ((unsigned char *)0x000011acU);
    puVar5[0x18a] = us_out_fmt_2;
    us_out_fmt_3 = *(undefined4 *)(ctx + 0x2588);
    puVar5[0x18d] = ((unsigned char *)0x000010c0U);
    puVar5[0x18c] = us_out_fmt_3;
    rs_count = *(undefined4 *)(ctx + 0x216c);
    puVar5[399] = ((unsigned char *)0x000010c1U);
    puVar5[0x191] = ((unsigned char *)0x000010c8U);
    puVar5[0x193] = ((unsigned char *)0x0000101dU);
    puVar5[0x18e] = rs_count;
    rs_ip_0 = *(undefined4 *)(ctx + 0x2128);
    puVar5[0x195] = ((unsigned char *)0x0000138aU);
    puVar5[0x197] = ((unsigned char *)0x0000138eU);
    puVar5[0x19c] = 0;
    puVar5[0x199] = ((unsigned char *)0x00001040U);
    puVar5[0x196] = 0;
    puVar5[0x198] = 0;
    puVar5[0x19a] = 0;
    puVar5[0x194] = rs_ip_0;
    puVar5[0x19b] = ((unsigned char *)0x00001150U);
    puVar5[0x19d] = ((unsigned char *)0x00001100U);
    tx_filter0 = *(undefined4 *)(ctx + 0x1f1c);
    puVar5[0x19f] = ((unsigned char *)0x00001110U);
    puVar5[0x19e] = tx_filter0;
    puVar5[0x1a0] = *(undefined4 *)(ctx + 0x1f5c);
    puVar5[0x1a1] = ((unsigned char *)0x00001120U);
    tx_format0 = *(undefined4 *)(ctx + 0x1f9c);
    puVar5[0x1a3] = ((unsigned char *)0x00001130U);
    puVar5[0x1a2] = tx_format0;
    tx_format1 = *(undefined4 *)(ctx + 0x1fdc);
    puVar5[0x1a5] = ((unsigned char *)0x00001140U);
    puVar5[0x1a4] = tx_format1;
    tx_format2 = *(undefined4 *)(ctx + 0x201c);
    puVar5[0x1a7] = ((unsigned char *)0x000010f4U);
    puVar5[0x1a8] = 0xaaaa;
    puVar5[0x1a9] = ((unsigned char *)0x00001383U);
    puVar5[0x1a6] = tx_format2;
    rb3d_color_channel_mask = *(undefined4 *)(ctx + 0x1d34);
    puVar5[0x1ab] = ((unsigned char *)0x00001386U);
    puVar5[0x1aa] = rb3d_color_channel_mask;
    rb3d_ropcntl = *(undefined4 *)(ctx + 0x1d38);
    puVar5[0x1ad] = 0x110f8;
    puVar5[0x1ac] = rb3d_ropcntl;
    puVar5[0x1ae] = *(undefined4 *)(ctx + 0x1d98);
    sc_scissor1 = *(undefined4 *)(ctx + 0x1d50);
    puVar5[0x1b0] = ((unsigned char *)0x00001087U);
    puVar5[0x1af] = sc_scissor1;
    ga_point_size = *(undefined4 *)(ctx + 0x1f0c);
    puVar5[0x1b2] = 0x31080;
    puVar5[0x1b1] = ga_point_size;
    puVar5[0x1b3] = *(undefined4 *)(ctx + 0x1efc);
    puVar5[0x1b4] = *(undefined4 *)(ctx + 0x1f04);
    puVar5[0x1b5] = *(undefined4 *)(ctx + 0x1f00);
    puVar5[0x1b6] = *(undefined4 *)(ctx + 0x1f08);
    FUN_0004c100(puVar5 + 0xfc,iVar7);
    if (bVar1) {
      *(undefined4 **)(ctx + 0x298c) = param_2;
      (**(code **)(ctx + 0x299c))(iVar7,param_2);
    }
  }
  return param_2;
}

/* returnSecondArgument @ 0x236f0 (8 bytes) */
int returnSecondArgument(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* gldEmitCurrentAttributeRegisters @ 0x23700 (360 bytes) */
int gldEmitCurrentAttributeRegisters(ctx, param_2, param_3)
  int ctx;
  uint *param_2;
  undefined4 *param_3;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = param_3 + 5;
  *param_3 = 0x308c8;
  param_3[1] = param_2[0xc];
  param_3[2] = param_2[0xd];
  param_3[3] = param_2[0xe];
  param_3[4] = param_2[0xf];
  if ((*(uint *)(ctx + 0x1ca0) & 8) != 0) {
    if (((unsigned char *)0x00002e0a)[*(int *)(*(int *)(ctx + 4) + 0x10)] == '\0') {
      puVar5 = param_3 + 9;
      param_3[5] = 0x208cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
    }
    else {
      puVar5 = param_3 + 10;
      param_3[5] = 0x308cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
      param_3[9] = param_2[0x13];
    }
  }
  uVar4 = 10;
  uVar2 = 0x8e8;
  iVar6 = 8;
  puVar3 = param_2;
  do {
    if ((1 << (uVar4 & 0x3f) & *(uint *)(ctx + 0x1ca0)) != 0) {
      *puVar5 = uVar2 | 0x30000;
      puVar5[1] = puVar3[0x20];
      puVar5[2] = puVar3[0x21];
      puVar5[3] = puVar3[0x22];
      puVar5[4] = puVar3[0x23];
      puVar5 = puVar5 + 5;
    }
    uVar4 = uVar4 + 1;
    uVar2 = uVar2 + 4;
    puVar3 = puVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *puVar5 = 0x917;
  bVar1 = *(byte *)(param_2 + 0x1f);
  puVar5[2] = (uint)0x000308c0;
  puVar5[1] = -(uint)bVar1 >> 0x1f;
  puVar5[3] = *param_2;
  puVar5[4] = param_2[1];
  puVar5[5] = param_2[2];
  puVar5[6] = param_2[3];
  return puVar5 + 7;
}

/* FUN_00023870 @ 0x23870 (420 bytes) */
int FUN_00023870(ctx, gb_aa_config, param_3, param_4)
  undefined4 ctx;
  uint gb_aa_config;
  int param_3;
  uint *param_4;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if ((gb_aa_config & 2) != 0) {
    *param_4 = 0x208c4;
    param_4[1] = *(uint *)(param_3 + 0x40);
    param_4[2] = *(uint *)(param_3 + 0x44);
    param_4[3] = *(uint *)(param_3 + 0x48);
    param_4 = param_4 + 4;
  }
  if ((gb_aa_config & 4) != 0) {
    *param_4 = 0x308c8;
    param_4[1] = *(uint *)(param_3 + 0x30);
    param_4[2] = *(uint *)(param_3 + 0x34);
    param_4[3] = *(uint *)(param_3 + 0x38);
    param_4[4] = *(uint *)(param_3 + 0x3c);
    param_4 = param_4 + 5;
  }
  if ((gb_aa_config & 8) != 0) {
    *param_4 = 0x208cc;
    param_4[1] = *(uint *)(param_3 + 0x50);
    param_4[2] = *(uint *)(param_3 + 0x54);
    param_4[3] = *(uint *)(param_3 + 0x58);
    param_4 = param_4 + 4;
  }
  uVar5 = 0;
  uVar4 = 0x8e8;
  iVar6 = 8;
  iVar3 = param_3;
  do {
    uVar2 = 0x400 << (uVar5 & 0x3f);
    if ((uVar2 & gb_aa_config) != 0) {
      gb_aa_config = gb_aa_config & ~uVar2;
      *param_4 = uVar4 | 0x30000;
      param_4[1] = *(uint *)(iVar3 + 0x80);
      param_4[2] = *(uint *)(iVar3 + 0x84);
      param_4[3] = *(uint *)(iVar3 + 0x88);
      param_4[4] = *(uint *)(iVar3 + 0x8c);
      param_4 = param_4 + 5;
    }
    if ((gb_aa_config & 0x3fc00) == 0) break;
    uVar5 = uVar5 + 1;
    uVar4 = uVar4 + 4;
    iVar3 = iVar3 + 0x10;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  if ((gb_aa_config & 0x40000) != 0) {
    *param_4 = 0x908;
    param_4[1] = *(uint *)(param_3 + 0x5c);
    param_4 = param_4 + 2;
  }
  if ((gb_aa_config & 0x80000) != 0) {
    *param_4 = 0x3090c;
    param_4[1] = *(uint *)(param_3 + 0x60);
    param_4[2] = *(uint *)(param_3 + 100);
    param_4[3] = *(uint *)(param_3 + 0x68);
    param_4[4] = *(uint *)(param_3 + 0x6c);
    param_4 = param_4 + 5;
  }
  *param_4 = 0x917;
  bVar1 = *(byte *)(param_3 + 0x7c);
  param_4[2] = (uint)0x000308c0;
  param_4[1] = -(uint)bVar1 >> 0x1f;
  param_4[3] = *(uint *)(param_3 + 0x20);
  param_4[4] = *(uint *)(param_3 + 0x24);
  param_4[5] = *(uint *)(param_3 + 0x28);
  param_4[6] = *(uint *)(param_3 + 0x2c);
  return param_4 + 7;
}

/* hidden-argument defect of gld_emitPrimitiveVertices (found auditing #70/#77): real callers (the
 * gldPrimWrapperTriangleFan_23a24-family wrappers tail-calling in via 0x23a20) pass a real 6th
 * argument in r8, previously read there as an undeclared, uninitialised in_r8. */
/* gld_emitPrimitiveVertices @ 0x23a24 (1860 bytes) */
int gld_emitPrimitiveVertices(ctx, hwPrimType, extraVertexAttribs, vertexAttribs, vertexCount, extraArg)
  int ctx;
  int hwPrimType;
  undefined4 extraVertexAttribs;
  int vertexAttribs;
  int vertexCount;
  undefined4 extraArg;
{
  int vertexIndex;
  int currentRegBlock;
  undefined4 cursorChain;
  undefined4 connection;
  bool emitsExtraVertex;
  int packetVertexCount;
  undefined4 *packetStart;
  undefined4 *packetCursor;
  undefined4 uVar5;
  undefined4 gb_aa_config;

  emitsExtraVertex = hwPrimType == 5;
  connection = *(undefined4 *)(ctx + 4);
  gb_aa_config = *(undefined4 *)(ctx + 0x1ca0);
  packetVertexCount = vertexCount;
  if (emitsExtraVertex) {
    packetVertexCount = vertexCount + 1;
  }
  packetStart = (undefined4 *)
           (**(code **)(ctx + 0x2758))
                     (ctx,(*(int *)(ctx + 0x243c) + 1U & 0xfffffffe) +
                              packetVertexCount * *(int *)(ctx + 0x243c) * 5 + packetVertexCount * 2 + 0x16,extraVertexAttribs,
                      vertexAttribs,vertexCount,extraArg,packetVertexCount * 2);
  currentRegBlock = *(int *)(ctx + 0x2440);
  *(undefined4 **)(0x00002748 + ctx + 4) = packetStart;
  if (currentRegBlock != ctx + 0x1be4) {
    *(int *)(ctx + 0x2440) = ctx + 0x1be4;
    *(int *)(ctx + 0x2444) = ctx + 0x1c04;
    *(undefined4 *)(ctx + 0x248c) = *(undefined4 *)(ctx + 0x1ca4);
    packetStart = (undefined4 *)FUN_0002c0c0(connection,packetStart);
  }
  if (*(char *)(ctx + 0x2802) == '\0') {
    *packetStart = 0x5c8;
    packetStart[1] = 0x10000000;
    packetStart = packetStart + 2;
    *(undefined1 *)(ctx + 0x2802) = 1;
  }
  packetCursor = packetStart + 4;
  *packetStart = 0x82c;
  uVar5 = *(undefined4 *)(ctx + 0x1b84);
  packetStart[2] = 0x821;
  packetStart[3] = hwPrimType;
  packetStart[1] = uVar5;
  if (*(char *)(*(int *)(ctx + 4) + 0x20) == '\0') {
    if (emitsExtraVertex) {
      packetCursor = (undefined4 *)((int (*)())gldEmitCurrentAttributeRegisters)(ctx,extraVertexAttribs,packetCursor);
    }
    if (vertexCount == 0x24) {
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs,packetCursor);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x100,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x200,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x300,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x400,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x500,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x600,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x700,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x800,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x900,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xa00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xb00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xc00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xd00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xe00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0xf00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1000,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001100) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001200) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001300) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001400) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001500) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001600) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,((unsigned char *)0x00001700) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1800,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1900,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1a00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1b00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1c00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1d00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1e00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x1f00,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x2000,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x2100,cursorChain);
      cursorChain = ((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x2200,cursorChain);
      packetCursor = (undefined4 *)((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs + 0x2300,cursorChain);
    }
    else if (0 < vertexCount) {
      vertexIndex = 0;
      do {
        vertexIndex = vertexIndex + 1;
        packetCursor = (undefined4 *)((int (*)())gldEmitCurrentAttributeRegisters)(ctx,vertexAttribs,packetCursor);
        vertexAttribs = vertexAttribs + 0x100;
      } while (vertexCount != vertexIndex);
    }
  }
  else {
    if (emitsExtraVertex) {
      packetCursor = (undefined4 *)((int (*)())FUN_00023870)(ctx,gb_aa_config,extraVertexAttribs,packetCursor);
    }
    if (vertexCount == 0x24) {
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs,packetCursor);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x100,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x200,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x300,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x400,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x500,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x600,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x700,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x800,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x900,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xa00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xb00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xc00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xd00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xe00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0xf00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1000,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001100) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001200) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001300) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001400) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001500) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001600) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,((unsigned char *)0x00001700) + vertexAttribs,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1800,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1900,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1a00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1b00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1c00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1d00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1e00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x1f00,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x2000,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x2100,cursorChain);
      cursorChain = ((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x2200,cursorChain);
      packetCursor = (undefined4 *)((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs + 0x2300,cursorChain);
    }
    else if (0 < vertexCount) {
      vertexIndex = 0;
      do {
        vertexIndex = vertexIndex + 1;
        packetCursor = (undefined4 *)((int (*)())FUN_00023870)(ctx,gb_aa_config,vertexAttribs,packetCursor);
        vertexAttribs = vertexAttribs + 0x100;
      } while (vertexCount != vertexIndex);
    }
  }
  *packetCursor = 0x92b;
  packetCursor[3] = 0;
  packetCursor[2] = ((unsigned char *)0x00001393U);
  packetCursor[1] = 0;
  *(undefined4 **)(0x00002748 + ctx + 4) = packetCursor + 4;
  /* dropped 2nd arg, same defect class as gld_startPacket (issue #64) - stock stores the just-advanced
   * pointer to +0x274c then loads it right back into r4 before the bctr tail-jump. */
  (**(code **)(ctx + 0x275c))(ctx,packetCursor + 4);
  return;
}

/* FUN_00024190: hidden-argument defect (found auditing #70): real callers
 * (gldPrimWrapperPolygon_24190/000246f0/0002 47f0, tail-calling in via 0x24190) pass a real 5th argument
 * in r7, previously read here as an undeclared, uninitialised in_r7. in_r8 stays as-is: no real caller
 * supplies it (stock genuinely forwards whatever garbage is there). */
/* FUN_00024190 @ 0x24190 (344 bytes) */
int FUN_00024190(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  uint param_4;
  undefined4 param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 staleArgR8;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,(*(int *)(param_1 + 0x243c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x243c) * param_4 * 5 + param_4 * 2 + 0x16,param_3,
                      param_4,param_5,staleArgR8,*(code **)(param_1 + 0x2758));
  iVar1 = *(int *)(param_1 + 0x2440);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
  if (iVar1 != param_1 + 0x1be4) {
    *(int *)(param_1 + 0x2440) = param_1 + 0x1be4;
    *(int *)(param_1 + 0x2444) = param_1 + 0x1c04;
    *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x1ca4);
    puVar2 = (undefined4 *)FUN_0002c0c0(uVar5,puVar2);
  }
  if (*(char *)(param_1 + 0x2802) == '\0') {
    *puVar2 = 0x5c8;
    puVar2[1] = 0x10000000;
    puVar2 = puVar2 + 2;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  puVar3 = puVar2 + 4;
  *puVar2 = 0x82c;
  uVar5 = *(undefined4 *)(param_1 + 0x1b84);
  puVar2[2] = 0x821;
  puVar2[3] = param_2;
  puVar2[1] = uVar5;
  if (param_4 != 0) {
    uVar4 = 0;
    do {
      uVar5 = *param_3;
      uVar4 = uVar4 + 1;
      param_3 = param_3 + 1;
      puVar3 = (undefined4 *)((int (*)())gldEmitCurrentAttributeRegisters)(param_1,uVar5,puVar3);
    } while (uVar4 < param_4);
  }
  *puVar3 = 0x92b;
  puVar3[3] = 0;
  puVar3[2] = ((unsigned char *)0x00001393U);
  puVar3[1] = 0;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3 + 4;
  /* dropped 2nd arg, same defect class as gld_startPacket (issue #64) - stock stores the just-advanced
   * pointer to +0x274c then loads it right back into r4 before the bctr tail-jump. */
  (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 4);
  return;
}

/* FUN_000242f0: same duplicated-body defect as #77: the real 116-byte wrapper had been overwritten with
 * unrelated FUN_00039330-family content. Rewritten from real stock disassembly. Also corrects an earlier
 * misreading of this function's own real 7th argument (see FUN_0002cc30): no real caller here sets r9
 * either, it just forwards garbage like the rest of the dispatch-wrapper family. */
/* FUN_000242f0 @ 0x242f0 (116 bytes) */
void FUN_000242f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8)
{
  uint uVar1;
  undefined4 staleArgR9;

  uVar1 = ((uint (*)())FUN_0002cc30)(param_1,0,4,param_3,param_5,param_6,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8);
  if (uVar1 != 0) {
    return gld_emitPrimitiveVertices(param_1 + 0x240,4,0,param_2,uVar1,param_4);
  }
  return;
}

/* FUN_00024370: same duplicated-body defect as #77 (this file's copy of the bug: the real 112-byte wrapper
 * had been overwritten with unrelated FUN_00039330-family content). Rewritten from real stock disassembly,
 * same as the part_004.c siblings. */
/* FUN_00024370 @ 0x24370 (112 bytes) */
void FUN_00024370(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint uVar1;
  undefined4 staleArgR9;

  uVar1 = ((uint (*)())FUN_0002cc30)(param_1,0,5,param_3,param_5,param_6,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (uVar1 != 0) {
    return gld_emitPrimitiveVertices(param_1 + 0x240,6,0,param_2,uVar1,param_4);
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl glFlush_impl");
asm(".set glFlush_impl, _glFlush_impl");
asm(".globl glFlush_impl_withSurfaceUpdate");
asm(".set glFlush_impl_withSurfaceUpdate, _glFlush_impl_withSurfaceUpdate");
asm(".globl gld_signalFence");
asm(".set gld_signalFence, _gld_signalFence");
asm(".globl glFinish_impl");
asm(".set glFinish_impl, _glFinish_impl");
asm(".globl FUN_0001a9d0");
asm(".set FUN_0001a9d0, _FUN_0001a9d0");
asm(".globl returnZero_1e270");
asm(".set returnZero_1e270, _returnZero_1e270");
asm(".globl gld_drawVertexArray");
asm(".set gld_drawVertexArray, _gld_drawVertexArray");
asm(".globl FUN_00020330");
asm(".set FUN_00020330, _FUN_00020330");
asm(".globl gldDisplayNotificationCallback");
asm(".set gldDisplayNotificationCallback, _gldDisplayNotificationCallback");
asm(".globl FUN_000242f0");
asm(".set FUN_000242f0, _FUN_000242f0");
asm(".globl FUN_00024370");
asm(".set FUN_00024370, _FUN_00024370");
