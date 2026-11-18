#include "decls.h"

/* _glRasterPos2sv_Exec @ 0x809b0 (744 bytes) */
void _glRasterPos2sv_Exec(int glContext,short *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00080b04:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00080b04;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00080c00;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00080c00:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos2sv_CompExec @ 0x80c98 (56 bytes) */
void _glRasterPos2sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glRasterPos2sv_Comp(glContext,v);
  ((void (*)())_glRasterPos2sv_Exec)(glContext,v,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3d_Comp @ 0x80cd0 (40 bytes) */
void _glRasterPos3d_Comp(undefined4 glContext,double x,double y,double z)
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)x,(double)(float)y,(double)(float)z,
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3d_Exec @ 0x80cf8 (744 bytes) */
void _glRasterPos3d_Exec(int glContext,double x,double y,double z,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00080f5c;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_00080f88;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  fparam_3_00 = z;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00080f88;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,
               fparam_3_00,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00080e60:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00080e60;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_00080f5c:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00080f88:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)x,(double)(float)y,(double)(float)z,
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3d_CompExec @ 0x80fe0 (96 bytes) */
void _glRasterPos3d_CompExec(undefined4 glContext,double x,double y,double z)
{
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3d_Comp)(glContext,x,y,z);
  ((void (*)())_glRasterPos3d_Exec)(glContext,x,y,z,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3dv_Comp @ 0x81040 (52 bytes) */
void _glRasterPos3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)*v,(double)(float)v[1],(double)(float)v[2],
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3dv_Exec @ 0x81074 (712 bytes) */
void _glRasterPos3dv_Exec(int glContext,double *v,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000812c4;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_000812f0;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000812f0;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000811c8:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000811c8;
    }
  }
  rendererInfoByte79Zero = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Zero) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Zero) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_000812c4:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_000812f0:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)(*v),(double)(float)(v[1]),
                   (double)(float)(v[2]),(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3dv_CompExec @ 0x8133c (56 bytes) */
void _glRasterPos3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3dv_Comp)(glContext,v);
  ((void (*)())_glRasterPos3dv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3f_Comp @ 0x81374 (28 bytes) */
void _glRasterPos3f_Comp(undefined4 glContext,float x,float y,float z)
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,x,y,z,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3f_Exec @ 0x81390 (744 bytes) */
void _glRasterPos3f_Exec(int glContext,float x,float y,float z,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000815f4;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_00081620;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  fparam_3_00 = z;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00081620;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,
               fparam_3_00,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000814f8:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000814f8;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_000815f4:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00081620:
  ((void (*)())_gleSetRasterPos)(glContext,x,y,z,(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3f_CompExec @ 0x81678 (96 bytes) */
void _glRasterPos3f_CompExec(undefined4 glContext,float x,float y,float z)
{
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3f_Comp)(glContext,x,y,z);
  ((void (*)())_glRasterPos3f_Exec)(glContext,x,y,z,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3fv_Comp @ 0x816d8 (40 bytes) */
void _glRasterPos3fv_Comp(glContext, v)
  undefined4 glContext;
  float *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)*v,(double)v[1],(double)v[2],(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3fv_Exec @ 0x81700 (700 bytes) */
void _glRasterPos3fv_Exec(int glContext,float *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00081950;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_0008197c;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0008197c;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00081854:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00081854;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_00081950:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_0008197c:
  ((void (*)())_gleSetRasterPos)(glContext,(double)*v,(double)v[1],(double)v[2],
                   (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3fv_CompExec @ 0x819bc (56 bytes) */
void _glRasterPos3fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3fv_Comp)(glContext,v);
  ((void (*)())_glRasterPos3fv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3i_Comp @ 0x819f4 (132 bytes) */
void _glRasterPos3i_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3i_Exec @ 0x81a78 (756 bytes) */
void _glRasterPos3i_Exec(int glContext,uint x,uint y,uint z,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  uint uVar6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint uVar8;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      uVar8 = y;
      uVar6 = z;
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar8,uVar6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00081bd4:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00081bd4;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00081cd0;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00081cd0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos3i_CompExec @ 0x81d6c (72 bytes) */
void _glRasterPos3i_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3i_Comp)(glContext,x,y,z);
  ((void (*)())_glRasterPos3i_Exec)(glContext,x,y,z,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                      incomingFpr8);
  return;
}

/* _glRasterPos3iv_Comp @ 0x81db4 (144 bytes) */
void _glRasterPos3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58
                             ),(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3iv_Exec @ 0x81e44 (760 bytes) */
void _glRasterPos3iv_Exec(int glContext,uint *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00081f98:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00081f98;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00082094;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00082094:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos3iv_CompExec @ 0x8213c (56 bytes) */
void _glRasterPos3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3iv_Comp)(glContext,v);
  ((void (*)())_glRasterPos3iv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos3s_Comp @ 0x82174 (132 bytes) */
void _glRasterPos3s_Comp(glContext, x, y, z)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
             (double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3s_Exec @ 0x821f8 (756 bytes) */
void _glRasterPos3s_Exec(int glContext,uint x,uint y,uint z,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  uint forwardedZ;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint forwardedY;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      forwardedY = y;
      forwardedZ = z;
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        forwardedFloatArg1 = f1AfterCall;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedY,forwardedZ,incomingR7,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00082354:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00082354;
          }
        }
        rendererInfoByte79Zero = rendererInfoByte79 == '\0';
        if (rendererInfoByte79Zero) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (rendererInfoByte79Zero) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00082450;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00082450:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos3s_CompExec @ 0x824ec (72 bytes) */
void _glRasterPos3s_CompExec(glContext, x, y, z)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3s_Comp)(glContext,x,y,z);
  ((void (*)())_glRasterPos3s_Exec)(glContext,x,y,z,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                      incomingFpr8);
  return;
}

/* _glRasterPos3sv_Comp @ 0x82534 (144 bytes) */
void _glRasterPos3sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                            DOUBLE_00108d58),(double)FLOAT_00108e54);
  return;
}

/* _glRasterPos3sv_Exec @ 0x825c4 (760 bytes) */
void _glRasterPos3sv_Exec(int glContext,short *v,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        forwardedFloatArg1 = f1AfterCall;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00082718:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00082718;
          }
        }
        rendererInfoByte79Zero = rendererInfoByte79 == '\0';
        if (rendererInfoByte79Zero) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (rendererInfoByte79Zero) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00082814;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00082814:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos3sv_CompExec @ 0x828bc (56 bytes) */
void _glRasterPos3sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos3sv_Comp)(glContext,v);
  ((void (*)())_glRasterPos3sv_Exec)(glContext,v,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4d_Comp @ 0x828f4 (20 bytes) */
void _glRasterPos4d_Comp(undefined4 glContext,double x,double y,double z,double w)
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)x,(double)(float)y,(double)(float)z,
             (double)(float)w);
  return;
}

/* _glRasterPos4d_Exec @ 0x82908 (708 bytes) */
void _glRasterPos4d_Exec(int glContext,double x,double y,double z,double w,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00082bc0;
    glErrorCode = 0x502;
LAB_00082b5c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00082bc0:
    return;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_00082b88;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  fparam_3_00 = z;
  fparam_4_00 = w;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00082b88;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4_00,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00082a60:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00082a60;
    }
  }
  rendererInfoByte79Zero = rendererInfoByte79 == '\0';
  if (rendererInfoByte79Zero) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (rendererInfoByte79Zero) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (stateClean) goto LAB_00082b88;
  if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
        ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
       ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
      if ((dispatchFlags & 4) == 0) {
        dispatchFlags = dispatchFlags & 0xfffffffe;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
      if (*(char *)(glContext + 0x759d) == '\0') {
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00082bc0;
        glErrorCode = 0x506;
        goto LAB_00082b5c;
      }
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(glContext);
  }
  remaining = 0x13;
  do {
    *dirtyFlagWords = 0;
    dirtyFlagWords = dirtyFlagWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_00082b88:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)x,(double)(float)y,(double)(float)z,
                   (double)(float)w);
  return;
}

/* _glRasterPos4d_CompExec @ 0x82bcc (96 bytes) */
void _glRasterPos4d_CompExec(undefined4 glContext,double x,double y,double z,double w)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4d_Comp)(glContext,x,y,z,w);
  ((void (*)())_glRasterPos4d_Exec)(glContext,x,y,z,w,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4dv_Comp @ 0x82c2c (36 bytes) */
void _glRasterPos4dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)*v,(double)(float)v[1],(double)(float)v[2],
             (double)(float)v[3]);
  return;
}

/* _glRasterPos4dv_Exec @ 0x82c50 (704 bytes) */
void _glRasterPos4dv_Exec(int glContext,double *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00082e98;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_00082ec4;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00082ec4;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00082d9c:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00082d9c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_00082e98:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00082ec4:
  ((void (*)())_gleSetRasterPos)(glContext,(double)(float)(*v),(double)(float)(v[1]),
                   (double)(float)(v[2]),(double)(float)(v[3]));
  return;
}

/* _glRasterPos4dv_CompExec @ 0x82f10 (56 bytes) */
void _glRasterPos4dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4dv_Comp)(glContext,v);
  ((void (*)())_glRasterPos4dv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4f_Exec @ 0x82f4c (708 bytes) */
void _glRasterPos4f_Exec(int glContext,float x,float y,float z,float w,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double fparam_1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00083204;
    glErrorCode = 0x502;
LAB_000831a0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00083204:
    return;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_000831cc;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  fparam_1_00 = x;
  fparam_2_00 = y;
  fparam_3_00 = z;
  fparam_4_00 = w;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1_00 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000831cc;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1_00,fparam_2_00,
               fparam_3_00,fparam_4_00,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000830a4:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000830a4;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (stateClean) goto LAB_000831cc;
  if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
        ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
       ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
      if ((dispatchFlags & 4) == 0) {
        dispatchFlags = dispatchFlags & 0xfffffffe;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
      if (*(char *)(glContext + 0x759d) == '\0') {
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00083204;
        glErrorCode = 0x506;
        goto LAB_000831a0;
      }
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(glContext);
  }
  remaining = 0x13;
  do {
    *dirtyFlagWords = 0;
    dirtyFlagWords = dirtyFlagWords + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
LAB_000831cc:
  ((void (*)())_gleSetRasterPos)(glContext,x,y,z,w);
  return;
}

/* _glRasterPos4f_CompExec @ 0x83210 (96 bytes) */
void _glRasterPos4f_CompExec(undefined4 glContext,float x,float y,float z,float w)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glRasterPos4f_Comp(glContext,x,y,z,w);
  ((void (*)())_glRasterPos4f_Exec)(glContext,x,y,z,w,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4fv_Comp @ 0x83270 (20 bytes) */
void _glRasterPos4fv_Comp(glContext, v)
  undefined4 glContext;
  float *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)*v,(double)v[1],(double)v[2],(double)v[3]);
  return;
}

/* _glRasterPos4fv_Exec @ 0x83284 (688 bytes) */
void _glRasterPos4fv_Exec(int glContext,float *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000834cc;
  }
  if ((*(int *)(glContext + 0x744c) == 0) && (-1 < *(int *)(glContext + 0x310))) goto LAB_000834f8;
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000834f8;
  framebufferObject = *(int *)(glContext + 0x744c);
  dirtyFlagWords = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000833d0:
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
    if ((dirtyWord3ThenMasked & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_000833d0;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
  }
  else {
    dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
  }
  if (bVar1) {
    stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!stateClean) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
LAB_000834cc:
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
      *dirtyFlagWords = 0;
      dirtyFlagWords = dirtyFlagWords + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_000834f8:
  ((void (*)())_gleSetRasterPos)(glContext,(double)*v,(double)v[1],(double)v[2],(double)v[3]
                  );
  return;
}

/* _glRasterPos4fv_CompExec @ 0x83534 (56 bytes) */
void _glRasterPos4fv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4fv_Comp)(glContext,v);
  ((void (*)())_glRasterPos4fv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4i_Comp @ 0x8356c (144 bytes) */
void _glRasterPos4i_Comp(glContext, x, y, z, w)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glRasterPos4i_Exec @ 0x835fc (772 bytes) */
void _glRasterPos4i_Exec(int glContext,uint x,uint y,uint z,uint w,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  uint uVar6;
  uint uVar7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint uVar9;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      uVar9 = y;
      uVar6 = z;
      uVar7 = w;
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar9,uVar6,uVar7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0008375c:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_0008375c;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00083858;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00083858:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos4i_CompExec @ 0x83900 (80 bytes) */
void _glRasterPos4i_CompExec(glContext, x, y, z, w)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4i_Comp)(glContext,x,y,z,w);
  ((void (*)())_glRasterPos4i_Exec)(glContext,x,y,z,w,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6
                      ,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4iv_Comp @ 0x83950 (160 bytes) */
void _glRasterPos4iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58)
             ,(double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58
                             ),
             (double)(float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) - DOUBLE_00108d58)
            );
  return;
}

/* _glRasterPos4iv_Exec @ 0x839f0 (776 bytes) */
void _glRasterPos4iv_Exec(int glContext,uint *v,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        forwardedFloatArg1 = f1AfterCall;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00083b44:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00083b44;
          }
        }
        rendererInfoByte79Zero = rendererInfoByte79 == '\0';
        if (rendererInfoByte79Zero) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (rendererInfoByte79Zero) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00083c40;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,v[3] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00083c40:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos4iv_CompExec @ 0x83cf8 (56 bytes) */
void _glRasterPos4iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4iv_Comp)(glContext,v);
  ((void (*)())_glRasterPos4iv_Exec)(glContext,v,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4s_Comp @ 0x83d30 (144 bytes) */
void _glRasterPos4s_Comp(glContext, x, y, z, w)
  undefined4 glContext;
  uint x;
  uint y;
  uint z;
  uint w;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) - DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glRasterPos4s_Exec @ 0x83dc0 (772 bytes) */
void _glRasterPos4s_Exec(int glContext,uint x,uint y,uint z,uint w,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  uint forwardedZ;
  uint forwardedW;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint forwardedY;
  uint dispatchFlags;
  uint dirtyWord3ThenMasked;
  int *dirtyFlagWords;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      forwardedY = y;
      forwardedZ = z;
      forwardedW = w;
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        forwardedFloatArg1 = f1AfterCall;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedY,forwardedZ,forwardedW,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00083f20:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
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
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00083f20;
          }
        }
        rendererInfoByte79Zero = rendererInfoByte79 == '\0';
        if (rendererInfoByte79Zero) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (rendererInfoByte79Zero) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_0008401c;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,z ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,w ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0008401c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos4s_CompExec @ 0x840c4 (80 bytes) */
void _glRasterPos4s_CompExec(glContext, x, y, z, w)
  undefined4 glContext;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4s_Comp)(glContext,x,y,z,w);
  ((void (*)())_glRasterPos4s_Exec)(glContext,x,y,z,w,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6
                      ,incomingFpr7,incomingFpr8);
  return;
}

/* _glRasterPos4sv_Comp @ 0x84114 (160 bytes) */
void _glRasterPos4sv_Comp(glContext, v)
  undefined4 glContext;
  short *v;
{
  ((void (*)())_glSetRasterPos_Comp)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) -
                                    DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                            DOUBLE_00108d58),
             (double)(float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                            DOUBLE_00108d58));
  return;
}

/* _glRasterPos4sv_Exec @ 0x841b4 (776 bytes) */
void _glRasterPos4sv_Exec(int glContext,short *v,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixFuncDirty = *(int *)(glContext + 0x50ac);
      if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        dirtyFlagWords = (int *)(glContext + 0x310);
        cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00084308:
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
        }
        else {
          loopIndex = 0;
          srcCursor = (int *)(glContext + 0x324);
          do {
            iVar5 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar5 != 0) {
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
              break;
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < 9);
          dirtyWord3ThenMasked = *(uint *)(glContext + 0x31c);
          if ((dirtyWord3ThenMasked & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_00084308;
          }
        }
        bVar1 = cVar2 == '\0';
        if (bVar1) {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17000000;
        }
        else {
          dirtyWord3ThenMasked = dirtyWord3ThenMasked & 0x17ffffff;
        }
        if (bVar1) {
          stateClean = ((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        else {
          stateClean = (((*dirtyFlagWords == 0 && *(int *)(glContext + 0x314) == 0) &&
                   (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && dirtyWord3ThenMasked == 0) &&
                  *(int *)(glContext + 800) == 0;
        }
        if (!stateClean) {
          if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
            dispatchFlags = (**(code **)(glContext + 0x4788))
                              (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
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
                goto LAB_00084404;
              }
            }
          }
          else {
            _gleSwitchToNonRevertRenderer(glContext);
          }
          remaining = 0x13;
          do {
            *dirtyFlagWords = 0;
            dirtyFlagWords = dirtyFlagWords + 1;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
      }
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000)
                                            - DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) -
                                    DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,(int)v[3] ^ 0x80000000) -
                                    DOUBLE_00108d58));
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00084404:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glRasterPos4sv_CompExec @ 0x844bc (56 bytes) */
void _glRasterPos4sv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((void (*)())_glRasterPos4sv_Comp)(glContext,v);
  ((void (*)())_glRasterPos4sv_Exec)(glContext,v,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glReadBuffer_ListExec @ 0x844f4 (40 bytes) */
int _glReadBuffer_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glReadBuffer_Exec(glContext,*listRecord);
  return 4;
}

/* _glReadBuffer_Comp @ 0x8451c (76 bytes) */
int _glReadBuffer_Comp(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glReadBuffer_ListExec_00110280,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = mode;
  }
  return listRecord;
}

/* _glReadBuffer_CompExec @ 0x84568 (56 bytes) */
void _glReadBuffer_CompExec(glContext, mode)
  undefined4 glContext;
  undefined4 mode;
{
  ((int (*)())_glReadBuffer_Comp)(glContext,mode);
  _glReadBuffer_Exec(glContext,mode);
  return;
}

/* _glRectd_Comp @ 0x845a0 (148 bytes) */
undefined4 _glRectd_Comp(undefined4 glContext,double x1,double y1,double x2,double y2)
{
  undefined4 uVar1;
  
  _glBegin_Comp(glContext,9);
  ((float * (*)())_glVertex2d_Comp)(glContext,x1,y1);
  ((float * (*)())_glVertex2d_Comp)(glContext,x2,y1);
  ((float * (*)())_glVertex2d_Comp)(glContext,x2,y2);
  ((float * (*)())_glVertex2d_Comp)(glContext,x1,y2);
  uVar1 = _glEnd_Comp(glContext);
  return uVar1;
}

/* _glRectd_CompExec @ 0x84634 (96 bytes) */
void _glRectd_CompExec(undefined4 glContext,double x1,double y1,double x2,double y2)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 (*)())_glRectd_Comp)(glContext,x1,y1,x2,y2);
  ((void (*)())_glRectd_Exec)(glContext,x1,y1,x2,y2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRectf_Comp @ 0x84694 (148 bytes) */
undefined4 _glRectf_Comp(undefined4 glContext,float x1,float y1,float x2,float y2)
{
  undefined4 endResult;
  
  _glBegin_Comp(glContext,9);
  ((float * (*)())_glVertex2f_Comp)(glContext,x1,y1);
  ((float * (*)())_glVertex2f_Comp)(glContext,x2,y1);
  ((float * (*)())_glVertex2f_Comp)(glContext,x2,y2);
  ((float * (*)())_glVertex2f_Comp)(glContext,x1,y2);
  endResult = _glEnd_Comp(glContext);
  return endResult;
}

/* _glRectf_Exec @ 0x84728 (196 bytes) */
void _glRectf_Exec(int glContext,double x1,double y1,double x2,double y2,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,x1,y1,x2,y2,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  ((void (*)())_glVertex2f_Exec)(glContext,x1,y1);
  ((void (*)())_glVertex2f_Exec)(glContext,x2,y1);
  ((void (*)())_glVertex2f_Exec)(glContext,x2,y2);
  ((void (*)())_glVertex2f_Exec)(glContext,x1,y2);
  _glEnd_Exec(glContext);
  return;
}

/* _glRectf_CompExec @ 0x847ec (96 bytes) */
void _glRectf_CompExec(undefined4 glContext,float x1,float y1,float x2,float y2)
{
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((undefined4 (*)())_glRectf_Comp)(glContext,x1,y1,x2,y2);
  ((void (*)())_glRectf_Exec)(glContext,x1,y1,x2,y2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glRecti_Comp @ 0x8484c (132 bytes) */
int _glRecti_Comp(glContext, x1, y1, x2, y2)
  undefined4 glContext;
  undefined4 x1;
  undefined4 y1;
  undefined4 x2;
  undefined4 y2;
{
  undefined4 uVar1;
  
  _glBegin_Comp(glContext,9);
  _glVertex2i_Comp(glContext,x1,y1);
  _glVertex2i_Comp(glContext,x2,y1);
  _glVertex2i_Comp(glContext,x2,y2);
  _glVertex2i_Comp(glContext,x1,y2);
  uVar1 = _glEnd_Comp(glContext);
  return uVar1;
}

/* _glRecti_Exec @ 0x848d0 (188 bytes) */
void _glRecti_Exec(int glContext,undefined4 x1,undefined4 y1,undefined4 x2,undefined4 y2,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return;
  }
  ((void (*)())_glBegin_Exec)(glContext,9,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  _glVertex2i_Exec(glContext,x1,y1);
  _glVertex2i_Exec(glContext,x2,y1);
  _glVertex2i_Exec(glContext,x2,y2);
  _glVertex2i_Exec(glContext,x1,y2);
  _glEnd_Exec(glContext);
  return;
}

/* _glRecti_CompExec @ 0x8498c (80 bytes) */
void _glRecti_CompExec(glContext, x1, y1, x2, y2)
  undefined4 glContext;
  undefined4 x1;
  undefined4 y1;
  undefined4 x2;
  undefined4 y2;
{
  double forwardedFloatArg1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glRecti_Comp)(glContext,x1,y1,x2,y2);
  ((void (*)())_glRecti_Exec)(glContext,x1,y1,x2,y2,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                ,incomingFpr8);
  return;
}

