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
int _gleLoadMatrixf(m, destination)
  undefined4 *m;
  undefined4 *destination;
{
  *destination = *m;
  destination[1] = m[1];
  destination[2] = m[2];
  destination[3] = m[3];
  destination[4] = m[4];
  destination[5] = m[5];
  destination[6] = m[6];
  destination[7] = m[7];
  destination[8] = m[8];
  destination[9] = m[9];
  destination[10] = m[10];
  destination[0xb] = m[0xb];
  destination[0xc] = m[0xc];
  destination[0xd] = m[0xd];
  destination[0xe] = m[0xe];
  destination[0xf] = m[0xf];
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
  undefined4 greenValue;
  undefined4 blueValue;
  undefined4 alphaValue;
  
  greenValue = v[1];
  blueValue = v[2];
  alphaValue = v[3];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2a4) = greenValue;
  *(undefined4 *)(glContext + 0x2a8) = blueValue;
  *(undefined4 *)(glContext + 0x2ac) = alphaValue;
  return;
}

/* _gleSetEnable_TEXTURE_3D @ 0x4f25c (80 bytes) */
void _gleSetEnable_TEXTURE_3D(glContext, unusedArg2, enable)
  int glContext;
  undefined4 unusedArg2;
  int enable;
{
  uint newFlags;
  int unitState;
  uint texUnit;
  uint oldFlags;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    unitState = texUnit * 0x7c + glContext;
    oldFlags = *(uint *)(unitState + 0x3534);
    newFlags = oldFlags & 0xfffffffd | enable << 1;
    if (oldFlags == newFlags) {
      return;
    }
    *(uint *)(unitState + 0x3534) = newFlags;
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
  byte dirtyBitIndex;
  uint changeWord3WithBit;
  uint expectedTarget;
  undefined4 glErrorCode;
  int dirtyWord348;
  int glContextWord5424;
  int targetSlot;
  int envParam;
  int envParams;
  int dirtyWord324;
  
  if (target == 0x8620) {
    targetSlot = 0;
    if (index < 0x100) {
      changeWord3WithBit = *(uint *)(glContext + 0x31c) | 0x800000;
LAB_0004f340:
      *(uint *)(glContext + 0x31c) = changeWord3WithBit;
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitIndex = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x158);
      }
      else {
        dirtyBitIndex = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x18c);
      }
      dirtyWord324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(dirtyWord324 + 0x324) = *(uint *)(dirtyWord324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex = *(byte *)(index + glContextWord5424 + 0x158);
      dirtyWord348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      *(uint *)(dirtyWord348 + 0x348) = *(uint *)(dirtyWord348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
      envParams = *(int *)(targetSlot * 8 + glContext + 0x4668);
      *(undefined4 *)(envParams + index * 0x10) = *params;
      envParam = envParams + index * 0x10;
      *(undefined4 *)(envParam + 4) = params[1];
      *(undefined4 *)(envParam + 8) = params[2];
      *(undefined4 *)(envParam + 0xc) = params[3];
      return;
    }
  }
  else {
    if (target < 0x8621) {
      expectedTarget = 0x8200;
    }
    else {
      expectedTarget = 0x8804;
    }
    if (target != expectedTarget) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_0004f338;
    }
    targetSlot = 1;
    if (index < 0x80) {
      changeWord3WithBit = *(uint *)(glContext + 0x31c) | 0x2000000;
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
void _glePPRelocateAttrib(oldAttribIndex, newAttribIndex, instructionList)
  uint oldAttribIndex;
  undefined4 newAttribIndex;
  int *instructionList;
{
  int instruction;
  uint instructionHeader;
  
  instruction = *instructionList;
  if (instruction != 0) {
    do {
      if ((((*(uint *)(instruction + 0xc) >> 0x1d != 0) &&
           ((*(uint *)(instruction + 0xc) >> 0x12 & 0xff) != 0x4a)) &&
          ((*(uint *)(instruction + 0x1c) & 0x3800000) == 0)) && (*(ushort *)(instruction + 0x22) == oldAttribIndex)) {
        *(undefined2 *)(instruction + 0x22) = (*(unsigned short *)((unsigned char *)&(newAttribIndex) + 2));
      }
      instructionHeader = *(uint *)(instruction + 0xc);
      if (((1 < instructionHeader >> 0x1d) && (3 < (instructionHeader >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(instruction + 0x24) & 0x3800000) == 0 && (*(ushort *)(instruction + 0x2a) == oldAttribIndex)))) {
        *(undefined2 *)(instruction + 0x2a) = (*(unsigned short *)((unsigned char *)&(newAttribIndex) + 2));
      }
      if (((2 < instructionHeader >> 0x1d) && ((*(uint *)(instruction + 0x2c) & 0x3800000) == 0)) &&
         (*(ushort *)(instruction + 0x32) == oldAttribIndex)) {
        *(undefined2 *)(instruction + 0x32) = (*(unsigned short *)((unsigned char *)&(newAttribIndex) + 2));
      }
      instruction = *(int *)(instruction + 8);
    } while (instruction != 0);
    return;
  }
  return;
}

/* _glePPRelocateLocal @ 0x4f4a8 (240 bytes) */
void _glePPRelocateLocal(oldLocalIndex, newLocalIndex, instructionList)
  uint oldLocalIndex;
  undefined4 newLocalIndex;
  int *instructionList;
{
  int instruction;
  uint instructionHeader;
  
  instruction = *instructionList;
  if (instruction != 0) {
    do {
      if ((((*(uint *)(instruction + 0xc) >> 0x12 & 0xff) < 0x4b) &&
          ((*(uint *)(instruction + 0x14) >> 0x11 & 7) == 1)) && (*(ushort *)(instruction + 0x1a) == oldLocalIndex)) {
        *(undefined2 *)(instruction + 0x1a) = (*(unsigned short *)((unsigned char *)&(newLocalIndex) + 2));
      }
      instructionHeader = *(uint *)(instruction + 0xc);
      if (((instructionHeader >> 0x1d != 0) && ((instructionHeader >> 0x12 & 0xff) != 0x4a)) &&
         (((*(uint *)(instruction + 0x1c) >> 0x17 & 7) == 1 && (*(ushort *)(instruction + 0x22) == oldLocalIndex)))) {
        *(undefined2 *)(instruction + 0x22) = (*(unsigned short *)((unsigned char *)&(newLocalIndex) + 2));
      }
      if (((1 < instructionHeader >> 0x1d) && (3 < (instructionHeader >> 0x12 & 0xff) - 0x41)) &&
         (((*(uint *)(instruction + 0x24) >> 0x17 & 7) == 1 && (*(ushort *)(instruction + 0x2a) == oldLocalIndex)))) {
        *(undefined2 *)(instruction + 0x2a) = (*(unsigned short *)((unsigned char *)&(newLocalIndex) + 2));
      }
      if (((2 < instructionHeader >> 0x1d) && ((*(uint *)(instruction + 0x2c) >> 0x17 & 7) == 1)) &&
         (*(ushort *)(instruction + 0x32) == oldLocalIndex)) {
        *(undefined2 *)(instruction + 0x32) = (*(unsigned short *)((unsigned char *)&(newLocalIndex) + 2));
      }
      instruction = *(int *)(instruction + 8);
    } while (instruction != 0);
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
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  int rendererRecordCursor;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    rendererRecordCursor = glContext + 0x10000;
    loopIndex = 0;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
        loopIndex = loopIndex + 1;
        rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
        rendererRecordCursor = rendererRecordCursor + 0x2e0;
        (**(code **)(*rendererCallbacks + 0x178))(*rendererHandlePtr);
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
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  int *srcCursor;
  int fenceObject;
  int dirtyWord;
  int framebufferObject;
  int incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterLookupHashObject;
  double forwardedFloatArg1;
  double f1AfterUpdateMatrixFunc;
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
  fenceObject = _gleLookupHashObject(glContext + 0x543c,fence);
  forwardedFloatArg1 = f1AfterLookupHashObject;
  if (fenceObject == 0) {
    fenceObject = ((int (*)())_gleCreateFenceObject)(fence);
    ((void (*)())_gleCreatePluginFence)(glContext,fenceObject + 0x10);
    incomingR5 = fenceObject;
    forwardedFloatArg1 = (double)_gleAddHashNameAndObject(glContext,glContext + 0x543c,fenceObject);
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterUpdateMatrixFunc;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0004fe34;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
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
      goto LAB_0004fd20;
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
             *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + fenceObject + 0x10));
  return;
}

/* _gleCreateFenceObject @ 0x4fe64 (112 bytes) */
int _gleCreateFenceObject(fence)
  undefined4 fence;
{
  undefined *freeFunc;
  undefined4 *cursor;
  undefined4 *allocatedBlock;
  int remaining;
  
  allocatedBlock = (undefined4 *)_malloc(0x30);
  freeFunc = PTR__gleFreeFenceObject_00110e1c;
  allocatedBlock[2] = 1;
  allocatedBlock[3] = freeFunc;
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
void _gleCreatePluginFence(glContext, fenceHandleCursor)
  int glContext;
  int fenceHandleCursor;
{
  int *rendererFuncTablePtr;
  undefined4 *rendererStatePtr;
  int rendererRecordCursor;
  int loopIndex;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererFuncTablePtr = (int *)(rendererRecordCursor + -0x777c);
      rendererStatePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererFuncTablePtr + 0x1b8))(*rendererStatePtr,fenceHandleCursor);
      fenceHandleCursor = fenceHandleCursor + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _glPointSize_Exec @ 0x4ff44 (216 bytes) */
void _glPointSize_Exec(int glContext,float size)
{
  byte dirtyBitIndex;
  undefined4 glErrorCode;
  int dirtyWord324;
  int dirtyWord348;
  int glContextPtr5424;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (!(size <= (double)FLOAT_00108e50)) {
      *(float *)(glContext + 0x341c) = (float)size;
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x325);
      }
      else {
        dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x359);
      }
      dirtyWord324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextPtr5424 = *(int *)(glContext + 0x5424);
      *(uint *)(dirtyWord324 + 0x324) = *(uint *)(dirtyWord324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x325);
      dirtyWord348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      *(uint *)(dirtyWord348 + 0x348) = *(uint *)(dirtyWord348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
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
  byte dirtyBitNumber;
  uint dirtyWordValue;
  undefined4 glErrorCode;
  int programObjectThenLocalParams;
  int glContextWord5424;
  int programKindThenDirtyWordBase348ThenParamRecord;
  int programSlotBase;
  int dirtyWordBase324;
  
  if (target == 0x8620) {
    programKindThenDirtyWordBase348ThenParamRecord = 0;
    if (index < 0x100) {
      dirtyWordValue = *(uint *)(glContext + 0x31c) | 0x400000;
LAB_000500b0:
      *(uint *)(glContext + 0x31c) = dirtyWordValue;
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitNumber = *(byte *)(index + *(int *)(glContext + 0x5420) + 0x58);
      }
      else {
        dirtyBitNumber = *(byte *)(index + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x8c);
      }
      dirtyWordBase324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      programSlotBase = programKindThenDirtyWordBase348ThenParamRecord * 4 + glContext;
      *(uint *)(dirtyWordBase324 + 0x324) = *(uint *)(dirtyWordBase324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
      dirtyBitNumber = *(byte *)(index + glContextWord5424 + 0x58);
      programObjectThenLocalParams = *(int *)(programSlotBase + 0x5420);
      programKindThenDirtyWordBase348ThenParamRecord = (dirtyBitNumber >> 3 & 0x1c) + glContext;
      *(uint *)(programKindThenDirtyWordBase348ThenParamRecord + 0x348) = *(uint *)(programKindThenDirtyWordBase348ThenParamRecord + 0x348) | 1 << (dirtyBitNumber & 0x1f);
      programObjectThenLocalParams = *(int *)(programObjectThenLocalParams + 0x4e0);
      programKindThenDirtyWordBase348ThenParamRecord = programObjectThenLocalParams + index * 0x10;
      *(float *)(programObjectThenLocalParams + index * 0x10) = (float)x;
      *(float *)(programKindThenDirtyWordBase348ThenParamRecord + 0xc) = (float)w;
      *(float *)(programKindThenDirtyWordBase348ThenParamRecord + 4) = (float)y;
      *(float *)(programKindThenDirtyWordBase348ThenParamRecord + 8) = (float)z;
      _gleModifyPluginPipelineProgram(glContext,*(int *)(programSlotBase + 0x5420) + 0x10,2);
      return;
    }
  }
  else {
    if (target < 0x8621) {
      dirtyWordValue = 0x8200;
    }
    else {
      dirtyWordValue = 0x8804;
    }
    if (target != dirtyWordValue) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_000500a8;
    }
    programKindThenDirtyWordBase348ThenParamRecord = 1;
    if (index < 0x80) {
      dirtyWordValue = *(uint *)(glContext + 0x31c) | 0x1000000;
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
  float priority;
  int sharedStateThenTextureObject;
  int textureName;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (n == 0) {
        return;
      }
      sharedStateThenTextureObject = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedStateThenTextureObject + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedStateThenTextureObject + 0x8028);
        sharedStateThenTextureObject = *(int *)(glContext + 0x5148);
      }
      floatOne = FLOAT_00108e54;
      floatZero = FLOAT_00108e50;
      loopIndex = 0;
      if (0 < n) {
        do {
          textureName = *(int *)(loopIndex * 4 + textures);
          if (textureName != 0) {
            sharedStateThenTextureObject = _gleLookupHashObject(sharedStateThenTextureObject + 0x2008,textureName);
            if (sharedStateThenTextureObject != 0) {
              priority = *(float *)(loopIndex * 4 + priorities);
              if (priority < floatZero) {
                priority = 0.0;
              }
              else if (floatOne < priority) {
                priority = 1.0;
              }
              *(float *)(sharedStateThenTextureObject + 0x38) = priority;
            }
            sharedStateThenTextureObject = *(int *)(glContext + 0x5148);
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < n);
      }
      if (*(char *)(sharedStateThenTextureObject + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(sharedStateThenTextureObject + 0x8028);
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
void _gleCopyPixelMapi(srcValues, mapStorageSlot, entryCount, capacitySlot)
  int *srcValues;
  undefined4 *mapStorageSlot;
  int entryCount;
  int *capacitySlot;
{
  undefined *mapStorage;
  int loopIndex;
  
  mapStorage = (undefined *)*mapStorageSlot;
  if ((entryCount == 1) && (*srcValues == 0)) {
    if (mapStorage == PTR__gle_default_pix_map_i_00112044) {
      return;
    }
    _free(mapStorage);
LAB_0005041c:
    *mapStorageSlot = PTR__gle_default_pix_map_i_00112044;
    *capacitySlot = 1;
  }
  else {
    if ((entryCount != *capacitySlot) || (mapStorage == PTR__gle_default_pix_map_i_00112044)) {
      if (mapStorage == PTR__gle_default_pix_map_i_00112044) {
        mapStorage = (undefined *)0x0;
      }
      mapStorage = (undefined *)_realloc(mapStorage,entryCount << 2);
      if (mapStorage == (undefined *)0x0) goto LAB_0005041c;
      *mapStorageSlot = mapStorage;
      *capacitySlot = entryCount;
    }
    loopIndex = 0;
    if (0 < entryCount) {
      do {
        *(int *)(mapStorage + loopIndex * 4) = srcValues[loopIndex];
        entryCount = entryCount + -1;
        loopIndex = loopIndex + 1;
      } while (entryCount != 0);
    }
  }
  return;
}

/* _gleCopyPixelMapf @ 0x50440 (240 bytes) */
int _gleCopyPixelMapf(srcMap, dstMapPtr, mapEntryCountThenRemaining, dstMapSizePtr)
  float *srcMap;
  undefined4 *dstMapPtr;
  int mapEntryCountThenRemaining;
  int *dstMapSizePtr;
{
  int loopIndex;
  undefined *dstMap;
  
  dstMap = (undefined *)*dstMapPtr;
  if ((mapEntryCountThenRemaining == 1) && (*srcMap == FLOAT_00108e50)) {
    if (dstMap == PTR__gle_default_pix_map_f_00112040) {
      return;
    }
    _free(dstMap);
LAB_0005050c:
    *dstMapPtr = PTR__gle_default_pix_map_f_00112040;
    *dstMapSizePtr = 1;
  }
  else {
    if ((mapEntryCountThenRemaining != *dstMapSizePtr) || (dstMap == PTR__gle_default_pix_map_f_00112040)) {
      if (dstMap == PTR__gle_default_pix_map_f_00112040) {
        dstMap = (undefined *)0x0;
      }
      dstMap = (undefined *)_realloc(dstMap,mapEntryCountThenRemaining << 2);
      if (dstMap == (undefined *)0x0) goto LAB_0005050c;
      *dstMapPtr = dstMap;
      *dstMapSizePtr = mapEntryCountThenRemaining;
    }
    loopIndex = 0;
    if (0 < mapEntryCountThenRemaining) {
      do {
        *(float *)(dstMap + loopIndex * 4) = srcMap[loopIndex];
        mapEntryCountThenRemaining = mapEntryCountThenRemaining + -1;
        loopIndex = loopIndex + 1;
      } while (mapEntryCountThenRemaining != 0);
    }
  }
  return;
}

/* _gleFreeFenceObject @ 0x50530 (52 bytes) */
void _gleFreeFenceObject(glContext, fenceObject)
  undefined4 glContext;
  int fenceObject;
{
  ((void (*)())_gleDestroyPluginFence)(glContext,fenceObject + 0x10);
  _free(fenceObject);
  return;
}

/* _gleDestroyPluginFence @ 0x50564 (120 bytes) */
void _gleDestroyPluginFence(glContext, fenceHandles)
  int glContext;
  int fenceHandles;
{
  int *rendererFuncTablePtr;
  undefined4 *rendererStatePtr;
  int handleOffset;
  int rendererRecordCursor;
  int loopIndex;
  
  rendererRecordCursor = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererFuncTablePtr = (int *)(rendererRecordCursor + -0x777c);
      handleOffset = loopIndex * 4;
      rendererStatePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
      rendererRecordCursor = rendererRecordCursor + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*rendererFuncTablePtr + 0x1bc))(*rendererStatePtr,*(undefined4 *)(handleOffset + fenceHandles));
      *(undefined4 *)(handleOffset + fenceHandles) = 0;
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
  undefined *setClipInterpFunc;
  undefined4 glErrorCode;
  uint glContextWord4e1c;
  int renderModeResult;
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
  
  renderModeResult = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode - 0x1c00 < 3) {
      glContextWord4e1c = *(uint *)(glContext + 0x4e1c);
      if (glContextWord4e1c == 0x1c01) {
        renderModeResult = -1;
        if (*(char *)(glContext + 0x4fdc) == '\0') {
          renderModeResult = *(int *)(glContext + 0x4fd0) - *(int *)(glContext + 0x4fcc) >> 2;
        }
      }
      else if (((0x1c01 < glContextWord4e1c) && (glContextWord4e1c == 0x1c02)) &&
              (renderModeResult = -1, *(char *)(glContext + 0x4fc9) == '\0')) {
        renderModeResult = *(int *)(glContext + 0x4fc4);
      }
      if (mode == 0x1c01) {
        if (*(int *)(glContext + 0x4fd4) == 0) {
LAB_000507ac:
          if (*(int *)(glContext + 0x7574) == 0) {
            *(undefined4 *)(glContext + 0x7574) = 0x502;
            return renderModeResult;
          }
          return renderModeResult;
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
      setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
      *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
      *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
      _gleSelectVertexSubmitFunc(glContext);
      _gleSelectVertexAddMaterialFunc(glContext);
      _gleUpdatePrimitiveData(glContext);
      ((void (*)())_gleUpdateViewScissorData)(glContext,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      ((void (*)())_gleUpdateDepthRangeData)(glContext,fparam_1_00,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffffb8,
                 incomingStack_ffffffc0,incomingStack_ffffffc8,incomingStack_ffffffd0,incomingStack_ffffffd8);
      _gleUpdateTextureTransform(glContext);
      _gleUpdatePolyMode(glContext);
      return renderModeResult;
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
void _gleFeedbackToken(int glContext,float tokenValue)
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
  *glContextPtr4fd0 = (float)tokenValue;
  *(float **)(glContext + 0x4fd0) = glContextPtr4fd0 + 1;
  return;
}

/* _gleBeginQuadsSelectFeedback @ 0x508b0 (76 bytes) */
void _gleBeginQuadsSelectFeedback(glContext)
  int glContext;
{
  undefined *quadsFunc;
  
  *(undefined **)(glContext + 0x4a0c) = PTR__gleFlushAtomicFunc_00112224;
  quadsFunc = PTR__gleFeedbackQuadsFunc_00112278;
  if (*(int *)(glContext + 0x4e1c) == 0x1c02) {
    quadsFunc = PTR__gleSelectQuadsFunc_0011227c;
  }
  *(undefined **)(glContext + 0x4a08) = quadsFunc;
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
  ushort facePolygonMode;
  bool fixedFunctionPath;
  bool facingChanged;
  bool lightingActive;
  bool twoSidedLighting;
  uint *newPolygonList;
  undefined4 bufferEnd;
  uint clipFlagsThenResumeCursor;
  int cullResultThenBackFacing;
  code *lightingFunc;
  int previousBackFacingThenVertexArrayEnd;
  uint *spareList;
  uint *puVar14;
  uint vertexCountThenLastQuadStart;
  uint *polygonList;
  uint nextRunStart;
  uint runStart;
  uint vertexCursor;
  int iVar20;
  int remaining;
  double forwardedFloatArg1;
  double f1AfterCall;
  double f1AfterCall1;
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
  int backFacing;
  int clipCount [4];
  
  previousBackFacingThenVertexArrayEnd = -1;
  fixedFunctionPath = false;
  if ((*(char *)(glContext + 0x4664) != '\0') || (*(int *)(glContext + 0x5434) != 0)) {
    fixedFunctionPath = true;
  }
  fixedFunctionPath = !fixedFunctionPath;
  lightingActive = false;
  if ((fixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) {
    lightingActive = true;
  }
  twoSidedLighting = false;
  if (((fixedFunctionPath) && (*(char *)(glContext + 0x30aa) != '\0')) && (*(char *)(glContext + 0x30ac) != '\0')) {
    twoSidedLighting = true;
  }
  glContextByte4fe0 = *(char *)(glContext + 0x4fe0);
  vertexCursor = *(uint *)(glContext + 0x4854);
  if (((int)*(short *)(glContext + 0x487c) != 0) &&
     (vertexCountThenLastQuadStart = (*(int *)(glContext + 0x4858) - vertexCursor) / (uint)(int)*(short *)(glContext + 0x487c),
     3 < (int)vertexCountThenLastQuadStart)) {
    if (fixedFunctionPath) {
      clipFlagsThenResumeCursor = (**(code **)(glContext + 0x5060))(glContext,vertexCursor,vertexCountThenLastQuadStart);
    }
    else {
      clipFlagsThenResumeCursor = _gleVPEmulate(glContext,vertexCountThenLastQuadStart);
    }
    if ((clipFlagsThenResumeCursor & 0xff00) == 0) {
      if (fixedFunctionPath) {
        if (*(char *)(glContext + 0x53e4) != '\0') {
          (**(code **)(glContext + 0x53dc))(glContext,vertexCursor,vertexCountThenLastQuadStart);
        }
        if (*(char *)(glContext + 0x50b4) != '\0') {
          (**(code **)(glContext + 0x5064))(glContext,vertexCursor,vertexCountThenLastQuadStart);
        }
        if ((lightingActive) || (*(char *)(glContext + 0x53e6) != '\0')) {
          (**(code **)(glContext + 0x5068))(glContext,vertexCursor,vertexCountThenLastQuadStart);
        }
        if (*(char *)(glContext + 0x53e5) != '\0') {
          (**(code **)(glContext + 0x53e0))(glContext,vertexCursor,vertexCountThenLastQuadStart);
        }
      }
      else {
        vertexCursor = *(uint *)(glContext + 0x4864);
      }
      if (((clipFlagsThenResumeCursor & 0xff) == 0) && (*(char *)(glContext + 0x4e18) == '\0')) {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x506c))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
        if (glContextByte4fe0 == '\0') {
          if (lightingActive) {
            (**(code **)(glContext + 0x4de8))(glContext,vertexCursor,vertexCountThenLastQuadStart);
          }
          _gleFeedbackQuads(glContext,vertexCursor,vertexCountThenLastQuadStart,*(ushort *)(glContext + 0x34d0) - 0x1b00);
        }
        else {
          vertexCountThenLastQuadStart = (vertexCursor + vertexCountThenLastQuadStart * 0x100) - 0x400;
          do {
            facingChanged = false;
            loopIndex = 0;
            clipFlagsThenResumeCursor = vertexCursor;
            runStart = vertexCursor;
            if (vertexCursor <= vertexCountThenLastQuadStart) {
              do {
                cullResultThenBackFacing = ((undefined4 (*)())_gleCullQuad)(glContext,vertexCursor,vertexCursor + 0x100,vertexCursor + 0x200,vertexCursor + 0x300,
                                      &backFacing,forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
                forwardedFloatArg1 = forwardedFloatArg1;
                if (cullResultThenBackFacing == 0) {
                  if (previousBackFacingThenVertexArrayEnd != backFacing) {
                    facingChanged = true;
                  }
                  if ((facingChanged) && (clipFlagsThenResumeCursor = vertexCursor, 0 < loopIndex)) break;
                  loopIndex = loopIndex + 4;
                  previousBackFacingThenVertexArrayEnd = backFacing;
                  nextRunStart = runStart;
                }
                else {
                  nextRunStart = vertexCursor + 0x400;
                  clipFlagsThenResumeCursor = nextRunStart;
                  if (0 < loopIndex) break;
                }
                vertexCursor = vertexCursor + 0x400;
                clipFlagsThenResumeCursor = vertexCursor;
                runStart = nextRunStart;
              } while (vertexCursor <= vertexCountThenLastQuadStart);
              if (3 < loopIndex) {
                if (twoSidedLighting) {
                  lightingFunc = *(code **)(previousBackFacingThenVertexArrayEnd * 4 + glContext + 0x4de8);
LAB_00050bc0:
                  (*lightingFunc)(glContext,runStart,loopIndex);
                }
                else if (lightingActive) {
                  lightingFunc = *(code **)(glContext + 0x4de8);
                  goto LAB_00050bc0;
                }
                if ((!fixedFunctionPath) && (lightingActive)) {
                  _gleVPFlipColors(glContext,runStart,loopIndex,previousBackFacingThenVertexArrayEnd);
                }
                if (previousBackFacingThenVertexArrayEnd == 0) {
                  facePolygonMode = *(ushort *)(glContext + 0x34d0);
                }
                else {
                  facePolygonMode = *(ushort *)(glContext + 0x34d2);
                }
                forwardedFloatArg1 = (double)_gleFeedbackQuads(glContext,runStart,loopIndex,facePolygonMode - 0x1b00);
              }
            }
            vertexCursor = clipFlagsThenResumeCursor;
          } while (clipFlagsThenResumeCursor <= vertexCountThenLastQuadStart);
        }
      }
      else {
        forwardedFloatArg1 = (double)(**(double ( **)(int,int,int,int))(glContext + 0x5074))(glContext, vertexCursor, vertexCountThenLastQuadStart, 0);
        previousBackFacingThenVertexArrayEnd = vertexCursor + vertexCountThenLastQuadStart * 0x100;
        polygonList = *(uint **)(glContext + 0x4870);
        spareList = *(uint **)(glContext + 0x4874);
        for (; vertexCursor <= previousBackFacingThenVertexArrayEnd - 0x400U; vertexCursor = vertexCursor + 0x400) {
          polygonList[1] = vertexCursor + 0x100;
          polygonList[2] = vertexCursor + 0x200;
          polygonList[3] = vertexCursor + 0x300;
          *polygonList = vertexCursor;
          if (fixedFunctionPath) {
            bufferEnd = *(undefined4 *)(glContext + 0x485c);
          }
          else {
            bufferEnd = *(undefined4 *)(glContext + 0x4854);
          }
          *(undefined4 *)(glContext + 0x4858) = bufferEnd;
          puVar14 = spareList;
          iVar20 = 4;
          newPolygonList = polygonList;
          if ((*(char *)(glContext + 0x4e18) == '\0') ||
             (forwardedFloatArg1 = (double)((double (*)())_gleClipPolyPlane)(glContext,polygonList,4,spareList,clipCount,forwardedFloatArg1,incomingFpr2,
                                                 incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                                 incomingStack_ffffff78,incomingStack_ffffff80),
             puVar14 = polygonList, iVar20 = clipCount[0], newPolygonList = spareList, clipCount[0] != 0)) {
            polygonList = newPolygonList;
            spareList = puVar14;
            if ((clipFlagsThenResumeCursor & 0xff) != 0) {
              forwardedFloatArg1 = (double)((double (*)())_gleClipPoly)(glContext,polygonList,iVar20,clipFlagsThenResumeCursor & 0xff,puVar14,clipCount,1);
              if (clipCount[0] == 0) goto LAB_00050ddc;
              if (0 < clipCount[0]) {
                spareList = polygonList;
                iVar20 = clipCount[0];
                polygonList = puVar14;
              }
            }
            if ((glContextByte4fe0 == '\0') ||
               (cullResultThenBackFacing = _gleCullPolygonPtrStack(glContext,polygonList,iVar20,&backFacing),
               forwardedFloatArg1 = f1AfterCall1, cullResultThenBackFacing == 0)) {
              cullResultThenBackFacing = backFacing;
              if (twoSidedLighting) {
                lightingFunc = *(code **)(backFacing * 4 + glContext + 0x4df0);
LAB_00050d70:
                (*lightingFunc)(glContext,polygonList,iVar20);
              }
              else if (lightingActive) {
                lightingFunc = *(code **)(glContext + 0x4df0);
                goto LAB_00050d70;
              }
              if (((!fixedFunctionPath) && (lightingActive)) && (cursor = polygonList, remaining = iVar20, 0 < iVar20)) {
                do {
                  _gleVPFlipColors(glContext,*cursor,1,cullResultThenBackFacing);
                  remaining = remaining + -1;
                  cursor = cursor + 1;
                } while (remaining != 0);
              }
              if (cullResultThenBackFacing == 0) {
                facePolygonMode = *(ushort *)(glContext + 0x34d0);
              }
              else {
                facePolygonMode = *(ushort *)(glContext + 0x34d2);
              }
              forwardedFloatArg1 = (double)((double (*)())_gleFeedbackPolygonPtr)(glContext,polygonList,iVar20,facePolygonMode - 0x1b00);
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
void _gleSetProjectionFuncAll(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  code *projectionFunc;
  
  projectionFunc = (code *)(*_gleBuildProjectionTransformFunc)(glContext,0,forwardedArg3);
  *(code **)(glContext + 0x5060) = projectionFunc;
  (*projectionFunc)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _gleBuildProjectionTransformFuncAV @ 0x50e6c (1208 bytes) */
int _gleBuildProjectionTransformFuncAV(glContext, optionBits)
  int glContext;
  uint optionBits;
{
  uint maskedMatrixIdentifier;
  uint matrixIdentifierThenClass;
  int cacheElem;
  int emittedWordCount;
  int chunkWordCountThenCodeCursor;
  int chunkWordCount;
  int chunkWordCountThenCodeCursor2;
  int chunkWordCount2;
  undefined *pushInstructionsFunc;
  undefined *codeChunk;
  int chunkWordCountThenCodeCursor3;
  int chunkWordCount3;
  undefined4 branchInstruction;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *cacheListHead;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  
  piVar14 = (int *)PTR__gleTransformProjectionBlend_00110a10;
  if (*(char *)(glContext + 0x4661) == '\0') {
    matrixIdentifierThenClass = (**(code **)PTR__gleGenerateMatrixIdentifier_00112060)(glContext,glContext + 0x27c0);
    *(uint *)(glContext + 0x5084) = matrixIdentifierThenClass;
    if (((optionBits & 1) != 0) && ((matrixIdentifierThenClass & 0x3030303) == 0x3030302)) {
      optionBits = optionBits | 4;
    }
    if ((matrixIdentifierThenClass != 0xbfeffbfe) &&
       (maskedMatrixIdentifier = matrixIdentifierThenClass & 0x3fcff3fc, matrixIdentifierThenClass = 0x3fcff3fc, maskedMatrixIdentifier != 0x3fcff3fc)) {
      matrixIdentifierThenClass = 0;
    }
    if (*(undefined **)(glContext + 0x5080) == ((unsigned char *)0x00001101)) {
      optionBits = optionBits | 8;
    }
    cacheListHead = *(int **)(glContext + 0x5088);
    piVar14 = cacheListHead;
    do {
      if (matrixIdentifierThenClass == piVar14[2] && optionBits == piVar14[3]) {
        if (piVar14 != cacheListHead) {
          _gleMoveFuncCacheElem(cacheListHead,piVar14);
          *(int **)(glContext + 0x5088) = piVar14;
        }
        return piVar14 + 8;
      }
      piVar14 = (int *)*piVar14;
    } while (piVar14 != cacheListHead);
    cacheElem = _gleCreateFuncCacheElem(piVar14,0xb8);
    piVar14 = (int *)PTR__gleRTCNoop_00112058;
    if (cacheElem != 0) {
      *(uint *)(cacheElem + 8) = matrixIdentifierThenClass;
      *(uint *)(cacheElem + 0xc) = optionBits;
      if (*(short *)(glContext + 0x508e) == *(short *)(glContext + 0x508c)) {
        _gleDeleteFuncCacheElem(*(undefined4 *)(cacheElem + 4));
      }
      else {
        *(short *)(glContext + 0x508e) = *(short *)(glContext + 0x508e) + 1;
      }
      chunkWordCountThenCodeCursor = _gleRTCAddAChunk_c5ddc(&_glePrologAVRTC_10f938,cacheElem + 0x20);
      chunkWordCountThenCodeCursor = cacheElem + 0x20 + chunkWordCountThenCodeCursor * 4;
      if (matrixIdentifierThenClass != 0xbfeffbfe) {
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(&_gleLoadMatrixPtrRTC_10f758,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
        if ((optionBits & 2) == 0) {
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
      if (matrixIdentifierThenClass == 0) {
        if ((optionBits & 1) == 0) {
          if ((optionBits & 2) == 0) {
            codeChunk = &_gleFullMatrixMultRTC_10fa18;
          }
          else {
            codeChunk = &_gleFullMatrixMultZ0RTC_10fa64;
          }
        }
        else if ((optionBits & 2) == 0) {
          codeChunk = &_gleFullMatrixMultW1RTC_10faa0;
        }
        else {
          codeChunk = &_gleFullMatrixMultZ0W1RTC_10fadc;
        }
      }
      else if (matrixIdentifierThenClass == 0x3fcff3fc) {
        chunkWordCount2 = _gleRTCAddAChunk_c5ddc(&_gleDiagMatrixSetupRTC_10fb08,chunkWordCountThenCodeCursor);
        chunkWordCountThenCodeCursor = chunkWordCountThenCodeCursor + chunkWordCount2 * 4;
        codeChunk = &_gleDiagMatrixMultRTC_10fb20;
      }
      else {
        codeChunk = &_gleIdentityMatrixMultRTC_10fb34;
      }
      chunkWordCountThenCodeCursor2 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor + chunkWordCountThenCodeCursor2 * 4;
      if ((optionBits & 8) == 0) {
        if ((optionBits & 4) == 0) {
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
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar10,chunkWordCountThenCodeCursor - (int)puVar10 >> 2);
        *puVar10 = branchInstruction;
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar12,chunkWordCountThenCodeCursor - (int)puVar12 >> 2);
        *puVar12 = branchInstruction;
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar15,chunkWordCountThenCodeCursor - (int)puVar15 >> 2);
        *puVar15 = branchInstruction;
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar16,chunkWordCountThenCodeCursor2 - (int)puVar16 >> 2);
        *puVar16 = branchInstruction;
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar9,chunkWordCountThenCodeCursor2 - (int)puVar9 >> 2);
        *puVar9 = branchInstruction;
        branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar11,chunkWordCountThenCodeCursor2 - (int)puVar11 >> 2);
        *puVar11 = branchInstruction;
      }
      else {
        if ((optionBits & 4) == 0) {
          codeChunk = &_gleNoClipCodeAVRTC;
        }
        else {
          codeChunk = &_gleNoClipCodeW1AVRTC;
        }
        chunkWordCount3 = _gleRTCAddAChunk_c5ddc(codeChunk,chunkWordCountThenCodeCursor2);
        chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount3 * 4;
      }
      puVar16 = (undefined4 *)(chunkWordCountThenCodeCursor2 + -4);
      branchInstruction = _gleRTCBuildABranch_c5dd0(*puVar16,chunkWordCountThenCodeCursor - (int)puVar16 >> 2);
      *puVar16 = branchInstruction;
      chunkWordCount = _gleRTCAddAChunk_c5ddc(&_gleCombineClipSumsAVRTC,chunkWordCountThenCodeCursor2);
      chunkWordCountThenCodeCursor2 = chunkWordCountThenCodeCursor2 + chunkWordCount * 4;
      chunkWordCount = _gleRTCAddAChunk_c5ddc(&_gleEpilogAVRTC_10f9c4,chunkWordCountThenCodeCursor2);
      puVar16 = (undefined4 *)(chunkWordCountThenCodeCursor2 + chunkWordCount * 4);
      *puVar16 = 0x4e800020;
      emittedWordCount = (int)puVar16 + (-0x1c - cacheElem) >> 2;
      if (0xb8 < emittedWordCount) {
                    
        _exit(1);
      }
      cacheElem = _gleShrinkFuncCacheElem(cacheElem,emittedWordCount);
      pushInstructionsFunc = PTR__glePushInstructions_00112054;
      *(int *)(glContext + 0x5088) = cacheElem;
      (**(code **)pushInstructionsFunc)(emittedWordCount,(int *)(cacheElem + 0x20));
      piVar14 = (int *)(cacheElem + 0x20);
    }
  }
  return piVar14;
}

/* _gleRTCAddAChunk_51324 @ 0x51324 (48 bytes) */
int _gleRTCAddAChunk_51324(sourceWords, destWords)
  int *sourceWords;
  int *destWords;
{
  int wordValue;
  int loopIndex;
  
  loopIndex = 0;
  wordValue = *sourceWords;
  while (wordValue != 0) {
    *destWords = wordValue;
    loopIndex = loopIndex + 1;
    sourceWords = sourceWords + 1;
    destWords = destWords + 1;
    wordValue = *sourceWords;
  }
  return loopIndex;
}

/* _gleRTCBuildABranch_51354 @ 0x51354 (12 bytes) */
int _gleRTCBuildABranch_51354(branchTemplate, branchDisplacementWords)
  uint branchTemplate;
  uint branchDisplacementWords;
{
  return (branchDisplacementWords & 0x3fff) << 2 | branchTemplate & 0xffff0003;
}

/* _gleTextureMatTrans_body @ 0x51364 (232 bytes) */
void _gleTextureMatTrans_body(int glContext,uint vertexCursor,int vertexBytes,int texUnit,double unusedFloatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12)
{
  float texMatrixElem0;
  float texMatrixElem14;
  float texMatrixElem1;
  float texMatrixElem3;
  float texMatrixElem4;
  float texMatrixElem5;
  float texMatrixElem7;
  float texMatrixElem8;
  float texMatrixElem9;
  float texMatrixElem11;
  float texMatrixElem12;
  float texMatrixElem13;
  float texMatrixElem15;
  float texMatrixElem2;
  float texMatrixElem6;
  float texMatrixElem10;
  float texCoordS;
  float texCoordT;
  float texCoordR;
  float texCoordQ;
  int texMatrixBase;
  int texCoordRecord;
  uint remaining;
  
  texMatrixBase = glContext + texUnit * 0x40;
  texMatrixElem0 = *(float *)(texMatrixBase + 0x1fc0);
  texMatrixElem14 = *(float *)(texMatrixBase + 0x1ff8);
  texMatrixElem1 = *(float *)(texMatrixBase + 0x1fc4);
  texMatrixElem3 = *(float *)(0x1fcc + texMatrixBase);
  texMatrixElem4 = *(float *)(texMatrixBase + 0x1fd0);
  texMatrixElem5 = *(float *)(texMatrixBase + 0x1fd4);
  texMatrixElem7 = *(float *)(texMatrixBase + 0x1fdc);
  texMatrixElem8 = *(float *)(texMatrixBase + 0x1fe0);
  texMatrixElem9 = *(float *)(texMatrixBase + 0x1fe4);
  texMatrixElem11 = *(float *)(texMatrixBase + 0x1fec);
  texMatrixElem12 = *(float *)(texMatrixBase + 0x1ff0);
  texMatrixElem13 = *(float *)(texMatrixBase + 0x1ff4);
  texMatrixElem15 = *(float *)(texMatrixBase + 0x1ffc);
  texMatrixElem2 = *(float *)(texMatrixBase + 0x1fc8);
  texMatrixElem6 = *(float *)(texMatrixBase + 0x1fd8);
  texMatrixElem10 = *(float *)(texMatrixBase + 0x1fe8);
  if (vertexCursor < vertexCursor + vertexBytes) {
    remaining = ((vertexCursor + vertexBytes) - vertexCursor) + 0xff >> 8;
    do {
      texCoordRecord = vertexCursor + texUnit * 0x10;
      vertexCursor = vertexCursor + 0x100;
      texCoordS = *(float *)(texCoordRecord + 0x80);
      texCoordT = *(float *)(texCoordRecord + 0x84);
      texCoordR = *(float *)(texCoordRecord + 0x88);
      texCoordQ = *(float *)(texCoordRecord + 0x8c);
      *(float *)(texCoordRecord + 0x8c) =
           texCoordQ * texMatrixElem15 + (texCoordR * texMatrixElem11 + (texCoordS * texMatrixElem3 + texCoordT * texMatrixElem7));
      *(float *)(texCoordRecord + 0x80) = texCoordQ * texMatrixElem12 + (texCoordR * texMatrixElem8 + (texCoordS * texMatrixElem0 + texCoordT * texMatrixElem4))
      ;
      *(float *)(texCoordRecord + 0x84) = texCoordQ * texMatrixElem13 + (texCoordR * texMatrixElem9 + (texCoordS * texMatrixElem1 + texCoordT * texMatrixElem5))
      ;
      *(float *)(texCoordRecord + 0x88) =
           texCoordQ * texMatrixElem14 + (texCoordR * texMatrixElem10 + (texCoordS * texMatrixElem2 + texCoordT * texMatrixElem6));
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  return;
}

/* _gleClipPoly @ 0x5144c (432 bytes) */
double _gleClipPoly(glContext, vertexList, vertexCount, clipPlaneMask, outputList, outCount, computeClipCodes)
  int glContext;
  int *vertexList;
  int vertexCount;
  uint clipPlaneMask;
  int *outputList;
  int *outCount;
  int computeClipCodes;
{
  int iVar1;
  uint uVar2;
  uint newVertexClipCode;
  int loopIndex;
  int iVar5;
  int *piVar6;
  int *cursor;
  int *inputEnd;
  int *cursor2;
  int remaining;
  
  if (computeClipCodes == 0) {
LAB_000514ac:
    iVar1 = *(int *)(glContext + 0x4858);
    inputEnd = vertexList + vertexCount;
    iVar5 = 0;
    uVar2 = 1;
    piVar6 = outputList;
    do {
      cursor = piVar6;
      if ((clipPlaneMask & uVar2) != 0) {
        *inputEnd = *vertexList;
        for (cursor2 = vertexList; cursor2 < inputEnd; cursor2 = cursor2 + 1) {
          iVar5 = *cursor2;
          if ((uVar2 & *(byte *)(iVar5 + 0x7f)) == 0) {
            *cursor = iVar5;
            cursor = cursor + 1;
            if ((uVar2 & *(byte *)(cursor2[1] + 0x7f)) != 0) {
              newVertexClipCode = (**(code **)(glContext + 0x49cc))(glContext,cursor2[1],*cursor2,iVar1,uVar2);
              *(undefined1 *)(iVar1 + 0x7c) = 0;
              *cursor = iVar1;
              goto LAB_0005156c;
            }
          }
          else if ((uVar2 & *(byte *)(cursor2[1] + 0x7f)) == 0) {
            newVertexClipCode = (**(code **)(glContext + 0x49cc))(glContext,iVar5,cursor2[1],iVar1,uVar2);
            *cursor = iVar1;
LAB_0005156c:
            clipPlaneMask = (clipPlaneMask | newVertexClipCode) & 0xff;
            iVar1 = iVar1 + 0x100;
            cursor = cursor + 1;
          }
        }
        iVar5 = (int)cursor - (int)piVar6 >> 2;
        if (iVar5 < 3) goto LAB_000514a0;
        inputEnd = piVar6 + iVar5;
        cursor = vertexList;
        vertexList = piVar6;
      }
      uVar2 = (uVar2 & 0x7f) << 1;
      piVar6 = cursor;
    } while (uVar2 < 0x21);
    if ((vertexList != outputList) && (loopIndex = 0, remaining = iVar5, 0 < iVar5)) {
      do {
        outputList[loopIndex] = vertexList[loopIndex];
        remaining = remaining + -1;
        loopIndex = loopIndex + 1;
      } while (remaining != 0);
    }
    *outCount = iVar5;
    *(int *)(glContext + 0x4858) = iVar1;
  }
  else {
    uVar2 = ((int (*)())_glePolyClipCode)(glContext,vertexList,vertexCount);
    if ((uVar2 & 0xff) == 0) {
      iVar1 = -1;
    }
    else {
      clipPlaneMask = uVar2 & 0xff;
      if ((uVar2 & 0xff00) == 0) goto LAB_000514ac;
LAB_000514a0:
      iVar1 = 0;
    }
    *outCount = iVar1;
  }
  return;
}

/* _glePolyClipCode @ 0x515fc (76 bytes) */
int _glePolyClipCode(glContext, vertexList, vertexCount)
  undefined4 glContext;
  int *vertexList;
  int vertexCount;
{
  int vertex;
  uint clipCodeAnd;
  uint clipCodeOr;
  uint remaining;
  
  clipCodeOr = 0;
  clipCodeAnd = 0xff;
  if (vertexList < vertexList + vertexCount) {
    remaining = (uint)((int)(vertexList + vertexCount) + (3 - (int)vertexList)) >> 2;
    do {
      vertex = *vertexList;
      vertexList = vertexList + 1;
      clipCodeAnd = clipCodeAnd & *(byte *)(vertex + 0x7f);
      clipCodeOr = clipCodeOr | *(byte *)(vertex + 0x7f);
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  return clipCodeAnd << 8 | clipCodeOr;
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
  code *interpolateFunc;
  
  interpolateFunc = (code *)((int (*)())_gleBuildInterpolateFunc)(glContext,1,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,forwardedArg8);
  *(code **)(glContext + 0x49cc) = interpolateFunc;
  (*interpolateFunc)(glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5);
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
double _gleFeedbackPolygonPtr(glContext, vertexList, vertexCount, polygonModeIndex)
  undefined4 glContext;
  int *vertexList;
  uint vertexCount;
  uint polygonModeIndex;
{
  int *cursor;
  uint polygonModeBits;
  double uintToDoubleBias;
  undefined4 feedbackTokenEnum;
  int *vertexEnd;
  
  uintToDoubleBias = DOUBLE_00108d70;
  polygonModeBits = polygonModeIndex & 3;
  feedbackTokenEnum = 0x707;
  if (polygonModeBits != 1) {
    if (polygonModeBits == 0) {
      vertexEnd = vertexList + vertexCount;
      for (; vertexList < vertexEnd; vertexList = vertexList + 1) {
        if ((*(char *)(*vertexList + 0x7c) != '\0') && (*(char *)(*vertexList + 0x7d) == '\0')) {
          ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f28);
          ((double (*)())_gleFeedbackHitRecord)(glContext,*vertexList);
        }
      }
      return;
    }
    if (polygonModeBits == 2) {
      ((void (*)())_gleFeedbackToken)(glContext,(double)FLOAT_00108f30);
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,vertexCount ^ 0x80000000) -
                                               DOUBLE_00108d58));
      vertexEnd = vertexList + vertexCount;
      for (; vertexList < vertexEnd; vertexList = vertexList + 1) {
        ((double (*)())_gleFeedbackHitRecord)(glContext,*vertexList);
      }
      return;
    }
    if (polygonModeBits != 3) {
      return;
    }
    feedbackTokenEnum = 0x702;
  }
  for (cursor = vertexList; cursor < vertexList + (vertexCount - 1); cursor = cursor + 1) {
    if (*(char *)(*cursor + 0x7c) != '\0') {
      ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,feedbackTokenEnum) - uintToDoubleBias));
      ((double (*)())_gleFeedbackHitRecord)(glContext,*cursor);
      ((double (*)())_gleFeedbackHitRecord)(glContext,cursor[1]);
      feedbackTokenEnum = 0x702;
    }
  }
  if (*(char *)(*cursor + 0x7c) != '\0') {
    ((void (*)())_gleFeedbackToken)(glContext,(double)(float)((double)CONCAT44(0x43300000,feedbackTokenEnum) - DOUBLE_00108d70))
    ;
    ((double (*)())_gleFeedbackHitRecord)(glContext,*cursor);
    ((double (*)())_gleFeedbackHitRecord)(glContext,*vertexList);
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
  uint shiftedEnableBits;
  uint texEnableBits;
  uint loopIndex;
  
  texEnableBits = _gleTexEnableBits(glContext);
  loopIndex = 0;
  do {
    shiftedEnableBits = texEnableBits >> (loopIndex & 0x3f);
    if ((shiftedEnableBits & 1) == 0) {
      if (shiftedEnableBits == 0) {
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
int _gleLoadMatrixd(m, floatMatrix)
  double *m;
  float *floatMatrix;
{
  *floatMatrix = (float)*m;
  floatMatrix[1] = (float)m[1];
  floatMatrix[2] = (float)m[2];
  floatMatrix[3] = (float)m[3];
  floatMatrix[4] = (float)m[4];
  floatMatrix[5] = (float)m[5];
  floatMatrix[6] = (float)m[6];
  floatMatrix[7] = (float)m[7];
  floatMatrix[8] = (float)m[8];
  floatMatrix[9] = (float)m[9];
  floatMatrix[10] = (float)m[10];
  floatMatrix[0xb] = (float)m[0xb];
  floatMatrix[0xc] = (float)m[0xc];
  floatMatrix[0xd] = (float)m[0xd];
  floatMatrix[0xe] = (float)m[0xe];
  floatMatrix[0xf] = (float)m[0xf];
  return;
}

/* _glGetTexParameteriv_Exec @ 0x52368 (964 bytes) */
void _glGetTexParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  uint *params;
{
  float halfThenFloatValue;
  float floatToIntScale;
  undefined4 glErrorCode;
  uint paramValue;
  int textureObject;
  
  textureObject = _gleLookUpNonProxyTexture(glContext,target);
  floatToIntScale = FLOAT_00108e94;
  halfThenFloatValue = FLOAT_00108e90;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00052714;
  }
  if (textureObject == 0) goto LAB_00052704;
  if (pname == (undefined *)0x813c) {
    paramValue = (uint)*(short *)(textureObject + 0x60);
    goto LAB_00052644;
  }
  if ((undefined *)0x813c < pname) {
    if (pname == (undefined *)0x85b7) {
      paramValue = *(uint *)(textureObject + 0x70);
      goto LAB_00052644;
    }
    if (pname < (undefined *)0x85b8) {
      if (pname == (undefined *)0x84fe) {
        halfThenFloatValue = *(float *)(textureObject + 0x50);
        goto LAB_00052638;
      }
      if (pname < (undefined *)0x84ff) {
        if (pname == (undefined *)0x813d) {
          paramValue = (uint)*(short *)(textureObject + 0x62);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x8191) {
          paramValue = *(uint *)(textureObject + 0x6c) >> 0xf & 1;
          goto LAB_00052644;
        }
      }
      else {
        if (pname == (undefined *)0x8501) {
          halfThenFloatValue = *(float *)(textureObject + 0x5c);
          goto LAB_00052638;
        }
        if (pname == (undefined *)0x85b6) {
          paramValue = *(uint *)(textureObject + 0x6c) >> 7 & 1;
          goto LAB_00052644;
        }
      }
    }
    else {
      if (pname == (undefined *)0x884b) {
        paramValue = (uint)*(ushort *)(textureObject + 0x6c);
        goto LAB_00052644;
      }
      if (pname < (undefined *)0x884c) {
        if (pname == (undefined *)0x85bc) {
          paramValue = (uint)*(ushort *)(textureObject + 0x3e);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x871a) {
          *params = (int)*(float *)(textureObject + 0x40);
          params[1] = (int)*(float *)(textureObject + 0x44);
          params[2] = (int)*(float *)(textureObject + 0x48);
          halfThenFloatValue = *(float *)(textureObject + 0x4c);
          goto LAB_000526f0;
        }
      }
      else {
        if (pname == (undefined *)0x884d) {
          paramValue = (uint)*(ushort *)(textureObject + 100);
          goto LAB_00052644;
        }
        if (pname < (undefined *)0x884d) {
          paramValue = (uint)*(ushort *)(textureObject + 0x66);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x8a7f) {
          paramValue = *(uint *)(textureObject + 0x6c) >> 6 & 1;
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
    halfThenFloatValue = *(float *)(textureObject + 0x28);
  }
  else {
    if (pname < (undefined *)0x8067) {
      if (pname == (undefined *)0x2801) {
        paramValue = (uint)*(ushort *)(textureObject + 0x3a);
        goto LAB_00052644;
      }
      if (pname < (undefined *)0x2802) {
        if (pname == ((unsigned char *)0x00001004)) {
          *params = (int)(*(float *)(textureObject + 0x40) * FLOAT_00108e94 - FLOAT_00108e90);
          params[1] = (int)(*(float *)(textureObject + 0x44) * floatToIntScale - halfThenFloatValue);
          params[2] = (int)(*(float *)(textureObject + 0x48) * floatToIntScale - halfThenFloatValue);
          halfThenFloatValue = *(float *)(textureObject + 0x4c) * floatToIntScale - halfThenFloatValue;
LAB_000526f0:
          params[3] = (int)halfThenFloatValue;
          return;
        }
        if (pname == (undefined *)0x2800) {
          paramValue = (uint)*(ushort *)(textureObject + 0x3c);
          goto LAB_00052644;
        }
      }
      else {
        if (pname == (undefined *)0x2802) {
          paramValue = (uint)*(ushort *)(textureObject + 0x34);
          goto LAB_00052644;
        }
        if (pname == (undefined *)0x2803) {
          paramValue = (uint)*(ushort *)(textureObject + 0x36);
          goto LAB_00052644;
        }
      }
      goto LAB_00052704;
    }
    if (pname == (undefined *)0x80bf) {
      halfThenFloatValue = *(float *)(textureObject + 0x68);
    }
    else {
      if (pname < (undefined *)0x80c0) {
        if (pname == (undefined *)0x8067) {
          paramValue = (**(code **)(glContext + 0x47ac))
                            (*(undefined4 *)(glContext + 0x4688),
                             *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4));
          *params = paramValue;
          return;
        }
        if (pname == (undefined *)0x8072) {
          paramValue = (uint)*(ushort *)(textureObject + 0x38);
          goto LAB_00052644;
        }
        goto LAB_00052704;
      }
      if (pname == (undefined *)0x813a) {
        halfThenFloatValue = *(float *)(textureObject + 0x54);
      }
      else {
        if (pname != (undefined *)0x813b) goto LAB_00052704;
        halfThenFloatValue = *(float *)(textureObject + 0x58);
      }
    }
  }
LAB_00052638:
  paramValue = (uint)(int)halfThenFloatValue;
LAB_00052644:
  *params = paramValue;
  return;
}

/* _glGetTexParameterfv_Exec @ 0x5272c (916 bytes) */
void _glGetTexParameterfv_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  float *params;
{
  float floatParamValue;
  undefined4 glErrorCode;
  uint intParamValue;
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
      intParamValue = (uint)*(short *)(textureObject + 0x60);
LAB_000529b4:
      floatParamValue = (float)((double)CONCAT44(0x43300000,intParamValue ^ 0x80000000) - DOUBLE_00108d58);
LAB_00052a3c:
      *params = floatParamValue;
      return;
    }
    if (pname < (undefined *)0x813d) {
      if (pname == (undefined *)0x8066) {
        floatParamValue = *(float *)(textureObject + 0x28);
        goto LAB_00052a3c;
      }
      if (pname < (undefined *)0x8067) {
        if (pname == (undefined *)0x2801) {
          intParamValue = (uint)*(ushort *)(textureObject + 0x3a);
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
            intParamValue = (uint)*(ushort *)(textureObject + 0x3c);
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x2802) {
            intParamValue = (uint)*(ushort *)(textureObject + 0x34);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x2803) {
            intParamValue = (uint)*(ushort *)(textureObject + 0x36);
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (pname == (undefined *)0x80bf) {
          floatParamValue = *(float *)(textureObject + 0x68);
          goto LAB_00052a3c;
        }
        if (pname < (undefined *)0x80c0) {
          if (pname == (undefined *)0x8067) {
            intParamValue = (**(code **)(glContext + 0x47ac))
                              (*(undefined4 *)(glContext + 0x4688),
                               *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4));
            intParamValue = intParamValue & 0xffff;
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x8072) {
            intParamValue = (uint)*(ushort *)(textureObject + 0x38);
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x813a) {
            floatParamValue = *(float *)(textureObject + 0x54);
            goto LAB_00052a3c;
          }
          if (pname == (undefined *)0x813b) {
            floatParamValue = *(float *)(textureObject + 0x58);
            goto LAB_00052a3c;
          }
        }
      }
    }
    else {
      if (pname == (undefined *)0x85b7) {
        intParamValue = *(uint *)(textureObject + 0x70);
        goto LAB_000529b4;
      }
      if (pname < (undefined *)0x85b8) {
        if (pname == (undefined *)0x84fe) {
          floatParamValue = *(float *)(textureObject + 0x50);
          goto LAB_00052a3c;
        }
        if (pname < (undefined *)0x84ff) {
          if (pname == (undefined *)0x813d) {
            intParamValue = (uint)*(short *)(textureObject + 0x62);
            goto LAB_000529b4;
          }
          if (pname == (undefined *)0x8191) {
            intParamValue = *(uint *)(textureObject + 0x6c) >> 0xf & 1;
            goto LAB_00052a80;
          }
        }
        else {
          if (pname == (undefined *)0x8501) {
            floatParamValue = *(float *)(textureObject + 0x5c);
            goto LAB_00052a3c;
          }
          if (pname == (undefined *)0x85b6) {
            intParamValue = *(uint *)(textureObject + 0x6c) >> 7 & 1;
            goto LAB_00052a80;
          }
        }
      }
      else {
        if (pname == (undefined *)0x884b) {
          intParamValue = (uint)*(ushort *)(textureObject + 0x6c);
          goto LAB_00052a80;
        }
        if (pname < (undefined *)0x884c) {
          if (pname == (undefined *)0x85bc) {
            intParamValue = (uint)*(ushort *)(textureObject + 0x3e);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x871a) goto LAB_0005294c;
        }
        else {
          if (pname == (undefined *)0x884d) {
            intParamValue = (uint)*(ushort *)(textureObject + 100);
LAB_00052a80:
            *params = GH_U2F((unsigned int)((intParamValue | 0x4b000000))) - 8388608.0;
            return;
          }
          if (pname < (undefined *)0x884d) {
            intParamValue = (uint)*(ushort *)(textureObject + 0x66);
            goto LAB_00052a80;
          }
          if (pname == (undefined *)0x8a7f) {
            intParamValue = *(uint *)(textureObject + 0x6c) >> 6 & 1;
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
void _gleSetEnable_POLYGON_SMOOTH(glContext, unusedArg2, enable)
  int glContext;
  undefined4 unusedArg2;
  undefined4 enable;
{
  *(undefined1 *)(glContext + 0x34d9) = (undefined1)enable;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800000;
  return;
}

/* _gleFogExp @ 0x52eac (88 bytes) */
double _gleFogExp(int glContext,float fogDistance)
{
  float scaledDistance;
  float one;
  
  one = *(float *)(glContext + 0x24);
  if ((double)FLOAT_00108e50 < fogDistance) {
    fogDistance = -fogDistance;
  }
  scaledDistance = (*(float *)(glContext + 0x3150) * fogDistance);
  return (double)(one / ((((*(float *)(glContext + 0x38) * scaledDistance - *(float *)(glContext + 0x34)) *
                             scaledDistance + *(float *)(glContext + 0x30)) * scaledDistance - one) * scaledDistance + one));
}

/* _glFogi_Exec @ 0x52f04 (652 bytes) */
void _glFogi_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  uint param;
{
  bool word5434IsZero;
  byte dirtyBitIndex;
  undefined4 glErrorCode;
  undefined2 paramAsShort;
  int dirtyWord348;
  int glContextPtr5424;
  int dirtyWord324;
  
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
    word5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3158) =
         (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0xb64 < pname) {
      paramAsShort = (undefined2)param;
      if (pname == 0x8450) {
        if (param - 0x8451 < 2) {
          *(undefined2 *)(glContext + 0x3166) = paramAsShort;
          _gleSelectVertexSubmitFunc(glContext);
          goto LAB_00053168;
        }
      }
      else if (pname < 0x8451) {
        if (((pname == 0xb65) && (0x7ff < (int)param)) &&
           (((int)param < 0x802 || (param == 0x2601)))) {
          *(undefined2 *)(glContext + 0x3164) = paramAsShort;
          goto LAB_00053168;
        }
      }
      else if ((pname == 0x855a) &&
              ((param == 0x2502 || ((0x2501 < (int)param && (param - 0x855b < 2)))))) {
        *(undefined2 *)(glContext + 0x3168) = paramAsShort;
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
      word5434IsZero = *(int *)(glContext + 0x5434) == 0;
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
      word5434IsZero = *(int *)(glContext + 0x5434) == 0;
      *(float *)(glContext + 0x3154) =
           (float)((double)CONCAT44(0x43300000,param ^ 0x80000000) - DOUBLE_00108d58);
    }
  }
  if (word5434IsZero) {
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
  }
  dirtyWord324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWord324 + 0x324) = *(uint *)(dirtyWord324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x323);
  dirtyWord348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348 + 0x348) = *(uint *)(dirtyWord348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
LAB_00053168:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _gleFogLinear @ 0x53190 (92 bytes) */
double _gleFogLinear(int glContext,float fogDistance)
{
  float fogFactor;
  
  if ((double)FLOAT_00108e50 < fogDistance) {
    fogDistance = -fogDistance;
  }
  fogFactor = (double)((*(float *)(glContext + 0x3158) + fogDistance) *
                  *(float *)(glContext + 0x315c));
  if ((double)*(float *)(glContext + 0x24) < (double)fogFactor) {
    return (double)*(float *)(glContext + 0x24);
  }
  if (!((double)fogFactor < (double)FLOAT_00108e50)) {
    return (double)fogFactor;
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
  bool glContextWord5434IsZero;
  byte dirtyBitNumber;
  float fogColorComponent;
  float enumParamAsFloat;
  float floatOne;
  undefined4 glErrorCode;
  undefined2 enumValue16;
  uint enumValue;
  int dirtyWordAddress348;
  int glContextPtr5424;
  int dirtyWordAddress324;
  float paramAsDouble;
  
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
    glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
    *(float *)(glContext + 0x3158) = *params;
LAB_00053594:
    if (glContextWord5434IsZero) {
      dirtyBitNumber = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
    }
    else {
      dirtyBitNumber = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
    }
    dirtyWordAddress324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(glContextPtr5424 + 0x323);
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
        glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
      }
      else {
        if (pname < 0xb63) {
          if (pname == 0xb61) {
            *(float *)(glContext + 0x3160) = *params * FLOAT_00108e5c;
            goto LAB_0005360c;
          }
          goto LAB_000535f8;
        }
        glContextWord5434IsZero = *(int *)(glContext + 0x5434) == 0;
        *(float *)(glContext + 0x3154) = *params;
      }
      goto LAB_00053594;
    }
    if (pname != 0xb66) {
      if (pname < 0xb66) {
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= (double)paramAsDouble) {
          enumValue = (int)((double)paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          enumValue = (uint)(int)*params;
        }
        if (enumValue != 0x801) {
          if (enumValue < 0x802) {
            glContextWord5434IsZero = enumValue == 0x800;
          }
          else {
            glContextWord5434IsZero = enumValue == 0x2601;
          }
          if (!glContextWord5434IsZero) goto LAB_000535f8;
        }
        *(short *)(glContext + 0x3164) = (short)enumValue;
      }
      else {
        if (pname == 0x8450) {
          enumParamAsFloat = *params;
          paramAsDouble = (double)enumParamAsFloat;
          if (DOUBLE_00108d80 <= (double)paramAsDouble) {
            enumValue = (int)((double)paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            enumValue = (uint)(int)enumParamAsFloat;
          }
          if (enumValue - 0x8451 < 2) {
            if (DOUBLE_00108d80 <= (double)paramAsDouble) {
              enumValue16 = (undefined2)(int)((double)paramAsDouble - DOUBLE_00108d80);
            }
            else {
              enumValue16 = (undefined2)(int)enumParamAsFloat;
            }
            *(undefined2 *)(glContext + 0x3166) = enumValue16;
            _gleSelectVertexSubmitFunc(glContext);
            goto LAB_0005360c;
          }
        }
        else if (pname == 0x855a) {
          enumParamAsFloat = *params;
          paramAsDouble = (double)enumParamAsFloat;
          if (DOUBLE_00108d80 <= (double)paramAsDouble) {
            enumValue = (int)((double)paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            enumValue = (uint)(int)enumParamAsFloat;
          }
          if ((enumValue == 0x2502) || ((0x2501 < enumValue && (enumValue - 0x855b < 2)))) {
            if (DOUBLE_00108d80 <= (double)paramAsDouble) {
              enumValue16 = (undefined2)(int)((double)paramAsDouble - DOUBLE_00108d80);
            }
            else {
              enumValue16 = (undefined2)(int)enumParamAsFloat;
            }
            *(undefined2 *)(glContext + 0x3168) = enumValue16;
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
    fogColorComponent = *params;
    if (fogColorComponent < FLOAT_00108e50) {
      *(float *)(glContext + 0x3140) = FLOAT_00108e50;
    }
    else if (FLOAT_00108e54 < fogColorComponent) {
      *(float *)(glContext + 0x3140) = FLOAT_00108e54;
    }
    else {
      *(float *)(glContext + 0x3140) = fogColorComponent;
    }
    fogColorComponent = params[1];
    if (fogColorComponent < floatZero) {
      *(float *)(glContext + 0x3144) = floatZero;
    }
    else if (floatOne < fogColorComponent) {
      *(float *)(glContext + 0x3144) = floatOne;
    }
    else {
      *(float *)(glContext + 0x3144) = fogColorComponent;
    }
    fogColorComponent = params[2];
    if (fogColorComponent < floatZero) {
      *(float *)(glContext + 0x3148) = floatZero;
    }
    else if (floatOne < fogColorComponent) {
      *(float *)(glContext + 0x3148) = floatOne;
    }
    else {
      *(float *)(glContext + 0x3148) = fogColorComponent;
    }
    fogColorComponent = params[3];
    if (fogColorComponent < floatZero) {
      *(float *)(glContext + 0x314c) = floatZero;
    }
    else if (floatOne < fogColorComponent) {
      *(float *)(glContext + 0x314c) = floatOne;
    }
    else {
      *(float *)(glContext + 0x314c) = fogColorComponent;
    }
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitNumber = *(byte *)(*(int *)(glContext + 0x5420) + 0x322);
    }
    else {
      dirtyBitNumber = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x356);
    }
    dirtyWordAddress324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    glContextPtr5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(glContextPtr5424 + 0x322);
  }
  dirtyWordAddress348 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitNumber & 0x1f);
LAB_0005360c:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _glFogf_Exec @ 0x53634 (700 bytes) */
void _glFogf_Exec(int glContext,uint pname,double param)
{
  byte dirtyBitIndex;
  undefined4 glErrorCode;
  int dirtyWord348;
  int glContextPtr5424;
  int glContextWord5434;
  uint paramAsEnum;
  int dirtyWord324;
  
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
          paramAsEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramAsEnum = (uint)(int)param;
        }
        if (paramAsEnum - 0x8451 < 2) {
          *(short *)(glContext + 0x3166) = (short)paramAsEnum;
          _gleSelectVertexSubmitFunc(glContext);
          goto LAB_000538c8;
        }
      }
      else if (pname < 0x8451) {
        if (pname == 0xb65) {
          if (DOUBLE_00108d80 <= param) {
            paramAsEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramAsEnum = (uint)(int)param;
          }
          if ((0x7ff < paramAsEnum) && ((paramAsEnum < 0x802 || (paramAsEnum == 0x2601)))) {
            *(short *)(glContext + 0x3164) = (short)paramAsEnum;
            goto LAB_000538c8;
          }
        }
      }
      else if (pname == 0x855a) {
        if (DOUBLE_00108d80 <= param) {
          paramAsEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramAsEnum = (uint)(int)param;
        }
        if ((paramAsEnum == 0x2502) || ((0x2501 < paramAsEnum && (paramAsEnum - 0x855b < 2)))) {
          *(short *)(glContext + 0x3168) = (short)paramAsEnum;
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
    dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x323);
  }
  else {
    dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x357);
  }
  dirtyWord324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  glContextPtr5424 = *(int *)(glContext + 0x5424);
  *(uint *)(dirtyWord324 + 0x324) = *(uint *)(dirtyWord324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
  dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x323);
  dirtyWord348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348 + 0x348) = *(uint *)(dirtyWord348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
LAB_000538c8:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
  ((double (*)())_gleUpdateFogData)(glContext);
  return;
}

/* _gleLightMaterialRGBAChange_FB_AD @ 0x538f0 (344 bytes) */
void _gleLightMaterialRGBAChange_FB_AD(glContext, colorPtr)
  int glContext;
  undefined8 *colorPtr;
{
  byte dirtyBitNumber;
  undefined8 *material;
  int glContextWord5424;
  int secondDirtyWordBase;
  int glContextWord5434;
  int slotTableOffset;
  int firstDirtyWordBase;
  int loopIndex;
  undefined8 colorQword1;
  
  loopIndex = 0;
  do {
    material = (undefined8 *)_glePushMaterial(glContext,loopIndex);
    *material = *colorPtr;
    material[1] = colorPtr[1];
    material[2] = *colorPtr;
    colorQword1 = colorPtr[1];
    *(ushort *)((int)material + 0x234) = *(ushort *)((int)material + 0x234) | 0xc0c;
    material[3] = colorQword1;
    glContextWord5434 = *(int *)(glContext + 0x5434);
    if (glContextWord5434 == 0) {
      dirtyBitNumber = *(byte *)(loopIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c0);
    }
    else {
      dirtyBitNumber = *(byte *)(loopIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f4);
    }
    slotTableOffset = loopIndex * 6;
    firstDirtyWordBase = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(firstDirtyWordBase + 0x324) = *(uint *)(firstDirtyWordBase + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(slotTableOffset + glContextWord5424 + 0x2c0);
    firstDirtyWordBase = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    *(uint *)(firstDirtyWordBase + 0x348) = *(uint *)(firstDirtyWordBase + 0x348) | 1 << (dirtyBitNumber & 0x1f);
    if (glContextWord5434 == 0) {
      dirtyBitNumber = *(byte *)(slotTableOffset + *(int *)(glContext + 0x5420) + 0x2c1);
    }
    else {
      dirtyBitNumber = *(byte *)(slotTableOffset + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f5);
    }
    secondDirtyWordBase = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    loopIndex = loopIndex + 1;
    *(uint *)(secondDirtyWordBase + 0x324) = *(uint *)(secondDirtyWordBase + 0x324) | 1 << (dirtyBitNumber & 0x1f);
    dirtyBitNumber = *(byte *)(slotTableOffset + glContextWord5424 + 0x2c1);
    secondDirtyWordBase = (dirtyBitNumber >> 3 & 0x1c) + glContext;
    *(uint *)(secondDirtyWordBase + 0x348) = *(uint *)(secondDirtyWordBase + 0x348) | 1 << (dirtyBitNumber & 0x1f);
  } while (loopIndex < 2);
  return;
}

/* _glCopyTexImage2D_Exec @ 0x53a48 (1780 bytes) */
void _glCopyTexImage2D_Exec(int glContext,int target,uint level,undefined4 internalformat,undefined4 x,undefined4 y,int width,int height,undefined4 border,double forwardedF1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
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
  uint levelThenDispatchFlagsThenFaceIndex;
  uint changeWord3;
  uint texUnit;
  int copyHeight;
  int *changeWordCursor;
  int textureLevel;
  double f1AfterCall;
  
  if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
    matrixChangeBits = *(int *)(glContext + 0x50ac);
    levelThenDispatchFlagsThenFaceIndex = level;
    forwardedArg4 = internalformat;
    forwardedArg5 = x;
    forwardedArg6 = y;
    if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(glContext);
      forwardedF1 = f1AfterCall;
    }
    if (*(char *)(glContext + 0x4691) != '\0') {
      framebufferObject = *(int *)(glContext + 0x744c);
      changeWordCursor = (int *)(glContext + 0x310);
      rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
      if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,levelThenDispatchFlagsThenFaceIndex,forwardedArg4,forwardedArg5,forwardedArg6,matrixChangeBits,forwardedF1,forwardedFloatArg2,
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
          levelThenDispatchFlagsThenFaceIndex = (**(code **)(glContext + 0x4788))
                             (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
          if ((((levelThenDispatchFlagsThenFaceIndex & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
              ((levelThenDispatchFlagsThenFaceIndex & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
             ((levelThenDispatchFlagsThenFaceIndex & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
            if ((levelThenDispatchFlagsThenFaceIndex & 4) == 0) {
              levelThenDispatchFlagsThenFaceIndex = levelThenDispatchFlagsThenFaceIndex & 0xfffffffe;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
            }
            _gleUpdateDispatchCodeChange(glContext,levelThenDispatchFlagsThenFaceIndex);
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
  levelThenDispatchFlagsThenFaceIndex = target - 0x8515;
  if (5 < levelThenDispatchFlagsThenFaceIndex) {
    levelThenDispatchFlagsThenFaceIndex = 0;
  }
  levelRecord = textureObject + levelThenDispatchFlagsThenFaceIndex * 0x168 + level * 0x18;
  textureLevel = levelRecord + 0xc4;
  if ((*(byte *)(levelRecord + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(glContext,textureObject,textureLevel,levelThenDispatchFlagsThenFaceIndex,level);
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
    _gleCreatePluginTextureLevel(glContext,textureObject,textureLevel,levelThenDispatchFlagsThenFaceIndex,level,internalformat);
    if ((((int)level < (int)(uint)*(byte *)(textureObject + 0x8d)) ||
        ((int)(uint)*(byte *)(textureObject + 0x8f) < (int)level)) ||
       (createResultThenMaskBase = levelThenDispatchFlagsThenFaceIndex * 2 + textureObject, (*(ushort *)(createResultThenMaskBase + 0x94) >> (level & 0x3f) & 1) == 0)) {
LAB_00053fcc:
      levelFlags = *(byte *)(levelRecord + 0xcf);
    }
    else {
      levelFlags = *(byte *)(levelRecord + 0xcf);
      if ((levelFlags & 0x80) == 0) {
        pluginResult = (**(code **)(glContext + 0x470c))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)(textureObject + (uint)*(byte *)(glContext + 0x85a8) * 4),levelThenDispatchFlagsThenFaceIndex,
                           level,0,0,0,x);
        if (pluginResult != 0) {
          *(undefined4 *)(textureObject + 0x20) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          *(byte *)(levelRecord + 0xcf) = *(byte *)(levelRecord + 0xcf) | 0x40;
          if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) &&
              ((int)*(short *)(textureObject + 0x60) == level)) &&
             (nextMipLevel = level + 1, (int)nextMipLevel <= (int)(uint)*(byte *)(textureObject + 0x83))) {
            copyWidthThenLevelCursor = nextMipLevel * 0x18 + levelThenDispatchFlagsThenFaceIndex * 0x168 + textureObject + 0xc4;
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
                  (glContext,textureObject,textureLevel,levelThenDispatchFlagsThenFaceIndex,level,(uint)*(byte *)(glContext + 0x85a8));
      }
    }
    _gleModifyPluginTextureLevel(glContext,textureObject,textureLevel,levelThenDispatchFlagsThenFaceIndex,level,0,0,0,copyWidthThenLevelCursor,copyHeight,1);
    _gleTextureImageCopy(glContext,textureLevel,internalformat,x,y,width,height);
    if ((((*(uint *)(textureObject + 0x6c) & 0x8000) != 0) && ((int)*(short *)(textureObject + 0x60) == level))
       && (textureObject = _gleGenMipmapsToLevel(glContext,textureObject,levelThenDispatchFlagsThenFaceIndex,level,0xf,1), textureObject != 0)) {
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
  ushort textureTargetKind;
  int readOffsetXThenResultObject;
  int glContextPtr468c;
  int textureObject;
  undefined4 uVar4;
  uint maxTextureDimension;
  int readOffsetYThenCheckResult;
  undefined4 uVar7;
  uint innerHeight;
  uint innerWidth;
  
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
    readOffsetXThenResultObject = 0;
  }
  else {
    if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
      if (((*(uint *)(glContext + 0x3410) & 4) != 0) && (*(short *)(glContext + 0x3348) == -0x7fea)) {
        readOffsetYThenCheckResult = *(int *)(glContext + 0x3354);
        readOffsetXThenResultObject = *(int *)(glContext + 0x3350);
        goto LAB_000541e0;
      }
    }
    else if (*(short *)(glContext + 0x3308) == -0x7fea) {
      readOffsetYThenCheckResult = *(int *)(glContext + 0x3314);
      readOffsetXThenResultObject = *(int *)(glContext + 0x3310);
LAB_000541e0:
      width = (width - readOffsetXThenResultObject) + 1;
      height = (height - readOffsetYThenCheckResult) + 1;
    }
    innerHeight = height + border * -2;
    innerWidth = width + border * -2;
    textureTargetKind = *(ushort *)(textureObject + 0x24) & 0xf;
    if (textureTargetKind == 2) {
      uVar7 = 0;
      if ((((int)innerWidth < 0) ||
          (maxTextureDimension = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc0), (int)maxTextureDimension < (int)innerWidth))
         || ((int)innerHeight < 0)) goto LAB_000542d0;
LAB_000542cc:
      if ((int)maxTextureDimension < (int)innerHeight) {
LAB_000542d0:
        if (*(int *)(glContext + 0x7574) == 0) {
          glErrorCode = 0x501;
          goto LAB_000542e0;
        }
        goto LAB_000542e4;
      }
    }
    else if (textureTargetKind < 3) {
      if ((*(ushort *)(textureObject + 0x24) & 0xf) == 0) {
        uVar4 = 0;
        if ((innerWidth != innerHeight) ||
           ((int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2) < (int)innerHeight))
        goto LAB_000542d0;
LAB_00054244:
        if (-1 < (int)innerWidth) {
          if ((innerWidth & innerWidth - 1) == 0) {
            glContextPtr468c = *(int *)(glContext + 0x468c);
          }
          else {
            glContextPtr468c = *(int *)(glContext + 0x468c);
            if ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) == 0) goto LAB_000542d0;
          }
          maxTextureDimension = (uint)*(ushort *)(glContextPtr468c + 0xbc);
          if ((((int)innerWidth <= (int)maxTextureDimension) && (-1 < (int)innerHeight)) &&
             (((innerHeight & innerHeight - 1) == 0 || ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) != 0))))
          goto LAB_000542cc;
        }
        goto LAB_000542d0;
      }
    }
    else if (textureTargetKind == 3) goto LAB_00054244;
    readOffsetYThenCheckResult = ((int (*)())_gleCheckCopyTexImageArgs)(glContext,level,internalformat,border,uVar4,uVar7);
    readOffsetXThenResultObject = 0;
    if (readOffsetYThenCheckResult != 0) {
      readOffsetXThenResultObject = textureObject;
    }
  }
  return readOffsetXThenResultObject;
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
  bool levelInRange;
  bool formatIsSingleValue;
  bool formatNotInRange;
  undefined4 glErrorCode;
  uint formatOffset;
  
  levelInRange = true;
  if (0xe < level) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x501;
    }
    levelInRange = false;
  }
  if (!levelInRange) {
    return 0;
  }
  if (internalformat < 0x83f4) {
    if (0x83ef < internalformat) goto LAB_00054528;
    if (internalformat < 0x804e) {
      if (internalformat < 0x803b) {
        if (internalformat == 0x1902) goto LAB_000544f8;
        if (internalformat < 0x1903) {
          formatNotInRange = 3 < internalformat - 1U;
          goto LAB_000544e0;
        }
        if (internalformat < 0x1906) goto LAB_000544e4;
        if (0x190a < internalformat) {
          formatIsSingleValue = internalformat == 0x2a10;
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
      formatOffset = internalformat - 0x804f;
      goto LAB_000544b8;
    }
    if (param_6 != 0) goto LAB_00054528;
  }
  else {
    if (internalformat < 0x8700) {
      if (internalformat < 0x86fe) {
        if (0x86f6 < internalformat) {
          formatNotInRange = 4 < internalformat - 0x86f8U;
          goto LAB_000544e0;
        }
        if (internalformat < 0x86f4) {
          if (internalformat < 0x84e9) goto LAB_000544e4;
          if (0x84ee < internalformat) {
            formatIsSingleValue = internalformat == 0x86dc;
LAB_00054478:
            if (!formatIsSingleValue) goto LAB_000544e4;
          }
        }
      }
    }
    else if (internalformat < 0x8820) {
      if (internalformat < 0x8814) {
        formatOffset = internalformat - 0x8701;
LAB_000544b8:
        formatNotInRange = 0xc < formatOffset;
LAB_000544e0:
        if (formatNotInRange) {
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
      formatNotInRange = 1 < internalformat - 0x885eU;
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
void _glRasterPos2i_Exec(int glContext,uint x,uint y,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint forwardedY;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterCall;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((*(int *)(glContext + 0x744c) != 0) || (*(int *)(glContext + 0x310) < 0)) {
      matrixChangeBits = *(int *)(glContext + 0x50ac);
      forwardedY = y;
      if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
        _gleUpdateMatrixFunc(glContext);
        forwardedFloatArg1 = f1AfterCall;
      }
      if (*(char *)(glContext + 0x4691) != '\0') {
        framebufferObject = *(int *)(glContext + 0x744c);
        changeWordCursor = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedY,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
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
            goto LAB_000546a8;
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
void _gleSetRasterPos(int glContext,float x,float y,float z,float w)
{
  float floatZero;
  int loopIndex;
  undefined4 *texCoordSrc;
  bool wLargeEnough;
  float eyeY;
  float inverseClipW;
  float glContextFloat2b4;
  float eyeX;
  float glContextFloat2b0;
  float eyeZ;
  float glContextFloat2b8;
  float eyeW;
  undefined4 texCoordWord2;
  undefined4 texCoordWord3;
  float clipY;
  float clipZ;
  float clipX;
  float clipW;
  float negClipW;
  int glContextPtr4854;
  int texCoordCursor;
  int clipPlaneRecord;
  int *srcCursor;
  undefined4 texCoordWord1;
  undefined4 glContextWord4864;
  int texCoordDst;
  int glContextWord48d0;
  int glContextWord4e1c;
  int rasterVertex;
  int remaining;
  double fogFactor;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  *(undefined1 *)(glContext + 0x2ef) = 0;
  rasterVertex = glContextPtr4854 + -0x200;
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5434) == 0)) {
    remaining = 8;
    texCoordDst = rasterVertex;
    texCoordCursor = glContext;
    do {
      texCoordSrc = (undefined4 *)(texCoordCursor + 0x120);
      texCoordWord1 = *(undefined4 *)(texCoordCursor + 0x124);
      texCoordWord2 = *(undefined4 *)(texCoordCursor + 0x128);
      texCoordWord3 = *(undefined4 *)(texCoordCursor + 300);
      texCoordCursor = texCoordCursor + 0x10;
      *(undefined4 *)(texCoordDst + 0x80) = *texCoordSrc;
      *(undefined4 *)(texCoordDst + 0x84) = texCoordWord1;
      *(undefined4 *)(texCoordDst + 0x88) = texCoordWord2;
      *(undefined4 *)(texCoordDst + 0x8c) = texCoordWord3;
      texCoordDst = texCoordDst + 0x10;
      remaining = remaining + -1;
    } while (remaining != 0);
    *(undefined4 *)(glContextPtr4854 + -0x184) = *(undefined4 *)(glContext + 0x2ec);
    if (*(char *)(glContext + 0x53e4) != '\0') {
      *(float *)(glContextPtr4854 + -0x1e0) = (float)x;
      *(float *)(glContextPtr4854 + -0x1dc) = (float)y;
      *(float *)(glContextPtr4854 + -0x1d8) = (float)z;
      *(float *)(glContextPtr4854 + -0x1d4) = (float)w;
      (**(code **)(glContext + 0x53dc))(glContext,rasterVertex,1);
    }
    eyeY = (w * *(float *)(glContext + 0x1cf4) + (z * *(float *)(glContext + 0x1ce4) + (x * *(float *)(glContext + 0x1cc4) + (y * *(float *)(glContext + 0x1cd4)))));
    eyeX = (w * *(float *)(glContext + 0x1cf0) + (z * *(float *)(glContext + 0x1ce0) + (x * *(float *)(glContext + 0x1cc0) + (y * *(float *)(glContext + 0x1cd0)))));
    eyeZ = (w * *(float *)(glContext + 0x1cf8) + (z * *(float *)(glContext + 0x1ce8) + (x * *(float *)(0x1cc8 + glContext) + (y * *(float *)(glContext + 0x1cd8)))));
    eyeW = (w * *(float *)(glContext + 0x1cfc) + (z * *(float *)(glContext + 0x1cec) + (x * *(float *)(glContext + 0x1ccc) + (y * *(float *)(glContext + 0x1cdc)))));
    clipW = eyeW * *(float *)(glContext + 0x1cbc) +
             (eyeZ * *(float *)(glContext + 0x1cac) +
             (eyeX * *(float *)(glContext + 0x1c8c) + eyeY * *(float *)(glContext + 0x1c9c)));
    clipX = eyeW * *(float *)(glContext + 0x1cb0) +
             (eyeZ * *(float *)(glContext + 0x1ca0) +
             (eyeX * *(float *)(glContext + 0x1c80) + eyeY * *(float *)(glContext + 0x1c90)));
    clipZ = eyeW * *(float *)(glContext + 0x1cb8) +
             (eyeZ * *(float *)(glContext + 0x1ca8) +
             (eyeX * *(float *)(glContext + 0x1c88) + eyeY * *(float *)(glContext + 0x1c98)));
    clipY = eyeW * *(float *)(glContext + 0x1cb4) +
            (eyeZ * *(float *)(glContext + 0x1ca4) +
            (eyeX * *(float *)(glContext + 0x1c84) + eyeY * *(float *)(glContext + 0x1c94)));
    negClipW = -clipW;
    if (((*(char *)(glContext + 0x50b5) == '\0') &&
        ((((clipX < negClipW || (clipW < clipX)) || (clipY < negClipW)) || (clipW < clipY)))) ||
       ((clipZ < negClipW || (clipW < clipZ)))) goto LAB_00054e14;
    if (*(char *)(glContext + 0x4e18) != '\0') {
      loopIndex = 0;
      if (0 < *(int *)(glContext + 0x4dfc)) {
        srcCursor = (int *)(glContext + 0x4e00);
        do {
          clipPlaneRecord = *srcCursor;
          srcCursor = srcCursor + 1;
          clipPlaneRecord = glContext + clipPlaneRecord * 0x10;
          if (eyeW * *(float *)(clipPlaneRecord + 0x4198) +
              (eyeZ * *(float *)(clipPlaneRecord + 0x4194) +
              (eyeX * *(float *)(clipPlaneRecord + 0x418c) + eyeY * *(float *)(clipPlaneRecord + 0x4190))) <
              FLOAT_00108e50) goto LAB_00054e14;
          loopIndex = loopIndex + 1;
        } while (loopIndex < *(int *)(glContext + 0x4dfc));
      }
    }
    *(float *)(glContextPtr4854 + -0x1e0) = eyeX;
    floatZero = FLOAT_00108e50;
    *(float *)(glContextPtr4854 + -0x1dc) = eyeY;
    *(float *)(glContextPtr4854 + -0x1d8) = eyeZ;
    *(float *)(glContextPtr4854 + -0x1d4) = eyeW;
    *(float *)(glContextPtr4854 + -0x1f0) = clipX;
    *(float *)(glContextPtr4854 + -0x1ec) = clipY;
    *(float *)(glContextPtr4854 + -0x1e8) = clipZ;
    *(float *)(glContextPtr4854 + -0x1e4) = clipW;
    if (floatZero <= clipW) {
      wLargeEnough = FLOAT_00108e80 <= clipW;
    }
    else {
      wLargeEnough = clipW <= FLOAT_00108f3c;
    }
    if (wLargeEnough) {
      inverseClipW = FLOAT_00108e54 / clipW;
    }
    else {
      inverseClipW = FLOAT_00108f7c;
      if (FLOAT_00108e50 <= clipW) {
        inverseClipW = FLOAT_00108eb4;
      }
    }
    *(float *)(glContext + 0x2e0) =
         *(float *)(glContext + 0x4a2c) * clipX * inverseClipW + *(float *)(glContext + 0x4a30);
    *(float *)(glContext + 0x2e4) =
         *(float *)(glContext + 0x4a34) * clipY * inverseClipW + *(float *)(glContext + 19000);
    *(float *)(glContext + 0x2e8) =
         *(float *)(glContext + 0x4a3c) * clipZ * inverseClipW + *(float *)(glContext + 0x4a40);
    *(float *)(glContextPtr4854 + -500) = inverseClipW;
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
      (**(code **)(glContext + 0x53e0))(glContext,rasterVertex,1);
    }
    (**(code **)(glContext + 0x506c))(glContext,rasterVertex,1,0);
    if (*(short *)(glContext + 0x3166) == -0x7baf) {
      *(undefined4 *)(glContextPtr4854 + -0x1d8) = *(undefined4 *)(glContext + 0x2cc);
    }
    fogFactor = (double)(**(double ( **)(int,double))(glContext + 0x4fe4))(glContext, (double)*(float *)(glContextPtr4854 + -0x1d8));
    *(float *)(glContextPtr4854 + -0x1b4) = (float)fogFactor;
    if (*(char *)(glContext + 0x30aa) == '\0') {
      *(undefined8 *)(glContextPtr4854 + -0x1d0) = *(undefined8 *)(glContext + 0x2a0);
      *(undefined8 *)(glContextPtr4854 + -0x1c8) = *(undefined8 *)(glContext + 0x2a8);
      *(undefined8 *)(glContextPtr4854 + -0x1b0) = *(undefined8 *)(glContext + 0x2c0);
      *(undefined4 *)(glContextPtr4854 + -0x1a8) = *(undefined4 *)(glContext + 0x2c8);
    }
    else {
      *(undefined4 *)(glContextPtr4854 + -0x18c) = *(undefined4 *)(glContext + 0x4dd0);
      *(undefined4 *)(glContextPtr4854 + -0x188) = *(undefined4 *)(glContext + 0x4dd4);
      (**(code **)(glContext + 0x4de8))(glContext,rasterVertex,1);
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
    (**(int ( **)(int,double,double,double,double))(glContext + 0x4888))(glContext, x, y, z, w);
    if (glContextWord48d0 != 0) {
      *(int *)(glContext + 0x48d0) = glContextWord48d0;
      _gleSelectVertexSubmitFunc(glContext);
    }
    *(int *)(glContext + 0x4864) = rasterVertex;
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
    _gleSelectHit(glContext,rasterVertex);
  }
  *(undefined1 *)(glContext + 0x2ef) = 1;
LAB_00054e14:
  return;
}

/* _glBitmap_Exec @ 0x54e2c (984 bytes) */
void _glBitmap_Exec(int glContext,int width,int height,undefined4 xorigShadowThenScratch,undefined4 yorigShadowThenFormatArg,int xmoveShadowThenBitmapArg,undefined4 ymoveShadow,int bitmap,double xorig,double yorig,float xmove,float ymove,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int glContextPtr4854;
  int *srcCursor;
  int imageEndOffset;
  int framebufferObject;
  int forwardedHeight;
  uint dispatchFlags;
  uint changeWord3;
  float *a1;
  int dirtyWord;
  int matrixChangeBits;
  int pixelUnpackBuffer;
  int *changeWordCursor;
  double f1AfterOffsetLimitImage;
  double fparam_1_00;
  double f1AfterUpdateMatrixFunc;
  double fparam_2_00;
  double fparam_3_00;
  double fparam_4_00;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  a1 = (float *)(glContextPtr4854 + -0x200);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < width) && (-1 < height)) {
      pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
      forwardedHeight = height;
      fparam_1_00 = xorig;
      fparam_2_00 = yorig;
      fparam_3_00 = xmove;
      fparam_4_00 = ymove;
      if (pixelUnpackBuffer != 0) {
        xorigShadowThenScratch = 0;
        yorigShadowThenFormatArg = 0x1a00;
        xmoveShadowThenBitmapArg = bitmap;
        imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,0,0x1a00,bitmap);
        if (*(int *)(pixelUnpackBuffer + 0x38) < imageEndOffset) goto LAB_00054ec8;
        fparam_1_00 = f1AfterOffsetLimitImage;
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
            fparam_1_00 = f1AfterUpdateMatrixFunc;
          }
          if (*(char *)(glContext + 0x4691) != '\0') {
            framebufferObject = *(int *)(glContext + 0x744c);
            changeWordCursor = (int *)(glContext + 0x310);
            rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
            if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
              ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedHeight,xorigShadowThenScratch,yorigShadowThenFormatArg,xmoveShadowThenBitmapArg,matrixChangeBits,fparam_1_00,
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
                goto LAB_0005501c;
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
                    (*(undefined4 *)(glContext + 0x4688),a1,width,height,yorigShadowThenFormatArg,xmoveShadowThenBitmapArg,bitmap,0,
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
void _glCopyPixels_Exec(int glContext,undefined4 x,undefined4 y,int width,int height,int type,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 forwardedY;
  uint dispatchFlags;
  uint changeWord3;
  uint glContextWord4e1c;
  int forwardedHeight;
  int dirtyWord;
  int glContextPtr4854;
  int *srcCursor;
  int framebufferObject;
  int forwardedType;
  int matrixChangeBits;
  int forwardedWidth;
  int *changeWordCursor;
  float *rasterVertex;
  double f1AfterCall;
  
  glContextPtr4854 = *(int *)(glContext + 0x4854);
  rasterVertex = (float *)(glContextPtr4854 + -0x200);
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
      _gleFeedbackCopyPixels(glContext,rasterVertex);
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
        forwardedY = y;
        forwardedWidth = width;
        forwardedHeight = height;
        forwardedType = type;
        if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(glContext);
          forwardedFloatArg1 = f1AfterCall;
        }
        if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0005550c;
        framebufferObject = *(int *)(glContext + 0x744c);
        changeWordCursor = (int *)(glContext + 0x310);
        rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
        if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
          ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,forwardedY,forwardedWidth,forwardedHeight,forwardedType,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3
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
            goto LAB_000553e8;
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
        *rasterVertex = *(float *)(glContext + 0x4a44) * *(float *)(glContext + 0x2e0) +
                   *(float *)(glContext + 0x4a48);
        *(float *)(glContextPtr4854 + -0x1fc) =
             *(float *)(glContext + 0x4a4c) * *(float *)(glContext + 0x2e4) +
             *(float *)(glContext + 0x4a50);
        *(float *)(glContextPtr4854 + -0x1f8) = *(float *)(glContext + 0x4a54) * *(float *)(glContext + 0x2e8);
                    
                    
        (**(code **)(glContext + 0x46a8))
                  (*(undefined4 *)(glContext + 0x4688),rasterVertex,x,y,width,height,type
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

