#include "decls.h"

/* _gldDestroyShared @ 0x6f40 (76 bytes) */
int _gldDestroyShared(shared)
  int shared;
{
  undefined4 returnCode;
  
  returnCode = 0x2714;
  if (shared != 0) {
    noop_24fc0();
    _pthread_mutex_destroy(shared);
    _free(shared);
    returnCode = 0;
  }
  return returnCode;
}

/* _gldReclaimContext @ 0x6f90 (128 bytes) */
int _gldReclaimContext(ctx)
  int ctx;
{
  int status;
  
  gld_submitRingIfNeeded(ctx);
  status = _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0x11,0,0,0,0);
  if (status != 0) {
    _free(ctx);
    return;
  }
  *(undefined4 *)(ctx + GLD_dataRefillCount) = 0;
  *(undefined4 *)(ctx + GLD_dataBase) = 0;
  *(undefined4 *)(ctx + GLD_dataBufferId) = 0;
  *(undefined4 *)(ctx + GLD_dataCursor) = 0;
  *(undefined4 *)(ctx + GLD_dataLimit) = 0;
  return;
}

/* gld_detachDrawable @ 0x7020 (164 bytes) */
int gld_detachDrawable(ctx)
  int *ctx;
{
  char connectionUseCount;
  undefined *rendererLibrary;
  
  if ((ctx[GLD_attachedDrawable / 4] != 0) &&
     (ctx[GLD_attachedDrawable / 4] = 0, rendererLibrary = PTR_DAT_001e88ac, (ctx[GLD_drawableFlags / 4] & 0x20U) == 0)) {
    connectionUseCount = PTR_DAT_001e88ac[*ctx + 0x98];
    PTR_DAT_001e88ac[*ctx + 0x98] = connectionUseCount + -1;
    if ((char)(connectionUseCount + -1) == '\0') {
      _IOServiceClose(*(undefined4 *)(rendererLibrary + *ctx * 4 + 0x18));
      *(undefined4 *)(rendererLibrary + *ctx * 4 + 0x18) = 0;
    }
  }
  return;
}

/* _gldAttachDrawable @ 0x70d0 (1804 bytes) */
int _gldAttachDrawable(ctx, drawableType, drawable, drawableIds)
  int *ctx;
  int drawableType;
  int *drawable;
  uint drawableIds;
{
  ushort rectField9c;
  undefined *library;
  code *attachCallback;
  int status;
  int rendererIndex;
  int *pbufferArg;
  uint ctxFlags;
  int ownRendererIndex;
  int serviceList;
  uint drawableHigh;
  undefined4 returnCode;
  undefined4 outCount;
  int callWords [3];
  uint scalarIn0;
  uint scalarIn1;
  uint scalarIn2;
  uint scalarIn3;
  uint drawableWidth;
  int drawableHeight;
  int drawableExtra0;
  int drawableExtra1;
  
  if (ctx == (int *)0x0) {
    return 0x271e;
  }
  drawableHigh = drawableIds >> 8 & 0xff;
  if ((drawableType == 0x50) || (drawableType == 0x5a)) {
    if (drawable == (int *)0x0) {
      return 0x2715;
    }
    ctx[GLD_drawableFlags / 4] = ctx[GLD_drawableFlags / 4] | 0x20;
    pbufferArg = drawable;
    if (drawableType != 0x5a) {
      pbufferArg = (int *)0x0;
    }
    gld_applyPbufferToRenderFlags(ctx,ctx + GLD_drawableFlags / 4,pbufferArg);
    callWords[0] = drawable[2];
    callWords[1] = 3;
    status = _io_connect_method_scalarI_scalarO(ctx[GLD_connect / 4],6,callWords,1,&drawableWidth,callWords + 1);
    if (status == 0) {
      ctxFlags = ctx[GLD_drawableFlags / 4];
      if ((drawableWidth & 0xf) != (ctxFlags & 0xf)) {
        if ((ctxFlags & 0x33c0) != 0) {
          if (ctx[GLD_boundFramebuffer / 4] != 0) {
            return 0x2715;
          }
          ctx[GLD_renderFlags / 4] = ctxFlags;
          return 0x2715;
        }
        ctxFlags = drawableWidth & 0xf | ctxFlags & 0xfffffff0;
        ctx[GLD_drawableFlags / 4] = ctxFlags;
        if (ctx[GLD_boundFramebuffer / 4] == 0) {
          ctx[GLD_renderFlags / 4] = ctxFlags;
          gld_updateColorFormatIndex(ctx);
          ctxFlags = ctx[GLD_drawableFlags / 4];
        }
      }
    }
    else {
      ctxFlags = ctx[GLD_drawableFlags / 4];
    }
    if (drawableType != 0x5a) {
      ownRendererIndex = *ctx;
      status = *drawable;
      rendererIndex = drawable[1];
      attachCallback = *(code **)(PTR_DAT_001e88ac + 0x14);
      serviceList = *(int *)(PTR_DAT_001e88ac + 8);
    }
    else {
      ownRendererIndex = *ctx;
      status = 0;
      rendererIndex = 0;
      attachCallback = *(code **)(PTR_DAT_001e88ac + 0x14);
      serviceList = *(int *)(PTR_DAT_001e88ac + 8);
    }
    status = (*attachCallback)(status,rendererIndex,drawable[2],ctxFlags & 0x803f,*(undefined4 *)(ownRendererIndex * 4 + serviceList));
    if (status == 0) {
      scalarIn0 = drawable[2];
      scalarIn1 = ctx[GLD_drawableFlags / 4] & 0xffff3fc0;
      scalarIn2 = drawableHigh;
      scalarIn3 = drawableIds & 0xff;
      status = _io_connect_method_scalarI_structureI(ctx[GLD_connect / 4],0,&scalarIn0,4,0,0);
      if ((status == 0) &&
         ((*(char *)((int)ctx + GLD_scaleEnabled) == '\0' ||
          (status = _io_connect_method_scalarI_structureI(ctx[GLD_connect / 4],0xe,ctx + GLD_scaleFlags / 4,3,0,0),
          status == 0)))) {
        scalarIn0 = (uint)*(byte *)((int)ctx + GLD_surfaceVolatile);
        _io_connect_method_scalarI_structureI(ctx[GLD_connect / 4],0x10,&scalarIn0,1,0,0);
loopSetOutCount:
        outCount = 4;
        returnCode = 0x2715;
        status = _io_connect_method_scalarI_scalarO(ctx[GLD_connect / 4],5,0,0,&drawableWidth,&outCount);
        if (status == 0) {
          outCount = 3;
          returnCode = 0x2715;
          status = _io_connect_method_scalarI_scalarO(ctx[GLD_connect / 4],3,0,0,ctx + GLD_hwConfig0 / 4,&outCount);
          if (status == 0) {
            outCount = 1;
            _io_connect_method_scalarI_scalarO(ctx[GLD_connect / 4],4,0,0,callWords + 2,&outCount);
            if ((callWords[2] & 1U) == 0) {
              returnCode = 0x2720;
              ctx[0x47] = drawableExtra0;
              ctx[0x48] = drawableExtra1;
              ctx[GLD_drawableWidth / 4] = drawableWidth;
              ctx[GLD_drawableHeight / 4] = drawableHeight;
            }
            else if (drawable == (int *)ctx[GLD_attachedDrawable / 4]) {
              if ((drawableWidth != ctx[GLD_drawableWidth / 4]) || (returnCode = 0, drawableHeight != ctx[GLD_drawableHeight / 4])) {
                ctx[0x47] = drawableExtra0;
                ctx[0x48] = drawableExtra1;
                returnCode = 3;
                ctx[GLD_drawableWidth / 4] = drawableWidth;
                ctx[GLD_drawableHeight / 4] = drawableHeight;
              }
            }
            else {
              returnCode = 2;
              ctx[0x47] = drawableExtra0;
              ctx[0x48] = drawableExtra1;
              ctx[GLD_drawableWidth / 4] = drawableWidth;
              ctx[GLD_drawableHeight / 4] = drawableHeight;
            }
            if (*(char *)((int)ctx + GLD_softwareBufferFormat) != '\0') {
              status = 4;
              if (*(char *)((int)ctx + GLD_softwareBufferFormat) != '\x01') {
                status = 8;
              }
              status = status * (drawableWidth + 7 & 0xfffffff8) * drawableHeight;
              if (status != ctx[GLD_softwareBufferSize / 4]) {
                if (ctx[GLD_softwareBuffer / 4] != 0) {
                  _free(ctx[GLD_softwareBuffer / 4]);
                }
                rendererIndex = _malloc(status);
                ctx[GLD_softwareBufferSize / 4] = status;
                ctx[GLD_softwareBuffer / 4] = rendererIndex;
              }
            }
            ((int (*)())gld_detachDrawable)(ctx);
            ctx[GLD_attachedDrawable / 4] = (int)drawable;
            ctx[GLD_drawableIdHigh / 4] = drawableHigh;
            ctx[GLD_drawableIdLow / 4] = drawableIds & 0xff;
            if (ctx[GLD_boundFramebuffer / 4] == 0) {
              ctx[GLD_renderFlags / 4] = ctx[GLD_drawableFlags / 4];
              ctx[GLD_renderWidth / 4] = ctx[GLD_drawableWidth / 4];
              ctx[GLD_renderHeight / 4] = ctx[GLD_drawableHeight / 4];
              ctx[0x59] = ctx[0x43];
              ctx[0x5a] = ctx[0x44];
              ctx[0x5b] = ctx[0x45];
              ctx[0x5c] = ctx[0x46];
              return returnCode;
            }
            return returnCode;
          }
        }
        goto callGldDetachDrawable;
      }
      goto returnCode1;
    }
  }
  else {
    if (drawableType == 0x36) {
      if (drawable == (int *)0x0) {
        return 0x2715;
      }
      ctxFlags = ctx[GLD_drawableFlags / 4];
      ctx[GLD_drawableFlags / 4] = ctxFlags & 0xffffffdf;
      if (((ctxFlags & 0x400) != 0) || ((ctxFlags & 0x10) != 0)) {
        ctx[GLD_drawableFlags / 4] = ctxFlags & 0xffffffdf | 0x8000;
      }
      gld_applyPbufferToRenderFlags(ctx,ctx + GLD_drawableFlags / 4,0);
      rendererIndex = *ctx;
      status = rendererIndex * 4;
      if (*(int *)(PTR_DAT_001e88ac + status + 0x18) == 0) {
        status = _IOServiceOpen(*(undefined4 *)(*(int *)(PTR_DAT_001e88ac + 8) + status),
                               *(undefined4 *)ptrTo_machTaskSelf_001e88b4,0,PTR_DAT_001e88ac + status + 0x18);
        if (status != 0) goto returnCode2;
        rendererIndex = *ctx;
      }
      library = PTR_DAT_001e88ac;
      status = *(int *)(PTR_DAT_001e88ac + 0xc);
      PTR_DAT_001e88ac[rendererIndex + 0x98] = PTR_DAT_001e88ac[rendererIndex + 0x98] + '\x01';
      scalarIn0 = (uint)*(byte *)(status + *ctx);
      callWords[0] = 0;
      scalarIn1 = ctx[GLD_drawableFlags / 4] & 0x803f;
      ctxFlags = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(library + *ctx * 4 + 0x18),7,&scalarIn0,2,0,callWords);
      if (ctxFlags == 0) {
        scalarIn0 = ~(uint)*(byte *)(*(int *)(library + 0xc) + *ctx);
        scalarIn1 = ctx[GLD_drawableFlags / 4] & 0xffff3fc0;
        scalarIn2 = ctxFlags;
        scalarIn3 = ctxFlags;
        status = _io_connect_method_scalarI_structureI(ctx[GLD_connect / 4],0,&scalarIn0,4,0,0);
        if (status == 0) goto loopSetOutCount;
      }
returnCode1:
      returnCode = 0x2715;
      goto callGldDetachDrawable;
    }
    if (drawableType != 0x35) {
      if (drawableType != 0) {
        if (drawableType == 0x5b) {
          if (drawable != (int *)0x0) {
            ctx[GLD_renderFlags / 4] = drawable[3];
            ctx[GLD_renderBufferMask / 4] = drawable[2];
            ctx[GLD_renderWidth / 4] = (uint)*(ushort *)(*drawable + 0x9a);
            rectField9c = *(ushort *)(*drawable + 0x9c);
            ctx[0x5c] = 0;
            ctx[0x59] = 0;
            ctx[0x5a] = 0;
            ctx[0x5b] = 0;
            ctx[GLD_renderHeight / 4] = (uint)rectField9c;
            _memcpy(ctx[GLD_capsBlock / 4] + 0x24,drawable + 4,0x3c);
            *(uint *)ctx[GLD_capsBlock / 4] = *(uint *)ctx[GLD_capsBlock / 4] & 0xfffffffd;
            return 0;
          }
          ctx[GLD_renderFlags / 4] = ctx[GLD_drawableFlags / 4];
          ctx[GLD_renderBufferMask / 4] = ctx[0xe];
          ctx[GLD_renderWidth / 4] = ctx[GLD_drawableWidth / 4];
          ctx[GLD_renderHeight / 4] = ctx[GLD_drawableHeight / 4];
          ctx[0x59] = ctx[0x43];
          ctx[0x5a] = ctx[0x44];
          ctx[0x5b] = ctx[0x45];
          ctx[0x5c] = ctx[0x46];
          _memcpy(ctx[GLD_capsBlock / 4] + 0x24,ctx + GLD_stateCopy / 4,0x3c);
          if (*(char *)((int)ctx + 0x143) == '\0') {
            *(uint *)ctx[GLD_capsBlock / 4] = *(uint *)ctx[GLD_capsBlock / 4] & 0xfffffffd;
            return 0;
          }
          *(uint *)ctx[GLD_capsBlock / 4] = *(uint *)ctx[GLD_capsBlock / 4] | 2;
          return 0;
        }
        returnCode = 0x271a;
        goto callGldDetachDrawable;
      }
      if (drawable == (int *)0x0) {
        returnCode = 1;
        goto callGldDetachDrawable;
      }
    }
  }
returnCode2:
  returnCode = 0x2715;
callGldDetachDrawable:
  ((int (*)())gld_detachDrawable)(ctx);
  scalarIn1 = 0;
  scalarIn0 = 0;
  _io_connect_method_scalarI_structureI(ctx[GLD_connect / 4],0,&scalarIn0,4,0,0);
  return returnCode;
}

/* gld_latchValue178 @ 0x7810 (20 bytes) */
int gld_latchValue178(ctx, value)
  int ctx;
  undefined4 value;
{
  if (*(int *)(ctx + 0x178) != 0) {
    return;
  }
  *(undefined4 *)(ctx + 0x178) = value;
  return;
}

/* _gldGetError @ 0x7830 (20 bytes) */
int _gldGetError(ctx)
  int ctx;
{
  undefined4 error;
  
  error = *(undefined4 *)(ctx + GLD_lastError);
  *(undefined4 *)(ctx + GLD_lastError) = 0;
  return error;
}

/* _gldCreateFence @ 0x7850 (408 bytes) */
int _gldCreateFence(ctx, fenceOut)
  int ctx;
  undefined4 *fenceOut;
{
  undefined *taskPtr;
  int wordIndex;
  int *fence;
  int wordByteOffset;
  uint *bitmap;
  uint bitmapWord;
  uint *bitmapCursor;
  uint freeBitIndex;
  uint scanCounter;
  int bitsLeft;
  
  fence = (int *)_malloc(8);
  fence[1] = 0;
  *fence = 0;
  taskPtr = ptrTo_machTaskSelf_001e88b4;
  do {
    scanCounter = *(uint *)(ctx + GLD_statusRegionSize) >> 8;
    if (scanCounter != 0) {
      bitmap = *(uint **)(ctx + GLD_fenceBitmap);
      bitmapWord = *bitmap;
      if (bitmapWord != 0xffffffff) {
        wordIndex = 0;
        wordByteOffset = 0;
loopSetBitsLeft:
        bitsLeft = 0x20;
        scanCounter = 0;
        break;
      }
      wordIndex = 0;
      bitmapCursor = bitmap;
      while( true ) {
        wordIndex = wordIndex + 1;
        bitmapCursor = bitmapCursor + 1;
        scanCounter = scanCounter - 1;
        if (scanCounter == 0) break;
        bitmapWord = *bitmapCursor;
        wordByteOffset = wordIndex * 4;
        if (bitmapWord != 0xffffffff) goto loopSetBitsLeft;
      }
    }
    wordByteOffset = _IOConnectMapMemory(*(undefined4 *)(ctx + GLD_connect),4,*(undefined4 *)taskPtr,ctx + GLD_statusRegion
                                ,ctx + GLD_statusRegionSize,1);
    if (wordByteOffset != 0) {
      _free(fence);
      *fenceOut = 0;
      return 0x2720;
    }
    wordByteOffset = _realloc(*(undefined4 *)(ctx + GLD_fenceBitmap),*(uint *)(ctx + GLD_statusRegionSize) >> 5);
    *(int *)(ctx + GLD_fenceBitmap) = wordByteOffset;
    scanCounter = *(uint *)(ctx + GLD_statusRegionSize) >> 6;
    _memset(wordByteOffset + scanCounter,0,scanCounter);
  } while( true );
  while( true ) {
    freeBitIndex = scanCounter + 1;
    bitsLeft = bitsLeft + -1;
    scanCounter = freeBitIndex;
    if (bitsLeft == 0) break;
    freeBitIndex = scanCounter;
    if ((bitmapWord >> (scanCounter & 0x3f) & 1) == 0) goto setWordIndex;
  }
  scanCounter = 0x20;
setWordIndex:
  wordIndex = freeBitIndex + wordIndex * 0x20;
  *(uint *)((int)bitmap + wordByteOffset) = 1 << (scanCounter & 0x3f) | *(uint *)((int)bitmap + wordByteOffset);
  *fence = wordIndex;
  *(undefined4 *)(wordIndex * 8 + *(int *)(ctx + GLD_statusRegion)) =
       *(undefined4 *)(*(int *)(ctx + GLD_ringMap) + 0x18);
  *(undefined4 *)(*fence * 8 + *(int *)(ctx + GLD_statusRegion) + 4) = 0;
  *fenceOut = fence;
  *(undefined1 *)(fence + 1) = 1;
  return 0;
}

/* _gldDestroyFence @ 0x79f0 (76 bytes) */
int _gldDestroyFence(ctx, fence)
  int ctx;
  uint *fence;
{
  uint bitIndex;
  uint wordOffset;
  
  wordOffset = *fence >> 3 & 0x1ffffffc;
  bitIndex = *fence & 0x1f;
  *(uint *)(wordOffset + *(int *)(ctx + GLD_fenceBitmap)) =
       (-2 << bitIndex | 0xfffffffeU >> 0x20 - bitIndex) & *(uint *)(wordOffset + *(int *)(ctx + GLD_fenceBitmap));
  _free(fence);
  return 0;
}

/* _gldTestObject @ 0x7a40 (232 bytes) */
int _gldTestObject(ctx, objectKind, object)
  int ctx;
  int objectKind;
  int *object;
{
  uint isDone;
  byte completed;
  int entryIndex;
  int table;
  
  if (objectKind == 1) {
    isDone = gld_isTextureBackingIdle(ctx,object);
  }
  else if (objectKind == 0) {
    completed = *(byte *)(object + 1);
    if (completed == 0) {
      entryIndex = *object;
      table = *(int *)(ctx + GLD_statusRegion);
      if (*(int *)(entryIndex * 8 + table + 4) != 0) {
        _gldFlush(ctx);
        entryIndex = *object;
        table = *(int *)(ctx + GLD_statusRegion);
      }
      completed = gld_isStampRetired(ctx,*(undefined4 *)(entryIndex * 8 + table));
      *(byte *)(object + 1) = completed;
    }
    isDone = (uint)completed;
  }
  else if (objectKind == 2) {
    isDone = gld_isVertexArrayBackingIdle(ctx,object);
  }
  else {
    isDone = 1;
    if (objectKind == 3) {
      isDone = gld_isBufferBackingIdle(ctx,object);
    }
  }
  return isDone;
}

/* _gldFinishObject @ 0x7b30 (300 bytes) */
int _gldFinishObject(ctx, objectKind, object)
  int ctx;
  int objectKind;
  int *object;
{
  undefined4 returnCode;
  int table;
  int entryIndex;
  
  if (objectKind == 1) {
    gld_waitTextureStamp(ctx,object);
    returnCode = 0;
  }
  else if (objectKind == 0) {
    if (*(char *)(object + 1) == '\0') {
      entryIndex = *object;
      table = *(int *)(ctx + GLD_statusRegion);
      if (*(int *)(entryIndex * 8 + table + 4) != 0) {
        _gldFlush(ctx);
        entryIndex = *object;
        table = *(int *)(ctx + GLD_statusRegion);
      }
      table = gld_isStampRetired(ctx,*(undefined4 *)(entryIndex * 8 + table));
      *(char *)(object + 1) = (char)table;
      if (table == 0) {
        _io_connect_method_scalarI_structureI
                  (*(undefined4 *)(ctx + GLD_connect),9,*object * 8 + *(int *)(ctx + GLD_statusRegion),1,0,0);
        *(undefined1 *)(object + 1) = 1;
        return 0;
      }
    }
    returnCode = 0;
  }
  else if (objectKind == 2) {
    gld_waitVertexArrayStamp(ctx,object);
    returnCode = 0;
  }
  else {
    returnCode = 0x271a;
    if (objectKind == 3) {
      gld_waitBufferStamp(ctx,object);
      returnCode = 0;
    }
  }
  return returnCode;
}

/* _gldCreateFramebuffer @ 0x7c70 (104 bytes) */
int _gldCreateFramebuffer(ctx, framebufferOut, initialWord0, initialWord1)
  undefined4 ctx;
  int *framebufferOut;
  undefined4 initialWord0;
  undefined4 initialWord1;
{
  undefined4 *clearCursor;
  undefined4 *framebuffer;
  int clearCount;
  
  framebuffer = (undefined4 *)_calloc(1,200);
  *framebuffer = initialWord0;
  framebuffer[1] = initialWord1;
  clearCount = 6;
  clearCursor = framebuffer;
  do {
    clearCursor[0x13] = 0;
    clearCursor = clearCursor + 1;
    clearCount = clearCount + -1;
  } while (clearCount != 0);
  *framebufferOut = (int)framebuffer;
  return 0;
}

/* _gldReclaimFramebuffer @ 0x7ce0 (4 bytes) */
int _gldReclaimFramebuffer()
{
  return;
}

/* _gldDestroyFramebuffer @ 0x7cf0 (96 bytes) */
int _gldDestroyFramebuffer(ctx, framebuffer)
  int ctx;
  int framebuffer;
{
  if (*(int *)(ctx + GLD_boundFramebuffer) == framebuffer) {
    gld_updateYInvertedFlag(ctx);
    *(undefined4 *)(ctx + GLD_boundFramebuffer) = 0;
  }
  _free(framebuffer);
  return 0;
}

/* gld_bindCurrentFramebuffer @ 0x7d50 (368 bytes) */
int gld_bindCurrentFramebuffer(ctx, dispatch, dirtyBits, scratchR6, scratchR7, scratchR8)
  int ctx;
  undefined4 dispatch;
  undefined4 dirtyBits;
  undefined4 scratchR6;
  undefined4 scratchR7;
  undefined4 scratchR8;
{
  int casResult2;
  int oldAttachmentsLeft;
  int attachmentsLeft;
  int validateResult;
  bool hadFramebuffer;
  bool noNewFramebuffer;
  int casResult;
  int oldAttachmentCursor;
  int *refCountWord;
  int *newFramebuffer;
  char reservation;
  byte crField0;
  
  oldAttachmentCursor = *(int *)(ctx + 0x150);
  hadFramebuffer = oldAttachmentCursor != 0;
  newFramebuffer = *(int **)(*(int *)(ctx + 0x18) + 0x1a0);
  if (hadFramebuffer) {
    oldAttachmentsLeft = 6;
    do {
      if (*(int *)(oldAttachmentCursor + 0x4c) != 0) {
        refCountWord = (int *)(*(int *)(oldAttachmentCursor + 0x4c) + 0x10);
        do {
          if (reservation != '\0') {
            casResult = storeWordConditionalIndexed(*refCountWord + -0x10000,0,refCountWord);
            *refCountWord = casResult;
            crField0 = 2;
          }
        } while (!(bool)(crField0 >> 1 & 1));
      }
      oldAttachmentCursor = oldAttachmentCursor + 4;
      oldAttachmentsLeft = oldAttachmentsLeft + -1;
    } while (oldAttachmentsLeft != 0);
  }
  noNewFramebuffer = newFramebuffer == (int *)0x0;
  if ((!noNewFramebuffer) && (*(int *)(*newFramebuffer + 0xa0) == 0)) {
    if (*(int *)(newFramebuffer[1] + 0x18) == 0) {
      if (*(int *)(newFramebuffer[1] + 0x1c) == 0) goto storeCtx;
    }
    else {
      validateResult = gld_validateFramebuffer(ctx,newFramebuffer,dirtyBits,scratchR6,scratchR7,scratchR8);
      if (validateResult != 0) goto storeCtx;
    }
  }
  newFramebuffer = (int *)0x0;
  noNewFramebuffer = true;
storeCtx:
  *(int **)(ctx + 0x150) = newFramebuffer;
  if (!noNewFramebuffer) {
    attachmentsLeft = 6;
    do {
      if (newFramebuffer[0x13] != 0) {
        refCountWord = (int *)(newFramebuffer[0x13] + 0x10);
        do {
          if (reservation != '\0') {
            casResult2 = storeWordConditionalIndexed(*refCountWord + 0x10000,0,refCountWord);
            *refCountWord = casResult2;
            crField0 = 2;
          }
        } while (!(bool)(crField0 >> 1 & 1));
      }
      newFramebuffer = newFramebuffer + 1;
      attachmentsLeft = attachmentsLeft + -1;
    } while (attachmentsLeft != 0);
  }
  if ((*(int *)(*(int *)(ctx + 0x18) + 0x1a0) == 0) && (hadFramebuffer)) {
    gld_updateYInvertedFlag(ctx);
    return;
  }
  return;
}

/* gldDepthBitsToFormatMask @ 0x7ec0 (256 bytes) */
int gldDepthBitsToFormatMask(bitCount)
  uint bitCount;
{
  if (0x7f < bitCount) {
    return 0x10000;
  }
  if (0x5f < bitCount) {
    return 0x18000;
  }
  if (0x3f < bitCount) {
    return 0x1c000;
  }
  if (0x2f < bitCount) {
    return 0x1e000;
  }
  if (0x1f < bitCount) {
    return 0x1f000;
  }
  if (0x17 < bitCount) {
    return 0x1f800;
  }
  if (0xf < bitCount) {
    return 0x1fc00;
  }
  if (0xb < bitCount) {
    return 0x1fe00;
  }
  if (9 < bitCount) {
    return 0x1ff00;
  }
  if (7 < bitCount) {
    return 0x1ff80;
  }
  if (5 < bitCount) {
    return 0x1ffc0;
  }
  if (bitCount == 5) {
    return 0x1ffe0;
  }
  if (3 < bitCount) {
    return 0x1fff0;
  }
  if (bitCount == 3) {
    return 0x1fff8;
  }
  if (1 < bitCount) {
    return 0x1fffc;
  }
  return (bitCount == 0) + 0x1fffe;
}

/* gldColorBitsToFormatMask @ 0x7fc0 (112 bytes) */
int gldColorBitsToFormatMask(bitCount)
  uint bitCount;
{
  if (0x100 < bitCount) {
    return 0;
  }
  if (0x80 < bitCount) {
    return 0x30000000;
  }
  if (0x40 < bitCount) {
    return 0xc000000;
  }
  if (0x20 < bitCount) {
    return 0x3ff00000;
  }
  if (0x10 < bitCount) {
    return 0x3fffc000;
  }
  if (8 < bitCount) {
    return 0x3fffffc0;
  }
  if (bitCount != 0) {
    return 0x3ffffffc;
  }
  return 0xbffffffc;
}

/* gldAlphaBitsToFormatMask @ 0x8030 (128 bytes) */
int gldAlphaBitsToFormatMask(bitCount)
  uint bitCount;
{
  if (0x20 < bitCount) {
    return 0;
  }
  if (0x10 < bitCount) {
    return 0x8000000;
  }
  if (0xc < bitCount) {
    return 0xa800000;
  }
  if (8 < bitCount) {
    return 0xaa00000;
  }
  if (4 < bitCount) {
    return 0xaa9a928;
  }
  if (2 < bitCount) {
    return 0xaa9a9a8;
  }
  if (bitCount == 2) {
    return 0xaada9a8;
  }
  if (bitCount != 0) {
    return 0xaadada8;
  }
  return 0xbffffffc;
}

/* _gldChoosePixelFormat @ 0x80b0 (1980 bytes) */
int _gldChoosePixelFormat(formatListOut, attribList)
  int *formatListOut;
  uint *attribList;
{
  undefined *library;
  uint attribValue;
  uint stencilSize;
  int formatCount;
  int *newList;
  int copyIndex;
  uint *nextCursor;
  int *rendererListCursor;
  uint *attribCursor;
  int serviceOrNewRows;
  uint bufferFlags;
  uint colorSize;
  uint accumSize;
  uint alphaSize;
  int *formatList;
  uint accumAlphaSize;
  uint depthSize;
  uint redSize;
  uint greenSize;
  uint blueSize;
  uint accumRedSize;
  int recordsCopied;
  uint accumGreenSize;
  uint accumBlueSize;
  int *oldRecordCursor;
  undefined4 *candidateCursor;
  uint screenMask;
  uint surfaceFlags;
  uint capabilityMask;
  /* issue #64 live-repro: candidateRow = &pfNext (below) is used with pointer arithmetic spanning
   * MULTIPLE 0x34-byte rows (candidateRow + N*0xd, N up to a driver-computed pixel-format-variant
   * count) - the real stock array this represents is bigger than just this one row of individually
   * named locals. Ghidra only named row 0's fields (this group, exactly 0x34 bytes, confirmed by
   * each name's own hex offset: 0x194-0x160=0x34); the next declared local after this group is
   * depthMask, a real, unrelated variable - so the gap between them (0x194-0x88=0x10c bytes) is
   * exactly where the stock compiler placed the array's further rows, accessed only through this
   * pointer arithmetic and never given individual names. Left as separate scalars (the same defect
   * class fixed once already this session in auStack_c148/ilRewriteForTextureState), the -O0 rebuild does not
   * place them contiguously, so writes past row 0 miss into whatever real local happens to come
   * next on this build's stack - confirmed live: corrupts far enough to overwrite this function's
   * own formatListOut/attribList (live differential harness: _gldChoosePixelFormat crashes with
   * formatListOut=0xf, attribList=0x8000 - stock's real args here are always real pointers). Merged into one
   * 0x10c-byte buffer (row 0 aliased back to the original names, byte-exact per their own offsets;
   * the further rows stay unnamed/only reached via candidateRow, exactly as in the transcription). */
  unsigned char local_194_buf[0x10c];
#define pfNext (*(undefined4 *)(local_194_buf + 0x00))
#define pfRendererId (*(uint *)(local_194_buf + 0x04))
#define pfSurfaceFlags (*(uint *)(local_194_buf + 0x08))
#define pfBufferFlags (*(uint *)(local_194_buf + 0x0c))
#define pfColorMask (*(uint *)(local_194_buf + 0x10))
#define pfAccumMask (*(uint *)(local_194_buf + 0x14))
#define pfDepthMask (*(uint *)(local_194_buf + 0x18))
#define pfStencilMask (*(uint *)(local_194_buf + 0x1c))
#define pfLevel (*(undefined2 *)(local_194_buf + 0x20))
#define pfAuxBuffers (*(undefined2 *)(local_194_buf + 0x22))
#define pfSampleBuffers (*(undefined2 *)(local_194_buf + 0x24))
#define pfSamples (*(undefined2 *)(local_194_buf + 0x26))
#define pfAntialiasMode (*(undefined4 *)(local_194_buf + 0x28))
#define pfSampleAlpha (*(undefined1 *)(local_194_buf + 0x2c))
#define pfPad0 (*(undefined1 *)(local_194_buf + 0x2d))
#define pfPad1 (*(undefined1 *)(local_194_buf + 0x2e))
#define pfPad2 (*(undefined1 *)(local_194_buf + 0x2f))
#define pfDisplayMask (*(uint *)(local_194_buf + 0x30))
  uint depthMask;
  uint stencilMask;
  int level;
  int auxBuffers;
  int sampleBuffers;
  int samples;
  undefined4 antialiasMode;
  undefined4 sampleAlpha;
  undefined4 minimumPolicy;
  undefined4 maximumPolicy;
  undefined4 *candidateRow;
  
  if (formatListOut == (int *)0x0) {
    return 0x271e;
  }
  *formatListOut = 0;
  formatCount = _getenv("GL_REJECT_HW");
  if (formatCount != 0) {
    return 0;
  }
  capabilityMask = 0xfffffc;
  colorSize = 0;
  depthSize = 0;
  accumSize = 0;
  maximumPolicy = 0;
  minimumPolicy = 0;
  sampleAlpha = 0;
  antialiasMode = 0;
  samples = 0;
  sampleBuffers = 0;
  screenMask = *(uint *)PTR_DAT_001e88ac;
  auxBuffers = 0;
  alphaSize = 0;
  level = 0;
  redSize = 0;
  greenSize = 0;
  blueSize = 0;
  accumRedSize = 0;
  accumGreenSize = 0;
  accumBlueSize = 0;
  accumAlphaSize = 0;
  bufferFlags = 0;
  surfaceFlags = 0x510;
  stencilSize = 0;
  attribCursor = attribList;
  do {
    if (*attribCursor == 0) {
      stencilMask = ((int (*)())gldDepthBitsToFormatMask)(stencilSize);
      stencilMask = stencilMask & 0x1ffff;
      depthMask = ((int (*)())gldDepthBitsToFormatMask)(depthSize);
      depthMask = depthMask & 0x1ffff;
      blueSize = greenSize + redSize + blueSize;
      if ((int)colorSize < (int)blueSize) {
        colorSize = blueSize;
      }
      stencilSize = accumRedSize + accumGreenSize + accumBlueSize + accumAlphaSize;
      if ((int)accumSize < (int)stencilSize) {
        accumSize = stencilSize;
      }
      if (((int)colorSize < 0x21) && ((int)alphaSize < 9)) {
        capabilityMask = capabilityMask & 0xff0fffff;
      }
      stencilSize = ((int (*)())gldColorBitsToFormatMask)(colorSize);
      colorSize = ((int (*)())gldAlphaBitsToFormatMask)(alphaSize);
      accumSize = ((int (*)())gldColorBitsToFormatMask)(accumSize);
      alphaSize = ((int (*)())gldAlphaBitsToFormatMask)(accumAlphaSize);
      library = PTR_DAT_001e88ac;
      if (CONCAT22((short)sampleBuffers,(short)samples) == 0) {
        sampleAlpha = 0;
        antialiasMode = 0;
      }
      if (((surfaceFlags & 2) == 0) && ((surfaceFlags & 4) == 0)) {
        surfaceFlags = surfaceFlags | 1;
      }
      accumAlphaSize = *(uint *)(PTR_DAT_001e88ac + 4);
      formatList = (int *)0x0;
      if (accumAlphaSize != 0) {
        candidateRow = &pfNext;
        depthSize = 0;
        formatCount = 0;
        do {
          rendererListCursor = *(int **)(library + 8);
          serviceOrNewRows = rendererListCursor[depthSize];
          newList = formatList;
          if (serviceOrNewRows != 0) {
            if (depthSize == 0) {
loopSetGreenSize:
              greenSize = depthSize + 1;
              redSize = 1 << (depthSize & 0x3f);
              if (greenSize < accumAlphaSize) {
                copyIndex = accumAlphaSize - greenSize;
                rendererListCursor = rendererListCursor + greenSize;
                do {
                  if (serviceOrNewRows == *rendererListCursor) {
                    redSize = redSize | 1 << (greenSize & 0x3f);
                  }
                  greenSize = greenSize + 1;
                  rendererListCursor = rendererListCursor + 1;
                  copyIndex = copyIndex + -1;
                } while (copyIndex != 0);
              }
              redSize = redSize & screenMask;
              if (redSize != 0) {
                pfPad2 = 0;
                pfPad1 = 0;
                pfPad0 = 0;
                pfRendererId = 0;
                pfNext = 0;
                pfSampleAlpha = (undefined1)sampleAlpha;
                pfAntialiasMode = antialiasMode;
                pfSamples = (undefined2)samples;
                pfSampleBuffers = (undefined2)sampleBuffers;
                pfAuxBuffers = (undefined2)auxBuffers;
                pfLevel = (undefined2)level;
                pfStencilMask = stencilMask;
                pfDepthMask = depthMask;
                pfSurfaceFlags = surfaceFlags;
                if ((redSize & redSize - 1) != 0) {
                  pfSurfaceFlags = surfaceFlags | 0x200;
                }
                pfBufferFlags = bufferFlags;
                pfColorMask = capabilityMask & stencilSize & colorSize;
                pfAccumMask = accumSize & 0xbffffffc & alphaSize;
                pfDisplayMask = redSize;
                pfRendererId = gld_rendererStatusFlags(depthSize);
                pfRendererId = pfRendererId | depthSize << 0x18;
                serviceOrNewRows = gld_expandPixelFormatVariants(candidateRow,minimumPolicy,maximumPolicy);
                if (serviceOrNewRows != 0) {
                  formatCount = formatCount + serviceOrNewRows;
                  newList = (int *)_malloc(formatCount * 0x34);
                  if (newList == (int *)0x0) {
                    if (formatList != (int *)0x0) {
                      _free(formatList);
                      return 0x2720;
                    }
                    return 0x2720;
                  }
                  copyIndex = formatCount - serviceOrNewRows;
                  if (copyIndex < 1) {
                    copyIndex = 0;
                  }
                  else {
                    recordsCopied = 0;
                    oldRecordCursor = formatList;
                    rendererListCursor = newList;
                    do {
                      recordsCopied = recordsCopied + 1;
                      _memcpy(rendererListCursor,oldRecordCursor,0x34);
                      *rendererListCursor = (int)(rendererListCursor + 0xd);
                      oldRecordCursor = oldRecordCursor + 0xd;
                      rendererListCursor = rendererListCursor + 0xd;
                    } while (copyIndex != recordsCopied);
                  }
                  if (copyIndex < formatCount) {
                    recordsCopied = 0;
                    candidateCursor = candidateRow + (serviceOrNewRows + (copyIndex - formatCount)) * 0xd;
                    rendererListCursor = newList + copyIndex * 0xd;
                    do {
                      recordsCopied = recordsCopied + 1;
                      _memcpy(rendererListCursor,candidateCursor,0x34);
                      *rendererListCursor = (int)(rendererListCursor + 0xd);
                      candidateCursor = candidateCursor + 0xd;
                      rendererListCursor = rendererListCursor + 0xd;
                    } while (formatCount - copyIndex != recordsCopied);
                    copyIndex = copyIndex + recordsCopied;
                  }
                  newList[copyIndex * 0xd + -0xd] = 0;
                  if (formatList != (int *)0x0) {
                    _free(formatList);
                  }
                }
              }
            }
            else if (*rendererListCursor != serviceOrNewRows) {
              copyIndex = 0;
              redSize = depthSize;
              do {
                copyIndex = copyIndex + 1;
                redSize = redSize - 1;
                if (redSize == 0) goto loopSetGreenSize;
              } while (rendererListCursor[copyIndex] != serviceOrNewRows);
            }
          }
          depthSize = depthSize + 1;
          accumAlphaSize = *(uint *)(library + 4);
          formatList = newList;
        } while (depthSize < accumAlphaSize);
        if ((newList != (int *)0x0) && (formatCount < 1)) {
          formatList = (int *)0x0;
          _free(newList);
        }
      }
      *formatListOut = (int)formatList;
      return 0;
    }
    nextCursor = attribCursor + 1;
    switch(*attribCursor) {
    default:
      goto LAB_000089f0;
    case 2:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0;
      }
      break;
    case 3:
      level = (int)*(short *)((int)attribCursor + 6);
      nextCursor = attribCursor + 2;
      break;
    case 4:
      break;
    case 5:
      bufferFlags = bufferFlags | 8;
      break;
    case 6:
      bufferFlags = bufferFlags | 2;
      break;
    case 7:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      auxBuffers = (int)(short)attribValue;
      break;
    case 8:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)colorSize < (int)attribValue) {
        colorSize = attribValue;
      }
      break;
    case 0xb:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)alphaSize < (int)attribValue) {
        alphaSize = attribValue;
      }
      break;
    case 0xc:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)depthSize < (int)attribValue) {
        depthSize = attribValue;
      }
      break;
    case 0xd:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)stencilSize < (int)attribValue) {
        stencilSize = attribValue;
      }
      break;
    case 0xe:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)accumSize < (int)attribValue) {
        accumSize = attribValue;
      }
      break;
    case 0x14:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)redSize < (int)attribValue) {
        redSize = attribValue;
      }
      break;
    case 0x15:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)greenSize < (int)attribValue) {
        greenSize = attribValue;
      }
      break;
    case 0x16:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)blueSize < (int)attribValue) {
        blueSize = attribValue;
      }
      break;
    case 0x17:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)accumRedSize < (int)attribValue) {
        accumRedSize = attribValue;
      }
      break;
    case 0x18:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)accumGreenSize < (int)attribValue) {
        accumGreenSize = attribValue;
      }
      break;
    case 0x19:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)accumBlueSize < (int)attribValue) {
        accumBlueSize = attribValue;
      }
      break;
    case 0x1a:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      if ((int)accumAlphaSize < (int)attribValue) {
        accumAlphaSize = attribValue;
      }
      break;
    case 0x33:
      minimumPolicy = 1;
      break;
    case 0x34:
      maximumPolicy = 1;
      break;
    case 0x35:
      surfaceFlags = surfaceFlags | 4;
      break;
    case 0x36:
      surfaceFlags = surfaceFlags | 2;
      break;
    case 0x37:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      sampleBuffers = (int)(short)attribValue;
      break;
    case 0x38:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      if ((int)attribValue < 0) {
        return 0x2718;
      }
      samples = (int)(short)attribValue;
      break;
    case 0x39:
      surfaceFlags = surfaceFlags | 0x800;
      break;
    case 0x3a:
      capabilityMask = 0x3f000000;
      break;
    case 0x3b:
      antialiasMode = 2;
      break;
    case 0x3c:
      antialiasMode = 1;
      break;
    case 0x3d:
      sampleAlpha = 1;
      break;
    case 0x4c:
      surfaceFlags = surfaceFlags | 8;
      break;
    case 0x50:
      surfaceFlags = surfaceFlags | 1;
      break;
    case 0x54:
      attribValue = *nextCursor;
      nextCursor = attribCursor + 2;
      screenMask = screenMask & attribValue;
      break;
    case 0x5a:
      surfaceFlags = surfaceFlags | 0x2000;
    }
    attribCursor = nextCursor;
  } while ((int)nextCursor - (int)attribList < 0x94);
LAB_000089f0:
  return 10000;
}

/* _gldDestroyPixelFormat @ 0x8a10 (52 bytes) */
int _gldDestroyPixelFormat(pixelFormat)
  int pixelFormat;
{
  undefined4 returnCode;
  
  returnCode = 0x271e;
  if (pixelFormat != 0) {
    _free(pixelFormat);
    returnCode = 0;
  }
  return returnCode;
}

/* _gldGetRendererInfo @ 0x8a50 (500 bytes) */
int _gldGetRendererInfo(rendererInfo, rendererMask, unused3, unused4, unused5, unused6, unused7, unused8)
  undefined4 *rendererInfo;
  uint rendererMask;
  undefined4 unused3;
  undefined4 unused4;
  undefined4 unused5;
  undefined4 unused6;
  undefined4 unused7;
  undefined4 unused8;
{
  undefined4 returnCode;
  uint bitOrId;
  int *serviceList;
  int listCount;
  int rendererIndex;
  int offsetOrService;
  undefined4 outCount;
  undefined4 connection;
  undefined1 scalarOut0 [4];
  undefined4 scalarOut1;
  undefined4 scalarOut2;
  
  if (((*(uint *)PTR_DAT_001e88ac & rendererMask) == 0) || ((rendererMask & ~*(uint *)PTR_DAT_001e88ac) != 0))
  {
    returnCode = 0x2719;
  }
  else {
    listCount = *(int *)(PTR_DAT_001e88ac + 4);
    if ((listCount == 0) || ((rendererMask & 1) != 0)) {
      offsetOrService = 0;
    }
    else {
      bitOrId = 0;
      offsetOrService = listCount;
      do {
        bitOrId = bitOrId + 1;
        offsetOrService = offsetOrService + -1;
        if (offsetOrService == 0) {
          offsetOrService = listCount << 2;
          goto setServiceList;
        }
      } while ((rendererMask & 1 << (bitOrId & 0x3f)) == 0);
      offsetOrService = bitOrId * 4;
    }
setServiceList:
    serviceList = *(int **)(PTR_DAT_001e88ac + 8);
    offsetOrService = *(int *)((int)serviceList + offsetOrService);
    if ((listCount == 0) || (offsetOrService == *serviceList)) {
      rendererIndex = 0;
    }
    else {
      rendererIndex = 0;
      do {
        rendererIndex = rendererIndex + 1;
        listCount = listCount + -1;
        if (listCount == 0) break;
      } while (offsetOrService != serviceList[rendererIndex]);
    }
    listCount = _IOServiceOpen(offsetOrService,*(undefined4 *)ptrTo_machTaskSelf_001e88b4,1,&connection);
    returnCode = 0x271f;
    if (listCount == 0) {
      outCount = 3;
      listCount = _io_connect_method_scalarI_scalarO(connection,3,0,0,scalarOut0,&outCount);
      if (listCount == 0) {
        *rendererInfo = 0;
        bitOrId = gld_rendererStatusFlags(rendererIndex);
        *(undefined2 *)(rendererInfo + 8) = 0;
        *(undefined2 *)((int)rendererInfo + 0x22) = 0;
        *(undefined2 *)(rendererInfo + 9) = 0;
        *(undefined2 *)((int)rendererInfo + 0x26) = 0;
        *(undefined2 *)(rendererInfo + 10) = 0;
        rendererInfo[0xb] = 0;
        rendererInfo[0xc] = scalarOut2;
        rendererInfo[0xd] = scalarOut1;
        rendererInfo[3] = 0xd;
        rendererInfo[2] = 0xa513;
        rendererInfo[1] = bitOrId | rendererIndex << 0x18;
        rendererInfo[6] = 0x1c01;
        rendererInfo[4] = 0x8400;
        rendererInfo[5] = 0x808000;
        *(undefined1 *)((int)rendererInfo + 0x2a) = 0;
        rendererInfo[7] = 0x80;
        gld_fillMaxPixelFormat(rendererInfo);
        _IOServiceClose(connection);
        returnCode = 0;
      }
      else {
        _IOServiceClose(connection);
        returnCode = 0x271f;
      }
    }
  }
  return returnCode;
}

/* _gldInitializeLibrary @ 0x8c60 (156 bytes) */
int _gldInitializeLibrary(libArg0, libArg1, displayMask, libArg3, attachCallback)
  undefined4 libArg0;
  undefined4 libArg1;
  uint displayMask;
  undefined4 libArg3;
  undefined4 attachCallback;
{
  undefined *library;
  undefined *libraryAlias;
  uint bitIndex;
  undefined4 *slotCursor;
  
  library = PTR_DAT_001e88ac;
  bitIndex = 0;
  *(undefined4 *)(PTR_DAT_001e88ac + 0xc) = libArg1;
  *(undefined4 *)(library + 8) = libArg0;
  *(undefined4 *)(library + 4) = 0;
  *(uint *)library = displayMask;
  slotCursor = (undefined4 *)(library + 0x18);
  do {
    *slotCursor = 0;
    library[bitIndex + 0x98] = 0;
    if ((1 << (bitIndex & 0x3f) & displayMask) != 0) {
      *(uint *)(library + 4) = bitIndex + 1;
    }
    libraryAlias = PTR_DAT_001e88ac;
    slotCursor = slotCursor + 1;
    bitIndex = bitIndex + 1;
  } while ((int)bitIndex < 0x20);
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = attachCallback;
  *(undefined4 *)(libraryAlias + 0x10) = libArg3;
  return;
}

/* _gldTerminateLibrary @ 0x8d10 (56 bytes) */
int _gldTerminateLibrary()
{
  undefined *library;
  
  library = PTR_DAT_001e88ac;
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = 0;
  *(undefined4 *)(library + 8) = 0;
  *(undefined4 *)(library + 0xc) = 0;
  *(undefined4 *)library = 0;
  *(undefined4 *)(library + 4) = 0;
  *(undefined4 *)(library + 0x10) = 0;
  return;
}

/* _gldIsTextureResident @ 0x8d50 (16 bytes) */
int _gldIsTextureResident(ctx, texture)
  undefined4 ctx;
  int texture;
{
  return *(int *)(texture + 0x34) != 0;
}

/* _gldCreateTexture @ 0x8d60 (164 bytes) */
int _gldCreateTexture(ctx, textureOut, textureArg)
  undefined4 ctx;
  undefined4 *textureOut;
  undefined4 textureArg;
{
  undefined4 *texture;
  
  texture = (undefined4 *)_calloc(1,0xd8);
  *textureOut = texture;
  texture[0xc] = textureArg;
  texture[0xd] = 0;
  *texture = 0;
  texture[1] = 3;
  texture[2] = 0;
  texture[3] = 0;
  texture[4] = 0;
  texture[5] = 0;
  texture[8] = texture + 6;
  texture[7] = 0;
  *(undefined1 *)((int)texture + 0x39) = 3;
  *(undefined2 *)((int)texture + 0x2e) = 0;
  *(undefined1 *)(texture + 0xe) = 0;
  *(undefined2 *)(texture + 9) = 0;
  *(undefined2 *)((int)texture + 0x26) = 0;
  *(undefined2 *)(texture + 10) = 0;
  *(undefined2 *)((int)texture + 0x2a) = 0;
  *(undefined2 *)(texture + 0xb) = 0;
  texture[6] = texture + 7;
  return 0;
}

/* _gldCreateTextureLevel @ 0x8e10 (76 bytes) */
int _gldCreateTextureLevel(ctx, texture, changeFlags, face, level)
  undefined4 ctx;
  int texture;
  undefined4 changeFlags;
  int face;
  uint level;
{
  int faceEntry;
  
  *(byte *)(texture + 0x39) = (byte)changeFlags | *(byte *)(texture + 0x39);
  if (((byte)changeFlags & 1) != 0) {
    *(undefined1 *)(texture + 0x38) = 0;
  }
  if (((byte)changeFlags & 7) != 0) {
    faceEntry = face * 2 + texture;
    *(ushort *)(faceEntry + 0x24) = (ushort)(1 << (level & 0x3f)) | *(ushort *)(faceEntry + 0x24);
  }
  return 0;
}

/* _gldModifyTexture @ 0x8e60 (20 bytes) */
int _gldModifyTexture(ctx, texture, changeFlags)
  undefined4 ctx;
  int texture;
  undefined4 changeFlags;
{
  *(byte *)(texture + 0x39) = (byte)changeFlags | *(byte *)(texture + 0x39);
  return 0;
}

/* _gldModifyTextureLevel @ 0x8e80 (204 bytes) */
int _gldModifyTextureLevel(ctx, texture, face, level)
  undefined4 ctx;
  int texture;
  int face;
  uint level;
{
  ushort oldLevelMask;
  int faceEntry;
  int resident;
  
  resident = *(int *)(texture + 0x34);
  if (level == 0xffffffff) {
    *(byte *)(texture + 0x39) = *(byte *)(texture + 0x39) | 0x40;
  }
  else {
    faceEntry = face * 2 + texture;
    oldLevelMask = *(ushort *)(faceEntry + 0x24);
    *(byte *)(texture + 0x39) = *(byte *)(texture + 0x39) | 4;
    *(ushort *)(faceEntry + 0x24) = (ushort)(1 << (level & 0x3f)) | oldLevelMask;
  }
  if ((resident != 0) && ((byte)(*(char *)(resident + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(resident + 0x10)) {
      _gldFlush(ctx);
    }
    gld_waitTextureStamp(ctx,texture);
  }
  return 0;
}

/* _gldGetTextureLevelInfo @ 0x8f60 (520 bytes) */
int _gldGetTextureLevelInfo(ctx, texture, face, level, pname, valueOut)
  int ctx;
  int texture;
  undefined4 face;
  undefined4 level;
  undefined *pname;
  uint *valueOut;
{
  uint residentSize;
  int boundTextureSize;
  int boundSlotCursor;
  uint infoComponents;
  uint infoRedSize;
  uint infoGreenSize;
  uint infoBlueSize;
  uint infoAlphaSize;
  uint infoLuminanceSize;
  uint infoIntensitySize;
  uint infoDepthSize;
  uint infoCompressedImageSize;
  byte infoCompressed;
  
  gld_getTextureFormatInfo(ctx,texture,face,level,&infoComponents);
  if ((**(ushort **)(texture + 0x30) & 0x100) != 0) {
    residentSize = gld_textureMemoryBytes(ctx,texture);
    boundSlotCursor = ctx;
    do {
      if (*(int *)(boundSlotCursor + 0x18c) != 0) {
        boundTextureSize = gld_textureMemoryBytes(ctx,*(int *)(boundSlotCursor + 0x18c));
        residentSize = residentSize + boundTextureSize;
      }
      boundSlotCursor = boundSlotCursor + 4;
    } while (ctx + GLD_stateCopy != boundSlotCursor);
    if (*(uint *)(ctx + GLD_hwConfig1) < residentSize) {
      *valueOut = 0;
      return 0x2720;
    }
  }
  if (pname == (undefined *)0x805f) {
    *valueOut = infoAlphaSize;
    return 0;
  }
  if (pname < (undefined *)0x8060) {
    if (pname == (undefined *)0x805c) {
      *valueOut = infoRedSize;
      return 0;
    }
    if (pname < (undefined *)0x805d) {
      if (pname == ((unsigned char *)0x00001003)) {
        *valueOut = infoComponents;
        return 0;
      }
    }
    else {
      if (pname == (undefined *)0x805d) {
        *valueOut = infoGreenSize;
        return 0;
      }
      if (pname == (undefined *)0x805e) {
        *valueOut = infoBlueSize;
        return 0;
      }
    }
  }
  else {
    if (pname == (undefined *)0x86a0) {
      *valueOut = infoCompressedImageSize;
      return 0;
    }
    if (pname < (undefined *)0x86a1) {
      if (pname == (undefined *)0x8060) {
        *valueOut = infoLuminanceSize;
        return 0;
      }
      if (pname == (undefined *)0x8061) {
        *valueOut = infoIntensitySize;
        return 0;
      }
    }
    else {
      if (pname == (undefined *)0x86a1) {
        *valueOut = (uint)infoCompressed;
        return 0;
      }
      if (pname == (undefined *)0x884a) {
        *valueOut = infoDepthSize;
        return 0;
      }
    }
  }
  return 0;
}

/* _gldDeleteTextureLevel @ 0x9180 (264 bytes) */
int _gldDeleteTextureLevel(ctx, texture, face, level)
  int ctx;
  int texture;
  int face;
  uint level;
{
  ushort oldLevelMask;
  int updatedRefCount;
  int *refCountSlot;
  int oldRefCount;
  int faceEntry;
  char reservation;
  byte crBits;
  
  if (level == 0xffffffff) {
    *(byte *)(texture + 0x39) = *(byte *)(texture + 0x39) | 0x43;
  }
  else {
    faceEntry = face * 2 + texture;
    oldLevelMask = *(ushort *)(faceEntry + 0x24);
    *(byte *)(texture + 0x39) = *(byte *)(texture + 0x39) | 7;
    *(ushort *)(faceEntry + 0x24) = (ushort)(1 << (level & 0x3f)) | oldLevelMask;
  }
  faceEntry = *(int *)(texture + 0x34);
  if ((faceEntry != 0) && ((byte)(*(char *)(faceEntry + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(faceEntry + 0x10)) {
      _gldFlush(ctx);
    }
    refCountSlot = (int *)(faceEntry + 0x10);
    do {
      oldRefCount = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (oldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,faceEntry,1,0,0);
    }
    *(undefined4 *)(texture + 0x34) = 0;
  }
  return 0;
}

/* _gldReclaimTexture @ 0x9290 (396 bytes) */
int _gldReclaimTexture(ctx, texture)
  int ctx;
  int texture;
{
  bool moreUnits;
  int updatedRefCount;
  int *refCountSlot;
  int *listNeighbour;
  int unitOrOldRefCount;
  int unitSlotCursor;
  char reservation;
  byte crBits;
  
  unitOrOldRefCount = 0;
  unitSlotCursor = ctx;
  do {
    if (texture == *(int *)(unitSlotCursor + 0x18c)) {
      *(undefined4 *)(unitSlotCursor + 0x18c) = 0;
      gld_emitUnitClearPacket(ctx,unitOrOldRefCount);
    }
    moreUnits = unitOrOldRefCount != 0xf;
    unitSlotCursor = unitSlotCursor + 4;
    unitOrOldRefCount = unitOrOldRefCount + 1;
  } while (moreUnits);
  unitSlotCursor = *(int *)(texture + 0x34);
  if (unitSlotCursor != 0) {
    if ((0x1ffff < (int)*(uint *)(unitSlotCursor + 0x10)) || ((*(uint *)(unitSlotCursor + 0x10) & 0xffff) != 0)) {
      _gldFlush(ctx);
    }
    gld_waitTextureStamp(ctx,texture);
    refCountSlot = (int *)(unitSlotCursor + 0x10);
    do {
      unitOrOldRefCount = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(unitOrOldRefCount + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (unitOrOldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,unitSlotCursor,1,0,0);
    }
    *(undefined4 *)(texture + 0x34) = 0;
  }
  while( true ) {
    refCountSlot = *(int **)(texture + 0x18);
    if (*refCountSlot == 0) break;
    listNeighbour = (int *)refCountSlot[1];
    *listNeighbour = *refCountSlot;
    unitSlotCursor = *refCountSlot;
    *refCountSlot = 0;
    *(int **)(unitSlotCursor + 4) = listNeighbour;
    refCountSlot[1] = 0;
    if (refCountSlot == (int *)0x0) break;
    unitSlotCursor = refCountSlot[4];
    listNeighbour = (int *)(unitSlotCursor + 0x10);
    do {
      unitOrOldRefCount = *listNeighbour;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(unitOrOldRefCount + -0x10000,0,listNeighbour);
        *listNeighbour = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (unitOrOldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,unitSlotCursor,1,0,0);
    }
    refCountSlot[4] = 0;
    _free(refCountSlot);
  }
  *(undefined1 *)(texture + 0x39) = 0x23;
  return;
}

/* _gldDeleteTexture @ 0x9420 (56 bytes) */
int _gldDeleteTexture(ctx, texture)
  undefined4 ctx;
  undefined4 texture;
{
  ((int (*)())_gldReclaimTexture)(ctx,texture);
  _free(texture);
  return 0;
}

/* _gldCreatePipelineProgram @ 0x9460 (80 bytes) */
int _gldCreatePipelineProgram(ctx, programOut, programRef)
  undefined4 ctx;
  int *programOut;
  undefined4 programRef;
{
  undefined4 *program;
  
  program = (undefined4 *)_calloc(1,0x40);
  *programOut = (int)program;
  *program = programRef;
  program[0xf] = 3;
  return 0;
}

/* _gldModifyPipelineProgram @ 0x94b0 (48 bytes) */
int _gldModifyPipelineProgram(ctx, program, changeFlags)
  undefined4 ctx;
  int program;
  uint changeFlags;
{
  *(uint *)(program + 0x3c) = changeFlags | *(uint *)(program + 0x3c);
  noop_24fd0();
  return 0;
}

/* _gldRelatePipelineProgram @ 0x94e0 (84 bytes) */
int _gldRelatePipelineProgram(ctx, programState, programRef, bind)
  undefined4 ctx;
  int programState;
  undefined4 *programRef;
  int bind;
{
  if (*(short *)*programRef == -0x74d0) {
    if (bind == 0) {
      programRef = (undefined4 *)0x0;
    }
    *(undefined4 **)(programState + 8) = programRef;
  }
  else if (*(short *)*programRef == -0x74cf) {
    if (bind == 0) {
      programRef = (undefined4 *)0x0;
    }
    *(undefined4 **)(programState + 4) = programRef;
  }
  return 0;
}

/* _gldGetPipelineProgramInfo @ 0x9540 (36 bytes) */
int _gldGetPipelineProgramInfo(arg0, arg1, arg2, arg3)
  undefined4 arg0;
  undefined4 arg1;
  undefined4 arg2;
  undefined4 arg3;
{
  gld_getProgramParameter(arg0,arg1,arg2,arg3);
  return 0;
}

/* _gldDestroyPipelineProgram @ 0x9570 (104 bytes) */
int _gldDestroyPipelineProgram(ctx, program)
  int ctx;
  int program;
{
  bool moreSlots;
  int slotCursor;
  int slot;
  
  slot = 0;
  slotCursor = ctx;
  do {
    if (program == *(int *)(slotCursor + 0x1cc)) {
      *(undefined4 *)(slotCursor + 0x1cc) = 0;
    }
    moreSlots = slot != 1;
    slotCursor = slotCursor + 4;
    slot = slot + 1;
  } while (moreSlots);
  gld_releaseProgramObject(ctx,program);
  _free(program);
  return 0;
}

/* gld_resolveProgramSlots @ 0x95e0 (192 bytes) */
int gld_resolveProgramSlots(ctx)
  int ctx;
{
  bool isLastSlot;
  int engineObjectSlot;
  int programIndex;
  int programSlotPtr;
  int *programObject;
  
  programIndex = 0;
  programSlotPtr = ctx;
  do {
    engineObjectSlot = programIndex * 4 + *(int *)(ctx + 0x18);
    programObject = *(int **)(engineObjectSlot + 0x198);
    if (programObject == (int *)0x0) {
      if (((unsigned char *)0x00004304)[programIndex * 8 + *(int *)(ctx + 0x10)] != '\0') {
        programObject = *(int **)(engineObjectSlot + 0x18c);
        goto checkProgramObject;
      }
      *(undefined4 *)(programSlotPtr + 0x1cc) = 0;
    }
    else {
checkProgramObject:
      if ((*(int *)(*programObject + 4) == 0) || (engineObjectSlot = gld_bindProgramObject(ctx,programObject), engineObjectSlot == 0)) {
        *(undefined4 *)(programSlotPtr + 0x1cc) = 0;
      }
      else {
        *(int **)(programSlotPtr + 0x1cc) = programObject;
      }
    }
    isLastSlot = programIndex == 1;
    programSlotPtr = programSlotPtr + 4;
    programIndex = programIndex + 1;
    if (isLastSlot) {
      return;
    }
  } while( true );
}

/* gld_decodeProgramOperandOffset @ 0x96b0 (72 bytes) */
int gld_decodeProgramOperandOffset(operandWord, staleArgR4, offsetOut, byteSizeOut)
  uint operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
  undefined4 *byteSizeOut;
{
  uint scratchUint1;
  uint scratchUint2;
  uint operandIndexByte;
  int stateOffset;
  
  *byteSizeOut = 4;
  switch(operandWord >> 0x10 & 0x1f) {
  case 0:
  case 1:
  case 9:
  case 0xf:
    return;
  case 2:
    *offsetOut = (operandWord & 0xffff) * 0x10 + 0x10;
    return;
  case 3:
    scratchUint2 = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      *offsetOut = scratchUint2 * 0x80 + 0x24c0;
      return;
    case 1:
      *offsetOut = scratchUint2 * 0x80 + 0x24d0;
      return;
    case 2:
      *offsetOut = scratchUint2 * 0x80 + 0x24e0;
      return;
    case 3:
      *offsetOut = scratchUint2 * 0x80 + 0x24f0;
      return;
    case 4:
      *offsetOut = scratchUint2 * 0x80 + 0x2500;
      return;
    case 5:
      *offsetOut = scratchUint2 * 0x80 + 0x2510;
      return;
    case 6:
      *offsetOut = scratchUint2 * 0x80 + 0x2520;
      return;
    default:
      return;
    }
  case 4:
    operandIndexByte = operandWord & 0xff;
    scratchUint1 = operandWord >> 9 & 3;
    scratchUint2 = operandWord >> 8 & 1;
    if (scratchUint1 == 1) {
      *offsetOut = scratchUint2 * 0x240 + operandIndexByte * 0x30 + 0x2920;
      return;
    }
    if (scratchUint1 == 2) {
      *offsetOut = scratchUint2 * 0x240 + operandIndexByte * 0x30 + 0x2930;
      return;
    }
    if (scratchUint1 == 0) {
      *offsetOut = scratchUint2 * 0x240 + operandIndexByte * 0x30 + 0x2910;
      return;
    }
    return;
  case 5:
    scratchUint2 = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      *offsetOut = scratchUint2 * 0x240 + 0x28c0;
      return;
    case 1:
      *offsetOut = scratchUint2 * 0x240 + 0x28d0;
      return;
    case 2:
      *offsetOut = scratchUint2 * 0x240 + 0x28e0;
      return;
    case 3:
      *offsetOut = scratchUint2 * 0x240 + 0x28f0;
      return;
    case 4:
      *offsetOut = scratchUint2 * 0x240 + 0x2900;
      return;
    case 5:
      *offsetOut = scratchUint2 * 0x240 + 0x2a90;
      return;
    default:
      return;
    }
  case 6:
    *offsetOut = 0x24b0;
    return;
  case 7:
    break;
  case 8:
    scratchUint1 = operandWord >> 5 & 7;
    scratchUint2 = operandWord & 0x1f;
    if (scratchUint1 == 1) {
      *offsetOut = (int)(((unsigned char *)0x000039c0) + scratchUint2 * 0x94);
      return;
    }
    if (scratchUint1 < 2) {
      if (scratchUint1 == 0) {
        *offsetOut = (int)(((unsigned char *)0x0000399c) + scratchUint2 * 0x94);
        return;
      }
      return;
    }
    if (scratchUint1 == 2) {
      *offsetOut = (int)(((unsigned char *)0x000039e4) + scratchUint2 * 0x94);
      return;
    }
    if (scratchUint1 == 3) {
      *offsetOut = (int)(((unsigned char *)0x00003a08) + scratchUint2 * 0x94);
      return;
    }
    return;
  case 10:
    *offsetOut = (int)(((unsigned char *)0x00003e2c) + (operandWord & 0xff) * 0x10);
    return;
  case 0xb:
    *offsetOut = (int)((unsigned char *)0x00002de0);
    return;
  case 0xc:
    *offsetOut = (int)((unsigned char *)0x00002df0);
    return;
  case 0xd:
    *offsetOut = (int)((unsigned char *)0x000030bc);
    return;
  case 0xe:
    *offsetOut = (int)((unsigned char *)0x000030cc);
    return;
  case 0x10:
    scratchUint2 = operandWord & 0xff;
    stateOffset = scratchUint2 << 6;
    switch(operandWord >> 8 & 7) {
    case 0:
      stateOffset = 0;
      break;
    case 1:
      stateOffset = 0xc0;
      break;
    case 2:
      stateOffset = 0x80;
      break;
    case 3:
      stateOffset = (scratchUint2 + 4) * 0x40;
      break;
    case 4:
      stateOffset = (scratchUint2 + 0x10) * 0x40;
      break;
    case 5:
      stateOffset = (scratchUint2 + 8) * 0x40;
    }
    scratchUint2 = operandWord >> 0xe & 3;
    if (scratchUint2 < 2) {
      *offsetOut = stateOffset + 0x1860;
    }
    else {
      *offsetOut = stateOffset + 0x1e60;
    }
    scratchUint1 = operandWord >> 0xc & 3;
    if (scratchUint2 < 3) {
      if (scratchUint2 != 0) {
        *offsetOut = scratchUint1 * 0x10 + *offsetOut;
        return;
      }
    }
    else if (scratchUint2 != 3) {
      return;
    }
    *offsetOut = scratchUint1 * 4 + *offsetOut;
    *byteSizeOut = 0x10;
    return;
  default:
    return;
  }
  scratchUint1 = operandWord >> 5 & 7;
  scratchUint2 = operandWord & 0x1f;
  if (scratchUint1 == 1) {
    *offsetOut = (int)(((unsigned char *)0x000039b0) + scratchUint2 * 0x94);
    return;
  }
  if (scratchUint1 < 2) {
    if (scratchUint1 == 0) {
      *offsetOut = (int)(((unsigned char *)0x0000398c) + scratchUint2 * 0x94);
      return;
    }
    return;
  }
  if (scratchUint1 == 2) {
    *offsetOut = (int)(((unsigned char *)0x000039d4) + scratchUint2 * 0x94);
    return;
  }
  if (scratchUint1 == 3) {
    *offsetOut = (int)(((unsigned char *)0x000039f8) + scratchUint2 * 0x94);
    return;
  }
  return;
}

/* gld_decodeProgramOperandOffset_frag_0000973c @ 0x973c (20 bytes) */
int gld_decodeProgramOperandOffset_frag_0000973c(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  undefined2 registerIndexShort;
  
  *offsetOut = (uint)registerIndexShort * 0x10 + 0x10;
  return;
}

/* gld_decodeProgramOperandOffset_frag_00009750 @ 0x9750 (48 bytes) */
int gld_decodeProgramOperandOffset_frag_00009750(operandWord, staleArgR4, offsetOut, byteSizeOut, staleArgR7, jumpTableBase)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
  undefined4 byteSizeOut;
  undefined4 staleArgR7;
  int jumpTableBase;
{
  uint fileSelect;
  uint registerIndex;
  undefined4 operandWordReg;
  
  registerIndex = operandWordReg & 0xff;
  fileSelect = operandWordReg >> 8 & 0xf;
  if (6 < fileSelect) {
    return;
  }
                    
  switch(*(int *)(fileSelect * 4 + jumpTableBase + 0xbc) + jumpTableBase + 0xbc) {
  case 0x979c:
    *offsetOut = registerIndex * 0x80 + 0x24c0;
    return;
  case 0x97ac:
    *offsetOut = registerIndex * 0x80 + 0x24d0;
    return;
  case 0x97bc:
    *offsetOut = registerIndex * 0x80 + 0x24e0;
    return;
  case 0x97cc:
    *offsetOut = registerIndex * 0x80 + 0x24f0;
    return;
  case 0x97dc:
    *offsetOut = registerIndex * 0x80 + 0x2500;
    return;
  case 0x97ec:
    *offsetOut = registerIndex * 0x80 + 0x2510;
    return;
  case 0x97fc:
    *offsetOut = registerIndex * 0x80 + 0x2520;
    return;
  }
}

/* gld_decodeProgramOperandOffset_frag_0000979c @ 0x979c (16 bytes) */
int gld_decodeProgramOperandOffset_frag_0000979c(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x24c0;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097ac @ 0x97ac (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097ac(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x24d0;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097bc @ 0x97bc (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097bc(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x24e0;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097cc @ 0x97cc (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097cc(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x24f0;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097dc @ 0x97dc (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097dc(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x2500;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097ec @ 0x97ec (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097ec(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x2510;
  return;
}

/* gld_decodeProgramOperandOffset_frag_000097fc @ 0x97fc (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000097fc(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x80 + 0x2520;
  return;
}

/* gld_decodeProgramOperandOffset_frag_00009810 @ 0x9810 (112 bytes) */
int gld_decodeProgramOperandOffset_frag_00009810(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  uint bankSelect;
  uint kindSelect;
  uint registerIndex;
  undefined4 operandWordReg;
  
  registerIndex = operandWordReg & 0xff;
  kindSelect = operandWordReg >> 9 & 3;
  bankSelect = operandWordReg >> 8 & 1;
  if (kindSelect == 1) {
    *offsetOut = bankSelect * 0x240 + registerIndex * 0x30 + 0x2920;
    return;
  }
  if (kindSelect != 2) {
    if (kindSelect != 0) {
      return;
    }
    *offsetOut = bankSelect * 0x240 + registerIndex * 0x30 + 0x2910;
    return;
  }
  *offsetOut = bankSelect * 0x240 + registerIndex * 0x30 + 0x2930;
  return;
}

/* gld_decodeProgramOperandOffset_frag_00009880 @ 0x9880 (48 bytes) */
int gld_decodeProgramOperandOffset_frag_00009880(operandWord, staleArgR4, offsetOut, byteSizeOut, staleArgR7, staleArgR8)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
  undefined4 byteSizeOut;
  undefined4 staleArgR7;
  int staleArgR8;
{
  uint operandWordReg;
  
  if ((operandWordReg >> 1 & 7) < 6) {
                    
    *offsetOut = (operandWordReg & 1) * 0x240 + 0x28c0;
    return;
  }
  return;
}

/* gld_decodeProgramOperandOffset_frag_000098c8 @ 0x98c8 (16 bytes) */
int gld_decodeProgramOperandOffset_frag_000098c8(operandWord, staleArgR4, offsetOut)
  undefined4 operandWord;
  undefined4 staleArgR4;
  int *offsetOut;
{
  int registerIndex;
  
  *offsetOut = registerIndex * 0x240 + 0x28c0;
  return;
}

/* gldAllocQueryRecord @ 0x9b70 (88 bytes) */
int gldAllocQueryRecord(ctx)
  int ctx;
{
  undefined4 returnCode;
  int record;
  
  record = _calloc(1,0x18);
  returnCode = 0x2720;
  *(int *)(ctx + GLD_queryRecord) = record;
  if (record != 0) {
    returnCode = 0;
  }
  return returnCode;
}

/* gld_waitQueryStamp @ 0x9bd0 (164 bytes) */
int gld_waitQueryStamp(ctx)
  int ctx;
{
  int gld_isStampRetiredResult;
  int queryRecord;
  
  queryRecord = **(int **)(ctx + 0x234);
  if (queryRecord != 0) {
    if ((0x1ffff < (int)*(uint *)(queryRecord + 0x10)) || ((*(uint *)(queryRecord + 0x10) & 0xffff) != 0)) {
      _gldFlush(ctx);
    }
    gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(queryRecord + 8));
    if (gld_isStampRetiredResult == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,queryRecord + 8,1,0,0);
      return;
    }
  }
  return;
}

/* _gldDestroyQuery @ 0x9c80 (76 bytes) */
int _gldDestroyQuery(ctx, query)
  int ctx;
  uint *query;
{
  uint bitIndex;
  uint wordOffset;
  
  wordOffset = *query >> 3 & 0x1ffffffc;
  bitIndex = *query & 0x1f;
  *(uint *)(wordOffset + *(int *)(ctx + GLD_queryBitmap)) =
       (-2 << bitIndex | 0xfffffffeU >> 0x20 - bitIndex) & *(uint *)(wordOffset + *(int *)(ctx + GLD_queryBitmap));
  _free(query);
  return 0;
}

/* gld_releaseQueryMemory @ 0x9cd0 (152 bytes) */
int gld_releaseQueryMemory(ctx)
  int ctx;
{
  int updatedRefCount;
  int *refCountSlot;
  int oldRefCount;
  int memory;
  char reservation;
  byte crBits;
  
  memory = **(int **)(ctx + GLD_queryRecord);
  if (memory != 0) {
    ((int (*)())gld_waitQueryStamp)(ctx);
    refCountSlot = (int *)(memory + 0x10);
    do {
      oldRefCount = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (oldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,memory,1,0,0);
      **(undefined4 **)(ctx + GLD_queryRecord) = 0;
    }
  }
  return 0;
}

/* gld_setQueryAgpRefBacking @ 0x9d70 (248 bytes) */
int gld_setQueryAgpRefBacking(ctx, record, addressWord, sizeWord, limitWord)
  int ctx;
  int *record;
  int addressWord;
  int sizeWord;
  int limitWord;
{
  int updatedRefCount;
  int *refCountSlot;
  int status;
  int oldMemory;
  char reservation;
  byte crBits;
  undefined4 structOutSize;
  undefined1 structOut0 [4];
  int newMemory;
  
  record[2] = addressWord;
  record[3] = sizeWord;
  record[1] = 6;
  record[4] = limitWord;
  oldMemory = *record;
  *record = 0;
  structOutSize = 8;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + GLD_connect),10,record + 1,0x14,structOut0,&structOutSize);
  if (status == 0) {
    *record = newMemory;
    refCountSlot = (int *)(newMemory + 0x10);
    do {
      if (reservation != '\0') {
        status = storeWordConditionalIndexed(*refCountSlot + 0x10000,0,refCountSlot);
        *refCountSlot = status;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    *(undefined1 *)(newMemory + 0x14) = 1;
  }
  if (oldMemory != 0) {
    refCountSlot = (int *)(oldMemory + 0x10);
    do {
      status = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(status + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (status == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,oldMemory,1,0,0);
    }
  }
  return 1;
}

/* _gldCreateQuery @ 0x9e70 (532 bytes) */
int _gldCreateQuery(ctx, queryOut)
  int ctx;
  undefined4 *queryOut;
{
  int wordIndex;
  int *query;
  int wordByteOffset;
  undefined4 scratchUint4;
  uint *bitmap;
  uint bitmapWord;
  uint *bitmapCursor;
  uint freeBitIndex;
  uint scanCounter;
  int bitsLeft;
  
  query = (int *)_malloc(4);
  *query = 0;
  do {
    scanCounter = *(uint *)(ctx + GLD_queryCapacity) >> 5;
    if (scanCounter != 0) {
      bitmap = *(uint **)(ctx + GLD_queryBitmap);
      bitmapWord = *bitmap;
      if (bitmapWord != 0xffffffff) {
        wordIndex = 0;
        wordByteOffset = 0;
loopSetBitsLeft:
        bitsLeft = 0x20;
        scanCounter = 0;
        break;
      }
      wordIndex = 0;
      bitmapCursor = bitmap;
      while( true ) {
        wordIndex = wordIndex + 1;
        bitmapCursor = bitmapCursor + 1;
        scanCounter = scanCounter - 1;
        if (scanCounter == 0) break;
        bitmapWord = *bitmapCursor;
        wordByteOffset = wordIndex * 4;
        if (bitmapWord != 0xffffffff) goto loopSetBitsLeft;
      }
    }
    if ((*(int *)(ctx + GLD_queryRecord) == 0) && (wordByteOffset = ((int (*)())gldAllocQueryRecord)(ctx), wordByteOffset == 0x2720)) {
loopCallFree:
      _free(query);
      *queryOut = 0;
      return 0x2720;
    }
    if (*(int *)(ctx + GLD_queryPoolBytes) == 0) {
      *(undefined4 *)(ctx + GLD_queryCapacity) = 0x20;
      *(undefined4 *)(ctx + GLD_queryPoolBytes) = 0x610;
      scratchUint4 = _malloc(0x610);
      *(undefined4 *)(ctx + GLD_queryPool) = scratchUint4;
      _memset(scratchUint4,0,*(undefined4 *)(ctx + GLD_queryPoolBytes));
    }
    else {
      if (**(int **)(ctx + GLD_queryRecord) != 0) {
        ((int (*)())gld_releaseQueryMemory)(ctx);
      }
      wordByteOffset = *(int *)(ctx + GLD_queryCapacity) * 0x40 + 0x210;
      *(int *)(ctx + GLD_queryCapacity) = *(int *)(ctx + GLD_queryCapacity) << 1;
      *(int *)(ctx + GLD_queryPoolBytes) = wordByteOffset;
      wordByteOffset = _realloc(*(undefined4 *)(ctx + GLD_queryPool),wordByteOffset);
      *(int *)(ctx + GLD_queryPool) = wordByteOffset;
      if (wordByteOffset == 0) goto loopCallFree;
    }
    wordByteOffset = ((int (*)())gld_setQueryAgpRefBacking)(ctx,*(undefined4 *)(ctx + GLD_queryRecord),*(undefined4 *)(ctx + GLD_queryPool),
                         *(undefined4 *)(ctx + GLD_queryPool),*(undefined4 *)(ctx + GLD_queryPoolBytes));
    if (wordByteOffset != 1) goto loopCallFree;
    noop_2b3b0(ctx);
    bitmapWord = *(uint *)(ctx + GLD_queryCapacity);
    scanCounter = bitmapWord >> 3;
    if (*(int *)(ctx + GLD_queryBitmap) == 0) {
      scratchUint4 = _malloc(scanCounter);
      *(undefined4 *)(ctx + GLD_queryBitmap) = scratchUint4;
      _memset(scratchUint4,0,scanCounter);
    }
    else {
      wordByteOffset = _realloc(*(int *)(ctx + GLD_queryBitmap),scanCounter);
      bitmapWord = bitmapWord >> 4;
      *(int *)(ctx + GLD_queryBitmap) = wordByteOffset;
      _memset(wordByteOffset + bitmapWord,0,bitmapWord);
    }
  } while( true );
  while( true ) {
    freeBitIndex = scanCounter + 1;
    bitsLeft = bitsLeft + -1;
    scanCounter = freeBitIndex;
    if (bitsLeft == 0) break;
    freeBitIndex = scanCounter;
    if ((bitmapWord >> (scanCounter & 0x3f) & 1) == 0) goto storeBitmap;
  }
  scanCounter = 0x20;
storeBitmap:
  *(uint *)((int)bitmap + wordByteOffset) = 1 << (scanCounter & 0x3f) | *(uint *)((int)bitmap + wordByteOffset);
  *queryOut = query;
  *query = freeBitIndex + wordIndex * 0x20;
  return 0;
}

/* gldFormatBitsPerPixel @ 0xa0a0 (68 bytes) */
int gldFormatBitsPerPixel(formatMask)
  uint formatMask;
{
  if ((formatMask & 0x3c) != 0) {
    return 8;
  }
  if ((formatMask & 0x3fc0) != 0) {
    return 0x10;
  }
  if ((formatMask & 0xfc000) != 0) {
    return 0x20;
  }
  if ((formatMask & 0x3f00000) != 0) {
    return 0x40;
  }
  return -(formatMask & 0xc000000) >> 0x18 & 0x80;
}

/* gld_bitsFromRenderFlags @ 0xa0f0 (48 bytes) */
int gld_bitsFromRenderFlags(renderFlags)
  uint renderFlags;
{
  if ((renderFlags & 0x1000) != 0) {
    return 0x20;
  }
  if ((renderFlags & 0x800) != 0) {
    return 0x18;
  }
  if ((renderFlags & 0x400) != 0) {
    return 0x10;
  }
  return renderFlags >> 4 & 8;
}

/* gldFormatAlphaBits @ 0xa120 (92 bytes) */
int gldFormatAlphaBits(formatMask, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  uint formatMask;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  if ((formatMask & 0x400) != 0) {
    return 1;
  }
  if ((formatMask & 0x40000) != 0) {
    return 2;
  }
  if ((formatMask & 0x80) != 0) {
    return 4;
  }
  if ((formatMask & 0x9a928) != 0) {
    return 8;
  }
  if ((formatMask & 0x200000) != 0) {
    return 0xc;
  }
  if ((formatMask & 0x2800000) != 0) {
    return 0x10;
  }
  return formatMask >> 0x16 & 0x20;
}

/* gld_channelBitsForFormat @ 0xa180 (344 bytes) */
int gld_channelBitsForFormat(formatWord, bitsOut, staleArgR5, staleArgR6, staleArgR7, staleArgR8, staleArgR9)
  uint formatWord;
  undefined2 *bitsOut;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  undefined4 staleArgR9;
{
  undefined2 alphaBits;
  
  *bitsOut = 0;
  bitsOut[4] = 0;
  bitsOut[1] = 0;
  bitsOut[2] = 0;
  bitsOut[3] = 0;
  if ((formatWord & 0x3c) == 0) {
    if ((formatWord & 0x1c0) == 0) {
      if ((formatWord & 0xe00) == 0) {
        if ((formatWord & 0x3000) == 0) {
          if ((formatWord & 0x1c000) == 0) {
            if ((formatWord & 0xe0000) == 0) {
              if ((formatWord & 0x300000) == 0) {
                if ((formatWord & 0x2c00000) == 0) {
                  if ((formatWord & 0x8000000) == 0) {
                    return 0;
                  }
                  bitsOut[2] = 0x20;
                  *bitsOut = 0x20;
                  bitsOut[1] = 0x20;
                }
                else {
                  bitsOut[2] = 0x10;
                  *bitsOut = 0x10;
                  bitsOut[1] = 0x10;
                }
              }
              else {
                bitsOut[2] = 0xc;
                *bitsOut = 0xc;
                bitsOut[1] = 0xc;
              }
            }
            else {
              bitsOut[2] = 10;
              *bitsOut = 10;
              bitsOut[1] = 10;
            }
          }
          else {
            bitsOut[2] = 8;
            *bitsOut = 8;
            bitsOut[1] = 8;
          }
        }
        else {
          bitsOut[2] = 5;
          bitsOut[1] = 6;
          *bitsOut = 5;
        }
      }
      else {
        bitsOut[2] = 5;
        *bitsOut = 5;
        bitsOut[1] = 5;
      }
    }
    else {
      bitsOut[2] = 4;
      *bitsOut = 4;
      bitsOut[1] = 4;
    }
  }
  else {
    bitsOut[1] = 3;
    bitsOut[2] = 2;
    *bitsOut = 3;
  }
  alphaBits = ((int (*)())gldFormatAlphaBits)(formatWord,bitsOut,staleArgR5,staleArgR6,staleArgR7,staleArgR8,staleArgR9);
  bitsOut[3] = alphaBits;
  return 1;
}

