#include "decls.h"

/* _glResetHistogram_Comp @ 0x690f0 (76 bytes) */
int _glResetHistogram_Comp(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glResetHistogram_ListExec_00110110,0x10);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
  }
  return listRecord;
}

/* _glResetMinmax_Comp @ 0x6913c (76 bytes) */
int _glResetMinmax_Comp(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glResetMinmax_ListExec_0011010c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = target;
  }
  return listRecord;
}

/* _glConvolutionFilter1D_Exec @ 0x69188 (376 bytes) */
void _glConvolutionFilter1D_Exec(glContext, target, internalformat, width, format, type, image)
  int glContext;
  int target;
  undefined4 internalformat;
  uint width;
  undefined4 format;
  undefined4 type;
  int image;
{
  undefined4 glErrorCode;
  int internalFormat;
  int iVar3;
  int pixelUnpackBuffer;
  int imageEndOffset;
  int iVar5;
  int iVar6;
  double bytesPerElement;
  
  internalFormat = _gleImagingTexFormatToInternal(internalformat);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target != 0x8010) || (internalFormat == 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000692a4;
    }
    iVar3 = _CheckTypeFormat(type,format);
    if (iVar3 != 0) {
      if (0xb < width) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_000692a4;
      }
      pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
      if (pixelUnpackBuffer == 0) {
LAB_000692cc:
        _gleConvolutionFilter1D(glContext,0x8010,internalFormat,width,format,type,image);
        return;
      }
      imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,image);
      iVar6 = *(int *)(pixelUnpackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar5 = (int)bytesPerElement;
      if (imageEndOffset <= iVar6) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(format,type);
        }
        if (image == (image / iVar5) * iVar5) {
          if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
          }
          image = image + *(int *)(pixelUnpackBuffer + 0x30);
          goto LAB_000692cc;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_000692a4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glConvolutionFilter2D_Exec @ 0x69300 (408 bytes) */
void _glConvolutionFilter2D_Exec(glContext, target, internalformat, width, height, format, type, image)
  int glContext;
  int target;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  int image;
{
  undefined4 glErrorCode;
  int internalFormat;
  int iVar3;
  int pixelUnpackBuffer;
  int imageEndOffset;
  int iVar5;
  int iVar6;
  double bytesPerElement;
  
  internalFormat = _gleImagingTexFormatToInternal(internalformat);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target != 0x8011) || (internalFormat == 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00069438;
    }
    iVar3 = _CheckTypeFormat(type,format);
    if (iVar3 != 0) {
      if ((((0xb < width) || (0xb < height)) || (width < 0)) || (height < 0)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_00069438;
      }
      pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
      if (pixelUnpackBuffer == 0) {
LAB_00069460:
        _gleConvolutionFilter2D(glContext,0x8011,internalFormat,width,height,format,type,image);
        return;
      }
      imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,image);
      iVar6 = *(int *)(pixelUnpackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar5 = (int)bytesPerElement;
      if (imageEndOffset <= iVar6) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(format,type);
        }
        if (image == (image / iVar5) * iVar5) {
          if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
          }
          image = image + *(int *)(pixelUnpackBuffer + 0x30);
          goto LAB_00069460;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00069438:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glConvolutionParameteri_Exec @ 0x69498 (176 bytes) */
void _glConvolutionParameteri_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  int pname;
  undefined4 params;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target - 0x8010 < 3) && (pname == 0x8013)) {
      if (target == 0x8011) {
        *(undefined2 *)(glContext + 0x3308) = (*(unsigned short *)((unsigned char *)&(params) + 2));
        return;
      }
      if (target < 0x8012) {
        if (target == 0x8010) {
          *(undefined2 *)(glContext + 13000) = (*(unsigned short *)((unsigned char *)&(params) + 2));
          return;
        }
      }
      else if (target == 0x8012) {
        *(undefined2 *)(glContext + 0x3348) = (*(unsigned short *)((unsigned char *)&(params) + 2));
        return;
      }
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

/* _glConvolutionParameteriv_Exec @ 0x69548 (692 bytes) */
void _glConvolutionParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  uint *params;
{
  double intToDoubleMagic;
  undefined4 glErrorCode;
  float *pfVar3;
  
  intToDoubleMagic = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8011) {
      pfVar3 = (float *)(glContext + 0x32d8);
LAB_000695f0:
      if (pname == 0x8015) {
        pfVar3[5] = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        pfVar3[7] = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
        pfVar3[9] = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
        pfVar3[0xb] = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
        return;
      }
      if (pname < 0x8016) {
        if (pname == 0x8014) {
          pfVar3[4] = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
          pfVar3[6] = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
          pfVar3[8] = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
          pfVar3[10] = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
          return;
        }
      }
      else if (pname == 0x8154) {
        *pfVar3 = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
        pfVar3[1] = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
        pfVar3[2] = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
        pfVar3[3] = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
        return;
      }
      ((void (*)())_glConvolutionParameteri_Exec)(glContext,target,pname,*params);
      return;
    }
    if (target < 0x8012) {
      if (target == 0x8010) {
        pfVar3 = (float *)(glContext + 0x3298);
        goto LAB_000695f0;
      }
    }
    else if (target == 0x8012) {
      pfVar3 = (float *)(glContext + 0x3318);
      goto LAB_000695f0;
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

/* _glConvolutionParameterf_Exec @ 0x697fc (44 bytes) */
void _glConvolutionParameterf_Exec(undefined4 glContext,undefined4 target,undefined4 pname,double params)
{
  ((void (*)())_glConvolutionParameteri_Exec)(glContext,target,pname,(int)params);
  return;
}

/* _glConvolutionParameterfv_Exec @ 0x69828 (324 bytes) */
void _glConvolutionParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  float *params;
{
  undefined4 glErrorCode;
  float *pfVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8011) {
      pfVar2 = (float *)(glContext + 0x32d8);
LAB_000698b8:
      if (pname == 0x8015) {
        pfVar2[5] = *params;
        pfVar2[7] = params[1];
        pfVar2[9] = params[2];
        pfVar2[0xb] = params[3];
        return;
      }
      if (pname < 0x8016) {
        if (pname == 0x8014) {
          pfVar2[4] = *params;
          pfVar2[6] = params[1];
          pfVar2[8] = params[2];
          pfVar2[10] = params[3];
          return;
        }
      }
      else if (pname == 0x8154) {
        *pfVar2 = *params;
        pfVar2[1] = params[1];
        pfVar2[2] = params[2];
        pfVar2[3] = params[3];
        return;
      }
      ((void (*)())_glConvolutionParameterf_Exec)(glContext,target,pname,(double)*params);
      return;
    }
    if (target < 0x8012) {
      if (target == 0x8010) {
        pfVar2 = (float *)(glContext + 0x3298);
        goto LAB_000698b8;
      }
    }
    else if (target == 0x8012) {
      pfVar2 = (float *)(glContext + 0x3318);
      goto LAB_000698b8;
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

/* _glCopyConvolutionFilter1D_Exec @ 0x6996c (824 bytes) */
void _glCopyConvolutionFilter1D_Exec(glContext, target, internalformat, x, y, width)
  int glContext;
  int target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  uint width;
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 uVar3;
  int *srcCursor;
  int internalFormat;
  int iVar6;
  int framebufferObject;
  undefined4 uVar7;
  int matrixChangeBits;
  uint uVar9;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar11;
  double extraout_f1_02;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  undefined1 auStack_e0 [188];
  
  uVar3 = x;
  uVar7 = y;
  uVar9 = width;
  internalFormat = _gleImagingTexFormatToInternal(internalformat);
  dVar11 = extraout_f1;
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      dVar11 = extraout_f1_00;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,internalformat,uVar3,uVar7,uVar9,matrixChangeBits,dVar11,incomingFpr2,incomingFpr3,incomingFpr4,
                   incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        dVar11 = dVar11;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00069ab8:
        changeWord3 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar6 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar6 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        changeWord3 = *(uint *)(glContext + 0x31c);
        if ((changeWord3 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            dVar11 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            dVar11 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_00069ab8;
        }
      }
      bVar1 = rendererInfoByte79 == '\0';
      if (bVar1) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (bVar1) {
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
             (dVar11 = extraout_f1_02, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
          {
            if ((dispatchFlags & 4) == 0) {
              dispatchFlags = dispatchFlags & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            dVar11 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00069c40;
            }
          }
        }
        else {
          dVar11 = (double)_gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *changeWordCursor = 0;
          changeWordCursor = changeWordCursor + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target == 0x8010) && (internalFormat != 0)) {
      if (width < 0xc) {
        ((void (*)())_glReadPixels_Exec)(glContext,x,y,width,1,internalFormat,0x1406,auStack_e0,dVar11,incomingFpr2,
                           incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
        ((void (*)())_glConvolutionFilter1D_Exec)(glContext,0x8010,internalFormat,width,internalFormat,0x1406,auStack_e0);
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
      glErrorCode = 0x500;
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
LAB_00069c40:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCopyConvolutionFilter2D_Exec @ 0x69ca4 (856 bytes) */
void _glCopyConvolutionFilter2D_Exec(glContext, target, internalformat, x, y, width, height)
  int glContext;
  int target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  int width;
  int height;
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 uVar3;
  int *srcCursor;
  int internalFormat;
  int framebufferObject;
  undefined4 uVar7;
  int iVar8;
  int matrixChangeBits;
  int iVar9;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar12;
  double extraout_f1_02;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  undefined1 auStack_7c0 [1944];
  
  uVar3 = x;
  uVar7 = y;
  iVar9 = width;
  internalFormat = _gleImagingTexFormatToInternal(internalformat);
  dVar12 = extraout_f1;
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      dVar12 = extraout_f1_00;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,internalformat,uVar3,uVar7,iVar9,matrixChangeBits,dVar12,incomingFpr2,incomingFpr3,incomingFpr4,
                   incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        dVar12 = dVar12;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00069df4:
        changeWord3 = *(uint *)(glContext + 0x31c);
      }
      else {
        loopIndex = 0;
        srcCursor = (int *)(glContext + 0x324);
        do {
          iVar8 = *srcCursor;
          srcCursor = srcCursor + 1;
          if (iVar8 != 0) {
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 9);
        changeWord3 = *(uint *)(glContext + 0x31c);
        if ((changeWord3 & 0x15555) != 0) {
          if (*(char *)(glContext + 0x2e54) != '\0') {
            dVar12 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
          }
          if (*(char *)(glContext + 0x3094) != '\0') {
            dVar12 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
          }
          goto LAB_00069df4;
        }
      }
      bVar1 = rendererInfoByte79 == '\0';
      if (bVar1) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (bVar1) {
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
             (dVar12 = extraout_f1_02, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
          {
            if ((dispatchFlags & 4) == 0) {
              dispatchFlags = dispatchFlags & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            dVar12 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00069f94;
            }
          }
        }
        else {
          dVar12 = (double)_gleSwitchToNonRevertRenderer(glContext);
        }
        remaining = 0x13;
        do {
          *changeWordCursor = 0;
          changeWordCursor = changeWordCursor + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target == 0x8011) && (internalFormat != 0)) {
      if (((width < 0xc) && (height < 0xc)) && ((-1 < width && (-1 < height)))) {
        ((void (*)())_glReadPixels_Exec)(glContext,x,y,width,height,internalFormat,0x1406,auStack_7c0,dVar12,
                           incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
        ((void (*)())_glConvolutionFilter2D_Exec)(glContext,0x8011,internalFormat,width,height,internalFormat,0x1406,auStack_7c0);
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
      glErrorCode = 0x500;
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
LAB_00069f94:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetConvolutionFilter_Exec @ 0x69ffc (340 bytes) */
void _glGetConvolutionFilter_Exec(glContext, target, format, type, image)
  int glContext;
  int target;
  undefined4 format;
  undefined4 type;
  int image;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int pixelPackBuffer;
  int iVar4;
  double bytesPerElement;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (1 < target - 0x8010U) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0006a0fc;
    }
    iVar3 = _CheckTypeFormat(format,type);
    if (iVar3 != 0) {
      pixelPackBuffer = *(int *)(glContext + 0x4a68);
      if (pixelPackBuffer == 0) {
LAB_0006a124:
        _gleGetConvolutionFilter(glContext,target,format,type,image);
        return;
      }
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar2 = glContext + 0x3298;
      iVar4 = (int)bytesPerElement;
      if (target != 0x8010) {
        iVar2 = glContext + 0x32d8;
      }
      iVar2 = _gleOffsetLimitImage
                        (glContext + 0x31b0,*(undefined4 *)(iVar2 + 0x38),
                         *(undefined4 *)(iVar2 + 0x3c),format,type,image);
      if (iVar2 <= *(int *)(pixelPackBuffer + 0x38)) {
        if (iVar4 == 0) {
          iVar4 = _glePixelBytes(format,type);
        }
        if (image == (image / iVar4) * iVar4) {
          if (*(int *)(pixelPackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
          }
          image = image + *(int *)(pixelPackBuffer + 0x30);
          goto LAB_0006a124;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0006a0fc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetConvolutionParameteriv_Exec @ 0x6a150 (568 bytes) */
void _glGetConvolutionParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  float *params;
{
  undefined4 glErrorCode;
  float fVar2;
  float *pfVar3;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006a1d8;
  }
  if (target == 0x8011) {
    pfVar3 = (float *)(glContext + 0x32d8);
LAB_0006a1e0:
    if (pname == 0x8018) {
      fVar2 = pfVar3[0xe];
      goto LAB_0006a368;
    }
    if (0x8018 < pname) {
      if (pname != 0x801a) {
        if (pname < 0x801a) {
          fVar2 = pfVar3[0xf];
          goto LAB_0006a368;
        }
        if (pname != 0x801b) {
          if (pname == 0x8154) {
            *params = GH_U2F((unsigned int)((int)*pfVar3));
            params[1] = GH_U2F((unsigned int)((int)pfVar3[1]));
            params[2] = GH_U2F((unsigned int)((int)pfVar3[2]));
            fVar2 = pfVar3[3];
            goto LAB_0006a30c;
          }
          goto LAB_0006a1c8;
        }
      }
      fVar2 = 1.54143e-44;
LAB_0006a368:
      *params = fVar2;
      return;
    }
    if (pname == 0x8014) {
      *params = GH_U2F((unsigned int)((int)pfVar3[4]));
      params[1] = GH_U2F((unsigned int)((int)pfVar3[6]));
      params[2] = GH_U2F((unsigned int)((int)pfVar3[8]));
      fVar2 = pfVar3[10];
LAB_0006a30c:
      params[3] = GH_U2F((unsigned int)((int)fVar2));
      return;
    }
    if (pname < 0x8015) {
      if (pname == 0x8013) {
        fVar2 = GH_U2F((unsigned int)((uint)*(ushort *)(pfVar3 + 0xc)));
        goto LAB_0006a368;
      }
    }
    else {
      if (pname == 0x8015) {
        *params = GH_U2F((unsigned int)((int)pfVar3[5]));
        params[1] = GH_U2F((unsigned int)((int)pfVar3[7]));
        params[2] = GH_U2F((unsigned int)((int)pfVar3[9]));
        fVar2 = pfVar3[0xb];
        goto LAB_0006a30c;
      }
      if (pname == 0x8017) {
        fVar2 = GH_U2F((unsigned int)((uint)*(ushort *)((int)pfVar3 + 0x32)));
        goto LAB_0006a368;
      }
    }
  }
  else if (target < 0x8012) {
    if (target == 0x8010) {
      pfVar3 = (float *)(glContext + 0x3298);
      goto LAB_0006a1e0;
    }
  }
  else if (target == 0x8012) {
    pfVar3 = (float *)(glContext + 0x3318);
    goto LAB_0006a1e0;
  }
LAB_0006a1c8:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0006a1d8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetConvolutionParameterfv_Exec @ 0x6a388 (404 bytes) */
void _glGetConvolutionParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  float *params;
{
  float fVar1;
  undefined4 glErrorCode;
  float *pfVar3;
  uint local_18 [4];
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006a42c;
  }
  if (target != 0x8011) {
    if (target < 0x8012) {
      if (target == 0x8010) {
        pfVar3 = (float *)(glContext + 0x3298);
        goto LAB_0006a434;
      }
    }
    else if (target == 0x8012) {
      pfVar3 = (float *)(glContext + 0x3318);
      goto LAB_0006a434;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0006a42c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  pfVar3 = (float *)(glContext + 0x32d8);
LAB_0006a434:
  if (pname != 0x8015) {
    if (pname < 0x8016) {
      if (pname == 0x8014) {
        *params = pfVar3[4];
        params[1] = pfVar3[6];
        params[2] = pfVar3[8];
        fVar1 = pfVar3[10];
        goto LAB_0006a4cc;
      }
    }
    else if (pname == 0x8154) {
      *params = *pfVar3;
      params[1] = pfVar3[1];
      params[2] = pfVar3[2];
      fVar1 = pfVar3[3];
      goto LAB_0006a4cc;
    }
    ((void (*)())_glGetConvolutionParameteriv_Exec)(glContext,target,pname,local_18);
    *params = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
    return;
  }
  *params = pfVar3[5];
  params[1] = pfVar3[7];
  params[2] = pfVar3[9];
  fVar1 = pfVar3[0xb];
LAB_0006a4cc:
  params[3] = fVar1;
  return;
}

/* _glGetSeparableFilter_Exec @ 0x6a51c (400 bytes) */
void _glGetSeparableFilter_Exec(glContext, target, format, type, row, column, span)
  int glContext;
  int target;
  undefined4 format;
  undefined4 type;
  int row;
  int column;
  undefined4 span;
{
  undefined4 glErrorCode;
  int iVar2;
  int pixelPackBuffer;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double bytesPerElement;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8012) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0006a64c;
    }
    iVar2 = _CheckTypeFormat(type,format);
    if (iVar2 != 0) {
      pixelPackBuffer = *(int *)(glContext + 0x4a68);
      if (pixelPackBuffer == 0) {
LAB_0006a678:
        _gleGetSeparableFilter(glContext,0x8012,format,type,row,column);
        return;
      }
      iVar3 = _gleOffsetLimitImage
                        (glContext + 0x31b0,*(undefined4 *)(glContext + 0x3350),1,format,type,
                         row);
      iVar4 = _gleOffsetLimitImage
                        (glContext + 0x31b0,*(undefined4 *)(glContext + 0x3354),1,format,type,
                         column);
      iVar6 = *(int *)(pixelPackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar5 = (int)bytesPerElement;
      if ((iVar3 <= iVar6) && (iVar4 <= iVar6)) {
        if (iVar5 == 0) {
          iVar5 = _glePixelBytes(format,type);
        }
        if ((row == (row / iVar5) * iVar5) && (column == (column / iVar5) * iVar5)) {
          if (*(int *)(pixelPackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
          }
          column = column + *(int *)(pixelPackBuffer + 0x30);
          row = row + *(int *)(pixelPackBuffer + 0x30);
          goto LAB_0006a678;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0006a64c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glSeparableFilter2D_Exec @ 0x6a6ac (480 bytes) */
void _glSeparableFilter2D_Exec(glContext, target, internalformat, width, height, format, type, row, column)
  int glContext;
  int target;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  int row;
  int column;
{
  undefined4 glErrorCode;
  int internalFormat;
  int iVar3;
  int pixelUnpackBuffer;
  int imageEndOffset;
  int imageEndOffset2;
  int iVar6;
  int iVar7;
  double bytesPerElement;
  
  internalFormat = _gleImagingTexFormatToInternal(internalformat);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((target != 0x8012) || (internalFormat == 0)) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0006a824;
    }
    iVar3 = _CheckTypeFormat(type,format);
    if (iVar3 != 0) {
      if ((((0xb < width) || (0xb < height)) || (width < 0)) || (height < 0)) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_0006a824;
      }
      pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
      if (pixelUnpackBuffer == 0) {
LAB_0006a850:
        _gleSeparableFilter2D(glContext,0x8012,internalFormat,width,height,format,type,row,column);
        return;
      }
      imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,1,format,type,row);
      imageEndOffset2 = _gleOffsetLimitImage(glContext + 0x31cc,height,1,format,type,column);
      iVar7 = *(int *)(pixelUnpackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar6 = (int)bytesPerElement;
      if ((imageEndOffset <= iVar7) && (imageEndOffset2 <= iVar7)) {
        if (iVar6 == 0) {
          iVar6 = _glePixelBytes(format,type);
        }
        if ((row == (row / iVar6) * iVar6) && (column == (column / iVar6) * iVar6)) {
          if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
          }
          column = column + *(int *)(pixelUnpackBuffer + 0x30);
          row = row + *(int *)(pixelUnpackBuffer + 0x30);
          goto LAB_0006a850;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0006a824:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetHistogram_Exec @ 0x6a88c (332 bytes) */
void _glGetHistogram_Exec(glContext, target, reset, format, type, values)
  int glContext;
  int target;
  undefined4 reset;
  undefined4 format;
  undefined4 type;
  int values;
{
  undefined4 glErrorCode;
  int iVar2;
  int pixelPackBuffer;
  int iVar3;
  int iVar4;
  int iVar5;
  double bytesPerElement;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8024) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0006a980;
    }
    iVar2 = _CheckTypeFormat(type,format);
    if (iVar2 != 0) {
      if (*(int *)(glContext + 0x3388) < 1) {
        return;
      }
      pixelPackBuffer = *(int *)(glContext + 0x4a68);
      if (pixelPackBuffer == 0) {
LAB_0006a9a8:
        _gleGetHistogram(glContext,0x8024,reset,format,type,values);
        return;
      }
      iVar3 = _gleOffsetLimitImage
                        (glContext + 0x31b0,*(int *)(glContext + 0x3388),1,format,type,values);
      iVar5 = *(int *)(pixelPackBuffer + 0x38);
      bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
      iVar4 = (int)bytesPerElement;
      if (iVar3 <= iVar5) {
        if (iVar4 == 0) {
          iVar4 = _glePixelBytes(format,type);
        }
        if (values == (values / iVar4) * iVar4) {
          if (*(int *)(pixelPackBuffer + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
          }
          values = values + *(int *)(pixelPackBuffer + 0x30);
          goto LAB_0006a9a8;
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0006a980:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetHistogramParameterfv_Exec @ 0x6a9d8 (100 bytes) */
void _glGetHistogramParameterfv_Exec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  float *params;
{
  uint local_18 [3];
  
  ((void (*)())_glGetHistogramParameteriv_Exec)(glContext,target,pname,local_18);
  *params = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glGetHistogramParameteriv_Exec @ 0x6aa3c (168 bytes) */
void _glGetHistogramParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  undefined4 pname;
  uint *params;
{
  undefined4 glErrorCode;
  uint uVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006aa8c;
  }
  if (1 < target - 0x8024U) {
switchD_0006aabc_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0006aa8c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  switch(pname) {
  case 0x8026:
    uVar2 = *(uint *)(glContext + 0x3388);
    break;
  case 0x8027:
    uVar2 = (uint)*(ushort *)(glContext + 0x338c);
    break;
  case 0x8028:
  case 0x8029:
  case 0x802a:
  case 0x802b:
  case 0x802c:
    uVar2 = 0x20;
    break;
  case 0x802d:
    uVar2 = (uint)*(byte *)(glContext + 0x338e);
    break;
  default:
    goto switchD_0006aabc_default;
  }
  *params = uVar2;
  return;
}

/* _glGetMinmax_Exec @ 0x6ab04 (292 bytes) */
void _glGetMinmax_Exec(glContext, target, reset, format, type, values)
  int glContext;
  int target;
  undefined4 reset;
  undefined4 format;
  undefined4 type;
  int values;
{
  undefined4 glErrorCode;
  int imageEndOffset;
  int iVar3;
  int pixelPackBuffer;
  int iVar5;
  double bytesPerElement;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x802e) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0006abd0;
    }
    pixelPackBuffer = *(int *)(glContext + 0x4a68);
    if (pixelPackBuffer == 0) {
LAB_0006abf8:
      _gleGetMinmax(glContext,0x802e,reset,format,type,values);
      return;
    }
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31b0,2,1,format,type,values);
    iVar5 = *(int *)(pixelPackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar3 = (int)bytesPerElement;
    if (imageEndOffset <= iVar5) {
      if (iVar3 == 0) {
        iVar3 = _glePixelBytes(format,type);
      }
      if (values == (values / iVar3) * iVar3) {
        if (*(int *)(pixelPackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelPackBuffer + 0x10);
        }
        values = values + *(int *)(pixelPackBuffer + 0x30);
        goto LAB_0006abf8;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0006abd0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetMinmaxParameteriv_Exec @ 0x6ac28 (128 bytes) */
void _glGetMinmaxParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  int pname;
  uint *params;
{
  undefined4 glErrorCode;
  uint uVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x802e) {
      if (pname == 0x802f) {
        uVar2 = (uint)*(ushort *)(glContext + 0x3380);
LAB_0006aca0:
        *params = uVar2;
        return;
      }
      if (pname == 0x8030) {
        uVar2 = (uint)*(byte *)(glContext + 0x3382);
        goto LAB_0006aca0;
      }
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

/* _glGetMinmaxParameterfv_Exec @ 0x6aca8 (100 bytes) */
void _glGetMinmaxParameterfv_Exec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  float *params;
{
  uint local_18 [3];
  
  ((void (*)())_glGetMinmaxParameteriv_Exec)(glContext,target,pname,local_18);
  *params = (float)((double)CONCAT44(0x43300000,local_18[0] ^ 0x80000000) - DOUBLE_00108d58);
  return;
}

/* _glHistogram_Exec @ 0x6ad0c (280 bytes) */
void _glHistogram_Exec(glContext, target, width, internalformat, sink)
  int glContext;
  undefined4 target;
  uint width;
  undefined4 internalformat;
  int sink;
{
  undefined4 allocatedBlock;
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (((width & width - 1) == 0) && (-1 < (int)width)) {
      if ((int)width < 0x20001) {
        iVar2 = _CheckInternalFormat(internalformat);
        if (iVar2 != 0) {
          *(short *)(glContext + 0x338c) = (short)internalformat;
          *(byte *)(glContext + 0x338e) = (byte)((uint)-sink >> 0x1f);
          *(uint *)(glContext + 0x3388) = width;
          if (*(int *)(glContext + 0x3384) != 0) {
            _free(*(int *)(glContext + 0x3384));
          }
          if ((int)width < 1) {
            width = 1;
          }
          allocatedBlock = _calloc(width,0x10);
          *(undefined4 *)(glContext + 0x3384) = allocatedBlock;
          return;
        }
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
      }
      else {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x8031;
      }
    }
    else {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = uVar1;
  return;
}

/* _glMinmax_Exec @ 0x6ae24 (120 bytes) */
void _glMinmax_Exec(glContext, target, internalformat, sink)
  int glContext;
  int target;
  undefined4 internalformat;
  int sink;
{
  int iVar1;
  
  if ((target == 0x802e) && (iVar1 = _CheckInternalFormat(internalformat), iVar1 != 0)) {
    *(short *)(glContext + 0x3380) = (short)internalformat;
    *(byte *)(glContext + 0x3382) = (byte)((uint)-sink >> 0x1f);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
  return;
}

/* _glResetHistogram_Exec @ 0x6ae9c (172 bytes) */
void _glResetHistogram_Exec(glContext, target)
  int glContext;
  int target;
{
  int glContextFloat20;
  int iVar2;
  undefined4 glErrorCode;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8024) {
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x3388)) {
        glContextFloat20 = (int)*(float *)(glContext + 0x20);
        do {
          iVar2 = loopIndex * 0x10;
          loopIndex = loopIndex + 1;
          *(int *)(iVar2 + *(int *)(glContext + 0x3384)) = glContextFloat20;
          *(int *)(iVar2 + *(int *)(glContext + 0x3384) + 4) = glContextFloat20;
          *(int *)(iVar2 + *(int *)(glContext + 0x3384) + 8) = glContextFloat20;
          *(int *)(iVar2 + *(int *)(glContext + 0x3384) + 0xc) = glContextFloat20;
        } while (loopIndex < *(int *)(glContext + 0x3388));
        return;
      }
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

/* _glResetMinmax_Exec @ 0x6af48 (172 bytes) */
void _glResetMinmax_Exec(glContext, target)
  int glContext;
  int target;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x802e) {
      **(undefined4 **)(glContext + 0x337c) = *(undefined4 *)(glContext + 0x24);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 4) = *(undefined4 *)(glContext + 0x24);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 8) = *(undefined4 *)(glContext + 0x24);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 0xc) = *(undefined4 *)(glContext + 0x24);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 0x10) = *(undefined4 *)(glContext + 0x20);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 0x14) = *(undefined4 *)(glContext + 0x20);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 0x18) = *(undefined4 *)(glContext + 0x20);
      *(undefined4 *)(*(int *)(glContext + 0x337c) + 0x1c) = *(undefined4 *)(glContext + 0x20);
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

/* _glConvolutionFilter1D_CompExec @ 0x6aff4 (96 bytes) */
void _glConvolutionFilter1D_CompExec(glContext, target, internalformat, width, format, type, image)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  _glConvolutionFilter1D_Comp(glContext,target,internalformat,width,format,type,image);
  ((void (*)())_glConvolutionFilter1D_Exec)(glContext,target,internalformat,width,format,type,image);
  return;
}

/* _glConvolutionFilter2D_CompExec @ 0x6b054 (104 bytes) */
void _glConvolutionFilter2D_CompExec(glContext, target, internalformat, width, height, format, type, image)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  _glConvolutionFilter2D_Comp(glContext,target,internalformat,width,height,format,type,image);
  ((void (*)())_glConvolutionFilter2D_Exec)(glContext,target,internalformat,width,height,format,type,image);
  return;
}

/* _glConvolutionParameterf_CompExec @ 0x6b0bc (80 bytes) */
void _glConvolutionParameterf_CompExec(undefined4 glContext,undefined4 target,undefined4 pname,float params)
{
  ((undefined4 (*)())_glConvolutionParameterf_Comp)(glContext,target,pname,params);
  ((void (*)())_glConvolutionParameterf_Exec)(glContext,target,pname,params);
  return;
}

/* _glConvolutionParameterfv_CompExec @ 0x6b10c (72 bytes) */
void _glConvolutionParameterfv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  _glConvolutionParameterfv_Comp(glContext,target,pname,params);
  ((void (*)())_glConvolutionParameterfv_Exec)(glContext,target,pname,params);
  return;
}

/* _glConvolutionParameteri_CompExec @ 0x6b154 (72 bytes) */
void _glConvolutionParameteri_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  _glConvolutionParameteri_Comp(glContext,target,pname,params);
  ((void (*)())_glConvolutionParameteri_Exec)(glContext,target,pname,params);
  return;
}

/* _glConvolutionParameteriv_CompExec @ 0x6b19c (72 bytes) */
void _glConvolutionParameteriv_CompExec(glContext, target, pname, params)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 params;
{
  _glConvolutionParameteriv_Comp(glContext,target,pname,params);
  ((void (*)())_glConvolutionParameteriv_Exec)(glContext,target,pname,params);
  return;
}

/* _glCopyConvolutionFilter1D_CompExec @ 0x6b1e4 (88 bytes) */
void _glCopyConvolutionFilter1D_CompExec(glContext, target, internalformat, x, y, width)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
{
  _glCopyConvolutionFilter1D_Comp(glContext,target,internalformat,x,y,width);
  ((void (*)())_glCopyConvolutionFilter1D_Exec)(glContext,target,internalformat,x,y,width);
  return;
}

/* _glCopyConvolutionFilter2D_CompExec @ 0x6b23c (96 bytes) */
void _glCopyConvolutionFilter2D_CompExec(glContext, target, internalformat, x, y, width, height)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
  undefined4 height;
{
  _glCopyConvolutionFilter2D_Comp(glContext,target,internalformat,x,y,width,height);
  ((void (*)())_glCopyConvolutionFilter2D_Exec)(glContext,target,internalformat,x,y,width,height);
  return;
}

/* _glSeparableFilter2D_CompExec @ 0x6b29c (116 bytes) */
void _glSeparableFilter2D_CompExec(glContext, target, internalformat, width, height, format, type, row, column)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 row;
  undefined4 column;
{
  _glSeparableFilter2D_Comp(glContext,target,internalformat,width,height,format,type,row,column)
  ;
  ((void (*)())_glSeparableFilter2D_Exec)(glContext,target,internalformat,width,height,format,type,row,column)
  ;
  return;
}

/* _glHistogram_CompExec @ 0x6b310 (80 bytes) */
void _glHistogram_CompExec(glContext, target, width, internalformat, sink)
  undefined4 glContext;
  undefined4 target;
  undefined4 width;
  undefined4 internalformat;
  undefined4 sink;
{
  _glHistogram_Comp(glContext,target,width,internalformat,sink);
  ((void (*)())_glHistogram_Exec)(glContext,target,width,internalformat,sink);
  return;
}

/* _glMinmax_CompExec @ 0x6b360 (72 bytes) */
void _glMinmax_CompExec(glContext, target, internalformat, sink)
  undefined4 glContext;
  undefined4 target;
  undefined4 internalformat;
  undefined4 sink;
{
  _glMinmax_Comp(glContext,target,internalformat,sink);
  ((void (*)())_glMinmax_Exec)(glContext,target,internalformat,sink);
  return;
}

/* _glResetHistogram_CompExec @ 0x6b3a8 (56 bytes) */
void _glResetHistogram_CompExec(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  ((int (*)())_glResetHistogram_Comp)(glContext,target);
  ((void (*)())_glResetHistogram_Exec)(glContext,target);
  return;
}

/* _glResetMinmax_CompExec @ 0x6b3e0 (56 bytes) */
void _glResetMinmax_CompExec(glContext, target)
  undefined4 glContext;
  undefined4 target;
{
  ((int (*)())_glResetMinmax_Comp)(glContext,target);
  ((void (*)())_glResetMinmax_Exec)(glContext,target);
  return;
}

/* _glLightf_ListExec @ 0x6b418 (52 bytes) */
int _glLightf_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glLightf_Exec)(glContext,*recordedArgs,recordedArgs[1],(double)GH_U2F((unsigned int)(recordedArgs[2])));
  return 0xc;
}

/* _glLightf_Comp @ 0x6b44c (100 bytes) */
undefined4 * _glLightf_Comp(undefined4 glContext,undefined4 light,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLightf_ListExec_00110144,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = (float)param;
    *listRecord = light;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _glLightf_Exec @ 0x6b4b0 (724 bytes) */
void _glLightf_Exec(int glContext,int light,undefined4 pname,double param)
{
  byte bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int glContextWord5424;
  int iVar4;
  uint uVar5;
  double cosValue;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006b764;
  }
  uVar5 = light - 0x4000;
  if (uVar5 < 8) {
    iVar3 = glContext + uVar5 * 0x80;
    switch(pname) {
    case 0x1205:
      if ((!(param < (double)FLOAT_00108e50)) &&
         (!((double)(float)((double)CONCAT44(0x43300000,
                                             *(uint *)(*(int *)(glContext + 0x468c) + 0xa4) ^
                                             0x80000000) - DOUBLE_00108d58) < param))) {
        *(float *)(iVar3 + 0x287c) = (float)param;
        _gleUpdateLightExponents(glContext,uVar5);
        if (*(int *)(glContext + 0x5434) == 0) {
          bVar1 = *(byte *)(uVar5 * 7 + *(int *)(glContext + 0x5420) + 0x25d);
        }
        else {
          bVar1 = *(byte *)(uVar5 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
        }
        iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
        glContextWord5424 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
        bVar1 = *(byte *)(uVar5 * 7 + glContextWord5424 + 0x25d);
        goto LAB_0006b6cc;
      }
      break;
    case 0x1206:
      if (((double)FLOAT_00108e50 <= param) && (param <= (double)FLOAT_00108e88)) {
        *(float *)(iVar3 + 0x2890) = (float)param;
        cosValue = _cos((double)(float)(param * (double)FLOAT_00108e84));
        *(float *)(iVar3 + 0x286c) = (float)cosValue;
      }
      else {
        if (param != (double)FLOAT_00108e8c) break;
        *(undefined4 *)(iVar3 + 0x286c) = 0xbf800000;
        *(undefined4 *)(iVar3 + 0x2890) = 0;
      }
      _gleUpdateLightExponents(glContext,uVar5);
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(uVar5 * 7 + *(int *)(glContext + 0x5420) + 0x25c);
      }
      else {
        bVar1 = *(byte *)(uVar5 * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
      }
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(uVar5 * 7 + glContextWord5424 + 0x25c);
LAB_0006b6cc:
      iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
LAB_0006b76c:
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 4 << (uVar5 * 2 & 0x3e);
      return;
    case 0x1207:
      if (!(param < (double)FLOAT_00108e50)) {
        *(float *)(iVar3 + 0x2870) = (float)param;
LAB_0006b744:
        _gleUpdateLightAttenuation(glContext,uVar5);
        goto LAB_0006b76c;
      }
      break;
    case 0x1208:
      if (!(param < (double)FLOAT_00108e50)) {
        *(float *)(iVar3 + 0x2874) = (float)param;
        goto LAB_0006b744;
      }
      break;
    case 0x1209:
      if (!(param < (double)FLOAT_00108e50)) {
        *(float *)(iVar3 + 0x2878) = (float)param;
        goto LAB_0006b744;
      }
      break;
    default:
      goto switchD_0006b52c_default;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
switchD_0006b52c_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
LAB_0006b764:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glLightf_CompExec @ 0x6b798 (80 bytes) */
void _glLightf_CompExec(undefined4 glContext,undefined4 light,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glLightf_Comp)(glContext,light,pname,param);
  ((void (*)())_glLightf_Exec)(glContext,light,pname,param);
  return;
}

/* _glLightfv_ListExec @ 0x6b7e8 (52 bytes) */
undefined4 _glLightfv_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  
  ((void (*)())_glLightfv_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                  forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0);
  return 0x18;
}

/* _glLightfv_Comp @ 0x6b81c (200 bytes) */
int _glLightfv_Comp(glContext, light, pname, params)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLightfv_ListExec_00110140,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = light;
    listRecord[1] = pname;
    switch(pname) {
    case 0x1200:
    case 0x1201:
    case 0x1202:
    case 0x1203:
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      listRecord[5] = params[3];
      break;
    case 0x1204:
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      break;
    case 0x1205:
    case 0x1206:
    case 0x1207:
    case 0x1208:
    case 0x1209:
      listRecord[2] = *params;
    }
  }
  return listRecord;
}

/* _glLightfv_CompExec @ 0x6b90c (72 bytes) */
void _glLightfv_CompExec(glContext, light, pname, params)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 params;
{
  undefined4 in_LR;
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glLightfv_Comp)(glContext,light,pname,params);
  ((void (*)())_glLightfv_Exec)(glContext,light,pname,params,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8
                  ,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glLighti_ListExec @ 0x6b954 (52 bytes) */
undefined4 _glLighti_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  
  ((double (*)())_glLighti_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs[2],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5
                 ,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
                 incomingStack_ffffffd0);
  return 0xc;
}

/* _glLighti_Comp @ 0x6b988 (92 bytes) */
int _glLighti_Comp(glContext, light, pname, param)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLighti_ListExec_0011013c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = param;
    *listRecord = light;
    listRecord[1] = pname;
  }
  return listRecord;
}

/* _glLighti_Exec @ 0x6b9e4 (756 bytes) */
double _glLighti_Exec(int glContext,int light,undefined4 pname,uint param,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  float paramAsFloat;
  byte dirtyBitIndex;
  undefined4 glErrorCode;
  int lightRecord;
  int dirtyWord348Address;
  int glContextWord5424;
  int dirtyWordAddress;
  uint lightIndex;
  double updateResult;
  double cosValue;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return fparam_1;
    }
    glErrorCode = 0x502;
    goto LAB_0006bcb8;
  }
  lightIndex = light - 0x4000;
  if (lightIndex < 8) {
    lightRecord = glContext + lightIndex * 0x80;
    paramAsFloat = (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    switch(pname) {
    case 0x1205:
      if ((!(paramAsFloat < FLOAT_00108e50)) &&
         (!((float)((double)CONCAT44(0x43300000,
                                     *(uint *)(*(int *)(glContext + 0x468c) + 0xa4) ^ 0x80000000) -
                   DOUBLE_00108d58) < paramAsFloat))) {
        *(float *)(lightRecord + 0x287c) = paramAsFloat;
        updateResult = (double)_gleUpdateLightExponents(glContext,lightIndex);
        if (*(int *)(glContext + 0x5434) == 0) {
          dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25d);
        }
        else {
          dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
        }
        dirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        glContextWord5424 = *(int *)(glContext + 0x5424);
        *(uint *)(dirtyWordAddress + 0x324) = *(uint *)(dirtyWordAddress + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyBitIndex = *(byte *)(lightIndex * 7 + glContextWord5424 + 0x25d);
        goto LAB_0006bc20;
      }
      break;
    case 0x1206:
      if ((FLOAT_00108e50 <= paramAsFloat) && (paramAsFloat <= FLOAT_00108e88)) {
        *(float *)(lightRecord + 0x2890) = paramAsFloat;
        cosValue = _cos((double)(paramAsFloat * FLOAT_00108e84));
        *(float *)(lightRecord + 0x286c) = (float)cosValue;
      }
      else {
        if (paramAsFloat != FLOAT_00108e8c) break;
        *(undefined4 *)(lightRecord + 0x286c) = 0xbf800000;
        *(undefined4 *)(lightRecord + 0x2890) = 0;
      }
      updateResult = (double)_gleUpdateLightExponents(glContext,lightIndex);
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25c);
      }
      else {
        dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
      }
      dirtyWordAddress = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(dirtyWordAddress + 0x324) = *(uint *)(dirtyWordAddress + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex = *(byte *)(lightIndex * 7 + glContextWord5424 + 0x25c);
LAB_0006bc20:
      dirtyWord348Address = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      *(uint *)(dirtyWord348Address + 0x348) = *(uint *)(dirtyWord348Address + 0x348) | 1 << (dirtyBitIndex & 0x1f);
LAB_0006bcc0:
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 4 << (lightIndex * 2 & 0x3e);
      return updateResult;
    case 0x1207:
      if (!(paramAsFloat < FLOAT_00108e50)) {
        *(float *)(lightRecord + 0x2870) = paramAsFloat;
LAB_0006bc98:
        updateResult = (double)_gleUpdateLightAttenuation(glContext,lightIndex);
        goto LAB_0006bcc0;
      }
      break;
    case 0x1208:
      if (!(paramAsFloat < FLOAT_00108e50)) {
        *(float *)(lightRecord + 0x2874) = paramAsFloat;
        goto LAB_0006bc98;
      }
      break;
    case 0x1209:
      if (!(paramAsFloat < FLOAT_00108e50)) {
        *(float *)(lightRecord + 0x2878) = paramAsFloat;
        goto LAB_0006bc98;
      }
      break;
    default:
      goto switchD_0006ba80_default;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return fparam_1;
    }
    glErrorCode = 0x501;
  }
  else {
switchD_0006ba80_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return fparam_1;
    }
    glErrorCode = 0x500;
  }
LAB_0006bcb8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return fparam_1;
}

/* _glLighti_CompExec @ 0x6bcec (72 bytes) */
void _glLighti_CompExec(glContext, light, pname, param)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 param;
{
  unsigned int ghidra_home[8] = { glContext, light, pname, param, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double incomingFpr1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glLighti_Comp)(glContext,light,pname,param);
  ((double (*)())_glLighti_Exec)(glContext,light,pname,param,incomingFpr1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                 (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                 (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glLightiv_ListExec @ 0x6bd34 (52 bytes) */
undefined4 _glLightiv_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  
  ((void (*)())_glLightiv_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                  forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,
                  incomingStack_ffffffc8,incomingStack_ffffffd0);
  return 0x18;
}

/* _glLightiv_Comp @ 0x6bd68 (200 bytes) */
int _glLightiv_Comp(glContext, light, pname, params)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLightiv_ListExec_00110138,0x18);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = light;
    listRecord[1] = pname;
    switch(pname) {
    case 0x1200:
    case 0x1201:
    case 0x1202:
    case 0x1203:
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      listRecord[5] = params[3];
      break;
    case 0x1204:
      listRecord[2] = *params;
      listRecord[3] = params[1];
      listRecord[4] = params[2];
      break;
    case 0x1205:
    case 0x1206:
    case 0x1207:
    case 0x1208:
    case 0x1209:
      listRecord[2] = *params;
    }
  }
  return listRecord;
}

/* _glLightiv_Exec @ 0x6be58 (2268 bytes) */
void _glLightiv_Exec(int glContext,int light,undefined4 pname,uint *params,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  double intToDoubleMagic;
  float paramValue;
  byte dirtyBitIndex;
  float positionY;
  float positionX;
  float positionZ;
  double colorScale;
  undefined4 glErrorCode;
  int lightState;
  int dirtyWordBase2;
  int glContextWord5424;
  uint dirtyBitIndex2;
  int dirtyWordBase;
  uint lightIndex;
  double cosValue;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  
  colorScale = DOUBLE_00108d88;
  intToDoubleMagic = DOUBLE_00108d58;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006c728;
  }
  lightIndex = light - 0x4000;
  if (7 < lightIndex) {
switchD_0006bed0_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_0006c728;
  }
  lightState = glContext + lightIndex * 0x80;
  switch(pname) {
  case 0x1200:
    *(float *)(lightState + 0x2820) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(lightState + 0x2824) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x2828) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x282c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 600);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28c);
    }
    dirtyWordBase = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordBase + 0x324) = *(uint *)(dirtyWordBase + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 600);
    break;
  case 0x1201:
    *(float *)(lightState + 0x2830) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(lightState + 0x2834) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x2838) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x283c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x259);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28d);
    }
    dirtyWordBase = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordBase + 0x324) = *(uint *)(dirtyWordBase + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x259);
    break;
  case 0x1202:
    *(float *)(lightState + 0x2840) =
         (float)((double)(float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) -
                                DOUBLE_00108d58) * DOUBLE_00108d88);
    *(float *)(lightState + 0x2844) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x2848) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(float *)(lightState + 0x284c) =
         (float)((double)(float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic) *
                colorScale);
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25a);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28e);
    }
    dirtyWordBase = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordBase + 0x324) = *(uint *)(dirtyWordBase + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25a);
    break;
  case 0x1203:
    *(float *)(lightState + 0x2850) =
         (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(lightState + 0x2854) =
         (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
    *(float *)(lightState + 0x2858) =
         (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
    positionY = *(float *)(lightState + 0x2854);
    positionX = *(float *)(lightState + 0x2850);
    positionZ = *(float *)(lightState + 0x2858);
    paramValue = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
    *(float *)(lightState + 0x285c) = paramValue;
    *(float *)(lightState + 0x2850) =
         paramValue * *(float *)(glContext + 0x1cf0) +
         (positionZ * *(float *)(glContext + 0x1ce0) +
         (positionX * *(float *)(glContext + 0x1cc0) + positionY * *(float *)(glContext + 0x1cd0)));
    *(float *)(lightState + 0x2854) =
         paramValue * *(float *)(glContext + 0x1cf4) +
         (positionZ * *(float *)(glContext + 0x1ce4) +
         (positionX * *(float *)(glContext + 0x1cc4) + positionY * *(float *)(glContext + 0x1cd4)));
    *(float *)(lightState + 0x2858) =
         paramValue * *(float *)(glContext + 0x1cf8) +
         (positionZ * *(float *)(glContext + 0x1ce8) +
         (positionX * *(float *)(0x1cc8 + glContext) + positionY * *(float *)(glContext + 0x1cd8)));
    *(float *)(lightState + 0x285c) =
         paramValue * *(float *)(glContext + 0x1cfc) +
         (positionZ * *(float *)(glContext + 0x1cec) +
         (positionX * *(float *)(glContext + 0x1ccc) + positionY * *(float *)(glContext + 0x1cdc)));
    ((double (*)())_gleUpdateLightPosition)(glContext,lightIndex,forwardedFloatArg1);
    goto LAB_0006c730;
  case 0x1204:
    *(float *)(lightState + 0x2860) =
         (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    *(float *)(lightState + 0x2864) =
         (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
    *(float *)(lightState + 0x2868) =
         (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
    ((void (*)())_gleTransformLightDirection)(glContext,lightIndex,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
               forwardedFloatArg8,incomingStack_ffffffa8,incomingStack_ffffffb0);
    goto LAB_0006c730;
  case 0x1205:
    paramValue = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    if ((paramValue < FLOAT_00108e50) ||
       ((float)((double)CONCAT44(0x43300000,
                                 *(uint *)(*(int *)(glContext + 0x468c) + 0xa4) ^ 0x80000000) -
               DOUBLE_00108d58) < paramValue)) goto LAB_0006c6f0;
    *(float *)(lightState + 0x287c) = paramValue;
    _gleUpdateLightExponents(glContext,lightIndex);
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25d);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
    }
    dirtyWordBase = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordBase + 0x324) = *(uint *)(dirtyWordBase + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25d);
    break;
  case 0x1206:
    paramValue = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    if ((FLOAT_00108e50 <= paramValue) && (paramValue <= FLOAT_00108e88)) {
      *(float *)(lightState + 0x2890) = paramValue;
      cosValue = _cos((double)(paramValue * FLOAT_00108e84));
      *(float *)(lightState + 0x286c) = (float)cosValue;
    }
    else {
      if (paramValue != FLOAT_00108e8c) goto LAB_0006c6f0;
      *(undefined4 *)(lightState + 0x286c) = 0xbf800000;
      *(undefined4 *)(lightState + 0x2890) = 0;
    }
    _gleUpdateLightExponents(glContext,lightIndex);
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25c);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
    }
    dirtyWordBase = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordBase + 0x324) = *(uint *)(dirtyWordBase + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25c);
    break;
  case 0x1207:
    paramValue = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    if (!(paramValue < FLOAT_00108e50)) {
      *(float *)(lightState + 0x2870) = paramValue;
LAB_0006c708:
      _gleUpdateLightAttenuation(glContext,lightIndex);
      goto LAB_0006c730;
    }
    goto LAB_0006c6f0;
  case 0x1208:
    paramValue = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    if (!(paramValue < FLOAT_00108e50)) {
      *(float *)(lightState + 0x2874) = paramValue;
      goto LAB_0006c708;
    }
    goto LAB_0006c6f0;
  case 0x1209:
    paramValue = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
    if (!(paramValue < FLOAT_00108e50)) {
      *(float *)(lightState + 0x2878) = paramValue;
      goto LAB_0006c708;
    }
LAB_0006c6f0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_0006c728:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  default:
    goto switchD_0006bed0_default;
  }
  dirtyWordBase2 = (dirtyBitIndex2 >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordBase2 + 0x348) = *(uint *)(dirtyWordBase2 + 0x348) | 1 << (dirtyBitIndex2 & 0x1f);
LAB_0006c730:
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 4 << (lightIndex * 2 & 0x3e);
  return;
}

/* _glLightiv_CompExec @ 0x6c75c (72 bytes) */
void _glLightiv_CompExec(glContext, light, pname, params)
  undefined4 glContext;
  undefined4 light;
  undefined4 pname;
  undefined4 params;
{
  unsigned int ghidra_home[8] = { glContext, light, pname, params, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glLightiv_Comp)(glContext,light,pname,params);
  ((void (*)())_glLightiv_Exec)(glContext,light,pname,params,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
                  ,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
                  (*(double *)((unsigned char *)ghidra_home + 8)));
  return;
}

/* _glGetLightfv_Exec @ 0x6c7a4 (340 bytes) */
void _glGetLightfv_Exec(glContext, light, pname, params)
  int glContext;
  int light;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006c7f0;
  }
  if (7 < light - 0x4000U) {
switchD_0006c828_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0006c7f0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  iVar2 = glContext + (light - 0x4000U) * 0x80;
  switch(pname) {
  case 0x1200:
    *params = *(undefined4 *)(iVar2 + 0x2820);
    params[1] = *(undefined4 *)(iVar2 + 0x2824);
    params[2] = *(undefined4 *)(iVar2 + 0x2828);
    uVar1 = *(undefined4 *)(iVar2 + 0x282c);
    goto LAB_0006c890;
  case 0x1201:
    *params = *(undefined4 *)(iVar2 + 0x2830);
    params[1] = *(undefined4 *)(iVar2 + 0x2834);
    params[2] = *(undefined4 *)(iVar2 + 0x2838);
    uVar1 = *(undefined4 *)(iVar2 + 0x283c);
    goto LAB_0006c890;
  case 0x1202:
    *params = *(undefined4 *)(iVar2 + 0x2840);
    params[1] = *(undefined4 *)(iVar2 + 0x2844);
    params[2] = *(undefined4 *)(iVar2 + 0x2848);
    uVar1 = *(undefined4 *)(iVar2 + 0x284c);
    goto LAB_0006c890;
  case 0x1203:
    *params = *(undefined4 *)(iVar2 + 0x2850);
    params[1] = *(undefined4 *)(iVar2 + 0x2854);
    params[2] = *(undefined4 *)(iVar2 + 0x2858);
    uVar1 = *(undefined4 *)(iVar2 + 0x285c);
LAB_0006c890:
    params[3] = uVar1;
    return;
  case 0x1204:
    *params = *(undefined4 *)(iVar2 + 0x2860);
    params[1] = *(undefined4 *)(iVar2 + 0x2864);
    params[2] = *(undefined4 *)(iVar2 + 0x2868);
    return;
  case 0x1205:
    uVar1 = *(undefined4 *)(iVar2 + 0x287c);
    break;
  case 0x1206:
    uVar1 = *(undefined4 *)(iVar2 + 0x2890);
    break;
  case 0x1207:
    uVar1 = *(undefined4 *)(iVar2 + 0x2870);
    break;
  case 0x1208:
    uVar1 = *(undefined4 *)(iVar2 + 0x2874);
    break;
  case 0x1209:
    uVar1 = *(undefined4 *)(iVar2 + 0x2878);
    break;
  default:
    goto switchD_0006c828_default;
  }
  *params = uVar1;
  return;
}

/* _glGetLightiv_Exec @ 0x6c920 (676 bytes) */
void _glGetLightiv_Exec(glContext, light, pname, params)
  int glContext;
  int light;
  undefined4 pname;
  int *params;
{
  float roundBias;
  float lightParamValue;
  double colorToIntScale;
  undefined4 glErrorCode;
  int lightRecord;
  int spotCutoffInt;
  double fourthComponent;
  
  roundBias = FLOAT_00108e90;
  colorToIntScale = DOUBLE_00108d90;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0006c96c;
  }
  if (7 < light - 0x4000U) {
switchD_0006c9a4_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_0006c96c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  lightRecord = glContext + (light - 0x4000U) * 0x80;
  switch(pname) {
  case 0x1200:
    *params = (int)((double)*(float *)(lightRecord + 0x2820) * DOUBLE_00108d90);
    params[1] = (int)((double)*(float *)(lightRecord + 0x2824) * colorToIntScale);
    params[2] = (int)((double)*(float *)(lightRecord + 0x2828) * colorToIntScale);
    fourthComponent = (double)*(float *)(lightRecord + 0x282c);
    goto LAB_0006ca7c;
  case 0x1201:
    *params = (int)((double)*(float *)(lightRecord + 0x2830) * DOUBLE_00108d90);
    params[1] = (int)((double)*(float *)(lightRecord + 0x2834) * colorToIntScale);
    params[2] = (int)((double)*(float *)(lightRecord + 0x2838) * colorToIntScale);
    fourthComponent = (double)*(float *)(lightRecord + 0x283c);
    goto LAB_0006ca7c;
  case 0x1202:
    *params = (int)((double)*(float *)(lightRecord + 0x2840) * DOUBLE_00108d90);
    params[1] = (int)((double)*(float *)(lightRecord + 0x2844) * colorToIntScale);
    params[2] = (int)((double)*(float *)(lightRecord + 0x2848) * colorToIntScale);
    fourthComponent = (double)*(float *)(lightRecord + 0x284c);
LAB_0006ca7c:
    fourthComponent = fourthComponent * colorToIntScale;
LAB_0006ca80:
    params[3] = (int)fourthComponent;
    return;
  case 0x1203:
    *params = (int)*(float *)(lightRecord + 0x2850);
    params[1] = (int)*(float *)(lightRecord + 0x2854);
    params[2] = (int)*(float *)(lightRecord + 0x2858);
    fourthComponent = (double)*(float *)(lightRecord + 0x285c);
    goto LAB_0006ca80;
  case 0x1204:
    *params = (int)(*(float *)(lightRecord + 0x2860) + FLOAT_00108e90);
    params[1] = (int)(*(float *)(lightRecord + 0x2864) + roundBias);
    params[2] = (int)(*(float *)(lightRecord + 0x2868) + roundBias);
    return;
  case 0x1205:
    lightParamValue = *(float *)(lightRecord + 0x287c);
    break;
  case 0x1206:
    lightParamValue = *(float *)(lightRecord + 0x2890);
    if (lightParamValue < FLOAT_00108e50) {
      spotCutoffInt = 0xb4;
      goto LAB_0006cbd4;
    }
    break;
  case 0x1207:
    lightParamValue = *(float *)(lightRecord + 0x2870);
    break;
  case 0x1208:
    lightParamValue = *(float *)(lightRecord + 0x2874);
    break;
  case 0x1209:
    lightParamValue = *(float *)(lightRecord + 0x2878);
    break;
  default:
    goto switchD_0006c9a4_default;
  }
  spotCutoffInt = (int)(lightParamValue + FLOAT_00108e90);
LAB_0006cbd4:
  *params = spotCutoffInt;
  return;
}

/* _glLightModelf_ListExec @ 0x6cbec (44 bytes) */
int _glLightModelf_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glLightModelf_Exec)(glContext,*recordedArgs,(double)GH_U2F((unsigned int)(recordedArgs[1])));
  return 8;
}

/* _glLightModelf_Comp @ 0x6cc18 (92 bytes) */
undefined4 * _glLightModelf_Comp(undefined4 glContext,undefined4 pname,float param)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLightModelf_ListExec_00110154,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glLightModelf_Exec @ 0x6cc74 (500 bytes) */
void _glLightModelf_Exec(int glContext,uint pname,double param)
{
  undefined4 glErrorCode;
  uint uVar2;
  undefined2 uVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0xb52) {
      *(bool *)(glContext + 0x30ac) = param != (double)FLOAT_00108e50;
      _gleUpdatePolyMode(glContext);
      _gleSelectVertexSubmitFunc(glContext);
      _gleSelectVertexAddMaterialFunc(glContext);
    }
    else if (pname < 0xb53) {
      if (pname != 0xb51) goto LAB_0006ce28;
      *(bool *)(glContext + 0x30ad) = param != (double)FLOAT_00108e50;
    }
    else if (pname == 0x81f8) {
      if (DOUBLE_00108d80 <= param) {
        uVar2 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar2 = (uint)(int)param;
      }
      if (1 < uVar2 - 0x81f9) goto LAB_0006ce28;
      if (DOUBLE_00108d80 <= param) {
        uVar3 = (undefined2)(int)(param - DOUBLE_00108d80);
      }
      else {
        uVar3 = (undefined2)(int)param;
      }
      *(undefined2 *)(glContext + 0x30a8) = uVar3;
      if ((*(char *)(glContext + 0x30aa) != '\0') && (*(char *)(glContext + 0x4664) == '\0')) {
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
        *(bool *)(glContext + 0x316b) = *(short *)(glContext + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (pname != 0x85b0) {
LAB_0006ce28:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006ce38;
      }
      *(bool *)(glContext + 0x30ae) = param != (double)FLOAT_00108e50;
    }
    _gleUpdateLightModel(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 1;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0006ce38:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glLightModelf_CompExec @ 0x6ce68 (72 bytes) */
void _glLightModelf_CompExec(undefined4 glContext,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glLightModelf_Comp)(glContext,pname,param);
  ((void (*)())_glLightModelf_Exec)(glContext,pname,param);
  return;
}

/* _glLightModelfv_ListExec @ 0x6ceb0 (48 bytes) */
int _glLightModelfv_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glLightModelfv_Exec(glContext,*recordedArgs,recordedArgs + 1);
  return 0x14;
}

