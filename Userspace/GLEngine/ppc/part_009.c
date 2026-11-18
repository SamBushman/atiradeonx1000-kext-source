#include "decls.h"

/* _glFinish_Exec @ 0x555d4 (724 bytes) */
void _glFinish_Exec(int glContext,double forwardedFloatArg1ThenCalleeResult,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  uint loopIndex3;
  int loopIndex2;
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
  int rendererRecordCursor;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      forwardedFloatArg1ThenCalleeResult = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1ThenCalleeResult,forwardedFloatArg2,forwardedFloatArg3,
                   forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00055708:
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
          goto LAB_00055708;
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
              goto LAB_0005580c;
            }
          }
        }
        else {
          _gleSwitchToNonRevertRenderer(glContext);
        }
        loopIndex2 = 0;
        do {
          loopIndex2 = loopIndex2 + 1;
          *changeWordCursor = 0;
          changeWordCursor = changeWordCursor + 1;
        } while (loopIndex2 < 0x13);
      }
    }
    loopIndex3 = 0;
    (**(code **)(glContext + 0x46f0))(*(undefined4 *)(glContext + 0x4688));
    if (*(char *)(glContext + 0x85a4) != '\0') {
      rendererRecordCursor = glContext + 0x10000;
      do {
        if (loopIndex3 != *(byte *)(glContext + 0x85a8)) {
          (**(code **)(*(int *)(rendererRecordCursor + -0x777c) + 0x178))(*(undefined4 *)(rendererRecordCursor + -0x7a54));
        }
        loopIndex3 = loopIndex3 + 1;
        rendererRecordCursor = rendererRecordCursor + 0x2e0;
      } while ((int)loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0005580c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glFrontFace_Exec @ 0x558a8 (76 bytes) */
void _glFrontFace_Exec(glContext, mode)
  int glContext;
  int mode;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((1 < mode - 0x900U) && (*(int *)(glContext + 0x7574) == 0)) {
      *(undefined4 *)(glContext + 0x7574) = 0x500;
    }
    *(short *)(glContext + 0x34d4) = (short)mode;
    _gleUpdatePolyMode(glContext);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gliTerminateLibrary @ 0x558f4 (40 bytes) */
void _gliTerminateLibrary()
{
  ((int (*)())_gliDestroyAllContexts)();
  ((void (*)())_glepPluginDisconnectAll)();
  return;
}

/* _gliDestroyAllContexts @ 0x5591c (92 bytes) */
int _gliDestroyAllContexts()
{
  int glContext;
  int nextContext;
  
  glContext = _gl_list;
  while (glContext != 0) {
    nextContext = *(int *)(glContext + 0x85a0);
    _gliDestroyContext(glContext);
    glContext = nextContext;
  }
  _gl_list = 0;
  return 0;
}

/* _glepPluginDisconnectAll @ 0x55978 (100 bytes) */
void _glepPluginDisconnectAll()
{
  int *plugin;
  
  plugin = _glep_plugin_head;
  if (_glep_plugin_head != (int *)0x0) {
    do {
      ((void (*)())_glepPluginDisconnect)(plugin);
      plugin = (int *)*plugin;
    } while (plugin != (int *)0x0);
    ((void (*)())_glepUnloadRenderers)();
    return;
  }
  return;
}

/* _glepPluginDisconnect @ 0x559dc (140 bytes) */
void _glepPluginDisconnect(plugin)
  int plugin;
{
  int terminateSymbol;
  code *a0;
  
  if (*(int *)(plugin + 0x108) != 0) {
    terminateSymbol = _NSLookupSymbolInModule(*(undefined4 *)(plugin + 0x10c),"_gldTerminateLibrary");
    if ((terminateSymbol != 0) && (a0 = (code *)_NSAddressOfSymbol(terminateSymbol), a0 != (code *)0x0)) {
      (*a0)(a0);
    }
    _NSUnLinkModule(*(undefined4 *)(plugin + 0x10c),0);
    *(undefined4 *)(plugin + 0x10c) = 0;
    _NSDestroyObjectFileImage(*(undefined4 *)(plugin + 0x108));
    *(undefined4 *)(plugin + 0x108) = 0;
  }
  return;
}

/* _glepUnloadRenderers @ 0x55a68 (116 bytes) */
void _glepUnloadRenderers()
{
  int *pluginCursor;
  undefined4 *ioData;
  int nextPlugin;
  
  pluginCursor = (int *)_glep_plugin_head;
  ioData = (undefined4 *)PTR__gle_io_data_00112434;
  while (PTR__gle_io_data_00112434 = (undefined *)ioData, pluginCursor != (int *)0x0) {
    nextPlugin = *pluginCursor;
    _free(pluginCursor);
    pluginCursor = (int *)nextPlugin;
    ioData = (undefined4 *)PTR__gle_io_data_00112434;
  }
  _glep_plugin_head = 0;
  ioData[4] = 0;
  *ioData = 0;
  ioData[1] = 0;
  ioData[2] = 0;
  ioData[3] = 0;
  return;
}

/* _glTexCoord3f_Exec @ 0x55adc (36 bytes) */
void _glTexCoord3f_Exec(int glContext,float sCoord,float tCoord,float rCoord)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
  *(float *)(glContext + 0x124) = (float)tCoord;
  *(float *)(glContext + 0x128) = (float)rCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  return;
}

/* _glGetTexImage_Exec @ 0x55b00 (1268 bytes) */
void _glGetTexImage_Exec(glContext, target, level, format, type, pixels)
  int glContext;
  int target;
  uint level;
  uint format;
  uint type;
  int pixels;
{
  int loopIndex;
  undefined4 glErrorCode;
  bool formatMatchesType;
  byte levelFlags;
  ushort levelHeight;
  undefined4 pixelOpFlags;
  short storedFormat;
  int levelRecord;
  int textureObject;
  int rowBytes;
  int srcSliceOffset;
  int requiredBufferSize;
  int dstSliceOffset;
  int elementSize;
  undefined4 *dstConvertDescPtrA;
  undefined4 *dstConvertDescPtrB;
  uint requiredFormat;
  uint glContextByte31c8;
  uint *forwardedArg7;
  int *forwardedArg8;
  int pixelPackBuffer;
  uint faceIndexThenHeight;
  int packBufferSize;
  double bytesPerElement;
  int srcImagePtr;
  int srcRowBytes;
  undefined4 srcConvertDescA;
  undefined4 srcConvertDescB;
  int dstImagePtr;
  uint *dstRowBytes;
  undefined4 dstConvertDescA;
  undefined4 dstConvertDescB;
  undefined4 unitCount;
  uint copyFlags;
  undefined4 dstPixelOpFlags;
  uint imageWidth;
  uint imageHeight;
  undefined1 processReserved;
  uint *packedRowBytes;
  undefined1 rowPadding [4];
  uint imageBytes;
  undefined1 imagePadding [4];
  uint packPixelBytes;
  int packOffset;
  undefined4 srcConvertDescAOut;
  undefined4 srcConvertDescBOut;
  undefined4 dstConvertDescAOut;
  undefined4 dstConvertDescBOut [3];
  
  faceIndexThenHeight = target - 0x8515;
  textureObject = _gleLookUpNonProxyTexture(glContext,target);
  if (5 < faceIndexThenHeight) {
    faceIndexThenHeight = 0;
  }
  levelRecord = textureObject + faceIndexThenHeight * 0x168 + level * 0x18;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00055d40;
  if (textureObject == 0) goto LAB_00055c7c;
  if (0xe < level) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_00055d50;
  }
  if (type < 0x8037) {
    if (0x8032 < type) {
LAB_00055c54:
      if (format != 0x1908) {
        requiredFormat = 0x80e1;
        goto LAB_00055c70;
      }
      goto LAB_00055c94;
    }
    if (type != 0x140b) {
      if (type < 0x140c) {
        if (type - 0x1400 < 7) goto LAB_00055c00;
      }
      else if (type == 0x8032) goto LAB_00055c4c;
LAB_00055c7c:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00055d50;
    }
LAB_00055c00:
    if (format < 0x190b) {
      if (0x1901 < format) goto LAB_00055c94;
      if (format != 0x1900) goto LAB_00055d40;
      goto LAB_00055c98;
    }
    if ((format == 0x8000) || ((0x7fff < format && (format - 0x80e0 < 2)))) goto LAB_00055c94;
  }
  else {
    if (type < 0x8369) {
      if (0x8364 < type) goto LAB_00055c54;
      if (type < 0x8362) goto LAB_00055c7c;
LAB_00055c4c:
      formatMatchesType = format == 0x1907;
    }
    else {
      if (1 < type - 0x85ba) goto LAB_00055c7c;
      requiredFormat = 0x85b9;
LAB_00055c70:
      formatMatchesType = format == requiredFormat;
    }
    if (!formatMatchesType) goto LAB_00055d40;
LAB_00055c94:
    if (format == 0x1900) {
LAB_00055c98:
      storedFormat = *(short *)(levelRecord + 0xd4);
      if (storedFormat != 0x1900) goto LAB_00055d40;
    }
    else {
      storedFormat = *(short *)(levelRecord + 0xd4);
    }
    if ((format == 0x1902) == (storedFormat == 0x1902)) {
      pixelPackBuffer = *(int *)(glContext + 0x4a68);
      if (pixelPackBuffer == 0) {
LAB_00055d78:
        levelFlags = *(byte *)(levelRecord + 0xcf);
        if ((levelFlags & 0x20) == 0) {
          return;
        }
        if ((((int)level < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
            ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)level)) || ((levelFlags & 0x40) == 0)) {
          if ((levelFlags & 0x10) == 0) {
            return;
          }
        }
        else {
          ((void (*)())_gleUploadPluginTextureLevel)(glContext,textureObject,levelRecord + 0xc4,faceIndexThenHeight,level,(uint)*(byte *)(glContext + 0x85a8));
        }
        faceIndexThenHeight = (uint)*(ushort *)(levelRecord + 0xca);
        forwardedArg7 = &packPixelBytes;
        forwardedArg8 = &packOffset;
        _glePixelPackSettings
                  (glContext,format,type,(uint)*(ushort *)(levelRecord + 200),faceIndexThenHeight,glContext + 0x31b0,
                   forwardedArg7,forwardedArg8,&packedRowBytes,rowPadding,&imageBytes,imagePadding);
        if (((((*(byte *)(levelRecord + 0xcf) & 1) == 0) ||
             (pixels + packOffset != *(int *)(levelRecord + 0xd8))) ||
            ((format != *(ushort *)(levelRecord + 0xd4) ||
             ((type != *(ushort *)(levelRecord + 0xd6) ||
              (forwardedArg7 = packedRowBytes, (uint)packedRowBytes / packPixelBytes != (uint)*(ushort *)(levelRecord + 0xd0)
              )))))) || (imageBytes / (uint)packedRowBytes != (uint)*(ushort *)(levelRecord + 0xd2))) {
          glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
        }
        else {
          glContextByte31c8 = (uint)*(byte *)(glContext + 0x31c8);
          if (glContextByte31c8 == 0) {
            return;
          }
        }
        copyFlags = 0x60000;
        if ((*(short *)(textureObject + 0x26) == 0x1907) &&
           ((*(short *)(levelRecord + 0xd4) == 0x1908 || (*(short *)(levelRecord + 0xd4) == -0x7f1f)))) {
          copyFlags = 0x68000;
        }
        if (glContextByte31c8 != 0) {
          copyFlags = copyFlags | 2;
        }
        loopIndex = 0;
        rowBytes = _gleRowBytes((uint)*(ushort *)(levelRecord + 0xd4),(uint)*(ushort *)(levelRecord + 0xd6),
                             (uint)*(ushort *)(levelRecord + 0xd0));
        _glgConvertType((uint)*(ushort *)(levelRecord + 0xd4),(uint)*(ushort *)(levelRecord + 0xd6),&srcConvertDescAOut,
                        &srcConvertDescBOut,faceIndexThenHeight,glContextByte31c8,forwardedArg7,forwardedArg8);
        dstConvertDescPtrA = &dstConvertDescAOut;
        dstConvertDescPtrB = dstConvertDescBOut;
        _glgConvertType(format,type,dstConvertDescPtrA,dstConvertDescPtrB,faceIndexThenHeight,glContextByte31c8,forwardedArg7,forwardedArg8);
        levelHeight = *(ushort *)(levelRecord + 0xca);
        pixelOpFlags = 0x68002;
        srcConvertDescA = srcConvertDescAOut;
        srcConvertDescB = srcConvertDescBOut;
        dstRowBytes = packedRowBytes;
        dstConvertDescA = dstConvertDescAOut;
        dstConvertDescB = dstConvertDescBOut[0];
        unitCount = 2;
        dstPixelOpFlags = 0x68002;
        imageWidth = (uint)*(ushort *)(levelRecord + 200);
        imageHeight = (uint)*(ushort *)(levelRecord + 0xca);
        processReserved = 0;
        if (*(short *)(levelRecord + 0xcc) == 0) {
          return;
        }
        dstSliceOffset = 0;
        srcSliceOffset = 0;
        srcRowBytes = rowBytes;
        do {
          loopIndex = loopIndex + 1;
          dstImagePtr = pixels + packOffset + dstSliceOffset;
          srcImagePtr = *(int *)(levelRecord + 0xd8) + srcSliceOffset;
          srcSliceOffset = srcSliceOffset + rowBytes * (uint)levelHeight;
          _glgProcessPixels(glContext + 0x31a8,&srcImagePtr,dstConvertDescPtrA,dstConvertDescPtrB,faceIndexThenHeight,glContextByte31c8,pixelOpFlags,forwardedArg8)
          ;
          dstSliceOffset = dstSliceOffset + imageBytes;
        } while (loopIndex < (int)(uint)*(ushort *)(levelRecord + 0xcc));
        return;
      }
      requiredBufferSize = _gleOffsetLimitImage3D
                        (glContext + 0x31b0,(uint)*(ushort *)(levelRecord + 200),
                         (uint)*(ushort *)(levelRecord + 0xca),(uint)*(ushort *)(levelRecord + 0xcc),format,
                         type,pixels);
      packBufferSize = *(int *)(pixelPackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      elementSize = (int)bytesPerElement;
      if (requiredBufferSize <= packBufferSize) {
        if (elementSize == 0) {
          elementSize = _glePixelBytes(format,type);
        }
        if (pixels == (pixels / elementSize) * elementSize) {
          if (*(int *)(pixelPackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
          }
          pixels = pixels + *(int *)(pixelPackBuffer + 0x30);
          goto LAB_00055d78;
        }
      }
    }
  }
LAB_00055d40:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00055d50:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleUploadPluginTextureLevel @ 0x55ff4 (420 bytes) */
void _gleUploadPluginTextureLevel(glContext, param_2, param_3, forwardedArg4, level, param_6)
  int glContext;
  int param_2;
  int param_3;
  undefined4 forwardedArg4;
  undefined4 level;
  int param_6;
{
  ushort uVar1;
  int iVar2;
  undefined4 glContextWord31b0;
  undefined4 glContextWord31c8;
  undefined4 glContextWord31c4;
  undefined4 glContextWord31c0;
  undefined4 glContextWord31bc;
  undefined4 a5;
  int iVar8;
  undefined4 a7;
  
  if ((*(byte *)(param_3 + 0xb) & 1) == 0) {
    iVar8 = *(int *)(param_3 + 0x14);
    if (iVar8 == 0) {
      iVar8 = _gleAllocateTextureLevel(glContext,param_2,param_3);
      if (iVar8 == 0) {
        return;
      }
      iVar8 = *(int *)(param_3 + 0x14);
    }
    iVar2 = param_6 * 0x2e0 + glContext;
    (**(code **)(*(int *)(iVar2 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar2 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),forwardedArg4,
               level,iVar8);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
  }
  else {
    glContextWord31b0 = *(undefined4 *)(glContext + 0x31b0);
    *(uint *)(glContext + 0x31b0) = (uint)*(ushort *)(param_3 + 0xc);
    uVar1 = *(ushort *)(param_3 + 0xe);
    iVar8 = param_6 * 0x2e0 + glContext;
    glContextWord31bc = *(undefined4 *)(glContext + 0x31bc);
    glContextWord31c0 = *(undefined4 *)(glContext + 0x31c0);
    glContextWord31c4 = *(undefined4 *)(glContext + 0x31c4);
    a7 = *(undefined4 *)(0x31b4 + glContext);
    a5 = *(undefined4 *)(glContext + 0x31b8);
    glContextWord31c8 = *(undefined4 *)(glContext + 0x31c8);
    *(undefined4 *)(glContext + 0x31c4) = 1;
    *(uint *)(0x31b4 + glContext) = (uint)uVar1;
    *(undefined4 *)(glContext + 0x31c0) = 0;
    *(undefined4 *)(glContext + 0x31b8) = 0;
    *(undefined4 *)(glContext + 0x31bc) = 0;
    (**(code **)(*(int *)(iVar8 + 0x8884) + 0x160))
              (*(undefined4 *)(iVar8 + 0x85ac),*(undefined4 *)(param_2 + param_6 * 4),forwardedArg4,
               level,*(undefined4 *)(param_3 + 0x14),a5,iVar8 + 0x10000,a7);
    if ((*(byte *)(param_3 + 0xb) & 0x80) == 0) {
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) | 0x10;
      *(byte *)(param_3 + 0xb) = *(byte *)(param_3 + 0xb) & 0xbf;
    }
    *(undefined4 *)(glContext + 0x31c8) = glContextWord31c8;
    *(undefined4 *)(glContext + 0x31b0) = glContextWord31b0;
    *(undefined4 *)(0x31b4 + glContext) = a7;
    *(undefined4 *)(glContext + 0x31b8) = a5;
    *(undefined4 *)(glContext + 0x31bc) = glContextWord31bc;
    *(undefined4 *)(glContext + 0x31c0) = glContextWord31c0;
    *(undefined4 *)(glContext + 0x31c4) = glContextWord31c4;
  }
  return;
}

/* _gleFlushPrimitiveTCLFunc @ 0x56198 (760 bytes) */
void _gleFlushPrimitiveTCLFunc(glContext)
  int glContext;
{
  int loopIndex9;
  int loopIndex8;
  int loopIndex7;
  int loopIndex6;
  int loopIndex5;
  int loopIndex4;
  int loopIndex3;
  int loopIndex2;
  int loopIndex;
  int carryOffset;
  int glContextWord4858;
  int glContextPtr4868;
  int iVar2;
  int glContextPtr4854;
  int glContextPtr4858;
  int iVar4;
  int glContextWord48582;
  int iVar5;
  uint qwordsLeft;
  undefined8 carriedVertices [64];
  int bufferVertexCount [5];
  
  iVar5 = (int)*(short *)(glContext + 0x487c);
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  case 2:
    if (*(char *)(glContext + 0x4a18) == '\0') {
      loopIndex8 = 0;
      glContextPtr4854 = *(int *)(glContext + 0x4854);
      glContextPtr4868 = *(int *)(glContext + 0x4868);
      if (0 < iVar5) {
        qwordsLeft = iVar5 + 7U >> 3;
        do {
          *(undefined8 *)(glContextPtr4854 + -0x100 + loopIndex8) = *(undefined8 *)(glContextPtr4868 + loopIndex8);
          loopIndex8 = loopIndex8 + 8;
          qwordsLeft = qwordsLeft - 1;
        } while (qwordsLeft != 0);
      }
    }
  case 3:
    loopIndex3 = 0;
    glContextWord4858 = *(int *)(glContext + 0x4858);
    *(undefined1 *)(glContext + 0x4a18) = 1;
    if (0 < iVar5) {
      qwordsLeft = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex3) = *(undefined8 *)((glContextWord4858 - iVar5) + loopIndex3);
        loopIndex3 = loopIndex3 + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
    break;
  case 5:
  case 8:
    iVar2 = iVar5 * 2;
    loopIndex9 = 0;
    glContextPtr4858 = *(int *)(glContext + 0x4858);
    carryOffset = iVar5 * -2;
    iVar5 = iVar2;
    if (0 < iVar2) {
      qwordsLeft = iVar2 + 7U >> 3;
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex9) = *(undefined8 *)(glContextPtr4858 + carryOffset + loopIndex9);
        loopIndex9 = loopIndex9 + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
    break;
  case 6:
    loopIndex4 = 0;
    glContextWord48582 = *(int *)(glContext + 0x4858);
    glContextPtr4868 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex4) = *(undefined8 *)(glContextPtr4868 + loopIndex4);
        loopIndex4 = loopIndex4 + 8;
      } while (loopIndex4 < iVar5);
    }
    loopIndex5 = 0;
    if (0 < iVar5) {
      qwordsLeft = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex5 + iVar5) = *(undefined8 *)((glContextWord48582 - iVar5) + loopIndex5);
        loopIndex5 = loopIndex5 + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
    break;
  case 9:
    loopIndex6 = 0;
    iVar4 = *(int *)(glContext + 0x4858);
    glContextPtr4868 = *(int *)(glContext + 0x4868);
    if (0 < iVar5) {
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex6) = *(undefined8 *)(glContextPtr4868 + loopIndex6);
        loopIndex6 = loopIndex6 + 8;
      } while (loopIndex6 < iVar5);
    }
    loopIndex7 = 0;
    iVar4 = iVar4 - iVar5;
    if (0 < iVar5) {
      qwordsLeft = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)((int)carriedVertices + loopIndex7 + iVar5) = *(undefined8 *)(iVar4 + loopIndex7);
        loopIndex7 = loopIndex7 + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)(iVar4 + *(short *)(glContext + 0x487e)) = 0;
    }
  }
  (**(code **)(glContext + 0x4a08))(glContext);
  bufferVertexCount[0] = *(int *)(glContext + 0x4a14);
  iVar2 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),bufferVertexCount);
  *(int *)(glContext + 0x4868) = iVar2;
  *(int *)(glContext + 0x485c) = iVar2 + *(short *)(glContext + 0x487c) * bufferVertexCount[0];
  switch(*(undefined2 *)(glContext + 0x4a10)) {
  default:
    goto switchD_00056410_caseD_0;
  case 2:
  case 3:
    loopIndex = 0;
    if (0 < iVar5) {
      qwordsLeft = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + loopIndex) = *(undefined8 *)((int)carriedVertices + loopIndex);
        loopIndex = loopIndex + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
    break;
  case 9:
    if ((*(short *)(glContext + 0x34d2) == 0x1b01) || (*(short *)(glContext + 0x34d0) == 0x1b01)) {
      *(undefined1 *)((int)carriedVertices + (int)*(short *)(glContext + 0x487e)) = 0;
    }
  case 6:
    iVar5 = iVar5 << 1;
  case 5:
  case 8:
    loopIndex2 = 0;
    if (0 < iVar5) {
      qwordsLeft = iVar5 + 7U >> 3;
      do {
        *(undefined8 *)(iVar2 + loopIndex2) = *(undefined8 *)((int)carriedVertices + loopIndex2);
        loopIndex2 = loopIndex2 + 8;
        qwordsLeft = qwordsLeft - 1;
      } while (qwordsLeft != 0);
    }
  }
  iVar2 = iVar2 + iVar5;
switchD_00056410_caseD_0:
  *(int *)(glContext + 0x4858) = iVar2;
  return;
}

/* _glMultMatrixf_Exec @ 0x564e0 (140 bytes) */
int _glMultMatrixf_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  int copyMatrixResultOrGlContext;
  undefined1 productMatrix [72];
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    ((void (*)())_gleMultMatrixf)(*(undefined4 *)(glContext + 0x4fec),m,productMatrix);
    copyMatrixResultOrGlContext = _gleCopyMatrix(productMatrix,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else {
    copyMatrixResultOrGlContext = glContext;
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return copyMatrixResultOrGlContext;
}

/* _gleMultMatrixf @ 0x5656c (836 bytes) */
void _gleMultMatrixf(leftMatrix, m, product)
  float *leftMatrix;
  float *m;
  float *product;
{
  *product = leftMatrix[0xc] * m[3] +
             (leftMatrix[8] * m[2] + (*leftMatrix * *m + leftMatrix[4] * m[1]));
  product[4] = leftMatrix[0xc] * m[7] +
               (leftMatrix[8] * m[6] + (*leftMatrix * m[4] + leftMatrix[4] * m[5]));
  product[8] = leftMatrix[0xc] * m[0xb] +
               (leftMatrix[8] * m[10] + (*leftMatrix * m[8] + leftMatrix[4] * m[9]));
  product[0xc] = leftMatrix[0xc] * m[0xf] +
                 (leftMatrix[8] * m[0xe] + (*leftMatrix * m[0xc] + leftMatrix[4] * m[0xd]));
  product[1] = leftMatrix[0xd] * m[3] +
               (leftMatrix[9] * m[2] + (leftMatrix[1] * *m + leftMatrix[5] * m[1]));
  product[5] = leftMatrix[0xd] * m[7] +
               (leftMatrix[9] * m[6] + (leftMatrix[1] * m[4] + leftMatrix[5] * m[5]));
  product[9] = leftMatrix[0xd] * m[0xb] +
               (leftMatrix[9] * m[10] + (leftMatrix[1] * m[8] + leftMatrix[5] * m[9]));
  product[0xd] = leftMatrix[0xd] * m[0xf] +
                 (leftMatrix[9] * m[0xe] + (leftMatrix[1] * m[0xc] + leftMatrix[5] * m[0xd]));
  product[2] = leftMatrix[0xe] * m[3] +
               (leftMatrix[10] * m[2] + (leftMatrix[2] * *m + leftMatrix[6] * m[1]));
  product[6] = leftMatrix[0xe] * m[7] +
               (leftMatrix[10] * m[6] + (leftMatrix[2] * m[4] + leftMatrix[6] * m[5]));
  product[10] = leftMatrix[0xe] * m[0xb] +
                (leftMatrix[10] * m[10] + (leftMatrix[2] * m[8] + leftMatrix[6] * m[9]));
  product[0xe] = leftMatrix[0xe] * m[0xf] +
                 (leftMatrix[10] * m[0xe] + (leftMatrix[2] * m[0xc] + leftMatrix[6] * m[0xd]));
  product[3] = leftMatrix[0xf] * m[3] +
               (leftMatrix[0xb] * m[2] + (leftMatrix[3] * *m + leftMatrix[7] * m[1]));
  product[7] = leftMatrix[0xf] * m[7] +
               (leftMatrix[0xb] * m[6] + (leftMatrix[3] * m[4] + leftMatrix[7] * m[5]));
  product[0xb] = leftMatrix[0xf] * m[0xb] +
                 (leftMatrix[0xb] * m[10] + (leftMatrix[3] * m[8] + leftMatrix[7] * m[9]));
  product[0xf] = leftMatrix[0xf] * m[0xf] +
                 (leftMatrix[0xb] * m[0xe] + (leftMatrix[3] * m[0xc] + leftMatrix[7] * m[0xd]))
  ;
  return;
}

/* __dyld_func_lookup @ 0x568b0 (32 bytes) */
void __dyld_func_lookup()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
}

/* _glAccum_ListExec @ 0x568d0 (44 bytes) */
undefined4 _glAccum_ListExec(undefined4 glContext,undefined4 *recordedArgs,double unusedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glAccum_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])),forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 8;
}

/* _glAccum_Comp @ 0x568fc (92 bytes) */
undefined4 * _glAccum_Comp(undefined4 glContext,undefined4 op,float value)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glAccum_ListExec_00110004,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)value;
    *listRecord = op;
  }
  return listRecord;
}

/* _glAccum_Exec @ 0x56958 (748 bytes) */
void _glAccum_Exec(int glContext,int op,double value,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79IsZero;
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
  double f1AfterCall;
  double fparam_1_00;
  
  if ((-1 < *(short *)(glContext + 0x4a10)) || (*(int *)(*(int *)(glContext + 0x468c) + 0x44) < 1)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00056bd4;
  }
  if (4 < op - 0x100U) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00056bd4;
  }
  if ((op == 0x102) && (*(int *)(glContext + 0x4e1c) != 0x1c00)) {
    return;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  fparam_1_00 = value;
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00056c00;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1_00,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00056ad8:
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
      goto LAB_00056ad8;
    }
  }
  rendererInfoByte79IsZero = rendererInfoByte79 == '\0';
  if (rendererInfoByte79IsZero) {
    changeWord3 = changeWord3 & 0x17000000;
  }
  else {
    changeWord3 = changeWord3 & 0x17ffffff;
  }
  if (rendererInfoByte79IsZero) {
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
LAB_00056bd4:
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
LAB_00056c00:
                    
                    
  (**(int ( **)(int,int,double))(glContext + 0x4698))(*(undefined4 *)(glContext + 0x4688), op, value);
  return;
}

/* _glAccum_CompExec @ 0x56c44 (72 bytes) */
void _glAccum_CompExec(undefined4 glContext,undefined4 op,float value)
{
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 * (*)())_glAccum_Comp)(glContext,op,value);
  ((void (*)())_glAccum_Exec)(glContext,op,value,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glActiveTexture_ListExec @ 0x56c8c (40 bytes) */
int _glActiveTexture_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glActiveTexture_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glActiveTexture_Comp @ 0x56cb4 (76 bytes) */
int _glActiveTexture_Comp(glContext, texture)
  undefined4 glContext;
  undefined4 texture;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glActiveTexture_ListExec_00110008,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = texture;
  }
  return listRecord;
}

/* _glActiveTexture_CompExec @ 0x56d00 (56 bytes) */
void _glActiveTexture_CompExec(glContext, texture)
  undefined4 glContext;
  undefined4 texture;
{
  ((int (*)())_glActiveTexture_Comp)(glContext,texture);
  _glActiveTexture_Exec(glContext,texture);
  return;
}

/* _glAlphaFunc_ListExec @ 0x56d38 (44 bytes) */
int _glAlphaFunc_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glAlphaFunc_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])));
  return 8;
}

/* _glAlphaFunc_Comp @ 0x56d64 (92 bytes) */
undefined4 * _glAlphaFunc_Comp(undefined4 glContext,undefined4 func,float ref)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glAlphaFunc_ListExec_0011000c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)ref;
    *listRecord = func;
  }
  return listRecord;
}

/* _glAlphaFunc_CompExec @ 0x56dc0 (72 bytes) */
void _glAlphaFunc_CompExec(undefined4 glContext,undefined4 func,float ref)
{
  ((undefined4 * (*)())_glAlphaFunc_Comp)(glContext,func,ref);
  ((void (*)())_glAlphaFunc_Exec)(glContext,func,ref);
  return;
}

/* _glVertexArrayParameteriEXT_ListExec @ 0x56e08 (44 bytes) */
int _glVertexArrayParameteriEXT_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glVertexArrayParameteriEXT_Comp @ 0x56e34 (84 bytes) */
int _glVertexArrayParameteriEXT_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glVertexArrayParameteriEXT_ListExec_00110010,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glVertexArrayParameteriEXT_Exec @ 0x56e88 (344 bytes) */
void _glVertexArrayParameteriEXT_Exec(glContext, pname, param)
  int glContext;
  int pname;
  uint param;
{
  undefined4 glErrorCode;
  int clientState;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00056fc8;
  }
  if (pname != 0x851f) {
    if (pname == 0x897c) {
      *(char *)(clientState + 0x34c) = '\x01' - (param == 0);
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 4;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      return;
    }
    goto LAB_00056fb8;
  }
  if (param == 0x85bd) {
    *(undefined2 *)(clientState + 0x342) = 0x85b4;
    goto LAB_00056f58;
  }
  if ((int)param < 0x85be) {
    if (param == 0x85b4) {
LAB_00056f34:
      if (*(ushort *)(clientState + 0x342) != param) {
        _gleUpdateDrawArraysFuncs(glContext);
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
        *(short *)(clientState + 0x342) = (short)param;
      }
LAB_00056f58:
      *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
      *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 8;
      _gleModifyPluginVertexArray(glContext,clientState + 0x10);
      return;
    }
  }
  else if ((int)param < 0x85c0) goto LAB_00056f34;
LAB_00056fb8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00056fc8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glVertexArrayParameteriEXT_CompExec @ 0x56fe0 (64 bytes) */
void _glVertexArrayParameteriEXT_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glVertexArrayParameteriEXT_Comp)(glContext,pname,param);
  ((void (*)())_glVertexArrayParameteriEXT_Exec)(glContext,pname,param);
  return;
}

/* _glPushAttrib_ListExec @ 0x57020 (40 bytes) */
int _glPushAttrib_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glPushAttrib_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glPushAttrib_Comp @ 0x57048 (76 bytes) */
int _glPushAttrib_Comp(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glPushAttrib_ListExec_00110018,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mask;
  }
  return listRecord;
}

/* _glPushAttrib_CompExec @ 0x57094 (56 bytes) */
void _glPushAttrib_CompExec(glContext, mask)
  undefined4 glContext;
  undefined4 mask;
{
  ((int (*)())_glPushAttrib_Comp)(glContext,mask);
  _glPushAttrib_Exec(glContext,mask);
  return;
}

/* _glPopAttrib_ListExec @ 0x570cc (36 bytes) */
int _glPopAttrib_ListExec(glContext)
  undefined4 glContext;
{
  _glPopAttrib_Exec(glContext);
  return 0;
}

/* _glPopAttrib_Comp @ 0x570f0 (32 bytes) */
int _glPopAttrib_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glPopAttrib_ListExec_00110014,0);
  return listRecord;
}

/* _glPopAttrib_CompExec @ 0x57110 (48 bytes) */
void _glPopAttrib_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glPopAttrib_Comp)(glContext);
  _glPopAttrib_Exec(glContext);
  return;
}

/* _glPopClientAttrib_Exec @ 0x57140 (188 bytes) */
void _glPopClientAttrib_Exec(glContext)
  int glContext;
{
  undefined4 glErrorCode;
  int attribStackPointerThenElem;
  int nextElem;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < *(int *)(glContext + 0x5144)) {
      attribStackPointerThenElem = *(int *)(glContext + 0x5140);
      *(int *)(glContext + 0x5144) = *(int *)(glContext + 0x5144) + -1;
      *(int *)(glContext + 0x5140) = attribStackPointerThenElem + -4;
      attribStackPointerThenElem = *(int *)(attribStackPointerThenElem + -4);
      while (attribStackPointerThenElem != 0) {
        nextElem = *(int *)(attribStackPointerThenElem + 700);
        _gleRemoveClientAttribElem(glContext,attribStackPointerThenElem);
        attribStackPointerThenElem = nextElem;
      }
      _gleUpdateState(glContext);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x504;
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

/* _glPushClientAttrib_Exec @ 0x571fc (184 bytes) */
void _glPushClientAttrib_Exec(glContext, mask)
  int glContext;
  uint mask;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x5144) < 0x10) {
      **(undefined4 **)(glContext + 0x5140) = 0;
      if ((mask & 1) != 0) {
        _gleAddClientAttribElem(glContext,1);
      }
      if ((mask & 2) != 0) {
        _gleAddClientAttribElem(glContext,2);
      }
      *(int *)(glContext + 0x5140) = *(int *)(glContext + 0x5140) + 4;
      *(int *)(glContext + 0x5144) = *(int *)(glContext + 0x5144) + 1;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x503;
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

/* _glBegin_NoopExec @ 0x572b4 (668 bytes) */
void _glBegin_NoopExec(int glContext,undefined4 mode,double forwardedFloatArg1ThenCalleeResult,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
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
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00057518;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1ThenCalleeResult = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000574fc:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glBegin_Exec)(glContext,mode,forwardedFloatArg1ThenCalleeResult,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                    forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1ThenCalleeResult,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      forwardedFloatArg1ThenCalleeResult = forwardedFloatArg1ThenCalleeResult;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000573e8:
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
          forwardedFloatArg1ThenCalleeResult = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          forwardedFloatArg1ThenCalleeResult = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000573e8;
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
    if (noStateChangePending) goto LAB_000574fc;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      forwardedFloatArg1ThenCalleeResult = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000574e0:
      remaining = 0x13;
      do {
        *changeWordCursor = 0;
        changeWordCursor = changeWordCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000574fc;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (forwardedFloatArg1ThenCalleeResult = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000574e0;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    forwardedFloatArg1ThenCalleeResult = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000574e0;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_00057518:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBitmap_ListExec @ 0x57550 (976 bytes) */
int _glBitmap_ListExec(int glContext,uint *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  float bitmapWidth;
  float bitmapHeight;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int glContextPtr4854;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  int recordSize;
  float *a1;
  double f1AfterCall;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  a1 = (float *)(glContextPtr4854 + -0x200);
  recordSize = recordedArgs[6] + 0x1c;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return recordSize;
    }
    glErrorCode = 0x502;
    goto LAB_0005782c;
  }
  bitmapWidth = (float)((double)CONCAT44(0x43300000,*recordedArgs ^ 0x80000000) - DOUBLE_00108d58);
  if ((bitmapWidth < FLOAT_00108e50) ||
     (bitmapHeight = (float)((double)CONCAT44(0x43300000,recordedArgs[1] ^ 0x80000000) - DOUBLE_00108d58),
     bitmapHeight < FLOAT_00108e50)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return recordSize;
    }
    glErrorCode = 0x501;
    goto LAB_0005782c;
  }
  if (*(char *)(glContext + 0x2ef) == '\0') {
    return recordSize;
  }
  if (*(int *)(glContext + 0x4e1c) != 0x1c00) {
    if (*(int *)(glContext + 0x4e1c) == 0x1c01) {
      *(undefined4 *)(glContextPtr4854 + -0x200) = *(undefined4 *)(glContext + 0x2e0);
      *(undefined4 *)(glContextPtr4854 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
      *(undefined4 *)(glContextPtr4854 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
      _gleFeedbackBitmap(glContext,a1);
    }
    goto LAB_000578e8;
  }
  if ((!(FLOAT_00108e50 < bitmapWidth)) || (!(FLOAT_00108e50 < bitmapHeight))) goto LAB_000578e8;
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00057730:
      changeWord3 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        dirtyWord = *srcCursor;
        srcCursor = srcCursor + 1;
        if (dirtyWord != 0) {
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
        goto LAB_00057730;
      }
    }
    rendererInfoByte79Zero = rendererInfoByte79 == '\0';
    if (rendererInfoByte79Zero) {
      changeWord3 = changeWord3 & 0x17000000;
    }
    else {
      changeWord3 = changeWord3 & 0x17ffffff;
    }
    if (rendererInfoByte79Zero) {
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
              return recordSize;
            }
            glErrorCode = 0x506;
LAB_0005782c:
            *(undefined4 *)(glContext + 0x7574) = glErrorCode;
            return recordSize;
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
  }
  *a1 = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) + *(float *)(glContext + 0x4a48);
  *(float *)(glContextPtr4854 + -0x1fc) =
       *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) + *(float *)(glContext + 0x4a50);
  *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
  (**(code **)(glContext + 0x46ac))
            (*(undefined4 *)(glContext + 0x4688),a1,*recordedArgs,recordedArgs[1],incomingR7,incomingR8,recordedArgs + 7,1,
             (double)GH_U2F((unsigned int)(recordedArgs[2])),(double)GH_U2F((unsigned int)(recordedArgs[3])));
LAB_000578e8:
  *(float *)(glContext + 0x2e0) = *(float *)(glContext + 0x2e0) + GH_U2F((unsigned int)(recordedArgs[4]));
  *(float *)(glContext + 0x2e4) = *(float *)(glContext + 0x2e4) + GH_U2F((unsigned int)(recordedArgs[5]));
  return recordSize;
}

/* _glBitmap_Comp @ 0x57920 (444 bytes) */
void _glBitmap_Comp(int glContext,int width,int height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,int bitmap,float xorig,float yorig,float xmove,float ymove)
{
  uint paddedBitmapBytes;
  int imageEndOffset;
  int *listRecord;
  int bitmapBytes;
  int pixelUnpackBuffer;
  
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  bitmapBytes = (width + 7 >> 3) * height;
  paddedBitmapBytes = bitmapBytes + 3U & 0xfffffffc;
  if (pixelUnpackBuffer != 0) {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,0,0x1a00,bitmap);
    if (*(int *)(pixelUnpackBuffer + 0x38) < imageEndOffset) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
      goto LAB_00057ad0;
    }
    if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
      _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
    }
    bitmap = bitmap + *(int *)(pixelUnpackBuffer + 0x30);
  }
  listRecord = (int *)_gleAddListItem(glContext,PTR__glBitmap_ListExec_00110020,paddedBitmapBytes + 0x1c);
  if (listRecord != (int *)0x0) {
    listRecord[2] = (int)GH_F2U((float)xorig);
    listRecord[3] = (int)GH_F2U((float)yorig);
    listRecord[4] = (int)GH_F2U((float)xmove);
    listRecord[5] = (int)GH_F2U((float)ymove);
    listRecord[6] = paddedBitmapBytes;
    *listRecord = width;
    listRecord[1] = height;
    if (bitmapBytes != 0) {
      if ((((*(char *)(glContext + 0x31e5) == '\0') && (*(int *)(glContext + 0x31cc) == 0)) &&
          (*(int *)(glContext + 0x31d4) == 0)) &&
         ((*(int *)(glContext + 0x31e0) == 1 && ((*(uint *)(glContext + 0x31d8) & 7) == 0)))) {
        _gleCopy(bitmap + ((int)*(uint *)(glContext + 0x31d8) >> 3),listRecord + 7,bitmapBytes,1,0,0);
        return;
      }
      _gleFillImage(glContext,width,height,1,0x1900,0x1a00,bitmap,listRecord + 7);
      return;
    }
  }
LAB_00057ad0:
  return;
}

/* _glBitmap_CompExec @ 0x57adc (120 bytes) */
void _glBitmap_CompExec(undefined4 glContext,undefined4 width,undefined4 height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,undefined4 bitmap,float xorig,float yorig,float xmove,float ymove)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glBitmap_Comp)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,ymoveShadow,bitmap,xorig,yorig,
                 xmove,ymove);
  ((void (*)())_glBitmap_Exec)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,ymoveShadow,bitmap,xorig,yorig,
                 xmove,ymove,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glBitmap_NoopExec @ 0x57b54 (696 bytes) */
void _glBitmap_NoopExec(int glContext,undefined4 width,undefined4 height,undefined4 xorigShadow,undefined4 yorigShadow,undefined4 xmoveShadow,undefined4 ymoveShadow,undefined4 bitmap,double xorig,double yorig,float xmove,float ymove,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79IsZero;
  bool noStateChangePending;
  char rendererInfoByte79;
  int dirtyBitArrayWord;
  int *srcCursor;
  int framebufferObject;
  undefined4 savedHeight;
  uint matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterCall;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit = *(uint *)(glContext + 0x50ac);
  savedHeight = height;
  fparam_1_00 = xorig;
  fparam_2_00 = yorig;
  fparam_3_00 = xmove;
  fparam_4_00 = ymove;
  if (matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,savedHeight,xorigShadow,yorigShadow,xmoveShadow,matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit,fparam_1_00,fparam_2_00,
                 fparam_3_00,fparam_4_00,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00057c84:
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
        goto LAB_00057c84;
      }
    }
    rendererInfoByte79IsZero = rendererInfoByte79 == '\0';
    if (rendererInfoByte79IsZero) {
      changeWord3 = changeWord3 & 0x17000000;
    }
    else {
      changeWord3 = changeWord3 & 0x17ffffff;
    }
    matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit = *(uint *)(glContext + 800);
    if (rendererInfoByte79IsZero) {
      noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) && matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit == 0;
    }
    else {
      noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) && matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit == 0;
    }
    if (!noStateChangePending) {
      matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit = (uint)*(byte *)(glContext + 0x85a6);
      if (*(byte *)(glContext + 0x85a8) == matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit) {
        dispatchFlags = (**(code **)(glContext + 0x4788))
                          (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
        matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit = dispatchFlags & 4;
        if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            (matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit != *(byte *)(glContext + 0x7581))) ||
           ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
          if (matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00057da4;
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
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glBitmap_Exec)(glContext,width,height,xorigShadow,yorigShadow,xmoveShadow,matrixChangeBitsThenChangeWord4ThenRendererIndexThenDispatchBit,bitmap,xorig,yorig,
                   xmove,ymove,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
LAB_00057da4:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glBlendFunc_ListExec @ 0x57e0c (44 bytes) */
int _glBlendFunc_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glBlendFunc_Exec(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glBlendFunc_Comp @ 0x57e38 (84 bytes) */
int _glBlendFunc_Comp(glContext, sfactor, dfactor)
  undefined4 glContext;
  undefined4 sfactor;
  undefined4 dfactor;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendFunc_ListExec_00110034,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = dfactor;
    *listRecord = sfactor;
  }
  return listRecord;
}

/* _glBlendFunc_CompExec @ 0x57e8c (64 bytes) */
void _glBlendFunc_CompExec(glContext, sfactor, dfactor)
  undefined4 glContext;
  undefined4 sfactor;
  undefined4 dfactor;
{
  ((int (*)())_glBlendFunc_Comp)(glContext,sfactor,dfactor);
  _glBlendFunc_Exec(glContext,sfactor,dfactor);
  return;
}

/* _glBlendColor_ListExec @ 0x57ecc (52 bytes) */
int _glBlendColor_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glBlendColor_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2],
                     (double)recordedArgs[3]);
  return 0x10;
}

/* _glBlendColor_Comp @ 0x57f00 (92 bytes) */
void _glBlendColor_Comp(undefined4 glContext,float red,float green,float blue,float alpha)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glBlendColor_ListExec_00110030,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)alpha;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return;
}

/* _glBlendColor_Exec @ 0x57f5c (228 bytes) */
void _glBlendColor_Exec(int glContext,float red,float green,float blue,float alpha)
{
  float floatZero;
  float floatOne;
  float zeroAsDouble;
  float oneAsDouble;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  zeroAsDouble = (double)FLOAT_00108e50;
  oneAsDouble = (double)FLOAT_00108e54;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 4;
  if (red < (double)zeroAsDouble) {
    *(float *)(glContext + 0x30d0) = floatZero;
  }
  else if ((double)oneAsDouble < red) {
    *(float *)(glContext + 0x30d0) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d0) = (float)red;
  }
  if (green < (double)zeroAsDouble) {
    *(float *)(glContext + 0x30d4) = floatZero;
  }
  else if ((double)oneAsDouble < green) {
    *(float *)(glContext + 0x30d4) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d4) = (float)green;
  }
  if (blue < (double)zeroAsDouble) {
    *(float *)(glContext + 0x30d8) = floatZero;
  }
  else if ((double)oneAsDouble < blue) {
    *(float *)(glContext + 0x30d8) = floatOne;
  }
  else {
    *(float *)(glContext + 0x30d8) = (float)blue;
  }
  if (alpha < (double)zeroAsDouble) {
    *(float *)(glContext + 0x30dc) = floatZero;
    return;
  }
  if ((double)oneAsDouble < alpha) {
    *(float *)(glContext + 0x30dc) = floatOne;
    return;
  }
  *(float *)(glContext + 0x30dc) = (float)alpha;
  return;
}

/* _glBlendColor_CompExec @ 0x58040 (96 bytes) */
void _glBlendColor_CompExec(undefined4 glContext,float red,float green,float blue,float alpha)
{
  ((void (*)())_glBlendColor_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glBlendColor_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glBlendEquation_ListExec @ 0x580a0 (40 bytes) */
int _glBlendEquation_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendEquation_Exec)(glContext,*recordedArgs);
  return 4;
}

/* _glBlendEquation_Comp @ 0x580c8 (76 bytes) */
int _glBlendEquation_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendEquation_ListExec_0011002c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glBlendEquation_Exec @ 0x58114 (128 bytes) */
void _glBlendEquation_Exec(glContext, mode)
  int glContext;
  uint mode;
{
  bool modeOutOfRange;
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode < 0x800c) {
      if (0x8009 < mode) goto LAB_0005817c;
      modeOutOfRange = 2 < mode - 0x8006;
    }
    else {
      modeOutOfRange = 1 < mode - 0x877d;
    }
    if (!modeOutOfRange) {
LAB_0005817c:
      *(short *)(glContext + 0x30e2) = (short)mode;
      *(short *)(glContext + 0x30e0) = (short)mode;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
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

/* _glBlendEquation_CompExec @ 0x58194 (56 bytes) */
void _glBlendEquation_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glBlendEquation_Comp)(glContext,mode);
  ((void (*)())_glBlendEquation_Exec)(glContext,mode);
  return;
}

/* _glBlendFuncSeparate_ListExec @ 0x581cc (56 bytes) */
int _glBlendFuncSeparate_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendFuncSeparate_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],recordedArgs[3]);
  return 0x10;
}

/* _glBlendFuncSeparate_Comp @ 0x58204 (100 bytes) */
int _glBlendFuncSeparate_Comp(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  undefined4 glContext;
  undefined4 sfactorRGB;
  undefined4 dfactorRGB;
  undefined4 sfactorAlpha;
  undefined4 dfactorAlpha;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glBlendFuncSeparate_ListExec_00110028,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = dfactorAlpha;
    *listRecord = sfactorRGB;
    listRecord[1] = dfactorRGB;
    listRecord[2] = sfactorAlpha;
  }
  return listRecord;
}

/* _glBlendFuncSeparate_Exec @ 0x58268 (248 bytes) */
void _glBlendFuncSeparate_Exec(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  int glContext;
  uint sfactorRGB;
  uint dfactorRGB;
  uint sfactorAlpha;
  uint dfactorAlpha;
{
  bool factorOutOfRange;
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000582c0;
  }
  if (dfactorRGB < 0x308) {
    if (dfactorRGB < 0x300) {
      factorOutOfRange = 1 < dfactorRGB;
      goto LAB_000582ac;
    }
LAB_000582c8:
    if (sfactorRGB < 0x309) {
      if (sfactorRGB < 0x300) {
        factorOutOfRange = 1 < sfactorRGB;
        goto LAB_000582ec;
      }
    }
    else {
      factorOutOfRange = 3 < sfactorRGB - 0x8001;
LAB_000582ec:
      if (factorOutOfRange) goto LAB_000582b0;
    }
    if (dfactorAlpha < 0x308) {
      if (dfactorAlpha < 0x300) {
        factorOutOfRange = 1 < dfactorAlpha;
        goto LAB_00058314;
      }
    }
    else {
      factorOutOfRange = 3 < dfactorAlpha - 0x8001;
LAB_00058314:
      if (factorOutOfRange) goto LAB_000582b0;
    }
    if (sfactorAlpha < 0x309) {
      if (0x2ff < sfactorAlpha) goto LAB_00058340;
      factorOutOfRange = 1 < sfactorAlpha;
    }
    else {
      factorOutOfRange = 3 < sfactorAlpha - 0x8001;
    }
    if (!factorOutOfRange) {
LAB_00058340:
      *(short *)(glContext + 0x30ca) = (short)dfactorRGB;
      *(short *)(glContext + 0x30c8) = (short)sfactorRGB;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      *(short *)(glContext + 0x30ce) = (short)dfactorAlpha;
      *(short *)(glContext + 0x30cc) = (short)sfactorAlpha;
      return;
    }
  }
  else {
    factorOutOfRange = 3 < dfactorRGB - 0x8001;
LAB_000582ac:
    if (!factorOutOfRange) goto LAB_000582c8;
  }
LAB_000582b0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000582c0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBlendFuncSeparate_CompExec @ 0x58360 (80 bytes) */
void _glBlendFuncSeparate_CompExec(glContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)
  undefined4 glContext;
  undefined4 sfactorRGB;
  undefined4 dfactorRGB;
  undefined4 sfactorAlpha;
  undefined4 dfactorAlpha;
{
  ((int (*)())_glBlendFuncSeparate_Comp)(glContext,sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  ((void (*)())_glBlendFuncSeparate_Exec)(glContext,sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  return;
}

/* _glBlendEquationSeparateEXT_ListExec @ 0x583b0 (44 bytes) */
int _glBlendEquationSeparateEXT_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(glContext,*recordedArgs,recordedArgs[1]);
  return 8;
}

/* _glBlendEquationSeparateEXT_Comp @ 0x583dc (84 bytes) */
int _glBlendEquationSeparateEXT_Comp(glContext, modeRGB, modeAlpha)
  undefined4 glContext;
  undefined4 modeRGB;
  undefined4 modeAlpha;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glBlendEquationSeparateEXT_ListExec_00110024,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = modeAlpha;
    *listRecord = modeRGB;
  }
  return listRecord;
}

/* _glBlendEquationSeparateEXT_Exec @ 0x58430 (176 bytes) */
void _glBlendEquationSeparateEXT_Exec(glContext, modeRGB, modeAlpha)
  int glContext;
  uint modeRGB;
  uint modeAlpha;
{
  bool modeOutOfRange;
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00058490;
  }
  if (modeRGB < 0x800c) {
    if (modeRGB < 0x800a) {
      modeOutOfRange = 2 < modeRGB - 0x8006;
      goto LAB_0005847c;
    }
LAB_00058498:
    if (modeAlpha < 0x800c) {
      if (0x8009 < modeAlpha) goto LAB_000584c8;
      modeOutOfRange = 2 < modeAlpha - 0x8006;
    }
    else {
      modeOutOfRange = 1 < modeAlpha - 0x877d;
    }
    if (!modeOutOfRange) {
LAB_000584c8:
      *(short *)(glContext + 0x30e0) = (short)modeRGB;
      *(short *)(glContext + 0x30e2) = (short)modeAlpha;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      return;
    }
  }
  else {
    modeOutOfRange = 1 < modeRGB - 0x877d;
LAB_0005847c:
    if (!modeOutOfRange) goto LAB_00058498;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00058490:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBlendEquationSeparateEXT_CompExec @ 0x584e0 (64 bytes) */
void _glBlendEquationSeparateEXT_CompExec(glContext, modeRGB, modeAlpha)
  undefined4 glContext;
  undefined4 modeRGB;
  undefined4 modeAlpha;
{
  ((int (*)())_glBlendEquationSeparateEXT_Comp)(glContext,modeRGB,modeAlpha);
  ((void (*)())_glBlendEquationSeparateEXT_Exec)(glContext,modeRGB,modeAlpha);
  return;
}

