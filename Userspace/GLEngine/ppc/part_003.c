#include "decls.h"

/* _gleShrinkFuncCacheElem @ 0x1ecb8 (88 bytes) */
int _gleShrinkFuncCacheElem(glContext, payloadWords)
  int glContext;
  int payloadWords;
{
  int *newElem;
  
  newElem = (int *)_gleDCBRealloc(glContext,payloadWords * 4 + 0x20);
  if (*newElem == glContext) {
    newElem[1] = (int)newElem;
    *newElem = (int)newElem;
  }
  else {
    *(int **)(*newElem + 4) = newElem;
    *(int **)newElem[1] = newElem;
  }
  return (int)newElem;
}

/* _glEndNoMat_Exec @ 0x1ed10 (64 bytes) */
void _glEndNoMat_Exec(glContext)
  int glContext;
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    *(undefined2 *)(glContext + 0x4a10) = 0xffff;
    *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0xd8);
                    
                    
    (**(int ( **)(int))(glContext + 0x4a08))(glContext);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glFlush_Exec @ 0x1ee38 (652 bytes) */
void _glFlush_Exec(int glContext,double forwardedFloatArg1ThenCalleeResult,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79Clear;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyBitArrayWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0001f064;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1ThenCalleeResult = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0001f090;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1ThenCalleeResult,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0001ef68:
    changeWord3 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      dirtyBitArrayWord = *srcCursor;
      srcCursor = srcCursor + 1;
      if (dirtyBitArrayWord != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    changeWord3 = *(uint *)(glContext + 0x31c);
    if ((changeWord3 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0001ef68;
    }
  }
  rendererInfoByte79Clear = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Clear) {
    changeWord3 = changeWord3 & 0x17000000;
  }
  else {
    changeWord3 = changeWord3 & 0x17ffffff;
  }
  if (rendererInfoByte79Clear) {
    noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!noStateChangePending) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0001f064:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *changeWordCursor = 0;
      changeWordCursor = changeWordCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0001f090:
                    
                    
  (**(code **)(glContext + 0x46f4))(*(undefined4 *)(glContext + 0x4688));
  return;
}

/* _glTexSubImage2D_Exec @ 0x1f0c4 (1364 bytes) */
int _glTexSubImage2D_Exec(glContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
  int glContext;
  int target;
  uint level;
  int xoffset;
  int yoffset;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  uint face;
  int levelBase;
  int imageEndOffset;
  int iVar3;
  int callbackResult;
  undefined4 uVar5;
  undefined4 glContextWord4688;
  undefined4 pluginTextureHandle;
  byte levelFlagByte;
  uint mipLevel;
  int mipLevelRecord;
  int pixelUnpackBuffer;
  int textureLevel;
  int bufferSize;
  int fastPathResultThenFaceOffset;
  double bytesPerElement;
  
  iVar3 = glContext;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_0001f180;
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer != 0) {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    bufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar3 = (int)bytesPerElement;
    if (bufferSize < imageEndOffset) {
LAB_0001f180:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
      return iVar3;
    }
    if (iVar3 == 0) {
      iVar3 = _glePixelBytes(format,type);
    }
    if (pixels != (pixels / iVar3) * iVar3) goto LAB_0001f180;
    pixels = pixels + *(int *)(pixelUnpackBuffer + 0x30);
  }
  if (width == 0) {
    return iVar3;
  }
  if (height == 0) {
    return iVar3;
  }
  iVar3 = ((int (*)())_gleCheckTexSubImage2DArgs)(glContext,target,level,xoffset,yoffset,width,height,format,type);
  if (iVar3 == 0) {
    return 0;
  }
  face = target - 0x8515;
  if (5 < face) {
    face = 0;
  }
  levelBase = iVar3 + face * 0x168 + level * 0x18;
  textureLevel = levelBase + 0xc4;
  fastPathResultThenFaceOffset = ((int (*)())_checkFastPath)(glContext,textureLevel,xoffset,yoffset,0,width,height,format,type,pixels)
  ;
  if ((((fastPathResultThenFaceOffset != 0) && ((int)(uint)*(byte *)(iVar3 + 0x8d) <= (int)level)) &&
      ((int)level <= (int)(uint)*(byte *)(iVar3 + 0x8f))) &&
     (fastPathResultThenFaceOffset = face * 2, (*(ushort *)(fastPathResultThenFaceOffset + iVar3 + 0x94) >> (level & 0x3f) & 1) != 0)) {
    if (pixelUnpackBuffer == 0) {
      glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
      pluginTextureHandle = *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4);
    }
    else {
      callbackResult = (**(code **)(glContext + 0x4710))
                        (*(undefined4 *)(glContext + 0x4688),
                         *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4),face,
                         level,xoffset,yoffset,0,width);
      if (callbackResult != 0) goto LAB_0001f388;
      if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
      }
      glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
      pluginTextureHandle = *(undefined4 *)(iVar3 + (uint)*(byte *)(glContext + 0x85a8) * 4);
    }
    callbackResult = (**(code **)(glContext + 0x4710))(glContextWord4688,pluginTextureHandle,face,level,xoffset,yoffset,0,width);
    if (callbackResult != 0) {
LAB_0001f388:
      *(undefined4 *)(iVar3 + 0x20) =
           *(undefined4 *)
            ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
      if (*(int *)(levelBase + 0xd8) != 0) {
        levelFlagByte = *(byte *)(levelBase + 0xcf);
        if (((levelFlagByte & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
          callbackResult = _gleFreeTextureLevel(glContext,iVar3,textureLevel);
          levelFlagByte = *(byte *)(levelBase + 0xcf);
        }
        *(byte *)(levelBase + 0xcf) = levelFlagByte & 0xef;
        *(ushort *)(fastPathResultThenFaceOffset + iVar3 + 0xa0) =
             *(ushort *)(fastPathResultThenFaceOffset + iVar3 + 0xa0) &
             ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
      }
      *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) | 0x40;
      if ((*(uint *)(iVar3 + 0x6c) & 0x8000) == 0) {
        return callbackResult;
      }
      if ((int)*(short *)(iVar3 + 0x60) != level) {
        return callbackResult;
      }
      mipLevel = level + 1;
      if ((int)(uint)*(byte *)(iVar3 + 0x83) < (int)mipLevel) {
        return callbackResult;
      }
      mipLevelRecord = mipLevel * 0x18 + face * 0x168 + iVar3 + 0xc4;
      do {
        if (*(int *)(mipLevelRecord + 0x14) != 0) {
          if (((*(byte *)(mipLevelRecord + 0xb) & 1) == 0) && (*(short *)(iVar3 + 0x3e) == -0x7a43)) {
            callbackResult = _gleFreeTextureLevel(glContext,iVar3,mipLevelRecord);
          }
          *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) & 0xef;
          *(ushort *)(fastPathResultThenFaceOffset + iVar3 + 0xa0) =
               *(ushort *)(fastPathResultThenFaceOffset + iVar3 + 0xa0) & ~(ushort)(1 << (mipLevel & 0x3f));
        }
        mipLevel = mipLevel + 1;
        *(byte *)(mipLevelRecord + 0xb) = *(byte *)(mipLevelRecord + 0xb) | 0x40;
        mipLevelRecord = mipLevelRecord + 0x18;
      } while ((int)mipLevel <= (int)(uint)*(byte *)(iVar3 + 0x83));
      return callbackResult;
    }
  }
  levelFlagByte = *(byte *)(levelBase + 0xcf);
  if ((levelFlagByte & 0x10) == 0) {
    if ((levelFlagByte & 0x40) == 0) {
      if (*(int *)(levelBase + 0xd8) == 0) {
        _gleAllocateTextureLevel(glContext,iVar3,textureLevel);
        levelFlagByte = *(byte *)(levelBase + 0xcf);
      }
      *(byte *)(levelBase + 0xcf) = levelFlagByte | 0x10;
    }
    else {
      _gleUploadPluginTextureLevel
                (glContext,iVar3,textureLevel,face,level,(uint)*(byte *)(glContext + 0x85a8));
    }
  }
  ((int (*)())_gleModifyPluginTextureLevel)(glContext,iVar3,textureLevel,face,level,xoffset,yoffset,0,width,height,1);
  uVar5 = _gleTextureImagePut(glContext,textureLevel,xoffset + (uint)*(byte *)(levelBase + 0xce),
                              yoffset + (uint)*(byte *)(levelBase + 0xce),0,width,height,1,format,
                              type,1,glContext + 0x31cc,pixels);
  if ((((*(uint *)(iVar3 + 0x6c) & 0x8000) != 0) && ((int)*(short *)(iVar3 + 0x60) == level)) &&
     (iVar3 = _gleGenMipmapsToLevel(glContext,iVar3,face,level,0xf,1), uVar5 = 0, iVar3 != 0)) {
    return iVar3;
  }
  *(uint *)(glContext + 0x314) =
       *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  return uVar5;
}

/* _gleCheckTexSubImage2DArgs @ 0x1f618 (484 bytes) */
int _gleCheckTexSubImage2DArgs(glContext, target, level, xoffset, yoffset, width, height, format, type)
  int glContext;
  int target;
  int level;
  uint xoffset;
  uint yoffset;
  uint width;
  uint height;
  int format;
  undefined4 type;
{
  undefined4 glErrorCode;
  int regionOffsetXThenXRangeResult;
  int textureObject;
  int argsCheckThenTextureLevelThenYRangeResult;
  int regionOffsetY;
  
  textureObject = ((int (*)())_gleLookUpNonProxyTexture2D)(glContext,target);
  if (textureObject == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    if ((format != 0x1902) || (*(short *)(textureObject + 0x26) == 0x1902)) {
      argsCheckThenTextureLevelThenYRangeResult = _gleCheckTexSubImageArgs(glContext,level,format,type);
      if (argsCheckThenTextureLevelThenYRangeResult == 0) {
        return 0;
      }
      argsCheckThenTextureLevelThenYRangeResult = textureObject + 0xc4 + level * 0x18;
      if (target - 0x8515U < 6) {
        argsCheckThenTextureLevelThenYRangeResult = textureObject + 0xc4 + target * 0x168 + level * 0x18 + -0xbb2588;
      }
      if (((*(byte *)(argsCheckThenTextureLevelThenYRangeResult + 0xb) & 0x20) != 0) &&
         ((*(short *)(argsCheckThenTextureLevelThenYRangeResult + 0x12) != 0 ||
          (((((width & 3) == 0 || (width == *(ushort *)(argsCheckThenTextureLevelThenYRangeResult + 4))) &&
            (((height & 3) == 0 || (height == *(ushort *)(argsCheckThenTextureLevelThenYRangeResult + 6))))) &&
           (((xoffset & 3) == 0 && ((yoffset & 3) == 0)))))))) {
        if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
          if (((*(uint *)(glContext + 0x3410) & 4) == 0) || (*(short *)(glContext + 0x3348) != -0x7fea))
          goto LAB_0001f79c;
          regionOffsetY = *(int *)(glContext + 0x3354);
          regionOffsetXThenXRangeResult = *(int *)(glContext + 0x3350);
        }
        else {
          if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_0001f79c;
          regionOffsetY = *(int *)(glContext + 0x3314);
          regionOffsetXThenXRangeResult = *(int *)(glContext + 0x3310);
        }
        width = (width - regionOffsetXThenXRangeResult) + 1;
        height = (height - regionOffsetY) + 1;
LAB_0001f79c:
        regionOffsetXThenXRangeResult = ((int (*)())_gleCheckTexSubImageRange)(glContext,argsCheckThenTextureLevelThenYRangeResult,xoffset,width,(uint)*(ushort *)(argsCheckThenTextureLevelThenYRangeResult + 4));
        if (regionOffsetXThenXRangeResult == 0) {
          return 0;
        }
        argsCheckThenTextureLevelThenYRangeResult = ((int (*)())_gleCheckTexSubImageRange)(glContext,argsCheckThenTextureLevelThenYRangeResult,yoffset,height,(uint)*(ushort *)(argsCheckThenTextureLevelThenYRangeResult + 6));
        if (argsCheckThenTextureLevelThenYRangeResult != 0) {
          return textureObject;
        }
        return 0;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleLookUpNonProxyTexture2D @ 0x1f7fc (144 bytes) */
int _gleLookUpNonProxyTexture2D(glContext, target)
  int glContext;
  uint target;
{
  uint targetCompareConstant;
  int textureUnitThenTextureObject;
  
  textureUnitThenTextureObject = *(int *)(glContext + 0x53d4);
  if (target == 0x8513) {
LAB_0001f860:
    textureUnitThenTextureObject = *(int *)(textureUnitThenTextureObject * 0x14 + glContext + 0x5154);
  }
  else {
    if (target < 0x8514) {
      if (target == 0xde1) {
        textureUnitThenTextureObject = *(int *)(textureUnitThenTextureObject * 0x14 + glContext + 0x5160);
        goto LAB_0001f86c;
      }
      targetCompareConstant = 0x84f5;
    }
    else {
      if (target < 0x8515) {
        return 0;
      }
      if (target < 0x851b) goto LAB_0001f860;
      targetCompareConstant = 0x85b3;
    }
    if (target != targetCompareConstant) {
      return 0;
    }
    textureUnitThenTextureObject = *(int *)(textureUnitThenTextureObject * 0x14 + glContext + 0x515c);
  }
LAB_0001f86c:
  return textureUnitThenTextureObject + 0x10;
}

/* _gleCheckTexSubImageRange @ 0x1f88c (76 bytes) */
int _gleCheckTexSubImageRange(glContext, textureLevel, offset, extent, levelExtent)
  int glContext;
  int textureLevel;
  int offset;
  int extent;
  int levelExtent;
{
  if (((-1 < extent) && ((int)-(uint)*(byte *)(textureLevel + 10) <= offset)) &&
     (offset + extent <= (int)(levelExtent + (uint)*(byte *)(textureLevel + 10)))) {
    return 1;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return 0;
}

/* _checkFastPath @ 0x1f8d8 (260 bytes) */
int _checkFastPath(glContext, textureLevel, xoffset, yoffset, zoffset, width, height, format, type, pixels)
  int glContext;
  int textureLevel;
  int xoffset;
  int yoffset;
  int zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  ushort levelHeight;
  ushort levelWidth;
  int pixelBytes;
  int rowBytes;
  int levelData;
  int packRowBytes;
  undefined1 packRowPadding [4];
  undefined1 packImageBytes [4];
  undefined1 packImagePadding [4];
  undefined1 packPixelBytes [4];
  int packStartOffset [4];
  
  if ((*(byte *)(textureLevel + 0xb) & 1) != 0) {
    pixelBytes = _glePixelBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
    rowBytes = _gleRowBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                         (uint)*(ushort *)(textureLevel + 0xc));
    levelHeight = *(ushort *)(textureLevel + 0xe);
    levelWidth = *(ushort *)(textureLevel + 0xc);
    levelData = *(int *)(textureLevel + 0x14);
    _glePixelPackSettings
              (glContext,format,type,width,height,glContext + 0x31cc,packPixelBytes,packStartOffset,
               &packRowBytes,packRowPadding,packImageBytes,packImagePadding);
    if ((pixels + packStartOffset[0] ==
         levelData + pixelBytes * ((uint)levelWidth * ((uint)levelHeight * zoffset + yoffset) + xoffset)) &&
       (packRowBytes == rowBytes)) {
      return 0;
    }
  }
  return 1;
}

/* _gleModifyPluginTextureLevel @ 0x1f9dc (376 bytes) */
int _gleModifyPluginTextureLevel(glContext, param_2, param_3, param_4, level, forwardedArg6, yoffset, forwardedArg8, forwardedArg9, height, unusedArg11)
  int glContext;
  undefined4 *param_2;
  int *param_3;
  int param_4;
  uint level;
  undefined4 forwardedArg6;
  undefined4 yoffset;
  undefined4 forwardedArg8;
  undefined4 forwardedArg9;
  undefined4 height;
  undefined4 unusedArg11;
{
  int loopIndex2;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  int loopIndex;
  
  if ((*(byte *)((int)param_3 + 0xb) & 0x10) == 0) {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) &
            ((ushort)(-2 << (level & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (level & 0x1f)));
  }
  else {
    iVar3 = param_4 * 2 + (int)param_2;
    uVar5 = *(ushort *)(iVar3 + 0xa0) | *(ushort *)(iVar3 + 0x94) & (ushort)(1 << (level & 0x3f));
  }
  *(ushort *)(iVar3 + 0xa0) = uVar5;
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      uVar4 = *param_2;
      iVar3 = iVar3 + 0x2e0;
      loopIndex = loopIndex + 1;
      param_2 = param_2 + 1;
      (**(code **)(*piVar1 + 0x158))(*puVar2,uVar4,param_4,level,forwardedArg6,yoffset,forwardedArg8,forwardedArg9);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if ((*(byte *)((int)param_3 + 0xb) & 0x80) != 0) {
    loopIndex2 = 0;
    iVar3 = *(int *)(glContext + 0x744c) + 0x10;
    *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        loopIndex2 = loopIndex2 + 1;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  *param_3 = *param_3 + 1;
  return;
}

/* _glTestObjectAPPLE_Exec @ 0x1fb54 (304 bytes) */
int _glTestObjectAPPLE_Exec(glContext, object, name)
  int glContext;
  uint object;
  undefined4 name;
{
  undefined4 objectKindThenTestResult;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return 1;
  }
  if (object == 0x8a0a) {
    return 1;
  }
  if (object < 0x8a0b) {
    if (object == 0x8074) {
      objectKindThenTestResult = 2;
    }
    else if (object < 0x8075) {
      if (object != 0x1702) {
LAB_0001fc50:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
        }
        return 0;
      }
      objectKindThenTestResult = 1;
    }
    else {
      if (object != 0x85b3) goto LAB_0001fc50;
      objectKindThenTestResult = 3;
    }
  }
  else if (object == 0x8d40) {
    objectKindThenTestResult = 5;
  }
  else if (object < 0x8d41) {
    if (object != 0x8a0b) goto LAB_0001fc50;
    objectKindThenTestResult = 0;
  }
  else {
    if (object != 0x8d41) goto LAB_0001fc50;
    objectKindThenTestResult = 4;
  }
  objectKindThenTestResult = ((int (*)())_gleTestObject)(glContext,objectKindThenTestResult,name);
  return objectKindThenTestResult;
}

/* _gleTestObject @ 0x1fc84 (760 bytes) */
int _gleTestObject(glContext, objectType, name)
  int glContext;
  undefined4 objectType;
  undefined4 name;
{
  uint loopIndex5;
  uint loopIndex4;
  uint loopIndex3;
  uint loopIndex2;
  bool stillValid;
  int returnValue;
  int hashObjectThenRendererTestResult;
  int rendererBase;
  int allValid;
  undefined4 *srcCursor;
  uint loopIndex;
  
  allValid = 1;
  returnValue = 1;
  switch(objectType) {
  case 0:
    hashObjectThenRendererTestResult = _gleLookupHashObject(glContext + 0x543c,name);
    if (hashObjectThenRendererTestResult == 0) {
LAB_0001ff68:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else {
      rendererBase = glContext + 0x10000;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        srcCursor = (undefined4 *)(hashObjectThenRendererTestResult + 0x10);
        do {
          stillValid = allValid != 0;
          allValid = 0;
          if ((stillValid) &&
             (hashObjectThenRendererTestResult = (**(code **)(*(int *)(rendererBase + -0x777c) + 0x1c0))
                                (*(undefined4 *)(rendererBase + -0x7a54),objectType,*srcCursor), hashObjectThenRendererTestResult != 0)) {
            allValid = 1;
          }
          loopIndex = loopIndex + 1;
          rendererBase = rendererBase + 0x2e0;
          srcCursor = srcCursor + 1;
        } while (loopIndex < *(byte *)(glContext + 0x85a4));
      }
    }
    break;
  case 1:
    hashObjectThenRendererTestResult = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,name);
    if (hashObjectThenRendererTestResult == 0) goto LAB_0001ff68;
    rendererBase = glContext + 0x10000;
    loopIndex2 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      srcCursor = (undefined4 *)(hashObjectThenRendererTestResult + 0x10);
      do {
        stillValid = allValid != 0;
        allValid = 0;
        if ((stillValid) &&
           (hashObjectThenRendererTestResult = (**(code **)(*(int *)(rendererBase + -0x777c) + 0x1c0))
                              (*(undefined4 *)(rendererBase + -0x7a54),objectType,*srcCursor), hashObjectThenRendererTestResult != 0)) {
          allValid = 1;
        }
        loopIndex2 = loopIndex2 + 1;
        rendererBase = rendererBase + 0x2e0;
        srcCursor = srcCursor + 1;
      } while (loopIndex2 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 2:
    hashObjectThenRendererTestResult = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x5014,name);
    if (hashObjectThenRendererTestResult == 0) goto LAB_0001ff68;
    rendererBase = glContext + 0x10000;
    loopIndex3 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      srcCursor = (undefined4 *)(hashObjectThenRendererTestResult + 0x10);
      do {
        stillValid = allValid != 0;
        allValid = 0;
        if ((stillValid) &&
           (hashObjectThenRendererTestResult = (**(code **)(*(int *)(rendererBase + -0x777c) + 0x1c0))
                              (*(undefined4 *)(rendererBase + -0x7a54),objectType,*srcCursor), hashObjectThenRendererTestResult != 0)) {
          allValid = 1;
        }
        loopIndex3 = loopIndex3 + 1;
        rendererBase = rendererBase + 0x2e0;
        srcCursor = srcCursor + 1;
      } while (loopIndex3 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 3:
    hashObjectThenRendererTestResult = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x701c,name);
    if (hashObjectThenRendererTestResult == 0) goto LAB_0001ff68;
    rendererBase = glContext + 0x10000;
    loopIndex4 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      srcCursor = (undefined4 *)(hashObjectThenRendererTestResult + 0x10);
      do {
        stillValid = allValid != 0;
        allValid = 0;
        if ((stillValid) &&
           (hashObjectThenRendererTestResult = (**(code **)(*(int *)(rendererBase + -0x777c) + 0x1c0))
                              (*(undefined4 *)(rendererBase + -0x7a54),objectType,*srcCursor), hashObjectThenRendererTestResult != 0)) {
          allValid = 1;
        }
        loopIndex4 = loopIndex4 + 1;
        rendererBase = rendererBase + 0x2e0;
        srcCursor = srcCursor + 1;
      } while (loopIndex4 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 4:
    hashObjectThenRendererTestResult = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148),name);
    if (hashObjectThenRendererTestResult == 0) goto LAB_0001ff68;
    rendererBase = glContext + 0x10000;
    loopIndex5 = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      srcCursor = (undefined4 *)(hashObjectThenRendererTestResult + 0x10);
      do {
        stillValid = allValid != 0;
        allValid = 0;
        if ((stillValid) &&
           (hashObjectThenRendererTestResult = (**(code **)(*(int *)(rendererBase + -0x777c) + 0x1c0))
                              (*(undefined4 *)(rendererBase + -0x7a54),objectType,*srcCursor), hashObjectThenRendererTestResult != 0)) {
          allValid = 1;
        }
        loopIndex5 = loopIndex5 + 1;
        rendererBase = rendererBase + 0x2e0;
        srcCursor = srcCursor + 1;
      } while (loopIndex5 < *(byte *)(glContext + 0x85a4));
    }
    break;
  case 5:
    break;
  default:
    goto switchD_0001fcd0_default;
  }
  returnValue = allValid;
switchD_0001fcd0_default:
  return returnValue;
}

/* _glDeleteTextures_Exec_body @ 0x1ff98 (572 bytes) */
void _glDeleteTextures_Exec_body(glContext, n, textures)
  int glContext;
  int n;
  int *textures;
{
  uint loopIndex3;
  int *cursor;
  undefined4 glErrorCode;
  int iVar2;
  int sharedState;
  int framebufferObject;
  uint loopIndex4;
  int *srcCursor;
  int *piVar6;
  int iVar7;
  int loopIndex;
  int iVar9;
  int iVar10;
  uint loopIndex2;
  int iVar12;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (n == 0) {
        return;
      }
      sharedState = *(int *)(glContext + 0x5148);
      piVar6 = (int *)0x0;
      iVar7 = sharedState + 0x2008;
      if (*(char *)(sharedState + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedState + 0x8028);
      }
      framebufferObject = *(int *)(glContext + 0x744c);
      if (framebufferObject != 0) {
        piVar6 = (int *)(framebufferObject + 0xd4);
      }
      loopIndex = 0;
      iVar9 = *textures;
      iVar10 = iVar9;
      if (0 < n) {
        do {
          if (*textures == 0) {
            ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
            iVar9 = textures[1];
            iVar10 = iVar9 + -1;
          }
          else {
            loopIndex2 = 0;
            iVar12 = glContext;
            do {
              srcCursor = (int *)(iVar12 + 0x5154);
              loopIndex4 = 0;
              do {
                if (*(int *)(*srcCursor + 4) == *textures) {
                  _gleBindTexture(glContext,loopIndex4,0,loopIndex2);
                  break;
                }
                loopIndex4 = loopIndex4 + 1;
                srcCursor = srcCursor + 1;
              } while (loopIndex4 < 5);
              loopIndex2 = loopIndex2 + 1;
              iVar12 = iVar12 + 0x14;
            } while (loopIndex2 < 0x10);
            if ((framebufferObject != 0) && (iVar12 = _gleLookupHashObject(iVar7,*textures), iVar12 != 0)) {
              loopIndex3 = 0;
              cursor = piVar6;
              do {
                iVar2 = *cursor;
                cursor = cursor + 1;
                if (iVar12 == iVar2) {
                  _gleFramebufferTexture(glContext,loopIndex3,0,0,0,0,0);
                }
                loopIndex3 = loopIndex3 + 1;
              } while (loopIndex3 < 6);
            }
            if (*textures != iVar10) {
              ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
              iVar9 = *textures;
              iVar10 = iVar9;
            }
          }
          loopIndex = loopIndex + 1;
          textures = textures + 1;
          iVar10 = iVar10 + 1;
        } while (loopIndex < n);
      }
      ((void (*)())_gleDeleteHashNamesAndObjects)(glContext,iVar7,iVar9,iVar10 - iVar9);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleDeleteHashNamesAndObjects @ 0x201d4 (340 bytes) */
void _gleDeleteHashNamesAndObjects(glContext, hashTable, list, listRange)
  undefined4 glContext;
  int hashTable;
  uint list;
  int listRange;
{
  uint hashName;
  int *nextRangeNode;
  int referenceCount;
  int hashObject;
  int *previousLink;
  int *allocatedBlock;
  uint deleteEnd;
  uint overlapStart;
  uint rangeEndName;
  uint rangeFirstName;
  uint overlapEnd;
  int *rangeNode;
  
  deleteEnd = list + listRange;
  nextRangeNode = (int *)*(int *)(hashTable + 0x1000);
  previousLink = (int *)(hashTable + 0x1000);
  do {
    while( true ) {
      rangeNode = nextRangeNode;
      if (rangeNode == (int *)0x0) {
        return;
      }
      rangeFirstName = rangeNode[1];
      rangeEndName = rangeFirstName + rangeNode[2];
      if (deleteEnd <= rangeFirstName) {
        return;
      }
      if (list < rangeEndName) break;
LAB_00020304:
      nextRangeNode = (int *)*rangeNode;
      previousLink = rangeNode;
    }
    overlapStart = list;
    if (list < rangeFirstName) {
      overlapStart = rangeFirstName;
    }
    hashName = overlapStart;
    overlapEnd = deleteEnd;
    if (rangeEndName < deleteEnd) {
      overlapEnd = rangeEndName;
    }
    for (; hashName < overlapEnd; hashName = hashName + 1) {
      hashObject = ((int (*)())_gleRemoveHashObject)(hashTable,hashName);
      if ((hashObject != 0) &&
         (referenceCount = *(int *)(hashObject + 8) + -1, *(int *)(hashObject + 8) = referenceCount, referenceCount == 0)) {
        (**(code **)(hashObject + 0xc))(glContext);
      }
    }
    if (rangeFirstName < overlapStart) {
      rangeNode[2] = overlapStart - rangeFirstName;
      if (overlapEnd < rangeEndName) {
        allocatedBlock = (int *)_malloc(0xc);
        hashObject = *rangeNode;
        allocatedBlock[1] = overlapEnd;
        *allocatedBlock = hashObject;
        allocatedBlock[2] = rangeEndName - overlapEnd;
        *rangeNode = (int)allocatedBlock;
        rangeNode = allocatedBlock;
      }
      goto LAB_00020304;
    }
    if (overlapEnd < rangeEndName) {
      rangeNode[1] = overlapEnd;
      rangeNode[2] = rangeEndName - overlapEnd;
      goto LAB_00020304;
    }
    *previousLink = *rangeNode;
    _free(rangeNode);
    nextRangeNode = (int *)*previousLink;
  } while( true );
}

/* _gleRemoveHashObject @ 0x20328 (120 bytes) */
int _gleRemoveHashObject(hashTable, objectName)
  int hashTable;
  uint objectName;
{
  int *entry;
  int *bucketHeadThenPreviousEntry;
  int bucketOffset;
  
  bucketOffset = (objectName & 0x3ff) * 4;
  bucketHeadThenPreviousEntry = *(int **)(bucketOffset + hashTable);
  if (bucketHeadThenPreviousEntry == (int *)0x0) {
    return (int *)0x0;
  }
  if (bucketHeadThenPreviousEntry[1] != objectName) {
    entry = (int *)*bucketHeadThenPreviousEntry;
    while( true ) {
      if (entry == (int *)0x0) {
        return (int *)0x0;
      }
      if (entry[1] == objectName) break;
      bucketHeadThenPreviousEntry = entry;
      entry = (int *)*entry;
    }
    *bucketHeadThenPreviousEntry = *entry;
    return entry;
  }
  *(int *)(bucketOffset + hashTable) = *bucketHeadThenPreviousEntry;
  return bucketHeadThenPreviousEntry;
}

/* _gleFreeTextureObject @ 0x203a0 (256 bytes) */
void _gleFreeTextureObject(glContext, textureObject)
  undefined4 glContext;
  int textureObject;
{
  ushort textureFlags;
  int faceCount;
  int pluginTextureHandles;
  int loopIndex;
  int loopIndex2;
  int remaining;
  int levelRecord;
  
  pluginTextureHandles = textureObject + 0x10;
  ((void (*)())_gleDeletePluginTexture)(glContext,pluginTextureHandles);
  textureFlags = *(ushort *)(textureObject + 0x34);
  if ((textureFlags & 0x100) == 0) {
    if ((*(int *)(textureObject + 0xd0) != 0) && ((*(byte *)(textureObject + 199) & 7) == 0)) {
      _gleFreeTextureLevel(glContext,pluginTextureHandles,textureObject + 0xbc);
      textureFlags = *(ushort *)(textureObject + 0x34);
    }
    faceCount = 0;
    if ((textureFlags & 0x200) == 0) {
      faceCount = 1;
      if ((textureFlags & 0x2000) == 0) {
        faceCount = 6;
        if ((textureFlags & 0xf) != 0) {
          faceCount = 1;
        }
      }
    }
    loopIndex = 0;
    if (faceCount != 0) {
      loopIndex2 = 0;
      do {
        remaining = 0xe;
        levelRecord = textureObject + loopIndex2 + 0xd4;
        do {
          if ((*(int *)(levelRecord + 0x14) != 0) && ((*(byte *)(levelRecord + 0xb) & 7) == 0)) {
            _gleFreeTextureLevel(glContext,pluginTextureHandles,levelRecord);
          }
          remaining = remaining + -1;
          levelRecord = levelRecord + 0x18;
        } while (-1 < remaining);
        loopIndex = loopIndex + 1;
        loopIndex2 = loopIndex2 + 0x168;
      } while (loopIndex < faceCount);
    }
  }
  _free(textureObject);
  return;
}

/* _gleDeletePluginTexture @ 0x204a0 (120 bytes) */
void _gleDeletePluginTexture(glContext, rendererHandles)
  int glContext;
  int rendererHandles;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int slotByteOffset;
  int rendererRecordCursor;
  int loopIndex;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      slotByteOffset = loopIndex * 4;
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererCallbacks + 0x168))(*rendererHandlePtr,*(undefined4 *)(slotByteOffset + rendererHandles));
      *(undefined4 *)(slotByteOffset + rendererHandles) = 0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleSetEnable_SCISSOR_TEST @ 0x20518 (72 bytes) */
void _gleSetEnable_SCISSOR_TEST(int glContext,undefined4 unusedArg2,uint enable,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (*(byte *)(glContext + 0x34f0) != enable) {
    *(char *)(glContext + 0x34f0) = (char)enable;
    ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000000;
  }
  return;
}

/* _glScissor_Exec @ 0x20560 (144 bytes) */
void _glScissor_Exec(int glContext,undefined4 x,undefined4 y,int width,int height,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < width) && (-1 < height)) {
      *(undefined4 *)(glContext + 0x34e0) = x;
      *(undefined4 *)(glContext + 0x34e4) = y;
      *(int *)(glContext + 0x34e8) = width;
      *(int *)(glContext + 0x34ec) = height;
      ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x4000000;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleMoveFuncCacheElem @ 0x205f0 (44 bytes) */
void _gleMoveFuncCacheElem(listHead, elem)
  int listHead;
  int *elem;
{
  undefined4 *tailElem;
  int *previousElem;
  
  previousElem = (int *)elem[1];
  *previousElem = *elem;
  *(int **)(*elem + 4) = previousElem;
  tailElem = *(undefined4 **)(listHead + 4);
  *tailElem = elem;
  elem[1] = (int)tailElem;
  *elem = listHead;
  *(int **)(listHead + 4) = elem;
  return;
}

/* _gliSetInteger @ 0x2061c (2408 bytes) */
int _gliSetInteger(glContext, stateId, valuePtr)
  int glContext;
  uint stateId;
  int *valuePtr;
{
  int loopIndex2;
  int loopIndex;
  byte levelFlagByte;
  ushort textureFlags;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined4 funcCache;
  undefined4 baseFormat;
  int checkedTextureObject;
  int mipmapSource;
  int iVar7;
  int width;
  undefined1 uVar8;
  int iVar9;
  int firstPluginError;
  int textureObject;
  int levelBase;
  int surfaceHandle;
  int newCacheLimit;
  int glContextWord5408;
  int level;
  int faceCount;
  int surfaceHandle2;
  int depth;
  int textureLevel;
  int iVar13;
  int internalformat;
  uint targetThenFace;
  int levelRecord2;
  int height;
  
  firstPluginError = 0;
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  if (valuePtr == (int *)0x0) {
    return 0x271e;
  }
  if (stateId == 0x176) {
    newCacheLimit = *valuePtr;
    if (newCacheLimit < 1) {
      return 0x2718;
    }
    *(short *)(glContext + 0x49c0) = (short)newCacheLimit;
    if (*(short *)(glContext + 0x49c2) <= newCacheLimit) {
      return 0;
    }
    funcCache = *(undefined4 *)(glContext + 0x49b8);
    iVar13 = *(short *)(glContext + 0x49c2) - newCacheLimit;
    *(short *)(glContext + 0x49c2) = (short)newCacheLimit;
LAB_0002085c:
    _gleShrinkFuncCache(funcCache,iVar13);
  }
  else {
    if (stateId < 0x177) {
      if (stateId == 0x133) {
        *(char *)(glContext + 0x5410) = '\x01' - (*valuePtr == 0);
        return 0;
      }
      if (0x133 < stateId) {
        if (stateId == 0x162) {
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 4) {
            return 0x2718;
          }
          *(short *)(glContext + 0x5098) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x509a) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x5094);
          iVar13 = *(short *)(glContext + 0x509a) - newCacheLimit;
          *(short *)(glContext + 0x509a) = (short)newCacheLimit;
        }
        else if (stateId < 0x163) {
          if (stateId == 0x134) {
            _gleReclaimContextResources(glContext);
            return 0;
          }
          if (stateId != 0x15e) goto LAB_00020f04;
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 4) {
            return 0x2718;
          }
          *(short *)(glContext + 0x508c) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x508e) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x5088);
          iVar13 = *(short *)(glContext + 0x508e) - newCacheLimit;
          *(short *)(glContext + 0x508e) = (short)newCacheLimit;
        }
        else if (stateId == 0x16a) {
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48b4) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x48b6) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x48b0);
          iVar13 = *(short *)(glContext + 0x48b6) - newCacheLimit;
          *(short *)(glContext + 0x48b6) = (short)newCacheLimit;
        }
        else if (stateId < 0x16b) {
          if (stateId != 0x166) goto LAB_00020f04;
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x50a4) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x50a6) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x50a0);
          iVar13 = *(short *)(glContext + 0x50a6) - newCacheLimit;
          *(short *)(glContext + 0x50a6) = (short)newCacheLimit;
        }
        else {
          if (stateId != 0x172) goto LAB_00020f04;
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x49bc) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x49be) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x49b4);
          iVar13 = *(short *)(glContext + 0x49be) - newCacheLimit;
          *(short *)(glContext + 0x49be) = (short)newCacheLimit;
        }
        goto LAB_0002085c;
      }
      if (stateId == 0xe5) {
        *(char *)(glContext + 0x4693) = '\x01' - (*valuePtr == 0);
        return 0;
      }
      if (stateId < 0xe6) {
        if (stateId == 0xdd) {
          uVar8 = 0;
          *(char *)(glContext + 0x4690) = '\x01' - (*valuePtr == 0);
          if ((*(char *)(glContext + 0x4690) == '\0') || (*(int *)(glContext + 0x4848) == 0)) {
            uVar8 = 1;
          }
          uVar4 = 0;
          *(undefined1 *)(glContext + 0x4692) = uVar8;
          if ((*(int *)(glContext + 0x4e1c) == 0x1c00) && (*(char *)(glContext + 0x4692) == '\0')) {
            uVar4 = 1;
          }
          *(undefined1 *)(glContext + 0x4691) = uVar4;
          *(undefined4 *)(glContext + 0x757c) = 0xffffffff;
          _gliSetCurrentPluginDispatchTable(glContext);
          return 0;
        }
        if (stateId == 0xe4) {
          *(int *)(glContext + 0x7590) = *valuePtr;
          return 0;
        }
LAB_00020f04:
        iVar13 = glContext + 0x10000;
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            iVar7 = (**(code **)(*(int *)(iVar13 + -0x777c) + 0x140))
                              (*(undefined4 *)(iVar13 + -0x7a54),stateId,valuePtr);
            if ((iVar7 != 0) && (firstPluginError == 0)) {
              firstPluginError = iVar7;
            }
            loopIndex = loopIndex + 1;
            iVar13 = iVar13 + 0x2e0;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          return firstPluginError;
        }
        return 0;
      }
      if (stateId != 0x128) {
        if (stateId == 0x132) {
          *(char *)(glContext + 0x4694) = '\x01' - (*valuePtr == 0);
        }
        goto LAB_00020f04;
      }
      if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00020c88;
      targetThenFace = valuePtr[1];
      iVar9 = valuePtr[7];
      surfaceHandle = *valuePtr;
      level = valuePtr[2];
      internalformat = valuePtr[3];
      width = valuePtr[4];
      height = valuePtr[5];
      depth = valuePtr[6];
      if (targetThenFace == 0xde1) {
LAB_00020a7c:
        checkedTextureObject = _gleCheckTexImage2DArgs
                          (glContext,targetThenFace,level,internalformat,width,height,iVar9,0x80e1,0x1401);
      }
      else if (targetThenFace < 0xde2) {
        if (targetThenFace != 0xde0) {
          return 0x2717;
        }
        checkedTextureObject = _gleCheckTexImage1DArgs(glContext,0xde0,level,internalformat,width,iVar9,0x80e1,0x1401);
      }
      else {
        if (targetThenFace != 0x806f) {
          if (targetThenFace != 0x84f5) {
            return 0x2717;
          }
          goto LAB_00020a7c;
        }
        checkedTextureObject = ((int (*)())_gleCheckTexImage3DArgs)(glContext,0x806f,level,internalformat,width,height,depth,iVar9,0x80e1,0x1401);
      }
      if (checkedTextureObject == 0) {
        return 0;
      }
      textureFlags = *(ushort *)(checkedTextureObject + 0x24);
      if ((textureFlags & 0x3c00) != 0x800) {
        if ((textureFlags & 0x3c00) == 0) {
          *(ushort *)(checkedTextureObject + 0x24) = textureFlags | 0x800;
        }
        else if ((textureFlags & 0x1400) != 0) {
LAB_00020c88:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x502;
          }
          return 0x2717;
        }
      }
      *(int *)(checkedTextureObject + 0x2c) = surfaceHandle;
      targetThenFace = targetThenFace - 0x8515;
      if (5 < targetThenFace) {
        targetThenFace = 0;
      }
      levelBase = checkedTextureObject + targetThenFace * 0x168 + level * 0x18;
      levelRecord2 = levelBase + 0xc4;
      if ((*(byte *)(levelBase + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,checkedTextureObject,levelRecord2,targetThenFace,level);
        if (*(int *)(levelBase + 0xd8) != 0) {
          levelFlagByte = *(byte *)(levelBase + 0xcf);
          if ((levelFlagByte & 1) == 0) {
            _gleFreeTextureLevel(glContext,checkedTextureObject,levelRecord2);
            levelFlagByte = *(byte *)(levelBase + 0xcf);
          }
          else {
            *(undefined4 *)(levelBase + 0xd8) = 0;
          }
          *(byte *)(levelBase + 0xcf) = levelFlagByte & 0xef;
        }
        *(byte *)(levelBase + 0xcf) = *(byte *)(levelBase + 0xcf) & 0xdf;
      }
      _gleCreateGlobalLevel(glContext,levelRecord2,width,height,depth,iVar9);
      _gleCreatePluginTextureLevel(glContext,checkedTextureObject,levelRecord2,targetThenFace,level,internalformat);
    }
    else {
      if (stateId == 0x3e1) {
        glContextWord5408 = *(int *)(glContext + 0x5408);
        *(char *)(glContext + 0x7586) = '\x01' - (*valuePtr == 0);
joined_r0x00020e50:
        if (glContextWord5408 != 0) {
          return 0;
        }
        _gliExecDispatchTable(glContext);
        return 0;
      }
      if (stateId < 0x3e2) {
        if (stateId == 0x184) {
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48bc) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x48be) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x48b8);
          iVar13 = *(short *)(glContext + 0x48be) - newCacheLimit;
          *(short *)(glContext + 0x48be) = (short)newCacheLimit;
        }
        else if (stateId < 0x185) {
          if (stateId == 0x17c) {
            newCacheLimit = *valuePtr;
            if (newCacheLimit < 1) {
              return 0x2718;
            }
            *(short *)(glContext + 0x48a4) = (short)newCacheLimit;
            if (*(short *)(glContext + 0x48a6) <= newCacheLimit) {
              return 0;
            }
            funcCache = *(undefined4 *)(glContext + 0x48a0);
            iVar13 = *(short *)(glContext + 0x48a6) - newCacheLimit;
            *(short *)(glContext + 0x48a6) = (short)newCacheLimit;
          }
          else {
            if (stateId != 0x180) goto LAB_00020f04;
            newCacheLimit = *valuePtr;
            if (newCacheLimit < 1) {
              return 0x2718;
            }
            *(short *)(glContext + 0x48ac) = (short)newCacheLimit;
            if (*(short *)(glContext + 0x48ae) <= newCacheLimit) {
              return 0;
            }
            funcCache = *(undefined4 *)(glContext + 0x48a8);
            iVar13 = *(short *)(glContext + 0x48ae) - newCacheLimit;
            *(short *)(glContext + 0x48ae) = (short)newCacheLimit;
          }
        }
        else {
          if (stateId != 0x188) {
            if (stateId == 0x3e0) {
              glContextWord5408 = *(int *)(glContext + 0x5408);
              *(char *)(glContext + 0x7587) = '\x01' - (*valuePtr == 0);
              goto joined_r0x00020e50;
            }
            goto LAB_00020f04;
          }
          newCacheLimit = *valuePtr;
          if (newCacheLimit < 1) {
            return 0x2718;
          }
          *(short *)(glContext + 0x48c4) = (short)newCacheLimit;
          if (*(short *)(glContext + 0x48c6) <= newCacheLimit) {
            return 0;
          }
          funcCache = *(undefined4 *)(glContext + 0x48c0);
          iVar13 = *(short *)(glContext + 0x48c6) - newCacheLimit;
          *(short *)(glContext + 0x48c6) = (short)newCacheLimit;
        }
        goto LAB_0002085c;
      }
      if (999 < stateId) {
        if (stateId == 0x6a7) {
          *(int *)(glContext + 0x7594) = *valuePtr;
          return 0;
        }
        if (stateId == 0x6a8) {
          *(int *)(glContext + 0x7598) = *valuePtr;
          return 0;
        }
        goto LAB_00020f04;
      }
      if (stateId < 0x3e5) {
        if (stateId == 0x3e2) {
          *(char *)(glContext + 0x7584) = '\x01' - (*valuePtr == 0);
          return 0;
        }
        if (stateId == 0x3e4) {
          *(char *)(glContext + 0x53e7) = '\x01' - (*valuePtr == 0);
          *(char *)(glContext + 0x7585) = '\x01' - (*valuePtr == 0);
          return 0;
        }
        goto LAB_00020f04;
      }
      iVar9 = valuePtr[1];
      internalformat = valuePtr[2];
      width = valuePtr[3];
      height = valuePtr[4];
      surfaceHandle2 = *valuePtr;
      textureObject = _gleCheckTexImage2DArgs(glContext,iVar9,0,internalformat,width,height,0,0x80e1,0x8367);
      if (textureObject == 0) {
        return 0;
      }
      textureFlags = *(ushort *)(textureObject + 0x24);
      if ((textureFlags & 0x3c00) != 0x400) {
        if ((textureFlags & 0x3c00) == 0) {
          *(ushort *)(textureObject + 0x24) = textureFlags | 0x400;
        }
        else if ((textureFlags & 0x1800) != 0) goto LAB_00020c88;
      }
      *(int *)(textureObject + 0x2c) = surfaceHandle2;
      if (stateId != 0x3e5) {
        uVar3 = 0x404;
      }
      else {
        uVar3 = *(undefined2 *)((int)valuePtr + 0x1a);
      }
      *(undefined2 *)(textureObject + 0x30) = uVar3;
      faceCount = 6;
      if (iVar9 != 0x8513) {
        faceCount = 1;
      }
      loopIndex2 = 0;
      if (faceCount != 0) {
        textureLevel = textureObject + 0xc4;
        do {
          if ((*(byte *)(textureLevel + 0xb) & 0x20) != 0) {
            _gleDeletePluginTextureLevel(glContext,textureObject,textureLevel,0,0);
            if (*(int *)(textureLevel + 0x14) != 0) {
              levelFlagByte = *(byte *)(textureLevel + 0xb);
              if ((levelFlagByte & 1) == 0) {
                _gleFreeTextureLevel(glContext,textureObject,textureLevel);
                levelFlagByte = *(byte *)(textureLevel + 0xb);
              }
              else {
                *(undefined4 *)(textureLevel + 0x14) = 0;
              }
              *(byte *)(textureLevel + 0xb) = levelFlagByte & 0xef;
            }
            *(byte *)(textureLevel + 0xb) = *(byte *)(textureLevel + 0xb) & 0xdf;
          }
          ((int (*)())_gleCreateSurfaceLevel)(glContext,textureLevel,width,height,0,0);
          if (stateId != 0x3e5) {
            mipmapSource = 0;
          }
          else {
            mipmapSource = valuePtr[7];
          }
          baseFormat = _gleReqToBase(internalformat);
          _gleCreatePluginTextureLevel(glContext,textureObject,textureLevel,loopIndex2,0,baseFormat);
          if (mipmapSource != 0) {
            _gleGenSurfaceMipmaps(glContext,textureObject,loopIndex2,mipmapSource,*(uint *)(textureObject + 0x6c) >> 0xf & 1);
          }
          loopIndex2 = loopIndex2 + 1;
          textureLevel = textureLevel + 0x168;
        } while (loopIndex2 < faceCount);
      }
    }
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  }
  return 0;
}

/* _gleCreateSurfaceLevel @ 0x20f84 (60 bytes) */
int _gleCreateSurfaceLevel(glContext, textureLevel, width, height, format, type)
  undefined4 glContext;
  int textureLevel;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
{
  *(undefined2 *)(textureLevel + 8) = 1;
  *(undefined2 *)(textureLevel + 0xe) = 0;
  *(undefined2 *)(textureLevel + 4) = (*(unsigned short *)((unsigned char *)&(width) + 2));
  *(undefined2 *)(textureLevel + 6) = (*(unsigned short *)((unsigned char *)&(height) + 2));
  *(undefined2 *)(textureLevel + 0x10) = (*(unsigned short *)((unsigned char *)&(format) + 2));
  *(undefined2 *)(textureLevel + 0x12) = (*(unsigned short *)((unsigned char *)&(type) + 2));
  *(undefined1 *)(textureLevel + 0xb) = 0x32;
  *(undefined4 *)(textureLevel + 0x14) = 0;
  *(undefined1 *)(textureLevel + 10) = 0;
  *(undefined2 *)(textureLevel + 0xc) = 0;
  return 0;
}

/* _glFlushRender_Exec @ 0x20fc0 (52 bytes) */
void _glFlushRender_Exec(glContext)
  int glContext;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
                    
                    
    (**(code **)(glContext + 0x47b4))(*(undefined4 *)(glContext + 0x4688));
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glGetFloatv_Exec @ 0x20ff4 (280 bytes) */
void _glGetFloatv_Exec(glContext, pname, params)
  int glContext;
  undefined4 pname;
  float *params;
{
  double intToDoubleMagic;
  undefined4 glErrorCode;
  uint intValue;
  double *cursor;
  int remaining;
  double stateValue;
  undefined1 stateFlagBytes [16];
  double stateValueBuffer [16];
  undefined4 intToDoubleHighWord;
  uint intToDoubleLowWord;
  int valueType [2];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    cursor = stateValueBuffer;
    remaining = _gleGetState(glContext,pname,cursor,valueType,stateFlagBytes);
    intToDoubleMagic = DOUBLE_00108d58;
    if (remaining == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00021068;
    }
    if (remaining != -1) {
      if (valueType[0] != 0x1404) {
        if (remaining < 1) {
          return;
        }
        do {
          stateValue = *cursor;
          cursor = cursor + 1;
          *params = (float)stateValue;
          params = params + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        return;
      }
      if (remaining < 1) {
        return;
      }
      do {
        intValue = *(uint *)cursor;
        cursor = cursor + 1;
        intToDoubleHighWord = 0x43300000;
        intToDoubleLowWord = intValue ^ 0x80000000;
        *params = (float)((double)CONCAT44(0x43300000,intValue ^ 0x80000000) - intToDoubleMagic);
        params = params + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00021068:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramivARB_Exec @ 0x2110c (2084 bytes) */
void _glGetProgramivARB_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  uint *params;
{
  int programLimitsOffset;
  uint result;
  undefined4 glErrorCode;
  uint uVar4;
  uint programIndex;
  int programRecord;
  uint queryValue [5];
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0002190c;
  }
  if (target == 0x8620) {
    programIndex = 0;
LAB_00021188:
    programRecord = *(int *)(programIndex * 4 + glContext + 0x5420);
    if (pname == 0x88a6) goto LAB_000216f4;
    if (pname < 0x88a7) {
      if (pname == 0x880d) {
LAB_00021804:
        result = 0;
        if (programIndex != 0) {
          result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x110);
        }
        goto LAB_00021914;
      }
      if (pname < 0x880e) {
        if (pname == 0x8807) {
          result = (uint)*(ushort *)(programRecord + 0x4f0);
          goto LAB_00021914;
        }
        if (0x8807 < pname) {
          if (pname == 0x880b) {
LAB_000217d4:
            result = 0;
            if (programIndex != 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10c);
            }
            goto LAB_00021914;
          }
          if (0x880b < pname) goto LAB_000217ec;
          goto LAB_000216f4;
        }
        if (pname == 0x8677) {
          result = *(uint *)(programRecord + 4);
          goto LAB_00021914;
        }
        if (pname < 0x8678) {
          if (pname == 0x8627) {
            result = *(uint *)(programRecord + 0x18);
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x8805) {
            result = (uint)*(ushort *)(programRecord + 0x4ec);
            goto LAB_00021914;
          }
          if (pname == 0x8806) {
            result = (uint)*(ushort *)(programRecord + 0x4ee);
            goto LAB_00021914;
          }
        }
      }
      else {
        if (pname == 0x88a0) {
          result = (uint)*(ushort *)(programRecord + 0x50);
          goto LAB_00021914;
        }
        if (pname < 0x88a1) {
          if (pname == 0x880f) {
LAB_000217ec:
            result = 0;
            if (programIndex != 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10e);
            }
            goto LAB_00021914;
          }
          if (pname < 0x880f) goto LAB_000217d4;
          if (pname == 0x8810) goto LAB_00021804;
          if (pname == 0x8876) {
            result = *(uint *)(programRecord + 0x1c);
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x88a3) {
            result = (uint)*(ushort *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xec);
            goto LAB_00021914;
          }
          if (pname < 0x88a4) {
            if (pname == 0x88a1) {
              result = 0x8000;
              if (programIndex != 0) {
                result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xfc);
              }
              goto LAB_00021914;
            }
            uVar4 = 0x88a2;
            goto LAB_00021354;
          }
          if (pname == 0x88a4) {
            result = (uint)*(ushort *)(programRecord + 0x56);
            goto LAB_00021914;
          }
          if (pname == 0x88a5) {
            result = 0x100;
            if (programIndex != 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x102);
            }
            goto LAB_00021914;
          }
        }
      }
    }
    else {
      if (pname == 0x88b1) {
        result = (programIndex ^ 1) << 1;
        goto LAB_00021914;
      }
      if (pname < 0x88b2) {
        if (pname == 0x88ab) {
          result = (uint)*(ushort *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xf0);
          goto LAB_00021914;
        }
        if (pname < 0x88ac) {
          if (pname == 0x88a8) {
            result = (uint)*(ushort *)(programRecord + 0x54);
            goto LAB_00021914;
          }
          if (pname < 0x88a8) {
            result = (uint)*(ushort *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xf2);
            goto LAB_00021914;
          }
          if (pname == 0x88a9) {
            result = 0x100;
            if (programIndex != 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x100);
            }
            goto LAB_00021914;
          }
          uVar4 = 0x88aa;
LAB_00021354:
          if (pname == uVar4) {
LAB_000216f4:
            (**(code **)(glContext + 0x47dc))
                      (*(undefined4 *)(glContext + 0x4688),
                       *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                       pname,queryValue);
            result = queryValue[0];
LAB_00021914:
            queryValue[0] = result;
            *params = queryValue[0];
            return;
          }
        }
        else {
          if (pname == 0x88ae) goto LAB_000216f4;
          if (pname < 0x88af) {
            if (pname == 0x88ac) {
              result = (uint)*(ushort *)(programRecord + 0x52);
              goto LAB_00021914;
            }
            if (pname == 0x88ad) {
              result = 0x20;
              if (programIndex != 0) {
                result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xfe);
              }
              goto LAB_00021914;
            }
          }
          else {
            if (pname == 0x88af) {
              result = (uint)*(ushort *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xee);
              goto LAB_00021914;
            }
            if (pname == 0x88b0) {
              result = (uint)*(ushort *)(programRecord + 0x4e);
              goto LAB_00021914;
            }
          }
        }
      }
      else {
        if (pname == 0x88b6) {
          programLimitsOffset = programIndex * 0x10;
          result = 0;
          if (*(short *)(programLimitsOffset + *(int *)(glContext + 0x468c) + 0xec) == 0) goto LAB_00021914;
          (**(code **)(glContext + 0x47dc))
                    (*(undefined4 *)(glContext + 0x4688),
                     *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),0x88a2,
                     queryValue);
          if (((((int)queryValue[0] <=
                 (int)(uint)*(ushort *)(programLimitsOffset + *(int *)(glContext + 0x468c) + 0xec)) &&
               ((**(code **)(glContext + 0x47dc))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                           0x88aa,queryValue),
               (int)queryValue[0] <= (int)(uint)*(ushort *)(programLimitsOffset + *(int *)(glContext + 0x468c) + 0xf0)
               )) && ((**(code **)(glContext + 0x47dc))
                                (*(undefined4 *)(glContext + 0x4688),
                                 *(undefined4 *)
                                  ((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),0x88a6,
                                 queryValue),
                     (int)queryValue[0] <=
                     (int)(uint)*(ushort *)(programLimitsOffset + *(int *)(glContext + 0x468c) + 0xf2))) &&
             ((**(code **)(glContext + 0x47dc))
                        (*(undefined4 *)(glContext + 0x4688),
                         *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                         0x88ae,queryValue),
             (int)queryValue[0] <= (int)(uint)*(ushort *)(programLimitsOffset + *(int *)(glContext + 0x468c) + 0xee)))
          {
            if ((programIndex == 0) &&
               ((**(code **)(glContext + 0x47dc))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                           0x88b2,queryValue),
               (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x118) < (int)queryValue[0])) {
              result = 0;
              goto LAB_00021914;
            }
            if ((programIndex != 1) ||
               ((((**(code **)(glContext + 0x47dc))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                             0x8808,queryValue),
                 (int)queryValue[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10c) &&
                 ((**(code **)(glContext + 0x47dc))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                             0x8809,queryValue),
                 (int)queryValue[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x10e))) &&
                ((**(code **)(glContext + 0x47dc))
                           (*(undefined4 *)(glContext + 0x4688),
                            *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + programRecord + 0x4a8),
                            0x880a,queryValue),
                (int)queryValue[0] <= (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x110))))) {
              result = 1;
              goto LAB_00021914;
            }
          }
          result = 0;
          goto LAB_00021914;
        }
        if (pname < 34999) {
          if (pname == 0x88b3) {
            result = 0;
            if (programIndex == 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x118);
            }
            goto LAB_00021914;
          }
          if (pname < 0x88b3) goto LAB_000216f4;
          if ((pname == 0x88b4) || (pname == 0x88b5)) {
            result = 0x100;
            if (programIndex != 0) {
              result = 0x80;
            }
            goto LAB_00021914;
          }
        }
        else {
          if (pname == 0x88f6) {
            result = 0;
            if (programIndex != 0) {
              result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x112);
            }
            goto LAB_00021914;
          }
          if (pname < 0x88f7) {
            if (pname == 0x88f4) {
              result = *(uint *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xf8);
              goto LAB_00021914;
            }
            if (pname == 0x88f5) {
              result = (uint)*(ushort *)(programIndex * 0x10 + *(int *)(glContext + 0x468c) + 0xf4);
              goto LAB_00021914;
            }
          }
          else {
            if (pname == 0x88f7) {
              result = 0;
              if (programIndex != 0) {
                result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x114);
              }
              goto LAB_00021914;
            }
            if (pname == 0x88f8) {
              result = 0;
              if (programIndex != 0) {
                result = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0x116);
              }
              goto LAB_00021914;
            }
          }
        }
      }
    }
  }
  else {
    if (target < 0x8621) {
      uVar4 = 0x8200;
    }
    else {
      uVar4 = 0x8804;
    }
    if (target == uVar4) {
      programIndex = 1;
      goto LAB_00021188;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0002190c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsEnabled_Exec @ 0x21930 (72 bytes) */
int _glIsEnabled_Exec(glContext, cap)
  int glContext;
  undefined4 cap;
{
  undefined4 enabled;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    enabled = ((int (*)())_gleGetEnabled)(glContext,cap);
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    enabled = 0;
  }
  return enabled;
}

/* _gleGetEnabled @ 0x21978 (2652 bytes) */
int _gleGetEnabled(glContext, cap)
  int glContext;
  uint cap;
{
  uint stateWord;
  uint shiftAmount;
  int clientState;
  longlong texCoordArrayEnableMask;
  
  if (cap < 0x4008) {
    if (cap < 0x4000) {
      if (cap == 0xd90) {
        return (uint)*(byte *)(glContext + 0x74e2);
      }
      if (cap < 0xd91) {
        if (cap == 0xba1) {
          return (uint)*(byte *)(glContext + 0x280d);
        }
        if (0xba1 < cap) {
          if (cap == 0xc11) {
            return (uint)*(byte *)(glContext + 0x34f0);
          }
          if (cap < 0xc12) {
            if (cap == 0xbe2) {
              return (uint)*(byte *)(glContext + 0x30e4);
            }
            if (cap < 0xbe3) {
              if (cap == 0xbc0) {
                return (uint)*(byte *)(glContext + 0x30c6);
              }
              if (cap == 0xbd0) {
                return (uint)*(byte *)(glContext + 0x313c);
              }
            }
            else {
              if (cap == 0xbf1) {
                return (uint)*(byte *)(glContext + 0x3192);
              }
              if (cap == 0xbf2) {
                return (uint)*(byte *)(glContext + 0x3193);
              }
            }
          }
          else {
            if (cap == 0xc62) {
              return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7a);
            }
            if (cap < 0xc63) {
              if (cap == 0xc60) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d78);
              }
              if (cap == 0xc61) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d79);
              }
            }
            else {
              if (cap == 0xc63) {
                return (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x94 + glContext + 0x3d7b);
              }
              if (cap == 0xd80) {
                return (uint)*(byte *)(glContext + 0x74f2);
              }
            }
          }
LAB_000223a8:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x500;
          }
          return 0;
        }
        if (cap == 0xb44) {
          return (uint)*(byte *)(glContext + 0x34da);
        }
        if (cap < 0xb45) {
          if (cap == 0xb24) {
            return (uint)*(byte *)(glContext + 0x318c);
          }
          if (cap < 0xb25) {
            if (cap == 0xb10) {
              return (uint)*(byte *)(glContext + 0x343c);
            }
            if (cap == 0xb20) {
              return (uint)*(byte *)(glContext + 0x318d);
            }
          }
          else {
            if (cap == 0xb41) {
              return (uint)*(byte *)(glContext + 0x34d9);
            }
            if (cap == 0xb42) {
              return (uint)*(byte *)(glContext + 0x34d8);
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0xb60) {
          return (uint)*(byte *)(glContext + 0x316a);
        }
        if (cap < 0xb61) {
          if (cap == 0xb50) {
            return (uint)*(byte *)(glContext + 0x30aa);
          }
          if (cap == 0xb57) {
            return (uint)*(byte *)(glContext + 0x30ab);
          }
          goto LAB_000223a8;
        }
        if (cap == 0xb71) {
          return (uint)*(byte *)(glContext + 0x3128);
        }
        if (cap != 0xb90) goto LAB_000223a8;
        stateWord = *(uint *)(glContext + 0x3520);
        shiftAmount = (uint)*(byte *)(glContext + 0x7583);
      }
      else {
        if (cap == 0xdb3) {
          return (uint)*(byte *)(glContext + 0x74ee);
        }
        if (cap < 0xdb4) {
          if (cap == 0xd96) {
            return (uint)*(byte *)(glContext + 0x74e8);
          }
          if (cap < 0xd97) {
            if (cap == 0xd93) {
              return (uint)*(byte *)(glContext + 0x74e5);
            }
            if (cap < 0xd94) {
              if (cap == 0xd91) {
                return (uint)*(byte *)(glContext + 0x74e3);
              }
              if (cap == 0xd92) {
                return (uint)*(byte *)(glContext + 0x74e4);
              }
            }
            else {
              if (cap == 0xd94) {
                return (uint)*(byte *)(glContext + 0x74e6);
              }
              if (cap == 0xd95) {
                return (uint)*(byte *)(glContext + 0x74e7);
              }
            }
          }
          else {
            if (cap == 0xdb0) {
              return (uint)*(byte *)(glContext + 0x74eb);
            }
            if (cap < 0xdb1) {
              if (cap == 0xd97) {
                return (uint)*(byte *)(glContext + 0x74e0);
              }
              if (cap == 0xd98) {
                return (uint)*(byte *)(glContext + 0x74e1);
              }
            }
            else {
              if (cap == 0xdb1) {
                return (uint)*(byte *)(glContext + 0x74ec);
              }
              if (cap == 0xdb2) {
                return (uint)*(byte *)(glContext + 0x74ed);
              }
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0xde0) {
          stateWord = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
LAB_00022360:
          return stateWord >> 4 & 1;
        }
        if (cap < 0xde1) {
          if (cap == 0xdb6) {
            return (uint)*(byte *)(glContext + 0x74f1);
          }
          if (cap < 0xdb7) {
            if (cap == 0xdb4) {
              return (uint)*(byte *)(glContext + 0x74ef);
            }
            if (cap == 0xdb5) {
              return (uint)*(byte *)(glContext + 0x74f0);
            }
          }
          else {
            if (cap == 0xdb7) {
              return (uint)*(byte *)(glContext + 0x74e9);
            }
            if (cap == 0xdb8) {
              return (uint)*(byte *)(glContext + 0x74ea);
            }
          }
          goto LAB_000223a8;
        }
        if (cap == 0x2a02) {
          return (uint)*(byte *)(glContext + 0x34dc);
        }
        if (cap < 0x2a03) {
          if (cap == 0xde1) {
            stateWord = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
            goto LAB_0002236c;
          }
          if (cap == 0x2a01) {
            return (uint)*(byte *)(glContext + 0x34db);
          }
          goto LAB_000223a8;
        }
        shiftAmount = cap - 0x3000;
        if (5 < shiftAmount) goto LAB_000223a8;
        stateWord = *(uint *)(glContext + 0x4188);
      }
    }
    else {
      stateWord = *(uint *)(glContext + 0x30a0);
      shiftAmount = cap - 0x4000;
    }
    stateWord = stateWord >> (shiftAmount & 0x3f);
LAB_00022378:
    return stateWord & 1;
  }
  if (cap == 0x8200) {
LAB_00022328:
    return (uint)*(byte *)(glContext + 0x466c);
  }
  if (cap < 0x8201) {
    if (cap == 0x8076) {
      stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x12;
      goto LAB_0002227c;
    }
    if (0x8076 < cap) {
      if (cap == 0x809f) {
        return (uint)*(byte *)(glContext + 0x41f2);
      }
      if (cap < 0x80a0) {
        if (cap == 0x8079) {
          stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x16;
          goto LAB_0002227c;
        }
        if (cap < 0x807a) {
          if (cap == 0x8077) {
            return (uint)*(byte *)(glContext + 0x48eb);
          }
          if (cap == 0x8078) {
            clientState = *(int *)(glContext + 0x4a60);
            texCoordArrayEnableMask = ___ashldi3(0,0x1000000,*(undefined4 *)(glContext + 0x53d8));
            if ((*(uint *)(clientState + 0x330) & (uint)((ulonglong)texCoordArrayEnableMask >> 0x20)) == 0 &&
                (*(uint *)(clientState + 0x334) & (uint)texCoordArrayEnableMask) == 0) {
              return 0;
            }
            return 1;
          }
        }
        else {
          if (cap == 0x809d) {
            return (uint)*(byte *)(glContext + 0x41f0);
          }
          if (cap == 0x809e) {
            return (uint)*(byte *)(glContext + 0x41f1);
          }
        }
      }
      else {
        if (cap == 0x80d1) {
          return *(uint *)(glContext + 0x3410) >> 6 & 1;
        }
        if (cap < 0x80d2) {
          if (cap == 0x80a0) {
            return (uint)*(byte *)(glContext + 0x41f3);
          }
          if (cap == 0x80d0) {
            return *(uint *)(glContext + 0x3410) >> 5 & 1;
          }
        }
        else {
          if (cap == 0x80d2) {
            return *(uint *)(glContext + 0x3410) >> 7 & 1;
          }
          if (cap == 0x81fb) {
            return *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534) >> 8 & 1;
          }
        }
      }
      goto LAB_000223a8;
    }
    if (cap == 0x802e) {
      stateWord = *(uint *)(glContext + 0x3410);
LAB_0002236c:
      return stateWord >> 3 & 1;
    }
    if (cap < 0x802f) {
      if (cap != 0x8011) {
        if (cap < 0x8012) {
          if (cap == 0x6090) {
            return (uint)*(byte *)(glContext + 0x280c);
          }
          if (cap == 0x8010) {
            stateWord = (uint)*(byte *)(glContext + 0x3413);
            goto LAB_00022378;
          }
        }
        else {
          if (cap == 0x8012) {
            stateWord = *(uint *)(glContext + 0x3410);
            goto LAB_00022398;
          }
          if (cap == 0x8024) {
            stateWord = *(uint *)(glContext + 0x3410);
            goto LAB_00022360;
          }
        }
        goto LAB_000223a8;
      }
      stateWord = *(uint *)(glContext + 0x3410);
    }
    else {
      if (cap != 0x806f) {
        if (0x806f < cap) {
          if (cap == 0x8074) {
            stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x10;
          }
          else {
            if (cap != 0x8075) goto LAB_000223a8;
            stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x11;
          }
          goto LAB_0002227c;
        }
        if (cap == 0x8037) {
          return (uint)*(byte *)(glContext + 0x34dd);
        }
        if (cap == 0x803a) {
          return (uint)*(byte *)(glContext + 0x280e);
        }
        goto LAB_000223a8;
      }
      stateWord = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
    }
    return stateWord >> 1 & 1;
  }
  if (cap == 0x8643) {
    return (uint)*(byte *)(glContext + 0x4666);
  }
  if (cap < 0x8644) {
    if (cap == 0x851d) {
      return (uint)*(byte *)(glContext + 0x465c);
    }
    if (cap < 0x851e) {
      if (cap == 0x845e) {
        stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x14;
LAB_0002227c:
        return stateWord & 1;
      }
      if (cap < 0x845f) {
        if (cap != 0x8457) {
          if (cap == 0x8458) {
            return (uint)*(byte *)(glContext + 0x4fea);
          }
          goto LAB_000223a8;
        }
        stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x13;
        goto LAB_0002227c;
      }
      if (cap != 0x84f5) {
        if (cap != 0x8513) goto LAB_000223a8;
        stateWord = (uint)*(byte *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3537);
        goto LAB_00022378;
      }
    }
    else if (cap != 0x85b3) {
      if (cap < 0x85b4) {
        if (cap == 0x8522) {
          return (uint)*(byte *)(glContext + 0x41f8);
        }
        if (cap == 0x8535) {
          return (uint)*(byte *)(glContext + 0x41f9);
        }
      }
      else {
        if (cap == 0x8620) {
          return (uint)*(byte *)(glContext + 0x4664);
        }
        if (cap == 0x8642) {
          return (uint)*(byte *)(glContext + 0x4665);
        }
      }
      goto LAB_000223a8;
    }
    stateWord = *(uint *)(*(int *)(glContext + 0x53d4) * 0x7c + glContext + 0x3534);
  }
  else {
    if (cap == 0x8804) goto LAB_00022328;
    if (cap < 0x8805) {
      if (cap == 0x86a7) {
        return (uint)*(byte *)(glContext + 0x4661);
      }
      if (cap < 0x86a8) {
        if (cap == 0x864f) {
          return (uint)*(byte *)(glContext + 0x3129);
        }
        if (cap == 0x86a6) {
          return (uint)*(byte *)(glContext + 0x4662);
        }
      }
      else {
        if (cap == 0x86ad) {
          stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x15;
          goto LAB_0002227c;
        }
        if (cap == 0x86de) {
          return (uint)*(byte *)(glContext + 0x3ce4);
        }
      }
      goto LAB_000223a8;
    }
    if (cap != 0x8910) {
      if (cap < 0x8911) {
        if (cap == 0x8861) {
          return (uint)*(byte *)(glContext + 0x343d);
        }
        if (cap == 0x8890) {
          return (uint)*(byte *)(glContext + 0x312a);
        }
      }
      else {
        if (cap == 0x8a0c) {
          stateWord = *(uint *)(*(int *)(glContext + 0x4a60) + 0x334) >> 0x17;
          goto LAB_0002227c;
        }
        if (cap == 0x19262) {
          return (uint)*(byte *)(glContext + 0x50b5);
        }
      }
      goto LAB_000223a8;
    }
    stateWord = *(uint *)(glContext + 0x3520);
  }
LAB_00022398:
  return stateWord >> 2 & 1;
}

/* _gleShareSharedState @ 0x223d4 (88 bytes) */
int _gleShareSharedState(glContext)
  int glContext;
{
  int sharedState;
  
  sharedState = *(int *)(glContext + 0x5148);
  _pthread_mutex_lock(sharedState + 0x8028);
  *(undefined1 *)(sharedState + 0x8024) = 1;
  *(int *)(sharedState + 0x8020) = *(int *)(sharedState + 0x8020) + 1;
  _pthread_mutex_unlock(sharedState + 0x8028);
  return sharedState;
}

/* _gleSetEnable_DITHER @ 0x2242c (32 bytes) */
void _gleSetEnable_DITHER(glContext, unusedArg2, enable)
  int glContext;
  undefined4 unusedArg2;
  uint enable;
{
  if (*(byte *)(glContext + 0x313c) == enable) {
    return;
  }
  *(char *)(glContext + 0x313c) = (char)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400;
  return;
}

/* _glStencilMask_Exec @ 0x2244c (68 bytes) */
void _glStencilMask_Exec(glContext, mask)
  int glContext;
  undefined4 mask;
{
  uint glContextWord310;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    glContextWord310 = *(uint *)(glContext + 0x310);
    *(undefined4 *)((uint)*(byte *)(glContext + 0x7583) * 4 + glContext + 0x3198) = mask;
    *(uint *)(glContext + 0x310) = glContextWord310 | 0x100000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glClearColor_Exec @ 0x22490 (228 bytes) */
void _glClearColor_Exec(int glContext,float red,float green,float blue,float alpha)
{
  float floatZero;
  float floatOne;
  float clampLowDouble;
  float clampHighDouble;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  clampLowDouble = (double)FLOAT_00108e50;
  clampHighDouble = (double)FLOAT_00108e54;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 8;
  if (red < (double)clampLowDouble) {
    *(float *)(glContext + 0x3100) = floatZero;
  }
  else if ((double)clampHighDouble < red) {
    *(float *)(glContext + 0x3100) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3100) = (float)red;
  }
  if (green < (double)clampLowDouble) {
    *(float *)(glContext + 0x3104) = floatZero;
  }
  else if ((double)clampHighDouble < green) {
    *(float *)(glContext + 0x3104) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3104) = (float)green;
  }
  if (blue < (double)clampLowDouble) {
    *(float *)(glContext + 0x3108) = floatZero;
  }
  else if ((double)clampHighDouble < blue) {
    *(float *)(glContext + 0x3108) = floatOne;
  }
  else {
    *(float *)(glContext + 0x3108) = (float)blue;
  }
  if (alpha < (double)clampLowDouble) {
    *(float *)(glContext + 0x310c) = floatZero;
    return;
  }
  if ((double)clampHighDouble < alpha) {
    *(float *)(glContext + 0x310c) = floatOne;
    return;
  }
  *(float *)(glContext + 0x310c) = (float)alpha;
  return;
}

/* _glMultiTexCoord4fv_Exec @ 0x225b4 (60 bytes) */
double _glMultiTexCoord4fv_Exec(glContext, target, v)
  int glContext;
  uint target;
  undefined4 *v;
{
  undefined4 texCoordQ;
  undefined4 texCoordT;
  undefined4 texCoordR;
  int unitTexCoord;
  
  texCoordQ = v[3];
  unitTexCoord = glContext + (target & 7) * 0x10;
  texCoordT = v[1];
  texCoordR = v[2];
  *(undefined4 *)(unitTexCoord + 0x120) = *v;
  *(undefined4 *)(unitTexCoord + 300) = texCoordQ;
  *(undefined4 *)(unitTexCoord + 0x124) = texCoordT;
  *(undefined4 *)(unitTexCoord + 0x128) = texCoordR;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
  return;
}

/* _glVertex4fv_Exec @ 0x225f0 (48 bytes) */
void _glVertex4fv_Exec(glContext, v)
  int glContext;
  float *v;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int,int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (glContext, v, (double)*v, (double)v[1], (double)v[2], (double)v[3]);
  return;
}

/* _glGenProgramsARB_Exec @ 0x22620 (236 bytes) */
void _glGenProgramsARB_Exec(glContext, n, programs)
  int glContext;
  int n;
  int *programs;
{
  undefined4 glErrorCode;
  int programName;
  int loopIndex;
  int sharedStateThenFirstName;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedStateThenFirstName + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedStateThenFirstName + 0x8028);
        sharedStateThenFirstName = *(int *)(glContext + 0x5148);
      }
      sharedStateThenFirstName = _gleGenHashNames(sharedStateThenFirstName + 0x4010,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (sharedStateThenFirstName == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        programName = loopIndex + sharedStateThenFirstName;
        loopIndex = loopIndex + 1;
        *programs = programName;
        programs = programs + 1;
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBindProgramARB_Exec @ 0x2270c (276 bytes) */
void _glBindProgramARB_Exec(glContext, target, program)
  int glContext;
  uint target;
  undefined4 program;
{
  undefined4 glErrorCode;
  undefined4 pipelineStageIndex;
  uint acceptedFragmentTarget;
  int sharedStateMutex;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0002279c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (target == 0x8620) {
    pipelineStageIndex = 0;
  }
  else {
    if (target < 0x8621) {
      acceptedFragmentTarget = 0x8200;
    }
    else {
      acceptedFragmentTarget = 0x8804;
    }
    if (target != acceptedFragmentTarget) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0002279c;
    }
    pipelineStageIndex = 1;
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    sharedStateMutex = *(int *)(glContext + 0x5148) + 0x8028;
    _pthread_mutex_lock(sharedStateMutex);
    ((int (*)())_gleBindPipelineProgram)(glContext,pipelineStageIndex,program);
    _pthread_mutex_unlock(sharedStateMutex);
    return;
  }
  ((int (*)())_gleBindPipelineProgram)(glContext,pipelineStageIndex,program);
  return;
}

/* _gleBindPipelineProgram @ 0x22820 (644 bytes) */
int _gleBindPipelineProgram(glContext, pipelineStageIndex, program)
  int glContext;
  uint pipelineStageIndex;
  int program;
{
  int loopIndex2;
  int remaining;
  char glContextByte85a4;
  int wordOffset;
  undefined *setClipInterpFunc;
  undefined4 copiedWord;
  int sharedState;
  uint newChangeWord;
  int programObject;
  undefined4 *srcCursor;
  int stageStateOffset;
  int loopIndex;
  undefined4 *dstCursor;
  int programHashThenStageOffsetThenCountThenRefCount;
  int previousProgramObject;
  int programRecord;
  
  programHashThenStageOffsetThenCountThenRefCount = *(int *)(glContext + 0x5148) + 0x4010;
  if (program == 0) {
    programHashThenStageOffsetThenCountThenRefCount = pipelineStageIndex * 4;
    programObject = *(int *)(programHashThenStageOffsetThenCountThenRefCount + glContext + 0x5428);
    programRecord = programObject + 0x10;
  }
  else {
    programObject = _gleLookupHashObject(programHashThenStageOffsetThenCountThenRefCount,program);
    if (programObject == 0) {
      programObject = _gleCreatePipelineProgramObject(glContext,pipelineStageIndex,program);
      programRecord = programObject + 0x10;
      _gleCreatePluginPipelineProgram(glContext,programRecord);
      _gleAddHashNameAndObject(glContext,programHashThenStageOffsetThenCountThenRefCount,programObject);
    }
    else {
      if (*(ushort *)(programObject + 0x4ca) != pipelineStageIndex) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x502;
        return;
      }
      programRecord = programObject + 0x10;
    }
    programHashThenStageOffsetThenCountThenRefCount = pipelineStageIndex << 2;
  }
  **(undefined1 **)(glContext + 0x5418) = 0;
  loopIndex2 = 0;
  *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
  *(int *)(programObject + 8) = *(int *)(programObject + 8) + 1;
  glContextByte85a4 = *(char *)(glContext + 0x85a4);
  previousProgramObject = *(int *)(programHashThenStageOffsetThenCountThenRefCount + glContext + 0x5420);
  *(int *)(programHashThenStageOffsetThenCountThenRefCount + glContext + 0x5420) = programObject;
  if (glContextByte85a4 != '\0') {
    srcCursor = (undefined4 *)(programObject + 0x4a8);
    dstCursor = (undefined4 *)(pipelineStageIndex * 4 + glContext + 0x886c);
    do {
      copiedWord = *srcCursor;
      loopIndex2 = loopIndex2 + 1;
      srcCursor = srcCursor + 1;
      *dstCursor = copiedWord;
      dstCursor = dstCursor + 0xb8;
    } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (pipelineStageIndex == 0) {
    remaining = 9;
    programHashThenStageOffsetThenCountThenRefCount = 5;
    newChangeWord = *(uint *)(glContext + 0x31c) | 0x400000;
  }
  else {
    if (pipelineStageIndex != 1) {
      remaining = 0;
      programHashThenStageOffsetThenCountThenRefCount = 0;
      goto LAB_0002299c;
    }
    remaining = 5;
    programHashThenStageOffsetThenCountThenRefCount = 0xe;
    newChangeWord = *(uint *)(glContext + 0x31c) | 0x1000000;
  }
  *(uint *)(glContext + 0x31c) = newChangeWord;
LAB_0002299c:
  stageStateOffset = pipelineStageIndex * 0xa30;
  if (*(int *)(stageStateOffset + *(int *)(glContext + 0x5148) + 0x8a98) != *(int *)(programRecord + 0x14)) {
    ((void (*)())_glePPUpdateProgram)(glContext,programRecord);
    *(undefined4 *)(programRecord + 0x14) = *(undefined4 *)(stageStateOffset + *(int *)(glContext + 0x5148) + 0x8a98);
  }
  _gleUpdateInverseNeeds(glContext);
  loopIndex = 0;
  if (remaining != 0) {
    sharedState = *(int *)(glContext + 0x5148);
    programHashThenStageOffsetThenCountThenRefCount = programHashThenStageOffsetThenCountThenRefCount * 4 + glContext;
    do {
      wordOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      newChangeWord = *(uint *)(programHashThenStageOffsetThenCountThenRefCount + 0x310) |
              *(uint *)(wordOffset + programRecord + 0x18) &
              (*(uint *)(wordOffset + sharedState + stageStateOffset + 0x8a74) | ~*(uint *)(wordOffset + previousProgramObject + 0x28));
      *(uint *)(programHashThenStageOffsetThenCountThenRefCount + 0x310) = newChangeWord;
      *(uint *)(programHashThenStageOffsetThenCountThenRefCount + 0x310) = newChangeWord & *(uint *)(wordOffset + programRecord + 0x18);
      programHashThenStageOffsetThenCountThenRefCount = programHashThenStageOffsetThenCountThenRefCount + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  programHashThenStageOffsetThenCountThenRefCount = *(int *)(previousProgramObject + 8) + -1;
  *(int *)(previousProgramObject + 8) = programHashThenStageOffsetThenCountThenRefCount;
  if (programHashThenStageOffsetThenCountThenRefCount == 0) {
    _gleFreePipelineProgramObject(glContext,previousProgramObject);
  }
  _gleSelectVertexSubmitFunc(glContext);
  setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
  return;
}

/* _glProgramStringARB_Exec @ 0x22aa4 (796 bytes) */
void _glProgramStringARB_Exec(glContext, target, format, len, string)
  int glContext;
  uint target;
  int format;
  int len;
  int string;
{
  int allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor;
  int remaining4;
  int loopIndex5;
  int stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount;
  undefined4 glErrorCodeThenCopiedWord;
  uint *copyWordPtrThenBodyWordPtr;
  bool stringHasNoEarlyNul;
  uint expectedTargetThenNewDirtyWord;
  undefined4 *srcCursor;
  int programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor;
  int remaining3;
  int remaining;
  uint savedRecordWords28 [15];
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCodeThenCopiedWord = 0x502;
    goto LAB_00022bb8;
  }
  if (-1 < len) {
    if (format != 0x8875) {
LAB_00022b48:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCodeThenCopiedWord = 0x500;
      goto LAB_00022bb8;
    }
    if (target == 0x8620) {
      programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor = 0;
    }
    else {
      if (target < 0x8621) {
        expectedTargetThenNewDirtyWord = 0x8200;
      }
      else {
        expectedTargetThenNewDirtyWord = 0x8804;
      }
      if (target != expectedTargetThenNewDirtyWord) goto LAB_00022b48;
      programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor = 1;
    }
    stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = 0;
    allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = _malloc(len + 1);
    stringHasNoEarlyNul = len == 0;
    if (0 < len) {
      do {
        if (*(char *)(string + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount) == '\0') break;
        *(char *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount) = *(char *)(string + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount);
        stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 1;
        stringHasNoEarlyNul = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount == len;
      } while (stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount < len);
    }
    *(undefined1 *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount) = 0;
    if (stringHasNoEarlyNul) {
      programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor = *(int *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor * 4 + glContext + 0x5420);
      if (*(int *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x14) != 0) {
        ((void (*)())_gleModifyPluginPipelineProgram)(glContext,programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x10,1);
        _free(*(undefined4 *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x14));
      }
      *(undefined1 *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x4c) = 1;
      *(undefined4 *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x1c) = 0x8875;
      *(int *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x18) = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount;
      *(int *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x14) = allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor;
      *(short *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x4c8) = (short)target;
      if (target == 0x8620) {
        allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x10;
        remaining3 = 9;
        srcCursor = (undefined4 *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x28);
        stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = 0;
        do {
          glErrorCodeThenCopiedWord = *srcCursor;
          srcCursor = srcCursor + 1;
          *(undefined4 *)((int)savedRecordWords28 + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount) = glErrorCodeThenCopiedWord;
          stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 4;
          remaining3 = remaining3 + -1;
        } while (remaining3 != 0);
        ((void (*)())_glePPParse)(glContext,allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor,0);
        ((void (*)())_glePPUpdateProgram)(glContext,allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor);
        _gleUpdateInverseNeeds(glContext);
        remaining = 9;
        loopIndex5 = 0;
        stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = glContext;
        do {
          copyWordPtrThenBodyWordPtr = (uint *)((int)savedRecordWords28 + loopIndex5);
          loopIndex5 = loopIndex5 + 4;
          expectedTargetThenNewDirtyWord = *(uint *)(stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 0x324) | *(uint *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 0x18) & ~*copyWordPtrThenBodyWordPtr;
          *(uint *)(stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 0x324) = expectedTargetThenNewDirtyWord;
          copyWordPtrThenBodyWordPtr = (uint *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 0x18);
          allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 4;
          *(uint *)(stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 0x324) = expectedTargetThenNewDirtyWord & *copyWordPtrThenBodyWordPtr;
          stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 4;
          remaining = remaining + -1;
        } while (remaining != 0);
        _gleSelectVertexSubmitFunc(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
      }
      if (target == 0x8804) {
        srcCursor = (undefined4 *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x28);
        stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = 5;
        programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor = programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x10;
        allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = 0;
        do {
          glErrorCodeThenCopiedWord = *srcCursor;
          srcCursor = srcCursor + 1;
          *(undefined4 *)((int)savedRecordWords28 + allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor) = glErrorCodeThenCopiedWord;
          allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 4;
          stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + -1;
        } while (stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount != 0);
        ((void (*)())_glePPParse)(glContext,programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor,1);
        ((void (*)())_glePPUpdateProgram)(glContext,programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor);
        _gleUpdateInverseNeeds(glContext);
        remaining4 = 9;
        stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = 0;
        allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = glContext;
        do {
          copyWordPtrThenBodyWordPtr = (uint *)((int)savedRecordWords28 + stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount);
          stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount = stringIndexThenCopyOffsetThenDirtyWordCursorThenRemainingWordCount + 4;
          expectedTargetThenNewDirtyWord = *(uint *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 0x348) | *(uint *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x18) & ~*copyWordPtrThenBodyWordPtr;
          *(uint *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 0x348) = expectedTargetThenNewDirtyWord;
          copyWordPtrThenBodyWordPtr = (uint *)(programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 0x18);
          programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor = programSlotThenProgramRecordThenProgramBodyThenBodyWordCursor + 4;
          *(uint *)(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 0x348) = expectedTargetThenNewDirtyWord & *copyWordPtrThenBodyWordPtr;
          allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor = allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor + 4;
          remaining4 = remaining4 + -1;
        } while (remaining4 != 0);
        _gleSelectVertexSubmitFunc(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
      }
      if (target != 0x8200) {
        return;
      }
      _gleLFSParse(glContext);
      _gleSelectVertexSubmitFunc(glContext);
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
      return;
    }
    _free(allocatedBlockThenProgramBodyThenCopyOffsetThenDirtyWordCursor);
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCodeThenCopiedWord = 0x501;
LAB_00022bb8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCodeThenCopiedWord;
  return;
}

/* _glePPParse @ 0x22dc0 (4884 bytes) */
void _glePPParse(glContext, programRecord, programKind)
  int glContext;
  int *programRecord;
  int programKind;
{
  int allocatedBlock;
  bool isFragmentProgram;
  bool pruneSucceeded;
  short oldFirstOrdinal;
  ushort rendererWord11a;
  int iVar5;
  int allocatedBlock2;
  int *opListCopy;
  int *paramArrayListCopy;
  undefined1 *fillerChunk;
  undefined4 chunkCopy;
  undefined2 texOperationCount;
  short sVar12;
  undefined4 *srcCursor;
  int iVar14;
  uint uVar15;
  int iVar16;
  int oldStreamThenParser;
  int *paramArrayList;
  int *opList;
  int *paramBindingList;
  int iVar21;
  int sourceTextThenStream;
  uint uVar23;
  uint loopIndex;
  undefined4 uVar24;
  uint limitsWord0ThenAttribBindingWord0;
  uint limitsWord1ThenAttribBindingWord1;
  undefined4 limitsWord2;
  undefined4 limitsWord3;
  uint limitsWord4ThenOutputBindingWord0;
  undefined4 limitsWord5ThenOutputBindingWord1;
  undefined4 limitsWord6;
  undefined4 limitsWord7;
  uint limitsWord8ThenParamBindingWord0;
  undefined4 limitsWord9ThenParamBindingWord1;
  undefined4 limitsWord10ThenParamBindingWord2;
  undefined4 limitsWord11ThenParamBindingWord3;
  undefined4 limitsWord12;
  undefined4 limitsWord13;
  undefined4 limitsWord14;
  uint operationWord0;
  uint operationWord1;
  undefined4 operationWord2;
  uint operationWord3;
  uint operationWord4;
  uint operationWord5;
  uint operationWord6;
  uint operationWord7;
  uint operationWord8;
  uint operationWord9;
  uint operationWord10;
  uint operationWord11;
  uint operationWord12;
  uint operationWord13;
  uint tempUsageWord0;
  undefined4 tempUsageWord1;
  uint tempUsageWord2;
  uint tempUsageWord3;
  uint outputBinding2Word0;
  undefined4 outputBinding2Word1;
  uint paramBinding2Word0;
  undefined4 paramBinding2Word1;
  undefined4 paramBinding2Word2;
  undefined4 paramBinding2Word3;
  uint paramBindingCount;
  undefined4 paramArrayCount;
  int packedEntryCount [5];
  
  sourceTextThenStream = programRecord[1];
  oldStreamThenParser = *programRecord;
  if (programRecord[0x12f] != 0) {
    _gleVecFree(programRecord[0x12f]);
    programRecord[0x12f] = 0;
  }
  if (oldStreamThenParser != 0) {
    _PPStreamFree(oldStreamThenParser);
    *programRecord = 0;
  }
  isFragmentProgram = programKind == 1;
  oldStreamThenParser = _PPParserCreate(isFragmentProgram << 1);
  _PPParserInit();
  if (isFragmentProgram) {
    limitsWord5ThenOutputBindingWord1 = 0x80;
    limitsWord6 = 0x40;
    limitsWord7 = 0;
    limitsWord0ThenAttribBindingWord0 = 0x80;
    limitsWord1ThenAttribBindingWord1 = 0x80;
    limitsWord14 = 0;
  }
  else {
    limitsWord14 = 0x10;
    limitsWord5ThenOutputBindingWord1 = 0x100;
    limitsWord6 = 0x20;
    limitsWord7 = 2;
    limitsWord0ThenAttribBindingWord0 = 0x100;
    limitsWord1ThenAttribBindingWord1 = 0x100;
  }
  limitsWord4ThenOutputBindingWord0 = 0x100;
  limitsWord3 = 0x8000;
  limitsWord9ThenParamBindingWord1 = 0x10;
  limitsWord10ThenParamBindingWord2 = 4;
  limitsWord11ThenParamBindingWord3 = 1;
  limitsWord12 = 6;
  limitsWord13 = 8;
  limitsWord2 = 8;
  limitsWord8ThenParamBindingWord0 = 8;
  _memcpy(oldStreamThenParser + 0x450,&limitsWord0ThenAttribBindingWord0,0x3c);
  _PPParserAttachString(oldStreamThenParser,sourceTextThenStream,1);
  sourceTextThenStream = _PPStreamCreate();
  _PPParserAttachStream(oldStreamThenParser,sourceTextThenStream);
  iVar5 = _PPParserParse(oldStreamThenParser);
  if (iVar5 == 0) {
    *(undefined8 *)(programRecord + 0x130) = *(undefined8 *)(oldStreamThenParser + 0x34);
    iVar5 = ((int (*)())_glePPPruneParamArrays)(oldStreamThenParser);
    pruneSucceeded = iVar5 == 0;
    if (pruneSucceeded) {
      iVar5 = ((int (*)())_glePPPruneAttribs)(oldStreamThenParser);
      pruneSucceeded = iVar5 == 0;
      if (!pruneSucceeded) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneOutputs)(oldStreamThenParser);
      pruneSucceeded = iVar5 == 0;
      if (!pruneSucceeded) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneLocals)(oldStreamThenParser);
      pruneSucceeded = iVar5 == 0;
      if (!pruneSucceeded) goto LAB_00022f84;
      iVar5 = ((int (*)())_glePPPruneParams)(oldStreamThenParser);
      pruneSucceeded = iVar5 == 0;
      if (!pruneSucceeded) goto LAB_00022f84;
      paramBindingList = *(int **)(sourceTextThenStream + 0x10);
      uVar24 = *(undefined4 *)(sourceTextThenStream + 0x14);
      _PPStreamChunkListGetStream(paramBindingList,0,&paramBindingCount,sourceTextThenStream);
      _PPStreamChunkListGetStream(uVar24,0,&paramArrayCount,sourceTextThenStream);
      allocatedBlock = _calloc(paramBindingCount,8);
      allocatedBlock2 = _calloc(paramArrayCount,8);
      _PPStreamChunkListGetStream(paramBindingList,allocatedBlock,&paramBindingCount,sourceTextThenStream);
      _PPStreamChunkListGetStream(uVar24,allocatedBlock2,&paramArrayCount,sourceTextThenStream);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      ((void (*)())_glePPLogParameters)(glContext,programRecord,paramBindingCount,allocatedBlock,paramArrayCount,allocatedBlock2);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      opList = *(int **)(sourceTextThenStream + 0x20);
      loopIndex = 0;
      paramArrayList = *(int **)(sourceTextThenStream + 0x14);
      opListCopy = (int *)_PPStreamChunkListCreateFromChunkList(opList);
      paramArrayListCopy = (int *)_PPStreamChunkListCreateFromChunkList(paramArrayList);
      iVar21 = *paramBindingList;
      if (paramBindingCount != 0) {
        srcCursor = (undefined4 *)(allocatedBlock + 4);
        do {
          uVar24 = *srcCursor;
          srcCursor = srcCursor + 2;
          iVar14 = *opListCopy;
          sVar12 = (short)uVar24;
          for (iVar16 = *opList; iVar16 != 0; iVar16 = *(int *)(iVar16 + 8)) {
            if ((((*(uint *)(iVar16 + 0xc) >> 0x1d != 0) &&
                 ((*(uint *)(iVar16 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
                ((*(uint *)(iVar16 + 0x1c) >> 0x17 & 7) == 2)) &&
               (*(short *)(iVar16 + 0x22) == *(short *)(iVar21 + 0x12))) {
              *(short *)(iVar14 + 0x22) = sVar12;
            }
            uVar15 = *(uint *)(iVar16 + 0xc);
            if (((1 < uVar15 >> 0x1d) && (3 < (uVar15 >> 0x12 & 0xff) - 0x41)) &&
               (((*(uint *)(iVar16 + 0x24) >> 0x17 & 7) == 2 &&
                (*(short *)(iVar16 + 0x2a) == *(short *)(iVar21 + 0x12))))) {
              *(short *)(iVar14 + 0x2a) = sVar12;
              uVar15 = *(uint *)(iVar16 + 0xc);
            }
            if (((2 < uVar15 >> 0x1d) && ((*(uint *)(iVar16 + 0x2c) >> 0x17 & 7) == 2)) &&
               (*(short *)(iVar16 + 0x32) == *(short *)(iVar21 + 0x12))) {
              *(short *)(iVar14 + 0x32) = sVar12;
            }
            iVar14 = *(int *)(iVar14 + 8);
          }
          iVar14 = *paramArrayListCopy;
          for (iVar16 = *paramArrayList; iVar16 != 0; iVar16 = *(int *)(iVar16 + 8)) {
            if (*(short *)(iVar16 + 0xe) == *(short *)(iVar21 + 0x12)) {
              oldFirstOrdinal = *(short *)(iVar14 + 0xe);
              *(short *)(iVar14 + 0xe) = sVar12;
              *(short *)(iVar14 + 0x12) = (*(short *)(iVar14 + 0x12) + sVar12) - oldFirstOrdinal;
            }
            iVar14 = *(int *)(iVar14 + 8);
          }
          *(short *)(iVar21 + 0x12) = sVar12;
          loopIndex = loopIndex + 1;
          iVar21 = *(int *)(iVar21 + 8);
        } while (loopIndex < paramBindingCount);
      }
      uVar23 = 0;
      _PPStreamChunkListSort(paramBindingList);
      iVar21 = *paramBindingList;
      uVar24 = _PPStreamChunkListCreate();
      for (; iVar21 != 0; iVar21 = *(int *)(iVar21 + 8)) {
        if ((*(ushort *)(iVar21 + 0x12) != 0) && (uVar23 < *(ushort *)(iVar21 + 0x12))) {
          do {
            fillerChunk = (undefined1 *)_calloc(0x1c,1);
            *(uint *)(fillerChunk + 0xc) = *(uint *)(fillerChunk + 0xc) & 0xffe0ffff;
            *(short *)(fillerChunk + 0x12) = (short)uVar23;
            uVar23 = uVar23 + 1;
            *fillerChunk = 3;
            _PPStreamChunkListAddChunk(uVar24,fillerChunk);
          } while (uVar23 < *(ushort *)(iVar21 + 0x12));
        }
        chunkCopy = _PPStreamChunkCreateFromChunk(iVar21);
        _PPStreamChunkListAddChunk(uVar24,chunkCopy);
        uVar23 = *(ushort *)(iVar21 + 0x12) + 1;
      }
      if (allocatedBlock != 0) {
        _free(allocatedBlock);
      }
      if (allocatedBlock2 != 0) {
        _free(allocatedBlock2);
      }
      _PPStreamAttachOperationsChunkList(sourceTextThenStream,opListCopy);
      _PPStreamAttachParamBindingsChunkList(sourceTextThenStream,uVar24);
      _PPStreamAttachParamBindingArraysChunkList(sourceTextThenStream,paramArrayListCopy);
      _PPStreamGetStream(sourceTextThenStream,0,packedEntryCount);
      iVar5 = _gleVecAlloc(packedEntryCount[0] << 3);
      _PPStreamGetStream(sourceTextThenStream,iVar5,packedEntryCount);
      *(undefined2 *)((int)programRecord + 0x46) = *(undefined2 *)(iVar5 + 0x12);
      *(undefined2 *)((int)programRecord + 0x3e) = *(undefined2 *)(iVar5 + 0x1a);
      *(undefined2 *)((int)programRecord + 0x42) = *(undefined2 *)(iVar5 + 0x22);
      *(undefined2 *)(programRecord + 0x11) = *(undefined2 *)(iVar5 + 0x2a);
      *(undefined2 *)(programRecord + 0x10) = *(undefined2 *)(iVar5 + 0x52);
      if (isFragmentProgram) {
        texOperationCount = _PPStreamGetTexOperationCount(sourceTextThenStream);
        *(undefined2 *)((int)programRecord + 0x4de) = texOperationCount;
        *(undefined2 *)(programRecord + 0x138) = 1;
        *(short *)(programRecord + 0x137) = *(short *)(programRecord + 0x10) - *(short *)((int)programRecord + 0x4de);
      }
      programRecord[0x12f] = iVar5;
      *programRecord = sourceTextThenStream;
      if (((*(byte *)(oldStreamThenParser + 0x442) & 1) != 0) &&
         ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 2) == 0)) {
        for (iVar5 = **(int **)(sourceTextThenStream + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
          limitsWord0ThenAttribBindingWord0 = *(uint *)(iVar5 + 0xc);
          limitsWord1ThenAttribBindingWord1 = *(uint *)(iVar5 + 0x10);
          if ((limitsWord0ThenAttribBindingWord0 >> 0x10 & 0xf) == 1) break;
        }
        uVar24 = *(undefined4 *)(sourceTextThenStream + 0x1c);
        limitsWord4ThenOutputBindingWord0 = 0;
        loopIndex = 0;
        limitsWord5ThenOutputBindingWord1 = 0;
        sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
        limitsWord4ThenOutputBindingWord0 = limitsWord4ThenOutputBindingWord0 & 0xfff0ffff | 0x10000;
        limitsWord5ThenOutputBindingWord1 = CONCAT22((*(unsigned short *)((unsigned char *)&(limitsWord5ThenOutputBindingWord1) + 0)),sVar12 + 1);
        _PPStreamAddOutputBinding(sourceTextThenStream,&limitsWord4ThenOutputBindingWord0);
        outputBinding2Word1 = 0;
        outputBinding2Word0 = 0;
        sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
        outputBinding2Word0 = outputBinding2Word0 & 0xfff0ffff | 0x80000;
        outputBinding2Word1 = CONCAT22((*(unsigned short *)((unsigned char *)&(outputBinding2Word1) + 0)),sVar12 + 1);
        _PPStreamAddOutputBinding(sourceTextThenStream,&outputBinding2Word0);
        uVar24 = *(undefined4 *)(sourceTextThenStream + 0x10);
        do {
          limitsWord8ThenParamBindingWord0 = 0;
          limitsWord9ThenParamBindingWord1 = 0;
          limitsWord10ThenParamBindingWord2 = 0;
          limitsWord11ThenParamBindingWord3 = 0;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          limitsWord9ThenParamBindingWord1 = CONCAT22((*(unsigned short *)((unsigned char *)&(limitsWord9ThenParamBindingWord1) + 0)),sVar12 + 1);
          if ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 1) == 0) {
            uVar15 = limitsWord8ThenParamBindingWord0 & 0xffe03fff | 0x104000;
          }
          else {
            uVar15 = limitsWord8ThenParamBindingWord0 & 0xffe03fff | 0x100000;
          }
          limitsWord8ThenParamBindingWord0 = (loopIndex & 3) << 0xc | uVar15 & 0xffffc8ff;
          loopIndex = loopIndex + 1;
          _PPStreamAddParamBinding(sourceTextThenStream,&limitsWord8ThenParamBindingWord0);
        } while (loopIndex < 4);
        uVar24 = *(undefined4 *)(sourceTextThenStream + 0x10);
        loopIndex = 0;
        do {
          paramBinding2Word0 = 0;
          paramBinding2Word1 = 0;
          paramBinding2Word2 = 0;
          paramBinding2Word3 = 0;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          paramBinding2Word1 = CONCAT22((*(unsigned short *)((unsigned char *)&(paramBinding2Word1) + 0)),sVar12 + 1);
          if ((*(ushort *)(*(int *)(glContext + 0x468c) + 0x11a) & 1) == 0) {
            uVar15 = paramBinding2Word0 & 0xffe03fff | 0x104000;
          }
          else {
            uVar15 = paramBinding2Word0 & 0xffe03fff | 0x100000;
          }
          paramBinding2Word0 = (loopIndex & 3) << 0xc | uVar15 & 0xffffc8ff | 0x300;
          loopIndex = loopIndex + 1;
          _PPStreamAddParamBinding(sourceTextThenStream,&paramBinding2Word0);
        } while (loopIndex < 4);
        rendererWord11a = *(ushort *)(*(int *)(glContext + 0x468c) + 0x11a);
        uVar23 = rendererWord11a & 1;
        if ((rendererWord11a & 1) == 0) {
          tempUsageWord0 = uVar23;
          tempUsageWord1 = uVar23;
          tempUsageWord2 = uVar23;
          tempUsageWord3 = uVar23;
          sVar12 = _PPStreamChunkListGetMaxIndex(uVar24);
          tempUsageWord1 = CONCAT22((*(unsigned short *)((unsigned char *)&(tempUsageWord1) + 0)),sVar12 + 1);
          _PPStreamAddTempUsage(sourceTextThenStream,&tempUsageWord0);
          operationWord0 = uVar23 << 0x1a | 0x40880000;
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord6 = uVar23 << 0xf |
                     uVar23 << 0x11 | uVar23 << 0x13 | uVar23 << 0x15 | uVar23 << 0x17;
          operationWord2 = 0x3e000;
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 3);
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord8 = uVar23;
          operationWord9 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord6 = uVar23 << 0x17 | 0x2a8000;
          operationWord2 = 0x3e000;
          operationWord0 = 0x68fc0000;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 2);
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord6 = uVar23 << 0x17 | 0x550000;
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord0 = 0x6cfc0000;
          operationWord2 = 0x3e000;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 1);
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord6 = uVar23 << 0x17 | 0x7f8000;
          operationWord2 = 0x7e000;
          operationWord0 = 0x6cfc0000;
          operationWord3 = limitsWord5ThenOutputBindingWord1 & 0xffff;
          operationWord5 = limitsWord9ThenParamBindingWord1 & 0xffff;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord6 = uVar23 << 0xf |
                     uVar23 << 0x11 | uVar23 << 0x13 | uVar23 << 0x15 | uVar23 << 0x17;
          operationWord0 = 0x4c880000;
          operationWord2 = 0x3e000;
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord5 = (uint)(ushort)((*(unsigned short *)((unsigned char *)&(paramBinding2Word1) + 2)) - 3);
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord8 = uVar23;
          operationWord9 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord6 = uVar23 << 0x17 | 0x2a8000;
          operationWord2 = 0x3e000;
          operationWord0 = 0x68fc0000;
          operationWord5 = (uint)(ushort)((short)paramBinding2Word1 - 2);
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord6 = uVar23 << 0x17 | 0x550000;
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord0 = 0x6cfc0000;
          operationWord2 = 0x3e000;
          operationWord5 = (uint)(ushort)((short)paramBinding2Word1 - 1);
          operationWord3 = tempUsageWord1 & 0xffff;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord1 = uVar23;
          operationWord10 = uVar23;
          operationWord11 = uVar23;
          operationWord12 = uVar23;
          operationWord13 = uVar23;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord4 = uVar23 << 0x15 | 0x10d8000;
          operationWord6 = uVar23 << 0x17 | 0x7f8000;
          operationWord8 = uVar23 << 0x15 | 0x8d8000;
          operationWord0 = 0x6cfc0000;
          operationWord2 = 0x7e000;
          operationWord9 = tempUsageWord1 & 0xffff;
          operationWord13 = uVar23;
        }
        else {
          operationWord0 = 0x40a40000;
          operationWord2 = 0x62000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = limitsWord5ThenOutputBindingWord1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 3);
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x64000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = limitsWord5ThenOutputBindingWord1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 2);
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x68000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = limitsWord5ThenOutputBindingWord1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)limitsWord9ThenParamBindingWord1 - 1);
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x70000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = limitsWord5ThenOutputBindingWord1 & 0xffff;
          operationWord5 = limitsWord9ThenParamBindingWord1 & 0xffff;
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x62000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = outputBinding2Word1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)paramBinding2Word1 - 3);
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x64000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord3 = outputBinding2Word1 & 0xffff;
          operationWord5 = (uint)(ushort)((short)paramBinding2Word1 - 2);
          operationWord1 = 0;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord0 = 0x48a40000;
          operationWord2 = 0x68000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord5 = (uint)(ushort)((short)paramBinding2Word1 - 1);
          operationWord3 = outputBinding2Word1 & 0xffff;
          operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
          operationWord1 = 0;
          operationWord8 = 0;
          operationWord9 = 0;
          operationWord10 = 0;
          operationWord11 = 0;
          operationWord12 = 0;
          operationWord13 = 0;
          _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
          operationWord13 = 0;
          operationWord0 = 0x48a40000;
          operationWord2 = 0x70000;
          operationWord4 = 0x10d8000;
          operationWord6 = 0xd8000;
          operationWord8 = 0;
          operationWord9 = 0;
        }
        operationWord7 = limitsWord1ThenAttribBindingWord1 & 0xffff;
        operationWord5 = paramBinding2Word1 & 0xffff;
        operationWord3 = outputBinding2Word1 & 0xffff;
        operationWord1 = operationWord13;
        operationWord10 = operationWord13;
        operationWord11 = operationWord13;
        operationWord12 = operationWord13;
        _PPStreamAddOperation(sourceTextThenStream,&operationWord0,0,0);
      }
      if (programKind == 0) {
        iVar5 = _PPEmulatorProgramCreate();
        ((void (*)())_PPEmulatorProgramSetupHandlesFromPPStream)(iVar5,glContext,sourceTextThenStream);
        _PPEmulatorProgramConvertFromPPStream(iVar5,sourceTextThenStream);
        if (programRecord[0x135] != 0) {
          _PPEmulatorProgramFree(programRecord[0x135]);
        }
        programRecord[0x135] = iVar5;
      }
      **(undefined1 **)(glContext + 0x5418) = 0;
      *(undefined4 *)(glContext + 0x541c) = 0xffffffff;
    }
    else {
LAB_00022f84:
      _PPParserBuildErrorString(oldStreamThenParser,iVar5,0);
    }
    if (pruneSucceeded) goto LAB_000240b0;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  _strncpy(*(char **)(glContext + 0x5418),(char *)(oldStreamThenParser + 0x3c),0x600);
  *(undefined4 *)(glContext + 0x541c) = 0;
  _PPParserAttachStream(oldStreamThenParser,0);
LAB_000240b0:
  _PPParserFree(oldStreamThenParser);
  return;
}

/* _glePPPruneParamArrays @ 0x240d4 (300 bytes) */
int _glePPPruneParamArrays(param_1)
  int param_1;
{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  piVar5 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
  piVar6 = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar7 = *piVar5;
  do {
    iVar2 = iVar7;
    if (iVar2 == 0) {
      return 0;
    }
    sVar1 = *(short *)(iVar2 + 0xe);
    for (iVar4 = *piVar6; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
      if (((((*(uint *)(iVar4 + 0xc) >> 0x1d != 0) &&
            ((*(uint *)(iVar4 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
           ((*(uint *)(iVar4 + 0x1c) >> 0x17 & 7) == 2)) &&
          ((*(short *)(iVar4 + 0x22) == sVar1 && ((int)*(uint *)(iVar4 + 0x1c) < 0)))) ||
         ((((uVar3 = *(uint *)(iVar4 + 0xc), 1 < uVar3 >> 0x1d &&
            ((3 < (uVar3 >> 0x12 & 0xff) - 0x41 && ((*(uint *)(iVar4 + 0x24) >> 0x17 & 7) == 2))))
           && ((*(short *)(iVar4 + 0x2a) == sVar1 && ((int)*(uint *)(iVar4 + 0x24) < 0)))) ||
          ((((2 < uVar3 >> 0x1d && ((*(uint *)(iVar4 + 0x2c) >> 0x17 & 7) == 2)) &&
            (*(short *)(iVar4 + 0x32) == sVar1)) && ((int)*(uint *)(iVar4 + 0x2c) < 0)))))) break;
    }
    iVar7 = *(int *)(iVar2 + 8);
    if (iVar4 == 0) {
      _PPStreamChunkListRemoveChunk(piVar5,iVar2);
    }
  } while( true );
}

/* _glePPPruneAttribs @ 0x24200 (496 bytes) */
int _glePPPruneAttribs(param_1)
  int param_1;
{
  uint loopIndex;
  int bindingEqual;
  undefined4 statusCode;
  uint instructionHeader;
  int iVar4;
  int *instructionList;
  int *attribList;
  int attribChunk;
  
  attribList = *(int **)(*(int *)(param_1 + 0x1c) + 0x18);
  instructionList = *(int **)(*(int *)(param_1 + 0x1c) + 0x20);
  iVar4 = 0;
  attribChunk = *attribList;
  if (*attribList != 0) {
    do {
      if (((*(byte *)(param_1 + 0x442) & 1) == 0) || (attribChunk != *attribList)) {
        for (iVar4 = *instructionList; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
          if ((((((*(uint *)(iVar4 + 0xc) >> 0x1d != 0) &&
                 ((*(uint *)(iVar4 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
                ((*(uint *)(iVar4 + 0x1c) & 0x3800000) == 0)) &&
               (*(short *)(iVar4 + 0x22) == *(short *)(attribChunk + 0x12))) ||
              (((instructionHeader = *(uint *)(iVar4 + 0xc), 1 < instructionHeader >> 0x1d &&
                (3 < (instructionHeader >> 0x12 & 0xff) - 0x41)) &&
               (((*(uint *)(iVar4 + 0x24) & 0x3800000) == 0 &&
                (*(short *)(iVar4 + 0x2a) == *(short *)(attribChunk + 0x12))))))) ||
             (((2 < instructionHeader >> 0x1d && ((*(uint *)(iVar4 + 0x2c) & 0x3800000) == 0)) &&
              (*(short *)(iVar4 + 0x32) == *(short *)(attribChunk + 0x12))))) {
            iVar4 = *attribList;
            goto joined_r0x0002431c;
          }
        }
LAB_0002435c:
        iVar4 = *(int *)(attribChunk + 8);
        _PPStreamChunkListRemoveChunk(attribList,attribChunk);
      }
      else {
LAB_00024370:
        iVar4 = *(int *)(attribChunk + 8);
      }
      attribChunk = iVar4;
    } while (iVar4 != 0);
    iVar4 = *attribList;
  }
  loopIndex = 0;
  for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (loopIndex != *(ushort *)(iVar4 + 0x12)) {
      _glePPRelocateAttrib((uint)*(ushort *)(iVar4 + 0x12),loopIndex,instructionList);
      *(short *)(iVar4 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  statusCode = 0x35;
  if ((uint)attribList[2] <= *(uint *)(param_1 + 0x468)) {
    statusCode = 0;
  }
  return statusCode;
joined_r0x0002431c:
  if (iVar4 == attribChunk) goto LAB_00024370;
  bindingEqual = _PPStreamAttribBindingIsEqual(attribChunk + 0xc,iVar4 + 0xc);
  if (bindingEqual != 0) {
    _glePPRelocateAttrib((uint)*(ushort *)(attribChunk + 0x12),(uint)*(ushort *)(iVar4 + 0x12),instructionList);
    goto LAB_0002435c;
  }
  iVar4 = *(int *)(iVar4 + 8);
  goto joined_r0x0002431c;
}

/* _glePPPruneOutputs @ 0x243f0 (344 bytes) */
int _glePPPruneOutputs(ppProgram)
  int ppProgram;
{
  int bindingEqual;
  int instructionThenOutputChunkCursor;
  int *instructionList;
  int *outputList;
  uint loopIndex;
  int outputChunk;
  
  outputList = *(int **)(*(int *)(ppProgram + 0x1c) + 0x1c);
  instructionList = *(int **)(*(int *)(ppProgram + 0x1c) + 0x20);
  instructionThenOutputChunkCursor = 0;
  outputChunk = *outputList;
  if (*outputList != 0) {
LAB_00024424:
    for (instructionThenOutputChunkCursor = *instructionList; instructionThenOutputChunkCursor != 0; instructionThenOutputChunkCursor = *(int *)(instructionThenOutputChunkCursor + 8)) {
      if ((((*(uint *)(instructionThenOutputChunkCursor + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(instructionThenOutputChunkCursor + 0x14) >> 0x11 & 7) == 3)) &&
         (*(short *)(instructionThenOutputChunkCursor + 0x1a) == *(short *)(outputChunk + 0x12))) {
        instructionThenOutputChunkCursor = *outputList;
        goto joined_r0x00024488;
      }
    }
LAB_000244c8:
    instructionThenOutputChunkCursor = *(int *)(outputChunk + 8);
    _PPStreamChunkListRemoveChunk(outputList,outputChunk);
    goto LAB_000244e0;
  }
LAB_000244ec:
  loopIndex = 0;
  for (; instructionThenOutputChunkCursor != 0; instructionThenOutputChunkCursor = *(int *)(instructionThenOutputChunkCursor + 8)) {
    if (loopIndex != *(ushort *)(instructionThenOutputChunkCursor + 0x12)) {
      _glePPRelocateOutput((uint)*(ushort *)(instructionThenOutputChunkCursor + 0x12),loopIndex,instructionList);
      *(short *)(instructionThenOutputChunkCursor + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  return 0;
joined_r0x00024488:
  if (instructionThenOutputChunkCursor == outputChunk) goto LAB_000244dc;
  bindingEqual = _PPStreamOutputBindingIsEqual(outputChunk + 0xc,instructionThenOutputChunkCursor + 0xc);
  if (bindingEqual != 0) {
    _glePPRelocateOutput((uint)*(ushort *)(outputChunk + 0x12),(uint)*(ushort *)(instructionThenOutputChunkCursor + 0x12),instructionList);
    goto LAB_000244c8;
  }
  instructionThenOutputChunkCursor = *(int *)(instructionThenOutputChunkCursor + 8);
  goto joined_r0x00024488;
LAB_000244dc:
  instructionThenOutputChunkCursor = *(int *)(outputChunk + 8);
LAB_000244e0:
  outputChunk = instructionThenOutputChunkCursor;
  if (instructionThenOutputChunkCursor == 0) goto code_r0x000244e8;
  goto LAB_00024424;
code_r0x000244e8:
  instructionThenOutputChunkCursor = *outputList;
  goto LAB_000244ec;
}

/* _glePPPruneLocals @ 0x24548 (412 bytes) */
int _glePPPruneLocals(program)
  int program;
{
  uint loopIndex;
  uint instructionHeader;
  int chunkCursor;
  int nextChunk;
  int instruction;
  int *instructionList;
  int *localList;
  int localChunk;
  
  localList = *(int **)(*(int *)(program + 0x1c) + 4);
  instructionList = *(int **)(*(int *)(program + 0x1c) + 0x20);
  chunkCursor = 0;
  localChunk = *localList;
  if (*localList != 0) {
    do {
      for (instruction = *instructionList; instruction != 0; instruction = *(int *)(instruction + 8)) {
        if (((((((*(uint *)(instruction + 0xc) >> 0x12 & 0xff) < 0x4b) &&
               ((*(uint *)(instruction + 0x14) >> 0x11 & 7) == 1)) &&
              (*(short *)(instruction + 0x1a) == *(short *)(localChunk + 0x12))) ||
             (((instructionHeader = *(uint *)(instruction + 0xc), instructionHeader >> 0x1d != 0 &&
               ((instructionHeader >> 0x12 & 0xff) != 0x4a)) &&
              (((*(uint *)(instruction + 0x1c) >> 0x17 & 7) == 1 &&
               (*(short *)(instruction + 0x22) == *(short *)(localChunk + 0x12))))))) ||
            (((1 < instructionHeader >> 0x1d && (3 < (instructionHeader >> 0x12 & 0xff) - 0x41)) &&
             (((*(uint *)(instruction + 0x24) >> 0x17 & 7) == 1 &&
              (*(short *)(instruction + 0x2a) == *(short *)(localChunk + 0x12))))))) ||
           (((2 < instructionHeader >> 0x1d && ((*(uint *)(instruction + 0x2c) >> 0x17 & 7) == 1)) &&
            (*(short *)(instruction + 0x32) == *(short *)(localChunk + 0x12))))) {
          nextChunk = *(int *)(localChunk + 8);
          goto LAB_00024684;
        }
      }
      nextChunk = *(int *)(localChunk + 8);
      _PPStreamChunkListRemoveChunk(localList,localChunk);
LAB_00024684:
      localChunk = nextChunk;
    } while (nextChunk != 0);
    chunkCursor = *localList;
  }
  loopIndex = 0;
  for (; chunkCursor != 0; chunkCursor = *(int *)(chunkCursor + 8)) {
    if (loopIndex != *(ushort *)(chunkCursor + 0x12)) {
      _glePPRelocateLocal((uint)*(ushort *)(chunkCursor + 0x12),loopIndex,instructionList);
      *(short *)(chunkCursor + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  return 0;
}

/* _glePPPruneParams @ 0x246e4 (648 bytes) */
int _glePPPruneParams(param_1)
  int param_1;
{
  uint loopIndex;
  int iVar1;
  int iVar2;
  undefined4 statusCode;
  uint instructionHeader;
  int *paramArrayList;
  int *instructionList;
  int *paramList;
  int iVar8;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  paramList = *(int **)(iVar1 + 0x10);
  paramArrayList = *(int **)(iVar1 + 0x14);
  iVar8 = *paramList;
  instructionList = *(int **)(iVar1 + 0x20);
  iVar1 = 0;
  if (iVar8 != 0) {
    do {
      iVar1 = *paramArrayList;
      if (iVar1 == 0) break;
      do {
        if ((*(ushort *)(iVar1 + 0xe) <= *(ushort *)(iVar8 + 0x12)) &&
           (*(ushort *)(iVar8 + 0x12) <= *(ushort *)(iVar1 + 0x12))) {
          *(undefined4 *)(iVar8 + 0x14) = 1;
          break;
        }
        iVar1 = *(int *)(iVar1 + 8);
      } while (iVar1 != 0);
      iVar8 = *(int *)(iVar8 + 8);
    } while (iVar8 != 0);
    iVar1 = *paramList;
  }
  iVar8 = 0;
  if (iVar1 != 0) {
LAB_0002477c:
    if (*(int *)(iVar1 + 0x14) != 0) {
LAB_00024868:
      iVar8 = *paramList;
joined_r0x00024874:
      do {
        if (iVar8 == 0) goto LAB_000248e8;
        if ((iVar1 + 0xc != iVar8 + 0xc) &&
           (iVar2 = _PPStreamParamBindingIsEqual(iVar1 + 0xc,iVar8 + 0xc), iVar2 != 0)) {
          if (*(int *)(iVar8 + 0x14) == 0) {
            _glePPRelocateParam((uint)*(ushort *)(iVar8 + 0x12),(uint)*(ushort *)(iVar1 + 0x12),
                                instructionList,0);
            iVar2 = *(int *)(iVar8 + 8);
            _PPStreamChunkListRemoveChunk(paramList,iVar8);
            iVar8 = iVar2;
            goto joined_r0x00024874;
          }
          if (*(int *)(iVar1 + 0x14) != 0) {
            return 0x29;
          }
        }
        iVar8 = *(int *)(iVar8 + 8);
      } while( true );
    }
    for (iVar8 = *instructionList; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
      if ((((((*(uint *)(iVar8 + 0xc) >> 0x1d != 0) &&
             ((*(uint *)(iVar8 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
            ((*(uint *)(iVar8 + 0x1c) >> 0x17 & 7) == 2)) &&
           (*(short *)(iVar8 + 0x22) == *(short *)(iVar1 + 0x12))) ||
          (((instructionHeader = *(uint *)(iVar8 + 0xc), 1 < instructionHeader >> 0x1d &&
            (3 < (instructionHeader >> 0x12 & 0xff) - 0x41)) &&
           (((*(uint *)(iVar8 + 0x24) >> 0x17 & 7) == 2 &&
            (*(short *)(iVar8 + 0x2a) == *(short *)(iVar1 + 0x12))))))) ||
         (((2 < instructionHeader >> 0x1d && ((*(uint *)(iVar8 + 0x2c) >> 0x17 & 7) == 2)) &&
          (*(short *)(iVar8 + 0x32) == *(short *)(iVar1 + 0x12))))) goto LAB_00024868;
    }
    iVar8 = *(int *)(iVar1 + 8);
    _PPStreamChunkListRemoveChunk(paramList,iVar1);
    goto LAB_000248ec;
  }
LAB_000248f8:
  loopIndex = 0;
  for (; iVar8 != 0; iVar8 = *(int *)(iVar8 + 8)) {
    *(undefined4 *)(iVar8 + 0x14) = 0;
    if (loopIndex != *(ushort *)(iVar8 + 0x12)) {
      _glePPRelocateParam((uint)*(ushort *)(iVar8 + 0x12),loopIndex,instructionList,paramArrayList);
      *(short *)(iVar8 + 0x12) = (short)loopIndex;
    }
    loopIndex = loopIndex + 1;
  }
  statusCode = 0x34;
  if ((uint)paramList[2] <= *(uint *)(param_1 + 0x464)) {
    statusCode = 0;
  }
  return statusCode;
LAB_000248e8:
  iVar8 = *(int *)(iVar1 + 8);
LAB_000248ec:
  iVar1 = iVar8;
  if (iVar8 == 0) goto code_r0x000248f4;
  goto LAB_0002477c;
code_r0x000248f4:
  iVar8 = *paramList;
  goto LAB_000248f8;
}

/* _glePPLogParameters @ 0x2496c (728 bytes) */
void _glePPLogParameters(glContext, program, paramCount, paramEntries, paramArrayCount, paramArrays)
  int glContext;
  int program;
  uint paramCount;
  int paramEntries;
  uint paramArrayCount;
  int paramArrays;
{
  uint loopIndex5;
  uint loopIndex4;
  uint loopIndex3;
  int loopIndex;
  int remaining;
  uint lastSlot;
  int iVar2;
  undefined4 *cursor;
  undefined2 slotResult;
  int iVar5;
  uint *srcCursor;
  uint bankIndex;
  int sharedState;
  uint rangeEnd;
  int iVar10;
  uint loopIndex2;
  uint paramIndex;
  uint uVar13;
  undefined4 blockedSlotBits [12];
  uint local_70;
  uint local_6c;
  uint arrayStartWord;
  uint arrayEndWord;
  
  loopIndex2 = 0;
  bankIndex = (uint)*(ushort *)(program + 0x4ba);
  sharedState = *(int *)(glContext + 0x5148);
  iVar5 = bankIndex * 0xa30 + sharedState;
  iVar2 = *(int *)(iVar5 + 0x8a98) + 1;
  *(int *)(iVar5 + 0x8a98) = iVar2;
  *(int *)(program + 0x14) = iVar2;
  lastSlot = 0;
  if (*(uint *)(iVar5 + 0x8a9c) != 0) {
    srcCursor = *(uint **)(iVar5 + 0x8aa0);
    do {
      lastSlot = *srcCursor;
      srcCursor = srcCursor + 1;
      if (paramCount <= lastSlot) break;
      loopIndex2 = loopIndex2 + 1;
      lastSlot = 0;
    } while (loopIndex2 < *(uint *)(iVar5 + 0x8a9c));
  }
  loopIndex3 = 0;
  do {
    cursor = blockedSlotBits;
    remaining = 9;
    do {
      *cursor = 0;
      cursor = cursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    loopIndex = 0;
    for (uVar13 = paramCount; uVar13 != 0; uVar13 = uVar13 - 1) {
      iVar5 = loopIndex * 8;
      loopIndex = loopIndex + 1;
      *(uint *)(iVar5 + paramEntries) = *(uint *)(iVar5 + paramEntries) & 0xff1fffff;
    }
    loopIndex5 = 0;
    iVar2 = -1;
    if (paramArrayCount != 0) {
      do {
        arrayStartWord = *(uint *)(paramArrays + loopIndex5 * 8);
        arrayEndWord = *(uint *)(loopIndex5 * 8 + paramArrays + 4);
        paramIndex = arrayStartWord & 0xffff;
        rangeEnd = (arrayEndWord & 0xffff) + 1;
        if (loopIndex3 <= loopIndex5) {
          iVar5 = paramIndex * 8;
          iVar10 = iVar5 + paramEntries;
          local_70 = *(undefined4 *)(iVar5 + paramEntries);
          local_6c = *(uint *)(iVar10 + 4) & 0xffff0000;
          iVar2 = ((int (*)())_glePPLogParam)(glContext,sharedState,bankIndex,local_70,local_6c,rangeEnd - paramIndex,0xffffffff,
                                 blockedSlotBits,lastSlot);
          if (iVar2 < 0) break;
          paramIndex = paramIndex + 1;
          *(uint *)(iVar5 + paramEntries) = local_70;
          *(uint *)(iVar10 + 4) = local_6c;
          *(short *)(iVar10 + 6) = (short)iVar2;
          *(uint *)(iVar5 + paramEntries) = *(uint *)(iVar5 + paramEntries) & 0xff1fffff | 0x200000;
        }
        for (; paramIndex < rangeEnd; paramIndex = paramIndex + 1) {
          iVar5 = paramIndex * 8;
          iVar10 = iVar5 + paramEntries;
          local_70 = *(undefined4 *)(iVar5 + paramEntries);
          local_6c = *(uint *)(iVar10 + 4) & 0xffff0000;
          iVar2 = ((int (*)())_glePPLogParam)(glContext,sharedState,bankIndex,local_70,local_6c,1,iVar2 + 1,blockedSlotBits,lastSlot);
          *(uint *)(iVar5 + paramEntries) = local_70;
          *(uint *)(iVar10 + 4) = local_6c;
          *(short *)(iVar10 + 6) = (short)iVar2;
          *(uint *)(iVar5 + paramEntries) = *(uint *)(iVar5 + paramEntries) & 0xff1fffff | 0x200000;
        }
        loopIndex5 = loopIndex5 + 1;
      } while (loopIndex5 < paramArrayCount);
    }
    if ((loopIndex5 == paramArrayCount) || (loopIndex3 = loopIndex3 + 1, paramArrayCount < loopIndex3)) {
      loopIndex4 = 0;
      if (paramCount != 0) {
        do {
          iVar2 = loopIndex4 * 8;
          local_70 = *(uint *)(iVar2 + paramEntries);
          iVar5 = iVar2 + paramEntries;
          if ((local_70 >> 0x15 & 7) == 0) {
            local_6c = *(uint *)(iVar5 + 4) & 0xffff0000;
            slotResult = ((int (*)())_glePPLogParam)(glContext,sharedState,bankIndex,local_70,local_6c,1,0xffffffff,blockedSlotBits,lastSlot
                                  );
            *(uint *)(iVar2 + paramEntries) = local_70;
            *(uint *)(iVar5 + 4) = local_6c;
            *(undefined2 *)(iVar5 + 6) = slotResult;
            *(uint *)(iVar2 + paramEntries) = *(uint *)(iVar2 + paramEntries) & 0xff1fffff | 0x200000;
          }
          loopIndex4 = loopIndex4 + 1;
        } while (loopIndex4 < paramCount);
      }
      return;
    }
  } while( true );
}

/* _glePPLogParam @ 0x24c44 (1068 bytes) */
int _glePPLogParam(glContext, paramLogState, bankIndex, paramWord, paramWord2, slotSpan, requestedSlot, blockedSlotBits, lastSlot)
  int glContext;
  int paramLogState;
  int bankIndex;
  uint paramWord;
  int paramWord2;
  int slotSpan;
  uint requestedSlot;
  int blockedSlotBits;
  int lastSlot;
{
  bool slotIsUnused;
  int slotRecord;
  int slotRecordThenSlotWord2;
  int slotWordIndex;
  int slotScanCursor;
  undefined4 matchKind;
  int slotWord2ThenSlotRecordThenPriorityRowOffset;
  int freeBitsWordThenDirtyBitsWordThenSlotRecord;
  int freeBitsWordCase4;
  uint paramKind;
  uint slotWord1;
  uint slotPriority;
  uint spanEnd;
  uint evictionSlot;
  uint slotBit;
  uint slotValue1;
  uint oldSlotBits;
  uint unusedSlot;
  uint freeSlot;
  uint lowestPriority;
  short oldPriority;
  
  paramKind = paramWord >> 0x10 & 0x1f;
  lowestPriority = 0x7fffffff;
  unusedSlot = 0xffffffff;
  freeSlot = 0xffffffff;
  evictionSlot = 0xffffffff;
  if (paramKind == 0) {
    return 0;
  }
  if ((paramKind == 1) || (paramKind == 0x11)) {
    if (-1 < (int)requestedSlot) {
      if ((*(uint *)(blockedSlotBits + ((int)requestedSlot >> 5) * 4) >> (requestedSlot & 0x1f) & 1) != 0) {
        return 0xffffffff;
      }
      matchKind = 1;
      slotRecord = (bankIndex * 0x146 + requestedSlot) * 8 + paramLogState;
      slotIsUnused = *(int *)(slotRecord + 0x8074) == 0 && *(int *)(slotRecord + 0x8078) == 0;
      goto LAB_00024ea0;
    }
    freeSlot = 0;
    if (lastSlot - slotSpan == -1) {
      return 0xffffffff;
    }
    slotScanCursor = bankIndex * 0xa30 + paramLogState + 0x8070;
    do {
      for (spanEnd = freeSlot;
          ((int)spanEnd < (int)(freeSlot + slotSpan) &&
          ((*(uint *)(blockedSlotBits + ((int)spanEnd >> 5) * 4) >> (spanEnd & 0x1f) & 1) == 0));
          spanEnd = spanEnd + 1) {
      }
      if (spanEnd == freeSlot + slotSpan) {
        if ((*(int *)(slotScanCursor + 4) == -1) && (*(int *)(slotScanCursor + 8) == -1)) goto LAB_00024ff0;
        if (*(int *)(slotScanCursor + 4) == 0 && *(int *)(slotScanCursor + 8) == 0) {
          if (unusedSlot == 0xffffffff) {
            unusedSlot = freeSlot;
          }
        }
        else {
          slotPriority = (uint)*(ushort *)((bankIndex * 0x518 + freeSlot) * 2 + paramLogState + 0x8874);
          if (slotPriority < lowestPriority) {
            evictionSlot = freeSlot;
            lowestPriority = slotPriority;
          }
        }
      }
      freeSlot = freeSlot + 1;
      slotScanCursor = slotScanCursor + 8;
    } while (freeSlot < (lastSlot - slotSpan) + 1U);
    requestedSlot = evictionSlot;
    if (unusedSlot != 0xffffffff) {
      matchKind = 1;
      requestedSlot = unusedSlot;
      goto LAB_00025008;
    }
LAB_00024fd4:
    if (requestedSlot == 0xffffffff) {
      return 0xffffffff;
    }
  }
  else {
    if ((int)requestedSlot < 0) {
      requestedSlot = 0;
      if (lastSlot - slotSpan == -1) {
        return 0xffffffff;
      }
      slotScanCursor = bankIndex * 0xa30 + paramLogState + 0x8070;
      do {
        for (spanEnd = requestedSlot;
            ((int)spanEnd < (int)(requestedSlot + slotSpan) &&
            ((*(uint *)(blockedSlotBits + ((int)spanEnd >> 5) * 4) >> (spanEnd & 0x1f) & 1) == 0));
            spanEnd = spanEnd + 1) {
        }
        if (spanEnd == requestedSlot + slotSpan) {
          slotWord1 = *(uint *)(slotScanCursor + 4);
          slotWord2ThenSlotRecordThenPriorityRowOffset = *(int *)(slotScanCursor + 8);
          if ((slotWord1 == paramWord) && (slotWord2ThenSlotRecordThenPriorityRowOffset == paramWord2)) {
            matchKind = 5;
            goto LAB_00025008;
          }
          if ((slotWord1 == 0xffffffff) && (slotWord2ThenSlotRecordThenPriorityRowOffset == -1)) {
            if (freeSlot == 0xffffffff) {
              freeSlot = requestedSlot;
            }
          }
          else if (slotWord1 == 0 && slotWord2ThenSlotRecordThenPriorityRowOffset == 0) {
            if (unusedSlot == 0xffffffff) {
              unusedSlot = requestedSlot;
            }
          }
          else {
            slotPriority = (uint)*(ushort *)((bankIndex * 0x518 + requestedSlot) * 2 + paramLogState + 0x8874);
            if (slotPriority < lowestPriority) {
              evictionSlot = requestedSlot;
              lowestPriority = slotPriority;
            }
          }
        }
        requestedSlot = requestedSlot + 1;
        slotScanCursor = slotScanCursor + 8;
      } while (requestedSlot < (lastSlot - slotSpan) + 1U);
      if (unusedSlot != 0xffffffff) {
        matchKind = 2;
        requestedSlot = unusedSlot;
        goto LAB_00025008;
      }
      requestedSlot = evictionSlot;
      if (freeSlot != 0xffffffff) {
LAB_00024ff0:
        matchKind = 3;
        requestedSlot = freeSlot;
        goto LAB_00025008;
      }
      goto LAB_00024fd4;
    }
    if ((*(uint *)(blockedSlotBits + ((int)requestedSlot >> 5) * 4) >> (requestedSlot & 0x1f) & 1) != 0) {
      return 0xffffffff;
    }
    slotRecordThenSlotWord2 = (bankIndex * 0x146 + requestedSlot) * 8 + paramLogState;
    slotValue1 = *(uint *)(slotRecordThenSlotWord2 + 0x8074);
    slotRecordThenSlotWord2 = *(int *)(slotRecordThenSlotWord2 + 0x8078);
    if (((slotValue1 == paramWord) && (matchKind = 5, slotRecordThenSlotWord2 == paramWord2)) ||
       ((slotValue1 == 0xffffffff && (matchKind = 3, slotRecordThenSlotWord2 == -1)))) goto LAB_00025008;
    slotIsUnused = slotValue1 == 0 && slotRecordThenSlotWord2 == 0;
    matchKind = 2;
LAB_00024ea0:
    if (slotIsUnused) goto LAB_00025008;
  }
  matchKind = 4;
LAB_00025008:
  slotWordIndex = (int)requestedSlot >> 5;
                    
  switch(matchKind) {
  case 0:
    slotWord2ThenSlotRecordThenPriorityRowOffset = bankIndex * 0x518;
    oldPriority = 0;
    break;
  case 1:
    slotWord2ThenSlotRecordThenPriorityRowOffset = (bankIndex * 0x146 + requestedSlot) * 8 + paramLogState;
    freeBitsWordThenDirtyBitsWordThenSlotRecord = (bankIndex * 0x28c + slotWordIndex) * 4 + paramLogState;
    *(undefined4 *)(slotWord2ThenSlotRecordThenPriorityRowOffset + 0x8074) = 0xffffffff;
    *(undefined4 *)(slotWord2ThenSlotRecordThenPriorityRowOffset + 0x8078) = 0xffffffff;
    slotWord2ThenSlotRecordThenPriorityRowOffset = bankIndex * 0x518;
    oldPriority = 0;
    *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8a74) = *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8a74) | 1 << (requestedSlot & 0x1f);
    break;
  case 2:
    freeBitsWordThenDirtyBitsWordThenSlotRecord = (bankIndex * 0x28c + slotWordIndex) * 4 + paramLogState;
    oldSlotBits = *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8a74);
    slotWord2ThenSlotRecordThenPriorityRowOffset = (bankIndex * 0x146 + requestedSlot) * 8 + paramLogState;
    slotBit = 1 << (requestedSlot & 0x1f);
    *(uint *)(slotWord2ThenSlotRecordThenPriorityRowOffset + 0x8074) = paramWord;
    *(int *)(slotWord2ThenSlotRecordThenPriorityRowOffset + 0x8078) = paramWord2;
    oldPriority = 0;
    *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8a74) = oldSlotBits & ~slotBit;
    if (bankIndex == 0) {
      slotWord2ThenSlotRecordThenPriorityRowOffset = 0;
      freeBitsWordThenDirtyBitsWordThenSlotRecord = slotWordIndex * 4 + glContext;
      *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x324) = *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x324) | slotBit;
    }
    else {
      slotWord2ThenSlotRecordThenPriorityRowOffset = bankIndex * 0x518;
      freeBitsWordThenDirtyBitsWordThenSlotRecord = slotWordIndex * 4 + glContext;
      *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x348) = *(uint *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x348) | slotBit;
    }
    break;
  case 5:
  case 3:
    slotWord2ThenSlotRecordThenPriorityRowOffset = bankIndex * 0x518;
    oldPriority = *(short *)((slotWord2ThenSlotRecordThenPriorityRowOffset + requestedSlot) * 2 + paramLogState + 0x8874);
    break;
  case 4:
    slotWord2ThenSlotRecordThenPriorityRowOffset = bankIndex * 0x518;
    freeBitsWordThenDirtyBitsWordThenSlotRecord = (bankIndex * 0x146 + requestedSlot) * 8 + paramLogState;
    freeBitsWordCase4 = (bankIndex * 0x28c + slotWordIndex) * 4 + paramLogState;
    oldPriority = *(short *)((slotWord2ThenSlotRecordThenPriorityRowOffset + requestedSlot) * 2 + paramLogState + 0x8874);
    *(undefined4 *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8074) = 0xffffffff;
    *(undefined4 *)(freeBitsWordThenDirtyBitsWordThenSlotRecord + 0x8078) = 0xffffffff;
    *(uint *)(freeBitsWordCase4 + 0x8a74) = *(uint *)(freeBitsWordCase4 + 0x8a74) | 1 << (requestedSlot & 0x1f);
  }
  *(uint *)(slotWordIndex * 4 + blockedSlotBits) = *(uint *)(slotWordIndex * 4 + blockedSlotBits) | 1 << (requestedSlot & 0x1f);
  *(short *)((slotWord2ThenSlotRecordThenPriorityRowOffset + requestedSlot) * 2 + paramLogState + 0x8874) = oldPriority + 1;
  return requestedSlot;
}

/* _PPEmulatorProgramSetupHandlesFromPPStream @ 0x25218 (844 bytes) */
void _PPEmulatorProgramSetupHandlesFromPPStream(emulatorProgram, glContext, ppStream)
  int emulatorProgram;
  undefined4 glContext;
  int ppStream;
{
  int loopIndex;
  uint operandKind;
  int resultHandleBank;
  int parameterHandleBank;
  int identityHandleBank;
  int handleEntry;
  int indexHandleBank;
  int tempCountThenRemaining;
  int parameterChunk;
  int identityMappedChunk;
  int resultChunk;
  uint operandDescriptor;
  undefined4 operandDescriptorWord2;
  undefined1 chunkEntryCount [4];
  int handleOffset;
  undefined1 resultComponentStride [4];
  int componentStride [2];
  
  tempCountThenRemaining = 0;
  if (*(int *)(*(int *)(ppStream + 4) + 8) != 0) {
    tempCountThenRemaining = _PPStreamChunkListGetMaxIndex(*(int *)(ppStream + 4));
    tempCountThenRemaining = tempCountThenRemaining + 1;
  }
  _PPEmulatorProgramInitialiseHandleBanks
            (emulatorProgram,tempCountThenRemaining,*(undefined4 *)(*(int *)(ppStream + 0x1c) + 8),
             *(undefined4 *)(*(int *)(ppStream + 0x18) + 8),
             *(undefined4 *)(*(int *)(ppStream + 0x10) + 8));
  loopIndex = 0;
  indexHandleBank = *(int *)(emulatorProgram + 0x80);
  for (; tempCountThenRemaining != 0; tempCountThenRemaining = tempCountThenRemaining + -1) {
    handleOffset = loopIndex * 0x10;
    loopIndex = loopIndex + 1;
    *(int *)(handleOffset + indexHandleBank) = handleOffset;
    handleEntry = handleOffset + indexHandleBank;
    *(int *)(handleEntry + 4) = handleOffset + 4;
    *(int *)(handleEntry + 8) = handleOffset + 8;
    *(int *)(handleEntry + 0xc) = handleOffset + 0xc;
  }
  resultHandleBank = *(int *)(emulatorProgram + 0x8c);
  for (resultChunk = **(int **)(ppStream + 0x1c); resultChunk != 0; resultChunk = *(int *)(resultChunk + 8)) {
    _PPStreamChunkGetStream(&operandDescriptor,resultChunk,ppStream,chunkEntryCount,0);
    ((void (*)())_gleVPGetResultOffset)(glContext,operandDescriptor,operandDescriptorWord2,&handleOffset,resultComponentStride);
    *(int *)(resultHandleBank + (uint)*(ushort *)(resultChunk + 0x12) * 0x10) = handleOffset;
    *(int *)((uint)*(ushort *)(resultChunk + 0x12) * 0x10 + resultHandleBank + 4) = handleOffset + 4;
    *(int *)((uint)*(ushort *)(resultChunk + 0x12) * 0x10 + resultHandleBank + 8) = handleOffset + 8;
    *(int *)((uint)*(ushort *)(resultChunk + 0x12) * 0x10 + resultHandleBank + 0xc) = handleOffset + 0xc;
  }
  identityHandleBank = *(int *)(emulatorProgram + 0x98);
  for (identityMappedChunk = **(int **)(ppStream + 0x18); identityMappedChunk != 0; identityMappedChunk = *(int *)(identityMappedChunk + 8)) {
    handleOffset = (uint)*(ushort *)(identityMappedChunk + 0x12) * 0x10;
    *(int *)(identityHandleBank + (uint)*(ushort *)(identityMappedChunk + 0x12) * 0x10) = handleOffset;
    *(int *)((uint)*(ushort *)(identityMappedChunk + 0x12) * 0x10 + identityHandleBank + 4) = handleOffset + 4;
    *(int *)((uint)*(ushort *)(identityMappedChunk + 0x12) * 0x10 + identityHandleBank + 8) = handleOffset + 8;
    *(int *)((uint)*(ushort *)(identityMappedChunk + 0x12) * 0x10 + identityHandleBank + 0xc) = handleOffset + 0xc;
  }
  parameterHandleBank = *(int *)(emulatorProgram + 0xa4);
  for (parameterChunk = **(int **)(ppStream + 0x10); parameterChunk != 0; parameterChunk = *(int *)(parameterChunk + 8)) {
    operandKind = *(uint *)(parameterChunk + 0xc) >> 0x10 & 0x1f;
    if ((operandKind == 1) || (operandKind == 0x11)) {
      _PPStreamChunkGetStream(&operandDescriptor,parameterChunk,ppStream,chunkEntryCount,0);
      handleOffset = (operandDescriptor & 0xffff) * 0x10;
      *(int *)(parameterHandleBank + (uint)*(ushort *)(parameterChunk + 0x12) * 0x10) = handleOffset;
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 4) = handleOffset + 4;
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 8) = handleOffset + 8;
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 0xc) = handleOffset + 0xc;
    }
    else {
      _PPStreamChunkGetStream(&operandDescriptor,parameterChunk,ppStream,chunkEntryCount,0);
      ((void (*)())_gleVPGetParameterPtr)(glContext,operandDescriptor,operandDescriptorWord2,&handleOffset,componentStride);
      *(int *)(parameterHandleBank + (uint)*(ushort *)(parameterChunk + 0x12) * 0x10) = handleOffset;
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 4) = handleOffset + componentStride[0];
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 8) = handleOffset + componentStride[0] * 2;
      *(int *)((uint)*(ushort *)(parameterChunk + 0x12) * 0x10 + parameterHandleBank + 0xc) = handleOffset + componentStride[0] * 3;
    }
  }
  return;
}

/* _gleVPGetResultOffset @ 0x25564 (204 bytes) */
void _gleVPGetResultOffset(glContext, operandDescriptor, unusedArg3, outOffset, outComponentStride)
  undefined4 glContext;
  uint operandDescriptor;
  undefined4 unusedArg3;
  int *outOffset;
  undefined4 *outComponentStride;
{
  int vertexRecordOffset;
  
  *outComponentStride = 4;
  switch(operandDescriptor >> 0x10 & 0xf) {
  case 0:
  case 7:
    return;
  case 1:
    vertexRecordOffset = 0x10;
    break;
  case 2:
    vertexRecordOffset = 0x5c;
    *outComponentStride = 1;
    goto LAB_00025630;
  case 3:
    *outComponentStride = 1;
    *outOffset = 0x70;
    return;
  case 4:
    if ((operandDescriptor & 1) == 0) {
      vertexRecordOffset = 0x30;
      break;
    }
  case 8:
    vertexRecordOffset = 0x20;
    break;
  case 5:
    *outComponentStride = 3;
    if ((operandDescriptor & 1) == 0) {
      vertexRecordOffset = 0x50;
    }
    else {
      vertexRecordOffset = 0x40;
    }
    break;
  case 6:
    vertexRecordOffset = (operandDescriptor & 0x1f) * 0x10 + 0x80;
LAB_00025630:
    *outOffset = vertexRecordOffset;
    return;
  default:
    return;
  }
  *outOffset = vertexRecordOffset;
  return;
}

/* _gleVPGetParameterPtr @ 0x25654 (972 bytes) */
void _gleVPGetParameterPtr(glContext, operandDescriptor, unusedArg3, outOffset, outComponentStride)
  undefined4 glContext;
  uint operandDescriptor;
  undefined4 unusedArg3;
  int *outOffset;
  undefined4 *outComponentStride;
{
  uint uVar1;
  int contextOffset;
  uint uVar3;
  uint uVar4;
  
  *outComponentStride = 4;
  switch(operandDescriptor >> 0x10 & 0x1f) {
  case 0:
  case 1:
  case 9:
  case 0x11:
    return;
  case 2:
    contextOffset = (operandDescriptor & 0xffff) * 0x10 + 0x10;
    break;
  case 3:
    uVar1 = operandDescriptor & 0xff;
    switch(operandDescriptor >> 8 & 0xf) {
    case 0:
      contextOffset = uVar1 * 0x80 + 0x24c0;
      break;
    case 1:
      contextOffset = uVar1 * 0x80 + 0x24d0;
      break;
    case 2:
      contextOffset = uVar1 * 0x80 + 0x24e0;
      break;
    case 3:
      contextOffset = uVar1 * 0x80 + 0x24f0;
      break;
    case 4:
      contextOffset = uVar1 * 0x80 + 0x2500;
      break;
    case 5:
      contextOffset = uVar1 * 0x80 + 0x2510;
      break;
    case 6:
      contextOffset = uVar1 * 0x80 + 0x2520;
      break;
    case 7:
      contextOffset = uVar1 * 0x80 + 0x2530;
      break;
    default:
      return;
    }
    break;
  case 4:
    uVar3 = operandDescriptor >> 9 & 3;
    uVar1 = operandDescriptor & 0xff;
    uVar4 = operandDescriptor >> 8 & 1;
    if (uVar3 == 1) {
      contextOffset = uVar4 * 0x240 + uVar1 * 0x30 + 0x2920;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      contextOffset = uVar4 * 0x240 + uVar1 * 0x30 + 0x2910;
    }
    else {
      if (uVar3 != 2) {
        return;
      }
      contextOffset = uVar4 * 0x240 + uVar1 * 0x30 + 0x2930;
    }
    break;
  case 5:
    uVar1 = operandDescriptor & 1;
    switch(operandDescriptor >> 1 & 7) {
    case 0:
      contextOffset = uVar1 * 0x240 + 0x28c0;
      break;
    case 1:
      contextOffset = uVar1 * 0x240 + 0x28d0;
      break;
    case 2:
      contextOffset = uVar1 * 0x240 + 0x28e0;
      break;
    case 3:
      contextOffset = uVar1 * 0x240 + 0x28f0;
      break;
    case 4:
      contextOffset = uVar1 * 0x240 + 0x2900;
      break;
    case 5:
      contextOffset = uVar1 * 0x240 + 0x2a90;
      break;
    default:
      return;
    }
    break;
  case 6:
    contextOffset = 0x24b0;
    goto LAB_00025998;
  case 7:
    uVar3 = operandDescriptor >> 5 & 7;
    uVar1 = operandDescriptor & 0x1f;
    if (uVar3 == 1) {
      contextOffset = uVar1 * 0x94 + 0x39b0;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      contextOffset = uVar1 * 0x94 + 0x398c;
    }
    else if (uVar3 == 2) {
      contextOffset = uVar1 * 0x94 + 0x39d4;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      contextOffset = uVar1 * 0x94 + 0x39f8;
    }
    break;
  case 8:
    uVar3 = operandDescriptor >> 5 & 7;
    uVar1 = operandDescriptor & 0x1f;
    if (uVar3 == 1) {
      contextOffset = uVar1 * 0x94 + 0x39c0;
    }
    else if (uVar3 < 2) {
      if (uVar3 != 0) {
        return;
      }
      contextOffset = uVar1 * 0x94 + 0x399c;
    }
    else if (uVar3 == 2) {
      contextOffset = uVar1 * 0x94 + 0x39e4;
    }
    else {
      if (uVar3 != 3) {
        return;
      }
      contextOffset = uVar1 * 0x94 + 0x3a08;
    }
    break;
  case 10:
    contextOffset = (operandDescriptor & 0xff) * 0x10 + 0x3e2c;
    break;
  case 0xb:
    contextOffset = 0x2de0;
    goto LAB_00025998;
  case 0xc:
    contextOffset = 0x2df0;
    goto LAB_00025998;
  case 0xd:
    contextOffset = 0x30bc;
    goto LAB_00025998;
  case 0xe:
    contextOffset = 0x30cc;
    goto LAB_00025998;
  case 0xf:
    contextOffset = 0x1850;
LAB_00025998:
    *outOffset = contextOffset;
    return;
  case 0x10:
    uVar1 = operandDescriptor & 0xff;
    switch(operandDescriptor >> 8 & 7) {
    case 0:
      uVar1 = 0;
      break;
    case 1:
      uVar1 = 3;
      break;
    case 2:
      uVar1 = 2;
      break;
    case 3:
      uVar1 = uVar1 + 4;
      break;
    case 4:
      uVar1 = uVar1 + 0x10;
      break;
    case 5:
      uVar1 = uVar1 + 8;
    }
    if ((operandDescriptor >> 0xe & 3) < 2) {
      contextOffset = uVar1 * 0x40 + 0x1860;
    }
    else {
      contextOffset = uVar1 * 0x40 + 0x1e60;
    }
    uVar1 = operandDescriptor >> 0xe & 3;
    *outOffset = contextOffset;
    uVar3 = operandDescriptor >> 0xc & 3;
    if (uVar1 < 3) {
      if (uVar1 != 0) {
        contextOffset = *outOffset + uVar3 * 0x10;
        goto LAB_00025998;
      }
    }
    else if (uVar1 != 3) {
      return;
    }
    *outOffset = *outOffset + uVar3 * 4;
    *outComponentStride = 0x10;
    return;
  case 0x12:
    *outOffset = 0x24a4;
    return;
  default:
    return;
  }
  *outOffset = contextOffset;
  return;
}

/* _glePPUpdateProgram @ 0x25abc (1144 bytes) */
void _glePPUpdateProgram(glContext, programRecord)
  undefined4 glContext;
  int programRecord;
{
  uint uVar1;
  int compiledStream;
  int descriptorTableWordOffset;
  undefined4 fillValue;
  int descriptorCount;
  uint uVar6;
  int usedBitsWord;
  uint loopIndex;
  undefined1 descriptorIndexByte;
  uint uVar10;
  
  fillValue = 0x100;
  if (*(short *)(programRecord + 0x4ba) != 0) {
    fillValue = 0x80;
  }
  _memset(programRecord + 0x48,fillValue,0x450);
  *(undefined4 *)(programRecord + 0x10) = 0;
  if ((*(short *)(programRecord + 0x4b8) == -0x7e00) || (compiledStream = *(int *)(programRecord + 0x4bc), compiledStream == 0)) {
    return;
  }
  descriptorTableWordOffset = *(int *)(compiledStream + 0x2c);
  descriptorCount = *(int *)(compiledStream + 0x28);
  loopIndex = 0;
  if (descriptorCount < 1) {
    return;
  }
  do {
    uVar6 = *(uint *)(loopIndex * 8 + compiledStream + descriptorTableWordOffset * 8);
    descriptorIndexByte = (undefined1)loopIndex;
    switch(uVar6 >> 0x10 & 0x1f) {
    default:
      goto switchD_00025bb0_caseD_0;
    case 1:
      *(undefined1 *)((uVar6 & 0xffff) + programRecord + 0x48) = descriptorIndexByte;
      break;
    case 2:
      *(undefined1 *)((uVar6 & 0xffff) + programRecord + 0x148) = descriptorIndexByte;
      break;
    case 3:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 0xf) {
      case 0:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x248) = descriptorIndexByte;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x249) = descriptorIndexByte;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x24a) = descriptorIndexByte;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x24b) = descriptorIndexByte;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x24c) = descriptorIndexByte;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x24d) = descriptorIndexByte;
        break;
      case 6:
        *(undefined1 *)(uVar10 * 7 + programRecord + 0x24e) = descriptorIndexByte;
      }
      break;
    case 4:
      uVar1 = uVar6 >> 9 & 3;
      uVar10 = uVar6 & 0xff;
      uVar6 = uVar6 >> 8 & 1;
      if (uVar1 == 1) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + programRecord + 0x281) = descriptorIndexByte;
      }
      else if (uVar1 < 2) {
        if (uVar1 == 0) {
          *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + programRecord + 0x280) = descriptorIndexByte;
        }
      }
      else if (uVar1 == 2) {
        *(undefined1 *)(uVar10 * 6 + uVar6 * 3 + programRecord + 0x282) = descriptorIndexByte;
      }
      break;
    case 5:
      uVar10 = uVar6 & 1;
      switch(uVar6 >> 1 & 7) {
      case 0:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b0) = descriptorIndexByte;
        break;
      case 1:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b1) = descriptorIndexByte;
        break;
      case 2:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b2) = descriptorIndexByte;
        break;
      case 3:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b3) = descriptorIndexByte;
        break;
      case 4:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b4) = descriptorIndexByte;
        break;
      case 5:
        *(undefined1 *)(uVar10 * 6 + programRecord + 0x2b5) = descriptorIndexByte;
      }
      break;
    case 6:
      *(undefined1 *)(programRecord + 0x314) = descriptorIndexByte;
      break;
    case 7:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + programRecord + (uVar6 >> 5 & 7) + 700) = descriptorIndexByte;
      break;
    case 8:
      *(undefined1 *)((uVar6 & 0x1f) * 4 + programRecord + (uVar6 >> 5 & 7) + 0x2dc) = descriptorIndexByte;
      break;
    case 10:
      *(undefined1 *)((uVar6 & 0xff) + programRecord + 0x30c) = descriptorIndexByte;
      break;
    case 0xb:
      *(undefined1 *)(programRecord + 0x312) = descriptorIndexByte;
      break;
    case 0xc:
      *(undefined1 *)(programRecord + 0x313) = descriptorIndexByte;
      break;
    case 0xd:
      *(undefined1 *)(programRecord + 0x315) = descriptorIndexByte;
      break;
    case 0xe:
      *(undefined1 *)(programRecord + 0x316) = descriptorIndexByte;
      break;
    case 0x10:
      uVar10 = uVar6 & 0xff;
      switch(uVar6 >> 8 & 7) {
      case 0:
        uVar10 = 0;
        goto LAB_00025eec;
      case 1:
        uVar10 = 3;
        goto LAB_00025eec;
      case 2:
        uVar10 = 2;
        goto LAB_00025eec;
      case 3:
        uVar10 = uVar10 + 4;
        break;
      case 4:
        uVar10 = uVar10 + 0x10;
        break;
      case 5:
        uVar10 = uVar10 + 8;
        break;
      default:
        uVar10 = 0xffffffff;
      }
      if (uVar10 != 0xffffffff) {
LAB_00025eec:
        uVar1 = uVar6 >> 0xe & 3;
        uVar6 = uVar6 >> 0xc & 3;
        if (uVar1 == 1) {
          *(undefined1 *)(uVar10 * 4 + programRecord + uVar6 + 0x3d8) = descriptorIndexByte;
        }
        else if (uVar1 < 2) {
          if (uVar1 == 0) {
            *(undefined1 *)(uVar10 * 4 + programRecord + uVar6 + 0x318) = descriptorIndexByte;
          }
        }
        else {
          if (uVar1 == 2) {
            uVar1 = *(uint *)(programRecord + 0x10) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + programRecord + uVar6 + 0x378) = descriptorIndexByte;
          }
          else {
            if (uVar1 != 3) break;
            uVar1 = *(uint *)(programRecord + 0x10) | 1 << (uVar10 & 0x3f);
            *(undefined1 *)(uVar10 * 4 + programRecord + uVar6 + 0x438) = descriptorIndexByte;
          }
          *(uint *)(programRecord + 0x10) = uVar1;
        }
      }
    }
    usedBitsWord = ((int)loopIndex >> 5) * 4 + programRecord;
    *(uint *)(usedBitsWord + 0x18) = *(uint *)(usedBitsWord + 0x18) | 1 << (loopIndex & 0x1f);
switchD_00025bb0_caseD_0:
    loopIndex = loopIndex + 1;
    if (descriptorCount <= (int)loopIndex) {
      return;
    }
  } while( true );
}

/* _gleVPEnable @ 0x25fc4 (128 bytes) */
double _gleVPEnable(int glContext,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_gleVPChanged)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  if (*(char *)(glContext + 0x30aa) != '\0') {
    *(undefined1 *)(glContext + 0x316b) = *(undefined1 *)(glContext + 0x4fea);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  }
  _gleSetColorMaterialEnable(glContext);
  _gleUpdateInverseNeeds(glContext);
  _gleUpdatePrimitiveData(glContext);
  _gleUpdateTextureTransform(glContext);
  _gleUpdatePolyMode(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
  return;
}

/* _gleVPChanged @ 0x26044 (184 bytes) */
void _gleVPChanged(int glContext,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int programBitsAddr;
  uint programDirtyWord;
  int currentProgram;
  int loopIndex;
  int dirtyWordCursor;
  uint *srcCursor;
  int remaining2;
  
  if (*(int *)(glContext + 0x5434) == 0) {
    remaining = 9;
    srcCursor = (uint *)(*(int *)(glContext + 0x5420) + 0x28);
    dirtyWordCursor = glContext;
    do {
      programDirtyWord = *srcCursor;
      srcCursor = srcCursor + 1;
      *(uint *)(dirtyWordCursor + 0x324) = *(uint *)(dirtyWordCursor + 0x324) | programDirtyWord;
      dirtyWordCursor = dirtyWordCursor + 4;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  else {
    currentProgram = *(int *)(glContext + 0x5430);
    remaining2 = 9;
    loopIndex = 0;
    dirtyWordCursor = glContext;
    do {
      programBitsAddr = loopIndex + *(int *)(currentProgram + 0x20);
      loopIndex = loopIndex + 4;
      *(uint *)(dirtyWordCursor + 0x324) = *(uint *)(dirtyWordCursor + 0x324) | *(uint *)(programBitsAddr + 8);
      dirtyWordCursor = dirtyWordCursor + 4;
      remaining2 = remaining2 + -1;
    } while (remaining2 != 0);
  }
  ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
  _gleSelectVertexSubmitFunc(glContext);
  return;
}

/* _glProgramLocalParameter4fvARB_Exec @ 0x260fc (344 bytes) */
void _glProgramLocalParameter4fvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  undefined4 *params;
{
  byte dirtyBitIndex;
  byte dirtyBitIndex2;
  uint changeWord3WithFlag;
  uint alternateFragmentTarget;
  undefined4 glErrorCode;
  int dirtyWord348Ptr;
  int glContextWord5424;
  int pipelineStageIndex;
  int boundProgramThenLocalParamArrayThenEntry;
  int stageTableBase;
  int dirtyWordPtr;
  
  if (target == 0x8620) {
    pipelineStageIndex = 0;
    if (index < 0x100) {
      changeWord3WithFlag = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_00026190:
      *(uint *)(glContext + 0x31c) = changeWord3WithFlag;
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitIndex = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        dirtyBitIndex = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      dirtyWordPtr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      stageTableBase = pipelineStageIndex * 4 + glContext;
      *(uint *)(dirtyWordPtr + 0x324) = *(uint *)(dirtyWordPtr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex2 = *(byte *)(index + glContextWord5424 + 0x58);
      dirtyWord348Ptr = (dirtyBitIndex2 >> 3 & 0x1c) + glContext;
      boundProgramThenLocalParamArrayThenEntry = *(int *)(stageTableBase + 0x5420);
      *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (dirtyBitIndex2 & 0x1f);
      boundProgramThenLocalParamArrayThenEntry = *(int *)(boundProgramThenLocalParamArrayThenEntry + 0x4e0);
      *(undefined4 *)(boundProgramThenLocalParamArrayThenEntry + index * 0x10) = *params;
      boundProgramThenLocalParamArrayThenEntry = boundProgramThenLocalParamArrayThenEntry + index * 0x10;
      *(undefined4 *)(boundProgramThenLocalParamArrayThenEntry + 4) = params[1];
      *(undefined4 *)(boundProgramThenLocalParamArrayThenEntry + 8) = params[2];
      *(undefined4 *)(boundProgramThenLocalParamArrayThenEntry + 0xc) = params[3];
      ((void (*)())_gleModifyPluginPipelineProgram)(glContext,*(int *)(stageTableBase + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      alternateFragmentTarget = 0x8200;
    }
    else {
      alternateFragmentTarget = 0x8804;
    }
    if (target != alternateFragmentTarget) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00026188;
    }
    pipelineStageIndex = 1;
    if (index < 0x80) {
      changeWord3WithFlag = *(uint *)(glContext + 0x31c) | 0x1000000;
      goto LAB_00026190;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_00026188:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleModifyPluginPipelineProgram @ 0x26254 (120 bytes) */
void _gleModifyPluginPipelineProgram(glContext, programObject, forwardedArg3)
  int glContext;
  int programObject;
  undefined4 forwardedArg3;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 programHandle;
  int rendererRecordCursor;
  int loopIndex;
  undefined4 *srcCursor;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    srcCursor = (undefined4 *)(programObject + 0x498);
    do {
      rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
      programHandle = *srcCursor;
      loopIndex = loopIndex + 1;
      srcCursor = srcCursor + 1;
      rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      (**(code **)(*rendererCallbacks + 0x194))(*rendererHandlePtr,programHandle,forwardedArg3);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleVPDisable @ 0x262cc (140 bytes) */
void _gleVPDisable(glContext)
  int glContext;
{
  if (*(char *)(glContext + 0x30aa) != '\0') {
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
    *(bool *)(glContext + 0x316b) = *(short *)(glContext + 0x30a8) == -0x7e06;
  }
  _gleSetColorMaterialEnable(glContext);
  _gleUpdateInverseNeeds(glContext);
  _gleUpdatePrimitiveData(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  _gleUpdateTextureTransform(glContext);
  _gleUpdatePolyMode(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x400000;
  return;
}

/* _glPixelTransferi_Exec @ 0x26358 (3128 bytes) */
void _glPixelTransferi_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  uint param;
{
  float neutralValue;
  float alternateDefaultThenSelectedDefault;
  undefined4 glErrorCode;
  uint nonDefaultBits;
  uint parameterBit;
  
  alternateDefaultThenSelectedDefault = FLOAT_00108e54;
  neutralValue = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00026ef8;
  }
  if (pname == 0x8022) {
    parameterBit = 0x40000000;
    *(float *)(glContext + 0x33a4) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8022 < pname) {
      if (pname == 0x870f) {
        parameterBit = 4;
        *(float *)(glContext + 0x3224) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname < 0x8710) {
          if (pname == 0x80b7) {
            parameterBit = 0x80000;
            *(float *)(glContext + 0x3374) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            neutralValue = alternateDefaultThenSelectedDefault;
          }
          else if (pname < 0x80b8) {
            if (pname == 0x80b4) {
              parameterBit = 0x10000;
              *(float *)(glContext + 0x335c) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              neutralValue = alternateDefaultThenSelectedDefault;
            }
            else if (pname < 0x80b5) {
              if (pname != 0x8023) goto LAB_00026ee8;
              parameterBit = 0x80000000;
              *(float *)(glContext + 0x33ac) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
            else if (pname == 0x80b5) {
              parameterBit = 0x20000;
              *(float *)(glContext + 0x336c) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              neutralValue = alternateDefaultThenSelectedDefault;
            }
            else {
              if (pname != 0x80b6) goto LAB_00026ee8;
              parameterBit = 0x40000;
              *(float *)(glContext + 0x3364) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
              neutralValue = alternateDefaultThenSelectedDefault;
            }
          }
          else if (pname == 0x80ba) {
            parameterBit = 0x400000;
            *(float *)(glContext + 0x3370) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname < 0x80bb) {
            if (pname == 0x80b8) {
              parameterBit = 0x100000;
              *(float *)(glContext + 0x3360) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
            else {
              if (pname != 0x80b9) goto LAB_00026ee8;
              parameterBit = 0x200000;
              *(float *)(glContext + 0x3368) =
                   (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            }
          }
          else {
            if (pname != 0x80bb) {
              if (pname == 0x870e) {
                parameterBit = 1;
                *(float *)(glContext + 0x321c) =
                     (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
                goto LAB_00026f44;
              }
              goto LAB_00026ee8;
            }
            parameterBit = 0x800000;
            *(float *)(glContext + 0x3378) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          goto LAB_00026f00;
        }
        if (pname == 0x8714) {
          parameterBit = 2;
          *(float *)(glContext + 0x3218) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          alternateDefaultThenSelectedDefault = neutralValue;
        }
        else if (pname < 0x8715) {
          if (pname == 0x8711) {
            parameterBit = 0x40;
            *(float *)(glContext + 0x3234) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname < 0x8711) {
            parameterBit = 0x10;
            *(float *)(glContext + 0x322c) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else if (pname == 0x8712) {
            parameterBit = 0x100;
            *(float *)(glContext + 0x323c) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
            if (pname != 0x8713) goto LAB_00026ee8;
            parameterBit = 0x400;
            *(float *)(glContext + 0x3244) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          }
        }
        else if (pname == 0x8717) {
          parameterBit = 0x80;
          *(float *)(glContext + 0x3230) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          alternateDefaultThenSelectedDefault = neutralValue;
        }
        else if (pname < 0x8718) {
          if (pname == 0x8715) {
            parameterBit = 8;
            *(float *)(glContext + 0x3220) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            alternateDefaultThenSelectedDefault = neutralValue;
          }
          else {
            if (pname != 0x8716) goto LAB_00026ee8;
            parameterBit = 0x20;
            *(float *)(glContext + 0x3228) =
                 (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
            alternateDefaultThenSelectedDefault = neutralValue;
          }
        }
        else if (pname == 0x8718) {
          parameterBit = 0x200;
          *(float *)(glContext + 0x3238) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          alternateDefaultThenSelectedDefault = neutralValue;
        }
        else {
          if (pname != 0x8719) goto LAB_00026ee8;
          parameterBit = 0x800;
          *(float *)(glContext + 0x3240) =
               (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
          alternateDefaultThenSelectedDefault = neutralValue;
        }
      }
LAB_00026f44:
      nonDefaultBits = *(uint *)(glContext + 0x3418) & ~parameterBit;
      if ((float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58) != alternateDefaultThenSelectedDefault) {
        nonDefaultBits = nonDefaultBits | parameterBit;
      }
      *(uint *)(glContext + 0x3418) = nonDefaultBits;
      goto LAB_00026f80;
    }
    if (pname == 0xd1b) {
      parameterBit = 0x400;
      *(float *)(glContext + 0x31f8) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
    else if (pname < 0xd1c) {
      if (pname == 0xd14) {
        parameterBit = 0x10;
        *(float *)(glContext + 0x31ec) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
      else if (pname < 0xd15) {
        if (pname == 0xd11) {
          parameterBit = 2;
        }
        else if (pname < 0xd12) {
          if (pname != 0xd10) {
LAB_00026ee8:
            if (*(int *)(glContext + 0x7574) != 0) {
              return;
            }
            glErrorCode = 0x500;
LAB_00026ef8:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return;
          }
          parameterBit = 1;
        }
        else if (pname == 0xd12) {
          *(uint *)(glContext + 0x3214) = param;
          parameterBit = 4;
          neutralValue = FLOAT_00108e50;
        }
        else {
          if (pname != 0xd13) goto LAB_00026ee8;
          *(uint *)(glContext + 0x3210) = param;
          parameterBit = 8;
          neutralValue = FLOAT_00108e50;
        }
      }
      else if (pname == 0xd18) {
        parameterBit = 0x20;
        *(float *)(glContext + 0x31f4) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
      else if (pname < 0xd19) {
        if (pname != 0xd15) goto LAB_00026ee8;
        parameterBit = 0x100;
        *(float *)(glContext + 0x31e8) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (pname == 0xd19) {
        parameterBit = 0x200;
        *(float *)(glContext + 0x31f0) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname != 0xd1a) goto LAB_00026ee8;
        parameterBit = 0x40;
        *(float *)(glContext + 0x31fc) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
    }
    else if (pname == 0x801c) {
      parameterBit = 0x1000000;
      *(float *)(glContext + 0x3390) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      neutralValue = alternateDefaultThenSelectedDefault;
    }
    else if (pname < 0x801d) {
      if (pname == 0xd1d) {
        parameterBit = 0x800;
        *(float *)(glContext + 0x3200) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (pname < 0xd1d) {
        parameterBit = 0x80;
        *(float *)(glContext + 0x3204) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
      else if (pname == 0xd1e) {
        parameterBit = 0x1000;
        *(float *)(glContext + 0x320c) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
      else {
        if (pname != 0xd1f) goto LAB_00026ee8;
        parameterBit = 0x2000;
        *(float *)(glContext + 0x3208) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      }
    }
    else if (pname == 0x801f) {
      parameterBit = 0x8000000;
      *(float *)(glContext + 0x33a8) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
      neutralValue = alternateDefaultThenSelectedDefault;
    }
    else if (pname < 0x8020) {
      if (pname == 0x801d) {
        parameterBit = 0x2000000;
        *(float *)(glContext + 0x33a0) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
      else {
        if (pname != 0x801e) goto LAB_00026ee8;
        parameterBit = 0x4000000;
        *(float *)(glContext + 0x3398) =
             (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
        neutralValue = alternateDefaultThenSelectedDefault;
      }
    }
    else if (pname == 0x8020) {
      parameterBit = 0x10000000;
      *(float *)(glContext + 0x3394) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
    else {
      if (pname != 0x8021) goto LAB_00026ee8;
      parameterBit = 0x20000000;
      *(float *)(glContext + 0x339c) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
LAB_00026f00:
  nonDefaultBits = *(uint *)(glContext + 0x3414) & ~parameterBit;
  if ((float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58) != neutralValue) {
    nonDefaultBits = nonDefaultBits | parameterBit;
  }
  *(uint *)(glContext + 0x3414) = nonDefaultBits;
LAB_00026f80:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  return;
}

/* _glTexImage3D_Exec @ 0x26f94 (800 bytes) */
int _glTexImage3D_Exec(glContext, target, level, internalformat, width, height, depth, border, format, type, pixels)
  int glContext;
  undefined4 target;
  int level;
  undefined4 internalformat;
  int width;
  int height;
  int depth;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  byte levelFlags;
  ushort textureTargetBits;
  undefined4 glErrorCode;
  int levelRecord;
  int imageEndOffset;
  int levelSlot;
  int elementBytes;
  int createdLevel;
  int textureObjectThenMipmapResult;
  int pixelUnpackBuffer;
  int bufferSize;
  double bytesPerElement;
  
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_000270fc;
  if ((pixels == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0002710c;
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer == 0) {
LAB_00027098:
    textureObjectThenMipmapResult = ((int (*)())_gleCheckTexImage3DArgs)(glContext,target,level,internalformat,width,height,depth,border,format,
                       type);
    if (textureObjectThenMipmapResult == 0) {
      return;
    }
    textureTargetBits = *(ushort *)(textureObjectThenMipmapResult + 0x24);
    if ((textureTargetBits & 0x3c00) == 0x1000) {
LAB_00027114:
      levelSlot = textureObjectThenMipmapResult + level * 0x18;
      levelRecord = levelSlot + 0xc4;
      if ((*(byte *)(levelSlot + 0xcf) & 0x20) != 0) {
        _gleDeletePluginTextureLevel(glContext,textureObjectThenMipmapResult,levelRecord,0,level);
        if (*(int *)(levelSlot + 0xd8) != 0) {
          levelFlags = *(byte *)(levelSlot + 0xcf);
          if ((levelFlags & 1) == 0) {
            _gleFreeTextureLevel(glContext,textureObjectThenMipmapResult,levelRecord);
            levelFlags = *(byte *)(levelSlot + 0xcf);
          }
          else {
            *(undefined4 *)(levelSlot + 0xd8) = 0;
          }
          *(byte *)(levelSlot + 0xcf) = levelFlags & 0xef;
        }
        *(byte *)(levelSlot + 0xcf) = *(byte *)(levelSlot + 0xcf) & 0xdf;
      }
      createdLevel = _gleCreateTextureLevel
                        (glContext,textureObjectThenMipmapResult,levelRecord,internalformat,width,height,depth,border,format,
                         type,1,pixels);
      if ((createdLevel != 0) && (pixels != 0)) {
        _gleTextureImagePut(glContext,levelRecord,0,0,0,width,height,depth,format,type,0,
                            glContext + 0x31cc,pixels);
      }
      if ((((width != 0) && (height != 0)) && (depth != 0)) &&
         (((_gleCreatePluginTextureLevel(glContext,textureObjectThenMipmapResult,levelRecord,0,level,internalformat),
           (*(uint *)(textureObjectThenMipmapResult + 0x6c) & 0x8000) != 0 && (*(short *)(textureObjectThenMipmapResult + 0x60) == level)) &&
          (textureObjectThenMipmapResult = _gleGenMipmapsToLevel(glContext,textureObjectThenMipmapResult,0,level,0xf,1), textureObjectThenMipmapResult != 0)))) {
        return;
      }
      *(uint *)(glContext + 0x314) =
           *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
      return;
    }
    if ((textureTargetBits & 0x3c00) == 0) {
      *(ushort *)(textureObjectThenMipmapResult + 0x24) = textureTargetBits | 0x1000;
      goto LAB_00027114;
    }
    if ((textureTargetBits & 0xc00) == 0) goto LAB_00027114;
  }
  else {
    imageEndOffset = _gleOffsetLimitImage3D
                      (glContext + 0x31cc,width,height,depth,format,type,pixels);
    bufferSize = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    elementBytes = (int)bytesPerElement;
    if (imageEndOffset <= bufferSize) {
      if (elementBytes == 0) {
        elementBytes = _glePixelBytes(format,type);
      }
      if (pixels == (pixels / elementBytes) * elementBytes) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        pixels = pixels + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00027098;
      }
    }
  }
LAB_000270fc:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0002710c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleCheckTexImage3DArgs @ 0x272b4 (324 bytes) */
int _gleCheckTexImage3DArgs(glContext, target, level, internalformat, width, height, depth, border, format, type)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  int depth;
  int border;
  undefined4 format;
  undefined4 type;
{
  undefined4 glErrorCode;
  int argsCheckResult;
  int glContextPtr468c;
  int textureObject;
  uint maxDimension;
  uint depthNoBorder;
  uint heightNoBorder;
  uint widthNoBorder;
  
  textureObject = ((int (*)())_gleLookUpTexture3D)(glContext,target);
  if (textureObject == 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
    goto LAB_000273a4;
  }
  widthNoBorder = width + border * -2;
  heightNoBorder = height + border * -2;
  depthNoBorder = depth + border * -2;
  if (-1 < (int)widthNoBorder) {
    if ((widthNoBorder & widthNoBorder - 1) == 0) {
      glContextPtr468c = *(int *)(glContext + 0x468c);
    }
    else {
      glContextPtr468c = *(int *)(glContext + 0x468c);
      if ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) == 0) goto LAB_00027394;
    }
    maxDimension = (uint)*(ushort *)(glContextPtr468c + 0xbe);
    if (((((((int)widthNoBorder <= (int)maxDimension) && (-1 < (int)heightNoBorder)) &&
          (((heightNoBorder & heightNoBorder - 1) == 0 || ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) != 0)))) &&
         (((int)heightNoBorder <= (int)maxDimension && (-1 < (int)depthNoBorder)))) &&
        (((depthNoBorder & depthNoBorder - 1) == 0 || ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) != 0)))) &&
       ((int)depthNoBorder <= (int)maxDimension)) {
      argsCheckResult = _gleCheckTexImageArgs(glContext,level,format,type,internalformat,border,0,1);
      if (argsCheckResult != 0) {
        return textureObject;
      }
      return 0;
    }
  }
LAB_00027394:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x501;
LAB_000273a4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleLookUpTexture3D @ 0x273f8 (80 bytes) */
int _gleLookUpTexture3D(glContext, target)
  int glContext;
  int target;
{
  if (target == 0x806f) {
    return *(int *)(*(int *)(glContext + 0x53d4) * 0x14 + glContext + 0x5158) + 0x10;
  }
  if (target != 0x8070) {
    return 0;
  }
  return *(int *)(glContext + 0x52ac) + 0x10;
}

/* _gleTextureImagePut_Slow @ 0x27448 (28188 bytes) */
void _gleTextureImagePut_Slow(glContext, textureLevel, xoffset, yoffset, zoffset, width, height, depth, format, type, applyPixelTransfer, pixelStoreState, pixels)
  int glContext;
  int textureLevel;
  uint xoffset;
  uint yoffset;
  int zoffset;
  int width;
  uint height;
  uint depth;
  int format;
  int type;
  undefined4 applyPixelTransfer;
  int pixelStoreState;
  uint pixels;
{
  int srcPixel;
  uint componentUint;
  int columnsLeft2;
  uint rowsLeft;
  uint allocatedBlock;
  float floatOne3;
  float floatMinusOne2;
  float float255C;
  float float127B;
  float floatZero2;
  float floatOne2;
  float float32767;
  float float255B;
  float floatZero;
  float floatOne;
  int scaledInt;
  short dstTypeCompare;
  ushort dstFormat;
  ushort dstType;
  bool freeTempImage;
  double twoPow31;
  double uint32MaxAsDouble;
  float float65535;
  float floatMinusOne;
  float fVar9;
  float float127;
  float float255;
  ushort compareFormat;
  undefined1 componentByte;
  uint componentUint3;
  uint componentUint4;
  undefined2 componentShort;
  int iVar17;
  int componentCount;
  int imageSize;
  uint componentUint2;
  uint loopIndex;
  code *extractPixelFunc;
  code *modifyPixelFunc;
  int iVar21;
  int colorTable;
  int rowBytes;
  int pixelBytes;
  uint uVar22;
  uint uVar23;
  int iVar24;
  int *piVar25;
  uint *dstSlice;
  int dstSliceBytes;
  uint *dstRow;
  int columnsLeft;
  undefined1 *puVar30;
  uint *dstPixel;
  double scaledComponent;
  undefined1 pixelRecord [4];
  float pixelRed;
  float pixelGreen;
  float pixelBlue;
  float pixelAlpha;
  float pixelDepth;
  float pixelHi;
  float pixelLo;
  float pixelDs;
  float pixelDt;
  float pixelMagnitude;
  int procSrcAddress;
  int procSrcRowBytes;
  undefined1 procSrcConvertA [4];
  undefined1 procSrcConvertB [4];
  int procDstAddress;
  int procDstRowBytes;
  undefined1 procDstConvertA [4];
  undefined1 procDstConvertB [4];
  undefined4 procMode;
  uint procFlags;
  undefined4 procMask;
  int procWidth;
  uint procHeight;
  undefined4 procZero13c;
  undefined4 procZero138;
  uint colorTableFormat;
  uint colorTableType;
  uint colorTableWidth;
  undefined4 colorTableData;
  uint postColorMatrixTableFormat;
  uint postColorMatrixTableType;
  uint postColorMatrixTableWidth;
  undefined4 postColorMatrixTableData;
  uint postConvolutionTableFormat;
  uint postConvolutionTableType;
  uint postConvolutionTableWidth;
  undefined4 postConvolutionTableData;
  undefined1 procEnd;
  undefined8 fctiwzSlot100;
  longlong fctiwzSlotF8;
  undefined8 fctiwzSlotF0;
  longlong fctiwzSlotE8;
  longlong fctiwzSlotE0;
  longlong fctiwzSlotD8;
  longlong fctiwzSlotD0;
  undefined8 fctiwzSlotC8;
  int srcRowBytes;
  int srcRowPad;
  int srcImageBytes;
  int srcImagePad;
  int srcPixelStride;
  int srcOffset;
  float float65535Spill;
  float float32767Spill;
  int dstPixelStrideSpillB;
  int dstPixelStrideSpill;
  float scaleSpill;
  
  if (type != 0x1a00) {
    freeTempImage = false;
    iVar17 = zoffset;
    iVar21 = width;
    uVar22 = height;
    uVar23 = depth;
  }
  else {
    imageSize = _gleImageSize(format,0x1a00,width,height);
    allocatedBlock = _malloc(imageSize * depth);
    if (allocatedBlock == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x505;
      return;
    }
    iVar21 = 0x1a00;
    iVar17 = format;
    uVar23 = allocatedBlock;
    _gleFillImage(glContext,width,height,depth,format,0x1a00,pixels,allocatedBlock);
    freeTempImage = true;
    uVar22 = pixels;
    pixels = allocatedBlock;
  }
  if (((((pixelStoreState != 0) && (*(char *)(pixelStoreState + 0x18) != '\0')) ||
       (((char)applyPixelTransfer != '\0' &&
        ((((*(uint *)(glContext + 0x3410) & 0x1ff) != 0 ||
          (uVar22 = *(uint *)(glContext + 0x3414) & 0xff0000, uVar22 != 0)) && (format != 0x1900)))))
       ) || ((type == 0x140b || (type == 0x1406)))) ||
     ((dstTypeCompare = *(short *)(textureLevel + 0x12), dstTypeCompare == 0x140b ||
      (((dstTypeCompare == 0x1406 || (dstTypeCompare == 0)) || ((dstTypeCompare == 0x1403 || (type == 0x1a00)))))))) {
    _glgConvertType(format,type,procSrcConvertA,procSrcConvertB,iVar17,iVar21,uVar22,uVar23);
    piVar25 = &srcOffset;
    rowsLeft = height;
    iVar17 = pixelStoreState;
    _glePixelPackSettings
              (glContext,format,type,width,height,pixelStoreState,&srcPixelStride,piVar25,&srcRowBytes,
               &srcRowPad,&srcImageBytes,&srcImagePad);
    uVar23 = 0;
    procFlags = 0;
    procMask = 0x7efff;
    procZero138 = 0;
    procZero13c = 0;
    if ((char)applyPixelTransfer != '\0') {
      uVar23 = *(uint *)(glContext + 0x3410);
      if ((uVar23 & 0x20) != 0) {
        colorTable = _gleLookUpNonProxyColorTable(glContext,0x80d0);
        uVar23 = *(uint *)(glContext + 0x3410);
        colorTableData = *(undefined4 *)(colorTable + 0xc0);
        colorTableFormat = (uint)*(ushort *)(colorTable + 0xbc);
        colorTableType = (uint)*(ushort *)(colorTable + 0xbe);
        colorTableWidth = (uint)*(ushort *)(colorTable + 0xb0);
      }
      if ((uVar23 & 0x80) != 0) {
        colorTable = _gleLookUpNonProxyColorTable(glContext,0x80d2);
        uVar23 = *(uint *)(glContext + 0x3410);
        postColorMatrixTableData = *(undefined4 *)(colorTable + 0xc0);
        postColorMatrixTableFormat = (uint)*(ushort *)(colorTable + 0xbc);
        postColorMatrixTableType = (uint)*(ushort *)(colorTable + 0xbe);
        postColorMatrixTableWidth = (uint)*(ushort *)(colorTable + 0xb0);
      }
      if ((uVar23 & 0x40) != 0) {
        colorTable = _gleLookUpNonProxyColorTable(glContext,0x80d1);
        postConvolutionTableData = *(undefined4 *)(colorTable + 0xc0);
        postConvolutionTableFormat = (uint)*(ushort *)(colorTable + 0xbc);
        postConvolutionTableType = (uint)*(ushort *)(colorTable + 0xbe);
        postConvolutionTableWidth = (uint)*(ushort *)(colorTable + 0xb0);
      }
    }
    if (pixelStoreState == 0) {
      if (1 < (int)depth) {
        srcImageBytes = srcRowBytes * height;
      }
    }
    else {
      if (*(char *)(pixelStoreState + 0x19) != '\0') {
        procFlags = procFlags | 4;
      }
      if (*(char *)(pixelStoreState + 0x18) != '\0') {
        procFlags = procFlags | 1;
      }
    }
    puVar30 = procDstConvertB;
    procMode = 2;
    procEnd = 0;
    procWidth = width;
    procHeight = height;
    _glgConvertType((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),procDstConvertA,
                    puVar30,rowsLeft,iVar17,uVar23,piVar25);
    pixelBytes = _glePixelBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
    uVar23 = (uint)*(ushort *)(textureLevel + 0xc);
    procDstRowBytes = _gleRowBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                             uVar23);
    dstSliceBytes = procDstRowBytes * (uint)*(ushort *)(textureLevel + 6);
    procSrcAddress = pixels + srcOffset;
    procSrcRowBytes = srcRowBytes;
    if ((*(short *)(textureLevel + 0x12) == 0) && (((xoffset != 0 || (yoffset != 0)) || (zoffset != 0))))
    {
      dstFormat = *(ushort *)(textureLevel + 0x10);
      if (((0x83f3 < dstFormat) || (0x83f1 < dstFormat)) || (uVar23 = 8, dstFormat < 0x83f0)) {
        uVar23 = 0x10;
      }
      iVar24 = ((int)xoffset >> 2) + (uint)((int)xoffset < 0 && (xoffset & 3) != 0);
      procDstAddress = *(int *)(textureLevel + 0x14) +
                  ((uint)(*(ushort *)(textureLevel + 4) >> 2) *
                   (((int)yoffset >> 2) + (uint)((int)yoffset < 0 && (yoffset & 3) != 0)) + iVar24)
                  * uVar23;
    }
    else {
      iVar24 = procDstRowBytes * yoffset;
      procDstAddress = dstSliceBytes * zoffset + iVar24 + *(int *)(textureLevel + 0x14) + pixelBytes * xoffset;
    }
    loopIndex = 0;
    while( true ) {
      loopIndex = loopIndex + 1;
      _glgProcessPixels(glContext + 0x31a8,&procSrcAddress,uVar23,puVar30,rowsLeft,iVar17,iVar24,piVar25);
      if (loopIndex == depth) break;
      procDstAddress = procDstAddress + dstSliceBytes;
      procSrcAddress = procSrcAddress + srcImageBytes;
      iVar24 = srcImageBytes;
    }
    goto LAB_0002e240;
  }
  componentCount = _gleComponents((uint)*(ushort *)(textureLevel + 0x10));
  pixelBytes = _glePixelBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
  dstSlice = (uint *)(*(int *)(textureLevel + 0x14) +
                    pixelBytes * ((uint)*(ushort *)(textureLevel + 4) *
                              ((uint)*(ushort *)(textureLevel + 6) * zoffset + yoffset) + xoffset));
  rowBytes = _gleRowBytes((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                        (uint)*(ushort *)(textureLevel + 4));
  dstSliceBytes = rowBytes * (uint)*(ushort *)(textureLevel + 6);
  _glePixelPackSettings
            (glContext,format,type,width,height,pixelStoreState,&srcPixelStride,&srcOffset,&srcRowBytes,
             &srcRowPad,&srcImageBytes,&srcImagePad);
  srcPixel = pixels + srcOffset;
  extractPixelFunc = (code *)((int (*)())_gleSelectPixelExtractFunc)(format,type);
  modifyPixelFunc = (code *)((int (*)())_gleSelectModifyPixelFunc)(glContext,format);
  float65535 = FLOAT_00108ea0;
  uint32MaxAsDouble = DOUBLE_00108da8;
  if (extractPixelFunc == (code *)0x0) {
    return;
  }
  pixelBlue = 0.0;
  pixelAlpha = 1.0;
  pixelRed = 0.0;
  pixelGreen = 0.0;
  if (modifyPixelFunc != (code *)0x0) {
    dstFormat = *(ushort *)(textureLevel + 0x10);
    if (dstFormat == 0x190a) {
      if (*(short *)(textureLevel + 0x12) == 1) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    _gleModifyPixelSignedRGBA(glContext,pixelRecord);
                    if (floatOne < pixelAlpha) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelAlpha < floatMinusOne)) {
                        scaledInt = (int)(pixelAlpha * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne < pixelRed) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelRed < floatMinusOne)) {
                        scaledInt = (int)(pixelRed * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  pixelRed = floatZero;
                  pixelAlpha = floatOne2;
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  (*modifyPixelFunc)(glContext,pixelRecord);
                  if (floatOne2 < pixelRed) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelRed < floatZero)) {
                      scaledInt = (int)(pixelRed * float255C);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < pixelAlpha) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelAlpha < floatZero)) {
                      scaledInt = (int)(pixelAlpha * float255C);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (dstFormat < 0x190b) {
      if (dstFormat == 0x1907) {
        dstType = *(ushort *)(textureLevel + 0x12);
        if (dstType == 0x8362) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255B = FLOAT_00108f70;
                  columnsLeft2 = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      columnsLeft2 = columnsLeft2 + -1;
                      fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255B);
                      fctiwzSlotD0 = (longlong)(int)(pixelGreen * float255B);
                      fctiwzSlotD8 = (longlong)(int)(pixelRed * float255B);
                      *(byte *)dstPixel =
                           (byte)(int)(pixelBlue * float255B) & 0xc0 |
                           (byte)((uint)(int)(pixelGreen * float255B) >> 2) & 0x38 |
                           (byte)((uint)(int)(pixelRed * float255B) >> 5) & 7;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + 1);
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstType < 0x8363) {
          if (dstType == 8) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        _gleModifyPixelSignedRGBA(glContext,pixelRecord);
                        if (floatOne < pixelRed) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelRed < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                          }
                        }
                        *(undefined1 *)dstPixel = componentByte;
                        if (floatOne < pixelGreen) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelGreen < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelGreen * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 1) = componentByte;
                        if (floatOne < pixelBlue) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelBlue < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelBlue * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)((int)dstPixel + 2) = componentByte;
                        *(undefined1 *)((int)dstPixel + 3) = 0;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + componentCount);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType == 0x8032) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float255B = FLOAT_00108f70;
                    columnsLeft2 = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelRed * float255B);
                        fctiwzSlotD0 = (longlong)(int)(pixelGreen * float255B);
                        fctiwzSlotD8 = (longlong)(int)(pixelBlue * float255B);
                        *(byte *)dstPixel =
                             (byte)(int)(pixelRed * float255B) & 0xe0 |
                             (byte)((uint)(int)(pixelGreen * float255B) >> 3) & 0x1c |
                             (byte)((uint)(int)(pixelBlue * float255B) >> 6) & 3;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + 1);
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (dstType == 0x8363) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelRed * float65535);
                        fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlotD8 = (longlong)(int)(pixelBlue * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelRed * float65535) & 0xf800 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(pixelBlue * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType == 0x8364) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float65535);
                        fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlotD8 = (longlong)(int)(pixelRed * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelBlue * float65535) & 0xf800 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7e0 |
                             (ushort)((uint)(int)(pixelRed * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    pixelRed = floatZero;
                    pixelGreen = floatZero;
                    pixelBlue = floatZero;
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    (*modifyPixelFunc)(glContext,pixelRecord);
                    if (floatOne2 < pixelRed) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelRed < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < pixelGreen) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelGreen < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelGreen * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < pixelBlue) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelBlue < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (dstFormat < 0x1908) {
        if (dstFormat == 0x1906) {
          if (*(short *)(textureLevel + 0x12) == 0x1400) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float255C = FLOAT_00108f70;
                    floatOne2 = FLOAT_00108e54;
                    floatZero = FLOAT_00108e50;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        if (floatOne2 < pixelAlpha) {
                          componentByte = 0xff;
                        }
                        else {
                          componentByte = 0;
                          if (!(pixelAlpha < floatZero)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)dstPixel = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + componentCount);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
          }
          else if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      pixelAlpha = floatOne2;
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne2 < pixelAlpha) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelAlpha < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (dstFormat == 0x1908) {
          dstType = *(ushort *)(textureLevel + 0x12);
          if (dstType == 0x8036) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          fctiwzSlotD0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          fctiwzSlotC8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint2 = (uint)(int)scaledComponent;
                          fctiwzSlotD8 = (longlong)(int)componentUint2;
                        }
                        scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint3 = (uint)(int)scaledComponent;
                          fctiwzSlotE8 = (longlong)(int)componentUint3;
                        }
                        scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint4 = (uint)(int)scaledComponent;
                          fctiwzSlotF8 = (longlong)(int)componentUint4;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xffc00000 | componentUint2 >> 10 & 0x3ff000 |
                                   componentUint3 >> 0x14 & 0xffc | componentUint4 >> 0x1e;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType < 0x8037) {
            if (dstType == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          (*modifyPixelFunc)(glContext,pixelRecord);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotC8 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotD8 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelRed * float65535) & 0xf000 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType < 0x8034) {
              if (dstType == 8) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        float127B = FLOAT_00108f6c;
                        floatMinusOne = FLOAT_00108e58;
                        floatOne = FLOAT_00108e54;
                        columnsLeft = width;
                        dstPixel = dstRow;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            _gleModifyPixelSignedRGBA(glContext,pixelRecord);
                            if (floatOne < pixelRed) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelRed < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                              }
                            }
                            *(undefined1 *)dstPixel = componentByte;
                            if (floatOne < pixelGreen) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelGreen < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float127B);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelGreen * float127B);
                              }
                            }
                            *(undefined1 *)((int)dstPixel + 1) = componentByte;
                            if (floatOne < pixelBlue) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelBlue < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float127B);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelBlue * float127B);
                              }
                            }
                            *(undefined1 *)((int)dstPixel + 2) = componentByte;
                            if (floatOne < pixelAlpha) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelAlpha < floatMinusOne)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float127B);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float127B);
                              }
                            }
                            columnsLeft = columnsLeft + -1;
                            *(undefined1 *)((int)dstPixel + 3) = componentByte;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = (uint *)((int)dstPixel + componentCount);
                          } while (columnsLeft != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (dstType == 0x8034) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          scaleSpill = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            columnsLeft2 = columnsLeft2 + -1;
                            fctiwzSlotC8 = (longlong)(int)(pixelRed * float65535);
                            fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                            fctiwzSlotD8 = (longlong)(int)(pixelBlue * float65535);
                            fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(pixelRed * float65535) & 0xf800 |
                                 (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(pixelBlue * float65535) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xf) & 1;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (dstType == 0x8035) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                       componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (dstType == 0x8366) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          (*modifyPixelFunc)(glContext,pixelRecord);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                          fctiwzSlotD0 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotE0 = (longlong)(int)(pixelRed * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelAlpha * float65535) & 0x8000 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(pixelRed * float65535) >> 0xb) & 0x1f;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType < 0x8367) {
              if (dstType == 0x8365) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          scaleSpill = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            columnsLeft2 = columnsLeft2 + -1;
                            fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                            fctiwzSlotD0 = (longlong)(int)(pixelBlue * float65535);
                            fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                            fctiwzSlotE0 = (longlong)(int)(pixelRed * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(pixelAlpha * float65535) & 0xf000 |
                                 (ushort)((uint)(int)(pixelBlue * float65535) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(pixelGreen * float65535) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(pixelRed * float65535) >> 0xc) & 0xf;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (dstType == 0x8367) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                       componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (dstType == 0x8368) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xc0000000 | componentUint2 >> 2 & 0x3ff00000 |
                                       componentUint3 >> 0xc & 0xffc00 | componentUint4 >> 0x16;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      pixelRed = floatZero;
                      pixelGreen = floatZero;
                      pixelBlue = floatZero;
                      pixelAlpha = floatOne2;
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne2 < pixelRed) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelRed < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne2 < pixelGreen) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelGreen < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelGreen * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne2 < pixelBlue) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelBlue < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne2 < pixelAlpha) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelAlpha < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstFormat == 0x1909) {
          if (*(short *)(textureLevel + 0x12) == 0x1400) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        _gleModifyPixelSignedRGBA(glContext,pixelRecord);
                        if (floatOne < pixelRed) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelRed < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)dstPixel = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + componentCount);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
          }
          else if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      pixelRed = floatZero;
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne2 < pixelRed) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelRed < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
    }
    else {
      if (dstFormat == 0x86f4) {
        dstType = *(ushort *)(textureLevel + 0x12);
        if (dstType == 6) {
          if (0 < (int)depth) {
            dstPixelStrideSpill = componentCount << 1;
            do {
              iVar17 = dstPixelStrideSpill;
              if (0 < (int)height) {
                float32767Spill = FLOAT_00108f74;
                rowsLeft = height;
                dstRow = dstSlice;
                do {
                  fVar9 = float32767Spill;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne < pixelHi) {
                        componentShort = 0x7fff;
                      }
                      else {
                        componentShort = 0x8001;
                        if (!(pixelHi < floatMinusOne)) {
                          scaledInt = (int)(pixelHi * fVar9);
                          (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined2 *)dstPixel = componentShort;
                      if (floatOne < pixelLo) {
                        componentShort = 0x7fff;
                      }
                      else {
                        componentShort = 0x8001;
                        if (!(pixelLo < floatMinusOne)) {
                          scaledInt = (int)(pixelLo * fVar9);
                          (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined2 *)((int)dstPixel + 2) = componentShort;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                  srcPixel = srcPixel + srcRowPad;
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (dstType < 7) {
          if ((dstType == 5) && (0 < (int)depth)) {
            dstPixelStrideSpillB = componentCount << 1;
            do {
              iVar17 = dstPixelStrideSpillB;
              if (0 < (int)height) {
                float65535Spill = FLOAT_00108ea0;
                rowsLeft = height;
                dstRow = dstSlice;
                do {
                  fVar9 = float65535Spill;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne2 < pixelHi) {
                        componentShort = 0xffff;
                      }
                      else {
                        componentShort = 0;
                        if (!(pixelHi < floatZero)) {
                          scaledInt = (int)(pixelHi * fVar9);
                          (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined2 *)dstPixel = componentShort;
                      if (floatOne2 < pixelLo) {
                        componentShort = 0xffff;
                      }
                      else {
                        componentShort = 0;
                        if (!(pixelLo < floatZero)) {
                          scaledInt = (int)(pixelLo * fVar9);
                          (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)scaledInt;
                          componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined2 *)((int)dstPixel + 2) = componentShort;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + iVar17);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                  srcPixel = srcPixel + srcRowPad;
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (dstType == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne < pixelHi) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelHi < floatMinusOne)) {
                          scaledInt = (int)(pixelHi * float127B);
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne < pixelLo) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelLo < floatMinusOne)) {
                          scaledInt = (int)(pixelLo * float127B);
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if ((dstType == 0x1401) && (0 < (int)depth)) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    (*modifyPixelFunc)(glContext,pixelRecord);
                    if (floatOne2 < pixelHi) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelHi < floatZero)) {
                        scaledInt = (int)(pixelHi * float255C);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < pixelLo) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelLo < floatZero)) {
                        scaledInt = (int)(pixelLo * float255C);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (dstFormat < 0x86f5) {
        if (dstFormat == 0x80e1) {
          dstType = *(ushort *)(textureLevel + 0x12);
          if (dstType == 0x8036) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        (*modifyPixelFunc)(glContext,pixelRecord);
                        scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          fctiwzSlotD0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          fctiwzSlotC8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint2 = (uint)(int)scaledComponent;
                          fctiwzSlotD8 = (longlong)(int)componentUint2;
                        }
                        scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint3 = (uint)(int)scaledComponent;
                          fctiwzSlotE8 = (longlong)(int)componentUint3;
                        }
                        scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint4 = (uint)(int)scaledComponent;
                          fctiwzSlotF8 = (longlong)(int)componentUint4;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xffc00000 | componentUint2 >> 10 & 0x3ff000 |
                                   componentUint3 >> 0x14 & 0xffc | componentUint4 >> 0x1e;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType < 0x8037) {
            if (dstType == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          (*modifyPixelFunc)(glContext,pixelRecord);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotC8 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotD8 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelBlue * float65535) & 0xf000 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(pixelRed * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType < 0x8034) {
              if (dstType == 7) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        float255 = FLOAT_00108f70;
                        float127 = FLOAT_00108f6c;
                        floatMinusOne2 = FLOAT_00108e58;
                        floatOne2 = FLOAT_00108e54;
                        floatZero = FLOAT_00108e50;
                        if (0 < width) {
                          puVar30 = (undefined1 *)((int)dstRow + 3);
                          dstPixel = dstRow;
                          columnsLeft = width;
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            _gleModifyPixelSignedRGB_UnsignedA(glContext,pixelRecord);
                            if (floatOne2 < pixelAlpha) {
                              componentByte = 0xff;
                            }
                            else {
                              componentByte = 0;
                              if (!(pixelAlpha < floatZero)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255);
                              }
                            }
                            *(undefined1 *)dstPixel = componentByte;
                            if (floatOne2 < pixelRed) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelRed < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelRed * float127);
                              }
                            }
                            puVar30[-2] = componentByte;
                            if (floatOne2 < pixelGreen) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelGreen < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float127);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelGreen * float127);
                              }
                            }
                            puVar30[-1] = componentByte;
                            if (floatOne2 < pixelBlue) {
                              componentByte = 0x7f;
                            }
                            else {
                              componentByte = 0x81;
                              if (!(pixelBlue < floatMinusOne2)) {
                                (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float127);
                                componentByte = (undefined1)fctiwzSlotC8;
                                fctiwzSlotC8 = (longlong)(int)(pixelBlue * float127);
                              }
                            }
                            columnsLeft = columnsLeft + -1;
                            *puVar30 = componentByte;
                            puVar30 = puVar30 + componentCount;
                            dstPixel = (uint *)((int)dstPixel + componentCount);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (dstType == 0x8034) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          scaleSpill = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            columnsLeft2 = columnsLeft2 + -1;
                            fctiwzSlotC8 = (longlong)(int)(pixelBlue * float65535);
                            fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                            fctiwzSlotD8 = (longlong)(int)(pixelRed * float65535);
                            fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(pixelBlue * float65535) & 0xf800 |
                                 (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7c0 |
                                 (ushort)((uint)(int)(pixelRed * float65535) >> 10) & 0x3e |
                                 (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xf) & 1;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (dstType == 0x8035) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                       componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          else {
            if (dstType == 0x8366) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          (*modifyPixelFunc)(glContext,pixelRecord);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                          fctiwzSlotD0 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotE0 = (longlong)(int)(pixelBlue * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelAlpha * float65535) & 0x8000 |
                               (ushort)((uint)(int)(pixelRed * float65535) >> 1) & 0x7c00 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 6) & 0x3e0 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 0xb) & 0x1f;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType < 0x8367) {
              if (dstType == 0x8365) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        if (0 < width) {
                          scaleSpill = float65535;
                          dstPixel = dstRow;
                          columnsLeft2 = width;
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            columnsLeft2 = columnsLeft2 + -1;
                            fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                            fctiwzSlotD0 = (longlong)(int)(pixelRed * float65535);
                            fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                            fctiwzSlotE0 = (longlong)(int)(pixelBlue * float65535);
                            *(ushort *)dstPixel =
                                 (ushort)(int)(pixelAlpha * float65535) & 0xf000 |
                                 (ushort)((uint)(int)(pixelRed * float65535) >> 4) & 0xf00 |
                                 (ushort)((uint)(int)(pixelGreen * float65535) >> 8) & 0xf0 |
                                 (ushort)((uint)(int)(pixelBlue * float65535) >> 0xc) & 0xf;
                            dstPixel = (uint *)((int)dstPixel + 2);
                            srcPixel = srcPixel + srcPixelStride;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
            else {
              if (dstType == 0x8367) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                       componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
              if (dstType == 0x8368) {
                if (0 < (int)depth) {
                  do {
                    rowsLeft = height;
                    dstRow = dstSlice;
                    if (0 < (int)height) {
                      do {
                        twoPow31 = DOUBLE_00108d80;
                        dstPixel = dstRow;
                        columnsLeft2 = width;
                        if (0 < width) {
                          do {
                            (*extractPixelFunc)(pixelRecord,srcPixel);
                            (*modifyPixelFunc)(glContext,pixelRecord);
                            scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                            if (twoPow31 <= scaledComponent) {
                              componentUint = (uint)(int)(scaledComponent - twoPow31);
                              fctiwzSlotD0 = (longlong)(int)componentUint;
                              componentUint = componentUint ^ 0x80000000;
                            }
                            else {
                              componentUint = (uint)(int)scaledComponent;
                              fctiwzSlotC8 = (longlong)(int)componentUint;
                            }
                            scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint2 = (uint)(int)scaledComponent;
                              fctiwzSlotD8 = (longlong)(int)componentUint2;
                            }
                            scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint3 = (uint)(int)scaledComponent;
                              fctiwzSlotE8 = (longlong)(int)componentUint3;
                            }
                            scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                            if (DOUBLE_00108d80 <= scaledComponent) {
                              fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                              componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                            }
                            else {
                              componentUint4 = (uint)(int)scaledComponent;
                              fctiwzSlotF8 = (longlong)(int)componentUint4;
                            }
                            columnsLeft2 = columnsLeft2 + -1;
                            *dstPixel = componentUint & 0xc0000000 | componentUint2 >> 2 & 0x3ff00000 |
                                       componentUint3 >> 0xc & 0xffc00 | componentUint4 >> 0x16;
                            srcPixel = srcPixel + srcPixelStride;
                            dstPixel = dstPixel + 1;
                          } while (columnsLeft2 != 0);
                        }
                        rowsLeft = rowsLeft - 1;
                        srcPixel = srcPixel + srcRowPad;
                        dstRow = (uint *)((int)dstRow + rowBytes);
                      } while (rowsLeft != 0);
                    }
                    depth = depth - 1;
                    dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                    srcPixel = srcPixel + srcImagePad;
                  } while (depth != 0);
                }
                goto LAB_0002e240;
              }
            }
          }
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      pixelRed = floatZero;
                      pixelGreen = floatZero;
                      pixelBlue = floatZero;
                      pixelAlpha = floatOne2;
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne2 < pixelBlue) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelBlue < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255C);
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne2 < pixelGreen) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelGreen < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelGreen * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne2 < pixelRed) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelRed < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne2 < pixelAlpha) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelAlpha < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        compareFormat = 0x86dc;
      }
      else {
        if (dstFormat == 0x86f5) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      (*modifyPixelFunc)(glContext,pixelRecord);
                      if (floatOne < pixelDs) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelDs < floatMinusOne)) {
                          scaledInt = (int)(pixelDs * float127B);
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      *(undefined1 *)dstPixel = componentByte;
                      if (floatOne < pixelDt) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelDt < floatMinusOne)) {
                          scaledInt = (int)(pixelDt * float127B);
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)scaledInt;
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        compareFormat = 0x86f6;
      }
      if (dstFormat == compareFormat) {
        if (0 < (int)depth) {
          do {
            dstRow = dstSlice;
            rowsLeft = height;
            if (0 < (int)height) {
              do {
                float255 = FLOAT_00108f70;
                float127 = FLOAT_00108f6c;
                floatMinusOne2 = FLOAT_00108e58;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                if (0 < width) {
                  puVar30 = (undefined1 *)((int)dstRow + 3);
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    (*modifyPixelFunc)(glContext,pixelRecord);
                    if (floatOne2 < pixelRed) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelRed < floatZero)) {
                        scaledInt = (int)(pixelRed * float255);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < pixelMagnitude) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelMagnitude < floatZero)) {
                        scaledInt = (int)(pixelMagnitude * float255);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < pixelDt) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelDt < floatMinusOne2)) {
                        scaledInt = (int)(pixelDt * float127);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    puVar30[-1] = componentByte;
                    if (floatOne2 < pixelDs) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelDs < floatMinusOne2)) {
                        scaledInt = (int)(pixelDs * float127);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *puVar30 = componentByte;
                    puVar30 = puVar30 + componentCount;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
    if (*(short *)(textureLevel + 0x12) == 0x1400) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float127B = FLOAT_00108f6c;
              floatMinusOne = FLOAT_00108e58;
              floatOne = FLOAT_00108e54;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  _gleModifyPixelSignedRGBA(glContext,pixelRecord);
                  if (floatOne < pixelRed) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(pixelRed < floatMinusOne)) {
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)dstPixel = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
    }
    else if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float255C = FLOAT_00108f70;
            floatOne2 = FLOAT_00108e54;
            floatZero = FLOAT_00108e50;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                pixelRed = floatOne2;
                (*extractPixelFunc)(pixelRecord,srcPixel);
                (*modifyPixelFunc)(glContext,pixelRecord);
                if (floatOne2 < pixelRed) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(pixelRed < floatZero)) {
                    (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                    componentByte = (undefined1)fctiwzSlotC8;
                    fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)dstPixel = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + componentCount);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + rowBytes);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
    goto LAB_0002e240;
  }
  dstFormat = *(ushort *)(textureLevel + 0x10);
  if (dstFormat == 0x190a) {
    if (*(short *)(textureLevel + 0x12) == 1) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float127B = FLOAT_00108f6c;
              floatMinusOne = FLOAT_00108e58;
              floatOne = FLOAT_00108e54;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  if (floatOne < pixelAlpha) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(pixelAlpha < floatMinusOne)) {
                      scaledInt = (int)(pixelAlpha * float127B);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlot100;
                      fctiwzSlot100 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne < pixelRed) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(pixelRed < floatMinusOne)) {
                      scaledInt = (int)(pixelRed * float127B);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlot100;
                      fctiwzSlot100 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
    }
    else if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float255C = FLOAT_00108f70;
            floatOne2 = FLOAT_00108e54;
            floatZero = FLOAT_00108e50;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                (*extractPixelFunc)(pixelRecord,srcPixel);
                if (floatOne2 < pixelRed) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(pixelRed < floatZero)) {
                    scaledInt = (int)(pixelRed * float255C);
                    (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)scaledInt;
                    componentByte = (undefined1)fctiwzSlot100;
                    fctiwzSlot100 = (longlong)scaledInt;
                  }
                }
                *(undefined1 *)dstPixel = componentByte;
                if (floatOne2 < pixelAlpha) {
                  componentByte = 0xff;
                }
                else {
                  componentByte = 0;
                  if (!(pixelAlpha < floatZero)) {
                    scaledInt = (int)(pixelAlpha * float255C);
                    (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)scaledInt;
                    componentByte = (undefined1)fctiwzSlot100;
                    fctiwzSlot100 = (longlong)scaledInt;
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)((int)dstPixel + 1) = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + componentCount);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + rowBytes);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
    goto LAB_0002e240;
  }
  if (dstFormat < 0x190b) {
    if (dstFormat == 0x1907) {
      dstType = *(ushort *)(textureLevel + 0x12);
      if (dstType == 0x8362) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255B = FLOAT_00108f70;
                columnsLeft2 = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    columnsLeft2 = columnsLeft2 + -1;
                    fctiwzSlotF0 = (longlong)(int)(pixelBlue * float255B);
                    fctiwzSlotF8 = (longlong)(int)(pixelGreen * float255B);
                    fctiwzSlot100 = (longlong)(int)(pixelRed * float255B);
                    *(byte *)dstPixel =
                         (byte)(int)(pixelBlue * float255B) & 0xc0 |
                         (byte)((uint)(int)(pixelGreen * float255B) >> 2) & 0x38 |
                         (byte)((uint)(int)(pixelRed * float255B) >> 5) & 7;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + 1);
                  } while (columnsLeft2 != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (dstType < 0x8363) {
        if (dstType == 8) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      *(undefined1 *)dstPixel = 0x7f;
                      if (floatOne < pixelRed) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelRed < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelRed * float127B);
                          componentByte = (undefined1)fctiwzSlotF0;
                          fctiwzSlotF0 = (longlong)(int)(pixelRed * float127B);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 1) = componentByte;
                      if (floatOne < pixelGreen) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelGreen < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelGreen * float127B);
                          componentByte = (undefined1)fctiwzSlotF0;
                          fctiwzSlotF0 = (longlong)(int)(pixelGreen * float127B);
                        }
                      }
                      *(undefined1 *)((int)dstPixel + 2) = componentByte;
                      if (floatOne < pixelBlue) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelBlue < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelBlue * float127B);
                          componentByte = (undefined1)fctiwzSlotF0;
                          fctiwzSlotF0 = (longlong)(int)(pixelBlue * float127B);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)((int)dstPixel + 3) = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstType == 0x8032) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255B = FLOAT_00108f70;
                  columnsLeft2 = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      fctiwzSlot100 = (longlong)(int)(pixelRed * float255B);
                      fctiwzSlotF8 = (longlong)(int)(pixelGreen * float255B);
                      fctiwzSlotF0 = (longlong)(int)(pixelBlue * float255B);
                      *(byte *)dstPixel =
                           (byte)(int)(pixelRed * float255B) & 0xe0 |
                           (byte)((uint)(int)(pixelGreen * float255B) >> 3) & 0x1c |
                           (byte)((uint)(int)(pixelBlue * float255B) >> 6) & 3;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + 1);
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      else {
        if (dstType == 0x8363) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  if (0 < width) {
                    scaleSpill = float65535;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      fctiwzSlotF0 = (longlong)(int)(pixelRed * float65535);
                      fctiwzSlotF8 = (longlong)(int)(pixelGreen * float65535);
                      fctiwzSlot100 = (longlong)(int)(pixelBlue * float65535);
                      *(ushort *)dstPixel =
                           (ushort)(int)(pixelRed * float65535) & 0xf800 |
                           (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(pixelBlue * float65535) >> 0xb) & 0x1f;
                      dstPixel = (uint *)((int)dstPixel + 2);
                      srcPixel = srcPixel + srcPixelStride;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstType == 0x8364) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  if (0 < width) {
                    scaleSpill = float65535;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      columnsLeft2 = columnsLeft2 + -1;
                      fctiwzSlotF0 = (longlong)(int)(pixelBlue * float65535);
                      fctiwzSlotF8 = (longlong)(int)(pixelGreen * float65535);
                      fctiwzSlot100 = (longlong)(int)(pixelRed * float65535);
                      *(ushort *)dstPixel =
                           (ushort)(int)(pixelBlue * float65535) & 0xf800 |
                           (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7e0 |
                           (ushort)((uint)(int)(pixelRed * float65535) >> 0xb) & 0x1f;
                      dstPixel = (uint *)((int)dstPixel + 2);
                      srcPixel = srcPixel + srcPixelStride;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
      }
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  if (floatOne2 < pixelRed) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelRed < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelRed * float255C);
                      componentByte = (undefined1)fctiwzSlotF0;
                      fctiwzSlotF0 = (longlong)(int)(pixelRed * float255C);
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < pixelGreen) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelGreen < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                      componentByte = (undefined1)fctiwzSlotF0;
                      fctiwzSlotF0 = (longlong)(int)(pixelGreen * float255C);
                    }
                  }
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  if (floatOne2 < pixelBlue) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelBlue < floatZero)) {
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotF0) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                      componentByte = (undefined1)fctiwzSlotF0;
                      fctiwzSlotF0 = (longlong)(int)(pixelBlue * float255C);
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 2) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (dstFormat < 0x1908) {
      if (dstFormat == 0x1902) {
        if (*(short *)(textureLevel + 0x12) == 0x1405) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      scaledComponent = (double)pixelDepth * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        fctiwzSlotD0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        fctiwzSlotC8 = (longlong)(int)componentUint;
                      }
                      columnsLeft = columnsLeft + -1;
                      *dstPixel = componentUint;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + componentCount;
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            float65535 = FLOAT_00108ea0;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                if (0 < width) {
                  scaleSpill = float65535;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    columnsLeft = columnsLeft + -1;
                    scaledInt = (int)(pixelDepth * float65535);
                    fctiwzSlotC8 = (longlong)scaledInt;
                    *(short *)dstPixel = (short)scaledInt;
                    dstPixel = (uint *)((int)dstPixel + componentCount * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (dstFormat == 0x1906) {
        if (*(short *)(textureLevel + 0x12) == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float255C = FLOAT_00108f70;
                  floatOne2 = FLOAT_00108e54;
                  floatZero = FLOAT_00108e50;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      if (floatOne2 < pixelAlpha) {
                        componentByte = 0xff;
                      }
                      else {
                        componentByte = 0;
                        if (!(pixelAlpha < floatZero)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                          componentByte = (undefined1)fctiwzSlotC8;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne2 < pixelAlpha) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelAlpha < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
    else {
      if (dstFormat == 0x1908) {
        dstType = *(ushort *)(textureLevel + 0x12);
        if (dstType == 0x8035) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  dstPixel = dstRow;
                  columnsLeft2 = width;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        fctiwzSlotF0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        fctiwzSlotE8 = (longlong)(int)componentUint;
                      }
                      scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint2 = (uint)(int)scaledComponent;
                        fctiwzSlotF8 = (longlong)(int)componentUint2;
                      }
                      scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlotD8 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint3 = (uint)(int)scaledComponent;
                        fctiwzSlotE0 = (longlong)(int)componentUint3;
                      }
                      scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlotC8 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint4 = (uint)(int)scaledComponent;
                        fctiwzSlotD0 = (longlong)(int)componentUint4;
                      }
                      columnsLeft2 = columnsLeft2 + -1;
                      *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                 componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + 1;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstType < 0x8036) {
          if (dstType == 8) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    float127B = FLOAT_00108f6c;
                    floatMinusOne = FLOAT_00108e58;
                    floatOne = FLOAT_00108e54;
                    columnsLeft = width;
                    dstPixel = dstRow;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        if (floatOne < pixelAlpha) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelAlpha < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float127B);
                          }
                        }
                        *(undefined1 *)dstPixel = componentByte;
                        if (floatOne < pixelRed) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelRed < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 1) = componentByte;
                        if (floatOne < pixelGreen) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelGreen < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelGreen * float127B);
                          }
                        }
                        *(undefined1 *)((int)dstPixel + 2) = componentByte;
                        if (floatOne < pixelBlue) {
                          componentByte = 0x7f;
                        }
                        else {
                          componentByte = 0x81;
                          if (!(pixelBlue < floatMinusOne)) {
                            (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float127B);
                            componentByte = (undefined1)fctiwzSlotC8;
                            fctiwzSlotC8 = (longlong)(int)(pixelBlue * float127B);
                          }
                        }
                        columnsLeft = columnsLeft + -1;
                        *(undefined1 *)((int)dstPixel + 3) = componentByte;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = (uint *)((int)dstPixel + componentCount);
                      } while (columnsLeft != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType < 9) {
            if (dstType == 7) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      float255 = FLOAT_00108f70;
                      float127 = FLOAT_00108f6c;
                      floatMinusOne2 = FLOAT_00108e58;
                      floatOne2 = FLOAT_00108e54;
                      floatZero = FLOAT_00108e50;
                      if (0 < width) {
                        puVar30 = (undefined1 *)((int)dstRow + 3);
                        dstPixel = dstRow;
                        columnsLeft = width;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          if (floatOne2 < pixelAlpha) {
                            componentByte = 0xff;
                          }
                          else {
                            componentByte = 0;
                            if (!(pixelAlpha < floatZero)) {
                              (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255);
                              componentByte = (undefined1)fctiwzSlotC8;
                              fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255);
                            }
                          }
                          *(undefined1 *)dstPixel = componentByte;
                          if (floatOne2 < pixelRed) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(pixelRed < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127);
                              componentByte = (undefined1)fctiwzSlotC8;
                              fctiwzSlotC8 = (longlong)(int)(pixelRed * float127);
                            }
                          }
                          puVar30[-2] = componentByte;
                          if (floatOne2 < pixelGreen) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(pixelGreen < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float127);
                              componentByte = (undefined1)fctiwzSlotC8;
                              fctiwzSlotC8 = (longlong)(int)(pixelGreen * float127);
                            }
                          }
                          puVar30[-1] = componentByte;
                          if (floatOne2 < pixelBlue) {
                            componentByte = 0x7f;
                          }
                          else {
                            componentByte = 0x81;
                            if (!(pixelBlue < floatMinusOne2)) {
                              (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float127);
                              componentByte = (undefined1)fctiwzSlotC8;
                              fctiwzSlotC8 = (longlong)(int)(pixelBlue * float127);
                            }
                          }
                          columnsLeft = columnsLeft + -1;
                          *puVar30 = componentByte;
                          puVar30 = puVar30 + componentCount;
                          dstPixel = (uint *)((int)dstPixel + componentCount);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (dstType == 0x8033) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotF0 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotF8 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlot100 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlotE8 = (longlong)(int)(pixelAlpha * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelRed * float65535) & 0xf000 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType == 0x8034) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotE8 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotF0 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotF8 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlot100 = (longlong)(int)(pixelAlpha * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelRed * float65535) & 0xf800 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7c0 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 10) & 0x3e |
                               (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xf) & 1;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        else {
          if (dstType == 0x8366) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotE8 = (longlong)(int)(pixelAlpha * float65535);
                        fctiwzSlotF0 = (longlong)(int)(pixelBlue * float65535);
                        fctiwzSlotF8 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlot100 = (longlong)(int)(pixelRed * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelAlpha * float65535) & 0x8000 |
                             (ushort)((uint)(int)(pixelBlue * float65535) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(pixelRed * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType < 0x8367) {
            if (dstType == 0x8036) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            fctiwzSlotD0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            fctiwzSlotC8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint2 = (uint)(int)scaledComponent;
                            fctiwzSlotD8 = (longlong)(int)componentUint2;
                          }
                          scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint3 = (uint)(int)scaledComponent;
                            fctiwzSlotE8 = (longlong)(int)componentUint3;
                          }
                          scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint4 = (uint)(int)scaledComponent;
                            fctiwzSlotF8 = (longlong)(int)componentUint4;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xffc00000 | componentUint2 >> 10 & 0x3ff000 |
                                     componentUint3 >> 0x14 & 0xffc | componentUint4 >> 0x1e;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType == 0x8365) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotE8 = (longlong)(int)(pixelAlpha * float65535);
                          fctiwzSlotF0 = (longlong)(int)(pixelBlue * float65535);
                          fctiwzSlotF8 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlot100 = (longlong)(int)(pixelRed * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelAlpha * float65535) & 0xf000 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(pixelRed * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (dstType == 0x8367) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            fctiwzSlotD0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            fctiwzSlotC8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint2 = (uint)(int)scaledComponent;
                            fctiwzSlotD8 = (longlong)(int)componentUint2;
                          }
                          scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint3 = (uint)(int)scaledComponent;
                            fctiwzSlotE8 = (longlong)(int)componentUint3;
                          }
                          scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint4 = (uint)(int)scaledComponent;
                            fctiwzSlotF8 = (longlong)(int)componentUint4;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                     componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType == 0x8368) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            fctiwzSlotD0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            fctiwzSlotC8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint2 = (uint)(int)scaledComponent;
                            fctiwzSlotD8 = (longlong)(int)componentUint2;
                          }
                          scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint3 = (uint)(int)scaledComponent;
                            fctiwzSlotE8 = (longlong)(int)componentUint3;
                          }
                          scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint4 = (uint)(int)scaledComponent;
                            fctiwzSlotF8 = (longlong)(int)componentUint4;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xc0000000 | componentUint2 >> 2 & 0x3ff00000 |
                                     componentUint3 >> 0xc & 0xffc00 | componentUint4 >> 0x16;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne2 < pixelRed) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelRed < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < pixelGreen) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelGreen < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelGreen * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < pixelBlue) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelBlue < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    if (floatOne2 < pixelAlpha) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelAlpha < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 3) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      if (dstFormat == 0x1909) {
        if (*(short *)(textureLevel + 0x12) == 0x1400) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  float127B = FLOAT_00108f6c;
                  floatMinusOne = FLOAT_00108e58;
                  floatOne = FLOAT_00108e54;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      if (floatOne < pixelRed) {
                        componentByte = 0x7f;
                      }
                      else {
                        componentByte = 0x81;
                        if (!(pixelRed < floatMinusOne)) {
                          (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)(int)(pixelRed * float127B);
                          componentByte = (undefined1)fctiwzSlot100;
                          fctiwzSlot100 = (longlong)(int)(pixelRed * float127B);
                        }
                      }
                      columnsLeft = columnsLeft + -1;
                      *(undefined1 *)dstPixel = componentByte;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = (uint *)((int)dstPixel + componentCount);
                    } while (columnsLeft != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
        }
        else if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne2 < pixelRed) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelRed < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlot100) + 7)) = (undefined1)(int)(pixelRed * float255C);
                        componentByte = (undefined1)fctiwzSlot100;
                        fctiwzSlot100 = (longlong)(int)(pixelRed * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
    }
  }
  else {
    if (dstFormat == 0x86f4) {
      dstType = *(ushort *)(textureLevel + 0x12);
      if (dstType == 6) {
        if (0 < (int)depth) {
          do {
            float32767 = FLOAT_00108f74;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                floatMinusOne2 = FLOAT_00108e58;
                floatOne2 = FLOAT_00108e54;
                if (0 < width) {
                  scaleSpill = float32767;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne2 < pixelHi) {
                      componentShort = 0x7fff;
                    }
                    else {
                      componentShort = 0x8001;
                      if (!(pixelHi < floatMinusOne2)) {
                        (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)(int)(pixelHi * float32767);
                        componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                        fctiwzSlotC8 = (longlong)(int)(pixelHi * float32767);
                      }
                    }
                    *(undefined2 *)dstPixel = componentShort;
                    if (floatOne2 < pixelLo) {
                      componentShort = 0x7fff;
                    }
                    else {
                      componentShort = 0x8001;
                      if (!(pixelLo < floatMinusOne2)) {
                        (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)(int)(pixelLo * float32767);
                        componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                        fctiwzSlotC8 = (longlong)(int)(pixelLo * float32767);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined2 *)((int)dstPixel + 2) = componentShort;
                    dstPixel = (uint *)((int)dstPixel + componentCount * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (dstType < 7) {
        if ((dstType == 5) && (0 < (int)depth)) {
          do {
            float65535 = FLOAT_00108ea0;
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                floatOne3 = FLOAT_00108e54;
                floatZero2 = FLOAT_00108e50;
                if (0 < width) {
                  scaleSpill = float65535;
                  columnsLeft = width;
                  dstPixel = dstRow;
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne3 < pixelHi) {
                      componentShort = 0xffff;
                    }
                    else {
                      componentShort = 0;
                      if (!(pixelHi < floatZero2)) {
                        (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)(int)(pixelHi * float65535);
                        componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                        fctiwzSlotC8 = (longlong)(int)(pixelHi * float65535);
                      }
                    }
                    *(undefined2 *)dstPixel = componentShort;
                    if (floatOne3 < pixelLo) {
                      componentShort = 0xffff;
                    }
                    else {
                      componentShort = 0;
                      if (!(pixelLo < floatZero2)) {
                        (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6)) = (undefined2)(int)(pixelLo * float65535);
                        componentShort = (*(unsigned short *)((unsigned char *)&(fctiwzSlotC8) + 6));
                        fctiwzSlotC8 = (longlong)(int)(pixelLo * float65535);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined2 *)((int)dstPixel + 2) = componentShort;
                    dstPixel = (uint *)((int)dstPixel + componentCount * 2);
                    srcPixel = srcPixel + srcPixelStride;
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if (dstType == 0x1400) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne < pixelHi) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelHi < floatMinusOne)) {
                        scaledInt = (int)(pixelHi * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne < pixelLo) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelLo < floatMinusOne)) {
                        scaledInt = (int)(pixelLo * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
      }
      else if ((dstType == 0x1401) && (0 < (int)depth)) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255C = FLOAT_00108f70;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              columnsLeft = width;
              dstPixel = dstRow;
              if (0 < width) {
                do {
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  if (floatOne2 < pixelHi) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelHi < floatZero)) {
                      scaledInt = (int)(pixelHi * float255C);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)dstPixel = componentByte;
                  if (floatOne2 < pixelLo) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelLo < floatZero)) {
                      scaledInt = (int)(pixelLo * float255C);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  srcPixel = srcPixel + srcPixelStride;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
    if (dstFormat < 0x86f5) {
      if (dstFormat == 0x80e1) {
        dstType = *(ushort *)(textureLevel + 0x12);
        if (dstType == 0x8036) {
          if (0 < (int)depth) {
            do {
              rowsLeft = height;
              dstRow = dstSlice;
              if (0 < (int)height) {
                do {
                  twoPow31 = DOUBLE_00108d80;
                  dstPixel = dstRow;
                  columnsLeft2 = width;
                  if (0 < width) {
                    do {
                      (*extractPixelFunc)(pixelRecord,srcPixel);
                      scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                      if (twoPow31 <= scaledComponent) {
                        componentUint = (uint)(int)(scaledComponent - twoPow31);
                        fctiwzSlotD0 = (longlong)(int)componentUint;
                        componentUint = componentUint ^ 0x80000000;
                      }
                      else {
                        componentUint = (uint)(int)scaledComponent;
                        fctiwzSlotC8 = (longlong)(int)componentUint;
                      }
                      scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint2 = (uint)(int)scaledComponent;
                        fctiwzSlotD8 = (longlong)(int)componentUint2;
                      }
                      scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint3 = (uint)(int)scaledComponent;
                        fctiwzSlotE8 = (longlong)(int)componentUint3;
                      }
                      scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                      if (DOUBLE_00108d80 <= scaledComponent) {
                        fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                        componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                      }
                      else {
                        componentUint4 = (uint)(int)scaledComponent;
                        fctiwzSlotF8 = (longlong)(int)componentUint4;
                      }
                      columnsLeft2 = columnsLeft2 + -1;
                      *dstPixel = componentUint & 0xffc00000 | componentUint2 >> 10 & 0x3ff000 |
                                 componentUint3 >> 0x14 & 0xffc | componentUint4 >> 0x1e;
                      srcPixel = srcPixel + srcPixelStride;
                      dstPixel = dstPixel + 1;
                    } while (columnsLeft2 != 0);
                  }
                  rowsLeft = rowsLeft - 1;
                  srcPixel = srcPixel + srcRowPad;
                  dstRow = (uint *)((int)dstRow + rowBytes);
                } while (rowsLeft != 0);
              }
              depth = depth - 1;
              dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
              srcPixel = srcPixel + srcImagePad;
            } while (depth != 0);
          }
          goto LAB_0002e240;
        }
        if (dstType < 0x8037) {
          if (dstType == 0x8034) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float65535);
                        fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlotD8 = (longlong)(int)(pixelRed * float65535);
                        fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelBlue * float65535) & 0xf800 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 5) & 0x7c0 |
                             (ushort)((uint)(int)(pixelRed * float65535) >> 10) & 0x3e |
                             (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xf) & 1;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (0x8034 < dstType) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    twoPow31 = DOUBLE_00108d80;
                    dstPixel = dstRow;
                    columnsLeft2 = width;
                    if (0 < width) {
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                        if (twoPow31 <= scaledComponent) {
                          componentUint = (uint)(int)(scaledComponent - twoPow31);
                          fctiwzSlotD0 = (longlong)(int)componentUint;
                          componentUint = componentUint ^ 0x80000000;
                        }
                        else {
                          componentUint = (uint)(int)scaledComponent;
                          fctiwzSlotC8 = (longlong)(int)componentUint;
                        }
                        scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint2 = (uint)(int)scaledComponent;
                          fctiwzSlotD8 = (longlong)(int)componentUint2;
                        }
                        scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint3 = (uint)(int)scaledComponent;
                          fctiwzSlotE8 = (longlong)(int)componentUint3;
                        }
                        scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                        if (DOUBLE_00108d80 <= scaledComponent) {
                          fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                          componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                        }
                        else {
                          componentUint4 = (uint)(int)scaledComponent;
                          fctiwzSlotF8 = (longlong)(int)componentUint4;
                        }
                        columnsLeft2 = columnsLeft2 + -1;
                        *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                   componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                        srcPixel = srcPixel + srcPixelStride;
                        dstPixel = dstPixel + 1;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType == 0x8033) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float65535);
                        fctiwzSlotD0 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlotD8 = (longlong)(int)(pixelRed * float65535);
                        fctiwzSlotE0 = (longlong)(int)(pixelAlpha * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelBlue * float65535) & 0xf000 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 4) & 0xf00 |
                             (ushort)((uint)(int)(pixelRed * float65535) >> 8) & 0xf0 |
                             (ushort)((uint)(int)(pixelAlpha * float65535) >> 0xc) & 0xf;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
        }
        else {
          if (dstType == 0x8366) {
            if (0 < (int)depth) {
              do {
                rowsLeft = height;
                dstRow = dstSlice;
                if (0 < (int)height) {
                  do {
                    if (0 < width) {
                      scaleSpill = float65535;
                      columnsLeft2 = width;
                      dstPixel = dstRow;
                      do {
                        (*extractPixelFunc)(pixelRecord,srcPixel);
                        columnsLeft2 = columnsLeft2 + -1;
                        fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                        fctiwzSlotD0 = (longlong)(int)(pixelRed * float65535);
                        fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                        fctiwzSlotE0 = (longlong)(int)(pixelBlue * float65535);
                        *(ushort *)dstPixel =
                             (ushort)(int)(pixelAlpha * float65535) & 0x8000 |
                             (ushort)((uint)(int)(pixelRed * float65535) >> 1) & 0x7c00 |
                             (ushort)((uint)(int)(pixelGreen * float65535) >> 6) & 0x3e0 |
                             (ushort)((uint)(int)(pixelBlue * float65535) >> 0xb) & 0x1f;
                        dstPixel = (uint *)((int)dstPixel + 2);
                        srcPixel = srcPixel + srcPixelStride;
                      } while (columnsLeft2 != 0);
                    }
                    rowsLeft = rowsLeft - 1;
                    srcPixel = srcPixel + srcRowPad;
                    dstRow = (uint *)((int)dstRow + rowBytes);
                  } while (rowsLeft != 0);
                }
                depth = depth - 1;
                dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                srcPixel = srcPixel + srcImagePad;
              } while (depth != 0);
            }
            goto LAB_0002e240;
          }
          if (dstType < 0x8367) {
            if (dstType == 0x8365) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      if (0 < width) {
                        scaleSpill = float65535;
                        columnsLeft2 = width;
                        dstPixel = dstRow;
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          columnsLeft2 = columnsLeft2 + -1;
                          fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float65535);
                          fctiwzSlotD0 = (longlong)(int)(pixelRed * float65535);
                          fctiwzSlotD8 = (longlong)(int)(pixelGreen * float65535);
                          fctiwzSlotE0 = (longlong)(int)(pixelBlue * float65535);
                          *(ushort *)dstPixel =
                               (ushort)(int)(pixelAlpha * float65535) & 0xf000 |
                               (ushort)((uint)(int)(pixelRed * float65535) >> 4) & 0xf00 |
                               (ushort)((uint)(int)(pixelGreen * float65535) >> 8) & 0xf0 |
                               (ushort)((uint)(int)(pixelBlue * float65535) >> 0xc) & 0xf;
                          dstPixel = (uint *)((int)dstPixel + 2);
                          srcPixel = srcPixel + srcPixelStride;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
          else {
            if (dstType == 0x8367) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            fctiwzSlotD0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            fctiwzSlotC8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint2 = (uint)(int)scaledComponent;
                            fctiwzSlotD8 = (longlong)(int)componentUint2;
                          }
                          scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint3 = (uint)(int)scaledComponent;
                            fctiwzSlotE8 = (longlong)(int)componentUint3;
                          }
                          scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint4 = (uint)(int)scaledComponent;
                            fctiwzSlotF8 = (longlong)(int)componentUint4;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xff000000 | componentUint2 >> 8 & 0xff0000 |
                                     componentUint3 >> 0x10 & 0xff00 | componentUint4 >> 0x18;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
            if (dstType == 0x8368) {
              if (0 < (int)depth) {
                do {
                  rowsLeft = height;
                  dstRow = dstSlice;
                  if (0 < (int)height) {
                    do {
                      twoPow31 = DOUBLE_00108d80;
                      dstPixel = dstRow;
                      columnsLeft2 = width;
                      if (0 < width) {
                        do {
                          (*extractPixelFunc)(pixelRecord,srcPixel);
                          scaledComponent = (double)pixelAlpha * uint32MaxAsDouble;
                          if (twoPow31 <= scaledComponent) {
                            componentUint = (uint)(int)(scaledComponent - twoPow31);
                            fctiwzSlotD0 = (longlong)(int)componentUint;
                            componentUint = componentUint ^ 0x80000000;
                          }
                          else {
                            componentUint = (uint)(int)scaledComponent;
                            fctiwzSlotC8 = (longlong)(int)componentUint;
                          }
                          scaledComponent = (double)pixelRed * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotE0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint2 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint2 = (uint)(int)scaledComponent;
                            fctiwzSlotD8 = (longlong)(int)componentUint2;
                          }
                          scaledComponent = (double)pixelGreen * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlotF0 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint3 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint3 = (uint)(int)scaledComponent;
                            fctiwzSlotE8 = (longlong)(int)componentUint3;
                          }
                          scaledComponent = (double)pixelBlue * uint32MaxAsDouble;
                          if (DOUBLE_00108d80 <= scaledComponent) {
                            fctiwzSlot100 = (longlong)(int)(scaledComponent - DOUBLE_00108d80);
                            componentUint4 = (int)(scaledComponent - DOUBLE_00108d80) ^ 0x80000000;
                          }
                          else {
                            componentUint4 = (uint)(int)scaledComponent;
                            fctiwzSlotF8 = (longlong)(int)componentUint4;
                          }
                          columnsLeft2 = columnsLeft2 + -1;
                          *dstPixel = componentUint & 0xc0000000 | componentUint2 >> 2 & 0x3ff00000 |
                                     componentUint3 >> 0xc & 0xffc00 | componentUint4 >> 0x16;
                          srcPixel = srcPixel + srcPixelStride;
                          dstPixel = dstPixel + 1;
                        } while (columnsLeft2 != 0);
                      }
                      rowsLeft = rowsLeft - 1;
                      srcPixel = srcPixel + srcRowPad;
                      dstRow = (uint *)((int)dstRow + rowBytes);
                    } while (rowsLeft != 0);
                  }
                  depth = depth - 1;
                  dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
                  srcPixel = srcPixel + srcImagePad;
                } while (depth != 0);
              }
              goto LAB_0002e240;
            }
          }
        }
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float255C = FLOAT_00108f70;
                floatOne2 = FLOAT_00108e54;
                floatZero = FLOAT_00108e50;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne2 < pixelBlue) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelBlue < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelBlue * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelBlue * float255C);
                      }
                    }
                    *(undefined1 *)dstPixel = componentByte;
                    if (floatOne2 < pixelGreen) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelGreen < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelGreen * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelGreen * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne2 < pixelRed) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelRed < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 2) = componentByte;
                    if (floatOne2 < pixelAlpha) {
                      componentByte = 0xff;
                    }
                    else {
                      componentByte = 0;
                      if (!(pixelAlpha < floatZero)) {
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelAlpha * float255C);
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)(int)(pixelAlpha * float255C);
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)((int)dstPixel + 3) = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      compareFormat = 0x86dc;
    }
    else {
      if (dstFormat == 0x86f5) {
        if (0 < (int)depth) {
          do {
            rowsLeft = height;
            dstRow = dstSlice;
            if (0 < (int)height) {
              do {
                float127B = FLOAT_00108f6c;
                floatMinusOne = FLOAT_00108e58;
                floatOne = FLOAT_00108e54;
                columnsLeft = width;
                dstPixel = dstRow;
                if (0 < width) {
                  do {
                    (*extractPixelFunc)(pixelRecord,srcPixel);
                    if (floatOne < pixelDs) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelDs < floatMinusOne)) {
                        scaledInt = (int)(pixelDs * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    *(undefined1 *)((int)dstPixel + 1) = componentByte;
                    if (floatOne < pixelDt) {
                      componentByte = 0x7f;
                    }
                    else {
                      componentByte = 0x81;
                      if (!(pixelDt < floatMinusOne)) {
                        scaledInt = (int)(pixelDt * float127B);
                        (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                        componentByte = (undefined1)fctiwzSlotC8;
                        fctiwzSlotC8 = (longlong)scaledInt;
                      }
                    }
                    columnsLeft = columnsLeft + -1;
                    *(undefined1 *)dstPixel = componentByte;
                    srcPixel = srcPixel + srcPixelStride;
                    dstPixel = (uint *)((int)dstPixel + componentCount);
                  } while (columnsLeft != 0);
                }
                rowsLeft = rowsLeft - 1;
                srcPixel = srcPixel + srcRowPad;
                dstRow = (uint *)((int)dstRow + rowBytes);
              } while (rowsLeft != 0);
            }
            depth = depth - 1;
            dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
            srcPixel = srcPixel + srcImagePad;
          } while (depth != 0);
        }
        goto LAB_0002e240;
      }
      compareFormat = 0x86f6;
    }
    if (dstFormat == compareFormat) {
      if (0 < (int)depth) {
        do {
          rowsLeft = height;
          dstRow = dstSlice;
          if (0 < (int)height) {
            do {
              float255 = FLOAT_00108f70;
              float127 = FLOAT_00108f6c;
              floatMinusOne2 = FLOAT_00108e58;
              floatOne2 = FLOAT_00108e54;
              floatZero = FLOAT_00108e50;
              if (0 < width) {
                puVar30 = (undefined1 *)((int)dstRow + 2);
                dstPixel = dstRow;
                columnsLeft = width;
                do {
                  (*extractPixelFunc)(pixelRecord,srcPixel);
                  if (floatOne2 < pixelDs) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(pixelDs < floatMinusOne2)) {
                      scaledInt = (int)(pixelDs * float127);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  puVar30[1] = componentByte;
                  if (floatOne2 < pixelDt) {
                    componentByte = 0x7f;
                  }
                  else {
                    componentByte = 0x81;
                    if (!(pixelDt < floatMinusOne2)) {
                      scaledInt = (int)(pixelDt * float127);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  *puVar30 = componentByte;
                  if (floatOne2 < pixelMagnitude) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelMagnitude < floatZero)) {
                      scaledInt = (int)(pixelMagnitude * float255);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  *(undefined1 *)((int)dstPixel + 1) = componentByte;
                  if (floatOne2 < pixelRed) {
                    componentByte = 0xff;
                  }
                  else {
                    componentByte = 0;
                    if (!(pixelRed < floatZero)) {
                      scaledInt = (int)(pixelRed * float255);
                      (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)scaledInt;
                      componentByte = (undefined1)fctiwzSlotC8;
                      fctiwzSlotC8 = (longlong)scaledInt;
                    }
                  }
                  columnsLeft = columnsLeft + -1;
                  *(undefined1 *)dstPixel = componentByte;
                  puVar30 = puVar30 + componentCount;
                  dstPixel = (uint *)((int)dstPixel + componentCount);
                  srcPixel = srcPixel + srcPixelStride;
                } while (columnsLeft != 0);
              }
              rowsLeft = rowsLeft - 1;
              srcPixel = srcPixel + srcRowPad;
              dstRow = (uint *)((int)dstRow + rowBytes);
            } while (rowsLeft != 0);
          }
          depth = depth - 1;
          dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
          srcPixel = srcPixel + srcImagePad;
        } while (depth != 0);
      }
      goto LAB_0002e240;
    }
  }
  if (*(short *)(textureLevel + 0x12) == 0x1400) {
    if (0 < (int)depth) {
      do {
        rowsLeft = height;
        dstRow = dstSlice;
        if (0 < (int)height) {
          do {
            float127B = FLOAT_00108f6c;
            floatMinusOne = FLOAT_00108e58;
            floatOne = FLOAT_00108e54;
            columnsLeft = width;
            dstPixel = dstRow;
            if (0 < width) {
              do {
                (*extractPixelFunc)(pixelRecord,srcPixel);
                if (floatOne < pixelRed) {
                  componentByte = 0x7f;
                }
                else {
                  componentByte = 0x81;
                  if (!(pixelRed < floatMinusOne)) {
                    (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float127B);
                    componentByte = (undefined1)fctiwzSlotC8;
                    fctiwzSlotC8 = (longlong)(int)(pixelRed * float127B);
                  }
                }
                columnsLeft = columnsLeft + -1;
                *(undefined1 *)dstPixel = componentByte;
                srcPixel = srcPixel + srcPixelStride;
                dstPixel = (uint *)((int)dstPixel + componentCount);
              } while (columnsLeft != 0);
            }
            rowsLeft = rowsLeft - 1;
            srcPixel = srcPixel + srcRowPad;
            dstRow = (uint *)((int)dstRow + rowBytes);
          } while (rowsLeft != 0);
        }
        depth = depth - 1;
        dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
        srcPixel = srcPixel + srcImagePad;
      } while (depth != 0);
    }
  }
  else if (0 < (int)depth) {
    do {
      rowsLeft = height;
      dstRow = dstSlice;
      if (0 < (int)height) {
        do {
          float255C = FLOAT_00108f70;
          floatOne2 = FLOAT_00108e54;
          floatZero = FLOAT_00108e50;
          columnsLeft = width;
          dstPixel = dstRow;
          if (0 < width) {
            do {
              (*extractPixelFunc)(pixelRecord,srcPixel);
              if (floatOne2 < pixelRed) {
                componentByte = 0xff;
              }
              else {
                componentByte = 0;
                if (!(pixelRed < floatZero)) {
                  (*(unsigned char *)((unsigned char *)&(fctiwzSlotC8) + 7)) = (undefined1)(int)(pixelRed * float255C);
                  componentByte = (undefined1)fctiwzSlotC8;
                  fctiwzSlotC8 = (longlong)(int)(pixelRed * float255C);
                }
              }
              columnsLeft = columnsLeft + -1;
              *(undefined1 *)dstPixel = componentByte;
              srcPixel = srcPixel + srcPixelStride;
              dstPixel = (uint *)((int)dstPixel + componentCount);
            } while (columnsLeft != 0);
          }
          rowsLeft = rowsLeft - 1;
          srcPixel = srcPixel + srcRowPad;
          dstRow = (uint *)((int)dstRow + rowBytes);
        } while (rowsLeft != 0);
      }
      depth = depth - 1;
      dstSlice = (uint *)((int)dstSlice + dstSliceBytes);
      srcPixel = srcPixel + srcImagePad;
    } while (depth != 0);
  }
LAB_0002e240:
  if (freeTempImage) {
    _free(pixels);
  }
  return;
}

/* _gleSelectPixelExtractFunc @ 0x2e264 (3124 bytes) */
int _gleSelectPixelExtractFunc(format, type)
  uint format;
  uint type;
{
  if (format == 0x1908) {
    if (type == 0x1406) {
      return PTR__gleExtractPixel_RGBA_Float_00111074;
    }
    if (type < 0x1407) {
      if (type == 0x1402) {
        return PTR__gleExtractPixel_RGBA_Short_00111084;
      }
      if (0x1402 < type) {
        if (type == 0x1404) {
          return PTR__gleExtractPixel_RGBA_Int_0011107c;
        }
        if (0x1404 < type) {
          return PTR__gleExtractPixel_RGBA_Uint_00111078;
        }
        return PTR__gleExtractPixel_RGBA_Ushort_00111080;
      }
      if (type == 0x1400) {
        return PTR__gleExtractPixel_RGBA_Byte_0011108c;
      }
      if (type == 0x1401) {
        return PTR__gleExtractPixel_RGBA_Ubyte_00111088;
      }
    }
    else {
      if (type == 0x8036) {
        return PTR__gleExtractPixel_RGBA_1010102_00111058;
      }
      if (type < 0x8037) {
        if (type == 0x8034) {
          return PTR__gleExtractPixel_RGBA_5551_00111068;
        }
        if (0x8034 < type) {
          return PTR__gleExtractPixel_RGBA_8888_00111060;
        }
        if (type == 0x8033) {
          return PTR__gleExtractPixel_RGBA_4444_00111070;
        }
      }
      else {
        if (type == 0x8366) {
          return PTR__gleExtractPixel_RGBA_1555Rev_00111064;
        }
        if (type < 0x8367) {
          if (type == 0x8365) {
            return PTR__gleExtractPixel_RGBA_4444Rev_0011106c;
          }
        }
        else if (type == 0x8367) {
          return PTR__gleExtractPixel_RGBA_8888Rev_0011105c;
        }
      }
    }
    return PTR__gleExtractPixel_RGBA_2101010Rev_00111054;
  }
  if (format < 0x1909) {
    if (format == 0x1903) {
      switch(type) {
      case 0x1400:
        return PTR__gleExtractPixel_R_Byte_00110f38;
      case 0x1401:
        return PTR__gleExtractPixel_R_Ubyte_00110f34;
      case 0x1402:
        return PTR__gleExtractPixel_R_Short_00110f30;
      case 0x1403:
        return PTR__gleExtractPixel_R_Ushort_00110f2c;
      case 0x1404:
        return PTR__gleExtractPixel_R_Int_00110f28;
      case 0x1405:
        return PTR__gleExtractPixel_R_Uint_00110f24;
      default:
        return PTR__gleExtractPixel_R_Float_00110f20;
      }
    }
    if (format < 0x1904) {
      if (0x18ff < format) {
        if (0x1901 < format) {
          switch(type) {
          case 0x1400:
            return PTR__gleExtractPixel_Depth_Byte_001110a8;
          case 0x1401:
            return PTR__gleExtractPixel_Depth_Ubyte_001110a4;
          case 0x1402:
            return PTR__gleExtractPixel_Depth_Short_001110a0;
          case 0x1403:
            return PTR__gleExtractPixel_Depth_Ushort_0011109c;
          case 0x1404:
            return PTR__gleExtractPixel_Depth_Int_00111098;
          case 0x1405:
            return PTR__gleExtractPixel_Depth_Uint_00111094;
          default:
            return PTR__gleExtractPixel_Depth_Float_00111090;
          }
        }
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_Index_Byte_001110c4;
        case 0x1401:
          return PTR__gleExtractPixel_Index_Ubyte_001110c0;
        case 0x1402:
          return PTR__gleExtractPixel_Index_Short_001110bc;
        case 0x1403:
          return PTR__gleExtractPixel_Index_Ushort_001110b8;
        case 0x1404:
          return PTR__gleExtractPixel_Index_Int_001110b4;
        case 0x1405:
          return PTR__gleExtractPixel_Index_Uint_001110b0;
        default:
          return PTR__gleExtractPixel_Index_Float_001110ac;
        }
      }
    }
    else {
      if (format == 0x1905) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_B_Byte_00110f00;
        case 0x1401:
          return PTR__gleExtractPixel_B_Ubyte_00110efc;
        case 0x1402:
          return PTR__gleExtractPixel_B_Short_00110ef8;
        case 0x1403:
          return PTR__gleExtractPixel_B_Ushort_00110ef4;
        case 0x1404:
          return PTR__gleExtractPixel_B_Int_00110ef0;
        case 0x1405:
          return PTR__gleExtractPixel_B_Uint_00110eec;
        default:
          return PTR__gleExtractPixel_B_Float_00110ee8;
        }
      }
      if (format < 0x1905) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_G_Byte_00110f1c;
        case 0x1401:
          return PTR__gleExtractPixel_G_Ubyte_00110f18;
        case 0x1402:
          return PTR__gleExtractPixel_G_Short_00110f14;
        case 0x1403:
          return PTR__gleExtractPixel_G_Ushort_00110f10;
        case 0x1404:
          return PTR__gleExtractPixel_G_Int_00110f0c;
        case 0x1405:
          return PTR__gleExtractPixel_G_Uint_00110f08;
        default:
          return PTR__gleExtractPixel_G_Float_00110f04;
        }
      }
      if (format == 0x1906) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_A_Byte_00110ee4;
        case 0x1401:
          return PTR__gleExtractPixel_A_Ubyte_00110ee0;
        case 0x1402:
          return PTR__gleExtractPixel_A_Short_00110edc;
        case 0x1403:
          return PTR__gleExtractPixel_A_Ushort_00110ed8;
        case 0x1404:
          return PTR__gleExtractPixel_A_Int_00110ed4;
        case 0x1405:
          return PTR__gleExtractPixel_A_Uint_00110ed0;
        default:
          return PTR__gleExtractPixel_A_Float_00110ecc;
        }
      }
      if (format == 0x1907) {
        if (type == 0x1404) {
          return PTR__gleExtractPixel_RGB_Int_00110f54;
        }
        if (type < 0x1405) {
          if (type == 0x1401) {
            return PTR__gleExtractPixel_RGB_Ubyte_00110f60;
          }
          if (type < 0x1402) {
            if (type == 0x1400) {
              return PTR__gleExtractPixel_RGB_Byte_00110f64;
            }
          }
          else {
            if (type == 0x1402) {
              return PTR__gleExtractPixel_RGB_Short_00110f5c;
            }
            if (type == 0x1403) {
              return PTR__gleExtractPixel_RGB_Ushort_00110f58;
            }
          }
        }
        else {
          if (type == 0x8032) {
            return PTR__gleExtractPixel_RGB_332_00110f48;
          }
          if (type < 0x8033) {
            if (type == 0x1405) {
              return PTR__gleExtractPixel_RGB_Uint_00110f50;
            }
            if (type == 0x1406) {
              return PTR__gleExtractPixel_RGB_Float_00110f4c;
            }
          }
          else {
            if (type == 0x8362) {
              return PTR__gleExtractPixel_RGB_233Rev_00110f44;
            }
            if (type == 0x8363) {
              return PTR__gleExtractPixel_RGB_565_00110f40;
            }
          }
        }
        return PTR__gleExtractPixel_RGB_565Rev_00110f3c;
      }
    }
  }
  else {
    if (format == 0x80e1) {
      if (type == 0x1406) {
        return PTR__gleExtractPixel_BGRA_EXT_Float_0011101c;
      }
      if (type < 0x1407) {
        if (type == 0x1402) {
          return PTR__gleExtractPixel_BGRA_EXT_Short_0011102c;
        }
        if (0x1402 < type) {
          if (type == 0x1404) {
            return PTR__gleExtractPixel_BGRA_EXT_Int_00111024;
          }
          if (0x1404 < type) {
            return PTR__gleExtractPixel_BGRA_EXT_Uint_00111020;
          }
          return PTR__gleExtractPixel_BGRA_EXT_Ushort_00111028;
        }
        if (type == 0x1400) {
          return PTR__gleExtractPixel_BGRA_EXT_Byte_00111034;
        }
        if (type == 0x1401) {
          return PTR__gleExtractPixel_BGRA_EXT_Ubyte_00111030;
        }
      }
      else {
        if (type == 0x8036) {
          return PTR__gleExtractPixel_BGRA_1010102_00111000;
        }
        if (type < 0x8037) {
          if (type == 0x8034) {
            return PTR__gleExtractPixel_BGRA_5551_00111010;
          }
          if (0x8034 < type) {
            return PTR__gleExtractPixel_BGRA_8888_00111008;
          }
          if (type == 0x8033) {
            return PTR__gleExtractPixel_BGRA_4444_00111018;
          }
        }
        else {
          if (type == 0x8366) {
            return PTR__gleExtractPixel_BGRA_1555Rev_0011100c;
          }
          if (type < 0x8367) {
            if (type == 0x8365) {
              return PTR__gleExtractPixel_BGRA_4444Rev_00111014;
            }
          }
          else if (type == 0x8367) {
            return PTR__gleExtractPixel_BGRA_8888Rev_00111004;
          }
        }
      }
      return PTR__gleExtractPixel_BGRA_2101010Rev_00110ffc;
    }
    if (format < 0x80e2) {
      if (format == 0x8000) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_ABGR_EXT_Byte_00111050;
        case 0x1401:
          return PTR__gleExtractPixel_ABGR_EXT_Ubyte_0011104c;
        case 0x1402:
          return PTR__gleExtractPixel_ABGR_EXT_Short_00111048;
        case 0x1403:
          return PTR__gleExtractPixel_ABGR_EXT_Ushort_00111044;
        case 0x1404:
          return PTR__gleExtractPixel_ABGR_EXT_Int_00111040;
        case 0x1405:
          return PTR__gleExtractPixel_ABGR_EXT_Uint_0011103c;
        default:
          return PTR__gleExtractPixel_ABGR_EXT_Float_00111038;
        }
      }
      if (format < 0x8001) {
        if (format == 0x1909) {
          switch(type) {
          case 0x1400:
            return PTR__gleExtractPixel_L_Byte_00110ec8;
          case 0x1401:
            return PTR__gleExtractPixel_L_Ubyte_00110ec4;
          case 0x1402:
            return PTR__gleExtractPixel_L_Short_00110ec0;
          case 0x1403:
            return PTR__gleExtractPixel_L_Ushort_00110ebc;
          case 0x1404:
            return PTR__gleExtractPixel_L_Int_00110eb8;
          case 0x1405:
            return PTR__gleExtractPixel_L_Uint_00110eb4;
          default:
            return PTR__gleExtractPixel_L_Float_00110eb0;
          }
        }
      }
      else if (format == 0x80e0) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_BGR_EXT_Byte_00110ff8;
        case 0x1401:
          return PTR__gleExtractPixel_BGR_EXT_Ubyte_00110ff4;
        case 0x1402:
          return PTR__gleExtractPixel_BGR_EXT_Short_00110ff0;
        case 0x1403:
          return PTR__gleExtractPixel_BGR_EXT_Ushort_00110fec;
        case 0x1404:
          return PTR__gleExtractPixel_BGR_EXT_Int_00110fe8;
        case 0x1405:
          return PTR__gleExtractPixel_BGR_EXT_Uint_00110fe4;
        default:
          return PTR__gleExtractPixel_BGR_EXT_Float_00110fe0;
        }
      }
    }
    else {
      if (format == 0x86f5) {
        switch(type) {
        case 0x1400:
          return PTR__gleExtractPixel_DSDT_Byte_00110fc0;
        case 0x1401:
          return PTR__gleExtractPixel_DSDT_Ubyte_00110fbc;
        case 0x1402:
          return PTR__gleExtractPixel_DSDT_Short_00110fb8;
        case 0x1403:
          return PTR__gleExtractPixel_DSDT_Ushort_00110fb4;
        case 0x1404:
          return PTR__gleExtractPixel_DSDT_Int_00110fb0;
        case 0x1405:
          return PTR__gleExtractPixel_DSDT_Uint_00110fac;
        default:
          return PTR__gleExtractPixel_DSDT_Float_00110fa8;
        }
      }
      if (format < 0x86f6) {
        if (format == 0x86f4) {
          switch(type) {
          case 0x1400:
            return PTR__gleExtractPixel_HILO_Byte_00110fdc;
          case 0x1401:
            return PTR__gleExtractPixel_HILO_Ubyte_00110fd8;
          case 0x1402:
            return PTR__gleExtractPixel_HILO_Short_00110fd4;
          case 0x1403:
            return PTR__gleExtractPixel_HILO_Ushort_00110fd0;
          case 0x1404:
            return PTR__gleExtractPixel_HILO_Int_00110fcc;
          case 0x1405:
            return PTR__gleExtractPixel_HILO_Uint_00110fc8;
          default:
            return PTR__gleExtractPixel_HILO_Float_00110fc4;
          }
        }
      }
      else {
        if (format == 0x86f6) {
          switch(type) {
          case 0x1400:
            return PTR__gleExtractPixel_DSDT_MAG_Byte_00110fa4;
          case 0x1401:
            return PTR__gleExtractPixel_DSDT_MAG_Ubyte_00110fa0;
          case 0x1402:
            return PTR__gleExtractPixel_DSDT_MAG_Short_00110f9c;
          case 0x1403:
            return PTR__gleExtractPixel_DSDT_MAG_Ushort_00110f98;
          case 0x1404:
            return PTR__gleExtractPixel_DSDT_MAG_Int_00110f94;
          case 0x1405:
            return PTR__gleExtractPixel_DSDT_MAG_Uint_00110f90;
          default:
            return PTR__gleExtractPixel_DSDT_MAG_Float_00110f8c;
          }
        }
        if (format == 0x86f7) {
          if (type == 0x1403) {
            return PTR__gleExtractPixel_DSDT_MAG_VIB_Ushort_00110f74;
          }
          if (type < 0x1404) {
            if (type == 0x1401) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Ubyte_00110f7c;
            }
            if (0x1401 < type) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Short_00110f78;
            }
            if (type == 0x1400) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Byte_00110f80;
            }
          }
          else {
            if (type == 0x1405) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Uint_00110f6c;
            }
            if (type < 0x1405) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_Int_00110f70;
            }
            if (type == 0x86da) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_S8_S8_8_8_00110f88;
            }
            if (type == 0x86db) {
              return PTR__gleExtractPixel_DSDT_MAG_VIB_8_8_S8_S8_Rev_00110f84;
            }
          }
          return PTR__gleExtractPixel_DSDT_MAG_VIB_Float_00110f68;
        }
      }
    }
  }
  switch(type) {
  case 0x1400:
    return PTR__gleExtractPixel_LA_Byte_00110eac;
  case 0x1401:
    return PTR__gleExtractPixel_LA_Ubyte_00110ea8;
  case 0x1402:
    return PTR__gleExtractPixel_LA_Short_00110ea4;
  case 0x1403:
    return PTR__gleExtractPixel_LA_Ushort_00110ea0;
  case 0x1404:
    return PTR__gleExtractPixel_LA_Int_00110e9c;
  case 0x1405:
    return PTR__gleExtractPixel_LA_Uint_00110e98;
  default:
    return PTR__gleExtractPixel_LA_Float_00110e94;
  }
}

/* _gleSelectModifyPixelFunc @ 0x2efd0 (476 bytes) */
int _gleSelectModifyPixelFunc(glContext, format)
  int glContext;
  uint format;
{
  bool formatIsLuminanceAlphaThenBGRA;
  int isIndexFormat;
  undefined *modifyPixelFunc;
  
  isIndexFormat = _gleIsIndex(format);
  if (isIndexFormat == 0) {
    if (format == 0x1902) {
      modifyPixelFunc = (undefined *)0x0;
      if ((*(uint *)(glContext + 0x3414) & 0x3000) != 0) {
        modifyPixelFunc = PTR__gleModifyPixelDepth_00111200;
      }
    }
    else if (format == 0x86f4) {
      modifyPixelFunc = (undefined *)0x0;
      if ((*(uint *)(glContext + 0x3418) & 0xf) != 0) {
        modifyPixelFunc = PTR__gleModifyPixelHILO_001111fc;
      }
    }
    else if ((format - 0x86f5 < 2) || (format == 0x86dc)) {
      modifyPixelFunc = (undefined *)0x0;
      if ((*(uint *)(glContext + 0x3418) & 0xff0) != 0) {
        modifyPixelFunc = PTR__gleModifyPixelDSDTMagVib_001111f8;
      }
    }
    else {
      modifyPixelFunc = (undefined *)0x0;
      if (((*(uint *)(glContext + 0x3414) & 0xff1) != 0) &&
         (modifyPixelFunc = PTR__gleModifyPixelRGBA_001111f4, format != 0x1908)) {
        modifyPixelFunc = PTR__gleModifyPixelA_001111e0;
        if (format < 0x1909) {
          if (format == 0x1904) {
            return PTR__gleModifyPixelG_001111e8;
          }
          if (format < 0x1905) {
            if (format == 0x1903) {
              return PTR__gleModifyPixelR_001111ec;
            }
          }
          else {
            if (format == 0x1905) {
              return PTR__gleModifyPixelB_001111e4;
            }
            if (format == 0x1907) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
          }
        }
        else {
          if (format == 0x8000) {
            return PTR__gleModifyPixelRGBA_001111f4;
          }
          if (format < 0x8001) {
            if (format == 0x1909) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
            formatIsLuminanceAlphaThenBGRA = format == 0x190a;
          }
          else {
            if (format == 0x80e0) {
              return PTR__gleModifyPixelRGB_001111f0;
            }
            formatIsLuminanceAlphaThenBGRA = format == 0x80e1;
          }
          if (formatIsLuminanceAlphaThenBGRA) {
            return PTR__gleModifyPixelRGBA_001111f4;
          }
        }
      }
    }
  }
  else {
    modifyPixelFunc = PTR__gleModifyPixelRGBAIndex_00111208;
    if ((format != 0x1900) && (modifyPixelFunc = (undefined *)0x0, (*(uint *)(glContext + 0x3414) & 0xe) != 0)
       ) {
      modifyPixelFunc = PTR__gleModifyPixelStencil_00111204;
    }
  }
  return modifyPixelFunc;
}

