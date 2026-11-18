#include "decls.h"

/* _glDrawArrays_CompExec @ 0xa8624 (72 bytes) */
void _glDrawArrays_CompExec(glContext, mode, first, count)
  undefined4 glContext;
  undefined4 mode;
  undefined4 first;
  undefined4 count;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glDrawArrays_Comp(glContext,mode,first,count);
  ((void (*)())_glDrawArrays_Exec)(glContext,mode,first,count,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                     incomingFpr8);
  return;
}

/* _glDrawArrays_NoopExec @ 0xa866c (684 bytes) */
void _glDrawArrays_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 first,undefined4 count,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a88d8;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = first;
  uVar6 = count;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a88bc:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glDrawArrays_Exec)(glContext,forwardedArg2,first,count,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                         forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a87a8:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a87a8;
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
    if (stateClean) goto LAB_000a88bc;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a88a0:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a88bc;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a88a0;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a88a0;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a88d8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawElements_Comp @ 0xa8918 (132 bytes) */
int _glDrawElements_Comp(glContext, mode, count, type, indices)
  int glContext;
  undefined4 mode;
  undefined4 count;
  uint type;
  int indices;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return glContext;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return glContext;
    }
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  uVar3 = _gleDrawArraysOrElements_Comp(glContext,mode,0,count);
  return uVar3;
}

/* _glDrawElements_IMM_Exec @ 0xa899c (136 bytes) */
void _glDrawElements_IMM_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(glContext,forwardedArg2,0,forwardedArg3,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_VBO_Exec @ 0xa8a24 (136 bytes) */
void _glDrawElements_VBO_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  ((void (*)())_gleDrawArraysOrElements_VBO_Exec)(glContext,forwardedArg2,0,forwardedArg3,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_VAR_Exec @ 0xa8aac (136 bytes) */
void _glDrawElements_VAR_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,uint param_4,int param_5,undefined4 unusedArg6,undefined4 forwardedArg7,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (param_4 != 0x1403) {
    if (param_4 < 0x1404) {
      bVar1 = param_4 == 0x1401;
    }
    else {
      bVar1 = param_4 == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  if (param_4 != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = param_4;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    param_5 = param_5 + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = param_5;
  *(int *)(glContext + 0x4978) = param_5;
  ((void (*)())_gleDrawArraysOrElements_VAR_Exec)(glContext,forwardedArg2,0,forwardedArg3,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedArg7,forwardedFloatArg1,forwardedFloatArg2
             ,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_CVA_Exec @ 0xa8b34 (136 bytes) */
void _glDrawElements_CVA_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  ((void (*)())_gleDrawArraysOrElements_CVA_Exec)(glContext,forwardedArg2,0,forwardedArg3,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_STD_Exec @ 0xa8bbc (136 bytes) */
void _glDrawElements_STD_Exec(int glContext,undefined4 forwardedArg2,undefined4 forwardedArg3,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  ((void (*)())_gleDrawArraysOrElements_Exec)(glContext,forwardedArg2,0,forwardedArg3,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_Exec @ 0xa8c44 (136 bytes) */
void _glDrawElements_Exec(int glContext,undefined4 mode,undefined4 count,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  int iVar2;
  
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x500;
      return;
    }
  }
  iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar2 != 0) {
    indices = indices + *(int *)(iVar2 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  ((void (*)())_gleEvalDrawArraysOrElements_Entires_Exec)(glContext,mode,0,count,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElements_CompExec @ 0xa8ccc (80 bytes) */
void _glDrawElements_CompExec(glContext, mode, count, type, indices)
  undefined4 glContext;
  undefined4 mode;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glDrawElements_Comp)(glContext,mode,count,type,indices);
  ((void (*)())_glDrawElements_Exec)(glContext,mode,count,type,indices,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
             incomingFpr8);
  return;
}

/* _glDrawElements_NoopExec @ 0xa8d1c (692 bytes) */
void _glDrawElements_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 count,undefined4 type,undefined4 indices,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a8f8c;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = count;
  uVar6 = type;
  uVar7 = indices;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a8f70:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glDrawElements_Exec)(glContext,forwardedArg2,count,type,indices,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                 forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a8e5c:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a8e5c;
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
    if (stateClean) goto LAB_000a8f70;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a8f54:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a8f70;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a8f54;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a8f54;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a8f8c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawRangeElements_Comp @ 0xa8fd0 (48 bytes) */
int _glDrawRangeElements_Comp(glContext, mode, start, end, count, type, indices)
  int glContext;
  undefined4 mode;
  uint start;
  uint end;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
{
  undefined4 uVar1;
  
  if (start <= end) {
    uVar1 = ((int (*)())_glDrawElements_Comp)(glContext,mode,count,type,indices);
    return uVar1;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return glContext;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return glContext;
}

/* _glDrawRangeElements_IMM_Exec @ 0xa9000 (168 bytes) */
void _glDrawRangeElements_IMM_Exec(int glContext,undefined4 forwardedArg2,uint start,uint end,undefined4 forwardedArg5,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (end < start) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000a9058:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000a9058;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    indices = indices + *(int *)(iVar3 + 0x30);
  }
  *(int *)(glContext + 0x4978) = indices;
  *(int *)(glContext + 0x48d8) = indices;
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(glContext,forwardedArg2,0,forwardedArg5,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawRangeElements_VBO_Exec @ 0xa90a8 (168 bytes) */
void _glDrawRangeElements_VBO_Exec(int glContext,undefined4 forwardedArg2,uint start,uint end,undefined4 forwardedArg5,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (end < start) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000a9100:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000a9100;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    indices = indices + *(int *)(iVar3 + 0x30);
  }
  *(int *)(glContext + 0x4978) = indices;
  *(int *)(glContext + 0x48d8) = indices;
  ((void (*)())_gleDrawArraysOrElements_VBO_Exec)(glContext,forwardedArg2,0,forwardedArg5,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawRangeElements_VAR_Exec @ 0xa9150 (168 bytes) */
void _glDrawRangeElements_VAR_Exec(int glContext,undefined4 forwardedArg2,uint start,uint end,undefined4 forwardedArg5,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (end < start) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000a91a8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000a91a8;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    indices = indices + *(int *)(iVar3 + 0x30);
  }
  *(int *)(glContext + 0x4978) = indices;
  *(int *)(glContext + 0x48d8) = indices;
  ((void (*)())_gleDrawArraysOrElements_VAR_Exec)(glContext,forwardedArg2,0,forwardedArg5,1,*(int *)(glContext + 0x4a60) + 0x10,indices,forwardedFloatArg1,forwardedFloatArg2
             ,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawRangeElements_CVA_Exec @ 0xa91f8 (168 bytes) */
void _glDrawRangeElements_CVA_Exec(int glContext,undefined4 forwardedArg2,uint start,uint end,undefined4 forwardedArg5,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (end < start) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000a9250:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000a9250;
    }
  }
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    indices = indices + *(int *)(iVar3 + 0x30);
  }
  *(int *)(glContext + 0x4978) = indices;
  *(int *)(glContext + 0x48d8) = indices;
  ((void (*)())_gleDrawArraysOrElements_CVA_Exec)(glContext,forwardedArg2,0,forwardedArg5,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawRangeElements_Exec @ 0xa92a0 (168 bytes) */
void _glDrawRangeElements_Exec(int glContext,undefined4 mode,uint start,uint end,undefined4 count,uint type,int indices,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  
  if (end < start) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_000a92f8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (type != 0x1403) {
    if (type < 0x1404) {
      bVar1 = type == 0x1401;
    }
    else {
      bVar1 = type == 0x1405;
    }
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000a92f8;
    }
  }
  iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
  if (iVar3 != 0) {
    indices = indices + *(int *)(iVar3 + 0x30);
  }
  *(int *)(glContext + 0x48d8) = indices;
  *(int *)(glContext + 0x4978) = indices;
  if (type != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = type;
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  ((void (*)())_gleEvalDrawArraysOrElements_Entires_Exec)(glContext,mode,0,count,1,*(int *)(glContext + 0x4a60) + 0x10,forwardedFloatArg1,forwardedFloatArg2,
             forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawRangeElements_CompExec @ 0xa9348 (96 bytes) */
void _glDrawRangeElements_CompExec(glContext, mode, start, end, count, type, indices)
  undefined4 glContext;
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glDrawRangeElements_Comp)(glContext,mode,start,end,count,type,indices);
  ((void (*)())_glDrawRangeElements_Exec)(glContext,mode,start,end,count,type,indices,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,
             incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glDrawRangeElements_NoopExec @ 0xa93a8 (708 bytes) */
void _glDrawRangeElements_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 start,undefined4 end,undefined4 count,undefined4 type,undefined4 forwardedArg7,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a9620;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = start;
  uVar6 = end;
  uVar7 = count;
  uVar8 = type;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a9604:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glDrawRangeElements_Exec)(glContext,forwardedArg2,start,end,count,type,forwardedArg7,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,uVar8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a94f0:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a94f0;
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
    if (stateClean) goto LAB_000a9604;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a95e8:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a9604;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a95e8;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a95e8;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a9620:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawRangeElementArrayAPPLE_Comp @ 0xa966c (44 bytes) */
int _glDrawRangeElementArrayAPPLE_Comp(glContext, mode, start, end, first, count)
  int glContext;
  undefined4 mode;
  uint start;
  uint end;
  undefined4 first;
  undefined4 count;
{
  undefined4 uVar1;
  
  if (start <= end) {
    uVar1 = ((int (*)())_glDrawElementArrayAPPLE_Comp)(glContext,mode,first,count);
    return uVar1;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return glContext;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return glContext;
}

/* _glDrawRangeElementArrayAPPLE_Exec @ 0xa9698 (44 bytes) */
void _glDrawRangeElementArrayAPPLE_Exec(int glContext,undefined4 mode,uint start,uint end,undefined4 first,undefined4 count,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (start <= end) {
    ((void (*)())_glDrawElementArrayAPPLE_Exec)(glContext,mode,first,count,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6
               ,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glDrawRangeElementArrayAPPLE_CompExec @ 0xa96c4 (88 bytes) */
void _glDrawRangeElementArrayAPPLE_CompExec(glContext, mode, start, end, first, count)
  undefined4 glContext;
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 first;
  undefined4 count;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glDrawRangeElementArrayAPPLE_Comp)(glContext,mode,start,end,first,count);
  ((void (*)())_glDrawRangeElementArrayAPPLE_Exec)(glContext,mode,start,end,first,count,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
             incomingFpr7,incomingFpr8);
  return;
}

/* _glDrawRangeElementArrayAPPLE_NoopExec @ 0xa971c (700 bytes) */
void _glDrawRangeElementArrayAPPLE_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 start,undefined4 end,undefined4 first,undefined4 count,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a9990;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = start;
  uVar6 = end;
  uVar7 = first;
  uVar8 = count;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a9974:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glDrawRangeElementArrayAPPLE_Exec)(glContext,forwardedArg2,start,end,first,count,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4
                 ,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,uVar8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a9860:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a9860;
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
    if (stateClean) goto LAB_000a9974;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a9958:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a9974;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a9958;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a9958;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a9990:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_Comp @ 0xa99d8 (48 bytes) */
int _glMultiDrawRangeElementArrayAPPLE_Comp(glContext, mode, start, end, first, count, primcount)
  int glContext;
  undefined4 mode;
  uint start;
  uint end;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
{
  undefined4 uVar1;
  
  if (start <= end) {
    uVar1 = ((int (*)())_glMultiDrawElementArrayAPPLE_Comp)(glContext,mode,first,count,primcount);
    return uVar1;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return glContext;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return glContext;
}

/* _glMultiDrawRangeElementArrayAPPLE_Exec @ 0xa9a08 (48 bytes) */
void _glMultiDrawRangeElementArrayAPPLE_Exec(int glContext,undefined4 mode,uint start,uint end,undefined4 first,undefined4 count,undefined4 primcount,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (start <= end) {
    ((void (*)())_glMultiDrawElementArrayAPPLE_Exec)(glContext,mode,first,count,primcount,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
               forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x501;
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_CompExec @ 0xa9a38 (96 bytes) */
void _glMultiDrawRangeElementArrayAPPLE_CompExec(glContext, mode, start, end, first, count, primcount)
  undefined4 glContext;
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMultiDrawRangeElementArrayAPPLE_Comp)(glContext,mode,start,end,first,count,primcount);
  ((void (*)())_glMultiDrawRangeElementArrayAPPLE_Exec)(glContext,mode,start,end,first,count,primcount,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,
             incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE_NoopExec @ 0xa9a98 (708 bytes) */
void _glMultiDrawRangeElementArrayAPPLE_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 start,undefined4 end,undefined4 first,undefined4 count,undefined4 forwardedArg7,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000a9d10;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = start;
  uVar6 = end;
  uVar7 = first;
  uVar8 = count;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000a9cf4:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawRangeElementArrayAPPLE_Exec)(glContext,forwardedArg2,start,end,first,count,forwardedArg7,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,uVar8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a9be0:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a9be0;
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
    if (stateClean) goto LAB_000a9cf4;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000a9cd8:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000a9cf4;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000a9cd8;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000a9cd8;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000a9d10:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDrawElementArrayAPPLE_Comp @ 0xa9d5c (84 bytes) */
int _glDrawElementArrayAPPLE_Comp(glContext, mode, first, count)
  int glContext;
  undefined4 mode;
  undefined4 first;
  undefined4 count;
{
  int clientState;
  undefined4 uVar2;
  int iVar3;
  
  clientState = *(int *)(glContext + 0x4a60);
  iVar3 = *(int *)(clientState + 0xd8);
  if (*(int *)(clientState + 0x35c) != 0) {
    iVar3 = iVar3 + *(int *)(*(int *)(clientState + 0x35c) + 0x30);
  }
  *(int *)(glContext + 0x48d8) = iVar3;
  *(int *)(glContext + 0x4978) = iVar3;
  if ((uint)*(ushort *)(clientState + 0xe0) != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = (uint)*(ushort *)(clientState + 0xe0);
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  uVar2 = _gleDrawArraysOrElements_Comp(glContext,mode,first,count);
  return uVar2;
}

/* _glDrawElementArrayAPPLE_Exec @ 0xa9db0 (84 bytes) */
void _glDrawElementArrayAPPLE_Exec(int glContext,undefined4 mode,undefined4 first,undefined4 count,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int clientState;
  int iVar2;
  
  clientState = *(int *)(glContext + 0x4a60);
  iVar2 = *(int *)(clientState + 0xd8);
  if (*(int *)(clientState + 0x35c) != 0) {
    iVar2 = iVar2 + *(int *)(*(int *)(clientState + 0x35c) + 0x30);
  }
  *(int *)(glContext + 0x48d8) = iVar2;
  *(int *)(glContext + 0x4978) = iVar2;
  if ((uint)*(ushort *)(clientState + 0xe0) != *(uint *)(glContext + 0x48dc)) {
    *(uint *)(glContext + 0x48dc) = (uint)*(ushort *)(clientState + 0xe0);
    *(undefined4 *)(glContext + 0x488c) = 0;
    *(undefined4 *)(glContext + 0x4890) = 0;
  }
  ((void (*)())_gleDrawArraysOrElements_Exec)(glContext,mode,first,count,2,clientState + 0x10,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glDrawElementArrayAPPLE_CompExec @ 0xa9e04 (72 bytes) */
void _glDrawElementArrayAPPLE_CompExec(glContext, mode, first, count)
  undefined4 glContext;
  undefined4 mode;
  undefined4 first;
  undefined4 count;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glDrawElementArrayAPPLE_Comp)(glContext,mode,first,count);
  ((void (*)())_glDrawElementArrayAPPLE_Exec)(glContext,mode,first,count,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
  return;
}

/* _glDrawElementArrayAPPLE_NoopExec @ 0xa9e4c (684 bytes) */
void _glDrawElementArrayAPPLE_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 first,undefined4 count,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000aa0b8;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = first;
  uVar6 = count;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000aa09c:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glDrawElementArrayAPPLE_Exec)(glContext,forwardedArg2,first,count,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                 forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,incomingR7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000a9f88:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000a9f88;
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
    if (stateClean) goto LAB_000aa09c;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000aa080:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000aa09c;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000aa080;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000aa080;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000aa0b8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMultiDrawElementArrayAPPLE_Comp @ 0xaa0f8 (208 bytes) */
int _glMultiDrawElementArrayAPPLE_Comp(glContext, mode, first, count, primcount)
  int glContext;
  undefined4 mode;
  int first;
  int count;
  int primcount;
{
  int iVar1;
  int loopIndex;
  int iVar2;
  int clientState;
  
  clientState = *(int *)(glContext + 0x4a60);
  iVar1 = *(int *)(clientState + 0xd8);
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    if (*(int *)(clientState + 0x35c) != 0) {
      iVar1 = iVar1 + *(int *)(*(int *)(clientState + 0x35c) + 0x30);
    }
    *(int *)(glContext + 0x48d8) = iVar1;
    *(int *)(glContext + 0x4978) = iVar1;
    if ((uint)*(ushort *)(clientState + 0xe0) != *(uint *)(glContext + 0x48dc)) {
      *(uint *)(glContext + 0x48dc) = (uint)*(ushort *)(clientState + 0xe0);
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(undefined4 *)(glContext + 0x4890) = 0;
    }
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar2 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        _gleDrawArraysOrElements_Comp
                  (glContext,mode,*(undefined4 *)(first + iVar2),*(undefined4 *)(count + iVar2)
                  );
      } while (loopIndex < primcount);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_Exec @ 0xaa1c8 (212 bytes) */
void _glMultiDrawElementArrayAPPLE_Exec(int glContext,undefined4 mode,int first,int count,int primcount,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int clientState;
  double extraout_f1;
  
  clientState = *(int *)(glContext + 0x4a60);
  iVar2 = *(int *)(clientState + 0xd8);
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    if (*(int *)(clientState + 0x35c) != 0) {
      iVar2 = iVar2 + *(int *)(*(int *)(clientState + 0x35c) + 0x30);
    }
    *(int *)(glContext + 0x48d8) = iVar2;
    *(int *)(glContext + 0x4978) = iVar2;
    if ((uint)*(ushort *)(clientState + 0xe0) != *(uint *)(glContext + 0x48dc)) {
      *(uint *)(glContext + 0x48dc) = (uint)*(ushort *)(clientState + 0xe0);
      *(undefined4 *)(glContext + 0x488c) = 0;
      *(undefined4 *)(glContext + 0x4890) = 0;
    }
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        ((void (*)())_gleDrawArraysOrElements_Exec)(glContext,mode,*(undefined4 *)(first + iVar1),*(undefined4 *)(count + iVar1)
                   ,2,clientState + 0x10,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                   forwardedFloatArg8);
        fparam_1 = extraout_f1;
      } while (loopIndex < primcount);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_CompExec @ 0xaa29c (152 bytes) */
void _glMultiDrawElementArrayAPPLE_CompExec(glContext, mode, first, count, primcount)
  int glContext;
  undefined4 mode;
  int first;
  int count;
  int primcount;
{
  int iVar1;
  int loopIndex;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar1 = loopIndex * 4;
        ((int (*)())_glDrawElementArrayAPPLE_Comp)(glContext,mode,*(undefined4 *)(iVar1 + first),*(undefined4 *)(iVar1 + count)
                  );
        loopIndex = loopIndex + 1;
        ((void (*)())_glDrawElementArrayAPPLE_Exec)(glContext,mode,*(undefined4 *)(iVar1 + first),*(undefined4 *)(iVar1 + count)
                   ,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      } while (loopIndex < primcount);
    }
  }
  return;
}

/* _glMultiDrawElementArrayAPPLE_NoopExec @ 0xaa334 (692 bytes) */
void _glMultiDrawElementArrayAPPLE_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 first,undefined4 count,undefined4 primcount,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000aa5a4;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = first;
  uVar6 = count;
  uVar7 = primcount;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000aa588:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawElementArrayAPPLE_Exec)(glContext,forwardedArg2,first,count,primcount,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                 forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,incomingR8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000aa474:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000aa474;
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
    if (stateClean) goto LAB_000aa588;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000aa56c:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000aa588;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000aa56c;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000aa56c;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000aa5a4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMultiDrawArrays_Comp @ 0xaa5e8 (132 bytes) */
int _glMultiDrawArrays_Comp(glContext, mode, first, count, primcount)
  int glContext;
  undefined4 mode;
  int first;
  int count;
  int primcount;
{
  int iVar1;
  int loopIndex;
  
  iVar1 = glContext;
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        iVar1 = _glDrawArrays_Comp(glContext,mode,*(undefined4 *)(first + iVar1),
                                   *(undefined4 *)(count + iVar1));
      } while (loopIndex < primcount);
    }
  }
  return iVar1;
}

/* _glMultiDrawArrays_Exec @ 0xaa66c (132 bytes) */
void _glMultiDrawArrays_Exec(int glContext,undefined4 mode,int first,int count,int primcount,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int iVar1;
  int loopIndex;
  double extraout_f1;
  
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        ((void (*)())_glDrawArrays_STD_Exec)(glContext,mode,*(undefined4 *)(first + iVar1),*(undefined4 *)(count + iVar1)
                   ,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        fparam_1 = extraout_f1;
      } while (loopIndex < primcount);
    }
  }
  return;
}

/* _glMultiDrawArrays_CompExec @ 0xaa6f0 (80 bytes) */
void _glMultiDrawArrays_CompExec(glContext, mode, first, count, primcount)
  undefined4 glContext;
  undefined4 mode;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMultiDrawArrays_Comp)(glContext,mode,first,count,primcount);
  ((void (*)())_glMultiDrawArrays_Exec)(glContext,mode,first,count,primcount,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
             incomingFpr8);
  return;
}

/* _glMultiDrawArrays_NoopExec @ 0xaa740 (692 bytes) */
void _glMultiDrawArrays_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 first,undefined4 count,undefined4 primcount,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool rendererInfoByte79Zero;
  bool stateClean;
  char rendererInfoByte79;
  undefined4 forwardedFirst;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 forwardedCount;
  undefined4 forwardedPrimcount;
  undefined4 incomingR8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double f1AfterCall;
  double f1AfterCall1;
  double f1AfterCall2;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000aa9b0;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  forwardedFirst = first;
  forwardedCount = count;
  forwardedPrimcount = primcount;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000aa994:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawArrays_Exec)(glContext,forwardedArg2,first,count,primcount,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                 forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedFirst,forwardedCount,forwardedPrimcount,incomingR8,matrixFuncDirty,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      forwardedFloatArg1 = forwardedFloatArg1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000aa880:
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
          forwardedFloatArg1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          forwardedFloatArg1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000aa880;
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
    if (stateClean) goto LAB_000aa994;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      forwardedFloatArg1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000aa978:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000aa994;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (forwardedFloatArg1 = f1AfterCall2, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000aa978;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    forwardedFloatArg1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000aa978;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000aa9b0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMultiDrawElements_Comp @ 0xaa9f4 (140 bytes) */
int _glMultiDrawElements_Comp(glContext, mode, count, type, indices, primcount)
  int glContext;
  undefined4 mode;
  int count;
  undefined4 type;
  int indices;
  int primcount;
{
  int iVar1;
  int loopIndex;
  
  iVar1 = glContext;
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else {
    loopIndex = 0;
    if (0 < primcount) {
      do {
        iVar1 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        iVar1 = ((int (*)())_glDrawElements_Comp)(glContext,mode,*(undefined4 *)(count + iVar1),type,
                           *(undefined4 *)(indices + iVar1));
      } while (loopIndex < primcount);
    }
  }
  return iVar1;
}

/* _glMultiDrawElements_Exec @ 0xaaa80 (136 bytes) */
void _glMultiDrawElements_Exec(int glContext,undefined4 mode,undefined4 *count,undefined4 type,undefined4 indices,int primcount,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 uVar1;
  double extraout_f1;
  
  if (primcount < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
  }
  else if (0 < primcount) {
    do {
      uVar1 = *count;
      count = count + 1;
      ((void (*)())_glDrawElements_STD_Exec)(glContext,mode,uVar1,type,indices,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,
                 forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      primcount = primcount + -1;
      fparam_1 = extraout_f1;
    } while (primcount != 0);
  }
  return;
}

/* _glMultiDrawElements_CompExec @ 0xaab08 (88 bytes) */
void _glMultiDrawElements_CompExec(glContext, mode, count, type, indices, primcount)
  undefined4 glContext;
  undefined4 mode;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
  undefined4 primcount;
{
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  ((int (*)())_glMultiDrawElements_Comp)(glContext,mode,count,type,indices,primcount);
  ((void (*)())_glMultiDrawElements_Exec)(glContext,mode,count,type,indices,primcount,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,
             incomingFpr7,incomingFpr8);
  return;
}

/* _glMultiDrawElements_NoopExec @ 0xaab60 (700 bytes) */
void _glMultiDrawElements_NoopExec(int glContext,undefined4 forwardedArg2,undefined4 count,undefined4 type,undefined4 indices,undefined4 primcount,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  bool bVar1;
  bool stateClean;
  char cVar2;
  undefined4 uVar3;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int matrixFuncDirty;
  int remaining;
  int loopIndex;
  uint dirtyWord3ThenMasked;
  uint dispatchFlags;
  int *dirtyFlagWords;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000aadd4;
  }
  matrixFuncDirty = *(int *)(glContext + 0x50ac);
  uVar3 = count;
  uVar6 = type;
  uVar7 = indices;
  uVar8 = primcount;
  if (matrixFuncDirty != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') {
LAB_000aadb8:
    if (*(char *)(glContext + 0x759d) != '\0') {
      ((void (*)())_glMultiDrawElements_Exec)(glContext,forwardedArg2,count,type,indices,primcount,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4
                 ,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      return;
    }
  }
  else {
    framebufferObject = *(int *)(glContext + 0x744c);
    dirtyFlagWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,uVar6,uVar7,uVar8,matrixFuncDirty,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000aaca4:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000aaca4;
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
    if (stateClean) goto LAB_000aadb8;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000aad9c:
      remaining = 0x13;
      do {
        *dirtyFlagWords = 0;
        dirtyFlagWords = dirtyFlagWords + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000aadb8;
    }
    dispatchFlags = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,dirtyFlagWords);
    if ((((dispatchFlags & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((dispatchFlags & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (dispatchFlags & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000aad9c;
    if ((dispatchFlags & 4) == 0) {
      dispatchFlags = dispatchFlags & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000aad9c;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x506;
LAB_000aadd4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glWeightARB_ListExec @ 0xaae1c (100 bytes) */
int _glWeightARB_ListExec(glContext, listRecord)
  int glContext;
  int *listRecord;
{
  int iVar1;
  int *dstCursor;
  int iVar3;
  int iVar4;
  int remaining;
  
  iVar3 = *listRecord;
  iVar4 = 0;
  if (0 < iVar3) {
    dstCursor = (int *)(glContext + 0x2d0);
    remaining = iVar3;
    do {
      listRecord = listRecord + 1;
      *dstCursor = *listRecord;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    iVar4 = iVar3;
    if (3 < iVar3) goto LAB_000aae74;
  }
  do {
    iVar1 = iVar4 * 4;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar1 + glContext + 0x2d0) = 0;
  } while (iVar4 < 4);
LAB_000aae74:
  return iVar3 * 4 + 4;
}

/* _glWeightbvARB_Exec @ 0xaae80 (188 bytes) */
double _glWeightbvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  int weights;
{
  char *pcVar1;
  int iVar2;
  double intToDoubleBias;
  float channelScale;
  float fVar5;
  float *dstCursor;
  int loopIndex;
  
  fVar5 = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  intToDoubleBias = DOUBLE_00108d58;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  loopIndex = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    do {
      pcVar1 = (char *)(weights + loopIndex);
      loopIndex = loopIndex + 1;
      *dstCursor = (float)((double)CONCAT44(0x43300000,(int)*pcVar1 ^ 0x80000000) - intToDoubleBias) * channelScale +
                fVar5;
      dstCursor = dstCursor + 1;
      size = size + -1;
    } while (size != 0);
    if (3 < loopIndex) {
      return;
    }
  }
  do {
    iVar2 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    *(undefined4 *)(iVar2 + glContext + 0x2d0) = 0;
  } while (loopIndex < 4);
  return;
}

/* _glWeightbvARB_Comp @ 0xaaf3c (216 bytes) */
int _glWeightbvARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  char *pcVar1;
  double intToDoubleBias;
  float channelScale;
  float fVar4;
  int iVar5;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if ((float *)glContext != (float *)0x0) {
      iVar5 = 0;
      *(uint *)glContext = size;
      fVar4 = FLOAT_00108e64;
      channelScale = FLOAT_00108e60;
      intToDoubleBias = DOUBLE_00108d58;
      if (0 < (int)size) {
        glContext = glContext + 4;
        do {
          pcVar1 = (char *)(weights + iVar5);
          iVar5 = iVar5 + 1;
          *(float *)glContext =
               (float)((double)CONCAT44(0x43300000,(int)*pcVar1 ^ 0x80000000) - intToDoubleBias) * channelScale +
               fVar4;
          glContext = glContext + 4;
          size = size - 1;
        } while (size != 0);
      }
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightbvARB_CompExec @ 0xab014 (64 bytes) */
void _glWeightbvARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightbvARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightbvARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightsvARB_Exec @ 0xab054 (192 bytes) */
double _glWeightsvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  short *weights;
{
  short sVar1;
  int iVar2;
  double intToDoubleBias;
  float channelScale;
  float fVar5;
  float *dstCursor;
  int iVar7;
  int remaining;
  
  fVar5 = FLOAT_00108e74;
  channelScale = FLOAT_00108e70;
  intToDoubleBias = DOUBLE_00108d58;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar7 = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    remaining = size;
    do {
      sVar1 = *weights;
      weights = weights + 1;
      *dstCursor = (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - intToDoubleBias) * channelScale +
                fVar5;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    iVar7 = size;
    if (3 < size) {
      return;
    }
  }
  do {
    iVar2 = iVar7 * 4;
    iVar7 = iVar7 + 1;
    *(undefined4 *)(iVar2 + glContext + 0x2d0) = 0;
  } while (iVar7 < 4);
  return;
}

/* _glWeightsvARB_Comp @ 0xab114 (216 bytes) */
int _glWeightsvARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  short sVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if (((float *)glContext != (float *)0x0) &&
       (*(uint *)glContext = size, fVar4 = FLOAT_00108e74, fVar3 = FLOAT_00108e70,
       dVar2 = DOUBLE_00108d58, 0 < (int)size)) {
      glContext = glContext + 4;
      do {
        sVar1 = *(short *)weights;
        weights = weights + 2;
        *(float *)glContext =
             (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - dVar2) * fVar3 + fVar4;
        glContext = glContext + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightsvARB_CompExec @ 0xab1ec (64 bytes) */
void _glWeightsvARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightsvARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightsvARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightivARB_Exec @ 0xab22c (188 bytes) */
double _glWeightivARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  uint *weights;
{
  int iVar1;
  double intToDoubleBias;
  float channelScale;
  float fVar4;
  uint uVar5;
  float *dstCursor;
  int loopIndex;
  
  fVar4 = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  intToDoubleBias = DOUBLE_00108d58;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  loopIndex = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    do {
      uVar5 = *weights;
      loopIndex = loopIndex + 1;
      weights = weights + 1;
      *dstCursor = (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - intToDoubleBias) * channelScale + fVar4;
      dstCursor = dstCursor + 1;
      size = size + -1;
    } while (size != 0);
    if (3 < loopIndex) {
      return;
    }
  }
  do {
    iVar1 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    *(undefined4 *)(iVar1 + glContext + 0x2d0) = 0;
  } while (loopIndex < 4);
  return;
}

/* _glWeightivARB_Comp @ 0xab2e8 (212 bytes) */
int _glWeightivARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  double dVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if (((float *)glContext != (float *)0x0) &&
       (*(uint *)glContext = size, fVar3 = FLOAT_00108e6c, fVar2 = FLOAT_00108e68,
       dVar1 = DOUBLE_00108d58, 0 < (int)size)) {
      glContext = glContext + 4;
      do {
        uVar4 = *(uint *)weights;
        weights = weights + 4;
        *(float *)glContext =
             (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
        glContext = glContext + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightivARB_CompExec @ 0xab3bc (64 bytes) */
void _glWeightivARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightivARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightivARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightfvARB_Exec @ 0xab3fc (116 bytes) */
double _glWeightfvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  undefined4 *weights;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *dstCursor;
  int loopIndex;
  
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  loopIndex = 0;
  if (0 < size) {
    dstCursor = (undefined4 *)(glContext + 0x2d0);
    do {
      uVar1 = *weights;
      loopIndex = loopIndex + 1;
      weights = weights + 1;
      *dstCursor = uVar1;
      dstCursor = dstCursor + 1;
      size = size + -1;
    } while (size != 0);
    if (3 < loopIndex) {
      return;
    }
  }
  do {
    iVar2 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    *(undefined4 *)(iVar2 + glContext + 0x2d0) = 0;
  } while (loopIndex < 4);
  return;
}

/* _glWeightfvARB_Comp @ 0xab470 (156 bytes) */
int _glWeightfvARB_Comp(glContext, size, weights)
  int *glContext;
  int size;
  int *weights;
{
  int iVar1;
  
  if (size < 5) {
    glContext = (int *)_gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if ((glContext != (int *)0x0) && (*glContext = size, 0 < size)) {
      glContext = glContext + 1;
      do {
        iVar1 = *weights;
        weights = weights + 1;
        *glContext = iVar1;
        glContext = glContext + 1;
        size = size + -1;
      } while (size != 0);
    }
  }
  else if (glContext[0x1d5d] == 0) {
    glContext[0x1d5d] = 0x501;
  }
  return glContext;
}

/* _glWeightfvARB_CompExec @ 0xab50c (64 bytes) */
void _glWeightfvARB_CompExec(glContext, size, weights)
  undefined4 glContext;
  undefined4 size;
  undefined4 weights;
{
  ((int (*)())_glWeightfvARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightfvARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightdvARB_Exec @ 0xab54c (120 bytes) */
double _glWeightdvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  double *weights;
{
  int iVar1;
  float *dstCursor;
  int iVar3;
  int remaining;
  double dVar4;
  
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  iVar3 = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    remaining = size;
    do {
      dVar4 = *weights;
      weights = weights + 1;
      *dstCursor = (float)dVar4;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    iVar3 = size;
    if (3 < size) {
      return;
    }
  }
  do {
    iVar1 = iVar3 * 4;
    iVar3 = iVar3 + 1;
    *(undefined4 *)(iVar1 + glContext + 0x2d0) = 0;
  } while (iVar3 < 4);
  return;
}

/* _glWeightdvARB_Comp @ 0xab5c4 (160 bytes) */
int _glWeightdvARB_Comp(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  double dVar1;
  
  if ((int)size < 5) {
    glContext = _gleAddListItem(glContext,PTR__glWeightARB_ListExec_0011045c,size * 4 + 4);
    if (((float *)glContext != (float *)0x0) && (*(uint *)glContext = size, 0 < (int)size)) {
      glContext = glContext + 4;
      do {
        dVar1 = *(double *)weights;
        weights = weights + 8;
        *(float *)glContext = (float)dVar1;
        glContext = glContext + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x501;
  }
  return glContext;
}

/* _glWeightdvARB_CompExec @ 0xab664 (64 bytes) */
void _glWeightdvARB_CompExec(glContext, size, weights)
  uint glContext;
  uint size;
  uint weights;
{
  ((int (*)())_glWeightdvARB_Comp)(glContext,size,weights);
  ((double (*)())_glWeightdvARB_Exec)(glContext,size,weights);
  return;
}

/* _glWeightubvARB_Exec @ 0xab6a4 (172 bytes) */
double _glWeightubvARB_Exec(glContext, size, weights)
  int glContext;
  int size;
  int weights;
{
  byte *pbVar1;
  int iVar2;
  float channelScale;
  float *dstCursor;
  int loopIndex;
  
  channelScale = FLOAT_00108e78;
  if (4 < size) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    return;
  }
  loopIndex = 0;
  if (0 < size) {
    dstCursor = (float *)(glContext + 0x2d0);
    do {
      pbVar1 = (byte *)(weights + loopIndex);
      loopIndex = loopIndex + 1;
      *dstCursor = (GH_U2F((unsigned int)((*pbVar1 | 0x4b000000))) - 8388608.0) * channelScale;
      dstCursor = dstCursor + 1;
      size = size + -1;
    } while (size != 0);
    if (3 < loopIndex) {
      return;
    }
  }
  do {
    iVar2 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    *(undefined4 *)(iVar2 + glContext + 0x2d0) = 0;
  } while (loopIndex < 4);
  return;
}

