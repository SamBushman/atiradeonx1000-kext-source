#include "decls.h"

/* _glClientActiveTexture_Exec @ 0x4f0b0 (88 bytes) */
void _glClientActiveTexture_Exec(glContext, texture)
  int glContext;
  int texture;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (texture - 0x84c0U < (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xba)) {
      *(uint *)(glContext + 0x53d8) = texture - 0x84c0U;
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

/* _glLoadMatrixf_Exec @ 0x4f108 (128 bytes) */
int _glLoadMatrixf_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    m = ((int (*)())_gleLoadMatrixf)(m,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return m;
}

/* _gleLoadMatrixf @ 0x4f188 (132 bytes) */
int _gleLoadMatrixf(m, param_2)
  undefined4 *m;
  undefined4 *param_2;
{
  *param_2 = *m;
  param_2[1] = m[1];
  param_2[2] = m[2];
  param_2[3] = m[3];
  param_2[4] = m[4];
  param_2[5] = m[5];
  param_2[6] = m[6];
  param_2[7] = m[7];
  param_2[8] = m[8];
  param_2[9] = m[9];
  param_2[10] = m[10];
  param_2[0xb] = m[0xb];
  param_2[0xc] = m[0xc];
  param_2[0xd] = m[0xd];
  param_2[0xe] = m[0xe];
  param_2[0xf] = m[0xf];
  return;
}

/* _glDisableClientState_Exec @ 0x4f20c (44 bytes) */
void _glDisableClientState_Exec(glContext, array)
  int glContext;
  undefined4 array;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    _gleSetClientEnableFlag(glContext,array,0);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glColor4fv_NoColorMat_Exec @ 0x4f238 (36 bytes) */
double _glColor4fv_NoColorMat_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = v[1];
  uVar2 = v[2];
  uVar3 = v[3];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2a4) = uVar1;
  *(undefined4 *)(glContext + 0x2a8) = uVar2;
  *(undefined4 *)(glContext + 0x2ac) = uVar3;
  return;
}

/* _gleSetEnable_TEXTURE_3D @ 0x4f25c (80 bytes) */
void _gleSetEnable_TEXTURE_3D(glContext, unusedArg2, param_3)
  int glContext;
  undefined4 unusedArg2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint texUnit;
  uint uVar4;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    iVar2 = texUnit * 0x7c + glContext;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffffd | param_3 << 1;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(glContext,texUnit);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glProgramEnvParameter4fvARB_Exec @ 0x4f2ac (324 bytes) */
void _glProgramEnvParameter4fvARB_Exec(glContext, target, index, params)
  int glContext;
  uint target;
  uint index;
  undefined4 *params;
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int glContextWord5424;
  int iVar5;
  int iVar6;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x800000;
LAB_0004f340:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x158);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x18c);
      }
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + glContextWord5424 + 0x158);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar5 = *(int *)(iVar5 * 8 + glContext + 0x4668);
      *(undefined4 *)(iVar5 + index * 0x10) = *params;
      iVar5 = iVar5 + index * 0x10;
      *(undefined4 *)(iVar5 + 4) = params[1];
      *(undefined4 *)(iVar5 + 8) = params[2];
      *(undefined4 *)(iVar5 + 0xc) = params[3];
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0004f338;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x2000000;
      goto LAB_0004f340;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_0004f338:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glePPRelocateAttrib @ 0x4f3f0 (184 bytes) */
void _glePPRelocateAttrib(param_1, param_2, param_3)
  uint param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      if ((((*(uint *)(iVar1 + 0xc) >> 0x1d != 0) &&
           ((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
          ((*(uint *)(iVar1 + 0x1c) & 0x3800000) == 0)) && (*(ushort *)(iVar1 + 0x22) == param_1)) {
        *(undefined2 *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      uVar2 = *(uint *)(iVar1 + 0xc);
      if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(iVar1 + 0x24) & 0x3800000) == 0 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) & 0x3800000) == 0)) &&
         (*(ushort *)(iVar1 + 0x32) == param_1)) {
        *(undefined2 *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _glePPRelocateLocal @ 0x4f4a8 (240 bytes) */
void _glePPRelocateLocal(param_1, param_2, param_3)
  uint param_1;
  undefined4 param_2;
  int *param_3;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_3;
  if (iVar1 != 0) {
    do {
      if ((((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(iVar1 + 0x14) >> 0x11 & 7) == 1)) && (*(ushort *)(iVar1 + 0x1a) == param_1)) {
        *(undefined2 *)(iVar1 + 0x1a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      uVar2 = *(uint *)(iVar1 + 0xc);
      if (((uVar2 >> 0x1d != 0) && ((uVar2 >> 0x12 & 0xff) != 0x4a)) &&
         (((*(uint *)(iVar1 + 0x1c) >> 0x17 & 7) == 1 && (*(ushort *)(iVar1 + 0x22) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(iVar1 + 0x24) >> 0x17 & 7) == 1 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
        *(undefined2 *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) >> 0x17 & 7) == 1)) &&
         (*(ushort *)(iVar1 + 0x32) == param_1)) {
        *(undefined2 *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      }
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* _glePPRelocateParam @ 0x4f598 (264 bytes) */
void _glePPRelocateParam(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  int *param_4;
{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = *param_3; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
    if ((((*(uint *)(iVar1 + 0xc) >> 0x1d != 0) && ((*(uint *)(iVar1 + 0xc) >> 0x12 & 0xff) != 0x4a)
         ) && ((*(uint *)(iVar1 + 0x1c) >> 0x17 & 7) == 2)) &&
       (*(ushort *)(iVar1 + 0x22) == param_1)) {
      *(short *)(iVar1 + 0x22) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
    uVar2 = *(uint *)(iVar1 + 0xc);
    if (((1 < uVar2 >> 0x1d) && (3 < (uVar2 >> 0x12 & 0xff) - 0x41)) &&
       (((*(uint *)(iVar1 + 0x24) >> 0x17 & 7) == 2 && (*(ushort *)(iVar1 + 0x2a) == param_1)))) {
      *(short *)(iVar1 + 0x2a) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
    if (((2 < uVar2 >> 0x1d) && ((*(uint *)(iVar1 + 0x2c) >> 0x17 & 7) == 2)) &&
       (*(ushort *)(iVar1 + 0x32) == param_1)) {
      *(short *)(iVar1 + 0x32) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
    }
  }
  if (param_4 == (int *)0x0) {
    return;
  }
  iVar1 = *param_4;
  if (iVar1 == 0) {
    return;
  }
  do {
    if (*(ushort *)(iVar1 + 0xe) == param_1) {
      *(short *)(iVar1 + 0xe) = (*(unsigned short *)((unsigned char *)&(param_2) + 2));
      *(short *)(iVar1 + 0x12) = (*(short *)(iVar1 + 0x12) + (*(unsigned short *)((unsigned char *)&(param_2) + 2))) - (short)param_1;
    }
    iVar1 = *(int *)(iVar1 + 8);
  } while (iVar1 != 0);
  return;
}

/* _glFinishRender_Exec @ 0x4f6a0 (136 bytes) */
void _glFinishRender_Exec(glContext)
  int glContext;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar3 = glContext + 0x10000;
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar3 + -0x777c);
        loopIndex = loopIndex + 1;
        puVar2 = (undefined4 *)(iVar3 + -0x7a54);
        iVar3 = iVar3 + 0x2e0;
        (**(code **)(*piVar1 + 0x178))(*puVar2);
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _gleDrawArraysOrElements_VAR_Exec @ 0x4f798 (972 bytes) */
void _gleDrawArraysOrElements_VAR_Exec(int glContext,uint mode,undefined4 first,int count,undefined4 param_5,int param_6,undefined4 unusedArg7,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 uVar3;
  int *srcCursor;
  int framebufferObject;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int matrixChangeBits;
  int iVar9;
  uint uVar10;
  uint dispatchFlags;
  uint changeWord3;
  uint uVar11;
  int *changeWordCursor;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0004f820:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0004fac4;
  }
  if (9 < mode) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_0004fac4;
  }
  if (count < 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0004fac4;
  }
  if ((*(char *)(glContext + 0x4664) != '\0') && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0))
  goto LAB_0004f820;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (count == 0) {
    return;
  }
  iVar7 = param_6;
  if (*(int *)(param_6 + 0x340) != 0 || *(int *)(param_6 + 0x344) != 0) {
    uVar10 = *(uint *)(param_6 + 0x340);
    uVar11 = *(uint *)(param_6 + 0x344);
    iVar7 = glContext + 0x10000;
    *(undefined4 *)(param_6 + 0x340) = 0;
    *(undefined4 *)(param_6 + 0x344) = 0;
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      iVar8 = param_6 + 0x450;
      do {
        loopIndex = loopIndex + 1;
        *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | uVar10;
        *(uint *)(iVar8 + 8) = *(uint *)(iVar8 + 8) | uVar11;
        iVar8 = iVar8 + 0x8c;
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  uVar3 = first;
  iVar9 = count;
  uVar6 = param_5;
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0004faf0;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,iVar9,uVar6,iVar7,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    fparam_1 = fparam_1;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0004f9c8:
    changeWord3 = *(uint *)(glContext + 0x31c);
  }
  else {
    iVar7 = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar9 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar9 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 9);
    changeWord3 = *(uint *)(glContext + 0x31c);
    if ((changeWord3 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0004f9c8;
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
         (fparam_1 = extraout_f1_01, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_0004fac4:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
    }
    iVar7 = 0x13;
    do {
      *changeWordCursor = 0;
      changeWordCursor = changeWordCursor + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
LAB_0004faf0:
  if ((*(char *)(glContext + 0x7580) != '\0') &&
     (iVar7 = _gleExecuteVertexArrayRange
                        (glContext,param_5,mode,first,count,*(undefined4 *)(glContext + 0x48dc),
                         *(undefined4 *)(glContext + 0x48d8)), fparam_1 = extraout_f1_02, iVar7 != 0))
  {
    return;
  }
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(glContext,mode,first,count,param_5,param_6,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return;
}

/* _glSetFenceAPPLE_Exec @ 0x4fb9c (712 bytes) */
void _glSetFenceAPPLE_Exec(glContext, fence)
  int glContext;
  undefined4 fence;
{
  int loopIndex2;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  int *srcCursor;
  int iVar4;
  int iVar5;
  int framebufferObject;
  int in_r5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  double fparam_1;
  double extraout_f1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  iVar4 = _gleLookupHashObject(glContext + 0x543c,fence);
  fparam_1 = extraout_f1;
  if (iVar4 == 0) {
    iVar4 = ((int (*)())_gleCreateFenceObject)(fence);
    ((void (*)())_gleCreatePluginFence)(glContext,iVar4 + 0x10);
    in_r5 = iVar4;
    fparam_1 = (double)_gleAddHashNameAndObject(glContext,glContext + 0x543c,iVar4);
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_00;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0004fe34;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,in_r5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
               incomingFpr6,incomingFpr7,incomingFpr8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0004fd20:
    changeWord3 = *(uint *)(glContext + 0x31c);
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
    changeWord3 = *(uint *)(glContext + 0x31c);
    if ((changeWord3 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0004fd20;
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
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
  }
  loopIndex2 = 0;
  do {
    loopIndex2 = loopIndex2 + 1;
    *changeWordCursor = 0;
    changeWordCursor = changeWordCursor + 1;
  } while (loopIndex2 < 0x13);
LAB_0004fe34:
                    
                    
  (**(code **)(glContext + 0x46fc))
            (*(undefined4 *)(glContext + 0x4688),
             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar4 + 0x10));
  return;
}

/* _gleCreateFenceObject @ 0x4fe64 (112 bytes) */
int _gleCreateFenceObject(fence)
  undefined4 fence;
{
  undefined *puVar1;
  undefined4 *cursor;
  undefined4 *allocatedBlock;
  int remaining;
  
  allocatedBlock = (undefined4 *)_malloc(0x30);
  puVar1 = PTR__gleFreeFenceObject_00110e1c;
  allocatedBlock[2] = 1;
  allocatedBlock[3] = puVar1;
  allocatedBlock[1] = fence;
  cursor = allocatedBlock + 4;
  *allocatedBlock = 0;
  remaining = 8;
  do {
    *cursor = 0;
    cursor = cursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return (int)allocatedBlock;
}

/* _gleCreatePluginFence @ 0x4fed4 (112 bytes) */
void _gleCreatePluginFence(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x1b8))(*puVar2,param_2);
      param_2 = param_2 + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _glPointSize_Exec @ 0x4ff44 (216 bytes) */
void _glPointSize_Exec(int glContext,float size)
{
  byte bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int glContextPtr5424;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (!(size <= (double)FLOAT_00108e50)) {
      *(float *)(glContext + 0x341c) = (float)size;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
      }
      iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
      glContextPtr5424 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar3 + 0x324) = *(uint *)(iVar3 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(glContextPtr5424 + 0x325);
      iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
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

/* _glProgramLocalParameter4fARB_Exec @ 0x5001c (328 bytes) */
void _glProgramLocalParameter4fARB_Exec(int glContext,uint target,uint index,float x,float y,float z,float w)
{
  byte bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  int iVar4;
  int glContextWord5424;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (target == 0x8620) {
    iVar5 = 0;
    if (index < 0x100) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_000500b0:
      *(uint *)(glContext + 0x31c) = uVar2;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        bVar1 = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      iVar6 = iVar5 * 4 + glContext;
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(index + glContextWord5424 + 0x58);
      iVar4 = *(int *)(iVar6 + 0x5420);
      iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar1 & 0x1f);
      iVar4 = *(int *)(iVar4 + 0x4e0);
      iVar5 = iVar4 + index * 0x10;
      *(float *)(iVar4 + index * 0x10) = (float)x;
      *(float *)(iVar5 + 0xc) = (float)w;
      *(float *)(iVar5 + 4) = (float)y;
      *(float *)(iVar5 + 8) = (float)z;
      _gleModifyPluginPipelineProgram(glContext,*(int *)(iVar6 + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      uVar2 = 0x8200;
    }
    else {
      uVar2 = 0x8804;
    }
    if (target != uVar2) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000500a8;
    }
    iVar5 = 1;
    if (index < 0x80) {
      uVar2 = *(uint *)(glContext + 0x31c) | 0x1000000;
      goto LAB_000500b0;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x501;
LAB_000500a8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glPrioritizeTextures_Exec @ 0x50164 (348 bytes) */
void _glPrioritizeTextures_Exec(glContext, n, textures, priorities)
  int glContext;
  int n;
  int textures;
  int priorities;
{
  float floatZero;
  float floatOne;
  undefined4 glErrorCode;
  float fVar4;
  int iVar5;
  int iVar6;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (n == 0) {
        return;
      }
      iVar5 = *(int *)(glContext + 0x5148);
      if (*(char *)(iVar5 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar5 + 0x8028);
        iVar5 = *(int *)(glContext + 0x5148);
      }
      floatOne = FLOAT_00108e54;
      floatZero = FLOAT_00108e50;
      loopIndex = 0;
      if (0 < n) {
        do {
          iVar6 = *(int *)(loopIndex * 4 + textures);
          if (iVar6 != 0) {
            iVar5 = _gleLookupHashObject(iVar5 + 0x2008,iVar6);
            if (iVar5 != 0) {
              fVar4 = *(float *)(loopIndex * 4 + priorities);
              if (fVar4 < floatZero) {
                fVar4 = 0.0;
              }
              else if (floatOne < fVar4) {
                fVar4 = 1.0;
              }
              *(float *)(iVar5 + 0x38) = fVar4;
            }
            iVar5 = *(int *)(glContext + 0x5148);
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < n);
      }
      if (*(char *)(iVar5 + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(iVar5 + 0x8028);
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

/* _glPassThrough_Exec @ 0x502c0 (152 bytes) */
void _glPassThrough_Exec(int glContext,float token)
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x4e1c) == 0x1c01) {
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108e7c);
      ((void (*)())_gleFeedbackToken)(glContext,token);
      return;
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _gleCopyPixelMapi @ 0x50358 (232 bytes) */
void _gleCopyPixelMapi(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  undefined *puVar1;
  int loopIndex;
  
  puVar1 = (undefined *)*param_2;
  if ((param_3 == 1) && (*param_1 == 0)) {
    if (puVar1 == PTR__gle_default_pix_map_i_00112044) {
      return;
    }
    _free(puVar1);
LAB_0005041c:
    *param_2 = PTR__gle_default_pix_map_i_00112044;
    *param_4 = 1;
  }
  else {
    if ((param_3 != *param_4) || (puVar1 == PTR__gle_default_pix_map_i_00112044)) {
      if (puVar1 == PTR__gle_default_pix_map_i_00112044) {
        puVar1 = (undefined *)0x0;
      }
      puVar1 = (undefined *)_realloc(puVar1,param_3 << 2);
      if (puVar1 == (undefined *)0x0) goto LAB_0005041c;
      *param_2 = puVar1;
      *param_4 = param_3;
    }
    loopIndex = 0;
    if (0 < param_3) {
      do {
        *(int *)(puVar1 + loopIndex * 4) = param_1[loopIndex];
        param_3 = param_3 + -1;
        loopIndex = loopIndex + 1;
      } while (param_3 != 0);
    }
  }
  return;
}

/* _gleCopyPixelMapf @ 0x50440 (240 bytes) */
int _gleCopyPixelMapf(param_1, param_2, param_3, param_4)
  float *param_1;
  undefined4 *param_2;
  int param_3;
  int *param_4;
{
  int loopIndex;
  undefined *puVar2;
  
  puVar2 = (undefined *)*param_2;
  if ((param_3 == 1) && (*param_1 == FLOAT_00108e50)) {
    if (puVar2 == PTR__gle_default_pix_map_f_00112040) {
      return;
    }
    _free(puVar2);
LAB_0005050c:
    *param_2 = PTR__gle_default_pix_map_f_00112040;
    *param_4 = 1;
  }
  else {
    if ((param_3 != *param_4) || (puVar2 == PTR__gle_default_pix_map_f_00112040)) {
      if (puVar2 == PTR__gle_default_pix_map_f_00112040) {
        puVar2 = (undefined *)0x0;
      }
      puVar2 = (undefined *)_realloc(puVar2,param_3 << 2);
      if (puVar2 == (undefined *)0x0) goto LAB_0005050c;
      *param_2 = puVar2;
      *param_4 = param_3;
    }
    loopIndex = 0;
    if (0 < param_3) {
      do {
        *(float *)(puVar2 + loopIndex * 4) = param_1[loopIndex];
        param_3 = param_3 + -1;
        loopIndex = loopIndex + 1;
      } while (param_3 != 0);
    }
  }
  return;
}

/* _gleFreeFenceObject @ 0x50530 (52 bytes) */
void _gleFreeFenceObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  ((void (*)())_gleDestroyPluginFence)(glContext,param_2 + 0x10);
  _free(param_2);
  return;
}

/* _gleDestroyPluginFence @ 0x50564 (120 bytes) */
void _gleDestroyPluginFence(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int loopIndex;
  
  iVar4 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = loopIndex * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x1bc))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _glFeedbackBuffer_Exec @ 0x505dc (132 bytes) */
void _glFeedbackBuffer_Exec(glContext, size, type, buffer)
  int glContext;
  int size;
  int type;
  undefined4 buffer;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (4 < type - 0x600U) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00050604;
    }
    if (size < 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00050604;
    }
    if (*(int *)(glContext + 0x4e1c) != 0x1c01) {
      *(int *)(glContext + 0x4fd8) = type;
      *(undefined4 *)(glContext + 0x4fd0) = buffer;
      *(char *)(glContext + 0x4fdc) = (char)size;
      *(undefined4 *)(glContext + 0x4fcc) = buffer;
      *(int *)(glContext + 0x4fd4) = size;
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00050604:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glRenderMode_Exec @ 0x50660 (508 bytes) */
int _glRenderMode_Exec(glContext, mode)
  int glContext;
  uint mode;
{
  undefined *puVar1;
  undefined4 glErrorCode;
  uint glContextWord4e1c;
  int iVar4;
  double forwardedFloatArg1;
  double fparam_1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  iVar4 = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode - 0x1c00 < 3) {
      glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
      if (glContextWord4e1c == 0x1c01) {
        iVar4 = -1;
        if (*(char *)(glContext + 0x4fdc) == '\0') {
          iVar4 = *(int *)(glContext + 0x4fd0) - *(int *)(glContext + 0x4fcc) >> 2;
        }
      }
      else if (((0x1c01 < glContextWord4e1c) && (glContextWord4e1c == 0x1c02)) &&
              (iVar4 = -1, *(char *)(glContext + 0x4fc9) == '\0')) {
        iVar4 = *(int *)(glContext + 0x4fc4);
      }
      if (mode == 0x1c01) {
        if (*(int *)(glContext + 0x4fd4) == 0) {
LAB_000507ac:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x502;
            return iVar4;
          }
          return iVar4;
        }
        *(undefined1 *)(glContext + 0x4691) = 0;
        *(undefined4 *)(glContext + 0x4fd0) = *(undefined4 *)(glContext + 0x4fcc);
        *(undefined1 *)(glContext + 0x4fdc) = 0;
        *(undefined1 *)(glContext + 0x7580) = 0;
      }
      else if (mode < 0x1c02) {
        if (mode == 0x1c00) {
          *(bool *)(glContext + 0x4691) = *(char *)(glContext + 0x4692) == '\0';
          *(undefined4 *)(glContext + 0x757c) = 0xffffffff;
        }
      }
      else if (mode == 0x1c02) {
        if (*(int *)(glContext + 0x4e28) == 0) goto LAB_000507ac;
        *(undefined4 *)(glContext + 0x4e24) = *(undefined4 *)(glContext + 20000);
        *(undefined1 *)(glContext + 0x4fc9) = 0;
        *(int *)(glContext + 0x4fbc) = glContext + 0x4e2c;
        *(undefined1 *)(glContext + 0x4691) = 0;
        *(undefined4 *)(glContext + 0x4fc4) = 0;
        *(undefined1 *)(glContext + 0x4fc8) = 0;
        *(undefined4 *)(glContext + 0x4fc0) = 0;
        *(undefined1 *)(glContext + 0x7580) = 0;
      }
      *(uint *)(glContext + 0x4e1c) = mode;
      *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
      _gleSetColorMaterialEnable(glContext);
      puVar1 = PTR__gleSetClipInterpFunc_00112038;
      *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
      *(undefined **)(glContext + 0x49cc) = puVar1;
      _gleSelectVertexSubmitFunc(glContext);
      _gleSelectVertexAddMaterialFunc(glContext);
      _gleUpdatePrimitiveData(glContext);
      ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
                 incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
      _gleUpdateTextureTransform(glContext);
      _gleUpdatePolyMode(glContext);
      return iVar4;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleFeedbackToken @ 0x5086c (68 bytes) */
void _gleFeedbackToken(int glContext,float fparam_1)
{
  float *glContextPtr4fd0;
  
  if (*(char *)(glContext + 0x4fdc) != '\0') {
    return;
  }
  glContextPtr4fd0 = *(float **)(glContext + 0x4fd0);
  if ((float *)(*(int *)(glContext + 0x4fcc) + *(int *)(glContext + 0x4fd4) * 4) <= glContextPtr4fd0) {
    *(undefined1 *)(glContext + 0x4fdc) = 1;
    return;
  }
  *glContextPtr4fd0 = (float)fparam_1;
  *(float **)(glContext + 0x4fd0) = glContextPtr4fd0 + 1;
  return;
}

/* _gleBeginQuadsSelectFeedback @ 0x508b0 (76 bytes) */
void _gleBeginQuadsSelectFeedback(glContext)
  int glContext;
{
  undefined *puVar1;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  puVar1 = PTR__gleFeedbackQuadsFunc_00112278;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    puVar1 = PTR__gleSelectQuadsFunc_0011227c;
  }
  *(undefined **)(glContext + 0x4a08) = puVar1;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  return;
}

/* _gleFeedbackQuadsFunc_body @ 0x50900 (1284 bytes) */
void _gleFeedbackQuadsFunc_body(glContext)
  int glContext;
{
  uint *cursor;
  int loopIndex;
  char glContextByte4fe0;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int remaining;
  double dVar22;
  double extraout_f1;
  double extraout_f1_00;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  int local_50;
  int local_4c [4];
  
  iVar12 = -1;
  bVar3 = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    bVar3 = true;
  }
  bVar3 = !bVar3;
  bVar5 = false;
  if ((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) {
    bVar5 = true;
  }
  bVar6 = false;
  if (((bVar3) && (*(char *)(glContext + 0x30aa) != '\0')) && (*(char *)(glContext + 0x30ac) != '\0')) {
    bVar6 = true;
  }
  glContextByte4fe0 = *(char *)(glContext + 0x4fe0);
  uVar19 = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (uVar15 = (*(int *)(glContext + 0x4858) - uVar19) / (uint)(int)*(short *)(glContext + 0x487c),
     3 < (int)uVar15)) {
    if (bVar3) {
      uVar9 = (**(code **)(glContext + 0x5060))(glContext,uVar19,uVar15);
    }
    else {
      uVar9 = _gleVPEmulate(glContext,uVar15);
    }
    if ((uVar9 & 0xff00) == 0) {
      if (bVar3) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,uVar19,uVar15);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,uVar19,uVar15);
        }
        if ((bVar5) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,uVar19,uVar15);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,uVar19,uVar15);
        }
      }
      else {
        uVar19 = *(uint *)(glContext + 0x4864);
      }
      if (((uVar9 & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, uVar19, uVar15, 0);
        if (glContextByte4fe0 == '\0') {
          if (bVar5) {
            (**(code **)(glContext + 0x4de8))(glContext,uVar19,uVar15);
          }
          _gleFeedbackQuads(glContext,uVar19,uVar15,*(ushort *)(glContext + 0x34d0) - 0x1b00);
        }
        else {
          uVar15 = (uVar19 + uVar15 * 0x100) - 0x400;
          do {
            bVar4 = false;
            loopIndex = 0;
            uVar9 = uVar19;
            uVar18 = uVar19;
            if (uVar19 <= uVar15) {
              do {
                iVar10 = ((undefined4 (*)())_gleCullQuad)(glContext,uVar19,uVar19 + 0x100,uVar19 + 0x200,uVar19 + 0x300,
                                      &local_50,dVar22,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
                dVar22 = dVar22;
                if (iVar10 == 0) {
                  if (iVar12 != local_50) {
                    bVar4 = true;
                  }
                  if ((bVar4) && (uVar9 = uVar19, 0 < loopIndex)) break;
                  loopIndex = loopIndex + 4;
                  iVar12 = local_50;
                  uVar17 = uVar18;
                }
                else {
                  uVar17 = uVar19 + 0x400;
                  uVar9 = uVar17;
                  if (0 < loopIndex) break;
                }
                uVar19 = uVar19 + 0x400;
                uVar9 = uVar19;
                uVar18 = uVar17;
              } while (uVar19 <= uVar15);
              if (3 < loopIndex) {
                if (bVar6) {
                  pcVar11 = *(code **)(iVar12 * 4 + glContext + 0x4de8);
LAB_00050bc0:
                  (*pcVar11)(glContext,uVar18,loopIndex);
                }
                else if (bVar5) {
                  pcVar11 = *(code **)(glContext + 0x4de8);
                  goto LAB_00050bc0;
                }
                if ((!bVar3) && (bVar5)) {
                  _gleVPFlipColors(glContext,uVar18,loopIndex,iVar12);
                }
                if (iVar12 == 0) {
                  uVar2 = *(ushort *)(glContext + 0x34d0);
                }
                else {
                  uVar2 = *(ushort *)(glContext + 0x34d2);
                }
                dVar22 = (double)_gleFeedbackQuads(glContext,uVar18,loopIndex,uVar2 - 0x1b00);
              }
            }
            uVar19 = uVar9;
          } while (uVar9 <= uVar15);
        }
      }
      else {
        dVar22 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, uVar19, uVar15, 0);
        iVar12 = uVar19 + uVar15 * 0x100;
        puVar16 = *(uint **)(glContext + 0x4870);
        puVar13 = *(uint **)(glContext + 0x4874);
        for (; uVar19 <= iVar12 - 0x400U; uVar19 = uVar19 + 0x400) {
          puVar16[1] = uVar19 + 0x100;
          puVar16[2] = uVar19 + 0x200;
          puVar16[3] = uVar19 + 0x300;
          *puVar16 = uVar19;
          if (bVar3) {
            uVar8 = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            uVar8 = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = uVar8;
          puVar14 = puVar13;
          iVar20 = 4;
          puVar7 = puVar16;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (dVar22 = (double)((double (*)())_gleClipPolyPlane)(glContext,puVar16,4,puVar13,local_4c,dVar22,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar14 = puVar16, iVar20 = local_4c[0], puVar7 = puVar13, local_4c[0] != 0)) {
            puVar16 = puVar7;
            puVar13 = puVar14;
            if ((uVar9 & 0xff) != 0) {
              dVar22 = (double)((double (*)())_gleClipPoly)(glContext,puVar16,iVar20,uVar9 & 0xff,puVar14,local_4c,1);
              if (local_4c[0] == 0) goto LAB_00050ddc;
              if (0 < local_4c[0]) {
                puVar13 = puVar16;
                iVar20 = local_4c[0];
                puVar16 = puVar14;
              }
            }
            if ((glContextByte4fe0 == '\0') ||
               (iVar10 = _gleCullPolygonPtrStack(glContext,puVar16,iVar20,&local_50),
               dVar22 = extraout_f1_00, iVar10 == 0)) {
              iVar10 = local_50;
              if (bVar6) {
                pcVar11 = *(code **)(local_50 * 4 + glContext + 0x4df0);
LAB_00050d70:
                (*pcVar11)(glContext,puVar16,iVar20);
              }
              else if (bVar5) {
                pcVar11 = *(code **)(glContext + 0x4df0);
                goto LAB_00050d70;
              }
              if (((!bVar3) && (bVar5)) && (cursor = puVar16, remaining = iVar20, 0 < iVar20)) {
                do {
                  _gleVPFlipColors(glContext,*cursor,1,iVar10);
                  remaining = remaining + -1;
                  cursor = cursor + 1;
                } while (remaining != 0);
              }
              if (iVar10 == 0) {
                uVar2 = *(ushort *)(glContext + 0x34d0);
              }
              else {
                uVar2 = *(ushort *)(glContext + 0x34d2);
              }
              dVar22 = (double)((double (*)())_gleFeedbackPolygonPtr)(glContext,puVar16,iVar20,uVar2 - 0x1b00);
            }
          }
LAB_00050ddc: ;
        }
      }
    }
  }
  return;
}

/* _gleSetProjectionFuncAll @ 0x50e04 (104 bytes) */
void _gleSetProjectionFuncAll(param_1, forwardedArg2, forwardedArg3)
  int param_1;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  code *pcVar1;
  
  pcVar1 = (code *)(*_gleBuildProjectionTransformFunc)(param_1,0,forwardedArg3);
  *(code **)(param_1 + 0x5060) = pcVar1;
  (*pcVar1)(param_1,forwardedArg2,forwardedArg3);
  return;
}

/* _gleBuildProjectionTransformFuncAV @ 0x50e6c (1208 bytes) */
int _gleBuildProjectionTransformFuncAV(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount;
  int chunkWordCountThenCodeCursor2;
  int chunkWordCount2;
  undefined *puVar6;
  undefined *codeChunk;
  int chunkWordCountThenCodeCursor3;
  int chunkWordCount3;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  
  piVar14 = (int *)PTR__gleTransformProjectionBlend_00110a10;
  if (*(char *)(param_1 + 0x4661) == '\0') {
    uVar2 = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(param_1,param_1 + 0x27c0);
    *(uint *)(param_1 + 0x5084) = uVar2;
    if (((param_2 & 1) != 0) && ((uVar2 & 0x3030303) == 0x3030302)) {
      param_2 = param_2 | 4;
    }
    if ((uVar2 != 0xbfeffbfe) &&
       (uVar1 = uVar2 & 0x3fcff3fc, uVar2 = 0x3fcff3fc, uVar1 != 0x3fcff3fc)) {
      uVar2 = 0;
    }
    if (*(undefined **)(param_1 + 0x5080) == ((unsigned char *)0x00001101)) {
      param_2 = param_2 | 8;
    }
    piVar13 = *(int **)(param_1 + 0x5088);
    piVar14 = piVar13;
    do {
      if (uVar2 == piVar14[2] && param_2 == piVar14[3]) {
        if (piVar14 != piVar13) {
          _gleMoveFuncCacheElem(piVar13,piVar14);
          *(int **)(param_1 + 0x5088) = piVar14;
        }
        return piVar14 + 8;
      }
      piVar14 = (int *)*piVar14;
    } while (piVar14 != piVar13);
    iVar3 = _gleCreateFuncCacheElem(piVar14,0xb8);
    piVar14 = (int *)PTR__gleRTCNoop_00112058;
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 8) = uVar2;
      *(uint *)(iVar3 + 0xc) = param_2;
      if (*(short *)(param_1 + 0x508e) == *(short *)(param_1 + 0x508c)) {
        _gleDeleteFuncCacheElem(*(undefined4 *)(iVar3 + 4));
      }
      else {
        *(short *)(param_1 + 0x508e) = *(short *)(param_1 + 0x508e) + 1;
      }
      chunkWordCountThenCodeCursor = _gleRTCAddAChunk_c5ddc(&_glePrologAVRTC_10f938,iVar3 + 0x20);
      chunkWordCountThenCodeCursor = iVar3 + 0x20 + chunkWordCountThenCodeCursor * 4;
      if (uVar2 != 0xbfeffbfe) {
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(&_gleLoadMatrixPtrRTC_10f758,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
        if ((param_2 & 2) == 0) {
          codeChunk = &_gleLoadMatrixVectorsRTC_10f9d0;
        }
        else {
          codeChunk = &_gleLoadMatrixVectorsZ0RTC_10f9f0;
        }
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      }
      chunkWordCount2 = _gleRTCAddAChunk_c5ddc(&_gleLoadModelOffsetRTC,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
      if (uVar2 == 0) {
        if ((param_2 & 1) == 0) {
          if ((param_2 & 2) == 0) {
            codeChunk = &_gleFullMatrixMultRTC_10fa18;
          }
          else {
            codeChunk = &_gleFullMatrixMultZ0RTC_10fa64;
          }
        }
        else if ((param_2 & 2) == 0) {
          codeChunk = &_gleFullMatrixMultW1RTC_10faa0;
        }
        else {
          codeChunk = &_gleFullMatrixMultZ0W1RTC_10fadc;
        }
      }
      else if (uVar2 == 0x3fcff3fc) {
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(&_gleDiagMatrixSetupRTC_10fb08,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
        codeChunk = &_gleDiagMatrixMultRTC_10fb20;
      }
      else {
        codeChunk = &_gleIdentityMatrixMultRTC_10fb34;
      }
      chunkWordCountThenCodeCursor2 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor + chunkWordCountThenCodeCursor2 * 4;
      if ((param_2 & 8) == 0) {
        if ((param_2 & 4) == 0) {
          chunkWordCount3 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode0AVRTC,chunkWordCountThenCodeCursor2);
          chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount3 * 4;
          chunkWordCountThenCodeCursor3 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode1AVRTC,chunkWordCountThenCodeCursor2);
          chunkWordCountThenCodeCursor3 = chunkWordCountThenCodeCursor2 + chunkWordCountThenCodeCursor3 * 4;
          codeChunk = &_gleCalcClipCode2AVRTC;
        }
        else {
          chunkWordCount3 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode0W1AVRTC,chunkWordCountThenCodeCursor2);
          chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount3 * 4;
          chunkWordCountThenCodeCursor3 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode1W1AVRTC,chunkWordCountThenCodeCursor2);
          chunkWordCountThenCodeCursor3 = chunkWordCountThenCodeCursor2 + chunkWordCountThenCodeCursor3 * 4;
          codeChunk = &_gleCalcClipCode2W1AVRTC;
        }
        puVar10 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -8);
        puVar16 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
        puVar12 = (undefined4 *)(chunkWordCountThenCodeCursor3 + -8);
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor3);
        puVar9 = (undefined4 *)(chunkWordCountThenCodeCursor3 + -4);
        chunkWordCountThenCodeCursor3 = chunkWordCountThenCodeCursor3 + chunkWordCount2 * 4;
        puVar15 = (undefined4 *)(chunkWordCountThenCodeCursor3 + -8);
        puVar11 = (undefined4 *)(chunkWordCountThenCodeCursor3 + -4);
        chunkWordCountThenCodeCursor2 = _gleRTCAddAChunk_c5ddc(&_gleCalcClipCode3AVRTC,chunkWordCountThenCodeCursor3);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor3 + chunkWordCountThenCodeCursor2 * 4;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar10,chunkWordCountThenCodeCursor - (int)puVar10 >> 2);
        *puVar10 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar12,chunkWordCountThenCodeCursor - (int)puVar12 >> 2);
        *puVar12 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar15,chunkWordCountThenCodeCursor - (int)puVar15 >> 2);
        *puVar15 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar16,chunkWordCountThenCodeCursor2 - (int)puVar16 >> 2);
        *puVar16 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar9,chunkWordCountThenCodeCursor2 - (int)puVar9 >> 2);
        *puVar9 = uVar8;
        uVar8 = _gleRTCBuildABranch_c5dd0(*puVar11,chunkWordCountThenCodeCursor2 - (int)puVar11 >> 2);
        *puVar11 = uVar8;
      }
      else {
        if ((param_2 & 4) == 0) {
          codeChunk = &_gleNoClipCodeAVRTC;
        }
        else {
          codeChunk = &_gleNoClipCodeW1AVRTC;
        }
        chunkWordCount3 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount3 * 4;
      }
      puVar16 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
      uVar8 = _gleRTCBuildABranch_c5dd0(*puVar16,chunkWordCountThenCodeCursor - (int)puVar16 >> 2);
      *puVar16 = uVar8;
      chunkWordCount = _gleRTCAddAChunk_c5ddc(&_gleCombineClipSumsAVRTC,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
      chunkWordCount = _gleRTCAddAChunk_c5ddc(&_gleEpilogAVRTC_10f9c4,chunkWordCountThenCodeCursor2);
      puVar16 = (undefined4 *)(chunkWordCountThenCodeCursor2 + chunkWordCount * 4);
      *puVar16 = 0x4e800020;
      iVar4 = (int)puVar16 + (-0x1c - iVar3) >> 2;
      if (0xb8 < iVar4) {
                    
        _exit(1);
      }
      iVar3 = _gleShrinkFuncCacheElem(iVar3,iVar4);
      puVar6 = PTR__glePushInstructions_00112054;
      *(int *)(param_1 + 0x5088) = iVar3;
      (**(code **)puVar6)(iVar4,(int *)(iVar3 + 0x20));
      piVar14 = (int *)(iVar3 + 0x20);
    }
  }
  return piVar14;
}

/* _gleRTCAddAChunk_51324 @ 0x51324 (48 bytes) */
int _gleRTCAddAChunk_51324(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int loopIndex;
  
  loopIndex = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    loopIndex = loopIndex + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return loopIndex;
}

/* _gleRTCBuildABranch_51354 @ 0x51354 (12 bytes) */
int _gleRTCBuildABranch_51354(param_1, param_2)
  uint param_1;
  uint param_2;
{
  return (param_2 & 0x3fff) << 2 | param_1 & 0xffff0003;
}

/* _gleTextureMatTrans_body @ 0x51364 (232 bytes) */
void _gleTextureMatTrans_body(int param_1,uint param_2,int param_3,int param_4,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
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
  int iVar21;
  uint uVar22;
  
  iVar21 = param_1 + param_4 * 0x40;
  fVar1 = *(float *)(iVar21 + 0x1fc0);
  fVar2 = *(float *)(iVar21 + 0x1ff8);
  fVar3 = *(float *)(iVar21 + 0x1fc4);
  fVar4 = *(float *)(0x1fcc + iVar21);
  fVar5 = *(float *)(iVar21 + 0x1fd0);
  fVar6 = *(float *)(iVar21 + 0x1fd4);
  fVar7 = *(float *)(iVar21 + 0x1fdc);
  fVar8 = *(float *)(iVar21 + 0x1fe0);
  fVar9 = *(float *)(iVar21 + 0x1fe4);
  fVar10 = *(float *)(iVar21 + 0x1fec);
  fVar11 = *(float *)(iVar21 + 0x1ff0);
  fVar12 = *(float *)(iVar21 + 0x1ff4);
  fVar13 = *(float *)(iVar21 + 0x1ffc);
  fVar14 = *(float *)(iVar21 + 0x1fc8);
  fVar15 = *(float *)(iVar21 + 0x1fd8);
  fVar16 = *(float *)(iVar21 + 0x1fe8);
  if (param_2 < param_2 + param_3) {
    uVar22 = ((param_2 + param_3) - param_2) + 0xff >> 8;
    do {
      iVar21 = param_2 + param_4 * 0x10;
      param_2 = param_2 + 0x100;
      fVar17 = *(float *)(iVar21 + 0x80);
      fVar18 = *(float *)(iVar21 + 0x84);
      fVar19 = *(float *)(iVar21 + 0x88);
      fVar20 = *(float *)(iVar21 + 0x8c);
      *(float *)(iVar21 + 0x8c) =
           fVar20 * fVar13 + (fVar19 * fVar10 + (fVar17 * fVar4 + fVar18 * fVar7));
      *(float *)(iVar21 + 0x80) = fVar20 * fVar11 + (fVar19 * fVar8 + (fVar17 * fVar1 + fVar18 * fVar5))
      ;
      *(float *)(iVar21 + 0x84) = fVar20 * fVar12 + (fVar19 * fVar9 + (fVar17 * fVar3 + fVar18 * fVar6))
      ;
      *(float *)(iVar21 + 0x88) =
           fVar20 * fVar2 + (fVar19 * fVar16 + (fVar17 * fVar14 + fVar18 * fVar15));
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  return;
}

/* _gleClipPoly @ 0x5144c (432 bytes) */
double _gleClipPoly(glContext, param_2, param_3, param_4, param_5, param_6, param_7)
  int glContext;
  int *param_2;
  int param_3;
  uint param_4;
  int *param_5;
  int *param_6;
  int param_7;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int loopIndex;
  int iVar5;
  int *piVar6;
  int *cursor;
  int *piVar8;
  int *cursor2;
  int remaining;
  
  if (param_7 == 0) {
LAB_000514ac:
    iVar1 = *(int *)(glContext + 0x4858);
    piVar8 = param_2 + param_3;
    iVar5 = 0;
    uVar2 = 1;
    piVar6 = param_5;
    do {
      cursor = piVar6;
      if ((param_4 & uVar2) != 0) {
        *piVar8 = *param_2;
        for (cursor2 = param_2; cursor2 < piVar8; cursor2 = cursor2 + 1) {
          iVar5 = *cursor2;
          if ((uVar2 & *(byte *)(iVar5 + 0x7f)) == 0) {
            *cursor = iVar5;
            cursor = cursor + 1;
            if ((uVar2 & *(byte *)(cursor2[1] + 0x7f)) != 0) {
              uVar3 = (**(code **)(glContext + 0x49cc))(glContext,cursor2[1],*cursor2,iVar1,uVar2);
              *(undefined1 *)(iVar1 + 0x7c) = 0;
              *cursor = iVar1;
              goto LAB_0005156c;
            }
          }
          else if ((uVar2 & *(byte *)(cursor2[1] + 0x7f)) == 0) {
            uVar3 = (**(code **)(glContext + 0x49cc))(glContext,iVar5,cursor2[1],iVar1,uVar2);
            *cursor = iVar1;
LAB_0005156c:
            param_4 = (param_4 | uVar3) & 0xff;
            iVar1 = iVar1 + 0x100;
            cursor = cursor + 1;
          }
        }
        iVar5 = (int)cursor - (int)piVar6 >> 2;
        if (iVar5 < 3) goto LAB_000514a0;
        piVar8 = piVar6 + iVar5;
        cursor = param_2;
        param_2 = piVar6;
      }
      uVar2 = (uVar2 & 0x7f) << 1;
      piVar6 = cursor;
    } while (uVar2 < 0x21);
    if ((param_2 != param_5) && (loopIndex = 0, remaining = iVar5, 0 < iVar5)) {
      do {
        param_5[loopIndex] = param_2[loopIndex];
        remaining = remaining + -1;
        loopIndex = loopIndex + 1;
      } while (remaining != 0);
    }
    *param_6 = iVar5;
    *(int *)(glContext + 0x4858) = iVar1;
  }
  else {
    uVar2 = ((int (*)())_glePolyClipCode)(glContext,param_2,param_3);
    if ((uVar2 & 0xff) == 0) {
      iVar1 = -1;
    }
    else {
      param_4 = uVar2 & 0xff;
      if ((uVar2 & 0xff00) == 0) goto LAB_000514ac;
LAB_000514a0:
      iVar1 = 0;
    }
    *param_6 = iVar1;
  }
  return;
}

/* _glePolyClipCode @ 0x515fc (76 bytes) */
int _glePolyClipCode(glContext, param_2, param_3)
  undefined4 glContext;
  int *param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = 0xff;
  if (param_2 < param_2 + param_3) {
    uVar4 = (uint)((int)(param_2 + param_3) + (3 - (int)param_2)) >> 2;
    do {
      iVar1 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = uVar2 & *(byte *)(iVar1 + 0x7f);
      uVar3 = uVar3 | *(byte *)(iVar1 + 0x7f);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return uVar2 << 8 | uVar3;
}

/* _gleSetClipInterpFunc @ 0x51648 (100 bytes) */
void _gleSetClipInterpFunc(glContext, forwardedArg2, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7, forwardedArg8)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
  undefined4 forwardedArg8;
{
  code *pcVar1;
  
  pcVar1 = (code *)((int (*)())_gleBuildInterpolateFunc)(glContext,1,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedArg8);
  *(code **)(glContext + 0x49cc) = pcVar1;
  (*pcVar1)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5);
  return;
}

/* _gleBuildInterpolateFunc @ 0x516ac (1776 bytes) */
int _gleBuildInterpolateFunc(glContext, clipSpaceFlag, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int glContext;
  int clipSpaceFlag;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint loopIndex2;
  uint loopIndex;
  bool programActive;
  bool noBranchPending;
  uint texCoordUnit;
  uint funcKeyPartial;
  uint glContextWord4e1c;
  int funcCacheElem;
  int glContextWord5438;
  int remaining;
  uint unitShift;
  int programRecord;
  int chunkWordCountThenTotalWords;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount;
  int *selectedFunc;
  int *funcCache;
  int chunkWordCount2;
  undefined *pushInstructionsFn;
  undefined *codeChunk;
  uint *codeCursor;
  uint *srcCursor;
  uint *srcEqualDestBranch;
  uint funcKeyBase;
  uint branchInstruction;
  uint clipFlag;
  uint funcKey;
  uint enabledUnitsShifted;
  int *cacheListHead;
  int *cacheElem;
  int *resultFunc;
  uint *tailCodeCursor;
  
  srcEqualDestBranch = (uint *)0x0;
  if ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0) {
    selectedFunc = (int *)_gleSelectArrayInterpFunc(glContext,clipSpaceFlag);
    return selectedFunc;
  }
  funcKeyBase = 1;
  if (clipSpaceFlag != 1) {
    funcKeyBase = 0x10;
  }
  if (*(int *)(glContext + 0x34f4) == 0x1d01) {
    funcKeyBase = funcKeyBase | 2;
  }
  glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
  if (glContextWord4e1c == 0x1c01) {
    funcKey = funcKeyBase | 0x10020;
    if (((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) &&
       (funcKey = funcKeyBase | 0x10060, *(char *)(glContext + 0x30aa) != '\0')) {
      funcKey = funcKeyBase | 0x10470;
    }
  }
  else {
    funcKey = funcKeyBase;
    if ((glContextWord4e1c < 0x1c02) && (glContextWord4e1c == 0x1c00)) {
      if ((*(uint *)(*(int *)(glContext + 0x468c) + 0x94) & 4) == 0) {
        funcKeyBase = funcKeyBase | 4;
      }
      programActive = *(char *)(glContext + 0x466c) != '\0';
      if (programActive) {
        glContextWord5438 = *(int *)(glContext + 0x5438);
      }
      else {
        glContextWord5438 = *(int *)(glContext + 0x5438);
        if (glContextWord5438 == 0) {
          loopIndex = 0;
          *(uint *)(glContext + 0x5150) = *(uint *)(glContext + 0x514c);
          do {
            enabledUnitsShifted = *(uint *)(glContext + 0x514c) >> (loopIndex & 0x3f);
            if ((enabledUnitsShifted & 1) == 0) {
              if (enabledUnitsShifted == 0) goto LAB_00051840;
            }
            else {
              funcKeyBase = funcKeyBase | 0x10000 << (loopIndex & 0x3f);
            }
            loopIndex = loopIndex + 1;
          } while( true );
        }
      }
      programRecord = 0;
      if (programActive) {
        programRecord = *(int *)(*(int *)(glContext + 0x5424) + 0x4cc);
      }
      if (glContextWord5438 != 0) {
        programRecord = *(int *)(*(int *)(*(int *)(glContext + 0x5430) + 0x24) + 0x508);
      }
      *(undefined4 *)(glContext + 0x5150) = 0;
      if (programRecord != 0) {
        srcCursor = (uint *)(programRecord + *(int *)(programRecord + 0x24) * 8);
        for (remaining = *(int *)(programRecord + 0x20); remaining != 0; remaining = remaining + -1) {
          if ((*srcCursor >> 0x10 & 0xf) == 7) {
            texCoordUnit = *srcCursor & 0x1f;
            funcKeyBase = funcKeyBase | 0x10000 << texCoordUnit;
            *(uint *)(glContext + 0x5150) = *(uint *)(glContext + 0x5150) | 1 << texCoordUnit;
          }
          srcCursor = srcCursor + 2;
        }
      }
LAB_00051840:
      funcKeyPartial = funcKeyBase;
      if ((*(char *)(glContext + 0x316a) != '\0') &&
         (funcKeyPartial = funcKeyBase | 0x80, *(short *)(0x3170 + glContext + 4) == 0x1102)) {
        funcKeyPartial = funcKeyBase | 0x280;
      }
      if (((*(char *)(glContext + 0x30aa) == '\0') || (*(char *)(glContext + 0x4664) != '\0')) ||
         (*(int *)(glContext + 0x5434) != 0)) {
        funcKey = funcKeyPartial | 0x20;
        if (*(char *)(glContext + 0x4fea) != '\0') {
          funcKey = funcKeyPartial | 0x120;
        }
      }
      else {
        funcKey = funcKeyPartial | 0x450;
      }
    }
  }
  funcCache = (int *)(glContext + 0x49d0);
  if (clipSpaceFlag != 0) {
    funcCache = (int *)(glContext + 0x49d8);
  }
  cacheListHead = (int *)*funcCache;
  cacheElem = cacheListHead;
  do {
    if (funcKey == cacheElem[2]) {
      if (cacheElem != cacheListHead) {
        _gleMoveFuncCacheElem(cacheListHead,cacheElem);
        *funcCache = (int)cacheElem;
      }
      return cacheElem + 8;
    }
    cacheElem = (int *)*cacheElem;
  } while (cacheElem != cacheListHead);
  funcCacheElem = _gleCreateFuncCacheElem(cacheElem,0xa0);
  resultFunc = (int *)PTR__gleRTCNoop_00112058;
  if (funcCacheElem != 0) {
    *(uint *)(funcCacheElem + 8) = funcKey;
    if (*(short *)((int)funcCache + 6) == *(short *)(funcCache + 1)) {
      _gleDeleteFuncCacheElem(*(undefined4 *)(funcCacheElem + 4));
    }
    else {
      *(short *)((int)funcCache + 6) = *(short *)((int)funcCache + 6) + 1;
    }
    clipFlag = funcKey & 1;
    chunkWordCountThenCodeCursor = ((int (*)())_gleRTCAddAChunk_51324)(&_gleStartAVRTC,funcCacheElem + 0x20);
    chunkWordCountThenCodeCursor = funcCacheElem + 0x20 + chunkWordCountThenCodeCursor * 4;
    if (clipFlag != 0) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleCalculateTAVRTC,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpClip1AVRTC,chunkWordCountThenCodeCursor);
    chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    if (clipFlag != 0) {
      chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleClipExactWAVRTC,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
    }
    noBranchPending = true;
    chunkWordCount2 = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpClip2AVRTC,chunkWordCountThenCodeCursor);
    codeCursor = (uint *)(chunkWordCountThenCodeCursor + chunkWordCount2 * 4);
    if ((funcKey & 0x10) != 0) {
      *codeCursor = 0x39200020;
      codeCursor = codeCursor + 1;
      if ((funcKey & 3) == 1) {
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,codeCursor);
        codeCursor = codeCursor + chunkWordCount;
        srcEqualDestBranch = codeCursor + -1;
        noBranchPending = srcEqualDestBranch == (uint *)0x0;
        codeChunk = &_gleCopyVecAVRTC;
      }
      else {
        codeChunk = &_gleInterpVecAVRTC;
        noBranchPending = true;
      }
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(codeChunk,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    if ((funcKey & 0x20) != 0) {
      *codeCursor = 0x39200030;
      codeCursor = codeCursor + 1;
      if ((funcKey & 2) == 0) {
        if (noBranchPending) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,codeCursor);
          codeCursor = codeCursor + chunkWordCount;
          srcEqualDestBranch = codeCursor + -1;
          noBranchPending = srcEqualDestBranch == (uint *)0x0;
        }
        codeChunk = &_gleCopyVecAVRTC;
      }
      else {
        codeChunk = &_gleInterpVecAVRTC;
      }
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(codeChunk,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    if ((funcKey & 0x40) != 0) {
      *codeCursor = 0x39200040;
      codeCursor = codeCursor + 1;
      if ((funcKey & 2) == 0) {
        if (noBranchPending) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,codeCursor);
          codeCursor = codeCursor + chunkWordCount;
          srcEqualDestBranch = codeCursor + -1;
          noBranchPending = srcEqualDestBranch == (uint *)0x0;
        }
        codeChunk = &_gleCopyVecAVRTC;
      }
      else {
        codeChunk = &_gleInterpVecAVRTC;
      }
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(codeChunk,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    if ((funcKey & 0x100) != 0) {
      *codeCursor = 0x39200050;
      codeCursor = codeCursor + 1;
      if ((funcKey & 2) == 0) {
        if (noBranchPending) {
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,codeCursor);
          codeCursor = codeCursor + chunkWordCount;
          srcEqualDestBranch = codeCursor + -1;
          noBranchPending = srcEqualDestBranch == (uint *)0x0;
        }
        codeChunk = &_gleCopyVecAVRTC;
      }
      else {
        codeChunk = &_gleInterpVecAVRTC;
      }
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(codeChunk,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    if ((funcKey & 0x400) != 0) {
      if (noBranchPending) {
        chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleTestSrcEqualDestAVRTC,codeCursor);
        codeCursor = codeCursor + chunkWordCount;
        srcEqualDestBranch = codeCursor + -1;
        noBranchPending = srcEqualDestBranch == (uint *)0x0;
      }
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleCopyMaterialsAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    tailCodeCursor = codeCursor;
    if (((funcKey & 0x80) != 0) && ((funcKey & 0x42) != 0x42)) {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpFogAVRTC,codeCursor);
      tailCodeCursor = codeCursor + chunkWordCount;
    }
    if (((funcKey & 0x200) != 0) && ((funcKey & 0x102) != 0x102)) {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleInterpFogCoordAVRTC,tailCodeCursor);
      tailCodeCursor = tailCodeCursor + chunkWordCount;
    }
    if (funcKey >> 0x10 != 0) {
      loopIndex2 = 0;
      do {
        if ((funcKey & 0x10000 << (loopIndex2 & 0x3f)) != 0) {
          *tailCodeCursor = loopIndex2 * 0x10 + 0x80 & 0xffff | 0x39200000;
          if ((funcKey & 4) == 0) {
            codeChunk = &_gleInterpTexNoDivAVRTC;
          }
          else if (clipFlag == 0) {
            codeChunk = &_gleInterpTexTestAVRTC;
          }
          else {
            codeChunk = &_gleInterpTexAVRTC;
          }
          chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(codeChunk,tailCodeCursor + 1);
          tailCodeCursor = tailCodeCursor + 1 + chunkWordCount;
        }
      } while (((int)(loopIndex2 + 1) < 8) &&
              (unitShift = loopIndex2 + 0x11, loopIndex2 = loopIndex2 + 1, funcKey >> (unitShift & 0x3f) != 0));
    }
    if (clipFlag != 0) {
      chunkWordCount = ((int (*)())_gleRTCAddAChunk_51324)(&_gleSetReturnAVRTC,tailCodeCursor);
      tailCodeCursor = tailCodeCursor + chunkWordCount;
    }
    chunkWordCountThenTotalWords = ((int (*)())_gleRTCAddAChunk_51324)(&_gleEndAVRTC,tailCodeCursor);
    if (!noBranchPending) {
      branchInstruction = ((int (*)())_gleRTCBuildABranch_51354)(*srcEqualDestBranch,(int)codeCursor - (int)srcEqualDestBranch >> 2);
      *srcEqualDestBranch = branchInstruction;
    }
    chunkWordCountThenTotalWords = (int)tailCodeCursor + (chunkWordCountThenTotalWords * 4 - funcCacheElem) + -0x20 >> 2;
    if (0xa0 < chunkWordCountThenTotalWords) {
                    
      _exit(1);
    }
    funcCacheElem = _gleShrinkFuncCacheElem(funcCacheElem,chunkWordCountThenTotalWords);
    pushInstructionsFn = PTR__glePushInstructions_00112054;
    *funcCache = funcCacheElem;
    (**(code **)pushInstructionsFn)(chunkWordCountThenTotalWords,(int *)(funcCacheElem + 0x20));
    resultFunc = (int *)(funcCacheElem + 0x20);
  }
  return resultFunc;
}

/* _gleFeedbackPolygonPtr @ 0x51d9c (512 bytes) */
double _gleFeedbackPolygonPtr(glContext, param_2, param_3, param_4)
  undefined4 glContext;
  int *param_2;
  uint param_3;
  uint param_4;
{
  int *cursor;
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  int *piVar4;
  
  dVar2 = DOUBLE_00108d70;
  uVar1 = param_4 & 3;
  uVar3 = 0x707;
  if (uVar1 != 1) {
    if (uVar1 == 0) {
      piVar4 = param_2 + param_3;
      for (; param_2 < piVar4; param_2 = param_2 + 1) {
        if ((*(char *)(*param_2 + 0x7c) != '\0') && (*(char *)(*param_2 + 0x7d) == '\0')) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          ((double (*)())_gleFeedbackHitRecord)(glContext,*param_2);
        }
      }
      return;
    }
    if (uVar1 == 2) {
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) -
                                               DOUBLE_00108d58));
      piVar4 = param_2 + param_3;
      for (; param_2 < piVar4; param_2 = param_2 + 1) {
        ((double (*)())_gleFeedbackHitRecord)(glContext,*param_2);
      }
      return;
    }
    if (uVar1 != 3) {
      return;
    }
    uVar3 = 0x702;
  }
  for (cursor = param_2; cursor < param_2 + (param_3 - 1); cursor = cursor + 1) {
    if (*(char *)(*cursor + 0x7c) != '\0') {
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - dVar2));
      ((double (*)())_gleFeedbackHitRecord)(glContext,*cursor);
      ((double (*)())_gleFeedbackHitRecord)(glContext,cursor[1]);
      uVar3 = 0x702;
    }
  }
  if (*(char *)(*cursor + 0x7c) != '\0') {
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,uVar3) - DOUBLE_00108d70))
    ;
    ((double (*)())_gleFeedbackHitRecord)(glContext,*cursor);
    ((double (*)())_gleFeedbackHitRecord)(glContext,*param_2);
  }
  return;
}

/* _gleFeedbackHitRecord @ 0x51f9c (528 bytes) */
double _gleFeedbackHitRecord(glContext, param_2)
  int glContext;
  float *param_2;
{
  uint glContextWord4fd8;
  double fparam_1;
  
  if (*(char *)(glContext + 0x4fdc) == '\0') {
    glContextWord4fd8 = *(uint *)(glContext + 0x4fd8);
    if (glContextWord4fd8 == 0x601) {
      ((void (*)())_gleFeedbackToken)(glContext,(double)*param_2);
      ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[1]);
      fparam_1 = (double)param_2[2];
      goto LAB_000520f4;
    }
    if (glContextWord4fd8 < 0x602) {
      if (glContextWord4fd8 == 0x600) {
        ((void (*)())_gleFeedbackToken)(glContext,(double)*param_2);
        fparam_1 = (double)param_2[1];
        goto LAB_000520f4;
      }
    }
    else {
      if (glContextWord4fd8 == 0x602) {
        ((void (*)())_gleFeedbackToken)(glContext,(double)*param_2);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[1]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[2]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xc]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xd]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xe]);
        fparam_1 = (double)param_2[0xf];
LAB_000520f4:
        ((void (*)())_gleFeedbackToken)(glContext,fparam_1);
        return;
      }
      if (glContextWord4fd8 == 0x603) {
        ((void (*)())_gleFeedbackToken)(glContext,(double)*param_2);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[1]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[2]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xc]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xd]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xe]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xf]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x20]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x21]);
        ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x22]);
        fparam_1 = (double)param_2[0x23];
        goto LAB_000520f4;
      }
    }
    ((void (*)())_gleFeedbackToken)(glContext,(double)*param_2);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[1]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[2]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[7]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xc]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xd]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xe]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0xf]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x20]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x21]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x22]);
    ((void (*)())_gleFeedbackToken)(glContext,(double)param_2[0x23]);
  }
  return;
}

/* _gleMultiTextureMatTransPtr @ 0x521ac (120 bytes) */
void _gleMultiTextureMatTransPtr(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  uint uVar1;
  uint uVar2;
  uint loopIndex;
  
  uVar2 = _gleTexEnableBits(glContext);
  loopIndex = 0;
  do {
    uVar1 = uVar2 >> (loopIndex & 0x3f);
    if ((uVar1 & 1) == 0) {
      if (uVar1 == 0) {
        return;
      }
    }
    else {
      (**(code **)(glContext + 0x5078))(glContext,forwardedArg2,forwardedArg3,loopIndex);
    }
    loopIndex = loopIndex + 1;
  } while( true );
}

/* _glLoadMatrixd_Exec @ 0x52224 (128 bytes) */
int _glLoadMatrixd_Exec(glContext, m)
  int glContext;
  undefined4 m;
{
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    m = ((int (*)())_gleLoadMatrixd)(m,*(undefined4 *)(glContext + 0x4fec));
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
    *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return m;
}

/* _gleLoadMatrixd @ 0x522a4 (196 bytes) */
int _gleLoadMatrixd(m, param_2)
  double *m;
  float *param_2;
{
  *param_2 = (float)*m;
  param_2[1] = (float)m[1];
  param_2[2] = (float)m[2];
  param_2[3] = (float)m[3];
  param_2[4] = (float)m[4];
  param_2[5] = (float)m[5];
  param_2[6] = (float)m[6];
  param_2[7] = (float)m[7];
  param_2[8] = (float)m[8];
  param_2[9] = (float)m[9];
  param_2[10] = (float)m[10];
  param_2[0xb] = (float)m[0xb];
  param_2[0xc] = (float)m[0xc];
  param_2[0xd] = (float)m[0xd];
  param_2[0xe] = (float)m[0xe];
  param_2[0xf] = (float)m[0xf];
  return;
}

/* _glGetTexParameteriv_Exec @ 0x52368 (964 bytes) */
void _glGetTexParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  uint *params;
{
  float fVar1;
  float fVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int textureObject;
  
  textureObject = _gleLookUpNonProxyTexture(glContext,target);
  fVar2 = FLOAT_00108e94;
  fVar1 = FLOAT_00108e90;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00052714;
  }
  if (textureObject == 0) goto LAB_00052704;
  if (pname == (undefined *)0x813c) {
    uVar4 = (uint)*(short *)(textureObject + 0x60);
    goto LAB_00052644;
  }
  if ((undefined *)0x813c < pname) {
    if (pname == (undefined *)0x85b7) {
      uVar4 = *(uint *)(textureObject + 0x70);
      goto LAB_00052644;
    }
    if (pname < (undefined *)0x85b8) {
      if (pname == (undefined *)0x84fe) {
        fVar1 = *(float *)(textureObject + 0x50);
        goto LAB_00052638;
      }
      if (pname < (undefined *)0x84ff) {
        if (pname == (undefined *)0x813d) {
          uVar4 = (uint)*(short *)(textureObject + 0x62);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x8191) {
          uVar4 = *(uint *)(textureObject + 0x6c) >> 0xf & 1;
          goto LAB_00052644;
        }
      }
      else {
        if (pname == (undefined *)0x8501) {
          fVar1 = *(float *)(textureObject + 0x5c);
          goto LAB_00052638;
        }
        if (pname == (undefined *)0x85b6) {
          uVar4 = *(uint *)(textureObject + 0x6c) >> 7 & 1;
          goto LAB_00052644;
        }
      }
    }
    else {
      if (pname == (undefined *)0x884b) {
        uVar4 = (uint)*(ushort *)(textureObject + 0x6c);
        goto LAB_00052644;
      }
      if (pname < (undefined *)0x884c) {
        if (pname == (undefined *)0x85bc) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x3e);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x871a) {
          *params = (int)*(float *)(textureObject + 0x40);
          params[1] = (int)*(float *)(textureObject + 0x44);
          params[2] = (int)*(float *)(textureObject + 0x48);
          fVar1 = *(float *)(textureObject + 0x4c);
          goto LAB_000526f0;
        }
      }
      else {
        if (pname == (undefined *)0x884d) {
          uVar4 = (uint)*(ushort *)(textureObject + 100);
          goto LAB_00052644;
        }
        if (pname < (undefined *)0x884d) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x66);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x8a7f) {
          uVar4 = *(uint *)(textureObject + 0x6c) >> 6 & 1;
          goto LAB_00052644;
        }
      }
    }
LAB_00052704:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_00052714:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (pname == (undefined *)0x8066) {
    fVar1 = *(float *)(textureObject + 0x28);
  }
  else {
    if (pname < (undefined *)0x8067) {
      if (pname == (undefined *)0x2801) {
        uVar4 = (uint)*(ushort *)(textureObject + 0x3a);
        goto LAB_00052644;
      }
      if (pname < (undefined *)0x2802) {
        if (pname == ((unsigned char *)0x00001004)) {
          *params = (int)(*(float *)(textureObject + 0x40) * FLOAT_00108e94 - FLOAT_00108e90);
          params[1] = (int)(*(float *)(textureObject + 0x44) * fVar2 - fVar1);
          params[2] = (int)(*(float *)(textureObject + 0x48) * fVar2 - fVar1);
          fVar1 = *(float *)(textureObject + 0x4c) * fVar2 - fVar1;
LAB_000526f0:
          params[3] = (int)fVar1;
          return;
        }
        if (pname == (undefined *)0x2800) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x3c);
          goto LAB_00052644;
        }
      }
      else {
        if (pname == (undefined *)0x2802) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x34);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x2803) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x36);
          goto LAB_00052644;
        }
      }
      goto LAB_00052704;
    }
    if (pname == (undefined *)0x80bf) {
      fVar1 = *(float *)(textureObject + 0x68);
    }
    else {
      if (pname < (undefined *)0x80c0) {
        if (pname == (undefined *)0x8067) {
          uVar4 = (**(code **)(glContext + 0x47ac))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4));
          *params = uVar4;
          return;
        }
        if (pname == (undefined *)0x8072) {
          uVar4 = (uint)*(ushort *)(textureObject + 0x38);
          goto LAB_00052644;
        }
        goto LAB_00052704;
      }
      if (pname == (undefined *)0x813a) {
        fVar1 = *(float *)(textureObject + 0x54);
      }
      else {
        if (pname != (undefined *)0x813b) goto LAB_00052704;
        fVar1 = *(float *)(textureObject + 0x58);
      }
    }
  }
LAB_00052638:
  uVar4 = (uint)(int)fVar1;
LAB_00052644:
  *params = uVar4;
  return;
}

/* _glGetTexParameterfv_Exec @ 0x5272c (916 bytes) */
void _glGetTexParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  float *params;
{
  float fVar1;
  undefined4 glErrorCode;
  uint uVar3;
  int textureObject;
  
  textureObject = _gleLookUpNonProxyTexture(glContext,target);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00052aa8;
  }
  if (textureObject != 0) {
    if (pname == (undefined *)0x813c) {
      uVar3 = (uint)*(short *)(textureObject + 0x60);
LAB_000529b4:
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - DOUBLE_00108d58);
LAB_00052a3c:
      *params = fVar1;
      return;
    }
    if (pname < (undefined *)0x813d) {
      if (pname == (undefined *)0x8066) {
        fVar1 = *(float *)(textureObject + 0x28);
        goto LAB_00052a3c;
      }
      if (pname < (undefined *)0x8067) {
        if (pname == (undefined *)0x2801) {
          uVar3 = (uint)*(ushort *)(textureObject + 0x3a);
          goto LAB_00052a80;
        }
        if (pname < (undefined *)0x2802) {
          if (pname == ((unsigned char *)0x00001004)) {
LAB_0005294c:
            *params = *(float *)(textureObject + 0x40);
            params[1] = *(float *)(textureObject + 0x44);
            params[2] = *(float *)(textureObject + 0x48);
            params[3] = *(float *)(textureObject + 0x4c);
            return;
          }
          if (pname == (undefined *)0x2800) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x3c);
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x2802) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x34);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x2803) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x36);
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (pname == (undefined *)0x80bf) {
          fVar1 = *(float *)(textureObject + 0x68);
          goto LAB_00052a3c;
        }
        if (pname < (undefined *)0x80c0) {
          if (pname == (undefined *)0x8067) {
            uVar3 = (**(code **)(glContext + 0x47ac))
                              (*(undefined4 *)(glContext + 0x4688),
                               *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4));
            uVar3 = uVar3 & 0xffff;
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x8072) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x38);
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x813a) {
            fVar1 = *(float *)(textureObject + 0x54);
            goto LAB_00052a3c;
          }
          if (pname == (undefined *)0x813b) {
            fVar1 = *(float *)(textureObject + 0x58);
            goto LAB_00052a3c;
          }
        }
      }
    }
    else {
      if (pname == (undefined *)0x85b7) {
        uVar3 = *(uint *)(textureObject + 0x70);
        goto LAB_000529b4;
      }
      if (pname < (undefined *)0x85b8) {
        if (pname == (undefined *)0x84fe) {
          fVar1 = *(float *)(textureObject + 0x50);
          goto LAB_00052a3c;
        }
        if (pname < (undefined *)0x84ff) {
          if (pname == (undefined *)0x813d) {
            uVar3 = (uint)*(short *)(textureObject + 0x62);
            goto LAB_000529b4;
          }
          if (pname == (undefined *)0x8191) {
            uVar3 = *(uint *)(textureObject + 0x6c) >> 0xf & 1;
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x8501) {
            fVar1 = *(float *)(textureObject + 0x5c);
            goto LAB_00052a3c;
          }
          if (pname == (undefined *)0x85b6) {
            uVar3 = *(uint *)(textureObject + 0x6c) >> 7 & 1;
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (pname == (undefined *)0x884b) {
          uVar3 = (uint)*(ushort *)(textureObject + 0x6c);
          goto LAB_00052a80;
        }
        if (pname < (undefined *)0x884c) {
          if (pname == (undefined *)0x85bc) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x3e);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x871a) goto LAB_0005294c;
        }
        else {
          if (pname == (undefined *)0x884d) {
            uVar3 = (uint)*(ushort *)(textureObject + 100);
LAB_00052a80:
            *params = GH_U2F((unsigned int)((uVar3 | 0x4b000000))) - 8388608.0;
            return;
          }
          if (pname < (undefined *)0x884d) {
            uVar3 = (uint)*(ushort *)(textureObject + 0x66);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x8a7f) {
            uVar3 = *(uint *)(textureObject + 0x6c) >> 6 & 1;
            goto LAB_00052a80;
          }
        }
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00052aa8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColor4d_Exec @ 0x52ac0 (60 bytes) */
void _glColor4d_Exec(int glContext,double red,double green,double blue,double alpha)
{
  *(float *)(glContext + 0x2a0) = (float)red;
  *(float *)(glContext + 0x2a4) = (float)green;
  *(float *)(glContext + 0x2a8) = (float)blue;
  *(float *)(glContext + 0x2ac) = (float)alpha;
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glFinishObjectAPPLE_Exec @ 0x52afc (900 bytes) */
void _glFinishObjectAPPLE_Exec(glContext, object, name)
  int glContext;
  uint object;
  undefined4 name;
{
  uint loopIndex5;
  uint loopIndex4;
  uint loopIndex3;
  uint loopIndex2;
  undefined4 glErrorCode;
  int *rendererDispatch;
  undefined4 *rendererHandlePtr;
  undefined4 objectKind;
  int hashObject;
  undefined4 rendererObjectName;
  int rendererSlotCursor;
  uint loopIndex;
  undefined4 *srcCursor;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00052bec;
  }
  if (object == 0x8a0a) {
    return;
  }
  if (object < 0x8a0b) {
    if (object == 0x8074) {
      objectKind = 2;
    }
    else if (object < 0x8075) {
      if (object != 0x1702) {
LAB_00052bdc:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
LAB_00052bec:
        *(undefined4 *)(glContext + 0x7574) = glErrorCode;
        return;
      }
      objectKind = 1;
    }
    else {
      if (object != 0x85b3) goto LAB_00052bdc;
      objectKind = 3;
    }
  }
  else if (object == 0x8d40) {
    objectKind = 5;
  }
  else if (object < 0x8d41) {
    if (object != 0x8a0b) goto LAB_00052bdc;
    objectKind = 0;
  }
  else {
    if (object != 0x8d41) goto LAB_00052bdc;
    objectKind = 4;
  }
  switch(objectKind) {
  case 0:
    hashObject = _gleLookupHashObject(glContext + 0x543c,name);
    if (hashObject != 0) {
      rendererSlotCursor = glContext + 0x10000;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) == '\0') {
        return;
      }
      srcCursor = (undefined4 *)(hashObject + 0x10);
      do {
        rendererDispatch = (int *)(rendererSlotCursor + -0x777c);
        rendererObjectName = *srcCursor;
        loopIndex = loopIndex + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1c4))(*rendererHandlePtr,objectKind,rendererObjectName);
      } while (loopIndex < *(byte *)(glContext + 0x85a4));
      return;
    }
    break;
  case 1:
    hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x2008,name);
    if (hashObject != 0) {
      rendererSlotCursor = glContext + 0x10000;
      loopIndex2 = 0;
      if (*(char *)(glContext + 0x85a4) == '\0') {
        return;
      }
      srcCursor = (undefined4 *)(hashObject + 0x10);
      do {
        rendererDispatch = (int *)(rendererSlotCursor + -0x777c);
        rendererObjectName = *srcCursor;
        loopIndex2 = loopIndex2 + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1c4))(*rendererHandlePtr,objectKind,rendererObjectName);
      } while (loopIndex2 < *(byte *)(glContext + 0x85a4));
      return;
    }
    break;
  case 2:
    hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x5014,name);
    if (hashObject != 0) {
      rendererSlotCursor = glContext + 0x10000;
      loopIndex3 = 0;
      if (*(char *)(glContext + 0x85a4) == '\0') {
        return;
      }
      srcCursor = (undefined4 *)(hashObject + 0x10);
      do {
        rendererDispatch = (int *)(rendererSlotCursor + -0x777c);
        rendererObjectName = *srcCursor;
        loopIndex3 = loopIndex3 + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1c4))(*rendererHandlePtr,objectKind,rendererObjectName);
      } while (loopIndex3 < *(byte *)(glContext + 0x85a4));
      return;
    }
    break;
  case 3:
    hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x701c,name);
    if (hashObject != 0) {
      rendererSlotCursor = glContext + 0x10000;
      loopIndex4 = 0;
      if (*(char *)(glContext + 0x85a4) == '\0') {
        return;
      }
      srcCursor = (undefined4 *)(hashObject + 0x10);
      do {
        rendererDispatch = (int *)(rendererSlotCursor + -0x777c);
        rendererObjectName = *srcCursor;
        loopIndex4 = loopIndex4 + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1c4))(*rendererHandlePtr,objectKind,rendererObjectName);
      } while (loopIndex4 < *(byte *)(glContext + 0x85a4));
      return;
    }
    break;
  case 4:
    hashObject = _gleLookupHashObject(((unsigned char *)0x00001004) + *(int *)(glContext + 0x5148),name);
    if (hashObject != 0) {
      rendererSlotCursor = glContext + 0x10000;
      loopIndex5 = 0;
      if (*(char *)(glContext + 0x85a4) == '\0') {
        return;
      }
      srcCursor = (undefined4 *)(hashObject + 0x10);
      do {
        rendererDispatch = (int *)(rendererSlotCursor + -0x777c);
        rendererObjectName = *srcCursor;
        loopIndex5 = loopIndex5 + 1;
        srcCursor = srcCursor + 1;
        rendererHandlePtr = (undefined4 *)(rendererSlotCursor + -0x7a54);
        rendererSlotCursor = rendererSlotCursor + 0x2e0;
        (**(code **)(*rendererDispatch + 0x1c4))(*rendererHandlePtr,objectKind,rendererObjectName);
      } while (loopIndex5 < *(byte *)(glContext + 0x85a4));
      return;
    }
    break;
  case 5:
    goto switchD_00052c3c_caseD_5;
  default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00052e80;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    glErrorCode = 0x502;
LAB_00052e80:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
switchD_00052c3c_caseD_5:
  return;
}

/* _gleSetEnable_POLYGON_SMOOTH @ 0x52e98 (20 bytes) */
void _gleSetEnable_POLYGON_SMOOTH(param_1, unusedArg2, param_3)
  int param_1;
  undefined4 unusedArg2;
  undefined4 param_3;
{
  *(undefined1 *)(param_1 + 0x34d9) = (undefined1)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x800000;
  return;
}

/* _gleFogExp @ 0x52eac (88 bytes) */
double _gleFogExp(int param_1,float fparam_1)
{
  float fVar1;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x24);
  if ((double)FLOAT_00108e50 < fparam_1) {
    fparam_1 = -fparam_1;
  }
  fVar1 = (*(float *)(param_1 + 0x3150) * fparam_1);
  return (double)(fVar2 / ((((*(float *)(param_1 + 0x38) * fVar1 - *(float *)(param_1 + 0x34)) *
                             fVar1 + *(float *)(param_1 + 0x30)) * fVar1 - fVar2) * fVar1 + fVar2));
}

/* _glFogi_Exec @ 0x52f04 (652 bytes) */
void _glFogi_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  uint param;
{
  bool bVar1;
  byte bVar2;
  undefined4 glErrorCode;
  undefined2 uVar4;
  int iVar5;
  int glContextPtr5424;
  int iVar6;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0005301c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (pname == 0xb64) {
    bVar1 = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3158) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0xb64 < pname) {
      uVar4 = (undefined2)param;
      if (pname == 0x8450) {
        if (param - 0x8451 < 2) {
          *(undefined2 *)(glContext + 0x3166) = uVar4;
          _gleSelectVertexSubmitFunc(glContext);
          goto LAB_00053168;
        }
      }
      else if (pname < 0x8451) {
        if (((pname == 0xb65) && (0x7ff < (int)param)) &&
           (((int)param < 0x802 || (param == 0x2601)))) {
          *(undefined2 *)(glContext + 0x3164) = uVar4;
          goto LAB_00053168;
        }
      }
      else if ((pname == 0x855a) &&
              ((param == 0x2502 || ((0x2501 < (int)param && (param - 0x855b < 2)))))) {
        *(undefined2 *)(glContext + 0x3168) = uVar4;
        goto LAB_00053168;
      }
LAB_00053154:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_00053168;
    }
    if (pname == 0xb62) {
      if ((int)param < 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_0005301c;
      }
      bVar1 = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3150) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
    else {
      if (pname < 0xb63) {
        if (pname == 0xb61) {
          *(float *)(glContext + 0x3160) =
               (float)((double)CONCAT44(0x43300000,param * 0x101 ^ 0x80000000) - DOUBLE_00108d58);
          goto LAB_00053168;
        }
        goto LAB_00053154;
      }
      bVar1 = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3154) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
  if (bVar1) {
    bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
  }
  else {
    bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
  }
  iVar6 = (bVar2 >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar2 & 0x1f);
  bVar2 = *(byte *)(glContextPtr5424 + 0x323);
  iVar5 = (bVar2 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar5 + 0x348) = *(uint *)(iVar5 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_00053168:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _gleFogLinear @ 0x53190 (92 bytes) */
double _gleFogLinear(int param_1,float fparam_1)
{
  float dVar1;
  
  if ((double)FLOAT_00108e50 < fparam_1) {
    fparam_1 = -fparam_1;
  }
  dVar1 = (double)((*(float *)(param_1 + 0x3158) + fparam_1) *
                  *(float *)(param_1 + 0x315c));
  if ((double)*(float *)(param_1 + 0x24) < (double)dVar1) {
    return (double)*(float *)(param_1 + 0x24);
  }
  if (!((double)dVar1 < (double)FLOAT_00108e50)) {
    return (double)dVar1;
  }
  return (double)FLOAT_00108e50;
}

/* _glFogfv_Exec @ 0x531ec (1096 bytes) */
void _glFogfv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  float *params;
{
  float floatZero;
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float floatOne;
  undefined4 glErrorCode;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  int glContextPtr5424;
  int iVar10;
  float dVar11;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000533ac:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (pname == 0xb64) {
    bVar1 = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3158) = *params;
LAB_00053594:
    if (bVar1) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(glContextPtr5424 + 0x323);
  }
  else {
    if (pname < 0xb65) {
      if (pname == 0xb62) {
        if (*params < FLOAT_00108e50) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x501;
          goto LAB_000533ac;
        }
        *(float *)(glContext + 0x3150) = *params;
        bVar1 = *(int *)(glContext + 0x5434) == 0;
      }
      else {
        if (pname < 0xb63) {
          if (pname == 0xb61) {
            *(float *)(glContext + 0x3160) = *params * FLOAT_00108e5c;
            goto LAB_0005360c;
          }
          goto LAB_000535f8;
        }
        bVar1 = *(int *)(glContext + 0x5434) == 0;
        *(float *)(glContext + 0x3154) = *params;
      }
      goto LAB_00053594;
    }
    if (pname != 0xb66) {
      if (pname < 0xb66) {
        dVar11 = (double)*params;
        if (DOUBLE_00108d80 <= (double)dVar11) {
          uVar8 = (int)((double)dVar11 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar8 = (uint)(int)*params;
        }
        if (uVar8 != 0x801) {
          if (uVar8 < 0x802) {
            bVar1 = uVar8 == 0x800;
          }
          else {
            bVar1 = uVar8 == 0x2601;
          }
          if (!bVar1) goto LAB_000535f8;
        }
        *(short *)(glContext + 0x3164) = (short)uVar8;
      }
      else {
        if (pname == 0x8450) {
          fVar4 = *params;
          dVar11 = (double)fVar4;
          if (DOUBLE_00108d80 <= (double)dVar11) {
            uVar8 = (int)((double)dVar11 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)fVar4;
          }
          if (uVar8 - 0x8451 < 2) {
            if (DOUBLE_00108d80 <= (double)dVar11) {
              uVar7 = (undefined2)(int)((double)dVar11 - DOUBLE_00108d80);
            }
            else {
              uVar7 = (undefined2)(int)fVar4;
            }
            *(undefined2 *)(glContext + 0x3166) = uVar7;
            _gleSelectVertexSubmitFunc(glContext);
            goto LAB_0005360c;
          }
        }
        else if (pname == 0x855a) {
          fVar4 = *params;
          dVar11 = (double)fVar4;
          if (DOUBLE_00108d80 <= (double)dVar11) {
            uVar8 = (int)((double)dVar11 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)fVar4;
          }
          if ((uVar8 == 0x2502) || ((0x2501 < uVar8 && (uVar8 - 0x855b < 2)))) {
            if (DOUBLE_00108d80 <= (double)dVar11) {
              uVar7 = (undefined2)(int)((double)dVar11 - DOUBLE_00108d80);
            }
            else {
              uVar7 = (undefined2)(int)fVar4;
            }
            *(undefined2 *)(glContext + 0x3168) = uVar7;
            goto LAB_0005360c;
          }
        }
LAB_000535f8:
        if (*(int *)(glContext + 0x7574) == 0) {
          *(undefined4 *)(glContext + 0x7574) = 0x500;
        }
      }
      goto LAB_0005360c;
    }
    fVar3 = *params;
    if (fVar3 < FLOAT_00108e50) {
      *(float *)(glContext + 0x3140) = FLOAT_00108e50;
    }
    else if (FLOAT_00108e54 < fVar3) {
      *(float *)(glContext + 0x3140) = FLOAT_00108e54;
    }
    else {
      *(float *)(glContext + 0x3140) = fVar3;
    }
    fVar3 = params[1];
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x3144) = floatZero;
    }
    else if (floatOne < fVar3) {
      *(float *)(glContext + 0x3144) = floatOne;
    }
    else {
      *(float *)(glContext + 0x3144) = fVar3;
    }
    fVar3 = params[2];
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x3148) = floatZero;
    }
    else if (floatOne < fVar3) {
      *(float *)(glContext + 0x3148) = floatOne;
    }
    else {
      *(float *)(glContext + 0x3148) = fVar3;
    }
    fVar3 = params[3];
    if (fVar3 < floatZero) {
      *(float *)(glContext + 0x314c) = floatZero;
    }
    else if (floatOne < fVar3) {
      *(float *)(glContext + 0x314c) = floatOne;
    }
    else {
      *(float *)(glContext + 0x314c) = fVar3;
    }
    if (*(int *)(glContext + 0x5434) == 0) {
      bVar2 = *(byte *)(*(int *)(glContext + 0x5420) + 0x322);
    }
    else {
      bVar2 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x356);
    }
    iVar10 = (bVar2 >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar10 + 0x324) = *(uint *)(iVar10 + 0x324) | 1 << (bVar2 & 0x1f);
    bVar2 = *(byte *)(glContextPtr5424 + 0x322);
  }
  iVar9 = (bVar2 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar9 + 0x348) = *(uint *)(iVar9 + 0x348) | 1 << (bVar2 & 0x1f);
LAB_0005360c:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _glFogf_Exec @ 0x53634 (700 bytes) */
void _glFogf_Exec(int glContext,uint pname,double param)
{
  byte bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int glContextPtr5424;
  int glContextWord5434;
  uint uVar4;
  int iVar5;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000536f4:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (pname == 0xb64) {
    glContextWord5434 = *(int *)(glContext + 0x5434);
    *(float *)(glContext + 0x3158) = (float)param;
  }
  else {
    if (0xb64 < pname) {
      if (pname == 0x8450) {
        if (DOUBLE_00108d80 <= param) {
          uVar4 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar4 = (uint)(int)param;
        }
        if (uVar4 - 0x8451 < 2) {
          *(short *)(glContext + 0x3166) = (short)uVar4;
          _gleSelectVertexSubmitFunc(glContext);
          goto LAB_000538c8;
        }
      }
      else if (pname < 0x8451) {
        if (pname == 0xb65) {
          if (DOUBLE_00108d80 <= param) {
            uVar4 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar4 = (uint)(int)param;
          }
          if ((0x7ff < uVar4) && ((uVar4 < 0x802 || (uVar4 == 0x2601)))) {
            *(short *)(glContext + 0x3164) = (short)uVar4;
            goto LAB_000538c8;
          }
        }
      }
      else if (pname == 0x855a) {
        if (DOUBLE_00108d80 <= param) {
          uVar4 = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar4 = (uint)(int)param;
        }
        if ((uVar4 == 0x2502) || ((0x2501 < uVar4 && (uVar4 - 0x855b < 2)))) {
          *(short *)(glContext + 0x3168) = (short)uVar4;
          goto LAB_000538c8;
        }
      }
LAB_000538b4:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x500;
      }
      goto LAB_000538c8;
    }
    if (pname == 0xb62) {
      if (param < (double)FLOAT_00108e50) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x501;
        goto LAB_000536f4;
      }
      glContextWord5434 = *(int *)(glContext + 0x5434);
      *(float *)(glContext + 0x3150) = (float)param;
    }
    else {
      if (pname < 0xb63) {
        if (pname == 0xb61) {
          *(float *)(glContext + 0x3160) = (float)(param * (double)FLOAT_00108e5c);
          goto LAB_000538c8;
        }
        goto LAB_000538b4;
      }
      glContextWord5434 = *(int *)(glContext + 0x5434);
      *(float *)(glContext + 0x3154) = (float)param;
    }
  }
  if (glContextWord5434 == 0) {
    bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
  }
  else {
    bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
  }
  iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
  bVar1 = *(byte *)(glContextPtr5424 + 0x323);
  iVar3 = (bVar1 >> 3 & 0x1c) + glContext;
  *(uint *)(iVar3 + 0x348) = *(uint *)(iVar3 + 0x348) | 1 << (bVar1 & 0x1f);
LAB_000538c8:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _gleLightMaterialRGBAChange_FB_AD @ 0x538f0 (344 bytes) */
void _gleLightMaterialRGBAChange_FB_AD(glContext, param_2)
  int glContext;
  undefined8 *param_2;
{
  byte bVar1;
  undefined8 *puVar2;
  int glContextWord5424;
  int iVar4;
  int glContextWord5434;
  int iVar5;
  int iVar6;
  int loopIndex;
  undefined8 uVar8;
  
  loopIndex = 0;
  do {
    puVar2 = (undefined8 *)_glePushMaterial(glContext,loopIndex);
    *puVar2 = *param_2;
    puVar2[1] = param_2[1];
    puVar2[2] = *param_2;
    uVar8 = param_2[1];
    *(ushort *)((int)puVar2 + 0x234) = *(ushort *)((int)puVar2 + 0x234) | 0xc0c;
    puVar2[3] = uVar8;
    glContextWord5434 = *(int *)(glContext + 0x5434);
    if (glContextWord5434 == 0) {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c0);
    }
    else {
      bVar1 = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f4);
    }
    iVar5 = loopIndex * 6;
    iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(iVar6 + 0x324) = *(uint *)(iVar6 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar5 + glContextWord5424 + 0x2c0);
    iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
    if (glContextWord5434 == 0) {
      bVar1 = *(byte *)(iVar5 + *(int *)(glContext + 0x5420) + 0x2c1);
    }
    else {
      bVar1 = *(byte *)(iVar5 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f5);
    }
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    *(uint *)(iVar4 + 0x324) = *(uint *)(iVar4 + 0x324) | 1 << (bVar1 & 0x1f);
    bVar1 = *(byte *)(iVar5 + glContextWord5424 + 0x2c1);
    iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
    *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _glCopyTexImage2D_Exec @ 0x53a48 (1780 bytes) */
void _glCopyTexImage2D_Exec(int glContext,int target,uint level,undefined4 internalformat,undefined4 x,undefined4 y,int width,int height,undefined4 border,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool rendererByte79Clear;
  bool noStateChangePending;
  char rendererInfoByte79;
  ushort objectFlags;
  undefined4 forwardedArg4;
  int *srcCursor;
  int levelRecord;
  byte levelFlags;
  uint nextMipLevel;
  uint glContextWord314;
  int pluginResult;
  int createResultThenMaskBase;
  int dirtyWord;
  int copyWidthThenLevelCursor;
  int framebufferObject;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  int textureObject;
  int matrixChangeBits;
  uint uVar15;
  uint changeWord3;
  uint texUnit;
  int copyHeight;
  int *changeWordCursor;
  int textureLevel;
  double extraout_f1;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    uVar15 = level;
    forwardedArg4 = internalformat;
    forwardedArg5 = x;
    forwardedArg6 = y;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar15,forwardedArg4,forwardedArg5,forwardedArg6,matrixChangeBits,fparam_1,forwardedFloatArg2,
                   forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      }
      if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00053b9c:
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
          goto LAB_00053b9c;
        }
      }
      rendererByte79Clear = rendererInfoByte79 == '\0';
      if (rendererByte79Clear) {
        changeWord3 = changeWord3 & 0x17000000;
      }
      else {
        changeWord3 = changeWord3 & 0x17ffffff;
      }
      if (rendererByte79Clear) {
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
          uVar15 = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
          if ((((uVar15 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((uVar15 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((uVar15 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((uVar15 & 4) == 0) {
              uVar15 = uVar15 & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,uVar15);
            if (*(char *)(glContext + 0x759d) == '\0') {
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x506;
              goto LAB_00053d34;
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
  }
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_00053d24:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00053d34:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  textureObject = ((int (*)())_gleCheckCopyTexImage2DArgs)(glContext,target,level,internalformat,width,height,border);
  if (textureObject == 0) {
    return;
  }
  objectFlags = *(ushort *)(textureObject + 0x24);
  if ((objectFlags & 0x3c00) != 0x1000) {
    if ((objectFlags & 0x3c00) == 0) {
      *(ushort *)(textureObject + 0x24) = objectFlags | 0x1000;
    }
    else if ((objectFlags & 0xc00) != 0) goto LAB_00053d24;
  }
  copyWidthThenLevelCursor = width;
  copyHeight = height;
  if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
    if (((*(uint *)(glContext + 0x3410) & 4) != 0) && (*(short *)(glContext + 0x3348) == -0x7fea)) {
      copyHeight = *(int *)(glContext + 0x3354);
      copyWidthThenLevelCursor = *(int *)(glContext + 0x3350);
      goto LAB_00053d90;
    }
  }
  else if (*(short *)(glContext + 0x3308) == -0x7fea) {
    copyHeight = *(int *)(glContext + 0x3314);
    copyWidthThenLevelCursor = *(int *)(glContext + 0x3310);
LAB_00053d90:
    copyWidthThenLevelCursor = (width - copyWidthThenLevelCursor) + 1;
    copyHeight = (height - copyHeight) + 1;
  }
  uVar15 = target - 0x8515;
  if (5 < uVar15) {
    uVar15 = 0;
  }
  levelRecord = textureObject + uVar15 * 0x168 + level * 0x18;
  textureLevel = levelRecord + 0xc4;
  if ((*(byte *)(levelRecord + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(glContext,textureObject,textureLevel,uVar15,level);
    if (*(int *)(levelRecord + 0xd8) != 0) {
      levelFlags = *(byte *)(levelRecord + 0xcf);
      if ((levelFlags & 1) == 0) {
        _gleFreeTextureLevel(glContext,textureObject,textureLevel);
        levelFlags = *(byte *)(levelRecord + 0xcf);
      }
      else {
        *(undefined4 *)(levelRecord + 0xd8) = 0;
      }
      *(byte *)(levelRecord + 0xcf) = levelFlags & 0xef;
    }
    *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) & 0xdf;
  }
  createResultThenMaskBase = _gleCreateTextureLevel
                     (glContext,textureObject,textureLevel,internalformat,copyWidthThenLevelCursor,copyHeight,1,border,0x1908,0x1401,0,0);
  if (createResultThenMaskBase != 0) {
    _gleCreatePluginTextureLevel(glContext,textureObject,textureLevel,uVar15,level,internalformat);
    if ((((int)level < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
        ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)level)) ||
       (createResultThenMaskBase = uVar15 * 2 + textureObject, (*(ushort *)(createResultThenMaskBase + 0x94) >> (level & 0x3f) & 1) == 0)) {
LAB_00053fcc:
      levelFlags = *(byte *)(levelRecord + 0xcf);
    }
    else {
      levelFlags = *(byte *)(levelRecord + 0xcf);
      if ((levelFlags & 0x80) == 0) {
        pluginResult = (**(code **)(glContext + 0x470c))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),uVar15,
                           level,0,0,0,x);
        if (pluginResult != 0) {
          *(undefined4 *)(textureObject + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) | 0x40;
          if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) &&
              ((int)*(short *)(textureObject + 0x60) == level)) &&
             (nextMipLevel = level + 1, (int)nextMipLevel <= (int)(uint)*(byte *)(textureObject + 0x83))) {
            copyWidthThenLevelCursor = nextMipLevel * 0x18 + uVar15 * 0x168 + textureObject + 0xc4;
            do {
              if (*(int *)(copyWidthThenLevelCursor + 0x14) != 0) {
                if (((*(byte *)(copyWidthThenLevelCursor + 0xb) & 1) == 0) && (*(short *)(textureObject + 0x3e) == -0x7a43))
                {
                  _gleFreeTextureLevel(glContext,textureObject,copyWidthThenLevelCursor);
                }
                *(byte *)(copyWidthThenLevelCursor + 0xb) = *(byte *)(copyWidthThenLevelCursor + 0xb) & 0xef;
                *(ushort *)(createResultThenMaskBase + 0xa0) =
                     *(ushort *)(createResultThenMaskBase + 0xa0) & ~(ushort)(1 << (nextMipLevel & 0x3f));
              }
              nextMipLevel = nextMipLevel + 1;
              *(byte *)(copyWidthThenLevelCursor + 0xb) = *(byte *)(copyWidthThenLevelCursor + 0xb) | 0x40;
              copyWidthThenLevelCursor = copyWidthThenLevelCursor + 0x18;
            } while ((int)nextMipLevel <= (int)(uint)*(byte *)(textureObject + 0x83));
          }
          texUnit = *(uint *)(glContext + 0x53d4);
          glContextWord314 = *(uint *)(glContext + 0x314);
          goto LAB_00054120;
        }
        goto LAB_00053fcc;
      }
    }
    if ((levelFlags & 0x10) == 0) {
      if ((levelFlags & 0x40) == 0) {
        if (*(int *)(levelRecord + 0xd8) == 0) {
          _gleAllocateTextureLevel(glContext,textureObject,textureLevel);
          levelFlags = *(byte *)(levelRecord + 0xcf);
        }
        *(byte *)(levelRecord + 0xcf) = levelFlags | 0x10;
      }
      else {
        _gleUploadPluginTextureLevel
                  (glContext,textureObject,textureLevel,uVar15,level,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel(glContext,textureObject,textureLevel,uVar15,level,0,0,0,copyWidthThenLevelCursor,copyHeight,1);
    _gleTextureImageCopy(glContext,textureLevel,internalformat,x,y,width,height);
    if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) && ((int)*(short *)(textureObject + 0x60) == level))
       && (textureObject = _gleGenMipmapsToLevel(glContext,textureObject,uVar15,level,0xf,1), textureObject != 0)) {
      return;
    }
  }
  texUnit = *(uint *)(glContext + 0x53d4);
  glContextWord314 = *(uint *)(glContext + 0x314);
LAB_00054120:
  *(uint *)(glContext + 0x314) = glContextWord314 | 1 << (texUnit & 0x3f);
  return;
}

/* _gleCheckCopyTexImage2DArgs @ 0x5413c (492 bytes) */
int _gleCheckCopyTexImage2DArgs(glContext, target, level, internalformat, width, height, border)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  int border;
{
  undefined4 glErrorCode;
  ushort uVar1;
  int iVar2;
  int glContextPtr468c;
  int textureObject;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  textureObject = _gleLookUpNonProxyTexture2D(glContext,target);
  uVar4 = 1;
  uVar7 = 1;
  if (textureObject == 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      glErrorCode = 0x500;
LAB_000542e0:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    }
LAB_000542e4:
    iVar2 = 0;
  }
  else {
    if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
      if (((*(uint *)(glContext + 0x3410) & 4) != 0) && (*(short *)(glContext + 0x3348) == -0x7fea)) {
        iVar6 = *(int *)(glContext + 0x3354);
        iVar2 = *(int *)(glContext + 0x3350);
        goto LAB_000541e0;
      }
    }
    else if (*(short *)(glContext + 0x3308) == -0x7fea) {
      iVar6 = *(int *)(glContext + 0x3314);
      iVar2 = *(int *)(glContext + 0x3310);
LAB_000541e0:
      width = (width - iVar2) + 1;
      height = (height - iVar6) + 1;
    }
    uVar8 = height + border * -2;
    uVar9 = width + border * -2;
    uVar1 = *(ushort *)(textureObject + 0x24) & 0xf;
    if (uVar1 == 2) {
      uVar7 = 0;
      if ((((int)uVar9 < 0) ||
          (uVar5 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc0), (int)uVar5 < (int)uVar9))
         || ((int)uVar8 < 0)) goto LAB_000542d0;
LAB_000542cc:
      if ((int)uVar5 < (int)uVar8) {
LAB_000542d0:
        if (*(int *)(glContext + 0x7574) == 0) {
          glErrorCode = 0x501;
          goto LAB_000542e0;
        }
        goto LAB_000542e4;
      }
    }
    else if (uVar1 < 3) {
      if ((*(ushort *)(textureObject + 0x24) & 0xf) == 0) {
        uVar4 = 0;
        if ((uVar9 != uVar8) ||
           ((int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2) < (int)uVar8))
        goto LAB_000542d0;
LAB_00054244:
        if (-1 < (int)uVar9) {
          if ((uVar9 & uVar9 - 1) == 0) {
            glContextPtr468c = *(int *)(glContext + 0x468c);
          }
          else {
            glContextPtr468c = *(int *)(glContext + 0x468c);
            if ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) == 0) goto LAB_000542d0;
          }
          uVar5 = (uint)*(ushort *)(glContextPtr468c + 0xbc);
          if ((((int)uVar9 <= (int)uVar5) && (-1 < (int)uVar8)) &&
             (((uVar8 & uVar8 - 1) == 0 || ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) != 0))))
          goto LAB_000542cc;
        }
        goto LAB_000542d0;
      }
    }
    else if (uVar1 == 3) goto LAB_00054244;
    iVar6 = ((int (*)())_gleCheckCopyTexImageArgs)(glContext,level,internalformat,border,uVar4,uVar7);
    iVar2 = 0;
    if (iVar6 != 0) {
      iVar2 = textureObject;
    }
  }
  return iVar2;
}

/* _gleCheckCopyTexImageArgs @ 0x54328 (552 bytes) */
int _gleCheckCopyTexImageArgs(glContext, level, internalformat, border, param_5, param_6)
  int glContext;
  uint level;
  int internalformat;
  uint border;
  int param_5;
  int param_6;
{
  bool bVar1;
  undefined4 glErrorCode;
  uint uVar3;
  
  bVar1 = true;
  if (0xe < level) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
    bVar1 = false;
  }
  if (!bVar1) {
    return 0;
  }
  if (internalformat < 0x83f4) {
    if (0x83ef < internalformat) goto LAB_00054528;
    if (internalformat < 0x804e) {
      if (internalformat < 0x803b) {
        if (internalformat == 0x1902) goto LAB_000544f8;
        if (internalformat < 0x1903) {
          bVar1 = 3 < internalformat - 1U;
          goto LAB_000544e0;
        }
        if (internalformat < 0x1906) goto LAB_000544e4;
        if (0x190a < internalformat) {
          bVar1 = internalformat == 0x2a10;
          goto LAB_00054478;
        }
      }
      goto LAB_00054528;
    }
    if (32999 < internalformat) {
      if (2 < internalformat - 0x81a5U) goto LAB_000544e4;
LAB_000544f8:
      if (param_5 == 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return 0;
        }
        glErrorCode = 0x502;
        goto LAB_00054544;
      }
      goto LAB_00054528;
    }
    if (internalformat < 0x80e2) {
      uVar3 = internalformat - 0x804f;
      goto LAB_000544b8;
    }
    if (param_6 != 0) goto LAB_00054528;
  }
  else {
    if (internalformat < 0x8700) {
      if (internalformat < 0x86fe) {
        if (0x86f6 < internalformat) {
          bVar1 = 4 < internalformat - 0x86f8U;
          goto LAB_000544e0;
        }
        if (internalformat < 0x86f4) {
          if (internalformat < 0x84e9) goto LAB_000544e4;
          if (0x84ee < internalformat) {
            bVar1 = internalformat == 0x86dc;
LAB_00054478:
            if (!bVar1) goto LAB_000544e4;
          }
        }
      }
    }
    else if (internalformat < 0x8820) {
      if (internalformat < 0x8814) {
        uVar3 = internalformat - 0x8701;
LAB_000544b8:
        bVar1 = 0xc < uVar3;
LAB_000544e0:
        if (bVar1) {
LAB_000544e4:
          if (*(int *)(glContext + 0x7574) != 0) {
            return 0;
          }
          glErrorCode = 0x501;
          goto LAB_00054544;
        }
      }
    }
    else if (internalformat != 0x8837) {
      if (internalformat < 0x8837) goto LAB_000544e4;
      bVar1 = 1 < internalformat - 0x885eU;
      goto LAB_000544e0;
    }
LAB_00054528:
    if ((border & 0xfffffffe) == 0) {
      return 1;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x500;
LAB_00054544:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glRasterPos2i_Exec @ 0x54550 (740 bytes) */
void _glRasterPos2i_Exec(int glContext,uint x,uint y,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint uVar7;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixChangeBits = *(int *)(glContext + 0x50ac);
      uVar7 = y;
      if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        fparam_1 = extraout_f1;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        changeWordCursor = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar7,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                     forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000546a8:
          changeWord3 = *(uint *)(glContext + 0x31c);
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
          changeWord3 = *(uint *)(glContext + 0x31c);
          if ((changeWord3 & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_000546a8;
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
                goto LAB_000547a4;
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
    }
    ((void (*)())_gleSetRasterPos)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                            DOUBLE_00108d58),
                     (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) -
                                    DOUBLE_00108d58),(double)FLOAT_00108e50,(double)FLOAT_00108e54);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000547a4:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _gleSetRasterPos @ 0x54834 (1524 bytes) */
void _gleSetRasterPos(int glContext,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float floatZero;
  int loopIndex;
  undefined4 *puVar1;
  bool bVar2;
  float fVar3;
  float glContextFloat2b4;
  float fVar4;
  float glContextFloat2b0;
  float fVar5;
  float glContextFloat2b8;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int glContextPtr4854;
  int iVar15;
  int *srcCursor;
  undefined4 uVar17;
  undefined4 glContextWord4864;
  int iVar18;
  int glContextWord48d0;
  int glContextWord4e1c;
  int iVar19;
  int remaining;
  double dVar21;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x2ef) = 0;
  iVar19 = glContextPtr4854 + -0x200;
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
    remaining = 8;
    iVar18 = iVar19;
    iVar15 = glContext;
    do {
      puVar1 = (undefined4 *)(iVar15 + 0x120);
      uVar17 = *(undefined4 *)(iVar15 + 0x124);
      uVar7 = *(undefined4 *)(iVar15 + 0x128);
      uVar8 = *(undefined4 *)(iVar15 + 300);
      iVar15 = iVar15 + 0x10;
      *(undefined4 *)(iVar18 + 0x80) = *puVar1;
      *(undefined4 *)(iVar18 + 0x84) = uVar17;
      *(undefined4 *)(iVar18 + 0x88) = uVar7;
      *(undefined4 *)(iVar18 + 0x8c) = uVar8;
      iVar18 = iVar18 + 0x10;
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined4 *)(glContextPtr4854 + -0x184) = *(undefined4 *)(glContext + 0x2ec);
    if (*(char *)(glContext + 0x53e4) != '\0') {
      *(float *)(glContextPtr4854 + -0x1e0) = (float)fparam_1;
      *(float *)(glContextPtr4854 + -0x1dc) = (float)fparam_2;
      *(float *)(glContextPtr4854 + -0x1d8) = (float)fparam_3;
      *(float *)(glContextPtr4854 + -0x1d4) = (float)fparam_4;
      (**(code **)(glContext + 0x53dc))(glContext,iVar19,1);
    }
    fVar3 = (fparam_4 * *(float *)(glContext + 0x1cf4) + (fparam_3 * *(float *)(glContext + 0x1ce4) + (fparam_1 * *(float *)(glContext + 0x1cc4) + (fparam_2 * *(float *)(glContext + 0x1cd4)))));
    fVar4 = (fparam_4 * *(float *)(glContext + 0x1cf0) + (fparam_3 * *(float *)(glContext + 0x1ce0) + (fparam_1 * *(float *)(glContext + 0x1cc0) + (fparam_2 * *(float *)(glContext + 0x1cd0)))));
    fVar5 = (fparam_4 * *(float *)(glContext + 0x1cf8) + (fparam_3 * *(float *)(glContext + 0x1ce8) + (fparam_1 * *(float *)(0x1cc8 + glContext) + (fparam_2 * *(float *)(glContext + 0x1cd8)))));
    fVar6 = (fparam_4 * *(float *)(glContext + 0x1cfc) + (fparam_3 * *(float *)(glContext + 0x1cec) + (fparam_1 * *(float *)(glContext + 0x1ccc) + (fparam_2 * *(float *)(glContext + 0x1cdc)))));
    fVar12 = fVar6 * *(float *)(glContext + 0x1cbc) +
             (fVar5 * *(float *)(glContext + 0x1cac) +
             (fVar4 * *(float *)(glContext + 0x1c8c) + fVar3 * *(float *)(glContext + 0x1c9c)));
    fVar11 = fVar6 * *(float *)(glContext + 0x1cb0) +
             (fVar5 * *(float *)(glContext + 0x1ca0) +
             (fVar4 * *(float *)(glContext + 0x1c80) + fVar3 * *(float *)(glContext + 0x1c90)));
    fVar10 = fVar6 * *(float *)(glContext + 0x1cb8) +
             (fVar5 * *(float *)(glContext + 0x1ca8) +
             (fVar4 * *(float *)(glContext + 0x1c88) + fVar3 * *(float *)(glContext + 0x1c98)));
    fVar9 = fVar6 * *(float *)(glContext + 0x1cb4) +
            (fVar5 * *(float *)(glContext + 0x1ca4) +
            (fVar4 * *(float *)(glContext + 0x1c84) + fVar3 * *(float *)(glContext + 0x1c94)));
    fVar13 = -fVar12;
    if (((*(char *)(glContext + 0x50b5) == '\0') &&
        ((((fVar11 < fVar13 || (fVar12 < fVar11)) || (fVar9 < fVar13)) || (fVar12 < fVar9)))) ||
       ((fVar10 < fVar13 || (fVar12 < fVar10)))) goto LAB_00054e14;
    if (*(char *)(glContext + 0x4e18) != '\0') {
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x4dfc)) {
        srcCursor = (int *)(glContext + 0x4e00);
        do {
          iVar15 = *srcCursor;
          srcCursor = srcCursor + 1;
          iVar15 = glContext + iVar15 * 0x10;
          if (fVar6 * *(float *)(iVar15 + 0x4198) +
              (fVar5 * *(float *)(iVar15 + 0x4194) +
              (fVar4 * *(float *)(iVar15 + 0x418c) + fVar3 * *(float *)(iVar15 + 0x4190))) <
              FLOAT_00108e50) goto LAB_00054e14;
          loopIndex = loopIndex + 1;
        } while (loopIndex < *(int *)(glContext + 0x4dfc));
      }
    }
    *(float *)(glContextPtr4854 + -0x1e0) = fVar4;
    floatZero = FLOAT_00108e50;
    *(float *)(glContextPtr4854 + -0x1dc) = fVar3;
    *(float *)(glContextPtr4854 + -0x1d8) = fVar5;
    *(float *)(glContextPtr4854 + -0x1d4) = fVar6;
    *(float *)(glContextPtr4854 + -0x1f0) = fVar11;
    *(float *)(glContextPtr4854 + -0x1ec) = fVar9;
    *(float *)(glContextPtr4854 + -0x1e8) = fVar10;
    *(float *)(glContextPtr4854 + -0x1e4) = fVar12;
    if (floatZero <= fVar12) {
      bVar2 = FLOAT_00108e80 <= fVar12;
    }
    else {
      bVar2 = fVar12 <= FLOAT_00108f3c;
    }
    if (bVar2) {
      fVar3 = FLOAT_00108e54 / fVar12;
    }
    else {
      fVar3 = FLOAT_00108f7c;
      if (FLOAT_00108e50 <= fVar12) {
        fVar3 = FLOAT_00108eb4;
      }
    }
    *(float *)(glContext + 0x2e0) =
         *(float *)(glContext + 0x4a2c) * fVar11 * fVar3 + *(float *)(glContext + 0x4a30);
    *(float *)(glContext + 0x2e4) =
         *(float *)(glContext + 0x4a34) * fVar9 * fVar3 + *(float *)(glContext + 19000);
    *(float *)(glContext + 0x2e8) =
         *(float *)(glContext + 0x4a3c) * fVar10 * fVar3 + *(float *)(glContext + 0x4a40);
    *(float *)(glContextPtr4854 + -500) = fVar3;
    if (*(int *)(glContext + 0x50ac) != 0 ||
        (*(uint *)(glContext + 0x50b0) & *(uint *)(glContext + 0x505c)) != 0) {
      _gleUpdateMatrixFunc(glContext);
    }
    if ((*(char *)(glContext + 0x30aa) != '\0') || (*(char *)(glContext + 0x53e6) != '\0')) {
      glContextFloat2b4 = *(float *)(glContext + 0x2b4);
      glContextFloat2b0 = *(float *)(glContext + 0x2b0);
      glContextFloat2b8 = *(float *)(glContext + 0x2b8);
      *(float *)(glContextPtr4854 + -0x1c0) =
           glContextFloat2b8 * *(float *)(glContext + 0x22e0) +
           (glContextFloat2b0 * *(float *)(glContext + 0x22c0) + glContextFloat2b4 * *(float *)(glContext + 0x22d0));
      *(float *)(glContextPtr4854 + -0x1bc) =
           glContextFloat2b8 * *(float *)(glContext + 0x22e4) +
           (glContextFloat2b0 * *(float *)(glContext + 0x22c4) + glContextFloat2b4 * *(float *)(glContext + 0x22d4));
      *(float *)(glContextPtr4854 + -0x1b8) =
           glContextFloat2b8 * *(float *)(glContext + 0x22e8) +
           (glContextFloat2b0 * *(float *)(glContext + 0x22c8) + glContextFloat2b4 * *(float *)(glContext + 0x22d8));
      if (*(char *)(glContext + 0x280d) != '\0') {
        (**(code **)PTR__gleVectorNormalize_00112064)(glContext,glContextPtr4854 + -0x1c0,glContextPtr4854 + -0x1c0);
      }
    }
    if (*(char *)(glContext + 0x53e5) != '\0') {
      (**(code **)(glContext + 0x53e0))(glContext,iVar19,1);
    }
    (**(code **)(glContext + 0x506c))(glContext,iVar19,1,0);
    if (*(short *)(glContext + 0x3166) == -0x7baf) {
      *(undefined4 *)(glContextPtr4854 + -0x1d8) = *(undefined4 *)(glContext + 0x2cc);
    }
    dVar21 = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)*(float *)(glContextPtr4854 + -0x1d8));
    *(float *)(glContextPtr4854 + -0x1b4) = (float)dVar21;
    if (*(char *)(glContext + 0x30aa) == '\0') {
      *(undefined8 *)(glContextPtr4854 + -0x1d0) = *(undefined8 *)(glContext + 0x2a0);
      *(undefined8 *)(glContextPtr4854 + -0x1c8) = *(undefined8 *)(glContext + 0x2a8);
      *(undefined8 *)(glContextPtr4854 + -0x1b0) = *(undefined8 *)(glContext + 0x2c0);
      *(undefined4 *)(glContextPtr4854 + -0x1a8) = *(undefined4 *)(glContext + 0x2c8);
    }
    else {
      *(undefined4 *)(glContextPtr4854 + -0x18c) = *(undefined4 *)(glContext + 0x4dd0);
      *(undefined4 *)(glContextPtr4854 + -0x188) = *(undefined4 *)(glContext + 0x4dd4);
      (**(code **)(glContext + 0x4de8))(glContext,iVar19,1);
    }
    glContextWord4e1c = *(int *)(glContext + 0x4e1c);
  }
  else {
    glContextWord48d0 = *(int *)(glContext + 0x48d0);
    *(int *)(glContext + 0x4858) = glContextPtr4854;
    glContextWord4864 = *(undefined4 *)(glContext + 0x4864);
    if (glContextWord48d0 != 0) {
      *(undefined4 *)(glContext + 0x48d0) = 0;
      _gleSelectVertexSubmitFunc(glContext);
    }
    (**(int ( **)(int,double,double,double,double))(glContext + 0x4888))(glContext, fparam_1, fparam_2, fparam_3, fparam_4);
    if (glContextWord48d0 != 0) {
      *(int *)(glContext + 0x48d0) = glContextWord48d0;
      _gleSelectVertexSubmitFunc(glContext);
    }
    *(int *)(glContext + 0x4864) = iVar19;
    _gleVPEmulate(glContext,1);
    *(undefined4 *)(glContext + 0x4864) = glContextWord4864;
    glContextWord4e1c = *(int *)(glContext + 0x4e1c);
    *(float *)(glContext + 0x2e0) =
         *(float *)(glContext + 0x4a2c) * *(float *)(glContextPtr4854 + -0x1f0) * *(float *)(glContextPtr4854 + -0x1e4) +
         *(float *)(glContext + 0x4a30);
    *(float *)(glContext + 0x2e4) =
         *(float *)(glContext + 0x4a34) * *(float *)(glContextPtr4854 + -0x1ec) * *(float *)(glContextPtr4854 + -0x1e4) +
         *(float *)(glContext + 19000);
    *(float *)(glContext + 0x2e8) =
         *(float *)(glContext + 0x4a3c) * *(float *)(glContextPtr4854 + -0x1e8) * *(float *)(glContextPtr4854 + -0x1e4) +
         *(float *)(glContext + 0x4a40);
  }
  if (glContextWord4e1c == 0x1c02) {
    _gleSelectHit(glContext,iVar19);
  }
  *(undefined1 *)(glContext + 0x2ef) = 1;
LAB_00054e14:
  return;
}

/* _glBitmap_Exec @ 0x54e2c (984 bytes) */
void _glBitmap_Exec(int glContext,int width,int height,undefined4 xorigShadowThenScratch,undefined4 param_5,int param_6,undefined4 ymoveShadow,int bitmap,double xorig,double yorig,float xmove,float ymove,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int glContextPtr4854;
  int *srcCursor;
  int imageEndOffset;
  int framebufferObject;
  int iVar7;
  uint dispatchFlags;
  uint changeWord3;
  float *a1;
  int iVar9;
  int matrixChangeBits;
  int pixelUnpackBuffer;
  int *changeWordCursor;
  double extraout_f1;
  double fparam_1_00;
  double extraout_f1_00;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  a1 = (float *)(glContextPtr4854 + -0x200);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < width) && (-1 < height)) {
      pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
      iVar7 = height;
      fparam_1_00 = xorig;
      fparam_2_00 = yorig;
      fparam_3_00 = xmove;
      fparam_4_00 = ymove;
      if (pixelUnpackBuffer != 0) {
        xorigShadowThenScratch = 0;
        param_5 = 0x1a00;
        param_6 = bitmap;
        imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,0,0x1a00,bitmap);
        if (*(int *)(pixelUnpackBuffer + 0x38) < imageEndOffset) goto LAB_00054ec8;
        fparam_1_00 = extraout_f1;
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          fparam_1_00 = (double)_gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        bitmap = bitmap + *(int *)(pixelUnpackBuffer + 0x30);
      }
      if (*(char *)(glContext + 0x2ef) == '\0') goto LAB_000551f0;
      if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
        if ((0 < width) && (0 < height)) {
          matrixChangeBits = *(int *)(glContext + 0x50ac);
          if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
            _gleUpdateMatrixFunc(glContext);
            fparam_1_00 = extraout_f1_00;
          }
          if (*(char *)(glContext + 0x4691) != '\0') {
            framebufferObject = *(int *)(glContext + 0x744c);
            changeWordCursor = (int *)(glContext + 0x310);
            rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
            if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
              ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,iVar7,xorigShadowThenScratch,param_5,param_6,matrixChangeBits,fparam_1_00,
                         fparam_2_00,fparam_3_00,fparam_4_00,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
              *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
            }
            if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0005501c:
              changeWord3 = *(uint *)(glContext + 0x31c);
            }
            else {
              loopIndex = 0;
              srcCursor = (int *)(glContext + 0x324);
              do {
                iVar9 = *srcCursor;
                srcCursor = srcCursor + 1;
                if (iVar9 != 0) {
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
                goto LAB_0005501c;
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
                   ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
                  if ((dispatchFlags & 4) == 0) {
                    dispatchFlags = dispatchFlags & 0xfffffffe;
                    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
                  }
                  _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
                  if (*(char *)(glContext + 0x759d) == '\0') {
                    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000551f0;
                    glErrorCode = 0x506;
                    goto LAB_00055118;
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
          *a1 = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                *(float *)(glContext + 0x4a48);
          *(float *)(glContextPtr4854 + -0x1fc) =
               *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) +
               *(float *)(glContext + 0x4a50);
          *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
          (**(code **)(glContext + 0x46ac))
                    (*(undefined4 *)(glContext + 0x4688),a1,width,height,param_5,param_6,bitmap,0,
                     xorig,yorig);
        }
      }
      else if (*(int *)(glContext + 0x4e1c) == 0x1c01) {
        *a1 = *(float *)(glContext + 0x2e0);
        *(undefined4 *)(glContextPtr4854 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
        *(undefined4 *)(glContextPtr4854 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
        _gleFeedbackBitmap(glContext,a1);
      }
      *(float *)(glContext + 0x2e0) = (*(float *)(glContext + 0x2e0) + xmove);
      *(float *)(glContext + 0x2e4) = (*(float *)(glContext + 0x2e4) + ymove);
      goto LAB_000551f0;
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000551f0;
    glErrorCode = 0x501;
  }
  else {
LAB_00054ec8:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000551f0;
    glErrorCode = 0x502;
  }
LAB_00055118:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_000551f0:
  return;
}

/* _glCopyPixels_Exec @ 0x55204 (976 bytes) */
void _glCopyPixels_Exec(int glContext,undefined4 x,undefined4 y,int width,int height,int type,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 uVar3;
  uint dispatchFlags;
  uint changeWord3;
  uint glContextWord4e1c;
  int iVar5;
  int glContextPtr4854;
  int *srcCursor;
  int framebufferObject;
  int iVar9;
  int matrixChangeBits;
  int iVar11;
  int *changeWordCursor;
  float *pfVar13;
  double extraout_f1;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  pfVar13 = (float *)(glContextPtr4854 + -0x200);
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000555bc;
  }
  if ((width < 0) || (height < 0)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_000555bc;
  }
  if (type - 0x1800U < 3) {
    if (*(char *)(glContext + 0x2ef) == '\0') {
      return;
    }
    glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
    if (glContextWord4e1c == 0x1c01) {
      *(undefined4 *)(glContextPtr4854 + -0x200) = *(undefined4 *)(glContext + 0x2e0);
      *(undefined4 *)(glContextPtr4854 + -0x1fc) = *(undefined4 *)(glContext + 0x2e4);
      *(undefined4 *)(glContextPtr4854 + -0x1f8) = *(undefined4 *)(glContext + 0x2e8);
      _gleFeedbackCopyPixels(glContext,pfVar13);
      return;
    }
    if (glContextWord4e1c < 0x1c02) {
      if (glContextWord4e1c == 0x1c00) {
        if (*(float *)(glContext + 0x31a8) == FLOAT_00108e50) {
          return;
        }
        if (*(float *)(glContext + 0x31ac) == FLOAT_00108e50) {
          return;
        }
        if (width == 0) {
          return;
        }
        if (height == 0) {
          return;
        }
        matrixChangeBits = *(int *)(glContext + 0x50ac);
        uVar3 = y;
        iVar11 = width;
        iVar5 = height;
        iVar9 = type;
        if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(glContext);
          fparam_1 = extraout_f1;
        }
        if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0005550c;
        framebufferObject = *(int *)(glContext + 0x744c);
        changeWordCursor = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,uVar3,iVar11,iVar5,iVar9,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3
                     ,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
        }
        if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000553e8:
          changeWord3 = *(uint *)(glContext + 0x31c);
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
          changeWord3 = *(uint *)(glContext + 0x31c);
          if ((changeWord3 & 0x15555) != 0) {
            if (*(char *)(glContext + 0x2e54) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
            }
            if (*(char *)(glContext + 0x3094) != '\0') {
              _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
            }
            goto LAB_000553e8;
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
                goto LAB_000555bc;
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
LAB_0005550c:
        *pfVar13 = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                   *(float *)(glContext + 0x4a48);
        *(float *)(glContextPtr4854 + -0x1fc) =
             *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) +
             *(float *)(glContext + 0x4a50);
        *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
                    
                    
        (**(code **)(glContext + 0x46a8))
                  (*(undefined4 *)(glContext + 0x4688),pfVar13,x,y,width,height,type
                  );
        return;
      }
    }
    else if (glContextWord4e1c == 0x1c02) {
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000555bc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

